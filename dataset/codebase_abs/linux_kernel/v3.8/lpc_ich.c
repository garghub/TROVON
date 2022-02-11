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
static void F_3 ( struct V_1 * V_2 )
{
T_1 V_7 ;
F_4 ( V_2 , V_4 , & V_7 ) ;
F_2 ( V_2 , V_4 , V_7 | 0x10 ) ;
V_3 = V_7 ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_7 ;
F_4 ( V_2 , V_6 , & V_7 ) ;
F_2 ( V_2 , V_6 , V_7 | 0x10 ) ;
V_5 = V_7 ;
}
static void F_6 ( struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
V_9 -> V_12 = & V_13 [ V_11 -> V_14 ] ;
V_9 -> V_15 = sizeof( struct V_16 ) ;
}
static int F_7 ( struct V_17 * V_18 )
{
int V_19 ;
T_1 V_20 = 0 ;
if ( F_8 ( V_18 ) >= 0x50 &&
! F_9 ( V_18 -> V_21 + 0x40 , 0x10 , L_1 ) )
V_20 |= 1 << 2 ;
if ( ! F_9 ( V_18 -> V_21 + 0x30 , 0x10 , L_2 ) )
V_20 |= 1 << 1 ;
V_19 = F_9 ( V_18 -> V_21 + 0x00 , 0x30 , L_3 ) ;
if ( ! V_19 )
V_20 |= 1 << 0 ;
return V_20 ? V_20 : V_19 ;
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_10 * V_11 )
{
T_2 V_22 ;
T_2 V_23 ;
int V_19 ;
bool V_24 = false ;
struct V_17 * V_18 ;
F_11 ( V_2 , V_25 , & V_22 ) ;
V_23 = V_22 & 0x0000ff80 ;
if ( ! V_23 ) {
F_12 ( & V_2 -> V_2 , L_4 ) ;
V_26 [ V_27 ] . V_28 -- ;
goto V_29;
}
V_18 = & V_30 [ V_31 ] ;
V_18 -> V_21 = V_23 + V_32 ;
V_18 -> V_33 = V_23 + V_34 ;
V_19 = F_13 ( V_18 ) ;
if ( V_19 ) {
V_26 [ V_27 ] . V_28 -- ;
V_24 = true ;
} else {
F_3 ( V_2 ) ;
}
V_29:
F_11 ( V_2 , V_35 , & V_22 ) ;
V_23 = V_22 & 0x0000ff80 ;
if ( ! V_23 ) {
F_12 ( & V_2 -> V_2 , L_5 ) ;
V_19 = - V_36 ;
goto V_37;
}
V_18 = & V_30 [ V_38 ] ;
V_18 -> V_21 = V_23 ;
switch ( V_13 [ V_11 -> V_14 ] . V_39 ) {
case V_40 :
case V_41 :
V_18 -> V_33 = V_18 -> V_21 + 128 - 1 ;
break;
default:
V_18 -> V_33 = V_18 -> V_21 + 64 - 1 ;
break;
}
V_19 = F_7 ( V_18 ) ;
if ( V_19 < 0 ) {
V_24 = true ;
goto V_37;
}
V_13 [ V_11 -> V_14 ] . V_20 = V_19 ;
F_5 ( V_2 ) ;
F_6 ( & V_26 [ V_27 ] , V_11 ) ;
V_19 = F_14 ( & V_2 -> V_2 , - 1 , & V_26 [ V_27 ] ,
1 , NULL , 0 , NULL ) ;
V_37:
if ( V_24 )
F_15 ( L_6 ,
V_26 [ V_27 ] . V_42 ) ;
return V_19 ;
}
static int F_16 ( struct V_1 * V_2 ,
const struct V_10 * V_11 )
{
T_2 V_22 ;
T_2 V_23 ;
int V_19 ;
struct V_17 * V_18 ;
F_11 ( V_2 , V_25 , & V_22 ) ;
V_23 = V_22 & 0x0000ff80 ;
if ( ! V_23 ) {
F_12 ( & V_2 -> V_2 , L_4 ) ;
V_19 = - V_36 ;
goto V_43;
}
V_18 = F_17 ( V_44 ) ;
V_18 -> V_21 = V_23 + V_45 ;
V_18 -> V_33 = V_23 + V_46 ;
V_18 = F_17 ( V_47 ) ;
V_18 -> V_21 = V_23 + V_48 ;
V_18 -> V_33 = V_23 + V_49 ;
F_3 ( V_2 ) ;
if ( V_13 [ V_11 -> V_14 ] . V_50 == 1 ) {
V_26 [ V_51 ] . V_28 -- ;
} else {
F_11 ( V_2 , V_52 , & V_22 ) ;
V_23 = V_22 & 0xffffc000 ;
if ( ! ( V_22 & 1 ) ) {
F_12 ( & V_2 -> V_2 , L_7
L_8 ) ;
V_19 = - V_36 ;
goto V_43;
}
V_18 = F_18 ( V_53 ) ;
V_18 -> V_21 = V_23 + V_54 ;
V_18 -> V_33 = V_23 + V_55 ;
}
F_6 ( & V_26 [ V_51 ] , V_11 ) ;
V_19 = F_14 ( & V_2 -> V_2 , - 1 , & V_26 [ V_51 ] ,
1 , NULL , 0 , NULL ) ;
V_43:
return V_19 ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_10 * V_11 )
{
int V_19 ;
bool V_56 = false ;
V_19 = F_16 ( V_2 , V_11 ) ;
if ( ! V_19 )
V_56 = true ;
V_19 = F_10 ( V_2 , V_11 ) ;
if ( ! V_19 )
V_56 = true ;
if ( ! V_56 ) {
F_20 ( & V_2 -> V_2 , L_9 ) ;
F_1 ( V_2 ) ;
return - V_36 ;
}
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_2 ) ;
F_1 ( V_2 ) ;
}
static int T_3 F_23 ( void )
{
return F_24 ( & V_57 ) ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_57 ) ;
}
