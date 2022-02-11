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
static int F_43 ( struct V_9 * V_10 )
{
unsigned int V_86 = 1000 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_87 ) ;
V_16 |= V_88 | V_89 | V_90 | V_91 ;
F_14 ( V_10 , V_16 , V_87 ) ;
do {
V_16 = F_7 ( V_10 , V_87 ) ;
if ( ! ( V_16 & V_91 ) )
break;
F_44 () ;
} while ( V_86 -- );
if ( ! V_86 )
return - V_92 ;
F_14 ( V_10 , 0 , V_87 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
F_14 ( V_10 , V_3 , V_93 ) ;
return F_43 ( V_10 ) ;
}
static int F_46 ( struct V_9 * V_10 , T_6 V_94 )
{
F_14 ( V_10 , V_94 , V_95 ) ;
return F_43 ( V_10 ) ;
}
static int F_47 ( struct V_9 * V_10 )
{
unsigned int V_86 = 10 ;
T_4 V_16 ;
do {
V_16 = F_7 ( V_10 , V_96 ) ;
if ( ! ( V_16 & V_97 ) )
return 0 ;
F_48 ( 1000 , 2000 ) ;
} while ( V_86 -- );
return - V_92 ;
}
static int F_49 ( struct V_9 * V_10 , T_7 V_98 )
{
F_14 ( V_10 , V_97 | V_98 , V_96 ) ;
return F_47 ( V_10 ) ;
}
static void F_50 ( struct V_9 * V_10 , T_6 V_94 ,
struct V_99 * V_100 )
{
int V_77 ;
F_14 ( V_10 , V_94 & V_101 , V_102 ) ;
F_14 ( V_10 , V_100 -> V_103 << V_104 | V_100 -> V_105 ,
V_106 ) ;
V_77 = F_49 ( V_10 , V_107 ) ;
if ( V_77 )
F_51 ( L_2 ) ;
}
static int F_52 ( struct V_9 * V_10 , T_6 V_94 ,
struct V_99 * V_100 )
{
T_4 V_108 ;
int V_77 ;
F_14 ( V_10 , V_94 & V_101 , V_102 ) ;
V_77 = F_49 ( V_10 , V_109 ) ;
if ( V_77 )
return V_77 ;
V_108 = F_7 ( V_10 , V_106 ) ;
V_100 -> V_105 = V_108 & V_110 ;
V_100 -> V_103 = ( V_108 >> V_104 ) & V_111 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , int V_3 ,
struct V_112 * V_113 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_5 V_24 = V_2 -> V_62 -> V_24 ;
unsigned int V_5 ;
T_4 V_16 , V_114 ;
V_16 = F_7 ( V_10 , V_115 ) ;
V_16 &= ~ F_54 ( V_3 ) ;
if ( ( V_16 & F_54 ( V_24 ) ) == F_54 ( V_24 ) )
V_16 &= ~ F_54 ( V_24 ) ;
F_14 ( V_10 , V_16 , V_115 ) ;
V_10 -> V_70 [ V_3 ] . V_116 = V_113 ;
V_114 = F_7 ( V_10 , F_13 ( V_3 ) ) ;
for ( V_5 = 0 ; V_5 < V_10 -> V_25 . V_26 ; V_5 ++ ) {
if ( V_10 -> V_70 [ V_5 ] . V_116 != V_113 )
continue;
V_16 = F_7 ( V_10 , F_13 ( V_5 ) ) ;
V_16 |= 1 << V_3 ;
F_14 ( V_10 , V_16 , F_13 ( V_5 ) ) ;
V_10 -> V_70 [ V_5 ] . V_71 = V_16 ;
V_114 |= 1 << V_5 ;
}
F_14 ( V_10 , V_114 , F_13 ( V_3 ) ) ;
V_10 -> V_70 [ V_3 ] . V_71 = V_114 ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_112 * V_113 = V_10 -> V_70 [ V_3 ] . V_116 ;
T_5 V_24 = V_2 -> V_62 -> V_24 ;
unsigned int V_5 ;
T_4 V_16 , V_114 ;
V_114 = F_7 ( V_10 , F_13 ( V_3 ) ) ;
for ( V_5 = 0 ; V_5 < V_10 -> V_25 . V_26 ; V_5 ++ ) {
if ( V_10 -> V_70 [ V_5 ] . V_116 != V_113 )
continue;
V_16 = F_7 ( V_10 , F_13 ( V_5 ) ) ;
V_16 &= ~ ( 1 << V_3 ) ;
F_14 ( V_10 , V_16 , F_13 ( V_5 ) ) ;
V_10 -> V_70 [ V_3 ] . V_71 = V_16 ;
if ( V_3 != V_5 )
V_114 &= ~ ( 1 << V_5 ) ;
}
F_14 ( V_10 , V_114 , F_13 ( V_3 ) ) ;
V_10 -> V_70 [ V_3 ] . V_71 = V_114 ;
V_10 -> V_70 [ V_3 ] . V_116 = NULL ;
V_16 = F_7 ( V_10 , V_115 ) ;
V_16 |= F_54 ( V_3 ) ;
if ( ! ( V_16 & F_54 ( V_24 ) ) )
V_16 |= F_54 ( V_24 ) ;
F_14 ( V_10 , V_16 , V_115 ) ;
}
static void F_56 ( struct V_1 * V_2 , int V_3 ,
T_7 V_66 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_7 V_117 , V_118 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , F_35 ( V_3 ) ) ;
V_118 = V_16 & ( V_119 << V_120 ) ;
switch ( V_66 ) {
case V_121 :
V_117 = V_122 ;
break;
case V_123 :
V_117 = V_124 ;
break;
case V_125 :
V_117 = V_126 ;
break;
case V_127 :
V_117 = V_128 ;
break;
case V_129 :
V_117 = V_130 ;
break;
default:
F_51 ( L_3 , V_131 , V_66 ) ;
return;
}
if ( V_118 != V_117 ) {
if ( V_118 >= V_126 &&
V_117 <= V_124 ) {
if ( F_45 ( V_2 , V_3 ) ) {
F_51 ( L_4 , V_131 ) ;
return;
}
}
}
V_16 = F_7 ( V_10 , F_35 ( V_3 ) ) ;
V_16 &= ~ ( V_119 << V_120 ) ;
V_16 |= V_117 ;
F_14 ( V_10 , V_16 , F_35 ( V_3 ) ) ;
}
static int F_57 ( struct V_9 * V_10 )
{
unsigned int V_86 = 10 ;
T_4 V_16 ;
do {
V_16 = F_7 ( V_10 , V_132 ) ;
if ( ! ( V_16 & V_133 ) )
return 0 ;
F_48 ( 1000 , 2000 ) ;
} while ( V_86 -- );
return - V_92 ;
}
static int F_58 ( struct V_9 * V_10 , unsigned int V_98 )
{
T_4 V_134 ;
if ( V_98 > V_135 )
return - V_136 ;
V_134 = F_7 ( V_10 , V_132 ) ;
V_134 &= ~ V_137 ;
V_134 |= V_133 ;
if ( V_98 )
V_134 |= V_135 ;
else
V_134 &= ~ V_135 ;
F_14 ( V_10 , V_134 , V_132 ) ;
return F_57 ( V_10 ) ;
}
static int F_59 ( struct V_9 * V_10 , T_3 V_138 ,
T_6 V_94 , struct V_139 * V_140 , T_7 * V_141 ,
bool V_142 )
{
unsigned int V_5 ;
int V_77 ;
V_77 = F_57 ( V_10 ) ;
if ( V_77 )
return V_77 ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
T_3 V_143 ;
T_4 V_144 ;
V_143 = F_6 ( V_10 , F_60 ( V_5 ) ) ;
V_144 = F_7 ( V_10 , F_61 ( V_5 ) ) ;
F_62 ( V_140 , V_143 , V_144 ) ;
if ( V_140 -> V_142 && V_142 ) {
* V_141 = V_5 ;
return 0 ;
}
if ( ! V_142 && ( V_143 & V_138 ) )
return 0 ;
}
return - V_145 ;
}
static int F_63 ( struct V_9 * V_10 , int V_98 , int V_3 ,
const unsigned char * V_146 , T_6 V_94 , bool V_142 )
{
struct V_139 V_140 ;
T_4 V_144 ;
T_3 V_138 , V_143 = 0 ;
T_7 V_141 = 0 ;
int V_77 ;
V_138 = F_64 ( V_146 ) ;
F_65 ( V_10 , V_138 , V_147 ) ;
F_14 ( V_10 , V_94 , V_148 ) ;
V_77 = F_58 ( V_10 , 1 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_59 ( V_10 , V_138 , V_94 , & V_140 , & V_141 , V_142 ) ;
if ( V_98 )
return V_77 ;
if ( V_77 ) {
V_144 = 0 ;
V_141 = 0 ;
}
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_140 . V_3 = V_3 ;
V_140 . V_142 = V_142 ;
V_140 . V_94 = V_94 ;
V_140 . V_149 = true ;
memcpy ( V_140 . V_138 , V_146 , V_150 ) ;
F_66 ( & V_143 , & V_144 , & V_140 ) ;
F_65 ( V_10 , V_143 , F_60 ( V_141 ) ) ;
F_14 ( V_10 , V_144 , F_61 ( V_141 ) ) ;
V_77 = F_58 ( V_10 , 0 ) ;
if ( V_77 )
return V_77 ;
return F_59 ( V_10 , V_138 , V_94 , & V_140 , & V_141 , V_142 ) ;
}
static int F_67 ( struct V_1 * V_2 , int V_3 ,
const struct V_151 * V_152 ,
struct V_153 * V_154 )
{
return 0 ;
}
static void F_68 ( struct V_1 * V_2 , int V_3 ,
const struct V_151 * V_152 ,
struct V_153 * V_154 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
if ( F_63 ( V_10 , 0 , V_3 , V_152 -> V_146 , V_152 -> V_94 , true ) )
F_51 ( L_5 , V_131 ) ;
}
static int F_69 ( struct V_1 * V_2 , int V_3 ,
const struct V_151 * V_152 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
return F_63 ( V_10 , 0 , V_3 , V_152 -> V_146 , V_152 -> V_94 , false ) ;
}
static int F_70 ( struct V_9 * V_10 )
{
unsigned V_86 = 1000 ;
T_4 V_16 ;
do {
V_16 = F_7 ( V_10 , V_155 ) ;
if ( ! ( V_16 & V_156 ) )
return 0 ;
if ( V_16 & V_157 )
return 0 ;
F_48 ( 1000 , 2000 ) ;
} while ( V_86 -- );
return - V_92 ;
}
static void F_71 ( struct V_9 * V_10 , T_7 V_141 ,
struct V_139 * V_140 )
{
T_3 V_143 ;
T_4 V_144 ;
V_143 = F_6 ( V_10 , F_72 ( V_141 ) ) ;
V_144 = F_7 ( V_10 , F_73 ( V_141 ) ) ;
F_62 ( V_140 , V_143 , V_144 ) ;
}
static int F_74 ( struct V_112 * V_158 , int V_3 ,
const struct V_139 * V_140 ,
struct V_151 * V_152 ,
int (* F_75)( struct V_159 * V_160 ) )
{
if ( ! V_140 -> V_142 )
return 0 ;
if ( V_3 != V_140 -> V_3 )
return 0 ;
F_76 ( V_152 -> V_146 , V_140 -> V_138 ) ;
V_152 -> V_94 = V_140 -> V_94 ;
V_152 -> V_161 = V_140 -> V_149 ? V_162 : V_163 ;
return F_75 ( & V_152 -> V_160 ) ;
}
static int F_77 ( struct V_1 * V_2 , int V_3 ,
struct V_151 * V_152 ,
int (* F_75)( struct V_159 * V_160 ) )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_112 * V_158 = V_2 -> V_164 [ V_3 ] . V_165 ;
struct V_139 V_166 [ 2 ] ;
unsigned int V_167 = 0 ;
int V_77 ;
F_14 ( V_10 , V_156 , V_155 ) ;
do {
V_77 = F_70 ( V_10 ) ;
if ( V_77 )
return V_77 ;
F_71 ( V_10 , 0 , & V_166 [ 0 ] ) ;
V_77 = F_74 ( V_158 , V_3 , & V_166 [ 0 ] , V_152 , F_75 ) ;
if ( V_77 )
return V_77 ;
F_71 ( V_10 , 1 , & V_166 [ 1 ] ) ;
V_77 = F_74 ( V_158 , V_3 , & V_166 [ 1 ] , V_152 , F_75 ) ;
if ( V_77 )
return V_77 ;
if ( ! V_166 [ 0 ] . V_142 && ! V_166 [ 1 ] . V_142 )
break;
} while ( V_167 ++ < V_168 );
return 0 ;
}
static int F_78 ( struct V_9 * V_10 , int V_98 , int V_146 ,
int V_169 , T_6 V_13 )
{
int V_77 = 0 ;
T_4 V_16 ;
V_16 = F_19 ( V_10 , V_170 ) ;
V_16 |= V_171 ;
F_20 ( V_10 , V_16 , V_170 ) ;
V_16 = 0x70 ;
V_16 <<= 2 ;
F_14 ( V_10 , V_146 , V_16 ) ;
V_16 = 0x80 << 8 | V_169 << 1 ;
V_16 <<= 2 ;
if ( V_98 )
V_77 = F_7 ( V_10 , V_16 ) ;
else
F_14 ( V_10 , V_13 , V_16 ) ;
V_16 = F_19 ( V_10 , V_170 ) ;
V_16 &= ~ V_171 ;
F_20 ( V_10 , V_16 , V_170 ) ;
return V_77 & 0xffff ;
}
static int F_79 ( struct V_172 * V_173 , int V_146 , int V_169 )
{
struct V_9 * V_10 = V_173 -> V_10 ;
if ( V_146 == V_174 && V_10 -> V_175 & F_54 ( V_146 ) )
return F_78 ( V_10 , 1 , V_146 , V_169 , 0 ) ;
else
return F_80 ( V_10 -> V_176 , V_146 , V_169 ) ;
}
static int F_81 ( struct V_172 * V_173 , int V_146 , int V_169 ,
T_6 V_13 )
{
struct V_9 * V_10 = V_173 -> V_10 ;
if ( V_146 == V_174 && V_10 -> V_175 & F_54 ( V_146 ) )
F_78 ( V_10 , 0 , V_146 , V_169 , V_13 ) ;
else
F_82 ( V_10 -> V_176 , V_146 , V_169 , V_13 ) ;
return 0 ;
}
static T_8 F_83 ( int V_177 , void * V_178 )
{
struct V_9 * V_10 = V_178 ;
V_10 -> V_179 = F_84 ( V_10 , V_180 ) &
~ V_10 -> V_181 ;
F_31 ( V_10 , V_10 -> V_179 , V_59 ) ;
return V_182 ;
}
static T_8 F_85 ( int V_177 , void * V_178 )
{
struct V_9 * V_10 = V_178 ;
V_10 -> V_183 = F_86 ( V_10 , V_180 ) &
~ V_10 -> V_184 ;
F_33 ( V_10 , V_10 -> V_183 , V_59 ) ;
if ( V_10 -> V_183 & F_87 ( V_57 ) )
V_10 -> V_70 [ 7 ] . V_185 = 1 ;
if ( V_10 -> V_183 & F_88 ( V_57 ) )
V_10 -> V_70 [ 7 ] . V_185 = 0 ;
return V_182 ;
}
static int F_89 ( struct V_9 * V_10 )
{
unsigned int V_86 = 1000 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_186 ) ;
V_16 |= V_187 | V_188 | V_189 ;
F_14 ( V_10 , V_16 , V_186 ) ;
do {
V_16 = F_7 ( V_10 , V_186 ) ;
if ( ! ( V_16 & V_187 ) )
break;
F_48 ( 1000 , 2000 ) ;
} while ( V_86 -- > 0 );
if ( V_86 == 0 )
return - V_92 ;
return 0 ;
}
static void F_90 ( struct V_9 * V_10 )
{
F_31 ( V_10 , 0xffffffff , V_190 ) ;
F_31 ( V_10 , 0xffffffff , V_59 ) ;
F_31 ( V_10 , 0 , V_191 ) ;
F_33 ( V_10 , 0xffffffff , V_190 ) ;
F_33 ( V_10 , 0xffffffff , V_59 ) ;
F_33 ( V_10 , 0 , V_191 ) ;
}
static void F_91 ( struct V_9 * V_10 ,
struct V_192 * V_193 )
{
struct V_192 * V_3 ;
const char * V_194 ;
int V_195 ;
unsigned int V_196 ;
int V_77 ;
V_10 -> V_68 = - 1 ;
F_92 (dn, port) {
if ( F_93 ( V_3 , L_6 , & V_196 ) )
continue;
V_195 = F_94 ( V_3 ) ;
if ( V_195 < 0 ) {
V_77 = F_95 ( V_3 , L_7 ,
& V_194 ) ;
if ( V_77 < 0 )
continue;
if ( ! strcasecmp ( V_194 , L_8 ) )
V_10 -> V_64 |= 1 << V_196 ;
}
if ( V_195 == V_197 )
V_10 -> V_68 = V_196 ;
}
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_192 * V_193 ;
static int V_63 ;
int V_198 ;
V_193 = F_97 ( NULL , NULL , L_9 ) ;
V_10 -> V_176 = F_98 ( V_193 ) ;
if ( ! V_10 -> V_176 )
return - V_199 ;
F_99 ( & V_10 -> V_176 -> V_158 ) ;
V_10 -> V_200 = V_193 ;
V_10 -> V_201 = F_100 ( V_2 -> V_158 ) ;
if ( ! V_10 -> V_201 )
return - V_202 ;
V_10 -> V_201 -> V_10 = V_10 ;
V_10 -> V_201 -> V_203 = L_10 ;
V_10 -> V_201 -> V_204 = F_79 ;
V_10 -> V_201 -> V_205 = F_81 ;
snprintf ( V_10 -> V_201 -> V_206 , V_207 , L_11 ,
V_63 ++ ) ;
V_10 -> V_201 -> V_158 . V_208 = V_193 ;
if ( F_101 ( L_12 ) )
V_10 -> V_175 |= ( 1 << V_174 ) ;
else
V_10 -> V_175 = 0 ;
V_2 -> V_209 = V_10 -> V_175 ;
V_2 -> V_201 = V_10 -> V_201 ;
V_10 -> V_201 -> V_210 = V_2 -> V_158 -> V_210 ;
V_10 -> V_201 -> V_211 = ~ V_10 -> V_175 ;
if ( V_193 )
V_198 = F_102 ( V_10 -> V_201 , V_193 ) ;
else
V_198 = F_103 ( V_10 -> V_201 ) ;
if ( V_198 )
F_104 ( V_193 ) ;
return V_198 ;
}
static void F_105 ( struct V_9 * V_10 )
{
F_106 ( V_10 -> V_201 ) ;
if ( V_10 -> V_200 )
F_104 ( V_10 -> V_200 ) ;
}
static int F_107 ( struct V_1 * V_2 , T_7 * V_146 )
{
return 0 ;
}
static T_4 F_108 ( struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
return V_10 -> V_25 . V_212 ;
}
static void F_109 ( struct V_1 * V_2 , int V_3 ,
struct V_60 * V_84 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_213 = 0 , V_214 ;
const char * V_215 = NULL ;
T_4 V_16 ;
switch ( V_84 -> V_216 ) {
case V_217 :
V_215 = L_13 ;
V_213 = 1 ;
case V_218 :
if ( ! V_215 )
V_215 = L_14 ;
V_214 = V_219 ;
break;
case V_220 :
V_215 = L_15 ;
V_214 = V_221 ;
break;
case V_222 :
V_215 = L_16 ;
V_214 = V_223 ;
break;
default:
goto V_224;
}
if ( ! V_84 -> V_185 ) {
V_16 = F_19 ( V_10 , F_110 ( V_3 ) ) ;
V_16 &= ~ V_225 ;
F_20 ( V_10 , V_16 , F_110 ( V_3 ) ) ;
goto V_224;
}
V_16 = F_19 ( V_10 , F_110 ( V_3 ) ) ;
V_16 &= ~ V_226 ;
V_16 &= ~ ( V_227 << V_228 ) ;
V_16 &= ~ ( V_229 | V_230 ) ;
V_16 |= V_214 | V_225 ;
if ( V_213 )
V_16 |= V_226 ;
if ( V_84 -> V_231 ) {
if ( V_84 -> V_232 )
V_16 |= V_230 ;
V_16 |= V_229 ;
}
F_20 ( V_10 , V_16 , F_110 ( V_3 ) ) ;
F_111 ( L_17 , V_3 , V_215 ) ;
V_224:
V_16 = V_233 ;
switch ( V_84 -> V_234 ) {
case V_235 :
V_16 |= V_236 << V_237 ;
break;
case V_238 :
V_16 |= V_239 << V_237 ;
break;
}
if ( V_84 -> V_185 )
V_16 |= V_47 ;
if ( V_84 -> V_240 == V_241 )
V_16 |= V_242 ;
F_14 ( V_10 , V_16 , F_112 ( V_3 ) ) ;
}
static void F_113 ( struct V_1 * V_2 , int V_3 ,
struct V_243 * V_244 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_240 , V_231 ;
T_4 V_16 ;
V_240 = F_7 ( V_10 , V_245 ) ;
V_231 = F_7 ( V_10 , V_246 ) ;
V_244 -> V_185 = 0 ;
if ( V_3 == V_10 -> V_68 ) {
V_244 -> V_185 = V_10 -> V_70 [ V_3 ] . V_185 ;
if ( ! V_244 -> V_185 )
F_114 ( V_2 -> V_164 [ V_3 ] . V_165 ) ;
V_244 -> V_240 = 1 ;
} else {
V_244 -> V_185 = 1 ;
V_244 -> V_240 = ! ! ( V_240 & ( 1 << V_3 ) ) ;
}
V_16 = F_7 ( V_10 , F_112 ( V_3 ) ) ;
V_16 |= V_233 ;
if ( V_244 -> V_185 )
V_16 |= V_47 ;
else
V_16 &= ~ V_47 ;
F_14 ( V_10 , V_16 , F_112 ( V_3 ) ) ;
if ( ( V_231 & ( 1 << V_3 ) ) &&
( V_231 & ( 1 << ( V_3 + V_247 ) ) ) ) {
V_244 -> V_232 = 1 ;
V_244 -> V_231 = 1 ;
}
if ( V_231 & ( 1 << V_3 ) )
V_244 -> V_231 = 1 ;
}
static int F_115 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_3 ;
F_90 ( V_10 ) ;
for ( V_3 = 0 ; V_3 < V_248 ; V_3 ++ ) {
if ( ( 1 << V_3 ) & V_2 -> V_27 ||
F_38 ( V_2 , V_3 ) )
F_37 ( V_2 , V_3 , NULL ) ;
}
return 0 ;
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_3 ;
int V_77 ;
V_77 = F_89 ( V_10 ) ;
if ( V_77 ) {
F_51 ( L_18 , V_131 ) ;
return V_77 ;
}
if ( V_10 -> V_25 . V_65 == 1 )
F_18 ( V_2 , true ) ;
for ( V_3 = 0 ; V_3 < V_248 ; V_3 ++ ) {
if ( ( 1 << V_3 ) & V_2 -> V_27 )
F_34 ( V_2 , V_3 , NULL ) ;
else if ( F_38 ( V_2 , V_3 ) )
F_15 ( V_2 , V_3 ) ;
}
return 0 ;
}
static void F_117 ( struct V_1 * V_2 , int V_3 ,
struct V_249 * V_250 )
{
struct V_112 * V_76 = V_2 -> V_62 [ V_2 -> V_63 ] . V_251 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_249 V_252 ;
V_76 -> V_253 -> V_254 ( V_76 , & V_252 ) ;
V_250 -> V_78 = V_252 . V_78 ;
memset ( & V_250 -> V_255 , 0 , sizeof( V_250 -> V_255 ) ) ;
if ( V_252 . V_256 & V_257 )
memcpy ( & V_250 -> V_255 , V_252 . V_255 , sizeof( V_250 -> V_255 ) ) ;
if ( V_10 -> V_74 & ( 1 << V_3 ) )
V_250 -> V_256 = V_252 . V_256 ;
else
V_250 -> V_256 = 0 ;
}
static int F_118 ( struct V_1 * V_2 , int V_3 ,
struct V_249 * V_250 )
{
struct V_112 * V_76 = V_2 -> V_62 [ V_2 -> V_63 ] . V_251 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_5 V_24 = V_2 -> V_62 [ V_2 -> V_63 ] . V_24 ;
struct V_249 V_252 ;
V_76 -> V_253 -> V_254 ( V_76 , & V_252 ) ;
if ( V_250 -> V_256 & ~ V_252 . V_78 )
return - V_136 ;
if ( V_250 -> V_256 )
V_10 -> V_74 |= ( 1 << V_3 ) ;
else
V_10 -> V_74 &= ~ ( 1 << V_3 ) ;
if ( V_10 -> V_74 && V_10 -> V_74 != ( 1 << V_24 ) )
V_10 -> V_74 |= ( 1 << V_24 ) ;
else
V_10 -> V_74 &= ~ ( 1 << V_24 ) ;
return V_76 -> V_253 -> V_258 ( V_76 , V_250 ) ;
}
static void F_119 ( struct V_9 * V_10 , bool V_48 )
{
T_4 V_259 , V_260 , V_261 , V_262 , V_263 ;
V_259 = F_7 ( V_10 , V_36 ) ;
V_260 = F_7 ( V_10 , V_264 ) ;
V_261 = F_7 ( V_10 , V_265 ) ;
V_262 = F_7 ( V_10 , V_266 ) ;
V_263 = F_7 ( V_10 , V_267 ) ;
V_259 &= ~ V_268 ;
if ( V_48 ) {
V_260 |= V_269 | V_270 ;
V_261 |= V_271 | V_272 ;
V_262 &= ~ ( V_273 << V_274 ) ;
V_262 |= V_275 ;
V_263 |= V_276 | V_277 ;
} else {
V_260 &= ~ ( V_269 | V_270 ) ;
V_261 &= ~ ( V_271 | V_272 ) ;
V_262 &= ~ ( V_273 << V_274 ) ;
V_263 &= ~ ( V_276 | V_277 ) ;
V_262 |= V_278 ;
}
F_14 ( V_10 , V_260 , V_264 ) ;
F_14 ( V_10 , V_261 , V_265 ) ;
F_14 ( V_10 , 0 , V_279 ) ;
F_14 ( V_10 , V_262 , V_266 ) ;
F_14 ( V_10 , V_263 , V_267 ) ;
F_14 ( V_10 , V_259 , V_36 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_3 ;
F_49 ( V_10 , V_280 ) ;
for ( V_3 = 0 ; V_3 < V_10 -> V_25 . V_26 ; V_3 ++ ) {
if ( ! ( ( 1 << V_3 ) & V_2 -> V_27 ) )
continue;
F_14 ( V_10 , 1 , F_121 ( V_3 ) ) ;
}
}
static int F_122 ( struct V_1 * V_2 , int V_3 ,
bool V_281 )
{
return 0 ;
}
static int F_123 ( struct V_1 * V_2 , int V_3 ,
const struct V_282 * V_100 ,
struct V_153 * V_154 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
F_119 ( V_10 , true ) ;
return 0 ;
}
static void F_124 ( struct V_1 * V_2 , int V_3 ,
const struct V_282 * V_100 ,
struct V_153 * V_154 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
bool V_283 = V_100 -> V_284 & V_285 ;
bool V_286 = V_100 -> V_284 & V_287 ;
T_5 V_24 = V_2 -> V_62 -> V_24 ;
struct V_99 * V_288 ;
T_6 V_94 ;
for ( V_94 = V_100 -> V_289 ; V_94 <= V_100 -> V_290 ; ++ V_94 ) {
V_288 = & V_10 -> V_291 [ V_94 ] ;
F_52 ( V_10 , V_94 , V_288 ) ;
V_288 -> V_105 |= F_54 ( V_3 ) | F_54 ( V_24 ) ;
if ( V_283 )
V_288 -> V_103 |= F_54 ( V_3 ) | F_54 ( V_24 ) ;
else
V_288 -> V_103 &= ~ ( F_54 ( V_3 ) | F_54 ( V_24 ) ) ;
F_50 ( V_10 , V_94 , V_288 ) ;
F_46 ( V_10 , V_94 ) ;
}
if ( V_286 ) {
F_14 ( V_10 , V_100 -> V_290 , F_121 ( V_3 ) ) ;
F_14 ( V_10 , V_100 -> V_290 ,
F_121 ( V_24 ) ) ;
F_46 ( V_10 , V_94 ) ;
}
}
static int F_125 ( struct V_1 * V_2 , int V_3 ,
const struct V_282 * V_100 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
bool V_283 = V_100 -> V_284 & V_285 ;
T_5 V_24 = V_2 -> V_62 -> V_24 ;
struct V_99 * V_288 ;
T_6 V_94 , V_286 ;
int V_77 ;
V_286 = F_7 ( V_10 , F_121 ( V_3 ) ) ;
for ( V_94 = V_100 -> V_289 ; V_94 <= V_100 -> V_290 ; ++ V_94 ) {
V_288 = & V_10 -> V_291 [ V_94 ] ;
V_77 = F_52 ( V_10 , V_94 , V_288 ) ;
if ( V_77 )
return V_77 ;
V_288 -> V_105 &= ~ F_54 ( V_3 ) ;
if ( ( V_288 -> V_105 & F_54 ( V_24 ) ) == F_54 ( V_24 ) )
V_288 -> V_105 = 0 ;
if ( V_286 == V_94 )
V_286 = 0 ;
if ( V_283 ) {
V_288 -> V_103 &= ~ F_54 ( V_3 ) ;
if ( ( V_288 -> V_103 & F_54 ( V_3 ) ) == F_54 ( V_24 ) )
V_288 -> V_103 = 0 ;
}
F_50 ( V_10 , V_94 , V_288 ) ;
F_46 ( V_10 , V_94 ) ;
}
F_14 ( V_10 , V_286 , F_121 ( V_3 ) ) ;
F_14 ( V_10 , V_286 , F_121 ( V_24 ) ) ;
F_46 ( V_10 , V_94 ) ;
return 0 ;
}
static int F_126 ( struct V_1 * V_2 , int V_3 ,
struct V_282 * V_100 ,
int (* F_75)( struct V_159 * V_160 ) )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_292 * V_76 = & V_10 -> V_70 [ V_3 ] ;
struct V_99 * V_288 ;
T_6 V_94 , V_286 ;
int V_198 = 0 ;
V_286 = F_7 ( V_10 , F_121 ( V_3 ) ) ;
for ( V_94 = 0 ; V_94 < V_293 ; V_94 ++ ) {
V_288 = & V_10 -> V_291 [ V_94 ] ;
if ( ! ( V_288 -> V_105 & F_54 ( V_3 ) ) )
continue;
V_100 -> V_289 = V_100 -> V_290 = V_94 ;
V_100 -> V_284 = 0 ;
if ( V_288 -> V_103 & F_54 ( V_3 ) )
V_100 -> V_284 |= V_285 ;
if ( V_76 -> V_286 == V_94 )
V_100 -> V_284 |= V_287 ;
V_198 = F_75 ( & V_100 -> V_160 ) ;
if ( V_198 )
break;
}
return V_198 ;
}
static int F_127 ( struct V_1 * V_2 )
{
const char * V_294 [ V_295 ] = V_296 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_192 * V_193 ;
void T_9 * * V_297 ;
unsigned int V_3 ;
unsigned int V_5 ;
T_4 V_16 , V_298 ;
int V_77 ;
F_128 ( & V_10 -> V_299 ) ;
F_129 ( & V_10 -> V_15 ) ;
V_193 = V_2 -> V_300 -> V_208 -> V_210 ;
F_91 ( V_10 , V_2 -> V_300 -> V_208 ) ;
V_10 -> V_301 = F_130 ( V_193 , 0 ) ;
V_10 -> V_302 = F_130 ( V_193 , 1 ) ;
V_297 = & V_10 -> V_303 ;
for ( V_5 = 0 ; V_5 < V_295 ; V_5 ++ ) {
* V_297 = F_131 ( V_193 , V_5 ) ;
if ( * V_297 == NULL ) {
F_51 ( L_19 , V_294 [ V_5 ] ) ;
V_77 = - V_202 ;
goto V_304;
}
V_297 ++ ;
}
V_77 = F_89 ( V_10 ) ;
if ( V_77 ) {
F_51 ( L_20 , V_77 ) ;
goto V_304;
}
V_77 = F_96 ( V_2 ) ;
if ( V_77 ) {
F_51 ( L_21 ) ;
goto V_304;
}
F_90 ( V_10 ) ;
V_77 = F_132 ( V_10 -> V_301 , F_83 , 0 ,
L_22 , V_10 ) ;
if ( V_77 < 0 ) {
F_51 ( L_23 ) ;
goto V_305;
}
V_77 = F_132 ( V_10 -> V_302 , F_85 , 0 ,
L_24 , V_10 ) ;
if ( V_77 < 0 ) {
F_51 ( L_25 ) ;
goto V_306;
}
V_16 = F_7 ( V_10 , V_307 ) ;
V_16 |= V_308 ;
F_14 ( V_10 , V_16 , V_307 ) ;
V_16 &= ~ V_308 ;
F_14 ( V_10 , V_16 , V_307 ) ;
V_10 -> V_25 . V_26 = F_7 ( V_10 , V_309 ) + 1 ;
if ( V_10 -> V_25 . V_26 > V_248 )
V_10 -> V_25 . V_26 = V_248 ;
if ( F_93 ( V_193 , L_26 ,
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
F_120 ( V_2 ) ;
V_298 = F_19 ( V_10 , V_310 ) ;
V_10 -> V_25 . V_311 = ( V_298 >> V_312 ) &
V_313 ;
V_10 -> V_25 . V_314 = ( V_298 & V_315 ) ;
V_298 = F_19 ( V_10 , V_316 ) ;
V_10 -> V_25 . V_212 = V_298 & V_317 ;
F_111 ( L_27 ,
V_10 -> V_25 . V_311 >> 8 , V_10 -> V_25 . V_311 & 0xff ,
V_10 -> V_25 . V_314 >> 8 , V_10 -> V_25 . V_314 & 0xff ,
V_10 -> V_303 , V_10 -> V_301 , V_10 -> V_302 ) ;
return 0 ;
V_306:
F_133 ( V_10 -> V_301 , V_10 ) ;
V_305:
F_105 ( V_10 ) ;
V_304:
V_297 = & V_10 -> V_303 ;
for ( V_5 = 0 ; V_5 < V_295 ; V_5 ++ ) {
if ( * V_297 )
F_134 ( * V_297 ) ;
V_297 ++ ;
}
return V_77 ;
}
static int T_10 F_135 ( void )
{
F_136 ( & V_318 ) ;
return 0 ;
}
static void T_11 F_137 ( void )
{
F_138 ( & V_318 ) ;
}
