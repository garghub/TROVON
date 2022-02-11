static int F_1 ( void )
{
unsigned long V_1 = 0 ;
T_1 V_2 ;
F_2 () ;
V_2 = V_3 + 0x1 ;
F_3 ( V_4 , V_2 , 0 ) ;
V_1 = F_4 ( V_3 + 0x8 ) ;
V_2 = V_3 + 0x0 ;
F_3 ( V_4 , V_2 , 0 ) ;
F_5 () ;
return V_5 [ V_6 [ ( V_1 >> 5 ) & 7 ] ] . V_7 ;
}
static void F_6 ( unsigned int V_8 )
{
unsigned long V_9 , V_1 ;
unsigned long V_2 ;
unsigned long V_10 ;
F_2 () ;
V_10 = F_7 () ;
F_8 ( V_10 | V_11 ) ;
F_9 () ;
V_9 = ( 1 << 12 ) | ( 1 << 10 ) | ( 1 << 9 ) | ( V_12 [ V_8 ] << 5 ) ;
V_2 = V_3 + 0x1 ;
F_3 ( V_4 , V_2 , 0 ) ;
V_1 = F_4 ( V_3 + 0x8 ) ;
V_1 = V_1 & 0x1f ;
V_9 = V_9 | V_1 ;
F_10 ( V_9 , ( V_3 + 0x8 ) ) ;
V_2 = V_3 + 0x0 ;
F_3 ( V_4 , V_2 , 0 ) ;
F_8 ( V_10 ) ;
F_5 () ;
}
static int F_11 ( struct V_13 * V_14 ,
unsigned int V_8 )
{
struct V_15 V_16 ;
if ( V_5 [ V_8 ] . V_7 > V_17 ) {
F_12 (KERN_ERR PFX L_1 ) ;
return - V_18 ;
}
V_16 . V_19 = V_20 * F_1 () ;
V_16 . V_21 = V_20 * V_5 [ V_8 ] . V_7 ;
F_13 ( V_14 , & V_16 , V_22 ) ;
F_6 ( V_8 ) ;
F_13 ( V_14 , & V_16 , V_23 ) ;
return 0 ;
}
static int F_14 ( struct V_13 * V_14 )
{
unsigned int V_24 , V_25 ;
unsigned V_26 ;
if ( V_14 -> V_27 != 0 )
return - V_28 ;
V_17 = 0 ;
V_26 = V_29 ;
for ( V_24 = 0 ; V_24 < F_15 ( V_30 ) ; V_24 ++ ) {
if ( V_26 >= V_30 [ V_24 ] . V_31 - V_32 &&
V_26 <= V_30 [ V_24 ] . V_31 + V_32 ) {
V_26 = V_30 [ V_24 ] . V_31 ;
V_17 = V_30 [ V_24 ] . V_33 ;
break;
}
}
if ( V_34 ) {
for ( V_24 = 0 ; ( V_5 [ V_24 ] . V_35 != V_36 ) ; V_24 ++ ) {
if ( V_5 [ V_24 ] . V_7 == V_34 ) {
V_17 = V_34 ;
goto V_37;
}
}
F_12 ( V_38 L_2 ) ;
return - V_18 ;
}
if ( ! V_17 ) {
F_12 ( V_39 L_3 , V_26 ) ;
F_12 ( V_39 L_4 ) ;
return - V_40 ;
}
V_37:
V_34 = V_17 ;
if ( V_41 ) {
if ( V_41 >= 50000 && V_41 <= 150000 ) {
V_20 = V_41 / 10 ;
goto V_42;
}
F_12 ( V_38 L_5 ) ;
return - V_18 ;
}
V_20 = V_26 / V_17 ;
V_42:
V_41 = V_20 * 10 ;
for ( V_24 = 0 ; ( V_5 [ V_24 ] . V_35 != V_36 ) ; V_24 ++ ) {
V_25 = V_5 [ V_24 ] . V_7 ;
if ( V_25 > V_17 )
V_5 [ V_24 ] . V_35 = V_43 ;
else
V_5 [ V_24 ] . V_35 = V_20 * V_25 ;
}
V_14 -> V_44 . V_45 = 500000 ;
return F_16 ( V_14 , V_5 ) ;
}
static int F_17 ( struct V_13 * V_14 )
{
unsigned int V_24 ;
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ ) {
if ( V_24 == V_17 )
F_11 ( V_14 , V_24 ) ;
}
F_18 ( V_14 -> V_27 ) ;
return 0 ;
}
static unsigned int F_19 ( unsigned int V_27 )
{
unsigned int V_46 ;
V_46 = ( V_20 * F_1 () ) ;
return V_46 ;
}
static int T_2 F_20 ( void )
{
if ( ! F_21 ( V_47 ) )
return - V_28 ;
if ( ! F_22 ( V_3 , 16 , L_6 ) ) {
F_12 (KERN_INFO PFX L_7 ) ;
return - V_48 ;
}
if ( F_23 ( & V_49 ) ) {
F_24 ( V_3 , 16 ) ;
return - V_18 ;
}
return 0 ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_49 ) ;
F_24 ( V_3 , 16 ) ;
}
