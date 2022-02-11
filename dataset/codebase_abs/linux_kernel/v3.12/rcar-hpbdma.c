static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static void F_5 ( struct V_6 * V_7 , T_1 V_3 )
{
F_2 ( V_3 , V_7 -> V_8 + V_9 ) ;
}
static void F_6 ( struct V_6 * V_7 , T_1 V_10 )
{
F_2 ( 0x1 , V_7 -> V_11 + F_7 ( V_10 ) ) ;
}
static T_1 F_8 ( struct V_6 * V_7 , T_1 V_10 )
{
T_1 V_12 ;
if ( V_10 < 32 )
V_12 = F_4 ( V_7 -> V_11 + V_13 ) >> V_10 ;
else
V_12 = F_4 ( V_7 -> V_11 + V_14 ) >> ( V_10 - 32 ) ;
return V_12 & 0x1 ;
}
static void F_9 ( struct V_6 * V_7 , T_1 V_10 )
{
if ( V_10 < 32 )
F_2 ( ( 0x1 << V_10 ) , V_7 -> V_11 + V_15 ) ;
else
F_2 ( ( 0x1 << ( V_10 - 32 ) ) ,
V_7 -> V_11 + V_16 ) ;
}
static void F_10 ( struct V_6 * V_7 , T_1 V_3 )
{
F_2 ( V_3 , V_7 -> V_17 ) ;
}
static T_1 F_11 ( struct V_6 * V_7 )
{
return F_4 ( V_7 -> V_17 ) ;
}
static void F_12 ( struct V_6 * V_7 , T_1 V_10 )
{
T_1 V_18 ;
F_13 ( & V_7 -> V_19 ) ;
if ( V_10 < 32 ) {
V_18 = F_4 ( V_7 -> V_11 + V_20 ) ;
F_2 ( F_14 ( V_10 ) | V_18 ,
V_7 -> V_11 + V_20 ) ;
} else {
V_18 = F_4 ( V_7 -> V_11 + V_21 ) ;
F_2 ( F_14 ( V_10 - 32 ) | V_18 ,
V_7 -> V_11 + V_21 ) ;
}
F_15 ( & V_7 -> V_19 ) ;
}
static void F_16 ( struct V_6 * V_7 , T_1 V_3 )
{
T_1 V_22 ;
int V_23 = 10000 ;
F_17 ( & V_7 -> V_19 ) ;
V_22 = F_4 ( V_7 -> V_24 ) ;
V_22 |= V_3 ;
F_2 ( V_22 , V_7 -> V_24 ) ;
do {
V_22 = F_4 ( V_7 -> V_24 ) ;
if ( ( V_22 & V_3 ) == V_3 )
break;
F_18 ( 10 ) ;
} while ( V_23 -- );
if ( V_23 < 0 )
F_19 ( V_7 -> V_25 . V_26 . V_27 ,
L_1 , V_28 ) ;
V_22 &= ~ V_3 ;
F_2 ( V_22 , V_7 -> V_24 ) ;
F_20 ( & V_7 -> V_19 ) ;
}
static void F_21 ( struct V_6 * V_7 ,
T_1 V_29 , T_1 V_3 )
{
T_1 V_30 ;
F_13 ( & V_7 -> V_19 ) ;
V_30 = F_11 ( V_7 ) ;
V_30 &= ~ V_29 ;
V_30 |= V_3 ;
F_10 ( V_7 , V_30 ) ;
F_15 ( & V_7 -> V_19 ) ;
}
static void F_22 ( struct V_6 * V_7 )
{
F_5 ( V_7 , V_31 ) ;
}
static void F_23 ( struct V_6 * V_7 )
{
T_1 V_10 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_32 -> V_33 ; V_10 ++ )
F_6 ( V_7 , V_10 ) ;
}
static unsigned int F_24 ( struct V_1 * V_34 )
{
struct V_6 * V_7 = F_25 ( V_34 ) ;
struct V_35 * V_32 = V_7 -> V_32 ;
int V_36 = F_3 ( V_34 , V_37 ) ;
int V_38 ;
switch ( V_36 & ( V_39 | V_40 ) ) {
case V_41 | V_42 :
default:
V_38 = V_43 ;
break;
case V_44 | V_45 :
V_38 = V_46 ;
break;
case V_47 | V_48 :
V_38 = V_49 ;
break;
}
return V_32 -> V_50 [ V_38 ] ;
}
static void F_26 ( struct V_1 * V_34 ,
struct V_51 * V_52 , unsigned V_53 )
{
F_1 ( V_34 , V_52 -> V_54 ,
V_53 ? V_55 : V_56 ) ;
F_1 ( V_34 , V_52 -> V_57 ,
V_53 ? V_58 : V_59 ) ;
F_1 ( V_34 , V_52 -> V_60 >> V_34 -> V_61 ,
V_53 ? V_62 : V_63 ) ;
}
static void F_27 ( struct V_1 * V_34 , bool V_64 )
{
F_1 ( V_34 , ( V_64 ? V_65 : 0 ) |
V_66 , V_9 ) ;
}
static void F_28 ( struct V_67 * V_68 )
{
struct V_1 * V_69 = F_29 ( V_68 ) ;
F_1 ( V_69 , V_70 , V_9 ) ;
F_1 ( V_69 , V_71 , V_72 ) ;
}
static const struct V_73 *
F_30 ( struct V_1 * V_34 , int V_74 )
{
struct V_6 * V_7 = F_25 ( V_34 ) ;
struct V_35 * V_32 = V_7 -> V_32 ;
int V_38 ;
if ( V_74 >= V_75 )
return NULL ;
for ( V_38 = 0 ; V_38 < V_32 -> V_76 ; V_38 ++ )
if ( V_32 -> V_77 [ V_38 ] . V_78 == V_74 )
return V_32 -> V_77 + V_38 ;
return NULL ;
}
static void F_31 ( struct V_67 * V_68 ,
struct V_79 * V_80 )
{
struct V_1 * V_69 = F_29 ( V_68 ) ;
struct V_6 * V_7 = F_25 ( V_69 ) ;
struct V_81 * V_82 = F_32 ( V_80 ) ;
if ( V_69 -> V_83 -> V_84 & V_85 )
F_16 ( V_7 , V_69 -> V_83 -> V_22 ) ;
V_82 -> V_86 = V_69 -> V_86 ;
F_26 ( V_69 , & V_82 -> V_52 , V_69 -> V_86 ) ;
F_27 ( V_69 , ! V_69 -> V_87 ) ;
if ( V_69 -> V_88 == V_89 ) {
V_69 -> V_86 ^= 1 ;
V_69 -> V_87 = false ;
}
}
static bool F_33 ( struct V_67 * V_68 ,
struct V_79 * V_80 )
{
return true ;
}
static bool F_34 ( struct V_67 * V_68 , int V_90 )
{
struct V_1 * V_69 = F_29 ( V_68 ) ;
struct V_6 * V_7 = F_25 ( V_69 ) ;
int V_10 = V_69 -> V_83 -> V_91 ;
if ( F_8 ( V_7 , V_10 ) ) {
F_9 ( V_7 , V_10 ) ;
return true ;
}
return false ;
}
static int F_35 ( struct V_67 * V_68 ,
struct V_79 * V_80 ,
T_2 V_92 , T_2 V_93 , T_3 * V_94 )
{
struct V_81 * V_82 = F_32 ( V_80 ) ;
if ( * V_94 > ( T_3 ) V_95 )
* V_94 = ( T_3 ) V_95 ;
V_82 -> V_52 . V_54 = V_92 ;
V_82 -> V_52 . V_57 = V_93 ;
V_82 -> V_52 . V_60 = * V_94 ;
return 0 ;
}
static T_3 F_36 ( struct V_67 * V_68 ,
struct V_79 * V_80 )
{
struct V_81 * V_82 = F_32 ( V_80 ) ;
struct V_1 * V_69 = F_29 ( V_68 ) ;
T_1 V_60 = F_3 ( V_69 , V_82 -> V_86 ?
V_62 : V_63 ) ;
return ( V_82 -> V_52 . V_60 - V_60 ) << V_69 -> V_61 ;
}
static bool F_37 ( struct V_67 * V_68 )
{
struct V_1 * V_69 = F_29 ( V_68 ) ;
T_1 V_96 = F_3 ( V_69 , V_97 ) ;
return ( V_96 & V_98 ) == V_98 ;
}
static int
F_38 ( struct V_1 * V_34 ,
const struct V_73 * V_83 )
{
struct V_6 * V_7 = F_25 ( V_34 ) ;
struct V_35 * V_32 = V_7 -> V_32 ;
const struct V_99 * V_100 = V_32 -> V_101 ;
int V_74 = V_83 -> V_78 ;
int V_38 , V_102 ;
for ( V_38 = 0 ; V_38 < V_32 -> V_103 ; V_38 ++ , V_100 ++ ) {
if ( V_100 -> V_104 == V_74 ) {
struct V_105 * V_27 = V_34 -> V_67 . V_27 ;
V_34 -> V_5 = V_7 -> V_8 +
F_39 ( V_83 -> V_91 ) ;
F_40 ( V_27 , L_2 ) ;
F_40 ( V_27 , L_3 , V_74 ) ;
F_40 ( V_27 , L_4 , V_83 -> V_91 ) ;
F_40 ( V_27 , L_5 ,
V_100 -> V_106 ) ;
break;
}
}
V_102 = F_41 ( & V_34 -> V_67 , V_100 -> V_106 ,
V_107 , V_34 -> V_108 ) ;
if ( V_102 ) {
F_19 ( V_34 -> V_67 . V_27 ,
L_6 ,
V_100 -> V_106 , V_102 ) ;
return V_102 ;
}
V_34 -> V_86 = 0 ;
V_34 -> V_87 = true ;
if ( ( V_83 -> V_109 & ( V_110 | V_111 ) ) == 0 ) {
V_34 -> V_88 = V_112 ;
} else if ( ( V_83 -> V_109 & ( V_110 | V_111 ) ) ==
( V_110 | V_111 ) ) {
V_34 -> V_88 = V_89 ;
} else {
F_19 ( V_34 -> V_67 . V_27 , L_7 ) ;
return - V_113 ;
}
if ( V_83 -> V_84 & V_114 )
F_21 ( V_7 , V_83 -> V_115 , V_83 -> V_116 ) ;
F_1 ( V_34 , V_83 -> V_109 , V_37 ) ;
F_1 ( V_34 , V_83 -> V_117 , V_118 ) ;
V_34 -> V_61 = F_24 ( V_34 ) ;
F_12 ( V_7 , V_83 -> V_91 ) ;
return 0 ;
}
static int F_42 ( struct V_67 * V_68 , int V_74 ,
T_2 V_119 , bool V_120 )
{
struct V_1 * V_69 = F_29 ( V_68 ) ;
const struct V_73 * V_121 =
F_30 ( V_69 , V_74 ) ;
if ( ! V_121 )
return - V_122 ;
if ( V_120 )
return 0 ;
V_69 -> V_83 = V_121 ;
V_69 -> V_119 = V_119 ? : V_121 -> V_123 ;
return F_38 ( V_69 , V_121 ) ;
}
static void F_43 ( struct V_67 * V_68 , int V_74 )
{
}
static T_2 F_44 ( struct V_67 * V_68 )
{
struct V_1 * V_69 = F_29 ( V_68 ) ;
return V_69 -> V_119 ;
}
static struct V_79 * F_45 ( void * V_124 , int V_38 )
{
return & ( (struct V_81 * ) V_124 ) [ V_38 ] . V_79 ;
}
static int F_46 ( struct V_6 * V_7 , int V_78 )
{
struct V_25 * V_125 = & V_7 -> V_25 ;
struct V_126 * V_127 =
F_47 ( V_7 -> V_25 . V_26 . V_27 ) ;
struct V_1 * V_128 ;
struct V_67 * V_68 ;
V_128 = F_48 ( & V_127 -> V_27 ,
sizeof( struct V_1 ) , V_129 ) ;
if ( ! V_128 ) {
F_19 ( V_7 -> V_25 . V_26 . V_27 ,
L_8 ) ;
return - V_130 ;
}
V_68 = & V_128 -> V_67 ;
F_49 ( V_125 , V_68 , V_78 ) ;
if ( V_127 -> V_78 >= 0 )
snprintf ( V_128 -> V_108 , sizeof( V_128 -> V_108 ) ,
L_9 , V_127 -> V_78 , V_78 ) ;
else
snprintf ( V_128 -> V_108 , sizeof( V_128 -> V_108 ) ,
L_10 , V_78 ) ;
return 0 ;
}
static int F_50 ( struct V_126 * V_127 )
{
struct V_35 * V_32 = V_127 -> V_27 . V_131 ;
struct V_6 * V_7 ;
struct V_132 * V_26 ;
struct V_133 * V_69 , * V_134 , * V_135 , * V_30 , * V_136 ;
int V_102 , V_38 ;
if ( ! V_32 || ! V_32 -> V_103 )
return - V_122 ;
V_69 = F_51 ( V_127 , V_137 , 0 ) ;
V_134 = F_51 ( V_127 , V_137 , 1 ) ;
V_135 = F_51 ( V_127 , V_137 , 2 ) ;
V_30 = F_51 ( V_127 , V_137 , 3 ) ;
V_136 = F_51 ( V_127 , V_138 , 0 ) ;
if ( ! V_136 )
return - V_122 ;
V_7 = F_48 ( & V_127 -> V_27 , sizeof( struct V_6 ) ,
V_129 ) ;
if ( ! V_7 ) {
F_19 ( & V_127 -> V_27 , L_11 ) ;
return - V_130 ;
}
V_7 -> V_8 = F_52 ( & V_127 -> V_27 , V_69 ) ;
if ( F_53 ( V_7 -> V_8 ) )
return F_54 ( V_7 -> V_8 ) ;
V_7 -> V_11 = F_52 ( & V_127 -> V_27 , V_134 ) ;
if ( F_53 ( V_7 -> V_11 ) )
return F_54 ( V_7 -> V_11 ) ;
V_7 -> V_24 = F_52 ( & V_127 -> V_27 , V_135 ) ;
if ( F_53 ( V_7 -> V_24 ) )
return F_54 ( V_7 -> V_24 ) ;
V_7 -> V_17 = F_52 ( & V_127 -> V_27 , V_30 ) ;
if ( F_53 ( V_7 -> V_17 ) )
return F_54 ( V_7 -> V_17 ) ;
V_26 = & V_7 -> V_25 . V_26 ;
F_55 ( & V_7 -> V_19 ) ;
V_7 -> V_32 = V_32 ;
F_56 ( & V_127 -> V_27 ) ;
V_102 = F_57 ( & V_127 -> V_27 ) ;
if ( V_102 < 0 )
F_19 ( & V_127 -> V_27 , L_12 , V_28 , V_102 ) ;
F_23 ( V_7 ) ;
F_58 ( & V_127 -> V_27 ) ;
F_59 ( V_139 , V_26 -> V_140 ) ;
F_59 ( V_141 , V_26 -> V_140 ) ;
V_7 -> V_25 . V_142 = & V_143 ;
V_7 -> V_25 . V_144 = sizeof( struct V_81 ) ;
V_102 = F_60 ( & V_127 -> V_27 , & V_7 -> V_25 , V_32 -> V_103 ) ;
if ( V_102 < 0 )
goto error;
for ( V_38 = 0 ; V_38 < V_32 -> V_103 ; V_38 ++ )
F_46 ( V_7 , V_38 ) ;
F_61 ( V_127 , V_7 ) ;
V_102 = F_62 ( V_26 ) ;
if ( ! V_102 )
return 0 ;
F_63 ( & V_7 -> V_25 ) ;
error:
F_64 ( & V_127 -> V_27 ) ;
return V_102 ;
}
static void F_65 ( struct V_6 * V_7 )
{
struct V_132 * V_26 = & V_7 -> V_25 . V_26 ;
struct V_67 * V_68 ;
int V_38 ;
F_66 (schan, &hpbdev->shdma_dev, i) {
F_67 ( ! V_68 ) ;
F_68 ( V_68 ) ;
}
V_26 -> V_145 = 0 ;
}
static int F_69 ( struct V_126 * V_127 )
{
struct V_6 * V_7 = F_70 ( V_127 ) ;
F_71 ( & V_7 -> V_25 . V_26 ) ;
F_64 ( & V_127 -> V_27 ) ;
F_65 ( V_7 ) ;
return 0 ;
}
static void F_72 ( struct V_126 * V_127 )
{
struct V_6 * V_7 = F_70 ( V_127 ) ;
F_22 ( V_7 ) ;
}
