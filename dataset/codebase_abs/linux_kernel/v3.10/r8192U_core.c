double F_1 ( int V_1 ) { return V_1 ; }
unsigned int F_2 ( double V_2 ) { return V_2 ; }
double F_3 ( double V_3 , double V_4 ) { return V_3 + V_4 ; }
double F_4 ( float V_3 , float V_4 ) { return V_3 + V_4 ; }
double F_5 ( double V_3 , double V_4 ) { return V_3 - V_4 ; }
double F_6 ( float V_3 ) { return V_3 ; }
static void F_7 ( T_1 V_5 , struct V_6 * V_7 )
{
int V_1 , V_8 = - 1 , V_9 = - 1 ;
struct V_10 * V_11 = V_7 -> V_12 ;
switch ( V_5 )
{
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
}
else {
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
void F_12 ( struct V_35 * V_36 , T_1 V_37 , T_2 V_38 )
{
F_13 ( V_36 , V_39 , V_38 ) ;
F_13 ( V_36 , V_40 , V_41 | V_42 | ( V_37 & 0xff ) ) ;
}
T_2 F_14 ( struct V_35 * V_36 , T_1 V_37 )
{
F_13 ( V_36 , V_40 , 0x80000000 | ( V_37 & 0xff ) ) ;
return F_15 ( V_36 , 0xa8 ) ;
}
void F_16 ( struct V_35 * V_36 , int V_43 , T_1 V_38 )
{
int V_44 ;
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
struct V_45 * V_46 = V_7 -> V_46 ;
V_44 = F_18 ( V_46 , F_19 ( V_46 , 0 ) ,
V_47 , V_48 ,
V_43 | 0xfe00 , 0 , & V_38 , 1 , V_49 / 2 ) ;
if ( V_44 < 0 )
{
F_20 ( L_2 , V_44 ) ;
}
}
T_1 F_21 ( struct V_35 * V_36 , int V_43 )
{
int V_44 ;
T_1 V_38 ;
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
struct V_45 * V_46 = V_7 -> V_46 ;
V_44 = F_18 ( V_46 , F_22 ( V_46 , 0 ) ,
V_50 , V_51 ,
V_43 | 0xfe00 , 0 , & V_38 , 1 , V_49 / 2 ) ;
if ( V_44 < 0 )
{
F_20 ( L_3 , V_44 ) ;
}
return V_38 ;
}
void F_23 ( struct V_35 * V_36 , int V_43 , T_1 V_38 )
{
int V_44 ;
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
struct V_45 * V_46 = V_7 -> V_46 ;
V_44 = F_18 ( V_46 , F_19 ( V_46 , 0 ) ,
V_47 , V_48 ,
( V_43 & 0xff ) | 0xff00 , ( V_43 >> 8 ) & 0x0f , & V_38 , 1 , V_49 / 2 ) ;
if ( V_44 < 0 )
{
F_20 ( L_4 , V_44 ) ;
}
}
void F_24 ( struct V_35 * V_36 , int V_43 , T_3 V_38 )
{
int V_44 ;
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
struct V_45 * V_46 = V_7 -> V_46 ;
V_44 = F_18 ( V_46 , F_19 ( V_46 , 0 ) ,
V_47 , V_48 ,
( V_43 & 0xff ) | 0xff00 , ( V_43 >> 8 ) & 0x0f , & V_38 , 2 , V_49 / 2 ) ;
if ( V_44 < 0 )
{
F_20 ( L_5 , V_44 ) ;
}
}
void F_13 ( struct V_35 * V_36 , int V_43 , T_2 V_38 )
{
int V_44 ;
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
struct V_45 * V_46 = V_7 -> V_46 ;
V_44 = F_18 ( V_46 , F_19 ( V_46 , 0 ) ,
V_47 , V_48 ,
( V_43 & 0xff ) | 0xff00 , ( V_43 >> 8 ) & 0x0f , & V_38 , 4 , V_49 / 2 ) ;
if ( V_44 < 0 )
{
F_20 ( L_6 , V_44 ) ;
}
}
T_1 F_25 ( struct V_35 * V_36 , int V_43 )
{
T_1 V_38 ;
int V_44 ;
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
struct V_45 * V_46 = V_7 -> V_46 ;
V_44 = F_18 ( V_46 , F_22 ( V_46 , 0 ) ,
V_50 , V_51 ,
( V_43 & 0xff ) | 0xff00 , ( V_43 >> 8 ) & 0x0f , & V_38 , 1 , V_49 / 2 ) ;
if ( V_44 < 0 )
{
F_20 ( L_7 , V_44 ) ;
}
return V_38 ;
}
T_3 F_26 ( struct V_35 * V_36 , int V_43 )
{
T_3 V_38 ;
int V_44 ;
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
struct V_45 * V_46 = V_7 -> V_46 ;
V_44 = F_18 ( V_46 , F_22 ( V_46 , 0 ) ,
V_50 , V_51 ,
( V_43 & 0xff ) | 0xff00 , ( V_43 >> 8 ) & 0x0f ,
& V_38 , 2 , V_49 / 2 ) ;
if ( V_44 < 0 )
F_20 ( L_8 , V_44 ) ;
return V_38 ;
}
T_3 F_27 ( struct V_35 * V_36 , int V_43 )
{
T_3 V_38 ;
int V_44 ;
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
struct V_45 * V_46 = V_7 -> V_46 ;
V_44 = F_18 ( V_46 , F_22 ( V_46 , 0 ) ,
V_50 , V_51 ,
V_43 | 0xfe00 , 0 , & V_38 , 2 , V_49 / 2 ) ;
if ( V_44 < 0 )
F_20 ( L_8 , V_44 ) ;
return V_38 ;
}
T_2 F_15 ( struct V_35 * V_36 , int V_43 )
{
T_2 V_38 ;
int V_44 ;
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
struct V_45 * V_46 = V_7 -> V_46 ;
V_44 = F_18 ( V_46 , F_22 ( V_46 , 0 ) ,
V_50 , V_51 ,
( V_43 & 0xff ) | 0xff00 , ( V_43 >> 8 ) & 0x0f ,
& V_38 , 4 , V_49 / 2 ) ;
if ( V_44 < 0 )
F_20 ( L_9 , V_44 ) ;
return V_38 ;
}
inline void F_28 ( struct V_35 * V_36 )
{
}
static int F_29 ( struct V_52 * V_53 , void * V_54 )
{
struct V_35 * V_36 = V_53 -> V_55 ;
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_56 * V_57 ;
F_30 (target, &ieee->network_list, list) {
const char * V_58 = L_10 ;
if ( V_57 -> V_59 > 0 || V_57 -> V_60 > 0 )
V_58 = L_11 ;
F_31 ( V_53 , L_12 , V_57 -> V_61 , V_58 ) ;
}
return 0 ;
}
static int F_32 ( struct V_52 * V_53 , void * V_54 )
{
struct V_35 * V_36 = V_53 -> V_55 ;
int V_1 , V_62 , V_63 = 0xff ;
F_33 ( V_53 , L_13 ) ;
for ( V_62 = 0 ; V_62 <= V_63 ; ) {
F_31 ( V_53 , L_14 , V_62 ) ;
for ( V_1 = 0 ; V_1 < 16 && V_62 <= V_63 ; V_1 ++ , V_62 ++ )
F_31 ( V_53 , L_15 , F_25 ( V_36 , 0x000 | V_62 ) ) ;
}
F_33 ( V_53 , L_16 ) ;
for ( V_62 = 0 ; V_62 <= V_63 ; ) {
F_31 ( V_53 , L_14 , V_62 ) ;
for ( V_1 = 0 ; V_1 < 16 && V_62 <= V_63 ; V_1 ++ , V_62 ++ )
F_31 ( V_53 , L_15 , F_25 ( V_36 , 0x100 | V_62 ) ) ;
}
F_33 ( V_53 , L_17 ) ;
for ( V_62 = 0 ; V_62 <= V_63 ; ) {
F_31 ( V_53 , L_14 , V_62 ) ;
for( V_1 = 0 ; V_1 < 16 && V_62 <= V_63 ; V_1 ++ , V_62 ++ )
F_31 ( V_53 , L_15 , F_25 ( V_36 , 0x300 | V_62 ) ) ;
}
F_34 ( V_53 , '\n' ) ;
return 0 ;
}
static int F_35 ( struct V_52 * V_53 , void * V_54 )
{
struct V_35 * V_36 = V_53 -> V_55 ;
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
F_31 ( V_53 ,
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
L_38
L_39
L_40
L_41 ,
V_7 -> V_64 . V_65 ,
V_7 -> V_64 . V_66 ,
V_7 -> V_64 . V_67 ,
V_7 -> V_64 . V_68 ,
V_7 -> V_64 . V_69 ,
V_7 -> V_64 . V_70 ,
V_7 -> V_64 . V_71 ,
V_7 -> V_64 . V_72 ,
V_7 -> V_64 . V_73 ,
V_7 -> V_64 . V_74 ,
V_7 -> V_64 . V_75 ,
V_7 -> V_64 . V_76 ,
V_7 -> V_64 . V_77 ,
F_36 ( V_36 ) ,
V_7 -> V_64 . V_78 ,
F_37 ( & ( V_7 -> V_79 [ V_80 ] ) ) ,
F_37 ( & ( V_7 -> V_79 [ V_81 ] ) ) ,
F_37 ( & ( V_7 -> V_79 [ V_82 ] ) ) ,
F_37 ( & ( V_7 -> V_79 [ V_83 ] ) ) ,
V_7 -> V_64 . V_84 ,
V_7 -> V_64 . V_85 ,
V_7 -> V_64 . V_86 ,
V_7 -> V_64 . V_87 ,
V_7 -> V_64 . V_88
) ;
return 0 ;
}
static int F_38 ( struct V_52 * V_53 , void * V_54 )
{
struct V_35 * V_36 = V_53 -> V_55 ;
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
F_31 ( V_53 ,
L_42
L_43
L_44 ,
V_7 -> V_64 . V_89 ,
V_7 -> V_64 . V_90 ,
V_7 -> V_64 . V_91 ) ;
return 0 ;
}
void F_39 ( void )
{
F_9 ( V_92 , L_45 ) ;
V_93 = F_40 ( V_94 , V_95 . V_96 ) ;
}
void F_41 ( void )
{
F_42 ( V_94 , V_95 . V_96 ) ;
}
static int F_43 ( struct V_97 * V_97 , struct V_98 * V_98 )
{
struct V_35 * V_36 = F_44 ( V_97 ) ;
int (* F_45)( struct V_52 * , void * ) = F_46 ( V_97 ) ;
return F_47 ( V_98 , F_45 , V_36 ) ;
}
void F_48 ( struct V_35 * V_36 )
{
const struct V_99 * V_100 ;
struct V_101 * V_102 ;
if ( V_93 ) {
V_102 = F_49 ( V_36 -> V_103 , 0 , V_93 , V_36 ) ;
if ( ! V_102 ) {
F_9 ( V_27 , L_46 ,
V_36 -> V_103 ) ;
return;
}
for ( V_100 = V_104 ; V_100 -> V_103 [ 0 ] ; V_100 ++ ) {
if ( ! F_50 ( V_100 -> V_103 , V_105 | V_106 , V_102 ,
& V_107 , V_100 -> F_45 ) ) {
F_9 ( V_27 , L_47
L_48 ,
V_36 -> V_103 , V_100 -> V_103 ) ;
return;
}
}
}
}
void F_51 ( struct V_35 * V_36 )
{
F_52 ( V_36 -> V_103 , V_93 ) ;
}
void F_53 ( T_2 * V_108 , int V_109 )
{
int V_1 ;
T_1 * V_110 = ( T_1 * ) V_108 ;
F_20 ( L_49 , V_109 ) ;
for( V_1 = 0 ; V_1 < V_109 ; V_1 ++ )
F_20 ( L_50 , V_110 [ V_1 ] ) ;
F_20 ( L_51 , V_109 ) ;
for( V_1 = 0 ; V_1 < V_109 ; V_1 ++ )
F_20 ( L_52 , V_110 [ V_1 ] ) ;
F_20 ( L_53 ) ;
}
short F_54 ( struct V_35 * V_36 , int V_111 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
int V_112 = F_37 ( & V_7 -> V_79 [ V_111 ] ) ;
return ( V_112 < V_113 ) ;
}
void F_55 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
F_56 ( & V_7 -> V_114 ) ;
}
void F_57 ( struct V_35 * V_36 )
{
int V_1 ;
for( V_1 = 0 ; V_1 < 63 ; V_1 ++ )
F_9 ( V_115 , L_54 , V_1 , F_58 ( V_36 , V_1 ) ) ;
}
void F_59 ( struct V_35 * V_36 )
{
int V_1 ;
int V_62 ;
int V_63 = 0x1ff ;
F_9 ( V_116 , L_55 ) ;
for( V_62 = 0 ; V_62 <= V_63 ; )
{
F_20 ( L_56 , V_62 ) ;
for( V_1 = 0 ; V_1 < 16 && V_62 <= V_63 ; V_1 ++ , V_62 ++ )
F_20 ( L_15 , F_25 ( V_36 , V_62 ) ) ;
}
F_20 ( L_53 ) ;
}
void F_60 ( struct V_35 * V_36 , int V_117 )
{
T_1 V_118 ;
V_118 = F_25 ( V_36 , V_119 ) ;
V_118 = V_118 & ~ V_120 ;
V_118 = V_118 | ( V_117 << V_121 ) ;
V_118 = V_118 & ~ ( 1 << V_122 ) ;
V_118 = V_118 & ~ ( 1 << V_123 ) ;
F_23 ( V_36 , V_119 , V_118 ) ;
}
void F_61 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
T_1 V_124 ;
V_124 = F_25 ( V_36 , V_125 ) ;
V_124 &= ~ V_126 ;
if ( V_7 -> V_12 -> V_127 == V_128 ) {
if ( V_7 -> V_12 -> V_129 == V_130 )
V_124 |= ( V_131 << V_132 ) ;
else if ( V_7 -> V_12 -> V_129 == V_133 )
V_124 |= ( V_134 << V_132 ) ;
else if ( V_7 -> V_12 -> V_129 == V_135 )
V_124 |= ( V_136 << V_132 ) ;
} else
V_124 |= ( V_137 << V_132 ) ;
F_23 ( V_36 , V_125 , V_124 ) ;
}
void F_62 ( struct V_35 * V_36 , short V_138 )
{
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
F_9 ( V_139 , L_57 , V_28 , V_138 ) ;
V_7 -> V_140 = V_138 ;
#ifndef F_63
if ( V_7 -> V_141 )
V_7 -> V_141 ( V_36 , V_7 -> V_140 ) ;
F_64 ( 10 ) ;
#endif
}
T_2 F_65 ( struct V_142 * V_143 )
{
#ifdef F_66
if ( V_143 -> V_144 )
return ( sizeof( V_145 ) + V_143 -> V_146
+ V_143 -> V_147 + 8 ) ;
else
#endif
return ( sizeof( V_145 ) + V_143 -> V_146
+ V_143 -> V_147 ) ;
}
static int F_67 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
struct V_148 * V_149 ;
struct V_150 * V_151 ;
struct V_152 * V_153 ;
while ( F_68 ( & V_7 -> V_154 ) < V_155 ) {
V_151 = F_69 ( V_156 , V_157 ) ;
if ( ! V_151 )
break;
V_149 = F_70 ( 0 , V_157 ) ;
if ( ! V_149 ) {
F_71 ( V_151 ) ;
break;
}
F_72 ( V_149 , V_7 -> V_46 ,
F_73 ( V_7 -> V_46 , 3 ) , F_74 ( V_151 ) ,
V_156 , V_158 , V_151 ) ;
V_153 = (struct V_152 * ) V_151 -> V_159 ;
V_153 -> V_148 = V_149 ;
V_153 -> V_36 = V_36 ;
V_153 -> V_160 = 3 ;
F_75 ( & V_7 -> V_154 , V_151 ) ;
F_76 ( V_149 , V_157 ) ;
}
while ( F_68 ( & V_7 -> V_154 ) < V_155 + 3 ) {
V_151 = F_69 ( V_156 , V_157 ) ;
if ( ! V_151 )
break;
V_149 = F_70 ( 0 , V_157 ) ;
if ( ! V_149 ) {
F_71 ( V_151 ) ;
break;
}
F_72 ( V_149 , V_7 -> V_46 ,
F_73 ( V_7 -> V_46 , 9 ) , F_74 ( V_151 ) ,
V_156 , V_158 , V_151 ) ;
V_153 = (struct V_152 * ) V_151 -> V_159 ;
V_153 -> V_148 = V_149 ;
V_153 -> V_36 = V_36 ;
V_153 -> V_160 = 9 ;
F_75 ( & V_7 -> V_154 , V_151 ) ;
F_76 ( V_149 , V_157 ) ;
}
return 0 ;
}
void F_77 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
T_2 V_161 ;
V_161 = F_15 ( V_36 , V_162 ) ;
V_161 = V_161 & ~ V_163 ;
V_161 = V_161 | V_164 ;
V_161 = V_161 | V_165 ;
V_161 = V_161 | V_166 ;
V_161 = V_161 | V_167 ;
if ( V_36 -> V_168 & V_169 ) { F_78 ( L_58 ) ; }
if( V_7 -> V_12 -> V_129 == V_170 || \
V_36 -> V_168 & V_169 ) {
V_161 = V_161 | V_171 ;
} else{
V_161 = V_161 | V_172 ;
V_161 = V_161 | V_173 ;
}
if( V_7 -> V_12 -> V_129 == V_170 ) {
V_161 = V_161 | V_174 ;
V_161 = V_161 | V_175 ;
}
if( V_7 -> V_176 == 1 && V_7 -> V_12 -> V_129 == V_170 )
V_161 = V_161 | V_177 ;
V_161 = V_161 & ~ V_178 ;
V_161 = V_161 | ( V_179 << V_180 ) ;
V_161 = V_161 & ~ V_181 ;
V_161 = V_161 | ( ( T_2 ) 7 << V_182 ) ;
V_161 = V_161 | V_183 ;
F_13 ( V_36 , V_162 , V_161 ) ;
#ifdef F_79
F_78 ( L_59 , V_161 , F_15 ( V_36 , V_162 ) ) ;
#endif
}
void F_80 ( struct V_35 * V_36 )
{
F_67 ( V_36 ) ;
}
void F_81 ( struct V_35 * V_36 )
{
}
void F_82 ( struct V_35 * V_36 )
{
T_1 V_184 ;
struct V_6 * V_7 = F_17 ( V_36 ) ;
struct V_150 * V_151 ;
struct V_152 * V_153 ;
V_184 = F_25 ( V_36 , V_185 ) ;
F_23 ( V_36 , V_185 , V_184 & ~ \
( V_186 | V_187 ) ) ;
F_28 ( V_36 ) ;
F_64 ( 10 ) ;
while ( ( V_151 = F_83 ( & V_7 -> V_154 ) ) ) {
V_153 = (struct V_152 * ) V_151 -> V_159 ;
if ( ! V_153 -> V_148 )
continue;
F_84 ( V_153 -> V_148 ) ;
F_71 ( V_151 ) ;
}
if ( F_68 ( & V_7 -> V_188 ) ) {
F_20 ( V_189 L_60 ) ;
}
F_85 ( & V_7 -> V_188 ) ;
return;
}
int F_86 ( struct V_35 * V_36 , int V_190 )
{
return 0 ;
}
inline T_3 F_87 ( int V_191 )
{
switch( V_191 ) {
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
inline T_3 F_88 ( short V_191 )
{
if ( V_191 > 11 ) return 0 ;
return V_192 [ V_191 ] ;
}
static void V_158 ( struct V_148 * V_148 )
{
struct V_150 * V_151 = (struct V_150 * ) V_148 -> V_193 ;
struct V_152 * V_153 = (struct V_152 * ) V_151 -> V_159 ;
struct V_35 * V_36 = V_153 -> V_36 ;
struct V_6 * V_7 = F_17 ( V_36 ) ;
int V_160 = V_153 -> V_160 ;
int V_194 ;
if( ! V_7 -> V_195 )
return;
if ( F_89 ( V_148 -> V_44 ) ) {
V_153 -> V_148 = NULL ;
V_7 -> V_64 . V_90 ++ ;
V_7 -> V_12 -> V_64 . V_196 ++ ;
F_90 ( V_148 ) ;
return;
}
F_91 ( V_151 , & V_7 -> V_154 ) ;
F_92 ( V_151 , V_148 -> V_197 ) ;
F_75 ( & V_7 -> V_188 , V_151 ) ;
F_93 ( & V_7 -> V_198 ) ;
V_151 = F_94 ( V_156 ) ;
if ( F_89 ( ! V_151 ) ) {
F_90 ( V_148 ) ;
F_20 ( L_61 , V_28 ) ;
return;
}
F_72 ( V_148 , V_7 -> V_46 ,
F_73 ( V_7 -> V_46 , V_160 ) , F_74 ( V_151 ) ,
V_156 , V_158 , V_151 ) ;
V_153 = (struct V_152 * ) V_151 -> V_159 ;
V_153 -> V_148 = V_148 ;
V_153 -> V_36 = V_36 ;
V_153 -> V_160 = V_160 ;
V_148 -> V_199 = F_74 ( V_151 ) ;
V_148 -> V_193 = V_151 ;
F_75 ( & V_7 -> V_154 , V_151 ) ;
V_194 = F_76 ( V_148 , V_200 ) ;
if( V_194 && V_194 != V_201 )
F_20 ( L_62 , V_194 , V_148 -> V_44 ) ;
}
T_2
F_95 (
struct V_35 * V_36 ,
struct V_142 * V_143
)
{
T_2 V_44 ;
V_44 = F_96 ( V_36 , V_143 ) ;
if ( V_44 )
{
F_78 ( L_63 ) ;
}
else
{
}
return V_44 ;
}
void F_97 ( struct V_35 * V_36 )
{
}
void F_98 ( struct V_35 * V_36 )
{
}
void F_99 ( struct V_150 * V_151 , struct V_35 * V_36 , int V_191 )
{
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
int V_202 ;
unsigned long V_168 ;
T_4 * V_203 = ( T_4 * ) ( V_151 -> V_159 + V_204 ) ;
T_1 V_111 = V_203 -> V_111 ;
assert ( V_111 != V_205 ) ;
F_100 ( & V_7 -> V_206 , V_168 ) ;
memcpy ( ( unsigned char * ) ( V_151 -> V_159 ) , & V_36 , sizeof( V_36 ) ) ;
V_203 -> V_207 = 1 ;
F_101 ( V_151 , V_7 -> V_12 -> V_208 ) ;
V_202 = F_102 ( V_36 , V_151 ) ;
F_103 ( & V_7 -> V_206 , V_168 ) ;
return;
}
int F_104 ( struct V_150 * V_151 , struct V_35 * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
int V_202 ;
unsigned long V_168 ;
T_4 * V_203 = ( T_4 * ) ( V_151 -> V_159 + V_204 ) ;
T_1 V_111 = V_203 -> V_111 ;
F_100 ( & V_7 -> V_206 , V_168 ) ;
memcpy ( ( unsigned char * ) ( V_151 -> V_159 ) , & V_36 , sizeof( V_36 ) ) ;
if( V_111 == V_205 ) {
F_101 ( V_151 , V_209 ) ;
F_105 ( V_36 , V_151 ) ;
V_202 = 1 ;
F_103 ( & V_7 -> V_206 , V_168 ) ;
return V_202 ;
} else {
F_101 ( V_151 , V_7 -> V_12 -> V_208 ) ;
V_202 = F_102 ( V_36 , V_151 ) ;
}
F_103 ( & V_7 -> V_206 , V_168 ) ;
return V_202 ;
}
T_3 F_106 ( struct V_35 * V_36 , struct V_150 * V_151 )
{
T_3 V_210 = 256 - ( ( V_151 -> V_109 + V_211 ) % 256 ) ;
return ( V_210 & 0xff ) ;
}
struct V_150 * F_107 ( struct V_35 * V_36 , struct V_212 * V_213 )
{
struct V_10 * V_11 = F_108 ( V_36 ) ;
struct V_6 * V_7 = F_17 ( V_36 ) ;
T_4 * V_203 = NULL ;
T_1 V_1 ;
T_2 V_214 ;
struct V_150 * V_151 ;
struct V_150 * V_215 ;
T_5 * V_216 = NULL ;
T_6 * V_217 = NULL ;
V_151 = V_213 -> V_218 [ 0 ] ;
V_214 = V_151 -> V_109 ;
for( V_1 = 1 ; V_1 < V_213 -> V_219 ; V_1 ++ ) {
V_214 += F_106 ( V_36 , V_151 ) ;
V_151 = V_213 -> V_218 [ V_1 ] ;
V_214 += ( V_151 -> V_109 + V_211 ) ;
}
V_215 = F_94 ( V_214 + V_11 -> V_208 ) ;
memset ( V_215 -> V_38 , 0 , V_215 -> V_109 ) ;
F_109 ( V_215 , V_11 -> V_208 ) ;
V_151 = V_213 -> V_218 [ 0 ] ;
V_203 = ( T_4 * ) ( V_151 -> V_159 + V_204 ) ;
V_203 -> V_220 = 1 ;
V_203 -> V_221 = V_151 -> V_109 ;
V_203 -> V_222 = V_213 -> V_219 ;
F_20 ( L_64 , V_203 -> V_222 ) ;
memcpy ( V_215 -> V_159 , V_151 -> V_159 , sizeof( V_151 -> V_159 ) ) ;
memcpy ( F_92 ( V_215 , V_151 -> V_109 ) , V_151 -> V_38 , V_151 -> V_109 ) ;
for( V_1 = 1 ; V_1 < V_213 -> V_219 ; V_1 ++ ) {
F_92 ( V_215 , F_106 ( V_36 , V_151 ) ) ;
V_151 = V_213 -> V_218 [ V_1 ] ;
V_203 = ( T_4 * ) ( V_151 -> V_159 + V_204 ) ;
V_216 = ( T_5 * ) V_215 -> V_223 ;
V_217 = ( T_6 * ) ( V_215 -> V_223 + sizeof( T_5 ) ) ;
memset ( V_217 , 0 , sizeof( T_6 ) ) ;
V_217 -> V_224 = ( V_203 -> V_225 & 0x80 ) ? 1 : 0 ;
V_217 -> V_226 = F_110 ( V_203 -> V_225 ) ;
V_217 -> V_227 = V_203 -> V_207 ;
V_217 -> Short = F_111 ( V_217 -> V_224 , V_217 -> V_226 , V_203 ) ;
if( V_203 -> V_228 ) {
V_217 -> V_229 = 1 ;
V_217 -> V_230 = V_203 -> V_231 ;
V_217 -> V_232 = V_203 -> V_233 & 0x07 ;
} else {
V_217 -> V_229 = 0 ;
V_217 -> V_230 = 0 ;
V_217 -> V_232 = 0 ;
}
V_217 -> V_234 = ( V_203 -> V_235 ) ? 1 : 0 ;
V_217 -> V_236 = ( V_203 -> V_237 ) ? 1 : 0 ;
V_217 -> V_238 = ( V_203 -> V_239 ) ? 1 : 0 ;
V_217 -> V_240 = ( V_203 -> V_241 & 0x80 ) ? 1 : 0 ;
V_217 -> V_242 = F_110 ( ( T_1 ) V_203 -> V_241 ) ;
V_217 -> V_243 = ( V_217 -> V_240 == 0 ) ? ( V_203 -> V_244 ) : 0 ;
V_217 -> V_245 = ( V_217 -> V_240 == 1 ) ? ( ( V_203 -> V_246 ) ? 1 : 0 ) : 0 ;
V_217 -> V_247 = ( V_217 -> V_240 == 0 ) ? ( V_203 -> V_248 ? 1 : 0 ) :\
( V_203 -> V_249 ? 1 : 0 ) ;
if( V_7 -> V_250 == V_251 )
{
if( V_203 -> V_252 ) {
V_217 -> V_253 = 1 ;
V_217 -> V_254 = 0 ;
} else {
V_217 -> V_253 = 0 ;
V_217 -> V_254 = V_7 -> V_255 ;
}
} else {
V_217 -> V_253 = 0 ;
V_217 -> V_254 = 0 ;
}
memset ( V_216 , 0 , sizeof( T_5 ) ) ;
V_216 -> V_256 = sizeof( T_6 ) + 8 ;
V_216 -> V_257 = V_151 -> V_109 & 0xffff ;
V_216 -> V_258 = 0 ;
V_216 -> V_259 = V_203 -> V_260 ;
{
V_216 -> V_261 = 1 ;
}
V_216 -> V_262 = 0x0 ;
if ( V_203 -> V_263 ) {
switch ( V_7 -> V_12 -> V_264 )
{
case V_265 :
case V_266 :
V_216 -> V_262 = 0x1 ;
V_216 -> V_261 = 0 ;
break;
case V_267 :
V_216 -> V_262 = 0x2 ;
V_216 -> V_261 = 0 ;
break;
case V_268 :
V_216 -> V_262 = 0x3 ;
V_216 -> V_261 = 0 ;
break;
case V_269 :
V_216 -> V_262 = 0x0 ;
V_216 -> V_261 = 1 ;
break;
}
}
V_216 -> V_270 = F_112 ( V_203 -> V_111 ) ;
V_216 -> V_271 = sizeof( T_6 ) ;
V_216 -> V_272 = V_203 -> V_273 ;
V_216 -> V_274 = V_203 -> V_275 ;
V_216 -> V_276 = 1 ;
F_92 ( V_215 , V_211 ) ;
memcpy ( F_92 ( V_215 , V_151 -> V_109 ) , V_151 -> V_38 , V_151 -> V_109 ) ;
}
for( V_1 = 0 ; V_1 < V_213 -> V_219 ; V_1 ++ ) {
F_113 ( V_213 -> V_218 [ V_1 ] ) ;
}
return V_215 ;
}
T_1 F_114 ( struct V_35 * V_36 , struct V_150 * V_151 ,
struct V_212 * V_213 )
{
struct V_10 * V_11 = F_108 ( V_36 ) ;
T_7 V_277 = V_11 -> V_277 ;
T_3 V_278 = V_277 -> V_279 ;
T_4 * V_203 = ( T_4 * ) ( V_151 -> V_159 + V_204 ) ;
T_1 V_280 = V_203 -> V_111 ;
do {
V_213 -> V_218 [ V_213 -> V_219 ++ ] = V_151 ;
if( V_213 -> V_219 >= V_278 ) {
break;
}
} while( ( V_151 = F_115 ( & V_11 -> V_281 [ V_280 ] ) ) );
F_9 ( V_282 , L_65 , V_213 -> V_219 ) ;
return V_213 -> V_219 ;
}
static void F_116 ( struct V_148 * V_283 )
{
struct V_150 * V_151 = (struct V_150 * ) V_283 -> V_193 ;
struct V_35 * V_36 = NULL ;
struct V_6 * V_7 = NULL ;
T_4 * V_203 = ( T_4 * ) ( V_151 -> V_159 + V_204 ) ;
T_1 V_111 = V_203 -> V_111 ;
memcpy ( & V_36 , (struct V_35 * ) ( V_151 -> V_159 ) , sizeof( struct V_35 * ) ) ;
V_7 = F_17 ( V_36 ) ;
if( V_203 -> V_111 != V_205 ) {
if( V_283 -> V_44 == 0 ) {
V_36 -> V_284 = V_285 ;
V_7 -> V_64 . V_286 ++ ;
V_7 -> V_12 -> V_287 . V_288 ++ ;
V_7 -> V_64 . V_289 += ( V_151 -> V_109 - V_7 -> V_12 -> V_208 ) ;
} else {
V_7 -> V_12 -> V_64 . V_290 ++ ;
}
}
if( V_151 != NULL ) {
F_113 ( V_151 ) ;
F_90 ( V_283 ) ;
F_117 ( & V_7 -> V_79 [ V_111 ] ) ;
}
{
if( V_111 != V_291 ) {
if( ( F_68 ( & V_7 -> V_12 -> V_292 [ V_111 ] ) != 0 ) &&\
( ! ( V_7 -> V_12 -> V_293 ) ) ) {
if( NULL != ( V_151 = F_115 ( & ( V_7 -> V_12 -> V_292 [ V_111 ] ) ) ) )
V_7 -> V_12 -> V_294 ( V_151 , V_36 ) ;
return;
}
#ifdef F_118
else if ( ( F_68 ( & V_7 -> V_12 -> V_281 [ V_111 ] ) != 0 ) &&\
( ! ( V_7 -> V_12 -> V_293 ) ) ) {
V_151 = F_115 ( & V_7 -> V_12 -> V_281 [ V_111 ] ) ;
if( ! F_54 ( V_36 , V_111 ) ) {
F_119 ( & ( V_7 -> V_12 -> V_281 [ V_111 ] ) , V_151 ) ;
return;
}
{
{
struct V_212 V_295 ;
memset ( & V_295 , 0 , sizeof( struct V_212 ) ) ;
if( F_114 ( V_36 , V_151 , & V_295 ) > 1 ) {
V_151 = F_107 ( V_36 , & V_295 ) ;
}
}
V_7 -> V_12 -> V_294 ( V_151 , V_36 ) ;
}
}
#endif
}
}
}
void F_120 ( struct V_35 * V_36 )
{
T_1 V_124 , V_296 , V_297 ;
struct V_6 * V_7 = F_17 ( V_36 ) ;
V_124 = F_25 ( V_36 , V_125 ) ;
V_296 = V_124 & V_126 ;
V_297 = V_124 & ~ V_126 ;
if( V_298 == V_7 -> V_299 ) {
F_84 ( V_7 -> V_300 [ V_155 ] ) ;
}
if ( ( V_296 == ( V_134 << V_132 ) ||
( V_296 == ( V_136 << V_132 ) ) ) ) {
F_23 ( V_36 , V_125 , V_297 | V_137 ) ;
F_23 ( V_36 , V_125 , V_124 ) ;
}
}
void F_121 ( struct V_35 * V_36 , T_3 * V_301 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
struct V_56 * V_302 ;
T_1 V_1 = 0 , V_303 = 0 ;
V_302 = & V_7 -> V_12 -> V_304 ;
for ( V_1 = 0 ; V_1 < V_302 -> V_305 ; V_1 ++ )
{
V_303 = V_302 -> V_306 [ V_1 ] & 0x7f ;
switch( V_303 )
{
case V_307 : * V_301 |= V_308 ; break;
case V_309 : * V_301 |= V_310 ; break;
case V_311 : * V_301 |= V_312 ; break;
case V_313 : * V_301 |= V_314 ; break;
case V_315 : * V_301 |= V_316 ; break;
case V_317 : * V_301 |= V_318 ; break;
case V_319 : * V_301 |= V_320 ; break;
case V_321 : * V_301 |= V_322 ; break;
case V_323 : * V_301 |= V_324 ; break;
case V_325 : * V_301 |= V_326 ; break;
case V_327 : * V_301 |= V_328 ; break;
case V_329 : * V_301 |= V_330 ; break;
}
}
for ( V_1 = 0 ; V_1 < V_302 -> V_331 ; V_1 ++ )
{
V_303 = V_302 -> V_332 [ V_1 ] & 0x7f ;
switch( V_303 )
{
case V_307 : * V_301 |= V_308 ; break;
case V_309 : * V_301 |= V_310 ; break;
case V_311 : * V_301 |= V_312 ; break;
case V_313 : * V_301 |= V_314 ; break;
case V_315 : * V_301 |= V_316 ; break;
case V_317 : * V_301 |= V_318 ; break;
case V_319 : * V_301 |= V_320 ; break;
case V_321 : * V_301 |= V_322 ; break;
case V_323 : * V_301 |= V_324 ; break;
case V_325 : * V_301 |= V_326 ; break;
case V_327 : * V_301 |= V_328 ; break;
case V_329 : * V_301 |= V_330 ; break;
}
}
}
void F_122 ( struct V_35 * V_36 , T_3 V_333 )
{
T_2 V_334 = 0 ;
struct V_6 * V_7 = F_17 ( V_36 ) ;
struct V_56 * V_302 = & V_7 -> V_12 -> V_304 ;
V_7 -> V_335 = V_333 & V_336 ;
V_334 = V_7 -> V_303 ;
if ( V_7 -> V_335 )
V_334 |= V_337 ;
F_13 ( V_36 , V_338 , V_334 ) ;
if ( V_302 -> V_117 & ( V_339 | V_340 ) )
{
T_1 V_341 = 0 ;
if ( ( V_333 & V_342 ) && ( ! V_7 -> V_12 -> V_277 -> V_343 ) )
{
V_341 = V_344 ;
}
else
V_341 = V_345 ;
V_7 -> V_341 = V_341 ;
F_23 ( V_36 , V_346 , V_341 ) ;
}
}
void F_123 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
struct V_56 * V_302 ;
T_3 V_347 = 0 , V_348 = 6 , V_349 = 0xf ;
T_3 V_301 = 0 ;
V_302 = & V_7 -> V_12 -> V_304 ;
F_121 ( V_36 , & V_301 ) ;
V_7 -> V_303 = V_301 &= 0x15f ;
F_13 ( V_36 , V_350 , ( ( T_2 * ) V_302 -> V_351 ) [ 0 ] ) ;
F_24 ( V_36 , V_350 + 4 , ( ( T_3 * ) V_302 -> V_351 ) [ 2 ] ) ;
F_61 ( V_36 ) ;
if ( V_7 -> V_12 -> V_129 == V_133 )
{
F_24 ( V_36 , V_352 , 2 ) ;
F_24 ( V_36 , V_353 , 1023 ) ;
F_24 ( V_36 , V_354 , V_302 -> V_355 ) ;
F_24 ( V_36 , V_356 , 1 ) ;
F_23 ( V_36 , V_357 , 100 ) ;
V_347 |= ( V_348 << V_358 ) ;
V_347 |= V_349 << V_359 ;
F_24 ( V_36 , V_360 , V_347 ) ;
}
}
void F_124 ( struct V_35 * V_36 , T_3 V_361 )
{
}
inline T_1 F_125 ( T_3 V_191 )
{
if( ( ( V_191 <= 110 ) && ( V_191 != 60 ) && ( V_191 != 90 ) ) || ( V_191 == 220 ) )
return 1 ;
else return 0 ;
}
T_3 F_126 (
T_3 V_362 ,
T_3 V_363 ,
T_1 V_364 ,
T_1 V_365
)
{
T_3 V_366 ;
T_3 V_367 ;
T_3 V_368 ;
if( F_125 ( V_363 ) )
{
if( V_364 || ! V_365 || V_363 == 10 )
{
V_366 = ( T_3 ) ( 144 + 48 + ( V_362 * 8 / ( V_363 / 10 ) ) ) ;
}
else
{
V_366 = ( T_3 ) ( 72 + 24 + ( V_362 * 8 / ( V_363 / 10 ) ) ) ;
}
if( ( V_362 * 8 % ( V_363 / 10 ) ) != 0 )
V_366 ++ ;
} else {
V_367 = F_127 ( V_363 ) ;
V_368 = ( 16 + 8 * V_362 + 6 ) / V_367
+ ( ( ( 16 + 8 * V_362 + 6 ) % V_367 ) ? 1 : 0 ) ;
V_366 = ( T_3 ) ( 16 + 4 + 4 * V_368 + 6 ) ;
}
return V_366 ;
}
T_3 F_127 ( T_3 V_363 )
{
T_3 V_367 = 24 ;
switch( V_363 )
{
case 60 :
V_367 = 24 ;
break;
case 90 :
V_367 = 36 ;
break;
case 120 :
V_367 = 48 ;
break;
case 180 :
V_367 = 72 ;
break;
case 240 :
V_367 = 96 ;
break;
case 360 :
V_367 = 144 ;
break;
case 480 :
V_367 = 192 ;
break;
case 540 :
V_367 = 216 ;
break;
default:
break;
}
return V_367 ;
}
void F_128 ( struct V_148 * V_369 , struct V_370 * V_371 )
{
F_90 ( V_369 ) ;
}
unsigned int F_129 ( struct V_6 * V_7 , unsigned int V_372 ) {
if( V_372 >= 9 )
{
F_9 ( V_27 , L_66 , V_28 ) ;
return 0x04 ;
}
return V_7 -> V_373 [ V_372 ] ;
}
short F_105 ( struct V_35 * V_36 , struct V_150 * V_151 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
int V_44 ;
struct V_148 * V_283 ;
unsigned int V_374 ;
T_8 * V_375 = ( T_8 * ) V_151 -> V_38 ;
T_4 * V_203 = ( T_4 * ) ( V_151 -> V_159 + V_204 ) ;
T_1 V_111 = V_203 -> V_111 ;
F_130 ( & V_7 -> V_79 [ V_111 ] ) ;
V_283 = F_70 ( 0 , V_200 ) ;
if( ! V_283 ) {
F_131 ( V_151 ) ;
return - V_376 ;
}
memset ( V_375 , 0 , V_209 ) ;
V_375 -> V_377 = 1 ;
V_375 -> V_378 = 1 ;
V_375 -> V_379 = V_203 -> V_380 ;
V_375 -> V_381 = V_203 -> V_382 ;
V_375 -> V_276 = 1 ;
V_375 -> V_383 = V_203 -> V_384 ;
#ifndef F_132
V_374 = F_129 ( V_7 , V_111 ) ;
#else
V_374 = 0x04 ;
#endif
#ifdef F_133
int V_1 ;
F_20 ( L_67 , V_191 ) ;
for ( V_1 = 0 ; V_1 < 8 ; V_1 ++ )
F_20 ( L_68 , V_385 [ V_1 ] ) ;
F_20 ( L_53 ) ;
#endif
F_72 ( V_283 , V_7 -> V_46 , F_134 ( V_7 -> V_46 , V_374 ) , \
V_151 -> V_38 , V_151 -> V_109 , F_116 , V_151 ) ;
V_44 = F_76 ( V_283 , V_200 ) ;
if ( ! V_44 ) {
return 0 ;
} else{
F_135 ( L_69 ,
V_44 ) ;
return - 1 ;
}
}
T_1 F_112 ( T_1 V_280 )
{
T_1 V_270 = 0x0 ;
switch( V_280 ) {
case V_386 :
V_270 = V_387 ;
break;
case V_388 :
V_270 = V_389 ;
break;
case V_390 :
V_270 = V_391 ;
break;
case V_392 :
V_270 = V_393 ;
break;
case V_394 :
V_270 = V_395 ;
break;
case V_291 :
V_270 = V_396 ;
break;
case V_205 :
V_270 = V_397 ;
break;
case V_398 :
V_270 = V_399 ;
break;
default:
F_9 ( V_27 , L_70 , V_280 ) ;
break;
}
return V_270 ;
}
T_1 F_110 ( T_1 V_191 )
{
T_1 V_202 = V_400 ;
switch( V_191 ) {
case V_307 : V_202 = V_400 ; break;
case V_309 : V_202 = V_401 ; break;
case V_311 : V_202 = V_402 ; break;
case V_313 : V_202 = V_403 ; break;
case V_315 : V_202 = V_404 ; break;
case V_317 : V_202 = V_405 ; break;
case V_319 : V_202 = V_406 ; break;
case V_321 : V_202 = V_407 ; break;
case V_323 : V_202 = V_408 ; break;
case V_325 : V_202 = V_409 ; break;
case V_327 : V_202 = V_410 ; break;
case V_329 : V_202 = V_411 ; break;
case V_412 : V_202 = V_413 ; break;
case V_414 : V_202 = V_415 ; break;
case V_416 : V_202 = V_417 ; break;
case V_418 : V_202 = V_419 ; break;
case V_420 : V_202 = V_421 ; break;
case V_422 : V_202 = V_423 ; break;
case V_424 : V_202 = V_425 ; break;
case V_426 : V_202 = V_427 ; break;
case V_428 : V_202 = V_429 ; break;
case V_430 : V_202 = V_431 ; break;
case V_432 : V_202 = V_433 ; break;
case V_434 : V_202 = V_435 ; break;
case V_436 : V_202 = V_437 ; break;
case V_438 : V_202 = V_439 ; break;
case V_440 : V_202 = V_441 ; break;
case V_442 : V_202 = V_443 ; break;
case ( 0x80 | 0x20 ) : V_202 = V_444 ; break;
default: break;
}
return V_202 ;
}
T_1 F_111 ( T_1 V_224 , T_1 V_226 , T_4 * V_203 )
{
T_1 V_445 ;
V_445 = ( V_224 == 1 ) ? ( ( V_203 -> V_446 ) ? 1 : 0 ) : ( ( V_203 -> V_447 ) ? 1 : 0 ) ;
if( V_224 == 1 && V_226 != V_443 )
V_445 = 0 ;
return V_445 ;
}
static void F_136 ( struct V_148 * V_283 )
{
return;
}
short F_102 ( struct V_35 * V_36 , struct V_150 * V_151 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
T_4 * V_203 = ( T_4 * ) ( V_151 -> V_159 + V_204 ) ;
T_9 * V_448 = ( T_9 * ) V_151 -> V_38 ;
T_6 * V_217 = ( T_6 * ) ( V_151 -> V_38 + V_209 ) ;
struct V_45 * V_46 = V_7 -> V_46 ;
int V_449 ;
int V_44 ;
struct V_148 * V_283 = NULL , * V_450 = NULL ;
unsigned int V_374 ;
V_449 = F_37 ( & V_7 -> V_79 [ V_203 -> V_111 ] ) ;
if( V_449 > V_113 ) {
F_20 ( L_71 ) ;
F_113 ( V_151 ) ;
return - 1 ;
}
V_283 = F_70 ( 0 , V_200 ) ;
if( ! V_283 ) {
F_113 ( V_151 ) ;
return - V_376 ;
}
memset ( V_217 , 0 , sizeof( T_6 ) ) ;
V_217 -> V_224 = ( V_203 -> V_225 & 0x80 ) ? 1 : 0 ;
V_217 -> V_226 = F_110 ( V_203 -> V_225 ) ;
V_217 -> V_227 = V_203 -> V_207 ;
V_217 -> Short = F_111 ( V_217 -> V_224 , V_217 -> V_226 , V_203 ) ;
if( V_203 -> V_228 ) {
V_217 -> V_229 = 1 ;
V_217 -> V_230 = V_203 -> V_231 ;
V_217 -> V_232 = V_203 -> V_233 & 0x07 ;
} else {
V_217 -> V_229 = 0 ;
V_217 -> V_230 = 0 ;
V_217 -> V_232 = 0 ;
}
V_217 -> V_234 = ( V_203 -> V_235 ) ? 1 : 0 ;
V_217 -> V_236 = ( V_203 -> V_237 ) ? 1 : 0 ;
V_217 -> V_238 = ( V_203 -> V_239 ) ? 1 : 0 ;
V_217 -> V_240 = ( V_203 -> V_241 & 0x80 ) ? 1 : 0 ;
V_217 -> V_242 = F_110 ( ( T_1 ) V_203 -> V_241 ) ;
V_217 -> V_243 = ( V_217 -> V_240 == 0 ) ? ( V_203 -> V_244 ) : 0 ;
V_217 -> V_245 = ( V_217 -> V_240 == 1 ) ? ( ( V_203 -> V_246 ) ? 1 : 0 ) : 0 ;
V_217 -> V_247 = ( V_217 -> V_240 == 0 ) ? ( V_203 -> V_248 ? 1 : 0 ) :\
( V_203 -> V_249 ? 1 : 0 ) ;
if( V_7 -> V_250 == V_251 )
{
if( V_203 -> V_252 ) {
V_217 -> V_253 = 1 ;
V_217 -> V_254 = 0 ;
} else {
V_217 -> V_253 = 0 ;
V_217 -> V_254 = V_7 -> V_255 ;
}
} else {
V_217 -> V_253 = 0 ;
V_217 -> V_254 = 0 ;
}
#ifdef F_118
if ( V_203 -> V_220 )
{
V_217 -> V_451 = ( V_203 -> V_222 & 0x1f ) << 1 ;
}
#endif
memset ( V_448 , 0 , sizeof( T_9 ) ) ;
V_448 -> V_383 = 0 ;
V_448 -> V_379 = 1 ;
V_448 -> V_256 = sizeof( T_6 ) + 8 ;
#ifdef F_118
if ( V_203 -> V_220 ) {
V_448 -> V_257 = V_203 -> V_221 ;
} else
#endif
{
V_448 -> V_257 = ( V_151 -> V_109 - V_452 ) & 0xffff ;
}
V_448 -> V_258 = 0 ;
V_448 -> V_259 = V_203 -> V_260 ;
{
V_448 -> V_261 = 1 ;
}
V_448 -> V_262 = 0x0 ;
if ( V_203 -> V_263 )
{
switch ( V_7 -> V_12 -> V_264 )
{
case V_265 :
case V_266 :
V_448 -> V_262 = 0x1 ;
V_448 -> V_261 = 0 ;
break;
case V_267 :
V_448 -> V_262 = 0x2 ;
V_448 -> V_261 = 0 ;
break;
case V_268 :
V_448 -> V_262 = 0x3 ;
V_448 -> V_261 = 0 ;
break;
case V_269 :
V_448 -> V_262 = 0x0 ;
V_448 -> V_261 = 1 ;
break;
}
}
V_448 -> V_270 = F_112 ( V_203 -> V_111 ) ;
V_448 -> V_271 = sizeof( T_6 ) ;
V_448 -> V_272 = V_203 -> V_273 ;
V_448 -> V_274 = V_203 -> V_275 ;
V_448 -> V_377 = 1 ;
V_448 -> V_378 = 1 ;
V_448 -> V_276 = 1 ;
#ifdef F_118
if ( V_203 -> V_220 ) {
V_448 -> V_381 = V_203 -> V_221 + sizeof( T_6 ) ;
} else
#endif
{
V_448 -> V_381 = ( T_2 ) ( V_151 -> V_109 - V_209 ) ;
}
#ifndef F_132
V_374 = F_129 ( V_7 , V_203 -> V_111 ) ;
#else
V_374 = 0x5 ;
#endif
F_72 ( V_283 , V_46 ,
F_134 ( V_46 , V_374 ) , V_151 -> V_38 ,
V_151 -> V_109 , F_116 , V_151 ) ;
V_44 = F_76 ( V_283 , V_200 ) ;
if ( ! V_44 ) {
bool V_453 = false ;
T_1 V_454 = 0 ;
if( V_46 -> V_455 == V_456 )
{
if ( V_151 -> V_109 > 0 && V_151 -> V_109 % 512 == 0 )
V_453 = true ;
}
else
{
if ( V_151 -> V_109 > 0 && V_151 -> V_109 % 64 == 0 )
V_453 = true ;
}
if ( V_453 )
{
V_450 = F_70 ( 0 , V_200 ) ;
if( ! V_450 ) {
F_9 ( V_27 , L_72 ) ;
return - V_376 ;
}
F_72 ( V_450 , V_46 ,
F_134 ( V_46 , V_374 ) , & V_454 ,
0 , F_136 , V_36 ) ;
V_44 = F_76 ( V_450 , V_200 ) ;
if ( V_44 ) {
F_9 ( V_27 , L_73 , F_37 ( & V_7 -> V_79 [ V_203 -> V_111 ] ) , V_44 ) ;
return - 1 ;
}
}
V_36 -> V_284 = V_285 ;
F_130 ( & V_7 -> V_79 [ V_203 -> V_111 ] ) ;
return 0 ;
} else {
F_9 ( V_27 , L_74 , F_37 ( & V_7 -> V_79 [ V_203 -> V_111 ] ) ,
V_44 ) ;
return - 1 ;
}
}
short F_137 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
V_7 -> V_300 = F_138 ( sizeof( struct V_148 * ) * ( V_155 + 1 ) ,
V_157 ) ;
if ( V_7 -> V_300 == NULL )
return - V_376 ;
#ifndef F_139
for( V_1 = 0 ; V_1 < ( V_155 + 1 ) ; V_1 ++ ) {
V_7 -> V_300 [ V_1 ] = F_70 ( 0 , V_157 ) ;
V_7 -> V_300 [ V_1 ] -> V_199 = F_138 ( V_156 , V_157 ) ;
V_7 -> V_300 [ V_1 ] -> V_457 = V_156 ;
}
#endif
#ifdef F_140
{
long V_458 = 0 ;
void * V_459 , * V_460 ;
V_7 -> V_300 [ 16 ] = F_70 ( 0 , V_157 ) ;
V_7 -> V_459 = F_138 ( 16 , V_157 ) ;
V_459 = V_7 -> V_459 ;
V_458 = ( ( long ) V_459 ) & 3 ;
if ( V_458 ) {
V_460 = V_459 + 4 - V_458 ;
V_7 -> V_300 [ 16 ] -> V_457 = 16 - 4 + V_458 ;
} else {
V_460 = V_459 ;
V_7 -> V_300 [ 16 ] -> V_457 = 16 ;
}
V_7 -> V_300 [ 16 ] -> V_199 = V_460 ;
}
#endif
memset ( V_7 -> V_300 , 0 , sizeof( struct V_148 * ) * V_155 ) ;
V_7 -> V_461 = F_141 ( V_155 , sizeof( struct V_150 * ) ,
V_157 ) ;
if ( ! V_7 -> V_461 ) {
F_142 ( V_7 -> V_300 ) ;
V_7 -> V_461 = NULL ;
V_7 -> V_300 = NULL ;
F_135 ( L_75 ) ;
return - V_376 ;
}
F_20 ( L_76 ) ;
return 0 ;
}
void F_143 ( struct V_35 * V_36 )
{
int V_1 ;
struct V_6 * V_7 = F_17 ( V_36 ) ;
if( V_7 -> V_300 ) {
for( V_1 = 0 ; V_1 < ( V_155 + 1 ) ; V_1 ++ ) {
F_84 ( V_7 -> V_300 [ V_1 ] ) ;
F_90 ( V_7 -> V_300 [ V_1 ] ) ;
}
F_142 ( V_7 -> V_300 ) ;
V_7 -> V_300 = NULL ;
}
F_142 ( V_7 -> V_459 ) ;
V_7 -> V_459 = NULL ;
if ( V_7 -> V_461 ) {
F_142 ( V_7 -> V_461 ) ;
V_7 -> V_461 = 0 ;
}
}
void F_143 ( struct V_35 * V_36 )
{
int V_1 ;
struct V_6 * V_7 = F_17 ( V_36 ) ;
#ifndef F_139
if( V_7 -> V_300 ) {
for( V_1 = 0 ; V_1 < ( V_155 + 1 ) ; V_1 ++ ) {
F_84 ( V_7 -> V_300 [ V_1 ] ) ;
F_142 ( V_7 -> V_300 [ V_1 ] -> V_199 ) ;
F_90 ( V_7 -> V_300 [ V_1 ] ) ;
}
F_142 ( V_7 -> V_300 ) ;
V_7 -> V_300 = NULL ;
}
#else
F_142 ( V_7 -> V_300 ) ;
V_7 -> V_300 = NULL ;
F_142 ( V_7 -> V_459 ) ;
V_7 -> V_459 = NULL ;
if ( V_7 -> V_461 ) {
F_142 ( V_7 -> V_461 ) ;
V_7 -> V_461 = 0 ;
}
#endif
}
void F_144 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
if ( V_11 -> V_127 == V_128 )
{
F_123 ( V_36 ) ;
F_145 ( V_36 ) ;
if ( ( V_265 == V_11 -> V_264 ) || ( V_266 == V_11 -> V_264 ) )
F_146 ( V_36 ) ;
}
if ( V_11 -> V_129 == V_130 || V_11 -> V_129 == V_133 )
{
T_2 V_462 = 0 ;
V_462 = F_15 ( V_36 , V_162 ) ;
if ( V_7 -> V_12 -> V_127 == V_128 )
V_7 -> V_463 = V_462 |= V_173 ;
else
V_7 -> V_463 = V_462 &= ~ V_173 ;
F_13 ( V_36 , V_162 , V_462 ) ;
}
}
void F_147 ( struct V_464 * V_465 )
{
struct V_6 * V_7 = F_148 ( V_465 , struct V_6 , V_466 . V_465 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_56 * V_302 = & V_11 -> V_304 ;
if ( V_11 -> V_277 -> V_467 )
F_149 ( V_11 , V_302 ) ;
V_11 -> V_277 -> V_343 = V_302 -> V_468 . V_469 ;
F_122 ( V_36 , V_302 -> V_470 ) ;
}
void F_150 ( struct V_464 * V_465 )
{
struct V_6 * V_7 = F_148 ( V_465 , struct V_6 , V_471 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
struct V_472 * V_473 = & V_7 -> V_12 -> V_304 . V_474 . V_475 ;
T_1 V_117 = V_7 -> V_12 -> V_304 . V_117 ;
T_1 V_476 ;
T_2 V_477 ;
int V_1 ;
if ( V_7 == NULL )
return;
F_151 ( & V_7 -> V_478 ) ;
if( V_7 -> V_12 -> V_127 != V_128 )
goto V_479;
F_9 ( V_480 , L_77 ) ;
for( V_1 = 0 ; V_1 < V_481 ; V_1 ++ ) {
V_476 = V_473 -> V_482 [ V_1 ] * ( ( V_117 & ( V_339 | V_340 ) ) ? 9 : 20 ) + V_483 ;
V_477 = ( ( ( ( T_2 ) ( V_473 -> V_484 [ V_1 ] ) ) << V_485 ) |
( ( ( T_2 ) ( V_473 -> V_486 [ V_1 ] ) ) << V_487 ) |
( ( ( T_2 ) ( V_473 -> V_488 [ V_1 ] ) ) << V_489 ) |
( ( T_2 ) V_476 << V_490 ) ) ;
F_13 ( V_36 , V_491 [ V_1 ] , V_477 ) ;
}
V_479:
F_152 ( & V_7 -> V_478 ) ;
}
static int F_153 ( struct V_6 * V_7 ,
int V_492 ,
struct V_56 * V_493 )
{
int V_202 = 0 ;
T_2 V_494 = sizeof( struct V_472 ) ;
if( V_7 -> V_12 -> V_127 != V_128 )
return V_202 ;
if ( ( V_7 -> V_12 -> V_129 != V_130 ) )
return V_202 ;
if ( V_493 -> V_168 & V_495 ) {
if ( V_492 &&
( V_493 -> V_168 & V_496 ) )
V_493 -> V_474 . V_497 = V_493 -> V_474 . V_498 ;
if ( ( V_493 -> V_474 . V_497 == 1 ) && ( V_492 == 1 ) &&
( V_493 -> V_168 & V_496 ) &&
( V_493 -> V_474 . V_499 !=
V_493 -> V_474 . V_500 ) ) {
V_493 -> V_474 . V_499 =
V_493 -> V_474 . V_500 ;
F_154 ( V_7 -> V_501 , & V_7 -> V_471 ) ;
F_9 ( V_480 , L_78
L_79 ) ;
}
} else {
memcpy ( & V_7 -> V_12 -> V_304 . V_474 . V_475 ,\
& V_502 , V_494 ) ;
if ( ( V_493 -> V_474 . V_497 == 1 ) && ( V_492 == 1 ) ) {
F_154 ( V_7 -> V_501 , & V_7 -> V_471 ) ;
F_9 ( V_480 , L_80 ) ;
}
V_493 -> V_474 . V_497 = 0 ;
V_493 -> V_474 . V_498 = 0 ;
}
return 0 ;
}
static int F_155 ( struct V_35 * V_36 ,
struct V_503 * V_504 ,
struct V_56 * V_493 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
F_153 ( V_7 , 1 , V_493 ) ;
F_156 ( V_7 -> V_501 , & V_7 -> V_466 , 0 ) ;
return 0 ;
}
static int F_157 ( struct V_6 * V_7 ,
struct V_56 * V_493 )
{
int V_202 = 0 ;
unsigned long V_168 ;
T_2 V_494 = sizeof( struct V_472 ) ;
int V_505 = 0 ;
if ( ( V_7 == NULL ) || ( V_493 == NULL ) )
return V_202 ;
if( V_7 -> V_12 -> V_127 != V_128 )
return V_202 ;
if ( ( V_7 -> V_12 -> V_129 != V_130 ) )
return V_202 ;
F_100 ( & V_7 -> V_12 -> V_506 , V_168 ) ;
if( V_493 -> V_168 & V_496 ) {
memcpy ( & V_7 -> V_12 -> V_304 . V_474 . V_475 ,\
& V_493 -> V_474 . V_475 ,\
sizeof( struct V_472 ) ) ;
V_7 -> V_12 -> V_304 . V_474 . V_497 = 1 ;
{
V_505 = 1 ;
V_7 -> V_12 -> V_304 . V_474 . V_499 = \
V_7 -> V_12 -> V_304 . V_474 . V_500 ;
V_7 -> V_12 -> V_304 . V_474 . V_500 = \
V_493 -> V_474 . V_500 ;
}
} else {
memcpy ( & V_7 -> V_12 -> V_304 . V_474 . V_475 ,\
& V_502 , V_494 ) ;
V_7 -> V_12 -> V_304 . V_474 . V_497 = 0 ;
V_7 -> V_12 -> V_304 . V_474 . V_498 = 0 ;
V_505 = 1 ;
}
F_103 ( & V_7 -> V_12 -> V_506 , V_168 ) ;
F_9 ( V_480 , L_81 , V_28 , V_493 -> V_168 , V_7 -> V_12 -> V_304 . V_474 . V_497 ) ;
if ( V_505 == 1 )
F_154 ( V_7 -> V_501 , & V_7 -> V_471 ) ;
return V_202 ;
}
static int F_158 ( struct V_35 * V_36 ,
struct V_507 * V_508 ,
struct V_56 * V_493 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
F_157 ( V_7 , V_493 ) ;
return 0 ;
}
void F_145 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
T_1 * V_509 = V_11 -> V_510 ;
T_2 V_511 = 0 ;
T_1 V_512 = 0 ;
F_121 ( V_36 , ( T_3 * ) ( & V_511 ) ) ;
V_511 |= ( * ( T_3 * ) ( V_509 ) ) << 12 ;
switch ( V_11 -> V_117 )
{
case V_513 :
V_511 &= 0x00000FF0 ;
break;
case V_514 :
V_511 &= 0x0000000F ;
break;
case V_339 :
V_511 &= 0x00000FF7 ;
break;
case V_340 :
case V_515 :
if ( V_11 -> V_277 -> V_516 == 0 )
V_511 &= 0x0007F007 ;
else{
if ( V_7 -> V_517 == V_518 )
V_511 &= 0x000FF007 ;
else
V_511 &= 0x0F81F007 ;
}
break;
default:
break;
}
V_511 &= 0x0FFFFFFF ;
if( V_11 -> V_277 -> V_519 && V_11 -> V_277 -> V_520 ) {
V_511 |= 0x80000000 ;
} else if( ! V_11 -> V_277 -> V_519 && V_11 -> V_277 -> V_521 ) {
V_511 |= 0x80000000 ;
}
F_13 ( V_36 , V_522 + V_512 * 4 , V_511 ) ;
F_23 ( V_36 , V_523 , 1 ) ;
}
bool F_159 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_56 * V_493 = & V_11 -> V_304 ;
int V_59 = V_11 -> V_59 ;
struct V_524 * V_525 ;
int V_526 ;
V_525 = V_11 -> V_525 [ V_11 -> V_527 ] ;
V_526 = ( V_493 -> V_470 & V_528 ) || ( V_11 -> V_529 && V_525 && V_525 -> V_530 && ( 0 == strcmp ( V_525 -> V_530 -> V_103 , L_82 ) ) ) ;
if( V_526 && ( V_59 == 0 ) ) {
return false ;
} else if( ( V_59 != 0 ) ) {
if ( ( ( V_11 -> V_531 [ 0 ] == 0xdd ) && ( ! memcmp ( & ( V_11 -> V_531 [ 14 ] ) , V_532 , 4 ) ) ) || ( ( V_11 -> V_531 [ 0 ] == 0x30 ) && ( ! memcmp ( & V_11 -> V_531 [ 10 ] , V_533 , 4 ) ) ) )
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
bool V_534 ;
struct V_6 * V_7 = F_17 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
if( V_11 -> V_535 == true )
V_534 = true ;
else
V_534 = false ;
return V_534 ;
}
void F_161 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
if ( V_11 -> V_117 == V_536 || V_11 -> V_117 == V_537 )
{
memcpy ( V_11 -> V_538 , V_11 -> V_539 , 16 ) ;
}
else
memset ( V_11 -> V_538 , 0 , 16 ) ;
return;
}
T_1 F_162 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
T_1 V_202 = 0 ;
switch( V_7 -> V_24 )
{
case V_25 :
case V_26 :
case V_540 :
V_202 = ( V_536 | V_541 | V_542 ) ;
break;
case V_543 :
V_202 = ( V_544 | V_537 ) ;
break;
default:
V_202 = V_542 ;
break;
}
return V_202 ;
}
void F_163 ( struct V_35 * V_36 , T_1 V_545 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
T_1 V_546 = F_162 ( V_36 ) ;
if ( ( V_545 == V_547 ) || ( ( V_545 & V_546 ) == 0 ) )
{
if( V_546 & V_536 )
{
V_545 = V_536 ;
}
else if( V_546 & V_537 )
{
V_545 = V_537 ;
}
else if( ( V_546 & V_544 ) )
{
V_545 = V_544 ;
}
else if( ( V_546 & V_541 ) )
{
V_545 = V_541 ;
}
else if( ( V_546 & V_542 ) )
{
V_545 = V_542 ;
}
else{
F_9 ( V_27 , L_83 , V_28 , V_546 ) ;
V_545 = V_542 ;
}
}
#ifdef F_164
F_165 ( V_548 , V_549 -> V_550 , & V_548 -> V_551 . V_552 . V_553 ) ;
#endif
V_7 -> V_12 -> V_117 = V_545 ;
if ( ( V_545 == V_536 ) || ( V_545 == V_537 ) )
V_7 -> V_12 -> V_277 -> V_554 = 1 ;
else
V_7 -> V_12 -> V_277 -> V_554 = 0 ;
F_9 ( V_92 , L_84 , V_545 ) ;
F_161 ( V_7 ) ;
}
static void F_166 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
T_1 V_1 ;
V_7 -> V_299 = V_298 ;
V_7 -> V_140 = 1 ;
V_7 -> V_12 -> V_117 = V_547 ;
V_7 -> V_12 -> V_129 = V_130 ;
V_7 -> V_12 -> V_555 = 0 ;
V_7 -> V_556 = V_557 ;
V_7 -> V_558 = V_559 ;
V_7 -> V_12 -> V_560 = V_561 ;
V_7 -> V_12 -> V_191 = 110 ;
V_7 -> V_12 -> V_562 = 1 ;
V_7 -> V_563 = ( V_36 -> V_168 & V_169 ) ? 1 : 0 ;
V_7 -> V_564 = 6 ;
V_7 -> V_565 = 1 ;
V_7 -> V_566 = V_567 ;
V_7 -> V_568 = 0 ;
V_7 -> V_569 = false ;
V_7 -> V_570 = false ;
V_7 -> V_12 -> V_571 = 0 ;
V_7 -> V_12 -> V_304 . V_355 = V_572 ;
V_7 -> V_12 -> V_129 = V_130 ;
V_7 -> V_12 -> V_573 = V_574 |
V_575 | V_576 |
V_577 | V_578 |
V_579 ;
V_7 -> V_12 -> V_580 = 1 ;
V_7 -> V_12 -> V_581 = V_582 | V_583 ;
V_7 -> V_12 -> V_529 = 1 ;
V_7 -> V_12 -> V_584 = 1 ;
V_7 -> V_12 -> V_585 = NULL ;
V_7 -> V_12 -> V_586 = NULL ;
V_7 -> V_12 -> V_294 = F_104 ;
V_7 -> V_12 -> V_587 = F_62 ;
V_7 -> V_12 -> V_588 = F_144 ;
V_7 -> V_12 -> V_589 = F_99 ;
V_7 -> V_12 -> V_590 = F_97 ;
V_7 -> V_12 -> V_591 = F_98 ;
V_7 -> V_12 -> V_592 = 0 ;
V_7 -> V_12 -> V_593 = V_594 ;
V_7 -> V_12 -> F_54 = F_54 ;
V_7 -> V_12 -> V_208 = V_452 ;
V_7 -> V_12 -> V_595 = 1 ;
V_7 -> V_12 -> V_596 = V_597 ;
V_7 -> V_12 -> V_598 = F_158 ;
V_7 -> V_12 -> V_599 = F_155 ;
V_7 -> V_12 -> V_600 = F_159 ;
V_7 -> V_12 -> V_601 = F_160 ;
V_7 -> V_12 -> V_602 = F_163 ;
V_7 -> V_12 -> V_603 = V_604 ;
V_7 -> V_605 = V_606 ;
#ifdef F_164
if( V_607 -> V_608 )
{
V_549 -> V_609 = 7 ;
V_549 -> V_610 = 7 ;
}
#endif
{
V_7 -> V_609 = 0x30 ;
V_7 -> V_610 = 0x30 ;
}
V_7 -> V_611 = 7 ;
V_7 -> V_612 = 0 ;
V_7 -> V_613 =
( V_614 << V_615 ) |
( V_7 -> V_609 << V_616 ) |
( V_7 -> V_610 << V_617 ) |
( false ? V_618 : 0 ) ;
#ifdef F_164
if( V_607 -> V_608 )
V_549 -> V_463 = V_549 -> V_619 |
V_164 | V_165 |
V_620 |
V_166 | V_167 | V_172 |
V_174 | V_177 |
( ( T_2 ) 7 << V_182 ) |
( V_549 -> V_611 << V_621 ) |
( V_549 -> V_611 == 7 ? V_622 : 0 ) ;
else
#endif
V_7 -> V_463 =
V_164 | V_165 |
V_620 |
V_166 | V_167 | V_172 |
( ( T_2 ) 7 << V_182 ) |
( V_7 -> V_611 << V_180 ) |
( V_7 -> V_611 == 7 ? V_183 : 0 ) ;
V_7 -> V_623 = 0 ;
V_7 -> V_624 = F_167 ( sizeof( V_625 ) , V_157 ) ;
F_168 ( & V_7 -> V_154 ) ;
F_168 ( & V_7 -> V_188 ) ;
for( V_1 = 0 ; V_1 < V_626 ; V_1 ++ ) {
F_168 ( & V_7 -> V_12 -> V_292 [ V_1 ] ) ;
}
for( V_1 = 0 ; V_1 < V_626 ; V_1 ++ ) {
F_168 ( & V_7 -> V_12 -> V_627 [ V_1 ] ) ;
}
for( V_1 = 0 ; V_1 < V_626 ; V_1 ++ ) {
F_168 ( & V_7 -> V_12 -> V_281 [ V_1 ] ) ;
}
V_7 -> V_141 = V_628 ;
}
static void F_169 ( struct V_6 * V_7 )
{
F_170 ( & V_7 -> V_206 ) ;
F_170 ( & V_7 -> V_629 ) ;
F_171 ( & V_7 -> V_630 , 1 ) ;
F_171 ( & V_7 -> V_631 , 1 ) ;
F_172 ( & V_7 -> V_478 ) ;
}
static void F_173 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
V_7 -> V_501 = F_174 ( V_632 ) ;
F_175 ( & V_7 -> V_114 , V_633 ) ;
F_176 ( & V_7 -> V_634 , V_635 ) ;
F_176 ( & V_7 -> V_636 , V_637 ) ;
F_176 ( & V_7 -> V_638 , V_639 ) ;
F_176 ( & V_7 -> V_466 , F_147 ) ;
F_176 ( & V_7 -> V_640 , V_641 ) ;
F_175 ( & V_7 -> V_471 , F_150 ) ;
F_177 ( & V_7 -> V_198 ,
( void (*) ( unsigned long ) ) V_642 ,
( unsigned long ) V_7 ) ;
}
static void F_178 ( struct V_35 * V_36 )
{
T_3 V_643 = 0 ;
struct V_6 * V_7 = F_17 ( V_36 ) ;
F_9 ( V_115 , L_85 , V_28 ) ;
V_643 = F_27 ( V_36 , V_119 ) ;
F_9 ( V_115 , L_86 , V_119 , V_643 ) ;
V_7 -> V_644 = ( V_643 & V_645 ) ? V_646 : V_647 ;
F_9 ( V_115 , L_87 , V_28 , V_7 -> V_644 ) ;
}
static inline T_3 F_179 ( T_3 * V_38 )
{
T_3 V_334 = * V_38 ;
* V_38 = ( V_334 >> 8 ) | ( V_334 << 8 ) ;
return * V_38 ;
}
static void F_180 ( struct V_35 * V_36 )
{
T_3 V_648 = 0 ;
T_1 V_649 [ 6 ] = { 0x00 , 0xe0 , 0x4c , 0x00 , 0x00 , 0x02 } ;
T_1 V_650 = false ;
struct V_6 * V_7 = F_17 ( V_36 ) ;
T_3 V_651 = 0 ;
F_9 ( V_115 , L_85 , V_28 ) ;
V_648 = F_58 ( V_36 , 0 ) ;
F_9 ( V_115 , L_88 , V_648 ) ;
if ( V_648 != V_652 )
{
F_9 ( V_27 , L_89 , V_648 , V_652 ) ;
}
else
V_650 = true ;
if ( V_650 )
{
V_651 = F_58 ( V_36 , ( V_653 >> 1 ) ) ;
V_7 -> V_654 = F_179 ( & V_651 ) ;
V_7 -> V_655 = F_58 ( V_36 , ( V_656 >> 1 ) ) ;
V_651 = F_58 ( V_36 , ( V_657 >> 1 ) ) ;
V_7 -> V_658 = ( ( V_651 & 0xff00 ) >> 8 ) ;
V_7 -> V_659 = true ;
V_7 -> V_660 = F_58 ( V_36 , ( V_661 >> 1 ) ) >> 8 ;
}
else
{
V_7 -> V_654 = 0 ;
V_7 -> V_655 = 0 ;
V_7 -> V_662 = V_663 ;
V_7 -> V_658 = 0 ;
V_7 -> V_660 = 0 ;
}
F_9 ( V_115 , L_90 , V_7 -> V_654 , V_7 -> V_655 , V_7 -> V_660 , V_7 -> V_658 ) ;
V_7 -> V_29 = V_7 -> V_658 ;
if ( V_650 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < 6 ; V_1 += 2 )
{
T_3 V_334 = 0 ;
V_334 = F_58 ( V_36 , ( T_3 ) ( ( V_664 + V_1 ) >> 1 ) ) ;
* ( T_3 * ) ( & V_36 -> V_665 [ V_1 ] ) = V_334 ;
}
}
else
{
memcpy ( V_36 -> V_665 , V_649 , 6 ) ;
}
F_9 ( V_115 , L_91 , V_36 -> V_665 ) ;
V_7 -> V_517 = V_666 ;
V_7 -> V_24 = V_26 ;
if ( V_7 -> V_662 == ( T_1 ) V_667 )
{
if ( V_650 )
V_7 -> V_668 = ( F_58 ( V_36 , ( V_669 >> 1 ) ) & 0xff00 ) >> 8 ;
else
V_7 -> V_668 = V_670 ;
F_9 ( V_115 , L_92 , V_7 -> V_668 ) ;
if ( V_650 )
V_7 -> V_671 = ( T_1 ) ( F_58 ( V_36 , ( V_672 >> 1 ) ) & 0x00ff ) ;
else
V_7 -> V_671 = V_673 ;
F_9 ( V_115 , L_93 , V_7 -> V_671 ) ;
V_7 -> V_674 = V_7 -> V_671 * 100 ;
if ( V_650 )
V_7 -> V_675 = ( F_58 ( V_36 , ( V_676 >> 1 ) ) & 0x0f00 ) >> 8 ;
else
V_7 -> V_675 = V_677 ;
F_9 ( V_115 , L_94 , V_7 -> V_675 ) ;
if ( V_650 )
V_7 -> V_678 = ( F_58 ( V_36 , ( V_679 >> 1 ) ) & 0x0f ) ;
else
V_7 -> V_678 = V_680 ;
F_9 ( V_115 , L_95 , V_7 -> V_678 ) ;
if ( V_650 )
V_7 -> V_681 = ( F_58 ( V_36 , ( V_682 >> 1 ) ) & 0xff00 ) >> 8 ;
else
V_7 -> V_681 = 1 ;
F_9 ( V_115 , L_96 , V_7 -> V_681 ) ;
if ( V_7 -> V_681 == 0 )
{
int V_1 ;
if ( V_650 )
V_7 -> V_683 = ( F_58 ( V_36 , ( V_684 >> 1 ) ) & 0xff ) >> 8 ;
else
V_7 -> V_683 = 0x10 ;
F_9 ( V_115 , L_97 , V_7 -> V_683 ) ;
for ( V_1 = 0 ; V_1 < 3 ; V_1 ++ )
{
if ( V_650 )
{
V_651 = F_58 ( V_36 , ( V_685 + V_1 ) >> 1 ) ;
if ( ( ( V_685 + V_1 ) % 2 ) == 0 )
V_651 = V_651 & 0x00ff ;
else
V_651 = ( V_651 & 0xff00 ) >> 8 ;
}
else
V_651 = 0x10 ;
V_7 -> V_686 [ V_1 ] = ( T_1 ) V_651 ;
F_9 ( V_115 , L_98 , V_1 , V_7 -> V_683 ) ;
}
}
else if ( V_7 -> V_681 == 1 )
{
if ( V_650 )
{
V_651 = F_58 ( V_36 , ( V_687 >> 1 ) ) ;
V_651 = ( V_651 & 0xff00 ) >> 8 ;
}
else
V_651 = 0x10 ;
V_7 -> V_688 [ 0 ] = ( T_1 ) V_651 ;
if ( V_650 )
V_651 = F_58 ( V_36 , ( V_687 + 2 ) >> 1 ) ;
else
V_651 = 0x1010 ;
* ( ( T_3 * ) ( & V_7 -> V_688 [ 1 ] ) ) = V_651 ;
if ( V_650 )
V_651 = F_58 ( V_36 , ( V_689 >> 1 ) ) ;
else
V_651 = 0x1010 ;
* ( ( T_3 * ) ( & V_7 -> V_686 [ 0 ] ) ) = V_651 ;
if ( V_650 )
V_651 = F_58 ( V_36 , ( V_689 + 2 ) >> 1 ) ;
else
V_651 = 0x10 ;
V_7 -> V_686 [ 2 ] = ( T_1 ) V_651 ;
}
{
int V_1 ;
for ( V_1 = 0 ; V_1 < 14 ; V_1 ++ )
{
if ( V_1 <= 3 )
V_7 -> V_690 [ V_1 ] = V_7 -> V_686 [ 0 ] ;
else if ( V_1 >= 4 && V_1 <= 9 )
V_7 -> V_690 [ V_1 ] = V_7 -> V_686 [ 1 ] ;
else
V_7 -> V_690 [ V_1 ] = V_7 -> V_686 [ 2 ] ;
}
for ( V_1 = 0 ; V_1 < 14 ; V_1 ++ )
{
if ( V_7 -> V_681 == 0 )
{
if ( V_1 <= 3 )
V_7 -> V_691 [ V_1 ] = V_7 -> V_686 [ 0 ] + ( V_7 -> V_683 - V_7 -> V_686 [ 1 ] ) ;
else if ( V_1 >= 4 && V_1 <= 9 )
V_7 -> V_691 [ V_1 ] = V_7 -> V_683 ;
else
V_7 -> V_691 [ V_1 ] = V_7 -> V_686 [ 2 ] + ( V_7 -> V_683 - V_7 -> V_686 [ 1 ] ) ;
}
else if ( V_7 -> V_681 == 1 )
{
if ( V_1 <= 3 )
V_7 -> V_691 [ V_1 ] = V_7 -> V_688 [ 0 ] ;
else if ( V_1 >= 4 && V_1 <= 9 )
V_7 -> V_691 [ V_1 ] = V_7 -> V_688 [ 1 ] ;
else
V_7 -> V_691 [ V_1 ] = V_7 -> V_688 [ 2 ] ;
}
}
}
V_7 -> V_692 = V_7 -> V_675 ;
V_7 -> V_693 [ 0 ] = ( V_7 -> V_668 & 0xf ) ;
V_7 -> V_693 [ 1 ] = ( ( V_7 -> V_668 & 0xf0 ) >> 4 ) ;
V_7 -> V_694 = V_7 -> V_678 ;
V_7 -> V_695 [ 0 ] = V_7 -> V_671 ;
}
switch( V_7 -> V_660 )
{
case V_696 :
V_7 -> V_697 = V_698 ;
break;
case V_699 :
V_7 -> V_697 = V_700 ;
break;
default:
V_7 -> V_697 = V_701 ;
break;
}
switch( V_7 -> V_697 )
{
case V_698 :
V_7 -> V_702 = V_703 ;
break;
case V_700 :
V_7 -> V_702 = V_704 ;
break;
default:
V_7 -> V_702 = V_705 ;
break;
}
if( V_7 -> V_517 == V_518 )
{
F_9 ( V_115 , L_99 ) ;
}
else
{
F_9 ( V_115 , L_100 ) ;
}
F_181 ( V_36 ) ;
F_9 ( V_115 , L_101 , V_28 ) ;
return;
}
short F_182 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
if( V_7 -> V_29 > V_33 ) {
F_20 ( L_102 ) ;
V_7 -> V_29 = 0 ;
}
F_9 ( V_92 , L_103 , V_7 -> V_29 ) ;
F_7 ( V_7 -> V_29 , V_7 ) ;
return 0 ;
}
short F_183 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
memset ( & ( V_7 -> V_64 ) , 0 , sizeof( struct V_706 ) ) ;
memset ( V_7 -> V_373 , 0 , 9 ) ;
#ifdef F_184
{
int V_1 = 0 ;
T_1 V_707 [] = { 3 , 2 , 1 , 0 , 4 , 8 , 7 , 6 , 5 } ;
memcpy ( V_7 -> V_373 , V_707 , 9 ) ;
}
#else
{
T_1 V_707 [] = { 3 , 2 , 1 , 0 , 4 , 4 , 0 , 4 , 4 } ;
memcpy ( V_7 -> V_373 , V_707 , 9 ) ;
}
#endif
F_166 ( V_36 ) ;
F_169 ( V_7 ) ;
F_173 ( V_36 ) ;
F_178 ( V_36 ) ;
F_180 ( V_36 ) ;
F_182 ( V_36 ) ;
F_185 ( V_36 ) ;
F_186 ( & V_7 -> V_708 ) ;
V_7 -> V_708 . V_38 = ( unsigned long ) V_36 ;
V_7 -> V_708 . V_709 = V_710 ;
if( F_137 ( V_36 ) != 0 ) {
F_78 ( L_104 ) ;
return - V_376 ;
}
#ifdef F_187
F_57 ( V_36 ) ;
#endif
return 0 ;
}
void F_188 ( struct V_35 * V_36 )
{
T_2 V_711 = 0 , V_712 = 0 ;
T_1 V_713 = 0 , V_714 = 0 ;
struct V_6 * V_7 = F_17 ( V_36 ) ;
switch( V_7 -> V_12 -> V_117 )
{
case V_542 :
V_713 = V_715 ;
V_711 = V_716 ;
V_712 = V_716 ;
break;
case V_544 :
V_713 = V_717 | V_715 ;
V_711 = V_718 ;
V_712 = V_718 ;
break;
case V_541 :
V_713 = V_715 ;
V_711 = V_716 | V_718 ;
V_712 = V_716 | V_718 ;
break;
case V_547 :
#ifdef F_164
if ( V_607 -> V_608 )
{
V_713 = V_715 ;
V_711 = V_716 | V_718 ;
V_712 = V_716 | V_718 ;
}
else
#endif
{
V_713 = V_715 ;
V_711 = V_716 | V_718 | V_719 | V_720 ;
V_712 = V_716 | V_718 ;
}
break;
case V_536 :
V_713 = V_715 ;
V_711 = V_716 | V_718 | V_719 | V_720 ;
V_712 = V_716 | V_718 ;
break;
case V_537 :
V_713 = V_717 ;
V_711 = V_718 | V_719 | V_720 ;
V_712 = V_718 ;
break;
}
F_23 ( V_36 , V_721 , V_713 ) ;
{
T_2 V_511 = 0 ;
V_511 = V_711 ;
if ( V_7 -> V_517 == V_518 )
{
V_511 &= ~ ( V_720 ) ;
}
F_13 ( V_36 , V_522 , V_511 ) ;
F_23 ( V_36 , V_523 , 1 ) ;
}
V_714 = F_25 ( V_36 , 0x313 ) ;
V_712 = ( ( V_714 ) << 24 ) | ( V_712 & 0x00ffffff ) ;
F_13 ( V_36 , V_338 , V_712 ) ;
F_24 ( V_36 , V_722 ,
V_7 -> V_609 << V_723 | \
V_7 -> V_610 << V_724 ) ;
}
bool F_189 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
T_2 V_725 = 0 ;
bool V_726 = true ;
F_9 ( V_92 , L_105 , V_28 ) ;
V_7 -> V_727 = V_728 ;
F_16 ( V_36 , 0x5f , 0x80 ) ;
F_64 ( 50 ) ;
F_16 ( V_36 , 0x5f , 0xf0 ) ;
F_16 ( V_36 , 0x5d , 0x00 ) ;
F_16 ( V_36 , 0x5e , 0x80 ) ;
F_23 ( V_36 , 0x17 , 0x37 ) ;
F_64 ( 10 ) ;
V_7 -> V_624 -> V_729 = V_730 ;
V_725 = F_15 ( V_36 , V_731 ) ;
if ( V_7 -> V_624 -> V_729 == V_730 )
V_725 |= V_732 ;
else if ( V_7 -> V_624 -> V_729 == V_733 )
V_725 |= V_734 ;
else
F_9 ( V_27 , L_106 , V_28 , V_7 -> V_624 -> V_729 ) ;
F_13 ( V_36 , V_731 , V_725 ) ;
F_190 ( V_36 ) ;
V_7 -> V_735 = V_736 ;
V_725 = F_15 ( V_36 , V_731 ) ;
if ( V_7 -> V_735 == V_736 )
V_725 = ( ( V_725 & V_737 ) | V_738 ) ;
else if ( V_7 -> V_735 == V_739 )
V_725 |= V_740 ;
else
F_9 ( V_27 , L_107 , V_28 , V_7 -> V_735 ) ;
F_13 ( V_36 , V_731 , V_725 ) ;
F_191 ( 500 ) ;
F_16 ( V_36 , 0x5f , ( F_21 ( V_36 , 0x5f ) | 0x20 ) ) ;
F_188 ( V_36 ) ;
F_23 ( V_36 , V_185 , V_187 | V_186 ) ;
F_13 ( V_36 , V_741 , ( ( T_2 * ) V_36 -> V_665 ) [ 0 ] ) ;
F_24 ( V_36 , V_742 , ( ( T_3 * ) ( V_36 -> V_665 + 4 ) ) [ 0 ] ) ;
F_13 ( V_36 , V_162 , V_7 -> V_463 ) ;
F_13 ( V_36 , V_743 , V_744 << V_745 |\
V_746 << V_747 | \
V_748 << V_749 | \
V_750 << V_751 ) ;
F_13 ( V_36 , V_752 , V_753 << V_754 |\
V_755 << V_756 ) ;
F_13 ( V_36 , V_757 , V_758 | \
V_759 << V_760
) ;
F_13 ( V_36 , V_522 + 4 * 7 , ( V_718 | V_716 ) ) ;
F_23 ( V_36 , V_761 , 0x30 ) ;
if( V_7 -> V_566 == V_567 )
F_163 ( V_36 , V_7 -> V_12 -> V_117 ) ;
if( V_7 -> V_566 == V_567 ) {
F_192 ( V_36 ) ;
{
T_1 V_762 = 0x0 ;
V_762 |= V_763 ;
V_762 |= V_764 ;
V_762 |= V_765 ;
F_23 ( V_36 , V_766 , V_762 ) ;
}
}
F_24 ( V_36 , V_352 , 2 ) ;
F_24 ( V_36 , V_354 , 100 ) ;
{
#define F_193 0x005e4332
int V_1 ;
for ( V_1 = 0 ; V_1 < V_481 ; V_1 ++ )
F_13 ( V_36 , V_491 [ V_1 ] , F_193 ) ;
}
#ifdef F_66
if( V_7 -> V_566 == V_567 )
{
T_2 V_767 ;
T_7 V_277 = V_7 -> V_12 -> V_277 ;
V_767 = ( V_277 -> V_768 << 24 ) | ( V_277 -> V_769 << 16 ) |
( V_277 -> V_770 << 8 ) | ( V_277 -> V_771 ) ;
F_13 ( V_36 , 0x1a8 , V_767 ) ;
V_7 -> V_772 = true ;
}
#endif
F_194 ( V_36 ) ;
if ( V_7 -> V_662 == ( T_1 ) V_667 )
{
F_195 ( V_36 ) ;
F_196 ( V_36 , V_7 -> V_140 ) ;
}
V_726 = F_197 ( V_36 ) ;
if( ! V_726 )
{
F_9 ( V_27 , L_108 , V_28 ) ;
return V_726 ;
}
F_9 ( V_92 , L_109 , V_28 ) ;
#ifdef F_164
if( V_607 -> V_566 == V_567 )
{
if( V_773 -> V_774 == TRUE )
{
F_9 ( ( V_92 | V_775 ) , V_776 , ( L_110 ) ) ;
F_198 ( V_607 , V_777 , V_778 ) ;
for( V_779 = 0 ; V_779 < V_549 -> V_780 ; V_779 ++ )
F_199 ( V_607 , ( V_781 ) V_779 , 0x4 , 0xC00 , 0x0 ) ;
}
else if( V_773 -> V_782 > V_783 )
{
F_9 ( ( V_92 | V_775 ) , V_776 , ( L_111 , V_773 -> V_782 ) ) ;
F_198 ( V_607 , V_777 , V_773 -> V_782 ) ;
}
else
{
V_549 -> V_784 = V_785 ;
V_773 -> V_782 = 0 ;
F_9 ( ( V_92 | V_775 ) , V_776 , ( L_112 ) ) ;
}
}
else
{
if( V_549 -> V_784 == V_777 )
{
F_198 ( V_607 , V_777 , V_773 -> V_782 ) ;
for( V_779 = 0 ; V_779 < V_549 -> V_780 ; V_779 ++ )
F_199 ( V_607 , ( V_781 ) V_779 , 0x4 , 0xC00 , 0x0 ) ;
}
}
#endif
if( V_7 -> V_566 == V_567 ) {
F_200 ( V_36 ) ;
F_9 ( V_92 , L_113 , V_28 ) ;
}
if( V_7 -> V_12 -> V_571 )
V_7 -> V_727 = V_786 ;
else
V_7 -> V_727 = V_728 ;
F_201 ( V_36 ) ;
F_202 ( V_36 , V_787 , V_788 , 0x1 ) ;
F_202 ( V_36 , V_787 , V_789 , 0x1 ) ;
if( V_7 -> V_566 == V_567 )
{
T_1 V_790 = F_25 ( V_36 , 0x301 ) ;
if( V_790 == 0x03 )
{
V_7 -> V_791 = TRUE ;
F_9 ( V_792 , L_114 ) ;
}
else
{
V_7 -> V_791 = FALSE ;
F_9 ( V_792 , L_115 ) ;
}
F_203 ( V_36 ) ;
if( V_7 -> V_791 == TRUE )
{
T_2 V_1 , V_793 ;
T_2 V_794 = F_204 ( V_36 , V_795 , V_796 ) ;
for( V_1 = 0 ; V_1 < V_797 ; V_1 ++ )
{
if( V_794 == V_7 -> V_798 [ V_1 ] . V_799 )
{
V_7 -> V_800 = ( T_1 ) V_1 ;
V_7 -> V_801 = ( T_1 ) V_1 ;
V_7 -> V_802 = V_7 -> V_800 ;
break;
}
}
V_793 = F_204 ( V_36 , V_803 , V_804 ) ;
for( V_1 = 0 ; V_1 < V_805 ; V_1 ++ )
{
if( V_793 == V_7 -> V_806 [ V_1 ] . V_807 [ 0 ] )
{
V_7 -> V_808 = ( T_1 ) V_1 ;
break;
}
}
V_7 -> V_809 = 0 ;
V_7 -> V_810 = 0 ;
V_7 -> V_811 = V_7 -> V_808 ;
}
}
F_23 ( V_36 , 0x87 , 0x0 ) ;
return V_726 ;
}
static struct V_812 * F_205 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
return & V_7 -> V_12 -> V_64 ;
}
bool
F_206 (
struct V_35 * V_36
)
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
T_3 V_813 = F_26 ( V_36 , 0x128 ) ;
bool V_814 = FALSE ;
F_9 ( V_815 , L_116 , V_28 , V_813 , V_7 -> V_816 ) ;
if( V_7 -> V_816 == V_813 )
V_814 = TRUE ;
V_7 -> V_816 = V_813 ;
return V_814 ;
}
T_10
F_207 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
T_1 V_280 ;
bool V_817 = false ;
for ( V_280 = 0 ; V_280 <= V_291 ; V_280 ++ )
{
if( V_280 == V_205 )
continue;
#ifdef F_118
if( ( F_68 ( & V_7 -> V_12 -> V_292 [ V_280 ] ) == 0 ) && ( F_68 ( & V_7 -> V_12 -> V_627 [ V_280 ] ) == 0 ) && ( F_68 ( & V_7 -> V_12 -> V_281 [ V_280 ] ) == 0 ) )
#else
if( ( F_68 ( & V_7 -> V_12 -> V_292 [ V_280 ] ) == 0 ) && ( F_68 ( & V_7 -> V_12 -> V_627 [ V_280 ] ) == 0 ) )
#endif
continue;
V_817 = true ;
}
if( V_817 )
{
if( F_206 ( V_36 ) )
{
F_9 ( V_815 , L_117 ) ;
return V_818 ;
}
}
return V_567 ;
}
bool
F_208 ( struct V_35 * V_36 )
{
T_3 V_819 = F_26 ( V_36 , 0x130 ) ;
struct V_6 * V_7 = F_17 ( V_36 ) ;
bool V_814 = FALSE ;
static T_1 V_820 ;
F_9 ( V_815 , L_118 , V_28 , V_819 , V_7 -> V_821 ) ;
V_820 ++ ;
if( V_7 -> V_822 >= ( V_823 + 5 ) )
{
V_820 = 0 ;
}
else if( V_7 -> V_822 < ( V_823 + 5 ) &&
( ( V_7 -> V_250 != V_824 && V_7 -> V_822 >= V_825 ) ||
( V_7 -> V_250 == V_824 && V_7 -> V_822 >= V_826 ) ) )
{
if( V_820 < 2 )
{
return V_814 ;
}
else
{
V_820 = 0 ;
}
}
else if( ( ( V_7 -> V_250 != V_824 && V_7 -> V_822 < V_825 ) ||
( V_7 -> V_250 == V_824 && V_7 -> V_822 < V_826 ) ) &&
V_7 -> V_822 >= V_827 )
{
if( V_820 < 4 )
{
return V_814 ;
}
else
{
V_820 = 0 ;
}
}
else
{
if( V_820 < 8 )
{
return V_814 ;
}
else
{
V_820 = 0 ;
}
}
if( V_7 -> V_821 == V_819 )
V_814 = TRUE ;
V_7 -> V_821 = V_819 ;
return V_814 ;
}
T_10
F_209 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
bool V_828 = FALSE ;
if( V_7 -> V_565 > 1 )
V_828 = TRUE ;
if( V_828 )
{
if( F_208 ( V_36 ) )
{
F_9 ( V_815 , L_119 ) ;
return V_818 ;
}
}
return V_567 ;
}
T_10
F_210 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
T_10 V_829 = V_567 ;
T_10 V_830 = V_567 ;
T_11 V_831 ;
V_831 = V_7 -> V_12 -> V_784 ;
V_829 = F_207 ( V_36 ) ;
if( V_831 != V_777 ||
( V_7 -> V_12 -> V_129 != V_133 ) )
{
V_830 = F_209 ( V_36 ) ;
}
if( V_829 == V_832 || V_830 == V_832 )
return V_832 ;
else if( V_829 == V_818 || V_830 == V_818 ) {
F_9 ( V_815 , L_120 , V_28 ) ;
return V_818 ;
}
else
return V_567 ;
}
void
F_211 ( struct V_35 * V_36 )
{
T_1 V_833 = 0 ;
struct V_6 * V_7 = F_17 ( V_36 ) ;
T_1 * V_834 = V_7 -> V_12 -> V_304 . V_351 ;
static T_1 V_835 [ 4 ] [ 6 ] = {
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x02 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x03 } } ;
static T_1 V_836 [] =
{ 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
F_9 ( V_837 , L_121 ) ;
if ( ( V_7 -> V_12 -> V_264 == V_265 ) ||
( V_7 -> V_12 -> V_264 == V_266 ) )
{
for( V_833 = 0 ; V_833 < 4 ; V_833 ++ )
{
{
V_834 = V_835 [ V_833 ] ;
F_212 ( V_36 ,
V_833 ,
V_833 ,
V_7 -> V_12 -> V_264 ,
V_834 ,
0 ,
NULL ) ;
}
}
}
else if( V_7 -> V_12 -> V_264 == V_267 )
{
{
if( V_7 -> V_12 -> V_129 == V_133 )
F_212 ( V_36 ,
4 ,
0 ,
V_7 -> V_12 -> V_264 ,
( T_1 * ) V_36 -> V_665 ,
0 ,
NULL ) ;
else
F_212 ( V_36 ,
4 ,
0 ,
V_7 -> V_12 -> V_264 ,
V_834 ,
0 ,
NULL ) ;
}
}
else if( V_7 -> V_12 -> V_264 == V_268 )
{
{
if( V_7 -> V_12 -> V_129 == V_133 )
F_212 ( V_36 ,
4 ,
0 ,
V_7 -> V_12 -> V_264 ,
( T_1 * ) V_36 -> V_665 ,
0 ,
NULL ) ;
else
F_212 ( V_36 ,
4 ,
0 ,
V_7 -> V_12 -> V_264 ,
V_834 ,
0 ,
NULL ) ;
}
}
if( V_7 -> V_12 -> V_838 == V_267 )
{
V_834 = V_836 ;
for( V_833 = 1 ; V_833 < 4 ; V_833 ++ )
{
{
F_212 ( V_36 ,
V_833 ,
V_833 ,
V_7 -> V_12 -> V_838 ,
V_834 ,
0 ,
NULL ) ;
}
}
if( V_7 -> V_12 -> V_129 == V_133 )
F_212 ( V_36 ,
0 ,
0 ,
V_7 -> V_12 -> V_838 ,
V_835 [ 0 ] ,
0 ,
NULL ) ;
}
else if( V_7 -> V_12 -> V_838 == V_268 )
{
V_834 = V_836 ;
for( V_833 = 1 ; V_833 < 4 ; V_833 ++ )
{
{
F_212 ( V_36 ,
V_833 ,
V_833 ,
V_7 -> V_12 -> V_838 ,
V_834 ,
0 ,
NULL ) ;
}
}
if( V_7 -> V_12 -> V_129 == V_133 )
F_212 ( V_36 ,
0 ,
0 ,
V_7 -> V_12 -> V_838 ,
V_835 [ 0 ] ,
0 ,
NULL ) ;
}
}
void
F_213 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
T_1 V_839 = 0 ;
int V_840 = 0 ;
struct V_10 * V_11 = V_7 -> V_12 ;
if( V_7 -> V_566 == V_567 )
{
V_841:
F_9 ( V_815 , L_122 ) ;
V_7 -> V_566 = V_818 ;
F_214 ( & V_7 -> V_630 ) ;
if( V_7 -> V_195 == 0 )
{
F_9 ( V_27 , L_123 , V_28 ) ;
V_195 ( & V_7 -> V_630 ) ;
return ;
}
V_7 -> V_195 = 0 ;
F_9 ( V_815 , L_124 , V_28 ) ;
F_82 ( V_36 ) ;
F_215 ( V_7 ) ;
F_216 ( V_36 ) ;
F_217 ( & V_7 -> V_708 ) ;
V_11 -> V_842 = 1 ;
if( V_11 -> V_127 == V_128 )
{
F_214 ( & V_11 -> V_630 ) ;
F_20 ( L_125 ) ;
F_218 ( V_7 -> V_12 ) ;
F_217 ( & V_11 -> V_843 ) ;
F_219 ( & V_11 -> V_844 ) ;
F_220 ( V_11 ) ;
F_221 ( V_36 ) ;
V_195 ( & V_11 -> V_630 ) ;
}
else{
F_20 ( L_126 ) ;
F_222 ( V_7 -> V_12 ) ; }
V_195 ( & V_7 -> V_630 ) ;
F_9 ( V_815 , L_127 , V_28 ) ;
F_9 ( V_815 , L_128 , V_28 ) ;
V_840 = F_223 ( V_36 ) ;
F_9 ( V_815 , L_129 , V_28 ) ;
if( V_840 == - V_845 )
{
if( V_839 < 3 )
{
V_839 ++ ;
goto V_841;
}
else
{
F_9 ( V_27 , L_130 , V_28 ) ;
}
}
V_11 -> V_846 = 1 ;
F_146 ( V_36 ) ;
if( V_11 -> V_127 == V_128 && V_11 -> V_129 == V_130 )
{
V_11 -> V_587 ( V_11 -> V_36 , V_11 -> V_304 . V_847 ) ;
F_154 ( V_11 -> V_848 , & V_11 -> V_849 ) ;
}
else if( V_11 -> V_127 == V_128 && V_11 -> V_129 == V_133 )
{
V_11 -> V_587 ( V_11 -> V_36 , V_11 -> V_304 . V_847 ) ;
V_11 -> V_588 ( V_11 -> V_36 ) ;
F_224 ( V_11 ) ;
if ( V_11 -> V_591 )
V_11 -> V_591 ( V_11 -> V_36 ) ;
F_225 ( V_11 -> V_36 ) ;
}
F_211 ( V_36 ) ;
V_7 -> V_566 = V_567 ;
V_7 -> V_850 ++ ;
V_7 -> V_568 = false ;
V_7 -> V_851 = false ;
F_23 ( V_36 , V_523 , 1 ) ;
F_9 ( V_815 , L_131 , V_7 -> V_850 ) ;
}
}
void F_226 (
struct V_35 * V_36 ,
T_2 V_852
)
{
T_2 V_853 = 0 ;
T_2 V_854 = 0 ;
T_1 V_855 = 0 ;
T_2 V_856 ;
T_12 V_1 = 100 ;
for( V_855 = 0 ; V_855 < V_857 ; V_855 ++ )
{
V_853 = V_855 + V_857 * V_852 ;
V_853 = V_853 | V_41 ;
while( ( V_1 -- ) >= 0 )
{
V_856 = F_15 ( V_36 , V_40 ) ;
if( V_856 & V_41 ) {
continue;
}
else{
break;
}
}
F_13 ( V_36 , V_40 , V_853 ) ;
F_9 ( V_837 , L_132 , V_853 ) ;
V_854 = F_15 ( V_36 , V_858 ) ;
F_9 ( V_837 , L_133 , V_854 ) ;
}
F_20 ( L_53 ) ;
}
void F_227 (
struct V_6 * V_7 ,
T_2 * V_859 ,
T_2 * V_860
)
{
T_3 V_861 ;
T_1 V_1 ;
* V_859 = 0 ;
* V_860 = 0 ;
V_861 = ( V_7 -> V_12 -> V_287 . V_861 ++ ) % ( V_7 -> V_12 -> V_287 . V_862 ) ;
V_7 -> V_12 -> V_287 . V_863 [ V_861 ] = V_7 -> V_12 -> V_287 . V_864 ;
V_7 -> V_12 -> V_287 . V_865 [ V_861 ] = V_7 -> V_12 -> V_287 . V_866 ;
for( V_1 = 0 ; V_1 < V_7 -> V_12 -> V_287 . V_862 ; V_1 ++ ) {
* V_859 += V_7 -> V_12 -> V_287 . V_863 [ V_1 ] ;
* V_860 += V_7 -> V_12 -> V_287 . V_865 [ V_1 ] ;
}
}
extern void V_635 ( struct V_464 * V_465 )
{
struct V_867 * V_868 = F_148 ( V_465 , struct V_867 , V_465 ) ;
struct V_6 * V_7 = F_148 ( V_868 , struct V_6 , V_634 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
struct V_10 * V_11 = V_7 -> V_12 ;
T_10 V_869 = V_567 ;
static T_1 V_870 ;
bool V_871 = false ;
if( ! V_7 -> V_195 )
return;
F_228 ( V_36 ) ;
{
if( V_11 -> V_127 == V_128 )
{
if( V_11 -> V_287 . V_872 > 666 ||
V_11 -> V_287 . V_288 > 666 ) {
V_871 = true ;
}
V_11 -> V_287 . V_872 = 0 ;
V_11 -> V_287 . V_288 = 0 ;
V_11 -> V_287 . V_871 = V_871 ;
}
}
{
if( V_7 -> V_12 -> V_127 == V_128 && V_7 -> V_12 -> V_129 == V_130 )
{
T_2 V_859 = 0 ;
T_2 V_860 = 0 ;
F_227 ( V_7 , & V_859 , & V_860 ) ;
if( ( V_859 + V_860 ) == 0 )
{
#ifdef F_229
if( V_831 == V_777 )
F_9 ( V_27 , L_134 , V_28 ) ;
#endif
F_20 ( L_135 , V_28 ) ;
V_7 -> V_12 -> V_127 = V_873 ;
F_230 ( V_7 -> V_12 ) ;
F_231 ( V_7 -> V_12 , V_7 -> V_12 -> V_304 . V_351 ) ;
V_7 -> V_12 -> V_588 ( V_36 ) ;
F_154 ( V_7 -> V_12 -> V_848 , & V_7 -> V_12 -> V_874 ) ;
}
}
V_7 -> V_12 -> V_287 . V_864 = 0 ;
V_7 -> V_12 -> V_287 . V_866 = 0 ;
}
if( V_870 ++ >= 3 )
{
V_869 = F_210 ( V_36 ) ;
V_870 = 3 ;
}
if( ( V_7 -> V_570 ) || ( V_7 -> V_566 == V_567 &&
( V_7 -> V_568 ||
( ! V_7 -> V_569 && V_869 == V_818 ) ) ) )
{
F_9 ( V_815 , L_136 , V_28 , V_7 -> V_570 , V_7 -> V_566 , V_7 -> V_568 , V_7 -> V_569 , V_869 ) ;
F_213 ( V_36 ) ;
}
V_7 -> V_570 = false ;
V_7 -> V_568 = false ;
V_7 -> V_851 = false ;
F_9 ( V_875 , L_137 ) ;
}
void V_710 ( unsigned long V_38 )
{
struct V_6 * V_7 = F_17 ( (struct V_35 * ) V_38 ) ;
F_156 ( V_7 -> V_501 , & V_7 -> V_634 , 0 ) ;
F_232 ( & V_7 -> V_708 , V_285 + F_233 ( V_876 ) ) ;
}
int F_223 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
int V_726 = 0 ;
V_7 -> V_195 = 1 ;
V_7 -> V_12 -> V_555 = 1 ;
F_9 ( V_92 , L_138 ) ;
V_726 = F_189 ( V_36 ) ;
if( ! V_726 )
{
F_9 ( V_27 , L_139 , V_28 ) ;
V_7 -> V_195 = V_7 -> V_12 -> V_555 = 0 ;
return - V_845 ;
}
F_9 ( V_92 , L_140 ) ;
F_80 ( V_36 ) ;
if( V_7 -> V_12 -> V_127 != V_128 )
F_234 ( V_7 -> V_12 ) ;
F_235 ( V_7 -> V_12 ) ;
V_710 ( ( unsigned long ) V_36 ) ;
if( ! F_36 ( V_36 ) )
F_236 ( V_36 ) ;
else
F_237 ( V_36 ) ;
return 0 ;
}
int F_238 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
int V_202 ;
F_214 ( & V_7 -> V_630 ) ;
V_202 = F_239 ( V_36 ) ;
V_195 ( & V_7 -> V_630 ) ;
return V_202 ;
}
int F_239 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
if ( V_7 -> V_195 == 1 ) return - 1 ;
return F_223 ( V_36 ) ;
}
int F_240 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
int V_202 ;
F_214 ( & V_7 -> V_630 ) ;
V_202 = F_241 ( V_36 ) ;
V_195 ( & V_7 -> V_630 ) ;
return V_202 ;
}
int F_241 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
int V_1 ;
if ( V_7 -> V_195 == 0 ) return - 1 ;
V_7 -> V_195 = 0 ;
V_7 -> V_12 -> V_555 = 0 ;
F_9 ( V_877 , L_141 , V_28 ) ;
if ( ! F_36 ( V_36 ) )
F_242 ( V_36 ) ;
F_82 ( V_36 ) ;
for( V_1 = 0 ; V_1 < V_626 ; V_1 ++ ) {
F_85 ( & V_7 -> V_12 -> V_292 [ V_1 ] ) ;
}
for( V_1 = 0 ; V_1 < V_626 ; V_1 ++ ) {
F_85 ( & V_7 -> V_12 -> V_627 [ V_1 ] ) ;
}
for( V_1 = 0 ; V_1 < V_626 ; V_1 ++ ) {
F_85 ( & V_7 -> V_12 -> V_281 [ V_1 ] ) ;
}
F_215 ( V_7 ) ;
F_216 ( V_36 ) ;
F_217 ( & V_7 -> V_708 ) ;
F_222 ( V_7 -> V_12 ) ;
memset ( & V_7 -> V_12 -> V_304 , 0 , F_243 ( struct V_56 , V_878 ) ) ;
F_9 ( V_877 , L_142 , V_28 ) ;
return 0 ;
}
void F_244 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
int V_840 = 0 ;
if ( V_7 -> V_195 == 0 ) return ;
V_7 -> V_195 = 0 ;
F_215 ( V_7 ) ;
F_217 ( & V_7 -> V_708 ) ;
F_222 ( V_7 -> V_12 ) ;
F_82 ( V_36 ) ;
V_840 = F_223 ( V_36 ) ;
}
void V_633 ( struct V_464 * V_465 )
{
struct V_6 * V_7 = F_148 ( V_465 , struct V_6 , V_114 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
F_214 ( & V_7 -> V_630 ) ;
F_244 ( V_36 ) ;
V_195 ( & V_7 -> V_630 ) ;
}
static void F_245 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
short V_563 ;
V_563 = ( V_36 -> V_168 & V_169 ) ? 1 : 0 ;
if ( V_563 != V_7 -> V_563 )
V_7 -> V_563 = V_563 ;
}
int F_246 ( struct V_35 * V_36 , void * V_879 )
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
struct V_880 * V_37 = V_879 ;
F_214 ( & V_7 -> V_630 ) ;
memcpy ( V_36 -> V_665 , V_37 -> V_881 , V_882 ) ;
F_56 ( & V_7 -> V_114 ) ;
V_195 ( & V_7 -> V_630 ) ;
return 0 ;
}
int F_247 ( struct V_35 * V_36 , struct V_883 * V_884 , int V_184 )
{
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
struct V_885 * V_886 = (struct V_885 * ) V_884 ;
int V_202 = - 1 ;
struct V_10 * V_11 = V_7 -> V_12 ;
T_2 V_887 [ 4 ] ;
T_1 V_888 [ 6 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_889 * V_890 = & V_886 -> V_891 . V_38 ;
struct V_892 * V_893 = NULL ;
F_214 ( & V_7 -> V_630 ) ;
if ( V_890 -> V_894 < sizeof( struct V_892 ) || ! V_890 -> V_895 ) {
V_202 = - V_896 ;
goto V_897;
}
V_893 = F_138 ( V_890 -> V_894 , V_157 ) ;
if ( V_893 == NULL ) {
V_202 = - V_376 ;
goto V_897;
}
if ( F_248 ( V_893 , V_890 -> V_895 , V_890 -> V_894 ) ) {
F_142 ( V_893 ) ;
V_202 = - V_898 ;
goto V_897;
}
switch ( V_184 ) {
case V_899 :
if ( V_893 -> V_184 == V_900 )
{
if ( V_893 -> V_891 . V_525 . V_901 )
{
if ( strcmp ( V_893 -> V_891 . V_525 . V_902 , L_143 ) == 0 )
V_11 -> V_264 = V_268 ;
else if ( strcmp ( V_893 -> V_891 . V_525 . V_902 , L_144 ) == 0 )
V_11 -> V_264 = V_267 ;
else if ( strcmp ( V_893 -> V_891 . V_525 . V_902 , L_82 ) == 0 )
{
if ( V_893 -> V_891 . V_525 . V_903 == 13 )
V_11 -> V_264 = V_266 ;
else if ( V_893 -> V_891 . V_525 . V_903 == 5 )
V_11 -> V_264 = V_265 ;
}
else
V_11 -> V_264 = V_269 ;
if ( V_11 -> V_264 )
{
memcpy ( ( T_1 * ) V_887 , V_893 -> V_891 . V_525 . V_887 , 16 ) ;
F_146 ( V_36 ) ;
F_212 ( V_36 , 4 , V_893 -> V_891 . V_525 . V_904 , V_11 -> V_264 , ( T_1 * ) V_11 -> V_905 , 0 , V_887 ) ;
if ( V_11 -> V_906 != 2 )
F_212 ( V_36 , V_893 -> V_891 . V_525 . V_904 , V_893 -> V_891 . V_525 . V_904 , V_11 -> V_264 , ( T_1 * ) V_11 -> V_905 , 0 , V_887 ) ;
}
}
else
{
memcpy ( ( T_1 * ) V_887 , V_893 -> V_891 . V_525 . V_887 , 16 ) ;
if ( strcmp ( V_893 -> V_891 . V_525 . V_902 , L_143 ) == 0 )
V_11 -> V_838 = V_268 ;
else if ( strcmp ( V_893 -> V_891 . V_525 . V_902 , L_144 ) == 0 )
V_11 -> V_838 = V_267 ;
else if ( strcmp ( V_893 -> V_891 . V_525 . V_902 , L_82 ) == 0 )
{
if ( V_893 -> V_891 . V_525 . V_903 == 13 )
V_11 -> V_838 = V_266 ;
else if ( V_893 -> V_891 . V_525 . V_903 == 5 )
V_11 -> V_838 = V_265 ;
}
else
V_11 -> V_838 = V_269 ;
if ( V_11 -> V_838 )
{
F_212 ( V_36 ,
V_893 -> V_891 . V_525 . V_904 ,
V_893 -> V_891 . V_525 . V_904 ,
V_11 -> V_838 ,
V_888 ,
0 ,
V_887 ) ;
}
}
}
#ifdef F_249
F_20 ( L_145 ) ;
for( V_1 = 0 ; V_1 < V_886 -> V_891 . V_38 . V_894 ; V_1 ++ ) {
if( V_1 % 10 == 0 ) F_20 ( L_53 ) ;
F_20 ( L_146 , ( ( T_2 * ) V_886 -> V_891 . V_38 . V_895 ) [ V_1 ] ) ;
}
F_20 ( L_53 ) ;
#endif
V_202 = F_250 ( V_7 -> V_12 , & V_886 -> V_891 . V_38 ) ;
break;
default:
V_202 = - V_907 ;
break;
}
F_142 ( V_893 ) ;
V_893 = NULL ;
V_897:
V_195 ( & V_7 -> V_630 ) ;
return V_202 ;
}
T_1 F_251 ( bool V_908 , T_1 V_191 )
{
T_1 V_909 = 0xff ;
if( ! V_908 ) {
switch( V_191 ) {
case V_400 : V_909 = V_307 ; break;
case V_401 : V_909 = V_309 ; break;
case V_402 : V_909 = V_311 ; break;
case V_403 : V_909 = V_313 ; break;
case V_404 : V_909 = V_315 ; break;
case V_405 : V_909 = V_317 ; break;
case V_406 : V_909 = V_319 ; break;
case V_407 : V_909 = V_321 ; break;
case V_408 : V_909 = V_323 ; break;
case V_409 : V_909 = V_325 ; break;
case V_410 : V_909 = V_327 ; break;
case V_411 : V_909 = V_329 ; break;
default:
V_909 = 0xff ;
F_9 ( V_910 , L_147 , V_191 , V_908 ) ;
break;
}
} else {
switch( V_191 ) {
case V_413 : V_909 = V_412 ; break;
case V_415 : V_909 = V_414 ; break;
case V_417 : V_909 = V_416 ; break;
case V_419 : V_909 = V_418 ; break;
case V_421 : V_909 = V_420 ; break;
case V_423 : V_909 = V_422 ; break;
case V_425 : V_909 = V_424 ; break;
case V_427 : V_909 = V_426 ; break;
case V_429 : V_909 = V_428 ; break;
case V_431 : V_909 = V_430 ; break;
case V_433 : V_909 = V_432 ; break;
case V_435 : V_909 = V_434 ; break;
case V_437 : V_909 = V_436 ; break;
case V_439 : V_909 = V_438 ; break;
case V_441 : V_909 = V_440 ; break;
case V_443 : V_909 = V_442 ; break;
case V_444 : V_909 = ( 0x80 | 0x20 ) ; break;
default:
V_909 = 0xff ;
F_9 ( V_910 , L_147 , V_191 , V_908 ) ;
break;
}
}
return V_909 ;
}
void F_252 ( struct V_35 * V_36 , struct V_142 * V_64 )
{
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
if( V_64 -> V_911 && ! V_64 -> V_912 ) {
V_64 -> V_913 [ 0 ] = V_7 -> V_914 ;
V_64 -> V_913 [ 1 ] = V_7 -> V_915 ;
} else {
V_7 -> V_914 = V_64 -> V_913 [ 0 ] ;
V_7 -> V_915 = V_64 -> V_913 [ 1 ] ;
}
}
long F_253 ( T_1 V_916 )
{
long V_917 ;
V_917 = ( long ) ( ( V_916 + 1 ) >> 1 ) ;
V_917 -= 95 ;
return V_917 ;
}
void F_254 ( struct V_6 * V_7 , T_1 * V_108 , struct V_142 * V_918 , struct V_142 * V_919 )
{
bool V_920 = false ;
T_1 V_921 ;
T_2 V_922 , V_923 ;
static T_2 V_924 , V_925 ;
static T_2 V_926 , V_927 ;
static T_2 V_928 , V_929 ;
static T_2 V_930 , V_931 ;
static T_2 V_932 ;
struct V_933 * V_934 ;
T_3 V_935 ;
unsigned int V_936 , V_937 ;
V_934 = (struct V_933 * ) V_108 ;
V_935 = F_255 ( V_934 -> V_938 ) ;
V_936 = F_256 ( V_935 ) ;
V_937 = F_257 ( V_935 ) ;
V_919 -> V_939 = V_937 ;
if( ! V_918 -> V_911 )
{
V_920 = true ;
}
if( V_925 ++ >= V_940 )
{
V_925 = V_940 ;
V_928 = V_7 -> V_64 . V_941 [ V_924 ] ;
V_7 -> V_64 . V_942 -= V_928 ;
}
V_7 -> V_64 . V_942 += V_918 -> V_943 ;
V_7 -> V_64 . V_941 [ V_924 ++ ] = V_918 -> V_943 ;
if( V_924 >= V_940 )
V_924 = 0 ;
V_923 = V_7 -> V_64 . V_942 / V_925 ;
V_7 -> V_64 . V_944 = F_253 ( ( T_1 ) V_923 ) ;
V_919 -> V_945 = V_7 -> V_64 . V_944 ;
if( ! V_918 -> V_946 )
{
if( ! V_918 -> V_947 )
return;
}
if( ! V_920 )
return;
V_7 -> V_64 . V_948 ++ ;
if( ! V_918 -> V_949 && ( V_918 -> V_950 || V_918 -> V_947 ) )
{
for ( V_921 = V_951 ; V_921 < V_7 -> V_780 ; V_921 ++ )
{
if ( ! F_258 ( V_7 -> V_12 -> V_36 , V_921 ) )
continue;
if( V_7 -> V_64 . V_952 [ V_921 ] == 0 )
{
V_7 -> V_64 . V_952 [ V_921 ] = V_918 -> V_953 [ V_921 ] ;
}
if( V_918 -> V_953 [ V_921 ] > V_7 -> V_64 . V_952 [ V_921 ] )
{
V_7 -> V_64 . V_952 [ V_921 ] =
( ( V_7 -> V_64 . V_952 [ V_921 ] * ( V_954 - 1 ) ) +
( V_918 -> V_953 [ V_921 ] ) ) / ( V_954 ) ;
V_7 -> V_64 . V_952 [ V_921 ] = V_7 -> V_64 . V_952 [ V_921 ] + 1 ;
}
else
{
V_7 -> V_64 . V_952 [ V_921 ] =
( ( V_7 -> V_64 . V_952 [ V_921 ] * ( V_954 - 1 ) ) +
( V_918 -> V_953 [ V_921 ] ) ) / ( V_954 ) ;
}
F_9 ( V_955 , L_148 , V_7 -> V_64 . V_952 [ V_921 ] ) ;
}
}
F_9 ( V_956 , L_149 ,
V_918 -> V_949 ? L_150 : L_151 ,
V_918 -> V_957 ) ;
if( V_918 -> V_958 )
{
if( V_931 ++ >= V_959 )
{
V_931 = V_959 ;
V_932 = V_7 -> V_64 . V_960 [ V_930 ] ;
V_7 -> V_64 . V_961 -= V_932 ;
}
V_7 -> V_64 . V_961 += V_918 -> V_957 ;
V_7 -> V_64 . V_960 [ V_930 ] = V_918 -> V_957 ;
V_930 ++ ;
if( V_930 >= V_959 )
V_930 = 0 ;
V_918 -> V_957 = V_7 -> V_64 . V_961 / V_931 ;
if( V_918 -> V_957 >= 3 )
V_918 -> V_957 -= 3 ;
}
F_9 ( V_956 , L_149 ,
V_918 -> V_949 ? L_150 : L_151 ,
V_918 -> V_957 ) ;
if( V_918 -> V_950 || V_918 -> V_958 || V_918 -> V_947 )
{
if( V_7 -> V_822 < 0 )
{
V_7 -> V_822 = V_918 -> V_957 ;
}
if( V_918 -> V_957 > ( T_2 ) V_7 -> V_822 )
{
V_7 -> V_822 =
( ( ( V_7 -> V_822 ) * ( V_954 - 1 ) ) +
( V_918 -> V_957 ) ) / ( V_954 ) ;
V_7 -> V_822 = V_7 -> V_822 + 1 ;
}
else
{
V_7 -> V_822 =
( ( ( V_7 -> V_822 ) * ( V_954 - 1 ) ) +
( V_918 -> V_957 ) ) / ( V_954 ) ;
}
}
if( V_918 -> V_962 == 0 )
{
}
else
{
if( V_918 -> V_950 || V_918 -> V_958 || V_918 -> V_947 ) {
if( V_927 ++ >= V_940 ) {
V_927 = V_940 ;
V_929 = V_7 -> V_64 . V_963 [ V_926 ] ;
V_7 -> V_64 . V_964 -= V_929 ;
}
V_7 -> V_64 . V_964 += V_918 -> V_962 ;
V_7 -> V_64 . V_963 [ V_926 ++ ] = V_918 -> V_962 ;
if( V_926 >= V_940 )
V_926 = 0 ;
V_923 = V_7 -> V_64 . V_964 / V_927 ;
V_7 -> V_64 . V_965 = V_923 ;
V_7 -> V_64 . V_966 = V_923 ;
}
if( V_918 -> V_950 || V_918 -> V_958 || V_918 -> V_947 )
{
for( V_922 = 0 ; V_922 < 2 ; V_922 ++ )
{
if( V_918 -> V_967 [ V_922 ] != - 1 )
{
if( V_7 -> V_64 . V_968 [ V_922 ] == 0 )
{
V_7 -> V_64 . V_968 [ V_922 ] = V_918 -> V_967 [ V_922 ] ;
}
V_7 -> V_64 . V_968 [ V_922 ] =
( ( V_7 -> V_64 . V_968 [ V_922 ] * ( V_954 - 1 ) ) +
( V_918 -> V_967 [ V_922 ] * 1 ) ) / ( V_954 ) ;
}
}
}
}
}
static T_1 F_259 (
char V_969
)
{
if ( ( V_969 <= - 100 ) || ( V_969 >= 20 ) )
{
return 0 ;
}
else if ( V_969 >= 0 )
{
return 100 ;
}
else
{
return ( 100 + V_969 ) ;
}
}
static T_1
F_260 (
char V_970
)
{
char V_971 ;
V_971 = V_970 ;
if( V_971 >= 0 )
V_971 = 0 ;
if( V_971 <= - 33 )
V_971 = - 33 ;
V_971 = 0 - V_971 ;
V_971 *= 3 ;
if( V_971 == 99 )
V_971 = 100 ;
return ( V_971 ) ;
}
long
F_261 (
long V_972
)
{
long V_973 ;
if( V_972 >= 61 && V_972 <= 100 )
{
V_973 = 90 + ( ( V_972 - 60 ) / 4 ) ;
}
else if( V_972 >= 41 && V_972 <= 60 )
{
V_973 = 78 + ( ( V_972 - 40 ) / 2 ) ;
}
else if( V_972 >= 31 && V_972 <= 40 )
{
V_973 = 66 + ( V_972 - 30 ) ;
}
else if( V_972 >= 21 && V_972 <= 30 )
{
V_973 = 54 + ( V_972 - 20 ) ;
}
else if( V_972 >= 5 && V_972 <= 20 )
{
V_973 = 42 + ( ( ( V_972 - 5 ) * 2 ) / 3 ) ;
}
else if( V_972 == 4 )
{
V_973 = 36 ;
}
else if( V_972 == 3 )
{
V_973 = 27 ;
}
else if( V_972 == 2 )
{
V_973 = 18 ;
}
else if( V_972 == 1 )
{
V_973 = 9 ;
}
else
{
V_973 = V_972 ;
}
return V_973 ;
}
static void F_262 (
struct V_6 * V_7 ,
struct V_142 * V_143 ,
T_13 * V_974 ,
struct V_142 * V_975 ,
bool V_976 ,
bool V_977 ,
bool V_958 ,
bool V_947
)
{
T_14 * V_978 ;
T_15 * V_979 ;
T_16 * V_980 ;
T_1 * V_981 ;
T_1 V_1 , V_982 , V_983 , V_984 , V_985 ;
char V_986 [ 4 ] , V_987 = 0 ;
char V_988 , V_989 ;
T_1 V_990 , V_991 ;
T_2 V_992 , V_993 = 0 ;
T_1 V_994 = 0 ;
T_1 V_995 = 0 ;
V_7 -> V_64 . V_996 ++ ;
V_994 = F_263 ( V_974 ) ;
memset ( V_975 , 0 , sizeof( struct V_142 ) ) ;
V_143 -> V_946 = V_975 -> V_946 = V_976 ;
V_143 -> V_950 = V_975 -> V_950 = V_977 ;
V_143 -> V_949 = V_975 -> V_949 = V_994 ;
V_143 -> V_958 = V_975 -> V_958 = V_958 ;
V_143 -> V_947 = V_975 -> V_947 = V_947 ;
V_981 = ( T_1 * ) V_974 ;
V_981 += sizeof( T_13 ) ;
V_979 = ( T_15 * ) V_981 ;
V_978 = ( T_14 * ) V_981 ;
V_143 -> V_967 [ 0 ] = - 1 ;
V_143 -> V_967 [ 1 ] = - 1 ;
V_975 -> V_967 [ 0 ] = - 1 ;
V_975 -> V_967 [ 1 ] = - 1 ;
if( V_994 )
{
T_1 V_997 ;
V_7 -> V_64 . V_998 ++ ;
if( ! V_7 -> V_999 )
{
V_997 = V_979 -> V_1000 & 0xc0 ;
V_997 = V_997 >> 6 ;
switch( V_997 )
{
case 0x3 :
V_987 = - 35 - ( V_979 -> V_1000 & 0x3e ) ;
break;
case 0x2 :
V_987 = - 23 - ( V_979 -> V_1000 & 0x3e ) ;
break;
case 0x1 :
V_987 = - 11 - ( V_979 -> V_1000 & 0x3e ) ;
break;
case 0x0 :
V_987 = 6 - ( V_979 -> V_1000 & 0x3e ) ;
break;
}
}
else
{
V_997 = V_979 -> V_1000 & 0x60 ;
V_997 = V_997 >> 5 ;
switch( V_997 )
{
case 0x3 :
V_987 = - 35 - ( ( V_979 -> V_1000 & 0x1f ) << 1 ) ;
break;
case 0x2 :
V_987 = - 23 - ( ( V_979 -> V_1000 & 0x1f ) << 1 ) ;
break;
case 0x1 :
V_987 = - 11 - ( ( V_979 -> V_1000 & 0x1f ) << 1 ) ;
break;
case 0x0 :
V_987 = 6 - ( ( V_979 -> V_1000 & 0x1f ) << 1 ) ;
break;
}
}
V_991 = F_259 ( V_987 ) ;
V_143 -> V_957 = V_975 -> V_957 = V_991 ;
V_143 -> V_1001 = V_991 ;
{
T_1 V_1002 ;
if( V_143 -> V_957 > 40 )
{
V_1002 = 100 ;
} else
{
V_1002 = V_979 -> V_1003 ;
if( V_979 -> V_1003 > 64 )
V_1002 = 0 ;
else if ( V_979 -> V_1003 < 20 )
V_1002 = 100 ;
else
V_1002 = ( ( 64 - V_1002 ) * 100 ) / 44 ;
}
V_143 -> V_962 = V_975 -> V_962 = V_1002 ;
V_143 -> V_967 [ 0 ] = V_975 -> V_967 [ 0 ] = V_1002 ;
V_143 -> V_967 [ 1 ] = V_975 -> V_967 [ 1 ] = - 1 ;
}
}
else
{
V_7 -> V_64 . V_1004 ++ ;
for( V_1 = V_951 ; V_1 < V_7 -> V_780 ; V_1 ++ )
{
if ( V_7 -> V_1005 [ V_1 ] )
V_995 ++ ;
else
continue;
if ( ! F_258 ( V_7 -> V_12 -> V_36 , V_1 ) )
continue;
V_986 [ V_1 ] = ( ( V_978 -> V_1006 [ V_1 ] & 0x3F ) * 2 ) - 106 ;
V_983 = V_978 -> V_1007 [ V_1 ] ;
V_988 = ( char ) ( V_983 ) ;
V_988 /= 2 ;
V_7 -> V_64 . V_1008 [ V_1 ] = ( long ) V_988 ;
V_992 = F_259 ( V_986 [ V_1 ] ) ;
V_993 += V_992 ;
{
V_143 -> V_953 [ V_1 ] = ( T_1 ) V_992 ;
V_975 -> V_953 [ V_1 ] = ( T_1 ) V_992 ;
}
}
V_987 = ( ( ( V_978 -> V_991 ) >> 1 ) & 0x7f ) - 106 ;
V_991 = F_259 ( V_987 ) ;
V_143 -> V_957 = V_975 -> V_957 = V_991 ;
V_143 -> V_1009 = V_975 -> V_1009 = V_987 ;
if( V_974 -> V_1010 && V_974 -> V_1011 >= V_429 &&
V_974 -> V_1011 <= V_443 )
V_982 = 2 ;
else
V_982 = 1 ;
for( V_1 = 0 ; V_1 < V_982 ; V_1 ++ )
{
V_984 = V_978 -> V_1012 [ V_1 ] ;
V_989 = ( char ) ( V_984 ) ;
V_989 /= 2 ;
V_990 = F_260 ( V_989 ) ;
{
if( V_1 == 0 )
V_143 -> V_962 = V_975 -> V_962 = ( T_1 ) ( V_990 & 0xff ) ;
V_143 -> V_967 [ V_1 ] = V_975 -> V_967 [ V_1 ] = ( T_1 ) ( V_990 & 0xff ) ;
}
}
V_985 = V_978 -> V_985 ;
V_980 = ( T_16 * ) & V_985 ;
if( V_974 -> V_1013 )
V_7 -> V_64 . V_1014 [ 1 + V_980 -> V_1015 ] ++ ;
else
V_7 -> V_64 . V_1014 [ 0 ] ++ ;
}
if( V_994 )
{
V_143 -> V_943 = V_975 -> V_943 = ( T_1 ) ( F_261 ( ( long ) V_991 ) ) ;
}
else
{
if ( V_995 != 0 )
V_143 -> V_943 = V_975 -> V_943 = ( T_1 ) ( F_261 ( ( long ) ( V_993 /= V_995 ) ) ) ;
}
}
void
F_264 (
struct V_142 * V_1016 ,
struct V_142 * V_1017
)
{
V_1017 -> V_911 = V_1016 -> V_911 ;
V_1017 -> V_912 = V_1016 -> V_912 ;
V_1017 -> V_939 = V_1016 -> V_939 ;
}
void F_265 ( struct V_150 * V_151 ,
struct V_142 * V_143 ,
T_13 * V_974 )
{
V_152 * V_153 = (struct V_152 * ) V_151 -> V_159 ;
struct V_35 * V_36 = V_153 -> V_36 ;
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
bool V_976 , V_977 ;
bool V_958 = FALSE , V_947 = FALSE ;
static struct V_142 V_1018 ;
struct V_933 * V_934 ;
T_3 V_1019 , type ;
T_1 * V_1020 ;
T_1 * V_1021 ;
V_1020 = ( T_1 * ) V_151 -> V_38 ;
V_934 = (struct V_933 * ) V_1020 ;
V_1019 = F_255 ( V_934 -> V_1022 ) ;
type = F_266 ( V_1019 ) ;
V_1021 = V_934 -> V_1023 ;
V_976 = ( ( V_1024 != type ) &&
( F_267 ( V_7 -> V_12 -> V_304 . V_351 , ( V_1019 & V_1025 ) ? V_934 -> V_1023 : ( V_1019 & V_1026 ) ? V_934 -> V_1027 : V_934 -> V_1028 ) )
&& ( ! V_143 -> V_1029 ) && ( ! V_143 -> V_1030 ) && ( ! V_143 -> V_1031 ) ) ;
V_977 = V_976 & ( F_267 ( V_1021 , V_7 -> V_12 -> V_36 -> V_665 ) ) ;
if( F_268 ( V_1019 ) == V_1032 )
{
V_958 = true ;
}
if( F_268 ( V_1019 ) == V_1033 )
{
if( ( F_267 ( V_1021 , V_36 -> V_665 ) ) )
V_947 = true ;
}
if( V_976 )
{
V_7 -> V_64 . V_1034 ++ ;
}
if( V_977 ) {
V_7 -> V_64 . V_1035 ++ ;
}
F_254 ( V_7 , V_1020 , & V_1018 , V_143 ) ;
F_262 ( V_7 , V_143 , V_974 , & V_1018 , V_976 , V_977 , V_958 , V_947 ) ;
F_264 ( V_143 , & V_1018 ) ;
}
void
F_269 (
struct V_35 * V_36 ,
struct V_142 * V_64
)
{
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
T_2 V_1036 = 1 ;
T_2 V_1037 ;
T_2 V_1038 ;
if( V_64 -> V_1030 )
V_1036 = 2 ;
else if( V_64 -> V_1031 )
V_1036 = 3 ;
if( V_64 -> V_365 )
V_1038 = 1 ;
else
V_1038 = 0 ;
switch( V_64 -> V_191 )
{
case V_307 : V_1037 = 0 ; break;
case V_309 : V_1037 = 1 ; break;
case V_311 : V_1037 = 2 ; break;
case V_313 : V_1037 = 3 ; break;
case V_315 : V_1037 = 4 ; break;
case V_317 : V_1037 = 5 ; break;
case V_319 : V_1037 = 6 ; break;
case V_321 : V_1037 = 7 ; break;
case V_323 : V_1037 = 8 ; break;
case V_325 : V_1037 = 9 ; break;
case V_327 : V_1037 = 10 ; break;
case V_329 : V_1037 = 11 ; break;
case V_412 : V_1037 = 12 ; break;
case V_414 : V_1037 = 13 ; break;
case V_416 : V_1037 = 14 ; break;
case V_418 : V_1037 = 15 ; break;
case V_420 : V_1037 = 16 ; break;
case V_422 : V_1037 = 17 ; break;
case V_424 : V_1037 = 18 ; break;
case V_426 : V_1037 = 19 ; break;
case V_428 : V_1037 = 20 ; break;
case V_430 : V_1037 = 21 ; break;
case V_432 : V_1037 = 22 ; break;
case V_434 : V_1037 = 23 ; break;
case V_436 : V_1037 = 24 ; break;
case V_438 : V_1037 = 25 ; break;
case V_440 : V_1037 = 26 ; break;
case V_442 : V_1037 = 27 ; break;
default: V_1037 = 28 ; break;
}
V_7 -> V_64 . V_1039 [ V_1038 ] [ V_1037 ] ++ ;
V_7 -> V_64 . V_1040 [ 0 ] [ V_1037 ] ++ ;
V_7 -> V_64 . V_1040 [ V_1036 ] [ V_1037 ] ++ ;
}
void F_270 ( struct V_150 * V_151 , struct V_142 * V_64 , bool V_1041 )
{
V_152 * V_153 = (struct V_152 * ) V_151 -> V_159 ;
struct V_35 * V_36 = V_153 -> V_36 ;
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
T_13 * V_1042 = NULL ;
#ifdef F_66
if ( V_1041 )
{
T_17 * V_1043 = ( T_17 * ) V_151 -> V_38 ;
V_64 -> V_1044 = V_1043 -> V_1044 ;
V_64 -> V_146 = V_1043 -> V_146 ;
V_64 -> V_147 = 0 ;
V_64 -> V_1031 = V_1043 -> V_1045 ;
V_64 -> V_1030 = V_1043 -> V_1046 ;
V_64 -> V_1029 = V_64 -> V_1030 | V_64 -> V_1031 ;
V_64 -> V_1047 = ! V_1043 -> V_1048 ;
} else
#endif
{
V_145 * V_1043 = ( V_145 * ) V_151 -> V_38 ;
V_64 -> V_1044 = V_1043 -> V_1044 ;
V_64 -> V_146 = V_1043 -> V_146 ;
V_64 -> V_147 = 0 ;
V_64 -> V_1031 = V_1043 -> V_1045 ;
V_64 -> V_1030 = V_1043 -> V_1046 ;
V_64 -> V_1029 = V_64 -> V_1030 | V_64 -> V_1031 ;
V_64 -> V_1047 = ! V_1043 -> V_1048 ;
}
if( ( V_7 -> V_12 -> V_277 -> V_467 == true ) && ( V_7 -> V_12 -> V_264 == V_268 ) )
{
V_64 -> V_1029 = false ;
}
else
{
V_64 -> V_1029 = V_64 -> V_1030 | V_64 -> V_1031 ;
}
if( V_64 -> V_1044 < 24 || V_64 -> V_1044 > V_1049 )
V_64 -> V_1029 |= 1 ;
if ( V_64 -> V_146 != 0 ) {
V_1042 = ( T_13 * ) ( V_151 -> V_38 + sizeof( V_145 ) + \
V_64 -> V_147 ) ;
if( ! V_64 -> V_1029 ) {
T_1 V_909 ;
V_909 = F_251 ( V_1042 -> V_1010 , V_1042 -> V_1011 ) ;
if( V_909 == 0xff )
{
V_64 -> V_1029 = 1 ;
V_64 -> V_191 = V_307 ;
} else
{
V_64 -> V_191 = V_909 ;
}
}
else
V_64 -> V_191 = 0x02 ;
V_64 -> V_365 = V_1042 -> V_1050 ;
F_269 ( V_36 , V_64 ) ;
V_64 -> V_911 = ( V_1042 -> V_1051 == 1 ) ;
V_64 -> V_912 = ( V_1042 -> V_1051 == 1 ) && ( V_1042 -> V_1052 == 1 ) ;
V_64 -> V_1053 = V_1042 -> V_1054 ;
F_252 ( V_36 , V_64 ) ;
if( V_1042 -> V_1052 == 1 || V_1042 -> V_1051 == 1 )
F_9 ( V_956 , L_152 ,
V_1042 -> V_1052 , V_1042 -> V_1051 ) ;
}
F_271 ( V_151 , sizeof( V_145 ) ) ;
if( ( V_64 -> V_147 + V_64 -> V_146 ) > 0 ) {
V_64 -> V_1055 = 1 ;
F_271 ( V_151 , V_64 -> V_147 + V_64 -> V_146 ) ;
}
#ifdef F_66
if( V_1041 ) {
F_271 ( V_151 , 8 ) ;
}
#endif
V_64 -> V_1056 = V_1042 -> V_1013 ;
if( V_64 -> V_146 != 0 )
F_265 ( V_151 , V_64 , V_1042 ) ;
}
T_2 F_272 ( struct V_142 * V_1057 , bool V_1041 )
{
#ifdef F_66
if ( V_1041 )
return ( sizeof( V_145 ) + V_1057 -> V_146
+ V_1057 -> V_147 + 8 ) ;
else
#endif
return ( sizeof( V_145 ) + V_1057 -> V_146
+ V_1057 -> V_147 ) ;
}
void F_273 ( struct V_150 * V_151 )
{
V_152 * V_153 = (struct V_152 * ) V_151 -> V_159 ;
struct V_35 * V_36 = V_153 -> V_36 ;
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
struct V_142 V_64 = {
. signal = 0 ,
. V_1058 = - 98 ,
. V_191 = 0 ,
. V_1059 = V_1060 ,
} ;
T_2 V_1061 = 0 ;
struct V_1062 * V_1063 = NULL ;
bool V_1064 = false ;
#ifdef F_66
struct V_150 * V_215 = NULL ;
T_2 V_214 = 0 ;
T_2 V_1065 = 0 ;
T_2 V_1066 = 0 ;
T_2 V_1067 = 0 ;
T_1 V_1068 = 0 ;
T_2 V_1069 = 0 ;
T_17 * V_1070 = NULL ;
T_1 V_1071 = 0 ;
T_1 V_1072 ;
#endif
if( ( V_151 -> V_109 >= ( 20 + sizeof( V_145 ) ) ) && ( V_151 -> V_109 < V_156 ) ) {
#ifdef F_66
V_1068 = * ( V_151 -> V_38 + sizeof( V_145 ) ) ;
#endif
F_270 ( V_151 , & V_64 , false ) ;
#ifdef F_66
if ( V_1068 & V_1073 ) {
V_215 = V_151 ;
V_214 = V_64 . V_1044 - 4 ;
V_1065 = * ( T_2 * ) ( V_215 -> V_38 - 4 ) ;
V_1066 = ( T_3 ) ( V_1065 & 0x3FFF ) ;
V_151 = F_94 ( V_1066 ) ;
memcpy ( F_92 ( V_151 , V_1066 ) , V_215 -> V_38 , V_1066 ) ;
V_1069 = F_272 ( & V_64 , false ) ;
}
#endif
F_274 ( V_151 , V_151 -> V_109 - 4 ) ;
V_1061 = V_151 -> V_109 ;
V_1063 = (struct V_1062 * ) V_151 -> V_38 ;
V_1064 = false ;
if( F_275 ( V_1063 -> V_1023 ) ) {
} else if( F_276 ( V_1063 -> V_1023 ) ) {
} else {
V_1064 = true ;
}
if( ! F_277 ( V_7 -> V_12 , V_151 , & V_64 ) ) {
F_113 ( V_151 ) ;
} else {
V_7 -> V_64 . V_89 ++ ;
if( V_1064 ) {
V_7 -> V_64 . V_1074 += V_1061 ;
}
}
#ifdef F_66
V_1072 = 1 ;
if ( V_214 > 0 ) {
V_1067 = V_1066 + ( V_1069 + 8 ) ;
if ( ( V_1067 & 0xFF ) != 0 )
V_1067 = ( V_1067 & 0xFFFFFF00 ) + 256 ;
V_1067 -= 8 ;
V_1065 = V_1067 - V_1069 ;
if ( V_215 -> V_109 > V_1065 )
F_271 ( V_215 , V_1065 ) ;
else
V_215 -> V_109 = 0 ;
while ( V_215 -> V_109 >= F_272 ( & V_64 , true ) ) {
T_1 V_1075 = 0 , V_1076 = 0 ;
V_1070 = ( T_17 * ) ( V_215 -> V_38 ) ;
V_1075 = V_1070 -> V_1046 ;
V_1076 = V_1070 -> V_1045 ;
memcpy ( V_215 -> V_38 , & V_215 -> V_38 [ 44 ] , 2 ) ;
V_1070 -> V_1046 = V_1075 ;
V_1070 -> V_1045 = V_1076 ;
memset ( & V_64 , 0 , sizeof( struct V_142 ) ) ;
V_64 . signal = 0 ;
V_64 . V_1058 = - 98 ;
V_64 . V_191 = 0 ;
V_64 . V_1059 = V_1060 ;
F_270 ( V_215 , & V_64 , true ) ;
V_1066 = V_64 . V_1044 ;
if( V_1066 > V_215 -> V_109 ) {
break;
}
V_151 = F_94 ( V_1066 ) ;
memcpy ( F_92 ( V_151 , V_1066 ) , V_215 -> V_38 , V_1066 ) ;
F_274 ( V_151 , V_151 -> V_109 - 4 ) ;
V_1061 = V_151 -> V_109 ;
V_1063 = (struct V_1062 * ) V_151 -> V_38 ;
V_1064 = false ;
if( F_275 ( V_1063 -> V_1023 ) ) {
} else if( F_276 ( V_1063 -> V_1023 ) ) {
} else {
V_1064 = true ;
}
if( ! F_277 ( V_7 -> V_12 , V_151 , & V_64 ) ) {
F_113 ( V_151 ) ;
} else {
V_7 -> V_64 . V_89 ++ ;
if( V_1064 ) {
V_7 -> V_64 . V_1074 += V_1061 ;
}
}
F_271 ( V_215 , V_1066 ) ;
V_1069 = F_272 ( & V_64 , true ) ;
V_1067 = V_1066 + V_1069 ;
if ( ( V_1067 & 0xFF ) != 0 ) {
V_1071 = 256 - ( V_1067 & 0xFF ) ;
if ( V_215 -> V_109 > V_1071 )
F_271 ( V_215 , V_1071 ) ;
else
V_215 -> V_109 = 0 ;
}
}
F_131 ( V_215 ) ;
}
#endif
} else {
V_7 -> V_64 . V_91 ++ ;
F_20 ( L_153 , V_151 -> V_109 ) ;
F_113 ( V_151 ) ;
}
}
void
F_278 (
struct V_35 * V_36 ,
struct V_142 * V_143
)
{
T_1 * V_1077 ;
T_3 V_1078 = 0 ;
struct V_6 * V_7 = F_17 ( V_36 ) ;
V_143 -> V_1079 += F_65 ( V_143 ) ;
V_1077 = V_143 -> V_1079 ;
V_1078 = V_143 -> V_1080 ;
#ifdef F_229
if( ! V_607 -> V_608 )
F_279 ( V_607 , V_1081 ) ;
#endif
{
#ifdef F_280
T_11 V_1082 ;
V_607 -> V_1083 . V_1084 ( V_607 , V_1085 , ( T_1 * ) ( & V_1082 ) ) ;
if ( V_1082 == V_777 )
{
return;
}
#endif
V_7 -> V_64 . V_1086 ++ ;
}
#ifdef F_229
F_281 ( V_607 , V_1081 ) ;
#endif
if ( F_95 ( V_36 , V_143 ) )
{
return;
}
#ifdef F_282
F_283 () ;
#endif
}
void F_284 ( struct V_150 * V_151 , struct V_142 * V_64 )
{
V_145 * V_1043 = ( V_145 * ) V_151 -> V_38 ;
V_64 -> V_1079 = ( T_1 * ) V_151 -> V_38 ;
V_64 -> V_1044 = V_1043 -> V_1044 ;
V_64 -> V_146 = 0 ;
V_64 -> V_147 = 0 ;
V_64 -> V_1080 = V_64 -> V_1044 - V_1087 ;
V_64 -> V_1088 = V_64 -> V_1080 ;
V_64 -> V_1089 = 0 ;
V_64 -> V_1090 = 1 ;
}
void F_285 ( struct V_150 * V_151 )
{
struct V_152 * V_153 = (struct V_152 * ) V_151 -> V_159 ;
struct V_35 * V_36 = V_153 -> V_36 ;
struct V_142 V_64 = {
. signal = 0 ,
. V_1058 = - 98 ,
. V_191 = 0 ,
. V_1059 = V_1060 ,
} ;
if( ( V_151 -> V_109 >= ( 20 + sizeof( V_145 ) ) ) && ( V_151 -> V_109 < V_156 ) )
{
F_284 ( V_151 , & V_64 ) ;
F_278 ( V_36 , & V_64 ) ;
F_113 ( V_151 ) ;
}
}
void V_642 ( struct V_6 * V_7 )
{
struct V_150 * V_151 ;
struct V_152 * V_153 ;
while ( NULL != ( V_151 = F_115 ( & V_7 -> V_188 ) ) ) {
V_153 = (struct V_152 * ) V_151 -> V_159 ;
switch ( V_153 -> V_160 ) {
case 3 :
V_7 -> V_565 -- ;
F_273 ( V_151 ) ;
break;
case 9 :
F_9 ( V_910 , L_154 ,\
V_153 -> V_160 ) ;
F_285 ( V_151 ) ;
break;
default:
F_9 ( V_27 , L_155 ,\
V_153 -> V_160 ) ;
F_131 ( V_151 ) ;
break;
}
}
}
static int F_286 ( struct V_1091 * V_1092 ,
const struct V_1093 * V_1094 )
{
struct V_35 * V_36 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_45 * V_46 = F_287 ( V_1092 ) ;
int V_202 ;
F_9 ( V_92 , L_156 ) ;
V_36 = F_288 ( sizeof( struct V_6 ) ) ;
if ( V_36 == NULL )
return - V_376 ;
F_289 ( V_1092 , V_36 ) ;
F_290 ( V_36 , & V_1092 -> V_36 ) ;
V_7 = F_17 ( V_36 ) ;
V_7 -> V_12 = F_108 ( V_36 ) ;
V_7 -> V_46 = V_46 ;
V_36 -> V_1095 = & V_1096 ;
#if V_1097 >= 12
#if V_1097 < 17
V_36 -> V_1098 = V_1099 ;
#endif
V_36 -> V_1100 = (struct V_1101 * ) & V_1102 ;
#endif
V_36 -> type = V_1103 ;
V_36 -> V_1104 = V_49 * 3 ;
if ( F_291 ( V_36 , V_1105 ) < 0 ) {
F_9 ( V_92 , L_157 ) ;
V_1105 = L_158 ;
F_291 ( V_36 , V_1105 ) ;
}
F_9 ( V_92 , L_159 ) ;
if( F_183 ( V_36 ) != 0 ) {
F_9 ( V_27 , L_160 ) ;
V_202 = - V_1106 ;
goto V_1107;
}
F_221 ( V_36 ) ;
F_242 ( V_36 ) ;
V_202 = F_292 ( V_36 ) ;
if ( V_202 )
goto V_1108;
F_9 ( V_92 , L_161 , V_36 -> V_103 ) ;
F_48 ( V_36 ) ;
F_9 ( V_92 , L_162 ) ;
return 0 ;
V_1108:
F_241 ( V_36 ) ;
F_142 ( V_7 -> V_624 ) ;
V_7 -> V_624 = NULL ;
F_143 ( V_36 ) ;
F_293 ( V_7 -> V_501 ) ;
F_64 ( 10 ) ;
V_1107:
F_294 ( V_36 ) ;
F_9 ( V_27 , L_163 ) ;
return V_202 ;
}
void F_215 ( struct V_6 * V_7 )
{
F_295 ( & V_7 -> V_114 ) ;
F_219 ( & V_7 -> V_634 ) ;
F_219 ( & V_7 -> V_466 ) ;
F_295 ( & V_7 -> V_471 ) ;
}
static void F_296 ( struct V_1091 * V_1092 )
{
struct V_35 * V_36 = F_297 ( V_1092 ) ;
struct V_6 * V_7 = F_17 ( V_36 ) ;
if( V_36 ) {
F_298 ( V_36 ) ;
F_9 ( V_877 , L_164 ) ;
F_51 ( V_36 ) ;
F_241 ( V_36 ) ;
F_142 ( V_7 -> V_624 ) ;
V_7 -> V_624 = NULL ;
F_143 ( V_36 ) ;
F_293 ( V_7 -> V_501 ) ;
F_64 ( 10 ) ;
}
F_294 ( V_36 ) ;
F_9 ( V_877 , L_165 ) ;
}
static int T_18 F_299 ( void )
{
int V_202 ;
#ifdef F_300
V_202 = F_301 () ;
if ( V_202 ) {
F_20 ( V_1109 L_166 , V_202 ) ;
return V_202 ;
}
#endif
V_202 = F_302 () ;
if ( V_202 ) {
F_20 ( V_1109 L_167 , V_202 ) ;
return V_202 ;
}
V_202 = F_303 () ;
if ( V_202 ) {
F_20 ( V_1109 L_168 ,
V_202 ) ;
return V_202 ;
}
V_202 = F_304 () ;
if ( V_202 ) {
F_20 ( V_1109 L_169 ,
V_202 ) ;
return V_202 ;
}
V_202 = F_305 () ;
if ( V_202 ) {
F_20 ( V_1109 L_170 , V_202 ) ;
return V_202 ;
}
F_20 ( V_1110 L_171 ) ;
F_20 ( V_1110 L_172 ) ;
F_9 ( V_92 , L_173 ) ;
F_9 ( V_92 , L_174 , V_1097 ) ;
F_39 () ;
return F_306 ( & V_1111 ) ;
}
static void T_19 F_307 ( void )
{
F_308 ( & V_1111 ) ;
F_9 ( V_877 , L_175 ) ;
}
void F_309 ( struct V_35 * V_36 , int V_1112 )
{
unsigned long V_168 ;
short V_1113 ;
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
F_100 ( & V_7 -> V_206 , V_168 ) ;
V_1113 = F_54 ( V_36 , V_1112 ) ;
F_103 ( & V_7 -> V_206 , V_168 ) ;
if( V_1113 )
F_310 ( V_7 -> V_12 ) ;
}
void F_146 ( struct V_35 * V_36 )
{
T_1 V_762 = 0x0 ;
struct V_6 * V_7 = (struct V_6 * ) F_17 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
V_762 = V_763 | V_764 ;
if ( ( ( V_265 == V_11 -> V_264 ) || ( V_266 == V_11 -> V_264 ) ) && ( V_7 -> V_12 -> V_906 != 2 ) )
{
V_762 |= V_1114 ;
V_762 |= V_1115 ;
}
else if ( ( V_11 -> V_129 == V_133 ) && ( V_11 -> V_264 & ( V_268 | V_267 ) ) )
{
V_762 |= V_1114 ;
V_762 |= V_1115 ;
}
V_11 -> V_1116 = 1 ;
if ( ( V_11 -> V_277 -> V_1117 & V_1118 ) || ! V_1119 )
{
V_11 -> V_1116 = 0 ;
V_762 &= ~ V_764 ;
}
F_9 ( V_837 , L_176 , V_28 , \
V_11 -> V_1116 , V_11 -> V_264 , V_762 ) ;
{
F_23 ( V_36 , V_766 , V_762 ) ;
}
}
void F_212 ( struct V_35 * V_36 ,
T_1 V_1120 ,
T_1 V_1121 ,
T_3 V_1122 ,
T_1 * V_834 ,
T_1 V_1123 ,
T_2 * V_1124 )
{
T_2 V_1125 = 0 ;
T_2 V_1126 = 0 ;
T_3 V_1127 = 0 ;
T_1 V_1 ;
if ( V_1120 >= V_1128 )
F_9 ( V_27 , L_177 ) ;
F_9 ( V_837 , L_178 , V_36 , V_1120 , V_1121 , V_1122 , V_834 ) ;
if ( V_1123 )
V_1127 |= V_1129 | ( V_1122 << 2 ) ;
else
V_1127 |= V_1129 | ( V_1122 << 2 ) | V_1121 ;
for( V_1 = 0 ; V_1 < V_857 ; V_1 ++ ) {
V_1125 = V_1 + V_857 * V_1120 ;
V_1125 |= V_41 | V_42 ;
if( V_1 == 0 ) {
V_1126 = ( T_2 ) ( * ( V_834 + 0 ) ) << 16 |
( T_2 ) ( * ( V_834 + 1 ) ) << 24 |
( T_2 ) V_1127 ;
F_13 ( V_36 , V_39 , V_1126 ) ;
F_13 ( V_36 , V_40 , V_1125 ) ;
}
else if( V_1 == 1 ) {
V_1126 = ( T_2 ) ( * ( V_834 + 2 ) ) |
( T_2 ) ( * ( V_834 + 3 ) ) << 8 |
( T_2 ) ( * ( V_834 + 4 ) ) << 16 |
( T_2 ) ( * ( V_834 + 5 ) ) << 24 ;
F_13 ( V_36 , V_39 , V_1126 ) ;
F_13 ( V_36 , V_40 , V_1125 ) ;
}
else {
if( V_1124 != NULL ) {
F_13 ( V_36 , V_39 , ( T_2 ) ( * ( V_1124 + V_1 - 2 ) ) ) ;
F_13 ( V_36 , V_40 , V_1125 ) ;
}
}
}
}
