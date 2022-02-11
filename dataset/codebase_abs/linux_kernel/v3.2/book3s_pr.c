void F_1 ( struct V_1 * V_2 , int V_3 )
{
#ifdef F_2
memcpy ( F_3 ( V_2 ) -> V_4 , F_4 ( V_2 ) -> V_5 , sizeof( F_3 ( V_2 ) -> V_4 ) ) ;
memcpy ( & F_5 () -> V_6 , F_4 ( V_2 ) -> V_6 ,
sizeof( F_5 () -> V_6 ) ) ;
F_3 ( V_2 ) -> V_7 = F_4 ( V_2 ) -> V_8 ;
#endif
#ifdef F_6
V_9 -> V_10 . V_11 = F_4 ( V_2 ) -> V_6 ;
#endif
}
void F_7 ( struct V_1 * V_2 )
{
#ifdef F_2
memcpy ( F_4 ( V_2 ) -> V_5 , F_3 ( V_2 ) -> V_4 , sizeof( F_3 ( V_2 ) -> V_4 ) ) ;
memcpy ( F_4 ( V_2 ) -> V_6 , & F_5 () -> V_6 ,
sizeof( F_5 () -> V_6 ) ) ;
F_4 ( V_2 ) -> V_8 = F_3 ( V_2 ) -> V_7 ;
#endif
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , V_13 ) ;
F_8 ( V_2 , V_14 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_1 V_15 = V_2 -> V_16 . V_17 -> V_18 ;
V_15 &= V_19 | V_20 | V_21 | V_22 | V_23 | V_24 ;
V_15 |= V_25 | V_26 | V_27 | V_28 | V_29 | V_30 ;
V_15 |= ( V_2 -> V_16 . V_17 -> V_18 & V_2 -> V_16 . V_31 ) ;
#ifdef F_2
V_15 |= V_32 | V_33 ;
#endif
V_2 -> V_16 . V_34 = V_15 ;
}
void F_10 ( struct V_1 * V_2 , T_2 V_18 )
{
T_1 V_35 = V_2 -> V_16 . V_17 -> V_18 ;
#ifdef F_11
F_12 ( V_36 L_1 , V_18 ) ;
#endif
V_18 &= F_4 ( V_2 ) -> V_37 ;
V_2 -> V_16 . V_17 -> V_18 = V_18 ;
F_9 ( V_2 ) ;
if ( V_18 & V_38 ) {
if ( ! V_2 -> V_16 . V_39 ) {
F_13 ( V_2 ) ;
V_2 -> V_40 . V_41 ++ ;
V_18 &= ~ V_38 ;
V_2 -> V_16 . V_17 -> V_18 = V_18 ;
}
}
if ( ( V_2 -> V_16 . V_17 -> V_18 & ( V_29 | V_27 | V_28 ) ) !=
( V_35 & ( V_29 | V_27 | V_28 ) ) ) {
F_14 ( V_2 ) ;
F_15 ( V_2 , F_16 ( V_2 ) ) ;
if ( ! ( V_18 & V_29 ) && V_2 -> V_16 . V_42 ) {
struct V_43 * V_44 = & V_2 -> V_16 ;
if ( V_18 & V_28 )
F_15 ( V_2 , V_44 -> V_45 ) ;
else
F_15 ( V_2 , V_44 -> V_42 ) ;
}
}
if ( V_2 -> V_16 . V_17 -> V_18 & V_12 )
F_17 ( V_2 , V_46 , V_12 ) ;
}
void F_18 ( struct V_1 * V_2 , T_3 V_47 )
{
T_3 V_48 ;
V_2 -> V_16 . V_49 &= ~ V_50 ;
V_2 -> V_16 . V_47 = V_47 ;
#ifdef F_2
if ( ( V_47 >= 0x330000 ) && ( V_47 < 0x70330000 ) ) {
F_19 ( V_2 ) ;
F_4 ( V_2 ) -> V_51 = 0xfff00000 ;
F_4 ( V_2 ) -> V_37 = 0xffffffffffffffffULL ;
V_2 -> V_16 . V_52 = V_53 ;
} else
#endif
{
F_20 ( V_2 ) ;
F_4 ( V_2 ) -> V_51 = 0 ;
F_4 ( V_2 ) -> V_37 = 0xffffffffULL ;
V_2 -> V_16 . V_52 = V_54 ;
}
F_21 ( V_2 ) ;
V_2 -> V_16 . V_49 &= ~ V_55 ;
if ( V_2 -> V_16 . V_56 . V_57 ( V_2 ) && ( F_22 () & V_33 ) &&
! strcmp ( V_58 -> V_59 , L_2 ) )
V_2 -> V_16 . V_49 |= V_55 ;
if ( ! strcmp ( V_58 -> V_59 , L_3 ) )
F_4 ( V_2 ) -> V_37 &= ~ ( V_19 | V_20 ) ;
#ifdef F_6
V_2 -> V_16 . V_49 |= V_55 ;
#endif
asm ( "mfpvr %0" : "=r"(host_pvr));
switch ( V_48 ) {
case 0x00080200 :
case 0x00088202 :
case 0x70000100 :
case 0x00080100 :
case 0x00083203 :
case 0x00083213 :
case 0x00083204 :
case 0x00083214 :
case 0x00087200 :
V_2 -> V_16 . V_49 |= V_60 ;
F_23 ( V_61 , F_24 ( V_61 ) | ( 1 << 29 ) ) ;
}
}
static void F_25 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
struct V_64 * V_65 ;
T_2 V_66 ;
T_3 * V_64 ;
int V_67 ;
V_65 = F_26 ( V_2 -> V_68 , V_63 -> V_69 >> V_70 ) ;
if ( F_27 ( V_65 ) ) {
F_28 ( V_65 ) ;
return;
}
V_66 = V_63 -> V_69 & ~ V_71 ;
V_66 &= ~ 0xFFFULL ;
V_66 /= 4 ;
F_29 ( V_65 ) ;
V_64 = F_30 ( V_65 , V_72 ) ;
for ( V_67 = V_66 ; V_67 < V_66 + ( V_73 / 4 ) ; V_67 ++ )
if ( ( V_64 [ V_67 ] & 0xff0007ff ) == V_74 )
V_64 [ V_67 ] &= 0xfffffff7 ;
F_31 ( V_64 , V_72 ) ;
F_32 ( V_65 ) ;
}
static int F_33 ( struct V_1 * V_2 , T_4 V_75 )
{
T_1 V_76 = V_2 -> V_16 . V_42 ;
if ( F_34 ( V_76 ) &&
F_34 ( ( V_76 & V_77 ) >> V_70 == V_75 ) ) {
return 1 ;
}
return F_35 ( V_2 -> V_68 , V_75 ) ;
}
int F_36 ( struct V_78 * V_79 , struct V_1 * V_2 ,
T_1 V_80 , int V_81 )
{
bool V_82 = ( V_81 == V_83 ) ;
int V_84 = V_85 ;
int V_86 ;
int V_87 = 0 ;
struct V_62 V_63 ;
bool V_88 = false ;
bool V_89 = ( V_2 -> V_16 . V_17 -> V_18 & V_28 ) ? true : false ;
bool V_90 = ( V_2 -> V_16 . V_17 -> V_18 & V_27 ) ? true : false ;
T_2 V_91 ;
V_86 = V_82 ? V_89 : V_90 ;
if ( V_86 ) {
V_87 = V_2 -> V_16 . V_56 . V_92 ( V_2 , V_80 , & V_63 , V_82 ) ;
} else {
V_63 . V_93 = true ;
V_63 . V_94 = true ;
V_63 . V_95 = true ;
V_63 . V_69 = V_80 & V_77 ;
V_63 . V_80 = V_80 ;
V_63 . V_96 = V_80 >> 12 ;
}
switch ( V_2 -> V_16 . V_17 -> V_18 & ( V_28 | V_27 ) ) {
case 0 :
V_63 . V_96 |= ( ( T_2 ) V_97 << ( V_98 - 12 ) ) ;
break;
case V_28 :
case V_27 :
V_2 -> V_16 . V_56 . V_99 ( V_2 , V_80 >> V_98 , & V_91 ) ;
if ( ( V_2 -> V_16 . V_17 -> V_18 & ( V_28 | V_27 ) ) == V_28 )
V_63 . V_96 |= ( ( T_2 ) V_100 << ( V_98 - 12 ) ) ;
else
V_63 . V_96 |= ( ( T_2 ) V_101 << ( V_98 - 12 ) ) ;
V_63 . V_96 |= V_91 ;
if ( V_91 == - 1 )
V_87 = - V_102 ;
break;
}
if ( V_2 -> V_16 . V_56 . V_57 ( V_2 ) &&
( ! ( V_2 -> V_16 . V_49 & V_55 ) ) ) {
V_63 . V_93 = ! V_82 ;
}
if ( V_87 == - V_103 ) {
V_2 -> V_16 . V_17 -> V_104 = F_37 ( V_2 ) ;
V_2 -> V_16 . V_17 -> V_105 = F_3 ( V_2 ) -> V_106 ;
V_2 -> V_16 . V_17 -> V_18 |=
( F_3 ( V_2 ) -> V_107 & 0x00000000f8000000ULL ) ;
F_38 ( V_2 , V_81 ) ;
} else if ( V_87 == - V_108 ) {
V_2 -> V_16 . V_17 -> V_104 = F_37 ( V_2 ) ;
V_2 -> V_16 . V_17 -> V_105 =
F_3 ( V_2 ) -> V_106 & ~ V_109 ;
V_2 -> V_16 . V_17 -> V_105 |= V_110 ;
V_2 -> V_16 . V_17 -> V_18 |=
( F_3 ( V_2 ) -> V_107 & 0x00000000f8000000ULL ) ;
F_38 ( V_2 , V_81 ) ;
} else if ( V_87 == - V_102 ) {
V_2 -> V_16 . V_17 -> V_104 = F_37 ( V_2 ) ;
F_38 ( V_2 , V_81 + 0x80 ) ;
} else if ( ! V_88 &&
F_33 ( V_2 , V_63 . V_69 >> V_70 ) ) {
F_39 ( V_2 , & V_63 ) ;
if ( V_82 )
V_2 -> V_40 . V_111 ++ ;
else if ( V_2 -> V_16 . V_56 . V_57 ( V_2 ) &&
( ! ( V_2 -> V_16 . V_49 & V_55 ) ) )
F_25 ( V_2 , & V_63 ) ;
} else {
V_2 -> V_40 . V_112 ++ ;
V_2 -> V_16 . V_113 = V_63 . V_69 ;
V_84 = F_40 ( V_79 , V_2 ) ;
if ( V_84 == V_114 )
V_84 = V_115 ;
}
return V_84 ;
}
static inline int F_41 ( int V_67 )
{
#ifdef F_42
V_67 *= 2 ;
#endif
return V_67 ;
}
void F_8 ( struct V_1 * V_2 , T_1 V_18 )
{
struct V_116 * V_117 = & V_9 -> V_10 ;
T_2 * V_118 = V_2 -> V_16 . V_119 ;
#ifdef F_42
T_2 * V_120 = V_2 -> V_16 . V_121 ;
#endif
T_2 * V_122 = ( T_2 * ) V_117 -> V_119 ;
int V_67 ;
if ( ! ( V_2 -> V_16 . V_31 & V_18 ) )
return;
#ifdef F_43
F_12 ( V_36 L_4 , V_18 ) ;
#endif
switch ( V_18 ) {
case V_12 :
F_44 ( V_9 ) ;
for ( V_67 = 0 ; V_67 < F_45 ( V_2 -> V_16 . V_119 ) ; V_67 ++ )
V_118 [ V_67 ] = V_122 [ F_41 ( V_67 ) ] ;
V_2 -> V_16 . V_123 = V_117 -> V_123 . V_124 ;
break;
case V_13 :
#ifdef F_46
F_47 ( V_9 ) ;
memcpy ( V_2 -> V_16 . V_125 , V_117 -> V_125 , sizeof( V_2 -> V_16 . V_125 ) ) ;
V_2 -> V_16 . V_126 = V_117 -> V_126 ;
#endif
break;
case V_14 :
#ifdef F_42
F_48 ( V_9 ) ;
for ( V_67 = 0 ; V_67 < F_45 ( V_2 -> V_16 . V_121 ) ; V_67 ++ )
V_120 [ V_67 ] = V_122 [ F_41 ( V_67 ) + 1 ] ;
#endif
break;
default:
F_49 () ;
}
V_2 -> V_16 . V_31 &= ~ V_18 ;
V_9 -> V_10 . V_127 -> V_18 &= ~ V_18 ;
F_9 ( V_2 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
T_1 V_128 = F_16 ( V_2 ) ;
T_3 V_129 = F_51 ( V_2 ) ;
int V_130 ;
V_130 = F_52 ( V_2 , & V_128 , sizeof( T_3 ) , & V_129 , false ) ;
if ( V_130 == - V_103 ) {
T_1 V_18 = V_2 -> V_16 . V_17 -> V_18 ;
V_18 = F_53 ( V_18 , 33 , 33 , 1 ) ;
V_18 = F_53 ( V_18 , 34 , 36 , 0 ) ;
V_2 -> V_16 . V_17 -> V_18 = F_53 ( V_18 , 42 , 47 , 0 ) ;
F_38 ( V_2 , V_131 ) ;
return V_132 ;
}
return V_133 ;
}
static int F_54 ( struct V_1 * V_2 , unsigned int V_134 )
{
if ( ! ( V_2 -> V_16 . V_49 & V_135 ) )
return V_133 ;
if ( F_50 ( V_2 ) == V_133 )
return V_136 ;
return V_132 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_134 ,
T_1 V_18 )
{
struct V_116 * V_117 = & V_9 -> V_10 ;
T_2 * V_118 = V_2 -> V_16 . V_119 ;
#ifdef F_42
T_2 * V_120 = V_2 -> V_16 . V_121 ;
#endif
T_2 * V_122 = ( T_2 * ) V_117 -> V_119 ;
int V_67 ;
if ( V_2 -> V_16 . V_49 & V_135 )
return V_85 ;
if ( ! ( V_2 -> V_16 . V_17 -> V_18 & V_18 ) ) {
F_38 ( V_2 , V_134 ) ;
return V_85 ;
}
if ( V_2 -> V_16 . V_31 & V_18 ) {
return V_85 ;
}
#ifdef F_43
F_12 ( V_36 L_5 , V_18 ) ;
#endif
V_9 -> V_10 . V_127 -> V_18 |= V_18 ;
switch ( V_18 ) {
case V_12 :
for ( V_67 = 0 ; V_67 < F_45 ( V_2 -> V_16 . V_119 ) ; V_67 ++ )
V_122 [ F_41 ( V_67 ) ] = V_118 [ V_67 ] ;
V_117 -> V_123 . V_124 = V_2 -> V_16 . V_123 ;
V_117 -> V_137 = 0 ;
F_55 () ;
break;
case V_13 :
#ifdef F_46
memcpy ( V_117 -> V_125 , V_2 -> V_16 . V_125 , sizeof( V_2 -> V_16 . V_125 ) ) ;
V_117 -> V_126 = V_2 -> V_16 . V_126 ;
V_117 -> V_138 = - 1 ;
F_56 () ;
#endif
break;
case V_14 :
#ifdef F_42
for ( V_67 = 0 ; V_67 < F_45 ( V_2 -> V_16 . V_121 ) ; V_67 ++ )
V_122 [ F_41 ( V_67 ) + 1 ] = V_120 [ V_67 ] ;
F_57 () ;
#endif
break;
default:
F_49 () ;
}
V_2 -> V_16 . V_31 |= V_18 ;
F_9 ( V_2 ) ;
return V_85 ;
}
int F_58 ( struct V_78 * V_79 , struct V_1 * V_2 ,
unsigned int V_134 )
{
int V_84 = V_115 ;
V_2 -> V_40 . V_139 ++ ;
V_79 -> V_140 = V_141 ;
V_79 -> V_142 = 1 ;
F_59 ( V_134 , V_2 ) ;
F_60 ( V_2 ) ;
switch ( V_134 ) {
case V_131 :
V_2 -> V_40 . V_143 ++ ;
#ifdef F_6
if ( F_3 ( V_2 ) -> V_144 [ F_16 ( V_2 ) >> V_98 ]
== V_145 ) {
F_15 ( V_2 , F_16 ( V_2 ) ) ;
V_84 = V_85 ;
break;
}
#endif
if ( F_3 ( V_2 ) -> V_107 & 0x40000000 ) {
V_84 = F_36 ( V_79 , V_2 , F_16 ( V_2 ) , V_134 ) ;
V_2 -> V_40 . V_146 ++ ;
} else if ( V_2 -> V_16 . V_56 . V_57 ( V_2 ) &&
( ! ( V_2 -> V_16 . V_49 & V_55 ) ) ) {
F_61 ( V_2 , F_16 ( V_2 ) , ~ 0xFFFUL ) ;
V_84 = V_85 ;
} else {
V_2 -> V_16 . V_17 -> V_18 |=
F_3 ( V_2 ) -> V_107 & 0x58000000 ;
F_38 ( V_2 , V_134 ) ;
V_84 = V_85 ;
}
break;
case V_83 :
{
T_1 V_104 = F_37 ( V_2 ) ;
V_2 -> V_40 . V_147 ++ ;
#ifdef F_6
if ( ( F_3 ( V_2 ) -> V_144 [ V_104 >> V_98 ] ) == V_145 ) {
F_15 ( V_2 , V_104 ) ;
V_84 = V_85 ;
break;
}
#endif
if ( F_3 ( V_2 ) -> V_106 & V_109 ) {
V_84 = F_36 ( V_79 , V_2 , V_104 , V_134 ) ;
} else {
V_2 -> V_16 . V_17 -> V_104 = V_104 ;
V_2 -> V_16 . V_17 -> V_105 = F_3 ( V_2 ) -> V_106 ;
F_38 ( V_2 , V_134 ) ;
V_84 = V_85 ;
}
break;
}
case V_148 :
if ( F_15 ( V_2 , F_37 ( V_2 ) ) < 0 ) {
V_2 -> V_16 . V_17 -> V_104 = F_37 ( V_2 ) ;
F_38 ( V_2 ,
V_148 ) ;
}
V_84 = V_85 ;
break;
case V_149 :
if ( F_15 ( V_2 , F_16 ( V_2 ) ) < 0 ) {
F_38 ( V_2 ,
V_149 ) ;
}
V_84 = V_85 ;
break;
case V_150 :
V_2 -> V_40 . V_151 ++ ;
V_84 = V_85 ;
break;
case V_152 :
V_2 -> V_40 . V_153 ++ ;
V_84 = V_85 ;
break;
case V_154 :
V_84 = V_85 ;
break;
case V_155 :
{
enum V_156 V_157 ;
T_1 V_158 ;
V_159:
V_158 = F_3 ( V_2 ) -> V_107 & 0x1f0000ull ;
if ( V_2 -> V_16 . V_17 -> V_18 & V_29 ) {
#ifdef F_11
F_12 ( V_36 L_6 , F_16 ( V_2 ) , F_51 ( V_2 ) ) ;
#endif
if ( ( F_51 ( V_2 ) & 0xff0007ff ) !=
( V_74 & 0xfffffff7 ) ) {
F_62 ( V_2 , V_158 ) ;
V_84 = V_85 ;
break;
}
}
V_2 -> V_40 . V_160 ++ ;
V_157 = F_63 ( V_79 , V_2 ) ;
switch ( V_157 ) {
case V_133 :
V_84 = V_161 ;
break;
case V_132 :
V_84 = V_85 ;
break;
case V_136 :
F_12 ( V_162 L_7 ,
V_163 , F_16 ( V_2 ) , F_51 ( V_2 ) ) ;
F_62 ( V_2 , V_158 ) ;
V_84 = V_85 ;
break;
case V_164 :
V_79 -> V_140 = V_165 ;
V_84 = V_114 ;
break;
default:
F_49 () ;
}
break;
}
case V_166 :
if ( V_2 -> V_16 . V_167 &&
( F_51 ( V_2 ) == 0x44000022 ) &&
! ( V_2 -> V_16 . V_17 -> V_18 & V_29 ) ) {
T_1 V_168 = F_64 ( V_2 , 3 ) ;
int V_67 ;
#ifdef F_65
if ( F_66 ( V_2 , V_168 ) == V_133 ) {
V_84 = V_85 ;
break;
}
#endif
V_79 -> V_169 . V_170 = V_168 ;
for ( V_67 = 0 ; V_67 < 9 ; ++ V_67 ) {
T_1 V_171 = F_64 ( V_2 , 4 + V_67 ) ;
V_79 -> V_169 . args [ V_67 ] = V_171 ;
}
V_79 -> V_140 = V_172 ;
V_2 -> V_16 . V_173 = 1 ;
V_84 = V_115 ;
} else if ( V_2 -> V_16 . V_174 &&
( ( ( T_3 ) F_64 ( V_2 , 3 ) ) == V_175 ) &&
( ( ( T_3 ) F_64 ( V_2 , 4 ) ) == V_176 ) ) {
T_2 * V_177 = V_79 -> V_178 . V_177 ;
int V_67 ;
V_79 -> V_140 = V_179 ;
for ( V_67 = 0 ; V_67 < 32 ; V_67 ++ )
V_177 [ V_67 ] = F_64 ( V_2 , V_67 ) ;
V_2 -> V_16 . V_180 = 1 ;
V_84 = V_114 ;
} else if ( ! ( V_2 -> V_16 . V_17 -> V_18 & V_29 ) &&
( ( ( T_3 ) F_64 ( V_2 , 0 ) ) == V_181 ) ) {
F_67 ( V_2 , 3 , F_68 ( V_2 ) ) ;
V_84 = V_85 ;
} else {
V_2 -> V_40 . V_182 ++ ;
F_38 ( V_2 , V_134 ) ;
V_84 = V_85 ;
}
break;
case V_46 :
case V_183 :
case V_184 :
{
int V_185 = 0 ;
switch ( V_134 ) {
case V_46 : V_185 = V_12 ; break;
case V_183 : V_185 = V_13 ; break;
case V_184 : V_185 = V_14 ; break;
}
switch ( F_54 ( V_2 , V_134 ) ) {
case V_133 :
V_84 = F_17 ( V_2 , V_134 , V_185 ) ;
break;
case V_136 :
goto V_159;
break;
default:
break;
}
break;
}
case V_186 :
if ( F_50 ( V_2 ) == V_133 ) {
V_2 -> V_16 . V_17 -> V_105 = F_69 ( V_2 ,
F_51 ( V_2 ) ) ;
V_2 -> V_16 . V_17 -> V_104 = F_70 ( V_2 ,
F_51 ( V_2 ) ) ;
F_38 ( V_2 , V_134 ) ;
}
V_84 = V_85 ;
break;
case V_187 :
case V_188 :
F_38 ( V_2 , V_134 ) ;
V_84 = V_85 ;
break;
default:
F_12 ( V_189 L_8 ,
V_134 , F_16 ( V_2 ) , F_3 ( V_2 ) -> V_107 ) ;
V_84 = V_115 ;
F_49 () ;
break;
}
if ( ! ( V_84 & V_115 ) ) {
if ( F_71 ( V_9 ) ) {
#ifdef F_11
F_12 ( V_189 L_9 ) ;
#endif
V_2 -> V_40 . V_190 ++ ;
V_79 -> V_140 = V_191 ;
V_84 = - V_192 ;
} else {
F_72 ( V_2 ) ;
}
}
F_73 ( V_84 , V_2 ) ;
return V_84 ;
}
int F_74 ( struct V_1 * V_2 ,
struct V_193 * V_194 )
{
struct V_195 * V_196 = F_4 ( V_2 ) ;
int V_67 ;
V_194 -> V_47 = V_2 -> V_16 . V_47 ;
V_194 -> V_197 . V_198 . V_199 = F_4 ( V_2 ) -> V_199 ;
if ( V_2 -> V_16 . V_49 & V_50 ) {
for ( V_67 = 0 ; V_67 < 64 ; V_67 ++ ) {
V_194 -> V_197 . V_198 . V_200 . V_4 [ V_67 ] . V_201 = V_2 -> V_16 . V_4 [ V_67 ] . V_202 | V_67 ;
V_194 -> V_197 . V_198 . V_200 . V_4 [ V_67 ] . V_203 = V_2 -> V_16 . V_4 [ V_67 ] . V_204 ;
}
} else {
for ( V_67 = 0 ; V_67 < 16 ; V_67 ++ )
V_194 -> V_197 . V_198 . V_205 . V_144 [ V_67 ] = V_2 -> V_16 . V_17 -> V_144 [ V_67 ] ;
for ( V_67 = 0 ; V_67 < 8 ; V_67 ++ ) {
V_194 -> V_197 . V_198 . V_205 . V_206 [ V_67 ] = V_196 -> V_206 [ V_67 ] . V_207 ;
V_194 -> V_197 . V_198 . V_205 . V_208 [ V_67 ] = V_196 -> V_208 [ V_67 ] . V_207 ;
}
}
return 0 ;
}
int F_75 ( struct V_1 * V_2 ,
struct V_193 * V_194 )
{
struct V_195 * V_196 = F_4 ( V_2 ) ;
int V_67 ;
F_18 ( V_2 , V_194 -> V_47 ) ;
V_196 -> V_199 = V_194 -> V_197 . V_198 . V_199 ;
if ( V_2 -> V_16 . V_49 & V_50 ) {
for ( V_67 = 0 ; V_67 < 64 ; V_67 ++ ) {
V_2 -> V_16 . V_56 . V_209 ( V_2 , V_194 -> V_197 . V_198 . V_200 . V_4 [ V_67 ] . V_203 ,
V_194 -> V_197 . V_198 . V_200 . V_4 [ V_67 ] . V_201 ) ;
}
} else {
for ( V_67 = 0 ; V_67 < 16 ; V_67 ++ ) {
V_2 -> V_16 . V_56 . V_210 ( V_2 , V_67 , V_194 -> V_197 . V_198 . V_205 . V_144 [ V_67 ] ) ;
}
for ( V_67 = 0 ; V_67 < 8 ; V_67 ++ ) {
F_76 ( V_2 , & ( V_196 -> V_206 [ V_67 ] ) , false ,
( T_3 ) V_194 -> V_197 . V_198 . V_205 . V_206 [ V_67 ] ) ;
F_76 ( V_2 , & ( V_196 -> V_206 [ V_67 ] ) , true ,
( T_3 ) ( V_194 -> V_197 . V_198 . V_205 . V_206 [ V_67 ] >> 32 ) ) ;
F_76 ( V_2 , & ( V_196 -> V_208 [ V_67 ] ) , false ,
( T_3 ) V_194 -> V_197 . V_198 . V_205 . V_208 [ V_67 ] ) ;
F_76 ( V_2 , & ( V_196 -> V_208 [ V_67 ] ) , true ,
( T_3 ) ( V_194 -> V_197 . V_198 . V_205 . V_208 [ V_67 ] >> 32 ) ) ;
}
}
F_61 ( V_2 , 0 , 0 ) ;
return 0 ;
}
int F_77 ( void )
{
return 0 ;
}
struct V_1 * F_78 ( struct V_68 * V_68 , unsigned int V_211 )
{
struct V_195 * V_212 ;
struct V_1 * V_2 ;
int V_213 = - V_214 ;
unsigned long V_215 ;
V_212 = F_79 ( sizeof( struct V_195 ) ) ;
if ( ! V_212 )
goto V_216;
V_212 -> V_6 = (struct V_217 * )
F_80 ( sizeof( * V_212 -> V_6 ) , V_218 ) ;
if ( ! V_212 -> V_6 )
goto V_219;
V_2 = & V_212 -> V_2 ;
V_213 = F_81 ( V_2 , V_68 , V_211 ) ;
if ( V_213 )
goto V_220;
V_215 = F_82 ( V_218 | V_221 ) ;
V_2 -> V_16 . V_17 = ( void * ) ( V_215 + V_222 - 4096 ) ;
if ( ! V_215 )
goto V_223;
#ifdef F_2
V_2 -> V_16 . V_47 = 0x3C0301 ;
#else
V_2 -> V_16 . V_47 = 0x84202 ;
#endif
F_18 ( V_2 , V_2 -> V_16 . V_47 ) ;
V_2 -> V_16 . V_224 = 64 ;
V_2 -> V_16 . V_34 = V_225 ;
V_213 = F_83 ( V_2 ) ;
if ( V_213 < 0 )
goto V_223;
return V_2 ;
V_223:
F_84 ( V_2 ) ;
V_220:
F_85 ( V_212 -> V_6 ) ;
V_219:
F_86 ( V_212 ) ;
V_216:
return F_87 ( V_213 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
struct V_195 * V_212 = F_4 ( V_2 ) ;
F_89 ( ( unsigned long ) V_2 -> V_16 . V_17 & V_71 ) ;
F_84 ( V_2 ) ;
F_85 ( V_212 -> V_6 ) ;
F_86 ( V_212 ) ;
}
int F_90 ( struct V_78 * V_78 , struct V_1 * V_2 )
{
int V_130 ;
double V_119 [ 32 ] [ V_226 ] ;
unsigned int V_123 ;
int V_137 ;
#ifdef F_46
T_5 V_125 [ 32 ] ;
T_5 V_126 ;
unsigned long V_227 ( V_138 ) ;
int V_228 ;
#endif
#ifdef F_42
int V_229 ;
#endif
T_1 V_185 ;
if ( ! V_2 -> V_16 . V_230 ) {
V_78 -> V_140 = V_231 ;
return - V_102 ;
}
if ( F_71 ( V_9 ) ) {
V_78 -> V_140 = V_191 ;
return - V_192 ;
}
if ( V_9 -> V_10 . V_127 -> V_18 & V_12 )
F_44 ( V_9 ) ;
memcpy ( V_119 , V_9 -> V_10 . V_119 , sizeof( V_9 -> V_10 . V_119 ) ) ;
V_123 = V_9 -> V_10 . V_123 . V_124 ;
V_137 = V_9 -> V_10 . V_137 ;
#ifdef F_46
V_228 = V_9 -> V_10 . V_228 ;
if ( V_228 ) {
if ( V_9 -> V_10 . V_127 -> V_18 & V_13 )
F_47 ( V_9 ) ;
memcpy ( V_125 , V_9 -> V_10 . V_125 , sizeof( V_9 -> V_10 . V_125 ) ) ;
V_126 = V_9 -> V_10 . V_126 ;
V_138 = V_9 -> V_10 . V_138 ;
}
#endif
#ifdef F_42
V_229 = V_9 -> V_10 . V_229 ;
if ( V_229 && ( V_9 -> V_10 . V_127 -> V_18 & V_14 ) )
F_48 ( V_9 ) ;
#endif
V_185 = V_9 -> V_10 . V_127 -> V_18 ;
if ( V_2 -> V_16 . V_17 -> V_18 & V_12 )
F_17 ( V_2 , V_46 , V_12 ) ;
F_91 () ;
V_130 = F_92 ( V_78 , V_2 ) ;
F_93 () ;
F_94 () ;
V_9 -> V_10 . V_127 -> V_18 = V_185 ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , V_13 ) ;
F_8 ( V_2 , V_14 ) ;
memcpy ( V_9 -> V_10 . V_119 , V_119 , sizeof( V_9 -> V_10 . V_119 ) ) ;
V_9 -> V_10 . V_123 . V_124 = V_123 ;
V_9 -> V_10 . V_137 = V_137 ;
#ifdef F_46
if ( V_228 && V_9 -> V_10 . V_228 ) {
memcpy ( V_9 -> V_10 . V_125 , V_125 , sizeof( V_9 -> V_10 . V_125 ) ) ;
V_9 -> V_10 . V_126 = V_126 ;
V_9 -> V_10 . V_138 = V_138 ;
}
V_9 -> V_10 . V_228 = V_228 ;
#endif
#ifdef F_42
V_9 -> V_10 . V_229 = V_229 ;
#endif
return V_130 ;
}
int F_95 ( struct V_68 * V_68 ,
struct V_232 * V_233 )
{
return 0 ;
}
void F_96 ( struct V_68 * V_68 ,
struct V_232 * V_233 )
{
}
int F_97 ( struct V_68 * V_68 )
{
return 0 ;
}
void F_98 ( struct V_68 * V_68 )
{
}
static int F_99 ( void )
{
int V_84 ;
V_84 = F_100 ( NULL , sizeof( struct V_195 ) , 0 ,
V_234 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_101 () ;
return V_84 ;
}
static void F_102 ( void )
{
F_103 () ;
F_104 () ;
}
