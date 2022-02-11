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
F_48 ( V_93 , V_2 ) ;
V_2 -> V_94 . V_95 ++ ;
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
if ( ! ( V_3 & V_82 ) && V_2 -> V_7 . V_96 ) {
struct V_97 * V_98 = & V_2 -> V_7 ;
if ( V_3 & V_5 )
F_50 ( V_2 , V_98 -> V_99 ) ;
else
F_50 ( V_2 , V_98 -> V_96 ) ;
}
}
if ( V_2 -> V_7 . V_96 &&
! ( V_88 & V_82 ) && ! ( V_88 & V_76 ) && ( V_3 & V_76 ) ) {
F_28 ( V_2 , ( V_100 ) V_2 -> V_7 . V_96 ,
~ 0xFFFUL ) ;
}
if ( F_2 ( V_2 ) & V_28 )
F_51 ( V_2 , V_101 , V_28 ) ;
}
void F_52 ( struct V_1 * V_2 , T_5 V_102 )
{
T_5 V_103 ;
V_2 -> V_7 . V_8 &= ~ V_104 ;
V_2 -> V_7 . V_102 = V_102 ;
#ifdef F_7
if ( ( V_102 >= 0x330000 ) && ( V_102 < 0x70330000 ) ) {
F_53 ( V_2 ) ;
if ( ! F_9 ( V_2 ) -> V_105 )
F_9 ( V_2 ) -> V_106 = 0xfff00000 ;
F_9 ( V_2 ) -> V_90 = 0xffffffffffffffffULL ;
V_2 -> V_7 . V_107 = V_108 ;
} else
#endif
{
F_54 ( V_2 ) ;
if ( ! F_9 ( V_2 ) -> V_105 )
F_9 ( V_2 ) -> V_106 = 0 ;
F_9 ( V_2 ) -> V_90 = 0xffffffffULL ;
V_2 -> V_7 . V_107 = V_109 ;
}
F_55 ( V_2 ) ;
V_2 -> V_7 . V_8 &= ~ V_110 ;
if ( V_2 -> V_7 . V_111 . V_112 ( V_2 ) && ( F_56 () & V_86 ) &&
! strcmp ( V_113 -> V_114 , L_2 ) )
V_2 -> V_7 . V_8 |= V_110 ;
if ( ! strcmp ( V_113 -> V_114 , L_3 ) )
F_9 ( V_2 ) -> V_90 &= ~ ( V_74 | V_75 ) ;
switch ( F_57 ( V_102 ) ) {
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_2 -> V_7 . V_8 |= V_121 |
V_122 ;
break;
}
#ifdef F_15
V_2 -> V_7 . V_8 |= V_110 ;
#endif
asm ( "mfpvr %0" : "=r"(host_pvr));
switch ( V_103 ) {
case 0x00080200 :
case 0x00088202 :
case 0x70000100 :
case 0x00080100 :
case 0x00083203 :
case 0x00083213 :
case 0x00083204 :
case 0x00083214 :
case 0x00087200 :
V_2 -> V_7 . V_8 |= V_123 ;
F_12 ( V_124 , F_13 ( V_124 ) | ( 1 << 29 ) ) ;
}
}
static void F_58 ( struct V_1 * V_2 , struct V_125 * V_71 )
{
struct V_126 * V_127 ;
T_4 V_128 ;
T_5 * V_126 ;
int V_57 ;
V_127 = F_59 ( V_2 -> V_54 , V_71 -> V_129 >> V_68 ) ;
if ( F_60 ( V_127 ) )
return;
V_128 = V_71 -> V_129 & ~ V_130 ;
V_128 &= ~ 0xFFFULL ;
V_128 /= 4 ;
F_61 ( V_127 ) ;
V_126 = F_62 ( V_127 ) ;
for ( V_57 = V_128 ; V_57 < V_128 + ( V_131 / 4 ) ; V_57 ++ )
if ( ( F_63 ( V_126 [ V_57 ] ) & 0xff0007ff ) == V_132 )
V_126 [ V_57 ] &= F_64 ( 0xfffffff7 ) ;
F_65 ( V_126 ) ;
F_66 ( V_127 ) ;
}
static bool F_67 ( struct V_1 * V_2 , T_6 V_133 )
{
T_1 V_134 = V_2 -> V_7 . V_96 ;
if ( ! ( F_2 ( V_2 ) & V_76 ) )
V_134 = ( V_100 ) V_134 ;
V_133 &= ~ 0xFFFULL ;
if ( F_68 ( V_134 ) && F_68 ( ( V_134 & V_135 ) == ( V_133 & V_135 ) ) ) {
return true ;
}
return F_69 ( V_2 -> V_54 , V_133 >> V_68 ) ;
}
int F_70 ( struct V_136 * V_137 , struct V_1 * V_2 ,
T_1 V_138 , int V_139 )
{
bool V_140 = ( V_139 == V_141 ) ;
bool V_142 = false ;
int V_52 = V_143 ;
int V_144 ;
int V_145 = 0 ;
struct V_125 V_71 = { 0 } ;
bool V_146 = ( F_2 ( V_2 ) & V_5 ) ? true : false ;
bool V_147 = ( F_2 ( V_2 ) & V_4 ) ? true : false ;
T_4 V_148 ;
V_144 = V_140 ? V_146 : V_147 ;
if ( V_140 && ( V_2 -> V_7 . V_46 & V_149 ) )
V_142 = true ;
if ( V_144 ) {
V_145 = V_2 -> V_7 . V_111 . V_150 ( V_2 , V_138 , & V_71 , V_140 , V_142 ) ;
} else {
V_71 . V_151 = true ;
V_71 . V_152 = true ;
V_71 . V_153 = true ;
V_71 . V_129 = V_138 & V_135 ;
V_71 . V_138 = V_138 ;
V_71 . V_154 = V_138 >> 12 ;
V_71 . V_155 = V_156 ;
}
switch ( F_2 ( V_2 ) & ( V_5 | V_4 ) ) {
case 0 :
V_71 . V_154 |= ( ( T_4 ) V_157 << ( V_158 - 12 ) ) ;
break;
case V_5 :
if ( ! V_140 &&
( V_2 -> V_7 . V_8 & V_9 ) &&
( ( V_71 . V_129 & V_10 ) == V_11 ) )
V_71 . V_129 &= ~ V_10 ;
case V_4 :
V_2 -> V_7 . V_111 . V_159 ( V_2 , V_138 >> V_158 , & V_148 ) ;
if ( ( F_2 ( V_2 ) & ( V_5 | V_4 ) ) == V_5 )
V_71 . V_154 |= ( ( T_4 ) V_160 << ( V_158 - 12 ) ) ;
else
V_71 . V_154 |= ( ( T_4 ) V_161 << ( V_158 - 12 ) ) ;
V_71 . V_154 |= V_148 ;
if ( V_148 == - 1 )
V_145 = - V_162 ;
break;
}
if ( V_2 -> V_7 . V_111 . V_112 ( V_2 ) &&
( ! ( V_2 -> V_7 . V_8 & V_110 ) ) ) {
V_71 . V_151 = ! V_140 ;
}
if ( V_145 == - V_163 ) {
T_4 V_164 = V_2 -> V_7 . V_44 ;
T_4 V_3 = F_2 ( V_2 ) ;
F_71 ( V_2 , F_72 ( V_2 ) ) ;
F_73 ( V_2 , V_2 -> V_7 . V_46 ) ;
F_46 ( V_2 , V_3 | ( V_164 & 0xf8000000ULL ) ) ;
F_74 ( V_2 , V_139 ) ;
} else if ( V_145 == - V_165 ) {
T_5 V_166 = V_2 -> V_7 . V_46 ;
T_4 V_164 = V_2 -> V_7 . V_44 ;
T_4 V_3 = F_2 ( V_2 ) ;
F_71 ( V_2 , F_72 ( V_2 ) ) ;
V_166 = ( V_166 & ~ V_167 ) | V_168 ;
F_73 ( V_2 , V_166 ) ;
F_46 ( V_2 , V_3 | ( V_164 & 0xf8000000ULL ) ) ;
F_74 ( V_2 , V_139 ) ;
} else if ( V_145 == - V_162 ) {
F_71 ( V_2 , F_72 ( V_2 ) ) ;
F_74 ( V_2 , V_139 + 0x80 ) ;
} else if ( F_67 ( V_2 , V_71 . V_129 ) ) {
if ( V_140 && ! ( V_2 -> V_7 . V_46 & V_167 ) ) {
F_75 ( V_2 , & V_71 ) ;
}
if ( F_76 ( V_2 , & V_71 , V_142 ) == - V_169 ) {
V_137 -> V_170 = V_171 ;
return V_172 ;
}
if ( V_140 )
V_2 -> V_94 . V_173 ++ ;
else if ( V_2 -> V_7 . V_111 . V_112 ( V_2 ) &&
( ! ( V_2 -> V_7 . V_8 & V_110 ) ) )
F_58 ( V_2 , & V_71 ) ;
} else {
V_2 -> V_94 . V_174 ++ ;
V_2 -> V_7 . V_175 = V_71 . V_129 ;
V_2 -> V_7 . V_176 = V_71 . V_138 ;
V_52 = F_77 ( V_137 , V_2 ) ;
if ( V_52 == V_177 )
V_52 = V_172 ;
}
return V_52 ;
}
void F_19 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_178 * V_179 = & V_24 -> V_25 ;
if ( V_3 & V_30 )
V_3 |= V_28 | V_29 ;
V_3 &= V_2 -> V_7 . V_84 ;
if ( ! V_3 )
return;
#ifdef F_78
F_45 ( V_89 L_4 , V_3 ) ;
#endif
if ( V_3 & V_28 ) {
if ( V_179 -> V_180 -> V_3 & V_28 )
F_79 ( V_24 ) ;
V_179 -> V_181 = NULL ;
}
#ifdef F_80
if ( V_3 & V_29 ) {
if ( V_24 -> V_25 . V_180 -> V_3 & V_29 )
F_81 ( V_24 ) ;
V_179 -> V_182 = NULL ;
}
#endif
V_2 -> V_7 . V_84 &= ~ ( V_3 | V_30 ) ;
F_42 ( V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_183 )
{
#ifdef F_7
if ( ! ( V_2 -> V_7 . V_38 & ( 1ULL << V_183 ) ) ) {
return;
}
switch ( V_183 ) {
case V_31 :
V_2 -> V_7 . V_184 = F_13 ( V_185 ) ;
F_12 ( V_185 , V_24 -> V_25 . V_184 ) ;
V_2 -> V_7 . V_38 &= ~ V_186 ;
break;
}
#endif
}
static int F_51 ( struct V_1 * V_2 , unsigned int V_187 ,
T_1 V_3 )
{
struct V_178 * V_179 = & V_24 -> V_25 ;
if ( V_2 -> V_7 . V_8 & V_188 )
return V_143 ;
if ( ! ( F_2 ( V_2 ) & V_3 ) ) {
F_74 ( V_2 , V_187 ) ;
return V_143 ;
}
if ( V_3 == V_30 ) {
#ifdef F_82
if ( ! F_11 ( V_189 ) )
#endif
{
F_83 ( V_2 , V_190 ) ;
return V_143 ;
}
V_3 = V_28 | V_29 | V_30 ;
}
V_3 &= ~ V_2 -> V_7 . V_84 ;
if ( ! V_3 )
return V_143 ;
#ifdef F_78
F_45 ( V_89 L_5 , V_3 ) ;
#endif
if ( V_3 & V_28 ) {
F_24 () ;
F_84 () ;
F_85 ( & V_2 -> V_7 . V_191 ) ;
F_86 () ;
V_179 -> V_181 = & V_2 -> V_7 . V_191 ;
F_25 () ;
}
if ( V_3 & V_29 ) {
#ifdef F_80
F_24 () ;
F_87 () ;
F_88 ( & V_2 -> V_7 . V_192 ) ;
F_89 () ;
V_179 -> V_182 = & V_2 -> V_7 . V_192 ;
F_25 () ;
#endif
}
V_179 -> V_180 -> V_3 |= V_3 ;
V_2 -> V_7 . V_84 |= V_3 ;
F_42 ( V_2 ) ;
return V_143 ;
}
static void F_90 ( struct V_1 * V_2 )
{
unsigned long V_193 ;
V_193 = V_2 -> V_7 . V_84 & ~ V_24 -> V_25 . V_180 -> V_3 ;
if ( ! V_193 )
return;
if ( V_193 & V_28 ) {
F_24 () ;
F_84 () ;
F_85 ( & V_2 -> V_7 . V_191 ) ;
F_86 () ;
F_25 () ;
}
#ifdef F_80
if ( V_193 & V_29 ) {
F_24 () ;
F_87 () ;
F_88 ( & V_2 -> V_7 . V_192 ) ;
F_89 () ;
F_25 () ;
}
#endif
V_24 -> V_25 . V_180 -> V_3 |= V_193 ;
}
static void F_91 ( struct V_1 * V_2 , T_1 V_183 )
{
V_2 -> V_7 . V_194 &= ~ ( 0xffULL << 56 ) ;
V_2 -> V_7 . V_194 |= ( V_183 << 56 ) ;
F_74 ( V_2 , V_195 ) ;
}
static void F_92 ( struct V_1 * V_2 , T_1 V_183 )
{
enum V_196 V_197 = V_198 ;
if ( ! ( F_2 ( V_2 ) & V_82 ) )
V_197 = F_93 ( V_2 -> V_137 , V_2 ) ;
if ( ( V_197 != V_199 ) && ( V_197 != V_200 ) ) {
F_91 ( V_2 , V_183 ) ;
}
}
static int F_94 ( struct V_1 * V_2 , T_1 V_183 )
{
bool V_201 ;
F_95 ( ! F_11 ( V_21 ) ) ;
switch ( V_183 ) {
case V_31 :
case V_202 :
V_201 = ( V_2 -> V_7 . V_194 & ( 1ULL << V_183 ) ) ;
break;
case V_203 :
V_201 = F_2 ( V_2 ) & V_204 ;
break;
default:
V_201 = false ;
break;
}
if ( ! V_201 ) {
F_91 ( V_2 , V_183 ) ;
return V_143 ;
}
switch ( V_183 ) {
case V_31 :
V_24 -> V_25 . V_184 = F_13 ( V_185 ) ;
F_12 ( V_185 , V_2 -> V_7 . V_184 ) ;
V_2 -> V_7 . V_38 |= V_186 ;
break;
default:
F_92 ( V_2 , V_183 ) ;
break;
}
return V_143 ;
}
void F_96 ( struct V_1 * V_2 , T_4 V_194 )
{
if ( ( V_2 -> V_7 . V_194 & V_186 ) && ! ( V_194 & V_186 ) ) {
F_20 ( V_2 , V_31 ) ;
}
V_2 -> V_7 . V_194 = V_194 ;
}
static void F_97 ( struct V_1 * V_2 )
{
if ( V_2 -> V_205 & V_206 ) {
T_4 V_3 = F_2 ( V_2 ) ;
F_98 ( V_2 , V_3 | V_77 ) ;
}
}
static void F_99 ( struct V_1 * V_2 )
{
if ( V_2 -> V_205 & V_206 ) {
T_4 V_3 = F_2 ( V_2 ) ;
F_98 ( V_2 , V_3 & ~ V_77 ) ;
}
}
static int F_100 ( struct V_136 * V_137 , struct V_1 * V_2 ,
unsigned int V_187 )
{
enum V_196 V_197 ;
T_1 V_207 ;
T_5 V_47 ;
int V_208 , V_52 ;
if ( V_187 == V_209 )
V_207 = V_2 -> V_7 . V_44 & 0x1f0000ull ;
else
V_207 = V_190 ;
V_208 = F_101 ( V_2 , V_210 , & V_47 ) ;
if ( V_208 != V_199 )
return V_143 ;
if ( F_2 ( V_2 ) & V_82 ) {
#ifdef F_44
F_102 ( L_6 ,
F_4 ( V_2 ) , V_47 ) ;
#endif
if ( ( V_47 & 0xff0007ff ) != ( V_132 & 0xfffffff7 ) ) {
F_83 ( V_2 , V_207 ) ;
return V_143 ;
}
}
V_2 -> V_94 . V_211 ++ ;
V_197 = F_93 ( V_137 , V_2 ) ;
switch ( V_197 ) {
case V_199 :
V_52 = V_212 ;
break;
case V_200 :
V_52 = V_143 ;
break;
case V_198 :
F_103 ( L_7 ,
V_213 , F_4 ( V_2 ) , V_47 ) ;
F_83 ( V_2 , V_207 ) ;
V_52 = V_143 ;
break;
case V_214 :
V_137 -> V_170 = V_215 ;
V_52 = V_177 ;
break;
case V_216 :
V_52 = V_177 ;
break;
default:
F_104 () ;
}
return V_52 ;
}
int F_105 ( struct V_136 * V_137 , struct V_1 * V_2 ,
unsigned int V_187 )
{
int V_52 = V_172 ;
int V_217 ;
V_2 -> V_94 . V_218 ++ ;
V_137 -> V_170 = V_219 ;
V_137 -> V_220 = 1 ;
F_106 ( V_187 , V_2 ) ;
F_107 () ;
switch ( V_187 ) {
case V_221 :
{
T_1 V_44 = V_2 -> V_7 . V_44 ;
V_2 -> V_94 . V_222 ++ ;
if ( F_1 ( V_2 ) )
F_3 ( V_2 ) ;
#ifdef F_15
{
struct V_13 * V_14 ;
T_5 V_223 ;
V_14 = F_8 ( V_2 ) ;
V_223 = V_14 -> V_223 [ F_4 ( V_2 ) >> V_158 ] ;
F_10 ( V_14 ) ;
if ( V_223 == V_224 ) {
F_50 ( V_2 , F_4 ( V_2 ) ) ;
V_52 = V_143 ;
break;
}
}
#endif
if ( V_44 & 0x40000000 ) {
int V_225 = F_108 ( & V_2 -> V_54 -> V_226 ) ;
V_52 = F_70 ( V_137 , V_2 , F_4 ( V_2 ) , V_187 ) ;
F_109 ( & V_2 -> V_54 -> V_226 , V_225 ) ;
V_2 -> V_94 . V_227 ++ ;
} else if ( V_2 -> V_7 . V_111 . V_112 ( V_2 ) &&
( ! ( V_2 -> V_7 . V_8 & V_110 ) ) ) {
F_28 ( V_2 , F_4 ( V_2 ) , ~ 0xFFFUL ) ;
V_52 = V_143 ;
} else {
T_4 V_3 = F_2 ( V_2 ) ;
V_3 |= V_44 & 0x58000000 ;
F_46 ( V_2 , V_3 ) ;
F_74 ( V_2 , V_187 ) ;
V_52 = V_143 ;
}
break;
}
case V_141 :
{
T_1 V_228 = F_72 ( V_2 ) ;
T_5 V_46 = V_2 -> V_7 . V_46 ;
V_2 -> V_94 . V_229 ++ ;
#ifdef F_15
{
struct V_13 * V_14 ;
T_5 V_223 ;
V_14 = F_8 ( V_2 ) ;
V_223 = V_14 -> V_223 [ V_228 >> V_158 ] ;
F_10 ( V_14 ) ;
if ( V_223 == V_224 ) {
F_50 ( V_2 , V_228 ) ;
V_52 = V_143 ;
break;
}
}
#endif
if ( V_46 & ( V_167 | V_168 ) ) {
int V_225 = F_108 ( & V_2 -> V_54 -> V_226 ) ;
V_52 = F_70 ( V_137 , V_2 , V_228 , V_187 ) ;
F_109 ( & V_2 -> V_54 -> V_226 , V_225 ) ;
} else {
F_71 ( V_2 , V_228 ) ;
F_73 ( V_2 , V_46 ) ;
F_74 ( V_2 , V_187 ) ;
V_52 = V_143 ;
}
break;
}
case V_230 :
if ( F_50 ( V_2 , F_72 ( V_2 ) ) < 0 ) {
F_71 ( V_2 , F_72 ( V_2 ) ) ;
F_74 ( V_2 ,
V_230 ) ;
}
V_52 = V_143 ;
break;
case V_231 :
if ( F_50 ( V_2 , F_4 ( V_2 ) ) < 0 ) {
F_74 ( V_2 ,
V_231 ) ;
}
V_52 = V_143 ;
break;
case V_232 :
case V_233 :
case V_234 :
case V_235 :
V_2 -> V_94 . V_236 ++ ;
V_52 = V_143 ;
break;
case V_237 :
case V_238 :
case V_239 :
V_2 -> V_94 . V_240 ++ ;
V_52 = V_143 ;
break;
case V_241 :
V_52 = V_143 ;
break;
case V_209 :
case V_242 :
V_52 = F_100 ( V_137 , V_2 , V_187 ) ;
break;
case V_243 :
{
T_5 V_244 ;
int V_208 ;
if ( V_2 -> V_7 . V_245 ) {
V_208 = F_101 ( V_2 , V_246 , & V_244 ) ;
if ( V_208 != V_199 ) {
F_5 ( V_2 , F_4 ( V_2 ) - 4 ) ;
V_52 = V_143 ;
break;
}
}
if ( V_2 -> V_7 . V_245 &&
( V_244 == 0x44000022 ) &&
! ( F_2 ( V_2 ) & V_82 ) ) {
T_1 V_247 = F_110 ( V_2 , 3 ) ;
int V_57 ;
#ifdef F_7
if ( F_111 ( V_2 , V_247 ) == V_199 ) {
V_52 = V_143 ;
break;
}
#endif
V_137 -> V_248 . V_249 = V_247 ;
for ( V_57 = 0 ; V_57 < 9 ; ++ V_57 ) {
T_1 V_33 = F_110 ( V_2 , 4 + V_57 ) ;
V_137 -> V_248 . args [ V_57 ] = V_33 ;
}
V_137 -> V_170 = V_250 ;
V_2 -> V_7 . V_251 = 1 ;
V_52 = V_172 ;
} else if ( V_2 -> V_7 . V_252 &&
( ( ( T_5 ) F_110 ( V_2 , 3 ) ) == V_253 ) &&
( ( ( T_5 ) F_110 ( V_2 , 4 ) ) == V_254 ) ) {
T_4 * V_255 = V_137 -> V_256 . V_255 ;
int V_57 ;
V_137 -> V_170 = V_257 ;
for ( V_57 = 0 ; V_57 < 32 ; V_57 ++ )
V_255 [ V_57 ] = F_110 ( V_2 , V_57 ) ;
V_2 -> V_7 . V_258 = 1 ;
V_52 = V_177 ;
} else if ( ! ( F_2 ( V_2 ) & V_82 ) &&
( ( ( T_5 ) F_110 ( V_2 , 0 ) ) == V_259 ) ) {
F_112 ( V_2 , 3 , F_113 ( V_2 ) ) ;
V_52 = V_143 ;
} else {
V_2 -> V_94 . V_260 ++ ;
F_74 ( V_2 , V_187 ) ;
V_52 = V_143 ;
}
break;
}
case V_101 :
case V_261 :
case V_262 :
{
int V_263 = 0 ;
int V_208 ;
T_5 V_47 ;
if ( V_2 -> V_7 . V_8 & V_188 ) {
V_208 = F_101 ( V_2 , V_210 ,
& V_47 ) ;
if ( V_208 == V_199 )
V_52 = F_100 ( V_137 , V_2 , V_187 ) ;
else
V_52 = V_143 ;
break;
}
switch ( V_187 ) {
case V_101 :
V_263 = V_28 ;
break;
case V_261 :
V_263 = V_29 ;
break;
case V_262 :
V_263 = V_30 ;
break;
}
V_52 = F_51 ( V_2 , V_187 , V_263 ) ;
break;
}
case V_264 :
{
T_5 V_47 ;
int V_208 = F_101 ( V_2 , V_210 , & V_47 ) ;
if ( V_208 == V_199 ) {
T_5 V_166 ;
T_4 V_228 ;
V_166 = F_114 ( V_2 , V_47 ) ;
V_228 = F_115 ( V_2 , V_47 ) ;
F_73 ( V_2 , V_166 ) ;
F_71 ( V_2 , V_228 ) ;
F_74 ( V_2 , V_187 ) ;
}
V_52 = V_143 ;
break;
}
#ifdef F_7
case V_195 :
F_94 ( V_2 , V_2 -> V_7 . V_38 >> 56 ) ;
V_52 = V_143 ;
break;
#endif
case V_265 :
F_74 ( V_2 , V_187 ) ;
V_52 = V_143 ;
break;
case V_266 :
if ( V_2 -> V_205 & V_206 ) {
V_137 -> V_170 = V_267 ;
V_52 = V_172 ;
} else {
F_74 ( V_2 , V_187 ) ;
V_52 = V_143 ;
}
break;
default:
{
T_1 V_44 = V_2 -> V_7 . V_44 ;
F_45 ( V_268 L_8 ,
V_187 , F_4 ( V_2 ) , V_44 ) ;
V_52 = V_172 ;
F_104 () ;
break;
}
}
if ( ! ( V_52 & V_172 ) ) {
V_217 = F_116 ( V_2 ) ;
if ( V_217 <= 0 )
V_52 = V_217 ;
else {
F_117 () ;
}
F_90 ( V_2 ) ;
}
F_118 ( V_52 , V_2 ) ;
return V_52 ;
}
static int F_119 ( struct V_1 * V_2 ,
struct V_269 * V_270 )
{
struct V_271 * V_272 = F_9 ( V_2 ) ;
int V_57 ;
V_270 -> V_102 = V_2 -> V_7 . V_102 ;
V_270 -> V_273 . V_217 . V_274 = F_9 ( V_2 ) -> V_274 ;
if ( V_2 -> V_7 . V_8 & V_104 ) {
for ( V_57 = 0 ; V_57 < 64 ; V_57 ++ ) {
V_270 -> V_273 . V_217 . V_275 . V_15 [ V_57 ] . V_276 = V_2 -> V_7 . V_15 [ V_57 ] . V_277 | V_57 ;
V_270 -> V_273 . V_217 . V_275 . V_15 [ V_57 ] . V_278 = V_2 -> V_7 . V_15 [ V_57 ] . V_279 ;
}
} else {
for ( V_57 = 0 ; V_57 < 16 ; V_57 ++ )
V_270 -> V_273 . V_217 . V_280 . V_223 [ V_57 ] = F_120 ( V_2 , V_57 ) ;
for ( V_57 = 0 ; V_57 < 8 ; V_57 ++ ) {
V_270 -> V_273 . V_217 . V_280 . V_281 [ V_57 ] = V_272 -> V_281 [ V_57 ] . V_282 ;
V_270 -> V_273 . V_217 . V_280 . V_283 [ V_57 ] = V_272 -> V_283 [ V_57 ] . V_282 ;
}
}
return 0 ;
}
static int F_121 ( struct V_1 * V_2 ,
struct V_269 * V_270 )
{
struct V_271 * V_272 = F_9 ( V_2 ) ;
int V_57 ;
F_52 ( V_2 , V_270 -> V_102 ) ;
V_272 -> V_274 = V_270 -> V_273 . V_217 . V_274 ;
if ( V_2 -> V_7 . V_8 & V_104 ) {
for ( V_57 = 0 ; V_57 < 64 ; V_57 ++ ) {
V_2 -> V_7 . V_111 . V_284 ( V_2 , V_270 -> V_273 . V_217 . V_275 . V_15 [ V_57 ] . V_278 ,
V_270 -> V_273 . V_217 . V_275 . V_15 [ V_57 ] . V_276 ) ;
}
} else {
for ( V_57 = 0 ; V_57 < 16 ; V_57 ++ ) {
V_2 -> V_7 . V_111 . V_285 ( V_2 , V_57 , V_270 -> V_273 . V_217 . V_280 . V_223 [ V_57 ] ) ;
}
for ( V_57 = 0 ; V_57 < 8 ; V_57 ++ ) {
F_122 ( V_2 , & ( V_272 -> V_281 [ V_57 ] ) , false ,
( T_5 ) V_270 -> V_273 . V_217 . V_280 . V_281 [ V_57 ] ) ;
F_122 ( V_2 , & ( V_272 -> V_281 [ V_57 ] ) , true ,
( T_5 ) ( V_270 -> V_273 . V_217 . V_280 . V_281 [ V_57 ] >> 32 ) ) ;
F_122 ( V_2 , & ( V_272 -> V_283 [ V_57 ] ) , false ,
( T_5 ) V_270 -> V_273 . V_217 . V_280 . V_283 [ V_57 ] ) ;
F_122 ( V_2 , & ( V_272 -> V_283 [ V_57 ] ) , true ,
( T_5 ) ( V_270 -> V_273 . V_217 . V_280 . V_283 [ V_57 ] >> 32 ) ) ;
}
}
F_28 ( V_2 , 0 , 0 ) ;
return 0 ;
}
static int F_123 ( struct V_1 * V_2 , T_4 V_286 ,
union V_287 * V_288 )
{
int V_52 = 0 ;
switch ( V_286 ) {
case V_289 :
* V_288 = F_124 ( V_286 , V_290 ) ;
break;
case V_291 :
* V_288 = F_124 ( V_286 , F_9 ( V_2 ) -> V_106 ) ;
break;
case V_292 :
* V_288 = F_124 ( V_286 , F_9 ( V_2 ) -> V_50 ) ;
break;
case V_293 :
case V_294 :
if ( V_2 -> V_7 . V_295 & V_79 )
* V_288 = F_124 ( V_286 , V_296 ) ;
else
* V_288 = F_124 ( V_286 , 0 ) ;
break;
default:
V_52 = - V_162 ;
break;
}
return V_52 ;
}
static void F_125 ( struct V_1 * V_2 , T_4 V_297 )
{
if ( V_297 & V_296 )
V_2 -> V_7 . V_295 |= V_79 ;
else
V_2 -> V_7 . V_295 &= ~ V_79 ;
}
static int F_126 ( struct V_1 * V_2 , T_4 V_286 ,
union V_287 * V_288 )
{
int V_52 = 0 ;
switch ( V_286 ) {
case V_291 :
F_9 ( V_2 ) -> V_106 = F_127 ( V_286 , * V_288 ) ;
F_9 ( V_2 ) -> V_105 = true ;
break;
case V_292 :
F_9 ( V_2 ) -> V_50 = F_127 ( V_286 , * V_288 ) ;
break;
case V_293 :
case V_294 :
F_125 ( V_2 , F_127 ( V_286 , * V_288 ) ) ;
break;
default:
V_52 = - V_162 ;
break;
}
return V_52 ;
}
static struct V_1 * F_128 ( struct V_54 * V_54 ,
unsigned int V_286 )
{
struct V_271 * V_298 ;
struct V_1 * V_2 ;
int V_299 = - V_300 ;
unsigned long V_301 ;
V_2 = F_129 ( V_302 , V_303 ) ;
if ( ! V_2 )
goto V_43;
V_298 = F_130 ( sizeof( struct V_271 ) ) ;
if ( ! V_298 )
goto V_304;
V_2 -> V_7 . V_305 = V_298 ;
#ifdef F_131
V_2 -> V_7 . V_27 =
F_132 ( sizeof( * V_2 -> V_7 . V_27 ) , V_303 ) ;
if ( ! V_2 -> V_7 . V_27 )
goto V_306;
#endif
V_299 = F_133 ( V_2 , V_54 , V_286 ) ;
if ( V_299 )
goto V_307;
V_299 = - V_300 ;
V_301 = F_134 ( V_303 | V_308 ) ;
if ( ! V_301 )
goto V_309;
V_2 -> V_7 . V_310 = ( void * ) V_301 ;
#ifdef F_7
#ifdef F_135
V_2 -> V_7 . V_311 = true ;
#else
V_2 -> V_7 . V_311 = false ;
#endif
V_2 -> V_7 . V_102 = 0x3C0301 ;
if ( F_136 ( V_312 ) )
V_2 -> V_7 . V_102 = F_13 ( V_313 ) ;
V_2 -> V_7 . V_295 = V_76 ;
#else
V_2 -> V_7 . V_102 = 0x84202 ;
#endif
F_52 ( V_2 , V_2 -> V_7 . V_102 ) ;
V_2 -> V_7 . V_314 = 64 ;
V_2 -> V_7 . V_87 = V_315 & ~ V_79 ;
V_299 = F_137 ( V_2 ) ;
if ( V_299 < 0 )
goto V_309;
return V_2 ;
V_309:
F_138 ( V_2 ) ;
V_307:
#ifdef F_131
F_139 ( V_2 -> V_7 . V_27 ) ;
V_306:
#endif
F_140 ( V_298 ) ;
V_304:
F_141 ( V_302 , V_2 ) ;
V_43:
return F_142 ( V_299 ) ;
}
static void F_143 ( struct V_1 * V_2 )
{
struct V_271 * V_298 = F_9 ( V_2 ) ;
F_144 ( ( unsigned long ) V_2 -> V_7 . V_310 & V_130 ) ;
F_138 ( V_2 ) ;
#ifdef F_131
F_139 ( V_2 -> V_7 . V_27 ) ;
#endif
F_140 ( V_298 ) ;
F_141 ( V_302 , V_2 ) ;
}
static int F_145 ( struct V_136 * V_136 , struct V_1 * V_2 )
{
int V_316 ;
#ifdef F_80
unsigned long V_317 ( V_318 ) ;
#endif
if ( ! V_2 -> V_7 . V_319 ) {
V_136 -> V_170 = V_171 ;
V_316 = - V_162 ;
goto V_43;
}
F_97 ( V_2 ) ;
V_316 = F_116 ( V_2 ) ;
if ( V_316 <= 0 )
goto V_43;
F_146 ( V_24 ) ;
if ( F_2 ( V_2 ) & V_28 )
F_51 ( V_2 , V_101 , V_28 ) ;
F_117 () ;
V_316 = F_147 ( V_136 , V_2 ) ;
F_99 ( V_2 ) ;
F_19 ( V_2 , V_28 | V_29 | V_30 ) ;
F_20 ( V_2 , V_31 ) ;
V_43:
V_2 -> V_320 = V_321 ;
return V_316 ;
}
static int F_148 ( struct V_54 * V_54 ,
struct V_322 * log )
{
struct V_58 * V_59 ;
struct V_60 * V_61 ;
struct V_1 * V_2 ;
T_1 V_323 , V_324 ;
int V_325 = 0 ;
int V_52 ;
unsigned long V_326 ;
F_149 ( & V_54 -> V_327 ) ;
V_52 = F_150 ( V_54 , log , & V_325 ) ;
if ( V_52 )
goto V_43;
if ( V_325 ) {
V_59 = V_58 ( V_54 ) ;
V_61 = F_151 ( V_59 , log -> V_328 ) ;
V_323 = V_61 -> V_329 << V_68 ;
V_324 = V_323 + ( V_61 -> V_67 << V_68 ) ;
F_34 (n, vcpu, kvm)
F_35 ( V_2 , V_323 , V_324 ) ;
V_326 = F_152 ( V_61 ) ;
memset ( V_61 -> V_330 , 0 , V_326 ) ;
}
V_52 = 0 ;
V_43:
F_153 ( & V_54 -> V_327 ) ;
return V_52 ;
}
static void F_154 ( struct V_54 * V_54 ,
struct V_60 * V_61 )
{
return;
}
static int F_155 ( struct V_54 * V_54 ,
struct V_60 * V_61 ,
const struct V_331 * V_332 )
{
return 0 ;
}
static void F_156 ( struct V_54 * V_54 ,
const struct V_331 * V_332 ,
const struct V_60 * V_333 ,
const struct V_60 * V_334 )
{
return;
}
static void F_157 ( struct V_60 * free ,
struct V_60 * V_335 )
{
return;
}
static int F_158 ( struct V_60 * V_328 ,
unsigned long V_67 )
{
return 0 ;
}
static int F_159 ( struct V_54 * V_54 ,
struct V_336 * V_337 )
{
long int V_57 ;
struct V_1 * V_2 ;
V_337 -> V_207 = 0 ;
V_337 -> V_338 = 64 ;
V_337 -> V_339 [ 0 ] . V_340 = 12 ;
V_337 -> V_339 [ 0 ] . V_341 = 0 ;
V_337 -> V_339 [ 0 ] . V_342 [ 0 ] . V_340 = 12 ;
V_337 -> V_339 [ 0 ] . V_342 [ 0 ] . V_343 = 0 ;
V_57 = 1 ;
V_2 = F_160 ( V_54 , 0 ) ;
if ( V_2 && ( V_2 -> V_7 . V_8 & V_121 ) ) {
V_337 -> V_207 = V_344 ;
V_337 -> V_339 [ V_57 ] . V_340 = 16 ;
V_337 -> V_339 [ V_57 ] . V_341 = V_345 | V_346 ;
V_337 -> V_339 [ V_57 ] . V_342 [ 0 ] . V_340 = 16 ;
V_337 -> V_339 [ V_57 ] . V_342 [ 0 ] . V_343 = 1 ;
++ V_57 ;
}
V_337 -> V_339 [ V_57 ] . V_340 = 24 ;
V_337 -> V_339 [ V_57 ] . V_341 = V_345 ;
V_337 -> V_339 [ V_57 ] . V_342 [ 0 ] . V_340 = 24 ;
V_337 -> V_339 [ V_57 ] . V_342 [ 0 ] . V_343 = 0 ;
return 0 ;
}
static int F_159 ( struct V_54 * V_54 ,
struct V_336 * V_337 )
{
F_104 () ;
}
static int F_161 ( struct V_54 * V_54 )
{
F_162 ( & V_54 -> V_7 . V_347 ) ;
#ifdef F_7
F_163 ( V_54 ) ;
#endif
if ( F_164 ( V_348 ) ) {
F_165 ( & V_349 ) ;
if ( ++ V_350 == 1 )
F_166 () ;
F_167 ( & V_349 ) ;
}
return 0 ;
}
static void F_168 ( struct V_54 * V_54 )
{
#ifdef F_169
F_170 ( ! F_171 ( & V_54 -> V_7 . V_351 ) ) ;
#endif
if ( F_164 ( V_348 ) ) {
F_165 ( & V_349 ) ;
F_95 ( V_350 == 0 ) ;
if ( -- V_350 == 0 )
F_172 () ;
F_167 ( & V_349 ) ;
}
}
static int F_173 ( void )
{
if ( F_11 ( V_352 ) )
return - V_169 ;
return 0 ;
}
static long F_174 ( struct V_353 * V_354 ,
unsigned int V_355 , unsigned long V_356 )
{
return - V_357 ;
}
int F_175 ( void )
{
int V_52 ;
V_52 = F_173 () ;
if ( V_52 < 0 )
return V_52 ;
V_358 . V_359 = V_360 ;
V_361 = & V_358 ;
V_52 = F_176 () ;
return V_52 ;
}
void F_177 ( void )
{
V_361 = NULL ;
F_178 () ;
}
