static void F_1 ( void T_1 * V_1 , T_2 V_2 )
{
unsigned int V_3 ;
F_2 ( V_4 , V_2 ) ;
F_3 ( 1 ) ;
for ( V_3 = 0 ; V_3 < 100 ; V_3 ++ ) {
if ( ! ( F_4 ( V_4 ) & V_5 ) )
break;
F_3 ( 1 ) ;
}
if ( V_3 > 99 )
F_5 ( L_1 ) ;
}
static void F_6 ( void T_1 * V_1 , int V_6 , int V_7 , int V_8 )
{
F_1 ( V_1 , V_9 | V_10 |
( ( ( T_2 ) V_7 ) << V_11 ) | ( V_6 << V_12 ) |
( ( ( T_2 ) V_8 ) << V_13 ) ) ;
}
static int F_7 ( void T_1 * V_1 , int V_6 , int V_7 )
{
F_1 ( V_1 , V_9 | V_14 |
( ( ( T_2 ) V_7 ) << V_11 ) | ( V_6 << V_12 ) ) ;
return ( V_15 ) ( F_4 ( V_4 ) >> V_13 ) ;
}
static void F_8 ( struct V_16 * V_17 , int V_6 , int V_7 , int V_8 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
F_6 ( V_19 -> V_20 , V_6 , V_7 , V_8 ) ;
}
static int F_10 ( struct V_16 * V_17 , int V_6 , int V_7 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
return F_7 ( V_19 -> V_20 , V_6 , V_7 ) ;
}
static V_15 F_11 ( void T_1 * V_1 , int V_6 , int V_7 )
{
F_7 ( V_1 , V_6 , V_7 ) ;
return F_7 ( V_1 , V_6 , V_7 ) ;
}
static V_15 T_3 F_12 ( void T_1 * V_1 , T_2 V_7 )
{
V_15 V_21 = 0xffff ;
unsigned int V_3 ;
if ( ! ( F_4 ( V_22 ) & 0x0002 ) )
return 0 ;
F_2 ( V_23 , V_24 | V_25 | ( V_7 << 10 ) ) ;
for ( V_3 = 0 ; V_3 < 200 ; V_3 ++ ) {
if ( ! ( F_4 ( V_23 ) & V_24 ) ) {
V_21 = ( F_4 ( V_23 ) & 0xffff0000 ) >> 16 ;
break;
}
F_3 ( 1 ) ;
}
return V_21 ;
}
static void F_13 ( void T_1 * V_1 )
{
F_2 ( V_26 , 0x00 ) ;
F_2 ( V_27 , 0xffffffff ) ;
F_14 () ;
}
static void F_15 ( void T_1 * V_1 )
{
F_2 ( V_28 , 0x1a00 ) ;
F_2 ( V_29 , 0x1a00 ) ;
F_13 ( V_1 ) ;
}
static void F_16 ( struct V_30 * V_31 )
{
V_31 -> V_32 |= F_17 ( V_33 ) ;
}
static inline void F_18 ( struct V_30 * V_31 , T_2 V_34 )
{
T_2 V_35 = F_19 ( V_31 -> V_32 ) & V_33 ;
V_31 -> V_36 = 0x0 ;
V_31 -> V_32 = F_17 ( ( V_34 & V_37 ) | V_35 ) ;
F_20 () ;
V_31 -> V_38 = F_17 ( V_39 | V_40 ) ;
}
static inline void F_21 ( struct V_30 * V_31 , T_4 V_41 ,
T_2 V_34 )
{
V_31 -> V_42 = F_17 ( V_41 ) ;
F_18 ( V_31 , V_34 ) ;
}
static inline void F_22 ( struct V_30 * V_31 )
{
V_31 -> V_36 = 0x0 ;
V_31 -> V_42 = F_17 ( 0xdeadbeef ) ;
V_31 -> V_32 &= F_17 ( V_33 ) ;
F_20 () ;
V_31 -> V_38 = 0x0 ;
}
static struct V_43 * F_23 ( struct V_18 * V_19 ,
struct V_30 * V_31 )
{
T_2 V_34 = V_19 -> V_34 ;
struct V_43 * V_44 ;
T_4 V_41 ;
V_44 = F_24 ( V_19 -> V_17 , V_34 ) ;
if ( F_25 ( ! V_44 ) )
goto V_45;
V_41 = F_26 ( V_19 -> V_46 , V_44 -> V_21 , V_19 -> V_34 ,
V_47 ) ;
if ( F_27 ( V_19 -> V_46 , V_41 ) )
goto V_48;
F_21 ( V_31 , V_41 , V_34 ) ;
return V_44 ;
V_48:
F_28 ( V_44 ) ;
V_45:
F_22 ( V_31 ) ;
return NULL ;
}
static T_2 F_29 ( struct V_18 * V_19 , struct V_16 * V_17 ,
T_2 V_49 , T_2 V_50 )
{
T_2 V_51 ;
for ( V_51 = V_49 ; V_51 < V_50 ; V_51 ++ ) {
unsigned int V_3 = V_51 % V_52 ;
if ( V_19 -> V_53 [ V_3 ] )
continue;
V_19 -> V_53 [ V_3 ] = F_23 ( V_19 , V_19 -> V_54 + V_3 ) ;
if ( ! V_19 -> V_53 [ V_3 ] )
break;
}
return V_51 - V_49 ;
}
static bool F_30 ( struct V_18 * V_19 ,
struct V_43 * * V_43 , int V_55 ,
T_4 V_42 )
{
struct V_43 * V_44 ;
bool V_56 = false ;
if ( V_55 >= V_57 )
goto V_48;
V_44 = F_31 ( V_19 -> V_17 , V_55 ) ;
if ( ! V_44 )
goto V_48;
F_32 ( V_19 -> V_46 , V_42 , V_19 -> V_34 ,
V_47 ) ;
F_33 ( V_44 , V_43 [ 0 ] -> V_21 , V_55 ) ;
* V_43 = V_44 ;
V_56 = true ;
V_48:
return V_56 ;
}
static inline int F_34 ( T_2 V_38 , struct V_58 * V_59 )
{
#define F_35 (OVRUN | SHORT | LIMIT | MIIER | NIBON | COLON | ABORT)
if ( ( V_38 & V_60 ) && ! ( V_38 & F_35 ) )
return 0 ;
if ( ! ( V_38 & V_60 ) )
V_59 -> V_61 ++ ;
else if ( V_38 & V_62 )
V_59 -> V_63 ++ ;
else if ( V_38 & ( SHORT | V_64 ) )
V_59 -> V_65 ++ ;
else if ( V_38 & ( V_66 | V_67 | V_68 ) )
V_59 -> V_69 ++ ;
V_59 -> V_70 ++ ;
return - 1 ;
}
static int F_36 ( struct V_16 * V_17 ,
struct V_18 * V_19 , void T_1 * V_1 )
{
struct V_58 * V_59 = & V_17 -> V_59 ;
T_2 V_71 , V_72 = V_19 -> V_72 ;
T_2 V_73 , V_74 ;
V_71 = V_52 + V_19 -> V_75 - V_72 ;
V_71 = F_37 ( V_71 , ( T_2 ) V_17 -> V_76 ) ;
for (; V_71 > 0 ; V_71 -- , V_72 ++ ) {
unsigned int V_77 = V_72 % V_52 ;
struct V_30 * V_31 = V_19 -> V_54 + V_77 ;
T_2 V_38 ;
if ( F_19 ( V_31 -> V_38 ) & V_39 )
break;
V_38 = F_19 ( V_31 -> V_36 ) ;
if ( F_34 ( V_38 , V_59 ) < 0 )
F_18 ( V_31 , V_19 -> V_34 ) ;
else {
struct V_43 * V_44 = V_19 -> V_53 [ V_77 ] ;
T_4 V_42 = F_19 ( V_31 -> V_42 ) ;
int V_55 = ( V_38 & V_78 ) - 4 ;
struct V_46 * V_79 = V_19 -> V_46 ;
if ( F_25 ( V_55 > V_19 -> V_34 ) ) {
F_38 ( V_19 , V_80 , V_17 ,
L_2 , V_38 ) ;
V_59 -> V_81 ++ ;
V_59 -> V_65 ++ ;
F_18 ( V_31 , V_19 -> V_34 ) ;
continue;
}
if ( F_30 ( V_19 , & V_44 , V_55 , V_42 ) ) {
F_39 ( V_79 , V_42 ,
V_19 -> V_34 , V_47 ) ;
F_18 ( V_31 , V_19 -> V_34 ) ;
} else {
F_40 ( V_79 , V_42 , V_19 -> V_34 ,
V_47 ) ;
V_19 -> V_53 [ V_77 ] = NULL ;
F_22 ( V_31 ) ;
}
F_41 ( V_44 , V_55 ) ;
V_44 -> V_82 = F_42 ( V_44 , V_17 ) ;
F_43 ( V_44 ) ;
V_59 -> V_83 ++ ;
V_59 -> V_84 += V_55 ;
if ( ( V_38 & V_85 ) == V_86 )
V_59 -> V_87 ++ ;
}
}
V_74 = V_72 - V_19 -> V_72 ;
V_19 -> V_72 = V_72 ;
V_73 = F_29 ( V_19 , V_17 , V_19 -> V_75 , V_19 -> V_72 ) ;
if ( ! V_73 && V_74 )
F_38 ( V_19 , V_80 , V_17 , L_3 ) ;
V_19 -> V_75 += V_73 ;
if ( ( V_19 -> V_75 + V_52 ) == V_19 -> V_72 )
F_44 ( V_19 , V_80 , V_17 , L_4 ) ;
return V_74 ;
}
static void F_45 ( struct V_46 * V_79 , struct V_43 * V_44 ,
struct V_88 * V_31 )
{
unsigned int V_89 ;
V_89 = V_44 -> V_89 < V_90 ? V_90 : V_44 -> V_89 ;
F_40 ( V_79 , F_19 ( V_31 -> V_42 ) , V_89 , V_91 ) ;
memset ( V_31 , 0x00 , sizeof( * V_31 ) ) ;
}
static inline int F_46 ( T_2 V_38 , struct V_58 * V_59 )
{
#define F_47 (WND | TABRT | FIFO | LINK)
if ( ! F_25 ( V_38 & F_47 ) )
return 0 ;
if ( V_38 & V_92 )
V_59 -> V_93 ++ ;
if ( V_38 & V_94 )
V_59 -> V_95 ++ ;
if ( V_38 & V_96 )
V_59 -> V_97 ++ ;
if ( V_38 & V_98 )
V_59 -> V_99 ++ ;
V_59 -> V_100 ++ ;
return - 1 ;
}
static void F_48 ( struct V_16 * V_17 ,
struct V_18 * V_19 , void T_1 * V_1 )
{
struct V_58 * V_59 = & V_17 -> V_59 ;
T_2 V_101 , V_102 = V_19 -> V_102 ;
unsigned int V_103 ;
F_49 () ;
V_101 = V_19 -> V_104 - V_102 ;
V_103 = ( V_101 == V_105 ) ;
for (; V_101 ; V_101 -- , V_102 ++ ) {
unsigned int V_77 = V_102 % V_105 ;
struct V_88 * V_106 = V_19 -> V_107 + V_77 ;
T_2 V_38 = F_19 ( V_106 -> V_38 ) ;
struct V_43 * V_44 ;
if ( V_38 & V_39 )
break;
V_44 = V_19 -> V_108 [ V_77 ] ;
if ( F_50 ( F_46 ( V_38 , V_59 ) == 0 ) ) {
V_59 -> V_109 ++ ;
V_59 -> V_110 += V_44 -> V_89 ;
V_59 -> V_111 += ( ( V_38 & V_112 ) - 1 ) ;
}
F_45 ( V_19 -> V_46 , V_44 , V_106 ) ;
V_19 -> V_108 [ V_77 ] = NULL ;
F_51 ( V_44 ) ;
}
if ( V_19 -> V_102 != V_102 ) {
V_19 -> V_102 = V_102 ;
F_52 () ;
if ( V_103 )
F_53 ( V_17 ) ;
}
}
static T_5 F_54 ( int V_113 , void * V_114 )
{
struct V_16 * V_17 = V_114 ;
struct V_18 * V_19 = F_9 ( V_17 ) ;
void T_1 * V_1 = V_19 -> V_20 ;
unsigned int V_115 = 0 ;
T_2 V_38 ;
V_38 = F_4 ( V_27 ) ;
if ( ( V_38 == 0xffffffff ) || ! V_38 )
goto V_48;
V_115 = 1 ;
if ( F_25 ( ! F_55 ( V_17 ) ) ) {
F_15 ( V_1 ) ;
goto V_48;
}
F_2 ( V_27 , V_38 ) ;
if ( V_38 & V_116 ) {
F_38 ( V_19 , V_80 , V_17 , L_5 ) ;
F_56 ( & V_19 -> V_117 ) ;
F_57 ( & V_19 -> V_118 ) ;
}
if ( V_38 & V_119 )
F_36 ( V_17 , V_19 , V_1 ) ;
if ( V_38 & V_120 )
F_48 ( V_17 , V_19 , V_1 ) ;
V_48:
return F_58 ( V_115 ) ;
}
static void F_59 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
struct V_46 * V_79 = V_19 -> V_46 ;
F_60 ( V_79 -> V_113 ) ;
F_54 ( V_79 -> V_113 , V_17 ) ;
F_61 ( V_79 -> V_113 ) ;
}
static void F_62 ( struct V_18 * V_19 ,
struct V_43 * * V_43 , struct V_30 * V_31 )
{
struct V_46 * V_79 = V_19 -> V_46 ;
F_40 ( V_79 , F_19 ( V_31 -> V_42 ) , V_19 -> V_34 ,
V_47 ) ;
F_63 ( * V_43 ) ;
* V_43 = NULL ;
F_22 ( V_31 ) ;
}
static void F_64 ( struct V_18 * V_19 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_52 ; V_3 ++ ) {
if ( ! V_19 -> V_53 [ V_3 ] )
continue;
F_62 ( V_19 , V_19 -> V_53 + V_3 , V_19 -> V_54 + V_3 ) ;
}
}
static void F_65 ( struct V_18 * V_19 )
{
V_19 -> V_102 = V_19 -> V_75 = V_19 -> V_104 = V_19 -> V_72 = 0 ;
}
static int F_66 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
F_65 ( V_19 ) ;
memset ( V_19 -> V_108 , 0x0 , V_105 * sizeof( struct V_43 * ) ) ;
memset ( V_19 -> V_53 , 0x0 , V_52 * sizeof( struct V_43 * ) ) ;
if ( F_29 ( V_19 , V_17 , 0 , V_52 ) != V_52 )
goto V_121;
F_16 ( V_19 -> V_54 + V_52 - 1 ) ;
return 0 ;
V_121:
F_64 ( V_19 ) ;
return - V_122 ;
}
static void F_67 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
void T_1 * V_1 = V_19 -> V_20 ;
unsigned long V_123 ;
T_2 V_124 [ 2 ] ;
V_15 V_125 ;
if ( V_17 -> V_123 & V_126 ) {
V_125 =
V_127 | V_128 | V_129 |
V_130 ;
V_124 [ 1 ] = V_124 [ 0 ] = 0xffffffff ;
} else if ( ( F_68 ( V_17 ) > V_131 ) ||
( V_17 -> V_123 & V_132 ) ) {
V_125 = V_127 | V_128 | V_129 ;
V_124 [ 1 ] = V_124 [ 0 ] = 0xffffffff ;
} else {
struct V_133 * V_134 ;
V_125 = V_127 | V_129 ;
V_124 [ 1 ] = V_124 [ 0 ] = 0 ;
F_69 (ha, dev) {
int V_135 =
F_70 ( V_136 , V_134 -> V_42 ) & 0x3f ;
V_124 [ V_135 >> 5 ] |= 1 << ( V_135 & 31 ) ;
V_125 |= V_128 ;
}
}
F_71 ( & V_19 -> V_137 , V_123 ) ;
F_72 ( V_138 , V_125 | 0x2 ) ;
F_2 ( V_139 , V_124 [ 0 ] ) ;
F_2 ( V_139 + 4 , V_124 [ 1 ] ) ;
F_73 ( & V_19 -> V_137 , V_123 ) ;
}
static void F_74 ( void T_1 * V_1 )
{
F_2 ( V_140 , 0x8000 ) ;
F_14 () ;
F_2 ( V_140 , 0x0 ) ;
F_15 ( V_1 ) ;
}
static void F_75 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
void T_1 * V_1 = V_19 -> V_20 ;
F_74 ( V_1 ) ;
F_2 ( V_141 , V_19 -> V_142 ) ;
F_2 ( V_143 , V_19 -> V_144 ) ;
F_2 ( V_27 , 0xffffffff ) ;
F_2 ( V_26 , 0x0 ) ;
F_2 ( V_4 , 0x0 ) ;
F_2 ( V_145 , 0x60 ) ;
F_72 ( V_138 , 0x02 ) ;
F_2 ( V_139 , 0x0 ) ;
F_2 ( 0x6c , 0x0 ) ;
F_2 ( V_146 , 0x0 ) ;
F_2 ( V_147 , 0x0 ) ;
F_14 () ;
F_67 ( V_17 ) ;
F_2 ( V_26 , V_148 ) ;
F_2 ( V_28 , 0x1a00 | V_149 ) ;
F_2 ( V_29 , 0x1a1d ) ;
F_76 ( V_17 ) ;
}
static void F_77 ( struct V_150 * V_151 )
{
struct V_18 * V_19 =
F_78 ( V_151 , struct V_18 , V_118 ) ;
struct V_16 * V_17 = V_19 -> V_17 ;
void T_1 * V_1 = V_19 -> V_20 ;
int V_6 = V_19 -> V_152 . V_6 ;
V_15 V_8 ;
F_79 () ;
if ( ! F_55 ( V_17 ) )
goto V_153;
V_8 = F_7 ( V_1 , V_6 , V_154 ) ;
if ( V_8 & V_155 ) {
F_80 ( & V_19 -> V_117 , V_156 + V_157 / 10 ) ;
goto V_153;
}
V_8 = F_11 ( V_1 , V_6 , V_158 ) ;
if ( ! ( V_8 & V_159 ) && V_19 -> V_160 != V_161 ) {
F_81 ( V_17 ) ;
F_82 ( V_19 , V_162 , V_17 , L_6 ) ;
V_19 -> V_160 = V_161 ;
} else if ( ( V_8 & V_163 ) && V_19 -> V_160 != V_164 ) {
struct {
int V_8 ;
T_2 V_2 ;
const char * V_165 ;
} V_166 [] = {
{ V_167 , 0x07000c00 | 0x00001000 ,
L_7 } ,
{ V_168 , 0x07000c00 ,
L_8 } ,
{ V_169 , 0x04000800 | 0x00001000 ,
L_9 } ,
{ V_170 , 0x04000800 ,
L_10 } ,
{ V_171 , 0x04000400 | 0x00001000 ,
L_11 } ,
{ V_172 , 0x04000400 ,
L_12 } ,
{ 0 , 0x04000400 , L_13 }
} , * V_173 = NULL ;
V_15 V_174 , V_175 , V_176 , V_177 ;
V_8 = F_7 ( V_1 , V_6 , 0x1f ) ;
F_38 ( V_19 , V_162 , V_17 , L_14 , V_8 ) ;
V_8 = F_7 ( V_1 , V_6 , V_178 ) ;
V_174 = F_7 ( V_1 , V_6 , V_179 ) ;
V_175 = F_7 ( V_1 , V_6 , V_180 ) ;
F_38 ( V_19 , V_162 , V_17 , L_15 ,
V_8 , V_174 , V_175 ) ;
if ( V_8 & V_181 && V_175 & V_182 ) {
V_176 = F_7 ( V_1 , V_6 , V_183 ) ;
V_177 = F_7 ( V_1 , V_6 , V_184 ) ;
V_8 = ( V_176 & ( V_177 >> 2 ) ) ;
if ( V_8 & V_185 )
V_173 = V_166 ;
else if ( V_8 & V_186 )
V_173 = V_166 + 1 ;
}
if ( ! V_173 ) {
V_8 &= V_174 ;
for ( V_173 = V_166 ; V_173 -> V_8 ; V_173 ++ ) {
if ( ( V_8 & V_173 -> V_8 ) == V_173 -> V_8 )
break;
}
}
V_173 -> V_2 |= F_4 ( V_187 ) & ~ 0x0f001c00 ;
if ( ( V_19 -> V_188 & V_189 ) &&
( V_19 -> V_188 & V_190 ) ) {
F_6 ( V_1 , V_6 , 0x18 , 0xf1c7 ) ;
F_83 ( 200 ) ;
F_6 ( V_1 , V_6 , 0x1c , 0x8c00 ) ;
V_173 -> V_2 |= 0x03000000 ;
}
F_2 ( V_187 , V_173 -> V_2 ) ;
if ( V_19 -> V_188 & V_189 ) {
F_2 ( V_191 , 0x0441 ) ;
F_2 ( V_191 , 0x0440 ) ;
}
V_19 -> V_192 = V_173 -> V_8 ;
F_38 ( V_19 , V_162 , V_17 , L_16 , V_173 -> V_165 ) ;
F_84 ( V_17 ) ;
V_19 -> V_160 = V_164 ;
} else if ( ! ( V_8 & V_163 ) && V_19 -> V_160 != V_161 )
V_19 -> V_160 = V_193 ;
F_80 ( & V_19 -> V_117 , V_156 + V_194 ) ;
V_153:
F_85 () ;
}
static void F_86 ( unsigned long V_195 )
{
struct V_16 * V_17 = (struct V_16 * ) V_195 ;
struct V_18 * V_19 = F_9 ( V_17 ) ;
if ( F_50 ( F_55 ( V_17 ) ) )
F_57 ( & V_19 -> V_118 ) ;
}
static inline void F_87 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
F_88 ( & V_19 -> V_117 ) ;
}
static inline void F_89 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
struct V_196 * V_117 = & V_19 -> V_117 ;
F_90 ( V_117 ) ;
V_117 -> V_197 = V_156 + V_194 ;
V_117 -> V_21 = ( unsigned long ) V_17 ;
V_117 -> V_198 = F_86 ;
F_91 ( V_117 ) ;
}
static void F_92 ( struct V_18 * V_19 ,
struct V_16 * V_17 )
{
unsigned int V_199 = V_17 -> V_199 ;
V_19 -> V_34 = ( V_199 > V_200 ) ? V_199 + V_201 + 8 : V_200 ;
if ( V_19 -> V_34 & 0x07 ) {
V_19 -> V_34 += 8 ;
V_19 -> V_34 &= V_37 ;
}
}
static int F_93 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
struct V_46 * V_79 = V_19 -> V_46 ;
int V_202 = - V_122 ;
F_92 ( V_19 , V_17 ) ;
V_19 -> V_107 = F_94 ( V_79 , V_203 , & V_19 -> V_142 ) ;
if ( ! V_19 -> V_107 )
goto V_48;
V_19 -> V_54 = F_94 ( V_79 , V_204 , & V_19 -> V_144 ) ;
if ( ! V_19 -> V_54 )
goto V_205;
V_202 = F_66 ( V_17 ) ;
if ( V_202 < 0 )
goto V_206;
F_89 ( V_17 ) ;
V_202 = F_95 ( V_17 -> V_113 , F_54 , V_207 , V_17 -> V_208 , V_17 ) ;
if ( V_202 < 0 )
goto V_209;
F_75 ( V_17 ) ;
V_48:
return V_202 ;
V_209:
F_87 ( V_17 ) ;
F_64 ( V_19 ) ;
V_206:
F_96 ( V_19 -> V_46 , V_204 , V_19 -> V_54 ,
V_19 -> V_144 ) ;
V_205:
F_96 ( V_19 -> V_46 , V_203 , V_19 -> V_107 ,
V_19 -> V_142 ) ;
goto V_48;
}
static void F_97 ( struct V_18 * V_19 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_105 ; V_3 ++ ) {
struct V_43 * V_44 = V_19 -> V_108 [ V_3 ] ;
if ( ! V_44 )
continue;
F_45 ( V_19 -> V_46 , V_44 , V_19 -> V_107 + V_3 ) ;
V_19 -> V_108 [ V_3 ] = NULL ;
F_63 ( V_44 ) ;
V_19 -> V_17 -> V_59 . V_210 ++ ;
}
V_19 -> V_104 = V_19 -> V_102 = 0 ;
}
static void F_98 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
void T_1 * V_1 = V_19 -> V_20 ;
unsigned int V_211 = 0 ;
F_87 ( V_17 ) ;
F_99 ( V_17 ) ;
do {
F_100 ( & V_19 -> V_137 ) ;
F_15 ( V_1 ) ;
F_101 ( & V_19 -> V_137 ) ;
F_102 ( V_17 -> V_113 ) ;
if ( ! V_211 )
V_211 ++ ;
F_103 () ;
} while ( F_4 ( V_26 ) );
F_97 ( V_19 ) ;
F_64 ( V_19 ) ;
}
static int F_104 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
struct V_46 * V_79 = V_19 -> V_46 ;
F_98 ( V_17 ) ;
F_105 ( V_17 -> V_113 , V_17 ) ;
F_96 ( V_79 , V_203 , V_19 -> V_107 , V_19 -> V_142 ) ;
F_96 ( V_79 , V_204 , V_19 -> V_54 , V_19 -> V_144 ) ;
V_19 -> V_107 = NULL ;
V_19 -> V_54 = NULL ;
return 0 ;
}
static T_6 F_106 ( struct V_43 * V_44 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
void T_1 * V_1 = V_19 -> V_20 ;
T_2 V_89 , V_77 , V_102 ;
struct V_88 * V_31 ;
T_4 V_41 ;
if ( F_25 ( V_44 -> V_89 < V_90 ) ) {
if ( F_107 ( V_44 , V_90 ) ) {
V_17 -> V_59 . V_210 ++ ;
goto V_48;
}
V_89 = V_90 ;
} else {
V_89 = V_44 -> V_89 ;
}
V_77 = V_19 -> V_104 % V_105 ;
V_31 = V_19 -> V_107 + V_77 ;
if ( F_25 ( F_19 ( V_31 -> V_38 ) & V_39 ) ) {
F_99 ( V_17 ) ;
F_108 ( V_19 , V_212 , V_17 ,
L_17 ) ;
return V_213 ;
}
V_41 = F_26 ( V_19 -> V_46 , V_44 -> V_21 , V_89 , V_91 ) ;
if ( F_27 ( V_19 -> V_46 , V_41 ) ) {
F_108 ( V_19 , V_212 , V_17 ,
L_18 ) ;
return V_213 ;
}
V_19 -> V_108 [ V_77 ] = V_44 ;
V_31 -> V_36 = F_17 ( V_89 ) ;
V_31 -> V_42 = F_17 ( V_41 ) ;
V_31 -> V_32 = F_17 ( V_89 ) ;
if ( V_77 == ( V_105 - 1 ) )
V_31 -> V_32 |= F_17 ( V_33 ) ;
F_20 () ;
V_31 -> V_38 = F_17 ( V_39 | V_40 | V_214 | V_215 | V_216 ) ;
if ( V_19 -> V_192 & ( V_168 | V_170 | V_172 ) ) {
V_31 -> V_38 |= F_17 ( V_217 | V_218 | V_219 ) ;
if ( V_19 -> V_192 & ( V_168 | V_167 ) )
V_31 -> V_38 |= F_17 ( V_220 | V_221 ) ;
}
V_19 -> V_104 ++ ;
F_52 () ;
F_2 ( V_28 , 0x1a00 | V_222 | V_149 ) ;
V_102 = V_19 -> V_102 ;
if ( ( V_19 -> V_104 - V_105 ) == V_102 ) {
F_99 ( V_17 ) ;
F_49 () ;
if ( V_102 != V_19 -> V_102 )
F_53 ( V_17 ) ;
}
V_48:
return V_223 ;
}
static void F_109 ( struct V_224 * V_225 )
{
struct V_226 * V_51 , * V_227 ;
F_110 (cur, next, first_phy, list) {
F_111 ( V_51 ) ;
}
}
static V_15 F_112 ( struct V_16 * V_17 )
{
struct V_226 * V_228 , * V_229 , * V_230 , * V_231 ;
struct V_18 * V_19 = F_9 ( V_17 ) ;
struct V_232 * V_152 = & V_19 -> V_152 ;
void T_1 * V_1 = V_19 -> V_20 ;
V_15 V_38 ;
V_229 = V_230 = V_231 = NULL ;
F_113 (phy, &tp->first_phy, list) {
V_38 = F_11 ( V_1 , V_228 -> V_6 , V_158 ) ;
if ( ( V_38 & V_163 ) &&
! V_230 &&
( V_228 -> type != V_233 ) ) {
V_230 = V_228 ;
} else {
V_38 = F_7 ( V_1 , V_228 -> V_6 , V_154 ) ;
F_6 ( V_1 , V_228 -> V_6 , V_154 ,
V_38 | V_234 | V_235 ) ;
if ( V_228 -> type == V_236 )
V_229 = V_228 ;
else if ( V_228 -> type == V_237 )
V_231 = V_228 ;
}
}
if ( ! V_230 ) {
if ( V_229 )
V_230 = V_229 ;
else if ( V_231 )
V_230 = V_231 ;
else
V_230 = F_114 ( & V_19 -> V_225 ,
struct V_226 , V_238 ) ;
}
if ( V_152 -> V_6 != V_230 -> V_6 ) {
V_152 -> V_6 = V_230 -> V_6 ;
if ( F_115 ( V_19 ) )
F_116 ( L_19 ,
F_117 ( V_19 -> V_46 ) , V_152 -> V_6 ) ;
}
V_38 = F_7 ( V_1 , V_152 -> V_6 , V_154 ) ;
V_38 &= ( ~ V_235 ) ;
F_6 ( V_1 , V_152 -> V_6 , V_154 , V_38 ) ;
V_38 = F_11 ( V_1 , V_152 -> V_6 , V_158 ) ;
return V_38 ;
}
static void F_118 ( struct V_16 * V_17 , struct V_18 * V_19 ,
struct V_226 * V_228 , unsigned int V_6 ,
V_15 V_239 )
{
void T_1 * V_1 = V_19 -> V_20 ;
struct V_240 * V_173 ;
F_119 ( & V_228 -> V_238 ) ;
V_228 -> V_38 = V_239 ;
V_228 -> V_6 = V_6 ;
V_228 -> V_241 [ 0 ] = F_7 ( V_1 , V_6 , V_242 ) ;
V_228 -> V_241 [ 1 ] = F_7 ( V_1 , V_6 , V_243 ) ;
for ( V_173 = V_244 ; V_173 -> type ; V_173 ++ ) {
if ( ( V_173 -> V_241 [ 0 ] == V_228 -> V_241 [ 0 ] ) &&
( V_173 -> V_241 [ 1 ] == ( V_228 -> V_241 [ 1 ] & 0xfff0 ) ) ) {
break;
}
}
if ( V_173 -> V_241 [ 1 ] ) {
V_228 -> type = ( V_173 -> type == V_245 ) ?
( ( V_239 & ( V_246 | V_247 ) ) ?
V_237 : V_236 ) : V_173 -> type ;
V_19 -> V_188 |= V_173 -> V_248 ;
if ( F_115 ( V_19 ) )
F_116 ( L_20 ,
F_117 ( V_19 -> V_46 ) , V_173 -> V_208 , V_6 ) ;
} else {
V_228 -> type = V_233 ;
if ( F_115 ( V_19 ) )
F_116 ( L_21 ,
F_117 ( V_19 -> V_46 ) ,
V_228 -> V_241 [ 0 ] , ( V_228 -> V_241 [ 1 ] & 0xfff0 ) , V_6 ) ;
}
}
static void F_120 ( struct V_18 * V_19 )
{
if ( V_19 -> V_188 & V_249 ) {
void T_1 * V_1 = V_19 -> V_20 ;
int V_6 = V_19 -> V_152 . V_6 ;
V_15 V_7 [ 2 ] [ 2 ] = {
{ 0x808b , 0x0ce1 } ,
{ 0x808f , 0x0c60 }
} , * V_173 ;
V_173 = ( V_19 -> V_188 & V_189 ) ? V_7 [ 0 ] : V_7 [ 1 ] ;
F_6 ( V_1 , V_6 , 0x1b , V_173 [ 0 ] ) ;
F_83 ( 200 ) ;
F_6 ( V_1 , V_6 , 0x14 , V_173 [ 1 ] ) ;
F_83 ( 200 ) ;
}
}
static int T_3 F_121 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
struct V_232 * V_152 = & V_19 -> V_152 ;
void T_1 * V_1 = V_19 -> V_20 ;
int V_6 ;
int V_202 = 0 ;
F_119 ( & V_19 -> V_225 ) ;
for ( V_6 = 0 ; V_6 < V_250 ; V_6 ++ ) {
struct V_226 * V_228 ;
V_15 V_38 ;
V_38 = F_11 ( V_1 , V_6 , V_158 ) ;
if ( V_38 == 0xffff || V_38 == 0x0000 )
continue;
V_228 = F_122 ( sizeof( * V_228 ) , V_251 ) ;
if ( ! V_228 ) {
F_109 ( & V_19 -> V_225 ) ;
V_202 = - V_122 ;
goto V_48;
}
F_118 ( V_17 , V_19 , V_228 , V_6 , V_38 ) ;
F_123 ( & V_19 -> V_225 , & V_228 -> V_238 ) ;
}
if ( F_124 ( & V_19 -> V_225 ) ) {
if ( F_115 ( V_19 ) )
F_116 ( L_22 ,
F_117 ( V_19 -> V_46 ) ) ;
V_202 = - V_252 ;
goto V_48;
}
F_112 ( V_17 ) ;
F_120 ( V_19 ) ;
V_152 -> V_17 = V_17 ;
V_152 -> F_7 = F_10 ;
V_152 -> F_6 = F_8 ;
V_152 -> V_253 = V_254 ;
V_152 -> V_255 = V_256 ;
V_48:
return V_202 ;
}
static void F_125 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
F_109 ( & V_19 -> V_225 ) ;
}
static void F_126 ( struct V_46 * V_79 )
{
struct V_16 * V_17 = F_127 ( V_79 ) ;
struct V_18 * V_19 = F_9 ( V_17 ) ;
F_128 ( V_19 -> V_20 ) ;
F_129 ( V_79 ) ;
F_130 ( V_79 ) ;
F_131 ( V_17 ) ;
}
static struct V_16 * T_3 F_132 ( struct V_46 * V_79 )
{
struct V_18 * V_19 ;
struct V_16 * V_17 ;
void T_1 * V_1 ;
int V_202 ;
V_17 = F_133 ( sizeof( * V_19 ) ) ;
if ( ! V_17 ) {
if ( F_134 ( & V_257 ) )
F_5 ( L_23 ) ;
V_202 = - V_122 ;
goto V_258;
}
F_135 ( V_17 , & V_79 -> V_17 ) ;
V_19 = F_9 ( V_17 ) ;
V_19 -> V_17 = V_17 ;
V_19 -> V_259 = F_136 ( V_257 . V_259 , V_260 ) ;
V_202 = F_137 ( V_79 ) ;
if ( V_202 < 0 ) {
if ( F_115 ( V_19 ) )
F_5 ( L_24 , F_117 ( V_79 ) ) ;
goto V_261;
}
V_202 = - V_262 ;
if ( ! ( F_138 ( V_79 , 0 ) & V_263 ) ) {
if ( F_115 ( V_19 ) )
F_5 ( L_25 ,
F_117 ( V_79 ) ) ;
goto V_264;
}
if ( F_139 ( V_79 , 0 ) < V_265 ) {
if ( F_115 ( V_19 ) )
F_5 ( L_26 ,
F_117 ( V_79 ) ) ;
goto V_264;
}
V_202 = F_140 ( V_79 , V_266 ) ;
if ( V_202 < 0 ) {
if ( F_115 ( V_19 ) )
F_5 ( L_27 ,
F_117 ( V_79 ) ) ;
goto V_264;
}
V_202 = F_141 ( V_79 , F_142 ( 32 ) ) ;
if ( V_202 < 0 ) {
if ( F_115 ( V_19 ) )
F_5 ( L_28 ,
F_117 ( V_79 ) ) ;
goto V_267;
}
F_143 ( V_79 ) ;
V_1 = F_144 ( F_145 ( V_79 , 0 ) , V_265 ) ;
if ( ! V_1 ) {
if ( F_115 ( V_19 ) )
F_5 ( L_29 ,
F_117 ( V_79 ) ) ;
V_202 = - V_252 ;
goto V_267;
}
V_19 -> V_46 = V_79 ;
V_19 -> V_20 = V_1 ;
V_19 -> V_160 = V_193 ;
F_13 ( V_1 ) ;
F_74 ( V_1 ) ;
V_48:
return V_17 ;
V_267:
F_129 ( V_79 ) ;
V_264:
F_130 ( V_79 ) ;
V_261:
F_131 ( V_17 ) ;
V_258:
V_17 = F_146 ( V_202 ) ;
goto V_48;
}
static void F_147 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
void T_1 * V_1 = V_19 -> V_20 ;
T_7 V_268 ;
V_268 = F_148 ( V_28 ) ;
if ( V_268 & V_149 )
F_149 ( V_28 , V_268 & ~ V_149 ) ;
F_38 ( V_19 , V_212 , V_17 , L_30 ,
F_4 ( V_28 ) , F_4 ( V_269 ) ) ;
F_2 ( V_26 , 0x0000 ) ;
F_100 ( & V_19 -> V_137 ) ;
F_97 ( V_19 ) ;
F_101 ( & V_19 -> V_137 ) ;
F_75 ( V_17 ) ;
F_53 ( V_17 ) ;
}
static void F_150 ( struct V_18 * V_19 , T_7 V_7 )
{
V_19 -> V_188 |= ( V_7 & 0x80 ) ? V_189 : 0 ;
}
static int T_3 F_151 ( struct V_46 * V_79 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
void T_1 * V_1 = V_19 -> V_20 ;
V_15 V_270 ;
int V_3 ;
if ( F_115 ( V_19 ) )
F_116 ( L_31 , F_117 ( V_79 ) ) ;
V_270 = ( V_15 ) F_12 ( V_1 , V_271 ) ;
if ( ( V_270 == 0xffff ) || ( V_270 == 0x0000 ) ) {
if ( F_115 ( V_19 ) )
F_116 ( L_32 ,
F_117 ( V_79 ) , V_270 ) ;
return - V_252 ;
}
for ( V_3 = 0 ; V_3 < V_272 / 2 ; V_3 ++ ) {
V_15 V_273 = F_12 ( V_1 , V_274 + V_3 ) ;
( ( V_275 * ) V_17 -> V_276 ) [ V_3 ] = F_152 ( V_273 ) ;
}
F_150 ( V_19 , F_12 ( V_1 , V_277 ) ) ;
return 0 ;
}
static int T_3 F_153 ( struct V_46 * V_79 ,
struct V_16 * V_17 )
{
static const V_15 T_8 V_278 [] = { 0x0965 , 0x0966 , 0x0968 } ;
struct V_18 * V_19 = F_9 ( V_17 ) ;
struct V_46 * V_279 ;
T_7 V_7 , V_268 ;
unsigned int V_3 ;
if ( F_115 ( V_19 ) )
F_116 ( L_33 , F_117 ( V_79 ) ) ;
for ( V_3 = 0 ; V_3 < F_154 ( V_278 ) ; V_3 ++ ) {
V_279 = F_155 ( V_280 , V_278 [ V_3 ] , NULL ) ;
if ( V_279 )
break;
}
if ( ! V_279 ) {
if ( F_115 ( V_19 ) )
F_116 ( L_34 ,
F_117 ( V_79 ) ) ;
return - V_252 ;
}
F_156 ( V_279 , 0x48 , & V_268 ) ;
V_7 = ( V_268 & ~ 0x02 ) ;
F_157 ( V_279 , 0x48 , V_7 ) ;
F_83 ( 50 ) ;
F_156 ( V_279 , 0x48 , & V_7 ) ;
for ( V_3 = 0 ; V_3 < V_272 ; V_3 ++ ) {
F_158 ( 0x9 + V_3 , 0x78 ) ;
V_17 -> V_276 [ V_3 ] = F_159 ( 0x79 ) ;
}
F_158 ( 0x12 , 0x78 ) ;
V_7 = F_159 ( 0x79 ) ;
F_150 ( V_19 , V_7 ) ;
F_157 ( V_279 , 0x48 , V_268 ) ;
F_160 ( V_279 ) ;
return 0 ;
}
static inline void F_161 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
void T_1 * V_1 = V_19 -> V_20 ;
V_15 V_2 ;
int V_3 ;
V_2 = F_162 ( V_138 ) ;
F_72 ( V_138 , V_2 & ~ 0x0f00 ) ;
for ( V_3 = 0 ; V_3 < V_272 ; V_3 ++ )
F_149 ( V_281 + V_3 , V_17 -> V_276 [ V_3 ] ) ;
F_72 ( V_138 , V_2 ) ;
F_14 () ;
}
static int T_3 F_163 ( struct V_46 * V_79 ,
struct V_16 * V_17 )
{
int V_202 ;
V_202 = F_151 ( V_79 , V_17 ) ;
if ( V_202 < 0 ) {
T_7 V_7 ;
F_156 ( V_79 , 0x73 , & V_7 ) ;
if ( V_7 & 0x00000001 )
V_202 = F_153 ( V_79 , V_17 ) ;
}
return V_202 ;
}
static void F_164 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
void T_1 * V_1 = V_19 -> V_20 ;
int V_6 = V_19 -> V_152 . V_6 ;
int V_8 ;
F_38 ( V_19 , V_162 , V_17 , L_35 ) ;
V_8 = F_7 ( V_1 , V_6 , V_179 ) ;
F_6 ( V_1 , V_6 , V_179 , ( V_8 & V_282 ) |
V_283 | V_284 |
V_285 | V_286 ) ;
F_6 ( V_1 , V_6 , V_183 , V_185 ) ;
F_6 ( V_1 , V_6 , V_154 ,
V_234 | V_287 | V_155 ) ;
}
static int F_165 ( struct V_16 * V_17 , struct V_288 * V_289 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
return F_166 ( & V_19 -> V_152 , V_289 ) ;
}
static int F_167 ( struct V_16 * V_17 , struct V_288 * V_289 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
return F_168 ( & V_19 -> V_152 , V_289 ) ;
}
static void F_169 ( struct V_16 * V_17 ,
struct V_290 * V_291 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
strcpy ( V_291 -> V_292 , V_266 ) ;
strcpy ( V_291 -> V_293 , V_294 ) ;
strcpy ( V_291 -> V_295 , F_117 ( V_19 -> V_46 ) ) ;
}
static int F_170 ( struct V_16 * V_17 )
{
return V_265 ;
}
static void F_171 ( struct V_16 * V_17 , struct V_296 * V_297 ,
void * V_173 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
unsigned long V_123 ;
if ( V_297 -> V_89 > V_265 )
V_297 -> V_89 = V_265 ;
F_71 ( & V_19 -> V_137 , V_123 ) ;
F_172 ( V_173 , V_19 -> V_20 , V_297 -> V_89 ) ;
F_73 ( & V_19 -> V_137 , V_123 ) ;
}
static int F_173 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
return F_174 ( & V_19 -> V_152 ) ;
}
static T_2 F_175 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
return V_19 -> V_259 ;
}
static void F_176 ( struct V_16 * V_17 , T_2 V_298 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
V_19 -> V_259 = V_298 ;
}
static int F_177 ( struct V_16 * V_17 , struct V_299 * V_300 , int V_289 )
{
struct V_18 * V_19 = F_9 ( V_17 ) ;
return ! F_55 ( V_17 ) ? - V_301 :
F_178 ( & V_19 -> V_152 , F_179 ( V_300 ) , V_289 , NULL ) ;
}
static int T_3 F_180 ( struct V_46 * V_79 ,
const struct V_302 * V_303 )
{
static int V_304 = 0 ;
struct V_18 * V_19 ;
struct V_16 * V_17 ;
void T_1 * V_1 ;
int V_202 ;
if ( ! V_304 ) {
if ( F_134 ( & V_257 ) )
F_116 ( V_305 L_36 ) ;
V_304 = 1 ;
}
V_17 = F_132 ( V_79 ) ;
if ( F_181 ( V_17 ) ) {
V_202 = F_182 ( V_17 ) ;
goto V_48;
}
F_183 ( V_79 , V_17 ) ;
V_19 = F_9 ( V_17 ) ;
V_1 = V_19 -> V_20 ;
V_202 = F_163 ( V_79 , V_17 ) ;
if ( V_202 < 0 )
goto V_306;
F_161 ( V_17 ) ;
F_184 ( & V_19 -> V_118 , F_77 ) ;
V_17 -> V_307 = & V_308 ;
F_185 ( V_17 , & V_309 ) ;
V_17 -> V_113 = V_79 -> V_113 ;
V_17 -> V_310 = ( unsigned long ) 0xdead ;
V_17 -> V_311 = V_312 ;
F_186 ( & V_19 -> V_137 ) ;
V_202 = F_121 ( V_17 ) ;
if ( V_202 < 0 )
goto V_306;
V_202 = F_187 ( V_17 ) ;
if ( V_202 < 0 )
goto V_313;
if ( F_115 ( V_19 ) ) {
F_188 ( V_17 , L_37 ,
F_117 ( V_79 ) ,
V_314 [ V_303 -> V_315 ] . V_208 ,
V_1 , V_17 -> V_113 , V_17 -> V_276 ) ;
F_188 ( V_17 , L_38 ,
( V_19 -> V_188 & V_189 ) ? L_39 : L_40 ) ;
}
F_81 ( V_17 ) ;
F_164 ( V_17 ) ;
V_48:
return V_202 ;
V_313:
F_125 ( V_17 ) ;
V_306:
F_126 ( V_79 ) ;
goto V_48;
}
static void T_9 F_189 ( struct V_46 * V_79 )
{
struct V_16 * V_17 = F_127 ( V_79 ) ;
struct V_18 * V_19 = F_9 ( V_17 ) ;
F_125 ( V_17 ) ;
F_190 ( & V_19 -> V_118 ) ;
F_191 ( V_17 ) ;
F_126 ( V_79 ) ;
F_183 ( V_79 , NULL ) ;
}
static int T_10 F_192 ( void )
{
return F_193 ( & V_316 ) ;
}
static void T_11 F_194 ( void )
{
F_195 ( & V_316 ) ;
}
