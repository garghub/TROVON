static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = V_4 -> V_9 . V_10 ;
unsigned int V_11 , V_12 ;
int V_13 = 0 ;
V_11 = F_3 ( V_14 ) ;
if ( V_6 -> V_15 ) {
V_13 = 1 ;
goto V_16;
}
V_12 = V_11 & 0x70 ;
if ( V_12 & ( 1 << V_8 -> V_17 ) ) {
V_6 -> V_15 = ! ! ( V_12 & ( 1 << V_8 -> V_17 ) ) ;
if ( V_6 -> V_15 )
F_4 ( & V_6 -> V_18 , V_19 + 50 ) ;
V_13 = 1 ;
}
V_16:
V_11 |= ( 0x7 << 12 ) ;
F_5 ( V_11 , V_14 ) ;
return F_6 ( V_13 ) ;
}
static int T_2 F_7 ( void )
{
return F_8 ( V_20 , F_9 ( V_20 ) ) ;
}
