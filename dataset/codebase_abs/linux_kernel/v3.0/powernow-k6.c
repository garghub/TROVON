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
static void F_4 ( unsigned int V_7 )
{
unsigned long V_8 = 0 , V_1 = 0 ;
unsigned long V_2 ;
struct V_9 V_10 ;
if ( V_5 [ V_7 ] . V_6 > V_11 ) {
F_5 (KERN_ERR PFX L_1 ) ;
return;
}
V_10 . V_12 = V_13 * F_1 () ;
V_10 . V_14 = V_13 * V_5 [ V_7 ] . V_6 ;
V_10 . V_15 = 0 ;
F_6 ( & V_10 , V_16 ) ;
V_8 = ( 1 << 12 ) | ( 1 << 10 ) | ( 1 << 9 ) | ( V_7 << 5 ) ;
V_2 = V_3 + 0x1 ;
F_2 ( V_4 , V_2 , 0 ) ;
V_1 = F_3 ( V_3 + 0x8 ) ;
V_1 = V_1 & 0xf ;
V_8 = V_8 | V_1 ;
F_7 ( V_8 , ( V_3 + 0x8 ) ) ;
V_2 = V_3 + 0x0 ;
F_2 ( V_4 , V_2 , 0 ) ;
F_6 ( & V_10 , V_17 ) ;
return;
}
static int F_8 ( struct V_18 * V_19 )
{
return F_9 ( V_19 , & V_5 [ 0 ] ) ;
}
static int F_10 ( struct V_18 * V_19 ,
unsigned int V_20 ,
unsigned int V_21 )
{
unsigned int V_22 = 0 ;
if ( F_11 ( V_19 , & V_5 [ 0 ] ,
V_20 , V_21 , & V_22 ) )
return - V_23 ;
F_4 ( V_22 ) ;
return 0 ;
}
static int F_12 ( struct V_18 * V_19 )
{
unsigned int V_24 , V_25 ;
int V_26 ;
if ( V_19 -> V_15 != 0 )
return - V_27 ;
V_11 = F_1 () ;
V_13 = V_28 / V_11 ;
for ( V_24 = 0 ; ( V_5 [ V_24 ] . V_29 != V_30 ) ; V_24 ++ ) {
V_25 = V_5 [ V_24 ] . V_6 ;
if ( V_25 > V_11 )
V_5 [ V_24 ] . V_29 = V_31 ;
else
V_5 [ V_24 ] . V_29 = V_13 * V_25 ;
}
V_19 -> V_32 . V_33 = 200000 ;
V_19 -> V_34 = V_13 * V_11 ;
V_26 = F_13 ( V_19 , V_5 ) ;
if ( V_26 )
return V_26 ;
F_14 ( V_5 , V_19 -> V_15 ) ;
return 0 ;
}
static int F_15 ( struct V_18 * V_19 )
{
unsigned int V_24 ;
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ ) {
if ( V_24 == V_11 )
F_4 ( V_24 ) ;
}
F_16 ( V_19 -> V_15 ) ;
return 0 ;
}
static unsigned int F_17 ( unsigned int V_15 )
{
unsigned int V_35 ;
V_35 = ( V_13 * F_1 () ) ;
return V_35 ;
}
static int T_3 F_18 ( void )
{
struct V_36 * V_37 = & F_19 ( 0 ) ;
if ( ( V_37 -> V_38 != V_39 ) || ( V_37 -> V_40 != 5 ) ||
( ( V_37 -> V_41 != 12 ) && ( V_37 -> V_41 != 13 ) ) )
return - V_27 ;
if ( ! F_20 ( V_3 , 16 , L_2 ) ) {
F_5 (KERN_INFO PFX L_3 ) ;
return - V_42 ;
}
if ( F_21 ( & V_43 ) ) {
F_22 ( V_3 , 16 ) ;
return - V_23 ;
}
return 0 ;
}
static void T_4 F_23 ( void )
{
F_24 ( & V_43 ) ;
F_22 ( V_3 , 16 ) ;
}
