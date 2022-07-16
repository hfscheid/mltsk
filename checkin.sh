#!/usr/bin/env bash

tmin
tmux new-session -x- -y- -d 'bash'
tmux split-window -v  'tmout -c'
tmux resize-pane -y 2
tmux select-pane -U
tmux -2 attach-session -d
