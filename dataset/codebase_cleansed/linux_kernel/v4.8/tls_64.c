void clear_flushed_tls(struct task_struct *task)\r\n{\r\n}\r\nint arch_copy_tls(struct task_struct *t)\r\n{\r\nt->thread.arch.fs = t->thread.regs.regs.gp[R8 / sizeof(long)];\r\nreturn 0;\r\n}
