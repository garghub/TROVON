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
static void F_4 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
unsigned long V_10 = 0 , V_1 = 0 ;
unsigned long V_2 ;
struct V_11 V_12 ;
if ( V_5 [ V_9 ] . V_6 > V_13 ) {
F_5 (KERN_ERR PFX L_1 ) ;
return;
}
V_12 . V_14 = V_15 * F_1 () ;
V_12 . V_16 = V_15 * V_5 [ V_9 ] . V_6 ;
F_6 ( V_8 , & V_12 , V_17 ) ;
V_10 = ( 1 << 12 ) | ( 1 << 10 ) | ( 1 << 9 ) | ( V_9 << 5 ) ;
V_2 = V_3 + 0x1 ;
F_2 ( V_4 , V_2 , 0 ) ;
V_1 = F_3 ( V_3 + 0x8 ) ;
V_1 = V_1 & 0xf ;
V_10 = V_10 | V_1 ;
F_7 ( V_10 , ( V_3 + 0x8 ) ) ;
V_2 = V_3 + 0x0 ;
F_2 ( V_4 , V_2 , 0 ) ;
F_6 ( V_8 , & V_12 , V_18 ) ;
return;
}
static int F_8 ( struct V_7 * V_8 )
{
return F_9 ( V_8 , & V_5 [ 0 ] ) ;
}
static int F_10 ( struct V_7 * V_8 ,
unsigned int V_19 ,
unsigned int V_20 )
{
unsigned int V_21 = 0 ;
if ( F_11 ( V_8 , & V_5 [ 0 ] ,
V_19 , V_20 , & V_21 ) )
return - V_22 ;
F_4 ( V_8 , V_21 ) ;
return 0 ;
}
static int F_12 ( struct V_7 * V_8 )
{
unsigned int V_23 , V_24 ;
int V_25 ;
if ( V_8 -> V_26 != 0 )
return - V_27 ;
V_13 = F_1 () ;
V_15 = V_28 / V_13 ;
for ( V_23 = 0 ; ( V_5 [ V_23 ] . V_29 != V_30 ) ; V_23 ++ ) {
V_24 = V_5 [ V_23 ] . V_6 ;
if ( V_24 > V_13 )
V_5 [ V_23 ] . V_29 = V_31 ;
else
V_5 [ V_23 ] . V_29 = V_15 * V_24 ;
}
V_8 -> V_32 . V_33 = 200000 ;
V_8 -> V_34 = V_15 * V_13 ;
V_25 = F_13 ( V_8 , V_5 ) ;
if ( V_25 )
return V_25 ;
F_14 ( V_5 , V_8 -> V_26 ) ;
return 0 ;
}
static int F_15 ( struct V_7 * V_8 )
{
unsigned int V_23 ;
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ ) {
if ( V_23 == V_13 )
F_4 ( V_8 , V_23 ) ;
}
F_16 ( V_8 -> V_26 ) ;
return 0 ;
}
static unsigned int F_17 ( unsigned int V_26 )
{
unsigned int V_35 ;
V_35 = ( V_15 * F_1 () ) ;
return V_35 ;
}
static int T_3 F_18 ( void )
{
if ( ! F_19 ( V_36 ) )
return - V_27 ;
if ( ! F_20 ( V_3 , 16 , L_2 ) ) {
F_5 (KERN_INFO PFX L_3 ) ;
return - V_37 ;
}
if ( F_21 ( & V_38 ) ) {
F_22 ( V_3 , 16 ) ;
return - V_22 ;
}
return 0 ;
}
static void T_4 F_23 ( void )
{
F_24 ( & V_38 ) ;
F_22 ( V_3 , 16 ) ;
}
