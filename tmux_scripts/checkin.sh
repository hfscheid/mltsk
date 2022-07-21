#!/usr/bin/env bash

tmin $1
tmux new-session -x- -y- -d 'vim'
tmux resize-pane -y 20
tmux -2 attach-session -d
