static inline int ip_vs_app_get(struct ip_vs_app *app)\r\n{\r\nreturn try_module_get(app->module);\r\n}\r\nstatic inline void ip_vs_app_put(struct ip_vs_app *app)\r\n{\r\nmodule_put(app->module);\r\n}\r\nstatic void ip_vs_app_inc_destroy(struct ip_vs_app *inc)\r\n{\r\nkfree(inc->timeout_table);\r\nkfree(inc);\r\n}\r\nstatic void ip_vs_app_inc_rcu_free(struct rcu_head *head)\r\n{\r\nstruct ip_vs_app *inc = container_of(head, struct ip_vs_app, rcu_head);\r\nip_vs_app_inc_destroy(inc);\r\n}\r\nstatic int\r\nip_vs_app_inc_new(struct netns_ipvs *ipvs, struct ip_vs_app *app, __u16 proto,\r\n__u16 port)\r\n{\r\nstruct ip_vs_protocol *pp;\r\nstruct ip_vs_app *inc;\r\nint ret;\r\nif (!(pp = ip_vs_proto_get(proto)))\r\nreturn -EPROTONOSUPPORT;\r\nif (!pp->unregister_app)\r\nreturn -EOPNOTSUPP;\r\ninc = kmemdup(app, sizeof(*inc), GFP_KERNEL);\r\nif (!inc)\r\nreturn -ENOMEM;\r\nINIT_LIST_HEAD(&inc->p_list);\r\nINIT_LIST_HEAD(&inc->incs_list);\r\ninc->app = app;\r\ninc->port = htons(port);\r\natomic_set(&inc->usecnt, 0);\r\nif (app->timeouts) {\r\ninc->timeout_table =\r\nip_vs_create_timeout_table(app->timeouts,\r\napp->timeouts_size);\r\nif (!inc->timeout_table) {\r\nret = -ENOMEM;\r\ngoto out;\r\n}\r\n}\r\nret = pp->register_app(ipvs, inc);\r\nif (ret)\r\ngoto out;\r\nlist_add(&inc->a_list, &app->incs_list);\r\nIP_VS_DBG(9, "%s App %s:%u registered\n",\r\npp->name, inc->name, ntohs(inc->port));\r\nreturn 0;\r\nout:\r\nip_vs_app_inc_destroy(inc);\r\nreturn ret;\r\n}\r\nstatic void\r\nip_vs_app_inc_release(struct netns_ipvs *ipvs, struct ip_vs_app *inc)\r\n{\r\nstruct ip_vs_protocol *pp;\r\nif (!(pp = ip_vs_proto_get(inc->protocol)))\r\nreturn;\r\nif (pp->unregister_app)\r\npp->unregister_app(ipvs, inc);\r\nIP_VS_DBG(9, "%s App %s:%u unregistered\n",\r\npp->name, inc->name, ntohs(inc->port));\r\nlist_del(&inc->a_list);\r\ncall_rcu(&inc->rcu_head, ip_vs_app_inc_rcu_free);\r\n}\r\nint ip_vs_app_inc_get(struct ip_vs_app *inc)\r\n{\r\nint result;\r\nresult = ip_vs_app_get(inc->app);\r\nif (result)\r\natomic_inc(&inc->usecnt);\r\nreturn result;\r\n}\r\nvoid ip_vs_app_inc_put(struct ip_vs_app *inc)\r\n{\r\natomic_dec(&inc->usecnt);\r\nip_vs_app_put(inc->app);\r\n}\r\nint\r\nregister_ip_vs_app_inc(struct netns_ipvs *ipvs, struct ip_vs_app *app, __u16 proto,\r\n__u16 port)\r\n{\r\nint result;\r\nmutex_lock(&__ip_vs_app_mutex);\r\nresult = ip_vs_app_inc_new(ipvs, app, proto, port);\r\nmutex_unlock(&__ip_vs_app_mutex);\r\nreturn result;\r\n}\r\nstruct ip_vs_app *register_ip_vs_app(struct netns_ipvs *ipvs, struct ip_vs_app *app)\r\n{\r\nstruct ip_vs_app *a;\r\nint err = 0;\r\nmutex_lock(&__ip_vs_app_mutex);\r\nlist_for_each_entry(a, &ipvs->app_list, a_list) {\r\nif (!strcmp(app->name, a->name)) {\r\nerr = -EEXIST;\r\ngoto out_unlock;\r\n}\r\n}\r\na = kmemdup(app, sizeof(*app), GFP_KERNEL);\r\nif (!a) {\r\nerr = -ENOMEM;\r\ngoto out_unlock;\r\n}\r\nINIT_LIST_HEAD(&a->incs_list);\r\nlist_add(&a->a_list, &ipvs->app_list);\r\nip_vs_use_count_inc();\r\nout_unlock:\r\nmutex_unlock(&__ip_vs_app_mutex);\r\nreturn err ? ERR_PTR(err) : a;\r\n}\r\nvoid unregister_ip_vs_app(struct netns_ipvs *ipvs, struct ip_vs_app *app)\r\n{\r\nstruct ip_vs_app *a, *anxt, *inc, *nxt;\r\nmutex_lock(&__ip_vs_app_mutex);\r\nlist_for_each_entry_safe(a, anxt, &ipvs->app_list, a_list) {\r\nif (app && strcmp(app->name, a->name))\r\ncontinue;\r\nlist_for_each_entry_safe(inc, nxt, &a->incs_list, a_list) {\r\nip_vs_app_inc_release(ipvs, inc);\r\n}\r\nlist_del(&a->a_list);\r\nkfree(a);\r\nip_vs_use_count_dec();\r\n}\r\nmutex_unlock(&__ip_vs_app_mutex);\r\n}\r\nint ip_vs_bind_app(struct ip_vs_conn *cp,\r\nstruct ip_vs_protocol *pp)\r\n{\r\nreturn pp->app_conn_bind(cp);\r\n}\r\nvoid ip_vs_unbind_app(struct ip_vs_conn *cp)\r\n{\r\nstruct ip_vs_app *inc = cp->app;\r\nif (!inc)\r\nreturn;\r\nif (inc->unbind_conn)\r\ninc->unbind_conn(inc, cp);\r\nif (inc->done_conn)\r\ninc->done_conn(inc, cp);\r\nip_vs_app_inc_put(inc);\r\ncp->app = NULL;\r\n}\r\nstatic inline void vs_fix_seq(const struct ip_vs_seq *vseq, struct tcphdr *th)\r\n{\r\n__u32 seq = ntohl(th->seq);\r\nif (vseq->delta || vseq->previous_delta) {\r\nif(after(seq, vseq->init_seq)) {\r\nth->seq = htonl(seq + vseq->delta);\r\nIP_VS_DBG(9, "%s(): added delta (%d) to seq\n",\r\n__func__, vseq->delta);\r\n} else {\r\nth->seq = htonl(seq + vseq->previous_delta);\r\nIP_VS_DBG(9, "%s(): added previous_delta (%d) to seq\n",\r\n__func__, vseq->previous_delta);\r\n}\r\n}\r\n}\r\nstatic inline void\r\nvs_fix_ack_seq(const struct ip_vs_seq *vseq, struct tcphdr *th)\r\n{\r\n__u32 ack_seq = ntohl(th->ack_seq);\r\nif (vseq->delta || vseq->previous_delta) {\r\nif(after(ack_seq, vseq->init_seq+vseq->delta)) {\r\nth->ack_seq = htonl(ack_seq - vseq->delta);\r\nIP_VS_DBG(9, "%s(): subtracted delta "\r\n"(%d) from ack_seq\n", __func__, vseq->delta);\r\n} else {\r\nth->ack_seq = htonl(ack_seq - vseq->previous_delta);\r\nIP_VS_DBG(9, "%s(): subtracted "\r\n"previous_delta (%d) from ack_seq\n",\r\n__func__, vseq->previous_delta);\r\n}\r\n}\r\n}\r\nstatic inline void vs_seq_update(struct ip_vs_conn *cp, struct ip_vs_seq *vseq,\r\nunsigned int flag, __u32 seq, int diff)\r\n{\r\nspin_lock_bh(&cp->lock);\r\nif (!(cp->flags & flag) || after(seq, vseq->init_seq)) {\r\nvseq->previous_delta = vseq->delta;\r\nvseq->delta += diff;\r\nvseq->init_seq = seq;\r\ncp->flags |= flag;\r\n}\r\nspin_unlock_bh(&cp->lock);\r\n}\r\nstatic inline int app_tcp_pkt_out(struct ip_vs_conn *cp, struct sk_buff *skb,\r\nstruct ip_vs_app *app)\r\n{\r\nint diff;\r\nconst unsigned int tcp_offset = ip_hdrlen(skb);\r\nstruct tcphdr *th;\r\n__u32 seq;\r\nif (!skb_make_writable(skb, tcp_offset + sizeof(*th)))\r\nreturn 0;\r\nth = (struct tcphdr *)(skb_network_header(skb) + tcp_offset);\r\nseq = ntohl(th->seq);\r\nif (cp->flags & IP_VS_CONN_F_OUT_SEQ)\r\nvs_fix_seq(&cp->out_seq, th);\r\nif (cp->flags & IP_VS_CONN_F_IN_SEQ)\r\nvs_fix_ack_seq(&cp->in_seq, th);\r\nif (app->pkt_out == NULL)\r\nreturn 1;\r\nif (!app->pkt_out(app, cp, skb, &diff))\r\nreturn 0;\r\nif (diff != 0)\r\nvs_seq_update(cp, &cp->out_seq,\r\nIP_VS_CONN_F_OUT_SEQ, seq, diff);\r\nreturn 1;\r\n}\r\nint ip_vs_app_pkt_out(struct ip_vs_conn *cp, struct sk_buff *skb)\r\n{\r\nstruct ip_vs_app *app;\r\nif ((app = cp->app) == NULL)\r\nreturn 1;\r\nif (cp->protocol == IPPROTO_TCP)\r\nreturn app_tcp_pkt_out(cp, skb, app);\r\nif (app->pkt_out == NULL)\r\nreturn 1;\r\nreturn app->pkt_out(app, cp, skb, NULL);\r\n}\r\nstatic inline int app_tcp_pkt_in(struct ip_vs_conn *cp, struct sk_buff *skb,\r\nstruct ip_vs_app *app)\r\n{\r\nint diff;\r\nconst unsigned int tcp_offset = ip_hdrlen(skb);\r\nstruct tcphdr *th;\r\n__u32 seq;\r\nif (!skb_make_writable(skb, tcp_offset + sizeof(*th)))\r\nreturn 0;\r\nth = (struct tcphdr *)(skb_network_header(skb) + tcp_offset);\r\nseq = ntohl(th->seq);\r\nif (cp->flags & IP_VS_CONN_F_IN_SEQ)\r\nvs_fix_seq(&cp->in_seq, th);\r\nif (cp->flags & IP_VS_CONN_F_OUT_SEQ)\r\nvs_fix_ack_seq(&cp->out_seq, th);\r\nif (app->pkt_in == NULL)\r\nreturn 1;\r\nif (!app->pkt_in(app, cp, skb, &diff))\r\nreturn 0;\r\nif (diff != 0)\r\nvs_seq_update(cp, &cp->in_seq,\r\nIP_VS_CONN_F_IN_SEQ, seq, diff);\r\nreturn 1;\r\n}\r\nint ip_vs_app_pkt_in(struct ip_vs_conn *cp, struct sk_buff *skb)\r\n{\r\nstruct ip_vs_app *app;\r\nif ((app = cp->app) == NULL)\r\nreturn 1;\r\nif (cp->protocol == IPPROTO_TCP)\r\nreturn app_tcp_pkt_in(cp, skb, app);\r\nif (app->pkt_in == NULL)\r\nreturn 1;\r\nreturn app->pkt_in(app, cp, skb, NULL);\r\n}\r\nstatic struct ip_vs_app *ip_vs_app_idx(struct netns_ipvs *ipvs, loff_t pos)\r\n{\r\nstruct ip_vs_app *app, *inc;\r\nlist_for_each_entry(app, &ipvs->app_list, a_list) {\r\nlist_for_each_entry(inc, &app->incs_list, a_list) {\r\nif (pos-- == 0)\r\nreturn inc;\r\n}\r\n}\r\nreturn NULL;\r\n}\r\nstatic void *ip_vs_app_seq_start(struct seq_file *seq, loff_t *pos)\r\n{\r\nstruct net *net = seq_file_net(seq);\r\nstruct netns_ipvs *ipvs = net_ipvs(net);\r\nmutex_lock(&__ip_vs_app_mutex);\r\nreturn *pos ? ip_vs_app_idx(ipvs, *pos - 1) : SEQ_START_TOKEN;\r\n}\r\nstatic void *ip_vs_app_seq_next(struct seq_file *seq, void *v, loff_t *pos)\r\n{\r\nstruct ip_vs_app *inc, *app;\r\nstruct list_head *e;\r\nstruct net *net = seq_file_net(seq);\r\nstruct netns_ipvs *ipvs = net_ipvs(net);\r\n++*pos;\r\nif (v == SEQ_START_TOKEN)\r\nreturn ip_vs_app_idx(ipvs, 0);\r\ninc = v;\r\napp = inc->app;\r\nif ((e = inc->a_list.next) != &app->incs_list)\r\nreturn list_entry(e, struct ip_vs_app, a_list);\r\nfor (e = app->a_list.next; e != &ipvs->app_list; e = e->next) {\r\napp = list_entry(e, struct ip_vs_app, a_list);\r\nlist_for_each_entry(inc, &app->incs_list, a_list) {\r\nreturn inc;\r\n}\r\n}\r\nreturn NULL;\r\n}\r\nstatic void ip_vs_app_seq_stop(struct seq_file *seq, void *v)\r\n{\r\nmutex_unlock(&__ip_vs_app_mutex);\r\n}\r\nstatic int ip_vs_app_seq_show(struct seq_file *seq, void *v)\r\n{\r\nif (v == SEQ_START_TOKEN)\r\nseq_puts(seq, "prot port usecnt name\n");\r\nelse {\r\nconst struct ip_vs_app *inc = v;\r\nseq_printf(seq, "%-3s %-7u %-6d %-17s\n",\r\nip_vs_proto_name(inc->protocol),\r\nntohs(inc->port),\r\natomic_read(&inc->usecnt),\r\ninc->name);\r\n}\r\nreturn 0;\r\n}\r\nstatic int ip_vs_app_open(struct inode *inode, struct file *file)\r\n{\r\nreturn seq_open_net(inode, file, &ip_vs_app_seq_ops,\r\nsizeof(struct seq_net_private));\r\n}\r\nint __net_init ip_vs_app_net_init(struct netns_ipvs *ipvs)\r\n{\r\nstruct net *net = ipvs->net;\r\nINIT_LIST_HEAD(&ipvs->app_list);\r\nproc_create("ip_vs_app", 0, net->proc_net, &ip_vs_app_fops);\r\nreturn 0;\r\n}\r\nvoid __net_exit ip_vs_app_net_cleanup(struct netns_ipvs *ipvs)\r\n{\r\nstruct net *net = ipvs->net;\r\nunregister_ip_vs_app(ipvs, NULL );\r\nremove_proc_entry("ip_vs_app", net->proc_net);\r\n}
