# mltsk : the suboptimal tool for multitasking
The `mltsk` package builds upon `tmux` to provide simple multitasking utility, especially regarding time management. It is used to create working sessions in `tmux` with managed time logging. `mltsk` morking model is a "task", comprising its idendifying name and time logging. The package provides a command-line interface to start, open, close and end tasks.

There are two layers of utilites. At the most basic, the `mltsk` package 6 the "tm-" time logging commands. Next, the `mltsk` command layer uses those commands along with tmux to provide its working sessions.

## Interface of "tm-" commands
Time logging commands:
- tmin *task_name*
- tmout *task_name*
- tmon *task_name*
- tmall *task_name*
- tmoff *task_name*

Working session commands:
- mltsk in *task_name*
- mltsk out *task_name*
- mltsk off *task_name*

## Use of "tm-" commands
Simple time logging utilizes a data structure called a `time_inteval`, basically consisting of a beginning timestamp and an ending timestamp. A time log for a task codifies an array of `time_interval`'s.
Thus, to start tracking time in a task, an entry must be created with `tmin`:

```
# if no task_name is specified, it is named "default".
$ tmin namedtask
```
Runing these commands would create the time log "~/.mltsk/time\_in\_namedtask.mltsk". 

> **Note**: attempting to `tmin` twice in a row for a specific task will result in an error, since the last `time\_interval` must be closed for a new one to be open.

Not that there is at least one `time\_interval` related to this task, its length may be acquired by the `tmon` command:

```
# if no task_name is specified, tmon will reach for the "default" time log.
$ tmon namedtask

1:17:28
```
In this example, `tmon` was executed 1 hour, 17 minutes and 28 seconds after the last `tmin` was run for this specific task. 

After `tmin` is executed, the new `time_interval` is open, and each `tmon` will count and increasing time duration. In order to close the interval, `tmout` must be used:

```
# if no task_name is specified, tmout will reach for the "default" time log.
$ tmout namedtask
```
This command will log that the last `time_interval` is now closed. From this point on, `tmon`'s output will remain constant (until a new `tmin` is executed).

> **Note**: attempting to `tmout` twice in a row for a specific task will result in an error, since it doesn't make sense to close an already closed `time\_interval`. To resume time metering, a ne interval must be first open.

Once there are multiple `time_intervals` in a task, it may be worthy to check the total time sum. This is done via `tmall`:

```
# first tmin for task
$ tmin namedtask

# tmout after 5 minutes
$ tmout namedtask

# second tmin after an arbitrary amount of time
$ tmin namedtask

# tmout after 10 minutes
$ tmout namedtask

# if no task_name is specified, tmall will reach for the "default" time log.
$ tmall namedtask

0:15:0
```
This command also works with open last intervals, similarly to `tmon`.
