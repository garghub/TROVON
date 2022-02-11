void F_1 ( struct V_1 * V_2 )
{
F_2 () ;
if ( V_3 == & V_2 -> V_4 )
V_3 = NULL ;
F_3 () ;
}
static int F_4 ( T_1 V_5 )
{
return ! ! ( V_5 & V_6 ) ;
}
static int F_5 ( struct V_7 * V_8 , unsigned long V_9 , void * V_10 )
{
struct V_1 * V_2 = (struct V_1 * ) V_10 ;
struct V_11 * V_11 ;
T_1 V_5 ;
V_11 = & V_2 -> V_4 ;
switch ( V_9 ) {
case V_12 :
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
case V_13 :
F_1 ( V_2 ) ;
break;
case V_14 :
V_5 = F_6 ( V_15 ) ;
if ( F_4 ( V_5 ) || V_3 == V_11 ) {
V_5 ^= V_6 ;
F_7 ( 0xaa , V_16 ) ;
F_7 ( V_5 , V_15 ) ;
}
break;
}
return V_17 ;
}
int T_2 F_8 ( void )
{
F_9 ( & V_18 ) ;
V_19 |= V_20 ;
return 0 ;
}
