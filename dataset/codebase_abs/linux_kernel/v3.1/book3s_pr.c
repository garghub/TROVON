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
} else
#endif
{
F_20 ( V_2 ) ;
F_4 ( V_2 ) -> V_51 = 0 ;
F_4 ( V_2 ) -> V_37 = 0xffffffffULL ;
}
V_2 -> V_16 . V_49 &= ~ V_52 ;
if ( V_2 -> V_16 . V_53 . V_54 ( V_2 ) && ( F_21 () & V_33 ) &&
! strcmp ( V_55 -> V_56 , L_2 ) )
V_2 -> V_16 . V_49 |= V_52 ;
if ( ! strcmp ( V_55 -> V_56 , L_3 ) )
F_4 ( V_2 ) -> V_37 &= ~ ( V_19 | V_20 ) ;
#ifdef F_6
V_2 -> V_16 . V_49 |= V_52 ;
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
V_2 -> V_16 . V_49 |= V_57 ;
F_22 ( V_58 , F_23 ( V_58 ) | ( 1 << 29 ) ) ;
}
}
static void F_24 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
struct V_61 * V_62 ;
T_2 V_63 ;
T_3 * V_61 ;
int V_64 ;
V_62 = F_25 ( V_2 -> V_65 , V_60 -> V_66 >> V_67 ) ;
if ( F_26 ( V_62 ) ) {
F_27 ( V_62 ) ;
return;
}
V_63 = V_60 -> V_66 & ~ V_68 ;
V_63 &= ~ 0xFFFULL ;
V_63 /= 4 ;
F_28 ( V_62 ) ;
V_61 = F_29 ( V_62 , V_69 ) ;
for ( V_64 = V_63 ; V_64 < V_63 + ( V_70 / 4 ) ; V_64 ++ )
if ( ( V_61 [ V_64 ] & 0xff0007ff ) == V_71 )
V_61 [ V_64 ] &= 0xfffffff7 ;
F_30 ( V_61 , V_69 ) ;
F_31 ( V_62 ) ;
}
static int F_32 ( struct V_1 * V_2 , T_4 V_72 )
{
T_1 V_73 = V_2 -> V_16 . V_42 ;
if ( F_33 ( V_73 ) &&
F_33 ( ( V_73 & V_74 ) >> V_67 == V_72 ) ) {
return 1 ;
}
return F_34 ( V_2 -> V_65 , V_72 ) ;
}
int F_35 ( struct V_75 * V_76 , struct V_1 * V_2 ,
T_1 V_77 , int V_78 )
{
bool V_79 = ( V_78 == V_80 ) ;
int V_81 = V_82 ;
int V_83 ;
int V_84 = 0 ;
struct V_59 V_60 ;
bool V_85 = false ;
bool V_86 = ( V_2 -> V_16 . V_17 -> V_18 & V_28 ) ? true : false ;
bool V_87 = ( V_2 -> V_16 . V_17 -> V_18 & V_27 ) ? true : false ;
T_2 V_88 ;
V_83 = V_79 ? V_86 : V_87 ;
if ( V_83 ) {
V_84 = V_2 -> V_16 . V_53 . V_89 ( V_2 , V_77 , & V_60 , V_79 ) ;
} else {
V_60 . V_90 = true ;
V_60 . V_91 = true ;
V_60 . V_92 = true ;
V_60 . V_66 = V_77 & V_74 ;
V_60 . V_77 = V_77 ;
V_60 . V_93 = V_77 >> 12 ;
}
switch ( V_2 -> V_16 . V_17 -> V_18 & ( V_28 | V_27 ) ) {
case 0 :
V_60 . V_93 |= ( ( T_2 ) V_94 << ( V_95 - 12 ) ) ;
break;
case V_28 :
case V_27 :
V_2 -> V_16 . V_53 . V_96 ( V_2 , V_77 >> V_95 , & V_88 ) ;
if ( ( V_2 -> V_16 . V_17 -> V_18 & ( V_28 | V_27 ) ) == V_28 )
V_60 . V_93 |= ( ( T_2 ) V_97 << ( V_95 - 12 ) ) ;
else
V_60 . V_93 |= ( ( T_2 ) V_98 << ( V_95 - 12 ) ) ;
V_60 . V_93 |= V_88 ;
if ( V_88 == - 1 )
V_84 = - V_99 ;
break;
}
if ( V_2 -> V_16 . V_53 . V_54 ( V_2 ) &&
( ! ( V_2 -> V_16 . V_49 & V_52 ) ) ) {
V_60 . V_90 = ! V_79 ;
}
if ( V_84 == - V_100 ) {
V_2 -> V_16 . V_17 -> V_101 = F_36 ( V_2 ) ;
V_2 -> V_16 . V_17 -> V_102 = F_3 ( V_2 ) -> V_103 ;
V_2 -> V_16 . V_17 -> V_18 |=
( F_3 ( V_2 ) -> V_104 & 0x00000000f8000000ULL ) ;
F_37 ( V_2 , V_78 ) ;
} else if ( V_84 == - V_105 ) {
V_2 -> V_16 . V_17 -> V_101 = F_36 ( V_2 ) ;
V_2 -> V_16 . V_17 -> V_102 =
F_3 ( V_2 ) -> V_103 & ~ V_106 ;
V_2 -> V_16 . V_17 -> V_102 |= V_107 ;
V_2 -> V_16 . V_17 -> V_18 |=
( F_3 ( V_2 ) -> V_104 & 0x00000000f8000000ULL ) ;
F_37 ( V_2 , V_78 ) ;
} else if ( V_84 == - V_99 ) {
V_2 -> V_16 . V_17 -> V_101 = F_36 ( V_2 ) ;
F_37 ( V_2 , V_78 + 0x80 ) ;
} else if ( ! V_85 &&
F_32 ( V_2 , V_60 . V_66 >> V_67 ) ) {
F_38 ( V_2 , & V_60 ) ;
if ( V_79 )
V_2 -> V_40 . V_108 ++ ;
else if ( V_2 -> V_16 . V_53 . V_54 ( V_2 ) &&
( ! ( V_2 -> V_16 . V_49 & V_52 ) ) )
F_24 ( V_2 , & V_60 ) ;
} else {
V_2 -> V_40 . V_109 ++ ;
V_2 -> V_16 . V_110 = V_60 . V_66 ;
V_81 = F_39 ( V_76 , V_2 ) ;
if ( V_81 == V_111 )
V_81 = V_112 ;
}
return V_81 ;
}
static inline int F_40 ( int V_64 )
{
#ifdef F_41
V_64 *= 2 ;
#endif
return V_64 ;
}
void F_8 ( struct V_1 * V_2 , T_1 V_18 )
{
struct V_113 * V_114 = & V_9 -> V_10 ;
T_2 * V_115 = V_2 -> V_16 . V_116 ;
#ifdef F_41
T_2 * V_117 = V_2 -> V_16 . V_118 ;
#endif
T_2 * V_119 = ( T_2 * ) V_114 -> V_116 ;
int V_64 ;
if ( ! ( V_2 -> V_16 . V_31 & V_18 ) )
return;
#ifdef F_42
F_12 ( V_36 L_4 , V_18 ) ;
#endif
switch ( V_18 ) {
case V_12 :
F_43 ( V_9 ) ;
for ( V_64 = 0 ; V_64 < F_44 ( V_2 -> V_16 . V_116 ) ; V_64 ++ )
V_115 [ V_64 ] = V_119 [ F_40 ( V_64 ) ] ;
V_2 -> V_16 . V_120 = V_114 -> V_120 . V_121 ;
break;
case V_13 :
#ifdef F_45
F_46 ( V_9 ) ;
memcpy ( V_2 -> V_16 . V_122 , V_114 -> V_122 , sizeof( V_2 -> V_16 . V_122 ) ) ;
V_2 -> V_16 . V_123 = V_114 -> V_123 ;
#endif
break;
case V_14 :
#ifdef F_41
F_47 ( V_9 ) ;
for ( V_64 = 0 ; V_64 < F_44 ( V_2 -> V_16 . V_118 ) ; V_64 ++ )
V_117 [ V_64 ] = V_119 [ F_40 ( V_64 ) + 1 ] ;
#endif
break;
default:
F_48 () ;
}
V_2 -> V_16 . V_31 &= ~ V_18 ;
V_9 -> V_10 . V_124 -> V_18 &= ~ V_18 ;
F_9 ( V_2 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
T_1 V_125 = F_16 ( V_2 ) ;
T_3 V_126 = F_50 ( V_2 ) ;
int V_127 ;
V_127 = F_51 ( V_2 , & V_125 , sizeof( T_3 ) , & V_126 , false ) ;
if ( V_127 == - V_100 ) {
T_1 V_18 = V_2 -> V_16 . V_17 -> V_18 ;
V_18 = F_52 ( V_18 , 33 , 33 , 1 ) ;
V_18 = F_52 ( V_18 , 34 , 36 , 0 ) ;
V_2 -> V_16 . V_17 -> V_18 = F_52 ( V_18 , 42 , 47 , 0 ) ;
F_37 ( V_2 , V_128 ) ;
return V_129 ;
}
return V_130 ;
}
static int F_53 ( struct V_1 * V_2 , unsigned int V_131 )
{
if ( ! ( V_2 -> V_16 . V_49 & V_132 ) )
return V_130 ;
if ( F_49 ( V_2 ) == V_130 )
return V_133 ;
return V_129 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_131 ,
T_1 V_18 )
{
struct V_113 * V_114 = & V_9 -> V_10 ;
T_2 * V_115 = V_2 -> V_16 . V_116 ;
#ifdef F_41
T_2 * V_117 = V_2 -> V_16 . V_118 ;
#endif
T_2 * V_119 = ( T_2 * ) V_114 -> V_116 ;
int V_64 ;
if ( V_2 -> V_16 . V_49 & V_132 )
return V_82 ;
if ( ! ( V_2 -> V_16 . V_17 -> V_18 & V_18 ) ) {
F_37 ( V_2 , V_131 ) ;
return V_82 ;
}
if ( V_2 -> V_16 . V_31 & V_18 ) {
return V_82 ;
}
#ifdef F_42
F_12 ( V_36 L_5 , V_18 ) ;
#endif
V_9 -> V_10 . V_124 -> V_18 |= V_18 ;
switch ( V_18 ) {
case V_12 :
for ( V_64 = 0 ; V_64 < F_44 ( V_2 -> V_16 . V_116 ) ; V_64 ++ )
V_119 [ F_40 ( V_64 ) ] = V_115 [ V_64 ] ;
V_114 -> V_120 . V_121 = V_2 -> V_16 . V_120 ;
V_114 -> V_134 = 0 ;
F_54 () ;
break;
case V_13 :
#ifdef F_45
memcpy ( V_114 -> V_122 , V_2 -> V_16 . V_122 , sizeof( V_2 -> V_16 . V_122 ) ) ;
V_114 -> V_123 = V_2 -> V_16 . V_123 ;
V_114 -> V_135 = - 1 ;
F_55 () ;
#endif
break;
case V_14 :
#ifdef F_41
for ( V_64 = 0 ; V_64 < F_44 ( V_2 -> V_16 . V_118 ) ; V_64 ++ )
V_119 [ F_40 ( V_64 ) + 1 ] = V_117 [ V_64 ] ;
F_56 () ;
#endif
break;
default:
F_48 () ;
}
V_2 -> V_16 . V_31 |= V_18 ;
F_9 ( V_2 ) ;
return V_82 ;
}
int F_57 ( struct V_75 * V_76 , struct V_1 * V_2 ,
unsigned int V_131 )
{
int V_81 = V_112 ;
V_2 -> V_40 . V_136 ++ ;
V_76 -> V_137 = V_138 ;
V_76 -> V_139 = 1 ;
F_58 ( V_131 , V_2 ) ;
F_59 ( V_2 ) ;
switch ( V_131 ) {
case V_128 :
V_2 -> V_40 . V_140 ++ ;
#ifdef F_6
if ( F_3 ( V_2 ) -> V_141 [ F_16 ( V_2 ) >> V_95 ]
== V_142 ) {
F_15 ( V_2 , F_16 ( V_2 ) ) ;
V_81 = V_82 ;
break;
}
#endif
if ( F_3 ( V_2 ) -> V_104 & 0x40000000 ) {
V_81 = F_35 ( V_76 , V_2 , F_16 ( V_2 ) , V_131 ) ;
V_2 -> V_40 . V_143 ++ ;
} else if ( V_2 -> V_16 . V_53 . V_54 ( V_2 ) &&
( ! ( V_2 -> V_16 . V_49 & V_52 ) ) ) {
F_60 ( V_2 , F_16 ( V_2 ) , ~ 0xFFFUL ) ;
V_81 = V_82 ;
} else {
V_2 -> V_16 . V_17 -> V_18 |=
F_3 ( V_2 ) -> V_104 & 0x58000000 ;
F_37 ( V_2 , V_131 ) ;
V_81 = V_82 ;
}
break;
case V_80 :
{
T_1 V_101 = F_36 ( V_2 ) ;
V_2 -> V_40 . V_144 ++ ;
#ifdef F_6
if ( ( F_3 ( V_2 ) -> V_141 [ V_101 >> V_95 ] ) == V_142 ) {
F_15 ( V_2 , V_101 ) ;
V_81 = V_82 ;
break;
}
#endif
if ( F_3 ( V_2 ) -> V_103 & V_106 ) {
V_81 = F_35 ( V_76 , V_2 , V_101 , V_131 ) ;
} else {
V_2 -> V_16 . V_17 -> V_101 = V_101 ;
V_2 -> V_16 . V_17 -> V_102 = F_3 ( V_2 ) -> V_103 ;
F_37 ( V_2 , V_131 ) ;
V_81 = V_82 ;
}
break;
}
case V_145 :
if ( F_15 ( V_2 , F_36 ( V_2 ) ) < 0 ) {
V_2 -> V_16 . V_17 -> V_101 = F_36 ( V_2 ) ;
F_37 ( V_2 ,
V_145 ) ;
}
V_81 = V_82 ;
break;
case V_146 :
if ( F_15 ( V_2 , F_16 ( V_2 ) ) < 0 ) {
F_37 ( V_2 ,
V_146 ) ;
}
V_81 = V_82 ;
break;
case V_147 :
V_2 -> V_40 . V_148 ++ ;
V_81 = V_82 ;
break;
case V_149 :
V_2 -> V_40 . V_150 ++ ;
V_81 = V_82 ;
break;
case V_151 :
V_81 = V_82 ;
break;
case V_152 :
{
enum V_153 V_154 ;
T_1 V_155 ;
V_156:
V_155 = F_3 ( V_2 ) -> V_104 & 0x1f0000ull ;
if ( V_2 -> V_16 . V_17 -> V_18 & V_29 ) {
#ifdef F_11
F_12 ( V_36 L_6 , F_16 ( V_2 ) , F_50 ( V_2 ) ) ;
#endif
if ( ( F_50 ( V_2 ) & 0xff0007ff ) !=
( V_71 & 0xfffffff7 ) ) {
F_61 ( V_2 , V_155 ) ;
V_81 = V_82 ;
break;
}
}
V_2 -> V_40 . V_157 ++ ;
V_154 = F_62 ( V_76 , V_2 ) ;
switch ( V_154 ) {
case V_130 :
V_81 = V_158 ;
break;
case V_129 :
V_81 = V_82 ;
break;
case V_133 :
F_12 ( V_159 L_7 ,
V_160 , F_16 ( V_2 ) , F_50 ( V_2 ) ) ;
F_61 ( V_2 , V_155 ) ;
V_81 = V_82 ;
break;
case V_161 :
V_76 -> V_137 = V_162 ;
V_81 = V_111 ;
break;
default:
F_48 () ;
}
break;
}
case V_163 :
if ( V_2 -> V_16 . V_164 &&
( ( ( T_3 ) F_63 ( V_2 , 3 ) ) == V_165 ) &&
( ( ( T_3 ) F_63 ( V_2 , 4 ) ) == V_166 ) ) {
T_2 * V_167 = V_76 -> V_168 . V_167 ;
int V_64 ;
V_76 -> V_137 = V_169 ;
for ( V_64 = 0 ; V_64 < 32 ; V_64 ++ )
V_167 [ V_64 ] = F_63 ( V_2 , V_64 ) ;
V_2 -> V_16 . V_170 = 1 ;
V_81 = V_111 ;
} else if ( ! ( V_2 -> V_16 . V_17 -> V_18 & V_29 ) &&
( ( ( T_3 ) F_63 ( V_2 , 0 ) ) == V_171 ) ) {
F_64 ( V_2 , 3 , F_65 ( V_2 ) ) ;
V_81 = V_82 ;
} else {
V_2 -> V_40 . V_172 ++ ;
F_37 ( V_2 , V_131 ) ;
V_81 = V_82 ;
}
break;
case V_46 :
case V_173 :
case V_174 :
{
int V_175 = 0 ;
switch ( V_131 ) {
case V_46 : V_175 = V_12 ; break;
case V_173 : V_175 = V_13 ; break;
case V_174 : V_175 = V_14 ; break;
}
switch ( F_53 ( V_2 , V_131 ) ) {
case V_130 :
V_81 = F_17 ( V_2 , V_131 , V_175 ) ;
break;
case V_133 :
goto V_156;
break;
default:
break;
}
break;
}
case V_176 :
if ( F_49 ( V_2 ) == V_130 ) {
V_2 -> V_16 . V_17 -> V_102 = F_66 ( V_2 ,
F_50 ( V_2 ) ) ;
V_2 -> V_16 . V_17 -> V_101 = F_67 ( V_2 ,
F_50 ( V_2 ) ) ;
F_37 ( V_2 , V_131 ) ;
}
V_81 = V_82 ;
break;
case V_177 :
case V_178 :
F_37 ( V_2 , V_131 ) ;
V_81 = V_82 ;
break;
default:
F_12 ( V_179 L_8 ,
V_131 , F_16 ( V_2 ) , F_3 ( V_2 ) -> V_104 ) ;
V_81 = V_112 ;
F_48 () ;
break;
}
if ( ! ( V_81 & V_112 ) ) {
if ( F_68 ( V_9 ) ) {
#ifdef F_11
F_12 ( V_179 L_9 ) ;
#endif
V_2 -> V_40 . V_180 ++ ;
V_76 -> V_137 = V_181 ;
V_81 = - V_182 ;
} else {
F_69 ( V_2 ) ;
}
}
F_70 ( V_81 , V_2 ) ;
return V_81 ;
}
int F_71 ( struct V_1 * V_2 ,
struct V_183 * V_184 )
{
struct V_185 * V_186 = F_4 ( V_2 ) ;
int V_64 ;
V_184 -> V_47 = V_2 -> V_16 . V_47 ;
V_184 -> V_187 . V_188 . V_189 = F_4 ( V_2 ) -> V_189 ;
if ( V_2 -> V_16 . V_49 & V_50 ) {
for ( V_64 = 0 ; V_64 < 64 ; V_64 ++ ) {
V_184 -> V_187 . V_188 . V_190 . V_4 [ V_64 ] . V_191 = V_2 -> V_16 . V_4 [ V_64 ] . V_192 | V_64 ;
V_184 -> V_187 . V_188 . V_190 . V_4 [ V_64 ] . V_193 = V_2 -> V_16 . V_4 [ V_64 ] . V_194 ;
}
} else {
for ( V_64 = 0 ; V_64 < 16 ; V_64 ++ )
V_184 -> V_187 . V_188 . V_195 . V_141 [ V_64 ] = V_2 -> V_16 . V_17 -> V_141 [ V_64 ] ;
for ( V_64 = 0 ; V_64 < 8 ; V_64 ++ ) {
V_184 -> V_187 . V_188 . V_195 . V_196 [ V_64 ] = V_186 -> V_196 [ V_64 ] . V_197 ;
V_184 -> V_187 . V_188 . V_195 . V_198 [ V_64 ] = V_186 -> V_198 [ V_64 ] . V_197 ;
}
}
return 0 ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_183 * V_184 )
{
struct V_185 * V_186 = F_4 ( V_2 ) ;
int V_64 ;
F_18 ( V_2 , V_184 -> V_47 ) ;
V_186 -> V_189 = V_184 -> V_187 . V_188 . V_189 ;
if ( V_2 -> V_16 . V_49 & V_50 ) {
for ( V_64 = 0 ; V_64 < 64 ; V_64 ++ ) {
V_2 -> V_16 . V_53 . V_199 ( V_2 , V_184 -> V_187 . V_188 . V_190 . V_4 [ V_64 ] . V_193 ,
V_184 -> V_187 . V_188 . V_190 . V_4 [ V_64 ] . V_191 ) ;
}
} else {
for ( V_64 = 0 ; V_64 < 16 ; V_64 ++ ) {
V_2 -> V_16 . V_53 . V_200 ( V_2 , V_64 , V_184 -> V_187 . V_188 . V_195 . V_141 [ V_64 ] ) ;
}
for ( V_64 = 0 ; V_64 < 8 ; V_64 ++ ) {
F_73 ( V_2 , & ( V_186 -> V_196 [ V_64 ] ) , false ,
( T_3 ) V_184 -> V_187 . V_188 . V_195 . V_196 [ V_64 ] ) ;
F_73 ( V_2 , & ( V_186 -> V_196 [ V_64 ] ) , true ,
( T_3 ) ( V_184 -> V_187 . V_188 . V_195 . V_196 [ V_64 ] >> 32 ) ) ;
F_73 ( V_2 , & ( V_186 -> V_198 [ V_64 ] ) , false ,
( T_3 ) V_184 -> V_187 . V_188 . V_195 . V_198 [ V_64 ] ) ;
F_73 ( V_2 , & ( V_186 -> V_198 [ V_64 ] ) , true ,
( T_3 ) ( V_184 -> V_187 . V_188 . V_195 . V_198 [ V_64 ] >> 32 ) ) ;
}
}
F_60 ( V_2 , 0 , 0 ) ;
return 0 ;
}
int F_74 ( void )
{
return 0 ;
}
struct V_1 * F_75 ( struct V_65 * V_65 , unsigned int V_201 )
{
struct V_185 * V_202 ;
struct V_1 * V_2 ;
int V_203 = - V_204 ;
unsigned long V_205 ;
V_202 = F_76 ( sizeof( struct V_185 ) ) ;
if ( ! V_202 )
goto V_206;
V_202 -> V_6 = (struct V_207 * )
F_77 ( sizeof( * V_202 -> V_6 ) , V_208 ) ;
if ( ! V_202 -> V_6 )
goto V_209;
V_2 = & V_202 -> V_2 ;
V_203 = F_78 ( V_2 , V_65 , V_201 ) ;
if ( V_203 )
goto V_210;
V_205 = F_79 ( V_208 | V_211 ) ;
V_2 -> V_16 . V_17 = ( void * ) ( V_205 + V_212 - 4096 ) ;
if ( ! V_205 )
goto V_213;
V_2 -> V_16 . V_214 = V_215 ;
V_2 -> V_16 . V_216 = F_21 () ;
#ifdef F_2
V_2 -> V_16 . V_47 = 0x3C0301 ;
#else
V_2 -> V_16 . V_47 = 0x84202 ;
#endif
F_18 ( V_2 , V_2 -> V_16 . V_47 ) ;
V_2 -> V_16 . V_217 = 64 ;
V_2 -> V_16 . V_218 = F_80 ( V_219 ) ;
V_2 -> V_16 . V_220 = F_80 ( V_221 ) ;
V_2 -> V_16 . V_222 = ( T_1 ) V_223 ;
#ifdef F_2
V_2 -> V_16 . V_224 = * ( T_1 * ) V_225 ;
#else
V_2 -> V_16 . V_224 = ( T_1 ) V_225 ;
#endif
V_2 -> V_16 . V_34 = V_226 ;
V_203 = F_81 ( V_2 ) ;
if ( V_203 < 0 )
goto V_213;
return V_2 ;
V_213:
F_82 ( V_2 ) ;
V_210:
F_83 ( V_202 -> V_6 ) ;
V_209:
F_84 ( V_202 ) ;
V_206:
return F_85 ( V_203 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
struct V_185 * V_202 = F_4 ( V_2 ) ;
F_87 ( ( unsigned long ) V_2 -> V_16 . V_17 & V_68 ) ;
F_82 ( V_2 ) ;
F_83 ( V_202 -> V_6 ) ;
F_84 ( V_202 ) ;
}
int F_88 ( struct V_75 * V_75 , struct V_1 * V_2 )
{
int V_127 ;
double V_116 [ 32 ] [ V_227 ] ;
unsigned int V_120 ;
int V_134 ;
#ifdef F_45
T_5 V_122 [ 32 ] ;
T_5 V_123 ;
unsigned long V_228 ( V_135 ) ;
int V_229 ;
#endif
#ifdef F_41
int V_230 ;
#endif
T_1 V_175 ;
if ( F_68 ( V_9 ) ) {
V_75 -> V_137 = V_181 ;
return - V_182 ;
}
if ( V_9 -> V_10 . V_124 -> V_18 & V_12 )
F_43 ( V_9 ) ;
memcpy ( V_116 , V_9 -> V_10 . V_116 , sizeof( V_9 -> V_10 . V_116 ) ) ;
V_120 = V_9 -> V_10 . V_120 . V_121 ;
V_134 = V_9 -> V_10 . V_134 ;
#ifdef F_45
V_229 = V_9 -> V_10 . V_229 ;
if ( V_229 ) {
if ( V_9 -> V_10 . V_124 -> V_18 & V_13 )
F_46 ( V_9 ) ;
memcpy ( V_122 , V_9 -> V_10 . V_122 , sizeof( V_9 -> V_10 . V_122 ) ) ;
V_123 = V_9 -> V_10 . V_123 ;
V_135 = V_9 -> V_10 . V_135 ;
}
#endif
#ifdef F_41
V_230 = V_9 -> V_10 . V_230 ;
if ( V_230 && ( V_9 -> V_10 . V_124 -> V_18 & V_14 ) )
F_47 ( V_9 ) ;
#endif
V_175 = V_9 -> V_10 . V_124 -> V_18 ;
if ( V_2 -> V_16 . V_17 -> V_18 & V_12 )
F_17 ( V_2 , V_46 , V_12 ) ;
F_89 () ;
V_127 = F_90 ( V_75 , V_2 ) ;
F_91 () ;
F_92 () ;
V_9 -> V_10 . V_124 -> V_18 = V_175 ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , V_13 ) ;
F_8 ( V_2 , V_14 ) ;
memcpy ( V_9 -> V_10 . V_116 , V_116 , sizeof( V_9 -> V_10 . V_116 ) ) ;
V_9 -> V_10 . V_120 . V_121 = V_120 ;
V_9 -> V_10 . V_134 = V_134 ;
#ifdef F_45
if ( V_229 && V_9 -> V_10 . V_229 ) {
memcpy ( V_9 -> V_10 . V_122 , V_122 , sizeof( V_9 -> V_10 . V_122 ) ) ;
V_9 -> V_10 . V_123 = V_123 ;
V_9 -> V_10 . V_135 = V_135 ;
}
V_9 -> V_10 . V_229 = V_229 ;
#endif
#ifdef F_41
V_9 -> V_10 . V_230 = V_230 ;
#endif
return V_127 ;
}
int F_93 ( struct V_65 * V_65 ,
struct V_231 * V_232 )
{
return 0 ;
}
void F_94 ( struct V_65 * V_65 ,
struct V_231 * V_232 )
{
}
int F_95 ( struct V_65 * V_65 )
{
return 0 ;
}
void F_96 ( struct V_65 * V_65 )
{
}
static int F_97 ( void )
{
int V_81 ;
V_81 = F_98 ( NULL , sizeof( struct V_185 ) , 0 ,
V_233 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_99 () ;
return V_81 ;
}
static void F_100 ( void )
{
F_101 () ;
F_102 () ;
}
