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
int F_28 ( struct V_35 * V_36 , int V_45 , T_3 * V_42 )
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
void F_40 ( void )
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
void F_49 ( struct V_35 * V_36 )
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
void F_52 ( struct V_35 * V_36 )
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
T_2 F_64 ( struct V_141 * V_142 )
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
T_2 F_94 ( struct V_35 * V_36 ,
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
#ifdef F_134
int V_1 ;
F_135 ( L_56 , V_189 ) ;
for ( V_1 = 0 ; V_1 < 8 ; V_1 ++ )
F_135 ( L_57 , V_383 [ V_1 ] ) ;
F_135 ( L_58 ) ;
#endif
F_71 ( V_281 , V_7 -> V_48 , F_136 ( V_7 -> V_48 , V_372 ) ,
V_150 -> V_42 , V_150 -> V_209 , F_117 , V_150 ) ;
V_46 = F_75 ( V_281 , V_198 ) ;
if ( ! V_46 ) {
return 0 ;
} else {
F_137 ( L_59 , V_46 ) ;
return - 1 ;
}
}
T_1 F_113 ( T_1 V_278 )
{
T_1 V_268 = 0x0 ;
switch ( V_278 ) {
case V_384 :
V_268 = V_385 ;
break;
case V_386 :
V_268 = V_387 ;
break;
case V_388 :
V_268 = V_389 ;
break;
case V_390 :
V_268 = V_391 ;
break;
case V_392 :
V_268 = V_393 ;
break;
case V_289 :
V_268 = V_394 ;
break;
case V_203 :
V_268 = V_395 ;
break;
case V_396 :
V_268 = V_397 ;
break;
default:
F_9 ( V_27 , L_60 , V_278 ) ;
break;
}
return V_268 ;
}
T_1 F_111 ( T_1 V_189 )
{
T_1 V_200 = V_398 ;
switch ( V_189 ) {
case V_305 : V_200 = V_398 ; break;
case V_307 : V_200 = V_399 ; break;
case V_309 : V_200 = V_400 ; break;
case V_311 : V_200 = V_401 ; break;
case V_313 : V_200 = V_402 ; break;
case V_315 : V_200 = V_403 ; break;
case V_317 : V_200 = V_404 ; break;
case V_319 : V_200 = V_405 ; break;
case V_321 : V_200 = V_406 ; break;
case V_323 : V_200 = V_407 ; break;
case V_325 : V_200 = V_408 ; break;
case V_327 : V_200 = V_409 ; break;
case V_410 : V_200 = V_411 ; break;
case V_412 : V_200 = V_413 ; break;
case V_414 : V_200 = V_415 ; break;
case V_416 : V_200 = V_417 ; break;
case V_418 : V_200 = V_419 ; break;
case V_420 : V_200 = V_421 ; break;
case V_422 : V_200 = V_423 ; break;
case V_424 : V_200 = V_425 ; break;
case V_426 : V_200 = V_427 ; break;
case V_428 : V_200 = V_429 ; break;
case V_430 : V_200 = V_431 ; break;
case V_432 : V_200 = V_433 ; break;
case V_434 : V_200 = V_435 ; break;
case V_436 : V_200 = V_437 ; break;
case V_438 : V_200 = V_439 ; break;
case V_440 : V_200 = V_441 ; break;
case ( 0x80 | 0x20 ) : V_200 = V_442 ; break;
default: break;
}
return V_200 ;
}
T_1 F_112 ( T_1 V_222 , T_1 V_224 , T_4 * V_201 )
{
T_1 V_443 ;
V_443 = ( V_222 == 1 ) ? ( ( V_201 -> V_444 ) ? 1 : 0 ) : ( ( V_201 -> V_445 ) ? 1 : 0 ) ;
if ( V_222 == 1 && V_224 != V_441 )
V_443 = 0 ;
return V_443 ;
}
static void F_138 ( struct V_147 * V_281 )
{
return;
}
short F_102 ( struct V_35 * V_36 , struct V_149 * V_150 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_4 * V_201 = ( T_4 * ) ( V_150 -> V_158 + V_202 ) ;
T_9 * V_446 = ( T_9 * ) V_150 -> V_42 ;
T_6 * V_216 = ( T_6 * ) ( V_150 -> V_42 + V_207 ) ;
struct V_47 * V_48 = V_7 -> V_48 ;
int V_447 ;
int V_46 ;
struct V_147 * V_281 = NULL , * V_448 = NULL ;
unsigned int V_372 ;
V_447 = F_38 ( & V_7 -> V_82 [ V_201 -> V_111 ] ) ;
if ( V_447 > V_113 ) {
F_110 ( V_36 , L_61 ) ;
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
V_216 -> V_449 = ( V_201 -> V_221 & 0x1f ) << 1 ;
#endif
memset ( V_446 , 0 , sizeof( T_9 ) ) ;
V_446 -> V_381 = 0 ;
V_446 -> V_377 = 1 ;
V_446 -> V_254 = sizeof( T_6 ) + 8 ;
#ifdef F_119
if ( V_201 -> V_219 )
V_446 -> V_255 = V_201 -> V_220 ;
else
#endif
{
V_446 -> V_255 = ( V_150 -> V_209 - V_450 ) & 0xffff ;
}
V_446 -> V_256 = 0 ;
V_446 -> V_257 = V_201 -> V_258 ;
V_446 -> V_259 = 1 ;
V_446 -> V_260 = 0x0 ;
if ( V_201 -> V_261 ) {
switch ( V_7 -> V_12 -> V_262 ) {
case V_263 :
case V_264 :
V_446 -> V_260 = 0x1 ;
V_446 -> V_259 = 0 ;
break;
case V_265 :
V_446 -> V_260 = 0x2 ;
V_446 -> V_259 = 0 ;
break;
case V_266 :
V_446 -> V_260 = 0x3 ;
V_446 -> V_259 = 0 ;
break;
case V_267 :
V_446 -> V_260 = 0x0 ;
V_446 -> V_259 = 1 ;
break;
}
}
V_446 -> V_268 = F_113 ( V_201 -> V_111 ) ;
V_446 -> V_269 = sizeof( T_6 ) ;
V_446 -> V_270 = V_201 -> V_271 ;
V_446 -> V_272 = V_201 -> V_273 ;
V_446 -> V_375 = 1 ;
V_446 -> V_376 = 1 ;
V_446 -> V_274 = 1 ;
#ifdef F_119
if ( V_201 -> V_219 ) {
V_446 -> V_379 = V_201 -> V_220 + sizeof( T_6 ) ;
} else
#endif
{
V_446 -> V_379 = ( T_2 ) ( V_150 -> V_209 - V_207 ) ;
}
#ifndef F_133
V_372 = F_130 ( V_7 , V_201 -> V_111 ) ;
#else
V_372 = 0x5 ;
#endif
F_71 ( V_281 , V_48 ,
F_136 ( V_48 , V_372 ) , V_150 -> V_42 ,
V_150 -> V_209 , F_117 , V_150 ) ;
V_46 = F_75 ( V_281 , V_198 ) ;
if ( ! V_46 ) {
bool V_451 = false ;
T_1 V_452 = 0 ;
if ( V_48 -> V_453 == V_454 ) {
if ( V_150 -> V_209 > 0 && V_150 -> V_209 % 512 == 0 )
V_451 = true ;
} else {
if ( V_150 -> V_209 > 0 && V_150 -> V_209 % 64 == 0 )
V_451 = true ;
}
if ( V_451 ) {
V_448 = F_69 ( 0 , V_198 ) ;
if ( ! V_448 ) {
F_9 ( V_27 , L_62 ) ;
return - V_374 ;
}
F_71 ( V_448 , V_48 ,
F_136 ( V_48 , V_372 ) , & V_452 ,
0 , F_138 , V_36 ) ;
V_46 = F_75 ( V_448 , V_198 ) ;
if ( V_46 ) {
F_9 ( V_27 , L_63 , F_38 ( & V_7 -> V_82 [ V_201 -> V_111 ] ) , V_46 ) ;
return - 1 ;
}
}
V_36 -> V_282 = V_283 ;
F_131 ( & V_7 -> V_82 [ V_201 -> V_111 ] ) ;
return 0 ;
} else {
F_9 ( V_27 , L_64 , F_38 ( & V_7 -> V_82 [ V_201 -> V_111 ] ) ,
V_46 ) ;
return - 1 ;
}
}
short F_139 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
V_7 -> V_298 = F_140 ( sizeof( struct V_147 * ) * ( V_154 + 1 ) ,
V_156 ) ;
if ( V_7 -> V_298 == NULL )
return - V_374 ;
#ifndef F_141
for ( V_1 = 0 ; V_1 < ( V_154 + 1 ) ; V_1 ++ ) {
V_7 -> V_298 [ V_1 ] = F_69 ( 0 , V_156 ) ;
V_7 -> V_298 [ V_1 ] -> V_197 = F_140 ( V_155 , V_156 ) ;
V_7 -> V_298 [ V_1 ] -> V_455 = V_155 ;
}
#endif
#ifdef F_142
{
long V_456 = 0 ;
void * V_457 , * V_458 ;
V_7 -> V_298 [ 16 ] = F_69 ( 0 , V_156 ) ;
V_7 -> V_457 = F_140 ( 16 , V_156 ) ;
V_457 = V_7 -> V_457 ;
V_456 = ( ( long ) V_457 ) & 3 ;
if ( V_456 ) {
V_458 = V_457 + 4 - V_456 ;
V_7 -> V_298 [ 16 ] -> V_455 = 16 - 4 + V_456 ;
} else {
V_458 = V_457 ;
V_7 -> V_298 [ 16 ] -> V_455 = 16 ;
}
V_7 -> V_298 [ 16 ] -> V_197 = V_458 ;
}
#endif
memset ( V_7 -> V_298 , 0 , sizeof( struct V_147 * ) * V_154 ) ;
V_7 -> V_459 = F_143 ( V_154 , sizeof( struct V_149 * ) ,
V_156 ) ;
if ( ! V_7 -> V_459 ) {
F_144 ( V_7 -> V_298 ) ;
V_7 -> V_459 = NULL ;
V_7 -> V_298 = NULL ;
F_137 ( L_65 ) ;
return - V_374 ;
}
F_110 ( V_36 , L_66 ) ;
return 0 ;
}
void F_145 ( struct V_35 * V_36 )
{
int V_1 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
if ( V_7 -> V_298 ) {
for ( V_1 = 0 ; V_1 < ( V_154 + 1 ) ; V_1 ++ ) {
F_82 ( V_7 -> V_298 [ V_1 ] ) ;
F_89 ( V_7 -> V_298 [ V_1 ] ) ;
}
F_144 ( V_7 -> V_298 ) ;
V_7 -> V_298 = NULL ;
}
F_144 ( V_7 -> V_457 ) ;
V_7 -> V_457 = NULL ;
if ( V_7 -> V_459 ) {
F_144 ( V_7 -> V_459 ) ;
V_7 -> V_459 = 0 ;
}
}
void F_145 ( struct V_35 * V_36 )
{
int V_1 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
#ifndef F_141
if ( V_7 -> V_298 ) {
for ( V_1 = 0 ; V_1 < ( V_154 + 1 ) ; V_1 ++ ) {
F_82 ( V_7 -> V_298 [ V_1 ] ) ;
F_144 ( V_7 -> V_298 [ V_1 ] -> V_197 ) ;
F_89 ( V_7 -> V_298 [ V_1 ] ) ;
}
F_144 ( V_7 -> V_298 ) ;
V_7 -> V_298 = NULL ;
}
#else
F_144 ( V_7 -> V_298 ) ;
V_7 -> V_298 = NULL ;
F_144 ( V_7 -> V_457 ) ;
V_7 -> V_457 = NULL ;
if ( V_7 -> V_459 ) {
F_144 ( V_7 -> V_459 ) ;
V_7 -> V_459 = 0 ;
}
#endif
}
void F_146 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
if ( V_11 -> V_126 == V_127 ) {
F_124 ( V_36 ) ;
F_147 ( V_36 ) ;
if ( ( V_263 == V_11 -> V_262 ) || ( V_264 == V_11 -> V_262 ) )
F_148 ( V_36 ) ;
}
if ( V_11 -> V_128 == V_129 || V_11 -> V_128 == V_132 ) {
T_2 V_460 = 0 ;
F_16 ( V_36 , V_161 , & V_460 ) ;
if ( V_7 -> V_12 -> V_126 == V_127 )
V_7 -> V_461 = V_460 |= V_172 ;
else
V_7 -> V_461 = V_460 &= ~ V_172 ;
F_13 ( V_36 , V_161 , V_460 ) ;
}
}
void F_149 ( struct V_462 * V_463 )
{
struct V_6 * V_7 = F_150 ( V_463 , struct V_6 , V_464 . V_463 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_58 * V_300 = & V_11 -> V_302 ;
if ( V_11 -> V_275 -> V_465 )
F_151 ( V_11 , V_300 ) ;
V_11 -> V_275 -> V_341 = V_300 -> V_466 . V_467 ;
F_123 ( V_36 , V_300 -> V_468 ) ;
}
void F_152 ( struct V_462 * V_463 )
{
struct V_6 * V_7 = F_150 ( V_463 , struct V_6 , V_469 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
struct V_470 * V_471 = & V_7 -> V_12 -> V_302 . V_472 . V_473 ;
T_1 V_116 = V_7 -> V_12 -> V_302 . V_116 ;
T_1 V_474 ;
T_2 V_475 ;
int V_1 ;
if ( V_7 == NULL )
return;
F_153 ( & V_7 -> V_476 ) ;
if ( V_7 -> V_12 -> V_126 != V_127 )
goto V_477;
F_9 ( V_478 , L_67 ) ;
for ( V_1 = 0 ; V_1 < V_479 ; V_1 ++ ) {
V_474 = V_471 -> V_480 [ V_1 ] * ( ( V_116 & ( V_337 | V_338 ) ) ? 9 : 20 ) + V_481 ;
V_475 = ( ( ( ( T_2 ) ( V_471 -> V_482 [ V_1 ] ) ) << V_483 ) |
( ( ( T_2 ) ( V_471 -> V_484 [ V_1 ] ) ) << V_485 ) |
( ( ( T_2 ) ( V_471 -> V_486 [ V_1 ] ) ) << V_487 ) |
( ( T_2 ) V_474 << V_488 ) ) ;
F_13 ( V_36 , V_489 [ V_1 ] , V_475 ) ;
}
V_477:
F_154 ( & V_7 -> V_476 ) ;
}
static int F_155 ( struct V_6 * V_7 ,
int V_490 ,
struct V_58 * V_491 )
{
int V_200 = 0 ;
T_2 V_492 = sizeof( struct V_470 ) ;
if ( V_7 -> V_12 -> V_126 != V_127 )
return V_200 ;
if ( ( V_7 -> V_12 -> V_128 != V_129 ) )
return V_200 ;
if ( V_491 -> V_167 & V_493 ) {
if ( V_490 &&
( V_491 -> V_167 & V_494 ) )
V_491 -> V_472 . V_495 = V_491 -> V_472 . V_496 ;
if ( ( V_491 -> V_472 . V_495 == 1 ) && ( V_490 == 1 ) &&
( V_491 -> V_167 & V_494 ) &&
( V_491 -> V_472 . V_497 !=
V_491 -> V_472 . V_498 ) ) {
V_491 -> V_472 . V_497 =
V_491 -> V_472 . V_498 ;
F_156 ( V_7 -> V_499 , & V_7 -> V_469 ) ;
F_9 ( V_478 , L_68
L_69 ) ;
}
} else {
memcpy ( & V_7 -> V_12 -> V_302 . V_472 . V_473 ,
& V_500 , V_492 ) ;
if ( ( V_491 -> V_472 . V_495 == 1 ) && ( V_490 == 1 ) ) {
F_156 ( V_7 -> V_499 , & V_7 -> V_469 ) ;
F_9 ( V_478 , L_70 ) ;
}
V_491 -> V_472 . V_495 = 0 ;
V_491 -> V_472 . V_496 = 0 ;
}
return 0 ;
}
static int F_157 ( struct V_35 * V_36 ,
struct V_501 * V_502 ,
struct V_58 * V_491 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
F_155 ( V_7 , 1 , V_491 ) ;
F_158 ( V_7 -> V_499 , & V_7 -> V_464 , 0 ) ;
return 0 ;
}
static int F_159 ( struct V_6 * V_7 ,
struct V_58 * V_491 )
{
int V_200 = 0 ;
unsigned long V_167 ;
T_2 V_492 = sizeof( struct V_470 ) ;
int V_503 = 0 ;
if ( ( V_7 == NULL ) || ( V_491 == NULL ) )
return V_200 ;
if ( V_7 -> V_12 -> V_126 != V_127 )
return V_200 ;
if ( ( V_7 -> V_12 -> V_128 != V_129 ) )
return V_200 ;
F_100 ( & V_7 -> V_12 -> V_504 , V_167 ) ;
if ( V_491 -> V_167 & V_494 ) {
memcpy ( & V_7 -> V_12 -> V_302 . V_472 . V_473 ,
& V_491 -> V_472 . V_473 ,
sizeof( struct V_470 ) ) ;
V_7 -> V_12 -> V_302 . V_472 . V_495 = 1 ;
V_503 = 1 ;
V_7 -> V_12 -> V_302 . V_472 . V_497 =
V_7 -> V_12 -> V_302 . V_472 . V_498 ;
V_7 -> V_12 -> V_302 . V_472 . V_498 =
V_491 -> V_472 . V_498 ;
} else {
memcpy ( & V_7 -> V_12 -> V_302 . V_472 . V_473 ,
& V_500 , V_492 ) ;
V_7 -> V_12 -> V_302 . V_472 . V_495 = 0 ;
V_7 -> V_12 -> V_302 . V_472 . V_496 = 0 ;
V_503 = 1 ;
}
F_103 ( & V_7 -> V_12 -> V_504 , V_167 ) ;
F_9 ( V_478 , L_71 , V_28 , V_491 -> V_167 , V_7 -> V_12 -> V_302 . V_472 . V_495 ) ;
if ( V_503 == 1 )
F_156 ( V_7 -> V_499 , & V_7 -> V_469 ) ;
return V_200 ;
}
static int F_160 ( struct V_35 * V_36 ,
struct V_505 * V_506 ,
struct V_58 * V_491 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
F_159 ( V_7 , V_491 ) ;
return 0 ;
}
void F_147 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
T_1 * V_507 = V_11 -> V_508 ;
T_2 V_509 = 0 ;
T_1 V_510 = 0 ;
F_122 ( V_36 , ( T_3 * ) ( & V_509 ) ) ;
V_509 |= ( * ( T_3 * ) ( V_507 ) ) << 12 ;
switch ( V_11 -> V_116 ) {
case V_511 :
V_509 &= 0x00000FF0 ;
break;
case V_512 :
V_509 &= 0x0000000F ;
break;
case V_337 :
V_509 &= 0x00000FF7 ;
break;
case V_338 :
case V_513 :
if ( V_11 -> V_275 -> V_514 == 0 ) {
V_509 &= 0x0007F007 ;
} else {
if ( V_7 -> V_515 == V_516 )
V_509 &= 0x000FF007 ;
else
V_509 &= 0x0F81F007 ;
}
break;
default:
break;
}
V_509 &= 0x0FFFFFFF ;
if ( V_11 -> V_275 -> V_517 && V_11 -> V_275 -> V_518 )
V_509 |= 0x80000000 ;
else if ( ! V_11 -> V_275 -> V_517 && V_11 -> V_275 -> V_519 )
V_509 |= 0x80000000 ;
F_13 ( V_36 , V_520 + V_510 * 4 , V_509 ) ;
F_24 ( V_36 , V_521 , 1 ) ;
}
bool F_161 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_58 * V_491 = & V_11 -> V_302 ;
int V_61 = V_11 -> V_61 ;
struct V_522 * V_523 ;
int V_524 ;
V_523 = V_11 -> V_523 [ V_11 -> V_525 ] ;
V_524 = ( V_491 -> V_468 & V_526 ) || ( V_11 -> V_527 && V_523 && V_523 -> V_528 && ( 0 == strcmp ( V_523 -> V_528 -> V_106 , L_72 ) ) ) ;
if ( V_524 && ( V_61 == 0 ) ) {
return false ;
} else if ( ( V_61 != 0 ) ) {
if ( ( ( V_11 -> V_529 [ 0 ] == 0xdd ) && ( ! memcmp ( & ( V_11 -> V_529 [ 14 ] ) , V_530 , 4 ) ) ) || ( ( V_11 -> V_529 [ 0 ] == 0x30 ) && ( ! memcmp ( & V_11 -> V_529 [ 10 ] , V_531 , 4 ) ) ) )
return true ;
else
return false ;
} else {
return true ;
}
return true ;
}
bool F_162 ( struct V_35 * V_36 )
{
bool V_532 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
if ( V_11 -> V_533 == true )
V_532 = true ;
else
V_532 = false ;
return V_532 ;
}
void F_163 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
if ( V_11 -> V_116 == V_534 || V_11 -> V_116 == V_535 )
memcpy ( V_11 -> V_536 , V_11 -> V_537 , 16 ) ;
else
memset ( V_11 -> V_536 , 0 , 16 ) ;
return;
}
T_1 F_164 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 V_200 = 0 ;
switch ( V_7 -> V_24 ) {
case V_25 :
case V_26 :
case V_538 :
V_200 = ( V_534 | V_539 | V_540 ) ;
break;
case V_541 :
V_200 = ( V_542 | V_535 ) ;
break;
default:
V_200 = V_540 ;
break;
}
return V_200 ;
}
void F_165 ( struct V_35 * V_36 , T_1 V_543 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 V_544 = F_164 ( V_36 ) ;
if ( ( V_543 == V_545 ) || ( ( V_543 & V_544 ) == 0 ) ) {
if ( V_544 & V_534 ) {
V_543 = V_534 ;
} else if ( V_544 & V_535 ) {
V_543 = V_535 ;
} else if ( ( V_544 & V_542 ) ) {
V_543 = V_542 ;
} else if ( ( V_544 & V_539 ) ) {
V_543 = V_539 ;
} else if ( ( V_544 & V_540 ) ) {
V_543 = V_540 ;
} else {
F_9 ( V_27 , L_73 , V_28 , V_544 ) ;
V_543 = V_540 ;
}
}
#ifdef F_166
F_167 ( V_546 , V_547 -> V_548 , & V_546 -> V_549 . V_550 . V_551 ) ;
#endif
V_7 -> V_12 -> V_116 = V_543 ;
if ( ( V_543 == V_534 ) || ( V_543 == V_535 ) )
V_7 -> V_12 -> V_275 -> V_552 = 1 ;
else
V_7 -> V_12 -> V_275 -> V_552 = 0 ;
F_9 ( V_95 , L_74 , V_543 ) ;
F_163 ( V_7 ) ;
}
static void F_168 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 V_1 ;
V_7 -> V_297 = V_296 ;
V_7 -> V_139 = 1 ;
V_7 -> V_12 -> V_116 = V_545 ;
V_7 -> V_12 -> V_128 = V_129 ;
V_7 -> V_12 -> V_553 = 0 ;
V_7 -> V_554 = V_555 ;
V_7 -> V_556 = V_557 ;
V_7 -> V_12 -> V_558 = V_559 ;
V_7 -> V_12 -> V_189 = 110 ;
V_7 -> V_12 -> V_560 = 1 ;
V_7 -> V_561 = ( V_36 -> V_167 & V_168 ) ? 1 : 0 ;
V_7 -> V_562 = 6 ;
V_7 -> V_563 = 1 ;
V_7 -> V_564 = V_565 ;
V_7 -> V_566 = 0 ;
V_7 -> V_567 = false ;
V_7 -> V_568 = false ;
V_7 -> V_12 -> V_569 = 0 ;
V_7 -> V_12 -> V_302 . V_353 = V_570 ;
V_7 -> V_12 -> V_128 = V_129 ;
V_7 -> V_12 -> V_571 = V_572 |
V_573 | V_574 |
V_575 | V_576 |
V_577 ;
V_7 -> V_12 -> V_578 = 1 ;
V_7 -> V_12 -> V_579 = V_580 | V_581 ;
V_7 -> V_12 -> V_527 = 1 ;
V_7 -> V_12 -> V_582 = 1 ;
V_7 -> V_12 -> V_583 = NULL ;
V_7 -> V_12 -> V_584 = NULL ;
V_7 -> V_12 -> V_292 = F_104 ;
V_7 -> V_12 -> V_585 = F_61 ;
V_7 -> V_12 -> V_586 = F_146 ;
V_7 -> V_12 -> V_587 = F_98 ;
V_7 -> V_12 -> V_588 = F_96 ;
V_7 -> V_12 -> V_589 = F_97 ;
V_7 -> V_12 -> V_590 = 0 ;
V_7 -> V_12 -> V_591 = V_592 ;
V_7 -> V_12 -> F_54 = F_54 ;
V_7 -> V_12 -> V_206 = V_450 ;
V_7 -> V_12 -> V_593 = 1 ;
V_7 -> V_12 -> V_594 = V_595 ;
V_7 -> V_12 -> V_596 = F_160 ;
V_7 -> V_12 -> V_597 = F_157 ;
V_7 -> V_12 -> V_598 = F_161 ;
V_7 -> V_12 -> V_599 = F_162 ;
V_7 -> V_12 -> V_600 = F_165 ;
V_7 -> V_12 -> V_601 = V_602 ;
V_7 -> V_603 = V_604 ;
#ifdef F_166
if ( V_605 -> V_606 ) {
V_547 -> V_607 = 7 ;
V_547 -> V_608 = 7 ;
}
#endif
V_7 -> V_607 = 0x30 ;
V_7 -> V_608 = 0x30 ;
V_7 -> V_609 = 7 ;
V_7 -> V_610 = 0 ;
V_7 -> V_611 =
( V_612 << V_613 ) |
( V_7 -> V_607 << V_614 ) |
( V_7 -> V_608 << V_615 ) |
( false ? V_616 : 0 ) ;
#ifdef F_166
if ( V_605 -> V_606 )
V_547 -> V_461 = V_547 -> V_617 |
V_163 | V_164 |
V_618 |
V_165 | V_166 | V_171 |
V_173 | V_176 |
( ( T_2 ) 7 << V_181 ) |
( V_547 -> V_609 << V_619 ) |
( V_547 -> V_609 == 7 ? V_620 : 0 ) ;
else
#endif
V_7 -> V_461 =
V_163 | V_164 |
V_618 |
V_165 | V_166 | V_171 |
( ( T_2 ) 7 << V_181 ) |
( V_7 -> V_609 << V_179 ) |
( V_7 -> V_609 == 7 ? V_182 : 0 ) ;
V_7 -> V_621 = 0 ;
V_7 -> V_622 = F_169 ( sizeof( V_623 ) , V_156 ) ;
F_170 ( & V_7 -> V_153 ) ;
F_170 ( & V_7 -> V_187 ) ;
for ( V_1 = 0 ; V_1 < V_624 ; V_1 ++ )
F_170 ( & V_7 -> V_12 -> V_290 [ V_1 ] ) ;
for ( V_1 = 0 ; V_1 < V_624 ; V_1 ++ )
F_170 ( & V_7 -> V_12 -> V_625 [ V_1 ] ) ;
for ( V_1 = 0 ; V_1 < V_624 ; V_1 ++ )
F_170 ( & V_7 -> V_12 -> V_279 [ V_1 ] ) ;
V_7 -> V_140 = V_626 ;
}
static void F_171 ( struct V_6 * V_7 )
{
F_172 ( & V_7 -> V_204 ) ;
F_172 ( & V_7 -> V_627 ) ;
F_173 ( & V_7 -> V_628 , 1 ) ;
F_173 ( & V_7 -> V_629 , 1 ) ;
F_174 ( & V_7 -> V_476 ) ;
}
static void F_175 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
V_7 -> V_499 = F_176 ( V_630 ) ;
F_177 ( & V_7 -> V_114 , V_631 ) ;
F_178 ( & V_7 -> V_632 , V_633 ) ;
F_178 ( & V_7 -> V_634 , V_635 ) ;
F_178 ( & V_7 -> V_636 , V_637 ) ;
F_178 ( & V_7 -> V_464 , F_149 ) ;
F_178 ( & V_7 -> V_638 , V_639 ) ;
F_177 ( & V_7 -> V_469 , F_152 ) ;
F_179 ( & V_7 -> V_196 ,
( void (*) ( unsigned long ) ) V_640 ,
( unsigned long ) V_7 ) ;
}
static void F_180 ( struct V_35 * V_36 )
{
T_3 V_641 = 0 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
F_9 ( V_115 , L_75 , V_28 ) ;
F_28 ( V_36 , V_118 , & V_641 ) ;
F_9 ( V_115 , L_76 , V_118 , V_641 ) ;
V_7 -> V_642 = ( V_641 & V_643 ) ? V_644 : V_645 ;
F_9 ( V_115 , L_77 , V_28 , V_7 -> V_642 ) ;
}
static inline T_3 F_181 ( T_3 * V_42 )
{
T_3 V_332 = * V_42 ;
* V_42 = ( V_332 >> 8 ) | ( V_332 << 8 ) ;
return * V_42 ;
}
static void F_182 ( struct V_35 * V_36 )
{
T_3 V_646 = 0 ;
T_1 V_647 [ 6 ] = { 0x00 , 0xe0 , 0x4c , 0x00 , 0x00 , 0x02 } ;
T_1 V_648 = false ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_3 V_649 = 0 ;
int V_1 ;
F_9 ( V_115 , L_75 , V_28 ) ;
V_646 = F_58 ( V_36 , 0 ) ;
F_9 ( V_115 , L_78 , V_646 ) ;
if ( V_646 != V_650 ) {
F_9 ( V_27 , L_79 , V_646 , V_650 ) ;
} else {
V_648 = true ;
}
if ( V_648 ) {
V_649 = F_58 ( V_36 , ( V_651 >> 1 ) ) ;
V_7 -> V_652 = F_181 ( & V_649 ) ;
V_7 -> V_653 = F_58 ( V_36 , ( V_654 >> 1 ) ) ;
V_649 = F_58 ( V_36 , ( V_655 >> 1 ) ) ;
V_7 -> V_656 = ( ( V_649 & 0xff00 ) >> 8 ) ;
V_7 -> V_657 = true ;
V_7 -> V_658 = F_58 ( V_36 , ( V_659 >> 1 ) ) >> 8 ;
} else {
V_7 -> V_652 = 0 ;
V_7 -> V_653 = 0 ;
V_7 -> V_660 = V_661 ;
V_7 -> V_656 = 0 ;
V_7 -> V_658 = 0 ;
}
F_9 ( V_115 , L_80 , V_7 -> V_652 , V_7 -> V_653 , V_7 -> V_658 , V_7 -> V_656 ) ;
V_7 -> V_29 = V_7 -> V_656 ;
if ( V_648 ) {
int V_1 ;
for ( V_1 = 0 ; V_1 < 6 ; V_1 += 2 ) {
T_3 V_332 = 0 ;
V_332 = F_58 ( V_36 , ( T_3 ) ( ( V_662 + V_1 ) >> 1 ) ) ;
* ( T_3 * ) ( & V_36 -> V_663 [ V_1 ] ) = V_332 ;
}
} else {
memcpy ( V_36 -> V_663 , V_647 , 6 ) ;
}
F_9 ( V_115 , L_81 , V_36 -> V_663 ) ;
V_7 -> V_515 = V_664 ;
V_7 -> V_24 = V_26 ;
if ( V_7 -> V_660 == ( T_1 ) V_665 ) {
if ( V_648 )
V_7 -> V_666 = ( F_58 ( V_36 , ( V_667 >> 1 ) ) & 0xff00 ) >> 8 ;
else
V_7 -> V_666 = V_668 ;
F_9 ( V_115 , L_82 , V_7 -> V_666 ) ;
if ( V_648 )
V_7 -> V_669 = ( T_1 ) ( F_58 ( V_36 , ( V_670 >> 1 ) ) & 0x00ff ) ;
else
V_7 -> V_669 = V_671 ;
F_9 ( V_115 , L_83 , V_7 -> V_669 ) ;
V_7 -> V_672 = V_7 -> V_669 * 100 ;
if ( V_648 )
V_7 -> V_673 = ( F_58 ( V_36 , ( V_674 >> 1 ) ) & 0x0f00 ) >> 8 ;
else
V_7 -> V_673 = V_675 ;
F_9 ( V_115 , L_84 , V_7 -> V_673 ) ;
if ( V_648 )
V_7 -> V_676 = ( F_58 ( V_36 , ( V_677 >> 1 ) ) & 0x0f ) ;
else
V_7 -> V_676 = V_678 ;
F_9 ( V_115 , L_85 , V_7 -> V_676 ) ;
if ( V_648 )
V_7 -> V_679 = ( F_58 ( V_36 , ( V_680 >> 1 ) ) & 0xff00 ) >> 8 ;
else
V_7 -> V_679 = 1 ;
F_9 ( V_115 , L_86 , V_7 -> V_679 ) ;
if ( V_7 -> V_679 == 0 ) {
int V_1 ;
if ( V_648 )
V_7 -> V_681 = ( F_58 ( V_36 , ( V_682 >> 1 ) ) & 0xff ) >> 8 ;
else
V_7 -> V_681 = 0x10 ;
F_9 ( V_115 , L_87 , V_7 -> V_681 ) ;
for ( V_1 = 0 ; V_1 < 3 ; V_1 ++ ) {
if ( V_648 ) {
V_649 = F_58 ( V_36 , ( V_683 + V_1 ) >> 1 ) ;
if ( ( ( V_683 + V_1 ) % 2 ) == 0 )
V_649 = V_649 & 0x00ff ;
else
V_649 = ( V_649 & 0xff00 ) >> 8 ;
} else {
V_649 = 0x10 ;
}
V_7 -> V_684 [ V_1 ] = ( T_1 ) V_649 ;
F_9 ( V_115 , L_88 , V_1 , V_7 -> V_681 ) ;
}
} else if ( V_7 -> V_679 == 1 ) {
if ( V_648 ) {
V_649 = F_58 ( V_36 , ( V_685 >> 1 ) ) ;
V_649 = ( V_649 & 0xff00 ) >> 8 ;
} else {
V_649 = 0x10 ;
}
V_7 -> V_686 [ 0 ] = ( T_1 ) V_649 ;
if ( V_648 )
V_649 = F_58 ( V_36 , ( V_685 + 2 ) >> 1 ) ;
else
V_649 = 0x1010 ;
* ( ( T_3 * ) ( & V_7 -> V_686 [ 1 ] ) ) = V_649 ;
if ( V_648 )
V_649 = F_58 ( V_36 , ( V_687 >> 1 ) ) ;
else
V_649 = 0x1010 ;
* ( ( T_3 * ) ( & V_7 -> V_684 [ 0 ] ) ) = V_649 ;
if ( V_648 )
V_649 = F_58 ( V_36 , ( V_687 + 2 ) >> 1 ) ;
else
V_649 = 0x10 ;
V_7 -> V_684 [ 2 ] = ( T_1 ) V_649 ;
}
for ( V_1 = 0 ; V_1 < 14 ; V_1 ++ ) {
if ( V_1 <= 3 )
V_7 -> V_688 [ V_1 ] = V_7 -> V_684 [ 0 ] ;
else if ( V_1 >= 4 && V_1 <= 9 )
V_7 -> V_688 [ V_1 ] = V_7 -> V_684 [ 1 ] ;
else
V_7 -> V_688 [ V_1 ] = V_7 -> V_684 [ 2 ] ;
}
for ( V_1 = 0 ; V_1 < 14 ; V_1 ++ ) {
if ( V_7 -> V_679 == 0 ) {
if ( V_1 <= 3 )
V_7 -> V_689 [ V_1 ] = V_7 -> V_684 [ 0 ] + ( V_7 -> V_681 - V_7 -> V_684 [ 1 ] ) ;
else if ( V_1 >= 4 && V_1 <= 9 )
V_7 -> V_689 [ V_1 ] = V_7 -> V_681 ;
else
V_7 -> V_689 [ V_1 ] = V_7 -> V_684 [ 2 ] + ( V_7 -> V_681 - V_7 -> V_684 [ 1 ] ) ;
} else if ( V_7 -> V_679 == 1 ) {
if ( V_1 <= 3 )
V_7 -> V_689 [ V_1 ] = V_7 -> V_686 [ 0 ] ;
else if ( V_1 >= 4 && V_1 <= 9 )
V_7 -> V_689 [ V_1 ] = V_7 -> V_686 [ 1 ] ;
else
V_7 -> V_689 [ V_1 ] = V_7 -> V_686 [ 2 ] ;
}
}
V_7 -> V_690 = V_7 -> V_673 ;
V_7 -> V_691 [ 0 ] = ( V_7 -> V_666 & 0xf ) ;
V_7 -> V_691 [ 1 ] = ( ( V_7 -> V_666 & 0xf0 ) >> 4 ) ;
V_7 -> V_692 = V_7 -> V_676 ;
V_7 -> V_693 [ 0 ] = V_7 -> V_669 ;
}
switch ( V_7 -> V_658 ) {
case V_694 :
V_7 -> V_695 = V_696 ;
break;
case V_697 :
V_7 -> V_695 = V_698 ;
break;
default:
V_7 -> V_695 = V_699 ;
break;
}
switch ( V_7 -> V_695 ) {
case V_696 :
V_7 -> V_700 = V_701 ;
break;
case V_698 :
V_7 -> V_700 = V_702 ;
break;
default:
V_7 -> V_700 = V_703 ;
break;
}
if ( V_7 -> V_515 == V_516 ) {
F_9 ( V_115 , L_89 ) ;
} else {
F_9 ( V_115 , L_90 ) ;
}
F_183 ( V_36 ) ;
F_9 ( V_115 , L_91 , V_28 ) ;
return;
}
short F_184 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
if ( V_7 -> V_29 > V_33 ) {
F_21 ( V_36 , L_92 ) ;
V_7 -> V_29 = 0 ;
}
F_9 ( V_95 , L_93 , V_7 -> V_29 ) ;
F_7 ( V_7 -> V_29 , V_7 ) ;
return 0 ;
}
short F_185 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
memset ( & ( V_7 -> V_67 ) , 0 , sizeof( struct V_704 ) ) ;
memset ( V_7 -> V_371 , 0 , 9 ) ;
#ifdef F_186
{
int V_1 = 0 ;
T_1 V_705 [] = { 3 , 2 , 1 , 0 , 4 , 8 , 7 , 6 , 5 } ;
memcpy ( V_7 -> V_371 , V_705 , 9 ) ;
}
#else
{
T_1 V_705 [] = { 3 , 2 , 1 , 0 , 4 , 4 , 0 , 4 , 4 } ;
memcpy ( V_7 -> V_371 , V_705 , 9 ) ;
}
#endif
F_168 ( V_36 ) ;
F_171 ( V_7 ) ;
F_175 ( V_36 ) ;
F_180 ( V_36 ) ;
F_182 ( V_36 ) ;
F_184 ( V_36 ) ;
F_187 ( V_36 ) ;
F_188 ( & V_7 -> V_706 ) ;
V_7 -> V_706 . V_42 = ( unsigned long ) V_36 ;
V_7 -> V_706 . V_707 = V_708 ;
if ( F_139 ( V_36 ) != 0 ) {
F_77 ( L_94 ) ;
return - V_374 ;
}
#ifdef F_189
F_57 ( V_36 ) ;
#endif
return 0 ;
}
void F_190 ( struct V_35 * V_36 )
{
T_2 V_709 = 0 , V_710 = 0 ;
T_1 V_711 = 0 , V_712 = 0 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_2 V_509 = 0 ;
switch ( V_7 -> V_12 -> V_116 ) {
case V_540 :
V_711 = V_713 ;
V_709 = V_714 ;
V_710 = V_714 ;
break;
case V_542 :
V_711 = V_715 | V_713 ;
V_709 = V_716 ;
V_710 = V_716 ;
break;
case V_539 :
V_711 = V_713 ;
V_709 = V_714 | V_716 ;
V_710 = V_714 | V_716 ;
break;
case V_545 :
#ifdef F_166
if ( V_605 -> V_606 ) {
V_711 = V_713 ;
V_709 = V_714 | V_716 ;
V_710 = V_714 | V_716 ;
}
else
#endif
{
V_711 = V_713 ;
V_709 = V_714 | V_716 | V_717 | V_718 ;
V_710 = V_714 | V_716 ;
}
break;
case V_534 :
V_711 = V_713 ;
V_709 = V_714 | V_716 | V_717 | V_718 ;
V_710 = V_714 | V_716 ;
break;
case V_535 :
V_711 = V_715 ;
V_709 = V_716 | V_717 | V_718 ;
V_710 = V_716 ;
break;
}
F_24 ( V_36 , V_719 , V_711 ) ;
V_509 = V_709 ;
if ( V_7 -> V_515 == V_516 )
V_509 &= ~ ( V_718 ) ;
F_13 ( V_36 , V_520 , V_509 ) ;
F_24 ( V_36 , V_521 , 1 ) ;
F_26 ( V_36 , 0x313 , & V_712 ) ;
V_710 = ( ( V_712 ) << 24 ) | ( V_710 & 0x00ffffff ) ;
F_13 ( V_36 , V_336 , V_710 ) ;
F_25 ( V_36 , V_720 ,
V_7 -> V_607 << V_721 |
V_7 -> V_608 << V_722 ) ;
}
bool F_191 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_2 V_723 = 0 ;
bool V_724 = true ;
T_1 V_725 = 0x0 ;
T_1 V_332 ;
F_9 ( V_95 , L_95 , V_28 ) ;
V_7 -> V_726 = V_727 ;
F_17 ( V_36 , 0x5f , 0x80 ) ;
F_63 ( 50 ) ;
F_17 ( V_36 , 0x5f , 0xf0 ) ;
F_17 ( V_36 , 0x5d , 0x00 ) ;
F_17 ( V_36 , 0x5e , 0x80 ) ;
F_24 ( V_36 , 0x17 , 0x37 ) ;
F_63 ( 10 ) ;
V_7 -> V_622 -> V_728 = V_729 ;
F_16 ( V_36 , V_730 , & V_723 ) ;
if ( V_7 -> V_622 -> V_728 == V_729 )
V_723 |= V_731 ;
else if ( V_7 -> V_622 -> V_728 == V_732 )
V_723 |= V_733 ;
else
F_9 ( V_27 , L_96 , V_28 , V_7 -> V_622 -> V_728 ) ;
F_13 ( V_36 , V_730 , V_723 ) ;
F_192 ( V_36 ) ;
V_7 -> V_734 = V_735 ;
F_16 ( V_36 , V_730 , & V_723 ) ;
if ( V_7 -> V_734 == V_735 )
V_723 = ( ( V_723 & V_736 ) | V_737 ) ;
else if ( V_7 -> V_734 == V_738 )
V_723 |= V_739 ;
else
F_9 ( V_27 , L_97 , V_28 , V_7 -> V_734 ) ;
F_13 ( V_36 , V_730 , V_723 ) ;
F_193 ( 500 ) ;
F_22 ( V_36 , 0x5f , & V_332 ) ;
F_17 ( V_36 , 0x5f , V_332 | 0x20 ) ;
F_190 ( V_36 ) ;
F_24 ( V_36 , V_184 , V_186 | V_185 ) ;
F_13 ( V_36 , V_740 , ( ( T_2 * ) V_36 -> V_663 ) [ 0 ] ) ;
F_25 ( V_36 , V_741 , ( ( T_3 * ) ( V_36 -> V_663 + 4 ) ) [ 0 ] ) ;
F_13 ( V_36 , V_161 , V_7 -> V_461 ) ;
F_13 ( V_36 , V_742 , V_743 << V_744 |
V_745 << V_746 |
V_747 << V_748 |
V_749 << V_750 ) ;
F_13 ( V_36 , V_751 , V_752 << V_753 |
V_754 << V_755 ) ;
F_13 ( V_36 , V_756 , V_757 |
V_758 << V_759 ) ;
F_13 ( V_36 , V_520 + 4 * 7 , ( V_716 | V_714 ) ) ;
F_24 ( V_36 , V_760 , 0x30 ) ;
if ( V_7 -> V_564 == V_565 )
F_165 ( V_36 , V_7 -> V_12 -> V_116 ) ;
if ( V_7 -> V_564 == V_565 ) {
F_12 ( V_36 ) ;
V_725 |= V_761 ;
V_725 |= V_762 ;
V_725 |= V_763 ;
F_24 ( V_36 , V_764 , V_725 ) ;
}
F_25 ( V_36 , V_350 , 2 ) ;
F_25 ( V_36 , V_352 , 100 ) ;
#define F_194 0x005e4332
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_479 ; V_1 ++ )
F_13 ( V_36 , V_489 [ V_1 ] , F_194 ) ;
}
#ifdef F_65
if ( V_7 -> V_564 == V_565 ) {
T_2 V_765 ;
T_7 V_275 = V_7 -> V_12 -> V_275 ;
V_765 = ( V_275 -> V_766 << 24 ) | ( V_275 -> V_767 << 16 ) |
( V_275 -> V_768 << 8 ) | ( V_275 -> V_769 ) ;
F_13 ( V_36 , 0x1a8 , V_765 ) ;
V_7 -> V_770 = true ;
}
#endif
F_195 ( V_36 ) ;
if ( V_7 -> V_660 == ( T_1 ) V_665 ) {
F_196 ( V_36 ) ;
F_197 ( V_36 , V_7 -> V_139 ) ;
}
V_724 = F_198 ( V_36 ) ;
if ( ! V_724 ) {
F_9 ( V_27 , L_98 , V_28 ) ;
return V_724 ;
}
F_9 ( V_95 , L_99 , V_28 ) ;
#ifdef F_166
if ( V_605 -> V_564 == V_565 ) {
if ( V_771 -> V_772 == TRUE ) {
F_9 ( ( V_95 | V_773 ) , V_774 , ( L_100 ) ) ;
F_199 ( V_605 , V_775 , V_776 ) ;
for ( V_777 = 0 ; V_777 < V_547 -> V_778 ; V_777 ++ )
F_200 ( V_605 , ( V_779 ) V_777 , 0x4 , 0xC00 , 0x0 ) ;
} else if ( V_771 -> V_780 > V_781 ) {
F_9 ( ( V_95 | V_773 ) , V_774 , ( L_101 , V_771 -> V_780 ) ) ;
F_199 ( V_605 , V_775 , V_771 -> V_780 ) ;
} else {
V_547 -> V_782 = V_783 ;
V_771 -> V_780 = 0 ;
F_9 ( ( V_95 | V_773 ) , V_774 , ( L_102 ) ) ;
}
} else {
if ( V_547 -> V_782 == V_775 ) {
F_199 ( V_605 , V_775 , V_771 -> V_780 ) ;
for ( V_777 = 0 ; V_777 < V_547 -> V_778 ; V_777 ++ )
F_200 ( V_605 , ( V_779 ) V_777 , 0x4 , 0xC00 , 0x0 ) ;
}
}
#endif
if ( V_7 -> V_564 == V_565 ) {
F_201 ( V_36 ) ;
F_9 ( V_95 , L_103 , V_28 ) ;
}
if ( V_7 -> V_12 -> V_569 )
V_7 -> V_726 = V_784 ;
else
V_7 -> V_726 = V_727 ;
F_202 ( V_36 ) ;
F_203 ( V_36 , V_785 , V_786 , 0x1 ) ;
F_203 ( V_36 , V_785 , V_787 , 0x1 ) ;
if ( V_7 -> V_564 == V_565 ) {
T_1 V_788 ;
F_26 ( V_36 , 0x301 , & V_788 ) ;
if ( V_788 == 0x03 ) {
V_7 -> V_789 = TRUE ;
F_9 ( V_790 , L_104 ) ;
} else {
V_7 -> V_789 = FALSE ;
F_9 ( V_790 , L_105 ) ;
}
F_204 ( V_36 ) ;
if ( V_7 -> V_789 == TRUE ) {
T_2 V_1 , V_791 ;
T_2 V_792 = F_205 ( V_36 , V_793 , V_794 ) ;
for ( V_1 = 0 ; V_1 < V_795 ; V_1 ++ ) {
if ( V_792 == V_7 -> V_796 [ V_1 ] . V_797 ) {
V_7 -> V_798 = ( T_1 ) V_1 ;
V_7 -> V_799 = ( T_1 ) V_1 ;
V_7 -> V_800 = V_7 -> V_798 ;
break;
}
}
V_791 = F_205 ( V_36 , V_801 , V_802 ) ;
for ( V_1 = 0 ; V_1 < V_803 ; V_1 ++ ) {
if ( V_791 == V_7 -> V_804 [ V_1 ] . V_805 [ 0 ] ) {
V_7 -> V_806 = ( T_1 ) V_1 ;
break;
}
}
V_7 -> V_807 = 0 ;
V_7 -> V_808 = 0 ;
V_7 -> V_809 = V_7 -> V_806 ;
}
}
F_24 ( V_36 , 0x87 , 0x0 ) ;
return V_724 ;
}
static struct V_810 * F_206 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
return & V_7 -> V_12 -> V_67 ;
}
bool F_207 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_3 V_811 ;
bool V_812 = FALSE ;
F_27 ( V_36 , 0x128 , & V_811 ) ;
F_9 ( V_813 , L_106 , V_28 , V_811 , V_7 -> V_814 ) ;
if ( V_7 -> V_814 == V_811 )
V_812 = TRUE ;
V_7 -> V_814 = V_811 ;
return V_812 ;
}
T_10 F_208 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 V_278 ;
bool V_815 = false ;
for ( V_278 = 0 ; V_278 <= V_289 ; V_278 ++ ) {
if ( V_278 == V_203 )
continue;
#ifdef F_119
if ( ( F_67 ( & V_7 -> V_12 -> V_290 [ V_278 ] ) == 0 ) && ( F_67 ( & V_7 -> V_12 -> V_625 [ V_278 ] ) == 0 ) && ( F_67 ( & V_7 -> V_12 -> V_279 [ V_278 ] ) == 0 ) )
#else
if ( ( F_67 ( & V_7 -> V_12 -> V_290 [ V_278 ] ) == 0 ) && ( F_67 ( & V_7 -> V_12 -> V_625 [ V_278 ] ) == 0 ) )
#endif
continue;
V_815 = true ;
}
if ( V_815 ) {
if ( F_207 ( V_36 ) ) {
F_9 ( V_813 , L_107 ) ;
return V_816 ;
}
}
return V_565 ;
}
bool F_209 ( struct V_35 * V_36 )
{
T_3 V_817 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
bool V_812 = FALSE ;
static T_1 V_818 ;
F_27 ( V_36 , 0x130 , & V_817 ) ;
F_9 ( V_813 , L_108 , V_28 , V_817 , V_7 -> V_819 ) ;
V_818 ++ ;
if ( V_7 -> V_820 >= ( V_821 + 5 ) ) {
V_818 = 0 ;
} else if ( V_7 -> V_820 < ( V_821 + 5 ) &&
( ( V_7 -> V_248 != V_822 && V_7 -> V_820 >= V_823 ) ||
( V_7 -> V_248 == V_822 && V_7 -> V_820 >= V_824 ) ) ) {
if ( V_818 < 2 )
return V_812 ;
else
V_818 = 0 ;
} else if ( ( ( V_7 -> V_248 != V_822 && V_7 -> V_820 < V_823 ) ||
( V_7 -> V_248 == V_822 && V_7 -> V_820 < V_824 ) ) &&
V_7 -> V_820 >= V_825 ) {
if ( V_818 < 4 )
return V_812 ;
else
V_818 = 0 ;
} else {
if ( V_818 < 8 )
return V_812 ;
else
V_818 = 0 ;
}
if ( V_7 -> V_819 == V_817 )
V_812 = TRUE ;
V_7 -> V_819 = V_817 ;
return V_812 ;
}
T_10 F_210 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
bool V_826 = FALSE ;
if ( V_7 -> V_563 > 1 )
V_826 = TRUE ;
if ( V_826 ) {
if ( F_209 ( V_36 ) ) {
F_9 ( V_813 , L_109 ) ;
return V_816 ;
}
}
return V_565 ;
}
T_10 F_211 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_10 V_827 = V_565 ;
T_10 V_828 = V_565 ;
T_11 V_829 ;
V_829 = V_7 -> V_12 -> V_782 ;
V_827 = F_208 ( V_36 ) ;
if ( V_829 != V_775 ||
( V_7 -> V_12 -> V_128 != V_132 ) ) {
V_828 = F_210 ( V_36 ) ;
}
if ( V_827 == V_830 || V_828 == V_830 ) {
return V_830 ;
} else if ( V_827 == V_816 || V_828 == V_816 ) {
F_9 ( V_813 , L_110 , V_28 ) ;
return V_816 ;
} else {
return V_565 ;
}
}
void F_212 ( struct V_35 * V_36 )
{
T_1 V_831 = 0 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 * V_832 = V_7 -> V_12 -> V_302 . V_349 ;
static T_1 V_833 [ 4 ] [ 6 ] = {
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x02 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x03 } } ;
static T_1 V_834 [] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
F_9 ( V_835 , L_111 ) ;
if ( ( V_7 -> V_12 -> V_262 == V_263 ) ||
( V_7 -> V_12 -> V_262 == V_264 ) ) {
for ( V_831 = 0 ; V_831 < 4 ; V_831 ++ ) {
V_832 = V_833 [ V_831 ] ;
F_213 ( V_36 , V_831 , V_831 ,
V_7 -> V_12 -> V_262 ,
V_832 , 0 , NULL ) ;
}
} else if ( V_7 -> V_12 -> V_262 == V_265 ) {
if ( V_7 -> V_12 -> V_128 == V_132 )
F_213 ( V_36 , 4 , 0 , V_7 -> V_12 -> V_262 ,
( T_1 * ) V_36 -> V_663 , 0 , NULL ) ;
else
F_213 ( V_36 , 4 , 0 , V_7 -> V_12 -> V_262 ,
V_832 , 0 , NULL ) ;
} else if ( V_7 -> V_12 -> V_262 == V_266 ) {
if ( V_7 -> V_12 -> V_128 == V_132 )
F_213 ( V_36 , 4 , 0 , V_7 -> V_12 -> V_262 ,
( T_1 * ) V_36 -> V_663 , 0 , NULL ) ;
else
F_213 ( V_36 , 4 , 0 , V_7 -> V_12 -> V_262 ,
V_832 , 0 , NULL ) ;
}
if ( V_7 -> V_12 -> V_836 == V_265 ) {
V_832 = V_834 ;
for ( V_831 = 1 ; V_831 < 4 ; V_831 ++ ) {
F_213 ( V_36 , V_831 , V_831 ,
V_7 -> V_12 -> V_836 ,
V_832 , 0 , NULL ) ;
}
if ( V_7 -> V_12 -> V_128 == V_132 )
F_213 ( V_36 , 0 , 0 , V_7 -> V_12 -> V_836 ,
V_833 [ 0 ] , 0 , NULL ) ;
} else if ( V_7 -> V_12 -> V_836 == V_266 ) {
V_832 = V_834 ;
for ( V_831 = 1 ; V_831 < 4 ; V_831 ++ ) {
F_213 ( V_36 , V_831 , V_831 ,
V_7 -> V_12 -> V_836 ,
V_832 , 0 , NULL ) ;
}
if ( V_7 -> V_12 -> V_128 == V_132 )
F_213 ( V_36 , 0 , 0 , V_7 -> V_12 -> V_836 ,
V_833 [ 0 ] , 0 , NULL ) ;
}
}
void F_214 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 V_837 = 0 ;
int V_838 = 0 ;
struct V_10 * V_11 = V_7 -> V_12 ;
if ( V_7 -> V_564 == V_565 ) {
V_839:
F_9 ( V_813 , L_112 ) ;
V_7 -> V_564 = V_816 ;
F_215 ( & V_7 -> V_628 ) ;
if ( V_7 -> V_193 == 0 ) {
F_9 ( V_27 , L_113 , V_28 ) ;
V_193 ( & V_7 -> V_628 ) ;
return;
}
V_7 -> V_193 = 0 ;
F_9 ( V_813 , L_114 , V_28 ) ;
F_80 ( V_36 ) ;
F_216 ( V_7 ) ;
F_217 ( V_36 ) ;
F_218 ( & V_7 -> V_706 ) ;
V_11 -> V_840 = 1 ;
if ( V_11 -> V_126 == V_127 ) {
F_215 ( & V_11 -> V_628 ) ;
F_110 ( V_36 , L_115 ) ;
F_219 ( V_7 -> V_12 ) ;
F_218 ( & V_11 -> V_841 ) ;
F_220 ( & V_11 -> V_842 ) ;
F_221 ( V_11 ) ;
F_222 ( V_36 ) ;
V_193 ( & V_11 -> V_628 ) ;
} else {
F_110 ( V_36 , L_116 ) ;
F_223 ( V_7 -> V_12 ) ;
}
V_193 ( & V_7 -> V_628 ) ;
F_9 ( V_813 , L_117 , V_28 ) ;
F_9 ( V_813 , L_118 , V_28 ) ;
V_838 = F_224 ( V_36 ) ;
F_9 ( V_813 , L_119 , V_28 ) ;
if ( V_838 == - V_843 ) {
if ( V_837 < 3 ) {
V_837 ++ ;
goto V_839;
} else {
F_9 ( V_27 , L_120 , V_28 ) ;
}
}
V_11 -> V_844 = 1 ;
F_148 ( V_36 ) ;
if ( V_11 -> V_126 == V_127 && V_11 -> V_128 == V_129 ) {
V_11 -> V_585 ( V_11 -> V_36 , V_11 -> V_302 . V_845 ) ;
F_156 ( V_11 -> V_846 , & V_11 -> V_847 ) ;
} else if ( V_11 -> V_126 == V_127 && V_11 -> V_128 == V_132 ) {
V_11 -> V_585 ( V_11 -> V_36 , V_11 -> V_302 . V_845 ) ;
V_11 -> V_586 ( V_11 -> V_36 ) ;
F_225 ( V_11 ) ;
if ( V_11 -> V_589 )
V_11 -> V_589 ( V_11 -> V_36 ) ;
F_226 ( V_11 -> V_36 ) ;
}
F_212 ( V_36 ) ;
V_7 -> V_564 = V_565 ;
V_7 -> V_848 ++ ;
V_7 -> V_566 = false ;
V_7 -> V_849 = false ;
F_24 ( V_36 , V_521 , 1 ) ;
F_9 ( V_813 , L_121 , V_7 -> V_848 ) ;
}
}
void F_227 ( struct V_35 * V_36 , T_2 V_850 )
{
T_2 V_851 = 0 ;
T_2 V_852 = 0 ;
T_1 V_853 = 0 ;
T_2 V_854 ;
T_12 V_1 = 100 ;
for ( V_853 = 0 ; V_853 < V_855 ; V_853 ++ ) {
V_851 = V_853 + V_855 * V_850 ;
V_851 = V_851 | V_38 ;
while ( ( V_1 -- ) >= 0 ) {
F_16 ( V_36 , V_40 , & V_854 ) ;
if ( V_854 & V_38 )
continue;
else
break;
}
F_13 ( V_36 , V_40 , V_851 ) ;
F_9 ( V_835 , L_122 , V_851 ) ;
F_16 ( V_36 , V_856 , & V_852 ) ;
F_9 ( V_835 , L_123 , V_852 ) ;
}
F_135 ( L_58 ) ;
}
void F_228 ( struct V_6 * V_7 , T_2 * V_857 ,
T_2 * V_858 )
{
T_3 V_859 ;
T_1 V_1 ;
* V_857 = 0 ;
* V_858 = 0 ;
V_859 = ( V_7 -> V_12 -> V_285 . V_859 ++ ) % ( V_7 -> V_12 -> V_285 . V_860 ) ;
V_7 -> V_12 -> V_285 . V_861 [ V_859 ] = V_7 -> V_12 -> V_285 . V_862 ;
V_7 -> V_12 -> V_285 . V_863 [ V_859 ] = V_7 -> V_12 -> V_285 . V_864 ;
for ( V_1 = 0 ; V_1 < V_7 -> V_12 -> V_285 . V_860 ; V_1 ++ ) {
* V_857 += V_7 -> V_12 -> V_285 . V_861 [ V_1 ] ;
* V_858 += V_7 -> V_12 -> V_285 . V_863 [ V_1 ] ;
}
}
extern void V_633 ( struct V_462 * V_463 )
{
struct V_865 * V_866 = F_150 ( V_463 , struct V_865 , V_463 ) ;
struct V_6 * V_7 = F_150 ( V_866 , struct V_6 , V_632 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
struct V_10 * V_11 = V_7 -> V_12 ;
T_10 V_867 = V_565 ;
static T_1 V_868 ;
bool V_869 = false ;
T_2 V_857 = 0 ;
T_2 V_858 = 0 ;
if ( ! V_7 -> V_193 )
return;
F_229 ( V_36 ) ;
if ( V_11 -> V_126 == V_127 ) {
if ( V_11 -> V_285 . V_870 > 666 ||
V_11 -> V_285 . V_286 > 666 ) {
V_869 = true ;
}
V_11 -> V_285 . V_870 = 0 ;
V_11 -> V_285 . V_286 = 0 ;
V_11 -> V_285 . V_869 = V_869 ;
}
if ( V_7 -> V_12 -> V_126 == V_127 && V_7 -> V_12 -> V_128 == V_129 ) {
F_228 ( V_7 , & V_857 , & V_858 ) ;
if ( ( V_857 + V_858 ) == 0 ) {
#ifdef F_230
if ( V_829 == V_775 )
F_9 ( V_27 , L_124 , V_28 ) ;
#endif
F_110 ( V_36 , L_125 , V_28 ) ;
V_7 -> V_12 -> V_126 = V_871 ;
F_231 ( V_7 -> V_12 ) ;
F_232 ( V_7 -> V_12 , V_7 -> V_12 -> V_302 . V_349 ) ;
V_7 -> V_12 -> V_586 ( V_36 ) ;
F_156 ( V_7 -> V_12 -> V_846 , & V_7 -> V_12 -> V_872 ) ;
}
}
V_7 -> V_12 -> V_285 . V_862 = 0 ;
V_7 -> V_12 -> V_285 . V_864 = 0 ;
if ( V_868 ++ >= 3 ) {
V_867 = F_211 ( V_36 ) ;
V_868 = 3 ;
}
if ( ( V_7 -> V_568 ) || ( V_7 -> V_564 == V_565 &&
( V_7 -> V_566 ||
( ! V_7 -> V_567 && V_867 == V_816 ) ) ) ) {
F_9 ( V_813 , L_126 , V_28 , V_7 -> V_568 , V_7 -> V_564 , V_7 -> V_566 , V_7 -> V_567 , V_867 ) ;
F_214 ( V_36 ) ;
}
V_7 -> V_568 = false ;
V_7 -> V_566 = false ;
V_7 -> V_849 = false ;
F_9 ( V_873 , L_127 ) ;
}
void V_708 ( unsigned long V_42 )
{
struct V_6 * V_7 = F_18 ( (struct V_35 * ) V_42 ) ;
F_158 ( V_7 -> V_499 , & V_7 -> V_632 , 0 ) ;
F_233 ( & V_7 -> V_706 , V_283 + F_234 ( V_874 ) ) ;
}
int F_224 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_724 = 0 ;
V_7 -> V_193 = 1 ;
V_7 -> V_12 -> V_553 = 1 ;
F_9 ( V_95 , L_128 ) ;
V_724 = F_191 ( V_36 ) ;
if ( ! V_724 ) {
F_9 ( V_27 , L_129 , V_28 ) ;
V_7 -> V_193 = V_7 -> V_12 -> V_553 = 0 ;
return - V_843 ;
}
F_9 ( V_95 , L_130 ) ;
F_78 ( V_36 ) ;
if ( V_7 -> V_12 -> V_126 != V_127 )
F_235 ( V_7 -> V_12 ) ;
F_236 ( V_7 -> V_12 ) ;
V_708 ( ( unsigned long ) V_36 ) ;
if ( ! F_37 ( V_36 ) )
F_237 ( V_36 ) ;
else
F_238 ( V_36 ) ;
return 0 ;
}
int F_239 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_200 ;
F_215 ( & V_7 -> V_628 ) ;
V_200 = F_240 ( V_36 ) ;
V_193 ( & V_7 -> V_628 ) ;
return V_200 ;
}
int F_240 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
if ( V_7 -> V_193 == 1 ) return - 1 ;
return F_224 ( V_36 ) ;
}
int F_241 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_200 ;
F_215 ( & V_7 -> V_628 ) ;
V_200 = F_242 ( V_36 ) ;
V_193 ( & V_7 -> V_628 ) ;
return V_200 ;
}
int F_242 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_1 ;
if ( V_7 -> V_193 == 0 ) return - 1 ;
V_7 -> V_193 = 0 ;
V_7 -> V_12 -> V_553 = 0 ;
F_9 ( V_875 , L_131 , V_28 ) ;
if ( ! F_37 ( V_36 ) )
F_243 ( V_36 ) ;
F_80 ( V_36 ) ;
for ( V_1 = 0 ; V_1 < V_624 ; V_1 ++ )
F_84 ( & V_7 -> V_12 -> V_290 [ V_1 ] ) ;
for ( V_1 = 0 ; V_1 < V_624 ; V_1 ++ )
F_84 ( & V_7 -> V_12 -> V_625 [ V_1 ] ) ;
for ( V_1 = 0 ; V_1 < V_624 ; V_1 ++ )
F_84 ( & V_7 -> V_12 -> V_279 [ V_1 ] ) ;
F_216 ( V_7 ) ;
F_217 ( V_36 ) ;
F_218 ( & V_7 -> V_706 ) ;
F_223 ( V_7 -> V_12 ) ;
memset ( & V_7 -> V_12 -> V_302 , 0 , F_244 ( struct V_58 , V_876 ) ) ;
F_9 ( V_875 , L_132 , V_28 ) ;
return 0 ;
}
void F_245 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_838 = 0 ;
if ( V_7 -> V_193 == 0 ) return;
V_7 -> V_193 = 0 ;
F_216 ( V_7 ) ;
F_218 ( & V_7 -> V_706 ) ;
F_223 ( V_7 -> V_12 ) ;
F_80 ( V_36 ) ;
V_838 = F_224 ( V_36 ) ;
}
void V_631 ( struct V_462 * V_463 )
{
struct V_6 * V_7 = F_150 ( V_463 , struct V_6 , V_114 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
F_215 ( & V_7 -> V_628 ) ;
F_245 ( V_36 ) ;
V_193 ( & V_7 -> V_628 ) ;
}
static void F_246 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
short V_561 ;
V_561 = ( V_36 -> V_167 & V_168 ) ? 1 : 0 ;
if ( V_561 != V_7 -> V_561 )
V_7 -> V_561 = V_561 ;
}
int F_247 ( struct V_35 * V_36 , void * V_877 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_878 * V_41 = V_877 ;
F_215 ( & V_7 -> V_628 ) ;
memcpy ( V_36 -> V_663 , V_41 -> V_879 , V_880 ) ;
F_56 ( & V_7 -> V_114 ) ;
V_193 ( & V_7 -> V_628 ) ;
return 0 ;
}
int F_248 ( struct V_35 * V_36 , struct V_881 * V_882 , int V_183 )
{
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_883 * V_884 = (struct V_883 * ) V_882 ;
int V_200 = - 1 ;
struct V_10 * V_11 = V_7 -> V_12 ;
T_2 V_885 [ 4 ] ;
T_1 V_886 [ 6 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_887 * V_888 = & V_884 -> V_889 . V_42 ;
struct V_890 * V_891 = NULL ;
F_215 ( & V_7 -> V_628 ) ;
if ( V_888 -> V_892 < sizeof( struct V_890 ) || ! V_888 -> V_893 ) {
V_200 = - V_894 ;
goto V_895;
}
V_891 = F_140 ( V_888 -> V_892 , V_156 ) ;
if ( V_891 == NULL ) {
V_200 = - V_374 ;
goto V_895;
}
if ( F_249 ( V_891 , V_888 -> V_893 , V_888 -> V_892 ) ) {
F_144 ( V_891 ) ;
V_200 = - V_896 ;
goto V_895;
}
switch ( V_183 ) {
case V_897 :
if ( V_891 -> V_183 == V_898 ) {
if ( V_891 -> V_889 . V_523 . V_899 ) {
if ( strcmp ( V_891 -> V_889 . V_523 . V_900 , L_133 ) == 0 ) {
V_11 -> V_262 = V_266 ;
} else if ( strcmp ( V_891 -> V_889 . V_523 . V_900 , L_134 ) == 0 ) {
V_11 -> V_262 = V_265 ;
} else if ( strcmp ( V_891 -> V_889 . V_523 . V_900 , L_72 ) == 0 ) {
if ( V_891 -> V_889 . V_523 . V_901 == 13 )
V_11 -> V_262 = V_264 ;
else if ( V_891 -> V_889 . V_523 . V_901 == 5 )
V_11 -> V_262 = V_263 ;
} else {
V_11 -> V_262 = V_267 ;
}
if ( V_11 -> V_262 ) {
memcpy ( ( T_1 * ) V_885 , V_891 -> V_889 . V_523 . V_885 , 16 ) ;
F_148 ( V_36 ) ;
F_213 ( V_36 , 4 , V_891 -> V_889 . V_523 . V_902 , V_11 -> V_262 , ( T_1 * ) V_11 -> V_903 , 0 , V_885 ) ;
if ( V_11 -> V_904 != 2 )
F_213 ( V_36 , V_891 -> V_889 . V_523 . V_902 , V_891 -> V_889 . V_523 . V_902 , V_11 -> V_262 , ( T_1 * ) V_11 -> V_903 , 0 , V_885 ) ;
}
} else {
memcpy ( ( T_1 * ) V_885 , V_891 -> V_889 . V_523 . V_885 , 16 ) ;
if ( strcmp ( V_891 -> V_889 . V_523 . V_900 , L_133 ) == 0 ) {
V_11 -> V_836 = V_266 ;
} else if ( strcmp ( V_891 -> V_889 . V_523 . V_900 , L_134 ) == 0 ) {
V_11 -> V_836 = V_265 ;
} else if ( strcmp ( V_891 -> V_889 . V_523 . V_900 , L_72 ) == 0 ) {
if ( V_891 -> V_889 . V_523 . V_901 == 13 )
V_11 -> V_836 = V_264 ;
else if ( V_891 -> V_889 . V_523 . V_901 == 5 )
V_11 -> V_836 = V_263 ;
} else {
V_11 -> V_836 = V_267 ;
}
if ( V_11 -> V_836 ) {
F_213 ( V_36 , V_891 -> V_889 . V_523 . V_902 ,
V_891 -> V_889 . V_523 . V_902 ,
V_11 -> V_836 ,
V_886 ,
0 ,
V_885 ) ;
}
}
}
#ifdef F_250
F_135 ( L_135 ) ;
for ( V_1 = 0 ; V_1 < V_884 -> V_889 . V_42 . V_892 ; V_1 ++ ) {
if ( V_1 % 10 == 0 ) F_135 ( L_58 ) ;
F_135 ( L_136 , ( ( T_2 * ) V_884 -> V_889 . V_42 . V_893 ) [ V_1 ] ) ;
}
F_135 ( L_58 ) ;
#endif
V_200 = F_251 ( V_7 -> V_12 , & V_884 -> V_889 . V_42 ) ;
break;
default:
V_200 = - V_905 ;
break;
}
F_144 ( V_891 ) ;
V_891 = NULL ;
V_895:
V_193 ( & V_7 -> V_628 ) ;
return V_200 ;
}
T_1 F_252 ( bool V_906 , T_1 V_189 )
{
T_1 V_907 = 0xff ;
if ( ! V_906 ) {
switch ( V_189 ) {
case V_398 : V_907 = V_305 ; break;
case V_399 : V_907 = V_307 ; break;
case V_400 : V_907 = V_309 ; break;
case V_401 : V_907 = V_311 ; break;
case V_402 : V_907 = V_313 ; break;
case V_403 : V_907 = V_315 ; break;
case V_404 : V_907 = V_317 ; break;
case V_405 : V_907 = V_319 ; break;
case V_406 : V_907 = V_321 ; break;
case V_407 : V_907 = V_323 ; break;
case V_408 : V_907 = V_325 ; break;
case V_409 : V_907 = V_327 ; break;
default:
V_907 = 0xff ;
F_9 ( V_908 , L_137 , V_189 , V_906 ) ;
break;
}
} else {
switch ( V_189 ) {
case V_411 : V_907 = V_410 ; break;
case V_413 : V_907 = V_412 ; break;
case V_415 : V_907 = V_414 ; break;
case V_417 : V_907 = V_416 ; break;
case V_419 : V_907 = V_418 ; break;
case V_421 : V_907 = V_420 ; break;
case V_423 : V_907 = V_422 ; break;
case V_425 : V_907 = V_424 ; break;
case V_427 : V_907 = V_426 ; break;
case V_429 : V_907 = V_428 ; break;
case V_431 : V_907 = V_430 ; break;
case V_433 : V_907 = V_432 ; break;
case V_435 : V_907 = V_434 ; break;
case V_437 : V_907 = V_436 ; break;
case V_439 : V_907 = V_438 ; break;
case V_441 : V_907 = V_440 ; break;
case V_442 : V_907 = ( 0x80 | 0x20 ) ; break;
default:
V_907 = 0xff ;
F_9 ( V_908 , L_137 , V_189 , V_906 ) ;
break;
}
}
return V_907 ;
}
void F_253 ( struct V_35 * V_36 , struct V_141 * V_67 )
{
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
if ( V_67 -> V_909 && ! V_67 -> V_910 ) {
V_67 -> V_911 [ 0 ] = V_7 -> V_912 ;
V_67 -> V_911 [ 1 ] = V_7 -> V_913 ;
} else {
V_7 -> V_912 = V_67 -> V_911 [ 0 ] ;
V_7 -> V_913 = V_67 -> V_911 [ 1 ] ;
}
}
long F_254 ( T_1 V_914 )
{
long V_915 ;
V_915 = ( long ) ( ( V_914 + 1 ) >> 1 ) ;
V_915 -= 95 ;
return V_915 ;
}
void F_255 ( struct V_6 * V_7 , T_1 * V_916 , struct V_141 * V_917 , struct V_141 * V_918 )
{
bool V_919 = false ;
T_1 V_920 ;
T_2 V_921 , V_922 ;
static T_2 V_923 , V_924 ;
static T_2 V_925 , V_926 ;
static T_2 V_927 , V_928 ;
static T_2 V_929 , V_930 ;
static T_2 V_931 ;
struct V_932 * V_933 ;
T_3 V_934 ;
unsigned int V_935 , V_936 ;
V_933 = (struct V_932 * ) V_916 ;
V_934 = F_256 ( V_933 -> V_937 ) ;
V_935 = F_257 ( V_934 ) ;
V_936 = F_258 ( V_934 ) ;
V_918 -> V_938 = V_936 ;
if ( ! V_917 -> V_909 ) {
V_919 = true ;
}
if ( V_924 ++ >= V_939 ) {
V_924 = V_939 ;
V_927 = V_7 -> V_67 . V_940 [ V_923 ] ;
V_7 -> V_67 . V_941 -= V_927 ;
}
V_7 -> V_67 . V_941 += V_917 -> V_942 ;
V_7 -> V_67 . V_940 [ V_923 ++ ] = V_917 -> V_942 ;
if ( V_923 >= V_939 )
V_923 = 0 ;
V_922 = V_7 -> V_67 . V_941 / V_924 ;
V_7 -> V_67 . V_943 = F_254 ( ( T_1 ) V_922 ) ;
V_918 -> V_944 = V_7 -> V_67 . V_943 ;
if ( ! V_917 -> V_945 ) {
if ( ! V_917 -> V_946 )
return;
}
if ( ! V_919 )
return;
V_7 -> V_67 . V_947 ++ ;
if ( ! V_917 -> V_948 && ( V_917 -> V_949 || V_917 -> V_946 ) ) {
for ( V_920 = V_950 ; V_920 < V_7 -> V_778 ; V_920 ++ ) {
if ( ! F_259 ( V_7 -> V_12 -> V_36 , V_920 ) )
continue;
if ( V_7 -> V_67 . V_951 [ V_920 ] == 0 )
V_7 -> V_67 . V_951 [ V_920 ] = V_917 -> V_952 [ V_920 ] ;
if ( V_917 -> V_952 [ V_920 ] > V_7 -> V_67 . V_951 [ V_920 ] ) {
V_7 -> V_67 . V_951 [ V_920 ] =
( ( V_7 -> V_67 . V_951 [ V_920 ] * ( V_953 - 1 ) ) +
( V_917 -> V_952 [ V_920 ] ) ) / ( V_953 ) ;
V_7 -> V_67 . V_951 [ V_920 ] = V_7 -> V_67 . V_951 [ V_920 ] + 1 ;
} else {
V_7 -> V_67 . V_951 [ V_920 ] =
( ( V_7 -> V_67 . V_951 [ V_920 ] * ( V_953 - 1 ) ) +
( V_917 -> V_952 [ V_920 ] ) ) / ( V_953 ) ;
}
F_9 ( V_954 , L_138 , V_7 -> V_67 . V_951 [ V_920 ] ) ;
}
}
F_9 ( V_955 , L_139 ,
V_917 -> V_948 ? L_140 : L_141 ,
V_917 -> V_956 ) ;
if ( V_917 -> V_957 ) {
if ( V_930 ++ >= V_958 ) {
V_930 = V_958 ;
V_931 = V_7 -> V_67 . V_959 [ V_929 ] ;
V_7 -> V_67 . V_960 -= V_931 ;
}
V_7 -> V_67 . V_960 += V_917 -> V_956 ;
V_7 -> V_67 . V_959 [ V_929 ] = V_917 -> V_956 ;
V_929 ++ ;
if ( V_929 >= V_958 )
V_929 = 0 ;
V_917 -> V_956 = V_7 -> V_67 . V_960 / V_930 ;
if ( V_917 -> V_956 >= 3 )
V_917 -> V_956 -= 3 ;
}
F_9 ( V_955 , L_139 ,
V_917 -> V_948 ? L_140 : L_141 ,
V_917 -> V_956 ) ;
if ( V_917 -> V_949 || V_917 -> V_957 || V_917 -> V_946 ) {
if ( V_7 -> V_820 < 0 )
V_7 -> V_820 = V_917 -> V_956 ;
if ( V_917 -> V_956 > ( T_2 ) V_7 -> V_820 ) {
V_7 -> V_820 =
( ( ( V_7 -> V_820 ) * ( V_953 - 1 ) ) +
( V_917 -> V_956 ) ) / ( V_953 ) ;
V_7 -> V_820 = V_7 -> V_820 + 1 ;
} else {
V_7 -> V_820 =
( ( ( V_7 -> V_820 ) * ( V_953 - 1 ) ) +
( V_917 -> V_956 ) ) / ( V_953 ) ;
}
}
if ( V_917 -> V_961 ) {
if ( V_917 -> V_949 || V_917 -> V_957 || V_917 -> V_946 ) {
if ( V_926 ++ >= V_939 ) {
V_926 = V_939 ;
V_928 = V_7 -> V_67 . V_962 [ V_925 ] ;
V_7 -> V_67 . V_963 -= V_928 ;
}
V_7 -> V_67 . V_963 += V_917 -> V_961 ;
V_7 -> V_67 . V_962 [ V_925 ++ ] = V_917 -> V_961 ;
if ( V_925 >= V_939 )
V_925 = 0 ;
V_922 = V_7 -> V_67 . V_963 / V_926 ;
V_7 -> V_67 . V_964 = V_922 ;
V_7 -> V_67 . V_965 = V_922 ;
}
if ( V_917 -> V_949 || V_917 -> V_957 || V_917 -> V_946 ) {
for ( V_921 = 0 ; V_921 < 2 ; V_921 ++ ) {
if ( V_917 -> V_966 [ V_921 ] != - 1 ) {
if ( V_7 -> V_67 . V_967 [ V_921 ] == 0 )
V_7 -> V_67 . V_967 [ V_921 ] = V_917 -> V_966 [ V_921 ] ;
V_7 -> V_67 . V_967 [ V_921 ] =
( ( V_7 -> V_67 . V_967 [ V_921 ] * ( V_953 - 1 ) ) +
( V_917 -> V_966 [ V_921 ] * 1 ) ) / ( V_953 ) ;
}
}
}
}
}
static T_1 F_260 ( char V_968 )
{
if ( ( V_968 <= - 100 ) || ( V_968 >= 20 ) )
return 0 ;
else if ( V_968 >= 0 )
return 100 ;
else
return 100 + V_968 ;
}
static T_1 F_261 ( char V_969 )
{
char V_970 ;
V_970 = V_969 ;
if ( V_970 >= 0 )
V_970 = 0 ;
if ( V_970 <= - 33 )
V_970 = - 33 ;
V_970 = 0 - V_970 ;
V_970 *= 3 ;
if ( V_970 == 99 )
V_970 = 100 ;
return V_970 ;
}
long F_262 ( long V_971 )
{
long V_972 ;
if ( V_971 >= 61 && V_971 <= 100 )
V_972 = 90 + ( ( V_971 - 60 ) / 4 ) ;
else if ( V_971 >= 41 && V_971 <= 60 )
V_972 = 78 + ( ( V_971 - 40 ) / 2 ) ;
else if ( V_971 >= 31 && V_971 <= 40 )
V_972 = 66 + ( V_971 - 30 ) ;
else if ( V_971 >= 21 && V_971 <= 30 )
V_972 = 54 + ( V_971 - 20 ) ;
else if ( V_971 >= 5 && V_971 <= 20 )
V_972 = 42 + ( ( ( V_971 - 5 ) * 2 ) / 3 ) ;
else if ( V_971 == 4 )
V_972 = 36 ;
else if ( V_971 == 3 )
V_972 = 27 ;
else if ( V_971 == 2 )
V_972 = 18 ;
else if ( V_971 == 1 )
V_972 = 9 ;
else
V_972 = V_971 ;
return V_972 ;
}
static inline bool F_263 ( struct V_973 * V_974 )
{
if ( V_974 -> V_975 )
return false ;
switch ( V_974 -> V_976 ) {
case V_398 :
case V_399 :
case V_400 :
case V_401 :
return true ;
default:
return false ;
}
}
static void F_264 ( struct V_6 * V_7 ,
struct V_141 * V_142 ,
V_973 * V_974 ,
struct V_141 * V_977 ,
bool V_978 ,
bool V_979 ,
bool V_957 ,
bool V_946 )
{
T_13 * V_980 ;
T_14 * V_981 ;
T_15 * V_982 ;
T_1 * V_983 ;
T_1 V_1 , V_984 , V_985 , V_986 , V_987 ;
char V_988 [ 4 ] , V_989 = 0 ;
char V_990 , V_991 ;
T_1 V_992 , V_993 ;
T_2 V_994 , V_995 = 0 ;
T_1 V_996 = 0 ;
T_1 V_997 = 0 ;
T_1 V_998 ;
V_7 -> V_67 . V_999 ++ ;
V_996 = F_263 ( V_974 ) ;
memset ( V_977 , 0 , sizeof( struct V_141 ) ) ;
V_142 -> V_945 = V_977 -> V_945 = V_978 ;
V_142 -> V_949 = V_977 -> V_949 = V_979 ;
V_142 -> V_948 = V_977 -> V_948 = V_996 ;
V_142 -> V_957 = V_977 -> V_957 = V_957 ;
V_142 -> V_946 = V_977 -> V_946 = V_946 ;
V_983 = ( T_1 * ) V_974 ;
V_983 += sizeof( V_973 ) ;
V_981 = ( T_14 * ) V_983 ;
V_980 = ( T_13 * ) V_983 ;
V_142 -> V_966 [ 0 ] = - 1 ;
V_142 -> V_966 [ 1 ] = - 1 ;
V_977 -> V_966 [ 0 ] = - 1 ;
V_977 -> V_966 [ 1 ] = - 1 ;
if ( V_996 ) {
T_1 V_1000 ;
V_7 -> V_67 . V_1001 ++ ;
if ( ! V_7 -> V_1002 ) {
V_1000 = V_981 -> V_1003 & 0xc0 ;
V_1000 = V_1000 >> 6 ;
switch ( V_1000 ) {
case 0x3 :
V_989 = - 35 - ( V_981 -> V_1003 & 0x3e ) ;
break;
case 0x2 :
V_989 = - 23 - ( V_981 -> V_1003 & 0x3e ) ;
break;
case 0x1 :
V_989 = - 11 - ( V_981 -> V_1003 & 0x3e ) ;
break;
case 0x0 :
V_989 = 6 - ( V_981 -> V_1003 & 0x3e ) ;
break;
}
} else {
V_1000 = V_981 -> V_1003 & 0x60 ;
V_1000 = V_1000 >> 5 ;
switch ( V_1000 ) {
case 0x3 :
V_989 = - 35 - ( ( V_981 -> V_1003 & 0x1f ) << 1 ) ;
break;
case 0x2 :
V_989 = - 23 - ( ( V_981 -> V_1003 & 0x1f ) << 1 ) ;
break;
case 0x1 :
V_989 = - 11 - ( ( V_981 -> V_1003 & 0x1f ) << 1 ) ;
break;
case 0x0 :
V_989 = 6 - ( ( V_981 -> V_1003 & 0x1f ) << 1 ) ;
break;
}
}
V_993 = F_260 ( V_989 ) ;
V_142 -> V_956 = V_977 -> V_956 = V_993 ;
V_142 -> V_1004 = V_993 ;
if ( V_142 -> V_956 > 40 ) {
V_998 = 100 ;
} else {
V_998 = V_981 -> V_1005 ;
if ( V_981 -> V_1005 > 64 )
V_998 = 0 ;
else if ( V_981 -> V_1005 < 20 )
V_998 = 100 ;
else
V_998 = ( ( 64 - V_998 ) * 100 ) / 44 ;
}
V_142 -> V_961 = V_977 -> V_961 = V_998 ;
V_142 -> V_966 [ 0 ] = V_977 -> V_966 [ 0 ] = V_998 ;
V_142 -> V_966 [ 1 ] = V_977 -> V_966 [ 1 ] = - 1 ;
} else {
V_7 -> V_67 . V_1006 ++ ;
for ( V_1 = V_950 ; V_1 < V_7 -> V_778 ; V_1 ++ ) {
if ( V_7 -> V_1007 [ V_1 ] )
V_997 ++ ;
else
continue;
if ( ! F_259 ( V_7 -> V_12 -> V_36 , V_1 ) )
continue;
V_988 [ V_1 ] = ( ( V_980 -> V_1008 [ V_1 ] & 0x3F ) * 2 ) - 106 ;
V_985 = V_980 -> V_1009 [ V_1 ] ;
V_990 = ( char ) ( V_985 ) ;
V_990 /= 2 ;
V_7 -> V_67 . V_1010 [ V_1 ] = ( long ) V_990 ;
V_994 = F_260 ( V_988 [ V_1 ] ) ;
V_995 += V_994 ;
V_142 -> V_952 [ V_1 ] = ( T_1 ) V_994 ;
V_977 -> V_952 [ V_1 ] = ( T_1 ) V_994 ;
}
V_989 = ( ( ( V_980 -> V_993 ) >> 1 ) & 0x7f ) - 106 ;
V_993 = F_260 ( V_989 ) ;
V_142 -> V_956 = V_977 -> V_956 = V_993 ;
V_142 -> V_1011 = V_977 -> V_1011 = V_989 ;
if ( V_974 -> V_975 && V_974 -> V_976 >= V_427 &&
V_974 -> V_976 <= V_441 )
V_984 = 2 ;
else
V_984 = 1 ;
for ( V_1 = 0 ; V_1 < V_984 ; V_1 ++ ) {
V_986 = V_980 -> V_1012 [ V_1 ] ;
V_991 = ( char ) ( V_986 ) ;
V_991 /= 2 ;
V_992 = F_261 ( V_991 ) ;
if ( V_1 == 0 )
V_142 -> V_961 = V_977 -> V_961 = ( T_1 ) ( V_992 & 0xff ) ;
V_142 -> V_966 [ V_1 ] = V_977 -> V_966 [ V_1 ] = ( T_1 ) ( V_992 & 0xff ) ;
}
V_987 = V_980 -> V_987 ;
V_982 = ( T_15 * ) & V_987 ;
if ( V_974 -> V_1013 )
V_7 -> V_67 . V_1014 [ 1 + V_982 -> V_1015 ] ++ ;
else
V_7 -> V_67 . V_1014 [ 0 ] ++ ;
}
if ( V_996 ) {
V_142 -> V_942 = V_977 -> V_942 = ( T_1 ) ( F_262 ( ( long ) V_993 ) ) ;
} else {
if ( V_997 != 0 )
V_142 -> V_942 = V_977 -> V_942 = ( T_1 ) ( F_262 ( ( long ) ( V_995 /= V_997 ) ) ) ;
}
}
void F_265 ( struct V_141 * V_1016 ,
struct V_141 * V_1017 )
{
V_1017 -> V_909 = V_1016 -> V_909 ;
V_1017 -> V_910 = V_1016 -> V_910 ;
V_1017 -> V_938 = V_1016 -> V_938 ;
}
void F_266 ( struct V_149 * V_150 ,
struct V_141 * V_142 ,
V_973 * V_974 )
{
V_151 * V_152 = (struct V_151 * ) V_150 -> V_158 ;
struct V_35 * V_36 = V_152 -> V_36 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
bool V_978 , V_979 ;
bool V_957 = FALSE , V_946 = FALSE ;
static struct V_141 V_1018 ;
struct V_932 * V_933 ;
T_3 V_1019 , type ;
T_1 * V_1020 ;
T_1 * V_1021 ;
V_1020 = ( T_1 * ) V_150 -> V_42 ;
V_933 = (struct V_932 * ) V_1020 ;
V_1019 = F_256 ( V_933 -> V_1022 ) ;
type = F_267 ( V_1019 ) ;
V_1021 = V_933 -> V_1023 ;
V_978 = ( ( V_1024 != type ) &&
( F_268 ( V_7 -> V_12 -> V_302 . V_349 , ( V_1019 & V_1025 ) ? V_933 -> V_1023 : ( V_1019 & V_1026 ) ? V_933 -> V_1027 : V_933 -> V_1028 ) )
&& ( ! V_142 -> V_1029 ) && ( ! V_142 -> V_1030 ) && ( ! V_142 -> V_1031 ) ) ;
V_979 = V_978 & ( F_268 ( V_1021 , V_7 -> V_12 -> V_36 -> V_663 ) ) ;
if ( F_269 ( V_1019 ) == V_1032 )
V_957 = true ;
if ( F_269 ( V_1019 ) == V_1033 ) {
if ( ( F_268 ( V_1021 , V_36 -> V_663 ) ) )
V_946 = true ;
}
if ( V_978 )
V_7 -> V_67 . V_1034 ++ ;
if ( V_979 )
V_7 -> V_67 . V_1035 ++ ;
F_255 ( V_7 , V_1020 , & V_1018 , V_142 ) ;
F_264 ( V_7 , V_142 , V_974 , & V_1018 , V_978 , V_979 , V_957 , V_946 ) ;
F_265 ( V_142 , & V_1018 ) ;
}
void F_270 ( struct V_35 * V_36 ,
struct V_141 * V_67 )
{
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
T_2 V_1036 = 1 ;
T_2 V_1037 ;
T_2 V_1038 ;
if ( V_67 -> V_1030 )
V_1036 = 2 ;
else if ( V_67 -> V_1031 )
V_1036 = 3 ;
if ( V_67 -> V_363 )
V_1038 = 1 ;
else
V_1038 = 0 ;
switch ( V_67 -> V_189 ) {
case V_305 : V_1037 = 0 ; break;
case V_307 : V_1037 = 1 ; break;
case V_309 : V_1037 = 2 ; break;
case V_311 : V_1037 = 3 ; break;
case V_313 : V_1037 = 4 ; break;
case V_315 : V_1037 = 5 ; break;
case V_317 : V_1037 = 6 ; break;
case V_319 : V_1037 = 7 ; break;
case V_321 : V_1037 = 8 ; break;
case V_323 : V_1037 = 9 ; break;
case V_325 : V_1037 = 10 ; break;
case V_327 : V_1037 = 11 ; break;
case V_410 : V_1037 = 12 ; break;
case V_412 : V_1037 = 13 ; break;
case V_414 : V_1037 = 14 ; break;
case V_416 : V_1037 = 15 ; break;
case V_418 : V_1037 = 16 ; break;
case V_420 : V_1037 = 17 ; break;
case V_422 : V_1037 = 18 ; break;
case V_424 : V_1037 = 19 ; break;
case V_426 : V_1037 = 20 ; break;
case V_428 : V_1037 = 21 ; break;
case V_430 : V_1037 = 22 ; break;
case V_432 : V_1037 = 23 ; break;
case V_434 : V_1037 = 24 ; break;
case V_436 : V_1037 = 25 ; break;
case V_438 : V_1037 = 26 ; break;
case V_440 : V_1037 = 27 ; break;
default: V_1037 = 28 ; break;
}
V_7 -> V_67 . V_1039 [ V_1038 ] [ V_1037 ] ++ ;
V_7 -> V_67 . V_1040 [ 0 ] [ V_1037 ] ++ ;
V_7 -> V_67 . V_1040 [ V_1036 ] [ V_1037 ] ++ ;
}
void F_271 ( struct V_149 * V_150 , struct V_141 * V_67 , bool V_1041 )
{
V_151 * V_152 = (struct V_151 * ) V_150 -> V_158 ;
struct V_35 * V_36 = V_152 -> V_36 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
V_973 * V_1042 = NULL ;
#ifdef F_65
if ( V_1041 ) {
T_16 * V_1043 = ( T_16 * ) V_150 -> V_42 ;
V_67 -> V_1044 = V_1043 -> V_1044 ;
V_67 -> V_145 = V_1043 -> V_145 ;
V_67 -> V_146 = 0 ;
V_67 -> V_1031 = V_1043 -> V_1045 ;
V_67 -> V_1030 = V_1043 -> V_1046 ;
V_67 -> V_1029 = V_67 -> V_1030 | V_67 -> V_1031 ;
V_67 -> V_1047 = ! V_1043 -> V_1048 ;
} else
#endif
{
V_144 * V_1043 = ( V_144 * ) V_150 -> V_42 ;
V_67 -> V_1044 = V_1043 -> V_1044 ;
V_67 -> V_145 = V_1043 -> V_145 ;
V_67 -> V_146 = 0 ;
V_67 -> V_1031 = V_1043 -> V_1045 ;
V_67 -> V_1030 = V_1043 -> V_1046 ;
V_67 -> V_1029 = V_67 -> V_1030 | V_67 -> V_1031 ;
V_67 -> V_1047 = ! V_1043 -> V_1048 ;
}
if ( ( V_7 -> V_12 -> V_275 -> V_465 == true ) && ( V_7 -> V_12 -> V_262 == V_266 ) )
V_67 -> V_1029 = false ;
else
V_67 -> V_1029 = V_67 -> V_1030 | V_67 -> V_1031 ;
if ( V_67 -> V_1044 < 24 || V_67 -> V_1044 > V_1049 )
V_67 -> V_1029 |= 1 ;
if ( V_67 -> V_145 != 0 ) {
V_1042 = ( V_973 * ) ( V_150 -> V_42 + sizeof( V_144 ) +
V_67 -> V_146 ) ;
if ( ! V_67 -> V_1029 ) {
T_1 V_907 ;
V_907 = F_252 ( V_1042 -> V_975 , V_1042 -> V_976 ) ;
if ( V_907 == 0xff ) {
V_67 -> V_1029 = 1 ;
V_67 -> V_189 = V_305 ;
} else {
V_67 -> V_189 = V_907 ;
}
} else {
V_67 -> V_189 = 0x02 ;
}
V_67 -> V_363 = V_1042 -> V_1050 ;
F_270 ( V_36 , V_67 ) ;
V_67 -> V_909 = ( V_1042 -> V_1051 == 1 ) ;
V_67 -> V_910 = ( V_1042 -> V_1051 == 1 ) && ( V_1042 -> V_1052 == 1 ) ;
V_67 -> V_1053 = V_1042 -> V_1054 ;
F_253 ( V_36 , V_67 ) ;
if ( V_1042 -> V_1052 == 1 || V_1042 -> V_1051 == 1 )
F_9 ( V_955 , L_142 ,
V_1042 -> V_1052 , V_1042 -> V_1051 ) ;
}
F_272 ( V_150 , sizeof( V_144 ) ) ;
if ( ( V_67 -> V_146 + V_67 -> V_145 ) > 0 ) {
V_67 -> V_1055 = 1 ;
F_272 ( V_150 , V_67 -> V_146 + V_67 -> V_145 ) ;
}
#ifdef F_65
if ( V_1041 )
F_272 ( V_150 , 8 ) ;
#endif
V_67 -> V_1056 = V_1042 -> V_1013 ;
if ( V_67 -> V_145 != 0 )
F_266 ( V_150 , V_67 , V_1042 ) ;
}
T_2 F_273 ( struct V_141 * V_1057 , bool V_1041 )
{
#ifdef F_65
if ( V_1041 )
return ( sizeof( V_144 ) + V_1057 -> V_145
+ V_1057 -> V_146 + 8 ) ;
else
#endif
return ( sizeof( V_144 ) + V_1057 -> V_145
+ V_1057 -> V_146 ) ;
}
void F_274 ( struct V_149 * V_150 )
{
V_151 * V_152 = (struct V_151 * ) V_150 -> V_158 ;
struct V_35 * V_36 = V_152 -> V_36 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_141 V_67 = {
. signal = 0 ,
. V_1058 = - 98 ,
. V_189 = 0 ,
. V_1059 = V_1060 ,
} ;
T_2 V_1061 = 0 ;
struct V_1062 * V_1063 = NULL ;
bool V_1064 = false ;
#ifdef F_65
struct V_149 * V_214 = NULL ;
T_2 V_213 = 0 ;
T_2 V_1065 = 0 ;
T_2 V_1066 = 0 ;
T_2 V_1067 = 0 ;
T_1 V_1068 = 0 ;
T_2 V_1069 = 0 ;
T_16 * V_1070 = NULL ;
T_1 V_1071 = 0 ;
T_1 V_1072 ;
#endif
if ( ( V_150 -> V_209 >= ( 20 + sizeof( V_144 ) ) ) && ( V_150 -> V_209 < V_155 ) ) {
#ifdef F_65
V_1068 = * ( V_150 -> V_42 + sizeof( V_144 ) ) ;
#endif
F_271 ( V_150 , & V_67 , false ) ;
#ifdef F_65
if ( V_1068 & V_1073 ) {
V_214 = V_150 ;
V_213 = V_67 . V_1044 - 4 ;
V_1065 = * ( T_2 * ) ( V_214 -> V_42 - 4 ) ;
V_1066 = ( T_3 ) ( V_1065 & 0x3FFF ) ;
V_150 = F_93 ( V_1066 ) ;
memcpy ( F_91 ( V_150 , V_1066 ) , V_214 -> V_42 , V_1066 ) ;
V_1069 = F_273 ( & V_67 , false ) ;
}
#endif
F_275 ( V_150 , V_150 -> V_209 - 4 ) ;
V_1061 = V_150 -> V_209 ;
V_1063 = (struct V_1062 * ) V_150 -> V_42 ;
V_1064 = false ;
if ( F_276 ( V_1063 -> V_1023 ) ) {
} else if ( F_277 ( V_1063 -> V_1023 ) ) {
} else {
V_1064 = true ;
}
if ( ! F_278 ( V_7 -> V_12 , V_150 , & V_67 ) ) {
F_114 ( V_150 ) ;
} else {
V_7 -> V_67 . V_92 ++ ;
if ( V_1064 )
V_7 -> V_67 . V_1074 += V_1061 ;
}
#ifdef F_65
V_1072 = 1 ;
if ( V_213 > 0 ) {
V_1067 = V_1066 + ( V_1069 + 8 ) ;
if ( ( V_1067 & 0xFF ) != 0 )
V_1067 = ( V_1067 & 0xFFFFFF00 ) + 256 ;
V_1067 -= 8 ;
V_1065 = V_1067 - V_1069 ;
if ( V_214 -> V_209 > V_1065 )
F_272 ( V_214 , V_1065 ) ;
else
V_214 -> V_209 = 0 ;
while ( V_214 -> V_209 >= F_273 ( & V_67 , true ) ) {
T_1 V_1075 = 0 , V_1076 = 0 ;
V_1070 = ( T_16 * ) ( V_214 -> V_42 ) ;
V_1075 = V_1070 -> V_1046 ;
V_1076 = V_1070 -> V_1045 ;
memcpy ( V_214 -> V_42 , & V_214 -> V_42 [ 44 ] , 2 ) ;
V_1070 -> V_1046 = V_1075 ;
V_1070 -> V_1045 = V_1076 ;
memset ( & V_67 , 0 , sizeof( struct V_141 ) ) ;
V_67 . signal = 0 ;
V_67 . V_1058 = - 98 ;
V_67 . V_189 = 0 ;
V_67 . V_1059 = V_1060 ;
F_271 ( V_214 , & V_67 , true ) ;
V_1066 = V_67 . V_1044 ;
if ( V_1066 > V_214 -> V_209 )
break;
V_150 = F_93 ( V_1066 ) ;
memcpy ( F_91 ( V_150 , V_1066 ) , V_214 -> V_42 , V_1066 ) ;
F_275 ( V_150 , V_150 -> V_209 - 4 ) ;
V_1061 = V_150 -> V_209 ;
V_1063 = (struct V_1062 * ) V_150 -> V_42 ;
V_1064 = false ;
if ( F_276 ( V_1063 -> V_1023 ) ) {
} else if ( F_277 ( V_1063 -> V_1023 ) ) {
} else {
V_1064 = true ;
}
if ( ! F_278 ( V_7 -> V_12 , V_150 , & V_67 ) ) {
F_114 ( V_150 ) ;
} else {
V_7 -> V_67 . V_92 ++ ;
if ( V_1064 )
V_7 -> V_67 . V_1074 += V_1061 ;
}
F_272 ( V_214 , V_1066 ) ;
V_1069 = F_273 ( & V_67 , true ) ;
V_1067 = V_1066 + V_1069 ;
if ( ( V_1067 & 0xFF ) != 0 ) {
V_1071 = 256 - ( V_1067 & 0xFF ) ;
if ( V_214 -> V_209 > V_1071 )
F_272 ( V_214 , V_1071 ) ;
else
V_214 -> V_209 = 0 ;
}
}
F_132 ( V_214 ) ;
}
#endif
} else {
V_7 -> V_67 . V_94 ++ ;
F_110 ( V_36 , L_143 , V_150 -> V_209 ) ;
F_114 ( V_150 ) ;
}
}
void F_279 ( struct V_35 * V_36 ,
struct V_141 * V_142 )
{
T_1 * V_1077 ;
T_3 V_1078 = 0 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
V_142 -> V_1079 += F_64 ( V_142 ) ;
V_1077 = V_142 -> V_1079 ;
V_1078 = V_142 -> V_1080 ;
#ifdef F_230
if ( ! V_605 -> V_606 )
F_280 ( V_605 , V_1081 ) ;
#endif
#ifdef F_281
T_11 V_1082 ;
V_605 -> V_1083 . V_1084 ( V_605 , V_1085 , ( T_1 * ) ( & V_1082 ) ) ;
if ( V_1082 == V_775 )
return;
#endif
V_7 -> V_67 . V_1086 ++ ;
#ifdef F_230
F_282 ( V_605 , V_1081 ) ;
#endif
if ( F_94 ( V_36 , V_142 ) )
return;
#ifdef F_283
F_284 () ;
#endif
}
void F_285 ( struct V_149 * V_150 , struct V_141 * V_67 )
{
V_144 * V_1043 = ( V_144 * ) V_150 -> V_42 ;
V_67 -> V_1079 = ( T_1 * ) V_150 -> V_42 ;
V_67 -> V_1044 = V_1043 -> V_1044 ;
V_67 -> V_145 = 0 ;
V_67 -> V_146 = 0 ;
V_67 -> V_1080 = V_67 -> V_1044 - V_1087 ;
V_67 -> V_1088 = V_67 -> V_1080 ;
V_67 -> V_1089 = 0 ;
V_67 -> V_1090 = 1 ;
}
void F_286 ( struct V_149 * V_150 )
{
struct V_151 * V_152 = (struct V_151 * ) V_150 -> V_158 ;
struct V_35 * V_36 = V_152 -> V_36 ;
struct V_141 V_67 = {
. signal = 0 ,
. V_1058 = - 98 ,
. V_189 = 0 ,
. V_1059 = V_1060 ,
} ;
if ( ( V_150 -> V_209 >= ( 20 + sizeof( V_144 ) ) ) && ( V_150 -> V_209 < V_155 ) ) {
F_285 ( V_150 , & V_67 ) ;
F_279 ( V_36 , & V_67 ) ;
F_114 ( V_150 ) ;
}
}
void V_640 ( struct V_6 * V_7 )
{
struct V_149 * V_150 ;
struct V_151 * V_152 ;
while ( NULL != ( V_150 = F_116 ( & V_7 -> V_187 ) ) ) {
V_152 = (struct V_151 * ) V_150 -> V_158 ;
switch ( V_152 -> V_159 ) {
case 3 :
V_7 -> V_563 -- ;
F_274 ( V_150 ) ;
break;
case 9 :
F_9 ( V_908 , L_144 ,
V_152 -> V_159 ) ;
F_286 ( V_150 ) ;
break;
default:
F_9 ( V_27 , L_145 ,
V_152 -> V_159 ) ;
F_132 ( V_150 ) ;
break;
}
}
}
static int F_287 ( struct V_1091 * V_1092 ,
const struct V_1093 * V_1094 )
{
struct V_35 * V_36 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_47 * V_48 = F_288 ( V_1092 ) ;
int V_200 ;
F_9 ( V_95 , L_146 ) ;
V_36 = F_289 ( sizeof( struct V_6 ) ) ;
if ( V_36 == NULL )
return - V_374 ;
F_290 ( V_1092 , V_36 ) ;
F_291 ( V_36 , & V_1092 -> V_36 ) ;
V_7 = F_18 ( V_36 ) ;
V_7 -> V_12 = F_108 ( V_36 ) ;
V_7 -> V_48 = V_48 ;
V_36 -> V_1095 = & V_1096 ;
#if V_1097 >= 12
#if V_1097 < 17
V_36 -> V_1098 = V_1099 ;
#endif
V_36 -> V_1100 = (struct V_1101 * ) & V_1102 ;
#endif
V_36 -> type = V_1103 ;
V_36 -> V_1104 = V_51 * 3 ;
if ( F_292 ( V_36 , V_1105 ) < 0 ) {
F_9 ( V_95 , L_147 ) ;
V_1105 = L_148 ;
F_292 ( V_36 , V_1105 ) ;
}
F_9 ( V_95 , L_149 ) ;
if ( F_185 ( V_36 ) != 0 ) {
F_9 ( V_27 , L_150 ) ;
V_200 = - V_1106 ;
goto V_1107;
}
F_222 ( V_36 ) ;
F_243 ( V_36 ) ;
V_200 = F_293 ( V_36 ) ;
if ( V_200 )
goto V_1108;
F_9 ( V_95 , L_151 , V_36 -> V_106 ) ;
F_49 ( V_36 ) ;
F_9 ( V_95 , L_152 ) ;
return 0 ;
V_1108:
F_242 ( V_36 ) ;
F_144 ( V_7 -> V_622 ) ;
V_7 -> V_622 = NULL ;
F_145 ( V_36 ) ;
F_294 ( V_7 -> V_499 ) ;
F_63 ( 10 ) ;
V_1107:
F_295 ( V_36 ) ;
F_9 ( V_27 , L_153 ) ;
return V_200 ;
}
void F_216 ( struct V_6 * V_7 )
{
F_296 ( & V_7 -> V_114 ) ;
F_220 ( & V_7 -> V_632 ) ;
F_220 ( & V_7 -> V_464 ) ;
F_296 ( & V_7 -> V_469 ) ;
}
static void F_297 ( struct V_1091 * V_1092 )
{
struct V_35 * V_36 = F_298 ( V_1092 ) ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
if ( V_36 ) {
F_299 ( V_36 ) ;
F_9 ( V_875 , L_154 ) ;
F_52 ( V_36 ) ;
F_242 ( V_36 ) ;
F_144 ( V_7 -> V_622 ) ;
V_7 -> V_622 = NULL ;
F_145 ( V_36 ) ;
F_294 ( V_7 -> V_499 ) ;
F_63 ( 10 ) ;
}
F_295 ( V_36 ) ;
F_9 ( V_875 , L_155 ) ;
}
static int T_17 F_300 ( void )
{
int V_200 ;
#ifdef F_301
V_200 = F_302 () ;
if ( V_200 ) {
F_303 ( L_156 , V_200 ) ;
return V_200 ;
}
#endif
V_200 = F_304 () ;
if ( V_200 ) {
F_303 ( L_157 , V_200 ) ;
return V_200 ;
}
V_200 = F_305 () ;
if ( V_200 ) {
F_303 ( L_158 , V_200 ) ;
return V_200 ;
}
V_200 = F_306 () ;
if ( V_200 ) {
F_303 ( L_159 , V_200 ) ;
return V_200 ;
}
V_200 = F_307 () ;
if ( V_200 ) {
F_303 ( L_160 , V_200 ) ;
return V_200 ;
}
F_308 ( L_161 ) ;
F_308 ( L_162 ) ;
F_9 ( V_95 , L_163 ) ;
F_9 ( V_95 , L_164 , V_1097 ) ;
F_40 () ;
return F_309 ( & V_1109 ) ;
}
static void T_18 F_310 ( void )
{
F_311 ( & V_1109 ) ;
F_9 ( V_875 , L_165 ) ;
}
void F_312 ( struct V_35 * V_36 , int V_1110 )
{
unsigned long V_167 ;
short V_1111 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
F_100 ( & V_7 -> V_204 , V_167 ) ;
V_1111 = F_54 ( V_36 , V_1110 ) ;
F_103 ( & V_7 -> V_204 , V_167 ) ;
if ( V_1111 )
F_313 ( V_7 -> V_12 ) ;
}
void F_148 ( struct V_35 * V_36 )
{
T_1 V_725 = 0x0 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
V_725 = V_761 | V_762 ;
if ( ( ( V_263 == V_11 -> V_262 ) || ( V_264 == V_11 -> V_262 ) ) && ( V_7 -> V_12 -> V_904 != 2 ) ) {
V_725 |= V_1112 ;
V_725 |= V_1113 ;
} else if ( ( V_11 -> V_128 == V_132 ) && ( V_11 -> V_262 & ( V_266 | V_265 ) ) ) {
V_725 |= V_1112 ;
V_725 |= V_1113 ;
}
V_11 -> V_1114 = 1 ;
if ( ( V_11 -> V_275 -> V_1115 & V_1116 ) || ! V_1117 ) {
V_11 -> V_1114 = 0 ;
V_725 &= ~ V_762 ;
}
F_9 ( V_835 , L_166 , V_28 ,
V_11 -> V_1114 , V_11 -> V_262 , V_725 ) ;
F_24 ( V_36 , V_764 , V_725 ) ;
}
void F_213 ( struct V_35 * V_36 , T_1 V_1118 , T_1 V_1119 , T_3 V_1120 ,
T_1 * V_832 , T_1 V_1121 , T_2 * V_1122 )
{
T_2 V_1123 = 0 ;
T_2 V_1124 = 0 ;
T_3 V_1125 = 0 ;
T_1 V_1 ;
if ( V_1118 >= V_1126 )
F_9 ( V_27 , L_167 ) ;
F_9 ( V_835 , L_168 , V_36 , V_1118 , V_1119 , V_1120 , V_832 ) ;
if ( V_1121 )
V_1125 |= V_1127 | ( V_1120 << 2 ) ;
else
V_1125 |= V_1127 | ( V_1120 << 2 ) | V_1119 ;
for ( V_1 = 0 ; V_1 < V_855 ; V_1 ++ ) {
V_1123 = V_1 + V_855 * V_1118 ;
V_1123 |= V_38 | V_44 ;
if ( V_1 == 0 ) {
V_1124 = ( T_2 ) ( * ( V_832 + 0 ) ) << 16 |
( T_2 ) ( * ( V_832 + 1 ) ) << 24 |
( T_2 ) V_1125 ;
F_13 ( V_36 , V_43 , V_1124 ) ;
F_13 ( V_36 , V_40 , V_1123 ) ;
} else if ( V_1 == 1 ) {
V_1124 = ( T_2 ) ( * ( V_832 + 2 ) ) |
( T_2 ) ( * ( V_832 + 3 ) ) << 8 |
( T_2 ) ( * ( V_832 + 4 ) ) << 16 |
( T_2 ) ( * ( V_832 + 5 ) ) << 24 ;
F_13 ( V_36 , V_43 , V_1124 ) ;
F_13 ( V_36 , V_40 , V_1123 ) ;
} else {
if ( V_1122 != NULL ) {
F_13 ( V_36 , V_43 , ( T_2 ) ( * ( V_1122 + V_1 - 2 ) ) ) ;
F_13 ( V_36 , V_40 , V_1123 ) ;
}
}
}
}
