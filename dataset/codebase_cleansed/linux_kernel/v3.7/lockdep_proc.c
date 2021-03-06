static void *l_next(struct seq_file *m, void *v, loff_t *pos)\r\n{\r\nreturn seq_list_next(v, &all_lock_classes, pos);\r\n}\r\nstatic void *l_start(struct seq_file *m, loff_t *pos)\r\n{\r\nreturn seq_list_start_head(&all_lock_classes, *pos);\r\n}\r\nstatic void l_stop(struct seq_file *m, void *v)\r\n{\r\n}\r\nstatic void print_name(struct seq_file *m, struct lock_class *class)\r\n{\r\nchar str[128];\r\nconst char *name = class->name;\r\nif (!name) {\r\nname = __get_key_name(class->key, str);\r\nseq_printf(m, "%s", name);\r\n} else{\r\nseq_printf(m, "%s", name);\r\nif (class->name_version > 1)\r\nseq_printf(m, "#%d", class->name_version);\r\nif (class->subclass)\r\nseq_printf(m, "/%d", class->subclass);\r\n}\r\n}\r\nstatic int l_show(struct seq_file *m, void *v)\r\n{\r\nstruct lock_class *class = list_entry(v, struct lock_class, lock_entry);\r\nstruct lock_list *entry;\r\nchar usage[LOCK_USAGE_CHARS];\r\nif (v == &all_lock_classes) {\r\nseq_printf(m, "all lock classes:\n");\r\nreturn 0;\r\n}\r\nseq_printf(m, "%p", class->key);\r\n#ifdef CONFIG_DEBUG_LOCKDEP\r\nseq_printf(m, " OPS:%8ld", class->ops);\r\n#endif\r\n#ifdef CONFIG_PROVE_LOCKING\r\nseq_printf(m, " FD:%5ld", lockdep_count_forward_deps(class));\r\nseq_printf(m, " BD:%5ld", lockdep_count_backward_deps(class));\r\n#endif\r\nget_usage_chars(class, usage);\r\nseq_printf(m, " %s", usage);\r\nseq_printf(m, ": ");\r\nprint_name(m, class);\r\nseq_puts(m, "\n");\r\nlist_for_each_entry(entry, &class->locks_after, entry) {\r\nif (entry->distance == 1) {\r\nseq_printf(m, " -> [%p] ", entry->class->key);\r\nprint_name(m, entry->class);\r\nseq_puts(m, "\n");\r\n}\r\n}\r\nseq_puts(m, "\n");\r\nreturn 0;\r\n}\r\nstatic int lockdep_open(struct inode *inode, struct file *file)\r\n{\r\nreturn seq_open(file, &lockdep_ops);\r\n}\r\nstatic void *lc_start(struct seq_file *m, loff_t *pos)\r\n{\r\nif (*pos == 0)\r\nreturn SEQ_START_TOKEN;\r\nif (*pos - 1 < nr_lock_chains)\r\nreturn lock_chains + (*pos - 1);\r\nreturn NULL;\r\n}\r\nstatic void *lc_next(struct seq_file *m, void *v, loff_t *pos)\r\n{\r\n(*pos)++;\r\nreturn lc_start(m, pos);\r\n}\r\nstatic void lc_stop(struct seq_file *m, void *v)\r\n{\r\n}\r\nstatic int lc_show(struct seq_file *m, void *v)\r\n{\r\nstruct lock_chain *chain = v;\r\nstruct lock_class *class;\r\nint i;\r\nif (v == SEQ_START_TOKEN) {\r\nseq_printf(m, "all lock chains:\n");\r\nreturn 0;\r\n}\r\nseq_printf(m, "irq_context: %d\n", chain->irq_context);\r\nfor (i = 0; i < chain->depth; i++) {\r\nclass = lock_chain_get_class(chain, i);\r\nif (!class->key)\r\ncontinue;\r\nseq_printf(m, "[%p] ", class->key);\r\nprint_name(m, class);\r\nseq_puts(m, "\n");\r\n}\r\nseq_puts(m, "\n");\r\nreturn 0;\r\n}\r\nstatic int lockdep_chains_open(struct inode *inode, struct file *file)\r\n{\r\nreturn seq_open(file, &lockdep_chains_ops);\r\n}\r\nstatic void lockdep_stats_debug_show(struct seq_file *m)\r\n{\r\n#ifdef CONFIG_DEBUG_LOCKDEP\r\nunsigned long long hi1 = debug_atomic_read(hardirqs_on_events),\r\nhi2 = debug_atomic_read(hardirqs_off_events),\r\nhr1 = debug_atomic_read(redundant_hardirqs_on),\r\nhr2 = debug_atomic_read(redundant_hardirqs_off),\r\nsi1 = debug_atomic_read(softirqs_on_events),\r\nsi2 = debug_atomic_read(softirqs_off_events),\r\nsr1 = debug_atomic_read(redundant_softirqs_on),\r\nsr2 = debug_atomic_read(redundant_softirqs_off);\r\nseq_printf(m, " chain lookup misses: %11llu\n",\r\ndebug_atomic_read(chain_lookup_misses));\r\nseq_printf(m, " chain lookup hits: %11llu\n",\r\ndebug_atomic_read(chain_lookup_hits));\r\nseq_printf(m, " cyclic checks: %11llu\n",\r\ndebug_atomic_read(nr_cyclic_checks));\r\nseq_printf(m, " find-mask forwards checks: %11llu\n",\r\ndebug_atomic_read(nr_find_usage_forwards_checks));\r\nseq_printf(m, " find-mask backwards checks: %11llu\n",\r\ndebug_atomic_read(nr_find_usage_backwards_checks));\r\nseq_printf(m, " hardirq on events: %11llu\n", hi1);\r\nseq_printf(m, " hardirq off events: %11llu\n", hi2);\r\nseq_printf(m, " redundant hardirq ons: %11llu\n", hr1);\r\nseq_printf(m, " redundant hardirq offs: %11llu\n", hr2);\r\nseq_printf(m, " softirq on events: %11llu\n", si1);\r\nseq_printf(m, " softirq off events: %11llu\n", si2);\r\nseq_printf(m, " redundant softirq ons: %11llu\n", sr1);\r\nseq_printf(m, " redundant softirq offs: %11llu\n", sr2);\r\n#endif\r\n}\r\nstatic int lockdep_stats_show(struct seq_file *m, void *v)\r\n{\r\nstruct lock_class *class;\r\nunsigned long nr_unused = 0, nr_uncategorized = 0,\r\nnr_irq_safe = 0, nr_irq_unsafe = 0,\r\nnr_softirq_safe = 0, nr_softirq_unsafe = 0,\r\nnr_hardirq_safe = 0, nr_hardirq_unsafe = 0,\r\nnr_irq_read_safe = 0, nr_irq_read_unsafe = 0,\r\nnr_softirq_read_safe = 0, nr_softirq_read_unsafe = 0,\r\nnr_hardirq_read_safe = 0, nr_hardirq_read_unsafe = 0,\r\nsum_forward_deps = 0;\r\nlist_for_each_entry(class, &all_lock_classes, lock_entry) {\r\nif (class->usage_mask == 0)\r\nnr_unused++;\r\nif (class->usage_mask == LOCKF_USED)\r\nnr_uncategorized++;\r\nif (class->usage_mask & LOCKF_USED_IN_IRQ)\r\nnr_irq_safe++;\r\nif (class->usage_mask & LOCKF_ENABLED_IRQ)\r\nnr_irq_unsafe++;\r\nif (class->usage_mask & LOCKF_USED_IN_SOFTIRQ)\r\nnr_softirq_safe++;\r\nif (class->usage_mask & LOCKF_ENABLED_SOFTIRQ)\r\nnr_softirq_unsafe++;\r\nif (class->usage_mask & LOCKF_USED_IN_HARDIRQ)\r\nnr_hardirq_safe++;\r\nif (class->usage_mask & LOCKF_ENABLED_HARDIRQ)\r\nnr_hardirq_unsafe++;\r\nif (class->usage_mask & LOCKF_USED_IN_IRQ_READ)\r\nnr_irq_read_safe++;\r\nif (class->usage_mask & LOCKF_ENABLED_IRQ_READ)\r\nnr_irq_read_unsafe++;\r\nif (class->usage_mask & LOCKF_USED_IN_SOFTIRQ_READ)\r\nnr_softirq_read_safe++;\r\nif (class->usage_mask & LOCKF_ENABLED_SOFTIRQ_READ)\r\nnr_softirq_read_unsafe++;\r\nif (class->usage_mask & LOCKF_USED_IN_HARDIRQ_READ)\r\nnr_hardirq_read_safe++;\r\nif (class->usage_mask & LOCKF_ENABLED_HARDIRQ_READ)\r\nnr_hardirq_read_unsafe++;\r\n#ifdef CONFIG_PROVE_LOCKING\r\nsum_forward_deps += lockdep_count_forward_deps(class);\r\n#endif\r\n}\r\n#ifdef CONFIG_DEBUG_LOCKDEP\r\nDEBUG_LOCKS_WARN_ON(debug_atomic_read(nr_unused_locks) != nr_unused);\r\n#endif\r\nseq_printf(m, " lock-classes: %11lu [max: %lu]\n",\r\nnr_lock_classes, MAX_LOCKDEP_KEYS);\r\nseq_printf(m, " direct dependencies: %11lu [max: %lu]\n",\r\nnr_list_entries, MAX_LOCKDEP_ENTRIES);\r\nseq_printf(m, " indirect dependencies: %11lu\n",\r\nsum_forward_deps);\r\nseq_printf(m, " all direct dependencies: %11lu\n",\r\nnr_irq_unsafe * nr_irq_safe +\r\nnr_hardirq_unsafe * nr_hardirq_safe +\r\nnr_list_entries);\r\n#ifdef CONFIG_PROVE_LOCKING\r\nseq_printf(m, " dependency chains: %11lu [max: %lu]\n",\r\nnr_lock_chains, MAX_LOCKDEP_CHAINS);\r\nseq_printf(m, " dependency chain hlocks: %11d [max: %lu]\n",\r\nnr_chain_hlocks, MAX_LOCKDEP_CHAIN_HLOCKS);\r\n#endif\r\n#ifdef CONFIG_TRACE_IRQFLAGS\r\nseq_printf(m, " in-hardirq chains: %11u\n",\r\nnr_hardirq_chains);\r\nseq_printf(m, " in-softirq chains: %11u\n",\r\nnr_softirq_chains);\r\n#endif\r\nseq_printf(m, " in-process chains: %11u\n",\r\nnr_process_chains);\r\nseq_printf(m, " stack-trace entries: %11lu [max: %lu]\n",\r\nnr_stack_trace_entries, MAX_STACK_TRACE_ENTRIES);\r\nseq_printf(m, " combined max dependencies: %11u\n",\r\n(nr_hardirq_chains + 1) *\r\n(nr_softirq_chains + 1) *\r\n(nr_process_chains + 1)\r\n);\r\nseq_printf(m, " hardirq-safe locks: %11lu\n",\r\nnr_hardirq_safe);\r\nseq_printf(m, " hardirq-unsafe locks: %11lu\n",\r\nnr_hardirq_unsafe);\r\nseq_printf(m, " softirq-safe locks: %11lu\n",\r\nnr_softirq_safe);\r\nseq_printf(m, " softirq-unsafe locks: %11lu\n",\r\nnr_softirq_unsafe);\r\nseq_printf(m, " irq-safe locks: %11lu\n",\r\nnr_irq_safe);\r\nseq_printf(m, " irq-unsafe locks: %11lu\n",\r\nnr_irq_unsafe);\r\nseq_printf(m, " hardirq-read-safe locks: %11lu\n",\r\nnr_hardirq_read_safe);\r\nseq_printf(m, " hardirq-read-unsafe locks: %11lu\n",\r\nnr_hardirq_read_unsafe);\r\nseq_printf(m, " softirq-read-safe locks: %11lu\n",\r\nnr_softirq_read_safe);\r\nseq_printf(m, " softirq-read-unsafe locks: %11lu\n",\r\nnr_softirq_read_unsafe);\r\nseq_printf(m, " irq-read-safe locks: %11lu\n",\r\nnr_irq_read_safe);\r\nseq_printf(m, " irq-read-unsafe locks: %11lu\n",\r\nnr_irq_read_unsafe);\r\nseq_printf(m, " uncategorized locks: %11lu\n",\r\nnr_uncategorized);\r\nseq_printf(m, " unused locks: %11lu\n",\r\nnr_unused);\r\nseq_printf(m, " max locking depth: %11u\n",\r\nmax_lockdep_depth);\r\n#ifdef CONFIG_PROVE_LOCKING\r\nseq_printf(m, " max bfs queue depth: %11u\n",\r\nmax_bfs_queue_depth);\r\n#endif\r\nlockdep_stats_debug_show(m);\r\nseq_printf(m, " debug_locks: %11u\n",\r\ndebug_locks);\r\nreturn 0;\r\n}\r\nstatic int lockdep_stats_open(struct inode *inode, struct file *file)\r\n{\r\nreturn single_open(file, lockdep_stats_show, NULL);\r\n}\r\nstatic int lock_stat_cmp(const void *l, const void *r)\r\n{\r\nconst struct lock_stat_data *dl = l, *dr = r;\r\nunsigned long nl, nr;\r\nnl = dl->stats.read_waittime.nr + dl->stats.write_waittime.nr;\r\nnr = dr->stats.read_waittime.nr + dr->stats.write_waittime.nr;\r\nreturn nr - nl;\r\n}\r\nstatic void seq_line(struct seq_file *m, char c, int offset, int length)\r\n{\r\nint i;\r\nfor (i = 0; i < offset; i++)\r\nseq_puts(m, " ");\r\nfor (i = 0; i < length; i++)\r\nseq_printf(m, "%c", c);\r\nseq_puts(m, "\n");\r\n}\r\nstatic void snprint_time(char *buf, size_t bufsiz, s64 nr)\r\n{\r\ns64 div;\r\ns32 rem;\r\nnr += 5;\r\ndiv = div_s64_rem(nr, 1000, &rem);\r\nsnprintf(buf, bufsiz, "%lld.%02d", (long long)div, (int)rem/10);\r\n}\r\nstatic void seq_time(struct seq_file *m, s64 time)\r\n{\r\nchar num[15];\r\nsnprint_time(num, sizeof(num), time);\r\nseq_printf(m, " %14s", num);\r\n}\r\nstatic void seq_lock_time(struct seq_file *m, struct lock_time *lt)\r\n{\r\nseq_printf(m, "%14lu", lt->nr);\r\nseq_time(m, lt->min);\r\nseq_time(m, lt->max);\r\nseq_time(m, lt->total);\r\n}\r\nstatic void seq_stats(struct seq_file *m, struct lock_stat_data *data)\r\n{\r\nchar name[39];\r\nstruct lock_class *class;\r\nstruct lock_class_stats *stats;\r\nint i, namelen;\r\nclass = data->class;\r\nstats = &data->stats;\r\nnamelen = 38;\r\nif (class->name_version > 1)\r\nnamelen -= 2;\r\nif (class->subclass)\r\nnamelen -= 2;\r\nif (!class->name) {\r\nchar str[KSYM_NAME_LEN];\r\nconst char *key_name;\r\nkey_name = __get_key_name(class->key, str);\r\nsnprintf(name, namelen, "%s", key_name);\r\n} else {\r\nsnprintf(name, namelen, "%s", class->name);\r\n}\r\nnamelen = strlen(name);\r\nif (class->name_version > 1) {\r\nsnprintf(name+namelen, 3, "#%d", class->name_version);\r\nnamelen += 2;\r\n}\r\nif (class->subclass) {\r\nsnprintf(name+namelen, 3, "/%d", class->subclass);\r\nnamelen += 2;\r\n}\r\nif (stats->write_holdtime.nr) {\r\nif (stats->read_holdtime.nr)\r\nseq_printf(m, "%38s-W:", name);\r\nelse\r\nseq_printf(m, "%40s:", name);\r\nseq_printf(m, "%14lu ", stats->bounces[bounce_contended_write]);\r\nseq_lock_time(m, &stats->write_waittime);\r\nseq_printf(m, " %14lu ", stats->bounces[bounce_acquired_write]);\r\nseq_lock_time(m, &stats->write_holdtime);\r\nseq_puts(m, "\n");\r\n}\r\nif (stats->read_holdtime.nr) {\r\nseq_printf(m, "%38s-R:", name);\r\nseq_printf(m, "%14lu ", stats->bounces[bounce_contended_read]);\r\nseq_lock_time(m, &stats->read_waittime);\r\nseq_printf(m, " %14lu ", stats->bounces[bounce_acquired_read]);\r\nseq_lock_time(m, &stats->read_holdtime);\r\nseq_puts(m, "\n");\r\n}\r\nif (stats->read_waittime.nr + stats->write_waittime.nr == 0)\r\nreturn;\r\nif (stats->read_holdtime.nr)\r\nnamelen += 2;\r\nfor (i = 0; i < LOCKSTAT_POINTS; i++) {\r\nchar ip[32];\r\nif (class->contention_point[i] == 0)\r\nbreak;\r\nif (!i)\r\nseq_line(m, '-', 40-namelen, namelen);\r\nsnprintf(ip, sizeof(ip), "[<%p>]",\r\n(void *)class->contention_point[i]);\r\nseq_printf(m, "%40s %14lu %29s %pS\n",\r\nname, stats->contention_point[i],\r\nip, (void *)class->contention_point[i]);\r\n}\r\nfor (i = 0; i < LOCKSTAT_POINTS; i++) {\r\nchar ip[32];\r\nif (class->contending_point[i] == 0)\r\nbreak;\r\nif (!i)\r\nseq_line(m, '-', 40-namelen, namelen);\r\nsnprintf(ip, sizeof(ip), "[<%p>]",\r\n(void *)class->contending_point[i]);\r\nseq_printf(m, "%40s %14lu %29s %pS\n",\r\nname, stats->contending_point[i],\r\nip, (void *)class->contending_point[i]);\r\n}\r\nif (i) {\r\nseq_puts(m, "\n");\r\nseq_line(m, '.', 0, 40 + 1 + 10 * (14 + 1));\r\nseq_puts(m, "\n");\r\n}\r\n}\r\nstatic void seq_header(struct seq_file *m)\r\n{\r\nseq_printf(m, "lock_stat version 0.3\n");\r\nif (unlikely(!debug_locks))\r\nseq_printf(m, "*WARNING* lock debugging disabled!! - possibly due to a lockdep warning\n");\r\nseq_line(m, '-', 0, 40 + 1 + 10 * (14 + 1));\r\nseq_printf(m, "%40s %14s %14s %14s %14s %14s %14s %14s %14s "\r\n"%14s %14s\n",\r\n"class name",\r\n"con-bounces",\r\n"contentions",\r\n"waittime-min",\r\n"waittime-max",\r\n"waittime-total",\r\n"acq-bounces",\r\n"acquisitions",\r\n"holdtime-min",\r\n"holdtime-max",\r\n"holdtime-total");\r\nseq_line(m, '-', 0, 40 + 1 + 10 * (14 + 1));\r\nseq_printf(m, "\n");\r\n}\r\nstatic void *ls_start(struct seq_file *m, loff_t *pos)\r\n{\r\nstruct lock_stat_seq *data = m->private;\r\nstruct lock_stat_data *iter;\r\nif (*pos == 0)\r\nreturn SEQ_START_TOKEN;\r\niter = data->stats + (*pos - 1);\r\nif (iter >= data->iter_end)\r\niter = NULL;\r\nreturn iter;\r\n}\r\nstatic void *ls_next(struct seq_file *m, void *v, loff_t *pos)\r\n{\r\n(*pos)++;\r\nreturn ls_start(m, pos);\r\n}\r\nstatic void ls_stop(struct seq_file *m, void *v)\r\n{\r\n}\r\nstatic int ls_show(struct seq_file *m, void *v)\r\n{\r\nif (v == SEQ_START_TOKEN)\r\nseq_header(m);\r\nelse\r\nseq_stats(m, v);\r\nreturn 0;\r\n}\r\nstatic int lock_stat_open(struct inode *inode, struct file *file)\r\n{\r\nint res;\r\nstruct lock_class *class;\r\nstruct lock_stat_seq *data = vmalloc(sizeof(struct lock_stat_seq));\r\nif (!data)\r\nreturn -ENOMEM;\r\nres = seq_open(file, &lockstat_ops);\r\nif (!res) {\r\nstruct lock_stat_data *iter = data->stats;\r\nstruct seq_file *m = file->private_data;\r\nlist_for_each_entry(class, &all_lock_classes, lock_entry) {\r\niter->class = class;\r\niter->stats = lock_stats(class);\r\niter++;\r\n}\r\ndata->iter_end = iter;\r\nsort(data->stats, data->iter_end - data->stats,\r\nsizeof(struct lock_stat_data),\r\nlock_stat_cmp, NULL);\r\nm->private = data;\r\n} else\r\nvfree(data);\r\nreturn res;\r\n}\r\nstatic ssize_t lock_stat_write(struct file *file, const char __user *buf,\r\nsize_t count, loff_t *ppos)\r\n{\r\nstruct lock_class *class;\r\nchar c;\r\nif (count) {\r\nif (get_user(c, buf))\r\nreturn -EFAULT;\r\nif (c != '0')\r\nreturn count;\r\nlist_for_each_entry(class, &all_lock_classes, lock_entry)\r\nclear_lock_stats(class);\r\n}\r\nreturn count;\r\n}\r\nstatic int lock_stat_release(struct inode *inode, struct file *file)\r\n{\r\nstruct seq_file *seq = file->private_data;\r\nvfree(seq->private);\r\nreturn seq_release(inode, file);\r\n}\r\nstatic int __init lockdep_proc_init(void)\r\n{\r\nproc_create("lockdep", S_IRUSR, NULL, &proc_lockdep_operations);\r\n#ifdef CONFIG_PROVE_LOCKING\r\nproc_create("lockdep_chains", S_IRUSR, NULL,\r\n&proc_lockdep_chains_operations);\r\n#endif\r\nproc_create("lockdep_stats", S_IRUSR, NULL,\r\n&proc_lockdep_stats_operations);\r\n#ifdef CONFIG_LOCK_STAT\r\nproc_create("lock_stat", S_IRUSR | S_IWUSR, NULL,\r\n&proc_lock_stat_operations);\r\n#endif\r\nreturn 0;\r\n}
