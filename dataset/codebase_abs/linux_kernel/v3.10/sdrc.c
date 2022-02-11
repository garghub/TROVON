void F_1 ( void )
{
V_1 . V_2 = F_2 ( V_3 ) ;
}
void F_3 ( void )
{
F_4 ( V_1 . V_2 , V_3 ) ;
}
int F_5 ( unsigned long V_4 ,
struct V_5 * * V_6 ,
struct V_5 * * V_7 )
{
struct V_5 * V_8 , * V_9 ;
if ( ! V_10 )
return - 1 ;
V_8 = V_10 ;
V_9 = V_11 ;
while ( V_8 -> V_12 && V_8 -> V_12 != V_4 ) {
V_8 ++ ;
if ( V_11 )
V_9 ++ ;
}
if ( ! V_8 -> V_12 )
return - 1 ;
* V_6 = V_8 ;
* V_7 = V_9 ;
return 0 ;
}
void T_1 F_6 ( void T_2 * V_13 , void T_2 * V_14 )
{
V_15 = V_13 ;
V_16 = V_14 ;
}
void T_1 F_7 ( struct V_5 * V_6 ,
struct V_5 * V_7 )
{
T_3 V_17 ;
V_17 = F_2 ( V_3 ) ;
V_17 &= ~ ( 0x3 << 3 ) ;
V_17 |= ( 0x2 << 3 ) ;
F_4 ( V_17 , V_3 ) ;
V_17 = F_8 ( V_18 ) ;
V_17 &= ~ ( 0x3 << 3 ) ;
V_17 |= ( 0x2 << 3 ) ;
F_9 ( V_17 , V_18 ) ;
V_10 = V_6 ;
V_11 = V_7 ;
V_17 = ( 1 << V_19 ) |
( 1 << V_20 ) ;
F_9 ( V_17 , V_21 ) ;
F_1 () ;
}
