static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_4 ) ;
T_1 type = F_3 ( V_2 ) ;
int V_5 = V_2 -> V_5 - V_6 ;
if ( type & V_7 )
V_3 &= ~ ( 0x001 << V_5 ) ;
if ( type & V_8 )
V_3 &= ~ ( 0x100 << V_5 ) ;
F_4 ( V_3 , V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_4 ) ;
T_1 type = F_3 ( V_2 ) ;
int V_5 = V_2 -> V_5 - V_6 ;
if ( type & V_7 )
V_3 |= ( 0x001 << V_5 ) ;
if ( type & V_8 )
V_3 |= ( 0x100 << V_5 ) ;
F_4 ( V_3 , V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
T_1 type = F_3 ( V_2 ) ;
int V_5 = V_2 -> V_5 - V_6 ;
if ( type & V_7 )
V_3 |= ( 0x001 << V_5 ) ;
if ( type & V_8 )
V_3 |= ( 0x100 << V_5 ) ;
F_4 ( V_3 , V_9 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_10 )
{
if ( V_10 & ~ V_11 )
return - V_12 ;
return 0 ;
}
static int T_2 F_8 ( void )
{
int V_5 ;
F_4 ( V_13 , V_14 ) ;
for ( V_5 = V_6 ; ( V_5 <= V_15 ) ; V_5 ++ ) {
F_9 ( V_5 , & V_16 ) ;
F_10 ( V_5 , V_17 ) ;
}
return 0 ;
}
