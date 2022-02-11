static void F_1 ( struct V_1 * V_2 )
{
if ( V_3 >= 0 ) {
F_2 ( V_2 , V_4 , V_3 ) ;
V_3 = - 1 ;
}
if ( V_5 >= 0 ) {
F_2 ( V_2 , V_6 , V_5 ) ;
V_5 = - 1 ;
}
}
static void T_1 F_3 ( struct V_1 * V_2 )
{
T_2 V_7 ;
F_4 ( V_2 , V_4 , & V_7 ) ;
F_2 ( V_2 , V_4 , V_7 | 0x10 ) ;
V_3 = V_7 ;
}
static void T_1 F_5 ( struct V_1 * V_2 )
{
T_2 V_7 ;
F_4 ( V_2 , V_6 , & V_7 ) ;
F_2 ( V_2 , V_6 , V_7 | 0x10 ) ;
V_5 = V_7 ;
}
static void T_1 F_6 ( struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
V_9 -> V_12 = & V_13 [ V_11 -> V_14 ] ;
V_9 -> V_15 = sizeof( struct V_16 ) ;
}
static int T_1 F_7 ( struct V_1 * V_2 ,
const struct V_10 * V_11 )
{
T_3 V_17 ;
T_3 V_18 ;
int V_19 ;
bool V_20 = false ;
struct V_21 * V_22 ;
F_8 ( V_2 , V_23 , & V_17 ) ;
V_18 = V_17 & 0x0000ff80 ;
if ( ! V_18 ) {
F_9 ( & V_2 -> V_2 , L_1 ) ;
V_24 [ V_25 ] . V_26 -- ;
goto V_27;
}
V_22 = & V_28 [ V_29 ] ;
V_22 -> V_30 = V_18 + V_31 ;
V_22 -> V_32 = V_18 + V_33 ;
V_19 = F_10 ( V_22 ) ;
if ( V_19 ) {
V_24 [ V_25 ] . V_26 -- ;
V_20 = true ;
} else {
F_3 ( V_2 ) ;
}
V_27:
F_8 ( V_2 , V_34 , & V_17 ) ;
V_18 = V_17 & 0x0000ff80 ;
if ( ! V_18 ) {
F_9 ( & V_2 -> V_2 , L_2 ) ;
V_19 = - V_35 ;
goto V_36;
}
V_22 = & V_28 [ V_37 ] ;
V_22 -> V_30 = V_18 ;
switch ( V_13 [ V_11 -> V_14 ] . V_38 ) {
case V_39 :
case V_40 :
V_22 -> V_32 = V_22 -> V_30 + 128 - 1 ;
break;
default:
V_22 -> V_32 = V_22 -> V_30 + 64 - 1 ;
break;
}
V_19 = F_10 ( V_22 ) ;
if ( V_19 ) {
V_20 = true ;
goto V_36;
}
F_5 ( V_2 ) ;
F_6 ( & V_24 [ V_25 ] , V_11 ) ;
V_19 = F_11 ( & V_2 -> V_2 , - 1 , & V_24 [ V_25 ] ,
1 , NULL , 0 ) ;
V_36:
if ( V_20 )
F_12 ( L_3 ,
V_24 [ V_25 ] . V_41 ) ;
return V_19 ;
}
static int T_1 F_13 ( struct V_1 * V_2 ,
const struct V_10 * V_11 )
{
T_3 V_17 ;
T_3 V_18 ;
int V_19 ;
bool V_20 = false ;
struct V_21 * V_22 ;
F_8 ( V_2 , V_23 , & V_17 ) ;
V_18 = V_17 & 0x0000ff80 ;
if ( ! V_18 ) {
F_9 ( & V_2 -> V_2 , L_1 ) ;
V_19 = - V_35 ;
goto V_42;
}
V_22 = F_14 ( V_43 ) ;
V_22 -> V_30 = V_18 + V_44 ;
V_22 -> V_32 = V_18 + V_45 ;
V_19 = F_10 ( V_22 ) ;
if ( V_19 ) {
V_20 = true ;
goto V_42;
}
V_22 = F_14 ( V_46 ) ;
V_22 -> V_30 = V_18 + V_47 ;
V_22 -> V_32 = V_18 + V_48 ;
V_19 = F_10 ( V_22 ) ;
if ( V_19 ) {
V_20 = true ;
goto V_42;
}
F_3 ( V_2 ) ;
if ( V_13 [ V_11 -> V_14 ] . V_49 == 2 ) {
F_8 ( V_2 , V_50 , & V_17 ) ;
V_18 = V_17 & 0xffffc000 ;
if ( ! ( V_17 & 1 ) ) {
F_15 ( L_4
L_5 ) ;
V_19 = - V_35 ;
goto V_42;
}
V_22 = F_16 ( V_51 ) ;
V_22 -> V_30 = V_18 + V_52 ;
V_22 -> V_32 = V_18 + V_53 ;
V_19 = F_10 ( V_22 ) ;
if ( V_19 ) {
V_20 = true ;
goto V_42;
}
}
F_6 ( & V_24 [ V_54 ] , V_11 ) ;
V_19 = F_11 ( & V_2 -> V_2 , - 1 , & V_24 [ V_54 ] ,
1 , NULL , 0 ) ;
V_42:
if ( V_20 )
F_12 ( L_3 ,
V_24 [ V_54 ] . V_41 ) ;
return V_19 ;
}
static int T_1 F_17 ( struct V_1 * V_2 ,
const struct V_10 * V_11 )
{
int V_19 ;
bool V_55 = false ;
V_19 = F_13 ( V_2 , V_11 ) ;
if ( ! V_19 )
V_55 = true ;
V_19 = F_7 ( V_2 , V_11 ) ;
if ( ! V_19 )
V_55 = true ;
if ( ! V_55 ) {
F_1 ( V_2 ) ;
return - V_35 ;
}
return 0 ;
}
static void T_4 F_18 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_2 ) ;
F_1 ( V_2 ) ;
}
static int T_5 F_20 ( void )
{
return F_21 ( & V_56 ) ;
}
static void T_6 F_22 ( void )
{
F_23 ( & V_56 ) ;
}
