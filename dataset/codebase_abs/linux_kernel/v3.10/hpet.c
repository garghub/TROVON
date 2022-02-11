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
V_10 = V_57 -> V_67 ;
V_5 = V_10 -> V_12 -> V_86 ;
if ( V_5 & ( V_87 - 1 ) )
return - V_88 ;
V_85 -> V_89 = F_34 ( V_85 -> V_89 ) ;
return F_35 ( V_85 , V_5 , V_87 ) ;
#else
return - V_88 ;
#endif
}
static int F_36 ( int V_90 , struct V_57 * V_57 , int V_91 )
{
struct V_9 * V_10 ;
V_10 = V_57 -> V_67 ;
if ( F_37 ( V_90 , V_57 , V_91 , & V_10 -> V_37 ) >= 0 )
return 0 ;
else
return - V_74 ;
}
static int F_38 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
struct V_9 * V_10 ;
struct V_42 V_3 * V_43 ;
int V_7 = 0 ;
V_10 = V_57 -> V_67 ;
V_43 = V_10 -> V_32 ;
F_14 ( & V_19 ) ;
F_5 ( ( F_3 ( & V_43 -> V_45 ) & ~ V_92 ) ,
& V_43 -> V_45 ) ;
V_7 = V_10 -> V_93 ;
V_10 -> V_93 = 0 ;
V_10 -> V_31 = 0 ;
if ( V_10 -> V_14 & V_22
&& F_3 ( & V_43 -> V_45 ) & V_94 ) {
unsigned long V_6 ;
V_6 = F_3 ( & V_43 -> V_45 ) ;
V_6 ^= V_94 ;
F_5 ( V_6 , & V_43 -> V_45 ) ;
}
V_10 -> V_14 &= ~ ( V_65 | V_21 | V_22 ) ;
F_15 ( & V_19 ) ;
if ( V_7 )
F_39 ( V_7 , V_10 ) ;
V_57 -> V_67 = NULL ;
return 0 ;
}
static int F_40 ( struct V_9 * V_10 )
{
struct V_42 V_3 * V_43 ;
struct V_28 V_3 * V_28 ;
struct V_29 * V_30 ;
int V_7 ;
unsigned long V_95 , V_6 , V_24 , V_23 ;
unsigned long V_96 , V_11 ;
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
unsigned long V_97 ;
if ( V_10 -> V_14 & V_15 ) {
F_6 ( F_4 ( & V_43 -> V_45 ) & ~ V_94 ,
& V_43 -> V_45 ) ;
F_9 ( F_2 ( & V_28 -> V_34 ) ,
& V_43 -> V_33 ) ;
V_11 = 1 << ( V_10 - V_10 -> V_12 -> V_13 ) ;
F_6 ( V_11 , & V_28 -> V_17 ) ;
}
sprintf ( V_10 -> V_98 , L_1 , ( int ) ( V_10 - V_30 -> V_13 ) ) ;
V_97 = V_10 -> V_14 & V_15
? V_99 : V_100 ;
if ( F_41 ( V_7 , F_7 , V_97 ,
V_10 -> V_98 , ( void * ) V_10 ) ) {
F_42 ( V_101 L_2 , V_7 ) ;
V_7 = 0 ;
}
}
if ( V_7 == 0 ) {
F_14 ( & V_19 ) ;
V_10 -> V_14 ^= V_21 ;
F_15 ( & V_19 ) ;
return - V_74 ;
}
V_10 -> V_93 = V_7 ;
V_24 = V_10 -> V_31 ;
V_6 = F_3 ( & V_43 -> V_45 ) ;
V_95 = V_6 | V_102 | V_92 ;
if ( V_10 -> V_14 & V_22 ) {
V_95 |= V_94 ;
V_6 |= V_94 | V_103 ;
F_5 ( V_6 , & V_43 -> V_45 ) ;
F_43 ( V_96 ) ;
V_23 = F_2 ( & V_28 -> V_34 ) ;
F_9 ( V_24 + V_23 + V_30 -> V_35 , & V_43 -> V_33 ) ;
F_9 ( V_24 , & V_43 -> V_33 ) ;
} else {
F_43 ( V_96 ) ;
V_23 = F_2 ( & V_28 -> V_34 ) ;
F_9 ( V_24 + V_23 + V_30 -> V_35 , & V_43 -> V_33 ) ;
}
if ( V_10 -> V_14 & V_15 ) {
V_11 = 1 << ( V_10 - V_10 -> V_12 -> V_13 ) ;
F_6 ( V_11 , & V_28 -> V_17 ) ;
}
F_5 ( V_95 , & V_43 -> V_45 ) ;
F_44 ( V_96 ) ;
return 0 ;
}
static inline unsigned long F_45 ( struct V_29 * V_29 ,
unsigned long V_104 )
{
unsigned long long V_23 ;
V_23 = V_29 -> V_105 + ( V_104 >> 1 ) ;
F_46 ( V_23 , V_104 ) ;
return ( unsigned long ) V_23 ;
}
static int
F_47 ( struct V_9 * V_10 , int V_106 , unsigned long V_107 ,
struct V_108 * V_109 )
{
struct V_42 V_3 * V_43 ;
struct V_28 V_3 * V_28 ;
struct V_29 * V_30 ;
int V_110 ;
unsigned long V_6 ;
switch ( V_106 ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_43 = V_10 -> V_32 ;
V_28 = V_10 -> V_16 ;
V_30 = V_10 -> V_12 ;
break;
case V_116 :
return F_40 ( V_10 ) ;
default:
return - V_61 ;
}
V_110 = 0 ;
switch ( V_106 ) {
case V_111 :
if ( ( V_10 -> V_14 & V_21 ) == 0 )
break;
V_6 = F_3 ( & V_43 -> V_45 ) ;
V_6 &= ~ V_92 ;
F_5 ( V_6 , & V_43 -> V_45 ) ;
if ( V_10 -> V_93 ) {
F_39 ( V_10 -> V_93 , V_10 ) ;
V_10 -> V_93 = 0 ;
}
V_10 -> V_14 ^= V_21 ;
break;
case V_112 :
{
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
if ( V_10 -> V_31 )
V_109 -> V_117 =
F_45 ( V_30 , V_10 -> V_31 ) ;
V_109 -> V_118 =
F_3 ( & V_43 -> V_45 ) & V_119 ;
V_109 -> V_120 = V_30 -> V_121 ;
V_109 -> V_122 = V_10 - V_30 -> V_13 ;
break;
}
case V_113 :
V_6 = F_3 ( & V_43 -> V_45 ) ;
if ( ( V_6 & V_119 ) == 0 ) {
V_110 = - V_123 ;
break;
}
V_10 -> V_14 |= V_22 ;
break;
case V_114 :
V_6 = F_3 ( & V_43 -> V_45 ) ;
if ( ( V_6 & V_119 ) == 0 ) {
V_110 = - V_123 ;
break;
}
if ( V_10 -> V_14 & V_22 &&
F_3 ( & V_43 -> V_45 ) & V_94 ) {
V_6 = F_3 ( & V_43 -> V_45 ) ;
V_6 ^= V_94 ;
F_5 ( V_6 , & V_43 -> V_45 ) ;
}
V_10 -> V_14 &= ~ V_22 ;
break;
case V_115 :
if ( ( V_107 > V_124 ) &&
! F_48 ( V_125 ) ) {
V_110 = - V_126 ;
break;
}
if ( ! V_107 ) {
V_110 = - V_61 ;
break;
}
V_10 -> V_31 = F_45 ( V_30 , V_107 ) ;
}
return V_110 ;
}
static long
F_49 ( struct V_57 * V_57 , unsigned int V_106 , unsigned long V_107 )
{
struct V_108 V_109 ;
int V_110 ;
F_19 ( & V_62 ) ;
V_110 = F_47 ( V_57 -> V_67 , V_106 , V_107 , & V_109 ) ;
F_20 ( & V_62 ) ;
if ( ( V_106 == V_112 ) && ! V_110 &&
( F_50 ( ( void T_4 * ) V_107 , & V_109 , sizeof( V_109 ) ) ) )
V_110 = - V_127 ;
return V_110 ;
}
static long
F_51 ( struct V_57 * V_57 , unsigned int V_106 , unsigned long V_107 )
{
struct V_108 V_109 ;
int V_110 ;
F_19 ( & V_62 ) ;
V_110 = F_47 ( V_57 -> V_67 , V_106 , V_107 , & V_109 ) ;
F_20 ( & V_62 ) ;
if ( ( V_106 == V_112 ) && ! V_110 ) {
struct V_128 T_4 * V_129 = F_52 ( V_107 ) ;
if ( F_27 ( V_109 . V_117 , & V_129 -> V_117 ) ||
F_27 ( V_109 . V_118 , & V_129 -> V_118 ) ||
F_27 ( V_109 . V_120 , & V_129 -> V_120 ) ||
F_27 ( V_109 . V_122 , & V_129 -> V_122 ) )
V_110 = - V_127 ;
}
return V_110 ;
}
static int F_53 ( struct V_130 * V_131 )
{
struct V_29 * V_30 ;
for ( V_30 = V_29 ; V_30 ; V_30 = V_30 -> V_63 )
if ( V_30 -> V_86 == V_131 -> V_132 )
return 1 ;
return 0 ;
}
static unsigned long F_54 ( struct V_29 * V_30 )
{
struct V_42 V_3 * V_43 = NULL ;
unsigned long V_24 , V_23 , V_69 , V_58 , V_96 , V_133 ;
struct V_9 * V_10 ;
int V_134 ;
struct V_28 V_3 * V_28 ;
for ( V_134 = 0 , V_10 = V_30 -> V_13 ; V_134 < V_30 -> V_64 ; V_134 ++ , V_10 ++ )
if ( ( V_10 -> V_14 & V_65 ) == 0 ) {
V_43 = V_10 -> V_32 ;
break;
}
if ( ! V_43 )
return 0 ;
V_28 = V_30 -> V_135 ;
V_24 = F_2 ( & V_43 -> V_33 ) ;
V_58 = 0 ;
V_69 = F_45 ( V_30 , V_136 ) ;
F_43 ( V_96 ) ;
V_133 = F_2 ( & V_28 -> V_34 ) ;
do {
V_23 = F_2 ( & V_28 -> V_34 ) ;
F_9 ( V_24 + V_23 + V_30 -> V_35 , & V_43 -> V_33 ) ;
} while ( V_58 ++ , ( V_23 - V_133 ) < V_69 );
F_44 ( V_96 ) ;
return ( V_23 - V_133 ) / V_58 ;
}
static unsigned long F_55 ( struct V_29 * V_30 )
{
unsigned long V_137 = ~ 0UL ;
unsigned long V_138 ;
for ( ; ; ) {
V_138 = F_54 ( V_30 ) ;
if ( V_137 <= V_138 )
break;
V_137 = V_138 ;
}
return V_137 ;
}
int F_56 ( struct V_130 * V_131 )
{
T_8 V_139 , V_140 ;
struct V_9 * V_10 ;
T_9 V_58 , V_141 ;
struct V_29 * V_30 ;
T_5 V_142 ;
struct V_28 V_3 * V_28 ;
static struct V_29 * V_143 ;
unsigned long V_144 ;
unsigned long long V_145 ;
T_9 V_146 ;
if ( F_53 ( V_131 ) ) {
F_42 ( V_147 L_3 ,
V_148 ) ;
return 0 ;
}
V_142 = sizeof( struct V_29 ) + ( ( V_131 -> V_149 - 1 ) *
sizeof( struct V_9 ) ) ;
V_30 = F_57 ( V_142 , V_150 ) ;
if ( ! V_30 )
return - V_151 ;
V_30 -> V_121 = V_152 ++ ;
V_30 -> V_135 = V_131 -> V_153 ;
V_30 -> V_86 = V_131 -> V_132 ;
V_30 -> V_64 = V_131 -> V_149 ;
for ( V_58 = 0 ; V_58 < V_131 -> V_149 ; V_58 ++ )
V_30 -> V_13 [ V_58 ] . V_44 = V_131 -> V_93 [ V_58 ] ;
V_28 = V_30 -> V_135 ;
V_139 = F_3 ( & V_28 -> V_154 ) ;
V_141 = ( ( V_139 & V_155 ) >> V_156 ) + 1 ;
if ( V_30 -> V_64 != V_141 ) {
F_42 ( V_157 L_4
L_5 ) ;
F_58 ( V_30 ) ;
return - V_158 ;
}
if ( V_143 )
V_143 -> V_63 = V_30 ;
else
V_29 = V_30 ;
V_143 = V_30 ;
V_144 = ( V_139 & V_159 ) >>
V_160 ;
V_145 = 1000000000000000uLL ;
V_145 += V_144 >> 1 ;
F_46 ( V_145 , V_144 ) ;
V_30 -> V_105 = V_145 ;
F_42 ( V_161 L_6 ,
V_30 -> V_121 , V_131 -> V_132 ,
V_30 -> V_64 > 1 ? L_7 : L_8 ) ;
for ( V_58 = 0 ; V_58 < V_30 -> V_64 ; V_58 ++ )
F_42 ( V_162 L_9 , V_58 > 0 ? L_10 : L_8 , V_131 -> V_93 [ V_58 ] ) ;
F_42 ( V_162 L_11 ) ;
V_145 = V_30 -> V_105 ;
V_146 = F_46 ( V_145 , 1000000 ) ;
F_42 ( V_161
L_12 ,
V_30 -> V_121 , V_30 -> V_64 ,
V_139 & V_163 ? 64 : 32 ,
( unsigned ) V_145 , V_146 ) ;
V_140 = F_3 ( & V_28 -> V_45 ) ;
if ( ( V_140 & V_164 ) == 0 ) {
F_9 ( 0L , & V_28 -> V_34 ) ;
V_140 |= V_164 ;
F_5 ( V_140 , & V_28 -> V_45 ) ;
}
for ( V_58 = 0 , V_10 = V_30 -> V_13 ; V_58 < V_30 -> V_64 ; V_58 ++ , V_10 ++ ) {
struct V_42 V_3 * V_43 ;
V_43 = & V_28 -> V_165 [ V_10 - V_30 -> V_13 ] ;
V_10 -> V_12 = V_30 ;
V_10 -> V_16 = V_28 ;
V_10 -> V_32 = V_43 ;
if ( V_131 -> V_166 & ( 1 << V_58 ) ) {
V_10 -> V_14 = V_65 ;
continue;
}
F_59 ( & V_10 -> V_36 ) ;
}
V_30 -> V_35 = F_55 ( V_30 ) ;
#ifdef F_60
if ( ! V_167 ) {
V_4 = ( void V_3 * ) & V_30 -> V_135 -> V_34 ;
V_168 . V_169 . V_170 = V_4 ;
F_61 ( & V_168 , V_30 -> V_105 ) ;
V_30 -> V_171 = & V_168 ;
V_167 = & V_168 ;
}
#endif
return 0 ;
}
static T_10 F_62 ( struct V_172 * V_173 , void * V_8 )
{
struct V_130 * V_131 ;
T_10 V_174 ;
struct V_175 V_5 ;
V_131 = V_8 ;
V_174 = F_63 ( V_173 , & V_5 ) ;
if ( F_64 ( V_174 ) ) {
V_131 -> V_132 = V_5 . V_176 ;
V_131 -> V_153 = F_65 ( V_5 . V_176 , V_5 . V_177 ) ;
if ( F_53 ( V_131 ) ) {
F_66 ( V_131 -> V_153 ) ;
return V_178 ;
}
} else if ( V_173 -> type == V_179 ) {
struct V_180 * V_181 ;
V_181 = & V_173 -> V_8 . V_182 ;
if ( ! V_181 )
return V_183 ;
V_131 -> V_132 = V_181 -> V_184 ;
V_131 -> V_153 = F_65 ( V_181 -> V_184 ,
V_185 ) ;
if ( F_53 ( V_131 ) ) {
F_66 ( V_131 -> V_153 ) ;
return V_178 ;
}
} else if ( V_173 -> type == V_186 ) {
struct V_187 * V_188 ;
int V_58 , V_7 ;
V_188 = & V_173 -> V_8 . V_189 ;
for ( V_58 = 0 ; V_58 < V_188 -> V_190 ; V_58 ++ ) {
if ( V_131 -> V_149 >= V_191 )
break;
V_7 = F_17 ( NULL , V_188 -> V_192 [ V_58 ] ,
V_188 -> V_193 , V_188 -> V_194 ) ;
if ( V_7 < 0 )
return V_195 ;
V_131 -> V_93 [ V_131 -> V_149 ] = V_7 ;
V_131 -> V_149 ++ ;
}
}
return V_196 ;
}
static int F_67 ( struct V_197 * V_198 )
{
T_10 V_199 ;
struct V_130 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_199 =
F_68 ( V_198 -> V_200 , V_201 ,
F_62 , & V_8 ) ;
if ( F_69 ( V_199 ) )
return - V_158 ;
if ( ! V_8 . V_153 || ! V_8 . V_149 ) {
if ( V_8 . V_153 )
F_66 ( V_8 . V_153 ) ;
F_42 ( L_13 , V_148 ) ;
return - V_158 ;
}
return F_56 ( & V_8 ) ;
}
static int F_70 ( struct V_197 * V_198 )
{
return - V_61 ;
}
static int T_11 F_71 ( void )
{
int V_199 ;
V_199 = F_72 ( & V_202 ) ;
if ( V_199 < 0 )
return - V_158 ;
V_203 = F_73 ( V_204 ) ;
V_199 = F_74 ( & V_205 ) ;
if ( V_199 < 0 ) {
if ( V_203 )
F_75 ( V_203 ) ;
F_76 ( & V_202 ) ;
return V_199 ;
}
return 0 ;
}
static void T_12 F_77 ( void )
{
F_78 ( & V_205 ) ;
if ( V_203 )
F_75 ( V_203 ) ;
F_76 ( & V_202 ) ;
return;
}
