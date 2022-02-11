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
F_10 ( V_1 -> V_19 ) ;
do {
F_5 ( V_1 , V_20 , V_21 ) ;
V_4 = F_2 ( V_1 , V_21 ) ;
if ( V_16 ++ > 1000 ) {
F_11 ( V_22 L_1 ) ;
return - V_23 ;
}
} while ( ( V_4 & V_20 ) != V_20 );
F_5 ( V_1 , 0x04 , 0x02 ) ;
} else {
do {
F_5 ( V_1 , V_24 , V_21 ) ;
V_4 = F_2 ( V_1 , V_21 ) ;
if ( V_16 ++ > 1000 ) {
F_11 ( V_22 L_1 ) ;
return - V_23 ;
}
} while ( ( V_4 & V_24 ) != V_24 );
F_3 ( V_1 , V_24 , V_21 ) ;
F_12 ( V_1 , F_13 ( V_1 -> V_17 ) ,
V_25 , V_21 ) ;
V_16 = 0 ;
F_4 ( V_1 , V_26 , V_21 ) ;
do {
F_14 ( 1 ) ;
V_4 = F_2 ( V_1 , V_21 ) ;
if ( V_16 ++ > 500 ) {
F_11 ( V_22 L_1 ) ;
return - V_23 ;
}
} while ( ( V_4 & V_20 ) != V_20 );
}
return 0 ;
}
static void F_15 ( struct V_1 * V_1 )
{
F_3 ( V_1 , V_20 , V_21 ) ;
F_16 ( 1 ) ;
if ( V_1 -> V_17 -> V_18 ) {
F_17 ( V_1 -> V_19 ) ;
} else {
F_3 ( V_1 , V_27 , V_21 ) ;
F_3 ( V_1 , V_26 , V_21 ) ;
F_3 ( V_1 , V_24 , V_21 ) ;
}
}
static void F_18 ( struct V_1 * V_1 , int V_13 )
{
T_1 V_14 ;
V_14 = V_13 ? V_28 : V_29 | V_28 ;
F_4 ( V_1 , V_14 , F_19 ( V_13 ) ) ;
F_4 ( V_1 , V_30 , F_19 ( V_13 ) ) ;
F_5 ( V_1 , V_31 | V_32 , F_20 ( V_13 ) ) ;
F_3 ( V_1 , V_33 , F_21 ( V_13 ) ) ;
F_4 ( V_1 , V_34 , F_21 ( V_13 ) ) ;
}
static void F_22 ( struct V_1 * V_1 , int V_13 )
{
T_1 V_14 , V_4 ;
F_5 ( V_1 , 0 , F_21 ( V_13 ) ) ;
F_5 ( V_1 , 0 , F_23 ( V_13 ) ) ;
F_24 ( V_1 , V_13 , 0 ) ;
do {
V_4 = F_2 ( V_1 , V_35 ) & V_36 ;
F_16 ( 640 ) ;
} while ( V_4 == V_36 );
V_14 = V_13 ? V_28 : V_29 | V_28 ;
F_3 ( V_1 , V_14 , F_19 ( V_13 ) ) ;
F_3 ( V_1 , V_30 , F_19 ( V_13 ) ) ;
}
static int F_25 ( struct V_1 * V_1 )
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
F_18 ( V_1 , V_13 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_1 )
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
F_22 ( V_1 , V_13 ) ;
F_15 ( V_1 ) ;
}
static int F_27 ( struct V_1 * V_1 ,
struct V_62 * V_63 )
{
struct V_64 * V_65 ;
if ( V_63 -> V_66 && V_63 -> V_66 -> V_67 != 1 )
V_63 = V_63 -> V_66 ;
V_65 = F_28 ( & V_63 -> V_65 ) ;
if ( V_65 )
return V_65 -> V_68 ;
else
return 0 ;
}
static int F_29 ( char * V_69 )
{
return ( V_69 [ 2 ] ? 1 : 0 ) ;
}
static int F_30 ( char * V_69 )
{
return ( ( strlen ( V_69 ) >= 4 ) ? 1 : 0 ) ;
}
static void F_31 ( struct V_1 * V_1 ,
char * V_69 , T_1 * V_70 , T_1 * V_71 )
{
if ( V_70 ) {
* V_70 = ( V_69 [ 0 ] & 0x0F ) - 1 ;
if ( * V_70 >= V_1 -> V_57 )
F_11 ( V_22 L_2 ) ;
}
if ( V_71 )
* V_71 = V_69 [ 2 ] & 0x0F ;
}
static T_1 F_32 ( enum V_72 V_73 )
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
F_11 ( V_22 L_3 ) ;
break;
}
return V_10 ;
}
static void F_33 ( struct V_1 * V_1 , int V_68 )
{
int V_80 ;
V_80 = V_68 / 32 ;
V_1 -> V_81 [ V_80 ] |= 1 << ( V_68 % 32 ) ;
}
static void F_34 ( struct V_1 * V_1 , int V_68 )
{
int V_80 ;
V_80 = V_68 / 32 ;
V_1 -> V_81 [ V_80 ] &= ~ ( 1 << ( V_68 % 32 ) ) ;
}
static void F_35 ( struct V_82 * V_83 , T_2 V_84 )
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
V_83 -> V_96 = F_36 ( V_2 ) ;
if ( F_37 ( V_2 ) ) {
V_83 -> V_98 = F_38 ( V_2 ) ;
V_83 -> V_99 = F_39 ( V_2 ) ;
} else {
V_83 -> V_98 = 0 ;
V_83 -> V_99 = 0 ;
}
}
static struct V_64 *
F_40 ( struct V_1 * V_1 , struct V_100 * V_100 )
{
if ( F_41 ( V_100 -> V_83 ) == 0 )
return & V_1 -> V_101 ;
return F_28 ( & V_100 -> V_65 -> V_65 ) ;
}
static int F_42 ( struct V_1 * V_1 ,
struct V_100 * V_100 , T_2 V_102 )
{
struct V_64 * V_65 ;
int V_103 = V_100 -> V_104 [ 2 ] ;
V_65 = F_43 ( sizeof( struct V_64 ) , V_105 ) ;
if ( V_65 == NULL )
return - V_106 ;
F_44 ( & V_100 -> V_65 -> V_65 , V_65 ) ;
V_65 -> V_63 = V_100 -> V_65 ;
V_65 -> V_68 = V_102 ;
V_65 -> V_103 = V_103 ;
V_65 -> V_107 = V_108 ;
V_65 -> V_109 = 0 ;
V_65 -> V_110 = 0 ;
F_45 ( & V_65 -> V_111 ) ;
F_46 ( & V_65 -> V_111 , & V_1 -> V_112 ) ;
F_31 ( V_1 , V_100 -> V_65 -> V_69 ,
& V_65 -> V_70 , & V_65 -> V_71 ) ;
if ( ! F_29 ( V_100 -> V_65 -> V_69 ) )
V_1 -> V_113 [ V_65 -> V_70 ] . V_65 = V_65 ;
F_7 ( V_1 , V_65 -> V_68 ,
F_32 ( V_100 -> V_65 -> V_73 ) ,
F_27 ( V_1 , V_100 -> V_65 ) ,
V_65 -> V_71 , V_65 -> V_70 ) ;
return 0 ;
}
static T_2 F_47 ( struct V_1 * V_1 , struct V_100 * V_100 )
{
T_2 V_102 ;
struct V_64 * V_65 ;
if ( F_30 ( V_100 -> V_65 -> V_69 ) ) {
F_48 ( & V_100 -> V_65 -> V_65 , L_4 ) ;
return 0 ;
}
V_65 = F_40 ( V_1 , V_100 ) ;
if ( V_65 && V_65 -> V_107 >= V_108 )
return V_65 -> V_68 ;
for ( V_102 = 1 ; V_102 <= V_114 ; V_102 ++ ) {
if ( V_1 -> V_115 & ( 1 << V_102 ) )
continue;
F_49 ( & V_100 -> V_65 -> V_65 , L_5 , V_102 ) ;
V_1 -> V_115 |= 1 << V_102 ;
if ( F_42 ( V_1 , V_100 , V_102 ) < 0 )
return 0 ;
return V_102 ;
}
F_48 ( & V_100 -> V_65 -> V_65 ,
L_6 ,
V_1 -> V_115 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_1 ,
struct V_64 * V_65 , int V_116 )
{
int V_13 ;
if ( ! V_65 )
return;
F_49 ( & V_65 -> V_63 -> V_65 , L_7 , V_65 -> V_68 ) ;
V_65 -> V_107 = V_117 ;
V_1 -> V_115 &= ~ ( 1 << V_65 -> V_68 ) ;
V_65 -> V_68 = 0 ;
if ( V_116 )
F_44 ( & V_65 -> V_63 -> V_65 , NULL ) ;
F_51 ( & V_65 -> V_111 ) ;
F_52 ( V_65 ) ;
for ( V_13 = 0 ; V_13 < V_1 -> V_57 ; V_13 ++ ) {
if ( V_1 -> V_113 [ V_13 ] . V_65 == V_65 ) {
V_1 -> V_113 [ V_13 ] . V_65 = NULL ;
break;
}
}
}
static void F_53 ( struct V_1 * V_1 , unsigned long V_3 ,
T_1 V_118 , T_1 V_119 )
{
T_1 V_4 ;
int V_16 = 0 ;
do {
V_4 = F_2 ( V_1 , V_3 ) ;
if ( V_16 ++ > 1000000 ) {
F_11 ( V_22 L_8
L_9 , V_3 , V_119 ) ;
break;
}
F_54 ( 1 ) ;
} while ( ( V_4 & V_118 ) != V_119 );
}
static void F_55 ( struct V_1 * V_1 , struct V_82 * V_83 )
{
T_1 V_4 ;
V_4 = F_2 ( V_1 , V_83 -> V_96 ) & V_120 ;
if ( ( V_83 -> V_85 . V_2 != 0 ) & ( ( V_4 & V_121 ) != 0 ) )
F_12 ( V_1 , V_122 , V_120 , V_83 -> V_96 ) ;
F_12 ( V_1 , V_123 , V_120 , V_83 -> V_96 ) ;
}
static void F_56 ( struct V_1 * V_1 , struct V_82 * V_83 )
{
T_1 V_4 ;
V_4 = F_2 ( V_1 , V_83 -> V_96 ) & V_120 ;
if ( ( V_4 & V_124 ) != V_124 )
F_12 ( V_1 , V_121 , V_120 , V_83 -> V_96 ) ;
F_12 ( V_1 , V_122 , V_120 , V_83 -> V_96 ) ;
F_53 ( V_1 , V_83 -> V_96 , V_125 , 0 ) ;
}
static void F_57 ( struct V_1 * V_1 ,
struct V_82 * V_83 )
{
T_1 V_4 ;
if ( ! V_83 || V_83 -> V_85 . V_2 == 0 )
return;
F_56 ( V_1 , V_83 ) ;
F_4 ( V_1 , V_126 , V_83 -> V_96 ) ;
V_4 = F_2 ( V_1 , V_83 -> V_96 ) ;
V_4 = F_2 ( V_1 , V_83 -> V_96 ) ;
V_4 = F_2 ( V_1 , V_83 -> V_96 ) ;
F_3 ( V_1 , V_126 , V_83 -> V_96 ) ;
}
static void F_58 ( struct V_1 * V_1 ,
struct V_82 * V_83 , int V_127 )
{
if ( V_127 )
F_4 ( V_1 , V_128 , V_83 -> V_96 ) ;
else
F_4 ( V_1 , V_129 , V_83 -> V_96 ) ;
}
static inline unsigned short F_59 ( struct V_1 * V_1 )
{
if ( V_1 -> V_17 -> V_18 )
return V_130 ;
else
return V_131 ;
}
static inline void F_60 ( struct V_1 * V_1 , T_1 V_2 )
{
unsigned short V_132 = F_59 ( V_1 ) ;
F_12 ( V_1 , V_132 | V_2 , V_132 | V_133 , V_50 ) ;
F_53 ( V_1 , V_50 , V_133 , V_2 ) ;
}
static inline void F_61 ( struct V_1 * V_1 ,
struct V_82 * V_83 )
{
unsigned short V_132 = F_59 ( V_1 ) ;
F_60 ( V_1 , 0 ) ;
F_12 ( V_1 , V_132 | 0 , V_132 | V_133 , V_51 ) ;
F_12 ( V_1 , V_132 | 0 , V_132 | V_133 , V_52 ) ;
F_12 ( V_1 , V_132 | V_83 -> V_85 . V_2 , V_132 | V_133 ,
V_83 -> V_90 ) ;
F_53 ( V_1 , V_83 -> V_90 , V_133 , V_83 -> V_85 . V_2 ) ;
}
static T_1 F_62 ( struct V_100 * V_100 , struct V_134 * V_135 )
{
struct V_82 * V_83 = V_135 -> V_136 ;
if ( F_63 ( V_100 -> V_83 ) == 0 )
return 0 ;
else
return V_83 -> V_85 . V_2 ;
}
static T_1 F_64 ( struct V_1 * V_1 , struct V_100 * V_100 )
{
struct V_64 * V_65 = F_40 ( V_1 , V_100 ) ;
return ( F_41 ( V_100 -> V_83 ) == 0 ) ? 0 : V_65 -> V_68 ;
}
static unsigned short * F_65 ( struct V_64 * V_65 ,
int V_137 )
{
if ( ! V_65 )
return NULL ;
return F_66 ( V_137 ) ? & V_65 -> V_109 : & V_65 -> V_110 ;
}
static void F_67 ( struct V_1 * V_1 ,
struct V_82 * V_83 ,
struct V_100 * V_100 , int V_138 )
{
struct V_64 * V_65 = F_40 ( V_1 , V_100 ) ;
unsigned char V_139 = F_63 ( V_100 -> V_83 ) ;
unsigned short * V_127 = F_65 ( V_65 , V_100 -> V_83 ) ;
if ( ! V_127 )
return;
if ( V_138 )
* V_127 |= 1 << V_139 ;
else
* V_127 &= ~ ( 1 << V_139 ) ;
}
static void F_68 ( struct V_1 * V_1 ,
struct V_82 * V_83 ,
struct V_100 * V_100 )
{
if ( F_2 ( V_1 , V_83 -> V_96 ) & V_140 )
F_67 ( V_1 , V_83 , V_100 , 1 ) ;
else
F_67 ( V_1 , V_83 , V_100 , 0 ) ;
}
static void F_69 ( struct V_1 * V_1 ,
struct V_82 * V_83 ,
struct V_100 * V_100 )
{
struct V_64 * V_65 = F_40 ( V_1 , V_100 ) ;
unsigned char V_139 = F_63 ( V_100 -> V_83 ) ;
unsigned short * V_127 = F_65 ( V_65 , V_100 -> V_83 ) ;
if ( ! V_127 )
return;
F_58 ( V_1 , V_83 , * V_127 & ( 1 << V_139 ) ) ;
}
static void F_70 ( struct V_1 * V_1 ,
struct V_141 * V_85 )
{
T_1 V_14 = 0 ;
if ( V_85 -> V_2 == 0 )
return;
F_4 ( V_1 , V_126 , F_36 ( V_85 -> V_2 ) ) ;
F_3 ( V_1 , V_126 , F_36 ( V_85 -> V_2 ) ) ;
F_5 ( V_1 , V_85 -> V_2 , V_142 ) ;
if ( ! V_85 -> V_143 )
V_14 |= V_144 ;
if ( V_85 -> type == V_145 && V_85 -> V_143 )
V_14 |= V_146 | V_147 ;
V_14 |= V_85 -> type | V_85 -> V_148 ;
F_5 ( V_1 , V_14 , V_149 ) ;
F_5 ( V_1 , ( V_85 -> V_150 << 10 ) | ( V_85 -> V_151 ) ,
V_152 ) ;
F_5 ( V_1 , F_71 ( V_85 -> V_68 ) | V_85 -> V_153 ,
V_154 ) ;
F_5 ( V_1 , V_85 -> V_155 , V_156 ) ;
}
static void F_72 ( struct V_1 * V_1 , struct V_157 * V_158 )
{
struct V_141 * V_85 ;
struct V_100 * V_100 = V_158 -> V_100 ;
if ( V_158 -> V_2 > 0 ) {
V_85 = & V_158 -> V_83 -> V_85 ;
F_60 ( V_1 , 0 ) ;
F_70 ( V_1 , V_85 ) ;
if ( ! F_73 ( V_100 -> V_65 , F_63 ( V_100 -> V_83 ) ,
F_74 ( V_100 -> V_83 ) ) &&
! F_75 ( V_100 -> V_83 ) ) {
F_58 ( V_1 , V_158 -> V_83 , 0 ) ;
F_67 ( V_1 , V_158 -> V_83 , V_100 , 0 ) ;
F_57 ( V_1 , V_158 -> V_83 ) ;
F_76 ( V_100 -> V_65 , F_63 ( V_100 -> V_83 ) ,
F_74 ( V_100 -> V_83 ) , 1 ) ;
}
F_69 ( V_1 , V_158 -> V_83 , V_100 ) ;
}
}
static T_1 F_77 ( struct V_1 * V_1 ,
struct V_159 * V_160 )
{
T_1 V_161 [ V_162 ] , V_16 = 0 , V_163 ;
memset ( V_161 , 0 , sizeof( V_161 ) ) ;
switch ( F_78 ( V_160 ) ) {
case V_164 :
if ( F_79 ( V_160 ) )
V_161 [ V_16 ++ ] = 4 ;
else {
V_161 [ V_16 ++ ] = 3 ;
V_161 [ V_16 ++ ] = 5 ;
}
break;
case V_165 :
if ( F_79 ( V_160 ) ) {
V_161 [ V_16 ++ ] = 6 ;
V_161 [ V_16 ++ ] = 7 ;
V_161 [ V_16 ++ ] = 8 ;
} else
V_161 [ V_16 ++ ] = 9 ;
break;
case V_166 :
if ( F_79 ( V_160 ) )
V_161 [ V_16 ++ ] = 2 ;
else
V_161 [ V_16 ++ ] = 1 ;
break;
default:
F_11 ( V_22 L_10 ) ;
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
static T_1 F_80 ( T_3 type )
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
F_11 ( V_22 L_10 ) ;
V_168 = 0x0000 ;
break;
}
return V_168 ;
}
static T_1 F_81 ( T_1 V_2 )
{
T_1 V_151 = 0 ;
if ( V_2 == 0 )
V_151 = 0 ;
else if ( F_37 ( V_2 ) )
V_151 = 8 + ( V_2 - 1 ) * V_171 * 2 ;
else if ( F_82 ( V_2 ) )
V_151 = 4 + ( V_2 - 6 ) ;
else
F_11 ( V_22 L_11 , V_2 ) ;
return V_151 ;
}
static T_1 F_83 ( T_1 V_2 )
{
T_1 V_150 = 0 ;
if ( V_2 == 0 )
V_150 = 3 ;
else if ( F_37 ( V_2 ) )
V_150 = V_171 - 1 ;
else if ( F_82 ( V_2 ) )
V_150 = 0 ;
else
F_11 ( V_22 L_11 , V_2 ) ;
return V_150 ;
}
static void F_84 ( struct V_1 * V_1 ,
struct V_64 * V_65 ,
struct V_82 * V_83 ,
struct V_100 * V_100 )
{
int V_16 ;
struct V_141 * V_85 = & V_83 -> V_85 ;
unsigned short V_132 = F_59 ( V_1 ) ;
if ( V_1 -> V_17 -> V_18 )
return;
if ( ( V_83 -> V_85 . V_2 != 0 ) && ( V_85 -> type != V_169 ) ) {
for ( V_16 = 0 ; V_16 < V_172 ; V_16 ++ ) {
if ( ( V_1 -> V_173 & ( 1 << V_16 ) ) != 0 )
continue;
F_85 ( & V_65 -> V_63 -> V_65 ,
L_12
L_13 , F_41 ( V_100 -> V_83 ) ,
V_85 -> V_143 ?
V_174 + V_85 -> V_148
: V_85 -> V_148 ) ;
V_1 -> V_173 |= 1 << V_16 ;
V_65 -> V_173 |= 1 << V_16 ;
F_35 ( V_83 , V_16 ) ;
F_60 ( V_1 , 0 ) ;
F_12 ( V_1 , V_132 | V_83 -> V_85 . V_2 ,
V_132 | V_133 , V_83 -> V_90 ) ;
F_53 ( V_1 , V_83 -> V_90 , V_133 ,
V_83 -> V_85 . V_2 ) ;
F_4 ( V_1 , V_175 , V_83 -> V_91 ) ;
break;
}
}
}
static void F_86 ( struct V_1 * V_1 , struct V_100 * V_100 ,
struct V_134 * V_135 ,
struct V_141 * V_85 )
{
struct V_64 * V_65 = F_40 ( V_1 , V_100 ) ;
struct V_82 * V_83 = V_135 -> V_136 ;
F_49 ( & V_65 -> V_63 -> V_65 , L_14 ) ;
V_83 -> V_85 = * V_85 ;
F_35 ( V_83 , V_95 ) ;
V_1 -> V_167 [ V_83 -> V_85 . V_2 ] ++ ;
V_65 -> V_167 [ V_83 -> V_85 . V_2 ] ++ ;
F_84 ( V_1 , V_65 , V_83 , V_100 ) ;
}
static void F_87 ( struct V_1 * V_1 , struct V_100 * V_100 ,
int V_176 )
__releases( V_1 -> V_177 )
__acquires( V_1 -> V_177 )
{
if ( F_66 ( V_100 -> V_83 ) && F_88 ( V_100 -> V_83 ) != V_178 ) {
void * V_179 ;
for ( V_179 = V_100 -> V_180 ;
V_179 < V_100 -> V_180 + V_100 -> V_181 ;
V_179 += V_182 )
F_89 ( F_90 ( V_179 ) ) ;
}
F_91 ( F_92 ( V_1 ) , V_100 ) ;
F_93 ( & V_1 -> V_177 ) ;
F_94 ( F_92 ( V_1 ) , V_100 , V_176 ) ;
F_95 ( & V_1 -> V_177 ) ;
}
static void F_96 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_68 )
{
struct V_157 * V_158 , * V_183 ;
struct V_100 * V_100 ;
struct V_184 * V_185 = & V_1 -> V_186 [ V_2 ] ;
if ( F_97 ( V_185 ) )
return;
F_98 (td, next, list, queue) {
if ( V_158 -> V_68 != V_68 )
continue;
V_100 = V_158 -> V_100 ;
F_51 ( & V_158 -> V_187 ) ;
F_52 ( V_158 ) ;
if ( V_100 )
F_87 ( V_1 , V_100 , - V_188 ) ;
break;
}
}
static void F_99 ( struct V_1 * V_1 ,
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
F_96 ( V_1 , 0 , V_65 -> V_68 ) ;
}
V_1 -> V_167 [ V_2 ] -= V_65 -> V_167 [ V_2 ] ;
V_65 -> V_167 [ V_2 ] = 0 ;
F_96 ( V_1 , V_2 , V_65 -> V_68 ) ;
}
F_49 ( & V_65 -> V_63 -> V_65 , L_15 ) ;
V_1 -> V_173 &= ~ ( V_65 -> V_173 ) ;
V_65 -> V_173 = 0 ;
}
static T_1 F_100 ( struct V_100 * V_100 , T_3 V_155 )
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
static unsigned long F_101 ( struct V_100 * V_100 , T_3 V_155 )
{
T_3 V_16 ;
unsigned long time = 1 ;
if ( F_102 ( V_100 -> V_83 ) )
return 0 ;
if ( F_32 ( V_100 -> V_65 -> V_73 ) == V_79 ) {
for ( V_16 = 0 ; V_16 < ( V_155 - 1 ) ; V_16 ++ )
time *= 2 ;
time = time * 125 / 1000 ;
} else {
time = V_155 ;
}
return time ;
}
static void F_103 ( struct V_1 * V_1 , struct V_100 * V_100 ,
struct V_134 * V_135 ,
struct V_159 * V_160 )
{
struct V_141 V_85 ;
V_85 . V_2 = F_77 ( V_1 , V_160 ) ;
V_85 . V_68 = F_64 ( V_1 , V_100 ) ;
V_85 . V_148 = F_104 ( V_160 ) ;
V_85 . V_153 = F_105 ( V_160 ) ;
V_85 . type = F_80 ( F_78 ( V_160 ) ) ;
V_85 . V_151 = F_81 ( V_85 . V_2 ) ;
V_85 . V_150 = F_83 ( V_85 . V_2 ) ;
if ( V_85 . type == V_145 ) {
V_85 . V_155 = 0 ;
V_85 . V_191 = 0 ;
} else {
V_85 . V_155 = F_100 ( V_100 , V_160 -> V_192 ) ;
V_85 . V_191 = F_101 ( V_100 , V_160 -> V_192 ) ;
}
if ( F_79 ( V_160 ) )
V_85 . V_143 = 1 ;
else
V_85 . V_143 = 0 ;
F_86 ( V_1 , V_100 , V_135 , & V_85 ) ;
}
static void F_106 ( struct V_1 * V_1 , struct V_100 * V_100 )
{
struct V_64 * V_65 ;
V_65 = F_40 ( V_1 , V_100 ) ;
V_65 -> V_107 = V_193 ;
}
static void F_107 ( struct V_1 * V_1 , struct V_100 * V_100 ,
T_1 V_2 )
{
if ( V_2 == 0 && F_74 ( V_100 -> V_83 ) )
F_108 ( V_1 , V_2 ) ;
else
F_109 ( V_1 , V_2 ) ;
if ( ! F_102 ( V_100 -> V_83 ) )
F_110 ( V_1 , V_2 ) ;
}
static void F_111 ( struct V_1 * V_1 , T_1 V_2 )
{
F_112 ( V_1 , V_2 ) ;
F_113 ( V_1 , V_2 ) ;
}
static void F_114 ( struct V_1 * V_1 )
{
F_115 ( & V_1 -> V_194 ,
V_195 + F_116 ( V_196 ) ) ;
}
static void F_117 ( struct V_1 * V_1 , int V_13 ,
int V_197 )
{
struct V_198 * V_199 = & V_1 -> V_113 [ V_13 ] ;
V_199 -> V_200 = F_2 ( V_1 , F_118 ( V_13 ) ) & V_201 ;
V_199 -> V_202 = V_203 ;
if ( V_197 )
V_199 -> V_13 |= V_204 ;
else
V_199 -> V_13 &= ~ V_204 ;
V_199 -> V_13 |= V_205 << 16 ;
F_114 ( V_1 ) ;
}
static void F_119 ( struct V_1 * V_1 , int V_13 ,
T_1 V_206 )
__releases( V_1 -> V_177 )
__acquires( V_1 -> V_177 )
{
if ( V_206 == V_207 ) {
F_5 ( V_1 , ~ V_208 , F_23 ( V_13 ) ) ;
F_4 ( V_1 , V_34 , F_21 ( V_13 ) ) ;
} else {
if ( V_206 == V_209 )
F_4 ( V_1 , V_30 , F_19 ( V_13 ) ) ;
else if ( V_206 == V_210 )
F_3 ( V_1 , V_30 , F_19 ( V_13 ) ) ;
F_5 ( V_1 , ~ V_211 , F_23 ( V_13 ) ) ;
F_4 ( V_1 , V_33 , F_21 ( V_13 ) ) ;
if ( V_1 -> V_212 )
F_120 ( F_92 ( V_1 ) ) ;
}
F_93 ( & V_1 -> V_177 ) ;
F_121 ( F_92 ( V_1 ) ) ;
F_95 ( & V_1 -> V_177 ) ;
}
static void F_122 ( struct V_1 * V_1 , int V_13 )
{
T_1 V_73 = F_123 ( V_1 , V_13 ) ;
struct V_198 * V_199 = & V_1 -> V_113 [ V_13 ] ;
V_199 -> V_13 &= ~ ( V_213 | V_214 ) ;
if ( V_73 == V_79 )
V_199 -> V_13 |= V_213 ;
else if ( V_73 == V_75 )
V_199 -> V_13 |= V_214 ;
V_199 -> V_13 &= ~ V_215 ;
V_199 -> V_13 |= V_216 ;
}
static void F_124 ( struct V_1 * V_1 , int V_13 )
{
struct V_64 * V_65 = V_1 -> V_113 [ V_13 ] . V_65 ;
F_99 ( V_1 , V_65 ) ;
F_50 ( V_1 , V_65 , 0 ) ;
F_117 ( V_1 , V_13 , 0 ) ;
}
static void F_125 ( struct V_1 * V_1 ,
struct V_157 * V_158 )
{
int V_16 ;
T_4 * V_217 = ( T_4 * ) V_158 -> V_100 -> V_104 ;
unsigned long V_218 = V_219 ;
F_5 ( V_1 , F_71 ( V_158 -> V_68 ) | V_158 -> V_153 ,
V_220 ) ;
F_5 ( V_1 , ~ ( V_221 | V_222 ) , V_223 ) ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ ) {
F_5 ( V_1 , F_126 ( V_217 [ V_16 ] ) , V_218 ) ;
V_218 += 2 ;
}
F_5 ( V_1 , V_224 , V_97 ) ;
}
static void F_127 ( struct V_1 * V_1 ,
struct V_157 * V_158 )
{
struct V_100 * V_100 = V_158 -> V_100 ;
if ( F_75 ( V_100 -> V_83 ) ) {
F_3 ( V_1 , V_144 , V_225 ) ;
F_12 ( V_1 , 0 , V_226 | V_133 , V_50 ) ;
F_53 ( V_1 , V_50 , V_133 , 0 ) ;
if ( V_100 -> V_227 == 0 ) {
F_58 ( V_1 , V_158 -> V_83 , 1 ) ;
F_5 ( V_1 , V_175 , V_94 ) ;
}
F_111 ( V_1 , V_158 -> V_2 ) ;
F_55 ( V_1 , V_158 -> V_83 ) ;
F_107 ( V_1 , V_100 , V_158 -> V_2 ) ;
} else {
if ( V_100 -> V_227 == 0 ) {
F_111 ( V_1 , V_158 -> V_2 ) ;
F_72 ( V_1 , V_158 ) ;
F_56 ( V_1 , V_158 -> V_83 ) ;
F_5 ( V_1 , ~ ( 1 << V_158 -> V_2 ) , V_59 ) ;
if ( V_158 -> V_83 -> V_98 ) {
F_5 ( V_1 , V_228 ,
V_158 -> V_83 -> V_98 ) ;
F_5 ( V_1 ,
F_128
( V_100 -> V_181 ,
V_158 -> V_153 ) ,
V_158 -> V_83 -> V_99 ) ;
F_4 ( V_1 , V_229 ,
V_158 -> V_83 -> V_98 ) ;
}
F_55 ( V_1 , V_158 -> V_83 ) ;
F_107 ( V_1 , V_100 , V_158 -> V_2 ) ;
}
}
}
static void F_129 ( struct V_1 * V_1 ,
struct V_157 * V_158 )
{
T_1 V_4 ;
struct V_100 * V_100 = V_158 -> V_100 ;
if ( F_75 ( V_100 -> V_83 ) ) {
F_56 ( V_1 , V_158 -> V_83 ) ;
F_4 ( V_1 , V_144 , V_225 ) ;
F_12 ( V_1 , V_226 , V_226 | V_133 , V_50 ) ;
F_53 ( V_1 , V_50 , V_133 , 0 ) ;
if ( V_100 -> V_227 == 0 ) {
F_58 ( V_1 , V_158 -> V_83 , 1 ) ;
F_5 ( V_1 , V_175 , V_94 ) ;
}
} else {
if ( V_100 -> V_227 == 0 )
F_72 ( V_1 , V_158 ) ;
if ( V_158 -> V_83 -> V_98 )
F_3 ( V_1 , V_229 , V_158 -> V_83 -> V_98 ) ;
}
F_5 ( V_1 , ~ ( 1 << V_158 -> V_2 ) , V_59 ) ;
F_61 ( V_1 , V_158 -> V_83 ) ;
V_4 = F_2 ( V_1 , V_158 -> V_83 -> V_91 ) ;
if ( F_130 ( ( V_4 & V_230 ) == 0 ) )
F_107 ( V_1 , V_100 , V_158 -> V_2 ) ;
else
F_131 ( V_1 , V_158 -> V_2 ) ;
F_55 ( V_1 , V_158 -> V_83 ) ;
}
static void F_132 ( struct V_1 * V_1 ,
struct V_157 * V_158 )
{
struct V_100 * V_100 = V_158 -> V_100 ;
F_58 ( V_1 , V_158 -> V_83 , 1 ) ;
F_56 ( V_1 , V_158 -> V_83 ) ;
if ( V_100 -> V_104 [ 0 ] & V_174 ) {
F_4 ( V_1 , V_144 , V_225 ) ;
F_12 ( V_1 , V_226 , V_226 | V_133 , V_50 ) ;
F_53 ( V_1 , V_50 , V_133 , 0 ) ;
F_5 ( V_1 , ~ V_48 , V_61 ) ;
F_5 ( V_1 , V_175 | V_231 , V_94 ) ;
F_108 ( V_1 , 0 ) ;
} else {
F_3 ( V_1 , V_144 , V_225 ) ;
F_12 ( V_1 , 0 , V_226 | V_133 , V_50 ) ;
F_53 ( V_1 , V_50 , V_133 , 0 ) ;
F_5 ( V_1 , V_175 , V_94 ) ;
F_109 ( V_1 , 0 ) ;
}
F_110 ( V_1 , 0 ) ;
F_55 ( V_1 , V_158 -> V_83 ) ;
}
static int F_133 ( unsigned char * V_104 )
{
if ( ( ( V_104 [ 0 ] & V_232 ) == V_233 ) &&
V_104 [ 1 ] == V_234 )
return 1 ;
else
return 0 ;
}
static int F_134 ( struct V_1 * V_1 , struct V_157 * V_158 )
{
F_135 ( ! V_158 ) ;
switch ( V_158 -> type ) {
case V_235 :
if ( F_133 ( V_158 -> V_100 -> V_104 ) ) {
V_158 -> V_236 = 1 ;
V_158 -> V_100 -> V_104 [ 2 ] = F_47 ( V_1 ,
V_158 -> V_100 ) ;
if ( V_158 -> V_100 -> V_104 [ 2 ] == 0 )
return - V_237 ;
}
F_125 ( V_1 , V_158 ) ;
break;
case V_238 :
F_127 ( V_1 , V_158 ) ;
break;
case V_239 :
F_129 ( V_1 , V_158 ) ;
break;
case V_240 :
F_132 ( V_1 , V_158 ) ;
break;
default:
F_11 ( V_22 L_16 ) ;
break;
}
return 0 ;
}
static int F_136 ( struct V_157 * V_158 , struct V_100 * V_100 )
{
if ( F_102 ( V_100 -> V_83 ) ) {
if ( V_100 -> V_241 == V_158 -> V_242 )
return 1 ;
}
if ( ( V_100 -> V_181 <= V_100 -> V_227 ) ||
( V_158 -> V_243 ) || ( V_158 -> V_244 ) )
return 1 ;
return 0 ;
}
static void F_137 ( struct V_1 * V_1 , struct V_157 * V_158 )
{
unsigned long time ;
F_135 ( ! V_158 ) ;
if ( ! F_97 ( & V_1 -> V_186 [ V_158 -> V_2 ] ) &&
! F_75 ( V_158 -> V_100 -> V_83 ) && F_66 ( V_158 -> V_100 -> V_83 ) ) {
V_1 -> V_245 |= 1 << V_158 -> V_2 ;
switch ( F_88 ( V_158 -> V_100 -> V_83 ) ) {
case V_246 :
case V_247 :
time = 30 ;
break;
default:
time = 300 ;
break;
}
F_115 ( & V_1 -> V_248 [ V_158 -> V_2 ] ,
V_195 + F_116 ( time ) ) ;
}
}
static void F_138 ( struct V_1 * V_1 , struct V_157 * V_158 ,
T_1 V_2 , struct V_100 * V_100 , int V_176 )
__releases( V_1 -> V_177 ) __acquires( V_1 -> V_177 )
{
int V_249 = 0 ;
struct V_250 * V_251 = F_92 ( V_1 ) ;
V_1 -> V_245 &= ~ ( 1 << V_2 ) ;
if ( F_139 ( V_158 ) ) {
if ( V_158 -> V_236 && ( V_176 != 0 || V_100 -> V_252 ) )
V_1 -> V_115 &= ~ ( 1 << V_100 -> V_104 [ 2 ] ) ;
F_68 ( V_1 , V_158 -> V_83 , V_100 ) ;
F_51 ( & V_158 -> V_187 ) ;
F_52 ( V_158 ) ;
}
if ( ! F_97 ( & V_1 -> V_186 [ V_2 ] ) )
V_249 = 1 ;
if ( F_139 ( V_100 ) ) {
if ( F_102 ( V_100 -> V_83 ) )
V_100 -> V_253 = F_140 ( V_251 ) ;
F_87 ( V_1 , V_100 , V_176 ) ;
}
if ( V_249 ) {
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
int V_254 , V_255 , V_256 , V_257 ;
T_1 * V_258 ;
struct V_157 * V_158 = F_141 ( V_1 , V_2 ) ;
struct V_100 * V_100 ;
int V_259 = 0 ;
int V_176 = 0 ;
if ( F_130 ( ! V_158 ) )
return;
V_100 = V_158 -> V_100 ;
F_61 ( V_1 , V_158 -> V_83 ) ;
V_4 = F_2 ( V_1 , V_158 -> V_83 -> V_91 ) ;
if ( F_130 ( ( V_4 & V_230 ) == 0 ) ) {
F_56 ( V_1 , V_158 -> V_83 ) ;
F_111 ( V_1 , V_2 ) ;
F_11 ( V_22 L_17 , V_2 ) ;
F_138 ( V_1 , V_158 , V_2 , V_158 -> V_100 , - V_237 ) ;
return;
}
V_254 = V_4 & V_260 ;
if ( F_102 ( V_100 -> V_83 ) ) {
V_258 = ( T_1 * ) ( V_100 -> V_180 +
V_100 -> V_261 [ V_158 -> V_242 ] . V_262 ) ;
V_256 = V_100 -> V_261 [ V_158 -> V_242 ] . V_263 ;
} else {
V_258 = ( void * ) V_100 -> V_180 + V_100 -> V_227 ;
V_256 = V_100 -> V_181 - V_100 -> V_227 ;
}
V_255 = V_163 ( V_256 , ( int ) V_158 -> V_153 ) ;
if ( V_254 <= V_255 ) {
V_257 = V_254 ;
} else {
V_257 = V_255 ;
V_176 = - V_264 ;
V_259 = 1 ;
}
V_100 -> V_227 += V_257 ;
if ( V_254 == 0 )
V_158 -> V_244 = 1 ;
if ( V_254 < V_255 ) {
V_158 -> V_243 = 1 ;
}
if ( F_102 ( V_100 -> V_83 ) ) {
V_100 -> V_261 [ V_158 -> V_242 ] . V_227 = V_257 ;
V_100 -> V_261 [ V_158 -> V_242 ] . V_176 = V_176 ;
V_158 -> V_242 ++ ;
V_259 = 0 ;
}
if ( V_259 || F_136 ( V_158 , V_100 ) ) {
F_56 ( V_1 , V_158 -> V_83 ) ;
F_111 ( V_1 , V_2 ) ;
V_259 = 1 ;
}
if ( V_100 -> V_180 ) {
if ( V_257 == 0 )
F_5 ( V_1 , V_175 , V_158 -> V_83 -> V_91 ) ;
else
F_143 ( V_1 , V_158 -> V_83 -> V_86 ,
V_258 , V_257 ) ;
}
if ( V_259 && V_2 != 0 )
F_138 ( V_1 , V_158 , V_2 , V_100 , V_176 ) ;
}
static void F_131 ( struct V_1 * V_1 , T_1 V_2 )
{
T_1 V_4 ;
int V_255 , V_257 ;
T_1 * V_258 ;
struct V_157 * V_158 = F_141 ( V_1 , V_2 ) ;
struct V_100 * V_100 ;
if ( F_130 ( ! V_158 ) )
return;
V_100 = V_158 -> V_100 ;
F_61 ( V_1 , V_158 -> V_83 ) ;
V_4 = F_2 ( V_1 , V_158 -> V_83 -> V_91 ) ;
if ( F_130 ( ( V_4 & V_230 ) == 0 ) ) {
F_56 ( V_1 , V_158 -> V_83 ) ;
F_111 ( V_1 , V_2 ) ;
F_11 ( V_22 L_18 , V_2 ) ;
F_138 ( V_1 , V_158 , V_2 , V_100 , - V_237 ) ;
return;
}
V_255 = V_158 -> V_153 ;
if ( F_102 ( V_100 -> V_83 ) ) {
V_258 = ( T_1 * ) ( V_100 -> V_180 +
V_100 -> V_261 [ V_158 -> V_242 ] . V_262 ) ;
V_257 = V_163 ( V_255 ,
( int ) V_100 -> V_261 [ V_158 -> V_242 ] . V_263 ) ;
} else {
V_258 = ( T_1 * ) ( V_100 -> V_180 + V_100 -> V_227 ) ;
V_257 = F_144 ( V_265 , V_255 ,
V_100 -> V_181 - V_100 -> V_227 ) ;
}
if ( V_2 > 0 )
F_5 ( V_1 , ~ ( 1 << V_2 ) , V_61 ) ;
if ( V_100 -> V_180 ) {
F_145 ( V_1 , V_158 -> V_83 , V_258 , V_257 ) ;
if ( ! F_146 ( V_100 -> V_83 ) || V_158 -> V_153 != V_257 )
F_5 ( V_1 , V_231 , V_158 -> V_83 -> V_91 ) ;
}
V_100 -> V_227 += V_257 ;
if ( F_102 ( V_100 -> V_83 ) ) {
V_100 -> V_261 [ V_158 -> V_242 ] . V_227 = V_257 ;
V_100 -> V_261 [ V_158 -> V_242 ] . V_176 = 0 ;
V_158 -> V_242 ++ ;
}
if ( F_136 ( V_158 , V_100 ) ) {
F_112 ( V_1 , V_2 ) ;
F_108 ( V_1 , V_2 ) ;
if ( ! F_102 ( V_100 -> V_83 ) )
F_110 ( V_1 , V_2 ) ;
} else
F_107 ( V_1 , V_100 , V_2 ) ;
}
static void F_147 ( struct V_1 * V_1 , int V_176 )
{
struct V_157 * V_158 = F_141 ( V_1 , 0 ) ;
struct V_100 * V_100 ;
T_2 V_259 = 0 ;
if ( F_130 ( ! V_158 ) )
return;
V_100 = V_158 -> V_100 ;
switch ( V_158 -> type ) {
case V_238 :
case V_239 :
if ( F_136 ( V_158 , V_100 ) )
V_158 -> type = V_240 ;
break;
case V_235 :
if ( V_100 -> V_181 == V_100 -> V_227 )
V_158 -> type = V_240 ;
else if ( F_74 ( V_100 -> V_83 ) )
V_158 -> type = V_239 ;
else
V_158 -> type = V_238 ;
break;
case V_240 :
V_259 = 1 ;
break;
}
if ( V_259 || V_176 != 0 || V_100 -> V_252 )
F_138 ( V_1 , V_158 , 0 , V_100 , V_176 ) ;
else
F_134 ( V_1 , V_158 ) ;
}
static int F_148 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_157 * V_158 = F_141 ( V_1 , V_2 ) ;
if ( V_158 ) {
T_1 V_266 = F_2 ( V_1 , V_158 -> V_83 -> V_96 ) & V_120 ;
if ( V_266 == V_122 )
return - V_267 ;
else
return - V_237 ;
}
return 0 ;
}
static void F_149 ( struct V_1 * V_1 )
{
T_1 V_268 ;
T_1 V_2 ;
T_1 V_118 ;
struct V_157 * V_158 ;
V_118 = F_2 ( V_1 , V_59 )
& F_2 ( V_1 , V_47 ) ;
F_5 ( V_1 , ~ V_118 , V_59 ) ;
if ( V_118 & V_46 ) {
V_158 = F_141 ( V_1 , 0 ) ;
if ( V_158 && V_158 -> type == V_238 )
F_142 ( V_1 , 0 ) ;
else
F_111 ( V_1 , 0 ) ;
F_147 ( V_1 , 0 ) ;
}
for ( V_2 = 1 ; V_2 < V_162 ; V_2 ++ ) {
V_268 = 1 << V_2 ;
if ( V_118 & V_268 ) {
V_158 = F_141 ( V_1 , V_2 ) ;
if ( F_130 ( ! V_158 ) )
continue;
if ( V_158 -> type == V_238 )
F_142 ( V_1 , V_2 ) ;
else if ( V_158 -> type == V_239 )
F_131 ( V_1 , V_2 ) ;
}
}
}
static void F_150 ( struct V_1 * V_1 )
{
T_1 V_4 ;
T_1 V_268 ;
T_1 V_2 ;
T_1 V_118 ;
struct V_157 * V_158 ;
V_118 = F_2 ( V_1 , V_61 )
& F_2 ( V_1 , V_49 ) ;
F_5 ( V_1 , ~ V_118 , V_61 ) ;
if ( V_118 & V_48 ) {
F_60 ( V_1 , 0 ) ;
V_158 = F_141 ( V_1 , 0 ) ;
if ( V_158 && V_158 -> type != V_239 )
F_151 ( V_1 , 0 ) ;
F_147 ( V_1 , 0 ) ;
}
for ( V_2 = 1 ; V_2 < V_162 ; V_2 ++ ) {
V_268 = 1 << V_2 ;
if ( V_118 & V_268 ) {
struct V_157 * V_158 ;
V_158 = F_141 ( V_1 , V_2 ) ;
if ( F_130 ( ! V_158 ) )
continue;
V_4 = F_2 ( V_1 , V_158 -> V_83 -> V_96 ) ;
if ( ( V_4 & V_269 ) == 0 ) {
F_151 ( V_1 , V_2 ) ;
F_111 ( V_1 , V_2 ) ;
F_138 ( V_1 , V_158 , V_2 , V_158 -> V_100 ,
0 ) ;
}
}
}
}
static void F_152 ( struct V_1 * V_1 )
{
T_1 V_268 ;
T_1 V_2 ;
T_1 V_118 ;
int V_176 ;
V_118 = F_2 ( V_1 , V_60 )
& F_2 ( V_1 , V_58 ) ;
F_5 ( V_1 , ~ V_118 , V_60 ) ;
if ( V_118 & V_270 ) {
F_60 ( V_1 , 0 ) ;
V_176 = F_148 ( V_1 , 0 ) ;
F_111 ( V_1 , 0 ) ;
F_147 ( V_1 , V_176 ) ;
}
for ( V_2 = 1 ; V_2 < V_162 ; V_2 ++ ) {
V_268 = 1 << V_2 ;
if ( V_118 & V_268 ) {
struct V_157 * V_158 ;
V_158 = F_141 ( V_1 , V_2 ) ;
if ( F_130 ( ! V_158 ) )
continue;
V_176 = F_148 ( V_1 , V_2 ) ;
F_111 ( V_1 , V_2 ) ;
F_56 ( V_1 , V_158 -> V_83 ) ;
F_138 ( V_1 , V_158 , V_2 , V_158 -> V_100 , V_176 ) ;
}
}
}
static T_5 F_153 ( struct V_250 * V_251 )
{
struct V_1 * V_1 = F_154 ( V_251 ) ;
T_1 V_271 , V_272 , V_273 ;
T_1 V_274 , V_275 , V_276 ;
T_1 V_277 , V_278 , V_279 ;
int V_176 ;
F_95 ( & V_1 -> V_177 ) ;
V_271 = F_2 ( V_1 , V_280 ) ;
V_272 = F_2 ( V_1 , V_223 ) ;
V_273 = F_2 ( V_1 , V_281 ) ;
V_274 = F_2 ( V_1 , V_5 ) ;
V_275 = F_2 ( V_1 , V_56 ) ;
V_276 = F_2 ( V_1 , V_282 ) ;
V_279 = V_273 & V_276 ;
V_278 = V_272 & V_275 ;
V_277 = V_271 & V_274 & ( V_283 | V_284 | V_285 ) ;
if ( V_279 ) {
if ( V_279 & V_208 ) {
F_5 ( V_1 , ~ V_208 , V_281 ) ;
F_3 ( V_1 , V_34 , V_282 ) ;
F_117 ( V_1 , 1 , 1 ) ;
}
if ( V_279 & V_211 ) {
F_5 ( V_1 , ~ V_211 , V_281 ) ;
F_3 ( V_1 , V_33 , V_282 ) ;
F_124 ( V_1 , 1 ) ;
}
if ( V_279 & V_286 ) {
F_5 ( V_1 , ~ V_286 , V_281 ) ;
F_3 ( V_1 , V_287 , V_282 ) ;
F_120 ( F_92 ( V_1 ) ) ;
}
}
if ( V_278 ) {
if ( V_278 & V_208 ) {
F_5 ( V_1 , ~ V_208 , V_223 ) ;
F_3 ( V_1 , V_34 , V_56 ) ;
F_117 ( V_1 , 0 , 1 ) ;
}
if ( V_278 & V_211 ) {
F_5 ( V_1 , ~ V_211 , V_223 ) ;
F_3 ( V_1 , V_33 , V_56 ) ;
F_124 ( V_1 , 0 ) ;
}
if ( V_278 & V_286 ) {
F_5 ( V_1 , ~ V_286 , V_223 ) ;
F_3 ( V_1 , V_287 , V_56 ) ;
F_120 ( F_92 ( V_1 ) ) ;
}
if ( V_278 & V_221 ) {
F_5 ( V_1 , ~ V_221 , V_223 ) ;
V_176 = F_148 ( V_1 , 0 ) ;
F_147 ( V_1 , V_176 ) ;
}
if ( V_278 & V_222 ) {
F_5 ( V_1 , ~ V_222 , V_223 ) ;
F_147 ( V_1 , 0 ) ;
}
}
if ( V_277 ) {
if ( V_277 & V_285 )
F_149 ( V_1 ) ;
if ( V_277 & V_283 )
F_150 ( V_1 ) ;
if ( V_277 & V_284 )
F_152 ( V_1 ) ;
}
F_93 ( & V_1 -> V_177 ) ;
return V_288 ;
}
static void F_155 ( struct V_1 * V_1 , int V_13 )
{
T_1 V_4 ;
struct V_198 * V_199 = & V_1 -> V_113 [ V_13 ] ;
if ( V_199 -> V_13 & V_215 ) {
unsigned long V_289 = F_156 ( V_13 ) ;
V_4 = F_2 ( V_1 , V_289 ) ;
if ( ( V_4 & V_290 ) == V_290 ) {
F_12 ( V_1 , V_291 , V_290 | V_291 ,
V_289 ) ;
F_114 ( V_1 ) ;
} else
F_122 ( V_1 , V_13 ) ;
}
if ( ! ( V_199 -> V_13 & V_204 ) ) {
F_5 ( V_1 , ~ V_208 , F_23 ( V_13 ) ) ;
F_4 ( V_1 , V_34 , F_21 ( V_13 ) ) ;
}
if ( V_199 -> V_202 > 0 ) {
V_4 = F_2 ( V_1 , F_118 ( V_13 ) ) & V_201 ;
if ( V_4 == V_199 -> V_200 ) {
V_199 -> V_202 -- ;
if ( V_199 -> V_202 == 0 )
F_119 ( V_1 , V_13 , V_4 ) ;
else
F_114 ( V_1 ) ;
} else {
V_199 -> V_202 = V_203 ;
V_199 -> V_200 = V_4 ;
F_114 ( V_1 ) ;
}
}
}
static void F_157 ( unsigned long V_292 )
{
struct V_1 * V_1 = (struct V_1 * ) V_292 ;
unsigned long V_293 ;
T_1 V_2 ;
struct V_157 * V_158 ;
F_158 ( & V_1 -> V_177 , V_293 ) ;
for ( V_2 = 0 ; V_2 < V_162 ; V_2 ++ ) {
if ( ! ( V_1 -> V_294 & ( 1 << V_2 ) ) )
continue;
if ( F_159 ( & V_1 -> V_295 [ V_2 ] ) )
continue;
V_158 = F_141 ( V_1 , V_2 ) ;
if ( V_158 )
F_134 ( V_1 , V_158 ) ;
}
F_160 ( & V_1 -> V_177 , V_293 ) ;
}
static void F_161 ( unsigned long V_292 )
{
struct V_1 * V_1 = (struct V_1 * ) V_292 ;
unsigned long V_293 ;
T_1 V_2 ;
struct V_157 * V_158 , * V_296 = NULL ;
struct V_82 * V_83 ;
F_158 ( & V_1 -> V_177 , V_293 ) ;
for ( V_2 = 0 ; V_2 < V_162 ; V_2 ++ ) {
if ( ! ( V_1 -> V_245 & ( 1 << V_2 ) ) )
continue;
if ( F_159 ( & V_1 -> V_248 [ V_2 ] ) )
continue;
V_158 = F_141 ( V_1 , V_2 ) ;
if ( ! V_158 ) {
V_1 -> V_245 &= ~ ( 1 << V_2 ) ;
continue;
}
if ( V_158 -> V_100 -> V_227 ) {
F_137 ( V_1 , V_158 ) ;
break;
}
V_83 = V_158 -> V_83 ;
F_56 ( V_1 , V_83 ) ;
V_296 = V_158 ;
do {
F_162 ( & V_296 -> V_187 ,
& V_1 -> V_186 [ V_2 ] ) ;
V_296 = F_141 ( V_1 , V_2 ) ;
if ( ! V_296 ) {
V_296 = V_158 ;
break;
}
} while ( V_158 != V_296 && V_158 -> V_68 == V_296 -> V_68 );
F_134 ( V_1 , V_296 ) ;
if ( V_158 == V_296 )
V_1 -> V_245 &= ~ ( 1 << V_2 ) ;
else
F_137 ( V_1 , V_296 ) ;
break;
}
F_160 ( & V_1 -> V_177 , V_293 ) ;
}
static void F_163 ( unsigned long V_292 )
{
struct V_1 * V_1 = (struct V_1 * ) V_292 ;
unsigned long V_293 ;
int V_13 ;
F_158 ( & V_1 -> V_177 , V_293 ) ;
for ( V_13 = 0 ; V_13 < V_1 -> V_57 ; V_13 ++ )
F_155 ( V_1 , V_13 ) ;
F_160 ( & V_1 -> V_177 , V_293 ) ;
}
static int F_164 ( struct V_1 * V_1 , struct V_100 * V_100 )
{
struct V_64 * V_65 = F_40 ( V_1 , V_100 ) ;
if ( V_65 && V_65 -> V_68 && V_65 -> V_107 != V_193 &&
( V_100 -> V_65 -> V_107 == V_193 ) )
return 1 ;
else
return 0 ;
}
static int F_165 ( struct V_250 * V_251 )
{
struct V_1 * V_1 = F_154 ( V_251 ) ;
V_251 -> V_107 = V_297 ;
return F_25 ( V_1 ) ;
}
static void F_166 ( struct V_250 * V_251 )
{
struct V_1 * V_1 = F_154 ( V_251 ) ;
F_26 ( V_1 ) ;
}
static void F_167 ( struct V_1 * V_1 , struct V_100 * V_100 )
{
unsigned int V_103 = F_41 ( V_100 -> V_83 ) ;
T_1 V_70 , V_71 ;
if ( V_103 == 0 ) {
F_31 ( V_1 , V_100 -> V_65 -> V_69 ,
& V_70 , & V_71 ) ;
F_7 ( V_1 , 0 ,
F_32 ( V_100 -> V_65 -> V_73 ) ,
F_27 ( V_1 , V_100 -> V_65 ) ,
V_71 , V_70 ) ;
}
}
static struct V_157 * F_168 ( struct V_1 * V_1 ,
struct V_100 * V_100 ,
struct V_134 * V_135 )
{
struct V_157 * V_158 ;
T_1 V_2 ;
V_158 = F_43 ( sizeof( struct V_157 ) , V_105 ) ;
if ( V_158 == NULL )
return NULL ;
V_2 = F_62 ( V_100 , V_135 ) ;
V_158 -> V_2 = V_2 ;
V_158 -> V_83 = V_135 -> V_136 ;
V_158 -> V_100 = V_100 ;
V_158 -> V_68 = F_64 ( V_1 , V_100 ) ;
V_158 -> V_153 = F_169 ( V_100 -> V_65 , V_100 -> V_83 ,
! F_66 ( V_100 -> V_83 ) ) ;
if ( F_75 ( V_100 -> V_83 ) )
V_158 -> type = V_235 ;
else if ( F_66 ( V_100 -> V_83 ) )
V_158 -> type = V_238 ;
else
V_158 -> type = V_239 ;
F_45 ( & V_158 -> V_187 ) ;
return V_158 ;
}
static int F_170 ( struct V_250 * V_251 ,
struct V_100 * V_100 ,
T_6 V_298 )
{
struct V_134 * V_135 = V_100 -> V_160 ;
struct V_1 * V_1 = F_154 ( V_251 ) ;
struct V_157 * V_158 = NULL ;
int V_37 , V_299 = 0 ;
unsigned long V_293 ;
F_158 ( & V_1 -> V_177 , V_293 ) ;
if ( ! F_40 ( V_1 , V_100 ) ) {
V_37 = - V_188 ;
goto V_300;
}
V_37 = F_171 ( V_251 , V_100 ) ;
if ( V_37 )
goto V_300;
if ( ! V_135 -> V_136 ) {
V_135 -> V_136 = F_43 ( sizeof( struct V_82 ) ,
V_105 ) ;
if ( ! V_135 -> V_136 ) {
V_37 = - V_106 ;
goto error;
}
F_35 ( V_135 -> V_136 , V_95 ) ;
if ( F_63 ( V_100 -> V_83 ) )
F_103 ( V_1 , V_100 , V_135 , & V_135 -> V_301 ) ;
}
if ( F_130 ( F_164 ( V_1 , V_100 ) ) )
F_106 ( V_1 , V_100 ) ;
F_167 ( V_1 , V_100 ) ;
V_158 = F_168 ( V_1 , V_100 , V_135 ) ;
if ( V_158 == NULL ) {
V_37 = - V_106 ;
goto error;
}
if ( F_97 ( & V_1 -> V_186 [ V_158 -> V_2 ] ) )
V_299 = 1 ;
F_46 ( & V_158 -> V_187 , & V_1 -> V_186 [ V_158 -> V_2 ] ) ;
V_100 -> V_136 = V_158 ;
if ( V_299 ) {
if ( V_158 -> V_83 -> V_85 . V_191 ) {
V_1 -> V_294 |= 1 << V_158 -> V_2 ;
F_115 ( & V_1 -> V_295 [ V_158 -> V_2 ] ,
V_195 + F_116 (
V_158 -> V_83 -> V_85 . V_191 ) ) ;
} else {
V_37 = F_134 ( V_1 , V_158 ) ;
if ( V_37 < 0 ) {
F_51 ( & V_158 -> V_187 ) ;
F_52 ( V_158 ) ;
}
}
} else
F_137 ( V_1 , V_158 ) ;
error:
if ( V_37 )
F_91 ( V_251 , V_100 ) ;
V_300:
F_160 ( & V_1 -> V_177 , V_293 ) ;
return V_37 ;
}
static int F_172 ( struct V_250 * V_251 , struct V_100 * V_100 ,
int V_176 )
{
struct V_1 * V_1 = F_154 ( V_251 ) ;
struct V_157 * V_158 ;
unsigned long V_293 ;
int V_302 ;
F_158 ( & V_1 -> V_177 , V_293 ) ;
V_302 = F_173 ( V_251 , V_100 , V_176 ) ;
if ( V_302 )
goto V_303;
if ( V_100 -> V_136 ) {
V_158 = V_100 -> V_136 ;
F_56 ( V_1 , V_158 -> V_83 ) ;
F_111 ( V_1 , V_158 -> V_2 ) ;
F_151 ( V_1 , V_158 -> V_2 ) ;
F_138 ( V_1 , V_158 , V_158 -> V_2 , V_100 , V_176 ) ;
}
V_303:
F_160 ( & V_1 -> V_177 , V_293 ) ;
return V_302 ;
}
static void F_174 ( struct V_250 * V_251 ,
struct V_134 * V_135 )
{
struct V_1 * V_1 = F_154 ( V_251 ) ;
struct V_82 * V_83 = (struct V_82 * ) V_135 -> V_136 ;
struct V_157 * V_158 ;
struct V_100 * V_100 = NULL ;
T_1 V_2 ;
unsigned long V_293 ;
if ( V_83 == NULL )
return;
V_2 = V_83 -> V_85 . V_2 ;
if ( V_2 == 0 ) {
F_52 ( V_135 -> V_136 ) ;
V_135 -> V_136 = NULL ;
return;
}
F_158 ( & V_1 -> V_177 , V_293 ) ;
F_56 ( V_1 , V_83 ) ;
F_111 ( V_1 , V_2 ) ;
F_151 ( V_1 , V_2 ) ;
V_158 = F_141 ( V_1 , V_2 ) ;
if ( V_158 )
V_100 = V_158 -> V_100 ;
F_138 ( V_1 , V_158 , V_2 , V_100 , - V_304 ) ;
F_52 ( V_135 -> V_136 ) ;
V_135 -> V_136 = NULL ;
F_160 ( & V_1 -> V_177 , V_293 ) ;
}
static int F_140 ( struct V_250 * V_251 )
{
struct V_1 * V_1 = F_154 ( V_251 ) ;
return F_2 ( V_1 , V_305 ) & 0x03FF ;
}
static void F_175 ( struct V_62 * V_63 , unsigned long * V_306 )
{
int V_307 ;
struct V_62 * V_308 ;
if ( V_63 -> V_107 == V_193 &&
V_63 -> V_66 && V_63 -> V_66 -> V_67 > 1 &&
V_63 -> V_66 -> V_309 . V_310 == V_311 )
V_306 [ V_63 -> V_67 / 32 ] |= ( 1 << ( V_63 -> V_67 % 32 ) ) ;
F_176 (udev, chix, childdev)
F_175 ( V_308 , V_306 ) ;
}
static struct V_64 * F_177 ( struct V_1 * V_1 ,
int V_102 )
{
struct V_64 * V_65 ;
struct V_184 * V_185 = & V_1 -> V_112 ;
F_178 (dev, list, device_list) {
if ( V_65 -> V_103 != V_102 )
continue;
return V_65 ;
}
F_11 ( V_22 L_19 , V_102 ) ;
return NULL ;
}
static void F_179 ( struct V_1 * V_1 ,
struct V_62 * V_113 ,
unsigned long * V_306 )
{
int V_16 , V_312 , V_102 ;
unsigned long V_313 ;
unsigned long V_293 ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ ) {
V_313 = V_1 -> V_81 [ V_16 ] ^ V_306 [ V_16 ] ;
if ( ! V_313 )
continue;
for ( V_312 = 0 ; V_312 < 32 ; V_312 ++ ) {
if ( ! ( V_313 & ( 1 << V_312 ) ) )
continue;
V_102 = V_16 * 32 + V_312 ;
if ( V_306 [ V_16 ] & ( 1 << V_312 ) )
F_33 ( V_1 , V_102 ) ;
else {
struct V_64 * V_65 ;
F_158 ( & V_1 -> V_177 , V_293 ) ;
V_65 = F_177 ( V_1 , V_102 ) ;
F_99 ( V_1 , V_65 ) ;
F_50 ( V_1 , V_65 , 0 ) ;
F_34 ( V_1 , V_102 ) ;
F_160 ( & V_1 -> V_177 , V_293 ) ;
}
}
}
}
static void F_180 ( struct V_1 * V_1 ,
struct V_250 * V_251 )
{
struct V_314 * V_315 ;
unsigned long V_316 [ 4 ] ;
memset ( V_316 , 0 , sizeof( V_316 ) ) ;
F_178 (bus, &usb_bus_list, bus_list) {
if ( ! V_315 -> V_113 )
continue;
if ( V_315 -> V_317 != V_251 -> V_318 . V_317 )
continue;
F_175 ( V_315 -> V_113 , V_316 ) ;
F_179 ( V_1 , V_315 -> V_113 , V_316 ) ;
}
}
static int F_181 ( struct V_250 * V_251 , char * V_258 )
{
struct V_1 * V_1 = F_154 ( V_251 ) ;
unsigned long V_293 ;
int V_16 ;
F_180 ( V_1 , V_251 ) ;
F_158 ( & V_1 -> V_177 , V_293 ) ;
* V_258 = 0 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_57 ; V_16 ++ ) {
if ( V_1 -> V_113 [ V_16 ] . V_13 & 0xffff0000 )
* V_258 |= 1 << ( V_16 + 1 ) ;
}
F_160 ( & V_1 -> V_177 , V_293 ) ;
return ( * V_258 != 0 ) ;
}
static void F_182 ( struct V_1 * V_1 ,
struct V_319 * V_301 )
{
V_301 -> V_320 = 0x29 ;
V_301 -> V_321 = 0 ;
V_301 -> V_322 = V_1 -> V_57 ;
V_301 -> V_323 = 9 ;
V_301 -> V_324 = 0 ;
V_301 -> V_325 =
F_183 ( V_326 | V_327 ) ;
V_301 -> V_328 . V_329 . V_330 [ 0 ] =
( ( 1 << V_1 -> V_57 ) - 1 ) << 1 ;
V_301 -> V_328 . V_329 . V_330 [ 1 ] = ~ 0 ;
}
static int F_184 ( struct V_250 * V_251 , T_1 V_331 , T_1 V_332 ,
T_1 V_333 , char * V_258 , T_1 V_334 )
{
struct V_1 * V_1 = F_154 ( V_251 ) ;
int V_37 ;
int V_13 = ( V_333 & 0x00FF ) - 1 ;
struct V_198 * V_199 = & V_1 -> V_113 [ V_13 ] ;
unsigned long V_293 ;
V_37 = 0 ;
F_158 ( & V_1 -> V_177 , V_293 ) ;
switch ( V_331 ) {
case V_335 :
case V_336 :
switch ( V_332 ) {
case V_337 :
case V_338 :
break;
default:
goto error;
}
break;
case V_339 :
if ( V_333 > V_1 -> V_57 )
goto error;
if ( V_334 != 0 )
goto error;
switch ( V_332 ) {
case V_340 :
V_199 -> V_13 &= ~ V_341 ;
break;
case V_342 :
break;
case V_343 :
F_24 ( V_1 , V_13 , 0 ) ;
break;
case V_344 :
case V_345 :
case V_346 :
case V_347 :
case V_348 :
break;
default:
goto error;
}
V_199 -> V_13 &= ~ ( 1 << V_332 ) ;
break;
case V_349 :
F_182 ( V_1 ,
(struct V_319 * ) V_258 ) ;
break;
case V_350 :
* V_258 = 0x00 ;
break;
case V_351 :
if ( V_333 > V_1 -> V_57 )
goto error;
* ( V_352 * ) V_258 = F_185 ( V_199 -> V_13 ) ;
break;
case V_353 :
if ( V_333 > V_1 -> V_57 )
goto error;
if ( V_334 != 0 )
goto error;
switch ( V_332 ) {
case V_342 :
break;
case V_343 :
F_24 ( V_1 , V_13 , 1 ) ;
V_199 -> V_13 |= V_341 ;
break;
case V_354 : {
struct V_64 * V_65 = V_199 -> V_65 ;
V_199 -> V_13 |= V_215 ;
F_99 ( V_1 , V_65 ) ;
F_50 ( V_1 , V_65 , 1 ) ;
F_12 ( V_1 , V_290 , V_290 | V_291 ,
F_156 ( V_13 ) ) ;
F_115 ( & V_1 -> V_194 ,
V_195 + F_116 ( 50 ) ) ;
}
break;
default:
goto error;
}
V_199 -> V_13 |= 1 << V_332 ;
break;
default:
error:
V_37 = - V_237 ;
break;
}
F_160 ( & V_1 -> V_177 , V_293 ) ;
return V_37 ;
}
static int F_186 ( struct V_250 * V_251 )
{
struct V_1 * V_1 = F_154 ( V_251 ) ;
int V_13 ;
F_49 ( & V_1 -> V_101 . V_63 -> V_65 , L_20 , V_355 ) ;
for ( V_13 = 0 ; V_13 < V_1 -> V_57 ; V_13 ++ ) {
struct V_198 * V_199 = & V_1 -> V_113 [ V_13 ] ;
unsigned long V_289 = F_156 ( V_13 ) ;
if ( ! ( V_199 -> V_13 & V_216 ) )
continue;
F_49 ( & V_199 -> V_65 -> V_63 -> V_65 , L_21 , V_13 ) ;
F_3 ( V_1 , V_291 , V_289 ) ;
V_199 -> V_13 |= V_356 ;
if ( V_199 -> V_65 -> V_63 -> V_357 ) {
F_14 ( 3 ) ;
F_4 ( V_1 , V_358 , V_289 ) ;
F_5 ( V_1 , ~ V_286 , F_23 ( V_13 ) ) ;
F_4 ( V_1 , V_287 , F_21 ( V_13 ) ) ;
}
}
V_1 -> V_212 = 1 ;
return 0 ;
}
static int F_187 ( struct V_250 * V_251 )
{
struct V_1 * V_1 = F_154 ( V_251 ) ;
int V_13 ;
F_49 ( & V_1 -> V_101 . V_63 -> V_65 , L_20 , V_355 ) ;
for ( V_13 = 0 ; V_13 < V_1 -> V_57 ; V_13 ++ ) {
struct V_198 * V_199 = & V_1 -> V_113 [ V_13 ] ;
unsigned long V_289 = F_156 ( V_13 ) ;
if ( ! ( V_199 -> V_13 & V_356 ) )
continue;
F_49 ( & V_199 -> V_65 -> V_63 -> V_65 , L_22 , V_13 ) ;
V_199 -> V_13 &= ~ V_356 ;
V_199 -> V_13 |= V_359 << 16 ;
F_12 ( V_1 , V_360 , V_360 | V_291 , V_289 ) ;
F_14 ( 50 ) ;
F_12 ( V_1 , V_291 , V_360 | V_291 , V_289 ) ;
}
return 0 ;
}
static int F_188 ( struct V_361 * V_65 )
{
struct V_1 * V_1 = F_28 ( V_65 ) ;
int V_13 ;
F_49 ( V_65 , L_20 , V_355 ) ;
F_26 ( V_1 ) ;
for ( V_13 = 0 ; V_13 < V_1 -> V_57 ; V_13 ++ ) {
struct V_198 * V_199 = & V_1 -> V_113 [ V_13 ] ;
V_199 -> V_13 = 0x00000000 ;
}
return 0 ;
}
static int F_189 ( struct V_361 * V_65 )
{
struct V_1 * V_1 = F_28 ( V_65 ) ;
struct V_250 * V_251 = F_92 ( V_1 ) ;
F_49 ( V_65 , L_20 , V_355 ) ;
F_25 ( V_1 ) ;
F_190 ( V_251 -> V_318 . V_113 ) ;
return 0 ;
}
static int F_191 ( struct V_362 * V_363 )
{
struct V_1 * V_1 = F_192 ( V_363 ) ;
struct V_250 * V_251 = F_92 ( V_1 ) ;
F_193 ( & V_1 -> V_194 ) ;
F_194 ( V_251 ) ;
F_195 ( V_1 -> V_3 ) ;
if ( V_1 -> V_17 -> V_18 )
F_196 ( V_1 -> V_19 ) ;
F_197 ( V_251 ) ;
return 0 ;
}
static int F_198 ( struct V_362 * V_363 )
{
char V_364 [ 8 ] ;
struct V_365 * V_366 = NULL , * V_367 ;
int V_368 = - 1 ;
void T_7 * V_3 = NULL ;
struct V_250 * V_251 = NULL ;
struct V_1 * V_1 ;
int V_37 = 0 ;
int V_16 ;
unsigned long V_369 ;
if ( F_199 () )
return - V_188 ;
if ( V_363 -> V_65 . V_370 ) {
V_37 = - V_371 ;
F_48 ( & V_363 -> V_65 , L_23 ) ;
goto V_372;
}
V_366 = F_200 ( V_363 , V_373 , 0 ) ;
if ( ! V_366 ) {
V_37 = - V_188 ;
F_48 ( & V_363 -> V_65 , L_24 ) ;
goto V_372;
}
V_367 = F_200 ( V_363 , V_374 , 0 ) ;
if ( ! V_367 ) {
V_37 = - V_188 ;
F_48 ( & V_363 -> V_65 ,
L_25 ) ;
goto V_372;
}
V_368 = V_367 -> V_375 ;
V_369 = V_367 -> V_293 & V_376 ;
V_3 = F_201 ( V_366 -> V_375 , F_202 ( V_366 ) ) ;
if ( V_3 == NULL ) {
V_37 = - V_106 ;
F_48 ( & V_363 -> V_65 , L_26 ) ;
goto V_372;
}
if ( V_363 -> V_65 . V_377 == NULL ) {
F_48 ( & V_363 -> V_65 , L_27 ) ;
V_37 = - V_188 ;
goto V_372;
}
V_251 = F_203 ( & V_378 , & V_363 -> V_65 , ( char * ) V_379 ) ;
if ( ! V_251 ) {
V_37 = - V_106 ;
F_48 ( & V_363 -> V_65 , L_28 ) ;
goto V_372;
}
V_1 = F_154 ( V_251 ) ;
memset ( V_1 , 0 , sizeof( struct V_1 ) ) ;
F_204 ( V_363 , V_1 ) ;
V_1 -> V_17 = F_205 ( & V_363 -> V_65 ) ;
V_1 -> V_41 = V_369 == V_380 ;
if ( V_1 -> V_17 -> V_18 ) {
snprintf ( V_364 , sizeof( V_364 ) , L_29 , V_363 -> V_381 ) ;
V_1 -> V_19 = F_206 ( & V_363 -> V_65 , V_364 ) ;
if ( F_207 ( V_1 -> V_19 ) ) {
F_48 ( & V_363 -> V_65 , L_30 ,
V_364 ) ;
V_37 = F_208 ( V_1 -> V_19 ) ;
goto V_382;
}
V_1 -> V_57 = 1 ;
} else
V_1 -> V_57 = 2 ;
F_209 ( & V_1 -> V_177 ) ;
F_210 ( & V_1 -> V_194 , F_163 ,
( unsigned long ) V_1 ) ;
V_1 -> V_3 = V_3 ;
V_37 = F_9 ( V_1 ) ;
if ( V_37 < 0 )
goto V_383;
F_26 ( V_1 ) ;
for ( V_16 = 0 ; V_16 < V_162 ; V_16 ++ ) {
F_45 ( & V_1 -> V_186 [ V_16 ] ) ;
F_210 ( & V_1 -> V_248 [ V_16 ] , F_161 ,
( unsigned long ) V_1 ) ;
F_210 ( & V_1 -> V_295 [ V_16 ] ,
F_157 ,
( unsigned long ) V_1 ) ;
}
F_45 ( & V_1 -> V_112 ) ;
V_251 -> V_384 = V_366 -> V_375 ;
V_251 -> V_385 = 1 ;
V_37 = F_211 ( V_251 , V_368 , V_369 ) ;
if ( V_37 != 0 ) {
F_48 ( & V_363 -> V_65 , L_31 ) ;
goto V_383;
}
F_212 ( V_251 -> V_318 . V_386 ) ;
return 0 ;
V_383:
if ( V_1 -> V_17 -> V_18 )
F_196 ( V_1 -> V_19 ) ;
V_382:
F_197 ( V_251 ) ;
V_372:
if ( V_3 )
F_195 ( V_3 ) ;
return V_37 ;
}
