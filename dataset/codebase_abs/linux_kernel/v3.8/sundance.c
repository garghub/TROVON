static void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_6 = V_5 -> V_7 + V_8 ;
int V_9 ;
F_3 ( V_3 | F_4 ( V_6 ) , V_6 ) ;
V_9 = 10 + 1 ;
while ( F_4 ( V_6 ) & ( V_10 << 16 ) ) {
if ( -- V_9 == 0 ) {
F_5 ( V_11 L_1 , V_2 -> V_12 ) ;
break;
}
F_6 ( 100 ) ;
}
}
static int F_7 ( struct V_13 * V_14 ,
const struct V_15 * V_16 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
static int V_17 ;
int V_18 = V_16 -> V_19 ;
int V_20 ;
int V_21 ;
void T_1 * V_6 ;
T_2 V_22 ;
void * V_23 ;
T_3 V_24 ;
#ifdef F_8
int V_25 = 0 ;
#else
int V_25 = 1 ;
#endif
int V_26 , V_27 , V_28 = 0 ;
#ifndef F_9
static int V_29 ;
if ( ! V_29 ++ )
F_5 ( V_30 ) ;
#endif
if ( F_10 ( V_14 ) )
return - V_31 ;
F_11 ( V_14 ) ;
V_20 = V_14 -> V_20 ;
V_2 = F_12 ( sizeof( * V_5 ) ) ;
if ( ! V_2 )
return - V_32 ;
F_13 ( V_2 , & V_14 -> V_2 ) ;
if ( F_14 ( V_14 , V_33 ) )
goto V_34;
V_6 = F_15 ( V_14 , V_25 , V_35 ) ;
if ( ! V_6 )
goto V_36;
for ( V_21 = 0 ; V_21 < 3 ; V_21 ++ )
( ( V_37 * ) V_2 -> V_38 ) [ V_21 ] =
F_16 ( F_17 ( V_6 , V_21 + V_39 ) ) ;
memcpy ( V_2 -> V_40 , V_2 -> V_38 , V_2 -> V_41 ) ;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_7 = V_6 ;
V_5 -> V_13 = V_14 ;
V_5 -> V_42 = V_18 ;
V_5 -> V_43 = ( 1 << V_44 ) - 1 ;
F_18 ( & V_5 -> V_45 ) ;
F_18 ( & V_5 -> V_46 ) ;
F_19 ( & V_5 -> V_47 , V_48 , ( unsigned long ) V_2 ) ;
F_19 ( & V_5 -> V_49 , V_50 , ( unsigned long ) V_2 ) ;
V_23 = F_20 ( & V_14 -> V_2 , V_51 ,
& V_24 , V_52 ) ;
if ( ! V_23 )
goto V_53;
V_5 -> V_54 = (struct V_55 * ) V_23 ;
V_5 -> V_56 = V_24 ;
V_23 = F_20 ( & V_14 -> V_2 , V_57 ,
& V_24 , V_52 ) ;
if ( ! V_23 )
goto V_58;
V_5 -> V_59 = (struct V_55 * ) V_23 ;
V_5 -> V_60 = V_24 ;
V_5 -> V_61 . V_2 = V_2 ;
V_5 -> V_61 . V_62 = V_62 ;
V_5 -> V_61 . V_63 = V_63 ;
V_5 -> V_61 . V_64 = 0x1f ;
V_5 -> V_61 . V_65 = 0x1f ;
V_2 -> V_66 = & V_66 ;
F_21 ( V_2 , & V_67 ) ;
V_2 -> V_68 = V_69 ;
F_22 ( V_14 , V_2 ) ;
V_21 = F_23 ( V_2 ) ;
if ( V_21 )
goto V_70;
F_5 ( V_71 L_2 ,
V_2 -> V_12 , V_72 [ V_18 ] . V_12 , V_6 ,
V_2 -> V_38 , V_20 ) ;
V_5 -> V_73 [ 0 ] = 1 ;
V_5 -> V_74 ++ ;
if ( V_75 [ V_5 -> V_42 ] . V_76 == 0x0200 ) {
V_26 = 0 ;
V_27 = 31 ;
} else {
V_26 = 1 ;
V_27 = 32 ;
}
for (; V_26 <= V_27 && V_28 < V_77 ; V_26 ++ ) {
int V_78 = V_26 & 0x1f ;
int V_79 = V_62 ( V_2 , V_78 , V_80 ) ;
if ( V_79 != 0xffff && V_79 != 0x0000 ) {
V_5 -> V_73 [ V_28 ++ ] = V_78 ;
V_5 -> V_61 . V_81 = V_62 ( V_2 , V_78 , V_82 ) ;
if ( ( V_79 & 0x0040 ) == 0 )
V_5 -> V_74 ++ ;
F_5 ( V_71 L_3
L_4 ,
V_2 -> V_12 , V_78 , V_79 , V_5 -> V_61 . V_81 ) ;
}
}
V_5 -> V_74 -- ;
if ( V_28 == 0 ) {
F_5 ( V_71 L_5 ,
V_2 -> V_12 , F_4 ( V_6 + V_8 ) ) ;
goto V_83;
}
V_5 -> V_61 . V_84 = V_5 -> V_73 [ 0 ] ;
V_5 -> V_85 = 1 ;
if ( V_17 < V_86 ) {
if ( V_87 [ V_17 ] != NULL ) {
V_5 -> V_85 = 0 ;
if ( strcmp ( V_87 [ V_17 ] , L_6 ) == 0 ||
strcmp ( V_87 [ V_17 ] , L_7 ) == 0 ) {
V_5 -> V_88 = 100 ;
V_5 -> V_61 . V_89 = 1 ;
} else if ( strcmp ( V_87 [ V_17 ] , L_8 ) == 0 ||
strcmp ( V_87 [ V_17 ] , L_9 ) == 0 ) {
V_5 -> V_88 = 100 ;
V_5 -> V_61 . V_89 = 0 ;
} else if ( strcmp ( V_87 [ V_17 ] , L_10 ) == 0 ||
strcmp ( V_87 [ V_17 ] , L_11 ) == 0 ) {
V_5 -> V_88 = 10 ;
V_5 -> V_61 . V_89 = 1 ;
} else if ( strcmp ( V_87 [ V_17 ] , L_12 ) == 0 ||
strcmp ( V_87 [ V_17 ] , L_13 ) == 0 ) {
V_5 -> V_88 = 10 ;
V_5 -> V_61 . V_89 = 0 ;
} else {
V_5 -> V_85 = 1 ;
}
}
if ( V_90 == 1 )
V_5 -> V_90 = 1 ;
}
if ( F_4 ( V_6 + V_8 ) & 0x80 ) {
if ( V_5 -> V_85 ) {
V_5 -> V_88 = 100 ;
V_5 -> V_61 . V_89 = 1 ;
V_5 -> V_85 = 0 ;
}
}
V_63 ( V_2 , V_5 -> V_73 [ 0 ] , V_91 , V_92 ) ;
F_24 ( 300 ) ;
if ( V_5 -> V_90 )
V_63 ( V_2 , V_5 -> V_73 [ 0 ] , V_82 , V_5 -> V_61 . V_81 | 0x0400 ) ;
V_63 ( V_2 , V_5 -> V_73 [ 0 ] , V_91 , V_93 | V_94 ) ;
if ( ! V_5 -> V_85 ) {
V_22 = 0 ;
V_22 |= ( V_5 -> V_88 == 100 ) ? V_95 : 0 ;
V_22 |= ( V_5 -> V_61 . V_89 ) ? V_96 : 0 ;
V_63 ( V_2 , V_5 -> V_73 [ 0 ] , V_91 , V_22 ) ;
F_5 ( V_71 L_14 ,
V_5 -> V_88 , V_5 -> V_61 . V_89 ? L_15 : L_16 ) ;
}
if ( F_25 ( V_5 ) )
F_5 ( L_17 , F_4 ( V_6 + V_8 ) ) ;
F_1 ( V_2 , 0x00ff << 16 ) ;
if ( F_25 ( V_5 ) )
F_5 ( L_18 , F_4 ( V_6 + V_8 ) ) ;
V_17 ++ ;
return 0 ;
V_83:
F_26 ( V_2 ) ;
V_70:
F_27 ( & V_14 -> V_2 , V_57 ,
V_5 -> V_59 , V_5 -> V_60 ) ;
V_58:
F_27 ( & V_14 -> V_2 , V_51 ,
V_5 -> V_54 , V_5 -> V_56 ) ;
V_53:
F_22 ( V_14 , NULL ) ;
F_28 ( V_14 , V_6 ) ;
V_36:
F_29 ( V_14 ) ;
V_34:
F_30 ( V_2 ) ;
return - V_97 ;
}
static int F_31 ( struct V_1 * V_2 , int V_98 )
{
if ( ( V_98 < 68 ) || ( V_98 > 8191 ) )
return - V_99 ;
if ( F_32 ( V_2 ) )
return - V_100 ;
V_2 -> V_101 = V_98 ;
return 0 ;
}
static int F_17 ( void T_1 * V_6 , int V_102 )
{
int V_103 = 10000 ;
F_33 ( 0x0200 | ( V_102 & 0xff ) , V_6 + V_104 ) ;
do {
F_34 ( V_6 + V_104 ) ;
if ( ! ( F_35 ( V_6 + V_104 ) & 0x8000 ) ) {
return F_35 ( V_6 + V_105 ) ;
}
} while ( -- V_103 > 0 );
return 0 ;
}
static void F_36 ( void T_1 * V_106 )
{
int V_107 = 32 ;
while ( -- V_107 >= 0 ) {
F_37 ( V_108 , V_106 ) ;
F_38 () ;
F_37 ( V_108 | V_109 , V_106 ) ;
F_38 () ;
}
}
static int V_62 ( struct V_1 * V_2 , int V_84 , int V_102 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_106 = V_5 -> V_7 + V_110 ;
int V_111 = ( 0xf6 << 10 ) | ( V_84 << 5 ) | V_102 ;
int V_21 , V_112 = 0 ;
if ( V_5 -> V_74 )
F_36 ( V_106 ) ;
for ( V_21 = 15 ; V_21 >= 0 ; V_21 -- ) {
int V_113 = ( V_111 & ( 1 << V_21 ) ) ? V_108 : V_114 ;
F_37 ( V_113 , V_106 ) ;
F_38 () ;
F_37 ( V_113 | V_109 , V_106 ) ;
F_38 () ;
}
for ( V_21 = 19 ; V_21 > 0 ; V_21 -- ) {
F_37 ( V_115 , V_106 ) ;
F_38 () ;
V_112 = ( V_112 << 1 ) | ( ( F_39 ( V_106 ) & V_116 ) ? 1 : 0 ) ;
F_37 ( V_115 | V_109 , V_106 ) ;
F_38 () ;
}
return ( V_112 >> 1 ) & 0xffff ;
}
static void V_63 ( struct V_1 * V_2 , int V_84 , int V_102 , int V_117 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_106 = V_5 -> V_7 + V_110 ;
int V_111 = ( 0x5002 << 16 ) | ( V_84 << 23 ) | ( V_102 << 18 ) | V_117 ;
int V_21 ;
if ( V_5 -> V_74 )
F_36 ( V_106 ) ;
for ( V_21 = 31 ; V_21 >= 0 ; V_21 -- ) {
int V_113 = ( V_111 & ( 1 << V_21 ) ) ? V_108 : V_114 ;
F_37 ( V_113 , V_106 ) ;
F_38 () ;
F_37 ( V_113 | V_109 , V_106 ) ;
F_38 () ;
}
for ( V_21 = 2 ; V_21 > 0 ; V_21 -- ) {
F_37 ( V_115 , V_106 ) ;
F_38 () ;
F_37 ( V_115 | V_109 , V_106 ) ;
F_38 () ;
}
}
static int F_40 ( struct V_1 * V_2 , int V_118 )
{
int V_119 ;
int V_84 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
V_84 = V_5 -> V_73 [ 0 ] ;
do {
V_119 = V_62 ( V_2 , V_84 , V_80 ) ;
if ( V_119 & 0x0004 )
return 0 ;
F_24 ( 1 ) ;
} while ( -- V_118 > 0 );
return - 1 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_6 = V_5 -> V_7 ;
const int V_20 = V_5 -> V_13 -> V_20 ;
unsigned long V_120 ;
int V_21 ;
F_1 ( V_2 , 0x00ff << 16 ) ;
V_21 = F_42 ( V_20 , V_121 , V_122 , V_2 -> V_12 , V_2 ) ;
if ( V_21 )
return V_21 ;
if ( F_43 ( V_5 ) )
F_5 ( V_123 L_19 , V_2 -> V_12 , V_20 ) ;
F_44 ( V_2 ) ;
F_3 ( V_5 -> V_60 , V_6 + V_124 ) ;
F_45 ( V_2 ) ;
#if F_46 ( V_125 ) || F_46 ( V_126 )
F_33 ( V_2 -> V_101 + 18 , V_6 + V_127 ) ;
#else
F_33 ( V_2 -> V_101 + 14 , V_6 + V_127 ) ;
#endif
if ( V_2 -> V_101 > 2047 )
F_3 ( F_4 ( V_6 + V_8 ) | 0x0C , V_6 + V_8 ) ;
if ( V_2 -> V_128 == 0 )
V_2 -> V_128 = V_5 -> V_129 ;
F_18 ( & V_5 -> V_130 ) ;
F_47 ( V_2 ) ;
F_33 ( 0 , V_6 + V_131 ) ;
F_33 ( 0 , V_6 + V_132 ) ;
F_37 ( 100 , V_6 + V_133 ) ;
F_37 ( 127 , V_6 + V_134 ) ;
if ( V_5 -> V_13 -> V_135 >= 0x14 )
F_37 ( 0x01 , V_6 + V_136 ) ;
F_48 ( V_2 ) ;
F_49 ( & V_5 -> V_45 , V_120 ) ;
F_50 ( V_2 ) ;
F_51 ( & V_5 -> V_45 , V_120 ) ;
F_33 ( V_137 | V_138 | V_139 , V_6 + V_140 ) ;
F_37 ( F_39 ( V_6 + V_141 ) | 0x00 , V_6 + V_141 ) ;
V_5 -> V_142 = 0 ;
if ( F_43 ( V_5 ) )
F_5 ( V_123 L_20
L_21 ,
V_2 -> V_12 , F_4 ( V_6 + V_143 ) , F_39 ( V_6 + V_144 ) ,
F_4 ( V_6 + V_145 ) ,
F_35 ( V_6 + V_140 ) , F_35 ( V_6 + V_145 ) ) ;
F_52 ( & V_5 -> V_146 ) ;
V_5 -> V_146 . V_147 = V_148 + 3 * V_149 ;
V_5 -> V_146 . V_150 = ( unsigned long ) V_2 ;
V_5 -> V_146 . V_151 = V_152 ;
F_53 ( & V_5 -> V_146 ) ;
F_33 ( V_153 , V_6 + V_131 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_6 = V_5 -> V_7 ;
int V_154 = V_62 ( V_2 , V_5 -> V_73 [ 0 ] , V_155 ) ;
int V_156 = V_154 & V_5 -> V_61 . V_81 ;
int V_157 ;
if ( ! V_5 -> V_85 || V_154 == 0xffff ) {
if ( V_5 -> V_61 . V_89 )
F_33 ( F_35 ( V_6 + V_145 ) | V_158 ,
V_6 + V_145 ) ;
return;
}
V_157 = ( V_156 & 0x0100 ) || ( V_156 & 0x01C0 ) == 0x0040 ;
if ( V_5 -> V_61 . V_89 != V_157 ) {
V_5 -> V_61 . V_89 = V_157 ;
if ( F_55 ( V_5 ) )
F_5 ( V_71 L_22
L_23 , V_2 -> V_12 ,
V_157 ? L_24 : L_25 , V_5 -> V_73 [ 0 ] , V_156 ) ;
F_33 ( F_35 ( V_6 + V_145 ) | ( V_157 ? 0x20 : 0 ) , V_6 + V_145 ) ;
}
}
static void V_152 ( unsigned long V_150 )
{
struct V_1 * V_2 = (struct V_1 * ) V_150 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_6 = V_5 -> V_7 ;
int V_159 = 10 * V_149 ;
if ( F_56 ( V_5 ) ) {
F_5 ( V_123 L_26
L_27 ,
V_2 -> V_12 , F_35 ( V_6 + V_131 ) ,
F_39 ( V_6 + V_144 ) , F_4 ( V_6 + V_143 ) ) ;
}
F_54 ( V_2 ) ;
V_5 -> V_146 . V_147 = V_148 + V_159 ;
F_53 ( & V_5 -> V_146 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_6 = V_5 -> V_7 ;
unsigned long V_160 ;
F_58 ( V_2 ) ;
F_59 ( & V_5 -> V_49 ) ;
F_33 ( 0 , V_6 + V_131 ) ;
F_5 ( V_11 L_28
L_29
L_30 , V_2 -> V_12 , F_39 ( V_6 + V_144 ) ,
F_39 ( V_6 + V_161 ) ) ;
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_162 ; V_21 ++ ) {
F_5 ( V_123 L_31 , V_21 ,
( unsigned long long ) ( V_5 -> V_56 + V_21 * sizeof( * V_5 -> V_54 ) ) ,
F_60 ( V_5 -> V_54 [ V_21 ] . V_163 ) ,
F_60 ( V_5 -> V_54 [ V_21 ] . V_164 ) ,
( F_60 ( V_5 -> V_54 [ V_21 ] . V_164 ) >> 2 ) & 0xff ,
F_60 ( V_5 -> V_54 [ V_21 ] . V_165 [ 0 ] . V_166 ) ,
F_60 ( V_5 -> V_54 [ V_21 ] . V_165 [ 0 ] . V_167 ) ) ;
}
F_5 ( V_123 L_32 ,
F_4 ( V_5 -> V_7 + V_168 ) ,
F_61 ( V_2 ) ) ;
F_5 ( V_123 L_33 ,
V_5 -> V_169 , V_5 -> V_169 % V_162 ,
V_5 -> V_170 , V_5 -> V_170 % V_162 ) ;
F_5 ( V_123 L_34 , V_5 -> V_171 , V_5 -> V_172 ) ;
F_5 ( V_123 L_35 , V_5 -> V_173 ) ;
}
F_49 ( & V_5 -> V_45 , V_160 ) ;
F_50 ( V_2 ) ;
F_51 ( & V_5 -> V_45 , V_160 ) ;
V_2 -> V_128 = 0 ;
V_2 -> V_174 = V_148 ;
V_2 -> V_175 . V_176 ++ ;
if ( V_5 -> V_169 - V_5 -> V_170 < V_177 - 4 ) {
F_62 ( V_2 ) ;
}
F_33 ( V_153 , V_6 + V_131 ) ;
F_63 ( & V_5 -> V_49 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_21 ;
V_5 -> V_171 = V_5 -> V_169 = 0 ;
V_5 -> V_172 = V_5 -> V_170 = 0 ;
V_5 -> V_173 = 0 ;
V_5 -> V_178 = ( V_2 -> V_101 <= 1520 ? V_179 : V_2 -> V_101 + 16 ) ;
for ( V_21 = 0 ; V_21 < V_180 ; V_21 ++ ) {
V_5 -> V_59 [ V_21 ] . V_163 = F_64 ( V_5 -> V_60 +
( ( V_21 + 1 ) % V_180 ) * sizeof( * V_5 -> V_59 ) ) ;
V_5 -> V_59 [ V_21 ] . V_164 = 0 ;
V_5 -> V_59 [ V_21 ] . V_165 [ 0 ] . V_167 = 0 ;
V_5 -> V_181 [ V_21 ] = NULL ;
}
for ( V_21 = 0 ; V_21 < V_180 ; V_21 ++ ) {
struct V_182 * V_183 =
F_65 ( V_2 , V_5 -> V_178 + 2 ) ;
V_5 -> V_181 [ V_21 ] = V_183 ;
if ( V_183 == NULL )
break;
F_66 ( V_183 , 2 ) ;
V_5 -> V_59 [ V_21 ] . V_165 [ 0 ] . V_166 = F_64 (
F_67 ( & V_5 -> V_13 -> V_2 , V_183 -> V_150 ,
V_5 -> V_178 , V_184 ) ) ;
if ( F_68 ( & V_5 -> V_13 -> V_2 ,
V_5 -> V_59 [ V_21 ] . V_165 [ 0 ] . V_166 ) ) {
F_69 ( V_183 ) ;
V_5 -> V_181 [ V_21 ] = NULL ;
break;
}
V_5 -> V_59 [ V_21 ] . V_165 [ 0 ] . V_167 = F_64 ( V_5 -> V_178 | V_185 ) ;
}
V_5 -> V_172 = ( unsigned int ) ( V_21 - V_180 ) ;
for ( V_21 = 0 ; V_21 < V_162 ; V_21 ++ ) {
V_5 -> V_186 [ V_21 ] = NULL ;
V_5 -> V_54 [ V_21 ] . V_164 = 0 ;
}
}
static void V_50 ( unsigned long V_150 )
{
struct V_1 * V_2 = (struct V_1 * ) V_150 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned V_187 = V_5 -> V_173 % V_162 ;
struct V_55 * V_188 =
& V_5 -> V_54 [ ( V_5 -> V_169 - 1 ) % V_162 ] ;
for (; V_5 -> V_169 - V_5 -> V_173 > 0 ; V_5 -> V_173 ++ ) {
int V_189 = V_5 -> V_173 % V_162 ;
V_188 = & V_5 -> V_54 [ V_189 ] ;
if ( V_5 -> V_190 ) {
V_5 -> V_190 -> V_163 = F_64 ( V_5 -> V_56 +
V_189 * sizeof( struct V_55 ) ) ;
}
V_5 -> V_190 = V_188 ;
}
V_188 -> V_164 |= F_64 ( V_191 ) ;
if ( F_4 ( V_5 -> V_7 + V_168 ) == 0 )
F_3 ( V_5 -> V_56 + V_187 * sizeof( struct V_55 ) ,
V_5 -> V_7 + V_168 ) ;
}
static T_4
F_70 ( struct V_182 * V_183 , struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_55 * V_188 ;
unsigned V_189 ;
V_189 = V_5 -> V_169 % V_162 ;
V_5 -> V_186 [ V_189 ] = V_183 ;
V_188 = & V_5 -> V_54 [ V_189 ] ;
V_188 -> V_163 = 0 ;
V_188 -> V_164 = F_64 ( ( V_189 << 2 ) | V_192 ) ;
V_188 -> V_165 [ 0 ] . V_166 = F_64 ( F_67 ( & V_5 -> V_13 -> V_2 ,
V_183 -> V_150 , V_183 -> V_193 , V_194 ) ) ;
if ( F_68 ( & V_5 -> V_13 -> V_2 ,
V_188 -> V_165 [ 0 ] . V_166 ) )
goto V_195;
V_188 -> V_165 [ 0 ] . V_167 = F_64 ( V_183 -> V_193 | V_185 ) ;
V_5 -> V_169 ++ ;
F_71 () ;
F_72 ( & V_5 -> V_49 ) ;
if ( V_5 -> V_169 - V_5 -> V_170 < V_177 - 1 &&
! F_61 ( V_2 ) ) {
} else {
F_58 ( V_2 ) ;
}
if ( F_73 ( V_5 ) ) {
F_5 ( V_123
L_36 ,
V_2 -> V_12 , V_5 -> V_169 , V_189 ) ;
}
return V_196 ;
V_195:
F_69 ( V_183 ) ;
V_5 -> V_186 [ V_189 ] = NULL ;
V_2 -> V_175 . V_197 ++ ;
return V_196 ;
}
static int
F_50 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_6 = V_5 -> V_7 ;
struct V_182 * V_183 ;
int V_21 ;
F_33 ( V_198 , V_6 + V_140 ) ;
F_1 ( V_2 , ( V_199 | V_200 | V_201 | V_202 ) << 16 ) ;
for ( V_21 = 0 ; V_21 < V_162 ; V_21 ++ ) {
V_5 -> V_54 [ V_21 ] . V_163 = 0 ;
V_183 = V_5 -> V_186 [ V_21 ] ;
if ( V_183 ) {
F_74 ( & V_5 -> V_13 -> V_2 ,
F_60 ( V_5 -> V_54 [ V_21 ] . V_165 [ 0 ] . V_166 ) ,
V_183 -> V_193 , V_194 ) ;
F_75 ( V_183 ) ;
V_5 -> V_186 [ V_21 ] = NULL ;
V_2 -> V_175 . V_197 ++ ;
}
}
V_5 -> V_169 = V_5 -> V_170 = 0 ;
V_5 -> V_173 = 0 ;
V_5 -> V_190 = NULL ;
F_37 ( 127 , V_6 + V_134 ) ;
F_33 ( V_137 | V_138 | V_139 , V_6 + V_140 ) ;
return 0 ;
}
static T_5 V_121 ( int V_20 , void * V_203 )
{
struct V_1 * V_2 = (struct V_1 * ) V_203 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_6 = V_5 -> V_7 ;
int V_204 ;
int V_205 ;
int V_206 ;
int V_207 = 0 ;
int V_21 ;
do {
int V_208 = F_35 ( V_6 + V_209 ) ;
F_33 ( V_208 , V_6 + V_209 ) ;
if ( F_76 ( V_5 ) )
F_5 ( V_123 L_37 ,
V_2 -> V_12 , V_208 ) ;
if ( ! ( V_208 & V_153 ) )
break;
V_207 = 1 ;
if ( V_208 & ( V_210 ) ) {
F_33 ( V_153 & ~ ( V_211 | V_210 ) ,
V_6 + V_131 ) ;
if ( V_5 -> V_212 < 0 )
V_5 -> V_212 = V_213 ;
F_72 ( & V_5 -> V_47 ) ;
}
if ( V_208 & ( V_214 | V_215 ) ) {
V_206 = F_35 ( V_6 + V_144 ) ;
for ( V_205 = 32 ; V_206 & 0x80 ; -- V_205 ) {
if ( F_77 ( V_5 ) )
F_5
( L_38 ,
V_2 -> V_12 , V_206 ) ;
if ( V_206 & 0x1e ) {
if ( F_78 ( V_5 ) )
F_5 ( L_39 ,
V_2 -> V_12 , V_206 ) ;
V_2 -> V_175 . V_176 ++ ;
if ( V_206 & 0x10 )
V_2 -> V_175 . V_216 ++ ;
if ( V_206 & 0x08 )
V_2 -> V_175 . V_217 ++ ;
if ( V_206 & 0x04 )
V_2 -> V_175 . V_216 ++ ;
if ( V_206 & 0x02 )
V_2 -> V_175 . V_218 ++ ;
if ( V_206 & 0x10 ) {
F_1 ( V_2 , ( V_199 | V_200 | V_202 ) << 16 ) ;
}
V_21 = 10 ;
do {
F_33 ( F_35 ( V_6 + V_140 ) | V_139 , V_6 + V_140 ) ;
if ( F_35 ( V_6 + V_140 ) & V_219 )
break;
F_24 ( 1 ) ;
} while ( -- V_21 );
}
F_33 ( 0 , V_6 + V_144 ) ;
if ( V_205 < 0 ) {
F_3 ( 5000 , V_6 + V_132 ) ;
break;
}
V_206 = F_35 ( V_6 + V_144 ) ;
}
V_204 = ( V_206 >> 8 ) & 0xff ;
} else {
V_204 = F_39 ( V_6 + V_161 ) ;
}
if ( V_5 -> V_13 -> V_135 >= 0x14 ) {
F_79 ( & V_5 -> V_45 ) ;
for (; V_5 -> V_169 - V_5 -> V_170 > 0 ; V_5 -> V_170 ++ ) {
int V_189 = V_5 -> V_170 % V_162 ;
struct V_182 * V_183 ;
int V_220 ;
V_220 = ( F_60 (
V_5 -> V_54 [ V_189 ] . V_164 ) >> 2 ) & 0xff ;
if ( V_220 == V_204 &&
! ( F_60 ( V_5 -> V_54 [ V_189 ] . V_164 )
& 0x00010000 ) )
break;
if ( V_220 == ( V_204 + 1 ) %
V_162 )
break;
V_183 = V_5 -> V_186 [ V_189 ] ;
F_74 ( & V_5 -> V_13 -> V_2 ,
F_60 ( V_5 -> V_54 [ V_189 ] . V_165 [ 0 ] . V_166 ) ,
V_183 -> V_193 , V_194 ) ;
F_80 ( V_5 -> V_186 [ V_189 ] ) ;
V_5 -> V_186 [ V_189 ] = NULL ;
V_5 -> V_54 [ V_189 ] . V_165 [ 0 ] . V_166 = 0 ;
V_5 -> V_54 [ V_189 ] . V_165 [ 0 ] . V_167 = 0 ;
}
F_81 ( & V_5 -> V_45 ) ;
} else {
F_79 ( & V_5 -> V_45 ) ;
for (; V_5 -> V_169 - V_5 -> V_170 > 0 ; V_5 -> V_170 ++ ) {
int V_189 = V_5 -> V_170 % V_162 ;
struct V_182 * V_183 ;
if ( ! ( F_60 ( V_5 -> V_54 [ V_189 ] . V_164 )
& 0x00010000 ) )
break;
V_183 = V_5 -> V_186 [ V_189 ] ;
F_74 ( & V_5 -> V_13 -> V_2 ,
F_60 ( V_5 -> V_54 [ V_189 ] . V_165 [ 0 ] . V_166 ) ,
V_183 -> V_193 , V_194 ) ;
F_80 ( V_5 -> V_186 [ V_189 ] ) ;
V_5 -> V_186 [ V_189 ] = NULL ;
V_5 -> V_54 [ V_189 ] . V_165 [ 0 ] . V_166 = 0 ;
V_5 -> V_54 [ V_189 ] . V_165 [ 0 ] . V_167 = 0 ;
}
F_81 ( & V_5 -> V_45 ) ;
}
if ( F_61 ( V_2 ) &&
V_5 -> V_169 - V_5 -> V_170 < V_177 - 4 ) {
F_62 ( V_2 ) ;
}
if ( V_208 & ( V_221 | V_222 | V_223 ) )
F_82 ( V_2 , V_208 ) ;
} while ( 0 );
if ( F_76 ( V_5 ) )
F_5 ( V_123 L_40 ,
V_2 -> V_12 , F_35 ( V_6 + V_209 ) ) ;
return F_83 ( V_207 ) ;
}
static void V_48 ( unsigned long V_150 )
{
struct V_1 * V_2 = (struct V_1 * ) V_150 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_189 = V_5 -> V_171 % V_180 ;
int V_103 = V_5 -> V_212 ;
void T_1 * V_6 = V_5 -> V_7 ;
int V_224 = 0 ;
while ( 1 ) {
struct V_55 * V_225 = & ( V_5 -> V_59 [ V_189 ] ) ;
T_6 V_226 = F_60 ( V_225 -> V_164 ) ;
int V_227 ;
if ( -- V_103 < 0 ) {
goto V_228;
}
if ( ! ( V_226 & V_229 ) )
break;
V_227 = V_226 & 0x1fff ;
if ( F_84 ( V_5 ) )
F_5 ( V_123 L_41 ,
V_226 ) ;
if ( V_226 & 0x001f4000 ) {
if ( F_85 ( V_5 ) )
F_5 ( V_123 L_42 ,
V_226 ) ;
V_2 -> V_175 . V_230 ++ ;
if ( V_226 & 0x00100000 )
V_2 -> V_175 . V_231 ++ ;
if ( V_226 & 0x00010000 )
V_2 -> V_175 . V_232 ++ ;
if ( V_226 & 0x00060000 )
V_2 -> V_175 . V_233 ++ ;
if ( V_226 & 0x00080000 )
V_2 -> V_175 . V_234 ++ ;
if ( V_226 & 0x00100000 ) {
F_5 ( V_11 L_43
L_44 ,
V_2 -> V_12 , V_226 ) ;
}
} else {
struct V_182 * V_183 ;
#ifndef F_86
if ( F_84 ( V_5 ) )
F_5 ( V_123 L_45
L_46 ,
V_227 , V_103 ) ;
#endif
if ( V_227 < V_235 &&
( V_183 = F_65 ( V_2 , V_227 + 2 ) ) != NULL ) {
F_66 ( V_183 , 2 ) ;
F_87 ( & V_5 -> V_13 -> V_2 ,
F_60 ( V_225 -> V_165 [ 0 ] . V_166 ) ,
V_5 -> V_178 , V_184 ) ;
F_88 ( V_183 , V_5 -> V_181 [ V_189 ] -> V_150 , V_227 ) ;
F_89 ( & V_5 -> V_13 -> V_2 ,
F_60 ( V_225 -> V_165 [ 0 ] . V_166 ) ,
V_5 -> V_178 , V_184 ) ;
F_90 ( V_183 , V_227 ) ;
} else {
F_74 ( & V_5 -> V_13 -> V_2 ,
F_60 ( V_225 -> V_165 [ 0 ] . V_166 ) ,
V_5 -> V_178 , V_184 ) ;
F_90 ( V_183 = V_5 -> V_181 [ V_189 ] , V_227 ) ;
V_5 -> V_181 [ V_189 ] = NULL ;
}
V_183 -> V_236 = F_91 ( V_183 , V_2 ) ;
F_92 ( V_183 ) ;
}
V_189 = ( V_189 + 1 ) % V_180 ;
V_224 ++ ;
}
V_5 -> V_171 = V_189 ;
F_93 ( V_2 ) ;
V_5 -> V_212 -= V_224 ;
F_33 ( V_153 , V_6 + V_131 ) ;
return;
V_228:
V_5 -> V_171 = V_189 ;
F_93 ( V_2 ) ;
if ( ! V_224 )
V_224 = 1 ;
V_5 -> V_212 -= V_224 ;
if ( V_5 -> V_212 <= 0 )
V_5 -> V_212 = V_213 ;
F_72 ( & V_5 -> V_47 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_189 ;
int V_237 = 0 ;
for (; ( V_5 -> V_171 - V_5 -> V_172 + V_180 ) % V_180 > 0 ;
V_5 -> V_172 = ( V_5 -> V_172 + 1 ) % V_180 ) {
struct V_182 * V_183 ;
V_189 = V_5 -> V_172 % V_180 ;
if ( V_5 -> V_181 [ V_189 ] == NULL ) {
V_183 = F_65 ( V_2 , V_5 -> V_178 + 2 ) ;
V_5 -> V_181 [ V_189 ] = V_183 ;
if ( V_183 == NULL )
break;
F_66 ( V_183 , 2 ) ;
V_5 -> V_59 [ V_189 ] . V_165 [ 0 ] . V_166 = F_64 (
F_67 ( & V_5 -> V_13 -> V_2 , V_183 -> V_150 ,
V_5 -> V_178 , V_184 ) ) ;
if ( F_68 ( & V_5 -> V_13 -> V_2 ,
V_5 -> V_59 [ V_189 ] . V_165 [ 0 ] . V_166 ) ) {
F_80 ( V_183 ) ;
V_5 -> V_181 [ V_189 ] = NULL ;
break;
}
}
V_5 -> V_59 [ V_189 ] . V_165 [ 0 ] . V_167 =
F_64 ( V_5 -> V_178 | V_185 ) ;
V_5 -> V_59 [ V_189 ] . V_164 = 0 ;
V_237 ++ ;
}
}
static void F_82 ( struct V_1 * V_2 , int V_208 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_6 = V_5 -> V_7 ;
T_2 V_22 , V_238 , V_154 ;
int V_88 ;
if ( V_208 & V_222 ) {
if ( F_40 ( V_2 , 10 ) == 0 ) {
F_5 ( V_71 L_47 , V_2 -> V_12 ) ;
if ( V_5 -> V_85 ) {
V_238 = V_62 ( V_2 , V_5 -> V_73 [ 0 ] ,
V_82 ) ;
V_154 = V_62 ( V_2 , V_5 -> V_73 [ 0 ] , V_155 ) ;
V_238 &= V_154 ;
F_5 ( V_71 L_48 ,
V_2 -> V_12 ) ;
if ( V_238 & V_239 ) {
V_5 -> V_88 = 100 ;
F_5 ( L_49 ) ;
} else if ( V_238 & V_240 ) {
V_5 -> V_88 = 100 ;
F_5 ( L_50 ) ;
} else if ( V_238 & V_241 ) {
V_5 -> V_88 = 10 ;
F_5 ( L_51 ) ;
} else if ( V_238 & V_242 ) {
V_5 -> V_88 = 10 ;
F_5 ( L_52 ) ;
} else
F_5 ( L_53 ) ;
} else {
V_22 = V_62 ( V_2 , V_5 -> V_73 [ 0 ] , V_91 ) ;
V_88 = ( V_22 & V_95 ) ? 100 : 10 ;
V_5 -> V_88 = V_88 ;
F_5 ( V_71 L_54 ,
V_2 -> V_12 , V_88 ) ;
F_5 ( L_55 ,
( V_22 & V_96 ) ?
L_24 : L_25 ) ;
}
F_54 ( V_2 ) ;
if ( V_5 -> V_90 && V_5 -> V_61 . V_89 ) {
F_33 ( F_35 ( V_6 + V_243 + 2 ) | 0x0200 ,
V_6 + V_243 + 2 ) ;
F_33 ( F_35 ( V_6 + V_145 ) | V_244 ,
V_6 + V_145 ) ;
}
F_94 ( V_2 ) ;
} else {
F_5 ( V_71 L_56 , V_2 -> V_12 ) ;
F_95 ( V_2 ) ;
}
}
if ( V_208 & V_223 ) {
F_96 ( V_2 ) ;
}
if ( V_208 & V_221 ) {
F_5 ( V_245 L_57 ,
V_2 -> V_12 , V_208 ) ;
}
}
static struct V_246 * F_96 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_6 = V_5 -> V_7 ;
unsigned long V_120 ;
T_7 V_247 , V_248 , V_249 ;
F_49 ( & V_5 -> V_46 , V_120 ) ;
V_2 -> V_175 . V_250 += F_39 ( V_6 + V_251 ) ;
V_2 -> V_175 . V_252 += F_35 ( V_6 + V_253 ) ;
V_2 -> V_175 . V_254 += F_35 ( V_6 + V_255 ) ;
V_2 -> V_175 . V_256 += F_39 ( V_6 + V_257 ) ;
V_249 = F_39 ( V_6 + V_258 ) ;
V_5 -> V_259 . V_260 += V_249 ;
V_248 = F_39 ( V_6 + V_261 ) ;
V_5 -> V_259 . V_262 += V_248 ;
V_247 = F_39 ( V_6 + V_263 ) ;
V_5 -> V_259 . V_264 += V_247 ;
V_2 -> V_175 . V_217 += V_249
+ V_248
+ V_247 ;
V_5 -> V_259 . V_265 += F_39 ( V_6 + V_266 ) ;
V_5 -> V_259 . V_267 += F_39 ( V_6 + V_268 ) ;
V_5 -> V_259 . V_269 += F_39 ( V_6 + V_270 ) ;
V_5 -> V_259 . V_271 += F_39 ( V_6 + V_272 ) ;
V_5 -> V_259 . V_273 += F_39 ( V_6 + V_274 ) ;
V_5 -> V_259 . V_275 += F_39 ( V_6 + V_276 ) ;
V_5 -> V_259 . V_277 += F_39 ( V_6 + V_278 ) ;
V_2 -> V_175 . V_279 += F_35 ( V_6 + V_280 ) ;
V_2 -> V_175 . V_279 += F_35 ( V_6 + V_281 ) << 16 ;
V_2 -> V_175 . V_282 += F_35 ( V_6 + V_283 ) ;
V_2 -> V_175 . V_282 += F_35 ( V_6 + V_284 ) << 16 ;
F_51 ( & V_5 -> V_46 , V_120 ) ;
return & V_2 -> V_175 ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_6 = V_5 -> V_7 ;
T_2 V_285 [ 4 ] ;
T_6 V_286 ;
int V_21 ;
if ( V_2 -> V_120 & V_287 ) {
memset ( V_285 , 0xff , sizeof( V_285 ) ) ;
V_286 = V_288 | V_289 | V_290 | V_291 ;
} else if ( ( F_97 ( V_2 ) > V_292 ) ||
( V_2 -> V_120 & V_293 ) ) {
memset ( V_285 , 0xff , sizeof( V_285 ) ) ;
V_286 = V_288 | V_289 | V_291 ;
} else if ( ! F_98 ( V_2 ) ) {
struct V_294 * V_295 ;
int V_296 ;
int V_297 ;
int V_298 ;
memset ( V_285 , 0 , sizeof ( V_285 ) ) ;
F_99 (ha, dev) {
V_298 = F_100 ( V_299 , V_295 -> V_166 ) ;
for ( V_297 = 0 , V_296 = 0 ; V_296 < 6 ; V_296 ++ , V_298 <<= 1 )
if ( V_298 & 0x80000000 ) V_297 |= 1 << V_296 ;
V_285 [ V_297 / 16 ] |= ( 1 << ( V_297 % 16 ) ) ;
}
V_286 = V_288 | V_300 | V_291 ;
} else {
F_37 ( V_288 | V_291 , V_6 + V_301 ) ;
return;
}
if ( V_5 -> V_61 . V_89 && V_5 -> V_90 )
V_285 [ 3 ] |= 0x0200 ;
for ( V_21 = 0 ; V_21 < 4 ; V_21 ++ )
F_33 ( V_285 [ V_21 ] , V_6 + V_302 + V_21 * 2 ) ;
F_37 ( V_286 , V_6 + V_301 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_303 ;
V_303 = ( V_2 -> V_38 [ 0 ] | ( V_2 -> V_38 [ 1 ] << 8 ) ) ;
F_33 ( V_303 , V_5 -> V_7 + V_304 ) ;
V_303 = ( V_2 -> V_38 [ 2 ] | ( V_2 -> V_38 [ 3 ] << 8 ) ) ;
F_33 ( V_303 , V_5 -> V_7 + V_304 + 2 ) ;
V_303 = ( V_2 -> V_38 [ 4 ] | ( V_2 -> V_38 [ 5 ] << 8 ) ) ;
F_33 ( V_303 , V_5 -> V_7 + V_304 + 4 ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 , void * V_150 )
{
const struct V_305 * V_166 = V_150 ;
if ( ! F_102 ( V_166 -> V_306 ) )
return - V_307 ;
memcpy ( V_2 -> V_38 , V_166 -> V_306 , V_299 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
if ( ! F_32 ( V_2 ) )
return - V_99 ;
return 0 ;
}
static void F_104 ( struct V_1 * V_2 , struct V_308 * V_309 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_105 ( V_309 -> V_310 , V_33 , sizeof( V_309 -> V_310 ) ) ;
F_105 ( V_309 -> V_30 , V_311 , sizeof( V_309 -> V_30 ) ) ;
F_105 ( V_309 -> V_312 , F_106 ( V_5 -> V_13 ) , sizeof( V_309 -> V_312 ) ) ;
}
static int F_107 ( struct V_1 * V_2 , struct V_313 * V_314 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_108 ( & V_5 -> V_45 ) ;
F_109 ( & V_5 -> V_61 , V_314 ) ;
F_110 ( & V_5 -> V_45 ) ;
return 0 ;
}
static int F_111 ( struct V_1 * V_2 , struct V_313 * V_314 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_315 ;
F_108 ( & V_5 -> V_45 ) ;
V_315 = F_112 ( & V_5 -> V_61 , V_314 ) ;
F_110 ( & V_5 -> V_45 ) ;
return V_315 ;
}
static int F_113 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_114 ( & V_5 -> V_61 ) ;
}
static T_6 F_115 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_116 ( & V_5 -> V_61 ) ;
}
static T_6 F_117 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_43 ;
}
static void F_118 ( struct V_1 * V_2 , T_6 V_316 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_43 = V_316 ;
}
static void F_119 ( struct V_1 * V_2 , T_6 V_317 ,
T_7 * V_150 )
{
if ( V_317 == V_318 )
memcpy ( V_150 , V_319 , sizeof( V_319 ) ) ;
}
static int F_120 ( struct V_1 * V_2 , int V_320 )
{
switch ( V_320 ) {
case V_318 :
return F_121 ( V_319 ) ;
default:
return - V_321 ;
}
}
static void F_122 ( struct V_1 * V_2 ,
struct V_322 * V_175 , T_8 * V_150 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_21 = 0 ;
F_96 ( V_2 ) ;
V_150 [ V_21 ++ ] = V_5 -> V_259 . V_260 ;
V_150 [ V_21 ++ ] = V_5 -> V_259 . V_262 ;
V_150 [ V_21 ++ ] = V_5 -> V_259 . V_264 ;
V_150 [ V_21 ++ ] = V_5 -> V_259 . V_265 ;
V_150 [ V_21 ++ ] = V_5 -> V_259 . V_267 ;
V_150 [ V_21 ++ ] = V_5 -> V_259 . V_269 ;
V_150 [ V_21 ++ ] = V_5 -> V_259 . V_271 ;
V_150 [ V_21 ++ ] = V_5 -> V_259 . V_273 ;
V_150 [ V_21 ++ ] = V_5 -> V_259 . V_275 ;
V_150 [ V_21 ++ ] = V_5 -> V_259 . V_277 ;
}
static void F_123 ( struct V_1 * V_2 ,
struct V_323 * V_324 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_6 = V_5 -> V_7 ;
T_7 V_325 ;
V_324 -> V_326 = 0 ;
V_324 -> V_327 = ( V_328 | V_329 ) ;
if ( ! V_5 -> V_142 )
return;
V_325 = F_39 ( V_6 + V_141 ) ;
if ( V_325 & V_330 )
V_324 -> V_326 |= V_329 ;
if ( V_325 & V_331 )
V_324 -> V_326 |= V_328 ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_323 * V_324 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_6 = V_5 -> V_7 ;
T_7 V_325 ;
if ( ! F_125 ( & V_5 -> V_13 -> V_2 ) )
return - V_321 ;
V_5 -> V_142 = ! ! ( V_324 -> V_326 ) ;
V_325 = F_39 ( V_6 + V_141 ) ;
V_325 &= ~ ( V_332 | V_330 |
V_331 | V_333 ) ;
if ( V_5 -> V_142 ) {
if ( V_324 -> V_326 & V_329 )
V_325 |= ( V_330 | V_333 ) ;
if ( V_324 -> V_326 & V_328 )
V_325 |= ( V_331 | V_333 ) ;
}
F_37 ( V_325 , V_6 + V_141 ) ;
F_126 ( & V_5 -> V_13 -> V_2 , V_5 -> V_142 ) ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 , struct V_334 * V_335 , int V_336 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_337 ;
if ( ! F_32 ( V_2 ) )
return - V_99 ;
F_108 ( & V_5 -> V_45 ) ;
V_337 = F_128 ( & V_5 -> V_61 , F_129 ( V_335 ) , V_336 , NULL ) ;
F_110 ( & V_5 -> V_45 ) ;
return V_337 ;
}
static int F_130 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_6 = V_5 -> V_7 ;
struct V_182 * V_183 ;
int V_21 ;
F_131 ( & V_5 -> V_47 ) ;
F_131 ( & V_5 -> V_49 ) ;
V_5 -> V_169 = 0 ;
V_5 -> V_170 = 0 ;
V_5 -> V_173 = 0 ;
V_5 -> V_190 = NULL ;
F_58 ( V_2 ) ;
if ( F_132 ( V_5 ) ) {
F_5 ( V_123 L_58
L_59 ,
V_2 -> V_12 , F_39 ( V_6 + V_144 ) ,
F_4 ( V_6 + V_143 ) , F_35 ( V_6 + V_209 ) ) ;
F_5 ( V_123 L_60 ,
V_2 -> V_12 , V_5 -> V_169 , V_5 -> V_170 , V_5 -> V_171 , V_5 -> V_172 ) ;
}
F_33 ( 0x0000 , V_6 + V_131 ) ;
F_3 ( 0x500 , V_6 + V_338 ) ;
F_33 ( V_198 | V_339 | V_340 , V_6 + V_140 ) ;
for ( V_21 = 2000 ; V_21 > 0 ; V_21 -- ) {
if ( ( F_4 ( V_6 + V_338 ) & 0xc000 ) == 0 )
break;
F_24 ( 1 ) ;
}
F_33 ( V_341 | V_201 | V_200 | V_199 ,
V_6 + F_133 ( V_8 ) ) ;
for ( V_21 = 2000 ; V_21 > 0 ; V_21 -- ) {
if ( ( F_35 ( V_6 + F_133 ( V_8 ) ) & V_10 ) == 0 )
break;
F_24 ( 1 ) ;
}
#ifdef F_134
if ( F_25 ( V_5 ) ) {
F_5 ( V_123 L_61 ,
( int ) ( V_5 -> V_56 ) ) ;
for ( V_21 = 0 ; V_21 < V_162 ; V_21 ++ )
F_5 ( V_123 L_62 ,
V_21 , V_5 -> V_54 [ V_21 ] . V_164 , V_5 -> V_54 [ V_21 ] . V_165 [ 0 ] . V_166 ,
V_5 -> V_54 [ V_21 ] . V_165 [ 0 ] . V_167 ) ;
F_5 ( V_123 L_63 ,
( int ) ( V_5 -> V_60 ) ) ;
for ( V_21 = 0 ; V_21 < 4 ; V_21 ++ ) {
F_5 ( V_123 L_64 ,
V_21 , V_5 -> V_59 [ V_21 ] . V_164 , V_5 -> V_59 [ V_21 ] . V_165 [ 0 ] . V_166 ,
V_5 -> V_59 [ V_21 ] . V_165 [ 0 ] . V_167 ) ;
}
}
#endif
F_135 ( V_5 -> V_13 -> V_20 , V_2 ) ;
F_136 ( & V_5 -> V_146 ) ;
for ( V_21 = 0 ; V_21 < V_180 ; V_21 ++ ) {
V_5 -> V_59 [ V_21 ] . V_164 = 0 ;
V_183 = V_5 -> V_181 [ V_21 ] ;
if ( V_183 ) {
F_74 ( & V_5 -> V_13 -> V_2 ,
F_60 ( V_5 -> V_59 [ V_21 ] . V_165 [ 0 ] . V_166 ) ,
V_5 -> V_178 , V_184 ) ;
F_69 ( V_183 ) ;
V_5 -> V_181 [ V_21 ] = NULL ;
}
V_5 -> V_59 [ V_21 ] . V_165 [ 0 ] . V_166 = F_64 ( 0xBADF00D0 ) ;
}
for ( V_21 = 0 ; V_21 < V_162 ; V_21 ++ ) {
V_5 -> V_54 [ V_21 ] . V_163 = 0 ;
V_183 = V_5 -> V_186 [ V_21 ] ;
if ( V_183 ) {
F_74 ( & V_5 -> V_13 -> V_2 ,
F_60 ( V_5 -> V_54 [ V_21 ] . V_165 [ 0 ] . V_166 ) ,
V_183 -> V_193 , V_194 ) ;
F_69 ( V_183 ) ;
V_5 -> V_186 [ V_21 ] = NULL ;
}
}
return 0 ;
}
static void F_137 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_138 ( V_14 ) ;
if ( V_2 ) {
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( & V_14 -> V_2 , V_57 ,
V_5 -> V_59 , V_5 -> V_60 ) ;
F_27 ( & V_14 -> V_2 , V_51 ,
V_5 -> V_54 , V_5 -> V_56 ) ;
F_28 ( V_14 , V_5 -> V_7 ) ;
F_29 ( V_14 ) ;
F_30 ( V_2 ) ;
F_22 ( V_14 , NULL ) ;
}
}
static int F_139 ( struct V_13 * V_13 , T_9 V_342 )
{
struct V_1 * V_2 = F_138 ( V_13 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_6 = V_5 -> V_7 ;
if ( ! F_32 ( V_2 ) )
return 0 ;
F_130 ( V_2 ) ;
F_140 ( V_2 ) ;
F_141 ( V_13 ) ;
if ( V_5 -> V_142 ) {
F_37 ( V_288 | V_291 , V_6 + V_301 ) ;
F_33 ( V_138 , V_6 + V_140 ) ;
}
F_142 ( V_13 , F_143 ( V_13 , V_342 ) ,
V_5 -> V_142 ) ;
F_144 ( V_13 , F_143 ( V_13 , V_342 ) ) ;
return 0 ;
}
static int F_145 ( struct V_13 * V_13 )
{
struct V_1 * V_2 = F_138 ( V_13 ) ;
int V_343 = 0 ;
if ( ! F_32 ( V_2 ) )
return 0 ;
F_144 ( V_13 , V_344 ) ;
F_146 ( V_13 ) ;
F_142 ( V_13 , V_344 , 0 ) ;
V_343 = F_41 ( V_2 ) ;
if ( V_343 ) {
F_5 ( V_245 L_65 ,
V_2 -> V_12 ) ;
goto V_345;
}
F_147 ( V_2 ) ;
V_345:
return V_343 ;
}
static int T_10 F_148 ( void )
{
#ifdef F_9
F_5 ( V_30 ) ;
#endif
return F_149 ( & V_346 ) ;
}
static void T_11 F_150 ( void )
{
F_151 ( & V_346 ) ;
}
