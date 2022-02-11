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
static int F_74 ( struct V_1 * V_2 )
{
T_4 V_112 = V_2 -> V_4 -> V_113 ;
struct V_114 V_115 ;
int V_71 = 0 ;
memset ( & V_115 , 0 , sizeof( V_115 ) ) ;
V_71 = F_75 ( & V_115 , V_2 ,
V_116 ) ;
if ( V_71 )
return V_71 ;
V_115 . V_117 . V_118 [ 1 ] = V_119 ;
V_115 . V_117 . V_118 [ 2 ] = V_120 |
V_121 |
F_76 ( V_112 ) ;
V_71 = F_77 ( V_2 , & V_115 ) ;
if ( V_71 )
F_78 ( V_2 -> V_41 ,
L_24 ,
V_112 ) ;
F_79 ( & V_115 ) ;
return V_71 ;
}
static int F_80 ( struct V_1 * V_2 ,
bool V_43 )
{
T_4 V_113 = V_2 -> V_4 -> V_113 ;
struct V_114 V_115 ;
int V_71 = 0 ;
memset ( & V_115 , 0 , sizeof( V_115 ) ) ;
V_71 = F_75 ( & V_115 , V_2 ,
V_122 ) ;
if ( V_71 )
return V_71 ;
V_115 . V_117 . V_118 [ 1 ] = V_43 ? V_123 :
V_124 ;
V_71 = F_77 ( V_2 , & V_115 ) ;
if ( V_71 )
F_78 ( V_2 -> V_41 ,
L_25 ,
V_43 ? L_26 : L_27 , V_113 ) ;
else
F_24 ( V_2 -> V_41 ,
L_28 ,
V_43 ? L_29 : L_30 , V_113 ) ;
F_79 ( & V_115 ) ;
return V_71 ;
}
static void F_81 ( struct V_1 * V_2 )
{
if ( V_2 -> V_125 . V_126 )
F_82 ( V_2 ) ;
#ifdef F_83
if ( V_2 -> V_104 & V_127 ) {
if ( F_74 ( V_2 ) )
return;
if ( F_80 ( V_2 , true ) )
return;
V_2 -> V_104 &= ~ V_127 ;
} else if ( V_2 -> V_104 & V_128 ) {
if ( F_80 ( V_2 , false ) )
return;
V_2 -> V_4 -> V_113 = 0 ;
V_2 -> V_104 &= ~ V_128 ;
}
#endif
}
void F_84 ( struct V_129 * V_130 )
{
struct V_1 * V_2 ;
T_1 V_43 ;
V_2 = F_85 ( V_130 , struct V_1 , V_131 . V_130 ) ;
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
F_81 ( V_2 ) ;
if ( F_86 ( V_81 , & V_2 -> V_4 -> V_8 . V_27 ) )
F_87 ( V_2 , F_84 ,
V_2 -> V_4 -> V_8 . V_83 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
T_1 V_132 , V_3 ;
if ( F_89 ( V_2 , V_133 ,
( T_2 * ) & V_132 , 1 ) ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_31 , V_29 ) ;
V_2 -> V_134 = V_96 ;
V_2 -> V_135 = V_39 ;
} else {
V_2 -> V_134 = V_132 & 0xFFFF ;
V_2 -> V_135 = ( ( V_132 >> 16 ) & 0xFFFF ) ;
}
V_2 -> V_4 -> V_8 . V_9 = V_94 ;
V_2 -> V_4 -> V_8 . V_10 = V_94 ;
V_2 -> V_4 -> V_8 . V_83 = V_84 ;
V_2 -> V_4 -> V_8 . V_85 = 0 ;
V_2 -> V_4 -> V_8 . V_86 = 0 ;
V_2 -> V_4 -> V_8 . V_13 = ( char * * ) V_136 ;
F_23 ( V_42 , & V_2 -> V_43 ) ;
F_54 ( V_81 , & V_2 -> V_4 -> V_8 . V_27 ) ;
if ( ! V_137 ) {
V_3 = F_2 ( V_2 -> V_4 , V_32 ) ;
V_3 = V_3 | V_106 ;
F_7 ( V_2 -> V_4 , V_32 , V_3 ) ;
}
}
static int
F_90 ( struct V_1 * V_2 )
{
T_1 V_43 , V_3 ;
if ( F_6 ( V_2 ) )
return - V_30 ;
F_7 ( V_2 -> V_4 , V_138 , 0 ) ;
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
if ( V_137 ) {
V_3 = F_2 ( V_2 -> V_4 , V_32 ) ;
V_3 = V_3 & ~ V_106 ;
F_7 ( V_2 -> V_4 , V_32 , V_3 ) ;
}
F_8 ( V_2 ) ;
return 0 ;
}
int F_91 ( struct V_1 * V_2 )
{
int V_71 = - V_30 ;
F_88 ( V_2 ) ;
if ( F_92 ( V_2 ) )
return V_71 ;
if ( ! F_1 ( V_2 ) ) {
if ( F_90 ( V_2 ) )
return - V_30 ;
} else {
if ( F_12 ( V_2 ) )
return - V_30 ;
}
F_5 ( V_2 , 0 , 1 ) ;
return 0 ;
}
void F_93 ( struct V_1 * V_2 )
{
int V_47 ;
T_1 V_3 ;
while ( F_18 ( V_42 , & V_2 -> V_43 ) )
F_94 ( 10000 , 11000 ) ;
V_47 = F_2 ( V_2 -> V_4 , V_139 ) ;
V_47 = V_47 & 0xFF ;
if ( V_47 == V_2 -> V_19 ) {
F_43 ( & V_2 -> V_11 -> V_12 ,
L_32 , V_29 , V_47 ) ;
F_95 ( 20 ) ;
V_47 = F_2 ( V_2 -> V_4 , V_139 ) ;
V_47 = V_47 & 0xFF ;
}
V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
V_3 = V_3 & ~ ( 1 << V_2 -> V_19 ) ;
F_7 ( V_2 -> V_4 , V_5 , V_3 ) ;
F_23 ( V_81 , & V_2 -> V_4 -> V_8 . V_27 ) ;
F_23 ( V_42 , & V_2 -> V_43 ) ;
F_96 ( & V_2 -> V_131 ) ;
}
void F_97 ( struct V_1 * V_2 , T_1 V_140 )
{
T_1 V_3 ;
if ( F_98 ( V_2 ) )
return;
if ( F_6 ( V_2 ) ) {
F_43 ( & V_2 -> V_11 -> V_12 ,
L_33 , V_29 ) ;
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
if ( V_140 == V_141 ) {
V_3 = F_2 ( V_2 -> V_4 , V_32 ) ;
V_3 = V_3 | V_33 ;
F_7 ( V_2 -> V_4 , V_32 , V_3 ) ;
} else if ( V_140 == V_142 ) {
V_2 -> V_4 -> V_8 . V_86 = 1 ;
}
F_8 ( V_2 ) ;
return;
}
static int F_99 ( struct V_1 * V_2 )
{
T_2 * V_143 ;
T_1 V_49 , V_144 ;
T_3 V_145 ;
int V_71 = - V_30 ;
V_49 = V_146 ;
V_145 = F_2 ( V_2 -> V_4 , V_147 ) ;
V_144 = F_2 ( V_2 -> V_4 , V_148 ) ;
if ( V_144 & 0xF )
V_144 = ( V_144 + 16 ) & ~ 0xF ;
V_143 = F_100 ( V_144 ) ;
if ( V_143 == NULL )
return - V_149 ;
V_71 = F_101 ( V_2 , V_49 , V_143 ,
V_144 / sizeof( T_1 ) ) ;
if ( V_71 ) {
F_102 ( V_143 ) ;
return V_71 ;
}
V_71 = F_103 ( V_2 , V_145 , ( T_1 * ) V_143 ,
V_144 / 16 ) ;
if ( V_71 ) {
F_102 ( V_143 ) ;
return V_71 ;
}
F_102 ( V_143 ) ;
return V_71 ;
}
static int F_104 ( struct V_1 * V_2 )
{
struct V_150 * V_151 = V_2 -> V_4 -> V_151 ;
const struct V_152 * V_153 = V_151 -> V_153 ;
T_1 V_145 , * V_143 , * V_101 ;
int V_44 , V_71 = - V_30 ;
T_5 * V_154 ;
T_2 V_155 [ 16 ] ;
T_6 V_144 ;
T_3 V_156 ;
V_101 = F_105 ( V_153 -> V_144 , V_157 ) ;
if ( ! V_101 ) {
F_106 ( V_153 ) ;
V_151 -> V_153 = NULL ;
return - V_149 ;
}
V_154 = ( T_5 * ) V_153 -> V_155 ;
for ( V_44 = 0 ; V_44 < V_153 -> V_144 / sizeof( T_1 ) ; V_44 ++ )
V_101 [ V_44 ] = F_107 ( V_154 [ V_44 ] ) ;
V_145 = F_2 ( V_2 -> V_4 , V_158 ) ;
V_144 = ( V_153 -> V_144 & ~ 0xF ) ;
V_143 = V_101 ;
V_156 = ( T_3 ) V_145 ;
V_71 = F_103 ( V_2 , V_156 ,
V_143 , V_144 / 16 ) ;
if ( V_71 ) {
F_43 ( & V_2 -> V_11 -> V_12 , L_34 ) ;
goto exit;
}
if ( V_153 -> V_144 & 0xF ) {
V_156 = V_145 + V_144 ;
for ( V_44 = 0 ; V_44 < ( V_153 -> V_144 & 0xF ) ; V_44 ++ )
V_155 [ V_44 ] = V_101 [ V_144 + V_44 ] ;
for (; V_44 < 16 ; V_44 ++ )
V_155 [ V_44 ] = 0 ;
V_71 = F_103 ( V_2 , V_156 ,
( T_1 * ) V_155 , 1 ) ;
if ( V_71 ) {
F_43 ( & V_2 -> V_11 -> V_12 ,
L_34 ) ;
goto exit;
}
}
exit:
F_106 ( V_153 ) ;
V_151 -> V_153 = NULL ;
F_108 ( V_101 ) ;
return V_71 ;
}
static void F_109 ( struct V_1 * V_2 )
{
int V_44 , V_61 ;
T_1 V_3 = 0 , V_159 = 0 , V_58 = 0 ;
int V_75 = 0 ;
V_3 = F_110 ( V_2 , V_160 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
F_4 ( & V_2 -> V_11 -> V_12 , L_35 , V_3 ) ;
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
if ( V_61 == 0 ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_36 ) ;
V_58 = V_161 ;
} else if ( V_61 == 1 ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_37 ) ;
V_58 = V_162 ;
}
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ ) {
V_3 = F_110 ( V_2 , V_58 + ( V_44 * 0x4 ) , & V_75 ) ;
if ( V_75 == - V_30 )
return;
F_4 ( & V_2 -> V_11 -> V_12 , L_38 , V_3 ) ;
}
F_4 ( & V_2 -> V_11 -> V_12 , L_39 ) ;
}
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
if ( V_61 == 0 ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_40 ) ;
V_58 = V_163 ;
} else if ( V_61 == 1 ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_41 ) ;
V_58 = V_164 ;
}
for ( V_44 = 0 ; V_44 < 4 ; V_44 ++ ) {
V_3 = F_110 ( V_2 , V_58 + ( V_44 * 0x4 ) , & V_75 ) ;
if ( V_75 == - V_30 )
return;
F_4 ( & V_2 -> V_11 -> V_12 , L_38 , V_3 ) ;
}
F_4 ( & V_2 -> V_11 -> V_12 , L_39 ) ;
}
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
if ( V_61 == 0 ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_42 ) ;
V_58 = V_165 ;
} else if ( V_61 == 1 ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
L_43 ) ;
V_58 = V_166 ;
}
for ( V_44 = 7 ; V_44 >= 0 ; V_44 -- ) {
V_3 = F_110 ( V_2 , V_58 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
V_3 &= ~ ( 0x7 << 29 ) ;
F_111 ( V_2 , V_58 , ( V_3 | ( V_44 << 29 ) ) ) ;
V_3 = F_110 ( V_2 , V_58 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
F_4 ( & V_2 -> V_11 -> V_12 , L_38 , V_3 ) ;
}
F_4 ( & V_2 -> V_11 -> V_12 , L_39 ) ;
}
V_3 = F_110 ( V_2 , V_167 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
V_159 = F_110 ( V_2 , V_168 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
F_4 ( & V_2 -> V_11 -> V_12 ,
L_44 ,
V_3 , V_159 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
T_1 V_58 = 0 , V_44 , V_61 ;
if ( F_6 ( V_2 ) ) {
F_43 ( & V_2 -> V_11 -> V_12 ,
L_45 , V_29 ) ;
return;
}
F_109 ( V_2 ) ;
F_111 ( V_2 , V_160 , 0x0 ) ;
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
if ( V_61 == 0 )
V_58 = V_161 ;
else if ( V_61 == 1 )
V_58 = V_162 ;
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ )
F_111 ( V_2 , V_58 + ( V_44 * 0x4 ) , 0x0 ) ;
}
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
if ( V_61 == 0 )
V_58 = V_163 ;
else if ( V_61 == 1 )
V_58 = V_164 ;
for ( V_44 = 0 ; V_44 < 4 ; V_44 ++ )
F_111 ( V_2 , V_58 + ( V_44 * 0x4 ) , 0x03FF03FF ) ;
}
F_111 ( V_2 , V_167 , 0 ) ;
F_111 ( V_2 , V_168 , 0 ) ;
F_4 ( & V_2 -> V_11 -> V_12 ,
L_46 ) ;
F_8 ( V_2 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
F_111 ( V_2 , V_169 , 0 ) ;
F_111 ( V_2 , V_170 , 0 ) ;
F_111 ( V_2 , V_171 , 0 ) ;
F_111 ( V_2 , V_172 , 0 ) ;
F_111 ( V_2 , V_173 , 0 ) ;
F_111 ( V_2 , V_174 , 0 ) ;
F_111 ( V_2 , V_175 , 0 ) ;
F_111 ( V_2 , V_176 , 0 ) ;
F_111 ( V_2 , V_177 , 1 ) ;
}
static int F_63 ( struct V_1 * V_178 )
{
T_1 V_179 , V_180 ;
int V_181 , V_71 = - V_30 , V_75 = 0 ;
V_181 = V_182 ;
V_178 -> V_179 = F_42 ( V_178 ,
V_183 ) ;
do {
F_95 ( V_184 ) ;
V_179 = F_42 ( V_178 ,
V_183 ) ;
if ( V_179 != V_178 -> V_179 ) {
V_71 = V_185 ;
break;
}
} while ( -- V_181 );
if ( V_71 ) {
F_43 ( & V_178 -> V_11 -> V_12 , L_47 ) ;
F_113 ( V_178 ) ;
F_112 ( V_178 ) ;
V_180 = F_42 ( V_178 ,
V_72 ) ;
F_4 ( & V_178 -> V_11 -> V_12 , L_48
L_49
L_50
L_51
L_52 , V_180 ,
F_42 ( V_178 , V_186 ) ,
F_110 ( V_178 , V_187 , & V_75 ) ,
F_110 ( V_178 , V_188 , & V_75 ) ,
F_110 ( V_178 , V_189 , & V_75 ) ,
F_110 ( V_178 , V_190 , & V_75 ) ,
F_110 ( V_178 , V_191 , & V_75 ) ) ;
if ( F_44 ( V_180 ) == 0x67 )
F_43 ( & V_178 -> V_11 -> V_12 ,
L_53 ) ;
}
return V_71 ;
}
static int F_114 ( struct V_1 * V_178 )
{
int V_181 = V_192 ;
T_1 V_3 ;
do {
V_3 = F_42 ( V_178 , V_193 ) ;
if ( V_3 == V_194 )
return 0 ;
F_95 ( V_195 ) ;
} while ( -- V_181 );
F_43 ( & V_178 -> V_11 -> V_12 , L_54 , V_29 , V_3 ) ;
return - V_30 ;
}
static int F_59 ( struct V_1 * V_178 )
{
int V_75 ;
V_75 = F_114 ( V_178 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_63 ( V_178 ) ;
if ( V_75 )
return V_75 ;
return V_75 ;
}
static int F_115 ( struct V_1 * V_178 , T_1 V_156 ,
int V_196 , T_1 V_197 , T_1 V_27 )
{
int V_198 , V_75 = 0 ;
T_1 V_199 ;
T_2 V_181 ;
V_199 = F_110 ( V_178 , V_156 , & V_75 ) ;
if ( V_75 == - V_30 )
return V_75 ;
V_181 = V_196 / 10 ;
do {
if ( ( V_199 & V_197 ) != V_27 ) {
V_198 = 1 ;
F_95 ( V_196 / 10 ) ;
V_199 = F_110 ( V_178 , V_156 , & V_75 ) ;
if ( V_75 == - V_30 )
return V_75 ;
} else {
V_198 = 0 ;
break;
}
} while ( V_181 -- );
if ( V_198 ) {
V_178 -> V_4 -> V_200 . V_201 ++ ;
F_43 ( & V_178 -> V_11 -> V_12 ,
L_55 ,
V_29 , V_178 -> V_4 -> V_200 . V_202 ) ;
F_43 ( & V_178 -> V_11 -> V_12 ,
L_56 ,
V_199 , V_197 , V_27 ) ;
}
return V_198 ;
}
static int F_116 ( struct V_1 * V_178 )
{
T_1 V_203 = 0 ;
T_4 * V_204 = ( T_4 * ) V_178 -> V_4 -> V_200 . V_204 ;
int V_205 = V_178 -> V_4 -> V_200 . V_206 -> V_144 / sizeof( T_4 ) ;
while ( V_205 -- > 0 )
V_203 += * V_204 ++ ;
while ( V_203 >> 16 )
V_203 = ( V_203 & 0xFFFF ) + ( V_203 >> 16 ) ;
if ( ~ V_203 ) {
return 0 ;
} else {
F_43 ( & V_178 -> V_11 -> V_12 , L_57 , V_29 ) ;
return - 1 ;
}
}
static int F_92 ( struct V_1 * V_178 )
{
struct V_80 * V_4 = V_178 -> V_4 ;
T_1 V_156 , V_205 , V_207 , V_208 ;
T_2 * V_209 ;
if ( V_4 -> V_200 . V_204 != NULL ) {
V_207 = V_178 -> V_210 ;
V_208 = F_117 ( V_178 ) ;
if ( V_208 > V_207 )
F_108 ( V_4 -> V_200 . V_204 ) ;
else
return 0 ;
}
V_4 -> V_200 . V_201 = 0 ;
V_4 -> V_200 . V_204 = F_105 ( V_211 , V_157 ) ;
if ( V_178 -> V_4 -> V_200 . V_204 == NULL )
return - V_149 ;
V_209 = V_178 -> V_4 -> V_200 . V_204 ;
V_156 = V_212 ;
V_205 = sizeof( struct V_213 ) / sizeof( T_1 ) ;
if ( F_89 ( V_178 , V_156 , V_209 , V_205 ) ) {
F_43 ( & V_178 -> V_11 -> V_12 , L_58 , V_29 ) ;
return - V_30 ;
}
V_4 -> V_200 . V_206 = (struct V_213 * ) V_4 -> V_200 . V_204 ;
V_156 = V_212 + V_4 -> V_200 . V_206 -> V_214 ;
V_209 = V_4 -> V_200 . V_204 + V_4 -> V_200 . V_206 -> V_214 ;
V_205 = ( V_4 -> V_200 . V_206 -> V_144 - V_4 -> V_200 . V_206 -> V_214 ) / sizeof( T_1 ) ;
if ( F_89 ( V_178 , V_156 , V_209 , V_205 ) ) {
F_43 ( & V_178 -> V_11 -> V_12 , L_58 , V_29 ) ;
return - V_30 ;
}
if ( F_116 ( V_178 ) )
return - V_30 ;
V_4 -> V_200 . V_215 = V_4 -> V_200 . V_204 + V_4 -> V_200 . V_206 -> V_215 ;
V_4 -> V_200 . V_216 = V_4 -> V_200 . V_204 +
V_4 -> V_200 . V_206 -> V_216 ;
V_4 -> V_200 . V_217 = V_4 -> V_200 . V_204 + V_4 -> V_200 . V_206 -> V_214 ;
return 0 ;
}
static void F_118 ( struct V_1 * V_178 ,
T_1 V_218 , T_1 V_219 )
{
int V_75 = 0 ;
T_1 V_199 ;
V_199 = F_110 ( V_178 , V_218 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
F_119 ( V_178 , V_219 , V_199 ) ;
}
static void F_120 ( struct V_1 * V_178 ,
T_1 V_218 , T_1 V_219 ,
struct V_220 * V_221 )
{
int V_75 = 0 ;
T_1 V_199 ;
if ( V_221 -> V_222 ) {
V_199 = V_178 -> V_4 -> V_200 . V_223 [ V_221 -> V_222 ] ;
} else {
V_199 = F_110 ( V_178 , V_218 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
}
V_199 &= V_221 -> V_197 ;
V_199 <<= V_221 -> V_224 ;
V_199 >>= V_221 -> V_225 ;
V_199 |= V_221 -> V_226 ;
V_199 ^= V_221 -> V_227 ;
F_119 ( V_178 , V_219 , V_199 ) ;
}
static void F_121 ( struct V_1 * V_178 ,
struct V_228 * V_229 )
{
int V_44 ;
struct V_230 * V_231 ;
V_231 = (struct V_230 * ) ( ( char * ) V_229 +
sizeof( struct V_228 ) ) ;
for ( V_44 = 0 ; V_44 < V_229 -> V_205 ; V_44 ++ , V_231 ++ ) {
F_119 ( V_178 , V_231 -> V_232 ,
V_231 -> V_233 ) ;
if ( V_229 -> V_83 )
F_122 ( ( T_1 ) ( V_229 -> V_83 ) ) ;
}
}
static void F_123 ( struct V_1 * V_178 ,
struct V_228 * V_229 )
{
int V_44 ;
struct V_230 * V_231 ;
V_231 = (struct V_230 * ) ( ( char * ) V_229 +
sizeof( struct V_228 ) ) ;
for ( V_44 = 0 ; V_44 < V_229 -> V_205 ; V_44 ++ , V_231 ++ ) {
F_118 ( V_178 , V_231 -> V_232 ,
V_231 -> V_233 ) ;
if ( V_229 -> V_83 )
F_122 ( ( T_1 ) ( V_229 -> V_83 ) ) ;
}
}
static void F_124 ( struct V_1 * V_178 ,
struct V_228 * V_229 )
{
long V_83 ;
struct V_230 * V_231 ;
struct V_234 * V_235 ;
int V_44 , V_75 = 0 ;
unsigned long V_232 , V_233 ;
V_235 = (struct V_234 * ) ( ( char * ) V_229 +
sizeof( struct V_228 ) ) ;
V_231 = (struct V_230 * ) ( ( char * ) V_235 +
sizeof( struct V_234 ) ) ;
V_83 = ( long ) V_229 -> V_83 ;
if ( ! V_83 ) {
for ( V_44 = 0 ; V_44 < V_229 -> V_205 ; V_44 ++ , V_231 ++ )
F_115 ( V_178 , V_231 -> V_232 ,
V_83 , V_235 -> V_197 ,
V_235 -> V_27 ) ;
} else {
for ( V_44 = 0 ; V_44 < V_229 -> V_205 ; V_44 ++ , V_231 ++ ) {
V_232 = V_231 -> V_232 ;
V_233 = V_231 -> V_233 ;
if ( V_83 ) {
if ( F_115 ( V_178 ,
V_232 , V_83 ,
V_235 -> V_197 ,
V_235 -> V_27 ) ) {
F_110 ( V_178 , V_232 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
F_110 ( V_178 , V_233 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
}
}
}
}
}
static void F_125 ( struct V_1 * V_178 ,
struct V_228 * V_229 )
{
int V_44 ;
long V_83 ;
struct V_236 * V_231 ;
struct V_234 * V_235 ;
V_235 = (struct V_234 * ) ( ( char * ) V_229 +
sizeof( struct V_228 ) ) ;
V_231 = (struct V_236 * ) ( ( char * ) V_235 +
sizeof( struct V_234 ) ) ;
V_83 = ( long ) V_229 -> V_83 ;
for ( V_44 = 0 ; V_44 < V_229 -> V_205 ; V_44 ++ , V_231 ++ ) {
F_119 ( V_178 , V_231 -> V_237 ,
V_231 -> V_238 ) ;
F_119 ( V_178 , V_231 -> V_239 ,
V_231 -> V_240 ) ;
if ( V_83 )
F_115 ( V_178 , V_231 -> V_239 , V_83 ,
V_235 -> V_197 , V_235 -> V_27 ) ;
}
}
static void F_126 ( struct V_1 * V_178 ,
struct V_228 * V_229 )
{
int V_44 ;
struct V_230 * V_231 ;
struct V_220 * V_241 ;
V_241 = (struct V_220 * ) ( ( char * ) V_229 +
sizeof( struct V_228 ) ) ;
V_231 = (struct V_230 * ) ( ( char * ) V_241 +
sizeof( struct V_220 ) ) ;
for ( V_44 = 0 ; V_44 < V_229 -> V_205 ; V_44 ++ , V_231 ++ ) {
F_120 ( V_178 , V_231 -> V_232 ,
V_231 -> V_233 , V_241 ) ;
if ( V_229 -> V_83 )
F_122 ( ( T_1 ) ( V_229 -> V_83 ) ) ;
}
}
static void F_127 ( struct V_228 * V_229 )
{
if ( V_229 -> V_83 )
F_128 ( ( T_1 ) ( ( long ) V_229 -> V_83 ) ) ;
}
static void F_129 ( struct V_1 * V_178 ,
struct V_228 * V_229 )
{
long V_83 ;
int V_242 , V_44 , V_61 , V_75 ;
struct V_236 * V_231 ;
struct V_234 * V_235 ;
unsigned long V_156 ;
V_235 = (struct V_234 * ) ( ( char * ) V_229 +
sizeof( struct V_228 ) ) ;
V_231 = (struct V_236 * ) ( ( char * ) V_235 +
sizeof( struct V_234 ) ) ;
V_83 = ( long ) V_229 -> V_83 ;
for ( V_44 = 0 ; V_44 < V_229 -> V_205 ; V_44 ++ , V_231 ++ ) {
F_119 ( V_178 , V_231 -> V_239 ,
V_231 -> V_240 ) ;
if ( V_83 ) {
if ( ! F_115 ( V_178 , V_231 -> V_239 , V_83 ,
V_235 -> V_197 , V_235 -> V_27 ) ) {
V_242 = V_178 -> V_4 -> V_200 . V_243 ;
V_156 = V_231 -> V_237 ;
V_61 = F_110 ( V_178 , V_156 , & V_75 ) ;
if ( V_75 == - V_30 )
return;
V_178 -> V_4 -> V_200 . V_223 [ V_242 ++ ] = V_61 ;
if ( V_242 == V_244 )
V_178 -> V_4 -> V_200 . V_243 = 1 ;
}
}
}
}
static inline void F_130 ( struct V_1 * V_178 )
{
V_178 -> V_4 -> V_200 . V_245 = 1 ;
}
static void F_131 ( struct V_1 * V_178 )
{
V_178 -> V_4 -> V_200 . V_246 = 1 ;
if ( V_178 -> V_4 -> V_200 . V_201 == 0 )
F_43 ( & V_178 -> V_11 -> V_12 ,
L_59 ) ;
else
F_43 ( & V_178 -> V_11 -> V_12 ,
L_60 ) ;
}
static void F_132 ( struct V_1 * V_178 ,
char * V_209 )
{
int V_242 , V_247 ;
struct V_228 * V_229 ;
char * V_231 = V_209 ;
V_178 -> V_4 -> V_200 . V_245 = 0 ;
V_178 -> V_4 -> V_200 . V_246 = 0 ;
V_247 = V_178 -> V_4 -> V_200 . V_206 -> V_247 ;
V_242 = V_178 -> V_4 -> V_200 . V_202 ;
for (; ( ! V_178 -> V_4 -> V_200 . V_245 ) && ( V_242 < V_247 ) ; V_242 ++ ) {
V_229 = (struct V_228 * ) V_231 ;
switch ( V_229 -> V_115 ) {
case V_248 :
break;
case V_249 :
F_121 ( V_178 , V_229 ) ;
break;
case V_250 :
F_123 ( V_178 , V_229 ) ;
break;
case V_251 :
F_124 ( V_178 , V_229 ) ;
break;
case V_252 :
F_125 ( V_178 , V_229 ) ;
break;
case V_253 :
F_126 ( V_178 , V_229 ) ;
break;
case V_254 :
F_127 ( V_229 ) ;
break;
case V_255 :
F_130 ( V_178 ) ;
break;
case V_256 :
F_131 ( V_178 ) ;
break;
case V_257 :
F_129 ( V_178 , V_229 ) ;
break;
default:
F_43 ( & V_178 -> V_11 -> V_12 ,
L_61 ,
V_29 , V_229 -> V_115 , V_242 ) ;
break;
}
V_231 += V_229 -> V_144 ;
}
V_178 -> V_4 -> V_200 . V_202 = V_242 ;
}
static void F_69 ( struct V_1 * V_178 )
{
V_178 -> V_4 -> V_200 . V_202 = 0 ;
F_132 ( V_178 , V_178 -> V_4 -> V_200 . V_217 ) ;
if ( V_178 -> V_4 -> V_200 . V_245 != 1 )
F_43 ( & V_178 -> V_11 -> V_12 , L_57 , V_29 ) ;
}
static void F_133 ( struct V_1 * V_178 )
{
F_132 ( V_178 , V_178 -> V_4 -> V_200 . V_216 ) ;
if ( V_178 -> V_4 -> V_200 . V_246 != 1 )
F_43 ( & V_178 -> V_11 -> V_12 , L_57 , V_29 ) ;
}
static void F_134 ( struct V_1 * V_178 )
{
F_132 ( V_178 , V_178 -> V_4 -> V_200 . V_215 ) ;
if ( V_178 -> V_4 -> V_200 . V_245 != 1 )
F_43 ( & V_178 -> V_11 -> V_12 , L_57 , V_29 ) ;
}
static int F_135 ( struct V_1 * V_2 )
{
struct V_150 * V_151 = V_2 -> V_4 -> V_151 ;
struct V_258 * V_12 = & V_2 -> V_11 -> V_12 ;
int V_36 , V_205 , V_71 = 0 ;
T_1 V_259 ;
switch ( V_2 -> V_4 -> V_260 ) {
case V_261 :
V_36 = V_262 + 2000 ;
break;
case V_263 :
V_36 = V_264 + 2000 ;
break;
case V_265 :
V_36 = V_266 + 2000 ;
break;
default:
return - V_267 ;
}
strncpy ( V_151 -> V_268 , V_269 ,
V_270 ) ;
V_71 = F_136 ( & V_151 -> V_153 , V_151 -> V_268 , V_12 ) ;
if ( V_71 ) {
F_43 ( V_12 , L_62 ) ;
return 0 ;
}
V_71 = F_104 ( V_2 ) ;
if ( V_71 )
return V_71 ;
F_137 ( V_2 , V_271 , 0 ) ;
F_137 ( V_2 , V_272 ,
V_2 -> V_4 -> V_260 ) ;
F_138 ( V_2 , V_273 ,
V_274 ) ;
F_133 ( V_2 ) ;
V_205 = 0 ;
do {
F_95 ( 100 ) ;
V_205 += 100 ;
V_259 = F_139 ( V_2 , V_271 ) ;
if ( V_259 == V_275 )
break;
} while ( V_36 > V_205 );
if ( V_36 <= V_205 ) {
F_43 ( V_12 , L_63 , V_259 ) ;
return - V_30 ;
}
switch ( V_259 ) {
case V_275 :
F_4 ( V_12 , L_64 , V_259 ) ;
break;
case V_276 :
F_43 ( V_12 , L_65 ,
V_259 ) ;
V_71 = - V_30 ;
break;
case V_277 :
F_43 ( V_12 , L_66 ,
V_259 ) ;
V_71 = - V_30 ;
break;
case V_278 :
F_43 ( V_12 , L_67 ,
V_259 ) ;
V_71 = - V_30 ;
break;
case V_279 :
F_43 ( V_12 , L_68 ,
V_259 ) ;
V_71 = - V_30 ;
break;
default:
F_43 ( V_12 , L_69 ,
V_259 ) ;
V_71 = - V_30 ;
break;
}
return V_71 ;
}
static int F_140 ( struct V_1 * V_2 )
{
struct V_150 * V_151 = V_2 -> V_4 -> V_151 ;
int V_75 = - V_30 ;
if ( F_136 ( & V_151 -> V_153 , V_151 -> V_268 ,
& ( V_2 -> V_11 -> V_12 ) ) ) {
F_43 ( & V_2 -> V_11 -> V_12 ,
L_70 ) ;
F_138 ( V_2 , V_273 ,
V_280 ) ;
} else {
if ( F_104 ( V_2 ) )
return V_75 ;
F_138 ( V_2 , V_273 ,
V_274 ) ;
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
F_134 ( V_2 ) ;
if ( F_99 ( V_2 ) )
return V_75 ;
if ( V_2 -> V_4 -> V_281 ) {
V_75 = F_135 ( V_2 ) ;
if ( V_75 )
return V_75 ;
V_2 -> V_4 -> V_281 = false ;
F_69 ( V_2 ) ;
F_134 ( V_2 ) ;
V_75 = F_99 ( V_2 ) ;
if ( V_75 )
return V_75 ;
}
if ( V_95 == 1 ) {
if ( F_140 ( V_2 ) )
return V_75 ;
} else {
F_138 ( V_2 , V_273 ,
V_280 ) ;
}
F_133 ( V_2 ) ;
if ( F_59 ( V_2 ) )
return - V_30 ;
return 0 ;
}
static int F_141 ( struct V_1 * V_2 )
{
int V_75 ;
struct V_282 V_283 ;
struct V_80 * V_4 = V_2 -> V_4 ;
memset ( & V_283 , 0 , sizeof( struct V_282 ) ) ;
V_75 = F_142 ( V_2 , & V_283 , V_4 -> V_97 ) ;
if ( V_75 )
return - V_30 ;
V_4 -> V_284 = ( T_2 ) V_283 . V_285 ;
V_4 -> V_286 = V_283 . V_286 ;
V_4 -> V_287 = V_283 . V_287 ;
V_4 -> V_288 = V_283 . V_288 ;
V_4 -> V_289 = V_283 . V_289 ;
V_4 -> V_290 = V_283 . V_290 ;
V_4 -> V_291 = V_283 . V_291 ;
if ( F_86 ( V_292 , & V_2 -> V_43 ) )
return V_293 ;
if ( V_4 -> V_289 & V_294 )
return V_108 ;
return V_293 ;
}
int F_50 ( struct V_1 * V_2 )
{
struct V_80 * V_4 = V_2 -> V_4 ;
T_4 V_295 , V_296 ;
int V_71 ;
V_71 = F_141 ( V_2 ) ;
if ( V_71 == - V_30 )
return - V_30 ;
if ( V_71 == V_108 ) {
V_4 -> V_107 = V_108 ;
if ( F_143 ( V_2 ) )
return - V_30 ;
V_295 = V_297 ;
V_296 = V_298 ;
} else if ( V_71 == V_293 ) {
V_4 -> V_107 = V_299 ;
V_2 -> V_77 -> V_78 = V_300 ;
V_4 -> V_8 . V_100 = F_55 ;
V_295 = V_301 ;
V_296 = V_302 ;
} else {
F_43 ( & V_2 -> V_11 -> V_12 , L_71 ,
V_29 , V_71 ) ;
return - V_30 ;
}
V_2 -> V_295 = F_144 ( V_4 -> V_288 , V_295 ) ;
V_2 -> V_296 = F_144 ( V_4 -> V_287 , V_296 ) ;
return 0 ;
}
static void F_145 ( struct V_1 * V_2 )
{
struct V_80 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_303 == V_304 ) {
V_2 -> V_305 = V_306 ;
V_2 -> V_307 = V_308 ;
V_2 -> V_309 = V_310 ;
V_2 -> V_311 = V_310 ;
} else if ( V_4 -> V_303 == V_312 ) {
V_2 -> V_305 = V_313 ;
V_2 -> V_309 = V_314 ;
V_2 -> V_311 = V_314 ;
V_2 -> V_307 = V_315 ;
}
V_2 -> V_316 = V_317 ;
V_2 -> V_318 = V_319 ;
}
static int V_300 ( struct V_1 * V_2 )
{
int V_75 = - V_30 ;
F_146 ( V_2 ) ;
if ( F_147 ( V_2 ) )
return V_75 ;
F_145 ( V_2 ) ;
V_2 -> V_4 -> V_320 = ! ! V_321 ;
V_2 -> V_104 |= V_322 ;
F_4 ( & V_2 -> V_11 -> V_12 , L_72 ,
V_2 -> V_4 -> V_323 ) ;
return 0 ;
}
static void F_148 ( struct V_1 * V_2 )
{
struct V_114 V_115 ;
T_1 V_324 , V_325 ;
int V_27 ;
V_324 = F_2 ( V_2 -> V_4 , V_5 ) ;
V_325 = F_2 ( V_2 -> V_4 , V_18 ) ;
if ( F_149 ( V_2 , V_324 , V_325 ) ) {
V_27 = F_75 ( & V_115 , V_2 ,
V_326 ) ;
if ( V_27 )
return;
V_115 . V_117 . V_118 [ 1 ] = V_327 ;
V_27 = F_77 ( V_2 , & V_115 ) ;
if ( V_27 )
F_43 ( & V_2 -> V_11 -> V_12 ,
L_73 ) ;
F_79 ( & V_115 ) ;
}
}
static int F_150 ( struct V_1 * V_2 )
{
struct V_80 * V_4 = V_2 -> V_4 ;
struct V_328 * V_11 = V_2 -> V_11 ;
struct V_150 * V_151 ;
int V_75 = 0 ;
V_4 -> V_151 = F_105 ( sizeof( * V_151 ) , V_157 ) ;
if ( ! V_4 -> V_151 ) {
V_75 = - V_149 ;
} else {
V_151 = V_4 -> V_151 ;
switch ( V_11 -> V_258 ) {
case V_329 :
case V_330 :
strncpy ( V_151 -> V_268 , V_331 ,
V_270 ) ;
break;
case V_332 :
strncpy ( V_151 -> V_268 , V_333 ,
V_270 ) ;
break;
default:
F_43 ( & V_11 -> V_12 , L_74 ,
V_29 ) ;
V_75 = - V_267 ;
break;
}
}
return V_75 ;
}
static void F_151 ( struct V_1 * V_2 )
{
T_2 V_334 = V_335 ;
T_2 V_336 = V_337 ;
V_2 -> V_296 = V_302 ;
V_2 -> V_295 = V_301 ;
if ( ! V_2 -> V_4 -> V_320 ) {
V_334 = V_338 ;
V_336 = V_338 ;
}
F_152 ( V_2 , V_336 ) ;
F_153 ( V_2 , V_334 ) ;
}
int F_154 ( struct V_1 * V_2 , int V_339 )
{
struct V_80 * V_4 = V_2 -> V_4 ;
int V_75 = 0 ;
V_2 -> V_340 = false ;
V_4 -> V_320 = ! ! V_321 ;
switch ( V_95 ) {
case 2 :
V_4 -> V_260 = V_261 ;
V_4 -> V_281 = true ;
break;
case 3 :
V_4 -> V_260 = V_263 ;
V_4 -> V_281 = true ;
break;
case 4 :
V_4 -> V_260 = V_265 ;
V_4 -> V_281 = true ;
break;
default:
V_4 -> V_281 = false ;
break;
}
F_151 ( V_2 ) ;
V_75 = F_155 ( V_2 ) ;
if ( V_75 )
goto exit;
if ( F_98 ( V_2 ) ) {
V_75 = F_156 ( V_2 , V_339 ) ;
if ( V_75 )
goto V_341;
else
return V_75 ;
}
if ( F_157 ( V_2 ) ||
F_158 ( V_2 ) ) {
F_43 ( & V_2 -> V_11 -> V_12 , L_75 ) ;
V_75 = - V_342 ;
goto V_341;
}
V_75 = F_59 ( V_2 ) ;
if ( V_75 )
goto V_341;
V_75 = F_150 ( V_2 ) ;
if ( V_75 )
goto V_341;
V_75 = F_91 ( V_2 ) ;
if ( V_75 )
goto V_341;
V_75 = F_159 ( V_2 ) ;
if ( V_75 ) {
F_43 ( & V_2 -> V_11 -> V_12 , L_76 ) ;
goto V_343;
}
F_160 ( & V_2 -> V_344 , V_345 ) ;
V_75 = F_161 ( V_2 ) ;
if ( V_75 )
goto V_346;
F_148 ( V_2 ) ;
F_162 ( V_2 -> V_79 ) ;
F_48 ( V_2 , 1 ) ;
F_52 ( V_2 -> V_79 ) ;
V_75 = F_50 ( V_2 ) ;
if ( V_75 )
goto V_346;
V_75 = V_2 -> V_77 -> V_78 ( V_2 ) ;
if ( V_75 )
goto V_346;
F_84 ( & V_2 -> V_131 . V_130 ) ;
return 0 ;
V_346:
F_163 ( V_2 ) ;
V_343:
F_164 ( V_2 ) ;
V_341:
F_26 ( V_2 ) ;
F_165 ( V_4 -> V_76 ) ;
V_4 -> V_76 = NULL ;
exit:
return V_75 ;
}
void F_166 ( struct V_1 * V_2 )
{
struct V_80 * V_4 = V_2 -> V_4 ;
struct V_347 * V_8 = & V_4 -> V_8 ;
F_23 ( V_103 , & V_8 -> V_27 ) ;
F_96 ( & V_2 -> V_131 ) ;
if ( V_4 -> V_107 == V_108 )
F_65 ( V_2 , 1 ) ;
F_25 ( V_2 ) ;
F_48 ( V_2 , 0 ) ;
F_96 ( & V_2 -> V_344 ) ;
}
int F_167 ( struct V_1 * V_2 )
{
struct V_80 * V_4 = V_2 -> V_4 ;
struct V_347 * V_8 = & V_4 -> V_8 ;
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
void F_168 ( struct V_1 * V_2 )
{
struct V_80 * V_4 = V_2 -> V_4 ;
struct V_347 * V_8 = & V_4 -> V_8 ;
T_1 V_62 ;
V_8 -> V_10 = V_57 ;
V_62 = F_38 ( V_2 ) ;
if ( V_4 -> V_97 == V_62 )
F_37 ( V_2 , 0 ) ;
F_87 ( V_2 , F_84 , 0 ) ;
}
