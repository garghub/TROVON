static void F_1 ( struct V_1 * V_2 , int V_3 )
{
#ifdef F_2
struct V_4 * V_5 = F_3 ( V_2 ) ;
memcpy ( V_5 -> V_6 , F_4 ( V_2 ) -> V_7 , sizeof( V_5 -> V_6 ) ) ;
V_5 -> V_8 = F_4 ( V_2 ) -> V_9 ;
V_5 -> V_10 = 0 ;
F_5 ( V_5 ) ;
#endif
V_2 -> V_3 = F_6 () ;
#ifdef F_7
V_11 -> V_12 . V_13 = V_2 -> V_14 . V_15 ;
#endif
}
static void F_8 ( struct V_1 * V_2 )
{
#ifdef F_2
struct V_4 * V_5 = F_3 ( V_2 ) ;
if ( V_5 -> V_10 ) {
F_9 ( V_2 , V_5 ) ;
}
memcpy ( F_4 ( V_2 ) -> V_7 , V_5 -> V_6 , sizeof( V_5 -> V_6 ) ) ;
F_4 ( V_2 ) -> V_9 = V_5 -> V_8 ;
F_5 ( V_5 ) ;
#endif
F_10 ( V_2 , V_16 | V_17 | V_18 ) ;
F_11 ( V_2 , V_19 ) ;
V_2 -> V_3 = - 1 ;
}
void F_12 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
V_5 -> V_20 [ 0 ] = V_2 -> V_14 . V_20 [ 0 ] ;
V_5 -> V_20 [ 1 ] = V_2 -> V_14 . V_20 [ 1 ] ;
V_5 -> V_20 [ 2 ] = V_2 -> V_14 . V_20 [ 2 ] ;
V_5 -> V_20 [ 3 ] = V_2 -> V_14 . V_20 [ 3 ] ;
V_5 -> V_20 [ 4 ] = V_2 -> V_14 . V_20 [ 4 ] ;
V_5 -> V_20 [ 5 ] = V_2 -> V_14 . V_20 [ 5 ] ;
V_5 -> V_20 [ 6 ] = V_2 -> V_14 . V_20 [ 6 ] ;
V_5 -> V_20 [ 7 ] = V_2 -> V_14 . V_20 [ 7 ] ;
V_5 -> V_20 [ 8 ] = V_2 -> V_14 . V_20 [ 8 ] ;
V_5 -> V_20 [ 9 ] = V_2 -> V_14 . V_20 [ 9 ] ;
V_5 -> V_20 [ 10 ] = V_2 -> V_14 . V_20 [ 10 ] ;
V_5 -> V_20 [ 11 ] = V_2 -> V_14 . V_20 [ 11 ] ;
V_5 -> V_20 [ 12 ] = V_2 -> V_14 . V_20 [ 12 ] ;
V_5 -> V_20 [ 13 ] = V_2 -> V_14 . V_20 [ 13 ] ;
V_5 -> V_21 = V_2 -> V_14 . V_21 ;
V_5 -> V_22 = V_2 -> V_14 . V_22 ;
V_5 -> V_23 = V_2 -> V_14 . V_23 ;
V_5 -> V_24 = V_2 -> V_14 . V_24 ;
V_5 -> V_25 = V_2 -> V_14 . V_25 ;
#ifdef F_2
V_5 -> V_26 = V_2 -> V_14 . V_26 ;
#endif
V_5 -> V_10 = true ;
}
void F_9 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
F_13 () ;
if ( ! V_5 -> V_10 )
goto V_27;
V_2 -> V_14 . V_20 [ 0 ] = V_5 -> V_20 [ 0 ] ;
V_2 -> V_14 . V_20 [ 1 ] = V_5 -> V_20 [ 1 ] ;
V_2 -> V_14 . V_20 [ 2 ] = V_5 -> V_20 [ 2 ] ;
V_2 -> V_14 . V_20 [ 3 ] = V_5 -> V_20 [ 3 ] ;
V_2 -> V_14 . V_20 [ 4 ] = V_5 -> V_20 [ 4 ] ;
V_2 -> V_14 . V_20 [ 5 ] = V_5 -> V_20 [ 5 ] ;
V_2 -> V_14 . V_20 [ 6 ] = V_5 -> V_20 [ 6 ] ;
V_2 -> V_14 . V_20 [ 7 ] = V_5 -> V_20 [ 7 ] ;
V_2 -> V_14 . V_20 [ 8 ] = V_5 -> V_20 [ 8 ] ;
V_2 -> V_14 . V_20 [ 9 ] = V_5 -> V_20 [ 9 ] ;
V_2 -> V_14 . V_20 [ 10 ] = V_5 -> V_20 [ 10 ] ;
V_2 -> V_14 . V_20 [ 11 ] = V_5 -> V_20 [ 11 ] ;
V_2 -> V_14 . V_20 [ 12 ] = V_5 -> V_20 [ 12 ] ;
V_2 -> V_14 . V_20 [ 13 ] = V_5 -> V_20 [ 13 ] ;
V_2 -> V_14 . V_21 = V_5 -> V_21 ;
V_2 -> V_14 . V_22 = V_5 -> V_22 ;
V_2 -> V_14 . V_23 = V_5 -> V_23 ;
V_2 -> V_14 . V_24 = V_5 -> V_24 ;
V_2 -> V_14 . V_25 = V_5 -> V_25 ;
V_2 -> V_14 . V_28 = V_5 -> V_28 ;
V_2 -> V_14 . V_29 = V_5 -> V_29 ;
V_2 -> V_14 . V_30 = V_5 -> V_30 ;
V_2 -> V_14 . V_31 = V_5 -> V_31 ;
#ifdef F_2
V_2 -> V_14 . V_26 = V_5 -> V_26 ;
#endif
V_5 -> V_10 = false ;
V_27:
F_14 () ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_32 = 1 ;
if ( F_16 ( V_33 , V_2 ) )
F_17 ( V_2 , 0 , 0 ) ;
return V_32 ;
}
static void F_18 ( struct V_34 * V_34 , unsigned long V_35 ,
unsigned long V_36 )
{
long V_37 ;
struct V_1 * V_2 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
V_39 = V_38 ( V_34 ) ;
F_19 (memslot, slots) {
unsigned long V_42 , V_43 ;
T_1 V_44 , V_45 ;
V_42 = F_20 ( V_35 , V_41 -> V_46 ) ;
V_43 = F_21 ( V_36 , V_41 -> V_46 +
( V_41 -> V_47 << V_48 ) ) ;
if ( V_42 >= V_43 )
continue;
V_44 = F_22 ( V_42 , V_41 ) ;
V_45 = F_22 ( V_43 + V_49 - 1 , V_41 ) ;
F_23 (i, vcpu, kvm)
F_24 ( V_2 , V_44 << V_48 ,
V_45 << V_48 ) ;
}
}
static int F_25 ( struct V_34 * V_34 , unsigned long V_50 )
{
F_26 ( V_50 ) ;
F_18 ( V_34 , V_50 , V_50 + V_49 ) ;
return 0 ;
}
static int F_27 ( struct V_34 * V_34 , unsigned long V_35 ,
unsigned long V_36 )
{
F_18 ( V_34 , V_35 , V_36 ) ;
return 0 ;
}
static int F_28 ( struct V_34 * V_34 , unsigned long V_50 )
{
return 0 ;
}
static int F_29 ( struct V_34 * V_34 , unsigned long V_50 )
{
return 0 ;
}
static void F_30 ( struct V_34 * V_34 , unsigned long V_50 , T_2 V_51 )
{
F_18 ( V_34 , V_50 , V_50 + V_49 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_3 V_52 = F_32 ( V_2 ) ;
T_3 V_53 = V_52 ;
V_53 &= V_54 | V_55 | V_56 | V_57 | V_58 | V_59 ;
V_53 |= V_60 | V_61 | V_62 | V_63 | V_64 | V_65 ;
V_53 |= ( V_52 & V_2 -> V_14 . V_66 ) ;
#ifdef F_2
V_53 |= V_67 | V_68 ;
#endif
V_2 -> V_14 . V_69 = V_53 ;
}
static void F_33 ( struct V_1 * V_2 , T_4 V_70 )
{
T_3 V_71 = F_32 ( V_2 ) ;
#ifdef F_34
F_35 ( V_72 L_1 , V_70 ) ;
#endif
V_70 &= F_4 ( V_2 ) -> V_73 ;
F_36 ( V_2 , V_70 ) ;
F_31 ( V_2 ) ;
if ( V_70 & V_74 ) {
if ( ! V_2 -> V_14 . V_75 ) {
F_37 ( V_2 ) ;
F_38 ( V_76 , & V_2 -> V_77 ) ;
V_2 -> V_78 . V_79 ++ ;
V_70 &= ~ V_74 ;
F_36 ( V_2 , V_70 ) ;
}
}
if ( ( F_32 ( V_2 ) & ( V_64 | V_62 | V_63 ) ) !=
( V_71 & ( V_64 | V_62 | V_63 ) ) ) {
F_39 ( V_2 ) ;
F_40 ( V_2 , F_41 ( V_2 ) ) ;
if ( ! ( V_70 & V_64 ) && V_2 -> V_14 . V_80 ) {
struct V_81 * V_82 = & V_2 -> V_14 ;
if ( V_70 & V_63 )
F_40 ( V_2 , V_82 -> V_83 ) ;
else
F_40 ( V_2 , V_82 -> V_80 ) ;
}
}
if ( V_2 -> V_14 . V_80 &&
! ( V_71 & V_64 ) && ! ( V_71 & V_56 ) && ( V_70 & V_56 ) ) {
F_17 ( V_2 , ( V_84 ) V_2 -> V_14 . V_80 ,
~ 0xFFFUL ) ;
}
if ( F_32 ( V_2 ) & V_16 )
F_42 ( V_2 , V_85 , V_16 ) ;
}
void F_43 ( struct V_1 * V_2 , T_5 V_86 )
{
T_5 V_87 ;
V_2 -> V_14 . V_88 &= ~ V_89 ;
V_2 -> V_14 . V_86 = V_86 ;
#ifdef F_2
if ( ( V_86 >= 0x330000 ) && ( V_86 < 0x70330000 ) ) {
F_44 ( V_2 ) ;
if ( ! F_4 ( V_2 ) -> V_90 )
F_4 ( V_2 ) -> V_91 = 0xfff00000 ;
F_4 ( V_2 ) -> V_73 = 0xffffffffffffffffULL ;
V_2 -> V_14 . V_92 = V_93 ;
} else
#endif
{
F_45 ( V_2 ) ;
if ( ! F_4 ( V_2 ) -> V_90 )
F_4 ( V_2 ) -> V_91 = 0 ;
F_4 ( V_2 ) -> V_73 = 0xffffffffULL ;
V_2 -> V_14 . V_92 = V_94 ;
}
F_46 ( V_2 ) ;
V_2 -> V_14 . V_88 &= ~ V_95 ;
if ( V_2 -> V_14 . V_96 . V_97 ( V_2 ) && ( F_47 () & V_68 ) &&
! strcmp ( V_98 -> V_99 , L_2 ) )
V_2 -> V_14 . V_88 |= V_95 ;
if ( ! strcmp ( V_98 -> V_99 , L_3 ) )
F_4 ( V_2 ) -> V_73 &= ~ ( V_54 | V_55 ) ;
switch ( F_48 ( V_86 ) ) {
case V_100 :
case V_101 :
case V_102 :
case V_103 :
V_2 -> V_14 . V_88 |= V_104 |
V_105 ;
break;
}
#ifdef F_7
V_2 -> V_14 . V_88 |= V_95 ;
#endif
asm ( "mfpvr %0" : "=r"(host_pvr));
switch ( V_87 ) {
case 0x00080200 :
case 0x00088202 :
case 0x70000100 :
case 0x00080100 :
case 0x00083203 :
case 0x00083213 :
case 0x00083204 :
case 0x00083214 :
case 0x00087200 :
V_2 -> V_14 . V_88 |= V_106 ;
F_49 ( V_107 , F_50 ( V_107 ) | ( 1 << 29 ) ) ;
}
}
static void F_51 ( struct V_1 * V_2 , struct V_108 * V_51 )
{
struct V_109 * V_110 ;
T_4 V_111 ;
T_5 * V_109 ;
int V_37 ;
V_110 = F_52 ( V_2 -> V_34 , V_51 -> V_112 >> V_48 ) ;
if ( F_53 ( V_110 ) )
return;
V_111 = V_51 -> V_112 & ~ V_113 ;
V_111 &= ~ 0xFFFULL ;
V_111 /= 4 ;
F_54 ( V_110 ) ;
V_109 = F_55 ( V_110 ) ;
for ( V_37 = V_111 ; V_37 < V_111 + ( V_114 / 4 ) ; V_37 ++ )
if ( ( F_56 ( V_109 [ V_37 ] ) & 0xff0007ff ) == V_115 )
V_109 [ V_37 ] &= F_57 ( 0xfffffff7 ) ;
F_58 ( V_109 ) ;
F_59 ( V_110 ) ;
}
static int F_60 ( struct V_1 * V_2 , T_1 V_44 )
{
T_3 V_116 = V_2 -> V_14 . V_80 ;
if ( ! ( F_32 ( V_2 ) & V_56 ) )
V_116 = ( V_84 ) V_116 ;
if ( F_61 ( V_116 ) &&
F_61 ( ( V_116 & V_117 ) >> V_48 == V_44 ) ) {
return 1 ;
}
return F_62 ( V_2 -> V_34 , V_44 ) ;
}
int F_63 ( struct V_118 * V_119 , struct V_1 * V_2 ,
T_3 V_120 , int V_121 )
{
bool V_122 = ( V_121 == V_123 ) ;
bool V_124 = false ;
int V_32 = V_125 ;
int V_126 ;
int V_127 = 0 ;
struct V_108 V_51 ;
bool V_128 = false ;
bool V_129 = ( F_32 ( V_2 ) & V_63 ) ? true : false ;
bool V_130 = ( F_32 ( V_2 ) & V_62 ) ? true : false ;
T_4 V_131 ;
V_126 = V_122 ? V_129 : V_130 ;
if ( V_122 && ( V_2 -> V_14 . V_30 & V_132 ) )
V_124 = true ;
if ( V_126 ) {
V_127 = V_2 -> V_14 . V_96 . V_133 ( V_2 , V_120 , & V_51 , V_122 , V_124 ) ;
} else {
V_51 . V_134 = true ;
V_51 . V_135 = true ;
V_51 . V_136 = true ;
V_51 . V_112 = V_120 & V_117 ;
V_51 . V_120 = V_120 ;
V_51 . V_137 = V_120 >> 12 ;
V_51 . V_138 = V_139 ;
}
switch ( F_32 ( V_2 ) & ( V_63 | V_62 ) ) {
case 0 :
V_51 . V_137 |= ( ( T_4 ) V_140 << ( V_141 - 12 ) ) ;
break;
case V_63 :
case V_62 :
V_2 -> V_14 . V_96 . V_142 ( V_2 , V_120 >> V_141 , & V_131 ) ;
if ( ( F_32 ( V_2 ) & ( V_63 | V_62 ) ) == V_63 )
V_51 . V_137 |= ( ( T_4 ) V_143 << ( V_141 - 12 ) ) ;
else
V_51 . V_137 |= ( ( T_4 ) V_144 << ( V_141 - 12 ) ) ;
V_51 . V_137 |= V_131 ;
if ( V_131 == - 1 )
V_127 = - V_145 ;
break;
}
if ( V_2 -> V_14 . V_96 . V_97 ( V_2 ) &&
( ! ( V_2 -> V_14 . V_88 & V_95 ) ) ) {
V_51 . V_134 = ! V_122 ;
}
if ( V_127 == - V_146 ) {
T_4 V_147 = V_2 -> V_14 . V_28 ;
T_4 V_70 = F_32 ( V_2 ) ;
F_64 ( V_2 , F_65 ( V_2 ) ) ;
F_66 ( V_2 , V_2 -> V_14 . V_30 ) ;
F_36 ( V_2 , V_70 | ( V_147 & 0xf8000000ULL ) ) ;
F_67 ( V_2 , V_121 ) ;
} else if ( V_127 == - V_148 ) {
T_5 V_149 = V_2 -> V_14 . V_30 ;
T_4 V_147 = V_2 -> V_14 . V_28 ;
T_4 V_70 = F_32 ( V_2 ) ;
F_64 ( V_2 , F_65 ( V_2 ) ) ;
V_149 = ( V_149 & ~ V_150 ) | V_151 ;
F_66 ( V_2 , V_149 ) ;
F_36 ( V_2 , V_70 | ( V_147 & 0xf8000000ULL ) ) ;
F_67 ( V_2 , V_121 ) ;
} else if ( V_127 == - V_145 ) {
F_64 ( V_2 , F_65 ( V_2 ) ) ;
F_67 ( V_2 , V_121 + 0x80 ) ;
} else if ( ! V_128 &&
F_60 ( V_2 , V_51 . V_112 >> V_48 ) ) {
if ( V_122 && ! ( V_2 -> V_14 . V_30 & V_150 ) ) {
F_68 ( V_2 , & V_51 ) ;
}
F_69 ( V_2 , & V_51 , V_124 ) ;
if ( V_122 )
V_2 -> V_78 . V_152 ++ ;
else if ( V_2 -> V_14 . V_96 . V_97 ( V_2 ) &&
( ! ( V_2 -> V_14 . V_88 & V_95 ) ) )
F_51 ( V_2 , & V_51 ) ;
} else {
V_2 -> V_78 . V_153 ++ ;
V_2 -> V_14 . V_154 = V_51 . V_112 ;
V_2 -> V_14 . V_155 = V_51 . V_120 ;
V_32 = F_70 ( V_119 , V_2 ) ;
if ( V_32 == V_156 )
V_32 = V_157 ;
}
return V_32 ;
}
static inline int F_71 ( int V_37 )
{
return V_37 * V_158 ;
}
void F_10 ( struct V_1 * V_2 , T_3 V_70 )
{
struct V_159 * V_160 = & V_11 -> V_12 ;
if ( V_70 & V_18 )
V_70 |= V_16 | V_17 ;
V_70 &= V_2 -> V_14 . V_66 ;
if ( ! V_70 )
return;
#ifdef F_72
F_35 ( V_72 L_4 , V_70 ) ;
#endif
if ( V_70 & V_16 ) {
if ( V_160 -> V_161 -> V_70 & V_16 )
F_73 ( V_11 ) ;
V_160 -> V_162 = NULL ;
}
#ifdef F_74
if ( V_70 & V_17 ) {
if ( V_11 -> V_12 . V_161 -> V_70 & V_17 )
F_75 ( V_11 ) ;
V_160 -> V_163 = NULL ;
}
#endif
V_2 -> V_14 . V_66 &= ~ ( V_70 | V_18 ) ;
F_31 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_3 V_164 )
{
#ifdef F_2
if ( ! ( V_2 -> V_14 . V_26 & ( 1ULL << V_164 ) ) ) {
return;
}
switch ( V_164 ) {
case V_19 :
V_2 -> V_14 . V_165 = F_50 ( V_166 ) ;
F_49 ( V_166 , V_11 -> V_12 . V_165 ) ;
V_2 -> V_14 . V_26 &= ~ V_167 ;
break;
}
#endif
}
static int F_76 ( struct V_1 * V_2 )
{
T_3 V_168 = F_41 ( V_2 ) ;
T_5 V_31 = F_77 ( V_2 ) ;
int V_169 ;
V_169 = F_78 ( V_2 , & V_168 , sizeof( T_5 ) , & V_31 , false ) ;
if ( V_169 == - V_146 ) {
T_3 V_70 = F_32 ( V_2 ) ;
V_70 = F_79 ( V_70 , 33 , 33 , 1 ) ;
V_70 = F_79 ( V_70 , 34 , 36 , 0 ) ;
V_70 = F_79 ( V_70 , 42 , 47 , 0 ) ;
F_36 ( V_2 , V_70 ) ;
F_67 ( V_2 , V_170 ) ;
return V_171 ;
}
return V_172 ;
}
static int F_80 ( struct V_1 * V_2 , unsigned int V_173 )
{
if ( ! ( V_2 -> V_14 . V_88 & V_174 ) )
return V_172 ;
if ( F_76 ( V_2 ) == V_172 )
return V_175 ;
return V_171 ;
}
static int F_42 ( struct V_1 * V_2 , unsigned int V_173 ,
T_3 V_70 )
{
struct V_159 * V_160 = & V_11 -> V_12 ;
if ( V_2 -> V_14 . V_88 & V_174 )
return V_125 ;
if ( ! ( F_32 ( V_2 ) & V_70 ) ) {
F_67 ( V_2 , V_173 ) ;
return V_125 ;
}
if ( V_70 == V_18 ) {
#ifdef F_81
if ( ! F_82 ( V_176 ) )
#endif
{
F_83 ( V_2 , V_177 ) ;
return V_125 ;
}
V_70 = V_16 | V_17 | V_18 ;
}
V_70 &= ~ V_2 -> V_14 . V_66 ;
if ( ! V_70 )
return V_125 ;
#ifdef F_72
F_35 ( V_72 L_5 , V_70 ) ;
#endif
if ( V_70 & V_16 ) {
F_13 () ;
F_84 () ;
F_85 ( & V_2 -> V_14 . V_178 ) ;
V_160 -> V_162 = & V_2 -> V_14 . V_178 ;
F_14 () ;
}
if ( V_70 & V_17 ) {
#ifdef F_74
F_13 () ;
F_86 () ;
F_87 ( & V_2 -> V_14 . V_179 ) ;
V_160 -> V_163 = & V_2 -> V_14 . V_179 ;
F_14 () ;
#endif
}
V_160 -> V_161 -> V_70 |= V_70 ;
V_2 -> V_14 . V_66 |= V_70 ;
F_31 ( V_2 ) ;
return V_125 ;
}
static void F_88 ( struct V_1 * V_2 )
{
unsigned long V_180 ;
V_180 = V_2 -> V_14 . V_66 & ~ V_11 -> V_12 . V_161 -> V_70 ;
if ( ! V_180 )
return;
if ( V_180 & V_16 ) {
F_13 () ;
F_84 () ;
F_85 ( & V_2 -> V_14 . V_178 ) ;
F_14 () ;
}
#ifdef F_74
if ( V_180 & V_17 ) {
F_13 () ;
F_86 () ;
F_87 ( & V_2 -> V_14 . V_179 ) ;
F_14 () ;
}
#endif
V_11 -> V_12 . V_161 -> V_70 |= V_180 ;
}
static void F_89 ( struct V_1 * V_2 , T_3 V_164 )
{
V_2 -> V_14 . V_181 &= ~ ( 0xffULL << 56 ) ;
V_2 -> V_14 . V_181 |= ( V_164 << 56 ) ;
F_67 ( V_2 , V_182 ) ;
}
static void F_90 ( struct V_1 * V_2 , T_3 V_164 )
{
enum V_183 V_184 = V_175 ;
if ( ! ( F_32 ( V_2 ) & V_64 ) )
V_184 = F_91 ( V_2 -> V_119 , V_2 ) ;
if ( ( V_184 != V_172 ) && ( V_184 != V_171 ) ) {
F_89 ( V_2 , V_164 ) ;
}
}
static int F_92 ( struct V_1 * V_2 , T_3 V_164 )
{
bool V_185 ;
F_93 ( ! F_82 ( V_186 ) ) ;
switch ( V_164 ) {
case V_19 :
case V_187 :
V_185 = ( V_2 -> V_14 . V_181 & ( 1ULL << V_164 ) ) ;
break;
case V_188 :
V_185 = F_32 ( V_2 ) & V_189 ;
break;
default:
V_185 = false ;
break;
}
if ( ! V_185 ) {
F_89 ( V_2 , V_164 ) ;
return V_125 ;
}
switch ( V_164 ) {
case V_19 :
V_11 -> V_12 . V_165 = F_50 ( V_166 ) ;
F_49 ( V_166 , V_2 -> V_14 . V_165 ) ;
V_2 -> V_14 . V_26 |= V_167 ;
break;
default:
F_90 ( V_2 , V_164 ) ;
break;
}
return V_125 ;
}
int F_94 ( struct V_118 * V_119 , struct V_1 * V_2 ,
unsigned int V_173 )
{
int V_32 = V_157 ;
int V_190 ;
V_2 -> V_78 . V_191 ++ ;
V_119 -> V_192 = V_193 ;
V_119 -> V_194 = 1 ;
F_95 ( V_173 , V_2 ) ;
F_96 () ;
switch ( V_173 ) {
case V_170 :
{
T_3 V_28 = V_2 -> V_14 . V_28 ;
V_2 -> V_78 . V_195 ++ ;
#ifdef F_7
{
struct V_4 * V_5 ;
T_5 V_196 ;
V_5 = F_3 ( V_2 ) ;
V_196 = V_5 -> V_196 [ F_41 ( V_2 ) >> V_141 ] ;
F_5 ( V_5 ) ;
if ( V_196 == V_197 ) {
F_40 ( V_2 , F_41 ( V_2 ) ) ;
V_32 = V_125 ;
break;
}
}
#endif
if ( V_28 & 0x40000000 ) {
int V_198 = F_97 ( & V_2 -> V_34 -> V_199 ) ;
V_32 = F_63 ( V_119 , V_2 , F_41 ( V_2 ) , V_173 ) ;
F_98 ( & V_2 -> V_34 -> V_199 , V_198 ) ;
V_2 -> V_78 . V_200 ++ ;
} else if ( V_2 -> V_14 . V_96 . V_97 ( V_2 ) &&
( ! ( V_2 -> V_14 . V_88 & V_95 ) ) ) {
F_17 ( V_2 , F_41 ( V_2 ) , ~ 0xFFFUL ) ;
V_32 = V_125 ;
} else {
T_4 V_70 = F_32 ( V_2 ) ;
V_70 |= V_28 & 0x58000000 ;
F_36 ( V_2 , V_70 ) ;
F_67 ( V_2 , V_173 ) ;
V_32 = V_125 ;
}
break;
}
case V_123 :
{
T_3 V_201 = F_65 ( V_2 ) ;
T_5 V_30 = V_2 -> V_14 . V_30 ;
V_2 -> V_78 . V_202 ++ ;
#ifdef F_7
{
struct V_4 * V_5 ;
T_5 V_196 ;
V_5 = F_3 ( V_2 ) ;
V_196 = V_5 -> V_196 [ V_201 >> V_141 ] ;
F_5 ( V_5 ) ;
if ( V_196 == V_197 ) {
F_40 ( V_2 , V_201 ) ;
V_32 = V_125 ;
break;
}
}
#endif
if ( V_30 & ( V_150 | V_151 ) ) {
int V_198 = F_97 ( & V_2 -> V_34 -> V_199 ) ;
V_32 = F_63 ( V_119 , V_2 , V_201 , V_173 ) ;
F_98 ( & V_2 -> V_34 -> V_199 , V_198 ) ;
} else {
F_64 ( V_2 , V_201 ) ;
F_66 ( V_2 , V_30 ) ;
F_67 ( V_2 , V_173 ) ;
V_32 = V_125 ;
}
break;
}
case V_203 :
if ( F_40 ( V_2 , F_65 ( V_2 ) ) < 0 ) {
F_64 ( V_2 , F_65 ( V_2 ) ) ;
F_67 ( V_2 ,
V_203 ) ;
}
V_32 = V_125 ;
break;
case V_204 :
if ( F_40 ( V_2 , F_41 ( V_2 ) ) < 0 ) {
F_67 ( V_2 ,
V_204 ) ;
}
V_32 = V_125 ;
break;
case V_205 :
case V_206 :
case V_207 :
V_2 -> V_78 . V_208 ++ ;
V_32 = V_125 ;
break;
case V_209 :
case V_210 :
case V_211 :
V_2 -> V_78 . V_212 ++ ;
V_32 = V_125 ;
break;
case V_213 :
V_32 = V_125 ;
break;
case V_214 :
case V_215 :
{
enum V_183 V_184 ;
T_3 V_216 ;
V_217:
V_216 = V_2 -> V_14 . V_28 & 0x1f0000ull ;
if ( F_32 ( V_2 ) & V_64 ) {
#ifdef F_34
F_35 ( V_72 L_6 , F_41 ( V_2 ) , F_77 ( V_2 ) ) ;
#endif
if ( ( F_77 ( V_2 ) & 0xff0007ff ) !=
( V_115 & 0xfffffff7 ) ) {
F_83 ( V_2 , V_216 ) ;
V_32 = V_125 ;
break;
}
}
V_2 -> V_78 . V_218 ++ ;
V_184 = F_91 ( V_119 , V_2 ) ;
switch ( V_184 ) {
case V_172 :
V_32 = V_219 ;
break;
case V_171 :
V_32 = V_125 ;
break;
case V_175 :
F_35 ( V_220 L_7 ,
V_221 , F_41 ( V_2 ) , F_77 ( V_2 ) ) ;
F_83 ( V_2 , V_216 ) ;
V_32 = V_125 ;
break;
case V_222 :
V_119 -> V_192 = V_223 ;
V_32 = V_156 ;
break;
case V_224 :
V_32 = V_156 ;
break;
default:
F_99 () ;
}
break;
}
case V_225 :
if ( V_2 -> V_14 . V_226 &&
( F_100 ( V_2 ) == 0x44000022 ) &&
! ( F_32 ( V_2 ) & V_64 ) ) {
T_3 V_227 = F_101 ( V_2 , 3 ) ;
int V_37 ;
#ifdef F_2
if ( F_102 ( V_2 , V_227 ) == V_172 ) {
V_32 = V_125 ;
break;
}
#endif
V_119 -> V_228 . V_229 = V_227 ;
for ( V_37 = 0 ; V_37 < 9 ; ++ V_37 ) {
T_3 V_20 = F_101 ( V_2 , 4 + V_37 ) ;
V_119 -> V_228 . args [ V_37 ] = V_20 ;
}
V_119 -> V_192 = V_230 ;
V_2 -> V_14 . V_231 = 1 ;
V_32 = V_157 ;
} else if ( V_2 -> V_14 . V_232 &&
( ( ( T_5 ) F_101 ( V_2 , 3 ) ) == V_233 ) &&
( ( ( T_5 ) F_101 ( V_2 , 4 ) ) == V_234 ) ) {
T_4 * V_235 = V_119 -> V_236 . V_235 ;
int V_37 ;
V_119 -> V_192 = V_237 ;
for ( V_37 = 0 ; V_37 < 32 ; V_37 ++ )
V_235 [ V_37 ] = F_101 ( V_2 , V_37 ) ;
V_2 -> V_14 . V_238 = 1 ;
V_32 = V_156 ;
} else if ( ! ( F_32 ( V_2 ) & V_64 ) &&
( ( ( T_5 ) F_101 ( V_2 , 0 ) ) == V_239 ) ) {
F_103 ( V_2 , 3 , F_104 ( V_2 ) ) ;
V_32 = V_125 ;
} else {
V_2 -> V_78 . V_240 ++ ;
F_67 ( V_2 , V_173 ) ;
V_32 = V_125 ;
}
break;
case V_85 :
case V_241 :
case V_242 :
{
int V_243 = 0 ;
switch ( V_173 ) {
case V_85 : V_243 = V_16 ; break;
case V_241 : V_243 = V_17 ; break;
case V_242 : V_243 = V_18 ; break;
}
switch ( F_80 ( V_2 , V_173 ) ) {
case V_172 :
V_32 = F_42 ( V_2 , V_173 , V_243 ) ;
break;
case V_175 :
goto V_217;
break;
default:
break;
}
break;
}
case V_244 :
if ( F_76 ( V_2 ) == V_172 ) {
T_5 V_31 = F_77 ( V_2 ) ;
T_5 V_149 ;
T_4 V_201 ;
V_149 = F_105 ( V_2 , V_31 ) ;
V_201 = F_106 ( V_2 , V_31 ) ;
F_66 ( V_2 , V_149 ) ;
F_64 ( V_2 , V_201 ) ;
F_67 ( V_2 , V_173 ) ;
}
V_32 = V_125 ;
break;
#ifdef F_2
case V_182 :
F_92 ( V_2 , V_2 -> V_14 . V_26 >> 56 ) ;
V_32 = V_125 ;
break;
#endif
case V_245 :
case V_246 :
F_67 ( V_2 , V_173 ) ;
V_32 = V_125 ;
break;
default:
{
T_3 V_28 = V_2 -> V_14 . V_28 ;
F_35 ( V_247 L_8 ,
V_173 , F_41 ( V_2 ) , V_28 ) ;
V_32 = V_157 ;
F_99 () ;
break;
}
}
if ( ! ( V_32 & V_157 ) ) {
V_190 = F_107 ( V_2 ) ;
if ( V_190 <= 0 )
V_32 = V_190 ;
else {
F_108 () ;
}
F_88 ( V_2 ) ;
}
F_109 ( V_32 , V_2 ) ;
return V_32 ;
}
static int F_110 ( struct V_1 * V_2 ,
struct V_248 * V_249 )
{
struct V_250 * V_251 = F_4 ( V_2 ) ;
int V_37 ;
V_249 -> V_86 = V_2 -> V_14 . V_86 ;
V_249 -> V_252 . V_190 . V_253 = F_4 ( V_2 ) -> V_253 ;
if ( V_2 -> V_14 . V_88 & V_89 ) {
for ( V_37 = 0 ; V_37 < 64 ; V_37 ++ ) {
V_249 -> V_252 . V_190 . V_254 . V_6 [ V_37 ] . V_255 = V_2 -> V_14 . V_6 [ V_37 ] . V_256 | V_37 ;
V_249 -> V_252 . V_190 . V_254 . V_6 [ V_37 ] . V_257 = V_2 -> V_14 . V_6 [ V_37 ] . V_258 ;
}
} else {
for ( V_37 = 0 ; V_37 < 16 ; V_37 ++ )
V_249 -> V_252 . V_190 . V_259 . V_196 [ V_37 ] = F_111 ( V_2 , V_37 ) ;
for ( V_37 = 0 ; V_37 < 8 ; V_37 ++ ) {
V_249 -> V_252 . V_190 . V_259 . V_260 [ V_37 ] = V_251 -> V_260 [ V_37 ] . V_261 ;
V_249 -> V_252 . V_190 . V_259 . V_262 [ V_37 ] = V_251 -> V_262 [ V_37 ] . V_261 ;
}
}
return 0 ;
}
static int F_112 ( struct V_1 * V_2 ,
struct V_248 * V_249 )
{
struct V_250 * V_251 = F_4 ( V_2 ) ;
int V_37 ;
F_43 ( V_2 , V_249 -> V_86 ) ;
V_251 -> V_253 = V_249 -> V_252 . V_190 . V_253 ;
if ( V_2 -> V_14 . V_88 & V_89 ) {
for ( V_37 = 0 ; V_37 < 64 ; V_37 ++ ) {
V_2 -> V_14 . V_96 . V_263 ( V_2 , V_249 -> V_252 . V_190 . V_254 . V_6 [ V_37 ] . V_257 ,
V_249 -> V_252 . V_190 . V_254 . V_6 [ V_37 ] . V_255 ) ;
}
} else {
for ( V_37 = 0 ; V_37 < 16 ; V_37 ++ ) {
V_2 -> V_14 . V_96 . V_264 ( V_2 , V_37 , V_249 -> V_252 . V_190 . V_259 . V_196 [ V_37 ] ) ;
}
for ( V_37 = 0 ; V_37 < 8 ; V_37 ++ ) {
F_113 ( V_2 , & ( V_251 -> V_260 [ V_37 ] ) , false ,
( T_5 ) V_249 -> V_252 . V_190 . V_259 . V_260 [ V_37 ] ) ;
F_113 ( V_2 , & ( V_251 -> V_260 [ V_37 ] ) , true ,
( T_5 ) ( V_249 -> V_252 . V_190 . V_259 . V_260 [ V_37 ] >> 32 ) ) ;
F_113 ( V_2 , & ( V_251 -> V_262 [ V_37 ] ) , false ,
( T_5 ) V_249 -> V_252 . V_190 . V_259 . V_262 [ V_37 ] ) ;
F_113 ( V_2 , & ( V_251 -> V_262 [ V_37 ] ) , true ,
( T_5 ) ( V_249 -> V_252 . V_190 . V_259 . V_262 [ V_37 ] >> 32 ) ) ;
}
}
F_17 ( V_2 , 0 , 0 ) ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 , T_4 V_265 ,
union V_266 * V_267 )
{
int V_32 = 0 ;
switch ( V_265 ) {
case V_268 :
* V_267 = F_115 ( V_265 , F_4 ( V_2 ) -> V_91 ) ;
break;
case V_269 :
if ( V_2 -> V_14 . V_270 & V_59 )
* V_267 = F_115 ( V_265 , V_271 ) ;
else
* V_267 = F_115 ( V_265 , 0 ) ;
break;
default:
V_32 = - V_145 ;
break;
}
return V_32 ;
}
static void F_116 ( struct V_1 * V_2 , T_4 V_272 )
{
if ( V_272 & V_271 )
V_2 -> V_14 . V_270 |= V_59 ;
else
V_2 -> V_14 . V_270 &= ~ V_59 ;
}
static int F_117 ( struct V_1 * V_2 , T_4 V_265 ,
union V_266 * V_267 )
{
int V_32 = 0 ;
switch ( V_265 ) {
case V_268 :
F_4 ( V_2 ) -> V_91 = F_118 ( V_265 , * V_267 ) ;
F_4 ( V_2 ) -> V_90 = true ;
break;
case V_269 :
F_116 ( V_2 , F_118 ( V_265 , * V_267 ) ) ;
break;
default:
V_32 = - V_145 ;
break;
}
return V_32 ;
}
static struct V_1 * F_119 ( struct V_34 * V_34 ,
unsigned int V_265 )
{
struct V_250 * V_273 ;
struct V_1 * V_2 ;
int V_274 = - V_275 ;
unsigned long V_276 ;
V_2 = F_120 ( V_277 , V_278 ) ;
if ( ! V_2 )
goto V_27;
V_273 = F_121 ( sizeof( struct V_250 ) ) ;
if ( ! V_273 )
goto V_279;
V_2 -> V_14 . V_280 = V_273 ;
#ifdef F_122
V_2 -> V_14 . V_15 =
F_123 ( sizeof( * V_2 -> V_14 . V_15 ) , V_278 ) ;
if ( ! V_2 -> V_14 . V_15 )
goto V_281;
#endif
V_274 = F_124 ( V_2 , V_34 , V_265 ) ;
if ( V_274 )
goto V_282;
V_274 = - V_275 ;
V_276 = F_125 ( V_278 | V_283 ) ;
if ( ! V_276 )
goto V_284;
V_2 -> V_14 . V_285 = ( void * ) ( V_276 + V_49 - 4096 ) ;
#ifdef F_2
#ifdef F_126
V_2 -> V_14 . V_286 = true ;
#else
V_2 -> V_14 . V_286 = false ;
#endif
V_2 -> V_14 . V_86 = 0x3C0301 ;
if ( F_127 ( V_287 ) )
V_2 -> V_14 . V_86 = F_50 ( V_288 ) ;
V_2 -> V_14 . V_270 = V_56 ;
#else
V_2 -> V_14 . V_86 = 0x84202 ;
#endif
F_43 ( V_2 , V_2 -> V_14 . V_86 ) ;
V_2 -> V_14 . V_289 = 64 ;
V_2 -> V_14 . V_69 = V_290 & ~ V_59 ;
V_274 = F_128 ( V_2 ) ;
if ( V_274 < 0 )
goto V_284;
return V_2 ;
V_284:
F_129 ( V_2 ) ;
V_282:
#ifdef F_122
F_130 ( V_2 -> V_14 . V_15 ) ;
V_281:
#endif
F_131 ( V_273 ) ;
V_279:
F_132 ( V_277 , V_2 ) ;
V_27:
return F_133 ( V_274 ) ;
}
static void F_134 ( struct V_1 * V_2 )
{
struct V_250 * V_273 = F_4 ( V_2 ) ;
F_135 ( ( unsigned long ) V_2 -> V_14 . V_285 & V_113 ) ;
F_129 ( V_2 ) ;
#ifdef F_122
F_130 ( V_2 -> V_14 . V_15 ) ;
#endif
F_131 ( V_273 ) ;
F_132 ( V_277 , V_2 ) ;
}
static int F_136 ( struct V_118 * V_118 , struct V_1 * V_2 )
{
int V_169 ;
#ifdef F_74
unsigned long V_291 ( V_292 ) ;
#endif
if ( ! V_2 -> V_14 . V_293 ) {
V_118 -> V_192 = V_294 ;
V_169 = - V_145 ;
goto V_27;
}
V_169 = F_107 ( V_2 ) ;
if ( V_169 <= 0 )
goto V_27;
if ( V_11 -> V_12 . V_161 -> V_70 & V_16 )
F_73 ( V_11 ) ;
#ifdef F_74
if ( V_11 -> V_12 . V_161 -> V_70 & V_17 )
F_75 ( V_11 ) ;
#endif
#ifdef F_81
if ( V_11 -> V_12 . V_161 -> V_70 & V_18 )
F_137 ( V_11 ) ;
#endif
if ( F_32 ( V_2 ) & V_16 )
F_42 ( V_2 , V_85 , V_16 ) ;
F_108 () ;
V_169 = F_138 ( V_118 , V_2 ) ;
F_10 ( V_2 , V_16 | V_17 | V_18 ) ;
F_11 ( V_2 , V_19 ) ;
V_27:
V_2 -> V_295 = V_296 ;
return V_169 ;
}
static int F_139 ( struct V_34 * V_34 ,
struct V_297 * log )
{
struct V_40 * V_41 ;
struct V_1 * V_2 ;
T_3 V_298 , V_299 ;
int V_300 = 0 ;
int V_32 ;
unsigned long V_301 ;
F_140 ( & V_34 -> V_302 ) ;
V_32 = F_141 ( V_34 , log , & V_300 ) ;
if ( V_32 )
goto V_27;
if ( V_300 ) {
V_41 = F_142 ( V_34 -> V_303 , log -> V_304 ) ;
V_298 = V_41 -> V_305 << V_48 ;
V_299 = V_298 + ( V_41 -> V_47 << V_48 ) ;
F_23 (n, vcpu, kvm)
F_24 ( V_2 , V_298 , V_299 ) ;
V_301 = F_143 ( V_41 ) ;
memset ( V_41 -> V_306 , 0 , V_301 ) ;
}
V_32 = 0 ;
V_27:
F_144 ( & V_34 -> V_302 ) ;
return V_32 ;
}
static void F_145 ( struct V_34 * V_34 ,
struct V_40 * V_41 )
{
return;
}
static int F_146 ( struct V_34 * V_34 ,
struct V_40 * V_41 ,
struct V_307 * V_308 )
{
return 0 ;
}
static void F_147 ( struct V_34 * V_34 ,
struct V_307 * V_308 ,
const struct V_40 * V_309 )
{
return;
}
static void F_148 ( struct V_40 * free ,
struct V_40 * V_310 )
{
return;
}
static int F_149 ( struct V_40 * V_304 ,
unsigned long V_47 )
{
return 0 ;
}
static int F_150 ( struct V_34 * V_34 ,
struct V_311 * V_312 )
{
long int V_37 ;
struct V_1 * V_2 ;
V_312 -> V_216 = 0 ;
V_312 -> V_313 = 64 ;
V_312 -> V_314 [ 0 ] . V_315 = 12 ;
V_312 -> V_314 [ 0 ] . V_316 = 0 ;
V_312 -> V_314 [ 0 ] . V_317 [ 0 ] . V_315 = 12 ;
V_312 -> V_314 [ 0 ] . V_317 [ 0 ] . V_318 = 0 ;
V_37 = 1 ;
V_2 = F_151 ( V_34 , 0 ) ;
if ( V_2 && ( V_2 -> V_14 . V_88 & V_104 ) ) {
V_312 -> V_216 = V_319 ;
V_312 -> V_314 [ V_37 ] . V_315 = 16 ;
V_312 -> V_314 [ V_37 ] . V_316 = V_320 | V_321 ;
V_312 -> V_314 [ V_37 ] . V_317 [ 0 ] . V_315 = 16 ;
V_312 -> V_314 [ V_37 ] . V_317 [ 0 ] . V_318 = 1 ;
++ V_37 ;
}
V_312 -> V_314 [ V_37 ] . V_315 = 24 ;
V_312 -> V_314 [ V_37 ] . V_316 = V_320 ;
V_312 -> V_314 [ V_37 ] . V_317 [ 0 ] . V_315 = 24 ;
V_312 -> V_314 [ V_37 ] . V_317 [ 0 ] . V_318 = 0 ;
return 0 ;
}
static int F_150 ( struct V_34 * V_34 ,
struct V_311 * V_312 )
{
F_99 () ;
}
static int F_152 ( struct V_34 * V_34 )
{
F_153 ( & V_34 -> V_14 . V_322 ) ;
if ( F_154 ( V_323 ) ) {
F_155 ( & V_324 ) ;
if ( ++ V_325 == 1 )
F_156 () ;
F_157 ( & V_324 ) ;
}
return 0 ;
}
static void F_158 ( struct V_34 * V_34 )
{
#ifdef F_159
F_160 ( ! F_161 ( & V_34 -> V_14 . V_326 ) ) ;
#endif
if ( F_154 ( V_323 ) ) {
F_155 ( & V_324 ) ;
F_93 ( V_325 == 0 ) ;
if ( -- V_325 == 0 )
F_162 () ;
F_157 ( & V_324 ) ;
}
}
static int F_163 ( void )
{
return 0 ;
}
static long F_164 ( struct V_327 * V_328 ,
unsigned int V_329 , unsigned long V_330 )
{
return - V_331 ;
}
int F_165 ( void )
{
int V_32 ;
V_32 = F_163 () ;
if ( V_32 < 0 )
return V_32 ;
V_332 . V_333 = V_334 ;
V_335 = & V_332 ;
V_32 = F_166 () ;
return V_32 ;
}
void F_167 ( void )
{
V_335 = NULL ;
F_168 () ;
}
