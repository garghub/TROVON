static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 ;
static int V_8 = 0 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_9 , L_1 ) ;
goto V_10;
}
V_5 = F_4 ( V_2 , L_2 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_9 , L_3 ) ;
goto V_11;
}
V_7 = F_5 ( sizeof( struct V_6 ) , V_12 ) ;
if ( ! V_7 ) {
F_3 ( & V_2 -> V_9 ,
L_4 ) ;
V_5 = - V_13 ;
goto V_14;
}
V_7 -> V_15 = V_8 ++ ;
V_7 -> V_1 = V_2 ;
if ( V_2 -> V_16 == V_17 )
V_7 -> V_18 = 4 ;
else if ( V_2 -> V_16 == V_19 )
V_7 -> V_18 = 8 ;
else
V_7 -> V_18 = 2 ;
F_6 ( & V_7 -> V_20 ) ;
V_7 -> V_21 = V_2 -> V_22 ;
V_7 -> V_23 = V_2 -> V_23 ;
F_7 ( V_24 , & V_7 -> V_1 , L_5 ) ;
V_7 -> V_25 = F_8 ( V_2 , 0 ) ;
V_7 -> V_26 = F_9 ( V_2 , 0 ) ;
if ( V_7 -> V_25 & 1 )
V_7 -> V_25 &= ~ 3 ;
else
V_7 -> V_25 &= ~ 15 ;
V_7 -> V_27 = & V_28 ;
V_7 -> V_29 = 0x200 ;
V_7 -> V_30 = 921600 ;
V_7 -> V_31 = F_10 ( V_7 -> V_25 , F_11 ( V_2 , 0 ) ) ;
if ( ! V_7 -> V_31 ) {
F_3 ( & V_2 -> V_9 ,
L_6
L_7 ) ;
V_5 = - V_13 ;
goto V_32;
}
V_5 = F_12 ( V_7 -> V_23 , V_7 -> V_27 -> V_33 ,
V_34 , L_8 , V_7 ) ;
if ( V_5 ) {
F_13 ( V_35 L_9 , V_7 -> V_23 ) ;
goto V_36;
}
V_5 = F_14 ( V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_9 , L_10 , V_5 ) ;
V_5 = - V_37 ;
goto V_38;
}
V_5 = F_15 ( V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_9 , L_11 , V_5 ) ;
V_5 = - V_37 ;
goto V_38;
}
F_16 ( & V_2 -> V_9 , L_12 ,
V_8 , V_7 -> V_21 , V_7 -> V_23 ) ;
F_17 ( V_2 , V_7 ) ;
F_18 ( V_2 ) ;
return 0 ;
V_38:
F_19 ( V_7 ) ;
F_20 ( V_7 -> V_23 , V_7 ) ;
V_36:
F_21 ( V_7 -> V_31 ) ;
V_32:
F_22 ( V_7 ) ;
V_14:
F_23 ( V_2 ) ;
V_11:
F_24 ( V_2 ) ;
V_10:
return V_5 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_26 ( V_2 ) ;
int V_39 = 0 ;
F_19 ( V_7 ) ;
F_20 ( V_7 -> V_23 , V_7 ) ;
F_21 ( V_7 -> V_31 ) ;
for ( V_39 = 0 ; V_39 < V_7 -> V_18 ; V_39 ++ ) {
if ( V_7 -> V_40 [ V_39 ] ) {
F_22 ( V_7 -> V_40 [ V_39 ] -> V_41 ) ;
F_22 ( V_7 -> V_40 [ V_39 ] -> V_42 ) ;
F_22 ( V_7 -> V_40 [ V_39 ] ) ;
}
}
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
F_22 ( V_7 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
T_2 V_43 )
{
struct V_6 * V_7 = F_26 ( V_2 ) ;
F_19 ( V_7 ) ;
return V_44 ;
}
static T_1 F_28 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
return V_45 ;
F_29 ( V_2 ) ;
return V_46 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_26 ( V_2 ) ;
F_31 ( V_2 ) ;
F_18 ( V_2 ) ;
F_15 ( V_7 ) ;
}
static int T_3 F_32 ( void )
{
int V_5 ;
V_5 = F_33 ( & V_47 ) ;
if ( ! V_5 ) {
V_5 = F_34 ( & V_48 ) ;
if ( V_5 )
F_35 ( & V_47 ) ;
}
return V_5 ;
}
static void T_4 F_36 ( void )
{
F_37 ( & V_48 ) ;
F_35 ( & V_47 ) ;
}
