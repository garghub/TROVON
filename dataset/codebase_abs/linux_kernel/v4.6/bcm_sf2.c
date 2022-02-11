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
static char * F_10 ( struct V_18 * V_19 , int V_20 )
{
return L_1 ;
}
static void F_11 ( struct V_1 * V_2 , int V_21 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_5 ;
T_4 V_16 ;
for ( V_5 = 0 ; V_5 < V_10 -> V_22 . V_23 ; V_5 ++ ) {
if ( ! ( ( 1 << V_5 ) & V_2 -> V_24 ) )
continue;
V_16 = F_7 ( V_10 , F_12 ( V_5 ) ) ;
V_16 |= ( 1 << V_21 ) ;
F_13 ( V_10 , V_16 , F_12 ( V_5 ) ) ;
}
}
static void F_14 ( struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_16 , V_13 ;
V_16 = F_7 ( V_10 , V_25 ) ;
V_16 &= ~ F_15 ( V_3 ) ;
F_13 ( V_10 , V_16 , V_25 ) ;
V_16 = F_7 ( V_10 , V_26 ) ;
V_16 |= ( V_27 | V_28 | V_29 ) ;
V_16 &= ~ ( V_30 | V_31 ) ;
F_13 ( V_10 , V_16 , V_26 ) ;
F_13 ( V_10 , V_32 , V_33 ) ;
V_16 = F_7 ( V_10 , V_34 ) ;
V_16 |= V_35 ;
F_13 ( V_10 , V_16 , V_34 ) ;
switch ( V_3 ) {
case 8 :
V_13 = V_36 ;
break;
case 7 :
V_13 = V_37 ;
break;
case 5 :
V_13 = V_38 ;
break;
default:
V_13 = 0 ;
break;
}
V_16 = F_7 ( V_10 , V_39 ) ;
V_16 |= V_13 ;
F_13 ( V_10 , V_16 , V_39 ) ;
V_16 = F_7 ( V_10 , V_40 ) ;
V_16 &= ~ ( 1 << V_3 ) ;
F_13 ( V_10 , V_16 , V_40 ) ;
V_16 = F_7 ( V_10 , V_41 ) ;
V_16 &= ~ ( 1 << V_3 ) ;
F_13 ( V_10 , V_16 , V_41 ) ;
V_16 = F_7 ( V_10 , V_42 ) ;
V_16 |= ( V_43 | V_44 ) ;
F_13 ( V_10 , V_16 , V_42 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_3 , bool V_45 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_46 ) ;
if ( V_45 )
V_16 |= 1 << V_3 ;
else
V_16 &= ~ ( 1 << V_3 ) ;
F_13 ( V_10 , V_16 , V_46 ) ;
}
static void F_17 ( struct V_1 * V_2 , bool V_45 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_16 ;
V_16 = F_18 ( V_10 , V_47 ) ;
if ( V_45 ) {
V_16 |= V_48 ;
V_16 &= ~ ( V_49 | V_50 | V_51 ) ;
F_19 ( V_10 , V_16 , V_47 ) ;
F_20 ( 21 ) ;
V_16 = F_18 ( V_10 , V_47 ) ;
V_16 &= ~ V_48 ;
} else {
V_16 |= V_49 | V_50 | V_48 ;
F_19 ( V_10 , V_16 , V_47 ) ;
F_21 ( 1 ) ;
V_16 |= V_51 ;
}
F_19 ( V_10 , V_16 , V_47 ) ;
if ( ! V_45 ) {
V_16 = F_18 ( V_10 , F_22 ( 0 ) ) ;
V_16 |= V_52 ;
F_19 ( V_10 , V_16 , F_22 ( 0 ) ) ;
}
}
static inline void F_23 ( struct V_9 * V_10 ,
int V_3 )
{
unsigned int V_53 ;
switch ( V_3 ) {
case 7 :
V_53 = V_54 ;
break;
case 0 :
F_24 ( V_10 , F_25 ( V_55 ) ) ;
return;
default:
V_53 = F_26 ( V_3 ) ;
break;
}
F_27 ( V_10 , F_25 ( V_53 ) ) ;
}
static inline void F_28 ( struct V_9 * V_10 ,
int V_3 )
{
unsigned int V_53 ;
switch ( V_3 ) {
case 7 :
V_53 = V_54 ;
break;
case 0 :
F_29 ( V_10 , F_25 ( V_55 ) ) ;
F_30 ( V_10 , F_25 ( V_55 ) , V_56 ) ;
return;
default:
V_53 = F_26 ( V_3 ) ;
break;
}
F_31 ( V_10 , F_25 ( V_53 ) ) ;
F_32 ( V_10 , F_25 ( V_53 ) , V_56 ) ;
}
static int F_33 ( struct V_1 * V_2 , int V_3 ,
struct V_57 * V_58 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_5 V_21 = V_2 -> V_59 [ V_2 -> V_60 ] . V_21 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_25 ) ;
V_16 &= ~ F_15 ( V_3 ) ;
F_13 ( V_10 , V_16 , V_25 ) ;
F_13 ( V_10 , 0 , F_34 ( V_3 ) ) ;
if ( V_10 -> V_61 & 1 << V_3 && V_10 -> V_22 . V_62 == 1 ) {
F_17 ( V_2 , true ) ;
if ( V_58 ) {
V_58 -> V_63 = V_64 ;
F_35 ( V_58 ) ;
}
}
if ( V_3 == V_10 -> V_65 )
F_23 ( V_10 , V_3 ) ;
V_16 = F_7 ( V_10 , F_12 ( V_3 ) ) ;
V_16 &= ~ V_66 ;
V_16 |= ( 1 << V_3 ) ;
V_16 |= V_10 -> V_67 [ V_3 ] . V_68 ;
F_13 ( V_10 , V_16 , F_12 ( V_3 ) ) ;
F_11 ( V_2 , V_21 ) ;
if ( V_10 -> V_67 [ V_3 ] . V_69 . V_70 )
F_16 ( V_2 , V_3 , true ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 , int V_3 ,
struct V_57 * V_58 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_53 , V_16 ;
if ( V_10 -> V_71 & ( 1 << V_3 ) )
return;
if ( V_3 == V_10 -> V_65 )
F_28 ( V_10 , V_3 ) ;
if ( V_10 -> V_61 & 1 << V_3 && V_10 -> V_22 . V_62 == 1 )
F_17 ( V_2 , false ) ;
if ( F_37 ( V_2 , V_3 ) )
V_53 = V_26 ;
else
V_53 = F_34 ( V_3 ) ;
V_16 = F_7 ( V_10 , V_53 ) ;
V_16 |= V_30 | V_31 ;
F_13 ( V_10 , V_16 , V_53 ) ;
V_16 = F_7 ( V_10 , V_25 ) ;
V_16 |= F_15 ( V_3 ) ;
F_13 ( V_10 , V_16 , V_25 ) ;
}
static int F_38 ( struct V_1 * V_2 , int V_3 ,
struct V_57 * V_58 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_72 * V_73 = & V_10 -> V_67 [ V_3 ] . V_69 ;
int V_74 ;
V_73 -> V_75 = ( V_76 | V_77 ) ;
V_74 = F_39 ( V_58 , 0 ) ;
if ( V_74 )
return 0 ;
F_16 ( V_2 , V_3 , true ) ;
return 1 ;
}
static int F_40 ( struct V_1 * V_2 , int V_3 ,
struct V_72 * V_78 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_72 * V_73 = & V_10 -> V_67 [ V_3 ] . V_69 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_79 ) ;
V_78 -> V_70 = V_73 -> V_70 ;
V_78 -> V_80 = ! ! ( V_16 & ( 1 << V_3 ) ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , int V_3 ,
struct V_57 * V_81 ,
struct V_72 * V_78 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_72 * V_73 = & V_10 -> V_67 [ V_3 ] . V_69 ;
V_73 -> V_70 = V_78 -> V_70 ;
if ( ! V_73 -> V_70 ) {
F_16 ( V_2 , V_3 , false ) ;
} else {
V_73 -> V_70 = F_38 ( V_2 , V_3 , V_81 ) ;
if ( ! V_73 -> V_70 )
return - V_82 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_83 = 1000 ;
T_4 V_16 ;
F_13 ( V_10 , V_3 , V_84 ) ;
V_16 = F_7 ( V_10 , V_85 ) ;
V_16 |= V_86 | V_87 | V_88 ;
F_13 ( V_10 , V_16 , V_85 ) ;
do {
V_16 = F_7 ( V_10 , V_85 ) ;
if ( ! ( V_16 & V_88 ) )
break;
F_43 () ;
} while ( V_83 -- );
if ( ! V_83 )
return - V_89 ;
F_13 ( V_10 , 0 , V_85 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , int V_3 ,
struct V_90 * V_91 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_5 ;
T_4 V_16 , V_92 ;
V_10 -> V_67 [ V_3 ] . V_93 = V_91 ;
V_92 = F_7 ( V_10 , F_12 ( V_3 ) ) ;
for ( V_5 = 0 ; V_5 < V_10 -> V_22 . V_23 ; V_5 ++ ) {
if ( V_10 -> V_67 [ V_5 ] . V_93 != V_91 )
continue;
V_16 = F_7 ( V_10 , F_12 ( V_5 ) ) ;
V_16 |= 1 << V_3 ;
F_13 ( V_10 , V_16 , F_12 ( V_5 ) ) ;
V_10 -> V_67 [ V_5 ] . V_68 = V_16 ;
V_92 |= 1 << V_5 ;
}
F_13 ( V_10 , V_92 , F_12 ( V_3 ) ) ;
V_10 -> V_67 [ V_3 ] . V_68 = V_92 ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_90 * V_91 = V_10 -> V_67 [ V_3 ] . V_93 ;
unsigned int V_5 ;
T_4 V_16 , V_92 ;
V_92 = F_7 ( V_10 , F_12 ( V_3 ) ) ;
for ( V_5 = 0 ; V_5 < V_10 -> V_22 . V_23 ; V_5 ++ ) {
if ( V_10 -> V_67 [ V_5 ] . V_93 != V_91 )
continue;
V_16 = F_7 ( V_10 , F_12 ( V_5 ) ) ;
V_16 &= ~ ( 1 << V_3 ) ;
F_13 ( V_10 , V_16 , F_12 ( V_5 ) ) ;
V_10 -> V_67 [ V_3 ] . V_68 = V_16 ;
if ( V_3 != V_5 )
V_92 &= ~ ( 1 << V_5 ) ;
}
F_13 ( V_10 , V_92 , F_12 ( V_3 ) ) ;
V_10 -> V_67 [ V_3 ] . V_68 = V_92 ;
V_10 -> V_67 [ V_3 ] . V_93 = NULL ;
}
static int F_46 ( struct V_1 * V_2 , int V_3 ,
T_6 V_63 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_6 V_94 , V_95 ;
int V_74 = 0 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , F_34 ( V_3 ) ) ;
V_95 = V_16 & ( V_96 << V_97 ) ;
switch ( V_63 ) {
case V_98 :
V_94 = V_99 ;
break;
case V_100 :
V_94 = V_101 ;
break;
case V_102 :
V_94 = V_103 ;
break;
case V_104 :
V_94 = V_105 ;
break;
case V_106 :
V_94 = V_107 ;
break;
default:
F_47 ( L_2 , V_108 , V_63 ) ;
return - V_109 ;
}
if ( V_95 != V_94 ) {
if ( V_95 >= V_103 &&
V_94 <= V_101 ) {
V_74 = F_42 ( V_2 , V_3 ) ;
if ( V_74 ) {
F_47 ( L_3 , V_108 ) ;
return V_74 ;
}
}
}
V_16 = F_7 ( V_10 , F_34 ( V_3 ) ) ;
V_16 &= ~ ( V_96 << V_97 ) ;
V_16 |= V_94 ;
F_13 ( V_10 , V_16 , F_34 ( V_3 ) ) ;
return 0 ;
}
static int F_48 ( struct V_9 * V_10 )
{
unsigned int V_83 = 10 ;
T_4 V_16 ;
do {
V_16 = F_7 ( V_10 , V_110 ) ;
if ( ! ( V_16 & V_111 ) )
return 0 ;
F_49 ( 1000 , 2000 ) ;
} while ( V_83 -- );
return - V_89 ;
}
static int F_50 ( struct V_9 * V_10 , unsigned int V_112 )
{
T_4 V_113 ;
if ( V_112 > V_114 )
return - V_109 ;
V_113 = F_7 ( V_10 , V_110 ) ;
V_113 &= ~ V_115 ;
V_113 |= V_111 ;
if ( V_112 )
V_113 |= V_114 ;
else
V_113 &= ~ V_114 ;
F_13 ( V_10 , V_113 , V_110 ) ;
return F_48 ( V_10 ) ;
}
static int F_51 ( struct V_9 * V_10 , T_3 V_116 ,
T_7 V_117 , struct V_118 * V_119 , T_6 * V_120 ,
bool V_121 )
{
unsigned int V_5 ;
int V_74 ;
V_74 = F_48 ( V_10 ) ;
if ( V_74 )
return V_74 ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
T_3 V_122 ;
T_4 V_123 ;
V_122 = F_6 ( V_10 , F_52 ( V_5 ) ) ;
V_123 = F_7 ( V_10 , F_53 ( V_5 ) ) ;
F_54 ( V_119 , V_122 , V_123 ) ;
if ( V_119 -> V_121 && V_121 ) {
* V_120 = V_5 ;
return 0 ;
}
if ( ! V_121 && ( V_122 & V_116 ) )
return 0 ;
}
return - V_124 ;
}
static int F_55 ( struct V_9 * V_10 , int V_112 , int V_3 ,
const unsigned char * V_125 , T_7 V_117 , bool V_121 )
{
struct V_118 V_119 ;
T_4 V_123 ;
T_3 V_116 , V_122 = 0 ;
T_6 V_120 = 0 ;
int V_74 ;
V_116 = F_56 ( V_125 ) ;
F_57 ( V_10 , V_116 , V_126 ) ;
F_13 ( V_10 , V_117 , V_127 ) ;
V_74 = F_50 ( V_10 , 1 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_51 ( V_10 , V_116 , V_117 , & V_119 , & V_120 , V_121 ) ;
if ( V_112 )
return V_74 ;
if ( V_74 ) {
V_123 = 0 ;
V_120 = 0 ;
}
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . V_3 = V_3 ;
V_119 . V_121 = V_121 ;
V_119 . V_117 = V_117 ;
V_119 . V_128 = true ;
memcpy ( V_119 . V_116 , V_125 , V_129 ) ;
F_58 ( & V_122 , & V_123 , & V_119 ) ;
F_57 ( V_10 , V_122 , F_52 ( V_120 ) ) ;
F_13 ( V_10 , V_123 , F_53 ( V_120 ) ) ;
V_74 = F_50 ( V_10 , 0 ) ;
if ( V_74 )
return V_74 ;
return F_51 ( V_10 , V_116 , V_117 , & V_119 , & V_120 , V_121 ) ;
}
static int F_59 ( struct V_1 * V_2 , int V_3 ,
const struct V_130 * V_131 ,
struct V_132 * V_133 )
{
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , int V_3 ,
const struct V_130 * V_131 ,
struct V_132 * V_133 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
return F_55 ( V_10 , 0 , V_3 , V_131 -> V_125 , V_131 -> V_117 , true ) ;
}
static int F_61 ( struct V_1 * V_2 , int V_3 ,
const struct V_130 * V_131 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
return F_55 ( V_10 , 0 , V_3 , V_131 -> V_125 , V_131 -> V_117 , false ) ;
}
static int F_62 ( struct V_9 * V_10 )
{
unsigned V_83 = 1000 ;
T_4 V_16 ;
do {
V_16 = F_7 ( V_10 , V_134 ) ;
if ( ! ( V_16 & V_135 ) )
return 0 ;
if ( V_16 & V_136 )
return 0 ;
F_49 ( 1000 , 2000 ) ;
} while ( V_83 -- );
return - V_89 ;
}
static void F_63 ( struct V_9 * V_10 , T_6 V_120 ,
struct V_118 * V_119 )
{
T_3 V_122 ;
T_4 V_123 ;
V_122 = F_6 ( V_10 , F_64 ( V_120 ) ) ;
V_123 = F_7 ( V_10 , F_65 ( V_120 ) ) ;
F_54 ( V_119 , V_122 , V_123 ) ;
}
static int F_66 ( struct V_90 * V_137 , int V_3 ,
const struct V_118 * V_119 ,
struct V_130 * V_131 ,
int (* F_67)( struct V_138 * V_139 ) )
{
if ( ! V_119 -> V_121 )
return 0 ;
if ( V_3 != V_119 -> V_3 )
return 0 ;
F_68 ( V_131 -> V_125 , V_119 -> V_116 ) ;
V_131 -> V_117 = V_119 -> V_117 ;
V_131 -> V_140 = V_119 -> V_128 ? V_141 : V_142 ;
return F_67 ( & V_131 -> V_139 ) ;
}
static int F_69 ( struct V_1 * V_2 , int V_3 ,
struct V_130 * V_131 ,
int (* F_67)( struct V_138 * V_139 ) )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_90 * V_137 = V_2 -> V_143 [ V_3 ] ;
struct V_118 V_144 [ 2 ] ;
unsigned int V_145 = 0 ;
int V_74 ;
F_13 ( V_10 , V_135 , V_134 ) ;
do {
V_74 = F_62 ( V_10 ) ;
if ( V_74 )
return V_74 ;
F_63 ( V_10 , 0 , & V_144 [ 0 ] ) ;
V_74 = F_66 ( V_137 , V_3 , & V_144 [ 0 ] , V_131 , F_67 ) ;
if ( V_74 )
return V_74 ;
F_63 ( V_10 , 1 , & V_144 [ 1 ] ) ;
V_74 = F_66 ( V_137 , V_3 , & V_144 [ 1 ] , V_131 , F_67 ) ;
if ( V_74 )
return V_74 ;
if ( ! V_144 [ 0 ] . V_121 && ! V_144 [ 1 ] . V_121 )
break;
} while ( V_145 ++ < V_146 );
return 0 ;
}
static T_8 F_70 ( int V_147 , void * V_148 )
{
struct V_9 * V_10 = V_148 ;
V_10 -> V_149 = F_71 ( V_10 , V_150 ) &
~ V_10 -> V_151 ;
F_30 ( V_10 , V_10 -> V_149 , V_56 ) ;
return V_152 ;
}
static T_8 F_72 ( int V_147 , void * V_148 )
{
struct V_9 * V_10 = V_148 ;
V_10 -> V_153 = F_73 ( V_10 , V_150 ) &
~ V_10 -> V_154 ;
F_32 ( V_10 , V_10 -> V_153 , V_56 ) ;
if ( V_10 -> V_153 & F_74 ( V_54 ) )
V_10 -> V_67 [ 7 ] . V_155 = 1 ;
if ( V_10 -> V_153 & F_75 ( V_54 ) )
V_10 -> V_67 [ 7 ] . V_155 = 0 ;
return V_152 ;
}
static int F_76 ( struct V_9 * V_10 )
{
unsigned int V_83 = 1000 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_156 ) ;
V_16 |= V_157 | V_158 | V_159 ;
F_13 ( V_10 , V_16 , V_156 ) ;
do {
V_16 = F_7 ( V_10 , V_156 ) ;
if ( ! ( V_16 & V_157 ) )
break;
F_49 ( 1000 , 2000 ) ;
} while ( V_83 -- > 0 );
if ( V_83 == 0 )
return - V_89 ;
return 0 ;
}
static void F_77 ( struct V_9 * V_10 )
{
F_30 ( V_10 , 0xffffffff , V_160 ) ;
F_30 ( V_10 , 0xffffffff , V_56 ) ;
F_30 ( V_10 , 0 , V_161 ) ;
F_32 ( V_10 , 0xffffffff , V_160 ) ;
F_32 ( V_10 , 0xffffffff , V_56 ) ;
F_32 ( V_10 , 0 , V_161 ) ;
}
static void F_78 ( struct V_9 * V_10 ,
struct V_162 * V_163 )
{
struct V_162 * V_3 ;
const char * V_164 ;
int V_165 ;
unsigned int V_166 ;
int V_74 ;
V_10 -> V_65 = - 1 ;
F_79 (dn, port) {
if ( F_80 ( V_3 , L_4 , & V_166 ) )
continue;
V_165 = F_81 ( V_3 ) ;
if ( V_165 < 0 ) {
V_74 = F_82 ( V_3 , L_5 ,
& V_164 ) ;
if ( V_74 < 0 )
continue;
if ( ! strcasecmp ( V_164 , L_6 ) )
V_10 -> V_61 |= 1 << V_166 ;
}
if ( V_165 == V_167 )
V_10 -> V_65 = V_166 ;
}
}
static int F_83 ( struct V_1 * V_2 )
{
const char * V_168 [ V_169 ] = V_170 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_162 * V_163 ;
void T_9 * * V_171 ;
unsigned int V_3 ;
unsigned int V_5 ;
T_4 V_16 , V_172 ;
int V_74 ;
F_84 ( & V_10 -> V_173 ) ;
F_85 ( & V_10 -> V_15 ) ;
V_163 = V_2 -> V_174 -> V_175 -> V_176 ;
F_78 ( V_10 , V_2 -> V_174 -> V_175 ) ;
V_10 -> V_177 = F_86 ( V_163 , 0 ) ;
V_10 -> V_178 = F_86 ( V_163 , 1 ) ;
V_171 = & V_10 -> V_179 ;
for ( V_5 = 0 ; V_5 < V_169 ; V_5 ++ ) {
* V_171 = F_87 ( V_163 , V_5 ) ;
if ( * V_171 == NULL ) {
F_47 ( L_7 , V_168 [ V_5 ] ) ;
V_74 = - V_180 ;
goto V_181;
}
V_171 ++ ;
}
V_74 = F_76 ( V_10 ) ;
if ( V_74 ) {
F_47 ( L_8 , V_74 ) ;
goto V_181;
}
F_77 ( V_10 ) ;
V_74 = F_88 ( V_10 -> V_177 , F_70 , 0 ,
L_9 , V_10 ) ;
if ( V_74 < 0 ) {
F_47 ( L_10 ) ;
goto V_181;
}
V_74 = F_88 ( V_10 -> V_178 , F_72 , 0 ,
L_11 , V_10 ) ;
if ( V_74 < 0 ) {
F_47 ( L_12 ) ;
goto V_182;
}
V_16 = F_7 ( V_10 , V_183 ) ;
V_16 |= V_184 ;
F_13 ( V_10 , V_16 , V_183 ) ;
V_16 &= ~ V_184 ;
F_13 ( V_10 , V_16 , V_183 ) ;
V_10 -> V_22 . V_23 = F_7 ( V_10 , V_185 ) + 1 ;
if ( V_10 -> V_22 . V_23 > V_186 )
V_10 -> V_22 . V_23 = V_186 ;
if ( F_80 ( V_163 , L_13 ,
& V_10 -> V_22 . V_62 ) )
V_10 -> V_22 . V_62 = 1 ;
for ( V_3 = 0 ; V_3 < V_10 -> V_22 . V_23 ; V_3 ++ ) {
if ( ( 1 << V_3 ) & V_2 -> V_24 )
F_33 ( V_2 , V_3 , NULL ) ;
else if ( F_37 ( V_2 , V_3 ) )
F_14 ( V_2 , V_3 ) ;
else
F_36 ( V_2 , V_3 , NULL ) ;
}
if ( F_89 ( L_14 ) )
V_2 -> V_187 |= ( ( 1 << V_188 ) | ( 1 << 0 ) ) ;
else
V_2 -> V_187 = 0 ;
V_172 = F_18 ( V_10 , V_189 ) ;
V_10 -> V_22 . V_190 = ( V_172 >> V_191 ) &
V_192 ;
V_10 -> V_22 . V_193 = ( V_172 & V_194 ) ;
V_172 = F_18 ( V_10 , V_195 ) ;
V_10 -> V_22 . V_196 = V_172 & V_197 ;
F_90 ( L_15 ,
V_10 -> V_22 . V_190 >> 8 , V_10 -> V_22 . V_190 & 0xff ,
V_10 -> V_22 . V_193 >> 8 , V_10 -> V_22 . V_193 & 0xff ,
V_10 -> V_179 , V_10 -> V_177 , V_10 -> V_178 ) ;
return 0 ;
V_182:
F_91 ( V_10 -> V_177 , V_10 ) ;
V_181:
V_171 = & V_10 -> V_179 ;
for ( V_5 = 0 ; V_5 < V_169 ; V_5 ++ ) {
if ( * V_171 )
F_92 ( * V_171 ) ;
V_171 ++ ;
}
return V_74 ;
}
static int F_93 ( struct V_1 * V_2 , T_6 * V_125 )
{
return 0 ;
}
static T_4 F_94 ( struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
return V_10 -> V_22 . V_196 ;
}
static int F_95 ( struct V_1 * V_2 , int V_112 , int V_125 ,
int V_198 , T_7 V_13 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_74 = 0 ;
T_4 V_16 ;
V_16 = F_18 ( V_10 , V_199 ) ;
V_16 |= V_200 ;
F_19 ( V_10 , V_16 , V_199 ) ;
V_16 = 0x70 ;
V_16 <<= 2 ;
F_13 ( V_10 , V_125 , V_16 ) ;
V_16 = 0x80 << 8 | V_198 << 1 ;
V_16 <<= 2 ;
if ( V_112 )
V_74 = F_7 ( V_10 , V_16 ) ;
else
F_13 ( V_10 , V_13 , V_16 ) ;
V_16 = F_18 ( V_10 , V_199 ) ;
V_16 &= ~ V_200 ;
F_19 ( V_10 , V_16 , V_199 ) ;
return V_74 & 0xffff ;
}
static int F_96 ( struct V_1 * V_2 , int V_125 , int V_198 )
{
switch ( V_125 ) {
case 0 :
case V_188 :
return F_95 ( V_2 , 1 , V_125 , V_198 , 0 ) ;
default:
return 0xffff ;
}
}
static int F_97 ( struct V_1 * V_2 , int V_125 , int V_198 ,
T_7 V_13 )
{
switch ( V_125 ) {
case 0 :
case V_188 :
F_95 ( V_2 , 0 , V_125 , V_198 , V_13 ) ;
break;
}
return 0 ;
}
static void F_98 ( struct V_1 * V_2 , int V_3 ,
struct V_57 * V_81 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_201 = 0 , V_202 ;
const char * V_203 = NULL ;
T_4 V_16 ;
switch ( V_81 -> V_204 ) {
case V_205 :
V_203 = L_16 ;
V_201 = 1 ;
case V_206 :
if ( ! V_203 )
V_203 = L_17 ;
V_202 = V_207 ;
break;
case V_208 :
V_203 = L_18 ;
V_202 = V_209 ;
break;
case V_210 :
V_203 = L_19 ;
V_202 = V_211 ;
break;
default:
goto V_212;
}
if ( ! V_81 -> V_155 ) {
V_16 = F_18 ( V_10 , F_99 ( V_3 ) ) ;
V_16 &= ~ V_213 ;
F_19 ( V_10 , V_16 , F_99 ( V_3 ) ) ;
goto V_212;
}
V_16 = F_18 ( V_10 , F_99 ( V_3 ) ) ;
V_16 &= ~ V_214 ;
V_16 &= ~ ( V_215 << V_216 ) ;
V_16 &= ~ ( V_217 | V_218 ) ;
V_16 |= V_202 | V_213 ;
if ( V_201 )
V_16 |= V_214 ;
if ( V_81 -> V_219 ) {
if ( V_81 -> V_220 )
V_16 |= V_218 ;
V_16 |= V_217 ;
}
F_19 ( V_10 , V_16 , F_99 ( V_3 ) ) ;
F_90 ( L_20 , V_3 , V_203 ) ;
V_212:
V_16 = V_221 ;
switch ( V_81 -> V_222 ) {
case V_223 :
V_16 |= V_224 << V_225 ;
break;
case V_226 :
V_16 |= V_227 << V_225 ;
break;
}
if ( V_81 -> V_155 )
V_16 |= V_44 ;
if ( V_81 -> V_228 == V_229 )
V_16 |= V_230 ;
F_13 ( V_10 , V_16 , F_100 ( V_3 ) ) ;
}
static void F_101 ( struct V_1 * V_2 , int V_3 ,
struct V_231 * V_232 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_228 , V_219 ;
T_4 V_16 ;
V_228 = F_7 ( V_10 , V_233 ) ;
V_219 = F_7 ( V_10 , V_234 ) ;
V_232 -> V_155 = 0 ;
if ( V_3 == V_10 -> V_65 ) {
V_232 -> V_155 = V_10 -> V_67 [ V_3 ] . V_155 ;
if ( ! V_232 -> V_155 )
F_102 ( V_2 -> V_143 [ V_3 ] ) ;
V_232 -> V_228 = 1 ;
} else {
V_232 -> V_155 = 1 ;
V_232 -> V_228 = ! ! ( V_228 & ( 1 << V_3 ) ) ;
}
V_16 = F_7 ( V_10 , F_100 ( V_3 ) ) ;
V_16 |= V_221 ;
if ( V_232 -> V_155 )
V_16 |= V_44 ;
else
V_16 &= ~ V_44 ;
F_13 ( V_10 , V_16 , F_100 ( V_3 ) ) ;
if ( ( V_219 & ( 1 << V_3 ) ) &&
( V_219 & ( 1 << ( V_3 + V_235 ) ) ) ) {
V_232 -> V_220 = 1 ;
V_232 -> V_219 = 1 ;
}
if ( V_219 & ( 1 << V_3 ) )
V_232 -> V_219 = 1 ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_3 ;
F_77 ( V_10 ) ;
for ( V_3 = 0 ; V_3 < V_186 ; V_3 ++ ) {
if ( ( 1 << V_3 ) & V_2 -> V_24 ||
F_37 ( V_2 , V_3 ) )
F_36 ( V_2 , V_3 , NULL ) ;
}
return 0 ;
}
static int F_104 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_3 ;
int V_74 ;
V_74 = F_76 ( V_10 ) ;
if ( V_74 ) {
F_47 ( L_21 , V_108 ) ;
return V_74 ;
}
if ( V_10 -> V_22 . V_62 == 1 )
F_17 ( V_2 , true ) ;
for ( V_3 = 0 ; V_3 < V_186 ; V_3 ++ ) {
if ( ( 1 << V_3 ) & V_2 -> V_24 )
F_33 ( V_2 , V_3 , NULL ) ;
else if ( F_37 ( V_2 , V_3 ) )
F_14 ( V_2 , V_3 ) ;
}
return 0 ;
}
static void F_105 ( struct V_1 * V_2 , int V_3 ,
struct V_236 * V_237 )
{
struct V_90 * V_73 = V_2 -> V_59 [ V_2 -> V_60 ] . V_238 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_236 V_239 ;
V_73 -> V_240 -> V_241 ( V_73 , & V_239 ) ;
V_237 -> V_75 = V_239 . V_75 ;
memset ( & V_237 -> V_242 , 0 , sizeof( V_237 -> V_242 ) ) ;
if ( V_239 . V_243 & V_244 )
memcpy ( & V_237 -> V_242 , V_239 . V_242 , sizeof( V_237 -> V_242 ) ) ;
if ( V_10 -> V_71 & ( 1 << V_3 ) )
V_237 -> V_243 = V_239 . V_243 ;
else
V_237 -> V_243 = 0 ;
}
static int F_106 ( struct V_1 * V_2 , int V_3 ,
struct V_236 * V_237 )
{
struct V_90 * V_73 = V_2 -> V_59 [ V_2 -> V_60 ] . V_238 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_5 V_21 = V_2 -> V_59 [ V_2 -> V_60 ] . V_21 ;
struct V_236 V_239 ;
V_73 -> V_240 -> V_241 ( V_73 , & V_239 ) ;
if ( V_237 -> V_243 & ~ V_239 . V_75 )
return - V_109 ;
if ( V_237 -> V_243 )
V_10 -> V_71 |= ( 1 << V_3 ) ;
else
V_10 -> V_71 &= ~ ( 1 << V_3 ) ;
if ( V_10 -> V_71 && V_10 -> V_71 != ( 1 << V_21 ) )
V_10 -> V_71 |= ( 1 << V_21 ) ;
else
V_10 -> V_71 &= ~ ( 1 << V_21 ) ;
return V_73 -> V_240 -> V_245 ( V_73 , V_237 ) ;
}
static int T_10 F_107 ( void )
{
F_108 ( & V_246 ) ;
return 0 ;
}
static void T_11 F_109 ( void )
{
F_110 ( & V_246 ) ;
}
