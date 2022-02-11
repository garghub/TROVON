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
V_2 -> V_3 = - 1 ;
}
void F_11 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
V_5 -> V_19 [ 0 ] = V_2 -> V_14 . V_19 [ 0 ] ;
V_5 -> V_19 [ 1 ] = V_2 -> V_14 . V_19 [ 1 ] ;
V_5 -> V_19 [ 2 ] = V_2 -> V_14 . V_19 [ 2 ] ;
V_5 -> V_19 [ 3 ] = V_2 -> V_14 . V_19 [ 3 ] ;
V_5 -> V_19 [ 4 ] = V_2 -> V_14 . V_19 [ 4 ] ;
V_5 -> V_19 [ 5 ] = V_2 -> V_14 . V_19 [ 5 ] ;
V_5 -> V_19 [ 6 ] = V_2 -> V_14 . V_19 [ 6 ] ;
V_5 -> V_19 [ 7 ] = V_2 -> V_14 . V_19 [ 7 ] ;
V_5 -> V_19 [ 8 ] = V_2 -> V_14 . V_19 [ 8 ] ;
V_5 -> V_19 [ 9 ] = V_2 -> V_14 . V_19 [ 9 ] ;
V_5 -> V_19 [ 10 ] = V_2 -> V_14 . V_19 [ 10 ] ;
V_5 -> V_19 [ 11 ] = V_2 -> V_14 . V_19 [ 11 ] ;
V_5 -> V_19 [ 12 ] = V_2 -> V_14 . V_19 [ 12 ] ;
V_5 -> V_19 [ 13 ] = V_2 -> V_14 . V_19 [ 13 ] ;
V_5 -> V_20 = V_2 -> V_14 . V_20 ;
V_5 -> V_21 = V_2 -> V_14 . V_21 ;
V_5 -> V_22 = V_2 -> V_14 . V_22 ;
V_5 -> V_23 = V_2 -> V_14 . V_23 ;
V_5 -> V_24 = V_2 -> V_14 . V_24 ;
V_5 -> V_10 = true ;
}
void F_9 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
F_12 () ;
if ( ! V_5 -> V_10 )
goto V_25;
V_2 -> V_14 . V_19 [ 0 ] = V_5 -> V_19 [ 0 ] ;
V_2 -> V_14 . V_19 [ 1 ] = V_5 -> V_19 [ 1 ] ;
V_2 -> V_14 . V_19 [ 2 ] = V_5 -> V_19 [ 2 ] ;
V_2 -> V_14 . V_19 [ 3 ] = V_5 -> V_19 [ 3 ] ;
V_2 -> V_14 . V_19 [ 4 ] = V_5 -> V_19 [ 4 ] ;
V_2 -> V_14 . V_19 [ 5 ] = V_5 -> V_19 [ 5 ] ;
V_2 -> V_14 . V_19 [ 6 ] = V_5 -> V_19 [ 6 ] ;
V_2 -> V_14 . V_19 [ 7 ] = V_5 -> V_19 [ 7 ] ;
V_2 -> V_14 . V_19 [ 8 ] = V_5 -> V_19 [ 8 ] ;
V_2 -> V_14 . V_19 [ 9 ] = V_5 -> V_19 [ 9 ] ;
V_2 -> V_14 . V_19 [ 10 ] = V_5 -> V_19 [ 10 ] ;
V_2 -> V_14 . V_19 [ 11 ] = V_5 -> V_19 [ 11 ] ;
V_2 -> V_14 . V_19 [ 12 ] = V_5 -> V_19 [ 12 ] ;
V_2 -> V_14 . V_19 [ 13 ] = V_5 -> V_19 [ 13 ] ;
V_2 -> V_14 . V_20 = V_5 -> V_20 ;
V_2 -> V_14 . V_21 = V_5 -> V_21 ;
V_2 -> V_14 . V_22 = V_5 -> V_22 ;
V_2 -> V_14 . V_23 = V_5 -> V_23 ;
V_2 -> V_14 . V_24 = V_5 -> V_24 ;
V_2 -> V_14 . V_26 = V_5 -> V_26 ;
V_2 -> V_14 . V_27 = V_5 -> V_27 ;
V_2 -> V_14 . V_28 = V_5 -> V_28 ;
V_2 -> V_14 . V_29 = V_5 -> V_29 ;
V_5 -> V_10 = false ;
V_25:
F_13 () ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_30 = 1 ;
if ( F_15 ( V_31 , V_2 ) )
F_16 ( V_2 , 0 , 0 ) ;
return V_30 ;
}
static void F_17 ( struct V_32 * V_32 , unsigned long V_33 ,
unsigned long V_34 )
{
long V_35 ;
struct V_1 * V_2 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
V_37 = V_36 ( V_32 ) ;
F_18 (memslot, slots) {
unsigned long V_40 , V_41 ;
T_1 V_42 , V_43 ;
V_40 = F_19 ( V_33 , V_39 -> V_44 ) ;
V_41 = F_20 ( V_34 , V_39 -> V_44 +
( V_39 -> V_45 << V_46 ) ) ;
if ( V_40 >= V_41 )
continue;
V_42 = F_21 ( V_40 , V_39 ) ;
V_43 = F_21 ( V_41 + V_47 - 1 , V_39 ) ;
F_22 (i, vcpu, kvm)
F_23 ( V_2 , V_42 << V_46 ,
V_43 << V_46 ) ;
}
}
static int F_24 ( struct V_32 * V_32 , unsigned long V_48 )
{
F_25 ( V_48 ) ;
F_17 ( V_32 , V_48 , V_48 + V_47 ) ;
return 0 ;
}
static int F_26 ( struct V_32 * V_32 , unsigned long V_33 ,
unsigned long V_34 )
{
F_17 ( V_32 , V_33 , V_34 ) ;
return 0 ;
}
static int F_27 ( struct V_32 * V_32 , unsigned long V_48 )
{
return 0 ;
}
static int F_28 ( struct V_32 * V_32 , unsigned long V_48 )
{
return 0 ;
}
static void F_29 ( struct V_32 * V_32 , unsigned long V_48 , T_2 V_49 )
{
F_17 ( V_32 , V_48 , V_48 + V_47 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
T_3 V_50 = V_2 -> V_14 . V_51 -> V_52 ;
V_50 &= V_53 | V_54 | V_55 | V_56 | V_57 ;
V_50 |= V_58 | V_59 | V_60 | V_61 | V_62 | V_63 ;
V_50 |= ( V_2 -> V_14 . V_51 -> V_52 & V_2 -> V_14 . V_64 ) ;
#ifdef F_2
V_50 |= V_65 | V_66 ;
#endif
V_2 -> V_14 . V_67 = V_50 ;
}
static void F_31 ( struct V_1 * V_2 , T_4 V_52 )
{
T_3 V_68 = V_2 -> V_14 . V_51 -> V_52 ;
#ifdef F_32
F_33 ( V_69 L_1 , V_52 ) ;
#endif
V_52 &= F_4 ( V_2 ) -> V_70 ;
V_2 -> V_14 . V_51 -> V_52 = V_52 ;
F_30 ( V_2 ) ;
if ( V_52 & V_71 ) {
if ( ! V_2 -> V_14 . V_72 ) {
F_34 ( V_2 ) ;
F_35 ( V_73 , & V_2 -> V_74 ) ;
V_2 -> V_75 . V_76 ++ ;
V_52 &= ~ V_71 ;
V_2 -> V_14 . V_51 -> V_52 = V_52 ;
}
}
if ( ( V_2 -> V_14 . V_51 -> V_52 & ( V_62 | V_60 | V_61 ) ) !=
( V_68 & ( V_62 | V_60 | V_61 ) ) ) {
F_36 ( V_2 ) ;
F_37 ( V_2 , F_38 ( V_2 ) ) ;
if ( ! ( V_52 & V_62 ) && V_2 -> V_14 . V_77 ) {
struct V_78 * V_79 = & V_2 -> V_14 ;
if ( V_52 & V_61 )
F_37 ( V_2 , V_79 -> V_80 ) ;
else
F_37 ( V_2 , V_79 -> V_77 ) ;
}
}
if ( V_2 -> V_14 . V_77 &&
! ( V_68 & V_62 ) && ! ( V_68 & V_55 ) && ( V_52 & V_55 ) ) {
F_16 ( V_2 , ( V_81 ) V_2 -> V_14 . V_77 ,
~ 0xFFFUL ) ;
}
if ( V_2 -> V_14 . V_51 -> V_52 & V_16 )
F_39 ( V_2 , V_82 , V_16 ) ;
}
void F_40 ( struct V_1 * V_2 , T_5 V_83 )
{
T_5 V_84 ;
V_2 -> V_14 . V_85 &= ~ V_86 ;
V_2 -> V_14 . V_83 = V_83 ;
#ifdef F_2
if ( ( V_83 >= 0x330000 ) && ( V_83 < 0x70330000 ) ) {
F_41 ( V_2 ) ;
if ( ! F_4 ( V_2 ) -> V_87 )
F_4 ( V_2 ) -> V_88 = 0xfff00000 ;
F_4 ( V_2 ) -> V_70 = 0xffffffffffffffffULL ;
V_2 -> V_14 . V_89 = V_90 ;
} else
#endif
{
F_42 ( V_2 ) ;
if ( ! F_4 ( V_2 ) -> V_87 )
F_4 ( V_2 ) -> V_88 = 0 ;
F_4 ( V_2 ) -> V_70 = 0xffffffffULL ;
V_2 -> V_14 . V_89 = V_91 ;
}
F_43 ( V_2 ) ;
V_2 -> V_14 . V_85 &= ~ V_92 ;
if ( V_2 -> V_14 . V_93 . V_94 ( V_2 ) && ( F_44 () & V_66 ) &&
! strcmp ( V_95 -> V_96 , L_2 ) )
V_2 -> V_14 . V_85 |= V_92 ;
if ( ! strcmp ( V_95 -> V_96 , L_3 ) )
F_4 ( V_2 ) -> V_70 &= ~ ( V_53 | V_54 ) ;
switch ( F_45 ( V_83 ) ) {
case V_97 :
case V_98 :
case V_99 :
case V_100 :
V_2 -> V_14 . V_85 |= V_101 |
V_102 ;
break;
}
#ifdef F_7
V_2 -> V_14 . V_85 |= V_92 ;
#endif
asm ( "mfpvr %0" : "=r"(host_pvr));
switch ( V_84 ) {
case 0x00080200 :
case 0x00088202 :
case 0x70000100 :
case 0x00080100 :
case 0x00083203 :
case 0x00083213 :
case 0x00083204 :
case 0x00083214 :
case 0x00087200 :
V_2 -> V_14 . V_85 |= V_103 ;
F_46 ( V_104 , F_47 ( V_104 ) | ( 1 << 29 ) ) ;
}
}
static void F_48 ( struct V_1 * V_2 , struct V_105 * V_49 )
{
struct V_106 * V_107 ;
T_4 V_108 ;
T_5 * V_106 ;
int V_35 ;
V_107 = F_49 ( V_2 -> V_32 , V_49 -> V_109 >> V_46 ) ;
if ( F_50 ( V_107 ) )
return;
V_108 = V_49 -> V_109 & ~ V_110 ;
V_108 &= ~ 0xFFFULL ;
V_108 /= 4 ;
F_51 ( V_107 ) ;
V_106 = F_52 ( V_107 ) ;
for ( V_35 = V_108 ; V_35 < V_108 + ( V_111 / 4 ) ; V_35 ++ )
if ( ( V_106 [ V_35 ] & 0xff0007ff ) == V_112 )
V_106 [ V_35 ] &= 0xfffffff7 ;
F_53 ( V_106 ) ;
F_54 ( V_107 ) ;
}
static int F_55 ( struct V_1 * V_2 , T_1 V_42 )
{
T_3 V_113 = V_2 -> V_14 . V_77 ;
if ( ! ( V_2 -> V_14 . V_51 -> V_52 & V_55 ) )
V_113 = ( V_81 ) V_113 ;
if ( F_56 ( V_113 ) &&
F_56 ( ( V_113 & V_114 ) >> V_46 == V_42 ) ) {
return 1 ;
}
return F_57 ( V_2 -> V_32 , V_42 ) ;
}
int F_58 ( struct V_115 * V_116 , struct V_1 * V_2 ,
T_3 V_117 , int V_118 )
{
bool V_119 = ( V_118 == V_120 ) ;
bool V_121 = false ;
int V_30 = V_122 ;
int V_123 ;
int V_124 = 0 ;
struct V_105 V_49 ;
bool V_125 = false ;
bool V_126 = ( V_2 -> V_14 . V_51 -> V_52 & V_61 ) ? true : false ;
bool V_127 = ( V_2 -> V_14 . V_51 -> V_52 & V_60 ) ? true : false ;
T_4 V_128 ;
V_123 = V_119 ? V_126 : V_127 ;
if ( V_119 && ( V_2 -> V_14 . V_28 & V_129 ) )
V_121 = true ;
if ( V_123 ) {
V_124 = V_2 -> V_14 . V_93 . V_130 ( V_2 , V_117 , & V_49 , V_119 , V_121 ) ;
} else {
V_49 . V_131 = true ;
V_49 . V_132 = true ;
V_49 . V_133 = true ;
V_49 . V_109 = V_117 & V_114 ;
V_49 . V_117 = V_117 ;
V_49 . V_134 = V_117 >> 12 ;
V_49 . V_135 = V_136 ;
}
switch ( V_2 -> V_14 . V_51 -> V_52 & ( V_61 | V_60 ) ) {
case 0 :
V_49 . V_134 |= ( ( T_4 ) V_137 << ( V_138 - 12 ) ) ;
break;
case V_61 :
case V_60 :
V_2 -> V_14 . V_93 . V_139 ( V_2 , V_117 >> V_138 , & V_128 ) ;
if ( ( V_2 -> V_14 . V_51 -> V_52 & ( V_61 | V_60 ) ) == V_61 )
V_49 . V_134 |= ( ( T_4 ) V_140 << ( V_138 - 12 ) ) ;
else
V_49 . V_134 |= ( ( T_4 ) V_141 << ( V_138 - 12 ) ) ;
V_49 . V_134 |= V_128 ;
if ( V_128 == - 1 )
V_124 = - V_142 ;
break;
}
if ( V_2 -> V_14 . V_93 . V_94 ( V_2 ) &&
( ! ( V_2 -> V_14 . V_85 & V_92 ) ) ) {
V_49 . V_131 = ! V_119 ;
}
if ( V_124 == - V_143 ) {
V_2 -> V_14 . V_51 -> V_144 = F_59 ( V_2 ) ;
V_2 -> V_14 . V_51 -> V_145 = V_2 -> V_14 . V_28 ;
V_2 -> V_14 . V_51 -> V_52 |=
V_2 -> V_14 . V_26 & 0x00000000f8000000ULL ;
F_60 ( V_2 , V_118 ) ;
} else if ( V_124 == - V_146 ) {
V_2 -> V_14 . V_51 -> V_144 = F_59 ( V_2 ) ;
V_2 -> V_14 . V_51 -> V_145 = V_2 -> V_14 . V_28 & ~ V_147 ;
V_2 -> V_14 . V_51 -> V_145 |= V_148 ;
V_2 -> V_14 . V_51 -> V_52 |=
V_2 -> V_14 . V_26 & 0x00000000f8000000ULL ;
F_60 ( V_2 , V_118 ) ;
} else if ( V_124 == - V_142 ) {
V_2 -> V_14 . V_51 -> V_144 = F_59 ( V_2 ) ;
F_60 ( V_2 , V_118 + 0x80 ) ;
} else if ( ! V_125 &&
F_55 ( V_2 , V_49 . V_109 >> V_46 ) ) {
if ( V_119 && ! ( V_2 -> V_14 . V_28 & V_147 ) ) {
F_61 ( V_2 , & V_49 ) ;
}
F_62 ( V_2 , & V_49 , V_121 ) ;
if ( V_119 )
V_2 -> V_75 . V_149 ++ ;
else if ( V_2 -> V_14 . V_93 . V_94 ( V_2 ) &&
( ! ( V_2 -> V_14 . V_85 & V_92 ) ) )
F_48 ( V_2 , & V_49 ) ;
} else {
V_2 -> V_75 . V_150 ++ ;
V_2 -> V_14 . V_151 = V_49 . V_109 ;
V_2 -> V_14 . V_152 = V_49 . V_117 ;
V_30 = F_63 ( V_116 , V_2 ) ;
if ( V_30 == V_153 )
V_30 = V_154 ;
}
return V_30 ;
}
static inline int F_64 ( int V_35 )
{
return V_35 * V_155 ;
}
void F_10 ( struct V_1 * V_2 , T_3 V_52 )
{
struct V_156 * V_157 = & V_11 -> V_12 ;
if ( V_52 & V_18 )
V_52 |= V_16 | V_17 ;
V_52 &= V_2 -> V_14 . V_64 ;
if ( ! V_52 )
return;
#ifdef F_65
F_33 ( V_69 L_4 , V_52 ) ;
#endif
if ( V_52 & V_16 ) {
if ( V_157 -> V_158 -> V_52 & V_16 )
F_66 ( V_11 ) ;
V_157 -> V_159 = NULL ;
}
#ifdef F_67
if ( V_52 & V_17 ) {
if ( V_11 -> V_12 . V_158 -> V_52 & V_17 )
F_68 ( V_11 ) ;
V_157 -> V_160 = NULL ;
}
#endif
V_2 -> V_14 . V_64 &= ~ ( V_52 | V_18 ) ;
F_30 ( V_2 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
T_3 V_161 = F_38 ( V_2 ) ;
T_5 V_29 = F_70 ( V_2 ) ;
int V_162 ;
V_162 = F_71 ( V_2 , & V_161 , sizeof( T_5 ) , & V_29 , false ) ;
if ( V_162 == - V_143 ) {
T_3 V_52 = V_2 -> V_14 . V_51 -> V_52 ;
V_52 = F_72 ( V_52 , 33 , 33 , 1 ) ;
V_52 = F_72 ( V_52 , 34 , 36 , 0 ) ;
V_2 -> V_14 . V_51 -> V_52 = F_72 ( V_52 , 42 , 47 , 0 ) ;
F_60 ( V_2 , V_163 ) ;
return V_164 ;
}
return V_165 ;
}
static int F_73 ( struct V_1 * V_2 , unsigned int V_166 )
{
if ( ! ( V_2 -> V_14 . V_85 & V_167 ) )
return V_165 ;
if ( F_69 ( V_2 ) == V_165 )
return V_168 ;
return V_164 ;
}
static int F_39 ( struct V_1 * V_2 , unsigned int V_166 ,
T_3 V_52 )
{
struct V_156 * V_157 = & V_11 -> V_12 ;
if ( V_2 -> V_14 . V_85 & V_167 )
return V_122 ;
if ( ! ( V_2 -> V_14 . V_51 -> V_52 & V_52 ) ) {
F_60 ( V_2 , V_166 ) ;
return V_122 ;
}
if ( V_52 == V_18 ) {
#ifdef F_74
if ( ! F_75 ( V_169 ) )
#endif
{
F_76 ( V_2 , V_170 ) ;
return V_122 ;
}
V_52 = V_16 | V_17 | V_18 ;
}
V_52 &= ~ V_2 -> V_14 . V_64 ;
if ( ! V_52 )
return V_122 ;
#ifdef F_65
F_33 ( V_69 L_5 , V_52 ) ;
#endif
if ( V_52 & V_16 ) {
F_77 () ;
F_78 ( & V_2 -> V_14 . V_171 ) ;
V_157 -> V_159 = & V_2 -> V_14 . V_171 ;
}
if ( V_52 & V_17 ) {
#ifdef F_67
F_79 () ;
F_80 ( & V_2 -> V_14 . V_172 ) ;
V_157 -> V_160 = & V_2 -> V_14 . V_172 ;
#endif
}
V_157 -> V_158 -> V_52 |= V_52 ;
V_2 -> V_14 . V_64 |= V_52 ;
F_30 ( V_2 ) ;
return V_122 ;
}
static void F_81 ( struct V_1 * V_2 )
{
unsigned long V_173 ;
V_173 = V_2 -> V_14 . V_64 & ~ V_11 -> V_12 . V_158 -> V_52 ;
if ( ! V_173 )
return;
if ( V_173 & V_16 ) {
F_77 () ;
F_78 ( & V_2 -> V_14 . V_171 ) ;
}
#ifdef F_67
if ( V_173 & V_17 ) {
F_79 () ;
F_80 ( & V_2 -> V_14 . V_172 ) ;
}
#endif
V_11 -> V_12 . V_158 -> V_52 |= V_173 ;
}
int F_82 ( struct V_115 * V_116 , struct V_1 * V_2 ,
unsigned int V_166 )
{
int V_30 = V_154 ;
int V_174 ;
V_2 -> V_75 . V_175 ++ ;
V_116 -> V_176 = V_177 ;
V_116 -> V_178 = 1 ;
F_83 ( V_166 , V_2 ) ;
F_84 () ;
switch ( V_166 ) {
case V_163 :
{
T_3 V_26 = V_2 -> V_14 . V_26 ;
V_2 -> V_75 . V_179 ++ ;
#ifdef F_7
{
struct V_4 * V_5 ;
T_5 V_180 ;
V_5 = F_3 ( V_2 ) ;
V_180 = V_5 -> V_180 [ F_38 ( V_2 ) >> V_138 ] ;
F_5 ( V_5 ) ;
if ( V_180 == V_181 ) {
F_37 ( V_2 , F_38 ( V_2 ) ) ;
V_30 = V_122 ;
break;
}
}
#endif
if ( V_26 & 0x40000000 ) {
int V_182 = F_85 ( & V_2 -> V_32 -> V_183 ) ;
V_30 = F_58 ( V_116 , V_2 , F_38 ( V_2 ) , V_166 ) ;
F_86 ( & V_2 -> V_32 -> V_183 , V_182 ) ;
V_2 -> V_75 . V_184 ++ ;
} else if ( V_2 -> V_14 . V_93 . V_94 ( V_2 ) &&
( ! ( V_2 -> V_14 . V_85 & V_92 ) ) ) {
F_16 ( V_2 , F_38 ( V_2 ) , ~ 0xFFFUL ) ;
V_30 = V_122 ;
} else {
V_2 -> V_14 . V_51 -> V_52 |= V_26 & 0x58000000 ;
F_60 ( V_2 , V_166 ) ;
V_30 = V_122 ;
}
break;
}
case V_120 :
{
T_3 V_144 = F_59 ( V_2 ) ;
T_5 V_28 = V_2 -> V_14 . V_28 ;
V_2 -> V_75 . V_185 ++ ;
#ifdef F_7
{
struct V_4 * V_5 ;
T_5 V_180 ;
V_5 = F_3 ( V_2 ) ;
V_180 = V_5 -> V_180 [ V_144 >> V_138 ] ;
F_5 ( V_5 ) ;
if ( V_180 == V_181 ) {
F_37 ( V_2 , V_144 ) ;
V_30 = V_122 ;
break;
}
}
#endif
if ( V_28 & ( V_147 | V_148 ) ) {
int V_182 = F_85 ( & V_2 -> V_32 -> V_183 ) ;
V_30 = F_58 ( V_116 , V_2 , V_144 , V_166 ) ;
F_86 ( & V_2 -> V_32 -> V_183 , V_182 ) ;
} else {
V_2 -> V_14 . V_51 -> V_144 = V_144 ;
V_2 -> V_14 . V_51 -> V_145 = V_28 ;
F_60 ( V_2 , V_166 ) ;
V_30 = V_122 ;
}
break;
}
case V_186 :
if ( F_37 ( V_2 , F_59 ( V_2 ) ) < 0 ) {
V_2 -> V_14 . V_51 -> V_144 = F_59 ( V_2 ) ;
F_60 ( V_2 ,
V_186 ) ;
}
V_30 = V_122 ;
break;
case V_187 :
if ( F_37 ( V_2 , F_38 ( V_2 ) ) < 0 ) {
F_60 ( V_2 ,
V_187 ) ;
}
V_30 = V_122 ;
break;
case V_188 :
case V_189 :
case V_190 :
V_2 -> V_75 . V_191 ++ ;
V_30 = V_122 ;
break;
case V_192 :
case V_193 :
case V_194 :
V_2 -> V_75 . V_195 ++ ;
V_30 = V_122 ;
break;
case V_196 :
V_30 = V_122 ;
break;
case V_197 :
case V_198 :
{
enum V_199 V_200 ;
T_3 V_201 ;
V_202:
V_201 = V_2 -> V_14 . V_26 & 0x1f0000ull ;
if ( V_2 -> V_14 . V_51 -> V_52 & V_62 ) {
#ifdef F_32
F_33 ( V_69 L_6 , F_38 ( V_2 ) , F_70 ( V_2 ) ) ;
#endif
if ( ( F_70 ( V_2 ) & 0xff0007ff ) !=
( V_112 & 0xfffffff7 ) ) {
F_76 ( V_2 , V_201 ) ;
V_30 = V_122 ;
break;
}
}
V_2 -> V_75 . V_203 ++ ;
V_200 = F_87 ( V_116 , V_2 ) ;
switch ( V_200 ) {
case V_165 :
V_30 = V_204 ;
break;
case V_164 :
V_30 = V_122 ;
break;
case V_168 :
F_33 ( V_205 L_7 ,
V_206 , F_38 ( V_2 ) , F_70 ( V_2 ) ) ;
F_76 ( V_2 , V_201 ) ;
V_30 = V_122 ;
break;
case V_207 :
V_116 -> V_176 = V_208 ;
V_30 = V_153 ;
break;
case V_209 :
V_30 = V_153 ;
break;
default:
F_88 () ;
}
break;
}
case V_210 :
if ( V_2 -> V_14 . V_211 &&
( F_89 ( V_2 ) == 0x44000022 ) &&
! ( V_2 -> V_14 . V_51 -> V_52 & V_62 ) ) {
T_3 V_212 = F_90 ( V_2 , 3 ) ;
int V_35 ;
#ifdef F_2
if ( F_91 ( V_2 , V_212 ) == V_165 ) {
V_30 = V_122 ;
break;
}
#endif
V_116 -> V_213 . V_214 = V_212 ;
for ( V_35 = 0 ; V_35 < 9 ; ++ V_35 ) {
T_3 V_19 = F_90 ( V_2 , 4 + V_35 ) ;
V_116 -> V_213 . args [ V_35 ] = V_19 ;
}
V_116 -> V_176 = V_215 ;
V_2 -> V_14 . V_216 = 1 ;
V_30 = V_154 ;
} else if ( V_2 -> V_14 . V_217 &&
( ( ( T_5 ) F_90 ( V_2 , 3 ) ) == V_218 ) &&
( ( ( T_5 ) F_90 ( V_2 , 4 ) ) == V_219 ) ) {
T_4 * V_220 = V_116 -> V_221 . V_220 ;
int V_35 ;
V_116 -> V_176 = V_222 ;
for ( V_35 = 0 ; V_35 < 32 ; V_35 ++ )
V_220 [ V_35 ] = F_90 ( V_2 , V_35 ) ;
V_2 -> V_14 . V_223 = 1 ;
V_30 = V_153 ;
} else if ( ! ( V_2 -> V_14 . V_51 -> V_52 & V_62 ) &&
( ( ( T_5 ) F_90 ( V_2 , 0 ) ) == V_224 ) ) {
F_92 ( V_2 , 3 , F_93 ( V_2 ) ) ;
V_30 = V_122 ;
} else {
V_2 -> V_75 . V_225 ++ ;
F_60 ( V_2 , V_166 ) ;
V_30 = V_122 ;
}
break;
case V_82 :
case V_226 :
case V_227 :
{
int V_228 = 0 ;
switch ( V_166 ) {
case V_82 : V_228 = V_16 ; break;
case V_226 : V_228 = V_17 ; break;
case V_227 : V_228 = V_18 ; break;
}
switch ( F_73 ( V_2 , V_166 ) ) {
case V_165 :
V_30 = F_39 ( V_2 , V_166 , V_228 ) ;
break;
case V_168 :
goto V_202;
break;
default:
break;
}
break;
}
case V_229 :
if ( F_69 ( V_2 ) == V_165 ) {
V_2 -> V_14 . V_51 -> V_145 = F_94 ( V_2 ,
F_70 ( V_2 ) ) ;
V_2 -> V_14 . V_51 -> V_144 = F_95 ( V_2 ,
F_70 ( V_2 ) ) ;
F_60 ( V_2 , V_166 ) ;
}
V_30 = V_122 ;
break;
case V_230 :
case V_231 :
F_60 ( V_2 , V_166 ) ;
V_30 = V_122 ;
break;
default:
{
T_3 V_26 = V_2 -> V_14 . V_26 ;
F_33 ( V_232 L_8 ,
V_166 , F_38 ( V_2 ) , V_26 ) ;
V_30 = V_154 ;
F_88 () ;
break;
}
}
if ( ! ( V_30 & V_154 ) ) {
V_174 = F_96 ( V_2 ) ;
if ( V_174 <= 0 )
V_30 = V_174 ;
else {
F_97 () ;
}
F_81 ( V_2 ) ;
}
F_98 ( V_30 , V_2 ) ;
return V_30 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_233 * V_234 )
{
struct V_235 * V_236 = F_4 ( V_2 ) ;
int V_35 ;
V_234 -> V_83 = V_2 -> V_14 . V_83 ;
V_234 -> V_237 . V_174 . V_238 = F_4 ( V_2 ) -> V_238 ;
if ( V_2 -> V_14 . V_85 & V_86 ) {
for ( V_35 = 0 ; V_35 < 64 ; V_35 ++ ) {
V_234 -> V_237 . V_174 . V_239 . V_6 [ V_35 ] . V_240 = V_2 -> V_14 . V_6 [ V_35 ] . V_241 | V_35 ;
V_234 -> V_237 . V_174 . V_239 . V_6 [ V_35 ] . V_242 = V_2 -> V_14 . V_6 [ V_35 ] . V_243 ;
}
} else {
for ( V_35 = 0 ; V_35 < 16 ; V_35 ++ )
V_234 -> V_237 . V_174 . V_244 . V_180 [ V_35 ] = V_2 -> V_14 . V_51 -> V_180 [ V_35 ] ;
for ( V_35 = 0 ; V_35 < 8 ; V_35 ++ ) {
V_234 -> V_237 . V_174 . V_244 . V_245 [ V_35 ] = V_236 -> V_245 [ V_35 ] . V_246 ;
V_234 -> V_237 . V_174 . V_244 . V_247 [ V_35 ] = V_236 -> V_247 [ V_35 ] . V_246 ;
}
}
return 0 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_233 * V_234 )
{
struct V_235 * V_236 = F_4 ( V_2 ) ;
int V_35 ;
F_40 ( V_2 , V_234 -> V_83 ) ;
V_236 -> V_238 = V_234 -> V_237 . V_174 . V_238 ;
if ( V_2 -> V_14 . V_85 & V_86 ) {
for ( V_35 = 0 ; V_35 < 64 ; V_35 ++ ) {
V_2 -> V_14 . V_93 . V_248 ( V_2 , V_234 -> V_237 . V_174 . V_239 . V_6 [ V_35 ] . V_242 ,
V_234 -> V_237 . V_174 . V_239 . V_6 [ V_35 ] . V_240 ) ;
}
} else {
for ( V_35 = 0 ; V_35 < 16 ; V_35 ++ ) {
V_2 -> V_14 . V_93 . V_249 ( V_2 , V_35 , V_234 -> V_237 . V_174 . V_244 . V_180 [ V_35 ] ) ;
}
for ( V_35 = 0 ; V_35 < 8 ; V_35 ++ ) {
F_101 ( V_2 , & ( V_236 -> V_245 [ V_35 ] ) , false ,
( T_5 ) V_234 -> V_237 . V_174 . V_244 . V_245 [ V_35 ] ) ;
F_101 ( V_2 , & ( V_236 -> V_245 [ V_35 ] ) , true ,
( T_5 ) ( V_234 -> V_237 . V_174 . V_244 . V_245 [ V_35 ] >> 32 ) ) ;
F_101 ( V_2 , & ( V_236 -> V_247 [ V_35 ] ) , false ,
( T_5 ) V_234 -> V_237 . V_174 . V_244 . V_247 [ V_35 ] ) ;
F_101 ( V_2 , & ( V_236 -> V_247 [ V_35 ] ) , true ,
( T_5 ) ( V_234 -> V_237 . V_174 . V_244 . V_247 [ V_35 ] >> 32 ) ) ;
}
}
F_16 ( V_2 , 0 , 0 ) ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 , T_4 V_250 ,
union V_251 * V_252 )
{
int V_30 = 0 ;
switch ( V_250 ) {
case V_253 :
* V_252 = F_103 ( V_250 , F_4 ( V_2 ) -> V_88 ) ;
break;
default:
V_30 = - V_142 ;
break;
}
return V_30 ;
}
static int F_104 ( struct V_1 * V_2 , T_4 V_250 ,
union V_251 * V_252 )
{
int V_30 = 0 ;
switch ( V_250 ) {
case V_253 :
F_4 ( V_2 ) -> V_88 = F_105 ( V_250 , * V_252 ) ;
F_4 ( V_2 ) -> V_87 = true ;
break;
default:
V_30 = - V_142 ;
break;
}
return V_30 ;
}
static struct V_1 * F_106 ( struct V_32 * V_32 ,
unsigned int V_250 )
{
struct V_235 * V_254 ;
struct V_1 * V_2 ;
int V_255 = - V_256 ;
unsigned long V_257 ;
V_2 = F_107 ( V_258 , V_259 ) ;
if ( ! V_2 )
goto V_25;
V_254 = F_108 ( sizeof( struct V_235 ) ) ;
if ( ! V_254 )
goto V_260;
V_2 -> V_14 . V_261 = V_254 ;
#ifdef F_109
V_2 -> V_14 . V_15 =
F_110 ( sizeof( * V_2 -> V_14 . V_15 ) , V_259 ) ;
if ( ! V_2 -> V_14 . V_15 )
goto V_262;
#endif
V_255 = F_111 ( V_2 , V_32 , V_250 ) ;
if ( V_255 )
goto V_263;
V_255 = - V_256 ;
V_257 = F_112 ( V_259 | V_264 ) ;
if ( ! V_257 )
goto V_265;
V_2 -> V_14 . V_51 = ( void * ) ( V_257 + V_47 - 4096 ) ;
#ifdef F_2
V_2 -> V_14 . V_83 = 0x3C0301 ;
if ( F_113 ( V_266 ) )
V_2 -> V_14 . V_83 = F_47 ( V_267 ) ;
#else
V_2 -> V_14 . V_83 = 0x84202 ;
#endif
F_40 ( V_2 , V_2 -> V_14 . V_83 ) ;
V_2 -> V_14 . V_268 = 64 ;
V_2 -> V_14 . V_67 = V_269 ;
V_255 = F_114 ( V_2 ) ;
if ( V_255 < 0 )
goto V_265;
return V_2 ;
V_265:
F_115 ( V_2 ) ;
V_263:
#ifdef F_109
F_116 ( V_2 -> V_14 . V_15 ) ;
V_262:
#endif
F_117 ( V_254 ) ;
V_260:
F_118 ( V_258 , V_2 ) ;
V_25:
return F_119 ( V_255 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_235 * V_254 = F_4 ( V_2 ) ;
F_121 ( ( unsigned long ) V_2 -> V_14 . V_51 & V_110 ) ;
F_115 ( V_2 ) ;
#ifdef F_109
F_116 ( V_2 -> V_14 . V_15 ) ;
#endif
F_117 ( V_254 ) ;
F_118 ( V_258 , V_2 ) ;
}
static int F_122 ( struct V_115 * V_115 , struct V_1 * V_2 )
{
int V_162 ;
#ifdef F_67
unsigned long V_270 ( V_271 ) ;
#endif
if ( ! V_2 -> V_14 . V_272 ) {
V_115 -> V_176 = V_273 ;
V_162 = - V_142 ;
goto V_25;
}
V_162 = F_96 ( V_2 ) ;
if ( V_162 <= 0 )
goto V_25;
if ( V_11 -> V_12 . V_158 -> V_52 & V_16 )
F_66 ( V_11 ) ;
#ifdef F_67
if ( V_11 -> V_12 . V_158 -> V_52 & V_17 )
F_68 ( V_11 ) ;
#endif
#ifdef F_74
if ( V_11 -> V_12 . V_158 -> V_52 & V_18 )
F_123 ( V_11 ) ;
#endif
if ( V_2 -> V_14 . V_51 -> V_52 & V_16 )
F_39 ( V_2 , V_82 , V_16 ) ;
F_97 () ;
V_162 = F_124 ( V_115 , V_2 ) ;
F_10 ( V_2 , V_16 | V_17 | V_18 ) ;
V_25:
V_2 -> V_274 = V_275 ;
return V_162 ;
}
static int F_125 ( struct V_32 * V_32 ,
struct V_276 * log )
{
struct V_38 * V_39 ;
struct V_1 * V_2 ;
T_3 V_277 , V_278 ;
int V_279 = 0 ;
int V_30 ;
unsigned long V_280 ;
F_126 ( & V_32 -> V_281 ) ;
V_30 = F_127 ( V_32 , log , & V_279 ) ;
if ( V_30 )
goto V_25;
if ( V_279 ) {
V_39 = F_128 ( V_32 -> V_282 , log -> V_283 ) ;
V_277 = V_39 -> V_284 << V_46 ;
V_278 = V_277 + ( V_39 -> V_45 << V_46 ) ;
F_22 (n, vcpu, kvm)
F_23 ( V_2 , V_277 , V_278 ) ;
V_280 = F_129 ( V_39 ) ;
memset ( V_39 -> V_285 , 0 , V_280 ) ;
}
V_30 = 0 ;
V_25:
F_130 ( & V_32 -> V_281 ) ;
return V_30 ;
}
static void F_131 ( struct V_32 * V_32 ,
struct V_38 * V_39 )
{
return;
}
static int F_132 ( struct V_32 * V_32 ,
struct V_38 * V_39 ,
struct V_286 * V_287 )
{
return 0 ;
}
static void F_133 ( struct V_32 * V_32 ,
struct V_286 * V_287 ,
const struct V_38 * V_288 )
{
return;
}
static void F_134 ( struct V_38 * free ,
struct V_38 * V_289 )
{
return;
}
static int F_135 ( struct V_38 * V_283 ,
unsigned long V_45 )
{
return 0 ;
}
static int F_136 ( struct V_32 * V_32 ,
struct V_290 * V_291 )
{
long int V_35 ;
struct V_1 * V_2 ;
V_291 -> V_201 = 0 ;
V_291 -> V_292 = 64 ;
V_291 -> V_293 [ 0 ] . V_294 = 12 ;
V_291 -> V_293 [ 0 ] . V_295 = 0 ;
V_291 -> V_293 [ 0 ] . V_296 [ 0 ] . V_294 = 12 ;
V_291 -> V_293 [ 0 ] . V_296 [ 0 ] . V_297 = 0 ;
V_35 = 1 ;
V_2 = F_137 ( V_32 , 0 ) ;
if ( V_2 && ( V_2 -> V_14 . V_85 & V_101 ) ) {
V_291 -> V_201 = V_298 ;
V_291 -> V_293 [ V_35 ] . V_294 = 16 ;
V_291 -> V_293 [ V_35 ] . V_295 = V_299 | V_300 ;
V_291 -> V_293 [ V_35 ] . V_296 [ 0 ] . V_294 = 16 ;
V_291 -> V_293 [ V_35 ] . V_296 [ 0 ] . V_297 = 1 ;
++ V_35 ;
}
V_291 -> V_293 [ V_35 ] . V_294 = 24 ;
V_291 -> V_293 [ V_35 ] . V_295 = V_299 ;
V_291 -> V_293 [ V_35 ] . V_296 [ 0 ] . V_294 = 24 ;
V_291 -> V_293 [ V_35 ] . V_296 [ 0 ] . V_297 = 0 ;
return 0 ;
}
static int F_136 ( struct V_32 * V_32 ,
struct V_290 * V_291 )
{
F_88 () ;
}
static int F_138 ( struct V_32 * V_32 )
{
F_139 ( & V_32 -> V_14 . V_301 ) ;
if ( F_140 ( V_302 ) ) {
F_141 ( & V_303 ) ;
if ( ++ V_304 == 1 )
F_142 () ;
F_143 ( & V_303 ) ;
}
return 0 ;
}
static void F_144 ( struct V_32 * V_32 )
{
#ifdef F_145
F_146 ( ! F_147 ( & V_32 -> V_14 . V_305 ) ) ;
#endif
if ( F_140 ( V_302 ) ) {
F_141 ( & V_303 ) ;
F_148 ( V_304 == 0 ) ;
if ( -- V_304 == 0 )
F_149 () ;
F_143 ( & V_303 ) ;
}
}
static int F_150 ( void )
{
return 0 ;
}
static long F_151 ( struct V_306 * V_307 ,
unsigned int V_308 , unsigned long V_309 )
{
return - V_310 ;
}
int F_152 ( void )
{
int V_30 ;
V_30 = F_150 () ;
if ( V_30 < 0 )
return V_30 ;
V_311 . V_312 = V_313 ;
V_314 = & V_311 ;
V_30 = F_153 () ;
return V_30 ;
}
void F_154 ( void )
{
V_314 = NULL ;
F_155 () ;
}
