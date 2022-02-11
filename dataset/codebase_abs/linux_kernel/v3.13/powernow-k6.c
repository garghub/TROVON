static int F_1 ( void )
{
T_1 V_1 = 0 ;
T_2 V_2 ;
V_2 = V_3 + 0x1 ;
F_2 ( V_4 , V_2 , 0 ) ;
V_1 = F_3 ( V_3 + 0x8 ) ;
V_2 = V_3 + 0x0 ;
F_2 ( V_4 , V_2 , 0 ) ;
return V_5 [ ( V_1 >> 5 ) & 7 ] . V_6 ;
}
static int F_4 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
unsigned long V_10 = 0 , V_1 = 0 ;
unsigned long V_2 ;
struct V_11 V_12 ;
if ( V_5 [ V_9 ] . V_6 > V_13 ) {
F_5 (KERN_ERR PFX L_1 ) ;
return - V_14 ;
}
V_12 . V_15 = V_16 * F_1 () ;
V_12 . V_17 = V_16 * V_5 [ V_9 ] . V_6 ;
F_6 ( V_8 , & V_12 , V_18 ) ;
V_10 = ( 1 << 12 ) | ( 1 << 10 ) | ( 1 << 9 ) | ( V_9 << 5 ) ;
V_2 = V_3 + 0x1 ;
F_2 ( V_4 , V_2 , 0 ) ;
V_1 = F_3 ( V_3 + 0x8 ) ;
V_1 = V_1 & 0xf ;
V_10 = V_10 | V_1 ;
F_7 ( V_10 , ( V_3 + 0x8 ) ) ;
V_2 = V_3 + 0x0 ;
F_2 ( V_4 , V_2 , 0 ) ;
F_6 ( V_8 , & V_12 , V_19 ) ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 )
{
unsigned int V_20 , V_21 ;
if ( V_8 -> V_22 != 0 )
return - V_23 ;
V_13 = F_1 () ;
V_16 = V_24 / V_13 ;
for ( V_20 = 0 ; ( V_5 [ V_20 ] . V_25 != V_26 ) ; V_20 ++ ) {
V_21 = V_5 [ V_20 ] . V_6 ;
if ( V_21 > V_13 )
V_5 [ V_20 ] . V_25 = V_27 ;
else
V_5 [ V_20 ] . V_25 = V_16 * V_21 ;
}
V_8 -> V_28 . V_29 = 200000 ;
return F_9 ( V_8 , V_5 ) ;
}
static int F_10 ( struct V_7 * V_8 )
{
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ ) {
if ( V_20 == V_13 )
F_4 ( V_8 , V_20 ) ;
}
F_11 ( V_8 -> V_22 ) ;
return 0 ;
}
static unsigned int F_12 ( unsigned int V_22 )
{
unsigned int V_30 ;
V_30 = ( V_16 * F_1 () ) ;
return V_30 ;
}
static int T_3 F_13 ( void )
{
if ( ! F_14 ( V_31 ) )
return - V_23 ;
if ( ! F_15 ( V_3 , 16 , L_2 ) ) {
F_5 (KERN_INFO PFX L_3 ) ;
return - V_32 ;
}
if ( F_16 ( & V_33 ) ) {
F_17 ( V_3 , 16 ) ;
return - V_14 ;
}
return 0 ;
}
static void T_4 F_18 ( void )
{
F_19 ( & V_33 ) ;
F_17 ( V_3 , 16 ) ;
}
