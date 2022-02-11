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
V_5 = F_3 ( V_2 , V_13 , NULL , V_4 ,
F_4 ( V_4 ) -> V_14 . V_15 ) ;
if ( V_5 != V_16 && V_5 != V_17 &&
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
F_8 ( unsigned int V_18 , struct V_1 * V_2 ,
const struct V_3 * V_19 , const struct V_3 * V_4 ,
int (* F_9)( struct V_1 * ) )
{
if ( V_18 == V_13 )
return F_1 ( V_2 , V_4 ) ;
if ( V_18 == V_20 )
return F_3 ( V_2 , V_18 , V_19 , V_4 ,
F_4 ( V_4 ) -> V_14 . V_15 ) ;
return F_3 ( V_2 , V_18 , V_19 , V_4 ,
F_4 ( V_19 ) -> V_14 . V_15 ) ;
}
static int T_3 F_10 ( struct V_21 * V_21 )
{
struct V_22 * V_23 ;
V_23 = F_11 ( & V_24 ) ;
if ( V_23 == NULL )
return - V_25 ;
V_21 -> V_14 . V_15 =
F_12 ( V_21 , & V_24 , V_23 ) ;
F_13 ( V_23 ) ;
return F_14 ( V_21 -> V_14 . V_15 ) ;
}
static void T_4 F_15 ( struct V_21 * V_21 )
{
F_16 ( V_21 , V_21 -> V_14 . V_15 ) ;
}
static int T_5 F_17 ( void )
{
int V_5 ;
V_5 = F_18 ( & V_26 ) ;
if ( V_5 < 0 )
return V_5 ;
V_27 = F_19 ( & V_24 , F_8 ) ;
if ( F_20 ( V_27 ) ) {
V_5 = F_21 ( V_27 ) ;
goto V_28;
}
return V_5 ;
V_28:
F_22 ( & V_26 ) ;
return V_5 ;
}
static void T_6 F_23 ( void )
{
F_24 ( & V_24 , V_27 ) ;
F_22 ( & V_26 ) ;
}
