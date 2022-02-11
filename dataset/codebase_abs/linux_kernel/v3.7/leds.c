static T_1 F_1 ( void )
{
F_2 ( 0x09 , 0x24 ) ;
return F_3 ( 0x26 ) ;
}
static void F_4 ( T_1 V_1 )
{
F_2 ( 0x09 , 0x24 ) ;
F_2 ( V_1 , 0x26 ) ;
}
static void F_5 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
struct V_6 * V_7 = F_6 ( V_3 ,
struct V_6 , V_3 ) ;
T_1 V_8 = F_1 () ;
if ( V_5 != V_9 )
V_8 |= V_7 -> V_10 ;
else
V_8 &= ~ V_7 -> V_10 ;
F_4 ( V_8 ) ;
}
static enum V_4 F_7 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_6 ( V_3 ,
struct V_6 , V_3 ) ;
T_1 V_8 = F_1 () ;
return ( V_8 & V_7 -> V_10 ) ? V_11 : V_9 ;
}
static int T_2 F_8 ( void )
{
int V_12 ;
T_1 V_8 ;
if ( ! F_9 () )
return - V_13 ;
for ( V_12 = 0 ; V_12 < F_10 ( V_14 ) ; V_12 ++ ) {
struct V_6 * V_7 ;
V_7 = F_11 ( sizeof( * V_7 ) , V_15 ) ;
if ( ! V_7 )
break;
V_7 -> V_3 . V_16 = V_14 [ V_12 ] . V_16 ;
V_7 -> V_3 . V_17 = F_5 ;
V_7 -> V_3 . V_18 = F_7 ;
V_7 -> V_3 . V_19 = V_14 [ V_12 ] . V_20 ;
V_7 -> V_10 = F_12 ( V_12 + 5 ) ;
if ( F_13 ( NULL , & V_7 -> V_3 ) < 0 ) {
F_14 ( V_7 ) ;
break;
}
}
F_15 ( 0x24 , 4 , L_1 ) ;
V_8 = F_1 () ;
V_8 |= 1 << 10 ;
F_4 ( V_8 ) ;
return 0 ;
}
