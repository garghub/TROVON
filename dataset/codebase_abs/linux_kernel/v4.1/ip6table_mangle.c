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
V_5 = F_3 ( V_2 , V_13 , V_4 ,
F_4 ( V_4 -> V_14 ) -> V_15 . V_16 ) ;
if ( V_5 != V_17 && V_5 != V_18 &&
( ! F_5 ( & F_2 ( V_2 ) -> V_7 , & V_7 ) ||
! F_5 ( & F_2 ( V_2 ) -> V_8 , & V_8 ) ||
V_2 -> V_11 != V_11 ||
F_2 ( V_2 ) -> V_9 != V_9 ||
V_10 != * ( ( T_2 * ) F_2 ( V_2 ) ) ) ) {
V_12 = F_6 ( V_2 ) ;
if ( V_12 < 0 )
V_5 = F_7 ( V_12 ) ;
}
return V_5 ;
}
static unsigned int
F_8 ( const struct V_19 * V_20 , struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( V_20 -> V_21 == V_13 )
return F_1 ( V_2 , V_4 ) ;
if ( V_20 -> V_21 == V_22 )
return F_3 ( V_2 , V_20 -> V_21 , V_4 ,
F_4 ( V_4 -> V_14 ) -> V_15 . V_16 ) ;
return F_3 ( V_2 , V_20 -> V_21 , V_4 ,
F_4 ( V_4 -> V_23 ) -> V_15 . V_16 ) ;
}
static int T_3 F_9 ( struct V_24 * V_24 )
{
struct V_25 * V_26 ;
V_26 = F_10 ( & V_27 ) ;
if ( V_26 == NULL )
return - V_28 ;
V_24 -> V_15 . V_16 =
F_11 ( V_24 , & V_27 , V_26 ) ;
F_12 ( V_26 ) ;
return F_13 ( V_24 -> V_15 . V_16 ) ;
}
static void T_4 F_14 ( struct V_24 * V_24 )
{
F_15 ( V_24 , V_24 -> V_15 . V_16 ) ;
}
static int T_5 F_16 ( void )
{
int V_5 ;
V_5 = F_17 ( & V_29 ) ;
if ( V_5 < 0 )
return V_5 ;
V_30 = F_18 ( & V_27 , F_8 ) ;
if ( F_19 ( V_30 ) ) {
V_5 = F_20 ( V_30 ) ;
goto V_31;
}
return V_5 ;
V_31:
F_21 ( & V_29 ) ;
return V_5 ;
}
static void T_6 F_22 ( void )
{
F_23 ( & V_27 , V_30 ) ;
F_21 ( & V_29 ) ;
}
