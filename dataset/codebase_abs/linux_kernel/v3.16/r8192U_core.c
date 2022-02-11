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
static void F_12 ( struct V_35 * V_36 )
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
static int F_42 ( struct V_100 * V_100 , struct V_101 * V_101 )
{
struct V_35 * V_36 = F_43 ( V_100 ) ;
int (* F_44)( struct V_54 * , void * ) = F_45 ( V_100 ) ;
return F_46 ( V_101 , F_44 , V_36 ) ;
}
static void F_47 ( struct V_35 * V_36 )
{
const struct V_102 * V_103 ;
struct V_104 * V_105 ;
if ( V_96 ) {
V_105 = F_48 ( V_36 -> V_106 , 0 , V_96 , V_36 ) ;
if ( ! V_105 ) {
F_9 ( V_27 , L_43 ,
V_36 -> V_106 ) ;
return;
}
for ( V_103 = V_107 ; V_103 -> V_106 [ 0 ] ; V_103 ++ ) {
if ( ! F_49 ( V_103 -> V_106 , V_108 | V_109 , V_105 ,
& V_110 , V_103 -> F_44 ) ) {
F_9 ( V_27 , L_44
L_45 ,
V_36 -> V_106 , V_103 -> V_106 ) ;
return;
}
}
}
}
static void F_50 ( struct V_35 * V_36 )
{
F_51 ( V_36 -> V_106 , V_96 ) ;
}
short F_52 ( struct V_35 * V_36 , int V_111 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_112 = F_38 ( & V_7 -> V_82 [ V_111 ] ) ;
return ( V_112 < V_113 ) ;
}
static void F_53 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
F_54 ( & V_7 -> V_114 ) ;
}
void F_55 ( struct V_35 * V_36 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < 63 ; V_1 ++ )
F_9 ( V_115 , L_46 , V_1 , F_56 ( V_36 , V_1 ) ) ;
}
void F_57 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 V_116 ;
F_26 ( V_36 , V_117 , & V_116 ) ;
V_116 &= ~ V_118 ;
if ( V_7 -> V_12 -> V_119 == V_120 ) {
if ( V_7 -> V_12 -> V_121 == V_122 )
V_116 |= ( V_123 << V_124 ) ;
else if ( V_7 -> V_12 -> V_121 == V_125 )
V_116 |= ( V_126 << V_124 ) ;
else if ( V_7 -> V_12 -> V_121 == V_127 )
V_116 |= ( V_128 << V_124 ) ;
} else {
V_116 |= ( V_129 << V_124 ) ;
}
F_24 ( V_36 , V_117 , V_116 ) ;
}
void F_58 ( struct V_35 * V_36 , short V_130 )
{
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
F_9 ( V_131 , L_47 , V_28 , V_130 ) ;
V_7 -> V_132 = V_130 ;
#ifndef F_59
if ( V_7 -> V_133 )
V_7 -> V_133 ( V_36 , V_7 -> V_132 ) ;
F_60 ( 10 ) ;
#endif
}
static T_2 F_61 ( struct V_134 * V_135 )
{
#ifdef F_62
if ( V_135 -> V_136 )
return ( sizeof( V_137 ) + V_135 -> V_138
+ V_135 -> V_139 + 8 ) ;
else
#endif
return ( sizeof( V_137 ) + V_135 -> V_138
+ V_135 -> V_139 ) ;
}
static int F_63 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_140 * V_141 ;
struct V_142 * V_143 ;
struct V_144 * V_145 ;
while ( F_64 ( & V_7 -> V_146 ) < V_147 ) {
V_143 = F_65 ( V_148 , V_149 ) ;
if ( ! V_143 )
break;
V_141 = F_66 ( 0 , V_149 ) ;
if ( ! V_141 ) {
F_67 ( V_143 ) ;
break;
}
F_68 ( V_141 , V_7 -> V_48 ,
F_69 ( V_7 -> V_48 , 3 ) , F_70 ( V_143 ) ,
V_148 , V_150 , V_143 ) ;
V_145 = (struct V_144 * ) V_143 -> V_151 ;
V_145 -> V_140 = V_141 ;
V_145 -> V_36 = V_36 ;
V_145 -> V_152 = 3 ;
F_71 ( & V_7 -> V_146 , V_143 ) ;
F_72 ( V_141 , V_149 ) ;
}
while ( F_64 ( & V_7 -> V_146 ) < V_147 + 3 ) {
V_143 = F_65 ( V_148 , V_149 ) ;
if ( ! V_143 )
break;
V_141 = F_66 ( 0 , V_149 ) ;
if ( ! V_141 ) {
F_67 ( V_143 ) ;
break;
}
F_68 ( V_141 , V_7 -> V_48 ,
F_69 ( V_7 -> V_48 , 9 ) , F_70 ( V_143 ) ,
V_148 , V_150 , V_143 ) ;
V_145 = (struct V_144 * ) V_143 -> V_151 ;
V_145 -> V_140 = V_141 ;
V_145 -> V_36 = V_36 ;
V_145 -> V_152 = 9 ;
F_71 ( & V_7 -> V_146 , V_143 ) ;
F_72 ( V_141 , V_149 ) ;
}
return 0 ;
}
void F_73 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
T_2 V_153 ;
F_16 ( V_36 , V_154 , & V_153 ) ;
V_153 = V_153 & ~ V_155 ;
V_153 = V_153 | V_156 ;
V_153 = V_153 | V_157 ;
V_153 = V_153 | V_158 ;
V_153 = V_153 | V_159 ;
if ( V_36 -> V_160 & V_161 )
F_74 ( L_48 ) ;
if ( V_7 -> V_12 -> V_121 == V_162 ||
V_36 -> V_160 & V_161 ) {
V_153 = V_153 | V_163 ;
} else {
V_153 = V_153 | V_164 ;
V_153 = V_153 | V_165 ;
}
if ( V_7 -> V_12 -> V_121 == V_162 ) {
V_153 = V_153 | V_166 ;
V_153 = V_153 | V_167 ;
}
if ( V_7 -> V_168 == 1 && V_7 -> V_12 -> V_121 == V_162 )
V_153 = V_153 | V_169 ;
V_153 = V_153 & ~ V_170 ;
V_153 = V_153 | ( V_171 << V_172 ) ;
V_153 = V_153 & ~ V_173 ;
V_153 = V_153 | ( ( T_2 ) 7 << V_174 ) ;
V_153 = V_153 | V_175 ;
F_13 ( V_36 , V_154 , V_153 ) ;
}
void F_75 ( struct V_35 * V_36 )
{
F_63 ( V_36 ) ;
}
void F_76 ( struct V_35 * V_36 )
{
}
void F_77 ( struct V_35 * V_36 )
{
T_1 V_176 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_142 * V_143 ;
struct V_144 * V_145 ;
F_26 ( V_36 , V_177 , & V_176 ) ;
F_24 ( V_36 , V_177 , V_176 & ~ ( V_178 | V_179 ) ) ;
F_29 ( V_36 ) ;
F_60 ( 10 ) ;
while ( ( V_143 = F_78 ( & V_7 -> V_146 ) ) ) {
V_145 = (struct V_144 * ) V_143 -> V_151 ;
if ( ! V_145 -> V_140 )
continue;
F_79 ( V_145 -> V_140 ) ;
F_67 ( V_143 ) ;
}
if ( F_64 ( & V_7 -> V_180 ) )
F_80 ( V_36 , L_49 ) ;
F_81 ( & V_7 -> V_180 ) ;
return;
}
inline T_3 F_82 ( int V_181 )
{
switch ( V_181 ) {
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
inline T_3 F_83 ( short V_181 )
{
if ( V_181 > 11 ) return 0 ;
return V_182 [ V_181 ] ;
}
static void V_150 ( struct V_140 * V_140 )
{
struct V_142 * V_143 = (struct V_142 * ) V_140 -> V_183 ;
struct V_144 * V_145 = (struct V_144 * ) V_143 -> V_151 ;
struct V_35 * V_36 = V_145 -> V_36 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_152 = V_145 -> V_152 ;
int V_184 ;
if ( ! V_7 -> V_185 )
return;
if ( F_84 ( V_140 -> V_46 ) ) {
V_145 -> V_140 = NULL ;
V_7 -> V_67 . V_93 ++ ;
V_7 -> V_12 -> V_67 . V_186 ++ ;
F_85 ( V_140 ) ;
return;
}
F_86 ( V_143 , & V_7 -> V_146 ) ;
F_87 ( V_143 , V_140 -> V_187 ) ;
F_71 ( & V_7 -> V_180 , V_143 ) ;
F_88 ( & V_7 -> V_188 ) ;
V_143 = F_89 ( V_148 ) ;
if ( F_84 ( ! V_143 ) ) {
F_85 ( V_140 ) ;
F_21 ( V_36 , L_50 , V_28 ) ;
return;
}
F_68 ( V_140 , V_7 -> V_48 ,
F_69 ( V_7 -> V_48 , V_152 ) , F_70 ( V_143 ) ,
V_148 , V_150 , V_143 ) ;
V_145 = (struct V_144 * ) V_143 -> V_151 ;
V_145 -> V_140 = V_140 ;
V_145 -> V_36 = V_36 ;
V_145 -> V_152 = V_152 ;
V_140 -> V_189 = F_70 ( V_143 ) ;
V_140 -> V_183 = V_143 ;
F_71 ( & V_7 -> V_146 , V_143 ) ;
V_184 = F_72 ( V_140 , V_190 ) ;
if ( V_184 && V_184 != V_191 )
F_21 ( V_36 , L_51 , V_184 , V_140 -> V_46 ) ;
}
static T_2 F_90 ( struct V_35 * V_36 ,
struct V_134 * V_135 )
{
T_2 V_46 ;
V_46 = F_91 ( V_36 , V_135 ) ;
if ( V_46 )
F_74 ( L_52 ) ;
return V_46 ;
}
static void F_92 ( struct V_35 * V_36 )
{
}
static void F_93 ( struct V_35 * V_36 )
{
}
static void F_94 ( struct V_142 * V_143 , struct V_35 * V_36 , int V_181 )
{
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
int V_192 ;
unsigned long V_160 ;
T_4 * V_193 = ( T_4 * ) ( V_143 -> V_151 + V_194 ) ;
T_1 V_111 = V_193 -> V_111 ;
F_95 ( V_111 != V_195 ) ;
F_96 ( & V_7 -> V_196 , V_160 ) ;
memcpy ( ( unsigned char * ) ( V_143 -> V_151 ) , & V_36 , sizeof( V_36 ) ) ;
V_193 -> V_197 = 1 ;
F_97 ( V_143 , V_7 -> V_12 -> V_198 ) ;
V_192 = F_98 ( V_36 , V_143 ) ;
F_99 ( & V_7 -> V_196 , V_160 ) ;
return;
}
static int F_100 ( struct V_142 * V_143 , struct V_35 * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
int V_192 ;
unsigned long V_160 ;
T_4 * V_193 = ( T_4 * ) ( V_143 -> V_151 + V_194 ) ;
T_1 V_111 = V_193 -> V_111 ;
F_96 ( & V_7 -> V_196 , V_160 ) ;
memcpy ( ( unsigned char * ) ( V_143 -> V_151 ) , & V_36 , sizeof( V_36 ) ) ;
if ( V_111 == V_195 ) {
F_97 ( V_143 , V_199 ) ;
F_101 ( V_36 , V_143 ) ;
V_192 = 1 ;
F_99 ( & V_7 -> V_196 , V_160 ) ;
return V_192 ;
} else {
F_97 ( V_143 , V_7 -> V_12 -> V_198 ) ;
V_192 = F_98 ( V_36 , V_143 ) ;
}
F_99 ( & V_7 -> V_196 , V_160 ) ;
return V_192 ;
}
T_3 F_102 ( struct V_35 * V_36 , struct V_142 * V_143 )
{
T_3 V_200 = 256 - ( ( V_143 -> V_201 + V_202 ) % 256 ) ;
return V_200 & 0xff ;
}
struct V_142 * F_103 ( struct V_35 * V_36 , struct V_203 * V_204 )
{
struct V_10 * V_11 = F_104 ( V_36 ) ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_4 * V_193 = NULL ;
T_1 V_1 ;
T_2 V_205 ;
struct V_142 * V_143 ;
struct V_142 * V_206 ;
T_5 * V_207 = NULL ;
T_6 * V_208 = NULL ;
V_143 = V_204 -> V_209 [ 0 ] ;
V_205 = V_143 -> V_201 ;
for ( V_1 = 1 ; V_1 < V_204 -> V_210 ; V_1 ++ ) {
V_205 += F_102 ( V_36 , V_143 ) ;
V_143 = V_204 -> V_209 [ V_1 ] ;
V_205 += ( V_143 -> V_201 + V_202 ) ;
}
V_206 = F_89 ( V_205 + V_11 -> V_198 ) ;
memset ( V_206 -> V_42 , 0 , V_206 -> V_201 ) ;
F_105 ( V_206 , V_11 -> V_198 ) ;
V_143 = V_204 -> V_209 [ 0 ] ;
V_193 = ( T_4 * ) ( V_143 -> V_151 + V_194 ) ;
V_193 -> V_211 = 1 ;
V_193 -> V_212 = V_143 -> V_201 ;
V_193 -> V_213 = V_204 -> V_210 ;
F_106 ( V_36 , L_53 , V_193 -> V_213 ) ;
memcpy ( V_206 -> V_151 , V_143 -> V_151 , sizeof( V_143 -> V_151 ) ) ;
memcpy ( F_87 ( V_206 , V_143 -> V_201 ) , V_143 -> V_42 , V_143 -> V_201 ) ;
for ( V_1 = 1 ; V_1 < V_204 -> V_210 ; V_1 ++ ) {
F_87 ( V_206 , F_102 ( V_36 , V_143 ) ) ;
V_143 = V_204 -> V_209 [ V_1 ] ;
V_193 = ( T_4 * ) ( V_143 -> V_151 + V_194 ) ;
V_207 = ( T_5 * ) F_70 ( V_206 ) ;
V_208 = ( T_6 * ) ( F_70 ( V_206 ) + sizeof( T_5 ) ) ;
memset ( V_208 , 0 , sizeof( T_6 ) ) ;
V_208 -> V_214 = ( V_193 -> V_215 & 0x80 ) ? 1 : 0 ;
V_208 -> V_216 = F_107 ( V_193 -> V_215 ) ;
V_208 -> V_217 = V_193 -> V_197 ;
V_208 -> Short = F_108 ( V_208 -> V_214 , V_208 -> V_216 , V_193 ) ;
if ( V_193 -> V_218 ) {
V_208 -> V_219 = 1 ;
V_208 -> V_220 = V_193 -> V_221 ;
V_208 -> V_222 = V_193 -> V_223 & 0x07 ;
} else {
V_208 -> V_219 = 0 ;
V_208 -> V_220 = 0 ;
V_208 -> V_222 = 0 ;
}
V_208 -> V_224 = ( V_193 -> V_225 ) ? 1 : 0 ;
V_208 -> V_226 = ( V_193 -> V_227 ) ? 1 : 0 ;
V_208 -> V_228 = ( V_193 -> V_229 ) ? 1 : 0 ;
V_208 -> V_230 = ( V_193 -> V_231 & 0x80 ) ? 1 : 0 ;
V_208 -> V_232 = F_107 ( ( T_1 ) V_193 -> V_231 ) ;
V_208 -> V_233 = ( V_208 -> V_230 == 0 ) ? ( V_193 -> V_234 ) : 0 ;
V_208 -> V_235 = ( V_208 -> V_230 == 1 ) ? ( ( V_193 -> V_236 ) ? 1 : 0 ) : 0 ;
V_208 -> V_237 = ( V_208 -> V_230 == 0 ) ? ( V_193 -> V_238 ? 1 : 0 ) :
( V_193 -> V_239 ? 1 : 0 ) ;
if ( V_7 -> V_240 == V_241 ) {
if ( V_193 -> V_242 ) {
V_208 -> V_243 = 1 ;
V_208 -> V_244 = 0 ;
} else {
V_208 -> V_243 = 0 ;
V_208 -> V_244 = V_7 -> V_245 ;
}
} else {
V_208 -> V_243 = 0 ;
V_208 -> V_244 = 0 ;
}
memset ( V_207 , 0 , sizeof( T_5 ) ) ;
V_207 -> V_246 = sizeof( T_6 ) + 8 ;
V_207 -> V_247 = V_143 -> V_201 & 0xffff ;
V_207 -> V_248 = 0 ;
V_207 -> V_249 = V_193 -> V_250 ;
V_207 -> V_251 = 1 ;
V_207 -> V_252 = 0x0 ;
if ( V_193 -> V_253 ) {
switch ( V_7 -> V_12 -> V_254 ) {
case V_255 :
case V_256 :
V_207 -> V_252 = 0x1 ;
V_207 -> V_251 = 0 ;
break;
case V_257 :
V_207 -> V_252 = 0x2 ;
V_207 -> V_251 = 0 ;
break;
case V_258 :
V_207 -> V_252 = 0x3 ;
V_207 -> V_251 = 0 ;
break;
case V_259 :
V_207 -> V_252 = 0x0 ;
V_207 -> V_251 = 1 ;
break;
}
}
V_207 -> V_260 = F_109 ( V_193 -> V_111 ) ;
V_207 -> V_261 = sizeof( T_6 ) ;
V_207 -> V_262 = V_193 -> V_263 ;
V_207 -> V_264 = V_193 -> V_265 ;
V_207 -> V_266 = 1 ;
F_87 ( V_206 , V_202 ) ;
memcpy ( F_87 ( V_206 , V_143 -> V_201 ) , V_143 -> V_42 , V_143 -> V_201 ) ;
}
for ( V_1 = 0 ; V_1 < V_204 -> V_210 ; V_1 ++ )
F_110 ( V_204 -> V_209 [ V_1 ] ) ;
return V_206 ;
}
T_1 F_111 ( struct V_35 * V_36 , struct V_142 * V_143 ,
struct V_203 * V_204 )
{
struct V_10 * V_11 = F_104 ( V_36 ) ;
T_7 V_267 = V_11 -> V_267 ;
T_3 V_268 = V_267 -> V_269 ;
T_4 * V_193 = ( T_4 * ) ( V_143 -> V_151 + V_194 ) ;
T_1 V_270 = V_193 -> V_111 ;
do {
V_204 -> V_209 [ V_204 -> V_210 ++ ] = V_143 ;
if ( V_204 -> V_210 >= V_268 )
break;
} while ( ( V_143 = F_112 ( & V_11 -> V_271 [ V_270 ] ) ) );
F_9 ( V_272 , L_54 , V_204 -> V_210 ) ;
return V_204 -> V_210 ;
}
static void F_113 ( struct V_140 * V_273 )
{
struct V_142 * V_143 = (struct V_142 * ) V_273 -> V_183 ;
struct V_35 * V_36 = NULL ;
struct V_6 * V_7 = NULL ;
T_4 * V_193 = ( T_4 * ) ( V_143 -> V_151 + V_194 ) ;
T_1 V_111 = V_193 -> V_111 ;
memcpy ( & V_36 , (struct V_35 * ) ( V_143 -> V_151 ) , sizeof( struct V_35 * ) ) ;
V_7 = F_18 ( V_36 ) ;
if ( V_193 -> V_111 != V_195 ) {
if ( V_273 -> V_46 == 0 ) {
V_36 -> V_274 = V_275 ;
V_7 -> V_67 . V_276 ++ ;
V_7 -> V_12 -> V_277 . V_278 ++ ;
V_7 -> V_67 . V_279 += ( V_143 -> V_201 - V_7 -> V_12 -> V_198 ) ;
} else {
V_7 -> V_12 -> V_67 . V_280 ++ ;
}
}
if ( V_143 != NULL ) {
F_110 ( V_143 ) ;
F_85 ( V_273 ) ;
F_114 ( & V_7 -> V_82 [ V_111 ] ) ;
}
if ( V_111 != V_281 ) {
if ( ( F_64 ( & V_7 -> V_12 -> V_282 [ V_111 ] ) != 0 ) &&
( ! ( V_7 -> V_12 -> V_283 ) ) ) {
V_143 = F_112 ( & ( V_7 -> V_12 -> V_282 [ V_111 ] ) ) ;
if ( V_143 )
V_7 -> V_12 -> V_284 ( V_143 , V_36 ) ;
return;
}
#ifdef F_115
else if ( ( F_64 ( & V_7 -> V_12 -> V_271 [ V_111 ] ) != 0 ) &&
( ! ( V_7 -> V_12 -> V_283 ) ) ) {
V_143 = F_112 ( & V_7 -> V_12 -> V_271 [ V_111 ] ) ;
if ( ! F_52 ( V_36 , V_111 ) ) {
F_116 ( & ( V_7 -> V_12 -> V_271 [ V_111 ] ) , V_143 ) ;
return;
}
{
struct V_203 V_285 ;
memset ( & V_285 , 0 , sizeof( struct V_203 ) ) ;
if ( F_111 ( V_36 , V_143 , & V_285 ) > 1 ) {
V_143 = F_103 ( V_36 , & V_285 ) ;
}
}
V_7 -> V_12 -> V_284 ( V_143 , V_36 ) ;
}
#endif
}
}
static void F_117 ( struct V_35 * V_36 , T_3 * V_286 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_58 * V_287 ;
T_1 V_1 = 0 , V_288 = 0 ;
V_287 = & V_7 -> V_12 -> V_289 ;
for ( V_1 = 0 ; V_1 < V_287 -> V_290 ; V_1 ++ ) {
V_288 = V_287 -> V_291 [ V_1 ] & 0x7f ;
switch ( V_288 ) {
case V_292 : * V_286 |= V_293 ; break;
case V_294 : * V_286 |= V_295 ; break;
case V_296 : * V_286 |= V_297 ; break;
case V_298 : * V_286 |= V_299 ; break;
case V_300 : * V_286 |= V_301 ; break;
case V_302 : * V_286 |= V_303 ; break;
case V_304 : * V_286 |= V_305 ; break;
case V_306 : * V_286 |= V_307 ; break;
case V_308 : * V_286 |= V_309 ; break;
case V_310 : * V_286 |= V_311 ; break;
case V_312 : * V_286 |= V_313 ; break;
case V_314 : * V_286 |= V_315 ; break;
}
}
for ( V_1 = 0 ; V_1 < V_287 -> V_316 ; V_1 ++ ) {
V_288 = V_287 -> V_317 [ V_1 ] & 0x7f ;
switch ( V_288 ) {
case V_292 : * V_286 |= V_293 ; break;
case V_294 : * V_286 |= V_295 ; break;
case V_296 : * V_286 |= V_297 ; break;
case V_298 : * V_286 |= V_299 ; break;
case V_300 : * V_286 |= V_301 ; break;
case V_302 : * V_286 |= V_303 ; break;
case V_304 : * V_286 |= V_305 ; break;
case V_306 : * V_286 |= V_307 ; break;
case V_308 : * V_286 |= V_309 ; break;
case V_310 : * V_286 |= V_311 ; break;
case V_312 : * V_286 |= V_313 ; break;
case V_314 : * V_286 |= V_315 ; break;
}
}
}
static void F_118 ( struct V_35 * V_36 , T_3 V_318 )
{
T_2 V_319 = 0 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_58 * V_287 = & V_7 -> V_12 -> V_289 ;
V_7 -> V_320 = V_318 & V_321 ;
V_319 = V_7 -> V_288 ;
if ( V_7 -> V_320 )
V_319 |= V_322 ;
F_13 ( V_36 , V_323 , V_319 ) ;
if ( V_287 -> V_324 & ( V_325 | V_326 ) ) {
T_1 V_327 = 0 ;
if ( ( V_318 & V_328 ) && ( ! V_7 -> V_12 -> V_267 -> V_329 ) )
V_327 = V_330 ;
else
V_327 = V_331 ;
V_7 -> V_327 = V_327 ;
F_24 ( V_36 , V_332 , V_327 ) ;
}
}
static void F_119 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_58 * V_287 ;
T_3 V_333 = 0 , V_334 = 6 , V_335 = 0xf ;
T_3 V_286 = 0 ;
V_287 = & V_7 -> V_12 -> V_289 ;
F_117 ( V_36 , & V_286 ) ;
V_7 -> V_288 = V_286 &= 0x15f ;
F_13 ( V_36 , V_336 , ( ( T_2 * ) V_287 -> V_337 ) [ 0 ] ) ;
F_25 ( V_36 , V_336 + 4 , ( ( T_3 * ) V_287 -> V_337 ) [ 2 ] ) ;
F_57 ( V_36 ) ;
if ( V_7 -> V_12 -> V_121 == V_125 ) {
F_25 ( V_36 , V_338 , 2 ) ;
F_25 ( V_36 , V_339 , 1023 ) ;
F_25 ( V_36 , V_340 , V_287 -> V_341 ) ;
F_25 ( V_36 , V_342 , 1 ) ;
F_24 ( V_36 , V_343 , 100 ) ;
V_333 |= ( V_334 << V_344 ) ;
V_333 |= V_335 << V_345 ;
F_25 ( V_36 , V_346 , V_333 ) ;
}
}
void F_120 ( struct V_35 * V_36 , T_3 V_347 )
{
}
inline T_1 F_121 ( T_3 V_181 )
{
if ( ( ( V_181 <= 110 ) && ( V_181 != 60 ) && ( V_181 != 90 ) ) || ( V_181 == 220 ) )
return 1 ;
else return 0 ;
}
T_3 F_122 ( T_3 V_348 , T_3 V_349 , T_1 V_350 ,
T_1 V_351 )
{
T_3 V_352 ;
T_3 V_353 ;
T_3 V_354 ;
if ( F_121 ( V_349 ) ) {
if ( V_350 || ! V_351 || V_349 == 10 )
V_352 = ( T_3 ) ( 144 + 48 + ( V_348 * 8 / ( V_349 / 10 ) ) ) ;
else
V_352 = ( T_3 ) ( 72 + 24 + ( V_348 * 8 / ( V_349 / 10 ) ) ) ;
if ( ( V_348 * 8 % ( V_349 / 10 ) ) != 0 )
V_352 ++ ;
} else {
V_353 = F_123 ( V_349 ) ;
V_354 = ( 16 + 8 * V_348 + 6 ) / V_353
+ ( ( ( 16 + 8 * V_348 + 6 ) % V_353 ) ? 1 : 0 ) ;
V_352 = ( T_3 ) ( 16 + 4 + 4 * V_354 + 6 ) ;
}
return V_352 ;
}
T_3 F_123 ( T_3 V_349 )
{
T_3 V_353 = 24 ;
switch ( V_349 ) {
case 60 :
V_353 = 24 ;
break;
case 90 :
V_353 = 36 ;
break;
case 120 :
V_353 = 48 ;
break;
case 180 :
V_353 = 72 ;
break;
case 240 :
V_353 = 96 ;
break;
case 360 :
V_353 = 144 ;
break;
case 480 :
V_353 = 192 ;
break;
case 540 :
V_353 = 216 ;
break;
default:
break;
}
return V_353 ;
}
unsigned int F_124 ( struct V_6 * V_7 , unsigned int V_355 )
{
if ( V_355 >= 9 ) {
F_9 ( V_27 , L_55 , V_28 ) ;
return 0x04 ;
}
return V_7 -> V_356 [ V_355 ] ;
}
short F_101 ( struct V_35 * V_36 , struct V_142 * V_143 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_46 ;
struct V_140 * V_273 ;
unsigned int V_357 ;
T_8 * V_358 = ( T_8 * ) V_143 -> V_42 ;
T_4 * V_193 = ( T_4 * ) ( V_143 -> V_151 + V_194 ) ;
T_1 V_111 = V_193 -> V_111 ;
F_125 ( & V_7 -> V_82 [ V_111 ] ) ;
V_273 = F_66 ( 0 , V_190 ) ;
if ( ! V_273 ) {
F_126 ( V_143 ) ;
return - V_359 ;
}
memset ( V_358 , 0 , V_199 ) ;
V_358 -> V_360 = 1 ;
V_358 -> V_361 = 1 ;
V_358 -> V_362 = V_193 -> V_363 ;
V_358 -> V_364 = V_193 -> V_365 ;
V_358 -> V_266 = 1 ;
V_358 -> V_366 = V_193 -> V_367 ;
#ifndef F_127
V_357 = F_124 ( V_7 , V_111 ) ;
#else
V_357 = 0x04 ;
#endif
F_68 ( V_273 , V_7 -> V_48 , F_128 ( V_7 -> V_48 , V_357 ) ,
V_143 -> V_42 , V_143 -> V_201 , F_113 , V_143 ) ;
V_46 = F_72 ( V_273 , V_190 ) ;
if ( ! V_46 ) {
return 0 ;
} else {
F_129 ( L_56 , V_46 ) ;
return - 1 ;
}
}
static T_1 F_109 ( T_1 V_270 )
{
T_1 V_260 = 0x0 ;
switch ( V_270 ) {
case V_368 :
V_260 = V_369 ;
break;
case V_370 :
V_260 = V_371 ;
break;
case V_372 :
V_260 = V_373 ;
break;
case V_374 :
V_260 = V_375 ;
break;
case V_376 :
V_260 = V_377 ;
break;
case V_281 :
V_260 = V_378 ;
break;
case V_195 :
V_260 = V_379 ;
break;
case V_380 :
V_260 = V_381 ;
break;
default:
F_9 ( V_27 , L_57 , V_270 ) ;
break;
}
return V_260 ;
}
static T_1 F_107 ( T_1 V_181 )
{
T_1 V_192 = V_382 ;
switch ( V_181 ) {
case V_292 : V_192 = V_382 ; break;
case V_294 : V_192 = V_383 ; break;
case V_296 : V_192 = V_384 ; break;
case V_298 : V_192 = V_385 ; break;
case V_300 : V_192 = V_386 ; break;
case V_302 : V_192 = V_387 ; break;
case V_304 : V_192 = V_388 ; break;
case V_306 : V_192 = V_389 ; break;
case V_308 : V_192 = V_390 ; break;
case V_310 : V_192 = V_391 ; break;
case V_312 : V_192 = V_392 ; break;
case V_314 : V_192 = V_393 ; break;
case V_394 : V_192 = V_395 ; break;
case V_396 : V_192 = V_397 ; break;
case V_398 : V_192 = V_399 ; break;
case V_400 : V_192 = V_401 ; break;
case V_402 : V_192 = V_403 ; break;
case V_404 : V_192 = V_405 ; break;
case V_406 : V_192 = V_407 ; break;
case V_408 : V_192 = V_409 ; break;
case V_410 : V_192 = V_411 ; break;
case V_412 : V_192 = V_413 ; break;
case V_414 : V_192 = V_415 ; break;
case V_416 : V_192 = V_417 ; break;
case V_418 : V_192 = V_419 ; break;
case V_420 : V_192 = V_421 ; break;
case V_422 : V_192 = V_423 ; break;
case V_424 : V_192 = V_425 ; break;
case ( 0x80 | 0x20 ) : V_192 = V_426 ; break;
default: break;
}
return V_192 ;
}
static T_1 F_108 ( T_1 V_214 , T_1 V_216 , T_4 * V_193 )
{
T_1 V_427 ;
V_427 = ( V_214 == 1 ) ? ( ( V_193 -> V_428 ) ? 1 : 0 ) : ( ( V_193 -> V_429 ) ? 1 : 0 ) ;
if ( V_214 == 1 && V_216 != V_425 )
V_427 = 0 ;
return V_427 ;
}
static void F_130 ( struct V_140 * V_273 )
{
return;
}
short F_98 ( struct V_35 * V_36 , struct V_142 * V_143 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_4 * V_193 = ( T_4 * ) ( V_143 -> V_151 + V_194 ) ;
T_9 * V_430 = ( T_9 * ) V_143 -> V_42 ;
T_6 * V_208 = ( T_6 * ) ( V_143 -> V_42 + V_199 ) ;
struct V_47 * V_48 = V_7 -> V_48 ;
int V_431 ;
int V_46 ;
struct V_140 * V_273 = NULL , * V_432 = NULL ;
unsigned int V_357 ;
V_431 = F_38 ( & V_7 -> V_82 [ V_193 -> V_111 ] ) ;
if ( V_431 > V_113 ) {
F_106 ( V_36 , L_58 ) ;
F_110 ( V_143 ) ;
return - 1 ;
}
V_273 = F_66 ( 0 , V_190 ) ;
if ( ! V_273 ) {
F_110 ( V_143 ) ;
return - V_359 ;
}
memset ( V_208 , 0 , sizeof( T_6 ) ) ;
V_208 -> V_214 = ( V_193 -> V_215 & 0x80 ) ? 1 : 0 ;
V_208 -> V_216 = F_107 ( V_193 -> V_215 ) ;
V_208 -> V_217 = V_193 -> V_197 ;
V_208 -> Short = F_108 ( V_208 -> V_214 , V_208 -> V_216 , V_193 ) ;
if ( V_193 -> V_218 ) {
V_208 -> V_219 = 1 ;
V_208 -> V_220 = V_193 -> V_221 ;
V_208 -> V_222 = V_193 -> V_223 & 0x07 ;
} else {
V_208 -> V_219 = 0 ;
V_208 -> V_220 = 0 ;
V_208 -> V_222 = 0 ;
}
V_208 -> V_224 = ( V_193 -> V_225 ) ? 1 : 0 ;
V_208 -> V_226 = ( V_193 -> V_227 ) ? 1 : 0 ;
V_208 -> V_228 = ( V_193 -> V_229 ) ? 1 : 0 ;
V_208 -> V_230 = ( V_193 -> V_231 & 0x80 ) ? 1 : 0 ;
V_208 -> V_232 = F_107 ( ( T_1 ) V_193 -> V_231 ) ;
V_208 -> V_233 = ( V_208 -> V_230 == 0 ) ? ( V_193 -> V_234 ) : 0 ;
V_208 -> V_235 = ( V_208 -> V_230 == 1 ) ? ( ( V_193 -> V_236 ) ? 1 : 0 ) : 0 ;
V_208 -> V_237 = ( V_208 -> V_230 == 0 ) ? ( V_193 -> V_238 ? 1 : 0 ) :
( V_193 -> V_239 ? 1 : 0 ) ;
if ( V_7 -> V_240 == V_241 ) {
if ( V_193 -> V_242 ) {
V_208 -> V_243 = 1 ;
V_208 -> V_244 = 0 ;
} else {
V_208 -> V_243 = 0 ;
V_208 -> V_244 = V_7 -> V_245 ;
}
} else {
V_208 -> V_243 = 0 ;
V_208 -> V_244 = 0 ;
}
#ifdef F_115
if ( V_193 -> V_211 )
V_208 -> V_433 = ( V_193 -> V_213 & 0x1f ) << 1 ;
#endif
memset ( V_430 , 0 , sizeof( T_9 ) ) ;
V_430 -> V_366 = 0 ;
V_430 -> V_362 = 1 ;
V_430 -> V_246 = sizeof( T_6 ) + 8 ;
#ifdef F_115
if ( V_193 -> V_211 )
V_430 -> V_247 = V_193 -> V_212 ;
else
#endif
{
V_430 -> V_247 = ( V_143 -> V_201 - V_434 ) & 0xffff ;
}
V_430 -> V_248 = 0 ;
V_430 -> V_249 = V_193 -> V_250 ;
V_430 -> V_251 = 1 ;
V_430 -> V_252 = 0x0 ;
if ( V_193 -> V_253 ) {
switch ( V_7 -> V_12 -> V_254 ) {
case V_255 :
case V_256 :
V_430 -> V_252 = 0x1 ;
V_430 -> V_251 = 0 ;
break;
case V_257 :
V_430 -> V_252 = 0x2 ;
V_430 -> V_251 = 0 ;
break;
case V_258 :
V_430 -> V_252 = 0x3 ;
V_430 -> V_251 = 0 ;
break;
case V_259 :
V_430 -> V_252 = 0x0 ;
V_430 -> V_251 = 1 ;
break;
}
}
V_430 -> V_260 = F_109 ( V_193 -> V_111 ) ;
V_430 -> V_261 = sizeof( T_6 ) ;
V_430 -> V_262 = V_193 -> V_263 ;
V_430 -> V_264 = V_193 -> V_265 ;
V_430 -> V_360 = 1 ;
V_430 -> V_361 = 1 ;
V_430 -> V_266 = 1 ;
#ifdef F_115
if ( V_193 -> V_211 ) {
V_430 -> V_364 = V_193 -> V_212 + sizeof( T_6 ) ;
} else
#endif
{
V_430 -> V_364 = ( T_2 ) ( V_143 -> V_201 - V_199 ) ;
}
#ifndef F_127
V_357 = F_124 ( V_7 , V_193 -> V_111 ) ;
#else
V_357 = 0x5 ;
#endif
F_68 ( V_273 , V_48 ,
F_128 ( V_48 , V_357 ) , V_143 -> V_42 ,
V_143 -> V_201 , F_113 , V_143 ) ;
V_46 = F_72 ( V_273 , V_190 ) ;
if ( ! V_46 ) {
bool V_435 = false ;
T_1 V_436 = 0 ;
if ( V_48 -> V_437 == V_438 ) {
if ( V_143 -> V_201 > 0 && V_143 -> V_201 % 512 == 0 )
V_435 = true ;
} else {
if ( V_143 -> V_201 > 0 && V_143 -> V_201 % 64 == 0 )
V_435 = true ;
}
if ( V_435 ) {
V_432 = F_66 ( 0 , V_190 ) ;
if ( ! V_432 ) {
F_9 ( V_27 , L_59 ) ;
return - V_359 ;
}
F_68 ( V_432 , V_48 ,
F_128 ( V_48 , V_357 ) , & V_436 ,
0 , F_130 , V_36 ) ;
V_46 = F_72 ( V_432 , V_190 ) ;
if ( V_46 ) {
F_9 ( V_27 , L_60 , F_38 ( & V_7 -> V_82 [ V_193 -> V_111 ] ) , V_46 ) ;
return - 1 ;
}
}
V_36 -> V_274 = V_275 ;
F_125 ( & V_7 -> V_82 [ V_193 -> V_111 ] ) ;
return 0 ;
} else {
F_9 ( V_27 , L_61 , F_38 ( & V_7 -> V_82 [ V_193 -> V_111 ] ) ,
V_46 ) ;
return - 1 ;
}
}
static short F_131 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
V_7 -> V_439 = F_132 ( sizeof( struct V_140 * ) * ( V_147 + 1 ) ,
V_149 ) ;
if ( V_7 -> V_439 == NULL )
return - V_359 ;
#ifndef F_133
for ( V_1 = 0 ; V_1 < ( V_147 + 1 ) ; V_1 ++ ) {
V_7 -> V_439 [ V_1 ] = F_66 ( 0 , V_149 ) ;
V_7 -> V_439 [ V_1 ] -> V_189 = F_132 ( V_148 , V_149 ) ;
V_7 -> V_439 [ V_1 ] -> V_440 = V_148 ;
}
#endif
#ifdef F_134
{
long V_441 = 0 ;
void * V_442 , * V_443 ;
V_7 -> V_439 [ 16 ] = F_66 ( 0 , V_149 ) ;
V_7 -> V_442 = F_132 ( 16 , V_149 ) ;
V_442 = V_7 -> V_442 ;
V_441 = ( ( long ) V_442 ) & 3 ;
if ( V_441 ) {
V_443 = V_442 + 4 - V_441 ;
V_7 -> V_439 [ 16 ] -> V_440 = 16 - 4 + V_441 ;
} else {
V_443 = V_442 ;
V_7 -> V_439 [ 16 ] -> V_440 = 16 ;
}
V_7 -> V_439 [ 16 ] -> V_189 = V_443 ;
}
#endif
memset ( V_7 -> V_439 , 0 , sizeof( struct V_140 * ) * V_147 ) ;
V_7 -> V_444 = F_135 ( V_147 , sizeof( struct V_142 * ) ,
V_149 ) ;
if ( ! V_7 -> V_444 ) {
F_136 ( V_7 -> V_439 ) ;
V_7 -> V_444 = NULL ;
V_7 -> V_439 = NULL ;
F_129 ( L_62 ) ;
return - V_359 ;
}
F_106 ( V_36 , L_63 ) ;
return 0 ;
}
static void F_137 ( struct V_35 * V_36 )
{
int V_1 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
if ( V_7 -> V_439 ) {
for ( V_1 = 0 ; V_1 < ( V_147 + 1 ) ; V_1 ++ ) {
F_79 ( V_7 -> V_439 [ V_1 ] ) ;
F_85 ( V_7 -> V_439 [ V_1 ] ) ;
}
F_136 ( V_7 -> V_439 ) ;
V_7 -> V_439 = NULL ;
}
F_136 ( V_7 -> V_442 ) ;
V_7 -> V_442 = NULL ;
if ( V_7 -> V_444 ) {
F_136 ( V_7 -> V_444 ) ;
V_7 -> V_444 = NULL ;
}
}
void F_137 ( struct V_35 * V_36 )
{
int V_1 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
#ifndef F_133
if ( V_7 -> V_439 ) {
for ( V_1 = 0 ; V_1 < ( V_147 + 1 ) ; V_1 ++ ) {
F_79 ( V_7 -> V_439 [ V_1 ] ) ;
F_136 ( V_7 -> V_439 [ V_1 ] -> V_189 ) ;
F_85 ( V_7 -> V_439 [ V_1 ] ) ;
}
F_136 ( V_7 -> V_439 ) ;
V_7 -> V_439 = NULL ;
}
#else
F_136 ( V_7 -> V_439 ) ;
V_7 -> V_439 = NULL ;
F_136 ( V_7 -> V_442 ) ;
V_7 -> V_442 = NULL ;
if ( V_7 -> V_444 ) {
F_136 ( V_7 -> V_444 ) ;
V_7 -> V_444 = 0 ;
}
#endif
}
static void F_138 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
if ( V_11 -> V_119 == V_120 ) {
F_119 ( V_36 ) ;
F_139 ( V_36 ) ;
if ( ( V_255 == V_11 -> V_254 ) || ( V_256 == V_11 -> V_254 ) )
F_140 ( V_36 ) ;
}
if ( V_11 -> V_121 == V_122 || V_11 -> V_121 == V_125 ) {
T_2 V_445 = 0 ;
F_16 ( V_36 , V_154 , & V_445 ) ;
if ( V_7 -> V_12 -> V_119 == V_120 )
V_7 -> V_446 = V_445 |= V_165 ;
else
V_7 -> V_446 = V_445 &= ~ V_165 ;
F_13 ( V_36 , V_154 , V_445 ) ;
}
}
static void F_141 ( struct V_447 * V_448 )
{
struct V_6 * V_7 = F_142 ( V_448 , struct V_6 , V_449 . V_448 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_58 * V_287 = & V_11 -> V_289 ;
if ( V_11 -> V_267 -> V_450 )
F_143 ( V_11 , V_287 ) ;
V_11 -> V_267 -> V_329 = V_287 -> V_451 . V_452 ;
F_118 ( V_36 , V_287 -> V_453 ) ;
}
static void F_144 ( struct V_447 * V_448 )
{
struct V_6 * V_7 = F_142 ( V_448 , struct V_6 , V_454 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
struct V_455 * V_456 = & V_7 -> V_12 -> V_289 . V_457 . V_458 ;
T_1 V_324 = V_7 -> V_12 -> V_289 . V_324 ;
T_1 V_459 ;
T_2 V_460 ;
int V_1 ;
F_145 ( & V_7 -> V_461 ) ;
if ( V_7 -> V_12 -> V_119 != V_120 )
goto V_462;
F_9 ( V_463 , L_64 ) ;
for ( V_1 = 0 ; V_1 < V_464 ; V_1 ++ ) {
V_459 = V_456 -> V_465 [ V_1 ] * ( ( V_324 & ( V_325 | V_326 ) ) ? 9 : 20 ) + V_466 ;
V_460 = ( ( ( ( T_2 ) ( V_456 -> V_467 [ V_1 ] ) ) << V_468 ) |
( ( ( T_2 ) ( V_456 -> V_469 [ V_1 ] ) ) << V_470 ) |
( ( ( T_2 ) ( V_456 -> V_471 [ V_1 ] ) ) << V_472 ) |
( ( T_2 ) V_459 << V_473 ) ) ;
F_13 ( V_36 , V_474 [ V_1 ] , V_460 ) ;
}
V_462:
F_146 ( & V_7 -> V_461 ) ;
}
static int F_147 ( struct V_6 * V_7 ,
int V_475 ,
struct V_58 * V_476 )
{
int V_192 = 0 ;
T_2 V_477 = sizeof( struct V_455 ) ;
if ( V_7 -> V_12 -> V_119 != V_120 )
return V_192 ;
if ( ( V_7 -> V_12 -> V_121 != V_122 ) )
return V_192 ;
if ( V_476 -> V_160 & V_478 ) {
if ( V_475 &&
( V_476 -> V_160 & V_479 ) )
V_476 -> V_457 . V_480 = V_476 -> V_457 . V_481 ;
if ( ( V_476 -> V_457 . V_480 == 1 ) && ( V_475 == 1 ) &&
( V_476 -> V_160 & V_479 ) &&
( V_476 -> V_457 . V_482 !=
V_476 -> V_457 . V_483 ) ) {
V_476 -> V_457 . V_482 =
V_476 -> V_457 . V_483 ;
F_148 ( V_7 -> V_484 , & V_7 -> V_454 ) ;
F_9 ( V_463 , L_65
L_66 ) ;
}
} else {
memcpy ( & V_7 -> V_12 -> V_289 . V_457 . V_458 ,
& V_485 , V_477 ) ;
if ( ( V_476 -> V_457 . V_480 == 1 ) && ( V_475 == 1 ) ) {
F_148 ( V_7 -> V_484 , & V_7 -> V_454 ) ;
F_9 ( V_463 , L_67 ) ;
}
V_476 -> V_457 . V_480 = 0 ;
V_476 -> V_457 . V_481 = 0 ;
}
return 0 ;
}
static int F_149 ( struct V_35 * V_36 ,
struct V_486 * V_487 ,
struct V_58 * V_476 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
F_147 ( V_7 , 1 , V_476 ) ;
F_150 ( V_7 -> V_484 , & V_7 -> V_449 , 0 ) ;
return 0 ;
}
static int F_151 ( struct V_6 * V_7 ,
struct V_58 * V_476 )
{
int V_192 = 0 ;
unsigned long V_160 ;
T_2 V_477 = sizeof( struct V_455 ) ;
int V_488 = 0 ;
if ( ( V_7 == NULL ) || ( V_476 == NULL ) )
return V_192 ;
if ( V_7 -> V_12 -> V_119 != V_120 )
return V_192 ;
if ( ( V_7 -> V_12 -> V_121 != V_122 ) )
return V_192 ;
F_96 ( & V_7 -> V_12 -> V_489 , V_160 ) ;
if ( V_476 -> V_160 & V_479 ) {
memcpy ( & V_7 -> V_12 -> V_289 . V_457 . V_458 ,
& V_476 -> V_457 . V_458 ,
sizeof( struct V_455 ) ) ;
V_7 -> V_12 -> V_289 . V_457 . V_480 = 1 ;
V_488 = 1 ;
V_7 -> V_12 -> V_289 . V_457 . V_482 =
V_7 -> V_12 -> V_289 . V_457 . V_483 ;
V_7 -> V_12 -> V_289 . V_457 . V_483 =
V_476 -> V_457 . V_483 ;
} else {
memcpy ( & V_7 -> V_12 -> V_289 . V_457 . V_458 ,
& V_485 , V_477 ) ;
V_7 -> V_12 -> V_289 . V_457 . V_480 = 0 ;
V_7 -> V_12 -> V_289 . V_457 . V_481 = 0 ;
V_488 = 1 ;
}
F_99 ( & V_7 -> V_12 -> V_489 , V_160 ) ;
F_9 ( V_463 , L_68 , V_28 , V_476 -> V_160 , V_7 -> V_12 -> V_289 . V_457 . V_480 ) ;
if ( V_488 == 1 )
F_148 ( V_7 -> V_484 , & V_7 -> V_454 ) ;
return V_192 ;
}
static int F_152 ( struct V_35 * V_36 ,
struct V_490 * V_491 ,
struct V_58 * V_476 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
F_151 ( V_7 , V_476 ) ;
return 0 ;
}
void F_139 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
T_1 * V_492 = V_11 -> V_493 ;
T_2 V_494 = 0 ;
T_1 V_495 = 0 ;
F_117 ( V_36 , ( T_3 * ) ( & V_494 ) ) ;
V_494 |= ( * ( T_3 * ) ( V_492 ) ) << 12 ;
switch ( V_11 -> V_324 ) {
case V_496 :
V_494 &= 0x00000FF0 ;
break;
case V_497 :
V_494 &= 0x0000000F ;
break;
case V_325 :
V_494 &= 0x00000FF7 ;
break;
case V_326 :
case V_498 :
if ( V_11 -> V_267 -> V_499 == 0 ) {
V_494 &= 0x0007F007 ;
} else {
if ( V_7 -> V_500 == V_501 )
V_494 &= 0x000FF007 ;
else
V_494 &= 0x0F81F007 ;
}
break;
default:
break;
}
V_494 &= 0x0FFFFFFF ;
if ( V_11 -> V_267 -> V_502 && V_11 -> V_267 -> V_503 )
V_494 |= 0x80000000 ;
else if ( ! V_11 -> V_267 -> V_502 && V_11 -> V_267 -> V_504 )
V_494 |= 0x80000000 ;
F_13 ( V_36 , V_505 + V_495 * 4 , V_494 ) ;
F_24 ( V_36 , V_506 , 1 ) ;
}
static bool F_153 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_58 * V_476 = & V_11 -> V_289 ;
int V_61 = V_11 -> V_61 ;
struct V_507 * V_508 ;
int V_509 ;
V_508 = V_11 -> V_508 [ V_11 -> V_510 ] ;
V_509 = ( V_476 -> V_453 & V_511 ) || ( V_11 -> V_512 && V_508 && V_508 -> V_513 && ( 0 == strcmp ( V_508 -> V_513 -> V_106 , L_69 ) ) ) ;
if ( V_509 && ( V_61 == 0 ) ) {
return false ;
} else if ( ( V_61 != 0 ) ) {
if ( ( ( V_11 -> V_514 [ 0 ] == 0xdd ) && ( ! memcmp ( & ( V_11 -> V_514 [ 14 ] ) , V_515 , 4 ) ) ) || ( ( V_11 -> V_514 [ 0 ] == 0x30 ) && ( ! memcmp ( & V_11 -> V_514 [ 10 ] , V_516 , 4 ) ) ) )
return true ;
else
return false ;
} else {
return true ;
}
return true ;
}
static bool F_154 ( struct V_35 * V_36 )
{
bool V_517 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
if ( V_11 -> V_518 == true )
V_517 = true ;
else
V_517 = false ;
return V_517 ;
}
static void F_155 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
if ( V_11 -> V_324 == V_519 || V_11 -> V_324 == V_520 )
memcpy ( V_11 -> V_521 , V_11 -> V_522 , 16 ) ;
else
memset ( V_11 -> V_521 , 0 , 16 ) ;
return;
}
static T_1 F_156 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 V_192 = 0 ;
switch ( V_7 -> V_24 ) {
case V_25 :
case V_26 :
case V_523 :
V_192 = ( V_519 | V_524 | V_525 ) ;
break;
case V_526 :
V_192 = ( V_527 | V_520 ) ;
break;
default:
V_192 = V_525 ;
break;
}
return V_192 ;
}
static void F_157 ( struct V_35 * V_36 , T_1 V_528 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 V_529 = F_156 ( V_36 ) ;
if ( ( V_528 == V_530 ) || ( ( V_528 & V_529 ) == 0 ) ) {
if ( V_529 & V_519 ) {
V_528 = V_519 ;
} else if ( V_529 & V_520 ) {
V_528 = V_520 ;
} else if ( ( V_529 & V_527 ) ) {
V_528 = V_527 ;
} else if ( ( V_529 & V_524 ) ) {
V_528 = V_524 ;
} else if ( ( V_529 & V_525 ) ) {
V_528 = V_525 ;
} else {
F_9 ( V_27 , L_70 , V_28 , V_529 ) ;
V_528 = V_525 ;
}
}
#ifdef F_158
F_159 ( V_531 , V_532 -> V_533 , & V_531 -> V_534 . V_535 . V_536 ) ;
#endif
V_7 -> V_12 -> V_324 = V_528 ;
if ( ( V_528 == V_519 ) || ( V_528 == V_520 ) )
V_7 -> V_12 -> V_267 -> V_537 = 1 ;
else
V_7 -> V_12 -> V_267 -> V_537 = 0 ;
F_9 ( V_95 , L_71 , V_528 ) ;
F_155 ( V_7 ) ;
}
static void F_160 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 V_1 ;
V_7 -> V_538 = V_539 ;
V_7 -> V_132 = 1 ;
V_7 -> V_12 -> V_324 = V_530 ;
V_7 -> V_12 -> V_121 = V_122 ;
V_7 -> V_12 -> V_540 = 0 ;
V_7 -> V_541 = V_542 ;
V_7 -> V_543 = V_544 ;
V_7 -> V_12 -> V_545 = V_546 ;
V_7 -> V_12 -> V_181 = 110 ;
V_7 -> V_12 -> V_547 = 1 ;
V_7 -> V_548 = ( V_36 -> V_160 & V_161 ) ? 1 : 0 ;
V_7 -> V_549 = 6 ;
V_7 -> V_550 = 1 ;
V_7 -> V_551 = V_552 ;
V_7 -> V_553 = 0 ;
V_7 -> V_554 = false ;
V_7 -> V_555 = false ;
V_7 -> V_12 -> V_556 = 0 ;
V_7 -> V_12 -> V_289 . V_341 = V_557 ;
V_7 -> V_12 -> V_121 = V_122 ;
V_7 -> V_12 -> V_558 = V_559 |
V_560 | V_561 |
V_562 | V_563 |
V_564 ;
V_7 -> V_12 -> V_565 = 1 ;
V_7 -> V_12 -> V_566 = V_567 | V_568 ;
V_7 -> V_12 -> V_512 = 1 ;
V_7 -> V_12 -> V_569 = 1 ;
V_7 -> V_12 -> V_570 = NULL ;
V_7 -> V_12 -> V_571 = NULL ;
V_7 -> V_12 -> V_284 = F_100 ;
V_7 -> V_12 -> V_572 = F_58 ;
V_7 -> V_12 -> V_573 = F_138 ;
V_7 -> V_12 -> V_574 = F_94 ;
V_7 -> V_12 -> V_575 = F_92 ;
V_7 -> V_12 -> V_576 = F_93 ;
V_7 -> V_12 -> V_577 = 0 ;
V_7 -> V_12 -> V_578 = V_579 ;
V_7 -> V_12 -> F_52 = F_52 ;
V_7 -> V_12 -> V_198 = V_434 ;
V_7 -> V_12 -> V_580 = 1 ;
V_7 -> V_12 -> V_581 = V_582 ;
V_7 -> V_12 -> V_583 = F_152 ;
V_7 -> V_12 -> V_584 = F_149 ;
V_7 -> V_12 -> V_585 = F_153 ;
V_7 -> V_12 -> V_586 = F_154 ;
V_7 -> V_12 -> V_587 = F_157 ;
V_7 -> V_12 -> V_588 = V_589 ;
V_7 -> V_590 = V_591 ;
#ifdef F_158
if ( V_592 -> V_593 ) {
V_532 -> V_594 = 7 ;
V_532 -> V_595 = 7 ;
}
#endif
V_7 -> V_594 = 0x30 ;
V_7 -> V_595 = 0x30 ;
V_7 -> V_596 = 7 ;
V_7 -> V_597 = 0 ;
V_7 -> V_598 =
( V_599 << V_600 ) |
( V_7 -> V_594 << V_601 ) |
( V_7 -> V_595 << V_602 ) |
( false ? V_603 : 0 ) ;
#ifdef F_158
if ( V_592 -> V_593 )
V_532 -> V_446 = V_532 -> V_604 |
V_156 | V_157 |
V_605 |
V_158 | V_159 | V_164 |
V_166 | V_169 |
( ( T_2 ) 7 << V_174 ) |
( V_532 -> V_596 << V_606 ) |
( V_532 -> V_596 == 7 ? V_607 : 0 ) ;
else
#endif
V_7 -> V_446 =
V_156 | V_157 |
V_605 |
V_158 | V_159 | V_164 |
( ( T_2 ) 7 << V_174 ) |
( V_7 -> V_596 << V_172 ) |
( V_7 -> V_596 == 7 ? V_175 : 0 ) ;
V_7 -> V_608 = 0 ;
V_7 -> V_609 = F_161 ( sizeof( V_610 ) , V_149 ) ;
F_162 ( & V_7 -> V_146 ) ;
F_162 ( & V_7 -> V_180 ) ;
for ( V_1 = 0 ; V_1 < V_611 ; V_1 ++ )
F_162 ( & V_7 -> V_12 -> V_282 [ V_1 ] ) ;
for ( V_1 = 0 ; V_1 < V_611 ; V_1 ++ )
F_162 ( & V_7 -> V_12 -> V_612 [ V_1 ] ) ;
for ( V_1 = 0 ; V_1 < V_611 ; V_1 ++ )
F_162 ( & V_7 -> V_12 -> V_271 [ V_1 ] ) ;
V_7 -> V_133 = V_613 ;
}
static void F_163 ( struct V_6 * V_7 )
{
F_164 ( & V_7 -> V_196 ) ;
F_164 ( & V_7 -> V_614 ) ;
F_165 ( & V_7 -> V_615 , 1 ) ;
F_165 ( & V_7 -> V_616 , 1 ) ;
F_166 ( & V_7 -> V_461 ) ;
}
static void F_167 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
V_7 -> V_484 = F_168 ( V_617 ) ;
F_169 ( & V_7 -> V_114 , V_618 ) ;
F_170 ( & V_7 -> V_619 , V_620 ) ;
F_170 ( & V_7 -> V_621 , V_622 ) ;
F_170 ( & V_7 -> V_623 , V_624 ) ;
F_170 ( & V_7 -> V_449 , F_141 ) ;
F_170 ( & V_7 -> V_625 , V_626 ) ;
F_169 ( & V_7 -> V_454 , F_144 ) ;
F_171 ( & V_7 -> V_188 ,
( void (*) ( unsigned long ) ) V_627 ,
( unsigned long ) V_7 ) ;
}
static void F_172 ( struct V_35 * V_36 )
{
T_3 V_628 = 0 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
F_9 ( V_115 , L_72 , V_28 ) ;
F_28 ( V_36 , V_629 , & V_628 ) ;
F_9 ( V_115 , L_73 , V_629 , V_628 ) ;
V_7 -> V_630 = ( V_628 & V_631 ) ? V_632 : V_633 ;
F_9 ( V_115 , L_74 , V_28 , V_7 -> V_630 ) ;
}
static inline T_3 F_173 ( T_3 * V_42 )
{
T_3 V_319 = * V_42 ;
* V_42 = ( V_319 >> 8 ) | ( V_319 << 8 ) ;
return * V_42 ;
}
static void F_174 ( struct V_35 * V_36 )
{
T_3 V_634 = 0 ;
T_1 V_635 [ 6 ] = { 0x00 , 0xe0 , 0x4c , 0x00 , 0x00 , 0x02 } ;
T_1 V_636 = false ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_3 V_637 = 0 ;
int V_1 ;
F_9 ( V_115 , L_72 , V_28 ) ;
V_634 = F_56 ( V_36 , 0 ) ;
F_9 ( V_115 , L_75 , V_634 ) ;
if ( V_634 != V_638 ) {
F_9 ( V_27 , L_76 , V_634 , V_638 ) ;
} else {
V_636 = true ;
}
if ( V_636 ) {
V_637 = F_56 ( V_36 , ( V_639 >> 1 ) ) ;
V_7 -> V_640 = F_173 ( & V_637 ) ;
V_7 -> V_641 = F_56 ( V_36 , ( V_642 >> 1 ) ) ;
V_637 = F_56 ( V_36 , ( V_643 >> 1 ) ) ;
V_7 -> V_644 = ( ( V_637 & 0xff00 ) >> 8 ) ;
V_7 -> V_645 = true ;
V_7 -> V_646 = F_56 ( V_36 , ( V_647 >> 1 ) ) >> 8 ;
} else {
V_7 -> V_640 = 0 ;
V_7 -> V_641 = 0 ;
V_7 -> V_648 = V_649 ;
V_7 -> V_644 = 0 ;
V_7 -> V_646 = 0 ;
}
F_9 ( V_115 , L_77 , V_7 -> V_640 , V_7 -> V_641 , V_7 -> V_646 , V_7 -> V_644 ) ;
V_7 -> V_29 = V_7 -> V_644 ;
if ( V_636 ) {
int V_1 ;
for ( V_1 = 0 ; V_1 < 6 ; V_1 += 2 ) {
T_3 V_319 = 0 ;
V_319 = F_56 ( V_36 , ( T_3 ) ( ( V_650 + V_1 ) >> 1 ) ) ;
* ( T_3 * ) ( & V_36 -> V_651 [ V_1 ] ) = V_319 ;
}
} else {
memcpy ( V_36 -> V_651 , V_635 , 6 ) ;
}
F_9 ( V_115 , L_78 , V_36 -> V_651 ) ;
V_7 -> V_500 = V_652 ;
V_7 -> V_24 = V_26 ;
if ( V_7 -> V_648 == ( T_1 ) V_653 ) {
if ( V_636 )
V_7 -> V_654 = ( F_56 ( V_36 , ( V_655 >> 1 ) ) & 0xff00 ) >> 8 ;
else
V_7 -> V_654 = V_656 ;
F_9 ( V_115 , L_79 , V_7 -> V_654 ) ;
if ( V_636 )
V_7 -> V_657 = ( T_1 ) ( F_56 ( V_36 , ( V_658 >> 1 ) ) & 0x00ff ) ;
else
V_7 -> V_657 = V_659 ;
F_9 ( V_115 , L_80 , V_7 -> V_657 ) ;
V_7 -> V_660 = V_7 -> V_657 * 100 ;
if ( V_636 )
V_7 -> V_661 = ( F_56 ( V_36 , ( V_662 >> 1 ) ) & 0x0f00 ) >> 8 ;
else
V_7 -> V_661 = V_663 ;
F_9 ( V_115 , L_81 , V_7 -> V_661 ) ;
if ( V_636 )
V_7 -> V_664 = ( F_56 ( V_36 , ( V_665 >> 1 ) ) & 0x0f ) ;
else
V_7 -> V_664 = V_666 ;
F_9 ( V_115 , L_82 , V_7 -> V_664 ) ;
if ( V_636 )
V_7 -> V_667 = ( F_56 ( V_36 , ( V_668 >> 1 ) ) & 0xff00 ) >> 8 ;
else
V_7 -> V_667 = 1 ;
F_9 ( V_115 , L_83 , V_7 -> V_667 ) ;
if ( V_7 -> V_667 == 0 ) {
int V_1 ;
if ( V_636 )
V_7 -> V_669 = ( F_56 ( V_36 , ( V_670 >> 1 ) ) & 0xff ) >> 8 ;
else
V_7 -> V_669 = 0x10 ;
F_9 ( V_115 , L_84 , V_7 -> V_669 ) ;
for ( V_1 = 0 ; V_1 < 3 ; V_1 ++ ) {
if ( V_636 ) {
V_637 = F_56 ( V_36 , ( V_671 + V_1 ) >> 1 ) ;
if ( ( ( V_671 + V_1 ) % 2 ) == 0 )
V_637 = V_637 & 0x00ff ;
else
V_637 = ( V_637 & 0xff00 ) >> 8 ;
} else {
V_637 = 0x10 ;
}
V_7 -> V_672 [ V_1 ] = ( T_1 ) V_637 ;
F_9 ( V_115 , L_85 , V_1 , V_7 -> V_669 ) ;
}
} else if ( V_7 -> V_667 == 1 ) {
if ( V_636 ) {
V_637 = F_56 ( V_36 , ( V_673 >> 1 ) ) ;
V_637 = ( V_637 & 0xff00 ) >> 8 ;
} else {
V_637 = 0x10 ;
}
V_7 -> V_674 [ 0 ] = ( T_1 ) V_637 ;
if ( V_636 )
V_637 = F_56 ( V_36 , ( V_673 + 2 ) >> 1 ) ;
else
V_637 = 0x1010 ;
* ( ( T_3 * ) ( & V_7 -> V_674 [ 1 ] ) ) = V_637 ;
if ( V_636 )
V_637 = F_56 ( V_36 , ( V_675 >> 1 ) ) ;
else
V_637 = 0x1010 ;
* ( ( T_3 * ) ( & V_7 -> V_672 [ 0 ] ) ) = V_637 ;
if ( V_636 )
V_637 = F_56 ( V_36 , ( V_675 + 2 ) >> 1 ) ;
else
V_637 = 0x10 ;
V_7 -> V_672 [ 2 ] = ( T_1 ) V_637 ;
}
for ( V_1 = 0 ; V_1 < 14 ; V_1 ++ ) {
if ( V_1 <= 3 )
V_7 -> V_676 [ V_1 ] = V_7 -> V_672 [ 0 ] ;
else if ( V_1 >= 4 && V_1 <= 9 )
V_7 -> V_676 [ V_1 ] = V_7 -> V_672 [ 1 ] ;
else
V_7 -> V_676 [ V_1 ] = V_7 -> V_672 [ 2 ] ;
}
for ( V_1 = 0 ; V_1 < 14 ; V_1 ++ ) {
if ( V_7 -> V_667 == 0 ) {
if ( V_1 <= 3 )
V_7 -> V_677 [ V_1 ] = V_7 -> V_672 [ 0 ] + ( V_7 -> V_669 - V_7 -> V_672 [ 1 ] ) ;
else if ( V_1 >= 4 && V_1 <= 9 )
V_7 -> V_677 [ V_1 ] = V_7 -> V_669 ;
else
V_7 -> V_677 [ V_1 ] = V_7 -> V_672 [ 2 ] + ( V_7 -> V_669 - V_7 -> V_672 [ 1 ] ) ;
} else if ( V_7 -> V_667 == 1 ) {
if ( V_1 <= 3 )
V_7 -> V_677 [ V_1 ] = V_7 -> V_674 [ 0 ] ;
else if ( V_1 >= 4 && V_1 <= 9 )
V_7 -> V_677 [ V_1 ] = V_7 -> V_674 [ 1 ] ;
else
V_7 -> V_677 [ V_1 ] = V_7 -> V_674 [ 2 ] ;
}
}
V_7 -> V_678 = V_7 -> V_661 ;
V_7 -> V_679 [ 0 ] = ( V_7 -> V_654 & 0xf ) ;
V_7 -> V_679 [ 1 ] = ( ( V_7 -> V_654 & 0xf0 ) >> 4 ) ;
V_7 -> V_680 = V_7 -> V_664 ;
V_7 -> V_681 [ 0 ] = V_7 -> V_657 ;
}
switch ( V_7 -> V_646 ) {
case V_682 :
V_7 -> V_683 = V_684 ;
break;
case V_685 :
V_7 -> V_683 = V_686 ;
break;
default:
V_7 -> V_683 = V_687 ;
break;
}
switch ( V_7 -> V_683 ) {
case V_684 :
V_7 -> V_688 = V_689 ;
break;
case V_686 :
V_7 -> V_688 = V_690 ;
break;
default:
V_7 -> V_688 = V_691 ;
break;
}
if ( V_7 -> V_500 == V_501 ) {
F_9 ( V_115 , L_86 ) ;
} else {
F_9 ( V_115 , L_87 ) ;
}
F_175 ( V_36 ) ;
F_9 ( V_115 , L_88 , V_28 ) ;
return;
}
static short F_176 ( struct V_35 * V_36 )
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
static short F_177 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
memset ( & ( V_7 -> V_67 ) , 0 , sizeof( struct V_692 ) ) ;
memset ( V_7 -> V_356 , 0 , 9 ) ;
#ifdef F_178
{
int V_1 = 0 ;
T_1 V_693 [] = { 3 , 2 , 1 , 0 , 4 , 8 , 7 , 6 , 5 } ;
memcpy ( V_7 -> V_356 , V_693 , 9 ) ;
}
#else
{
T_1 V_693 [] = { 3 , 2 , 1 , 0 , 4 , 4 , 0 , 4 , 4 } ;
memcpy ( V_7 -> V_356 , V_693 , 9 ) ;
}
#endif
F_160 ( V_36 ) ;
F_163 ( V_7 ) ;
F_167 ( V_36 ) ;
F_172 ( V_36 ) ;
F_174 ( V_36 ) ;
F_176 ( V_36 ) ;
F_179 ( V_36 ) ;
F_180 ( & V_7 -> V_694 ) ;
V_7 -> V_694 . V_42 = ( unsigned long ) V_36 ;
V_7 -> V_694 . V_695 = V_696 ;
if ( F_131 ( V_36 ) != 0 ) {
F_74 ( L_91 ) ;
return - V_359 ;
}
#ifdef F_181
F_55 ( V_36 ) ;
#endif
return 0 ;
}
static void F_182 ( struct V_35 * V_36 )
{
T_2 V_697 = 0 , V_698 = 0 ;
T_1 V_699 = 0 , V_700 = 0 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_2 V_494 = 0 ;
switch ( V_7 -> V_12 -> V_324 ) {
case V_525 :
V_699 = V_701 ;
V_697 = V_702 ;
V_698 = V_702 ;
break;
case V_527 :
V_699 = V_703 | V_701 ;
V_697 = V_704 ;
V_698 = V_704 ;
break;
case V_524 :
V_699 = V_701 ;
V_697 = V_702 | V_704 ;
V_698 = V_702 | V_704 ;
break;
case V_530 :
#ifdef F_158
if ( V_592 -> V_593 ) {
V_699 = V_701 ;
V_697 = V_702 | V_704 ;
V_698 = V_702 | V_704 ;
}
else
#endif
{
V_699 = V_701 ;
V_697 = V_702 | V_704 | V_705 | V_706 ;
V_698 = V_702 | V_704 ;
}
break;
case V_519 :
V_699 = V_701 ;
V_697 = V_702 | V_704 | V_705 | V_706 ;
V_698 = V_702 | V_704 ;
break;
case V_520 :
V_699 = V_703 ;
V_697 = V_704 | V_705 | V_706 ;
V_698 = V_704 ;
break;
}
F_24 ( V_36 , V_707 , V_699 ) ;
V_494 = V_697 ;
if ( V_7 -> V_500 == V_501 )
V_494 &= ~ ( V_706 ) ;
F_13 ( V_36 , V_505 , V_494 ) ;
F_24 ( V_36 , V_506 , 1 ) ;
F_26 ( V_36 , 0x313 , & V_700 ) ;
V_698 = ( ( V_700 ) << 24 ) | ( V_698 & 0x00ffffff ) ;
F_13 ( V_36 , V_323 , V_698 ) ;
F_25 ( V_36 , V_708 ,
V_7 -> V_594 << V_709 |
V_7 -> V_595 << V_710 ) ;
}
static bool F_183 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_2 V_711 = 0 ;
bool V_712 = true ;
T_1 V_713 = 0x0 ;
T_1 V_319 ;
F_9 ( V_95 , L_92 , V_28 ) ;
V_7 -> V_714 = V_715 ;
F_17 ( V_36 , 0x5f , 0x80 ) ;
F_60 ( 50 ) ;
F_17 ( V_36 , 0x5f , 0xf0 ) ;
F_17 ( V_36 , 0x5d , 0x00 ) ;
F_17 ( V_36 , 0x5e , 0x80 ) ;
F_24 ( V_36 , 0x17 , 0x37 ) ;
F_60 ( 10 ) ;
V_7 -> V_609 -> V_716 = V_717 ;
F_16 ( V_36 , V_718 , & V_711 ) ;
if ( V_7 -> V_609 -> V_716 == V_717 )
V_711 |= V_719 ;
else if ( V_7 -> V_609 -> V_716 == V_720 )
V_711 |= V_721 ;
else
F_9 ( V_27 , L_93 , V_28 , V_7 -> V_609 -> V_716 ) ;
F_13 ( V_36 , V_718 , V_711 ) ;
F_184 ( V_36 ) ;
V_7 -> V_722 = V_723 ;
F_16 ( V_36 , V_718 , & V_711 ) ;
if ( V_7 -> V_722 == V_723 )
V_711 = ( ( V_711 & V_724 ) | V_725 ) ;
else if ( V_7 -> V_722 == V_726 )
V_711 |= V_727 ;
else
F_9 ( V_27 , L_94 , V_28 , V_7 -> V_722 ) ;
F_13 ( V_36 , V_718 , V_711 ) ;
F_185 ( 500 ) ;
F_22 ( V_36 , 0x5f , & V_319 ) ;
F_17 ( V_36 , 0x5f , V_319 | 0x20 ) ;
F_182 ( V_36 ) ;
F_24 ( V_36 , V_177 , V_179 | V_178 ) ;
F_13 ( V_36 , V_728 , ( ( T_2 * ) V_36 -> V_651 ) [ 0 ] ) ;
F_25 ( V_36 , V_729 , ( ( T_3 * ) ( V_36 -> V_651 + 4 ) ) [ 0 ] ) ;
F_13 ( V_36 , V_154 , V_7 -> V_446 ) ;
F_13 ( V_36 , V_730 , V_731 << V_732 |
V_733 << V_734 |
V_735 << V_736 |
V_737 << V_738 ) ;
F_13 ( V_36 , V_739 , V_740 << V_741 |
V_742 << V_743 ) ;
F_13 ( V_36 , V_744 , V_745 |
V_746 << V_747 ) ;
F_13 ( V_36 , V_505 + 4 * 7 , ( V_704 | V_702 ) ) ;
F_24 ( V_36 , V_748 , 0x30 ) ;
if ( V_7 -> V_551 == V_552 )
F_157 ( V_36 , V_7 -> V_12 -> V_324 ) ;
if ( V_7 -> V_551 == V_552 ) {
F_12 ( V_36 ) ;
V_713 |= V_749 ;
V_713 |= V_750 ;
V_713 |= V_751 ;
F_24 ( V_36 , V_752 , V_713 ) ;
}
F_25 ( V_36 , V_338 , 2 ) ;
F_25 ( V_36 , V_340 , 100 ) ;
#define F_186 0x005e4332
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_464 ; V_1 ++ )
F_13 ( V_36 , V_474 [ V_1 ] , F_186 ) ;
}
#ifdef F_62
if ( V_7 -> V_551 == V_552 ) {
T_2 V_753 ;
T_7 V_267 = V_7 -> V_12 -> V_267 ;
V_753 = ( V_267 -> V_754 << 24 ) | ( V_267 -> V_755 << 16 ) |
( V_267 -> V_756 << 8 ) | ( V_267 -> V_757 ) ;
F_13 ( V_36 , 0x1a8 , V_753 ) ;
V_7 -> V_758 = true ;
}
#endif
F_187 ( V_36 ) ;
if ( V_7 -> V_648 == ( T_1 ) V_653 ) {
F_188 ( V_36 ) ;
F_189 ( V_36 , V_7 -> V_132 ) ;
}
V_712 = F_190 ( V_36 ) ;
if ( ! V_712 ) {
F_9 ( V_27 , L_95 , V_28 ) ;
return V_712 ;
}
F_9 ( V_95 , L_96 , V_28 ) ;
#ifdef F_158
if ( V_592 -> V_551 == V_552 ) {
if ( V_759 -> V_760 == TRUE ) {
F_9 ( ( V_95 | V_761 ) , V_762 , ( L_97 ) ) ;
F_191 ( V_592 , V_763 , V_764 ) ;
for ( V_765 = 0 ; V_765 < V_532 -> V_766 ; V_765 ++ )
F_192 ( V_592 , ( V_767 ) V_765 , 0x4 , 0xC00 , 0x0 ) ;
} else if ( V_759 -> V_768 > V_769 ) {
F_9 ( ( V_95 | V_761 ) , V_762 , ( L_98 , V_759 -> V_768 ) ) ;
F_191 ( V_592 , V_763 , V_759 -> V_768 ) ;
} else {
V_532 -> V_770 = V_771 ;
V_759 -> V_768 = 0 ;
F_9 ( ( V_95 | V_761 ) , V_762 , ( L_99 ) ) ;
}
} else {
if ( V_532 -> V_770 == V_763 ) {
F_191 ( V_592 , V_763 , V_759 -> V_768 ) ;
for ( V_765 = 0 ; V_765 < V_532 -> V_766 ; V_765 ++ )
F_192 ( V_592 , ( V_767 ) V_765 , 0x4 , 0xC00 , 0x0 ) ;
}
}
#endif
if ( V_7 -> V_551 == V_552 ) {
F_193 ( V_36 ) ;
F_9 ( V_95 , L_100 , V_28 ) ;
}
if ( V_7 -> V_12 -> V_556 )
V_7 -> V_714 = V_772 ;
else
V_7 -> V_714 = V_715 ;
F_194 ( V_36 ) ;
F_195 ( V_36 , V_773 , V_774 , 0x1 ) ;
F_195 ( V_36 , V_773 , V_775 , 0x1 ) ;
if ( V_7 -> V_551 == V_552 ) {
T_1 V_776 ;
F_26 ( V_36 , 0x301 , & V_776 ) ;
if ( V_776 == 0x03 ) {
V_7 -> V_777 = TRUE ;
F_9 ( V_778 , L_101 ) ;
} else {
V_7 -> V_777 = FALSE ;
F_9 ( V_778 , L_102 ) ;
}
F_196 ( V_36 ) ;
if ( V_7 -> V_777 == TRUE ) {
T_2 V_1 , V_779 ;
T_2 V_780 = F_197 ( V_36 , V_781 , V_782 ) ;
for ( V_1 = 0 ; V_1 < V_783 ; V_1 ++ ) {
if ( V_780 == V_7 -> V_784 [ V_1 ] . V_785 ) {
V_7 -> V_786 = ( T_1 ) V_1 ;
V_7 -> V_787 = ( T_1 ) V_1 ;
V_7 -> V_788 = V_7 -> V_786 ;
break;
}
}
V_779 = F_197 ( V_36 , V_789 , V_790 ) ;
for ( V_1 = 0 ; V_1 < V_791 ; V_1 ++ ) {
if ( V_779 == V_7 -> V_792 [ V_1 ] . V_793 [ 0 ] ) {
V_7 -> V_794 = ( T_1 ) V_1 ;
break;
}
}
V_7 -> V_795 = 0 ;
V_7 -> V_796 = 0 ;
V_7 -> V_797 = V_7 -> V_794 ;
}
}
F_24 ( V_36 , 0x87 , 0x0 ) ;
return V_712 ;
}
static struct V_798 * F_198 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
return & V_7 -> V_12 -> V_67 ;
}
static bool F_199 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_3 V_799 ;
bool V_800 = FALSE ;
F_27 ( V_36 , 0x128 , & V_799 ) ;
F_9 ( V_801 , L_103 , V_28 , V_799 , V_7 -> V_802 ) ;
if ( V_7 -> V_802 == V_799 )
V_800 = TRUE ;
V_7 -> V_802 = V_799 ;
return V_800 ;
}
static T_10 F_200 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 V_270 ;
bool V_803 = false ;
for ( V_270 = 0 ; V_270 <= V_281 ; V_270 ++ ) {
if ( V_270 == V_195 )
continue;
#ifdef F_115
if ( ( F_64 ( & V_7 -> V_12 -> V_282 [ V_270 ] ) == 0 ) && ( F_64 ( & V_7 -> V_12 -> V_612 [ V_270 ] ) == 0 ) && ( F_64 ( & V_7 -> V_12 -> V_271 [ V_270 ] ) == 0 ) )
#else
if ( ( F_64 ( & V_7 -> V_12 -> V_282 [ V_270 ] ) == 0 ) && ( F_64 ( & V_7 -> V_12 -> V_612 [ V_270 ] ) == 0 ) )
#endif
continue;
V_803 = true ;
}
if ( V_803 ) {
if ( F_199 ( V_36 ) ) {
F_9 ( V_801 , L_104 ) ;
return V_804 ;
}
}
return V_552 ;
}
static bool F_201 ( struct V_35 * V_36 )
{
T_3 V_805 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
bool V_800 = FALSE ;
static T_1 V_806 ;
F_27 ( V_36 , 0x130 , & V_805 ) ;
F_9 ( V_801 , L_105 , V_28 , V_805 , V_7 -> V_807 ) ;
V_806 ++ ;
if ( V_7 -> V_808 >= ( V_809 + 5 ) ) {
V_806 = 0 ;
} else if ( V_7 -> V_808 < ( V_809 + 5 ) &&
( ( V_7 -> V_240 != V_810 && V_7 -> V_808 >= V_811 ) ||
( V_7 -> V_240 == V_810 && V_7 -> V_808 >= V_812 ) ) ) {
if ( V_806 < 2 )
return V_800 ;
else
V_806 = 0 ;
} else if ( ( ( V_7 -> V_240 != V_810 && V_7 -> V_808 < V_811 ) ||
( V_7 -> V_240 == V_810 && V_7 -> V_808 < V_812 ) ) &&
V_7 -> V_808 >= V_813 ) {
if ( V_806 < 4 )
return V_800 ;
else
V_806 = 0 ;
} else {
if ( V_806 < 8 )
return V_800 ;
else
V_806 = 0 ;
}
if ( V_7 -> V_807 == V_805 )
V_800 = TRUE ;
V_7 -> V_807 = V_805 ;
return V_800 ;
}
static T_10 F_202 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
bool V_814 = FALSE ;
if ( V_7 -> V_550 > 1 )
V_814 = TRUE ;
if ( V_814 ) {
if ( F_201 ( V_36 ) ) {
F_9 ( V_801 , L_106 ) ;
return V_804 ;
}
}
return V_552 ;
}
static T_10 F_203 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_10 V_815 = V_552 ;
T_10 V_816 = V_552 ;
T_11 V_817 ;
V_817 = V_7 -> V_12 -> V_770 ;
V_815 = F_200 ( V_36 ) ;
if ( V_817 != V_763 ||
( V_7 -> V_12 -> V_121 != V_125 ) ) {
V_816 = F_202 ( V_36 ) ;
}
if ( V_815 == V_818 || V_816 == V_818 ) {
return V_818 ;
} else if ( V_815 == V_804 || V_816 == V_804 ) {
F_9 ( V_801 , L_107 , V_28 ) ;
return V_804 ;
} else {
return V_552 ;
}
}
static void F_204 ( struct V_35 * V_36 )
{
T_1 V_819 = 0 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 * V_820 = V_7 -> V_12 -> V_289 . V_337 ;
static T_1 V_821 [ 4 ] [ 6 ] = {
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x02 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x03 } } ;
static T_1 V_822 [] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
F_9 ( V_823 , L_108 ) ;
if ( ( V_7 -> V_12 -> V_254 == V_255 ) ||
( V_7 -> V_12 -> V_254 == V_256 ) ) {
for ( V_819 = 0 ; V_819 < 4 ; V_819 ++ ) {
V_820 = V_821 [ V_819 ] ;
F_205 ( V_36 , V_819 , V_819 ,
V_7 -> V_12 -> V_254 ,
V_820 , 0 , NULL ) ;
}
} else if ( V_7 -> V_12 -> V_254 == V_257 ) {
if ( V_7 -> V_12 -> V_121 == V_125 )
F_205 ( V_36 , 4 , 0 , V_7 -> V_12 -> V_254 ,
( T_1 * ) V_36 -> V_651 , 0 , NULL ) ;
else
F_205 ( V_36 , 4 , 0 , V_7 -> V_12 -> V_254 ,
V_820 , 0 , NULL ) ;
} else if ( V_7 -> V_12 -> V_254 == V_258 ) {
if ( V_7 -> V_12 -> V_121 == V_125 )
F_205 ( V_36 , 4 , 0 , V_7 -> V_12 -> V_254 ,
( T_1 * ) V_36 -> V_651 , 0 , NULL ) ;
else
F_205 ( V_36 , 4 , 0 , V_7 -> V_12 -> V_254 ,
V_820 , 0 , NULL ) ;
}
if ( V_7 -> V_12 -> V_824 == V_257 ) {
V_820 = V_822 ;
for ( V_819 = 1 ; V_819 < 4 ; V_819 ++ ) {
F_205 ( V_36 , V_819 , V_819 ,
V_7 -> V_12 -> V_824 ,
V_820 , 0 , NULL ) ;
}
if ( V_7 -> V_12 -> V_121 == V_125 )
F_205 ( V_36 , 0 , 0 , V_7 -> V_12 -> V_824 ,
V_821 [ 0 ] , 0 , NULL ) ;
} else if ( V_7 -> V_12 -> V_824 == V_258 ) {
V_820 = V_822 ;
for ( V_819 = 1 ; V_819 < 4 ; V_819 ++ ) {
F_205 ( V_36 , V_819 , V_819 ,
V_7 -> V_12 -> V_824 ,
V_820 , 0 , NULL ) ;
}
if ( V_7 -> V_12 -> V_121 == V_125 )
F_205 ( V_36 , 0 , 0 , V_7 -> V_12 -> V_824 ,
V_821 [ 0 ] , 0 , NULL ) ;
}
}
static void F_206 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
T_1 V_825 = 0 ;
int V_826 = 0 ;
struct V_10 * V_11 = V_7 -> V_12 ;
if ( V_7 -> V_551 == V_552 ) {
V_827:
F_9 ( V_801 , L_109 ) ;
V_7 -> V_551 = V_804 ;
F_207 ( & V_7 -> V_615 ) ;
if ( V_7 -> V_185 == 0 ) {
F_9 ( V_27 , L_110 , V_28 ) ;
V_185 ( & V_7 -> V_615 ) ;
return;
}
V_7 -> V_185 = 0 ;
F_9 ( V_801 , L_111 , V_28 ) ;
F_77 ( V_36 ) ;
F_208 ( V_7 ) ;
F_209 ( V_36 ) ;
F_210 ( & V_7 -> V_694 ) ;
V_11 -> V_828 = 1 ;
if ( V_11 -> V_119 == V_120 ) {
F_207 ( & V_11 -> V_615 ) ;
F_106 ( V_36 , L_112 ) ;
F_211 ( V_7 -> V_12 ) ;
F_210 ( & V_11 -> V_829 ) ;
F_212 ( & V_11 -> V_830 ) ;
F_213 ( V_11 ) ;
F_214 ( V_36 ) ;
V_185 ( & V_11 -> V_615 ) ;
} else {
F_106 ( V_36 , L_113 ) ;
F_215 ( V_7 -> V_12 ) ;
}
V_185 ( & V_7 -> V_615 ) ;
F_9 ( V_801 , L_114 , V_28 ) ;
F_9 ( V_801 , L_115 , V_28 ) ;
V_826 = F_216 ( V_36 ) ;
F_9 ( V_801 , L_116 , V_28 ) ;
if ( V_826 == - V_831 ) {
if ( V_825 < 3 ) {
V_825 ++ ;
goto V_827;
} else {
F_9 ( V_27 , L_117 , V_28 ) ;
}
}
V_11 -> V_832 = 1 ;
F_140 ( V_36 ) ;
if ( V_11 -> V_119 == V_120 && V_11 -> V_121 == V_122 ) {
V_11 -> V_572 ( V_11 -> V_36 , V_11 -> V_289 . V_833 ) ;
F_148 ( V_11 -> V_834 , & V_11 -> V_835 ) ;
} else if ( V_11 -> V_119 == V_120 && V_11 -> V_121 == V_125 ) {
V_11 -> V_572 ( V_11 -> V_36 , V_11 -> V_289 . V_833 ) ;
V_11 -> V_573 ( V_11 -> V_36 ) ;
F_217 ( V_11 ) ;
if ( V_11 -> V_576 )
V_11 -> V_576 ( V_11 -> V_36 ) ;
F_218 ( V_11 -> V_36 ) ;
}
F_204 ( V_36 ) ;
V_7 -> V_551 = V_552 ;
V_7 -> V_836 ++ ;
V_7 -> V_553 = false ;
V_7 -> V_837 = false ;
F_24 ( V_36 , V_506 , 1 ) ;
F_9 ( V_801 , L_118 , V_7 -> V_836 ) ;
}
}
void F_219 ( struct V_35 * V_36 , T_2 V_838 )
{
T_2 V_839 = 0 ;
T_2 V_840 = 0 ;
T_1 V_841 = 0 ;
T_2 V_842 ;
T_12 V_1 = 100 ;
for ( V_841 = 0 ; V_841 < V_843 ; V_841 ++ ) {
V_839 = V_841 + V_843 * V_838 ;
V_839 = V_839 | V_38 ;
while ( ( V_1 -- ) >= 0 ) {
F_16 ( V_36 , V_40 , & V_842 ) ;
if ( V_842 & V_38 )
continue;
else
break;
}
F_13 ( V_36 , V_40 , V_839 ) ;
F_9 ( V_823 , L_119 , V_839 ) ;
F_16 ( V_36 , V_844 , & V_840 ) ;
F_9 ( V_823 , L_120 , V_840 ) ;
}
F_220 ( L_121 ) ;
}
static void F_221 ( struct V_6 * V_7 , T_2 * V_845 ,
T_2 * V_846 )
{
T_3 V_847 ;
T_1 V_1 ;
* V_845 = 0 ;
* V_846 = 0 ;
V_847 = ( V_7 -> V_12 -> V_277 . V_847 ++ ) % ( V_7 -> V_12 -> V_277 . V_848 ) ;
V_7 -> V_12 -> V_277 . V_849 [ V_847 ] = V_7 -> V_12 -> V_277 . V_850 ;
V_7 -> V_12 -> V_277 . V_851 [ V_847 ] = V_7 -> V_12 -> V_277 . V_852 ;
for ( V_1 = 0 ; V_1 < V_7 -> V_12 -> V_277 . V_848 ; V_1 ++ ) {
* V_845 += V_7 -> V_12 -> V_277 . V_849 [ V_1 ] ;
* V_846 += V_7 -> V_12 -> V_277 . V_851 [ V_1 ] ;
}
}
void V_620 ( struct V_447 * V_448 )
{
struct V_853 * V_854 = F_142 ( V_448 , struct V_853 , V_448 ) ;
struct V_6 * V_7 = F_142 ( V_854 , struct V_6 , V_619 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
struct V_10 * V_11 = V_7 -> V_12 ;
T_10 V_855 = V_552 ;
static T_1 V_856 ;
bool V_857 = false ;
T_2 V_845 = 0 ;
T_2 V_846 = 0 ;
if ( ! V_7 -> V_185 )
return;
F_222 ( V_36 ) ;
if ( V_11 -> V_119 == V_120 ) {
if ( V_11 -> V_277 . V_858 > 666 ||
V_11 -> V_277 . V_278 > 666 ) {
V_857 = true ;
}
V_11 -> V_277 . V_858 = 0 ;
V_11 -> V_277 . V_278 = 0 ;
V_11 -> V_277 . V_857 = V_857 ;
}
if ( V_7 -> V_12 -> V_119 == V_120 && V_7 -> V_12 -> V_121 == V_122 ) {
F_221 ( V_7 , & V_845 , & V_846 ) ;
if ( ( V_845 + V_846 ) == 0 ) {
#ifdef F_223
if ( V_817 == V_763 )
F_9 ( V_27 , L_122 , V_28 ) ;
#endif
F_106 ( V_36 , L_123 , V_28 ) ;
V_7 -> V_12 -> V_119 = V_859 ;
F_224 ( V_7 -> V_12 ) ;
F_225 ( V_7 -> V_12 , V_7 -> V_12 -> V_289 . V_337 ) ;
V_7 -> V_12 -> V_573 ( V_36 ) ;
F_148 ( V_7 -> V_12 -> V_834 , & V_7 -> V_12 -> V_860 ) ;
}
}
V_7 -> V_12 -> V_277 . V_850 = 0 ;
V_7 -> V_12 -> V_277 . V_852 = 0 ;
if ( V_856 ++ >= 3 ) {
V_855 = F_203 ( V_36 ) ;
V_856 = 3 ;
}
if ( ( V_7 -> V_555 ) || ( V_7 -> V_551 == V_552 &&
( V_7 -> V_553 ||
( ! V_7 -> V_554 && V_855 == V_804 ) ) ) ) {
F_9 ( V_801 , L_124 , V_28 , V_7 -> V_555 , V_7 -> V_551 , V_7 -> V_553 , V_7 -> V_554 , V_855 ) ;
F_206 ( V_36 ) ;
}
V_7 -> V_555 = false ;
V_7 -> V_553 = false ;
V_7 -> V_837 = false ;
F_9 ( V_861 , L_125 ) ;
}
void V_696 ( unsigned long V_42 )
{
struct V_6 * V_7 = F_18 ( (struct V_35 * ) V_42 ) ;
F_150 ( V_7 -> V_484 , & V_7 -> V_619 , 0 ) ;
F_226 ( & V_7 -> V_694 , V_275 + F_227 ( V_862 ) ) ;
}
int F_216 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_712 = 0 ;
V_7 -> V_185 = 1 ;
V_7 -> V_12 -> V_540 = 1 ;
F_9 ( V_95 , L_126 ) ;
V_712 = F_183 ( V_36 ) ;
if ( ! V_712 ) {
F_9 ( V_27 , L_127 , V_28 ) ;
V_7 -> V_185 = V_7 -> V_12 -> V_540 = 0 ;
return - V_831 ;
}
F_9 ( V_95 , L_128 ) ;
F_75 ( V_36 ) ;
if ( V_7 -> V_12 -> V_119 != V_120 )
F_228 ( V_7 -> V_12 ) ;
F_229 ( V_7 -> V_12 ) ;
V_696 ( ( unsigned long ) V_36 ) ;
if ( ! F_37 ( V_36 ) )
F_230 ( V_36 ) ;
else
F_231 ( V_36 ) ;
return 0 ;
}
static int F_232 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_192 ;
F_207 ( & V_7 -> V_615 ) ;
V_192 = F_233 ( V_36 ) ;
V_185 ( & V_7 -> V_615 ) ;
return V_192 ;
}
int F_233 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
if ( V_7 -> V_185 == 1 ) return - 1 ;
return F_216 ( V_36 ) ;
}
int F_234 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_192 ;
F_207 ( & V_7 -> V_615 ) ;
V_192 = F_235 ( V_36 ) ;
V_185 ( & V_7 -> V_615 ) ;
return V_192 ;
}
int F_235 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_1 ;
if ( V_7 -> V_185 == 0 ) return - 1 ;
V_7 -> V_185 = 0 ;
V_7 -> V_12 -> V_540 = 0 ;
F_9 ( V_863 , L_129 , V_28 ) ;
if ( ! F_37 ( V_36 ) )
F_236 ( V_36 ) ;
F_77 ( V_36 ) ;
for ( V_1 = 0 ; V_1 < V_611 ; V_1 ++ )
F_81 ( & V_7 -> V_12 -> V_282 [ V_1 ] ) ;
for ( V_1 = 0 ; V_1 < V_611 ; V_1 ++ )
F_81 ( & V_7 -> V_12 -> V_612 [ V_1 ] ) ;
for ( V_1 = 0 ; V_1 < V_611 ; V_1 ++ )
F_81 ( & V_7 -> V_12 -> V_271 [ V_1 ] ) ;
F_208 ( V_7 ) ;
F_209 ( V_36 ) ;
F_210 ( & V_7 -> V_694 ) ;
F_215 ( V_7 -> V_12 ) ;
memset ( & V_7 -> V_12 -> V_289 , 0 , F_237 ( struct V_58 , V_864 ) ) ;
F_9 ( V_863 , L_130 , V_28 ) ;
return 0 ;
}
void F_238 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
int V_826 = 0 ;
if ( V_7 -> V_185 == 0 ) return;
V_7 -> V_185 = 0 ;
F_208 ( V_7 ) ;
F_210 ( & V_7 -> V_694 ) ;
F_215 ( V_7 -> V_12 ) ;
F_77 ( V_36 ) ;
V_826 = F_216 ( V_36 ) ;
}
void V_618 ( struct V_447 * V_448 )
{
struct V_6 * V_7 = F_142 ( V_448 , struct V_6 , V_114 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
F_207 ( & V_7 -> V_615 ) ;
F_238 ( V_36 ) ;
V_185 ( & V_7 -> V_615 ) ;
}
static void F_239 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
short V_548 ;
V_548 = ( V_36 -> V_160 & V_161 ) ? 1 : 0 ;
if ( V_548 != V_7 -> V_548 )
V_7 -> V_548 = V_548 ;
}
static int F_240 ( struct V_35 * V_36 , void * V_865 )
{
struct V_6 * V_7 = F_18 ( V_36 ) ;
struct V_866 * V_41 = V_865 ;
F_207 ( & V_7 -> V_615 ) ;
memcpy ( V_36 -> V_651 , V_41 -> V_867 , V_868 ) ;
F_54 ( & V_7 -> V_114 ) ;
V_185 ( & V_7 -> V_615 ) ;
return 0 ;
}
static int F_241 ( struct V_35 * V_36 , struct V_869 * V_870 , int V_176 )
{
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_871 * V_872 = (struct V_871 * ) V_870 ;
int V_192 = - 1 ;
struct V_10 * V_11 = V_7 -> V_12 ;
T_2 V_873 [ 4 ] ;
T_1 V_874 [ 6 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_875 * V_876 = & V_872 -> V_877 . V_42 ;
struct V_878 * V_879 = NULL ;
F_207 ( & V_7 -> V_615 ) ;
if ( V_876 -> V_880 < sizeof( struct V_878 ) || ! V_876 -> V_881 ) {
V_192 = - V_882 ;
goto V_883;
}
V_879 = F_242 ( V_876 -> V_881 , V_876 -> V_880 ) ;
if ( F_243 ( V_879 ) ) {
V_192 = F_244 ( V_879 ) ;
goto V_883;
}
switch ( V_176 ) {
case V_884 :
if ( V_879 -> V_176 == V_885 ) {
if ( V_879 -> V_877 . V_508 . V_886 ) {
if ( strcmp ( V_879 -> V_877 . V_508 . V_887 , L_131 ) == 0 ) {
V_11 -> V_254 = V_258 ;
} else if ( strcmp ( V_879 -> V_877 . V_508 . V_887 , L_132 ) == 0 ) {
V_11 -> V_254 = V_257 ;
} else if ( strcmp ( V_879 -> V_877 . V_508 . V_887 , L_69 ) == 0 ) {
if ( V_879 -> V_877 . V_508 . V_888 == 13 )
V_11 -> V_254 = V_256 ;
else if ( V_879 -> V_877 . V_508 . V_888 == 5 )
V_11 -> V_254 = V_255 ;
} else {
V_11 -> V_254 = V_259 ;
}
if ( V_11 -> V_254 ) {
memcpy ( ( T_1 * ) V_873 , V_879 -> V_877 . V_508 . V_873 , 16 ) ;
F_140 ( V_36 ) ;
F_205 ( V_36 , 4 , V_879 -> V_877 . V_508 . V_889 , V_11 -> V_254 , ( T_1 * ) V_11 -> V_890 , 0 , V_873 ) ;
if ( V_11 -> V_891 != 2 )
F_205 ( V_36 , V_879 -> V_877 . V_508 . V_889 , V_879 -> V_877 . V_508 . V_889 , V_11 -> V_254 , ( T_1 * ) V_11 -> V_890 , 0 , V_873 ) ;
}
} else {
memcpy ( ( T_1 * ) V_873 , V_879 -> V_877 . V_508 . V_873 , 16 ) ;
if ( strcmp ( V_879 -> V_877 . V_508 . V_887 , L_131 ) == 0 ) {
V_11 -> V_824 = V_258 ;
} else if ( strcmp ( V_879 -> V_877 . V_508 . V_887 , L_132 ) == 0 ) {
V_11 -> V_824 = V_257 ;
} else if ( strcmp ( V_879 -> V_877 . V_508 . V_887 , L_69 ) == 0 ) {
if ( V_879 -> V_877 . V_508 . V_888 == 13 )
V_11 -> V_824 = V_256 ;
else if ( V_879 -> V_877 . V_508 . V_888 == 5 )
V_11 -> V_824 = V_255 ;
} else {
V_11 -> V_824 = V_259 ;
}
if ( V_11 -> V_824 ) {
F_205 ( V_36 , V_879 -> V_877 . V_508 . V_889 ,
V_879 -> V_877 . V_508 . V_889 ,
V_11 -> V_824 ,
V_874 ,
0 ,
V_873 ) ;
}
}
}
V_192 = F_245 ( V_7 -> V_12 , & V_872 -> V_877 . V_42 ) ;
break;
default:
V_192 = - V_892 ;
break;
}
F_136 ( V_879 ) ;
V_879 = NULL ;
V_883:
V_185 ( & V_7 -> V_615 ) ;
return V_192 ;
}
static T_1 F_246 ( bool V_893 , T_1 V_181 )
{
T_1 V_894 = 0xff ;
if ( ! V_893 ) {
switch ( V_181 ) {
case V_382 : V_894 = V_292 ; break;
case V_383 : V_894 = V_294 ; break;
case V_384 : V_894 = V_296 ; break;
case V_385 : V_894 = V_298 ; break;
case V_386 : V_894 = V_300 ; break;
case V_387 : V_894 = V_302 ; break;
case V_388 : V_894 = V_304 ; break;
case V_389 : V_894 = V_306 ; break;
case V_390 : V_894 = V_308 ; break;
case V_391 : V_894 = V_310 ; break;
case V_392 : V_894 = V_312 ; break;
case V_393 : V_894 = V_314 ; break;
default:
V_894 = 0xff ;
F_9 ( V_895 , L_133 , V_181 , V_893 ) ;
break;
}
} else {
switch ( V_181 ) {
case V_395 : V_894 = V_394 ; break;
case V_397 : V_894 = V_396 ; break;
case V_399 : V_894 = V_398 ; break;
case V_401 : V_894 = V_400 ; break;
case V_403 : V_894 = V_402 ; break;
case V_405 : V_894 = V_404 ; break;
case V_407 : V_894 = V_406 ; break;
case V_409 : V_894 = V_408 ; break;
case V_411 : V_894 = V_410 ; break;
case V_413 : V_894 = V_412 ; break;
case V_415 : V_894 = V_414 ; break;
case V_417 : V_894 = V_416 ; break;
case V_419 : V_894 = V_418 ; break;
case V_421 : V_894 = V_420 ; break;
case V_423 : V_894 = V_422 ; break;
case V_425 : V_894 = V_424 ; break;
case V_426 : V_894 = ( 0x80 | 0x20 ) ; break;
default:
V_894 = 0xff ;
F_9 ( V_895 , L_133 , V_181 , V_893 ) ;
break;
}
}
return V_894 ;
}
static void F_247 ( struct V_35 * V_36 ,
struct V_134 * V_67 )
{
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
if ( V_67 -> V_896 && ! V_67 -> V_897 ) {
V_67 -> V_898 [ 0 ] = V_7 -> V_899 ;
V_67 -> V_898 [ 1 ] = V_7 -> V_900 ;
} else {
V_7 -> V_899 = V_67 -> V_898 [ 0 ] ;
V_7 -> V_900 = V_67 -> V_898 [ 1 ] ;
}
}
static long F_248 ( T_1 V_901 )
{
long V_902 ;
V_902 = ( long ) ( ( V_901 + 1 ) >> 1 ) ;
V_902 -= 95 ;
return V_902 ;
}
static void F_249 ( struct V_6 * V_7 , T_1 * V_903 ,
struct V_134 * V_904 ,
struct V_134 * V_905 )
{
bool V_906 = false ;
T_1 V_907 ;
T_2 V_908 , V_909 ;
static T_2 V_910 , V_911 ;
static T_2 V_912 , V_913 ;
static T_2 V_914 , V_915 ;
static T_2 V_916 , V_917 ;
static T_2 V_918 ;
struct V_919 * V_920 ;
T_3 V_921 ;
unsigned int V_922 , V_923 ;
V_920 = (struct V_919 * ) V_903 ;
V_921 = F_250 ( V_920 -> V_924 ) ;
V_922 = F_251 ( V_921 ) ;
V_923 = F_252 ( V_921 ) ;
V_905 -> V_925 = V_923 ;
if ( ! V_904 -> V_896 ) {
V_906 = true ;
}
if ( V_911 ++ >= V_926 ) {
V_911 = V_926 ;
V_914 = V_7 -> V_67 . V_927 [ V_910 ] ;
V_7 -> V_67 . V_928 -= V_914 ;
}
V_7 -> V_67 . V_928 += V_904 -> V_929 ;
V_7 -> V_67 . V_927 [ V_910 ++ ] = V_904 -> V_929 ;
if ( V_910 >= V_926 )
V_910 = 0 ;
V_909 = V_7 -> V_67 . V_928 / V_911 ;
V_7 -> V_67 . V_930 = F_248 ( ( T_1 ) V_909 ) ;
V_905 -> V_931 = V_7 -> V_67 . V_930 ;
if ( ! V_904 -> V_932 ) {
if ( ! V_904 -> V_933 )
return;
}
if ( ! V_906 )
return;
V_7 -> V_67 . V_934 ++ ;
if ( ! V_904 -> V_935 && ( V_904 -> V_936 || V_904 -> V_933 ) ) {
for ( V_907 = V_937 ; V_907 < V_7 -> V_766 ; V_907 ++ ) {
if ( ! F_253 ( V_7 -> V_12 -> V_36 , V_907 ) )
continue;
if ( V_7 -> V_67 . V_938 [ V_907 ] == 0 )
V_7 -> V_67 . V_938 [ V_907 ] = V_904 -> V_939 [ V_907 ] ;
if ( V_904 -> V_939 [ V_907 ] > V_7 -> V_67 . V_938 [ V_907 ] ) {
V_7 -> V_67 . V_938 [ V_907 ] =
( ( V_7 -> V_67 . V_938 [ V_907 ] * ( V_940 - 1 ) ) +
( V_904 -> V_939 [ V_907 ] ) ) / ( V_940 ) ;
V_7 -> V_67 . V_938 [ V_907 ] = V_7 -> V_67 . V_938 [ V_907 ] + 1 ;
} else {
V_7 -> V_67 . V_938 [ V_907 ] =
( ( V_7 -> V_67 . V_938 [ V_907 ] * ( V_940 - 1 ) ) +
( V_904 -> V_939 [ V_907 ] ) ) / ( V_940 ) ;
}
F_9 ( V_941 , L_134 , V_7 -> V_67 . V_938 [ V_907 ] ) ;
}
}
F_9 ( V_942 , L_135 ,
V_904 -> V_935 ? L_136 : L_137 ,
V_904 -> V_943 ) ;
if ( V_904 -> V_944 ) {
if ( V_917 ++ >= V_945 ) {
V_917 = V_945 ;
V_918 = V_7 -> V_67 . V_946 [ V_916 ] ;
V_7 -> V_67 . V_947 -= V_918 ;
}
V_7 -> V_67 . V_947 += V_904 -> V_943 ;
V_7 -> V_67 . V_946 [ V_916 ] = V_904 -> V_943 ;
V_916 ++ ;
if ( V_916 >= V_945 )
V_916 = 0 ;
V_904 -> V_943 = V_7 -> V_67 . V_947 / V_917 ;
if ( V_904 -> V_943 >= 3 )
V_904 -> V_943 -= 3 ;
}
F_9 ( V_942 , L_135 ,
V_904 -> V_935 ? L_136 : L_137 ,
V_904 -> V_943 ) ;
if ( V_904 -> V_936 || V_904 -> V_944 || V_904 -> V_933 ) {
if ( V_7 -> V_808 < 0 )
V_7 -> V_808 = V_904 -> V_943 ;
if ( V_904 -> V_943 > ( T_2 ) V_7 -> V_808 ) {
V_7 -> V_808 =
( ( ( V_7 -> V_808 ) * ( V_940 - 1 ) ) +
( V_904 -> V_943 ) ) / ( V_940 ) ;
V_7 -> V_808 = V_7 -> V_808 + 1 ;
} else {
V_7 -> V_808 =
( ( ( V_7 -> V_808 ) * ( V_940 - 1 ) ) +
( V_904 -> V_943 ) ) / ( V_940 ) ;
}
}
if ( V_904 -> V_948 ) {
if ( V_904 -> V_936 || V_904 -> V_944 || V_904 -> V_933 ) {
if ( V_913 ++ >= V_926 ) {
V_913 = V_926 ;
V_915 = V_7 -> V_67 . V_949 [ V_912 ] ;
V_7 -> V_67 . V_950 -= V_915 ;
}
V_7 -> V_67 . V_950 += V_904 -> V_948 ;
V_7 -> V_67 . V_949 [ V_912 ++ ] = V_904 -> V_948 ;
if ( V_912 >= V_926 )
V_912 = 0 ;
V_909 = V_7 -> V_67 . V_950 / V_913 ;
V_7 -> V_67 . V_951 = V_909 ;
V_7 -> V_67 . V_952 = V_909 ;
}
if ( V_904 -> V_936 || V_904 -> V_944 || V_904 -> V_933 ) {
for ( V_908 = 0 ; V_908 < 2 ; V_908 ++ ) {
if ( V_904 -> V_953 [ V_908 ] != - 1 ) {
if ( V_7 -> V_67 . V_954 [ V_908 ] == 0 )
V_7 -> V_67 . V_954 [ V_908 ] = V_904 -> V_953 [ V_908 ] ;
V_7 -> V_67 . V_954 [ V_908 ] =
( ( V_7 -> V_67 . V_954 [ V_908 ] * ( V_940 - 1 ) ) +
( V_904 -> V_953 [ V_908 ] * 1 ) ) / ( V_940 ) ;
}
}
}
}
}
static T_1 F_254 ( char V_955 )
{
if ( ( V_955 <= - 100 ) || ( V_955 >= 20 ) )
return 0 ;
else if ( V_955 >= 0 )
return 100 ;
else
return 100 + V_955 ;
}
static T_1 F_255 ( char V_956 )
{
char V_957 ;
V_957 = V_956 ;
if ( V_957 >= 0 )
V_957 = 0 ;
if ( V_957 <= - 33 )
V_957 = - 33 ;
V_957 = 0 - V_957 ;
V_957 *= 3 ;
if ( V_957 == 99 )
V_957 = 100 ;
return V_957 ;
}
static long F_256 ( long V_958 )
{
long V_959 ;
if ( V_958 >= 61 && V_958 <= 100 )
V_959 = 90 + ( ( V_958 - 60 ) / 4 ) ;
else if ( V_958 >= 41 && V_958 <= 60 )
V_959 = 78 + ( ( V_958 - 40 ) / 2 ) ;
else if ( V_958 >= 31 && V_958 <= 40 )
V_959 = 66 + ( V_958 - 30 ) ;
else if ( V_958 >= 21 && V_958 <= 30 )
V_959 = 54 + ( V_958 - 20 ) ;
else if ( V_958 >= 5 && V_958 <= 20 )
V_959 = 42 + ( ( ( V_958 - 5 ) * 2 ) / 3 ) ;
else if ( V_958 == 4 )
V_959 = 36 ;
else if ( V_958 == 3 )
V_959 = 27 ;
else if ( V_958 == 2 )
V_959 = 18 ;
else if ( V_958 == 1 )
V_959 = 9 ;
else
V_959 = V_958 ;
return V_959 ;
}
static inline bool F_257 ( struct V_960 * V_961 )
{
if ( V_961 -> V_962 )
return false ;
switch ( V_961 -> V_963 ) {
case V_382 :
case V_383 :
case V_384 :
case V_385 :
return true ;
default:
return false ;
}
}
static void F_258 ( struct V_6 * V_7 ,
struct V_134 * V_135 ,
V_960 * V_961 ,
struct V_134 * V_964 ,
bool V_965 ,
bool V_966 ,
bool V_944 ,
bool V_933 )
{
T_13 * V_967 ;
T_14 * V_968 ;
T_15 * V_969 ;
T_1 * V_970 ;
T_1 V_1 , V_971 , V_972 , V_973 , V_974 ;
char V_975 [ 4 ] , V_976 = 0 ;
char V_977 , V_978 ;
T_1 V_979 , V_980 ;
T_2 V_981 , V_982 = 0 ;
T_1 V_983 = 0 ;
T_1 V_984 = 0 ;
T_1 V_985 ;
V_7 -> V_67 . V_986 ++ ;
V_983 = F_257 ( V_961 ) ;
memset ( V_964 , 0 , sizeof( struct V_134 ) ) ;
V_135 -> V_932 = V_964 -> V_932 = V_965 ;
V_135 -> V_936 = V_964 -> V_936 = V_966 ;
V_135 -> V_935 = V_964 -> V_935 = V_983 ;
V_135 -> V_944 = V_964 -> V_944 = V_944 ;
V_135 -> V_933 = V_964 -> V_933 = V_933 ;
V_970 = ( T_1 * ) V_961 ;
V_970 += sizeof( V_960 ) ;
V_968 = ( T_14 * ) V_970 ;
V_967 = ( T_13 * ) V_970 ;
V_135 -> V_953 [ 0 ] = - 1 ;
V_135 -> V_953 [ 1 ] = - 1 ;
V_964 -> V_953 [ 0 ] = - 1 ;
V_964 -> V_953 [ 1 ] = - 1 ;
if ( V_983 ) {
T_1 V_987 ;
V_7 -> V_67 . V_988 ++ ;
if ( ! V_7 -> V_989 ) {
V_987 = V_968 -> V_990 & 0xc0 ;
V_987 = V_987 >> 6 ;
switch ( V_987 ) {
case 0x3 :
V_976 = - 35 - ( V_968 -> V_990 & 0x3e ) ;
break;
case 0x2 :
V_976 = - 23 - ( V_968 -> V_990 & 0x3e ) ;
break;
case 0x1 :
V_976 = - 11 - ( V_968 -> V_990 & 0x3e ) ;
break;
case 0x0 :
V_976 = 6 - ( V_968 -> V_990 & 0x3e ) ;
break;
}
} else {
V_987 = V_968 -> V_990 & 0x60 ;
V_987 = V_987 >> 5 ;
switch ( V_987 ) {
case 0x3 :
V_976 = - 35 - ( ( V_968 -> V_990 & 0x1f ) << 1 ) ;
break;
case 0x2 :
V_976 = - 23 - ( ( V_968 -> V_990 & 0x1f ) << 1 ) ;
break;
case 0x1 :
V_976 = - 11 - ( ( V_968 -> V_990 & 0x1f ) << 1 ) ;
break;
case 0x0 :
V_976 = 6 - ( ( V_968 -> V_990 & 0x1f ) << 1 ) ;
break;
}
}
V_980 = F_254 ( V_976 ) ;
V_135 -> V_943 = V_964 -> V_943 = V_980 ;
V_135 -> V_991 = V_980 ;
if ( V_135 -> V_943 > 40 ) {
V_985 = 100 ;
} else {
V_985 = V_968 -> V_992 ;
if ( V_968 -> V_992 > 64 )
V_985 = 0 ;
else if ( V_968 -> V_992 < 20 )
V_985 = 100 ;
else
V_985 = ( ( 64 - V_985 ) * 100 ) / 44 ;
}
V_135 -> V_948 = V_964 -> V_948 = V_985 ;
V_135 -> V_953 [ 0 ] = V_964 -> V_953 [ 0 ] = V_985 ;
V_135 -> V_953 [ 1 ] = V_964 -> V_953 [ 1 ] = - 1 ;
} else {
V_7 -> V_67 . V_993 ++ ;
for ( V_1 = V_937 ; V_1 < V_7 -> V_766 ; V_1 ++ ) {
if ( V_7 -> V_994 [ V_1 ] )
V_984 ++ ;
else
continue;
if ( ! F_253 ( V_7 -> V_12 -> V_36 , V_1 ) )
continue;
V_975 [ V_1 ] = ( ( V_967 -> V_995 [ V_1 ] & 0x3F ) * 2 ) - 106 ;
V_972 = V_967 -> V_996 [ V_1 ] ;
V_977 = ( char ) ( V_972 ) ;
V_977 /= 2 ;
V_7 -> V_67 . V_997 [ V_1 ] = ( long ) V_977 ;
V_981 = F_254 ( V_975 [ V_1 ] ) ;
V_982 += V_981 ;
V_135 -> V_939 [ V_1 ] = ( T_1 ) V_981 ;
V_964 -> V_939 [ V_1 ] = ( T_1 ) V_981 ;
}
V_976 = ( ( ( V_967 -> V_980 ) >> 1 ) & 0x7f ) - 106 ;
V_980 = F_254 ( V_976 ) ;
V_135 -> V_943 = V_964 -> V_943 = V_980 ;
V_135 -> V_998 = V_964 -> V_998 = V_976 ;
if ( V_961 -> V_962 && V_961 -> V_963 >= V_411 &&
V_961 -> V_963 <= V_425 )
V_971 = 2 ;
else
V_971 = 1 ;
for ( V_1 = 0 ; V_1 < V_971 ; V_1 ++ ) {
V_973 = V_967 -> V_999 [ V_1 ] ;
V_978 = ( char ) ( V_973 ) ;
V_978 /= 2 ;
V_979 = F_255 ( V_978 ) ;
if ( V_1 == 0 )
V_135 -> V_948 = V_964 -> V_948 = ( T_1 ) ( V_979 & 0xff ) ;
V_135 -> V_953 [ V_1 ] = V_964 -> V_953 [ V_1 ] = ( T_1 ) ( V_979 & 0xff ) ;
}
V_974 = V_967 -> V_974 ;
V_969 = ( T_15 * ) & V_974 ;
if ( V_961 -> V_1000 )
V_7 -> V_67 . V_1001 [ 1 + V_969 -> V_1002 ] ++ ;
else
V_7 -> V_67 . V_1001 [ 0 ] ++ ;
}
if ( V_983 ) {
V_135 -> V_929 = V_964 -> V_929 = ( T_1 ) ( F_256 ( ( long ) V_980 ) ) ;
} else {
if ( V_984 != 0 )
V_135 -> V_929 = V_964 -> V_929 = ( T_1 ) ( F_256 ( ( long ) ( V_982 /= V_984 ) ) ) ;
}
}
static void F_259 ( struct V_134 * V_1003 ,
struct V_134 * V_1004 )
{
V_1004 -> V_896 = V_1003 -> V_896 ;
V_1004 -> V_897 = V_1003 -> V_897 ;
V_1004 -> V_925 = V_1003 -> V_925 ;
}
static void F_260 ( struct V_142 * V_143 ,
struct V_134 * V_135 ,
V_960 * V_961 )
{
V_144 * V_145 = (struct V_144 * ) V_143 -> V_151 ;
struct V_35 * V_36 = V_145 -> V_36 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
bool V_965 , V_966 ;
bool V_944 = FALSE , V_933 = FALSE ;
static struct V_134 V_1005 ;
struct V_919 * V_920 ;
T_3 V_1006 , type ;
T_1 * V_1007 ;
T_1 * V_1008 ;
V_1007 = ( T_1 * ) V_143 -> V_42 ;
V_920 = (struct V_919 * ) V_1007 ;
V_1006 = F_250 ( V_920 -> V_1009 ) ;
type = F_261 ( V_1006 ) ;
V_1008 = V_920 -> V_1010 ;
V_965 = ( ( V_1011 != type ) &&
( F_262 ( V_7 -> V_12 -> V_289 . V_337 , ( V_1006 & V_1012 ) ? V_920 -> V_1010 : ( V_1006 & V_1013 ) ? V_920 -> V_1014 : V_920 -> V_1015 ) )
&& ( ! V_135 -> V_1016 ) && ( ! V_135 -> V_1017 ) && ( ! V_135 -> V_1018 ) ) ;
V_966 = V_965 & ( F_262 ( V_1008 , V_7 -> V_12 -> V_36 -> V_651 ) ) ;
if ( F_263 ( V_1006 ) == V_1019 )
V_944 = true ;
if ( F_263 ( V_1006 ) == V_1020 ) {
if ( ( F_262 ( V_1008 , V_36 -> V_651 ) ) )
V_933 = true ;
}
if ( V_965 )
V_7 -> V_67 . V_1021 ++ ;
if ( V_966 )
V_7 -> V_67 . V_1022 ++ ;
F_249 ( V_7 , V_1007 , & V_1005 , V_135 ) ;
F_258 ( V_7 , V_135 , V_961 , & V_1005 , V_965 , V_966 , V_944 , V_933 ) ;
F_259 ( V_135 , & V_1005 ) ;
}
static void
F_264 ( struct V_35 * V_36 ,
struct V_134 * V_67 )
{
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
T_2 V_1023 = 1 ;
T_2 V_1024 ;
T_2 V_1025 ;
if ( V_67 -> V_1017 )
V_1023 = 2 ;
else if ( V_67 -> V_1018 )
V_1023 = 3 ;
if ( V_67 -> V_351 )
V_1025 = 1 ;
else
V_1025 = 0 ;
switch ( V_67 -> V_181 ) {
case V_292 : V_1024 = 0 ; break;
case V_294 : V_1024 = 1 ; break;
case V_296 : V_1024 = 2 ; break;
case V_298 : V_1024 = 3 ; break;
case V_300 : V_1024 = 4 ; break;
case V_302 : V_1024 = 5 ; break;
case V_304 : V_1024 = 6 ; break;
case V_306 : V_1024 = 7 ; break;
case V_308 : V_1024 = 8 ; break;
case V_310 : V_1024 = 9 ; break;
case V_312 : V_1024 = 10 ; break;
case V_314 : V_1024 = 11 ; break;
case V_394 : V_1024 = 12 ; break;
case V_396 : V_1024 = 13 ; break;
case V_398 : V_1024 = 14 ; break;
case V_400 : V_1024 = 15 ; break;
case V_402 : V_1024 = 16 ; break;
case V_404 : V_1024 = 17 ; break;
case V_406 : V_1024 = 18 ; break;
case V_408 : V_1024 = 19 ; break;
case V_410 : V_1024 = 20 ; break;
case V_412 : V_1024 = 21 ; break;
case V_414 : V_1024 = 22 ; break;
case V_416 : V_1024 = 23 ; break;
case V_418 : V_1024 = 24 ; break;
case V_420 : V_1024 = 25 ; break;
case V_422 : V_1024 = 26 ; break;
case V_424 : V_1024 = 27 ; break;
default: V_1024 = 28 ; break;
}
V_7 -> V_67 . V_1026 [ V_1025 ] [ V_1024 ] ++ ;
V_7 -> V_67 . V_1027 [ 0 ] [ V_1024 ] ++ ;
V_7 -> V_67 . V_1027 [ V_1023 ] [ V_1024 ] ++ ;
}
static void F_265 ( struct V_142 * V_143 ,
struct V_134 * V_67 ,
bool V_1028 )
{
V_144 * V_145 = (struct V_144 * ) V_143 -> V_151 ;
struct V_35 * V_36 = V_145 -> V_36 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
V_960 * V_1029 = NULL ;
#ifdef F_62
if ( V_1028 ) {
T_16 * V_1030 = ( T_16 * ) V_143 -> V_42 ;
V_67 -> V_1031 = V_1030 -> V_1031 ;
V_67 -> V_138 = V_1030 -> V_138 ;
V_67 -> V_139 = 0 ;
V_67 -> V_1018 = V_1030 -> V_1032 ;
V_67 -> V_1017 = V_1030 -> V_1033 ;
V_67 -> V_1016 = V_67 -> V_1017 | V_67 -> V_1018 ;
V_67 -> V_1034 = ! V_1030 -> V_1035 ;
} else
#endif
{
V_137 * V_1030 = ( V_137 * ) V_143 -> V_42 ;
V_67 -> V_1031 = V_1030 -> V_1031 ;
V_67 -> V_138 = V_1030 -> V_138 ;
V_67 -> V_139 = 0 ;
V_67 -> V_1018 = V_1030 -> V_1032 ;
V_67 -> V_1017 = V_1030 -> V_1033 ;
V_67 -> V_1016 = V_67 -> V_1017 | V_67 -> V_1018 ;
V_67 -> V_1034 = ! V_1030 -> V_1035 ;
}
if ( ( V_7 -> V_12 -> V_267 -> V_450 == true ) && ( V_7 -> V_12 -> V_254 == V_258 ) )
V_67 -> V_1016 = false ;
else
V_67 -> V_1016 = V_67 -> V_1017 | V_67 -> V_1018 ;
if ( V_67 -> V_1031 < 24 || V_67 -> V_1031 > V_1036 )
V_67 -> V_1016 |= 1 ;
if ( V_67 -> V_138 != 0 ) {
V_1029 = ( V_960 * ) ( V_143 -> V_42 + sizeof( V_137 ) +
V_67 -> V_139 ) ;
if ( ! V_67 -> V_1016 ) {
T_1 V_894 ;
V_894 = F_246 ( V_1029 -> V_962 , V_1029 -> V_963 ) ;
if ( V_894 == 0xff ) {
V_67 -> V_1016 = 1 ;
V_67 -> V_181 = V_292 ;
} else {
V_67 -> V_181 = V_894 ;
}
} else {
V_67 -> V_181 = 0x02 ;
}
V_67 -> V_351 = V_1029 -> V_1037 ;
F_264 ( V_36 , V_67 ) ;
V_67 -> V_896 = ( V_1029 -> V_1038 == 1 ) ;
V_67 -> V_897 = ( V_1029 -> V_1038 == 1 ) && ( V_1029 -> V_1039 == 1 ) ;
V_67 -> V_1040 = V_1029 -> V_1041 ;
F_247 ( V_36 , V_67 ) ;
if ( V_1029 -> V_1039 == 1 || V_1029 -> V_1038 == 1 )
F_9 ( V_942 , L_138 ,
V_1029 -> V_1039 , V_1029 -> V_1038 ) ;
}
F_266 ( V_143 , sizeof( V_137 ) ) ;
if ( ( V_67 -> V_139 + V_67 -> V_138 ) > 0 ) {
V_67 -> V_1042 = 1 ;
F_266 ( V_143 , V_67 -> V_139 + V_67 -> V_138 ) ;
}
#ifdef F_62
if ( V_1028 )
F_266 ( V_143 , 8 ) ;
#endif
V_67 -> V_1043 = V_1029 -> V_1000 ;
if ( V_67 -> V_138 != 0 )
F_260 ( V_143 , V_67 , V_1029 ) ;
}
T_2 F_267 ( struct V_134 * V_1044 , bool V_1028 )
{
#ifdef F_62
if ( V_1028 )
return ( sizeof( V_137 ) + V_1044 -> V_138
+ V_1044 -> V_139 + 8 ) ;
else
#endif
return ( sizeof( V_137 ) + V_1044 -> V_138
+ V_1044 -> V_139 ) ;
}
static void F_268 ( struct V_142 * V_143 )
{
V_144 * V_145 = (struct V_144 * ) V_143 -> V_151 ;
struct V_35 * V_36 = V_145 -> V_36 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_134 V_67 = {
. signal = 0 ,
. V_1045 = - 98 ,
. V_181 = 0 ,
. V_1046 = V_1047 ,
} ;
T_2 V_1048 = 0 ;
struct V_1049 * V_1050 = NULL ;
bool V_1051 = false ;
#ifdef F_62
struct V_142 * V_206 = NULL ;
T_2 V_205 = 0 ;
T_2 V_1052 = 0 ;
T_2 V_1053 = 0 ;
T_2 V_1054 = 0 ;
T_1 V_1055 = 0 ;
T_2 V_1056 = 0 ;
T_16 * V_1057 = NULL ;
T_1 V_1058 = 0 ;
T_1 V_1059 ;
#endif
if ( ( V_143 -> V_201 >= ( 20 + sizeof( V_137 ) ) ) && ( V_143 -> V_201 < V_148 ) ) {
#ifdef F_62
V_1055 = * ( V_143 -> V_42 + sizeof( V_137 ) ) ;
#endif
F_265 ( V_143 , & V_67 , false ) ;
#ifdef F_62
if ( V_1055 & V_1060 ) {
V_206 = V_143 ;
V_205 = V_67 . V_1031 - 4 ;
V_1052 = * ( T_2 * ) ( V_206 -> V_42 - 4 ) ;
V_1053 = ( T_3 ) ( V_1052 & 0x3FFF ) ;
V_143 = F_89 ( V_1053 ) ;
memcpy ( F_87 ( V_143 , V_1053 ) , V_206 -> V_42 , V_1053 ) ;
V_1056 = F_267 ( & V_67 , false ) ;
}
#endif
F_269 ( V_143 , V_143 -> V_201 - 4 ) ;
V_1048 = V_143 -> V_201 ;
V_1050 = (struct V_1049 * ) V_143 -> V_42 ;
V_1051 = false ;
if ( F_270 ( V_1050 -> V_1010 ) ) {
} else if ( F_271 ( V_1050 -> V_1010 ) ) {
} else {
V_1051 = true ;
}
if ( ! F_272 ( V_7 -> V_12 , V_143 , & V_67 ) ) {
F_110 ( V_143 ) ;
} else {
V_7 -> V_67 . V_92 ++ ;
if ( V_1051 )
V_7 -> V_67 . V_1061 += V_1048 ;
}
#ifdef F_62
V_1059 = 1 ;
if ( V_205 > 0 ) {
V_1054 = V_1053 + ( V_1056 + 8 ) ;
if ( ( V_1054 & 0xFF ) != 0 )
V_1054 = ( V_1054 & 0xFFFFFF00 ) + 256 ;
V_1054 -= 8 ;
V_1052 = V_1054 - V_1056 ;
if ( V_206 -> V_201 > V_1052 )
F_266 ( V_206 , V_1052 ) ;
else
V_206 -> V_201 = 0 ;
while ( V_206 -> V_201 >= F_267 ( & V_67 , true ) ) {
T_1 V_1062 = 0 , V_1063 = 0 ;
V_1057 = ( T_16 * ) ( V_206 -> V_42 ) ;
V_1062 = V_1057 -> V_1033 ;
V_1063 = V_1057 -> V_1032 ;
memcpy ( V_206 -> V_42 , & V_206 -> V_42 [ 44 ] , 2 ) ;
V_1057 -> V_1033 = V_1062 ;
V_1057 -> V_1032 = V_1063 ;
memset ( & V_67 , 0 , sizeof( struct V_134 ) ) ;
V_67 . signal = 0 ;
V_67 . V_1045 = - 98 ;
V_67 . V_181 = 0 ;
V_67 . V_1046 = V_1047 ;
F_265 ( V_206 , & V_67 , true ) ;
V_1053 = V_67 . V_1031 ;
if ( V_1053 > V_206 -> V_201 )
break;
V_143 = F_89 ( V_1053 ) ;
memcpy ( F_87 ( V_143 , V_1053 ) , V_206 -> V_42 , V_1053 ) ;
F_269 ( V_143 , V_143 -> V_201 - 4 ) ;
V_1048 = V_143 -> V_201 ;
V_1050 = (struct V_1049 * ) V_143 -> V_42 ;
V_1051 = false ;
if ( F_270 ( V_1050 -> V_1010 ) ) {
} else if ( F_271 ( V_1050 -> V_1010 ) ) {
} else {
V_1051 = true ;
}
if ( ! F_272 ( V_7 -> V_12 , V_143 , & V_67 ) ) {
F_110 ( V_143 ) ;
} else {
V_7 -> V_67 . V_92 ++ ;
if ( V_1051 )
V_7 -> V_67 . V_1061 += V_1048 ;
}
F_266 ( V_206 , V_1053 ) ;
V_1056 = F_267 ( & V_67 , true ) ;
V_1054 = V_1053 + V_1056 ;
if ( ( V_1054 & 0xFF ) != 0 ) {
V_1058 = 256 - ( V_1054 & 0xFF ) ;
if ( V_206 -> V_201 > V_1058 )
F_266 ( V_206 , V_1058 ) ;
else
V_206 -> V_201 = 0 ;
}
}
F_126 ( V_206 ) ;
}
#endif
} else {
V_7 -> V_67 . V_94 ++ ;
F_106 ( V_36 , L_139 , V_143 -> V_201 ) ;
F_110 ( V_143 ) ;
}
}
static void F_273 ( struct V_35 * V_36 ,
struct V_134 * V_135 )
{
T_1 * V_1064 ;
T_3 V_1065 = 0 ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
V_135 -> V_1066 += F_61 ( V_135 ) ;
V_1064 = V_135 -> V_1066 ;
V_1065 = V_135 -> V_1067 ;
#ifdef F_223
if ( ! V_592 -> V_593 )
F_274 ( V_592 , V_1068 ) ;
#endif
#ifdef F_275
T_11 V_1069 ;
V_592 -> V_1070 . V_1071 ( V_592 , V_1072 , ( T_1 * ) ( & V_1069 ) ) ;
if ( V_1069 == V_763 )
return;
#endif
V_7 -> V_67 . V_1073 ++ ;
#ifdef F_223
F_276 ( V_592 , V_1068 ) ;
#endif
if ( F_90 ( V_36 , V_135 ) )
return;
#ifdef F_277
F_278 () ;
#endif
}
static void F_279 ( struct V_142 * V_143 ,
struct V_134 * V_67 )
{
V_137 * V_1030 = ( V_137 * ) V_143 -> V_42 ;
V_67 -> V_1066 = ( T_1 * ) V_143 -> V_42 ;
V_67 -> V_1031 = V_1030 -> V_1031 ;
V_67 -> V_138 = 0 ;
V_67 -> V_139 = 0 ;
V_67 -> V_1067 = V_67 -> V_1031 - V_1074 ;
V_67 -> V_1075 = V_67 -> V_1067 ;
V_67 -> V_1076 = 0 ;
V_67 -> V_1077 = 1 ;
}
static void F_280 ( struct V_142 * V_143 )
{
struct V_144 * V_145 = (struct V_144 * ) V_143 -> V_151 ;
struct V_35 * V_36 = V_145 -> V_36 ;
struct V_134 V_67 = {
. signal = 0 ,
. V_1045 = - 98 ,
. V_181 = 0 ,
. V_1046 = V_1047 ,
} ;
if ( ( V_143 -> V_201 >= ( 20 + sizeof( V_137 ) ) ) && ( V_143 -> V_201 < V_148 ) ) {
F_279 ( V_143 , & V_67 ) ;
F_273 ( V_36 , & V_67 ) ;
F_110 ( V_143 ) ;
}
}
void V_627 ( struct V_6 * V_7 )
{
struct V_142 * V_143 ;
struct V_144 * V_145 ;
while ( NULL != ( V_143 = F_112 ( & V_7 -> V_180 ) ) ) {
V_145 = (struct V_144 * ) V_143 -> V_151 ;
switch ( V_145 -> V_152 ) {
case 3 :
V_7 -> V_550 -- ;
F_268 ( V_143 ) ;
break;
case 9 :
F_9 ( V_895 , L_140 ,
V_145 -> V_152 ) ;
F_280 ( V_143 ) ;
break;
default:
F_9 ( V_27 , L_141 ,
V_145 -> V_152 ) ;
F_126 ( V_143 ) ;
break;
}
}
}
static int F_281 ( struct V_1078 * V_1079 ,
const struct V_1080 * V_1081 )
{
struct V_35 * V_36 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_47 * V_48 = F_282 ( V_1079 ) ;
int V_192 ;
F_9 ( V_95 , L_142 ) ;
V_36 = F_283 ( sizeof( struct V_6 ) ) ;
if ( V_36 == NULL )
return - V_359 ;
F_284 ( V_1079 , V_36 ) ;
F_285 ( V_36 , & V_1079 -> V_36 ) ;
V_7 = F_18 ( V_36 ) ;
V_7 -> V_12 = F_104 ( V_36 ) ;
V_7 -> V_48 = V_48 ;
V_36 -> V_1082 = & V_1083 ;
V_36 -> V_1084 = (struct V_1085 * ) & V_1086 ;
V_36 -> type = V_1087 ;
V_36 -> V_1088 = V_51 * 3 ;
if ( F_286 ( V_36 , V_1089 ) < 0 ) {
F_9 ( V_95 , L_143 ) ;
V_1089 = L_144 ;
F_286 ( V_36 , V_1089 ) ;
}
F_9 ( V_95 , L_145 ) ;
if ( F_177 ( V_36 ) != 0 ) {
F_9 ( V_27 , L_146 ) ;
V_192 = - V_1090 ;
goto V_1091;
}
F_214 ( V_36 ) ;
F_236 ( V_36 ) ;
V_192 = F_287 ( V_36 ) ;
if ( V_192 )
goto V_1092;
F_9 ( V_95 , L_147 , V_36 -> V_106 ) ;
F_47 ( V_36 ) ;
F_9 ( V_95 , L_148 ) ;
return 0 ;
V_1092:
F_235 ( V_36 ) ;
F_136 ( V_7 -> V_609 ) ;
V_7 -> V_609 = NULL ;
F_137 ( V_36 ) ;
F_288 ( V_7 -> V_484 ) ;
F_60 ( 10 ) ;
V_1091:
F_289 ( V_36 ) ;
F_9 ( V_27 , L_149 ) ;
return V_192 ;
}
void F_208 ( struct V_6 * V_7 )
{
F_290 ( & V_7 -> V_114 ) ;
F_212 ( & V_7 -> V_619 ) ;
F_212 ( & V_7 -> V_449 ) ;
F_290 ( & V_7 -> V_454 ) ;
}
static void F_291 ( struct V_1078 * V_1079 )
{
struct V_35 * V_36 = F_292 ( V_1079 ) ;
struct V_6 * V_7 = F_18 ( V_36 ) ;
if ( V_36 ) {
F_293 ( V_36 ) ;
F_9 ( V_863 , L_150 ) ;
F_50 ( V_36 ) ;
F_235 ( V_36 ) ;
F_136 ( V_7 -> V_609 ) ;
V_7 -> V_609 = NULL ;
F_137 ( V_36 ) ;
F_288 ( V_7 -> V_484 ) ;
F_60 ( 10 ) ;
}
F_289 ( V_36 ) ;
F_9 ( V_863 , L_151 ) ;
}
static int T_17 F_294 ( void )
{
int V_192 ;
#ifdef F_295
V_192 = F_296 () ;
if ( V_192 ) {
F_297 ( L_152 , V_192 ) ;
return V_192 ;
}
#endif
V_192 = F_298 () ;
if ( V_192 ) {
F_297 ( L_153 , V_192 ) ;
return V_192 ;
}
V_192 = F_299 () ;
if ( V_192 ) {
F_297 ( L_154 , V_192 ) ;
return V_192 ;
}
V_192 = F_300 () ;
if ( V_192 ) {
F_297 ( L_155 , V_192 ) ;
return V_192 ;
}
V_192 = F_301 () ;
if ( V_192 ) {
F_297 ( L_156 , V_192 ) ;
return V_192 ;
}
F_302 ( L_157 ) ;
F_302 ( L_158 ) ;
F_9 ( V_95 , L_159 ) ;
F_9 ( V_95 , L_160 , V_1093 ) ;
F_40 () ;
return F_303 ( & V_1094 ) ;
}
static void T_18 F_304 ( void )
{
F_305 ( & V_1094 ) ;
F_9 ( V_863 , L_161 ) ;
}
void F_306 ( struct V_35 * V_36 , int V_1095 )
{
unsigned long V_160 ;
short V_1096 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
F_96 ( & V_7 -> V_196 , V_160 ) ;
V_1096 = F_52 ( V_36 , V_1095 ) ;
F_99 ( & V_7 -> V_196 , V_160 ) ;
if ( V_1096 )
F_307 ( V_7 -> V_12 ) ;
}
void F_140 ( struct V_35 * V_36 )
{
T_1 V_713 = 0x0 ;
struct V_6 * V_7 = (struct V_6 * ) F_18 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
V_713 = V_749 | V_750 ;
if ( ( ( V_255 == V_11 -> V_254 ) || ( V_256 == V_11 -> V_254 ) ) && ( V_7 -> V_12 -> V_891 != 2 ) ) {
V_713 |= V_1097 ;
V_713 |= V_1098 ;
} else if ( ( V_11 -> V_121 == V_125 ) && ( V_11 -> V_254 & ( V_258 | V_257 ) ) ) {
V_713 |= V_1097 ;
V_713 |= V_1098 ;
}
V_11 -> V_1099 = 1 ;
if ( ( V_11 -> V_267 -> V_1100 & V_1101 ) || ! V_1102 ) {
V_11 -> V_1099 = 0 ;
V_713 &= ~ V_750 ;
}
F_9 ( V_823 , L_162 , V_28 ,
V_11 -> V_1099 , V_11 -> V_254 , V_713 ) ;
F_24 ( V_36 , V_752 , V_713 ) ;
}
void F_205 ( struct V_35 * V_36 , T_1 V_1103 , T_1 V_1104 , T_3 V_1105 ,
T_1 * V_820 , T_1 V_1106 , T_2 * V_1107 )
{
T_2 V_1108 = 0 ;
T_2 V_1109 = 0 ;
T_3 V_1110 = 0 ;
T_1 V_1 ;
if ( V_1103 >= V_1111 )
F_9 ( V_27 , L_163 ) ;
F_9 ( V_823 , L_164 , V_36 , V_1103 , V_1104 , V_1105 , V_820 ) ;
if ( V_1106 )
V_1110 |= V_1112 | ( V_1105 << 2 ) ;
else
V_1110 |= V_1112 | ( V_1105 << 2 ) | V_1104 ;
for ( V_1 = 0 ; V_1 < V_843 ; V_1 ++ ) {
V_1108 = V_1 + V_843 * V_1103 ;
V_1108 |= V_38 | V_44 ;
if ( V_1 == 0 ) {
V_1109 = ( T_2 ) ( * ( V_820 + 0 ) ) << 16 |
( T_2 ) ( * ( V_820 + 1 ) ) << 24 |
( T_2 ) V_1110 ;
F_13 ( V_36 , V_43 , V_1109 ) ;
F_13 ( V_36 , V_40 , V_1108 ) ;
} else if ( V_1 == 1 ) {
V_1109 = ( T_2 ) ( * ( V_820 + 2 ) ) |
( T_2 ) ( * ( V_820 + 3 ) ) << 8 |
( T_2 ) ( * ( V_820 + 4 ) ) << 16 |
( T_2 ) ( * ( V_820 + 5 ) ) << 24 ;
F_13 ( V_36 , V_43 , V_1109 ) ;
F_13 ( V_36 , V_40 , V_1108 ) ;
} else {
if ( V_1107 != NULL ) {
F_13 ( V_36 , V_43 , ( T_2 ) ( * ( V_1107 + V_1 - 2 ) ) ) ;
F_13 ( V_36 , V_40 , V_1108 ) ;
}
}
}
}
