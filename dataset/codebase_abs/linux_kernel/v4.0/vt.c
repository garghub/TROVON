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
F_7 ( V_5 ) ;
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
F_7 ( V_5 ) ;
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
F_7 ( V_5 ) ;
}
}
static void F_30 ( struct V_4 * V_5 , unsigned int V_24 )
{
unsigned short * V_14 = ( unsigned short * ) V_5 -> V_76 ;
F_14 ( V_14 + V_24 , V_14 , ( V_5 -> V_31 - V_5 -> V_77 - V_24 ) * 2 ) ;
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
void F_39 ( struct V_4 * V_5 )
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
V_5 -> V_116 = NULL ;
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
F_58 ( V_5 ) ;
V_99 [ V_120 ] . V_25 = NULL ;
return - V_126 ;
}
if ( V_130 == - 1 )
V_130 = 1 ;
F_59 ( V_5 , V_5 -> V_27 , V_5 -> V_31 , 1 ) ;
F_60 ( V_120 ) ;
F_6 ( & V_3 , V_131 , & V_8 ) ;
}
return 0 ;
}
static inline int F_61 ( struct V_4 * V_5 , int V_132 , int V_133 ,
int V_134 )
{
int V_135 = 0 ;
if ( V_5 -> V_87 != V_88 && V_5 -> V_16 -> V_136 )
V_135 = V_5 -> V_16 -> V_136 ( V_5 , V_132 , V_133 , V_134 ) ;
return V_135 ;
}
static int F_62 ( struct V_137 * V_138 , struct V_4 * V_5 ,
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
V_135 = F_61 ( V_5 , V_148 , V_149 , V_134 ) ;
if ( V_135 ) {
F_58 ( V_152 ) ;
return V_135 ;
}
V_5 -> V_27 = V_149 ;
V_5 -> V_31 = V_148 ;
V_5 -> V_30 = V_150 ;
V_5 -> V_72 = V_151 ;
V_143 = F_63 ( V_147 , V_150 ) ;
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
V_145 = V_140 + V_147 * F_63 ( V_146 , V_149 ) ;
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
F_58 ( V_5 -> V_92 ) ;
V_5 -> V_92 = V_152 ;
V_5 -> V_72 = V_151 ;
F_37 ( V_5 ) ;
V_5 -> V_158 = 0 ;
V_5 -> V_159 = V_5 -> V_27 ;
F_64 ( V_5 , V_5 -> V_77 , V_5 -> V_82 ) ;
F_65 ( V_5 ) ;
if ( V_138 ) {
struct V_160 V_161 ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_161 . V_162 = V_5 -> V_27 ;
V_161 . V_163 = V_5 -> V_31 ;
V_161 . V_164 = V_5 -> V_165 ;
F_66 ( V_138 , & V_161 ) ;
}
if ( F_13 ( V_5 ) )
F_67 ( V_5 ) ;
F_68 ( V_166 , V_5 -> V_102 , V_5 -> V_102 ) ;
return V_135 ;
}
int F_69 ( struct V_4 * V_5 , unsigned int V_139 , unsigned int V_167 )
{
return F_62 ( V_5 -> V_127 . V_138 , V_5 , V_139 , V_167 ) ;
}
static int F_70 ( struct V_137 * V_138 , struct V_160 * V_161 )
{
struct V_4 * V_5 = V_138 -> V_168 ;
int V_169 ;
F_71 () ;
V_169 = F_62 ( V_138 , V_5 , V_161 -> V_163 , V_161 -> V_162 ) ;
F_72 () ;
return V_169 ;
}
struct V_4 * F_73 ( unsigned int V_120 )
{
struct V_4 * V_5 = NULL ;
F_21 () ;
if ( F_46 ( V_120 ) ) {
struct V_7 V_8 ;
V_8 . V_5 = V_5 = V_99 [ V_120 ] . V_25 ;
F_6 ( & V_3 , V_170 , & V_8 ) ;
F_74 ( V_120 ) ;
V_5 -> V_16 -> V_171 ( V_5 ) ;
F_75 ( V_5 -> V_172 ) ;
F_48 ( V_5 -> V_16 -> V_111 ) ;
F_58 ( V_5 -> V_92 ) ;
V_99 [ V_120 ] . V_25 = NULL ;
}
return V_5 ;
}
static void F_64 ( struct V_4 * V_5 , int V_173 , int V_174 )
{
int V_175 , V_176 ;
if ( V_173 < 0 )
V_5 -> V_77 = 0 ;
else {
if ( V_173 >= V_5 -> V_31 )
V_5 -> V_77 = V_5 -> V_31 - 1 ;
else
V_5 -> V_77 = V_173 ;
}
if ( V_5 -> V_177 ) {
V_175 = V_5 -> V_158 ;
V_176 = V_5 -> V_159 ;
} else {
V_175 = 0 ;
V_176 = V_5 -> V_27 ;
}
if ( V_174 < V_175 )
V_5 -> V_82 = V_175 ;
else if ( V_174 >= V_176 )
V_5 -> V_82 = V_176 - 1 ;
else
V_5 -> V_82 = V_174 ;
V_5 -> V_76 = V_5 -> V_15 + V_5 -> V_82 * V_5 -> V_30 + ( V_5 -> V_77 << 1 ) ;
V_5 -> V_78 = 0 ;
}
static void F_76 ( struct V_4 * V_5 , int V_173 , int V_174 )
{
F_64 ( V_5 , V_173 , V_5 -> V_177 ? ( V_5 -> V_158 + V_174 ) : V_174 ) ;
}
void F_77 ( struct V_4 * V_5 , int V_19 )
{
if ( ! V_19 )
V_19 = V_5 -> V_27 / 2 ;
F_9 ( - V_19 ) ;
}
void F_78 ( struct V_4 * V_5 , int V_19 )
{
if ( ! V_19 )
V_19 = V_5 -> V_27 / 2 ;
F_9 ( V_19 ) ;
}
static void F_79 ( struct V_4 * V_5 )
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
static void F_80 ( struct V_4 * V_5 )
{
if ( V_5 -> V_82 == V_5 -> V_158 )
F_16 ( V_5 , V_5 -> V_158 , V_5 -> V_159 , 1 ) ;
else if ( V_5 -> V_82 > 0 ) {
V_5 -> V_82 -- ;
V_5 -> V_76 -= V_5 -> V_30 ;
}
V_5 -> V_78 = 0 ;
}
static inline void F_81 ( struct V_4 * V_5 )
{
V_5 -> V_76 -= V_5 -> V_77 << 1 ;
V_5 -> V_78 = V_5 -> V_77 = 0 ;
F_5 ( V_5 , '\r' ) ;
}
static inline void F_82 ( struct V_4 * V_5 )
{
if ( V_5 -> V_77 ) {
V_5 -> V_76 -= 2 ;
V_5 -> V_77 -- ;
V_5 -> V_78 = 0 ;
F_5 ( V_5 , '\b' ) ;
}
}
static inline void F_83 ( struct V_4 * V_5 )
{
}
static void F_84 ( struct V_4 * V_5 , int V_178 )
{
unsigned int V_36 ;
unsigned short * V_35 ;
switch ( V_178 ) {
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
if ( F_13 ( V_5 ) )
F_67 ( V_5 ) ;
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
static void F_85 ( struct V_4 * V_5 , int V_178 )
{
unsigned int V_36 ;
unsigned short * V_35 ;
switch ( V_178 ) {
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
static void F_86 ( struct V_4 * V_5 , int V_178 )
{
int V_36 ;
if ( ! V_178 )
V_178 ++ ;
V_36 = ( V_178 > V_5 -> V_31 - V_5 -> V_77 ) ? ( V_5 -> V_31 - V_5 -> V_77 ) : V_178 ;
F_15 ( ( unsigned short * ) V_5 -> V_76 , V_5 -> V_32 , 2 * V_36 ) ;
if ( F_22 ( V_5 ) )
V_5 -> V_16 -> V_179 ( V_5 , V_5 -> V_82 , V_5 -> V_77 , 1 , V_36 ) ;
V_5 -> V_78 = 0 ;
}
static void F_87 ( struct V_4 * V_5 )
{
V_5 -> V_60 = 1 ;
V_5 -> V_65 = 0 ;
V_5 -> V_62 = 0 ;
V_5 -> V_63 = 0 ;
V_5 -> V_61 = 0 ;
V_5 -> V_59 = V_5 -> V_180 ;
}
struct V_181 F_88 ( int V_79 )
{
struct V_181 V_9 ;
if ( V_79 < 8 ) {
V_9 . V_182 = V_79 & 1 ? 0xaa : 0x00 ;
V_9 . V_183 = V_79 & 2 ? 0xaa : 0x00 ;
V_9 . V_23 = V_79 & 4 ? 0xaa : 0x00 ;
} else if ( V_79 < 16 ) {
V_9 . V_182 = V_79 & 1 ? 0xff : 0x55 ;
V_9 . V_183 = V_79 & 2 ? 0xff : 0x55 ;
V_9 . V_23 = V_79 & 4 ? 0xff : 0x55 ;
} else if ( V_79 < 232 ) {
V_9 . V_182 = ( V_79 - 16 ) / 36 * 85 / 2 ;
V_9 . V_183 = ( V_79 - 16 ) / 6 % 6 * 85 / 2 ;
V_9 . V_23 = ( V_79 - 16 ) % 6 * 85 / 2 ;
} else
V_9 . V_182 = V_9 . V_183 = V_9 . V_23 = V_79 * 10 - 2312 ;
return V_9 ;
}
static void F_89 ( struct V_4 * V_5 , struct V_181 V_9 )
{
T_2 V_184 , V_185 = V_9 . V_182 ;
if ( V_9 . V_183 > V_185 )
V_185 = V_9 . V_183 ;
if ( V_9 . V_23 > V_185 )
V_185 = V_9 . V_23 ;
V_184 = ( V_9 . V_182 > V_185 / 2 ? 4 : 0 )
| ( V_9 . V_183 > V_185 / 2 ? 2 : 0 )
| ( V_9 . V_23 > V_185 / 2 ? 1 : 0 ) ;
if ( V_184 == 7 && V_185 <= 0x55 )
V_184 = 0 , V_5 -> V_60 = 2 ;
else
V_5 -> V_60 = ( V_185 > 0xaa ) + 1 ;
V_5 -> V_59 = ( V_5 -> V_59 & 0xf0 ) | V_184 ;
}
static void F_90 ( struct V_4 * V_5 , struct V_181 V_9 )
{
V_5 -> V_59 = ( V_5 -> V_59 & 0x0f )
| ( V_9 . V_182 & 0x80 ) >> 1 | ( V_9 . V_183 & 0x80 ) >> 2 | ( V_9 . V_23 & 0x80 ) >> 3 ;
}
static void F_91 ( struct V_4 * V_5 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 <= V_5 -> V_186 ; V_79 ++ )
switch ( V_5 -> V_187 [ V_79 ] ) {
case 0 :
F_87 ( V_5 ) ;
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
V_5 -> V_188 = F_92 ( V_5 -> V_189 == 0
? V_5 -> V_190
: V_5 -> V_191 , V_5 ) ;
V_5 -> V_192 = 0 ;
V_5 -> V_193 = 0 ;
break;
case 11 :
V_5 -> V_188 = F_92 ( V_194 , V_5 ) ;
V_5 -> V_192 = 1 ;
V_5 -> V_193 = 0 ;
break;
case 12 :
V_5 -> V_188 = F_92 ( V_194 , V_5 ) ;
V_5 -> V_192 = 1 ;
V_5 -> V_193 = 1 ;
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
V_79 ++ ;
if ( V_79 > V_5 -> V_186 )
break;
if ( V_5 -> V_187 [ V_79 ] == 5 &&
V_79 < V_5 -> V_186 ) {
V_79 ++ ;
F_89 ( V_5 ,
F_88 ( V_5 -> V_187 [ V_79 ] ) ) ;
} else if ( V_5 -> V_187 [ V_79 ] == 2 &&
V_79 <= V_5 -> V_186 + 3 ) {
struct V_181 V_9 = {
. V_182 = V_5 -> V_187 [ V_79 + 1 ] ,
. V_183 = V_5 -> V_187 [ V_79 + 2 ] ,
. V_23 = V_5 -> V_187 [ V_79 + 3 ] ,
} ;
F_89 ( V_5 , V_9 ) ;
V_79 += 3 ;
}
break;
case 48 :
V_79 ++ ;
if ( V_79 > V_5 -> V_186 )
break;
if ( V_5 -> V_187 [ V_79 ] == 5 &&
V_79 < V_5 -> V_186 ) {
V_79 ++ ;
F_90 ( V_5 ,
F_88 ( V_5 -> V_187 [ V_79 ] ) ) ;
} else if ( V_5 -> V_187 [ V_79 ] == 2 &&
V_79 <= V_5 -> V_186 + 3 ) {
struct V_181 V_9 = {
. V_182 = V_5 -> V_187 [ V_79 + 1 ] ,
. V_183 = V_5 -> V_187 [ V_79 + 2 ] ,
. V_23 = V_5 -> V_187 [ V_79 + 3 ] ,
} ;
F_90 ( V_5 , V_9 ) ;
V_79 += 3 ;
}
break;
case 39 :
V_5 -> V_59 = ( V_5 -> V_180 & 0x0f ) | ( V_5 -> V_59 & 0xf0 ) ;
break;
case 49 :
V_5 -> V_59 = ( V_5 -> V_180 & 0xf0 ) | ( V_5 -> V_59 & 0x0f ) ;
break;
default:
if ( V_5 -> V_187 [ V_79 ] >= 30 && V_5 -> V_187 [ V_79 ] <= 37 )
V_5 -> V_59 = V_195 [ V_5 -> V_187 [ V_79 ] - 30 ]
| ( V_5 -> V_59 & 0xf0 ) ;
else if ( V_5 -> V_187 [ V_79 ] >= 40 && V_5 -> V_187 [ V_79 ] <= 47 )
V_5 -> V_59 = ( V_195 [ V_5 -> V_187 [ V_79 ] - 40 ] << 4 )
| ( V_5 -> V_59 & 0x0f ) ;
break;
}
F_26 ( V_5 ) ;
}
static void F_93 ( const char * V_14 , struct V_196 * V_127 )
{
while ( * V_14 ) {
F_94 ( V_127 , * V_14 , 0 ) ;
V_14 ++ ;
}
F_95 ( V_127 ) ;
}
static void F_96 ( struct V_4 * V_5 , struct V_137 * V_138 )
{
char V_197 [ 40 ] ;
sprintf ( V_197 , L_2 , V_5 -> V_82 + ( V_5 -> V_177 ? V_5 -> V_158 + 1 : 1 ) , V_5 -> V_77 + 1 ) ;
F_93 ( V_197 , V_138 -> V_127 ) ;
}
static inline void F_97 ( struct V_137 * V_138 )
{
F_93 ( L_3 , V_138 -> V_127 ) ;
}
static inline void F_98 ( struct V_137 * V_138 )
{
F_93 ( V_198 , V_138 -> V_127 ) ;
}
void F_99 ( struct V_137 * V_138 , int V_199 , int V_200 , int V_201 )
{
char V_197 [ 8 ] ;
sprintf ( V_197 , L_4 , ( char ) ( ' ' + V_199 ) , ( char ) ( '!' + V_200 ) ,
( char ) ( '!' + V_201 ) ) ;
F_93 ( V_197 , V_138 -> V_127 ) ;
}
int F_100 ( void )
{
return V_99 [ V_100 ] . V_25 -> V_202 ;
}
static void F_101 ( struct V_4 * V_5 , int V_203 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 <= V_5 -> V_186 ; V_79 ++ )
if ( V_5 -> V_204 ) {
switch( V_5 -> V_187 [ V_79 ] ) {
case 1 :
if ( V_203 )
F_102 ( V_5 , V_205 ) ;
else
F_103 ( V_5 , V_205 ) ;
break;
case 3 :
V_5 -> V_206 = V_203 ;
#if 0
vc_resize(deccolm ? 132 : 80, vc->vc_rows);
#endif
break;
case 5 :
if ( V_5 -> V_64 != V_203 ) {
V_5 -> V_64 = V_203 ;
F_27 ( V_5 , 0 , V_5 -> V_72 , 0 ) ;
F_26 ( V_5 ) ;
}
break;
case 6 :
V_5 -> V_177 = V_203 ;
F_76 ( V_5 , 0 , 0 ) ;
break;
case 7 :
V_5 -> V_207 = V_203 ;
break;
case 8 :
if ( V_203 )
F_102 ( V_5 , V_208 ) ;
else
F_103 ( V_5 , V_208 ) ;
break;
case 9 :
V_5 -> V_202 = V_203 ? 1 : 0 ;
break;
case 25 :
V_5 -> V_89 = V_203 ;
break;
case 1000 :
V_5 -> V_202 = V_203 ? 2 : 0 ;
break;
}
} else {
switch( V_5 -> V_187 [ V_79 ] ) {
case 3 :
V_5 -> V_192 = V_203 ;
break;
case 4 :
V_5 -> V_209 = V_203 ;
break;
case 20 :
if ( V_203 )
F_102 ( V_5 , V_210 ) ;
else
F_103 ( V_5 , V_210 ) ;
break;
}
}
}
static void F_104 ( struct V_4 * V_5 )
{
switch( V_5 -> V_187 [ 0 ] ) {
case 1 :
if ( V_5 -> V_54 &&
V_5 -> V_187 [ 1 ] < 16 ) {
V_5 -> V_56 = V_195 [ V_5 -> V_187 [ 1 ] ] ;
if ( V_5 -> V_62 )
F_26 ( V_5 ) ;
}
break;
case 2 :
if ( V_5 -> V_54 &&
V_5 -> V_187 [ 1 ] < 16 ) {
V_5 -> V_211 = V_195 [ V_5 -> V_187 [ 1 ] ] ;
if ( V_5 -> V_60 == 0 )
F_26 ( V_5 ) ;
}
break;
case 8 :
V_5 -> V_180 = V_5 -> V_58 ;
if ( V_5 -> V_57 == 0x100 )
V_5 -> V_180 >>= 1 ;
F_87 ( V_5 ) ;
F_26 ( V_5 ) ;
break;
case 9 :
V_212 = ( ( V_5 -> V_187 [ 1 ] < 60 ) ? V_5 -> V_187 [ 1 ] : 60 ) * 60 ;
F_105 () ;
break;
case 10 :
if ( V_5 -> V_186 >= 1 )
V_5 -> V_213 = V_5 -> V_187 [ 1 ] ;
else
V_5 -> V_213 = V_214 ;
break;
case 11 :
if ( V_5 -> V_186 >= 1 )
V_5 -> V_215 = ( V_5 -> V_187 [ 1 ] < 2000 ) ?
V_5 -> V_187 [ 1 ] * V_216 / 1000 : 0 ;
else
V_5 -> V_215 = V_217 ;
break;
case 12 :
if ( V_5 -> V_187 [ 1 ] >= 1 && F_46 ( V_5 -> V_187 [ 1 ] - 1 ) )
F_106 ( V_5 -> V_187 [ 1 ] - 1 ) ;
break;
case 13 :
F_105 () ;
break;
case 14 :
V_218 = ( ( V_5 -> V_187 [ 1 ] < 60 ) ? V_5 -> V_187 [ 1 ] : 60 ) * 60 * V_216 ;
break;
case 15 :
F_106 ( V_219 ) ;
break;
}
}
static void F_107 ( struct V_4 * V_5 , unsigned int V_24 )
{
if ( V_24 > V_5 -> V_31 - V_5 -> V_77 )
V_24 = V_5 -> V_31 - V_5 -> V_77 ;
else if ( ! V_24 )
V_24 = 1 ;
F_30 ( V_5 , V_24 ) ;
}
static void F_108 ( struct V_4 * V_5 , unsigned int V_24 )
{
if ( V_24 > V_5 -> V_27 - V_5 -> V_82 )
V_24 = V_5 -> V_27 - V_5 -> V_82 ;
else if ( ! V_24 )
V_24 = 1 ;
F_16 ( V_5 , V_5 -> V_82 , V_5 -> V_159 , V_24 ) ;
V_5 -> V_78 = 0 ;
}
static void F_109 ( struct V_4 * V_5 , unsigned int V_24 )
{
if ( V_24 > V_5 -> V_31 - V_5 -> V_77 )
V_24 = V_5 -> V_31 - V_5 -> V_77 ;
else if ( ! V_24 )
V_24 = 1 ;
F_31 ( V_5 , V_24 ) ;
}
static void F_110 ( struct V_4 * V_5 , unsigned int V_24 )
{
if ( V_24 > V_5 -> V_27 - V_5 -> V_82 )
V_24 = V_5 -> V_27 - V_5 -> V_82 ;
else if ( ! V_24 )
V_24 = 1 ;
F_12 ( V_5 , V_5 -> V_82 , V_5 -> V_159 , V_24 ) ;
V_5 -> V_78 = 0 ;
}
static void F_65 ( struct V_4 * V_5 )
{
V_5 -> V_220 = V_5 -> V_77 ;
V_5 -> V_221 = V_5 -> V_82 ;
V_5 -> V_222 = V_5 -> V_60 ;
V_5 -> V_223 = V_5 -> V_65 ;
V_5 -> V_224 = V_5 -> V_62 ;
V_5 -> V_225 = V_5 -> V_61 ;
V_5 -> V_226 = V_5 -> V_63 ;
V_5 -> V_227 = V_5 -> V_189 ;
V_5 -> V_228 = V_5 -> V_59 ;
V_5 -> V_229 = V_5 -> V_190 ;
V_5 -> V_230 = V_5 -> V_191 ;
}
static void F_111 ( struct V_4 * V_5 )
{
F_64 ( V_5 , V_5 -> V_220 , V_5 -> V_221 ) ;
V_5 -> V_60 = V_5 -> V_222 ;
V_5 -> V_65 = V_5 -> V_223 ;
V_5 -> V_62 = V_5 -> V_224 ;
V_5 -> V_61 = V_5 -> V_225 ;
V_5 -> V_63 = V_5 -> V_226 ;
V_5 -> V_189 = V_5 -> V_227 ;
V_5 -> V_59 = V_5 -> V_228 ;
V_5 -> V_190 = V_5 -> V_229 ;
V_5 -> V_191 = V_5 -> V_230 ;
V_5 -> V_188 = F_92 ( V_5 -> V_189 ? V_5 -> V_191 : V_5 -> V_190 , V_5 ) ;
F_26 ( V_5 ) ;
V_5 -> V_78 = 0 ;
}
static void F_112 ( struct V_4 * V_5 , int V_231 )
{
V_5 -> V_158 = 0 ;
V_5 -> V_159 = V_5 -> V_27 ;
V_5 -> V_232 = V_233 ;
V_5 -> V_204 = 0 ;
V_5 -> V_188 = F_92 ( V_234 , V_5 ) ;
V_5 -> V_190 = V_234 ;
V_5 -> V_191 = V_235 ;
V_5 -> V_189 = 0 ;
V_5 -> V_78 = 0 ;
V_5 -> V_202 = 0 ;
V_5 -> V_236 = V_237 ;
V_5 -> V_238 = 0 ;
V_5 -> V_192 = 0 ;
V_5 -> V_193 = 0 ;
V_5 -> V_64 = 0 ;
V_5 -> V_177 = 0 ;
V_5 -> V_207 = 1 ;
V_5 -> V_89 = V_130 ;
V_5 -> V_209 = 0 ;
F_113 ( V_5 -> V_102 ) ;
V_5 -> V_80 = V_239 ;
V_5 -> V_75 = V_5 -> V_119 ;
F_87 ( V_5 ) ;
F_26 ( V_5 ) ;
V_5 -> V_240 [ 0 ] = 0x01010100 ;
V_5 -> V_240 [ 1 ] =
V_5 -> V_240 [ 2 ] =
V_5 -> V_240 [ 3 ] =
V_5 -> V_240 [ 4 ] =
V_5 -> V_240 [ 5 ] =
V_5 -> V_240 [ 6 ] =
V_5 -> V_240 [ 7 ] = 0x01010101 ;
V_5 -> V_213 = V_214 ;
V_5 -> V_215 = V_217 ;
F_64 ( V_5 , 0 , 0 ) ;
F_65 ( V_5 ) ;
if ( V_231 )
F_84 ( V_5 , 2 ) ;
}
static void F_114 ( struct V_137 * V_138 , struct V_4 * V_5 , int V_9 )
{
if ( V_5 -> V_232 == V_241 && V_9 >= 8 && V_9 <= 13 )
return;
switch ( V_9 ) {
case 0 :
return;
case 7 :
if ( V_5 -> V_232 == V_241 )
V_5 -> V_232 = V_233 ;
else if ( V_5 -> V_215 )
F_115 ( V_5 -> V_213 , V_5 -> V_215 ) ;
return;
case 8 :
F_82 ( V_5 ) ;
return;
case 9 :
V_5 -> V_76 -= ( V_5 -> V_77 << 1 ) ;
while ( V_5 -> V_77 < V_5 -> V_31 - 1 ) {
V_5 -> V_77 ++ ;
if ( V_5 -> V_240 [ V_5 -> V_77 >> 5 ] & ( 1 << ( V_5 -> V_77 & 31 ) ) )
break;
}
V_5 -> V_76 += ( V_5 -> V_77 << 1 ) ;
F_5 ( V_5 , '\t' ) ;
return;
case 10 : case 11 : case 12 :
F_79 ( V_5 ) ;
if ( ! F_116 ( V_5 , V_210 ) )
return;
case 13 :
F_81 ( V_5 ) ;
return;
case 14 :
V_5 -> V_189 = 1 ;
V_5 -> V_188 = F_92 ( V_5 -> V_191 , V_5 ) ;
V_5 -> V_192 = 1 ;
return;
case 15 :
V_5 -> V_189 = 0 ;
V_5 -> V_188 = F_92 ( V_5 -> V_190 , V_5 ) ;
V_5 -> V_192 = 0 ;
return;
case 24 : case 26 :
V_5 -> V_232 = V_233 ;
return;
case 27 :
V_5 -> V_232 = V_242 ;
return;
case 127 :
F_83 ( V_5 ) ;
return;
case 128 + 27 :
V_5 -> V_232 = V_243 ;
return;
}
switch( V_5 -> V_232 ) {
case V_242 :
V_5 -> V_232 = V_233 ;
switch ( V_9 ) {
case '[' :
V_5 -> V_232 = V_243 ;
return;
case ']' :
V_5 -> V_232 = V_244 ;
return;
case '%' :
V_5 -> V_232 = V_245 ;
return;
case 'E' :
F_81 ( V_5 ) ;
F_79 ( V_5 ) ;
return;
case 'M' :
F_80 ( V_5 ) ;
return;
case 'D' :
F_79 ( V_5 ) ;
return;
case 'H' :
V_5 -> V_240 [ V_5 -> V_77 >> 5 ] |= ( 1 << ( V_5 -> V_77 & 31 ) ) ;
return;
case 'Z' :
F_98 ( V_138 ) ;
return;
case '7' :
F_65 ( V_5 ) ;
return;
case '8' :
F_111 ( V_5 ) ;
return;
case '(' :
V_5 -> V_232 = V_246 ;
return;
case ')' :
V_5 -> V_232 = V_247 ;
return;
case '#' :
V_5 -> V_232 = V_248 ;
return;
case 'c' :
F_112 ( V_5 , 1 ) ;
return;
case '>' :
F_103 ( V_5 , V_249 ) ;
return;
case '=' :
F_102 ( V_5 , V_249 ) ;
return;
}
return;
case V_244 :
if ( V_9 == 'P' ) {
for ( V_5 -> V_186 = 0 ; V_5 -> V_186 < V_250 ; V_5 -> V_186 ++ )
V_5 -> V_187 [ V_5 -> V_186 ] = 0 ;
V_5 -> V_186 = 0 ;
V_5 -> V_232 = V_251 ;
return;
} else if ( V_9 == 'R' ) {
F_117 ( V_5 ) ;
V_5 -> V_232 = V_233 ;
} else if ( V_9 >= '0' && V_9 <= '9' )
V_5 -> V_232 = V_241 ;
else
V_5 -> V_232 = V_233 ;
return;
case V_251 :
if ( isxdigit ( V_9 ) ) {
V_5 -> V_187 [ V_5 -> V_186 ++ ] = F_118 ( V_9 ) ;
if ( V_5 -> V_186 == 7 ) {
int V_79 = V_5 -> V_187 [ 0 ] * 3 , V_252 = 1 ;
V_5 -> V_253 [ V_79 ] = 16 * V_5 -> V_187 [ V_252 ++ ] ;
V_5 -> V_253 [ V_79 ++ ] += V_5 -> V_187 [ V_252 ++ ] ;
V_5 -> V_253 [ V_79 ] = 16 * V_5 -> V_187 [ V_252 ++ ] ;
V_5 -> V_253 [ V_79 ++ ] += V_5 -> V_187 [ V_252 ++ ] ;
V_5 -> V_253 [ V_79 ] = 16 * V_5 -> V_187 [ V_252 ++ ] ;
V_5 -> V_253 [ V_79 ] += V_5 -> V_187 [ V_252 ] ;
F_42 ( V_5 ) ;
V_5 -> V_232 = V_233 ;
}
} else
V_5 -> V_232 = V_233 ;
return;
case V_243 :
for ( V_5 -> V_186 = 0 ; V_5 -> V_186 < V_250 ; V_5 -> V_186 ++ )
V_5 -> V_187 [ V_5 -> V_186 ] = 0 ;
V_5 -> V_186 = 0 ;
V_5 -> V_232 = V_254 ;
if ( V_9 == '[' ) {
V_5 -> V_232 = V_255 ;
return;
}
V_5 -> V_204 = ( V_9 == '?' ) ;
if ( V_5 -> V_204 )
return;
case V_254 :
if ( V_9 == ';' && V_5 -> V_186 < V_250 - 1 ) {
V_5 -> V_186 ++ ;
return;
} else if ( V_9 >= '0' && V_9 <= '9' ) {
V_5 -> V_187 [ V_5 -> V_186 ] *= 10 ;
V_5 -> V_187 [ V_5 -> V_186 ] += V_9 - '0' ;
return;
}
V_5 -> V_232 = V_233 ;
switch( V_9 ) {
case 'h' :
F_101 ( V_5 , 1 ) ;
return;
case 'l' :
F_101 ( V_5 , 0 ) ;
return;
case 'c' :
if ( V_5 -> V_204 ) {
if ( V_5 -> V_187 [ 0 ] )
V_5 -> V_80 = V_5 -> V_187 [ 0 ] | ( V_5 -> V_187 [ 1 ] << 8 ) | ( V_5 -> V_187 [ 2 ] << 16 ) ;
else
V_5 -> V_80 = V_239 ;
return;
}
break;
case 'm' :
if ( V_5 -> V_204 ) {
F_35 () ;
if ( V_5 -> V_187 [ 0 ] )
V_5 -> V_75 = V_5 -> V_187 [ 0 ] << 8 | V_5 -> V_187 [ 1 ] ;
else
V_5 -> V_75 = V_5 -> V_119 ;
return;
}
break;
case 'n' :
if ( ! V_5 -> V_204 ) {
if ( V_5 -> V_187 [ 0 ] == 5 )
F_97 ( V_138 ) ;
else if ( V_5 -> V_187 [ 0 ] == 6 )
F_96 ( V_5 , V_138 ) ;
}
return;
}
if ( V_5 -> V_204 ) {
V_5 -> V_204 = 0 ;
return;
}
switch( V_9 ) {
case 'G' : case '`' :
if ( V_5 -> V_187 [ 0 ] )
V_5 -> V_187 [ 0 ] -- ;
F_64 ( V_5 , V_5 -> V_187 [ 0 ] , V_5 -> V_82 ) ;
return;
case 'A' :
if ( ! V_5 -> V_187 [ 0 ] )
V_5 -> V_187 [ 0 ] ++ ;
F_64 ( V_5 , V_5 -> V_77 , V_5 -> V_82 - V_5 -> V_187 [ 0 ] ) ;
return;
case 'B' : case 'e' :
if ( ! V_5 -> V_187 [ 0 ] )
V_5 -> V_187 [ 0 ] ++ ;
F_64 ( V_5 , V_5 -> V_77 , V_5 -> V_82 + V_5 -> V_187 [ 0 ] ) ;
return;
case 'C' : case 'a' :
if ( ! V_5 -> V_187 [ 0 ] )
V_5 -> V_187 [ 0 ] ++ ;
F_64 ( V_5 , V_5 -> V_77 + V_5 -> V_187 [ 0 ] , V_5 -> V_82 ) ;
return;
case 'D' :
if ( ! V_5 -> V_187 [ 0 ] )
V_5 -> V_187 [ 0 ] ++ ;
F_64 ( V_5 , V_5 -> V_77 - V_5 -> V_187 [ 0 ] , V_5 -> V_82 ) ;
return;
case 'E' :
if ( ! V_5 -> V_187 [ 0 ] )
V_5 -> V_187 [ 0 ] ++ ;
F_64 ( V_5 , 0 , V_5 -> V_82 + V_5 -> V_187 [ 0 ] ) ;
return;
case 'F' :
if ( ! V_5 -> V_187 [ 0 ] )
V_5 -> V_187 [ 0 ] ++ ;
F_64 ( V_5 , 0 , V_5 -> V_82 - V_5 -> V_187 [ 0 ] ) ;
return;
case 'd' :
if ( V_5 -> V_187 [ 0 ] )
V_5 -> V_187 [ 0 ] -- ;
F_76 ( V_5 , V_5 -> V_77 , V_5 -> V_187 [ 0 ] ) ;
return;
case 'H' : case 'f' :
if ( V_5 -> V_187 [ 0 ] )
V_5 -> V_187 [ 0 ] -- ;
if ( V_5 -> V_187 [ 1 ] )
V_5 -> V_187 [ 1 ] -- ;
F_76 ( V_5 , V_5 -> V_187 [ 1 ] , V_5 -> V_187 [ 0 ] ) ;
return;
case 'J' :
F_84 ( V_5 , V_5 -> V_187 [ 0 ] ) ;
return;
case 'K' :
F_85 ( V_5 , V_5 -> V_187 [ 0 ] ) ;
return;
case 'L' :
F_108 ( V_5 , V_5 -> V_187 [ 0 ] ) ;
return;
case 'M' :
F_110 ( V_5 , V_5 -> V_187 [ 0 ] ) ;
return;
case 'P' :
F_109 ( V_5 , V_5 -> V_187 [ 0 ] ) ;
return;
case 'c' :
if ( ! V_5 -> V_187 [ 0 ] )
F_98 ( V_138 ) ;
return;
case 'g' :
if ( ! V_5 -> V_187 [ 0 ] )
V_5 -> V_240 [ V_5 -> V_77 >> 5 ] &= ~ ( 1 << ( V_5 -> V_77 & 31 ) ) ;
else if ( V_5 -> V_187 [ 0 ] == 3 ) {
V_5 -> V_240 [ 0 ] =
V_5 -> V_240 [ 1 ] =
V_5 -> V_240 [ 2 ] =
V_5 -> V_240 [ 3 ] =
V_5 -> V_240 [ 4 ] =
V_5 -> V_240 [ 5 ] =
V_5 -> V_240 [ 6 ] =
V_5 -> V_240 [ 7 ] = 0 ;
}
return;
case 'm' :
F_91 ( V_5 ) ;
return;
case 'q' :
if ( V_5 -> V_187 [ 0 ] < 4 )
F_119 ( V_5 -> V_102 ,
( V_5 -> V_187 [ 0 ] < 3 ) ? V_5 -> V_187 [ 0 ] : 4 ) ;
return;
case 'r' :
if ( ! V_5 -> V_187 [ 0 ] )
V_5 -> V_187 [ 0 ] ++ ;
if ( ! V_5 -> V_187 [ 1 ] )
V_5 -> V_187 [ 1 ] = V_5 -> V_27 ;
if ( V_5 -> V_187 [ 0 ] < V_5 -> V_187 [ 1 ] &&
V_5 -> V_187 [ 1 ] <= V_5 -> V_27 ) {
V_5 -> V_158 = V_5 -> V_187 [ 0 ] - 1 ;
V_5 -> V_159 = V_5 -> V_187 [ 1 ] ;
F_76 ( V_5 , 0 , 0 ) ;
}
return;
case 's' :
F_65 ( V_5 ) ;
return;
case 'u' :
F_111 ( V_5 ) ;
return;
case 'X' :
F_86 ( V_5 , V_5 -> V_187 [ 0 ] ) ;
return;
case '@' :
F_107 ( V_5 , V_5 -> V_187 [ 0 ] ) ;
return;
case ']' :
F_104 ( V_5 ) ;
return;
}
return;
case V_245 :
V_5 -> V_232 = V_233 ;
switch ( V_9 ) {
case '@' :
V_5 -> V_236 = 0 ;
return;
case 'G' :
case '8' :
V_5 -> V_236 = 1 ;
return;
}
return;
case V_255 :
V_5 -> V_232 = V_233 ;
return;
case V_248 :
V_5 -> V_232 = V_233 ;
if ( V_9 == '8' ) {
V_5 -> V_32 =
( V_5 -> V_32 & 0xff00 ) | 'E' ;
F_84 ( V_5 , 2 ) ;
V_5 -> V_32 =
( V_5 -> V_32 & 0xff00 ) | ' ' ;
F_17 ( V_5 , V_5 -> V_15 , V_5 -> V_72 / 2 ) ;
}
return;
case V_246 :
if ( V_9 == '0' )
V_5 -> V_190 = V_235 ;
else if ( V_9 == 'B' )
V_5 -> V_190 = V_234 ;
else if ( V_9 == 'U' )
V_5 -> V_190 = V_194 ;
else if ( V_9 == 'K' )
V_5 -> V_190 = V_256 ;
if ( V_5 -> V_189 == 0 )
V_5 -> V_188 = F_92 ( V_5 -> V_190 , V_5 ) ;
V_5 -> V_232 = V_233 ;
return;
case V_247 :
if ( V_9 == '0' )
V_5 -> V_191 = V_235 ;
else if ( V_9 == 'B' )
V_5 -> V_191 = V_234 ;
else if ( V_9 == 'U' )
V_5 -> V_191 = V_194 ;
else if ( V_9 == 'K' )
V_5 -> V_191 = V_256 ;
if ( V_5 -> V_189 == 1 )
V_5 -> V_188 = F_92 ( V_5 -> V_191 , V_5 ) ;
V_5 -> V_232 = V_233 ;
return;
case V_241 :
return;
default:
V_5 -> V_232 = V_233 ;
}
}
static int F_120 ( T_4 V_257 , const struct V_258 * V_259 , int V_185 )
{
int F_63 = 0 ;
int V_260 ;
if ( V_257 < V_259 [ 0 ] . V_261 || V_257 > V_259 [ V_185 ] . V_262 )
return 0 ;
while ( V_185 >= F_63 ) {
V_260 = ( F_63 + V_185 ) / 2 ;
if ( V_257 > V_259 [ V_260 ] . V_262 )
F_63 = V_260 + 1 ;
else if ( V_257 < V_259 [ V_260 ] . V_261 )
V_185 = V_260 - 1 ;
else
return 1 ;
}
return 0 ;
}
static int F_121 ( T_4 V_257 )
{
static const struct V_258 V_263 [] = {
{ 0x1100 , 0x115F } , { 0x2329 , 0x232A } , { 0x2E80 , 0x303E } ,
{ 0x3040 , 0xA4CF } , { 0xAC00 , 0xD7A3 } , { 0xF900 , 0xFAFF } ,
{ 0xFE10 , 0xFE19 } , { 0xFE30 , 0xFE6F } , { 0xFF00 , 0xFF60 } ,
{ 0xFFE0 , 0xFFE6 } , { 0x20000 , 0x2FFFD } , { 0x30000 , 0x3FFFD }
} ;
return F_120 ( V_257 , V_263 , F_122 ( V_263 ) - 1 ) ;
}
static int F_123 ( struct V_137 * V_138 , const unsigned char * V_197 , int V_36 )
{
#ifdef F_18
#define F_124 do { } while(0);
#else
#define F_124 if (draw_x >= 0) { \
vc->vc_sw->con_putcs(vc, (u16 *)draw_from, (u16 *)draw_to - (u16 *)draw_from, vc->vc_y, draw_x); \
draw_x = -1; \
}
#endif
int V_9 , V_264 , V_265 , V_266 = 0 , V_267 = - 1 ;
unsigned int V_120 ;
unsigned long V_268 = 0 , V_269 = 0 ;
struct V_4 * V_5 ;
unsigned char V_58 ;
struct V_7 V_8 ;
T_5 V_270 ;
T_5 V_271 ;
T_5 V_132 ;
T_1 V_272 , V_273 ;
if ( F_125 () )
return V_36 ;
F_126 () ;
F_71 () ;
V_5 = V_138 -> V_168 ;
if ( V_5 == NULL ) {
F_127 ( V_274 L_5 ) ;
F_72 () ;
return 0 ;
}
V_120 = V_5 -> V_102 ;
if ( ! F_46 ( V_120 ) ) {
F_128 ( L_6 , V_120 + 1 ) ;
F_72 () ;
return 0 ;
}
V_272 = V_5 -> V_57 ;
V_273 = V_272 ? 0x1ff : 0xff ;
if ( F_36 ( V_5 ) )
F_23 ( V_5 ) ;
V_8 . V_5 = V_5 ;
while ( ! V_138 -> V_275 && V_36 ) {
int V_276 = * V_197 ;
V_9 = V_276 ;
V_197 ++ ;
V_266 ++ ;
V_36 -- ;
V_270 = 0 ;
V_271 = 0 ;
V_132 = 1 ;
if ( V_5 -> V_232 != V_233 ) {
V_264 = V_9 ;
} else if ( V_5 -> V_236 && ! V_5 -> V_192 ) {
V_277:
if ( ( V_9 & 0xc0 ) == 0x80 ) {
static const T_4 V_278 [] = { 0x0000007f , 0x000007ff , 0x0000ffff , 0x001fffff , 0x03ffffff , 0x7fffffff } ;
if ( V_5 -> V_238 ) {
V_5 -> V_279 = ( V_5 -> V_279 << 6 ) | ( V_9 & 0x3f ) ;
V_5 -> V_186 ++ ;
if ( -- V_5 -> V_238 ) {
continue;
}
V_9 = V_5 -> V_279 ;
if ( V_9 <= V_278 [ V_5 -> V_186 - 1 ] ||
V_9 > V_278 [ V_5 -> V_186 ] )
V_9 = 0xfffd ;
} else {
V_5 -> V_238 = 0 ;
V_9 = 0xfffd ;
}
} else {
if ( V_5 -> V_238 ) {
V_270 = 1 ;
V_5 -> V_238 = 0 ;
V_9 = 0xfffd ;
} else if ( V_9 > 0x7f ) {
V_5 -> V_186 = 0 ;
if ( ( V_9 & 0xe0 ) == 0xc0 ) {
V_5 -> V_238 = 1 ;
V_5 -> V_279 = ( V_9 & 0x1f ) ;
} else if ( ( V_9 & 0xf0 ) == 0xe0 ) {
V_5 -> V_238 = 2 ;
V_5 -> V_279 = ( V_9 & 0x0f ) ;
} else if ( ( V_9 & 0xf8 ) == 0xf0 ) {
V_5 -> V_238 = 3 ;
V_5 -> V_279 = ( V_9 & 0x07 ) ;
} else if ( ( V_9 & 0xfc ) == 0xf8 ) {
V_5 -> V_238 = 4 ;
V_5 -> V_279 = ( V_9 & 0x03 ) ;
} else if ( ( V_9 & 0xfe ) == 0xfc ) {
V_5 -> V_238 = 5 ;
V_5 -> V_279 = ( V_9 & 0x01 ) ;
} else {
V_9 = 0xfffd ;
}
if ( V_5 -> V_238 ) {
continue;
}
}
}
if ( ( V_9 >= 0xd800 && V_9 <= 0xdfff ) || V_9 == 0xfffe || V_9 == 0xffff )
V_9 = 0xfffd ;
V_264 = V_9 ;
} else {
V_264 = V_188 ( V_5 , V_9 ) ;
}
V_8 . V_9 = V_264 ;
if ( F_6 ( & V_3 , V_280 ,
& V_8 ) == V_281 )
continue;
V_265 = V_264 && ( V_9 >= 32 ||
! ( V_5 -> V_192 ? ( V_282 >> V_9 ) & 1 :
V_5 -> V_236 || ( ( V_283 >> V_9 ) & 1 ) ) )
&& ( V_9 != 127 || V_5 -> V_192 )
&& ( V_9 != 128 + 27 ) ;
if ( V_5 -> V_232 == V_233 && V_265 ) {
if ( V_5 -> V_236 && ! V_5 -> V_192 ) {
if ( F_121 ( V_9 ) )
V_132 = 2 ;
}
V_264 = F_129 ( V_5 , V_264 ) ;
if ( V_264 & ~ V_273 ) {
if ( V_264 == - 1 || V_264 == - 2 ) {
continue;
}
if ( ( ! ( V_5 -> V_236 && ! V_5 -> V_192 ) || V_9 < 128 ) && ! ( V_9 & ~ V_273 ) ) {
V_264 = V_9 ;
} else {
V_264 = F_129 ( V_5 , 0xfffd ) ;
if ( V_264 < 0 ) {
V_271 = 1 ;
V_264 = F_129 ( V_5 , '?' ) ;
if ( V_264 < 0 ) V_264 = '?' ;
}
}
}
if ( ! V_271 ) {
V_58 = V_5 -> V_58 ;
} else {
if ( ! V_5 -> V_54 ) {
V_58 = ( V_5 -> V_58 ) ^ 0x08 ;
} else if ( V_5 -> V_57 == 0x100 ) {
V_58 = ( ( V_5 -> V_58 ) & 0x11 ) | ( ( ( V_5 -> V_58 ) & 0xe0 ) >> 4 ) | ( ( ( V_5 -> V_58 ) & 0x0e ) << 4 ) ;
} else {
V_58 = ( ( V_5 -> V_58 ) & 0x88 ) | ( ( ( V_5 -> V_58 ) & 0x70 ) >> 4 ) | ( ( ( V_5 -> V_58 ) & 0x07 ) << 4 ) ;
}
F_124
}
while ( 1 ) {
if ( V_5 -> V_78 || V_5 -> V_209 )
F_124
if ( V_5 -> V_78 ) {
F_81 ( V_5 ) ;
F_79 ( V_5 ) ;
}
if ( V_5 -> V_209 )
F_30 ( V_5 , 1 ) ;
F_28 ( V_272 ?
( ( V_58 << 8 ) & ~ V_272 ) + ( ( V_264 & 0x100 ) ? V_272 : 0 ) + ( V_264 & 0xff ) :
( V_58 << 8 ) + V_264 ,
( T_1 * ) V_5 -> V_76 ) ;
if ( F_22 ( V_5 ) && V_267 < 0 ) {
V_267 = V_5 -> V_77 ;
V_268 = V_5 -> V_76 ;
}
if ( V_5 -> V_77 == V_5 -> V_31 - 1 ) {
V_5 -> V_78 = V_5 -> V_207 ;
V_269 = V_5 -> V_76 + 2 ;
} else {
V_5 -> V_77 ++ ;
V_269 = ( V_5 -> V_76 += 2 ) ;
}
if ( ! -- V_132 ) break;
V_264 = F_129 ( V_5 , ' ' ) ;
if ( V_264 < 0 ) V_264 = ' ' ;
}
F_5 ( V_5 , V_9 ) ;
if ( V_271 ) {
F_124
}
if ( V_270 ) {
V_270 = 0 ;
V_271 = 0 ;
V_132 = 1 ;
V_9 = V_276 ;
goto V_277;
}
continue;
}
F_124
F_114 ( V_138 , V_5 , V_276 ) ;
}
F_124
F_130 ();
F_72 () ;
F_7 ( V_5 ) ;
return V_266 ;
#undef F_124
}
static void F_131 ( struct V_284 * V_285 )
{
F_71 () ;
if ( V_286 >= 0 ) {
if ( V_286 != V_100 &&
F_46 ( V_286 ) ) {
F_23 ( V_99 [ V_100 ] . V_25 ) ;
F_132 ( V_99 [ V_286 ] . V_25 ) ;
}
V_286 = - 1 ;
}
if ( V_287 ) {
V_287 = 0 ;
F_105 () ;
}
if ( V_20 ) {
struct V_4 * V_5 = V_99 [ V_100 ] . V_25 ;
F_35 () ;
if ( V_5 -> V_87 == V_288 )
V_5 -> V_16 -> V_289 ( V_5 , V_20 ) ;
V_20 = 0 ;
}
if ( V_290 ) {
F_133 ( 0 ) ;
V_290 = 0 ;
}
F_7 ( V_99 [ V_100 ] . V_25 ) ;
F_72 () ;
}
int F_106 ( int V_24 )
{
struct V_4 * V_5 = V_99 [ V_100 ] . V_25 ;
if ( ! F_46 ( V_24 ) || V_291 ||
( V_5 -> V_292 . V_293 == V_294 && V_5 -> V_87 == V_88 ) ) {
return - V_156 ;
}
V_286 = V_24 ;
F_10 () ;
return 0 ;
}
int F_134 ( int V_74 )
{
static int V_295 ;
if ( V_74 != - 1 )
return F_135 ( & V_295 , V_74 ) ;
else
return V_295 ;
}
static void F_136 ( struct V_296 * V_297 , const char * V_23 , unsigned V_36 )
{
struct V_4 * V_5 = V_99 [ V_100 ] . V_25 ;
unsigned char V_9 ;
static F_137 ( V_298 ) ;
const T_6 * V_35 ;
T_6 V_67 = 0 ;
T_6 V_299 ;
int V_300 ;
if ( ! V_301 )
return;
if ( ! F_138 ( & V_298 ) )
return;
V_300 = F_139 () ;
if ( V_300 && F_46 ( V_300 - 1 ) )
V_5 = V_99 [ V_300 - 1 ] . V_25 ;
V_299 = V_5 -> V_77 ;
if ( ! F_46 ( V_100 ) ) {
goto V_302;
}
if ( V_5 -> V_87 != V_288 && ! F_43 ( V_5 ) )
goto V_302;
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
F_82 ( V_5 ) ;
V_35 = ( T_6 * ) V_5 -> V_76 ;
V_299 = V_5 -> V_77 ;
continue;
}
if ( V_9 != 13 )
F_79 ( V_5 ) ;
F_81 ( V_5 ) ;
V_35 = ( T_6 * ) V_5 -> V_76 ;
V_299 = V_5 -> V_77 ;
if ( V_9 == 10 || V_9 == 13 )
continue;
}
F_28 ( ( V_5 -> V_58 << 8 ) + V_9 , ( unsigned short * ) V_5 -> V_76 ) ;
F_5 ( V_5 , V_9 ) ;
V_67 ++ ;
if ( V_299 == V_5 -> V_31 - 1 ) {
V_5 -> V_78 = 1 ;
continue;
}
V_5 -> V_76 += 2 ;
V_299 ++ ;
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
V_302:
F_140 ( & V_298 ) ;
}
static struct V_303 * F_141 ( struct V_296 * V_9 , int * V_304 )
{
* V_304 = V_9 -> V_304 ? V_9 -> V_304 - 1 : V_100 ;
return V_305 ;
}
int F_142 ( struct V_137 * V_138 , unsigned long V_306 )
{
char type , V_307 ;
char T_7 * V_14 = ( char T_7 * ) V_306 ;
int V_19 ;
int V_169 ;
if ( V_308 -> signal -> V_138 != V_138 && ! F_52 ( V_309 ) )
return - V_124 ;
if ( F_143 ( type , V_14 ) )
return - V_310 ;
V_169 = 0 ;
switch ( type )
{
case V_311 :
F_71 () ;
V_169 = F_144 ( (struct V_312 T_7 * ) ( V_14 + 1 ) , V_138 ) ;
F_72 () ;
break;
case V_313 :
V_169 = F_145 ( V_138 ) ;
break;
case V_314 :
F_71 () ;
F_146 () ;
F_72 () ;
break;
case V_315 :
F_71 () ;
V_169 = F_147 ( V_14 ) ;
F_72 () ;
break;
case V_316 :
V_307 = F_148 () ;
V_169 = F_149 ( V_307 , V_14 ) ;
break;
case V_317 :
F_71 () ;
V_307 = F_100 () ;
F_72 () ;
V_169 = F_149 ( V_307 , V_14 ) ;
break;
case V_318 :
F_71 () ;
V_169 = F_150 ( V_14 ) ;
F_72 () ;
break;
case V_319 :
V_307 = F_139 () ;
V_169 = F_149 ( V_307 , V_14 ) ;
break;
case V_320 :
if ( ! F_52 ( V_309 ) ) {
V_169 = - V_124 ;
} else {
if ( F_143 ( V_307 , V_14 + 1 ) )
V_169 = - V_310 ;
else
F_134 ( V_307 ) ;
}
break;
case V_321 :
V_169 = V_100 ;
break;
case V_322 :
if ( F_143 ( V_19 , ( V_323 T_7 * ) ( V_14 + 4 ) ) ) {
V_169 = - V_310 ;
} else {
F_71 () ;
F_78 ( V_99 [ V_100 ] . V_25 , V_19 ) ;
F_72 () ;
V_169 = 0 ;
}
break;
case V_324 :
F_71 () ;
V_325 = 1 ;
F_133 ( 0 ) ;
F_72 () ;
break;
case V_326 :
V_169 = V_86 ;
break;
default:
V_169 = - V_156 ;
break;
}
return V_169 ;
}
static int F_151 ( struct V_137 * V_138 , const unsigned char * V_197 , int V_36 )
{
int V_327 ;
V_327 = F_123 ( V_138 , V_197 , V_36 ) ;
F_152 ( V_138 ) ;
return V_327 ;
}
static int F_153 ( struct V_137 * V_138 , unsigned char V_328 )
{
if ( F_125 () )
return 0 ;
return F_123 ( V_138 , & V_328 , 1 ) ;
}
static int F_154 ( struct V_137 * V_138 )
{
if ( V_138 -> V_275 )
return 0 ;
return 32768 ;
}
static int F_155 ( struct V_137 * V_138 )
{
return 0 ;
}
static void F_156 ( struct V_137 * V_138 )
{
}
static void F_157 ( struct V_137 * V_138 )
{
struct V_4 * V_5 = V_138 -> V_168 ;
F_158 ( & V_5 -> V_329 ) ;
}
static void F_159 ( struct V_137 * V_138 )
{
int V_330 ;
if ( ! V_138 )
return;
V_330 = V_138 -> V_304 ;
if ( ! F_46 ( V_330 ) )
return;
F_160 ( V_330 ) ;
}
static void F_161 ( struct V_137 * V_138 )
{
int V_330 ;
if ( ! V_138 )
return;
V_330 = V_138 -> V_304 ;
if ( ! F_46 ( V_330 ) )
return;
F_162 ( V_330 ) ;
}
static void F_152 ( struct V_137 * V_138 )
{
struct V_4 * V_5 ;
if ( F_125 () )
return;
F_71 () ;
V_5 = V_138 -> V_168 ;
if ( V_5 )
F_24 ( V_5 ) ;
F_72 () ;
}
static int F_163 ( struct V_303 * V_331 , struct V_137 * V_138 )
{
unsigned int V_120 = V_138 -> V_304 ;
struct V_4 * V_5 ;
int V_169 ;
F_71 () ;
V_169 = F_51 ( V_120 ) ;
if ( V_169 )
goto V_332;
V_5 = V_99 [ V_120 ] . V_25 ;
if ( V_5 -> V_127 . V_138 ) {
V_169 = - V_333 ;
goto V_332;
}
V_169 = F_164 ( & V_5 -> V_127 , V_331 , V_138 ) ;
if ( V_169 )
goto V_332;
V_138 -> V_168 = V_5 ;
V_5 -> V_127 . V_138 = V_138 ;
if ( ! V_138 -> V_160 . V_162 && ! V_138 -> V_160 . V_163 ) {
V_138 -> V_160 . V_162 = V_99 [ V_120 ] . V_25 -> V_27 ;
V_138 -> V_160 . V_163 = V_99 [ V_120 ] . V_25 -> V_31 ;
}
if ( V_5 -> V_236 )
V_138 -> V_334 . V_335 |= V_336 ;
else
V_138 -> V_334 . V_335 &= ~ V_336 ;
V_332:
F_72 () ;
return V_169 ;
}
static int F_165 ( struct V_137 * V_138 , struct V_337 * V_338 )
{
return 0 ;
}
static void F_166 ( struct V_137 * V_138 , struct V_337 * V_338 )
{
}
static void F_167 ( struct V_137 * V_138 )
{
struct V_4 * V_5 = V_138 -> V_168 ;
F_168 ( V_5 == NULL ) ;
F_71 () ;
V_5 -> V_127 . V_138 = NULL ;
F_72 () ;
}
static void F_59 ( struct V_4 * V_5 , unsigned int V_167 ,
unsigned int V_139 , int V_231 )
{
int V_252 , V_339 ;
V_5 -> V_31 = V_139 ;
V_5 -> V_27 = V_167 ;
V_5 -> V_30 = V_139 << 1 ;
V_5 -> V_72 = V_5 -> V_27 * V_5 -> V_30 ;
F_37 ( V_5 ) ;
V_5 -> V_76 = V_5 -> V_15 ;
F_169 ( V_5 ) ;
for ( V_252 = V_339 = 0 ; V_252 < 16 ; V_252 ++ ) {
V_5 -> V_253 [ V_339 ++ ] = V_340 [ V_252 ] ;
V_5 -> V_253 [ V_339 ++ ] = V_341 [ V_252 ] ;
V_5 -> V_253 [ V_339 ++ ] = V_342 [ V_252 ] ;
}
V_5 -> V_180 = V_343 ;
V_5 -> V_56 = V_344 ;
V_5 -> V_55 = V_345 ;
V_5 -> V_211 = 0x08 ;
F_170 ( & V_5 -> V_329 ) ;
F_112 ( V_5 , V_231 ) ;
}
static int T_8 V_118 ( void )
{
const char * V_346 = NULL ;
struct V_4 * V_5 ;
unsigned int V_120 = 0 , V_79 ;
F_71 () ;
if ( V_112 )
V_346 = V_112 -> V_347 () ;
if ( ! V_346 ) {
V_100 = 0 ;
F_72 () ;
return 0 ;
}
for ( V_79 = 0 ; V_79 < V_348 ; V_79 ++ ) {
struct V_349 * V_349 = & V_350 [ V_79 ] ;
if ( V_349 -> V_351 == NULL ) {
V_349 -> V_351 = V_112 ;
V_349 -> V_352 = V_346 ;
V_349 -> V_353 = V_354 ;
V_349 -> V_261 = 0 ;
V_349 -> V_262 = V_108 - 1 ;
break;
}
}
for ( V_79 = 0 ; V_79 < V_108 ; V_79 ++ )
V_113 [ V_79 ] = V_112 ;
if ( V_212 ) {
V_355 = V_356 ;
F_171 ( & V_357 , V_358 + ( V_212 * V_216 ) ) ;
}
for ( V_120 = 0 ; V_120 < V_359 ; V_120 ++ ) {
V_99 [ V_120 ] . V_25 = V_5 = F_53 ( sizeof( struct V_4 ) , V_360 ) ;
F_55 ( & V_99 [ V_120 ] . V_128 , V_129 ) ;
F_54 ( & V_5 -> V_127 ) ;
F_47 ( V_5 , V_120 , 1 ) ;
V_5 -> V_92 = F_53 ( V_5 -> V_72 , V_360 ) ;
F_59 ( V_5 , V_5 -> V_27 , V_5 -> V_31 ,
V_120 || ! V_5 -> V_16 -> V_94 ) ;
}
V_120 = V_100 = 0 ;
V_114 = V_5 = V_99 [ V_120 ] . V_25 ;
F_37 ( V_5 ) ;
F_38 ( V_5 ) ;
F_64 ( V_5 , V_5 -> V_77 , V_5 -> V_82 ) ;
F_84 ( V_5 , 0 ) ;
F_67 ( V_5 ) ;
F_172 ( L_7 ,
V_5 -> V_54 ? L_8 : L_9 ,
V_346 , V_5 -> V_31 , V_5 -> V_27 ) ;
V_301 = 1 ;
F_72 () ;
#ifdef F_173
F_174 ( & V_361 ) ;
#endif
return 0 ;
}
static T_9 F_175 ( struct V_362 * V_363 ,
struct V_364 * V_365 , char * V_197 )
{
return sprintf ( V_197 , L_10 , V_100 + 1 ) ;
}
int T_8 F_176 ( const struct V_366 * V_367 )
{
F_177 ( & V_368 , V_367 ) ;
if ( F_178 ( & V_368 , F_179 ( V_369 , 0 ) , 1 ) ||
F_180 ( F_179 ( V_369 , 0 ) , 1 , L_11 ) < 0 )
F_181 ( L_12 ) ;
V_103 = F_182 ( V_370 , NULL , F_179 ( V_369 , 0 ) , NULL , L_13 ) ;
if ( F_183 ( V_103 ) )
V_103 = NULL ;
else
F_184 ( F_185 ( V_103 , & V_371 ) < 0 ) ;
F_186 () ;
V_305 = F_187 ( V_108 ) ;
if ( ! V_305 )
F_181 ( L_14 ) ;
V_305 -> V_372 = L_15 ;
V_305 -> V_373 = 1 ;
V_305 -> V_374 = V_369 ;
V_305 -> V_375 = 1 ;
V_305 -> type = V_376 ;
V_305 -> V_377 = V_378 ;
if ( V_237 )
V_305 -> V_377 . V_335 |= V_336 ;
V_305 -> V_379 = V_380 | V_381 ;
F_188 ( V_305 , & V_382 ) ;
if ( F_189 ( V_305 ) )
F_181 ( L_16 ) ;
F_190 () ;
F_191 () ;
#ifdef F_192
F_193 () ;
#endif
return 0 ;
}
static int F_194 ( const struct V_383 * V_384 , int V_261 , int V_262 ,
int V_385 )
{
struct V_386 * V_111 = V_384 -> V_111 ;
const char * V_352 = NULL ;
struct V_349 * V_349 ;
int V_79 , V_252 = - 1 , V_339 = - 1 , V_327 = - V_387 ;
if ( ! F_195 ( V_111 ) )
return - V_387 ;
F_21 () ;
for ( V_79 = 0 ; V_79 < V_348 ; V_79 ++ ) {
V_349 = & V_350 [ V_79 ] ;
if ( V_349 -> V_351 == V_384 ) {
V_352 = V_349 -> V_352 ;
V_327 = 0 ;
break;
}
}
if ( V_327 )
goto V_135;
if ( ! ( V_349 -> V_353 & V_354 ) ) {
V_384 -> V_347 () ;
V_349 -> V_353 |= V_354 ;
}
if ( V_385 ) {
if ( V_112 )
F_48 ( V_112 -> V_111 ) ;
F_50 ( V_111 ) ;
V_112 = V_384 ;
}
V_261 = V_185 ( V_261 , V_349 -> V_261 ) ;
V_262 = F_63 ( V_262 , V_349 -> V_262 ) ;
for ( V_79 = V_261 ; V_79 <= V_262 ; V_79 ++ ) {
int V_106 ;
struct V_4 * V_5 = V_99 [ V_79 ] . V_25 ;
if ( V_113 [ V_79 ] )
F_48 ( V_113 [ V_79 ] -> V_111 ) ;
F_50 ( V_111 ) ;
V_113 [ V_79 ] = V_384 ;
if ( ! V_5 || ! V_5 -> V_16 )
continue;
V_252 = V_79 ;
if ( F_13 ( V_5 ) ) {
V_339 = V_79 ;
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
F_172 ( L_17 ) ;
if ( ! V_385 )
F_127 ( L_18 , V_261 + 1 , V_262 + 1 ) ;
if ( V_252 >= 0 ) {
struct V_4 * V_5 = V_99 [ V_252 ] . V_25 ;
F_127 ( L_19 ,
V_5 -> V_54 ? L_8 : L_9 ,
V_352 , V_5 -> V_31 , V_5 -> V_27 ) ;
if ( V_339 >= 0 ) {
V_5 = V_99 [ V_339 ] . V_25 ;
F_67 ( V_5 ) ;
}
} else
F_127 ( L_20 , V_352 ) ;
V_327 = 0 ;
V_135:
F_48 ( V_111 ) ;
return V_327 ;
}
static int F_196 ( const struct V_383 * V_384 , int V_261 , int V_262 )
{
int V_79 , V_327 = 0 ;
for ( V_79 = V_261 ; V_79 <= V_262 ; V_79 ++ ) {
struct V_4 * V_5 = V_99 [ V_79 ] . V_25 ;
if ( V_5 && V_5 -> V_87 == V_88 ) {
V_327 = 1 ;
break;
}
}
return V_327 ;
}
int F_197 ( const struct V_383 * V_384 , int V_261 , int V_262 , int V_385 )
{
struct V_386 * V_111 = V_384 -> V_111 ;
const struct V_383 * V_388 = NULL ;
struct V_349 * V_349 = NULL , * V_389 = NULL ;
int V_79 , V_327 = - V_387 ;
if ( ! F_195 ( V_111 ) )
return - V_387 ;
F_21 () ;
for ( V_79 = 0 ; V_79 < V_348 ; V_79 ++ ) {
V_349 = & V_350 [ V_79 ] ;
if ( V_349 -> V_351 == V_384 &&
V_349 -> V_353 & V_390 ) {
V_327 = 0 ;
break;
}
}
if ( V_327 )
goto V_135;
V_327 = - V_387 ;
for ( V_79 = 0 ; V_79 < V_348 ; V_79 ++ ) {
V_389 = & V_350 [ V_79 ] ;
if ( V_389 -> V_351 && V_389 -> V_351 != V_384 ) {
V_388 = V_389 -> V_351 ;
V_327 = 0 ;
break;
}
}
if ( V_327 )
goto V_135;
if ( ! F_198 ( V_384 ) )
goto V_135;
V_261 = V_185 ( V_261 , V_349 -> V_261 ) ;
V_262 = F_63 ( V_262 , V_349 -> V_262 ) ;
for ( V_79 = V_261 ; V_79 <= V_262 ; V_79 ++ ) {
if ( V_113 [ V_79 ] == V_384 ) {
F_48 ( V_384 -> V_111 ) ;
V_113 [ V_79 ] = NULL ;
}
}
if ( ! F_198 ( V_388 ) ) {
const struct V_383 * V_391 = V_112 ;
V_388 -> V_347 () ;
V_389 -> V_353 |= V_354 ;
V_112 = V_391 ;
}
if ( ! F_198 ( V_384 ) )
V_349 -> V_353 &= ~ V_354 ;
F_194 ( V_388 , V_261 , V_262 , V_385 ) ;
V_135:
F_48 ( V_111 ) ;
return V_327 ;
}
static int F_199 ( struct V_349 * V_351 )
{
const struct V_383 * V_388 = NULL , * V_384 = NULL ;
int V_79 , V_392 = 1 , V_261 = - 1 , V_262 = - 1 , V_385 = 0 ;
if ( ! V_351 -> V_351 || ! ( V_351 -> V_353 & V_390 ) ||
F_196 ( V_351 -> V_351 , V_351 -> V_261 , V_351 -> V_262 ) )
goto V_135;
V_384 = V_351 -> V_351 ;
for ( V_79 = 0 ; V_79 < V_348 ; V_79 ++ ) {
struct V_349 * V_351 = & V_350 [ V_79 ] ;
if ( V_351 -> V_351 && ! ( V_351 -> V_353 & V_390 ) ) {
V_388 = V_351 -> V_351 ;
break;
}
}
if ( ! V_388 )
goto V_135;
while ( V_392 ) {
V_392 = 0 ;
for ( V_79 = V_351 -> V_261 ; V_79 <= V_351 -> V_262 ; V_79 ++ ) {
if ( V_113 [ V_79 ] == V_388 ) {
if ( V_261 == - 1 )
V_261 = V_79 ;
V_262 = V_79 ;
V_392 = 1 ;
} else if ( V_261 != - 1 )
break;
}
if ( V_261 == 0 && V_262 == V_108 - 1 )
V_385 = 1 ;
if ( V_261 != - 1 )
F_194 ( V_384 , V_261 , V_262 , V_385 ) ;
V_261 = - 1 ;
V_262 = - 1 ;
V_385 = 0 ;
}
V_135:
return 0 ;
}
static int F_200 ( struct V_349 * V_351 )
{
const struct V_383 * V_384 = NULL ;
int V_79 , V_392 = 1 , V_261 = - 1 , V_262 = - 1 , V_385 = 0 ;
int V_169 ;
if ( ! V_351 -> V_351 || ! ( V_351 -> V_353 & V_390 ) ||
F_196 ( V_351 -> V_351 , V_351 -> V_261 , V_351 -> V_262 ) )
goto V_135;
V_384 = V_351 -> V_351 ;
while ( V_392 ) {
V_392 = 0 ;
for ( V_79 = V_351 -> V_261 ; V_79 <= V_351 -> V_262 ; V_79 ++ ) {
if ( V_113 [ V_79 ] == V_384 ) {
if ( V_261 == - 1 )
V_261 = V_79 ;
V_262 = V_79 ;
V_392 = 1 ;
} else if ( V_261 != - 1 )
break;
}
if ( V_261 == 0 && V_262 == V_108 - 1 )
V_385 = 1 ;
if ( V_261 != - 1 ) {
V_169 = F_197 ( V_384 , V_261 , V_262 , V_385 ) ;
if ( V_169 != 0 )
return V_169 ;
}
V_261 = - 1 ;
V_262 = - 1 ;
V_385 = 0 ;
}
V_135:
return 0 ;
}
static inline int F_199 ( struct V_349 * V_351 )
{
return 0 ;
}
static inline int F_200 ( struct V_349 * V_351 )
{
return 0 ;
}
static T_9 F_201 ( struct V_362 * V_363 , struct V_364 * V_365 ,
const char * V_197 , T_10 V_36 )
{
struct V_349 * V_351 = F_202 ( V_363 ) ;
int V_393 = F_203 ( V_197 , NULL , 0 ) ;
F_71 () ;
if ( V_393 )
F_199 ( V_351 ) ;
else
F_200 ( V_351 ) ;
F_72 () ;
return V_36 ;
}
static T_9 F_204 ( struct V_362 * V_363 , struct V_364 * V_365 ,
char * V_197 )
{
struct V_349 * V_351 = F_202 ( V_363 ) ;
int V_393 = F_198 ( V_351 -> V_351 ) ;
return snprintf ( V_197 , V_394 , L_21 , V_393 ) ;
}
static T_9 F_205 ( struct V_362 * V_363 , struct V_364 * V_365 ,
char * V_197 )
{
struct V_349 * V_351 = F_202 ( V_363 ) ;
return snprintf ( V_197 , V_394 , L_22 ,
( V_351 -> V_353 & V_390 ) ? L_23 : L_24 ,
V_351 -> V_352 ) ;
}
static int F_206 ( struct V_349 * V_351 )
{
int V_79 ;
int error = 0 ;
V_351 -> V_353 |= V_395 ;
F_207 ( V_351 -> V_363 , V_351 ) ;
for ( V_79 = 0 ; V_79 < F_122 ( V_396 ) ; V_79 ++ ) {
error = F_185 ( V_351 -> V_363 , & V_396 [ V_79 ] ) ;
if ( error )
break;
}
if ( error ) {
while ( -- V_79 >= 0 )
F_208 ( V_351 -> V_363 , & V_396 [ V_79 ] ) ;
V_351 -> V_353 &= ~ V_395 ;
}
return error ;
}
static void F_209 ( struct V_349 * V_351 )
{
int V_79 ;
if ( V_351 -> V_353 & V_395 ) {
for ( V_79 = 0 ; V_79 < F_122 ( V_396 ) ; V_79 ++ )
F_208 ( V_351 -> V_363 , & V_396 [ V_79 ] ) ;
V_351 -> V_353 &= ~ V_395 ;
}
}
int F_198 ( const struct V_383 * V_384 )
{
int V_79 , V_397 = 0 ;
for ( V_79 = 0 ; V_79 < V_108 ; V_79 ++ ) {
if ( V_113 [ V_79 ] == V_384 ) {
V_397 = 1 ;
break;
}
}
return V_397 ;
}
int F_210 ( struct V_4 * V_5 )
{
int V_169 = 0 ;
V_398 = V_100 ;
V_399 = V_219 ;
V_400 = V_286 ;
V_401 = V_5 -> V_87 ;
V_402 = V_86 ;
V_5 -> V_87 = V_288 ;
V_86 = 0 ;
if ( V_5 -> V_16 -> F_210 )
V_169 = V_5 -> V_16 -> F_210 ( V_5 ) ;
#ifdef F_211
if ( V_5 -> V_27 < 999 ) {
int V_403 ;
char V_404 [ 4 ] ;
const char * V_405 [ 3 ] = {
L_25 ,
L_26 ,
V_404 ,
} ;
if ( F_212 ( V_405 [ 0 ] , & V_403 ) ) {
snprintf ( V_404 , 4 , L_27 , V_5 -> V_27 ) ;
F_213 ( 2 , V_405 ) ;
}
}
if ( V_5 -> V_31 < 999 ) {
int V_406 ;
char V_139 [ 4 ] ;
const char * V_405 [ 3 ] = {
L_25 ,
L_28 ,
V_139 ,
} ;
if ( F_212 ( V_405 [ 0 ] , & V_406 ) ) {
snprintf ( V_139 , 4 , L_27 , V_5 -> V_31 ) ;
F_213 ( 2 , V_405 ) ;
}
}
#endif
return V_169 ;
}
int F_214 ( void )
{
struct V_4 * V_5 ;
int V_169 = 0 ;
V_100 = V_398 ;
V_219 = V_399 ;
V_286 = V_400 ;
V_86 = V_402 ;
V_99 [ V_100 ] . V_25 -> V_87 = V_401 ;
V_5 = V_99 [ V_100 ] . V_25 ;
if ( V_5 -> V_16 -> F_214 )
V_169 = V_5 -> V_16 -> F_214 ( V_5 ) ;
return V_169 ;
}
static int F_215 ( const struct V_383 * V_384 , int V_261 , int V_262 )
{
struct V_386 * V_111 = V_384 -> V_111 ;
struct V_349 * V_349 ;
const char * V_352 ;
int V_79 , V_327 = 0 ;
F_21 () ;
if ( ! F_195 ( V_111 ) )
return - V_387 ;
for ( V_79 = 0 ; V_79 < V_348 ; V_79 ++ ) {
V_349 = & V_350 [ V_79 ] ;
if ( V_349 -> V_351 == V_384 )
V_327 = - V_407 ;
}
if ( V_327 )
goto V_135;
V_352 = V_384 -> V_347 () ;
if ( ! V_352 )
goto V_135;
V_327 = - V_156 ;
for ( V_79 = 0 ; V_79 < V_348 ; V_79 ++ ) {
V_349 = & V_350 [ V_79 ] ;
if ( V_349 -> V_351 == NULL ) {
V_349 -> V_351 = V_384 ;
V_349 -> V_352 = V_352 ;
V_349 -> V_408 = V_79 ;
V_349 -> V_353 = V_390 |
V_354 ;
V_349 -> V_261 = V_261 ;
V_349 -> V_262 = V_262 ;
V_327 = 0 ;
break;
}
}
if ( V_327 )
goto V_135;
V_349 -> V_363 = F_182 ( V_409 , NULL ,
F_179 ( 0 , V_349 -> V_408 ) ,
NULL , L_29 ,
V_349 -> V_408 ) ;
if ( F_183 ( V_349 -> V_363 ) ) {
F_127 ( V_410 L_30
L_31 , V_349 -> V_352 ,
F_216 ( V_349 -> V_363 ) ) ;
V_349 -> V_363 = NULL ;
} else {
F_206 ( V_349 ) ;
}
V_135:
F_48 ( V_111 ) ;
return V_327 ;
}
int F_217 ( const struct V_383 * V_384 )
{
int V_79 ;
if ( F_198 ( V_384 ) )
return - V_407 ;
if ( V_384 == V_112 )
return - V_156 ;
for ( V_79 = 0 ; V_79 < V_348 ; V_79 ++ ) {
struct V_349 * V_349 = & V_350 [ V_79 ] ;
if ( V_349 -> V_351 == V_384 ) {
F_209 ( V_349 ) ;
F_218 ( V_409 ,
F_179 ( 0 , V_349 -> V_408 ) ) ;
V_349 -> V_351 = NULL ;
V_349 -> V_352 = NULL ;
V_349 -> V_363 = NULL ;
V_349 -> V_408 = 0 ;
V_349 -> V_353 = 0 ;
V_349 -> V_261 = 0 ;
V_349 -> V_262 = 0 ;
return 0 ;
}
}
return - V_387 ;
}
int F_219 ( const struct V_383 * V_384 , int V_261 , int V_262 , int V_385 )
{
int V_135 ;
V_135 = F_215 ( V_384 , V_261 , V_262 ) ;
if ( V_135 == - V_407 )
V_135 = 0 ;
if ( ! V_135 )
F_194 ( V_384 , V_261 , V_262 , V_385 ) ;
return V_135 ;
}
void F_220 ( const struct V_383 * V_384 )
{
F_71 () ;
F_217 ( V_384 ) ;
F_72 () ;
}
static int T_8 F_221 ( void )
{
int V_79 ;
V_409 = F_222 ( V_411 , L_32 ) ;
if ( F_183 ( V_409 ) ) {
F_127 ( V_410 L_33
L_31 , F_216 ( V_409 ) ) ;
V_409 = NULL ;
}
for ( V_79 = 0 ; V_79 < V_348 ; V_79 ++ ) {
struct V_349 * V_351 = & V_350 [ V_79 ] ;
if ( V_351 -> V_351 && ! V_351 -> V_363 ) {
V_351 -> V_363 = F_182 ( V_409 , NULL ,
F_179 ( 0 , V_351 -> V_408 ) ,
NULL , L_29 ,
V_351 -> V_408 ) ;
if ( F_183 ( V_351 -> V_363 ) ) {
F_127 ( V_410 L_34
L_35 ,
V_351 -> V_352 , F_216 ( V_351 -> V_363 ) ) ;
V_351 -> V_363 = NULL ;
} else {
F_206 ( V_351 ) ;
}
}
}
return 0 ;
}
static int F_150 ( char T_7 * V_14 )
{
unsigned int V_293 ;
if ( F_143 ( V_293 , V_14 + 1 ) )
return - V_310 ;
V_412 = ( V_293 < 4 ) ? V_293 : 0 ;
return 0 ;
}
void F_133 ( int V_413 )
{
struct V_4 * V_5 = V_99 [ V_100 ] . V_25 ;
int V_79 ;
F_21 () ;
if ( V_86 ) {
if ( V_355 == V_414 ) {
V_355 = V_415 ;
V_5 -> V_16 -> V_416 ( V_5 , V_412 + 1 , 0 ) ;
}
return;
}
if ( V_413 ) {
F_23 ( V_5 ) ;
F_38 ( V_5 ) ;
V_5 -> V_16 -> V_416 ( V_5 , - 1 , 1 ) ;
V_86 = V_100 + 1 ;
V_355 = V_415 ;
F_37 ( V_5 ) ;
return;
}
if ( V_355 != V_356 )
return;
V_355 = V_415 ;
if ( V_5 -> V_87 != V_288 ) {
V_86 = V_100 + 1 ;
return;
}
F_23 ( V_5 ) ;
F_223 ( & V_357 ) ;
V_290 = 0 ;
F_38 ( V_5 ) ;
V_79 = V_5 -> V_16 -> V_416 ( V_5 , V_218 ? 1 : ( V_412 + 1 ) , 0 ) ;
V_86 = V_100 + 1 ;
if ( V_79 )
F_37 ( V_5 ) ;
if ( V_417 && V_417 ( 1 ) )
return;
if ( V_218 && V_412 ) {
V_355 = V_414 ;
F_171 ( & V_357 , V_358 + V_218 ) ;
}
F_68 ( V_418 , V_5 -> V_102 , V_5 -> V_102 ) ;
}
void F_224 ( int V_419 )
{
struct V_4 * V_5 ;
if ( ! V_420 )
F_126 () ;
F_21 () ;
V_325 = 0 ;
if ( ! V_86 )
return;
if ( ! F_46 ( V_100 ) ) {
F_225 ( L_36 ,
V_100 + 1 ) ;
return;
}
V_5 = V_99 [ V_100 ] . V_25 ;
if ( V_5 -> V_87 != V_288 && ! F_43 ( V_5 ) )
return;
if ( V_212 ) {
F_171 ( & V_357 , V_358 + ( V_212 * V_216 ) ) ;
V_355 = V_356 ;
}
V_86 = 0 ;
if ( V_5 -> V_16 -> V_416 ( V_5 , 0 , V_419 ) || F_43 ( V_5 ) )
F_67 ( V_5 ) ;
if ( V_417 )
V_417 ( 0 ) ;
F_42 ( V_5 ) ;
F_24 ( V_5 ) ;
F_68 ( V_421 , V_5 -> V_102 , V_5 -> V_102 ) ;
}
void F_146 ( void )
{
F_224 ( 0 ) ;
}
static void F_226 ( unsigned long V_422 )
{
if ( F_227 ( ! F_228 () ) ) {
F_171 ( & V_357 , V_358 + ( V_212 * V_216 ) ) ;
return;
}
V_290 = 1 ;
F_11 ( & V_21 ) ;
}
void F_105 ( void )
{
F_21 () ;
F_126 () ;
F_229 ( & V_357 ) ;
V_290 = 0 ;
if ( V_325 || ! V_99 [ V_100 ] . V_25 || V_99 [ V_100 ] . V_25 -> V_87 == V_88 )
return;
if ( V_86 )
F_146 () ;
else if ( V_212 ) {
F_171 ( & V_357 , V_358 + ( V_212 * V_216 ) ) ;
V_355 = V_356 ;
}
}
static void F_42 ( struct V_4 * V_5 )
{
F_21 () ;
if ( V_5 -> V_87 != V_88 )
V_5 -> V_16 -> V_423 ( V_5 , V_195 ) ;
}
int F_230 ( unsigned char T_7 * V_306 )
{
int V_79 , V_252 , V_339 ;
unsigned char V_424 [ 3 * 16 ] ;
if ( F_231 ( V_424 , V_306 , sizeof( V_424 ) ) )
return - V_310 ;
F_71 () ;
for ( V_79 = V_339 = 0 ; V_79 < 16 ; V_79 ++ ) {
V_340 [ V_79 ] = V_424 [ V_339 ++ ] ;
V_341 [ V_79 ] = V_424 [ V_339 ++ ] ;
V_342 [ V_79 ] = V_424 [ V_339 ++ ] ;
}
for ( V_79 = 0 ; V_79 < V_108 ; V_79 ++ ) {
if ( ! F_46 ( V_79 ) )
continue;
for ( V_252 = V_339 = 0 ; V_252 < 16 ; V_252 ++ ) {
V_99 [ V_79 ] . V_25 -> V_253 [ V_339 ++ ] = V_340 [ V_252 ] ;
V_99 [ V_79 ] . V_25 -> V_253 [ V_339 ++ ] = V_341 [ V_252 ] ;
V_99 [ V_79 ] . V_25 -> V_253 [ V_339 ++ ] = V_342 [ V_252 ] ;
}
F_42 ( V_99 [ V_79 ] . V_25 ) ;
}
F_72 () ;
return 0 ;
}
int F_232 ( unsigned char T_7 * V_306 )
{
int V_79 , V_339 ;
unsigned char V_424 [ 3 * 16 ] ;
F_71 () ;
for ( V_79 = V_339 = 0 ; V_79 < 16 ; V_79 ++ ) {
V_424 [ V_339 ++ ] = V_340 [ V_79 ] ;
V_424 [ V_339 ++ ] = V_341 [ V_79 ] ;
V_424 [ V_339 ++ ] = V_342 [ V_79 ] ;
}
F_72 () ;
if ( F_233 ( V_306 , V_424 , sizeof( V_424 ) ) )
return - V_310 ;
return 0 ;
}
void F_117 ( struct V_4 * V_5 )
{
int V_252 , V_339 ;
for ( V_252 = V_339 = 0 ; V_252 < 16 ; V_252 ++ ) {
V_5 -> V_253 [ V_339 ++ ] = V_340 [ V_252 ] ;
V_5 -> V_253 [ V_339 ++ ] = V_341 [ V_252 ] ;
V_5 -> V_253 [ V_339 ++ ] = V_342 [ V_252 ] ;
}
F_42 ( V_5 ) ;
}
static int F_234 ( struct V_4 * V_5 , struct V_425 * V_426 )
{
struct V_427 V_428 ;
int V_429 = - V_156 ;
int V_9 ;
if ( V_426 -> V_307 ) {
V_428 . V_307 = F_57 ( V_430 , V_125 ) ;
if ( ! V_428 . V_307 )
return - V_126 ;
} else
V_428 . V_307 = NULL ;
F_71 () ;
if ( V_5 -> V_87 != V_288 )
V_429 = - V_156 ;
else if ( V_5 -> V_16 -> F_234 )
V_429 = V_5 -> V_16 -> F_234 ( V_5 , & V_428 ) ;
else
V_429 = - V_431 ;
F_72 () ;
if ( V_429 )
goto V_432;
V_9 = ( V_428 . V_132 + 7 ) / 8 * 32 * V_428 . V_433 ;
if ( V_426 -> V_307 && V_428 . V_433 > V_426 -> V_433 )
V_429 = - V_434 ;
if ( ! ( V_426 -> V_379 & V_435 ) ) {
if ( V_428 . V_132 > V_426 -> V_132 || V_428 . V_133 > V_426 -> V_133 )
V_429 = - V_434 ;
} else {
if ( V_428 . V_132 != 8 )
V_429 = - V_436 ;
else if ( ( V_426 -> V_133 && V_428 . V_133 > V_426 -> V_133 ) ||
V_428 . V_133 > 32 )
V_429 = - V_434 ;
}
if ( V_429 )
goto V_432;
V_426 -> V_133 = V_428 . V_133 ;
V_426 -> V_132 = V_428 . V_132 ;
V_426 -> V_433 = V_428 . V_433 ;
if ( V_426 -> V_307 && F_233 ( V_426 -> V_307 , V_428 . V_307 , V_9 ) )
V_429 = - V_310 ;
V_432:
F_58 ( V_428 . V_307 ) ;
return V_429 ;
}
static int F_235 ( struct V_4 * V_5 , struct V_425 * V_426 )
{
struct V_427 V_428 ;
int V_429 = - V_156 ;
int V_437 ;
if ( V_5 -> V_87 != V_288 )
return - V_156 ;
if ( ! V_426 -> V_307 )
return - V_156 ;
if ( V_426 -> V_433 > 512 )
return - V_156 ;
if ( ! V_426 -> V_133 ) {
int V_438 , V_79 ;
T_2 T_7 * V_439 = V_426 -> V_307 ;
T_2 V_440 ;
if ( ! ( V_426 -> V_379 & V_435 ) )
return - V_156 ;
for ( V_438 = 32 ; V_438 > 0 ; V_438 -- )
for ( V_79 = 0 ; V_79 < V_426 -> V_433 ; V_79 ++ ) {
if ( F_143 ( V_440 , & V_439 [ 32 * V_79 + V_438 - 1 ] ) )
return - V_310 ;
if ( V_440 )
goto V_441;
}
return - V_156 ;
V_441:
V_426 -> V_133 = V_438 ;
}
if ( V_426 -> V_132 <= 0 || V_426 -> V_132 > 32 || V_426 -> V_133 > 32 )
return - V_156 ;
V_437 = ( V_426 -> V_132 + 7 ) / 8 * 32 * V_426 -> V_433 ;
if ( V_437 > V_430 )
return - V_434 ;
V_428 . V_433 = V_426 -> V_433 ;
V_428 . V_133 = V_426 -> V_133 ;
V_428 . V_132 = V_426 -> V_132 ;
V_428 . V_307 = F_236 ( V_426 -> V_307 , V_437 ) ;
if ( F_183 ( V_428 . V_307 ) )
return F_216 ( V_428 . V_307 ) ;
F_71 () ;
if ( V_5 -> V_87 != V_288 )
V_429 = - V_156 ;
else if ( V_5 -> V_16 -> F_235 )
V_429 = V_5 -> V_16 -> F_235 ( V_5 , & V_428 , V_426 -> V_379 ) ;
else
V_429 = - V_431 ;
F_72 () ;
F_58 ( V_428 . V_307 ) ;
return V_429 ;
}
static int F_237 ( struct V_4 * V_5 , struct V_425 * V_426 )
{
struct V_427 V_428 = { . V_132 = V_426 -> V_132 , . V_133 = V_426 -> V_133 } ;
char V_372 [ V_442 ] ;
char * V_26 = V_372 ;
int V_429 ;
if ( ! V_426 -> V_307 )
V_26 = NULL ;
else if ( F_238 ( V_372 , V_426 -> V_307 , V_442 - 1 ) < 0 )
return - V_310 ;
else
V_372 [ V_442 - 1 ] = 0 ;
F_71 () ;
if ( V_5 -> V_87 != V_288 ) {
F_72 () ;
return - V_156 ;
}
if ( V_5 -> V_16 -> F_237 )
V_429 = V_5 -> V_16 -> F_237 ( V_5 , & V_428 , V_26 ) ;
else
V_429 = - V_431 ;
F_72 () ;
if ( ! V_429 ) {
V_426 -> V_132 = V_428 . V_132 ;
V_426 -> V_133 = V_428 . V_133 ;
}
return V_429 ;
}
static int F_239 ( struct V_4 * V_5 , struct V_425 * V_426 )
{
int V_351 = V_426 -> V_133 ;
int V_429 ;
F_71 () ;
if ( V_5 -> V_87 != V_288 )
V_429 = - V_156 ;
else if ( ! V_5 -> V_16 -> F_239 )
V_429 = - V_431 ;
else if ( V_351 < 0 || ! F_46 ( V_351 ) )
V_429 = - V_443 ;
else if ( V_351 == V_5 -> V_102 )
V_429 = 0 ;
else
V_429 = V_5 -> V_16 -> F_239 ( V_5 , V_351 ) ;
F_72 () ;
return V_429 ;
}
int F_240 ( struct V_4 * V_5 , struct V_425 * V_426 )
{
switch ( V_426 -> V_426 ) {
case V_444 :
return F_235 ( V_5 , V_426 ) ;
case V_445 :
return F_234 ( V_5 , V_426 ) ;
case V_446 :
return F_237 ( V_5 , V_426 ) ;
case V_447 :
return F_239 ( V_5 , V_426 ) ;
}
return - V_431 ;
}
T_1 F_241 ( struct V_4 * V_5 , int V_12 )
{
T_1 V_448 = F_19 ( F_8 ( V_5 , V_12 , 1 ) ) ;
T_1 V_9 = V_448 & 0xff ;
if ( V_448 & V_5 -> V_57 )
V_9 |= 0x100 ;
return V_9 ;
}
unsigned short * F_242 ( struct V_4 * V_5 , int V_449 , int V_13 )
{
return F_8 ( V_5 , 2 * V_449 , V_13 ) ;
}
void F_243 ( struct V_4 * V_5 , unsigned char * V_14 )
{
V_14 [ 0 ] = V_5 -> V_77 ;
V_14 [ 1 ] = V_5 -> V_82 ;
}
void F_244 ( struct V_4 * V_5 , unsigned char * V_14 )
{
F_23 ( V_5 ) ;
F_64 ( V_5 , V_14 [ 0 ] , V_14 [ 1 ] ) ;
F_24 ( V_5 ) ;
}
T_1 F_245 ( struct V_4 * V_5 , const T_1 * V_450 )
{
if ( ( unsigned long ) V_450 == V_5 -> V_76 && V_81 != - 1 )
return V_81 ;
return F_19 ( V_450 ) ;
}
void F_246 ( struct V_4 * V_5 , T_1 V_451 , T_1 * V_450 )
{
F_28 ( V_451 , V_450 ) ;
if ( ( unsigned long ) V_450 == V_5 -> V_76 ) {
V_81 = - 1 ;
F_33 ( V_5 ) ;
}
}
void F_247 ( struct V_4 * V_5 )
{
F_7 ( V_5 ) ;
}
