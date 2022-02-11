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
static void F_15 ( struct V_4 * V_5 , unsigned int V_25 , unsigned int V_26 ,
enum F_15 V_27 , unsigned int V_28 )
{
T_1 * V_29 , * V_30 , * V_31 ;
if ( V_25 + V_28 >= V_26 )
V_28 = V_26 - V_25 - 1 ;
if ( V_26 > V_5 -> V_32 || V_25 >= V_26 || V_28 < 1 )
return;
if ( F_10 ( V_5 ) && V_5 -> V_19 -> F_15 ( V_5 , V_25 , V_26 , V_27 , V_28 ) )
return;
V_31 = V_29 = ( T_1 * ) ( V_5 -> V_18 + V_5 -> V_33 * V_25 ) ;
V_30 = ( T_1 * ) ( V_5 -> V_18 + V_5 -> V_33 * ( V_25 + V_28 ) ) ;
if ( V_27 == V_34 ) {
V_29 = V_31 + ( V_26 - V_25 - V_28 ) * V_5 -> V_35 ;
F_16 ( V_31 , V_30 ) ;
}
F_17 ( V_30 , V_31 , ( V_26 - V_25 - V_28 ) * V_5 -> V_33 ) ;
F_18 ( V_29 , V_5 -> V_36 , V_5 -> V_33 * V_28 ) ;
}
static void F_19 ( struct V_4 * V_5 , unsigned long V_37 , int V_38 )
{
unsigned int V_39 , V_40 , V_15 ;
T_1 * V_17 ;
V_17 = ( T_1 * ) V_37 ;
if ( ! V_5 -> V_19 -> V_41 ) {
V_15 = ( V_37 - V_5 -> V_18 ) / 2 ;
V_39 = V_15 % V_5 -> V_35 ;
V_40 = V_15 / V_5 -> V_35 ;
} else {
int V_42 , V_43 ;
V_37 = V_5 -> V_19 -> V_41 ( V_5 , V_37 , & V_42 , & V_43 ) ;
V_39 = V_42 ; V_40 = V_43 ;
}
for(; ; ) {
T_1 V_44 = F_20 ( V_17 ) & 0xff00 ;
int V_45 = V_39 ;
T_1 * V_46 = V_17 ;
while ( V_39 < V_5 -> V_35 && V_38 ) {
if ( V_44 != ( F_20 ( V_17 ) & 0xff00 ) ) {
if ( V_17 > V_46 )
V_5 -> V_19 -> V_47 ( V_5 , V_46 , V_17 - V_46 , V_40 , V_45 ) ;
V_45 = V_39 ;
V_46 = V_17 ;
V_44 = F_20 ( V_17 ) & 0xff00 ;
}
V_17 ++ ;
V_39 ++ ;
V_38 -- ;
}
if ( V_17 > V_46 )
V_5 -> V_19 -> V_47 ( V_5 , V_46 , V_17 - V_46 , V_40 , V_45 ) ;
if ( ! V_38 )
break;
V_39 = 0 ;
V_40 ++ ;
if ( V_5 -> V_19 -> V_41 ) {
V_17 = ( T_1 * ) V_37 ;
V_37 = V_5 -> V_19 -> V_41 ( V_5 , V_37 , NULL , NULL ) ;
}
}
}
void F_21 ( struct V_4 * V_5 , unsigned long V_37 , int V_38 )
{
F_22 () ;
if ( F_9 ( V_5 ) ) {
F_23 ( V_5 ) ;
F_19 ( V_5 , V_37 , V_38 ) ;
F_24 ( V_5 ) ;
}
}
static T_2 F_25 ( struct V_4 * V_5 , T_2 V_48 , T_2 V_49 , T_2 V_50 ,
T_2 V_51 , T_2 V_52 , T_2 V_53 )
{
if ( V_5 -> V_19 -> V_54 )
return V_5 -> V_19 -> V_54 ( V_5 , V_48 , V_49 ,
V_50 , V_51 , V_52 , V_53 ) ;
{
T_2 V_55 = V_48 ;
if ( ! V_5 -> V_56 )
return V_49 |
( V_53 ? 2 : 0 ) |
( V_51 ? 4 : 0 ) |
( V_52 ? 8 : 0 ) |
( V_50 ? 0x80 : 0 ) ;
if ( V_53 )
V_55 = ( V_55 & 0xF0 ) | V_5 -> V_57 ;
else if ( V_51 )
V_55 = ( V_55 & 0xf0 ) | V_5 -> V_58 ;
else if ( V_49 == 0 )
V_55 = ( V_55 & 0xf0 ) | V_5 -> V_59 ;
if ( V_52 )
V_55 = ( ( V_55 ) & 0x88 ) | ( ( ( ( V_55 ) >> 4 ) | ( ( V_55 ) << 4 ) ) & 0x77 ) ;
if ( V_50 )
V_55 ^= 0x80 ;
if ( V_49 == 2 )
V_55 ^= 0x08 ;
if ( V_5 -> V_60 == 0x100 )
V_55 <<= 1 ;
return V_55 ;
}
}
static void F_26 ( struct V_4 * V_5 )
{
V_5 -> V_61 = F_25 ( V_5 , V_5 -> V_62 , V_5 -> V_63 ,
V_5 -> V_64 , V_5 -> V_65 ,
V_5 -> V_66 ^ V_5 -> V_67 , V_5 -> V_68 ) ;
V_5 -> V_36 = ( F_25 ( V_5 , V_5 -> V_62 , 1 , V_5 -> V_64 , 0 , V_5 -> V_67 , 0 ) << 8 ) | ' ' ;
}
void F_27 ( struct V_4 * V_5 , int V_15 , int V_38 , int V_16 )
{
unsigned short * V_17 ;
F_22 () ;
V_38 /= 2 ;
V_17 = F_11 ( V_5 , V_15 , V_16 ) ;
if ( V_5 -> V_19 -> V_69 ) {
V_5 -> V_19 -> V_69 ( V_5 , V_17 , V_38 ) ;
} else {
T_1 * V_46 = V_17 ;
int V_70 = V_38 ;
T_1 V_55 ;
if ( ! V_5 -> V_56 ) {
while ( V_70 -- ) {
V_55 = F_20 ( V_46 ) ;
V_55 ^= 0x0800 ;
F_28 ( V_55 , V_46 ) ;
V_46 ++ ;
}
} else if ( V_5 -> V_60 == 0x100 ) {
while ( V_70 -- ) {
V_55 = F_20 ( V_46 ) ;
V_55 = ( ( V_55 ) & 0x11ff ) | ( ( ( V_55 ) & 0xe000 ) >> 4 ) | ( ( ( V_55 ) & 0x0e00 ) << 4 ) ;
F_28 ( V_55 , V_46 ) ;
V_46 ++ ;
}
} else {
while ( V_70 -- ) {
V_55 = F_20 ( V_46 ) ;
V_55 = ( ( V_55 ) & 0x88ff ) | ( ( ( V_55 ) & 0x7000 ) >> 4 ) | ( ( ( V_55 ) & 0x0700 ) << 4 ) ;
F_28 ( V_55 , V_46 ) ;
V_46 ++ ;
}
}
}
if ( F_9 ( V_5 ) )
F_19 ( V_5 , ( unsigned long ) V_17 , V_38 ) ;
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
V_73 = ( V_15 >> 1 ) % V_5 -> V_35 ;
V_74 = ( V_15 >> 1 ) / V_5 -> V_35 ;
V_5 -> V_19 -> V_76 ( V_5 , V_77 , V_74 , V_73 ) ;
}
F_7 ( V_5 ) ;
}
}
static void F_30 ( struct V_4 * V_5 , unsigned int V_28 )
{
unsigned short * V_17 = ( unsigned short * ) V_5 -> V_79 ;
F_17 ( V_17 + V_28 , V_17 , ( V_5 -> V_35 - V_5 -> V_80 - V_28 ) * 2 ) ;
F_18 ( V_17 , V_5 -> V_36 , V_28 * 2 ) ;
V_5 -> V_81 = 0 ;
if ( F_9 ( V_5 ) )
F_19 ( V_5 , ( unsigned long ) V_17 ,
V_5 -> V_35 - V_5 -> V_80 ) ;
}
static void F_31 ( struct V_4 * V_5 , unsigned int V_28 )
{
unsigned short * V_17 = ( unsigned short * ) V_5 -> V_79 ;
F_32 ( V_17 , V_17 + V_28 , ( V_5 -> V_35 - V_5 -> V_80 - V_28 ) * 2 ) ;
F_18 ( V_17 + V_5 -> V_35 - V_5 -> V_80 - V_28 , V_5 -> V_36 ,
V_28 * 2 ) ;
V_5 -> V_81 = 0 ;
if ( F_9 ( V_5 ) )
F_19 ( V_5 , ( unsigned long ) V_17 ,
V_5 -> V_35 - V_5 -> V_80 ) ;
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
static void F_38 ( struct V_4 * V_5 )
{
F_22 () ;
if ( V_5 -> V_19 -> V_97 )
V_5 -> V_19 -> V_97 ( V_5 ) ;
}
void F_39 ( struct V_4 * V_5 )
{
unsigned short * V_17 = ( unsigned short * ) V_5 -> V_18 ;
int V_38 = V_5 -> V_75 / 2 ;
int V_98 = V_5 -> V_60 | 0xff ;
for (; V_38 > 0 ; V_38 -- , V_17 ++ ) {
F_28 ( ( F_20 ( V_17 ) & V_98 ) | ( V_5 -> V_36 & ~ V_98 ) , V_17 ) ;
}
}
void F_40 ( struct V_4 * V_5 , int V_99 )
{
int V_100 = 0 ;
F_22 () ;
if ( ! V_5 ) {
return;
}
if ( V_99 ) {
struct V_4 * V_101 = V_102 [ V_13 ] . V_30 ;
if ( V_101 == V_5 )
return;
if ( ! F_10 ( V_5 ) )
V_100 = 1 ;
* V_5 -> V_103 = V_5 ;
V_13 = V_5 -> V_12 ;
F_23 ( V_101 ) ;
if ( ! F_10 ( V_101 ) ) {
F_37 ( V_101 ) ;
F_36 ( V_101 ) ;
}
if ( V_104 )
F_41 ( & V_104 -> V_105 , NULL , L_1 ) ;
} else {
F_23 ( V_5 ) ;
V_100 = 1 ;
}
if ( V_100 ) {
int V_106 ;
int V_107 = V_5 -> V_56 ;
F_36 ( V_5 ) ;
V_106 = V_5 -> V_19 -> V_108 ( V_5 ) ;
F_42 ( V_5 ) ;
if ( V_107 != V_5 -> V_56 ) {
F_26 ( V_5 ) ;
F_39 ( V_5 ) ;
}
if ( ( V_106 && V_5 -> V_89 != V_90 ) ||
F_43 ( V_5 ) )
F_19 ( V_5 , V_5 -> V_18 , V_5 -> V_75 / 2 ) ;
}
F_24 ( V_5 ) ;
if ( V_99 ) {
F_44 () ;
F_45 () ;
F_7 ( V_5 ) ;
}
}
int F_46 ( unsigned int V_82 )
{
return ( V_82 < V_109 && V_102 [ V_82 ] . V_30 ) ;
}
static void F_47 ( struct V_4 * V_5 , int V_110 , int V_111 )
{
if ( V_5 -> V_19 )
F_48 ( V_5 -> V_19 -> V_112 ) ;
V_5 -> V_19 = V_113 ;
#ifndef F_49
if ( V_114 [ V_110 ] )
V_5 -> V_19 = V_114 [ V_110 ] ;
#endif
F_50 ( V_5 -> V_19 -> V_112 ) ;
V_5 -> V_12 = V_110 ;
V_5 -> V_103 = & V_115 ;
if ( V_5 -> V_116 )
F_51 ( V_5 ) ;
V_5 -> V_116 = & V_5 -> V_117 ;
V_5 -> V_117 = NULL ;
V_5 -> V_60 = 0 ;
V_5 -> V_78 = 0 ;
V_5 -> V_56 = 0 ;
V_5 -> V_118 = false ;
V_5 -> V_119 = V_120 ;
V_5 -> V_19 -> V_121 ( V_5 , V_111 ) ;
if ( ! V_5 -> V_78 )
V_5 -> V_78 = V_5 -> V_56 ? 0x7700 : 0x0800 ;
V_5 -> V_122 = V_5 -> V_78 ;
V_5 -> V_33 = V_5 -> V_35 << 1 ;
V_5 -> V_75 = V_5 -> V_32 * V_5 -> V_33 ;
}
int F_52 ( unsigned int V_123 )
{
struct V_7 V_8 ;
struct V_4 * V_5 ;
F_22 () ;
if ( V_123 >= V_109 )
return - V_124 ;
if ( V_102 [ V_123 ] . V_30 )
return 0 ;
V_8 . V_5 = V_5 = F_53 ( sizeof( struct V_4 ) , V_125 ) ;
if ( ! V_5 )
return - V_126 ;
V_102 [ V_123 ] . V_30 = V_5 ;
F_54 ( & V_5 -> V_127 ) ;
F_55 ( & V_102 [ V_123 ] . V_128 , V_129 ) ;
F_47 ( V_5 , V_123 , 1 ) ;
if ( ! * V_5 -> V_116 )
F_56 ( V_5 ) ;
V_5 -> V_94 = F_57 ( V_5 -> V_75 , V_125 ) ;
if ( ! V_5 -> V_94 )
goto V_130;
if ( V_131 == - 1 )
V_131 = 1 ;
F_58 ( V_5 , V_5 -> V_32 , V_5 -> V_35 , 1 ) ;
F_59 ( V_123 ) ;
F_6 ( & V_3 , V_132 , & V_8 ) ;
return 0 ;
V_130:
F_60 ( V_5 ) ;
V_102 [ V_123 ] . V_30 = NULL ;
return - V_126 ;
}
static inline int F_61 ( struct V_4 * V_5 , int V_133 , int V_134 ,
int V_135 )
{
int V_136 = 0 ;
if ( V_5 -> V_89 != V_90 && V_5 -> V_19 -> V_137 )
V_136 = V_5 -> V_19 -> V_137 ( V_5 , V_133 , V_134 , V_135 ) ;
return V_136 ;
}
static int F_62 ( struct V_138 * V_139 , struct V_4 * V_5 ,
unsigned int V_140 , unsigned int V_22 )
{
unsigned long V_141 , V_142 , V_143 , V_144 , V_145 , V_136 = 0 ;
unsigned long V_146 ;
unsigned int V_147 , V_148 ;
unsigned int V_149 , V_150 , V_151 , V_152 ;
unsigned int V_135 ;
unsigned short * V_153 ;
F_22 () ;
if ( ! V_5 )
return - V_124 ;
V_135 = V_5 -> V_154 ;
V_5 -> V_154 = 0 ;
if ( V_140 > V_155 || V_22 > V_156 )
return - V_157 ;
V_149 = ( V_140 ? V_140 : V_5 -> V_35 ) ;
V_150 = ( V_22 ? V_22 : V_5 -> V_32 ) ;
V_151 = V_149 << 1 ;
V_152 = V_151 * V_150 ;
if ( V_149 == V_5 -> V_35 && V_150 == V_5 -> V_32 )
return 0 ;
if ( V_152 > ( 4 << 20 ) )
return - V_157 ;
V_153 = F_57 ( V_152 , V_158 ) ;
if ( ! V_153 )
return - V_126 ;
if ( V_5 == V_86 )
F_35 () ;
V_147 = V_5 -> V_32 ;
V_148 = V_5 -> V_33 ;
V_136 = F_61 ( V_5 , V_149 , V_150 , V_135 ) ;
if ( V_136 ) {
F_60 ( V_153 ) ;
return V_136 ;
}
V_5 -> V_32 = V_150 ;
V_5 -> V_35 = V_149 ;
V_5 -> V_33 = V_151 ;
V_5 -> V_75 = V_152 ;
V_144 = F_63 ( V_148 , V_151 ) ;
V_145 = V_151 - V_144 ;
V_141 = V_5 -> V_18 ;
V_142 = ( long ) V_153 ;
V_143 = V_142 + V_152 ;
if ( V_5 -> V_85 > V_150 ) {
if ( V_147 - V_5 -> V_85 < V_150 ) {
V_141 += ( V_147 - V_150 ) * V_148 ;
} else {
V_141 += ( V_5 -> V_85 - V_150 / 2 ) * V_148 ;
}
}
V_146 = V_141 + V_148 * F_63 ( V_147 , V_150 ) ;
F_26 ( V_5 ) ;
while ( V_141 < V_146 ) {
F_32 ( ( unsigned short * ) V_142 ,
( unsigned short * ) V_141 , V_144 ) ;
if ( V_145 )
F_18 ( ( void * ) ( V_142 + V_144 ) ,
V_5 -> V_36 , V_145 ) ;
V_141 += V_148 ;
V_142 += V_151 ;
}
if ( V_143 > V_142 )
F_18 ( ( void * ) V_142 , V_5 -> V_36 ,
V_143 - V_142 ) ;
F_60 ( V_5 -> V_94 ) ;
V_5 -> V_94 = V_153 ;
V_5 -> V_75 = V_152 ;
F_36 ( V_5 ) ;
V_5 -> V_159 = 0 ;
V_5 -> V_160 = V_5 -> V_32 ;
F_64 ( V_5 , V_5 -> V_80 , V_5 -> V_85 ) ;
F_65 ( V_5 ) ;
if ( V_139 ) {
struct V_161 V_162 ;
memset ( & V_162 , 0 , sizeof( V_162 ) ) ;
V_162 . V_163 = V_5 -> V_32 ;
V_162 . V_164 = V_5 -> V_35 ;
V_162 . V_165 = V_5 -> V_166 ;
F_66 ( V_139 , & V_162 ) ;
}
if ( F_10 ( V_5 ) )
F_67 ( V_5 ) ;
F_68 ( V_167 , V_5 -> V_12 , V_5 -> V_12 ) ;
return V_136 ;
}
int F_69 ( struct V_4 * V_5 , unsigned int V_140 , unsigned int V_168 )
{
return F_62 ( V_5 -> V_127 . V_139 , V_5 , V_140 , V_168 ) ;
}
static int F_70 ( struct V_138 * V_139 , struct V_161 * V_162 )
{
struct V_4 * V_5 = V_139 -> V_169 ;
int V_170 ;
F_71 () ;
V_170 = F_62 ( V_139 , V_5 , V_162 -> V_164 , V_162 -> V_163 ) ;
F_72 () ;
return V_170 ;
}
struct V_4 * F_73 ( unsigned int V_123 )
{
struct V_4 * V_5 = NULL ;
F_22 () ;
if ( F_46 ( V_123 ) ) {
struct V_7 V_8 ;
V_8 . V_5 = V_5 = V_102 [ V_123 ] . V_30 ;
F_6 ( & V_3 , V_171 , & V_8 ) ;
F_74 ( V_123 ) ;
V_5 -> V_19 -> V_172 ( V_5 ) ;
F_75 ( V_5 -> V_173 ) ;
F_48 ( V_5 -> V_19 -> V_112 ) ;
F_60 ( V_5 -> V_94 ) ;
V_102 [ V_123 ] . V_30 = NULL ;
}
return V_5 ;
}
static void F_64 ( struct V_4 * V_5 , int V_174 , int V_175 )
{
int V_176 , V_177 ;
if ( V_174 < 0 )
V_5 -> V_80 = 0 ;
else {
if ( V_174 >= V_5 -> V_35 )
V_5 -> V_80 = V_5 -> V_35 - 1 ;
else
V_5 -> V_80 = V_174 ;
}
if ( V_5 -> V_178 ) {
V_176 = V_5 -> V_159 ;
V_177 = V_5 -> V_160 ;
} else {
V_176 = 0 ;
V_177 = V_5 -> V_32 ;
}
if ( V_175 < V_176 )
V_5 -> V_85 = V_176 ;
else if ( V_175 >= V_177 )
V_5 -> V_85 = V_177 - 1 ;
else
V_5 -> V_85 = V_175 ;
V_5 -> V_79 = V_5 -> V_18 + V_5 -> V_85 * V_5 -> V_33 + ( V_5 -> V_80 << 1 ) ;
V_5 -> V_81 = 0 ;
}
static void F_76 ( struct V_4 * V_5 , int V_174 , int V_175 )
{
F_64 ( V_5 , V_174 , V_5 -> V_178 ? ( V_5 -> V_159 + V_175 ) : V_175 ) ;
}
void F_77 ( struct V_4 * V_5 )
{
F_12 ( - ( V_5 -> V_32 / 2 ) ) ;
}
void F_78 ( struct V_4 * V_5 , int V_22 )
{
if ( ! V_22 )
V_22 = V_5 -> V_32 / 2 ;
F_12 ( V_22 ) ;
}
static void F_79 ( struct V_4 * V_5 )
{
if ( V_5 -> V_85 + 1 == V_5 -> V_160 )
F_15 ( V_5 , V_5 -> V_159 , V_5 -> V_160 , V_34 , 1 ) ;
else if ( V_5 -> V_85 < V_5 -> V_32 - 1 ) {
V_5 -> V_85 ++ ;
V_5 -> V_79 += V_5 -> V_33 ;
}
V_5 -> V_81 = 0 ;
F_5 ( V_5 , '\n' ) ;
}
static void F_80 ( struct V_4 * V_5 )
{
if ( V_5 -> V_85 == V_5 -> V_159 )
F_15 ( V_5 , V_5 -> V_159 , V_5 -> V_160 , V_179 , 1 ) ;
else if ( V_5 -> V_85 > 0 ) {
V_5 -> V_85 -- ;
V_5 -> V_79 -= V_5 -> V_33 ;
}
V_5 -> V_81 = 0 ;
}
static inline void F_81 ( struct V_4 * V_5 )
{
V_5 -> V_79 -= V_5 -> V_80 << 1 ;
V_5 -> V_81 = V_5 -> V_80 = 0 ;
F_5 ( V_5 , '\r' ) ;
}
static inline void F_82 ( struct V_4 * V_5 )
{
if ( V_5 -> V_80 ) {
V_5 -> V_79 -= 2 ;
V_5 -> V_80 -- ;
V_5 -> V_81 = 0 ;
F_5 ( V_5 , '\b' ) ;
}
}
static inline void F_83 ( struct V_4 * V_5 )
{
}
static void F_84 ( struct V_4 * V_5 , int V_180 )
{
unsigned int V_38 ;
unsigned short * V_37 ;
switch ( V_180 ) {
case 0 :
V_38 = ( V_5 -> V_95 - V_5 -> V_79 ) >> 1 ;
V_37 = ( unsigned short * ) V_5 -> V_79 ;
break;
case 1 :
V_38 = ( ( V_5 -> V_79 - V_5 -> V_18 ) >> 1 ) + 1 ;
V_37 = ( unsigned short * ) V_5 -> V_18 ;
break;
case 3 :
F_18 ( V_5 -> V_94 , V_5 -> V_36 ,
V_5 -> V_75 ) ;
F_38 ( V_5 ) ;
F_36 ( V_5 ) ;
if ( F_10 ( V_5 ) )
F_67 ( V_5 ) ;
case 2 :
V_38 = V_5 -> V_35 * V_5 -> V_32 ;
V_37 = ( unsigned short * ) V_5 -> V_18 ;
break;
default:
return;
}
F_18 ( V_37 , V_5 -> V_36 , 2 * V_38 ) ;
if ( F_9 ( V_5 ) )
F_19 ( V_5 , ( unsigned long ) V_37 , V_38 ) ;
V_5 -> V_81 = 0 ;
}
static void F_85 ( struct V_4 * V_5 , int V_180 )
{
unsigned int V_38 ;
unsigned short * V_37 ;
switch ( V_180 ) {
case 0 :
V_38 = V_5 -> V_35 - V_5 -> V_80 ;
V_37 = ( unsigned short * ) V_5 -> V_79 ;
break;
case 1 :
V_37 = ( unsigned short * ) ( V_5 -> V_79 - ( V_5 -> V_80 << 1 ) ) ;
V_38 = V_5 -> V_80 + 1 ;
break;
case 2 :
V_37 = ( unsigned short * ) ( V_5 -> V_79 - ( V_5 -> V_80 << 1 ) ) ;
V_38 = V_5 -> V_35 ;
break;
default:
return;
}
F_18 ( V_37 , V_5 -> V_36 , 2 * V_38 ) ;
V_5 -> V_81 = 0 ;
if ( F_9 ( V_5 ) )
F_19 ( V_5 , ( unsigned long ) V_37 , V_38 ) ;
}
static void F_86 ( struct V_4 * V_5 , int V_180 )
{
int V_38 ;
if ( ! V_180 )
V_180 ++ ;
V_38 = ( V_180 > V_5 -> V_35 - V_5 -> V_80 ) ? ( V_5 -> V_35 - V_5 -> V_80 ) : V_180 ;
F_18 ( ( unsigned short * ) V_5 -> V_79 , V_5 -> V_36 , 2 * V_38 ) ;
if ( F_9 ( V_5 ) )
V_5 -> V_19 -> V_181 ( V_5 , V_5 -> V_85 , V_5 -> V_80 , 1 , V_38 ) ;
V_5 -> V_81 = 0 ;
}
static void F_87 ( struct V_4 * V_5 )
{
V_5 -> V_63 = 1 ;
V_5 -> V_68 = 0 ;
V_5 -> V_65 = 0 ;
V_5 -> V_66 = 0 ;
V_5 -> V_64 = 0 ;
V_5 -> V_62 = V_5 -> V_182 ;
}
static void F_88 ( int V_82 , struct V_183 * V_9 )
{
if ( V_82 < 8 ) {
V_9 -> V_184 = V_82 & 1 ? 0xaa : 0x00 ;
V_9 -> V_185 = V_82 & 2 ? 0xaa : 0x00 ;
V_9 -> V_26 = V_82 & 4 ? 0xaa : 0x00 ;
} else if ( V_82 < 16 ) {
V_9 -> V_184 = V_82 & 1 ? 0xff : 0x55 ;
V_9 -> V_185 = V_82 & 2 ? 0xff : 0x55 ;
V_9 -> V_26 = V_82 & 4 ? 0xff : 0x55 ;
} else if ( V_82 < 232 ) {
V_9 -> V_184 = ( V_82 - 16 ) / 36 * 85 / 2 ;
V_9 -> V_185 = ( V_82 - 16 ) / 6 % 6 * 85 / 2 ;
V_9 -> V_26 = ( V_82 - 16 ) % 6 * 85 / 2 ;
} else
V_9 -> V_184 = V_9 -> V_185 = V_9 -> V_26 = V_82 * 10 - 2312 ;
}
static void F_89 ( struct V_4 * V_5 , const struct V_183 * V_9 )
{
T_2 V_186 = 0 , V_187 = F_90 ( V_9 -> V_184 , V_9 -> V_185 , V_9 -> V_26 ) ;
if ( V_9 -> V_184 > V_187 / 2 )
V_186 |= 4 ;
if ( V_9 -> V_185 > V_187 / 2 )
V_186 |= 2 ;
if ( V_9 -> V_26 > V_187 / 2 )
V_186 |= 1 ;
if ( V_186 == 7 && V_187 <= 0x55 ) {
V_186 = 0 ;
V_5 -> V_63 = 2 ;
} else if ( V_187 > 0xaa )
V_5 -> V_63 = 2 ;
else
V_5 -> V_63 = 1 ;
V_5 -> V_62 = ( V_5 -> V_62 & 0xf0 ) | V_186 ;
}
static void F_91 ( struct V_4 * V_5 , const struct V_183 * V_9 )
{
V_5 -> V_62 = ( V_5 -> V_62 & 0x0f )
| ( V_9 -> V_184 & 0x80 ) >> 1 | ( V_9 -> V_185 & 0x80 ) >> 2 | ( V_9 -> V_26 & 0x80 ) >> 3 ;
}
static int F_92 ( struct V_4 * V_5 , int V_82 ,
void (* F_93)( struct V_4 * V_5 , const struct V_183 * V_9 ) )
{
struct V_183 V_9 ;
V_82 ++ ;
if ( V_82 > V_5 -> V_188 )
return V_82 ;
if ( V_5 -> V_189 [ V_82 ] == 5 && V_82 + 1 <= V_5 -> V_188 ) {
V_82 ++ ;
F_88 ( V_5 -> V_189 [ V_82 ] , & V_9 ) ;
} else if ( V_5 -> V_189 [ V_82 ] == 2 && V_82 + 3 <= V_5 -> V_188 ) {
V_9 . V_184 = V_5 -> V_189 [ V_82 + 1 ] ;
V_9 . V_185 = V_5 -> V_189 [ V_82 + 2 ] ;
V_9 . V_26 = V_5 -> V_189 [ V_82 + 3 ] ;
V_82 += 3 ;
} else
return V_82 ;
F_93 ( V_5 , & V_9 ) ;
return V_82 ;
}
static void F_94 ( struct V_4 * V_5 )
{
int V_82 ;
for ( V_82 = 0 ; V_82 <= V_5 -> V_188 ; V_82 ++ )
switch ( V_5 -> V_189 [ V_82 ] ) {
case 0 :
F_87 ( V_5 ) ;
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
V_5 -> V_190 = F_95 ( V_5 -> V_191 == 0
? V_5 -> V_192
: V_5 -> V_193 , V_5 ) ;
V_5 -> V_194 = 0 ;
V_5 -> V_195 = 0 ;
break;
case 11 :
V_5 -> V_190 = F_95 ( V_196 , V_5 ) ;
V_5 -> V_194 = 1 ;
V_5 -> V_195 = 0 ;
break;
case 12 :
V_5 -> V_190 = F_95 ( V_196 , V_5 ) ;
V_5 -> V_194 = 1 ;
V_5 -> V_195 = 1 ;
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
V_82 = F_92 ( V_5 , V_82 , F_89 ) ;
break;
case 48 :
V_82 = F_92 ( V_5 , V_82 , F_91 ) ;
break;
case 39 :
V_5 -> V_62 = ( V_5 -> V_182 & 0x0f ) |
( V_5 -> V_62 & 0xf0 ) ;
break;
case 49 :
V_5 -> V_62 = ( V_5 -> V_182 & 0xf0 ) |
( V_5 -> V_62 & 0x0f ) ;
break;
default:
if ( V_5 -> V_189 [ V_82 ] >= 90 && V_5 -> V_189 [ V_82 ] <= 107 ) {
if ( V_5 -> V_189 [ V_82 ] < 100 )
V_5 -> V_63 = 2 ;
V_5 -> V_189 [ V_82 ] -= 60 ;
}
if ( V_5 -> V_189 [ V_82 ] >= 30 && V_5 -> V_189 [ V_82 ] <= 37 )
V_5 -> V_62 = V_197 [ V_5 -> V_189 [ V_82 ] - 30 ]
| ( V_5 -> V_62 & 0xf0 ) ;
else if ( V_5 -> V_189 [ V_82 ] >= 40 && V_5 -> V_189 [ V_82 ] <= 47 )
V_5 -> V_62 = ( V_197 [ V_5 -> V_189 [ V_82 ] - 40 ] << 4 )
| ( V_5 -> V_62 & 0x0f ) ;
break;
}
F_26 ( V_5 ) ;
}
static void F_96 ( const char * V_17 , struct V_198 * V_127 )
{
while ( * V_17 ) {
F_97 ( V_127 , * V_17 , 0 ) ;
V_17 ++ ;
}
F_98 ( V_127 ) ;
}
static void F_99 ( struct V_4 * V_5 , struct V_138 * V_139 )
{
char V_199 [ 40 ] ;
sprintf ( V_199 , L_2 , V_5 -> V_85 + ( V_5 -> V_178 ? V_5 -> V_159 + 1 : 1 ) , V_5 -> V_80 + 1 ) ;
F_96 ( V_199 , V_139 -> V_127 ) ;
}
static inline void F_100 ( struct V_138 * V_139 )
{
F_96 ( L_3 , V_139 -> V_127 ) ;
}
static inline void F_101 ( struct V_138 * V_139 )
{
F_96 ( V_200 , V_139 -> V_127 ) ;
}
void F_102 ( struct V_138 * V_139 , int V_201 , int V_202 , int V_203 )
{
char V_199 [ 8 ] ;
sprintf ( V_199 , L_4 , ( char ) ( ' ' + V_201 ) , ( char ) ( '!' + V_202 ) ,
( char ) ( '!' + V_203 ) ) ;
F_96 ( V_199 , V_139 -> V_127 ) ;
}
int F_103 ( void )
{
return V_102 [ V_13 ] . V_30 -> V_204 ;
}
static void F_104 ( struct V_4 * V_5 , int V_205 )
{
int V_82 ;
for ( V_82 = 0 ; V_82 <= V_5 -> V_188 ; V_82 ++ )
if ( V_5 -> V_206 ) {
switch( V_5 -> V_189 [ V_82 ] ) {
case 1 :
if ( V_205 )
F_105 ( V_5 , V_207 ) ;
else
F_106 ( V_5 , V_207 ) ;
break;
case 3 :
#if 0
vc_resize(deccolm ? 132 : 80, vc->vc_rows);
#endif
break;
case 5 :
if ( V_5 -> V_67 != V_205 ) {
V_5 -> V_67 = V_205 ;
F_27 ( V_5 , 0 , V_5 -> V_75 , 0 ) ;
F_26 ( V_5 ) ;
}
break;
case 6 :
V_5 -> V_178 = V_205 ;
F_76 ( V_5 , 0 , 0 ) ;
break;
case 7 :
V_5 -> V_208 = V_205 ;
break;
case 8 :
if ( V_205 )
F_105 ( V_5 , V_209 ) ;
else
F_106 ( V_5 , V_209 ) ;
break;
case 9 :
V_5 -> V_204 = V_205 ? 1 : 0 ;
break;
case 25 :
V_5 -> V_91 = V_205 ;
break;
case 1000 :
V_5 -> V_204 = V_205 ? 2 : 0 ;
break;
}
} else {
switch( V_5 -> V_189 [ V_82 ] ) {
case 3 :
V_5 -> V_194 = V_205 ;
break;
case 4 :
V_5 -> V_210 = V_205 ;
break;
case 20 :
if ( V_205 )
F_105 ( V_5 , V_211 ) ;
else
F_106 ( V_5 , V_211 ) ;
break;
}
}
}
static void F_107 ( struct V_4 * V_5 )
{
switch( V_5 -> V_189 [ 0 ] ) {
case 1 :
if ( V_5 -> V_56 &&
V_5 -> V_189 [ 1 ] < 16 ) {
V_5 -> V_58 = V_197 [ V_5 -> V_189 [ 1 ] ] ;
if ( V_5 -> V_65 )
F_26 ( V_5 ) ;
}
break;
case 2 :
if ( V_5 -> V_56 &&
V_5 -> V_189 [ 1 ] < 16 ) {
V_5 -> V_59 = V_197 [ V_5 -> V_189 [ 1 ] ] ;
if ( V_5 -> V_63 == 0 )
F_26 ( V_5 ) ;
}
break;
case 8 :
V_5 -> V_182 = V_5 -> V_61 ;
if ( V_5 -> V_60 == 0x100 )
V_5 -> V_182 >>= 1 ;
F_87 ( V_5 ) ;
F_26 ( V_5 ) ;
break;
case 9 :
V_212 = ( ( V_5 -> V_189 [ 1 ] < 60 ) ? V_5 -> V_189 [ 1 ] : 60 ) * 60 ;
F_108 () ;
break;
case 10 :
if ( V_5 -> V_188 >= 1 )
V_5 -> V_213 = V_5 -> V_189 [ 1 ] ;
else
V_5 -> V_213 = V_214 ;
break;
case 11 :
if ( V_5 -> V_188 >= 1 )
V_5 -> V_215 = ( V_5 -> V_189 [ 1 ] < 2000 ) ?
F_109 ( V_5 -> V_189 [ 1 ] ) : 0 ;
else
V_5 -> V_215 = V_216 ;
break;
case 12 :
if ( V_5 -> V_189 [ 1 ] >= 1 && F_46 ( V_5 -> V_189 [ 1 ] - 1 ) )
F_110 ( V_5 -> V_189 [ 1 ] - 1 ) ;
break;
case 13 :
F_108 () ;
break;
case 14 :
V_217 = ( ( V_5 -> V_189 [ 1 ] < 60 ) ? V_5 -> V_189 [ 1 ] : 60 ) * 60 * V_218 ;
break;
case 15 :
F_110 ( V_219 ) ;
break;
case 16 :
if ( V_5 -> V_188 >= 1 && V_5 -> V_189 [ 1 ] >= 50 &&
V_5 -> V_189 [ 1 ] <= V_220 )
V_5 -> V_119 = V_5 -> V_189 [ 1 ] ;
else
V_5 -> V_119 = V_120 ;
break;
}
}
static void F_111 ( struct V_4 * V_5 , unsigned int V_28 )
{
if ( V_28 > V_5 -> V_35 - V_5 -> V_80 )
V_28 = V_5 -> V_35 - V_5 -> V_80 ;
else if ( ! V_28 )
V_28 = 1 ;
F_30 ( V_5 , V_28 ) ;
}
static void F_112 ( struct V_4 * V_5 , unsigned int V_28 )
{
if ( V_28 > V_5 -> V_32 - V_5 -> V_85 )
V_28 = V_5 -> V_32 - V_5 -> V_85 ;
else if ( ! V_28 )
V_28 = 1 ;
F_15 ( V_5 , V_5 -> V_85 , V_5 -> V_160 , V_179 , V_28 ) ;
V_5 -> V_81 = 0 ;
}
static void F_113 ( struct V_4 * V_5 , unsigned int V_28 )
{
if ( V_28 > V_5 -> V_35 - V_5 -> V_80 )
V_28 = V_5 -> V_35 - V_5 -> V_80 ;
else if ( ! V_28 )
V_28 = 1 ;
F_31 ( V_5 , V_28 ) ;
}
static void F_114 ( struct V_4 * V_5 , unsigned int V_28 )
{
if ( V_28 > V_5 -> V_32 - V_5 -> V_85 )
V_28 = V_5 -> V_32 - V_5 -> V_85 ;
else if ( ! V_28 )
V_28 = 1 ;
F_15 ( V_5 , V_5 -> V_85 , V_5 -> V_160 , V_34 , V_28 ) ;
V_5 -> V_81 = 0 ;
}
static void F_65 ( struct V_4 * V_5 )
{
V_5 -> V_221 = V_5 -> V_80 ;
V_5 -> V_222 = V_5 -> V_85 ;
V_5 -> V_223 = V_5 -> V_63 ;
V_5 -> V_224 = V_5 -> V_68 ;
V_5 -> V_225 = V_5 -> V_65 ;
V_5 -> V_226 = V_5 -> V_64 ;
V_5 -> V_227 = V_5 -> V_66 ;
V_5 -> V_228 = V_5 -> V_191 ;
V_5 -> V_229 = V_5 -> V_62 ;
V_5 -> V_230 = V_5 -> V_192 ;
V_5 -> V_231 = V_5 -> V_193 ;
}
static void F_115 ( struct V_4 * V_5 )
{
F_64 ( V_5 , V_5 -> V_221 , V_5 -> V_222 ) ;
V_5 -> V_63 = V_5 -> V_223 ;
V_5 -> V_68 = V_5 -> V_224 ;
V_5 -> V_65 = V_5 -> V_225 ;
V_5 -> V_64 = V_5 -> V_226 ;
V_5 -> V_66 = V_5 -> V_227 ;
V_5 -> V_191 = V_5 -> V_228 ;
V_5 -> V_62 = V_5 -> V_229 ;
V_5 -> V_192 = V_5 -> V_230 ;
V_5 -> V_193 = V_5 -> V_231 ;
V_5 -> V_190 = F_95 ( V_5 -> V_191 ? V_5 -> V_193 : V_5 -> V_192 , V_5 ) ;
F_26 ( V_5 ) ;
V_5 -> V_81 = 0 ;
}
static void F_116 ( struct V_4 * V_5 , int V_232 )
{
V_5 -> V_159 = 0 ;
V_5 -> V_160 = V_5 -> V_32 ;
V_5 -> V_233 = V_234 ;
V_5 -> V_206 = 0 ;
V_5 -> V_190 = F_95 ( V_235 , V_5 ) ;
V_5 -> V_192 = V_235 ;
V_5 -> V_193 = V_236 ;
V_5 -> V_191 = 0 ;
V_5 -> V_81 = 0 ;
V_5 -> V_204 = 0 ;
V_5 -> V_237 = V_238 ;
V_5 -> V_239 = 0 ;
V_5 -> V_194 = 0 ;
V_5 -> V_195 = 0 ;
V_5 -> V_67 = 0 ;
V_5 -> V_178 = 0 ;
V_5 -> V_208 = 1 ;
V_5 -> V_91 = V_131 ;
V_5 -> V_210 = 0 ;
F_117 ( V_5 -> V_12 ) ;
V_5 -> V_83 = V_240 ;
V_5 -> V_78 = V_5 -> V_122 ;
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
V_5 -> V_119 = V_120 ;
F_64 ( V_5 , 0 , 0 ) ;
F_65 ( V_5 ) ;
if ( V_232 )
F_84 ( V_5 , 2 ) ;
}
static void F_118 ( struct V_138 * V_139 , struct V_4 * V_5 , int V_9 )
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
F_119 ( V_5 -> V_213 , V_5 -> V_215 ) ;
return;
case 8 :
F_82 ( V_5 ) ;
return;
case 9 :
V_5 -> V_79 -= ( V_5 -> V_80 << 1 ) ;
while ( V_5 -> V_80 < V_5 -> V_35 - 1 ) {
V_5 -> V_80 ++ ;
if ( V_5 -> V_241 [ V_5 -> V_80 >> 5 ] & ( 1 << ( V_5 -> V_80 & 31 ) ) )
break;
}
V_5 -> V_79 += ( V_5 -> V_80 << 1 ) ;
F_5 ( V_5 , '\t' ) ;
return;
case 10 : case 11 : case 12 :
F_79 ( V_5 ) ;
if ( ! F_120 ( V_5 , V_211 ) )
return;
case 13 :
F_81 ( V_5 ) ;
return;
case 14 :
V_5 -> V_191 = 1 ;
V_5 -> V_190 = F_95 ( V_5 -> V_193 , V_5 ) ;
V_5 -> V_194 = 1 ;
return;
case 15 :
V_5 -> V_191 = 0 ;
V_5 -> V_190 = F_95 ( V_5 -> V_192 , V_5 ) ;
V_5 -> V_194 = 0 ;
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
V_5 -> V_241 [ V_5 -> V_80 >> 5 ] |= ( 1 << ( V_5 -> V_80 & 31 ) ) ;
return;
case 'Z' :
F_101 ( V_139 ) ;
return;
case '7' :
F_65 ( V_5 ) ;
return;
case '8' :
F_115 ( V_5 ) ;
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
F_116 ( V_5 , 1 ) ;
return;
case '>' :
F_106 ( V_5 , V_250 ) ;
return;
case '=' :
F_105 ( V_5 , V_250 ) ;
return;
}
return;
case V_245 :
if ( V_9 == 'P' ) {
for ( V_5 -> V_188 = 0 ; V_5 -> V_188 < V_251 ; V_5 -> V_188 ++ )
V_5 -> V_189 [ V_5 -> V_188 ] = 0 ;
V_5 -> V_188 = 0 ;
V_5 -> V_233 = V_252 ;
return;
} else if ( V_9 == 'R' ) {
F_121 ( V_5 ) ;
V_5 -> V_233 = V_234 ;
} else if ( V_9 >= '0' && V_9 <= '9' )
V_5 -> V_233 = V_242 ;
else
V_5 -> V_233 = V_234 ;
return;
case V_252 :
if ( isxdigit ( V_9 ) ) {
V_5 -> V_189 [ V_5 -> V_188 ++ ] = F_122 ( V_9 ) ;
if ( V_5 -> V_188 == 7 ) {
int V_82 = V_5 -> V_189 [ 0 ] * 3 , V_253 = 1 ;
V_5 -> V_254 [ V_82 ] = 16 * V_5 -> V_189 [ V_253 ++ ] ;
V_5 -> V_254 [ V_82 ++ ] += V_5 -> V_189 [ V_253 ++ ] ;
V_5 -> V_254 [ V_82 ] = 16 * V_5 -> V_189 [ V_253 ++ ] ;
V_5 -> V_254 [ V_82 ++ ] += V_5 -> V_189 [ V_253 ++ ] ;
V_5 -> V_254 [ V_82 ] = 16 * V_5 -> V_189 [ V_253 ++ ] ;
V_5 -> V_254 [ V_82 ] += V_5 -> V_189 [ V_253 ] ;
F_42 ( V_5 ) ;
V_5 -> V_233 = V_234 ;
}
} else
V_5 -> V_233 = V_234 ;
return;
case V_244 :
for ( V_5 -> V_188 = 0 ; V_5 -> V_188 < V_251 ; V_5 -> V_188 ++ )
V_5 -> V_189 [ V_5 -> V_188 ] = 0 ;
V_5 -> V_188 = 0 ;
V_5 -> V_233 = V_255 ;
if ( V_9 == '[' ) {
V_5 -> V_233 = V_256 ;
return;
}
V_5 -> V_206 = ( V_9 == '?' ) ;
if ( V_5 -> V_206 )
return;
case V_255 :
if ( V_9 == ';' && V_5 -> V_188 < V_251 - 1 ) {
V_5 -> V_188 ++ ;
return;
} else if ( V_9 >= '0' && V_9 <= '9' ) {
V_5 -> V_189 [ V_5 -> V_188 ] *= 10 ;
V_5 -> V_189 [ V_5 -> V_188 ] += V_9 - '0' ;
return;
}
V_5 -> V_233 = V_234 ;
switch( V_9 ) {
case 'h' :
F_104 ( V_5 , 1 ) ;
return;
case 'l' :
F_104 ( V_5 , 0 ) ;
return;
case 'c' :
if ( V_5 -> V_206 ) {
if ( V_5 -> V_189 [ 0 ] )
V_5 -> V_83 = V_5 -> V_189 [ 0 ] | ( V_5 -> V_189 [ 1 ] << 8 ) | ( V_5 -> V_189 [ 2 ] << 16 ) ;
else
V_5 -> V_83 = V_240 ;
return;
}
break;
case 'm' :
if ( V_5 -> V_206 ) {
F_35 () ;
if ( V_5 -> V_189 [ 0 ] )
V_5 -> V_78 = V_5 -> V_189 [ 0 ] << 8 | V_5 -> V_189 [ 1 ] ;
else
V_5 -> V_78 = V_5 -> V_122 ;
return;
}
break;
case 'n' :
if ( ! V_5 -> V_206 ) {
if ( V_5 -> V_189 [ 0 ] == 5 )
F_100 ( V_139 ) ;
else if ( V_5 -> V_189 [ 0 ] == 6 )
F_99 ( V_5 , V_139 ) ;
}
return;
}
if ( V_5 -> V_206 ) {
V_5 -> V_206 = 0 ;
return;
}
switch( V_9 ) {
case 'G' : case '`' :
if ( V_5 -> V_189 [ 0 ] )
V_5 -> V_189 [ 0 ] -- ;
F_64 ( V_5 , V_5 -> V_189 [ 0 ] , V_5 -> V_85 ) ;
return;
case 'A' :
if ( ! V_5 -> V_189 [ 0 ] )
V_5 -> V_189 [ 0 ] ++ ;
F_64 ( V_5 , V_5 -> V_80 , V_5 -> V_85 - V_5 -> V_189 [ 0 ] ) ;
return;
case 'B' : case 'e' :
if ( ! V_5 -> V_189 [ 0 ] )
V_5 -> V_189 [ 0 ] ++ ;
F_64 ( V_5 , V_5 -> V_80 , V_5 -> V_85 + V_5 -> V_189 [ 0 ] ) ;
return;
case 'C' : case 'a' :
if ( ! V_5 -> V_189 [ 0 ] )
V_5 -> V_189 [ 0 ] ++ ;
F_64 ( V_5 , V_5 -> V_80 + V_5 -> V_189 [ 0 ] , V_5 -> V_85 ) ;
return;
case 'D' :
if ( ! V_5 -> V_189 [ 0 ] )
V_5 -> V_189 [ 0 ] ++ ;
F_64 ( V_5 , V_5 -> V_80 - V_5 -> V_189 [ 0 ] , V_5 -> V_85 ) ;
return;
case 'E' :
if ( ! V_5 -> V_189 [ 0 ] )
V_5 -> V_189 [ 0 ] ++ ;
F_64 ( V_5 , 0 , V_5 -> V_85 + V_5 -> V_189 [ 0 ] ) ;
return;
case 'F' :
if ( ! V_5 -> V_189 [ 0 ] )
V_5 -> V_189 [ 0 ] ++ ;
F_64 ( V_5 , 0 , V_5 -> V_85 - V_5 -> V_189 [ 0 ] ) ;
return;
case 'd' :
if ( V_5 -> V_189 [ 0 ] )
V_5 -> V_189 [ 0 ] -- ;
F_76 ( V_5 , V_5 -> V_80 , V_5 -> V_189 [ 0 ] ) ;
return;
case 'H' : case 'f' :
if ( V_5 -> V_189 [ 0 ] )
V_5 -> V_189 [ 0 ] -- ;
if ( V_5 -> V_189 [ 1 ] )
V_5 -> V_189 [ 1 ] -- ;
F_76 ( V_5 , V_5 -> V_189 [ 1 ] , V_5 -> V_189 [ 0 ] ) ;
return;
case 'J' :
F_84 ( V_5 , V_5 -> V_189 [ 0 ] ) ;
return;
case 'K' :
F_85 ( V_5 , V_5 -> V_189 [ 0 ] ) ;
return;
case 'L' :
F_112 ( V_5 , V_5 -> V_189 [ 0 ] ) ;
return;
case 'M' :
F_114 ( V_5 , V_5 -> V_189 [ 0 ] ) ;
return;
case 'P' :
F_113 ( V_5 , V_5 -> V_189 [ 0 ] ) ;
return;
case 'c' :
if ( ! V_5 -> V_189 [ 0 ] )
F_101 ( V_139 ) ;
return;
case 'g' :
if ( ! V_5 -> V_189 [ 0 ] )
V_5 -> V_241 [ V_5 -> V_80 >> 5 ] &= ~ ( 1 << ( V_5 -> V_80 & 31 ) ) ;
else if ( V_5 -> V_189 [ 0 ] == 3 ) {
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
F_94 ( V_5 ) ;
return;
case 'q' :
if ( V_5 -> V_189 [ 0 ] < 4 )
F_123 ( V_5 -> V_12 ,
( V_5 -> V_189 [ 0 ] < 3 ) ? V_5 -> V_189 [ 0 ] : 4 ) ;
return;
case 'r' :
if ( ! V_5 -> V_189 [ 0 ] )
V_5 -> V_189 [ 0 ] ++ ;
if ( ! V_5 -> V_189 [ 1 ] )
V_5 -> V_189 [ 1 ] = V_5 -> V_32 ;
if ( V_5 -> V_189 [ 0 ] < V_5 -> V_189 [ 1 ] &&
V_5 -> V_189 [ 1 ] <= V_5 -> V_32 ) {
V_5 -> V_159 = V_5 -> V_189 [ 0 ] - 1 ;
V_5 -> V_160 = V_5 -> V_189 [ 1 ] ;
F_76 ( V_5 , 0 , 0 ) ;
}
return;
case 's' :
F_65 ( V_5 ) ;
return;
case 'u' :
F_115 ( V_5 ) ;
return;
case 'X' :
F_86 ( V_5 , V_5 -> V_189 [ 0 ] ) ;
return;
case '@' :
F_111 ( V_5 , V_5 -> V_189 [ 0 ] ) ;
return;
case ']' :
F_107 ( V_5 ) ;
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
V_5 -> V_36 =
( V_5 -> V_36 & 0xff00 ) | 'E' ;
F_84 ( V_5 , 2 ) ;
V_5 -> V_36 =
( V_5 -> V_36 & 0xff00 ) | ' ' ;
F_19 ( V_5 , V_5 -> V_18 , V_5 -> V_75 / 2 ) ;
}
return;
case V_247 :
if ( V_9 == '0' )
V_5 -> V_192 = V_236 ;
else if ( V_9 == 'B' )
V_5 -> V_192 = V_235 ;
else if ( V_9 == 'U' )
V_5 -> V_192 = V_196 ;
else if ( V_9 == 'K' )
V_5 -> V_192 = V_257 ;
if ( V_5 -> V_191 == 0 )
V_5 -> V_190 = F_95 ( V_5 -> V_192 , V_5 ) ;
V_5 -> V_233 = V_234 ;
return;
case V_248 :
if ( V_9 == '0' )
V_5 -> V_193 = V_236 ;
else if ( V_9 == 'B' )
V_5 -> V_193 = V_235 ;
else if ( V_9 == 'U' )
V_5 -> V_193 = V_196 ;
else if ( V_9 == 'K' )
V_5 -> V_193 = V_257 ;
if ( V_5 -> V_191 == 1 )
V_5 -> V_190 = F_95 ( V_5 -> V_193 , V_5 ) ;
V_5 -> V_233 = V_234 ;
return;
case V_242 :
return;
default:
V_5 -> V_233 = V_234 ;
}
}
static int F_124 ( T_4 V_258 , const struct V_259 * V_260 , int V_187 )
{
int F_63 = 0 ;
int V_261 ;
if ( V_258 < V_260 [ 0 ] . V_262 || V_258 > V_260 [ V_187 ] . V_263 )
return 0 ;
while ( V_187 >= F_63 ) {
V_261 = ( F_63 + V_187 ) / 2 ;
if ( V_258 > V_260 [ V_261 ] . V_263 )
F_63 = V_261 + 1 ;
else if ( V_258 < V_260 [ V_261 ] . V_262 )
V_187 = V_261 - 1 ;
else
return 1 ;
}
return 0 ;
}
static int F_125 ( T_4 V_258 )
{
static const struct V_259 V_264 [] = {
{ 0x1100 , 0x115F } , { 0x2329 , 0x232A } , { 0x2E80 , 0x303E } ,
{ 0x3040 , 0xA4CF } , { 0xAC00 , 0xD7A3 } , { 0xF900 , 0xFAFF } ,
{ 0xFE10 , 0xFE19 } , { 0xFE30 , 0xFE6F } , { 0xFF00 , 0xFF60 } ,
{ 0xFFE0 , 0xFFE6 } , { 0x20000 , 0x2FFFD } , { 0x30000 , 0x3FFFD }
} ;
return F_124 ( V_258 , V_264 , F_126 ( V_264 ) - 1 ) ;
}
static void F_127 ( struct V_4 * V_5 , unsigned long V_265 ,
unsigned long V_266 , int * V_267 )
{
if ( * V_267 < 0 )
return;
V_5 -> V_19 -> V_47 ( V_5 , ( T_1 * ) V_265 ,
( T_1 * ) V_266 - ( T_1 * ) V_265 , V_5 -> V_85 , * V_267 ) ;
* V_267 = - 1 ;
}
static int F_128 ( struct V_138 * V_139 , const unsigned char * V_199 , int V_38 )
{
int V_9 , V_268 , V_269 , V_270 = 0 , V_267 = - 1 ;
unsigned int V_123 ;
unsigned long V_265 = 0 , V_266 = 0 ;
struct V_4 * V_5 ;
unsigned char V_61 ;
struct V_7 V_8 ;
T_5 V_271 ;
T_5 V_272 ;
T_5 V_133 ;
T_1 V_273 , V_274 ;
if ( F_129 () )
return V_38 ;
F_130 () ;
F_71 () ;
V_5 = V_139 -> V_169 ;
if ( V_5 == NULL ) {
F_131 ( V_275 L_5 ) ;
F_72 () ;
return 0 ;
}
V_123 = V_5 -> V_12 ;
if ( ! F_46 ( V_123 ) ) {
F_132 ( L_6 , V_123 + 1 ) ;
F_72 () ;
return 0 ;
}
V_273 = V_5 -> V_60 ;
V_274 = V_273 ? 0x1ff : 0xff ;
if ( F_8 ( V_5 ) )
F_23 ( V_5 ) ;
V_8 . V_5 = V_5 ;
while ( ! V_139 -> V_276 && V_38 ) {
int V_277 = * V_199 ;
V_9 = V_277 ;
V_199 ++ ;
V_270 ++ ;
V_38 -- ;
V_271 = 0 ;
V_272 = 0 ;
V_133 = 1 ;
if ( V_5 -> V_233 != V_234 ) {
V_268 = V_9 ;
} else if ( V_5 -> V_237 && ! V_5 -> V_194 ) {
V_278:
if ( ( V_9 & 0xc0 ) == 0x80 ) {
static const T_4 V_279 [] = { 0x0000007f , 0x000007ff , 0x0000ffff , 0x001fffff , 0x03ffffff , 0x7fffffff } ;
if ( V_5 -> V_239 ) {
V_5 -> V_280 = ( V_5 -> V_280 << 6 ) | ( V_9 & 0x3f ) ;
V_5 -> V_188 ++ ;
if ( -- V_5 -> V_239 ) {
continue;
}
V_9 = V_5 -> V_280 ;
if ( V_9 <= V_279 [ V_5 -> V_188 - 1 ] ||
V_9 > V_279 [ V_5 -> V_188 ] )
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
V_5 -> V_188 = 0 ;
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
V_268 = V_9 ;
} else {
V_268 = V_190 ( V_5 , V_9 ) ;
}
V_8 . V_9 = V_268 ;
if ( F_6 ( & V_3 , V_281 ,
& V_8 ) == V_282 )
continue;
V_269 = V_268 && ( V_9 >= 32 ||
! ( V_5 -> V_194 ? ( V_283 >> V_9 ) & 1 :
V_5 -> V_237 || ( ( V_284 >> V_9 ) & 1 ) ) )
&& ( V_9 != 127 || V_5 -> V_194 )
&& ( V_9 != 128 + 27 ) ;
if ( V_5 -> V_233 == V_234 && V_269 ) {
if ( V_5 -> V_237 && ! V_5 -> V_194 ) {
if ( F_125 ( V_9 ) )
V_133 = 2 ;
}
V_268 = F_133 ( V_5 , V_268 ) ;
if ( V_268 & ~ V_274 ) {
if ( V_268 == - 1 || V_268 == - 2 ) {
continue;
}
if ( ( ! ( V_5 -> V_237 && ! V_5 -> V_194 ) || V_9 < 128 ) && ! ( V_9 & ~ V_274 ) ) {
V_268 = V_9 ;
} else {
V_268 = F_133 ( V_5 , 0xfffd ) ;
if ( V_268 < 0 ) {
V_272 = 1 ;
V_268 = F_133 ( V_5 , '?' ) ;
if ( V_268 < 0 ) V_268 = '?' ;
}
}
}
if ( ! V_272 ) {
V_61 = V_5 -> V_61 ;
} else {
if ( ! V_5 -> V_56 ) {
V_61 = ( V_5 -> V_61 ) ^ 0x08 ;
} else if ( V_5 -> V_60 == 0x100 ) {
V_61 = ( ( V_5 -> V_61 ) & 0x11 ) | ( ( ( V_5 -> V_61 ) & 0xe0 ) >> 4 ) | ( ( ( V_5 -> V_61 ) & 0x0e ) << 4 ) ;
} else {
V_61 = ( ( V_5 -> V_61 ) & 0x88 ) | ( ( ( V_5 -> V_61 ) & 0x70 ) >> 4 ) | ( ( ( V_5 -> V_61 ) & 0x07 ) << 4 ) ;
}
F_127 ( V_5 , V_265 , V_266 , & V_267 ) ;
}
while ( 1 ) {
if ( V_5 -> V_81 || V_5 -> V_210 )
F_127 ( V_5 , V_265 , V_266 ,
& V_267 ) ;
if ( V_5 -> V_81 ) {
F_81 ( V_5 ) ;
F_79 ( V_5 ) ;
}
if ( V_5 -> V_210 )
F_30 ( V_5 , 1 ) ;
F_28 ( V_273 ?
( ( V_61 << 8 ) & ~ V_273 ) + ( ( V_268 & 0x100 ) ? V_273 : 0 ) + ( V_268 & 0xff ) :
( V_61 << 8 ) + V_268 ,
( T_1 * ) V_5 -> V_79 ) ;
if ( F_9 ( V_5 ) && V_267 < 0 ) {
V_267 = V_5 -> V_80 ;
V_265 = V_5 -> V_79 ;
}
if ( V_5 -> V_80 == V_5 -> V_35 - 1 ) {
V_5 -> V_81 = V_5 -> V_208 ;
V_266 = V_5 -> V_79 + 2 ;
} else {
V_5 -> V_80 ++ ;
V_266 = ( V_5 -> V_79 += 2 ) ;
}
if ( ! -- V_133 ) break;
V_268 = F_133 ( V_5 , ' ' ) ;
if ( V_268 < 0 ) V_268 = ' ' ;
}
F_5 ( V_5 , V_9 ) ;
if ( V_272 )
F_127 ( V_5 , V_265 , V_266 , & V_267 ) ;
if ( V_271 ) {
V_271 = 0 ;
V_272 = 0 ;
V_133 = 1 ;
V_9 = V_277 ;
goto V_278;
}
continue;
}
F_127 ( V_5 , V_265 , V_266 , & V_267 ) ;
F_118 ( V_139 , V_5 , V_277 ) ;
}
F_127 ( V_5 , V_265 , V_266 , & V_267 ) ;
F_134 () ;
F_72 () ;
F_7 ( V_5 ) ;
return V_270 ;
}
static void F_135 ( struct V_285 * V_286 )
{
F_71 () ;
if ( V_287 >= 0 ) {
if ( V_287 != V_13 &&
F_46 ( V_287 ) ) {
F_23 ( V_102 [ V_13 ] . V_30 ) ;
F_136 ( V_102 [ V_287 ] . V_30 ) ;
}
V_287 = - 1 ;
}
if ( V_288 ) {
V_288 = 0 ;
F_108 () ;
}
if ( V_23 ) {
struct V_4 * V_5 = V_102 [ V_13 ] . V_30 ;
F_35 () ;
if ( V_5 -> V_89 == V_289 && V_5 -> V_19 -> V_290 )
V_5 -> V_19 -> V_290 ( V_5 , V_23 ) ;
V_23 = 0 ;
}
if ( V_291 ) {
F_137 ( 0 ) ;
V_291 = 0 ;
}
F_7 ( V_102 [ V_13 ] . V_30 ) ;
F_72 () ;
}
int F_110 ( int V_28 )
{
struct V_4 * V_5 = V_102 [ V_13 ] . V_30 ;
if ( ! F_46 ( V_28 ) || V_292 ||
( V_5 -> V_293 . V_294 == V_295 && V_5 -> V_89 == V_90 ) ) {
return - V_157 ;
}
V_287 = V_28 ;
F_13 () ;
return 0 ;
}
int F_138 ( int V_77 )
{
static int V_296 ;
if ( V_77 != - 1 )
return F_139 ( & V_296 , V_77 ) ;
else
return V_296 ;
}
static void F_140 ( struct V_297 * V_298 , const char * V_26 , unsigned V_38 )
{
struct V_4 * V_5 = V_102 [ V_13 ] . V_30 ;
unsigned char V_9 ;
static F_141 ( V_299 ) ;
const T_6 * V_37 ;
T_6 V_70 = 0 ;
T_6 V_300 ;
int V_301 ;
if ( ! V_302 )
return;
if ( ! F_142 ( & V_299 ) )
return;
V_301 = F_143 () ;
if ( V_301 && F_46 ( V_301 - 1 ) )
V_5 = V_102 [ V_301 - 1 ] . V_30 ;
V_300 = V_5 -> V_80 ;
if ( ! F_46 ( V_13 ) ) {
goto V_303;
}
if ( V_5 -> V_89 != V_289 && ! F_43 ( V_5 ) )
goto V_303;
if ( F_8 ( V_5 ) )
F_23 ( V_5 ) ;
V_37 = ( T_6 * ) V_5 -> V_79 ;
while ( V_38 -- ) {
V_9 = * V_26 ++ ;
if ( V_9 == 10 || V_9 == 13 || V_9 == 8 || V_5 -> V_81 ) {
if ( V_70 > 0 ) {
if ( F_10 ( V_5 ) )
V_5 -> V_19 -> V_47 ( V_5 , V_37 , V_70 , V_5 -> V_85 , V_5 -> V_80 ) ;
V_5 -> V_80 += V_70 ;
if ( V_5 -> V_81 )
V_5 -> V_80 -- ;
V_70 = 0 ;
}
if ( V_9 == 8 ) {
F_82 ( V_5 ) ;
V_37 = ( T_6 * ) V_5 -> V_79 ;
V_300 = V_5 -> V_80 ;
continue;
}
if ( V_9 != 13 )
F_79 ( V_5 ) ;
F_81 ( V_5 ) ;
V_37 = ( T_6 * ) V_5 -> V_79 ;
V_300 = V_5 -> V_80 ;
if ( V_9 == 10 || V_9 == 13 )
continue;
}
F_28 ( ( V_5 -> V_61 << 8 ) + V_9 , ( unsigned short * ) V_5 -> V_79 ) ;
F_5 ( V_5 , V_9 ) ;
V_70 ++ ;
if ( V_300 == V_5 -> V_35 - 1 ) {
V_5 -> V_81 = 1 ;
continue;
}
V_5 -> V_79 += 2 ;
V_300 ++ ;
}
if ( V_70 > 0 ) {
if ( F_10 ( V_5 ) )
V_5 -> V_19 -> V_47 ( V_5 , V_37 , V_70 , V_5 -> V_85 , V_5 -> V_80 ) ;
V_5 -> V_80 += V_70 ;
if ( V_5 -> V_80 == V_5 -> V_35 ) {
V_5 -> V_80 -- ;
V_5 -> V_81 = 1 ;
}
}
F_24 ( V_5 ) ;
F_7 ( V_5 ) ;
V_303:
F_144 ( & V_299 ) ;
}
static struct V_304 * F_145 ( struct V_297 * V_9 , int * V_305 )
{
* V_305 = V_9 -> V_305 ? V_9 -> V_305 - 1 : V_13 ;
return V_306 ;
}
int F_146 ( struct V_138 * V_139 , unsigned long V_307 )
{
char type , V_308 ;
char T_7 * V_17 = ( char T_7 * ) V_307 ;
int V_22 ;
int V_170 ;
if ( V_309 -> signal -> V_139 != V_139 && ! F_147 ( V_310 ) )
return - V_311 ;
if ( F_148 ( type , V_17 ) )
return - V_312 ;
V_170 = 0 ;
switch ( type )
{
case V_313 :
F_71 () ;
V_170 = F_149 ( (struct V_314 T_7 * ) ( V_17 + 1 ) , V_139 ) ;
F_72 () ;
break;
case V_315 :
V_170 = F_150 ( V_139 ) ;
break;
case V_316 :
F_71 () ;
F_151 () ;
F_72 () ;
break;
case V_317 :
F_71 () ;
V_170 = F_152 ( V_17 ) ;
F_72 () ;
break;
case V_318 :
V_308 = F_153 () ;
V_170 = F_154 ( V_308 , V_17 ) ;
break;
case V_319 :
F_71 () ;
V_308 = F_103 () ;
F_72 () ;
V_170 = F_154 ( V_308 , V_17 ) ;
break;
case V_320 :
F_71 () ;
V_170 = F_155 ( V_17 ) ;
F_72 () ;
break;
case V_321 :
V_308 = F_143 () ;
V_170 = F_154 ( V_308 , V_17 ) ;
break;
case V_322 :
if ( ! F_147 ( V_310 ) ) {
V_170 = - V_311 ;
} else {
if ( F_148 ( V_308 , V_17 + 1 ) )
V_170 = - V_312 ;
else
F_138 ( V_308 ) ;
}
break;
case V_323 :
V_170 = V_13 ;
break;
case V_324 :
if ( F_148 ( V_22 , ( V_325 T_7 * ) ( V_17 + 4 ) ) ) {
V_170 = - V_312 ;
} else {
F_71 () ;
F_78 ( V_102 [ V_13 ] . V_30 , V_22 ) ;
F_72 () ;
V_170 = 0 ;
}
break;
case V_326 :
F_71 () ;
V_327 = 1 ;
F_137 ( 0 ) ;
F_72 () ;
break;
case V_328 :
V_170 = V_14 ;
break;
default:
V_170 = - V_157 ;
break;
}
return V_170 ;
}
static int F_156 ( struct V_138 * V_139 , const unsigned char * V_199 , int V_38 )
{
int V_329 ;
V_329 = F_128 ( V_139 , V_199 , V_38 ) ;
F_157 ( V_139 ) ;
return V_329 ;
}
static int F_158 ( struct V_138 * V_139 , unsigned char V_330 )
{
if ( F_129 () )
return 0 ;
return F_128 ( V_139 , & V_330 , 1 ) ;
}
static int F_159 ( struct V_138 * V_139 )
{
if ( V_139 -> V_276 )
return 0 ;
return 32768 ;
}
static int F_160 ( struct V_138 * V_139 )
{
return 0 ;
}
static void F_161 ( struct V_138 * V_139 )
{
}
static void F_162 ( struct V_138 * V_139 )
{
struct V_4 * V_5 = V_139 -> V_169 ;
F_163 ( & V_5 -> V_331 ) ;
}
static void F_164 ( struct V_138 * V_139 )
{
int V_332 ;
if ( ! V_139 )
return;
V_332 = V_139 -> V_305 ;
if ( ! F_46 ( V_332 ) )
return;
F_165 ( V_332 ) ;
}
static void F_166 ( struct V_138 * V_139 )
{
int V_332 ;
if ( ! V_139 )
return;
V_332 = V_139 -> V_305 ;
if ( ! F_46 ( V_332 ) )
return;
F_167 ( V_332 ) ;
}
static void F_157 ( struct V_138 * V_139 )
{
struct V_4 * V_5 ;
if ( F_129 () )
return;
F_71 () ;
V_5 = V_139 -> V_169 ;
if ( V_5 )
F_24 ( V_5 ) ;
F_72 () ;
}
static int F_168 ( struct V_304 * V_333 , struct V_138 * V_139 )
{
unsigned int V_123 = V_139 -> V_305 ;
struct V_4 * V_5 ;
int V_170 ;
F_71 () ;
V_170 = F_52 ( V_123 ) ;
if ( V_170 )
goto V_334;
V_5 = V_102 [ V_123 ] . V_30 ;
if ( V_5 -> V_127 . V_139 ) {
V_170 = - V_335 ;
goto V_334;
}
V_170 = F_169 ( & V_5 -> V_127 , V_333 , V_139 ) ;
if ( V_170 )
goto V_334;
V_139 -> V_169 = V_5 ;
V_5 -> V_127 . V_139 = V_139 ;
if ( ! V_139 -> V_161 . V_163 && ! V_139 -> V_161 . V_164 ) {
V_139 -> V_161 . V_163 = V_102 [ V_123 ] . V_30 -> V_32 ;
V_139 -> V_161 . V_164 = V_102 [ V_123 ] . V_30 -> V_35 ;
}
if ( V_5 -> V_237 )
V_139 -> V_336 . V_337 |= V_338 ;
else
V_139 -> V_336 . V_337 &= ~ V_338 ;
V_334:
F_72 () ;
return V_170 ;
}
static int F_170 ( struct V_138 * V_139 , struct V_339 * V_340 )
{
return 0 ;
}
static void F_171 ( struct V_138 * V_139 , struct V_339 * V_340 )
{
}
static void F_172 ( struct V_138 * V_139 )
{
struct V_4 * V_5 = V_139 -> V_169 ;
F_173 ( V_5 == NULL ) ;
F_71 () ;
V_5 -> V_127 . V_139 = NULL ;
F_72 () ;
}
static void F_58 ( struct V_4 * V_5 , unsigned int V_168 ,
unsigned int V_140 , int V_232 )
{
int V_253 , V_341 ;
V_5 -> V_35 = V_140 ;
V_5 -> V_32 = V_168 ;
V_5 -> V_33 = V_140 << 1 ;
V_5 -> V_75 = V_5 -> V_32 * V_5 -> V_33 ;
F_36 ( V_5 ) ;
V_5 -> V_79 = V_5 -> V_18 ;
F_174 ( V_5 ) ;
for ( V_253 = V_341 = 0 ; V_253 < 16 ; V_253 ++ ) {
V_5 -> V_254 [ V_341 ++ ] = V_342 [ V_253 ] ;
V_5 -> V_254 [ V_341 ++ ] = V_343 [ V_253 ] ;
V_5 -> V_254 [ V_341 ++ ] = V_344 [ V_253 ] ;
}
V_5 -> V_182 = V_345 ;
V_5 -> V_58 = V_346 ;
V_5 -> V_57 = V_347 ;
V_5 -> V_59 = 0x08 ;
F_175 ( & V_5 -> V_331 ) ;
F_116 ( V_5 , V_232 ) ;
}
static int T_8 V_121 ( void )
{
const char * V_348 = NULL ;
struct V_4 * V_5 ;
unsigned int V_123 = 0 , V_82 ;
F_71 () ;
if ( V_113 )
V_348 = V_113 -> V_349 () ;
if ( ! V_348 ) {
V_13 = 0 ;
F_72 () ;
return 0 ;
}
for ( V_82 = 0 ; V_82 < V_350 ; V_82 ++ ) {
struct V_351 * V_351 = & V_352 [ V_82 ] ;
if ( V_351 -> V_353 == NULL ) {
V_351 -> V_353 = V_113 ;
V_351 -> V_354 = V_348 ;
V_351 -> V_355 = V_356 ;
V_351 -> V_262 = 0 ;
V_351 -> V_263 = V_109 - 1 ;
break;
}
}
for ( V_82 = 0 ; V_82 < V_109 ; V_82 ++ )
V_114 [ V_82 ] = V_113 ;
if ( V_212 ) {
V_357 = V_358 ;
F_176 ( & V_359 , V_360 + ( V_212 * V_218 ) ) ;
}
for ( V_123 = 0 ; V_123 < V_361 ; V_123 ++ ) {
V_102 [ V_123 ] . V_30 = V_5 = F_53 ( sizeof( struct V_4 ) , V_362 ) ;
F_55 ( & V_102 [ V_123 ] . V_128 , V_129 ) ;
F_54 ( & V_5 -> V_127 ) ;
F_47 ( V_5 , V_123 , 1 ) ;
V_5 -> V_94 = F_53 ( V_5 -> V_75 , V_362 ) ;
F_58 ( V_5 , V_5 -> V_32 , V_5 -> V_35 ,
V_123 || ! V_5 -> V_19 -> V_96 ) ;
}
V_123 = V_13 = 0 ;
V_115 = V_5 = V_102 [ V_123 ] . V_30 ;
F_36 ( V_5 ) ;
F_37 ( V_5 ) ;
F_64 ( V_5 , V_5 -> V_80 , V_5 -> V_85 ) ;
F_84 ( V_5 , 0 ) ;
F_67 ( V_5 ) ;
F_177 ( L_7 ,
V_5 -> V_56 ? L_8 : L_9 ,
V_348 , V_5 -> V_35 , V_5 -> V_32 ) ;
V_302 = 1 ;
F_72 () ;
#ifdef F_178
F_179 ( & V_363 ) ;
#endif
return 0 ;
}
static T_9 F_180 ( struct V_364 * V_365 ,
struct V_366 * V_367 , char * V_199 )
{
return sprintf ( V_199 , L_10 , V_13 + 1 ) ;
}
int T_8 F_181 ( const struct V_368 * V_369 )
{
F_182 ( & V_370 , V_369 ) ;
if ( F_183 ( & V_370 , F_184 ( V_371 , 0 ) , 1 ) ||
F_185 ( F_184 ( V_371 , 0 ) , 1 , L_11 ) < 0 )
F_186 ( L_12 ) ;
V_104 = F_187 ( V_372 , NULL ,
F_184 ( V_371 , 0 ) , NULL ,
V_373 , L_13 ) ;
if ( F_188 ( V_104 ) )
V_104 = NULL ;
F_189 () ;
V_306 = F_190 ( V_109 ) ;
if ( ! V_306 )
F_186 ( L_14 ) ;
V_306 -> V_374 = L_15 ;
V_306 -> V_375 = 1 ;
V_306 -> V_376 = V_371 ;
V_306 -> V_377 = 1 ;
V_306 -> type = V_378 ;
V_306 -> V_379 = V_380 ;
if ( V_238 )
V_306 -> V_379 . V_337 |= V_338 ;
V_306 -> V_381 = V_382 | V_383 ;
F_191 ( V_306 , & V_384 ) ;
if ( F_192 ( V_306 ) )
F_186 ( L_16 ) ;
F_193 () ;
F_194 () ;
#ifdef F_195
F_196 () ;
#endif
return 0 ;
}
static int F_197 ( const struct V_385 * V_386 , int V_262 , int V_263 ,
int V_387 )
{
struct V_388 * V_112 = V_386 -> V_112 ;
const char * V_354 = NULL ;
struct V_351 * V_351 ;
int V_82 , V_253 = - 1 , V_341 = - 1 , V_329 = - V_389 ;
if ( ! F_198 ( V_112 ) )
return - V_389 ;
F_22 () ;
for ( V_82 = 0 ; V_82 < V_350 ; V_82 ++ ) {
V_351 = & V_352 [ V_82 ] ;
if ( V_351 -> V_353 == V_386 ) {
V_354 = V_351 -> V_354 ;
V_329 = 0 ;
break;
}
}
if ( V_329 )
goto V_136;
if ( ! ( V_351 -> V_355 & V_356 ) ) {
V_386 -> V_349 () ;
V_351 -> V_355 |= V_356 ;
}
if ( V_387 ) {
if ( V_113 )
F_48 ( V_113 -> V_112 ) ;
F_50 ( V_112 ) ;
V_113 = V_386 ;
}
V_262 = V_187 ( V_262 , V_351 -> V_262 ) ;
V_263 = F_63 ( V_263 , V_351 -> V_263 ) ;
for ( V_82 = V_262 ; V_82 <= V_263 ; V_82 ++ ) {
int V_107 ;
struct V_4 * V_5 = V_102 [ V_82 ] . V_30 ;
if ( V_114 [ V_82 ] )
F_48 ( V_114 [ V_82 ] -> V_112 ) ;
F_50 ( V_112 ) ;
V_114 [ V_82 ] = V_386 ;
if ( ! V_5 || ! V_5 -> V_19 )
continue;
V_253 = V_82 ;
if ( F_10 ( V_5 ) ) {
V_341 = V_82 ;
F_37 ( V_5 ) ;
}
V_107 = V_5 -> V_56 ;
V_5 -> V_19 -> V_172 ( V_5 ) ;
V_5 -> V_18 = ( unsigned long ) V_5 -> V_94 ;
F_47 ( V_5 , V_82 , 0 ) ;
F_36 ( V_5 ) ;
F_26 ( V_5 ) ;
if ( V_107 != V_5 -> V_56 )
F_39 ( V_5 ) ;
}
F_177 ( L_17 ) ;
if ( ! V_387 )
F_131 ( V_390 L_18 , V_262 + 1 , V_263 + 1 ) ;
if ( V_253 >= 0 ) {
struct V_4 * V_5 = V_102 [ V_253 ] . V_30 ;
F_131 ( V_390 L_19 ,
V_5 -> V_56 ? L_8 : L_9 ,
V_354 , V_5 -> V_35 , V_5 -> V_32 ) ;
if ( V_341 >= 0 ) {
V_5 = V_102 [ V_341 ] . V_30 ;
F_67 ( V_5 ) ;
}
} else
F_131 ( V_390 L_20 , V_354 ) ;
V_329 = 0 ;
V_136:
F_48 ( V_112 ) ;
return V_329 ;
}
int F_199 ( const struct V_385 * V_386 , int V_262 , int V_263 , int V_387 )
{
struct V_388 * V_112 = V_386 -> V_112 ;
const struct V_385 * V_391 = NULL ;
struct V_351 * V_351 = NULL , * V_392 = NULL ;
int V_82 , V_329 = - V_389 ;
if ( ! F_198 ( V_112 ) )
return - V_389 ;
F_22 () ;
for ( V_82 = 0 ; V_82 < V_350 ; V_82 ++ ) {
V_351 = & V_352 [ V_82 ] ;
if ( V_351 -> V_353 == V_386 &&
V_351 -> V_355 & V_393 ) {
V_329 = 0 ;
break;
}
}
if ( V_329 )
goto V_136;
V_329 = - V_389 ;
for ( V_82 = 0 ; V_82 < V_350 ; V_82 ++ ) {
V_392 = & V_352 [ V_82 ] ;
if ( V_392 -> V_353 && V_392 -> V_353 != V_386 ) {
V_391 = V_392 -> V_353 ;
V_329 = 0 ;
break;
}
}
if ( V_329 )
goto V_136;
if ( ! F_200 ( V_386 ) )
goto V_136;
V_262 = V_187 ( V_262 , V_351 -> V_262 ) ;
V_263 = F_63 ( V_263 , V_351 -> V_263 ) ;
for ( V_82 = V_262 ; V_82 <= V_263 ; V_82 ++ ) {
if ( V_114 [ V_82 ] == V_386 ) {
F_48 ( V_386 -> V_112 ) ;
V_114 [ V_82 ] = NULL ;
}
}
if ( ! F_200 ( V_391 ) ) {
const struct V_385 * V_394 = V_113 ;
V_391 -> V_349 () ;
V_392 -> V_355 |= V_356 ;
V_113 = V_394 ;
}
if ( ! F_200 ( V_386 ) )
V_351 -> V_355 &= ~ V_356 ;
F_197 ( V_391 , V_262 , V_263 , V_387 ) ;
V_136:
F_48 ( V_112 ) ;
return V_329 ;
}
static int F_201 ( struct V_351 * V_353 )
{
const struct V_385 * V_391 = NULL , * V_386 = NULL ;
int V_82 , V_395 = 1 , V_262 = - 1 , V_263 = - 1 , V_387 = 0 ;
if ( ! V_353 -> V_353 || ! ( V_353 -> V_355 & V_393 ) )
goto V_136;
V_386 = V_353 -> V_353 ;
for ( V_82 = 0 ; V_82 < V_350 ; V_82 ++ ) {
struct V_351 * V_353 = & V_352 [ V_82 ] ;
if ( V_353 -> V_353 && ! ( V_353 -> V_355 & V_393 ) ) {
V_391 = V_353 -> V_353 ;
break;
}
}
if ( ! V_391 )
goto V_136;
while ( V_395 ) {
V_395 = 0 ;
for ( V_82 = V_353 -> V_262 ; V_82 <= V_353 -> V_263 ; V_82 ++ ) {
if ( V_114 [ V_82 ] == V_391 ) {
if ( V_262 == - 1 )
V_262 = V_82 ;
V_263 = V_82 ;
V_395 = 1 ;
} else if ( V_262 != - 1 )
break;
}
if ( V_262 == 0 && V_263 == V_109 - 1 )
V_387 = 1 ;
if ( V_262 != - 1 )
F_197 ( V_386 , V_262 , V_263 , V_387 ) ;
V_262 = - 1 ;
V_263 = - 1 ;
V_387 = 0 ;
}
V_136:
return 0 ;
}
static int F_202 ( struct V_351 * V_353 )
{
const struct V_385 * V_386 = NULL ;
int V_82 , V_395 = 1 , V_262 = - 1 , V_263 = - 1 , V_387 = 0 ;
int V_170 ;
if ( ! V_353 -> V_353 || ! ( V_353 -> V_355 & V_393 ) )
goto V_136;
V_386 = V_353 -> V_353 ;
while ( V_395 ) {
V_395 = 0 ;
for ( V_82 = V_353 -> V_262 ; V_82 <= V_353 -> V_263 ; V_82 ++ ) {
if ( V_114 [ V_82 ] == V_386 ) {
if ( V_262 == - 1 )
V_262 = V_82 ;
V_263 = V_82 ;
V_395 = 1 ;
} else if ( V_262 != - 1 )
break;
}
if ( V_262 == 0 && V_263 == V_109 - 1 )
V_387 = 1 ;
if ( V_262 != - 1 ) {
V_170 = F_199 ( V_386 , V_262 , V_263 , V_387 ) ;
if ( V_170 != 0 )
return V_170 ;
}
V_262 = - 1 ;
V_263 = - 1 ;
V_387 = 0 ;
}
V_136:
return 0 ;
}
static inline int F_201 ( struct V_351 * V_353 )
{
return 0 ;
}
static inline int F_202 ( struct V_351 * V_353 )
{
return 0 ;
}
static T_9 F_203 ( struct V_364 * V_365 , struct V_366 * V_367 ,
const char * V_199 , T_10 V_38 )
{
struct V_351 * V_353 = F_204 ( V_365 ) ;
int V_396 = F_205 ( V_199 , NULL , 0 ) ;
F_71 () ;
if ( V_396 )
F_201 ( V_353 ) ;
else
F_202 ( V_353 ) ;
F_72 () ;
return V_38 ;
}
static T_9 F_206 ( struct V_364 * V_365 , struct V_366 * V_367 ,
char * V_199 )
{
struct V_351 * V_353 = F_204 ( V_365 ) ;
int V_396 = F_200 ( V_353 -> V_353 ) ;
return snprintf ( V_199 , V_397 , L_21 , V_396 ) ;
}
static T_9 F_207 ( struct V_364 * V_365 , struct V_366 * V_367 ,
char * V_199 )
{
struct V_351 * V_353 = F_204 ( V_365 ) ;
return snprintf ( V_199 , V_397 , L_22 ,
( V_353 -> V_355 & V_393 ) ? L_23 : L_24 ,
V_353 -> V_354 ) ;
}
static int F_208 ( struct V_351 * V_353 )
{
V_353 -> V_355 |= V_398 ;
return 0 ;
}
static void F_209 ( struct V_351 * V_353 )
{
V_353 -> V_355 &= ~ V_398 ;
}
int F_200 ( const struct V_385 * V_386 )
{
int V_82 , V_399 = 0 ;
for ( V_82 = 0 ; V_82 < V_109 ; V_82 ++ ) {
if ( V_114 [ V_82 ] == V_386 ) {
V_399 = 1 ;
break;
}
}
return V_399 ;
}
int F_210 ( struct V_4 * V_5 )
{
int V_170 = 0 ;
V_400 = V_13 ;
V_401 = V_219 ;
V_402 = V_287 ;
V_403 = V_5 -> V_89 ;
V_404 = V_14 ;
V_5 -> V_89 = V_289 ;
V_14 = 0 ;
if ( V_5 -> V_19 -> F_210 )
V_170 = V_5 -> V_19 -> F_210 ( V_5 ) ;
#ifdef F_211
if ( V_5 -> V_32 < 999 ) {
int V_405 ;
char V_406 [ 4 ] ;
const char * V_407 [ 3 ] = {
L_25 ,
L_26 ,
V_406 ,
} ;
if ( F_212 ( V_407 [ 0 ] , & V_405 ) ) {
snprintf ( V_406 , 4 , L_27 , V_5 -> V_32 ) ;
F_213 ( 2 , V_407 ) ;
}
}
if ( V_5 -> V_35 < 999 ) {
int V_408 ;
char V_140 [ 4 ] ;
const char * V_407 [ 3 ] = {
L_25 ,
L_28 ,
V_140 ,
} ;
if ( F_212 ( V_407 [ 0 ] , & V_408 ) ) {
snprintf ( V_140 , 4 , L_27 , V_5 -> V_35 ) ;
F_213 ( 2 , V_407 ) ;
}
}
#endif
return V_170 ;
}
int F_214 ( void )
{
struct V_4 * V_5 ;
int V_170 = 0 ;
V_13 = V_400 ;
V_219 = V_401 ;
V_287 = V_402 ;
V_14 = V_404 ;
V_102 [ V_13 ] . V_30 -> V_89 = V_403 ;
V_5 = V_102 [ V_13 ] . V_30 ;
if ( V_5 -> V_19 -> F_214 )
V_170 = V_5 -> V_19 -> F_214 ( V_5 ) ;
return V_170 ;
}
static int F_215 ( const struct V_385 * V_386 , int V_262 , int V_263 )
{
struct V_388 * V_112 = V_386 -> V_112 ;
struct V_351 * V_351 ;
const char * V_354 ;
int V_82 , V_329 ;
F_22 () ;
if ( ! F_198 ( V_112 ) )
return - V_389 ;
for ( V_82 = 0 ; V_82 < V_350 ; V_82 ++ ) {
V_351 = & V_352 [ V_82 ] ;
if ( V_351 -> V_353 == V_386 ) {
V_329 = - V_409 ;
goto V_136;
}
}
V_354 = V_386 -> V_349 () ;
if ( ! V_354 ) {
V_329 = - V_389 ;
goto V_136;
}
V_329 = - V_157 ;
for ( V_82 = 0 ; V_82 < V_350 ; V_82 ++ ) {
V_351 = & V_352 [ V_82 ] ;
if ( V_351 -> V_353 == NULL &&
! ( V_351 -> V_355 & V_410 ) ) {
V_351 -> V_353 = V_386 ;
V_351 -> V_354 = V_354 ;
V_351 -> V_411 = V_82 ;
V_351 -> V_355 = V_393 |
V_356 ;
V_351 -> V_262 = V_262 ;
V_351 -> V_263 = V_263 ;
V_329 = 0 ;
break;
}
}
if ( V_329 )
goto V_136;
V_351 -> V_365 =
F_187 ( V_412 , NULL ,
F_184 ( 0 , V_351 -> V_411 ) ,
V_351 , V_413 ,
L_29 , V_351 -> V_411 ) ;
if ( F_188 ( V_351 -> V_365 ) ) {
F_131 ( V_414 L_30
L_31 , V_351 -> V_354 ,
F_216 ( V_351 -> V_365 ) ) ;
V_351 -> V_365 = NULL ;
} else {
F_208 ( V_351 ) ;
}
V_136:
F_48 ( V_112 ) ;
return V_329 ;
}
int F_217 ( const struct V_385 * V_386 )
{
int V_82 ;
if ( F_200 ( V_386 ) )
return - V_409 ;
if ( V_386 == V_113 )
return - V_157 ;
for ( V_82 = 0 ; V_82 < V_350 ; V_82 ++ ) {
struct V_351 * V_351 = & V_352 [ V_82 ] ;
if ( V_351 -> V_353 == V_386 ) {
V_351 -> V_353 = NULL ;
V_351 -> V_355 = V_410 ;
F_14 ( & V_415 ) ;
return 0 ;
}
}
return - V_389 ;
}
static void F_218 ( struct V_285 * V_286 )
{
int V_82 ;
F_71 () ;
for ( V_82 = 0 ; V_82 < V_350 ; V_82 ++ ) {
struct V_351 * V_351 = & V_352 [ V_82 ] ;
if ( ! ( V_351 -> V_355 & V_410 ) )
continue;
F_72 () ;
F_209 ( V_351 ) ;
F_219 ( V_412 , F_184 ( 0 , V_351 -> V_411 ) ) ;
F_71 () ;
if ( F_220 ( V_351 -> V_353 ) )
V_351 -> V_353 = NULL ;
V_351 -> V_354 = NULL ;
V_351 -> V_365 = NULL ;
V_351 -> V_411 = 0 ;
F_220 ( V_351 -> V_355 != V_410 ) ;
V_351 -> V_355 = 0 ;
V_351 -> V_262 = 0 ;
V_351 -> V_263 = 0 ;
}
F_72 () ;
}
int F_221 ( const struct V_385 * V_386 , int V_262 , int V_263 , int V_387 )
{
int V_136 ;
V_136 = F_215 ( V_386 , V_262 , V_263 ) ;
if ( V_136 == - V_409 )
V_136 = 0 ;
if ( ! V_136 )
F_197 ( V_386 , V_262 , V_263 , V_387 ) ;
return V_136 ;
}
void F_222 ( const struct V_385 * V_386 )
{
F_71 () ;
F_217 ( V_386 ) ;
F_72 () ;
}
static int T_8 F_223 ( void )
{
int V_82 ;
V_412 = F_224 ( V_416 , L_32 ) ;
if ( F_188 ( V_412 ) ) {
F_131 ( V_414 L_33
L_31 , F_216 ( V_412 ) ) ;
V_412 = NULL ;
}
for ( V_82 = 0 ; V_82 < V_350 ; V_82 ++ ) {
struct V_351 * V_353 = & V_352 [ V_82 ] ;
if ( V_353 -> V_353 && ! V_353 -> V_365 ) {
V_353 -> V_365 =
F_187 ( V_412 , NULL ,
F_184 ( 0 , V_353 -> V_411 ) ,
V_353 , V_413 ,
L_29 , V_353 -> V_411 ) ;
if ( F_188 ( V_353 -> V_365 ) ) {
F_131 ( V_414 L_34
L_35 ,
V_353 -> V_354 , F_216 ( V_353 -> V_365 ) ) ;
V_353 -> V_365 = NULL ;
} else {
F_208 ( V_353 ) ;
}
}
}
return 0 ;
}
static int F_155 ( char T_7 * V_17 )
{
unsigned int V_294 ;
if ( F_148 ( V_294 , V_17 + 1 ) )
return - V_312 ;
V_417 = ( V_294 < 4 ) ? V_294 : 0 ;
return 0 ;
}
void F_137 ( int V_418 )
{
struct V_4 * V_5 = V_102 [ V_13 ] . V_30 ;
int V_82 ;
F_22 () ;
if ( V_14 ) {
if ( V_357 == V_419 ) {
V_357 = V_420 ;
V_5 -> V_19 -> V_421 ( V_5 , V_417 + 1 , 0 ) ;
}
return;
}
if ( V_418 ) {
F_23 ( V_5 ) ;
F_37 ( V_5 ) ;
V_5 -> V_19 -> V_421 ( V_5 , - 1 , 1 ) ;
V_14 = V_13 + 1 ;
V_357 = V_420 ;
F_36 ( V_5 ) ;
return;
}
if ( V_357 != V_358 )
return;
V_357 = V_420 ;
if ( V_5 -> V_89 != V_289 ) {
V_14 = V_13 + 1 ;
return;
}
F_23 ( V_5 ) ;
F_225 ( & V_359 ) ;
V_291 = 0 ;
F_37 ( V_5 ) ;
V_82 = V_5 -> V_19 -> V_421 ( V_5 , V_217 ? 1 : ( V_417 + 1 ) , 0 ) ;
V_14 = V_13 + 1 ;
if ( V_82 )
F_36 ( V_5 ) ;
if ( V_422 && V_422 ( 1 ) )
return;
if ( V_217 && V_417 ) {
V_357 = V_419 ;
F_176 ( & V_359 , V_360 + V_217 ) ;
}
F_68 ( V_423 , V_5 -> V_12 , V_5 -> V_12 ) ;
}
void F_226 ( int V_424 )
{
struct V_4 * V_5 ;
if ( ! V_425 )
F_130 () ;
F_22 () ;
V_327 = 0 ;
if ( ! V_14 )
return;
if ( ! F_46 ( V_13 ) ) {
F_227 ( L_36 ,
V_13 + 1 ) ;
return;
}
V_5 = V_102 [ V_13 ] . V_30 ;
if ( V_5 -> V_89 != V_289 && ! F_43 ( V_5 ) )
return;
if ( V_212 ) {
F_176 ( & V_359 , V_360 + ( V_212 * V_218 ) ) ;
V_357 = V_358 ;
}
V_14 = 0 ;
if ( V_5 -> V_19 -> V_421 ( V_5 , 0 , V_424 ) || F_43 ( V_5 ) )
F_67 ( V_5 ) ;
if ( V_422 )
V_422 ( 0 ) ;
F_42 ( V_5 ) ;
F_24 ( V_5 ) ;
F_68 ( V_426 , V_5 -> V_12 , V_5 -> V_12 ) ;
}
void F_151 ( void )
{
F_226 ( 0 ) ;
}
static void F_228 ( unsigned long V_427 )
{
V_291 = 1 ;
F_14 ( & V_24 ) ;
}
void F_108 ( void )
{
F_22 () ;
F_130 () ;
F_229 ( & V_359 ) ;
V_291 = 0 ;
if ( V_327 || ! V_102 [ V_13 ] . V_30 || V_102 [ V_13 ] . V_30 -> V_89 == V_90 )
return;
if ( V_14 )
F_151 () ;
else if ( V_212 ) {
F_176 ( & V_359 , V_360 + ( V_212 * V_218 ) ) ;
V_357 = V_358 ;
}
}
static void F_42 ( struct V_4 * V_5 )
{
F_22 () ;
if ( V_5 -> V_89 != V_90 && V_5 -> V_19 -> V_428 )
V_5 -> V_19 -> V_428 ( V_5 , V_197 ) ;
}
int F_230 ( unsigned char T_7 * V_307 )
{
int V_82 , V_253 , V_341 ;
unsigned char V_429 [ 3 * 16 ] ;
if ( F_231 ( V_429 , V_307 , sizeof( V_429 ) ) )
return - V_312 ;
F_71 () ;
for ( V_82 = V_341 = 0 ; V_82 < 16 ; V_82 ++ ) {
V_342 [ V_82 ] = V_429 [ V_341 ++ ] ;
V_343 [ V_82 ] = V_429 [ V_341 ++ ] ;
V_344 [ V_82 ] = V_429 [ V_341 ++ ] ;
}
for ( V_82 = 0 ; V_82 < V_109 ; V_82 ++ ) {
if ( ! F_46 ( V_82 ) )
continue;
for ( V_253 = V_341 = 0 ; V_253 < 16 ; V_253 ++ ) {
V_102 [ V_82 ] . V_30 -> V_254 [ V_341 ++ ] = V_342 [ V_253 ] ;
V_102 [ V_82 ] . V_30 -> V_254 [ V_341 ++ ] = V_343 [ V_253 ] ;
V_102 [ V_82 ] . V_30 -> V_254 [ V_341 ++ ] = V_344 [ V_253 ] ;
}
F_42 ( V_102 [ V_82 ] . V_30 ) ;
}
F_72 () ;
return 0 ;
}
int F_232 ( unsigned char T_7 * V_307 )
{
int V_82 , V_341 ;
unsigned char V_429 [ 3 * 16 ] ;
F_71 () ;
for ( V_82 = V_341 = 0 ; V_82 < 16 ; V_82 ++ ) {
V_429 [ V_341 ++ ] = V_342 [ V_82 ] ;
V_429 [ V_341 ++ ] = V_343 [ V_82 ] ;
V_429 [ V_341 ++ ] = V_344 [ V_82 ] ;
}
F_72 () ;
if ( F_233 ( V_307 , V_429 , sizeof( V_429 ) ) )
return - V_312 ;
return 0 ;
}
void F_121 ( struct V_4 * V_5 )
{
int V_253 , V_341 ;
for ( V_253 = V_341 = 0 ; V_253 < 16 ; V_253 ++ ) {
V_5 -> V_254 [ V_341 ++ ] = V_342 [ V_253 ] ;
V_5 -> V_254 [ V_341 ++ ] = V_343 [ V_253 ] ;
V_5 -> V_254 [ V_341 ++ ] = V_344 [ V_253 ] ;
}
F_42 ( V_5 ) ;
}
static int F_234 ( struct V_4 * V_5 , struct V_430 * V_431 )
{
struct V_432 V_433 ;
int V_434 = - V_157 ;
int V_9 ;
if ( V_431 -> V_308 ) {
V_433 . V_308 = F_57 ( V_435 , V_125 ) ;
if ( ! V_433 . V_308 )
return - V_126 ;
} else
V_433 . V_308 = NULL ;
F_71 () ;
if ( V_5 -> V_89 != V_289 )
V_434 = - V_157 ;
else if ( V_5 -> V_19 -> F_234 )
V_434 = V_5 -> V_19 -> F_234 ( V_5 , & V_433 ) ;
else
V_434 = - V_436 ;
F_72 () ;
if ( V_434 )
goto V_437;
V_9 = ( V_433 . V_133 + 7 ) / 8 * 32 * V_433 . V_438 ;
if ( V_431 -> V_308 && V_433 . V_438 > V_431 -> V_438 )
V_434 = - V_439 ;
if ( ! ( V_431 -> V_381 & V_440 ) ) {
if ( V_433 . V_133 > V_431 -> V_133 || V_433 . V_134 > V_431 -> V_134 )
V_434 = - V_439 ;
} else {
if ( V_433 . V_133 != 8 )
V_434 = - V_441 ;
else if ( ( V_431 -> V_134 && V_433 . V_134 > V_431 -> V_134 ) ||
V_433 . V_134 > 32 )
V_434 = - V_439 ;
}
if ( V_434 )
goto V_437;
V_431 -> V_134 = V_433 . V_134 ;
V_431 -> V_133 = V_433 . V_133 ;
V_431 -> V_438 = V_433 . V_438 ;
if ( V_431 -> V_308 && F_233 ( V_431 -> V_308 , V_433 . V_308 , V_9 ) )
V_434 = - V_312 ;
V_437:
F_60 ( V_433 . V_308 ) ;
return V_434 ;
}
static int F_235 ( struct V_4 * V_5 , struct V_430 * V_431 )
{
struct V_432 V_433 ;
int V_434 = - V_157 ;
int V_442 ;
if ( V_5 -> V_89 != V_289 )
return - V_157 ;
if ( ! V_431 -> V_308 )
return - V_157 ;
if ( V_431 -> V_438 > 512 )
return - V_157 ;
if ( ! V_431 -> V_134 ) {
int V_443 , V_82 ;
T_2 T_7 * V_444 = V_431 -> V_308 ;
T_2 V_445 ;
if ( ! ( V_431 -> V_381 & V_440 ) )
return - V_157 ;
for ( V_443 = 32 ; V_443 > 0 ; V_443 -- )
for ( V_82 = 0 ; V_82 < V_431 -> V_438 ; V_82 ++ ) {
if ( F_148 ( V_445 , & V_444 [ 32 * V_82 + V_443 - 1 ] ) )
return - V_312 ;
if ( V_445 )
goto V_446;
}
return - V_157 ;
V_446:
V_431 -> V_134 = V_443 ;
}
if ( V_431 -> V_133 <= 0 || V_431 -> V_133 > 32 || V_431 -> V_134 > 32 )
return - V_157 ;
V_442 = ( V_431 -> V_133 + 7 ) / 8 * 32 * V_431 -> V_438 ;
if ( V_442 > V_435 )
return - V_439 ;
V_433 . V_438 = V_431 -> V_438 ;
V_433 . V_134 = V_431 -> V_134 ;
V_433 . V_133 = V_431 -> V_133 ;
V_433 . V_308 = F_236 ( V_431 -> V_308 , V_442 ) ;
if ( F_188 ( V_433 . V_308 ) )
return F_216 ( V_433 . V_308 ) ;
F_71 () ;
if ( V_5 -> V_89 != V_289 )
V_434 = - V_157 ;
else if ( V_5 -> V_19 -> F_235 )
V_434 = V_5 -> V_19 -> F_235 ( V_5 , & V_433 , V_431 -> V_381 ) ;
else
V_434 = - V_436 ;
F_72 () ;
F_60 ( V_433 . V_308 ) ;
return V_434 ;
}
static int F_237 ( struct V_4 * V_5 , struct V_430 * V_431 )
{
struct V_432 V_433 = { . V_133 = V_431 -> V_133 , . V_134 = V_431 -> V_134 } ;
char V_374 [ V_447 ] ;
char * V_31 = V_374 ;
int V_434 ;
if ( ! V_431 -> V_308 )
V_31 = NULL ;
else if ( F_238 ( V_374 , V_431 -> V_308 , V_447 - 1 ) < 0 )
return - V_312 ;
else
V_374 [ V_447 - 1 ] = 0 ;
F_71 () ;
if ( V_5 -> V_89 != V_289 ) {
F_72 () ;
return - V_157 ;
}
if ( V_5 -> V_19 -> F_237 )
V_434 = V_5 -> V_19 -> F_237 ( V_5 , & V_433 , V_31 ) ;
else
V_434 = - V_436 ;
F_72 () ;
if ( ! V_434 ) {
V_431 -> V_133 = V_433 . V_133 ;
V_431 -> V_134 = V_433 . V_134 ;
}
return V_434 ;
}
static int F_239 ( struct V_4 * V_5 , struct V_430 * V_431 )
{
int V_353 = V_431 -> V_134 ;
int V_434 ;
F_71 () ;
if ( V_5 -> V_89 != V_289 )
V_434 = - V_157 ;
else if ( ! V_5 -> V_19 -> F_239 )
V_434 = - V_436 ;
else if ( V_353 < 0 || ! F_46 ( V_353 ) )
V_434 = - V_448 ;
else if ( V_353 == V_5 -> V_12 )
V_434 = 0 ;
else
V_434 = V_5 -> V_19 -> F_239 ( V_5 , V_353 ) ;
F_72 () ;
return V_434 ;
}
int F_240 ( struct V_4 * V_5 , struct V_430 * V_431 )
{
switch ( V_431 -> V_431 ) {
case V_449 :
return F_235 ( V_5 , V_431 ) ;
case V_450 :
return F_234 ( V_5 , V_431 ) ;
case V_451 :
return F_237 ( V_5 , V_431 ) ;
case V_452 :
return F_239 ( V_5 , V_431 ) ;
}
return - V_436 ;
}
T_1 F_241 ( struct V_4 * V_5 , int V_15 )
{
T_1 V_453 = F_20 ( F_11 ( V_5 , V_15 , 1 ) ) ;
T_1 V_9 = V_453 & 0xff ;
if ( V_453 & V_5 -> V_60 )
V_9 |= 0x100 ;
return V_9 ;
}
unsigned short * F_242 ( struct V_4 * V_5 , int V_454 , int V_16 )
{
return F_11 ( V_5 , 2 * V_454 , V_16 ) ;
}
void F_243 ( struct V_4 * V_5 , unsigned char * V_17 )
{
V_17 [ 0 ] = V_5 -> V_80 ;
V_17 [ 1 ] = V_5 -> V_85 ;
}
void F_244 ( struct V_4 * V_5 , unsigned char * V_17 )
{
F_23 ( V_5 ) ;
F_64 ( V_5 , V_17 [ 0 ] , V_17 [ 1 ] ) ;
F_24 ( V_5 ) ;
}
T_1 F_245 ( struct V_4 * V_5 , const T_1 * V_455 )
{
if ( ( unsigned long ) V_455 == V_5 -> V_79 && V_84 != - 1 )
return V_84 ;
return F_20 ( V_455 ) ;
}
void F_246 ( struct V_4 * V_5 , T_1 V_456 , T_1 * V_455 )
{
F_28 ( V_456 , V_455 ) ;
if ( ( unsigned long ) V_455 == V_5 -> V_79 ) {
V_84 = - 1 ;
F_33 ( V_5 ) ;
}
}
void F_247 ( struct V_4 * V_5 )
{
F_7 ( V_5 ) ;
}
void F_248 ( struct V_4 * V_9 , int V_22 ,
unsigned int V_457 , void * V_458 , unsigned int V_442 )
{
unsigned long V_459 = ( unsigned long ) V_458 ;
T_11 V_460 = ( void * ) V_9 -> V_95 - V_458 ;
T_11 V_461 = ( void * ) V_9 -> V_21 - V_458 ;
T_11 V_462 = ( void * ) V_9 -> V_18 - V_458 ;
int V_463 = V_9 -> V_33 * 4 ;
int V_464 , V_465 , V_466 , V_467 ;
if ( ! V_22 ) {
V_9 -> V_21 = V_9 -> V_18 ;
return;
}
if ( V_457 > V_460 + V_463 ) {
V_464 = V_460 ;
V_465 = V_457 + V_9 -> V_33 ;
} else {
V_464 = 0 ;
V_465 = V_442 ;
}
V_466 = ( V_461 - V_464 + V_465 ) % V_465 + V_22 * V_9 -> V_33 ;
V_467 = ( V_462 - V_464 + V_465 ) % V_465 ;
if ( V_467 < 2 * V_463 )
V_463 = 0 ;
if ( V_466 < V_463 )
V_466 = 0 ;
if ( V_466 > V_467 - V_463 )
V_466 = V_467 ;
V_9 -> V_21 = V_459 + ( V_464 + V_466 ) % V_465 ;
}
