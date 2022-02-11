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
V_2 -> V_3 = F_7 () ;
#ifdef F_8
V_11 -> V_12 . V_13 = F_4 ( V_2 ) -> V_8 ;
#endif
}
void F_9 ( struct V_1 * V_2 )
{
#ifdef F_2
struct V_4 * V_5 = F_3 ( V_2 ) ;
memcpy ( F_4 ( V_2 ) -> V_7 , V_5 -> V_6 , sizeof( V_5 -> V_6 ) ) ;
memcpy ( F_4 ( V_2 ) -> V_8 , & F_5 () -> V_8 ,
sizeof( F_5 () -> V_8 ) ) ;
F_4 ( V_2 ) -> V_10 = V_5 -> V_9 ;
F_6 ( V_5 ) ;
#endif
F_10 ( V_2 , V_14 | V_15 | V_16 ) ;
V_2 -> V_3 = - 1 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_17 = 1 ;
if ( F_12 ( V_18 , V_2 ) )
F_13 ( V_2 , 0 , 0 ) ;
return V_17 ;
}
int F_14 ( struct V_19 * V_19 , unsigned long V_20 )
{
F_15 ( V_20 ) ;
F_16 ( V_19 ) ;
return 0 ;
}
int F_17 ( struct V_19 * V_19 , unsigned long V_21 , unsigned long V_22 )
{
F_14 ( V_19 , V_21 ) ;
return 0 ;
}
int F_18 ( struct V_19 * V_19 , unsigned long V_20 )
{
return 0 ;
}
int F_19 ( struct V_19 * V_19 , unsigned long V_20 )
{
return 0 ;
}
void F_20 ( struct V_19 * V_19 , unsigned long V_20 , T_1 V_23 )
{
F_14 ( V_19 , V_20 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_2 V_24 = V_2 -> V_25 . V_26 -> V_27 ;
V_24 &= V_28 | V_29 | V_30 | V_31 | V_32 ;
V_24 |= V_33 | V_34 | V_35 | V_36 | V_37 | V_38 ;
V_24 |= ( V_2 -> V_25 . V_26 -> V_27 & V_2 -> V_25 . V_39 ) ;
#ifdef F_2
V_24 |= V_40 | V_41 ;
#endif
V_2 -> V_25 . V_42 = V_24 ;
}
void F_22 ( struct V_1 * V_2 , T_3 V_27 )
{
T_2 V_43 = V_2 -> V_25 . V_26 -> V_27 ;
#ifdef F_23
F_24 ( V_44 L_1 , V_27 ) ;
#endif
V_27 &= F_4 ( V_2 ) -> V_45 ;
V_2 -> V_25 . V_26 -> V_27 = V_27 ;
F_21 ( V_2 ) ;
if ( V_27 & V_46 ) {
if ( ! V_2 -> V_25 . V_47 ) {
F_25 ( V_2 ) ;
F_26 ( V_48 , & V_2 -> V_49 ) ;
V_2 -> V_50 . V_51 ++ ;
V_27 &= ~ V_46 ;
V_2 -> V_25 . V_26 -> V_27 = V_27 ;
}
}
if ( ( V_2 -> V_25 . V_26 -> V_27 & ( V_37 | V_35 | V_36 ) ) !=
( V_43 & ( V_37 | V_35 | V_36 ) ) ) {
F_27 ( V_2 ) ;
F_28 ( V_2 , F_29 ( V_2 ) ) ;
if ( ! ( V_27 & V_37 ) && V_2 -> V_25 . V_52 ) {
struct V_53 * V_54 = & V_2 -> V_25 ;
if ( V_27 & V_36 )
F_28 ( V_2 , V_54 -> V_55 ) ;
else
F_28 ( V_2 , V_54 -> V_52 ) ;
}
}
if ( V_2 -> V_25 . V_52 &&
! ( V_43 & V_37 ) && ! ( V_43 & V_30 ) && ( V_27 & V_30 ) ) {
F_13 ( V_2 , ( V_56 ) V_2 -> V_25 . V_52 ,
~ 0xFFFUL ) ;
}
if ( V_2 -> V_25 . V_26 -> V_27 & V_14 )
F_30 ( V_2 , V_57 , V_14 ) ;
}
void F_31 ( struct V_1 * V_2 , T_4 V_58 )
{
T_4 V_59 ;
V_2 -> V_25 . V_60 &= ~ V_61 ;
V_2 -> V_25 . V_58 = V_58 ;
#ifdef F_2
if ( ( V_58 >= 0x330000 ) && ( V_58 < 0x70330000 ) ) {
F_32 ( V_2 ) ;
if ( ! F_4 ( V_2 ) -> V_62 )
F_4 ( V_2 ) -> V_63 = 0xfff00000 ;
F_4 ( V_2 ) -> V_45 = 0xffffffffffffffffULL ;
V_2 -> V_25 . V_64 = V_65 ;
} else
#endif
{
F_33 ( V_2 ) ;
if ( ! F_4 ( V_2 ) -> V_62 )
F_4 ( V_2 ) -> V_63 = 0 ;
F_4 ( V_2 ) -> V_45 = 0xffffffffULL ;
V_2 -> V_25 . V_64 = V_66 ;
}
F_34 ( V_2 ) ;
V_2 -> V_25 . V_60 &= ~ V_67 ;
if ( V_2 -> V_25 . V_68 . V_69 ( V_2 ) && ( F_35 () & V_41 ) &&
! strcmp ( V_70 -> V_71 , L_2 ) )
V_2 -> V_25 . V_60 |= V_67 ;
if ( ! strcmp ( V_70 -> V_71 , L_3 ) )
F_4 ( V_2 ) -> V_45 &= ~ ( V_28 | V_29 ) ;
#ifdef F_8
V_2 -> V_25 . V_60 |= V_67 ;
#endif
asm ( "mfpvr %0" : "=r"(host_pvr));
switch ( V_59 ) {
case 0x00080200 :
case 0x00088202 :
case 0x70000100 :
case 0x00080100 :
case 0x00083203 :
case 0x00083213 :
case 0x00083204 :
case 0x00083214 :
case 0x00087200 :
V_2 -> V_25 . V_60 |= V_72 ;
F_36 ( V_73 , F_37 ( V_73 ) | ( 1 << 29 ) ) ;
}
}
static void F_38 ( struct V_1 * V_2 , struct V_74 * V_23 )
{
struct V_75 * V_76 ;
T_3 V_77 ;
T_4 * V_75 ;
int V_78 ;
V_76 = F_39 ( V_2 -> V_19 , V_23 -> V_79 >> V_80 ) ;
if ( F_40 ( V_76 ) )
return;
V_77 = V_23 -> V_79 & ~ V_81 ;
V_77 &= ~ 0xFFFULL ;
V_77 /= 4 ;
F_41 ( V_76 ) ;
V_75 = F_42 ( V_76 ) ;
for ( V_78 = V_77 ; V_78 < V_77 + ( V_82 / 4 ) ; V_78 ++ )
if ( ( V_75 [ V_78 ] & 0xff0007ff ) == V_83 )
V_75 [ V_78 ] &= 0xfffffff7 ;
F_43 ( V_75 ) ;
F_44 ( V_76 ) ;
}
static int F_45 ( struct V_1 * V_2 , T_5 V_84 )
{
T_2 V_85 = V_2 -> V_25 . V_52 ;
if ( ! ( V_2 -> V_25 . V_26 -> V_27 & V_30 ) )
V_85 = ( V_56 ) V_85 ;
if ( F_46 ( V_85 ) &&
F_46 ( ( V_85 & V_86 ) >> V_80 == V_84 ) ) {
return 1 ;
}
return F_47 ( V_2 -> V_19 , V_84 ) ;
}
int F_48 ( struct V_87 * V_88 , struct V_1 * V_2 ,
T_2 V_89 , int V_90 )
{
bool V_91 = ( V_90 == V_92 ) ;
int V_17 = V_93 ;
int V_94 ;
int V_95 = 0 ;
struct V_74 V_23 ;
bool V_96 = false ;
bool V_97 = ( V_2 -> V_25 . V_26 -> V_27 & V_36 ) ? true : false ;
bool V_98 = ( V_2 -> V_25 . V_26 -> V_27 & V_35 ) ? true : false ;
T_3 V_99 ;
V_94 = V_91 ? V_97 : V_98 ;
if ( V_94 ) {
V_95 = V_2 -> V_25 . V_68 . V_100 ( V_2 , V_89 , & V_23 , V_91 ) ;
} else {
V_23 . V_101 = true ;
V_23 . V_102 = true ;
V_23 . V_103 = true ;
V_23 . V_79 = V_89 & V_86 ;
V_23 . V_89 = V_89 ;
V_23 . V_104 = V_89 >> 12 ;
}
switch ( V_2 -> V_25 . V_26 -> V_27 & ( V_36 | V_35 ) ) {
case 0 :
V_23 . V_104 |= ( ( T_3 ) V_105 << ( V_106 - 12 ) ) ;
break;
case V_36 :
case V_35 :
V_2 -> V_25 . V_68 . V_107 ( V_2 , V_89 >> V_106 , & V_99 ) ;
if ( ( V_2 -> V_25 . V_26 -> V_27 & ( V_36 | V_35 ) ) == V_36 )
V_23 . V_104 |= ( ( T_3 ) V_108 << ( V_106 - 12 ) ) ;
else
V_23 . V_104 |= ( ( T_3 ) V_109 << ( V_106 - 12 ) ) ;
V_23 . V_104 |= V_99 ;
if ( V_99 == - 1 )
V_95 = - V_110 ;
break;
}
if ( V_2 -> V_25 . V_68 . V_69 ( V_2 ) &&
( ! ( V_2 -> V_25 . V_60 & V_67 ) ) ) {
V_23 . V_101 = ! V_91 ;
}
if ( V_95 == - V_111 ) {
struct V_4 * V_5 = F_3 ( V_2 ) ;
V_2 -> V_25 . V_26 -> V_112 = F_49 ( V_2 ) ;
V_2 -> V_25 . V_26 -> V_113 = V_5 -> V_114 ;
V_2 -> V_25 . V_26 -> V_27 |=
( V_5 -> V_115 & 0x00000000f8000000ULL ) ;
F_6 ( V_5 ) ;
F_50 ( V_2 , V_90 ) ;
} else if ( V_95 == - V_116 ) {
struct V_4 * V_5 = F_3 ( V_2 ) ;
V_2 -> V_25 . V_26 -> V_112 = F_49 ( V_2 ) ;
V_2 -> V_25 . V_26 -> V_113 = V_5 -> V_114 & ~ V_117 ;
V_2 -> V_25 . V_26 -> V_113 |= V_118 ;
V_2 -> V_25 . V_26 -> V_27 |=
V_5 -> V_115 & 0x00000000f8000000ULL ;
F_6 ( V_5 ) ;
F_50 ( V_2 , V_90 ) ;
} else if ( V_95 == - V_110 ) {
V_2 -> V_25 . V_26 -> V_112 = F_49 ( V_2 ) ;
F_50 ( V_2 , V_90 + 0x80 ) ;
} else if ( ! V_96 &&
F_45 ( V_2 , V_23 . V_79 >> V_80 ) ) {
F_51 ( V_2 , & V_23 ) ;
if ( V_91 )
V_2 -> V_50 . V_119 ++ ;
else if ( V_2 -> V_25 . V_68 . V_69 ( V_2 ) &&
( ! ( V_2 -> V_25 . V_60 & V_67 ) ) )
F_38 ( V_2 , & V_23 ) ;
} else {
V_2 -> V_50 . V_120 ++ ;
V_2 -> V_25 . V_121 = V_23 . V_79 ;
V_2 -> V_25 . V_122 = V_23 . V_89 ;
V_17 = F_52 ( V_88 , V_2 ) ;
if ( V_17 == V_123 )
V_17 = V_124 ;
}
return V_17 ;
}
static inline int F_53 ( int V_78 )
{
return V_78 * V_125 ;
}
void F_10 ( struct V_1 * V_2 , T_2 V_27 )
{
struct V_126 * V_127 = & V_11 -> V_12 ;
T_3 * V_128 = V_2 -> V_25 . V_129 ;
#ifdef F_54
T_3 * V_130 = V_2 -> V_25 . V_131 ;
#endif
T_3 * V_132 = ( T_3 * ) V_127 -> V_129 ;
int V_78 ;
if ( V_27 & V_16 )
V_27 |= V_14 | V_15 ;
V_27 &= V_2 -> V_25 . V_39 ;
if ( ! V_27 )
return;
#ifdef F_55
F_24 ( V_44 L_4 , V_27 ) ;
#endif
if ( V_27 & V_14 ) {
if ( V_11 -> V_12 . V_133 -> V_27 & V_14 )
F_56 ( V_11 ) ;
for ( V_78 = 0 ; V_78 < F_57 ( V_2 -> V_25 . V_129 ) ; V_78 ++ )
V_128 [ V_78 ] = V_132 [ F_53 ( V_78 ) ] ;
V_2 -> V_25 . V_134 = V_127 -> V_134 . V_135 ;
#ifdef F_54
if ( F_58 ( V_136 ) )
for ( V_78 = 0 ; V_78 < F_57 ( V_2 -> V_25 . V_131 ) / 2 ; V_78 ++ )
V_130 [ V_78 ] = V_132 [ F_53 ( V_78 ) + 1 ] ;
#endif
}
#ifdef F_59
if ( V_27 & V_15 ) {
if ( V_11 -> V_12 . V_133 -> V_27 & V_15 )
F_60 ( V_11 ) ;
memcpy ( V_2 -> V_25 . V_137 , V_127 -> V_137 , sizeof( V_2 -> V_25 . V_137 ) ) ;
V_2 -> V_25 . V_138 = V_127 -> V_138 ;
}
#endif
V_2 -> V_25 . V_39 &= ~ ( V_27 | V_16 ) ;
F_21 ( V_2 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
T_2 V_139 = F_29 ( V_2 ) ;
T_4 V_140 = F_62 ( V_2 ) ;
int V_141 ;
V_141 = F_63 ( V_2 , & V_139 , sizeof( T_4 ) , & V_140 , false ) ;
if ( V_141 == - V_111 ) {
T_2 V_27 = V_2 -> V_25 . V_26 -> V_27 ;
V_27 = F_64 ( V_27 , 33 , 33 , 1 ) ;
V_27 = F_64 ( V_27 , 34 , 36 , 0 ) ;
V_2 -> V_25 . V_26 -> V_27 = F_64 ( V_27 , 42 , 47 , 0 ) ;
F_50 ( V_2 , V_142 ) ;
return V_143 ;
}
return V_144 ;
}
static int F_65 ( struct V_1 * V_2 , unsigned int V_145 )
{
if ( ! ( V_2 -> V_25 . V_60 & V_146 ) )
return V_144 ;
if ( F_61 ( V_2 ) == V_144 )
return V_147 ;
return V_143 ;
}
static int F_30 ( struct V_1 * V_2 , unsigned int V_145 ,
T_2 V_27 )
{
struct V_126 * V_127 = & V_11 -> V_12 ;
T_3 * V_128 = V_2 -> V_25 . V_129 ;
#ifdef F_54
T_3 * V_130 = V_2 -> V_25 . V_131 ;
#endif
T_3 * V_132 = ( T_3 * ) V_127 -> V_129 ;
int V_78 ;
if ( V_2 -> V_25 . V_60 & V_146 )
return V_93 ;
if ( ! ( V_2 -> V_25 . V_26 -> V_27 & V_27 ) ) {
F_50 ( V_2 , V_145 ) ;
return V_93 ;
}
if ( V_27 == V_16 ) {
#ifdef F_54
if ( ! F_58 ( V_136 ) )
#endif
{
F_66 ( V_2 , V_148 ) ;
return V_93 ;
}
V_27 = V_14 | V_15 | V_16 ;
}
V_27 &= ~ V_2 -> V_25 . V_39 ;
if ( ! V_27 )
return V_93 ;
#ifdef F_55
F_24 ( V_44 L_5 , V_27 ) ;
#endif
if ( V_27 & V_14 ) {
for ( V_78 = 0 ; V_78 < F_57 ( V_2 -> V_25 . V_129 ) ; V_78 ++ )
V_132 [ F_53 ( V_78 ) ] = V_128 [ V_78 ] ;
#ifdef F_54
for ( V_78 = 0 ; V_78 < F_57 ( V_2 -> V_25 . V_131 ) / 2 ; V_78 ++ )
V_132 [ F_53 ( V_78 ) + 1 ] = V_130 [ V_78 ] ;
#endif
V_127 -> V_134 . V_135 = V_2 -> V_25 . V_134 ;
V_127 -> V_149 = 0 ;
F_67 () ;
}
if ( V_27 & V_15 ) {
#ifdef F_59
memcpy ( V_127 -> V_137 , V_2 -> V_25 . V_137 , sizeof( V_2 -> V_25 . V_137 ) ) ;
V_127 -> V_138 = V_2 -> V_25 . V_138 ;
V_127 -> V_150 = - 1 ;
F_68 () ;
#endif
}
V_11 -> V_12 . V_133 -> V_27 |= V_27 ;
V_2 -> V_25 . V_39 |= V_27 ;
F_21 ( V_2 ) ;
return V_93 ;
}
static void F_69 ( struct V_1 * V_2 )
{
unsigned long V_151 ;
V_151 = V_2 -> V_25 . V_39 & ~ V_11 -> V_12 . V_133 -> V_27 ;
if ( ! V_151 )
return;
if ( V_151 & V_14 )
F_67 () ;
if ( V_151 & V_15 )
F_68 () ;
V_11 -> V_12 . V_133 -> V_27 |= V_151 ;
}
int F_70 ( struct V_87 * V_88 , struct V_1 * V_2 ,
unsigned int V_145 )
{
int V_17 = V_124 ;
int V_152 ;
V_2 -> V_50 . V_153 ++ ;
V_88 -> V_154 = V_155 ;
V_88 -> V_156 = 1 ;
F_71 ( V_145 , V_2 ) ;
F_72 () ;
switch ( V_145 ) {
case V_142 :
{
struct V_4 * V_5 = F_3 ( V_2 ) ;
T_2 V_115 = V_5 -> V_115 ;
V_2 -> V_50 . V_157 ++ ;
#ifdef F_8
if ( V_5 -> V_158 [ F_29 ( V_2 ) >> V_106 ] == V_159 ) {
F_28 ( V_2 , F_29 ( V_2 ) ) ;
V_17 = V_93 ;
F_6 ( V_5 ) ;
break;
}
#endif
F_6 ( V_5 ) ;
if ( V_115 & 0x40000000 ) {
V_17 = F_48 ( V_88 , V_2 , F_29 ( V_2 ) , V_145 ) ;
V_2 -> V_50 . V_160 ++ ;
} else if ( V_2 -> V_25 . V_68 . V_69 ( V_2 ) &&
( ! ( V_2 -> V_25 . V_60 & V_67 ) ) ) {
F_13 ( V_2 , F_29 ( V_2 ) , ~ 0xFFFUL ) ;
V_17 = V_93 ;
} else {
V_2 -> V_25 . V_26 -> V_27 |= V_115 & 0x58000000 ;
F_50 ( V_2 , V_145 ) ;
V_17 = V_93 ;
}
break;
}
case V_92 :
{
T_2 V_112 = F_49 ( V_2 ) ;
struct V_4 * V_5 = F_3 ( V_2 ) ;
T_4 V_114 = V_5 -> V_114 ;
V_2 -> V_50 . V_161 ++ ;
#ifdef F_8
if ( ( V_5 -> V_158 [ V_112 >> V_106 ] ) == V_159 ) {
F_28 ( V_2 , V_112 ) ;
V_17 = V_93 ;
F_6 ( V_5 ) ;
break;
}
#endif
F_6 ( V_5 ) ;
if ( V_114 & V_117 ) {
V_17 = F_48 ( V_88 , V_2 , V_112 , V_145 ) ;
} else {
V_2 -> V_25 . V_26 -> V_112 = V_112 ;
V_2 -> V_25 . V_26 -> V_113 = V_114 ;
F_50 ( V_2 , V_145 ) ;
V_17 = V_93 ;
}
break;
}
case V_162 :
if ( F_28 ( V_2 , F_49 ( V_2 ) ) < 0 ) {
V_2 -> V_25 . V_26 -> V_112 = F_49 ( V_2 ) ;
F_50 ( V_2 ,
V_162 ) ;
}
V_17 = V_93 ;
break;
case V_163 :
if ( F_28 ( V_2 , F_29 ( V_2 ) ) < 0 ) {
F_50 ( V_2 ,
V_163 ) ;
}
V_17 = V_93 ;
break;
case V_164 :
case V_165 :
V_2 -> V_50 . V_166 ++ ;
V_17 = V_93 ;
break;
case V_167 :
case V_168 :
case V_169 :
V_2 -> V_50 . V_170 ++ ;
V_17 = V_93 ;
break;
case V_171 :
V_17 = V_93 ;
break;
case V_172 :
case V_173 :
{
enum V_174 V_175 ;
struct V_4 * V_5 ;
T_2 V_176 ;
V_177:
V_5 = F_3 ( V_2 ) ;
V_176 = V_5 -> V_115 & 0x1f0000ull ;
F_6 ( V_5 ) ;
if ( V_2 -> V_25 . V_26 -> V_27 & V_37 ) {
#ifdef F_23
F_24 ( V_44 L_6 , F_29 ( V_2 ) , F_62 ( V_2 ) ) ;
#endif
if ( ( F_62 ( V_2 ) & 0xff0007ff ) !=
( V_83 & 0xfffffff7 ) ) {
F_66 ( V_2 , V_176 ) ;
V_17 = V_93 ;
break;
}
}
V_2 -> V_50 . V_178 ++ ;
V_175 = F_73 ( V_88 , V_2 ) ;
switch ( V_175 ) {
case V_144 :
V_17 = V_179 ;
break;
case V_143 :
V_17 = V_93 ;
break;
case V_147 :
F_24 ( V_180 L_7 ,
V_181 , F_29 ( V_2 ) , F_62 ( V_2 ) ) ;
F_66 ( V_2 , V_176 ) ;
V_17 = V_93 ;
break;
case V_182 :
V_88 -> V_154 = V_183 ;
V_17 = V_123 ;
break;
case V_184 :
V_17 = V_123 ;
break;
default:
F_74 () ;
}
break;
}
case V_185 :
if ( V_2 -> V_25 . V_186 &&
( F_75 ( V_2 ) == 0x44000022 ) &&
! ( V_2 -> V_25 . V_26 -> V_27 & V_37 ) ) {
T_2 V_187 = F_76 ( V_2 , 3 ) ;
int V_78 ;
#ifdef F_77
if ( F_78 ( V_2 , V_187 ) == V_144 ) {
V_17 = V_93 ;
break;
}
#endif
V_88 -> V_188 . V_189 = V_187 ;
for ( V_78 = 0 ; V_78 < 9 ; ++ V_78 ) {
T_2 V_190 = F_76 ( V_2 , 4 + V_78 ) ;
V_88 -> V_188 . args [ V_78 ] = V_190 ;
}
V_88 -> V_154 = V_191 ;
V_2 -> V_25 . V_192 = 1 ;
V_17 = V_124 ;
} else if ( V_2 -> V_25 . V_193 &&
( ( ( T_4 ) F_76 ( V_2 , 3 ) ) == V_194 ) &&
( ( ( T_4 ) F_76 ( V_2 , 4 ) ) == V_195 ) ) {
T_3 * V_196 = V_88 -> V_197 . V_196 ;
int V_78 ;
V_88 -> V_154 = V_198 ;
for ( V_78 = 0 ; V_78 < 32 ; V_78 ++ )
V_196 [ V_78 ] = F_76 ( V_2 , V_78 ) ;
V_2 -> V_25 . V_199 = 1 ;
V_17 = V_123 ;
} else if ( ! ( V_2 -> V_25 . V_26 -> V_27 & V_37 ) &&
( ( ( T_4 ) F_76 ( V_2 , 0 ) ) == V_200 ) ) {
F_79 ( V_2 , 3 , F_80 ( V_2 ) ) ;
V_17 = V_93 ;
} else {
V_2 -> V_50 . V_201 ++ ;
F_50 ( V_2 , V_145 ) ;
V_17 = V_93 ;
}
break;
case V_57 :
case V_202 :
case V_203 :
{
int V_204 = 0 ;
switch ( V_145 ) {
case V_57 : V_204 = V_14 ; break;
case V_202 : V_204 = V_15 ; break;
case V_203 : V_204 = V_16 ; break;
}
switch ( F_65 ( V_2 , V_145 ) ) {
case V_144 :
V_17 = F_30 ( V_2 , V_145 , V_204 ) ;
break;
case V_147 :
goto V_177;
break;
default:
break;
}
break;
}
case V_205 :
if ( F_61 ( V_2 ) == V_144 ) {
V_2 -> V_25 . V_26 -> V_113 = F_81 ( V_2 ,
F_62 ( V_2 ) ) ;
V_2 -> V_25 . V_26 -> V_112 = F_82 ( V_2 ,
F_62 ( V_2 ) ) ;
F_50 ( V_2 , V_145 ) ;
}
V_17 = V_93 ;
break;
case V_206 :
case V_207 :
F_50 ( V_2 , V_145 ) ;
V_17 = V_93 ;
break;
default:
{
struct V_4 * V_5 = F_3 ( V_2 ) ;
T_2 V_115 = V_5 -> V_115 ;
F_6 ( V_5 ) ;
F_24 ( V_208 L_8 ,
V_145 , F_29 ( V_2 ) , V_115 ) ;
V_17 = V_124 ;
F_74 () ;
break;
}
}
if ( ! ( V_17 & V_124 ) ) {
F_83 () ;
V_152 = F_84 ( V_2 ) ;
if ( V_152 <= 0 ) {
F_85 () ;
V_17 = V_152 ;
} else {
F_86 () ;
}
F_69 ( V_2 ) ;
}
F_87 ( V_17 , V_2 ) ;
return V_17 ;
}
int F_88 ( struct V_1 * V_2 ,
struct V_209 * V_210 )
{
struct V_211 * V_212 = F_4 ( V_2 ) ;
int V_78 ;
V_210 -> V_58 = V_2 -> V_25 . V_58 ;
V_210 -> V_213 . V_152 . V_214 = F_4 ( V_2 ) -> V_214 ;
if ( V_2 -> V_25 . V_60 & V_61 ) {
for ( V_78 = 0 ; V_78 < 64 ; V_78 ++ ) {
V_210 -> V_213 . V_152 . V_215 . V_6 [ V_78 ] . V_216 = V_2 -> V_25 . V_6 [ V_78 ] . V_217 | V_78 ;
V_210 -> V_213 . V_152 . V_215 . V_6 [ V_78 ] . V_218 = V_2 -> V_25 . V_6 [ V_78 ] . V_219 ;
}
} else {
for ( V_78 = 0 ; V_78 < 16 ; V_78 ++ )
V_210 -> V_213 . V_152 . V_220 . V_158 [ V_78 ] = V_2 -> V_25 . V_26 -> V_158 [ V_78 ] ;
for ( V_78 = 0 ; V_78 < 8 ; V_78 ++ ) {
V_210 -> V_213 . V_152 . V_220 . V_221 [ V_78 ] = V_212 -> V_221 [ V_78 ] . V_222 ;
V_210 -> V_213 . V_152 . V_220 . V_223 [ V_78 ] = V_212 -> V_223 [ V_78 ] . V_222 ;
}
}
return 0 ;
}
int F_89 ( struct V_1 * V_2 ,
struct V_209 * V_210 )
{
struct V_211 * V_212 = F_4 ( V_2 ) ;
int V_78 ;
F_31 ( V_2 , V_210 -> V_58 ) ;
V_212 -> V_214 = V_210 -> V_213 . V_152 . V_214 ;
if ( V_2 -> V_25 . V_60 & V_61 ) {
for ( V_78 = 0 ; V_78 < 64 ; V_78 ++ ) {
V_2 -> V_25 . V_68 . V_224 ( V_2 , V_210 -> V_213 . V_152 . V_215 . V_6 [ V_78 ] . V_218 ,
V_210 -> V_213 . V_152 . V_215 . V_6 [ V_78 ] . V_216 ) ;
}
} else {
for ( V_78 = 0 ; V_78 < 16 ; V_78 ++ ) {
V_2 -> V_25 . V_68 . V_225 ( V_2 , V_78 , V_210 -> V_213 . V_152 . V_220 . V_158 [ V_78 ] ) ;
}
for ( V_78 = 0 ; V_78 < 8 ; V_78 ++ ) {
F_90 ( V_2 , & ( V_212 -> V_221 [ V_78 ] ) , false ,
( T_4 ) V_210 -> V_213 . V_152 . V_220 . V_221 [ V_78 ] ) ;
F_90 ( V_2 , & ( V_212 -> V_221 [ V_78 ] ) , true ,
( T_4 ) ( V_210 -> V_213 . V_152 . V_220 . V_221 [ V_78 ] >> 32 ) ) ;
F_90 ( V_2 , & ( V_212 -> V_223 [ V_78 ] ) , false ,
( T_4 ) V_210 -> V_213 . V_152 . V_220 . V_223 [ V_78 ] ) ;
F_90 ( V_2 , & ( V_212 -> V_223 [ V_78 ] ) , true ,
( T_4 ) ( V_210 -> V_213 . V_152 . V_220 . V_223 [ V_78 ] >> 32 ) ) ;
}
}
F_13 ( V_2 , 0 , 0 ) ;
return 0 ;
}
int F_91 ( struct V_1 * V_2 , T_3 V_226 , union V_227 * V_135 )
{
int V_17 = 0 ;
switch ( V_226 ) {
case V_228 :
* V_135 = F_92 ( V_226 , F_4 ( V_2 ) -> V_63 ) ;
break;
#ifdef F_54
case V_229 ... V_230 : {
long int V_78 = V_226 - V_229 ;
if ( ! F_58 ( V_136 ) ) {
V_17 = - V_231 ;
break;
}
V_135 -> V_232 [ 0 ] = V_2 -> V_25 . V_129 [ V_78 ] ;
V_135 -> V_232 [ 1 ] = V_2 -> V_25 . V_131 [ V_78 ] ;
break;
}
#endif
default:
V_17 = - V_110 ;
break;
}
return V_17 ;
}
int F_93 ( struct V_1 * V_2 , T_3 V_226 , union V_227 * V_135 )
{
int V_17 = 0 ;
switch ( V_226 ) {
case V_228 :
F_4 ( V_2 ) -> V_63 = F_94 ( V_226 , * V_135 ) ;
F_4 ( V_2 ) -> V_62 = true ;
break;
#ifdef F_54
case V_229 ... V_230 : {
long int V_78 = V_226 - V_229 ;
if ( ! F_58 ( V_136 ) ) {
V_17 = - V_231 ;
break;
}
V_2 -> V_25 . V_129 [ V_78 ] = V_135 -> V_232 [ 0 ] ;
V_2 -> V_25 . V_131 [ V_78 ] = V_135 -> V_232 [ 1 ] ;
break;
}
#endif
default:
V_17 = - V_110 ;
break;
}
return V_17 ;
}
int F_95 ( void )
{
return 0 ;
}
struct V_1 * F_96 ( struct V_19 * V_19 , unsigned int V_226 )
{
struct V_211 * V_233 ;
struct V_1 * V_2 ;
int V_234 = - V_235 ;
unsigned long V_236 ;
V_233 = F_97 ( sizeof( struct V_211 ) ) ;
if ( ! V_233 )
goto V_237;
V_233 -> V_8 =
F_98 ( sizeof( * V_233 -> V_8 ) , V_238 ) ;
if ( ! V_233 -> V_8 )
goto V_239;
V_2 = & V_233 -> V_2 ;
V_234 = F_99 ( V_2 , V_19 , V_226 ) ;
if ( V_234 )
goto V_240;
V_234 = - V_235 ;
V_236 = F_100 ( V_238 | V_241 ) ;
if ( ! V_236 )
goto V_242;
V_2 -> V_25 . V_26 = ( void * ) ( V_236 + V_243 - 4096 ) ;
#ifdef F_2
V_2 -> V_25 . V_58 = 0x3C0301 ;
#else
V_2 -> V_25 . V_58 = 0x84202 ;
#endif
F_31 ( V_2 , V_2 -> V_25 . V_58 ) ;
V_2 -> V_25 . V_244 = 64 ;
V_2 -> V_25 . V_42 = V_245 ;
V_234 = F_101 ( V_2 ) ;
if ( V_234 < 0 )
goto V_242;
return V_2 ;
V_242:
F_102 ( V_2 ) ;
V_240:
F_103 ( V_233 -> V_8 ) ;
V_239:
F_104 ( V_233 ) ;
V_237:
return F_105 ( V_234 ) ;
}
void F_106 ( struct V_1 * V_2 )
{
struct V_211 * V_233 = F_4 ( V_2 ) ;
F_107 ( ( unsigned long ) V_2 -> V_25 . V_26 & V_81 ) ;
F_102 ( V_2 ) ;
F_103 ( V_233 -> V_8 ) ;
F_104 ( V_233 ) ;
}
int F_108 ( struct V_87 * V_87 , struct V_1 * V_2 )
{
int V_141 ;
double V_129 [ 32 ] [ V_125 ] ;
unsigned int V_134 ;
int V_149 ;
#ifdef F_59
T_6 V_137 [ 32 ] ;
T_6 V_138 ;
unsigned long V_246 ( V_150 ) ;
int V_247 ;
#endif
#ifdef F_54
int V_248 ;
#endif
T_2 V_204 ;
if ( ! V_2 -> V_25 . V_249 ) {
V_87 -> V_154 = V_250 ;
V_141 = - V_110 ;
goto V_237;
}
F_83 () ;
V_141 = F_84 ( V_2 ) ;
if ( V_141 <= 0 ) {
F_85 () ;
goto V_237;
}
if ( V_11 -> V_12 . V_133 -> V_27 & V_14 )
F_56 ( V_11 ) ;
memcpy ( V_129 , V_11 -> V_12 . V_129 , sizeof( V_11 -> V_12 . V_129 ) ) ;
V_134 = V_11 -> V_12 . V_134 . V_135 ;
V_149 = V_11 -> V_12 . V_149 ;
#ifdef F_59
V_247 = V_11 -> V_12 . V_247 ;
if ( V_247 ) {
if ( V_11 -> V_12 . V_133 -> V_27 & V_15 )
F_60 ( V_11 ) ;
memcpy ( V_137 , V_11 -> V_12 . V_137 , sizeof( V_11 -> V_12 . V_137 ) ) ;
V_138 = V_11 -> V_12 . V_138 ;
V_150 = V_11 -> V_12 . V_150 ;
}
#endif
#ifdef F_54
V_248 = V_11 -> V_12 . V_248 ;
if ( V_248 && ( V_11 -> V_12 . V_133 -> V_27 & V_16 ) )
F_109 ( V_11 ) ;
#endif
V_204 = V_11 -> V_12 . V_133 -> V_27 ;
if ( V_2 -> V_25 . V_26 -> V_27 & V_14 )
F_30 ( V_2 , V_57 , V_14 ) ;
F_86 () ;
V_141 = F_110 ( V_87 , V_2 ) ;
F_10 ( V_2 , V_14 | V_15 | V_16 ) ;
V_11 -> V_12 . V_133 -> V_27 = V_204 ;
memcpy ( V_11 -> V_12 . V_129 , V_129 , sizeof( V_11 -> V_12 . V_129 ) ) ;
V_11 -> V_12 . V_134 . V_135 = V_134 ;
V_11 -> V_12 . V_149 = V_149 ;
#ifdef F_59
if ( V_247 && V_11 -> V_12 . V_247 ) {
memcpy ( V_11 -> V_12 . V_137 , V_137 , sizeof( V_11 -> V_12 . V_137 ) ) ;
V_11 -> V_12 . V_138 = V_138 ;
V_11 -> V_12 . V_150 = V_150 ;
}
V_11 -> V_12 . V_247 = V_247 ;
#endif
#ifdef F_54
V_11 -> V_12 . V_248 = V_248 ;
#endif
V_237:
V_2 -> V_251 = V_252 ;
return V_141 ;
}
int F_111 ( struct V_19 * V_19 ,
struct V_253 * log )
{
struct V_254 * V_255 ;
struct V_1 * V_2 ;
T_2 V_256 , V_257 ;
int V_258 = 0 ;
int V_17 ;
unsigned long V_259 ;
F_112 ( & V_19 -> V_260 ) ;
V_17 = F_113 ( V_19 , log , & V_258 ) ;
if ( V_17 )
goto V_237;
if ( V_258 ) {
V_255 = F_114 ( V_19 -> V_261 , log -> V_262 ) ;
V_256 = V_255 -> V_263 << V_80 ;
V_257 = V_256 + ( V_255 -> V_264 << V_80 ) ;
F_115 (n, vcpu, kvm)
F_116 ( V_2 , V_256 , V_257 ) ;
V_259 = F_117 ( V_255 ) ;
memset ( V_255 -> V_265 , 0 , V_259 ) ;
}
V_17 = 0 ;
V_237:
F_118 ( & V_19 -> V_260 ) ;
return V_17 ;
}
int F_119 ( struct V_19 * V_19 , struct V_266 * V_267 )
{
V_267 -> V_176 = V_268 ;
V_267 -> V_269 = 64 ;
V_267 -> V_270 [ 0 ] . V_271 = 12 ;
V_267 -> V_270 [ 0 ] . V_272 = 0 ;
V_267 -> V_270 [ 0 ] . V_273 [ 0 ] . V_271 = 12 ;
V_267 -> V_270 [ 0 ] . V_273 [ 0 ] . V_274 = 0 ;
V_267 -> V_270 [ 1 ] . V_271 = 24 ;
V_267 -> V_270 [ 1 ] . V_272 = V_275 ;
V_267 -> V_270 [ 1 ] . V_273 [ 0 ] . V_271 = 24 ;
V_267 -> V_270 [ 1 ] . V_273 [ 0 ] . V_274 = 0 ;
return 0 ;
}
void F_120 ( struct V_254 * free ,
struct V_254 * V_276 )
{
}
int F_121 ( struct V_254 * V_262 ,
unsigned long V_264 )
{
return 0 ;
}
int F_122 ( struct V_19 * V_19 ,
struct V_254 * V_255 ,
struct V_277 * V_278 )
{
return 0 ;
}
void F_123 ( struct V_19 * V_19 ,
struct V_277 * V_278 ,
const struct V_254 * V_279 )
{
}
void F_124 ( struct V_19 * V_19 , struct V_254 * V_255 )
{
}
int F_125 ( struct V_19 * V_19 )
{
#ifdef F_126
F_127 ( & V_19 -> V_25 . V_280 ) ;
F_127 ( & V_19 -> V_25 . V_281 ) ;
#endif
if ( F_128 ( V_282 ) ) {
F_129 ( & V_283 ) ;
if ( ++ V_284 == 1 )
F_130 () ;
F_131 ( & V_283 ) ;
}
return 0 ;
}
void F_132 ( struct V_19 * V_19 )
{
#ifdef F_126
F_133 ( ! F_134 ( & V_19 -> V_25 . V_280 ) ) ;
#endif
if ( F_128 ( V_282 ) ) {
F_129 ( & V_283 ) ;
F_135 ( V_284 == 0 ) ;
if ( -- V_284 == 0 )
F_136 () ;
F_131 ( & V_283 ) ;
}
}
static int F_137 ( void )
{
int V_17 ;
V_17 = F_138 ( NULL , sizeof( struct V_211 ) , 0 ,
V_285 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_139 () ;
return V_17 ;
}
static void F_140 ( void )
{
F_141 () ;
F_142 () ;
}
