static void F_1 ( struct V_1 * V_2 ,
const unsigned int V_3 , const T_1 V_4 )
{
if ( F_2 ( V_3 > V_5 || ! F_3 ( V_3 , V_6 ) ) )
return;
F_4 ( V_4 , V_2 -> V_7 + ( V_8 ) V_3 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , const unsigned int V_3 )
{
if ( F_2 ( V_3 > V_5 || ! F_3 ( V_3 , V_6 ) ) )
return ~ 0 ;
return F_6 ( V_2 -> V_7 + ( V_8 ) V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
const unsigned int V_3 , const T_1 V_4 )
{
unsigned long V_9 ;
if ( F_2 ( V_3 > V_10 || ! F_3 ( V_3 , V_6 ) ) )
return;
F_8 ( & V_2 -> V_11 , V_9 ) ;
F_4 ( ( T_1 ) V_3 , V_2 -> V_7 + ( V_8 ) V_12 ) ;
F_4 ( V_4 , V_2 -> V_7 + ( V_8 ) V_13 ) ;
F_9 () ;
F_10 ( & V_2 -> V_11 , V_9 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , const unsigned int V_3 )
{
unsigned long V_9 ;
T_1 V_4 ;
if ( F_2 ( V_3 > V_10 || ! F_3 ( V_3 , V_6 ) ) )
return ~ 0 ;
F_8 ( & V_2 -> V_11 , V_9 ) ;
F_4 ( ( T_1 ) V_3 , V_2 -> V_7 + ( V_8 ) V_12 ) ;
V_4 = F_6 ( V_2 -> V_7 + ( V_8 ) V_13 ) ;
F_10 ( & V_2 -> V_11 , V_9 ) ;
return V_4 ;
}
static inline int F_12 ( struct V_1 * V_2 , unsigned int V_3 ,
T_2 * V_14 ,
T_3 V_15 , T_3 V_16 )
{
unsigned long V_9 ;
T_1 V_4 ;
if ( V_16 & ~ ( T_3 ) V_15 )
return - V_17 ;
F_8 ( V_14 , V_9 ) ;
V_4 = F_5 ( V_2 , V_3 ) | ( T_1 ) V_16 ;
F_1 ( V_2 , V_3 , V_4 ) ;
F_10 ( V_14 , V_9 ) ;
return 0 ;
}
static inline void F_13 ( struct V_1 * V_2 ,
unsigned int V_3 , T_2 * V_14 ,
T_3 V_18 )
{
unsigned long V_9 ;
T_1 V_4 ;
F_8 ( V_14 , V_9 ) ;
V_4 = F_5 ( V_2 , V_3 ) & ~ ( T_1 ) V_18 ;
F_1 ( V_2 , V_3 , V_4 ) ;
F_10 ( V_14 , V_9 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
unsigned char V_19 , V_20 , V_21 ;
T_1 V_4 , V_22 , V_23 ;
V_4 = F_5 ( V_2 , V_24 ) ;
V_2 -> V_20 = F_15 ( V_25 , V_4 ) ;
V_22 = F_11 ( V_2 , V_26 [ V_2 -> V_20 ] . V_27 ) ;
V_2 -> V_21 = F_15 ( V_28 , V_22 ) ;
memset ( V_2 -> V_29 , - V_17 , sizeof( V_2 -> V_29 ) ) ;
memset ( V_2 -> V_30 , - V_17 , sizeof( V_2 -> V_30 ) ) ;
V_2 -> V_31 = 0 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_32 -> V_33 ; V_19 ++ ) {
V_20 = V_2 -> V_32 -> V_34 [ V_19 ] ;
if ( V_20 == V_2 -> V_20 )
continue;
V_22 = F_11 ( V_2 , V_26 [ V_20 ] . V_27 ) ;
V_21 = F_15 ( V_28 , V_22 ) ;
V_23 = F_11 ( V_2 , V_35 [ V_21 ] . V_27 ) ;
if ( F_16 ( V_36 , V_23 , V_37 ) &&
( F_16 ( V_38 , V_22 , V_39 ) ||
F_16 ( V_38 , V_22 , V_40 ) ||
F_16 ( V_38 , V_22 , V_41 ) ||
F_16 ( V_38 , V_22 , V_42 ) ) ) {
V_2 -> V_43 [ V_2 -> V_31 ] . V_20 = V_20 ;
V_2 -> V_43 [ V_2 -> V_31 ] . V_21 = V_21 ;
V_2 -> V_29 [ V_20 ] = V_2 -> V_31 ;
V_2 -> V_30 [ V_21 ] = V_2 -> V_31 ;
V_2 -> V_31 ++ ;
}
}
F_17 ( & V_2 -> V_44 . V_45 -> V_46 , L_1 ,
V_2 -> V_20 , V_2 -> V_31 ) ;
if ( V_2 -> V_31 == 0 ) {
F_18 ( & V_2 -> V_44 . V_45 -> V_46 , L_2 ) ;
return - V_47 ;
}
return 0 ;
}
static int F_19 ( struct V_48 * V_44 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
return V_2 -> V_20 ;
}
static int F_21 ( struct V_48 * V_44 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
return V_2 -> V_31 ;
}
static int F_22 ( struct V_48 * V_44 , int V_19 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
if ( V_19 < 0 || V_2 -> V_31 <= V_19 )
return - V_17 ;
return V_2 -> V_43 [ V_19 ] . V_20 ;
}
static int F_23 ( struct V_48 * V_44 , int V_20 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
if ( V_20 < 0 || V_49 <= V_20 )
return - V_17 ;
return V_2 -> V_29 [ V_20 ] ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_50 , V_51 , V_52 ;
unsigned char V_19 ;
F_25 ( & V_2 -> V_53 ) ;
V_51 = ~ F_26 ( V_2 -> V_20 ) ;
V_50 = ~ F_26 ( V_2 -> V_21 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_31 ; V_19 ++ ) {
V_51 &= ~ F_26 ( V_2 -> V_43 [ V_19 ] . V_20 ) ;
V_50 &= ~ F_26 ( V_2 -> V_43 [ V_19 ] . V_21 ) ;
}
F_7 ( V_2 , V_54 , ( T_1 ) - 1 ) ;
F_7 ( V_2 , V_55 , ( T_1 ) - 1 ) ;
F_7 ( V_2 , V_56 , ( T_1 ) - 1 ) ;
F_7 ( V_2 , V_57 , V_50 ) ;
F_7 ( V_2 , V_58 , V_51 ) ;
F_7 ( V_2 , V_59 , V_51 ) ;
F_7 ( V_2 , V_60 , V_50 ) ;
V_52 = ~ ( V_61 | V_62 | V_63 ) ;
F_7 ( V_2 , V_64 , V_52 ) ;
F_17 ( & V_2 -> V_44 . V_45 -> V_46 , L_3 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
F_17 ( & V_2 -> V_44 . V_45 -> V_46 , L_4 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_65 )
{
T_1 V_66 ;
V_66 = F_11 ( V_2 , V_67 ) ;
F_7 ( V_2 , V_54 , ( T_1 ) - 1 ) ;
F_7 ( V_2 , V_55 , ( T_1 ) - 1 ) ;
F_7 ( V_2 , V_56 , ( T_1 ) - 1 ) ;
F_1 ( V_2 , V_68 , V_69 ) ;
F_17 ( & V_2 -> V_44 . V_45 -> V_46 , L_5 ,
V_65 , V_66 ) ;
F_30 ( & V_2 -> V_44 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_1 V_70 , V_71 = 0 ;
unsigned long V_9 ;
F_1 ( V_2 , V_72 , V_73 ) ;
V_70 = F_5 ( V_2 , V_74 ) ;
V_71 = F_32 ( V_75 , 0 , V_70 ) |
F_32 ( V_76 , 0 , V_2 -> V_21 ) |
V_77 ;
F_8 ( & V_2 -> V_53 , V_9 ) ;
F_1 ( V_2 , V_78 , V_2 -> V_21 ) ;
F_1 ( V_2 , V_79 , V_71 ) ;
F_9 () ;
F_10 ( & V_2 -> V_53 , V_9 ) ;
F_1 ( V_2 , V_80 , V_81 ) ;
F_7 ( V_2 , V_56 , ( T_1 ) 1 << V_2 -> V_21 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
F_1 ( V_2 , V_72 , 0 ) ;
F_8 ( & V_2 -> V_53 , V_9 ) ;
F_1 ( V_2 , V_78 , V_2 -> V_21 ) ;
F_1 ( V_2 , V_79 , 0 ) ;
F_9 () ;
F_10 ( & V_2 -> V_53 , V_9 ) ;
F_1 ( V_2 , V_80 , V_81 ) ;
F_7 ( V_2 , V_56 , ( T_1 ) 1 << V_2 -> V_21 ) ;
}
static bool F_33 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
T_1 V_4 ;
V_4 = F_5 ( V_2 , V_82 ) ;
if ( ! ( V_4 & V_83 ) )
return false ;
V_4 = F_5 ( V_2 , V_72 ) ;
if ( ! ( V_4 & V_73 ) )
return false ;
F_8 ( & V_2 -> V_53 , V_9 ) ;
F_1 ( V_2 , V_78 , V_2 -> V_21 ) ;
V_4 = F_5 ( V_2 , V_79 ) ;
F_10 ( & V_2 -> V_53 , V_9 ) ;
return ! ! ( V_4 & V_77 ) ;
}
static bool F_34 ( struct V_1 * V_2 , int V_19 )
{
unsigned long V_9 ;
unsigned char V_20 ;
T_1 V_4 ;
V_20 = V_2 -> V_43 [ V_19 ] . V_20 ;
V_4 = F_11 ( V_2 , V_26 [ V_20 ] . V_27 ) ;
if ( ! ( V_4 & V_84 ) )
return false ;
V_4 = F_11 ( V_2 , V_26 [ V_20 ] . V_85 ) ;
if ( ! ( V_4 & V_83 ) )
return false ;
V_4 = F_11 ( V_2 , V_26 [ V_20 ] . V_86 ) ;
if ( ! ( V_4 & V_73 ) )
return false ;
F_8 ( & V_2 -> V_53 , V_9 ) ;
F_1 ( V_2 , V_78 , V_2 -> V_43 [ V_19 ] . V_21 ) ;
V_4 = F_5 ( V_2 , V_79 ) ;
F_10 ( & V_2 -> V_53 , V_9 ) ;
return ! ! ( V_4 & V_77 ) ;
}
static T_3 F_35 ( struct V_48 * V_44 ,
enum V_87 * V_88 , enum V_89 * V_90 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
unsigned char V_19 ;
T_3 V_91 ;
T_1 V_4 ;
if ( V_88 != NULL || V_90 != NULL ) {
V_4 = F_5 ( V_2 , V_92 ) ;
if ( V_88 != NULL )
* V_88 = F_15 ( V_93 , V_4 ) ;
if ( V_90 != NULL )
* V_90 = F_15 ( V_94 , V_4 ) ;
}
if ( ! F_33 ( V_2 ) )
return 0 ;
V_91 = 0 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_31 ; V_19 ++ ) {
if ( F_34 ( V_2 , V_19 ) )
V_91 |= ( ( T_3 ) 1 << V_19 ) ;
}
return V_91 ;
}
static int F_36 ( struct V_48 * V_44 , enum V_87 V_88 ,
enum V_89 V_90 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
F_31 ( V_2 ) ;
F_17 ( & V_2 -> V_44 . V_45 -> V_46 , L_6 ) ;
return 0 ;
}
static int F_37 ( struct V_48 * V_44 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
F_28 ( V_2 ) ;
F_17 ( & V_2 -> V_44 . V_45 -> V_46 , L_7 ) ;
return 0 ;
}
static inline unsigned char F_38 ( enum V_95 V_96 )
{
switch ( V_96 ) {
case V_97 :
return 1 ;
case V_98 :
return 12 ;
case V_99 :
return 24 ;
default:
break;
}
return 0 ;
}
static inline char * F_39 ( enum V_95 V_96 )
{
switch ( V_96 ) {
case V_97 :
return L_8 ;
case V_98 :
return L_9 ;
case V_99 :
return L_10 ;
default:
break;
}
return L_11 ;
}
static struct V_100 * F_40 ( struct V_1 * V_2 , int V_20 ,
unsigned char * V_101 )
{
struct V_100 V_102 [ V_103 ] , * V_104 ;
const struct V_105 * V_106 ;
enum V_95 V_96 ;
unsigned char V_107 , V_108 , V_109 ;
bool V_110 = false ;
int V_111 ;
T_1 V_4 ;
V_106 = V_26 [ V_20 ] . V_106 ;
* V_101 = 0 ;
for ( V_108 = 0 ; V_108 < V_112 ; V_108 += 1 + V_110 ) {
V_4 = F_11 ( V_2 , V_106 [ V_108 ] . V_113 ) ;
if ( ! ( V_4 & V_114 ) ) {
V_110 = false ;
continue;
}
V_110 = F_16 ( V_115 , V_4 , 64 ) ;
if ( V_4 & V_116 )
continue;
V_96 = F_15 ( V_117 , V_4 ) ;
V_109 = F_38 ( V_96 ) ;
V_111 = ( T_3 ) 1 << F_15 ( V_118 , V_4 ) ;
for ( V_107 = 0 ; V_107 < V_109 ; V_107 ++ , ( * V_101 ) ++ ) {
if ( * V_101 >= V_103 )
return F_41 ( - V_17 ) ;
V_102 [ * V_101 ] . type = V_96 ;
V_102 [ * V_101 ] . V_119 = V_108 ;
V_102 [ * V_101 ] . V_120 = V_107 ;
V_102 [ * V_101 ] . V_121 = V_122 ;
if ( V_96 == V_97 )
V_102 [ * V_101 ] . V_123 = V_111 ;
else if ( V_96 == V_98 )
V_102 [ * V_101 ] . V_123 = V_111 / 16 ;
else
V_102 [ * V_101 ] . V_123 = V_111 / 32 ;
V_102 [ * V_101 ] . V_124 = ( V_96 == V_97 ) ?
V_125 : V_102 [ * V_101 ] . V_123 ;
}
}
V_104 = F_42 ( & V_2 -> V_44 . V_45 -> V_46 , * V_101 ,
sizeof( * V_104 ) , V_126 ) ;
if ( F_43 ( V_104 ) )
return F_41 ( - V_127 ) ;
memcpy ( V_104 , V_102 , ( * V_101 ) * sizeof( * V_104 ) ) ;
return V_104 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_128 * V_129 ;
unsigned char V_19 ;
V_2 -> V_102 = F_40 ( V_2 , V_2 -> V_20 , & V_2 -> V_101 ) ;
if ( F_45 ( V_2 -> V_102 ) ) {
F_46 ( & V_2 -> V_44 . V_45 -> V_46 ,
L_12 , V_2 -> V_20 ) ;
return F_47 ( V_2 -> V_102 ) ;
}
for ( V_19 = 0 ; V_19 < V_2 -> V_31 ; V_19 ++ ) {
V_129 = & V_2 -> V_43 [ V_19 ] ;
V_129 -> V_102 = F_40 ( V_2 , V_129 -> V_20 , & V_129 -> V_101 ) ;
if ( F_45 ( V_129 -> V_102 ) ) {
F_46 ( & V_2 -> V_44 . V_45 -> V_46 ,
L_13 , V_129 -> V_20 ) ;
return F_47 ( V_129 -> V_102 ) ;
}
}
F_25 ( & V_2 -> V_130 ) ;
F_17 ( & V_2 -> V_44 . V_45 -> V_46 , L_14 ) ;
return 0 ;
}
static int F_48 ( struct V_48 * V_44 , int V_19 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
if ( V_19 < 0 || V_2 -> V_31 <= V_19 )
return - V_17 ;
return V_2 -> V_43 [ V_19 ] . V_101 ;
}
static int F_49 ( struct V_48 * V_44 , int V_19 , int V_107 ,
T_4 * V_121 ,
T_4 * V_124 ,
T_4 * V_123 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
struct V_128 * V_129 ;
if ( V_19 < 0 || V_2 -> V_31 <= V_19 )
return - V_17 ;
V_129 = & V_2 -> V_43 [ V_19 ] ;
if ( V_107 < 0 || V_129 -> V_101 <= V_107 )
return - V_17 ;
if ( V_121 != NULL )
* V_121 = V_129 -> V_102 [ V_107 ] . V_121 ;
if ( V_124 != NULL )
* V_124 = V_129 -> V_102 [ V_107 ] . V_124 ;
if ( V_123 != NULL )
* V_123 = V_129 -> V_102 [ V_107 ] . V_123 ;
return 0 ;
}
static int F_50 ( struct V_48 * V_44 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
return V_2 -> V_101 ;
}
static int F_51 ( struct V_48 * V_44 , int V_107 ,
T_5 * V_131 , T_4 * V_132 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
if ( V_107 < 0 || V_2 -> V_101 <= V_107 )
return - V_17 ;
if ( V_131 != NULL )
* V_131 = F_52 ( V_44 -> V_45 , V_2 -> V_102 [ V_107 ] . V_119 ) +
V_2 -> V_102 [ V_107 ] . V_120 * V_2 -> V_102 [ V_107 ] . V_123 ;
if ( V_132 != NULL )
* V_132 = V_2 -> V_102 [ V_107 ] . V_123 ;
return 0 ;
}
static int F_53 ( struct V_48 * V_44 , int V_19 , int V_107 ,
T_3 V_133 , T_4 V_132 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
struct V_100 * V_134 ;
T_1 V_4 = 0 , V_135 = 0 ;
if ( V_19 < 0 || V_2 -> V_31 <= V_19 )
return - V_17 ;
if ( V_107 < 0 || V_2 -> V_101 <= V_107 )
return - V_17 ;
V_134 = & V_2 -> V_102 [ V_107 ] ;
if ( ! F_3 ( V_133 , V_134 -> V_121 ) )
return - V_17 ;
if ( ! F_3 ( V_132 , V_134 -> V_124 ) || V_132 > V_134 -> V_123 )
return - V_17 ;
if ( V_134 -> type == V_97 ) {
const struct V_105 * V_119 = & V_136 . V_106 [ V_134 -> V_119 ] ;
T_3 V_137 ;
V_4 = F_5 ( V_2 , V_119 -> V_113 ) ;
V_4 = F_32 ( V_138 , V_4 , V_2 -> V_43 [ V_19 ] . V_21 ) ;
F_1 ( V_2 , V_119 -> V_113 , V_4 ) ;
F_1 ( V_2 , V_119 -> V_139 , ( T_1 ) V_133 ) ;
F_1 ( V_2 , V_119 -> V_140 , ( T_1 ) ( V_133 >> 32 ) ) ;
V_137 = F_52 ( V_44 -> V_45 , V_134 -> V_119 ) + V_132 ;
F_1 ( V_2 , V_119 -> V_137 , ( T_1 ) V_137 ) ;
if ( F_16 ( V_115 , V_4 , 64 ) )
F_1 ( V_2 , ( V_119 + 1 ) -> V_137 , ( V_137 >> 32 ) ) ;
} else {
unsigned long V_9 ;
V_135 = F_32 ( V_141 , 0 , V_134 -> V_120 ) |
F_32 ( V_142 , 0 , V_134 -> V_119 ) ;
V_4 = F_32 ( V_143 , 0 , V_2 -> V_43 [ V_19 ] . V_21 ) |
V_144 ;
F_8 ( & V_2 -> V_130 , V_9 ) ;
F_1 ( V_2 , V_145 , V_135 ) ;
F_1 ( V_2 , V_146 , ( T_1 ) V_133 ) ;
F_1 ( V_2 , V_147 , ( T_1 ) ( V_133 >> 32 ) ) ;
F_1 ( V_2 , V_148 , V_4 ) ;
F_9 () ;
F_10 ( & V_2 -> V_130 , V_9 ) ;
}
return 0 ;
}
static int F_54 ( struct V_48 * V_44 , int V_19 ,
int V_107 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
struct V_100 * V_134 ;
if ( V_19 < 0 || V_2 -> V_31 <= V_19 )
return - V_17 ;
if ( V_107 < 0 || V_2 -> V_101 <= V_107 )
return - V_17 ;
V_134 = & V_2 -> V_102 [ V_107 ] ;
if ( V_134 -> type == V_97 ) {
const struct V_105 * V_119 = & V_136 . V_106 [ V_134 -> V_119 ] ;
T_1 V_4 ;
V_4 = F_5 ( V_2 , V_119 -> V_113 ) ;
F_1 ( V_2 , V_119 -> V_137 , 0 ) ;
if ( F_16 ( V_115 , V_4 , 64 ) )
F_1 ( V_2 , ( V_119 + 1 ) -> V_137 , 0 ) ;
} else {
unsigned long V_9 ;
T_1 V_135 ;
V_135 = F_32 ( V_141 , 0 , V_134 -> V_120 ) |
F_32 ( V_142 , 0 , V_134 -> V_119 ) ;
F_8 ( & V_2 -> V_130 , V_9 ) ;
F_1 ( V_2 , V_145 , V_135 ) ;
F_1 ( V_2 , V_146 , 0 ) ;
F_1 ( V_2 , V_147 , 0 ) ;
F_1 ( V_2 , V_148 , 0 ) ;
F_9 () ;
F_10 ( & V_2 -> V_130 , V_9 ) ;
}
return 0 ;
}
static void F_55 ( struct V_1 * V_2 , T_1 V_65 )
{
F_17 ( & V_2 -> V_44 . V_45 -> V_46 , L_15 , V_65 ) ;
F_56 ( & V_2 -> V_44 , 0 ) ;
}
static T_3 F_57 ( struct V_48 * V_44 )
{
return V_149 ;
}
static T_3 F_58 ( struct V_48 * V_44 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
return F_5 ( V_2 , V_150 ) ;
}
static int F_59 ( struct V_48 * V_44 , T_3 V_151 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
F_1 ( V_2 , V_150 , ( T_1 ) V_151 ) ;
return 0 ;
}
static T_3 F_60 ( struct V_48 * V_44 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
return F_5 ( V_2 , V_152 ) ;
}
static int F_61 ( struct V_48 * V_44 , T_3 V_151 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
return F_12 ( V_2 , V_152 , & V_2 -> V_153 ,
V_149 , V_151 ) ;
}
static int F_62 ( struct V_48 * V_44 , T_3 V_151 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
F_13 ( V_2 , V_152 , & V_2 -> V_153 ,
V_151 ) ;
return 0 ;
}
static int F_63 ( struct V_48 * V_44 , T_3 V_151 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
if ( V_151 & ~ ( T_3 ) V_149 )
return - V_17 ;
F_1 ( V_2 , V_154 , ( T_1 ) V_151 ) ;
return 0 ;
}
static void F_64 ( struct V_1 * V_2 )
{
unsigned char V_155 ;
for ( V_155 = 0 ; V_155 < V_156 ; V_155 ++ )
F_25 ( & V_2 -> V_157 [ V_155 ] ) ;
F_17 ( & V_2 -> V_44 . V_45 -> V_46 , L_16 ) ;
}
static void F_65 ( struct V_1 * V_2 , T_1 V_65 )
{
F_17 ( & V_2 -> V_44 . V_45 -> V_46 , L_17 , V_65 ) ;
F_66 ( & V_2 -> V_44 ) ;
}
static int F_67 ( struct V_48 * V_44 )
{
return V_156 ;
}
static T_3 F_68 ( struct V_48 * V_44 )
{
return ( T_3 ) V_158 ;
}
static T_3 F_69 ( struct V_48 * V_44 )
{
return ( T_3 ) V_159 ;
}
static T_3 F_70 ( struct V_48 * V_44 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
return F_5 ( V_2 , V_160 ) ;
}
static int F_71 ( struct V_48 * V_44 , T_3 V_161 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
F_1 ( V_2 , V_160 , V_161 ) ;
return 0 ;
}
static int F_72 ( struct V_48 * V_44 , T_3 V_162 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
return F_12 ( V_2 , V_163 , & V_2 -> V_164 ,
V_165 , V_162 ) ;
}
static int F_73 ( struct V_48 * V_44 , T_3 V_162 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
F_13 ( V_2 , V_163 , & V_2 -> V_164 ,
V_162 ) ;
return 0 ;
}
static int F_74 ( struct V_48 * V_44 , int V_155 , int * V_19 , T_1 * V_166 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
if ( V_155 < 0 || V_156 <= V_155 )
return - V_17 ;
if ( V_19 != NULL ) {
T_1 V_167 ;
V_167 = F_5 ( V_2 , V_136 . V_168 [ V_155 ] . V_169 ) ;
* V_19 = V_2 -> V_30 [ V_167 ] ;
if ( * V_19 == - V_17 )
* V_19 = 0 ;
}
if ( V_166 != NULL )
* V_166 = F_5 ( V_2 , V_136 . V_168 [ V_155 ] . V_170 ) ;
return 0 ;
}
static int F_75 ( struct V_48 * V_44 , int V_155 , int V_19 , T_1 V_166 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
unsigned long V_9 ;
T_1 V_171 = 0 ;
if ( V_155 < 0 || V_156 <= V_155 )
return - V_17 ;
if ( V_19 < 0 || V_2 -> V_31 <= V_19 )
return - V_17 ;
V_171 = F_32 ( V_172 , 0 , V_155 ) |
F_32 ( V_173 , 0 , V_2 -> V_43 [ V_19 ] . V_21 ) ;
F_8 ( & V_2 -> V_157 [ V_155 ] , V_9 ) ;
F_7 ( V_2 , V_35 [ V_2 -> V_21 ] . V_174 [ V_155 ] , V_171 ) ;
F_1 ( V_2 , V_136 . V_168 [ V_155 ] . V_175 , V_166 ) ;
F_9 () ;
F_10 ( & V_2 -> V_157 [ V_155 ] , V_9 ) ;
return 0 ;
}
static void F_76 ( struct V_1 * V_2 , unsigned char * V_176 ,
unsigned char * V_177 )
{
T_1 V_4 ;
V_4 = F_11 ( V_2 , V_178 ) ;
V_4 = F_15 ( V_179 , V_4 ) ;
* V_176 = V_4 >> 1 ;
* V_177 = ( ( V_4 & 0x1 ) ? 5 : 0 ) ;
}
static void F_77 ( struct V_1 * V_2 , T_1 V_65 )
{
unsigned char V_176 , V_177 ;
F_76 ( V_2 , & V_176 , & V_177 ) ;
F_1 ( V_2 , V_68 , V_180 ) ;
F_17 ( & V_2 -> V_44 . V_45 -> V_46 ,
L_18 , V_65 ) ;
F_18 ( & V_2 -> V_44 . V_45 -> V_46 , L_19 , V_176 , V_177 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_181 * V_45 = V_2 -> V_44 . V_45 ;
T_1 V_182 ;
int V_183 ;
V_183 = F_79 ( V_45 , 1 , 1 , V_184 | V_185 ) ;
if ( V_183 != 1 ) {
F_46 ( & V_45 -> V_46 , L_20 ) ;
return V_183 ;
}
V_183 = F_80 ( V_45 , 0 ) ;
if ( V_183 < 0 ) {
F_46 ( & V_45 -> V_46 , L_21 ) ;
goto V_186;
}
V_183 = F_81 ( & V_45 -> V_46 , V_183 , NULL , V_187 ,
V_188 , V_189 , V_2 ) ;
if ( V_183 != 0 ) {
F_46 ( & V_45 -> V_46 , L_22 , V_183 ) ;
goto V_186;
}
V_182 = F_5 ( V_2 , V_190 ) & ~ V_191 ;
F_1 ( V_2 , V_190 , V_182 ) ;
F_17 ( & V_45 -> V_46 , L_23 ) ;
return 0 ;
V_186:
F_82 ( V_45 ) ;
return V_183 ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_181 * V_45 = V_2 -> V_44 . V_45 ;
T_1 V_182 ;
V_182 = F_5 ( V_2 , V_190 ) | V_191 ;
F_1 ( V_2 , V_190 , V_182 ) ;
F_84 ( & V_45 -> V_46 , F_80 ( V_45 , 0 ) , V_2 ) ;
F_82 ( V_45 ) ;
F_17 ( & V_45 -> V_46 , L_24 ) ;
}
static T_6 V_187 ( int V_192 , void * V_193 )
{
struct V_1 * V_2 = V_193 ;
bool V_194 = false ;
T_1 V_65 ;
V_65 = F_5 ( V_2 , V_68 ) ;
if ( V_65 & V_195 ) {
F_65 ( V_2 , V_65 ) ;
V_194 = true ;
}
if ( V_65 & V_196 ) {
F_55 ( V_2 , V_65 ) ;
V_194 = true ;
}
if ( V_65 & V_69 ) {
F_29 ( V_2 , V_65 ) ;
V_194 = true ;
}
if ( V_65 & V_180 ) {
F_77 ( V_2 , V_65 ) ;
V_194 = true ;
}
F_17 ( & V_2 -> V_44 . V_45 -> V_46 , L_25 , V_65 ) ;
return V_194 ? V_197 : V_198 ;
}
static int F_85 ( struct V_1 * V_2 )
{
int V_183 ;
V_2 -> V_44 . V_199 = & V_200 ;
V_2 -> V_44 . V_201 = V_202 ;
V_183 = F_86 ( & V_2 -> V_44 ) ;
if ( V_183 != 0 ) {
F_46 ( & V_2 -> V_44 . V_45 -> V_46 , L_26 ) ;
return V_183 ;
}
F_17 ( & V_2 -> V_44 . V_45 -> V_46 , L_27 ) ;
return 0 ;
}
static void F_87 ( struct V_1 * V_2 )
{
F_88 ( & V_2 -> V_44 ) ;
F_17 ( & V_2 -> V_44 . V_45 -> V_46 , L_28 ) ;
}
static T_7 F_89 ( struct V_203 * V_204 , char T_8 * V_205 ,
T_9 V_206 , T_10 * V_207 )
{
struct V_1 * V_2 = V_204 -> V_208 ;
unsigned char V_209 , V_177 , V_120 , V_19 , V_210 ;
T_7 V_183 = 0 , V_211 = 0 ;
unsigned long V_9 ;
enum V_87 V_88 ;
enum V_89 V_90 ;
char * V_212 ;
T_9 V_132 ;
T_1 V_4 ;
V_132 = F_90 ( T_9 , V_206 , 0x1000U ) ;
V_212 = F_91 ( V_132 , V_126 ) ;
if ( V_212 == NULL )
return - V_127 ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_29 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_30 , V_2 -> V_20 , V_2 -> V_21 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 , L_31 ) ;
for ( V_120 = 0 ; V_120 < V_2 -> V_31 ; V_120 ++ ) {
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_32 ,
V_120 , V_2 -> V_43 [ V_120 ] . V_20 , V_2 -> V_43 [ V_120 ] . V_21 ) ;
}
V_4 = F_35 ( & V_2 -> V_44 , & V_88 , & V_90 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_33 , V_4 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 , L_34 ,
V_88 , V_90 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 , L_35 ) ;
for ( V_120 = 0 ; V_120 < V_213 ; V_120 ++ ) {
F_8 ( & V_2 -> V_53 , V_9 ) ;
F_1 ( V_2 , V_78 , V_120 ) ;
V_4 = F_5 ( V_2 , V_79 ) ;
F_10 ( & V_2 -> V_53 , V_9 ) ;
if ( V_4 & V_77 ) {
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_36 ,
V_120 , F_15 ( V_76 , V_4 ) ,
F_15 ( V_75 , V_4 ) ) ;
}
}
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 , L_37 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_38 ) ;
for ( V_120 = 0 ; V_120 < V_2 -> V_101 ; V_120 += V_210 ) {
V_4 = V_2 -> V_102 [ V_120 ] . type ;
V_210 = F_38 ( V_4 ) ;
if ( V_4 == V_97 )
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_39 , V_120 ) ;
else
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_40 , V_120 , V_120 + V_210 - 1 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 , L_41 ,
F_39 ( V_4 ) , V_2 -> V_102 [ V_120 ] . V_119 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_42 , V_2 -> V_102 [ V_120 ] . V_121 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_43 ,
V_2 -> V_102 [ V_120 ] . V_124 , V_2 -> V_102 [ V_120 ] . V_123 ) ;
}
for ( V_19 = 0 ; V_19 < V_2 -> V_31 ; V_19 ++ ) {
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_44 ,
V_19 , V_2 -> V_43 [ V_19 ] . V_20 ) ;
for ( V_120 = 0 ; V_120 < V_2 -> V_43 [ V_19 ] . V_101 ; V_120 += V_210 ) {
V_4 = V_2 -> V_43 [ V_19 ] . V_102 [ V_120 ] . type ;
V_210 = F_38 ( V_4 ) ;
if ( V_4 == V_97 )
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_39 , V_120 ) ;
else
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_40 , V_120 , V_120 + V_210 - 1 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_41 , F_39 ( V_4 ) ,
V_2 -> V_43 [ V_19 ] . V_102 [ V_120 ] . V_119 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_42 ,
V_2 -> V_43 [ V_19 ] . V_102 [ V_120 ] . V_121 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_43 ,
V_2 -> V_43 [ V_19 ] . V_102 [ V_120 ] . V_124 ,
V_2 -> V_43 [ V_19 ] . V_102 [ V_120 ] . V_123 ) ;
}
}
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 , L_37 ) ;
V_4 = F_11 ( V_2 , V_214 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_45 , V_4 ) ;
V_4 = F_58 ( & V_2 -> V_44 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_46 , V_4 ) ;
V_4 = F_5 ( V_2 , V_152 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_47 , V_4 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 , L_37 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_48 , V_165 ) ;
V_4 = F_70 ( & V_2 -> V_44 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_49 , V_4 ) ;
V_4 = F_5 ( V_2 , V_163 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_50 , V_4 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_51 ) ;
for ( V_120 = 0 ; V_120 < V_156 ; V_120 ++ ) {
int V_169 ;
( void ) F_74 ( & V_2 -> V_44 , V_120 , & V_169 , & V_4 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_52 ,
V_120 , V_4 , V_169 , V_2 -> V_43 [ V_169 ] . V_20 ) ;
}
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 , L_37 ) ;
F_76 ( V_2 , & V_209 , & V_177 ) ;
V_211 += F_92 ( V_212 + V_211 , V_132 - V_211 ,
L_53 , V_209 , V_177 ) ;
V_183 = F_93 ( V_205 , V_206 , V_207 , V_212 , V_211 ) ;
F_94 ( V_212 ) ;
return V_183 ;
}
static int F_95 ( struct V_1 * V_2 )
{
char V_215 [ 64 ] ;
if ( F_43 ( V_216 ) ) {
F_96 ( & V_2 -> V_44 . V_45 -> V_46 , L_54 ) ;
return F_47 ( V_216 ) ;
}
snprintf ( V_215 , 64 , L_55 , F_97 ( V_2 -> V_44 . V_45 ) ) ;
V_2 -> V_217 = F_98 ( V_215 , 0400 , V_216 ,
V_2 , & V_218 ) ;
if ( F_45 ( V_2 -> V_217 ) ) {
F_17 ( & V_2 -> V_44 . V_45 -> V_46 , L_56 ) ;
return F_47 ( V_2 -> V_217 ) ;
}
F_17 ( & V_2 -> V_44 . V_45 -> V_46 , L_57 ) ;
return 0 ;
}
static void F_99 ( struct V_1 * V_2 )
{
F_100 ( V_2 -> V_217 ) ;
F_17 ( & V_2 -> V_44 . V_45 -> V_46 , L_58 ) ;
}
static int F_101 ( struct V_181 * V_45 )
{
T_1 V_4 ;
int V_183 ;
V_183 = F_102 ( V_45 , V_219 , & V_4 ) ;
if ( V_183 != 0 ) {
F_46 ( & V_45 -> V_46 ,
L_59 ) ;
return V_183 ;
}
if ( ! ( V_4 & V_114 ) || ! ( V_4 & V_116 ) ) {
F_46 ( & V_45 -> V_46 , L_60 ) ;
return - V_17 ;
}
if ( ( V_4 & V_220 ) != V_221 ) {
F_46 ( & V_45 -> V_46 , L_61 ) ;
return - V_17 ;
}
F_17 ( & V_45 -> V_46 , L_62 ) ;
return 0 ;
}
static struct V_1 * F_103 ( struct V_181 * V_45 ,
const struct V_222 * V_223 )
{
struct V_1 * V_2 ;
V_2 = F_104 ( & V_45 -> V_46 , sizeof( * V_2 ) , V_126 ) ;
if ( F_43 ( V_2 ) ) {
F_46 ( & V_45 -> V_46 , L_63 ) ;
return F_41 ( - V_127 ) ;
}
V_2 -> V_32 = (struct V_224 * ) V_223 -> V_225 ;
V_2 -> V_44 . V_45 = V_45 ;
F_25 ( & V_2 -> V_153 ) ;
F_25 ( & V_2 -> V_164 ) ;
F_25 ( & V_2 -> V_11 ) ;
F_96 ( & V_45 -> V_46 , L_64 , V_2 -> V_32 -> V_226 ) ;
F_17 ( & V_45 -> V_46 , L_65 ) ;
return V_2 ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_181 * V_45 = V_2 -> V_44 . V_45 ;
int V_183 ;
V_183 = F_106 ( V_45 , F_107 ( 64 ) ) ;
if ( V_183 != 0 ) {
V_183 = F_106 ( V_45 , F_107 ( 32 ) ) ;
if ( V_183 != 0 ) {
F_46 ( & V_45 -> V_46 , L_66 ) ;
return V_183 ;
}
F_18 ( & V_45 -> V_46 , L_67 ) ;
}
V_183 = F_108 ( V_45 , F_107 ( 64 ) ) ;
if ( V_183 != 0 ) {
V_183 = F_108 ( V_45 , F_107 ( 32 ) ) ;
if ( V_183 != 0 ) {
F_46 ( & V_45 -> V_46 ,
L_68 ) ;
return V_183 ;
}
F_18 ( & V_45 -> V_46 ,
L_69 ) ;
}
V_183 = F_109 ( V_45 ) ;
if ( V_183 != 0 )
F_18 ( & V_45 -> V_46 , L_70 ) ;
else
F_110 ( V_45 ) ;
V_183 = F_111 ( V_45 ) ;
if ( V_183 != 0 ) {
F_46 ( & V_45 -> V_46 , L_71 ) ;
goto V_227;
}
F_112 ( V_45 ) ;
V_183 = F_113 ( V_45 , 1 , V_228 ) ;
if ( V_183 != 0 ) {
F_46 ( & V_45 -> V_46 , L_72 ) ;
goto V_229;
}
V_2 -> V_7 = F_114 ( V_45 ) [ 0 ] ;
F_115 ( V_45 , V_2 ) ;
F_17 ( & V_45 -> V_46 , L_73 ) ;
return 0 ;
V_229:
F_116 ( V_45 ) ;
V_227:
( void ) F_117 ( V_45 ) ;
return V_183 ;
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_181 * V_45 = V_2 -> V_44 . V_45 ;
F_115 ( V_45 , NULL ) ;
F_116 ( V_45 ) ;
( void ) F_117 ( V_45 ) ;
F_17 ( & V_45 -> V_46 , L_74 ) ;
}
static int F_119 ( struct V_181 * V_45 ,
const struct V_222 * V_223 )
{
struct V_1 * V_2 ;
int V_183 ;
V_183 = F_101 ( V_45 ) ;
if ( V_183 != 0 )
return V_183 ;
V_2 = F_103 ( V_45 , V_223 ) ;
if ( F_43 ( V_2 ) )
return F_47 ( V_2 ) ;
V_183 = F_105 ( V_2 ) ;
if ( V_183 != 0 )
return V_183 ;
( void ) F_14 ( V_2 ) ;
F_24 ( V_2 ) ;
V_183 = F_44 ( V_2 ) ;
if ( V_183 != 0 )
goto V_230;
F_64 ( V_2 ) ;
V_183 = F_78 ( V_2 ) ;
if ( V_183 != 0 )
goto V_230;
V_183 = F_85 ( V_2 ) ;
if ( V_183 != 0 )
goto V_231;
( void ) F_95 ( V_2 ) ;
F_96 ( & V_45 -> V_46 , L_75 ) ;
return 0 ;
V_231:
F_83 ( V_2 ) ;
V_230:
F_27 ( V_2 ) ;
F_118 ( V_2 ) ;
return V_183 ;
}
static void F_120 ( struct V_181 * V_45 )
{
struct V_1 * V_2 = F_121 ( V_45 ) ;
F_99 ( V_2 ) ;
F_87 ( V_2 ) ;
F_83 ( V_2 ) ;
F_27 ( V_2 ) ;
F_118 ( V_2 ) ;
F_96 ( & V_45 -> V_46 , L_76 ) ;
}
static int T_11 F_122 ( void )
{
F_123 ( L_77 , V_232 , V_233 ) ;
if ( F_124 () )
V_216 = F_125 ( V_234 , NULL ) ;
return F_126 ( & V_235 ) ;
}
static void T_12 F_127 ( void )
{
F_128 ( & V_235 ) ;
F_129 ( V_216 ) ;
}
