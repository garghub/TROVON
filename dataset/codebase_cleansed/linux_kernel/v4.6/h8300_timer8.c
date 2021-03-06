static irqreturn_t timer8_interrupt(int irq, void *dev_id)\r\n{\r\nstruct timer8_priv *p = dev_id;\r\nif (clockevent_state_oneshot(&p->ced))\r\niowrite16be(0x0000, p->mapbase + _8TCR);\r\np->ced.event_handler(&p->ced);\r\nbclr(CMFA, p->mapbase + _8TCSR);\r\nreturn IRQ_HANDLED;\r\n}\r\nstatic void timer8_set_next(struct timer8_priv *p, unsigned long delta)\r\n{\r\nif (delta >= 0x10000)\r\npr_warn("delta out of range\n");\r\nbclr(CMIEA, p->mapbase + _8TCR);\r\niowrite16be(delta, p->mapbase + TCORA);\r\niowrite16be(0x0000, p->mapbase + _8TCNT);\r\nbclr(CMFA, p->mapbase + _8TCSR);\r\nbset(CMIEA, p->mapbase + _8TCR);\r\n}\r\nstatic int timer8_enable(struct timer8_priv *p)\r\n{\r\niowrite16be(0xffff, p->mapbase + TCORA);\r\niowrite16be(0x0000, p->mapbase + _8TCNT);\r\niowrite16be(0x0c02, p->mapbase + _8TCR);\r\nreturn 0;\r\n}\r\nstatic int timer8_start(struct timer8_priv *p)\r\n{\r\nint ret;\r\nif ((p->flags & FLAG_STARTED))\r\nreturn 0;\r\nret = timer8_enable(p);\r\nif (!ret)\r\np->flags |= FLAG_STARTED;\r\nreturn ret;\r\n}\r\nstatic void timer8_stop(struct timer8_priv *p)\r\n{\r\niowrite16be(0x0000, p->mapbase + _8TCR);\r\n}\r\nstatic inline struct timer8_priv *ced_to_priv(struct clock_event_device *ced)\r\n{\r\nreturn container_of(ced, struct timer8_priv, ced);\r\n}\r\nstatic void timer8_clock_event_start(struct timer8_priv *p, unsigned long delta)\r\n{\r\nstruct clock_event_device *ced = &p->ced;\r\ntimer8_start(p);\r\nced->shift = 32;\r\nced->mult = div_sc(p->rate, NSEC_PER_SEC, ced->shift);\r\nced->max_delta_ns = clockevent_delta2ns(0xffff, ced);\r\nced->min_delta_ns = clockevent_delta2ns(0x0001, ced);\r\ntimer8_set_next(p, delta);\r\n}\r\nstatic int timer8_clock_event_shutdown(struct clock_event_device *ced)\r\n{\r\ntimer8_stop(ced_to_priv(ced));\r\nreturn 0;\r\n}\r\nstatic int timer8_clock_event_periodic(struct clock_event_device *ced)\r\n{\r\nstruct timer8_priv *p = ced_to_priv(ced);\r\npr_info("%s: used for periodic clock events\n", ced->name);\r\ntimer8_stop(p);\r\ntimer8_clock_event_start(p, (p->rate + HZ/2) / HZ);\r\nreturn 0;\r\n}\r\nstatic int timer8_clock_event_oneshot(struct clock_event_device *ced)\r\n{\r\nstruct timer8_priv *p = ced_to_priv(ced);\r\npr_info("%s: used for oneshot clock events\n", ced->name);\r\ntimer8_stop(p);\r\ntimer8_clock_event_start(p, 0x10000);\r\nreturn 0;\r\n}\r\nstatic int timer8_clock_event_next(unsigned long delta,\r\nstruct clock_event_device *ced)\r\n{\r\nstruct timer8_priv *p = ced_to_priv(ced);\r\nBUG_ON(!clockevent_state_oneshot(ced));\r\ntimer8_set_next(p, delta - 1);\r\nreturn 0;\r\n}\r\nstatic void __init h8300_8timer_init(struct device_node *node)\r\n{\r\nvoid __iomem *base;\r\nint irq;\r\nstruct clk *clk;\r\nclk = of_clk_get(node, 0);\r\nif (IS_ERR(clk)) {\r\npr_err("failed to get clock for clockevent\n");\r\nreturn;\r\n}\r\nbase = of_iomap(node, 0);\r\nif (!base) {\r\npr_err("failed to map registers for clockevent\n");\r\ngoto free_clk;\r\n}\r\nirq = irq_of_parse_and_map(node, 0);\r\nif (!irq) {\r\npr_err("failed to get irq for clockevent\n");\r\ngoto unmap_reg;\r\n}\r\ntimer8_priv.mapbase = base;\r\ntimer8_priv.rate = clk_get_rate(clk) / SCALE;\r\nif (!timer8_priv.rate) {\r\npr_err("Failed to get rate for the clocksource\n");\r\ngoto unmap_reg;\r\n}\r\nif (request_irq(irq, timer8_interrupt, IRQF_TIMER,\r\ntimer8_priv.ced.name, &timer8_priv) < 0) {\r\npr_err("failed to request irq %d for clockevent\n", irq);\r\ngoto unmap_reg;\r\n}\r\nclockevents_config_and_register(&timer8_priv.ced,\r\ntimer8_priv.rate, 1, 0x0000ffff);\r\nreturn;\r\nunmap_reg:\r\niounmap(base);\r\nfree_clk:\r\nclk_put(clk);\r\n}
