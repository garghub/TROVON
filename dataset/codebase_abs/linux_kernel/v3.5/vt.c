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
unsigned short * V_14 , * V_44 = ( unsigned short * ) V_5 -> V_76 ;
V_14 = V_44 + V_5 -> V_31 - V_24 - V_5 -> V_77 ;
while ( -- V_14 >= V_44 )
F_28 ( F_19 ( V_14 ) , V_14 + V_24 ) ;
F_15 ( V_44 , V_5 -> V_32 , V_24 * 2 ) ;
V_5 -> V_78 = 0 ;
if ( F_22 ( V_5 ) ) {
unsigned short V_79 = V_5 -> V_58 ;
V_5 -> V_16 -> V_80 ( V_5 , V_5 -> V_81 , V_5 -> V_77 , V_5 -> V_81 , V_5 -> V_77 + V_24 , 1 ,
V_5 -> V_31 - V_5 -> V_77 - V_24 ) ;
V_5 -> V_58 = V_5 -> V_32 >> 8 ;
while ( V_24 -- )
V_5 -> V_16 -> V_73 ( V_5 , V_5 -> V_32 , V_5 -> V_81 , V_5 -> V_77 + V_24 ) ;
V_5 -> V_58 = V_79 ;
}
}
static void F_31 ( struct V_4 * V_5 , unsigned int V_24 )
{
unsigned int V_82 = V_5 -> V_77 ;
unsigned short * V_14 = ( unsigned short * ) V_5 -> V_76 ;
while ( ++ V_82 <= V_5 -> V_31 - V_24 ) {
F_28 ( F_19 ( V_14 + V_24 ) , V_14 ) ;
V_14 ++ ;
}
F_15 ( V_14 , V_5 -> V_32 , V_24 * 2 ) ;
V_5 -> V_78 = 0 ;
if ( F_22 ( V_5 ) ) {
unsigned short V_79 = V_5 -> V_58 ;
V_5 -> V_16 -> V_80 ( V_5 , V_5 -> V_81 , V_5 -> V_77 + V_24 , V_5 -> V_81 , V_5 -> V_77 , 1 ,
V_5 -> V_31 - V_5 -> V_77 - V_24 ) ;
V_5 -> V_58 = V_5 -> V_32 >> 8 ;
while ( V_24 -- )
V_5 -> V_16 -> V_73 ( V_5 , V_5 -> V_32 , V_5 -> V_81 ,
V_5 -> V_31 - 1 - V_24 ) ;
V_5 -> V_58 = V_79 ;
}
}
static void F_32 ( struct V_4 * V_5 )
{
int V_82 = F_19 ( ( T_1 * ) V_5 -> V_76 ) ;
T_3 type = V_5 -> V_83 ;
if ( ! ( type & 0x10 ) ) return;
if ( V_84 != - 1 ) return;
V_84 = V_82 ;
V_82 |= ( ( type >> 8 ) & 0xff00 ) ;
V_82 ^= ( ( type ) & 0xff00 ) ;
if ( ( type & 0x20 ) && ( ( V_84 & 0x7000 ) == ( V_82 & 0x7000 ) ) ) V_82 ^= 0x7000 ;
if ( ( type & 0x40 ) && ( ( V_82 & 0x700 ) == ( ( V_82 & 0x7000 ) >> 4 ) ) ) V_82 ^= 0x0700 ;
F_28 ( V_82 , ( T_1 * ) V_5 -> V_76 ) ;
if ( F_22 ( V_5 ) )
V_5 -> V_16 -> V_73 ( V_5 , V_82 , V_5 -> V_81 , V_5 -> V_77 ) ;
}
static void F_33 ( struct V_4 * V_5 )
{
if ( V_84 != - 1 ) {
F_28 ( V_84 , ( T_1 * ) V_5 -> V_76 ) ;
if ( F_22 ( V_5 ) )
V_5 -> V_16 -> V_73 ( V_5 , V_84 ,
V_5 -> V_81 , V_5 -> V_77 ) ;
V_84 = - 1 ;
}
}
static void F_23 ( struct V_4 * V_5 )
{
if ( V_5 == V_85 )
F_34 () ;
V_5 -> V_16 -> V_86 ( V_5 , V_87 ) ;
F_33 ( V_5 ) ;
}
static void F_24 ( struct V_4 * V_5 )
{
if ( ! F_35 ( V_5 ) || V_88 ||
V_5 -> V_89 == V_90 )
return;
if ( V_5 -> V_91 ) {
if ( V_5 == V_85 )
F_34 () ;
F_32 ( V_5 ) ;
if ( ( V_5 -> V_83 & 0x0f ) != 1 )
V_5 -> V_16 -> V_86 ( V_5 , V_92 ) ;
} else
F_23 ( V_5 ) ;
}
static void F_36 ( struct V_4 * V_5 )
{
F_21 () ;
if ( ! F_13 ( V_5 ) ||
! V_5 -> V_16 -> V_93 ||
! V_5 -> V_16 -> V_93 ( V_5 ) )
V_5 -> V_15 = ( unsigned long ) V_5 -> V_94 ;
V_5 -> V_18 = V_5 -> V_15 ;
V_5 -> V_95 = V_5 -> V_15 + V_5 -> V_72 ;
V_5 -> V_76 = V_5 -> V_15 + V_5 -> V_30 * V_5 -> V_81 + 2 * V_5 -> V_77 ;
}
static inline void F_37 ( struct V_4 * V_5 )
{
F_21 () ;
if ( V_5 -> V_16 -> V_96 )
V_5 -> V_16 -> V_96 ( V_5 ) ;
}
static void F_38 ( struct V_4 * V_5 )
{
unsigned short * V_14 = ( unsigned short * ) V_5 -> V_15 ;
int V_36 = V_5 -> V_72 / 2 ;
int V_97 = V_5 -> V_57 | 0xff ;
for (; V_36 > 0 ; V_36 -- , V_14 ++ ) {
F_28 ( ( F_19 ( V_14 ) & V_97 ) | ( V_5 -> V_32 & ~ V_97 ) , V_14 ) ;
}
}
void F_39 ( struct V_4 * V_5 , int V_98 )
{
int V_99 = 0 ;
F_21 () ;
if ( ! V_5 ) {
return;
}
if ( V_98 ) {
struct V_4 * V_100 = V_101 [ V_102 ] . V_25 ;
if ( V_100 == V_5 )
return;
if ( ! F_13 ( V_5 ) )
V_99 = 1 ;
* V_5 -> V_103 = V_5 ;
V_102 = V_5 -> V_104 ;
F_23 ( V_100 ) ;
if ( ! F_13 ( V_100 ) ) {
F_37 ( V_100 ) ;
F_36 ( V_100 ) ;
}
if ( V_105 )
F_40 ( & V_105 -> V_106 , NULL , L_1 ) ;
} else {
F_23 ( V_5 ) ;
V_99 = 1 ;
}
if ( V_99 ) {
int V_107 ;
int V_108 = V_5 -> V_54 ;
F_36 ( V_5 ) ;
V_107 = V_5 -> V_16 -> V_109 ( V_5 ) ;
F_41 ( V_5 ) ;
if ( V_108 != V_5 -> V_54 ) {
F_26 ( V_5 ) ;
F_38 ( V_5 ) ;
}
if ( ( V_107 && V_5 -> V_89 != V_90 ) ||
F_42 ( V_5 ) )
F_17 ( V_5 , V_5 -> V_15 , V_5 -> V_72 / 2 ) ;
}
F_24 ( V_5 ) ;
if ( V_98 ) {
F_43 () ;
F_44 () ;
F_7 ( V_5 ) ;
}
}
int F_45 ( unsigned int V_82 )
{
return ( V_82 < V_110 && V_101 [ V_82 ] . V_25 ) ;
}
static void F_46 ( struct V_4 * V_5 , int V_111 , int V_112 )
{
if ( V_5 -> V_16 )
F_47 ( V_5 -> V_16 -> V_113 ) ;
V_5 -> V_16 = V_114 ;
#ifndef F_48
if ( V_115 [ V_111 ] )
V_5 -> V_16 = V_115 [ V_111 ] ;
#endif
F_49 ( V_5 -> V_16 -> V_113 ) ;
V_5 -> V_104 = V_111 ;
V_5 -> V_103 = & V_116 ;
V_5 -> V_117 = & V_5 -> V_118 ;
V_5 -> V_118 = 0 ;
V_5 -> V_57 = 0 ;
V_5 -> V_75 = 0 ;
V_5 -> V_54 = 0 ;
V_5 -> V_119 = false ;
V_5 -> V_16 -> V_120 ( V_5 , V_112 ) ;
if ( ! V_5 -> V_75 )
V_5 -> V_75 = V_5 -> V_54 ? 0x7700 : 0x0800 ;
V_5 -> V_121 = V_5 -> V_75 ;
V_5 -> V_30 = V_5 -> V_31 << 1 ;
V_5 -> V_72 = V_5 -> V_27 * V_5 -> V_30 ;
}
int F_50 ( unsigned int V_122 )
{
F_21 () ;
if ( V_122 >= V_110 )
return - V_123 ;
if ( ! V_101 [ V_122 ] . V_25 ) {
struct V_4 * V_5 ;
struct V_7 V_8 ;
if ( V_122 >= V_124 && ! F_51 ( V_125 ) )
return - V_126 ;
V_8 . V_5 = V_5 = F_52 ( sizeof( struct V_4 ) , V_127 ) ;
if ( ! V_5 )
return - V_128 ;
V_101 [ V_122 ] . V_25 = V_5 ;
F_53 ( & V_5 -> V_129 ) ;
F_54 ( & V_101 [ V_122 ] . V_130 , V_131 ) ;
F_46 ( V_5 , V_122 , 1 ) ;
if ( ! * V_5 -> V_117 )
F_55 ( V_5 ) ;
V_5 -> V_94 = F_56 ( V_5 -> V_72 , V_127 ) ;
if ( ! V_5 -> V_94 ) {
F_57 ( V_5 ) ;
V_101 [ V_122 ] . V_25 = NULL ;
return - V_128 ;
}
if ( V_132 == - 1 )
V_132 = 1 ;
F_58 ( V_5 , V_5 -> V_27 , V_5 -> V_31 , 1 ) ;
F_59 ( V_122 ) ;
F_6 ( & V_3 , V_133 , & V_8 ) ;
}
return 0 ;
}
static inline int F_60 ( struct V_4 * V_5 , int V_134 , int V_135 ,
int V_136 )
{
int V_137 = 0 ;
if ( V_5 -> V_89 != V_90 && V_5 -> V_16 -> V_138 )
V_137 = V_5 -> V_16 -> V_138 ( V_5 , V_134 , V_135 , V_136 ) ;
return V_137 ;
}
static int F_61 ( struct V_139 * V_140 , struct V_4 * V_5 ,
unsigned int V_141 , unsigned int V_19 )
{
unsigned long V_142 , V_143 , V_144 , V_145 , V_146 , V_137 = 0 ;
unsigned long V_147 ;
unsigned int V_148 , V_149 ;
unsigned int V_150 , V_151 , V_152 , V_153 ;
unsigned int V_136 ;
unsigned short * V_154 ;
F_21 () ;
if ( ! V_5 )
return - V_123 ;
V_136 = V_5 -> V_155 ;
V_5 -> V_155 = 0 ;
if ( V_141 > V_156 || V_19 > V_157 )
return - V_158 ;
V_150 = ( V_141 ? V_141 : V_5 -> V_31 ) ;
V_151 = ( V_19 ? V_19 : V_5 -> V_27 ) ;
V_152 = V_150 << 1 ;
V_153 = V_152 * V_151 ;
if ( V_150 == V_5 -> V_31 && V_151 == V_5 -> V_27 )
return 0 ;
V_154 = F_56 ( V_153 , V_159 ) ;
if ( ! V_154 )
return - V_128 ;
V_148 = V_5 -> V_27 ;
V_149 = V_5 -> V_30 ;
V_137 = F_60 ( V_5 , V_150 , V_151 , V_136 ) ;
if ( V_137 ) {
F_57 ( V_154 ) ;
return V_137 ;
}
V_5 -> V_27 = V_151 ;
V_5 -> V_31 = V_150 ;
V_5 -> V_30 = V_152 ;
V_5 -> V_72 = V_153 ;
V_145 = F_62 ( V_149 , V_152 ) ;
V_146 = V_152 - V_145 ;
V_142 = V_5 -> V_15 ;
V_143 = ( long ) V_154 ;
V_144 = V_143 + V_153 ;
if ( V_5 -> V_81 > V_151 ) {
if ( V_148 - V_5 -> V_81 < V_151 ) {
V_142 += ( V_148 - V_151 ) * V_149 ;
} else {
V_142 += ( V_5 -> V_81 - V_151 / 2 ) * V_149 ;
}
}
V_147 = V_142 + V_149 * F_62 ( V_148 , V_151 ) ;
F_26 ( V_5 ) ;
while ( V_142 < V_147 ) {
F_63 ( ( unsigned short * ) V_143 ,
( unsigned short * ) V_142 , V_145 ) ;
if ( V_146 )
F_15 ( ( void * ) ( V_143 + V_145 ) ,
V_5 -> V_32 , V_146 ) ;
V_142 += V_149 ;
V_143 += V_152 ;
}
if ( V_144 > V_143 )
F_15 ( ( void * ) V_143 , V_5 -> V_32 ,
V_144 - V_143 ) ;
F_57 ( V_5 -> V_94 ) ;
V_5 -> V_94 = V_154 ;
V_5 -> V_72 = V_153 ;
F_36 ( V_5 ) ;
V_5 -> V_160 = 0 ;
V_5 -> V_161 = V_5 -> V_27 ;
F_64 ( V_5 , V_5 -> V_77 , V_5 -> V_81 ) ;
F_65 ( V_5 ) ;
if ( V_140 ) {
struct V_162 V_163 ;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_163 . V_164 = V_5 -> V_27 ;
V_163 . V_165 = V_5 -> V_31 ;
V_163 . V_166 = V_5 -> V_167 ;
F_66 ( V_140 , & V_163 ) ;
}
if ( F_13 ( V_5 ) )
F_67 ( V_5 ) ;
F_68 ( V_168 , V_5 -> V_104 , V_5 -> V_104 ) ;
return V_137 ;
}
int F_69 ( struct V_4 * V_5 , unsigned int V_141 , unsigned int V_169 )
{
return F_61 ( V_5 -> V_129 . V_140 , V_5 , V_141 , V_169 ) ;
}
static int F_70 ( struct V_139 * V_140 , struct V_162 * V_163 )
{
struct V_4 * V_5 = V_140 -> V_170 ;
int V_171 ;
F_71 () ;
V_171 = F_61 ( V_140 , V_5 , V_163 -> V_165 , V_163 -> V_164 ) ;
F_72 () ;
return V_171 ;
}
void F_73 ( unsigned int V_122 )
{
F_21 () ;
if ( F_45 ( V_122 ) ) {
struct V_4 * V_5 = V_101 [ V_122 ] . V_25 ;
struct V_7 V_8 = { . V_5 = V_5 } ;
F_6 ( & V_3 , V_172 , & V_8 ) ;
F_74 ( V_122 ) ;
V_5 -> V_16 -> V_173 ( V_5 ) ;
F_75 ( V_5 -> V_174 ) ;
F_47 ( V_5 -> V_16 -> V_113 ) ;
F_57 ( V_5 -> V_94 ) ;
if ( V_122 >= V_175 )
F_57 ( V_5 ) ;
V_101 [ V_122 ] . V_25 = NULL ;
}
}
static void F_64 ( struct V_4 * V_5 , int V_176 , int V_177 )
{
int V_178 , V_179 ;
if ( V_176 < 0 )
V_5 -> V_77 = 0 ;
else {
if ( V_176 >= V_5 -> V_31 )
V_5 -> V_77 = V_5 -> V_31 - 1 ;
else
V_5 -> V_77 = V_176 ;
}
if ( V_5 -> V_180 ) {
V_178 = V_5 -> V_160 ;
V_179 = V_5 -> V_161 ;
} else {
V_178 = 0 ;
V_179 = V_5 -> V_27 ;
}
if ( V_177 < V_178 )
V_5 -> V_81 = V_178 ;
else if ( V_177 >= V_179 )
V_5 -> V_81 = V_179 - 1 ;
else
V_5 -> V_81 = V_177 ;
V_5 -> V_76 = V_5 -> V_15 + V_5 -> V_81 * V_5 -> V_30 + ( V_5 -> V_77 << 1 ) ;
V_5 -> V_78 = 0 ;
}
static void F_76 ( struct V_4 * V_5 , int V_176 , int V_177 )
{
F_64 ( V_5 , V_176 , V_5 -> V_180 ? ( V_5 -> V_160 + V_177 ) : V_177 ) ;
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
if ( V_5 -> V_81 + 1 == V_5 -> V_161 )
F_12 ( V_5 , V_5 -> V_160 , V_5 -> V_161 , 1 ) ;
else if ( V_5 -> V_81 < V_5 -> V_27 - 1 ) {
V_5 -> V_81 ++ ;
V_5 -> V_76 += V_5 -> V_30 ;
}
V_5 -> V_78 = 0 ;
F_5 ( V_5 , '\n' ) ;
}
static void F_80 ( struct V_4 * V_5 )
{
if ( V_5 -> V_81 == V_5 -> V_160 )
F_16 ( V_5 , V_5 -> V_160 , V_5 -> V_161 , 1 ) ;
else if ( V_5 -> V_81 > 0 ) {
V_5 -> V_81 -- ;
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
static void F_84 ( struct V_4 * V_5 , int V_181 )
{
unsigned int V_36 ;
unsigned short * V_35 ;
switch ( V_181 ) {
case 0 :
V_36 = ( V_5 -> V_95 - V_5 -> V_76 ) >> 1 ;
V_35 = ( unsigned short * ) V_5 -> V_76 ;
if ( F_22 ( V_5 ) ) {
V_5 -> V_16 -> V_182 ( V_5 , V_5 -> V_81 , V_5 -> V_77 , 1 ,
V_5 -> V_31 - V_5 -> V_77 ) ;
V_5 -> V_16 -> V_182 ( V_5 , V_5 -> V_81 + 1 , 0 ,
V_5 -> V_27 - V_5 -> V_81 - 1 ,
V_5 -> V_31 ) ;
}
break;
case 1 :
V_36 = ( ( V_5 -> V_76 - V_5 -> V_15 ) >> 1 ) + 1 ;
V_35 = ( unsigned short * ) V_5 -> V_15 ;
if ( F_22 ( V_5 ) ) {
V_5 -> V_16 -> V_182 ( V_5 , 0 , 0 , V_5 -> V_81 ,
V_5 -> V_31 ) ;
V_5 -> V_16 -> V_182 ( V_5 , V_5 -> V_81 , 0 , 1 ,
V_5 -> V_77 + 1 ) ;
}
break;
case 3 :
F_15 ( V_5 -> V_94 , V_5 -> V_32 ,
V_5 -> V_72 >> 1 ) ;
F_36 ( V_5 ) ;
if ( F_13 ( V_5 ) )
F_67 ( V_5 ) ;
case 2 :
V_36 = V_5 -> V_31 * V_5 -> V_27 ;
V_35 = ( unsigned short * ) V_5 -> V_15 ;
if ( F_22 ( V_5 ) )
V_5 -> V_16 -> V_182 ( V_5 , 0 , 0 ,
V_5 -> V_27 ,
V_5 -> V_31 ) ;
break;
default:
return;
}
F_15 ( V_35 , V_5 -> V_32 , 2 * V_36 ) ;
V_5 -> V_78 = 0 ;
}
static void F_85 ( struct V_4 * V_5 , int V_181 )
{
unsigned int V_36 ;
unsigned short * V_35 ;
switch ( V_181 ) {
case 0 :
V_36 = V_5 -> V_31 - V_5 -> V_77 ;
V_35 = ( unsigned short * ) V_5 -> V_76 ;
if ( F_22 ( V_5 ) )
V_5 -> V_16 -> V_182 ( V_5 , V_5 -> V_81 , V_5 -> V_77 , 1 ,
V_5 -> V_31 - V_5 -> V_77 ) ;
break;
case 1 :
V_35 = ( unsigned short * ) ( V_5 -> V_76 - ( V_5 -> V_77 << 1 ) ) ;
V_36 = V_5 -> V_77 + 1 ;
if ( F_22 ( V_5 ) )
V_5 -> V_16 -> V_182 ( V_5 , V_5 -> V_81 , 0 , 1 ,
V_5 -> V_77 + 1 ) ;
break;
case 2 :
V_35 = ( unsigned short * ) ( V_5 -> V_76 - ( V_5 -> V_77 << 1 ) ) ;
V_36 = V_5 -> V_31 ;
if ( F_22 ( V_5 ) )
V_5 -> V_16 -> V_182 ( V_5 , V_5 -> V_81 , 0 , 1 ,
V_5 -> V_31 ) ;
break;
default:
return;
}
F_15 ( V_35 , V_5 -> V_32 , 2 * V_36 ) ;
V_5 -> V_78 = 0 ;
}
static void F_86 ( struct V_4 * V_5 , int V_181 )
{
int V_36 ;
if ( ! V_181 )
V_181 ++ ;
V_36 = ( V_181 > V_5 -> V_31 - V_5 -> V_77 ) ? ( V_5 -> V_31 - V_5 -> V_77 ) : V_181 ;
F_15 ( ( unsigned short * ) V_5 -> V_76 , V_5 -> V_32 , 2 * V_36 ) ;
if ( F_22 ( V_5 ) )
V_5 -> V_16 -> V_182 ( V_5 , V_5 -> V_81 , V_5 -> V_77 , 1 , V_36 ) ;
V_5 -> V_78 = 0 ;
}
static void F_87 ( struct V_4 * V_5 )
{
V_5 -> V_60 = 1 ;
V_5 -> V_65 = 0 ;
V_5 -> V_62 = 0 ;
V_5 -> V_63 = 0 ;
V_5 -> V_61 = 0 ;
V_5 -> V_59 = V_5 -> V_183 ;
}
static void F_88 ( struct V_4 * V_5 )
{
int V_82 ;
for ( V_82 = 0 ; V_82 <= V_5 -> V_184 ; V_82 ++ )
switch ( V_5 -> V_185 [ V_82 ] ) {
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
V_5 -> V_186 = F_89 ( V_5 -> V_187 == 0
? V_5 -> V_188
: V_5 -> V_189 , V_5 ) ;
V_5 -> V_190 = 0 ;
V_5 -> V_191 = 0 ;
break;
case 11 :
V_5 -> V_186 = F_89 ( V_192 , V_5 ) ;
V_5 -> V_190 = 1 ;
V_5 -> V_191 = 0 ;
break;
case 12 :
V_5 -> V_186 = F_89 ( V_192 , V_5 ) ;
V_5 -> V_190 = 1 ;
V_5 -> V_191 = 1 ;
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
V_5 -> V_59 = ( V_5 -> V_183 & 0x0f ) | ( V_5 -> V_59 & 0xf0 ) ;
V_5 -> V_62 = 1 ;
break;
case 39 :
V_5 -> V_59 = ( V_5 -> V_183 & 0x0f ) | ( V_5 -> V_59 & 0xf0 ) ;
V_5 -> V_62 = 0 ;
break;
case 49 :
V_5 -> V_59 = ( V_5 -> V_183 & 0xf0 ) | ( V_5 -> V_59 & 0x0f ) ;
break;
default:
if ( V_5 -> V_185 [ V_82 ] >= 30 && V_5 -> V_185 [ V_82 ] <= 37 )
V_5 -> V_59 = V_193 [ V_5 -> V_185 [ V_82 ] - 30 ]
| ( V_5 -> V_59 & 0xf0 ) ;
else if ( V_5 -> V_185 [ V_82 ] >= 40 && V_5 -> V_185 [ V_82 ] <= 47 )
V_5 -> V_59 = ( V_193 [ V_5 -> V_185 [ V_82 ] - 40 ] << 4 )
| ( V_5 -> V_59 & 0x0f ) ;
break;
}
F_26 ( V_5 ) ;
}
static void F_90 ( const char * V_14 , struct V_139 * V_140 )
{
while ( * V_14 ) {
F_91 ( V_140 , * V_14 , 0 ) ;
V_14 ++ ;
}
F_92 ( V_140 ) ;
}
static void F_93 ( struct V_4 * V_5 , struct V_139 * V_140 )
{
char V_194 [ 40 ] ;
sprintf ( V_194 , L_2 , V_5 -> V_81 + ( V_5 -> V_180 ? V_5 -> V_160 + 1 : 1 ) , V_5 -> V_77 + 1 ) ;
F_90 ( V_194 , V_140 ) ;
}
static inline void F_94 ( struct V_139 * V_140 )
{
F_90 ( L_3 , V_140 ) ;
}
static inline void F_95 ( struct V_139 * V_140 )
{
F_90 ( V_195 , V_140 ) ;
}
void F_96 ( struct V_139 * V_140 , int V_196 , int V_197 , int V_198 )
{
char V_194 [ 8 ] ;
sprintf ( V_194 , L_4 , ( char ) ( ' ' + V_196 ) , ( char ) ( '!' + V_197 ) ,
( char ) ( '!' + V_198 ) ) ;
F_90 ( V_194 , V_140 ) ;
}
int F_97 ( void )
{
return V_101 [ V_102 ] . V_25 -> V_199 ;
}
static void F_98 ( struct V_4 * V_5 , int V_200 )
{
int V_82 ;
for ( V_82 = 0 ; V_82 <= V_5 -> V_184 ; V_82 ++ )
if ( V_5 -> V_201 ) {
switch( V_5 -> V_185 [ V_82 ] ) {
case 1 :
if ( V_200 )
F_99 ( V_5 , V_202 ) ;
else
F_100 ( V_5 , V_202 ) ;
break;
case 3 :
V_5 -> V_203 = V_200 ;
#if 0
vc_resize(deccolm ? 132 : 80, vc->vc_rows);
#endif
break;
case 5 :
if ( V_5 -> V_64 != V_200 ) {
V_5 -> V_64 = V_200 ;
F_27 ( V_5 , 0 , V_5 -> V_72 , 0 ) ;
F_26 ( V_5 ) ;
}
break;
case 6 :
V_5 -> V_180 = V_200 ;
F_76 ( V_5 , 0 , 0 ) ;
break;
case 7 :
V_5 -> V_204 = V_200 ;
break;
case 8 :
if ( V_200 )
F_99 ( V_5 , V_205 ) ;
else
F_100 ( V_5 , V_205 ) ;
break;
case 9 :
V_5 -> V_199 = V_200 ? 1 : 0 ;
break;
case 25 :
V_5 -> V_91 = V_200 ;
break;
case 1000 :
V_5 -> V_199 = V_200 ? 2 : 0 ;
break;
}
} else {
switch( V_5 -> V_185 [ V_82 ] ) {
case 3 :
V_5 -> V_190 = V_200 ;
break;
case 4 :
V_5 -> V_206 = V_200 ;
break;
case 20 :
if ( V_200 )
F_99 ( V_5 , V_207 ) ;
else
F_100 ( V_5 , V_207 ) ;
break;
}
}
}
static void F_101 ( struct V_4 * V_5 )
{
switch( V_5 -> V_185 [ 0 ] ) {
case 1 :
if ( V_5 -> V_54 &&
V_5 -> V_185 [ 1 ] < 16 ) {
V_5 -> V_56 = V_193 [ V_5 -> V_185 [ 1 ] ] ;
if ( V_5 -> V_62 )
F_26 ( V_5 ) ;
}
break;
case 2 :
if ( V_5 -> V_54 &&
V_5 -> V_185 [ 1 ] < 16 ) {
V_5 -> V_208 = V_193 [ V_5 -> V_185 [ 1 ] ] ;
if ( V_5 -> V_60 == 0 )
F_26 ( V_5 ) ;
}
break;
case 8 :
V_5 -> V_183 = V_5 -> V_58 ;
if ( V_5 -> V_57 == 0x100 )
V_5 -> V_183 >>= 1 ;
F_87 ( V_5 ) ;
F_26 ( V_5 ) ;
break;
case 9 :
V_209 = ( ( V_5 -> V_185 [ 1 ] < 60 ) ? V_5 -> V_185 [ 1 ] : 60 ) * 60 ;
F_102 () ;
break;
case 10 :
if ( V_5 -> V_184 >= 1 )
V_5 -> V_210 = V_5 -> V_185 [ 1 ] ;
else
V_5 -> V_210 = V_211 ;
break;
case 11 :
if ( V_5 -> V_184 >= 1 )
V_5 -> V_212 = ( V_5 -> V_185 [ 1 ] < 2000 ) ?
V_5 -> V_185 [ 1 ] * V_213 / 1000 : 0 ;
else
V_5 -> V_212 = V_214 ;
break;
case 12 :
if ( V_5 -> V_185 [ 1 ] >= 1 && F_45 ( V_5 -> V_185 [ 1 ] - 1 ) )
F_103 ( V_5 -> V_185 [ 1 ] - 1 ) ;
break;
case 13 :
F_102 () ;
break;
case 14 :
V_215 = ( ( V_5 -> V_185 [ 1 ] < 60 ) ? V_5 -> V_185 [ 1 ] : 60 ) * 60 * V_213 ;
break;
case 15 :
F_103 ( V_216 ) ;
break;
}
}
static void F_104 ( struct V_4 * V_5 , unsigned int V_24 )
{
if ( V_24 > V_5 -> V_31 - V_5 -> V_77 )
V_24 = V_5 -> V_31 - V_5 -> V_77 ;
else if ( ! V_24 )
V_24 = 1 ;
F_30 ( V_5 , V_24 ) ;
}
static void F_105 ( struct V_4 * V_5 , unsigned int V_24 )
{
if ( V_24 > V_5 -> V_27 - V_5 -> V_81 )
V_24 = V_5 -> V_27 - V_5 -> V_81 ;
else if ( ! V_24 )
V_24 = 1 ;
F_16 ( V_5 , V_5 -> V_81 , V_5 -> V_161 , V_24 ) ;
V_5 -> V_78 = 0 ;
}
static void F_106 ( struct V_4 * V_5 , unsigned int V_24 )
{
if ( V_24 > V_5 -> V_31 - V_5 -> V_77 )
V_24 = V_5 -> V_31 - V_5 -> V_77 ;
else if ( ! V_24 )
V_24 = 1 ;
F_31 ( V_5 , V_24 ) ;
}
static void F_107 ( struct V_4 * V_5 , unsigned int V_24 )
{
if ( V_24 > V_5 -> V_27 - V_5 -> V_81 )
V_24 = V_5 -> V_27 - V_5 -> V_81 ;
else if ( ! V_24 )
V_24 = 1 ;
F_12 ( V_5 , V_5 -> V_81 , V_5 -> V_161 , V_24 ) ;
V_5 -> V_78 = 0 ;
}
static void F_65 ( struct V_4 * V_5 )
{
V_5 -> V_217 = V_5 -> V_77 ;
V_5 -> V_218 = V_5 -> V_81 ;
V_5 -> V_219 = V_5 -> V_60 ;
V_5 -> V_220 = V_5 -> V_65 ;
V_5 -> V_221 = V_5 -> V_62 ;
V_5 -> V_222 = V_5 -> V_61 ;
V_5 -> V_223 = V_5 -> V_63 ;
V_5 -> V_224 = V_5 -> V_187 ;
V_5 -> V_225 = V_5 -> V_59 ;
V_5 -> V_226 = V_5 -> V_188 ;
V_5 -> V_227 = V_5 -> V_189 ;
}
static void F_108 ( struct V_4 * V_5 )
{
F_64 ( V_5 , V_5 -> V_217 , V_5 -> V_218 ) ;
V_5 -> V_60 = V_5 -> V_219 ;
V_5 -> V_65 = V_5 -> V_220 ;
V_5 -> V_62 = V_5 -> V_221 ;
V_5 -> V_61 = V_5 -> V_222 ;
V_5 -> V_63 = V_5 -> V_223 ;
V_5 -> V_187 = V_5 -> V_224 ;
V_5 -> V_59 = V_5 -> V_225 ;
V_5 -> V_188 = V_5 -> V_226 ;
V_5 -> V_189 = V_5 -> V_227 ;
V_5 -> V_186 = F_89 ( V_5 -> V_187 ? V_5 -> V_189 : V_5 -> V_188 , V_5 ) ;
F_26 ( V_5 ) ;
V_5 -> V_78 = 0 ;
}
static void F_109 ( struct V_4 * V_5 , int V_228 )
{
V_5 -> V_160 = 0 ;
V_5 -> V_161 = V_5 -> V_27 ;
V_5 -> V_229 = V_230 ;
V_5 -> V_201 = 0 ;
V_5 -> V_186 = F_89 ( V_231 , V_5 ) ;
V_5 -> V_188 = V_231 ;
V_5 -> V_189 = V_232 ;
V_5 -> V_187 = 0 ;
V_5 -> V_78 = 0 ;
V_5 -> V_199 = 0 ;
V_5 -> V_233 = V_234 ;
V_5 -> V_235 = 0 ;
V_5 -> V_190 = 0 ;
V_5 -> V_191 = 0 ;
V_5 -> V_64 = 0 ;
V_5 -> V_180 = 0 ;
V_5 -> V_204 = 1 ;
V_5 -> V_91 = V_132 ;
V_5 -> V_206 = 0 ;
F_110 ( V_5 -> V_104 ) ;
V_5 -> V_83 = V_236 ;
V_5 -> V_75 = V_5 -> V_121 ;
F_87 ( V_5 ) ;
F_26 ( V_5 ) ;
V_5 -> V_237 [ 0 ] = 0x01010100 ;
V_5 -> V_237 [ 1 ] =
V_5 -> V_237 [ 2 ] =
V_5 -> V_237 [ 3 ] =
V_5 -> V_237 [ 4 ] =
V_5 -> V_237 [ 5 ] =
V_5 -> V_237 [ 6 ] =
V_5 -> V_237 [ 7 ] = 0x01010101 ;
V_5 -> V_210 = V_211 ;
V_5 -> V_212 = V_214 ;
F_64 ( V_5 , 0 , 0 ) ;
F_65 ( V_5 ) ;
if ( V_228 )
F_84 ( V_5 , 2 ) ;
}
static void F_111 ( struct V_139 * V_140 , struct V_4 * V_5 , int V_9 )
{
switch ( V_9 ) {
case 0 :
return;
case 7 :
if ( V_5 -> V_212 )
F_112 ( V_5 -> V_210 , V_5 -> V_212 ) ;
return;
case 8 :
F_82 ( V_5 ) ;
return;
case 9 :
V_5 -> V_76 -= ( V_5 -> V_77 << 1 ) ;
while ( V_5 -> V_77 < V_5 -> V_31 - 1 ) {
V_5 -> V_77 ++ ;
if ( V_5 -> V_237 [ V_5 -> V_77 >> 5 ] & ( 1 << ( V_5 -> V_77 & 31 ) ) )
break;
}
V_5 -> V_76 += ( V_5 -> V_77 << 1 ) ;
F_5 ( V_5 , '\t' ) ;
return;
case 10 : case 11 : case 12 :
F_79 ( V_5 ) ;
if ( ! F_113 ( V_5 , V_207 ) )
return;
case 13 :
F_81 ( V_5 ) ;
return;
case 14 :
V_5 -> V_187 = 1 ;
V_5 -> V_186 = F_89 ( V_5 -> V_189 , V_5 ) ;
V_5 -> V_190 = 1 ;
return;
case 15 :
V_5 -> V_187 = 0 ;
V_5 -> V_186 = F_89 ( V_5 -> V_188 , V_5 ) ;
V_5 -> V_190 = 0 ;
return;
case 24 : case 26 :
V_5 -> V_229 = V_230 ;
return;
case 27 :
V_5 -> V_229 = V_238 ;
return;
case 127 :
F_83 ( V_5 ) ;
return;
case 128 + 27 :
V_5 -> V_229 = V_239 ;
return;
}
switch( V_5 -> V_229 ) {
case V_238 :
V_5 -> V_229 = V_230 ;
switch ( V_9 ) {
case '[' :
V_5 -> V_229 = V_239 ;
return;
case ']' :
V_5 -> V_229 = V_240 ;
return;
case '%' :
V_5 -> V_229 = V_241 ;
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
V_5 -> V_237 [ V_5 -> V_77 >> 5 ] |= ( 1 << ( V_5 -> V_77 & 31 ) ) ;
return;
case 'Z' :
F_95 ( V_140 ) ;
return;
case '7' :
F_65 ( V_5 ) ;
return;
case '8' :
F_108 ( V_5 ) ;
return;
case '(' :
V_5 -> V_229 = V_242 ;
return;
case ')' :
V_5 -> V_229 = V_243 ;
return;
case '#' :
V_5 -> V_229 = V_244 ;
return;
case 'c' :
F_109 ( V_5 , 1 ) ;
return;
case '>' :
F_100 ( V_5 , V_245 ) ;
return;
case '=' :
F_99 ( V_5 , V_245 ) ;
return;
}
return;
case V_240 :
if ( V_9 == 'P' ) {
for ( V_5 -> V_184 = 0 ; V_5 -> V_184 < V_246 ; V_5 -> V_184 ++ )
V_5 -> V_185 [ V_5 -> V_184 ] = 0 ;
V_5 -> V_184 = 0 ;
V_5 -> V_229 = V_247 ;
return;
} else if ( V_9 == 'R' ) {
F_114 ( V_5 ) ;
V_5 -> V_229 = V_230 ;
} else
V_5 -> V_229 = V_230 ;
return;
case V_247 :
if ( isxdigit ( V_9 ) ) {
V_5 -> V_185 [ V_5 -> V_184 ++ ] = F_115 ( V_9 ) ;
if ( V_5 -> V_184 == 7 ) {
int V_82 = V_5 -> V_185 [ 0 ] * 3 , V_248 = 1 ;
V_5 -> V_249 [ V_82 ] = 16 * V_5 -> V_185 [ V_248 ++ ] ;
V_5 -> V_249 [ V_82 ++ ] += V_5 -> V_185 [ V_248 ++ ] ;
V_5 -> V_249 [ V_82 ] = 16 * V_5 -> V_185 [ V_248 ++ ] ;
V_5 -> V_249 [ V_82 ++ ] += V_5 -> V_185 [ V_248 ++ ] ;
V_5 -> V_249 [ V_82 ] = 16 * V_5 -> V_185 [ V_248 ++ ] ;
V_5 -> V_249 [ V_82 ] += V_5 -> V_185 [ V_248 ] ;
F_41 ( V_5 ) ;
V_5 -> V_229 = V_230 ;
}
} else
V_5 -> V_229 = V_230 ;
return;
case V_239 :
for ( V_5 -> V_184 = 0 ; V_5 -> V_184 < V_246 ; V_5 -> V_184 ++ )
V_5 -> V_185 [ V_5 -> V_184 ] = 0 ;
V_5 -> V_184 = 0 ;
V_5 -> V_229 = V_250 ;
if ( V_9 == '[' ) {
V_5 -> V_229 = V_251 ;
return;
}
V_5 -> V_201 = ( V_9 == '?' ) ;
if ( V_5 -> V_201 )
return;
case V_250 :
if ( V_9 == ';' && V_5 -> V_184 < V_246 - 1 ) {
V_5 -> V_184 ++ ;
return;
} else if ( V_9 >= '0' && V_9 <= '9' ) {
V_5 -> V_185 [ V_5 -> V_184 ] *= 10 ;
V_5 -> V_185 [ V_5 -> V_184 ] += V_9 - '0' ;
return;
} else
V_5 -> V_229 = V_252 ;
case V_252 :
V_5 -> V_229 = V_230 ;
switch( V_9 ) {
case 'h' :
F_98 ( V_5 , 1 ) ;
return;
case 'l' :
F_98 ( V_5 , 0 ) ;
return;
case 'c' :
if ( V_5 -> V_201 ) {
if ( V_5 -> V_185 [ 0 ] )
V_5 -> V_83 = V_5 -> V_185 [ 0 ] | ( V_5 -> V_185 [ 1 ] << 8 ) | ( V_5 -> V_185 [ 2 ] << 16 ) ;
else
V_5 -> V_83 = V_236 ;
return;
}
break;
case 'm' :
if ( V_5 -> V_201 ) {
F_34 () ;
if ( V_5 -> V_185 [ 0 ] )
V_5 -> V_75 = V_5 -> V_185 [ 0 ] << 8 | V_5 -> V_185 [ 1 ] ;
else
V_5 -> V_75 = V_5 -> V_121 ;
return;
}
break;
case 'n' :
if ( ! V_5 -> V_201 ) {
if ( V_5 -> V_185 [ 0 ] == 5 )
F_94 ( V_140 ) ;
else if ( V_5 -> V_185 [ 0 ] == 6 )
F_93 ( V_5 , V_140 ) ;
}
return;
}
if ( V_5 -> V_201 ) {
V_5 -> V_201 = 0 ;
return;
}
switch( V_9 ) {
case 'G' : case '`' :
if ( V_5 -> V_185 [ 0 ] )
V_5 -> V_185 [ 0 ] -- ;
F_64 ( V_5 , V_5 -> V_185 [ 0 ] , V_5 -> V_81 ) ;
return;
case 'A' :
if ( ! V_5 -> V_185 [ 0 ] )
V_5 -> V_185 [ 0 ] ++ ;
F_64 ( V_5 , V_5 -> V_77 , V_5 -> V_81 - V_5 -> V_185 [ 0 ] ) ;
return;
case 'B' : case 'e' :
if ( ! V_5 -> V_185 [ 0 ] )
V_5 -> V_185 [ 0 ] ++ ;
F_64 ( V_5 , V_5 -> V_77 , V_5 -> V_81 + V_5 -> V_185 [ 0 ] ) ;
return;
case 'C' : case 'a' :
if ( ! V_5 -> V_185 [ 0 ] )
V_5 -> V_185 [ 0 ] ++ ;
F_64 ( V_5 , V_5 -> V_77 + V_5 -> V_185 [ 0 ] , V_5 -> V_81 ) ;
return;
case 'D' :
if ( ! V_5 -> V_185 [ 0 ] )
V_5 -> V_185 [ 0 ] ++ ;
F_64 ( V_5 , V_5 -> V_77 - V_5 -> V_185 [ 0 ] , V_5 -> V_81 ) ;
return;
case 'E' :
if ( ! V_5 -> V_185 [ 0 ] )
V_5 -> V_185 [ 0 ] ++ ;
F_64 ( V_5 , 0 , V_5 -> V_81 + V_5 -> V_185 [ 0 ] ) ;
return;
case 'F' :
if ( ! V_5 -> V_185 [ 0 ] )
V_5 -> V_185 [ 0 ] ++ ;
F_64 ( V_5 , 0 , V_5 -> V_81 - V_5 -> V_185 [ 0 ] ) ;
return;
case 'd' :
if ( V_5 -> V_185 [ 0 ] )
V_5 -> V_185 [ 0 ] -- ;
F_76 ( V_5 , V_5 -> V_77 , V_5 -> V_185 [ 0 ] ) ;
return;
case 'H' : case 'f' :
if ( V_5 -> V_185 [ 0 ] )
V_5 -> V_185 [ 0 ] -- ;
if ( V_5 -> V_185 [ 1 ] )
V_5 -> V_185 [ 1 ] -- ;
F_76 ( V_5 , V_5 -> V_185 [ 1 ] , V_5 -> V_185 [ 0 ] ) ;
return;
case 'J' :
F_84 ( V_5 , V_5 -> V_185 [ 0 ] ) ;
return;
case 'K' :
F_85 ( V_5 , V_5 -> V_185 [ 0 ] ) ;
return;
case 'L' :
F_105 ( V_5 , V_5 -> V_185 [ 0 ] ) ;
return;
case 'M' :
F_107 ( V_5 , V_5 -> V_185 [ 0 ] ) ;
return;
case 'P' :
F_106 ( V_5 , V_5 -> V_185 [ 0 ] ) ;
return;
case 'c' :
if ( ! V_5 -> V_185 [ 0 ] )
F_95 ( V_140 ) ;
return;
case 'g' :
if ( ! V_5 -> V_185 [ 0 ] )
V_5 -> V_237 [ V_5 -> V_77 >> 5 ] &= ~ ( 1 << ( V_5 -> V_77 & 31 ) ) ;
else if ( V_5 -> V_185 [ 0 ] == 3 ) {
V_5 -> V_237 [ 0 ] =
V_5 -> V_237 [ 1 ] =
V_5 -> V_237 [ 2 ] =
V_5 -> V_237 [ 3 ] =
V_5 -> V_237 [ 4 ] =
V_5 -> V_237 [ 5 ] =
V_5 -> V_237 [ 6 ] =
V_5 -> V_237 [ 7 ] = 0 ;
}
return;
case 'm' :
F_88 ( V_5 ) ;
return;
case 'q' :
if ( V_5 -> V_185 [ 0 ] < 4 )
F_116 ( V_5 -> V_104 ,
( V_5 -> V_185 [ 0 ] < 3 ) ? V_5 -> V_185 [ 0 ] : 4 ) ;
return;
case 'r' :
if ( ! V_5 -> V_185 [ 0 ] )
V_5 -> V_185 [ 0 ] ++ ;
if ( ! V_5 -> V_185 [ 1 ] )
V_5 -> V_185 [ 1 ] = V_5 -> V_27 ;
if ( V_5 -> V_185 [ 0 ] < V_5 -> V_185 [ 1 ] &&
V_5 -> V_185 [ 1 ] <= V_5 -> V_27 ) {
V_5 -> V_160 = V_5 -> V_185 [ 0 ] - 1 ;
V_5 -> V_161 = V_5 -> V_185 [ 1 ] ;
F_76 ( V_5 , 0 , 0 ) ;
}
return;
case 's' :
F_65 ( V_5 ) ;
return;
case 'u' :
F_108 ( V_5 ) ;
return;
case 'X' :
F_86 ( V_5 , V_5 -> V_185 [ 0 ] ) ;
return;
case '@' :
F_104 ( V_5 , V_5 -> V_185 [ 0 ] ) ;
return;
case ']' :
F_101 ( V_5 ) ;
return;
}
return;
case V_241 :
V_5 -> V_229 = V_230 ;
switch ( V_9 ) {
case '@' :
V_5 -> V_233 = 0 ;
return;
case 'G' :
case '8' :
V_5 -> V_233 = 1 ;
return;
}
return;
case V_251 :
V_5 -> V_229 = V_230 ;
return;
case V_244 :
V_5 -> V_229 = V_230 ;
if ( V_9 == '8' ) {
V_5 -> V_32 =
( V_5 -> V_32 & 0xff00 ) | 'E' ;
F_84 ( V_5 , 2 ) ;
V_5 -> V_32 =
( V_5 -> V_32 & 0xff00 ) | ' ' ;
F_17 ( V_5 , V_5 -> V_15 , V_5 -> V_72 / 2 ) ;
}
return;
case V_242 :
if ( V_9 == '0' )
V_5 -> V_188 = V_232 ;
else if ( V_9 == 'B' )
V_5 -> V_188 = V_231 ;
else if ( V_9 == 'U' )
V_5 -> V_188 = V_192 ;
else if ( V_9 == 'K' )
V_5 -> V_188 = V_253 ;
if ( V_5 -> V_187 == 0 )
V_5 -> V_186 = F_89 ( V_5 -> V_188 , V_5 ) ;
V_5 -> V_229 = V_230 ;
return;
case V_243 :
if ( V_9 == '0' )
V_5 -> V_189 = V_232 ;
else if ( V_9 == 'B' )
V_5 -> V_189 = V_231 ;
else if ( V_9 == 'U' )
V_5 -> V_189 = V_192 ;
else if ( V_9 == 'K' )
V_5 -> V_189 = V_253 ;
if ( V_5 -> V_187 == 1 )
V_5 -> V_186 = F_89 ( V_5 -> V_189 , V_5 ) ;
V_5 -> V_229 = V_230 ;
return;
default:
V_5 -> V_229 = V_230 ;
}
}
static int F_117 ( T_4 V_254 , const struct V_255 * V_256 , int V_257 )
{
int F_62 = 0 ;
int V_258 ;
if ( V_254 < V_256 [ 0 ] . V_259 || V_254 > V_256 [ V_257 ] . V_260 )
return 0 ;
while ( V_257 >= F_62 ) {
V_258 = ( F_62 + V_257 ) / 2 ;
if ( V_254 > V_256 [ V_258 ] . V_260 )
F_62 = V_258 + 1 ;
else if ( V_254 < V_256 [ V_258 ] . V_259 )
V_257 = V_258 - 1 ;
else
return 1 ;
}
return 0 ;
}
static int F_118 ( T_4 V_254 )
{
static const struct V_255 V_261 [] = {
{ 0x1100 , 0x115F } , { 0x2329 , 0x232A } , { 0x2E80 , 0x303E } ,
{ 0x3040 , 0xA4CF } , { 0xAC00 , 0xD7A3 } , { 0xF900 , 0xFAFF } ,
{ 0xFE10 , 0xFE19 } , { 0xFE30 , 0xFE6F } , { 0xFF00 , 0xFF60 } ,
{ 0xFFE0 , 0xFFE6 } , { 0x20000 , 0x2FFFD } , { 0x30000 , 0x3FFFD }
} ;
return F_117 ( V_254 , V_261 , F_119 ( V_261 ) - 1 ) ;
}
static int F_120 ( struct V_139 * V_140 , const unsigned char * V_194 , int V_36 )
{
#ifdef F_18
#define F_121 do { } while(0);
#else
#define F_121 if (draw_x >= 0) { \
vc->vc_sw->con_putcs(vc, (u16 *)draw_from, (u16 *)draw_to - (u16 *)draw_from, vc->vc_y, draw_x); \
draw_x = -1; \
}
#endif
int V_9 , V_262 , V_263 , V_264 = 0 , V_265 = - 1 ;
unsigned int V_122 ;
unsigned long V_266 = 0 , V_267 = 0 ;
struct V_4 * V_5 ;
unsigned char V_58 ;
struct V_7 V_8 ;
T_5 V_268 ;
T_5 V_269 ;
T_5 V_134 ;
T_1 V_270 , V_271 ;
if ( F_122 () )
return V_36 ;
F_123 () ;
F_71 () ;
V_5 = V_140 -> V_170 ;
if ( V_5 == NULL ) {
F_124 ( V_272 L_5 ) ;
F_72 () ;
return 0 ;
}
V_122 = V_5 -> V_104 ;
if ( ! F_45 ( V_122 ) ) {
F_125 ( L_6 , V_122 + 1 ) ;
F_72 () ;
return 0 ;
}
V_270 = V_5 -> V_57 ;
V_271 = V_270 ? 0x1ff : 0xff ;
if ( F_35 ( V_5 ) )
F_23 ( V_5 ) ;
V_8 . V_5 = V_5 ;
while ( ! V_140 -> V_273 && V_36 ) {
int V_274 = * V_194 ;
V_9 = V_274 ;
V_194 ++ ;
V_264 ++ ;
V_36 -- ;
V_268 = 0 ;
V_269 = 0 ;
V_134 = 1 ;
if ( V_5 -> V_229 != V_230 ) {
V_262 = V_9 ;
} else if ( V_5 -> V_233 && ! V_5 -> V_190 ) {
V_275:
if ( ( V_9 & 0xc0 ) == 0x80 ) {
static const T_4 V_276 [] = { 0x0000007f , 0x000007ff , 0x0000ffff , 0x001fffff , 0x03ffffff , 0x7fffffff } ;
if ( V_5 -> V_235 ) {
V_5 -> V_277 = ( V_5 -> V_277 << 6 ) | ( V_9 & 0x3f ) ;
V_5 -> V_184 ++ ;
if ( -- V_5 -> V_235 ) {
continue;
}
V_9 = V_5 -> V_277 ;
if ( V_9 <= V_276 [ V_5 -> V_184 - 1 ] ||
V_9 > V_276 [ V_5 -> V_184 ] )
V_9 = 0xfffd ;
} else {
V_5 -> V_235 = 0 ;
V_9 = 0xfffd ;
}
} else {
if ( V_5 -> V_235 ) {
V_268 = 1 ;
V_5 -> V_235 = 0 ;
V_9 = 0xfffd ;
} else if ( V_9 > 0x7f ) {
V_5 -> V_184 = 0 ;
if ( ( V_9 & 0xe0 ) == 0xc0 ) {
V_5 -> V_235 = 1 ;
V_5 -> V_277 = ( V_9 & 0x1f ) ;
} else if ( ( V_9 & 0xf0 ) == 0xe0 ) {
V_5 -> V_235 = 2 ;
V_5 -> V_277 = ( V_9 & 0x0f ) ;
} else if ( ( V_9 & 0xf8 ) == 0xf0 ) {
V_5 -> V_235 = 3 ;
V_5 -> V_277 = ( V_9 & 0x07 ) ;
} else if ( ( V_9 & 0xfc ) == 0xf8 ) {
V_5 -> V_235 = 4 ;
V_5 -> V_277 = ( V_9 & 0x03 ) ;
} else if ( ( V_9 & 0xfe ) == 0xfc ) {
V_5 -> V_235 = 5 ;
V_5 -> V_277 = ( V_9 & 0x01 ) ;
} else {
V_9 = 0xfffd ;
}
if ( V_5 -> V_235 ) {
continue;
}
}
}
if ( ( V_9 >= 0xd800 && V_9 <= 0xdfff ) || V_9 == 0xfffe || V_9 == 0xffff )
V_9 = 0xfffd ;
V_262 = V_9 ;
} else {
V_262 = V_186 ( V_5 , V_9 ) ;
}
V_8 . V_9 = V_262 ;
if ( F_6 ( & V_3 , V_278 ,
& V_8 ) == V_279 )
continue;
V_263 = V_262 && ( V_9 >= 32 ||
! ( V_5 -> V_190 ? ( V_280 >> V_9 ) & 1 :
V_5 -> V_233 || ( ( V_281 >> V_9 ) & 1 ) ) )
&& ( V_9 != 127 || V_5 -> V_190 )
&& ( V_9 != 128 + 27 ) ;
if ( V_5 -> V_229 == V_230 && V_263 ) {
if ( V_5 -> V_233 && ! V_5 -> V_190 ) {
if ( F_118 ( V_9 ) )
V_134 = 2 ;
}
V_262 = F_126 ( V_5 , V_262 ) ;
if ( V_262 & ~ V_271 ) {
if ( V_262 == - 1 || V_262 == - 2 ) {
continue;
}
if ( ( ! ( V_5 -> V_233 && ! V_5 -> V_190 ) || V_9 < 128 ) && ! ( V_9 & ~ V_271 ) ) {
V_262 = V_9 ;
} else {
V_262 = F_126 ( V_5 , 0xfffd ) ;
if ( V_262 < 0 ) {
V_269 = 1 ;
V_262 = F_126 ( V_5 , '?' ) ;
if ( V_262 < 0 ) V_262 = '?' ;
}
}
}
if ( ! V_269 ) {
V_58 = V_5 -> V_58 ;
} else {
if ( ! V_5 -> V_54 ) {
V_58 = ( V_5 -> V_58 ) ^ 0x08 ;
} else if ( V_5 -> V_57 == 0x100 ) {
V_58 = ( ( V_5 -> V_58 ) & 0x11 ) | ( ( ( V_5 -> V_58 ) & 0xe0 ) >> 4 ) | ( ( ( V_5 -> V_58 ) & 0x0e ) << 4 ) ;
} else {
V_58 = ( ( V_5 -> V_58 ) & 0x88 ) | ( ( ( V_5 -> V_58 ) & 0x70 ) >> 4 ) | ( ( ( V_5 -> V_58 ) & 0x07 ) << 4 ) ;
}
F_121
}
while ( 1 ) {
if ( V_5 -> V_78 || V_5 -> V_206 )
F_121
if ( V_5 -> V_78 ) {
F_81 ( V_5 ) ;
F_79 ( V_5 ) ;
}
if ( V_5 -> V_206 )
F_30 ( V_5 , 1 ) ;
F_28 ( V_270 ?
( ( V_58 << 8 ) & ~ V_270 ) + ( ( V_262 & 0x100 ) ? V_270 : 0 ) + ( V_262 & 0xff ) :
( V_58 << 8 ) + V_262 ,
( T_1 * ) V_5 -> V_76 ) ;
if ( F_22 ( V_5 ) && V_265 < 0 ) {
V_265 = V_5 -> V_77 ;
V_266 = V_5 -> V_76 ;
}
if ( V_5 -> V_77 == V_5 -> V_31 - 1 ) {
V_5 -> V_78 = V_5 -> V_204 ;
V_267 = V_5 -> V_76 + 2 ;
} else {
V_5 -> V_77 ++ ;
V_267 = ( V_5 -> V_76 += 2 ) ;
}
if ( ! -- V_134 ) break;
V_262 = F_126 ( V_5 , ' ' ) ;
if ( V_262 < 0 ) V_262 = ' ' ;
}
F_5 ( V_5 , V_9 ) ;
if ( V_269 ) {
F_121
}
if ( V_268 ) {
V_268 = 0 ;
V_269 = 0 ;
V_134 = 1 ;
V_9 = V_274 ;
goto V_275;
}
continue;
}
F_121
F_111 ( V_140 , V_5 , V_274 ) ;
}
F_121
F_127 ();
F_72 () ;
F_7 ( V_5 ) ;
return V_264 ;
#undef F_121
}
static void F_128 ( struct V_282 * V_283 )
{
F_71 () ;
if ( V_284 >= 0 ) {
if ( V_284 != V_102 &&
F_45 ( V_284 ) ) {
F_23 ( V_101 [ V_102 ] . V_25 ) ;
F_129 ( V_101 [ V_284 ] . V_25 ) ;
}
V_284 = - 1 ;
}
if ( V_285 ) {
V_285 = 0 ;
F_102 () ;
}
if ( V_20 ) {
struct V_4 * V_5 = V_101 [ V_102 ] . V_25 ;
F_34 () ;
if ( V_5 -> V_89 == V_286 )
V_5 -> V_16 -> V_287 ( V_5 , V_20 ) ;
V_20 = 0 ;
}
if ( V_288 ) {
F_130 ( 0 ) ;
V_288 = 0 ;
}
F_7 ( V_101 [ V_102 ] . V_25 ) ;
F_72 () ;
}
int F_103 ( int V_24 )
{
struct V_4 * V_5 = V_101 [ V_102 ] . V_25 ;
if ( ! F_45 ( V_24 ) || V_289 ||
( V_5 -> V_290 . V_291 == V_292 && V_5 -> V_89 == V_90 ) ) {
return - V_158 ;
}
V_284 = V_24 ;
F_10 () ;
return 0 ;
}
int F_131 ( int V_74 )
{
static int V_293 ;
if ( V_74 != - 1 )
return F_132 ( & V_293 , V_74 ) ;
else
return V_293 ;
}
static void F_133 ( struct V_294 * V_295 , const char * V_23 , unsigned V_36 )
{
struct V_4 * V_5 = V_101 [ V_102 ] . V_25 ;
unsigned char V_9 ;
static F_134 ( V_296 ) ;
const T_6 * V_35 ;
T_6 V_67 = 0 ;
T_6 V_297 ;
int V_298 ;
if ( ! V_299 )
return;
if ( ! F_135 ( & V_296 ) )
return;
V_298 = F_136 () ;
if ( V_298 && F_45 ( V_298 - 1 ) )
V_5 = V_101 [ V_298 - 1 ] . V_25 ;
V_297 = V_5 -> V_77 ;
if ( ! F_45 ( V_102 ) ) {
goto V_300;
}
if ( V_5 -> V_89 != V_286 && ! F_42 ( V_5 ) )
goto V_300;
if ( F_35 ( V_5 ) )
F_23 ( V_5 ) ;
V_35 = ( T_6 * ) V_5 -> V_76 ;
while ( V_36 -- ) {
V_9 = * V_23 ++ ;
if ( V_9 == 10 || V_9 == 13 || V_9 == 8 || V_5 -> V_78 ) {
if ( V_67 > 0 ) {
if ( F_13 ( V_5 ) )
V_5 -> V_16 -> V_45 ( V_5 , V_35 , V_67 , V_5 -> V_81 , V_5 -> V_77 ) ;
V_5 -> V_77 += V_67 ;
if ( V_5 -> V_78 )
V_5 -> V_77 -- ;
V_67 = 0 ;
}
if ( V_9 == 8 ) {
F_82 ( V_5 ) ;
V_35 = ( T_6 * ) V_5 -> V_76 ;
V_297 = V_5 -> V_77 ;
continue;
}
if ( V_9 != 13 )
F_79 ( V_5 ) ;
F_81 ( V_5 ) ;
V_35 = ( T_6 * ) V_5 -> V_76 ;
V_297 = V_5 -> V_77 ;
if ( V_9 == 10 || V_9 == 13 )
continue;
}
F_28 ( ( V_5 -> V_58 << 8 ) + V_9 , ( unsigned short * ) V_5 -> V_76 ) ;
F_5 ( V_5 , V_9 ) ;
V_67 ++ ;
if ( V_297 == V_5 -> V_31 - 1 ) {
V_5 -> V_78 = 1 ;
continue;
}
V_5 -> V_76 += 2 ;
V_297 ++ ;
}
if ( V_67 > 0 ) {
if ( F_13 ( V_5 ) )
V_5 -> V_16 -> V_45 ( V_5 , V_35 , V_67 , V_5 -> V_81 , V_5 -> V_77 ) ;
V_5 -> V_77 += V_67 ;
if ( V_5 -> V_77 == V_5 -> V_31 ) {
V_5 -> V_77 -- ;
V_5 -> V_78 = 1 ;
}
}
F_24 ( V_5 ) ;
F_7 ( V_5 ) ;
V_300:
F_137 ( & V_296 ) ;
}
static struct V_301 * F_138 ( struct V_294 * V_9 , int * V_302 )
{
* V_302 = V_9 -> V_302 ? V_9 -> V_302 - 1 : V_102 ;
return V_303 ;
}
int F_139 ( struct V_139 * V_140 , unsigned long V_304 )
{
char type , V_305 ;
char T_7 * V_14 = ( char T_7 * ) V_304 ;
int V_19 ;
int V_171 ;
if ( V_306 -> signal -> V_140 != V_140 && ! F_51 ( V_307 ) )
return - V_126 ;
if ( F_140 ( type , V_14 ) )
return - V_308 ;
V_171 = 0 ;
switch ( type )
{
case V_309 :
F_71 () ;
V_171 = F_141 ( (struct V_310 T_7 * ) ( V_14 + 1 ) , V_140 ) ;
F_72 () ;
break;
case V_311 :
V_171 = F_142 ( V_140 ) ;
break;
case V_312 :
F_71 () ;
F_143 () ;
F_72 () ;
break;
case V_313 :
F_71 () ;
V_171 = F_144 ( V_14 ) ;
F_72 () ;
break;
case V_314 :
V_305 = F_145 () ;
V_171 = F_146 ( V_305 , V_14 ) ;
break;
case V_315 :
F_71 () ;
V_305 = F_97 () ;
F_72 () ;
V_171 = F_146 ( V_305 , V_14 ) ;
break;
case V_316 :
F_71 () ;
V_171 = F_147 ( V_14 ) ;
F_72 () ;
break;
case V_317 :
V_305 = F_136 () ;
V_171 = F_146 ( V_305 , V_14 ) ;
break;
case V_318 :
if ( ! F_51 ( V_307 ) ) {
V_171 = - V_126 ;
} else {
if ( F_140 ( V_305 , V_14 + 1 ) )
V_171 = - V_308 ;
else
F_131 ( V_305 ) ;
}
break;
case V_319 :
V_171 = V_102 ;
break;
case V_320 :
if ( F_140 ( V_19 , ( V_321 T_7 * ) ( V_14 + 4 ) ) ) {
V_171 = - V_308 ;
} else {
F_71 () ;
F_78 ( V_101 [ V_102 ] . V_25 , V_19 ) ;
F_72 () ;
V_171 = 0 ;
}
break;
case V_322 :
F_71 () ;
V_323 = 1 ;
F_130 ( 0 ) ;
F_72 () ;
break;
case V_324 :
V_171 = V_88 ;
break;
default:
V_171 = - V_158 ;
break;
}
return V_171 ;
}
static int F_148 ( struct V_139 * V_140 , const unsigned char * V_194 , int V_36 )
{
int V_325 ;
V_325 = F_120 ( V_140 , V_194 , V_36 ) ;
F_149 ( V_140 ) ;
return V_325 ;
}
static int F_150 ( struct V_139 * V_140 , unsigned char V_326 )
{
if ( F_122 () )
return 0 ;
return F_120 ( V_140 , & V_326 , 1 ) ;
}
static int F_151 ( struct V_139 * V_140 )
{
if ( V_140 -> V_273 )
return 0 ;
return 32768 ;
}
static int F_152 ( struct V_139 * V_140 )
{
return 0 ;
}
static void F_153 ( struct V_139 * V_140 )
{
}
static void F_154 ( struct V_139 * V_140 )
{
struct V_4 * V_5 = V_140 -> V_170 ;
F_155 ( & V_5 -> V_327 ) ;
}
static void F_156 ( struct V_139 * V_140 )
{
int V_328 ;
if ( ! V_140 )
return;
V_328 = V_140 -> V_302 ;
if ( ! F_45 ( V_328 ) )
return;
F_157 ( V_328 ) ;
}
static void F_158 ( struct V_139 * V_140 )
{
int V_328 ;
if ( ! V_140 )
return;
V_328 = V_140 -> V_302 ;
if ( ! F_45 ( V_328 ) )
return;
F_159 ( V_328 ) ;
}
static void F_149 ( struct V_139 * V_140 )
{
struct V_4 * V_5 ;
if ( F_122 () )
return;
F_71 () ;
V_5 = V_140 -> V_170 ;
if ( V_5 )
F_24 ( V_5 ) ;
F_72 () ;
}
static int F_160 ( struct V_139 * V_140 , struct V_329 * V_330 )
{
unsigned int V_122 = V_140 -> V_302 ;
int V_171 = 0 ;
F_71 () ;
if ( V_140 -> V_170 == NULL ) {
V_171 = F_50 ( V_122 ) ;
if ( V_171 == 0 ) {
struct V_4 * V_5 = V_101 [ V_122 ] . V_25 ;
if ( V_5 -> V_129 . V_140 ) {
F_72 () ;
return - V_331 ;
}
V_140 -> V_170 = V_5 ;
V_5 -> V_129 . V_140 = V_140 ;
if ( ! V_140 -> V_162 . V_164 && ! V_140 -> V_162 . V_165 ) {
V_140 -> V_162 . V_164 = V_101 [ V_122 ] . V_25 -> V_27 ;
V_140 -> V_162 . V_165 = V_101 [ V_122 ] . V_25 -> V_31 ;
}
if ( V_5 -> V_233 )
V_140 -> V_332 -> V_333 |= V_334 ;
else
V_140 -> V_332 -> V_333 &= ~ V_334 ;
F_72 () ;
return V_171 ;
}
}
F_72 () ;
return V_171 ;
}
static void F_161 ( struct V_139 * V_140 , struct V_329 * V_330 )
{
}
static void F_162 ( struct V_139 * V_140 )
{
struct V_4 * V_5 = V_140 -> V_170 ;
F_163 ( V_5 == NULL ) ;
F_71 () ;
V_5 -> V_129 . V_140 = NULL ;
F_72 () ;
F_164 ( V_140 ) ;
}
static void F_58 ( struct V_4 * V_5 , unsigned int V_169 ,
unsigned int V_141 , int V_228 )
{
int V_248 , V_335 ;
V_5 -> V_31 = V_141 ;
V_5 -> V_27 = V_169 ;
V_5 -> V_30 = V_141 << 1 ;
V_5 -> V_72 = V_5 -> V_27 * V_5 -> V_30 ;
F_36 ( V_5 ) ;
V_5 -> V_76 = V_5 -> V_15 ;
F_165 ( V_5 ) ;
for ( V_248 = V_335 = 0 ; V_248 < 16 ; V_248 ++ ) {
V_5 -> V_249 [ V_335 ++ ] = V_336 [ V_248 ] ;
V_5 -> V_249 [ V_335 ++ ] = V_337 [ V_248 ] ;
V_5 -> V_249 [ V_335 ++ ] = V_338 [ V_248 ] ;
}
V_5 -> V_183 = 0x07 ;
V_5 -> V_56 = V_339 ;
V_5 -> V_55 = V_340 ;
V_5 -> V_208 = 0x08 ;
F_166 ( & V_5 -> V_327 ) ;
F_109 ( V_5 , V_228 ) ;
}
static int T_8 V_120 ( void )
{
const char * V_341 = NULL ;
struct V_4 * V_5 ;
unsigned int V_122 = 0 , V_82 ;
F_71 () ;
if ( V_114 )
V_341 = V_114 -> V_342 () ;
if ( ! V_341 ) {
V_102 = 0 ;
F_72 () ;
return 0 ;
}
for ( V_82 = 0 ; V_82 < V_343 ; V_82 ++ ) {
struct V_344 * V_344 = & V_345 [ V_82 ] ;
if ( V_344 -> V_346 == NULL ) {
V_344 -> V_346 = V_114 ;
V_344 -> V_347 = V_341 ;
V_344 -> V_348 = V_349 ;
V_344 -> V_259 = 0 ;
V_344 -> V_260 = V_110 - 1 ;
break;
}
}
for ( V_82 = 0 ; V_82 < V_110 ; V_82 ++ )
V_115 [ V_82 ] = V_114 ;
if ( V_209 ) {
V_350 = V_351 ;
F_167 ( & V_352 , V_353 + ( V_209 * V_213 ) ) ;
}
for ( V_122 = 0 ; V_122 < V_175 ; V_122 ++ ) {
V_101 [ V_122 ] . V_25 = V_5 = F_52 ( sizeof( struct V_4 ) , V_354 ) ;
F_54 ( & V_101 [ V_122 ] . V_130 , V_131 ) ;
F_53 ( & V_5 -> V_129 ) ;
F_46 ( V_5 , V_122 , 1 ) ;
V_5 -> V_94 = F_52 ( V_5 -> V_72 , V_354 ) ;
F_58 ( V_5 , V_5 -> V_27 , V_5 -> V_31 ,
V_122 || ! V_5 -> V_16 -> V_96 ) ;
}
V_122 = V_102 = 0 ;
V_116 = V_5 = V_101 [ V_122 ] . V_25 ;
F_36 ( V_5 ) ;
F_37 ( V_5 ) ;
F_64 ( V_5 , V_5 -> V_77 , V_5 -> V_81 ) ;
F_84 ( V_5 , 0 ) ;
F_67 ( V_5 ) ;
F_168 ( L_7 ,
V_5 -> V_54 ? L_8 : L_9 ,
V_341 , V_5 -> V_31 , V_5 -> V_27 ) ;
V_299 = 1 ;
F_72 () ;
#ifdef F_169
F_170 ( & V_355 ) ;
#endif
return 0 ;
}
static T_9 F_171 ( struct V_356 * V_357 ,
struct V_358 * V_359 , char * V_194 )
{
return sprintf ( V_194 , L_10 , V_102 + 1 ) ;
}
int T_8 F_172 ( const struct V_360 * V_361 )
{
F_173 ( & V_362 , V_361 ) ;
if ( F_174 ( & V_362 , F_175 ( V_363 , 0 ) , 1 ) ||
F_176 ( F_175 ( V_363 , 0 ) , 1 , L_11 ) < 0 )
F_177 ( L_12 ) ;
V_105 = F_178 ( V_364 , NULL , F_175 ( V_363 , 0 ) , NULL , L_13 ) ;
if ( F_179 ( V_105 ) )
V_105 = NULL ;
else
F_180 ( F_181 ( V_105 , & V_365 ) < 0 ) ;
F_182 () ;
V_303 = F_183 ( V_110 ) ;
if ( ! V_303 )
F_177 ( L_14 ) ;
V_303 -> V_366 = L_15 ;
V_303 -> V_367 = 1 ;
V_303 -> V_368 = V_363 ;
V_303 -> V_369 = 1 ;
V_303 -> type = V_370 ;
V_303 -> V_371 = V_372 ;
if ( V_234 )
V_303 -> V_371 . V_333 |= V_334 ;
V_303 -> V_373 = V_374 | V_375 ;
F_184 ( V_303 , & V_376 ) ;
if ( F_185 ( V_303 ) )
F_177 ( L_16 ) ;
F_186 () ;
F_187 () ;
#ifdef F_188
F_189 () ;
#endif
return 0 ;
}
static int F_190 ( const struct V_377 * V_378 , int V_259 , int V_260 ,
int V_379 )
{
struct V_380 * V_113 = V_378 -> V_113 ;
const char * V_347 = NULL ;
struct V_344 * V_344 ;
int V_82 , V_248 = - 1 , V_335 = - 1 , V_325 = - V_381 ;
if ( ! F_191 ( V_113 ) )
return - V_381 ;
F_71 () ;
for ( V_82 = 0 ; V_82 < V_343 ; V_82 ++ ) {
V_344 = & V_345 [ V_82 ] ;
if ( V_344 -> V_346 == V_378 ) {
V_347 = V_344 -> V_347 ;
V_325 = 0 ;
break;
}
}
if ( V_325 )
goto V_137;
if ( ! ( V_344 -> V_348 & V_349 ) ) {
V_378 -> V_342 () ;
V_344 -> V_348 |= V_349 ;
}
if ( V_379 ) {
if ( V_114 )
F_47 ( V_114 -> V_113 ) ;
F_49 ( V_113 ) ;
V_114 = V_378 ;
}
V_259 = V_257 ( V_259 , V_344 -> V_259 ) ;
V_260 = F_62 ( V_260 , V_344 -> V_260 ) ;
for ( V_82 = V_259 ; V_82 <= V_260 ; V_82 ++ ) {
int V_108 ;
struct V_4 * V_5 = V_101 [ V_82 ] . V_25 ;
if ( V_115 [ V_82 ] )
F_47 ( V_115 [ V_82 ] -> V_113 ) ;
F_49 ( V_113 ) ;
V_115 [ V_82 ] = V_378 ;
if ( ! V_5 || ! V_5 -> V_16 )
continue;
V_248 = V_82 ;
if ( F_13 ( V_5 ) ) {
V_335 = V_82 ;
F_37 ( V_5 ) ;
}
V_108 = V_5 -> V_54 ;
V_5 -> V_16 -> V_173 ( V_5 ) ;
V_5 -> V_15 = ( unsigned long ) V_5 -> V_94 ;
F_46 ( V_5 , V_82 , 0 ) ;
F_36 ( V_5 ) ;
F_26 ( V_5 ) ;
if ( V_108 != V_5 -> V_54 )
F_38 ( V_5 ) ;
}
F_168 ( L_17 ) ;
if ( ! V_379 )
F_124 ( L_18 , V_259 + 1 , V_260 + 1 ) ;
if ( V_248 >= 0 ) {
struct V_4 * V_5 = V_101 [ V_248 ] . V_25 ;
F_124 ( L_19 ,
V_5 -> V_54 ? L_8 : L_9 ,
V_347 , V_5 -> V_31 , V_5 -> V_27 ) ;
if ( V_335 >= 0 ) {
V_5 = V_101 [ V_335 ] . V_25 ;
F_67 ( V_5 ) ;
}
} else
F_124 ( L_20 , V_347 ) ;
V_325 = 0 ;
V_137:
F_72 () ;
F_47 ( V_113 ) ;
return V_325 ;
}
static int F_192 ( const struct V_377 * V_378 , int V_259 , int V_260 )
{
int V_82 , V_325 = 0 ;
for ( V_82 = V_259 ; V_82 <= V_260 ; V_82 ++ ) {
struct V_4 * V_5 = V_101 [ V_82 ] . V_25 ;
if ( V_5 && V_5 -> V_89 == V_90 ) {
V_325 = 1 ;
break;
}
}
return V_325 ;
}
int F_193 ( const struct V_377 * V_378 , int V_259 , int V_260 , int V_379 )
{
struct V_380 * V_113 = V_378 -> V_113 ;
const struct V_377 * V_382 = NULL ;
struct V_344 * V_344 = NULL , * V_383 = NULL ;
int V_82 , V_325 = - V_381 ;
if ( ! F_191 ( V_113 ) )
return - V_381 ;
F_71 () ;
for ( V_82 = 0 ; V_82 < V_343 ; V_82 ++ ) {
V_344 = & V_345 [ V_82 ] ;
if ( V_344 -> V_346 == V_378 &&
V_344 -> V_348 & V_384 ) {
V_325 = 0 ;
break;
}
}
if ( V_325 ) {
F_72 () ;
goto V_137;
}
V_325 = - V_381 ;
for ( V_82 = 0 ; V_82 < V_343 ; V_82 ++ ) {
V_383 = & V_345 [ V_82 ] ;
if ( V_383 -> V_346 &&
! ( V_383 -> V_348 & V_384 ) ) {
V_382 = V_383 -> V_346 ;
V_325 = 0 ;
break;
}
}
if ( V_325 ) {
F_72 () ;
goto V_137;
}
if ( ! F_194 ( V_378 ) ) {
F_72 () ;
goto V_137;
}
V_259 = V_257 ( V_259 , V_344 -> V_259 ) ;
V_260 = F_62 ( V_260 , V_344 -> V_260 ) ;
for ( V_82 = V_259 ; V_82 <= V_260 ; V_82 ++ ) {
if ( V_115 [ V_82 ] == V_378 ) {
F_47 ( V_378 -> V_113 ) ;
V_115 [ V_82 ] = NULL ;
}
}
if ( ! F_194 ( V_382 ) ) {
const struct V_377 * V_385 = V_114 ;
V_382 -> V_342 () ;
V_383 -> V_348 |= V_349 ;
V_114 = V_385 ;
}
if ( ! F_194 ( V_378 ) )
V_344 -> V_348 &= ~ V_349 ;
F_72 () ;
F_190 ( V_382 , V_259 , V_260 , V_379 ) ;
V_137:
F_47 ( V_113 ) ;
return V_325 ;
}
static int F_195 ( struct V_344 * V_346 )
{
const struct V_377 * V_382 = NULL , * V_378 = NULL ;
int V_82 , V_386 = 1 , V_259 = - 1 , V_260 = - 1 , V_379 = 0 ;
if ( ! V_346 -> V_346 || ! ( V_346 -> V_348 & V_384 ) ||
F_192 ( V_346 -> V_346 , V_346 -> V_259 , V_346 -> V_260 ) )
goto V_137;
V_378 = V_346 -> V_346 ;
for ( V_82 = 0 ; V_82 < V_343 ; V_82 ++ ) {
struct V_344 * V_346 = & V_345 [ V_82 ] ;
if ( V_346 -> V_346 && ! ( V_346 -> V_348 & V_384 ) ) {
V_382 = V_346 -> V_346 ;
break;
}
}
if ( ! V_382 )
goto V_137;
while ( V_386 ) {
V_386 = 0 ;
for ( V_82 = V_346 -> V_259 ; V_82 <= V_346 -> V_260 ; V_82 ++ ) {
if ( V_115 [ V_82 ] == V_382 ) {
if ( V_259 == - 1 )
V_259 = V_82 ;
V_260 = V_82 ;
V_386 = 1 ;
} else if ( V_259 != - 1 )
break;
}
if ( V_259 == 0 && V_260 == V_110 - 1 )
V_379 = 1 ;
if ( V_259 != - 1 )
F_190 ( V_378 , V_259 , V_260 , V_379 ) ;
V_259 = - 1 ;
V_260 = - 1 ;
V_379 = 0 ;
}
V_137:
return 0 ;
}
static int F_196 ( struct V_344 * V_346 )
{
const struct V_377 * V_378 = NULL ;
int V_82 , V_386 = 1 , V_259 = - 1 , V_260 = - 1 , V_379 = 0 ;
if ( ! V_346 -> V_346 || ! ( V_346 -> V_348 & V_384 ) ||
F_192 ( V_346 -> V_346 , V_346 -> V_259 , V_346 -> V_260 ) )
goto V_137;
V_378 = V_346 -> V_346 ;
while ( V_386 ) {
V_386 = 0 ;
for ( V_82 = V_346 -> V_259 ; V_82 <= V_346 -> V_260 ; V_82 ++ ) {
if ( V_115 [ V_82 ] == V_378 ) {
if ( V_259 == - 1 )
V_259 = V_82 ;
V_260 = V_82 ;
V_386 = 1 ;
} else if ( V_259 != - 1 )
break;
}
if ( V_259 == 0 && V_260 == V_110 - 1 )
V_379 = 1 ;
if ( V_259 != - 1 )
F_193 ( V_378 , V_259 , V_260 , V_379 ) ;
V_259 = - 1 ;
V_260 = - 1 ;
V_379 = 0 ;
}
V_137:
return 0 ;
}
static inline int F_195 ( struct V_344 * V_346 )
{
return 0 ;
}
static inline int F_196 ( struct V_344 * V_346 )
{
return 0 ;
}
static T_9 F_197 ( struct V_356 * V_357 , struct V_358 * V_359 ,
const char * V_194 , T_10 V_36 )
{
struct V_344 * V_346 = F_198 ( V_357 ) ;
int V_387 = F_199 ( V_194 , NULL , 0 ) ;
if ( V_387 )
F_195 ( V_346 ) ;
else
F_196 ( V_346 ) ;
return V_36 ;
}
static T_9 F_200 ( struct V_356 * V_357 , struct V_358 * V_359 ,
char * V_194 )
{
struct V_344 * V_346 = F_198 ( V_357 ) ;
int V_387 = F_194 ( V_346 -> V_346 ) ;
return snprintf ( V_194 , V_388 , L_21 , V_387 ) ;
}
static T_9 F_201 ( struct V_356 * V_357 , struct V_358 * V_359 ,
char * V_194 )
{
struct V_344 * V_346 = F_198 ( V_357 ) ;
return snprintf ( V_194 , V_388 , L_22 ,
( V_346 -> V_348 & V_384 ) ? L_23 : L_24 ,
V_346 -> V_347 ) ;
}
static int F_202 ( struct V_344 * V_346 )
{
int V_82 ;
int error = 0 ;
V_346 -> V_348 |= V_389 ;
F_203 ( V_346 -> V_357 , V_346 ) ;
for ( V_82 = 0 ; V_82 < F_119 ( V_390 ) ; V_82 ++ ) {
error = F_181 ( V_346 -> V_357 , & V_390 [ V_82 ] ) ;
if ( error )
break;
}
if ( error ) {
while ( -- V_82 >= 0 )
F_204 ( V_346 -> V_357 , & V_390 [ V_82 ] ) ;
V_346 -> V_348 &= ~ V_389 ;
}
return error ;
}
static void F_205 ( struct V_344 * V_346 )
{
int V_82 ;
if ( V_346 -> V_348 & V_389 ) {
for ( V_82 = 0 ; V_82 < F_119 ( V_390 ) ; V_82 ++ )
F_204 ( V_346 -> V_357 , & V_390 [ V_82 ] ) ;
V_346 -> V_348 &= ~ V_389 ;
}
}
int F_194 ( const struct V_377 * V_378 )
{
int V_82 , V_391 = 0 ;
for ( V_82 = 0 ; V_82 < V_110 ; V_82 ++ ) {
if ( V_115 [ V_82 ] == V_378 ) {
V_391 = 1 ;
break;
}
}
return V_391 ;
}
int F_206 ( struct V_4 * V_5 )
{
int V_171 = 0 ;
V_392 = V_102 ;
V_393 = V_216 ;
V_394 = V_284 ;
V_395 = V_5 -> V_89 ;
V_396 = V_88 ;
V_5 -> V_89 = V_286 ;
V_88 = 0 ;
if ( V_5 -> V_16 -> F_206 )
V_171 = V_5 -> V_16 -> F_206 ( V_5 ) ;
#ifdef F_207
if ( V_5 -> V_27 < 999 ) {
int V_397 ;
char V_398 [ 4 ] ;
const char * V_399 [ 3 ] = {
L_25 ,
L_26 ,
V_398 ,
} ;
if ( F_208 ( V_399 [ 0 ] , & V_397 ) ) {
snprintf ( V_398 , 4 , L_27 , V_5 -> V_27 ) ;
F_209 ( 2 , V_399 ) ;
}
}
#endif
return V_171 ;
}
int F_210 ( void )
{
struct V_4 * V_5 ;
int V_171 = 0 ;
V_102 = V_392 ;
V_216 = V_393 ;
V_284 = V_394 ;
V_88 = V_396 ;
V_101 [ V_102 ] . V_25 -> V_89 = V_395 ;
V_5 = V_101 [ V_102 ] . V_25 ;
if ( V_5 -> V_16 -> F_210 )
V_171 = V_5 -> V_16 -> F_210 ( V_5 ) ;
return V_171 ;
}
int F_211 ( const struct V_377 * V_378 , int V_259 , int V_260 )
{
struct V_380 * V_113 = V_378 -> V_113 ;
struct V_344 * V_344 ;
const char * V_347 ;
int V_82 , V_325 = 0 ;
if ( ! F_191 ( V_113 ) )
return - V_381 ;
F_71 () ;
for ( V_82 = 0 ; V_82 < V_343 ; V_82 ++ ) {
V_344 = & V_345 [ V_82 ] ;
if ( V_344 -> V_346 == V_378 )
V_325 = - V_400 ;
}
if ( V_325 )
goto V_137;
V_347 = V_378 -> V_342 () ;
if ( ! V_347 )
goto V_137;
V_325 = - V_158 ;
for ( V_82 = 0 ; V_82 < V_343 ; V_82 ++ ) {
V_344 = & V_345 [ V_82 ] ;
if ( V_344 -> V_346 == NULL ) {
V_344 -> V_346 = V_378 ;
V_344 -> V_347 = V_347 ;
V_344 -> V_401 = V_82 ;
V_344 -> V_348 = V_384 |
V_349 ;
V_344 -> V_259 = V_259 ;
V_344 -> V_260 = V_260 ;
V_325 = 0 ;
break;
}
}
if ( V_325 )
goto V_137;
V_344 -> V_357 = F_178 ( V_402 , NULL ,
F_175 ( 0 , V_344 -> V_401 ) ,
NULL , L_28 ,
V_344 -> V_401 ) ;
if ( F_179 ( V_344 -> V_357 ) ) {
F_124 ( V_403 L_29
L_30 , V_344 -> V_347 ,
F_212 ( V_344 -> V_357 ) ) ;
V_344 -> V_357 = NULL ;
} else {
F_202 ( V_344 ) ;
}
V_137:
F_72 () ;
F_47 ( V_113 ) ;
return V_325 ;
}
int F_213 ( const struct V_377 * V_378 )
{
int V_82 , V_325 = - V_381 ;
F_71 () ;
if ( F_194 ( V_378 ) )
goto V_137;
for ( V_82 = 0 ; V_82 < V_343 ; V_82 ++ ) {
struct V_344 * V_344 = & V_345 [ V_82 ] ;
if ( V_344 -> V_346 == V_378 &&
V_344 -> V_348 & V_384 ) {
F_205 ( V_344 ) ;
F_214 ( V_402 ,
F_175 ( 0 , V_344 -> V_401 ) ) ;
V_344 -> V_346 = NULL ;
V_344 -> V_347 = NULL ;
V_344 -> V_357 = NULL ;
V_344 -> V_401 = 0 ;
V_344 -> V_348 = 0 ;
V_344 -> V_259 = 0 ;
V_344 -> V_260 = 0 ;
V_325 = 0 ;
break;
}
}
V_137:
F_72 () ;
return V_325 ;
}
int F_215 ( const struct V_377 * V_378 , int V_259 , int V_260 , int V_379 )
{
int V_137 ;
V_137 = F_211 ( V_378 , V_259 , V_260 ) ;
if ( V_137 == - V_400 )
V_137 = 0 ;
if ( ! V_137 )
F_190 ( V_378 , V_259 , V_260 , V_379 ) ;
return V_137 ;
}
void F_216 ( const struct V_377 * V_378 )
{
F_213 ( V_378 ) ;
}
static int T_8 F_217 ( void )
{
int V_82 ;
V_402 = F_218 ( V_404 , L_31 ) ;
if ( F_179 ( V_402 ) ) {
F_124 ( V_403 L_32
L_30 , F_212 ( V_402 ) ) ;
V_402 = NULL ;
}
for ( V_82 = 0 ; V_82 < V_343 ; V_82 ++ ) {
struct V_344 * V_346 = & V_345 [ V_82 ] ;
if ( V_346 -> V_346 && ! V_346 -> V_357 ) {
V_346 -> V_357 = F_178 ( V_402 , NULL ,
F_175 ( 0 , V_346 -> V_401 ) ,
NULL , L_28 ,
V_346 -> V_401 ) ;
if ( F_179 ( V_346 -> V_357 ) ) {
F_124 ( V_403 L_33
L_34 ,
V_346 -> V_347 , F_212 ( V_346 -> V_357 ) ) ;
V_346 -> V_357 = NULL ;
} else {
F_202 ( V_346 ) ;
}
}
}
return 0 ;
}
static int F_147 ( char T_7 * V_14 )
{
unsigned int V_291 ;
if ( F_140 ( V_291 , V_14 + 1 ) )
return - V_308 ;
V_405 = ( V_291 < 4 ) ? V_291 : 0 ;
return 0 ;
}
void F_130 ( int V_406 )
{
struct V_4 * V_5 = V_101 [ V_102 ] . V_25 ;
int V_82 ;
F_21 () ;
if ( V_88 ) {
if ( V_350 == V_407 ) {
V_350 = V_408 ;
V_5 -> V_16 -> V_409 ( V_5 , V_405 + 1 , 0 ) ;
}
return;
}
if ( V_406 ) {
F_23 ( V_5 ) ;
F_37 ( V_5 ) ;
V_5 -> V_16 -> V_409 ( V_5 , - 1 , 1 ) ;
V_88 = V_102 + 1 ;
V_350 = V_408 ;
F_36 ( V_5 ) ;
return;
}
if ( V_350 != V_351 )
return;
V_350 = V_408 ;
if ( V_5 -> V_89 != V_286 ) {
V_88 = V_102 + 1 ;
return;
}
F_23 ( V_5 ) ;
F_219 ( & V_352 ) ;
V_288 = 0 ;
F_37 ( V_5 ) ;
V_82 = V_5 -> V_16 -> V_409 ( V_5 , V_215 ? 1 : ( V_405 + 1 ) , 0 ) ;
V_88 = V_102 + 1 ;
if ( V_82 )
F_36 ( V_5 ) ;
if ( V_410 && V_410 ( 1 ) )
return;
if ( V_215 && V_405 ) {
V_350 = V_407 ;
F_167 ( & V_352 , V_353 + V_215 ) ;
}
F_68 ( V_411 , V_5 -> V_104 , V_5 -> V_104 ) ;
}
void F_220 ( int V_412 )
{
struct V_4 * V_5 ;
if ( ! V_413 )
F_123 () ;
F_21 () ;
V_323 = 0 ;
if ( ! V_88 )
return;
if ( ! F_45 ( V_102 ) ) {
F_221 ( L_35 ,
V_102 + 1 ) ;
return;
}
V_5 = V_101 [ V_102 ] . V_25 ;
if ( V_5 -> V_89 != V_286 && ! F_42 ( V_5 ) )
return;
if ( V_209 ) {
F_167 ( & V_352 , V_353 + ( V_209 * V_213 ) ) ;
V_350 = V_351 ;
}
V_88 = 0 ;
if ( V_5 -> V_16 -> V_409 ( V_5 , 0 , V_412 ) || F_42 ( V_5 ) )
F_67 ( V_5 ) ;
if ( V_410 )
V_410 ( 0 ) ;
F_41 ( V_5 ) ;
F_24 ( V_5 ) ;
F_68 ( V_414 , V_5 -> V_104 , V_5 -> V_104 ) ;
}
void F_143 ( void )
{
F_220 ( 0 ) ;
}
static void F_222 ( unsigned long V_415 )
{
if ( F_223 ( ! F_224 () ) ) {
F_167 ( & V_352 , V_353 + ( V_209 * V_213 ) ) ;
return;
}
V_288 = 1 ;
F_11 ( & V_21 ) ;
}
void F_102 ( void )
{
F_21 () ;
F_123 () ;
F_225 ( & V_352 ) ;
V_288 = 0 ;
if ( V_323 || ! V_101 [ V_102 ] . V_25 || V_101 [ V_102 ] . V_25 -> V_89 == V_90 )
return;
if ( V_88 )
F_143 () ;
else if ( V_209 ) {
F_167 ( & V_352 , V_353 + ( V_209 * V_213 ) ) ;
V_350 = V_351 ;
}
}
static void F_41 ( struct V_4 * V_5 )
{
F_21 () ;
if ( V_5 -> V_89 != V_90 )
V_5 -> V_16 -> V_416 ( V_5 , V_193 ) ;
}
int F_226 ( unsigned char T_7 * V_304 )
{
int V_82 , V_248 , V_335 ;
unsigned char V_417 [ 3 * 16 ] ;
if ( F_227 ( V_417 , V_304 , sizeof( V_417 ) ) )
return - V_308 ;
F_71 () ;
for ( V_82 = V_335 = 0 ; V_82 < 16 ; V_82 ++ ) {
V_336 [ V_82 ] = V_417 [ V_335 ++ ] ;
V_337 [ V_82 ] = V_417 [ V_335 ++ ] ;
V_338 [ V_82 ] = V_417 [ V_335 ++ ] ;
}
for ( V_82 = 0 ; V_82 < V_110 ; V_82 ++ ) {
if ( ! F_45 ( V_82 ) )
continue;
for ( V_248 = V_335 = 0 ; V_248 < 16 ; V_248 ++ ) {
V_101 [ V_82 ] . V_25 -> V_249 [ V_335 ++ ] = V_336 [ V_248 ] ;
V_101 [ V_82 ] . V_25 -> V_249 [ V_335 ++ ] = V_337 [ V_248 ] ;
V_101 [ V_82 ] . V_25 -> V_249 [ V_335 ++ ] = V_338 [ V_248 ] ;
}
F_41 ( V_101 [ V_82 ] . V_25 ) ;
}
F_72 () ;
return 0 ;
}
int F_228 ( unsigned char T_7 * V_304 )
{
int V_82 , V_335 ;
unsigned char V_417 [ 3 * 16 ] ;
F_71 () ;
for ( V_82 = V_335 = 0 ; V_82 < 16 ; V_82 ++ ) {
V_417 [ V_335 ++ ] = V_336 [ V_82 ] ;
V_417 [ V_335 ++ ] = V_337 [ V_82 ] ;
V_417 [ V_335 ++ ] = V_338 [ V_82 ] ;
}
F_72 () ;
if ( F_229 ( V_304 , V_417 , sizeof( V_417 ) ) )
return - V_308 ;
return 0 ;
}
void F_114 ( struct V_4 * V_5 )
{
int V_248 , V_335 ;
for ( V_248 = V_335 = 0 ; V_248 < 16 ; V_248 ++ ) {
V_5 -> V_249 [ V_335 ++ ] = V_336 [ V_248 ] ;
V_5 -> V_249 [ V_335 ++ ] = V_337 [ V_248 ] ;
V_5 -> V_249 [ V_335 ++ ] = V_338 [ V_248 ] ;
}
F_41 ( V_5 ) ;
}
static int F_230 ( struct V_4 * V_5 , struct V_418 * V_419 )
{
struct V_420 V_421 ;
int V_422 = - V_158 ;
int V_9 ;
if ( V_419 -> V_305 ) {
V_421 . V_305 = F_56 ( V_423 , V_127 ) ;
if ( ! V_421 . V_305 )
return - V_128 ;
} else
V_421 . V_305 = NULL ;
F_71 () ;
if ( V_5 -> V_89 != V_286 )
V_422 = - V_158 ;
else if ( V_5 -> V_16 -> F_230 )
V_422 = V_5 -> V_16 -> F_230 ( V_5 , & V_421 ) ;
else
V_422 = - V_424 ;
F_72 () ;
if ( V_422 )
goto V_425;
V_9 = ( V_421 . V_134 + 7 ) / 8 * 32 * V_421 . V_426 ;
if ( V_419 -> V_305 && V_421 . V_426 > V_419 -> V_426 )
V_422 = - V_427 ;
if ( ! ( V_419 -> V_373 & V_428 ) ) {
if ( V_421 . V_134 > V_419 -> V_134 || V_421 . V_135 > V_419 -> V_135 )
V_422 = - V_427 ;
} else {
if ( V_421 . V_134 != 8 )
V_422 = - V_429 ;
else if ( ( V_419 -> V_135 && V_421 . V_135 > V_419 -> V_135 ) ||
V_421 . V_135 > 32 )
V_422 = - V_427 ;
}
if ( V_422 )
goto V_425;
V_419 -> V_135 = V_421 . V_135 ;
V_419 -> V_134 = V_421 . V_134 ;
V_419 -> V_426 = V_421 . V_426 ;
if ( V_419 -> V_305 && F_229 ( V_419 -> V_305 , V_421 . V_305 , V_9 ) )
V_422 = - V_308 ;
V_425:
F_57 ( V_421 . V_305 ) ;
return V_422 ;
}
static int F_231 ( struct V_4 * V_5 , struct V_418 * V_419 )
{
struct V_420 V_421 ;
int V_422 = - V_158 ;
int V_430 ;
if ( V_5 -> V_89 != V_286 )
return - V_158 ;
if ( ! V_419 -> V_305 )
return - V_158 ;
if ( V_419 -> V_426 > 512 )
return - V_158 ;
if ( ! V_419 -> V_135 ) {
int V_431 , V_82 ;
T_2 T_7 * V_432 = V_419 -> V_305 ;
T_2 V_433 ;
if ( ! ( V_419 -> V_373 & V_428 ) )
return - V_158 ;
for ( V_431 = 32 ; V_431 > 0 ; V_431 -- )
for ( V_82 = 0 ; V_82 < V_419 -> V_426 ; V_82 ++ ) {
if ( F_140 ( V_433 , & V_432 [ 32 * V_82 + V_431 - 1 ] ) )
return - V_308 ;
if ( V_433 )
goto V_434;
}
return - V_158 ;
V_434:
V_419 -> V_135 = V_431 ;
}
if ( V_419 -> V_134 <= 0 || V_419 -> V_134 > 32 || V_419 -> V_135 > 32 )
return - V_158 ;
V_430 = ( V_419 -> V_134 + 7 ) / 8 * 32 * V_419 -> V_426 ;
if ( V_430 > V_423 )
return - V_427 ;
V_421 . V_426 = V_419 -> V_426 ;
V_421 . V_135 = V_419 -> V_135 ;
V_421 . V_134 = V_419 -> V_134 ;
V_421 . V_305 = F_232 ( V_419 -> V_305 , V_430 ) ;
if ( F_179 ( V_421 . V_305 ) )
return F_212 ( V_421 . V_305 ) ;
F_71 () ;
if ( V_5 -> V_89 != V_286 )
V_422 = - V_158 ;
else if ( V_5 -> V_16 -> F_231 )
V_422 = V_5 -> V_16 -> F_231 ( V_5 , & V_421 , V_419 -> V_373 ) ;
else
V_422 = - V_424 ;
F_72 () ;
F_57 ( V_421 . V_305 ) ;
return V_422 ;
}
static int F_233 ( struct V_4 * V_5 , struct V_418 * V_419 )
{
struct V_420 V_421 = { . V_134 = V_419 -> V_134 , . V_135 = V_419 -> V_135 } ;
char V_366 [ V_435 ] ;
char * V_26 = V_366 ;
int V_422 ;
if ( ! V_419 -> V_305 )
V_26 = NULL ;
else if ( F_234 ( V_366 , V_419 -> V_305 , V_435 - 1 ) < 0 )
return - V_308 ;
else
V_366 [ V_435 - 1 ] = 0 ;
F_71 () ;
if ( V_5 -> V_89 != V_286 ) {
F_72 () ;
return - V_158 ;
}
if ( V_5 -> V_16 -> F_233 )
V_422 = V_5 -> V_16 -> F_233 ( V_5 , & V_421 , V_26 ) ;
else
V_422 = - V_424 ;
F_72 () ;
if ( ! V_422 ) {
V_419 -> V_134 = V_421 . V_134 ;
V_419 -> V_135 = V_421 . V_135 ;
}
return V_422 ;
}
static int F_235 ( struct V_4 * V_5 , struct V_418 * V_419 )
{
int V_346 = V_419 -> V_135 ;
int V_422 ;
F_71 () ;
if ( V_5 -> V_89 != V_286 )
V_422 = - V_158 ;
else if ( ! V_5 -> V_16 -> F_235 )
V_422 = - V_424 ;
else if ( V_346 < 0 || ! F_45 ( V_346 ) )
V_422 = - V_436 ;
else if ( V_346 == V_5 -> V_104 )
V_422 = 0 ;
else
V_422 = V_5 -> V_16 -> F_235 ( V_5 , V_346 ) ;
F_72 () ;
return V_422 ;
}
int F_236 ( struct V_4 * V_5 , struct V_418 * V_419 )
{
switch ( V_419 -> V_419 ) {
case V_437 :
return F_231 ( V_5 , V_419 ) ;
case V_438 :
return F_230 ( V_5 , V_419 ) ;
case V_439 :
return F_233 ( V_5 , V_419 ) ;
case V_440 :
return F_235 ( V_5 , V_419 ) ;
}
return - V_424 ;
}
T_1 F_237 ( struct V_4 * V_5 , int V_12 )
{
T_1 V_441 = F_19 ( F_8 ( V_5 , V_12 , 1 ) ) ;
T_1 V_9 = V_441 & 0xff ;
if ( V_441 & V_5 -> V_57 )
V_9 |= 0x100 ;
return V_9 ;
}
unsigned short * F_238 ( struct V_4 * V_5 , int V_442 , int V_13 )
{
return F_8 ( V_5 , 2 * V_442 , V_13 ) ;
}
void F_239 ( struct V_4 * V_5 , unsigned char * V_14 )
{
V_14 [ 0 ] = V_5 -> V_77 ;
V_14 [ 1 ] = V_5 -> V_81 ;
}
void F_240 ( struct V_4 * V_5 , unsigned char * V_14 )
{
F_23 ( V_5 ) ;
F_64 ( V_5 , V_14 [ 0 ] , V_14 [ 1 ] ) ;
F_24 ( V_5 ) ;
}
T_1 F_241 ( struct V_4 * V_5 , const T_1 * V_443 )
{
if ( ( unsigned long ) V_443 == V_5 -> V_76 && V_84 != - 1 )
return V_84 ;
return F_19 ( V_443 ) ;
}
void F_242 ( struct V_4 * V_5 , T_1 V_444 , T_1 * V_443 )
{
F_28 ( V_444 , V_443 ) ;
if ( ( unsigned long ) V_443 == V_5 -> V_76 ) {
V_84 = - 1 ;
F_32 ( V_5 ) ;
}
}
void F_243 ( struct V_4 * V_5 )
{
F_7 ( V_5 ) ;
}
