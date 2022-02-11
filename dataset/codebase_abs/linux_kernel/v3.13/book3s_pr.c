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
T_4 * V_158 = V_2 -> V_14 . V_159 ;
#ifdef F_65
T_4 * V_160 = V_2 -> V_14 . V_161 ;
#endif
T_4 * V_162 = & V_157 -> V_163 . V_159 [ 0 ] [ 0 ] ;
int V_35 ;
if ( V_52 & V_18 )
V_52 |= V_16 | V_17 ;
V_52 &= V_2 -> V_14 . V_64 ;
if ( ! V_52 )
return;
#ifdef F_66
F_33 ( V_69 L_4 , V_52 ) ;
#endif
if ( V_52 & V_16 ) {
if ( V_11 -> V_12 . V_164 -> V_52 & V_16 )
F_67 ( V_11 ) ;
for ( V_35 = 0 ; V_35 < F_68 ( V_2 -> V_14 . V_159 ) ; V_35 ++ )
V_158 [ V_35 ] = V_162 [ F_64 ( V_35 ) ] ;
V_2 -> V_14 . V_165 = V_157 -> V_163 . V_165 ;
#ifdef F_65
if ( F_69 ( V_166 ) )
for ( V_35 = 0 ; V_35 < F_68 ( V_2 -> V_14 . V_161 ) / 2 ; V_35 ++ )
V_160 [ V_35 ] = V_162 [ F_64 ( V_35 ) + 1 ] ;
#endif
}
#ifdef F_70
if ( V_52 & V_17 ) {
if ( V_11 -> V_12 . V_164 -> V_52 & V_17 )
F_71 ( V_11 ) ;
memcpy ( V_2 -> V_14 . V_167 , V_157 -> V_168 . V_167 , sizeof( V_2 -> V_14 . V_167 ) ) ;
V_2 -> V_14 . V_169 = V_157 -> V_168 . V_169 ;
}
#endif
V_2 -> V_14 . V_64 &= ~ ( V_52 | V_18 ) ;
F_30 ( V_2 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
T_3 V_170 = F_38 ( V_2 ) ;
T_5 V_29 = F_73 ( V_2 ) ;
int V_171 ;
V_171 = F_74 ( V_2 , & V_170 , sizeof( T_5 ) , & V_29 , false ) ;
if ( V_171 == - V_143 ) {
T_3 V_52 = V_2 -> V_14 . V_51 -> V_52 ;
V_52 = F_75 ( V_52 , 33 , 33 , 1 ) ;
V_52 = F_75 ( V_52 , 34 , 36 , 0 ) ;
V_2 -> V_14 . V_51 -> V_52 = F_75 ( V_52 , 42 , 47 , 0 ) ;
F_60 ( V_2 , V_172 ) ;
return V_173 ;
}
return V_174 ;
}
static int F_76 ( struct V_1 * V_2 , unsigned int V_175 )
{
if ( ! ( V_2 -> V_14 . V_85 & V_176 ) )
return V_174 ;
if ( F_72 ( V_2 ) == V_174 )
return V_177 ;
return V_173 ;
}
static int F_39 ( struct V_1 * V_2 , unsigned int V_175 ,
T_3 V_52 )
{
struct V_156 * V_157 = & V_11 -> V_12 ;
T_4 * V_158 = V_2 -> V_14 . V_159 ;
#ifdef F_65
T_4 * V_160 = V_2 -> V_14 . V_161 ;
#endif
T_4 * V_162 = & V_157 -> V_163 . V_159 [ 0 ] [ 0 ] ;
int V_35 ;
if ( V_2 -> V_14 . V_85 & V_176 )
return V_122 ;
if ( ! ( V_2 -> V_14 . V_51 -> V_52 & V_52 ) ) {
F_60 ( V_2 , V_175 ) ;
return V_122 ;
}
if ( V_52 == V_18 ) {
#ifdef F_65
if ( ! F_69 ( V_166 ) )
#endif
{
F_77 ( V_2 , V_178 ) ;
return V_122 ;
}
V_52 = V_16 | V_17 | V_18 ;
}
V_52 &= ~ V_2 -> V_14 . V_64 ;
if ( ! V_52 )
return V_122 ;
#ifdef F_66
F_33 ( V_69 L_5 , V_52 ) ;
#endif
if ( V_52 & V_16 ) {
for ( V_35 = 0 ; V_35 < F_68 ( V_2 -> V_14 . V_159 ) ; V_35 ++ )
V_162 [ F_64 ( V_35 ) ] = V_158 [ V_35 ] ;
#ifdef F_65
for ( V_35 = 0 ; V_35 < F_68 ( V_2 -> V_14 . V_161 ) / 2 ; V_35 ++ )
V_162 [ F_64 ( V_35 ) + 1 ] = V_160 [ V_35 ] ;
#endif
V_157 -> V_163 . V_165 = V_2 -> V_14 . V_165 ;
V_157 -> V_179 = 0 ;
F_78 () ;
}
if ( V_52 & V_17 ) {
#ifdef F_70
memcpy ( V_157 -> V_168 . V_167 , V_2 -> V_14 . V_167 , sizeof( V_2 -> V_14 . V_167 ) ) ;
V_157 -> V_168 . V_169 = V_2 -> V_14 . V_169 ;
V_157 -> V_180 = - 1 ;
F_79 () ;
#endif
}
V_11 -> V_12 . V_164 -> V_52 |= V_52 ;
V_2 -> V_14 . V_64 |= V_52 ;
F_30 ( V_2 ) ;
return V_122 ;
}
static void F_80 ( struct V_1 * V_2 )
{
unsigned long V_181 ;
V_181 = V_2 -> V_14 . V_64 & ~ V_11 -> V_12 . V_164 -> V_52 ;
if ( ! V_181 )
return;
if ( V_181 & V_16 )
F_78 () ;
#ifdef F_70
if ( V_181 & V_17 )
F_79 () ;
#endif
V_11 -> V_12 . V_164 -> V_52 |= V_181 ;
}
int F_81 ( struct V_115 * V_116 , struct V_1 * V_2 ,
unsigned int V_175 )
{
int V_30 = V_154 ;
int V_182 ;
V_2 -> V_75 . V_183 ++ ;
V_116 -> V_184 = V_185 ;
V_116 -> V_186 = 1 ;
F_82 ( V_175 , V_2 ) ;
F_83 () ;
switch ( V_175 ) {
case V_172 :
{
T_3 V_26 = V_2 -> V_14 . V_26 ;
V_2 -> V_75 . V_187 ++ ;
#ifdef F_7
{
struct V_4 * V_5 ;
T_5 V_188 ;
V_5 = F_3 ( V_2 ) ;
V_188 = V_5 -> V_188 [ F_38 ( V_2 ) >> V_138 ] ;
F_5 ( V_5 ) ;
if ( V_188 == V_189 ) {
F_37 ( V_2 , F_38 ( V_2 ) ) ;
V_30 = V_122 ;
break;
}
}
#endif
if ( V_26 & 0x40000000 ) {
int V_190 = F_84 ( & V_2 -> V_32 -> V_191 ) ;
V_30 = F_58 ( V_116 , V_2 , F_38 ( V_2 ) , V_175 ) ;
F_85 ( & V_2 -> V_32 -> V_191 , V_190 ) ;
V_2 -> V_75 . V_192 ++ ;
} else if ( V_2 -> V_14 . V_93 . V_94 ( V_2 ) &&
( ! ( V_2 -> V_14 . V_85 & V_92 ) ) ) {
F_16 ( V_2 , F_38 ( V_2 ) , ~ 0xFFFUL ) ;
V_30 = V_122 ;
} else {
V_2 -> V_14 . V_51 -> V_52 |= V_26 & 0x58000000 ;
F_60 ( V_2 , V_175 ) ;
V_30 = V_122 ;
}
break;
}
case V_120 :
{
T_3 V_144 = F_59 ( V_2 ) ;
T_5 V_28 = V_2 -> V_14 . V_28 ;
V_2 -> V_75 . V_193 ++ ;
#ifdef F_7
{
struct V_4 * V_5 ;
T_5 V_188 ;
V_5 = F_3 ( V_2 ) ;
V_188 = V_5 -> V_188 [ V_144 >> V_138 ] ;
F_5 ( V_5 ) ;
if ( V_188 == V_189 ) {
F_37 ( V_2 , V_144 ) ;
V_30 = V_122 ;
break;
}
}
#endif
if ( V_28 & ( V_147 | V_148 ) ) {
int V_190 = F_84 ( & V_2 -> V_32 -> V_191 ) ;
V_30 = F_58 ( V_116 , V_2 , V_144 , V_175 ) ;
F_85 ( & V_2 -> V_32 -> V_191 , V_190 ) ;
} else {
V_2 -> V_14 . V_51 -> V_144 = V_144 ;
V_2 -> V_14 . V_51 -> V_145 = V_28 ;
F_60 ( V_2 , V_175 ) ;
V_30 = V_122 ;
}
break;
}
case V_194 :
if ( F_37 ( V_2 , F_59 ( V_2 ) ) < 0 ) {
V_2 -> V_14 . V_51 -> V_144 = F_59 ( V_2 ) ;
F_60 ( V_2 ,
V_194 ) ;
}
V_30 = V_122 ;
break;
case V_195 :
if ( F_37 ( V_2 , F_38 ( V_2 ) ) < 0 ) {
F_60 ( V_2 ,
V_195 ) ;
}
V_30 = V_122 ;
break;
case V_196 :
case V_197 :
V_2 -> V_75 . V_198 ++ ;
V_30 = V_122 ;
break;
case V_199 :
case V_200 :
case V_201 :
V_2 -> V_75 . V_202 ++ ;
V_30 = V_122 ;
break;
case V_203 :
V_30 = V_122 ;
break;
case V_204 :
case V_205 :
{
enum V_206 V_207 ;
T_3 V_208 ;
V_209:
V_208 = V_2 -> V_14 . V_26 & 0x1f0000ull ;
if ( V_2 -> V_14 . V_51 -> V_52 & V_62 ) {
#ifdef F_32
F_33 ( V_69 L_6 , F_38 ( V_2 ) , F_73 ( V_2 ) ) ;
#endif
if ( ( F_73 ( V_2 ) & 0xff0007ff ) !=
( V_112 & 0xfffffff7 ) ) {
F_77 ( V_2 , V_208 ) ;
V_30 = V_122 ;
break;
}
}
V_2 -> V_75 . V_210 ++ ;
V_207 = F_86 ( V_116 , V_2 ) ;
switch ( V_207 ) {
case V_174 :
V_30 = V_211 ;
break;
case V_173 :
V_30 = V_122 ;
break;
case V_177 :
F_33 ( V_212 L_7 ,
V_213 , F_38 ( V_2 ) , F_73 ( V_2 ) ) ;
F_77 ( V_2 , V_208 ) ;
V_30 = V_122 ;
break;
case V_214 :
V_116 -> V_184 = V_215 ;
V_30 = V_153 ;
break;
case V_216 :
V_30 = V_153 ;
break;
default:
F_87 () ;
}
break;
}
case V_217 :
if ( V_2 -> V_14 . V_218 &&
( F_88 ( V_2 ) == 0x44000022 ) &&
! ( V_2 -> V_14 . V_51 -> V_52 & V_62 ) ) {
T_3 V_219 = F_89 ( V_2 , 3 ) ;
int V_35 ;
#ifdef F_2
if ( F_90 ( V_2 , V_219 ) == V_174 ) {
V_30 = V_122 ;
break;
}
#endif
V_116 -> V_220 . V_221 = V_219 ;
for ( V_35 = 0 ; V_35 < 9 ; ++ V_35 ) {
T_3 V_19 = F_89 ( V_2 , 4 + V_35 ) ;
V_116 -> V_220 . args [ V_35 ] = V_19 ;
}
V_116 -> V_184 = V_222 ;
V_2 -> V_14 . V_223 = 1 ;
V_30 = V_154 ;
} else if ( V_2 -> V_14 . V_224 &&
( ( ( T_5 ) F_89 ( V_2 , 3 ) ) == V_225 ) &&
( ( ( T_5 ) F_89 ( V_2 , 4 ) ) == V_226 ) ) {
T_4 * V_227 = V_116 -> V_228 . V_227 ;
int V_35 ;
V_116 -> V_184 = V_229 ;
for ( V_35 = 0 ; V_35 < 32 ; V_35 ++ )
V_227 [ V_35 ] = F_89 ( V_2 , V_35 ) ;
V_2 -> V_14 . V_230 = 1 ;
V_30 = V_153 ;
} else if ( ! ( V_2 -> V_14 . V_51 -> V_52 & V_62 ) &&
( ( ( T_5 ) F_89 ( V_2 , 0 ) ) == V_231 ) ) {
F_91 ( V_2 , 3 , F_92 ( V_2 ) ) ;
V_30 = V_122 ;
} else {
V_2 -> V_75 . V_232 ++ ;
F_60 ( V_2 , V_175 ) ;
V_30 = V_122 ;
}
break;
case V_82 :
case V_233 :
case V_234 :
{
int V_235 = 0 ;
switch ( V_175 ) {
case V_82 : V_235 = V_16 ; break;
case V_233 : V_235 = V_17 ; break;
case V_234 : V_235 = V_18 ; break;
}
switch ( F_76 ( V_2 , V_175 ) ) {
case V_174 :
V_30 = F_39 ( V_2 , V_175 , V_235 ) ;
break;
case V_177 :
goto V_209;
break;
default:
break;
}
break;
}
case V_236 :
if ( F_72 ( V_2 ) == V_174 ) {
V_2 -> V_14 . V_51 -> V_145 = F_93 ( V_2 ,
F_73 ( V_2 ) ) ;
V_2 -> V_14 . V_51 -> V_144 = F_94 ( V_2 ,
F_73 ( V_2 ) ) ;
F_60 ( V_2 , V_175 ) ;
}
V_30 = V_122 ;
break;
case V_237 :
case V_238 :
F_60 ( V_2 , V_175 ) ;
V_30 = V_122 ;
break;
default:
{
T_3 V_26 = V_2 -> V_14 . V_26 ;
F_33 ( V_239 L_8 ,
V_175 , F_38 ( V_2 ) , V_26 ) ;
V_30 = V_154 ;
F_87 () ;
break;
}
}
if ( ! ( V_30 & V_154 ) ) {
F_95 () ;
V_182 = F_96 ( V_2 ) ;
if ( V_182 <= 0 ) {
F_97 () ;
V_30 = V_182 ;
} else {
F_98 () ;
}
F_80 ( V_2 ) ;
}
F_99 ( V_30 , V_2 ) ;
return V_30 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_240 * V_241 )
{
struct V_242 * V_243 = F_4 ( V_2 ) ;
int V_35 ;
V_241 -> V_83 = V_2 -> V_14 . V_83 ;
V_241 -> V_244 . V_182 . V_245 = F_4 ( V_2 ) -> V_245 ;
if ( V_2 -> V_14 . V_85 & V_86 ) {
for ( V_35 = 0 ; V_35 < 64 ; V_35 ++ ) {
V_241 -> V_244 . V_182 . V_246 . V_6 [ V_35 ] . V_247 = V_2 -> V_14 . V_6 [ V_35 ] . V_248 | V_35 ;
V_241 -> V_244 . V_182 . V_246 . V_6 [ V_35 ] . V_249 = V_2 -> V_14 . V_6 [ V_35 ] . V_250 ;
}
} else {
for ( V_35 = 0 ; V_35 < 16 ; V_35 ++ )
V_241 -> V_244 . V_182 . V_251 . V_188 [ V_35 ] = V_2 -> V_14 . V_51 -> V_188 [ V_35 ] ;
for ( V_35 = 0 ; V_35 < 8 ; V_35 ++ ) {
V_241 -> V_244 . V_182 . V_251 . V_252 [ V_35 ] = V_243 -> V_252 [ V_35 ] . V_253 ;
V_241 -> V_244 . V_182 . V_251 . V_254 [ V_35 ] = V_243 -> V_254 [ V_35 ] . V_253 ;
}
}
return 0 ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_240 * V_241 )
{
struct V_242 * V_243 = F_4 ( V_2 ) ;
int V_35 ;
F_40 ( V_2 , V_241 -> V_83 ) ;
V_243 -> V_245 = V_241 -> V_244 . V_182 . V_245 ;
if ( V_2 -> V_14 . V_85 & V_86 ) {
for ( V_35 = 0 ; V_35 < 64 ; V_35 ++ ) {
V_2 -> V_14 . V_93 . V_255 ( V_2 , V_241 -> V_244 . V_182 . V_246 . V_6 [ V_35 ] . V_249 ,
V_241 -> V_244 . V_182 . V_246 . V_6 [ V_35 ] . V_247 ) ;
}
} else {
for ( V_35 = 0 ; V_35 < 16 ; V_35 ++ ) {
V_2 -> V_14 . V_93 . V_256 ( V_2 , V_35 , V_241 -> V_244 . V_182 . V_251 . V_188 [ V_35 ] ) ;
}
for ( V_35 = 0 ; V_35 < 8 ; V_35 ++ ) {
F_102 ( V_2 , & ( V_243 -> V_252 [ V_35 ] ) , false ,
( T_5 ) V_241 -> V_244 . V_182 . V_251 . V_252 [ V_35 ] ) ;
F_102 ( V_2 , & ( V_243 -> V_252 [ V_35 ] ) , true ,
( T_5 ) ( V_241 -> V_244 . V_182 . V_251 . V_252 [ V_35 ] >> 32 ) ) ;
F_102 ( V_2 , & ( V_243 -> V_254 [ V_35 ] ) , false ,
( T_5 ) V_241 -> V_244 . V_182 . V_251 . V_254 [ V_35 ] ) ;
F_102 ( V_2 , & ( V_243 -> V_254 [ V_35 ] ) , true ,
( T_5 ) ( V_241 -> V_244 . V_182 . V_251 . V_254 [ V_35 ] >> 32 ) ) ;
}
}
F_16 ( V_2 , 0 , 0 ) ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 , T_4 V_257 ,
union V_258 * V_259 )
{
int V_30 = 0 ;
switch ( V_257 ) {
case V_260 :
* V_259 = F_104 ( V_257 , F_4 ( V_2 ) -> V_88 ) ;
break;
#ifdef F_65
case V_261 ... V_262 : {
long int V_35 = V_257 - V_261 ;
if ( ! F_69 ( V_166 ) ) {
V_30 = - V_263 ;
break;
}
V_259 -> V_264 [ 0 ] = V_2 -> V_14 . V_159 [ V_35 ] ;
V_259 -> V_264 [ 1 ] = V_2 -> V_14 . V_161 [ V_35 ] ;
break;
}
#endif
default:
V_30 = - V_142 ;
break;
}
return V_30 ;
}
static int F_105 ( struct V_1 * V_2 , T_4 V_257 ,
union V_258 * V_259 )
{
int V_30 = 0 ;
switch ( V_257 ) {
case V_260 :
F_4 ( V_2 ) -> V_88 = F_106 ( V_257 , * V_259 ) ;
F_4 ( V_2 ) -> V_87 = true ;
break;
#ifdef F_65
case V_261 ... V_262 : {
long int V_35 = V_257 - V_261 ;
if ( ! F_69 ( V_166 ) ) {
V_30 = - V_263 ;
break;
}
V_2 -> V_14 . V_159 [ V_35 ] = V_259 -> V_264 [ 0 ] ;
V_2 -> V_14 . V_161 [ V_35 ] = V_259 -> V_264 [ 1 ] ;
break;
}
#endif
default:
V_30 = - V_142 ;
break;
}
return V_30 ;
}
static struct V_1 * F_107 ( struct V_32 * V_32 ,
unsigned int V_257 )
{
struct V_242 * V_265 ;
struct V_1 * V_2 ;
int V_266 = - V_267 ;
unsigned long V_268 ;
V_2 = F_108 ( V_269 , V_270 ) ;
if ( ! V_2 )
goto V_25;
V_265 = F_109 ( sizeof( struct V_242 ) ) ;
if ( ! V_265 )
goto V_271;
V_2 -> V_14 . V_272 = V_265 ;
#ifdef F_110
V_2 -> V_14 . V_15 =
F_111 ( sizeof( * V_2 -> V_14 . V_15 ) , V_270 ) ;
if ( ! V_2 -> V_14 . V_15 )
goto V_273;
#endif
V_266 = F_112 ( V_2 , V_32 , V_257 ) ;
if ( V_266 )
goto V_274;
V_266 = - V_267 ;
V_268 = F_113 ( V_270 | V_275 ) ;
if ( ! V_268 )
goto V_276;
V_2 -> V_14 . V_51 = ( void * ) ( V_268 + V_47 - 4096 ) ;
#ifdef F_2
V_2 -> V_14 . V_83 = 0x3C0301 ;
if ( F_114 ( V_277 ) )
V_2 -> V_14 . V_83 = F_47 ( V_278 ) ;
#else
V_2 -> V_14 . V_83 = 0x84202 ;
#endif
F_40 ( V_2 , V_2 -> V_14 . V_83 ) ;
V_2 -> V_14 . V_279 = 64 ;
V_2 -> V_14 . V_67 = V_280 ;
V_266 = F_115 ( V_2 ) ;
if ( V_266 < 0 )
goto V_276;
return V_2 ;
V_276:
F_116 ( V_2 ) ;
V_274:
#ifdef F_110
F_117 ( V_2 -> V_14 . V_15 ) ;
V_273:
#endif
F_118 ( V_265 ) ;
V_271:
F_119 ( V_269 , V_2 ) ;
V_25:
return F_120 ( V_266 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
struct V_242 * V_265 = F_4 ( V_2 ) ;
F_122 ( ( unsigned long ) V_2 -> V_14 . V_51 & V_110 ) ;
F_116 ( V_2 ) ;
#ifdef F_110
F_117 ( V_2 -> V_14 . V_15 ) ;
#endif
F_118 ( V_265 ) ;
F_119 ( V_269 , V_2 ) ;
}
static int F_123 ( struct V_115 * V_115 , struct V_1 * V_2 )
{
int V_171 ;
struct V_281 V_282 ;
int V_179 ;
#ifdef F_70
struct V_283 V_167 ;
unsigned long V_284 ( V_180 ) ;
int V_285 ;
#endif
#ifdef F_65
int V_286 ;
#endif
T_3 V_235 ;
if ( ! V_2 -> V_14 . V_287 ) {
V_115 -> V_184 = V_288 ;
V_171 = - V_142 ;
goto V_25;
}
F_95 () ;
V_171 = F_96 ( V_2 ) ;
if ( V_171 <= 0 ) {
F_97 () ;
goto V_25;
}
if ( V_11 -> V_12 . V_164 -> V_52 & V_16 )
F_67 ( V_11 ) ;
V_282 = V_11 -> V_12 . V_163 ;
V_179 = V_11 -> V_12 . V_179 ;
#ifdef F_70
V_285 = V_11 -> V_12 . V_285 ;
if ( V_285 ) {
if ( V_11 -> V_12 . V_164 -> V_52 & V_17 )
F_71 ( V_11 ) ;
V_167 = V_11 -> V_12 . V_168 ;
V_180 = V_11 -> V_12 . V_180 ;
}
#endif
#ifdef F_65
V_286 = V_11 -> V_12 . V_286 ;
if ( V_286 && ( V_11 -> V_12 . V_164 -> V_52 & V_18 ) )
F_124 ( V_11 ) ;
#endif
V_235 = V_11 -> V_12 . V_164 -> V_52 ;
if ( V_2 -> V_14 . V_51 -> V_52 & V_16 )
F_39 ( V_2 , V_82 , V_16 ) ;
F_98 () ;
V_171 = F_125 ( V_115 , V_2 ) ;
F_10 ( V_2 , V_16 | V_17 | V_18 ) ;
V_11 -> V_12 . V_164 -> V_52 = V_235 ;
V_11 -> V_12 . V_163 = V_282 ;
V_11 -> V_12 . V_179 = V_179 ;
#ifdef F_70
if ( V_285 && V_11 -> V_12 . V_285 ) {
V_11 -> V_12 . V_168 = V_167 ;
V_11 -> V_12 . V_180 = V_180 ;
}
V_11 -> V_12 . V_285 = V_285 ;
#endif
#ifdef F_65
V_11 -> V_12 . V_286 = V_286 ;
#endif
V_25:
V_2 -> V_289 = V_290 ;
return V_171 ;
}
static int F_126 ( struct V_32 * V_32 ,
struct V_291 * log )
{
struct V_38 * V_39 ;
struct V_1 * V_2 ;
T_3 V_292 , V_293 ;
int V_294 = 0 ;
int V_30 ;
unsigned long V_295 ;
F_127 ( & V_32 -> V_296 ) ;
V_30 = F_128 ( V_32 , log , & V_294 ) ;
if ( V_30 )
goto V_25;
if ( V_294 ) {
V_39 = F_129 ( V_32 -> V_297 , log -> V_298 ) ;
V_292 = V_39 -> V_299 << V_46 ;
V_293 = V_292 + ( V_39 -> V_45 << V_46 ) ;
F_22 (n, vcpu, kvm)
F_23 ( V_2 , V_292 , V_293 ) ;
V_295 = F_130 ( V_39 ) ;
memset ( V_39 -> V_300 , 0 , V_295 ) ;
}
V_30 = 0 ;
V_25:
F_131 ( & V_32 -> V_296 ) ;
return V_30 ;
}
static void F_132 ( struct V_32 * V_32 ,
struct V_38 * V_39 )
{
return;
}
static int F_133 ( struct V_32 * V_32 ,
struct V_38 * V_39 ,
struct V_301 * V_302 )
{
return 0 ;
}
static void F_134 ( struct V_32 * V_32 ,
struct V_301 * V_302 ,
const struct V_38 * V_303 )
{
return;
}
static void F_135 ( struct V_38 * free ,
struct V_38 * V_304 )
{
return;
}
static int F_136 ( struct V_38 * V_298 ,
unsigned long V_45 )
{
return 0 ;
}
static int F_137 ( struct V_32 * V_32 ,
struct V_305 * V_306 )
{
long int V_35 ;
struct V_1 * V_2 ;
V_306 -> V_208 = 0 ;
V_306 -> V_307 = 64 ;
V_306 -> V_308 [ 0 ] . V_309 = 12 ;
V_306 -> V_308 [ 0 ] . V_310 = 0 ;
V_306 -> V_308 [ 0 ] . V_311 [ 0 ] . V_309 = 12 ;
V_306 -> V_308 [ 0 ] . V_311 [ 0 ] . V_312 = 0 ;
V_35 = 1 ;
V_2 = F_138 ( V_32 , 0 ) ;
if ( V_2 && ( V_2 -> V_14 . V_85 & V_101 ) ) {
V_306 -> V_208 = V_313 ;
V_306 -> V_308 [ V_35 ] . V_309 = 16 ;
V_306 -> V_308 [ V_35 ] . V_310 = V_314 | V_315 ;
V_306 -> V_308 [ V_35 ] . V_311 [ 0 ] . V_309 = 16 ;
V_306 -> V_308 [ V_35 ] . V_311 [ 0 ] . V_312 = 1 ;
++ V_35 ;
}
V_306 -> V_308 [ V_35 ] . V_309 = 24 ;
V_306 -> V_308 [ V_35 ] . V_310 = V_314 ;
V_306 -> V_308 [ V_35 ] . V_311 [ 0 ] . V_309 = 24 ;
V_306 -> V_308 [ V_35 ] . V_311 [ 0 ] . V_312 = 0 ;
return 0 ;
}
static int F_137 ( struct V_32 * V_32 ,
struct V_305 * V_306 )
{
F_87 () ;
}
static int F_139 ( struct V_32 * V_32 )
{
F_140 ( & V_32 -> V_14 . V_316 ) ;
if ( F_141 ( V_317 ) ) {
F_142 ( & V_318 ) ;
if ( ++ V_319 == 1 )
F_143 () ;
F_144 ( & V_318 ) ;
}
return 0 ;
}
static void F_145 ( struct V_32 * V_32 )
{
#ifdef F_146
F_147 ( ! F_148 ( & V_32 -> V_14 . V_320 ) ) ;
#endif
if ( F_141 ( V_317 ) ) {
F_142 ( & V_318 ) ;
F_149 ( V_319 == 0 ) ;
if ( -- V_319 == 0 )
F_150 () ;
F_144 ( & V_318 ) ;
}
}
static int F_151 ( void )
{
return 0 ;
}
static long F_152 ( struct V_321 * V_322 ,
unsigned int V_323 , unsigned long V_324 )
{
return - V_325 ;
}
int F_153 ( void )
{
int V_30 ;
V_30 = F_151 () ;
if ( V_30 < 0 )
return V_30 ;
V_326 . V_327 = V_328 ;
V_329 = & V_326 ;
V_30 = F_154 () ;
return V_30 ;
}
void F_155 ( void )
{
V_329 = NULL ;
F_156 () ;
}
