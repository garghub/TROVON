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
if ( V_5 [ V_8 ] . V_7 > V_15 ) {
F_12 ( L_1 ) ;
return - V_16 ;
}
F_6 ( V_8 ) ;
return 0 ;
}
static int F_13 ( struct V_13 * V_14 )
{
struct V_17 * V_18 ;
unsigned int V_19 , V_20 ;
unsigned V_21 ;
if ( V_14 -> V_22 != 0 )
return - V_23 ;
V_15 = 0 ;
V_21 = V_24 ;
for ( V_19 = 0 ; V_19 < F_14 ( V_25 ) ; V_19 ++ ) {
if ( V_21 >= V_25 [ V_19 ] . V_26 - V_27 &&
V_21 <= V_25 [ V_19 ] . V_26 + V_27 ) {
V_21 = V_25 [ V_19 ] . V_26 ;
V_15 = V_25 [ V_19 ] . V_28 ;
break;
}
}
if ( V_29 ) {
F_15 (pos, clock_ratio)
if ( V_18 -> V_7 == V_29 ) {
V_15 = V_29 ;
goto V_30;
}
F_12 ( L_2 ) ;
return - V_16 ;
}
if ( ! V_15 ) {
F_16 ( L_3 ,
V_21 ) ;
F_16 ( L_4 ) ;
return - V_31 ;
}
V_30:
V_29 = V_15 ;
if ( V_32 ) {
if ( V_32 >= 50000 && V_32 <= 150000 ) {
V_33 = V_32 / 10 ;
goto V_34;
}
F_12 ( L_5 ) ;
return - V_16 ;
}
V_33 = V_21 / V_15 ;
V_34:
V_32 = V_33 * 10 ;
F_15 (pos, clock_ratio) {
V_20 = V_18 -> V_7 ;
if ( V_20 > V_15 )
V_18 -> V_35 = V_36 ;
else
V_18 -> V_35 = V_33 * V_20 ;
}
V_14 -> V_37 . V_38 = 500000 ;
return F_17 ( V_14 , V_5 ) ;
}
static int F_18 ( struct V_13 * V_14 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; ( V_5 [ V_19 ] . V_35 != V_39 ) ; V_19 ++ ) {
if ( V_5 [ V_19 ] . V_7 == V_15 ) {
struct V_40 V_41 ;
V_41 . V_42 = V_14 -> V_43 ;
V_41 . V_44 = V_5 [ V_19 ] . V_35 ;
V_41 . V_45 = 0 ;
F_19 ( V_14 , & V_41 ) ;
F_11 ( V_14 , V_19 ) ;
F_20 ( V_14 , & V_41 , 0 ) ;
break;
}
}
return 0 ;
}
static unsigned int F_21 ( unsigned int V_22 )
{
unsigned int V_46 ;
V_46 = ( V_33 * F_1 () ) ;
return V_46 ;
}
static int T_2 F_22 ( void )
{
if ( ! F_23 ( V_47 ) )
return - V_23 ;
if ( ! F_24 ( V_3 , 16 , L_6 ) ) {
F_25 ( L_7 ) ;
return - V_48 ;
}
if ( F_26 ( & V_49 ) ) {
F_27 ( V_3 , 16 ) ;
return - V_16 ;
}
return 0 ;
}
static void T_3 F_28 ( void )
{
F_29 ( & V_49 ) ;
F_27 ( V_3 , 16 ) ;
}
