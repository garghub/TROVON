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
static T_8 int F_32 ( char * V_84 )
{
F_33 ( & V_84 , & V_85 ) ;
F_34 ( L_1 , V_85 ? L_2 : L_3 ) ;
return 1 ;
}
static int F_35 ( struct V_57 * V_57 , struct V_86 * V_87 )
{
struct V_9 * V_10 ;
unsigned long V_5 ;
if ( ! V_85 )
return - V_88 ;
V_10 = V_57 -> V_67 ;
V_5 = V_10 -> V_12 -> V_89 ;
if ( V_5 & ( V_90 - 1 ) )
return - V_91 ;
V_87 -> V_92 = F_36 ( V_87 -> V_92 ) ;
return F_37 ( V_87 , V_5 , V_90 ) ;
}
static int F_35 ( struct V_57 * V_57 , struct V_86 * V_87 )
{
return - V_91 ;
}
static int F_38 ( int V_93 , struct V_57 * V_57 , int V_94 )
{
struct V_9 * V_10 ;
V_10 = V_57 -> V_67 ;
if ( F_39 ( V_93 , V_57 , V_94 , & V_10 -> V_37 ) >= 0 )
return 0 ;
else
return - V_74 ;
}
static int F_40 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
struct V_9 * V_10 ;
struct V_42 V_3 * V_43 ;
int V_7 = 0 ;
V_10 = V_57 -> V_67 ;
V_43 = V_10 -> V_32 ;
F_14 ( & V_19 ) ;
F_5 ( ( F_3 ( & V_43 -> V_45 ) & ~ V_95 ) ,
& V_43 -> V_45 ) ;
V_7 = V_10 -> V_96 ;
V_10 -> V_96 = 0 ;
V_10 -> V_31 = 0 ;
if ( V_10 -> V_14 & V_22
&& F_3 ( & V_43 -> V_45 ) & V_97 ) {
unsigned long V_6 ;
V_6 = F_3 ( & V_43 -> V_45 ) ;
V_6 ^= V_97 ;
F_5 ( V_6 , & V_43 -> V_45 ) ;
}
V_10 -> V_14 &= ~ ( V_65 | V_21 | V_22 ) ;
F_15 ( & V_19 ) ;
if ( V_7 )
F_41 ( V_7 , V_10 ) ;
V_57 -> V_67 = NULL ;
return 0 ;
}
static int F_42 ( struct V_9 * V_10 )
{
struct V_42 V_3 * V_43 ;
struct V_28 V_3 * V_28 ;
struct V_29 * V_30 ;
int V_7 ;
unsigned long V_98 , V_6 , V_24 , V_23 ;
unsigned long V_99 , V_11 ;
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
unsigned long V_100 ;
if ( V_10 -> V_14 & V_15 ) {
F_6 ( F_4 ( & V_43 -> V_45 ) & ~ V_97 ,
& V_43 -> V_45 ) ;
F_9 ( F_2 ( & V_28 -> V_34 ) ,
& V_43 -> V_33 ) ;
V_11 = 1 << ( V_10 - V_10 -> V_12 -> V_13 ) ;
F_6 ( V_11 , & V_28 -> V_17 ) ;
}
sprintf ( V_10 -> V_101 , L_4 , ( int ) ( V_10 - V_30 -> V_13 ) ) ;
V_100 = V_10 -> V_14 & V_15 ? V_102 : 0 ;
if ( F_43 ( V_7 , F_7 , V_100 ,
V_10 -> V_101 , ( void * ) V_10 ) ) {
F_44 ( V_103 L_5 , V_7 ) ;
V_7 = 0 ;
}
}
if ( V_7 == 0 ) {
F_14 ( & V_19 ) ;
V_10 -> V_14 ^= V_21 ;
F_15 ( & V_19 ) ;
return - V_74 ;
}
V_10 -> V_96 = V_7 ;
V_24 = V_10 -> V_31 ;
V_6 = F_3 ( & V_43 -> V_45 ) ;
V_98 = V_6 | V_104 | V_95 ;
if ( V_10 -> V_14 & V_22 ) {
V_98 |= V_97 ;
V_6 |= V_97 | V_105 ;
F_5 ( V_6 , & V_43 -> V_45 ) ;
F_45 ( V_99 ) ;
V_23 = F_2 ( & V_28 -> V_34 ) ;
F_9 ( V_24 + V_23 + V_30 -> V_35 , & V_43 -> V_33 ) ;
F_9 ( V_24 , & V_43 -> V_33 ) ;
} else {
F_45 ( V_99 ) ;
V_23 = F_2 ( & V_28 -> V_34 ) ;
F_9 ( V_24 + V_23 + V_30 -> V_35 , & V_43 -> V_33 ) ;
}
if ( V_10 -> V_14 & V_15 ) {
V_11 = 1 << ( V_10 - V_10 -> V_12 -> V_13 ) ;
F_6 ( V_11 , & V_28 -> V_17 ) ;
}
F_5 ( V_98 , & V_43 -> V_45 ) ;
F_46 ( V_99 ) ;
return 0 ;
}
static inline unsigned long F_47 ( struct V_29 * V_29 ,
unsigned long V_106 )
{
unsigned long long V_23 ;
V_23 = V_29 -> V_107 + ( V_106 >> 1 ) ;
F_48 ( V_23 , V_106 ) ;
return ( unsigned long ) V_23 ;
}
static int
F_49 ( struct V_9 * V_10 , unsigned int V_108 , unsigned long V_109 ,
struct V_110 * V_111 )
{
struct V_42 V_3 * V_43 ;
struct V_28 V_3 * V_28 ;
struct V_29 * V_30 ;
int V_112 ;
unsigned long V_6 ;
switch ( V_108 ) {
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
V_43 = V_10 -> V_32 ;
V_28 = V_10 -> V_16 ;
V_30 = V_10 -> V_12 ;
break;
case V_118 :
return F_42 ( V_10 ) ;
default:
return - V_61 ;
}
V_112 = 0 ;
switch ( V_108 ) {
case V_113 :
if ( ( V_10 -> V_14 & V_21 ) == 0 )
break;
V_6 = F_3 ( & V_43 -> V_45 ) ;
V_6 &= ~ V_95 ;
F_5 ( V_6 , & V_43 -> V_45 ) ;
if ( V_10 -> V_96 ) {
F_41 ( V_10 -> V_96 , V_10 ) ;
V_10 -> V_96 = 0 ;
}
V_10 -> V_14 ^= V_21 ;
break;
case V_114 :
{
memset ( V_111 , 0 , sizeof( * V_111 ) ) ;
if ( V_10 -> V_31 )
V_111 -> V_119 =
F_47 ( V_30 , V_10 -> V_31 ) ;
V_111 -> V_120 =
F_3 ( & V_43 -> V_45 ) & V_121 ;
V_111 -> V_122 = V_30 -> V_123 ;
V_111 -> V_124 = V_10 - V_30 -> V_13 ;
break;
}
case V_115 :
V_6 = F_3 ( & V_43 -> V_45 ) ;
if ( ( V_6 & V_121 ) == 0 ) {
V_112 = - V_125 ;
break;
}
V_10 -> V_14 |= V_22 ;
break;
case V_116 :
V_6 = F_3 ( & V_43 -> V_45 ) ;
if ( ( V_6 & V_121 ) == 0 ) {
V_112 = - V_125 ;
break;
}
if ( V_10 -> V_14 & V_22 &&
F_3 ( & V_43 -> V_45 ) & V_97 ) {
V_6 = F_3 ( & V_43 -> V_45 ) ;
V_6 ^= V_97 ;
F_5 ( V_6 , & V_43 -> V_45 ) ;
}
V_10 -> V_14 &= ~ V_22 ;
break;
case V_117 :
if ( ( V_109 > V_126 ) &&
! F_50 ( V_127 ) ) {
V_112 = - V_88 ;
break;
}
if ( ! V_109 ) {
V_112 = - V_61 ;
break;
}
V_10 -> V_31 = F_47 ( V_30 , V_109 ) ;
}
return V_112 ;
}
static long
F_51 ( struct V_57 * V_57 , unsigned int V_108 , unsigned long V_109 )
{
struct V_110 V_111 ;
int V_112 ;
F_19 ( & V_62 ) ;
V_112 = F_49 ( V_57 -> V_67 , V_108 , V_109 , & V_111 ) ;
F_20 ( & V_62 ) ;
if ( ( V_108 == V_114 ) && ! V_112 &&
( F_52 ( ( void T_4 * ) V_109 , & V_111 , sizeof( V_111 ) ) ) )
V_112 = - V_128 ;
return V_112 ;
}
static long
F_53 ( struct V_57 * V_57 , unsigned int V_108 , unsigned long V_109 )
{
struct V_110 V_111 ;
int V_112 ;
F_19 ( & V_62 ) ;
V_112 = F_49 ( V_57 -> V_67 , V_108 , V_109 , & V_111 ) ;
F_20 ( & V_62 ) ;
if ( ( V_108 == V_114 ) && ! V_112 ) {
struct V_129 T_4 * V_130 = F_54 ( V_109 ) ;
if ( F_27 ( V_111 . V_119 , & V_130 -> V_119 ) ||
F_27 ( V_111 . V_120 , & V_130 -> V_120 ) ||
F_27 ( V_111 . V_122 , & V_130 -> V_122 ) ||
F_27 ( V_111 . V_124 , & V_130 -> V_124 ) )
V_112 = - V_128 ;
}
return V_112 ;
}
static int F_55 ( struct V_131 * V_132 )
{
struct V_29 * V_30 ;
for ( V_30 = V_29 ; V_30 ; V_30 = V_30 -> V_63 )
if ( V_30 -> V_89 == V_132 -> V_133 )
return 1 ;
return 0 ;
}
static unsigned long F_56 ( struct V_29 * V_30 )
{
struct V_42 V_3 * V_43 = NULL ;
unsigned long V_24 , V_23 , V_69 , V_58 , V_99 , V_134 ;
struct V_9 * V_10 ;
int V_135 ;
struct V_28 V_3 * V_28 ;
for ( V_135 = 0 , V_10 = V_30 -> V_13 ; V_135 < V_30 -> V_64 ; V_135 ++ , V_10 ++ )
if ( ( V_10 -> V_14 & V_65 ) == 0 ) {
V_43 = V_10 -> V_32 ;
break;
}
if ( ! V_43 )
return 0 ;
V_28 = V_30 -> V_136 ;
V_24 = F_2 ( & V_43 -> V_33 ) ;
V_58 = 0 ;
V_69 = F_47 ( V_30 , V_137 ) ;
F_45 ( V_99 ) ;
V_134 = F_2 ( & V_28 -> V_34 ) ;
do {
V_23 = F_2 ( & V_28 -> V_34 ) ;
F_9 ( V_24 + V_23 + V_30 -> V_35 , & V_43 -> V_33 ) ;
} while ( V_58 ++ , ( V_23 - V_134 ) < V_69 );
F_46 ( V_99 ) ;
return ( V_23 - V_134 ) / V_58 ;
}
static unsigned long F_57 ( struct V_29 * V_30 )
{
unsigned long V_138 = ~ 0UL ;
unsigned long V_139 ;
for ( ; ; ) {
V_139 = F_56 ( V_30 ) ;
if ( V_138 <= V_139 )
break;
V_138 = V_139 ;
}
return V_138 ;
}
int F_58 ( struct V_131 * V_132 )
{
T_1 V_140 , V_141 ;
struct V_9 * V_10 ;
T_9 V_58 , V_142 ;
struct V_29 * V_30 ;
T_5 V_143 ;
struct V_28 V_3 * V_28 ;
static struct V_29 * V_144 ;
unsigned long V_145 ;
unsigned long long V_146 ;
T_9 V_147 ;
if ( F_55 ( V_132 ) ) {
F_44 ( V_148 L_6 ,
V_149 ) ;
return 0 ;
}
V_143 = sizeof( struct V_29 ) + ( ( V_132 -> V_150 - 1 ) *
sizeof( struct V_9 ) ) ;
V_30 = F_59 ( V_143 , V_151 ) ;
if ( ! V_30 )
return - V_152 ;
V_30 -> V_123 = V_153 ++ ;
V_30 -> V_136 = V_132 -> V_154 ;
V_30 -> V_89 = V_132 -> V_133 ;
V_30 -> V_64 = V_132 -> V_150 ;
for ( V_58 = 0 ; V_58 < V_132 -> V_150 ; V_58 ++ )
V_30 -> V_13 [ V_58 ] . V_44 = V_132 -> V_96 [ V_58 ] ;
V_28 = V_30 -> V_136 ;
V_140 = F_3 ( & V_28 -> V_155 ) ;
V_142 = ( ( V_140 & V_156 ) >> V_157 ) + 1 ;
if ( V_30 -> V_64 != V_142 ) {
F_44 ( V_158 L_7
L_8 ) ;
F_60 ( V_30 ) ;
return - V_159 ;
}
if ( V_144 )
V_144 -> V_63 = V_30 ;
else
V_29 = V_30 ;
V_144 = V_30 ;
V_145 = ( V_140 & V_160 ) >>
V_161 ;
V_146 = 1000000000000000uLL ;
V_146 += V_145 >> 1 ;
F_48 ( V_146 , V_145 ) ;
V_30 -> V_107 = V_146 ;
F_44 ( V_162 L_9 ,
V_30 -> V_123 , V_132 -> V_133 ,
V_30 -> V_64 > 1 ? L_10 : L_11 ) ;
for ( V_58 = 0 ; V_58 < V_30 -> V_64 ; V_58 ++ )
F_44 ( V_163 L_12 , V_58 > 0 ? L_13 : L_11 , V_132 -> V_96 [ V_58 ] ) ;
F_44 ( V_163 L_14 ) ;
V_146 = V_30 -> V_107 ;
V_147 = F_48 ( V_146 , 1000000 ) ;
F_44 ( V_162
L_15 ,
V_30 -> V_123 , V_30 -> V_64 ,
V_140 & V_164 ? 64 : 32 ,
( unsigned ) V_146 , V_147 ) ;
V_141 = F_3 ( & V_28 -> V_45 ) ;
if ( ( V_141 & V_165 ) == 0 ) {
F_9 ( 0L , & V_28 -> V_34 ) ;
V_141 |= V_165 ;
F_5 ( V_141 , & V_28 -> V_45 ) ;
}
for ( V_58 = 0 , V_10 = V_30 -> V_13 ; V_58 < V_30 -> V_64 ; V_58 ++ , V_10 ++ ) {
struct V_42 V_3 * V_43 ;
V_43 = & V_28 -> V_166 [ V_10 - V_30 -> V_13 ] ;
V_10 -> V_12 = V_30 ;
V_10 -> V_16 = V_28 ;
V_10 -> V_32 = V_43 ;
if ( V_132 -> V_167 & ( 1 << V_58 ) ) {
V_10 -> V_14 = V_65 ;
continue;
}
F_61 ( & V_10 -> V_36 ) ;
}
V_30 -> V_35 = F_57 ( V_30 ) ;
#ifdef F_62
if ( ! V_168 ) {
V_4 = ( void V_3 * ) & V_30 -> V_136 -> V_34 ;
V_169 . V_170 . V_171 = V_4 ;
F_63 ( & V_169 , V_30 -> V_107 ) ;
V_30 -> V_172 = & V_169 ;
V_168 = & V_169 ;
}
#endif
return 0 ;
}
static T_10 F_64 ( struct V_173 * V_174 , void * V_8 )
{
struct V_131 * V_132 ;
T_10 V_175 ;
struct V_176 V_5 ;
V_132 = V_8 ;
V_175 = F_65 ( V_174 , & V_5 ) ;
if ( F_66 ( V_175 ) ) {
V_132 -> V_133 = V_5 . V_177 . V_178 ;
V_132 -> V_154 = F_67 ( V_5 . V_177 . V_178 , V_5 . V_177 . V_179 ) ;
if ( F_55 ( V_132 ) ) {
F_68 ( V_132 -> V_154 ) ;
return V_180 ;
}
} else if ( V_174 -> type == V_181 ) {
struct V_182 * V_183 ;
V_183 = & V_174 -> V_8 . V_184 ;
V_132 -> V_133 = V_183 -> V_177 ;
V_132 -> V_154 = F_67 ( V_183 -> V_177 ,
V_185 ) ;
if ( F_55 ( V_132 ) ) {
F_68 ( V_132 -> V_154 ) ;
return V_180 ;
}
} else if ( V_174 -> type == V_186 ) {
struct V_187 * V_188 ;
int V_58 , V_7 ;
V_188 = & V_174 -> V_8 . V_189 ;
for ( V_58 = 0 ; V_58 < V_188 -> V_190 ; V_58 ++ ) {
if ( V_132 -> V_150 >= V_191 )
break;
V_7 = F_17 ( NULL , V_188 -> V_192 [ V_58 ] ,
V_188 -> V_193 , V_188 -> V_194 ) ;
if ( V_7 < 0 )
return V_195 ;
V_132 -> V_96 [ V_132 -> V_150 ] = V_7 ;
V_132 -> V_150 ++ ;
}
}
return V_196 ;
}
static int F_69 ( struct V_197 * V_198 )
{
T_10 V_199 ;
struct V_131 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_199 =
F_70 ( V_198 -> V_200 , V_201 ,
F_64 , & V_8 ) ;
if ( F_71 ( V_199 ) )
return - V_159 ;
if ( ! V_8 . V_154 || ! V_8 . V_150 ) {
if ( V_8 . V_154 )
F_68 ( V_8 . V_154 ) ;
F_44 ( L_16 , V_149 ) ;
return - V_159 ;
}
return F_58 ( & V_8 ) ;
}
static int T_8 F_72 ( void )
{
int V_199 ;
V_199 = F_73 ( & V_202 ) ;
if ( V_199 < 0 )
return - V_159 ;
V_203 = F_74 ( V_204 ) ;
V_199 = F_75 ( & V_205 ) ;
if ( V_199 < 0 ) {
if ( V_203 )
F_76 ( V_203 ) ;
F_77 ( & V_202 ) ;
return V_199 ;
}
return 0 ;
}
