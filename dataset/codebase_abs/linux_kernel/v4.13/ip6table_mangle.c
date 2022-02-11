static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
unsigned int V_5 ;
struct V_6 V_7 , V_8 ;
T_1 V_9 ;
T_2 V_10 , V_11 ;
int V_12 ;
#if 0
if (skb->len < sizeof(struct iphdr) ||
ip_hdrlen(skb) < sizeof(struct iphdr)) {
net_warn_ratelimited("ip6t_hook: happy cracking\n");
return NF_ACCEPT;
}
#endif
memcpy ( & V_7 , & F_2 ( V_2 ) -> V_7 , sizeof( V_7 ) ) ;
memcpy ( & V_8 , & F_2 ( V_2 ) -> V_8 , sizeof( V_8 ) ) ;
V_11 = V_2 -> V_11 ;
V_9 = F_2 ( V_2 ) -> V_9 ;
V_10 = * ( ( T_2 * ) F_2 ( V_2 ) ) ;
V_5 = F_3 ( V_2 , V_4 , V_4 -> V_13 -> V_14 . V_15 ) ;
if ( V_5 != V_16 && V_5 != V_17 &&
( ! F_4 ( & F_2 ( V_2 ) -> V_7 , & V_7 ) ||
! F_4 ( & F_2 ( V_2 ) -> V_8 , & V_8 ) ||
V_2 -> V_11 != V_11 ||
F_2 ( V_2 ) -> V_9 != V_9 ||
V_10 != * ( ( T_2 * ) F_2 ( V_2 ) ) ) ) {
V_12 = F_5 ( V_4 -> V_13 , V_2 ) ;
if ( V_12 < 0 )
V_5 = F_6 ( V_12 ) ;
}
return V_5 ;
}
static unsigned int
F_7 ( void * V_18 , struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_19 == V_20 )
return F_1 ( V_2 , V_4 ) ;
return F_3 ( V_2 , V_4 , V_4 -> V_13 -> V_14 . V_15 ) ;
}
static int T_3 F_8 ( struct V_13 * V_13 )
{
struct V_21 * V_22 ;
int V_5 ;
if ( V_13 -> V_14 . V_15 )
return 0 ;
V_22 = F_9 ( & V_23 ) ;
if ( V_22 == NULL )
return - V_24 ;
V_5 = F_10 ( V_13 , & V_23 , V_22 , V_25 ,
& V_13 -> V_14 . V_15 ) ;
F_11 ( V_22 ) ;
return V_5 ;
}
static void T_4 F_12 ( struct V_13 * V_13 )
{
if ( ! V_13 -> V_14 . V_15 )
return;
F_13 ( V_13 , V_13 -> V_14 . V_15 , V_25 ) ;
V_13 -> V_14 . V_15 = NULL ;
}
static int T_5 F_14 ( void )
{
int V_5 ;
V_25 = F_15 ( & V_23 , F_7 ) ;
if ( F_16 ( V_25 ) )
return F_17 ( V_25 ) ;
V_5 = F_18 ( & V_26 ) ;
if ( V_5 < 0 ) {
F_11 ( V_25 ) ;
return V_5 ;
}
V_5 = F_8 ( & V_27 ) ;
if ( V_5 ) {
F_19 ( & V_26 ) ;
F_11 ( V_25 ) ;
}
return V_5 ;
}
static void T_6 F_20 ( void )
{
F_19 ( & V_26 ) ;
F_11 ( V_25 ) ;
}
