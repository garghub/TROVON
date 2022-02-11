static bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 ) ;
return ( V_3 & ( V_4 | V_5 ) ) == V_5 ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 ) ;
T_1 V_6 = F_4 ( V_2 ) ;
if ( ( V_3 & ( V_4 | V_5 ) ) != V_5 )
return;
if ( V_2 -> V_7 . V_8 & V_9 )
return;
if ( V_6 & V_10 )
return;
V_2 -> V_7 . V_8 |= V_9 ;
F_5 ( V_2 , V_6 | V_11 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_12 )
{
#ifdef F_7
struct V_13 * V_14 = F_8 ( V_2 ) ;
memcpy ( V_14 -> V_15 , F_9 ( V_2 ) -> V_16 , sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_17 = F_9 ( V_2 ) -> V_18 ;
V_14 -> V_19 = 0 ;
F_10 ( V_14 ) ;
#endif
if ( F_11 ( V_20 ) &&
F_11 ( V_21 ) )
F_12 ( V_22 , F_13 ( V_22 ) & ~ V_23 ) ;
V_2 -> V_12 = F_14 () ;
#ifdef F_15
V_24 -> V_25 . V_26 = V_2 -> V_7 . V_27 ;
#endif
if ( F_1 ( V_2 ) )
F_3 ( V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
#ifdef F_7
struct V_13 * V_14 = F_8 ( V_2 ) ;
if ( V_14 -> V_19 ) {
F_17 ( V_2 , V_14 ) ;
}
memcpy ( F_9 ( V_2 ) -> V_16 , V_14 -> V_15 , sizeof( V_14 -> V_15 ) ) ;
F_9 ( V_2 ) -> V_18 = V_14 -> V_17 ;
F_10 ( V_14 ) ;
#endif
if ( F_1 ( V_2 ) )
F_18 ( V_2 ) ;
F_19 ( V_2 , V_28 | V_29 | V_30 ) ;
F_20 ( V_2 , V_31 ) ;
if ( F_11 ( V_20 ) &&
F_11 ( V_21 ) )
F_12 ( V_22 , F_13 ( V_22 ) | V_32 ) ;
V_2 -> V_12 = - 1 ;
}
void F_21 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
V_14 -> V_33 [ 0 ] = V_2 -> V_7 . V_33 [ 0 ] ;
V_14 -> V_33 [ 1 ] = V_2 -> V_7 . V_33 [ 1 ] ;
V_14 -> V_33 [ 2 ] = V_2 -> V_7 . V_33 [ 2 ] ;
V_14 -> V_33 [ 3 ] = V_2 -> V_7 . V_33 [ 3 ] ;
V_14 -> V_33 [ 4 ] = V_2 -> V_7 . V_33 [ 4 ] ;
V_14 -> V_33 [ 5 ] = V_2 -> V_7 . V_33 [ 5 ] ;
V_14 -> V_33 [ 6 ] = V_2 -> V_7 . V_33 [ 6 ] ;
V_14 -> V_33 [ 7 ] = V_2 -> V_7 . V_33 [ 7 ] ;
V_14 -> V_33 [ 8 ] = V_2 -> V_7 . V_33 [ 8 ] ;
V_14 -> V_33 [ 9 ] = V_2 -> V_7 . V_33 [ 9 ] ;
V_14 -> V_33 [ 10 ] = V_2 -> V_7 . V_33 [ 10 ] ;
V_14 -> V_33 [ 11 ] = V_2 -> V_7 . V_33 [ 11 ] ;
V_14 -> V_33 [ 12 ] = V_2 -> V_7 . V_33 [ 12 ] ;
V_14 -> V_33 [ 13 ] = V_2 -> V_7 . V_33 [ 13 ] ;
V_14 -> V_34 = V_2 -> V_7 . V_34 ;
V_14 -> V_35 = V_2 -> V_7 . V_35 ;
V_14 -> V_36 = V_2 -> V_7 . V_36 ;
V_14 -> V_37 = V_2 -> V_7 . V_37 ;
V_14 -> V_6 = V_2 -> V_7 . V_6 ;
#ifdef F_7
V_14 -> V_38 = V_2 -> V_7 . V_38 ;
#endif
V_2 -> V_7 . V_39 = F_22 () ;
V_2 -> V_7 . V_40 = F_23 () ;
if ( F_11 ( V_21 ) )
V_2 -> V_7 . V_41 = F_13 ( V_42 ) ;
V_14 -> V_19 = true ;
}
void F_17 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
F_24 () ;
if ( ! V_14 -> V_19 )
goto V_43;
V_2 -> V_7 . V_33 [ 0 ] = V_14 -> V_33 [ 0 ] ;
V_2 -> V_7 . V_33 [ 1 ] = V_14 -> V_33 [ 1 ] ;
V_2 -> V_7 . V_33 [ 2 ] = V_14 -> V_33 [ 2 ] ;
V_2 -> V_7 . V_33 [ 3 ] = V_14 -> V_33 [ 3 ] ;
V_2 -> V_7 . V_33 [ 4 ] = V_14 -> V_33 [ 4 ] ;
V_2 -> V_7 . V_33 [ 5 ] = V_14 -> V_33 [ 5 ] ;
V_2 -> V_7 . V_33 [ 6 ] = V_14 -> V_33 [ 6 ] ;
V_2 -> V_7 . V_33 [ 7 ] = V_14 -> V_33 [ 7 ] ;
V_2 -> V_7 . V_33 [ 8 ] = V_14 -> V_33 [ 8 ] ;
V_2 -> V_7 . V_33 [ 9 ] = V_14 -> V_33 [ 9 ] ;
V_2 -> V_7 . V_33 [ 10 ] = V_14 -> V_33 [ 10 ] ;
V_2 -> V_7 . V_33 [ 11 ] = V_14 -> V_33 [ 11 ] ;
V_2 -> V_7 . V_33 [ 12 ] = V_14 -> V_33 [ 12 ] ;
V_2 -> V_7 . V_33 [ 13 ] = V_14 -> V_33 [ 13 ] ;
V_2 -> V_7 . V_34 = V_14 -> V_34 ;
V_2 -> V_7 . V_35 = V_14 -> V_35 ;
V_2 -> V_7 . V_36 = V_14 -> V_36 ;
V_2 -> V_7 . V_37 = V_14 -> V_37 ;
V_2 -> V_7 . V_6 = V_14 -> V_6 ;
V_2 -> V_7 . V_44 = V_14 -> V_44 ;
V_2 -> V_7 . V_45 = V_14 -> V_45 ;
V_2 -> V_7 . V_46 = V_14 -> V_46 ;
V_2 -> V_7 . V_47 = V_14 -> V_47 ;
#ifdef F_7
V_2 -> V_7 . V_38 = V_14 -> V_38 ;
#endif
V_2 -> V_7 . V_48 += F_22 () - V_2 -> V_7 . V_39 ;
V_2 -> V_7 . V_49 += F_22 () - V_2 -> V_7 . V_39 ;
V_2 -> V_7 . V_50 += F_23 () - V_2 -> V_7 . V_40 ;
if ( F_11 ( V_21 ) )
V_2 -> V_7 . V_51 += F_13 ( V_42 ) - V_2 -> V_7 . V_41 ;
V_14 -> V_19 = false ;
V_43:
F_25 () ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_52 = 1 ;
if ( F_27 ( V_53 , V_2 ) )
F_28 ( V_2 , 0 , 0 ) ;
return V_52 ;
}
static void F_29 ( struct V_54 * V_54 , unsigned long V_55 ,
unsigned long V_56 )
{
long V_57 ;
struct V_1 * V_2 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
V_59 = V_58 ( V_54 ) ;
F_30 (memslot, slots) {
unsigned long V_62 , V_63 ;
T_2 V_64 , V_65 ;
V_62 = F_31 ( V_55 , V_61 -> V_66 ) ;
V_63 = F_32 ( V_56 , V_61 -> V_66 +
( V_61 -> V_67 << V_68 ) ) ;
if ( V_62 >= V_63 )
continue;
V_64 = F_33 ( V_62 , V_61 ) ;
V_65 = F_33 ( V_63 + V_69 - 1 , V_61 ) ;
F_34 (i, vcpu, kvm)
F_35 ( V_2 , V_64 << V_68 ,
V_65 << V_68 ) ;
}
}
static int F_36 ( struct V_54 * V_54 , unsigned long V_70 )
{
F_37 ( V_70 ) ;
F_29 ( V_54 , V_70 , V_70 + V_69 ) ;
return 0 ;
}
static int F_38 ( struct V_54 * V_54 , unsigned long V_55 ,
unsigned long V_56 )
{
F_29 ( V_54 , V_55 , V_56 ) ;
return 0 ;
}
static int F_39 ( struct V_54 * V_54 , unsigned long V_70 )
{
return 0 ;
}
static int F_40 ( struct V_54 * V_54 , unsigned long V_70 )
{
return 0 ;
}
static void F_41 ( struct V_54 * V_54 , unsigned long V_70 , T_3 V_71 )
{
F_29 ( V_54 , V_70 , V_70 + V_69 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
T_1 V_72 = F_2 ( V_2 ) ;
T_1 V_73 = V_72 ;
V_73 &= V_74 | V_75 | V_76 | V_77 | V_78 | V_79 ;
V_73 |= V_80 | V_81 | V_4 | V_5 | V_82 | V_83 ;
V_73 |= ( V_72 & V_2 -> V_7 . V_84 ) ;
#ifdef F_7
V_73 |= V_85 | V_86 ;
#endif
V_2 -> V_7 . V_87 = V_73 ;
}
static void F_43 ( struct V_1 * V_2 , T_4 V_3 )
{
T_1 V_88 = F_2 ( V_2 ) ;
#ifdef F_44
F_45 ( V_89 L_1 , V_3 ) ;
#endif
V_3 &= F_9 ( V_2 ) -> V_90 ;
F_46 ( V_2 , V_3 ) ;
F_42 ( V_2 ) ;
if ( V_3 & V_91 ) {
if ( ! V_2 -> V_7 . V_92 ) {
F_47 ( V_2 ) ;
F_48 ( V_93 , & V_2 -> V_94 ) ;
V_2 -> V_95 . V_96 ++ ;
V_3 &= ~ V_91 ;
F_46 ( V_2 , V_3 ) ;
}
}
if ( F_1 ( V_2 ) )
F_3 ( V_2 ) ;
else
F_18 ( V_2 ) ;
if ( ( F_2 ( V_2 ) & ( V_82 | V_4 | V_5 ) ) !=
( V_88 & ( V_82 | V_4 | V_5 ) ) ) {
F_49 ( V_2 ) ;
F_50 ( V_2 , F_4 ( V_2 ) ) ;
if ( ! ( V_3 & V_82 ) && V_2 -> V_7 . V_97 ) {
struct V_98 * V_99 = & V_2 -> V_7 ;
if ( V_3 & V_5 )
F_50 ( V_2 , V_99 -> V_100 ) ;
else
F_50 ( V_2 , V_99 -> V_97 ) ;
}
}
if ( V_2 -> V_7 . V_97 &&
! ( V_88 & V_82 ) && ! ( V_88 & V_76 ) && ( V_3 & V_76 ) ) {
F_28 ( V_2 , ( V_101 ) V_2 -> V_7 . V_97 ,
~ 0xFFFUL ) ;
}
if ( F_2 ( V_2 ) & V_28 )
F_51 ( V_2 , V_102 , V_28 ) ;
}
void F_52 ( struct V_1 * V_2 , T_5 V_103 )
{
T_5 V_104 ;
V_2 -> V_7 . V_8 &= ~ V_105 ;
V_2 -> V_7 . V_103 = V_103 ;
#ifdef F_7
if ( ( V_103 >= 0x330000 ) && ( V_103 < 0x70330000 ) ) {
F_53 ( V_2 ) ;
if ( ! F_9 ( V_2 ) -> V_106 )
F_9 ( V_2 ) -> V_107 = 0xfff00000 ;
F_9 ( V_2 ) -> V_90 = 0xffffffffffffffffULL ;
V_2 -> V_7 . V_108 = V_109 ;
} else
#endif
{
F_54 ( V_2 ) ;
if ( ! F_9 ( V_2 ) -> V_106 )
F_9 ( V_2 ) -> V_107 = 0 ;
F_9 ( V_2 ) -> V_90 = 0xffffffffULL ;
V_2 -> V_7 . V_108 = V_110 ;
}
F_55 ( V_2 ) ;
V_2 -> V_7 . V_8 &= ~ V_111 ;
if ( V_2 -> V_7 . V_112 . V_113 ( V_2 ) && ( F_56 () & V_86 ) &&
! strcmp ( V_114 -> V_115 , L_2 ) )
V_2 -> V_7 . V_8 |= V_111 ;
if ( ! strcmp ( V_114 -> V_115 , L_3 ) )
F_9 ( V_2 ) -> V_90 &= ~ ( V_74 | V_75 ) ;
switch ( F_57 ( V_103 ) ) {
case V_116 :
case V_117 :
case V_118 :
case V_119 :
V_2 -> V_7 . V_8 |= V_120 |
V_121 ;
break;
}
#ifdef F_15
V_2 -> V_7 . V_8 |= V_111 ;
#endif
asm ( "mfpvr %0" : "=r"(host_pvr));
switch ( V_104 ) {
case 0x00080200 :
case 0x00088202 :
case 0x70000100 :
case 0x00080100 :
case 0x00083203 :
case 0x00083213 :
case 0x00083204 :
case 0x00083214 :
case 0x00087200 :
V_2 -> V_7 . V_8 |= V_122 ;
F_12 ( V_123 , F_13 ( V_123 ) | ( 1 << 29 ) ) ;
}
}
static void F_58 ( struct V_1 * V_2 , struct V_124 * V_71 )
{
struct V_125 * V_126 ;
T_4 V_127 ;
T_5 * V_125 ;
int V_57 ;
V_126 = F_59 ( V_2 -> V_54 , V_71 -> V_128 >> V_68 ) ;
if ( F_60 ( V_126 ) )
return;
V_127 = V_71 -> V_128 & ~ V_129 ;
V_127 &= ~ 0xFFFULL ;
V_127 /= 4 ;
F_61 ( V_126 ) ;
V_125 = F_62 ( V_126 ) ;
for ( V_57 = V_127 ; V_57 < V_127 + ( V_130 / 4 ) ; V_57 ++ )
if ( ( F_63 ( V_125 [ V_57 ] ) & 0xff0007ff ) == V_131 )
V_125 [ V_57 ] &= F_64 ( 0xfffffff7 ) ;
F_65 ( V_125 ) ;
F_66 ( V_126 ) ;
}
static int F_67 ( struct V_1 * V_2 , T_6 V_132 )
{
T_1 V_133 = V_2 -> V_7 . V_97 ;
if ( ! ( F_2 ( V_2 ) & V_76 ) )
V_133 = ( V_101 ) V_133 ;
V_132 &= ~ 0xFFFULL ;
if ( F_68 ( V_133 ) && F_68 ( ( V_133 & V_134 ) == ( V_132 & V_134 ) ) ) {
return 1 ;
}
return F_69 ( V_2 -> V_54 , V_132 >> V_68 ) ;
}
int F_70 ( struct V_135 * V_136 , struct V_1 * V_2 ,
T_1 V_137 , int V_138 )
{
bool V_139 = ( V_138 == V_140 ) ;
bool V_141 = false ;
int V_52 = V_142 ;
int V_143 ;
int V_144 = 0 ;
struct V_124 V_71 ;
bool V_145 = false ;
bool V_146 = ( F_2 ( V_2 ) & V_5 ) ? true : false ;
bool V_147 = ( F_2 ( V_2 ) & V_4 ) ? true : false ;
T_4 V_148 ;
V_143 = V_139 ? V_146 : V_147 ;
if ( V_139 && ( V_2 -> V_7 . V_46 & V_149 ) )
V_141 = true ;
if ( V_143 ) {
V_144 = V_2 -> V_7 . V_112 . V_150 ( V_2 , V_137 , & V_71 , V_139 , V_141 ) ;
} else {
V_71 . V_151 = true ;
V_71 . V_152 = true ;
V_71 . V_153 = true ;
V_71 . V_128 = V_137 & V_134 ;
V_71 . V_137 = V_137 ;
V_71 . V_154 = V_137 >> 12 ;
V_71 . V_155 = V_156 ;
}
switch ( F_2 ( V_2 ) & ( V_5 | V_4 ) ) {
case 0 :
V_71 . V_154 |= ( ( T_4 ) V_157 << ( V_158 - 12 ) ) ;
break;
case V_5 :
if ( ! V_139 &&
( V_2 -> V_7 . V_8 & V_9 ) &&
( ( V_71 . V_128 & V_10 ) == V_11 ) )
V_71 . V_128 &= ~ V_10 ;
case V_4 :
V_2 -> V_7 . V_112 . V_159 ( V_2 , V_137 >> V_158 , & V_148 ) ;
if ( ( F_2 ( V_2 ) & ( V_5 | V_4 ) ) == V_5 )
V_71 . V_154 |= ( ( T_4 ) V_160 << ( V_158 - 12 ) ) ;
else
V_71 . V_154 |= ( ( T_4 ) V_161 << ( V_158 - 12 ) ) ;
V_71 . V_154 |= V_148 ;
if ( V_148 == - 1 )
V_144 = - V_162 ;
break;
}
if ( V_2 -> V_7 . V_112 . V_113 ( V_2 ) &&
( ! ( V_2 -> V_7 . V_8 & V_111 ) ) ) {
V_71 . V_151 = ! V_139 ;
}
if ( V_144 == - V_163 ) {
T_4 V_164 = V_2 -> V_7 . V_44 ;
T_4 V_3 = F_2 ( V_2 ) ;
F_71 ( V_2 , F_72 ( V_2 ) ) ;
F_73 ( V_2 , V_2 -> V_7 . V_46 ) ;
F_46 ( V_2 , V_3 | ( V_164 & 0xf8000000ULL ) ) ;
F_74 ( V_2 , V_138 ) ;
} else if ( V_144 == - V_165 ) {
T_5 V_166 = V_2 -> V_7 . V_46 ;
T_4 V_164 = V_2 -> V_7 . V_44 ;
T_4 V_3 = F_2 ( V_2 ) ;
F_71 ( V_2 , F_72 ( V_2 ) ) ;
V_166 = ( V_166 & ~ V_167 ) | V_168 ;
F_73 ( V_2 , V_166 ) ;
F_46 ( V_2 , V_3 | ( V_164 & 0xf8000000ULL ) ) ;
F_74 ( V_2 , V_138 ) ;
} else if ( V_144 == - V_162 ) {
F_71 ( V_2 , F_72 ( V_2 ) ) ;
F_74 ( V_2 , V_138 + 0x80 ) ;
} else if ( ! V_145 &&
F_67 ( V_2 , V_71 . V_128 ) ) {
if ( V_139 && ! ( V_2 -> V_7 . V_46 & V_167 ) ) {
F_75 ( V_2 , & V_71 ) ;
}
F_76 ( V_2 , & V_71 , V_141 ) ;
if ( V_139 )
V_2 -> V_95 . V_169 ++ ;
else if ( V_2 -> V_7 . V_112 . V_113 ( V_2 ) &&
( ! ( V_2 -> V_7 . V_8 & V_111 ) ) )
F_58 ( V_2 , & V_71 ) ;
} else {
V_2 -> V_95 . V_170 ++ ;
V_2 -> V_7 . V_171 = V_71 . V_128 ;
V_2 -> V_7 . V_172 = V_71 . V_137 ;
V_52 = F_77 ( V_136 , V_2 ) ;
if ( V_52 == V_173 )
V_52 = V_174 ;
}
return V_52 ;
}
static inline int F_78 ( int V_57 )
{
return V_57 * V_175 ;
}
void F_19 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_176 * V_177 = & V_24 -> V_25 ;
if ( V_3 & V_30 )
V_3 |= V_28 | V_29 ;
V_3 &= V_2 -> V_7 . V_84 ;
if ( ! V_3 )
return;
#ifdef F_79
F_45 ( V_89 L_4 , V_3 ) ;
#endif
if ( V_3 & V_28 ) {
if ( V_177 -> V_178 -> V_3 & V_28 )
F_80 ( V_24 ) ;
V_177 -> V_179 = NULL ;
}
#ifdef F_81
if ( V_3 & V_29 ) {
if ( V_24 -> V_25 . V_178 -> V_3 & V_29 )
F_82 ( V_24 ) ;
V_177 -> V_180 = NULL ;
}
#endif
V_2 -> V_7 . V_84 &= ~ ( V_3 | V_30 ) ;
F_42 ( V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_181 )
{
#ifdef F_7
if ( ! ( V_2 -> V_7 . V_38 & ( 1ULL << V_181 ) ) ) {
return;
}
switch ( V_181 ) {
case V_31 :
V_2 -> V_7 . V_182 = F_13 ( V_183 ) ;
F_12 ( V_183 , V_24 -> V_25 . V_182 ) ;
V_2 -> V_7 . V_38 &= ~ V_184 ;
break;
}
#endif
}
static int F_51 ( struct V_1 * V_2 , unsigned int V_185 ,
T_1 V_3 )
{
struct V_176 * V_177 = & V_24 -> V_25 ;
if ( V_2 -> V_7 . V_8 & V_186 )
return V_142 ;
if ( ! ( F_2 ( V_2 ) & V_3 ) ) {
F_74 ( V_2 , V_185 ) ;
return V_142 ;
}
if ( V_3 == V_30 ) {
#ifdef F_83
if ( ! F_11 ( V_187 ) )
#endif
{
F_84 ( V_2 , V_188 ) ;
return V_142 ;
}
V_3 = V_28 | V_29 | V_30 ;
}
V_3 &= ~ V_2 -> V_7 . V_84 ;
if ( ! V_3 )
return V_142 ;
#ifdef F_79
F_45 ( V_89 L_5 , V_3 ) ;
#endif
if ( V_3 & V_28 ) {
F_24 () ;
F_85 () ;
F_86 ( & V_2 -> V_7 . V_189 ) ;
V_177 -> V_179 = & V_2 -> V_7 . V_189 ;
F_25 () ;
}
if ( V_3 & V_29 ) {
#ifdef F_81
F_24 () ;
F_87 () ;
F_88 ( & V_2 -> V_7 . V_190 ) ;
V_177 -> V_180 = & V_2 -> V_7 . V_190 ;
F_25 () ;
#endif
}
V_177 -> V_178 -> V_3 |= V_3 ;
V_2 -> V_7 . V_84 |= V_3 ;
F_42 ( V_2 ) ;
return V_142 ;
}
static void F_89 ( struct V_1 * V_2 )
{
unsigned long V_191 ;
V_191 = V_2 -> V_7 . V_84 & ~ V_24 -> V_25 . V_178 -> V_3 ;
if ( ! V_191 )
return;
if ( V_191 & V_28 ) {
F_24 () ;
F_85 () ;
F_86 ( & V_2 -> V_7 . V_189 ) ;
F_25 () ;
}
#ifdef F_81
if ( V_191 & V_29 ) {
F_24 () ;
F_87 () ;
F_88 ( & V_2 -> V_7 . V_190 ) ;
F_25 () ;
}
#endif
V_24 -> V_25 . V_178 -> V_3 |= V_191 ;
}
static void F_90 ( struct V_1 * V_2 , T_1 V_181 )
{
V_2 -> V_7 . V_192 &= ~ ( 0xffULL << 56 ) ;
V_2 -> V_7 . V_192 |= ( V_181 << 56 ) ;
F_74 ( V_2 , V_193 ) ;
}
static void F_91 ( struct V_1 * V_2 , T_1 V_181 )
{
enum V_194 V_195 = V_196 ;
if ( ! ( F_2 ( V_2 ) & V_82 ) )
V_195 = F_92 ( V_2 -> V_136 , V_2 ) ;
if ( ( V_195 != V_197 ) && ( V_195 != V_198 ) ) {
F_90 ( V_2 , V_181 ) ;
}
}
static int F_93 ( struct V_1 * V_2 , T_1 V_181 )
{
bool V_199 ;
F_94 ( ! F_11 ( V_21 ) ) ;
switch ( V_181 ) {
case V_31 :
case V_200 :
V_199 = ( V_2 -> V_7 . V_192 & ( 1ULL << V_181 ) ) ;
break;
case V_201 :
V_199 = F_2 ( V_2 ) & V_202 ;
break;
default:
V_199 = false ;
break;
}
if ( ! V_199 ) {
F_90 ( V_2 , V_181 ) ;
return V_142 ;
}
switch ( V_181 ) {
case V_31 :
V_24 -> V_25 . V_182 = F_13 ( V_183 ) ;
F_12 ( V_183 , V_2 -> V_7 . V_182 ) ;
V_2 -> V_7 . V_38 |= V_184 ;
break;
default:
F_91 ( V_2 , V_181 ) ;
break;
}
return V_142 ;
}
void F_95 ( struct V_1 * V_2 , T_4 V_192 )
{
if ( ( V_2 -> V_7 . V_192 & V_184 ) && ! ( V_192 & V_184 ) ) {
F_20 ( V_2 , V_31 ) ;
}
V_2 -> V_7 . V_192 = V_192 ;
}
int F_96 ( struct V_135 * V_136 , struct V_1 * V_2 ,
unsigned int V_185 )
{
int V_52 = V_174 ;
int V_203 ;
V_2 -> V_95 . V_204 ++ ;
V_136 -> V_205 = V_206 ;
V_136 -> V_207 = 1 ;
F_97 ( V_185 , V_2 ) ;
F_98 () ;
switch ( V_185 ) {
case V_208 :
{
T_1 V_44 = V_2 -> V_7 . V_44 ;
V_2 -> V_95 . V_209 ++ ;
if ( F_1 ( V_2 ) )
F_3 ( V_2 ) ;
#ifdef F_15
{
struct V_13 * V_14 ;
T_5 V_210 ;
V_14 = F_8 ( V_2 ) ;
V_210 = V_14 -> V_210 [ F_4 ( V_2 ) >> V_158 ] ;
F_10 ( V_14 ) ;
if ( V_210 == V_211 ) {
F_50 ( V_2 , F_4 ( V_2 ) ) ;
V_52 = V_142 ;
break;
}
}
#endif
if ( V_44 & 0x40000000 ) {
int V_212 = F_99 ( & V_2 -> V_54 -> V_213 ) ;
V_52 = F_70 ( V_136 , V_2 , F_4 ( V_2 ) , V_185 ) ;
F_100 ( & V_2 -> V_54 -> V_213 , V_212 ) ;
V_2 -> V_95 . V_214 ++ ;
} else if ( V_2 -> V_7 . V_112 . V_113 ( V_2 ) &&
( ! ( V_2 -> V_7 . V_8 & V_111 ) ) ) {
F_28 ( V_2 , F_4 ( V_2 ) , ~ 0xFFFUL ) ;
V_52 = V_142 ;
} else {
T_4 V_3 = F_2 ( V_2 ) ;
V_3 |= V_44 & 0x58000000 ;
F_46 ( V_2 , V_3 ) ;
F_74 ( V_2 , V_185 ) ;
V_52 = V_142 ;
}
break;
}
case V_140 :
{
T_1 V_215 = F_72 ( V_2 ) ;
T_5 V_46 = V_2 -> V_7 . V_46 ;
V_2 -> V_95 . V_216 ++ ;
#ifdef F_15
{
struct V_13 * V_14 ;
T_5 V_210 ;
V_14 = F_8 ( V_2 ) ;
V_210 = V_14 -> V_210 [ V_215 >> V_158 ] ;
F_10 ( V_14 ) ;
if ( V_210 == V_211 ) {
F_50 ( V_2 , V_215 ) ;
V_52 = V_142 ;
break;
}
}
#endif
if ( V_46 & ( V_167 | V_168 ) ) {
int V_212 = F_99 ( & V_2 -> V_54 -> V_213 ) ;
V_52 = F_70 ( V_136 , V_2 , V_215 , V_185 ) ;
F_100 ( & V_2 -> V_54 -> V_213 , V_212 ) ;
} else {
F_71 ( V_2 , V_215 ) ;
F_73 ( V_2 , V_46 ) ;
F_74 ( V_2 , V_185 ) ;
V_52 = V_142 ;
}
break;
}
case V_217 :
if ( F_50 ( V_2 , F_72 ( V_2 ) ) < 0 ) {
F_71 ( V_2 , F_72 ( V_2 ) ) ;
F_74 ( V_2 ,
V_217 ) ;
}
V_52 = V_142 ;
break;
case V_218 :
if ( F_50 ( V_2 , F_4 ( V_2 ) ) < 0 ) {
F_74 ( V_2 ,
V_218 ) ;
}
V_52 = V_142 ;
break;
case V_219 :
case V_220 :
case V_221 :
case V_222 :
V_2 -> V_95 . V_223 ++ ;
V_52 = V_142 ;
break;
case V_224 :
case V_225 :
case V_226 :
V_2 -> V_95 . V_227 ++ ;
V_52 = V_142 ;
break;
case V_228 :
V_52 = V_142 ;
break;
case V_229 :
case V_230 :
{
enum V_194 V_195 ;
T_1 V_231 ;
T_5 V_47 ;
int V_232 ;
V_233:
V_231 = V_2 -> V_7 . V_44 & 0x1f0000ull ;
V_232 = F_101 ( V_2 , V_234 , & V_47 ) ;
if ( V_232 != V_197 ) {
V_52 = V_142 ;
break;
}
if ( F_2 ( V_2 ) & V_82 ) {
#ifdef F_44
F_102 ( L_6 ,
F_4 ( V_2 ) , V_47 ) ;
#endif
if ( ( V_47 & 0xff0007ff ) !=
( V_131 & 0xfffffff7 ) ) {
F_84 ( V_2 , V_231 ) ;
V_52 = V_142 ;
break;
}
}
V_2 -> V_95 . V_235 ++ ;
V_195 = F_92 ( V_136 , V_2 ) ;
switch ( V_195 ) {
case V_197 :
V_52 = V_236 ;
break;
case V_198 :
V_52 = V_142 ;
break;
case V_196 :
F_45 ( V_237 L_7 ,
V_238 , F_4 ( V_2 ) , V_47 ) ;
F_84 ( V_2 , V_231 ) ;
V_52 = V_142 ;
break;
case V_239 :
V_136 -> V_205 = V_240 ;
V_52 = V_173 ;
break;
case V_241 :
V_52 = V_173 ;
break;
default:
F_103 () ;
}
break;
}
case V_242 :
{
T_5 V_243 ;
int V_232 ;
if ( V_2 -> V_7 . V_244 ) {
V_232 = F_101 ( V_2 , V_245 , & V_243 ) ;
if ( V_232 != V_197 ) {
F_5 ( V_2 , F_4 ( V_2 ) - 4 ) ;
V_52 = V_142 ;
break;
}
}
if ( V_2 -> V_7 . V_244 &&
( V_243 == 0x44000022 ) &&
! ( F_2 ( V_2 ) & V_82 ) ) {
T_1 V_246 = F_104 ( V_2 , 3 ) ;
int V_57 ;
#ifdef F_7
if ( F_105 ( V_2 , V_246 ) == V_197 ) {
V_52 = V_142 ;
break;
}
#endif
V_136 -> V_247 . V_248 = V_246 ;
for ( V_57 = 0 ; V_57 < 9 ; ++ V_57 ) {
T_1 V_33 = F_104 ( V_2 , 4 + V_57 ) ;
V_136 -> V_247 . args [ V_57 ] = V_33 ;
}
V_136 -> V_205 = V_249 ;
V_2 -> V_7 . V_250 = 1 ;
V_52 = V_174 ;
} else if ( V_2 -> V_7 . V_251 &&
( ( ( T_5 ) F_104 ( V_2 , 3 ) ) == V_252 ) &&
( ( ( T_5 ) F_104 ( V_2 , 4 ) ) == V_253 ) ) {
T_4 * V_254 = V_136 -> V_255 . V_254 ;
int V_57 ;
V_136 -> V_205 = V_256 ;
for ( V_57 = 0 ; V_57 < 32 ; V_57 ++ )
V_254 [ V_57 ] = F_104 ( V_2 , V_57 ) ;
V_2 -> V_7 . V_257 = 1 ;
V_52 = V_173 ;
} else if ( ! ( F_2 ( V_2 ) & V_82 ) &&
( ( ( T_5 ) F_104 ( V_2 , 0 ) ) == V_258 ) ) {
F_106 ( V_2 , 3 , F_107 ( V_2 ) ) ;
V_52 = V_142 ;
} else {
V_2 -> V_95 . V_259 ++ ;
F_74 ( V_2 , V_185 ) ;
V_52 = V_142 ;
}
break;
}
case V_102 :
case V_260 :
case V_261 :
{
int V_262 = 0 ;
int V_232 ;
T_5 V_47 ;
if ( V_2 -> V_7 . V_8 & V_186 ) {
V_232 = F_101 ( V_2 , V_234 ,
& V_47 ) ;
if ( V_232 == V_197 )
goto V_233;
else
V_52 = V_142 ;
break;
}
switch ( V_185 ) {
case V_102 :
V_262 = V_28 ;
break;
case V_260 :
V_262 = V_29 ;
break;
case V_261 :
V_262 = V_30 ;
break;
}
V_52 = F_51 ( V_2 , V_185 , V_262 ) ;
break;
}
case V_263 :
{
T_5 V_47 ;
int V_232 = F_101 ( V_2 , V_234 , & V_47 ) ;
if ( V_232 == V_197 ) {
T_5 V_166 ;
T_4 V_215 ;
V_166 = F_108 ( V_2 , V_47 ) ;
V_215 = F_109 ( V_2 , V_47 ) ;
F_73 ( V_2 , V_166 ) ;
F_71 ( V_2 , V_215 ) ;
F_74 ( V_2 , V_185 ) ;
}
V_52 = V_142 ;
break;
}
#ifdef F_7
case V_193 :
F_93 ( V_2 , V_2 -> V_7 . V_38 >> 56 ) ;
V_52 = V_142 ;
break;
#endif
case V_264 :
case V_265 :
F_74 ( V_2 , V_185 ) ;
V_52 = V_142 ;
break;
default:
{
T_1 V_44 = V_2 -> V_7 . V_44 ;
F_45 ( V_266 L_8 ,
V_185 , F_4 ( V_2 ) , V_44 ) ;
V_52 = V_174 ;
F_103 () ;
break;
}
}
if ( ! ( V_52 & V_174 ) ) {
V_203 = F_110 ( V_2 ) ;
if ( V_203 <= 0 )
V_52 = V_203 ;
else {
F_111 () ;
}
F_89 ( V_2 ) ;
}
F_112 ( V_52 , V_2 ) ;
return V_52 ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_267 * V_268 )
{
struct V_269 * V_270 = F_9 ( V_2 ) ;
int V_57 ;
V_268 -> V_103 = V_2 -> V_7 . V_103 ;
V_268 -> V_271 . V_203 . V_272 = F_9 ( V_2 ) -> V_272 ;
if ( V_2 -> V_7 . V_8 & V_105 ) {
for ( V_57 = 0 ; V_57 < 64 ; V_57 ++ ) {
V_268 -> V_271 . V_203 . V_273 . V_15 [ V_57 ] . V_274 = V_2 -> V_7 . V_15 [ V_57 ] . V_275 | V_57 ;
V_268 -> V_271 . V_203 . V_273 . V_15 [ V_57 ] . V_276 = V_2 -> V_7 . V_15 [ V_57 ] . V_277 ;
}
} else {
for ( V_57 = 0 ; V_57 < 16 ; V_57 ++ )
V_268 -> V_271 . V_203 . V_278 . V_210 [ V_57 ] = F_114 ( V_2 , V_57 ) ;
for ( V_57 = 0 ; V_57 < 8 ; V_57 ++ ) {
V_268 -> V_271 . V_203 . V_278 . V_279 [ V_57 ] = V_270 -> V_279 [ V_57 ] . V_280 ;
V_268 -> V_271 . V_203 . V_278 . V_281 [ V_57 ] = V_270 -> V_281 [ V_57 ] . V_280 ;
}
}
return 0 ;
}
static int F_115 ( struct V_1 * V_2 ,
struct V_267 * V_268 )
{
struct V_269 * V_270 = F_9 ( V_2 ) ;
int V_57 ;
F_52 ( V_2 , V_268 -> V_103 ) ;
V_270 -> V_272 = V_268 -> V_271 . V_203 . V_272 ;
if ( V_2 -> V_7 . V_8 & V_105 ) {
for ( V_57 = 0 ; V_57 < 64 ; V_57 ++ ) {
V_2 -> V_7 . V_112 . V_282 ( V_2 , V_268 -> V_271 . V_203 . V_273 . V_15 [ V_57 ] . V_276 ,
V_268 -> V_271 . V_203 . V_273 . V_15 [ V_57 ] . V_274 ) ;
}
} else {
for ( V_57 = 0 ; V_57 < 16 ; V_57 ++ ) {
V_2 -> V_7 . V_112 . V_283 ( V_2 , V_57 , V_268 -> V_271 . V_203 . V_278 . V_210 [ V_57 ] ) ;
}
for ( V_57 = 0 ; V_57 < 8 ; V_57 ++ ) {
F_116 ( V_2 , & ( V_270 -> V_279 [ V_57 ] ) , false ,
( T_5 ) V_268 -> V_271 . V_203 . V_278 . V_279 [ V_57 ] ) ;
F_116 ( V_2 , & ( V_270 -> V_279 [ V_57 ] ) , true ,
( T_5 ) ( V_268 -> V_271 . V_203 . V_278 . V_279 [ V_57 ] >> 32 ) ) ;
F_116 ( V_2 , & ( V_270 -> V_281 [ V_57 ] ) , false ,
( T_5 ) V_268 -> V_271 . V_203 . V_278 . V_281 [ V_57 ] ) ;
F_116 ( V_2 , & ( V_270 -> V_281 [ V_57 ] ) , true ,
( T_5 ) ( V_268 -> V_271 . V_203 . V_278 . V_281 [ V_57 ] >> 32 ) ) ;
}
}
F_28 ( V_2 , 0 , 0 ) ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 , T_4 V_284 ,
union V_285 * V_286 )
{
int V_52 = 0 ;
switch ( V_284 ) {
case V_287 :
* V_286 = F_118 ( V_284 , F_9 ( V_2 ) -> V_107 ) ;
break;
case V_288 :
case V_289 :
if ( V_2 -> V_7 . V_290 & V_79 )
* V_286 = F_118 ( V_284 , V_291 ) ;
else
* V_286 = F_118 ( V_284 , 0 ) ;
break;
default:
V_52 = - V_162 ;
break;
}
return V_52 ;
}
static void F_119 ( struct V_1 * V_2 , T_4 V_292 )
{
if ( V_292 & V_291 )
V_2 -> V_7 . V_290 |= V_79 ;
else
V_2 -> V_7 . V_290 &= ~ V_79 ;
}
static int F_120 ( struct V_1 * V_2 , T_4 V_284 ,
union V_285 * V_286 )
{
int V_52 = 0 ;
switch ( V_284 ) {
case V_287 :
F_9 ( V_2 ) -> V_107 = F_121 ( V_284 , * V_286 ) ;
F_9 ( V_2 ) -> V_106 = true ;
break;
case V_288 :
case V_289 :
F_119 ( V_2 , F_121 ( V_284 , * V_286 ) ) ;
break;
default:
V_52 = - V_162 ;
break;
}
return V_52 ;
}
static struct V_1 * F_122 ( struct V_54 * V_54 ,
unsigned int V_284 )
{
struct V_269 * V_293 ;
struct V_1 * V_2 ;
int V_294 = - V_295 ;
unsigned long V_296 ;
V_2 = F_123 ( V_297 , V_298 ) ;
if ( ! V_2 )
goto V_43;
V_293 = F_124 ( sizeof( struct V_269 ) ) ;
if ( ! V_293 )
goto V_299;
V_2 -> V_7 . V_300 = V_293 ;
#ifdef F_125
V_2 -> V_7 . V_27 =
F_126 ( sizeof( * V_2 -> V_7 . V_27 ) , V_298 ) ;
if ( ! V_2 -> V_7 . V_27 )
goto V_301;
#endif
V_294 = F_127 ( V_2 , V_54 , V_284 ) ;
if ( V_294 )
goto V_302;
V_294 = - V_295 ;
V_296 = F_128 ( V_298 | V_303 ) ;
if ( ! V_296 )
goto V_304;
V_2 -> V_7 . V_305 = ( void * ) V_296 ;
#ifdef F_7
#ifdef F_129
V_2 -> V_7 . V_306 = true ;
#else
V_2 -> V_7 . V_306 = false ;
#endif
V_2 -> V_7 . V_103 = 0x3C0301 ;
if ( F_130 ( V_307 ) )
V_2 -> V_7 . V_103 = F_13 ( V_308 ) ;
V_2 -> V_7 . V_290 = V_76 ;
#else
V_2 -> V_7 . V_103 = 0x84202 ;
#endif
F_52 ( V_2 , V_2 -> V_7 . V_103 ) ;
V_2 -> V_7 . V_309 = 64 ;
V_2 -> V_7 . V_87 = V_310 & ~ V_79 ;
V_294 = F_131 ( V_2 ) ;
if ( V_294 < 0 )
goto V_304;
return V_2 ;
V_304:
F_132 ( V_2 ) ;
V_302:
#ifdef F_125
F_133 ( V_2 -> V_7 . V_27 ) ;
V_301:
#endif
F_134 ( V_293 ) ;
V_299:
F_135 ( V_297 , V_2 ) ;
V_43:
return F_136 ( V_294 ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
struct V_269 * V_293 = F_9 ( V_2 ) ;
F_138 ( ( unsigned long ) V_2 -> V_7 . V_305 & V_129 ) ;
F_132 ( V_2 ) ;
#ifdef F_125
F_133 ( V_2 -> V_7 . V_27 ) ;
#endif
F_134 ( V_293 ) ;
F_135 ( V_297 , V_2 ) ;
}
static int F_139 ( struct V_135 * V_135 , struct V_1 * V_2 )
{
int V_311 ;
#ifdef F_81
unsigned long V_312 ( V_313 ) ;
#endif
if ( ! V_2 -> V_7 . V_314 ) {
V_135 -> V_205 = V_315 ;
V_311 = - V_162 ;
goto V_43;
}
V_311 = F_110 ( V_2 ) ;
if ( V_311 <= 0 )
goto V_43;
if ( V_24 -> V_25 . V_178 -> V_3 & V_28 )
F_80 ( V_24 ) ;
#ifdef F_81
if ( V_24 -> V_25 . V_178 -> V_3 & V_29 )
F_82 ( V_24 ) ;
#endif
#ifdef F_83
if ( V_24 -> V_25 . V_178 -> V_3 & V_30 )
F_140 ( V_24 ) ;
#endif
if ( F_2 ( V_2 ) & V_28 )
F_51 ( V_2 , V_102 , V_28 ) ;
F_111 () ;
V_311 = F_141 ( V_135 , V_2 ) ;
F_19 ( V_2 , V_28 | V_29 | V_30 ) ;
F_20 ( V_2 , V_31 ) ;
V_43:
V_2 -> V_316 = V_317 ;
return V_311 ;
}
static int F_142 ( struct V_54 * V_54 ,
struct V_318 * log )
{
struct V_60 * V_61 ;
struct V_1 * V_2 ;
T_1 V_319 , V_320 ;
int V_321 = 0 ;
int V_52 ;
unsigned long V_322 ;
F_143 ( & V_54 -> V_323 ) ;
V_52 = F_144 ( V_54 , log , & V_321 ) ;
if ( V_52 )
goto V_43;
if ( V_321 ) {
V_61 = F_145 ( V_54 -> V_324 , log -> V_325 ) ;
V_319 = V_61 -> V_326 << V_68 ;
V_320 = V_319 + ( V_61 -> V_67 << V_68 ) ;
F_34 (n, vcpu, kvm)
F_35 ( V_2 , V_319 , V_320 ) ;
V_322 = F_146 ( V_61 ) ;
memset ( V_61 -> V_327 , 0 , V_322 ) ;
}
V_52 = 0 ;
V_43:
F_147 ( & V_54 -> V_323 ) ;
return V_52 ;
}
static void F_148 ( struct V_54 * V_54 ,
struct V_60 * V_61 )
{
return;
}
static int F_149 ( struct V_54 * V_54 ,
struct V_60 * V_61 ,
struct V_328 * V_329 )
{
return 0 ;
}
static void F_150 ( struct V_54 * V_54 ,
struct V_328 * V_329 ,
const struct V_60 * V_330 )
{
return;
}
static void F_151 ( struct V_60 * free ,
struct V_60 * V_331 )
{
return;
}
static int F_152 ( struct V_60 * V_325 ,
unsigned long V_67 )
{
return 0 ;
}
static int F_153 ( struct V_54 * V_54 ,
struct V_332 * V_333 )
{
long int V_57 ;
struct V_1 * V_2 ;
V_333 -> V_231 = 0 ;
V_333 -> V_334 = 64 ;
V_333 -> V_335 [ 0 ] . V_336 = 12 ;
V_333 -> V_335 [ 0 ] . V_337 = 0 ;
V_333 -> V_335 [ 0 ] . V_338 [ 0 ] . V_336 = 12 ;
V_333 -> V_335 [ 0 ] . V_338 [ 0 ] . V_339 = 0 ;
V_57 = 1 ;
V_2 = F_154 ( V_54 , 0 ) ;
if ( V_2 && ( V_2 -> V_7 . V_8 & V_120 ) ) {
V_333 -> V_231 = V_340 ;
V_333 -> V_335 [ V_57 ] . V_336 = 16 ;
V_333 -> V_335 [ V_57 ] . V_337 = V_341 | V_342 ;
V_333 -> V_335 [ V_57 ] . V_338 [ 0 ] . V_336 = 16 ;
V_333 -> V_335 [ V_57 ] . V_338 [ 0 ] . V_339 = 1 ;
++ V_57 ;
}
V_333 -> V_335 [ V_57 ] . V_336 = 24 ;
V_333 -> V_335 [ V_57 ] . V_337 = V_341 ;
V_333 -> V_335 [ V_57 ] . V_338 [ 0 ] . V_336 = 24 ;
V_333 -> V_335 [ V_57 ] . V_338 [ 0 ] . V_339 = 0 ;
return 0 ;
}
static int F_153 ( struct V_54 * V_54 ,
struct V_332 * V_333 )
{
F_103 () ;
}
static int F_155 ( struct V_54 * V_54 )
{
F_156 ( & V_54 -> V_7 . V_343 ) ;
#ifdef F_7
F_157 ( V_54 ) ;
#endif
if ( F_158 ( V_344 ) ) {
F_159 ( & V_345 ) ;
if ( ++ V_346 == 1 )
F_160 () ;
F_161 ( & V_345 ) ;
}
return 0 ;
}
static void F_162 ( struct V_54 * V_54 )
{
#ifdef F_163
F_164 ( ! F_165 ( & V_54 -> V_7 . V_347 ) ) ;
#endif
if ( F_158 ( V_344 ) ) {
F_159 ( & V_345 ) ;
F_94 ( V_346 == 0 ) ;
if ( -- V_346 == 0 )
F_166 () ;
F_161 ( & V_345 ) ;
}
}
static int F_167 ( void )
{
return 0 ;
}
static long F_168 ( struct V_348 * V_349 ,
unsigned int V_350 , unsigned long V_351 )
{
return - V_352 ;
}
int F_169 ( void )
{
int V_52 ;
V_52 = F_167 () ;
if ( V_52 < 0 )
return V_52 ;
V_353 . V_354 = V_355 ;
V_356 = & V_353 ;
V_52 = F_170 () ;
return V_52 ;
}
void F_171 ( void )
{
V_356 = NULL ;
F_172 () ;
}
