# mltsk : the suboptimal tool for multitasking
The `mltsk` package builds upon `tmux` to provide simple multitasking utility, especially regarding time management. It is used to create working sessions in `tmux` with managed time logging. `mltsk` morking model is a "task", comprising its idendifying name and time logging. The package provides a command-line interface to start, open, close and end tasks.

There are two layers of utilites. At the most basic, the `mltsk` package 6 the "tm-" time logging commands. Next, the `mltsk` command layer uses those commands along with tmux to provide its working sessions.

## Interface 
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

## Use
Simple time logging utilizes a data structure called a `time_inteval`, basically consisting of a beginning timestamp and an ending timestamp. A time log for a task codifies an array of `time_interval`'s.
Thus, to start tracking time in a task, an entry must be created with `tmin`:

```
# if no task_name is specified, it is named "default".
$ tmin
$ tmin namedtask
```
Runing these commands would create two time logs: "~/.mltsk/time\_in\_default.mltsk" and "~/.mltsk/time\_in\_namedtask.mltsk". 

> **Note**: attempting to `tmin` twice in a row for a specific task will result in an error, since the last `time\_interval` must be closed for a new one to be open.

When a `time\_interval` is open, it's length may be acquired by the `tmon` command:

```
# if no task_name is specified, tmon will reach for the "default" time log.
$ tmon namedtask

1:17:28
```
In this example, `tmon` was executed 1 hour, 17 minutes and 28 seconds after the last `tmin` was run for this specific task. 
