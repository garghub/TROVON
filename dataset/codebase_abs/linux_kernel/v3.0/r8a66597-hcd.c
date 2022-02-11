static void F_1 ( struct V_1 * V_1 , T_1 V_2 ,
unsigned long V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_1 , V_5 ) ;
F_3 ( V_1 , V_6 | V_7 | V_8 , V_5 ) ;
F_4 ( V_1 , 1 << V_2 , V_3 ) ;
F_5 ( V_1 , V_4 , V_5 ) ;
}
static void F_6 ( struct V_1 * V_1 , T_1 V_2 ,
unsigned long V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_1 , V_5 ) ;
F_3 ( V_1 , V_6 | V_7 | V_8 , V_5 ) ;
F_3 ( V_1 , 1 << V_2 , V_3 ) ;
F_5 ( V_1 , V_4 , V_5 ) ;
}
static void F_7 ( struct V_1 * V_1 , T_2 V_9 ,
T_1 V_10 , T_2 V_11 , T_2 V_12 , int V_13 )
{
T_1 V_14 ;
unsigned long V_15 = F_8 ( V_9 ) ;
V_14 = ( V_11 << 11 ) | ( V_12 << 8 ) | ( V_10 << 6 ) | ( V_13 & 0x0001 ) ;
F_5 ( V_1 , V_14 , V_15 ) ;
}
static int F_9 ( struct V_1 * V_1 )
{
T_1 V_4 ;
int V_16 = 0 ;
if ( V_1 -> V_17 -> V_18 ) {
#ifdef F_10
F_11 ( V_1 -> V_19 ) ;
#endif
do {
F_5 ( V_1 , V_20 , V_21 ) ;
V_4 = F_2 ( V_1 , V_21 ) ;
if ( V_16 ++ > 1000 ) {
F_12 ( V_22 L_1 ) ;
return - V_23 ;
}
} while ( ( V_4 & V_20 ) != V_20 );
F_5 ( V_1 , 0x04 , 0x02 ) ;
} else {
do {
F_5 ( V_1 , V_24 , V_21 ) ;
V_4 = F_2 ( V_1 , V_21 ) ;
if ( V_16 ++ > 1000 ) {
F_12 ( V_22 L_1 ) ;
return - V_23 ;
}
} while ( ( V_4 & V_24 ) != V_24 );
F_3 ( V_1 , V_24 , V_21 ) ;
F_13 ( V_1 , F_14 ( V_1 -> V_17 ) ,
V_25 , V_21 ) ;
V_16 = 0 ;
F_4 ( V_1 , V_26 , V_21 ) ;
do {
F_15 ( 1 ) ;
V_4 = F_2 ( V_1 , V_21 ) ;
if ( V_16 ++ > 500 ) {
F_12 ( V_22 L_1 ) ;
return - V_23 ;
}
} while ( ( V_4 & V_20 ) != V_20 );
}
return 0 ;
}
static void F_16 ( struct V_1 * V_1 )
{
F_3 ( V_1 , V_20 , V_21 ) ;
F_17 ( 1 ) ;
if ( V_1 -> V_17 -> V_18 ) {
#ifdef F_10
F_18 ( V_1 -> V_19 ) ;
#endif
} else {
F_3 ( V_1 , V_27 , V_21 ) ;
F_3 ( V_1 , V_26 , V_21 ) ;
F_3 ( V_1 , V_24 , V_21 ) ;
}
}
static void F_19 ( struct V_1 * V_1 , int V_13 )
{
T_1 V_14 ;
V_14 = V_13 ? V_28 : V_29 | V_28 ;
F_4 ( V_1 , V_14 , F_20 ( V_13 ) ) ;
F_4 ( V_1 , V_30 , F_20 ( V_13 ) ) ;
F_5 ( V_1 , V_31 | V_32 , F_21 ( V_13 ) ) ;
F_3 ( V_1 , V_33 , F_22 ( V_13 ) ) ;
F_4 ( V_1 , V_34 , F_22 ( V_13 ) ) ;
}
static void F_23 ( struct V_1 * V_1 , int V_13 )
{
T_1 V_14 , V_4 ;
F_5 ( V_1 , 0 , F_22 ( V_13 ) ) ;
F_5 ( V_1 , 0 , F_24 ( V_13 ) ) ;
F_25 ( V_1 , V_13 , 0 ) ;
do {
V_4 = F_2 ( V_1 , V_35 ) & V_36 ;
F_17 ( 640 ) ;
} while ( V_4 == V_36 );
V_14 = V_13 ? V_28 : V_29 | V_28 ;
F_3 ( V_1 , V_14 , F_20 ( V_13 ) ) ;
F_3 ( V_1 , V_30 , F_20 ( V_13 ) ) ;
}
static int F_26 ( struct V_1 * V_1 )
{
int V_37 , V_13 ;
T_1 V_38 = V_1 -> V_17 -> V_38 ? V_39 : 0 ;
T_1 V_40 = V_1 -> V_41 ? V_42 : 0 ;
T_1 V_43 = V_1 -> V_17 -> V_43 ? V_44 : 0 ;
V_37 = F_9 ( V_1 ) ;
if ( V_37 < 0 )
return V_37 ;
F_4 ( V_1 , V_38 & V_39 , V_45 ) ;
F_4 ( V_1 , V_24 , V_21 ) ;
F_4 ( V_1 , V_6 | V_7 | V_8 , V_5 ) ;
F_4 ( V_1 , V_40 & V_42 , V_35 ) ;
F_4 ( V_1 , V_46 , V_47 ) ;
F_4 ( V_1 , V_48 , V_49 ) ;
F_4 ( V_1 , V_43 & V_44 , V_50 ) ;
F_4 ( V_1 , V_43 & V_44 , V_51 ) ;
F_4 ( V_1 , V_43 & V_44 , V_52 ) ;
F_4 ( V_1 , V_53 , V_35 ) ;
F_4 ( V_1 , V_54 | V_55 , V_56 ) ;
for ( V_13 = 0 ; V_13 < V_1 -> V_57 ; V_13 ++ )
F_19 ( V_1 , V_13 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_1 )
{
int V_13 ;
F_5 ( V_1 , 0 , V_5 ) ;
F_5 ( V_1 , 0 , V_56 ) ;
F_5 ( V_1 , 0 , V_47 ) ;
F_5 ( V_1 , 0 , V_49 ) ;
F_5 ( V_1 , 0 , V_58 ) ;
F_5 ( V_1 , 0 , V_59 ) ;
F_5 ( V_1 , 0 , V_60 ) ;
F_5 ( V_1 , 0 , V_61 ) ;
for ( V_13 = 0 ; V_13 < V_1 -> V_57 ; V_13 ++ )
F_23 ( V_1 , V_13 ) ;
F_16 ( V_1 ) ;
}
static int F_28 ( struct V_1 * V_1 ,
struct V_62 * V_63 )
{
struct V_64 * V_65 ;
if ( V_63 -> V_66 && V_63 -> V_66 -> V_67 != 1 )
V_63 = V_63 -> V_66 ;
V_65 = F_29 ( & V_63 -> V_65 ) ;
if ( V_65 )
return V_65 -> V_68 ;
else
return 0 ;
}
static int F_30 ( char * V_69 )
{
return ( V_69 [ 2 ] ? 1 : 0 ) ;
}
static int F_31 ( char * V_69 )
{
return ( ( strlen ( V_69 ) >= 4 ) ? 1 : 0 ) ;
}
static void F_32 ( struct V_1 * V_1 ,
char * V_69 , T_1 * V_70 , T_1 * V_71 )
{
if ( V_70 ) {
* V_70 = ( V_69 [ 0 ] & 0x0F ) - 1 ;
if ( * V_70 >= V_1 -> V_57 )
F_12 ( V_22 L_2 ) ;
}
if ( V_71 )
* V_71 = V_69 [ 2 ] & 0x0F ;
}
static T_1 F_33 ( enum V_72 V_73 )
{
T_1 V_10 = 0 ;
switch ( V_73 ) {
case V_74 :
V_10 = V_75 ;
break;
case V_76 :
V_10 = V_77 ;
break;
case V_78 :
V_10 = V_79 ;
break;
default:
F_12 ( V_22 L_3 ) ;
break;
}
return V_10 ;
}
static void F_34 ( struct V_1 * V_1 , int V_68 )
{
int V_80 ;
V_80 = V_68 / 32 ;
V_1 -> V_81 [ V_80 ] |= 1 << ( V_68 % 32 ) ;
}
static void F_35 ( struct V_1 * V_1 , int V_68 )
{
int V_80 ;
V_80 = V_68 / 32 ;
V_1 -> V_81 [ V_80 ] &= ~ ( 1 << ( V_68 % 32 ) ) ;
}
static void F_36 ( struct V_82 * V_83 , T_2 V_84 )
{
T_1 V_2 = V_83 -> V_85 . V_2 ;
const unsigned long V_86 [] = { V_87 , V_88 , V_89 } ;
const unsigned long V_90 [] = { V_51 , V_52 , V_50 } ;
const unsigned long V_91 [] = { V_92 , V_93 , V_94 } ;
if ( V_84 > V_95 )
V_84 = V_95 ;
V_83 -> V_86 = V_86 [ V_84 ] ;
V_83 -> V_90 = V_90 [ V_84 ] ;
V_83 -> V_91 = V_91 [ V_84 ] ;
if ( V_2 == 0 )
V_83 -> V_96 = V_97 ;
else
V_83 -> V_96 = F_37 ( V_2 ) ;
if ( F_38 ( V_2 ) ) {
V_83 -> V_98 = F_39 ( V_2 ) ;
V_83 -> V_99 = F_40 ( V_2 ) ;
} else {
V_83 -> V_98 = 0 ;
V_83 -> V_99 = 0 ;
}
}
static struct V_64 *
F_41 ( struct V_1 * V_1 , struct V_100 * V_100 )
{
if ( F_42 ( V_100 -> V_83 ) == 0 )
return & V_1 -> V_101 ;
return F_29 ( & V_100 -> V_65 -> V_65 ) ;
}
static int F_43 ( struct V_1 * V_1 ,
struct V_100 * V_100 , T_2 V_102 )
{
struct V_64 * V_65 ;
int V_103 = V_100 -> V_104 [ 2 ] ;
V_65 = F_44 ( sizeof( struct V_64 ) , V_105 ) ;
if ( V_65 == NULL )
return - V_106 ;
F_45 ( & V_100 -> V_65 -> V_65 , V_65 ) ;
V_65 -> V_63 = V_100 -> V_65 ;
V_65 -> V_68 = V_102 ;
V_65 -> V_103 = V_103 ;
V_65 -> V_107 = V_108 ;
V_65 -> V_109 = 0 ;
V_65 -> V_110 = 0 ;
F_46 ( & V_65 -> V_111 ) ;
F_47 ( & V_65 -> V_111 , & V_1 -> V_112 ) ;
F_32 ( V_1 , V_100 -> V_65 -> V_69 ,
& V_65 -> V_70 , & V_65 -> V_71 ) ;
if ( ! F_30 ( V_100 -> V_65 -> V_69 ) )
V_1 -> V_113 [ V_65 -> V_70 ] . V_65 = V_65 ;
F_7 ( V_1 , V_65 -> V_68 ,
F_33 ( V_100 -> V_65 -> V_73 ) ,
F_28 ( V_1 , V_100 -> V_65 ) ,
V_65 -> V_71 , V_65 -> V_70 ) ;
return 0 ;
}
static T_2 F_48 ( struct V_1 * V_1 , struct V_100 * V_100 )
{
T_2 V_102 ;
struct V_64 * V_65 ;
if ( F_31 ( V_100 -> V_65 -> V_69 ) ) {
F_49 ( & V_100 -> V_65 -> V_65 , L_4 ) ;
return 0 ;
}
V_65 = F_41 ( V_1 , V_100 ) ;
if ( V_65 && V_65 -> V_107 >= V_108 )
return V_65 -> V_68 ;
for ( V_102 = 1 ; V_102 <= V_114 ; V_102 ++ ) {
if ( V_1 -> V_115 & ( 1 << V_102 ) )
continue;
F_50 ( L_5 , V_102 ) ;
V_1 -> V_115 |= 1 << V_102 ;
if ( F_43 ( V_1 , V_100 , V_102 ) < 0 )
return 0 ;
return V_102 ;
}
F_49 ( & V_100 -> V_65 -> V_65 ,
L_6 ,
V_1 -> V_115 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_1 ,
struct V_64 * V_65 , int V_116 )
{
int V_13 ;
if ( ! V_65 )
return;
F_50 ( L_7 , V_65 -> V_68 ) ;
V_65 -> V_107 = V_117 ;
V_1 -> V_115 &= ~ ( 1 << V_65 -> V_68 ) ;
V_65 -> V_68 = 0 ;
if ( V_116 )
F_45 ( & V_65 -> V_63 -> V_65 , NULL ) ;
F_52 ( & V_65 -> V_111 ) ;
F_53 ( V_65 ) ;
for ( V_13 = 0 ; V_13 < V_1 -> V_57 ; V_13 ++ ) {
if ( V_1 -> V_113 [ V_13 ] . V_65 == V_65 ) {
V_1 -> V_113 [ V_13 ] . V_65 = NULL ;
break;
}
}
}
static void F_54 ( struct V_1 * V_1 , unsigned long V_3 ,
T_1 V_118 , T_1 V_119 )
{
T_1 V_4 ;
int V_16 = 0 ;
do {
V_4 = F_2 ( V_1 , V_3 ) ;
if ( V_16 ++ > 1000000 ) {
F_12 ( V_22 L_8
L_9 , V_3 , V_119 ) ;
break;
}
F_55 ( 1 ) ;
} while ( ( V_4 & V_118 ) != V_119 );
}
static void F_56 ( struct V_1 * V_1 , struct V_82 * V_83 )
{
T_1 V_4 ;
V_4 = F_2 ( V_1 , V_83 -> V_96 ) & V_120 ;
if ( ( V_83 -> V_85 . V_2 != 0 ) & ( ( V_4 & V_121 ) != 0 ) )
F_13 ( V_1 , V_122 , V_120 , V_83 -> V_96 ) ;
F_13 ( V_1 , V_123 , V_120 , V_83 -> V_96 ) ;
}
static void F_57 ( struct V_1 * V_1 , struct V_82 * V_83 )
{
T_1 V_4 ;
V_4 = F_2 ( V_1 , V_83 -> V_96 ) & V_120 ;
if ( ( V_4 & V_124 ) != V_124 )
F_13 ( V_1 , V_121 , V_120 , V_83 -> V_96 ) ;
F_13 ( V_1 , V_122 , V_120 , V_83 -> V_96 ) ;
F_54 ( V_1 , V_83 -> V_96 , V_125 , 0 ) ;
}
static void F_58 ( struct V_1 * V_1 ,
struct V_82 * V_83 )
{
T_1 V_4 ;
if ( ! V_83 || V_83 -> V_85 . V_2 == 0 )
return;
F_57 ( V_1 , V_83 ) ;
F_4 ( V_1 , V_126 , V_83 -> V_96 ) ;
V_4 = F_2 ( V_1 , V_83 -> V_96 ) ;
V_4 = F_2 ( V_1 , V_83 -> V_96 ) ;
V_4 = F_2 ( V_1 , V_83 -> V_96 ) ;
F_3 ( V_1 , V_126 , V_83 -> V_96 ) ;
}
static void F_59 ( struct V_1 * V_1 ,
struct V_82 * V_83 , int V_127 )
{
if ( V_127 )
F_4 ( V_1 , V_128 , V_83 -> V_96 ) ;
else
F_4 ( V_1 , V_129 , V_83 -> V_96 ) ;
}
static inline unsigned short F_60 ( struct V_1 * V_1 )
{
if ( V_1 -> V_17 -> V_18 )
return V_130 ;
else
return V_131 ;
}
static inline void F_61 ( struct V_1 * V_1 , T_1 V_2 )
{
unsigned short V_132 = F_60 ( V_1 ) ;
F_13 ( V_1 , V_132 | V_2 , V_132 | V_133 , V_50 ) ;
F_54 ( V_1 , V_50 , V_133 , V_2 ) ;
}
static inline void F_62 ( struct V_1 * V_1 ,
struct V_82 * V_83 )
{
unsigned short V_132 = F_60 ( V_1 ) ;
F_61 ( V_1 , 0 ) ;
F_13 ( V_1 , V_132 | 0 , V_132 | V_133 , V_51 ) ;
F_13 ( V_1 , V_132 | 0 , V_132 | V_133 , V_52 ) ;
F_13 ( V_1 , V_132 | V_83 -> V_85 . V_2 , V_132 | V_133 ,
V_83 -> V_90 ) ;
F_54 ( V_1 , V_83 -> V_90 , V_133 , V_83 -> V_85 . V_2 ) ;
}
static T_1 F_63 ( struct V_100 * V_100 , struct V_134 * V_135 )
{
struct V_82 * V_83 = V_135 -> V_136 ;
if ( F_64 ( V_100 -> V_83 ) == 0 )
return 0 ;
else
return V_83 -> V_85 . V_2 ;
}
static T_1 F_65 ( struct V_1 * V_1 , struct V_100 * V_100 )
{
struct V_64 * V_65 = F_41 ( V_1 , V_100 ) ;
return ( F_42 ( V_100 -> V_83 ) == 0 ) ? 0 : V_65 -> V_68 ;
}
static unsigned short * F_66 ( struct V_64 * V_65 ,
int V_137 )
{
if ( ! V_65 )
return NULL ;
return F_67 ( V_137 ) ? & V_65 -> V_109 : & V_65 -> V_110 ;
}
static void F_68 ( struct V_1 * V_1 ,
struct V_82 * V_83 ,
struct V_100 * V_100 , int V_138 )
{
struct V_64 * V_65 = F_41 ( V_1 , V_100 ) ;
unsigned char V_139 = F_64 ( V_100 -> V_83 ) ;
unsigned short * V_127 = F_66 ( V_65 , V_100 -> V_83 ) ;
if ( ! V_127 )
return;
if ( V_138 )
* V_127 |= 1 << V_139 ;
else
* V_127 &= ~ ( 1 << V_139 ) ;
}
static void F_69 ( struct V_1 * V_1 ,
struct V_82 * V_83 ,
struct V_100 * V_100 )
{
if ( F_2 ( V_1 , V_83 -> V_96 ) & V_140 )
F_68 ( V_1 , V_83 , V_100 , 1 ) ;
else
F_68 ( V_1 , V_83 , V_100 , 0 ) ;
}
static void F_70 ( struct V_1 * V_1 ,
struct V_82 * V_83 ,
struct V_100 * V_100 )
{
struct V_64 * V_65 = F_41 ( V_1 , V_100 ) ;
unsigned char V_139 = F_64 ( V_100 -> V_83 ) ;
unsigned short * V_127 = F_66 ( V_65 , V_100 -> V_83 ) ;
if ( ! V_127 )
return;
F_59 ( V_1 , V_83 , * V_127 & ( 1 << V_139 ) ) ;
}
static void F_71 ( struct V_1 * V_1 ,
struct V_141 * V_85 )
{
T_1 V_14 = 0 ;
if ( V_85 -> V_2 == 0 )
return;
F_4 ( V_1 , V_126 , F_37 ( V_85 -> V_2 ) ) ;
F_3 ( V_1 , V_126 , F_37 ( V_85 -> V_2 ) ) ;
F_5 ( V_1 , V_85 -> V_2 , V_142 ) ;
if ( ! V_85 -> V_143 )
V_14 |= V_144 ;
if ( V_85 -> type == V_145 && V_85 -> V_143 )
V_14 |= V_146 | V_147 ;
V_14 |= V_85 -> type | V_85 -> V_148 ;
F_5 ( V_1 , V_14 , V_149 ) ;
F_5 ( V_1 , ( V_85 -> V_150 << 10 ) | ( V_85 -> V_151 ) ,
V_152 ) ;
F_5 ( V_1 , F_72 ( V_85 -> V_68 ) | V_85 -> V_153 ,
V_154 ) ;
F_5 ( V_1 , V_85 -> V_155 , V_156 ) ;
}
static void F_73 ( struct V_1 * V_1 , struct V_157 * V_158 )
{
struct V_141 * V_85 ;
struct V_100 * V_100 = V_158 -> V_100 ;
if ( V_158 -> V_2 > 0 ) {
V_85 = & V_158 -> V_83 -> V_85 ;
F_61 ( V_1 , 0 ) ;
F_71 ( V_1 , V_85 ) ;
if ( ! F_74 ( V_100 -> V_65 , F_64 ( V_100 -> V_83 ) ,
F_75 ( V_100 -> V_83 ) ) &&
! F_76 ( V_100 -> V_83 ) ) {
F_59 ( V_1 , V_158 -> V_83 , 0 ) ;
F_68 ( V_1 , V_158 -> V_83 , V_100 , 0 ) ;
F_58 ( V_1 , V_158 -> V_83 ) ;
F_77 ( V_100 -> V_65 , F_64 ( V_100 -> V_83 ) ,
F_75 ( V_100 -> V_83 ) , 1 ) ;
}
F_70 ( V_1 , V_158 -> V_83 , V_100 ) ;
}
}
static T_1 F_78 ( struct V_1 * V_1 ,
struct V_159 * V_160 )
{
T_1 V_161 [ V_162 ] , V_16 = 0 , V_163 ;
memset ( V_161 , 0 , sizeof( V_161 ) ) ;
switch ( F_79 ( V_160 ) ) {
case V_164 :
if ( F_80 ( V_160 ) )
V_161 [ V_16 ++ ] = 4 ;
else {
V_161 [ V_16 ++ ] = 3 ;
V_161 [ V_16 ++ ] = 5 ;
}
break;
case V_165 :
if ( F_80 ( V_160 ) ) {
V_161 [ V_16 ++ ] = 6 ;
V_161 [ V_16 ++ ] = 7 ;
V_161 [ V_16 ++ ] = 8 ;
} else
V_161 [ V_16 ++ ] = 9 ;
break;
case V_166 :
if ( F_80 ( V_160 ) )
V_161 [ V_16 ++ ] = 2 ;
else
V_161 [ V_16 ++ ] = 1 ;
break;
default:
F_12 ( V_22 L_10 ) ;
return 0 ;
}
V_16 = 1 ;
V_163 = V_161 [ 0 ] ;
while ( V_161 [ V_16 ] != 0 ) {
if ( V_1 -> V_167 [ V_163 ] > V_1 -> V_167 [ V_161 [ V_16 ] ] )
V_163 = V_161 [ V_16 ] ;
V_16 ++ ;
}
return V_163 ;
}
static T_1 F_81 ( T_3 type )
{
T_1 V_168 ;
switch ( type ) {
case V_164 :
V_168 = V_145 ;
break;
case V_165 :
V_168 = V_169 ;
break;
case V_166 :
V_168 = V_170 ;
break;
default:
F_12 ( V_22 L_10 ) ;
V_168 = 0x0000 ;
break;
}
return V_168 ;
}
static T_1 F_82 ( T_1 V_2 )
{
T_1 V_151 = 0 ;
if ( V_2 == 0 )
V_151 = 0 ;
else if ( F_38 ( V_2 ) )
V_151 = 8 + ( V_2 - 1 ) * V_171 * 2 ;
else if ( F_83 ( V_2 ) )
V_151 = 4 + ( V_2 - 6 ) ;
else
F_12 ( V_22 L_11 , V_2 ) ;
return V_151 ;
}
static T_1 F_84 ( T_1 V_2 )
{
T_1 V_150 = 0 ;
if ( V_2 == 0 )
V_150 = 3 ;
else if ( F_38 ( V_2 ) )
V_150 = V_171 - 1 ;
else if ( F_83 ( V_2 ) )
V_150 = 0 ;
else
F_12 ( V_22 L_11 , V_2 ) ;
return V_150 ;
}
static void F_85 ( struct V_1 * V_1 ,
struct V_64 * V_65 ,
struct V_82 * V_83 ,
struct V_100 * V_100 )
{
int V_16 ;
struct V_141 * V_85 = & V_83 -> V_85 ;
unsigned short V_132 = F_60 ( V_1 ) ;
if ( V_1 -> V_17 -> V_18 )
return;
if ( ( V_83 -> V_85 . V_2 != 0 ) && ( V_85 -> type != V_169 ) ) {
for ( V_16 = 0 ; V_16 < V_172 ; V_16 ++ ) {
if ( ( V_1 -> V_173 & ( 1 << V_16 ) ) != 0 )
continue;
F_86 ( & V_65 -> V_63 -> V_65 ,
L_12
L_13 , F_42 ( V_100 -> V_83 ) ,
V_85 -> V_143 ?
V_174 + V_85 -> V_148
: V_85 -> V_148 ) ;
V_1 -> V_173 |= 1 << V_16 ;
V_65 -> V_173 |= 1 << V_16 ;
F_36 ( V_83 , V_16 ) ;
F_61 ( V_1 , 0 ) ;
F_13 ( V_1 , V_132 | V_83 -> V_85 . V_2 ,
V_132 | V_133 , V_83 -> V_90 ) ;
F_54 ( V_1 , V_83 -> V_90 , V_133 ,
V_83 -> V_85 . V_2 ) ;
F_4 ( V_1 , V_175 , V_83 -> V_91 ) ;
break;
}
}
}
static void F_87 ( struct V_1 * V_1 , struct V_100 * V_100 ,
struct V_134 * V_135 ,
struct V_141 * V_85 )
{
struct V_64 * V_65 = F_41 ( V_1 , V_100 ) ;
struct V_82 * V_83 = V_135 -> V_136 ;
F_50 ( L_14 ) ;
V_83 -> V_85 = * V_85 ;
F_36 ( V_83 , V_95 ) ;
V_1 -> V_167 [ V_83 -> V_85 . V_2 ] ++ ;
V_65 -> V_167 [ V_83 -> V_85 . V_2 ] ++ ;
F_85 ( V_1 , V_65 , V_83 , V_100 ) ;
}
static void F_88 ( struct V_1 * V_1 , struct V_100 * V_100 ,
int V_176 )
__releases( V_1 -> V_177 )
__acquires( V_1 -> V_177 )
{
if ( F_67 ( V_100 -> V_83 ) && F_89 ( V_100 -> V_83 ) != V_178 ) {
void * V_179 ;
for ( V_179 = V_100 -> V_180 ;
V_179 < V_100 -> V_180 + V_100 -> V_181 ;
V_179 += V_182 )
F_90 ( F_91 ( V_179 ) ) ;
}
F_92 ( F_93 ( V_1 ) , V_100 ) ;
F_94 ( & V_1 -> V_177 ) ;
F_95 ( F_93 ( V_1 ) , V_100 , V_176 ) ;
F_96 ( & V_1 -> V_177 ) ;
}
static void F_97 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_68 )
{
struct V_157 * V_158 , * V_183 ;
struct V_100 * V_100 ;
struct V_184 * V_185 = & V_1 -> V_186 [ V_2 ] ;
if ( F_98 ( V_185 ) )
return;
F_99 (td, next, list, queue) {
if ( V_158 -> V_68 != V_68 )
continue;
V_100 = V_158 -> V_100 ;
F_52 ( & V_158 -> V_187 ) ;
F_53 ( V_158 ) ;
if ( V_100 )
F_88 ( V_1 , V_100 , - V_188 ) ;
break;
}
}
static void F_100 ( struct V_1 * V_1 ,
struct V_64 * V_65 )
{
int V_189 = 0 ;
T_1 V_2 ;
if ( ! V_65 )
return;
for ( V_2 = 1 ; V_2 < V_162 ; V_2 ++ ) {
if ( ! V_65 -> V_167 [ V_2 ] )
continue;
if ( ! V_189 ) {
V_189 = 1 ;
F_97 ( V_1 , 0 , V_65 -> V_68 ) ;
}
V_1 -> V_167 [ V_2 ] -= V_65 -> V_167 [ V_2 ] ;
V_65 -> V_167 [ V_2 ] = 0 ;
F_97 ( V_1 , V_2 , V_65 -> V_68 ) ;
}
F_50 ( L_15 ) ;
V_1 -> V_173 &= ~ ( V_65 -> V_173 ) ;
V_65 -> V_173 = 0 ;
}
static T_1 F_101 ( struct V_100 * V_100 , T_3 V_155 )
{
T_1 time = 1 ;
int V_16 ;
if ( V_100 -> V_65 -> V_73 == V_78 ) {
if ( V_155 > V_190 )
time = V_190 ;
else
time = V_155 ? V_155 - 1 : 0 ;
} else {
if ( V_155 > 128 ) {
time = V_190 ;
} else {
for ( V_16 = 0 ; V_16 < 7 ; V_16 ++ ) {
if ( ( 1 << V_16 ) < V_155 &&
( 1 << ( V_16 + 1 ) > V_155 ) )
time = 1 << V_16 ;
}
}
}
return time ;
}
static unsigned long F_102 ( struct V_100 * V_100 , T_3 V_155 )
{
T_3 V_16 ;
unsigned long time = 1 ;
if ( F_103 ( V_100 -> V_83 ) )
return 0 ;
if ( F_33 ( V_100 -> V_65 -> V_73 ) == V_79 ) {
for ( V_16 = 0 ; V_16 < ( V_155 - 1 ) ; V_16 ++ )
time *= 2 ;
time = time * 125 / 1000 ;
} else {
time = V_155 ;
}
return time ;
}
static void F_104 ( struct V_1 * V_1 , struct V_100 * V_100 ,
struct V_134 * V_135 ,
struct V_159 * V_160 )
{
struct V_141 V_85 ;
V_85 . V_2 = F_78 ( V_1 , V_160 ) ;
V_85 . V_68 = F_65 ( V_1 , V_100 ) ;
V_85 . V_148 = F_105 ( V_160 ) ;
V_85 . V_153 = F_106 ( V_160 -> V_191 ) ;
V_85 . type = F_81 ( F_79 ( V_160 ) ) ;
V_85 . V_151 = F_82 ( V_85 . V_2 ) ;
V_85 . V_150 = F_84 ( V_85 . V_2 ) ;
if ( V_85 . type == V_145 ) {
V_85 . V_155 = 0 ;
V_85 . V_192 = 0 ;
} else {
V_85 . V_155 = F_101 ( V_100 , V_160 -> V_193 ) ;
V_85 . V_192 = F_102 ( V_100 , V_160 -> V_193 ) ;
}
if ( F_80 ( V_160 ) )
V_85 . V_143 = 1 ;
else
V_85 . V_143 = 0 ;
F_87 ( V_1 , V_100 , V_135 , & V_85 ) ;
}
static void F_107 ( struct V_1 * V_1 , struct V_100 * V_100 )
{
struct V_64 * V_65 ;
V_65 = F_41 ( V_1 , V_100 ) ;
V_65 -> V_107 = V_194 ;
}
static void F_108 ( struct V_1 * V_1 , struct V_100 * V_100 ,
T_1 V_2 )
{
if ( V_2 == 0 && F_75 ( V_100 -> V_83 ) )
F_109 ( V_1 , V_2 ) ;
else
F_110 ( V_1 , V_2 ) ;
if ( ! F_103 ( V_100 -> V_83 ) )
F_111 ( V_1 , V_2 ) ;
}
static void F_112 ( struct V_1 * V_1 , T_1 V_2 )
{
F_113 ( V_1 , V_2 ) ;
F_114 ( V_1 , V_2 ) ;
}
static void F_115 ( struct V_1 * V_1 )
{
F_116 ( & V_1 -> V_195 ,
V_196 + F_117 ( V_197 ) ) ;
}
static void F_118 ( struct V_1 * V_1 , int V_13 ,
int V_198 )
{
struct V_199 * V_200 = & V_1 -> V_113 [ V_13 ] ;
V_200 -> V_201 = F_2 ( V_1 , F_119 ( V_13 ) ) & V_202 ;
V_200 -> V_203 = V_204 ;
if ( V_198 )
V_200 -> V_13 |= V_205 ;
else
V_200 -> V_13 &= ~ V_205 ;
V_200 -> V_13 |= V_206 << 16 ;
F_115 ( V_1 ) ;
}
static void F_120 ( struct V_1 * V_1 , int V_13 ,
T_1 V_207 )
__releases( V_1 -> V_177 )
__acquires( V_1 -> V_177 )
{
if ( V_207 == V_208 ) {
F_5 ( V_1 , ~ V_209 , F_24 ( V_13 ) ) ;
F_4 ( V_1 , V_34 , F_22 ( V_13 ) ) ;
} else {
if ( V_207 == V_210 )
F_4 ( V_1 , V_30 , F_20 ( V_13 ) ) ;
else if ( V_207 == V_211 )
F_3 ( V_1 , V_30 , F_20 ( V_13 ) ) ;
F_5 ( V_1 , ~ V_212 , F_24 ( V_13 ) ) ;
F_4 ( V_1 , V_33 , F_22 ( V_13 ) ) ;
if ( V_1 -> V_213 )
F_121 ( F_93 ( V_1 ) ) ;
}
F_94 ( & V_1 -> V_177 ) ;
F_122 ( F_93 ( V_1 ) ) ;
F_96 ( & V_1 -> V_177 ) ;
}
static void F_123 ( struct V_1 * V_1 , int V_13 )
{
T_1 V_73 = F_124 ( V_1 , V_13 ) ;
struct V_199 * V_200 = & V_1 -> V_113 [ V_13 ] ;
V_200 -> V_13 &= ~ ( V_214 | V_215 ) ;
if ( V_73 == V_79 )
V_200 -> V_13 |= V_214 ;
else if ( V_73 == V_75 )
V_200 -> V_13 |= V_215 ;
V_200 -> V_13 &= ~ V_216 ;
V_200 -> V_13 |= V_217 ;
}
static void F_125 ( struct V_1 * V_1 , int V_13 )
{
struct V_64 * V_65 = V_1 -> V_113 [ V_13 ] . V_65 ;
F_100 ( V_1 , V_65 ) ;
F_51 ( V_1 , V_65 , 0 ) ;
F_118 ( V_1 , V_13 , 0 ) ;
}
static void F_126 ( struct V_1 * V_1 ,
struct V_157 * V_158 )
{
int V_16 ;
T_4 * V_218 = ( T_4 * ) V_158 -> V_100 -> V_104 ;
unsigned long V_219 = V_220 ;
F_5 ( V_1 , F_72 ( V_158 -> V_68 ) | V_158 -> V_153 ,
V_221 ) ;
F_5 ( V_1 , ~ ( V_222 | V_223 ) , V_224 ) ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ ) {
F_5 ( V_1 , F_106 ( V_218 [ V_16 ] ) , V_219 ) ;
V_219 += 2 ;
}
F_5 ( V_1 , V_225 , V_97 ) ;
}
static void F_127 ( struct V_1 * V_1 ,
struct V_157 * V_158 )
{
struct V_100 * V_100 = V_158 -> V_100 ;
if ( F_76 ( V_100 -> V_83 ) ) {
F_3 ( V_1 , V_144 , V_226 ) ;
F_13 ( V_1 , 0 , V_227 | V_133 , V_50 ) ;
F_54 ( V_1 , V_50 , V_133 , 0 ) ;
if ( V_100 -> V_228 == 0 ) {
F_59 ( V_1 , V_158 -> V_83 , 1 ) ;
F_5 ( V_1 , V_175 , V_94 ) ;
}
F_112 ( V_1 , V_158 -> V_2 ) ;
F_56 ( V_1 , V_158 -> V_83 ) ;
F_108 ( V_1 , V_100 , V_158 -> V_2 ) ;
} else {
if ( V_100 -> V_228 == 0 ) {
F_112 ( V_1 , V_158 -> V_2 ) ;
F_73 ( V_1 , V_158 ) ;
F_57 ( V_1 , V_158 -> V_83 ) ;
F_5 ( V_1 , ~ ( 1 << V_158 -> V_2 ) , V_59 ) ;
if ( V_158 -> V_83 -> V_98 ) {
F_5 ( V_1 , V_229 ,
V_158 -> V_83 -> V_98 ) ;
F_5 ( V_1 ,
F_128
( V_100 -> V_181 ,
V_158 -> V_153 ) ,
V_158 -> V_83 -> V_99 ) ;
F_4 ( V_1 , V_230 ,
V_158 -> V_83 -> V_98 ) ;
}
F_56 ( V_1 , V_158 -> V_83 ) ;
F_108 ( V_1 , V_100 , V_158 -> V_2 ) ;
}
}
}
static void F_129 ( struct V_1 * V_1 ,
struct V_157 * V_158 )
{
T_1 V_4 ;
struct V_100 * V_100 = V_158 -> V_100 ;
if ( F_76 ( V_100 -> V_83 ) ) {
F_57 ( V_1 , V_158 -> V_83 ) ;
F_4 ( V_1 , V_144 , V_226 ) ;
F_13 ( V_1 , V_227 , V_227 | V_133 , V_50 ) ;
F_54 ( V_1 , V_50 , V_133 , 0 ) ;
if ( V_100 -> V_228 == 0 ) {
F_59 ( V_1 , V_158 -> V_83 , 1 ) ;
F_5 ( V_1 , V_175 , V_94 ) ;
}
} else {
if ( V_100 -> V_228 == 0 )
F_73 ( V_1 , V_158 ) ;
if ( V_158 -> V_83 -> V_98 )
F_3 ( V_1 , V_230 , V_158 -> V_83 -> V_98 ) ;
}
F_5 ( V_1 , ~ ( 1 << V_158 -> V_2 ) , V_59 ) ;
F_62 ( V_1 , V_158 -> V_83 ) ;
V_4 = F_2 ( V_1 , V_158 -> V_83 -> V_91 ) ;
if ( F_130 ( ( V_4 & V_231 ) == 0 ) )
F_108 ( V_1 , V_100 , V_158 -> V_2 ) ;
else
F_131 ( V_1 , V_158 -> V_2 ) ;
F_56 ( V_1 , V_158 -> V_83 ) ;
}
static void F_132 ( struct V_1 * V_1 ,
struct V_157 * V_158 )
{
struct V_100 * V_100 = V_158 -> V_100 ;
F_59 ( V_1 , V_158 -> V_83 , 1 ) ;
F_57 ( V_1 , V_158 -> V_83 ) ;
if ( V_100 -> V_104 [ 0 ] & V_174 ) {
F_4 ( V_1 , V_144 , V_226 ) ;
F_13 ( V_1 , V_227 , V_227 | V_133 , V_50 ) ;
F_54 ( V_1 , V_50 , V_133 , 0 ) ;
F_5 ( V_1 , ~ V_48 , V_61 ) ;
F_5 ( V_1 , V_175 | V_232 , V_94 ) ;
F_109 ( V_1 , 0 ) ;
} else {
F_3 ( V_1 , V_144 , V_226 ) ;
F_13 ( V_1 , 0 , V_227 | V_133 , V_50 ) ;
F_54 ( V_1 , V_50 , V_133 , 0 ) ;
F_5 ( V_1 , V_175 , V_94 ) ;
F_110 ( V_1 , 0 ) ;
}
F_111 ( V_1 , 0 ) ;
F_56 ( V_1 , V_158 -> V_83 ) ;
}
static int F_133 ( unsigned char * V_104 )
{
if ( ( ( V_104 [ 0 ] & V_233 ) == V_234 ) &&
V_104 [ 1 ] == V_235 )
return 1 ;
else
return 0 ;
}
static int F_134 ( struct V_1 * V_1 , struct V_157 * V_158 )
{
F_135 ( ! V_158 ) ;
switch ( V_158 -> type ) {
case V_236 :
if ( F_133 ( V_158 -> V_100 -> V_104 ) ) {
V_158 -> V_237 = 1 ;
V_158 -> V_100 -> V_104 [ 2 ] = F_48 ( V_1 ,
V_158 -> V_100 ) ;
if ( V_158 -> V_100 -> V_104 [ 2 ] == 0 )
return - V_238 ;
}
F_126 ( V_1 , V_158 ) ;
break;
case V_239 :
F_127 ( V_1 , V_158 ) ;
break;
case V_240 :
F_129 ( V_1 , V_158 ) ;
break;
case V_241 :
F_132 ( V_1 , V_158 ) ;
break;
default:
F_12 ( V_22 L_16 ) ;
break;
}
return 0 ;
}
static int F_136 ( struct V_157 * V_158 , struct V_100 * V_100 )
{
if ( F_103 ( V_100 -> V_83 ) ) {
if ( V_100 -> V_242 == V_158 -> V_243 )
return 1 ;
}
if ( ( V_100 -> V_181 <= V_100 -> V_228 ) ||
( V_158 -> V_244 ) || ( V_158 -> V_245 ) )
return 1 ;
return 0 ;
}
static void F_137 ( struct V_1 * V_1 , struct V_157 * V_158 )
{
unsigned long time ;
F_135 ( ! V_158 ) ;
if ( ! F_98 ( & V_1 -> V_186 [ V_158 -> V_2 ] ) &&
! F_76 ( V_158 -> V_100 -> V_83 ) && F_67 ( V_158 -> V_100 -> V_83 ) ) {
V_1 -> V_246 |= 1 << V_158 -> V_2 ;
switch ( F_89 ( V_158 -> V_100 -> V_83 ) ) {
case V_247 :
case V_248 :
time = 30 ;
break;
default:
time = 300 ;
break;
}
F_116 ( & V_1 -> V_249 [ V_158 -> V_2 ] ,
V_196 + F_117 ( time ) ) ;
}
}
static void F_138 ( struct V_1 * V_1 , struct V_157 * V_158 ,
T_1 V_2 , struct V_100 * V_100 , int V_176 )
__releases( V_1 -> V_177 ) __acquires( V_1 -> V_177 )
{
int V_250 = 0 ;
struct V_251 * V_252 = F_93 ( V_1 ) ;
V_1 -> V_246 &= ~ ( 1 << V_2 ) ;
if ( F_139 ( V_158 ) ) {
if ( V_158 -> V_237 && ( V_176 != 0 || V_100 -> V_253 ) )
V_1 -> V_115 &= ~ ( 1 << V_100 -> V_104 [ 2 ] ) ;
F_69 ( V_1 , V_158 -> V_83 , V_100 ) ;
F_52 ( & V_158 -> V_187 ) ;
F_53 ( V_158 ) ;
}
if ( ! F_98 ( & V_1 -> V_186 [ V_2 ] ) )
V_250 = 1 ;
if ( F_139 ( V_100 ) ) {
if ( F_103 ( V_100 -> V_83 ) )
V_100 -> V_254 = F_140 ( V_252 ) ;
F_88 ( V_1 , V_100 , V_176 ) ;
}
if ( V_250 ) {
V_158 = F_141 ( V_1 , V_2 ) ;
if ( F_130 ( ! V_158 ) )
return;
F_134 ( V_1 , V_158 ) ;
F_137 ( V_1 , V_158 ) ;
}
}
static void F_142 ( struct V_1 * V_1 , T_1 V_2 )
{
T_1 V_4 ;
int V_255 , V_256 , V_257 , V_258 ;
T_1 * V_259 ;
struct V_157 * V_158 = F_141 ( V_1 , V_2 ) ;
struct V_100 * V_100 ;
int V_260 = 0 ;
int V_176 = 0 ;
if ( F_130 ( ! V_158 ) )
return;
V_100 = V_158 -> V_100 ;
F_62 ( V_1 , V_158 -> V_83 ) ;
V_4 = F_2 ( V_1 , V_158 -> V_83 -> V_91 ) ;
if ( F_130 ( ( V_4 & V_231 ) == 0 ) ) {
F_57 ( V_1 , V_158 -> V_83 ) ;
F_112 ( V_1 , V_2 ) ;
F_12 ( V_22 L_17 , V_2 ) ;
F_138 ( V_1 , V_158 , V_2 , V_158 -> V_100 , - V_238 ) ;
return;
}
V_255 = V_4 & V_261 ;
if ( F_103 ( V_100 -> V_83 ) ) {
V_259 = ( T_1 * ) ( V_100 -> V_180 +
V_100 -> V_262 [ V_158 -> V_243 ] . V_263 ) ;
V_257 = V_100 -> V_262 [ V_158 -> V_243 ] . V_264 ;
} else {
V_259 = ( void * ) V_100 -> V_180 + V_100 -> V_228 ;
V_257 = V_100 -> V_181 - V_100 -> V_228 ;
}
V_256 = V_163 ( V_257 , ( int ) V_158 -> V_153 ) ;
if ( V_255 <= V_256 ) {
V_258 = V_255 ;
} else {
V_258 = V_256 ;
V_176 = - V_265 ;
V_260 = 1 ;
}
V_100 -> V_228 += V_258 ;
if ( V_255 == 0 )
V_158 -> V_245 = 1 ;
if ( V_255 < V_256 ) {
V_158 -> V_244 = 1 ;
}
if ( F_103 ( V_100 -> V_83 ) ) {
V_100 -> V_262 [ V_158 -> V_243 ] . V_228 = V_258 ;
V_100 -> V_262 [ V_158 -> V_243 ] . V_176 = V_176 ;
V_158 -> V_243 ++ ;
V_260 = 0 ;
}
if ( V_260 || F_136 ( V_158 , V_100 ) ) {
F_57 ( V_1 , V_158 -> V_83 ) ;
F_112 ( V_1 , V_2 ) ;
V_260 = 1 ;
}
if ( V_100 -> V_180 ) {
if ( V_258 == 0 )
F_5 ( V_1 , V_175 , V_158 -> V_83 -> V_91 ) ;
else
F_143 ( V_1 , V_158 -> V_83 -> V_86 ,
V_259 , V_258 ) ;
}
if ( V_260 && V_2 != 0 )
F_138 ( V_1 , V_158 , V_2 , V_100 , V_176 ) ;
}
static void F_131 ( struct V_1 * V_1 , T_1 V_2 )
{
T_1 V_4 ;
int V_256 , V_258 ;
T_1 * V_259 ;
struct V_157 * V_158 = F_141 ( V_1 , V_2 ) ;
struct V_100 * V_100 ;
if ( F_130 ( ! V_158 ) )
return;
V_100 = V_158 -> V_100 ;
F_62 ( V_1 , V_158 -> V_83 ) ;
V_4 = F_2 ( V_1 , V_158 -> V_83 -> V_91 ) ;
if ( F_130 ( ( V_4 & V_231 ) == 0 ) ) {
F_57 ( V_1 , V_158 -> V_83 ) ;
F_112 ( V_1 , V_2 ) ;
F_12 ( V_22 L_18 , V_2 ) ;
F_138 ( V_1 , V_158 , V_2 , V_100 , - V_238 ) ;
return;
}
V_256 = V_158 -> V_153 ;
if ( F_103 ( V_100 -> V_83 ) ) {
V_259 = ( T_1 * ) ( V_100 -> V_180 +
V_100 -> V_262 [ V_158 -> V_243 ] . V_263 ) ;
V_258 = V_163 ( V_256 ,
( int ) V_100 -> V_262 [ V_158 -> V_243 ] . V_264 ) ;
} else {
V_259 = ( T_1 * ) ( V_100 -> V_180 + V_100 -> V_228 ) ;
V_258 = F_144 ( V_266 , V_256 ,
V_100 -> V_181 - V_100 -> V_228 ) ;
}
if ( V_2 > 0 )
F_5 ( V_1 , ~ ( 1 << V_2 ) , V_61 ) ;
if ( V_100 -> V_180 ) {
F_145 ( V_1 , V_158 -> V_83 -> V_86 , V_259 , V_258 ) ;
if ( ! F_146 ( V_100 -> V_83 ) || V_158 -> V_153 != V_258 )
F_5 ( V_1 , V_232 , V_158 -> V_83 -> V_91 ) ;
}
V_100 -> V_228 += V_258 ;
if ( F_103 ( V_100 -> V_83 ) ) {
V_100 -> V_262 [ V_158 -> V_243 ] . V_228 = V_258 ;
V_100 -> V_262 [ V_158 -> V_243 ] . V_176 = 0 ;
V_158 -> V_243 ++ ;
}
if ( F_136 ( V_158 , V_100 ) ) {
F_113 ( V_1 , V_2 ) ;
F_109 ( V_1 , V_2 ) ;
if ( ! F_103 ( V_100 -> V_83 ) )
F_111 ( V_1 , V_2 ) ;
} else
F_108 ( V_1 , V_100 , V_2 ) ;
}
static void F_147 ( struct V_1 * V_1 , int V_176 )
{
struct V_157 * V_158 = F_141 ( V_1 , 0 ) ;
struct V_100 * V_100 ;
T_2 V_260 = 0 ;
if ( F_130 ( ! V_158 ) )
return;
V_100 = V_158 -> V_100 ;
switch ( V_158 -> type ) {
case V_239 :
case V_240 :
if ( F_136 ( V_158 , V_100 ) )
V_158 -> type = V_241 ;
break;
case V_236 :
if ( V_100 -> V_181 == V_100 -> V_228 )
V_158 -> type = V_241 ;
else if ( F_75 ( V_100 -> V_83 ) )
V_158 -> type = V_240 ;
else
V_158 -> type = V_239 ;
break;
case V_241 :
V_260 = 1 ;
break;
}
if ( V_260 || V_176 != 0 || V_100 -> V_253 )
F_138 ( V_1 , V_158 , 0 , V_100 , V_176 ) ;
else
F_134 ( V_1 , V_158 ) ;
}
static int F_148 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_157 * V_158 = F_141 ( V_1 , V_2 ) ;
if ( V_158 ) {
T_1 V_267 = F_2 ( V_1 , V_158 -> V_83 -> V_96 ) & V_120 ;
if ( V_267 == V_122 )
return - V_268 ;
else
return - V_238 ;
}
return 0 ;
}
static void F_149 ( struct V_1 * V_1 )
{
T_1 V_269 ;
T_1 V_2 ;
T_1 V_118 ;
struct V_157 * V_158 ;
V_118 = F_2 ( V_1 , V_59 )
& F_2 ( V_1 , V_47 ) ;
F_5 ( V_1 , ~ V_118 , V_59 ) ;
if ( V_118 & V_46 ) {
V_158 = F_141 ( V_1 , 0 ) ;
if ( V_158 && V_158 -> type == V_239 )
F_142 ( V_1 , 0 ) ;
else
F_112 ( V_1 , 0 ) ;
F_147 ( V_1 , 0 ) ;
}
for ( V_2 = 1 ; V_2 < V_162 ; V_2 ++ ) {
V_269 = 1 << V_2 ;
if ( V_118 & V_269 ) {
V_158 = F_141 ( V_1 , V_2 ) ;
if ( F_130 ( ! V_158 ) )
continue;
if ( V_158 -> type == V_239 )
F_142 ( V_1 , V_2 ) ;
else if ( V_158 -> type == V_240 )
F_131 ( V_1 , V_2 ) ;
}
}
}
static void F_150 ( struct V_1 * V_1 )
{
T_1 V_4 ;
T_1 V_269 ;
T_1 V_2 ;
T_1 V_118 ;
struct V_157 * V_158 ;
V_118 = F_2 ( V_1 , V_61 )
& F_2 ( V_1 , V_49 ) ;
F_5 ( V_1 , ~ V_118 , V_61 ) ;
if ( V_118 & V_48 ) {
F_61 ( V_1 , 0 ) ;
V_158 = F_141 ( V_1 , 0 ) ;
if ( V_158 && V_158 -> type != V_240 )
F_151 ( V_1 , 0 ) ;
F_147 ( V_1 , 0 ) ;
}
for ( V_2 = 1 ; V_2 < V_162 ; V_2 ++ ) {
V_269 = 1 << V_2 ;
if ( V_118 & V_269 ) {
struct V_157 * V_158 ;
V_158 = F_141 ( V_1 , V_2 ) ;
if ( F_130 ( ! V_158 ) )
continue;
V_4 = F_2 ( V_1 , V_158 -> V_83 -> V_96 ) ;
if ( ( V_4 & V_270 ) == 0 ) {
F_151 ( V_1 , V_2 ) ;
F_112 ( V_1 , V_2 ) ;
F_138 ( V_1 , V_158 , V_2 , V_158 -> V_100 ,
0 ) ;
}
}
}
}
static void F_152 ( struct V_1 * V_1 )
{
T_1 V_269 ;
T_1 V_2 ;
T_1 V_118 ;
int V_176 ;
V_118 = F_2 ( V_1 , V_60 )
& F_2 ( V_1 , V_58 ) ;
F_5 ( V_1 , ~ V_118 , V_60 ) ;
if ( V_118 & V_271 ) {
F_61 ( V_1 , 0 ) ;
V_176 = F_148 ( V_1 , 0 ) ;
F_112 ( V_1 , 0 ) ;
F_147 ( V_1 , V_176 ) ;
}
for ( V_2 = 1 ; V_2 < V_162 ; V_2 ++ ) {
V_269 = 1 << V_2 ;
if ( V_118 & V_269 ) {
struct V_157 * V_158 ;
V_158 = F_141 ( V_1 , V_2 ) ;
if ( F_130 ( ! V_158 ) )
continue;
V_176 = F_148 ( V_1 , V_2 ) ;
F_112 ( V_1 , V_2 ) ;
F_57 ( V_1 , V_158 -> V_83 ) ;
F_138 ( V_1 , V_158 , V_2 , V_158 -> V_100 , V_176 ) ;
}
}
}
static T_5 F_153 ( struct V_251 * V_252 )
{
struct V_1 * V_1 = F_154 ( V_252 ) ;
T_1 V_272 , V_273 , V_274 ;
T_1 V_275 , V_276 , V_277 ;
T_1 V_278 , V_279 , V_280 ;
int V_176 ;
F_96 ( & V_1 -> V_177 ) ;
V_272 = F_2 ( V_1 , V_281 ) ;
V_273 = F_2 ( V_1 , V_224 ) ;
V_274 = F_2 ( V_1 , V_282 ) ;
V_275 = F_2 ( V_1 , V_5 ) ;
V_276 = F_2 ( V_1 , V_56 ) ;
V_277 = F_2 ( V_1 , V_283 ) ;
V_280 = V_274 & V_277 ;
V_279 = V_273 & V_276 ;
V_278 = V_272 & V_275 & ( V_284 | V_285 | V_286 ) ;
if ( V_280 ) {
if ( V_280 & V_209 ) {
F_5 ( V_1 , ~ V_209 , V_282 ) ;
F_3 ( V_1 , V_34 , V_283 ) ;
F_118 ( V_1 , 1 , 1 ) ;
}
if ( V_280 & V_212 ) {
F_5 ( V_1 , ~ V_212 , V_282 ) ;
F_3 ( V_1 , V_33 , V_283 ) ;
F_125 ( V_1 , 1 ) ;
}
if ( V_280 & V_287 ) {
F_5 ( V_1 , ~ V_287 , V_282 ) ;
F_3 ( V_1 , V_288 , V_283 ) ;
F_121 ( F_93 ( V_1 ) ) ;
}
}
if ( V_279 ) {
if ( V_279 & V_209 ) {
F_5 ( V_1 , ~ V_209 , V_224 ) ;
F_3 ( V_1 , V_34 , V_56 ) ;
F_118 ( V_1 , 0 , 1 ) ;
}
if ( V_279 & V_212 ) {
F_5 ( V_1 , ~ V_212 , V_224 ) ;
F_3 ( V_1 , V_33 , V_56 ) ;
F_125 ( V_1 , 0 ) ;
}
if ( V_279 & V_287 ) {
F_5 ( V_1 , ~ V_287 , V_224 ) ;
F_3 ( V_1 , V_288 , V_56 ) ;
F_121 ( F_93 ( V_1 ) ) ;
}
if ( V_279 & V_222 ) {
F_5 ( V_1 , ~ V_222 , V_224 ) ;
V_176 = F_148 ( V_1 , 0 ) ;
F_147 ( V_1 , V_176 ) ;
}
if ( V_279 & V_223 ) {
F_5 ( V_1 , ~ V_223 , V_224 ) ;
F_147 ( V_1 , 0 ) ;
}
}
if ( V_278 ) {
if ( V_278 & V_286 )
F_149 ( V_1 ) ;
if ( V_278 & V_284 )
F_150 ( V_1 ) ;
if ( V_278 & V_285 )
F_152 ( V_1 ) ;
}
F_94 ( & V_1 -> V_177 ) ;
return V_289 ;
}
static void F_155 ( struct V_1 * V_1 , int V_13 )
{
T_1 V_4 ;
struct V_199 * V_200 = & V_1 -> V_113 [ V_13 ] ;
if ( V_200 -> V_13 & V_216 ) {
unsigned long V_290 = F_156 ( V_13 ) ;
V_4 = F_2 ( V_1 , V_290 ) ;
if ( ( V_4 & V_291 ) == V_291 ) {
F_13 ( V_1 , V_292 , V_291 | V_292 ,
V_290 ) ;
F_115 ( V_1 ) ;
} else
F_123 ( V_1 , V_13 ) ;
}
if ( ! ( V_200 -> V_13 & V_205 ) ) {
F_5 ( V_1 , ~ V_209 , F_24 ( V_13 ) ) ;
F_4 ( V_1 , V_34 , F_22 ( V_13 ) ) ;
}
if ( V_200 -> V_203 > 0 ) {
V_4 = F_2 ( V_1 , F_119 ( V_13 ) ) & V_202 ;
if ( V_4 == V_200 -> V_201 ) {
V_200 -> V_203 -- ;
if ( V_200 -> V_203 == 0 )
F_120 ( V_1 , V_13 , V_4 ) ;
else
F_115 ( V_1 ) ;
} else {
V_200 -> V_203 = V_204 ;
V_200 -> V_201 = V_4 ;
F_115 ( V_1 ) ;
}
}
}
static void F_157 ( unsigned long V_293 )
{
struct V_1 * V_1 = (struct V_1 * ) V_293 ;
unsigned long V_294 ;
T_1 V_2 ;
struct V_157 * V_158 ;
F_158 ( & V_1 -> V_177 , V_294 ) ;
for ( V_2 = 0 ; V_2 < V_162 ; V_2 ++ ) {
if ( ! ( V_1 -> V_295 & ( 1 << V_2 ) ) )
continue;
if ( F_159 ( & V_1 -> V_296 [ V_2 ] ) )
continue;
V_158 = F_141 ( V_1 , V_2 ) ;
if ( V_158 )
F_134 ( V_1 , V_158 ) ;
}
F_160 ( & V_1 -> V_177 , V_294 ) ;
}
static void F_161 ( unsigned long V_293 )
{
struct V_1 * V_1 = (struct V_1 * ) V_293 ;
unsigned long V_294 ;
T_1 V_2 ;
struct V_157 * V_158 , * V_297 = NULL ;
struct V_82 * V_83 ;
F_158 ( & V_1 -> V_177 , V_294 ) ;
for ( V_2 = 0 ; V_2 < V_162 ; V_2 ++ ) {
if ( ! ( V_1 -> V_246 & ( 1 << V_2 ) ) )
continue;
if ( F_159 ( & V_1 -> V_249 [ V_2 ] ) )
continue;
V_158 = F_141 ( V_1 , V_2 ) ;
if ( ! V_158 ) {
V_1 -> V_246 &= ~ ( 1 << V_2 ) ;
continue;
}
if ( V_158 -> V_100 -> V_228 ) {
F_137 ( V_1 , V_158 ) ;
break;
}
V_83 = V_158 -> V_83 ;
F_57 ( V_1 , V_83 ) ;
V_297 = V_158 ;
do {
F_162 ( & V_297 -> V_187 ,
& V_1 -> V_186 [ V_2 ] ) ;
V_297 = F_141 ( V_1 , V_2 ) ;
if ( ! V_297 ) {
V_297 = V_158 ;
break;
}
} while ( V_158 != V_297 && V_158 -> V_68 == V_297 -> V_68 );
F_134 ( V_1 , V_297 ) ;
if ( V_158 == V_297 )
V_1 -> V_246 &= ~ ( 1 << V_2 ) ;
else
F_137 ( V_1 , V_297 ) ;
break;
}
F_160 ( & V_1 -> V_177 , V_294 ) ;
}
static void F_163 ( unsigned long V_293 )
{
struct V_1 * V_1 = (struct V_1 * ) V_293 ;
unsigned long V_294 ;
int V_13 ;
F_158 ( & V_1 -> V_177 , V_294 ) ;
for ( V_13 = 0 ; V_13 < V_1 -> V_57 ; V_13 ++ )
F_155 ( V_1 , V_13 ) ;
F_160 ( & V_1 -> V_177 , V_294 ) ;
}
static int F_164 ( struct V_1 * V_1 , struct V_100 * V_100 )
{
struct V_64 * V_65 = F_41 ( V_1 , V_100 ) ;
if ( V_65 && V_65 -> V_68 && V_65 -> V_107 != V_194 &&
( V_100 -> V_65 -> V_107 == V_194 ) )
return 1 ;
else
return 0 ;
}
static int F_165 ( struct V_251 * V_252 )
{
struct V_1 * V_1 = F_154 ( V_252 ) ;
V_252 -> V_107 = V_298 ;
return F_26 ( V_1 ) ;
}
static void F_166 ( struct V_251 * V_252 )
{
struct V_1 * V_1 = F_154 ( V_252 ) ;
F_27 ( V_1 ) ;
}
static void F_167 ( struct V_1 * V_1 , struct V_100 * V_100 )
{
unsigned int V_103 = F_42 ( V_100 -> V_83 ) ;
T_1 V_70 , V_71 ;
if ( V_103 == 0 ) {
F_32 ( V_1 , V_100 -> V_65 -> V_69 ,
& V_70 , & V_71 ) ;
F_7 ( V_1 , 0 ,
F_33 ( V_100 -> V_65 -> V_73 ) ,
F_28 ( V_1 , V_100 -> V_65 ) ,
V_71 , V_70 ) ;
}
}
static struct V_157 * F_168 ( struct V_1 * V_1 ,
struct V_100 * V_100 ,
struct V_134 * V_135 )
{
struct V_157 * V_158 ;
T_1 V_2 ;
V_158 = F_44 ( sizeof( struct V_157 ) , V_105 ) ;
if ( V_158 == NULL )
return NULL ;
V_2 = F_63 ( V_100 , V_135 ) ;
V_158 -> V_2 = V_2 ;
V_158 -> V_83 = V_135 -> V_136 ;
V_158 -> V_100 = V_100 ;
V_158 -> V_68 = F_65 ( V_1 , V_100 ) ;
V_158 -> V_153 = F_169 ( V_100 -> V_65 , V_100 -> V_83 ,
! F_67 ( V_100 -> V_83 ) ) ;
if ( F_76 ( V_100 -> V_83 ) )
V_158 -> type = V_236 ;
else if ( F_67 ( V_100 -> V_83 ) )
V_158 -> type = V_239 ;
else
V_158 -> type = V_240 ;
F_46 ( & V_158 -> V_187 ) ;
return V_158 ;
}
static int F_170 ( struct V_251 * V_252 ,
struct V_100 * V_100 ,
T_6 V_299 )
{
struct V_134 * V_135 = V_100 -> V_160 ;
struct V_1 * V_1 = F_154 ( V_252 ) ;
struct V_157 * V_158 = NULL ;
int V_37 , V_300 = 0 ;
unsigned long V_294 ;
F_158 ( & V_1 -> V_177 , V_294 ) ;
if ( ! F_41 ( V_1 , V_100 ) ) {
V_37 = - V_188 ;
goto V_301;
}
V_37 = F_171 ( V_252 , V_100 ) ;
if ( V_37 )
goto V_301;
if ( ! V_135 -> V_136 ) {
V_135 -> V_136 = F_44 ( sizeof( struct V_82 ) ,
V_105 ) ;
if ( ! V_135 -> V_136 ) {
V_37 = - V_106 ;
goto error;
}
F_36 ( V_135 -> V_136 , V_95 ) ;
if ( F_64 ( V_100 -> V_83 ) )
F_104 ( V_1 , V_100 , V_135 , & V_135 -> V_302 ) ;
}
if ( F_130 ( F_164 ( V_1 , V_100 ) ) )
F_107 ( V_1 , V_100 ) ;
F_167 ( V_1 , V_100 ) ;
V_158 = F_168 ( V_1 , V_100 , V_135 ) ;
if ( V_158 == NULL ) {
V_37 = - V_106 ;
goto error;
}
if ( F_98 ( & V_1 -> V_186 [ V_158 -> V_2 ] ) )
V_300 = 1 ;
F_47 ( & V_158 -> V_187 , & V_1 -> V_186 [ V_158 -> V_2 ] ) ;
V_100 -> V_136 = V_158 ;
if ( V_300 ) {
if ( V_158 -> V_83 -> V_85 . V_192 ) {
V_1 -> V_295 |= 1 << V_158 -> V_2 ;
F_116 ( & V_1 -> V_296 [ V_158 -> V_2 ] ,
V_196 + F_117 (
V_158 -> V_83 -> V_85 . V_192 ) ) ;
} else {
V_37 = F_134 ( V_1 , V_158 ) ;
if ( V_37 < 0 ) {
F_52 ( & V_158 -> V_187 ) ;
F_53 ( V_158 ) ;
}
}
} else
F_137 ( V_1 , V_158 ) ;
error:
if ( V_37 )
F_92 ( V_252 , V_100 ) ;
V_301:
F_160 ( & V_1 -> V_177 , V_294 ) ;
return V_37 ;
}
static int F_172 ( struct V_251 * V_252 , struct V_100 * V_100 ,
int V_176 )
{
struct V_1 * V_1 = F_154 ( V_252 ) ;
struct V_157 * V_158 ;
unsigned long V_294 ;
int V_303 ;
F_158 ( & V_1 -> V_177 , V_294 ) ;
V_303 = F_173 ( V_252 , V_100 , V_176 ) ;
if ( V_303 )
goto V_304;
if ( V_100 -> V_136 ) {
V_158 = V_100 -> V_136 ;
F_57 ( V_1 , V_158 -> V_83 ) ;
F_112 ( V_1 , V_158 -> V_2 ) ;
F_151 ( V_1 , V_158 -> V_2 ) ;
F_138 ( V_1 , V_158 , V_158 -> V_2 , V_100 , V_176 ) ;
}
V_304:
F_160 ( & V_1 -> V_177 , V_294 ) ;
return V_303 ;
}
static void F_174 ( struct V_251 * V_252 ,
struct V_134 * V_135 )
{
struct V_1 * V_1 = F_154 ( V_252 ) ;
struct V_82 * V_83 = (struct V_82 * ) V_135 -> V_136 ;
struct V_157 * V_158 ;
struct V_100 * V_100 = NULL ;
T_1 V_2 ;
unsigned long V_294 ;
if ( V_83 == NULL )
return;
V_2 = V_83 -> V_85 . V_2 ;
if ( V_2 == 0 ) {
F_53 ( V_135 -> V_136 ) ;
V_135 -> V_136 = NULL ;
return;
}
F_158 ( & V_1 -> V_177 , V_294 ) ;
F_57 ( V_1 , V_83 ) ;
F_112 ( V_1 , V_2 ) ;
F_151 ( V_1 , V_2 ) ;
V_158 = F_141 ( V_1 , V_2 ) ;
if ( V_158 )
V_100 = V_158 -> V_100 ;
F_138 ( V_1 , V_158 , V_2 , V_100 , - V_305 ) ;
F_53 ( V_135 -> V_136 ) ;
V_135 -> V_136 = NULL ;
F_160 ( & V_1 -> V_177 , V_294 ) ;
}
static int F_140 ( struct V_251 * V_252 )
{
struct V_1 * V_1 = F_154 ( V_252 ) ;
return F_2 ( V_1 , V_306 ) & 0x03FF ;
}
static void F_175 ( struct V_62 * V_63 , unsigned long * V_307 )
{
int V_308 ;
if ( V_63 -> V_107 == V_194 &&
V_63 -> V_66 && V_63 -> V_66 -> V_67 > 1 &&
V_63 -> V_66 -> V_309 . V_310 == V_311 )
V_307 [ V_63 -> V_67 / 32 ] |= ( 1 << ( V_63 -> V_67 % 32 ) ) ;
for ( V_308 = 0 ; V_308 < V_63 -> V_312 ; V_308 ++ ) {
struct V_62 * V_313 = V_63 -> V_314 [ V_308 ] ;
if ( V_313 )
F_175 ( V_313 , V_307 ) ;
}
}
static struct V_64 * F_176 ( struct V_1 * V_1 ,
int V_102 )
{
struct V_64 * V_65 ;
struct V_184 * V_185 = & V_1 -> V_112 ;
F_177 (dev, list, device_list) {
if ( V_65 -> V_103 != V_102 )
continue;
return V_65 ;
}
F_12 ( V_22 L_19 , V_102 ) ;
return NULL ;
}
static void F_178 ( struct V_1 * V_1 ,
struct V_62 * V_113 ,
unsigned long * V_307 )
{
int V_16 , V_315 , V_102 ;
unsigned long V_316 ;
unsigned long V_294 ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ ) {
V_316 = V_1 -> V_81 [ V_16 ] ^ V_307 [ V_16 ] ;
if ( ! V_316 )
continue;
for ( V_315 = 0 ; V_315 < 32 ; V_315 ++ ) {
if ( ! ( V_316 & ( 1 << V_315 ) ) )
continue;
V_102 = V_16 * 32 + V_315 ;
if ( V_307 [ V_16 ] & ( 1 << V_315 ) )
F_34 ( V_1 , V_102 ) ;
else {
struct V_64 * V_65 ;
F_158 ( & V_1 -> V_177 , V_294 ) ;
V_65 = F_176 ( V_1 , V_102 ) ;
F_100 ( V_1 , V_65 ) ;
F_51 ( V_1 , V_65 , 0 ) ;
F_35 ( V_1 , V_102 ) ;
F_160 ( & V_1 -> V_177 , V_294 ) ;
}
}
}
}
static void F_179 ( struct V_1 * V_1 ,
struct V_251 * V_252 )
{
struct V_317 * V_318 ;
unsigned long V_319 [ 4 ] ;
memset ( V_319 , 0 , sizeof( V_319 ) ) ;
F_177 (bus, &usb_bus_list, bus_list) {
if ( ! V_318 -> V_113 )
continue;
if ( V_318 -> V_320 != V_252 -> V_321 . V_320 )
continue;
F_175 ( V_318 -> V_113 , V_319 ) ;
F_178 ( V_1 , V_318 -> V_113 , V_319 ) ;
}
}
static int F_180 ( struct V_251 * V_252 , char * V_259 )
{
struct V_1 * V_1 = F_154 ( V_252 ) ;
unsigned long V_294 ;
int V_16 ;
F_179 ( V_1 , V_252 ) ;
F_158 ( & V_1 -> V_177 , V_294 ) ;
* V_259 = 0 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_57 ; V_16 ++ ) {
if ( V_1 -> V_113 [ V_16 ] . V_13 & 0xffff0000 )
* V_259 |= 1 << ( V_16 + 1 ) ;
}
F_160 ( & V_1 -> V_177 , V_294 ) ;
return ( * V_259 != 0 ) ;
}
static void F_181 ( struct V_1 * V_1 ,
struct V_322 * V_302 )
{
V_302 -> V_323 = 0x29 ;
V_302 -> V_324 = 0 ;
V_302 -> V_325 = V_1 -> V_57 ;
V_302 -> V_326 = 9 ;
V_302 -> V_327 = 0 ;
V_302 -> V_328 = F_182 ( 0x0011 ) ;
V_302 -> V_329 . V_330 . V_331 [ 0 ] =
( ( 1 << V_1 -> V_57 ) - 1 ) << 1 ;
V_302 -> V_329 . V_330 . V_331 [ 1 ] = ~ 0 ;
}
static int F_183 ( struct V_251 * V_252 , T_1 V_332 , T_1 V_333 ,
T_1 V_334 , char * V_259 , T_1 V_335 )
{
struct V_1 * V_1 = F_154 ( V_252 ) ;
int V_37 ;
int V_13 = ( V_334 & 0x00FF ) - 1 ;
struct V_199 * V_200 = & V_1 -> V_113 [ V_13 ] ;
unsigned long V_294 ;
V_37 = 0 ;
F_158 ( & V_1 -> V_177 , V_294 ) ;
switch ( V_332 ) {
case V_336 :
case V_337 :
switch ( V_333 ) {
case V_338 :
case V_339 :
break;
default:
goto error;
}
break;
case V_340 :
if ( V_334 > V_1 -> V_57 )
goto error;
if ( V_335 != 0 )
goto error;
switch ( V_333 ) {
case V_341 :
V_200 -> V_13 &= ~ V_342 ;
break;
case V_343 :
break;
case V_344 :
F_25 ( V_1 , V_13 , 0 ) ;
break;
case V_345 :
case V_346 :
case V_347 :
case V_348 :
case V_349 :
break;
default:
goto error;
}
V_200 -> V_13 &= ~ ( 1 << V_333 ) ;
break;
case V_350 :
F_181 ( V_1 ,
(struct V_322 * ) V_259 ) ;
break;
case V_351 :
* V_259 = 0x00 ;
break;
case V_352 :
if ( V_334 > V_1 -> V_57 )
goto error;
* ( V_353 * ) V_259 = F_184 ( V_200 -> V_13 ) ;
break;
case V_354 :
if ( V_334 > V_1 -> V_57 )
goto error;
if ( V_335 != 0 )
goto error;
switch ( V_333 ) {
case V_343 :
break;
case V_344 :
F_25 ( V_1 , V_13 , 1 ) ;
V_200 -> V_13 |= V_342 ;
break;
case V_355 : {
struct V_64 * V_65 = V_200 -> V_65 ;
V_200 -> V_13 |= V_216 ;
F_100 ( V_1 , V_65 ) ;
F_51 ( V_1 , V_65 , 1 ) ;
F_13 ( V_1 , V_291 , V_291 | V_292 ,
F_156 ( V_13 ) ) ;
F_116 ( & V_1 -> V_195 ,
V_196 + F_117 ( 50 ) ) ;
}
break;
default:
goto error;
}
V_200 -> V_13 |= 1 << V_333 ;
break;
default:
error:
V_37 = - V_238 ;
break;
}
F_160 ( & V_1 -> V_177 , V_294 ) ;
return V_37 ;
}
static int F_185 ( struct V_251 * V_252 )
{
struct V_1 * V_1 = F_154 ( V_252 ) ;
int V_13 ;
F_50 ( L_20 , V_356 ) ;
for ( V_13 = 0 ; V_13 < V_1 -> V_57 ; V_13 ++ ) {
struct V_199 * V_200 = & V_1 -> V_113 [ V_13 ] ;
unsigned long V_290 = F_156 ( V_13 ) ;
if ( ! ( V_200 -> V_13 & V_217 ) )
continue;
F_50 ( L_21 , V_13 ) ;
F_3 ( V_1 , V_292 , V_290 ) ;
V_200 -> V_13 |= V_357 ;
if ( V_200 -> V_65 -> V_63 -> V_358 ) {
F_15 ( 3 ) ;
F_4 ( V_1 , V_359 , V_290 ) ;
F_5 ( V_1 , ~ V_287 , F_24 ( V_13 ) ) ;
F_4 ( V_1 , V_288 , F_22 ( V_13 ) ) ;
}
}
V_1 -> V_213 = 1 ;
return 0 ;
}
static int F_186 ( struct V_251 * V_252 )
{
struct V_1 * V_1 = F_154 ( V_252 ) ;
int V_13 ;
F_50 ( L_20 , V_356 ) ;
for ( V_13 = 0 ; V_13 < V_1 -> V_57 ; V_13 ++ ) {
struct V_199 * V_200 = & V_1 -> V_113 [ V_13 ] ;
unsigned long V_290 = F_156 ( V_13 ) ;
if ( ! ( V_200 -> V_13 & V_357 ) )
continue;
F_50 ( L_22 , V_13 ) ;
V_200 -> V_13 &= ~ V_357 ;
V_200 -> V_13 |= V_360 < 16 ;
F_13 ( V_1 , V_361 , V_361 | V_292 , V_290 ) ;
F_15 ( 50 ) ;
F_13 ( V_1 , V_292 , V_361 | V_292 , V_290 ) ;
}
return 0 ;
}
static int F_187 ( struct V_362 * V_65 )
{
struct V_1 * V_1 = F_29 ( V_65 ) ;
int V_13 ;
F_50 ( L_20 , V_356 ) ;
F_27 ( V_1 ) ;
for ( V_13 = 0 ; V_13 < V_1 -> V_57 ; V_13 ++ ) {
struct V_199 * V_200 = & V_1 -> V_113 [ V_13 ] ;
V_200 -> V_13 = 0x00000000 ;
}
return 0 ;
}
static int F_188 ( struct V_362 * V_65 )
{
struct V_1 * V_1 = F_29 ( V_65 ) ;
struct V_251 * V_252 = F_93 ( V_1 ) ;
F_50 ( L_20 , V_356 ) ;
F_26 ( V_1 ) ;
F_189 ( V_252 -> V_321 . V_113 ) ;
return 0 ;
}
static int T_7 F_190 ( struct V_363 * V_364 )
{
struct V_1 * V_1 = F_29 ( & V_364 -> V_65 ) ;
struct V_251 * V_252 = F_93 ( V_1 ) ;
F_191 ( & V_1 -> V_195 ) ;
F_192 ( V_252 ) ;
F_193 ( V_1 -> V_3 ) ;
#ifdef F_10
if ( V_1 -> V_17 -> V_18 )
F_194 ( V_1 -> V_19 ) ;
#endif
F_195 ( V_252 ) ;
return 0 ;
}
static int T_8 F_196 ( struct V_363 * V_364 )
{
#ifdef F_10
char V_365 [ 8 ] ;
#endif
struct V_366 * V_367 = NULL , * V_368 ;
int V_369 = - 1 ;
void T_9 * V_3 = NULL ;
struct V_251 * V_252 = NULL ;
struct V_1 * V_1 ;
int V_37 = 0 ;
int V_16 ;
unsigned long V_370 ;
if ( V_364 -> V_65 . V_371 ) {
V_37 = - V_372 ;
F_49 ( & V_364 -> V_65 , L_23 ) ;
goto V_373;
}
V_367 = F_197 ( V_364 , V_374 , 0 ) ;
if ( ! V_367 ) {
V_37 = - V_188 ;
F_49 ( & V_364 -> V_65 , L_24 ) ;
goto V_373;
}
V_368 = F_197 ( V_364 , V_375 , 0 ) ;
if ( ! V_368 ) {
V_37 = - V_188 ;
F_49 ( & V_364 -> V_65 ,
L_25 ) ;
goto V_373;
}
V_369 = V_368 -> V_376 ;
V_370 = V_368 -> V_294 & V_377 ;
V_3 = F_198 ( V_367 -> V_376 , F_199 ( V_367 ) ) ;
if ( V_3 == NULL ) {
V_37 = - V_106 ;
F_49 ( & V_364 -> V_65 , L_26 ) ;
goto V_373;
}
if ( V_364 -> V_65 . V_378 == NULL ) {
F_49 ( & V_364 -> V_65 , L_27 ) ;
V_37 = - V_188 ;
goto V_373;
}
V_252 = F_200 ( & V_379 , & V_364 -> V_65 , ( char * ) V_380 ) ;
if ( ! V_252 ) {
V_37 = - V_106 ;
F_49 ( & V_364 -> V_65 , L_28 ) ;
goto V_373;
}
V_1 = F_154 ( V_252 ) ;
memset ( V_1 , 0 , sizeof( struct V_1 ) ) ;
F_45 ( & V_364 -> V_65 , V_1 ) ;
V_1 -> V_17 = V_364 -> V_65 . V_378 ;
V_1 -> V_41 = V_370 == V_381 ;
if ( V_1 -> V_17 -> V_18 ) {
#ifdef F_10
snprintf ( V_365 , sizeof( V_365 ) , L_29 , V_364 -> V_382 ) ;
V_1 -> V_19 = F_201 ( & V_364 -> V_65 , V_365 ) ;
if ( F_202 ( V_1 -> V_19 ) ) {
F_49 ( & V_364 -> V_65 , L_30 ,
V_365 ) ;
V_37 = F_203 ( V_1 -> V_19 ) ;
goto V_383;
}
#endif
V_1 -> V_57 = 1 ;
} else
V_1 -> V_57 = 2 ;
F_204 ( & V_1 -> V_177 ) ;
F_205 ( & V_1 -> V_195 ) ;
V_1 -> V_195 . V_384 = F_163 ;
V_1 -> V_195 . V_385 = ( unsigned long ) V_1 ;
V_1 -> V_3 = V_3 ;
V_37 = F_9 ( V_1 ) ;
if ( V_37 < 0 )
goto V_386;
F_27 ( V_1 ) ;
for ( V_16 = 0 ; V_16 < V_162 ; V_16 ++ ) {
F_46 ( & V_1 -> V_186 [ V_16 ] ) ;
F_205 ( & V_1 -> V_249 [ V_16 ] ) ;
V_1 -> V_249 [ V_16 ] . V_384 = F_161 ;
V_1 -> V_249 [ V_16 ] . V_385 = ( unsigned long ) V_1 ;
F_206 ( & V_1 -> V_296 [ V_16 ] ,
F_157 ,
( unsigned long ) V_1 ) ;
}
F_46 ( & V_1 -> V_112 ) ;
V_252 -> V_387 = V_367 -> V_376 ;
V_252 -> V_388 = 1 ;
V_37 = F_207 ( V_252 , V_369 , V_389 | V_370 ) ;
if ( V_37 != 0 ) {
F_49 ( & V_364 -> V_65 , L_31 ) ;
goto V_386;
}
return 0 ;
V_386:
#ifdef F_10
if ( V_1 -> V_17 -> V_18 )
F_194 ( V_1 -> V_19 ) ;
V_383:
#endif
F_195 ( V_252 ) ;
V_373:
if ( V_3 )
F_193 ( V_3 ) ;
return V_37 ;
}
static int T_10 F_208 ( void )
{
if ( F_209 () )
return - V_188 ;
F_12 (KERN_INFO KBUILD_MODNAME L_32 , hcd_name,
DRIVER_VERSION) ;
return F_210 ( & V_390 ) ;
}
static void T_11 F_211 ( void )
{
F_212 ( & V_390 ) ;
}
