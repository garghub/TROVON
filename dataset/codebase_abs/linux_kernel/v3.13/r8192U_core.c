double F_1 ( int V_1 )
{
return V_1 ;
}
unsigned int F_2 ( double V_2 )
{
return V_2 ;
}
double F_3 ( double V_3 , double V_4 )
{
return V_3 + V_4 ;
}
double F_4 ( float V_3 , float V_4 )
{
return V_3 + V_4 ;
}
double F_5 ( double V_3 , double V_4 )
{
return V_3 - V_4 ;
}
double F_6 ( float V_3 )
{
return V_3 ;
}
static void F_7 ( T_1 V_5 , struct V_6 * V_7 )
{
int V_1 , V_8 = - 1 , V_9 = - 1 ;
struct V_10 * V_11 = V_7 -> V_12 ;
switch ( V_5 ) {
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
F_8 ( V_11 ) ;
V_11 -> V_23 = false ;
if ( ( V_7 -> V_24 == V_25 ) || ( V_7 -> V_24 == V_26 ) ) {
V_9 = 1 ;
V_8 = 14 ;
} else {
F_9 ( V_27 , L_1 , V_28 ) ;
}
if ( V_29 [ V_5 ] . V_30 != 0 ) {
memset ( F_10 ( V_11 ) -> V_31 , 0 , sizeof( F_10 ( V_11 ) -> V_31 ) ) ;
for ( V_1 = 0 ; V_1 < V_29 [ V_5 ] . V_30 ; V_1 ++ ) {
if ( V_29 [ V_5 ] . V_32 [ V_1 ] < V_9 || V_29 [ V_5 ] . V_32 [ V_1 ] > V_8 )
break;
F_10 ( V_11 ) -> V_31 [ V_29 [ V_5 ] . V_32 [ V_1 ] ] = 1 ;
}
}
break;
case V_33 :
F_10 ( V_11 ) -> V_34 = 0 ;
F_11 ( V_11 ) ;
V_11 -> V_23 = true ;
break;
default:
break;
}
}
void F_12 ( struct V_35 * V_36 )
{
T_2 V_37 = 0 ;
V_37 |= V_38 | V_39 ;
F_13 ( V_36 , V_40 , V_37 ) ;
}
void F_14 ( struct V_35 * V_36 , T_1 V_41 , T_2 V_42 )
{
F_13 ( V_36 , V_43 , V_42 ) ;
F_13 ( V_36 , V_40 , V_38 | V_44 | ( V_41 & 0xff ) ) ;
}
T_2 F_15 ( struct V_35 * V_36 , T_1 V_41 )
{
T_2 V_42 ;
F_13 ( V_36 , V_40 , 0x80000000 | ( V_41 & 0xff ) ) ;
F_16 ( V_36 , 0xa8 , & V_42 ) ;
return V_42 ;
}
void F_17 ( struct V_35 * V_36 , int V_45 , T_1 V_42 )
{
int V_46 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_47 * V_48 = V_7 -> V_48 ;
V_46 = F_19 ( V_48 , F_20 ( V_48 , 0 ) ,
V_49 , V_50 ,
V_45 | 0xfe00 , 0 , & V_42 , 1 , V_51 / 2 ) ;
if ( V_46 < 0 )
F_21 ( V_36 , L_2 , V_46 ) ;
}
int F_22 ( struct V_35 * V_36 , int V_45 , T_1 * V_42 )
{
int V_46 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_47 * V_48 = V_7 -> V_48 ;
V_46 = F_19 ( V_48 , F_23 ( V_48 , 0 ) ,
V_52 , V_53 ,
V_45 | 0xfe00 , 0 , V_42 , 1 , V_51 / 2 ) ;
if ( V_46 < 0 ) {
F_21 ( V_36 , L_3 , V_28 , V_46 ) ;
return V_46 ;
}
return 0 ;
}
void F_24 ( struct V_35 * V_36 , int V_45 , T_1 V_42 )
{
int V_46 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_47 * V_48 = V_7 -> V_48 ;
V_46 = F_19 ( V_48 , F_20 ( V_48 , 0 ) ,
V_49 , V_50 ,
( V_45 & 0xff ) | 0xff00 , ( V_45 >> 8 ) & 0x0f , & V_42 , 1 , V_51 / 2 ) ;
if ( V_46 < 0 )
F_21 ( V_36 , L_4 , V_46 ) ;
}
void F_25 ( struct V_35 * V_36 , int V_45 , T_3 V_42 )
{
int V_46 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_47 * V_48 = V_7 -> V_48 ;
V_46 = F_19 ( V_48 , F_20 ( V_48 , 0 ) ,
V_49 , V_50 ,
( V_45 & 0xff ) | 0xff00 , ( V_45 >> 8 ) & 0x0f , & V_42 , 2 , V_51 / 2 ) ;
if ( V_46 < 0 )
F_21 ( V_36 , L_5 , V_46 ) ;
}
void F_13 ( struct V_35 * V_36 , int V_45 , T_2 V_42 )
{
int V_46 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_47 * V_48 = V_7 -> V_48 ;
V_46 = F_19 ( V_48 , F_20 ( V_48 , 0 ) ,
V_49 , V_50 ,
( V_45 & 0xff ) | 0xff00 , ( V_45 >> 8 ) & 0x0f , & V_42 , 4 , V_51 / 2 ) ;
if ( V_46 < 0 )
F_21 ( V_36 , L_6 , V_46 ) ;
}
int F_26 ( struct V_35 * V_36 , int V_45 , T_1 * V_42 )
{
int V_46 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_47 * V_48 = V_7 -> V_48 ;
V_46 = F_19 ( V_48 , F_23 ( V_48 , 0 ) ,
V_52 , V_53 ,
( V_45 & 0xff ) | 0xff00 , ( V_45 >> 8 ) & 0x0f , V_42 , 1 , V_51 / 2 ) ;
if ( V_46 < 0 ) {
F_21 ( V_36 , L_3 , V_28 , V_46 ) ;
return V_46 ;
}
return 0 ;
}
int F_27 ( struct V_35 * V_36 , int V_45 , T_3 * V_42 )
{
int V_46 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_47 * V_48 = V_7 -> V_48 ;
V_46 = F_19 ( V_48 , F_23 ( V_48 , 0 ) ,
V_52 , V_53 ,
( V_45 & 0xff ) | 0xff00 , ( V_45 >> 8 ) & 0x0f ,
V_42 , 2 , V_51 / 2 ) ;
if ( V_46 < 0 ) {
F_21 ( V_36 , L_3 , V_28 , V_46 ) ;
return V_46 ;
}
return 0 ;
}
static int F_28 ( struct V_35 * V_36 , int V_45 , T_3 * V_42 )
{
int V_46 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_47 * V_48 = V_7 -> V_48 ;
V_46 = F_19 ( V_48 , F_23 ( V_48 , 0 ) ,
V_52 , V_53 ,
V_45 | 0xfe00 , 0 , V_42 , 2 , V_51 / 2 ) ;
if ( V_46 < 0 ) {
F_21 ( V_36 , L_3 , V_28 , V_46 ) ;
return V_46 ;
}
return 0 ;
}
int F_16 ( struct V_35 * V_36 , int V_45 , T_2 * V_42 )
{
int V_46 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_47 * V_48 = V_7 -> V_48 ;
V_46 = F_19 ( V_48 , F_23 ( V_48 , 0 ) ,
V_52 , V_53 ,
( V_45 & 0xff ) | 0xff00 , ( V_45 >> 8 ) & 0x0f ,
V_42 , 4 , V_51 / 2 ) ;
if ( V_46 < 0 ) {
F_21 ( V_36 , L_3 , V_28 , V_46 ) ;
return V_46 ;
}
return 0 ;
}
inline void F_29 ( struct V_35 * V_36 )
{
}
static int F_30 ( struct V_54 * V_55 , void * V_56 )
{
struct V_35 * V_36 = V_55 -> V_57 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_58 * V_59 ;
F_31 (target, &ieee->network_list, list) {
const char * V_60 = L_7 ;
if ( V_59 -> V_61 > 0 || V_59 -> V_62 > 0 )
V_60 = L_8 ;
F_32 ( V_55 , L_9 , V_59 -> V_63 , V_60 ) ;
}
return 0 ;
}
static int F_33 ( struct V_54 * V_55 , void * V_56 )
{
struct V_35 * V_36 = V_55 -> V_57 ;
int V_1 , V_64 , V_65 = 0xff ;
T_1 V_66 ;
F_34 ( V_55 , L_10 ) ;
for ( V_64 = 0 ; V_64 <= V_65 ; ) {
F_32 ( V_55 , L_11 , V_64 ) ;
for ( V_1 = 0 ; V_1 < 16 && V_64 <= V_65 ; V_1 ++ , V_64 ++ ) {
F_26 ( V_36 , 0x000 | V_64 , & V_66 ) ;
F_32 ( V_55 , L_12 , V_66 ) ;
}
}
F_34 ( V_55 , L_13 ) ;
for ( V_64 = 0 ; V_64 <= V_65 ; ) {
F_32 ( V_55 , L_11 , V_64 ) ;
for ( V_1 = 0 ; V_1 < 16 && V_64 <= V_65 ; V_1 ++ , V_64 ++ ) {
F_26 ( V_36 , 0x100 | V_64 , & V_66 ) ;
F_32 ( V_55 , L_12 , V_66 ) ;
}
}
F_34 ( V_55 , L_14 ) ;
for ( V_64 = 0 ; V_64 <= V_65 ; ) {
F_32 ( V_55 , L_11 , V_64 ) ;
for ( V_1 = 0 ; V_1 < 16 && V_64 <= V_65 ; V_1 ++ , V_64 ++ ) {
F_26 ( V_36 , 0x300 | V_64 , & V_66 ) ;
F_32 ( V_55 , L_12 , V_66 ) ;
}
}
F_35 ( V_55 , '\n' ) ;
return 0 ;
}
static int F_36 ( struct V_54 * V_55 , void * V_56 )
{
struct V_35 * V_36 = V_55 -> V_57 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
F_32 ( V_55 ,
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22
L_23
L_24
L_25
L_26
L_27
L_28
L_29
L_30
L_31
L_32
L_33
L_34
L_35
L_36
L_37
L_38 ,
V_7 -> V_67 . V_68 ,
V_7 -> V_67 . V_69 ,
V_7 -> V_67 . V_70 ,
V_7 -> V_67 . V_71 ,
V_7 -> V_67 . V_72 ,
V_7 -> V_67 . V_73 ,
V_7 -> V_67 . V_74 ,
V_7 -> V_67 . V_75 ,
V_7 -> V_67 . V_76 ,
V_7 -> V_67 . V_77 ,
V_7 -> V_67 . V_78 ,
V_7 -> V_67 . V_79 ,
V_7 -> V_67 . V_80 ,
F_37 ( V_36 ) ,
V_7 -> V_67 . V_81 ,
F_38 ( & ( V_7 -> V_82 [ V_83 ] ) ) ,
F_38 ( & ( V_7 -> V_82 [ V_84 ] ) ) ,
F_38 ( & ( V_7 -> V_82 [ V_85 ] ) ) ,
F_38 ( & ( V_7 -> V_82 [ V_86 ] ) ) ,
V_7 -> V_67 . V_87 ,
V_7 -> V_67 . V_88 ,
V_7 -> V_67 . V_89 ,
V_7 -> V_67 . V_90 ,
V_7 -> V_67 . V_91
) ;
return 0 ;
}
static int F_39 ( struct V_54 * V_55 , void * V_56 )
{
struct V_35 * V_36 = V_55 -> V_57 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
F_32 ( V_55 ,
L_39
L_40
L_41 ,
V_7 -> V_67 . V_92 ,
V_7 -> V_67 . V_93 ,
V_7 -> V_67 . V_94 ) ;
return 0 ;
}
static void F_40 ( void )
{
F_9 ( V_95 , L_42 ) ;
V_96 = F_41 ( V_97 , V_98 . V_99 ) ;
}
void F_42 ( void )
{
F_43 ( V_97 , V_98 . V_99 ) ;
}
static int F_44 ( struct V_100 * V_100 , struct V_101 * V_101 )
{
struct V_35 * V_36 = F_45 ( V_100 ) ;
int (* F_46)( struct V_54 * , void * ) = F_47 ( V_100 ) ;
return F_48 ( V_101 , F_46 , V_36 ) ;
}
static void F_49 ( struct V_35 * V_36 )
{
const struct V_102 * V_103 ;
struct V_104 * V_105 ;
if ( V_96 ) {
V_105 = F_50 ( V_36 -> V_106 , 0 , V_96 , V_36 ) ;
if ( ! V_105 ) {
F_9 ( V_27 , L_43 ,
V_36 -> V_106 ) ;
return;
}
for ( V_103 = V_107 ; V_103 -> V_106 [ 0 ] ; V_103 ++ ) {
if ( ! F_51 ( V_103 -> V_106 , V_108 | V_109 , V_105 ,
& V_110 , V_103 -> F_46 ) ) {
F_9 ( V_27 , L_44
L_45 ,
V_36 -> V_106 , V_103 -> V_106 ) ;
return;
}
}
}
}
static void F_52 ( struct V_35 * V_36 )
{
F_53 ( V_36 -> V_106 , V_96 ) ;
}
short F_54 ( struct V_35 * V_36 , int V_111 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_112 = F_38 ( & V_7 -> V_82 [ V_111 ] ) ;
return ( V_112 < V_113 ) ;
}
void F_55 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
F_56 ( & V_7 -> V_114 ) ;
}
void F_57 ( struct V_35 * V_36 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < 63 ; V_1 ++ )
F_9 ( V_115 , L_46 , V_1 , F_58 ( V_36 , V_1 ) ) ;
}
void F_59 ( struct V_35 * V_36 , int V_116 )
{
T_1 V_117 ;
F_26 ( V_36 , V_118 , & V_117 ) ;
V_117 = V_117 & ~ V_119 ;
V_117 = V_117 | ( V_116 << V_120 ) ;
V_117 = V_117 & ~ V_121 ;
V_117 = V_117 & ~ V_122 ;
F_24 ( V_36 , V_118 , V_117 ) ;
}
void F_60 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 V_123 ;
F_26 ( V_36 , V_124 , & V_123 ) ;
V_123 &= ~ V_125 ;
if ( V_7 -> V_12 -> V_126 == V_127 ) {
if ( V_7 -> V_12 -> V_128 == V_129 )
V_123 |= ( V_130 << V_131 ) ;
else if ( V_7 -> V_12 -> V_128 == V_132 )
V_123 |= ( V_133 << V_131 ) ;
else if ( V_7 -> V_12 -> V_128 == V_134 )
V_123 |= ( V_135 << V_131 ) ;
} else {
V_123 |= ( V_136 << V_131 ) ;
}
F_24 ( V_36 , V_124 , V_123 ) ;
}
void F_61 ( struct V_35 * V_36 , short V_137 )
{
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
F_9 ( V_138 , L_47 , V_28 , V_137 ) ;
V_7 -> V_139 = V_137 ;
#ifndef F_62
if ( V_7 -> V_140 )
V_7 -> V_140 ( V_36 , V_7 -> V_139 ) ;
F_63 ( 10 ) ;
#endif
}
static T_2 F_64 ( struct V_141 * V_142 )
{
#ifdef F_65
if ( V_142 -> V_143 )
return ( sizeof( V_144 ) + V_142 -> V_145
+ V_142 -> V_146 + 8 ) ;
else
#endif
return ( sizeof( V_144 ) + V_142 -> V_145
+ V_142 -> V_146 ) ;
}
static int F_66 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_147 * V_148 ;
struct V_149 * V_150 ;
struct V_151 * V_152 ;
while ( F_67 ( & V_7 -> V_153 ) < V_154 ) {
V_150 = F_68 ( V_155 , V_156 ) ;
if ( ! V_150 )
break;
V_148 = F_69 ( 0 , V_156 ) ;
if ( ! V_148 ) {
F_70 ( V_150 ) ;
break;
}
F_71 ( V_148 , V_7 -> V_48 ,
F_72 ( V_7 -> V_48 , 3 ) , F_73 ( V_150 ) ,
V_155 , V_157 , V_150 ) ;
V_152 = (struct V_151 * ) V_150 -> V_158 ;
V_152 -> V_147 = V_148 ;
V_152 -> V_36 = V_36 ;
V_152 -> V_159 = 3 ;
F_74 ( & V_7 -> V_153 , V_150 ) ;
F_75 ( V_148 , V_156 ) ;
}
while ( F_67 ( & V_7 -> V_153 ) < V_154 + 3 ) {
V_150 = F_68 ( V_155 , V_156 ) ;
if ( ! V_150 )
break;
V_148 = F_69 ( 0 , V_156 ) ;
if ( ! V_148 ) {
F_70 ( V_150 ) ;
break;
}
F_71 ( V_148 , V_7 -> V_48 ,
F_72 ( V_7 -> V_48 , 9 ) , F_73 ( V_150 ) ,
V_155 , V_157 , V_150 ) ;
V_152 = (struct V_151 * ) V_150 -> V_158 ;
V_152 -> V_147 = V_148 ;
V_152 -> V_36 = V_36 ;
V_152 -> V_159 = 9 ;
F_74 ( & V_7 -> V_153 , V_150 ) ;
F_75 ( V_148 , V_156 ) ;
}
return 0 ;
}
void F_76 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
T_2 V_160 ;
F_16 ( V_36 , V_161 , & V_160 ) ;
V_160 = V_160 & ~ V_162 ;
V_160 = V_160 | V_163 ;
V_160 = V_160 | V_164 ;
V_160 = V_160 | V_165 ;
V_160 = V_160 | V_166 ;
if ( V_36 -> V_167 & V_168 )
F_77 ( L_48 ) ;
if ( V_7 -> V_12 -> V_128 == V_169 ||
V_36 -> V_167 & V_168 ) {
V_160 = V_160 | V_170 ;
} else {
V_160 = V_160 | V_171 ;
V_160 = V_160 | V_172 ;
}
if ( V_7 -> V_12 -> V_128 == V_169 ) {
V_160 = V_160 | V_173 ;
V_160 = V_160 | V_174 ;
}
if ( V_7 -> V_175 == 1 && V_7 -> V_12 -> V_128 == V_169 )
V_160 = V_160 | V_176 ;
V_160 = V_160 & ~ V_177 ;
V_160 = V_160 | ( V_178 << V_179 ) ;
V_160 = V_160 & ~ V_180 ;
V_160 = V_160 | ( ( T_2 ) 7 << V_181 ) ;
V_160 = V_160 | V_182 ;
F_13 ( V_36 , V_161 , V_160 ) ;
}
void F_78 ( struct V_35 * V_36 )
{
F_66 ( V_36 ) ;
}
void F_79 ( struct V_35 * V_36 )
{
}
void F_80 ( struct V_35 * V_36 )
{
T_1 V_183 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_149 * V_150 ;
struct V_151 * V_152 ;
F_26 ( V_36 , V_184 , & V_183 ) ;
F_24 ( V_36 , V_184 , V_183 & ~ ( V_185 | V_186 ) ) ;
F_29 ( V_36 ) ;
F_63 ( 10 ) ;
while ( ( V_150 = F_81 ( & V_7 -> V_153 ) ) ) {
V_152 = (struct V_151 * ) V_150 -> V_158 ;
if ( ! V_152 -> V_147 )
continue;
F_82 ( V_152 -> V_147 ) ;
F_70 ( V_150 ) ;
}
if ( F_67 ( & V_7 -> V_187 ) )
F_83 ( V_36 , L_49 ) ;
F_84 ( & V_7 -> V_187 ) ;
return;
}
int F_85 ( struct V_35 * V_36 , int V_188 )
{
return 0 ;
}
inline T_3 F_86 ( int V_189 )
{
switch ( V_189 ) {
case 10 :
return 0 ;
case 20 :
return 1 ;
case 55 :
return 2 ;
case 110 :
return 3 ;
case 60 :
return 4 ;
case 90 :
return 5 ;
case 120 :
return 6 ;
case 180 :
return 7 ;
case 240 :
return 8 ;
case 360 :
return 9 ;
case 480 :
return 10 ;
case 540 :
return 11 ;
default:
return 3 ;
}
}
inline T_3 F_87 ( short V_189 )
{
if ( V_189 > 11 ) return 0 ;
return V_190 [ V_189 ] ;
}
static void V_157 ( struct V_147 * V_147 )
{
struct V_149 * V_150 = (struct V_149 * ) V_147 -> V_191 ;
struct V_151 * V_152 = (struct V_151 * ) V_150 -> V_158 ;
struct V_35 * V_36 = V_152 -> V_36 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_159 = V_152 -> V_159 ;
int V_192 ;
if ( ! V_7 -> V_193 )
return;
if ( F_88 ( V_147 -> V_46 ) ) {
V_152 -> V_147 = NULL ;
V_7 -> V_67 . V_93 ++ ;
V_7 -> V_12 -> V_67 . V_194 ++ ;
F_89 ( V_147 ) ;
return;
}
F_90 ( V_150 , & V_7 -> V_153 ) ;
F_91 ( V_150 , V_147 -> V_195 ) ;
F_74 ( & V_7 -> V_187 , V_150 ) ;
F_92 ( & V_7 -> V_196 ) ;
V_150 = F_93 ( V_155 ) ;
if ( F_88 ( ! V_150 ) ) {
F_89 ( V_147 ) ;
F_21 ( V_36 , L_50 , V_28 ) ;
return;
}
F_71 ( V_147 , V_7 -> V_48 ,
F_72 ( V_7 -> V_48 , V_159 ) , F_73 ( V_150 ) ,
V_155 , V_157 , V_150 ) ;
V_152 = (struct V_151 * ) V_150 -> V_158 ;
V_152 -> V_147 = V_147 ;
V_152 -> V_36 = V_36 ;
V_152 -> V_159 = V_159 ;
V_147 -> V_197 = F_73 ( V_150 ) ;
V_147 -> V_191 = V_150 ;
F_74 ( & V_7 -> V_153 , V_150 ) ;
V_192 = F_75 ( V_147 , V_198 ) ;
if ( V_192 && V_192 != V_199 )
F_21 ( V_36 , L_51 , V_192 , V_147 -> V_46 ) ;
}
static T_2 F_94 ( struct V_35 * V_36 ,
struct V_141 * V_142 )
{
T_2 V_46 ;
V_46 = F_95 ( V_36 , V_142 ) ;
if ( V_46 )
F_77 ( L_52 ) ;
return V_46 ;
}
void F_96 ( struct V_35 * V_36 )
{
}
void F_97 ( struct V_35 * V_36 )
{
}
void F_98 ( struct V_149 * V_150 , struct V_35 * V_36 , int V_189 )
{
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
int V_200 ;
unsigned long V_167 ;
T_4 * V_201 = ( T_4 * ) ( V_150 -> V_158 + V_202 ) ;
T_1 V_111 = V_201 -> V_111 ;
F_99 ( V_111 != V_203 ) ;
F_100 ( & V_7 -> V_204 , V_167 ) ;
memcpy ( ( unsigned char * ) ( V_150 -> V_158 ) , & V_36 , sizeof( V_36 ) ) ;
V_201 -> V_205 = 1 ;
F_101 ( V_150 , V_7 -> V_12 -> V_206 ) ;
V_200 = F_102 ( V_36 , V_150 ) ;
F_103 ( & V_7 -> V_204 , V_167 ) ;
return;
}
int F_104 ( struct V_149 * V_150 , struct V_35 * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
int V_200 ;
unsigned long V_167 ;
T_4 * V_201 = ( T_4 * ) ( V_150 -> V_158 + V_202 ) ;
T_1 V_111 = V_201 -> V_111 ;
F_100 ( & V_7 -> V_204 , V_167 ) ;
memcpy ( ( unsigned char * ) ( V_150 -> V_158 ) , & V_36 , sizeof( V_36 ) ) ;
if ( V_111 == V_203 ) {
F_101 ( V_150 , V_207 ) ;
F_105 ( V_36 , V_150 ) ;
V_200 = 1 ;
F_103 ( & V_7 -> V_204 , V_167 ) ;
return V_200 ;
} else {
F_101 ( V_150 , V_7 -> V_12 -> V_206 ) ;
V_200 = F_102 ( V_36 , V_150 ) ;
}
F_103 ( & V_7 -> V_204 , V_167 ) ;
return V_200 ;
}
T_3 F_106 ( struct V_35 * V_36 , struct V_149 * V_150 )
{
T_3 V_208 = 256 - ( ( V_150 -> V_209 + V_210 ) % 256 ) ;
return V_208 & 0xff ;
}
struct V_149 * F_107 ( struct V_35 * V_36 , struct V_211 * V_212 )
{
struct V_10 * V_11 = F_108 ( V_36 ) ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_4 * V_201 = NULL ;
T_1 V_1 ;
T_2 V_213 ;
struct V_149 * V_150 ;
struct V_149 * V_214 ;
T_5 * V_215 = NULL ;
T_6 * V_216 = NULL ;
V_150 = V_212 -> V_217 [ 0 ] ;
V_213 = V_150 -> V_209 ;
for ( V_1 = 1 ; V_1 < V_212 -> V_218 ; V_1 ++ ) {
V_213 += F_106 ( V_36 , V_150 ) ;
V_150 = V_212 -> V_217 [ V_1 ] ;
V_213 += ( V_150 -> V_209 + V_210 ) ;
}
V_214 = F_93 ( V_213 + V_11 -> V_206 ) ;
memset ( V_214 -> V_42 , 0 , V_214 -> V_209 ) ;
F_109 ( V_214 , V_11 -> V_206 ) ;
V_150 = V_212 -> V_217 [ 0 ] ;
V_201 = ( T_4 * ) ( V_150 -> V_158 + V_202 ) ;
V_201 -> V_219 = 1 ;
V_201 -> V_220 = V_150 -> V_209 ;
V_201 -> V_221 = V_212 -> V_218 ;
F_110 ( V_36 , L_53 , V_201 -> V_221 ) ;
memcpy ( V_214 -> V_158 , V_150 -> V_158 , sizeof( V_150 -> V_158 ) ) ;
memcpy ( F_91 ( V_214 , V_150 -> V_209 ) , V_150 -> V_42 , V_150 -> V_209 ) ;
for ( V_1 = 1 ; V_1 < V_212 -> V_218 ; V_1 ++ ) {
F_91 ( V_214 , F_106 ( V_36 , V_150 ) ) ;
V_150 = V_212 -> V_217 [ V_1 ] ;
V_201 = ( T_4 * ) ( V_150 -> V_158 + V_202 ) ;
V_215 = ( T_5 * ) F_73 ( V_214 ) ;
V_216 = ( T_6 * ) ( F_73 ( V_214 ) + sizeof( T_5 ) ) ;
memset ( V_216 , 0 , sizeof( T_6 ) ) ;
V_216 -> V_222 = ( V_201 -> V_223 & 0x80 ) ? 1 : 0 ;
V_216 -> V_224 = F_111 ( V_201 -> V_223 ) ;
V_216 -> V_225 = V_201 -> V_205 ;
V_216 -> Short = F_112 ( V_216 -> V_222 , V_216 -> V_224 , V_201 ) ;
if ( V_201 -> V_226 ) {
V_216 -> V_227 = 1 ;
V_216 -> V_228 = V_201 -> V_229 ;
V_216 -> V_230 = V_201 -> V_231 & 0x07 ;
} else {
V_216 -> V_227 = 0 ;
V_216 -> V_228 = 0 ;
V_216 -> V_230 = 0 ;
}
V_216 -> V_232 = ( V_201 -> V_233 ) ? 1 : 0 ;
V_216 -> V_234 = ( V_201 -> V_235 ) ? 1 : 0 ;
V_216 -> V_236 = ( V_201 -> V_237 ) ? 1 : 0 ;
V_216 -> V_238 = ( V_201 -> V_239 & 0x80 ) ? 1 : 0 ;
V_216 -> V_240 = F_111 ( ( T_1 ) V_201 -> V_239 ) ;
V_216 -> V_241 = ( V_216 -> V_238 == 0 ) ? ( V_201 -> V_242 ) : 0 ;
V_216 -> V_243 = ( V_216 -> V_238 == 1 ) ? ( ( V_201 -> V_244 ) ? 1 : 0 ) : 0 ;
V_216 -> V_245 = ( V_216 -> V_238 == 0 ) ? ( V_201 -> V_246 ? 1 : 0 ) :
( V_201 -> V_247 ? 1 : 0 ) ;
if ( V_7 -> V_248 == V_249 ) {
if ( V_201 -> V_250 ) {
V_216 -> V_251 = 1 ;
V_216 -> V_252 = 0 ;
} else {
V_216 -> V_251 = 0 ;
V_216 -> V_252 = V_7 -> V_253 ;
}
} else {
V_216 -> V_251 = 0 ;
V_216 -> V_252 = 0 ;
}
memset ( V_215 , 0 , sizeof( T_5 ) ) ;
V_215 -> V_254 = sizeof( T_6 ) + 8 ;
V_215 -> V_255 = V_150 -> V_209 & 0xffff ;
V_215 -> V_256 = 0 ;
V_215 -> V_257 = V_201 -> V_258 ;
V_215 -> V_259 = 1 ;
V_215 -> V_260 = 0x0 ;
if ( V_201 -> V_261 ) {
switch ( V_7 -> V_12 -> V_262 ) {
case V_263 :
case V_264 :
V_215 -> V_260 = 0x1 ;
V_215 -> V_259 = 0 ;
break;
case V_265 :
V_215 -> V_260 = 0x2 ;
V_215 -> V_259 = 0 ;
break;
case V_266 :
V_215 -> V_260 = 0x3 ;
V_215 -> V_259 = 0 ;
break;
case V_267 :
V_215 -> V_260 = 0x0 ;
V_215 -> V_259 = 1 ;
break;
}
}
V_215 -> V_268 = F_113 ( V_201 -> V_111 ) ;
V_215 -> V_269 = sizeof( T_6 ) ;
V_215 -> V_270 = V_201 -> V_271 ;
V_215 -> V_272 = V_201 -> V_273 ;
V_215 -> V_274 = 1 ;
F_91 ( V_214 , V_210 ) ;
memcpy ( F_91 ( V_214 , V_150 -> V_209 ) , V_150 -> V_42 , V_150 -> V_209 ) ;
}
for ( V_1 = 0 ; V_1 < V_212 -> V_218 ; V_1 ++ )
F_114 ( V_212 -> V_217 [ V_1 ] ) ;
return V_214 ;
}
T_1 F_115 ( struct V_35 * V_36 , struct V_149 * V_150 ,
struct V_211 * V_212 )
{
struct V_10 * V_11 = F_108 ( V_36 ) ;
T_7 V_275 = V_11 -> V_275 ;
T_3 V_276 = V_275 -> V_277 ;
T_4 * V_201 = ( T_4 * ) ( V_150 -> V_158 + V_202 ) ;
T_1 V_278 = V_201 -> V_111 ;
do {
V_212 -> V_217 [ V_212 -> V_218 ++ ] = V_150 ;
if ( V_212 -> V_218 >= V_276 )
break;
} while ( ( V_150 = F_116 ( & V_11 -> V_279 [ V_278 ] ) ) );
F_9 ( V_280 , L_54 , V_212 -> V_218 ) ;
return V_212 -> V_218 ;
}
static void F_117 ( struct V_147 * V_281 )
{
struct V_149 * V_150 = (struct V_149 * ) V_281 -> V_191 ;
struct V_35 * V_36 = NULL ;
struct V_6 * V_7 = NULL ;
T_4 * V_201 = ( T_4 * ) ( V_150 -> V_158 + V_202 ) ;
T_1 V_111 = V_201 -> V_111 ;
memcpy ( & V_36 , (struct V_35 * ) ( V_150 -> V_158 ) , sizeof( struct V_35 * ) ) ;
V_7 = F_18 ( V_36 ) ;
if ( V_201 -> V_111 != V_203 ) {
if ( V_281 -> V_46 == 0 ) {
V_36 -> V_282 = V_283 ;
V_7 -> V_67 . V_284 ++ ;
V_7 -> V_12 -> V_285 . V_286 ++ ;
V_7 -> V_67 . V_287 += ( V_150 -> V_209 - V_7 -> V_12 -> V_206 ) ;
} else {
V_7 -> V_12 -> V_67 . V_288 ++ ;
}
}
if ( V_150 != NULL ) {
F_114 ( V_150 ) ;
F_89 ( V_281 ) ;
F_118 ( & V_7 -> V_82 [ V_111 ] ) ;
}
if ( V_111 != V_289 ) {
if ( ( F_67 ( & V_7 -> V_12 -> V_290 [ V_111 ] ) != 0 ) &&
( ! ( V_7 -> V_12 -> V_291 ) ) ) {
if ( NULL != ( V_150 = F_116 ( & ( V_7 -> V_12 -> V_290 [ V_111 ] ) ) ) )
V_7 -> V_12 -> V_292 ( V_150 , V_36 ) ;
return;
}
#ifdef F_119
else if ( ( F_67 ( & V_7 -> V_12 -> V_279 [ V_111 ] ) != 0 ) &&
( ! ( V_7 -> V_12 -> V_291 ) ) ) {
V_150 = F_116 ( & V_7 -> V_12 -> V_279 [ V_111 ] ) ;
if ( ! F_54 ( V_36 , V_111 ) ) {
F_120 ( & ( V_7 -> V_12 -> V_279 [ V_111 ] ) , V_150 ) ;
return;
}
{
struct V_211 V_293 ;
memset ( & V_293 , 0 , sizeof( struct V_211 ) ) ;
if ( F_115 ( V_36 , V_150 , & V_293 ) > 1 ) {
V_150 = F_107 ( V_36 , & V_293 ) ;
}
}
V_7 -> V_12 -> V_292 ( V_150 , V_36 ) ;
}
#endif
}
}
void F_121 ( struct V_35 * V_36 )
{
T_1 V_123 , V_294 , V_295 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
F_26 ( V_36 , V_124 , & V_123 ) ;
V_294 = V_123 & V_125 ;
V_295 = V_123 & ~ V_125 ;
if ( V_296 == V_7 -> V_297 )
F_82 ( V_7 -> V_298 [ V_154 ] ) ;
if ( ( V_294 == ( V_133 << V_131 ) ||
( V_294 == ( V_135 << V_131 ) ) ) ) {
F_24 ( V_36 , V_124 , V_295 | V_136 ) ;
F_24 ( V_36 , V_124 , V_123 ) ;
}
}
void F_122 ( struct V_35 * V_36 , T_3 * V_299 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_58 * V_300 ;
T_1 V_1 = 0 , V_301 = 0 ;
V_300 = & V_7 -> V_12 -> V_302 ;
for ( V_1 = 0 ; V_1 < V_300 -> V_303 ; V_1 ++ ) {
V_301 = V_300 -> V_304 [ V_1 ] & 0x7f ;
switch ( V_301 ) {
case V_305 : * V_299 |= V_306 ; break;
case V_307 : * V_299 |= V_308 ; break;
case V_309 : * V_299 |= V_310 ; break;
case V_311 : * V_299 |= V_312 ; break;
case V_313 : * V_299 |= V_314 ; break;
case V_315 : * V_299 |= V_316 ; break;
case V_317 : * V_299 |= V_318 ; break;
case V_319 : * V_299 |= V_320 ; break;
case V_321 : * V_299 |= V_322 ; break;
case V_323 : * V_299 |= V_324 ; break;
case V_325 : * V_299 |= V_326 ; break;
case V_327 : * V_299 |= V_328 ; break;
}
}
for ( V_1 = 0 ; V_1 < V_300 -> V_329 ; V_1 ++ ) {
V_301 = V_300 -> V_330 [ V_1 ] & 0x7f ;
switch ( V_301 ) {
case V_305 : * V_299 |= V_306 ; break;
case V_307 : * V_299 |= V_308 ; break;
case V_309 : * V_299 |= V_310 ; break;
case V_311 : * V_299 |= V_312 ; break;
case V_313 : * V_299 |= V_314 ; break;
case V_315 : * V_299 |= V_316 ; break;
case V_317 : * V_299 |= V_318 ; break;
case V_319 : * V_299 |= V_320 ; break;
case V_321 : * V_299 |= V_322 ; break;
case V_323 : * V_299 |= V_324 ; break;
case V_325 : * V_299 |= V_326 ; break;
case V_327 : * V_299 |= V_328 ; break;
}
}
}
void F_123 ( struct V_35 * V_36 , T_3 V_331 )
{
T_2 V_332 = 0 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_58 * V_300 = & V_7 -> V_12 -> V_302 ;
V_7 -> V_333 = V_331 & V_334 ;
V_332 = V_7 -> V_301 ;
if ( V_7 -> V_333 )
V_332 |= V_335 ;
F_13 ( V_36 , V_336 , V_332 ) ;
if ( V_300 -> V_116 & ( V_337 | V_338 ) ) {
T_1 V_339 = 0 ;
if ( ( V_331 & V_340 ) && ( ! V_7 -> V_12 -> V_275 -> V_341 ) )
V_339 = V_342 ;
else
V_339 = V_343 ;
V_7 -> V_339 = V_339 ;
F_24 ( V_36 , V_344 , V_339 ) ;
}
}
void F_124 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_58 * V_300 ;
T_3 V_345 = 0 , V_346 = 6 , V_347 = 0xf ;
T_3 V_299 = 0 ;
V_300 = & V_7 -> V_12 -> V_302 ;
F_122 ( V_36 , & V_299 ) ;
V_7 -> V_301 = V_299 &= 0x15f ;
F_13 ( V_36 , V_348 , ( ( T_2 * ) V_300 -> V_349 ) [ 0 ] ) ;
F_25 ( V_36 , V_348 + 4 , ( ( T_3 * ) V_300 -> V_349 ) [ 2 ] ) ;
F_60 ( V_36 ) ;
if ( V_7 -> V_12 -> V_128 == V_132 ) {
F_25 ( V_36 , V_350 , 2 ) ;
F_25 ( V_36 , V_351 , 1023 ) ;
F_25 ( V_36 , V_352 , V_300 -> V_353 ) ;
F_25 ( V_36 , V_354 , 1 ) ;
F_24 ( V_36 , V_355 , 100 ) ;
V_345 |= ( V_346 << V_356 ) ;
V_345 |= V_347 << V_357 ;
F_25 ( V_36 , V_358 , V_345 ) ;
}
}
void F_125 ( struct V_35 * V_36 , T_3 V_359 )
{
}
inline T_1 F_126 ( T_3 V_189 )
{
if ( ( ( V_189 <= 110 ) && ( V_189 != 60 ) && ( V_189 != 90 ) ) || ( V_189 == 220 ) )
return 1 ;
else return 0 ;
}
T_3 F_127 ( T_3 V_360 , T_3 V_361 , T_1 V_362 ,
T_1 V_363 )
{
T_3 V_364 ;
T_3 V_365 ;
T_3 V_366 ;
if ( F_126 ( V_361 ) ) {
if ( V_362 || ! V_363 || V_361 == 10 )
V_364 = ( T_3 ) ( 144 + 48 + ( V_360 * 8 / ( V_361 / 10 ) ) ) ;
else
V_364 = ( T_3 ) ( 72 + 24 + ( V_360 * 8 / ( V_361 / 10 ) ) ) ;
if ( ( V_360 * 8 % ( V_361 / 10 ) ) != 0 )
V_364 ++ ;
} else {
V_365 = F_128 ( V_361 ) ;
V_366 = ( 16 + 8 * V_360 + 6 ) / V_365
+ ( ( ( 16 + 8 * V_360 + 6 ) % V_365 ) ? 1 : 0 ) ;
V_364 = ( T_3 ) ( 16 + 4 + 4 * V_366 + 6 ) ;
}
return V_364 ;
}
T_3 F_128 ( T_3 V_361 )
{
T_3 V_365 = 24 ;
switch ( V_361 ) {
case 60 :
V_365 = 24 ;
break;
case 90 :
V_365 = 36 ;
break;
case 120 :
V_365 = 48 ;
break;
case 180 :
V_365 = 72 ;
break;
case 240 :
V_365 = 96 ;
break;
case 360 :
V_365 = 144 ;
break;
case 480 :
V_365 = 192 ;
break;
case 540 :
V_365 = 216 ;
break;
default:
break;
}
return V_365 ;
}
void F_129 ( struct V_147 * V_367 , struct V_368 * V_369 )
{
F_89 ( V_367 ) ;
}
unsigned int F_130 ( struct V_6 * V_7 , unsigned int V_370 )
{
if ( V_370 >= 9 ) {
F_9 ( V_27 , L_55 , V_28 ) ;
return 0x04 ;
}
return V_7 -> V_371 [ V_370 ] ;
}
short F_105 ( struct V_35 * V_36 , struct V_149 * V_150 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_46 ;
struct V_147 * V_281 ;
unsigned int V_372 ;
T_8 * V_373 = ( T_8 * ) V_150 -> V_42 ;
T_4 * V_201 = ( T_4 * ) ( V_150 -> V_158 + V_202 ) ;
T_1 V_111 = V_201 -> V_111 ;
F_131 ( & V_7 -> V_82 [ V_111 ] ) ;
V_281 = F_69 ( 0 , V_198 ) ;
if ( ! V_281 ) {
F_132 ( V_150 ) ;
return - V_374 ;
}
memset ( V_373 , 0 , V_207 ) ;
V_373 -> V_375 = 1 ;
V_373 -> V_376 = 1 ;
V_373 -> V_377 = V_201 -> V_378 ;
V_373 -> V_379 = V_201 -> V_380 ;
V_373 -> V_274 = 1 ;
V_373 -> V_381 = V_201 -> V_382 ;
#ifndef F_133
V_372 = F_130 ( V_7 , V_111 ) ;
#else
V_372 = 0x04 ;
#endif
F_71 ( V_281 , V_7 -> V_48 , F_134 ( V_7 -> V_48 , V_372 ) ,
V_150 -> V_42 , V_150 -> V_209 , F_117 , V_150 ) ;
V_46 = F_75 ( V_281 , V_198 ) ;
if ( ! V_46 ) {
return 0 ;
} else {
F_135 ( L_56 , V_46 ) ;
return - 1 ;
}
}
static T_1 F_113 ( T_1 V_278 )
{
T_1 V_268 = 0x0 ;
switch ( V_278 ) {
case V_383 :
V_268 = V_384 ;
break;
case V_385 :
V_268 = V_386 ;
break;
case V_387 :
V_268 = V_388 ;
break;
case V_389 :
V_268 = V_390 ;
break;
case V_391 :
V_268 = V_392 ;
break;
case V_289 :
V_268 = V_393 ;
break;
case V_203 :
V_268 = V_394 ;
break;
case V_395 :
V_268 = V_396 ;
break;
default:
F_9 ( V_27 , L_57 , V_278 ) ;
break;
}
return V_268 ;
}
T_1 F_111 ( T_1 V_189 )
{
T_1 V_200 = V_397 ;
switch ( V_189 ) {
case V_305 : V_200 = V_397 ; break;
case V_307 : V_200 = V_398 ; break;
case V_309 : V_200 = V_399 ; break;
case V_311 : V_200 = V_400 ; break;
case V_313 : V_200 = V_401 ; break;
case V_315 : V_200 = V_402 ; break;
case V_317 : V_200 = V_403 ; break;
case V_319 : V_200 = V_404 ; break;
case V_321 : V_200 = V_405 ; break;
case V_323 : V_200 = V_406 ; break;
case V_325 : V_200 = V_407 ; break;
case V_327 : V_200 = V_408 ; break;
case V_409 : V_200 = V_410 ; break;
case V_411 : V_200 = V_412 ; break;
case V_413 : V_200 = V_414 ; break;
case V_415 : V_200 = V_416 ; break;
case V_417 : V_200 = V_418 ; break;
case V_419 : V_200 = V_420 ; break;
case V_421 : V_200 = V_422 ; break;
case V_423 : V_200 = V_424 ; break;
case V_425 : V_200 = V_426 ; break;
case V_427 : V_200 = V_428 ; break;
case V_429 : V_200 = V_430 ; break;
case V_431 : V_200 = V_432 ; break;
case V_433 : V_200 = V_434 ; break;
case V_435 : V_200 = V_436 ; break;
case V_437 : V_200 = V_438 ; break;
case V_439 : V_200 = V_440 ; break;
case ( 0x80 | 0x20 ) : V_200 = V_441 ; break;
default: break;
}
return V_200 ;
}
static T_1 F_112 ( T_1 V_222 , T_1 V_224 , T_4 * V_201 )
{
T_1 V_442 ;
V_442 = ( V_222 == 1 ) ? ( ( V_201 -> V_443 ) ? 1 : 0 ) : ( ( V_201 -> V_444 ) ? 1 : 0 ) ;
if ( V_222 == 1 && V_224 != V_440 )
V_442 = 0 ;
return V_442 ;
}
static void F_136 ( struct V_147 * V_281 )
{
return;
}
short F_102 ( struct V_35 * V_36 , struct V_149 * V_150 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_4 * V_201 = ( T_4 * ) ( V_150 -> V_158 + V_202 ) ;
T_9 * V_445 = ( T_9 * ) V_150 -> V_42 ;
T_6 * V_216 = ( T_6 * ) ( V_150 -> V_42 + V_207 ) ;
struct V_47 * V_48 = V_7 -> V_48 ;
int V_446 ;
int V_46 ;
struct V_147 * V_281 = NULL , * V_447 = NULL ;
unsigned int V_372 ;
V_446 = F_38 ( & V_7 -> V_82 [ V_201 -> V_111 ] ) ;
if ( V_446 > V_113 ) {
F_110 ( V_36 , L_58 ) ;
F_114 ( V_150 ) ;
return - 1 ;
}
V_281 = F_69 ( 0 , V_198 ) ;
if ( ! V_281 ) {
F_114 ( V_150 ) ;
return - V_374 ;
}
memset ( V_216 , 0 , sizeof( T_6 ) ) ;
V_216 -> V_222 = ( V_201 -> V_223 & 0x80 ) ? 1 : 0 ;
V_216 -> V_224 = F_111 ( V_201 -> V_223 ) ;
V_216 -> V_225 = V_201 -> V_205 ;
V_216 -> Short = F_112 ( V_216 -> V_222 , V_216 -> V_224 , V_201 ) ;
if ( V_201 -> V_226 ) {
V_216 -> V_227 = 1 ;
V_216 -> V_228 = V_201 -> V_229 ;
V_216 -> V_230 = V_201 -> V_231 & 0x07 ;
} else {
V_216 -> V_227 = 0 ;
V_216 -> V_228 = 0 ;
V_216 -> V_230 = 0 ;
}
V_216 -> V_232 = ( V_201 -> V_233 ) ? 1 : 0 ;
V_216 -> V_234 = ( V_201 -> V_235 ) ? 1 : 0 ;
V_216 -> V_236 = ( V_201 -> V_237 ) ? 1 : 0 ;
V_216 -> V_238 = ( V_201 -> V_239 & 0x80 ) ? 1 : 0 ;
V_216 -> V_240 = F_111 ( ( T_1 ) V_201 -> V_239 ) ;
V_216 -> V_241 = ( V_216 -> V_238 == 0 ) ? ( V_201 -> V_242 ) : 0 ;
V_216 -> V_243 = ( V_216 -> V_238 == 1 ) ? ( ( V_201 -> V_244 ) ? 1 : 0 ) : 0 ;
V_216 -> V_245 = ( V_216 -> V_238 == 0 ) ? ( V_201 -> V_246 ? 1 : 0 ) :
( V_201 -> V_247 ? 1 : 0 ) ;
if ( V_7 -> V_248 == V_249 ) {
if ( V_201 -> V_250 ) {
V_216 -> V_251 = 1 ;
V_216 -> V_252 = 0 ;
} else {
V_216 -> V_251 = 0 ;
V_216 -> V_252 = V_7 -> V_253 ;
}
} else {
V_216 -> V_251 = 0 ;
V_216 -> V_252 = 0 ;
}
#ifdef F_119
if ( V_201 -> V_219 )
V_216 -> V_448 = ( V_201 -> V_221 & 0x1f ) << 1 ;
#endif
memset ( V_445 , 0 , sizeof( T_9 ) ) ;
V_445 -> V_381 = 0 ;
V_445 -> V_377 = 1 ;
V_445 -> V_254 = sizeof( T_6 ) + 8 ;
#ifdef F_119
if ( V_201 -> V_219 )
V_445 -> V_255 = V_201 -> V_220 ;
else
#endif
{
V_445 -> V_255 = ( V_150 -> V_209 - V_449 ) & 0xffff ;
}
V_445 -> V_256 = 0 ;
V_445 -> V_257 = V_201 -> V_258 ;
V_445 -> V_259 = 1 ;
V_445 -> V_260 = 0x0 ;
if ( V_201 -> V_261 ) {
switch ( V_7 -> V_12 -> V_262 ) {
case V_263 :
case V_264 :
V_445 -> V_260 = 0x1 ;
V_445 -> V_259 = 0 ;
break;
case V_265 :
V_445 -> V_260 = 0x2 ;
V_445 -> V_259 = 0 ;
break;
case V_266 :
V_445 -> V_260 = 0x3 ;
V_445 -> V_259 = 0 ;
break;
case V_267 :
V_445 -> V_260 = 0x0 ;
V_445 -> V_259 = 1 ;
break;
}
}
V_445 -> V_268 = F_113 ( V_201 -> V_111 ) ;
V_445 -> V_269 = sizeof( T_6 ) ;
V_445 -> V_270 = V_201 -> V_271 ;
V_445 -> V_272 = V_201 -> V_273 ;
V_445 -> V_375 = 1 ;
V_445 -> V_376 = 1 ;
V_445 -> V_274 = 1 ;
#ifdef F_119
if ( V_201 -> V_219 ) {
V_445 -> V_379 = V_201 -> V_220 + sizeof( T_6 ) ;
} else
#endif
{
V_445 -> V_379 = ( T_2 ) ( V_150 -> V_209 - V_207 ) ;
}
#ifndef F_133
V_372 = F_130 ( V_7 , V_201 -> V_111 ) ;
#else
V_372 = 0x5 ;
#endif
F_71 ( V_281 , V_48 ,
F_134 ( V_48 , V_372 ) , V_150 -> V_42 ,
V_150 -> V_209 , F_117 , V_150 ) ;
V_46 = F_75 ( V_281 , V_198 ) ;
if ( ! V_46 ) {
bool V_450 = false ;
T_1 V_451 = 0 ;
if ( V_48 -> V_452 == V_453 ) {
if ( V_150 -> V_209 > 0 && V_150 -> V_209 % 512 == 0 )
V_450 = true ;
} else {
if ( V_150 -> V_209 > 0 && V_150 -> V_209 % 64 == 0 )
V_450 = true ;
}
if ( V_450 ) {
V_447 = F_69 ( 0 , V_198 ) ;
if ( ! V_447 ) {
F_9 ( V_27 , L_59 ) ;
return - V_374 ;
}
F_71 ( V_447 , V_48 ,
F_134 ( V_48 , V_372 ) , & V_451 ,
0 , F_136 , V_36 ) ;
V_46 = F_75 ( V_447 , V_198 ) ;
if ( V_46 ) {
F_9 ( V_27 , L_60 , F_38 ( & V_7 -> V_82 [ V_201 -> V_111 ] ) , V_46 ) ;
return - 1 ;
}
}
V_36 -> V_282 = V_283 ;
F_131 ( & V_7 -> V_82 [ V_201 -> V_111 ] ) ;
return 0 ;
} else {
F_9 ( V_27 , L_61 , F_38 ( & V_7 -> V_82 [ V_201 -> V_111 ] ) ,
V_46 ) ;
return - 1 ;
}
}
static short F_137 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
V_7 -> V_298 = F_138 ( sizeof( struct V_147 * ) * ( V_154 + 1 ) ,
V_156 ) ;
if ( V_7 -> V_298 == NULL )
return - V_374 ;
#ifndef F_139
for ( V_1 = 0 ; V_1 < ( V_154 + 1 ) ; V_1 ++ ) {
V_7 -> V_298 [ V_1 ] = F_69 ( 0 , V_156 ) ;
V_7 -> V_298 [ V_1 ] -> V_197 = F_138 ( V_155 , V_156 ) ;
V_7 -> V_298 [ V_1 ] -> V_454 = V_155 ;
}
#endif
#ifdef F_140
{
long V_455 = 0 ;
void * V_456 , * V_457 ;
V_7 -> V_298 [ 16 ] = F_69 ( 0 , V_156 ) ;
V_7 -> V_456 = F_138 ( 16 , V_156 ) ;
V_456 = V_7 -> V_456 ;
V_455 = ( ( long ) V_456 ) & 3 ;
if ( V_455 ) {
V_457 = V_456 + 4 - V_455 ;
V_7 -> V_298 [ 16 ] -> V_454 = 16 - 4 + V_455 ;
} else {
V_457 = V_456 ;
V_7 -> V_298 [ 16 ] -> V_454 = 16 ;
}
V_7 -> V_298 [ 16 ] -> V_197 = V_457 ;
}
#endif
memset ( V_7 -> V_298 , 0 , sizeof( struct V_147 * ) * V_154 ) ;
V_7 -> V_458 = F_141 ( V_154 , sizeof( struct V_149 * ) ,
V_156 ) ;
if ( ! V_7 -> V_458 ) {
F_142 ( V_7 -> V_298 ) ;
V_7 -> V_458 = NULL ;
V_7 -> V_298 = NULL ;
F_135 ( L_62 ) ;
return - V_374 ;
}
F_110 ( V_36 , L_63 ) ;
return 0 ;
}
static void F_143 ( struct V_35 * V_36 )
{
int V_1 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
if ( V_7 -> V_298 ) {
for ( V_1 = 0 ; V_1 < ( V_154 + 1 ) ; V_1 ++ ) {
F_82 ( V_7 -> V_298 [ V_1 ] ) ;
F_89 ( V_7 -> V_298 [ V_1 ] ) ;
}
F_142 ( V_7 -> V_298 ) ;
V_7 -> V_298 = NULL ;
}
F_142 ( V_7 -> V_456 ) ;
V_7 -> V_456 = NULL ;
if ( V_7 -> V_458 ) {
F_142 ( V_7 -> V_458 ) ;
V_7 -> V_458 = NULL ;
}
}
void F_143 ( struct V_35 * V_36 )
{
int V_1 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
#ifndef F_139
if ( V_7 -> V_298 ) {
for ( V_1 = 0 ; V_1 < ( V_154 + 1 ) ; V_1 ++ ) {
F_82 ( V_7 -> V_298 [ V_1 ] ) ;
F_142 ( V_7 -> V_298 [ V_1 ] -> V_197 ) ;
F_89 ( V_7 -> V_298 [ V_1 ] ) ;
}
F_142 ( V_7 -> V_298 ) ;
V_7 -> V_298 = NULL ;
}
#else
F_142 ( V_7 -> V_298 ) ;
V_7 -> V_298 = NULL ;
F_142 ( V_7 -> V_456 ) ;
V_7 -> V_456 = NULL ;
if ( V_7 -> V_458 ) {
F_142 ( V_7 -> V_458 ) ;
V_7 -> V_458 = 0 ;
}
#endif
}
void F_144 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
if ( V_11 -> V_126 == V_127 ) {
F_124 ( V_36 ) ;
F_145 ( V_36 ) ;
if ( ( V_263 == V_11 -> V_262 ) || ( V_264 == V_11 -> V_262 ) )
F_146 ( V_36 ) ;
}
if ( V_11 -> V_128 == V_129 || V_11 -> V_128 == V_132 ) {
T_2 V_459 = 0 ;
F_16 ( V_36 , V_161 , & V_459 ) ;
if ( V_7 -> V_12 -> V_126 == V_127 )
V_7 -> V_460 = V_459 |= V_172 ;
else
V_7 -> V_460 = V_459 &= ~ V_172 ;
F_13 ( V_36 , V_161 , V_459 ) ;
}
}
void F_147 ( struct V_461 * V_462 )
{
struct V_6 * V_7 = F_148 ( V_462 , struct V_6 , V_463 . V_462 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_58 * V_300 = & V_11 -> V_302 ;
if ( V_11 -> V_275 -> V_464 )
F_149 ( V_11 , V_300 ) ;
V_11 -> V_275 -> V_341 = V_300 -> V_465 . V_466 ;
F_123 ( V_36 , V_300 -> V_467 ) ;
}
void F_150 ( struct V_461 * V_462 )
{
struct V_6 * V_7 = F_148 ( V_462 , struct V_6 , V_468 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
struct V_469 * V_470 = & V_7 -> V_12 -> V_302 . V_471 . V_472 ;
T_1 V_116 = V_7 -> V_12 -> V_302 . V_116 ;
T_1 V_473 ;
T_2 V_474 ;
int V_1 ;
if ( V_7 == NULL )
return;
F_151 ( & V_7 -> V_475 ) ;
if ( V_7 -> V_12 -> V_126 != V_127 )
goto V_476;
F_9 ( V_477 , L_64 ) ;
for ( V_1 = 0 ; V_1 < V_478 ; V_1 ++ ) {
V_473 = V_470 -> V_479 [ V_1 ] * ( ( V_116 & ( V_337 | V_338 ) ) ? 9 : 20 ) + V_480 ;
V_474 = ( ( ( ( T_2 ) ( V_470 -> V_481 [ V_1 ] ) ) << V_482 ) |
( ( ( T_2 ) ( V_470 -> V_483 [ V_1 ] ) ) << V_484 ) |
( ( ( T_2 ) ( V_470 -> V_485 [ V_1 ] ) ) << V_486 ) |
( ( T_2 ) V_473 << V_487 ) ) ;
F_13 ( V_36 , V_488 [ V_1 ] , V_474 ) ;
}
V_476:
F_152 ( & V_7 -> V_475 ) ;
}
static int F_153 ( struct V_6 * V_7 ,
int V_489 ,
struct V_58 * V_490 )
{
int V_200 = 0 ;
T_2 V_491 = sizeof( struct V_469 ) ;
if ( V_7 -> V_12 -> V_126 != V_127 )
return V_200 ;
if ( ( V_7 -> V_12 -> V_128 != V_129 ) )
return V_200 ;
if ( V_490 -> V_167 & V_492 ) {
if ( V_489 &&
( V_490 -> V_167 & V_493 ) )
V_490 -> V_471 . V_494 = V_490 -> V_471 . V_495 ;
if ( ( V_490 -> V_471 . V_494 == 1 ) && ( V_489 == 1 ) &&
( V_490 -> V_167 & V_493 ) &&
( V_490 -> V_471 . V_496 !=
V_490 -> V_471 . V_497 ) ) {
V_490 -> V_471 . V_496 =
V_490 -> V_471 . V_497 ;
F_154 ( V_7 -> V_498 , & V_7 -> V_468 ) ;
F_9 ( V_477 , L_65
L_66 ) ;
}
} else {
memcpy ( & V_7 -> V_12 -> V_302 . V_471 . V_472 ,
& V_499 , V_491 ) ;
if ( ( V_490 -> V_471 . V_494 == 1 ) && ( V_489 == 1 ) ) {
F_154 ( V_7 -> V_498 , & V_7 -> V_468 ) ;
F_9 ( V_477 , L_67 ) ;
}
V_490 -> V_471 . V_494 = 0 ;
V_490 -> V_471 . V_495 = 0 ;
}
return 0 ;
}
static int F_155 ( struct V_35 * V_36 ,
struct V_500 * V_501 ,
struct V_58 * V_490 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
F_153 ( V_7 , 1 , V_490 ) ;
F_156 ( V_7 -> V_498 , & V_7 -> V_463 , 0 ) ;
return 0 ;
}
static int F_157 ( struct V_6 * V_7 ,
struct V_58 * V_490 )
{
int V_200 = 0 ;
unsigned long V_167 ;
T_2 V_491 = sizeof( struct V_469 ) ;
int V_502 = 0 ;
if ( ( V_7 == NULL ) || ( V_490 == NULL ) )
return V_200 ;
if ( V_7 -> V_12 -> V_126 != V_127 )
return V_200 ;
if ( ( V_7 -> V_12 -> V_128 != V_129 ) )
return V_200 ;
F_100 ( & V_7 -> V_12 -> V_503 , V_167 ) ;
if ( V_490 -> V_167 & V_493 ) {
memcpy ( & V_7 -> V_12 -> V_302 . V_471 . V_472 ,
& V_490 -> V_471 . V_472 ,
sizeof( struct V_469 ) ) ;
V_7 -> V_12 -> V_302 . V_471 . V_494 = 1 ;
V_502 = 1 ;
V_7 -> V_12 -> V_302 . V_471 . V_496 =
V_7 -> V_12 -> V_302 . V_471 . V_497 ;
V_7 -> V_12 -> V_302 . V_471 . V_497 =
V_490 -> V_471 . V_497 ;
} else {
memcpy ( & V_7 -> V_12 -> V_302 . V_471 . V_472 ,
& V_499 , V_491 ) ;
V_7 -> V_12 -> V_302 . V_471 . V_494 = 0 ;
V_7 -> V_12 -> V_302 . V_471 . V_495 = 0 ;
V_502 = 1 ;
}
F_103 ( & V_7 -> V_12 -> V_503 , V_167 ) ;
F_9 ( V_477 , L_68 , V_28 , V_490 -> V_167 , V_7 -> V_12 -> V_302 . V_471 . V_494 ) ;
if ( V_502 == 1 )
F_154 ( V_7 -> V_498 , & V_7 -> V_468 ) ;
return V_200 ;
}
static int F_158 ( struct V_35 * V_36 ,
struct V_504 * V_505 ,
struct V_58 * V_490 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
F_157 ( V_7 , V_490 ) ;
return 0 ;
}
void F_145 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
T_1 * V_506 = V_11 -> V_507 ;
T_2 V_508 = 0 ;
T_1 V_509 = 0 ;
F_122 ( V_36 , ( T_3 * ) ( & V_508 ) ) ;
V_508 |= ( * ( T_3 * ) ( V_506 ) ) << 12 ;
switch ( V_11 -> V_116 ) {
case V_510 :
V_508 &= 0x00000FF0 ;
break;
case V_511 :
V_508 &= 0x0000000F ;
break;
case V_337 :
V_508 &= 0x00000FF7 ;
break;
case V_338 :
case V_512 :
if ( V_11 -> V_275 -> V_513 == 0 ) {
V_508 &= 0x0007F007 ;
} else {
if ( V_7 -> V_514 == V_515 )
V_508 &= 0x000FF007 ;
else
V_508 &= 0x0F81F007 ;
}
break;
default:
break;
}
V_508 &= 0x0FFFFFFF ;
if ( V_11 -> V_275 -> V_516 && V_11 -> V_275 -> V_517 )
V_508 |= 0x80000000 ;
else if ( ! V_11 -> V_275 -> V_516 && V_11 -> V_275 -> V_518 )
V_508 |= 0x80000000 ;
F_13 ( V_36 , V_519 + V_509 * 4 , V_508 ) ;
F_24 ( V_36 , V_520 , 1 ) ;
}
static bool F_159 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_58 * V_490 = & V_11 -> V_302 ;
int V_61 = V_11 -> V_61 ;
struct V_521 * V_522 ;
int V_523 ;
V_522 = V_11 -> V_522 [ V_11 -> V_524 ] ;
V_523 = ( V_490 -> V_467 & V_525 ) || ( V_11 -> V_526 && V_522 && V_522 -> V_527 && ( 0 == strcmp ( V_522 -> V_527 -> V_106 , L_69 ) ) ) ;
if ( V_523 && ( V_61 == 0 ) ) {
return false ;
} else if ( ( V_61 != 0 ) ) {
if ( ( ( V_11 -> V_528 [ 0 ] == 0xdd ) && ( ! memcmp ( & ( V_11 -> V_528 [ 14 ] ) , V_529 , 4 ) ) ) || ( ( V_11 -> V_528 [ 0 ] == 0x30 ) && ( ! memcmp ( & V_11 -> V_528 [ 10 ] , V_530 , 4 ) ) ) )
return true ;
else
return false ;
} else {
return true ;
}
return true ;
}
bool F_160 ( struct V_35 * V_36 )
{
bool V_531 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
if ( V_11 -> V_532 == true )
V_531 = true ;
else
V_531 = false ;
return V_531 ;
}
void F_161 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
if ( V_11 -> V_116 == V_533 || V_11 -> V_116 == V_534 )
memcpy ( V_11 -> V_535 , V_11 -> V_536 , 16 ) ;
else
memset ( V_11 -> V_535 , 0 , 16 ) ;
return;
}
T_1 F_162 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 V_200 = 0 ;
switch ( V_7 -> V_24 ) {
case V_25 :
case V_26 :
case V_537 :
V_200 = ( V_533 | V_538 | V_539 ) ;
break;
case V_540 :
V_200 = ( V_541 | V_534 ) ;
break;
default:
V_200 = V_539 ;
break;
}
return V_200 ;
}
void F_163 ( struct V_35 * V_36 , T_1 V_542 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 V_543 = F_162 ( V_36 ) ;
if ( ( V_542 == V_544 ) || ( ( V_542 & V_543 ) == 0 ) ) {
if ( V_543 & V_533 ) {
V_542 = V_533 ;
} else if ( V_543 & V_534 ) {
V_542 = V_534 ;
} else if ( ( V_543 & V_541 ) ) {
V_542 = V_541 ;
} else if ( ( V_543 & V_538 ) ) {
V_542 = V_538 ;
} else if ( ( V_543 & V_539 ) ) {
V_542 = V_539 ;
} else {
F_9 ( V_27 , L_70 , V_28 , V_543 ) ;
V_542 = V_539 ;
}
}
#ifdef F_164
F_165 ( V_545 , V_546 -> V_547 , & V_545 -> V_548 . V_549 . V_550 ) ;
#endif
V_7 -> V_12 -> V_116 = V_542 ;
if ( ( V_542 == V_533 ) || ( V_542 == V_534 ) )
V_7 -> V_12 -> V_275 -> V_551 = 1 ;
else
V_7 -> V_12 -> V_275 -> V_551 = 0 ;
F_9 ( V_95 , L_71 , V_542 ) ;
F_161 ( V_7 ) ;
}
static void F_166 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 V_1 ;
V_7 -> V_297 = V_296 ;
V_7 -> V_139 = 1 ;
V_7 -> V_12 -> V_116 = V_544 ;
V_7 -> V_12 -> V_128 = V_129 ;
V_7 -> V_12 -> V_552 = 0 ;
V_7 -> V_553 = V_554 ;
V_7 -> V_555 = V_556 ;
V_7 -> V_12 -> V_557 = V_558 ;
V_7 -> V_12 -> V_189 = 110 ;
V_7 -> V_12 -> V_559 = 1 ;
V_7 -> V_560 = ( V_36 -> V_167 & V_168 ) ? 1 : 0 ;
V_7 -> V_561 = 6 ;
V_7 -> V_562 = 1 ;
V_7 -> V_563 = V_564 ;
V_7 -> V_565 = 0 ;
V_7 -> V_566 = false ;
V_7 -> V_567 = false ;
V_7 -> V_12 -> V_568 = 0 ;
V_7 -> V_12 -> V_302 . V_353 = V_569 ;
V_7 -> V_12 -> V_128 = V_129 ;
V_7 -> V_12 -> V_570 = V_571 |
V_572 | V_573 |
V_574 | V_575 |
V_576 ;
V_7 -> V_12 -> V_577 = 1 ;
V_7 -> V_12 -> V_578 = V_579 | V_580 ;
V_7 -> V_12 -> V_526 = 1 ;
V_7 -> V_12 -> V_581 = 1 ;
V_7 -> V_12 -> V_582 = NULL ;
V_7 -> V_12 -> V_583 = NULL ;
V_7 -> V_12 -> V_292 = F_104 ;
V_7 -> V_12 -> V_584 = F_61 ;
V_7 -> V_12 -> V_585 = F_144 ;
V_7 -> V_12 -> V_586 = F_98 ;
V_7 -> V_12 -> V_587 = F_96 ;
V_7 -> V_12 -> V_588 = F_97 ;
V_7 -> V_12 -> V_589 = 0 ;
V_7 -> V_12 -> V_590 = V_591 ;
V_7 -> V_12 -> F_54 = F_54 ;
V_7 -> V_12 -> V_206 = V_449 ;
V_7 -> V_12 -> V_592 = 1 ;
V_7 -> V_12 -> V_593 = V_594 ;
V_7 -> V_12 -> V_595 = F_158 ;
V_7 -> V_12 -> V_596 = F_155 ;
V_7 -> V_12 -> V_597 = F_159 ;
V_7 -> V_12 -> V_598 = F_160 ;
V_7 -> V_12 -> V_599 = F_163 ;
V_7 -> V_12 -> V_600 = V_601 ;
V_7 -> V_602 = V_603 ;
#ifdef F_164
if ( V_604 -> V_605 ) {
V_546 -> V_606 = 7 ;
V_546 -> V_607 = 7 ;
}
#endif
V_7 -> V_606 = 0x30 ;
V_7 -> V_607 = 0x30 ;
V_7 -> V_608 = 7 ;
V_7 -> V_609 = 0 ;
V_7 -> V_610 =
( V_611 << V_612 ) |
( V_7 -> V_606 << V_613 ) |
( V_7 -> V_607 << V_614 ) |
( false ? V_615 : 0 ) ;
#ifdef F_164
if ( V_604 -> V_605 )
V_546 -> V_460 = V_546 -> V_616 |
V_163 | V_164 |
V_617 |
V_165 | V_166 | V_171 |
V_173 | V_176 |
( ( T_2 ) 7 << V_181 ) |
( V_546 -> V_608 << V_618 ) |
( V_546 -> V_608 == 7 ? V_619 : 0 ) ;
else
#endif
V_7 -> V_460 =
V_163 | V_164 |
V_617 |
V_165 | V_166 | V_171 |
( ( T_2 ) 7 << V_181 ) |
( V_7 -> V_608 << V_179 ) |
( V_7 -> V_608 == 7 ? V_182 : 0 ) ;
V_7 -> V_620 = 0 ;
V_7 -> V_621 = F_167 ( sizeof( V_622 ) , V_156 ) ;
F_168 ( & V_7 -> V_153 ) ;
F_168 ( & V_7 -> V_187 ) ;
for ( V_1 = 0 ; V_1 < V_623 ; V_1 ++ )
F_168 ( & V_7 -> V_12 -> V_290 [ V_1 ] ) ;
for ( V_1 = 0 ; V_1 < V_623 ; V_1 ++ )
F_168 ( & V_7 -> V_12 -> V_624 [ V_1 ] ) ;
for ( V_1 = 0 ; V_1 < V_623 ; V_1 ++ )
F_168 ( & V_7 -> V_12 -> V_279 [ V_1 ] ) ;
V_7 -> V_140 = V_625 ;
}
static void F_169 ( struct V_6 * V_7 )
{
F_170 ( & V_7 -> V_204 ) ;
F_170 ( & V_7 -> V_626 ) ;
F_171 ( & V_7 -> V_627 , 1 ) ;
F_171 ( & V_7 -> V_628 , 1 ) ;
F_172 ( & V_7 -> V_475 ) ;
}
static void F_173 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
V_7 -> V_498 = F_174 ( V_629 ) ;
F_175 ( & V_7 -> V_114 , V_630 ) ;
F_176 ( & V_7 -> V_631 , V_632 ) ;
F_176 ( & V_7 -> V_633 , V_634 ) ;
F_176 ( & V_7 -> V_635 , V_636 ) ;
F_176 ( & V_7 -> V_463 , F_147 ) ;
F_176 ( & V_7 -> V_637 , V_638 ) ;
F_175 ( & V_7 -> V_468 , F_150 ) ;
F_177 ( & V_7 -> V_196 ,
( void (*) ( unsigned long ) ) V_639 ,
( unsigned long ) V_7 ) ;
}
static void F_178 ( struct V_35 * V_36 )
{
T_3 V_640 = 0 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
F_9 ( V_115 , L_72 , V_28 ) ;
F_28 ( V_36 , V_118 , & V_640 ) ;
F_9 ( V_115 , L_73 , V_118 , V_640 ) ;
V_7 -> V_641 = ( V_640 & V_642 ) ? V_643 : V_644 ;
F_9 ( V_115 , L_74 , V_28 , V_7 -> V_641 ) ;
}
static inline T_3 F_179 ( T_3 * V_42 )
{
T_3 V_332 = * V_42 ;
* V_42 = ( V_332 >> 8 ) | ( V_332 << 8 ) ;
return * V_42 ;
}
static void F_180 ( struct V_35 * V_36 )
{
T_3 V_645 = 0 ;
T_1 V_646 [ 6 ] = { 0x00 , 0xe0 , 0x4c , 0x00 , 0x00 , 0x02 } ;
T_1 V_647 = false ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_3 V_648 = 0 ;
int V_1 ;
F_9 ( V_115 , L_72 , V_28 ) ;
V_645 = F_58 ( V_36 , 0 ) ;
F_9 ( V_115 , L_75 , V_645 ) ;
if ( V_645 != V_649 ) {
F_9 ( V_27 , L_76 , V_645 , V_649 ) ;
} else {
V_647 = true ;
}
if ( V_647 ) {
V_648 = F_58 ( V_36 , ( V_650 >> 1 ) ) ;
V_7 -> V_651 = F_179 ( & V_648 ) ;
V_7 -> V_652 = F_58 ( V_36 , ( V_653 >> 1 ) ) ;
V_648 = F_58 ( V_36 , ( V_654 >> 1 ) ) ;
V_7 -> V_655 = ( ( V_648 & 0xff00 ) >> 8 ) ;
V_7 -> V_656 = true ;
V_7 -> V_657 = F_58 ( V_36 , ( V_658 >> 1 ) ) >> 8 ;
} else {
V_7 -> V_651 = 0 ;
V_7 -> V_652 = 0 ;
V_7 -> V_659 = V_660 ;
V_7 -> V_655 = 0 ;
V_7 -> V_657 = 0 ;
}
F_9 ( V_115 , L_77 , V_7 -> V_651 , V_7 -> V_652 , V_7 -> V_657 , V_7 -> V_655 ) ;
V_7 -> V_29 = V_7 -> V_655 ;
if ( V_647 ) {
int V_1 ;
for ( V_1 = 0 ; V_1 < 6 ; V_1 += 2 ) {
T_3 V_332 = 0 ;
V_332 = F_58 ( V_36 , ( T_3 ) ( ( V_661 + V_1 ) >> 1 ) ) ;
* ( T_3 * ) ( & V_36 -> V_662 [ V_1 ] ) = V_332 ;
}
} else {
memcpy ( V_36 -> V_662 , V_646 , 6 ) ;
}
F_9 ( V_115 , L_78 , V_36 -> V_662 ) ;
V_7 -> V_514 = V_663 ;
V_7 -> V_24 = V_26 ;
if ( V_7 -> V_659 == ( T_1 ) V_664 ) {
if ( V_647 )
V_7 -> V_665 = ( F_58 ( V_36 , ( V_666 >> 1 ) ) & 0xff00 ) >> 8 ;
else
V_7 -> V_665 = V_667 ;
F_9 ( V_115 , L_79 , V_7 -> V_665 ) ;
if ( V_647 )
V_7 -> V_668 = ( T_1 ) ( F_58 ( V_36 , ( V_669 >> 1 ) ) & 0x00ff ) ;
else
V_7 -> V_668 = V_670 ;
F_9 ( V_115 , L_80 , V_7 -> V_668 ) ;
V_7 -> V_671 = V_7 -> V_668 * 100 ;
if ( V_647 )
V_7 -> V_672 = ( F_58 ( V_36 , ( V_673 >> 1 ) ) & 0x0f00 ) >> 8 ;
else
V_7 -> V_672 = V_674 ;
F_9 ( V_115 , L_81 , V_7 -> V_672 ) ;
if ( V_647 )
V_7 -> V_675 = ( F_58 ( V_36 , ( V_676 >> 1 ) ) & 0x0f ) ;
else
V_7 -> V_675 = V_677 ;
F_9 ( V_115 , L_82 , V_7 -> V_675 ) ;
if ( V_647 )
V_7 -> V_678 = ( F_58 ( V_36 , ( V_679 >> 1 ) ) & 0xff00 ) >> 8 ;
else
V_7 -> V_678 = 1 ;
F_9 ( V_115 , L_83 , V_7 -> V_678 ) ;
if ( V_7 -> V_678 == 0 ) {
int V_1 ;
if ( V_647 )
V_7 -> V_680 = ( F_58 ( V_36 , ( V_681 >> 1 ) ) & 0xff ) >> 8 ;
else
V_7 -> V_680 = 0x10 ;
F_9 ( V_115 , L_84 , V_7 -> V_680 ) ;
for ( V_1 = 0 ; V_1 < 3 ; V_1 ++ ) {
if ( V_647 ) {
V_648 = F_58 ( V_36 , ( V_682 + V_1 ) >> 1 ) ;
if ( ( ( V_682 + V_1 ) % 2 ) == 0 )
V_648 = V_648 & 0x00ff ;
else
V_648 = ( V_648 & 0xff00 ) >> 8 ;
} else {
V_648 = 0x10 ;
}
V_7 -> V_683 [ V_1 ] = ( T_1 ) V_648 ;
F_9 ( V_115 , L_85 , V_1 , V_7 -> V_680 ) ;
}
} else if ( V_7 -> V_678 == 1 ) {
if ( V_647 ) {
V_648 = F_58 ( V_36 , ( V_684 >> 1 ) ) ;
V_648 = ( V_648 & 0xff00 ) >> 8 ;
} else {
V_648 = 0x10 ;
}
V_7 -> V_685 [ 0 ] = ( T_1 ) V_648 ;
if ( V_647 )
V_648 = F_58 ( V_36 , ( V_684 + 2 ) >> 1 ) ;
else
V_648 = 0x1010 ;
* ( ( T_3 * ) ( & V_7 -> V_685 [ 1 ] ) ) = V_648 ;
if ( V_647 )
V_648 = F_58 ( V_36 , ( V_686 >> 1 ) ) ;
else
V_648 = 0x1010 ;
* ( ( T_3 * ) ( & V_7 -> V_683 [ 0 ] ) ) = V_648 ;
if ( V_647 )
V_648 = F_58 ( V_36 , ( V_686 + 2 ) >> 1 ) ;
else
V_648 = 0x10 ;
V_7 -> V_683 [ 2 ] = ( T_1 ) V_648 ;
}
for ( V_1 = 0 ; V_1 < 14 ; V_1 ++ ) {
if ( V_1 <= 3 )
V_7 -> V_687 [ V_1 ] = V_7 -> V_683 [ 0 ] ;
else if ( V_1 >= 4 && V_1 <= 9 )
V_7 -> V_687 [ V_1 ] = V_7 -> V_683 [ 1 ] ;
else
V_7 -> V_687 [ V_1 ] = V_7 -> V_683 [ 2 ] ;
}
for ( V_1 = 0 ; V_1 < 14 ; V_1 ++ ) {
if ( V_7 -> V_678 == 0 ) {
if ( V_1 <= 3 )
V_7 -> V_688 [ V_1 ] = V_7 -> V_683 [ 0 ] + ( V_7 -> V_680 - V_7 -> V_683 [ 1 ] ) ;
else if ( V_1 >= 4 && V_1 <= 9 )
V_7 -> V_688 [ V_1 ] = V_7 -> V_680 ;
else
V_7 -> V_688 [ V_1 ] = V_7 -> V_683 [ 2 ] + ( V_7 -> V_680 - V_7 -> V_683 [ 1 ] ) ;
} else if ( V_7 -> V_678 == 1 ) {
if ( V_1 <= 3 )
V_7 -> V_688 [ V_1 ] = V_7 -> V_685 [ 0 ] ;
else if ( V_1 >= 4 && V_1 <= 9 )
V_7 -> V_688 [ V_1 ] = V_7 -> V_685 [ 1 ] ;
else
V_7 -> V_688 [ V_1 ] = V_7 -> V_685 [ 2 ] ;
}
}
V_7 -> V_689 = V_7 -> V_672 ;
V_7 -> V_690 [ 0 ] = ( V_7 -> V_665 & 0xf ) ;
V_7 -> V_690 [ 1 ] = ( ( V_7 -> V_665 & 0xf0 ) >> 4 ) ;
V_7 -> V_691 = V_7 -> V_675 ;
V_7 -> V_692 [ 0 ] = V_7 -> V_668 ;
}
switch ( V_7 -> V_657 ) {
case V_693 :
V_7 -> V_694 = V_695 ;
break;
case V_696 :
V_7 -> V_694 = V_697 ;
break;
default:
V_7 -> V_694 = V_698 ;
break;
}
switch ( V_7 -> V_694 ) {
case V_695 :
V_7 -> V_699 = V_700 ;
break;
case V_697 :
V_7 -> V_699 = V_701 ;
break;
default:
V_7 -> V_699 = V_702 ;
break;
}
if ( V_7 -> V_514 == V_515 ) {
F_9 ( V_115 , L_86 ) ;
} else {
F_9 ( V_115 , L_87 ) ;
}
F_181 ( V_36 ) ;
F_9 ( V_115 , L_88 , V_28 ) ;
return;
}
short F_182 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
if ( V_7 -> V_29 > V_33 ) {
F_21 ( V_36 , L_89 ) ;
V_7 -> V_29 = 0 ;
}
F_9 ( V_95 , L_90 , V_7 -> V_29 ) ;
F_7 ( V_7 -> V_29 , V_7 ) ;
return 0 ;
}
short F_183 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
memset ( & ( V_7 -> V_67 ) , 0 , sizeof( struct V_703 ) ) ;
memset ( V_7 -> V_371 , 0 , 9 ) ;
#ifdef F_184
{
int V_1 = 0 ;
T_1 V_704 [] = { 3 , 2 , 1 , 0 , 4 , 8 , 7 , 6 , 5 } ;
memcpy ( V_7 -> V_371 , V_704 , 9 ) ;
}
#else
{
T_1 V_704 [] = { 3 , 2 , 1 , 0 , 4 , 4 , 0 , 4 , 4 } ;
memcpy ( V_7 -> V_371 , V_704 , 9 ) ;
}
#endif
F_166 ( V_36 ) ;
F_169 ( V_7 ) ;
F_173 ( V_36 ) ;
F_178 ( V_36 ) ;
F_180 ( V_36 ) ;
F_182 ( V_36 ) ;
F_185 ( V_36 ) ;
F_186 ( & V_7 -> V_705 ) ;
V_7 -> V_705 . V_42 = ( unsigned long ) V_36 ;
V_7 -> V_705 . V_706 = V_707 ;
if ( F_137 ( V_36 ) != 0 ) {
F_77 ( L_91 ) ;
return - V_374 ;
}
#ifdef F_187
F_57 ( V_36 ) ;
#endif
return 0 ;
}
void F_188 ( struct V_35 * V_36 )
{
T_2 V_708 = 0 , V_709 = 0 ;
T_1 V_710 = 0 , V_711 = 0 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_2 V_508 = 0 ;
switch ( V_7 -> V_12 -> V_116 ) {
case V_539 :
V_710 = V_712 ;
V_708 = V_713 ;
V_709 = V_713 ;
break;
case V_541 :
V_710 = V_714 | V_712 ;
V_708 = V_715 ;
V_709 = V_715 ;
break;
case V_538 :
V_710 = V_712 ;
V_708 = V_713 | V_715 ;
V_709 = V_713 | V_715 ;
break;
case V_544 :
#ifdef F_164
if ( V_604 -> V_605 ) {
V_710 = V_712 ;
V_708 = V_713 | V_715 ;
V_709 = V_713 | V_715 ;
}
else
#endif
{
V_710 = V_712 ;
V_708 = V_713 | V_715 | V_716 | V_717 ;
V_709 = V_713 | V_715 ;
}
break;
case V_533 :
V_710 = V_712 ;
V_708 = V_713 | V_715 | V_716 | V_717 ;
V_709 = V_713 | V_715 ;
break;
case V_534 :
V_710 = V_714 ;
V_708 = V_715 | V_716 | V_717 ;
V_709 = V_715 ;
break;
}
F_24 ( V_36 , V_718 , V_710 ) ;
V_508 = V_708 ;
if ( V_7 -> V_514 == V_515 )
V_508 &= ~ ( V_717 ) ;
F_13 ( V_36 , V_519 , V_508 ) ;
F_24 ( V_36 , V_520 , 1 ) ;
F_26 ( V_36 , 0x313 , & V_711 ) ;
V_709 = ( ( V_711 ) << 24 ) | ( V_709 & 0x00ffffff ) ;
F_13 ( V_36 , V_336 , V_709 ) ;
F_25 ( V_36 , V_719 ,
V_7 -> V_606 << V_720 |
V_7 -> V_607 << V_721 ) ;
}
bool F_189 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_2 V_722 = 0 ;
bool V_723 = true ;
T_1 V_724 = 0x0 ;
T_1 V_332 ;
F_9 ( V_95 , L_92 , V_28 ) ;
V_7 -> V_725 = V_726 ;
F_17 ( V_36 , 0x5f , 0x80 ) ;
F_63 ( 50 ) ;
F_17 ( V_36 , 0x5f , 0xf0 ) ;
F_17 ( V_36 , 0x5d , 0x00 ) ;
F_17 ( V_36 , 0x5e , 0x80 ) ;
F_24 ( V_36 , 0x17 , 0x37 ) ;
F_63 ( 10 ) ;
V_7 -> V_621 -> V_727 = V_728 ;
F_16 ( V_36 , V_729 , & V_722 ) ;
if ( V_7 -> V_621 -> V_727 == V_728 )
V_722 |= V_730 ;
else if ( V_7 -> V_621 -> V_727 == V_731 )
V_722 |= V_732 ;
else
F_9 ( V_27 , L_93 , V_28 , V_7 -> V_621 -> V_727 ) ;
F_13 ( V_36 , V_729 , V_722 ) ;
F_190 ( V_36 ) ;
V_7 -> V_733 = V_734 ;
F_16 ( V_36 , V_729 , & V_722 ) ;
if ( V_7 -> V_733 == V_734 )
V_722 = ( ( V_722 & V_735 ) | V_736 ) ;
else if ( V_7 -> V_733 == V_737 )
V_722 |= V_738 ;
else
F_9 ( V_27 , L_94 , V_28 , V_7 -> V_733 ) ;
F_13 ( V_36 , V_729 , V_722 ) ;
F_191 ( 500 ) ;
F_22 ( V_36 , 0x5f , & V_332 ) ;
F_17 ( V_36 , 0x5f , V_332 | 0x20 ) ;
F_188 ( V_36 ) ;
F_24 ( V_36 , V_184 , V_186 | V_185 ) ;
F_13 ( V_36 , V_739 , ( ( T_2 * ) V_36 -> V_662 ) [ 0 ] ) ;
F_25 ( V_36 , V_740 , ( ( T_3 * ) ( V_36 -> V_662 + 4 ) ) [ 0 ] ) ;
F_13 ( V_36 , V_161 , V_7 -> V_460 ) ;
F_13 ( V_36 , V_741 , V_742 << V_743 |
V_744 << V_745 |
V_746 << V_747 |
V_748 << V_749 ) ;
F_13 ( V_36 , V_750 , V_751 << V_752 |
V_753 << V_754 ) ;
F_13 ( V_36 , V_755 , V_756 |
V_757 << V_758 ) ;
F_13 ( V_36 , V_519 + 4 * 7 , ( V_715 | V_713 ) ) ;
F_24 ( V_36 , V_759 , 0x30 ) ;
if ( V_7 -> V_563 == V_564 )
F_163 ( V_36 , V_7 -> V_12 -> V_116 ) ;
if ( V_7 -> V_563 == V_564 ) {
F_12 ( V_36 ) ;
V_724 |= V_760 ;
V_724 |= V_761 ;
V_724 |= V_762 ;
F_24 ( V_36 , V_763 , V_724 ) ;
}
F_25 ( V_36 , V_350 , 2 ) ;
F_25 ( V_36 , V_352 , 100 ) ;
#define F_192 0x005e4332
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_478 ; V_1 ++ )
F_13 ( V_36 , V_488 [ V_1 ] , F_192 ) ;
}
#ifdef F_65
if ( V_7 -> V_563 == V_564 ) {
T_2 V_764 ;
T_7 V_275 = V_7 -> V_12 -> V_275 ;
V_764 = ( V_275 -> V_765 << 24 ) | ( V_275 -> V_766 << 16 ) |
( V_275 -> V_767 << 8 ) | ( V_275 -> V_768 ) ;
F_13 ( V_36 , 0x1a8 , V_764 ) ;
V_7 -> V_769 = true ;
}
#endif
F_193 ( V_36 ) ;
if ( V_7 -> V_659 == ( T_1 ) V_664 ) {
F_194 ( V_36 ) ;
F_195 ( V_36 , V_7 -> V_139 ) ;
}
V_723 = F_196 ( V_36 ) ;
if ( ! V_723 ) {
F_9 ( V_27 , L_95 , V_28 ) ;
return V_723 ;
}
F_9 ( V_95 , L_96 , V_28 ) ;
#ifdef F_164
if ( V_604 -> V_563 == V_564 ) {
if ( V_770 -> V_771 == TRUE ) {
F_9 ( ( V_95 | V_772 ) , V_773 , ( L_97 ) ) ;
F_197 ( V_604 , V_774 , V_775 ) ;
for ( V_776 = 0 ; V_776 < V_546 -> V_777 ; V_776 ++ )
F_198 ( V_604 , ( V_778 ) V_776 , 0x4 , 0xC00 , 0x0 ) ;
} else if ( V_770 -> V_779 > V_780 ) {
F_9 ( ( V_95 | V_772 ) , V_773 , ( L_98 , V_770 -> V_779 ) ) ;
F_197 ( V_604 , V_774 , V_770 -> V_779 ) ;
} else {
V_546 -> V_781 = V_782 ;
V_770 -> V_779 = 0 ;
F_9 ( ( V_95 | V_772 ) , V_773 , ( L_99 ) ) ;
}
} else {
if ( V_546 -> V_781 == V_774 ) {
F_197 ( V_604 , V_774 , V_770 -> V_779 ) ;
for ( V_776 = 0 ; V_776 < V_546 -> V_777 ; V_776 ++ )
F_198 ( V_604 , ( V_778 ) V_776 , 0x4 , 0xC00 , 0x0 ) ;
}
}
#endif
if ( V_7 -> V_563 == V_564 ) {
F_199 ( V_36 ) ;
F_9 ( V_95 , L_100 , V_28 ) ;
}
if ( V_7 -> V_12 -> V_568 )
V_7 -> V_725 = V_783 ;
else
V_7 -> V_725 = V_726 ;
F_200 ( V_36 ) ;
F_201 ( V_36 , V_784 , V_785 , 0x1 ) ;
F_201 ( V_36 , V_784 , V_786 , 0x1 ) ;
if ( V_7 -> V_563 == V_564 ) {
T_1 V_787 ;
F_26 ( V_36 , 0x301 , & V_787 ) ;
if ( V_787 == 0x03 ) {
V_7 -> V_788 = TRUE ;
F_9 ( V_789 , L_101 ) ;
} else {
V_7 -> V_788 = FALSE ;
F_9 ( V_789 , L_102 ) ;
}
F_202 ( V_36 ) ;
if ( V_7 -> V_788 == TRUE ) {
T_2 V_1 , V_790 ;
T_2 V_791 = F_203 ( V_36 , V_792 , V_793 ) ;
for ( V_1 = 0 ; V_1 < V_794 ; V_1 ++ ) {
if ( V_791 == V_7 -> V_795 [ V_1 ] . V_796 ) {
V_7 -> V_797 = ( T_1 ) V_1 ;
V_7 -> V_798 = ( T_1 ) V_1 ;
V_7 -> V_799 = V_7 -> V_797 ;
break;
}
}
V_790 = F_203 ( V_36 , V_800 , V_801 ) ;
for ( V_1 = 0 ; V_1 < V_802 ; V_1 ++ ) {
if ( V_790 == V_7 -> V_803 [ V_1 ] . V_804 [ 0 ] ) {
V_7 -> V_805 = ( T_1 ) V_1 ;
break;
}
}
V_7 -> V_806 = 0 ;
V_7 -> V_807 = 0 ;
V_7 -> V_808 = V_7 -> V_805 ;
}
}
F_24 ( V_36 , 0x87 , 0x0 ) ;
return V_723 ;
}
static struct V_809 * F_204 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
return & V_7 -> V_12 -> V_67 ;
}
static bool F_205 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_3 V_810 ;
bool V_811 = FALSE ;
F_27 ( V_36 , 0x128 , & V_810 ) ;
F_9 ( V_812 , L_103 , V_28 , V_810 , V_7 -> V_813 ) ;
if ( V_7 -> V_813 == V_810 )
V_811 = TRUE ;
V_7 -> V_813 = V_810 ;
return V_811 ;
}
T_10 F_206 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 V_278 ;
bool V_814 = false ;
for ( V_278 = 0 ; V_278 <= V_289 ; V_278 ++ ) {
if ( V_278 == V_203 )
continue;
#ifdef F_119
if ( ( F_67 ( & V_7 -> V_12 -> V_290 [ V_278 ] ) == 0 ) && ( F_67 ( & V_7 -> V_12 -> V_624 [ V_278 ] ) == 0 ) && ( F_67 ( & V_7 -> V_12 -> V_279 [ V_278 ] ) == 0 ) )
#else
if ( ( F_67 ( & V_7 -> V_12 -> V_290 [ V_278 ] ) == 0 ) && ( F_67 ( & V_7 -> V_12 -> V_624 [ V_278 ] ) == 0 ) )
#endif
continue;
V_814 = true ;
}
if ( V_814 ) {
if ( F_205 ( V_36 ) ) {
F_9 ( V_812 , L_104 ) ;
return V_815 ;
}
}
return V_564 ;
}
static bool F_207 ( struct V_35 * V_36 )
{
T_3 V_816 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
bool V_811 = FALSE ;
static T_1 V_817 ;
F_27 ( V_36 , 0x130 , & V_816 ) ;
F_9 ( V_812 , L_105 , V_28 , V_816 , V_7 -> V_818 ) ;
V_817 ++ ;
if ( V_7 -> V_819 >= ( V_820 + 5 ) ) {
V_817 = 0 ;
} else if ( V_7 -> V_819 < ( V_820 + 5 ) &&
( ( V_7 -> V_248 != V_821 && V_7 -> V_819 >= V_822 ) ||
( V_7 -> V_248 == V_821 && V_7 -> V_819 >= V_823 ) ) ) {
if ( V_817 < 2 )
return V_811 ;
else
V_817 = 0 ;
} else if ( ( ( V_7 -> V_248 != V_821 && V_7 -> V_819 < V_822 ) ||
( V_7 -> V_248 == V_821 && V_7 -> V_819 < V_823 ) ) &&
V_7 -> V_819 >= V_824 ) {
if ( V_817 < 4 )
return V_811 ;
else
V_817 = 0 ;
} else {
if ( V_817 < 8 )
return V_811 ;
else
V_817 = 0 ;
}
if ( V_7 -> V_818 == V_816 )
V_811 = TRUE ;
V_7 -> V_818 = V_816 ;
return V_811 ;
}
static T_10 F_208 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
bool V_825 = FALSE ;
if ( V_7 -> V_562 > 1 )
V_825 = TRUE ;
if ( V_825 ) {
if ( F_207 ( V_36 ) ) {
F_9 ( V_812 , L_106 ) ;
return V_815 ;
}
}
return V_564 ;
}
T_10 F_209 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_10 V_826 = V_564 ;
T_10 V_827 = V_564 ;
T_11 V_828 ;
V_828 = V_7 -> V_12 -> V_781 ;
V_826 = F_206 ( V_36 ) ;
if ( V_828 != V_774 ||
( V_7 -> V_12 -> V_128 != V_132 ) ) {
V_827 = F_208 ( V_36 ) ;
}
if ( V_826 == V_829 || V_827 == V_829 ) {
return V_829 ;
} else if ( V_826 == V_815 || V_827 == V_815 ) {
F_9 ( V_812 , L_107 , V_28 ) ;
return V_815 ;
} else {
return V_564 ;
}
}
void F_210 ( struct V_35 * V_36 )
{
T_1 V_830 = 0 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 * V_831 = V_7 -> V_12 -> V_302 . V_349 ;
static T_1 V_832 [ 4 ] [ 6 ] = {
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x02 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x03 } } ;
static T_1 V_833 [] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
F_9 ( V_834 , L_108 ) ;
if ( ( V_7 -> V_12 -> V_262 == V_263 ) ||
( V_7 -> V_12 -> V_262 == V_264 ) ) {
for ( V_830 = 0 ; V_830 < 4 ; V_830 ++ ) {
V_831 = V_832 [ V_830 ] ;
F_211 ( V_36 , V_830 , V_830 ,
V_7 -> V_12 -> V_262 ,
V_831 , 0 , NULL ) ;
}
} else if ( V_7 -> V_12 -> V_262 == V_265 ) {
if ( V_7 -> V_12 -> V_128 == V_132 )
F_211 ( V_36 , 4 , 0 , V_7 -> V_12 -> V_262 ,
( T_1 * ) V_36 -> V_662 , 0 , NULL ) ;
else
F_211 ( V_36 , 4 , 0 , V_7 -> V_12 -> V_262 ,
V_831 , 0 , NULL ) ;
} else if ( V_7 -> V_12 -> V_262 == V_266 ) {
if ( V_7 -> V_12 -> V_128 == V_132 )
F_211 ( V_36 , 4 , 0 , V_7 -> V_12 -> V_262 ,
( T_1 * ) V_36 -> V_662 , 0 , NULL ) ;
else
F_211 ( V_36 , 4 , 0 , V_7 -> V_12 -> V_262 ,
V_831 , 0 , NULL ) ;
}
if ( V_7 -> V_12 -> V_835 == V_265 ) {
V_831 = V_833 ;
for ( V_830 = 1 ; V_830 < 4 ; V_830 ++ ) {
F_211 ( V_36 , V_830 , V_830 ,
V_7 -> V_12 -> V_835 ,
V_831 , 0 , NULL ) ;
}
if ( V_7 -> V_12 -> V_128 == V_132 )
F_211 ( V_36 , 0 , 0 , V_7 -> V_12 -> V_835 ,
V_832 [ 0 ] , 0 , NULL ) ;
} else if ( V_7 -> V_12 -> V_835 == V_266 ) {
V_831 = V_833 ;
for ( V_830 = 1 ; V_830 < 4 ; V_830 ++ ) {
F_211 ( V_36 , V_830 , V_830 ,
V_7 -> V_12 -> V_835 ,
V_831 , 0 , NULL ) ;
}
if ( V_7 -> V_12 -> V_128 == V_132 )
F_211 ( V_36 , 0 , 0 , V_7 -> V_12 -> V_835 ,
V_832 [ 0 ] , 0 , NULL ) ;
}
}
void F_212 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 V_836 = 0 ;
int V_837 = 0 ;
struct V_10 * V_11 = V_7 -> V_12 ;
if ( V_7 -> V_563 == V_564 ) {
V_838:
F_9 ( V_812 , L_109 ) ;
V_7 -> V_563 = V_815 ;
F_213 ( & V_7 -> V_627 ) ;
if ( V_7 -> V_193 == 0 ) {
F_9 ( V_27 , L_110 , V_28 ) ;
V_193 ( & V_7 -> V_627 ) ;
return;
}
V_7 -> V_193 = 0 ;
F_9 ( V_812 , L_111 , V_28 ) ;
F_80 ( V_36 ) ;
F_214 ( V_7 ) ;
F_215 ( V_36 ) ;
F_216 ( & V_7 -> V_705 ) ;
V_11 -> V_839 = 1 ;
if ( V_11 -> V_126 == V_127 ) {
F_213 ( & V_11 -> V_627 ) ;
F_110 ( V_36 , L_112 ) ;
F_217 ( V_7 -> V_12 ) ;
F_216 ( & V_11 -> V_840 ) ;
F_218 ( & V_11 -> V_841 ) ;
F_219 ( V_11 ) ;
F_220 ( V_36 ) ;
V_193 ( & V_11 -> V_627 ) ;
} else {
F_110 ( V_36 , L_113 ) ;
F_221 ( V_7 -> V_12 ) ;
}
V_193 ( & V_7 -> V_627 ) ;
F_9 ( V_812 , L_114 , V_28 ) ;
F_9 ( V_812 , L_115 , V_28 ) ;
V_837 = F_222 ( V_36 ) ;
F_9 ( V_812 , L_116 , V_28 ) ;
if ( V_837 == - V_842 ) {
if ( V_836 < 3 ) {
V_836 ++ ;
goto V_838;
} else {
F_9 ( V_27 , L_117 , V_28 ) ;
}
}
V_11 -> V_843 = 1 ;
F_146 ( V_36 ) ;
if ( V_11 -> V_126 == V_127 && V_11 -> V_128 == V_129 ) {
V_11 -> V_584 ( V_11 -> V_36 , V_11 -> V_302 . V_844 ) ;
F_154 ( V_11 -> V_845 , & V_11 -> V_846 ) ;
} else if ( V_11 -> V_126 == V_127 && V_11 -> V_128 == V_132 ) {
V_11 -> V_584 ( V_11 -> V_36 , V_11 -> V_302 . V_844 ) ;
V_11 -> V_585 ( V_11 -> V_36 ) ;
F_223 ( V_11 ) ;
if ( V_11 -> V_588 )
V_11 -> V_588 ( V_11 -> V_36 ) ;
F_224 ( V_11 -> V_36 ) ;
}
F_210 ( V_36 ) ;
V_7 -> V_563 = V_564 ;
V_7 -> V_847 ++ ;
V_7 -> V_565 = false ;
V_7 -> V_848 = false ;
F_24 ( V_36 , V_520 , 1 ) ;
F_9 ( V_812 , L_118 , V_7 -> V_847 ) ;
}
}
void F_225 ( struct V_35 * V_36 , T_2 V_849 )
{
T_2 V_850 = 0 ;
T_2 V_851 = 0 ;
T_1 V_852 = 0 ;
T_2 V_853 ;
T_12 V_1 = 100 ;
for ( V_852 = 0 ; V_852 < V_854 ; V_852 ++ ) {
V_850 = V_852 + V_854 * V_849 ;
V_850 = V_850 | V_38 ;
while ( ( V_1 -- ) >= 0 ) {
F_16 ( V_36 , V_40 , & V_853 ) ;
if ( V_853 & V_38 )
continue;
else
break;
}
F_13 ( V_36 , V_40 , V_850 ) ;
F_9 ( V_834 , L_119 , V_850 ) ;
F_16 ( V_36 , V_855 , & V_851 ) ;
F_9 ( V_834 , L_120 , V_851 ) ;
}
F_226 ( L_121 ) ;
}
void F_227 ( struct V_6 * V_7 , T_2 * V_856 ,
T_2 * V_857 )
{
T_3 V_858 ;
T_1 V_1 ;
* V_856 = 0 ;
* V_857 = 0 ;
V_858 = ( V_7 -> V_12 -> V_285 . V_858 ++ ) % ( V_7 -> V_12 -> V_285 . V_859 ) ;
V_7 -> V_12 -> V_285 . V_860 [ V_858 ] = V_7 -> V_12 -> V_285 . V_861 ;
V_7 -> V_12 -> V_285 . V_862 [ V_858 ] = V_7 -> V_12 -> V_285 . V_863 ;
for ( V_1 = 0 ; V_1 < V_7 -> V_12 -> V_285 . V_859 ; V_1 ++ ) {
* V_856 += V_7 -> V_12 -> V_285 . V_860 [ V_1 ] ;
* V_857 += V_7 -> V_12 -> V_285 . V_862 [ V_1 ] ;
}
}
extern void V_632 ( struct V_461 * V_462 )
{
struct V_864 * V_865 = F_148 ( V_462 , struct V_864 , V_462 ) ;
struct V_6 * V_7 = F_148 ( V_865 , struct V_6 , V_631 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
struct V_10 * V_11 = V_7 -> V_12 ;
T_10 V_866 = V_564 ;
static T_1 V_867 ;
bool V_868 = false ;
T_2 V_856 = 0 ;
T_2 V_857 = 0 ;
if ( ! V_7 -> V_193 )
return;
F_228 ( V_36 ) ;
if ( V_11 -> V_126 == V_127 ) {
if ( V_11 -> V_285 . V_869 > 666 ||
V_11 -> V_285 . V_286 > 666 ) {
V_868 = true ;
}
V_11 -> V_285 . V_869 = 0 ;
V_11 -> V_285 . V_286 = 0 ;
V_11 -> V_285 . V_868 = V_868 ;
}
if ( V_7 -> V_12 -> V_126 == V_127 && V_7 -> V_12 -> V_128 == V_129 ) {
F_227 ( V_7 , & V_856 , & V_857 ) ;
if ( ( V_856 + V_857 ) == 0 ) {
#ifdef F_229
if ( V_828 == V_774 )
F_9 ( V_27 , L_122 , V_28 ) ;
#endif
F_110 ( V_36 , L_123 , V_28 ) ;
V_7 -> V_12 -> V_126 = V_870 ;
F_230 ( V_7 -> V_12 ) ;
F_231 ( V_7 -> V_12 , V_7 -> V_12 -> V_302 . V_349 ) ;
V_7 -> V_12 -> V_585 ( V_36 ) ;
F_154 ( V_7 -> V_12 -> V_845 , & V_7 -> V_12 -> V_871 ) ;
}
}
V_7 -> V_12 -> V_285 . V_861 = 0 ;
V_7 -> V_12 -> V_285 . V_863 = 0 ;
if ( V_867 ++ >= 3 ) {
V_866 = F_209 ( V_36 ) ;
V_867 = 3 ;
}
if ( ( V_7 -> V_567 ) || ( V_7 -> V_563 == V_564 &&
( V_7 -> V_565 ||
( ! V_7 -> V_566 && V_866 == V_815 ) ) ) ) {
F_9 ( V_812 , L_124 , V_28 , V_7 -> V_567 , V_7 -> V_563 , V_7 -> V_565 , V_7 -> V_566 , V_866 ) ;
F_212 ( V_36 ) ;
}
V_7 -> V_567 = false ;
V_7 -> V_565 = false ;
V_7 -> V_848 = false ;
F_9 ( V_872 , L_125 ) ;
}
void V_707 ( unsigned long V_42 )
{
struct V_6 * V_7 = F_18 ( (struct V_35 * ) V_42 ) ;
F_156 ( V_7 -> V_498 , & V_7 -> V_631 , 0 ) ;
F_232 ( & V_7 -> V_705 , V_283 + F_233 ( V_873 ) ) ;
}
int F_222 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_723 = 0 ;
V_7 -> V_193 = 1 ;
V_7 -> V_12 -> V_552 = 1 ;
F_9 ( V_95 , L_126 ) ;
V_723 = F_189 ( V_36 ) ;
if ( ! V_723 ) {
F_9 ( V_27 , L_127 , V_28 ) ;
V_7 -> V_193 = V_7 -> V_12 -> V_552 = 0 ;
return - V_842 ;
}
F_9 ( V_95 , L_128 ) ;
F_78 ( V_36 ) ;
if ( V_7 -> V_12 -> V_126 != V_127 )
F_234 ( V_7 -> V_12 ) ;
F_235 ( V_7 -> V_12 ) ;
V_707 ( ( unsigned long ) V_36 ) ;
if ( ! F_37 ( V_36 ) )
F_236 ( V_36 ) ;
else
F_237 ( V_36 ) ;
return 0 ;
}
int F_238 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_200 ;
F_213 ( & V_7 -> V_627 ) ;
V_200 = F_239 ( V_36 ) ;
V_193 ( & V_7 -> V_627 ) ;
return V_200 ;
}
int F_239 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
if ( V_7 -> V_193 == 1 ) return - 1 ;
return F_222 ( V_36 ) ;
}
int F_240 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_200 ;
F_213 ( & V_7 -> V_627 ) ;
V_200 = F_241 ( V_36 ) ;
V_193 ( & V_7 -> V_627 ) ;
return V_200 ;
}
int F_241 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_1 ;
if ( V_7 -> V_193 == 0 ) return - 1 ;
V_7 -> V_193 = 0 ;
V_7 -> V_12 -> V_552 = 0 ;
F_9 ( V_874 , L_129 , V_28 ) ;
if ( ! F_37 ( V_36 ) )
F_242 ( V_36 ) ;
F_80 ( V_36 ) ;
for ( V_1 = 0 ; V_1 < V_623 ; V_1 ++ )
F_84 ( & V_7 -> V_12 -> V_290 [ V_1 ] ) ;
for ( V_1 = 0 ; V_1 < V_623 ; V_1 ++ )
F_84 ( & V_7 -> V_12 -> V_624 [ V_1 ] ) ;
for ( V_1 = 0 ; V_1 < V_623 ; V_1 ++ )
F_84 ( & V_7 -> V_12 -> V_279 [ V_1 ] ) ;
F_214 ( V_7 ) ;
F_215 ( V_36 ) ;
F_216 ( & V_7 -> V_705 ) ;
F_221 ( V_7 -> V_12 ) ;
memset ( & V_7 -> V_12 -> V_302 , 0 , F_243 ( struct V_58 , V_875 ) ) ;
F_9 ( V_874 , L_130 , V_28 ) ;
return 0 ;
}
void F_244 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_837 = 0 ;
if ( V_7 -> V_193 == 0 ) return;
V_7 -> V_193 = 0 ;
F_214 ( V_7 ) ;
F_216 ( & V_7 -> V_705 ) ;
F_221 ( V_7 -> V_12 ) ;
F_80 ( V_36 ) ;
V_837 = F_222 ( V_36 ) ;
}
void V_630 ( struct V_461 * V_462 )
{
struct V_6 * V_7 = F_148 ( V_462 , struct V_6 , V_114 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
F_213 ( & V_7 -> V_627 ) ;
F_244 ( V_36 ) ;
V_193 ( & V_7 -> V_627 ) ;
}
static void F_245 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
short V_560 ;
V_560 = ( V_36 -> V_167 & V_168 ) ? 1 : 0 ;
if ( V_560 != V_7 -> V_560 )
V_7 -> V_560 = V_560 ;
}
int F_246 ( struct V_35 * V_36 , void * V_876 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_877 * V_41 = V_876 ;
F_213 ( & V_7 -> V_627 ) ;
memcpy ( V_36 -> V_662 , V_41 -> V_878 , V_879 ) ;
F_56 ( & V_7 -> V_114 ) ;
V_193 ( & V_7 -> V_627 ) ;
return 0 ;
}
int F_247 ( struct V_35 * V_36 , struct V_880 * V_881 , int V_183 )
{
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_882 * V_883 = (struct V_882 * ) V_881 ;
int V_200 = - 1 ;
struct V_10 * V_11 = V_7 -> V_12 ;
T_2 V_884 [ 4 ] ;
T_1 V_885 [ 6 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_886 * V_887 = & V_883 -> V_888 . V_42 ;
struct V_889 * V_890 = NULL ;
F_213 ( & V_7 -> V_627 ) ;
if ( V_887 -> V_891 < sizeof( struct V_889 ) || ! V_887 -> V_892 ) {
V_200 = - V_893 ;
goto V_894;
}
V_890 = F_248 ( V_887 -> V_892 , V_887 -> V_891 ) ;
if ( F_249 ( V_890 ) ) {
V_200 = F_250 ( V_890 ) ;
goto V_894;
}
switch ( V_183 ) {
case V_895 :
if ( V_890 -> V_183 == V_896 ) {
if ( V_890 -> V_888 . V_522 . V_897 ) {
if ( strcmp ( V_890 -> V_888 . V_522 . V_898 , L_131 ) == 0 ) {
V_11 -> V_262 = V_266 ;
} else if ( strcmp ( V_890 -> V_888 . V_522 . V_898 , L_132 ) == 0 ) {
V_11 -> V_262 = V_265 ;
} else if ( strcmp ( V_890 -> V_888 . V_522 . V_898 , L_69 ) == 0 ) {
if ( V_890 -> V_888 . V_522 . V_899 == 13 )
V_11 -> V_262 = V_264 ;
else if ( V_890 -> V_888 . V_522 . V_899 == 5 )
V_11 -> V_262 = V_263 ;
} else {
V_11 -> V_262 = V_267 ;
}
if ( V_11 -> V_262 ) {
memcpy ( ( T_1 * ) V_884 , V_890 -> V_888 . V_522 . V_884 , 16 ) ;
F_146 ( V_36 ) ;
F_211 ( V_36 , 4 , V_890 -> V_888 . V_522 . V_900 , V_11 -> V_262 , ( T_1 * ) V_11 -> V_901 , 0 , V_884 ) ;
if ( V_11 -> V_902 != 2 )
F_211 ( V_36 , V_890 -> V_888 . V_522 . V_900 , V_890 -> V_888 . V_522 . V_900 , V_11 -> V_262 , ( T_1 * ) V_11 -> V_901 , 0 , V_884 ) ;
}
} else {
memcpy ( ( T_1 * ) V_884 , V_890 -> V_888 . V_522 . V_884 , 16 ) ;
if ( strcmp ( V_890 -> V_888 . V_522 . V_898 , L_131 ) == 0 ) {
V_11 -> V_835 = V_266 ;
} else if ( strcmp ( V_890 -> V_888 . V_522 . V_898 , L_132 ) == 0 ) {
V_11 -> V_835 = V_265 ;
} else if ( strcmp ( V_890 -> V_888 . V_522 . V_898 , L_69 ) == 0 ) {
if ( V_890 -> V_888 . V_522 . V_899 == 13 )
V_11 -> V_835 = V_264 ;
else if ( V_890 -> V_888 . V_522 . V_899 == 5 )
V_11 -> V_835 = V_263 ;
} else {
V_11 -> V_835 = V_267 ;
}
if ( V_11 -> V_835 ) {
F_211 ( V_36 , V_890 -> V_888 . V_522 . V_900 ,
V_890 -> V_888 . V_522 . V_900 ,
V_11 -> V_835 ,
V_885 ,
0 ,
V_884 ) ;
}
}
}
V_200 = F_251 ( V_7 -> V_12 , & V_883 -> V_888 . V_42 ) ;
break;
default:
V_200 = - V_903 ;
break;
}
F_142 ( V_890 ) ;
V_890 = NULL ;
V_894:
V_193 ( & V_7 -> V_627 ) ;
return V_200 ;
}
T_1 F_252 ( bool V_904 , T_1 V_189 )
{
T_1 V_905 = 0xff ;
if ( ! V_904 ) {
switch ( V_189 ) {
case V_397 : V_905 = V_305 ; break;
case V_398 : V_905 = V_307 ; break;
case V_399 : V_905 = V_309 ; break;
case V_400 : V_905 = V_311 ; break;
case V_401 : V_905 = V_313 ; break;
case V_402 : V_905 = V_315 ; break;
case V_403 : V_905 = V_317 ; break;
case V_404 : V_905 = V_319 ; break;
case V_405 : V_905 = V_321 ; break;
case V_406 : V_905 = V_323 ; break;
case V_407 : V_905 = V_325 ; break;
case V_408 : V_905 = V_327 ; break;
default:
V_905 = 0xff ;
F_9 ( V_906 , L_133 , V_189 , V_904 ) ;
break;
}
} else {
switch ( V_189 ) {
case V_410 : V_905 = V_409 ; break;
case V_412 : V_905 = V_411 ; break;
case V_414 : V_905 = V_413 ; break;
case V_416 : V_905 = V_415 ; break;
case V_418 : V_905 = V_417 ; break;
case V_420 : V_905 = V_419 ; break;
case V_422 : V_905 = V_421 ; break;
case V_424 : V_905 = V_423 ; break;
case V_426 : V_905 = V_425 ; break;
case V_428 : V_905 = V_427 ; break;
case V_430 : V_905 = V_429 ; break;
case V_432 : V_905 = V_431 ; break;
case V_434 : V_905 = V_433 ; break;
case V_436 : V_905 = V_435 ; break;
case V_438 : V_905 = V_437 ; break;
case V_440 : V_905 = V_439 ; break;
case V_441 : V_905 = ( 0x80 | 0x20 ) ; break;
default:
V_905 = 0xff ;
F_9 ( V_906 , L_133 , V_189 , V_904 ) ;
break;
}
}
return V_905 ;
}
static void F_253 ( struct V_35 * V_36 ,
struct V_141 * V_67 )
{
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
if ( V_67 -> V_907 && ! V_67 -> V_908 ) {
V_67 -> V_909 [ 0 ] = V_7 -> V_910 ;
V_67 -> V_909 [ 1 ] = V_7 -> V_911 ;
} else {
V_7 -> V_910 = V_67 -> V_909 [ 0 ] ;
V_7 -> V_911 = V_67 -> V_909 [ 1 ] ;
}
}
long F_254 ( T_1 V_912 )
{
long V_913 ;
V_913 = ( long ) ( ( V_912 + 1 ) >> 1 ) ;
V_913 -= 95 ;
return V_913 ;
}
void F_255 ( struct V_6 * V_7 , T_1 * V_914 , struct V_141 * V_915 , struct V_141 * V_916 )
{
bool V_917 = false ;
T_1 V_918 ;
T_2 V_919 , V_920 ;
static T_2 V_921 , V_922 ;
static T_2 V_923 , V_924 ;
static T_2 V_925 , V_926 ;
static T_2 V_927 , V_928 ;
static T_2 V_929 ;
struct V_930 * V_931 ;
T_3 V_932 ;
unsigned int V_933 , V_934 ;
V_931 = (struct V_930 * ) V_914 ;
V_932 = F_256 ( V_931 -> V_935 ) ;
V_933 = F_257 ( V_932 ) ;
V_934 = F_258 ( V_932 ) ;
V_916 -> V_936 = V_934 ;
if ( ! V_915 -> V_907 ) {
V_917 = true ;
}
if ( V_922 ++ >= V_937 ) {
V_922 = V_937 ;
V_925 = V_7 -> V_67 . V_938 [ V_921 ] ;
V_7 -> V_67 . V_939 -= V_925 ;
}
V_7 -> V_67 . V_939 += V_915 -> V_940 ;
V_7 -> V_67 . V_938 [ V_921 ++ ] = V_915 -> V_940 ;
if ( V_921 >= V_937 )
V_921 = 0 ;
V_920 = V_7 -> V_67 . V_939 / V_922 ;
V_7 -> V_67 . V_941 = F_254 ( ( T_1 ) V_920 ) ;
V_916 -> V_942 = V_7 -> V_67 . V_941 ;
if ( ! V_915 -> V_943 ) {
if ( ! V_915 -> V_944 )
return;
}
if ( ! V_917 )
return;
V_7 -> V_67 . V_945 ++ ;
if ( ! V_915 -> V_946 && ( V_915 -> V_947 || V_915 -> V_944 ) ) {
for ( V_918 = V_948 ; V_918 < V_7 -> V_777 ; V_918 ++ ) {
if ( ! F_259 ( V_7 -> V_12 -> V_36 , V_918 ) )
continue;
if ( V_7 -> V_67 . V_949 [ V_918 ] == 0 )
V_7 -> V_67 . V_949 [ V_918 ] = V_915 -> V_950 [ V_918 ] ;
if ( V_915 -> V_950 [ V_918 ] > V_7 -> V_67 . V_949 [ V_918 ] ) {
V_7 -> V_67 . V_949 [ V_918 ] =
( ( V_7 -> V_67 . V_949 [ V_918 ] * ( V_951 - 1 ) ) +
( V_915 -> V_950 [ V_918 ] ) ) / ( V_951 ) ;
V_7 -> V_67 . V_949 [ V_918 ] = V_7 -> V_67 . V_949 [ V_918 ] + 1 ;
} else {
V_7 -> V_67 . V_949 [ V_918 ] =
( ( V_7 -> V_67 . V_949 [ V_918 ] * ( V_951 - 1 ) ) +
( V_915 -> V_950 [ V_918 ] ) ) / ( V_951 ) ;
}
F_9 ( V_952 , L_134 , V_7 -> V_67 . V_949 [ V_918 ] ) ;
}
}
F_9 ( V_953 , L_135 ,
V_915 -> V_946 ? L_136 : L_137 ,
V_915 -> V_954 ) ;
if ( V_915 -> V_955 ) {
if ( V_928 ++ >= V_956 ) {
V_928 = V_956 ;
V_929 = V_7 -> V_67 . V_957 [ V_927 ] ;
V_7 -> V_67 . V_958 -= V_929 ;
}
V_7 -> V_67 . V_958 += V_915 -> V_954 ;
V_7 -> V_67 . V_957 [ V_927 ] = V_915 -> V_954 ;
V_927 ++ ;
if ( V_927 >= V_956 )
V_927 = 0 ;
V_915 -> V_954 = V_7 -> V_67 . V_958 / V_928 ;
if ( V_915 -> V_954 >= 3 )
V_915 -> V_954 -= 3 ;
}
F_9 ( V_953 , L_135 ,
V_915 -> V_946 ? L_136 : L_137 ,
V_915 -> V_954 ) ;
if ( V_915 -> V_947 || V_915 -> V_955 || V_915 -> V_944 ) {
if ( V_7 -> V_819 < 0 )
V_7 -> V_819 = V_915 -> V_954 ;
if ( V_915 -> V_954 > ( T_2 ) V_7 -> V_819 ) {
V_7 -> V_819 =
( ( ( V_7 -> V_819 ) * ( V_951 - 1 ) ) +
( V_915 -> V_954 ) ) / ( V_951 ) ;
V_7 -> V_819 = V_7 -> V_819 + 1 ;
} else {
V_7 -> V_819 =
( ( ( V_7 -> V_819 ) * ( V_951 - 1 ) ) +
( V_915 -> V_954 ) ) / ( V_951 ) ;
}
}
if ( V_915 -> V_959 ) {
if ( V_915 -> V_947 || V_915 -> V_955 || V_915 -> V_944 ) {
if ( V_924 ++ >= V_937 ) {
V_924 = V_937 ;
V_926 = V_7 -> V_67 . V_960 [ V_923 ] ;
V_7 -> V_67 . V_961 -= V_926 ;
}
V_7 -> V_67 . V_961 += V_915 -> V_959 ;
V_7 -> V_67 . V_960 [ V_923 ++ ] = V_915 -> V_959 ;
if ( V_923 >= V_937 )
V_923 = 0 ;
V_920 = V_7 -> V_67 . V_961 / V_924 ;
V_7 -> V_67 . V_962 = V_920 ;
V_7 -> V_67 . V_963 = V_920 ;
}
if ( V_915 -> V_947 || V_915 -> V_955 || V_915 -> V_944 ) {
for ( V_919 = 0 ; V_919 < 2 ; V_919 ++ ) {
if ( V_915 -> V_964 [ V_919 ] != - 1 ) {
if ( V_7 -> V_67 . V_965 [ V_919 ] == 0 )
V_7 -> V_67 . V_965 [ V_919 ] = V_915 -> V_964 [ V_919 ] ;
V_7 -> V_67 . V_965 [ V_919 ] =
( ( V_7 -> V_67 . V_965 [ V_919 ] * ( V_951 - 1 ) ) +
( V_915 -> V_964 [ V_919 ] * 1 ) ) / ( V_951 ) ;
}
}
}
}
}
static T_1 F_260 ( char V_966 )
{
if ( ( V_966 <= - 100 ) || ( V_966 >= 20 ) )
return 0 ;
else if ( V_966 >= 0 )
return 100 ;
else
return 100 + V_966 ;
}
static T_1 F_261 ( char V_967 )
{
char V_968 ;
V_968 = V_967 ;
if ( V_968 >= 0 )
V_968 = 0 ;
if ( V_968 <= - 33 )
V_968 = - 33 ;
V_968 = 0 - V_968 ;
V_968 *= 3 ;
if ( V_968 == 99 )
V_968 = 100 ;
return V_968 ;
}
static long F_262 ( long V_969 )
{
long V_970 ;
if ( V_969 >= 61 && V_969 <= 100 )
V_970 = 90 + ( ( V_969 - 60 ) / 4 ) ;
else if ( V_969 >= 41 && V_969 <= 60 )
V_970 = 78 + ( ( V_969 - 40 ) / 2 ) ;
else if ( V_969 >= 31 && V_969 <= 40 )
V_970 = 66 + ( V_969 - 30 ) ;
else if ( V_969 >= 21 && V_969 <= 30 )
V_970 = 54 + ( V_969 - 20 ) ;
else if ( V_969 >= 5 && V_969 <= 20 )
V_970 = 42 + ( ( ( V_969 - 5 ) * 2 ) / 3 ) ;
else if ( V_969 == 4 )
V_970 = 36 ;
else if ( V_969 == 3 )
V_970 = 27 ;
else if ( V_969 == 2 )
V_970 = 18 ;
else if ( V_969 == 1 )
V_970 = 9 ;
else
V_970 = V_969 ;
return V_970 ;
}
static inline bool F_263 ( struct V_971 * V_972 )
{
if ( V_972 -> V_973 )
return false ;
switch ( V_972 -> V_974 ) {
case V_397 :
case V_398 :
case V_399 :
case V_400 :
return true ;
default:
return false ;
}
}
static void F_264 ( struct V_6 * V_7 ,
struct V_141 * V_142 ,
V_971 * V_972 ,
struct V_141 * V_975 ,
bool V_976 ,
bool V_977 ,
bool V_955 ,
bool V_944 )
{
T_13 * V_978 ;
T_14 * V_979 ;
T_15 * V_980 ;
T_1 * V_981 ;
T_1 V_1 , V_982 , V_983 , V_984 , V_985 ;
char V_986 [ 4 ] , V_987 = 0 ;
char V_988 , V_989 ;
T_1 V_990 , V_991 ;
T_2 V_992 , V_993 = 0 ;
T_1 V_994 = 0 ;
T_1 V_995 = 0 ;
T_1 V_996 ;
V_7 -> V_67 . V_997 ++ ;
V_994 = F_263 ( V_972 ) ;
memset ( V_975 , 0 , sizeof( struct V_141 ) ) ;
V_142 -> V_943 = V_975 -> V_943 = V_976 ;
V_142 -> V_947 = V_975 -> V_947 = V_977 ;
V_142 -> V_946 = V_975 -> V_946 = V_994 ;
V_142 -> V_955 = V_975 -> V_955 = V_955 ;
V_142 -> V_944 = V_975 -> V_944 = V_944 ;
V_981 = ( T_1 * ) V_972 ;
V_981 += sizeof( V_971 ) ;
V_979 = ( T_14 * ) V_981 ;
V_978 = ( T_13 * ) V_981 ;
V_142 -> V_964 [ 0 ] = - 1 ;
V_142 -> V_964 [ 1 ] = - 1 ;
V_975 -> V_964 [ 0 ] = - 1 ;
V_975 -> V_964 [ 1 ] = - 1 ;
if ( V_994 ) {
T_1 V_998 ;
V_7 -> V_67 . V_999 ++ ;
if ( ! V_7 -> V_1000 ) {
V_998 = V_979 -> V_1001 & 0xc0 ;
V_998 = V_998 >> 6 ;
switch ( V_998 ) {
case 0x3 :
V_987 = - 35 - ( V_979 -> V_1001 & 0x3e ) ;
break;
case 0x2 :
V_987 = - 23 - ( V_979 -> V_1001 & 0x3e ) ;
break;
case 0x1 :
V_987 = - 11 - ( V_979 -> V_1001 & 0x3e ) ;
break;
case 0x0 :
V_987 = 6 - ( V_979 -> V_1001 & 0x3e ) ;
break;
}
} else {
V_998 = V_979 -> V_1001 & 0x60 ;
V_998 = V_998 >> 5 ;
switch ( V_998 ) {
case 0x3 :
V_987 = - 35 - ( ( V_979 -> V_1001 & 0x1f ) << 1 ) ;
break;
case 0x2 :
V_987 = - 23 - ( ( V_979 -> V_1001 & 0x1f ) << 1 ) ;
break;
case 0x1 :
V_987 = - 11 - ( ( V_979 -> V_1001 & 0x1f ) << 1 ) ;
break;
case 0x0 :
V_987 = 6 - ( ( V_979 -> V_1001 & 0x1f ) << 1 ) ;
break;
}
}
V_991 = F_260 ( V_987 ) ;
V_142 -> V_954 = V_975 -> V_954 = V_991 ;
V_142 -> V_1002 = V_991 ;
if ( V_142 -> V_954 > 40 ) {
V_996 = 100 ;
} else {
V_996 = V_979 -> V_1003 ;
if ( V_979 -> V_1003 > 64 )
V_996 = 0 ;
else if ( V_979 -> V_1003 < 20 )
V_996 = 100 ;
else
V_996 = ( ( 64 - V_996 ) * 100 ) / 44 ;
}
V_142 -> V_959 = V_975 -> V_959 = V_996 ;
V_142 -> V_964 [ 0 ] = V_975 -> V_964 [ 0 ] = V_996 ;
V_142 -> V_964 [ 1 ] = V_975 -> V_964 [ 1 ] = - 1 ;
} else {
V_7 -> V_67 . V_1004 ++ ;
for ( V_1 = V_948 ; V_1 < V_7 -> V_777 ; V_1 ++ ) {
if ( V_7 -> V_1005 [ V_1 ] )
V_995 ++ ;
else
continue;
if ( ! F_259 ( V_7 -> V_12 -> V_36 , V_1 ) )
continue;
V_986 [ V_1 ] = ( ( V_978 -> V_1006 [ V_1 ] & 0x3F ) * 2 ) - 106 ;
V_983 = V_978 -> V_1007 [ V_1 ] ;
V_988 = ( char ) ( V_983 ) ;
V_988 /= 2 ;
V_7 -> V_67 . V_1008 [ V_1 ] = ( long ) V_988 ;
V_992 = F_260 ( V_986 [ V_1 ] ) ;
V_993 += V_992 ;
V_142 -> V_950 [ V_1 ] = ( T_1 ) V_992 ;
V_975 -> V_950 [ V_1 ] = ( T_1 ) V_992 ;
}
V_987 = ( ( ( V_978 -> V_991 ) >> 1 ) & 0x7f ) - 106 ;
V_991 = F_260 ( V_987 ) ;
V_142 -> V_954 = V_975 -> V_954 = V_991 ;
V_142 -> V_1009 = V_975 -> V_1009 = V_987 ;
if ( V_972 -> V_973 && V_972 -> V_974 >= V_426 &&
V_972 -> V_974 <= V_440 )
V_982 = 2 ;
else
V_982 = 1 ;
for ( V_1 = 0 ; V_1 < V_982 ; V_1 ++ ) {
V_984 = V_978 -> V_1010 [ V_1 ] ;
V_989 = ( char ) ( V_984 ) ;
V_989 /= 2 ;
V_990 = F_261 ( V_989 ) ;
if ( V_1 == 0 )
V_142 -> V_959 = V_975 -> V_959 = ( T_1 ) ( V_990 & 0xff ) ;
V_142 -> V_964 [ V_1 ] = V_975 -> V_964 [ V_1 ] = ( T_1 ) ( V_990 & 0xff ) ;
}
V_985 = V_978 -> V_985 ;
V_980 = ( T_15 * ) & V_985 ;
if ( V_972 -> V_1011 )
V_7 -> V_67 . V_1012 [ 1 + V_980 -> V_1013 ] ++ ;
else
V_7 -> V_67 . V_1012 [ 0 ] ++ ;
}
if ( V_994 ) {
V_142 -> V_940 = V_975 -> V_940 = ( T_1 ) ( F_262 ( ( long ) V_991 ) ) ;
} else {
if ( V_995 != 0 )
V_142 -> V_940 = V_975 -> V_940 = ( T_1 ) ( F_262 ( ( long ) ( V_993 /= V_995 ) ) ) ;
}
}
void F_265 ( struct V_141 * V_1014 ,
struct V_141 * V_1015 )
{
V_1015 -> V_907 = V_1014 -> V_907 ;
V_1015 -> V_908 = V_1014 -> V_908 ;
V_1015 -> V_936 = V_1014 -> V_936 ;
}
static void F_266 ( struct V_149 * V_150 ,
struct V_141 * V_142 ,
V_971 * V_972 )
{
V_151 * V_152 = (struct V_151 * ) V_150 -> V_158 ;
struct V_35 * V_36 = V_152 -> V_36 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
bool V_976 , V_977 ;
bool V_955 = FALSE , V_944 = FALSE ;
static struct V_141 V_1016 ;
struct V_930 * V_931 ;
T_3 V_1017 , type ;
T_1 * V_1018 ;
T_1 * V_1019 ;
V_1018 = ( T_1 * ) V_150 -> V_42 ;
V_931 = (struct V_930 * ) V_1018 ;
V_1017 = F_256 ( V_931 -> V_1020 ) ;
type = F_267 ( V_1017 ) ;
V_1019 = V_931 -> V_1021 ;
V_976 = ( ( V_1022 != type ) &&
( F_268 ( V_7 -> V_12 -> V_302 . V_349 , ( V_1017 & V_1023 ) ? V_931 -> V_1021 : ( V_1017 & V_1024 ) ? V_931 -> V_1025 : V_931 -> V_1026 ) )
&& ( ! V_142 -> V_1027 ) && ( ! V_142 -> V_1028 ) && ( ! V_142 -> V_1029 ) ) ;
V_977 = V_976 & ( F_268 ( V_1019 , V_7 -> V_12 -> V_36 -> V_662 ) ) ;
if ( F_269 ( V_1017 ) == V_1030 )
V_955 = true ;
if ( F_269 ( V_1017 ) == V_1031 ) {
if ( ( F_268 ( V_1019 , V_36 -> V_662 ) ) )
V_944 = true ;
}
if ( V_976 )
V_7 -> V_67 . V_1032 ++ ;
if ( V_977 )
V_7 -> V_67 . V_1033 ++ ;
F_255 ( V_7 , V_1018 , & V_1016 , V_142 ) ;
F_264 ( V_7 , V_142 , V_972 , & V_1016 , V_976 , V_977 , V_955 , V_944 ) ;
F_265 ( V_142 , & V_1016 ) ;
}
static void
F_270 ( struct V_35 * V_36 ,
struct V_141 * V_67 )
{
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
T_2 V_1034 = 1 ;
T_2 V_1035 ;
T_2 V_1036 ;
if ( V_67 -> V_1028 )
V_1034 = 2 ;
else if ( V_67 -> V_1029 )
V_1034 = 3 ;
if ( V_67 -> V_363 )
V_1036 = 1 ;
else
V_1036 = 0 ;
switch ( V_67 -> V_189 ) {
case V_305 : V_1035 = 0 ; break;
case V_307 : V_1035 = 1 ; break;
case V_309 : V_1035 = 2 ; break;
case V_311 : V_1035 = 3 ; break;
case V_313 : V_1035 = 4 ; break;
case V_315 : V_1035 = 5 ; break;
case V_317 : V_1035 = 6 ; break;
case V_319 : V_1035 = 7 ; break;
case V_321 : V_1035 = 8 ; break;
case V_323 : V_1035 = 9 ; break;
case V_325 : V_1035 = 10 ; break;
case V_327 : V_1035 = 11 ; break;
case V_409 : V_1035 = 12 ; break;
case V_411 : V_1035 = 13 ; break;
case V_413 : V_1035 = 14 ; break;
case V_415 : V_1035 = 15 ; break;
case V_417 : V_1035 = 16 ; break;
case V_419 : V_1035 = 17 ; break;
case V_421 : V_1035 = 18 ; break;
case V_423 : V_1035 = 19 ; break;
case V_425 : V_1035 = 20 ; break;
case V_427 : V_1035 = 21 ; break;
case V_429 : V_1035 = 22 ; break;
case V_431 : V_1035 = 23 ; break;
case V_433 : V_1035 = 24 ; break;
case V_435 : V_1035 = 25 ; break;
case V_437 : V_1035 = 26 ; break;
case V_439 : V_1035 = 27 ; break;
default: V_1035 = 28 ; break;
}
V_7 -> V_67 . V_1037 [ V_1036 ] [ V_1035 ] ++ ;
V_7 -> V_67 . V_1038 [ 0 ] [ V_1035 ] ++ ;
V_7 -> V_67 . V_1038 [ V_1034 ] [ V_1035 ] ++ ;
}
static void F_271 ( struct V_149 * V_150 ,
struct V_141 * V_67 ,
bool V_1039 )
{
V_151 * V_152 = (struct V_151 * ) V_150 -> V_158 ;
struct V_35 * V_36 = V_152 -> V_36 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
V_971 * V_1040 = NULL ;
#ifdef F_65
if ( V_1039 ) {
T_16 * V_1041 = ( T_16 * ) V_150 -> V_42 ;
V_67 -> V_1042 = V_1041 -> V_1042 ;
V_67 -> V_145 = V_1041 -> V_145 ;
V_67 -> V_146 = 0 ;
V_67 -> V_1029 = V_1041 -> V_1043 ;
V_67 -> V_1028 = V_1041 -> V_1044 ;
V_67 -> V_1027 = V_67 -> V_1028 | V_67 -> V_1029 ;
V_67 -> V_1045 = ! V_1041 -> V_1046 ;
} else
#endif
{
V_144 * V_1041 = ( V_144 * ) V_150 -> V_42 ;
V_67 -> V_1042 = V_1041 -> V_1042 ;
V_67 -> V_145 = V_1041 -> V_145 ;
V_67 -> V_146 = 0 ;
V_67 -> V_1029 = V_1041 -> V_1043 ;
V_67 -> V_1028 = V_1041 -> V_1044 ;
V_67 -> V_1027 = V_67 -> V_1028 | V_67 -> V_1029 ;
V_67 -> V_1045 = ! V_1041 -> V_1046 ;
}
if ( ( V_7 -> V_12 -> V_275 -> V_464 == true ) && ( V_7 -> V_12 -> V_262 == V_266 ) )
V_67 -> V_1027 = false ;
else
V_67 -> V_1027 = V_67 -> V_1028 | V_67 -> V_1029 ;
if ( V_67 -> V_1042 < 24 || V_67 -> V_1042 > V_1047 )
V_67 -> V_1027 |= 1 ;
if ( V_67 -> V_145 != 0 ) {
V_1040 = ( V_971 * ) ( V_150 -> V_42 + sizeof( V_144 ) +
V_67 -> V_146 ) ;
if ( ! V_67 -> V_1027 ) {
T_1 V_905 ;
V_905 = F_252 ( V_1040 -> V_973 , V_1040 -> V_974 ) ;
if ( V_905 == 0xff ) {
V_67 -> V_1027 = 1 ;
V_67 -> V_189 = V_305 ;
} else {
V_67 -> V_189 = V_905 ;
}
} else {
V_67 -> V_189 = 0x02 ;
}
V_67 -> V_363 = V_1040 -> V_1048 ;
F_270 ( V_36 , V_67 ) ;
V_67 -> V_907 = ( V_1040 -> V_1049 == 1 ) ;
V_67 -> V_908 = ( V_1040 -> V_1049 == 1 ) && ( V_1040 -> V_1050 == 1 ) ;
V_67 -> V_1051 = V_1040 -> V_1052 ;
F_253 ( V_36 , V_67 ) ;
if ( V_1040 -> V_1050 == 1 || V_1040 -> V_1049 == 1 )
F_9 ( V_953 , L_138 ,
V_1040 -> V_1050 , V_1040 -> V_1049 ) ;
}
F_272 ( V_150 , sizeof( V_144 ) ) ;
if ( ( V_67 -> V_146 + V_67 -> V_145 ) > 0 ) {
V_67 -> V_1053 = 1 ;
F_272 ( V_150 , V_67 -> V_146 + V_67 -> V_145 ) ;
}
#ifdef F_65
if ( V_1039 )
F_272 ( V_150 , 8 ) ;
#endif
V_67 -> V_1054 = V_1040 -> V_1011 ;
if ( V_67 -> V_145 != 0 )
F_266 ( V_150 , V_67 , V_1040 ) ;
}
T_2 F_273 ( struct V_141 * V_1055 , bool V_1039 )
{
#ifdef F_65
if ( V_1039 )
return ( sizeof( V_144 ) + V_1055 -> V_145
+ V_1055 -> V_146 + 8 ) ;
else
#endif
return ( sizeof( V_144 ) + V_1055 -> V_145
+ V_1055 -> V_146 ) ;
}
void F_274 ( struct V_149 * V_150 )
{
V_151 * V_152 = (struct V_151 * ) V_150 -> V_158 ;
struct V_35 * V_36 = V_152 -> V_36 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_141 V_67 = {
. signal = 0 ,
. V_1056 = - 98 ,
. V_189 = 0 ,
. V_1057 = V_1058 ,
} ;
T_2 V_1059 = 0 ;
struct V_1060 * V_1061 = NULL ;
bool V_1062 = false ;
#ifdef F_65
struct V_149 * V_214 = NULL ;
T_2 V_213 = 0 ;
T_2 V_1063 = 0 ;
T_2 V_1064 = 0 ;
T_2 V_1065 = 0 ;
T_1 V_1066 = 0 ;
T_2 V_1067 = 0 ;
T_16 * V_1068 = NULL ;
T_1 V_1069 = 0 ;
T_1 V_1070 ;
#endif
if ( ( V_150 -> V_209 >= ( 20 + sizeof( V_144 ) ) ) && ( V_150 -> V_209 < V_155 ) ) {
#ifdef F_65
V_1066 = * ( V_150 -> V_42 + sizeof( V_144 ) ) ;
#endif
F_271 ( V_150 , & V_67 , false ) ;
#ifdef F_65
if ( V_1066 & V_1071 ) {
V_214 = V_150 ;
V_213 = V_67 . V_1042 - 4 ;
V_1063 = * ( T_2 * ) ( V_214 -> V_42 - 4 ) ;
V_1064 = ( T_3 ) ( V_1063 & 0x3FFF ) ;
V_150 = F_93 ( V_1064 ) ;
memcpy ( F_91 ( V_150 , V_1064 ) , V_214 -> V_42 , V_1064 ) ;
V_1067 = F_273 ( & V_67 , false ) ;
}
#endif
F_275 ( V_150 , V_150 -> V_209 - 4 ) ;
V_1059 = V_150 -> V_209 ;
V_1061 = (struct V_1060 * ) V_150 -> V_42 ;
V_1062 = false ;
if ( F_276 ( V_1061 -> V_1021 ) ) {
} else if ( F_277 ( V_1061 -> V_1021 ) ) {
} else {
V_1062 = true ;
}
if ( ! F_278 ( V_7 -> V_12 , V_150 , & V_67 ) ) {
F_114 ( V_150 ) ;
} else {
V_7 -> V_67 . V_92 ++ ;
if ( V_1062 )
V_7 -> V_67 . V_1072 += V_1059 ;
}
#ifdef F_65
V_1070 = 1 ;
if ( V_213 > 0 ) {
V_1065 = V_1064 + ( V_1067 + 8 ) ;
if ( ( V_1065 & 0xFF ) != 0 )
V_1065 = ( V_1065 & 0xFFFFFF00 ) + 256 ;
V_1065 -= 8 ;
V_1063 = V_1065 - V_1067 ;
if ( V_214 -> V_209 > V_1063 )
F_272 ( V_214 , V_1063 ) ;
else
V_214 -> V_209 = 0 ;
while ( V_214 -> V_209 >= F_273 ( & V_67 , true ) ) {
T_1 V_1073 = 0 , V_1074 = 0 ;
V_1068 = ( T_16 * ) ( V_214 -> V_42 ) ;
V_1073 = V_1068 -> V_1044 ;
V_1074 = V_1068 -> V_1043 ;
memcpy ( V_214 -> V_42 , & V_214 -> V_42 [ 44 ] , 2 ) ;
V_1068 -> V_1044 = V_1073 ;
V_1068 -> V_1043 = V_1074 ;
memset ( & V_67 , 0 , sizeof( struct V_141 ) ) ;
V_67 . signal = 0 ;
V_67 . V_1056 = - 98 ;
V_67 . V_189 = 0 ;
V_67 . V_1057 = V_1058 ;
F_271 ( V_214 , & V_67 , true ) ;
V_1064 = V_67 . V_1042 ;
if ( V_1064 > V_214 -> V_209 )
break;
V_150 = F_93 ( V_1064 ) ;
memcpy ( F_91 ( V_150 , V_1064 ) , V_214 -> V_42 , V_1064 ) ;
F_275 ( V_150 , V_150 -> V_209 - 4 ) ;
V_1059 = V_150 -> V_209 ;
V_1061 = (struct V_1060 * ) V_150 -> V_42 ;
V_1062 = false ;
if ( F_276 ( V_1061 -> V_1021 ) ) {
} else if ( F_277 ( V_1061 -> V_1021 ) ) {
} else {
V_1062 = true ;
}
if ( ! F_278 ( V_7 -> V_12 , V_150 , & V_67 ) ) {
F_114 ( V_150 ) ;
} else {
V_7 -> V_67 . V_92 ++ ;
if ( V_1062 )
V_7 -> V_67 . V_1072 += V_1059 ;
}
F_272 ( V_214 , V_1064 ) ;
V_1067 = F_273 ( & V_67 , true ) ;
V_1065 = V_1064 + V_1067 ;
if ( ( V_1065 & 0xFF ) != 0 ) {
V_1069 = 256 - ( V_1065 & 0xFF ) ;
if ( V_214 -> V_209 > V_1069 )
F_272 ( V_214 , V_1069 ) ;
else
V_214 -> V_209 = 0 ;
}
}
F_132 ( V_214 ) ;
}
#endif
} else {
V_7 -> V_67 . V_94 ++ ;
F_110 ( V_36 , L_139 , V_150 -> V_209 ) ;
F_114 ( V_150 ) ;
}
}
void F_279 ( struct V_35 * V_36 ,
struct V_141 * V_142 )
{
T_1 * V_1075 ;
T_3 V_1076 = 0 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
V_142 -> V_1077 += F_64 ( V_142 ) ;
V_1075 = V_142 -> V_1077 ;
V_1076 = V_142 -> V_1078 ;
#ifdef F_229
if ( ! V_604 -> V_605 )
F_280 ( V_604 , V_1079 ) ;
#endif
#ifdef F_281
T_11 V_1080 ;
V_604 -> V_1081 . V_1082 ( V_604 , V_1083 , ( T_1 * ) ( & V_1080 ) ) ;
if ( V_1080 == V_774 )
return;
#endif
V_7 -> V_67 . V_1084 ++ ;
#ifdef F_229
F_282 ( V_604 , V_1079 ) ;
#endif
if ( F_94 ( V_36 , V_142 ) )
return;
#ifdef F_283
F_284 () ;
#endif
}
static void F_285 ( struct V_149 * V_150 ,
struct V_141 * V_67 )
{
V_144 * V_1041 = ( V_144 * ) V_150 -> V_42 ;
V_67 -> V_1077 = ( T_1 * ) V_150 -> V_42 ;
V_67 -> V_1042 = V_1041 -> V_1042 ;
V_67 -> V_145 = 0 ;
V_67 -> V_146 = 0 ;
V_67 -> V_1078 = V_67 -> V_1042 - V_1085 ;
V_67 -> V_1086 = V_67 -> V_1078 ;
V_67 -> V_1087 = 0 ;
V_67 -> V_1088 = 1 ;
}
void F_286 ( struct V_149 * V_150 )
{
struct V_151 * V_152 = (struct V_151 * ) V_150 -> V_158 ;
struct V_35 * V_36 = V_152 -> V_36 ;
struct V_141 V_67 = {
. signal = 0 ,
. V_1056 = - 98 ,
. V_189 = 0 ,
. V_1057 = V_1058 ,
} ;
if ( ( V_150 -> V_209 >= ( 20 + sizeof( V_144 ) ) ) && ( V_150 -> V_209 < V_155 ) ) {
F_285 ( V_150 , & V_67 ) ;
F_279 ( V_36 , & V_67 ) ;
F_114 ( V_150 ) ;
}
}
void V_639 ( struct V_6 * V_7 )
{
struct V_149 * V_150 ;
struct V_151 * V_152 ;
while ( NULL != ( V_150 = F_116 ( & V_7 -> V_187 ) ) ) {
V_152 = (struct V_151 * ) V_150 -> V_158 ;
switch ( V_152 -> V_159 ) {
case 3 :
V_7 -> V_562 -- ;
F_274 ( V_150 ) ;
break;
case 9 :
F_9 ( V_906 , L_140 ,
V_152 -> V_159 ) ;
F_286 ( V_150 ) ;
break;
default:
F_9 ( V_27 , L_141 ,
V_152 -> V_159 ) ;
F_132 ( V_150 ) ;
break;
}
}
}
static int F_287 ( struct V_1089 * V_1090 ,
const struct V_1091 * V_1092 )
{
struct V_35 * V_36 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_47 * V_48 = F_288 ( V_1090 ) ;
int V_200 ;
F_9 ( V_95 , L_142 ) ;
V_36 = F_289 ( sizeof( struct V_6 ) ) ;
if ( V_36 == NULL )
return - V_374 ;
F_290 ( V_1090 , V_36 ) ;
F_291 ( V_36 , & V_1090 -> V_36 ) ;
V_7 = F_18 ( V_36 ) ;
V_7 -> V_12 = F_108 ( V_36 ) ;
V_7 -> V_48 = V_48 ;
V_36 -> V_1093 = & V_1094 ;
#if V_1095 >= 12
#if V_1095 < 17
V_36 -> V_1096 = V_1097 ;
#endif
V_36 -> V_1098 = (struct V_1099 * ) & V_1100 ;
#endif
V_36 -> type = V_1101 ;
V_36 -> V_1102 = V_51 * 3 ;
if ( F_292 ( V_36 , V_1103 ) < 0 ) {
F_9 ( V_95 , L_143 ) ;
V_1103 = L_144 ;
F_292 ( V_36 , V_1103 ) ;
}
F_9 ( V_95 , L_145 ) ;
if ( F_183 ( V_36 ) != 0 ) {
F_9 ( V_27 , L_146 ) ;
V_200 = - V_1104 ;
goto V_1105;
}
F_220 ( V_36 ) ;
F_242 ( V_36 ) ;
V_200 = F_293 ( V_36 ) ;
if ( V_200 )
goto V_1106;
F_9 ( V_95 , L_147 , V_36 -> V_106 ) ;
F_49 ( V_36 ) ;
F_9 ( V_95 , L_148 ) ;
return 0 ;
V_1106:
F_241 ( V_36 ) ;
F_142 ( V_7 -> V_621 ) ;
V_7 -> V_621 = NULL ;
F_143 ( V_36 ) ;
F_294 ( V_7 -> V_498 ) ;
F_63 ( 10 ) ;
V_1105:
F_295 ( V_36 ) ;
F_9 ( V_27 , L_149 ) ;
return V_200 ;
}
void F_214 ( struct V_6 * V_7 )
{
F_296 ( & V_7 -> V_114 ) ;
F_218 ( & V_7 -> V_631 ) ;
F_218 ( & V_7 -> V_463 ) ;
F_296 ( & V_7 -> V_468 ) ;
}
static void F_297 ( struct V_1089 * V_1090 )
{
struct V_35 * V_36 = F_298 ( V_1090 ) ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
if ( V_36 ) {
F_299 ( V_36 ) ;
F_9 ( V_874 , L_150 ) ;
F_52 ( V_36 ) ;
F_241 ( V_36 ) ;
F_142 ( V_7 -> V_621 ) ;
V_7 -> V_621 = NULL ;
F_143 ( V_36 ) ;
F_294 ( V_7 -> V_498 ) ;
F_63 ( 10 ) ;
}
F_295 ( V_36 ) ;
F_9 ( V_874 , L_151 ) ;
}
static int T_17 F_300 ( void )
{
int V_200 ;
#ifdef F_301
V_200 = F_302 () ;
if ( V_200 ) {
F_303 ( L_152 , V_200 ) ;
return V_200 ;
}
#endif
V_200 = F_304 () ;
if ( V_200 ) {
F_303 ( L_153 , V_200 ) ;
return V_200 ;
}
V_200 = F_305 () ;
if ( V_200 ) {
F_303 ( L_154 , V_200 ) ;
return V_200 ;
}
V_200 = F_306 () ;
if ( V_200 ) {
F_303 ( L_155 , V_200 ) ;
return V_200 ;
}
V_200 = F_307 () ;
if ( V_200 ) {
F_303 ( L_156 , V_200 ) ;
return V_200 ;
}
F_308 ( L_157 ) ;
F_308 ( L_158 ) ;
F_9 ( V_95 , L_159 ) ;
F_9 ( V_95 , L_160 , V_1095 ) ;
F_40 () ;
return F_309 ( & V_1107 ) ;
}
static void T_18 F_310 ( void )
{
F_311 ( & V_1107 ) ;
F_9 ( V_874 , L_161 ) ;
}
void F_312 ( struct V_35 * V_36 , int V_1108 )
{
unsigned long V_167 ;
short V_1109 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
F_100 ( & V_7 -> V_204 , V_167 ) ;
V_1109 = F_54 ( V_36 , V_1108 ) ;
F_103 ( & V_7 -> V_204 , V_167 ) ;
if ( V_1109 )
F_313 ( V_7 -> V_12 ) ;
}
void F_146 ( struct V_35 * V_36 )
{
T_1 V_724 = 0x0 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
V_724 = V_760 | V_761 ;
if ( ( ( V_263 == V_11 -> V_262 ) || ( V_264 == V_11 -> V_262 ) ) && ( V_7 -> V_12 -> V_902 != 2 ) ) {
V_724 |= V_1110 ;
V_724 |= V_1111 ;
} else if ( ( V_11 -> V_128 == V_132 ) && ( V_11 -> V_262 & ( V_266 | V_265 ) ) ) {
V_724 |= V_1110 ;
V_724 |= V_1111 ;
}
V_11 -> V_1112 = 1 ;
if ( ( V_11 -> V_275 -> V_1113 & V_1114 ) || ! V_1115 ) {
V_11 -> V_1112 = 0 ;
V_724 &= ~ V_761 ;
}
F_9 ( V_834 , L_162 , V_28 ,
V_11 -> V_1112 , V_11 -> V_262 , V_724 ) ;
F_24 ( V_36 , V_763 , V_724 ) ;
}
void F_211 ( struct V_35 * V_36 , T_1 V_1116 , T_1 V_1117 , T_3 V_1118 ,
T_1 * V_831 , T_1 V_1119 , T_2 * V_1120 )
{
T_2 V_1121 = 0 ;
T_2 V_1122 = 0 ;
T_3 V_1123 = 0 ;
T_1 V_1 ;
if ( V_1116 >= V_1124 )
F_9 ( V_27 , L_163 ) ;
F_9 ( V_834 , L_164 , V_36 , V_1116 , V_1117 , V_1118 , V_831 ) ;
if ( V_1119 )
V_1123 |= V_1125 | ( V_1118 << 2 ) ;
else
V_1123 |= V_1125 | ( V_1118 << 2 ) | V_1117 ;
for ( V_1 = 0 ; V_1 < V_854 ; V_1 ++ ) {
V_1121 = V_1 + V_854 * V_1116 ;
V_1121 |= V_38 | V_44 ;
if ( V_1 == 0 ) {
V_1122 = ( T_2 ) ( * ( V_831 + 0 ) ) << 16 |
( T_2 ) ( * ( V_831 + 1 ) ) << 24 |
( T_2 ) V_1123 ;
F_13 ( V_36 , V_43 , V_1122 ) ;
F_13 ( V_36 , V_40 , V_1121 ) ;
} else if ( V_1 == 1 ) {
V_1122 = ( T_2 ) ( * ( V_831 + 2 ) ) |
( T_2 ) ( * ( V_831 + 3 ) ) << 8 |
( T_2 ) ( * ( V_831 + 4 ) ) << 16 |
( T_2 ) ( * ( V_831 + 5 ) ) << 24 ;
F_13 ( V_36 , V_43 , V_1122 ) ;
F_13 ( V_36 , V_40 , V_1121 ) ;
} else {
if ( V_1120 != NULL ) {
F_13 ( V_36 , V_43 , ( T_2 ) ( * ( V_1120 + V_1 - 2 ) ) ) ;
F_13 ( V_36 , V_40 , V_1121 ) ;
}
}
}
}
