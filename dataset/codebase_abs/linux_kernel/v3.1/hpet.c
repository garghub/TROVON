static T_1 F_1 ( struct V_1 * V_2 )
{
return ( T_1 ) F_2 ( ( void V_3 * ) V_4 ) ;
}
static inline unsigned long long F_3 ( void V_3 * V_5 )
{
return F_4 ( V_5 ) | ( ( ( unsigned long long ) F_4 ( V_5 + 4 ) ) << 32LL ) ;
}
static inline void F_5 ( unsigned long long V_6 , void V_3 * V_5 )
{
F_6 ( V_6 & 0xffffffff , V_5 ) ;
F_6 ( V_6 >> 32 , V_5 + 4 ) ;
}
static T_2 F_7 ( int V_7 , void * V_8 )
{
struct V_9 * V_10 ;
unsigned long V_11 ;
V_10 = V_8 ;
V_11 = 1 << ( V_10 - V_10 -> V_12 -> V_13 ) ;
if ( ( V_10 -> V_14 & V_15 ) &&
! ( V_11 & F_4 ( & V_10 -> V_16 -> V_17 ) ) )
return V_18 ;
F_8 ( & V_19 ) ;
V_10 -> V_20 ++ ;
if ( ( V_10 -> V_14 & ( V_21 | V_22 ) ) == V_21 ) {
unsigned long V_23 , V_24 , V_25 , V_26 , V_27 ;
struct V_28 V_3 * V_28 = V_10 -> V_16 ;
struct V_29 * V_30 = V_10 -> V_12 ;
V_24 = V_10 -> V_31 ;
V_23 = F_2 ( & V_10 -> V_32 -> V_33 ) ;
V_25 = F_2 ( & V_28 -> V_34 ) ;
V_26 = V_25 % V_24 ;
V_27 = ( V_25 - V_26 + V_30 -> V_35 ) / V_24 ;
F_9 ( V_24 * ( V_27 + 1 ) + V_26 ,
& V_10 -> V_32 -> V_33 ) ;
}
if ( V_10 -> V_14 & V_15 )
F_6 ( V_11 , & V_10 -> V_16 -> V_17 ) ;
F_10 ( & V_19 ) ;
F_11 ( & V_10 -> V_36 ) ;
F_12 ( & V_10 -> V_37 , V_38 , V_39 ) ;
return V_40 ;
}
static void F_13 ( struct V_9 * V_10 )
{
unsigned long V_6 ;
int V_7 , V_41 ;
struct V_42 V_3 * V_43 ;
F_14 ( & V_19 ) ;
if ( V_10 -> V_44 ) {
F_15 ( & V_19 ) ;
return;
}
V_43 = V_10 -> V_32 ;
V_6 = F_4 ( & V_43 -> V_45 ) ;
if ( ! ( V_6 & V_46 ) ) {
V_6 |= V_46 ;
F_6 ( V_6 , & V_43 -> V_45 ) ;
}
F_15 ( & V_19 ) ;
V_6 = ( F_3 ( & V_43 -> V_45 ) & V_47 ) >>
V_48 ;
if ( V_49 == V_50 )
V_6 &= ~ 0xf3df ;
else
V_6 &= ~ 0xffff ;
F_16 (irq, &v, HPET_MAX_IRQ) {
if ( V_7 >= V_51 ) {
V_7 = V_52 ;
break;
}
V_41 = F_17 ( NULL , V_7 , V_53 ,
V_54 ) ;
if ( V_41 > 0 )
break;
}
if ( V_7 < V_52 ) {
F_14 ( & V_19 ) ;
V_6 = F_4 ( & V_43 -> V_45 ) ;
V_6 |= V_7 << V_55 ;
F_6 ( V_6 , & V_43 -> V_45 ) ;
V_10 -> V_44 = V_41 ;
F_15 ( & V_19 ) ;
}
return;
}
static int F_18 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
struct V_9 * V_10 ;
struct V_29 * V_30 ;
int V_58 ;
if ( V_57 -> V_59 & V_60 )
return - V_61 ;
F_19 ( & V_62 ) ;
F_14 ( & V_19 ) ;
for ( V_10 = NULL , V_30 = V_29 ; V_30 && ! V_10 ; V_30 = V_30 -> V_63 )
for ( V_58 = 0 ; V_58 < V_30 -> V_64 ; V_58 ++ )
if ( V_30 -> V_13 [ V_58 ] . V_14 & V_65 )
continue;
else {
V_10 = & V_30 -> V_13 [ V_58 ] ;
break;
}
if ( ! V_10 ) {
F_15 ( & V_19 ) ;
F_20 ( & V_62 ) ;
return - V_66 ;
}
V_57 -> V_67 = V_10 ;
V_10 -> V_20 = 0 ;
V_10 -> V_14 |= V_65 ;
F_15 ( & V_19 ) ;
F_20 ( & V_62 ) ;
F_13 ( V_10 ) ;
return 0 ;
}
static T_3
F_21 ( struct V_57 * V_57 , char T_4 * V_68 , T_5 V_69 , T_6 * V_70 )
{
F_22 ( V_71 , V_72 ) ;
unsigned long V_8 ;
T_3 V_73 ;
struct V_9 * V_10 ;
V_10 = V_57 -> V_67 ;
if ( ! V_10 -> V_31 )
return - V_74 ;
if ( V_69 < sizeof( unsigned long ) )
return - V_61 ;
F_23 ( & V_10 -> V_36 , & V_71 ) ;
for ( ; ; ) {
F_24 ( V_75 ) ;
F_14 ( & V_19 ) ;
V_8 = V_10 -> V_20 ;
V_10 -> V_20 = 0 ;
F_15 ( & V_19 ) ;
if ( V_8 )
break;
else if ( V_57 -> V_76 & V_77 ) {
V_73 = - V_78 ;
goto V_79;
} else if ( F_25 ( V_72 ) ) {
V_73 = - V_80 ;
goto V_79;
}
F_26 () ;
}
V_73 = F_27 ( V_8 , ( unsigned long T_4 * ) V_68 ) ;
if ( ! V_73 )
V_73 = sizeof( unsigned long ) ;
V_79:
F_28 ( V_81 ) ;
F_29 ( & V_10 -> V_36 , & V_71 ) ;
return V_73 ;
}
static unsigned int F_30 ( struct V_57 * V_57 , T_7 * V_71 )
{
unsigned long V_6 ;
struct V_9 * V_10 ;
V_10 = V_57 -> V_67 ;
if ( ! V_10 -> V_31 )
return 0 ;
F_31 ( V_57 , & V_10 -> V_36 , V_71 ) ;
F_14 ( & V_19 ) ;
V_6 = V_10 -> V_20 ;
F_15 ( & V_19 ) ;
if ( V_6 != 0 )
return V_82 | V_83 ;
return 0 ;
}
static int F_32 ( struct V_57 * V_57 , struct V_84 * V_85 )
{
#ifdef F_33
struct V_9 * V_10 ;
unsigned long V_5 ;
if ( ( ( V_85 -> V_86 - V_85 -> V_87 ) != V_88 ) || V_85 -> V_89 )
return - V_61 ;
V_10 = V_57 -> V_67 ;
V_5 = V_10 -> V_12 -> V_90 ;
if ( V_5 & ( V_88 - 1 ) )
return - V_91 ;
V_85 -> V_92 |= V_93 ;
V_85 -> V_94 = F_34 ( V_85 -> V_94 ) ;
if ( F_35 ( V_85 , V_85 -> V_87 , V_5 >> V_95 ,
V_88 , V_85 -> V_94 ) ) {
F_36 ( V_96 L_1 ,
V_97 ) ;
return - V_78 ;
}
return 0 ;
#else
return - V_91 ;
#endif
}
static int F_37 ( int V_98 , struct V_57 * V_57 , int V_99 )
{
struct V_9 * V_10 ;
V_10 = V_57 -> V_67 ;
if ( F_38 ( V_98 , V_57 , V_99 , & V_10 -> V_37 ) >= 0 )
return 0 ;
else
return - V_74 ;
}
static int F_39 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
struct V_9 * V_10 ;
struct V_42 V_3 * V_43 ;
int V_7 = 0 ;
V_10 = V_57 -> V_67 ;
V_43 = V_10 -> V_32 ;
F_14 ( & V_19 ) ;
F_5 ( ( F_3 ( & V_43 -> V_45 ) & ~ V_100 ) ,
& V_43 -> V_45 ) ;
V_7 = V_10 -> V_101 ;
V_10 -> V_101 = 0 ;
V_10 -> V_31 = 0 ;
if ( V_10 -> V_14 & V_22
&& F_3 ( & V_43 -> V_45 ) & V_102 ) {
unsigned long V_6 ;
V_6 = F_3 ( & V_43 -> V_45 ) ;
V_6 ^= V_102 ;
F_5 ( V_6 , & V_43 -> V_45 ) ;
}
V_10 -> V_14 &= ~ ( V_65 | V_21 | V_22 ) ;
F_15 ( & V_19 ) ;
if ( V_7 )
F_40 ( V_7 , V_10 ) ;
V_57 -> V_67 = NULL ;
return 0 ;
}
static int F_41 ( struct V_9 * V_10 )
{
struct V_42 V_3 * V_43 ;
struct V_28 V_3 * V_28 ;
struct V_29 * V_30 ;
int V_7 ;
unsigned long V_103 , V_6 , V_24 , V_23 ;
unsigned long V_104 , V_11 ;
V_43 = V_10 -> V_32 ;
V_28 = V_10 -> V_16 ;
V_30 = V_10 -> V_12 ;
if ( ! V_10 -> V_31 )
return - V_74 ;
F_14 ( & V_19 ) ;
if ( V_10 -> V_14 & V_21 ) {
F_15 ( & V_19 ) ;
return - V_66 ;
}
V_10 -> V_14 |= V_21 ;
if ( F_4 ( & V_43 -> V_45 ) & V_46 )
V_10 -> V_14 |= V_15 ;
F_15 ( & V_19 ) ;
V_7 = V_10 -> V_44 ;
if ( V_7 ) {
unsigned long V_105 ;
if ( V_10 -> V_14 & V_15 ) {
F_6 ( F_4 ( & V_43 -> V_45 ) & ~ V_102 ,
& V_43 -> V_45 ) ;
F_9 ( F_2 ( & V_28 -> V_34 ) ,
& V_43 -> V_33 ) ;
V_11 = 1 << ( V_10 - V_10 -> V_12 -> V_13 ) ;
F_6 ( V_11 , & V_28 -> V_17 ) ;
}
sprintf ( V_10 -> V_106 , L_2 , ( int ) ( V_10 - V_30 -> V_13 ) ) ;
V_105 = V_10 -> V_14 & V_15
? V_107 : V_108 ;
if ( F_42 ( V_7 , F_7 , V_105 ,
V_10 -> V_106 , ( void * ) V_10 ) ) {
F_36 ( V_96 L_3 , V_7 ) ;
V_7 = 0 ;
}
}
if ( V_7 == 0 ) {
F_14 ( & V_19 ) ;
V_10 -> V_14 ^= V_21 ;
F_15 ( & V_19 ) ;
return - V_74 ;
}
V_10 -> V_101 = V_7 ;
V_24 = V_10 -> V_31 ;
V_6 = F_3 ( & V_43 -> V_45 ) ;
V_103 = V_6 | V_109 | V_100 ;
if ( V_10 -> V_14 & V_22 ) {
V_103 |= V_102 ;
V_6 |= V_102 | V_110 ;
F_5 ( V_6 , & V_43 -> V_45 ) ;
F_43 ( V_104 ) ;
V_23 = F_2 ( & V_28 -> V_34 ) ;
F_9 ( V_24 + V_23 + V_30 -> V_35 , & V_43 -> V_33 ) ;
F_9 ( V_24 , & V_43 -> V_33 ) ;
} else {
F_43 ( V_104 ) ;
V_23 = F_2 ( & V_28 -> V_34 ) ;
F_9 ( V_24 + V_23 + V_30 -> V_35 , & V_43 -> V_33 ) ;
}
if ( V_10 -> V_14 & V_15 ) {
V_11 = 1 << ( V_10 - V_10 -> V_12 -> V_13 ) ;
F_6 ( V_11 , & V_28 -> V_17 ) ;
}
F_5 ( V_103 , & V_43 -> V_45 ) ;
F_44 ( V_104 ) ;
return 0 ;
}
static inline unsigned long F_45 ( struct V_29 * V_29 ,
unsigned long V_111 )
{
unsigned long long V_23 ;
V_23 = V_29 -> V_112 + ( V_111 >> 1 ) ;
F_46 ( V_23 , V_111 ) ;
return ( unsigned long ) V_23 ;
}
static int
F_47 ( struct V_9 * V_10 , int V_113 , unsigned long V_114 ,
struct V_115 * V_116 )
{
struct V_42 V_3 * V_43 ;
struct V_28 V_3 * V_28 ;
struct V_29 * V_30 ;
int V_117 ;
unsigned long V_6 ;
switch ( V_113 ) {
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
V_43 = V_10 -> V_32 ;
V_28 = V_10 -> V_16 ;
V_30 = V_10 -> V_12 ;
break;
case V_123 :
return F_41 ( V_10 ) ;
default:
return - V_61 ;
}
V_117 = 0 ;
switch ( V_113 ) {
case V_118 :
if ( ( V_10 -> V_14 & V_21 ) == 0 )
break;
V_6 = F_3 ( & V_43 -> V_45 ) ;
V_6 &= ~ V_100 ;
F_5 ( V_6 , & V_43 -> V_45 ) ;
if ( V_10 -> V_101 ) {
F_40 ( V_10 -> V_101 , V_10 ) ;
V_10 -> V_101 = 0 ;
}
V_10 -> V_14 ^= V_21 ;
break;
case V_119 :
{
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
if ( V_10 -> V_31 )
V_116 -> V_124 =
F_45 ( V_30 , V_10 -> V_31 ) ;
V_116 -> V_125 =
F_3 ( & V_43 -> V_45 ) & V_126 ;
V_116 -> V_127 = V_30 -> V_128 ;
V_116 -> V_129 = V_10 - V_30 -> V_13 ;
break;
}
case V_120 :
V_6 = F_3 ( & V_43 -> V_45 ) ;
if ( ( V_6 & V_126 ) == 0 ) {
V_117 = - V_130 ;
break;
}
V_10 -> V_14 |= V_22 ;
break;
case V_121 :
V_6 = F_3 ( & V_43 -> V_45 ) ;
if ( ( V_6 & V_126 ) == 0 ) {
V_117 = - V_130 ;
break;
}
if ( V_10 -> V_14 & V_22 &&
F_3 ( & V_43 -> V_45 ) & V_102 ) {
V_6 = F_3 ( & V_43 -> V_45 ) ;
V_6 ^= V_102 ;
F_5 ( V_6 , & V_43 -> V_45 ) ;
}
V_10 -> V_14 &= ~ V_22 ;
break;
case V_122 :
if ( ( V_114 > V_131 ) &&
! F_48 ( V_132 ) ) {
V_117 = - V_133 ;
break;
}
if ( ! V_114 ) {
V_117 = - V_61 ;
break;
}
V_10 -> V_31 = F_45 ( V_30 , V_114 ) ;
}
return V_117 ;
}
static long
F_49 ( struct V_57 * V_57 , unsigned int V_113 , unsigned long V_114 )
{
struct V_115 V_116 ;
int V_117 ;
F_19 ( & V_62 ) ;
V_117 = F_47 ( V_57 -> V_67 , V_113 , V_114 , & V_116 ) ;
F_20 ( & V_62 ) ;
if ( ( V_113 == V_119 ) && ! V_117 &&
( F_50 ( ( void T_4 * ) V_114 , & V_116 , sizeof( V_116 ) ) ) )
V_117 = - V_134 ;
return V_117 ;
}
static long
F_51 ( struct V_57 * V_57 , unsigned int V_113 , unsigned long V_114 )
{
struct V_115 V_116 ;
int V_117 ;
F_19 ( & V_62 ) ;
V_117 = F_47 ( V_57 -> V_67 , V_113 , V_114 , & V_116 ) ;
F_20 ( & V_62 ) ;
if ( ( V_113 == V_119 ) && ! V_117 ) {
struct V_135 T_4 * V_136 = F_52 ( V_114 ) ;
if ( F_27 ( V_116 . V_124 , & V_136 -> V_124 ) ||
F_27 ( V_116 . V_125 , & V_136 -> V_125 ) ||
F_27 ( V_116 . V_127 , & V_136 -> V_127 ) ||
F_27 ( V_116 . V_129 , & V_136 -> V_129 ) )
V_117 = - V_134 ;
}
return V_117 ;
}
static int F_53 ( struct V_137 * V_138 )
{
struct V_29 * V_30 ;
for ( V_30 = V_29 ; V_30 ; V_30 = V_30 -> V_63 )
if ( V_30 -> V_90 == V_138 -> V_139 )
return 1 ;
return 0 ;
}
static unsigned long F_54 ( struct V_29 * V_30 )
{
struct V_42 V_3 * V_43 = NULL ;
unsigned long V_24 , V_23 , V_69 , V_58 , V_104 , V_140 ;
struct V_9 * V_10 ;
int V_141 ;
struct V_28 V_3 * V_28 ;
for ( V_141 = 0 , V_10 = V_30 -> V_13 ; V_141 < V_30 -> V_64 ; V_141 ++ , V_10 ++ )
if ( ( V_10 -> V_14 & V_65 ) == 0 ) {
V_43 = V_10 -> V_32 ;
break;
}
if ( ! V_43 )
return 0 ;
V_28 = V_30 -> V_142 ;
V_24 = F_2 ( & V_43 -> V_33 ) ;
V_58 = 0 ;
V_69 = F_45 ( V_30 , V_143 ) ;
F_43 ( V_104 ) ;
V_140 = F_2 ( & V_28 -> V_34 ) ;
do {
V_23 = F_2 ( & V_28 -> V_34 ) ;
F_9 ( V_24 + V_23 + V_30 -> V_35 , & V_43 -> V_33 ) ;
} while ( V_58 ++ , ( V_23 - V_140 ) < V_69 );
F_44 ( V_104 ) ;
return ( V_23 - V_140 ) / V_58 ;
}
static unsigned long F_55 ( struct V_29 * V_30 )
{
unsigned long V_144 = - 1 ;
unsigned long V_145 ;
for ( ; ; ) {
V_145 = F_54 ( V_30 ) ;
if ( V_144 <= V_145 )
break;
V_144 = V_145 ;
}
return V_144 ;
}
int F_56 ( struct V_137 * V_138 )
{
T_8 V_146 , V_147 ;
struct V_9 * V_10 ;
T_9 V_58 , V_148 ;
struct V_29 * V_30 ;
T_5 V_149 ;
struct V_28 V_3 * V_28 ;
static struct V_29 * V_150 ;
unsigned long V_151 ;
unsigned long long V_152 ;
T_9 V_153 ;
if ( F_53 ( V_138 ) ) {
F_36 ( V_154 L_4 ,
V_97 ) ;
return 0 ;
}
V_149 = sizeof( struct V_29 ) + ( ( V_138 -> V_155 - 1 ) *
sizeof( struct V_9 ) ) ;
V_30 = F_57 ( V_149 , V_156 ) ;
if ( ! V_30 )
return - V_157 ;
V_30 -> V_128 = V_158 ++ ;
V_30 -> V_142 = V_138 -> V_159 ;
V_30 -> V_90 = V_138 -> V_139 ;
V_30 -> V_64 = V_138 -> V_155 ;
for ( V_58 = 0 ; V_58 < V_138 -> V_155 ; V_58 ++ )
V_30 -> V_13 [ V_58 ] . V_44 = V_138 -> V_101 [ V_58 ] ;
V_28 = V_30 -> V_142 ;
V_146 = F_3 ( & V_28 -> V_160 ) ;
V_148 = ( ( V_146 & V_161 ) >> V_162 ) + 1 ;
if ( V_30 -> V_64 != V_148 ) {
F_36 ( V_163 L_5
L_6 ) ;
F_58 ( V_30 ) ;
return - V_164 ;
}
if ( V_150 )
V_150 -> V_63 = V_30 ;
else
V_29 = V_30 ;
V_150 = V_30 ;
V_151 = ( V_146 & V_165 ) >>
V_166 ;
V_152 = 1000000000000000uLL ;
V_152 += V_151 >> 1 ;
F_46 ( V_152 , V_151 ) ;
V_30 -> V_112 = V_152 ;
F_36 ( V_167 L_7 ,
V_30 -> V_128 , V_138 -> V_139 ,
V_30 -> V_64 > 1 ? L_8 : L_9 ) ;
for ( V_58 = 0 ; V_58 < V_30 -> V_64 ; V_58 ++ )
F_36 ( L_10 , V_58 > 0 ? L_11 : L_9 , V_138 -> V_101 [ V_58 ] ) ;
F_36 ( L_12 ) ;
V_152 = V_30 -> V_112 ;
V_153 = F_46 ( V_152 , 1000000 ) ;
F_36 ( V_167
L_13 ,
V_30 -> V_128 , V_30 -> V_64 ,
V_146 & V_168 ? 64 : 32 ,
( unsigned ) V_152 , V_153 ) ;
V_147 = F_3 ( & V_28 -> V_45 ) ;
if ( ( V_147 & V_169 ) == 0 ) {
F_9 ( 0L , & V_28 -> V_34 ) ;
V_147 |= V_169 ;
F_5 ( V_147 , & V_28 -> V_45 ) ;
}
for ( V_58 = 0 , V_10 = V_30 -> V_13 ; V_58 < V_30 -> V_64 ; V_58 ++ , V_10 ++ ) {
struct V_42 V_3 * V_43 ;
V_43 = & V_28 -> V_170 [ V_10 - V_30 -> V_13 ] ;
V_10 -> V_12 = V_30 ;
V_10 -> V_16 = V_28 ;
V_10 -> V_32 = V_43 ;
if ( V_138 -> V_171 & ( 1 << V_58 ) ) {
V_10 -> V_14 = V_65 ;
continue;
}
F_59 ( & V_10 -> V_36 ) ;
}
V_30 -> V_35 = F_55 ( V_30 ) ;
#ifdef F_60
if ( ! V_172 ) {
V_4 = ( void V_3 * ) & V_30 -> V_142 -> V_34 ;
V_173 . V_174 . V_175 = V_4 ;
F_61 ( & V_173 , V_30 -> V_112 ) ;
V_30 -> V_176 = & V_173 ;
V_172 = & V_173 ;
}
#endif
return 0 ;
}
static T_10 F_62 ( struct V_177 * V_178 , void * V_8 )
{
struct V_137 * V_138 ;
T_10 V_179 ;
struct V_180 V_5 ;
V_138 = V_8 ;
V_179 = F_63 ( V_178 , & V_5 ) ;
if ( F_64 ( V_179 ) ) {
V_138 -> V_139 = V_5 . V_181 ;
V_138 -> V_159 = F_65 ( V_5 . V_181 , V_5 . V_182 ) ;
if ( F_53 ( V_138 ) ) {
F_66 ( V_138 -> V_159 ) ;
return V_183 ;
}
} else if ( V_178 -> type == V_184 ) {
struct V_185 * V_186 ;
V_186 = & V_178 -> V_8 . V_187 ;
if ( ! V_186 )
return V_188 ;
V_138 -> V_139 = V_186 -> V_189 ;
V_138 -> V_159 = F_65 ( V_186 -> V_189 ,
V_190 ) ;
if ( F_53 ( V_138 ) ) {
F_66 ( V_138 -> V_159 ) ;
return V_183 ;
}
} else if ( V_178 -> type == V_191 ) {
struct V_192 * V_193 ;
int V_58 , V_7 ;
V_193 = & V_178 -> V_8 . V_194 ;
for ( V_58 = 0 ; V_58 < V_193 -> V_195 ; V_58 ++ ) {
V_7 = F_17 ( NULL , V_193 -> V_196 [ V_58 ] ,
V_193 -> V_197 , V_193 -> V_198 ) ;
if ( V_7 < 0 )
return V_199 ;
V_138 -> V_101 [ V_138 -> V_155 ] = V_7 ;
V_138 -> V_155 ++ ;
}
}
return V_200 ;
}
static int F_67 ( struct V_201 * V_202 )
{
T_10 V_203 ;
struct V_137 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_203 =
F_68 ( V_202 -> V_204 , V_205 ,
F_62 , & V_8 ) ;
if ( F_69 ( V_203 ) )
return - V_164 ;
if ( ! V_8 . V_159 || ! V_8 . V_155 ) {
if ( V_8 . V_159 )
F_66 ( V_8 . V_159 ) ;
F_36 ( L_14 , V_97 ) ;
return - V_164 ;
}
return F_56 ( & V_8 ) ;
}
static int F_70 ( struct V_201 * V_202 , int type )
{
return - V_61 ;
}
static int T_11 F_71 ( void )
{
int V_203 ;
V_203 = F_72 ( & V_206 ) ;
if ( V_203 < 0 )
return - V_164 ;
V_207 = F_73 ( V_208 ) ;
V_203 = F_74 ( & V_209 ) ;
if ( V_203 < 0 ) {
if ( V_207 )
F_75 ( V_207 ) ;
F_76 ( & V_206 ) ;
return V_203 ;
}
return 0 ;
}
static void T_12 F_77 ( void )
{
F_78 ( & V_209 ) ;
if ( V_207 )
F_75 ( V_207 ) ;
F_76 ( & V_206 ) ;
return;
}
