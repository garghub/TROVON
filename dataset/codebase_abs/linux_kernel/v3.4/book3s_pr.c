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
V_2 -> V_42 . V_43 ++ ;
V_20 &= ~ V_40 ;
V_2 -> V_18 . V_19 -> V_20 = V_20 ;
}
}
if ( ( V_2 -> V_18 . V_19 -> V_20 & ( V_31 | V_29 | V_30 ) ) !=
( V_37 & ( V_31 | V_29 | V_30 ) ) ) {
F_15 ( V_2 ) ;
F_16 ( V_2 , F_17 ( V_2 ) ) ;
if ( ! ( V_20 & V_31 ) && V_2 -> V_18 . V_44 ) {
struct V_45 * V_46 = & V_2 -> V_18 ;
if ( V_20 & V_30 )
F_16 ( V_2 , V_46 -> V_47 ) ;
else
F_16 ( V_2 , V_46 -> V_44 ) ;
}
}
if ( V_2 -> V_18 . V_19 -> V_20 & V_14 )
F_18 ( V_2 , V_48 , V_14 ) ;
}
void F_19 ( struct V_1 * V_2 , T_3 V_49 )
{
T_3 V_50 ;
V_2 -> V_18 . V_51 &= ~ V_52 ;
V_2 -> V_18 . V_49 = V_49 ;
#ifdef F_2
if ( ( V_49 >= 0x330000 ) && ( V_49 < 0x70330000 ) ) {
F_20 ( V_2 ) ;
if ( ! F_4 ( V_2 ) -> V_53 )
F_4 ( V_2 ) -> V_54 = 0xfff00000 ;
F_4 ( V_2 ) -> V_39 = 0xffffffffffffffffULL ;
V_2 -> V_18 . V_55 = V_56 ;
} else
#endif
{
F_21 ( V_2 ) ;
if ( ! F_4 ( V_2 ) -> V_53 )
F_4 ( V_2 ) -> V_54 = 0 ;
F_4 ( V_2 ) -> V_39 = 0xffffffffULL ;
V_2 -> V_18 . V_55 = V_57 ;
}
F_22 ( V_2 ) ;
V_2 -> V_18 . V_51 &= ~ V_58 ;
if ( V_2 -> V_18 . V_59 . V_60 ( V_2 ) && ( F_23 () & V_35 ) &&
! strcmp ( V_61 -> V_62 , L_2 ) )
V_2 -> V_18 . V_51 |= V_58 ;
if ( ! strcmp ( V_61 -> V_62 , L_3 ) )
F_4 ( V_2 ) -> V_39 &= ~ ( V_21 | V_22 ) ;
#ifdef F_7
V_2 -> V_18 . V_51 |= V_58 ;
#endif
asm ( "mfpvr %0" : "=r"(host_pvr));
switch ( V_50 ) {
case 0x00080200 :
case 0x00088202 :
case 0x70000100 :
case 0x00080100 :
case 0x00083203 :
case 0x00083213 :
case 0x00083204 :
case 0x00083214 :
case 0x00087200 :
V_2 -> V_18 . V_51 |= V_63 ;
F_24 ( V_64 , F_25 ( V_64 ) | ( 1 << 29 ) ) ;
}
}
static void F_26 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
struct V_67 * V_68 ;
T_2 V_69 ;
T_3 * V_67 ;
int V_70 ;
V_68 = F_27 ( V_2 -> V_71 , V_66 -> V_72 >> V_73 ) ;
if ( F_28 ( V_68 ) ) {
F_29 ( V_68 ) ;
return;
}
V_69 = V_66 -> V_72 & ~ V_74 ;
V_69 &= ~ 0xFFFULL ;
V_69 /= 4 ;
F_30 ( V_68 ) ;
V_67 = F_31 ( V_68 ) ;
for ( V_70 = V_69 ; V_70 < V_69 + ( V_75 / 4 ) ; V_70 ++ )
if ( ( V_67 [ V_70 ] & 0xff0007ff ) == V_76 )
V_67 [ V_70 ] &= 0xfffffff7 ;
F_32 ( V_67 ) ;
F_33 ( V_68 ) ;
}
static int F_34 ( struct V_1 * V_2 , T_4 V_77 )
{
T_1 V_78 = V_2 -> V_18 . V_44 ;
if ( F_35 ( V_78 ) &&
F_35 ( ( V_78 & V_79 ) >> V_73 == V_77 ) ) {
return 1 ;
}
return F_36 ( V_2 -> V_71 , V_77 ) ;
}
int F_37 ( struct V_80 * V_81 , struct V_1 * V_2 ,
T_1 V_82 , int V_83 )
{
bool V_84 = ( V_83 == V_85 ) ;
int V_86 = V_87 ;
int V_88 ;
int V_89 = 0 ;
struct V_65 V_66 ;
bool V_90 = false ;
bool V_91 = ( V_2 -> V_18 . V_19 -> V_20 & V_30 ) ? true : false ;
bool V_92 = ( V_2 -> V_18 . V_19 -> V_20 & V_29 ) ? true : false ;
T_2 V_93 ;
V_88 = V_84 ? V_91 : V_92 ;
if ( V_88 ) {
V_89 = V_2 -> V_18 . V_59 . V_94 ( V_2 , V_82 , & V_66 , V_84 ) ;
} else {
V_66 . V_95 = true ;
V_66 . V_96 = true ;
V_66 . V_97 = true ;
V_66 . V_72 = V_82 & V_79 ;
V_66 . V_82 = V_82 ;
V_66 . V_98 = V_82 >> 12 ;
}
switch ( V_2 -> V_18 . V_19 -> V_20 & ( V_30 | V_29 ) ) {
case 0 :
V_66 . V_98 |= ( ( T_2 ) V_99 << ( V_100 - 12 ) ) ;
break;
case V_30 :
case V_29 :
V_2 -> V_18 . V_59 . V_101 ( V_2 , V_82 >> V_100 , & V_93 ) ;
if ( ( V_2 -> V_18 . V_19 -> V_20 & ( V_30 | V_29 ) ) == V_30 )
V_66 . V_98 |= ( ( T_2 ) V_102 << ( V_100 - 12 ) ) ;
else
V_66 . V_98 |= ( ( T_2 ) V_103 << ( V_100 - 12 ) ) ;
V_66 . V_98 |= V_93 ;
if ( V_93 == - 1 )
V_89 = - V_104 ;
break;
}
if ( V_2 -> V_18 . V_59 . V_60 ( V_2 ) &&
( ! ( V_2 -> V_18 . V_51 & V_58 ) ) ) {
V_66 . V_95 = ! V_84 ;
}
if ( V_89 == - V_105 ) {
struct V_4 * V_5 = F_3 ( V_2 ) ;
V_2 -> V_18 . V_19 -> V_106 = F_38 ( V_2 ) ;
V_2 -> V_18 . V_19 -> V_107 = V_5 -> V_108 ;
V_2 -> V_18 . V_19 -> V_20 |=
( V_5 -> V_109 & 0x00000000f8000000ULL ) ;
F_6 ( V_5 ) ;
F_39 ( V_2 , V_83 ) ;
} else if ( V_89 == - V_110 ) {
struct V_4 * V_5 = F_3 ( V_2 ) ;
V_2 -> V_18 . V_19 -> V_106 = F_38 ( V_2 ) ;
V_2 -> V_18 . V_19 -> V_107 = V_5 -> V_108 & ~ V_111 ;
V_2 -> V_18 . V_19 -> V_107 |= V_112 ;
V_2 -> V_18 . V_19 -> V_20 |=
V_5 -> V_109 & 0x00000000f8000000ULL ;
F_6 ( V_5 ) ;
F_39 ( V_2 , V_83 ) ;
} else if ( V_89 == - V_104 ) {
V_2 -> V_18 . V_19 -> V_106 = F_38 ( V_2 ) ;
F_39 ( V_2 , V_83 + 0x80 ) ;
} else if ( ! V_90 &&
F_34 ( V_2 , V_66 . V_72 >> V_73 ) ) {
F_40 ( V_2 , & V_66 ) ;
if ( V_84 )
V_2 -> V_42 . V_113 ++ ;
else if ( V_2 -> V_18 . V_59 . V_60 ( V_2 ) &&
( ! ( V_2 -> V_18 . V_51 & V_58 ) ) )
F_26 ( V_2 , & V_66 ) ;
} else {
V_2 -> V_42 . V_114 ++ ;
V_2 -> V_18 . V_115 = V_66 . V_72 ;
V_86 = F_41 ( V_81 , V_2 ) ;
if ( V_86 == V_116 )
V_86 = V_117 ;
}
return V_86 ;
}
static inline int F_42 ( int V_70 )
{
#ifdef F_43
V_70 *= 2 ;
#endif
return V_70 ;
}
void F_9 ( struct V_1 * V_2 , T_1 V_20 )
{
struct V_118 * V_119 = & V_11 -> V_12 ;
T_2 * V_120 = V_2 -> V_18 . V_121 ;
#ifdef F_43
T_2 * V_122 = V_2 -> V_18 . V_123 ;
#endif
T_2 * V_124 = ( T_2 * ) V_119 -> V_121 ;
int V_70 ;
if ( ! ( V_2 -> V_18 . V_33 & V_20 ) )
return;
#ifdef F_44
F_13 ( V_38 L_4 , V_20 ) ;
#endif
switch ( V_20 ) {
case V_14 :
F_45 ( V_11 ) ;
for ( V_70 = 0 ; V_70 < F_46 ( V_2 -> V_18 . V_121 ) ; V_70 ++ )
V_120 [ V_70 ] = V_124 [ F_42 ( V_70 ) ] ;
V_2 -> V_18 . V_125 = V_119 -> V_125 . V_126 ;
break;
case V_15 :
#ifdef F_47
F_48 ( V_11 ) ;
memcpy ( V_2 -> V_18 . V_127 , V_119 -> V_127 , sizeof( V_2 -> V_18 . V_127 ) ) ;
V_2 -> V_18 . V_128 = V_119 -> V_128 ;
#endif
break;
case V_16 :
#ifdef F_43
F_49 ( V_11 ) ;
for ( V_70 = 0 ; V_70 < F_46 ( V_2 -> V_18 . V_123 ) ; V_70 ++ )
V_122 [ V_70 ] = V_124 [ F_42 ( V_70 ) + 1 ] ;
#endif
break;
default:
F_50 () ;
}
V_2 -> V_18 . V_33 &= ~ V_20 ;
V_11 -> V_12 . V_129 -> V_20 &= ~ V_20 ;
F_10 ( V_2 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
T_1 V_130 = F_17 ( V_2 ) ;
T_3 V_131 = F_52 ( V_2 ) ;
int V_132 ;
V_132 = F_53 ( V_2 , & V_130 , sizeof( T_3 ) , & V_131 , false ) ;
if ( V_132 == - V_105 ) {
T_1 V_20 = V_2 -> V_18 . V_19 -> V_20 ;
V_20 = F_54 ( V_20 , 33 , 33 , 1 ) ;
V_20 = F_54 ( V_20 , 34 , 36 , 0 ) ;
V_2 -> V_18 . V_19 -> V_20 = F_54 ( V_20 , 42 , 47 , 0 ) ;
F_39 ( V_2 , V_133 ) ;
return V_134 ;
}
return V_135 ;
}
static int F_55 ( struct V_1 * V_2 , unsigned int V_136 )
{
if ( ! ( V_2 -> V_18 . V_51 & V_137 ) )
return V_135 ;
if ( F_51 ( V_2 ) == V_135 )
return V_138 ;
return V_134 ;
}
static int F_18 ( struct V_1 * V_2 , unsigned int V_136 ,
T_1 V_20 )
{
struct V_118 * V_119 = & V_11 -> V_12 ;
T_2 * V_120 = V_2 -> V_18 . V_121 ;
#ifdef F_43
T_2 * V_122 = V_2 -> V_18 . V_123 ;
#endif
T_2 * V_124 = ( T_2 * ) V_119 -> V_121 ;
int V_70 ;
if ( V_2 -> V_18 . V_51 & V_137 )
return V_87 ;
if ( ! ( V_2 -> V_18 . V_19 -> V_20 & V_20 ) ) {
F_39 ( V_2 , V_136 ) ;
return V_87 ;
}
if ( V_2 -> V_18 . V_33 & V_20 ) {
return V_87 ;
}
#ifdef F_44
F_13 ( V_38 L_5 , V_20 ) ;
#endif
V_11 -> V_12 . V_129 -> V_20 |= V_20 ;
switch ( V_20 ) {
case V_14 :
for ( V_70 = 0 ; V_70 < F_46 ( V_2 -> V_18 . V_121 ) ; V_70 ++ )
V_124 [ F_42 ( V_70 ) ] = V_120 [ V_70 ] ;
V_119 -> V_125 . V_126 = V_2 -> V_18 . V_125 ;
V_119 -> V_139 = 0 ;
F_56 () ;
break;
case V_15 :
#ifdef F_47
memcpy ( V_119 -> V_127 , V_2 -> V_18 . V_127 , sizeof( V_2 -> V_18 . V_127 ) ) ;
V_119 -> V_128 = V_2 -> V_18 . V_128 ;
V_119 -> V_140 = - 1 ;
F_57 () ;
#endif
break;
case V_16 :
#ifdef F_43
for ( V_70 = 0 ; V_70 < F_46 ( V_2 -> V_18 . V_123 ) ; V_70 ++ )
V_124 [ F_42 ( V_70 ) + 1 ] = V_122 [ V_70 ] ;
F_58 () ;
#endif
break;
default:
F_50 () ;
}
V_2 -> V_18 . V_33 |= V_20 ;
F_10 ( V_2 ) ;
return V_87 ;
}
int F_59 ( struct V_80 * V_81 , struct V_1 * V_2 ,
unsigned int V_136 )
{
int V_86 = V_117 ;
V_2 -> V_42 . V_141 ++ ;
V_81 -> V_142 = V_143 ;
V_81 -> V_144 = 1 ;
F_60 ( V_136 , V_2 ) ;
F_61 () ;
F_62 ( V_2 ) ;
switch ( V_136 ) {
case V_133 :
{
struct V_4 * V_5 = F_3 ( V_2 ) ;
T_1 V_109 = V_5 -> V_109 ;
V_2 -> V_42 . V_145 ++ ;
#ifdef F_7
if ( V_5 -> V_146 [ F_17 ( V_2 ) >> V_100 ] == V_147 ) {
F_16 ( V_2 , F_17 ( V_2 ) ) ;
V_86 = V_87 ;
F_6 ( V_5 ) ;
break;
}
#endif
F_6 ( V_5 ) ;
if ( V_109 & 0x40000000 ) {
V_86 = F_37 ( V_81 , V_2 , F_17 ( V_2 ) , V_136 ) ;
V_2 -> V_42 . V_148 ++ ;
} else if ( V_2 -> V_18 . V_59 . V_60 ( V_2 ) &&
( ! ( V_2 -> V_18 . V_51 & V_58 ) ) ) {
F_63 ( V_2 , F_17 ( V_2 ) , ~ 0xFFFUL ) ;
V_86 = V_87 ;
} else {
V_2 -> V_18 . V_19 -> V_20 |= V_109 & 0x58000000 ;
F_39 ( V_2 , V_136 ) ;
V_86 = V_87 ;
}
break;
}
case V_85 :
{
T_1 V_106 = F_38 ( V_2 ) ;
struct V_4 * V_5 = F_3 ( V_2 ) ;
T_3 V_108 = V_5 -> V_108 ;
V_2 -> V_42 . V_149 ++ ;
#ifdef F_7
if ( ( V_5 -> V_146 [ V_106 >> V_100 ] ) == V_147 ) {
F_16 ( V_2 , V_106 ) ;
V_86 = V_87 ;
F_6 ( V_5 ) ;
break;
}
#endif
F_6 ( V_5 ) ;
if ( V_108 & V_111 ) {
V_86 = F_37 ( V_81 , V_2 , V_106 , V_136 ) ;
} else {
V_2 -> V_18 . V_19 -> V_106 = V_106 ;
V_2 -> V_18 . V_19 -> V_107 = V_108 ;
F_39 ( V_2 , V_136 ) ;
V_86 = V_87 ;
}
break;
}
case V_150 :
if ( F_16 ( V_2 , F_38 ( V_2 ) ) < 0 ) {
V_2 -> V_18 . V_19 -> V_106 = F_38 ( V_2 ) ;
F_39 ( V_2 ,
V_150 ) ;
}
V_86 = V_87 ;
break;
case V_151 :
if ( F_16 ( V_2 , F_17 ( V_2 ) ) < 0 ) {
F_39 ( V_2 ,
V_151 ) ;
}
V_86 = V_87 ;
break;
case V_152 :
V_2 -> V_42 . V_153 ++ ;
V_86 = V_87 ;
break;
case V_154 :
V_2 -> V_42 . V_155 ++ ;
V_86 = V_87 ;
break;
case V_156 :
V_86 = V_87 ;
break;
case V_157 :
{
enum V_158 V_159 ;
struct V_4 * V_5 ;
T_1 V_160 ;
V_161:
V_5 = F_3 ( V_2 ) ;
V_160 = V_5 -> V_109 & 0x1f0000ull ;
F_6 ( V_5 ) ;
if ( V_2 -> V_18 . V_19 -> V_20 & V_31 ) {
#ifdef F_12
F_13 ( V_38 L_6 , F_17 ( V_2 ) , F_52 ( V_2 ) ) ;
#endif
if ( ( F_52 ( V_2 ) & 0xff0007ff ) !=
( V_76 & 0xfffffff7 ) ) {
F_64 ( V_2 , V_160 ) ;
V_86 = V_87 ;
break;
}
}
V_2 -> V_42 . V_162 ++ ;
V_159 = F_65 ( V_81 , V_2 ) ;
switch ( V_159 ) {
case V_135 :
V_86 = V_163 ;
break;
case V_134 :
V_86 = V_87 ;
break;
case V_138 :
F_13 ( V_164 L_7 ,
V_165 , F_17 ( V_2 ) , F_52 ( V_2 ) ) ;
F_64 ( V_2 , V_160 ) ;
V_86 = V_87 ;
break;
case V_166 :
V_81 -> V_142 = V_167 ;
V_86 = V_116 ;
break;
default:
F_50 () ;
}
break;
}
case V_168 :
if ( V_2 -> V_18 . V_169 &&
( F_52 ( V_2 ) == 0x44000022 ) &&
! ( V_2 -> V_18 . V_19 -> V_20 & V_31 ) ) {
T_1 V_170 = F_66 ( V_2 , 3 ) ;
int V_70 ;
#ifdef F_67
if ( F_68 ( V_2 , V_170 ) == V_135 ) {
V_86 = V_87 ;
break;
}
#endif
V_81 -> V_171 . V_172 = V_170 ;
for ( V_70 = 0 ; V_70 < 9 ; ++ V_70 ) {
T_1 V_173 = F_66 ( V_2 , 4 + V_70 ) ;
V_81 -> V_171 . args [ V_70 ] = V_173 ;
}
V_81 -> V_142 = V_174 ;
V_2 -> V_18 . V_175 = 1 ;
V_86 = V_117 ;
} else if ( V_2 -> V_18 . V_176 &&
( ( ( T_3 ) F_66 ( V_2 , 3 ) ) == V_177 ) &&
( ( ( T_3 ) F_66 ( V_2 , 4 ) ) == V_178 ) ) {
T_2 * V_179 = V_81 -> V_180 . V_179 ;
int V_70 ;
V_81 -> V_142 = V_181 ;
for ( V_70 = 0 ; V_70 < 32 ; V_70 ++ )
V_179 [ V_70 ] = F_66 ( V_2 , V_70 ) ;
V_2 -> V_18 . V_182 = 1 ;
V_86 = V_116 ;
} else if ( ! ( V_2 -> V_18 . V_19 -> V_20 & V_31 ) &&
( ( ( T_3 ) F_66 ( V_2 , 0 ) ) == V_183 ) ) {
F_69 ( V_2 , 3 , F_70 ( V_2 ) ) ;
V_86 = V_87 ;
} else {
V_2 -> V_42 . V_184 ++ ;
F_39 ( V_2 , V_136 ) ;
V_86 = V_87 ;
}
break;
case V_48 :
case V_185 :
case V_186 :
{
int V_187 = 0 ;
switch ( V_136 ) {
case V_48 : V_187 = V_14 ; break;
case V_185 : V_187 = V_15 ; break;
case V_186 : V_187 = V_16 ; break;
}
switch ( F_55 ( V_2 , V_136 ) ) {
case V_135 :
V_86 = F_18 ( V_2 , V_136 , V_187 ) ;
break;
case V_138 :
goto V_161;
break;
default:
break;
}
break;
}
case V_188 :
if ( F_51 ( V_2 ) == V_135 ) {
V_2 -> V_18 . V_19 -> V_107 = F_71 ( V_2 ,
F_52 ( V_2 ) ) ;
V_2 -> V_18 . V_19 -> V_106 = F_72 ( V_2 ,
F_52 ( V_2 ) ) ;
F_39 ( V_2 , V_136 ) ;
}
V_86 = V_87 ;
break;
case V_189 :
case V_190 :
F_39 ( V_2 , V_136 ) ;
V_86 = V_87 ;
break;
default:
{
struct V_4 * V_5 = F_3 ( V_2 ) ;
T_1 V_109 = V_5 -> V_109 ;
F_6 ( V_5 ) ;
F_13 ( V_191 L_8 ,
V_136 , F_17 ( V_2 ) , V_109 ) ;
V_86 = V_117 ;
F_50 () ;
break;
}
}
F_73 () ;
if ( ! ( V_86 & V_117 ) ) {
F_74 () ;
if ( F_75 ( V_11 ) ) {
F_76 () ;
#ifdef F_12
F_13 ( V_191 L_9 ) ;
#endif
V_2 -> V_42 . V_192 ++ ;
V_81 -> V_142 = V_193 ;
V_86 = - V_194 ;
} else {
F_77 ( V_2 ) ;
}
}
F_78 ( V_86 , V_2 ) ;
return V_86 ;
}
int F_79 ( struct V_1 * V_2 ,
struct V_195 * V_196 )
{
struct V_197 * V_198 = F_4 ( V_2 ) ;
int V_70 ;
V_196 -> V_49 = V_2 -> V_18 . V_49 ;
V_196 -> V_199 . V_200 . V_201 = F_4 ( V_2 ) -> V_201 ;
if ( V_2 -> V_18 . V_51 & V_52 ) {
for ( V_70 = 0 ; V_70 < 64 ; V_70 ++ ) {
V_196 -> V_199 . V_200 . V_202 . V_6 [ V_70 ] . V_203 = V_2 -> V_18 . V_6 [ V_70 ] . V_204 | V_70 ;
V_196 -> V_199 . V_200 . V_202 . V_6 [ V_70 ] . V_205 = V_2 -> V_18 . V_6 [ V_70 ] . V_206 ;
}
} else {
for ( V_70 = 0 ; V_70 < 16 ; V_70 ++ )
V_196 -> V_199 . V_200 . V_207 . V_146 [ V_70 ] = V_2 -> V_18 . V_19 -> V_146 [ V_70 ] ;
for ( V_70 = 0 ; V_70 < 8 ; V_70 ++ ) {
V_196 -> V_199 . V_200 . V_207 . V_208 [ V_70 ] = V_198 -> V_208 [ V_70 ] . V_209 ;
V_196 -> V_199 . V_200 . V_207 . V_210 [ V_70 ] = V_198 -> V_210 [ V_70 ] . V_209 ;
}
}
return 0 ;
}
int F_80 ( struct V_1 * V_2 ,
struct V_195 * V_196 )
{
struct V_197 * V_198 = F_4 ( V_2 ) ;
int V_70 ;
F_19 ( V_2 , V_196 -> V_49 ) ;
V_198 -> V_201 = V_196 -> V_199 . V_200 . V_201 ;
if ( V_2 -> V_18 . V_51 & V_52 ) {
for ( V_70 = 0 ; V_70 < 64 ; V_70 ++ ) {
V_2 -> V_18 . V_59 . V_211 ( V_2 , V_196 -> V_199 . V_200 . V_202 . V_6 [ V_70 ] . V_205 ,
V_196 -> V_199 . V_200 . V_202 . V_6 [ V_70 ] . V_203 ) ;
}
} else {
for ( V_70 = 0 ; V_70 < 16 ; V_70 ++ ) {
V_2 -> V_18 . V_59 . V_212 ( V_2 , V_70 , V_196 -> V_199 . V_200 . V_207 . V_146 [ V_70 ] ) ;
}
for ( V_70 = 0 ; V_70 < 8 ; V_70 ++ ) {
F_81 ( V_2 , & ( V_198 -> V_208 [ V_70 ] ) , false ,
( T_3 ) V_196 -> V_199 . V_200 . V_207 . V_208 [ V_70 ] ) ;
F_81 ( V_2 , & ( V_198 -> V_208 [ V_70 ] ) , true ,
( T_3 ) ( V_196 -> V_199 . V_200 . V_207 . V_208 [ V_70 ] >> 32 ) ) ;
F_81 ( V_2 , & ( V_198 -> V_210 [ V_70 ] ) , false ,
( T_3 ) V_196 -> V_199 . V_200 . V_207 . V_210 [ V_70 ] ) ;
F_81 ( V_2 , & ( V_198 -> V_210 [ V_70 ] ) , true ,
( T_3 ) ( V_196 -> V_199 . V_200 . V_207 . V_210 [ V_70 ] >> 32 ) ) ;
}
}
F_63 ( V_2 , 0 , 0 ) ;
return 0 ;
}
int F_82 ( struct V_1 * V_2 , struct V_213 * V_214 )
{
int V_86 = - V_104 ;
switch ( V_214 -> V_215 ) {
case V_216 :
V_86 = F_83 ( ( T_2 V_217 * ) ( long ) V_214 -> V_218 ,
& F_4 ( V_2 ) -> V_54 , sizeof( T_2 ) ) ;
break;
default:
break;
}
return V_86 ;
}
int F_84 ( struct V_1 * V_2 , struct V_213 * V_214 )
{
int V_86 = - V_104 ;
switch ( V_214 -> V_215 ) {
case V_216 :
V_86 = F_85 ( & F_4 ( V_2 ) -> V_54 ,
( T_2 V_217 * ) ( long ) V_214 -> V_218 , sizeof( T_2 ) ) ;
if ( ! V_86 )
F_4 ( V_2 ) -> V_53 = true ;
break;
default:
break;
}
return V_86 ;
}
int F_86 ( void )
{
return 0 ;
}
struct V_1 * F_87 ( struct V_71 * V_71 , unsigned int V_215 )
{
struct V_197 * V_219 ;
struct V_1 * V_2 ;
int V_220 = - V_221 ;
unsigned long V_222 ;
V_219 = F_88 ( sizeof( struct V_197 ) ) ;
if ( ! V_219 )
goto V_223;
V_219 -> V_8 = (struct V_4 * )
F_89 ( sizeof( * V_219 -> V_8 ) , V_224 ) ;
if ( ! V_219 -> V_8 )
goto V_225;
V_2 = & V_219 -> V_2 ;
V_220 = F_90 ( V_2 , V_71 , V_215 ) ;
if ( V_220 )
goto V_226;
V_222 = F_91 ( V_224 | V_227 ) ;
V_2 -> V_18 . V_19 = ( void * ) ( V_222 + V_228 - 4096 ) ;
if ( ! V_222 )
goto V_229;
#ifdef F_2
V_2 -> V_18 . V_49 = 0x3C0301 ;
#else
V_2 -> V_18 . V_49 = 0x84202 ;
#endif
F_19 ( V_2 , V_2 -> V_18 . V_49 ) ;
V_2 -> V_18 . V_230 = 64 ;
V_2 -> V_18 . V_36 = V_231 ;
V_220 = F_92 ( V_2 ) ;
if ( V_220 < 0 )
goto V_229;
return V_2 ;
V_229:
F_93 ( V_2 ) ;
V_226:
F_94 ( V_219 -> V_8 ) ;
V_225:
F_95 ( V_219 ) ;
V_223:
return F_96 ( V_220 ) ;
}
void F_97 ( struct V_1 * V_2 )
{
struct V_197 * V_219 = F_4 ( V_2 ) ;
F_98 ( ( unsigned long ) V_2 -> V_18 . V_19 & V_74 ) ;
F_93 ( V_2 ) ;
F_94 ( V_219 -> V_8 ) ;
F_95 ( V_219 ) ;
}
int F_99 ( struct V_80 * V_80 , struct V_1 * V_2 )
{
int V_132 ;
double V_121 [ 32 ] [ V_232 ] ;
unsigned int V_125 ;
int V_139 ;
#ifdef F_47
T_5 V_127 [ 32 ] ;
T_5 V_128 ;
unsigned long V_233 ( V_140 ) ;
int V_234 ;
#endif
#ifdef F_43
int V_235 ;
#endif
T_1 V_187 ;
F_73 () ;
if ( ! V_2 -> V_18 . V_236 ) {
V_80 -> V_142 = V_237 ;
V_132 = - V_104 ;
goto V_223;
}
F_77 ( V_2 ) ;
F_74 () ;
if ( F_75 ( V_11 ) ) {
F_76 () ;
V_80 -> V_142 = V_193 ;
V_132 = - V_194 ;
goto V_223;
}
if ( V_11 -> V_12 . V_129 -> V_20 & V_14 )
F_45 ( V_11 ) ;
memcpy ( V_121 , V_11 -> V_12 . V_121 , sizeof( V_11 -> V_12 . V_121 ) ) ;
V_125 = V_11 -> V_12 . V_125 . V_126 ;
V_139 = V_11 -> V_12 . V_139 ;
#ifdef F_47
V_234 = V_11 -> V_12 . V_234 ;
if ( V_234 ) {
if ( V_11 -> V_12 . V_129 -> V_20 & V_15 )
F_48 ( V_11 ) ;
memcpy ( V_127 , V_11 -> V_12 . V_127 , sizeof( V_11 -> V_12 . V_127 ) ) ;
V_128 = V_11 -> V_12 . V_128 ;
V_140 = V_11 -> V_12 . V_140 ;
}
#endif
#ifdef F_43
V_235 = V_11 -> V_12 . V_235 ;
if ( V_235 && ( V_11 -> V_12 . V_129 -> V_20 & V_16 ) )
F_49 ( V_11 ) ;
#endif
V_187 = V_11 -> V_12 . V_129 -> V_20 ;
if ( V_2 -> V_18 . V_19 -> V_20 & V_14 )
F_18 ( V_2 , V_48 , V_14 ) ;
F_100 () ;
V_132 = F_101 ( V_80 , V_2 ) ;
F_102 () ;
V_11 -> V_12 . V_129 -> V_20 = V_187 ;
F_9 ( V_2 , V_14 ) ;
F_9 ( V_2 , V_15 ) ;
F_9 ( V_2 , V_16 ) ;
memcpy ( V_11 -> V_12 . V_121 , V_121 , sizeof( V_11 -> V_12 . V_121 ) ) ;
V_11 -> V_12 . V_125 . V_126 = V_125 ;
V_11 -> V_12 . V_139 = V_139 ;
#ifdef F_47
if ( V_234 && V_11 -> V_12 . V_234 ) {
memcpy ( V_11 -> V_12 . V_127 , V_127 , sizeof( V_11 -> V_12 . V_127 ) ) ;
V_11 -> V_12 . V_128 = V_128 ;
V_11 -> V_12 . V_140 = V_140 ;
}
V_11 -> V_12 . V_234 = V_234 ;
#endif
#ifdef F_43
V_11 -> V_12 . V_235 = V_235 ;
#endif
V_223:
F_61 () ;
return V_132 ;
}
int F_103 ( struct V_71 * V_71 ,
struct V_238 * log )
{
struct V_239 * V_240 ;
struct V_1 * V_2 ;
T_1 V_241 , V_242 ;
int V_243 = 0 ;
int V_86 ;
unsigned long V_244 ;
F_104 ( & V_71 -> V_245 ) ;
V_86 = F_105 ( V_71 , log , & V_243 ) ;
if ( V_86 )
goto V_223;
if ( V_243 ) {
V_240 = F_106 ( V_71 -> V_246 , log -> V_247 ) ;
V_241 = V_240 -> V_248 << V_73 ;
V_242 = V_241 + ( V_240 -> V_249 << V_73 ) ;
F_107 (n, vcpu, kvm)
F_108 ( V_2 , V_241 , V_242 ) ;
V_244 = F_109 ( V_240 ) ;
memset ( V_240 -> V_250 , 0 , V_244 ) ;
}
V_86 = 0 ;
V_223:
F_110 ( & V_71 -> V_245 ) ;
return V_86 ;
}
int F_111 ( struct V_71 * V_71 ,
struct V_251 * V_252 )
{
return 0 ;
}
void F_112 ( struct V_71 * V_71 ,
struct V_251 * V_252 )
{
}
int F_113 ( struct V_71 * V_71 )
{
return 0 ;
}
void F_114 ( struct V_71 * V_71 )
{
}
static int F_115 ( void )
{
int V_86 ;
V_86 = F_116 ( NULL , sizeof( struct V_197 ) , 0 ,
V_253 ) ;
if ( V_86 )
return V_86 ;
V_86 = F_117 () ;
return V_86 ;
}
static void F_118 ( void )
{
F_119 () ;
F_120 () ;
}
