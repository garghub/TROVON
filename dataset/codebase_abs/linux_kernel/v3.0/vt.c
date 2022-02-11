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
struct V_7 V_8 = { . V_5 = V_5 , V_6 = V_6 } ;
F_6 ( & V_3 , V_9 , & V_8 ) ;
}
static void F_7 ( struct V_4 * V_5 )
{
struct V_7 V_8 = { . V_5 = V_5 } ;
F_6 ( & V_3 , V_10 , & V_8 ) ;
}
static inline unsigned short * F_8 ( struct V_4 * V_5 , int V_11 , int V_12 )
{
unsigned short * V_13 ;
if ( ! V_12 )
V_13 = ( unsigned short * ) ( V_5 -> V_14 + V_11 ) ;
else if ( ! V_5 -> V_15 -> V_16 )
V_13 = ( unsigned short * ) ( V_5 -> V_17 + V_11 ) ;
else
V_13 = V_5 -> V_15 -> V_16 ( V_5 , V_11 ) ;
return V_13 ;
}
static inline void F_9 ( int V_18 )
{
V_19 += V_18 ;
F_10 () ;
}
void F_10 ( void )
{
F_11 ( & V_20 ) ;
}
static void F_12 ( struct V_4 * V_5 , unsigned int V_21 , unsigned int V_22 , int V_23 )
{
unsigned short * V_24 , * V_25 ;
if ( V_21 + V_23 >= V_22 )
V_23 = V_22 - V_21 - 1 ;
if ( V_22 > V_5 -> V_26 || V_21 >= V_22 || V_23 < 1 )
return;
if ( F_13 ( V_5 ) && V_5 -> V_15 -> V_27 ( V_5 , V_21 , V_22 , V_28 , V_23 ) )
return;
V_24 = ( unsigned short * ) ( V_5 -> V_14 + V_5 -> V_29 * V_21 ) ;
V_25 = ( unsigned short * ) ( V_5 -> V_14 + V_5 -> V_29 * ( V_21 + V_23 ) ) ;
F_14 ( V_24 , V_25 , ( V_22 - V_21 - V_23 ) * V_5 -> V_29 ) ;
F_15 ( V_24 + ( V_22 - V_21 - V_23 ) * V_5 -> V_30 , V_5 -> V_31 ,
V_5 -> V_29 * V_23 ) ;
}
static void F_16 ( struct V_4 * V_5 , unsigned int V_21 , unsigned int V_22 , int V_23 )
{
unsigned short * V_25 ;
unsigned int V_32 ;
if ( V_21 + V_23 >= V_22 )
V_23 = V_22 - V_21 - 1 ;
if ( V_22 > V_5 -> V_26 || V_21 >= V_22 || V_23 < 1 )
return;
if ( F_13 ( V_5 ) && V_5 -> V_15 -> V_27 ( V_5 , V_21 , V_22 , V_33 , V_23 ) )
return;
V_25 = ( unsigned short * ) ( V_5 -> V_14 + V_5 -> V_29 * V_21 ) ;
V_32 = V_5 -> V_30 * V_23 ;
F_14 ( V_25 + V_32 , V_25 , ( V_22 - V_21 - V_23 ) * V_5 -> V_29 ) ;
F_15 ( V_25 , V_5 -> V_31 , 2 * V_32 ) ;
}
static void F_17 ( struct V_4 * V_5 , unsigned long V_34 , int V_35 )
{
#ifndef F_18
unsigned int V_36 , V_37 , V_11 ;
T_1 * V_13 ;
V_13 = ( T_1 * ) V_34 ;
if ( ! V_5 -> V_15 -> V_38 ) {
V_11 = ( V_34 - V_5 -> V_14 ) / 2 ;
V_36 = V_11 % V_5 -> V_30 ;
V_37 = V_11 / V_5 -> V_30 ;
} else {
int V_39 , V_40 ;
V_34 = V_5 -> V_15 -> V_38 ( V_5 , V_34 , & V_39 , & V_40 ) ;
V_36 = V_39 ; V_37 = V_40 ;
}
for(; ; ) {
T_1 V_41 = F_19 ( V_13 ) & 0xff00 ;
int V_42 = V_36 ;
T_1 * V_43 = V_13 ;
while ( V_36 < V_5 -> V_30 && V_35 ) {
if ( V_41 != ( F_19 ( V_13 ) & 0xff00 ) ) {
if ( V_13 > V_43 )
V_5 -> V_15 -> V_44 ( V_5 , V_43 , V_13 - V_43 , V_37 , V_42 ) ;
V_42 = V_36 ;
V_43 = V_13 ;
V_41 = F_19 ( V_13 ) & 0xff00 ;
}
V_13 ++ ;
V_36 ++ ;
V_35 -- ;
}
if ( V_13 > V_43 )
V_5 -> V_15 -> V_44 ( V_5 , V_43 , V_13 - V_43 , V_37 , V_42 ) ;
if ( ! V_35 )
break;
V_36 = 0 ;
V_37 ++ ;
if ( V_5 -> V_15 -> V_38 ) {
V_13 = ( T_1 * ) V_34 ;
V_34 = V_5 -> V_15 -> V_38 ( V_5 , V_34 , NULL , NULL ) ;
}
}
#endif
}
void F_20 ( struct V_4 * V_5 , unsigned long V_34 , int V_35 )
{
F_21 () ;
if ( F_22 ( V_5 ) ) {
F_23 ( V_5 ) ;
F_17 ( V_5 , V_34 , V_35 ) ;
F_24 ( V_5 ) ;
}
}
static T_2 F_25 ( struct V_4 * V_5 , T_2 V_45 , T_2 V_46 , T_2 V_47 ,
T_2 V_48 , T_2 V_49 , T_2 V_50 )
{
if ( V_5 -> V_15 -> V_51 )
return V_5 -> V_15 -> V_51 ( V_5 , V_45 , V_46 ,
V_47 , V_48 , V_49 , V_50 ) ;
#ifndef F_18
{
T_2 V_52 = V_45 ;
if ( ! V_5 -> V_53 )
return V_46 |
( V_50 ? 2 : 0 ) |
( V_48 ? 4 : 0 ) |
( V_49 ? 8 : 0 ) |
( V_47 ? 0x80 : 0 ) ;
if ( V_50 )
V_52 = ( V_52 & 0xF0 ) | V_5 -> V_54 ;
else if ( V_48 )
V_52 = ( V_52 & 0xf0 ) | V_5 -> V_55 ;
else if ( V_46 == 0 )
V_52 = ( V_52 & 0xf0 ) | V_5 -> V_55 ;
if ( V_49 )
V_52 = ( ( V_52 ) & 0x88 ) | ( ( ( ( V_52 ) >> 4 ) | ( ( V_52 ) << 4 ) ) & 0x77 ) ;
if ( V_47 )
V_52 ^= 0x80 ;
if ( V_46 == 2 )
V_52 ^= 0x08 ;
if ( V_5 -> V_56 == 0x100 )
V_52 <<= 1 ;
return V_52 ;
}
#else
return 0 ;
#endif
}
static void F_26 ( struct V_4 * V_5 )
{
V_5 -> V_57 = F_25 ( V_5 , V_5 -> V_58 , V_5 -> V_59 ,
V_5 -> V_60 , V_5 -> V_61 ,
V_5 -> V_62 ^ V_5 -> V_63 , V_5 -> V_64 ) ;
V_5 -> V_31 = ( F_25 ( V_5 , V_5 -> V_58 , 1 , V_5 -> V_60 , 0 , V_5 -> V_63 , 0 ) << 8 ) | ' ' ;
}
void F_27 ( struct V_4 * V_5 , int V_11 , int V_35 , int V_12 )
{
unsigned short * V_13 ;
F_21 () ;
V_35 /= 2 ;
V_13 = F_8 ( V_5 , V_11 , V_12 ) ;
if ( V_5 -> V_15 -> V_65 )
V_5 -> V_15 -> V_65 ( V_5 , V_13 , V_35 ) ;
#ifndef F_18
else {
T_1 * V_43 = V_13 ;
int V_66 = V_35 ;
T_1 V_52 ;
if ( ! V_5 -> V_53 ) {
while ( V_66 -- ) {
V_52 = F_19 ( V_43 ) ;
V_52 ^= 0x0800 ;
F_28 ( V_52 , V_43 ) ;
V_43 ++ ;
}
} else if ( V_5 -> V_56 == 0x100 ) {
while ( V_66 -- ) {
V_52 = F_19 ( V_43 ) ;
V_52 = ( ( V_52 ) & 0x11ff ) | ( ( ( V_52 ) & 0xe000 ) >> 4 ) | ( ( ( V_52 ) & 0x0e00 ) << 4 ) ;
F_28 ( V_52 , V_43 ) ;
V_43 ++ ;
}
} else {
while ( V_66 -- ) {
V_52 = F_19 ( V_43 ) ;
V_52 = ( ( V_52 ) & 0x88ff ) | ( ( ( V_52 ) & 0x7000 ) >> 4 ) | ( ( ( V_52 ) & 0x0700 ) << 4 ) ;
F_28 ( V_52 , V_43 ) ;
V_43 ++ ;
}
}
}
#endif
if ( F_22 ( V_5 ) )
F_17 ( V_5 , ( unsigned long ) V_13 , V_35 ) ;
}
void F_29 ( struct V_4 * V_5 , int V_11 )
{
static int V_67 = - 1 ;
static unsigned short V_68 ;
static unsigned short V_69 , V_70 ;
F_21 () ;
if ( V_67 != - 1 && V_67 >= 0 &&
V_67 < V_5 -> V_71 ) {
F_28 ( V_68 , F_8 ( V_5 , V_67 , 1 ) ) ;
if ( F_22 ( V_5 ) )
V_5 -> V_15 -> V_72 ( V_5 , V_68 , V_70 , V_69 ) ;
}
V_67 = V_11 ;
if ( V_11 != - 1 && V_11 >= 0 &&
V_11 < V_5 -> V_71 ) {
unsigned short V_73 ;
unsigned short * V_13 ;
V_13 = F_8 ( V_5 , V_11 , 1 ) ;
V_68 = F_19 ( V_13 ) ;
V_73 = V_68 ^ V_5 -> V_74 ;
F_28 ( V_73 , V_13 ) ;
if ( F_22 ( V_5 ) ) {
V_69 = ( V_11 >> 1 ) % V_5 -> V_30 ;
V_70 = ( V_11 >> 1 ) / V_5 -> V_30 ;
V_5 -> V_15 -> V_72 ( V_5 , V_73 , V_70 , V_69 ) ;
}
}
}
static void F_30 ( struct V_4 * V_5 , unsigned int V_23 )
{
unsigned short * V_13 , * V_43 = ( unsigned short * ) V_5 -> V_75 ;
V_13 = V_43 + V_5 -> V_30 - V_23 - V_5 -> V_76 ;
while ( -- V_13 >= V_43 )
F_28 ( F_19 ( V_13 ) , V_13 + V_23 ) ;
F_15 ( V_43 , V_5 -> V_31 , V_23 * 2 ) ;
V_5 -> V_77 = 0 ;
if ( F_22 ( V_5 ) ) {
unsigned short V_78 = V_5 -> V_57 ;
V_5 -> V_15 -> V_79 ( V_5 , V_5 -> V_80 , V_5 -> V_76 , V_5 -> V_80 , V_5 -> V_76 + V_23 , 1 ,
V_5 -> V_30 - V_5 -> V_76 - V_23 ) ;
V_5 -> V_57 = V_5 -> V_31 >> 8 ;
while ( V_23 -- )
V_5 -> V_15 -> V_72 ( V_5 , V_5 -> V_31 , V_5 -> V_80 , V_5 -> V_76 + V_23 ) ;
V_5 -> V_57 = V_78 ;
}
}
static void F_31 ( struct V_4 * V_5 , unsigned int V_23 )
{
unsigned int V_81 = V_5 -> V_76 ;
unsigned short * V_13 = ( unsigned short * ) V_5 -> V_75 ;
while ( ++ V_81 <= V_5 -> V_30 - V_23 ) {
F_28 ( F_19 ( V_13 + V_23 ) , V_13 ) ;
V_13 ++ ;
}
F_15 ( V_13 , V_5 -> V_31 , V_23 * 2 ) ;
V_5 -> V_77 = 0 ;
if ( F_22 ( V_5 ) ) {
unsigned short V_78 = V_5 -> V_57 ;
V_5 -> V_15 -> V_79 ( V_5 , V_5 -> V_80 , V_5 -> V_76 + V_23 , V_5 -> V_80 , V_5 -> V_76 , 1 ,
V_5 -> V_30 - V_5 -> V_76 - V_23 ) ;
V_5 -> V_57 = V_5 -> V_31 >> 8 ;
while ( V_23 -- )
V_5 -> V_15 -> V_72 ( V_5 , V_5 -> V_31 , V_5 -> V_80 ,
V_5 -> V_30 - 1 - V_23 ) ;
V_5 -> V_57 = V_78 ;
}
}
static void F_32 ( struct V_4 * V_5 )
{
int V_81 = F_19 ( ( T_1 * ) V_5 -> V_75 ) ;
T_3 type = V_5 -> V_82 ;
if ( ! ( type & 0x10 ) ) return;
if ( V_83 != - 1 ) return;
V_83 = V_81 ;
V_81 |= ( ( type >> 8 ) & 0xff00 ) ;
V_81 ^= ( ( type ) & 0xff00 ) ;
if ( ( type & 0x20 ) && ( ( V_83 & 0x7000 ) == ( V_81 & 0x7000 ) ) ) V_81 ^= 0x7000 ;
if ( ( type & 0x40 ) && ( ( V_81 & 0x700 ) == ( ( V_81 & 0x7000 ) >> 4 ) ) ) V_81 ^= 0x0700 ;
F_28 ( V_81 , ( T_1 * ) V_5 -> V_75 ) ;
if ( F_22 ( V_5 ) )
V_5 -> V_15 -> V_72 ( V_5 , V_81 , V_5 -> V_80 , V_5 -> V_76 ) ;
}
static void F_33 ( struct V_4 * V_5 )
{
if ( V_83 != - 1 ) {
F_28 ( V_83 , ( T_1 * ) V_5 -> V_75 ) ;
if ( F_22 ( V_5 ) )
V_5 -> V_15 -> V_72 ( V_5 , V_83 ,
V_5 -> V_80 , V_5 -> V_76 ) ;
V_83 = - 1 ;
}
}
static void F_23 ( struct V_4 * V_5 )
{
if ( V_5 == V_84 )
F_34 () ;
V_5 -> V_15 -> V_85 ( V_5 , V_86 ) ;
F_33 ( V_5 ) ;
}
static void F_24 ( struct V_4 * V_5 )
{
if ( ! F_35 ( V_5 ) || V_87 ||
V_5 -> V_88 == V_89 )
return;
if ( V_5 -> V_90 ) {
if ( V_5 == V_84 )
F_34 () ;
F_32 ( V_5 ) ;
if ( ( V_5 -> V_82 & 0x0f ) != 1 )
V_5 -> V_15 -> V_85 ( V_5 , V_91 ) ;
} else
F_23 ( V_5 ) ;
}
static void F_36 ( struct V_4 * V_5 )
{
F_21 () ;
if ( ! F_13 ( V_5 ) ||
! V_5 -> V_15 -> V_92 ||
! V_5 -> V_15 -> V_92 ( V_5 ) )
V_5 -> V_14 = ( unsigned long ) V_5 -> V_93 ;
V_5 -> V_17 = V_5 -> V_14 ;
V_5 -> V_94 = V_5 -> V_14 + V_5 -> V_71 ;
V_5 -> V_75 = V_5 -> V_14 + V_5 -> V_29 * V_5 -> V_80 + 2 * V_5 -> V_76 ;
}
static inline void F_37 ( struct V_4 * V_5 )
{
F_21 () ;
if ( V_5 -> V_15 -> V_95 )
V_5 -> V_15 -> V_95 ( V_5 ) ;
}
static void F_38 ( struct V_4 * V_5 )
{
unsigned short * V_13 = ( unsigned short * ) V_5 -> V_14 ;
int V_35 = V_5 -> V_71 / 2 ;
int V_96 = V_5 -> V_56 | 0xff ;
for (; V_35 > 0 ; V_35 -- , V_13 ++ ) {
F_28 ( ( F_19 ( V_13 ) & V_96 ) | ( V_5 -> V_31 & ~ V_96 ) , V_13 ) ;
}
}
void F_39 ( struct V_4 * V_5 , int V_97 )
{
int V_98 = 0 ;
F_21 () ;
if ( ! V_5 ) {
return;
}
if ( V_97 ) {
struct V_4 * V_99 = V_100 [ V_101 ] . V_24 ;
if ( V_99 == V_5 )
return;
if ( ! F_13 ( V_5 ) )
V_98 = 1 ;
* V_5 -> V_102 = V_5 ;
V_101 = V_5 -> V_103 ;
F_23 ( V_99 ) ;
if ( ! F_13 ( V_99 ) ) {
F_37 ( V_99 ) ;
F_36 ( V_99 ) ;
}
if ( V_104 )
F_40 ( & V_104 -> V_105 , NULL , L_1 ) ;
} else {
F_23 ( V_5 ) ;
V_98 = 1 ;
}
if ( V_98 ) {
int V_106 ;
int V_107 = V_5 -> V_53 ;
F_36 ( V_5 ) ;
V_106 = V_5 -> V_15 -> V_108 ( V_5 ) ;
F_41 ( V_5 ) ;
if ( V_107 != V_5 -> V_53 ) {
F_26 ( V_5 ) ;
F_38 ( V_5 ) ;
}
if ( ( V_106 && V_5 -> V_88 != V_89 ) ||
F_42 ( V_5 ) )
F_17 ( V_5 , V_5 -> V_14 , V_5 -> V_71 / 2 ) ;
}
F_24 ( V_5 ) ;
if ( V_97 ) {
F_43 () ;
F_44 () ;
F_7 ( V_5 ) ;
}
}
int F_45 ( unsigned int V_81 )
{
return ( V_81 < V_109 && V_100 [ V_81 ] . V_24 ) ;
}
static void F_46 ( struct V_4 * V_5 , int V_110 , int V_111 )
{
if ( V_5 -> V_15 )
F_47 ( V_5 -> V_15 -> V_112 ) ;
V_5 -> V_15 = V_113 ;
#ifndef F_48
if ( V_114 [ V_110 ] )
V_5 -> V_15 = V_114 [ V_110 ] ;
#endif
F_49 ( V_5 -> V_15 -> V_112 ) ;
V_5 -> V_103 = V_110 ;
V_5 -> V_102 = & V_115 ;
V_5 -> V_116 = & V_5 -> V_117 ;
V_5 -> V_117 = 0 ;
V_5 -> V_56 = 0 ;
V_5 -> V_74 = 0 ;
V_5 -> V_53 = 0 ;
V_5 -> V_118 = false ;
V_5 -> V_15 -> V_119 ( V_5 , V_111 ) ;
if ( ! V_5 -> V_74 )
V_5 -> V_74 = V_5 -> V_53 ? 0x7700 : 0x0800 ;
V_5 -> V_120 = V_5 -> V_74 ;
V_5 -> V_29 = V_5 -> V_30 << 1 ;
V_5 -> V_71 = V_5 -> V_26 * V_5 -> V_29 ;
}
int F_50 ( unsigned int V_121 )
{
F_21 () ;
if ( V_121 >= V_109 )
return - V_122 ;
if ( ! V_100 [ V_121 ] . V_24 ) {
struct V_4 * V_5 ;
struct V_7 V_8 ;
if ( V_121 >= V_123 && ! F_51 ( V_124 ) )
return - V_125 ;
V_8 . V_5 = V_5 = F_52 ( sizeof( struct V_4 ) , V_126 ) ;
if ( ! V_5 )
return - V_127 ;
V_100 [ V_121 ] . V_24 = V_5 ;
F_53 ( & V_5 -> V_128 ) ;
F_54 ( & V_100 [ V_121 ] . V_129 , V_130 ) ;
F_46 ( V_5 , V_121 , 1 ) ;
if ( ! * V_5 -> V_116 )
F_55 ( V_5 ) ;
V_5 -> V_93 = F_56 ( V_5 -> V_71 , V_126 ) ;
if ( ! V_5 -> V_93 ) {
F_57 ( V_5 ) ;
V_100 [ V_121 ] . V_24 = NULL ;
return - V_127 ;
}
if ( V_131 == - 1 )
V_131 = 1 ;
F_58 ( V_5 , V_5 -> V_26 , V_5 -> V_30 , 1 ) ;
F_59 ( V_121 ) ;
F_6 ( & V_3 , V_132 , & V_8 ) ;
}
return 0 ;
}
static inline int F_60 ( struct V_4 * V_5 , int V_133 , int V_134 ,
int V_135 )
{
int V_136 = 0 ;
if ( V_5 -> V_88 != V_89 && V_5 -> V_15 -> V_137 )
V_136 = V_5 -> V_15 -> V_137 ( V_5 , V_133 , V_134 , V_135 ) ;
return V_136 ;
}
static int F_61 ( struct V_138 * V_139 , struct V_4 * V_5 ,
unsigned int V_140 , unsigned int V_18 )
{
unsigned long V_141 , V_142 , V_143 , V_144 , V_145 , V_136 = 0 ;
unsigned long V_146 ;
unsigned int V_147 , V_148 ;
unsigned int V_149 , V_150 , V_151 , V_152 ;
unsigned int V_135 ;
unsigned short * V_153 ;
F_21 () ;
if ( ! V_5 )
return - V_122 ;
V_135 = V_5 -> V_154 ;
V_5 -> V_154 = 0 ;
if ( V_140 > V_155 || V_18 > V_156 )
return - V_157 ;
V_149 = ( V_140 ? V_140 : V_5 -> V_30 ) ;
V_150 = ( V_18 ? V_18 : V_5 -> V_26 ) ;
V_151 = V_149 << 1 ;
V_152 = V_151 * V_150 ;
if ( V_149 == V_5 -> V_30 && V_150 == V_5 -> V_26 )
return 0 ;
V_153 = F_56 ( V_152 , V_158 ) ;
if ( ! V_153 )
return - V_127 ;
V_147 = V_5 -> V_26 ;
V_148 = V_5 -> V_29 ;
V_136 = F_60 ( V_5 , V_149 , V_150 , V_135 ) ;
if ( V_136 ) {
F_57 ( V_153 ) ;
return V_136 ;
}
V_5 -> V_26 = V_150 ;
V_5 -> V_30 = V_149 ;
V_5 -> V_29 = V_151 ;
V_5 -> V_71 = V_152 ;
V_144 = F_62 ( V_148 , V_151 ) ;
V_145 = V_151 - V_144 ;
V_141 = V_5 -> V_14 ;
V_142 = ( long ) V_153 ;
V_143 = V_142 + V_152 ;
if ( V_5 -> V_80 > V_150 ) {
if ( V_147 - V_5 -> V_80 < V_150 ) {
V_141 += ( V_147 - V_150 ) * V_148 ;
} else {
V_141 += ( V_5 -> V_80 - V_150 / 2 ) * V_148 ;
}
}
V_146 = V_141 + V_148 * F_62 ( V_147 , V_150 ) ;
F_26 ( V_5 ) ;
while ( V_141 < V_146 ) {
F_63 ( ( unsigned short * ) V_142 ,
( unsigned short * ) V_141 , V_144 ) ;
if ( V_145 )
F_15 ( ( void * ) ( V_142 + V_144 ) ,
V_5 -> V_31 , V_145 ) ;
V_141 += V_148 ;
V_142 += V_151 ;
}
if ( V_143 > V_142 )
F_15 ( ( void * ) V_142 , V_5 -> V_31 ,
V_143 - V_142 ) ;
F_57 ( V_5 -> V_93 ) ;
V_5 -> V_93 = V_153 ;
V_5 -> V_71 = V_152 ;
F_36 ( V_5 ) ;
V_5 -> V_159 = 0 ;
V_5 -> V_160 = V_5 -> V_26 ;
F_64 ( V_5 , V_5 -> V_76 , V_5 -> V_80 ) ;
F_65 ( V_5 ) ;
if ( V_139 ) {
struct V_161 V_162 ;
memset ( & V_162 , 0 , sizeof( V_162 ) ) ;
V_162 . V_163 = V_5 -> V_26 ;
V_162 . V_164 = V_5 -> V_30 ;
V_162 . V_165 = V_5 -> V_166 ;
F_66 ( V_139 , & V_162 ) ;
}
if ( F_13 ( V_5 ) )
F_67 ( V_5 ) ;
F_68 ( V_167 , V_5 -> V_103 , V_5 -> V_103 ) ;
return V_136 ;
}
int F_69 ( struct V_4 * V_5 , unsigned int V_140 , unsigned int V_168 )
{
return F_61 ( V_5 -> V_128 . V_139 , V_5 , V_140 , V_168 ) ;
}
static int F_70 ( struct V_138 * V_139 , struct V_161 * V_162 )
{
struct V_4 * V_5 = V_139 -> V_169 ;
int V_170 ;
F_71 () ;
V_170 = F_61 ( V_139 , V_5 , V_162 -> V_164 , V_162 -> V_163 ) ;
F_72 () ;
return V_170 ;
}
void F_73 ( unsigned int V_121 )
{
F_21 () ;
if ( F_45 ( V_121 ) ) {
struct V_4 * V_5 = V_100 [ V_121 ] . V_24 ;
struct V_7 V_8 = { . V_5 = V_5 } ;
F_6 ( & V_3 , V_171 , & V_8 ) ;
F_74 ( V_121 ) ;
V_5 -> V_15 -> V_172 ( V_5 ) ;
F_75 ( V_5 -> V_173 ) ;
F_47 ( V_5 -> V_15 -> V_112 ) ;
F_57 ( V_5 -> V_93 ) ;
if ( V_121 >= V_174 )
F_57 ( V_5 ) ;
V_100 [ V_121 ] . V_24 = NULL ;
}
}
static void F_64 ( struct V_4 * V_5 , int V_175 , int V_176 )
{
int V_177 , V_178 ;
if ( V_175 < 0 )
V_5 -> V_76 = 0 ;
else {
if ( V_175 >= V_5 -> V_30 )
V_5 -> V_76 = V_5 -> V_30 - 1 ;
else
V_5 -> V_76 = V_175 ;
}
if ( V_5 -> V_179 ) {
V_177 = V_5 -> V_159 ;
V_178 = V_5 -> V_160 ;
} else {
V_177 = 0 ;
V_178 = V_5 -> V_26 ;
}
if ( V_176 < V_177 )
V_5 -> V_80 = V_177 ;
else if ( V_176 >= V_178 )
V_5 -> V_80 = V_178 - 1 ;
else
V_5 -> V_80 = V_176 ;
V_5 -> V_75 = V_5 -> V_14 + V_5 -> V_80 * V_5 -> V_29 + ( V_5 -> V_76 << 1 ) ;
V_5 -> V_77 = 0 ;
}
static void F_76 ( struct V_4 * V_5 , int V_175 , int V_176 )
{
F_64 ( V_5 , V_175 , V_5 -> V_179 ? ( V_5 -> V_159 + V_176 ) : V_176 ) ;
}
void F_77 ( struct V_4 * V_5 , int V_18 )
{
if ( ! V_18 )
V_18 = V_5 -> V_26 / 2 ;
F_9 ( - V_18 ) ;
}
void F_78 ( struct V_4 * V_5 , int V_18 )
{
if ( ! V_18 )
V_18 = V_5 -> V_26 / 2 ;
F_9 ( V_18 ) ;
}
static void F_79 ( struct V_4 * V_5 )
{
if ( V_5 -> V_80 + 1 == V_5 -> V_160 )
F_12 ( V_5 , V_5 -> V_159 , V_5 -> V_160 , 1 ) ;
else if ( V_5 -> V_80 < V_5 -> V_26 - 1 ) {
V_5 -> V_80 ++ ;
V_5 -> V_75 += V_5 -> V_29 ;
}
V_5 -> V_77 = 0 ;
F_5 ( V_5 , '\n' ) ;
}
static void F_80 ( struct V_4 * V_5 )
{
if ( V_5 -> V_80 == V_5 -> V_159 )
F_16 ( V_5 , V_5 -> V_159 , V_5 -> V_160 , 1 ) ;
else if ( V_5 -> V_80 > 0 ) {
V_5 -> V_80 -- ;
V_5 -> V_75 -= V_5 -> V_29 ;
}
V_5 -> V_77 = 0 ;
}
static inline void F_81 ( struct V_4 * V_5 )
{
V_5 -> V_75 -= V_5 -> V_76 << 1 ;
V_5 -> V_77 = V_5 -> V_76 = 0 ;
F_5 ( V_5 , '\r' ) ;
}
static inline void F_82 ( struct V_4 * V_5 )
{
if ( V_5 -> V_76 ) {
V_5 -> V_75 -= 2 ;
V_5 -> V_76 -- ;
V_5 -> V_77 = 0 ;
F_5 ( V_5 , '\b' ) ;
}
}
static inline void F_83 ( struct V_4 * V_5 )
{
}
static void F_84 ( struct V_4 * V_5 , int V_180 )
{
unsigned int V_35 ;
unsigned short * V_34 ;
switch ( V_180 ) {
case 0 :
V_35 = ( V_5 -> V_94 - V_5 -> V_75 ) >> 1 ;
V_34 = ( unsigned short * ) V_5 -> V_75 ;
if ( F_22 ( V_5 ) ) {
V_5 -> V_15 -> V_181 ( V_5 , V_5 -> V_80 , V_5 -> V_76 , 1 ,
V_5 -> V_30 - V_5 -> V_76 ) ;
V_5 -> V_15 -> V_181 ( V_5 , V_5 -> V_80 + 1 , 0 ,
V_5 -> V_26 - V_5 -> V_80 - 1 ,
V_5 -> V_30 ) ;
}
break;
case 1 :
V_35 = ( ( V_5 -> V_75 - V_5 -> V_14 ) >> 1 ) + 1 ;
V_34 = ( unsigned short * ) V_5 -> V_14 ;
if ( F_22 ( V_5 ) ) {
V_5 -> V_15 -> V_181 ( V_5 , 0 , 0 , V_5 -> V_80 ,
V_5 -> V_30 ) ;
V_5 -> V_15 -> V_181 ( V_5 , V_5 -> V_80 , 0 , 1 ,
V_5 -> V_76 + 1 ) ;
}
break;
case 3 :
F_15 ( V_5 -> V_93 , V_5 -> V_31 ,
V_5 -> V_71 >> 1 ) ;
F_36 ( V_5 ) ;
if ( F_13 ( V_5 ) )
F_67 ( V_5 ) ;
case 2 :
V_35 = V_5 -> V_30 * V_5 -> V_26 ;
V_34 = ( unsigned short * ) V_5 -> V_14 ;
if ( F_22 ( V_5 ) )
V_5 -> V_15 -> V_181 ( V_5 , 0 , 0 ,
V_5 -> V_26 ,
V_5 -> V_30 ) ;
break;
default:
return;
}
F_15 ( V_34 , V_5 -> V_31 , 2 * V_35 ) ;
V_5 -> V_77 = 0 ;
}
static void F_85 ( struct V_4 * V_5 , int V_180 )
{
unsigned int V_35 ;
unsigned short * V_34 ;
switch ( V_180 ) {
case 0 :
V_35 = V_5 -> V_30 - V_5 -> V_76 ;
V_34 = ( unsigned short * ) V_5 -> V_75 ;
if ( F_22 ( V_5 ) )
V_5 -> V_15 -> V_181 ( V_5 , V_5 -> V_80 , V_5 -> V_76 , 1 ,
V_5 -> V_30 - V_5 -> V_76 ) ;
break;
case 1 :
V_34 = ( unsigned short * ) ( V_5 -> V_75 - ( V_5 -> V_76 << 1 ) ) ;
V_35 = V_5 -> V_76 + 1 ;
if ( F_22 ( V_5 ) )
V_5 -> V_15 -> V_181 ( V_5 , V_5 -> V_80 , 0 , 1 ,
V_5 -> V_76 + 1 ) ;
break;
case 2 :
V_34 = ( unsigned short * ) ( V_5 -> V_75 - ( V_5 -> V_76 << 1 ) ) ;
V_35 = V_5 -> V_30 ;
if ( F_22 ( V_5 ) )
V_5 -> V_15 -> V_181 ( V_5 , V_5 -> V_80 , 0 , 1 ,
V_5 -> V_30 ) ;
break;
default:
return;
}
F_15 ( V_34 , V_5 -> V_31 , 2 * V_35 ) ;
V_5 -> V_77 = 0 ;
}
static void F_86 ( struct V_4 * V_5 , int V_180 )
{
int V_35 ;
if ( ! V_180 )
V_180 ++ ;
V_35 = ( V_180 > V_5 -> V_30 - V_5 -> V_76 ) ? ( V_5 -> V_30 - V_5 -> V_76 ) : V_180 ;
F_15 ( ( unsigned short * ) V_5 -> V_75 , V_5 -> V_31 , 2 * V_35 ) ;
if ( F_22 ( V_5 ) )
V_5 -> V_15 -> V_181 ( V_5 , V_5 -> V_80 , V_5 -> V_76 , 1 , V_35 ) ;
V_5 -> V_77 = 0 ;
}
static void F_87 ( struct V_4 * V_5 )
{
V_5 -> V_59 = 1 ;
V_5 -> V_64 = 0 ;
V_5 -> V_61 = 0 ;
V_5 -> V_62 = 0 ;
V_5 -> V_60 = 0 ;
V_5 -> V_58 = V_5 -> V_182 ;
}
static void F_88 ( struct V_4 * V_5 )
{
int V_81 ;
for ( V_81 = 0 ; V_81 <= V_5 -> V_183 ; V_81 ++ )
switch ( V_5 -> V_184 [ V_81 ] ) {
case 0 :
F_87 ( V_5 ) ;
break;
case 1 :
V_5 -> V_59 = 2 ;
break;
case 2 :
V_5 -> V_59 = 0 ;
break;
case 3 :
V_5 -> V_64 = 1 ;
break;
case 4 :
V_5 -> V_61 = 1 ;
break;
case 5 :
V_5 -> V_60 = 1 ;
break;
case 7 :
V_5 -> V_62 = 1 ;
break;
case 10 :
V_5 -> V_185 = F_89 ( V_5 -> V_186 == 0
? V_5 -> V_187
: V_5 -> V_188 , V_5 ) ;
V_5 -> V_189 = 0 ;
V_5 -> V_190 = 0 ;
break;
case 11 :
V_5 -> V_185 = F_89 ( V_191 , V_5 ) ;
V_5 -> V_189 = 1 ;
V_5 -> V_190 = 0 ;
break;
case 12 :
V_5 -> V_185 = F_89 ( V_191 , V_5 ) ;
V_5 -> V_189 = 1 ;
V_5 -> V_190 = 1 ;
break;
case 21 :
case 22 :
V_5 -> V_59 = 1 ;
break;
case 23 :
V_5 -> V_64 = 0 ;
break;
case 24 :
V_5 -> V_61 = 0 ;
break;
case 25 :
V_5 -> V_60 = 0 ;
break;
case 27 :
V_5 -> V_62 = 0 ;
break;
case 38 :
V_5 -> V_58 = ( V_5 -> V_182 & 0x0f ) | ( V_5 -> V_58 & 0xf0 ) ;
V_5 -> V_61 = 1 ;
break;
case 39 :
V_5 -> V_58 = ( V_5 -> V_182 & 0x0f ) | ( V_5 -> V_58 & 0xf0 ) ;
V_5 -> V_61 = 0 ;
break;
case 49 :
V_5 -> V_58 = ( V_5 -> V_182 & 0xf0 ) | ( V_5 -> V_58 & 0x0f ) ;
break;
default:
if ( V_5 -> V_184 [ V_81 ] >= 30 && V_5 -> V_184 [ V_81 ] <= 37 )
V_5 -> V_58 = V_192 [ V_5 -> V_184 [ V_81 ] - 30 ]
| ( V_5 -> V_58 & 0xf0 ) ;
else if ( V_5 -> V_184 [ V_81 ] >= 40 && V_5 -> V_184 [ V_81 ] <= 47 )
V_5 -> V_58 = ( V_192 [ V_5 -> V_184 [ V_81 ] - 40 ] << 4 )
| ( V_5 -> V_58 & 0x0f ) ;
break;
}
F_26 ( V_5 ) ;
}
static void F_90 ( const char * V_13 , struct V_138 * V_139 )
{
while ( * V_13 ) {
F_91 ( V_139 , * V_13 , 0 ) ;
V_13 ++ ;
}
F_92 ( V_139 ) ;
}
static void F_93 ( struct V_4 * V_5 , struct V_138 * V_139 )
{
char V_193 [ 40 ] ;
sprintf ( V_193 , L_2 , V_5 -> V_80 + ( V_5 -> V_179 ? V_5 -> V_159 + 1 : 1 ) , V_5 -> V_76 + 1 ) ;
F_90 ( V_193 , V_139 ) ;
}
static inline void F_94 ( struct V_138 * V_139 )
{
F_90 ( L_3 , V_139 ) ;
}
static inline void F_95 ( struct V_138 * V_139 )
{
F_90 ( V_194 , V_139 ) ;
}
void F_96 ( struct V_138 * V_139 , int V_195 , int V_196 , int V_197 )
{
char V_193 [ 8 ] ;
sprintf ( V_193 , L_4 , ( char ) ( ' ' + V_195 ) , ( char ) ( '!' + V_196 ) ,
( char ) ( '!' + V_197 ) ) ;
F_90 ( V_193 , V_139 ) ;
}
int F_97 ( void )
{
return V_100 [ V_101 ] . V_24 -> V_198 ;
}
static void F_98 ( struct V_4 * V_5 , int V_199 )
{
int V_81 ;
for ( V_81 = 0 ; V_81 <= V_5 -> V_183 ; V_81 ++ )
if ( V_5 -> V_200 ) {
switch( V_5 -> V_184 [ V_81 ] ) {
case 1 :
if ( V_199 )
F_99 ( V_5 , V_201 ) ;
else
F_100 ( V_5 , V_201 ) ;
break;
case 3 :
V_5 -> V_202 = V_199 ;
#if 0
vc_resize(deccolm ? 132 : 80, vc->vc_rows);
#endif
break;
case 5 :
if ( V_5 -> V_63 != V_199 ) {
V_5 -> V_63 = V_199 ;
F_27 ( V_5 , 0 , V_5 -> V_71 , 0 ) ;
F_26 ( V_5 ) ;
}
break;
case 6 :
V_5 -> V_179 = V_199 ;
F_76 ( V_5 , 0 , 0 ) ;
break;
case 7 :
V_5 -> V_203 = V_199 ;
break;
case 8 :
if ( V_199 )
F_99 ( V_5 , V_204 ) ;
else
F_100 ( V_5 , V_204 ) ;
break;
case 9 :
V_5 -> V_198 = V_199 ? 1 : 0 ;
break;
case 25 :
V_5 -> V_90 = V_199 ;
break;
case 1000 :
V_5 -> V_198 = V_199 ? 2 : 0 ;
break;
}
} else {
switch( V_5 -> V_184 [ V_81 ] ) {
case 3 :
V_5 -> V_189 = V_199 ;
break;
case 4 :
V_5 -> V_205 = V_199 ;
break;
case 20 :
if ( V_199 )
F_99 ( V_5 , V_206 ) ;
else
F_100 ( V_5 , V_206 ) ;
break;
}
}
}
static void F_101 ( struct V_4 * V_5 )
{
switch( V_5 -> V_184 [ 0 ] ) {
case 1 :
if ( V_5 -> V_53 &&
V_5 -> V_184 [ 1 ] < 16 ) {
V_5 -> V_55 = V_192 [ V_5 -> V_184 [ 1 ] ] ;
if ( V_5 -> V_61 )
F_26 ( V_5 ) ;
}
break;
case 2 :
if ( V_5 -> V_53 &&
V_5 -> V_184 [ 1 ] < 16 ) {
V_5 -> V_207 = V_192 [ V_5 -> V_184 [ 1 ] ] ;
if ( V_5 -> V_59 == 0 )
F_26 ( V_5 ) ;
}
break;
case 8 :
V_5 -> V_182 = V_5 -> V_57 ;
if ( V_5 -> V_56 == 0x100 )
V_5 -> V_182 >>= 1 ;
F_87 ( V_5 ) ;
F_26 ( V_5 ) ;
break;
case 9 :
V_208 = ( ( V_5 -> V_184 [ 1 ] < 60 ) ? V_5 -> V_184 [ 1 ] : 60 ) * 60 ;
F_102 () ;
break;
case 10 :
if ( V_5 -> V_183 >= 1 )
V_5 -> V_209 = V_5 -> V_184 [ 1 ] ;
else
V_5 -> V_209 = V_210 ;
break;
case 11 :
if ( V_5 -> V_183 >= 1 )
V_5 -> V_211 = ( V_5 -> V_184 [ 1 ] < 2000 ) ?
V_5 -> V_184 [ 1 ] * V_212 / 1000 : 0 ;
else
V_5 -> V_211 = V_213 ;
break;
case 12 :
if ( V_5 -> V_184 [ 1 ] >= 1 && F_45 ( V_5 -> V_184 [ 1 ] - 1 ) )
F_103 ( V_5 -> V_184 [ 1 ] - 1 ) ;
break;
case 13 :
F_102 () ;
break;
case 14 :
V_214 = ( ( V_5 -> V_184 [ 1 ] < 60 ) ? V_5 -> V_184 [ 1 ] : 60 ) * 60 * V_212 ;
break;
case 15 :
F_103 ( V_215 ) ;
break;
}
}
static void F_104 ( struct V_4 * V_5 , unsigned int V_23 )
{
if ( V_23 > V_5 -> V_30 - V_5 -> V_76 )
V_23 = V_5 -> V_30 - V_5 -> V_76 ;
else if ( ! V_23 )
V_23 = 1 ;
F_30 ( V_5 , V_23 ) ;
}
static void F_105 ( struct V_4 * V_5 , unsigned int V_23 )
{
if ( V_23 > V_5 -> V_26 - V_5 -> V_80 )
V_23 = V_5 -> V_26 - V_5 -> V_80 ;
else if ( ! V_23 )
V_23 = 1 ;
F_16 ( V_5 , V_5 -> V_80 , V_5 -> V_160 , V_23 ) ;
V_5 -> V_77 = 0 ;
}
static void F_106 ( struct V_4 * V_5 , unsigned int V_23 )
{
if ( V_23 > V_5 -> V_30 - V_5 -> V_76 )
V_23 = V_5 -> V_30 - V_5 -> V_76 ;
else if ( ! V_23 )
V_23 = 1 ;
F_31 ( V_5 , V_23 ) ;
}
static void F_107 ( struct V_4 * V_5 , unsigned int V_23 )
{
if ( V_23 > V_5 -> V_26 - V_5 -> V_80 )
V_23 = V_5 -> V_26 - V_5 -> V_80 ;
else if ( ! V_23 )
V_23 = 1 ;
F_12 ( V_5 , V_5 -> V_80 , V_5 -> V_160 , V_23 ) ;
V_5 -> V_77 = 0 ;
}
static void F_65 ( struct V_4 * V_5 )
{
V_5 -> V_216 = V_5 -> V_76 ;
V_5 -> V_217 = V_5 -> V_80 ;
V_5 -> V_218 = V_5 -> V_59 ;
V_5 -> V_219 = V_5 -> V_64 ;
V_5 -> V_220 = V_5 -> V_61 ;
V_5 -> V_221 = V_5 -> V_60 ;
V_5 -> V_222 = V_5 -> V_62 ;
V_5 -> V_223 = V_5 -> V_186 ;
V_5 -> V_224 = V_5 -> V_58 ;
V_5 -> V_225 = V_5 -> V_187 ;
V_5 -> V_226 = V_5 -> V_188 ;
}
static void F_108 ( struct V_4 * V_5 )
{
F_64 ( V_5 , V_5 -> V_216 , V_5 -> V_217 ) ;
V_5 -> V_59 = V_5 -> V_218 ;
V_5 -> V_64 = V_5 -> V_219 ;
V_5 -> V_61 = V_5 -> V_220 ;
V_5 -> V_60 = V_5 -> V_221 ;
V_5 -> V_62 = V_5 -> V_222 ;
V_5 -> V_186 = V_5 -> V_223 ;
V_5 -> V_58 = V_5 -> V_224 ;
V_5 -> V_187 = V_5 -> V_225 ;
V_5 -> V_188 = V_5 -> V_226 ;
V_5 -> V_185 = F_89 ( V_5 -> V_186 ? V_5 -> V_188 : V_5 -> V_187 , V_5 ) ;
F_26 ( V_5 ) ;
V_5 -> V_77 = 0 ;
}
static void F_109 ( struct V_4 * V_5 , int V_227 )
{
V_5 -> V_159 = 0 ;
V_5 -> V_160 = V_5 -> V_26 ;
V_5 -> V_228 = V_229 ;
V_5 -> V_200 = 0 ;
V_5 -> V_185 = F_89 ( V_230 , V_5 ) ;
V_5 -> V_187 = V_230 ;
V_5 -> V_188 = V_231 ;
V_5 -> V_186 = 0 ;
V_5 -> V_77 = 0 ;
V_5 -> V_198 = 0 ;
V_5 -> V_232 = V_233 ;
V_5 -> V_234 = 0 ;
V_5 -> V_189 = 0 ;
V_5 -> V_190 = 0 ;
V_5 -> V_63 = 0 ;
V_5 -> V_179 = 0 ;
V_5 -> V_203 = 1 ;
V_5 -> V_90 = V_131 ;
V_5 -> V_205 = 0 ;
F_99 ( V_5 , V_204 ) ;
F_100 ( V_5 , V_201 ) ;
F_100 ( V_5 , V_235 ) ;
F_100 ( V_5 , V_206 ) ;
V_236 [ V_5 -> V_103 ] . V_237 = 0 ;
V_236 [ V_5 -> V_103 ] . V_238 = 0 ;
V_236 [ V_5 -> V_103 ] . V_239 = V_240 ;
V_236 [ V_5 -> V_103 ] . V_241 = V_236 [ V_5 -> V_103 ] . V_242 ;
V_5 -> V_82 = V_243 ;
V_5 -> V_74 = V_5 -> V_120 ;
F_87 ( V_5 ) ;
F_26 ( V_5 ) ;
V_5 -> V_244 [ 0 ] = 0x01010100 ;
V_5 -> V_244 [ 1 ] =
V_5 -> V_244 [ 2 ] =
V_5 -> V_244 [ 3 ] =
V_5 -> V_244 [ 4 ] =
V_5 -> V_244 [ 5 ] =
V_5 -> V_244 [ 6 ] =
V_5 -> V_244 [ 7 ] = 0x01010101 ;
V_5 -> V_209 = V_210 ;
V_5 -> V_211 = V_213 ;
F_64 ( V_5 , 0 , 0 ) ;
F_65 ( V_5 ) ;
if ( V_227 )
F_84 ( V_5 , 2 ) ;
}
static void F_110 ( struct V_138 * V_139 , struct V_4 * V_5 , int V_245 )
{
switch ( V_245 ) {
case 0 :
return;
case 7 :
if ( V_5 -> V_211 )
F_111 ( V_5 -> V_209 , V_5 -> V_211 ) ;
return;
case 8 :
F_82 ( V_5 ) ;
return;
case 9 :
V_5 -> V_75 -= ( V_5 -> V_76 << 1 ) ;
while ( V_5 -> V_76 < V_5 -> V_30 - 1 ) {
V_5 -> V_76 ++ ;
if ( V_5 -> V_244 [ V_5 -> V_76 >> 5 ] & ( 1 << ( V_5 -> V_76 & 31 ) ) )
break;
}
V_5 -> V_75 += ( V_5 -> V_76 << 1 ) ;
F_5 ( V_5 , '\t' ) ;
return;
case 10 : case 11 : case 12 :
F_79 ( V_5 ) ;
if ( ! F_112 ( V_5 , V_206 ) )
return;
case 13 :
F_81 ( V_5 ) ;
return;
case 14 :
V_5 -> V_186 = 1 ;
V_5 -> V_185 = F_89 ( V_5 -> V_188 , V_5 ) ;
V_5 -> V_189 = 1 ;
return;
case 15 :
V_5 -> V_186 = 0 ;
V_5 -> V_185 = F_89 ( V_5 -> V_187 , V_5 ) ;
V_5 -> V_189 = 0 ;
return;
case 24 : case 26 :
V_5 -> V_228 = V_229 ;
return;
case 27 :
V_5 -> V_228 = V_246 ;
return;
case 127 :
F_83 ( V_5 ) ;
return;
case 128 + 27 :
V_5 -> V_228 = V_247 ;
return;
}
switch( V_5 -> V_228 ) {
case V_246 :
V_5 -> V_228 = V_229 ;
switch ( V_245 ) {
case '[' :
V_5 -> V_228 = V_247 ;
return;
case ']' :
V_5 -> V_228 = V_248 ;
return;
case '%' :
V_5 -> V_228 = V_249 ;
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
V_5 -> V_244 [ V_5 -> V_76 >> 5 ] |= ( 1 << ( V_5 -> V_76 & 31 ) ) ;
return;
case 'Z' :
F_95 ( V_139 ) ;
return;
case '7' :
F_65 ( V_5 ) ;
return;
case '8' :
F_108 ( V_5 ) ;
return;
case '(' :
V_5 -> V_228 = V_250 ;
return;
case ')' :
V_5 -> V_228 = V_251 ;
return;
case '#' :
V_5 -> V_228 = V_252 ;
return;
case 'c' :
F_109 ( V_5 , 1 ) ;
return;
case '>' :
F_100 ( V_5 , V_235 ) ;
return;
case '=' :
F_99 ( V_5 , V_235 ) ;
return;
}
return;
case V_248 :
if ( V_245 == 'P' ) {
for ( V_5 -> V_183 = 0 ; V_5 -> V_183 < V_253 ; V_5 -> V_183 ++ )
V_5 -> V_184 [ V_5 -> V_183 ] = 0 ;
V_5 -> V_183 = 0 ;
V_5 -> V_228 = V_254 ;
return;
} else if ( V_245 == 'R' ) {
F_113 ( V_5 ) ;
V_5 -> V_228 = V_229 ;
} else
V_5 -> V_228 = V_229 ;
return;
case V_254 :
if ( isxdigit ( V_245 ) ) {
V_5 -> V_184 [ V_5 -> V_183 ++ ] = F_114 ( V_245 ) ;
if ( V_5 -> V_183 == 7 ) {
int V_81 = V_5 -> V_184 [ 0 ] * 3 , V_255 = 1 ;
V_5 -> V_256 [ V_81 ] = 16 * V_5 -> V_184 [ V_255 ++ ] ;
V_5 -> V_256 [ V_81 ++ ] += V_5 -> V_184 [ V_255 ++ ] ;
V_5 -> V_256 [ V_81 ] = 16 * V_5 -> V_184 [ V_255 ++ ] ;
V_5 -> V_256 [ V_81 ++ ] += V_5 -> V_184 [ V_255 ++ ] ;
V_5 -> V_256 [ V_81 ] = 16 * V_5 -> V_184 [ V_255 ++ ] ;
V_5 -> V_256 [ V_81 ] += V_5 -> V_184 [ V_255 ] ;
F_41 ( V_5 ) ;
V_5 -> V_228 = V_229 ;
}
} else
V_5 -> V_228 = V_229 ;
return;
case V_247 :
for ( V_5 -> V_183 = 0 ; V_5 -> V_183 < V_253 ; V_5 -> V_183 ++ )
V_5 -> V_184 [ V_5 -> V_183 ] = 0 ;
V_5 -> V_183 = 0 ;
V_5 -> V_228 = V_257 ;
if ( V_245 == '[' ) {
V_5 -> V_228 = V_258 ;
return;
}
V_5 -> V_200 = ( V_245 == '?' ) ;
if ( V_5 -> V_200 )
return;
case V_257 :
if ( V_245 == ';' && V_5 -> V_183 < V_253 - 1 ) {
V_5 -> V_183 ++ ;
return;
} else if ( V_245 >= '0' && V_245 <= '9' ) {
V_5 -> V_184 [ V_5 -> V_183 ] *= 10 ;
V_5 -> V_184 [ V_5 -> V_183 ] += V_245 - '0' ;
return;
} else
V_5 -> V_228 = V_259 ;
case V_259 :
V_5 -> V_228 = V_229 ;
switch( V_245 ) {
case 'h' :
F_98 ( V_5 , 1 ) ;
return;
case 'l' :
F_98 ( V_5 , 0 ) ;
return;
case 'c' :
if ( V_5 -> V_200 ) {
if ( V_5 -> V_184 [ 0 ] )
V_5 -> V_82 = V_5 -> V_184 [ 0 ] | ( V_5 -> V_184 [ 1 ] << 8 ) | ( V_5 -> V_184 [ 2 ] << 16 ) ;
else
V_5 -> V_82 = V_243 ;
return;
}
break;
case 'm' :
if ( V_5 -> V_200 ) {
F_34 () ;
if ( V_5 -> V_184 [ 0 ] )
V_5 -> V_74 = V_5 -> V_184 [ 0 ] << 8 | V_5 -> V_184 [ 1 ] ;
else
V_5 -> V_74 = V_5 -> V_120 ;
return;
}
break;
case 'n' :
if ( ! V_5 -> V_200 ) {
if ( V_5 -> V_184 [ 0 ] == 5 )
F_94 ( V_139 ) ;
else if ( V_5 -> V_184 [ 0 ] == 6 )
F_93 ( V_5 , V_139 ) ;
}
return;
}
if ( V_5 -> V_200 ) {
V_5 -> V_200 = 0 ;
return;
}
switch( V_245 ) {
case 'G' : case '`' :
if ( V_5 -> V_184 [ 0 ] )
V_5 -> V_184 [ 0 ] -- ;
F_64 ( V_5 , V_5 -> V_184 [ 0 ] , V_5 -> V_80 ) ;
return;
case 'A' :
if ( ! V_5 -> V_184 [ 0 ] )
V_5 -> V_184 [ 0 ] ++ ;
F_64 ( V_5 , V_5 -> V_76 , V_5 -> V_80 - V_5 -> V_184 [ 0 ] ) ;
return;
case 'B' : case 'e' :
if ( ! V_5 -> V_184 [ 0 ] )
V_5 -> V_184 [ 0 ] ++ ;
F_64 ( V_5 , V_5 -> V_76 , V_5 -> V_80 + V_5 -> V_184 [ 0 ] ) ;
return;
case 'C' : case 'a' :
if ( ! V_5 -> V_184 [ 0 ] )
V_5 -> V_184 [ 0 ] ++ ;
F_64 ( V_5 , V_5 -> V_76 + V_5 -> V_184 [ 0 ] , V_5 -> V_80 ) ;
return;
case 'D' :
if ( ! V_5 -> V_184 [ 0 ] )
V_5 -> V_184 [ 0 ] ++ ;
F_64 ( V_5 , V_5 -> V_76 - V_5 -> V_184 [ 0 ] , V_5 -> V_80 ) ;
return;
case 'E' :
if ( ! V_5 -> V_184 [ 0 ] )
V_5 -> V_184 [ 0 ] ++ ;
F_64 ( V_5 , 0 , V_5 -> V_80 + V_5 -> V_184 [ 0 ] ) ;
return;
case 'F' :
if ( ! V_5 -> V_184 [ 0 ] )
V_5 -> V_184 [ 0 ] ++ ;
F_64 ( V_5 , 0 , V_5 -> V_80 - V_5 -> V_184 [ 0 ] ) ;
return;
case 'd' :
if ( V_5 -> V_184 [ 0 ] )
V_5 -> V_184 [ 0 ] -- ;
F_76 ( V_5 , V_5 -> V_76 , V_5 -> V_184 [ 0 ] ) ;
return;
case 'H' : case 'f' :
if ( V_5 -> V_184 [ 0 ] )
V_5 -> V_184 [ 0 ] -- ;
if ( V_5 -> V_184 [ 1 ] )
V_5 -> V_184 [ 1 ] -- ;
F_76 ( V_5 , V_5 -> V_184 [ 1 ] , V_5 -> V_184 [ 0 ] ) ;
return;
case 'J' :
F_84 ( V_5 , V_5 -> V_184 [ 0 ] ) ;
return;
case 'K' :
F_85 ( V_5 , V_5 -> V_184 [ 0 ] ) ;
return;
case 'L' :
F_105 ( V_5 , V_5 -> V_184 [ 0 ] ) ;
return;
case 'M' :
F_107 ( V_5 , V_5 -> V_184 [ 0 ] ) ;
return;
case 'P' :
F_106 ( V_5 , V_5 -> V_184 [ 0 ] ) ;
return;
case 'c' :
if ( ! V_5 -> V_184 [ 0 ] )
F_95 ( V_139 ) ;
return;
case 'g' :
if ( ! V_5 -> V_184 [ 0 ] )
V_5 -> V_244 [ V_5 -> V_76 >> 5 ] &= ~ ( 1 << ( V_5 -> V_76 & 31 ) ) ;
else if ( V_5 -> V_184 [ 0 ] == 3 ) {
V_5 -> V_244 [ 0 ] =
V_5 -> V_244 [ 1 ] =
V_5 -> V_244 [ 2 ] =
V_5 -> V_244 [ 3 ] =
V_5 -> V_244 [ 4 ] =
V_5 -> V_244 [ 5 ] =
V_5 -> V_244 [ 6 ] =
V_5 -> V_244 [ 7 ] = 0 ;
}
return;
case 'm' :
F_88 ( V_5 ) ;
return;
case 'q' :
if ( V_5 -> V_184 [ 0 ] < 4 )
F_115 ( V_236 + V_5 -> V_103 ,
( V_5 -> V_184 [ 0 ] < 3 ) ? V_5 -> V_184 [ 0 ] : 4 ) ;
return;
case 'r' :
if ( ! V_5 -> V_184 [ 0 ] )
V_5 -> V_184 [ 0 ] ++ ;
if ( ! V_5 -> V_184 [ 1 ] )
V_5 -> V_184 [ 1 ] = V_5 -> V_26 ;
if ( V_5 -> V_184 [ 0 ] < V_5 -> V_184 [ 1 ] &&
V_5 -> V_184 [ 1 ] <= V_5 -> V_26 ) {
V_5 -> V_159 = V_5 -> V_184 [ 0 ] - 1 ;
V_5 -> V_160 = V_5 -> V_184 [ 1 ] ;
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
F_86 ( V_5 , V_5 -> V_184 [ 0 ] ) ;
return;
case '@' :
F_104 ( V_5 , V_5 -> V_184 [ 0 ] ) ;
return;
case ']' :
F_101 ( V_5 ) ;
return;
}
return;
case V_249 :
V_5 -> V_228 = V_229 ;
switch ( V_245 ) {
case '@' :
V_5 -> V_232 = 0 ;
return;
case 'G' :
case '8' :
V_5 -> V_232 = 1 ;
return;
}
return;
case V_258 :
V_5 -> V_228 = V_229 ;
return;
case V_252 :
V_5 -> V_228 = V_229 ;
if ( V_245 == '8' ) {
V_5 -> V_31 =
( V_5 -> V_31 & 0xff00 ) | 'E' ;
F_84 ( V_5 , 2 ) ;
V_5 -> V_31 =
( V_5 -> V_31 & 0xff00 ) | ' ' ;
F_17 ( V_5 , V_5 -> V_14 , V_5 -> V_71 / 2 ) ;
}
return;
case V_250 :
if ( V_245 == '0' )
V_5 -> V_187 = V_231 ;
else if ( V_245 == 'B' )
V_5 -> V_187 = V_230 ;
else if ( V_245 == 'U' )
V_5 -> V_187 = V_191 ;
else if ( V_245 == 'K' )
V_5 -> V_187 = V_260 ;
if ( V_5 -> V_186 == 0 )
V_5 -> V_185 = F_89 ( V_5 -> V_187 , V_5 ) ;
V_5 -> V_228 = V_229 ;
return;
case V_251 :
if ( V_245 == '0' )
V_5 -> V_188 = V_231 ;
else if ( V_245 == 'B' )
V_5 -> V_188 = V_230 ;
else if ( V_245 == 'U' )
V_5 -> V_188 = V_191 ;
else if ( V_245 == 'K' )
V_5 -> V_188 = V_260 ;
if ( V_5 -> V_186 == 1 )
V_5 -> V_185 = F_89 ( V_5 -> V_188 , V_5 ) ;
V_5 -> V_228 = V_229 ;
return;
default:
V_5 -> V_228 = V_229 ;
}
}
static int F_116 ( T_4 V_261 , const struct V_262 * V_263 , int V_264 )
{
int F_62 = 0 ;
int V_265 ;
if ( V_261 < V_263 [ 0 ] . V_266 || V_261 > V_263 [ V_264 ] . V_267 )
return 0 ;
while ( V_264 >= F_62 ) {
V_265 = ( F_62 + V_264 ) / 2 ;
if ( V_261 > V_263 [ V_265 ] . V_267 )
F_62 = V_265 + 1 ;
else if ( V_261 < V_263 [ V_265 ] . V_266 )
V_264 = V_265 - 1 ;
else
return 1 ;
}
return 0 ;
}
static int F_117 ( T_4 V_261 )
{
static const struct V_262 V_268 [] = {
{ 0x1100 , 0x115F } , { 0x2329 , 0x232A } , { 0x2E80 , 0x303E } ,
{ 0x3040 , 0xA4CF } , { 0xAC00 , 0xD7A3 } , { 0xF900 , 0xFAFF } ,
{ 0xFE10 , 0xFE19 } , { 0xFE30 , 0xFE6F } , { 0xFF00 , 0xFF60 } ,
{ 0xFFE0 , 0xFFE6 } , { 0x20000 , 0x2FFFD } , { 0x30000 , 0x3FFFD }
} ;
return F_116 ( V_261 , V_268 , F_118 ( V_268 ) - 1 ) ;
}
static int F_119 ( struct V_138 * V_139 , const unsigned char * V_193 , int V_35 )
{
#ifdef F_18
#define F_120 do { } while(0);
#else
#define F_120 if (draw_x >= 0) { \
vc->vc_sw->con_putcs(vc, (u16 *)draw_from, (u16 *)draw_to - (u16 *)draw_from, vc->vc_y, draw_x); \
draw_x = -1; \
}
#endif
int V_245 , V_269 , V_270 , V_271 = 0 , V_272 = - 1 ;
unsigned int V_121 ;
unsigned long V_273 = 0 , V_274 = 0 ;
struct V_4 * V_5 ;
unsigned char V_57 ;
struct V_7 V_8 ;
T_5 V_275 ;
T_5 V_276 ;
T_5 V_133 ;
T_1 V_277 , V_278 ;
if ( F_121 () )
return V_35 ;
F_122 () ;
F_71 () ;
V_5 = V_139 -> V_169 ;
if ( V_5 == NULL ) {
F_123 ( V_279 L_5 ) ;
F_72 () ;
return 0 ;
}
V_121 = V_5 -> V_103 ;
if ( ! F_45 ( V_121 ) ) {
F_124 ( L_6 , V_121 + 1 ) ;
F_72 () ;
return 0 ;
}
V_277 = V_5 -> V_56 ;
V_278 = V_277 ? 0x1ff : 0xff ;
if ( F_35 ( V_5 ) )
F_23 ( V_5 ) ;
V_8 . V_5 = V_5 ;
while ( ! V_139 -> V_280 && V_35 ) {
int V_281 = * V_193 ;
V_245 = V_281 ;
V_193 ++ ;
V_271 ++ ;
V_35 -- ;
V_275 = 0 ;
V_276 = 0 ;
V_133 = 1 ;
if ( V_5 -> V_228 != V_229 ) {
V_269 = V_245 ;
} else if ( V_5 -> V_232 && ! V_5 -> V_189 ) {
V_282:
if ( ( V_245 & 0xc0 ) == 0x80 ) {
static const T_4 V_283 [] = { 0x0000007f , 0x000007ff , 0x0000ffff , 0x001fffff , 0x03ffffff , 0x7fffffff } ;
if ( V_5 -> V_234 ) {
V_5 -> V_284 = ( V_5 -> V_284 << 6 ) | ( V_245 & 0x3f ) ;
V_5 -> V_183 ++ ;
if ( -- V_5 -> V_234 ) {
continue;
}
V_245 = V_5 -> V_284 ;
if ( V_245 <= V_283 [ V_5 -> V_183 - 1 ] ||
V_245 > V_283 [ V_5 -> V_183 ] )
V_245 = 0xfffd ;
} else {
V_5 -> V_234 = 0 ;
V_245 = 0xfffd ;
}
} else {
if ( V_5 -> V_234 ) {
V_275 = 1 ;
V_5 -> V_234 = 0 ;
V_245 = 0xfffd ;
} else if ( V_245 > 0x7f ) {
V_5 -> V_183 = 0 ;
if ( ( V_245 & 0xe0 ) == 0xc0 ) {
V_5 -> V_234 = 1 ;
V_5 -> V_284 = ( V_245 & 0x1f ) ;
} else if ( ( V_245 & 0xf0 ) == 0xe0 ) {
V_5 -> V_234 = 2 ;
V_5 -> V_284 = ( V_245 & 0x0f ) ;
} else if ( ( V_245 & 0xf8 ) == 0xf0 ) {
V_5 -> V_234 = 3 ;
V_5 -> V_284 = ( V_245 & 0x07 ) ;
} else if ( ( V_245 & 0xfc ) == 0xf8 ) {
V_5 -> V_234 = 4 ;
V_5 -> V_284 = ( V_245 & 0x03 ) ;
} else if ( ( V_245 & 0xfe ) == 0xfc ) {
V_5 -> V_234 = 5 ;
V_5 -> V_284 = ( V_245 & 0x01 ) ;
} else {
V_245 = 0xfffd ;
}
if ( V_5 -> V_234 ) {
continue;
}
}
}
if ( ( V_245 >= 0xd800 && V_245 <= 0xdfff ) || V_245 == 0xfffe || V_245 == 0xffff )
V_245 = 0xfffd ;
V_269 = V_245 ;
} else {
V_269 = V_185 ( V_5 , V_245 ) ;
}
V_8 . V_245 = V_269 ;
if ( F_6 ( & V_3 , V_285 ,
& V_8 ) == V_286 )
continue;
V_270 = V_269 && ( V_245 >= 32 ||
! ( V_5 -> V_189 ? ( V_287 >> V_245 ) & 1 :
V_5 -> V_232 || ( ( V_288 >> V_245 ) & 1 ) ) )
&& ( V_245 != 127 || V_5 -> V_189 )
&& ( V_245 != 128 + 27 ) ;
if ( V_5 -> V_228 == V_229 && V_270 ) {
if ( V_5 -> V_232 && ! V_5 -> V_189 ) {
if ( F_117 ( V_245 ) )
V_133 = 2 ;
}
V_269 = F_125 ( V_5 , V_269 ) ;
if ( V_269 & ~ V_278 ) {
if ( V_269 == - 1 || V_269 == - 2 ) {
continue;
}
if ( ( ! ( V_5 -> V_232 && ! V_5 -> V_189 ) || V_245 < 128 ) && ! ( V_245 & ~ V_278 ) ) {
V_269 = V_245 ;
} else {
V_269 = F_125 ( V_5 , 0xfffd ) ;
if ( V_269 < 0 ) {
V_276 = 1 ;
V_269 = F_125 ( V_5 , '?' ) ;
if ( V_269 < 0 ) V_269 = '?' ;
}
}
}
if ( ! V_276 ) {
V_57 = V_5 -> V_57 ;
} else {
if ( ! V_5 -> V_53 ) {
V_57 = ( V_5 -> V_57 ) ^ 0x08 ;
} else if ( V_5 -> V_56 == 0x100 ) {
V_57 = ( ( V_5 -> V_57 ) & 0x11 ) | ( ( ( V_5 -> V_57 ) & 0xe0 ) >> 4 ) | ( ( ( V_5 -> V_57 ) & 0x0e ) << 4 ) ;
} else {
V_57 = ( ( V_5 -> V_57 ) & 0x88 ) | ( ( ( V_5 -> V_57 ) & 0x70 ) >> 4 ) | ( ( ( V_5 -> V_57 ) & 0x07 ) << 4 ) ;
}
F_120
}
while ( 1 ) {
if ( V_5 -> V_77 || V_5 -> V_205 )
F_120
if ( V_5 -> V_77 ) {
F_81 ( V_5 ) ;
F_79 ( V_5 ) ;
}
if ( V_5 -> V_205 )
F_30 ( V_5 , 1 ) ;
F_28 ( V_277 ?
( ( V_57 << 8 ) & ~ V_277 ) + ( ( V_269 & 0x100 ) ? V_277 : 0 ) + ( V_269 & 0xff ) :
( V_57 << 8 ) + V_269 ,
( T_1 * ) V_5 -> V_75 ) ;
if ( F_22 ( V_5 ) && V_272 < 0 ) {
V_272 = V_5 -> V_76 ;
V_273 = V_5 -> V_75 ;
}
if ( V_5 -> V_76 == V_5 -> V_30 - 1 ) {
V_5 -> V_77 = V_5 -> V_203 ;
V_274 = V_5 -> V_75 + 2 ;
} else {
V_5 -> V_76 ++ ;
V_274 = ( V_5 -> V_75 += 2 ) ;
}
if ( ! -- V_133 ) break;
V_269 = F_125 ( V_5 , ' ' ) ;
if ( V_269 < 0 ) V_269 = ' ' ;
}
F_5 ( V_5 , V_245 ) ;
if ( V_276 ) {
F_120
}
if ( V_275 ) {
V_275 = 0 ;
V_276 = 0 ;
V_133 = 1 ;
V_245 = V_281 ;
goto V_282;
}
continue;
}
F_120
F_110 ( V_139 , V_5 , V_281 ) ;
}
F_120
F_126 ();
F_72 () ;
F_7 ( V_5 ) ;
return V_271 ;
#undef F_120
}
static void F_127 ( struct V_289 * V_290 )
{
F_71 () ;
if ( V_291 >= 0 ) {
if ( V_291 != V_101 &&
F_45 ( V_291 ) ) {
F_23 ( V_100 [ V_101 ] . V_24 ) ;
F_128 ( V_100 [ V_291 ] . V_24 ) ;
}
V_291 = - 1 ;
}
if ( V_292 ) {
V_292 = 0 ;
F_102 () ;
}
if ( V_19 ) {
struct V_4 * V_5 = V_100 [ V_101 ] . V_24 ;
F_34 () ;
if ( V_5 -> V_88 == V_293 )
V_5 -> V_15 -> V_294 ( V_5 , V_19 ) ;
V_19 = 0 ;
}
if ( V_295 ) {
F_129 ( 0 ) ;
V_295 = 0 ;
}
F_7 ( V_100 [ V_101 ] . V_24 ) ;
F_72 () ;
}
int F_103 ( int V_23 )
{
struct V_4 * V_5 = V_100 [ V_101 ] . V_24 ;
if ( ! F_45 ( V_23 ) || V_296 ||
( V_5 -> V_297 . V_298 == V_299 && V_5 -> V_88 == V_89 ) ) {
return - V_157 ;
}
V_291 = V_23 ;
F_10 () ;
return 0 ;
}
int F_130 ( int V_73 )
{
static int V_300 ;
if ( V_73 != - 1 )
return F_131 ( & V_300 , V_73 ) ;
else
return V_300 ;
}
static void F_132 ( struct V_301 * V_302 , const char * V_22 , unsigned V_35 )
{
struct V_4 * V_5 = V_100 [ V_101 ] . V_24 ;
unsigned char V_245 ;
static F_133 ( V_303 ) ;
const T_6 * V_34 ;
T_6 V_66 = 0 ;
T_6 V_304 ;
int V_305 ;
if ( ! V_306 )
return;
if ( ! F_134 ( & V_303 ) )
return;
V_305 = F_135 () ;
if ( V_305 && F_45 ( V_305 - 1 ) )
V_5 = V_100 [ V_305 - 1 ] . V_24 ;
V_304 = V_5 -> V_76 ;
if ( ! F_45 ( V_101 ) ) {
goto V_307;
}
if ( V_5 -> V_88 != V_293 && ! F_42 ( V_5 ) )
goto V_307;
if ( F_35 ( V_5 ) )
F_23 ( V_5 ) ;
V_34 = ( T_6 * ) V_5 -> V_75 ;
while ( V_35 -- ) {
V_245 = * V_22 ++ ;
if ( V_245 == 10 || V_245 == 13 || V_245 == 8 || V_5 -> V_77 ) {
if ( V_66 > 0 ) {
if ( F_13 ( V_5 ) )
V_5 -> V_15 -> V_44 ( V_5 , V_34 , V_66 , V_5 -> V_80 , V_5 -> V_76 ) ;
V_5 -> V_76 += V_66 ;
if ( V_5 -> V_77 )
V_5 -> V_76 -- ;
V_66 = 0 ;
}
if ( V_245 == 8 ) {
F_82 ( V_5 ) ;
V_34 = ( T_6 * ) V_5 -> V_75 ;
V_304 = V_5 -> V_76 ;
continue;
}
if ( V_245 != 13 )
F_79 ( V_5 ) ;
F_81 ( V_5 ) ;
V_34 = ( T_6 * ) V_5 -> V_75 ;
V_304 = V_5 -> V_76 ;
if ( V_245 == 10 || V_245 == 13 )
continue;
}
F_28 ( ( V_5 -> V_57 << 8 ) + V_245 , ( unsigned short * ) V_5 -> V_75 ) ;
F_5 ( V_5 , V_245 ) ;
V_66 ++ ;
if ( V_304 == V_5 -> V_30 - 1 ) {
V_5 -> V_77 = 1 ;
continue;
}
V_5 -> V_75 += 2 ;
V_304 ++ ;
}
if ( V_66 > 0 ) {
if ( F_13 ( V_5 ) )
V_5 -> V_15 -> V_44 ( V_5 , V_34 , V_66 , V_5 -> V_80 , V_5 -> V_76 ) ;
V_5 -> V_76 += V_66 ;
if ( V_5 -> V_76 == V_5 -> V_30 ) {
V_5 -> V_76 -- ;
V_5 -> V_77 = 1 ;
}
}
F_24 ( V_5 ) ;
F_7 ( V_5 ) ;
V_307:
F_136 ( & V_303 ) ;
}
static struct V_308 * F_137 ( struct V_301 * V_245 , int * V_309 )
{
* V_309 = V_245 -> V_309 ? V_245 -> V_309 - 1 : V_101 ;
return V_310 ;
}
int F_138 ( struct V_138 * V_139 , unsigned long V_311 )
{
char type , V_312 ;
char T_7 * V_13 = ( char T_7 * ) V_311 ;
int V_18 ;
int V_170 ;
if ( V_313 -> signal -> V_139 != V_139 && ! F_51 ( V_314 ) )
return - V_125 ;
if ( F_139 ( type , V_13 ) )
return - V_315 ;
V_170 = 0 ;
switch ( type )
{
case V_316 :
F_71 () ;
V_170 = F_140 ( (struct V_317 T_7 * ) ( V_13 + 1 ) , V_139 ) ;
F_72 () ;
break;
case V_318 :
V_170 = F_141 ( V_139 ) ;
break;
case V_319 :
F_71 () ;
F_142 () ;
F_72 () ;
break;
case V_320 :
V_170 = F_143 ( V_13 ) ;
break;
case V_321 :
V_312 = V_322 ;
V_170 = F_144 ( V_312 , V_13 ) ;
break;
case V_323 :
V_312 = F_97 () ;
V_170 = F_144 ( V_312 , V_13 ) ;
break;
case V_324 :
V_170 = F_145 ( V_13 ) ;
break;
case V_325 :
V_312 = F_135 () ;
V_170 = F_144 ( V_312 , V_13 ) ;
break;
case V_326 :
if ( ! F_51 ( V_314 ) ) {
V_170 = - V_125 ;
} else {
if ( F_139 ( V_312 , V_13 + 1 ) )
V_170 = - V_315 ;
else
F_130 ( V_312 ) ;
}
break;
case V_327 :
V_170 = V_101 ;
break;
case V_328 :
if ( F_139 ( V_18 , ( V_329 T_7 * ) ( V_13 + 4 ) ) ) {
V_170 = - V_315 ;
} else {
F_78 ( V_100 [ V_101 ] . V_24 , V_18 ) ;
V_170 = 0 ;
}
break;
case V_330 :
F_71 () ;
V_331 = 1 ;
F_129 ( 0 ) ;
F_72 () ;
break;
case V_332 :
V_170 = V_87 ;
break;
default:
V_170 = - V_157 ;
break;
}
return V_170 ;
}
static int F_146 ( struct V_138 * V_139 , const unsigned char * V_193 , int V_35 )
{
int V_333 ;
V_333 = F_119 ( V_139 , V_193 , V_35 ) ;
F_147 ( V_139 ) ;
return V_333 ;
}
static int F_148 ( struct V_138 * V_139 , unsigned char V_334 )
{
if ( F_121 () )
return 0 ;
return F_119 ( V_139 , & V_334 , 1 ) ;
}
static int F_149 ( struct V_138 * V_139 )
{
if ( V_139 -> V_280 )
return 0 ;
return 32768 ;
}
static int F_150 ( struct V_138 * V_139 )
{
return 0 ;
}
static void F_151 ( struct V_138 * V_139 )
{
}
static void F_152 ( struct V_138 * V_139 )
{
struct V_4 * V_5 = V_139 -> V_169 ;
F_153 ( & V_5 -> V_335 ) ;
}
static void F_154 ( struct V_138 * V_139 )
{
int V_336 ;
if ( ! V_139 )
return;
V_336 = V_139 -> V_309 ;
if ( ! F_45 ( V_336 ) )
return;
F_155 ( V_236 + V_336 , V_337 ) ;
F_43 () ;
}
static void F_156 ( struct V_138 * V_139 )
{
int V_336 ;
if ( ! V_139 )
return;
V_336 = V_139 -> V_309 ;
if ( ! F_45 ( V_336 ) )
return;
F_157 ( V_236 + V_336 , V_337 ) ;
F_43 () ;
}
static void F_147 ( struct V_138 * V_139 )
{
struct V_4 * V_5 ;
if ( F_121 () )
return;
F_71 () ;
V_5 = V_139 -> V_169 ;
if ( V_5 )
F_24 ( V_5 ) ;
F_72 () ;
}
static int F_158 ( struct V_138 * V_139 , struct V_338 * V_339 )
{
unsigned int V_121 = V_139 -> V_309 ;
int V_170 = 0 ;
F_71 () ;
if ( V_139 -> V_169 == NULL ) {
V_170 = F_50 ( V_121 ) ;
if ( V_170 == 0 ) {
struct V_4 * V_5 = V_100 [ V_121 ] . V_24 ;
if ( V_5 -> V_128 . V_139 ) {
F_72 () ;
return - V_340 ;
}
V_139 -> V_169 = V_5 ;
V_5 -> V_128 . V_139 = V_139 ;
if ( ! V_139 -> V_161 . V_163 && ! V_139 -> V_161 . V_164 ) {
V_139 -> V_161 . V_163 = V_100 [ V_121 ] . V_24 -> V_26 ;
V_139 -> V_161 . V_164 = V_100 [ V_121 ] . V_24 -> V_30 ;
}
if ( V_5 -> V_232 )
V_139 -> V_341 -> V_342 |= V_343 ;
else
V_139 -> V_341 -> V_342 &= ~ V_343 ;
F_72 () ;
return V_170 ;
}
}
F_72 () ;
return V_170 ;
}
static void F_159 ( struct V_138 * V_139 , struct V_338 * V_339 )
{
}
static void F_160 ( struct V_138 * V_139 )
{
struct V_4 * V_5 = V_139 -> V_169 ;
F_161 ( V_5 == NULL ) ;
F_71 () ;
V_5 -> V_128 . V_139 = NULL ;
F_72 () ;
F_162 ( V_139 ) ;
}
static void F_58 ( struct V_4 * V_5 , unsigned int V_168 ,
unsigned int V_140 , int V_227 )
{
int V_255 , V_344 ;
V_5 -> V_30 = V_140 ;
V_5 -> V_26 = V_168 ;
V_5 -> V_29 = V_140 << 1 ;
V_5 -> V_71 = V_5 -> V_26 * V_5 -> V_29 ;
F_36 ( V_5 ) ;
V_5 -> V_75 = V_5 -> V_14 ;
F_163 ( V_5 ) ;
for ( V_255 = V_344 = 0 ; V_255 < 16 ; V_255 ++ ) {
V_5 -> V_256 [ V_344 ++ ] = V_345 [ V_255 ] ;
V_5 -> V_256 [ V_344 ++ ] = V_346 [ V_255 ] ;
V_5 -> V_256 [ V_344 ++ ] = V_347 [ V_255 ] ;
}
V_5 -> V_182 = 0x07 ;
V_5 -> V_55 = V_348 ;
V_5 -> V_54 = V_349 ;
V_5 -> V_207 = 0x08 ;
F_164 ( & V_5 -> V_335 ) ;
F_109 ( V_5 , V_227 ) ;
}
static int T_8 V_119 ( void )
{
const char * V_350 = NULL ;
struct V_4 * V_5 ;
unsigned int V_121 = 0 , V_81 ;
F_71 () ;
if ( V_113 )
V_350 = V_113 -> V_351 () ;
if ( ! V_350 ) {
V_101 = 0 ;
F_72 () ;
return 0 ;
}
for ( V_81 = 0 ; V_81 < V_352 ; V_81 ++ ) {
struct V_353 * V_353 = & V_354 [ V_81 ] ;
if ( V_353 -> V_355 == NULL ) {
V_353 -> V_355 = V_113 ;
V_353 -> V_356 = V_350 ;
V_353 -> V_357 = V_358 ;
V_353 -> V_266 = 0 ;
V_353 -> V_267 = V_109 - 1 ;
break;
}
}
for ( V_81 = 0 ; V_81 < V_109 ; V_81 ++ )
V_114 [ V_81 ] = V_113 ;
if ( V_208 ) {
V_359 = V_360 ;
F_165 ( & V_361 , V_362 + ( V_208 * V_212 ) ) ;
}
for ( V_121 = 0 ; V_121 < V_174 ; V_121 ++ ) {
V_100 [ V_121 ] . V_24 = V_5 = F_52 ( sizeof( struct V_4 ) , V_363 ) ;
F_54 ( & V_100 [ V_121 ] . V_129 , V_130 ) ;
F_53 ( & V_5 -> V_128 ) ;
F_46 ( V_5 , V_121 , 1 ) ;
V_5 -> V_93 = F_52 ( V_5 -> V_71 , V_363 ) ;
F_58 ( V_5 , V_5 -> V_26 , V_5 -> V_30 ,
V_121 || ! V_5 -> V_15 -> V_95 ) ;
}
V_121 = V_101 = 0 ;
V_115 = V_5 = V_100 [ V_121 ] . V_24 ;
F_36 ( V_5 ) ;
F_37 ( V_5 ) ;
F_64 ( V_5 , V_5 -> V_76 , V_5 -> V_80 ) ;
F_84 ( V_5 , 0 ) ;
F_67 ( V_5 ) ;
F_166 ( L_7 ,
V_5 -> V_53 ? L_8 : L_9 ,
V_350 , V_5 -> V_30 , V_5 -> V_26 ) ;
V_306 = 1 ;
F_123 ( L_10 ) ;
F_72 () ;
#ifdef F_167
F_168 ( & V_364 ) ;
#endif
return 0 ;
}
static T_9 F_169 ( struct V_365 * V_366 ,
struct V_367 * V_368 , char * V_193 )
{
return sprintf ( V_193 , L_11 , V_101 + 1 ) ;
}
int T_8 F_170 ( const struct V_369 * V_370 )
{
F_171 ( & V_371 , V_370 ) ;
if ( F_172 ( & V_371 , F_173 ( V_372 , 0 ) , 1 ) ||
F_174 ( F_173 ( V_372 , 0 ) , 1 , L_12 ) < 0 )
F_175 ( L_13 ) ;
V_104 = F_176 ( V_373 , NULL , F_173 ( V_372 , 0 ) , NULL , L_14 ) ;
if ( F_177 ( V_104 ) )
V_104 = NULL ;
else
F_178 ( F_179 ( V_104 , & V_374 ) < 0 ) ;
F_180 () ;
V_310 = F_181 ( V_109 ) ;
if ( ! V_310 )
F_175 ( L_15 ) ;
V_310 -> V_112 = V_375 ;
V_310 -> V_376 = L_16 ;
V_310 -> V_377 = 1 ;
V_310 -> V_378 = V_372 ;
V_310 -> V_379 = 1 ;
V_310 -> type = V_380 ;
V_310 -> V_381 = V_382 ;
if ( V_233 )
V_310 -> V_381 . V_342 |= V_343 ;
V_310 -> V_383 = V_384 | V_385 ;
F_182 ( V_310 , & V_386 ) ;
if ( F_183 ( V_310 ) )
F_175 ( L_17 ) ;
F_184 () ;
F_185 () ;
#ifdef F_186
F_187 () ;
#endif
return 0 ;
}
static int F_188 ( const struct V_387 * V_388 , int V_266 , int V_267 ,
int V_389 )
{
struct V_390 * V_112 = V_388 -> V_112 ;
const char * V_356 = NULL ;
struct V_353 * V_353 ;
int V_81 , V_255 = - 1 , V_344 = - 1 , V_333 = - V_391 ;
if ( ! F_189 ( V_112 ) )
return - V_391 ;
F_71 () ;
for ( V_81 = 0 ; V_81 < V_352 ; V_81 ++ ) {
V_353 = & V_354 [ V_81 ] ;
if ( V_353 -> V_355 == V_388 ) {
V_356 = V_353 -> V_356 ;
V_333 = 0 ;
break;
}
}
if ( V_333 )
goto V_136;
if ( ! ( V_353 -> V_357 & V_358 ) ) {
V_388 -> V_351 () ;
V_353 -> V_357 |= V_358 ;
}
if ( V_389 ) {
if ( V_113 )
F_47 ( V_113 -> V_112 ) ;
F_49 ( V_112 ) ;
V_113 = V_388 ;
}
V_266 = V_264 ( V_266 , V_353 -> V_266 ) ;
V_267 = F_62 ( V_267 , V_353 -> V_267 ) ;
for ( V_81 = V_266 ; V_81 <= V_267 ; V_81 ++ ) {
int V_107 ;
struct V_4 * V_5 = V_100 [ V_81 ] . V_24 ;
if ( V_114 [ V_81 ] )
F_47 ( V_114 [ V_81 ] -> V_112 ) ;
F_49 ( V_112 ) ;
V_114 [ V_81 ] = V_388 ;
if ( ! V_5 || ! V_5 -> V_15 )
continue;
V_255 = V_81 ;
if ( F_13 ( V_5 ) ) {
V_344 = V_81 ;
F_37 ( V_5 ) ;
}
V_107 = V_5 -> V_53 ;
V_5 -> V_15 -> V_172 ( V_5 ) ;
V_5 -> V_14 = ( unsigned long ) V_5 -> V_93 ;
F_46 ( V_5 , V_81 , 0 ) ;
F_36 ( V_5 ) ;
F_26 ( V_5 ) ;
if ( V_107 != V_5 -> V_53 )
F_38 ( V_5 ) ;
}
F_166 ( L_18 ) ;
if ( ! V_389 )
F_123 ( L_19 , V_266 + 1 , V_267 + 1 ) ;
if ( V_255 >= 0 ) {
struct V_4 * V_5 = V_100 [ V_255 ] . V_24 ;
F_123 ( L_20 ,
V_5 -> V_53 ? L_8 : L_9 ,
V_356 , V_5 -> V_30 , V_5 -> V_26 ) ;
if ( V_344 >= 0 ) {
V_5 = V_100 [ V_344 ] . V_24 ;
F_67 ( V_5 ) ;
}
} else
F_123 ( L_21 , V_356 ) ;
V_333 = 0 ;
V_136:
F_72 () ;
F_47 ( V_112 ) ;
return V_333 ;
}
static int F_190 ( const struct V_387 * V_388 , int V_266 , int V_267 )
{
int V_81 , V_333 = 0 ;
for ( V_81 = V_266 ; V_81 <= V_267 ; V_81 ++ ) {
struct V_4 * V_5 = V_100 [ V_81 ] . V_24 ;
if ( V_5 && V_5 -> V_88 == V_89 ) {
V_333 = 1 ;
break;
}
}
return V_333 ;
}
int F_191 ( const struct V_387 * V_388 , int V_266 , int V_267 , int V_389 )
{
struct V_390 * V_112 = V_388 -> V_112 ;
const struct V_387 * V_392 = NULL ;
struct V_353 * V_353 = NULL , * V_393 = NULL ;
int V_81 , V_333 = - V_391 ;
if ( ! F_189 ( V_112 ) )
return - V_391 ;
F_71 () ;
for ( V_81 = 0 ; V_81 < V_352 ; V_81 ++ ) {
V_353 = & V_354 [ V_81 ] ;
if ( V_353 -> V_355 == V_388 &&
V_353 -> V_357 & V_394 ) {
V_333 = 0 ;
break;
}
}
if ( V_333 ) {
F_72 () ;
goto V_136;
}
V_333 = - V_391 ;
for ( V_81 = 0 ; V_81 < V_352 ; V_81 ++ ) {
V_393 = & V_354 [ V_81 ] ;
if ( V_393 -> V_355 &&
! ( V_393 -> V_357 & V_394 ) ) {
V_392 = V_393 -> V_355 ;
V_333 = 0 ;
break;
}
}
if ( V_333 ) {
F_72 () ;
goto V_136;
}
if ( ! F_192 ( V_388 ) ) {
F_72 () ;
goto V_136;
}
V_266 = V_264 ( V_266 , V_353 -> V_266 ) ;
V_267 = F_62 ( V_267 , V_353 -> V_267 ) ;
for ( V_81 = V_266 ; V_81 <= V_267 ; V_81 ++ ) {
if ( V_114 [ V_81 ] == V_388 ) {
F_47 ( V_388 -> V_112 ) ;
V_114 [ V_81 ] = NULL ;
}
}
if ( ! F_192 ( V_392 ) ) {
const struct V_387 * V_395 = V_113 ;
V_392 -> V_351 () ;
V_393 -> V_357 |= V_358 ;
V_113 = V_395 ;
}
if ( ! F_192 ( V_388 ) )
V_353 -> V_357 &= ~ V_358 ;
F_72 () ;
F_188 ( V_392 , V_266 , V_267 , V_389 ) ;
V_136:
F_47 ( V_112 ) ;
return V_333 ;
}
static int F_193 ( struct V_353 * V_355 )
{
const struct V_387 * V_392 = NULL , * V_388 = NULL ;
int V_81 , V_396 = 1 , V_266 = - 1 , V_267 = - 1 , V_389 = 0 ;
if ( ! V_355 -> V_355 || ! ( V_355 -> V_357 & V_394 ) ||
F_190 ( V_355 -> V_355 , V_355 -> V_266 , V_355 -> V_267 ) )
goto V_136;
V_388 = V_355 -> V_355 ;
for ( V_81 = 0 ; V_81 < V_352 ; V_81 ++ ) {
struct V_353 * V_355 = & V_354 [ V_81 ] ;
if ( V_355 -> V_355 && ! ( V_355 -> V_357 & V_394 ) ) {
V_392 = V_355 -> V_355 ;
break;
}
}
if ( ! V_392 )
goto V_136;
while ( V_396 ) {
V_396 = 0 ;
for ( V_81 = V_355 -> V_266 ; V_81 <= V_355 -> V_267 ; V_81 ++ ) {
if ( V_114 [ V_81 ] == V_392 ) {
if ( V_266 == - 1 )
V_266 = V_81 ;
V_267 = V_81 ;
V_396 = 1 ;
} else if ( V_266 != - 1 )
break;
}
if ( V_266 == 0 && V_267 == V_109 - 1 )
V_389 = 1 ;
if ( V_266 != - 1 )
F_188 ( V_388 , V_266 , V_267 , V_389 ) ;
V_266 = - 1 ;
V_267 = - 1 ;
V_389 = 0 ;
}
V_136:
return 0 ;
}
static int F_194 ( struct V_353 * V_355 )
{
const struct V_387 * V_388 = NULL ;
int V_81 , V_396 = 1 , V_266 = - 1 , V_267 = - 1 , V_389 = 0 ;
if ( ! V_355 -> V_355 || ! ( V_355 -> V_357 & V_394 ) ||
F_190 ( V_355 -> V_355 , V_355 -> V_266 , V_355 -> V_267 ) )
goto V_136;
V_388 = V_355 -> V_355 ;
while ( V_396 ) {
V_396 = 0 ;
for ( V_81 = V_355 -> V_266 ; V_81 <= V_355 -> V_267 ; V_81 ++ ) {
if ( V_114 [ V_81 ] == V_388 ) {
if ( V_266 == - 1 )
V_266 = V_81 ;
V_267 = V_81 ;
V_396 = 1 ;
} else if ( V_266 != - 1 )
break;
}
if ( V_266 == 0 && V_267 == V_109 - 1 )
V_389 = 1 ;
if ( V_266 != - 1 )
F_191 ( V_388 , V_266 , V_267 , V_389 ) ;
V_266 = - 1 ;
V_267 = - 1 ;
V_389 = 0 ;
}
V_136:
return 0 ;
}
static inline int F_193 ( struct V_353 * V_355 )
{
return 0 ;
}
static inline int F_194 ( struct V_353 * V_355 )
{
return 0 ;
}
static T_9 F_195 ( struct V_365 * V_366 , struct V_367 * V_368 ,
const char * V_193 , T_10 V_35 )
{
struct V_353 * V_355 = F_196 ( V_366 ) ;
int V_397 = F_197 ( V_193 , NULL , 0 ) ;
if ( V_397 )
F_193 ( V_355 ) ;
else
F_194 ( V_355 ) ;
return V_35 ;
}
static T_9 F_198 ( struct V_365 * V_366 , struct V_367 * V_368 ,
char * V_193 )
{
struct V_353 * V_355 = F_196 ( V_366 ) ;
int V_397 = F_192 ( V_355 -> V_355 ) ;
return snprintf ( V_193 , V_398 , L_22 , V_397 ) ;
}
static T_9 F_199 ( struct V_365 * V_366 , struct V_367 * V_368 ,
char * V_193 )
{
struct V_353 * V_355 = F_196 ( V_366 ) ;
return snprintf ( V_193 , V_398 , L_23 ,
( V_355 -> V_357 & V_394 ) ? L_24 : L_25 ,
V_355 -> V_356 ) ;
}
static int F_200 ( struct V_353 * V_355 )
{
int V_81 ;
int error = 0 ;
V_355 -> V_357 |= V_399 ;
F_201 ( V_355 -> V_366 , V_355 ) ;
for ( V_81 = 0 ; V_81 < F_118 ( V_400 ) ; V_81 ++ ) {
error = F_179 ( V_355 -> V_366 , & V_400 [ V_81 ] ) ;
if ( error )
break;
}
if ( error ) {
while ( -- V_81 >= 0 )
F_202 ( V_355 -> V_366 , & V_400 [ V_81 ] ) ;
V_355 -> V_357 &= ~ V_399 ;
}
return error ;
}
static void F_203 ( struct V_353 * V_355 )
{
int V_81 ;
if ( V_355 -> V_357 & V_399 ) {
for ( V_81 = 0 ; V_81 < F_118 ( V_400 ) ; V_81 ++ )
F_202 ( V_355 -> V_366 , & V_400 [ V_81 ] ) ;
V_355 -> V_357 &= ~ V_399 ;
}
}
int F_192 ( const struct V_387 * V_388 )
{
int V_81 , V_401 = 0 ;
for ( V_81 = 0 ; V_81 < V_109 ; V_81 ++ ) {
if ( V_114 [ V_81 ] == V_388 ) {
V_401 = 1 ;
break;
}
}
return V_401 ;
}
int F_204 ( struct V_4 * V_5 )
{
int V_170 = 0 ;
V_402 = V_101 ;
V_403 = V_215 ;
V_404 = V_291 ;
V_405 = V_5 -> V_88 ;
V_406 = V_87 ;
V_5 -> V_88 = V_293 ;
V_87 = 0 ;
if ( V_5 -> V_15 -> F_204 )
V_170 = V_5 -> V_15 -> F_204 ( V_5 ) ;
#ifdef F_205
if ( V_5 -> V_26 < 999 ) {
int V_407 ;
char V_408 [ 4 ] ;
const char * V_409 [ 3 ] = {
L_26 ,
L_27 ,
V_408 ,
} ;
if ( F_206 ( V_409 [ 0 ] , & V_407 ) ) {
snprintf ( V_408 , 4 , L_28 , V_5 -> V_26 ) ;
F_207 ( 2 , V_409 ) ;
}
}
#endif
return V_170 ;
}
int F_208 ( void )
{
struct V_4 * V_5 ;
int V_170 = 0 ;
V_101 = V_402 ;
V_215 = V_403 ;
V_291 = V_404 ;
V_87 = V_406 ;
V_100 [ V_101 ] . V_24 -> V_88 = V_405 ;
V_5 = V_100 [ V_101 ] . V_24 ;
if ( V_5 -> V_15 -> F_208 )
V_170 = V_5 -> V_15 -> F_208 ( V_5 ) ;
return V_170 ;
}
int F_209 ( const struct V_387 * V_388 , int V_266 , int V_267 )
{
struct V_390 * V_112 = V_388 -> V_112 ;
struct V_353 * V_353 ;
const char * V_356 ;
int V_81 , V_333 = 0 ;
if ( ! F_189 ( V_112 ) )
return - V_391 ;
F_71 () ;
for ( V_81 = 0 ; V_81 < V_352 ; V_81 ++ ) {
V_353 = & V_354 [ V_81 ] ;
if ( V_353 -> V_355 == V_388 )
V_333 = - V_410 ;
}
if ( V_333 )
goto V_136;
V_356 = V_388 -> V_351 () ;
if ( ! V_356 )
goto V_136;
V_333 = - V_157 ;
for ( V_81 = 0 ; V_81 < V_352 ; V_81 ++ ) {
V_353 = & V_354 [ V_81 ] ;
if ( V_353 -> V_355 == NULL ) {
V_353 -> V_355 = V_388 ;
V_353 -> V_356 = V_356 ;
V_353 -> V_411 = V_81 ;
V_353 -> V_357 = V_394 |
V_358 ;
V_353 -> V_266 = V_266 ;
V_353 -> V_267 = V_267 ;
V_333 = 0 ;
break;
}
}
if ( V_333 )
goto V_136;
V_353 -> V_366 = F_176 ( V_412 , NULL ,
F_173 ( 0 , V_353 -> V_411 ) ,
NULL , L_29 ,
V_353 -> V_411 ) ;
if ( F_177 ( V_353 -> V_366 ) ) {
F_123 ( V_413 L_30
L_31 , V_353 -> V_356 ,
F_210 ( V_353 -> V_366 ) ) ;
V_353 -> V_366 = NULL ;
} else {
F_200 ( V_353 ) ;
}
V_136:
F_72 () ;
F_47 ( V_112 ) ;
return V_333 ;
}
int F_211 ( const struct V_387 * V_388 )
{
int V_81 , V_333 = - V_391 ;
F_71 () ;
if ( F_192 ( V_388 ) )
goto V_136;
for ( V_81 = 0 ; V_81 < V_352 ; V_81 ++ ) {
struct V_353 * V_353 = & V_354 [ V_81 ] ;
if ( V_353 -> V_355 == V_388 &&
V_353 -> V_357 & V_394 ) {
F_203 ( V_353 ) ;
F_212 ( V_412 ,
F_173 ( 0 , V_353 -> V_411 ) ) ;
V_353 -> V_355 = NULL ;
V_353 -> V_356 = NULL ;
V_353 -> V_366 = NULL ;
V_353 -> V_411 = 0 ;
V_353 -> V_357 = 0 ;
V_353 -> V_266 = 0 ;
V_353 -> V_267 = 0 ;
V_333 = 0 ;
break;
}
}
V_136:
F_72 () ;
return V_333 ;
}
int F_213 ( const struct V_387 * V_388 , int V_266 , int V_267 , int V_389 )
{
int V_136 ;
V_136 = F_209 ( V_388 , V_266 , V_267 ) ;
if ( V_136 == - V_410 )
V_136 = 0 ;
if ( ! V_136 )
F_188 ( V_388 , V_266 , V_267 , V_389 ) ;
return V_136 ;
}
void F_214 ( const struct V_387 * V_388 )
{
F_211 ( V_388 ) ;
}
static int T_8 F_215 ( void )
{
int V_81 ;
V_412 = F_216 ( V_375 , L_32 ) ;
if ( F_177 ( V_412 ) ) {
F_123 ( V_413 L_33
L_31 , F_210 ( V_412 ) ) ;
V_412 = NULL ;
}
for ( V_81 = 0 ; V_81 < V_352 ; V_81 ++ ) {
struct V_353 * V_355 = & V_354 [ V_81 ] ;
if ( V_355 -> V_355 && ! V_355 -> V_366 ) {
V_355 -> V_366 = F_176 ( V_412 , NULL ,
F_173 ( 0 , V_355 -> V_411 ) ,
NULL , L_29 ,
V_355 -> V_411 ) ;
if ( F_177 ( V_355 -> V_366 ) ) {
F_123 ( V_413 L_34
L_35 ,
V_355 -> V_356 , F_210 ( V_355 -> V_366 ) ) ;
V_355 -> V_366 = NULL ;
} else {
F_200 ( V_355 ) ;
}
}
}
return 0 ;
}
static int F_145 ( char T_7 * V_13 )
{
unsigned int V_298 ;
if ( F_139 ( V_298 , V_13 + 1 ) )
return - V_315 ;
V_414 = ( V_298 < 4 ) ? V_298 : 0 ;
return 0 ;
}
void F_129 ( int V_415 )
{
struct V_4 * V_5 = V_100 [ V_101 ] . V_24 ;
int V_81 ;
F_21 () ;
if ( V_87 ) {
if ( V_359 == V_416 ) {
V_359 = V_417 ;
V_5 -> V_15 -> V_418 ( V_5 , V_414 + 1 , 0 ) ;
}
return;
}
if ( V_415 ) {
F_23 ( V_5 ) ;
F_37 ( V_5 ) ;
V_5 -> V_15 -> V_418 ( V_5 , - 1 , 1 ) ;
V_87 = V_101 + 1 ;
V_359 = V_417 ;
F_36 ( V_5 ) ;
return;
}
if ( V_359 != V_360 )
return;
V_359 = V_417 ;
if ( V_5 -> V_88 != V_293 ) {
V_87 = V_101 + 1 ;
return;
}
F_23 ( V_5 ) ;
F_217 ( & V_361 ) ;
V_295 = 0 ;
F_37 ( V_5 ) ;
V_81 = V_5 -> V_15 -> V_418 ( V_5 , V_214 ? 1 : ( V_414 + 1 ) , 0 ) ;
V_87 = V_101 + 1 ;
if ( V_81 )
F_36 ( V_5 ) ;
if ( V_419 && V_419 ( 1 ) )
return;
if ( V_214 && V_414 ) {
V_359 = V_416 ;
F_165 ( & V_361 , V_362 + V_214 ) ;
}
F_68 ( V_420 , V_5 -> V_103 , V_5 -> V_103 ) ;
}
void F_218 ( int V_421 )
{
struct V_4 * V_5 ;
if ( ! V_422 )
F_122 () ;
F_21 () ;
V_331 = 0 ;
if ( ! V_87 )
return;
if ( ! F_45 ( V_101 ) ) {
F_219 ( L_36 ,
V_101 + 1 ) ;
return;
}
V_5 = V_100 [ V_101 ] . V_24 ;
if ( V_5 -> V_88 != V_293 && ! F_42 ( V_5 ) )
return;
if ( V_208 ) {
F_165 ( & V_361 , V_362 + ( V_208 * V_212 ) ) ;
V_359 = V_360 ;
}
V_87 = 0 ;
if ( V_5 -> V_15 -> V_418 ( V_5 , 0 , V_421 ) || F_42 ( V_5 ) )
F_67 ( V_5 ) ;
if ( V_419 )
V_419 ( 0 ) ;
F_41 ( V_5 ) ;
F_24 ( V_5 ) ;
F_68 ( V_423 , V_5 -> V_103 , V_5 -> V_103 ) ;
}
void F_142 ( void )
{
F_218 ( 0 ) ;
}
static void F_220 ( unsigned long V_424 )
{
if ( F_221 ( ! F_222 () ) ) {
F_165 ( & V_361 , V_362 + ( V_208 * V_212 ) ) ;
return;
}
V_295 = 1 ;
F_11 ( & V_20 ) ;
}
void F_102 ( void )
{
F_21 () ;
F_122 () ;
F_223 ( & V_361 ) ;
V_295 = 0 ;
if ( V_331 || ! V_100 [ V_101 ] . V_24 || V_100 [ V_101 ] . V_24 -> V_88 == V_89 )
return;
if ( V_87 )
F_142 () ;
else if ( V_208 ) {
F_165 ( & V_361 , V_362 + ( V_208 * V_212 ) ) ;
V_359 = V_360 ;
}
}
static void F_41 ( struct V_4 * V_5 )
{
F_21 () ;
if ( V_5 -> V_88 != V_89 )
V_5 -> V_15 -> V_425 ( V_5 , V_192 ) ;
}
static int F_224 ( unsigned char T_7 * V_311 , int V_426 )
{
int V_81 , V_255 , V_344 ;
F_21 () ;
for ( V_81 = 0 ; V_81 < 16 ; V_81 ++ )
if ( V_426 ) {
F_139 ( V_345 [ V_81 ] , V_311 ++ ) ;
F_139 ( V_346 [ V_81 ] , V_311 ++ ) ;
F_139 ( V_347 [ V_81 ] , V_311 ++ ) ;
} else {
F_225 ( V_345 [ V_81 ] , V_311 ++ ) ;
F_225 ( V_346 [ V_81 ] , V_311 ++ ) ;
F_225 ( V_347 [ V_81 ] , V_311 ++ ) ;
}
if ( V_426 ) {
for ( V_81 = 0 ; V_81 < V_109 ; V_81 ++ )
if ( F_45 ( V_81 ) ) {
for ( V_255 = V_344 = 0 ; V_255 < 16 ; V_255 ++ ) {
V_100 [ V_81 ] . V_24 -> V_256 [ V_344 ++ ] = V_345 [ V_255 ] ;
V_100 [ V_81 ] . V_24 -> V_256 [ V_344 ++ ] = V_346 [ V_255 ] ;
V_100 [ V_81 ] . V_24 -> V_256 [ V_344 ++ ] = V_347 [ V_255 ] ;
}
F_41 ( V_100 [ V_81 ] . V_24 ) ;
}
}
return 0 ;
}
int F_226 ( unsigned char T_7 * V_311 )
{
int V_427 ;
F_71 () ;
V_427 = F_224 ( V_311 , 1 ) ;
F_72 () ;
return V_427 ;
}
int F_227 ( unsigned char T_7 * V_311 )
{
int V_427 ;
F_71 () ;
V_427 = F_224 ( V_311 , 0 ) ;
F_72 () ;
return V_427 ;
}
void F_113 ( struct V_4 * V_5 )
{
int V_255 , V_344 ;
for ( V_255 = V_344 = 0 ; V_255 < 16 ; V_255 ++ ) {
V_5 -> V_256 [ V_344 ++ ] = V_345 [ V_255 ] ;
V_5 -> V_256 [ V_344 ++ ] = V_346 [ V_255 ] ;
V_5 -> V_256 [ V_344 ++ ] = V_347 [ V_255 ] ;
}
F_41 ( V_5 ) ;
}
static int F_228 ( struct V_4 * V_5 , struct V_428 * V_429 )
{
struct V_430 V_431 ;
int V_427 = - V_157 ;
int V_245 ;
if ( V_5 -> V_88 != V_293 )
return - V_157 ;
if ( V_429 -> V_312 ) {
V_431 . V_312 = F_56 ( V_432 , V_126 ) ;
if ( ! V_431 . V_312 )
return - V_127 ;
} else
V_431 . V_312 = NULL ;
F_71 () ;
if ( V_5 -> V_15 -> F_228 )
V_427 = V_5 -> V_15 -> F_228 ( V_5 , & V_431 ) ;
else
V_427 = - V_433 ;
F_72 () ;
if ( V_427 )
goto V_434;
V_245 = ( V_431 . V_133 + 7 ) / 8 * 32 * V_431 . V_435 ;
if ( V_429 -> V_312 && V_431 . V_435 > V_429 -> V_435 )
V_427 = - V_436 ;
if ( ! ( V_429 -> V_383 & V_437 ) ) {
if ( V_431 . V_133 > V_429 -> V_133 || V_431 . V_134 > V_429 -> V_134 )
V_427 = - V_436 ;
} else {
if ( V_431 . V_133 != 8 )
V_427 = - V_438 ;
else if ( ( V_429 -> V_134 && V_431 . V_134 > V_429 -> V_134 ) ||
V_431 . V_134 > 32 )
V_427 = - V_436 ;
}
if ( V_427 )
goto V_434;
V_429 -> V_134 = V_431 . V_134 ;
V_429 -> V_133 = V_431 . V_133 ;
V_429 -> V_435 = V_431 . V_435 ;
if ( V_429 -> V_312 && F_229 ( V_429 -> V_312 , V_431 . V_312 , V_245 ) )
V_427 = - V_315 ;
V_434:
F_57 ( V_431 . V_312 ) ;
return V_427 ;
}
static int F_230 ( struct V_4 * V_5 , struct V_428 * V_429 )
{
struct V_430 V_431 ;
int V_427 = - V_157 ;
int V_439 ;
if ( V_5 -> V_88 != V_293 )
return - V_157 ;
if ( ! V_429 -> V_312 )
return - V_157 ;
if ( V_429 -> V_435 > 512 )
return - V_157 ;
if ( ! V_429 -> V_134 ) {
int V_440 , V_81 ;
T_2 T_7 * V_441 = V_429 -> V_312 ;
T_2 V_442 ;
if ( ! ( V_429 -> V_383 & V_437 ) )
return - V_157 ;
for ( V_440 = 32 ; V_440 > 0 ; V_440 -- )
for ( V_81 = 0 ; V_81 < V_429 -> V_435 ; V_81 ++ ) {
if ( F_139 ( V_442 , & V_441 [ 32 * V_81 + V_440 - 1 ] ) )
return - V_315 ;
if ( V_442 )
goto V_443;
}
return - V_157 ;
V_443:
V_429 -> V_134 = V_440 ;
}
if ( V_429 -> V_133 <= 0 || V_429 -> V_133 > 32 || V_429 -> V_134 > 32 )
return - V_157 ;
V_439 = ( V_429 -> V_133 + 7 ) / 8 * 32 * V_429 -> V_435 ;
if ( V_439 > V_432 )
return - V_436 ;
V_431 . V_435 = V_429 -> V_435 ;
V_431 . V_134 = V_429 -> V_134 ;
V_431 . V_133 = V_429 -> V_133 ;
V_431 . V_312 = F_231 ( V_429 -> V_312 , V_439 ) ;
if ( F_177 ( V_431 . V_312 ) )
return F_210 ( V_431 . V_312 ) ;
F_71 () ;
if ( V_5 -> V_15 -> F_230 )
V_427 = V_5 -> V_15 -> F_230 ( V_5 , & V_431 , V_429 -> V_383 ) ;
else
V_427 = - V_433 ;
F_72 () ;
F_57 ( V_431 . V_312 ) ;
return V_427 ;
}
static int F_232 ( struct V_4 * V_5 , struct V_428 * V_429 )
{
struct V_430 V_431 = { . V_133 = V_429 -> V_133 , . V_134 = V_429 -> V_134 } ;
char V_376 [ V_444 ] ;
char * V_25 = V_376 ;
int V_427 ;
if ( V_5 -> V_88 != V_293 )
return - V_157 ;
if ( ! V_429 -> V_312 )
V_25 = NULL ;
else if ( F_233 ( V_376 , V_429 -> V_312 , V_444 - 1 ) < 0 )
return - V_315 ;
else
V_376 [ V_444 - 1 ] = 0 ;
F_71 () ;
if ( V_5 -> V_15 -> F_232 )
V_427 = V_5 -> V_15 -> F_232 ( V_5 , & V_431 , V_25 ) ;
else
V_427 = - V_433 ;
F_72 () ;
if ( ! V_427 ) {
V_429 -> V_133 = V_431 . V_133 ;
V_429 -> V_134 = V_431 . V_134 ;
}
return V_427 ;
}
static int F_234 ( struct V_4 * V_5 , struct V_428 * V_429 )
{
int V_355 = V_429 -> V_134 ;
int V_427 ;
if ( V_5 -> V_88 != V_293 )
return - V_157 ;
F_71 () ;
if ( ! V_5 -> V_15 -> F_234 )
V_427 = - V_433 ;
else if ( V_355 < 0 || ! F_45 ( V_355 ) )
V_427 = - V_445 ;
else if ( V_355 == V_5 -> V_103 )
V_427 = 0 ;
else
V_427 = V_5 -> V_15 -> F_234 ( V_5 , V_355 ) ;
F_72 () ;
return V_427 ;
}
int F_235 ( struct V_4 * V_5 , struct V_428 * V_429 )
{
switch ( V_429 -> V_429 ) {
case V_446 :
return F_230 ( V_5 , V_429 ) ;
case V_447 :
return F_228 ( V_5 , V_429 ) ;
case V_448 :
return F_232 ( V_5 , V_429 ) ;
case V_449 :
return F_234 ( V_5 , V_429 ) ;
}
return - V_433 ;
}
T_1 F_236 ( struct V_4 * V_5 , int V_11 )
{
T_1 V_450 = F_19 ( F_8 ( V_5 , V_11 , 1 ) ) ;
T_1 V_245 = V_450 & 0xff ;
if ( V_450 & V_5 -> V_56 )
V_245 |= 0x100 ;
return V_245 ;
}
unsigned short * F_237 ( struct V_4 * V_5 , int V_451 , int V_12 )
{
return F_8 ( V_5 , 2 * V_451 , V_12 ) ;
}
void F_238 ( struct V_4 * V_5 , unsigned char * V_13 )
{
V_13 [ 0 ] = V_5 -> V_76 ;
V_13 [ 1 ] = V_5 -> V_80 ;
}
void F_239 ( struct V_4 * V_5 , unsigned char * V_13 )
{
F_23 ( V_5 ) ;
F_64 ( V_5 , V_13 [ 0 ] , V_13 [ 1 ] ) ;
F_24 ( V_5 ) ;
}
T_1 F_240 ( struct V_4 * V_5 , const T_1 * V_452 )
{
if ( ( unsigned long ) V_452 == V_5 -> V_75 && V_83 != - 1 )
return V_83 ;
return F_19 ( V_452 ) ;
}
void F_241 ( struct V_4 * V_5 , T_1 V_453 , T_1 * V_452 )
{
F_28 ( V_453 , V_452 ) ;
if ( ( unsigned long ) V_452 == V_5 -> V_75 ) {
V_83 = - 1 ;
F_32 ( V_5 ) ;
}
}
void F_242 ( struct V_4 * V_5 )
{
F_7 ( V_5 ) ;
}
