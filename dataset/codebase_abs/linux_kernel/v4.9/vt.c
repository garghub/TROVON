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
static inline bool F_8 ( const struct V_4 * V_5 )
{
return V_5 -> V_12 == V_13 ;
}
static inline bool F_9 ( const struct V_4 * V_5 )
{
return F_10 ( V_5 ) && ! V_14 ;
}
static inline unsigned short * F_11 ( struct V_4 * V_5 , int V_15 , int V_16 )
{
unsigned short * V_17 ;
if ( ! V_16 )
V_17 = ( unsigned short * ) ( V_5 -> V_18 + V_15 ) ;
else if ( ! V_5 -> V_19 -> V_20 )
V_17 = ( unsigned short * ) ( V_5 -> V_21 + V_15 ) ;
else
V_17 = V_5 -> V_19 -> V_20 ( V_5 , V_15 ) ;
return V_17 ;
}
static inline void F_12 ( int V_22 )
{
V_23 += V_22 ;
F_13 () ;
}
void F_13 ( void )
{
F_14 ( & V_24 ) ;
}
static void F_15 ( struct V_4 * V_5 , unsigned int V_25 , unsigned int V_26 , int V_27 )
{
unsigned short * V_28 , * V_29 ;
if ( V_25 + V_27 >= V_26 )
V_27 = V_26 - V_25 - 1 ;
if ( V_26 > V_5 -> V_30 || V_25 >= V_26 || V_27 < 1 )
return;
if ( F_10 ( V_5 ) && V_5 -> V_19 -> V_31 ( V_5 , V_25 , V_26 , V_32 , V_27 ) )
return;
V_28 = ( unsigned short * ) ( V_5 -> V_18 + V_5 -> V_33 * V_25 ) ;
V_29 = ( unsigned short * ) ( V_5 -> V_18 + V_5 -> V_33 * ( V_25 + V_27 ) ) ;
F_16 ( V_28 , V_29 , ( V_26 - V_25 - V_27 ) * V_5 -> V_33 ) ;
F_17 ( V_28 + ( V_26 - V_25 - V_27 ) * V_5 -> V_34 , V_5 -> V_35 ,
V_5 -> V_33 * V_27 ) ;
}
static void F_18 ( struct V_4 * V_5 , unsigned int V_25 , unsigned int V_26 , int V_27 )
{
unsigned short * V_29 ;
unsigned int V_36 ;
if ( V_25 + V_27 >= V_26 )
V_27 = V_26 - V_25 - 1 ;
if ( V_26 > V_5 -> V_30 || V_25 >= V_26 || V_27 < 1 )
return;
if ( F_10 ( V_5 ) && V_5 -> V_19 -> V_31 ( V_5 , V_25 , V_26 , V_37 , V_27 ) )
return;
V_29 = ( unsigned short * ) ( V_5 -> V_18 + V_5 -> V_33 * V_25 ) ;
V_36 = V_5 -> V_34 * V_27 ;
F_16 ( V_29 + V_36 , V_29 , ( V_26 - V_25 - V_27 ) * V_5 -> V_33 ) ;
F_17 ( V_29 , V_5 -> V_35 , 2 * V_36 ) ;
}
static void F_19 ( struct V_4 * V_5 , unsigned long V_38 , int V_39 )
{
unsigned int V_40 , V_41 , V_15 ;
T_1 * V_17 ;
V_17 = ( T_1 * ) V_38 ;
if ( ! V_5 -> V_19 -> V_42 ) {
V_15 = ( V_38 - V_5 -> V_18 ) / 2 ;
V_40 = V_15 % V_5 -> V_34 ;
V_41 = V_15 / V_5 -> V_34 ;
} else {
int V_43 , V_44 ;
V_38 = V_5 -> V_19 -> V_42 ( V_5 , V_38 , & V_43 , & V_44 ) ;
V_40 = V_43 ; V_41 = V_44 ;
}
for(; ; ) {
T_1 V_45 = F_20 ( V_17 ) & 0xff00 ;
int V_46 = V_40 ;
T_1 * V_47 = V_17 ;
while ( V_40 < V_5 -> V_34 && V_39 ) {
if ( V_45 != ( F_20 ( V_17 ) & 0xff00 ) ) {
if ( V_17 > V_47 )
V_5 -> V_19 -> V_48 ( V_5 , V_47 , V_17 - V_47 , V_41 , V_46 ) ;
V_46 = V_40 ;
V_47 = V_17 ;
V_45 = F_20 ( V_17 ) & 0xff00 ;
}
V_17 ++ ;
V_40 ++ ;
V_39 -- ;
}
if ( V_17 > V_47 )
V_5 -> V_19 -> V_48 ( V_5 , V_47 , V_17 - V_47 , V_41 , V_46 ) ;
if ( ! V_39 )
break;
V_40 = 0 ;
V_41 ++ ;
if ( V_5 -> V_19 -> V_42 ) {
V_17 = ( T_1 * ) V_38 ;
V_38 = V_5 -> V_19 -> V_42 ( V_5 , V_38 , NULL , NULL ) ;
}
}
}
void F_21 ( struct V_4 * V_5 , unsigned long V_38 , int V_39 )
{
F_22 () ;
if ( F_9 ( V_5 ) ) {
F_23 ( V_5 ) ;
F_19 ( V_5 , V_38 , V_39 ) ;
F_24 ( V_5 ) ;
}
}
static T_2 F_25 ( struct V_4 * V_5 , T_2 V_49 , T_2 V_50 , T_2 V_51 ,
T_2 V_52 , T_2 V_53 , T_2 V_54 )
{
if ( V_5 -> V_19 -> V_55 )
return V_5 -> V_19 -> V_55 ( V_5 , V_49 , V_50 ,
V_51 , V_52 , V_53 , V_54 ) ;
{
T_2 V_56 = V_49 ;
if ( ! V_5 -> V_57 )
return V_50 |
( V_54 ? 2 : 0 ) |
( V_52 ? 4 : 0 ) |
( V_53 ? 8 : 0 ) |
( V_51 ? 0x80 : 0 ) ;
if ( V_54 )
V_56 = ( V_56 & 0xF0 ) | V_5 -> V_58 ;
else if ( V_52 )
V_56 = ( V_56 & 0xf0 ) | V_5 -> V_59 ;
else if ( V_50 == 0 )
V_56 = ( V_56 & 0xf0 ) | V_5 -> V_59 ;
if ( V_53 )
V_56 = ( ( V_56 ) & 0x88 ) | ( ( ( ( V_56 ) >> 4 ) | ( ( V_56 ) << 4 ) ) & 0x77 ) ;
if ( V_51 )
V_56 ^= 0x80 ;
if ( V_50 == 2 )
V_56 ^= 0x08 ;
if ( V_5 -> V_60 == 0x100 )
V_56 <<= 1 ;
return V_56 ;
}
}
static void F_26 ( struct V_4 * V_5 )
{
V_5 -> V_61 = F_25 ( V_5 , V_5 -> V_62 , V_5 -> V_63 ,
V_5 -> V_64 , V_5 -> V_65 ,
V_5 -> V_66 ^ V_5 -> V_67 , V_5 -> V_68 ) ;
V_5 -> V_35 = ( F_25 ( V_5 , V_5 -> V_62 , 1 , V_5 -> V_64 , 0 , V_5 -> V_67 , 0 ) << 8 ) | ' ' ;
}
void F_27 ( struct V_4 * V_5 , int V_15 , int V_39 , int V_16 )
{
unsigned short * V_17 ;
F_22 () ;
V_39 /= 2 ;
V_17 = F_11 ( V_5 , V_15 , V_16 ) ;
if ( V_5 -> V_19 -> V_69 ) {
V_5 -> V_19 -> V_69 ( V_5 , V_17 , V_39 ) ;
} else {
T_1 * V_47 = V_17 ;
int V_70 = V_39 ;
T_1 V_56 ;
if ( ! V_5 -> V_57 ) {
while ( V_70 -- ) {
V_56 = F_20 ( V_47 ) ;
V_56 ^= 0x0800 ;
F_28 ( V_56 , V_47 ) ;
V_47 ++ ;
}
} else if ( V_5 -> V_60 == 0x100 ) {
while ( V_70 -- ) {
V_56 = F_20 ( V_47 ) ;
V_56 = ( ( V_56 ) & 0x11ff ) | ( ( ( V_56 ) & 0xe000 ) >> 4 ) | ( ( ( V_56 ) & 0x0e00 ) << 4 ) ;
F_28 ( V_56 , V_47 ) ;
V_47 ++ ;
}
} else {
while ( V_70 -- ) {
V_56 = F_20 ( V_47 ) ;
V_56 = ( ( V_56 ) & 0x88ff ) | ( ( ( V_56 ) & 0x7000 ) >> 4 ) | ( ( ( V_56 ) & 0x0700 ) << 4 ) ;
F_28 ( V_56 , V_47 ) ;
V_47 ++ ;
}
}
}
if ( F_9 ( V_5 ) )
F_19 ( V_5 , ( unsigned long ) V_17 , V_39 ) ;
F_7 ( V_5 ) ;
}
void F_29 ( struct V_4 * V_5 , int V_15 )
{
static int V_71 = - 1 ;
static unsigned short V_72 ;
static unsigned short V_73 , V_74 ;
F_22 () ;
if ( V_71 != - 1 && V_71 >= 0 &&
V_71 < V_5 -> V_75 ) {
F_28 ( V_72 , F_11 ( V_5 , V_71 , 1 ) ) ;
if ( F_9 ( V_5 ) )
V_5 -> V_19 -> V_76 ( V_5 , V_72 , V_74 , V_73 ) ;
F_7 ( V_5 ) ;
}
V_71 = V_15 ;
if ( V_15 != - 1 && V_15 >= 0 &&
V_15 < V_5 -> V_75 ) {
unsigned short V_77 ;
unsigned short * V_17 ;
V_17 = F_11 ( V_5 , V_15 , 1 ) ;
V_72 = F_20 ( V_17 ) ;
V_77 = V_72 ^ V_5 -> V_78 ;
F_28 ( V_77 , V_17 ) ;
if ( F_9 ( V_5 ) ) {
V_73 = ( V_15 >> 1 ) % V_5 -> V_34 ;
V_74 = ( V_15 >> 1 ) / V_5 -> V_34 ;
V_5 -> V_19 -> V_76 ( V_5 , V_77 , V_74 , V_73 ) ;
}
F_7 ( V_5 ) ;
}
}
static void F_30 ( struct V_4 * V_5 , unsigned int V_27 )
{
unsigned short * V_17 = ( unsigned short * ) V_5 -> V_79 ;
F_16 ( V_17 + V_27 , V_17 , ( V_5 -> V_34 - V_5 -> V_80 - V_27 ) * 2 ) ;
F_17 ( V_17 , V_5 -> V_35 , V_27 * 2 ) ;
V_5 -> V_81 = 0 ;
if ( F_9 ( V_5 ) )
F_19 ( V_5 , ( unsigned long ) V_17 ,
V_5 -> V_34 - V_5 -> V_80 ) ;
}
static void F_31 ( struct V_4 * V_5 , unsigned int V_27 )
{
unsigned short * V_17 = ( unsigned short * ) V_5 -> V_79 ;
F_32 ( V_17 , V_17 + V_27 , ( V_5 -> V_34 - V_5 -> V_80 - V_27 ) * 2 ) ;
F_17 ( V_17 + V_5 -> V_34 - V_5 -> V_80 - V_27 , V_5 -> V_35 ,
V_27 * 2 ) ;
V_5 -> V_81 = 0 ;
if ( F_9 ( V_5 ) )
F_19 ( V_5 , ( unsigned long ) V_17 ,
V_5 -> V_34 - V_5 -> V_80 ) ;
}
static void F_33 ( struct V_4 * V_5 )
{
int V_82 = F_20 ( ( T_1 * ) V_5 -> V_79 ) ;
T_3 type = V_5 -> V_83 ;
if ( ! ( type & 0x10 ) ) return;
if ( V_84 != - 1 ) return;
V_84 = V_82 ;
V_82 |= ( ( type >> 8 ) & 0xff00 ) ;
V_82 ^= ( ( type ) & 0xff00 ) ;
if ( ( type & 0x20 ) && ( ( V_84 & 0x7000 ) == ( V_82 & 0x7000 ) ) ) V_82 ^= 0x7000 ;
if ( ( type & 0x40 ) && ( ( V_82 & 0x700 ) == ( ( V_82 & 0x7000 ) >> 4 ) ) ) V_82 ^= 0x0700 ;
F_28 ( V_82 , ( T_1 * ) V_5 -> V_79 ) ;
if ( F_9 ( V_5 ) )
V_5 -> V_19 -> V_76 ( V_5 , V_82 , V_5 -> V_85 , V_5 -> V_80 ) ;
}
static void F_34 ( struct V_4 * V_5 )
{
if ( V_84 != - 1 ) {
F_28 ( V_84 , ( T_1 * ) V_5 -> V_79 ) ;
if ( F_9 ( V_5 ) )
V_5 -> V_19 -> V_76 ( V_5 , V_84 ,
V_5 -> V_85 , V_5 -> V_80 ) ;
V_84 = - 1 ;
}
}
static void F_23 ( struct V_4 * V_5 )
{
if ( V_5 == V_86 )
F_35 () ;
V_5 -> V_19 -> V_87 ( V_5 , V_88 ) ;
F_34 ( V_5 ) ;
}
static void F_24 ( struct V_4 * V_5 )
{
if ( ! F_8 ( V_5 ) || V_14 || V_5 -> V_89 == V_90 )
return;
if ( V_5 -> V_91 ) {
if ( V_5 == V_86 )
F_35 () ;
F_33 ( V_5 ) ;
if ( ( V_5 -> V_83 & 0x0f ) != 1 )
V_5 -> V_19 -> V_87 ( V_5 , V_92 ) ;
} else
F_23 ( V_5 ) ;
}
static void F_36 ( struct V_4 * V_5 )
{
F_22 () ;
if ( ! F_10 ( V_5 ) ||
! V_5 -> V_19 -> V_93 ||
! V_5 -> V_19 -> V_93 ( V_5 ) )
V_5 -> V_18 = ( unsigned long ) V_5 -> V_94 ;
V_5 -> V_21 = V_5 -> V_18 ;
V_5 -> V_95 = V_5 -> V_18 + V_5 -> V_75 ;
V_5 -> V_79 = V_5 -> V_18 + V_5 -> V_33 * V_5 -> V_85 + 2 * V_5 -> V_80 ;
}
static void F_37 ( struct V_4 * V_5 )
{
F_22 () ;
if ( V_5 -> V_19 -> V_96 )
V_5 -> V_19 -> V_96 ( V_5 ) ;
}
void F_38 ( struct V_4 * V_5 )
{
unsigned short * V_17 = ( unsigned short * ) V_5 -> V_18 ;
int V_39 = V_5 -> V_75 / 2 ;
int V_97 = V_5 -> V_60 | 0xff ;
for (; V_39 > 0 ; V_39 -- , V_17 ++ ) {
F_28 ( ( F_20 ( V_17 ) & V_97 ) | ( V_5 -> V_35 & ~ V_97 ) , V_17 ) ;
}
}
void F_39 ( struct V_4 * V_5 , int V_98 )
{
int V_99 = 0 ;
F_22 () ;
if ( ! V_5 ) {
return;
}
if ( V_98 ) {
struct V_4 * V_100 = V_101 [ V_13 ] . V_28 ;
if ( V_100 == V_5 )
return;
if ( ! F_10 ( V_5 ) )
V_99 = 1 ;
* V_5 -> V_102 = V_5 ;
V_13 = V_5 -> V_12 ;
F_23 ( V_100 ) ;
if ( ! F_10 ( V_100 ) ) {
F_37 ( V_100 ) ;
F_36 ( V_100 ) ;
}
if ( V_103 )
F_40 ( & V_103 -> V_104 , NULL , L_1 ) ;
} else {
F_23 ( V_5 ) ;
V_99 = 1 ;
}
if ( V_99 ) {
int V_105 ;
int V_106 = V_5 -> V_57 ;
F_36 ( V_5 ) ;
V_105 = V_5 -> V_19 -> V_107 ( V_5 ) ;
F_41 ( V_5 ) ;
if ( V_106 != V_5 -> V_57 ) {
F_26 ( V_5 ) ;
F_38 ( V_5 ) ;
}
if ( ( V_105 && V_5 -> V_89 != V_90 ) ||
F_42 ( V_5 ) )
F_19 ( V_5 , V_5 -> V_18 , V_5 -> V_75 / 2 ) ;
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
return ( V_82 < V_108 && V_101 [ V_82 ] . V_28 ) ;
}
static void F_46 ( struct V_4 * V_5 , int V_109 , int V_110 )
{
if ( V_5 -> V_19 )
F_47 ( V_5 -> V_19 -> V_111 ) ;
V_5 -> V_19 = V_112 ;
#ifndef F_48
if ( V_113 [ V_109 ] )
V_5 -> V_19 = V_113 [ V_109 ] ;
#endif
F_49 ( V_5 -> V_19 -> V_111 ) ;
V_5 -> V_12 = V_109 ;
V_5 -> V_102 = & V_114 ;
if ( V_5 -> V_115 )
F_50 ( V_5 ) ;
V_5 -> V_115 = & V_5 -> V_116 ;
V_5 -> V_116 = NULL ;
V_5 -> V_60 = 0 ;
V_5 -> V_78 = 0 ;
V_5 -> V_57 = 0 ;
V_5 -> V_117 = false ;
V_5 -> V_118 = V_119 ;
V_5 -> V_19 -> V_120 ( V_5 , V_110 ) ;
if ( ! V_5 -> V_78 )
V_5 -> V_78 = V_5 -> V_57 ? 0x7700 : 0x0800 ;
V_5 -> V_121 = V_5 -> V_78 ;
V_5 -> V_33 = V_5 -> V_34 << 1 ;
V_5 -> V_75 = V_5 -> V_30 * V_5 -> V_33 ;
}
int F_51 ( unsigned int V_122 )
{
struct V_7 V_8 ;
struct V_4 * V_5 ;
F_22 () ;
if ( V_122 >= V_108 )
return - V_123 ;
if ( V_101 [ V_122 ] . V_28 )
return 0 ;
V_8 . V_5 = V_5 = F_52 ( sizeof( struct V_4 ) , V_124 ) ;
if ( ! V_5 )
return - V_125 ;
V_101 [ V_122 ] . V_28 = V_5 ;
F_53 ( & V_5 -> V_126 ) ;
F_54 ( & V_101 [ V_122 ] . V_127 , V_128 ) ;
F_46 ( V_5 , V_122 , 1 ) ;
if ( ! * V_5 -> V_115 )
F_55 ( V_5 ) ;
V_5 -> V_94 = F_56 ( V_5 -> V_75 , V_124 ) ;
if ( ! V_5 -> V_94 )
goto V_129;
if ( V_130 == - 1 )
V_130 = 1 ;
F_57 ( V_5 , V_5 -> V_30 , V_5 -> V_34 , 1 ) ;
F_58 ( V_122 ) ;
F_6 ( & V_3 , V_131 , & V_8 ) ;
return 0 ;
V_129:
F_59 ( V_5 ) ;
V_101 [ V_122 ] . V_28 = NULL ;
return - V_125 ;
}
static inline int F_60 ( struct V_4 * V_5 , int V_132 , int V_133 ,
int V_134 )
{
int V_135 = 0 ;
if ( V_5 -> V_89 != V_90 && V_5 -> V_19 -> V_136 )
V_135 = V_5 -> V_19 -> V_136 ( V_5 , V_132 , V_133 , V_134 ) ;
return V_135 ;
}
static int F_61 ( struct V_137 * V_138 , struct V_4 * V_5 ,
unsigned int V_139 , unsigned int V_22 )
{
unsigned long V_140 , V_141 , V_142 , V_143 , V_144 , V_135 = 0 ;
unsigned long V_145 ;
unsigned int V_146 , V_147 ;
unsigned int V_148 , V_149 , V_150 , V_151 ;
unsigned int V_134 ;
unsigned short * V_152 ;
F_22 () ;
if ( ! V_5 )
return - V_123 ;
V_134 = V_5 -> V_153 ;
V_5 -> V_153 = 0 ;
if ( V_139 > V_154 || V_22 > V_155 )
return - V_156 ;
V_148 = ( V_139 ? V_139 : V_5 -> V_34 ) ;
V_149 = ( V_22 ? V_22 : V_5 -> V_30 ) ;
V_150 = V_148 << 1 ;
V_151 = V_150 * V_149 ;
if ( V_148 == V_5 -> V_34 && V_149 == V_5 -> V_30 )
return 0 ;
if ( V_151 > ( 4 << 20 ) )
return - V_156 ;
V_152 = F_56 ( V_151 , V_157 ) ;
if ( ! V_152 )
return - V_125 ;
if ( V_5 == V_86 )
F_35 () ;
V_146 = V_5 -> V_30 ;
V_147 = V_5 -> V_33 ;
V_135 = F_60 ( V_5 , V_148 , V_149 , V_134 ) ;
if ( V_135 ) {
F_59 ( V_152 ) ;
return V_135 ;
}
V_5 -> V_30 = V_149 ;
V_5 -> V_34 = V_148 ;
V_5 -> V_33 = V_150 ;
V_5 -> V_75 = V_151 ;
V_143 = F_62 ( V_147 , V_150 ) ;
V_144 = V_150 - V_143 ;
V_140 = V_5 -> V_18 ;
V_141 = ( long ) V_152 ;
V_142 = V_141 + V_151 ;
if ( V_5 -> V_85 > V_149 ) {
if ( V_146 - V_5 -> V_85 < V_149 ) {
V_140 += ( V_146 - V_149 ) * V_147 ;
} else {
V_140 += ( V_5 -> V_85 - V_149 / 2 ) * V_147 ;
}
}
V_145 = V_140 + V_147 * F_62 ( V_146 , V_149 ) ;
F_26 ( V_5 ) ;
while ( V_140 < V_145 ) {
F_32 ( ( unsigned short * ) V_141 ,
( unsigned short * ) V_140 , V_143 ) ;
if ( V_144 )
F_17 ( ( void * ) ( V_141 + V_143 ) ,
V_5 -> V_35 , V_144 ) ;
V_140 += V_147 ;
V_141 += V_150 ;
}
if ( V_142 > V_141 )
F_17 ( ( void * ) V_141 , V_5 -> V_35 ,
V_142 - V_141 ) ;
F_59 ( V_5 -> V_94 ) ;
V_5 -> V_94 = V_152 ;
V_5 -> V_75 = V_151 ;
F_36 ( V_5 ) ;
V_5 -> V_158 = 0 ;
V_5 -> V_159 = V_5 -> V_30 ;
F_63 ( V_5 , V_5 -> V_80 , V_5 -> V_85 ) ;
F_64 ( V_5 ) ;
if ( V_138 ) {
struct V_160 V_161 ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_161 . V_162 = V_5 -> V_30 ;
V_161 . V_163 = V_5 -> V_34 ;
V_161 . V_164 = V_5 -> V_165 ;
F_65 ( V_138 , & V_161 ) ;
}
if ( F_10 ( V_5 ) )
F_66 ( V_5 ) ;
F_67 ( V_166 , V_5 -> V_12 , V_5 -> V_12 ) ;
return V_135 ;
}
int F_68 ( struct V_4 * V_5 , unsigned int V_139 , unsigned int V_167 )
{
return F_61 ( V_5 -> V_126 . V_138 , V_5 , V_139 , V_167 ) ;
}
static int F_69 ( struct V_137 * V_138 , struct V_160 * V_161 )
{
struct V_4 * V_5 = V_138 -> V_168 ;
int V_169 ;
F_70 () ;
V_169 = F_61 ( V_138 , V_5 , V_161 -> V_163 , V_161 -> V_162 ) ;
F_71 () ;
return V_169 ;
}
struct V_4 * F_72 ( unsigned int V_122 )
{
struct V_4 * V_5 = NULL ;
F_22 () ;
if ( F_45 ( V_122 ) ) {
struct V_7 V_8 ;
V_8 . V_5 = V_5 = V_101 [ V_122 ] . V_28 ;
F_6 ( & V_3 , V_170 , & V_8 ) ;
F_73 ( V_122 ) ;
V_5 -> V_19 -> V_171 ( V_5 ) ;
F_74 ( V_5 -> V_172 ) ;
F_47 ( V_5 -> V_19 -> V_111 ) ;
F_59 ( V_5 -> V_94 ) ;
V_101 [ V_122 ] . V_28 = NULL ;
}
return V_5 ;
}
static void F_63 ( struct V_4 * V_5 , int V_173 , int V_174 )
{
int V_175 , V_176 ;
if ( V_173 < 0 )
V_5 -> V_80 = 0 ;
else {
if ( V_173 >= V_5 -> V_34 )
V_5 -> V_80 = V_5 -> V_34 - 1 ;
else
V_5 -> V_80 = V_173 ;
}
if ( V_5 -> V_177 ) {
V_175 = V_5 -> V_158 ;
V_176 = V_5 -> V_159 ;
} else {
V_175 = 0 ;
V_176 = V_5 -> V_30 ;
}
if ( V_174 < V_175 )
V_5 -> V_85 = V_175 ;
else if ( V_174 >= V_176 )
V_5 -> V_85 = V_176 - 1 ;
else
V_5 -> V_85 = V_174 ;
V_5 -> V_79 = V_5 -> V_18 + V_5 -> V_85 * V_5 -> V_33 + ( V_5 -> V_80 << 1 ) ;
V_5 -> V_81 = 0 ;
}
static void F_75 ( struct V_4 * V_5 , int V_173 , int V_174 )
{
F_63 ( V_5 , V_173 , V_5 -> V_177 ? ( V_5 -> V_158 + V_174 ) : V_174 ) ;
}
void F_76 ( struct V_4 * V_5 )
{
F_12 ( - ( V_5 -> V_30 / 2 ) ) ;
}
void F_77 ( struct V_4 * V_5 , int V_22 )
{
if ( ! V_22 )
V_22 = V_5 -> V_30 / 2 ;
F_12 ( V_22 ) ;
}
static void F_78 ( struct V_4 * V_5 )
{
if ( V_5 -> V_85 + 1 == V_5 -> V_159 )
F_15 ( V_5 , V_5 -> V_158 , V_5 -> V_159 , 1 ) ;
else if ( V_5 -> V_85 < V_5 -> V_30 - 1 ) {
V_5 -> V_85 ++ ;
V_5 -> V_79 += V_5 -> V_33 ;
}
V_5 -> V_81 = 0 ;
F_5 ( V_5 , '\n' ) ;
}
static void F_79 ( struct V_4 * V_5 )
{
if ( V_5 -> V_85 == V_5 -> V_158 )
F_18 ( V_5 , V_5 -> V_158 , V_5 -> V_159 , 1 ) ;
else if ( V_5 -> V_85 > 0 ) {
V_5 -> V_85 -- ;
V_5 -> V_79 -= V_5 -> V_33 ;
}
V_5 -> V_81 = 0 ;
}
static inline void F_80 ( struct V_4 * V_5 )
{
V_5 -> V_79 -= V_5 -> V_80 << 1 ;
V_5 -> V_81 = V_5 -> V_80 = 0 ;
F_5 ( V_5 , '\r' ) ;
}
static inline void F_81 ( struct V_4 * V_5 )
{
if ( V_5 -> V_80 ) {
V_5 -> V_79 -= 2 ;
V_5 -> V_80 -- ;
V_5 -> V_81 = 0 ;
F_5 ( V_5 , '\b' ) ;
}
}
static inline void F_82 ( struct V_4 * V_5 )
{
}
static void F_83 ( struct V_4 * V_5 , int V_178 )
{
unsigned int V_39 ;
unsigned short * V_38 ;
switch ( V_178 ) {
case 0 :
V_39 = ( V_5 -> V_95 - V_5 -> V_79 ) >> 1 ;
V_38 = ( unsigned short * ) V_5 -> V_79 ;
break;
case 1 :
V_39 = ( ( V_5 -> V_79 - V_5 -> V_18 ) >> 1 ) + 1 ;
V_38 = ( unsigned short * ) V_5 -> V_18 ;
break;
case 3 :
F_17 ( V_5 -> V_94 , V_5 -> V_35 ,
V_5 -> V_75 ) ;
F_36 ( V_5 ) ;
if ( F_10 ( V_5 ) )
F_66 ( V_5 ) ;
case 2 :
V_39 = V_5 -> V_34 * V_5 -> V_30 ;
V_38 = ( unsigned short * ) V_5 -> V_18 ;
break;
default:
return;
}
F_17 ( V_38 , V_5 -> V_35 , 2 * V_39 ) ;
if ( F_9 ( V_5 ) )
F_19 ( V_5 , ( unsigned long ) V_38 , V_39 ) ;
V_5 -> V_81 = 0 ;
}
static void F_84 ( struct V_4 * V_5 , int V_178 )
{
unsigned int V_39 ;
unsigned short * V_38 ;
switch ( V_178 ) {
case 0 :
V_39 = V_5 -> V_34 - V_5 -> V_80 ;
V_38 = ( unsigned short * ) V_5 -> V_79 ;
break;
case 1 :
V_38 = ( unsigned short * ) ( V_5 -> V_79 - ( V_5 -> V_80 << 1 ) ) ;
V_39 = V_5 -> V_80 + 1 ;
break;
case 2 :
V_38 = ( unsigned short * ) ( V_5 -> V_79 - ( V_5 -> V_80 << 1 ) ) ;
V_39 = V_5 -> V_34 ;
break;
default:
return;
}
F_17 ( V_38 , V_5 -> V_35 , 2 * V_39 ) ;
V_5 -> V_81 = 0 ;
if ( F_9 ( V_5 ) )
F_19 ( V_5 , ( unsigned long ) V_38 , V_39 ) ;
}
static void F_85 ( struct V_4 * V_5 , int V_178 )
{
int V_39 ;
if ( ! V_178 )
V_178 ++ ;
V_39 = ( V_178 > V_5 -> V_34 - V_5 -> V_80 ) ? ( V_5 -> V_34 - V_5 -> V_80 ) : V_178 ;
F_17 ( ( unsigned short * ) V_5 -> V_79 , V_5 -> V_35 , 2 * V_39 ) ;
if ( F_9 ( V_5 ) )
V_5 -> V_19 -> V_179 ( V_5 , V_5 -> V_85 , V_5 -> V_80 , 1 , V_39 ) ;
V_5 -> V_81 = 0 ;
}
static void F_86 ( struct V_4 * V_5 )
{
V_5 -> V_63 = 1 ;
V_5 -> V_68 = 0 ;
V_5 -> V_65 = 0 ;
V_5 -> V_66 = 0 ;
V_5 -> V_64 = 0 ;
V_5 -> V_62 = V_5 -> V_180 ;
}
static void F_87 ( int V_82 , struct V_181 * V_9 )
{
if ( V_82 < 8 ) {
V_9 -> V_182 = V_82 & 1 ? 0xaa : 0x00 ;
V_9 -> V_183 = V_82 & 2 ? 0xaa : 0x00 ;
V_9 -> V_26 = V_82 & 4 ? 0xaa : 0x00 ;
} else if ( V_82 < 16 ) {
V_9 -> V_182 = V_82 & 1 ? 0xff : 0x55 ;
V_9 -> V_183 = V_82 & 2 ? 0xff : 0x55 ;
V_9 -> V_26 = V_82 & 4 ? 0xff : 0x55 ;
} else if ( V_82 < 232 ) {
V_9 -> V_182 = ( V_82 - 16 ) / 36 * 85 / 2 ;
V_9 -> V_183 = ( V_82 - 16 ) / 6 % 6 * 85 / 2 ;
V_9 -> V_26 = ( V_82 - 16 ) % 6 * 85 / 2 ;
} else
V_9 -> V_182 = V_9 -> V_183 = V_9 -> V_26 = V_82 * 10 - 2312 ;
}
static void F_88 ( struct V_4 * V_5 , const struct V_181 * V_9 )
{
T_2 V_184 = 0 , V_185 = F_89 ( V_9 -> V_182 , V_9 -> V_183 , V_9 -> V_26 ) ;
if ( V_9 -> V_182 > V_185 / 2 )
V_184 |= 4 ;
if ( V_9 -> V_183 > V_185 / 2 )
V_184 |= 2 ;
if ( V_9 -> V_26 > V_185 / 2 )
V_184 |= 1 ;
if ( V_184 == 7 && V_185 <= 0x55 ) {
V_184 = 0 ;
V_5 -> V_63 = 2 ;
} else if ( V_185 > 0xaa )
V_5 -> V_63 = 2 ;
else
V_5 -> V_63 = 1 ;
V_5 -> V_62 = ( V_5 -> V_62 & 0xf0 ) | V_184 ;
}
static void F_90 ( struct V_4 * V_5 , const struct V_181 * V_9 )
{
V_5 -> V_62 = ( V_5 -> V_62 & 0x0f )
| ( V_9 -> V_182 & 0x80 ) >> 1 | ( V_9 -> V_183 & 0x80 ) >> 2 | ( V_9 -> V_26 & 0x80 ) >> 3 ;
}
static int F_91 ( struct V_4 * V_5 , int V_82 ,
void (* F_92)( struct V_4 * V_5 , const struct V_181 * V_9 ) )
{
struct V_181 V_9 ;
V_82 ++ ;
if ( V_82 > V_5 -> V_186 )
return V_82 ;
if ( V_5 -> V_187 [ V_82 ] == 5 && V_82 + 1 <= V_5 -> V_186 ) {
V_82 ++ ;
F_87 ( V_5 -> V_187 [ V_82 ] , & V_9 ) ;
} else if ( V_5 -> V_187 [ V_82 ] == 2 && V_82 + 3 <= V_5 -> V_186 ) {
V_9 . V_182 = V_5 -> V_187 [ V_82 + 1 ] ;
V_9 . V_183 = V_5 -> V_187 [ V_82 + 2 ] ;
V_9 . V_26 = V_5 -> V_187 [ V_82 + 3 ] ;
V_82 += 3 ;
} else
return V_82 ;
F_92 ( V_5 , & V_9 ) ;
return V_82 ;
}
static void F_93 ( struct V_4 * V_5 )
{
int V_82 ;
for ( V_82 = 0 ; V_82 <= V_5 -> V_186 ; V_82 ++ )
switch ( V_5 -> V_187 [ V_82 ] ) {
case 0 :
F_86 ( V_5 ) ;
break;
case 1 :
V_5 -> V_63 = 2 ;
break;
case 2 :
V_5 -> V_63 = 0 ;
break;
case 3 :
V_5 -> V_68 = 1 ;
break;
case 4 :
V_5 -> V_65 = 1 ;
break;
case 5 :
V_5 -> V_64 = 1 ;
break;
case 7 :
V_5 -> V_66 = 1 ;
break;
case 10 :
V_5 -> V_188 = F_94 ( V_5 -> V_189 == 0
? V_5 -> V_190
: V_5 -> V_191 , V_5 ) ;
V_5 -> V_192 = 0 ;
V_5 -> V_193 = 0 ;
break;
case 11 :
V_5 -> V_188 = F_94 ( V_194 , V_5 ) ;
V_5 -> V_192 = 1 ;
V_5 -> V_193 = 0 ;
break;
case 12 :
V_5 -> V_188 = F_94 ( V_194 , V_5 ) ;
V_5 -> V_192 = 1 ;
V_5 -> V_193 = 1 ;
break;
case 21 :
case 22 :
V_5 -> V_63 = 1 ;
break;
case 23 :
V_5 -> V_68 = 0 ;
break;
case 24 :
V_5 -> V_65 = 0 ;
break;
case 25 :
V_5 -> V_64 = 0 ;
break;
case 27 :
V_5 -> V_66 = 0 ;
break;
case 38 :
V_82 = F_91 ( V_5 , V_82 , F_88 ) ;
break;
case 48 :
V_82 = F_91 ( V_5 , V_82 , F_90 ) ;
break;
case 39 :
V_5 -> V_62 = ( V_5 -> V_180 & 0x0f ) |
( V_5 -> V_62 & 0xf0 ) ;
break;
case 49 :
V_5 -> V_62 = ( V_5 -> V_180 & 0xf0 ) |
( V_5 -> V_62 & 0x0f ) ;
break;
default:
if ( V_5 -> V_187 [ V_82 ] >= 90 && V_5 -> V_187 [ V_82 ] <= 107 ) {
if ( V_5 -> V_187 [ V_82 ] < 100 )
V_5 -> V_63 = 2 ;
V_5 -> V_187 [ V_82 ] -= 60 ;
}
if ( V_5 -> V_187 [ V_82 ] >= 30 && V_5 -> V_187 [ V_82 ] <= 37 )
V_5 -> V_62 = V_195 [ V_5 -> V_187 [ V_82 ] - 30 ]
| ( V_5 -> V_62 & 0xf0 ) ;
else if ( V_5 -> V_187 [ V_82 ] >= 40 && V_5 -> V_187 [ V_82 ] <= 47 )
V_5 -> V_62 = ( V_195 [ V_5 -> V_187 [ V_82 ] - 40 ] << 4 )
| ( V_5 -> V_62 & 0x0f ) ;
break;
}
F_26 ( V_5 ) ;
}
static void F_95 ( const char * V_17 , struct V_196 * V_126 )
{
while ( * V_17 ) {
F_96 ( V_126 , * V_17 , 0 ) ;
V_17 ++ ;
}
F_97 ( V_126 ) ;
}
static void F_98 ( struct V_4 * V_5 , struct V_137 * V_138 )
{
char V_197 [ 40 ] ;
sprintf ( V_197 , L_2 , V_5 -> V_85 + ( V_5 -> V_177 ? V_5 -> V_158 + 1 : 1 ) , V_5 -> V_80 + 1 ) ;
F_95 ( V_197 , V_138 -> V_126 ) ;
}
static inline void F_99 ( struct V_137 * V_138 )
{
F_95 ( L_3 , V_138 -> V_126 ) ;
}
static inline void F_100 ( struct V_137 * V_138 )
{
F_95 ( V_198 , V_138 -> V_126 ) ;
}
void F_101 ( struct V_137 * V_138 , int V_199 , int V_200 , int V_201 )
{
char V_197 [ 8 ] ;
sprintf ( V_197 , L_4 , ( char ) ( ' ' + V_199 ) , ( char ) ( '!' + V_200 ) ,
( char ) ( '!' + V_201 ) ) ;
F_95 ( V_197 , V_138 -> V_126 ) ;
}
int F_102 ( void )
{
return V_101 [ V_13 ] . V_28 -> V_202 ;
}
static void F_103 ( struct V_4 * V_5 , int V_203 )
{
int V_82 ;
for ( V_82 = 0 ; V_82 <= V_5 -> V_186 ; V_82 ++ )
if ( V_5 -> V_204 ) {
switch( V_5 -> V_187 [ V_82 ] ) {
case 1 :
if ( V_203 )
F_104 ( V_5 , V_205 ) ;
else
F_105 ( V_5 , V_205 ) ;
break;
case 3 :
#if 0
vc_resize(deccolm ? 132 : 80, vc->vc_rows);
#endif
break;
case 5 :
if ( V_5 -> V_67 != V_203 ) {
V_5 -> V_67 = V_203 ;
F_27 ( V_5 , 0 , V_5 -> V_75 , 0 ) ;
F_26 ( V_5 ) ;
}
break;
case 6 :
V_5 -> V_177 = V_203 ;
F_75 ( V_5 , 0 , 0 ) ;
break;
case 7 :
V_5 -> V_206 = V_203 ;
break;
case 8 :
if ( V_203 )
F_104 ( V_5 , V_207 ) ;
else
F_105 ( V_5 , V_207 ) ;
break;
case 9 :
V_5 -> V_202 = V_203 ? 1 : 0 ;
break;
case 25 :
V_5 -> V_91 = V_203 ;
break;
case 1000 :
V_5 -> V_202 = V_203 ? 2 : 0 ;
break;
}
} else {
switch( V_5 -> V_187 [ V_82 ] ) {
case 3 :
V_5 -> V_192 = V_203 ;
break;
case 4 :
V_5 -> V_208 = V_203 ;
break;
case 20 :
if ( V_203 )
F_104 ( V_5 , V_209 ) ;
else
F_105 ( V_5 , V_209 ) ;
break;
}
}
}
static void F_106 ( struct V_4 * V_5 )
{
switch( V_5 -> V_187 [ 0 ] ) {
case 1 :
if ( V_5 -> V_57 &&
V_5 -> V_187 [ 1 ] < 16 ) {
V_5 -> V_59 = V_195 [ V_5 -> V_187 [ 1 ] ] ;
if ( V_5 -> V_65 )
F_26 ( V_5 ) ;
}
break;
case 2 :
if ( V_5 -> V_57 &&
V_5 -> V_187 [ 1 ] < 16 ) {
V_5 -> V_210 = V_195 [ V_5 -> V_187 [ 1 ] ] ;
if ( V_5 -> V_63 == 0 )
F_26 ( V_5 ) ;
}
break;
case 8 :
V_5 -> V_180 = V_5 -> V_61 ;
if ( V_5 -> V_60 == 0x100 )
V_5 -> V_180 >>= 1 ;
F_86 ( V_5 ) ;
F_26 ( V_5 ) ;
break;
case 9 :
V_211 = ( ( V_5 -> V_187 [ 1 ] < 60 ) ? V_5 -> V_187 [ 1 ] : 60 ) * 60 ;
F_107 () ;
break;
case 10 :
if ( V_5 -> V_186 >= 1 )
V_5 -> V_212 = V_5 -> V_187 [ 1 ] ;
else
V_5 -> V_212 = V_213 ;
break;
case 11 :
if ( V_5 -> V_186 >= 1 )
V_5 -> V_214 = ( V_5 -> V_187 [ 1 ] < 2000 ) ?
F_108 ( V_5 -> V_187 [ 1 ] ) : 0 ;
else
V_5 -> V_214 = V_215 ;
break;
case 12 :
if ( V_5 -> V_187 [ 1 ] >= 1 && F_45 ( V_5 -> V_187 [ 1 ] - 1 ) )
F_109 ( V_5 -> V_187 [ 1 ] - 1 ) ;
break;
case 13 :
F_107 () ;
break;
case 14 :
V_216 = ( ( V_5 -> V_187 [ 1 ] < 60 ) ? V_5 -> V_187 [ 1 ] : 60 ) * 60 * V_217 ;
break;
case 15 :
F_109 ( V_218 ) ;
break;
case 16 :
if ( V_5 -> V_186 >= 1 && V_5 -> V_187 [ 1 ] >= 50 &&
V_5 -> V_187 [ 1 ] <= V_219 )
V_5 -> V_118 = V_5 -> V_187 [ 1 ] ;
else
V_5 -> V_118 = V_119 ;
break;
}
}
static void F_110 ( struct V_4 * V_5 , unsigned int V_27 )
{
if ( V_27 > V_5 -> V_34 - V_5 -> V_80 )
V_27 = V_5 -> V_34 - V_5 -> V_80 ;
else if ( ! V_27 )
V_27 = 1 ;
F_30 ( V_5 , V_27 ) ;
}
static void F_111 ( struct V_4 * V_5 , unsigned int V_27 )
{
if ( V_27 > V_5 -> V_30 - V_5 -> V_85 )
V_27 = V_5 -> V_30 - V_5 -> V_85 ;
else if ( ! V_27 )
V_27 = 1 ;
F_18 ( V_5 , V_5 -> V_85 , V_5 -> V_159 , V_27 ) ;
V_5 -> V_81 = 0 ;
}
static void F_112 ( struct V_4 * V_5 , unsigned int V_27 )
{
if ( V_27 > V_5 -> V_34 - V_5 -> V_80 )
V_27 = V_5 -> V_34 - V_5 -> V_80 ;
else if ( ! V_27 )
V_27 = 1 ;
F_31 ( V_5 , V_27 ) ;
}
static void F_113 ( struct V_4 * V_5 , unsigned int V_27 )
{
if ( V_27 > V_5 -> V_30 - V_5 -> V_85 )
V_27 = V_5 -> V_30 - V_5 -> V_85 ;
else if ( ! V_27 )
V_27 = 1 ;
F_15 ( V_5 , V_5 -> V_85 , V_5 -> V_159 , V_27 ) ;
V_5 -> V_81 = 0 ;
}
static void F_64 ( struct V_4 * V_5 )
{
V_5 -> V_220 = V_5 -> V_80 ;
V_5 -> V_221 = V_5 -> V_85 ;
V_5 -> V_222 = V_5 -> V_63 ;
V_5 -> V_223 = V_5 -> V_68 ;
V_5 -> V_224 = V_5 -> V_65 ;
V_5 -> V_225 = V_5 -> V_64 ;
V_5 -> V_226 = V_5 -> V_66 ;
V_5 -> V_227 = V_5 -> V_189 ;
V_5 -> V_228 = V_5 -> V_62 ;
V_5 -> V_229 = V_5 -> V_190 ;
V_5 -> V_230 = V_5 -> V_191 ;
}
static void F_114 ( struct V_4 * V_5 )
{
F_63 ( V_5 , V_5 -> V_220 , V_5 -> V_221 ) ;
V_5 -> V_63 = V_5 -> V_222 ;
V_5 -> V_68 = V_5 -> V_223 ;
V_5 -> V_65 = V_5 -> V_224 ;
V_5 -> V_64 = V_5 -> V_225 ;
V_5 -> V_66 = V_5 -> V_226 ;
V_5 -> V_189 = V_5 -> V_227 ;
V_5 -> V_62 = V_5 -> V_228 ;
V_5 -> V_190 = V_5 -> V_229 ;
V_5 -> V_191 = V_5 -> V_230 ;
V_5 -> V_188 = F_94 ( V_5 -> V_189 ? V_5 -> V_191 : V_5 -> V_190 , V_5 ) ;
F_26 ( V_5 ) ;
V_5 -> V_81 = 0 ;
}
static void F_115 ( struct V_4 * V_5 , int V_231 )
{
V_5 -> V_158 = 0 ;
V_5 -> V_159 = V_5 -> V_30 ;
V_5 -> V_232 = V_233 ;
V_5 -> V_204 = 0 ;
V_5 -> V_188 = F_94 ( V_234 , V_5 ) ;
V_5 -> V_190 = V_234 ;
V_5 -> V_191 = V_235 ;
V_5 -> V_189 = 0 ;
V_5 -> V_81 = 0 ;
V_5 -> V_202 = 0 ;
V_5 -> V_236 = V_237 ;
V_5 -> V_238 = 0 ;
V_5 -> V_192 = 0 ;
V_5 -> V_193 = 0 ;
V_5 -> V_67 = 0 ;
V_5 -> V_177 = 0 ;
V_5 -> V_206 = 1 ;
V_5 -> V_91 = V_130 ;
V_5 -> V_208 = 0 ;
F_116 ( V_5 -> V_12 ) ;
V_5 -> V_83 = V_239 ;
V_5 -> V_78 = V_5 -> V_121 ;
F_86 ( V_5 ) ;
F_26 ( V_5 ) ;
V_5 -> V_240 [ 0 ] = 0x01010100 ;
V_5 -> V_240 [ 1 ] =
V_5 -> V_240 [ 2 ] =
V_5 -> V_240 [ 3 ] =
V_5 -> V_240 [ 4 ] =
V_5 -> V_240 [ 5 ] =
V_5 -> V_240 [ 6 ] =
V_5 -> V_240 [ 7 ] = 0x01010101 ;
V_5 -> V_212 = V_213 ;
V_5 -> V_214 = V_215 ;
V_5 -> V_118 = V_119 ;
F_63 ( V_5 , 0 , 0 ) ;
F_64 ( V_5 ) ;
if ( V_231 )
F_83 ( V_5 , 2 ) ;
}
static void F_117 ( struct V_137 * V_138 , struct V_4 * V_5 , int V_9 )
{
if ( V_5 -> V_232 == V_241 && V_9 >= 8 && V_9 <= 13 )
return;
switch ( V_9 ) {
case 0 :
return;
case 7 :
if ( V_5 -> V_232 == V_241 )
V_5 -> V_232 = V_233 ;
else if ( V_5 -> V_214 )
F_118 ( V_5 -> V_212 , V_5 -> V_214 ) ;
return;
case 8 :
F_81 ( V_5 ) ;
return;
case 9 :
V_5 -> V_79 -= ( V_5 -> V_80 << 1 ) ;
while ( V_5 -> V_80 < V_5 -> V_34 - 1 ) {
V_5 -> V_80 ++ ;
if ( V_5 -> V_240 [ V_5 -> V_80 >> 5 ] & ( 1 << ( V_5 -> V_80 & 31 ) ) )
break;
}
V_5 -> V_79 += ( V_5 -> V_80 << 1 ) ;
F_5 ( V_5 , '\t' ) ;
return;
case 10 : case 11 : case 12 :
F_78 ( V_5 ) ;
if ( ! F_119 ( V_5 , V_209 ) )
return;
case 13 :
F_80 ( V_5 ) ;
return;
case 14 :
V_5 -> V_189 = 1 ;
V_5 -> V_188 = F_94 ( V_5 -> V_191 , V_5 ) ;
V_5 -> V_192 = 1 ;
return;
case 15 :
V_5 -> V_189 = 0 ;
V_5 -> V_188 = F_94 ( V_5 -> V_190 , V_5 ) ;
V_5 -> V_192 = 0 ;
return;
case 24 : case 26 :
V_5 -> V_232 = V_233 ;
return;
case 27 :
V_5 -> V_232 = V_242 ;
return;
case 127 :
F_82 ( V_5 ) ;
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
F_80 ( V_5 ) ;
F_78 ( V_5 ) ;
return;
case 'M' :
F_79 ( V_5 ) ;
return;
case 'D' :
F_78 ( V_5 ) ;
return;
case 'H' :
V_5 -> V_240 [ V_5 -> V_80 >> 5 ] |= ( 1 << ( V_5 -> V_80 & 31 ) ) ;
return;
case 'Z' :
F_100 ( V_138 ) ;
return;
case '7' :
F_64 ( V_5 ) ;
return;
case '8' :
F_114 ( V_5 ) ;
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
F_115 ( V_5 , 1 ) ;
return;
case '>' :
F_105 ( V_5 , V_249 ) ;
return;
case '=' :
F_104 ( V_5 , V_249 ) ;
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
F_120 ( V_5 ) ;
V_5 -> V_232 = V_233 ;
} else if ( V_9 >= '0' && V_9 <= '9' )
V_5 -> V_232 = V_241 ;
else
V_5 -> V_232 = V_233 ;
return;
case V_251 :
if ( isxdigit ( V_9 ) ) {
V_5 -> V_187 [ V_5 -> V_186 ++ ] = F_121 ( V_9 ) ;
if ( V_5 -> V_186 == 7 ) {
int V_82 = V_5 -> V_187 [ 0 ] * 3 , V_252 = 1 ;
V_5 -> V_253 [ V_82 ] = 16 * V_5 -> V_187 [ V_252 ++ ] ;
V_5 -> V_253 [ V_82 ++ ] += V_5 -> V_187 [ V_252 ++ ] ;
V_5 -> V_253 [ V_82 ] = 16 * V_5 -> V_187 [ V_252 ++ ] ;
V_5 -> V_253 [ V_82 ++ ] += V_5 -> V_187 [ V_252 ++ ] ;
V_5 -> V_253 [ V_82 ] = 16 * V_5 -> V_187 [ V_252 ++ ] ;
V_5 -> V_253 [ V_82 ] += V_5 -> V_187 [ V_252 ] ;
F_41 ( V_5 ) ;
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
F_103 ( V_5 , 1 ) ;
return;
case 'l' :
F_103 ( V_5 , 0 ) ;
return;
case 'c' :
if ( V_5 -> V_204 ) {
if ( V_5 -> V_187 [ 0 ] )
V_5 -> V_83 = V_5 -> V_187 [ 0 ] | ( V_5 -> V_187 [ 1 ] << 8 ) | ( V_5 -> V_187 [ 2 ] << 16 ) ;
else
V_5 -> V_83 = V_239 ;
return;
}
break;
case 'm' :
if ( V_5 -> V_204 ) {
F_35 () ;
if ( V_5 -> V_187 [ 0 ] )
V_5 -> V_78 = V_5 -> V_187 [ 0 ] << 8 | V_5 -> V_187 [ 1 ] ;
else
V_5 -> V_78 = V_5 -> V_121 ;
return;
}
break;
case 'n' :
if ( ! V_5 -> V_204 ) {
if ( V_5 -> V_187 [ 0 ] == 5 )
F_99 ( V_138 ) ;
else if ( V_5 -> V_187 [ 0 ] == 6 )
F_98 ( V_5 , V_138 ) ;
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
F_63 ( V_5 , V_5 -> V_187 [ 0 ] , V_5 -> V_85 ) ;
return;
case 'A' :
if ( ! V_5 -> V_187 [ 0 ] )
V_5 -> V_187 [ 0 ] ++ ;
F_63 ( V_5 , V_5 -> V_80 , V_5 -> V_85 - V_5 -> V_187 [ 0 ] ) ;
return;
case 'B' : case 'e' :
if ( ! V_5 -> V_187 [ 0 ] )
V_5 -> V_187 [ 0 ] ++ ;
F_63 ( V_5 , V_5 -> V_80 , V_5 -> V_85 + V_5 -> V_187 [ 0 ] ) ;
return;
case 'C' : case 'a' :
if ( ! V_5 -> V_187 [ 0 ] )
V_5 -> V_187 [ 0 ] ++ ;
F_63 ( V_5 , V_5 -> V_80 + V_5 -> V_187 [ 0 ] , V_5 -> V_85 ) ;
return;
case 'D' :
if ( ! V_5 -> V_187 [ 0 ] )
V_5 -> V_187 [ 0 ] ++ ;
F_63 ( V_5 , V_5 -> V_80 - V_5 -> V_187 [ 0 ] , V_5 -> V_85 ) ;
return;
case 'E' :
if ( ! V_5 -> V_187 [ 0 ] )
V_5 -> V_187 [ 0 ] ++ ;
F_63 ( V_5 , 0 , V_5 -> V_85 + V_5 -> V_187 [ 0 ] ) ;
return;
case 'F' :
if ( ! V_5 -> V_187 [ 0 ] )
V_5 -> V_187 [ 0 ] ++ ;
F_63 ( V_5 , 0 , V_5 -> V_85 - V_5 -> V_187 [ 0 ] ) ;
return;
case 'd' :
if ( V_5 -> V_187 [ 0 ] )
V_5 -> V_187 [ 0 ] -- ;
F_75 ( V_5 , V_5 -> V_80 , V_5 -> V_187 [ 0 ] ) ;
return;
case 'H' : case 'f' :
if ( V_5 -> V_187 [ 0 ] )
V_5 -> V_187 [ 0 ] -- ;
if ( V_5 -> V_187 [ 1 ] )
V_5 -> V_187 [ 1 ] -- ;
F_75 ( V_5 , V_5 -> V_187 [ 1 ] , V_5 -> V_187 [ 0 ] ) ;
return;
case 'J' :
F_83 ( V_5 , V_5 -> V_187 [ 0 ] ) ;
return;
case 'K' :
F_84 ( V_5 , V_5 -> V_187 [ 0 ] ) ;
return;
case 'L' :
F_111 ( V_5 , V_5 -> V_187 [ 0 ] ) ;
return;
case 'M' :
F_113 ( V_5 , V_5 -> V_187 [ 0 ] ) ;
return;
case 'P' :
F_112 ( V_5 , V_5 -> V_187 [ 0 ] ) ;
return;
case 'c' :
if ( ! V_5 -> V_187 [ 0 ] )
F_100 ( V_138 ) ;
return;
case 'g' :
if ( ! V_5 -> V_187 [ 0 ] )
V_5 -> V_240 [ V_5 -> V_80 >> 5 ] &= ~ ( 1 << ( V_5 -> V_80 & 31 ) ) ;
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
F_93 ( V_5 ) ;
return;
case 'q' :
if ( V_5 -> V_187 [ 0 ] < 4 )
F_122 ( V_5 -> V_12 ,
( V_5 -> V_187 [ 0 ] < 3 ) ? V_5 -> V_187 [ 0 ] : 4 ) ;
return;
case 'r' :
if ( ! V_5 -> V_187 [ 0 ] )
V_5 -> V_187 [ 0 ] ++ ;
if ( ! V_5 -> V_187 [ 1 ] )
V_5 -> V_187 [ 1 ] = V_5 -> V_30 ;
if ( V_5 -> V_187 [ 0 ] < V_5 -> V_187 [ 1 ] &&
V_5 -> V_187 [ 1 ] <= V_5 -> V_30 ) {
V_5 -> V_158 = V_5 -> V_187 [ 0 ] - 1 ;
V_5 -> V_159 = V_5 -> V_187 [ 1 ] ;
F_75 ( V_5 , 0 , 0 ) ;
}
return;
case 's' :
F_64 ( V_5 ) ;
return;
case 'u' :
F_114 ( V_5 ) ;
return;
case 'X' :
F_85 ( V_5 , V_5 -> V_187 [ 0 ] ) ;
return;
case '@' :
F_110 ( V_5 , V_5 -> V_187 [ 0 ] ) ;
return;
case ']' :
F_106 ( V_5 ) ;
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
V_5 -> V_35 =
( V_5 -> V_35 & 0xff00 ) | 'E' ;
F_83 ( V_5 , 2 ) ;
V_5 -> V_35 =
( V_5 -> V_35 & 0xff00 ) | ' ' ;
F_19 ( V_5 , V_5 -> V_18 , V_5 -> V_75 / 2 ) ;
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
V_5 -> V_188 = F_94 ( V_5 -> V_190 , V_5 ) ;
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
V_5 -> V_188 = F_94 ( V_5 -> V_191 , V_5 ) ;
V_5 -> V_232 = V_233 ;
return;
case V_241 :
return;
default:
V_5 -> V_232 = V_233 ;
}
}
static int F_123 ( T_4 V_257 , const struct V_258 * V_259 , int V_185 )
{
int F_62 = 0 ;
int V_260 ;
if ( V_257 < V_259 [ 0 ] . V_261 || V_257 > V_259 [ V_185 ] . V_262 )
return 0 ;
while ( V_185 >= F_62 ) {
V_260 = ( F_62 + V_185 ) / 2 ;
if ( V_257 > V_259 [ V_260 ] . V_262 )
F_62 = V_260 + 1 ;
else if ( V_257 < V_259 [ V_260 ] . V_261 )
V_185 = V_260 - 1 ;
else
return 1 ;
}
return 0 ;
}
static int F_124 ( T_4 V_257 )
{
static const struct V_258 V_263 [] = {
{ 0x1100 , 0x115F } , { 0x2329 , 0x232A } , { 0x2E80 , 0x303E } ,
{ 0x3040 , 0xA4CF } , { 0xAC00 , 0xD7A3 } , { 0xF900 , 0xFAFF } ,
{ 0xFE10 , 0xFE19 } , { 0xFE30 , 0xFE6F } , { 0xFF00 , 0xFF60 } ,
{ 0xFFE0 , 0xFFE6 } , { 0x20000 , 0x2FFFD } , { 0x30000 , 0x3FFFD }
} ;
return F_123 ( V_257 , V_263 , F_125 ( V_263 ) - 1 ) ;
}
static void F_126 ( struct V_4 * V_5 , unsigned long V_264 ,
unsigned long V_265 , int * V_266 )
{
if ( * V_266 < 0 )
return;
V_5 -> V_19 -> V_48 ( V_5 , ( T_1 * ) V_264 ,
( T_1 * ) V_265 - ( T_1 * ) V_264 , V_5 -> V_85 , * V_266 ) ;
* V_266 = - 1 ;
}
static int F_127 ( struct V_137 * V_138 , const unsigned char * V_197 , int V_39 )
{
int V_9 , V_267 , V_268 , V_269 = 0 , V_266 = - 1 ;
unsigned int V_122 ;
unsigned long V_264 = 0 , V_265 = 0 ;
struct V_4 * V_5 ;
unsigned char V_61 ;
struct V_7 V_8 ;
T_5 V_270 ;
T_5 V_271 ;
T_5 V_132 ;
T_1 V_272 , V_273 ;
if ( F_128 () )
return V_39 ;
F_129 () ;
F_70 () ;
V_5 = V_138 -> V_168 ;
if ( V_5 == NULL ) {
F_130 ( V_274 L_5 ) ;
F_71 () ;
return 0 ;
}
V_122 = V_5 -> V_12 ;
if ( ! F_45 ( V_122 ) ) {
F_131 ( L_6 , V_122 + 1 ) ;
F_71 () ;
return 0 ;
}
V_272 = V_5 -> V_60 ;
V_273 = V_272 ? 0x1ff : 0xff ;
if ( F_8 ( V_5 ) )
F_23 ( V_5 ) ;
V_8 . V_5 = V_5 ;
while ( ! V_138 -> V_275 && V_39 ) {
int V_276 = * V_197 ;
V_9 = V_276 ;
V_197 ++ ;
V_269 ++ ;
V_39 -- ;
V_270 = 0 ;
V_271 = 0 ;
V_132 = 1 ;
if ( V_5 -> V_232 != V_233 ) {
V_267 = V_9 ;
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
V_267 = V_9 ;
} else {
V_267 = V_188 ( V_5 , V_9 ) ;
}
V_8 . V_9 = V_267 ;
if ( F_6 ( & V_3 , V_280 ,
& V_8 ) == V_281 )
continue;
V_268 = V_267 && ( V_9 >= 32 ||
! ( V_5 -> V_192 ? ( V_282 >> V_9 ) & 1 :
V_5 -> V_236 || ( ( V_283 >> V_9 ) & 1 ) ) )
&& ( V_9 != 127 || V_5 -> V_192 )
&& ( V_9 != 128 + 27 ) ;
if ( V_5 -> V_232 == V_233 && V_268 ) {
if ( V_5 -> V_236 && ! V_5 -> V_192 ) {
if ( F_124 ( V_9 ) )
V_132 = 2 ;
}
V_267 = F_132 ( V_5 , V_267 ) ;
if ( V_267 & ~ V_273 ) {
if ( V_267 == - 1 || V_267 == - 2 ) {
continue;
}
if ( ( ! ( V_5 -> V_236 && ! V_5 -> V_192 ) || V_9 < 128 ) && ! ( V_9 & ~ V_273 ) ) {
V_267 = V_9 ;
} else {
V_267 = F_132 ( V_5 , 0xfffd ) ;
if ( V_267 < 0 ) {
V_271 = 1 ;
V_267 = F_132 ( V_5 , '?' ) ;
if ( V_267 < 0 ) V_267 = '?' ;
}
}
}
if ( ! V_271 ) {
V_61 = V_5 -> V_61 ;
} else {
if ( ! V_5 -> V_57 ) {
V_61 = ( V_5 -> V_61 ) ^ 0x08 ;
} else if ( V_5 -> V_60 == 0x100 ) {
V_61 = ( ( V_5 -> V_61 ) & 0x11 ) | ( ( ( V_5 -> V_61 ) & 0xe0 ) >> 4 ) | ( ( ( V_5 -> V_61 ) & 0x0e ) << 4 ) ;
} else {
V_61 = ( ( V_5 -> V_61 ) & 0x88 ) | ( ( ( V_5 -> V_61 ) & 0x70 ) >> 4 ) | ( ( ( V_5 -> V_61 ) & 0x07 ) << 4 ) ;
}
F_126 ( V_5 , V_264 , V_265 , & V_266 ) ;
}
while ( 1 ) {
if ( V_5 -> V_81 || V_5 -> V_208 )
F_126 ( V_5 , V_264 , V_265 ,
& V_266 ) ;
if ( V_5 -> V_81 ) {
F_80 ( V_5 ) ;
F_78 ( V_5 ) ;
}
if ( V_5 -> V_208 )
F_30 ( V_5 , 1 ) ;
F_28 ( V_272 ?
( ( V_61 << 8 ) & ~ V_272 ) + ( ( V_267 & 0x100 ) ? V_272 : 0 ) + ( V_267 & 0xff ) :
( V_61 << 8 ) + V_267 ,
( T_1 * ) V_5 -> V_79 ) ;
if ( F_9 ( V_5 ) && V_266 < 0 ) {
V_266 = V_5 -> V_80 ;
V_264 = V_5 -> V_79 ;
}
if ( V_5 -> V_80 == V_5 -> V_34 - 1 ) {
V_5 -> V_81 = V_5 -> V_206 ;
V_265 = V_5 -> V_79 + 2 ;
} else {
V_5 -> V_80 ++ ;
V_265 = ( V_5 -> V_79 += 2 ) ;
}
if ( ! -- V_132 ) break;
V_267 = F_132 ( V_5 , ' ' ) ;
if ( V_267 < 0 ) V_267 = ' ' ;
}
F_5 ( V_5 , V_9 ) ;
if ( V_271 )
F_126 ( V_5 , V_264 , V_265 , & V_266 ) ;
if ( V_270 ) {
V_270 = 0 ;
V_271 = 0 ;
V_132 = 1 ;
V_9 = V_276 ;
goto V_277;
}
continue;
}
F_126 ( V_5 , V_264 , V_265 , & V_266 ) ;
F_117 ( V_138 , V_5 , V_276 ) ;
}
F_126 ( V_5 , V_264 , V_265 , & V_266 ) ;
F_133 () ;
F_71 () ;
F_7 ( V_5 ) ;
return V_269 ;
}
static void F_134 ( struct V_284 * V_285 )
{
F_70 () ;
if ( V_286 >= 0 ) {
if ( V_286 != V_13 &&
F_45 ( V_286 ) ) {
F_23 ( V_101 [ V_13 ] . V_28 ) ;
F_135 ( V_101 [ V_286 ] . V_28 ) ;
}
V_286 = - 1 ;
}
if ( V_287 ) {
V_287 = 0 ;
F_107 () ;
}
if ( V_23 ) {
struct V_4 * V_5 = V_101 [ V_13 ] . V_28 ;
F_35 () ;
if ( V_5 -> V_89 == V_288 && V_5 -> V_19 -> V_289 )
V_5 -> V_19 -> V_289 ( V_5 , V_23 ) ;
V_23 = 0 ;
}
if ( V_290 ) {
F_136 ( 0 ) ;
V_290 = 0 ;
}
F_7 ( V_101 [ V_13 ] . V_28 ) ;
F_71 () ;
}
int F_109 ( int V_27 )
{
struct V_4 * V_5 = V_101 [ V_13 ] . V_28 ;
if ( ! F_45 ( V_27 ) || V_291 ||
( V_5 -> V_292 . V_293 == V_294 && V_5 -> V_89 == V_90 ) ) {
return - V_156 ;
}
V_286 = V_27 ;
F_13 () ;
return 0 ;
}
int F_137 ( int V_77 )
{
static int V_295 ;
if ( V_77 != - 1 )
return F_138 ( & V_295 , V_77 ) ;
else
return V_295 ;
}
static void F_139 ( struct V_296 * V_297 , const char * V_26 , unsigned V_39 )
{
struct V_4 * V_5 = V_101 [ V_13 ] . V_28 ;
unsigned char V_9 ;
static F_140 ( V_298 ) ;
const T_6 * V_38 ;
T_6 V_70 = 0 ;
T_6 V_299 ;
int V_300 ;
if ( ! V_301 )
return;
if ( ! F_141 ( & V_298 ) )
return;
V_300 = F_142 () ;
if ( V_300 && F_45 ( V_300 - 1 ) )
V_5 = V_101 [ V_300 - 1 ] . V_28 ;
V_299 = V_5 -> V_80 ;
if ( ! F_45 ( V_13 ) ) {
goto V_302;
}
if ( V_5 -> V_89 != V_288 && ! F_42 ( V_5 ) )
goto V_302;
if ( F_8 ( V_5 ) )
F_23 ( V_5 ) ;
V_38 = ( T_6 * ) V_5 -> V_79 ;
while ( V_39 -- ) {
V_9 = * V_26 ++ ;
if ( V_9 == 10 || V_9 == 13 || V_9 == 8 || V_5 -> V_81 ) {
if ( V_70 > 0 ) {
if ( F_10 ( V_5 ) )
V_5 -> V_19 -> V_48 ( V_5 , V_38 , V_70 , V_5 -> V_85 , V_5 -> V_80 ) ;
V_5 -> V_80 += V_70 ;
if ( V_5 -> V_81 )
V_5 -> V_80 -- ;
V_70 = 0 ;
}
if ( V_9 == 8 ) {
F_81 ( V_5 ) ;
V_38 = ( T_6 * ) V_5 -> V_79 ;
V_299 = V_5 -> V_80 ;
continue;
}
if ( V_9 != 13 )
F_78 ( V_5 ) ;
F_80 ( V_5 ) ;
V_38 = ( T_6 * ) V_5 -> V_79 ;
V_299 = V_5 -> V_80 ;
if ( V_9 == 10 || V_9 == 13 )
continue;
}
F_28 ( ( V_5 -> V_61 << 8 ) + V_9 , ( unsigned short * ) V_5 -> V_79 ) ;
F_5 ( V_5 , V_9 ) ;
V_70 ++ ;
if ( V_299 == V_5 -> V_34 - 1 ) {
V_5 -> V_81 = 1 ;
continue;
}
V_5 -> V_79 += 2 ;
V_299 ++ ;
}
if ( V_70 > 0 ) {
if ( F_10 ( V_5 ) )
V_5 -> V_19 -> V_48 ( V_5 , V_38 , V_70 , V_5 -> V_85 , V_5 -> V_80 ) ;
V_5 -> V_80 += V_70 ;
if ( V_5 -> V_80 == V_5 -> V_34 ) {
V_5 -> V_80 -- ;
V_5 -> V_81 = 1 ;
}
}
F_24 ( V_5 ) ;
F_7 ( V_5 ) ;
V_302:
F_143 ( & V_298 ) ;
}
static struct V_303 * F_144 ( struct V_296 * V_9 , int * V_304 )
{
* V_304 = V_9 -> V_304 ? V_9 -> V_304 - 1 : V_13 ;
return V_305 ;
}
int F_145 ( struct V_137 * V_138 , unsigned long V_306 )
{
char type , V_307 ;
char T_7 * V_17 = ( char T_7 * ) V_306 ;
int V_22 ;
int V_169 ;
if ( V_308 -> signal -> V_138 != V_138 && ! F_146 ( V_309 ) )
return - V_310 ;
if ( F_147 ( type , V_17 ) )
return - V_311 ;
V_169 = 0 ;
switch ( type )
{
case V_312 :
F_70 () ;
V_169 = F_148 ( (struct V_313 T_7 * ) ( V_17 + 1 ) , V_138 ) ;
F_71 () ;
break;
case V_314 :
V_169 = F_149 ( V_138 ) ;
break;
case V_315 :
F_70 () ;
F_150 () ;
F_71 () ;
break;
case V_316 :
F_70 () ;
V_169 = F_151 ( V_17 ) ;
F_71 () ;
break;
case V_317 :
V_307 = F_152 () ;
V_169 = F_153 ( V_307 , V_17 ) ;
break;
case V_318 :
F_70 () ;
V_307 = F_102 () ;
F_71 () ;
V_169 = F_153 ( V_307 , V_17 ) ;
break;
case V_319 :
F_70 () ;
V_169 = F_154 ( V_17 ) ;
F_71 () ;
break;
case V_320 :
V_307 = F_142 () ;
V_169 = F_153 ( V_307 , V_17 ) ;
break;
case V_321 :
if ( ! F_146 ( V_309 ) ) {
V_169 = - V_310 ;
} else {
if ( F_147 ( V_307 , V_17 + 1 ) )
V_169 = - V_311 ;
else
F_137 ( V_307 ) ;
}
break;
case V_322 :
V_169 = V_13 ;
break;
case V_323 :
if ( F_147 ( V_22 , ( V_324 T_7 * ) ( V_17 + 4 ) ) ) {
V_169 = - V_311 ;
} else {
F_70 () ;
F_77 ( V_101 [ V_13 ] . V_28 , V_22 ) ;
F_71 () ;
V_169 = 0 ;
}
break;
case V_325 :
F_70 () ;
V_326 = 1 ;
F_136 ( 0 ) ;
F_71 () ;
break;
case V_327 :
V_169 = V_14 ;
break;
default:
V_169 = - V_156 ;
break;
}
return V_169 ;
}
static int F_155 ( struct V_137 * V_138 , const unsigned char * V_197 , int V_39 )
{
int V_328 ;
V_328 = F_127 ( V_138 , V_197 , V_39 ) ;
F_156 ( V_138 ) ;
return V_328 ;
}
static int F_157 ( struct V_137 * V_138 , unsigned char V_329 )
{
if ( F_128 () )
return 0 ;
return F_127 ( V_138 , & V_329 , 1 ) ;
}
static int F_158 ( struct V_137 * V_138 )
{
if ( V_138 -> V_275 )
return 0 ;
return 32768 ;
}
static int F_159 ( struct V_137 * V_138 )
{
return 0 ;
}
static void F_160 ( struct V_137 * V_138 )
{
}
static void F_161 ( struct V_137 * V_138 )
{
struct V_4 * V_5 = V_138 -> V_168 ;
F_162 ( & V_5 -> V_330 ) ;
}
static void F_163 ( struct V_137 * V_138 )
{
int V_331 ;
if ( ! V_138 )
return;
V_331 = V_138 -> V_304 ;
if ( ! F_45 ( V_331 ) )
return;
F_164 ( V_331 ) ;
}
static void F_165 ( struct V_137 * V_138 )
{
int V_331 ;
if ( ! V_138 )
return;
V_331 = V_138 -> V_304 ;
if ( ! F_45 ( V_331 ) )
return;
F_166 ( V_331 ) ;
}
static void F_156 ( struct V_137 * V_138 )
{
struct V_4 * V_5 ;
if ( F_128 () )
return;
F_70 () ;
V_5 = V_138 -> V_168 ;
if ( V_5 )
F_24 ( V_5 ) ;
F_71 () ;
}
static int F_167 ( struct V_303 * V_332 , struct V_137 * V_138 )
{
unsigned int V_122 = V_138 -> V_304 ;
struct V_4 * V_5 ;
int V_169 ;
F_70 () ;
V_169 = F_51 ( V_122 ) ;
if ( V_169 )
goto V_333;
V_5 = V_101 [ V_122 ] . V_28 ;
if ( V_5 -> V_126 . V_138 ) {
V_169 = - V_334 ;
goto V_333;
}
V_169 = F_168 ( & V_5 -> V_126 , V_332 , V_138 ) ;
if ( V_169 )
goto V_333;
V_138 -> V_168 = V_5 ;
V_5 -> V_126 . V_138 = V_138 ;
if ( ! V_138 -> V_160 . V_162 && ! V_138 -> V_160 . V_163 ) {
V_138 -> V_160 . V_162 = V_101 [ V_122 ] . V_28 -> V_30 ;
V_138 -> V_160 . V_163 = V_101 [ V_122 ] . V_28 -> V_34 ;
}
if ( V_5 -> V_236 )
V_138 -> V_335 . V_336 |= V_337 ;
else
V_138 -> V_335 . V_336 &= ~ V_337 ;
V_333:
F_71 () ;
return V_169 ;
}
static int F_169 ( struct V_137 * V_138 , struct V_338 * V_339 )
{
return 0 ;
}
static void F_170 ( struct V_137 * V_138 , struct V_338 * V_339 )
{
}
static void F_171 ( struct V_137 * V_138 )
{
struct V_4 * V_5 = V_138 -> V_168 ;
F_172 ( V_5 == NULL ) ;
F_70 () ;
V_5 -> V_126 . V_138 = NULL ;
F_71 () ;
}
static void F_57 ( struct V_4 * V_5 , unsigned int V_167 ,
unsigned int V_139 , int V_231 )
{
int V_252 , V_340 ;
V_5 -> V_34 = V_139 ;
V_5 -> V_30 = V_167 ;
V_5 -> V_33 = V_139 << 1 ;
V_5 -> V_75 = V_5 -> V_30 * V_5 -> V_33 ;
F_36 ( V_5 ) ;
V_5 -> V_79 = V_5 -> V_18 ;
F_173 ( V_5 ) ;
for ( V_252 = V_340 = 0 ; V_252 < 16 ; V_252 ++ ) {
V_5 -> V_253 [ V_340 ++ ] = V_341 [ V_252 ] ;
V_5 -> V_253 [ V_340 ++ ] = V_342 [ V_252 ] ;
V_5 -> V_253 [ V_340 ++ ] = V_343 [ V_252 ] ;
}
V_5 -> V_180 = V_344 ;
V_5 -> V_59 = V_345 ;
V_5 -> V_58 = V_346 ;
V_5 -> V_210 = 0x08 ;
F_174 ( & V_5 -> V_330 ) ;
F_115 ( V_5 , V_231 ) ;
}
static int T_8 V_120 ( void )
{
const char * V_347 = NULL ;
struct V_4 * V_5 ;
unsigned int V_122 = 0 , V_82 ;
F_70 () ;
if ( V_112 )
V_347 = V_112 -> V_348 () ;
if ( ! V_347 ) {
V_13 = 0 ;
F_71 () ;
return 0 ;
}
for ( V_82 = 0 ; V_82 < V_349 ; V_82 ++ ) {
struct V_350 * V_350 = & V_351 [ V_82 ] ;
if ( V_350 -> V_352 == NULL ) {
V_350 -> V_352 = V_112 ;
V_350 -> V_353 = V_347 ;
V_350 -> V_354 = V_355 ;
V_350 -> V_261 = 0 ;
V_350 -> V_262 = V_108 - 1 ;
break;
}
}
for ( V_82 = 0 ; V_82 < V_108 ; V_82 ++ )
V_113 [ V_82 ] = V_112 ;
if ( V_211 ) {
V_356 = V_357 ;
F_175 ( & V_358 , V_359 + ( V_211 * V_217 ) ) ;
}
for ( V_122 = 0 ; V_122 < V_360 ; V_122 ++ ) {
V_101 [ V_122 ] . V_28 = V_5 = F_52 ( sizeof( struct V_4 ) , V_361 ) ;
F_54 ( & V_101 [ V_122 ] . V_127 , V_128 ) ;
F_53 ( & V_5 -> V_126 ) ;
F_46 ( V_5 , V_122 , 1 ) ;
V_5 -> V_94 = F_52 ( V_5 -> V_75 , V_361 ) ;
F_57 ( V_5 , V_5 -> V_30 , V_5 -> V_34 ,
V_122 || ! V_5 -> V_19 -> V_96 ) ;
}
V_122 = V_13 = 0 ;
V_114 = V_5 = V_101 [ V_122 ] . V_28 ;
F_36 ( V_5 ) ;
F_37 ( V_5 ) ;
F_63 ( V_5 , V_5 -> V_80 , V_5 -> V_85 ) ;
F_83 ( V_5 , 0 ) ;
F_66 ( V_5 ) ;
F_176 ( L_7 ,
V_5 -> V_57 ? L_8 : L_9 ,
V_347 , V_5 -> V_34 , V_5 -> V_30 ) ;
V_301 = 1 ;
F_71 () ;
#ifdef F_177
F_178 ( & V_362 ) ;
#endif
return 0 ;
}
static T_9 F_179 ( struct V_363 * V_364 ,
struct V_365 * V_366 , char * V_197 )
{
return sprintf ( V_197 , L_10 , V_13 + 1 ) ;
}
int T_8 F_180 ( const struct V_367 * V_368 )
{
F_181 ( & V_369 , V_368 ) ;
if ( F_182 ( & V_369 , F_183 ( V_370 , 0 ) , 1 ) ||
F_184 ( F_183 ( V_370 , 0 ) , 1 , L_11 ) < 0 )
F_185 ( L_12 ) ;
V_103 = F_186 ( V_371 , NULL ,
F_183 ( V_370 , 0 ) , NULL ,
V_372 , L_13 ) ;
if ( F_187 ( V_103 ) )
V_103 = NULL ;
F_188 () ;
V_305 = F_189 ( V_108 ) ;
if ( ! V_305 )
F_185 ( L_14 ) ;
V_305 -> V_373 = L_15 ;
V_305 -> V_374 = 1 ;
V_305 -> V_375 = V_370 ;
V_305 -> V_376 = 1 ;
V_305 -> type = V_377 ;
V_305 -> V_378 = V_379 ;
if ( V_237 )
V_305 -> V_378 . V_336 |= V_337 ;
V_305 -> V_380 = V_381 | V_382 ;
F_190 ( V_305 , & V_383 ) ;
if ( F_191 ( V_305 ) )
F_185 ( L_16 ) ;
F_192 () ;
F_193 () ;
#ifdef F_194
F_195 () ;
#endif
return 0 ;
}
static int F_196 ( const struct V_384 * V_385 , int V_261 , int V_262 ,
int V_386 )
{
struct V_387 * V_111 = V_385 -> V_111 ;
const char * V_353 = NULL ;
struct V_350 * V_350 ;
int V_82 , V_252 = - 1 , V_340 = - 1 , V_328 = - V_388 ;
if ( ! F_197 ( V_111 ) )
return - V_388 ;
F_22 () ;
for ( V_82 = 0 ; V_82 < V_349 ; V_82 ++ ) {
V_350 = & V_351 [ V_82 ] ;
if ( V_350 -> V_352 == V_385 ) {
V_353 = V_350 -> V_353 ;
V_328 = 0 ;
break;
}
}
if ( V_328 )
goto V_135;
if ( ! ( V_350 -> V_354 & V_355 ) ) {
V_385 -> V_348 () ;
V_350 -> V_354 |= V_355 ;
}
if ( V_386 ) {
if ( V_112 )
F_47 ( V_112 -> V_111 ) ;
F_49 ( V_111 ) ;
V_112 = V_385 ;
}
V_261 = V_185 ( V_261 , V_350 -> V_261 ) ;
V_262 = F_62 ( V_262 , V_350 -> V_262 ) ;
for ( V_82 = V_261 ; V_82 <= V_262 ; V_82 ++ ) {
int V_106 ;
struct V_4 * V_5 = V_101 [ V_82 ] . V_28 ;
if ( V_113 [ V_82 ] )
F_47 ( V_113 [ V_82 ] -> V_111 ) ;
F_49 ( V_111 ) ;
V_113 [ V_82 ] = V_385 ;
if ( ! V_5 || ! V_5 -> V_19 )
continue;
V_252 = V_82 ;
if ( F_10 ( V_5 ) ) {
V_340 = V_82 ;
F_37 ( V_5 ) ;
}
V_106 = V_5 -> V_57 ;
V_5 -> V_19 -> V_171 ( V_5 ) ;
V_5 -> V_18 = ( unsigned long ) V_5 -> V_94 ;
F_46 ( V_5 , V_82 , 0 ) ;
F_36 ( V_5 ) ;
F_26 ( V_5 ) ;
if ( V_106 != V_5 -> V_57 )
F_38 ( V_5 ) ;
}
F_176 ( L_17 ) ;
if ( ! V_386 )
F_130 ( V_389 L_18 , V_261 + 1 , V_262 + 1 ) ;
if ( V_252 >= 0 ) {
struct V_4 * V_5 = V_101 [ V_252 ] . V_28 ;
F_130 ( V_389 L_19 ,
V_5 -> V_57 ? L_8 : L_9 ,
V_353 , V_5 -> V_34 , V_5 -> V_30 ) ;
if ( V_340 >= 0 ) {
V_5 = V_101 [ V_340 ] . V_28 ;
F_66 ( V_5 ) ;
}
} else
F_130 ( V_389 L_20 , V_353 ) ;
V_328 = 0 ;
V_135:
F_47 ( V_111 ) ;
return V_328 ;
}
int F_198 ( const struct V_384 * V_385 , int V_261 , int V_262 , int V_386 )
{
struct V_387 * V_111 = V_385 -> V_111 ;
const struct V_384 * V_390 = NULL ;
struct V_350 * V_350 = NULL , * V_391 = NULL ;
int V_82 , V_328 = - V_388 ;
if ( ! F_197 ( V_111 ) )
return - V_388 ;
F_22 () ;
for ( V_82 = 0 ; V_82 < V_349 ; V_82 ++ ) {
V_350 = & V_351 [ V_82 ] ;
if ( V_350 -> V_352 == V_385 &&
V_350 -> V_354 & V_392 ) {
V_328 = 0 ;
break;
}
}
if ( V_328 )
goto V_135;
V_328 = - V_388 ;
for ( V_82 = 0 ; V_82 < V_349 ; V_82 ++ ) {
V_391 = & V_351 [ V_82 ] ;
if ( V_391 -> V_352 && V_391 -> V_352 != V_385 ) {
V_390 = V_391 -> V_352 ;
V_328 = 0 ;
break;
}
}
if ( V_328 )
goto V_135;
if ( ! F_199 ( V_385 ) )
goto V_135;
V_261 = V_185 ( V_261 , V_350 -> V_261 ) ;
V_262 = F_62 ( V_262 , V_350 -> V_262 ) ;
for ( V_82 = V_261 ; V_82 <= V_262 ; V_82 ++ ) {
if ( V_113 [ V_82 ] == V_385 ) {
F_47 ( V_385 -> V_111 ) ;
V_113 [ V_82 ] = NULL ;
}
}
if ( ! F_199 ( V_390 ) ) {
const struct V_384 * V_393 = V_112 ;
V_390 -> V_348 () ;
V_391 -> V_354 |= V_355 ;
V_112 = V_393 ;
}
if ( ! F_199 ( V_385 ) )
V_350 -> V_354 &= ~ V_355 ;
F_196 ( V_390 , V_261 , V_262 , V_386 ) ;
V_135:
F_47 ( V_111 ) ;
return V_328 ;
}
static int F_200 ( struct V_350 * V_352 )
{
const struct V_384 * V_390 = NULL , * V_385 = NULL ;
int V_82 , V_394 = 1 , V_261 = - 1 , V_262 = - 1 , V_386 = 0 ;
if ( ! V_352 -> V_352 || ! ( V_352 -> V_354 & V_392 ) )
goto V_135;
V_385 = V_352 -> V_352 ;
for ( V_82 = 0 ; V_82 < V_349 ; V_82 ++ ) {
struct V_350 * V_352 = & V_351 [ V_82 ] ;
if ( V_352 -> V_352 && ! ( V_352 -> V_354 & V_392 ) ) {
V_390 = V_352 -> V_352 ;
break;
}
}
if ( ! V_390 )
goto V_135;
while ( V_394 ) {
V_394 = 0 ;
for ( V_82 = V_352 -> V_261 ; V_82 <= V_352 -> V_262 ; V_82 ++ ) {
if ( V_113 [ V_82 ] == V_390 ) {
if ( V_261 == - 1 )
V_261 = V_82 ;
V_262 = V_82 ;
V_394 = 1 ;
} else if ( V_261 != - 1 )
break;
}
if ( V_261 == 0 && V_262 == V_108 - 1 )
V_386 = 1 ;
if ( V_261 != - 1 )
F_196 ( V_385 , V_261 , V_262 , V_386 ) ;
V_261 = - 1 ;
V_262 = - 1 ;
V_386 = 0 ;
}
V_135:
return 0 ;
}
static int F_201 ( struct V_350 * V_352 )
{
const struct V_384 * V_385 = NULL ;
int V_82 , V_394 = 1 , V_261 = - 1 , V_262 = - 1 , V_386 = 0 ;
int V_169 ;
if ( ! V_352 -> V_352 || ! ( V_352 -> V_354 & V_392 ) )
goto V_135;
V_385 = V_352 -> V_352 ;
while ( V_394 ) {
V_394 = 0 ;
for ( V_82 = V_352 -> V_261 ; V_82 <= V_352 -> V_262 ; V_82 ++ ) {
if ( V_113 [ V_82 ] == V_385 ) {
if ( V_261 == - 1 )
V_261 = V_82 ;
V_262 = V_82 ;
V_394 = 1 ;
} else if ( V_261 != - 1 )
break;
}
if ( V_261 == 0 && V_262 == V_108 - 1 )
V_386 = 1 ;
if ( V_261 != - 1 ) {
V_169 = F_198 ( V_385 , V_261 , V_262 , V_386 ) ;
if ( V_169 != 0 )
return V_169 ;
}
V_261 = - 1 ;
V_262 = - 1 ;
V_386 = 0 ;
}
V_135:
return 0 ;
}
static inline int F_200 ( struct V_350 * V_352 )
{
return 0 ;
}
static inline int F_201 ( struct V_350 * V_352 )
{
return 0 ;
}
static T_9 F_202 ( struct V_363 * V_364 , struct V_365 * V_366 ,
const char * V_197 , T_10 V_39 )
{
struct V_350 * V_352 = F_203 ( V_364 ) ;
int V_395 = F_204 ( V_197 , NULL , 0 ) ;
F_70 () ;
if ( V_395 )
F_200 ( V_352 ) ;
else
F_201 ( V_352 ) ;
F_71 () ;
return V_39 ;
}
static T_9 F_205 ( struct V_363 * V_364 , struct V_365 * V_366 ,
char * V_197 )
{
struct V_350 * V_352 = F_203 ( V_364 ) ;
int V_395 = F_199 ( V_352 -> V_352 ) ;
return snprintf ( V_197 , V_396 , L_21 , V_395 ) ;
}
static T_9 F_206 ( struct V_363 * V_364 , struct V_365 * V_366 ,
char * V_197 )
{
struct V_350 * V_352 = F_203 ( V_364 ) ;
return snprintf ( V_197 , V_396 , L_22 ,
( V_352 -> V_354 & V_392 ) ? L_23 : L_24 ,
V_352 -> V_353 ) ;
}
static int F_207 ( struct V_350 * V_352 )
{
V_352 -> V_354 |= V_397 ;
return 0 ;
}
static void F_208 ( struct V_350 * V_352 )
{
V_352 -> V_354 &= ~ V_397 ;
}
int F_199 ( const struct V_384 * V_385 )
{
int V_82 , V_398 = 0 ;
for ( V_82 = 0 ; V_82 < V_108 ; V_82 ++ ) {
if ( V_113 [ V_82 ] == V_385 ) {
V_398 = 1 ;
break;
}
}
return V_398 ;
}
int F_209 ( struct V_4 * V_5 )
{
int V_169 = 0 ;
V_399 = V_13 ;
V_400 = V_218 ;
V_401 = V_286 ;
V_402 = V_5 -> V_89 ;
V_403 = V_14 ;
V_5 -> V_89 = V_288 ;
V_14 = 0 ;
if ( V_5 -> V_19 -> F_209 )
V_169 = V_5 -> V_19 -> F_209 ( V_5 ) ;
#ifdef F_210
if ( V_5 -> V_30 < 999 ) {
int V_404 ;
char V_405 [ 4 ] ;
const char * V_406 [ 3 ] = {
L_25 ,
L_26 ,
V_405 ,
} ;
if ( F_211 ( V_406 [ 0 ] , & V_404 ) ) {
snprintf ( V_405 , 4 , L_27 , V_5 -> V_30 ) ;
F_212 ( 2 , V_406 ) ;
}
}
if ( V_5 -> V_34 < 999 ) {
int V_407 ;
char V_139 [ 4 ] ;
const char * V_406 [ 3 ] = {
L_25 ,
L_28 ,
V_139 ,
} ;
if ( F_211 ( V_406 [ 0 ] , & V_407 ) ) {
snprintf ( V_139 , 4 , L_27 , V_5 -> V_34 ) ;
F_212 ( 2 , V_406 ) ;
}
}
#endif
return V_169 ;
}
int F_213 ( void )
{
struct V_4 * V_5 ;
int V_169 = 0 ;
V_13 = V_399 ;
V_218 = V_400 ;
V_286 = V_401 ;
V_14 = V_403 ;
V_101 [ V_13 ] . V_28 -> V_89 = V_402 ;
V_5 = V_101 [ V_13 ] . V_28 ;
if ( V_5 -> V_19 -> F_213 )
V_169 = V_5 -> V_19 -> F_213 ( V_5 ) ;
return V_169 ;
}
static int F_214 ( const struct V_384 * V_385 , int V_261 , int V_262 )
{
struct V_387 * V_111 = V_385 -> V_111 ;
struct V_350 * V_350 ;
const char * V_353 ;
int V_82 , V_328 ;
F_22 () ;
if ( ! F_197 ( V_111 ) )
return - V_388 ;
for ( V_82 = 0 ; V_82 < V_349 ; V_82 ++ ) {
V_350 = & V_351 [ V_82 ] ;
if ( V_350 -> V_352 == V_385 ) {
V_328 = - V_408 ;
goto V_135;
}
}
V_353 = V_385 -> V_348 () ;
if ( ! V_353 ) {
V_328 = - V_388 ;
goto V_135;
}
V_328 = - V_156 ;
for ( V_82 = 0 ; V_82 < V_349 ; V_82 ++ ) {
V_350 = & V_351 [ V_82 ] ;
if ( V_350 -> V_352 == NULL &&
! ( V_350 -> V_354 & V_409 ) ) {
V_350 -> V_352 = V_385 ;
V_350 -> V_353 = V_353 ;
V_350 -> V_410 = V_82 ;
V_350 -> V_354 = V_392 |
V_355 ;
V_350 -> V_261 = V_261 ;
V_350 -> V_262 = V_262 ;
V_328 = 0 ;
break;
}
}
if ( V_328 )
goto V_135;
V_350 -> V_364 =
F_186 ( V_411 , NULL ,
F_183 ( 0 , V_350 -> V_410 ) ,
V_350 , V_412 ,
L_29 , V_350 -> V_410 ) ;
if ( F_187 ( V_350 -> V_364 ) ) {
F_130 ( V_413 L_30
L_31 , V_350 -> V_353 ,
F_215 ( V_350 -> V_364 ) ) ;
V_350 -> V_364 = NULL ;
} else {
F_207 ( V_350 ) ;
}
V_135:
F_47 ( V_111 ) ;
return V_328 ;
}
int F_216 ( const struct V_384 * V_385 )
{
int V_82 ;
if ( F_199 ( V_385 ) )
return - V_408 ;
if ( V_385 == V_112 )
return - V_156 ;
for ( V_82 = 0 ; V_82 < V_349 ; V_82 ++ ) {
struct V_350 * V_350 = & V_351 [ V_82 ] ;
if ( V_350 -> V_352 == V_385 ) {
V_350 -> V_352 = NULL ;
V_350 -> V_354 = V_409 ;
F_14 ( & V_414 ) ;
return 0 ;
}
}
return - V_388 ;
}
static void F_217 ( struct V_284 * V_285 )
{
int V_82 ;
F_70 () ;
for ( V_82 = 0 ; V_82 < V_349 ; V_82 ++ ) {
struct V_350 * V_350 = & V_351 [ V_82 ] ;
if ( ! ( V_350 -> V_354 & V_409 ) )
continue;
F_71 () ;
F_208 ( V_350 ) ;
F_218 ( V_411 , F_183 ( 0 , V_350 -> V_410 ) ) ;
F_70 () ;
if ( F_219 ( V_350 -> V_352 ) )
V_350 -> V_352 = NULL ;
V_350 -> V_353 = NULL ;
V_350 -> V_364 = NULL ;
V_350 -> V_410 = 0 ;
F_219 ( V_350 -> V_354 != V_409 ) ;
V_350 -> V_354 = 0 ;
V_350 -> V_261 = 0 ;
V_350 -> V_262 = 0 ;
}
F_71 () ;
}
int F_220 ( const struct V_384 * V_385 , int V_261 , int V_262 , int V_386 )
{
int V_135 ;
V_135 = F_214 ( V_385 , V_261 , V_262 ) ;
if ( V_135 == - V_408 )
V_135 = 0 ;
if ( ! V_135 )
F_196 ( V_385 , V_261 , V_262 , V_386 ) ;
return V_135 ;
}
void F_221 ( const struct V_384 * V_385 )
{
F_70 () ;
F_216 ( V_385 ) ;
F_71 () ;
}
static int T_8 F_222 ( void )
{
int V_82 ;
V_411 = F_223 ( V_415 , L_32 ) ;
if ( F_187 ( V_411 ) ) {
F_130 ( V_413 L_33
L_31 , F_215 ( V_411 ) ) ;
V_411 = NULL ;
}
for ( V_82 = 0 ; V_82 < V_349 ; V_82 ++ ) {
struct V_350 * V_352 = & V_351 [ V_82 ] ;
if ( V_352 -> V_352 && ! V_352 -> V_364 ) {
V_352 -> V_364 =
F_186 ( V_411 , NULL ,
F_183 ( 0 , V_352 -> V_410 ) ,
V_352 , V_412 ,
L_29 , V_352 -> V_410 ) ;
if ( F_187 ( V_352 -> V_364 ) ) {
F_130 ( V_413 L_34
L_35 ,
V_352 -> V_353 , F_215 ( V_352 -> V_364 ) ) ;
V_352 -> V_364 = NULL ;
} else {
F_207 ( V_352 ) ;
}
}
}
return 0 ;
}
static int F_154 ( char T_7 * V_17 )
{
unsigned int V_293 ;
if ( F_147 ( V_293 , V_17 + 1 ) )
return - V_311 ;
V_416 = ( V_293 < 4 ) ? V_293 : 0 ;
return 0 ;
}
void F_136 ( int V_417 )
{
struct V_4 * V_5 = V_101 [ V_13 ] . V_28 ;
int V_82 ;
F_22 () ;
if ( V_14 ) {
if ( V_356 == V_418 ) {
V_356 = V_419 ;
V_5 -> V_19 -> V_420 ( V_5 , V_416 + 1 , 0 ) ;
}
return;
}
if ( V_417 ) {
F_23 ( V_5 ) ;
F_37 ( V_5 ) ;
V_5 -> V_19 -> V_420 ( V_5 , - 1 , 1 ) ;
V_14 = V_13 + 1 ;
V_356 = V_419 ;
F_36 ( V_5 ) ;
return;
}
if ( V_356 != V_357 )
return;
V_356 = V_419 ;
if ( V_5 -> V_89 != V_288 ) {
V_14 = V_13 + 1 ;
return;
}
F_23 ( V_5 ) ;
F_224 ( & V_358 ) ;
V_290 = 0 ;
F_37 ( V_5 ) ;
V_82 = V_5 -> V_19 -> V_420 ( V_5 , V_216 ? 1 : ( V_416 + 1 ) , 0 ) ;
V_14 = V_13 + 1 ;
if ( V_82 )
F_36 ( V_5 ) ;
if ( V_421 && V_421 ( 1 ) )
return;
if ( V_216 && V_416 ) {
V_356 = V_418 ;
F_175 ( & V_358 , V_359 + V_216 ) ;
}
F_67 ( V_422 , V_5 -> V_12 , V_5 -> V_12 ) ;
}
void F_225 ( int V_423 )
{
struct V_4 * V_5 ;
if ( ! V_424 )
F_129 () ;
F_22 () ;
V_326 = 0 ;
if ( ! V_14 )
return;
if ( ! F_45 ( V_13 ) ) {
F_226 ( L_36 ,
V_13 + 1 ) ;
return;
}
V_5 = V_101 [ V_13 ] . V_28 ;
if ( V_5 -> V_89 != V_288 && ! F_42 ( V_5 ) )
return;
if ( V_211 ) {
F_175 ( & V_358 , V_359 + ( V_211 * V_217 ) ) ;
V_356 = V_357 ;
}
V_14 = 0 ;
if ( V_5 -> V_19 -> V_420 ( V_5 , 0 , V_423 ) || F_42 ( V_5 ) )
F_66 ( V_5 ) ;
if ( V_421 )
V_421 ( 0 ) ;
F_41 ( V_5 ) ;
F_24 ( V_5 ) ;
F_67 ( V_425 , V_5 -> V_12 , V_5 -> V_12 ) ;
}
void F_150 ( void )
{
F_225 ( 0 ) ;
}
static void F_227 ( unsigned long V_426 )
{
if ( F_228 ( ! F_229 () ) ) {
F_175 ( & V_358 , V_359 + ( V_211 * V_217 ) ) ;
return;
}
V_290 = 1 ;
F_14 ( & V_24 ) ;
}
void F_107 ( void )
{
F_22 () ;
F_129 () ;
F_230 ( & V_358 ) ;
V_290 = 0 ;
if ( V_326 || ! V_101 [ V_13 ] . V_28 || V_101 [ V_13 ] . V_28 -> V_89 == V_90 )
return;
if ( V_14 )
F_150 () ;
else if ( V_211 ) {
F_175 ( & V_358 , V_359 + ( V_211 * V_217 ) ) ;
V_356 = V_357 ;
}
}
static void F_41 ( struct V_4 * V_5 )
{
F_22 () ;
if ( V_5 -> V_89 != V_90 && V_5 -> V_19 -> V_427 )
V_5 -> V_19 -> V_427 ( V_5 , V_195 ) ;
}
int F_231 ( unsigned char T_7 * V_306 )
{
int V_82 , V_252 , V_340 ;
unsigned char V_428 [ 3 * 16 ] ;
if ( F_232 ( V_428 , V_306 , sizeof( V_428 ) ) )
return - V_311 ;
F_70 () ;
for ( V_82 = V_340 = 0 ; V_82 < 16 ; V_82 ++ ) {
V_341 [ V_82 ] = V_428 [ V_340 ++ ] ;
V_342 [ V_82 ] = V_428 [ V_340 ++ ] ;
V_343 [ V_82 ] = V_428 [ V_340 ++ ] ;
}
for ( V_82 = 0 ; V_82 < V_108 ; V_82 ++ ) {
if ( ! F_45 ( V_82 ) )
continue;
for ( V_252 = V_340 = 0 ; V_252 < 16 ; V_252 ++ ) {
V_101 [ V_82 ] . V_28 -> V_253 [ V_340 ++ ] = V_341 [ V_252 ] ;
V_101 [ V_82 ] . V_28 -> V_253 [ V_340 ++ ] = V_342 [ V_252 ] ;
V_101 [ V_82 ] . V_28 -> V_253 [ V_340 ++ ] = V_343 [ V_252 ] ;
}
F_41 ( V_101 [ V_82 ] . V_28 ) ;
}
F_71 () ;
return 0 ;
}
int F_233 ( unsigned char T_7 * V_306 )
{
int V_82 , V_340 ;
unsigned char V_428 [ 3 * 16 ] ;
F_70 () ;
for ( V_82 = V_340 = 0 ; V_82 < 16 ; V_82 ++ ) {
V_428 [ V_340 ++ ] = V_341 [ V_82 ] ;
V_428 [ V_340 ++ ] = V_342 [ V_82 ] ;
V_428 [ V_340 ++ ] = V_343 [ V_82 ] ;
}
F_71 () ;
if ( F_234 ( V_306 , V_428 , sizeof( V_428 ) ) )
return - V_311 ;
return 0 ;
}
void F_120 ( struct V_4 * V_5 )
{
int V_252 , V_340 ;
for ( V_252 = V_340 = 0 ; V_252 < 16 ; V_252 ++ ) {
V_5 -> V_253 [ V_340 ++ ] = V_341 [ V_252 ] ;
V_5 -> V_253 [ V_340 ++ ] = V_342 [ V_252 ] ;
V_5 -> V_253 [ V_340 ++ ] = V_343 [ V_252 ] ;
}
F_41 ( V_5 ) ;
}
static int F_235 ( struct V_4 * V_5 , struct V_429 * V_430 )
{
struct V_431 V_432 ;
int V_433 = - V_156 ;
int V_9 ;
if ( V_430 -> V_307 ) {
V_432 . V_307 = F_56 ( V_434 , V_124 ) ;
if ( ! V_432 . V_307 )
return - V_125 ;
} else
V_432 . V_307 = NULL ;
F_70 () ;
if ( V_5 -> V_89 != V_288 )
V_433 = - V_156 ;
else if ( V_5 -> V_19 -> F_235 )
V_433 = V_5 -> V_19 -> F_235 ( V_5 , & V_432 ) ;
else
V_433 = - V_435 ;
F_71 () ;
if ( V_433 )
goto V_436;
V_9 = ( V_432 . V_132 + 7 ) / 8 * 32 * V_432 . V_437 ;
if ( V_430 -> V_307 && V_432 . V_437 > V_430 -> V_437 )
V_433 = - V_438 ;
if ( ! ( V_430 -> V_380 & V_439 ) ) {
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
if ( V_430 -> V_307 && F_234 ( V_430 -> V_307 , V_432 . V_307 , V_9 ) )
V_433 = - V_311 ;
V_436:
F_59 ( V_432 . V_307 ) ;
return V_433 ;
}
static int F_236 ( struct V_4 * V_5 , struct V_429 * V_430 )
{
struct V_431 V_432 ;
int V_433 = - V_156 ;
int V_441 ;
if ( V_5 -> V_89 != V_288 )
return - V_156 ;
if ( ! V_430 -> V_307 )
return - V_156 ;
if ( V_430 -> V_437 > 512 )
return - V_156 ;
if ( ! V_430 -> V_133 ) {
int V_442 , V_82 ;
T_2 T_7 * V_443 = V_430 -> V_307 ;
T_2 V_444 ;
if ( ! ( V_430 -> V_380 & V_439 ) )
return - V_156 ;
for ( V_442 = 32 ; V_442 > 0 ; V_442 -- )
for ( V_82 = 0 ; V_82 < V_430 -> V_437 ; V_82 ++ ) {
if ( F_147 ( V_444 , & V_443 [ 32 * V_82 + V_442 - 1 ] ) )
return - V_311 ;
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
V_432 . V_307 = F_237 ( V_430 -> V_307 , V_441 ) ;
if ( F_187 ( V_432 . V_307 ) )
return F_215 ( V_432 . V_307 ) ;
F_70 () ;
if ( V_5 -> V_89 != V_288 )
V_433 = - V_156 ;
else if ( V_5 -> V_19 -> F_236 )
V_433 = V_5 -> V_19 -> F_236 ( V_5 , & V_432 , V_430 -> V_380 ) ;
else
V_433 = - V_435 ;
F_71 () ;
F_59 ( V_432 . V_307 ) ;
return V_433 ;
}
static int F_238 ( struct V_4 * V_5 , struct V_429 * V_430 )
{
struct V_431 V_432 = { . V_132 = V_430 -> V_132 , . V_133 = V_430 -> V_133 } ;
char V_373 [ V_446 ] ;
char * V_29 = V_373 ;
int V_433 ;
if ( ! V_430 -> V_307 )
V_29 = NULL ;
else if ( F_239 ( V_373 , V_430 -> V_307 , V_446 - 1 ) < 0 )
return - V_311 ;
else
V_373 [ V_446 - 1 ] = 0 ;
F_70 () ;
if ( V_5 -> V_89 != V_288 ) {
F_71 () ;
return - V_156 ;
}
if ( V_5 -> V_19 -> F_238 )
V_433 = V_5 -> V_19 -> F_238 ( V_5 , & V_432 , V_29 ) ;
else
V_433 = - V_435 ;
F_71 () ;
if ( ! V_433 ) {
V_430 -> V_132 = V_432 . V_132 ;
V_430 -> V_133 = V_432 . V_133 ;
}
return V_433 ;
}
static int F_240 ( struct V_4 * V_5 , struct V_429 * V_430 )
{
int V_352 = V_430 -> V_133 ;
int V_433 ;
F_70 () ;
if ( V_5 -> V_89 != V_288 )
V_433 = - V_156 ;
else if ( ! V_5 -> V_19 -> F_240 )
V_433 = - V_435 ;
else if ( V_352 < 0 || ! F_45 ( V_352 ) )
V_433 = - V_447 ;
else if ( V_352 == V_5 -> V_12 )
V_433 = 0 ;
else
V_433 = V_5 -> V_19 -> F_240 ( V_5 , V_352 ) ;
F_71 () ;
return V_433 ;
}
int F_241 ( struct V_4 * V_5 , struct V_429 * V_430 )
{
switch ( V_430 -> V_430 ) {
case V_448 :
return F_236 ( V_5 , V_430 ) ;
case V_449 :
return F_235 ( V_5 , V_430 ) ;
case V_450 :
return F_238 ( V_5 , V_430 ) ;
case V_451 :
return F_240 ( V_5 , V_430 ) ;
}
return - V_435 ;
}
T_1 F_242 ( struct V_4 * V_5 , int V_15 )
{
T_1 V_452 = F_20 ( F_11 ( V_5 , V_15 , 1 ) ) ;
T_1 V_9 = V_452 & 0xff ;
if ( V_452 & V_5 -> V_60 )
V_9 |= 0x100 ;
return V_9 ;
}
unsigned short * F_243 ( struct V_4 * V_5 , int V_453 , int V_16 )
{
return F_11 ( V_5 , 2 * V_453 , V_16 ) ;
}
void F_244 ( struct V_4 * V_5 , unsigned char * V_17 )
{
V_17 [ 0 ] = V_5 -> V_80 ;
V_17 [ 1 ] = V_5 -> V_85 ;
}
void F_245 ( struct V_4 * V_5 , unsigned char * V_17 )
{
F_23 ( V_5 ) ;
F_63 ( V_5 , V_17 [ 0 ] , V_17 [ 1 ] ) ;
F_24 ( V_5 ) ;
}
T_1 F_246 ( struct V_4 * V_5 , const T_1 * V_454 )
{
if ( ( unsigned long ) V_454 == V_5 -> V_79 && V_84 != - 1 )
return V_84 ;
return F_20 ( V_454 ) ;
}
void F_247 ( struct V_4 * V_5 , T_1 V_455 , T_1 * V_454 )
{
F_28 ( V_455 , V_454 ) ;
if ( ( unsigned long ) V_454 == V_5 -> V_79 ) {
V_84 = - 1 ;
F_33 ( V_5 ) ;
}
}
void F_248 ( struct V_4 * V_5 )
{
F_7 ( V_5 ) ;
}
