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
static void F_91 ( const char * V_14 , struct V_192 * V_127 )
{
while ( * V_14 ) {
F_92 ( V_127 , * V_14 , 0 ) ;
V_14 ++ ;
}
F_93 ( V_127 ) ;
}
static void F_94 ( struct V_4 * V_5 , struct V_137 * V_138 )
{
char V_193 [ 40 ] ;
sprintf ( V_193 , L_2 , V_5 -> V_82 + ( V_5 -> V_178 ? V_5 -> V_158 + 1 : 1 ) , V_5 -> V_77 + 1 ) ;
F_91 ( V_193 , V_138 -> V_127 ) ;
}
static inline void F_95 ( struct V_137 * V_138 )
{
F_91 ( L_3 , V_138 -> V_127 ) ;
}
static inline void F_96 ( struct V_137 * V_138 )
{
F_91 ( V_194 , V_138 -> V_127 ) ;
}
void F_97 ( struct V_137 * V_138 , int V_195 , int V_196 , int V_197 )
{
char V_193 [ 8 ] ;
sprintf ( V_193 , L_4 , ( char ) ( ' ' + V_195 ) , ( char ) ( '!' + V_196 ) ,
( char ) ( '!' + V_197 ) ) ;
F_91 ( V_193 , V_138 -> V_127 ) ;
}
int F_98 ( void )
{
return V_99 [ V_100 ] . V_25 -> V_198 ;
}
static void F_99 ( struct V_4 * V_5 , int V_199 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 <= V_5 -> V_182 ; V_79 ++ )
if ( V_5 -> V_200 ) {
switch( V_5 -> V_183 [ V_79 ] ) {
case 1 :
if ( V_199 )
F_100 ( V_5 , V_201 ) ;
else
F_101 ( V_5 , V_201 ) ;
break;
case 3 :
V_5 -> V_202 = V_199 ;
#if 0
vc_resize(deccolm ? 132 : 80, vc->vc_rows);
#endif
break;
case 5 :
if ( V_5 -> V_64 != V_199 ) {
V_5 -> V_64 = V_199 ;
F_27 ( V_5 , 0 , V_5 -> V_72 , 0 ) ;
F_26 ( V_5 ) ;
}
break;
case 6 :
V_5 -> V_178 = V_199 ;
F_77 ( V_5 , 0 , 0 ) ;
break;
case 7 :
V_5 -> V_203 = V_199 ;
break;
case 8 :
if ( V_199 )
F_100 ( V_5 , V_204 ) ;
else
F_101 ( V_5 , V_204 ) ;
break;
case 9 :
V_5 -> V_198 = V_199 ? 1 : 0 ;
break;
case 25 :
V_5 -> V_89 = V_199 ;
break;
case 1000 :
V_5 -> V_198 = V_199 ? 2 : 0 ;
break;
}
} else {
switch( V_5 -> V_183 [ V_79 ] ) {
case 3 :
V_5 -> V_188 = V_199 ;
break;
case 4 :
V_5 -> V_205 = V_199 ;
break;
case 20 :
if ( V_199 )
F_100 ( V_5 , V_206 ) ;
else
F_101 ( V_5 , V_206 ) ;
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
V_5 -> V_207 = V_191 [ V_5 -> V_183 [ 1 ] ] ;
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
V_208 = ( ( V_5 -> V_183 [ 1 ] < 60 ) ? V_5 -> V_183 [ 1 ] : 60 ) * 60 ;
F_103 () ;
break;
case 10 :
if ( V_5 -> V_182 >= 1 )
V_5 -> V_209 = V_5 -> V_183 [ 1 ] ;
else
V_5 -> V_209 = V_210 ;
break;
case 11 :
if ( V_5 -> V_182 >= 1 )
V_5 -> V_211 = ( V_5 -> V_183 [ 1 ] < 2000 ) ?
V_5 -> V_183 [ 1 ] * V_212 / 1000 : 0 ;
else
V_5 -> V_211 = V_213 ;
break;
case 12 :
if ( V_5 -> V_183 [ 1 ] >= 1 && F_46 ( V_5 -> V_183 [ 1 ] - 1 ) )
F_104 ( V_5 -> V_183 [ 1 ] - 1 ) ;
break;
case 13 :
F_103 () ;
break;
case 14 :
V_214 = ( ( V_5 -> V_183 [ 1 ] < 60 ) ? V_5 -> V_183 [ 1 ] : 60 ) * 60 * V_212 ;
break;
case 15 :
F_104 ( V_215 ) ;
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
V_5 -> V_216 = V_5 -> V_77 ;
V_5 -> V_217 = V_5 -> V_82 ;
V_5 -> V_218 = V_5 -> V_60 ;
V_5 -> V_219 = V_5 -> V_65 ;
V_5 -> V_220 = V_5 -> V_62 ;
V_5 -> V_221 = V_5 -> V_61 ;
V_5 -> V_222 = V_5 -> V_63 ;
V_5 -> V_223 = V_5 -> V_185 ;
V_5 -> V_224 = V_5 -> V_59 ;
V_5 -> V_225 = V_5 -> V_186 ;
V_5 -> V_226 = V_5 -> V_187 ;
}
static void F_109 ( struct V_4 * V_5 )
{
F_65 ( V_5 , V_5 -> V_216 , V_5 -> V_217 ) ;
V_5 -> V_60 = V_5 -> V_218 ;
V_5 -> V_65 = V_5 -> V_219 ;
V_5 -> V_62 = V_5 -> V_220 ;
V_5 -> V_61 = V_5 -> V_221 ;
V_5 -> V_63 = V_5 -> V_222 ;
V_5 -> V_185 = V_5 -> V_223 ;
V_5 -> V_59 = V_5 -> V_224 ;
V_5 -> V_186 = V_5 -> V_225 ;
V_5 -> V_187 = V_5 -> V_226 ;
V_5 -> V_184 = F_90 ( V_5 -> V_185 ? V_5 -> V_187 : V_5 -> V_186 , V_5 ) ;
F_26 ( V_5 ) ;
V_5 -> V_78 = 0 ;
}
static void F_110 ( struct V_4 * V_5 , int V_227 )
{
V_5 -> V_158 = 0 ;
V_5 -> V_159 = V_5 -> V_27 ;
V_5 -> V_228 = V_229 ;
V_5 -> V_200 = 0 ;
V_5 -> V_184 = F_90 ( V_230 , V_5 ) ;
V_5 -> V_186 = V_230 ;
V_5 -> V_187 = V_231 ;
V_5 -> V_185 = 0 ;
V_5 -> V_78 = 0 ;
V_5 -> V_198 = 0 ;
V_5 -> V_232 = V_233 ;
V_5 -> V_234 = 0 ;
V_5 -> V_188 = 0 ;
V_5 -> V_189 = 0 ;
V_5 -> V_64 = 0 ;
V_5 -> V_178 = 0 ;
V_5 -> V_203 = 1 ;
V_5 -> V_89 = V_130 ;
V_5 -> V_205 = 0 ;
F_111 ( V_5 -> V_102 ) ;
V_5 -> V_80 = V_235 ;
V_5 -> V_75 = V_5 -> V_119 ;
F_88 ( V_5 ) ;
F_26 ( V_5 ) ;
V_5 -> V_236 [ 0 ] = 0x01010100 ;
V_5 -> V_236 [ 1 ] =
V_5 -> V_236 [ 2 ] =
V_5 -> V_236 [ 3 ] =
V_5 -> V_236 [ 4 ] =
V_5 -> V_236 [ 5 ] =
V_5 -> V_236 [ 6 ] =
V_5 -> V_236 [ 7 ] = 0x01010101 ;
V_5 -> V_209 = V_210 ;
V_5 -> V_211 = V_213 ;
F_65 ( V_5 , 0 , 0 ) ;
F_66 ( V_5 ) ;
if ( V_227 )
F_85 ( V_5 , 2 ) ;
}
static void F_112 ( struct V_137 * V_138 , struct V_4 * V_5 , int V_9 )
{
switch ( V_9 ) {
case 0 :
return;
case 7 :
if ( V_5 -> V_211 )
F_113 ( V_5 -> V_209 , V_5 -> V_211 ) ;
return;
case 8 :
F_83 ( V_5 ) ;
return;
case 9 :
V_5 -> V_76 -= ( V_5 -> V_77 << 1 ) ;
while ( V_5 -> V_77 < V_5 -> V_31 - 1 ) {
V_5 -> V_77 ++ ;
if ( V_5 -> V_236 [ V_5 -> V_77 >> 5 ] & ( 1 << ( V_5 -> V_77 & 31 ) ) )
break;
}
V_5 -> V_76 += ( V_5 -> V_77 << 1 ) ;
F_5 ( V_5 , '\t' ) ;
return;
case 10 : case 11 : case 12 :
F_80 ( V_5 ) ;
if ( ! F_114 ( V_5 , V_206 ) )
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
V_5 -> V_228 = V_229 ;
return;
case 27 :
V_5 -> V_228 = V_237 ;
return;
case 127 :
F_84 ( V_5 ) ;
return;
case 128 + 27 :
V_5 -> V_228 = V_238 ;
return;
}
switch( V_5 -> V_228 ) {
case V_237 :
V_5 -> V_228 = V_229 ;
switch ( V_9 ) {
case '[' :
V_5 -> V_228 = V_238 ;
return;
case ']' :
V_5 -> V_228 = V_239 ;
return;
case '%' :
V_5 -> V_228 = V_240 ;
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
V_5 -> V_236 [ V_5 -> V_77 >> 5 ] |= ( 1 << ( V_5 -> V_77 & 31 ) ) ;
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
V_5 -> V_228 = V_241 ;
return;
case ')' :
V_5 -> V_228 = V_242 ;
return;
case '#' :
V_5 -> V_228 = V_243 ;
return;
case 'c' :
F_110 ( V_5 , 1 ) ;
return;
case '>' :
F_101 ( V_5 , V_244 ) ;
return;
case '=' :
F_100 ( V_5 , V_244 ) ;
return;
}
return;
case V_239 :
if ( V_9 == 'P' ) {
for ( V_5 -> V_182 = 0 ; V_5 -> V_182 < V_245 ; V_5 -> V_182 ++ )
V_5 -> V_183 [ V_5 -> V_182 ] = 0 ;
V_5 -> V_182 = 0 ;
V_5 -> V_228 = V_246 ;
return;
} else if ( V_9 == 'R' ) {
F_115 ( V_5 ) ;
V_5 -> V_228 = V_229 ;
} else
V_5 -> V_228 = V_229 ;
return;
case V_246 :
if ( isxdigit ( V_9 ) ) {
V_5 -> V_183 [ V_5 -> V_182 ++ ] = F_116 ( V_9 ) ;
if ( V_5 -> V_182 == 7 ) {
int V_79 = V_5 -> V_183 [ 0 ] * 3 , V_247 = 1 ;
V_5 -> V_248 [ V_79 ] = 16 * V_5 -> V_183 [ V_247 ++ ] ;
V_5 -> V_248 [ V_79 ++ ] += V_5 -> V_183 [ V_247 ++ ] ;
V_5 -> V_248 [ V_79 ] = 16 * V_5 -> V_183 [ V_247 ++ ] ;
V_5 -> V_248 [ V_79 ++ ] += V_5 -> V_183 [ V_247 ++ ] ;
V_5 -> V_248 [ V_79 ] = 16 * V_5 -> V_183 [ V_247 ++ ] ;
V_5 -> V_248 [ V_79 ] += V_5 -> V_183 [ V_247 ] ;
F_42 ( V_5 ) ;
V_5 -> V_228 = V_229 ;
}
} else
V_5 -> V_228 = V_229 ;
return;
case V_238 :
for ( V_5 -> V_182 = 0 ; V_5 -> V_182 < V_245 ; V_5 -> V_182 ++ )
V_5 -> V_183 [ V_5 -> V_182 ] = 0 ;
V_5 -> V_182 = 0 ;
V_5 -> V_228 = V_249 ;
if ( V_9 == '[' ) {
V_5 -> V_228 = V_250 ;
return;
}
V_5 -> V_200 = ( V_9 == '?' ) ;
if ( V_5 -> V_200 )
return;
case V_249 :
if ( V_9 == ';' && V_5 -> V_182 < V_245 - 1 ) {
V_5 -> V_182 ++ ;
return;
} else if ( V_9 >= '0' && V_9 <= '9' ) {
V_5 -> V_183 [ V_5 -> V_182 ] *= 10 ;
V_5 -> V_183 [ V_5 -> V_182 ] += V_9 - '0' ;
return;
} else
V_5 -> V_228 = V_251 ;
case V_251 :
V_5 -> V_228 = V_229 ;
switch( V_9 ) {
case 'h' :
F_99 ( V_5 , 1 ) ;
return;
case 'l' :
F_99 ( V_5 , 0 ) ;
return;
case 'c' :
if ( V_5 -> V_200 ) {
if ( V_5 -> V_183 [ 0 ] )
V_5 -> V_80 = V_5 -> V_183 [ 0 ] | ( V_5 -> V_183 [ 1 ] << 8 ) | ( V_5 -> V_183 [ 2 ] << 16 ) ;
else
V_5 -> V_80 = V_235 ;
return;
}
break;
case 'm' :
if ( V_5 -> V_200 ) {
F_35 () ;
if ( V_5 -> V_183 [ 0 ] )
V_5 -> V_75 = V_5 -> V_183 [ 0 ] << 8 | V_5 -> V_183 [ 1 ] ;
else
V_5 -> V_75 = V_5 -> V_119 ;
return;
}
break;
case 'n' :
if ( ! V_5 -> V_200 ) {
if ( V_5 -> V_183 [ 0 ] == 5 )
F_95 ( V_138 ) ;
else if ( V_5 -> V_183 [ 0 ] == 6 )
F_94 ( V_5 , V_138 ) ;
}
return;
}
if ( V_5 -> V_200 ) {
V_5 -> V_200 = 0 ;
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
V_5 -> V_236 [ V_5 -> V_77 >> 5 ] &= ~ ( 1 << ( V_5 -> V_77 & 31 ) ) ;
else if ( V_5 -> V_183 [ 0 ] == 3 ) {
V_5 -> V_236 [ 0 ] =
V_5 -> V_236 [ 1 ] =
V_5 -> V_236 [ 2 ] =
V_5 -> V_236 [ 3 ] =
V_5 -> V_236 [ 4 ] =
V_5 -> V_236 [ 5 ] =
V_5 -> V_236 [ 6 ] =
V_5 -> V_236 [ 7 ] = 0 ;
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
case V_240 :
V_5 -> V_228 = V_229 ;
switch ( V_9 ) {
case '@' :
V_5 -> V_232 = 0 ;
return;
case 'G' :
case '8' :
V_5 -> V_232 = 1 ;
return;
}
return;
case V_250 :
V_5 -> V_228 = V_229 ;
return;
case V_243 :
V_5 -> V_228 = V_229 ;
if ( V_9 == '8' ) {
V_5 -> V_32 =
( V_5 -> V_32 & 0xff00 ) | 'E' ;
F_85 ( V_5 , 2 ) ;
V_5 -> V_32 =
( V_5 -> V_32 & 0xff00 ) | ' ' ;
F_17 ( V_5 , V_5 -> V_15 , V_5 -> V_72 / 2 ) ;
}
return;
case V_241 :
if ( V_9 == '0' )
V_5 -> V_186 = V_231 ;
else if ( V_9 == 'B' )
V_5 -> V_186 = V_230 ;
else if ( V_9 == 'U' )
V_5 -> V_186 = V_190 ;
else if ( V_9 == 'K' )
V_5 -> V_186 = V_252 ;
if ( V_5 -> V_185 == 0 )
V_5 -> V_184 = F_90 ( V_5 -> V_186 , V_5 ) ;
V_5 -> V_228 = V_229 ;
return;
case V_242 :
if ( V_9 == '0' )
V_5 -> V_187 = V_231 ;
else if ( V_9 == 'B' )
V_5 -> V_187 = V_230 ;
else if ( V_9 == 'U' )
V_5 -> V_187 = V_190 ;
else if ( V_9 == 'K' )
V_5 -> V_187 = V_252 ;
if ( V_5 -> V_185 == 1 )
V_5 -> V_184 = F_90 ( V_5 -> V_187 , V_5 ) ;
V_5 -> V_228 = V_229 ;
return;
default:
V_5 -> V_228 = V_229 ;
}
}
static int F_118 ( T_4 V_253 , const struct V_254 * V_255 , int V_256 )
{
int F_64 = 0 ;
int V_257 ;
if ( V_253 < V_255 [ 0 ] . V_258 || V_253 > V_255 [ V_256 ] . V_259 )
return 0 ;
while ( V_256 >= F_64 ) {
V_257 = ( F_64 + V_256 ) / 2 ;
if ( V_253 > V_255 [ V_257 ] . V_259 )
F_64 = V_257 + 1 ;
else if ( V_253 < V_255 [ V_257 ] . V_258 )
V_256 = V_257 - 1 ;
else
return 1 ;
}
return 0 ;
}
static int F_119 ( T_4 V_253 )
{
static const struct V_254 V_260 [] = {
{ 0x1100 , 0x115F } , { 0x2329 , 0x232A } , { 0x2E80 , 0x303E } ,
{ 0x3040 , 0xA4CF } , { 0xAC00 , 0xD7A3 } , { 0xF900 , 0xFAFF } ,
{ 0xFE10 , 0xFE19 } , { 0xFE30 , 0xFE6F } , { 0xFF00 , 0xFF60 } ,
{ 0xFFE0 , 0xFFE6 } , { 0x20000 , 0x2FFFD } , { 0x30000 , 0x3FFFD }
} ;
return F_118 ( V_253 , V_260 , F_120 ( V_260 ) - 1 ) ;
}
static int F_121 ( struct V_137 * V_138 , const unsigned char * V_193 , int V_36 )
{
#ifdef F_18
#define F_122 do { } while(0);
#else
#define F_122 if (draw_x >= 0) { \
vc->vc_sw->con_putcs(vc, (u16 *)draw_from, (u16 *)draw_to - (u16 *)draw_from, vc->vc_y, draw_x); \
draw_x = -1; \
}
#endif
int V_9 , V_261 , V_262 , V_263 = 0 , V_264 = - 1 ;
unsigned int V_120 ;
unsigned long V_265 = 0 , V_266 = 0 ;
struct V_4 * V_5 ;
unsigned char V_58 ;
struct V_7 V_8 ;
T_5 V_267 ;
T_5 V_268 ;
T_5 V_132 ;
T_1 V_269 , V_270 ;
if ( F_123 () )
return V_36 ;
F_124 () ;
F_72 () ;
V_5 = V_138 -> V_168 ;
if ( V_5 == NULL ) {
F_125 ( V_271 L_5 ) ;
F_73 () ;
return 0 ;
}
V_120 = V_5 -> V_102 ;
if ( ! F_46 ( V_120 ) ) {
F_126 ( L_6 , V_120 + 1 ) ;
F_73 () ;
return 0 ;
}
V_269 = V_5 -> V_57 ;
V_270 = V_269 ? 0x1ff : 0xff ;
if ( F_36 ( V_5 ) )
F_23 ( V_5 ) ;
V_8 . V_5 = V_5 ;
while ( ! V_138 -> V_272 && V_36 ) {
int V_273 = * V_193 ;
V_9 = V_273 ;
V_193 ++ ;
V_263 ++ ;
V_36 -- ;
V_267 = 0 ;
V_268 = 0 ;
V_132 = 1 ;
if ( V_5 -> V_228 != V_229 ) {
V_261 = V_9 ;
} else if ( V_5 -> V_232 && ! V_5 -> V_188 ) {
V_274:
if ( ( V_9 & 0xc0 ) == 0x80 ) {
static const T_4 V_275 [] = { 0x0000007f , 0x000007ff , 0x0000ffff , 0x001fffff , 0x03ffffff , 0x7fffffff } ;
if ( V_5 -> V_234 ) {
V_5 -> V_276 = ( V_5 -> V_276 << 6 ) | ( V_9 & 0x3f ) ;
V_5 -> V_182 ++ ;
if ( -- V_5 -> V_234 ) {
continue;
}
V_9 = V_5 -> V_276 ;
if ( V_9 <= V_275 [ V_5 -> V_182 - 1 ] ||
V_9 > V_275 [ V_5 -> V_182 ] )
V_9 = 0xfffd ;
} else {
V_5 -> V_234 = 0 ;
V_9 = 0xfffd ;
}
} else {
if ( V_5 -> V_234 ) {
V_267 = 1 ;
V_5 -> V_234 = 0 ;
V_9 = 0xfffd ;
} else if ( V_9 > 0x7f ) {
V_5 -> V_182 = 0 ;
if ( ( V_9 & 0xe0 ) == 0xc0 ) {
V_5 -> V_234 = 1 ;
V_5 -> V_276 = ( V_9 & 0x1f ) ;
} else if ( ( V_9 & 0xf0 ) == 0xe0 ) {
V_5 -> V_234 = 2 ;
V_5 -> V_276 = ( V_9 & 0x0f ) ;
} else if ( ( V_9 & 0xf8 ) == 0xf0 ) {
V_5 -> V_234 = 3 ;
V_5 -> V_276 = ( V_9 & 0x07 ) ;
} else if ( ( V_9 & 0xfc ) == 0xf8 ) {
V_5 -> V_234 = 4 ;
V_5 -> V_276 = ( V_9 & 0x03 ) ;
} else if ( ( V_9 & 0xfe ) == 0xfc ) {
V_5 -> V_234 = 5 ;
V_5 -> V_276 = ( V_9 & 0x01 ) ;
} else {
V_9 = 0xfffd ;
}
if ( V_5 -> V_234 ) {
continue;
}
}
}
if ( ( V_9 >= 0xd800 && V_9 <= 0xdfff ) || V_9 == 0xfffe || V_9 == 0xffff )
V_9 = 0xfffd ;
V_261 = V_9 ;
} else {
V_261 = V_184 ( V_5 , V_9 ) ;
}
V_8 . V_9 = V_261 ;
if ( F_6 ( & V_3 , V_277 ,
& V_8 ) == V_278 )
continue;
V_262 = V_261 && ( V_9 >= 32 ||
! ( V_5 -> V_188 ? ( V_279 >> V_9 ) & 1 :
V_5 -> V_232 || ( ( V_280 >> V_9 ) & 1 ) ) )
&& ( V_9 != 127 || V_5 -> V_188 )
&& ( V_9 != 128 + 27 ) ;
if ( V_5 -> V_228 == V_229 && V_262 ) {
if ( V_5 -> V_232 && ! V_5 -> V_188 ) {
if ( F_119 ( V_9 ) )
V_132 = 2 ;
}
V_261 = F_127 ( V_5 , V_261 ) ;
if ( V_261 & ~ V_270 ) {
if ( V_261 == - 1 || V_261 == - 2 ) {
continue;
}
if ( ( ! ( V_5 -> V_232 && ! V_5 -> V_188 ) || V_9 < 128 ) && ! ( V_9 & ~ V_270 ) ) {
V_261 = V_9 ;
} else {
V_261 = F_127 ( V_5 , 0xfffd ) ;
if ( V_261 < 0 ) {
V_268 = 1 ;
V_261 = F_127 ( V_5 , '?' ) ;
if ( V_261 < 0 ) V_261 = '?' ;
}
}
}
if ( ! V_268 ) {
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
if ( V_5 -> V_78 || V_5 -> V_205 )
F_122
if ( V_5 -> V_78 ) {
F_82 ( V_5 ) ;
F_80 ( V_5 ) ;
}
if ( V_5 -> V_205 )
F_30 ( V_5 , 1 ) ;
F_28 ( V_269 ?
( ( V_58 << 8 ) & ~ V_269 ) + ( ( V_261 & 0x100 ) ? V_269 : 0 ) + ( V_261 & 0xff ) :
( V_58 << 8 ) + V_261 ,
( T_1 * ) V_5 -> V_76 ) ;
if ( F_22 ( V_5 ) && V_264 < 0 ) {
V_264 = V_5 -> V_77 ;
V_265 = V_5 -> V_76 ;
}
if ( V_5 -> V_77 == V_5 -> V_31 - 1 ) {
V_5 -> V_78 = V_5 -> V_203 ;
V_266 = V_5 -> V_76 + 2 ;
} else {
V_5 -> V_77 ++ ;
V_266 = ( V_5 -> V_76 += 2 ) ;
}
if ( ! -- V_132 ) break;
V_261 = F_127 ( V_5 , ' ' ) ;
if ( V_261 < 0 ) V_261 = ' ' ;
}
F_5 ( V_5 , V_9 ) ;
if ( V_268 ) {
F_122
}
if ( V_267 ) {
V_267 = 0 ;
V_268 = 0 ;
V_132 = 1 ;
V_9 = V_273 ;
goto V_274;
}
continue;
}
F_122
F_112 ( V_138 , V_5 , V_273 ) ;
}
F_122
F_128 ();
F_73 () ;
F_7 ( V_5 ) ;
return V_263 ;
#undef F_122
}
static void F_129 ( struct V_281 * V_282 )
{
F_72 () ;
if ( V_283 >= 0 ) {
if ( V_283 != V_100 &&
F_46 ( V_283 ) ) {
F_23 ( V_99 [ V_100 ] . V_25 ) ;
F_130 ( V_99 [ V_283 ] . V_25 ) ;
}
V_283 = - 1 ;
}
if ( V_284 ) {
V_284 = 0 ;
F_103 () ;
}
if ( V_20 ) {
struct V_4 * V_5 = V_99 [ V_100 ] . V_25 ;
F_35 () ;
if ( V_5 -> V_87 == V_285 )
V_5 -> V_16 -> V_286 ( V_5 , V_20 ) ;
V_20 = 0 ;
}
if ( V_287 ) {
F_131 ( 0 ) ;
V_287 = 0 ;
}
F_7 ( V_99 [ V_100 ] . V_25 ) ;
F_73 () ;
}
int F_104 ( int V_24 )
{
struct V_4 * V_5 = V_99 [ V_100 ] . V_25 ;
if ( ! F_46 ( V_24 ) || V_288 ||
( V_5 -> V_289 . V_290 == V_291 && V_5 -> V_87 == V_88 ) ) {
return - V_156 ;
}
V_283 = V_24 ;
F_10 () ;
return 0 ;
}
int F_132 ( int V_74 )
{
static int V_292 ;
if ( V_74 != - 1 )
return F_133 ( & V_292 , V_74 ) ;
else
return V_292 ;
}
static void F_134 ( struct V_293 * V_294 , const char * V_23 , unsigned V_36 )
{
struct V_4 * V_5 = V_99 [ V_100 ] . V_25 ;
unsigned char V_9 ;
static F_135 ( V_295 ) ;
const T_6 * V_35 ;
T_6 V_67 = 0 ;
T_6 V_296 ;
int V_297 ;
if ( ! V_298 )
return;
if ( ! F_136 ( & V_295 ) )
return;
V_297 = F_137 () ;
if ( V_297 && F_46 ( V_297 - 1 ) )
V_5 = V_99 [ V_297 - 1 ] . V_25 ;
V_296 = V_5 -> V_77 ;
if ( ! F_46 ( V_100 ) ) {
goto V_299;
}
if ( V_5 -> V_87 != V_285 && ! F_43 ( V_5 ) )
goto V_299;
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
V_296 = V_5 -> V_77 ;
continue;
}
if ( V_9 != 13 )
F_80 ( V_5 ) ;
F_82 ( V_5 ) ;
V_35 = ( T_6 * ) V_5 -> V_76 ;
V_296 = V_5 -> V_77 ;
if ( V_9 == 10 || V_9 == 13 )
continue;
}
F_28 ( ( V_5 -> V_58 << 8 ) + V_9 , ( unsigned short * ) V_5 -> V_76 ) ;
F_5 ( V_5 , V_9 ) ;
V_67 ++ ;
if ( V_296 == V_5 -> V_31 - 1 ) {
V_5 -> V_78 = 1 ;
continue;
}
V_5 -> V_76 += 2 ;
V_296 ++ ;
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
V_299:
F_138 ( & V_295 ) ;
}
static struct V_300 * F_139 ( struct V_293 * V_9 , int * V_301 )
{
* V_301 = V_9 -> V_301 ? V_9 -> V_301 - 1 : V_100 ;
return V_302 ;
}
int F_140 ( struct V_137 * V_138 , unsigned long V_303 )
{
char type , V_304 ;
char T_7 * V_14 = ( char T_7 * ) V_303 ;
int V_19 ;
int V_169 ;
if ( V_305 -> signal -> V_138 != V_138 && ! F_52 ( V_306 ) )
return - V_124 ;
if ( F_141 ( type , V_14 ) )
return - V_307 ;
V_169 = 0 ;
switch ( type )
{
case V_308 :
F_72 () ;
V_169 = F_142 ( (struct V_309 T_7 * ) ( V_14 + 1 ) , V_138 ) ;
F_73 () ;
break;
case V_310 :
V_169 = F_143 ( V_138 ) ;
break;
case V_311 :
F_72 () ;
F_144 () ;
F_73 () ;
break;
case V_312 :
F_72 () ;
V_169 = F_145 ( V_14 ) ;
F_73 () ;
break;
case V_313 :
V_304 = F_146 () ;
V_169 = F_147 ( V_304 , V_14 ) ;
break;
case V_314 :
F_72 () ;
V_304 = F_98 () ;
F_73 () ;
V_169 = F_147 ( V_304 , V_14 ) ;
break;
case V_315 :
F_72 () ;
V_169 = F_148 ( V_14 ) ;
F_73 () ;
break;
case V_316 :
V_304 = F_137 () ;
V_169 = F_147 ( V_304 , V_14 ) ;
break;
case V_317 :
if ( ! F_52 ( V_306 ) ) {
V_169 = - V_124 ;
} else {
if ( F_141 ( V_304 , V_14 + 1 ) )
V_169 = - V_307 ;
else
F_132 ( V_304 ) ;
}
break;
case V_318 :
V_169 = V_100 ;
break;
case V_319 :
if ( F_141 ( V_19 , ( V_320 T_7 * ) ( V_14 + 4 ) ) ) {
V_169 = - V_307 ;
} else {
F_72 () ;
F_79 ( V_99 [ V_100 ] . V_25 , V_19 ) ;
F_73 () ;
V_169 = 0 ;
}
break;
case V_321 :
F_72 () ;
V_322 = 1 ;
F_131 ( 0 ) ;
F_73 () ;
break;
case V_323 :
V_169 = V_86 ;
break;
default:
V_169 = - V_156 ;
break;
}
return V_169 ;
}
static int F_149 ( struct V_137 * V_138 , const unsigned char * V_193 , int V_36 )
{
int V_324 ;
V_324 = F_121 ( V_138 , V_193 , V_36 ) ;
F_150 ( V_138 ) ;
return V_324 ;
}
static int F_151 ( struct V_137 * V_138 , unsigned char V_325 )
{
if ( F_123 () )
return 0 ;
return F_121 ( V_138 , & V_325 , 1 ) ;
}
static int F_152 ( struct V_137 * V_138 )
{
if ( V_138 -> V_272 )
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
F_156 ( & V_5 -> V_326 ) ;
}
static void F_157 ( struct V_137 * V_138 )
{
int V_327 ;
if ( ! V_138 )
return;
V_327 = V_138 -> V_301 ;
if ( ! F_46 ( V_327 ) )
return;
F_158 ( V_327 ) ;
}
static void F_159 ( struct V_137 * V_138 )
{
int V_327 ;
if ( ! V_138 )
return;
V_327 = V_138 -> V_301 ;
if ( ! F_46 ( V_327 ) )
return;
F_160 ( V_327 ) ;
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
static int F_161 ( struct V_300 * V_328 , struct V_137 * V_138 )
{
unsigned int V_120 = V_138 -> V_301 ;
struct V_4 * V_5 ;
int V_169 ;
F_72 () ;
V_169 = F_51 ( V_120 ) ;
if ( V_169 )
goto V_329;
V_5 = V_99 [ V_120 ] . V_25 ;
if ( V_5 -> V_127 . V_138 ) {
V_169 = - V_330 ;
goto V_329;
}
V_169 = F_162 ( & V_5 -> V_127 , V_328 , V_138 ) ;
if ( V_169 )
goto V_329;
V_138 -> V_168 = V_5 ;
V_5 -> V_127 . V_138 = V_138 ;
if ( ! V_138 -> V_160 . V_162 && ! V_138 -> V_160 . V_163 ) {
V_138 -> V_160 . V_162 = V_99 [ V_120 ] . V_25 -> V_27 ;
V_138 -> V_160 . V_163 = V_99 [ V_120 ] . V_25 -> V_31 ;
}
if ( V_5 -> V_232 )
V_138 -> V_331 . V_332 |= V_333 ;
else
V_138 -> V_331 . V_332 &= ~ V_333 ;
V_329:
F_73 () ;
return V_169 ;
}
static int F_163 ( struct V_137 * V_138 , struct V_334 * V_335 )
{
return 0 ;
}
static void F_164 ( struct V_137 * V_138 , struct V_334 * V_335 )
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
unsigned int V_139 , int V_227 )
{
int V_247 , V_336 ;
V_5 -> V_31 = V_139 ;
V_5 -> V_27 = V_167 ;
V_5 -> V_30 = V_139 << 1 ;
V_5 -> V_72 = V_5 -> V_27 * V_5 -> V_30 ;
F_37 ( V_5 ) ;
V_5 -> V_76 = V_5 -> V_15 ;
F_167 ( V_5 ) ;
for ( V_247 = V_336 = 0 ; V_247 < 16 ; V_247 ++ ) {
V_5 -> V_248 [ V_336 ++ ] = V_337 [ V_247 ] ;
V_5 -> V_248 [ V_336 ++ ] = V_338 [ V_247 ] ;
V_5 -> V_248 [ V_336 ++ ] = V_339 [ V_247 ] ;
}
V_5 -> V_181 = 0x07 ;
V_5 -> V_56 = V_340 ;
V_5 -> V_55 = V_341 ;
V_5 -> V_207 = 0x08 ;
F_168 ( & V_5 -> V_326 ) ;
F_110 ( V_5 , V_227 ) ;
}
static int T_8 V_118 ( void )
{
const char * V_342 = NULL ;
struct V_4 * V_5 ;
unsigned int V_120 = 0 , V_79 ;
F_72 () ;
if ( V_112 )
V_342 = V_112 -> V_343 () ;
if ( ! V_342 ) {
V_100 = 0 ;
F_73 () ;
return 0 ;
}
for ( V_79 = 0 ; V_79 < V_344 ; V_79 ++ ) {
struct V_345 * V_345 = & V_346 [ V_79 ] ;
if ( V_345 -> V_347 == NULL ) {
V_345 -> V_347 = V_112 ;
V_345 -> V_348 = V_342 ;
V_345 -> V_349 = V_350 ;
V_345 -> V_258 = 0 ;
V_345 -> V_259 = V_108 - 1 ;
break;
}
}
for ( V_79 = 0 ; V_79 < V_108 ; V_79 ++ )
V_113 [ V_79 ] = V_112 ;
if ( V_208 ) {
V_351 = V_352 ;
F_169 ( & V_353 , V_354 + ( V_208 * V_212 ) ) ;
}
for ( V_120 = 0 ; V_120 < V_173 ; V_120 ++ ) {
V_99 [ V_120 ] . V_25 = V_5 = F_53 ( sizeof( struct V_4 ) , V_355 ) ;
F_55 ( & V_99 [ V_120 ] . V_128 , V_129 ) ;
F_54 ( & V_5 -> V_127 ) ;
F_47 ( V_5 , V_120 , 1 ) ;
V_5 -> V_92 = F_53 ( V_5 -> V_72 , V_355 ) ;
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
V_342 , V_5 -> V_31 , V_5 -> V_27 ) ;
V_298 = 1 ;
F_73 () ;
#ifdef F_171
F_172 ( & V_356 ) ;
#endif
return 0 ;
}
static T_9 F_173 ( struct V_357 * V_358 ,
struct V_359 * V_360 , char * V_193 )
{
return sprintf ( V_193 , L_10 , V_100 + 1 ) ;
}
int T_8 F_174 ( const struct V_361 * V_362 )
{
F_175 ( & V_363 , V_362 ) ;
if ( F_176 ( & V_363 , F_177 ( V_364 , 0 ) , 1 ) ||
F_178 ( F_177 ( V_364 , 0 ) , 1 , L_11 ) < 0 )
F_179 ( L_12 ) ;
V_103 = F_180 ( V_365 , NULL , F_177 ( V_364 , 0 ) , NULL , L_13 ) ;
if ( F_181 ( V_103 ) )
V_103 = NULL ;
else
F_182 ( F_183 ( V_103 , & V_366 ) < 0 ) ;
F_184 () ;
V_302 = F_185 ( V_108 ) ;
if ( ! V_302 )
F_179 ( L_14 ) ;
V_302 -> V_367 = L_15 ;
V_302 -> V_368 = 1 ;
V_302 -> V_369 = V_364 ;
V_302 -> V_370 = 1 ;
V_302 -> type = V_371 ;
V_302 -> V_372 = V_373 ;
if ( V_233 )
V_302 -> V_372 . V_332 |= V_333 ;
V_302 -> V_374 = V_375 | V_376 ;
F_186 ( V_302 , & V_377 ) ;
if ( F_187 ( V_302 ) )
F_179 ( L_16 ) ;
F_188 () ;
F_189 () ;
#ifdef F_190
F_191 () ;
#endif
return 0 ;
}
static int F_192 ( const struct V_378 * V_379 , int V_258 , int V_259 ,
int V_380 )
{
struct V_381 * V_111 = V_379 -> V_111 ;
const char * V_348 = NULL ;
struct V_345 * V_345 ;
int V_79 , V_247 = - 1 , V_336 = - 1 , V_324 = - V_382 ;
if ( ! F_193 ( V_111 ) )
return - V_382 ;
F_21 () ;
for ( V_79 = 0 ; V_79 < V_344 ; V_79 ++ ) {
V_345 = & V_346 [ V_79 ] ;
if ( V_345 -> V_347 == V_379 ) {
V_348 = V_345 -> V_348 ;
V_324 = 0 ;
break;
}
}
if ( V_324 )
goto V_135;
if ( ! ( V_345 -> V_349 & V_350 ) ) {
V_379 -> V_343 () ;
V_345 -> V_349 |= V_350 ;
}
if ( V_380 ) {
if ( V_112 )
F_48 ( V_112 -> V_111 ) ;
F_50 ( V_111 ) ;
V_112 = V_379 ;
}
V_258 = V_256 ( V_258 , V_345 -> V_258 ) ;
V_259 = F_64 ( V_259 , V_345 -> V_259 ) ;
for ( V_79 = V_258 ; V_79 <= V_259 ; V_79 ++ ) {
int V_106 ;
struct V_4 * V_5 = V_99 [ V_79 ] . V_25 ;
if ( V_113 [ V_79 ] )
F_48 ( V_113 [ V_79 ] -> V_111 ) ;
F_50 ( V_111 ) ;
V_113 [ V_79 ] = V_379 ;
if ( ! V_5 || ! V_5 -> V_16 )
continue;
V_247 = V_79 ;
if ( F_13 ( V_5 ) ) {
V_336 = V_79 ;
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
if ( ! V_380 )
F_125 ( L_18 , V_258 + 1 , V_259 + 1 ) ;
if ( V_247 >= 0 ) {
struct V_4 * V_5 = V_99 [ V_247 ] . V_25 ;
F_125 ( L_19 ,
V_5 -> V_54 ? L_8 : L_9 ,
V_348 , V_5 -> V_31 , V_5 -> V_27 ) ;
if ( V_336 >= 0 ) {
V_5 = V_99 [ V_336 ] . V_25 ;
F_68 ( V_5 ) ;
}
} else
F_125 ( L_20 , V_348 ) ;
V_324 = 0 ;
V_135:
F_48 ( V_111 ) ;
return V_324 ;
}
static int F_194 ( const struct V_378 * V_379 , int V_258 , int V_259 ,
int V_380 )
{
int V_169 ;
F_72 () ;
V_169 = F_192 ( V_379 , V_258 , V_259 , V_380 ) ;
F_73 () ;
return V_169 ;
}
static int F_195 ( const struct V_378 * V_379 , int V_258 , int V_259 )
{
int V_79 , V_324 = 0 ;
for ( V_79 = V_258 ; V_79 <= V_259 ; V_79 ++ ) {
struct V_4 * V_5 = V_99 [ V_79 ] . V_25 ;
if ( V_5 && V_5 -> V_87 == V_88 ) {
V_324 = 1 ;
break;
}
}
return V_324 ;
}
int F_196 ( const struct V_378 * V_379 , int V_258 , int V_259 , int V_380 )
{
int V_324 ;
F_72 () ;
V_324 = F_197 ( V_379 , V_258 , V_259 , V_380 ) ;
F_73 () ;
return V_324 ;
}
int F_197 ( const struct V_378 * V_379 , int V_258 , int V_259 , int V_380 )
{
struct V_381 * V_111 = V_379 -> V_111 ;
const struct V_378 * V_383 = NULL ;
struct V_345 * V_345 = NULL , * V_384 = NULL ;
int V_79 , V_324 = - V_382 ;
if ( ! F_193 ( V_111 ) )
return - V_382 ;
F_21 () ;
for ( V_79 = 0 ; V_79 < V_344 ; V_79 ++ ) {
V_345 = & V_346 [ V_79 ] ;
if ( V_345 -> V_347 == V_379 &&
V_345 -> V_349 & V_385 ) {
V_324 = 0 ;
break;
}
}
if ( V_324 )
goto V_135;
V_324 = - V_382 ;
for ( V_79 = 0 ; V_79 < V_344 ; V_79 ++ ) {
V_384 = & V_346 [ V_79 ] ;
if ( V_384 -> V_347 &&
! ( V_384 -> V_349 & V_385 ) ) {
V_383 = V_384 -> V_347 ;
V_324 = 0 ;
break;
}
}
if ( V_324 )
goto V_135;
if ( ! F_198 ( V_379 ) )
goto V_135;
V_258 = V_256 ( V_258 , V_345 -> V_258 ) ;
V_259 = F_64 ( V_259 , V_345 -> V_259 ) ;
for ( V_79 = V_258 ; V_79 <= V_259 ; V_79 ++ ) {
if ( V_113 [ V_79 ] == V_379 ) {
F_48 ( V_379 -> V_111 ) ;
V_113 [ V_79 ] = NULL ;
}
}
if ( ! F_198 ( V_383 ) ) {
const struct V_378 * V_386 = V_112 ;
V_383 -> V_343 () ;
V_384 -> V_349 |= V_350 ;
V_112 = V_386 ;
}
if ( ! F_198 ( V_379 ) )
V_345 -> V_349 &= ~ V_350 ;
F_192 ( V_383 , V_258 , V_259 , V_380 ) ;
V_135:
F_48 ( V_111 ) ;
return V_324 ;
}
static int F_199 ( struct V_345 * V_347 )
{
const struct V_378 * V_383 = NULL , * V_379 = NULL ;
int V_79 , V_387 = 1 , V_258 = - 1 , V_259 = - 1 , V_380 = 0 ;
if ( ! V_347 -> V_347 || ! ( V_347 -> V_349 & V_385 ) ||
F_195 ( V_347 -> V_347 , V_347 -> V_258 , V_347 -> V_259 ) )
goto V_135;
V_379 = V_347 -> V_347 ;
for ( V_79 = 0 ; V_79 < V_344 ; V_79 ++ ) {
struct V_345 * V_347 = & V_346 [ V_79 ] ;
if ( V_347 -> V_347 && ! ( V_347 -> V_349 & V_385 ) ) {
V_383 = V_347 -> V_347 ;
break;
}
}
if ( ! V_383 )
goto V_135;
while ( V_387 ) {
V_387 = 0 ;
for ( V_79 = V_347 -> V_258 ; V_79 <= V_347 -> V_259 ; V_79 ++ ) {
if ( V_113 [ V_79 ] == V_383 ) {
if ( V_258 == - 1 )
V_258 = V_79 ;
V_259 = V_79 ;
V_387 = 1 ;
} else if ( V_258 != - 1 )
break;
}
if ( V_258 == 0 && V_259 == V_108 - 1 )
V_380 = 1 ;
if ( V_258 != - 1 )
F_194 ( V_379 , V_258 , V_259 , V_380 ) ;
V_258 = - 1 ;
V_259 = - 1 ;
V_380 = 0 ;
}
V_135:
return 0 ;
}
static int F_200 ( struct V_345 * V_347 )
{
const struct V_378 * V_379 = NULL ;
int V_79 , V_387 = 1 , V_258 = - 1 , V_259 = - 1 , V_380 = 0 ;
if ( ! V_347 -> V_347 || ! ( V_347 -> V_349 & V_385 ) ||
F_195 ( V_347 -> V_347 , V_347 -> V_258 , V_347 -> V_259 ) )
goto V_135;
V_379 = V_347 -> V_347 ;
while ( V_387 ) {
V_387 = 0 ;
for ( V_79 = V_347 -> V_258 ; V_79 <= V_347 -> V_259 ; V_79 ++ ) {
if ( V_113 [ V_79 ] == V_379 ) {
if ( V_258 == - 1 )
V_258 = V_79 ;
V_259 = V_79 ;
V_387 = 1 ;
} else if ( V_258 != - 1 )
break;
}
if ( V_258 == 0 && V_259 == V_108 - 1 )
V_380 = 1 ;
if ( V_258 != - 1 )
F_196 ( V_379 , V_258 , V_259 , V_380 ) ;
V_258 = - 1 ;
V_259 = - 1 ;
V_380 = 0 ;
}
V_135:
return 0 ;
}
static inline int F_199 ( struct V_345 * V_347 )
{
return 0 ;
}
static inline int F_200 ( struct V_345 * V_347 )
{
return 0 ;
}
static T_9 F_201 ( struct V_357 * V_358 , struct V_359 * V_360 ,
const char * V_193 , T_10 V_36 )
{
struct V_345 * V_347 = F_202 ( V_358 ) ;
int V_388 = F_203 ( V_193 , NULL , 0 ) ;
if ( V_388 )
F_199 ( V_347 ) ;
else
F_200 ( V_347 ) ;
return V_36 ;
}
static T_9 F_204 ( struct V_357 * V_358 , struct V_359 * V_360 ,
char * V_193 )
{
struct V_345 * V_347 = F_202 ( V_358 ) ;
int V_388 = F_198 ( V_347 -> V_347 ) ;
return snprintf ( V_193 , V_389 , L_21 , V_388 ) ;
}
static T_9 F_205 ( struct V_357 * V_358 , struct V_359 * V_360 ,
char * V_193 )
{
struct V_345 * V_347 = F_202 ( V_358 ) ;
return snprintf ( V_193 , V_389 , L_22 ,
( V_347 -> V_349 & V_385 ) ? L_23 : L_24 ,
V_347 -> V_348 ) ;
}
static int F_206 ( struct V_345 * V_347 )
{
int V_79 ;
int error = 0 ;
V_347 -> V_349 |= V_390 ;
F_207 ( V_347 -> V_358 , V_347 ) ;
for ( V_79 = 0 ; V_79 < F_120 ( V_391 ) ; V_79 ++ ) {
error = F_183 ( V_347 -> V_358 , & V_391 [ V_79 ] ) ;
if ( error )
break;
}
if ( error ) {
while ( -- V_79 >= 0 )
F_208 ( V_347 -> V_358 , & V_391 [ V_79 ] ) ;
V_347 -> V_349 &= ~ V_390 ;
}
return error ;
}
static void F_209 ( struct V_345 * V_347 )
{
int V_79 ;
if ( V_347 -> V_349 & V_390 ) {
for ( V_79 = 0 ; V_79 < F_120 ( V_391 ) ; V_79 ++ )
F_208 ( V_347 -> V_358 , & V_391 [ V_79 ] ) ;
V_347 -> V_349 &= ~ V_390 ;
}
}
int F_198 ( const struct V_378 * V_379 )
{
int V_79 , V_392 = 0 ;
for ( V_79 = 0 ; V_79 < V_108 ; V_79 ++ ) {
if ( V_113 [ V_79 ] == V_379 ) {
V_392 = 1 ;
break;
}
}
return V_392 ;
}
int F_210 ( struct V_4 * V_5 )
{
int V_169 = 0 ;
V_393 = V_100 ;
V_394 = V_215 ;
V_395 = V_283 ;
V_396 = V_5 -> V_87 ;
V_397 = V_86 ;
V_5 -> V_87 = V_285 ;
V_86 = 0 ;
if ( V_5 -> V_16 -> F_210 )
V_169 = V_5 -> V_16 -> F_210 ( V_5 ) ;
#ifdef F_211
if ( V_5 -> V_27 < 999 ) {
int V_398 ;
char V_399 [ 4 ] ;
const char * V_400 [ 3 ] = {
L_25 ,
L_26 ,
V_399 ,
} ;
if ( F_212 ( V_400 [ 0 ] , & V_398 ) ) {
snprintf ( V_399 , 4 , L_27 , V_5 -> V_27 ) ;
F_213 ( 2 , V_400 ) ;
}
}
if ( V_5 -> V_31 < 999 ) {
int V_401 ;
char V_139 [ 4 ] ;
const char * V_400 [ 3 ] = {
L_25 ,
L_28 ,
V_139 ,
} ;
if ( F_212 ( V_400 [ 0 ] , & V_401 ) ) {
snprintf ( V_139 , 4 , L_27 , V_5 -> V_31 ) ;
F_213 ( 2 , V_400 ) ;
}
}
#endif
return V_169 ;
}
int F_214 ( void )
{
struct V_4 * V_5 ;
int V_169 = 0 ;
V_100 = V_393 ;
V_215 = V_394 ;
V_283 = V_395 ;
V_86 = V_397 ;
V_99 [ V_100 ] . V_25 -> V_87 = V_396 ;
V_5 = V_99 [ V_100 ] . V_25 ;
if ( V_5 -> V_16 -> F_214 )
V_169 = V_5 -> V_16 -> F_214 ( V_5 ) ;
return V_169 ;
}
static int F_215 ( const struct V_378 * V_379 , int V_258 , int V_259 )
{
struct V_381 * V_111 = V_379 -> V_111 ;
struct V_345 * V_345 ;
const char * V_348 ;
int V_79 , V_324 = 0 ;
F_21 () ;
if ( ! F_193 ( V_111 ) )
return - V_382 ;
for ( V_79 = 0 ; V_79 < V_344 ; V_79 ++ ) {
V_345 = & V_346 [ V_79 ] ;
if ( V_345 -> V_347 == V_379 )
V_324 = - V_402 ;
}
if ( V_324 )
goto V_135;
V_348 = V_379 -> V_343 () ;
if ( ! V_348 )
goto V_135;
V_324 = - V_156 ;
for ( V_79 = 0 ; V_79 < V_344 ; V_79 ++ ) {
V_345 = & V_346 [ V_79 ] ;
if ( V_345 -> V_347 == NULL ) {
V_345 -> V_347 = V_379 ;
V_345 -> V_348 = V_348 ;
V_345 -> V_403 = V_79 ;
V_345 -> V_349 = V_385 |
V_350 ;
V_345 -> V_258 = V_258 ;
V_345 -> V_259 = V_259 ;
V_324 = 0 ;
break;
}
}
if ( V_324 )
goto V_135;
V_345 -> V_358 = F_180 ( V_404 , NULL ,
F_177 ( 0 , V_345 -> V_403 ) ,
NULL , L_29 ,
V_345 -> V_403 ) ;
if ( F_181 ( V_345 -> V_358 ) ) {
F_125 ( V_405 L_30
L_31 , V_345 -> V_348 ,
F_216 ( V_345 -> V_358 ) ) ;
V_345 -> V_358 = NULL ;
} else {
F_206 ( V_345 ) ;
}
V_135:
F_48 ( V_111 ) ;
return V_324 ;
}
int F_217 ( const struct V_378 * V_379 , int V_258 , int V_259 )
{
int V_324 ;
F_72 () ;
V_324 = F_215 ( V_379 , V_258 , V_259 ) ;
F_73 () ;
return V_324 ;
}
int F_218 ( const struct V_378 * V_379 )
{
int V_324 ;
F_72 () ;
V_324 = F_219 ( V_379 ) ;
F_73 () ;
return V_324 ;
}
int F_219 ( const struct V_378 * V_379 )
{
int V_79 , V_324 = - V_382 ;
if ( F_198 ( V_379 ) )
goto V_135;
for ( V_79 = 0 ; V_79 < V_344 ; V_79 ++ ) {
struct V_345 * V_345 = & V_346 [ V_79 ] ;
if ( V_345 -> V_347 == V_379 &&
V_345 -> V_349 & V_385 ) {
F_209 ( V_345 ) ;
F_220 ( V_404 ,
F_177 ( 0 , V_345 -> V_403 ) ) ;
V_345 -> V_347 = NULL ;
V_345 -> V_348 = NULL ;
V_345 -> V_358 = NULL ;
V_345 -> V_403 = 0 ;
V_345 -> V_349 = 0 ;
V_345 -> V_258 = 0 ;
V_345 -> V_259 = 0 ;
V_324 = 0 ;
break;
}
}
V_135:
return V_324 ;
}
int F_221 ( const struct V_378 * V_379 , int V_258 , int V_259 , int V_380 )
{
int V_135 ;
V_135 = F_215 ( V_379 , V_258 , V_259 ) ;
if ( V_135 == - V_402 )
V_135 = 0 ;
if ( ! V_135 )
F_192 ( V_379 , V_258 , V_259 , V_380 ) ;
return V_135 ;
}
int F_222 ( const struct V_378 * V_379 , int V_258 , int V_259 , int V_380 )
{
int V_135 ;
V_135 = F_217 ( V_379 , V_258 , V_259 ) ;
if ( V_135 == - V_402 )
V_135 = 0 ;
if ( ! V_135 )
F_194 ( V_379 , V_258 , V_259 , V_380 ) ;
return V_135 ;
}
void F_223 ( const struct V_378 * V_379 )
{
F_218 ( V_379 ) ;
}
static int T_8 F_224 ( void )
{
int V_79 ;
V_404 = F_225 ( V_406 , L_32 ) ;
if ( F_181 ( V_404 ) ) {
F_125 ( V_405 L_33
L_31 , F_216 ( V_404 ) ) ;
V_404 = NULL ;
}
for ( V_79 = 0 ; V_79 < V_344 ; V_79 ++ ) {
struct V_345 * V_347 = & V_346 [ V_79 ] ;
if ( V_347 -> V_347 && ! V_347 -> V_358 ) {
V_347 -> V_358 = F_180 ( V_404 , NULL ,
F_177 ( 0 , V_347 -> V_403 ) ,
NULL , L_29 ,
V_347 -> V_403 ) ;
if ( F_181 ( V_347 -> V_358 ) ) {
F_125 ( V_405 L_34
L_35 ,
V_347 -> V_348 , F_216 ( V_347 -> V_358 ) ) ;
V_347 -> V_358 = NULL ;
} else {
F_206 ( V_347 ) ;
}
}
}
return 0 ;
}
static int F_148 ( char T_7 * V_14 )
{
unsigned int V_290 ;
if ( F_141 ( V_290 , V_14 + 1 ) )
return - V_307 ;
V_407 = ( V_290 < 4 ) ? V_290 : 0 ;
return 0 ;
}
void F_131 ( int V_408 )
{
struct V_4 * V_5 = V_99 [ V_100 ] . V_25 ;
int V_79 ;
F_21 () ;
if ( V_86 ) {
if ( V_351 == V_409 ) {
V_351 = V_410 ;
V_5 -> V_16 -> V_411 ( V_5 , V_407 + 1 , 0 ) ;
}
return;
}
if ( V_408 ) {
F_23 ( V_5 ) ;
F_38 ( V_5 ) ;
V_5 -> V_16 -> V_411 ( V_5 , - 1 , 1 ) ;
V_86 = V_100 + 1 ;
V_351 = V_410 ;
F_37 ( V_5 ) ;
return;
}
if ( V_351 != V_352 )
return;
V_351 = V_410 ;
if ( V_5 -> V_87 != V_285 ) {
V_86 = V_100 + 1 ;
return;
}
F_23 ( V_5 ) ;
F_226 ( & V_353 ) ;
V_287 = 0 ;
F_38 ( V_5 ) ;
V_79 = V_5 -> V_16 -> V_411 ( V_5 , V_214 ? 1 : ( V_407 + 1 ) , 0 ) ;
V_86 = V_100 + 1 ;
if ( V_79 )
F_37 ( V_5 ) ;
if ( V_412 && V_412 ( 1 ) )
return;
if ( V_214 && V_407 ) {
V_351 = V_409 ;
F_169 ( & V_353 , V_354 + V_214 ) ;
}
F_69 ( V_413 , V_5 -> V_102 , V_5 -> V_102 ) ;
}
void F_227 ( int V_414 )
{
struct V_4 * V_5 ;
if ( ! V_415 )
F_124 () ;
F_21 () ;
V_322 = 0 ;
if ( ! V_86 )
return;
if ( ! F_46 ( V_100 ) ) {
F_228 ( L_36 ,
V_100 + 1 ) ;
return;
}
V_5 = V_99 [ V_100 ] . V_25 ;
if ( V_5 -> V_87 != V_285 && ! F_43 ( V_5 ) )
return;
if ( V_208 ) {
F_169 ( & V_353 , V_354 + ( V_208 * V_212 ) ) ;
V_351 = V_352 ;
}
V_86 = 0 ;
if ( V_5 -> V_16 -> V_411 ( V_5 , 0 , V_414 ) || F_43 ( V_5 ) )
F_68 ( V_5 ) ;
if ( V_412 )
V_412 ( 0 ) ;
F_42 ( V_5 ) ;
F_24 ( V_5 ) ;
F_69 ( V_416 , V_5 -> V_102 , V_5 -> V_102 ) ;
}
void F_144 ( void )
{
F_227 ( 0 ) ;
}
static void F_229 ( unsigned long V_417 )
{
if ( F_230 ( ! F_231 () ) ) {
F_169 ( & V_353 , V_354 + ( V_208 * V_212 ) ) ;
return;
}
V_287 = 1 ;
F_11 ( & V_21 ) ;
}
void F_103 ( void )
{
F_21 () ;
F_124 () ;
F_232 ( & V_353 ) ;
V_287 = 0 ;
if ( V_322 || ! V_99 [ V_100 ] . V_25 || V_99 [ V_100 ] . V_25 -> V_87 == V_88 )
return;
if ( V_86 )
F_144 () ;
else if ( V_208 ) {
F_169 ( & V_353 , V_354 + ( V_208 * V_212 ) ) ;
V_351 = V_352 ;
}
}
static void F_42 ( struct V_4 * V_5 )
{
F_21 () ;
if ( V_5 -> V_87 != V_88 )
V_5 -> V_16 -> V_418 ( V_5 , V_191 ) ;
}
int F_233 ( unsigned char T_7 * V_303 )
{
int V_79 , V_247 , V_336 ;
unsigned char V_419 [ 3 * 16 ] ;
if ( F_234 ( V_419 , V_303 , sizeof( V_419 ) ) )
return - V_307 ;
F_72 () ;
for ( V_79 = V_336 = 0 ; V_79 < 16 ; V_79 ++ ) {
V_337 [ V_79 ] = V_419 [ V_336 ++ ] ;
V_338 [ V_79 ] = V_419 [ V_336 ++ ] ;
V_339 [ V_79 ] = V_419 [ V_336 ++ ] ;
}
for ( V_79 = 0 ; V_79 < V_108 ; V_79 ++ ) {
if ( ! F_46 ( V_79 ) )
continue;
for ( V_247 = V_336 = 0 ; V_247 < 16 ; V_247 ++ ) {
V_99 [ V_79 ] . V_25 -> V_248 [ V_336 ++ ] = V_337 [ V_247 ] ;
V_99 [ V_79 ] . V_25 -> V_248 [ V_336 ++ ] = V_338 [ V_247 ] ;
V_99 [ V_79 ] . V_25 -> V_248 [ V_336 ++ ] = V_339 [ V_247 ] ;
}
F_42 ( V_99 [ V_79 ] . V_25 ) ;
}
F_73 () ;
return 0 ;
}
int F_235 ( unsigned char T_7 * V_303 )
{
int V_79 , V_336 ;
unsigned char V_419 [ 3 * 16 ] ;
F_72 () ;
for ( V_79 = V_336 = 0 ; V_79 < 16 ; V_79 ++ ) {
V_419 [ V_336 ++ ] = V_337 [ V_79 ] ;
V_419 [ V_336 ++ ] = V_338 [ V_79 ] ;
V_419 [ V_336 ++ ] = V_339 [ V_79 ] ;
}
F_73 () ;
if ( F_236 ( V_303 , V_419 , sizeof( V_419 ) ) )
return - V_307 ;
return 0 ;
}
void F_115 ( struct V_4 * V_5 )
{
int V_247 , V_336 ;
for ( V_247 = V_336 = 0 ; V_247 < 16 ; V_247 ++ ) {
V_5 -> V_248 [ V_336 ++ ] = V_337 [ V_247 ] ;
V_5 -> V_248 [ V_336 ++ ] = V_338 [ V_247 ] ;
V_5 -> V_248 [ V_336 ++ ] = V_339 [ V_247 ] ;
}
F_42 ( V_5 ) ;
}
static int F_237 ( struct V_4 * V_5 , struct V_420 * V_421 )
{
struct V_422 V_423 ;
int V_424 = - V_156 ;
int V_9 ;
if ( V_421 -> V_304 ) {
V_423 . V_304 = F_57 ( V_425 , V_125 ) ;
if ( ! V_423 . V_304 )
return - V_126 ;
} else
V_423 . V_304 = NULL ;
F_72 () ;
if ( V_5 -> V_87 != V_285 )
V_424 = - V_156 ;
else if ( V_5 -> V_16 -> F_237 )
V_424 = V_5 -> V_16 -> F_237 ( V_5 , & V_423 ) ;
else
V_424 = - V_426 ;
F_73 () ;
if ( V_424 )
goto V_427;
V_9 = ( V_423 . V_132 + 7 ) / 8 * 32 * V_423 . V_428 ;
if ( V_421 -> V_304 && V_423 . V_428 > V_421 -> V_428 )
V_424 = - V_429 ;
if ( ! ( V_421 -> V_374 & V_430 ) ) {
if ( V_423 . V_132 > V_421 -> V_132 || V_423 . V_133 > V_421 -> V_133 )
V_424 = - V_429 ;
} else {
if ( V_423 . V_132 != 8 )
V_424 = - V_431 ;
else if ( ( V_421 -> V_133 && V_423 . V_133 > V_421 -> V_133 ) ||
V_423 . V_133 > 32 )
V_424 = - V_429 ;
}
if ( V_424 )
goto V_427;
V_421 -> V_133 = V_423 . V_133 ;
V_421 -> V_132 = V_423 . V_132 ;
V_421 -> V_428 = V_423 . V_428 ;
if ( V_421 -> V_304 && F_236 ( V_421 -> V_304 , V_423 . V_304 , V_9 ) )
V_424 = - V_307 ;
V_427:
F_59 ( V_423 . V_304 ) ;
return V_424 ;
}
static int F_238 ( struct V_4 * V_5 , struct V_420 * V_421 )
{
struct V_422 V_423 ;
int V_424 = - V_156 ;
int V_432 ;
if ( V_5 -> V_87 != V_285 )
return - V_156 ;
if ( ! V_421 -> V_304 )
return - V_156 ;
if ( V_421 -> V_428 > 512 )
return - V_156 ;
if ( ! V_421 -> V_133 ) {
int V_433 , V_79 ;
T_2 T_7 * V_434 = V_421 -> V_304 ;
T_2 V_435 ;
if ( ! ( V_421 -> V_374 & V_430 ) )
return - V_156 ;
for ( V_433 = 32 ; V_433 > 0 ; V_433 -- )
for ( V_79 = 0 ; V_79 < V_421 -> V_428 ; V_79 ++ ) {
if ( F_141 ( V_435 , & V_434 [ 32 * V_79 + V_433 - 1 ] ) )
return - V_307 ;
if ( V_435 )
goto V_436;
}
return - V_156 ;
V_436:
V_421 -> V_133 = V_433 ;
}
if ( V_421 -> V_132 <= 0 || V_421 -> V_132 > 32 || V_421 -> V_133 > 32 )
return - V_156 ;
V_432 = ( V_421 -> V_132 + 7 ) / 8 * 32 * V_421 -> V_428 ;
if ( V_432 > V_425 )
return - V_429 ;
V_423 . V_428 = V_421 -> V_428 ;
V_423 . V_133 = V_421 -> V_133 ;
V_423 . V_132 = V_421 -> V_132 ;
V_423 . V_304 = F_239 ( V_421 -> V_304 , V_432 ) ;
if ( F_181 ( V_423 . V_304 ) )
return F_216 ( V_423 . V_304 ) ;
F_72 () ;
if ( V_5 -> V_87 != V_285 )
V_424 = - V_156 ;
else if ( V_5 -> V_16 -> F_238 )
V_424 = V_5 -> V_16 -> F_238 ( V_5 , & V_423 , V_421 -> V_374 ) ;
else
V_424 = - V_426 ;
F_73 () ;
F_59 ( V_423 . V_304 ) ;
return V_424 ;
}
static int F_240 ( struct V_4 * V_5 , struct V_420 * V_421 )
{
struct V_422 V_423 = { . V_132 = V_421 -> V_132 , . V_133 = V_421 -> V_133 } ;
char V_367 [ V_437 ] ;
char * V_26 = V_367 ;
int V_424 ;
if ( ! V_421 -> V_304 )
V_26 = NULL ;
else if ( F_241 ( V_367 , V_421 -> V_304 , V_437 - 1 ) < 0 )
return - V_307 ;
else
V_367 [ V_437 - 1 ] = 0 ;
F_72 () ;
if ( V_5 -> V_87 != V_285 ) {
F_73 () ;
return - V_156 ;
}
if ( V_5 -> V_16 -> F_240 )
V_424 = V_5 -> V_16 -> F_240 ( V_5 , & V_423 , V_26 ) ;
else
V_424 = - V_426 ;
F_73 () ;
if ( ! V_424 ) {
V_421 -> V_132 = V_423 . V_132 ;
V_421 -> V_133 = V_423 . V_133 ;
}
return V_424 ;
}
static int F_242 ( struct V_4 * V_5 , struct V_420 * V_421 )
{
int V_347 = V_421 -> V_133 ;
int V_424 ;
F_72 () ;
if ( V_5 -> V_87 != V_285 )
V_424 = - V_156 ;
else if ( ! V_5 -> V_16 -> F_242 )
V_424 = - V_426 ;
else if ( V_347 < 0 || ! F_46 ( V_347 ) )
V_424 = - V_438 ;
else if ( V_347 == V_5 -> V_102 )
V_424 = 0 ;
else
V_424 = V_5 -> V_16 -> F_242 ( V_5 , V_347 ) ;
F_73 () ;
return V_424 ;
}
int F_243 ( struct V_4 * V_5 , struct V_420 * V_421 )
{
switch ( V_421 -> V_421 ) {
case V_439 :
return F_238 ( V_5 , V_421 ) ;
case V_440 :
return F_237 ( V_5 , V_421 ) ;
case V_441 :
return F_240 ( V_5 , V_421 ) ;
case V_442 :
return F_242 ( V_5 , V_421 ) ;
}
return - V_426 ;
}
T_1 F_244 ( struct V_4 * V_5 , int V_12 )
{
T_1 V_443 = F_19 ( F_8 ( V_5 , V_12 , 1 ) ) ;
T_1 V_9 = V_443 & 0xff ;
if ( V_443 & V_5 -> V_57 )
V_9 |= 0x100 ;
return V_9 ;
}
unsigned short * F_245 ( struct V_4 * V_5 , int V_444 , int V_13 )
{
return F_8 ( V_5 , 2 * V_444 , V_13 ) ;
}
void F_246 ( struct V_4 * V_5 , unsigned char * V_14 )
{
V_14 [ 0 ] = V_5 -> V_77 ;
V_14 [ 1 ] = V_5 -> V_82 ;
}
void F_247 ( struct V_4 * V_5 , unsigned char * V_14 )
{
F_23 ( V_5 ) ;
F_65 ( V_5 , V_14 [ 0 ] , V_14 [ 1 ] ) ;
F_24 ( V_5 ) ;
}
T_1 F_248 ( struct V_4 * V_5 , const T_1 * V_445 )
{
if ( ( unsigned long ) V_445 == V_5 -> V_76 && V_81 != - 1 )
return V_81 ;
return F_19 ( V_445 ) ;
}
void F_249 ( struct V_4 * V_5 , T_1 V_446 , T_1 * V_445 )
{
F_28 ( V_446 , V_445 ) ;
if ( ( unsigned long ) V_445 == V_5 -> V_76 ) {
V_81 = - 1 ;
F_33 ( V_5 ) ;
}
}
void F_250 ( struct V_4 * V_5 )
{
F_7 ( V_5 ) ;
}
