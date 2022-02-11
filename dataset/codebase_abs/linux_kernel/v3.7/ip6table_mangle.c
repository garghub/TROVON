static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
unsigned int V_5 ;
struct V_6 V_7 , V_8 ;
T_1 V_9 ;
T_2 V_10 , V_11 ;
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
V_5 = F_3 ( V_2 , V_12 , NULL , V_4 ,
F_4 ( V_4 ) -> V_13 . V_14 ) ;
if ( V_5 != V_15 && V_5 != V_16 &&
( memcmp ( & F_2 ( V_2 ) -> V_7 , & V_7 , sizeof( V_7 ) ) ||
memcmp ( & F_2 ( V_2 ) -> V_8 , & V_8 , sizeof( V_8 ) ) ||
V_2 -> V_11 != V_11 ||
F_2 ( V_2 ) -> V_9 != V_9 ||
V_10 != * ( ( T_2 * ) F_2 ( V_2 ) ) ) )
return F_5 ( V_2 ) == 0 ? V_5 : V_15 ;
return V_5 ;
}
static unsigned int
F_6 ( unsigned int V_17 , struct V_1 * V_2 ,
const struct V_3 * V_18 , const struct V_3 * V_4 ,
int (* F_7)( struct V_1 * ) )
{
if ( V_17 == V_12 )
return F_1 ( V_2 , V_4 ) ;
if ( V_17 == V_19 )
return F_3 ( V_2 , V_17 , V_18 , V_4 ,
F_4 ( V_4 ) -> V_13 . V_14 ) ;
return F_3 ( V_2 , V_17 , V_18 , V_4 ,
F_4 ( V_18 ) -> V_13 . V_14 ) ;
}
static int T_3 F_8 ( struct V_20 * V_20 )
{
struct V_21 * V_22 ;
V_22 = F_9 ( & V_23 ) ;
if ( V_22 == NULL )
return - V_24 ;
V_20 -> V_13 . V_14 =
F_10 ( V_20 , & V_23 , V_22 ) ;
F_11 ( V_22 ) ;
return F_12 ( V_20 -> V_13 . V_14 ) ;
}
static void T_4 F_13 ( struct V_20 * V_20 )
{
F_14 ( V_20 , V_20 -> V_13 . V_14 ) ;
}
static int T_5 F_15 ( void )
{
int V_5 ;
V_5 = F_16 ( & V_25 ) ;
if ( V_5 < 0 )
return V_5 ;
V_26 = F_17 ( & V_23 , F_6 ) ;
if ( F_18 ( V_26 ) ) {
V_5 = F_19 ( V_26 ) ;
goto V_27;
}
return V_5 ;
V_27:
F_20 ( & V_25 ) ;
return V_5 ;
}
static void T_6 F_21 ( void )
{
F_22 ( & V_23 , V_26 ) ;
F_20 ( & V_25 ) ;
}
