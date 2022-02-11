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
F_9 ( V_2 ) -> V_50 += F_23 () - V_2 -> V_7 . V_40 ;
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
case V_120 :
case V_121 :
V_2 -> V_7 . V_8 |= V_122 |
V_123 ;
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
V_2 -> V_7 . V_8 |= V_124 ;
F_12 ( V_125 , F_13 ( V_125 ) | ( 1 << 29 ) ) ;
}
}
static void F_58 ( struct V_1 * V_2 , struct V_126 * V_71 )
{
struct V_127 * V_128 ;
T_4 V_129 ;
T_5 * V_127 ;
int V_57 ;
V_128 = F_59 ( V_2 -> V_54 , V_71 -> V_130 >> V_68 ) ;
if ( F_60 ( V_128 ) )
return;
V_129 = V_71 -> V_130 & ~ V_131 ;
V_129 &= ~ 0xFFFULL ;
V_129 /= 4 ;
F_61 ( V_128 ) ;
V_127 = F_62 ( V_128 ) ;
for ( V_57 = V_129 ; V_57 < V_129 + ( V_132 / 4 ) ; V_57 ++ )
if ( ( F_63 ( V_127 [ V_57 ] ) & 0xff0007ff ) == V_133 )
V_127 [ V_57 ] &= F_64 ( 0xfffffff7 ) ;
F_65 ( V_127 ) ;
F_66 ( V_128 ) ;
}
static bool F_67 ( struct V_1 * V_2 , T_6 V_134 )
{
T_1 V_135 = V_2 -> V_7 . V_97 ;
if ( ! ( F_2 ( V_2 ) & V_76 ) )
V_135 = ( V_101 ) V_135 ;
V_134 &= ~ 0xFFFULL ;
if ( F_68 ( V_135 ) && F_68 ( ( V_135 & V_136 ) == ( V_134 & V_136 ) ) ) {
return true ;
}
return F_69 ( V_2 -> V_54 , V_134 >> V_68 ) ;
}
int F_70 ( struct V_137 * V_138 , struct V_1 * V_2 ,
T_1 V_139 , int V_140 )
{
bool V_141 = ( V_140 == V_142 ) ;
bool V_143 = false ;
int V_52 = V_144 ;
int V_145 ;
int V_146 = 0 ;
struct V_126 V_71 ;
bool V_147 = false ;
bool V_148 = ( F_2 ( V_2 ) & V_5 ) ? true : false ;
bool V_149 = ( F_2 ( V_2 ) & V_4 ) ? true : false ;
T_4 V_150 ;
V_145 = V_141 ? V_148 : V_149 ;
if ( V_141 && ( V_2 -> V_7 . V_46 & V_151 ) )
V_143 = true ;
if ( V_145 ) {
V_146 = V_2 -> V_7 . V_112 . V_152 ( V_2 , V_139 , & V_71 , V_141 , V_143 ) ;
} else {
V_71 . V_153 = true ;
V_71 . V_154 = true ;
V_71 . V_155 = true ;
V_71 . V_130 = V_139 & V_136 ;
V_71 . V_139 = V_139 ;
V_71 . V_156 = V_139 >> 12 ;
V_71 . V_157 = V_158 ;
}
switch ( F_2 ( V_2 ) & ( V_5 | V_4 ) ) {
case 0 :
V_71 . V_156 |= ( ( T_4 ) V_159 << ( V_160 - 12 ) ) ;
break;
case V_5 :
if ( ! V_141 &&
( V_2 -> V_7 . V_8 & V_9 ) &&
( ( V_71 . V_130 & V_10 ) == V_11 ) )
V_71 . V_130 &= ~ V_10 ;
case V_4 :
V_2 -> V_7 . V_112 . V_161 ( V_2 , V_139 >> V_160 , & V_150 ) ;
if ( ( F_2 ( V_2 ) & ( V_5 | V_4 ) ) == V_5 )
V_71 . V_156 |= ( ( T_4 ) V_162 << ( V_160 - 12 ) ) ;
else
V_71 . V_156 |= ( ( T_4 ) V_163 << ( V_160 - 12 ) ) ;
V_71 . V_156 |= V_150 ;
if ( V_150 == - 1 )
V_146 = - V_164 ;
break;
}
if ( V_2 -> V_7 . V_112 . V_113 ( V_2 ) &&
( ! ( V_2 -> V_7 . V_8 & V_111 ) ) ) {
V_71 . V_153 = ! V_141 ;
}
if ( V_146 == - V_165 ) {
T_4 V_166 = V_2 -> V_7 . V_44 ;
T_4 V_3 = F_2 ( V_2 ) ;
F_71 ( V_2 , F_72 ( V_2 ) ) ;
F_73 ( V_2 , V_2 -> V_7 . V_46 ) ;
F_46 ( V_2 , V_3 | ( V_166 & 0xf8000000ULL ) ) ;
F_74 ( V_2 , V_140 ) ;
} else if ( V_146 == - V_167 ) {
T_5 V_168 = V_2 -> V_7 . V_46 ;
T_4 V_166 = V_2 -> V_7 . V_44 ;
T_4 V_3 = F_2 ( V_2 ) ;
F_71 ( V_2 , F_72 ( V_2 ) ) ;
V_168 = ( V_168 & ~ V_169 ) | V_170 ;
F_73 ( V_2 , V_168 ) ;
F_46 ( V_2 , V_3 | ( V_166 & 0xf8000000ULL ) ) ;
F_74 ( V_2 , V_140 ) ;
} else if ( V_146 == - V_164 ) {
F_71 ( V_2 , F_72 ( V_2 ) ) ;
F_74 ( V_2 , V_140 + 0x80 ) ;
} else if ( ! V_147 &&
F_67 ( V_2 , V_71 . V_130 ) ) {
if ( V_141 && ! ( V_2 -> V_7 . V_46 & V_169 ) ) {
F_75 ( V_2 , & V_71 ) ;
}
F_76 ( V_2 , & V_71 , V_143 ) ;
if ( V_141 )
V_2 -> V_95 . V_171 ++ ;
else if ( V_2 -> V_7 . V_112 . V_113 ( V_2 ) &&
( ! ( V_2 -> V_7 . V_8 & V_111 ) ) )
F_58 ( V_2 , & V_71 ) ;
} else {
V_2 -> V_95 . V_172 ++ ;
V_2 -> V_7 . V_173 = V_71 . V_130 ;
V_2 -> V_7 . V_174 = V_71 . V_139 ;
V_52 = F_77 ( V_138 , V_2 ) ;
if ( V_52 == V_175 )
V_52 = V_176 ;
}
return V_52 ;
}
void F_19 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_177 * V_178 = & V_24 -> V_25 ;
if ( V_3 & V_30 )
V_3 |= V_28 | V_29 ;
V_3 &= V_2 -> V_7 . V_84 ;
if ( ! V_3 )
return;
#ifdef F_78
F_45 ( V_89 L_4 , V_3 ) ;
#endif
if ( V_3 & V_28 ) {
if ( V_178 -> V_179 -> V_3 & V_28 )
F_79 ( V_24 ) ;
V_178 -> V_180 = NULL ;
}
#ifdef F_80
if ( V_3 & V_29 ) {
if ( V_24 -> V_25 . V_179 -> V_3 & V_29 )
F_81 ( V_24 ) ;
V_178 -> V_181 = NULL ;
}
#endif
V_2 -> V_7 . V_84 &= ~ ( V_3 | V_30 ) ;
F_42 ( V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_182 )
{
#ifdef F_7
if ( ! ( V_2 -> V_7 . V_38 & ( 1ULL << V_182 ) ) ) {
return;
}
switch ( V_182 ) {
case V_31 :
V_2 -> V_7 . V_183 = F_13 ( V_184 ) ;
F_12 ( V_184 , V_24 -> V_25 . V_183 ) ;
V_2 -> V_7 . V_38 &= ~ V_185 ;
break;
}
#endif
}
static int F_51 ( struct V_1 * V_2 , unsigned int V_186 ,
T_1 V_3 )
{
struct V_177 * V_178 = & V_24 -> V_25 ;
if ( V_2 -> V_7 . V_8 & V_187 )
return V_144 ;
if ( ! ( F_2 ( V_2 ) & V_3 ) ) {
F_74 ( V_2 , V_186 ) ;
return V_144 ;
}
if ( V_3 == V_30 ) {
#ifdef F_82
if ( ! F_11 ( V_188 ) )
#endif
{
F_83 ( V_2 , V_189 ) ;
return V_144 ;
}
V_3 = V_28 | V_29 | V_30 ;
}
V_3 &= ~ V_2 -> V_7 . V_84 ;
if ( ! V_3 )
return V_144 ;
#ifdef F_78
F_45 ( V_89 L_5 , V_3 ) ;
#endif
if ( V_3 & V_28 ) {
F_24 () ;
F_84 () ;
F_85 ( & V_2 -> V_7 . V_190 ) ;
F_86 () ;
V_178 -> V_180 = & V_2 -> V_7 . V_190 ;
F_25 () ;
}
if ( V_3 & V_29 ) {
#ifdef F_80
F_24 () ;
F_87 () ;
F_88 ( & V_2 -> V_7 . V_191 ) ;
F_89 () ;
V_178 -> V_181 = & V_2 -> V_7 . V_191 ;
F_25 () ;
#endif
}
V_178 -> V_179 -> V_3 |= V_3 ;
V_2 -> V_7 . V_84 |= V_3 ;
F_42 ( V_2 ) ;
return V_144 ;
}
static void F_90 ( struct V_1 * V_2 )
{
unsigned long V_192 ;
V_192 = V_2 -> V_7 . V_84 & ~ V_24 -> V_25 . V_179 -> V_3 ;
if ( ! V_192 )
return;
if ( V_192 & V_28 ) {
F_24 () ;
F_84 () ;
F_85 ( & V_2 -> V_7 . V_190 ) ;
F_86 () ;
F_25 () ;
}
#ifdef F_80
if ( V_192 & V_29 ) {
F_24 () ;
F_87 () ;
F_88 ( & V_2 -> V_7 . V_191 ) ;
F_89 () ;
F_25 () ;
}
#endif
V_24 -> V_25 . V_179 -> V_3 |= V_192 ;
}
static void F_91 ( struct V_1 * V_2 , T_1 V_182 )
{
V_2 -> V_7 . V_193 &= ~ ( 0xffULL << 56 ) ;
V_2 -> V_7 . V_193 |= ( V_182 << 56 ) ;
F_74 ( V_2 , V_194 ) ;
}
static void F_92 ( struct V_1 * V_2 , T_1 V_182 )
{
enum V_195 V_196 = V_197 ;
if ( ! ( F_2 ( V_2 ) & V_82 ) )
V_196 = F_93 ( V_2 -> V_138 , V_2 ) ;
if ( ( V_196 != V_198 ) && ( V_196 != V_199 ) ) {
F_91 ( V_2 , V_182 ) ;
}
}
static int F_94 ( struct V_1 * V_2 , T_1 V_182 )
{
bool V_200 ;
F_95 ( ! F_11 ( V_21 ) ) ;
switch ( V_182 ) {
case V_31 :
case V_201 :
V_200 = ( V_2 -> V_7 . V_193 & ( 1ULL << V_182 ) ) ;
break;
case V_202 :
V_200 = F_2 ( V_2 ) & V_203 ;
break;
default:
V_200 = false ;
break;
}
if ( ! V_200 ) {
F_91 ( V_2 , V_182 ) ;
return V_144 ;
}
switch ( V_182 ) {
case V_31 :
V_24 -> V_25 . V_183 = F_13 ( V_184 ) ;
F_12 ( V_184 , V_2 -> V_7 . V_183 ) ;
V_2 -> V_7 . V_38 |= V_185 ;
break;
default:
F_92 ( V_2 , V_182 ) ;
break;
}
return V_144 ;
}
void F_96 ( struct V_1 * V_2 , T_4 V_193 )
{
if ( ( V_2 -> V_7 . V_193 & V_185 ) && ! ( V_193 & V_185 ) ) {
F_20 ( V_2 , V_31 ) ;
}
V_2 -> V_7 . V_193 = V_193 ;
}
static void F_97 ( struct V_1 * V_2 )
{
if ( V_2 -> V_204 & V_205 ) {
T_4 V_3 = F_2 ( V_2 ) ;
F_98 ( V_2 , V_3 | V_77 ) ;
}
}
static void F_99 ( struct V_1 * V_2 )
{
if ( V_2 -> V_204 & V_205 ) {
T_4 V_3 = F_2 ( V_2 ) ;
F_98 ( V_2 , V_3 & ~ V_77 ) ;
}
}
int F_100 ( struct V_137 * V_138 , struct V_1 * V_2 ,
unsigned int V_186 )
{
int V_52 = V_176 ;
int V_206 ;
V_2 -> V_95 . V_207 ++ ;
V_138 -> V_208 = V_209 ;
V_138 -> V_210 = 1 ;
F_101 ( V_186 , V_2 ) ;
F_102 () ;
switch ( V_186 ) {
case V_211 :
{
T_1 V_44 = V_2 -> V_7 . V_44 ;
V_2 -> V_95 . V_212 ++ ;
if ( F_1 ( V_2 ) )
F_3 ( V_2 ) ;
#ifdef F_15
{
struct V_13 * V_14 ;
T_5 V_213 ;
V_14 = F_8 ( V_2 ) ;
V_213 = V_14 -> V_213 [ F_4 ( V_2 ) >> V_160 ] ;
F_10 ( V_14 ) ;
if ( V_213 == V_214 ) {
F_50 ( V_2 , F_4 ( V_2 ) ) ;
V_52 = V_144 ;
break;
}
}
#endif
if ( V_44 & 0x40000000 ) {
int V_215 = F_103 ( & V_2 -> V_54 -> V_216 ) ;
V_52 = F_70 ( V_138 , V_2 , F_4 ( V_2 ) , V_186 ) ;
F_104 ( & V_2 -> V_54 -> V_216 , V_215 ) ;
V_2 -> V_95 . V_217 ++ ;
} else if ( V_2 -> V_7 . V_112 . V_113 ( V_2 ) &&
( ! ( V_2 -> V_7 . V_8 & V_111 ) ) ) {
F_28 ( V_2 , F_4 ( V_2 ) , ~ 0xFFFUL ) ;
V_52 = V_144 ;
} else {
T_4 V_3 = F_2 ( V_2 ) ;
V_3 |= V_44 & 0x58000000 ;
F_46 ( V_2 , V_3 ) ;
F_74 ( V_2 , V_186 ) ;
V_52 = V_144 ;
}
break;
}
case V_142 :
{
T_1 V_218 = F_72 ( V_2 ) ;
T_5 V_46 = V_2 -> V_7 . V_46 ;
V_2 -> V_95 . V_219 ++ ;
#ifdef F_15
{
struct V_13 * V_14 ;
T_5 V_213 ;
V_14 = F_8 ( V_2 ) ;
V_213 = V_14 -> V_213 [ V_218 >> V_160 ] ;
F_10 ( V_14 ) ;
if ( V_213 == V_214 ) {
F_50 ( V_2 , V_218 ) ;
V_52 = V_144 ;
break;
}
}
#endif
if ( V_46 & ( V_169 | V_170 ) ) {
int V_215 = F_103 ( & V_2 -> V_54 -> V_216 ) ;
V_52 = F_70 ( V_138 , V_2 , V_218 , V_186 ) ;
F_104 ( & V_2 -> V_54 -> V_216 , V_215 ) ;
} else {
F_71 ( V_2 , V_218 ) ;
F_73 ( V_2 , V_46 ) ;
F_74 ( V_2 , V_186 ) ;
V_52 = V_144 ;
}
break;
}
case V_220 :
if ( F_50 ( V_2 , F_72 ( V_2 ) ) < 0 ) {
F_71 ( V_2 , F_72 ( V_2 ) ) ;
F_74 ( V_2 ,
V_220 ) ;
}
V_52 = V_144 ;
break;
case V_221 :
if ( F_50 ( V_2 , F_4 ( V_2 ) ) < 0 ) {
F_74 ( V_2 ,
V_221 ) ;
}
V_52 = V_144 ;
break;
case V_222 :
case V_223 :
case V_224 :
case V_225 :
V_2 -> V_95 . V_226 ++ ;
V_52 = V_144 ;
break;
case V_227 :
case V_228 :
case V_229 :
V_2 -> V_95 . V_230 ++ ;
V_52 = V_144 ;
break;
case V_231 :
V_52 = V_144 ;
break;
case V_232 :
case V_233 :
{
enum V_195 V_196 ;
T_1 V_234 ;
T_5 V_47 ;
int V_235 ;
V_236:
if ( V_186 == V_232 )
V_234 = V_2 -> V_7 . V_44 & 0x1f0000ull ;
else
V_234 = V_189 ;
V_235 = F_105 ( V_2 , V_237 , & V_47 ) ;
if ( V_235 != V_198 ) {
V_52 = V_144 ;
break;
}
if ( F_2 ( V_2 ) & V_82 ) {
#ifdef F_44
F_106 ( L_6 ,
F_4 ( V_2 ) , V_47 ) ;
#endif
if ( ( V_47 & 0xff0007ff ) !=
( V_133 & 0xfffffff7 ) ) {
F_83 ( V_2 , V_234 ) ;
V_52 = V_144 ;
break;
}
}
V_2 -> V_95 . V_238 ++ ;
V_196 = F_93 ( V_138 , V_2 ) ;
switch ( V_196 ) {
case V_198 :
V_52 = V_239 ;
break;
case V_199 :
V_52 = V_144 ;
break;
case V_197 :
F_45 ( V_240 L_7 ,
V_241 , F_4 ( V_2 ) , V_47 ) ;
F_83 ( V_2 , V_234 ) ;
V_52 = V_144 ;
break;
case V_242 :
V_138 -> V_208 = V_243 ;
V_52 = V_175 ;
break;
case V_244 :
V_52 = V_175 ;
break;
default:
F_107 () ;
}
break;
}
case V_245 :
{
T_5 V_246 ;
int V_235 ;
if ( V_2 -> V_7 . V_247 ) {
V_235 = F_105 ( V_2 , V_248 , & V_246 ) ;
if ( V_235 != V_198 ) {
F_5 ( V_2 , F_4 ( V_2 ) - 4 ) ;
V_52 = V_144 ;
break;
}
}
if ( V_2 -> V_7 . V_247 &&
( V_246 == 0x44000022 ) &&
! ( F_2 ( V_2 ) & V_82 ) ) {
T_1 V_249 = F_108 ( V_2 , 3 ) ;
int V_57 ;
#ifdef F_7
if ( F_109 ( V_2 , V_249 ) == V_198 ) {
V_52 = V_144 ;
break;
}
#endif
V_138 -> V_250 . V_251 = V_249 ;
for ( V_57 = 0 ; V_57 < 9 ; ++ V_57 ) {
T_1 V_33 = F_108 ( V_2 , 4 + V_57 ) ;
V_138 -> V_250 . args [ V_57 ] = V_33 ;
}
V_138 -> V_208 = V_252 ;
V_2 -> V_7 . V_253 = 1 ;
V_52 = V_176 ;
} else if ( V_2 -> V_7 . V_254 &&
( ( ( T_5 ) F_108 ( V_2 , 3 ) ) == V_255 ) &&
( ( ( T_5 ) F_108 ( V_2 , 4 ) ) == V_256 ) ) {
T_4 * V_257 = V_138 -> V_258 . V_257 ;
int V_57 ;
V_138 -> V_208 = V_259 ;
for ( V_57 = 0 ; V_57 < 32 ; V_57 ++ )
V_257 [ V_57 ] = F_108 ( V_2 , V_57 ) ;
V_2 -> V_7 . V_260 = 1 ;
V_52 = V_175 ;
} else if ( ! ( F_2 ( V_2 ) & V_82 ) &&
( ( ( T_5 ) F_108 ( V_2 , 0 ) ) == V_261 ) ) {
F_110 ( V_2 , 3 , F_111 ( V_2 ) ) ;
V_52 = V_144 ;
} else {
V_2 -> V_95 . V_262 ++ ;
F_74 ( V_2 , V_186 ) ;
V_52 = V_144 ;
}
break;
}
case V_102 :
case V_263 :
case V_264 :
{
int V_265 = 0 ;
int V_235 ;
T_5 V_47 ;
if ( V_2 -> V_7 . V_8 & V_187 ) {
V_235 = F_105 ( V_2 , V_237 ,
& V_47 ) ;
if ( V_235 == V_198 )
goto V_236;
else
V_52 = V_144 ;
break;
}
switch ( V_186 ) {
case V_102 :
V_265 = V_28 ;
break;
case V_263 :
V_265 = V_29 ;
break;
case V_264 :
V_265 = V_30 ;
break;
}
V_52 = F_51 ( V_2 , V_186 , V_265 ) ;
break;
}
case V_266 :
{
T_5 V_47 ;
int V_235 = F_105 ( V_2 , V_237 , & V_47 ) ;
if ( V_235 == V_198 ) {
T_5 V_168 ;
T_4 V_218 ;
V_168 = F_112 ( V_2 , V_47 ) ;
V_218 = F_113 ( V_2 , V_47 ) ;
F_73 ( V_2 , V_168 ) ;
F_71 ( V_2 , V_218 ) ;
F_74 ( V_2 , V_186 ) ;
}
V_52 = V_144 ;
break;
}
#ifdef F_7
case V_194 :
F_94 ( V_2 , V_2 -> V_7 . V_38 >> 56 ) ;
V_52 = V_144 ;
break;
#endif
case V_267 :
F_74 ( V_2 , V_186 ) ;
V_52 = V_144 ;
break;
case V_268 :
if ( V_2 -> V_204 & V_205 ) {
V_138 -> V_208 = V_269 ;
V_52 = V_176 ;
} else {
F_74 ( V_2 , V_186 ) ;
V_52 = V_144 ;
}
break;
default:
{
T_1 V_44 = V_2 -> V_7 . V_44 ;
F_45 ( V_270 L_8 ,
V_186 , F_4 ( V_2 ) , V_44 ) ;
V_52 = V_176 ;
F_107 () ;
break;
}
}
if ( ! ( V_52 & V_176 ) ) {
V_206 = F_114 ( V_2 ) ;
if ( V_206 <= 0 )
V_52 = V_206 ;
else {
F_115 () ;
}
F_90 ( V_2 ) ;
}
F_116 ( V_52 , V_2 ) ;
return V_52 ;
}
static int F_117 ( struct V_1 * V_2 ,
struct V_271 * V_272 )
{
struct V_273 * V_274 = F_9 ( V_2 ) ;
int V_57 ;
V_272 -> V_103 = V_2 -> V_7 . V_103 ;
V_272 -> V_275 . V_206 . V_276 = F_9 ( V_2 ) -> V_276 ;
if ( V_2 -> V_7 . V_8 & V_105 ) {
for ( V_57 = 0 ; V_57 < 64 ; V_57 ++ ) {
V_272 -> V_275 . V_206 . V_277 . V_15 [ V_57 ] . V_278 = V_2 -> V_7 . V_15 [ V_57 ] . V_279 | V_57 ;
V_272 -> V_275 . V_206 . V_277 . V_15 [ V_57 ] . V_280 = V_2 -> V_7 . V_15 [ V_57 ] . V_281 ;
}
} else {
for ( V_57 = 0 ; V_57 < 16 ; V_57 ++ )
V_272 -> V_275 . V_206 . V_282 . V_213 [ V_57 ] = F_118 ( V_2 , V_57 ) ;
for ( V_57 = 0 ; V_57 < 8 ; V_57 ++ ) {
V_272 -> V_275 . V_206 . V_282 . V_283 [ V_57 ] = V_274 -> V_283 [ V_57 ] . V_284 ;
V_272 -> V_275 . V_206 . V_282 . V_285 [ V_57 ] = V_274 -> V_285 [ V_57 ] . V_284 ;
}
}
return 0 ;
}
static int F_119 ( struct V_1 * V_2 ,
struct V_271 * V_272 )
{
struct V_273 * V_274 = F_9 ( V_2 ) ;
int V_57 ;
F_52 ( V_2 , V_272 -> V_103 ) ;
V_274 -> V_276 = V_272 -> V_275 . V_206 . V_276 ;
if ( V_2 -> V_7 . V_8 & V_105 ) {
for ( V_57 = 0 ; V_57 < 64 ; V_57 ++ ) {
V_2 -> V_7 . V_112 . V_286 ( V_2 , V_272 -> V_275 . V_206 . V_277 . V_15 [ V_57 ] . V_280 ,
V_272 -> V_275 . V_206 . V_277 . V_15 [ V_57 ] . V_278 ) ;
}
} else {
for ( V_57 = 0 ; V_57 < 16 ; V_57 ++ ) {
V_2 -> V_7 . V_112 . V_287 ( V_2 , V_57 , V_272 -> V_275 . V_206 . V_282 . V_213 [ V_57 ] ) ;
}
for ( V_57 = 0 ; V_57 < 8 ; V_57 ++ ) {
F_120 ( V_2 , & ( V_274 -> V_283 [ V_57 ] ) , false ,
( T_5 ) V_272 -> V_275 . V_206 . V_282 . V_283 [ V_57 ] ) ;
F_120 ( V_2 , & ( V_274 -> V_283 [ V_57 ] ) , true ,
( T_5 ) ( V_272 -> V_275 . V_206 . V_282 . V_283 [ V_57 ] >> 32 ) ) ;
F_120 ( V_2 , & ( V_274 -> V_285 [ V_57 ] ) , false ,
( T_5 ) V_272 -> V_275 . V_206 . V_282 . V_285 [ V_57 ] ) ;
F_120 ( V_2 , & ( V_274 -> V_285 [ V_57 ] ) , true ,
( T_5 ) ( V_272 -> V_275 . V_206 . V_282 . V_285 [ V_57 ] >> 32 ) ) ;
}
}
F_28 ( V_2 , 0 , 0 ) ;
return 0 ;
}
static int F_121 ( struct V_1 * V_2 , T_4 V_288 ,
union V_289 * V_290 )
{
int V_52 = 0 ;
switch ( V_288 ) {
case V_291 :
* V_290 = F_122 ( V_288 , V_292 ) ;
break;
case V_293 :
* V_290 = F_122 ( V_288 , F_9 ( V_2 ) -> V_107 ) ;
break;
case V_294 :
* V_290 = F_122 ( V_288 , F_9 ( V_2 ) -> V_50 ) ;
break;
case V_295 :
case V_296 :
if ( V_2 -> V_7 . V_297 & V_79 )
* V_290 = F_122 ( V_288 , V_298 ) ;
else
* V_290 = F_122 ( V_288 , 0 ) ;
break;
default:
V_52 = - V_164 ;
break;
}
return V_52 ;
}
static void F_123 ( struct V_1 * V_2 , T_4 V_299 )
{
if ( V_299 & V_298 )
V_2 -> V_7 . V_297 |= V_79 ;
else
V_2 -> V_7 . V_297 &= ~ V_79 ;
}
static int F_124 ( struct V_1 * V_2 , T_4 V_288 ,
union V_289 * V_290 )
{
int V_52 = 0 ;
switch ( V_288 ) {
case V_293 :
F_9 ( V_2 ) -> V_107 = F_125 ( V_288 , * V_290 ) ;
F_9 ( V_2 ) -> V_106 = true ;
break;
case V_294 :
F_9 ( V_2 ) -> V_50 = F_125 ( V_288 , * V_290 ) ;
break;
case V_295 :
case V_296 :
F_123 ( V_2 , F_125 ( V_288 , * V_290 ) ) ;
break;
default:
V_52 = - V_164 ;
break;
}
return V_52 ;
}
static struct V_1 * F_126 ( struct V_54 * V_54 ,
unsigned int V_288 )
{
struct V_273 * V_300 ;
struct V_1 * V_2 ;
int V_301 = - V_302 ;
unsigned long V_303 ;
V_2 = F_127 ( V_304 , V_305 ) ;
if ( ! V_2 )
goto V_43;
V_300 = F_128 ( sizeof( struct V_273 ) ) ;
if ( ! V_300 )
goto V_306;
V_2 -> V_7 . V_307 = V_300 ;
#ifdef F_129
V_2 -> V_7 . V_27 =
F_130 ( sizeof( * V_2 -> V_7 . V_27 ) , V_305 ) ;
if ( ! V_2 -> V_7 . V_27 )
goto V_308;
#endif
V_301 = F_131 ( V_2 , V_54 , V_288 ) ;
if ( V_301 )
goto V_309;
V_301 = - V_302 ;
V_303 = F_132 ( V_305 | V_310 ) ;
if ( ! V_303 )
goto V_311;
V_2 -> V_7 . V_312 = ( void * ) V_303 ;
#ifdef F_7
#ifdef F_133
V_2 -> V_7 . V_313 = true ;
#else
V_2 -> V_7 . V_313 = false ;
#endif
V_2 -> V_7 . V_103 = 0x3C0301 ;
if ( F_134 ( V_314 ) )
V_2 -> V_7 . V_103 = F_13 ( V_315 ) ;
V_2 -> V_7 . V_297 = V_76 ;
#else
V_2 -> V_7 . V_103 = 0x84202 ;
#endif
F_52 ( V_2 , V_2 -> V_7 . V_103 ) ;
V_2 -> V_7 . V_316 = 64 ;
V_2 -> V_7 . V_87 = V_317 & ~ V_79 ;
V_301 = F_135 ( V_2 ) ;
if ( V_301 < 0 )
goto V_311;
return V_2 ;
V_311:
F_136 ( V_2 ) ;
V_309:
#ifdef F_129
F_137 ( V_2 -> V_7 . V_27 ) ;
V_308:
#endif
F_138 ( V_300 ) ;
V_306:
F_139 ( V_304 , V_2 ) ;
V_43:
return F_140 ( V_301 ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
struct V_273 * V_300 = F_9 ( V_2 ) ;
F_142 ( ( unsigned long ) V_2 -> V_7 . V_312 & V_131 ) ;
F_136 ( V_2 ) ;
#ifdef F_129
F_137 ( V_2 -> V_7 . V_27 ) ;
#endif
F_138 ( V_300 ) ;
F_139 ( V_304 , V_2 ) ;
}
static int F_143 ( struct V_137 * V_137 , struct V_1 * V_2 )
{
int V_318 ;
#ifdef F_80
unsigned long V_319 ( V_320 ) ;
#endif
if ( ! V_2 -> V_7 . V_321 ) {
V_137 -> V_208 = V_322 ;
V_318 = - V_164 ;
goto V_43;
}
F_97 ( V_2 ) ;
V_318 = F_114 ( V_2 ) ;
if ( V_318 <= 0 )
goto V_43;
F_144 ( V_24 ) ;
if ( F_2 ( V_2 ) & V_28 )
F_51 ( V_2 , V_102 , V_28 ) ;
F_115 () ;
V_318 = F_145 ( V_137 , V_2 ) ;
F_99 ( V_2 ) ;
F_19 ( V_2 , V_28 | V_29 | V_30 ) ;
F_20 ( V_2 , V_31 ) ;
V_43:
V_2 -> V_323 = V_324 ;
return V_318 ;
}
static int F_146 ( struct V_54 * V_54 ,
struct V_325 * log )
{
struct V_58 * V_59 ;
struct V_60 * V_61 ;
struct V_1 * V_2 ;
T_1 V_326 , V_327 ;
int V_328 = 0 ;
int V_52 ;
unsigned long V_329 ;
F_147 ( & V_54 -> V_330 ) ;
V_52 = F_148 ( V_54 , log , & V_328 ) ;
if ( V_52 )
goto V_43;
if ( V_328 ) {
V_59 = V_58 ( V_54 ) ;
V_61 = F_149 ( V_59 , log -> V_331 ) ;
V_326 = V_61 -> V_332 << V_68 ;
V_327 = V_326 + ( V_61 -> V_67 << V_68 ) ;
F_34 (n, vcpu, kvm)
F_35 ( V_2 , V_326 , V_327 ) ;
V_329 = F_150 ( V_61 ) ;
memset ( V_61 -> V_333 , 0 , V_329 ) ;
}
V_52 = 0 ;
V_43:
F_151 ( & V_54 -> V_330 ) ;
return V_52 ;
}
static void F_152 ( struct V_54 * V_54 ,
struct V_60 * V_61 )
{
return;
}
static int F_153 ( struct V_54 * V_54 ,
struct V_60 * V_61 ,
const struct V_334 * V_335 )
{
return 0 ;
}
static void F_154 ( struct V_54 * V_54 ,
const struct V_334 * V_335 ,
const struct V_60 * V_336 ,
const struct V_60 * V_337 )
{
return;
}
static void F_155 ( struct V_60 * free ,
struct V_60 * V_338 )
{
return;
}
static int F_156 ( struct V_60 * V_331 ,
unsigned long V_67 )
{
return 0 ;
}
static int F_157 ( struct V_54 * V_54 ,
struct V_339 * V_340 )
{
long int V_57 ;
struct V_1 * V_2 ;
V_340 -> V_234 = 0 ;
V_340 -> V_341 = 64 ;
V_340 -> V_342 [ 0 ] . V_343 = 12 ;
V_340 -> V_342 [ 0 ] . V_344 = 0 ;
V_340 -> V_342 [ 0 ] . V_345 [ 0 ] . V_343 = 12 ;
V_340 -> V_342 [ 0 ] . V_345 [ 0 ] . V_346 = 0 ;
V_57 = 1 ;
V_2 = F_158 ( V_54 , 0 ) ;
if ( V_2 && ( V_2 -> V_7 . V_8 & V_122 ) ) {
V_340 -> V_234 = V_347 ;
V_340 -> V_342 [ V_57 ] . V_343 = 16 ;
V_340 -> V_342 [ V_57 ] . V_344 = V_348 | V_349 ;
V_340 -> V_342 [ V_57 ] . V_345 [ 0 ] . V_343 = 16 ;
V_340 -> V_342 [ V_57 ] . V_345 [ 0 ] . V_346 = 1 ;
++ V_57 ;
}
V_340 -> V_342 [ V_57 ] . V_343 = 24 ;
V_340 -> V_342 [ V_57 ] . V_344 = V_348 ;
V_340 -> V_342 [ V_57 ] . V_345 [ 0 ] . V_343 = 24 ;
V_340 -> V_342 [ V_57 ] . V_345 [ 0 ] . V_346 = 0 ;
return 0 ;
}
static int F_157 ( struct V_54 * V_54 ,
struct V_339 * V_340 )
{
F_107 () ;
}
static int F_159 ( struct V_54 * V_54 )
{
F_160 ( & V_54 -> V_7 . V_350 ) ;
#ifdef F_7
F_161 ( V_54 ) ;
#endif
if ( F_162 ( V_351 ) ) {
F_163 ( & V_352 ) ;
if ( ++ V_353 == 1 )
F_164 () ;
F_165 ( & V_352 ) ;
}
return 0 ;
}
static void F_166 ( struct V_54 * V_54 )
{
#ifdef F_167
F_168 ( ! F_169 ( & V_54 -> V_7 . V_354 ) ) ;
#endif
if ( F_162 ( V_351 ) ) {
F_163 ( & V_352 ) ;
F_95 ( V_353 == 0 ) ;
if ( -- V_353 == 0 )
F_170 () ;
F_165 ( & V_352 ) ;
}
}
static int F_171 ( void )
{
if ( F_11 ( V_355 ) )
return - V_356 ;
return 0 ;
}
static long F_172 ( struct V_357 * V_358 ,
unsigned int V_359 , unsigned long V_360 )
{
return - V_361 ;
}
int F_173 ( void )
{
int V_52 ;
V_52 = F_171 () ;
if ( V_52 < 0 )
return V_52 ;
V_362 . V_363 = V_364 ;
V_365 = & V_362 ;
V_52 = F_174 () ;
return V_52 ;
}
void F_175 ( void )
{
V_365 = NULL ;
F_176 () ;
}
