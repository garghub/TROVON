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
F_24 ( V_2 -> V_41 , L_7 , V_29 ) ;
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
F_43 ( & V_2 -> V_11 -> V_12 ,
L_9 , V_27 ) ;
if ( F_44 ( V_27 ) == V_74 ) {
F_43 ( & V_2 -> V_11 -> V_12 ,
L_10
L_11 ) ;
F_43 ( & V_2 -> V_11 -> V_12 ,
L_12 ) ;
return - V_30 ;
}
}
return 0 ;
}
int F_45 ( struct V_1 * V_2 )
{
int V_75 ;
F_46 ( V_2 -> V_4 -> V_76 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 , 1 ) ;
V_75 = F_49 ( V_2 ) ;
if ( V_75 )
return V_75 ;
F_47 ( V_2 ) ;
if ( F_50 ( V_2 ) ) {
F_33 ( V_2 , 1 ) ;
return - V_30 ;
}
if ( V_2 -> V_77 -> V_78 ( V_2 ) ) {
F_33 ( V_2 , 1 ) ;
return - V_30 ;
}
if ( V_2 -> V_19 == 0 )
F_51 ( V_2 ) ;
F_52 ( V_2 -> V_79 ) ;
F_30 ( V_2 ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_80 * V_4 = V_2 -> V_4 ;
F_11 ( V_2 , 1 , 1 ) ;
F_5 ( V_2 , 0 , 1 ) ;
F_54 ( V_81 , & V_2 -> V_4 -> V_8 . V_27 ) ;
V_4 -> V_8 . V_82 = 0 ;
V_4 -> V_8 . V_83 = V_84 ;
V_4 -> V_8 . V_85 = 0 ;
V_4 -> V_8 . V_86 = 0 ;
V_4 -> V_87 = 0 ;
V_2 -> V_88 = 0 ;
V_4 -> V_8 . V_89 = 0 ;
F_23 ( V_42 , & V_2 -> V_43 ) ;
}
int F_55 ( struct V_1 * V_2 )
{
struct V_80 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_8 . V_10 != V_57 ) {
F_53 ( V_2 ) ;
if ( ( V_4 -> V_8 . V_10 == V_56 ) ||
( V_4 -> V_8 . V_10 == V_54 ) ) {
if ( F_45 ( V_2 ) )
return - V_30 ;
}
}
return 0 ;
}
int F_56 ( struct V_1 * V_2 )
{
T_1 V_43 ;
struct V_80 * V_4 = V_2 -> V_4 ;
V_43 = F_2 ( V_2 -> V_4 , V_90 ) ;
if ( V_43 != V_91 ) {
if ( ! V_4 -> V_8 . V_92 -- ) {
F_33 ( V_2 , 1 ) ;
return - V_30 ;
}
F_4 ( & V_2 -> V_11 -> V_12 , L_13 ) ;
return - V_30 ;
} else {
if ( V_4 -> V_8 . V_93 != V_91 ) {
F_53 ( V_2 ) ;
if ( V_4 -> V_8 . V_10 != V_94 ) {
if ( F_45 ( V_2 ) )
return - V_30 ;
}
V_2 -> V_4 -> V_8 . V_93 = V_91 ;
F_4 ( & V_2 -> V_11 -> V_12 , L_14 ) ;
}
}
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
V_2 -> V_4 -> V_8 . V_85 = - V_30 ;
F_43 ( & V_2 -> V_11 -> V_12 ,
L_15 , V_29 ) ;
F_23 ( V_42 , & V_2 -> V_43 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
F_11 ( V_2 , 1 , 0 ) ;
F_5 ( V_2 , 1 , 0 ) ;
if ( V_95 ) {
F_39 ( V_2 , 0 ) ;
} else {
if ( F_59 ( V_2 ) ) {
F_33 ( V_2 , 0 ) ;
return - V_30 ;
} else {
F_37 ( V_2 , 0 ) ;
}
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_36 , V_71 = 0 ;
T_1 V_62 ;
V_36 = V_96 ;
if ( V_2 -> V_4 -> V_8 . V_10 == V_56 ) {
V_62 = F_38 ( V_2 ) ;
if ( V_2 -> V_4 -> V_97 == V_62 )
V_71 = F_39 ( V_2 , 1 ) ;
} else {
V_71 = F_15 ( V_2 , V_36 ) ;
}
return V_71 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_80 * V_4 = V_2 -> V_4 ;
struct V_98 * V_99 = V_4 -> V_76 ;
int V_71 = 0 ;
T_1 V_3 ;
if ( V_4 -> V_8 . V_100 ( V_2 ) )
return - V_30 ;
if ( F_62 ( V_2 ) ) {
if ( V_4 -> V_101 == V_102 ) {
F_41 ( V_2 ) ;
F_43 ( & V_2 -> V_11 -> V_12 ,
L_16 ,
V_2 -> V_4 -> V_101 ) ;
F_23 ( V_103 , & V_99 -> V_27 ) ;
F_54 ( V_42 , & V_2 -> V_43 ) ;
F_25 ( V_2 ) ;
F_33 ( V_2 , 1 ) ;
return - V_30 ;
}
}
V_3 = F_2 ( V_2 -> V_4 , V_32 ) ;
V_71 = F_63 ( V_2 ) ;
if ( V_71 ) {
V_2 -> V_104 |= V_105 ;
if ( ! ( V_3 & V_106 ) ) {
F_23 ( V_103 , & V_99 -> V_27 ) ;
F_54 ( V_42 , & V_2 -> V_43 ) ;
F_36 ( V_2 , 1 ) ;
} else {
F_24 ( V_2 -> V_41 , L_17 ,
V_29 ) ;
F_33 ( V_2 , 1 ) ;
}
return - V_30 ;
}
if ( ( V_3 & V_33 ) || V_4 -> V_8 . V_86 ) {
F_23 ( V_103 , & V_99 -> V_27 ) ;
F_36 ( V_2 , 1 ) ;
return V_71 ;
}
if ( V_4 -> V_87 &&
! ( V_3 & V_106 ) ) {
V_2 -> V_4 -> V_87 = 0 ;
F_17 ( V_2 ) ;
return V_71 ;
}
if ( V_2 -> V_4 -> V_8 . V_82 ) {
F_35 ( V_2 , 1 ) ;
F_5 ( V_2 , 0 , 1 ) ;
return V_71 ;
}
return V_71 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_98 * V_99 = V_2 -> V_4 -> V_76 ;
int V_71 = 0 ;
if ( V_2 -> V_4 -> V_8 . V_10 != V_56 ) {
F_5 ( V_2 , 0 , 1 ) ;
F_54 ( V_42 , & V_2 -> V_43 ) ;
F_23 ( V_103 , & V_99 -> V_27 ) ;
if ( V_2 -> V_4 -> V_107 == V_108 )
F_65 ( V_2 , 1 ) ;
if ( F_66 ( V_2 ) ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_18 , V_29 ) ;
V_2 -> V_4 -> V_8 . V_89 = 1 ;
return 0 ;
} else {
F_14 ( V_2 , 1 , 1 ) ;
F_25 ( V_2 ) ;
}
}
if ( F_66 ( V_2 ) ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_18 , V_29 ) ;
return - 1 ;
} else {
if ( V_2 -> V_4 -> V_8 . V_89 ) {
F_14 ( V_2 , 1 , 1 ) ;
F_25 ( V_2 ) ;
V_2 -> V_4 -> V_8 . V_89 = 0 ;
}
V_71 = F_16 ( V_2 ) ;
if ( V_71 ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_19 , V_29 ) ;
return - 1 ;
}
}
F_34 ( V_2 , 1 ) ;
return V_71 ;
}
static int F_67 ( struct V_1 * V_2 )
{
F_43 ( & V_2 -> V_11 -> V_12 , L_20 , V_29 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_80 * V_4 = V_2 -> V_4 ;
T_1 V_3 , V_62 ;
V_3 = F_2 ( V_2 -> V_4 , V_32 ) ;
if ( V_3 & V_106 ) {
V_62 = F_38 ( V_2 ) ;
if ( V_4 -> V_97 == V_62 ) {
F_69 ( V_2 ) ;
F_70 ( V_2 ) ;
}
}
F_71 ( V_2 -> V_41 , L_21 ,
V_29 ) ;
F_23 ( V_42 , & V_2 -> V_43 ) ;
V_4 -> V_8 . V_85 = - V_30 ;
return;
}
static int F_72 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_11 -> V_12 , L_20 , V_29 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
T_1 V_43 )
{
T_1 V_6 , V_7 , V_109 ;
V_6 = V_2 -> V_4 -> V_8 . V_9 ;
V_7 = V_2 -> V_4 -> V_8 . V_10 ;
V_109 = V_43 ;
if ( ( V_109 < V_110 ) ||
( V_109 > V_111 ) ) {
F_43 ( & V_2 -> V_11 -> V_12 ,
L_22 ,
V_29 , V_6 , V_7 , V_43 ) ;
return 1 ;
}
if ( ( V_6 == V_94 ) &&
( V_7 == V_94 ) ) {
if ( ( V_109 != V_110 ) &&
( V_109 != V_57 ) ) {
F_43 ( & V_2 -> V_11 -> V_12 ,
L_23 ,
V_29 , V_6 , V_7 , V_109 ) ;
return 1 ;
}
}
if ( V_109 == V_54 ) {
if ( ( V_7 != V_54 ) &&
( V_7 != V_110 ) &&
( V_7 != V_56 ) ) {
F_43 ( & V_2 -> V_11 -> V_12 ,
L_23 ,
V_29 , V_6 , V_7 , V_109 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_74 ( struct V_1 * V_2 )
{
if ( V_2 -> V_112 . V_113 )
F_75 ( V_2 ) ;
}
void F_76 ( struct V_114 * V_115 )
{
struct V_1 * V_2 ;
T_1 V_43 ;
V_2 = F_77 ( V_115 , struct V_1 , V_116 . V_115 ) ;
V_43 = F_2 ( V_2 -> V_4 , V_52 ) ;
if ( F_73 ( V_2 , V_43 ) ) {
F_3 ( V_2 ) ;
V_2 -> V_4 -> V_8 . V_9 = V_94 ;
} else {
V_2 -> V_4 -> V_8 . V_9 = V_43 ;
}
switch ( V_2 -> V_4 -> V_8 . V_9 ) {
case V_57 :
F_61 ( V_2 ) ;
break;
case V_56 :
F_64 ( V_2 ) ;
break;
case V_55 :
F_67 ( V_2 ) ;
break;
case V_53 :
F_68 ( V_2 ) ;
return;
case V_54 :
F_60 ( V_2 ) ;
break;
case V_111 :
F_72 ( V_2 ) ;
break;
default:
F_57 ( V_2 ) ;
return;
}
V_2 -> V_4 -> V_8 . V_10 = V_2 -> V_4 -> V_8 . V_9 ;
F_74 ( V_2 ) ;
if ( F_78 ( V_81 , & V_2 -> V_4 -> V_8 . V_27 ) )
F_79 ( V_2 , F_76 ,
V_2 -> V_4 -> V_8 . V_83 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
T_1 V_117 , V_3 ;
if ( F_81 ( V_2 ,
V_118 ,
( T_2 * ) & V_117 , 1 ) ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_24 , V_29 ) ;
V_2 -> V_119 = V_96 ;
V_2 -> V_120 = V_39 ;
} else {
V_2 -> V_119 = V_117 & 0xFFFF ;
V_2 -> V_120 = ( ( V_117 >> 16 ) & 0xFFFF ) ;
}
V_2 -> V_4 -> V_8 . V_9 = V_94 ;
V_2 -> V_4 -> V_8 . V_10 = V_94 ;
V_2 -> V_4 -> V_8 . V_83 = V_84 ;
V_2 -> V_4 -> V_8 . V_85 = 0 ;
V_2 -> V_4 -> V_8 . V_86 = 0 ;
V_2 -> V_4 -> V_8 . V_13 = ( char * * ) V_121 ;
F_23 ( V_42 , & V_2 -> V_43 ) ;
F_54 ( V_81 , & V_2 -> V_4 -> V_8 . V_27 ) ;
if ( ! V_122 ) {
V_3 = F_2 ( V_2 -> V_4 , V_32 ) ;
V_3 = V_3 | V_106 ;
F_7 ( V_2 -> V_4 , V_32 , V_3 ) ;
}
}
static int
F_82 ( struct V_1 * V_2 )
{
T_1 V_43 , V_3 ;
if ( F_6 ( V_2 ) )
return - V_30 ;
F_7 ( V_2 -> V_4 , V_123 , 0 ) ;
if ( F_10 ( V_2 , 0 ) ) {
F_8 ( V_2 ) ;
return - V_30 ;
}
V_43 = F_2 ( V_2 -> V_4 , V_52 ) ;
if ( F_73 ( V_2 , V_43 ) ) {
F_8 ( V_2 ) ;
return - V_30 ;
}
if ( V_43 != V_110 && V_95 ) {
F_7 ( V_2 -> V_4 , V_52 ,
V_110 ) ;
V_43 = V_110 ;
}
V_2 -> V_4 -> V_8 . V_9 = V_43 ;
if ( V_43 == V_110 )
F_58 ( V_2 ) ;
if ( V_122 ) {
V_3 = F_2 ( V_2 -> V_4 , V_32 ) ;
V_3 = V_3 & ~ V_106 ;
F_7 ( V_2 -> V_4 , V_32 , V_3 ) ;
}
F_8 ( V_2 ) ;
return 0 ;
}
int F_83 ( struct V_1 * V_2 )
{
int V_71 = - V_30 ;
F_80 ( V_2 ) ;
if ( F_84 ( V_2 ) )
return V_71 ;
if ( ! F_1 ( V_2 ) ) {
if ( F_82 ( V_2 ) )
return - V_30 ;
} else {
if ( F_12 ( V_2 ) )
return - V_30 ;
}
F_5 ( V_2 , 0 , 1 ) ;
return 0 ;
}
void F_85 ( struct V_1 * V_2 )
{
int V_47 ;
T_1 V_3 ;
while ( F_18 ( V_42 , & V_2 -> V_43 ) )
F_86 ( 10000 , 11000 ) ;
V_47 = F_2 ( V_2 -> V_4 , V_124 ) ;
V_47 = V_47 & 0xFF ;
if ( V_47 == V_2 -> V_19 ) {
F_43 ( & V_2 -> V_11 -> V_12 ,
L_25 , V_29 , V_47 ) ;
F_87 ( 20 ) ;
V_47 = F_2 ( V_2 -> V_4 , V_124 ) ;
V_47 = V_47 & 0xFF ;
}
V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
V_3 = V_3 & ~ ( 1 << V_2 -> V_19 ) ;
F_7 ( V_2 -> V_4 , V_5 , V_3 ) ;
F_23 ( V_81 , & V_2 -> V_4 -> V_8 . V_27 ) ;
F_23 ( V_42 , & V_2 -> V_43 ) ;
F_88 ( & V_2 -> V_116 ) ;
}
void F_89 ( struct V_1 * V_2 , T_1 V_125 )
{
T_1 V_3 ;
if ( F_90 ( V_2 ) )
return;
if ( F_6 ( V_2 ) ) {
F_43 ( & V_2 -> V_11 -> V_12 ,
L_26 , V_29 ) ;
return;
}
V_3 = F_2 ( V_2 -> V_4 , V_32 ) ;
if ( V_3 & V_106 ) {
F_24 ( V_2 -> V_41 , L_17 ,
V_29 ) ;
F_33 ( V_2 , 0 ) ;
F_8 ( V_2 ) ;
return;
}
if ( V_125 == V_126 ) {
V_3 = F_2 ( V_2 -> V_4 , V_32 ) ;
V_3 = V_3 | V_33 ;
F_7 ( V_2 -> V_4 , V_32 , V_3 ) ;
} else if ( V_125 == V_127 ) {
V_2 -> V_4 -> V_8 . V_86 = 1 ;
}
F_8 ( V_2 ) ;
return;
}
static int F_91 ( struct V_1 * V_2 )
{
T_2 * V_128 ;
T_1 V_49 , V_129 ;
T_3 V_130 ;
int V_71 = - V_30 ;
V_49 = V_131 ;
V_130 = F_2 ( V_2 -> V_4 , V_132 ) ;
V_129 = F_2 ( V_2 -> V_4 , V_133 ) ;
if ( V_129 & 0xF )
V_129 = ( V_129 + 16 ) & ~ 0xF ;
V_128 = F_92 ( V_129 ) ;
if ( V_128 == NULL )
return - V_134 ;
V_71 = F_81 ( V_2 , V_49 , V_128 ,
V_129 / sizeof( T_1 ) ) ;
if ( V_71 ) {
F_93 ( V_128 ) ;
return V_71 ;
}
V_71 = F_94 ( V_2 , V_130 , ( T_1 * ) V_128 ,
V_129 / 16 ) ;
if ( V_71 ) {
F_93 ( V_128 ) ;
return V_71 ;
}
F_93 ( V_128 ) ;
return V_71 ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_135 * V_136 = V_2 -> V_4 -> V_136 ;
const struct V_137 * V_138 = V_136 -> V_138 ;
T_1 V_130 , * V_128 ;
int V_44 , V_71 = - V_30 ;
T_2 V_139 [ 16 ] ;
T_4 V_129 ;
T_3 V_140 ;
V_130 = F_2 ( V_2 -> V_4 , V_141 ) ;
V_129 = ( V_138 -> V_129 & ~ 0xF ) ;
V_128 = ( T_1 * ) V_138 -> V_139 ;
V_140 = ( T_3 ) V_130 ;
V_71 = F_94 ( V_2 , V_140 ,
( T_1 * ) V_128 , V_129 / 16 ) ;
if ( V_71 ) {
F_43 ( & V_2 -> V_11 -> V_12 , L_27 ) ;
F_96 ( V_138 ) ;
V_136 -> V_138 = NULL ;
return - V_30 ;
}
if ( V_138 -> V_129 & 0xF ) {
V_140 = V_130 + V_129 ;
for ( V_44 = 0 ; V_44 < ( V_138 -> V_129 & 0xF ) ; V_44 ++ )
V_139 [ V_44 ] = V_138 -> V_139 [ V_129 + V_44 ] ;
for (; V_44 < 16 ; V_44 ++ )
V_139 [ V_44 ] = 0 ;
V_71 = F_94 ( V_2 , V_140 ,
( T_1 * ) V_139 , 1 ) ;
if ( V_71 ) {
F_43 ( & V_2 -> V_11 -> V_12 ,
L_27 ) ;
F_96 ( V_138 ) ;
V_136 -> V_138 = NULL ;
return - V_30 ;
}
}
F_96 ( V_138 ) ;
V_136 -> V_138 = NULL ;
return 0 ;
}
static void F_97 ( struct V_1 * V_2 )
{
int V_44 , V_61 ;
T_1 V_3 = 0 , V_142 = 0 , V_58 = 0 ;
int V_75 = 0 ;
V_3 = F_98 ( V_2 , V_143 , & V_75 ) ;
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
V_3 = F_98 ( V_2 , V_58 + ( V_44 * 0x4 ) , & V_75 ) ;
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
V_3 = F_98 ( V_2 , V_58 + ( V_44 * 0x4 ) , & V_75 ) ;
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
V_3 = F_98 ( V_2 , V_58 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
V_3 &= ~ ( 0x7 << 29 ) ;
F_99 ( V_2 , V_58 , ( V_3 | ( V_44 << 29 ) ) ) ;
V_3 = F_98 ( V_2 , V_58 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
F_4 ( & V_2 -> V_11 -> V_12 , L_31 , V_3 ) ;
}
F_4 ( & V_2 -> V_11 -> V_12 , L_32 ) ;
}
V_3 = F_98 ( V_2 , V_150 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
V_142 = F_98 ( V_2 , V_151 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
F_4 ( & V_2 -> V_11 -> V_12 ,
L_37 ,
V_3 , V_142 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
T_1 V_58 = 0 , V_44 , V_61 ;
if ( F_6 ( V_2 ) ) {
F_43 ( & V_2 -> V_11 -> V_12 ,
L_38 , V_29 ) ;
return;
}
F_97 ( V_2 ) ;
F_99 ( V_2 , V_143 , 0x0 ) ;
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
if ( V_61 == 0 )
V_58 = V_144 ;
else if ( V_61 == 1 )
V_58 = V_145 ;
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ )
F_99 ( V_2 , V_58 + ( V_44 * 0x4 ) , 0x0 ) ;
}
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
if ( V_61 == 0 )
V_58 = V_146 ;
else if ( V_61 == 1 )
V_58 = V_147 ;
for ( V_44 = 0 ; V_44 < 4 ; V_44 ++ )
F_99 ( V_2 , V_58 + ( V_44 * 0x4 ) , 0x03FF03FF ) ;
}
F_99 ( V_2 , V_150 , 0 ) ;
F_99 ( V_2 , V_151 , 0 ) ;
F_4 ( & V_2 -> V_11 -> V_12 ,
L_39 ) ;
F_8 ( V_2 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
F_99 ( V_2 , V_152 , 0 ) ;
F_99 ( V_2 , V_153 , 0 ) ;
F_99 ( V_2 , V_154 , 0 ) ;
F_99 ( V_2 , V_155 , 0 ) ;
F_99 ( V_2 , V_156 , 0 ) ;
F_99 ( V_2 , V_157 , 0 ) ;
F_99 ( V_2 , V_158 , 0 ) ;
F_99 ( V_2 , V_159 , 0 ) ;
F_99 ( V_2 , V_160 , 1 ) ;
}
static int F_63 ( struct V_1 * V_161 )
{
T_1 V_162 , V_163 ;
int V_164 , V_71 = - V_30 , V_75 = 0 ;
V_164 = V_165 ;
V_161 -> V_162 = F_42 ( V_161 ,
V_166 ) ;
do {
F_87 ( V_167 ) ;
V_162 = F_42 ( V_161 ,
V_166 ) ;
if ( V_162 != V_161 -> V_162 ) {
V_71 = V_168 ;
break;
}
} while ( -- V_164 );
if ( V_71 ) {
F_43 ( & V_161 -> V_11 -> V_12 , L_40 ) ;
F_101 ( V_161 ) ;
F_100 ( V_161 ) ;
V_163 = F_42 ( V_161 ,
V_72 ) ;
F_4 ( & V_161 -> V_11 -> V_12 , L_41
L_42
L_43
L_44
L_45 , V_163 ,
F_42 ( V_161 , V_169 ) ,
F_98 ( V_161 , V_170 , & V_75 ) ,
F_98 ( V_161 , V_171 , & V_75 ) ,
F_98 ( V_161 , V_172 , & V_75 ) ,
F_98 ( V_161 , V_173 , & V_75 ) ,
F_98 ( V_161 , V_174 , & V_75 ) ) ;
if ( F_44 ( V_163 ) == 0x67 )
F_43 ( & V_161 -> V_11 -> V_12 ,
L_46 ) ;
}
return V_71 ;
}
static int F_102 ( struct V_1 * V_161 )
{
int V_164 = V_175 ;
T_1 V_3 ;
do {
V_3 = F_42 ( V_161 , V_176 ) ;
if ( V_3 == V_177 )
return 0 ;
F_87 ( V_178 ) ;
} while ( -- V_164 );
F_43 ( & V_161 -> V_11 -> V_12 , L_47 , V_29 , V_3 ) ;
return - V_30 ;
}
static int F_59 ( struct V_1 * V_161 )
{
int V_75 ;
V_75 = F_102 ( V_161 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_63 ( V_161 ) ;
if ( V_75 )
return V_75 ;
return V_75 ;
}
static int F_103 ( struct V_1 * V_161 , T_1 V_140 ,
int V_179 , T_1 V_180 , T_1 V_27 )
{
int V_181 , V_75 = 0 ;
T_1 V_182 ;
T_2 V_164 ;
V_182 = F_98 ( V_161 , V_140 , & V_75 ) ;
if ( V_75 == - V_30 )
return V_75 ;
V_164 = V_179 / 10 ;
do {
if ( ( V_182 & V_180 ) != V_27 ) {
V_181 = 1 ;
F_87 ( V_179 / 10 ) ;
V_182 = F_98 ( V_161 , V_140 , & V_75 ) ;
if ( V_75 == - V_30 )
return V_75 ;
} else {
V_181 = 0 ;
break;
}
} while ( V_164 -- );
if ( V_181 ) {
V_161 -> V_4 -> V_183 . V_184 ++ ;
F_43 ( & V_161 -> V_11 -> V_12 ,
L_48 ,
V_29 , V_161 -> V_4 -> V_183 . V_185 ) ;
F_43 ( & V_161 -> V_11 -> V_12 ,
L_49 ,
V_182 , V_180 , V_27 ) ;
}
return V_181 ;
}
static int F_104 ( struct V_1 * V_161 )
{
T_1 V_186 = 0 ;
T_5 * V_187 = ( T_5 * ) V_161 -> V_4 -> V_183 . V_187 ;
int V_188 = V_161 -> V_4 -> V_183 . V_189 -> V_129 / sizeof( T_5 ) ;
while ( V_188 -- > 0 )
V_186 += * V_187 ++ ;
while ( V_186 >> 16 )
V_186 = ( V_186 & 0xFFFF ) + ( V_186 >> 16 ) ;
if ( ~ V_186 ) {
return 0 ;
} else {
F_43 ( & V_161 -> V_11 -> V_12 , L_50 , V_29 ) ;
return - 1 ;
}
}
static int F_84 ( struct V_1 * V_161 )
{
struct V_80 * V_4 = V_161 -> V_4 ;
T_1 V_140 , V_188 , V_190 , V_191 ;
T_2 * V_192 ;
if ( V_4 -> V_183 . V_187 != NULL ) {
V_190 = V_161 -> V_193 ;
V_191 = F_105 ( V_161 ) ;
if ( V_191 > V_190 )
F_106 ( V_4 -> V_183 . V_187 ) ;
else
return 0 ;
}
V_4 -> V_183 . V_184 = 0 ;
V_4 -> V_183 . V_187 = F_107 ( V_194 , V_195 ) ;
if ( V_161 -> V_4 -> V_183 . V_187 == NULL )
return - V_134 ;
V_192 = V_161 -> V_4 -> V_183 . V_187 ;
V_140 = V_196 ;
V_188 = sizeof( struct V_197 ) / sizeof( T_1 ) ;
if ( F_108 ( V_161 , V_140 , V_192 , V_188 ) ) {
F_43 ( & V_161 -> V_11 -> V_12 , L_51 , V_29 ) ;
return - V_30 ;
}
V_4 -> V_183 . V_189 = (struct V_197 * ) V_4 -> V_183 . V_187 ;
V_140 = V_196 + V_4 -> V_183 . V_189 -> V_198 ;
V_192 = V_4 -> V_183 . V_187 + V_4 -> V_183 . V_189 -> V_198 ;
V_188 = ( V_4 -> V_183 . V_189 -> V_129 - V_4 -> V_183 . V_189 -> V_198 ) / sizeof( T_1 ) ;
if ( F_108 ( V_161 , V_140 , V_192 , V_188 ) ) {
F_43 ( & V_161 -> V_11 -> V_12 , L_51 , V_29 ) ;
return - V_30 ;
}
if ( F_104 ( V_161 ) )
return - V_30 ;
V_4 -> V_183 . V_199 = V_4 -> V_183 . V_187 + V_4 -> V_183 . V_189 -> V_199 ;
V_4 -> V_183 . V_200 = V_4 -> V_183 . V_187 +
V_4 -> V_183 . V_189 -> V_200 ;
V_4 -> V_183 . V_201 = V_4 -> V_183 . V_187 + V_4 -> V_183 . V_189 -> V_198 ;
return 0 ;
}
static void F_109 ( struct V_1 * V_161 ,
T_1 V_202 , T_1 V_203 )
{
int V_75 = 0 ;
T_1 V_182 ;
V_182 = F_98 ( V_161 , V_202 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
F_110 ( V_161 , V_203 , V_182 ) ;
}
static void F_111 ( struct V_1 * V_161 ,
T_1 V_202 , T_1 V_203 ,
struct V_204 * V_205 )
{
int V_75 = 0 ;
T_1 V_182 ;
if ( V_205 -> V_206 ) {
V_182 = V_161 -> V_4 -> V_183 . V_207 [ V_205 -> V_206 ] ;
} else {
V_182 = F_98 ( V_161 , V_202 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
}
V_182 &= V_205 -> V_180 ;
V_182 <<= V_205 -> V_208 ;
V_182 >>= V_205 -> V_209 ;
V_182 |= V_205 -> V_210 ;
V_182 ^= V_205 -> V_211 ;
F_110 ( V_161 , V_203 , V_182 ) ;
}
static void F_112 ( struct V_1 * V_161 ,
struct V_212 * V_213 )
{
int V_44 ;
struct V_214 * V_215 ;
V_215 = (struct V_214 * ) ( ( char * ) V_213 +
sizeof( struct V_212 ) ) ;
for ( V_44 = 0 ; V_44 < V_213 -> V_188 ; V_44 ++ , V_215 ++ ) {
F_110 ( V_161 , V_215 -> V_216 ,
V_215 -> V_217 ) ;
if ( V_213 -> V_83 )
F_113 ( ( T_1 ) ( V_213 -> V_83 ) ) ;
}
}
static void F_114 ( struct V_1 * V_161 ,
struct V_212 * V_213 )
{
int V_44 ;
struct V_214 * V_215 ;
V_215 = (struct V_214 * ) ( ( char * ) V_213 +
sizeof( struct V_212 ) ) ;
for ( V_44 = 0 ; V_44 < V_213 -> V_188 ; V_44 ++ , V_215 ++ ) {
F_109 ( V_161 , V_215 -> V_216 ,
V_215 -> V_217 ) ;
if ( V_213 -> V_83 )
F_113 ( ( T_1 ) ( V_213 -> V_83 ) ) ;
}
}
static void F_115 ( struct V_1 * V_161 ,
struct V_212 * V_213 )
{
long V_83 ;
struct V_214 * V_215 ;
struct V_218 * V_219 ;
int V_44 , V_75 = 0 ;
unsigned long V_216 , V_217 ;
V_219 = (struct V_218 * ) ( ( char * ) V_213 +
sizeof( struct V_212 ) ) ;
V_215 = (struct V_214 * ) ( ( char * ) V_219 +
sizeof( struct V_218 ) ) ;
V_83 = ( long ) V_213 -> V_83 ;
if ( ! V_83 ) {
for ( V_44 = 0 ; V_44 < V_213 -> V_188 ; V_44 ++ , V_215 ++ )
F_103 ( V_161 , V_215 -> V_216 ,
V_83 , V_219 -> V_180 ,
V_219 -> V_27 ) ;
} else {
for ( V_44 = 0 ; V_44 < V_213 -> V_188 ; V_44 ++ , V_215 ++ ) {
V_216 = V_215 -> V_216 ;
V_217 = V_215 -> V_217 ;
if ( V_83 ) {
if ( F_103 ( V_161 ,
V_216 , V_83 ,
V_219 -> V_180 ,
V_219 -> V_27 ) ) {
F_98 ( V_161 , V_216 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
F_98 ( V_161 , V_217 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
}
}
}
}
}
static void F_116 ( struct V_1 * V_161 ,
struct V_212 * V_213 )
{
int V_44 ;
long V_83 ;
struct V_220 * V_215 ;
struct V_218 * V_219 ;
V_219 = (struct V_218 * ) ( ( char * ) V_213 +
sizeof( struct V_212 ) ) ;
V_215 = (struct V_220 * ) ( ( char * ) V_219 +
sizeof( struct V_218 ) ) ;
V_83 = ( long ) V_213 -> V_83 ;
for ( V_44 = 0 ; V_44 < V_213 -> V_188 ; V_44 ++ , V_215 ++ ) {
F_110 ( V_161 , V_215 -> V_221 ,
V_215 -> V_222 ) ;
F_110 ( V_161 , V_215 -> V_223 ,
V_215 -> V_224 ) ;
if ( V_83 )
F_103 ( V_161 , V_215 -> V_223 , V_83 ,
V_219 -> V_180 , V_219 -> V_27 ) ;
}
}
static void F_117 ( struct V_1 * V_161 ,
struct V_212 * V_213 )
{
int V_44 ;
struct V_214 * V_215 ;
struct V_204 * V_225 ;
V_225 = (struct V_204 * ) ( ( char * ) V_213 +
sizeof( struct V_212 ) ) ;
V_215 = (struct V_214 * ) ( ( char * ) V_225 +
sizeof( struct V_204 ) ) ;
for ( V_44 = 0 ; V_44 < V_213 -> V_188 ; V_44 ++ , V_215 ++ ) {
F_111 ( V_161 , V_215 -> V_216 ,
V_215 -> V_217 , V_225 ) ;
if ( V_213 -> V_83 )
F_113 ( ( T_1 ) ( V_213 -> V_83 ) ) ;
}
}
static void F_118 ( struct V_212 * V_213 )
{
if ( V_213 -> V_83 )
F_119 ( ( T_1 ) ( ( long ) V_213 -> V_83 ) ) ;
}
static void F_120 ( struct V_1 * V_161 ,
struct V_212 * V_213 )
{
long V_83 ;
int V_226 , V_44 , V_61 , V_75 ;
struct V_220 * V_215 ;
struct V_218 * V_219 ;
unsigned long V_140 ;
V_219 = (struct V_218 * ) ( ( char * ) V_213 +
sizeof( struct V_212 ) ) ;
V_215 = (struct V_220 * ) ( ( char * ) V_219 +
sizeof( struct V_218 ) ) ;
V_83 = ( long ) V_213 -> V_83 ;
for ( V_44 = 0 ; V_44 < V_213 -> V_188 ; V_44 ++ , V_215 ++ ) {
F_110 ( V_161 , V_215 -> V_223 ,
V_215 -> V_224 ) ;
if ( V_83 ) {
if ( ! F_103 ( V_161 , V_215 -> V_223 , V_83 ,
V_219 -> V_180 , V_219 -> V_27 ) ) {
V_226 = V_161 -> V_4 -> V_183 . V_227 ;
V_140 = V_215 -> V_221 ;
V_61 = F_98 ( V_161 , V_140 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
V_161 -> V_4 -> V_183 . V_207 [ V_226 ++ ] = V_61 ;
if ( V_226 == V_228 )
V_161 -> V_4 -> V_183 . V_227 = 1 ;
}
}
}
}
static inline void F_121 ( struct V_1 * V_161 )
{
V_161 -> V_4 -> V_183 . V_229 = 1 ;
}
static void F_122 ( struct V_1 * V_161 )
{
V_161 -> V_4 -> V_183 . V_230 = 1 ;
if ( V_161 -> V_4 -> V_183 . V_184 == 0 )
F_43 ( & V_161 -> V_11 -> V_12 ,
L_52 ) ;
else
F_43 ( & V_161 -> V_11 -> V_12 ,
L_53 ) ;
}
static void F_123 ( struct V_1 * V_161 ,
char * V_192 )
{
int V_226 , V_231 ;
struct V_212 * V_213 ;
char * V_215 = V_192 ;
V_161 -> V_4 -> V_183 . V_229 = 0 ;
V_161 -> V_4 -> V_183 . V_230 = 0 ;
V_231 = V_161 -> V_4 -> V_183 . V_189 -> V_231 ;
V_226 = V_161 -> V_4 -> V_183 . V_185 ;
for (; ( ! V_161 -> V_4 -> V_183 . V_229 ) && ( V_226 < V_231 ) ; V_226 ++ ) {
V_213 = (struct V_212 * ) V_215 ;
switch ( V_213 -> V_232 ) {
case V_233 :
break;
case V_234 :
F_112 ( V_161 , V_213 ) ;
break;
case V_235 :
F_114 ( V_161 , V_213 ) ;
break;
case V_236 :
F_115 ( V_161 , V_213 ) ;
break;
case V_237 :
F_116 ( V_161 , V_213 ) ;
break;
case V_238 :
F_117 ( V_161 , V_213 ) ;
break;
case V_239 :
F_118 ( V_213 ) ;
break;
case V_240 :
F_121 ( V_161 ) ;
break;
case V_241 :
F_122 ( V_161 ) ;
break;
case V_242 :
F_120 ( V_161 , V_213 ) ;
break;
default:
F_43 ( & V_161 -> V_11 -> V_12 ,
L_54 ,
V_29 , V_213 -> V_232 , V_226 ) ;
break;
}
V_215 += V_213 -> V_129 ;
}
V_161 -> V_4 -> V_183 . V_185 = V_226 ;
}
static void F_69 ( struct V_1 * V_161 )
{
V_161 -> V_4 -> V_183 . V_185 = 0 ;
F_123 ( V_161 , V_161 -> V_4 -> V_183 . V_201 ) ;
if ( V_161 -> V_4 -> V_183 . V_229 != 1 )
F_43 ( & V_161 -> V_11 -> V_12 , L_50 , V_29 ) ;
}
static void F_124 ( struct V_1 * V_161 )
{
F_123 ( V_161 , V_161 -> V_4 -> V_183 . V_200 ) ;
if ( V_161 -> V_4 -> V_183 . V_230 != 1 )
F_43 ( & V_161 -> V_11 -> V_12 , L_50 , V_29 ) ;
}
static void F_125 ( struct V_1 * V_161 )
{
F_123 ( V_161 , V_161 -> V_4 -> V_183 . V_199 ) ;
if ( V_161 -> V_4 -> V_183 . V_229 != 1 )
F_43 ( & V_161 -> V_11 -> V_12 , L_50 , V_29 ) ;
}
static int F_126 ( struct V_1 * V_2 )
{
struct V_135 * V_136 = V_2 -> V_4 -> V_136 ;
int V_75 = - V_30 ;
if ( F_127 ( & V_136 -> V_138 , V_136 -> V_243 ,
& ( V_2 -> V_11 -> V_12 ) ) ) {
F_43 ( & V_2 -> V_11 -> V_12 ,
L_55 ) ;
F_128 ( V_2 , V_244 ,
V_245 ) ;
} else {
if ( F_95 ( V_2 ) )
return V_75 ;
F_128 ( V_2 , V_244 ,
V_246 ) ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_75 = - V_30 ;
F_69 ( V_2 ) ;
V_3 = F_2 ( V_2 -> V_4 , V_32 ) ;
if ( ! ( V_3 & V_33 ) )
F_70 ( V_2 ) ;
if ( V_3 & V_106 ) {
F_24 ( V_2 -> V_41 , L_17 ,
V_29 ) ;
F_33 ( V_2 , 1 ) ;
return V_75 ;
}
F_125 ( V_2 ) ;
if ( F_91 ( V_2 ) )
return V_75 ;
if ( V_95 ) {
if ( F_126 ( V_2 ) )
return V_75 ;
} else {
F_128 ( V_2 , V_244 ,
V_245 ) ;
}
F_124 ( V_2 ) ;
if ( F_59 ( V_2 ) )
return - V_30 ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 )
{
int V_75 ;
struct V_247 V_248 ;
struct V_80 * V_4 = V_2 -> V_4 ;
memset ( & V_248 , 0 , sizeof( struct V_247 ) ) ;
V_75 = F_130 ( V_2 , & V_248 , V_4 -> V_97 ) ;
if ( V_75 )
return - V_30 ;
V_4 -> V_249 = ( T_2 ) V_248 . V_250 ;
V_4 -> V_251 = V_248 . V_251 ;
V_4 -> V_252 = V_248 . V_252 ;
V_4 -> V_253 = V_248 . V_253 ;
V_4 -> V_254 = V_248 . V_254 ;
V_4 -> V_255 = V_248 . V_255 ;
V_4 -> V_256 = V_248 . V_256 ;
V_2 -> V_257 = V_4 -> V_252 ;
V_2 -> V_258 = V_4 -> V_253 ;
if ( F_78 ( V_259 , & V_2 -> V_43 ) )
return V_260 ;
if ( V_4 -> V_254 & V_261 )
return V_108 ;
return V_260 ;
}
int F_50 ( struct V_1 * V_2 )
{
struct V_80 * V_4 = V_2 -> V_4 ;
int V_71 ;
V_71 = F_129 ( V_2 ) ;
if ( V_71 == - V_30 )
return - V_30 ;
if ( V_71 == V_108 ) {
V_4 -> V_107 = V_108 ;
if ( F_131 ( V_2 ) )
return - V_30 ;
V_2 -> V_258 = V_262 ;
V_2 -> V_257 = V_263 ;
} else if ( V_71 == V_260 ) {
V_4 -> V_107 = V_264 ;
V_2 -> V_77 -> V_78 = V_265 ;
V_4 -> V_8 . V_100 = F_55 ;
V_2 -> V_258 = V_266 ;
V_2 -> V_257 = V_267 ;
} else {
return - V_30 ;
}
return 0 ;
}
static void F_132 ( struct V_1 * V_2 )
{
struct V_80 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_268 == V_269 ) {
V_2 -> V_270 = V_271 ;
V_2 -> V_272 = V_273 ;
V_2 -> V_274 = V_275 ;
V_2 -> V_276 = V_275 ;
} else if ( V_4 -> V_268 == V_277 ) {
V_2 -> V_270 = V_278 ;
V_2 -> V_274 = V_279 ;
V_2 -> V_276 = V_279 ;
V_2 -> V_272 = V_280 ;
}
V_2 -> V_281 = V_282 ;
V_2 -> V_283 = V_284 ;
}
static int V_265 ( struct V_1 * V_2 )
{
int V_75 = - V_30 ;
F_133 ( V_2 ) ;
if ( F_134 ( V_2 ) )
return V_75 ;
F_132 ( V_2 ) ;
V_2 -> V_4 -> V_285 = ! ! V_286 ;
V_2 -> V_104 |= V_287 ;
F_4 ( & V_2 -> V_11 -> V_12 , L_56 ,
V_2 -> V_4 -> V_288 ) ;
return 0 ;
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_289 V_232 ;
T_1 V_290 , V_291 ;
int V_27 ;
V_290 = F_2 ( V_2 -> V_4 , V_5 ) ;
V_291 = F_2 ( V_2 -> V_4 , V_18 ) ;
if ( F_136 ( V_2 , V_290 , V_291 ) ) {
V_27 = F_137 ( & V_232 , V_2 ,
V_292 ) ;
if ( V_27 )
return;
V_232 . V_293 . V_294 [ 1 ] = V_295 ;
V_27 = F_138 ( V_2 , & V_232 ) ;
if ( V_27 )
F_43 ( & V_2 -> V_11 -> V_12 ,
L_57 ) ;
F_139 ( & V_232 ) ;
}
}
static int F_140 ( struct V_1 * V_2 )
{
struct V_80 * V_4 = V_2 -> V_4 ;
struct V_296 * V_11 = V_2 -> V_11 ;
struct V_135 * V_136 ;
int V_75 = 0 ;
V_4 -> V_136 = F_107 ( sizeof( * V_136 ) , V_195 ) ;
if ( ! V_4 -> V_136 ) {
V_75 = - V_134 ;
} else {
V_136 = V_4 -> V_136 ;
switch ( V_11 -> V_297 ) {
case V_298 :
strncpy ( V_136 -> V_243 , V_299 ,
V_300 ) ;
break;
case V_301 :
strncpy ( V_136 -> V_243 , V_302 ,
V_300 ) ;
break;
default:
F_43 ( & V_11 -> V_12 , L_58 ,
V_29 ) ;
V_75 = - V_303 ;
break;
}
}
return V_75 ;
}
static void F_141 ( struct V_1 * V_2 )
{
T_2 V_304 = V_305 ;
T_2 V_306 = V_307 ;
V_2 -> V_257 = V_267 ;
V_2 -> V_258 = V_266 ;
if ( ! V_2 -> V_4 -> V_285 ) {
V_304 = V_308 ;
V_306 = V_308 ;
}
F_142 ( V_2 , V_306 ) ;
F_143 ( V_2 , V_304 ) ;
}
int F_144 ( struct V_1 * V_2 , int V_309 )
{
struct V_80 * V_4 = V_2 -> V_4 ;
int V_75 = 0 ;
V_2 -> V_310 = false ;
V_4 -> V_285 = ! ! V_286 ;
F_141 ( V_2 ) ;
V_75 = F_145 ( V_2 ) ;
if ( V_75 )
goto exit;
if ( F_90 ( V_2 ) ) {
V_75 = F_146 ( V_2 , V_309 ) ;
if ( V_75 )
goto V_311;
else
return V_75 ;
}
if ( F_147 ( V_2 ) ||
F_148 ( V_2 ) ) {
F_43 ( & V_2 -> V_11 -> V_12 , L_59 ) ;
V_75 = - V_312 ;
goto V_311;
}
V_75 = F_59 ( V_2 ) ;
if ( V_75 )
goto V_311;
V_75 = F_140 ( V_2 ) ;
if ( V_75 )
goto V_311;
V_75 = F_83 ( V_2 ) ;
if ( V_75 )
goto V_311;
V_75 = F_149 ( V_2 ) ;
if ( V_75 ) {
F_43 ( & V_2 -> V_11 -> V_12 , L_60 ) ;
goto V_313;
}
V_75 = F_150 ( V_2 ) ;
if ( V_75 )
goto V_314;
F_135 ( V_2 ) ;
F_151 ( & V_2 -> V_315 , V_316 ) ;
F_48 ( V_2 , 1 ) ;
V_75 = F_50 ( V_2 ) ;
if ( V_75 )
goto V_314;
V_75 = V_2 -> V_77 -> V_78 ( V_2 ) ;
if ( V_75 )
goto V_314;
F_76 ( & V_2 -> V_116 . V_115 ) ;
return 0 ;
V_314:
F_152 ( V_2 ) ;
V_313:
F_153 ( V_2 ) ;
V_311:
F_26 ( V_2 ) ;
F_154 ( V_4 -> V_76 ) ;
V_4 -> V_76 = NULL ;
exit:
return V_75 ;
}
void F_155 ( struct V_1 * V_2 )
{
struct V_80 * V_4 = V_2 -> V_4 ;
struct V_317 * V_8 = & V_4 -> V_8 ;
F_23 ( V_103 , & V_8 -> V_27 ) ;
F_88 ( & V_2 -> V_116 ) ;
if ( V_4 -> V_107 == V_108 )
F_65 ( V_2 , 1 ) ;
F_25 ( V_2 ) ;
F_48 ( V_2 , 0 ) ;
F_88 ( & V_2 -> V_315 ) ;
}
int F_156 ( struct V_1 * V_2 )
{
struct V_80 * V_4 = V_2 -> V_4 ;
struct V_317 * V_8 = & V_4 -> V_8 ;
int V_71 = 0 ;
T_1 V_62 ;
V_8 -> V_10 = V_56 ;
V_62 = F_38 ( V_2 ) ;
if ( V_4 -> V_97 == V_62 ) {
V_71 = F_40 ( V_2 ) ;
if ( V_71 < 0 )
return V_71 ;
F_13 ( V_2 , 0 ) ;
}
V_71 = V_8 -> V_100 ( V_2 ) ;
return V_71 ;
}
void F_157 ( struct V_1 * V_2 )
{
struct V_80 * V_4 = V_2 -> V_4 ;
struct V_317 * V_8 = & V_4 -> V_8 ;
T_1 V_62 ;
V_8 -> V_10 = V_57 ;
V_62 = F_38 ( V_2 ) ;
if ( V_4 -> V_97 == V_62 )
F_37 ( V_2 , 0 ) ;
F_79 ( V_2 , F_76 , 0 ) ;
}
