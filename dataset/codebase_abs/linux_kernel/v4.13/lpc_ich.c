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
struct V_19 * V_20 = & V_21 ;
V_16 = F_9 ( & V_2 -> V_2 , sizeof( * V_16 ) , V_22 ) ;
if ( ! V_16 )
return - V_23 ;
V_18 = & V_12 [ V_4 -> V_13 ] ;
V_16 -> V_24 = V_18 -> V_14 ;
F_10 ( V_16 -> V_25 , V_18 -> V_25 , sizeof( V_16 -> V_25 ) ) ;
V_20 -> V_26 = V_16 ;
V_20 -> V_27 = sizeof( * V_16 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_19 * V_20 = & V_28 ;
V_20 -> V_26 = & V_12 [ V_4 -> V_13 ] ;
V_20 -> V_27 = sizeof( struct V_17 ) ;
}
static int F_12 ( struct V_29 * V_30 )
{
int V_31 ;
T_1 V_32 = 0 ;
if ( F_13 ( V_30 ) >= 0x50 &&
! F_14 ( V_30 -> V_33 + 0x40 , 0x10 , L_1 ) )
V_32 |= 1 << 2 ;
if ( ! F_14 ( V_30 -> V_33 + 0x30 , 0x10 , L_2 ) )
V_32 |= 1 << 1 ;
V_31 = F_14 ( V_30 -> V_33 + 0x00 , 0x30 , L_3 ) ;
if ( ! V_31 )
V_32 |= 1 << 0 ;
return V_32 ? V_32 : V_31 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_34 ;
T_2 V_35 ;
int V_31 ;
bool V_36 = false ;
struct V_29 * V_30 ;
F_16 ( V_2 , V_4 -> V_6 , & V_34 ) ;
V_35 = V_34 & 0x0000ff80 ;
if ( ! V_35 ) {
F_17 ( & V_2 -> V_2 , L_4 ) ;
V_28 . V_37 -- ;
goto V_38;
}
V_30 = & V_39 [ V_40 ] ;
V_30 -> V_33 = V_35 + V_41 ;
V_30 -> V_42 = V_35 + V_43 ;
V_31 = F_18 ( V_30 ) ;
if ( V_31 ) {
V_28 . V_37 -- ;
V_36 = true ;
} else {
F_4 ( V_2 ) ;
}
V_38:
F_16 ( V_2 , V_4 -> V_44 , & V_34 ) ;
V_35 = V_34 & 0x0000ff80 ;
if ( ! V_35 ) {
F_17 ( & V_2 -> V_2 , L_5 ) ;
V_31 = - V_45 ;
goto V_46;
}
V_30 = & V_39 [ V_47 ] ;
V_30 -> V_33 = V_35 ;
switch ( V_12 [ V_4 -> V_13 ] . V_48 ) {
case V_49 :
case V_50 :
V_30 -> V_42 = V_30 -> V_33 + 128 - 1 ;
break;
default:
V_30 -> V_42 = V_30 -> V_33 + 64 - 1 ;
break;
}
V_31 = F_12 ( V_30 ) ;
if ( V_31 < 0 ) {
V_36 = true ;
goto V_46;
}
V_12 [ V_4 -> V_13 ] . V_32 = V_31 ;
F_6 ( V_2 ) ;
F_11 ( V_2 ) ;
V_31 = F_19 ( & V_2 -> V_2 , V_51 ,
& V_28 , 1 , NULL , 0 , NULL ) ;
V_46:
if ( V_36 )
F_20 ( L_6 ,
V_28 . V_25 ) ;
return V_31 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_34 ;
T_2 V_35 ;
int V_31 ;
struct V_29 * V_30 ;
if ( F_22 () )
return - V_45 ;
F_16 ( V_2 , V_4 -> V_6 , & V_34 ) ;
V_35 = V_34 & 0x0000ff80 ;
if ( ! V_35 ) {
F_17 ( & V_2 -> V_2 , L_4 ) ;
V_31 = - V_45 ;
goto V_52;
}
V_30 = F_23 ( V_53 ) ;
V_30 -> V_33 = V_35 + V_54 ;
V_30 -> V_42 = V_35 + V_55 ;
V_30 = F_23 ( V_56 ) ;
V_30 -> V_33 = V_35 + V_57 ;
V_30 -> V_42 = V_35 + V_58 ;
F_4 ( V_2 ) ;
if ( V_12 [ V_4 -> V_13 ] . V_14 == 1 ) {
V_21 . V_37 -- ;
} else if ( V_12 [ V_4 -> V_13 ] . V_14 == 2 ) {
F_16 ( V_2 , V_59 , & V_34 ) ;
V_35 = V_34 & 0xffffc000 ;
if ( ! ( V_34 & 1 ) ) {
F_17 ( & V_2 -> V_2 , L_7
L_8 ) ;
V_31 = - V_45 ;
goto V_52;
}
V_30 = F_24 ( V_60 ) ;
V_30 -> V_33 = V_35 + V_61 ;
V_30 -> V_42 = V_35 + V_62 ;
} else if ( V_12 [ V_4 -> V_13 ] . V_14 == 3 ) {
F_7 ( V_2 ) ;
F_16 ( V_2 , V_63 , & V_34 ) ;
V_35 = V_34 & 0xfffffe00 ;
V_30 = F_24 ( V_60 ) ;
V_30 -> V_33 = V_35 + V_64 ;
V_30 -> V_42 = V_35 + V_65 ;
}
V_31 = F_8 ( V_2 ) ;
if ( V_31 )
goto V_52;
V_31 = F_19 ( & V_2 -> V_2 , V_51 ,
& V_21 , 1 , NULL , 0 , NULL ) ;
V_52:
return V_31 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_29 * V_30 = & V_66 [ 0 ] ;
struct V_67 * V_18 ;
T_2 V_68 , V_69 , V_70 ;
V_18 = F_9 ( & V_2 -> V_2 , sizeof( * V_18 ) , V_22 ) ;
if ( ! V_18 )
return - V_23 ;
V_18 -> type = V_12 [ V_4 -> V_13 ] . V_71 ;
switch ( V_18 -> type ) {
case V_72 :
F_16 ( V_2 , V_73 , & V_68 ) ;
if ( V_68 & V_74 ) {
V_30 -> V_33 = V_68 & ~ ( V_75 - 1 ) ;
V_30 -> V_42 = V_30 -> V_33 + V_75 - 1 ;
}
break;
case V_76 :
F_16 ( V_2 , V_59 , & V_69 ) ;
if ( V_69 & 1 ) {
V_68 = F_26 ( V_69 , V_77 ) ;
V_30 -> V_33 = V_68 + V_78 ;
V_30 -> V_42 = V_30 -> V_33 + V_77 - 1 ;
F_16 ( V_2 , V_79 , & V_70 ) ;
if ( ! ( V_70 & V_80 ) ) {
V_70 |= V_80 ;
F_27 ( V_2 , V_79 , V_70 ) ;
F_16 ( V_2 , V_79 , & V_70 ) ;
}
V_18 -> V_81 = ! ! ( V_70 & V_80 ) ;
}
break;
case V_82 : {
unsigned int V_83 = F_28 ( 13 , 0 ) ;
unsigned int V_84 = F_28 ( 13 , 2 ) ;
struct V_85 * V_86 = V_2 -> V_86 ;
F_29 ( V_86 , V_83 , 0xe1 , 0x0 ) ;
F_30 ( V_86 , V_84 , V_87 ,
& V_68 ) ;
if ( V_68 != ~ 0 ) {
V_30 -> V_33 = V_68 & 0xfffffff0 ;
V_30 -> V_42 = V_30 -> V_33 + V_88 - 1 ;
F_30 ( V_86 , V_84 , V_79 , & V_70 ) ;
if ( ! ( V_70 & V_80 ) ) {
V_70 |= V_80 ;
F_31 ( V_86 , V_84 , V_79 , V_70 ) ;
F_30 ( V_86 , V_84 , V_79 , & V_70 ) ;
}
V_18 -> V_81 = ! ! ( V_70 & V_80 ) ;
}
F_29 ( V_86 , V_83 , 0xe1 , 0x1 ) ;
break;
}
default:
return - V_89 ;
}
if ( ! V_30 -> V_33 )
return - V_45 ;
V_90 . V_26 = V_18 ;
V_90 . V_27 = sizeof( * V_18 ) ;
return F_19 ( & V_2 -> V_2 , V_91 ,
& V_90 , 1 , NULL , 0 , NULL ) ;
}
static int F_32 ( struct V_1 * V_2 ,
const struct V_92 * V_93 )
{
struct V_3 * V_4 ;
int V_31 ;
bool V_94 = false ;
V_4 = F_9 ( & V_2 -> V_2 ,
sizeof( struct V_3 ) , V_22 ) ;
if ( ! V_4 )
return - V_23 ;
V_4 -> V_13 = V_93 -> V_95 ;
V_4 -> V_7 = - 1 ;
V_4 -> V_5 = - 1 ;
V_4 -> V_6 = V_96 ;
V_4 -> V_8 = V_63 ;
V_4 -> V_9 = - 1 ;
if ( V_4 -> V_13 <= V_97 ) {
V_4 -> V_44 = V_98 ;
V_4 -> V_10 = V_99 ;
} else {
V_4 -> V_44 = V_100 ;
V_4 -> V_10 = V_101 ;
}
F_33 ( V_2 , V_4 ) ;
if ( V_12 [ V_4 -> V_13 ] . V_14 ) {
V_31 = F_21 ( V_2 ) ;
if ( ! V_31 )
V_94 = true ;
}
if ( V_12 [ V_4 -> V_13 ] . V_48 ) {
V_31 = F_15 ( V_2 ) ;
if ( ! V_31 )
V_94 = true ;
}
if ( V_12 [ V_4 -> V_13 ] . V_71 ) {
V_31 = F_25 ( V_2 ) ;
if ( ! V_31 )
V_94 = true ;
}
if ( ! V_94 ) {
F_34 ( & V_2 -> V_2 , L_9 ) ;
F_1 ( V_2 ) ;
return - V_45 ;
}
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_36 ( & V_2 -> V_2 ) ;
F_1 ( V_2 ) ;
}
