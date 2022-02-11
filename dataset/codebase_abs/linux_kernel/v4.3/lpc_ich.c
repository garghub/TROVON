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
static int F_8 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_17 * V_18 ;
struct V_19 * V_20 = & V_21 [ V_22 ] ;
V_16 = F_9 ( & V_2 -> V_2 , sizeof( * V_16 ) , V_23 ) ;
if ( ! V_16 )
return - V_24 ;
V_18 = & V_12 [ V_4 -> V_13 ] ;
V_16 -> V_25 = V_18 -> V_14 ;
F_10 ( V_16 -> V_26 , V_18 -> V_26 , sizeof( V_16 -> V_26 ) ) ;
V_20 -> V_27 = V_16 ;
V_20 -> V_28 = sizeof( * V_16 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_19 * V_20 = & V_21 [ V_29 ] ;
V_20 -> V_27 = & V_12 [ V_4 -> V_13 ] ;
V_20 -> V_28 = sizeof( struct V_17 ) ;
}
static int F_12 ( struct V_30 * V_31 )
{
int V_32 ;
T_1 V_33 = 0 ;
if ( F_13 ( V_31 ) >= 0x50 &&
! F_14 ( V_31 -> V_34 + 0x40 , 0x10 , L_1 ) )
V_33 |= 1 << 2 ;
if ( ! F_14 ( V_31 -> V_34 + 0x30 , 0x10 , L_2 ) )
V_33 |= 1 << 1 ;
V_32 = F_14 ( V_31 -> V_34 + 0x00 , 0x30 , L_3 ) ;
if ( ! V_32 )
V_33 |= 1 << 0 ;
return V_33 ? V_33 : V_32 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_35 ;
T_2 V_36 ;
int V_32 ;
bool V_37 = false ;
struct V_30 * V_31 ;
F_16 ( V_2 , V_4 -> V_6 , & V_35 ) ;
V_36 = V_35 & 0x0000ff80 ;
if ( ! V_36 ) {
F_17 ( & V_2 -> V_2 , L_4 ) ;
V_21 [ V_29 ] . V_38 -- ;
goto V_39;
}
V_31 = & V_40 [ V_41 ] ;
V_31 -> V_34 = V_36 + V_42 ;
V_31 -> V_43 = V_36 + V_44 ;
V_32 = F_18 ( V_31 ) ;
if ( V_32 ) {
V_21 [ V_29 ] . V_38 -- ;
V_37 = true ;
} else {
F_4 ( V_2 ) ;
}
V_39:
F_16 ( V_2 , V_4 -> V_45 , & V_35 ) ;
V_36 = V_35 & 0x0000ff80 ;
if ( ! V_36 ) {
F_17 ( & V_2 -> V_2 , L_5 ) ;
V_32 = - V_46 ;
goto V_47;
}
V_31 = & V_40 [ V_48 ] ;
V_31 -> V_34 = V_36 ;
switch ( V_12 [ V_4 -> V_13 ] . V_49 ) {
case V_50 :
case V_51 :
V_31 -> V_43 = V_31 -> V_34 + 128 - 1 ;
break;
default:
V_31 -> V_43 = V_31 -> V_34 + 64 - 1 ;
break;
}
V_32 = F_12 ( V_31 ) ;
if ( V_32 < 0 ) {
V_37 = true ;
goto V_47;
}
V_12 [ V_4 -> V_13 ] . V_33 = V_32 ;
F_6 ( V_2 ) ;
F_11 ( V_2 ) ;
V_32 = F_19 ( & V_2 -> V_2 , V_52 ,
& V_21 [ V_29 ] , 1 , NULL , 0 , NULL ) ;
V_47:
if ( V_37 )
F_20 ( L_6 ,
V_21 [ V_29 ] . V_26 ) ;
return V_32 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_35 ;
T_2 V_36 ;
int V_32 ;
struct V_30 * V_31 ;
F_16 ( V_2 , V_4 -> V_6 , & V_35 ) ;
V_36 = V_35 & 0x0000ff80 ;
if ( ! V_36 ) {
F_17 ( & V_2 -> V_2 , L_4 ) ;
V_32 = - V_46 ;
goto V_53;
}
V_31 = F_22 ( V_54 ) ;
V_31 -> V_34 = V_36 + V_55 ;
V_31 -> V_43 = V_36 + V_56 ;
V_31 = F_22 ( V_57 ) ;
V_31 -> V_34 = V_36 + V_58 ;
V_31 -> V_43 = V_36 + V_59 ;
F_4 ( V_2 ) ;
if ( V_12 [ V_4 -> V_13 ] . V_14 == 1 ) {
V_21 [ V_22 ] . V_38 -- ;
} else if ( V_12 [ V_4 -> V_13 ] . V_14 == 2 ) {
F_16 ( V_2 , V_60 , & V_35 ) ;
V_36 = V_35 & 0xffffc000 ;
if ( ! ( V_35 & 1 ) ) {
F_17 ( & V_2 -> V_2 , L_7
L_8 ) ;
V_32 = - V_46 ;
goto V_53;
}
V_31 = F_23 ( V_61 ) ;
V_31 -> V_34 = V_36 + V_62 ;
V_31 -> V_43 = V_36 + V_63 ;
} else if ( V_12 [ V_4 -> V_13 ] . V_14 == 3 ) {
F_7 ( V_2 ) ;
F_16 ( V_2 , V_64 , & V_35 ) ;
V_36 = V_35 & 0xfffffe00 ;
V_31 = F_23 ( V_61 ) ;
V_31 -> V_34 = V_36 + V_65 ;
V_31 -> V_43 = V_36 + V_66 ;
}
V_32 = F_8 ( V_2 ) ;
if ( V_32 )
goto V_53;
V_32 = F_19 ( & V_2 -> V_2 , V_52 ,
& V_21 [ V_22 ] , 1 , NULL , 0 , NULL ) ;
V_53:
return V_32 ;
}
static int F_24 ( struct V_1 * V_2 ,
const struct V_67 * V_68 )
{
struct V_3 * V_4 ;
int V_32 ;
bool V_69 = false ;
V_4 = F_9 ( & V_2 -> V_2 ,
sizeof( struct V_3 ) , V_23 ) ;
if ( ! V_4 )
return - V_24 ;
V_4 -> V_13 = V_68 -> V_70 ;
V_4 -> V_7 = - 1 ;
V_4 -> V_5 = - 1 ;
V_4 -> V_6 = V_71 ;
V_4 -> V_8 = V_64 ;
V_4 -> V_9 = - 1 ;
if ( V_4 -> V_13 <= V_72 ) {
V_4 -> V_45 = V_73 ;
V_4 -> V_10 = V_74 ;
} else {
V_4 -> V_45 = V_75 ;
V_4 -> V_10 = V_76 ;
}
F_25 ( V_2 , V_4 ) ;
if ( V_12 [ V_4 -> V_13 ] . V_14 ) {
V_32 = F_21 ( V_2 ) ;
if ( ! V_32 )
V_69 = true ;
}
if ( V_12 [ V_4 -> V_13 ] . V_49 ) {
V_32 = F_15 ( V_2 ) ;
if ( ! V_32 )
V_69 = true ;
}
if ( ! V_69 ) {
F_26 ( & V_2 -> V_2 , L_9 ) ;
F_1 ( V_2 ) ;
return - V_46 ;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_2 ) ;
F_1 ( V_2 ) ;
}
