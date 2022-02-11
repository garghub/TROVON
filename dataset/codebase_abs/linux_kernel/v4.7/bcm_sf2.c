static void F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 * V_4 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
memcpy ( V_4 + V_5 * V_7 ,
V_8 [ V_5 ] . string , V_7 ) ;
}
static void F_2 ( struct V_1 * V_2 ,
int V_3 , T_2 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
const struct V_11 * V_12 ;
unsigned int V_5 ;
T_3 V_13 = 0 ;
T_4 V_14 ;
F_4 ( & V_10 -> V_15 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_12 = & V_8 [ V_5 ] ;
V_14 = V_12 -> V_16 + F_5 ( V_3 ) ;
if ( V_12 -> V_17 == 8 )
V_13 = F_6 ( V_10 , V_14 ) ;
else
V_13 = F_7 ( V_10 , V_14 ) ;
V_4 [ V_5 ] = ( T_3 ) V_13 ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
return V_6 ;
}
static const char * F_10 ( struct V_18 * V_19 ,
struct V_18 * V_20 , int V_21 ,
void * * V_22 )
{
struct V_9 * V_10 ;
V_10 = F_11 ( V_19 , sizeof( * V_10 ) , V_23 ) ;
if ( ! V_10 )
return NULL ;
* V_22 = V_10 ;
return L_1 ;
}
static void F_12 ( struct V_1 * V_2 , int V_24 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_5 ;
T_4 V_16 ;
for ( V_5 = 0 ; V_5 < V_10 -> V_25 . V_26 ; V_5 ++ ) {
if ( ! ( ( 1 << V_5 ) & V_2 -> V_27 ) )
continue;
V_16 = F_7 ( V_10 , F_13 ( V_5 ) ) ;
V_16 |= ( 1 << V_24 ) ;
F_14 ( V_10 , V_16 , F_13 ( V_5 ) ) ;
}
}
static void F_15 ( struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_16 , V_13 ;
V_16 = F_7 ( V_10 , V_28 ) ;
V_16 &= ~ F_16 ( V_3 ) ;
F_14 ( V_10 , V_16 , V_28 ) ;
V_16 = F_7 ( V_10 , V_29 ) ;
V_16 |= ( V_30 | V_31 | V_32 ) ;
V_16 &= ~ ( V_33 | V_34 ) ;
F_14 ( V_10 , V_16 , V_29 ) ;
F_14 ( V_10 , V_35 , V_36 ) ;
V_16 = F_7 ( V_10 , V_37 ) ;
V_16 |= V_38 ;
F_14 ( V_10 , V_16 , V_37 ) ;
switch ( V_3 ) {
case 8 :
V_13 = V_39 ;
break;
case 7 :
V_13 = V_40 ;
break;
case 5 :
V_13 = V_41 ;
break;
default:
V_13 = 0 ;
break;
}
V_16 = F_7 ( V_10 , V_42 ) ;
V_16 |= V_13 ;
F_14 ( V_10 , V_16 , V_42 ) ;
V_16 = F_7 ( V_10 , V_43 ) ;
V_16 &= ~ ( 1 << V_3 ) ;
F_14 ( V_10 , V_16 , V_43 ) ;
V_16 = F_7 ( V_10 , V_44 ) ;
V_16 &= ~ ( 1 << V_3 ) ;
F_14 ( V_10 , V_16 , V_44 ) ;
V_16 = F_7 ( V_10 , V_45 ) ;
V_16 |= ( V_46 | V_47 ) ;
F_14 ( V_10 , V_16 , V_45 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_3 , bool V_48 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_49 ) ;
if ( V_48 )
V_16 |= 1 << V_3 ;
else
V_16 &= ~ ( 1 << V_3 ) ;
F_14 ( V_10 , V_16 , V_49 ) ;
}
static void F_18 ( struct V_1 * V_2 , bool V_48 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_16 ;
V_16 = F_19 ( V_10 , V_50 ) ;
if ( V_48 ) {
V_16 |= V_51 ;
V_16 &= ~ ( V_52 | V_53 | V_54 ) ;
F_20 ( V_10 , V_16 , V_50 ) ;
F_21 ( 21 ) ;
V_16 = F_19 ( V_10 , V_50 ) ;
V_16 &= ~ V_51 ;
} else {
V_16 |= V_52 | V_53 | V_51 ;
F_20 ( V_10 , V_16 , V_50 ) ;
F_22 ( 1 ) ;
V_16 |= V_54 ;
}
F_20 ( V_10 , V_16 , V_50 ) ;
if ( ! V_48 ) {
V_16 = F_19 ( V_10 , F_23 ( 0 ) ) ;
V_16 |= V_55 ;
F_20 ( V_10 , V_16 , F_23 ( 0 ) ) ;
}
}
static inline void F_24 ( struct V_9 * V_10 ,
int V_3 )
{
unsigned int V_56 ;
switch ( V_3 ) {
case 7 :
V_56 = V_57 ;
break;
case 0 :
F_25 ( V_10 , F_26 ( V_58 ) ) ;
return;
default:
V_56 = F_27 ( V_3 ) ;
break;
}
F_28 ( V_10 , F_26 ( V_56 ) ) ;
}
static inline void F_29 ( struct V_9 * V_10 ,
int V_3 )
{
unsigned int V_56 ;
switch ( V_3 ) {
case 7 :
V_56 = V_57 ;
break;
case 0 :
F_30 ( V_10 , F_26 ( V_58 ) ) ;
F_31 ( V_10 , F_26 ( V_58 ) , V_59 ) ;
return;
default:
V_56 = F_27 ( V_3 ) ;
break;
}
F_32 ( V_10 , F_26 ( V_56 ) ) ;
F_33 ( V_10 , F_26 ( V_56 ) , V_59 ) ;
}
static int F_34 ( struct V_1 * V_2 , int V_3 ,
struct V_60 * V_61 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_5 V_24 = V_2 -> V_62 [ V_2 -> V_63 ] . V_24 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_28 ) ;
V_16 &= ~ F_16 ( V_3 ) ;
F_14 ( V_10 , V_16 , V_28 ) ;
F_14 ( V_10 , 0 , F_35 ( V_3 ) ) ;
if ( V_10 -> V_64 & 1 << V_3 && V_10 -> V_25 . V_65 == 1 ) {
F_18 ( V_2 , true ) ;
if ( V_61 ) {
V_61 -> V_66 = V_67 ;
F_36 ( V_61 ) ;
}
}
if ( V_3 == V_10 -> V_68 )
F_24 ( V_10 , V_3 ) ;
V_16 = F_7 ( V_10 , F_13 ( V_3 ) ) ;
V_16 &= ~ V_69 ;
V_16 |= ( 1 << V_3 ) ;
V_16 |= V_10 -> V_70 [ V_3 ] . V_71 ;
F_14 ( V_10 , V_16 , F_13 ( V_3 ) ) ;
F_12 ( V_2 , V_24 ) ;
if ( V_10 -> V_70 [ V_3 ] . V_72 . V_73 )
F_17 ( V_2 , V_3 , true ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 , int V_3 ,
struct V_60 * V_61 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_56 , V_16 ;
if ( V_10 -> V_74 & ( 1 << V_3 ) )
return;
if ( V_3 == V_10 -> V_68 )
F_29 ( V_10 , V_3 ) ;
if ( V_10 -> V_64 & 1 << V_3 && V_10 -> V_25 . V_65 == 1 )
F_18 ( V_2 , false ) ;
if ( F_38 ( V_2 , V_3 ) )
V_56 = V_29 ;
else
V_56 = F_35 ( V_3 ) ;
V_16 = F_7 ( V_10 , V_56 ) ;
V_16 |= V_33 | V_34 ;
F_14 ( V_10 , V_16 , V_56 ) ;
V_16 = F_7 ( V_10 , V_28 ) ;
V_16 |= F_16 ( V_3 ) ;
F_14 ( V_10 , V_16 , V_28 ) ;
}
static int F_39 ( struct V_1 * V_2 , int V_3 ,
struct V_60 * V_61 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_75 * V_76 = & V_10 -> V_70 [ V_3 ] . V_72 ;
int V_77 ;
V_76 -> V_78 = ( V_79 | V_80 ) ;
V_77 = F_40 ( V_61 , 0 ) ;
if ( V_77 )
return 0 ;
F_17 ( V_2 , V_3 , true ) ;
return 1 ;
}
static int F_41 ( struct V_1 * V_2 , int V_3 ,
struct V_75 * V_81 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_75 * V_76 = & V_10 -> V_70 [ V_3 ] . V_72 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_82 ) ;
V_81 -> V_73 = V_76 -> V_73 ;
V_81 -> V_83 = ! ! ( V_16 & ( 1 << V_3 ) ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , int V_3 ,
struct V_60 * V_84 ,
struct V_75 * V_81 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_75 * V_76 = & V_10 -> V_70 [ V_3 ] . V_72 ;
V_76 -> V_73 = V_81 -> V_73 ;
if ( ! V_76 -> V_73 ) {
F_17 ( V_2 , V_3 , false ) ;
} else {
V_76 -> V_73 = F_39 ( V_2 , V_3 , V_84 ) ;
if ( ! V_76 -> V_73 )
return - V_85 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_86 = 1000 ;
T_4 V_16 ;
F_14 ( V_10 , V_3 , V_87 ) ;
V_16 = F_7 ( V_10 , V_88 ) ;
V_16 |= V_89 | V_90 | V_91 ;
F_14 ( V_10 , V_16 , V_88 ) ;
do {
V_16 = F_7 ( V_10 , V_88 ) ;
if ( ! ( V_16 & V_91 ) )
break;
F_44 () ;
} while ( V_86 -- );
if ( ! V_86 )
return - V_92 ;
F_14 ( V_10 , 0 , V_88 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , int V_3 ,
struct V_93 * V_94 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_5 ;
T_4 V_16 , V_95 ;
V_10 -> V_70 [ V_3 ] . V_96 = V_94 ;
V_95 = F_7 ( V_10 , F_13 ( V_3 ) ) ;
for ( V_5 = 0 ; V_5 < V_10 -> V_25 . V_26 ; V_5 ++ ) {
if ( V_10 -> V_70 [ V_5 ] . V_96 != V_94 )
continue;
V_16 = F_7 ( V_10 , F_13 ( V_5 ) ) ;
V_16 |= 1 << V_3 ;
F_14 ( V_10 , V_16 , F_13 ( V_5 ) ) ;
V_10 -> V_70 [ V_5 ] . V_71 = V_16 ;
V_95 |= 1 << V_5 ;
}
F_14 ( V_10 , V_95 , F_13 ( V_3 ) ) ;
V_10 -> V_70 [ V_3 ] . V_71 = V_95 ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_93 * V_94 = V_10 -> V_70 [ V_3 ] . V_96 ;
unsigned int V_5 ;
T_4 V_16 , V_95 ;
V_95 = F_7 ( V_10 , F_13 ( V_3 ) ) ;
for ( V_5 = 0 ; V_5 < V_10 -> V_25 . V_26 ; V_5 ++ ) {
if ( V_10 -> V_70 [ V_5 ] . V_96 != V_94 )
continue;
V_16 = F_7 ( V_10 , F_13 ( V_5 ) ) ;
V_16 &= ~ ( 1 << V_3 ) ;
F_14 ( V_10 , V_16 , F_13 ( V_5 ) ) ;
V_10 -> V_70 [ V_3 ] . V_71 = V_16 ;
if ( V_3 != V_5 )
V_95 &= ~ ( 1 << V_5 ) ;
}
F_14 ( V_10 , V_95 , F_13 ( V_3 ) ) ;
V_10 -> V_70 [ V_3 ] . V_71 = V_95 ;
V_10 -> V_70 [ V_3 ] . V_96 = NULL ;
}
static void F_47 ( struct V_1 * V_2 , int V_3 ,
T_6 V_66 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_6 V_97 , V_98 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , F_35 ( V_3 ) ) ;
V_98 = V_16 & ( V_99 << V_100 ) ;
switch ( V_66 ) {
case V_101 :
V_97 = V_102 ;
break;
case V_103 :
V_97 = V_104 ;
break;
case V_105 :
V_97 = V_106 ;
break;
case V_107 :
V_97 = V_108 ;
break;
case V_109 :
V_97 = V_110 ;
break;
default:
F_48 ( L_2 , V_111 , V_66 ) ;
return;
}
if ( V_98 != V_97 ) {
if ( V_98 >= V_106 &&
V_97 <= V_104 ) {
if ( F_43 ( V_2 , V_3 ) ) {
F_48 ( L_3 , V_111 ) ;
return;
}
}
}
V_16 = F_7 ( V_10 , F_35 ( V_3 ) ) ;
V_16 &= ~ ( V_99 << V_100 ) ;
V_16 |= V_97 ;
F_14 ( V_10 , V_16 , F_35 ( V_3 ) ) ;
}
static int F_49 ( struct V_9 * V_10 )
{
unsigned int V_86 = 10 ;
T_4 V_16 ;
do {
V_16 = F_7 ( V_10 , V_112 ) ;
if ( ! ( V_16 & V_113 ) )
return 0 ;
F_50 ( 1000 , 2000 ) ;
} while ( V_86 -- );
return - V_92 ;
}
static int F_51 ( struct V_9 * V_10 , unsigned int V_114 )
{
T_4 V_115 ;
if ( V_114 > V_116 )
return - V_117 ;
V_115 = F_7 ( V_10 , V_112 ) ;
V_115 &= ~ V_118 ;
V_115 |= V_113 ;
if ( V_114 )
V_115 |= V_116 ;
else
V_115 &= ~ V_116 ;
F_14 ( V_10 , V_115 , V_112 ) ;
return F_49 ( V_10 ) ;
}
static int F_52 ( struct V_9 * V_10 , T_3 V_119 ,
T_7 V_120 , struct V_121 * V_122 , T_6 * V_123 ,
bool V_124 )
{
unsigned int V_5 ;
int V_77 ;
V_77 = F_49 ( V_10 ) ;
if ( V_77 )
return V_77 ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
T_3 V_125 ;
T_4 V_126 ;
V_125 = F_6 ( V_10 , F_53 ( V_5 ) ) ;
V_126 = F_7 ( V_10 , F_54 ( V_5 ) ) ;
F_55 ( V_122 , V_125 , V_126 ) ;
if ( V_122 -> V_124 && V_124 ) {
* V_123 = V_5 ;
return 0 ;
}
if ( ! V_124 && ( V_125 & V_119 ) )
return 0 ;
}
return - V_127 ;
}
static int F_56 ( struct V_9 * V_10 , int V_114 , int V_3 ,
const unsigned char * V_128 , T_7 V_120 , bool V_124 )
{
struct V_121 V_122 ;
T_4 V_126 ;
T_3 V_119 , V_125 = 0 ;
T_6 V_123 = 0 ;
int V_77 ;
V_119 = F_57 ( V_128 ) ;
F_58 ( V_10 , V_119 , V_129 ) ;
F_14 ( V_10 , V_120 , V_130 ) ;
V_77 = F_51 ( V_10 , 1 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_52 ( V_10 , V_119 , V_120 , & V_122 , & V_123 , V_124 ) ;
if ( V_114 )
return V_77 ;
if ( V_77 ) {
V_126 = 0 ;
V_123 = 0 ;
}
memset ( & V_122 , 0 , sizeof( V_122 ) ) ;
V_122 . V_3 = V_3 ;
V_122 . V_124 = V_124 ;
V_122 . V_120 = V_120 ;
V_122 . V_131 = true ;
memcpy ( V_122 . V_119 , V_128 , V_132 ) ;
F_59 ( & V_125 , & V_126 , & V_122 ) ;
F_58 ( V_10 , V_125 , F_53 ( V_123 ) ) ;
F_14 ( V_10 , V_126 , F_54 ( V_123 ) ) ;
V_77 = F_51 ( V_10 , 0 ) ;
if ( V_77 )
return V_77 ;
return F_52 ( V_10 , V_119 , V_120 , & V_122 , & V_123 , V_124 ) ;
}
static int F_60 ( struct V_1 * V_2 , int V_3 ,
const struct V_133 * V_134 ,
struct V_135 * V_136 )
{
return 0 ;
}
static void F_61 ( struct V_1 * V_2 , int V_3 ,
const struct V_133 * V_134 ,
struct V_135 * V_136 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
if ( F_56 ( V_10 , 0 , V_3 , V_134 -> V_128 , V_134 -> V_120 , true ) )
F_48 ( L_4 , V_111 ) ;
}
static int F_62 ( struct V_1 * V_2 , int V_3 ,
const struct V_133 * V_134 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
return F_56 ( V_10 , 0 , V_3 , V_134 -> V_128 , V_134 -> V_120 , false ) ;
}
static int F_63 ( struct V_9 * V_10 )
{
unsigned V_86 = 1000 ;
T_4 V_16 ;
do {
V_16 = F_7 ( V_10 , V_137 ) ;
if ( ! ( V_16 & V_138 ) )
return 0 ;
if ( V_16 & V_139 )
return 0 ;
F_50 ( 1000 , 2000 ) ;
} while ( V_86 -- );
return - V_92 ;
}
static void F_64 ( struct V_9 * V_10 , T_6 V_123 ,
struct V_121 * V_122 )
{
T_3 V_125 ;
T_4 V_126 ;
V_125 = F_6 ( V_10 , F_65 ( V_123 ) ) ;
V_126 = F_7 ( V_10 , F_66 ( V_123 ) ) ;
F_55 ( V_122 , V_125 , V_126 ) ;
}
static int F_67 ( struct V_93 * V_140 , int V_3 ,
const struct V_121 * V_122 ,
struct V_133 * V_134 ,
int (* F_68)( struct V_141 * V_142 ) )
{
if ( ! V_122 -> V_124 )
return 0 ;
if ( V_3 != V_122 -> V_3 )
return 0 ;
F_69 ( V_134 -> V_128 , V_122 -> V_119 ) ;
V_134 -> V_120 = V_122 -> V_120 ;
V_134 -> V_143 = V_122 -> V_131 ? V_144 : V_145 ;
return F_68 ( & V_134 -> V_142 ) ;
}
static int F_70 ( struct V_1 * V_2 , int V_3 ,
struct V_133 * V_134 ,
int (* F_68)( struct V_141 * V_142 ) )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_93 * V_140 = V_2 -> V_146 [ V_3 ] ;
struct V_121 V_147 [ 2 ] ;
unsigned int V_148 = 0 ;
int V_77 ;
F_14 ( V_10 , V_138 , V_137 ) ;
do {
V_77 = F_63 ( V_10 ) ;
if ( V_77 )
return V_77 ;
F_64 ( V_10 , 0 , & V_147 [ 0 ] ) ;
V_77 = F_67 ( V_140 , V_3 , & V_147 [ 0 ] , V_134 , F_68 ) ;
if ( V_77 )
return V_77 ;
F_64 ( V_10 , 1 , & V_147 [ 1 ] ) ;
V_77 = F_67 ( V_140 , V_3 , & V_147 [ 1 ] , V_134 , F_68 ) ;
if ( V_77 )
return V_77 ;
if ( ! V_147 [ 0 ] . V_124 && ! V_147 [ 1 ] . V_124 )
break;
} while ( V_148 ++ < V_149 );
return 0 ;
}
static T_8 F_71 ( int V_150 , void * V_151 )
{
struct V_9 * V_10 = V_151 ;
V_10 -> V_152 = F_72 ( V_10 , V_153 ) &
~ V_10 -> V_154 ;
F_31 ( V_10 , V_10 -> V_152 , V_59 ) ;
return V_155 ;
}
static T_8 F_73 ( int V_150 , void * V_151 )
{
struct V_9 * V_10 = V_151 ;
V_10 -> V_156 = F_74 ( V_10 , V_153 ) &
~ V_10 -> V_157 ;
F_33 ( V_10 , V_10 -> V_156 , V_59 ) ;
if ( V_10 -> V_156 & F_75 ( V_57 ) )
V_10 -> V_70 [ 7 ] . V_158 = 1 ;
if ( V_10 -> V_156 & F_76 ( V_57 ) )
V_10 -> V_70 [ 7 ] . V_158 = 0 ;
return V_155 ;
}
static int F_77 ( struct V_9 * V_10 )
{
unsigned int V_86 = 1000 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_159 ) ;
V_16 |= V_160 | V_161 | V_162 ;
F_14 ( V_10 , V_16 , V_159 ) ;
do {
V_16 = F_7 ( V_10 , V_159 ) ;
if ( ! ( V_16 & V_160 ) )
break;
F_50 ( 1000 , 2000 ) ;
} while ( V_86 -- > 0 );
if ( V_86 == 0 )
return - V_92 ;
return 0 ;
}
static void F_78 ( struct V_9 * V_10 )
{
F_31 ( V_10 , 0xffffffff , V_163 ) ;
F_31 ( V_10 , 0xffffffff , V_59 ) ;
F_31 ( V_10 , 0 , V_164 ) ;
F_33 ( V_10 , 0xffffffff , V_163 ) ;
F_33 ( V_10 , 0xffffffff , V_59 ) ;
F_33 ( V_10 , 0 , V_164 ) ;
}
static void F_79 ( struct V_9 * V_10 ,
struct V_165 * V_166 )
{
struct V_165 * V_3 ;
const char * V_167 ;
int V_168 ;
unsigned int V_169 ;
int V_77 ;
V_10 -> V_68 = - 1 ;
F_80 (dn, port) {
if ( F_81 ( V_3 , L_5 , & V_169 ) )
continue;
V_168 = F_82 ( V_3 ) ;
if ( V_168 < 0 ) {
V_77 = F_83 ( V_3 , L_6 ,
& V_167 ) ;
if ( V_77 < 0 )
continue;
if ( ! strcasecmp ( V_167 , L_7 ) )
V_10 -> V_64 |= 1 << V_169 ;
}
if ( V_168 == V_170 )
V_10 -> V_68 = V_169 ;
}
}
static int F_84 ( struct V_1 * V_2 )
{
const char * V_171 [ V_172 ] = V_173 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_165 * V_166 ;
void T_9 * * V_174 ;
unsigned int V_3 ;
unsigned int V_5 ;
T_4 V_16 , V_175 ;
int V_77 ;
F_85 ( & V_10 -> V_176 ) ;
F_86 ( & V_10 -> V_15 ) ;
V_166 = V_2 -> V_177 -> V_178 -> V_179 ;
F_79 ( V_10 , V_2 -> V_177 -> V_178 ) ;
V_10 -> V_180 = F_87 ( V_166 , 0 ) ;
V_10 -> V_181 = F_87 ( V_166 , 1 ) ;
V_174 = & V_10 -> V_182 ;
for ( V_5 = 0 ; V_5 < V_172 ; V_5 ++ ) {
* V_174 = F_88 ( V_166 , V_5 ) ;
if ( * V_174 == NULL ) {
F_48 ( L_8 , V_171 [ V_5 ] ) ;
V_77 = - V_183 ;
goto V_184;
}
V_174 ++ ;
}
V_77 = F_77 ( V_10 ) ;
if ( V_77 ) {
F_48 ( L_9 , V_77 ) ;
goto V_184;
}
F_78 ( V_10 ) ;
V_77 = F_89 ( V_10 -> V_180 , F_71 , 0 ,
L_10 , V_10 ) ;
if ( V_77 < 0 ) {
F_48 ( L_11 ) ;
goto V_184;
}
V_77 = F_89 ( V_10 -> V_181 , F_73 , 0 ,
L_12 , V_10 ) ;
if ( V_77 < 0 ) {
F_48 ( L_13 ) ;
goto V_185;
}
V_16 = F_7 ( V_10 , V_186 ) ;
V_16 |= V_187 ;
F_14 ( V_10 , V_16 , V_186 ) ;
V_16 &= ~ V_187 ;
F_14 ( V_10 , V_16 , V_186 ) ;
V_10 -> V_25 . V_26 = F_7 ( V_10 , V_188 ) + 1 ;
if ( V_10 -> V_25 . V_26 > V_189 )
V_10 -> V_25 . V_26 = V_189 ;
if ( F_81 ( V_166 , L_14 ,
& V_10 -> V_25 . V_65 ) )
V_10 -> V_25 . V_65 = 1 ;
for ( V_3 = 0 ; V_3 < V_10 -> V_25 . V_26 ; V_3 ++ ) {
if ( ( 1 << V_3 ) & V_2 -> V_27 )
F_34 ( V_2 , V_3 , NULL ) ;
else if ( F_38 ( V_2 , V_3 ) )
F_15 ( V_2 , V_3 ) ;
else
F_37 ( V_2 , V_3 , NULL ) ;
}
if ( F_90 ( L_15 ) )
V_2 -> V_190 |= ( ( 1 << V_191 ) | ( 1 << 0 ) ) ;
else
V_2 -> V_190 = 0 ;
V_175 = F_19 ( V_10 , V_192 ) ;
V_10 -> V_25 . V_193 = ( V_175 >> V_194 ) &
V_195 ;
V_10 -> V_25 . V_196 = ( V_175 & V_197 ) ;
V_175 = F_19 ( V_10 , V_198 ) ;
V_10 -> V_25 . V_199 = V_175 & V_200 ;
F_91 ( L_16 ,
V_10 -> V_25 . V_193 >> 8 , V_10 -> V_25 . V_193 & 0xff ,
V_10 -> V_25 . V_196 >> 8 , V_10 -> V_25 . V_196 & 0xff ,
V_10 -> V_182 , V_10 -> V_180 , V_10 -> V_181 ) ;
return 0 ;
V_185:
F_92 ( V_10 -> V_180 , V_10 ) ;
V_184:
V_174 = & V_10 -> V_182 ;
for ( V_5 = 0 ; V_5 < V_172 ; V_5 ++ ) {
if ( * V_174 )
F_93 ( * V_174 ) ;
V_174 ++ ;
}
return V_77 ;
}
static int F_94 ( struct V_1 * V_2 , T_6 * V_128 )
{
return 0 ;
}
static T_4 F_95 ( struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
return V_10 -> V_25 . V_199 ;
}
static int F_96 ( struct V_1 * V_2 , int V_114 , int V_128 ,
int V_201 , T_7 V_13 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_77 = 0 ;
T_4 V_16 ;
V_16 = F_19 ( V_10 , V_202 ) ;
V_16 |= V_203 ;
F_20 ( V_10 , V_16 , V_202 ) ;
V_16 = 0x70 ;
V_16 <<= 2 ;
F_14 ( V_10 , V_128 , V_16 ) ;
V_16 = 0x80 << 8 | V_201 << 1 ;
V_16 <<= 2 ;
if ( V_114 )
V_77 = F_7 ( V_10 , V_16 ) ;
else
F_14 ( V_10 , V_13 , V_16 ) ;
V_16 = F_19 ( V_10 , V_202 ) ;
V_16 &= ~ V_203 ;
F_20 ( V_10 , V_16 , V_202 ) ;
return V_77 & 0xffff ;
}
static int F_97 ( struct V_1 * V_2 , int V_128 , int V_201 )
{
switch ( V_128 ) {
case 0 :
case V_191 :
return F_96 ( V_2 , 1 , V_128 , V_201 , 0 ) ;
default:
return 0xffff ;
}
}
static int F_98 ( struct V_1 * V_2 , int V_128 , int V_201 ,
T_7 V_13 )
{
switch ( V_128 ) {
case 0 :
case V_191 :
F_96 ( V_2 , 0 , V_128 , V_201 , V_13 ) ;
break;
}
return 0 ;
}
static void F_99 ( struct V_1 * V_2 , int V_3 ,
struct V_60 * V_84 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_204 = 0 , V_205 ;
const char * V_206 = NULL ;
T_4 V_16 ;
switch ( V_84 -> V_207 ) {
case V_208 :
V_206 = L_17 ;
V_204 = 1 ;
case V_209 :
if ( ! V_206 )
V_206 = L_18 ;
V_205 = V_210 ;
break;
case V_211 :
V_206 = L_19 ;
V_205 = V_212 ;
break;
case V_213 :
V_206 = L_20 ;
V_205 = V_214 ;
break;
default:
goto V_215;
}
if ( ! V_84 -> V_158 ) {
V_16 = F_19 ( V_10 , F_100 ( V_3 ) ) ;
V_16 &= ~ V_216 ;
F_20 ( V_10 , V_16 , F_100 ( V_3 ) ) ;
goto V_215;
}
V_16 = F_19 ( V_10 , F_100 ( V_3 ) ) ;
V_16 &= ~ V_217 ;
V_16 &= ~ ( V_218 << V_219 ) ;
V_16 &= ~ ( V_220 | V_221 ) ;
V_16 |= V_205 | V_216 ;
if ( V_204 )
V_16 |= V_217 ;
if ( V_84 -> V_222 ) {
if ( V_84 -> V_223 )
V_16 |= V_221 ;
V_16 |= V_220 ;
}
F_20 ( V_10 , V_16 , F_100 ( V_3 ) ) ;
F_91 ( L_21 , V_3 , V_206 ) ;
V_215:
V_16 = V_224 ;
switch ( V_84 -> V_225 ) {
case V_226 :
V_16 |= V_227 << V_228 ;
break;
case V_229 :
V_16 |= V_230 << V_228 ;
break;
}
if ( V_84 -> V_158 )
V_16 |= V_47 ;
if ( V_84 -> V_231 == V_232 )
V_16 |= V_233 ;
F_14 ( V_10 , V_16 , F_101 ( V_3 ) ) ;
}
static void F_102 ( struct V_1 * V_2 , int V_3 ,
struct V_234 * V_235 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_231 , V_222 ;
T_4 V_16 ;
V_231 = F_7 ( V_10 , V_236 ) ;
V_222 = F_7 ( V_10 , V_237 ) ;
V_235 -> V_158 = 0 ;
if ( V_3 == V_10 -> V_68 ) {
V_235 -> V_158 = V_10 -> V_70 [ V_3 ] . V_158 ;
if ( ! V_235 -> V_158 )
F_103 ( V_2 -> V_146 [ V_3 ] ) ;
V_235 -> V_231 = 1 ;
} else {
V_235 -> V_158 = 1 ;
V_235 -> V_231 = ! ! ( V_231 & ( 1 << V_3 ) ) ;
}
V_16 = F_7 ( V_10 , F_101 ( V_3 ) ) ;
V_16 |= V_224 ;
if ( V_235 -> V_158 )
V_16 |= V_47 ;
else
V_16 &= ~ V_47 ;
F_14 ( V_10 , V_16 , F_101 ( V_3 ) ) ;
if ( ( V_222 & ( 1 << V_3 ) ) &&
( V_222 & ( 1 << ( V_3 + V_238 ) ) ) ) {
V_235 -> V_223 = 1 ;
V_235 -> V_222 = 1 ;
}
if ( V_222 & ( 1 << V_3 ) )
V_235 -> V_222 = 1 ;
}
static int F_104 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_3 ;
F_78 ( V_10 ) ;
for ( V_3 = 0 ; V_3 < V_189 ; V_3 ++ ) {
if ( ( 1 << V_3 ) & V_2 -> V_27 ||
F_38 ( V_2 , V_3 ) )
F_37 ( V_2 , V_3 , NULL ) ;
}
return 0 ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_3 ;
int V_77 ;
V_77 = F_77 ( V_10 ) ;
if ( V_77 ) {
F_48 ( L_22 , V_111 ) ;
return V_77 ;
}
if ( V_10 -> V_25 . V_65 == 1 )
F_18 ( V_2 , true ) ;
for ( V_3 = 0 ; V_3 < V_189 ; V_3 ++ ) {
if ( ( 1 << V_3 ) & V_2 -> V_27 )
F_34 ( V_2 , V_3 , NULL ) ;
else if ( F_38 ( V_2 , V_3 ) )
F_15 ( V_2 , V_3 ) ;
}
return 0 ;
}
static void F_106 ( struct V_1 * V_2 , int V_3 ,
struct V_239 * V_240 )
{
struct V_93 * V_76 = V_2 -> V_62 [ V_2 -> V_63 ] . V_241 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_239 V_242 ;
V_76 -> V_243 -> V_244 ( V_76 , & V_242 ) ;
V_240 -> V_78 = V_242 . V_78 ;
memset ( & V_240 -> V_245 , 0 , sizeof( V_240 -> V_245 ) ) ;
if ( V_242 . V_246 & V_247 )
memcpy ( & V_240 -> V_245 , V_242 . V_245 , sizeof( V_240 -> V_245 ) ) ;
if ( V_10 -> V_74 & ( 1 << V_3 ) )
V_240 -> V_246 = V_242 . V_246 ;
else
V_240 -> V_246 = 0 ;
}
static int F_107 ( struct V_1 * V_2 , int V_3 ,
struct V_239 * V_240 )
{
struct V_93 * V_76 = V_2 -> V_62 [ V_2 -> V_63 ] . V_241 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_5 V_24 = V_2 -> V_62 [ V_2 -> V_63 ] . V_24 ;
struct V_239 V_242 ;
V_76 -> V_243 -> V_244 ( V_76 , & V_242 ) ;
if ( V_240 -> V_246 & ~ V_242 . V_78 )
return - V_117 ;
if ( V_240 -> V_246 )
V_10 -> V_74 |= ( 1 << V_3 ) ;
else
V_10 -> V_74 &= ~ ( 1 << V_3 ) ;
if ( V_10 -> V_74 && V_10 -> V_74 != ( 1 << V_24 ) )
V_10 -> V_74 |= ( 1 << V_24 ) ;
else
V_10 -> V_74 &= ~ ( 1 << V_24 ) ;
return V_76 -> V_243 -> V_248 ( V_76 , V_240 ) ;
}
static int T_10 F_108 ( void )
{
F_109 ( & V_249 ) ;
return 0 ;
}
static void T_11 F_110 ( void )
{
F_111 ( & V_249 ) ;
}
