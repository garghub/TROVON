static int __used atomic_dec_and_lock_1(atomic_t *atomic, spinlock_t *lock)\r\n{\r\nspin_lock(lock);\r\nif (atomic_dec_and_test(atomic))\r\nreturn 1;\r\nspin_unlock(lock);\r\nreturn 0;\r\n}
