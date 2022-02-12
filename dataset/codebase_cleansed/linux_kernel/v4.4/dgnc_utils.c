int dgnc_ms_sleep(ulong ms)\r\n{\r\n__set_current_state(TASK_INTERRUPTIBLE);\r\nschedule_timeout((ms * HZ) / 1000);\r\nreturn signal_pending(current);\r\n}
