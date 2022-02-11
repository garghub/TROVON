static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
if ( V_3 -> V_6 == V_7 )
return (struct V_1 * )
( ( V_8 * ) V_5 + sizeof( struct V_4 ) ) ;
if ( V_3 -> V_6 == V_9 )
return (struct V_1 * )
( ( V_8 * ) V_5 + sizeof( struct V_4 )
+ sizeof( struct V_10 ) ) ;
return NULL ;
}
static int F_2 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_2 * V_3 = F_3 ( V_12 , struct V_2 , V_11 ) ;
unsigned long V_15 ;
long V_16 , V_17 ;
T_1 V_18 , V_19 ;
F_4 ( & V_3 -> V_20 , V_15 ) ;
V_16 = F_5 ( V_3 , V_21 ) ;
V_18 = F_5 ( V_3 , V_22 ) ;
V_19 = F_5 ( V_3 , V_23 ) ;
V_17 = F_5 ( V_3 , V_21 ) ;
if ( V_16 > V_17 ) {
V_14 -> V_24 = F_5 ( V_3 , V_21 ) ;
V_18 = F_5 ( V_3 , V_22 ) ;
V_19 = F_5 ( V_3 , V_23 ) ;
} else {
V_14 -> V_24 = V_16 ;
}
F_6 ( & V_3 -> V_20 , V_15 ) ;
V_14 -> V_25 = ( ( ( V_26 ) V_19 << V_27 ) | V_18 )
& V_28 ;
return 0 ;
}
static int F_7 ( struct V_11 * V_12 ,
const struct V_13 * V_14 )
{
struct V_2 * V_3 = F_3 ( V_12 , struct V_2 , V_11 ) ;
unsigned long V_15 ;
T_1 V_29 , V_19 , V_18 ;
V_18 = ( T_1 ) V_14 -> V_25 ;
V_19 = ( V_14 -> V_25 >> V_27 ) & ( ( 1 << V_30 ) - 1 ) ;
V_29 = V_14 -> V_24 ;
F_4 ( & V_3 -> V_20 , V_15 ) ;
F_8 ( V_3 , V_21 , 0 ) ;
F_8 ( V_3 , V_23 , V_19 ) ;
F_8 ( V_3 , V_22 , V_18 ) ;
F_8 ( V_3 , V_21 , V_29 ) ;
F_6 ( & V_3 -> V_20 , V_15 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 , struct V_31 * V_32 )
{
unsigned long V_15 ;
F_4 ( & V_3 -> V_20 , V_15 ) ;
F_8 ( V_3 , V_33 , F_10 ( V_34 , V_32 -> V_35 ) ) ;
F_8 ( V_3 , V_36 , F_10 ( V_37 , V_32 -> V_29 ) ) ;
F_6 ( & V_3 -> V_20 , V_15 ) ;
return 0 ;
}
static int F_11 ( struct V_11 * V_12 , long V_38 )
{
struct V_2 * V_3 = F_3 ( V_12 , struct V_2 , V_11 ) ;
struct V_31 V_32 ;
bool V_39 = false ;
T_1 V_40 ;
V_26 V_41 ;
if ( V_38 < 0 ) {
V_39 = true ;
V_38 = - V_38 ;
}
V_32 . V_35 = V_3 -> V_31 . V_35 ;
V_32 . V_29 = V_3 -> V_31 . V_29 ;
V_40 = ( ( V_26 ) V_32 . V_29 << V_42 ) + V_32 . V_35 ;
V_41 = ( V_26 ) V_38 * V_40 ;
V_41 += ( V_43 >> 1 ) ;
V_41 >>= V_42 ;
V_41 = F_12 ( V_41 , V_43 ) ;
V_41 = V_39 ? ( V_40 - V_41 ) : ( V_40 + V_41 ) ;
V_32 . V_29 = ( V_41 >> V_42 )
& ( ( 1 << V_44 ) - 1 ) ;
V_32 . V_35 = V_41 & ( ( 1 << V_42 ) - 1 ) ;
F_9 ( V_3 , & V_32 ) ;
return 0 ;
}
static int F_13 ( struct V_11 * V_12 , T_2 V_45 )
{
struct V_2 * V_3 = F_3 ( V_12 , struct V_2 , V_11 ) ;
struct V_13 V_46 , V_47 = F_14 ( V_45 ) ;
T_1 V_41 , V_48 = 0 ;
if ( V_45 < 0 ) {
V_48 = 1 ;
V_45 = - V_45 ;
}
if ( V_45 > V_49 ) {
F_2 ( & V_3 -> V_11 , & V_46 ) ;
if ( V_48 )
V_46 = F_15 ( V_46 , V_47 ) ;
else
V_46 = F_16 ( V_46 , V_47 ) ;
F_7 ( & V_3 -> V_11 ,
( const struct V_13 * ) & V_46 ) ;
} else {
V_41 = ( V_48 << V_50 ) | V_45 ;
F_8 ( V_3 , V_51 , V_41 ) ;
}
return 0 ;
}
static int F_17 ( struct V_11 * V_12 ,
struct V_52 * V_53 , int V_54 )
{
return - V_55 ;
}
static void F_18 ( struct V_2 * V_3 )
{
T_1 V_56 = 0 ;
V_26 V_41 ;
V_3 -> V_31 . V_29 = F_19 ( V_57 , V_3 -> V_58 , & V_56 ) ;
if ( V_56 ) {
V_41 = V_56 ;
V_41 <<= V_42 ;
V_3 -> V_31 . V_35 = F_12 ( V_41 , V_3 -> V_58 ) ;
} else {
V_3 -> V_31 . V_35 = 0 ;
}
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_13 V_14 ;
V_14 = F_14 ( F_21 ( F_22 () ) ) ;
F_7 ( & V_3 -> V_11 , & V_14 ) ;
F_9 ( V_3 , & V_3 -> V_31 ) ;
F_8 ( V_3 , V_51 , 0 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
V_3 -> V_31 . V_35 = 0 ;
V_3 -> V_31 . V_29 = 0 ;
F_8 ( V_3 , V_33 , F_10 ( V_34 , 0 ) ) ;
F_8 ( V_3 , V_36 , F_10 ( V_37 , 0 ) ) ;
F_8 ( V_3 , V_51 , 0 ) ;
}
static int F_24 ( struct V_2 * V_3 , T_1 V_59 ,
T_1 V_60 , struct V_13 * V_14 )
{
struct V_13 V_61 ;
V_14 -> V_25 = ( F_25 ( V_62 , V_60 ) << V_63 ) |
F_25 ( V_64 , V_59 ) ;
V_14 -> V_24 = F_25 ( V_65 , V_59 ) ;
F_2 ( & V_3 -> V_11 , & V_61 ) ;
if ( ( V_14 -> V_25 & ( V_66 >> 1 ) ) &&
! ( V_61 . V_25 & ( V_66 >> 1 ) ) )
V_14 -> V_25 -= V_66 ;
V_14 -> V_25 += ( ( ~ V_67 ) & V_61 . V_25 ) ;
return 0 ;
}
void F_26 ( struct V_2 * V_3 , struct V_68 * V_69 ,
struct V_4 * V_5 )
{
struct V_70 * V_71 = F_27 ( V_69 ) ;
struct V_1 * V_72 ;
struct V_13 V_14 ;
if ( F_25 ( V_73 , V_5 -> V_74 ) ) {
V_72 = F_1 ( V_3 , V_5 ) ;
F_24 ( V_3 , V_72 -> V_75 , V_72 -> V_76 , & V_14 ) ;
memset ( V_71 , 0 , sizeof( struct V_70 ) ) ;
V_71 -> V_77 = F_28 ( V_14 . V_25 , V_14 . V_24 ) ;
}
}
static void F_29 ( struct V_2 * V_3 , struct V_68 * V_69 ,
struct V_1 * V_72 )
{
struct V_70 V_71 ;
struct V_13 V_14 ;
F_24 ( V_3 , V_72 -> V_75 , V_72 -> V_76 , & V_14 ) ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_77 = F_28 ( V_14 . V_25 , V_14 . V_24 ) ;
F_30 ( V_69 , & V_71 ) ;
}
int F_31 ( struct V_78 * V_79 , struct V_68 * V_69 ,
struct V_4 * V_5 )
{
unsigned long V_80 = F_32 ( V_79 -> V_81 ) ;
unsigned long V_82 = V_79 -> V_83 ;
struct V_1 * V_72 ;
struct V_84 * V_85 ;
if ( ! F_25 ( V_86 , V_5 -> V_87 ) )
return - V_88 ;
if ( F_33 ( V_82 , V_80 , V_89 ) == 0 )
return - V_90 ;
F_34 ( V_69 ) -> V_91 |= V_92 ;
V_72 = F_1 ( V_79 -> V_3 , V_5 ) ;
V_85 = & V_79 -> V_93 [ V_82 ] ;
V_85 -> V_69 = V_69 ;
V_85 -> V_72 . V_75 = V_72 -> V_75 ;
V_85 -> V_72 . V_76 = V_72 -> V_76 ;
F_35 ( & V_79 -> V_83 ,
( V_82 + 1 ) & ( V_89 - 1 ) ) ;
F_36 ( & V_79 -> V_94 ) ;
return 0 ;
}
static void F_37 ( struct V_95 * V_96 )
{
struct V_78 * V_79 =
F_3 ( V_96 , struct V_78 , V_94 ) ;
unsigned long V_82 , V_80 ;
struct V_84 * V_97 ;
V_82 = F_38 ( & V_79 -> V_83 ) ;
V_80 = V_79 -> V_81 ;
while ( F_39 ( V_82 , V_80 , V_89 ) ) {
V_97 = & V_79 -> V_93 [ V_80 ] ;
F_29 ( V_79 -> V_3 , V_97 -> V_69 , & V_97 -> V_72 ) ;
F_40 ( V_97 -> V_69 ) ;
F_35 ( & V_79 -> V_81 ,
( V_80 + 1 ) & ( V_89 - 1 ) ) ;
V_80 = V_79 -> V_81 ;
}
}
void F_41 ( struct V_98 * V_99 )
{
struct V_2 * V_3 = F_42 ( V_99 ) ;
struct V_78 * V_79 ;
unsigned int V_100 ;
V_3 -> V_11 = V_101 ;
V_3 -> V_58 = V_3 -> V_102 -> V_103 ( V_3 ) ;
V_3 -> V_11 . V_104 = V_3 -> V_102 -> V_105 () ;
F_18 ( V_3 ) ;
V_3 -> V_106 = F_43 ( & V_3 -> V_11 , & V_99 -> V_99 ) ;
if ( F_44 ( V_3 -> V_106 ) ) {
F_45 ( L_1 ,
F_46 ( V_3 -> V_106 ) ) ;
V_3 -> V_106 = NULL ;
return;
} else if ( V_3 -> V_106 == NULL ) {
F_45 ( L_2 ) ;
return;
}
F_47 ( & V_3 -> V_20 ) ;
for ( V_100 = 0 , V_79 = V_3 -> V_107 ; V_100 < V_3 -> V_108 ; ++ V_100 , ++ V_79 ) {
V_79 -> V_83 = 0 ;
V_79 -> V_81 = 0 ;
F_48 ( & V_79 -> V_94 , F_37 ) ;
}
F_20 ( V_3 ) ;
F_49 ( & V_3 -> V_109 -> V_99 , L_3 ,
V_110 ) ;
}
void F_50 ( struct V_98 * V_111 )
{
struct V_2 * V_3 = F_42 ( V_111 ) ;
if ( V_3 -> V_106 )
F_51 ( V_3 -> V_106 ) ;
F_23 ( V_3 ) ;
F_49 ( & V_3 -> V_109 -> V_99 , L_4 ,
V_110 ) ;
}
static int F_52 ( struct V_2 * V_3 ,
enum V_112 V_113 ,
enum V_112 V_114 )
{
F_8 ( V_3 , V_115 , F_10 ( V_116 , V_113 ) ) ;
F_8 ( V_3 , V_117 , F_10 ( V_118 , V_114 ) ) ;
return 0 ;
}
int F_53 ( struct V_98 * V_99 , struct V_119 * V_53 )
{
struct V_120 * V_121 ;
struct V_2 * V_3 = F_42 ( V_99 ) ;
V_121 = & V_3 -> V_121 ;
if ( ( V_3 -> V_6 & V_7 ) == 0 )
return - V_55 ;
if ( F_54 ( V_53 -> V_122 , V_121 , sizeof( * V_121 ) ) )
return - V_123 ;
else
return 0 ;
}
static int F_55 ( struct V_2 * V_3 , V_8 V_124 )
{
T_1 V_125 ;
V_125 = F_56 ( V_3 , V_126 ) ;
if ( V_124 )
F_57 ( V_3 , V_126 , V_125 | F_58 ( V_127 ) ) ;
else
F_57 ( V_3 , V_126 , V_125 & ~ F_58 ( V_127 ) ) ;
return 0 ;
}
int F_59 ( struct V_98 * V_99 , struct V_119 * V_128 , int V_129 )
{
enum V_112 V_113 = V_130 ;
enum V_112 V_114 = V_130 ;
struct V_120 * V_121 ;
struct V_2 * V_3 = F_42 ( V_99 ) ;
T_1 V_131 ;
V_121 = & V_3 -> V_121 ;
if ( ( V_3 -> V_6 & V_7 ) == 0 )
return - V_55 ;
if ( F_60 ( V_121 , V_128 -> V_122 ,
sizeof( * V_121 ) ) )
return - V_123 ;
if ( V_121 -> V_15 )
return - V_88 ;
switch ( V_121 -> V_132 ) {
case V_133 :
break;
case V_134 :
if ( F_55 ( V_3 , 1 ) != 0 )
return - V_135 ;
case V_136 :
V_113 = V_137 ;
break;
default:
return - V_135 ;
}
switch ( V_121 -> V_138 ) {
case V_139 :
break;
case V_140 :
break;
case V_141 :
break;
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
V_114 = V_151 ;
V_121 -> V_138 = V_142 ;
V_131 = F_56 ( V_3 , V_126 ) ;
F_57 ( V_3 , V_126 , ( V_131 | F_58 ( V_152 ) ) ) ;
break;
case V_153 :
case V_154 :
V_114 = V_137 ;
V_121 -> V_138 = V_154 ;
break;
default:
V_121 -> V_138 = V_139 ;
return - V_135 ;
}
if ( F_52 ( V_3 , V_113 , V_114 ) != 0 )
return - V_135 ;
if ( F_54 ( V_128 -> V_122 , V_121 , sizeof( * V_121 ) ) )
return - V_123 ;
else
return 0 ;
}
