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
static void F_38 ( struct V_4 * V_5 )
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
if ( V_5 -> V_115 )
F_51 ( V_5 ) ;
V_5 -> V_115 = & V_5 -> V_116 ;
V_5 -> V_116 = NULL ;
V_5 -> V_57 = 0 ;
V_5 -> V_75 = 0 ;
V_5 -> V_54 = 0 ;
V_5 -> V_117 = false ;
V_5 -> V_118 = V_119 ;
V_5 -> V_16 -> V_120 ( V_5 , V_110 ) ;
if ( ! V_5 -> V_75 )
V_5 -> V_75 = V_5 -> V_54 ? 0x7700 : 0x0800 ;
V_5 -> V_121 = V_5 -> V_75 ;
V_5 -> V_30 = V_5 -> V_31 << 1 ;
V_5 -> V_72 = V_5 -> V_27 * V_5 -> V_30 ;
}
int F_52 ( unsigned int V_122 )
{
struct V_7 V_8 ;
struct V_4 * V_5 ;
F_21 () ;
if ( V_122 >= V_108 )
return - V_123 ;
if ( V_99 [ V_122 ] . V_25 )
return 0 ;
V_8 . V_5 = V_5 = F_53 ( sizeof( struct V_4 ) , V_124 ) ;
if ( ! V_5 )
return - V_125 ;
V_99 [ V_122 ] . V_25 = V_5 ;
F_54 ( & V_5 -> V_126 ) ;
F_55 ( & V_99 [ V_122 ] . V_127 , V_128 ) ;
F_47 ( V_5 , V_122 , 1 ) ;
if ( ! * V_5 -> V_115 )
F_56 ( V_5 ) ;
V_5 -> V_92 = F_57 ( V_5 -> V_72 , V_124 ) ;
if ( ! V_5 -> V_92 )
goto V_129;
if ( V_130 == - 1 )
V_130 = 1 ;
F_58 ( V_5 , V_5 -> V_27 , V_5 -> V_31 , 1 ) ;
F_59 ( V_122 ) ;
F_6 ( & V_3 , V_131 , & V_8 ) ;
return 0 ;
V_129:
F_60 ( V_5 ) ;
V_99 [ V_122 ] . V_25 = NULL ;
return - V_125 ;
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
return - V_123 ;
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
return - V_125 ;
V_146 = V_5 -> V_27 ;
V_147 = V_5 -> V_30 ;
V_135 = F_61 ( V_5 , V_148 , V_149 , V_134 ) ;
if ( V_135 ) {
F_60 ( V_152 ) ;
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
F_60 ( V_5 -> V_92 ) ;
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
return F_62 ( V_5 -> V_126 . V_138 , V_5 , V_139 , V_167 ) ;
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
struct V_4 * F_73 ( unsigned int V_122 )
{
struct V_4 * V_5 = NULL ;
F_21 () ;
if ( F_46 ( V_122 ) ) {
struct V_7 V_8 ;
V_8 . V_5 = V_5 = V_99 [ V_122 ] . V_25 ;
F_6 ( & V_3 , V_170 , & V_8 ) ;
F_74 ( V_122 ) ;
V_5 -> V_16 -> V_171 ( V_5 ) ;
F_75 ( V_5 -> V_172 ) ;
F_48 ( V_5 -> V_16 -> V_111 ) ;
F_60 ( V_5 -> V_92 ) ;
V_99 [ V_122 ] . V_25 = NULL ;
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
static struct V_181 F_88 ( int V_79 )
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
static void F_93 ( const char * V_14 , struct V_196 * V_126 )
{
while ( * V_14 ) {
F_94 ( V_126 , * V_14 , 0 ) ;
V_14 ++ ;
}
F_95 ( V_126 ) ;
}
static void F_96 ( struct V_4 * V_5 , struct V_137 * V_138 )
{
char V_197 [ 40 ] ;
sprintf ( V_197 , L_2 , V_5 -> V_82 + ( V_5 -> V_177 ? V_5 -> V_158 + 1 : 1 ) , V_5 -> V_77 + 1 ) ;
F_93 ( V_197 , V_138 -> V_126 ) ;
}
static inline void F_97 ( struct V_137 * V_138 )
{
F_93 ( L_3 , V_138 -> V_126 ) ;
}
static inline void F_98 ( struct V_137 * V_138 )
{
F_93 ( V_198 , V_138 -> V_126 ) ;
}
void F_99 ( struct V_137 * V_138 , int V_199 , int V_200 , int V_201 )
{
char V_197 [ 8 ] ;
sprintf ( V_197 , L_4 , ( char ) ( ' ' + V_199 ) , ( char ) ( '!' + V_200 ) ,
( char ) ( '!' + V_201 ) ) ;
F_93 ( V_197 , V_138 -> V_126 ) ;
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
F_106 ( V_5 -> V_187 [ 1 ] ) : 0 ;
else
V_5 -> V_215 = V_216 ;
break;
case 12 :
if ( V_5 -> V_187 [ 1 ] >= 1 && F_46 ( V_5 -> V_187 [ 1 ] - 1 ) )
F_107 ( V_5 -> V_187 [ 1 ] - 1 ) ;
break;
case 13 :
F_105 () ;
break;
case 14 :
V_217 = ( ( V_5 -> V_187 [ 1 ] < 60 ) ? V_5 -> V_187 [ 1 ] : 60 ) * 60 * V_218 ;
break;
case 15 :
F_107 ( V_219 ) ;
break;
case 16 :
if ( V_5 -> V_186 >= 1 && V_5 -> V_187 [ 1 ] >= 50 &&
V_5 -> V_187 [ 1 ] <= V_220 )
V_5 -> V_118 = V_5 -> V_187 [ 1 ] ;
else
V_5 -> V_118 = V_119 ;
break;
}
}
static void F_108 ( struct V_4 * V_5 , unsigned int V_24 )
{
if ( V_24 > V_5 -> V_31 - V_5 -> V_77 )
V_24 = V_5 -> V_31 - V_5 -> V_77 ;
else if ( ! V_24 )
V_24 = 1 ;
F_30 ( V_5 , V_24 ) ;
}
static void F_109 ( struct V_4 * V_5 , unsigned int V_24 )
{
if ( V_24 > V_5 -> V_27 - V_5 -> V_82 )
V_24 = V_5 -> V_27 - V_5 -> V_82 ;
else if ( ! V_24 )
V_24 = 1 ;
F_16 ( V_5 , V_5 -> V_82 , V_5 -> V_159 , V_24 ) ;
V_5 -> V_78 = 0 ;
}
static void F_110 ( struct V_4 * V_5 , unsigned int V_24 )
{
if ( V_24 > V_5 -> V_31 - V_5 -> V_77 )
V_24 = V_5 -> V_31 - V_5 -> V_77 ;
else if ( ! V_24 )
V_24 = 1 ;
F_31 ( V_5 , V_24 ) ;
}
static void F_111 ( struct V_4 * V_5 , unsigned int V_24 )
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
V_5 -> V_221 = V_5 -> V_77 ;
V_5 -> V_222 = V_5 -> V_82 ;
V_5 -> V_223 = V_5 -> V_60 ;
V_5 -> V_224 = V_5 -> V_65 ;
V_5 -> V_225 = V_5 -> V_62 ;
V_5 -> V_226 = V_5 -> V_61 ;
V_5 -> V_227 = V_5 -> V_63 ;
V_5 -> V_228 = V_5 -> V_189 ;
V_5 -> V_229 = V_5 -> V_59 ;
V_5 -> V_230 = V_5 -> V_190 ;
V_5 -> V_231 = V_5 -> V_191 ;
}
static void F_112 ( struct V_4 * V_5 )
{
F_64 ( V_5 , V_5 -> V_221 , V_5 -> V_222 ) ;
V_5 -> V_60 = V_5 -> V_223 ;
V_5 -> V_65 = V_5 -> V_224 ;
V_5 -> V_62 = V_5 -> V_225 ;
V_5 -> V_61 = V_5 -> V_226 ;
V_5 -> V_63 = V_5 -> V_227 ;
V_5 -> V_189 = V_5 -> V_228 ;
V_5 -> V_59 = V_5 -> V_229 ;
V_5 -> V_190 = V_5 -> V_230 ;
V_5 -> V_191 = V_5 -> V_231 ;
V_5 -> V_188 = F_92 ( V_5 -> V_189 ? V_5 -> V_191 : V_5 -> V_190 , V_5 ) ;
F_26 ( V_5 ) ;
V_5 -> V_78 = 0 ;
}
static void F_113 ( struct V_4 * V_5 , int V_232 )
{
V_5 -> V_158 = 0 ;
V_5 -> V_159 = V_5 -> V_27 ;
V_5 -> V_233 = V_234 ;
V_5 -> V_204 = 0 ;
V_5 -> V_188 = F_92 ( V_235 , V_5 ) ;
V_5 -> V_190 = V_235 ;
V_5 -> V_191 = V_236 ;
V_5 -> V_189 = 0 ;
V_5 -> V_78 = 0 ;
V_5 -> V_202 = 0 ;
V_5 -> V_237 = V_238 ;
V_5 -> V_239 = 0 ;
V_5 -> V_192 = 0 ;
V_5 -> V_193 = 0 ;
V_5 -> V_64 = 0 ;
V_5 -> V_177 = 0 ;
V_5 -> V_207 = 1 ;
V_5 -> V_89 = V_130 ;
V_5 -> V_209 = 0 ;
F_114 ( V_5 -> V_102 ) ;
V_5 -> V_80 = V_240 ;
V_5 -> V_75 = V_5 -> V_121 ;
F_87 ( V_5 ) ;
F_26 ( V_5 ) ;
V_5 -> V_241 [ 0 ] = 0x01010100 ;
V_5 -> V_241 [ 1 ] =
V_5 -> V_241 [ 2 ] =
V_5 -> V_241 [ 3 ] =
V_5 -> V_241 [ 4 ] =
V_5 -> V_241 [ 5 ] =
V_5 -> V_241 [ 6 ] =
V_5 -> V_241 [ 7 ] = 0x01010101 ;
V_5 -> V_213 = V_214 ;
V_5 -> V_215 = V_216 ;
V_5 -> V_118 = V_119 ;
F_64 ( V_5 , 0 , 0 ) ;
F_65 ( V_5 ) ;
if ( V_232 )
F_84 ( V_5 , 2 ) ;
}
static void F_115 ( struct V_137 * V_138 , struct V_4 * V_5 , int V_9 )
{
if ( V_5 -> V_233 == V_242 && V_9 >= 8 && V_9 <= 13 )
return;
switch ( V_9 ) {
case 0 :
return;
case 7 :
if ( V_5 -> V_233 == V_242 )
V_5 -> V_233 = V_234 ;
else if ( V_5 -> V_215 )
F_116 ( V_5 -> V_213 , V_5 -> V_215 ) ;
return;
case 8 :
F_82 ( V_5 ) ;
return;
case 9 :
V_5 -> V_76 -= ( V_5 -> V_77 << 1 ) ;
while ( V_5 -> V_77 < V_5 -> V_31 - 1 ) {
V_5 -> V_77 ++ ;
if ( V_5 -> V_241 [ V_5 -> V_77 >> 5 ] & ( 1 << ( V_5 -> V_77 & 31 ) ) )
break;
}
V_5 -> V_76 += ( V_5 -> V_77 << 1 ) ;
F_5 ( V_5 , '\t' ) ;
return;
case 10 : case 11 : case 12 :
F_79 ( V_5 ) ;
if ( ! F_117 ( V_5 , V_210 ) )
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
V_5 -> V_233 = V_234 ;
return;
case 27 :
V_5 -> V_233 = V_243 ;
return;
case 127 :
F_83 ( V_5 ) ;
return;
case 128 + 27 :
V_5 -> V_233 = V_244 ;
return;
}
switch( V_5 -> V_233 ) {
case V_243 :
V_5 -> V_233 = V_234 ;
switch ( V_9 ) {
case '[' :
V_5 -> V_233 = V_244 ;
return;
case ']' :
V_5 -> V_233 = V_245 ;
return;
case '%' :
V_5 -> V_233 = V_246 ;
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
V_5 -> V_241 [ V_5 -> V_77 >> 5 ] |= ( 1 << ( V_5 -> V_77 & 31 ) ) ;
return;
case 'Z' :
F_98 ( V_138 ) ;
return;
case '7' :
F_65 ( V_5 ) ;
return;
case '8' :
F_112 ( V_5 ) ;
return;
case '(' :
V_5 -> V_233 = V_247 ;
return;
case ')' :
V_5 -> V_233 = V_248 ;
return;
case '#' :
V_5 -> V_233 = V_249 ;
return;
case 'c' :
F_113 ( V_5 , 1 ) ;
return;
case '>' :
F_103 ( V_5 , V_250 ) ;
return;
case '=' :
F_102 ( V_5 , V_250 ) ;
return;
}
return;
case V_245 :
if ( V_9 == 'P' ) {
for ( V_5 -> V_186 = 0 ; V_5 -> V_186 < V_251 ; V_5 -> V_186 ++ )
V_5 -> V_187 [ V_5 -> V_186 ] = 0 ;
V_5 -> V_186 = 0 ;
V_5 -> V_233 = V_252 ;
return;
} else if ( V_9 == 'R' ) {
F_118 ( V_5 ) ;
V_5 -> V_233 = V_234 ;
} else if ( V_9 >= '0' && V_9 <= '9' )
V_5 -> V_233 = V_242 ;
else
V_5 -> V_233 = V_234 ;
return;
case V_252 :
if ( isxdigit ( V_9 ) ) {
V_5 -> V_187 [ V_5 -> V_186 ++ ] = F_119 ( V_9 ) ;
if ( V_5 -> V_186 == 7 ) {
int V_79 = V_5 -> V_187 [ 0 ] * 3 , V_253 = 1 ;
V_5 -> V_254 [ V_79 ] = 16 * V_5 -> V_187 [ V_253 ++ ] ;
V_5 -> V_254 [ V_79 ++ ] += V_5 -> V_187 [ V_253 ++ ] ;
V_5 -> V_254 [ V_79 ] = 16 * V_5 -> V_187 [ V_253 ++ ] ;
V_5 -> V_254 [ V_79 ++ ] += V_5 -> V_187 [ V_253 ++ ] ;
V_5 -> V_254 [ V_79 ] = 16 * V_5 -> V_187 [ V_253 ++ ] ;
V_5 -> V_254 [ V_79 ] += V_5 -> V_187 [ V_253 ] ;
F_42 ( V_5 ) ;
V_5 -> V_233 = V_234 ;
}
} else
V_5 -> V_233 = V_234 ;
return;
case V_244 :
for ( V_5 -> V_186 = 0 ; V_5 -> V_186 < V_251 ; V_5 -> V_186 ++ )
V_5 -> V_187 [ V_5 -> V_186 ] = 0 ;
V_5 -> V_186 = 0 ;
V_5 -> V_233 = V_255 ;
if ( V_9 == '[' ) {
V_5 -> V_233 = V_256 ;
return;
}
V_5 -> V_204 = ( V_9 == '?' ) ;
if ( V_5 -> V_204 )
return;
case V_255 :
if ( V_9 == ';' && V_5 -> V_186 < V_251 - 1 ) {
V_5 -> V_186 ++ ;
return;
} else if ( V_9 >= '0' && V_9 <= '9' ) {
V_5 -> V_187 [ V_5 -> V_186 ] *= 10 ;
V_5 -> V_187 [ V_5 -> V_186 ] += V_9 - '0' ;
return;
}
V_5 -> V_233 = V_234 ;
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
V_5 -> V_80 = V_240 ;
return;
}
break;
case 'm' :
if ( V_5 -> V_204 ) {
F_35 () ;
if ( V_5 -> V_187 [ 0 ] )
V_5 -> V_75 = V_5 -> V_187 [ 0 ] << 8 | V_5 -> V_187 [ 1 ] ;
else
V_5 -> V_75 = V_5 -> V_121 ;
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
F_109 ( V_5 , V_5 -> V_187 [ 0 ] ) ;
return;
case 'M' :
F_111 ( V_5 , V_5 -> V_187 [ 0 ] ) ;
return;
case 'P' :
F_110 ( V_5 , V_5 -> V_187 [ 0 ] ) ;
return;
case 'c' :
if ( ! V_5 -> V_187 [ 0 ] )
F_98 ( V_138 ) ;
return;
case 'g' :
if ( ! V_5 -> V_187 [ 0 ] )
V_5 -> V_241 [ V_5 -> V_77 >> 5 ] &= ~ ( 1 << ( V_5 -> V_77 & 31 ) ) ;
else if ( V_5 -> V_187 [ 0 ] == 3 ) {
V_5 -> V_241 [ 0 ] =
V_5 -> V_241 [ 1 ] =
V_5 -> V_241 [ 2 ] =
V_5 -> V_241 [ 3 ] =
V_5 -> V_241 [ 4 ] =
V_5 -> V_241 [ 5 ] =
V_5 -> V_241 [ 6 ] =
V_5 -> V_241 [ 7 ] = 0 ;
}
return;
case 'm' :
F_91 ( V_5 ) ;
return;
case 'q' :
if ( V_5 -> V_187 [ 0 ] < 4 )
F_120 ( V_5 -> V_102 ,
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
F_112 ( V_5 ) ;
return;
case 'X' :
F_86 ( V_5 , V_5 -> V_187 [ 0 ] ) ;
return;
case '@' :
F_108 ( V_5 , V_5 -> V_187 [ 0 ] ) ;
return;
case ']' :
F_104 ( V_5 ) ;
return;
}
return;
case V_246 :
V_5 -> V_233 = V_234 ;
switch ( V_9 ) {
case '@' :
V_5 -> V_237 = 0 ;
return;
case 'G' :
case '8' :
V_5 -> V_237 = 1 ;
return;
}
return;
case V_256 :
V_5 -> V_233 = V_234 ;
return;
case V_249 :
V_5 -> V_233 = V_234 ;
if ( V_9 == '8' ) {
V_5 -> V_32 =
( V_5 -> V_32 & 0xff00 ) | 'E' ;
F_84 ( V_5 , 2 ) ;
V_5 -> V_32 =
( V_5 -> V_32 & 0xff00 ) | ' ' ;
F_17 ( V_5 , V_5 -> V_15 , V_5 -> V_72 / 2 ) ;
}
return;
case V_247 :
if ( V_9 == '0' )
V_5 -> V_190 = V_236 ;
else if ( V_9 == 'B' )
V_5 -> V_190 = V_235 ;
else if ( V_9 == 'U' )
V_5 -> V_190 = V_194 ;
else if ( V_9 == 'K' )
V_5 -> V_190 = V_257 ;
if ( V_5 -> V_189 == 0 )
V_5 -> V_188 = F_92 ( V_5 -> V_190 , V_5 ) ;
V_5 -> V_233 = V_234 ;
return;
case V_248 :
if ( V_9 == '0' )
V_5 -> V_191 = V_236 ;
else if ( V_9 == 'B' )
V_5 -> V_191 = V_235 ;
else if ( V_9 == 'U' )
V_5 -> V_191 = V_194 ;
else if ( V_9 == 'K' )
V_5 -> V_191 = V_257 ;
if ( V_5 -> V_189 == 1 )
V_5 -> V_188 = F_92 ( V_5 -> V_191 , V_5 ) ;
V_5 -> V_233 = V_234 ;
return;
case V_242 :
return;
default:
V_5 -> V_233 = V_234 ;
}
}
static int F_121 ( T_4 V_258 , const struct V_259 * V_260 , int V_185 )
{
int F_63 = 0 ;
int V_261 ;
if ( V_258 < V_260 [ 0 ] . V_262 || V_258 > V_260 [ V_185 ] . V_263 )
return 0 ;
while ( V_185 >= F_63 ) {
V_261 = ( F_63 + V_185 ) / 2 ;
if ( V_258 > V_260 [ V_261 ] . V_263 )
F_63 = V_261 + 1 ;
else if ( V_258 < V_260 [ V_261 ] . V_262 )
V_185 = V_261 - 1 ;
else
return 1 ;
}
return 0 ;
}
static int F_122 ( T_4 V_258 )
{
static const struct V_259 V_264 [] = {
{ 0x1100 , 0x115F } , { 0x2329 , 0x232A } , { 0x2E80 , 0x303E } ,
{ 0x3040 , 0xA4CF } , { 0xAC00 , 0xD7A3 } , { 0xF900 , 0xFAFF } ,
{ 0xFE10 , 0xFE19 } , { 0xFE30 , 0xFE6F } , { 0xFF00 , 0xFF60 } ,
{ 0xFFE0 , 0xFFE6 } , { 0x20000 , 0x2FFFD } , { 0x30000 , 0x3FFFD }
} ;
return F_121 ( V_258 , V_264 , F_123 ( V_264 ) - 1 ) ;
}
static int F_124 ( struct V_137 * V_138 , const unsigned char * V_197 , int V_36 )
{
#ifdef F_18
#define F_125 do { } while(0);
#else
#define F_125 if (draw_x >= 0) { \
vc->vc_sw->con_putcs(vc, (u16 *)draw_from, (u16 *)draw_to - (u16 *)draw_from, vc->vc_y, draw_x); \
draw_x = -1; \
}
#endif
int V_9 , V_265 , V_266 , V_267 = 0 , V_268 = - 1 ;
unsigned int V_122 ;
unsigned long V_269 = 0 , V_270 = 0 ;
struct V_4 * V_5 ;
unsigned char V_58 ;
struct V_7 V_8 ;
T_5 V_271 ;
T_5 V_272 ;
T_5 V_132 ;
T_1 V_273 , V_274 ;
if ( F_126 () )
return V_36 ;
F_127 () ;
F_71 () ;
V_5 = V_138 -> V_168 ;
if ( V_5 == NULL ) {
F_128 ( V_275 L_5 ) ;
F_72 () ;
return 0 ;
}
V_122 = V_5 -> V_102 ;
if ( ! F_46 ( V_122 ) ) {
F_129 ( L_6 , V_122 + 1 ) ;
F_72 () ;
return 0 ;
}
V_273 = V_5 -> V_57 ;
V_274 = V_273 ? 0x1ff : 0xff ;
if ( F_36 ( V_5 ) )
F_23 ( V_5 ) ;
V_8 . V_5 = V_5 ;
while ( ! V_138 -> V_276 && V_36 ) {
int V_277 = * V_197 ;
V_9 = V_277 ;
V_197 ++ ;
V_267 ++ ;
V_36 -- ;
V_271 = 0 ;
V_272 = 0 ;
V_132 = 1 ;
if ( V_5 -> V_233 != V_234 ) {
V_265 = V_9 ;
} else if ( V_5 -> V_237 && ! V_5 -> V_192 ) {
V_278:
if ( ( V_9 & 0xc0 ) == 0x80 ) {
static const T_4 V_279 [] = { 0x0000007f , 0x000007ff , 0x0000ffff , 0x001fffff , 0x03ffffff , 0x7fffffff } ;
if ( V_5 -> V_239 ) {
V_5 -> V_280 = ( V_5 -> V_280 << 6 ) | ( V_9 & 0x3f ) ;
V_5 -> V_186 ++ ;
if ( -- V_5 -> V_239 ) {
continue;
}
V_9 = V_5 -> V_280 ;
if ( V_9 <= V_279 [ V_5 -> V_186 - 1 ] ||
V_9 > V_279 [ V_5 -> V_186 ] )
V_9 = 0xfffd ;
} else {
V_5 -> V_239 = 0 ;
V_9 = 0xfffd ;
}
} else {
if ( V_5 -> V_239 ) {
V_271 = 1 ;
V_5 -> V_239 = 0 ;
V_9 = 0xfffd ;
} else if ( V_9 > 0x7f ) {
V_5 -> V_186 = 0 ;
if ( ( V_9 & 0xe0 ) == 0xc0 ) {
V_5 -> V_239 = 1 ;
V_5 -> V_280 = ( V_9 & 0x1f ) ;
} else if ( ( V_9 & 0xf0 ) == 0xe0 ) {
V_5 -> V_239 = 2 ;
V_5 -> V_280 = ( V_9 & 0x0f ) ;
} else if ( ( V_9 & 0xf8 ) == 0xf0 ) {
V_5 -> V_239 = 3 ;
V_5 -> V_280 = ( V_9 & 0x07 ) ;
} else if ( ( V_9 & 0xfc ) == 0xf8 ) {
V_5 -> V_239 = 4 ;
V_5 -> V_280 = ( V_9 & 0x03 ) ;
} else if ( ( V_9 & 0xfe ) == 0xfc ) {
V_5 -> V_239 = 5 ;
V_5 -> V_280 = ( V_9 & 0x01 ) ;
} else {
V_9 = 0xfffd ;
}
if ( V_5 -> V_239 ) {
continue;
}
}
}
if ( ( V_9 >= 0xd800 && V_9 <= 0xdfff ) || V_9 == 0xfffe || V_9 == 0xffff )
V_9 = 0xfffd ;
V_265 = V_9 ;
} else {
V_265 = V_188 ( V_5 , V_9 ) ;
}
V_8 . V_9 = V_265 ;
if ( F_6 ( & V_3 , V_281 ,
& V_8 ) == V_282 )
continue;
V_266 = V_265 && ( V_9 >= 32 ||
! ( V_5 -> V_192 ? ( V_283 >> V_9 ) & 1 :
V_5 -> V_237 || ( ( V_284 >> V_9 ) & 1 ) ) )
&& ( V_9 != 127 || V_5 -> V_192 )
&& ( V_9 != 128 + 27 ) ;
if ( V_5 -> V_233 == V_234 && V_266 ) {
if ( V_5 -> V_237 && ! V_5 -> V_192 ) {
if ( F_122 ( V_9 ) )
V_132 = 2 ;
}
V_265 = F_130 ( V_5 , V_265 ) ;
if ( V_265 & ~ V_274 ) {
if ( V_265 == - 1 || V_265 == - 2 ) {
continue;
}
if ( ( ! ( V_5 -> V_237 && ! V_5 -> V_192 ) || V_9 < 128 ) && ! ( V_9 & ~ V_274 ) ) {
V_265 = V_9 ;
} else {
V_265 = F_130 ( V_5 , 0xfffd ) ;
if ( V_265 < 0 ) {
V_272 = 1 ;
V_265 = F_130 ( V_5 , '?' ) ;
if ( V_265 < 0 ) V_265 = '?' ;
}
}
}
if ( ! V_272 ) {
V_58 = V_5 -> V_58 ;
} else {
if ( ! V_5 -> V_54 ) {
V_58 = ( V_5 -> V_58 ) ^ 0x08 ;
} else if ( V_5 -> V_57 == 0x100 ) {
V_58 = ( ( V_5 -> V_58 ) & 0x11 ) | ( ( ( V_5 -> V_58 ) & 0xe0 ) >> 4 ) | ( ( ( V_5 -> V_58 ) & 0x0e ) << 4 ) ;
} else {
V_58 = ( ( V_5 -> V_58 ) & 0x88 ) | ( ( ( V_5 -> V_58 ) & 0x70 ) >> 4 ) | ( ( ( V_5 -> V_58 ) & 0x07 ) << 4 ) ;
}
F_125
}
while ( 1 ) {
if ( V_5 -> V_78 || V_5 -> V_209 )
F_125
if ( V_5 -> V_78 ) {
F_81 ( V_5 ) ;
F_79 ( V_5 ) ;
}
if ( V_5 -> V_209 )
F_30 ( V_5 , 1 ) ;
F_28 ( V_273 ?
( ( V_58 << 8 ) & ~ V_273 ) + ( ( V_265 & 0x100 ) ? V_273 : 0 ) + ( V_265 & 0xff ) :
( V_58 << 8 ) + V_265 ,
( T_1 * ) V_5 -> V_76 ) ;
if ( F_22 ( V_5 ) && V_268 < 0 ) {
V_268 = V_5 -> V_77 ;
V_269 = V_5 -> V_76 ;
}
if ( V_5 -> V_77 == V_5 -> V_31 - 1 ) {
V_5 -> V_78 = V_5 -> V_207 ;
V_270 = V_5 -> V_76 + 2 ;
} else {
V_5 -> V_77 ++ ;
V_270 = ( V_5 -> V_76 += 2 ) ;
}
if ( ! -- V_132 ) break;
V_265 = F_130 ( V_5 , ' ' ) ;
if ( V_265 < 0 ) V_265 = ' ' ;
}
F_5 ( V_5 , V_9 ) ;
if ( V_272 ) {
F_125
}
if ( V_271 ) {
V_271 = 0 ;
V_272 = 0 ;
V_132 = 1 ;
V_9 = V_277 ;
goto V_278;
}
continue;
}
F_125
F_115 ( V_138 , V_5 , V_277 ) ;
}
F_125
F_131 ();
F_72 () ;
F_7 ( V_5 ) ;
return V_267 ;
#undef F_125
}
static void F_132 ( struct V_285 * V_286 )
{
F_71 () ;
if ( V_287 >= 0 ) {
if ( V_287 != V_100 &&
F_46 ( V_287 ) ) {
F_23 ( V_99 [ V_100 ] . V_25 ) ;
F_133 ( V_99 [ V_287 ] . V_25 ) ;
}
V_287 = - 1 ;
}
if ( V_288 ) {
V_288 = 0 ;
F_105 () ;
}
if ( V_20 ) {
struct V_4 * V_5 = V_99 [ V_100 ] . V_25 ;
F_35 () ;
if ( V_5 -> V_87 == V_289 )
V_5 -> V_16 -> V_290 ( V_5 , V_20 ) ;
V_20 = 0 ;
}
if ( V_291 ) {
F_134 ( 0 ) ;
V_291 = 0 ;
}
F_7 ( V_99 [ V_100 ] . V_25 ) ;
F_72 () ;
}
int F_107 ( int V_24 )
{
struct V_4 * V_5 = V_99 [ V_100 ] . V_25 ;
if ( ! F_46 ( V_24 ) || V_292 ||
( V_5 -> V_293 . V_294 == V_295 && V_5 -> V_87 == V_88 ) ) {
return - V_156 ;
}
V_287 = V_24 ;
F_10 () ;
return 0 ;
}
int F_135 ( int V_74 )
{
static int V_296 ;
if ( V_74 != - 1 )
return F_136 ( & V_296 , V_74 ) ;
else
return V_296 ;
}
static void F_137 ( struct V_297 * V_298 , const char * V_23 , unsigned V_36 )
{
struct V_4 * V_5 = V_99 [ V_100 ] . V_25 ;
unsigned char V_9 ;
static F_138 ( V_299 ) ;
const T_6 * V_35 ;
T_6 V_67 = 0 ;
T_6 V_300 ;
int V_301 ;
if ( ! V_302 )
return;
if ( ! F_139 ( & V_299 ) )
return;
V_301 = F_140 () ;
if ( V_301 && F_46 ( V_301 - 1 ) )
V_5 = V_99 [ V_301 - 1 ] . V_25 ;
V_300 = V_5 -> V_77 ;
if ( ! F_46 ( V_100 ) ) {
goto V_303;
}
if ( V_5 -> V_87 != V_289 && ! F_43 ( V_5 ) )
goto V_303;
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
V_300 = V_5 -> V_77 ;
continue;
}
if ( V_9 != 13 )
F_79 ( V_5 ) ;
F_81 ( V_5 ) ;
V_35 = ( T_6 * ) V_5 -> V_76 ;
V_300 = V_5 -> V_77 ;
if ( V_9 == 10 || V_9 == 13 )
continue;
}
F_28 ( ( V_5 -> V_58 << 8 ) + V_9 , ( unsigned short * ) V_5 -> V_76 ) ;
F_5 ( V_5 , V_9 ) ;
V_67 ++ ;
if ( V_300 == V_5 -> V_31 - 1 ) {
V_5 -> V_78 = 1 ;
continue;
}
V_5 -> V_76 += 2 ;
V_300 ++ ;
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
V_303:
F_141 ( & V_299 ) ;
}
static struct V_304 * F_142 ( struct V_297 * V_9 , int * V_305 )
{
* V_305 = V_9 -> V_305 ? V_9 -> V_305 - 1 : V_100 ;
return V_306 ;
}
int F_143 ( struct V_137 * V_138 , unsigned long V_307 )
{
char type , V_308 ;
char T_7 * V_14 = ( char T_7 * ) V_307 ;
int V_19 ;
int V_169 ;
if ( V_309 -> signal -> V_138 != V_138 && ! F_144 ( V_310 ) )
return - V_311 ;
if ( F_145 ( type , V_14 ) )
return - V_312 ;
V_169 = 0 ;
switch ( type )
{
case V_313 :
F_71 () ;
V_169 = F_146 ( (struct V_314 T_7 * ) ( V_14 + 1 ) , V_138 ) ;
F_72 () ;
break;
case V_315 :
V_169 = F_147 ( V_138 ) ;
break;
case V_316 :
F_71 () ;
F_148 () ;
F_72 () ;
break;
case V_317 :
F_71 () ;
V_169 = F_149 ( V_14 ) ;
F_72 () ;
break;
case V_318 :
V_308 = F_150 () ;
V_169 = F_151 ( V_308 , V_14 ) ;
break;
case V_319 :
F_71 () ;
V_308 = F_100 () ;
F_72 () ;
V_169 = F_151 ( V_308 , V_14 ) ;
break;
case V_320 :
F_71 () ;
V_169 = F_152 ( V_14 ) ;
F_72 () ;
break;
case V_321 :
V_308 = F_140 () ;
V_169 = F_151 ( V_308 , V_14 ) ;
break;
case V_322 :
if ( ! F_144 ( V_310 ) ) {
V_169 = - V_311 ;
} else {
if ( F_145 ( V_308 , V_14 + 1 ) )
V_169 = - V_312 ;
else
F_135 ( V_308 ) ;
}
break;
case V_323 :
V_169 = V_100 ;
break;
case V_324 :
if ( F_145 ( V_19 , ( V_325 T_7 * ) ( V_14 + 4 ) ) ) {
V_169 = - V_312 ;
} else {
F_71 () ;
F_78 ( V_99 [ V_100 ] . V_25 , V_19 ) ;
F_72 () ;
V_169 = 0 ;
}
break;
case V_326 :
F_71 () ;
V_327 = 1 ;
F_134 ( 0 ) ;
F_72 () ;
break;
case V_328 :
V_169 = V_86 ;
break;
default:
V_169 = - V_156 ;
break;
}
return V_169 ;
}
static int F_153 ( struct V_137 * V_138 , const unsigned char * V_197 , int V_36 )
{
int V_329 ;
V_329 = F_124 ( V_138 , V_197 , V_36 ) ;
F_154 ( V_138 ) ;
return V_329 ;
}
static int F_155 ( struct V_137 * V_138 , unsigned char V_330 )
{
if ( F_126 () )
return 0 ;
return F_124 ( V_138 , & V_330 , 1 ) ;
}
static int F_156 ( struct V_137 * V_138 )
{
if ( V_138 -> V_276 )
return 0 ;
return 32768 ;
}
static int F_157 ( struct V_137 * V_138 )
{
return 0 ;
}
static void F_158 ( struct V_137 * V_138 )
{
}
static void F_159 ( struct V_137 * V_138 )
{
struct V_4 * V_5 = V_138 -> V_168 ;
F_160 ( & V_5 -> V_331 ) ;
}
static void F_161 ( struct V_137 * V_138 )
{
int V_332 ;
if ( ! V_138 )
return;
V_332 = V_138 -> V_305 ;
if ( ! F_46 ( V_332 ) )
return;
F_162 ( V_332 ) ;
}
static void F_163 ( struct V_137 * V_138 )
{
int V_332 ;
if ( ! V_138 )
return;
V_332 = V_138 -> V_305 ;
if ( ! F_46 ( V_332 ) )
return;
F_164 ( V_332 ) ;
}
static void F_154 ( struct V_137 * V_138 )
{
struct V_4 * V_5 ;
if ( F_126 () )
return;
F_71 () ;
V_5 = V_138 -> V_168 ;
if ( V_5 )
F_24 ( V_5 ) ;
F_72 () ;
}
static int F_165 ( struct V_304 * V_333 , struct V_137 * V_138 )
{
unsigned int V_122 = V_138 -> V_305 ;
struct V_4 * V_5 ;
int V_169 ;
F_71 () ;
V_169 = F_52 ( V_122 ) ;
if ( V_169 )
goto V_334;
V_5 = V_99 [ V_122 ] . V_25 ;
if ( V_5 -> V_126 . V_138 ) {
V_169 = - V_335 ;
goto V_334;
}
V_169 = F_166 ( & V_5 -> V_126 , V_333 , V_138 ) ;
if ( V_169 )
goto V_334;
V_138 -> V_168 = V_5 ;
V_5 -> V_126 . V_138 = V_138 ;
if ( ! V_138 -> V_160 . V_162 && ! V_138 -> V_160 . V_163 ) {
V_138 -> V_160 . V_162 = V_99 [ V_122 ] . V_25 -> V_27 ;
V_138 -> V_160 . V_163 = V_99 [ V_122 ] . V_25 -> V_31 ;
}
if ( V_5 -> V_237 )
V_138 -> V_336 . V_337 |= V_338 ;
else
V_138 -> V_336 . V_337 &= ~ V_338 ;
V_334:
F_72 () ;
return V_169 ;
}
static int F_167 ( struct V_137 * V_138 , struct V_339 * V_340 )
{
return 0 ;
}
static void F_168 ( struct V_137 * V_138 , struct V_339 * V_340 )
{
}
static void F_169 ( struct V_137 * V_138 )
{
struct V_4 * V_5 = V_138 -> V_168 ;
F_170 ( V_5 == NULL ) ;
F_71 () ;
V_5 -> V_126 . V_138 = NULL ;
F_72 () ;
}
static void F_58 ( struct V_4 * V_5 , unsigned int V_167 ,
unsigned int V_139 , int V_232 )
{
int V_253 , V_341 ;
V_5 -> V_31 = V_139 ;
V_5 -> V_27 = V_167 ;
V_5 -> V_30 = V_139 << 1 ;
V_5 -> V_72 = V_5 -> V_27 * V_5 -> V_30 ;
F_37 ( V_5 ) ;
V_5 -> V_76 = V_5 -> V_15 ;
F_171 ( V_5 ) ;
for ( V_253 = V_341 = 0 ; V_253 < 16 ; V_253 ++ ) {
V_5 -> V_254 [ V_341 ++ ] = V_342 [ V_253 ] ;
V_5 -> V_254 [ V_341 ++ ] = V_343 [ V_253 ] ;
V_5 -> V_254 [ V_341 ++ ] = V_344 [ V_253 ] ;
}
V_5 -> V_180 = V_345 ;
V_5 -> V_56 = V_346 ;
V_5 -> V_55 = V_347 ;
V_5 -> V_211 = 0x08 ;
F_172 ( & V_5 -> V_331 ) ;
F_113 ( V_5 , V_232 ) ;
}
static int T_8 V_120 ( void )
{
const char * V_348 = NULL ;
struct V_4 * V_5 ;
unsigned int V_122 = 0 , V_79 ;
F_71 () ;
if ( V_112 )
V_348 = V_112 -> V_349 () ;
if ( ! V_348 ) {
V_100 = 0 ;
F_72 () ;
return 0 ;
}
for ( V_79 = 0 ; V_79 < V_350 ; V_79 ++ ) {
struct V_351 * V_351 = & V_352 [ V_79 ] ;
if ( V_351 -> V_353 == NULL ) {
V_351 -> V_353 = V_112 ;
V_351 -> V_354 = V_348 ;
V_351 -> V_355 = V_356 ;
V_351 -> V_262 = 0 ;
V_351 -> V_263 = V_108 - 1 ;
break;
}
}
for ( V_79 = 0 ; V_79 < V_108 ; V_79 ++ )
V_113 [ V_79 ] = V_112 ;
if ( V_212 ) {
V_357 = V_358 ;
F_173 ( & V_359 , V_360 + ( V_212 * V_218 ) ) ;
}
for ( V_122 = 0 ; V_122 < V_361 ; V_122 ++ ) {
V_99 [ V_122 ] . V_25 = V_5 = F_53 ( sizeof( struct V_4 ) , V_362 ) ;
F_55 ( & V_99 [ V_122 ] . V_127 , V_128 ) ;
F_54 ( & V_5 -> V_126 ) ;
F_47 ( V_5 , V_122 , 1 ) ;
V_5 -> V_92 = F_53 ( V_5 -> V_72 , V_362 ) ;
F_58 ( V_5 , V_5 -> V_27 , V_5 -> V_31 ,
V_122 || ! V_5 -> V_16 -> V_94 ) ;
}
V_122 = V_100 = 0 ;
V_114 = V_5 = V_99 [ V_122 ] . V_25 ;
F_37 ( V_5 ) ;
F_38 ( V_5 ) ;
F_64 ( V_5 , V_5 -> V_77 , V_5 -> V_82 ) ;
F_84 ( V_5 , 0 ) ;
F_67 ( V_5 ) ;
F_174 ( L_7 ,
V_5 -> V_54 ? L_8 : L_9 ,
V_348 , V_5 -> V_31 , V_5 -> V_27 ) ;
V_302 = 1 ;
F_72 () ;
#ifdef F_175
F_176 ( & V_363 ) ;
#endif
return 0 ;
}
static T_9 F_177 ( struct V_364 * V_365 ,
struct V_366 * V_367 , char * V_197 )
{
return sprintf ( V_197 , L_10 , V_100 + 1 ) ;
}
int T_8 F_178 ( const struct V_368 * V_369 )
{
F_179 ( & V_370 , V_369 ) ;
if ( F_180 ( & V_370 , F_181 ( V_371 , 0 ) , 1 ) ||
F_182 ( F_181 ( V_371 , 0 ) , 1 , L_11 ) < 0 )
F_183 ( L_12 ) ;
V_103 = F_184 ( V_372 , NULL ,
F_181 ( V_371 , 0 ) , NULL ,
V_373 , L_13 ) ;
if ( F_185 ( V_103 ) )
V_103 = NULL ;
F_186 () ;
V_306 = F_187 ( V_108 ) ;
if ( ! V_306 )
F_183 ( L_14 ) ;
V_306 -> V_374 = L_15 ;
V_306 -> V_375 = 1 ;
V_306 -> V_376 = V_371 ;
V_306 -> V_377 = 1 ;
V_306 -> type = V_378 ;
V_306 -> V_379 = V_380 ;
if ( V_238 )
V_306 -> V_379 . V_337 |= V_338 ;
V_306 -> V_381 = V_382 | V_383 ;
F_188 ( V_306 , & V_384 ) ;
if ( F_189 ( V_306 ) )
F_183 ( L_16 ) ;
F_190 () ;
F_191 () ;
#ifdef F_192
F_193 () ;
#endif
return 0 ;
}
static int F_194 ( const struct V_385 * V_386 , int V_262 , int V_263 ,
int V_387 )
{
struct V_388 * V_111 = V_386 -> V_111 ;
const char * V_354 = NULL ;
struct V_351 * V_351 ;
int V_79 , V_253 = - 1 , V_341 = - 1 , V_329 = - V_389 ;
if ( ! F_195 ( V_111 ) )
return - V_389 ;
F_21 () ;
for ( V_79 = 0 ; V_79 < V_350 ; V_79 ++ ) {
V_351 = & V_352 [ V_79 ] ;
if ( V_351 -> V_353 == V_386 ) {
V_354 = V_351 -> V_354 ;
V_329 = 0 ;
break;
}
}
if ( V_329 )
goto V_135;
if ( ! ( V_351 -> V_355 & V_356 ) ) {
V_386 -> V_349 () ;
V_351 -> V_355 |= V_356 ;
}
if ( V_387 ) {
if ( V_112 )
F_48 ( V_112 -> V_111 ) ;
F_50 ( V_111 ) ;
V_112 = V_386 ;
}
V_262 = V_185 ( V_262 , V_351 -> V_262 ) ;
V_263 = F_63 ( V_263 , V_351 -> V_263 ) ;
for ( V_79 = V_262 ; V_79 <= V_263 ; V_79 ++ ) {
int V_106 ;
struct V_4 * V_5 = V_99 [ V_79 ] . V_25 ;
if ( V_113 [ V_79 ] )
F_48 ( V_113 [ V_79 ] -> V_111 ) ;
F_50 ( V_111 ) ;
V_113 [ V_79 ] = V_386 ;
if ( ! V_5 || ! V_5 -> V_16 )
continue;
V_253 = V_79 ;
if ( F_13 ( V_5 ) ) {
V_341 = V_79 ;
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
F_174 ( L_17 ) ;
if ( ! V_387 )
F_128 ( L_18 , V_262 + 1 , V_263 + 1 ) ;
if ( V_253 >= 0 ) {
struct V_4 * V_5 = V_99 [ V_253 ] . V_25 ;
F_128 ( L_19 ,
V_5 -> V_54 ? L_8 : L_9 ,
V_354 , V_5 -> V_31 , V_5 -> V_27 ) ;
if ( V_341 >= 0 ) {
V_5 = V_99 [ V_341 ] . V_25 ;
F_67 ( V_5 ) ;
}
} else
F_128 ( L_20 , V_354 ) ;
V_329 = 0 ;
V_135:
F_48 ( V_111 ) ;
return V_329 ;
}
int F_196 ( const struct V_385 * V_386 , int V_262 , int V_263 , int V_387 )
{
struct V_388 * V_111 = V_386 -> V_111 ;
const struct V_385 * V_390 = NULL ;
struct V_351 * V_351 = NULL , * V_391 = NULL ;
int V_79 , V_329 = - V_389 ;
if ( ! F_195 ( V_111 ) )
return - V_389 ;
F_21 () ;
for ( V_79 = 0 ; V_79 < V_350 ; V_79 ++ ) {
V_351 = & V_352 [ V_79 ] ;
if ( V_351 -> V_353 == V_386 &&
V_351 -> V_355 & V_392 ) {
V_329 = 0 ;
break;
}
}
if ( V_329 )
goto V_135;
V_329 = - V_389 ;
for ( V_79 = 0 ; V_79 < V_350 ; V_79 ++ ) {
V_391 = & V_352 [ V_79 ] ;
if ( V_391 -> V_353 && V_391 -> V_353 != V_386 ) {
V_390 = V_391 -> V_353 ;
V_329 = 0 ;
break;
}
}
if ( V_329 )
goto V_135;
if ( ! F_197 ( V_386 ) )
goto V_135;
V_262 = V_185 ( V_262 , V_351 -> V_262 ) ;
V_263 = F_63 ( V_263 , V_351 -> V_263 ) ;
for ( V_79 = V_262 ; V_79 <= V_263 ; V_79 ++ ) {
if ( V_113 [ V_79 ] == V_386 ) {
F_48 ( V_386 -> V_111 ) ;
V_113 [ V_79 ] = NULL ;
}
}
if ( ! F_197 ( V_390 ) ) {
const struct V_385 * V_393 = V_112 ;
V_390 -> V_349 () ;
V_391 -> V_355 |= V_356 ;
V_112 = V_393 ;
}
if ( ! F_197 ( V_386 ) )
V_351 -> V_355 &= ~ V_356 ;
F_194 ( V_390 , V_262 , V_263 , V_387 ) ;
V_135:
F_48 ( V_111 ) ;
return V_329 ;
}
static int F_198 ( struct V_351 * V_353 )
{
const struct V_385 * V_390 = NULL , * V_386 = NULL ;
int V_79 , V_394 = 1 , V_262 = - 1 , V_263 = - 1 , V_387 = 0 ;
if ( ! V_353 -> V_353 || ! ( V_353 -> V_355 & V_392 ) )
goto V_135;
V_386 = V_353 -> V_353 ;
for ( V_79 = 0 ; V_79 < V_350 ; V_79 ++ ) {
struct V_351 * V_353 = & V_352 [ V_79 ] ;
if ( V_353 -> V_353 && ! ( V_353 -> V_355 & V_392 ) ) {
V_390 = V_353 -> V_353 ;
break;
}
}
if ( ! V_390 )
goto V_135;
while ( V_394 ) {
V_394 = 0 ;
for ( V_79 = V_353 -> V_262 ; V_79 <= V_353 -> V_263 ; V_79 ++ ) {
if ( V_113 [ V_79 ] == V_390 ) {
if ( V_262 == - 1 )
V_262 = V_79 ;
V_263 = V_79 ;
V_394 = 1 ;
} else if ( V_262 != - 1 )
break;
}
if ( V_262 == 0 && V_263 == V_108 - 1 )
V_387 = 1 ;
if ( V_262 != - 1 )
F_194 ( V_386 , V_262 , V_263 , V_387 ) ;
V_262 = - 1 ;
V_263 = - 1 ;
V_387 = 0 ;
}
V_135:
return 0 ;
}
static int F_199 ( struct V_351 * V_353 )
{
const struct V_385 * V_386 = NULL ;
int V_79 , V_394 = 1 , V_262 = - 1 , V_263 = - 1 , V_387 = 0 ;
int V_169 ;
if ( ! V_353 -> V_353 || ! ( V_353 -> V_355 & V_392 ) )
goto V_135;
V_386 = V_353 -> V_353 ;
while ( V_394 ) {
V_394 = 0 ;
for ( V_79 = V_353 -> V_262 ; V_79 <= V_353 -> V_263 ; V_79 ++ ) {
if ( V_113 [ V_79 ] == V_386 ) {
if ( V_262 == - 1 )
V_262 = V_79 ;
V_263 = V_79 ;
V_394 = 1 ;
} else if ( V_262 != - 1 )
break;
}
if ( V_262 == 0 && V_263 == V_108 - 1 )
V_387 = 1 ;
if ( V_262 != - 1 ) {
V_169 = F_196 ( V_386 , V_262 , V_263 , V_387 ) ;
if ( V_169 != 0 )
return V_169 ;
}
V_262 = - 1 ;
V_263 = - 1 ;
V_387 = 0 ;
}
V_135:
return 0 ;
}
static inline int F_198 ( struct V_351 * V_353 )
{
return 0 ;
}
static inline int F_199 ( struct V_351 * V_353 )
{
return 0 ;
}
static T_9 F_200 ( struct V_364 * V_365 , struct V_366 * V_367 ,
const char * V_197 , T_10 V_36 )
{
struct V_351 * V_353 = F_201 ( V_365 ) ;
int V_395 = F_202 ( V_197 , NULL , 0 ) ;
F_71 () ;
if ( V_395 )
F_198 ( V_353 ) ;
else
F_199 ( V_353 ) ;
F_72 () ;
return V_36 ;
}
static T_9 F_203 ( struct V_364 * V_365 , struct V_366 * V_367 ,
char * V_197 )
{
struct V_351 * V_353 = F_201 ( V_365 ) ;
int V_395 = F_197 ( V_353 -> V_353 ) ;
return snprintf ( V_197 , V_396 , L_21 , V_395 ) ;
}
static T_9 F_204 ( struct V_364 * V_365 , struct V_366 * V_367 ,
char * V_197 )
{
struct V_351 * V_353 = F_201 ( V_365 ) ;
return snprintf ( V_197 , V_396 , L_22 ,
( V_353 -> V_355 & V_392 ) ? L_23 : L_24 ,
V_353 -> V_354 ) ;
}
static int F_205 ( struct V_351 * V_353 )
{
V_353 -> V_355 |= V_397 ;
return 0 ;
}
static void F_206 ( struct V_351 * V_353 )
{
V_353 -> V_355 &= ~ V_397 ;
}
int F_197 ( const struct V_385 * V_386 )
{
int V_79 , V_398 = 0 ;
for ( V_79 = 0 ; V_79 < V_108 ; V_79 ++ ) {
if ( V_113 [ V_79 ] == V_386 ) {
V_398 = 1 ;
break;
}
}
return V_398 ;
}
int F_207 ( struct V_4 * V_5 )
{
int V_169 = 0 ;
V_399 = V_100 ;
V_400 = V_219 ;
V_401 = V_287 ;
V_402 = V_5 -> V_87 ;
V_403 = V_86 ;
V_5 -> V_87 = V_289 ;
V_86 = 0 ;
if ( V_5 -> V_16 -> F_207 )
V_169 = V_5 -> V_16 -> F_207 ( V_5 ) ;
#ifdef F_208
if ( V_5 -> V_27 < 999 ) {
int V_404 ;
char V_405 [ 4 ] ;
const char * V_406 [ 3 ] = {
L_25 ,
L_26 ,
V_405 ,
} ;
if ( F_209 ( V_406 [ 0 ] , & V_404 ) ) {
snprintf ( V_405 , 4 , L_27 , V_5 -> V_27 ) ;
F_210 ( 2 , V_406 ) ;
}
}
if ( V_5 -> V_31 < 999 ) {
int V_407 ;
char V_139 [ 4 ] ;
const char * V_406 [ 3 ] = {
L_25 ,
L_28 ,
V_139 ,
} ;
if ( F_209 ( V_406 [ 0 ] , & V_407 ) ) {
snprintf ( V_139 , 4 , L_27 , V_5 -> V_31 ) ;
F_210 ( 2 , V_406 ) ;
}
}
#endif
return V_169 ;
}
int F_211 ( void )
{
struct V_4 * V_5 ;
int V_169 = 0 ;
V_100 = V_399 ;
V_219 = V_400 ;
V_287 = V_401 ;
V_86 = V_403 ;
V_99 [ V_100 ] . V_25 -> V_87 = V_402 ;
V_5 = V_99 [ V_100 ] . V_25 ;
if ( V_5 -> V_16 -> F_211 )
V_169 = V_5 -> V_16 -> F_211 ( V_5 ) ;
return V_169 ;
}
static int F_212 ( const struct V_385 * V_386 , int V_262 , int V_263 )
{
struct V_388 * V_111 = V_386 -> V_111 ;
struct V_351 * V_351 ;
const char * V_354 ;
int V_79 , V_329 ;
F_21 () ;
if ( ! F_195 ( V_111 ) )
return - V_389 ;
for ( V_79 = 0 ; V_79 < V_350 ; V_79 ++ ) {
V_351 = & V_352 [ V_79 ] ;
if ( V_351 -> V_353 == V_386 ) {
V_329 = - V_408 ;
goto V_135;
}
}
V_354 = V_386 -> V_349 () ;
if ( ! V_354 ) {
V_329 = - V_389 ;
goto V_135;
}
V_329 = - V_156 ;
for ( V_79 = 0 ; V_79 < V_350 ; V_79 ++ ) {
V_351 = & V_352 [ V_79 ] ;
if ( V_351 -> V_353 == NULL &&
! ( V_351 -> V_355 & V_409 ) ) {
V_351 -> V_353 = V_386 ;
V_351 -> V_354 = V_354 ;
V_351 -> V_410 = V_79 ;
V_351 -> V_355 = V_392 |
V_356 ;
V_351 -> V_262 = V_262 ;
V_351 -> V_263 = V_263 ;
V_329 = 0 ;
break;
}
}
if ( V_329 )
goto V_135;
V_351 -> V_365 =
F_184 ( V_411 , NULL ,
F_181 ( 0 , V_351 -> V_410 ) ,
V_351 , V_412 ,
L_29 , V_351 -> V_410 ) ;
if ( F_185 ( V_351 -> V_365 ) ) {
F_128 ( V_413 L_30
L_31 , V_351 -> V_354 ,
F_213 ( V_351 -> V_365 ) ) ;
V_351 -> V_365 = NULL ;
} else {
F_205 ( V_351 ) ;
}
V_135:
F_48 ( V_111 ) ;
return V_329 ;
}
int F_214 ( const struct V_385 * V_386 )
{
int V_79 ;
if ( F_197 ( V_386 ) )
return - V_408 ;
if ( V_386 == V_112 )
return - V_156 ;
for ( V_79 = 0 ; V_79 < V_350 ; V_79 ++ ) {
struct V_351 * V_351 = & V_352 [ V_79 ] ;
if ( V_351 -> V_353 == V_386 ) {
V_351 -> V_353 = NULL ;
V_351 -> V_355 = V_409 ;
F_11 ( & V_414 ) ;
return 0 ;
}
}
return - V_389 ;
}
static void F_215 ( struct V_285 * V_286 )
{
int V_79 ;
F_71 () ;
for ( V_79 = 0 ; V_79 < V_350 ; V_79 ++ ) {
struct V_351 * V_351 = & V_352 [ V_79 ] ;
if ( ! ( V_351 -> V_355 & V_409 ) )
continue;
F_72 () ;
F_206 ( V_351 ) ;
F_216 ( V_411 , F_181 ( 0 , V_351 -> V_410 ) ) ;
F_71 () ;
if ( F_217 ( V_351 -> V_353 ) )
V_351 -> V_353 = NULL ;
V_351 -> V_354 = NULL ;
V_351 -> V_365 = NULL ;
V_351 -> V_410 = 0 ;
F_217 ( V_351 -> V_355 != V_409 ) ;
V_351 -> V_355 = 0 ;
V_351 -> V_262 = 0 ;
V_351 -> V_263 = 0 ;
}
F_72 () ;
}
int F_218 ( const struct V_385 * V_386 , int V_262 , int V_263 , int V_387 )
{
int V_135 ;
V_135 = F_212 ( V_386 , V_262 , V_263 ) ;
if ( V_135 == - V_408 )
V_135 = 0 ;
if ( ! V_135 )
F_194 ( V_386 , V_262 , V_263 , V_387 ) ;
return V_135 ;
}
void F_219 ( const struct V_385 * V_386 )
{
F_71 () ;
F_214 ( V_386 ) ;
F_72 () ;
}
static int T_8 F_220 ( void )
{
int V_79 ;
V_411 = F_221 ( V_415 , L_32 ) ;
if ( F_185 ( V_411 ) ) {
F_128 ( V_413 L_33
L_31 , F_213 ( V_411 ) ) ;
V_411 = NULL ;
}
for ( V_79 = 0 ; V_79 < V_350 ; V_79 ++ ) {
struct V_351 * V_353 = & V_352 [ V_79 ] ;
if ( V_353 -> V_353 && ! V_353 -> V_365 ) {
V_353 -> V_365 =
F_184 ( V_411 , NULL ,
F_181 ( 0 , V_353 -> V_410 ) ,
V_353 , V_412 ,
L_29 , V_353 -> V_410 ) ;
if ( F_185 ( V_353 -> V_365 ) ) {
F_128 ( V_413 L_34
L_35 ,
V_353 -> V_354 , F_213 ( V_353 -> V_365 ) ) ;
V_353 -> V_365 = NULL ;
} else {
F_205 ( V_353 ) ;
}
}
}
return 0 ;
}
static int F_152 ( char T_7 * V_14 )
{
unsigned int V_294 ;
if ( F_145 ( V_294 , V_14 + 1 ) )
return - V_312 ;
V_416 = ( V_294 < 4 ) ? V_294 : 0 ;
return 0 ;
}
void F_134 ( int V_417 )
{
struct V_4 * V_5 = V_99 [ V_100 ] . V_25 ;
int V_79 ;
F_21 () ;
if ( V_86 ) {
if ( V_357 == V_418 ) {
V_357 = V_419 ;
V_5 -> V_16 -> V_420 ( V_5 , V_416 + 1 , 0 ) ;
}
return;
}
if ( V_417 ) {
F_23 ( V_5 ) ;
F_38 ( V_5 ) ;
V_5 -> V_16 -> V_420 ( V_5 , - 1 , 1 ) ;
V_86 = V_100 + 1 ;
V_357 = V_419 ;
F_37 ( V_5 ) ;
return;
}
if ( V_357 != V_358 )
return;
V_357 = V_419 ;
if ( V_5 -> V_87 != V_289 ) {
V_86 = V_100 + 1 ;
return;
}
F_23 ( V_5 ) ;
F_222 ( & V_359 ) ;
V_291 = 0 ;
F_38 ( V_5 ) ;
V_79 = V_5 -> V_16 -> V_420 ( V_5 , V_217 ? 1 : ( V_416 + 1 ) , 0 ) ;
V_86 = V_100 + 1 ;
if ( V_79 )
F_37 ( V_5 ) ;
if ( V_421 && V_421 ( 1 ) )
return;
if ( V_217 && V_416 ) {
V_357 = V_418 ;
F_173 ( & V_359 , V_360 + V_217 ) ;
}
F_68 ( V_422 , V_5 -> V_102 , V_5 -> V_102 ) ;
}
void F_223 ( int V_423 )
{
struct V_4 * V_5 ;
if ( ! V_424 )
F_127 () ;
F_21 () ;
V_327 = 0 ;
if ( ! V_86 )
return;
if ( ! F_46 ( V_100 ) ) {
F_224 ( L_36 ,
V_100 + 1 ) ;
return;
}
V_5 = V_99 [ V_100 ] . V_25 ;
if ( V_5 -> V_87 != V_289 && ! F_43 ( V_5 ) )
return;
if ( V_212 ) {
F_173 ( & V_359 , V_360 + ( V_212 * V_218 ) ) ;
V_357 = V_358 ;
}
V_86 = 0 ;
if ( V_5 -> V_16 -> V_420 ( V_5 , 0 , V_423 ) || F_43 ( V_5 ) )
F_67 ( V_5 ) ;
if ( V_421 )
V_421 ( 0 ) ;
F_42 ( V_5 ) ;
F_24 ( V_5 ) ;
F_68 ( V_425 , V_5 -> V_102 , V_5 -> V_102 ) ;
}
void F_148 ( void )
{
F_223 ( 0 ) ;
}
static void F_225 ( unsigned long V_426 )
{
if ( F_226 ( ! F_227 () ) ) {
F_173 ( & V_359 , V_360 + ( V_212 * V_218 ) ) ;
return;
}
V_291 = 1 ;
F_11 ( & V_21 ) ;
}
void F_105 ( void )
{
F_21 () ;
F_127 () ;
F_228 ( & V_359 ) ;
V_291 = 0 ;
if ( V_327 || ! V_99 [ V_100 ] . V_25 || V_99 [ V_100 ] . V_25 -> V_87 == V_88 )
return;
if ( V_86 )
F_148 () ;
else if ( V_212 ) {
F_173 ( & V_359 , V_360 + ( V_212 * V_218 ) ) ;
V_357 = V_358 ;
}
}
static void F_42 ( struct V_4 * V_5 )
{
F_21 () ;
if ( V_5 -> V_87 != V_88 )
V_5 -> V_16 -> V_427 ( V_5 , V_195 ) ;
}
int F_229 ( unsigned char T_7 * V_307 )
{
int V_79 , V_253 , V_341 ;
unsigned char V_428 [ 3 * 16 ] ;
if ( F_230 ( V_428 , V_307 , sizeof( V_428 ) ) )
return - V_312 ;
F_71 () ;
for ( V_79 = V_341 = 0 ; V_79 < 16 ; V_79 ++ ) {
V_342 [ V_79 ] = V_428 [ V_341 ++ ] ;
V_343 [ V_79 ] = V_428 [ V_341 ++ ] ;
V_344 [ V_79 ] = V_428 [ V_341 ++ ] ;
}
for ( V_79 = 0 ; V_79 < V_108 ; V_79 ++ ) {
if ( ! F_46 ( V_79 ) )
continue;
for ( V_253 = V_341 = 0 ; V_253 < 16 ; V_253 ++ ) {
V_99 [ V_79 ] . V_25 -> V_254 [ V_341 ++ ] = V_342 [ V_253 ] ;
V_99 [ V_79 ] . V_25 -> V_254 [ V_341 ++ ] = V_343 [ V_253 ] ;
V_99 [ V_79 ] . V_25 -> V_254 [ V_341 ++ ] = V_344 [ V_253 ] ;
}
F_42 ( V_99 [ V_79 ] . V_25 ) ;
}
F_72 () ;
return 0 ;
}
int F_231 ( unsigned char T_7 * V_307 )
{
int V_79 , V_341 ;
unsigned char V_428 [ 3 * 16 ] ;
F_71 () ;
for ( V_79 = V_341 = 0 ; V_79 < 16 ; V_79 ++ ) {
V_428 [ V_341 ++ ] = V_342 [ V_79 ] ;
V_428 [ V_341 ++ ] = V_343 [ V_79 ] ;
V_428 [ V_341 ++ ] = V_344 [ V_79 ] ;
}
F_72 () ;
if ( F_232 ( V_307 , V_428 , sizeof( V_428 ) ) )
return - V_312 ;
return 0 ;
}
void F_118 ( struct V_4 * V_5 )
{
int V_253 , V_341 ;
for ( V_253 = V_341 = 0 ; V_253 < 16 ; V_253 ++ ) {
V_5 -> V_254 [ V_341 ++ ] = V_342 [ V_253 ] ;
V_5 -> V_254 [ V_341 ++ ] = V_343 [ V_253 ] ;
V_5 -> V_254 [ V_341 ++ ] = V_344 [ V_253 ] ;
}
F_42 ( V_5 ) ;
}
static int F_233 ( struct V_4 * V_5 , struct V_429 * V_430 )
{
struct V_431 V_432 ;
int V_433 = - V_156 ;
int V_9 ;
if ( V_430 -> V_308 ) {
V_432 . V_308 = F_57 ( V_434 , V_124 ) ;
if ( ! V_432 . V_308 )
return - V_125 ;
} else
V_432 . V_308 = NULL ;
F_71 () ;
if ( V_5 -> V_87 != V_289 )
V_433 = - V_156 ;
else if ( V_5 -> V_16 -> F_233 )
V_433 = V_5 -> V_16 -> F_233 ( V_5 , & V_432 ) ;
else
V_433 = - V_435 ;
F_72 () ;
if ( V_433 )
goto V_436;
V_9 = ( V_432 . V_132 + 7 ) / 8 * 32 * V_432 . V_437 ;
if ( V_430 -> V_308 && V_432 . V_437 > V_430 -> V_437 )
V_433 = - V_438 ;
if ( ! ( V_430 -> V_381 & V_439 ) ) {
if ( V_432 . V_132 > V_430 -> V_132 || V_432 . V_133 > V_430 -> V_133 )
V_433 = - V_438 ;
} else {
if ( V_432 . V_132 != 8 )
V_433 = - V_440 ;
else if ( ( V_430 -> V_133 && V_432 . V_133 > V_430 -> V_133 ) ||
V_432 . V_133 > 32 )
V_433 = - V_438 ;
}
if ( V_433 )
goto V_436;
V_430 -> V_133 = V_432 . V_133 ;
V_430 -> V_132 = V_432 . V_132 ;
V_430 -> V_437 = V_432 . V_437 ;
if ( V_430 -> V_308 && F_232 ( V_430 -> V_308 , V_432 . V_308 , V_9 ) )
V_433 = - V_312 ;
V_436:
F_60 ( V_432 . V_308 ) ;
return V_433 ;
}
static int F_234 ( struct V_4 * V_5 , struct V_429 * V_430 )
{
struct V_431 V_432 ;
int V_433 = - V_156 ;
int V_441 ;
if ( V_5 -> V_87 != V_289 )
return - V_156 ;
if ( ! V_430 -> V_308 )
return - V_156 ;
if ( V_430 -> V_437 > 512 )
return - V_156 ;
if ( ! V_430 -> V_133 ) {
int V_442 , V_79 ;
T_2 T_7 * V_443 = V_430 -> V_308 ;
T_2 V_444 ;
if ( ! ( V_430 -> V_381 & V_439 ) )
return - V_156 ;
for ( V_442 = 32 ; V_442 > 0 ; V_442 -- )
for ( V_79 = 0 ; V_79 < V_430 -> V_437 ; V_79 ++ ) {
if ( F_145 ( V_444 , & V_443 [ 32 * V_79 + V_442 - 1 ] ) )
return - V_312 ;
if ( V_444 )
goto V_445;
}
return - V_156 ;
V_445:
V_430 -> V_133 = V_442 ;
}
if ( V_430 -> V_132 <= 0 || V_430 -> V_132 > 32 || V_430 -> V_133 > 32 )
return - V_156 ;
V_441 = ( V_430 -> V_132 + 7 ) / 8 * 32 * V_430 -> V_437 ;
if ( V_441 > V_434 )
return - V_438 ;
V_432 . V_437 = V_430 -> V_437 ;
V_432 . V_133 = V_430 -> V_133 ;
V_432 . V_132 = V_430 -> V_132 ;
V_432 . V_308 = F_235 ( V_430 -> V_308 , V_441 ) ;
if ( F_185 ( V_432 . V_308 ) )
return F_213 ( V_432 . V_308 ) ;
F_71 () ;
if ( V_5 -> V_87 != V_289 )
V_433 = - V_156 ;
else if ( V_5 -> V_16 -> F_234 )
V_433 = V_5 -> V_16 -> F_234 ( V_5 , & V_432 , V_430 -> V_381 ) ;
else
V_433 = - V_435 ;
F_72 () ;
F_60 ( V_432 . V_308 ) ;
return V_433 ;
}
static int F_236 ( struct V_4 * V_5 , struct V_429 * V_430 )
{
struct V_431 V_432 = { . V_132 = V_430 -> V_132 , . V_133 = V_430 -> V_133 } ;
char V_374 [ V_446 ] ;
char * V_26 = V_374 ;
int V_433 ;
if ( ! V_430 -> V_308 )
V_26 = NULL ;
else if ( F_237 ( V_374 , V_430 -> V_308 , V_446 - 1 ) < 0 )
return - V_312 ;
else
V_374 [ V_446 - 1 ] = 0 ;
F_71 () ;
if ( V_5 -> V_87 != V_289 ) {
F_72 () ;
return - V_156 ;
}
if ( V_5 -> V_16 -> F_236 )
V_433 = V_5 -> V_16 -> F_236 ( V_5 , & V_432 , V_26 ) ;
else
V_433 = - V_435 ;
F_72 () ;
if ( ! V_433 ) {
V_430 -> V_132 = V_432 . V_132 ;
V_430 -> V_133 = V_432 . V_133 ;
}
return V_433 ;
}
static int F_238 ( struct V_4 * V_5 , struct V_429 * V_430 )
{
int V_353 = V_430 -> V_133 ;
int V_433 ;
F_71 () ;
if ( V_5 -> V_87 != V_289 )
V_433 = - V_156 ;
else if ( ! V_5 -> V_16 -> F_238 )
V_433 = - V_435 ;
else if ( V_353 < 0 || ! F_46 ( V_353 ) )
V_433 = - V_447 ;
else if ( V_353 == V_5 -> V_102 )
V_433 = 0 ;
else
V_433 = V_5 -> V_16 -> F_238 ( V_5 , V_353 ) ;
F_72 () ;
return V_433 ;
}
int F_239 ( struct V_4 * V_5 , struct V_429 * V_430 )
{
switch ( V_430 -> V_430 ) {
case V_448 :
return F_234 ( V_5 , V_430 ) ;
case V_449 :
return F_233 ( V_5 , V_430 ) ;
case V_450 :
return F_236 ( V_5 , V_430 ) ;
case V_451 :
return F_238 ( V_5 , V_430 ) ;
}
return - V_435 ;
}
T_1 F_240 ( struct V_4 * V_5 , int V_12 )
{
T_1 V_452 = F_19 ( F_8 ( V_5 , V_12 , 1 ) ) ;
T_1 V_9 = V_452 & 0xff ;
if ( V_452 & V_5 -> V_57 )
V_9 |= 0x100 ;
return V_9 ;
}
unsigned short * F_241 ( struct V_4 * V_5 , int V_453 , int V_13 )
{
return F_8 ( V_5 , 2 * V_453 , V_13 ) ;
}
void F_242 ( struct V_4 * V_5 , unsigned char * V_14 )
{
V_14 [ 0 ] = V_5 -> V_77 ;
V_14 [ 1 ] = V_5 -> V_82 ;
}
void F_243 ( struct V_4 * V_5 , unsigned char * V_14 )
{
F_23 ( V_5 ) ;
F_64 ( V_5 , V_14 [ 0 ] , V_14 [ 1 ] ) ;
F_24 ( V_5 ) ;
}
T_1 F_244 ( struct V_4 * V_5 , const T_1 * V_454 )
{
if ( ( unsigned long ) V_454 == V_5 -> V_76 && V_81 != - 1 )
return V_81 ;
return F_19 ( V_454 ) ;
}
void F_245 ( struct V_4 * V_5 , T_1 V_455 , T_1 * V_454 )
{
F_28 ( V_455 , V_454 ) ;
if ( ( unsigned long ) V_454 == V_5 -> V_76 ) {
V_81 = - 1 ;
F_33 ( V_5 ) ;
}
}
void F_246 ( struct V_4 * V_5 )
{
F_7 ( V_5 ) ;
}
