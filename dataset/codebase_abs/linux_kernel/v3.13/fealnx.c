static void F_1 ( void T_1 * V_1 , long V_2 )
{
int V_3 = 0x1000 ;
F_2 ( V_2 & ~ ( V_4 ) , V_1 + V_5 ) ;
while ( -- V_3 ) {
if ( ( F_3 ( V_1 + V_5 ) & V_6 ) == V_6 )
break;
}
}
static void F_4 ( void T_1 * V_1 , long V_2 )
{
int V_3 = 0x1000 ;
F_2 ( V_2 & ~ ( V_4 + V_7 ) , V_1 + V_5 ) ;
while ( -- V_3 ) {
if ( ( F_3 ( V_1 + V_5 ) & ( V_6 + V_8 ) )
== ( V_6 + V_8 ) )
break;
}
}
static int F_5 ( struct V_9 * V_10 ,
const struct V_11 * V_12 )
{
struct V_13 * V_14 ;
int V_15 , V_16 , V_17 , V_18 ;
static int V_19 = - 1 ;
char V_20 [ 12 ] ;
void T_1 * V_1 ;
unsigned long V_21 ;
unsigned int V_22 = V_12 -> V_23 ;
struct V_24 * V_25 ;
void * V_26 ;
T_2 V_27 ;
#ifdef F_6
int V_28 = 0 ;
#else
int V_28 = 1 ;
#endif
#ifndef F_7
static int V_29 ;
if ( ! V_29 ++ )
F_8 ( V_30 ) ;
#endif
V_19 ++ ;
sprintf ( V_20 , L_1 , V_19 ) ;
V_16 = V_19 < V_31 ? V_32 [ V_19 ] : 0 ;
V_15 = F_9 ( V_10 ) ;
if ( V_15 ) return V_15 ;
F_10 ( V_10 ) ;
V_21 = F_11 ( V_10 , V_28 ) ;
if ( V_21 < V_33 ) {
F_12 ( & V_10 -> V_25 ,
L_2 , V_21 ) ;
return - V_34 ;
}
V_15 = F_13 ( V_10 , V_20 ) ;
if ( V_15 )
return V_15 ;
V_18 = V_10 -> V_18 ;
V_1 = F_14 ( V_10 , V_28 , V_21 ) ;
if ( ! V_1 ) {
V_17 = - V_35 ;
goto V_36;
}
V_25 = F_15 ( sizeof( struct V_13 ) ) ;
if ( ! V_25 ) {
V_17 = - V_35 ;
goto V_37;
}
F_16 ( V_25 , & V_10 -> V_25 ) ;
for ( V_15 = 0 ; V_15 < 6 ; ++ V_15 )
V_25 -> V_38 [ V_15 ] = F_17 ( V_1 + V_39 + V_15 ) ;
F_2 ( 0x00000001 , V_1 + V_40 ) ;
V_14 = F_18 ( V_25 ) ;
V_14 -> V_41 = V_1 ;
F_19 ( & V_14 -> V_42 ) ;
V_14 -> V_9 = V_10 ;
V_14 -> V_43 = V_44 [ V_22 ] . V_43 ;
F_20 ( V_10 , V_25 ) ;
V_14 -> V_45 . V_25 = V_25 ;
V_14 -> V_45 . V_46 = V_46 ;
V_14 -> V_45 . V_47 = V_47 ;
V_14 -> V_45 . V_48 = 0x1f ;
V_14 -> V_45 . V_49 = 0x1f ;
V_26 = F_21 ( V_10 , V_50 , & V_27 ) ;
if ( ! V_26 ) {
V_17 = - V_35 ;
goto V_51;
}
V_14 -> V_52 = V_26 ;
V_14 -> V_53 = V_27 ;
V_26 = F_21 ( V_10 , V_54 , & V_27 ) ;
if ( ! V_26 ) {
V_17 = - V_35 ;
goto V_55;
}
V_14 -> V_56 = V_26 ;
V_14 -> V_57 = V_27 ;
if ( V_14 -> V_43 == V_58 ) {
int V_59 , V_60 = 0 ;
for ( V_59 = 1 ; V_59 < 32 && V_60 < F_22 ( V_14 -> V_61 ) ;
V_59 ++ ) {
int V_62 = V_46 ( V_25 , V_59 , 1 ) ;
if ( V_62 != 0xffff && V_62 != 0x0000 ) {
V_14 -> V_61 [ V_60 ++ ] = V_59 ;
F_23 ( & V_10 -> V_25 ,
L_3
L_4 , V_59 , V_62 ) ;
{
unsigned int V_63 ;
V_63 = V_46 ( V_25 , V_14 -> V_61 [ 0 ] , 2 ) ;
if ( V_63 == V_64 )
V_14 -> V_65 = V_66 ;
else if ( V_63 == V_67 )
V_14 -> V_65 = V_68 ;
else if ( V_63 == V_69 )
V_14 -> V_65 = V_70 ;
else if ( V_63 == V_71 )
V_14 -> V_65 = V_72 ;
else if ( V_63 == V_73 )
V_14 -> V_65 = V_74 ;
else
V_14 -> V_65 = V_75 ;
}
}
}
V_14 -> V_76 = V_60 ;
if ( V_60 == 0 )
F_24 ( & V_10 -> V_25 ,
L_5
L_6 ) ;
} else {
V_14 -> V_61 [ 0 ] = 32 ;
if ( F_3 ( V_1 + V_77 ) == V_78 )
V_14 -> V_65 = V_79 ;
else
V_14 -> V_65 = V_75 ;
}
V_14 -> V_45 . V_80 = V_14 -> V_61 [ 0 ] ;
if ( V_25 -> V_81 )
V_16 = V_25 -> V_81 ;
if ( V_16 > 0 ) {
if ( V_16 & 0x200 )
V_14 -> V_45 . V_82 = 1 ;
V_14 -> V_83 = V_16 & 15 ;
}
if ( V_19 < V_31 && V_82 [ V_19 ] > 0 )
V_14 -> V_45 . V_82 = V_82 [ V_19 ] ;
if ( V_14 -> V_45 . V_82 ) {
F_23 ( & V_10 -> V_25 , L_7 ) ;
if ( ( V_14 -> V_65 == V_70 ) || ( V_14 -> V_65 == V_74 ) ) {
unsigned int V_63 ;
V_63 = V_46 ( V_25 , V_14 -> V_61 [ 0 ] , 9 ) ;
V_63 = ( V_63 & 0xfcff ) | 0x0200 ;
V_47 ( V_25 , V_14 -> V_61 [ 0 ] , 9 , V_63 ) ;
}
if ( V_14 -> V_43 == V_58 )
V_47 ( V_25 , V_14 -> V_61 [ 0 ] , V_84 , V_85 ) ;
else
F_2 ( V_85 , V_1 + V_86 ) ;
V_14 -> V_45 . V_87 = 1 ;
}
V_25 -> V_88 = & V_88 ;
V_25 -> V_89 = & V_90 ;
V_25 -> V_91 = V_92 ;
V_17 = F_25 ( V_25 ) ;
if ( V_17 )
goto V_93;
F_8 ( V_94 L_8 ,
V_25 -> V_95 , V_44 [ V_22 ] . V_96 , V_1 ,
V_25 -> V_38 , V_18 ) ;
return 0 ;
V_93:
F_26 ( V_10 , V_54 , V_14 -> V_56 , V_14 -> V_57 ) ;
V_55:
F_26 ( V_10 , V_50 , V_14 -> V_52 , V_14 -> V_53 ) ;
V_51:
F_27 ( V_25 ) ;
V_37:
F_28 ( V_10 , V_1 ) ;
V_36:
F_29 ( V_10 ) ;
return V_17 ;
}
static void F_30 ( struct V_9 * V_10 )
{
struct V_24 * V_25 = F_31 ( V_10 ) ;
if ( V_25 ) {
struct V_13 * V_14 = F_18 ( V_25 ) ;
F_26 ( V_10 , V_54 , V_14 -> V_56 ,
V_14 -> V_57 ) ;
F_26 ( V_10 , V_50 , V_14 -> V_52 ,
V_14 -> V_53 ) ;
F_32 ( V_25 ) ;
F_28 ( V_10 , V_14 -> V_41 ) ;
F_27 ( V_25 ) ;
F_29 ( V_10 ) ;
} else
F_8 ( V_97 L_9 ) ;
}
static T_3 F_33 ( void T_1 * V_98 , int V_99 , int V_100 , int V_101 )
{
T_3 V_102 ;
int V_15 ;
unsigned int V_103 , V_63 ;
V_102 = ( T_3 ) F_3 ( V_98 ) ;
V_102 &= 0xfffffff0 ;
V_102 |= V_104 + V_105 ;
for ( V_15 = 0 ; V_15 < 32 ; V_15 ++ ) {
V_102 &= ~ V_106 ;
F_2 ( V_102 , V_98 ) ;
V_102 |= V_106 ;
F_2 ( V_102 , V_98 ) ;
}
V_63 = V_99 | ( V_100 << 7 ) | ( V_101 << 2 ) ;
V_103 = 0x8000 ;
while ( V_103 ) {
V_102 &= ~ ( V_106 + V_105 ) ;
if ( V_103 & V_63 )
V_102 |= V_105 ;
F_2 ( V_102 , V_98 ) ;
V_102 |= V_106 ;
F_2 ( V_102 , V_98 ) ;
F_34 ( 30 ) ;
V_103 >>= 1 ;
if ( V_103 == 0x2 && V_99 == V_107 )
V_102 &= ~ V_104 ;
}
return V_102 ;
}
static int V_46 ( struct V_24 * V_25 , int V_100 , int V_101 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
void T_1 * V_98 = V_14 -> V_41 + V_108 ;
T_3 V_102 ;
unsigned int V_103 , V_63 ;
V_102 = F_33 ( V_98 , V_107 , V_100 , V_101 ) ;
V_103 = 0x8000 ;
V_63 = 0 ;
while ( V_103 ) {
V_102 &= ~ V_106 ;
F_2 ( V_102 , V_98 ) ;
V_102 = F_3 ( V_98 ) ;
if ( V_102 & V_109 )
V_63 |= V_103 ;
V_102 |= V_106 ;
F_2 ( V_102 , V_98 ) ;
F_34 ( 30 ) ;
V_103 >>= 1 ;
}
V_102 &= ~ V_106 ;
F_2 ( V_102 , V_98 ) ;
return V_63 & 0xffff ;
}
static void V_47 ( struct V_24 * V_25 , int V_100 , int V_101 , int V_63 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
void T_1 * V_98 = V_14 -> V_41 + V_108 ;
T_3 V_102 ;
unsigned int V_103 ;
V_102 = F_33 ( V_98 , V_110 , V_100 , V_101 ) ;
V_103 = 0x8000 ;
while ( V_103 ) {
V_102 &= ~ ( V_106 + V_105 ) ;
if ( V_103 & V_63 )
V_102 |= V_105 ;
F_2 ( V_102 , V_98 ) ;
V_102 |= V_106 ;
F_2 ( V_102 , V_98 ) ;
V_103 >>= 1 ;
}
V_102 &= ~ V_106 ;
F_2 ( V_102 , V_98 ) ;
}
static int F_35 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
void T_1 * V_1 = V_14 -> V_41 ;
const int V_18 = V_14 -> V_9 -> V_18 ;
int V_111 , V_15 ;
F_2 ( 0x00000001 , V_1 + V_40 ) ;
V_111 = F_36 ( V_18 , V_112 , V_113 , V_25 -> V_95 , V_25 ) ;
if ( V_111 )
return - V_114 ;
for ( V_15 = 0 ; V_15 < 3 ; V_15 ++ )
F_37 ( ( ( unsigned short * ) V_25 -> V_38 ) [ V_15 ] ,
V_1 + V_39 + V_15 * 2 ) ;
F_38 ( V_25 ) ;
F_2 ( V_14 -> V_53 , V_1 + V_115 ) ;
F_2 ( V_14 -> V_57 , V_1 + V_116 ) ;
V_14 -> V_117 = 0x10 ;
#ifdef F_39
V_14 -> V_117 |= 0x04 ;
#endif
#if F_40 ( V_118 ) && ! F_40 ( F_7 )
if ( V_119 . V_120 <= 4 )
V_14 -> V_2 = 0xa00 ;
else
#endif
V_14 -> V_2 = 0xe00 ;
V_14 -> V_121 = V_122 | V_123 | V_124 | V_125 | V_126 ;
if ( V_14 -> V_9 -> V_127 == 0x891 ) {
V_14 -> V_117 |= 0x200 ;
V_14 -> V_2 |= V_128 ;
V_14 -> V_121 |= V_129 ;
}
F_2 ( V_14 -> V_117 , V_1 + V_40 ) ;
if ( V_25 -> V_130 == 0 )
V_25 -> V_130 = V_14 -> V_83 ;
F_2 ( 0 , V_1 + V_131 ) ;
V_14 -> V_2 |= 0x00e40001 ;
V_14 -> V_45 . V_82 = V_14 -> V_45 . V_87 ;
F_41 ( V_25 ) ;
if ( V_14 -> V_132 )
F_42 ( V_25 ) ;
F_43 ( V_25 ) ;
F_44 ( V_25 ) ;
F_2 ( V_133 | V_122 | V_123 | V_124 | V_125 | V_126 , V_1 + V_134 ) ;
F_2 ( V_14 -> V_121 , V_1 + V_135 ) ;
if ( V_136 )
F_8 ( V_137 L_10 , V_25 -> V_95 ) ;
F_45 ( & V_14 -> V_138 ) ;
V_14 -> V_138 . V_139 = F_46 ( 3 * V_140 ) ;
V_14 -> V_138 . V_63 = ( unsigned long ) V_25 ;
V_14 -> V_138 . V_141 = V_142 ;
F_47 ( & V_14 -> V_138 ) ;
F_45 ( & V_14 -> V_143 ) ;
V_14 -> V_143 . V_63 = ( unsigned long ) V_25 ;
V_14 -> V_143 . V_141 = V_143 ;
V_14 -> V_144 = 0 ;
return V_111 ;
}
static void F_41 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
unsigned int V_15 , V_145 = 0x1000 ;
V_14 -> V_132 = 0 ;
if ( V_14 -> V_65 == V_79 ) {
for ( V_15 = 0 ; V_15 < V_145 ; ++ V_15 ) {
if ( F_3 ( V_14 -> V_41 + V_146 ) & V_147 ) {
V_14 -> V_132 = 1 ;
return;
}
F_34 ( 100 ) ;
}
} else {
for ( V_15 = 0 ; V_15 < V_145 ; ++ V_15 ) {
if ( V_46 ( V_25 , V_14 -> V_61 [ 0 ] , V_148 ) & V_149 ) {
V_14 -> V_132 = 1 ;
return;
}
F_34 ( 100 ) ;
}
}
}
static void F_42 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
if ( V_14 -> V_65 == V_79 ) {
if ( F_3 ( V_14 -> V_41 + V_5 ) & V_150 )
V_14 -> V_151 = 2 ;
else
V_14 -> V_151 = 1 ;
if ( F_3 ( V_14 -> V_41 + V_5 ) & V_152 )
V_14 -> V_153 = 1 ;
else
V_14 -> V_153 = 2 ;
} else {
if ( V_14 -> V_65 == V_66 ) {
unsigned int V_63 ;
V_63 = V_46 ( V_25 , V_14 -> V_61 [ 0 ] , V_154 ) ;
if ( V_63 & V_155 )
V_14 -> V_153 = 2 ;
else
V_14 -> V_153 = 1 ;
if ( V_63 & V_156 )
V_14 -> V_151 = 2 ;
else
V_14 -> V_151 = 1 ;
} else if ( V_14 -> V_65 == V_68 ) {
unsigned int V_63 ;
V_63 = V_46 ( V_25 , V_14 -> V_61 [ 0 ] , V_157 ) ;
if ( V_63 & V_158 )
V_14 -> V_153 = 2 ;
else
V_14 -> V_153 = 1 ;
if ( V_63 & V_159 )
V_14 -> V_151 = 2 ;
else
V_14 -> V_151 = 1 ;
}
else if ( V_14 -> V_65 == V_70 ) {
unsigned int V_63 ;
V_63 = V_46 ( V_25 , V_14 -> V_61 [ 0 ] , V_160 ) ;
if ( V_63 & V_161 )
V_14 -> V_151 = 2 ;
else
V_14 -> V_151 = 1 ;
V_63 &= V_162 ;
if ( V_63 == V_163 )
V_14 -> V_153 = 3 ;
else if ( V_63 == V_164 )
V_14 -> V_153 = 2 ;
else
V_14 -> V_153 = 1 ;
}
else if ( V_14 -> V_65 == V_72 ) {
unsigned int V_63 ;
V_63 = V_46 ( V_25 , V_14 -> V_61 [ 0 ] , V_165 ) ;
if ( V_63 & V_166 )
V_14 -> V_153 = 2 ;
else
V_14 -> V_153 = 1 ;
if ( V_63 & V_167 )
V_14 -> V_151 = 2 ;
else
V_14 -> V_151 = 1 ;
}
else if ( V_14 -> V_65 == V_74 ) {
unsigned int V_63 ;
V_63 = V_46 ( V_25 , V_14 -> V_61 [ 0 ] , V_160 ) ;
if ( V_63 & V_168 )
V_14 -> V_151 = 2 ;
else
V_14 -> V_151 = 1 ;
V_63 &= V_162 ;
if ( V_63 == V_169 )
V_14 -> V_153 = 3 ;
else if ( V_63 == V_170 )
V_14 -> V_153 = 2 ;
else
V_14 -> V_153 = 1 ;
}
V_14 -> V_2 &= ( ~ V_171 ) & ( ~ V_172 ) & ( ~ V_173 ) ;
if ( V_14 -> V_153 == 1 )
V_14 -> V_2 |= V_171 ;
else if ( V_14 -> V_153 == 3 )
V_14 -> V_2 |= V_173 ;
if ( V_14 -> V_151 == 2 )
V_14 -> V_2 |= V_172 ;
}
}
static void F_48 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
while ( V_14 -> V_174 != V_175 ) {
struct V_176 * V_177 ;
V_177 = F_49 ( V_25 , V_14 -> V_178 ) ;
if ( V_177 == NULL )
break;
while ( V_14 -> V_179 -> V_180 )
V_14 -> V_179 = V_14 -> V_179 -> V_181 ;
V_14 -> V_179 -> V_180 = V_177 ;
V_14 -> V_179 -> V_182 = F_50 ( V_14 -> V_9 , V_177 -> V_63 ,
V_14 -> V_178 , V_183 ) ;
V_14 -> V_179 -> V_184 = V_185 ;
++ V_14 -> V_174 ;
}
}
static void V_142 ( unsigned long V_63 )
{
struct V_24 * V_25 = (struct V_24 * ) V_63 ;
struct V_13 * V_14 = F_18 ( V_25 ) ;
void T_1 * V_1 = V_14 -> V_41 ;
int V_186 = V_14 -> V_2 ;
unsigned int V_187 = V_14 -> V_132 ;
unsigned long V_43 ;
if ( V_136 )
F_8 ( V_137 L_11
L_12 , V_25 -> V_95 , F_3 ( V_1 + V_134 ) ,
F_3 ( V_1 + V_5 ) ) ;
F_51 ( & V_14 -> V_42 , V_43 ) ;
if ( V_14 -> V_43 == V_58 ) {
F_41 ( V_25 ) ;
if ( ( V_187 == 0 ) && ( V_14 -> V_132 == 1 ) ) {
F_42 ( V_25 ) ;
if ( V_14 -> V_2 != V_186 ) {
F_4 ( V_1 , V_14 -> V_2 ) ;
F_2 ( V_14 -> V_2 , V_1 + V_5 ) ;
}
}
}
F_48 ( V_25 ) ;
F_52 ( & V_14 -> V_42 , V_43 ) ;
V_14 -> V_138 . V_139 = F_46 ( 10 * V_140 ) ;
F_47 ( & V_14 -> V_138 ) ;
}
static void F_53 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
void T_1 * V_1 = V_14 -> V_41 ;
int V_3 = 51 ;
F_4 ( V_1 , 0 ) ;
F_2 ( 0 , V_1 + V_135 ) ;
F_2 ( 0x00000001 , V_1 + V_40 ) ;
while ( -- V_3 ) {
F_3 ( V_1 + V_40 ) ;
F_54 () ;
}
}
static void F_55 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
void T_1 * V_1 = V_14 -> V_41 ;
F_56 ( V_25 ) ;
F_2 ( V_14 -> V_57 + ( ( char * ) V_14 -> V_188 - ( char * ) V_14 -> V_56 ) ,
V_1 + V_116 ) ;
F_2 ( V_14 -> V_53 + ( ( char * ) V_14 -> V_189 - ( char * ) V_14 -> V_52 ) ,
V_1 + V_115 ) ;
F_2 ( V_14 -> V_117 , V_1 + V_40 ) ;
F_2 ( 0 , V_1 + V_131 ) ;
F_43 ( V_25 ) ;
F_2 ( V_133 | V_122 | V_123 | V_124 | V_125 | V_126 , V_1 + V_134 ) ;
F_2 ( V_14 -> V_121 , V_1 + V_135 ) ;
F_2 ( 0 , V_1 + V_190 ) ;
}
static void V_143 ( unsigned long V_63 )
{
struct V_24 * V_25 = (struct V_24 * ) V_63 ;
struct V_13 * V_14 = F_18 ( V_25 ) ;
unsigned long V_43 ;
F_8 ( V_191 L_13 , V_25 -> V_95 ) ;
F_51 ( & V_14 -> V_42 , V_43 ) ;
V_14 -> V_2 = V_14 -> V_192 ;
V_14 -> V_121 = V_14 -> V_193 ;
F_53 ( V_25 ) ;
F_55 ( V_25 ) ;
F_44 ( V_25 ) ;
V_14 -> V_144 = 0 ;
F_52 ( & V_14 -> V_42 , V_43 ) ;
}
static void F_57 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
void T_1 * V_1 = V_14 -> V_41 ;
unsigned long V_43 ;
int V_15 ;
F_8 ( V_191
L_14 ,
V_25 -> V_95 , F_3 ( V_1 + V_134 ) ) ;
{
F_8 ( V_137 L_15 , V_14 -> V_52 ) ;
for ( V_15 = 0 ; V_15 < V_175 ; V_15 ++ )
F_8 ( V_194 L_16 ,
( unsigned int ) V_14 -> V_52 [ V_15 ] . V_184 ) ;
F_8 ( V_194 L_17 ) ;
F_8 ( V_137 L_18 , V_14 -> V_56 ) ;
for ( V_15 = 0 ; V_15 < V_195 ; V_15 ++ )
F_8 ( V_194 L_19 , V_14 -> V_56 [ V_15 ] . V_184 ) ;
F_8 ( V_194 L_17 ) ;
}
F_51 ( & V_14 -> V_42 , V_43 ) ;
F_53 ( V_25 ) ;
F_58 ( V_25 ) ;
F_55 ( V_25 ) ;
F_52 ( & V_14 -> V_42 , V_43 ) ;
V_25 -> V_196 = V_197 ;
V_25 -> V_198 . V_199 ++ ;
F_59 ( V_25 ) ;
}
static void F_38 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
int V_15 ;
V_14 -> V_178 = ( V_25 -> V_200 <= 1500 ? V_201 : V_25 -> V_200 + 32 ) ;
V_14 -> V_189 = & V_14 -> V_52 [ 0 ] ;
V_14 -> V_179 = V_14 -> V_52 ;
V_14 -> V_174 = 0 ;
for ( V_15 = 0 ; V_15 < V_175 ; V_15 ++ ) {
V_14 -> V_52 [ V_15 ] . V_184 = 0 ;
V_14 -> V_52 [ V_15 ] . V_202 = V_14 -> V_178 << V_203 ;
V_14 -> V_52 [ V_15 ] . V_204 = V_14 -> V_53 +
( V_15 + 1 ) * sizeof( struct V_205 ) ;
V_14 -> V_52 [ V_15 ] . V_181 = & V_14 -> V_52 [ V_15 + 1 ] ;
V_14 -> V_52 [ V_15 ] . V_180 = NULL ;
}
V_14 -> V_52 [ V_15 - 1 ] . V_204 = V_14 -> V_53 ;
V_14 -> V_52 [ V_15 - 1 ] . V_181 = V_14 -> V_52 ;
for ( V_15 = 0 ; V_15 < V_175 ; V_15 ++ ) {
struct V_176 * V_177 = F_49 ( V_25 , V_14 -> V_178 ) ;
if ( V_177 == NULL ) {
V_14 -> V_179 = & V_14 -> V_52 [ V_15 ] ;
break;
}
++ V_14 -> V_174 ;
V_14 -> V_52 [ V_15 ] . V_180 = V_177 ;
V_14 -> V_52 [ V_15 ] . V_182 = F_50 ( V_14 -> V_9 , V_177 -> V_63 ,
V_14 -> V_178 , V_183 ) ;
V_14 -> V_52 [ V_15 ] . V_184 = V_185 ;
V_14 -> V_52 [ V_15 ] . V_202 |= V_206 ;
}
V_14 -> V_188 = & V_14 -> V_56 [ 0 ] ;
V_14 -> V_207 = & V_14 -> V_56 [ 0 ] ;
V_14 -> V_208 = 0 ;
V_14 -> V_209 = V_195 ;
for ( V_15 = 0 ; V_15 < V_195 ; V_15 ++ ) {
V_14 -> V_56 [ V_15 ] . V_184 = 0 ;
V_14 -> V_56 [ V_15 ] . V_204 = V_14 -> V_57 +
( V_15 + 1 ) * sizeof( struct V_205 ) ;
V_14 -> V_56 [ V_15 ] . V_181 = & V_14 -> V_56 [ V_15 + 1 ] ;
V_14 -> V_56 [ V_15 ] . V_180 = NULL ;
}
V_14 -> V_56 [ V_15 - 1 ] . V_204 = V_14 -> V_57 ;
V_14 -> V_56 [ V_15 - 1 ] . V_181 = & V_14 -> V_56 [ 0 ] ;
}
static T_4 F_60 ( struct V_176 * V_177 , struct V_24 * V_25 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
unsigned long V_43 ;
F_51 ( & V_14 -> V_42 , V_43 ) ;
V_14 -> V_207 -> V_180 = V_177 ;
#define F_61
#define F_62 1022
#if F_40 ( F_61 )
V_14 -> V_207 -> V_182 = F_50 ( V_14 -> V_9 , V_177 -> V_63 ,
V_177 -> V_21 , V_210 ) ;
V_14 -> V_207 -> V_202 = V_211 | V_212 | V_213 | V_214 | V_215 ;
V_14 -> V_207 -> V_202 |= ( V_177 -> V_21 << V_216 ) ;
V_14 -> V_207 -> V_202 |= ( V_177 -> V_21 << V_217 ) ;
if ( V_14 -> V_9 -> V_127 == 0x891 )
V_14 -> V_207 -> V_202 |= V_218 | V_219 ;
V_14 -> V_207 -> V_184 = V_220 ;
V_14 -> V_207 = V_14 -> V_207 -> V_181 ;
-- V_14 -> V_209 ;
#elif F_40 ( V_221 )
if ( V_177 -> V_21 > F_62 ) {
struct V_205 * V_222 ;
V_14 -> V_207 -> V_182 = F_50 ( V_14 -> V_9 , V_177 -> V_63 ,
F_62 , V_210 ) ;
V_14 -> V_207 -> V_202 = V_211 | V_213 | V_214 | V_215 ;
V_14 -> V_207 -> V_202 |= ( V_177 -> V_21 << V_216 ) ;
V_14 -> V_207 -> V_202 |= ( F_62 << V_217 ) ;
V_222 = V_14 -> V_207 -> V_181 ;
V_222 -> V_180 = V_177 ;
V_222 -> V_202 = V_211 | V_212 | V_214 | V_215 ;
V_222 -> V_202 |= ( V_177 -> V_21 << V_216 ) ;
V_222 -> V_202 |= ( ( V_177 -> V_21 - F_62 ) << V_217 ) ;
if ( V_14 -> V_9 -> V_127 == 0x891 )
V_14 -> V_207 -> V_202 |= V_218 | V_219 ;
V_222 -> V_182 = F_50 ( V_223 -> V_9 , V_177 -> V_63 + F_62 ,
V_177 -> V_21 - F_62 , V_210 ) ;
V_222 -> V_184 = V_220 ;
V_14 -> V_207 -> V_184 = V_220 ;
V_14 -> V_207 = V_222 -> V_181 ;
V_14 -> V_209 -= 2 ;
} else {
V_14 -> V_207 -> V_182 = F_50 ( V_14 -> V_9 , V_177 -> V_63 ,
V_177 -> V_21 , V_210 ) ;
V_14 -> V_207 -> V_202 = V_211 | V_212 | V_213 | V_214 | V_215 ;
V_14 -> V_207 -> V_202 |= ( V_177 -> V_21 << V_216 ) ;
V_14 -> V_207 -> V_202 |= ( V_177 -> V_21 << V_217 ) ;
if ( V_14 -> V_9 -> V_127 == 0x891 )
V_14 -> V_207 -> V_202 |= V_218 | V_219 ;
V_14 -> V_207 -> V_184 = V_220 ;
V_14 -> V_207 = V_14 -> V_207 -> V_181 ;
-- V_14 -> V_209 ;
}
#endif
if ( V_14 -> V_209 < 2 )
F_63 ( V_25 ) ;
++ V_14 -> V_208 ;
F_2 ( 0 , V_14 -> V_41 + V_190 ) ;
F_52 ( & V_14 -> V_42 , V_43 ) ;
return V_224 ;
}
static void F_58 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
struct V_205 * V_225 ;
int V_15 ;
V_14 -> V_188 = & V_14 -> V_56 [ 0 ] ;
V_14 -> V_207 = & V_14 -> V_56 [ 0 ] ;
V_14 -> V_208 = 0 ;
V_14 -> V_209 = V_195 ;
for ( V_15 = 0 ; V_15 < V_195 ; V_15 ++ ) {
V_225 = & V_14 -> V_56 [ V_15 ] ;
if ( V_225 -> V_180 ) {
F_64 ( V_14 -> V_9 , V_225 -> V_182 ,
V_225 -> V_180 -> V_21 , V_210 ) ;
F_65 ( V_225 -> V_180 ) ;
V_225 -> V_180 = NULL ;
}
V_225 -> V_184 = 0 ;
V_225 -> V_202 = 0 ;
V_225 -> V_204 = V_14 -> V_57 +
( V_15 + 1 ) * sizeof( struct V_205 ) ;
V_225 -> V_181 = & V_14 -> V_56 [ V_15 + 1 ] ;
}
V_14 -> V_56 [ V_195 - 1 ] . V_204 = V_14 -> V_57 ;
V_14 -> V_56 [ V_195 - 1 ] . V_181 = & V_14 -> V_56 [ 0 ] ;
}
static void F_56 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
struct V_205 * V_225 = V_14 -> V_189 ;
int V_15 ;
F_48 ( V_25 ) ;
for ( V_15 = 0 ; V_15 < V_175 ; V_15 ++ ) {
if ( V_225 -> V_180 )
V_225 -> V_184 = V_185 ;
V_225 = V_225 -> V_181 ;
}
F_2 ( V_14 -> V_53 + ( ( char * ) V_14 -> V_189 - ( char * ) V_14 -> V_52 ) ,
V_14 -> V_41 + V_115 ) ;
}
static T_5 V_112 ( int V_18 , void * V_226 )
{
struct V_24 * V_25 = (struct V_24 * ) V_226 ;
struct V_13 * V_14 = F_18 ( V_25 ) ;
void T_1 * V_1 = V_14 -> V_41 ;
long V_227 = V_228 ;
unsigned int V_229 = 0 ;
int V_230 = 0 ;
F_66 ( & V_14 -> V_42 ) ;
F_2 ( 0 , V_1 + V_135 ) ;
do {
T_6 V_231 = F_3 ( V_1 + V_134 ) ;
F_2 ( V_231 , V_1 + V_134 ) ;
if ( V_136 )
F_8 ( V_137 L_20 , V_25 -> V_95 ,
V_231 ) ;
if ( ! ( V_231 & V_14 -> V_121 ) )
break;
V_230 = 1 ;
if ( V_231 & V_122 )
F_2 ( 0 , V_1 + V_190 ) ;
if ( V_231 & V_123 ) {
V_25 -> V_198 . V_232 +=
F_3 ( V_1 + V_233 ) & 0x7fff ;
V_25 -> V_198 . V_234 +=
( F_3 ( V_1 + V_233 ) & 0x7fff0000 ) >> 16 ;
}
if ( V_231 & ( V_126 | V_124 ) ) {
if ( V_231 & V_126 )
F_67 ( V_25 ) ;
else {
F_1 ( V_1 , V_14 -> V_2 ) ;
F_56 ( V_25 ) ;
F_2 ( V_14 -> V_2 , V_1 + V_5 ) ;
}
}
while ( V_14 -> V_208 ) {
long V_235 = V_14 -> V_188 -> V_184 ;
long V_236 = V_14 -> V_188 -> V_202 ;
if ( ! ( V_236 & V_212 ) ) {
struct V_205 * V_222 ;
V_222 = V_14 -> V_188 -> V_181 ;
V_235 = V_222 -> V_184 ;
V_236 = V_222 -> V_202 ;
}
if ( V_235 & V_220 )
break;
if ( ! ( V_14 -> V_2 & V_128 ) ) {
if ( V_235 & ( V_237 | V_238 | V_239 | V_240 | V_241 ) ) {
V_25 -> V_198 . V_199 ++ ;
if ( V_235 & V_239 )
V_25 -> V_198 . V_242 ++ ;
if ( V_235 & V_237 )
V_25 -> V_198 . V_243 ++ ;
if ( V_235 & V_238 )
V_25 -> V_198 . V_244 ++ ;
if ( V_235 & V_240 )
V_25 -> V_198 . V_245 ++ ;
if ( ( V_235 & V_241 ) && V_14 -> V_45 . V_82 == 0 )
V_25 -> V_198 . V_246 ++ ;
} else {
V_25 -> V_198 . V_247 +=
( ( V_236 & V_248 ) >> V_216 ) ;
V_25 -> V_198 . V_249 +=
( ( V_235 & V_250 ) >> V_251 ) ;
V_25 -> V_198 . V_252 ++ ;
}
} else {
V_25 -> V_198 . V_247 +=
( ( V_236 & V_248 ) >> V_216 ) ;
V_25 -> V_198 . V_252 ++ ;
}
F_64 ( V_14 -> V_9 , V_14 -> V_188 -> V_182 ,
V_14 -> V_188 -> V_180 -> V_21 , V_210 ) ;
F_68 ( V_14 -> V_188 -> V_180 ) ;
V_14 -> V_188 -> V_180 = NULL ;
-- V_14 -> V_208 ;
if ( V_14 -> V_188 -> V_202 & V_212 ) {
V_14 -> V_188 = V_14 -> V_188 -> V_181 ;
++ V_14 -> V_209 ;
} else {
V_14 -> V_188 = V_14 -> V_188 -> V_181 ;
V_14 -> V_188 = V_14 -> V_188 -> V_181 ;
V_14 -> V_209 += 2 ;
}
V_229 ++ ;
}
if ( V_229 && V_14 -> V_209 >= 2 )
F_59 ( V_25 ) ;
if ( V_14 -> V_2 & V_128 ) {
long V_63 ;
V_63 = F_3 ( V_1 + V_253 ) ;
V_25 -> V_198 . V_199 += ( V_63 & 0xff000000 ) >> 24 ;
V_25 -> V_198 . V_242 +=
( V_63 & 0xff000000 ) >> 24 ;
V_25 -> V_198 . V_244 +=
( V_63 & 0x00ff0000 ) >> 16 ;
V_25 -> V_198 . V_249 += ( V_63 & 0x0000ffff ) ;
}
if ( -- V_227 < 0 ) {
F_8 ( V_191 L_21
L_22 , V_25 -> V_95 , V_231 ) ;
if ( ! V_14 -> V_144 ) {
V_14 -> V_144 = 1 ;
V_14 -> V_143 . V_139 = F_46 ( V_140 / 2 ) ;
F_47 ( & V_14 -> V_143 ) ;
F_4 ( V_1 , 0 ) ;
F_63 ( V_25 ) ;
V_14 -> V_192 = V_14 -> V_2 ;
V_14 -> V_193 = V_14 -> V_121 ;
V_14 -> V_2 &= ~ ( V_7 | V_4 ) ;
V_14 -> V_121 = 0 ;
}
break;
}
} while ( 1 );
V_25 -> V_198 . V_232 += F_3 ( V_1 + V_233 ) & 0x7fff ;
V_25 -> V_198 . V_234 +=
( F_3 ( V_1 + V_233 ) & 0x7fff0000 ) >> 16 ;
if ( V_136 )
F_8 ( V_137 L_23 ,
V_25 -> V_95 , F_3 ( V_1 + V_134 ) ) ;
F_2 ( V_14 -> V_121 , V_1 + V_135 ) ;
F_69 ( & V_14 -> V_42 ) ;
return F_70 ( V_230 ) ;
}
static int F_67 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
void T_1 * V_1 = V_14 -> V_41 ;
while ( ! ( V_14 -> V_189 -> V_184 & V_185 ) && V_14 -> V_189 -> V_180 ) {
T_7 V_254 = V_14 -> V_189 -> V_184 ;
if ( V_14 -> V_174 == 0 )
break;
if ( V_136 )
F_8 ( V_137 L_24 , V_254 ) ;
if ( ( ! ( ( V_254 & V_255 ) && ( V_254 & V_256 ) ) ) ||
( V_254 & V_257 ) ) {
if ( V_254 & V_257 ) {
if ( V_136 )
F_8 ( V_137
L_25 ,
V_25 -> V_95 , V_254 ) ;
V_25 -> V_198 . V_258 ++ ;
if ( V_254 & ( LONG | V_259 ) )
V_25 -> V_198 . V_260 ++ ;
if ( V_254 & V_261 )
V_25 -> V_198 . V_262 ++ ;
if ( V_254 & V_263 )
V_25 -> V_198 . V_234 ++ ;
} else {
int V_264 = 0 ;
int V_265 = 0 ;
if ( V_254 & V_255 ) {
struct V_205 * V_225 ;
V_225 = V_14 -> V_189 ;
while ( V_265 <= V_14 -> V_174 ) {
++ V_265 ;
if ( ( ! ( V_225 -> V_184 & V_185 ) ) &&
( V_225 -> V_184 & V_256 ) )
break;
V_225 = V_225 -> V_181 ;
}
if ( V_265 > V_14 -> V_174 )
V_264 = 1 ;
} else
V_264 = 1 ;
if ( V_264 == 0 ) {
int V_15 ;
V_25 -> V_198 . V_260 ++ ;
for ( V_15 = 0 ; V_15 < V_265 ; ++ V_15 ) {
if ( ! V_14 -> V_189 -> V_180 ) {
F_8 ( V_137
L_26 , V_25 -> V_95 ) ;
break;
}
V_14 -> V_189 -> V_184 = V_185 ;
V_14 -> V_189 = V_14 -> V_189 -> V_181 ;
}
continue;
} else {
F_1 ( V_1 , V_14 -> V_2 ) ;
F_56 ( V_25 ) ;
F_2 ( V_14 -> V_2 , V_1 + V_5 ) ;
}
break;
}
} else {
struct V_176 * V_177 ;
short V_266 = ( ( V_254 & V_267 ) >> V_268 ) - 4 ;
#ifndef F_71
if ( V_136 )
F_8 ( V_137 L_27
L_28 , V_266 , V_254 ) ;
#endif
if ( V_266 < V_269 &&
( V_177 = F_49 ( V_25 , V_266 + 2 ) ) != NULL ) {
F_72 ( V_177 , 2 ) ;
F_73 ( V_14 -> V_9 ,
V_14 -> V_189 -> V_182 ,
V_14 -> V_178 ,
V_183 ) ;
#if ! F_40 ( V_270 )
F_74 ( V_177 ,
V_14 -> V_189 -> V_180 -> V_63 , V_266 ) ;
F_75 ( V_177 , V_266 ) ;
#else
memcpy ( F_75 ( V_177 , V_266 ) ,
V_14 -> V_189 -> V_180 -> V_63 , V_266 ) ;
#endif
F_76 ( V_14 -> V_9 ,
V_14 -> V_189 -> V_182 ,
V_14 -> V_178 ,
V_183 ) ;
} else {
F_64 ( V_14 -> V_9 ,
V_14 -> V_189 -> V_182 ,
V_14 -> V_178 ,
V_183 ) ;
F_75 ( V_177 = V_14 -> V_189 -> V_180 , V_266 ) ;
V_14 -> V_189 -> V_180 = NULL ;
-- V_14 -> V_174 ;
}
V_177 -> V_271 = F_77 ( V_177 , V_25 ) ;
F_78 ( V_177 ) ;
V_25 -> V_198 . V_272 ++ ;
V_25 -> V_198 . V_273 += V_266 ;
}
V_14 -> V_189 = V_14 -> V_189 -> V_181 ;
}
F_48 ( V_25 ) ;
return 0 ;
}
static struct V_274 * F_79 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
void T_1 * V_1 = V_14 -> V_41 ;
if ( F_80 ( V_25 ) ) {
V_25 -> V_198 . V_232 +=
F_3 ( V_1 + V_233 ) & 0x7fff ;
V_25 -> V_198 . V_234 +=
( F_3 ( V_1 + V_233 ) & 0x7fff0000 ) >> 16 ;
}
return & V_25 -> V_198 ;
}
static void F_81 ( struct V_24 * V_25 )
{
T_8 * V_275 = & ( (struct V_13 * ) F_18 ( V_25 ) ) -> V_42 ;
unsigned long V_43 ;
F_51 ( V_275 , V_43 ) ;
F_43 ( V_25 ) ;
F_52 ( V_275 , V_43 ) ;
}
static void F_43 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
void T_1 * V_1 = V_14 -> V_41 ;
T_6 V_276 [ 2 ] ;
T_6 V_277 ;
if ( V_25 -> V_43 & V_278 ) {
memset ( V_276 , 0xff , sizeof( V_276 ) ) ;
V_277 = V_279 | V_280 | V_281 ;
} else if ( ( F_82 ( V_25 ) > V_282 ) ||
( V_25 -> V_43 & V_283 ) ) {
memset ( V_276 , 0xff , sizeof( V_276 ) ) ;
V_277 = V_280 | V_281 ;
} else {
struct V_284 * V_285 ;
memset ( V_276 , 0 , sizeof( V_276 ) ) ;
F_83 (ha, dev) {
unsigned int V_286 ;
V_286 = ( F_84 ( V_287 , V_285 -> V_288 ) >> 26 ) ^ 0x3F ;
V_276 [ V_286 >> 5 ] |= ( 1 << V_286 ) ;
}
V_277 = V_280 | V_281 ;
}
F_4 ( V_1 , V_14 -> V_2 ) ;
F_2 ( V_276 [ 0 ] , V_1 + V_289 ) ;
F_2 ( V_276 [ 1 ] , V_1 + V_290 ) ;
V_14 -> V_2 &= ~ V_291 ;
V_14 -> V_2 |= V_277 ;
F_2 ( V_14 -> V_2 , V_1 + V_5 ) ;
}
static void F_85 ( struct V_24 * V_25 , struct V_292 * V_293 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
F_86 ( V_293 -> V_294 , V_295 , sizeof( V_293 -> V_294 ) ) ;
F_86 ( V_293 -> V_30 , V_296 , sizeof( V_293 -> V_30 ) ) ;
F_86 ( V_293 -> V_297 , F_87 ( V_14 -> V_9 ) , sizeof( V_293 -> V_297 ) ) ;
}
static int F_88 ( struct V_24 * V_25 , struct V_298 * V_299 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
int V_111 ;
F_89 ( & V_14 -> V_42 ) ;
V_111 = F_90 ( & V_14 -> V_45 , V_299 ) ;
F_91 ( & V_14 -> V_42 ) ;
return V_111 ;
}
static int F_92 ( struct V_24 * V_25 , struct V_298 * V_299 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
int V_111 ;
F_89 ( & V_14 -> V_42 ) ;
V_111 = F_93 ( & V_14 -> V_45 , V_299 ) ;
F_91 ( & V_14 -> V_42 ) ;
return V_111 ;
}
static int F_94 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
return F_95 ( & V_14 -> V_45 ) ;
}
static T_6 F_96 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
return F_97 ( & V_14 -> V_45 ) ;
}
static T_6 F_98 ( struct V_24 * V_25 )
{
return V_136 ;
}
static void F_99 ( struct V_24 * V_25 , T_6 V_300 )
{
V_136 = V_300 ;
}
static int F_100 ( struct V_24 * V_25 , struct V_301 * V_302 , int V_299 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
int V_111 ;
if ( ! F_80 ( V_25 ) )
return - V_303 ;
F_89 ( & V_14 -> V_42 ) ;
V_111 = F_101 ( & V_14 -> V_45 , F_102 ( V_302 ) , V_299 , NULL ) ;
F_91 ( & V_14 -> V_42 ) ;
return V_111 ;
}
static int F_103 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = F_18 ( V_25 ) ;
void T_1 * V_1 = V_14 -> V_41 ;
int V_15 ;
F_63 ( V_25 ) ;
F_2 ( 0x0000 , V_1 + V_135 ) ;
F_4 ( V_1 , 0 ) ;
F_104 ( & V_14 -> V_138 ) ;
F_104 ( & V_14 -> V_143 ) ;
F_105 ( V_14 -> V_9 -> V_18 , V_25 ) ;
for ( V_15 = 0 ; V_15 < V_175 ; V_15 ++ ) {
struct V_176 * V_177 = V_14 -> V_52 [ V_15 ] . V_180 ;
V_14 -> V_52 [ V_15 ] . V_184 = 0 ;
if ( V_177 ) {
F_64 ( V_14 -> V_9 , V_14 -> V_52 [ V_15 ] . V_182 ,
V_14 -> V_178 , V_183 ) ;
F_106 ( V_177 ) ;
V_14 -> V_52 [ V_15 ] . V_180 = NULL ;
}
}
for ( V_15 = 0 ; V_15 < V_195 ; V_15 ++ ) {
struct V_176 * V_177 = V_14 -> V_56 [ V_15 ] . V_180 ;
if ( V_177 ) {
F_64 ( V_14 -> V_9 , V_14 -> V_56 [ V_15 ] . V_182 ,
V_177 -> V_21 , V_210 ) ;
F_106 ( V_177 ) ;
V_14 -> V_56 [ V_15 ] . V_180 = NULL ;
}
}
return 0 ;
}
static int T_9 F_107 ( void )
{
#ifdef F_7
F_8 ( V_30 ) ;
#endif
return F_108 ( & V_304 ) ;
}
static void T_10 F_109 ( void )
{
F_110 ( & V_304 ) ;
}
