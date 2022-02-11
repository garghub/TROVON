static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 >= 0 ) {
F_3 ( V_2 , V_4 -> V_6 , V_4 -> V_5 ) ;
V_4 -> V_5 = - 1 ;
}
if ( V_4 -> V_7 >= 0 ) {
F_3 ( V_2 , V_4 -> V_8 ,
V_4 -> V_7 ) ;
V_4 -> V_7 = - 1 ;
}
if ( V_4 -> V_9 >= 0 ) {
F_3 ( V_2 , V_4 -> V_10 , V_4 -> V_9 ) ;
V_4 -> V_9 = - 1 ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_11 ;
switch ( V_12 [ V_4 -> V_13 ] . V_14 ) {
case 3 :
F_5 ( V_2 , V_4 -> V_6 , & V_11 ) ;
F_3 ( V_2 , V_4 -> V_6 , V_11 | 0x2 ) ;
V_4 -> V_5 = V_11 ;
break;
default:
F_5 ( V_2 , V_4 -> V_8 , & V_11 ) ;
F_3 ( V_2 , V_4 -> V_8 , V_11 | 0x80 ) ;
V_4 -> V_7 = V_11 ;
break;
}
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_11 ;
F_5 ( V_2 , V_4 -> V_10 , & V_11 ) ;
F_3 ( V_2 , V_4 -> V_10 , V_11 | 0x10 ) ;
V_4 -> V_9 = V_11 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_11 ;
F_5 ( V_2 , V_4 -> V_8 , & V_11 ) ;
F_3 ( V_2 , V_4 -> V_8 , V_11 | 0x2 ) ;
V_4 -> V_7 = V_11 ;
}
static void F_8 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_16 -> V_17 = & V_12 [ V_4 -> V_13 ] ;
V_16 -> V_18 = sizeof( struct V_19 ) ;
}
static int F_9 ( struct V_20 * V_21 )
{
int V_22 ;
T_1 V_23 = 0 ;
if ( F_10 ( V_21 ) >= 0x50 &&
! F_11 ( V_21 -> V_24 + 0x40 , 0x10 , L_1 ) )
V_23 |= 1 << 2 ;
if ( ! F_11 ( V_21 -> V_24 + 0x30 , 0x10 , L_2 ) )
V_23 |= 1 << 1 ;
V_22 = F_11 ( V_21 -> V_24 + 0x00 , 0x30 , L_3 ) ;
if ( ! V_22 )
V_23 |= 1 << 0 ;
return V_23 ? V_23 : V_22 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_25 ;
T_2 V_26 ;
int V_22 ;
bool V_27 = false ;
struct V_20 * V_21 ;
F_13 ( V_2 , V_4 -> V_6 , & V_25 ) ;
V_26 = V_25 & 0x0000ff80 ;
if ( ! V_26 ) {
F_14 ( & V_2 -> V_2 , L_4 ) ;
V_28 [ V_29 ] . V_30 -- ;
goto V_31;
}
V_21 = & V_32 [ V_33 ] ;
V_21 -> V_24 = V_26 + V_34 ;
V_21 -> V_35 = V_26 + V_36 ;
V_22 = F_15 ( V_21 ) ;
if ( V_22 ) {
V_28 [ V_29 ] . V_30 -- ;
V_27 = true ;
} else {
F_4 ( V_2 ) ;
}
V_31:
F_13 ( V_2 , V_4 -> V_37 , & V_25 ) ;
V_26 = V_25 & 0x0000ff80 ;
if ( ! V_26 ) {
F_14 ( & V_2 -> V_2 , L_5 ) ;
V_22 = - V_38 ;
goto V_39;
}
V_21 = & V_32 [ V_40 ] ;
V_21 -> V_24 = V_26 ;
switch ( V_12 [ V_4 -> V_13 ] . V_41 ) {
case V_42 :
case V_43 :
V_21 -> V_35 = V_21 -> V_24 + 128 - 1 ;
break;
default:
V_21 -> V_35 = V_21 -> V_24 + 64 - 1 ;
break;
}
V_22 = F_9 ( V_21 ) ;
if ( V_22 < 0 ) {
V_27 = true ;
goto V_39;
}
V_12 [ V_4 -> V_13 ] . V_23 = V_22 ;
F_6 ( V_2 ) ;
F_8 ( V_2 , & V_28 [ V_29 ] ) ;
V_22 = F_16 ( & V_2 -> V_2 , - 1 , & V_28 [ V_29 ] ,
1 , NULL , 0 , NULL ) ;
V_39:
if ( V_27 )
F_17 ( L_6 ,
V_28 [ V_29 ] . V_44 ) ;
return V_22 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_25 ;
T_2 V_26 ;
int V_22 ;
struct V_20 * V_21 ;
F_13 ( V_2 , V_4 -> V_6 , & V_25 ) ;
V_26 = V_25 & 0x0000ff80 ;
if ( ! V_26 ) {
F_14 ( & V_2 -> V_2 , L_4 ) ;
V_22 = - V_38 ;
goto V_45;
}
V_21 = F_19 ( V_46 ) ;
V_21 -> V_24 = V_26 + V_47 ;
V_21 -> V_35 = V_26 + V_48 ;
V_21 = F_19 ( V_49 ) ;
V_21 -> V_24 = V_26 + V_50 ;
V_21 -> V_35 = V_26 + V_51 ;
F_4 ( V_2 ) ;
if ( V_12 [ V_4 -> V_13 ] . V_14 == 1 ) {
V_28 [ V_52 ] . V_30 -- ;
} else if ( V_12 [ V_4 -> V_13 ] . V_14 == 2 ) {
F_13 ( V_2 , V_53 , & V_25 ) ;
V_26 = V_25 & 0xffffc000 ;
if ( ! ( V_25 & 1 ) ) {
F_14 ( & V_2 -> V_2 , L_7
L_8 ) ;
V_22 = - V_38 ;
goto V_45;
}
V_21 = F_20 ( V_54 ) ;
V_21 -> V_24 = V_26 + V_55 ;
V_21 -> V_35 = V_26 + V_56 ;
} else if ( V_12 [ V_4 -> V_13 ] . V_14 == 3 ) {
F_7 ( V_2 ) ;
F_13 ( V_2 , V_57 , & V_25 ) ;
V_26 = V_25 & 0xfffffe00 ;
V_21 = F_20 ( V_54 ) ;
V_21 -> V_24 = V_26 + V_58 ;
V_21 -> V_35 = V_26 + V_59 ;
}
F_8 ( V_2 , & V_28 [ V_52 ] ) ;
V_22 = F_16 ( & V_2 -> V_2 , - 1 , & V_28 [ V_52 ] ,
1 , NULL , 0 , NULL ) ;
V_45:
return V_22 ;
}
static int F_21 ( struct V_1 * V_2 ,
const struct V_60 * V_61 )
{
struct V_3 * V_4 ;
int V_22 ;
bool V_62 = false ;
V_4 = F_22 ( & V_2 -> V_2 ,
sizeof( struct V_3 ) , V_63 ) ;
if ( ! V_4 )
return - V_64 ;
V_4 -> V_13 = V_61 -> V_65 ;
V_4 -> V_7 = - 1 ;
V_4 -> V_5 = - 1 ;
V_4 -> V_6 = V_66 ;
V_4 -> V_8 = V_57 ;
V_4 -> V_9 = - 1 ;
if ( V_4 -> V_13 <= V_67 ) {
V_4 -> V_37 = V_68 ;
V_4 -> V_10 = V_69 ;
} else {
V_4 -> V_37 = V_70 ;
V_4 -> V_10 = V_71 ;
}
F_23 ( V_2 , V_4 ) ;
if ( V_12 [ V_4 -> V_13 ] . V_14 ) {
V_22 = F_18 ( V_2 ) ;
if ( ! V_22 )
V_62 = true ;
}
if ( V_12 [ V_4 -> V_13 ] . V_41 ) {
V_22 = F_12 ( V_2 ) ;
if ( ! V_22 )
V_62 = true ;
}
if ( ! V_62 ) {
F_24 ( & V_2 -> V_2 , L_9 ) ;
F_1 ( V_2 ) ;
return - V_38 ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_26 ( & V_2 -> V_2 ) ;
F_1 ( V_2 ) ;
}
