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
static int F_39 ( struct V_54 * V_54 , unsigned long V_55 ,
unsigned long V_56 )
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
static bool F_67 ( struct V_1 * V_2 , T_6 V_132 )
{
T_1 V_133 = V_2 -> V_7 . V_97 ;
if ( ! ( F_2 ( V_2 ) & V_76 ) )
V_133 = ( V_101 ) V_133 ;
V_132 &= ~ 0xFFFULL ;
if ( F_68 ( V_133 ) && F_68 ( ( V_133 & V_134 ) == ( V_132 & V_134 ) ) ) {
return true ;
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
void F_19 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_175 * V_176 = & V_24 -> V_25 ;
if ( V_3 & V_30 )
V_3 |= V_28 | V_29 ;
V_3 &= V_2 -> V_7 . V_84 ;
if ( ! V_3 )
return;
#ifdef F_78
F_45 ( V_89 L_4 , V_3 ) ;
#endif
if ( V_3 & V_28 ) {
if ( V_176 -> V_177 -> V_3 & V_28 )
F_79 ( V_24 ) ;
V_176 -> V_178 = NULL ;
}
#ifdef F_80
if ( V_3 & V_29 ) {
if ( V_24 -> V_25 . V_177 -> V_3 & V_29 )
F_81 ( V_24 ) ;
V_176 -> V_179 = NULL ;
}
#endif
V_2 -> V_7 . V_84 &= ~ ( V_3 | V_30 ) ;
F_42 ( V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_180 )
{
#ifdef F_7
if ( ! ( V_2 -> V_7 . V_38 & ( 1ULL << V_180 ) ) ) {
return;
}
switch ( V_180 ) {
case V_31 :
V_2 -> V_7 . V_181 = F_13 ( V_182 ) ;
F_12 ( V_182 , V_24 -> V_25 . V_181 ) ;
V_2 -> V_7 . V_38 &= ~ V_183 ;
break;
}
#endif
}
static int F_51 ( struct V_1 * V_2 , unsigned int V_184 ,
T_1 V_3 )
{
struct V_175 * V_176 = & V_24 -> V_25 ;
if ( V_2 -> V_7 . V_8 & V_185 )
return V_142 ;
if ( ! ( F_2 ( V_2 ) & V_3 ) ) {
F_74 ( V_2 , V_184 ) ;
return V_142 ;
}
if ( V_3 == V_30 ) {
#ifdef F_82
if ( ! F_11 ( V_186 ) )
#endif
{
F_83 ( V_2 , V_187 ) ;
return V_142 ;
}
V_3 = V_28 | V_29 | V_30 ;
}
V_3 &= ~ V_2 -> V_7 . V_84 ;
if ( ! V_3 )
return V_142 ;
#ifdef F_78
F_45 ( V_89 L_5 , V_3 ) ;
#endif
if ( V_3 & V_28 ) {
F_24 () ;
F_84 () ;
F_85 ( & V_2 -> V_7 . V_188 ) ;
F_86 () ;
V_176 -> V_178 = & V_2 -> V_7 . V_188 ;
F_25 () ;
}
if ( V_3 & V_29 ) {
#ifdef F_80
F_24 () ;
F_87 () ;
F_88 ( & V_2 -> V_7 . V_189 ) ;
F_89 () ;
V_176 -> V_179 = & V_2 -> V_7 . V_189 ;
F_25 () ;
#endif
}
V_176 -> V_177 -> V_3 |= V_3 ;
V_2 -> V_7 . V_84 |= V_3 ;
F_42 ( V_2 ) ;
return V_142 ;
}
static void F_90 ( struct V_1 * V_2 )
{
unsigned long V_190 ;
V_190 = V_2 -> V_7 . V_84 & ~ V_24 -> V_25 . V_177 -> V_3 ;
if ( ! V_190 )
return;
if ( V_190 & V_28 ) {
F_24 () ;
F_84 () ;
F_85 ( & V_2 -> V_7 . V_188 ) ;
F_86 () ;
F_25 () ;
}
#ifdef F_80
if ( V_190 & V_29 ) {
F_24 () ;
F_87 () ;
F_88 ( & V_2 -> V_7 . V_189 ) ;
F_89 () ;
F_25 () ;
}
#endif
V_24 -> V_25 . V_177 -> V_3 |= V_190 ;
}
static void F_91 ( struct V_1 * V_2 , T_1 V_180 )
{
V_2 -> V_7 . V_191 &= ~ ( 0xffULL << 56 ) ;
V_2 -> V_7 . V_191 |= ( V_180 << 56 ) ;
F_74 ( V_2 , V_192 ) ;
}
static void F_92 ( struct V_1 * V_2 , T_1 V_180 )
{
enum V_193 V_194 = V_195 ;
if ( ! ( F_2 ( V_2 ) & V_82 ) )
V_194 = F_93 ( V_2 -> V_136 , V_2 ) ;
if ( ( V_194 != V_196 ) && ( V_194 != V_197 ) ) {
F_91 ( V_2 , V_180 ) ;
}
}
static int F_94 ( struct V_1 * V_2 , T_1 V_180 )
{
bool V_198 ;
F_95 ( ! F_11 ( V_21 ) ) ;
switch ( V_180 ) {
case V_31 :
case V_199 :
V_198 = ( V_2 -> V_7 . V_191 & ( 1ULL << V_180 ) ) ;
break;
case V_200 :
V_198 = F_2 ( V_2 ) & V_201 ;
break;
default:
V_198 = false ;
break;
}
if ( ! V_198 ) {
F_91 ( V_2 , V_180 ) ;
return V_142 ;
}
switch ( V_180 ) {
case V_31 :
V_24 -> V_25 . V_181 = F_13 ( V_182 ) ;
F_12 ( V_182 , V_2 -> V_7 . V_181 ) ;
V_2 -> V_7 . V_38 |= V_183 ;
break;
default:
F_92 ( V_2 , V_180 ) ;
break;
}
return V_142 ;
}
void F_96 ( struct V_1 * V_2 , T_4 V_191 )
{
if ( ( V_2 -> V_7 . V_191 & V_183 ) && ! ( V_191 & V_183 ) ) {
F_20 ( V_2 , V_31 ) ;
}
V_2 -> V_7 . V_191 = V_191 ;
}
int F_97 ( struct V_135 * V_136 , struct V_1 * V_2 ,
unsigned int V_184 )
{
int V_52 = V_174 ;
int V_202 ;
V_2 -> V_95 . V_203 ++ ;
V_136 -> V_204 = V_205 ;
V_136 -> V_206 = 1 ;
F_98 ( V_184 , V_2 ) ;
F_99 () ;
switch ( V_184 ) {
case V_207 :
{
T_1 V_44 = V_2 -> V_7 . V_44 ;
V_2 -> V_95 . V_208 ++ ;
if ( F_1 ( V_2 ) )
F_3 ( V_2 ) ;
#ifdef F_15
{
struct V_13 * V_14 ;
T_5 V_209 ;
V_14 = F_8 ( V_2 ) ;
V_209 = V_14 -> V_209 [ F_4 ( V_2 ) >> V_158 ] ;
F_10 ( V_14 ) ;
if ( V_209 == V_210 ) {
F_50 ( V_2 , F_4 ( V_2 ) ) ;
V_52 = V_142 ;
break;
}
}
#endif
if ( V_44 & 0x40000000 ) {
int V_211 = F_100 ( & V_2 -> V_54 -> V_212 ) ;
V_52 = F_70 ( V_136 , V_2 , F_4 ( V_2 ) , V_184 ) ;
F_101 ( & V_2 -> V_54 -> V_212 , V_211 ) ;
V_2 -> V_95 . V_213 ++ ;
} else if ( V_2 -> V_7 . V_112 . V_113 ( V_2 ) &&
( ! ( V_2 -> V_7 . V_8 & V_111 ) ) ) {
F_28 ( V_2 , F_4 ( V_2 ) , ~ 0xFFFUL ) ;
V_52 = V_142 ;
} else {
T_4 V_3 = F_2 ( V_2 ) ;
V_3 |= V_44 & 0x58000000 ;
F_46 ( V_2 , V_3 ) ;
F_74 ( V_2 , V_184 ) ;
V_52 = V_142 ;
}
break;
}
case V_140 :
{
T_1 V_214 = F_72 ( V_2 ) ;
T_5 V_46 = V_2 -> V_7 . V_46 ;
V_2 -> V_95 . V_215 ++ ;
#ifdef F_15
{
struct V_13 * V_14 ;
T_5 V_209 ;
V_14 = F_8 ( V_2 ) ;
V_209 = V_14 -> V_209 [ V_214 >> V_158 ] ;
F_10 ( V_14 ) ;
if ( V_209 == V_210 ) {
F_50 ( V_2 , V_214 ) ;
V_52 = V_142 ;
break;
}
}
#endif
if ( V_46 & ( V_167 | V_168 ) ) {
int V_211 = F_100 ( & V_2 -> V_54 -> V_212 ) ;
V_52 = F_70 ( V_136 , V_2 , V_214 , V_184 ) ;
F_101 ( & V_2 -> V_54 -> V_212 , V_211 ) ;
} else {
F_71 ( V_2 , V_214 ) ;
F_73 ( V_2 , V_46 ) ;
F_74 ( V_2 , V_184 ) ;
V_52 = V_142 ;
}
break;
}
case V_216 :
if ( F_50 ( V_2 , F_72 ( V_2 ) ) < 0 ) {
F_71 ( V_2 , F_72 ( V_2 ) ) ;
F_74 ( V_2 ,
V_216 ) ;
}
V_52 = V_142 ;
break;
case V_217 :
if ( F_50 ( V_2 , F_4 ( V_2 ) ) < 0 ) {
F_74 ( V_2 ,
V_217 ) ;
}
V_52 = V_142 ;
break;
case V_218 :
case V_219 :
case V_220 :
case V_221 :
V_2 -> V_95 . V_222 ++ ;
V_52 = V_142 ;
break;
case V_223 :
case V_224 :
case V_225 :
V_2 -> V_95 . V_226 ++ ;
V_52 = V_142 ;
break;
case V_227 :
V_52 = V_142 ;
break;
case V_228 :
case V_229 :
{
enum V_193 V_194 ;
T_1 V_230 ;
T_5 V_47 ;
int V_231 ;
V_232:
V_230 = V_2 -> V_7 . V_44 & 0x1f0000ull ;
V_231 = F_102 ( V_2 , V_233 , & V_47 ) ;
if ( V_231 != V_196 ) {
V_52 = V_142 ;
break;
}
if ( F_2 ( V_2 ) & V_82 ) {
#ifdef F_44
F_103 ( L_6 ,
F_4 ( V_2 ) , V_47 ) ;
#endif
if ( ( V_47 & 0xff0007ff ) !=
( V_131 & 0xfffffff7 ) ) {
F_83 ( V_2 , V_230 ) ;
V_52 = V_142 ;
break;
}
}
V_2 -> V_95 . V_234 ++ ;
V_194 = F_93 ( V_136 , V_2 ) ;
switch ( V_194 ) {
case V_196 :
V_52 = V_235 ;
break;
case V_197 :
V_52 = V_142 ;
break;
case V_195 :
F_45 ( V_236 L_7 ,
V_237 , F_4 ( V_2 ) , V_47 ) ;
F_83 ( V_2 , V_230 ) ;
V_52 = V_142 ;
break;
case V_238 :
V_136 -> V_204 = V_239 ;
V_52 = V_173 ;
break;
case V_240 :
V_52 = V_173 ;
break;
default:
F_104 () ;
}
break;
}
case V_241 :
{
T_5 V_242 ;
int V_231 ;
if ( V_2 -> V_7 . V_243 ) {
V_231 = F_102 ( V_2 , V_244 , & V_242 ) ;
if ( V_231 != V_196 ) {
F_5 ( V_2 , F_4 ( V_2 ) - 4 ) ;
V_52 = V_142 ;
break;
}
}
if ( V_2 -> V_7 . V_243 &&
( V_242 == 0x44000022 ) &&
! ( F_2 ( V_2 ) & V_82 ) ) {
T_1 V_245 = F_105 ( V_2 , 3 ) ;
int V_57 ;
#ifdef F_7
if ( F_106 ( V_2 , V_245 ) == V_196 ) {
V_52 = V_142 ;
break;
}
#endif
V_136 -> V_246 . V_247 = V_245 ;
for ( V_57 = 0 ; V_57 < 9 ; ++ V_57 ) {
T_1 V_33 = F_105 ( V_2 , 4 + V_57 ) ;
V_136 -> V_246 . args [ V_57 ] = V_33 ;
}
V_136 -> V_204 = V_248 ;
V_2 -> V_7 . V_249 = 1 ;
V_52 = V_174 ;
} else if ( V_2 -> V_7 . V_250 &&
( ( ( T_5 ) F_105 ( V_2 , 3 ) ) == V_251 ) &&
( ( ( T_5 ) F_105 ( V_2 , 4 ) ) == V_252 ) ) {
T_4 * V_253 = V_136 -> V_254 . V_253 ;
int V_57 ;
V_136 -> V_204 = V_255 ;
for ( V_57 = 0 ; V_57 < 32 ; V_57 ++ )
V_253 [ V_57 ] = F_105 ( V_2 , V_57 ) ;
V_2 -> V_7 . V_256 = 1 ;
V_52 = V_173 ;
} else if ( ! ( F_2 ( V_2 ) & V_82 ) &&
( ( ( T_5 ) F_105 ( V_2 , 0 ) ) == V_257 ) ) {
F_107 ( V_2 , 3 , F_108 ( V_2 ) ) ;
V_52 = V_142 ;
} else {
V_2 -> V_95 . V_258 ++ ;
F_74 ( V_2 , V_184 ) ;
V_52 = V_142 ;
}
break;
}
case V_102 :
case V_259 :
case V_260 :
{
int V_261 = 0 ;
int V_231 ;
T_5 V_47 ;
if ( V_2 -> V_7 . V_8 & V_185 ) {
V_231 = F_102 ( V_2 , V_233 ,
& V_47 ) ;
if ( V_231 == V_196 )
goto V_232;
else
V_52 = V_142 ;
break;
}
switch ( V_184 ) {
case V_102 :
V_261 = V_28 ;
break;
case V_259 :
V_261 = V_29 ;
break;
case V_260 :
V_261 = V_30 ;
break;
}
V_52 = F_51 ( V_2 , V_184 , V_261 ) ;
break;
}
case V_262 :
{
T_5 V_47 ;
int V_231 = F_102 ( V_2 , V_233 , & V_47 ) ;
if ( V_231 == V_196 ) {
T_5 V_166 ;
T_4 V_214 ;
V_166 = F_109 ( V_2 , V_47 ) ;
V_214 = F_110 ( V_2 , V_47 ) ;
F_73 ( V_2 , V_166 ) ;
F_71 ( V_2 , V_214 ) ;
F_74 ( V_2 , V_184 ) ;
}
V_52 = V_142 ;
break;
}
#ifdef F_7
case V_192 :
F_94 ( V_2 , V_2 -> V_7 . V_38 >> 56 ) ;
V_52 = V_142 ;
break;
#endif
case V_263 :
case V_264 :
F_74 ( V_2 , V_184 ) ;
V_52 = V_142 ;
break;
default:
{
T_1 V_44 = V_2 -> V_7 . V_44 ;
F_45 ( V_265 L_8 ,
V_184 , F_4 ( V_2 ) , V_44 ) ;
V_52 = V_174 ;
F_104 () ;
break;
}
}
if ( ! ( V_52 & V_174 ) ) {
V_202 = F_111 ( V_2 ) ;
if ( V_202 <= 0 )
V_52 = V_202 ;
else {
F_112 () ;
}
F_90 ( V_2 ) ;
}
F_113 ( V_52 , V_2 ) ;
return V_52 ;
}
static int F_114 ( struct V_1 * V_2 ,
struct V_266 * V_267 )
{
struct V_268 * V_269 = F_9 ( V_2 ) ;
int V_57 ;
V_267 -> V_103 = V_2 -> V_7 . V_103 ;
V_267 -> V_270 . V_202 . V_271 = F_9 ( V_2 ) -> V_271 ;
if ( V_2 -> V_7 . V_8 & V_105 ) {
for ( V_57 = 0 ; V_57 < 64 ; V_57 ++ ) {
V_267 -> V_270 . V_202 . V_272 . V_15 [ V_57 ] . V_273 = V_2 -> V_7 . V_15 [ V_57 ] . V_274 | V_57 ;
V_267 -> V_270 . V_202 . V_272 . V_15 [ V_57 ] . V_275 = V_2 -> V_7 . V_15 [ V_57 ] . V_276 ;
}
} else {
for ( V_57 = 0 ; V_57 < 16 ; V_57 ++ )
V_267 -> V_270 . V_202 . V_277 . V_209 [ V_57 ] = F_115 ( V_2 , V_57 ) ;
for ( V_57 = 0 ; V_57 < 8 ; V_57 ++ ) {
V_267 -> V_270 . V_202 . V_277 . V_278 [ V_57 ] = V_269 -> V_278 [ V_57 ] . V_279 ;
V_267 -> V_270 . V_202 . V_277 . V_280 [ V_57 ] = V_269 -> V_280 [ V_57 ] . V_279 ;
}
}
return 0 ;
}
static int F_116 ( struct V_1 * V_2 ,
struct V_266 * V_267 )
{
struct V_268 * V_269 = F_9 ( V_2 ) ;
int V_57 ;
F_52 ( V_2 , V_267 -> V_103 ) ;
V_269 -> V_271 = V_267 -> V_270 . V_202 . V_271 ;
if ( V_2 -> V_7 . V_8 & V_105 ) {
for ( V_57 = 0 ; V_57 < 64 ; V_57 ++ ) {
V_2 -> V_7 . V_112 . V_281 ( V_2 , V_267 -> V_270 . V_202 . V_272 . V_15 [ V_57 ] . V_275 ,
V_267 -> V_270 . V_202 . V_272 . V_15 [ V_57 ] . V_273 ) ;
}
} else {
for ( V_57 = 0 ; V_57 < 16 ; V_57 ++ ) {
V_2 -> V_7 . V_112 . V_282 ( V_2 , V_57 , V_267 -> V_270 . V_202 . V_277 . V_209 [ V_57 ] ) ;
}
for ( V_57 = 0 ; V_57 < 8 ; V_57 ++ ) {
F_117 ( V_2 , & ( V_269 -> V_278 [ V_57 ] ) , false ,
( T_5 ) V_267 -> V_270 . V_202 . V_277 . V_278 [ V_57 ] ) ;
F_117 ( V_2 , & ( V_269 -> V_278 [ V_57 ] ) , true ,
( T_5 ) ( V_267 -> V_270 . V_202 . V_277 . V_278 [ V_57 ] >> 32 ) ) ;
F_117 ( V_2 , & ( V_269 -> V_280 [ V_57 ] ) , false ,
( T_5 ) V_267 -> V_270 . V_202 . V_277 . V_280 [ V_57 ] ) ;
F_117 ( V_2 , & ( V_269 -> V_280 [ V_57 ] ) , true ,
( T_5 ) ( V_267 -> V_270 . V_202 . V_277 . V_280 [ V_57 ] >> 32 ) ) ;
}
}
F_28 ( V_2 , 0 , 0 ) ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 , T_4 V_283 ,
union V_284 * V_285 )
{
int V_52 = 0 ;
switch ( V_283 ) {
case V_286 :
* V_285 = F_119 ( V_283 , V_287 ) ;
break;
case V_288 :
* V_285 = F_119 ( V_283 , F_9 ( V_2 ) -> V_107 ) ;
break;
case V_289 :
case V_290 :
if ( V_2 -> V_7 . V_291 & V_79 )
* V_285 = F_119 ( V_283 , V_292 ) ;
else
* V_285 = F_119 ( V_283 , 0 ) ;
break;
default:
V_52 = - V_162 ;
break;
}
return V_52 ;
}
static void F_120 ( struct V_1 * V_2 , T_4 V_293 )
{
if ( V_293 & V_292 )
V_2 -> V_7 . V_291 |= V_79 ;
else
V_2 -> V_7 . V_291 &= ~ V_79 ;
}
static int F_121 ( struct V_1 * V_2 , T_4 V_283 ,
union V_284 * V_285 )
{
int V_52 = 0 ;
switch ( V_283 ) {
case V_288 :
F_9 ( V_2 ) -> V_107 = F_122 ( V_283 , * V_285 ) ;
F_9 ( V_2 ) -> V_106 = true ;
break;
case V_289 :
case V_290 :
F_120 ( V_2 , F_122 ( V_283 , * V_285 ) ) ;
break;
default:
V_52 = - V_162 ;
break;
}
return V_52 ;
}
static struct V_1 * F_123 ( struct V_54 * V_54 ,
unsigned int V_283 )
{
struct V_268 * V_294 ;
struct V_1 * V_2 ;
int V_295 = - V_296 ;
unsigned long V_297 ;
V_2 = F_124 ( V_298 , V_299 ) ;
if ( ! V_2 )
goto V_43;
V_294 = F_125 ( sizeof( struct V_268 ) ) ;
if ( ! V_294 )
goto V_300;
V_2 -> V_7 . V_301 = V_294 ;
#ifdef F_126
V_2 -> V_7 . V_27 =
F_127 ( sizeof( * V_2 -> V_7 . V_27 ) , V_299 ) ;
if ( ! V_2 -> V_7 . V_27 )
goto V_302;
#endif
V_295 = F_128 ( V_2 , V_54 , V_283 ) ;
if ( V_295 )
goto V_303;
V_295 = - V_296 ;
V_297 = F_129 ( V_299 | V_304 ) ;
if ( ! V_297 )
goto V_305;
V_2 -> V_7 . V_306 = ( void * ) V_297 ;
#ifdef F_7
#ifdef F_130
V_2 -> V_7 . V_307 = true ;
#else
V_2 -> V_7 . V_307 = false ;
#endif
V_2 -> V_7 . V_103 = 0x3C0301 ;
if ( F_131 ( V_308 ) )
V_2 -> V_7 . V_103 = F_13 ( V_309 ) ;
V_2 -> V_7 . V_291 = V_76 ;
#else
V_2 -> V_7 . V_103 = 0x84202 ;
#endif
F_52 ( V_2 , V_2 -> V_7 . V_103 ) ;
V_2 -> V_7 . V_310 = 64 ;
V_2 -> V_7 . V_87 = V_311 & ~ V_79 ;
V_295 = F_132 ( V_2 ) ;
if ( V_295 < 0 )
goto V_305;
return V_2 ;
V_305:
F_133 ( V_2 ) ;
V_303:
#ifdef F_126
F_134 ( V_2 -> V_7 . V_27 ) ;
V_302:
#endif
F_135 ( V_294 ) ;
V_300:
F_136 ( V_298 , V_2 ) ;
V_43:
return F_137 ( V_295 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
struct V_268 * V_294 = F_9 ( V_2 ) ;
F_139 ( ( unsigned long ) V_2 -> V_7 . V_306 & V_129 ) ;
F_133 ( V_2 ) ;
#ifdef F_126
F_134 ( V_2 -> V_7 . V_27 ) ;
#endif
F_135 ( V_294 ) ;
F_136 ( V_298 , V_2 ) ;
}
static int F_140 ( struct V_135 * V_135 , struct V_1 * V_2 )
{
int V_312 ;
#ifdef F_80
unsigned long V_313 ( V_314 ) ;
#endif
if ( ! V_2 -> V_7 . V_315 ) {
V_135 -> V_204 = V_316 ;
V_312 = - V_162 ;
goto V_43;
}
V_312 = F_111 ( V_2 ) ;
if ( V_312 <= 0 )
goto V_43;
F_141 ( V_24 ) ;
if ( F_2 ( V_2 ) & V_28 )
F_51 ( V_2 , V_102 , V_28 ) ;
F_112 () ;
V_312 = F_142 ( V_135 , V_2 ) ;
F_19 ( V_2 , V_28 | V_29 | V_30 ) ;
F_20 ( V_2 , V_31 ) ;
V_43:
V_2 -> V_317 = V_318 ;
return V_312 ;
}
static int F_143 ( struct V_54 * V_54 ,
struct V_319 * log )
{
struct V_58 * V_59 ;
struct V_60 * V_61 ;
struct V_1 * V_2 ;
T_1 V_320 , V_321 ;
int V_322 = 0 ;
int V_52 ;
unsigned long V_323 ;
F_144 ( & V_54 -> V_324 ) ;
V_52 = F_145 ( V_54 , log , & V_322 ) ;
if ( V_52 )
goto V_43;
if ( V_322 ) {
V_59 = V_58 ( V_54 ) ;
V_61 = F_146 ( V_59 , log -> V_325 ) ;
V_320 = V_61 -> V_326 << V_68 ;
V_321 = V_320 + ( V_61 -> V_67 << V_68 ) ;
F_34 (n, vcpu, kvm)
F_35 ( V_2 , V_320 , V_321 ) ;
V_323 = F_147 ( V_61 ) ;
memset ( V_61 -> V_327 , 0 , V_323 ) ;
}
V_52 = 0 ;
V_43:
F_148 ( & V_54 -> V_324 ) ;
return V_52 ;
}
static void F_149 ( struct V_54 * V_54 ,
struct V_60 * V_61 )
{
return;
}
static int F_150 ( struct V_54 * V_54 ,
struct V_60 * V_61 ,
const struct V_328 * V_329 )
{
return 0 ;
}
static void F_151 ( struct V_54 * V_54 ,
const struct V_328 * V_329 ,
const struct V_60 * V_330 ,
const struct V_60 * V_331 )
{
return;
}
static void F_152 ( struct V_60 * free ,
struct V_60 * V_332 )
{
return;
}
static int F_153 ( struct V_60 * V_325 ,
unsigned long V_67 )
{
return 0 ;
}
static int F_154 ( struct V_54 * V_54 ,
struct V_333 * V_334 )
{
long int V_57 ;
struct V_1 * V_2 ;
V_334 -> V_230 = 0 ;
V_334 -> V_335 = 64 ;
V_334 -> V_336 [ 0 ] . V_337 = 12 ;
V_334 -> V_336 [ 0 ] . V_338 = 0 ;
V_334 -> V_336 [ 0 ] . V_339 [ 0 ] . V_337 = 12 ;
V_334 -> V_336 [ 0 ] . V_339 [ 0 ] . V_340 = 0 ;
V_57 = 1 ;
V_2 = F_155 ( V_54 , 0 ) ;
if ( V_2 && ( V_2 -> V_7 . V_8 & V_120 ) ) {
V_334 -> V_230 = V_341 ;
V_334 -> V_336 [ V_57 ] . V_337 = 16 ;
V_334 -> V_336 [ V_57 ] . V_338 = V_342 | V_343 ;
V_334 -> V_336 [ V_57 ] . V_339 [ 0 ] . V_337 = 16 ;
V_334 -> V_336 [ V_57 ] . V_339 [ 0 ] . V_340 = 1 ;
++ V_57 ;
}
V_334 -> V_336 [ V_57 ] . V_337 = 24 ;
V_334 -> V_336 [ V_57 ] . V_338 = V_342 ;
V_334 -> V_336 [ V_57 ] . V_339 [ 0 ] . V_337 = 24 ;
V_334 -> V_336 [ V_57 ] . V_339 [ 0 ] . V_340 = 0 ;
return 0 ;
}
static int F_154 ( struct V_54 * V_54 ,
struct V_333 * V_334 )
{
F_104 () ;
}
static int F_156 ( struct V_54 * V_54 )
{
F_157 ( & V_54 -> V_7 . V_344 ) ;
#ifdef F_7
F_158 ( V_54 ) ;
#endif
if ( F_159 ( V_345 ) ) {
F_160 ( & V_346 ) ;
if ( ++ V_347 == 1 )
F_161 () ;
F_162 ( & V_346 ) ;
}
return 0 ;
}
static void F_163 ( struct V_54 * V_54 )
{
#ifdef F_164
F_165 ( ! F_166 ( & V_54 -> V_7 . V_348 ) ) ;
#endif
if ( F_159 ( V_345 ) ) {
F_160 ( & V_346 ) ;
F_95 ( V_347 == 0 ) ;
if ( -- V_347 == 0 )
F_167 () ;
F_162 ( & V_346 ) ;
}
}
static int F_168 ( void )
{
return 0 ;
}
static long F_169 ( struct V_349 * V_350 ,
unsigned int V_351 , unsigned long V_352 )
{
return - V_353 ;
}
int F_170 ( void )
{
int V_52 ;
V_52 = F_168 () ;
if ( V_52 < 0 )
return V_52 ;
V_354 . V_355 = V_356 ;
V_357 = & V_354 ;
V_52 = F_171 () ;
return V_52 ;
}
void F_172 ( void )
{
V_357 = NULL ;
F_173 () ;
}
