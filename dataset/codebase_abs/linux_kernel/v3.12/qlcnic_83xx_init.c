static int
F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
if ( ( V_3 & 0xFFFF ) )
return 1 ;
else
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_1 V_6 , V_7 ;
V_6 = V_2 -> V_4 -> V_8 . V_9 ;
V_7 = V_2 -> V_4 -> V_8 . V_10 ;
F_4 ( & V_2 -> V_11 -> V_12 ,
L_1 ,
V_2 -> V_4 -> V_8 . V_13 [ V_6 ] ,
V_2 -> V_4 -> V_8 . V_13 [ V_7 ] ) ;
}
static int F_5 ( struct V_1 * V_2 ,
T_2 V_14 , int V_15 )
{
T_1 V_3 ;
int V_16 ;
if ( V_15 ) {
if ( F_6 ( V_2 ) )
return - V_17 ;
}
V_3 = F_2 ( V_2 -> V_4 , V_18 ) ;
V_3 |= ( V_2 -> V_19 & 0xf ) ;
V_3 |= V_14 << 7 ;
if ( V_14 )
V_16 = V_20 / V_21 - V_2 -> V_4 -> V_8 . V_22 ;
else
V_16 = V_20 / V_21 ;
V_3 |= V_16 << 8 ;
F_7 ( V_2 -> V_4 , V_18 , V_3 ) ;
V_2 -> V_4 -> V_8 . V_22 = V_20 / V_21 ;
if ( V_15 )
F_8 ( V_2 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_23 ) ;
V_3 = V_3 & ~ ( 0x3 << ( V_2 -> V_19 * 2 ) ) ;
V_3 = V_3 | ( V_24 << ( V_2 -> V_19 * 2 ) ) ;
F_7 ( V_2 -> V_4 , V_23 , V_3 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
int V_15 )
{
T_1 V_3 ;
if ( V_15 ) {
if ( F_6 ( V_2 ) )
return - V_17 ;
}
V_3 = F_2 ( V_2 -> V_4 , V_25 ) ;
V_3 = V_3 & ~ 0xFF ;
V_3 = V_3 | V_26 ;
F_7 ( V_2 -> V_4 , V_25 , V_3 ) ;
if ( V_15 )
F_8 ( V_2 ) ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 ,
int V_27 , int V_15 )
{
T_1 V_3 ;
if ( V_15 ) {
if ( F_6 ( V_2 ) )
return - V_17 ;
}
V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
if ( V_27 )
V_3 = V_3 | ( 1 << V_2 -> V_19 ) ;
else
V_3 = V_3 & ~ ( 1 << V_2 -> V_19 ) ;
F_7 ( V_2 -> V_4 , V_5 , V_3 ) ;
F_9 ( V_2 ) ;
if ( V_15 )
F_8 ( V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_28 ;
V_3 = F_2 ( V_2 -> V_4 , V_25 ) ;
V_28 = V_3 & 0xFF ;
if ( V_28 != V_26 ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_2 ,
V_29 , V_28 , V_26 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_15 )
{
T_1 V_3 ;
if ( V_15 ) {
if ( F_6 ( V_2 ) )
return - V_17 ;
}
F_7 ( V_2 -> V_4 , V_31 , 0 ) ;
V_3 = F_2 ( V_2 -> V_4 , V_32 ) ;
V_3 &= ~ V_33 ;
F_7 ( V_2 -> V_4 , V_32 , V_3 ) ;
if ( V_15 )
F_8 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
int V_34 , int V_15 )
{
T_1 V_3 ;
if ( V_15 ) {
if ( F_6 ( V_2 ) )
return - V_17 ;
}
V_3 = F_2 ( V_2 -> V_4 , V_31 ) ;
if ( V_34 )
V_3 = V_3 | ( 1 << V_2 -> V_19 ) ;
else
V_3 = V_3 & ~ ( 1 << V_2 -> V_19 ) ;
F_7 ( V_2 -> V_4 , V_31 , V_3 ) ;
if ( V_15 )
F_8 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
int V_35 )
{
T_3 V_16 ;
V_16 = V_20 / V_21 - V_2 -> V_4 -> V_8 . V_22 ;
if ( V_16 <= V_35 )
return 0 ;
else
return - V_17 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_36 ;
T_1 V_37 , V_38 , V_3 ;
V_36 = V_39 ;
V_37 = F_2 ( V_2 -> V_4 , V_31 ) ;
V_38 = F_2 ( V_2 -> V_4 , V_5 ) ;
F_4 ( & V_2 -> V_11 -> V_12 ,
L_3 , V_29 , V_37 , V_38 ) ;
if ( ! ( ( V_37 & V_38 ) == V_38 ) ) {
if ( F_15 ( V_2 , V_36 ) ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_4 , V_29 ) ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
V_3 = V_3 & ~ ( V_37 ^ V_38 ) ;
if ( F_6 ( V_2 ) )
return - V_17 ;
F_7 ( V_2 -> V_4 , V_5 , V_3 ) ;
F_4 ( & V_2 -> V_11 -> V_12 ,
L_5 ,
V_29 , V_3 ) ;
F_8 ( V_2 ) ;
return 0 ;
} else {
return 1 ;
}
} else {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_6 ,
V_29 ) ;
return 0 ;
}
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = V_2 -> V_41 ;
if ( F_18 ( V_42 , & V_2 -> V_43 ) )
return - V_17 ;
F_19 ( V_41 ) ;
F_20 ( V_2 , V_41 ) ;
F_21 ( V_2 , V_41 ) ;
F_22 ( V_41 ) ;
F_23 ( V_42 , & V_2 -> V_43 ) ;
F_24 ( & V_2 -> V_11 -> V_12 , L_7 , V_29 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
int V_44 ;
struct V_40 * V_41 = V_2 -> V_41 ;
F_19 ( V_41 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_20 ( V_2 , V_41 ) ;
for ( V_44 = 0 ; V_44 < V_2 -> V_4 -> V_45 ; V_44 ++ ) {
V_2 -> V_4 -> V_46 [ V_44 ] . V_47 = V_44 ;
V_2 -> V_4 -> V_46 [ V_44 ] . V_48 = 0 ;
V_2 -> V_4 -> V_46 [ V_44 ] . V_49 = 0 ;
}
if ( F_28 ( V_2 ) )
F_29 ( V_2 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = V_2 -> V_41 ;
if ( F_31 ( V_41 ) ) {
if ( F_21 ( V_2 , V_41 ) )
goto V_50;
F_32 ( V_41 , V_51 ) ;
}
V_50:
F_22 ( V_41 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
int V_15 )
{
if ( V_15 ) {
if ( F_6 ( V_2 ) )
return - V_17 ;
}
F_13 ( V_2 , 0 ) ;
F_7 ( V_2 -> V_4 , V_52 , V_53 ) ;
if ( V_15 )
F_8 ( V_2 ) ;
F_3 ( V_2 ) ;
F_4 ( & V_2 -> V_11 -> V_12 , L_8 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
int V_15 )
{
if ( V_15 ) {
if ( F_6 ( V_2 ) )
return - V_17 ;
}
F_7 ( V_2 -> V_4 , V_52 , V_54 ) ;
if ( V_15 )
F_8 ( V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
int V_15 )
{
if ( V_15 ) {
if ( F_6 ( V_2 ) )
return - V_17 ;
}
F_7 ( V_2 -> V_4 , V_52 ,
V_55 ) ;
if ( V_15 )
F_8 ( V_2 ) ;
return 0 ;
}
static int
F_36 ( struct V_1 * V_2 , int V_15 )
{
if ( V_15 ) {
if ( F_6 ( V_2 ) )
return - V_17 ;
}
F_7 ( V_2 -> V_4 , V_52 ,
V_56 ) ;
if ( V_15 )
F_8 ( V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
int V_15 )
{
if ( V_15 ) {
if ( F_6 ( V_2 ) )
return - V_17 ;
}
F_7 ( V_2 -> V_4 , V_52 , V_57 ) ;
if ( V_15 )
F_8 ( V_2 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
T_1 V_58 , V_59 , V_60 , V_44 , V_61 , V_62 , V_63 ;
V_59 = F_2 ( V_2 -> V_4 , V_64 ) ;
V_60 = F_2 ( V_2 -> V_4 , V_65 ) ;
V_62 = V_66 ;
V_44 = 0 ;
V_61 = 0 ;
V_58 = V_59 ;
do {
V_63 = ( ( ( V_58 & ( 0xF << V_61 * 4 ) ) >> V_61 * 4 ) & 0x3 ) ;
if ( V_63 == V_62 )
break;
if ( V_44 == ( V_67 - 1 ) ) {
V_58 = V_60 ;
V_61 = 0 ;
} else {
V_61 ++ ;
}
if ( V_44 == ( V_68 - 1 ) ) {
if ( V_62 == V_66 )
V_62 = V_69 ;
else if ( V_62 == V_69 )
V_62 = V_70 ;
else if ( V_62 == V_70 )
return - V_30 ;
V_58 = V_59 ;
V_61 = 0 ;
V_44 = 0 ;
}
} while ( V_44 ++ < V_68 );
return V_44 ;
}
static int F_39 ( struct V_1 * V_2 , int V_15 )
{
int V_71 = 0 ;
V_71 = F_40 ( V_2 ) ;
if ( V_71 ) {
F_33 ( V_2 , V_15 ) ;
} else {
F_13 ( V_2 , V_15 ) ;
V_71 = F_37 ( V_2 , V_15 ) ;
}
return V_71 ;
}
static int F_41 ( struct V_1 * V_2 )
{
T_1 V_27 ;
V_27 = F_42 ( V_2 , V_72 ) ;
if ( V_27 & V_73 ) {
F_24 ( & V_2 -> V_11 -> V_12 ,
L_9 , V_27 ) ;
if ( F_43 ( V_27 ) == V_74 ) {
F_24 ( & V_2 -> V_11 -> V_12 ,
L_10
L_11 ) ;
F_24 ( & V_2 -> V_11 -> V_12 ,
L_12 ) ;
return - V_30 ;
}
}
return 0 ;
}
int F_44 ( struct V_1 * V_2 )
{
int V_75 ;
F_45 ( V_2 -> V_4 -> V_76 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 , 1 ) ;
V_75 = F_48 ( V_2 ) ;
if ( V_75 )
return V_75 ;
F_46 ( V_2 ) ;
if ( F_49 ( V_2 ) ) {
F_33 ( V_2 , 1 ) ;
return - V_30 ;
}
if ( V_2 -> V_77 -> V_78 ( V_2 ) ) {
F_33 ( V_2 , 1 ) ;
return - V_30 ;
}
if ( V_2 -> V_19 == 0 )
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
F_30 ( V_2 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_79 * V_4 = V_2 -> V_4 ;
F_11 ( V_2 , 1 , 1 ) ;
F_5 ( V_2 , 0 , 1 ) ;
F_53 ( V_80 , & V_2 -> V_4 -> V_8 . V_27 ) ;
V_4 -> V_8 . V_81 = 0 ;
V_4 -> V_8 . V_82 = V_83 ;
V_4 -> V_8 . V_84 = 0 ;
V_4 -> V_8 . V_85 = 0 ;
V_4 -> V_86 = 0 ;
V_2 -> V_87 = 0 ;
V_4 -> V_8 . V_88 = 0 ;
F_23 ( V_42 , & V_2 -> V_43 ) ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_79 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_8 . V_10 != V_57 ) {
F_52 ( V_2 ) ;
if ( ( V_4 -> V_8 . V_10 == V_56 ) ||
( V_4 -> V_8 . V_10 == V_54 ) ) {
if ( F_44 ( V_2 ) )
return - V_30 ;
}
}
return 0 ;
}
int F_55 ( struct V_1 * V_2 )
{
T_1 V_43 ;
struct V_79 * V_4 = V_2 -> V_4 ;
V_43 = F_2 ( V_2 -> V_4 , V_89 ) ;
if ( V_43 != V_90 ) {
if ( ! V_4 -> V_8 . V_91 -- ) {
F_33 ( V_2 , 1 ) ;
return - V_30 ;
}
F_4 ( & V_2 -> V_11 -> V_12 , L_13 ) ;
return - V_30 ;
} else {
if ( V_4 -> V_8 . V_92 != V_90 ) {
F_52 ( V_2 ) ;
if ( V_4 -> V_8 . V_10 != V_93 ) {
if ( F_44 ( V_2 ) )
return - V_30 ;
}
V_2 -> V_4 -> V_8 . V_92 = V_90 ;
F_4 ( & V_2 -> V_11 -> V_12 , L_14 ) ;
}
}
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
V_2 -> V_4 -> V_8 . V_84 = - V_30 ;
F_24 ( & V_2 -> V_11 -> V_12 ,
L_15 , V_29 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
F_11 ( V_2 , 1 , 0 ) ;
F_5 ( V_2 , 1 , 0 ) ;
if ( V_94 ) {
F_39 ( V_2 , 0 ) ;
} else {
if ( F_58 ( V_2 ) ) {
F_33 ( V_2 , 0 ) ;
return - V_30 ;
} else {
F_37 ( V_2 , 0 ) ;
}
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
int V_36 , V_71 = 0 ;
T_1 V_62 ;
V_36 = V_95 ;
if ( V_2 -> V_4 -> V_8 . V_10 == V_56 ) {
V_62 = F_38 ( V_2 ) ;
if ( V_2 -> V_4 -> V_96 == V_62 )
V_71 = F_39 ( V_2 , 1 ) ;
} else {
V_71 = F_15 ( V_2 , V_36 ) ;
}
return V_71 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_79 * V_4 = V_2 -> V_4 ;
struct V_97 * V_98 = V_4 -> V_76 ;
int V_71 = 0 ;
T_1 V_3 ;
if ( V_4 -> V_8 . V_99 ( V_2 ) )
return - V_30 ;
if ( F_61 ( V_2 ) ) {
if ( V_4 -> V_100 == V_101 ) {
F_41 ( V_2 ) ;
F_24 ( & V_2 -> V_11 -> V_12 ,
L_16 ,
V_2 -> V_4 -> V_100 ) ;
F_23 ( V_102 , & V_98 -> V_27 ) ;
F_53 ( V_42 , & V_2 -> V_43 ) ;
F_25 ( V_2 ) ;
F_33 ( V_2 , 1 ) ;
return - V_30 ;
}
}
V_3 = F_2 ( V_2 -> V_4 , V_32 ) ;
V_71 = F_62 ( V_2 ) ;
if ( V_71 ) {
V_2 -> V_103 |= V_104 ;
if ( ! ( V_3 & V_105 ) ) {
F_23 ( V_102 , & V_98 -> V_27 ) ;
F_53 ( V_42 , & V_2 -> V_43 ) ;
F_36 ( V_2 , 1 ) ;
}
return - V_30 ;
}
if ( ( V_3 & V_33 ) || V_4 -> V_8 . V_85 ) {
F_23 ( V_102 , & V_98 -> V_27 ) ;
F_36 ( V_2 , 1 ) ;
return V_71 ;
}
if ( V_4 -> V_86 &&
! ( V_3 & V_105 ) ) {
V_2 -> V_4 -> V_86 = 0 ;
F_17 ( V_2 ) ;
return V_71 ;
}
if ( V_2 -> V_4 -> V_8 . V_81 ) {
F_35 ( V_2 , 1 ) ;
F_5 ( V_2 , 0 , 1 ) ;
return V_71 ;
}
return V_71 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_97 * V_98 = V_2 -> V_4 -> V_76 ;
int V_71 = 0 ;
if ( V_2 -> V_4 -> V_8 . V_10 != V_56 ) {
F_5 ( V_2 , 0 , 1 ) ;
F_53 ( V_42 , & V_2 -> V_43 ) ;
F_23 ( V_102 , & V_98 -> V_27 ) ;
if ( V_2 -> V_4 -> V_106 == V_107 )
F_64 ( V_2 , 1 ) ;
if ( F_65 ( V_2 ) ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_17 , V_29 ) ;
V_2 -> V_4 -> V_8 . V_88 = 1 ;
return 0 ;
} else {
F_14 ( V_2 , 1 , 1 ) ;
F_25 ( V_2 ) ;
}
}
if ( F_65 ( V_2 ) ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_17 , V_29 ) ;
return - 1 ;
} else {
if ( V_2 -> V_4 -> V_8 . V_88 ) {
F_14 ( V_2 , 1 , 1 ) ;
F_25 ( V_2 ) ;
V_2 -> V_4 -> V_8 . V_88 = 0 ;
}
V_71 = F_16 ( V_2 ) ;
if ( V_71 ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_18 , V_29 ) ;
return - 1 ;
}
}
F_34 ( V_2 , 1 ) ;
return V_71 ;
}
static int F_66 ( struct V_1 * V_2 )
{
F_24 ( & V_2 -> V_11 -> V_12 , L_19 , V_29 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
F_24 ( & V_2 -> V_11 -> V_12 , L_20 , V_29 ) ;
F_23 ( V_42 , & V_2 -> V_43 ) ;
V_2 -> V_4 -> V_8 . V_84 = - V_30 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_11 -> V_12 , L_19 , V_29 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
T_1 V_43 )
{
T_1 V_6 , V_7 , V_108 ;
V_6 = V_2 -> V_4 -> V_8 . V_9 ;
V_7 = V_2 -> V_4 -> V_8 . V_10 ;
V_108 = V_43 ;
if ( ( V_108 < V_109 ) ||
( V_108 > V_110 ) ) {
F_24 ( & V_2 -> V_11 -> V_12 ,
L_21 ,
V_29 , V_6 , V_7 , V_43 ) ;
return 1 ;
}
if ( ( V_6 == V_93 ) &&
( V_7 == V_93 ) ) {
if ( ( V_108 != V_109 ) &&
( V_108 != V_57 ) ) {
F_24 ( & V_2 -> V_11 -> V_12 ,
L_22 ,
V_29 , V_6 , V_7 , V_108 ) ;
return 1 ;
}
}
if ( V_108 == V_54 ) {
if ( ( V_7 != V_54 ) &&
( V_7 != V_109 ) &&
( V_7 != V_56 ) ) {
F_24 ( & V_2 -> V_11 -> V_12 ,
L_22 ,
V_29 , V_6 , V_7 , V_108 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_70 ( struct V_1 * V_2 )
{
if ( V_2 -> V_111 . V_112 )
F_71 ( V_2 ) ;
}
void F_72 ( struct V_113 * V_114 )
{
struct V_1 * V_2 ;
T_1 V_43 ;
V_2 = F_73 ( V_114 , struct V_1 , V_115 . V_114 ) ;
V_43 = F_2 ( V_2 -> V_4 , V_52 ) ;
if ( F_69 ( V_2 , V_43 ) ) {
F_3 ( V_2 ) ;
V_2 -> V_4 -> V_8 . V_9 = V_93 ;
} else {
V_2 -> V_4 -> V_8 . V_9 = V_43 ;
}
switch ( V_2 -> V_4 -> V_8 . V_9 ) {
case V_57 :
F_60 ( V_2 ) ;
break;
case V_56 :
F_63 ( V_2 ) ;
break;
case V_55 :
F_66 ( V_2 ) ;
break;
case V_53 :
F_67 ( V_2 ) ;
return;
case V_54 :
F_59 ( V_2 ) ;
break;
case V_110 :
F_68 ( V_2 ) ;
break;
default:
F_56 ( V_2 ) ;
return;
}
V_2 -> V_4 -> V_8 . V_10 = V_2 -> V_4 -> V_8 . V_9 ;
F_70 ( V_2 ) ;
if ( F_74 ( V_80 , & V_2 -> V_4 -> V_8 . V_27 ) )
F_75 ( V_2 , F_72 ,
V_2 -> V_4 -> V_8 . V_82 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
T_1 V_116 , V_3 ;
if ( F_77 ( V_2 ,
V_117 ,
( T_2 * ) & V_116 , 1 ) ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_23 , V_29 ) ;
V_2 -> V_118 = V_95 ;
V_2 -> V_119 = V_39 ;
} else {
V_2 -> V_118 = V_116 & 0xFFFF ;
V_2 -> V_119 = ( ( V_116 >> 16 ) & 0xFFFF ) ;
}
V_2 -> V_4 -> V_8 . V_9 = V_93 ;
V_2 -> V_4 -> V_8 . V_10 = V_93 ;
V_2 -> V_4 -> V_8 . V_82 = V_83 ;
V_2 -> V_4 -> V_8 . V_84 = 0 ;
V_2 -> V_4 -> V_8 . V_85 = 0 ;
V_2 -> V_4 -> V_8 . V_13 = ( char * * ) V_120 ;
F_23 ( V_42 , & V_2 -> V_43 ) ;
F_53 ( V_80 , & V_2 -> V_4 -> V_8 . V_27 ) ;
if ( ! V_121 ) {
V_3 = F_2 ( V_2 -> V_4 , V_32 ) ;
V_3 = V_3 | V_105 ;
F_7 ( V_2 -> V_4 , V_32 , V_3 ) ;
}
}
static int
F_78 ( struct V_1 * V_2 )
{
T_1 V_43 , V_3 ;
if ( F_6 ( V_2 ) )
return - V_30 ;
F_7 ( V_2 -> V_4 , V_122 , 0 ) ;
if ( F_10 ( V_2 , 0 ) ) {
F_8 ( V_2 ) ;
return - V_30 ;
}
V_43 = F_2 ( V_2 -> V_4 , V_52 ) ;
if ( F_69 ( V_2 , V_43 ) ) {
F_8 ( V_2 ) ;
return - V_30 ;
}
if ( V_43 != V_109 && V_94 ) {
F_7 ( V_2 -> V_4 , V_52 ,
V_109 ) ;
V_43 = V_109 ;
}
V_2 -> V_4 -> V_8 . V_9 = V_43 ;
if ( V_43 == V_109 )
F_57 ( V_2 ) ;
if ( V_121 ) {
V_3 = F_2 ( V_2 -> V_4 , V_32 ) ;
V_3 = V_3 & ~ V_105 ;
F_7 ( V_2 -> V_4 , V_32 , V_3 ) ;
}
F_8 ( V_2 ) ;
return 0 ;
}
int F_79 ( struct V_1 * V_2 )
{
int V_71 = - V_30 ;
F_76 ( V_2 ) ;
if ( F_80 ( V_2 ) )
return V_71 ;
if ( ! F_1 ( V_2 ) ) {
if ( F_78 ( V_2 ) )
return - V_30 ;
} else {
if ( F_12 ( V_2 ) )
return - V_30 ;
}
F_5 ( V_2 , 0 , 1 ) ;
return 0 ;
}
void F_81 ( struct V_1 * V_2 )
{
int V_47 ;
T_1 V_3 ;
while ( F_18 ( V_42 , & V_2 -> V_43 ) )
F_82 ( 10000 , 11000 ) ;
V_47 = F_2 ( V_2 -> V_4 , V_123 ) ;
V_47 = V_47 & 0xFF ;
if ( V_47 == V_2 -> V_19 ) {
F_24 ( & V_2 -> V_11 -> V_12 ,
L_24 , V_29 , V_47 ) ;
F_83 ( 20 ) ;
V_47 = F_2 ( V_2 -> V_4 , V_123 ) ;
V_47 = V_47 & 0xFF ;
}
V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
V_3 = V_3 & ~ ( 1 << V_2 -> V_19 ) ;
F_7 ( V_2 -> V_4 , V_5 , V_3 ) ;
F_23 ( V_80 , & V_2 -> V_4 -> V_8 . V_27 ) ;
F_23 ( V_42 , & V_2 -> V_43 ) ;
F_84 ( & V_2 -> V_115 ) ;
}
void F_85 ( struct V_1 * V_2 , T_1 V_124 )
{
T_1 V_3 ;
if ( F_86 ( V_2 ) )
return;
if ( F_6 ( V_2 ) ) {
F_24 ( & V_2 -> V_11 -> V_12 ,
L_25 , V_29 ) ;
return;
}
V_3 = F_2 ( V_2 -> V_4 , V_32 ) ;
if ( ( V_3 & V_105 ) ||
! V_121 ) {
F_24 ( & V_2 -> V_11 -> V_12 ,
L_26 , V_29 ) ;
F_8 ( V_2 ) ;
return;
}
if ( V_124 == V_125 ) {
V_3 = F_2 ( V_2 -> V_4 , V_32 ) ;
V_3 = V_3 | V_33 ;
F_7 ( V_2 -> V_4 , V_32 , V_3 ) ;
} else if ( V_124 == V_126 ) {
V_2 -> V_4 -> V_8 . V_85 = 1 ;
}
F_8 ( V_2 ) ;
return;
}
static int F_87 ( struct V_1 * V_2 )
{
T_2 * V_127 ;
T_1 V_49 , V_128 ;
T_3 V_129 ;
int V_71 = - V_30 ;
V_49 = V_130 ;
V_129 = F_2 ( V_2 -> V_4 , V_131 ) ;
V_128 = F_2 ( V_2 -> V_4 , V_132 ) ;
if ( V_128 & 0xF )
V_128 = ( V_128 + 16 ) & ~ 0xF ;
V_127 = F_88 ( V_128 , V_133 ) ;
if ( V_127 == NULL )
return - V_134 ;
V_71 = F_77 ( V_2 , V_49 , V_127 ,
V_128 / sizeof( T_1 ) ) ;
if ( V_71 ) {
F_89 ( V_127 ) ;
return V_71 ;
}
V_71 = F_90 ( V_2 , V_129 , ( T_1 * ) V_127 ,
V_128 / 16 ) ;
if ( V_71 ) {
F_89 ( V_127 ) ;
return V_71 ;
}
F_89 ( V_127 ) ;
return V_71 ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_135 * V_136 = V_2 -> V_4 -> V_136 ;
const struct V_137 * V_138 = V_136 -> V_138 ;
T_1 V_129 , * V_127 ;
int V_44 , V_71 = - V_30 ;
T_2 V_139 [ 16 ] ;
T_4 V_128 ;
T_3 V_140 ;
V_129 = F_2 ( V_2 -> V_4 , V_141 ) ;
V_128 = ( V_138 -> V_128 & ~ 0xF ) ;
V_127 = ( T_1 * ) V_138 -> V_139 ;
V_140 = ( T_3 ) V_129 ;
V_71 = F_90 ( V_2 , V_140 ,
( T_1 * ) V_127 , V_128 / 16 ) ;
if ( V_71 ) {
F_24 ( & V_2 -> V_11 -> V_12 , L_27 ) ;
F_92 ( V_138 ) ;
V_136 -> V_138 = NULL ;
return - V_30 ;
}
if ( V_138 -> V_128 & 0xF ) {
V_140 = V_129 + V_128 ;
for ( V_44 = 0 ; V_44 < ( V_138 -> V_128 & 0xF ) ; V_44 ++ )
V_139 [ V_44 ] = V_138 -> V_139 [ V_128 + V_44 ] ;
for (; V_44 < 16 ; V_44 ++ )
V_139 [ V_44 ] = 0 ;
V_71 = F_90 ( V_2 , V_140 ,
( T_1 * ) V_139 , 1 ) ;
if ( V_71 ) {
F_24 ( & V_2 -> V_11 -> V_12 ,
L_27 ) ;
F_92 ( V_138 ) ;
V_136 -> V_138 = NULL ;
return - V_30 ;
}
}
F_92 ( V_138 ) ;
V_136 -> V_138 = NULL ;
return 0 ;
}
static void F_93 ( struct V_1 * V_2 )
{
int V_44 , V_61 ;
T_1 V_3 = 0 , V_142 = 0 , V_58 = 0 ;
int V_75 = 0 ;
V_3 = F_94 ( V_2 , V_143 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
F_4 ( & V_2 -> V_11 -> V_12 , L_28 , V_3 ) ;
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
if ( V_61 == 0 ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_29 ) ;
V_58 = V_144 ;
} else if ( V_61 == 1 ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_30 ) ;
V_58 = V_145 ;
}
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ ) {
V_3 = F_94 ( V_2 , V_58 + ( V_44 * 0x4 ) , & V_75 ) ;
if ( V_75 == - V_30 )
return;
F_4 ( & V_2 -> V_11 -> V_12 , L_31 , V_3 ) ;
}
F_4 ( & V_2 -> V_11 -> V_12 , L_32 ) ;
}
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
if ( V_61 == 0 ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_33 ) ;
V_58 = V_146 ;
} else if ( V_61 == 1 ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_34 ) ;
V_58 = V_147 ;
}
for ( V_44 = 0 ; V_44 < 4 ; V_44 ++ ) {
V_3 = F_94 ( V_2 , V_58 + ( V_44 * 0x4 ) , & V_75 ) ;
if ( V_75 == - V_30 )
return;
F_4 ( & V_2 -> V_11 -> V_12 , L_31 , V_3 ) ;
}
F_4 ( & V_2 -> V_11 -> V_12 , L_32 ) ;
}
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
if ( V_61 == 0 ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_35 ) ;
V_58 = V_148 ;
} else if ( V_61 == 1 ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_36 ) ;
V_58 = V_149 ;
}
for ( V_44 = 7 ; V_44 >= 0 ; V_44 -- ) {
V_3 = F_94 ( V_2 , V_58 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
V_3 &= ~ ( 0x7 << 29 ) ;
F_95 ( V_2 , V_58 , ( V_3 | ( V_44 << 29 ) ) ) ;
V_3 = F_94 ( V_2 , V_58 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
F_4 ( & V_2 -> V_11 -> V_12 , L_31 , V_3 ) ;
}
F_4 ( & V_2 -> V_11 -> V_12 , L_32 ) ;
}
V_3 = F_94 ( V_2 , V_150 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
V_142 = F_94 ( V_2 , V_151 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
F_4 ( & V_2 -> V_11 -> V_12 ,
L_37 ,
V_3 , V_142 ) ;
}
static void F_96 ( struct V_1 * V_2 )
{
T_1 V_58 = 0 , V_44 , V_61 ;
if ( F_6 ( V_2 ) ) {
F_24 ( & V_2 -> V_11 -> V_12 ,
L_38 , V_29 ) ;
return;
}
F_93 ( V_2 ) ;
F_95 ( V_2 , V_143 , 0x0 ) ;
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
if ( V_61 == 0 )
V_58 = V_144 ;
else if ( V_61 == 1 )
V_58 = V_145 ;
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ )
F_95 ( V_2 , V_58 + ( V_44 * 0x4 ) , 0x0 ) ;
}
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
if ( V_61 == 0 )
V_58 = V_146 ;
else if ( V_61 == 1 )
V_58 = V_147 ;
for ( V_44 = 0 ; V_44 < 4 ; V_44 ++ )
F_95 ( V_2 , V_58 + ( V_44 * 0x4 ) , 0x03FF03FF ) ;
}
F_95 ( V_2 , V_150 , 0 ) ;
F_95 ( V_2 , V_151 , 0 ) ;
F_4 ( & V_2 -> V_11 -> V_12 ,
L_39 ) ;
F_8 ( V_2 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
F_95 ( V_2 , V_152 , 0 ) ;
F_95 ( V_2 , V_153 , 0 ) ;
F_95 ( V_2 , V_154 , 0 ) ;
F_95 ( V_2 , V_155 , 0 ) ;
F_95 ( V_2 , V_156 , 0 ) ;
F_95 ( V_2 , V_157 , 0 ) ;
F_95 ( V_2 , V_158 , 0 ) ;
F_95 ( V_2 , V_159 , 0 ) ;
F_95 ( V_2 , V_160 , 1 ) ;
}
static int F_62 ( struct V_1 * V_161 )
{
T_1 V_162 , V_163 ;
int V_164 , V_71 = - V_30 , V_75 = 0 ;
V_164 = V_165 ;
V_161 -> V_162 = F_42 ( V_161 ,
V_166 ) ;
do {
F_83 ( V_167 ) ;
V_162 = F_42 ( V_161 ,
V_166 ) ;
if ( V_162 != V_161 -> V_162 ) {
V_71 = V_168 ;
break;
}
} while ( -- V_164 );
if ( V_71 ) {
F_24 ( & V_161 -> V_11 -> V_12 , L_40 ) ;
F_97 ( V_161 ) ;
F_96 ( V_161 ) ;
V_163 = F_42 ( V_161 ,
V_72 ) ;
F_4 ( & V_161 -> V_11 -> V_12 , L_41
L_42
L_43
L_44
L_45 , V_163 ,
F_42 ( V_161 , V_169 ) ,
F_94 ( V_161 , V_170 , & V_75 ) ,
F_94 ( V_161 , V_171 , & V_75 ) ,
F_94 ( V_161 , V_172 , & V_75 ) ,
F_94 ( V_161 , V_173 , & V_75 ) ,
F_94 ( V_161 , V_174 , & V_75 ) ) ;
if ( F_43 ( V_163 ) == 0x67 )
F_24 ( & V_161 -> V_11 -> V_12 ,
L_46 ) ;
}
return V_71 ;
}
static int F_98 ( struct V_1 * V_161 )
{
int V_164 = V_175 ;
T_1 V_3 ;
do {
V_3 = F_42 ( V_161 , V_176 ) ;
if ( V_3 == V_177 )
return 0 ;
F_83 ( V_178 ) ;
} while ( -- V_164 );
F_24 ( & V_161 -> V_11 -> V_12 , L_47 , V_29 , V_3 ) ;
return - V_30 ;
}
int F_58 ( struct V_1 * V_161 )
{
int V_75 ;
V_75 = F_98 ( V_161 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_62 ( V_161 ) ;
if ( V_75 )
return V_75 ;
return V_75 ;
}
static int F_99 ( struct V_1 * V_161 , T_1 V_140 ,
int V_179 , T_1 V_180 , T_1 V_27 )
{
int V_181 , V_75 = 0 ;
T_1 V_182 ;
T_2 V_164 ;
V_182 = F_94 ( V_161 , V_140 , & V_75 ) ;
if ( V_75 == - V_30 )
return V_75 ;
V_164 = V_179 / 10 ;
do {
if ( ( V_182 & V_180 ) != V_27 ) {
V_181 = 1 ;
F_83 ( V_179 / 10 ) ;
V_182 = F_94 ( V_161 , V_140 , & V_75 ) ;
if ( V_75 == - V_30 )
return V_75 ;
} else {
V_181 = 0 ;
break;
}
} while ( V_164 -- );
if ( V_181 ) {
V_161 -> V_4 -> V_183 . V_184 ++ ;
F_24 ( & V_161 -> V_11 -> V_12 ,
L_48 ,
V_29 , V_161 -> V_4 -> V_183 . V_185 ) ;
F_24 ( & V_161 -> V_11 -> V_12 ,
L_49 ,
V_182 , V_180 , V_27 ) ;
}
return V_181 ;
}
static int F_100 ( struct V_1 * V_161 )
{
T_1 V_186 = 0 ;
T_5 * V_187 = ( T_5 * ) V_161 -> V_4 -> V_183 . V_187 ;
int V_188 = V_161 -> V_4 -> V_183 . V_189 -> V_128 / sizeof( T_5 ) ;
while ( V_188 -- > 0 )
V_186 += * V_187 ++ ;
while ( V_186 >> 16 )
V_186 = ( V_186 & 0xFFFF ) + ( V_186 >> 16 ) ;
if ( ~ V_186 ) {
return 0 ;
} else {
F_24 ( & V_161 -> V_11 -> V_12 , L_50 , V_29 ) ;
return - 1 ;
}
}
int F_80 ( struct V_1 * V_161 )
{
struct V_79 * V_4 = V_161 -> V_4 ;
T_1 V_140 , V_188 , V_190 , V_191 ;
T_2 * V_192 ;
if ( V_4 -> V_183 . V_187 != NULL ) {
V_190 = V_161 -> V_193 ;
V_191 = F_101 ( V_161 ) ;
if ( V_191 > V_190 )
F_89 ( V_4 -> V_183 . V_187 ) ;
else
return 0 ;
}
V_4 -> V_183 . V_184 = 0 ;
V_4 -> V_183 . V_187 = F_88 ( V_194 , V_133 ) ;
if ( V_161 -> V_4 -> V_183 . V_187 == NULL )
return - V_134 ;
V_192 = V_161 -> V_4 -> V_183 . V_187 ;
V_140 = V_195 ;
V_188 = sizeof( struct V_196 ) / sizeof( T_1 ) ;
if ( F_102 ( V_161 , V_140 , V_192 , V_188 ) ) {
F_24 ( & V_161 -> V_11 -> V_12 , L_51 , V_29 ) ;
return - V_30 ;
}
V_4 -> V_183 . V_189 = (struct V_196 * ) V_4 -> V_183 . V_187 ;
V_140 = V_195 + V_4 -> V_183 . V_189 -> V_197 ;
V_192 = V_4 -> V_183 . V_187 + V_4 -> V_183 . V_189 -> V_197 ;
V_188 = ( V_4 -> V_183 . V_189 -> V_128 - V_4 -> V_183 . V_189 -> V_197 ) / sizeof( T_1 ) ;
if ( F_102 ( V_161 , V_140 , V_192 , V_188 ) ) {
F_24 ( & V_161 -> V_11 -> V_12 , L_51 , V_29 ) ;
return - V_30 ;
}
if ( F_100 ( V_161 ) )
return - V_30 ;
V_4 -> V_183 . V_198 = V_4 -> V_183 . V_187 + V_4 -> V_183 . V_189 -> V_198 ;
V_4 -> V_183 . V_199 = V_4 -> V_183 . V_187 +
V_4 -> V_183 . V_189 -> V_199 ;
V_4 -> V_183 . V_200 = V_4 -> V_183 . V_187 + V_4 -> V_183 . V_189 -> V_197 ;
return 0 ;
}
static void F_103 ( struct V_1 * V_161 ,
T_1 V_201 , T_1 V_202 )
{
int V_75 = 0 ;
T_1 V_182 ;
V_182 = F_94 ( V_161 , V_201 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
F_104 ( V_161 , V_202 , V_182 ) ;
}
static void F_105 ( struct V_1 * V_161 ,
T_1 V_201 , T_1 V_202 ,
struct V_203 * V_204 )
{
int V_75 = 0 ;
T_1 V_182 ;
if ( V_204 -> V_205 ) {
V_182 = V_161 -> V_4 -> V_183 . V_206 [ V_204 -> V_205 ] ;
} else {
V_182 = F_94 ( V_161 , V_201 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
}
V_182 &= V_204 -> V_180 ;
V_182 <<= V_204 -> V_207 ;
V_182 >>= V_204 -> V_208 ;
V_182 |= V_204 -> V_209 ;
V_182 ^= V_204 -> V_210 ;
F_104 ( V_161 , V_202 , V_182 ) ;
}
static void F_106 ( struct V_1 * V_161 ,
struct V_211 * V_212 )
{
int V_44 ;
struct V_213 * V_214 ;
V_214 = (struct V_213 * ) ( ( char * ) V_212 +
sizeof( struct V_211 ) ) ;
for ( V_44 = 0 ; V_44 < V_212 -> V_188 ; V_44 ++ , V_214 ++ ) {
F_104 ( V_161 , V_214 -> V_215 ,
V_214 -> V_216 ) ;
if ( V_212 -> V_82 )
F_107 ( ( T_1 ) ( V_212 -> V_82 ) ) ;
}
}
static void F_108 ( struct V_1 * V_161 ,
struct V_211 * V_212 )
{
int V_44 ;
struct V_213 * V_214 ;
V_214 = (struct V_213 * ) ( ( char * ) V_212 +
sizeof( struct V_211 ) ) ;
for ( V_44 = 0 ; V_44 < V_212 -> V_188 ; V_44 ++ , V_214 ++ ) {
F_103 ( V_161 , V_214 -> V_215 ,
V_214 -> V_216 ) ;
if ( V_212 -> V_82 )
F_107 ( ( T_1 ) ( V_212 -> V_82 ) ) ;
}
}
static void F_109 ( struct V_1 * V_161 ,
struct V_211 * V_212 )
{
long V_82 ;
struct V_213 * V_214 ;
struct V_217 * V_218 ;
int V_44 , V_75 = 0 ;
unsigned long V_215 , V_216 ;
V_218 = (struct V_217 * ) ( ( char * ) V_212 +
sizeof( struct V_211 ) ) ;
V_214 = (struct V_213 * ) ( ( char * ) V_218 +
sizeof( struct V_217 ) ) ;
V_82 = ( long ) V_212 -> V_82 ;
if ( ! V_82 ) {
for ( V_44 = 0 ; V_44 < V_212 -> V_188 ; V_44 ++ , V_214 ++ )
F_99 ( V_161 , V_214 -> V_215 ,
V_82 , V_218 -> V_180 ,
V_218 -> V_27 ) ;
} else {
for ( V_44 = 0 ; V_44 < V_212 -> V_188 ; V_44 ++ , V_214 ++ ) {
V_215 = V_214 -> V_215 ;
V_216 = V_214 -> V_216 ;
if ( V_82 ) {
if ( F_99 ( V_161 ,
V_215 , V_82 ,
V_218 -> V_180 ,
V_218 -> V_27 ) ) {
F_94 ( V_161 , V_215 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
F_94 ( V_161 , V_216 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
}
}
}
}
}
static void F_110 ( struct V_1 * V_161 ,
struct V_211 * V_212 )
{
int V_44 ;
long V_82 ;
struct V_219 * V_214 ;
struct V_217 * V_218 ;
V_218 = (struct V_217 * ) ( ( char * ) V_212 +
sizeof( struct V_211 ) ) ;
V_214 = (struct V_219 * ) ( ( char * ) V_218 +
sizeof( struct V_217 ) ) ;
V_82 = ( long ) V_212 -> V_82 ;
for ( V_44 = 0 ; V_44 < V_212 -> V_188 ; V_44 ++ , V_214 ++ ) {
F_104 ( V_161 , V_214 -> V_220 ,
V_214 -> V_221 ) ;
F_104 ( V_161 , V_214 -> V_222 ,
V_214 -> V_223 ) ;
if ( V_82 )
F_99 ( V_161 , V_214 -> V_222 , V_82 ,
V_218 -> V_180 , V_218 -> V_27 ) ;
}
}
static void F_111 ( struct V_1 * V_161 ,
struct V_211 * V_212 )
{
int V_44 ;
struct V_213 * V_214 ;
struct V_203 * V_224 ;
V_224 = (struct V_203 * ) ( ( char * ) V_212 +
sizeof( struct V_211 ) ) ;
V_214 = (struct V_213 * ) ( ( char * ) V_224 +
sizeof( struct V_203 ) ) ;
for ( V_44 = 0 ; V_44 < V_212 -> V_188 ; V_44 ++ , V_214 ++ ) {
F_105 ( V_161 , V_214 -> V_215 ,
V_214 -> V_216 , V_224 ) ;
if ( V_212 -> V_82 )
F_107 ( ( T_1 ) ( V_212 -> V_82 ) ) ;
}
}
static void F_112 ( struct V_211 * V_212 )
{
if ( V_212 -> V_82 )
F_113 ( ( T_1 ) ( ( long ) V_212 -> V_82 ) ) ;
}
static void F_114 ( struct V_1 * V_161 ,
struct V_211 * V_212 )
{
long V_82 ;
int V_225 , V_44 , V_61 , V_75 ;
struct V_219 * V_214 ;
struct V_217 * V_218 ;
unsigned long V_140 ;
V_218 = (struct V_217 * ) ( ( char * ) V_212 +
sizeof( struct V_211 ) ) ;
V_214 = (struct V_219 * ) ( ( char * ) V_218 +
sizeof( struct V_217 ) ) ;
V_82 = ( long ) V_212 -> V_82 ;
for ( V_44 = 0 ; V_44 < V_212 -> V_188 ; V_44 ++ , V_214 ++ ) {
F_104 ( V_161 , V_214 -> V_222 ,
V_214 -> V_223 ) ;
if ( V_82 ) {
if ( ! F_99 ( V_161 , V_214 -> V_222 , V_82 ,
V_218 -> V_180 , V_218 -> V_27 ) ) {
V_225 = V_161 -> V_4 -> V_183 . V_226 ;
V_140 = V_214 -> V_220 ;
V_61 = F_94 ( V_161 , V_140 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
V_161 -> V_4 -> V_183 . V_206 [ V_225 ++ ] = V_61 ;
if ( V_225 == V_227 )
V_161 -> V_4 -> V_183 . V_226 = 1 ;
}
}
}
}
static inline void F_115 ( struct V_1 * V_161 )
{
V_161 -> V_4 -> V_183 . V_228 = 1 ;
}
static void F_116 ( struct V_1 * V_161 )
{
V_161 -> V_4 -> V_183 . V_229 = 1 ;
if ( V_161 -> V_4 -> V_183 . V_184 == 0 )
F_24 ( & V_161 -> V_11 -> V_12 ,
L_52 ) ;
else
F_24 ( & V_161 -> V_11 -> V_12 ,
L_53 ) ;
}
static void F_117 ( struct V_1 * V_161 ,
char * V_192 )
{
int V_225 , V_230 ;
struct V_211 * V_212 ;
char * V_214 = V_192 ;
V_161 -> V_4 -> V_183 . V_228 = 0 ;
V_161 -> V_4 -> V_183 . V_229 = 0 ;
V_230 = V_161 -> V_4 -> V_183 . V_189 -> V_230 ;
V_225 = V_161 -> V_4 -> V_183 . V_185 ;
for (; ( ! V_161 -> V_4 -> V_183 . V_228 ) && ( V_225 < V_230 ) ; V_225 ++ ) {
V_212 = (struct V_211 * ) V_214 ;
switch ( V_212 -> V_231 ) {
case V_232 :
break;
case V_233 :
F_106 ( V_161 , V_212 ) ;
break;
case V_234 :
F_108 ( V_161 , V_212 ) ;
break;
case V_235 :
F_109 ( V_161 , V_212 ) ;
break;
case V_236 :
F_110 ( V_161 , V_212 ) ;
break;
case V_237 :
F_111 ( V_161 , V_212 ) ;
break;
case V_238 :
F_112 ( V_212 ) ;
break;
case V_239 :
F_115 ( V_161 ) ;
break;
case V_240 :
F_116 ( V_161 ) ;
break;
case V_241 :
F_114 ( V_161 , V_212 ) ;
break;
default:
F_24 ( & V_161 -> V_11 -> V_12 ,
L_54 ,
V_29 , V_212 -> V_231 , V_225 ) ;
break;
}
V_214 += V_212 -> V_128 ;
}
V_161 -> V_4 -> V_183 . V_185 = V_225 ;
}
static void F_118 ( struct V_1 * V_161 )
{
V_161 -> V_4 -> V_183 . V_185 = 0 ;
F_117 ( V_161 , V_161 -> V_4 -> V_183 . V_200 ) ;
if ( V_161 -> V_4 -> V_183 . V_228 != 1 )
F_24 ( & V_161 -> V_11 -> V_12 , L_50 , V_29 ) ;
}
static void F_119 ( struct V_1 * V_161 )
{
F_117 ( V_161 , V_161 -> V_4 -> V_183 . V_199 ) ;
if ( V_161 -> V_4 -> V_183 . V_229 != 1 )
F_24 ( & V_161 -> V_11 -> V_12 , L_50 , V_29 ) ;
}
static void F_120 ( struct V_1 * V_161 )
{
F_117 ( V_161 , V_161 -> V_4 -> V_183 . V_198 ) ;
if ( V_161 -> V_4 -> V_183 . V_228 != 1 )
F_24 ( & V_161 -> V_11 -> V_12 , L_50 , V_29 ) ;
}
static int F_121 ( struct V_1 * V_2 )
{
struct V_135 * V_136 = V_2 -> V_4 -> V_136 ;
int V_75 = - V_30 ;
if ( F_122 ( & V_136 -> V_138 , V_136 -> V_242 ,
& ( V_2 -> V_11 -> V_12 ) ) ) {
F_24 ( & V_2 -> V_11 -> V_12 ,
L_55 ) ;
F_123 ( V_2 , V_243 ,
V_244 ) ;
} else {
if ( F_91 ( V_2 ) )
return V_75 ;
F_123 ( V_2 , V_243 ,
V_245 ) ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_75 = - V_30 ;
F_118 ( V_2 ) ;
V_3 = F_2 ( V_2 -> V_4 , V_32 ) ;
if ( ! ( V_3 & V_33 ) )
F_124 ( V_2 ) ;
F_120 ( V_2 ) ;
if ( F_87 ( V_2 ) )
return V_75 ;
if ( V_94 ) {
if ( F_121 ( V_2 ) )
return V_75 ;
} else {
F_123 ( V_2 , V_243 ,
V_244 ) ;
}
F_119 ( V_2 ) ;
if ( F_58 ( V_2 ) )
return - V_30 ;
return 0 ;
}
int F_125 ( struct V_1 * V_2 )
{
int V_75 ;
struct V_246 V_247 ;
struct V_79 * V_4 = V_2 -> V_4 ;
memset ( & V_247 , 0 , sizeof( struct V_246 ) ) ;
V_75 = F_126 ( V_2 , & V_247 , V_4 -> V_96 ) ;
if ( V_75 )
return - V_30 ;
V_4 -> V_248 = ( T_2 ) V_247 . V_249 ;
V_4 -> V_250 = V_247 . V_250 ;
V_4 -> V_251 = V_247 . V_251 ;
V_4 -> V_252 = V_247 . V_252 ;
V_4 -> V_253 = V_247 . V_253 ;
V_4 -> V_254 = V_247 . V_254 ;
V_4 -> V_255 = V_247 . V_255 ;
if ( F_74 ( V_256 , & V_2 -> V_43 ) )
return V_257 ;
if ( V_4 -> V_253 & V_258 )
return V_107 ;
return V_257 ;
}
int F_49 ( struct V_1 * V_2 )
{
struct V_79 * V_4 = V_2 -> V_4 ;
int V_71 ;
V_71 = F_125 ( V_2 ) ;
if ( V_71 == - V_30 )
return - V_30 ;
if ( V_71 == V_107 ) {
V_4 -> V_106 = V_107 ;
if ( F_127 ( V_2 ) )
return - V_30 ;
} else if ( V_71 == V_257 ) {
V_4 -> V_106 = V_259 ;
V_2 -> V_77 -> V_78 = V_260 ;
V_4 -> V_8 . V_99 = F_54 ;
} else {
return - V_30 ;
}
return 0 ;
}
static void F_128 ( struct V_1 * V_2 )
{
struct V_79 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_261 == V_262 ) {
V_2 -> V_263 = V_264 ;
V_2 -> V_265 = V_266 ;
V_2 -> V_267 = V_268 ;
V_2 -> V_269 = V_268 ;
} else if ( V_4 -> V_261 == V_270 ) {
V_2 -> V_263 = V_271 ;
V_2 -> V_267 = V_272 ;
V_2 -> V_269 = V_272 ;
V_2 -> V_265 = V_273 ;
}
V_2 -> V_274 = V_275 ;
V_2 -> V_276 = V_277 ;
}
static int V_260 ( struct V_1 * V_2 )
{
int V_75 = - V_30 ;
F_129 ( V_2 ) ;
if ( F_130 ( V_2 ) )
return V_75 ;
F_128 ( V_2 ) ;
V_2 -> V_4 -> V_278 = ! ! V_279 ;
V_2 -> V_103 |= V_280 ;
F_4 ( & V_2 -> V_11 -> V_12 , L_56 ,
V_2 -> V_4 -> V_281 ) ;
return 0 ;
}
static void F_131 ( struct V_1 * V_2 )
{
struct V_282 V_231 ;
T_1 V_283 , V_284 ;
int V_27 ;
V_283 = F_2 ( V_2 -> V_4 , V_5 ) ;
V_284 = F_2 ( V_2 -> V_4 , V_18 ) ;
if ( F_132 ( V_2 , V_283 , V_284 ) ) {
V_27 = F_133 ( & V_231 , V_2 ,
V_285 ) ;
if ( V_27 )
return;
V_231 . V_286 . V_287 [ 1 ] = V_288 ;
V_27 = F_134 ( V_2 , & V_231 ) ;
if ( V_27 )
F_24 ( & V_2 -> V_11 -> V_12 ,
L_57 ) ;
F_135 ( & V_231 ) ;
}
}
static int F_136 ( struct V_1 * V_2 )
{
struct V_79 * V_4 = V_2 -> V_4 ;
struct V_289 * V_11 = V_2 -> V_11 ;
struct V_135 * V_136 ;
int V_75 = 0 ;
V_4 -> V_136 = F_88 ( sizeof( * V_136 ) , V_133 ) ;
if ( ! V_4 -> V_136 ) {
V_75 = - V_134 ;
} else {
V_136 = V_4 -> V_136 ;
switch ( V_11 -> V_290 ) {
case V_291 :
strncpy ( V_136 -> V_242 , V_292 ,
V_293 ) ;
break;
case V_294 :
strncpy ( V_136 -> V_242 , V_295 ,
V_293 ) ;
break;
default:
F_24 ( & V_11 -> V_12 , L_58 ,
V_29 ) ;
V_75 = - V_296 ;
break;
}
}
return V_75 ;
}
int F_137 ( struct V_1 * V_2 , int V_297 )
{
struct V_79 * V_4 = V_2 -> V_4 ;
int V_75 = 0 ;
V_4 -> V_278 = ! ! V_279 ;
V_75 = F_138 ( V_2 ) ;
if ( V_75 )
goto exit;
if ( F_86 ( V_2 ) ) {
V_75 = F_139 ( V_2 , V_297 ) ;
if ( V_75 )
goto V_298;
else
return V_75 ;
}
V_75 = F_58 ( V_2 ) ;
if ( V_75 )
goto V_298;
if ( ! F_140 ( V_2 ) )
F_141 ( V_2 ) ;
V_75 = F_136 ( V_2 ) ;
if ( V_75 )
goto V_298;
V_75 = F_79 ( V_2 ) ;
if ( V_75 )
goto V_299;
V_75 = F_142 ( V_2 , 0 , 0 ) ;
if ( V_75 ) {
F_24 ( & V_2 -> V_11 -> V_12 , L_59 ) ;
goto V_300;
}
V_75 = F_143 ( V_2 ) ;
if ( V_75 )
goto V_301;
F_131 ( V_2 ) ;
F_144 ( & V_2 -> V_302 , V_303 ) ;
F_47 ( V_2 , 1 ) ;
V_75 = F_49 ( V_2 ) ;
if ( V_75 )
goto V_301;
V_75 = V_2 -> V_77 -> V_78 ( V_2 ) ;
if ( V_75 )
goto V_301;
if ( V_2 -> V_304 && F_145 ( V_2 ) )
F_146 ( V_2 ) ;
F_72 ( & V_2 -> V_115 . V_114 ) ;
return 0 ;
V_301:
F_147 ( V_2 ) ;
V_300:
F_148 ( V_2 ) ;
V_299:
F_89 ( V_4 -> V_136 ) ;
V_298:
F_26 ( V_2 ) ;
F_149 ( V_4 -> V_76 ) ;
exit:
return V_75 ;
}
void F_150 ( struct V_1 * V_2 )
{
struct V_79 * V_4 = V_2 -> V_4 ;
struct V_305 * V_8 = & V_4 -> V_8 ;
F_23 ( V_102 , & V_8 -> V_27 ) ;
F_84 ( & V_2 -> V_115 ) ;
if ( V_4 -> V_106 == V_107 )
F_64 ( V_2 , 1 ) ;
F_25 ( V_2 ) ;
F_47 ( V_2 , 0 ) ;
F_84 ( & V_2 -> V_302 ) ;
}
int F_151 ( struct V_1 * V_2 )
{
struct V_79 * V_4 = V_2 -> V_4 ;
struct V_305 * V_8 = & V_4 -> V_8 ;
int V_71 = 0 ;
T_1 V_62 ;
V_8 -> V_10 = V_56 ;
V_62 = F_38 ( V_2 ) ;
if ( V_4 -> V_96 == V_62 ) {
V_71 = F_40 ( V_2 ) ;
if ( V_71 < 0 )
return V_71 ;
F_13 ( V_2 , 0 ) ;
}
V_71 = V_8 -> V_99 ( V_2 ) ;
return V_71 ;
}
void F_152 ( struct V_1 * V_2 )
{
struct V_79 * V_4 = V_2 -> V_4 ;
struct V_305 * V_8 = & V_4 -> V_8 ;
T_1 V_62 ;
V_8 -> V_10 = V_57 ;
V_62 = F_38 ( V_2 ) ;
if ( V_4 -> V_96 == V_62 )
F_37 ( V_2 , 0 ) ;
F_75 ( V_2 , F_72 , 0 ) ;
}
