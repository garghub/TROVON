void F_1 ( struct V_1 * V_2 , int V_3 )
{
#ifdef F_2
struct V_4 * V_5 = F_3 ( V_2 ) ;
memcpy ( V_5 -> V_6 , F_4 ( V_2 ) -> V_7 , sizeof( V_5 -> V_6 ) ) ;
memcpy ( & F_5 () -> V_8 , F_4 ( V_2 ) -> V_8 ,
sizeof( F_5 () -> V_8 ) ) ;
V_5 -> V_9 = F_4 ( V_2 ) -> V_10 ;
F_6 ( V_5 ) ;
#endif
#ifdef F_7
V_11 -> V_12 . V_13 = F_4 ( V_2 ) -> V_8 ;
#endif
}
void F_8 ( struct V_1 * V_2 )
{
#ifdef F_2
struct V_4 * V_5 = F_3 ( V_2 ) ;
memcpy ( F_4 ( V_2 ) -> V_7 , V_5 -> V_6 , sizeof( V_5 -> V_6 ) ) ;
memcpy ( F_4 ( V_2 ) -> V_8 , & F_5 () -> V_8 ,
sizeof( F_5 () -> V_8 ) ) ;
F_4 ( V_2 ) -> V_10 = V_5 -> V_9 ;
F_6 ( V_5 ) ;
#endif
F_9 ( V_2 , V_14 ) ;
F_9 ( V_2 , V_15 ) ;
F_9 ( V_2 , V_16 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 V_17 = V_2 -> V_18 . V_19 -> V_20 ;
V_17 &= V_21 | V_22 | V_23 | V_24 | V_25 | V_26 ;
V_17 |= V_27 | V_28 | V_29 | V_30 | V_31 | V_32 ;
V_17 |= ( V_2 -> V_18 . V_19 -> V_20 & V_2 -> V_18 . V_33 ) ;
#ifdef F_2
V_17 |= V_34 | V_35 ;
#endif
V_2 -> V_18 . V_36 = V_17 ;
}
void F_11 ( struct V_1 * V_2 , T_2 V_20 )
{
T_1 V_37 = V_2 -> V_18 . V_19 -> V_20 ;
#ifdef F_12
F_13 ( V_38 L_1 , V_20 ) ;
#endif
V_20 &= F_4 ( V_2 ) -> V_39 ;
V_2 -> V_18 . V_19 -> V_20 = V_20 ;
F_10 ( V_2 ) ;
if ( V_20 & V_40 ) {
if ( ! V_2 -> V_18 . V_41 ) {
F_14 ( V_2 ) ;
F_15 ( V_42 , & V_2 -> V_43 ) ;
V_2 -> V_44 . V_45 ++ ;
V_20 &= ~ V_40 ;
V_2 -> V_18 . V_19 -> V_20 = V_20 ;
}
}
if ( ( V_2 -> V_18 . V_19 -> V_20 & ( V_31 | V_29 | V_30 ) ) !=
( V_37 & ( V_31 | V_29 | V_30 ) ) ) {
F_16 ( V_2 ) ;
F_17 ( V_2 , F_18 ( V_2 ) ) ;
if ( ! ( V_20 & V_31 ) && V_2 -> V_18 . V_46 ) {
struct V_47 * V_48 = & V_2 -> V_18 ;
if ( V_20 & V_30 )
F_17 ( V_2 , V_48 -> V_49 ) ;
else
F_17 ( V_2 , V_48 -> V_46 ) ;
}
}
if ( V_2 -> V_18 . V_46 &&
! ( V_37 & V_31 ) && ! ( V_37 & V_23 ) && ( V_20 & V_23 ) ) {
F_19 ( V_2 , ( V_50 ) V_2 -> V_18 . V_46 ,
~ 0xFFFUL ) ;
}
if ( V_2 -> V_18 . V_19 -> V_20 & V_14 )
F_20 ( V_2 , V_51 , V_14 ) ;
}
void F_21 ( struct V_1 * V_2 , T_3 V_52 )
{
T_3 V_53 ;
V_2 -> V_18 . V_54 &= ~ V_55 ;
V_2 -> V_18 . V_52 = V_52 ;
#ifdef F_2
if ( ( V_52 >= 0x330000 ) && ( V_52 < 0x70330000 ) ) {
F_22 ( V_2 ) ;
if ( ! F_4 ( V_2 ) -> V_56 )
F_4 ( V_2 ) -> V_57 = 0xfff00000 ;
F_4 ( V_2 ) -> V_39 = 0xffffffffffffffffULL ;
V_2 -> V_18 . V_58 = V_59 ;
} else
#endif
{
F_23 ( V_2 ) ;
if ( ! F_4 ( V_2 ) -> V_56 )
F_4 ( V_2 ) -> V_57 = 0 ;
F_4 ( V_2 ) -> V_39 = 0xffffffffULL ;
V_2 -> V_18 . V_58 = V_60 ;
}
F_24 ( V_2 ) ;
V_2 -> V_18 . V_54 &= ~ V_61 ;
if ( V_2 -> V_18 . V_62 . V_63 ( V_2 ) && ( F_25 () & V_35 ) &&
! strcmp ( V_64 -> V_65 , L_2 ) )
V_2 -> V_18 . V_54 |= V_61 ;
if ( ! strcmp ( V_64 -> V_65 , L_3 ) )
F_4 ( V_2 ) -> V_39 &= ~ ( V_21 | V_22 ) ;
#ifdef F_7
V_2 -> V_18 . V_54 |= V_61 ;
#endif
asm ( "mfpvr %0" : "=r"(host_pvr));
switch ( V_53 ) {
case 0x00080200 :
case 0x00088202 :
case 0x70000100 :
case 0x00080100 :
case 0x00083203 :
case 0x00083213 :
case 0x00083204 :
case 0x00083214 :
case 0x00087200 :
V_2 -> V_18 . V_54 |= V_66 ;
F_26 ( V_67 , F_27 ( V_67 ) | ( 1 << 29 ) ) ;
}
}
static void F_28 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
struct V_70 * V_71 ;
T_2 V_72 ;
T_3 * V_70 ;
int V_73 ;
V_71 = F_29 ( V_2 -> V_74 , V_69 -> V_75 >> V_76 ) ;
if ( F_30 ( V_71 ) ) {
F_31 ( V_71 ) ;
return;
}
V_72 = V_69 -> V_75 & ~ V_77 ;
V_72 &= ~ 0xFFFULL ;
V_72 /= 4 ;
F_32 ( V_71 ) ;
V_70 = F_33 ( V_71 ) ;
for ( V_73 = V_72 ; V_73 < V_72 + ( V_78 / 4 ) ; V_73 ++ )
if ( ( V_70 [ V_73 ] & 0xff0007ff ) == V_79 )
V_70 [ V_73 ] &= 0xfffffff7 ;
F_34 ( V_70 ) ;
F_35 ( V_71 ) ;
}
static int F_36 ( struct V_1 * V_2 , T_4 V_80 )
{
T_1 V_81 = V_2 -> V_18 . V_46 ;
if ( ! ( V_2 -> V_18 . V_19 -> V_20 & V_23 ) )
V_81 = ( V_50 ) V_81 ;
if ( F_37 ( V_81 ) &&
F_37 ( ( V_81 & V_82 ) >> V_76 == V_80 ) ) {
return 1 ;
}
return F_38 ( V_2 -> V_74 , V_80 ) ;
}
int F_39 ( struct V_83 * V_84 , struct V_1 * V_2 ,
T_1 V_85 , int V_86 )
{
bool V_87 = ( V_86 == V_88 ) ;
int V_89 = V_90 ;
int V_91 ;
int V_92 = 0 ;
struct V_68 V_69 ;
bool V_93 = false ;
bool V_94 = ( V_2 -> V_18 . V_19 -> V_20 & V_30 ) ? true : false ;
bool V_95 = ( V_2 -> V_18 . V_19 -> V_20 & V_29 ) ? true : false ;
T_2 V_96 ;
V_91 = V_87 ? V_94 : V_95 ;
if ( V_91 ) {
V_92 = V_2 -> V_18 . V_62 . V_97 ( V_2 , V_85 , & V_69 , V_87 ) ;
} else {
V_69 . V_98 = true ;
V_69 . V_99 = true ;
V_69 . V_100 = true ;
V_69 . V_75 = V_85 & V_82 ;
V_69 . V_85 = V_85 ;
V_69 . V_101 = V_85 >> 12 ;
}
switch ( V_2 -> V_18 . V_19 -> V_20 & ( V_30 | V_29 ) ) {
case 0 :
V_69 . V_101 |= ( ( T_2 ) V_102 << ( V_103 - 12 ) ) ;
break;
case V_30 :
case V_29 :
V_2 -> V_18 . V_62 . V_104 ( V_2 , V_85 >> V_103 , & V_96 ) ;
if ( ( V_2 -> V_18 . V_19 -> V_20 & ( V_30 | V_29 ) ) == V_30 )
V_69 . V_101 |= ( ( T_2 ) V_105 << ( V_103 - 12 ) ) ;
else
V_69 . V_101 |= ( ( T_2 ) V_106 << ( V_103 - 12 ) ) ;
V_69 . V_101 |= V_96 ;
if ( V_96 == - 1 )
V_92 = - V_107 ;
break;
}
if ( V_2 -> V_18 . V_62 . V_63 ( V_2 ) &&
( ! ( V_2 -> V_18 . V_54 & V_61 ) ) ) {
V_69 . V_98 = ! V_87 ;
}
if ( V_92 == - V_108 ) {
struct V_4 * V_5 = F_3 ( V_2 ) ;
V_2 -> V_18 . V_19 -> V_109 = F_40 ( V_2 ) ;
V_2 -> V_18 . V_19 -> V_110 = V_5 -> V_111 ;
V_2 -> V_18 . V_19 -> V_20 |=
( V_5 -> V_112 & 0x00000000f8000000ULL ) ;
F_6 ( V_5 ) ;
F_41 ( V_2 , V_86 ) ;
} else if ( V_92 == - V_113 ) {
struct V_4 * V_5 = F_3 ( V_2 ) ;
V_2 -> V_18 . V_19 -> V_109 = F_40 ( V_2 ) ;
V_2 -> V_18 . V_19 -> V_110 = V_5 -> V_111 & ~ V_114 ;
V_2 -> V_18 . V_19 -> V_110 |= V_115 ;
V_2 -> V_18 . V_19 -> V_20 |=
V_5 -> V_112 & 0x00000000f8000000ULL ;
F_6 ( V_5 ) ;
F_41 ( V_2 , V_86 ) ;
} else if ( V_92 == - V_107 ) {
V_2 -> V_18 . V_19 -> V_109 = F_40 ( V_2 ) ;
F_41 ( V_2 , V_86 + 0x80 ) ;
} else if ( ! V_93 &&
F_36 ( V_2 , V_69 . V_75 >> V_76 ) ) {
F_42 ( V_2 , & V_69 ) ;
if ( V_87 )
V_2 -> V_44 . V_116 ++ ;
else if ( V_2 -> V_18 . V_62 . V_63 ( V_2 ) &&
( ! ( V_2 -> V_18 . V_54 & V_61 ) ) )
F_28 ( V_2 , & V_69 ) ;
} else {
V_2 -> V_44 . V_117 ++ ;
V_2 -> V_18 . V_118 = V_69 . V_75 ;
V_2 -> V_18 . V_119 = V_69 . V_85 ;
V_89 = F_43 ( V_84 , V_2 ) ;
if ( V_89 == V_120 )
V_89 = V_121 ;
}
return V_89 ;
}
static inline int F_44 ( int V_73 )
{
#ifdef F_45
V_73 *= 2 ;
#endif
return V_73 ;
}
void F_9 ( struct V_1 * V_2 , T_1 V_20 )
{
struct V_122 * V_123 = & V_11 -> V_12 ;
T_2 * V_124 = V_2 -> V_18 . V_125 ;
#ifdef F_45
T_2 * V_126 = V_2 -> V_18 . V_127 ;
#endif
T_2 * V_128 = ( T_2 * ) V_123 -> V_125 ;
int V_73 ;
if ( ! ( V_2 -> V_18 . V_33 & V_20 ) )
return;
#ifdef F_46
F_13 ( V_38 L_4 , V_20 ) ;
#endif
switch ( V_20 ) {
case V_14 :
F_47 ( V_11 ) ;
for ( V_73 = 0 ; V_73 < F_48 ( V_2 -> V_18 . V_125 ) ; V_73 ++ )
V_124 [ V_73 ] = V_128 [ F_44 ( V_73 ) ] ;
V_2 -> V_18 . V_129 = V_123 -> V_129 . V_130 ;
break;
case V_15 :
#ifdef F_49
F_50 ( V_11 ) ;
memcpy ( V_2 -> V_18 . V_131 , V_123 -> V_131 , sizeof( V_2 -> V_18 . V_131 ) ) ;
V_2 -> V_18 . V_132 = V_123 -> V_132 ;
#endif
break;
case V_16 :
#ifdef F_45
F_51 ( V_11 ) ;
for ( V_73 = 0 ; V_73 < F_48 ( V_2 -> V_18 . V_127 ) ; V_73 ++ )
V_126 [ V_73 ] = V_128 [ F_44 ( V_73 ) + 1 ] ;
#endif
break;
default:
F_52 () ;
}
V_2 -> V_18 . V_33 &= ~ V_20 ;
V_11 -> V_12 . V_133 -> V_20 &= ~ V_20 ;
F_10 ( V_2 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
T_1 V_134 = F_18 ( V_2 ) ;
T_3 V_135 = F_54 ( V_2 ) ;
int V_136 ;
V_136 = F_55 ( V_2 , & V_134 , sizeof( T_3 ) , & V_135 , false ) ;
if ( V_136 == - V_108 ) {
T_1 V_20 = V_2 -> V_18 . V_19 -> V_20 ;
V_20 = F_56 ( V_20 , 33 , 33 , 1 ) ;
V_20 = F_56 ( V_20 , 34 , 36 , 0 ) ;
V_2 -> V_18 . V_19 -> V_20 = F_56 ( V_20 , 42 , 47 , 0 ) ;
F_41 ( V_2 , V_137 ) ;
return V_138 ;
}
return V_139 ;
}
static int F_57 ( struct V_1 * V_2 , unsigned int V_140 )
{
if ( ! ( V_2 -> V_18 . V_54 & V_141 ) )
return V_139 ;
if ( F_53 ( V_2 ) == V_139 )
return V_142 ;
return V_138 ;
}
static int F_20 ( struct V_1 * V_2 , unsigned int V_140 ,
T_1 V_20 )
{
struct V_122 * V_123 = & V_11 -> V_12 ;
T_2 * V_124 = V_2 -> V_18 . V_125 ;
#ifdef F_45
T_2 * V_126 = V_2 -> V_18 . V_127 ;
#endif
T_2 * V_128 = ( T_2 * ) V_123 -> V_125 ;
int V_73 ;
if ( V_2 -> V_18 . V_54 & V_141 )
return V_90 ;
if ( ! ( V_2 -> V_18 . V_19 -> V_20 & V_20 ) ) {
F_41 ( V_2 , V_140 ) ;
return V_90 ;
}
if ( V_2 -> V_18 . V_33 & V_20 ) {
return V_90 ;
}
#ifdef F_46
F_13 ( V_38 L_5 , V_20 ) ;
#endif
V_11 -> V_12 . V_133 -> V_20 |= V_20 ;
switch ( V_20 ) {
case V_14 :
for ( V_73 = 0 ; V_73 < F_48 ( V_2 -> V_18 . V_125 ) ; V_73 ++ )
V_128 [ F_44 ( V_73 ) ] = V_124 [ V_73 ] ;
V_123 -> V_129 . V_130 = V_2 -> V_18 . V_129 ;
V_123 -> V_143 = 0 ;
F_58 () ;
break;
case V_15 :
#ifdef F_49
memcpy ( V_123 -> V_131 , V_2 -> V_18 . V_131 , sizeof( V_2 -> V_18 . V_131 ) ) ;
V_123 -> V_132 = V_2 -> V_18 . V_132 ;
V_123 -> V_144 = - 1 ;
F_59 () ;
#endif
break;
case V_16 :
#ifdef F_45
for ( V_73 = 0 ; V_73 < F_48 ( V_2 -> V_18 . V_127 ) ; V_73 ++ )
V_128 [ F_44 ( V_73 ) + 1 ] = V_126 [ V_73 ] ;
F_60 () ;
#endif
break;
default:
F_52 () ;
}
V_2 -> V_18 . V_33 |= V_20 ;
F_10 ( V_2 ) ;
return V_90 ;
}
int F_61 ( struct V_83 * V_84 , struct V_1 * V_2 ,
unsigned int V_140 )
{
int V_89 = V_121 ;
V_2 -> V_44 . V_145 ++ ;
V_84 -> V_146 = V_147 ;
V_84 -> V_148 = 1 ;
F_62 () ;
F_63 ( V_140 , V_2 ) ;
F_64 () ;
F_65 ( V_2 ) ;
switch ( V_140 ) {
case V_137 :
{
struct V_4 * V_5 = F_3 ( V_2 ) ;
T_1 V_112 = V_5 -> V_112 ;
V_2 -> V_44 . V_149 ++ ;
#ifdef F_7
if ( V_5 -> V_150 [ F_18 ( V_2 ) >> V_103 ] == V_151 ) {
F_17 ( V_2 , F_18 ( V_2 ) ) ;
V_89 = V_90 ;
F_6 ( V_5 ) ;
break;
}
#endif
F_6 ( V_5 ) ;
if ( V_112 & 0x40000000 ) {
V_89 = F_39 ( V_84 , V_2 , F_18 ( V_2 ) , V_140 ) ;
V_2 -> V_44 . V_152 ++ ;
} else if ( V_2 -> V_18 . V_62 . V_63 ( V_2 ) &&
( ! ( V_2 -> V_18 . V_54 & V_61 ) ) ) {
F_19 ( V_2 , F_18 ( V_2 ) , ~ 0xFFFUL ) ;
V_89 = V_90 ;
} else {
V_2 -> V_18 . V_19 -> V_20 |= V_112 & 0x58000000 ;
F_41 ( V_2 , V_140 ) ;
V_89 = V_90 ;
}
break;
}
case V_88 :
{
T_1 V_109 = F_40 ( V_2 ) ;
struct V_4 * V_5 = F_3 ( V_2 ) ;
T_3 V_111 = V_5 -> V_111 ;
V_2 -> V_44 . V_153 ++ ;
#ifdef F_7
if ( ( V_5 -> V_150 [ V_109 >> V_103 ] ) == V_151 ) {
F_17 ( V_2 , V_109 ) ;
V_89 = V_90 ;
F_6 ( V_5 ) ;
break;
}
#endif
F_6 ( V_5 ) ;
if ( V_111 & V_114 ) {
V_89 = F_39 ( V_84 , V_2 , V_109 , V_140 ) ;
} else {
V_2 -> V_18 . V_19 -> V_109 = V_109 ;
V_2 -> V_18 . V_19 -> V_110 = V_111 ;
F_41 ( V_2 , V_140 ) ;
V_89 = V_90 ;
}
break;
}
case V_154 :
if ( F_17 ( V_2 , F_40 ( V_2 ) ) < 0 ) {
V_2 -> V_18 . V_19 -> V_109 = F_40 ( V_2 ) ;
F_41 ( V_2 ,
V_154 ) ;
}
V_89 = V_90 ;
break;
case V_155 :
if ( F_17 ( V_2 , F_18 ( V_2 ) ) < 0 ) {
F_41 ( V_2 ,
V_155 ) ;
}
V_89 = V_90 ;
break;
case V_156 :
case V_157 :
V_2 -> V_44 . V_158 ++ ;
V_89 = V_90 ;
break;
case V_159 :
case V_160 :
case V_161 :
V_2 -> V_44 . V_162 ++ ;
V_89 = V_90 ;
break;
case V_163 :
V_89 = V_90 ;
break;
case V_164 :
case V_165 :
{
enum V_166 V_167 ;
struct V_4 * V_5 ;
T_1 V_168 ;
V_169:
V_5 = F_3 ( V_2 ) ;
V_168 = V_5 -> V_112 & 0x1f0000ull ;
F_6 ( V_5 ) ;
if ( V_2 -> V_18 . V_19 -> V_20 & V_31 ) {
#ifdef F_12
F_13 ( V_38 L_6 , F_18 ( V_2 ) , F_54 ( V_2 ) ) ;
#endif
if ( ( F_54 ( V_2 ) & 0xff0007ff ) !=
( V_79 & 0xfffffff7 ) ) {
F_66 ( V_2 , V_168 ) ;
V_89 = V_90 ;
break;
}
}
V_2 -> V_44 . V_170 ++ ;
V_167 = F_67 ( V_84 , V_2 ) ;
switch ( V_167 ) {
case V_139 :
V_89 = V_171 ;
break;
case V_138 :
V_89 = V_90 ;
break;
case V_142 :
F_13 ( V_172 L_7 ,
V_173 , F_18 ( V_2 ) , F_54 ( V_2 ) ) ;
F_66 ( V_2 , V_168 ) ;
V_89 = V_90 ;
break;
case V_174 :
V_84 -> V_146 = V_175 ;
V_89 = V_120 ;
break;
default:
F_52 () ;
}
break;
}
case V_176 :
if ( V_2 -> V_18 . V_177 &&
( F_54 ( V_2 ) == 0x44000022 ) &&
! ( V_2 -> V_18 . V_19 -> V_20 & V_31 ) ) {
T_1 V_178 = F_68 ( V_2 , 3 ) ;
int V_73 ;
#ifdef F_69
if ( F_70 ( V_2 , V_178 ) == V_139 ) {
V_89 = V_90 ;
break;
}
#endif
V_84 -> V_179 . V_180 = V_178 ;
for ( V_73 = 0 ; V_73 < 9 ; ++ V_73 ) {
T_1 V_181 = F_68 ( V_2 , 4 + V_73 ) ;
V_84 -> V_179 . args [ V_73 ] = V_181 ;
}
V_84 -> V_146 = V_182 ;
V_2 -> V_18 . V_183 = 1 ;
V_89 = V_121 ;
} else if ( V_2 -> V_18 . V_184 &&
( ( ( T_3 ) F_68 ( V_2 , 3 ) ) == V_185 ) &&
( ( ( T_3 ) F_68 ( V_2 , 4 ) ) == V_186 ) ) {
T_2 * V_187 = V_84 -> V_188 . V_187 ;
int V_73 ;
V_84 -> V_146 = V_189 ;
for ( V_73 = 0 ; V_73 < 32 ; V_73 ++ )
V_187 [ V_73 ] = F_68 ( V_2 , V_73 ) ;
V_2 -> V_18 . V_190 = 1 ;
V_89 = V_120 ;
} else if ( ! ( V_2 -> V_18 . V_19 -> V_20 & V_31 ) &&
( ( ( T_3 ) F_68 ( V_2 , 0 ) ) == V_191 ) ) {
F_71 ( V_2 , 3 , F_72 ( V_2 ) ) ;
V_89 = V_90 ;
} else {
V_2 -> V_44 . V_192 ++ ;
F_41 ( V_2 , V_140 ) ;
V_89 = V_90 ;
}
break;
case V_51 :
case V_193 :
case V_194 :
{
int V_195 = 0 ;
switch ( V_140 ) {
case V_51 : V_195 = V_14 ; break;
case V_193 : V_195 = V_15 ; break;
case V_194 : V_195 = V_16 ; break;
}
switch ( F_57 ( V_2 , V_140 ) ) {
case V_139 :
V_89 = F_20 ( V_2 , V_140 , V_195 ) ;
break;
case V_142 :
goto V_169;
break;
default:
break;
}
break;
}
case V_196 :
if ( F_53 ( V_2 ) == V_139 ) {
V_2 -> V_18 . V_19 -> V_110 = F_73 ( V_2 ,
F_54 ( V_2 ) ) ;
V_2 -> V_18 . V_19 -> V_109 = F_74 ( V_2 ,
F_54 ( V_2 ) ) ;
F_41 ( V_2 , V_140 ) ;
}
V_89 = V_90 ;
break;
case V_197 :
case V_198 :
F_41 ( V_2 , V_140 ) ;
V_89 = V_90 ;
break;
default:
{
struct V_4 * V_5 = F_3 ( V_2 ) ;
T_1 V_112 = V_5 -> V_112 ;
F_6 ( V_5 ) ;
F_13 ( V_199 L_8 ,
V_140 , F_18 ( V_2 ) , V_112 ) ;
V_89 = V_121 ;
F_52 () ;
break;
}
}
F_75 () ;
if ( ! ( V_89 & V_121 ) ) {
F_76 () ;
if ( F_77 ( V_11 ) ) {
F_62 () ;
#ifdef F_12
F_13 ( V_199 L_9 ) ;
#endif
V_2 -> V_44 . V_200 ++ ;
V_84 -> V_146 = V_201 ;
V_89 = - V_202 ;
} else {
F_78 ( V_2 ) ;
}
}
F_79 ( V_89 , V_2 ) ;
return V_89 ;
}
int F_80 ( struct V_1 * V_2 ,
struct V_203 * V_204 )
{
struct V_205 * V_206 = F_4 ( V_2 ) ;
int V_73 ;
V_204 -> V_52 = V_2 -> V_18 . V_52 ;
V_204 -> V_207 . V_208 . V_209 = F_4 ( V_2 ) -> V_209 ;
if ( V_2 -> V_18 . V_54 & V_55 ) {
for ( V_73 = 0 ; V_73 < 64 ; V_73 ++ ) {
V_204 -> V_207 . V_208 . V_210 . V_6 [ V_73 ] . V_211 = V_2 -> V_18 . V_6 [ V_73 ] . V_212 | V_73 ;
V_204 -> V_207 . V_208 . V_210 . V_6 [ V_73 ] . V_213 = V_2 -> V_18 . V_6 [ V_73 ] . V_214 ;
}
} else {
for ( V_73 = 0 ; V_73 < 16 ; V_73 ++ )
V_204 -> V_207 . V_208 . V_215 . V_150 [ V_73 ] = V_2 -> V_18 . V_19 -> V_150 [ V_73 ] ;
for ( V_73 = 0 ; V_73 < 8 ; V_73 ++ ) {
V_204 -> V_207 . V_208 . V_215 . V_216 [ V_73 ] = V_206 -> V_216 [ V_73 ] . V_217 ;
V_204 -> V_207 . V_208 . V_215 . V_218 [ V_73 ] = V_206 -> V_218 [ V_73 ] . V_217 ;
}
}
return 0 ;
}
int F_81 ( struct V_1 * V_2 ,
struct V_203 * V_204 )
{
struct V_205 * V_206 = F_4 ( V_2 ) ;
int V_73 ;
F_21 ( V_2 , V_204 -> V_52 ) ;
V_206 -> V_209 = V_204 -> V_207 . V_208 . V_209 ;
if ( V_2 -> V_18 . V_54 & V_55 ) {
for ( V_73 = 0 ; V_73 < 64 ; V_73 ++ ) {
V_2 -> V_18 . V_62 . V_219 ( V_2 , V_204 -> V_207 . V_208 . V_210 . V_6 [ V_73 ] . V_213 ,
V_204 -> V_207 . V_208 . V_210 . V_6 [ V_73 ] . V_211 ) ;
}
} else {
for ( V_73 = 0 ; V_73 < 16 ; V_73 ++ ) {
V_2 -> V_18 . V_62 . V_220 ( V_2 , V_73 , V_204 -> V_207 . V_208 . V_215 . V_150 [ V_73 ] ) ;
}
for ( V_73 = 0 ; V_73 < 8 ; V_73 ++ ) {
F_82 ( V_2 , & ( V_206 -> V_216 [ V_73 ] ) , false ,
( T_3 ) V_204 -> V_207 . V_208 . V_215 . V_216 [ V_73 ] ) ;
F_82 ( V_2 , & ( V_206 -> V_216 [ V_73 ] ) , true ,
( T_3 ) ( V_204 -> V_207 . V_208 . V_215 . V_216 [ V_73 ] >> 32 ) ) ;
F_82 ( V_2 , & ( V_206 -> V_218 [ V_73 ] ) , false ,
( T_3 ) V_204 -> V_207 . V_208 . V_215 . V_218 [ V_73 ] ) ;
F_82 ( V_2 , & ( V_206 -> V_218 [ V_73 ] ) , true ,
( T_3 ) ( V_204 -> V_207 . V_208 . V_215 . V_218 [ V_73 ] >> 32 ) ) ;
}
}
F_19 ( V_2 , 0 , 0 ) ;
return 0 ;
}
int F_83 ( struct V_1 * V_2 , struct V_221 * V_222 )
{
int V_89 = - V_107 ;
switch ( V_222 -> V_223 ) {
case V_224 :
V_89 = F_84 ( ( T_2 V_225 * ) ( long ) V_222 -> V_226 ,
& F_4 ( V_2 ) -> V_57 , sizeof( T_2 ) ) ;
break;
default:
break;
}
return V_89 ;
}
int F_85 ( struct V_1 * V_2 , struct V_221 * V_222 )
{
int V_89 = - V_107 ;
switch ( V_222 -> V_223 ) {
case V_224 :
V_89 = F_86 ( & F_4 ( V_2 ) -> V_57 ,
( T_2 V_225 * ) ( long ) V_222 -> V_226 , sizeof( T_2 ) ) ;
if ( ! V_89 )
F_4 ( V_2 ) -> V_56 = true ;
break;
default:
break;
}
return V_89 ;
}
int F_87 ( void )
{
return 0 ;
}
struct V_1 * F_88 ( struct V_74 * V_74 , unsigned int V_223 )
{
struct V_205 * V_227 ;
struct V_1 * V_2 ;
int V_228 = - V_229 ;
unsigned long V_230 ;
V_227 = F_89 ( sizeof( struct V_205 ) ) ;
if ( ! V_227 )
goto V_231;
V_227 -> V_8 = (struct V_4 * )
F_90 ( sizeof( * V_227 -> V_8 ) , V_232 ) ;
if ( ! V_227 -> V_8 )
goto V_233;
V_2 = & V_227 -> V_2 ;
V_228 = F_91 ( V_2 , V_74 , V_223 ) ;
if ( V_228 )
goto V_234;
V_230 = F_92 ( V_232 | V_235 ) ;
V_2 -> V_18 . V_19 = ( void * ) ( V_230 + V_236 - 4096 ) ;
if ( ! V_230 )
goto V_237;
#ifdef F_2
V_2 -> V_18 . V_52 = 0x3C0301 ;
#else
V_2 -> V_18 . V_52 = 0x84202 ;
#endif
F_21 ( V_2 , V_2 -> V_18 . V_52 ) ;
V_2 -> V_18 . V_238 = 64 ;
V_2 -> V_18 . V_36 = V_239 ;
V_228 = F_93 ( V_2 ) ;
if ( V_228 < 0 )
goto V_237;
return V_2 ;
V_237:
F_94 ( V_2 ) ;
V_234:
F_95 ( V_227 -> V_8 ) ;
V_233:
F_96 ( V_227 ) ;
V_231:
return F_97 ( V_228 ) ;
}
void F_98 ( struct V_1 * V_2 )
{
struct V_205 * V_227 = F_4 ( V_2 ) ;
F_99 ( ( unsigned long ) V_2 -> V_18 . V_19 & V_77 ) ;
F_94 ( V_2 ) ;
F_95 ( V_227 -> V_8 ) ;
F_96 ( V_227 ) ;
}
int F_100 ( struct V_83 * V_83 , struct V_1 * V_2 )
{
int V_136 ;
double V_125 [ 32 ] [ V_240 ] ;
unsigned int V_129 ;
int V_143 ;
#ifdef F_49
T_5 V_131 [ 32 ] ;
T_5 V_132 ;
unsigned long V_241 ( V_144 ) ;
int V_242 ;
#endif
#ifdef F_45
int V_243 ;
#endif
T_1 V_195 ;
F_75 () ;
if ( ! V_2 -> V_18 . V_244 ) {
V_83 -> V_146 = V_245 ;
V_136 = - V_107 ;
goto V_231;
}
F_78 ( V_2 ) ;
F_76 () ;
if ( F_77 ( V_11 ) ) {
F_62 () ;
V_83 -> V_146 = V_201 ;
V_136 = - V_202 ;
goto V_231;
}
if ( V_11 -> V_12 . V_133 -> V_20 & V_14 )
F_47 ( V_11 ) ;
memcpy ( V_125 , V_11 -> V_12 . V_125 , sizeof( V_11 -> V_12 . V_125 ) ) ;
V_129 = V_11 -> V_12 . V_129 . V_130 ;
V_143 = V_11 -> V_12 . V_143 ;
#ifdef F_49
V_242 = V_11 -> V_12 . V_242 ;
if ( V_242 ) {
if ( V_11 -> V_12 . V_133 -> V_20 & V_15 )
F_50 ( V_11 ) ;
memcpy ( V_131 , V_11 -> V_12 . V_131 , sizeof( V_11 -> V_12 . V_131 ) ) ;
V_132 = V_11 -> V_12 . V_132 ;
V_144 = V_11 -> V_12 . V_144 ;
}
#endif
#ifdef F_45
V_243 = V_11 -> V_12 . V_243 ;
if ( V_243 && ( V_11 -> V_12 . V_133 -> V_20 & V_16 ) )
F_51 ( V_11 ) ;
#endif
V_195 = V_11 -> V_12 . V_133 -> V_20 ;
if ( V_2 -> V_18 . V_19 -> V_20 & V_14 )
F_20 ( V_2 , V_51 , V_14 ) ;
F_101 () ;
V_136 = F_102 ( V_83 , V_2 ) ;
F_103 () ;
V_11 -> V_12 . V_133 -> V_20 = V_195 ;
F_9 ( V_2 , V_14 ) ;
F_9 ( V_2 , V_15 ) ;
F_9 ( V_2 , V_16 ) ;
memcpy ( V_11 -> V_12 . V_125 , V_125 , sizeof( V_11 -> V_12 . V_125 ) ) ;
V_11 -> V_12 . V_129 . V_130 = V_129 ;
V_11 -> V_12 . V_143 = V_143 ;
#ifdef F_49
if ( V_242 && V_11 -> V_12 . V_242 ) {
memcpy ( V_11 -> V_12 . V_131 , V_131 , sizeof( V_11 -> V_12 . V_131 ) ) ;
V_11 -> V_12 . V_132 = V_132 ;
V_11 -> V_12 . V_144 = V_144 ;
}
V_11 -> V_12 . V_242 = V_242 ;
#endif
#ifdef F_45
V_11 -> V_12 . V_243 = V_243 ;
#endif
V_231:
F_64 () ;
return V_136 ;
}
int F_104 ( struct V_74 * V_74 ,
struct V_246 * log )
{
struct V_247 * V_248 ;
struct V_1 * V_2 ;
T_1 V_249 , V_250 ;
int V_251 = 0 ;
int V_89 ;
unsigned long V_252 ;
F_105 ( & V_74 -> V_253 ) ;
V_89 = F_106 ( V_74 , log , & V_251 ) ;
if ( V_89 )
goto V_231;
if ( V_251 ) {
V_248 = F_107 ( V_74 -> V_254 , log -> V_255 ) ;
V_249 = V_248 -> V_256 << V_76 ;
V_250 = V_249 + ( V_248 -> V_257 << V_76 ) ;
F_108 (n, vcpu, kvm)
F_109 ( V_2 , V_249 , V_250 ) ;
V_252 = F_110 ( V_248 ) ;
memset ( V_248 -> V_258 , 0 , V_252 ) ;
}
V_89 = 0 ;
V_231:
F_111 ( & V_74 -> V_253 ) ;
return V_89 ;
}
int F_112 ( struct V_74 * V_74 , struct V_259 * V_260 )
{
V_260 -> V_168 = 0 ;
V_260 -> V_261 = 64 ;
V_260 -> V_262 [ 0 ] . V_263 = 12 ;
V_260 -> V_262 [ 0 ] . V_264 = 0 ;
V_260 -> V_262 [ 0 ] . V_265 [ 0 ] . V_263 = 12 ;
V_260 -> V_262 [ 0 ] . V_265 [ 0 ] . V_266 = 0 ;
V_260 -> V_262 [ 1 ] . V_263 = 24 ;
V_260 -> V_262 [ 1 ] . V_264 = V_267 ;
V_260 -> V_262 [ 1 ] . V_265 [ 0 ] . V_263 = 24 ;
V_260 -> V_262 [ 1 ] . V_265 [ 0 ] . V_266 = 0 ;
return 0 ;
}
int F_113 ( struct V_74 * V_74 ,
struct V_268 * V_269 )
{
return 0 ;
}
void F_114 ( struct V_74 * V_74 ,
struct V_268 * V_269 )
{
}
int F_115 ( struct V_74 * V_74 )
{
#ifdef F_116
F_117 ( & V_74 -> V_18 . V_270 ) ;
#endif
return 0 ;
}
void F_118 ( struct V_74 * V_74 )
{
#ifdef F_116
F_119 ( ! F_120 ( & V_74 -> V_18 . V_270 ) ) ;
#endif
}
static int F_121 ( void )
{
int V_89 ;
V_89 = F_122 ( NULL , sizeof( struct V_205 ) , 0 ,
V_271 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_123 () ;
return V_89 ;
}
static void F_124 ( void )
{
F_125 () ;
F_126 () ;
}
