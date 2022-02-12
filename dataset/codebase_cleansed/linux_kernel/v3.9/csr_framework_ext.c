void CsrThreadSleep(u16 sleepTimeInMs)\r\n{\r\nunsigned long t;\r\nt = ((sleepTimeInMs * HZ) + 999) / 1000;\r\nschedule_timeout_uninterruptible(t);\r\n}
