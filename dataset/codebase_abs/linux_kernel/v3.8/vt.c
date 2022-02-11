int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_3 , V_2 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
return F_4 ( & V_3 , V_2 ) ;
}
static void F_5 ( struct V_4 * V_5 , unsigned int V_6 )
{
struct V_7 V_8 = { . V_5 = V_5 , . V_9 = V_6 } ;
F_6 ( & V_3 , V_10 , & V_8 ) ;
}
static void F_7 ( struct V_4 * V_5 )
{
struct V_7 V_8 = { . V_5 = V_5 } ;
F_6 ( & V_3 , V_11 , & V_8 ) ;
}
static inline unsigned short * F_8 ( struct V_4 * V_5 , int V_12 , int V_13 )
{
unsigned short * V_14 ;
if ( ! V_13 )
V_14 = ( unsigned short * ) ( V_5 -> V_15 + V_12 ) ;
else if ( ! V_5 -> V_16 -> V_17 )
V_14 = ( unsigned short * ) ( V_5 -> V_18 + V_12 ) ;
else
V_14 = V_5 -> V_16 -> V_17 ( V_5 , V_12 ) ;
return V_14 ;
}
static inline void F_9 ( int V_19 )
{
V_20 += V_19 ;
F_10 () ;
}
void F_10 ( void )
{
F_11 ( & V_21 ) ;
}
static void F_12 ( struct V_4 * V_5 , unsigned int V_22 , unsigned int V_23 , int V_24 )
{
unsigned short * V_25 , * V_26 ;
if ( V_22 + V_24 >= V_23 )
V_24 = V_23 - V_22 - 1 ;
if ( V_23 > V_5 -> V_27 || V_22 >= V_23 || V_24 < 1 )
return;
if ( F_13 ( V_5 ) && V_5 -> V_16 -> V_28 ( V_5 , V_22 , V_23 , V_29 , V_24 ) )
return;
V_25 = ( unsigned short * ) ( V_5 -> V_15 + V_5 -> V_30 * V_22 ) ;
V_26 = ( unsigned short * ) ( V_5 -> V_15 + V_5 -> V_30 * ( V_22 + V_24 ) ) ;
F_14 ( V_25 , V_26 , ( V_23 - V_22 - V_24 ) * V_5 -> V_30 ) ;
F_15 ( V_25 + ( V_23 - V_22 - V_24 ) * V_5 -> V_31 , V_5 -> V_32 ,
V_5 -> V_30 * V_24 ) ;
}
static void F_16 ( struct V_4 * V_5 , unsigned int V_22 , unsigned int V_23 , int V_24 )
{
unsigned short * V_26 ;
unsigned int V_33 ;
if ( V_22 + V_24 >= V_23 )
V_24 = V_23 - V_22 - 1 ;
if ( V_23 > V_5 -> V_27 || V_22 >= V_23 || V_24 < 1 )
return;
if ( F_13 ( V_5 ) && V_5 -> V_16 -> V_28 ( V_5 , V_22 , V_23 , V_34 , V_24 ) )
return;
V_26 = ( unsigned short * ) ( V_5 -> V_15 + V_5 -> V_30 * V_22 ) ;
V_33 = V_5 -> V_31 * V_24 ;
F_14 ( V_26 + V_33 , V_26 , ( V_23 - V_22 - V_24 ) * V_5 -> V_30 ) ;
F_15 ( V_26 , V_5 -> V_32 , 2 * V_33 ) ;
}
static void F_17 ( struct V_4 * V_5 , unsigned long V_35 , int V_36 )
{
#ifndef F_18
unsigned int V_37 , V_38 , V_12 ;
T_1 * V_14 ;
V_14 = ( T_1 * ) V_35 ;
if ( ! V_5 -> V_16 -> V_39 ) {
V_12 = ( V_35 - V_5 -> V_15 ) / 2 ;
V_37 = V_12 % V_5 -> V_31 ;
V_38 = V_12 / V_5 -> V_31 ;
} else {
int V_40 , V_41 ;
V_35 = V_5 -> V_16 -> V_39 ( V_5 , V_35 , & V_40 , & V_41 ) ;
V_37 = V_40 ; V_38 = V_41 ;
}
for(; ; ) {
T_1 V_42 = F_19 ( V_14 ) & 0xff00 ;
int V_43 = V_37 ;
T_1 * V_44 = V_14 ;
while ( V_37 < V_5 -> V_31 && V_36 ) {
if ( V_42 != ( F_19 ( V_14 ) & 0xff00 ) ) {
if ( V_14 > V_44 )
V_5 -> V_16 -> V_45 ( V_5 , V_44 , V_14 - V_44 , V_38 , V_43 ) ;
V_43 = V_37 ;
V_44 = V_14 ;
V_42 = F_19 ( V_14 ) & 0xff00 ;
}
V_14 ++ ;
V_37 ++ ;
V_36 -- ;
}
if ( V_14 > V_44 )
V_5 -> V_16 -> V_45 ( V_5 , V_44 , V_14 - V_44 , V_38 , V_43 ) ;
if ( ! V_36 )
break;
V_37 = 0 ;
V_38 ++ ;
if ( V_5 -> V_16 -> V_39 ) {
V_14 = ( T_1 * ) V_35 ;
V_35 = V_5 -> V_16 -> V_39 ( V_5 , V_35 , NULL , NULL ) ;
}
}
#endif
}
void F_20 ( struct V_4 * V_5 , unsigned long V_35 , int V_36 )
{
F_21 () ;
if ( F_22 ( V_5 ) ) {
F_23 ( V_5 ) ;
F_17 ( V_5 , V_35 , V_36 ) ;
F_24 ( V_5 ) ;
}
}
static T_2 F_25 ( struct V_4 * V_5 , T_2 V_46 , T_2 V_47 , T_2 V_48 ,
T_2 V_49 , T_2 V_50 , T_2 V_51 )
{
if ( V_5 -> V_16 -> V_52 )
return V_5 -> V_16 -> V_52 ( V_5 , V_46 , V_47 ,
V_48 , V_49 , V_50 , V_51 ) ;
#ifndef F_18
{
T_2 V_53 = V_46 ;
if ( ! V_5 -> V_54 )
return V_47 |
( V_51 ? 2 : 0 ) |
( V_49 ? 4 : 0 ) |
( V_50 ? 8 : 0 ) |
( V_48 ? 0x80 : 0 ) ;
if ( V_51 )
V_53 = ( V_53 & 0xF0 ) | V_5 -> V_55 ;
else if ( V_49 )
V_53 = ( V_53 & 0xf0 ) | V_5 -> V_56 ;
else if ( V_47 == 0 )
V_53 = ( V_53 & 0xf0 ) | V_5 -> V_56 ;
if ( V_50 )
V_53 = ( ( V_53 ) & 0x88 ) | ( ( ( ( V_53 ) >> 4 ) | ( ( V_53 ) << 4 ) ) & 0x77 ) ;
if ( V_48 )
V_53 ^= 0x80 ;
if ( V_47 == 2 )
V_53 ^= 0x08 ;
if ( V_5 -> V_57 == 0x100 )
V_53 <<= 1 ;
return V_53 ;
}
#else
return 0 ;
#endif
}
static void F_26 ( struct V_4 * V_5 )
{
V_5 -> V_58 = F_25 ( V_5 , V_5 -> V_59 , V_5 -> V_60 ,
V_5 -> V_61 , V_5 -> V_62 ,
V_5 -> V_63 ^ V_5 -> V_64 , V_5 -> V_65 ) ;
V_5 -> V_32 = ( F_25 ( V_5 , V_5 -> V_59 , 1 , V_5 -> V_61 , 0 , V_5 -> V_64 , 0 ) << 8 ) | ' ' ;
}
void F_27 ( struct V_4 * V_5 , int V_12 , int V_36 , int V_13 )
{
unsigned short * V_14 ;
F_21 () ;
V_36 /= 2 ;
V_14 = F_8 ( V_5 , V_12 , V_13 ) ;
if ( V_5 -> V_16 -> V_66 )
V_5 -> V_16 -> V_66 ( V_5 , V_14 , V_36 ) ;
#ifndef F_18
else {
T_1 * V_44 = V_14 ;
int V_67 = V_36 ;
T_1 V_53 ;
if ( ! V_5 -> V_54 ) {
while ( V_67 -- ) {
V_53 = F_19 ( V_44 ) ;
V_53 ^= 0x0800 ;
F_28 ( V_53 , V_44 ) ;
V_44 ++ ;
}
} else if ( V_5 -> V_57 == 0x100 ) {
while ( V_67 -- ) {
V_53 = F_19 ( V_44 ) ;
V_53 = ( ( V_53 ) & 0x11ff ) | ( ( ( V_53 ) & 0xe000 ) >> 4 ) | ( ( ( V_53 ) & 0x0e00 ) << 4 ) ;
F_28 ( V_53 , V_44 ) ;
V_44 ++ ;
}
} else {
while ( V_67 -- ) {
V_53 = F_19 ( V_44 ) ;
V_53 = ( ( V_53 ) & 0x88ff ) | ( ( ( V_53 ) & 0x7000 ) >> 4 ) | ( ( ( V_53 ) & 0x0700 ) << 4 ) ;
F_28 ( V_53 , V_44 ) ;
V_44 ++ ;
}
}
}
#endif
if ( F_22 ( V_5 ) )
F_17 ( V_5 , ( unsigned long ) V_14 , V_36 ) ;
}
void F_29 ( struct V_4 * V_5 , int V_12 )
{
static int V_68 = - 1 ;
static unsigned short V_69 ;
static unsigned short V_70 , V_71 ;
F_21 () ;
if ( V_68 != - 1 && V_68 >= 0 &&
V_68 < V_5 -> V_72 ) {
F_28 ( V_69 , F_8 ( V_5 , V_68 , 1 ) ) ;
if ( F_22 ( V_5 ) )
V_5 -> V_16 -> V_73 ( V_5 , V_69 , V_71 , V_70 ) ;
}
V_68 = V_12 ;
if ( V_12 != - 1 && V_12 >= 0 &&
V_12 < V_5 -> V_72 ) {
unsigned short V_74 ;
unsigned short * V_14 ;
V_14 = F_8 ( V_5 , V_12 , 1 ) ;
V_69 = F_19 ( V_14 ) ;
V_74 = V_69 ^ V_5 -> V_75 ;
F_28 ( V_74 , V_14 ) ;
if ( F_22 ( V_5 ) ) {
V_70 = ( V_12 >> 1 ) % V_5 -> V_31 ;
V_71 = ( V_12 >> 1 ) / V_5 -> V_31 ;
V_5 -> V_16 -> V_73 ( V_5 , V_74 , V_71 , V_70 ) ;
}
}
}
static void F_30 ( struct V_4 * V_5 , unsigned int V_24 )
{
unsigned short * V_14 = ( unsigned short * ) V_5 -> V_76 ;
F_14 ( V_14 + V_24 , V_14 , ( V_5 -> V_31 - V_5 -> V_77 ) * 2 ) ;
F_15 ( V_14 , V_5 -> V_32 , V_24 * 2 ) ;
V_5 -> V_78 = 0 ;
if ( F_22 ( V_5 ) )
F_17 ( V_5 , ( unsigned long ) V_14 ,
V_5 -> V_31 - V_5 -> V_77 ) ;
}
static void F_31 ( struct V_4 * V_5 , unsigned int V_24 )
{
unsigned short * V_14 = ( unsigned short * ) V_5 -> V_76 ;
F_32 ( V_14 , V_14 + V_24 , ( V_5 -> V_31 - V_5 -> V_77 - V_24 ) * 2 ) ;
F_15 ( V_14 + V_5 -> V_31 - V_5 -> V_77 - V_24 , V_5 -> V_32 ,
V_24 * 2 ) ;
V_5 -> V_78 = 0 ;
if ( F_22 ( V_5 ) )
F_17 ( V_5 , ( unsigned long ) V_14 ,
V_5 -> V_31 - V_5 -> V_77 ) ;
}
static void F_33 ( struct V_4 * V_5 )
{
int V_79 = F_19 ( ( T_1 * ) V_5 -> V_76 ) ;
T_3 type = V_5 -> V_80 ;
if ( ! ( type & 0x10 ) ) return;
if ( V_81 != - 1 ) return;
V_81 = V_79 ;
V_79 |= ( ( type >> 8 ) & 0xff00 ) ;
V_79 ^= ( ( type ) & 0xff00 ) ;
if ( ( type & 0x20 ) && ( ( V_81 & 0x7000 ) == ( V_79 & 0x7000 ) ) ) V_79 ^= 0x7000 ;
if ( ( type & 0x40 ) && ( ( V_79 & 0x700 ) == ( ( V_79 & 0x7000 ) >> 4 ) ) ) V_79 ^= 0x0700 ;
F_28 ( V_79 , ( T_1 * ) V_5 -> V_76 ) ;
if ( F_22 ( V_5 ) )
V_5 -> V_16 -> V_73 ( V_5 , V_79 , V_5 -> V_82 , V_5 -> V_77 ) ;
}
static void F_34 ( struct V_4 * V_5 )
{
if ( V_81 != - 1 ) {
F_28 ( V_81 , ( T_1 * ) V_5 -> V_76 ) ;
if ( F_22 ( V_5 ) )
V_5 -> V_16 -> V_73 ( V_5 , V_81 ,
V_5 -> V_82 , V_5 -> V_77 ) ;
V_81 = - 1 ;
}
}
static void F_23 ( struct V_4 * V_5 )
{
if ( V_5 == V_83 )
F_35 () ;
V_5 -> V_16 -> V_84 ( V_5 , V_85 ) ;
F_34 ( V_5 ) ;
}
static void F_24 ( struct V_4 * V_5 )
{
if ( ! F_36 ( V_5 ) || V_86 ||
V_5 -> V_87 == V_88 )
return;
if ( V_5 -> V_89 ) {
if ( V_5 == V_83 )
F_35 () ;
F_33 ( V_5 ) ;
if ( ( V_5 -> V_80 & 0x0f ) != 1 )
V_5 -> V_16 -> V_84 ( V_5 , V_90 ) ;
} else
F_23 ( V_5 ) ;
}
static void F_37 ( struct V_4 * V_5 )
{
F_21 () ;
if ( ! F_13 ( V_5 ) ||
! V_5 -> V_16 -> V_91 ||
! V_5 -> V_16 -> V_91 ( V_5 ) )
V_5 -> V_15 = ( unsigned long ) V_5 -> V_92 ;
V_5 -> V_18 = V_5 -> V_15 ;
V_5 -> V_93 = V_5 -> V_15 + V_5 -> V_72 ;
V_5 -> V_76 = V_5 -> V_15 + V_5 -> V_30 * V_5 -> V_82 + 2 * V_5 -> V_77 ;
}
static inline void F_38 ( struct V_4 * V_5 )
{
F_21 () ;
if ( V_5 -> V_16 -> V_94 )
V_5 -> V_16 -> V_94 ( V_5 ) ;
}
static void F_39 ( struct V_4 * V_5 )
{
unsigned short * V_14 = ( unsigned short * ) V_5 -> V_15 ;
int V_36 = V_5 -> V_72 / 2 ;
int V_95 = V_5 -> V_57 | 0xff ;
for (; V_36 > 0 ; V_36 -- , V_14 ++ ) {
F_28 ( ( F_19 ( V_14 ) & V_95 ) | ( V_5 -> V_32 & ~ V_95 ) , V_14 ) ;
}
}
void F_40 ( struct V_4 * V_5 , int V_96 )
{
int V_97 = 0 ;
F_21 () ;
if ( ! V_5 ) {
return;
}
if ( V_96 ) {
struct V_4 * V_98 = V_99 [ V_100 ] . V_25 ;
if ( V_98 == V_5 )
return;
if ( ! F_13 ( V_5 ) )
V_97 = 1 ;
* V_5 -> V_101 = V_5 ;
V_100 = V_5 -> V_102 ;
F_23 ( V_98 ) ;
if ( ! F_13 ( V_98 ) ) {
F_38 ( V_98 ) ;
F_37 ( V_98 ) ;
}
if ( V_103 )
F_41 ( & V_103 -> V_104 , NULL , L_1 ) ;
} else {
F_23 ( V_5 ) ;
V_97 = 1 ;
}
if ( V_97 ) {
int V_105 ;
int V_106 = V_5 -> V_54 ;
F_37 ( V_5 ) ;
V_105 = V_5 -> V_16 -> V_107 ( V_5 ) ;
F_42 ( V_5 ) ;
if ( V_106 != V_5 -> V_54 ) {
F_26 ( V_5 ) ;
F_39 ( V_5 ) ;
}
if ( ( V_105 && V_5 -> V_87 != V_88 ) ||
F_43 ( V_5 ) )
F_17 ( V_5 , V_5 -> V_15 , V_5 -> V_72 / 2 ) ;
}
F_24 ( V_5 ) ;
if ( V_96 ) {
F_44 () ;
F_45 () ;
F_7 ( V_5 ) ;
}
}
int F_46 ( unsigned int V_79 )
{
return ( V_79 < V_108 && V_99 [ V_79 ] . V_25 ) ;
}
static void F_47 ( struct V_4 * V_5 , int V_109 , int V_110 )
{
if ( V_5 -> V_16 )
F_48 ( V_5 -> V_16 -> V_111 ) ;
V_5 -> V_16 = V_112 ;
#ifndef F_49
if ( V_113 [ V_109 ] )
V_5 -> V_16 = V_113 [ V_109 ] ;
#endif
F_50 ( V_5 -> V_16 -> V_111 ) ;
V_5 -> V_102 = V_109 ;
V_5 -> V_101 = & V_114 ;
V_5 -> V_115 = & V_5 -> V_116 ;
V_5 -> V_116 = 0 ;
V_5 -> V_57 = 0 ;
V_5 -> V_75 = 0 ;
V_5 -> V_54 = 0 ;
V_5 -> V_117 = false ;
V_5 -> V_16 -> V_118 ( V_5 , V_110 ) ;
if ( ! V_5 -> V_75 )
V_5 -> V_75 = V_5 -> V_54 ? 0x7700 : 0x0800 ;
V_5 -> V_119 = V_5 -> V_75 ;
V_5 -> V_30 = V_5 -> V_31 << 1 ;
V_5 -> V_72 = V_5 -> V_27 * V_5 -> V_30 ;
}
int F_51 ( unsigned int V_120 )
{
F_21 () ;
if ( V_120 >= V_108 )
return - V_121 ;
if ( ! V_99 [ V_120 ] . V_25 ) {
struct V_4 * V_5 ;
struct V_7 V_8 ;
if ( V_120 >= V_122 && ! F_52 ( V_123 ) )
return - V_124 ;
V_8 . V_5 = V_5 = F_53 ( sizeof( struct V_4 ) , V_125 ) ;
if ( ! V_5 )
return - V_126 ;
V_99 [ V_120 ] . V_25 = V_5 ;
F_54 ( & V_5 -> V_127 ) ;
F_55 ( & V_99 [ V_120 ] . V_128 , V_129 ) ;
F_47 ( V_5 , V_120 , 1 ) ;
if ( ! * V_5 -> V_115 )
F_56 ( V_5 ) ;
V_5 -> V_92 = F_57 ( V_5 -> V_72 , V_125 ) ;
if ( ! V_5 -> V_92 ) {
F_58 ( & V_5 -> V_127 ) ;
F_59 ( V_5 ) ;
V_99 [ V_120 ] . V_25 = NULL ;
return - V_126 ;
}
if ( V_130 == - 1 )
V_130 = 1 ;
F_60 ( V_5 , V_5 -> V_27 , V_5 -> V_31 , 1 ) ;
F_61 ( V_120 ) ;
F_6 ( & V_3 , V_131 , & V_8 ) ;
}
return 0 ;
}
static inline int F_62 ( struct V_4 * V_5 , int V_132 , int V_133 ,
int V_134 )
{
int V_135 = 0 ;
if ( V_5 -> V_87 != V_88 && V_5 -> V_16 -> V_136 )
V_135 = V_5 -> V_16 -> V_136 ( V_5 , V_132 , V_133 , V_134 ) ;
return V_135 ;
}
static int F_63 ( struct V_137 * V_138 , struct V_4 * V_5 ,
unsigned int V_139 , unsigned int V_19 )
{
unsigned long V_140 , V_141 , V_142 , V_143 , V_144 , V_135 = 0 ;
unsigned long V_145 ;
unsigned int V_146 , V_147 ;
unsigned int V_148 , V_149 , V_150 , V_151 ;
unsigned int V_134 ;
unsigned short * V_152 ;
F_21 () ;
if ( ! V_5 )
return - V_121 ;
V_134 = V_5 -> V_153 ;
V_5 -> V_153 = 0 ;
if ( V_139 > V_154 || V_19 > V_155 )
return - V_156 ;
V_148 = ( V_139 ? V_139 : V_5 -> V_31 ) ;
V_149 = ( V_19 ? V_19 : V_5 -> V_27 ) ;
V_150 = V_148 << 1 ;
V_151 = V_150 * V_149 ;
if ( V_148 == V_5 -> V_31 && V_149 == V_5 -> V_27 )
return 0 ;
V_152 = F_57 ( V_151 , V_157 ) ;
if ( ! V_152 )
return - V_126 ;
V_146 = V_5 -> V_27 ;
V_147 = V_5 -> V_30 ;
V_135 = F_62 ( V_5 , V_148 , V_149 , V_134 ) ;
if ( V_135 ) {
F_59 ( V_152 ) ;
return V_135 ;
}
V_5 -> V_27 = V_149 ;
V_5 -> V_31 = V_148 ;
V_5 -> V_30 = V_150 ;
V_5 -> V_72 = V_151 ;
V_143 = F_64 ( V_147 , V_150 ) ;
V_144 = V_150 - V_143 ;
V_140 = V_5 -> V_15 ;
V_141 = ( long ) V_152 ;
V_142 = V_141 + V_151 ;
if ( V_5 -> V_82 > V_149 ) {
if ( V_146 - V_5 -> V_82 < V_149 ) {
V_140 += ( V_146 - V_149 ) * V_147 ;
} else {
V_140 += ( V_5 -> V_82 - V_149 / 2 ) * V_147 ;
}
}
V_145 = V_140 + V_147 * F_64 ( V_146 , V_149 ) ;
F_26 ( V_5 ) ;
while ( V_140 < V_145 ) {
F_32 ( ( unsigned short * ) V_141 ,
( unsigned short * ) V_140 , V_143 ) ;
if ( V_144 )
F_15 ( ( void * ) ( V_141 + V_143 ) ,
V_5 -> V_32 , V_144 ) ;
V_140 += V_147 ;
V_141 += V_150 ;
}
if ( V_142 > V_141 )
F_15 ( ( void * ) V_141 , V_5 -> V_32 ,
V_142 - V_141 ) ;
F_59 ( V_5 -> V_92 ) ;
V_5 -> V_92 = V_152 ;
V_5 -> V_72 = V_151 ;
F_37 ( V_5 ) ;
V_5 -> V_158 = 0 ;
V_5 -> V_159 = V_5 -> V_27 ;
F_65 ( V_5 , V_5 -> V_77 , V_5 -> V_82 ) ;
F_66 ( V_5 ) ;
if ( V_138 ) {
struct V_160 V_161 ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_161 . V_162 = V_5 -> V_27 ;
V_161 . V_163 = V_5 -> V_31 ;
V_161 . V_164 = V_5 -> V_165 ;
F_67 ( V_138 , & V_161 ) ;
}
if ( F_13 ( V_5 ) )
F_68 ( V_5 ) ;
F_69 ( V_166 , V_5 -> V_102 , V_5 -> V_102 ) ;
return V_135 ;
}
int F_70 ( struct V_4 * V_5 , unsigned int V_139 , unsigned int V_167 )
{
return F_63 ( V_5 -> V_127 . V_138 , V_5 , V_139 , V_167 ) ;
}
static int F_71 ( struct V_137 * V_138 , struct V_160 * V_161 )
{
struct V_4 * V_5 = V_138 -> V_168 ;
int V_169 ;
F_72 () ;
V_169 = F_63 ( V_138 , V_5 , V_161 -> V_163 , V_161 -> V_162 ) ;
F_73 () ;
return V_169 ;
}
void F_74 ( unsigned int V_120 )
{
F_21 () ;
if ( F_46 ( V_120 ) ) {
struct V_4 * V_5 = V_99 [ V_120 ] . V_25 ;
struct V_7 V_8 = { . V_5 = V_5 } ;
F_6 ( & V_3 , V_170 , & V_8 ) ;
F_75 ( V_120 ) ;
V_5 -> V_16 -> V_171 ( V_5 ) ;
F_76 ( V_5 -> V_172 ) ;
F_48 ( V_5 -> V_16 -> V_111 ) ;
F_59 ( V_5 -> V_92 ) ;
if ( V_120 >= V_173 ) {
F_58 ( & V_5 -> V_127 ) ;
F_59 ( V_5 ) ;
}
V_99 [ V_120 ] . V_25 = NULL ;
}
}
static void F_65 ( struct V_4 * V_5 , int V_174 , int V_175 )
{
int V_176 , V_177 ;
if ( V_174 < 0 )
V_5 -> V_77 = 0 ;
else {
if ( V_174 >= V_5 -> V_31 )
V_5 -> V_77 = V_5 -> V_31 - 1 ;
else
V_5 -> V_77 = V_174 ;
}
if ( V_5 -> V_178 ) {
V_176 = V_5 -> V_158 ;
V_177 = V_5 -> V_159 ;
} else {
V_176 = 0 ;
V_177 = V_5 -> V_27 ;
}
if ( V_175 < V_176 )
V_5 -> V_82 = V_176 ;
else if ( V_175 >= V_177 )
V_5 -> V_82 = V_177 - 1 ;
else
V_5 -> V_82 = V_175 ;
V_5 -> V_76 = V_5 -> V_15 + V_5 -> V_82 * V_5 -> V_30 + ( V_5 -> V_77 << 1 ) ;
V_5 -> V_78 = 0 ;
}
static void F_77 ( struct V_4 * V_5 , int V_174 , int V_175 )
{
F_65 ( V_5 , V_174 , V_5 -> V_178 ? ( V_5 -> V_158 + V_175 ) : V_175 ) ;
}
void F_78 ( struct V_4 * V_5 , int V_19 )
{
if ( ! V_19 )
V_19 = V_5 -> V_27 / 2 ;
F_9 ( - V_19 ) ;
}
void F_79 ( struct V_4 * V_5 , int V_19 )
{
if ( ! V_19 )
V_19 = V_5 -> V_27 / 2 ;
F_9 ( V_19 ) ;
}
static void F_80 ( struct V_4 * V_5 )
{
if ( V_5 -> V_82 + 1 == V_5 -> V_159 )
F_12 ( V_5 , V_5 -> V_158 , V_5 -> V_159 , 1 ) ;
else if ( V_5 -> V_82 < V_5 -> V_27 - 1 ) {
V_5 -> V_82 ++ ;
V_5 -> V_76 += V_5 -> V_30 ;
}
V_5 -> V_78 = 0 ;
F_5 ( V_5 , '\n' ) ;
}
static void F_81 ( struct V_4 * V_5 )
{
if ( V_5 -> V_82 == V_5 -> V_158 )
F_16 ( V_5 , V_5 -> V_158 , V_5 -> V_159 , 1 ) ;
else if ( V_5 -> V_82 > 0 ) {
V_5 -> V_82 -- ;
V_5 -> V_76 -= V_5 -> V_30 ;
}
V_5 -> V_78 = 0 ;
}
static inline void F_82 ( struct V_4 * V_5 )
{
V_5 -> V_76 -= V_5 -> V_77 << 1 ;
V_5 -> V_78 = V_5 -> V_77 = 0 ;
F_5 ( V_5 , '\r' ) ;
}
static inline void F_83 ( struct V_4 * V_5 )
{
if ( V_5 -> V_77 ) {
V_5 -> V_76 -= 2 ;
V_5 -> V_77 -- ;
V_5 -> V_78 = 0 ;
F_5 ( V_5 , '\b' ) ;
}
}
static inline void F_84 ( struct V_4 * V_5 )
{
}
static void F_85 ( struct V_4 * V_5 , int V_179 )
{
unsigned int V_36 ;
unsigned short * V_35 ;
switch ( V_179 ) {
case 0 :
V_36 = ( V_5 -> V_93 - V_5 -> V_76 ) >> 1 ;
V_35 = ( unsigned short * ) V_5 -> V_76 ;
break;
case 1 :
V_36 = ( ( V_5 -> V_76 - V_5 -> V_15 ) >> 1 ) + 1 ;
V_35 = ( unsigned short * ) V_5 -> V_15 ;
break;
case 3 :
F_15 ( V_5 -> V_92 , V_5 -> V_32 ,
V_5 -> V_72 >> 1 ) ;
F_37 ( V_5 ) ;
case 2 :
V_36 = V_5 -> V_31 * V_5 -> V_27 ;
V_35 = ( unsigned short * ) V_5 -> V_15 ;
break;
default:
return;
}
F_15 ( V_35 , V_5 -> V_32 , 2 * V_36 ) ;
if ( F_22 ( V_5 ) )
F_17 ( V_5 , ( unsigned long ) V_35 , V_36 ) ;
V_5 -> V_78 = 0 ;
}
static void F_86 ( struct V_4 * V_5 , int V_179 )
{
unsigned int V_36 ;
unsigned short * V_35 ;
switch ( V_179 ) {
case 0 :
V_36 = V_5 -> V_31 - V_5 -> V_77 ;
V_35 = ( unsigned short * ) V_5 -> V_76 ;
break;
case 1 :
V_35 = ( unsigned short * ) ( V_5 -> V_76 - ( V_5 -> V_77 << 1 ) ) ;
V_36 = V_5 -> V_77 + 1 ;
break;
case 2 :
V_35 = ( unsigned short * ) ( V_5 -> V_76 - ( V_5 -> V_77 << 1 ) ) ;
V_36 = V_5 -> V_31 ;
break;
default:
return;
}
F_15 ( V_35 , V_5 -> V_32 , 2 * V_36 ) ;
V_5 -> V_78 = 0 ;
if ( F_22 ( V_5 ) )
F_17 ( V_5 , ( unsigned long ) V_35 , V_36 ) ;
}
static void F_87 ( struct V_4 * V_5 , int V_179 )
{
int V_36 ;
if ( ! V_179 )
V_179 ++ ;
V_36 = ( V_179 > V_5 -> V_31 - V_5 -> V_77 ) ? ( V_5 -> V_31 - V_5 -> V_77 ) : V_179 ;
F_15 ( ( unsigned short * ) V_5 -> V_76 , V_5 -> V_32 , 2 * V_36 ) ;
if ( F_22 ( V_5 ) )
V_5 -> V_16 -> V_180 ( V_5 , V_5 -> V_82 , V_5 -> V_77 , 1 , V_36 ) ;
V_5 -> V_78 = 0 ;
}
static void F_88 ( struct V_4 * V_5 )
{
V_5 -> V_60 = 1 ;
V_5 -> V_65 = 0 ;
V_5 -> V_62 = 0 ;
V_5 -> V_63 = 0 ;
V_5 -> V_61 = 0 ;
V_5 -> V_59 = V_5 -> V_181 ;
}
static void F_89 ( struct V_4 * V_5 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 <= V_5 -> V_182 ; V_79 ++ )
switch ( V_5 -> V_183 [ V_79 ] ) {
case 0 :
F_88 ( V_5 ) ;
break;
case 1 :
V_5 -> V_60 = 2 ;
break;
case 2 :
V_5 -> V_60 = 0 ;
break;
case 3 :
V_5 -> V_65 = 1 ;
break;
case 4 :
V_5 -> V_62 = 1 ;
break;
case 5 :
V_5 -> V_61 = 1 ;
break;
case 7 :
V_5 -> V_63 = 1 ;
break;
case 10 :
V_5 -> V_184 = F_90 ( V_5 -> V_185 == 0
? V_5 -> V_186
: V_5 -> V_187 , V_5 ) ;
V_5 -> V_188 = 0 ;
V_5 -> V_189 = 0 ;
break;
case 11 :
V_5 -> V_184 = F_90 ( V_190 , V_5 ) ;
V_5 -> V_188 = 1 ;
V_5 -> V_189 = 0 ;
break;
case 12 :
V_5 -> V_184 = F_90 ( V_190 , V_5 ) ;
V_5 -> V_188 = 1 ;
V_5 -> V_189 = 1 ;
break;
case 21 :
case 22 :
V_5 -> V_60 = 1 ;
break;
case 23 :
V_5 -> V_65 = 0 ;
break;
case 24 :
V_5 -> V_62 = 0 ;
break;
case 25 :
V_5 -> V_61 = 0 ;
break;
case 27 :
V_5 -> V_63 = 0 ;
break;
case 38 :
V_5 -> V_59 = ( V_5 -> V_181 & 0x0f ) | ( V_5 -> V_59 & 0xf0 ) ;
V_5 -> V_62 = 1 ;
break;
case 39 :
V_5 -> V_59 = ( V_5 -> V_181 & 0x0f ) | ( V_5 -> V_59 & 0xf0 ) ;
V_5 -> V_62 = 0 ;
break;
case 49 :
V_5 -> V_59 = ( V_5 -> V_181 & 0xf0 ) | ( V_5 -> V_59 & 0x0f ) ;
break;
default:
if ( V_5 -> V_183 [ V_79 ] >= 30 && V_5 -> V_183 [ V_79 ] <= 37 )
V_5 -> V_59 = V_191 [ V_5 -> V_183 [ V_79 ] - 30 ]
| ( V_5 -> V_59 & 0xf0 ) ;
else if ( V_5 -> V_183 [ V_79 ] >= 40 && V_5 -> V_183 [ V_79 ] <= 47 )
V_5 -> V_59 = ( V_191 [ V_5 -> V_183 [ V_79 ] - 40 ] << 4 )
| ( V_5 -> V_59 & 0x0f ) ;
break;
}
F_26 ( V_5 ) ;
}
static void F_91 ( const char * V_14 , struct V_137 * V_138 )
{
while ( * V_14 ) {
F_92 ( V_138 , * V_14 , 0 ) ;
V_14 ++ ;
}
F_93 ( V_138 ) ;
}
static void F_94 ( struct V_4 * V_5 , struct V_137 * V_138 )
{
char V_192 [ 40 ] ;
sprintf ( V_192 , L_2 , V_5 -> V_82 + ( V_5 -> V_178 ? V_5 -> V_158 + 1 : 1 ) , V_5 -> V_77 + 1 ) ;
F_91 ( V_192 , V_138 ) ;
}
static inline void F_95 ( struct V_137 * V_138 )
{
F_91 ( L_3 , V_138 ) ;
}
static inline void F_96 ( struct V_137 * V_138 )
{
F_91 ( V_193 , V_138 ) ;
}
void F_97 ( struct V_137 * V_138 , int V_194 , int V_195 , int V_196 )
{
char V_192 [ 8 ] ;
sprintf ( V_192 , L_4 , ( char ) ( ' ' + V_194 ) , ( char ) ( '!' + V_195 ) ,
( char ) ( '!' + V_196 ) ) ;
F_91 ( V_192 , V_138 ) ;
}
int F_98 ( void )
{
return V_99 [ V_100 ] . V_25 -> V_197 ;
}
static void F_99 ( struct V_4 * V_5 , int V_198 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 <= V_5 -> V_182 ; V_79 ++ )
if ( V_5 -> V_199 ) {
switch( V_5 -> V_183 [ V_79 ] ) {
case 1 :
if ( V_198 )
F_100 ( V_5 , V_200 ) ;
else
F_101 ( V_5 , V_200 ) ;
break;
case 3 :
V_5 -> V_201 = V_198 ;
#if 0
vc_resize(deccolm ? 132 : 80, vc->vc_rows);
#endif
break;
case 5 :
if ( V_5 -> V_64 != V_198 ) {
V_5 -> V_64 = V_198 ;
F_27 ( V_5 , 0 , V_5 -> V_72 , 0 ) ;
F_26 ( V_5 ) ;
}
break;
case 6 :
V_5 -> V_178 = V_198 ;
F_77 ( V_5 , 0 , 0 ) ;
break;
case 7 :
V_5 -> V_202 = V_198 ;
break;
case 8 :
if ( V_198 )
F_100 ( V_5 , V_203 ) ;
else
F_101 ( V_5 , V_203 ) ;
break;
case 9 :
V_5 -> V_197 = V_198 ? 1 : 0 ;
break;
case 25 :
V_5 -> V_89 = V_198 ;
break;
case 1000 :
V_5 -> V_197 = V_198 ? 2 : 0 ;
break;
}
} else {
switch( V_5 -> V_183 [ V_79 ] ) {
case 3 :
V_5 -> V_188 = V_198 ;
break;
case 4 :
V_5 -> V_204 = V_198 ;
break;
case 20 :
if ( V_198 )
F_100 ( V_5 , V_205 ) ;
else
F_101 ( V_5 , V_205 ) ;
break;
}
}
}
static void F_102 ( struct V_4 * V_5 )
{
switch( V_5 -> V_183 [ 0 ] ) {
case 1 :
if ( V_5 -> V_54 &&
V_5 -> V_183 [ 1 ] < 16 ) {
V_5 -> V_56 = V_191 [ V_5 -> V_183 [ 1 ] ] ;
if ( V_5 -> V_62 )
F_26 ( V_5 ) ;
}
break;
case 2 :
if ( V_5 -> V_54 &&
V_5 -> V_183 [ 1 ] < 16 ) {
V_5 -> V_206 = V_191 [ V_5 -> V_183 [ 1 ] ] ;
if ( V_5 -> V_60 == 0 )
F_26 ( V_5 ) ;
}
break;
case 8 :
V_5 -> V_181 = V_5 -> V_58 ;
if ( V_5 -> V_57 == 0x100 )
V_5 -> V_181 >>= 1 ;
F_88 ( V_5 ) ;
F_26 ( V_5 ) ;
break;
case 9 :
V_207 = ( ( V_5 -> V_183 [ 1 ] < 60 ) ? V_5 -> V_183 [ 1 ] : 60 ) * 60 ;
F_103 () ;
break;
case 10 :
if ( V_5 -> V_182 >= 1 )
V_5 -> V_208 = V_5 -> V_183 [ 1 ] ;
else
V_5 -> V_208 = V_209 ;
break;
case 11 :
if ( V_5 -> V_182 >= 1 )
V_5 -> V_210 = ( V_5 -> V_183 [ 1 ] < 2000 ) ?
V_5 -> V_183 [ 1 ] * V_211 / 1000 : 0 ;
else
V_5 -> V_210 = V_212 ;
break;
case 12 :
if ( V_5 -> V_183 [ 1 ] >= 1 && F_46 ( V_5 -> V_183 [ 1 ] - 1 ) )
F_104 ( V_5 -> V_183 [ 1 ] - 1 ) ;
break;
case 13 :
F_103 () ;
break;
case 14 :
V_213 = ( ( V_5 -> V_183 [ 1 ] < 60 ) ? V_5 -> V_183 [ 1 ] : 60 ) * 60 * V_211 ;
break;
case 15 :
F_104 ( V_214 ) ;
break;
}
}
static void F_105 ( struct V_4 * V_5 , unsigned int V_24 )
{
if ( V_24 > V_5 -> V_31 - V_5 -> V_77 )
V_24 = V_5 -> V_31 - V_5 -> V_77 ;
else if ( ! V_24 )
V_24 = 1 ;
F_30 ( V_5 , V_24 ) ;
}
static void F_106 ( struct V_4 * V_5 , unsigned int V_24 )
{
if ( V_24 > V_5 -> V_27 - V_5 -> V_82 )
V_24 = V_5 -> V_27 - V_5 -> V_82 ;
else if ( ! V_24 )
V_24 = 1 ;
F_16 ( V_5 , V_5 -> V_82 , V_5 -> V_159 , V_24 ) ;
V_5 -> V_78 = 0 ;
}
static void F_107 ( struct V_4 * V_5 , unsigned int V_24 )
{
if ( V_24 > V_5 -> V_31 - V_5 -> V_77 )
V_24 = V_5 -> V_31 - V_5 -> V_77 ;
else if ( ! V_24 )
V_24 = 1 ;
F_31 ( V_5 , V_24 ) ;
}
static void F_108 ( struct V_4 * V_5 , unsigned int V_24 )
{
if ( V_24 > V_5 -> V_27 - V_5 -> V_82 )
V_24 = V_5 -> V_27 - V_5 -> V_82 ;
else if ( ! V_24 )
V_24 = 1 ;
F_12 ( V_5 , V_5 -> V_82 , V_5 -> V_159 , V_24 ) ;
V_5 -> V_78 = 0 ;
}
static void F_66 ( struct V_4 * V_5 )
{
V_5 -> V_215 = V_5 -> V_77 ;
V_5 -> V_216 = V_5 -> V_82 ;
V_5 -> V_217 = V_5 -> V_60 ;
V_5 -> V_218 = V_5 -> V_65 ;
V_5 -> V_219 = V_5 -> V_62 ;
V_5 -> V_220 = V_5 -> V_61 ;
V_5 -> V_221 = V_5 -> V_63 ;
V_5 -> V_222 = V_5 -> V_185 ;
V_5 -> V_223 = V_5 -> V_59 ;
V_5 -> V_224 = V_5 -> V_186 ;
V_5 -> V_225 = V_5 -> V_187 ;
}
static void F_109 ( struct V_4 * V_5 )
{
F_65 ( V_5 , V_5 -> V_215 , V_5 -> V_216 ) ;
V_5 -> V_60 = V_5 -> V_217 ;
V_5 -> V_65 = V_5 -> V_218 ;
V_5 -> V_62 = V_5 -> V_219 ;
V_5 -> V_61 = V_5 -> V_220 ;
V_5 -> V_63 = V_5 -> V_221 ;
V_5 -> V_185 = V_5 -> V_222 ;
V_5 -> V_59 = V_5 -> V_223 ;
V_5 -> V_186 = V_5 -> V_224 ;
V_5 -> V_187 = V_5 -> V_225 ;
V_5 -> V_184 = F_90 ( V_5 -> V_185 ? V_5 -> V_187 : V_5 -> V_186 , V_5 ) ;
F_26 ( V_5 ) ;
V_5 -> V_78 = 0 ;
}
static void F_110 ( struct V_4 * V_5 , int V_226 )
{
V_5 -> V_158 = 0 ;
V_5 -> V_159 = V_5 -> V_27 ;
V_5 -> V_227 = V_228 ;
V_5 -> V_199 = 0 ;
V_5 -> V_184 = F_90 ( V_229 , V_5 ) ;
V_5 -> V_186 = V_229 ;
V_5 -> V_187 = V_230 ;
V_5 -> V_185 = 0 ;
V_5 -> V_78 = 0 ;
V_5 -> V_197 = 0 ;
V_5 -> V_231 = V_232 ;
V_5 -> V_233 = 0 ;
V_5 -> V_188 = 0 ;
V_5 -> V_189 = 0 ;
V_5 -> V_64 = 0 ;
V_5 -> V_178 = 0 ;
V_5 -> V_202 = 1 ;
V_5 -> V_89 = V_130 ;
V_5 -> V_204 = 0 ;
F_111 ( V_5 -> V_102 ) ;
V_5 -> V_80 = V_234 ;
V_5 -> V_75 = V_5 -> V_119 ;
F_88 ( V_5 ) ;
F_26 ( V_5 ) ;
V_5 -> V_235 [ 0 ] = 0x01010100 ;
V_5 -> V_235 [ 1 ] =
V_5 -> V_235 [ 2 ] =
V_5 -> V_235 [ 3 ] =
V_5 -> V_235 [ 4 ] =
V_5 -> V_235 [ 5 ] =
V_5 -> V_235 [ 6 ] =
V_5 -> V_235 [ 7 ] = 0x01010101 ;
V_5 -> V_208 = V_209 ;
V_5 -> V_210 = V_212 ;
F_65 ( V_5 , 0 , 0 ) ;
F_66 ( V_5 ) ;
if ( V_226 )
F_85 ( V_5 , 2 ) ;
}
static void F_112 ( struct V_137 * V_138 , struct V_4 * V_5 , int V_9 )
{
switch ( V_9 ) {
case 0 :
return;
case 7 :
if ( V_5 -> V_210 )
F_113 ( V_5 -> V_208 , V_5 -> V_210 ) ;
return;
case 8 :
F_83 ( V_5 ) ;
return;
case 9 :
V_5 -> V_76 -= ( V_5 -> V_77 << 1 ) ;
while ( V_5 -> V_77 < V_5 -> V_31 - 1 ) {
V_5 -> V_77 ++ ;
if ( V_5 -> V_235 [ V_5 -> V_77 >> 5 ] & ( 1 << ( V_5 -> V_77 & 31 ) ) )
break;
}
V_5 -> V_76 += ( V_5 -> V_77 << 1 ) ;
F_5 ( V_5 , '\t' ) ;
return;
case 10 : case 11 : case 12 :
F_80 ( V_5 ) ;
if ( ! F_114 ( V_5 , V_205 ) )
return;
case 13 :
F_82 ( V_5 ) ;
return;
case 14 :
V_5 -> V_185 = 1 ;
V_5 -> V_184 = F_90 ( V_5 -> V_187 , V_5 ) ;
V_5 -> V_188 = 1 ;
return;
case 15 :
V_5 -> V_185 = 0 ;
V_5 -> V_184 = F_90 ( V_5 -> V_186 , V_5 ) ;
V_5 -> V_188 = 0 ;
return;
case 24 : case 26 :
V_5 -> V_227 = V_228 ;
return;
case 27 :
V_5 -> V_227 = V_236 ;
return;
case 127 :
F_84 ( V_5 ) ;
return;
case 128 + 27 :
V_5 -> V_227 = V_237 ;
return;
}
switch( V_5 -> V_227 ) {
case V_236 :
V_5 -> V_227 = V_228 ;
switch ( V_9 ) {
case '[' :
V_5 -> V_227 = V_237 ;
return;
case ']' :
V_5 -> V_227 = V_238 ;
return;
case '%' :
V_5 -> V_227 = V_239 ;
return;
case 'E' :
F_82 ( V_5 ) ;
F_80 ( V_5 ) ;
return;
case 'M' :
F_81 ( V_5 ) ;
return;
case 'D' :
F_80 ( V_5 ) ;
return;
case 'H' :
V_5 -> V_235 [ V_5 -> V_77 >> 5 ] |= ( 1 << ( V_5 -> V_77 & 31 ) ) ;
return;
case 'Z' :
F_96 ( V_138 ) ;
return;
case '7' :
F_66 ( V_5 ) ;
return;
case '8' :
F_109 ( V_5 ) ;
return;
case '(' :
V_5 -> V_227 = V_240 ;
return;
case ')' :
V_5 -> V_227 = V_241 ;
return;
case '#' :
V_5 -> V_227 = V_242 ;
return;
case 'c' :
F_110 ( V_5 , 1 ) ;
return;
case '>' :
F_101 ( V_5 , V_243 ) ;
return;
case '=' :
F_100 ( V_5 , V_243 ) ;
return;
}
return;
case V_238 :
if ( V_9 == 'P' ) {
for ( V_5 -> V_182 = 0 ; V_5 -> V_182 < V_244 ; V_5 -> V_182 ++ )
V_5 -> V_183 [ V_5 -> V_182 ] = 0 ;
V_5 -> V_182 = 0 ;
V_5 -> V_227 = V_245 ;
return;
} else if ( V_9 == 'R' ) {
F_115 ( V_5 ) ;
V_5 -> V_227 = V_228 ;
} else
V_5 -> V_227 = V_228 ;
return;
case V_245 :
if ( isxdigit ( V_9 ) ) {
V_5 -> V_183 [ V_5 -> V_182 ++ ] = F_116 ( V_9 ) ;
if ( V_5 -> V_182 == 7 ) {
int V_79 = V_5 -> V_183 [ 0 ] * 3 , V_246 = 1 ;
V_5 -> V_247 [ V_79 ] = 16 * V_5 -> V_183 [ V_246 ++ ] ;
V_5 -> V_247 [ V_79 ++ ] += V_5 -> V_183 [ V_246 ++ ] ;
V_5 -> V_247 [ V_79 ] = 16 * V_5 -> V_183 [ V_246 ++ ] ;
V_5 -> V_247 [ V_79 ++ ] += V_5 -> V_183 [ V_246 ++ ] ;
V_5 -> V_247 [ V_79 ] = 16 * V_5 -> V_183 [ V_246 ++ ] ;
V_5 -> V_247 [ V_79 ] += V_5 -> V_183 [ V_246 ] ;
F_42 ( V_5 ) ;
V_5 -> V_227 = V_228 ;
}
} else
V_5 -> V_227 = V_228 ;
return;
case V_237 :
for ( V_5 -> V_182 = 0 ; V_5 -> V_182 < V_244 ; V_5 -> V_182 ++ )
V_5 -> V_183 [ V_5 -> V_182 ] = 0 ;
V_5 -> V_182 = 0 ;
V_5 -> V_227 = V_248 ;
if ( V_9 == '[' ) {
V_5 -> V_227 = V_249 ;
return;
}
V_5 -> V_199 = ( V_9 == '?' ) ;
if ( V_5 -> V_199 )
return;
case V_248 :
if ( V_9 == ';' && V_5 -> V_182 < V_244 - 1 ) {
V_5 -> V_182 ++ ;
return;
} else if ( V_9 >= '0' && V_9 <= '9' ) {
V_5 -> V_183 [ V_5 -> V_182 ] *= 10 ;
V_5 -> V_183 [ V_5 -> V_182 ] += V_9 - '0' ;
return;
} else
V_5 -> V_227 = V_250 ;
case V_250 :
V_5 -> V_227 = V_228 ;
switch( V_9 ) {
case 'h' :
F_99 ( V_5 , 1 ) ;
return;
case 'l' :
F_99 ( V_5 , 0 ) ;
return;
case 'c' :
if ( V_5 -> V_199 ) {
if ( V_5 -> V_183 [ 0 ] )
V_5 -> V_80 = V_5 -> V_183 [ 0 ] | ( V_5 -> V_183 [ 1 ] << 8 ) | ( V_5 -> V_183 [ 2 ] << 16 ) ;
else
V_5 -> V_80 = V_234 ;
return;
}
break;
case 'm' :
if ( V_5 -> V_199 ) {
F_35 () ;
if ( V_5 -> V_183 [ 0 ] )
V_5 -> V_75 = V_5 -> V_183 [ 0 ] << 8 | V_5 -> V_183 [ 1 ] ;
else
V_5 -> V_75 = V_5 -> V_119 ;
return;
}
break;
case 'n' :
if ( ! V_5 -> V_199 ) {
if ( V_5 -> V_183 [ 0 ] == 5 )
F_95 ( V_138 ) ;
else if ( V_5 -> V_183 [ 0 ] == 6 )
F_94 ( V_5 , V_138 ) ;
}
return;
}
if ( V_5 -> V_199 ) {
V_5 -> V_199 = 0 ;
return;
}
switch( V_9 ) {
case 'G' : case '`' :
if ( V_5 -> V_183 [ 0 ] )
V_5 -> V_183 [ 0 ] -- ;
F_65 ( V_5 , V_5 -> V_183 [ 0 ] , V_5 -> V_82 ) ;
return;
case 'A' :
if ( ! V_5 -> V_183 [ 0 ] )
V_5 -> V_183 [ 0 ] ++ ;
F_65 ( V_5 , V_5 -> V_77 , V_5 -> V_82 - V_5 -> V_183 [ 0 ] ) ;
return;
case 'B' : case 'e' :
if ( ! V_5 -> V_183 [ 0 ] )
V_5 -> V_183 [ 0 ] ++ ;
F_65 ( V_5 , V_5 -> V_77 , V_5 -> V_82 + V_5 -> V_183 [ 0 ] ) ;
return;
case 'C' : case 'a' :
if ( ! V_5 -> V_183 [ 0 ] )
V_5 -> V_183 [ 0 ] ++ ;
F_65 ( V_5 , V_5 -> V_77 + V_5 -> V_183 [ 0 ] , V_5 -> V_82 ) ;
return;
case 'D' :
if ( ! V_5 -> V_183 [ 0 ] )
V_5 -> V_183 [ 0 ] ++ ;
F_65 ( V_5 , V_5 -> V_77 - V_5 -> V_183 [ 0 ] , V_5 -> V_82 ) ;
return;
case 'E' :
if ( ! V_5 -> V_183 [ 0 ] )
V_5 -> V_183 [ 0 ] ++ ;
F_65 ( V_5 , 0 , V_5 -> V_82 + V_5 -> V_183 [ 0 ] ) ;
return;
case 'F' :
if ( ! V_5 -> V_183 [ 0 ] )
V_5 -> V_183 [ 0 ] ++ ;
F_65 ( V_5 , 0 , V_5 -> V_82 - V_5 -> V_183 [ 0 ] ) ;
return;
case 'd' :
if ( V_5 -> V_183 [ 0 ] )
V_5 -> V_183 [ 0 ] -- ;
F_77 ( V_5 , V_5 -> V_77 , V_5 -> V_183 [ 0 ] ) ;
return;
case 'H' : case 'f' :
if ( V_5 -> V_183 [ 0 ] )
V_5 -> V_183 [ 0 ] -- ;
if ( V_5 -> V_183 [ 1 ] )
V_5 -> V_183 [ 1 ] -- ;
F_77 ( V_5 , V_5 -> V_183 [ 1 ] , V_5 -> V_183 [ 0 ] ) ;
return;
case 'J' :
F_85 ( V_5 , V_5 -> V_183 [ 0 ] ) ;
return;
case 'K' :
F_86 ( V_5 , V_5 -> V_183 [ 0 ] ) ;
return;
case 'L' :
F_106 ( V_5 , V_5 -> V_183 [ 0 ] ) ;
return;
case 'M' :
F_108 ( V_5 , V_5 -> V_183 [ 0 ] ) ;
return;
case 'P' :
F_107 ( V_5 , V_5 -> V_183 [ 0 ] ) ;
return;
case 'c' :
if ( ! V_5 -> V_183 [ 0 ] )
F_96 ( V_138 ) ;
return;
case 'g' :
if ( ! V_5 -> V_183 [ 0 ] )
V_5 -> V_235 [ V_5 -> V_77 >> 5 ] &= ~ ( 1 << ( V_5 -> V_77 & 31 ) ) ;
else if ( V_5 -> V_183 [ 0 ] == 3 ) {
V_5 -> V_235 [ 0 ] =
V_5 -> V_235 [ 1 ] =
V_5 -> V_235 [ 2 ] =
V_5 -> V_235 [ 3 ] =
V_5 -> V_235 [ 4 ] =
V_5 -> V_235 [ 5 ] =
V_5 -> V_235 [ 6 ] =
V_5 -> V_235 [ 7 ] = 0 ;
}
return;
case 'm' :
F_89 ( V_5 ) ;
return;
case 'q' :
if ( V_5 -> V_183 [ 0 ] < 4 )
F_117 ( V_5 -> V_102 ,
( V_5 -> V_183 [ 0 ] < 3 ) ? V_5 -> V_183 [ 0 ] : 4 ) ;
return;
case 'r' :
if ( ! V_5 -> V_183 [ 0 ] )
V_5 -> V_183 [ 0 ] ++ ;
if ( ! V_5 -> V_183 [ 1 ] )
V_5 -> V_183 [ 1 ] = V_5 -> V_27 ;
if ( V_5 -> V_183 [ 0 ] < V_5 -> V_183 [ 1 ] &&
V_5 -> V_183 [ 1 ] <= V_5 -> V_27 ) {
V_5 -> V_158 = V_5 -> V_183 [ 0 ] - 1 ;
V_5 -> V_159 = V_5 -> V_183 [ 1 ] ;
F_77 ( V_5 , 0 , 0 ) ;
}
return;
case 's' :
F_66 ( V_5 ) ;
return;
case 'u' :
F_109 ( V_5 ) ;
return;
case 'X' :
F_87 ( V_5 , V_5 -> V_183 [ 0 ] ) ;
return;
case '@' :
F_105 ( V_5 , V_5 -> V_183 [ 0 ] ) ;
return;
case ']' :
F_102 ( V_5 ) ;
return;
}
return;
case V_239 :
V_5 -> V_227 = V_228 ;
switch ( V_9 ) {
case '@' :
V_5 -> V_231 = 0 ;
return;
case 'G' :
case '8' :
V_5 -> V_231 = 1 ;
return;
}
return;
case V_249 :
V_5 -> V_227 = V_228 ;
return;
case V_242 :
V_5 -> V_227 = V_228 ;
if ( V_9 == '8' ) {
V_5 -> V_32 =
( V_5 -> V_32 & 0xff00 ) | 'E' ;
F_85 ( V_5 , 2 ) ;
V_5 -> V_32 =
( V_5 -> V_32 & 0xff00 ) | ' ' ;
F_17 ( V_5 , V_5 -> V_15 , V_5 -> V_72 / 2 ) ;
}
return;
case V_240 :
if ( V_9 == '0' )
V_5 -> V_186 = V_230 ;
else if ( V_9 == 'B' )
V_5 -> V_186 = V_229 ;
else if ( V_9 == 'U' )
V_5 -> V_186 = V_190 ;
else if ( V_9 == 'K' )
V_5 -> V_186 = V_251 ;
if ( V_5 -> V_185 == 0 )
V_5 -> V_184 = F_90 ( V_5 -> V_186 , V_5 ) ;
V_5 -> V_227 = V_228 ;
return;
case V_241 :
if ( V_9 == '0' )
V_5 -> V_187 = V_230 ;
else if ( V_9 == 'B' )
V_5 -> V_187 = V_229 ;
else if ( V_9 == 'U' )
V_5 -> V_187 = V_190 ;
else if ( V_9 == 'K' )
V_5 -> V_187 = V_251 ;
if ( V_5 -> V_185 == 1 )
V_5 -> V_184 = F_90 ( V_5 -> V_187 , V_5 ) ;
V_5 -> V_227 = V_228 ;
return;
default:
V_5 -> V_227 = V_228 ;
}
}
static int F_118 ( T_4 V_252 , const struct V_253 * V_254 , int V_255 )
{
int F_64 = 0 ;
int V_256 ;
if ( V_252 < V_254 [ 0 ] . V_257 || V_252 > V_254 [ V_255 ] . V_258 )
return 0 ;
while ( V_255 >= F_64 ) {
V_256 = ( F_64 + V_255 ) / 2 ;
if ( V_252 > V_254 [ V_256 ] . V_258 )
F_64 = V_256 + 1 ;
else if ( V_252 < V_254 [ V_256 ] . V_257 )
V_255 = V_256 - 1 ;
else
return 1 ;
}
return 0 ;
}
static int F_119 ( T_4 V_252 )
{
static const struct V_253 V_259 [] = {
{ 0x1100 , 0x115F } , { 0x2329 , 0x232A } , { 0x2E80 , 0x303E } ,
{ 0x3040 , 0xA4CF } , { 0xAC00 , 0xD7A3 } , { 0xF900 , 0xFAFF } ,
{ 0xFE10 , 0xFE19 } , { 0xFE30 , 0xFE6F } , { 0xFF00 , 0xFF60 } ,
{ 0xFFE0 , 0xFFE6 } , { 0x20000 , 0x2FFFD } , { 0x30000 , 0x3FFFD }
} ;
return F_118 ( V_252 , V_259 , F_120 ( V_259 ) - 1 ) ;
}
static int F_121 ( struct V_137 * V_138 , const unsigned char * V_192 , int V_36 )
{
#ifdef F_18
#define F_122 do { } while(0);
#else
#define F_122 if (draw_x >= 0) { \
vc->vc_sw->con_putcs(vc, (u16 *)draw_from, (u16 *)draw_to - (u16 *)draw_from, vc->vc_y, draw_x); \
draw_x = -1; \
}
#endif
int V_9 , V_260 , V_261 , V_262 = 0 , V_263 = - 1 ;
unsigned int V_120 ;
unsigned long V_264 = 0 , V_265 = 0 ;
struct V_4 * V_5 ;
unsigned char V_58 ;
struct V_7 V_8 ;
T_5 V_266 ;
T_5 V_267 ;
T_5 V_132 ;
T_1 V_268 , V_269 ;
if ( F_123 () )
return V_36 ;
F_124 () ;
F_72 () ;
V_5 = V_138 -> V_168 ;
if ( V_5 == NULL ) {
F_125 ( V_270 L_5 ) ;
F_73 () ;
return 0 ;
}
V_120 = V_5 -> V_102 ;
if ( ! F_46 ( V_120 ) ) {
F_126 ( L_6 , V_120 + 1 ) ;
F_73 () ;
return 0 ;
}
V_268 = V_5 -> V_57 ;
V_269 = V_268 ? 0x1ff : 0xff ;
if ( F_36 ( V_5 ) )
F_23 ( V_5 ) ;
V_8 . V_5 = V_5 ;
while ( ! V_138 -> V_271 && V_36 ) {
int V_272 = * V_192 ;
V_9 = V_272 ;
V_192 ++ ;
V_262 ++ ;
V_36 -- ;
V_266 = 0 ;
V_267 = 0 ;
V_132 = 1 ;
if ( V_5 -> V_227 != V_228 ) {
V_260 = V_9 ;
} else if ( V_5 -> V_231 && ! V_5 -> V_188 ) {
V_273:
if ( ( V_9 & 0xc0 ) == 0x80 ) {
static const T_4 V_274 [] = { 0x0000007f , 0x000007ff , 0x0000ffff , 0x001fffff , 0x03ffffff , 0x7fffffff } ;
if ( V_5 -> V_233 ) {
V_5 -> V_275 = ( V_5 -> V_275 << 6 ) | ( V_9 & 0x3f ) ;
V_5 -> V_182 ++ ;
if ( -- V_5 -> V_233 ) {
continue;
}
V_9 = V_5 -> V_275 ;
if ( V_9 <= V_274 [ V_5 -> V_182 - 1 ] ||
V_9 > V_274 [ V_5 -> V_182 ] )
V_9 = 0xfffd ;
} else {
V_5 -> V_233 = 0 ;
V_9 = 0xfffd ;
}
} else {
if ( V_5 -> V_233 ) {
V_266 = 1 ;
V_5 -> V_233 = 0 ;
V_9 = 0xfffd ;
} else if ( V_9 > 0x7f ) {
V_5 -> V_182 = 0 ;
if ( ( V_9 & 0xe0 ) == 0xc0 ) {
V_5 -> V_233 = 1 ;
V_5 -> V_275 = ( V_9 & 0x1f ) ;
} else if ( ( V_9 & 0xf0 ) == 0xe0 ) {
V_5 -> V_233 = 2 ;
V_5 -> V_275 = ( V_9 & 0x0f ) ;
} else if ( ( V_9 & 0xf8 ) == 0xf0 ) {
V_5 -> V_233 = 3 ;
V_5 -> V_275 = ( V_9 & 0x07 ) ;
} else if ( ( V_9 & 0xfc ) == 0xf8 ) {
V_5 -> V_233 = 4 ;
V_5 -> V_275 = ( V_9 & 0x03 ) ;
} else if ( ( V_9 & 0xfe ) == 0xfc ) {
V_5 -> V_233 = 5 ;
V_5 -> V_275 = ( V_9 & 0x01 ) ;
} else {
V_9 = 0xfffd ;
}
if ( V_5 -> V_233 ) {
continue;
}
}
}
if ( ( V_9 >= 0xd800 && V_9 <= 0xdfff ) || V_9 == 0xfffe || V_9 == 0xffff )
V_9 = 0xfffd ;
V_260 = V_9 ;
} else {
V_260 = V_184 ( V_5 , V_9 ) ;
}
V_8 . V_9 = V_260 ;
if ( F_6 ( & V_3 , V_276 ,
& V_8 ) == V_277 )
continue;
V_261 = V_260 && ( V_9 >= 32 ||
! ( V_5 -> V_188 ? ( V_278 >> V_9 ) & 1 :
V_5 -> V_231 || ( ( V_279 >> V_9 ) & 1 ) ) )
&& ( V_9 != 127 || V_5 -> V_188 )
&& ( V_9 != 128 + 27 ) ;
if ( V_5 -> V_227 == V_228 && V_261 ) {
if ( V_5 -> V_231 && ! V_5 -> V_188 ) {
if ( F_119 ( V_9 ) )
V_132 = 2 ;
}
V_260 = F_127 ( V_5 , V_260 ) ;
if ( V_260 & ~ V_269 ) {
if ( V_260 == - 1 || V_260 == - 2 ) {
continue;
}
if ( ( ! ( V_5 -> V_231 && ! V_5 -> V_188 ) || V_9 < 128 ) && ! ( V_9 & ~ V_269 ) ) {
V_260 = V_9 ;
} else {
V_260 = F_127 ( V_5 , 0xfffd ) ;
if ( V_260 < 0 ) {
V_267 = 1 ;
V_260 = F_127 ( V_5 , '?' ) ;
if ( V_260 < 0 ) V_260 = '?' ;
}
}
}
if ( ! V_267 ) {
V_58 = V_5 -> V_58 ;
} else {
if ( ! V_5 -> V_54 ) {
V_58 = ( V_5 -> V_58 ) ^ 0x08 ;
} else if ( V_5 -> V_57 == 0x100 ) {
V_58 = ( ( V_5 -> V_58 ) & 0x11 ) | ( ( ( V_5 -> V_58 ) & 0xe0 ) >> 4 ) | ( ( ( V_5 -> V_58 ) & 0x0e ) << 4 ) ;
} else {
V_58 = ( ( V_5 -> V_58 ) & 0x88 ) | ( ( ( V_5 -> V_58 ) & 0x70 ) >> 4 ) | ( ( ( V_5 -> V_58 ) & 0x07 ) << 4 ) ;
}
F_122
}
while ( 1 ) {
if ( V_5 -> V_78 || V_5 -> V_204 )
F_122
if ( V_5 -> V_78 ) {
F_82 ( V_5 ) ;
F_80 ( V_5 ) ;
}
if ( V_5 -> V_204 )
F_30 ( V_5 , 1 ) ;
F_28 ( V_268 ?
( ( V_58 << 8 ) & ~ V_268 ) + ( ( V_260 & 0x100 ) ? V_268 : 0 ) + ( V_260 & 0xff ) :
( V_58 << 8 ) + V_260 ,
( T_1 * ) V_5 -> V_76 ) ;
if ( F_22 ( V_5 ) && V_263 < 0 ) {
V_263 = V_5 -> V_77 ;
V_264 = V_5 -> V_76 ;
}
if ( V_5 -> V_77 == V_5 -> V_31 - 1 ) {
V_5 -> V_78 = V_5 -> V_202 ;
V_265 = V_5 -> V_76 + 2 ;
} else {
V_5 -> V_77 ++ ;
V_265 = ( V_5 -> V_76 += 2 ) ;
}
if ( ! -- V_132 ) break;
V_260 = F_127 ( V_5 , ' ' ) ;
if ( V_260 < 0 ) V_260 = ' ' ;
}
F_5 ( V_5 , V_9 ) ;
if ( V_267 ) {
F_122
}
if ( V_266 ) {
V_266 = 0 ;
V_267 = 0 ;
V_132 = 1 ;
V_9 = V_272 ;
goto V_273;
}
continue;
}
F_122
F_112 ( V_138 , V_5 , V_272 ) ;
}
F_122
F_128 ();
F_73 () ;
F_7 ( V_5 ) ;
return V_262 ;
#undef F_122
}
static void F_129 ( struct V_280 * V_281 )
{
F_72 () ;
if ( V_282 >= 0 ) {
if ( V_282 != V_100 &&
F_46 ( V_282 ) ) {
F_23 ( V_99 [ V_100 ] . V_25 ) ;
F_130 ( V_99 [ V_282 ] . V_25 ) ;
}
V_282 = - 1 ;
}
if ( V_283 ) {
V_283 = 0 ;
F_103 () ;
}
if ( V_20 ) {
struct V_4 * V_5 = V_99 [ V_100 ] . V_25 ;
F_35 () ;
if ( V_5 -> V_87 == V_284 )
V_5 -> V_16 -> V_285 ( V_5 , V_20 ) ;
V_20 = 0 ;
}
if ( V_286 ) {
F_131 ( 0 ) ;
V_286 = 0 ;
}
F_7 ( V_99 [ V_100 ] . V_25 ) ;
F_73 () ;
}
int F_104 ( int V_24 )
{
struct V_4 * V_5 = V_99 [ V_100 ] . V_25 ;
if ( ! F_46 ( V_24 ) || V_287 ||
( V_5 -> V_288 . V_289 == V_290 && V_5 -> V_87 == V_88 ) ) {
return - V_156 ;
}
V_282 = V_24 ;
F_10 () ;
return 0 ;
}
int F_132 ( int V_74 )
{
static int V_291 ;
if ( V_74 != - 1 )
return F_133 ( & V_291 , V_74 ) ;
else
return V_291 ;
}
static void F_134 ( struct V_292 * V_293 , const char * V_23 , unsigned V_36 )
{
struct V_4 * V_5 = V_99 [ V_100 ] . V_25 ;
unsigned char V_9 ;
static F_135 ( V_294 ) ;
const T_6 * V_35 ;
T_6 V_67 = 0 ;
T_6 V_295 ;
int V_296 ;
if ( ! V_297 )
return;
if ( ! F_136 ( & V_294 ) )
return;
V_296 = F_137 () ;
if ( V_296 && F_46 ( V_296 - 1 ) )
V_5 = V_99 [ V_296 - 1 ] . V_25 ;
V_295 = V_5 -> V_77 ;
if ( ! F_46 ( V_100 ) ) {
goto V_298;
}
if ( V_5 -> V_87 != V_284 && ! F_43 ( V_5 ) )
goto V_298;
if ( F_36 ( V_5 ) )
F_23 ( V_5 ) ;
V_35 = ( T_6 * ) V_5 -> V_76 ;
while ( V_36 -- ) {
V_9 = * V_23 ++ ;
if ( V_9 == 10 || V_9 == 13 || V_9 == 8 || V_5 -> V_78 ) {
if ( V_67 > 0 ) {
if ( F_13 ( V_5 ) )
V_5 -> V_16 -> V_45 ( V_5 , V_35 , V_67 , V_5 -> V_82 , V_5 -> V_77 ) ;
V_5 -> V_77 += V_67 ;
if ( V_5 -> V_78 )
V_5 -> V_77 -- ;
V_67 = 0 ;
}
if ( V_9 == 8 ) {
F_83 ( V_5 ) ;
V_35 = ( T_6 * ) V_5 -> V_76 ;
V_295 = V_5 -> V_77 ;
continue;
}
if ( V_9 != 13 )
F_80 ( V_5 ) ;
F_82 ( V_5 ) ;
V_35 = ( T_6 * ) V_5 -> V_76 ;
V_295 = V_5 -> V_77 ;
if ( V_9 == 10 || V_9 == 13 )
continue;
}
F_28 ( ( V_5 -> V_58 << 8 ) + V_9 , ( unsigned short * ) V_5 -> V_76 ) ;
F_5 ( V_5 , V_9 ) ;
V_67 ++ ;
if ( V_295 == V_5 -> V_31 - 1 ) {
V_5 -> V_78 = 1 ;
continue;
}
V_5 -> V_76 += 2 ;
V_295 ++ ;
}
if ( V_67 > 0 ) {
if ( F_13 ( V_5 ) )
V_5 -> V_16 -> V_45 ( V_5 , V_35 , V_67 , V_5 -> V_82 , V_5 -> V_77 ) ;
V_5 -> V_77 += V_67 ;
if ( V_5 -> V_77 == V_5 -> V_31 ) {
V_5 -> V_77 -- ;
V_5 -> V_78 = 1 ;
}
}
F_24 ( V_5 ) ;
F_7 ( V_5 ) ;
V_298:
F_138 ( & V_294 ) ;
}
static struct V_299 * F_139 ( struct V_292 * V_9 , int * V_300 )
{
* V_300 = V_9 -> V_300 ? V_9 -> V_300 - 1 : V_100 ;
return V_301 ;
}
int F_140 ( struct V_137 * V_138 , unsigned long V_302 )
{
char type , V_303 ;
char T_7 * V_14 = ( char T_7 * ) V_302 ;
int V_19 ;
int V_169 ;
if ( V_304 -> signal -> V_138 != V_138 && ! F_52 ( V_305 ) )
return - V_124 ;
if ( F_141 ( type , V_14 ) )
return - V_306 ;
V_169 = 0 ;
switch ( type )
{
case V_307 :
F_72 () ;
V_169 = F_142 ( (struct V_308 T_7 * ) ( V_14 + 1 ) , V_138 ) ;
F_73 () ;
break;
case V_309 :
V_169 = F_143 ( V_138 ) ;
break;
case V_310 :
F_72 () ;
F_144 () ;
F_73 () ;
break;
case V_311 :
F_72 () ;
V_169 = F_145 ( V_14 ) ;
F_73 () ;
break;
case V_312 :
V_303 = F_146 () ;
V_169 = F_147 ( V_303 , V_14 ) ;
break;
case V_313 :
F_72 () ;
V_303 = F_98 () ;
F_73 () ;
V_169 = F_147 ( V_303 , V_14 ) ;
break;
case V_314 :
F_72 () ;
V_169 = F_148 ( V_14 ) ;
F_73 () ;
break;
case V_315 :
V_303 = F_137 () ;
V_169 = F_147 ( V_303 , V_14 ) ;
break;
case V_316 :
if ( ! F_52 ( V_305 ) ) {
V_169 = - V_124 ;
} else {
if ( F_141 ( V_303 , V_14 + 1 ) )
V_169 = - V_306 ;
else
F_132 ( V_303 ) ;
}
break;
case V_317 :
V_169 = V_100 ;
break;
case V_318 :
if ( F_141 ( V_19 , ( V_319 T_7 * ) ( V_14 + 4 ) ) ) {
V_169 = - V_306 ;
} else {
F_72 () ;
F_79 ( V_99 [ V_100 ] . V_25 , V_19 ) ;
F_73 () ;
V_169 = 0 ;
}
break;
case V_320 :
F_72 () ;
V_321 = 1 ;
F_131 ( 0 ) ;
F_73 () ;
break;
case V_322 :
V_169 = V_86 ;
break;
default:
V_169 = - V_156 ;
break;
}
return V_169 ;
}
static int F_149 ( struct V_137 * V_138 , const unsigned char * V_192 , int V_36 )
{
int V_323 ;
V_323 = F_121 ( V_138 , V_192 , V_36 ) ;
F_150 ( V_138 ) ;
return V_323 ;
}
static int F_151 ( struct V_137 * V_138 , unsigned char V_324 )
{
if ( F_123 () )
return 0 ;
return F_121 ( V_138 , & V_324 , 1 ) ;
}
static int F_152 ( struct V_137 * V_138 )
{
if ( V_138 -> V_271 )
return 0 ;
return 32768 ;
}
static int F_153 ( struct V_137 * V_138 )
{
return 0 ;
}
static void F_154 ( struct V_137 * V_138 )
{
}
static void F_155 ( struct V_137 * V_138 )
{
struct V_4 * V_5 = V_138 -> V_168 ;
F_156 ( & V_5 -> V_325 ) ;
}
static void F_157 ( struct V_137 * V_138 )
{
int V_326 ;
if ( ! V_138 )
return;
V_326 = V_138 -> V_300 ;
if ( ! F_46 ( V_326 ) )
return;
F_158 ( V_326 ) ;
}
static void F_159 ( struct V_137 * V_138 )
{
int V_326 ;
if ( ! V_138 )
return;
V_326 = V_138 -> V_300 ;
if ( ! F_46 ( V_326 ) )
return;
F_160 ( V_326 ) ;
}
static void F_150 ( struct V_137 * V_138 )
{
struct V_4 * V_5 ;
if ( F_123 () )
return;
F_72 () ;
V_5 = V_138 -> V_168 ;
if ( V_5 )
F_24 ( V_5 ) ;
F_73 () ;
}
static int F_161 ( struct V_299 * V_327 , struct V_137 * V_138 )
{
unsigned int V_120 = V_138 -> V_300 ;
struct V_4 * V_5 ;
int V_169 ;
F_72 () ;
V_169 = F_51 ( V_120 ) ;
if ( V_169 )
goto V_328;
V_5 = V_99 [ V_120 ] . V_25 ;
if ( V_5 -> V_127 . V_138 ) {
V_169 = - V_329 ;
goto V_328;
}
V_169 = F_162 ( & V_5 -> V_127 , V_327 , V_138 ) ;
if ( V_169 )
goto V_328;
V_138 -> V_168 = V_5 ;
V_5 -> V_127 . V_138 = V_138 ;
if ( ! V_138 -> V_160 . V_162 && ! V_138 -> V_160 . V_163 ) {
V_138 -> V_160 . V_162 = V_99 [ V_120 ] . V_25 -> V_27 ;
V_138 -> V_160 . V_163 = V_99 [ V_120 ] . V_25 -> V_31 ;
}
if ( V_5 -> V_231 )
V_138 -> V_330 . V_331 |= V_332 ;
else
V_138 -> V_330 . V_331 &= ~ V_332 ;
V_328:
F_73 () ;
return V_169 ;
}
static int F_163 ( struct V_137 * V_138 , struct V_333 * V_334 )
{
return 0 ;
}
static void F_164 ( struct V_137 * V_138 , struct V_333 * V_334 )
{
}
static void F_165 ( struct V_137 * V_138 )
{
struct V_4 * V_5 = V_138 -> V_168 ;
F_166 ( V_5 == NULL ) ;
F_72 () ;
V_5 -> V_127 . V_138 = NULL ;
F_73 () ;
}
static void F_60 ( struct V_4 * V_5 , unsigned int V_167 ,
unsigned int V_139 , int V_226 )
{
int V_246 , V_335 ;
V_5 -> V_31 = V_139 ;
V_5 -> V_27 = V_167 ;
V_5 -> V_30 = V_139 << 1 ;
V_5 -> V_72 = V_5 -> V_27 * V_5 -> V_30 ;
F_37 ( V_5 ) ;
V_5 -> V_76 = V_5 -> V_15 ;
F_167 ( V_5 ) ;
for ( V_246 = V_335 = 0 ; V_246 < 16 ; V_246 ++ ) {
V_5 -> V_247 [ V_335 ++ ] = V_336 [ V_246 ] ;
V_5 -> V_247 [ V_335 ++ ] = V_337 [ V_246 ] ;
V_5 -> V_247 [ V_335 ++ ] = V_338 [ V_246 ] ;
}
V_5 -> V_181 = 0x07 ;
V_5 -> V_56 = V_339 ;
V_5 -> V_55 = V_340 ;
V_5 -> V_206 = 0x08 ;
F_168 ( & V_5 -> V_325 ) ;
F_110 ( V_5 , V_226 ) ;
}
static int T_8 V_118 ( void )
{
const char * V_341 = NULL ;
struct V_4 * V_5 ;
unsigned int V_120 = 0 , V_79 ;
F_72 () ;
if ( V_112 )
V_341 = V_112 -> V_342 () ;
if ( ! V_341 ) {
V_100 = 0 ;
F_73 () ;
return 0 ;
}
for ( V_79 = 0 ; V_79 < V_343 ; V_79 ++ ) {
struct V_344 * V_344 = & V_345 [ V_79 ] ;
if ( V_344 -> V_346 == NULL ) {
V_344 -> V_346 = V_112 ;
V_344 -> V_347 = V_341 ;
V_344 -> V_348 = V_349 ;
V_344 -> V_257 = 0 ;
V_344 -> V_258 = V_108 - 1 ;
break;
}
}
for ( V_79 = 0 ; V_79 < V_108 ; V_79 ++ )
V_113 [ V_79 ] = V_112 ;
if ( V_207 ) {
V_350 = V_351 ;
F_169 ( & V_352 , V_353 + ( V_207 * V_211 ) ) ;
}
for ( V_120 = 0 ; V_120 < V_173 ; V_120 ++ ) {
V_99 [ V_120 ] . V_25 = V_5 = F_53 ( sizeof( struct V_4 ) , V_354 ) ;
F_55 ( & V_99 [ V_120 ] . V_128 , V_129 ) ;
F_54 ( & V_5 -> V_127 ) ;
F_47 ( V_5 , V_120 , 1 ) ;
V_5 -> V_92 = F_53 ( V_5 -> V_72 , V_354 ) ;
F_60 ( V_5 , V_5 -> V_27 , V_5 -> V_31 ,
V_120 || ! V_5 -> V_16 -> V_94 ) ;
}
V_120 = V_100 = 0 ;
V_114 = V_5 = V_99 [ V_120 ] . V_25 ;
F_37 ( V_5 ) ;
F_38 ( V_5 ) ;
F_65 ( V_5 , V_5 -> V_77 , V_5 -> V_82 ) ;
F_85 ( V_5 , 0 ) ;
F_68 ( V_5 ) ;
F_170 ( L_7 ,
V_5 -> V_54 ? L_8 : L_9 ,
V_341 , V_5 -> V_31 , V_5 -> V_27 ) ;
V_297 = 1 ;
F_73 () ;
#ifdef F_171
F_172 ( & V_355 ) ;
#endif
return 0 ;
}
static T_9 F_173 ( struct V_356 * V_357 ,
struct V_358 * V_359 , char * V_192 )
{
return sprintf ( V_192 , L_10 , V_100 + 1 ) ;
}
int T_8 F_174 ( const struct V_360 * V_361 )
{
F_175 ( & V_362 , V_361 ) ;
if ( F_176 ( & V_362 , F_177 ( V_363 , 0 ) , 1 ) ||
F_178 ( F_177 ( V_363 , 0 ) , 1 , L_11 ) < 0 )
F_179 ( L_12 ) ;
V_103 = F_180 ( V_364 , NULL , F_177 ( V_363 , 0 ) , NULL , L_13 ) ;
if ( F_181 ( V_103 ) )
V_103 = NULL ;
else
F_182 ( F_183 ( V_103 , & V_365 ) < 0 ) ;
F_184 () ;
V_301 = F_185 ( V_108 ) ;
if ( ! V_301 )
F_179 ( L_14 ) ;
V_301 -> V_366 = L_15 ;
V_301 -> V_367 = 1 ;
V_301 -> V_368 = V_363 ;
V_301 -> V_369 = 1 ;
V_301 -> type = V_370 ;
V_301 -> V_371 = V_372 ;
if ( V_232 )
V_301 -> V_371 . V_331 |= V_332 ;
V_301 -> V_373 = V_374 | V_375 ;
F_186 ( V_301 , & V_376 ) ;
if ( F_187 ( V_301 ) )
F_179 ( L_16 ) ;
F_188 () ;
F_189 () ;
#ifdef F_190
F_191 () ;
#endif
return 0 ;
}
static int F_192 ( const struct V_377 * V_378 , int V_257 , int V_258 ,
int V_379 )
{
struct V_380 * V_111 = V_378 -> V_111 ;
const char * V_347 = NULL ;
struct V_344 * V_344 ;
int V_79 , V_246 = - 1 , V_335 = - 1 , V_323 = - V_381 ;
if ( ! F_193 ( V_111 ) )
return - V_381 ;
F_72 () ;
for ( V_79 = 0 ; V_79 < V_343 ; V_79 ++ ) {
V_344 = & V_345 [ V_79 ] ;
if ( V_344 -> V_346 == V_378 ) {
V_347 = V_344 -> V_347 ;
V_323 = 0 ;
break;
}
}
if ( V_323 )
goto V_135;
if ( ! ( V_344 -> V_348 & V_349 ) ) {
V_378 -> V_342 () ;
V_344 -> V_348 |= V_349 ;
}
if ( V_379 ) {
if ( V_112 )
F_48 ( V_112 -> V_111 ) ;
F_50 ( V_111 ) ;
V_112 = V_378 ;
}
V_257 = V_255 ( V_257 , V_344 -> V_257 ) ;
V_258 = F_64 ( V_258 , V_344 -> V_258 ) ;
for ( V_79 = V_257 ; V_79 <= V_258 ; V_79 ++ ) {
int V_106 ;
struct V_4 * V_5 = V_99 [ V_79 ] . V_25 ;
if ( V_113 [ V_79 ] )
F_48 ( V_113 [ V_79 ] -> V_111 ) ;
F_50 ( V_111 ) ;
V_113 [ V_79 ] = V_378 ;
if ( ! V_5 || ! V_5 -> V_16 )
continue;
V_246 = V_79 ;
if ( F_13 ( V_5 ) ) {
V_335 = V_79 ;
F_38 ( V_5 ) ;
}
V_106 = V_5 -> V_54 ;
V_5 -> V_16 -> V_171 ( V_5 ) ;
V_5 -> V_15 = ( unsigned long ) V_5 -> V_92 ;
F_47 ( V_5 , V_79 , 0 ) ;
F_37 ( V_5 ) ;
F_26 ( V_5 ) ;
if ( V_106 != V_5 -> V_54 )
F_39 ( V_5 ) ;
}
F_170 ( L_17 ) ;
if ( ! V_379 )
F_125 ( L_18 , V_257 + 1 , V_258 + 1 ) ;
if ( V_246 >= 0 ) {
struct V_4 * V_5 = V_99 [ V_246 ] . V_25 ;
F_125 ( L_19 ,
V_5 -> V_54 ? L_8 : L_9 ,
V_347 , V_5 -> V_31 , V_5 -> V_27 ) ;
if ( V_335 >= 0 ) {
V_5 = V_99 [ V_335 ] . V_25 ;
F_68 ( V_5 ) ;
}
} else
F_125 ( L_20 , V_347 ) ;
V_323 = 0 ;
V_135:
F_73 () ;
F_48 ( V_111 ) ;
return V_323 ;
}
static int F_194 ( const struct V_377 * V_378 , int V_257 , int V_258 )
{
int V_79 , V_323 = 0 ;
for ( V_79 = V_257 ; V_79 <= V_258 ; V_79 ++ ) {
struct V_4 * V_5 = V_99 [ V_79 ] . V_25 ;
if ( V_5 && V_5 -> V_87 == V_88 ) {
V_323 = 1 ;
break;
}
}
return V_323 ;
}
int F_195 ( const struct V_377 * V_378 , int V_257 , int V_258 , int V_379 )
{
struct V_380 * V_111 = V_378 -> V_111 ;
const struct V_377 * V_382 = NULL ;
struct V_344 * V_344 = NULL , * V_383 = NULL ;
int V_79 , V_323 = - V_381 ;
if ( ! F_193 ( V_111 ) )
return - V_381 ;
F_72 () ;
for ( V_79 = 0 ; V_79 < V_343 ; V_79 ++ ) {
V_344 = & V_345 [ V_79 ] ;
if ( V_344 -> V_346 == V_378 &&
V_344 -> V_348 & V_384 ) {
V_323 = 0 ;
break;
}
}
if ( V_323 ) {
F_73 () ;
goto V_135;
}
V_323 = - V_381 ;
for ( V_79 = 0 ; V_79 < V_343 ; V_79 ++ ) {
V_383 = & V_345 [ V_79 ] ;
if ( V_383 -> V_346 &&
! ( V_383 -> V_348 & V_384 ) ) {
V_382 = V_383 -> V_346 ;
V_323 = 0 ;
break;
}
}
if ( V_323 ) {
F_73 () ;
goto V_135;
}
if ( ! F_196 ( V_378 ) ) {
F_73 () ;
goto V_135;
}
V_257 = V_255 ( V_257 , V_344 -> V_257 ) ;
V_258 = F_64 ( V_258 , V_344 -> V_258 ) ;
for ( V_79 = V_257 ; V_79 <= V_258 ; V_79 ++ ) {
if ( V_113 [ V_79 ] == V_378 ) {
F_48 ( V_378 -> V_111 ) ;
V_113 [ V_79 ] = NULL ;
}
}
if ( ! F_196 ( V_382 ) ) {
const struct V_377 * V_385 = V_112 ;
V_382 -> V_342 () ;
V_383 -> V_348 |= V_349 ;
V_112 = V_385 ;
}
if ( ! F_196 ( V_378 ) )
V_344 -> V_348 &= ~ V_349 ;
F_73 () ;
F_192 ( V_382 , V_257 , V_258 , V_379 ) ;
V_135:
F_48 ( V_111 ) ;
return V_323 ;
}
static int F_197 ( struct V_344 * V_346 )
{
const struct V_377 * V_382 = NULL , * V_378 = NULL ;
int V_79 , V_386 = 1 , V_257 = - 1 , V_258 = - 1 , V_379 = 0 ;
if ( ! V_346 -> V_346 || ! ( V_346 -> V_348 & V_384 ) ||
F_194 ( V_346 -> V_346 , V_346 -> V_257 , V_346 -> V_258 ) )
goto V_135;
V_378 = V_346 -> V_346 ;
for ( V_79 = 0 ; V_79 < V_343 ; V_79 ++ ) {
struct V_344 * V_346 = & V_345 [ V_79 ] ;
if ( V_346 -> V_346 && ! ( V_346 -> V_348 & V_384 ) ) {
V_382 = V_346 -> V_346 ;
break;
}
}
if ( ! V_382 )
goto V_135;
while ( V_386 ) {
V_386 = 0 ;
for ( V_79 = V_346 -> V_257 ; V_79 <= V_346 -> V_258 ; V_79 ++ ) {
if ( V_113 [ V_79 ] == V_382 ) {
if ( V_257 == - 1 )
V_257 = V_79 ;
V_258 = V_79 ;
V_386 = 1 ;
} else if ( V_257 != - 1 )
break;
}
if ( V_257 == 0 && V_258 == V_108 - 1 )
V_379 = 1 ;
if ( V_257 != - 1 )
F_192 ( V_378 , V_257 , V_258 , V_379 ) ;
V_257 = - 1 ;
V_258 = - 1 ;
V_379 = 0 ;
}
V_135:
return 0 ;
}
static int F_198 ( struct V_344 * V_346 )
{
const struct V_377 * V_378 = NULL ;
int V_79 , V_386 = 1 , V_257 = - 1 , V_258 = - 1 , V_379 = 0 ;
if ( ! V_346 -> V_346 || ! ( V_346 -> V_348 & V_384 ) ||
F_194 ( V_346 -> V_346 , V_346 -> V_257 , V_346 -> V_258 ) )
goto V_135;
V_378 = V_346 -> V_346 ;
while ( V_386 ) {
V_386 = 0 ;
for ( V_79 = V_346 -> V_257 ; V_79 <= V_346 -> V_258 ; V_79 ++ ) {
if ( V_113 [ V_79 ] == V_378 ) {
if ( V_257 == - 1 )
V_257 = V_79 ;
V_258 = V_79 ;
V_386 = 1 ;
} else if ( V_257 != - 1 )
break;
}
if ( V_257 == 0 && V_258 == V_108 - 1 )
V_379 = 1 ;
if ( V_257 != - 1 )
F_195 ( V_378 , V_257 , V_258 , V_379 ) ;
V_257 = - 1 ;
V_258 = - 1 ;
V_379 = 0 ;
}
V_135:
return 0 ;
}
static inline int F_197 ( struct V_344 * V_346 )
{
return 0 ;
}
static inline int F_198 ( struct V_344 * V_346 )
{
return 0 ;
}
static T_9 F_199 ( struct V_356 * V_357 , struct V_358 * V_359 ,
const char * V_192 , T_10 V_36 )
{
struct V_344 * V_346 = F_200 ( V_357 ) ;
int V_387 = F_201 ( V_192 , NULL , 0 ) ;
if ( V_387 )
F_197 ( V_346 ) ;
else
F_198 ( V_346 ) ;
return V_36 ;
}
static T_9 F_202 ( struct V_356 * V_357 , struct V_358 * V_359 ,
char * V_192 )
{
struct V_344 * V_346 = F_200 ( V_357 ) ;
int V_387 = F_196 ( V_346 -> V_346 ) ;
return snprintf ( V_192 , V_388 , L_21 , V_387 ) ;
}
static T_9 F_203 ( struct V_356 * V_357 , struct V_358 * V_359 ,
char * V_192 )
{
struct V_344 * V_346 = F_200 ( V_357 ) ;
return snprintf ( V_192 , V_388 , L_22 ,
( V_346 -> V_348 & V_384 ) ? L_23 : L_24 ,
V_346 -> V_347 ) ;
}
static int F_204 ( struct V_344 * V_346 )
{
int V_79 ;
int error = 0 ;
V_346 -> V_348 |= V_389 ;
F_205 ( V_346 -> V_357 , V_346 ) ;
for ( V_79 = 0 ; V_79 < F_120 ( V_390 ) ; V_79 ++ ) {
error = F_183 ( V_346 -> V_357 , & V_390 [ V_79 ] ) ;
if ( error )
break;
}
if ( error ) {
while ( -- V_79 >= 0 )
F_206 ( V_346 -> V_357 , & V_390 [ V_79 ] ) ;
V_346 -> V_348 &= ~ V_389 ;
}
return error ;
}
static void F_207 ( struct V_344 * V_346 )
{
int V_79 ;
if ( V_346 -> V_348 & V_389 ) {
for ( V_79 = 0 ; V_79 < F_120 ( V_390 ) ; V_79 ++ )
F_206 ( V_346 -> V_357 , & V_390 [ V_79 ] ) ;
V_346 -> V_348 &= ~ V_389 ;
}
}
int F_196 ( const struct V_377 * V_378 )
{
int V_79 , V_391 = 0 ;
for ( V_79 = 0 ; V_79 < V_108 ; V_79 ++ ) {
if ( V_113 [ V_79 ] == V_378 ) {
V_391 = 1 ;
break;
}
}
return V_391 ;
}
int F_208 ( struct V_4 * V_5 )
{
int V_169 = 0 ;
V_392 = V_100 ;
V_393 = V_214 ;
V_394 = V_282 ;
V_395 = V_5 -> V_87 ;
V_396 = V_86 ;
V_5 -> V_87 = V_284 ;
V_86 = 0 ;
if ( V_5 -> V_16 -> F_208 )
V_169 = V_5 -> V_16 -> F_208 ( V_5 ) ;
#ifdef F_209
if ( V_5 -> V_27 < 999 ) {
int V_397 ;
char V_398 [ 4 ] ;
const char * V_399 [ 3 ] = {
L_25 ,
L_26 ,
V_398 ,
} ;
if ( F_210 ( V_399 [ 0 ] , & V_397 ) ) {
snprintf ( V_398 , 4 , L_27 , V_5 -> V_27 ) ;
F_211 ( 2 , V_399 ) ;
}
}
if ( V_5 -> V_31 < 999 ) {
int V_400 ;
char V_139 [ 4 ] ;
const char * V_399 [ 3 ] = {
L_25 ,
L_28 ,
V_139 ,
} ;
if ( F_210 ( V_399 [ 0 ] , & V_400 ) ) {
snprintf ( V_139 , 4 , L_27 , V_5 -> V_31 ) ;
F_211 ( 2 , V_399 ) ;
}
}
#endif
return V_169 ;
}
int F_212 ( void )
{
struct V_4 * V_5 ;
int V_169 = 0 ;
V_100 = V_392 ;
V_214 = V_393 ;
V_282 = V_394 ;
V_86 = V_396 ;
V_99 [ V_100 ] . V_25 -> V_87 = V_395 ;
V_5 = V_99 [ V_100 ] . V_25 ;
if ( V_5 -> V_16 -> F_212 )
V_169 = V_5 -> V_16 -> F_212 ( V_5 ) ;
return V_169 ;
}
int F_213 ( const struct V_377 * V_378 , int V_257 , int V_258 )
{
struct V_380 * V_111 = V_378 -> V_111 ;
struct V_344 * V_344 ;
const char * V_347 ;
int V_79 , V_323 = 0 ;
if ( ! F_193 ( V_111 ) )
return - V_381 ;
F_72 () ;
for ( V_79 = 0 ; V_79 < V_343 ; V_79 ++ ) {
V_344 = & V_345 [ V_79 ] ;
if ( V_344 -> V_346 == V_378 )
V_323 = - V_401 ;
}
if ( V_323 )
goto V_135;
V_347 = V_378 -> V_342 () ;
if ( ! V_347 )
goto V_135;
V_323 = - V_156 ;
for ( V_79 = 0 ; V_79 < V_343 ; V_79 ++ ) {
V_344 = & V_345 [ V_79 ] ;
if ( V_344 -> V_346 == NULL ) {
V_344 -> V_346 = V_378 ;
V_344 -> V_347 = V_347 ;
V_344 -> V_402 = V_79 ;
V_344 -> V_348 = V_384 |
V_349 ;
V_344 -> V_257 = V_257 ;
V_344 -> V_258 = V_258 ;
V_323 = 0 ;
break;
}
}
if ( V_323 )
goto V_135;
V_344 -> V_357 = F_180 ( V_403 , NULL ,
F_177 ( 0 , V_344 -> V_402 ) ,
NULL , L_29 ,
V_344 -> V_402 ) ;
if ( F_181 ( V_344 -> V_357 ) ) {
F_125 ( V_404 L_30
L_31 , V_344 -> V_347 ,
F_214 ( V_344 -> V_357 ) ) ;
V_344 -> V_357 = NULL ;
} else {
F_204 ( V_344 ) ;
}
V_135:
F_73 () ;
F_48 ( V_111 ) ;
return V_323 ;
}
int F_215 ( const struct V_377 * V_378 )
{
int V_79 , V_323 = - V_381 ;
F_72 () ;
if ( F_196 ( V_378 ) )
goto V_135;
for ( V_79 = 0 ; V_79 < V_343 ; V_79 ++ ) {
struct V_344 * V_344 = & V_345 [ V_79 ] ;
if ( V_344 -> V_346 == V_378 &&
V_344 -> V_348 & V_384 ) {
F_207 ( V_344 ) ;
F_216 ( V_403 ,
F_177 ( 0 , V_344 -> V_402 ) ) ;
V_344 -> V_346 = NULL ;
V_344 -> V_347 = NULL ;
V_344 -> V_357 = NULL ;
V_344 -> V_402 = 0 ;
V_344 -> V_348 = 0 ;
V_344 -> V_257 = 0 ;
V_344 -> V_258 = 0 ;
V_323 = 0 ;
break;
}
}
V_135:
F_73 () ;
return V_323 ;
}
int F_217 ( const struct V_377 * V_378 , int V_257 , int V_258 , int V_379 )
{
int V_135 ;
V_135 = F_213 ( V_378 , V_257 , V_258 ) ;
if ( V_135 == - V_401 )
V_135 = 0 ;
if ( ! V_135 )
F_192 ( V_378 , V_257 , V_258 , V_379 ) ;
return V_135 ;
}
void F_218 ( const struct V_377 * V_378 )
{
F_215 ( V_378 ) ;
}
static int T_8 F_219 ( void )
{
int V_79 ;
V_403 = F_220 ( V_405 , L_32 ) ;
if ( F_181 ( V_403 ) ) {
F_125 ( V_404 L_33
L_31 , F_214 ( V_403 ) ) ;
V_403 = NULL ;
}
for ( V_79 = 0 ; V_79 < V_343 ; V_79 ++ ) {
struct V_344 * V_346 = & V_345 [ V_79 ] ;
if ( V_346 -> V_346 && ! V_346 -> V_357 ) {
V_346 -> V_357 = F_180 ( V_403 , NULL ,
F_177 ( 0 , V_346 -> V_402 ) ,
NULL , L_29 ,
V_346 -> V_402 ) ;
if ( F_181 ( V_346 -> V_357 ) ) {
F_125 ( V_404 L_34
L_35 ,
V_346 -> V_347 , F_214 ( V_346 -> V_357 ) ) ;
V_346 -> V_357 = NULL ;
} else {
F_204 ( V_346 ) ;
}
}
}
return 0 ;
}
static int F_148 ( char T_7 * V_14 )
{
unsigned int V_289 ;
if ( F_141 ( V_289 , V_14 + 1 ) )
return - V_306 ;
V_406 = ( V_289 < 4 ) ? V_289 : 0 ;
return 0 ;
}
void F_131 ( int V_407 )
{
struct V_4 * V_5 = V_99 [ V_100 ] . V_25 ;
int V_79 ;
F_21 () ;
if ( V_86 ) {
if ( V_350 == V_408 ) {
V_350 = V_409 ;
V_5 -> V_16 -> V_410 ( V_5 , V_406 + 1 , 0 ) ;
}
return;
}
if ( V_407 ) {
F_23 ( V_5 ) ;
F_38 ( V_5 ) ;
V_5 -> V_16 -> V_410 ( V_5 , - 1 , 1 ) ;
V_86 = V_100 + 1 ;
V_350 = V_409 ;
F_37 ( V_5 ) ;
return;
}
if ( V_350 != V_351 )
return;
V_350 = V_409 ;
if ( V_5 -> V_87 != V_284 ) {
V_86 = V_100 + 1 ;
return;
}
F_23 ( V_5 ) ;
F_221 ( & V_352 ) ;
V_286 = 0 ;
F_38 ( V_5 ) ;
V_79 = V_5 -> V_16 -> V_410 ( V_5 , V_213 ? 1 : ( V_406 + 1 ) , 0 ) ;
V_86 = V_100 + 1 ;
if ( V_79 )
F_37 ( V_5 ) ;
if ( V_411 && V_411 ( 1 ) )
return;
if ( V_213 && V_406 ) {
V_350 = V_408 ;
F_169 ( & V_352 , V_353 + V_213 ) ;
}
F_69 ( V_412 , V_5 -> V_102 , V_5 -> V_102 ) ;
}
void F_222 ( int V_413 )
{
struct V_4 * V_5 ;
if ( ! V_414 )
F_124 () ;
F_21 () ;
V_321 = 0 ;
if ( ! V_86 )
return;
if ( ! F_46 ( V_100 ) ) {
F_223 ( L_36 ,
V_100 + 1 ) ;
return;
}
V_5 = V_99 [ V_100 ] . V_25 ;
if ( V_5 -> V_87 != V_284 && ! F_43 ( V_5 ) )
return;
if ( V_207 ) {
F_169 ( & V_352 , V_353 + ( V_207 * V_211 ) ) ;
V_350 = V_351 ;
}
V_86 = 0 ;
if ( V_5 -> V_16 -> V_410 ( V_5 , 0 , V_413 ) || F_43 ( V_5 ) )
F_68 ( V_5 ) ;
if ( V_411 )
V_411 ( 0 ) ;
F_42 ( V_5 ) ;
F_24 ( V_5 ) ;
F_69 ( V_415 , V_5 -> V_102 , V_5 -> V_102 ) ;
}
void F_144 ( void )
{
F_222 ( 0 ) ;
}
static void F_224 ( unsigned long V_416 )
{
if ( F_225 ( ! F_226 () ) ) {
F_169 ( & V_352 , V_353 + ( V_207 * V_211 ) ) ;
return;
}
V_286 = 1 ;
F_11 ( & V_21 ) ;
}
void F_103 ( void )
{
F_21 () ;
F_124 () ;
F_227 ( & V_352 ) ;
V_286 = 0 ;
if ( V_321 || ! V_99 [ V_100 ] . V_25 || V_99 [ V_100 ] . V_25 -> V_87 == V_88 )
return;
if ( V_86 )
F_144 () ;
else if ( V_207 ) {
F_169 ( & V_352 , V_353 + ( V_207 * V_211 ) ) ;
V_350 = V_351 ;
}
}
static void F_42 ( struct V_4 * V_5 )
{
F_21 () ;
if ( V_5 -> V_87 != V_88 )
V_5 -> V_16 -> V_417 ( V_5 , V_191 ) ;
}
int F_228 ( unsigned char T_7 * V_302 )
{
int V_79 , V_246 , V_335 ;
unsigned char V_418 [ 3 * 16 ] ;
if ( F_229 ( V_418 , V_302 , sizeof( V_418 ) ) )
return - V_306 ;
F_72 () ;
for ( V_79 = V_335 = 0 ; V_79 < 16 ; V_79 ++ ) {
V_336 [ V_79 ] = V_418 [ V_335 ++ ] ;
V_337 [ V_79 ] = V_418 [ V_335 ++ ] ;
V_338 [ V_79 ] = V_418 [ V_335 ++ ] ;
}
for ( V_79 = 0 ; V_79 < V_108 ; V_79 ++ ) {
if ( ! F_46 ( V_79 ) )
continue;
for ( V_246 = V_335 = 0 ; V_246 < 16 ; V_246 ++ ) {
V_99 [ V_79 ] . V_25 -> V_247 [ V_335 ++ ] = V_336 [ V_246 ] ;
V_99 [ V_79 ] . V_25 -> V_247 [ V_335 ++ ] = V_337 [ V_246 ] ;
V_99 [ V_79 ] . V_25 -> V_247 [ V_335 ++ ] = V_338 [ V_246 ] ;
}
F_42 ( V_99 [ V_79 ] . V_25 ) ;
}
F_73 () ;
return 0 ;
}
int F_230 ( unsigned char T_7 * V_302 )
{
int V_79 , V_335 ;
unsigned char V_418 [ 3 * 16 ] ;
F_72 () ;
for ( V_79 = V_335 = 0 ; V_79 < 16 ; V_79 ++ ) {
V_418 [ V_335 ++ ] = V_336 [ V_79 ] ;
V_418 [ V_335 ++ ] = V_337 [ V_79 ] ;
V_418 [ V_335 ++ ] = V_338 [ V_79 ] ;
}
F_73 () ;
if ( F_231 ( V_302 , V_418 , sizeof( V_418 ) ) )
return - V_306 ;
return 0 ;
}
void F_115 ( struct V_4 * V_5 )
{
int V_246 , V_335 ;
for ( V_246 = V_335 = 0 ; V_246 < 16 ; V_246 ++ ) {
V_5 -> V_247 [ V_335 ++ ] = V_336 [ V_246 ] ;
V_5 -> V_247 [ V_335 ++ ] = V_337 [ V_246 ] ;
V_5 -> V_247 [ V_335 ++ ] = V_338 [ V_246 ] ;
}
F_42 ( V_5 ) ;
}
static int F_232 ( struct V_4 * V_5 , struct V_419 * V_420 )
{
struct V_421 V_422 ;
int V_423 = - V_156 ;
int V_9 ;
if ( V_420 -> V_303 ) {
V_422 . V_303 = F_57 ( V_424 , V_125 ) ;
if ( ! V_422 . V_303 )
return - V_126 ;
} else
V_422 . V_303 = NULL ;
F_72 () ;
if ( V_5 -> V_87 != V_284 )
V_423 = - V_156 ;
else if ( V_5 -> V_16 -> F_232 )
V_423 = V_5 -> V_16 -> F_232 ( V_5 , & V_422 ) ;
else
V_423 = - V_425 ;
F_73 () ;
if ( V_423 )
goto V_426;
V_9 = ( V_422 . V_132 + 7 ) / 8 * 32 * V_422 . V_427 ;
if ( V_420 -> V_303 && V_422 . V_427 > V_420 -> V_427 )
V_423 = - V_428 ;
if ( ! ( V_420 -> V_373 & V_429 ) ) {
if ( V_422 . V_132 > V_420 -> V_132 || V_422 . V_133 > V_420 -> V_133 )
V_423 = - V_428 ;
} else {
if ( V_422 . V_132 != 8 )
V_423 = - V_430 ;
else if ( ( V_420 -> V_133 && V_422 . V_133 > V_420 -> V_133 ) ||
V_422 . V_133 > 32 )
V_423 = - V_428 ;
}
if ( V_423 )
goto V_426;
V_420 -> V_133 = V_422 . V_133 ;
V_420 -> V_132 = V_422 . V_132 ;
V_420 -> V_427 = V_422 . V_427 ;
if ( V_420 -> V_303 && F_231 ( V_420 -> V_303 , V_422 . V_303 , V_9 ) )
V_423 = - V_306 ;
V_426:
F_59 ( V_422 . V_303 ) ;
return V_423 ;
}
static int F_233 ( struct V_4 * V_5 , struct V_419 * V_420 )
{
struct V_421 V_422 ;
int V_423 = - V_156 ;
int V_431 ;
if ( V_5 -> V_87 != V_284 )
return - V_156 ;
if ( ! V_420 -> V_303 )
return - V_156 ;
if ( V_420 -> V_427 > 512 )
return - V_156 ;
if ( ! V_420 -> V_133 ) {
int V_432 , V_79 ;
T_2 T_7 * V_433 = V_420 -> V_303 ;
T_2 V_434 ;
if ( ! ( V_420 -> V_373 & V_429 ) )
return - V_156 ;
for ( V_432 = 32 ; V_432 > 0 ; V_432 -- )
for ( V_79 = 0 ; V_79 < V_420 -> V_427 ; V_79 ++ ) {
if ( F_141 ( V_434 , & V_433 [ 32 * V_79 + V_432 - 1 ] ) )
return - V_306 ;
if ( V_434 )
goto V_435;
}
return - V_156 ;
V_435:
V_420 -> V_133 = V_432 ;
}
if ( V_420 -> V_132 <= 0 || V_420 -> V_132 > 32 || V_420 -> V_133 > 32 )
return - V_156 ;
V_431 = ( V_420 -> V_132 + 7 ) / 8 * 32 * V_420 -> V_427 ;
if ( V_431 > V_424 )
return - V_428 ;
V_422 . V_427 = V_420 -> V_427 ;
V_422 . V_133 = V_420 -> V_133 ;
V_422 . V_132 = V_420 -> V_132 ;
V_422 . V_303 = F_234 ( V_420 -> V_303 , V_431 ) ;
if ( F_181 ( V_422 . V_303 ) )
return F_214 ( V_422 . V_303 ) ;
F_72 () ;
if ( V_5 -> V_87 != V_284 )
V_423 = - V_156 ;
else if ( V_5 -> V_16 -> F_233 )
V_423 = V_5 -> V_16 -> F_233 ( V_5 , & V_422 , V_420 -> V_373 ) ;
else
V_423 = - V_425 ;
F_73 () ;
F_59 ( V_422 . V_303 ) ;
return V_423 ;
}
static int F_235 ( struct V_4 * V_5 , struct V_419 * V_420 )
{
struct V_421 V_422 = { . V_132 = V_420 -> V_132 , . V_133 = V_420 -> V_133 } ;
char V_366 [ V_436 ] ;
char * V_26 = V_366 ;
int V_423 ;
if ( ! V_420 -> V_303 )
V_26 = NULL ;
else if ( F_236 ( V_366 , V_420 -> V_303 , V_436 - 1 ) < 0 )
return - V_306 ;
else
V_366 [ V_436 - 1 ] = 0 ;
F_72 () ;
if ( V_5 -> V_87 != V_284 ) {
F_73 () ;
return - V_156 ;
}
if ( V_5 -> V_16 -> F_235 )
V_423 = V_5 -> V_16 -> F_235 ( V_5 , & V_422 , V_26 ) ;
else
V_423 = - V_425 ;
F_73 () ;
if ( ! V_423 ) {
V_420 -> V_132 = V_422 . V_132 ;
V_420 -> V_133 = V_422 . V_133 ;
}
return V_423 ;
}
static int F_237 ( struct V_4 * V_5 , struct V_419 * V_420 )
{
int V_346 = V_420 -> V_133 ;
int V_423 ;
F_72 () ;
if ( V_5 -> V_87 != V_284 )
V_423 = - V_156 ;
else if ( ! V_5 -> V_16 -> F_237 )
V_423 = - V_425 ;
else if ( V_346 < 0 || ! F_46 ( V_346 ) )
V_423 = - V_437 ;
else if ( V_346 == V_5 -> V_102 )
V_423 = 0 ;
else
V_423 = V_5 -> V_16 -> F_237 ( V_5 , V_346 ) ;
F_73 () ;
return V_423 ;
}
int F_238 ( struct V_4 * V_5 , struct V_419 * V_420 )
{
switch ( V_420 -> V_420 ) {
case V_438 :
return F_233 ( V_5 , V_420 ) ;
case V_439 :
return F_232 ( V_5 , V_420 ) ;
case V_440 :
return F_235 ( V_5 , V_420 ) ;
case V_441 :
return F_237 ( V_5 , V_420 ) ;
}
return - V_425 ;
}
T_1 F_239 ( struct V_4 * V_5 , int V_12 )
{
T_1 V_442 = F_19 ( F_8 ( V_5 , V_12 , 1 ) ) ;
T_1 V_9 = V_442 & 0xff ;
if ( V_442 & V_5 -> V_57 )
V_9 |= 0x100 ;
return V_9 ;
}
unsigned short * F_240 ( struct V_4 * V_5 , int V_443 , int V_13 )
{
return F_8 ( V_5 , 2 * V_443 , V_13 ) ;
}
void F_241 ( struct V_4 * V_5 , unsigned char * V_14 )
{
V_14 [ 0 ] = V_5 -> V_77 ;
V_14 [ 1 ] = V_5 -> V_82 ;
}
void F_242 ( struct V_4 * V_5 , unsigned char * V_14 )
{
F_23 ( V_5 ) ;
F_65 ( V_5 , V_14 [ 0 ] , V_14 [ 1 ] ) ;
F_24 ( V_5 ) ;
}
T_1 F_243 ( struct V_4 * V_5 , const T_1 * V_444 )
{
if ( ( unsigned long ) V_444 == V_5 -> V_76 && V_81 != - 1 )
return V_81 ;
return F_19 ( V_444 ) ;
}
void F_244 ( struct V_4 * V_5 , T_1 V_445 , T_1 * V_444 )
{
F_28 ( V_445 , V_444 ) ;
if ( ( unsigned long ) V_444 == V_5 -> V_76 ) {
V_81 = - 1 ;
F_33 ( V_5 ) ;
}
}
void F_245 ( struct V_4 * V_5 )
{
F_7 ( V_5 ) ;
}
