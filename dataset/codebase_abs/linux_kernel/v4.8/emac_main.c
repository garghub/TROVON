static inline int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 + V_4 - V_2 -> V_5 - 1 ) % V_4 ;
}
static void F_2 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
unsigned int V_11 , V_12 = 0 ;
if ( V_2 -> V_13 != V_9 -> V_13 ) {
V_2 -> V_13 = V_9 -> V_13 ;
V_12 = 1 ;
}
if ( V_2 -> V_14 != V_9 -> V_14 ) {
V_2 -> V_14 = V_9 -> V_14 ;
V_12 = 1 ;
if ( V_2 -> V_15 )
V_2 -> V_15 ( V_2 , V_2 -> V_14 ) ;
}
if ( V_2 -> V_16 != V_9 -> V_16 ) {
V_11 = F_4 ( V_2 , V_17 ) ;
if ( V_9 -> V_16 == V_18 )
V_11 |= V_19 ;
else
V_11 &= ~ V_19 ;
F_5 ( V_2 , V_17 , V_11 ) ;
V_2 -> V_16 = V_9 -> V_16 ;
V_12 = 1 ;
}
if ( V_12 )
F_6 ( V_9 ) ;
}
static void F_7 ( struct V_6 * V_7 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
F_8 ( V_21 -> V_22 , V_2 -> V_23 , sizeof( V_21 -> V_22 ) ) ;
F_8 ( V_21 -> V_24 , V_2 -> V_25 , sizeof( V_21 -> V_24 ) ) ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
struct V_26 * V_27 = & V_7 -> V_27 ;
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 ; V_28 ++ ) {
unsigned int * V_3 = & V_2 -> V_3 ;
struct V_29 * V_30 = & V_2 -> V_30 [ * V_3 ] ;
struct V_31 * V_32 = & V_2 -> V_32 [ * V_3 ] ;
struct V_33 * V_34 = V_32 -> V_34 ;
unsigned int V_21 = F_10 ( V_30 -> V_21 ) ;
if ( ( V_21 & V_35 ) || ! V_30 -> V_36 || ! V_34 )
break;
if ( F_11 ( V_21 & ( V_37 | V_38 | V_39 | V_40 ) ) ) {
V_27 -> V_41 ++ ;
V_27 -> V_42 ++ ;
if ( V_21 & V_38 )
V_27 -> V_43 ++ ;
if ( V_21 & V_39 )
V_27 -> V_44 ++ ;
if ( V_21 & V_40 )
V_27 -> V_45 ++ ;
} else if ( F_12 ( V_21 & V_46 ) ) {
V_27 -> V_47 ++ ;
V_27 -> V_48 += V_34 -> V_49 ;
}
F_13 ( & V_7 -> V_50 , F_14 ( V_32 , V_51 ) ,
F_15 ( V_32 , V_49 ) , V_52 ) ;
F_16 ( V_34 ) ;
V_30 -> V_36 = 0 ;
V_30 -> V_21 = 0 ;
V_32 -> V_34 = NULL ;
* V_3 = ( * V_3 + 1 ) % V_4 ;
}
F_17 () ;
if ( F_18 ( V_7 ) && F_1 ( V_2 ) )
F_19 ( V_7 ) ;
}
static int F_20 ( struct V_6 * V_7 , int V_53 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ ) {
unsigned int * V_55 = & V_2 -> V_55 ;
struct V_26 * V_27 = & V_7 -> V_27 ;
struct V_31 * V_56 = & V_2 -> V_56 [ * V_55 ] ;
struct V_29 * V_57 = & V_2 -> V_57 [ * V_55 ] ;
unsigned int V_58 , V_21 = F_10 ( V_57 -> V_21 ) ;
struct V_33 * V_34 ;
T_1 V_51 ;
if ( F_11 ( ( V_21 & V_59 ) == V_35 ) )
break;
* V_55 = ( * V_55 + 1 ) % V_60 ;
if ( F_11 ( ( V_21 & V_46 ) !=
V_46 ) ) {
if ( F_21 () )
F_22 ( V_7 , L_1 ) ;
V_57 -> V_21 = F_23 ( V_35 | V_61 ) ;
V_27 -> V_62 ++ ;
V_27 -> V_63 ++ ;
continue;
}
V_58 = V_21 & V_64 ;
V_27 -> V_65 ++ ;
V_27 -> V_66 += V_58 ;
V_34 = V_56 -> V_34 ;
F_24 ( V_34 , V_58 ) ;
V_34 -> V_50 = V_7 ;
V_34 -> V_67 = F_25 ( V_34 , V_7 ) ;
F_13 ( & V_7 -> V_50 , F_14 ( V_56 , V_51 ) ,
F_15 ( V_56 , V_49 ) , V_68 ) ;
V_56 -> V_34 = F_26 ( V_7 ,
V_61 ) ;
if ( F_11 ( ! V_56 -> V_34 ) ) {
V_27 -> V_62 ++ ;
V_27 -> V_69 ++ ;
continue;
}
F_27 ( V_34 ) ;
V_51 = F_28 ( & V_7 -> V_50 , ( void * ) V_56 -> V_34 -> V_36 ,
V_61 , V_68 ) ;
if ( F_29 ( & V_7 -> V_50 , V_51 ) ) {
if ( F_21 () )
F_22 ( V_7 , L_2 ) ;
F_30 ( V_56 -> V_34 ) ;
V_27 -> V_62 ++ ;
continue;
}
F_31 ( V_56 , V_51 , V_51 ) ;
F_32 ( V_56 , V_49 , V_61 ) ;
V_57 -> V_36 = F_23 ( V_51 ) ;
F_33 () ;
V_57 -> V_21 = F_23 ( V_35 | V_61 ) ;
}
return V_54 ;
}
static int F_34 ( struct V_70 * V_71 , int V_53 )
{
struct V_6 * V_7 = V_71 -> V_50 ;
struct V_1 * V_2 = F_3 ( V_7 ) ;
unsigned int V_54 ;
F_9 ( V_7 ) ;
V_54 = F_20 ( V_7 , V_53 ) ;
if ( V_54 < V_53 ) {
F_35 ( V_71 ) ;
F_36 ( V_2 , V_72 , V_73 | V_74 ) ;
}
return V_54 ;
}
static T_2 F_37 ( int V_75 , void * V_76 )
{
struct V_6 * V_7 = V_76 ;
struct V_1 * V_2 = F_3 ( V_7 ) ;
struct V_26 * V_27 = & V_7 -> V_27 ;
unsigned int V_77 ;
V_77 = F_4 ( V_2 , V_78 ) ;
V_77 &= ~ V_79 ;
F_5 ( V_2 , V_78 , V_77 ) ;
if ( V_77 & ( V_73 | V_74 ) ) {
if ( F_12 ( F_38 ( & V_2 -> V_71 ) ) ) {
F_39 ( V_2 , V_72 , V_73 | V_74 ) ;
F_40 ( & V_2 -> V_71 ) ;
}
}
if ( V_77 & V_80 ) {
if ( V_77 & V_81 ) {
V_27 -> V_82 += 0x100 ;
V_27 -> V_62 += 0x100 ;
}
if ( V_77 & V_83 ) {
V_27 -> V_84 += 0x100 ;
V_27 -> V_62 += 0x100 ;
}
if ( V_77 & V_85 ) {
V_27 -> V_86 += 0x100 ;
V_27 -> V_62 += 0x100 ;
}
if ( V_77 & V_87 ) {
V_27 -> V_88 += 0x100 ;
V_27 -> V_62 += 0x100 ;
}
}
return V_89 ;
}
static void F_41 ( struct V_6 * V_50 )
{
F_42 ( V_50 -> V_75 ) ;
F_37 ( V_50 -> V_75 , V_50 ) ;
F_43 ( V_50 -> V_75 ) ;
}
static int F_44 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_28 ;
V_9 -> V_90 = V_91 ;
V_9 -> V_14 = 0 ;
V_9 -> V_16 = 0 ;
V_9 -> V_92 &= V_9 -> V_93 ;
V_2 -> V_55 = 0 ;
for ( V_28 = 0 ; V_28 < V_60 ; V_28 ++ ) {
T_1 V_51 ;
unsigned int * V_55 = & V_2 -> V_55 ;
struct V_29 * V_57 = & V_2 -> V_57 [ * V_55 ] ;
struct V_31 * V_56 = & V_2 -> V_56 [ * V_55 ] ;
V_56 -> V_34 = F_26 ( V_7 ,
V_61 ) ;
if ( F_11 ( ! V_56 -> V_34 ) )
return - V_94 ;
V_51 = F_28 ( & V_7 -> V_50 , ( void * ) V_56 -> V_34 -> V_36 ,
V_61 , V_68 ) ;
if ( F_29 ( & V_7 -> V_50 , V_51 ) ) {
F_22 ( V_7 , L_2 ) ;
F_30 ( V_56 -> V_34 ) ;
return - V_94 ;
}
F_31 ( V_56 , V_51 , V_51 ) ;
F_32 ( V_56 , V_49 , V_61 ) ;
V_57 -> V_36 = F_23 ( V_51 ) ;
F_33 () ;
V_57 -> V_21 = F_23 ( V_35 | V_61 ) ;
* V_55 = ( * V_55 + 1 ) % V_60 ;
}
V_2 -> V_5 = 0 ;
V_2 -> V_3 = 0 ;
memset ( V_2 -> V_30 , 0 , V_95 ) ;
F_5 ( V_2 , V_96 , 0 ) ;
F_5 ( V_2 , V_97 , 0 ) ;
F_5 ( V_2 , V_98 , ( unsigned int ) V_2 -> V_99 ) ;
F_5 ( V_2 , V_100 , ( unsigned int ) V_2 -> V_101 ) ;
F_5 ( V_2 , V_72 , V_73 | V_74 | V_80 ) ;
F_5 ( V_2 , V_17 ,
( V_60 << 24 ) |
( V_4 << 16 ) |
V_102 | V_103 ) ;
F_45 ( & V_2 -> V_71 ) ;
F_36 ( V_2 , V_17 , V_104 ) ;
F_46 ( V_7 -> V_10 ) ;
F_47 ( V_7 ) ;
return 0 ;
}
static void F_48 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
if ( V_7 -> V_105 & V_106 ) {
F_36 ( V_2 , V_17 , V_107 ) ;
} else {
F_39 ( V_2 , V_17 , V_107 ) ;
if ( V_7 -> V_105 & V_108 ) {
F_5 ( V_2 , V_96 , ~ 0 ) ;
F_5 ( V_2 , V_97 , ~ 0 ) ;
} else {
struct V_109 * V_110 ;
unsigned int V_111 [ 2 ] = { 0 , 0 } ;
int V_112 ;
F_49 (ha, ndev) {
V_112 = F_50 ( V_113 , V_110 -> V_51 ) >> 26 ;
V_111 [ V_112 >> 5 ] |= 1 << ( V_112 & 31 ) ;
}
F_5 ( V_2 , V_96 , V_111 [ 0 ] ) ;
F_5 ( V_2 , V_97 , V_111 [ 1 ] ) ;
}
}
}
static void F_51 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 ; V_28 ++ ) {
struct V_29 * V_30 = & V_2 -> V_30 [ V_28 ] ;
struct V_31 * V_32 = & V_2 -> V_32 [ V_28 ] ;
if ( V_32 -> V_34 ) {
F_13 ( & V_7 -> V_50 ,
F_14 ( V_32 , V_51 ) ,
F_15 ( V_32 , V_49 ) ,
V_52 ) ;
F_16 ( V_32 -> V_34 ) ;
}
V_30 -> V_21 = 0 ;
V_30 -> V_36 = 0 ;
V_32 -> V_34 = NULL ;
}
}
static void F_52 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_60 ; V_28 ++ ) {
struct V_29 * V_57 = & V_2 -> V_57 [ V_28 ] ;
struct V_31 * V_56 = & V_2 -> V_56 [ V_28 ] ;
if ( V_56 -> V_34 ) {
F_13 ( & V_7 -> V_50 ,
F_14 ( V_56 , V_51 ) ,
F_15 ( V_56 , V_49 ) ,
V_68 ) ;
F_16 ( V_56 -> V_34 ) ;
}
V_57 -> V_21 = 0 ;
V_57 -> V_36 = 0 ;
V_56 -> V_34 = NULL ;
}
}
static int F_53 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
F_54 ( & V_2 -> V_71 ) ;
F_55 ( V_7 ) ;
F_39 ( V_2 , V_72 , V_73 | V_74 | V_80 ) ;
F_39 ( V_2 , V_17 , V_104 ) ;
F_51 ( V_7 ) ;
F_52 ( V_7 ) ;
return 0 ;
}
static struct V_26 * F_56 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
struct V_26 * V_27 = & V_7 -> V_27 ;
unsigned long V_114 , V_115 ;
T_3 V_116 , V_117 , V_118 ;
V_115 = F_4 ( V_2 , V_119 ) ;
V_114 = F_4 ( V_2 , V_120 ) ;
V_116 = V_115 ;
V_117 = V_115 >> 8 ;
V_118 = V_115 >> 16 ;
V_27 -> V_62 += V_114 ;
V_27 -> V_62 += V_116 + V_117 + V_118 ;
V_27 -> V_88 += V_118 ;
V_27 -> V_86 += V_117 ;
V_27 -> V_84 += V_116 ;
V_27 -> V_82 += V_114 ;
return V_27 ;
}
static int F_57 ( struct V_33 * V_34 , struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
unsigned int V_49 , * V_5 = & V_2 -> V_5 ;
struct V_26 * V_27 = & V_7 -> V_27 ;
T_4 * V_21 = & V_2 -> V_30 [ * V_5 ] . V_21 ;
T_1 V_51 ;
if ( F_58 ( V_34 , V_121 ) )
return V_122 ;
V_49 = F_59 (unsigned int, ETH_ZLEN, skb->len) ;
if ( F_11 ( ! F_1 ( V_2 ) ) ) {
F_55 ( V_7 ) ;
F_22 ( V_7 , L_3 ) ;
return V_123 ;
}
V_51 = F_28 ( & V_7 -> V_50 , ( void * ) V_34 -> V_36 , V_49 ,
V_52 ) ;
if ( F_11 ( F_29 ( & V_7 -> V_50 , V_51 ) ) ) {
V_27 -> V_42 ++ ;
V_27 -> V_41 ++ ;
F_30 ( V_34 ) ;
return V_122 ;
}
F_31 ( & V_2 -> V_32 [ * V_5 ] , V_51 , V_51 ) ;
F_32 ( & V_2 -> V_32 [ * V_5 ] , V_49 , V_49 ) ;
V_2 -> V_30 [ * V_5 ] . V_36 = F_23 ( V_51 ) ;
F_33 () ;
F_60 ( V_34 ) ;
* V_21 = F_23 ( V_35 | V_46 | V_49 ) ;
F_33 () ;
V_2 -> V_32 [ * V_5 ] . V_34 = V_34 ;
* V_5 = ( * V_5 + 1 ) % V_4 ;
F_17 () ;
if ( ! F_1 ( V_2 ) ) {
F_55 ( V_7 ) ;
F_17 () ;
if ( F_1 ( V_2 ) )
F_47 ( V_7 ) ;
}
F_5 ( V_2 , V_78 , V_124 ) ;
return V_122 ;
}
static void F_61 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
unsigned int V_125 , V_126 ;
V_125 = F_10 ( * ( T_4 * ) & V_7 -> V_127 [ 0 ] ) ;
V_126 = F_62 ( * ( V_128 * ) & V_7 -> V_127 [ 4 ] ) ;
F_5 ( V_2 , V_129 , V_125 ) ;
F_5 ( V_2 , V_130 , V_126 ) ;
}
static int F_63 ( struct V_6 * V_7 , void * V_131 )
{
struct V_132 * V_51 = V_131 ;
if ( F_64 ( V_7 ) )
return - V_133 ;
if ( ! F_65 ( V_51 -> V_134 ) )
return - V_135 ;
memcpy ( V_7 -> V_127 , V_51 -> V_134 , V_7 -> V_136 ) ;
F_61 ( V_7 ) ;
return 0 ;
}
int F_66 ( struct V_6 * V_7 , int V_137 )
{
struct V_138 * V_50 = V_7 -> V_50 . V_139 ;
struct V_140 V_141 ;
struct V_142 * V_143 ;
struct V_8 * V_10 = NULL ;
struct V_1 * V_2 ;
const char * V_144 ;
unsigned int V_145 , V_146 , V_75 ;
int V_147 ;
V_143 = F_67 ( V_50 -> V_148 , L_4 , 0 ) ;
if ( ! V_143 ) {
F_68 ( V_50 , L_5 ) ;
return - V_149 ;
}
V_147 = F_69 ( V_50 -> V_148 , 0 , & V_141 ) ;
if ( V_147 ) {
F_68 ( V_50 , L_6 ) ;
V_147 = - V_149 ;
goto V_150;
}
V_75 = F_70 ( V_50 -> V_148 , 0 ) ;
if ( ! V_75 ) {
F_68 ( V_50 , L_7 ) ;
V_147 = - V_149 ;
goto V_150;
}
V_7 -> V_151 = & V_152 ;
V_7 -> V_153 = & V_154 ;
V_7 -> V_155 = V_156 ;
V_7 -> V_105 &= ~ V_157 ;
V_2 = F_3 ( V_7 ) ;
V_2 -> V_50 = V_50 ;
V_2 -> V_158 = F_71 ( V_50 , & V_141 ) ;
if ( F_72 ( V_2 -> V_158 ) ) {
V_147 = F_73 ( V_2 -> V_158 ) ;
goto V_150;
}
F_74 ( V_50 , L_8 , V_2 -> V_158 ) ;
if ( V_2 -> V_159 ) {
V_147 = F_75 ( V_2 -> V_159 ) ;
if ( V_147 ) {
F_68 ( V_50 , L_9 ) ;
goto V_150;
}
V_146 = F_76 ( V_2 -> V_159 ) ;
} else {
if ( F_77 ( V_50 -> V_148 , L_10 ,
& V_146 ) ) {
F_68 ( V_50 , L_11 ) ;
V_147 = - V_160 ;
goto V_150;
}
}
V_145 = F_4 ( V_2 , V_161 ) ;
if ( ! ( V_145 == 0x0005fd02 || V_145 == 0x0007fd02 ) ) {
F_68 ( V_50 , L_12 , V_145 ) ;
V_147 = - V_149 ;
goto V_162;
}
F_78 ( V_50 , L_13 , V_145 ) ;
F_5 ( V_2 , V_163 , V_146 / 1000000 ) ;
V_7 -> V_75 = V_75 ;
F_78 ( V_50 , L_14 , V_7 -> V_75 ) ;
V_147 = F_79 ( V_50 , V_7 -> V_75 , F_37 , 0 ,
V_7 -> V_164 , V_7 ) ;
if ( V_147 ) {
F_68 ( V_50 , L_15 ) ;
goto V_162;
}
V_144 = F_80 ( V_50 -> V_148 ) ;
if ( V_144 )
memcpy ( V_7 -> V_127 , V_144 , V_113 ) ;
else
F_81 ( V_7 ) ;
F_61 ( V_7 ) ;
F_78 ( V_50 , L_16 , V_7 -> V_127 ) ;
V_2 -> V_57 = F_82 ( V_50 , V_165 + V_95 ,
& V_2 -> V_99 , V_166 ) ;
if ( ! V_2 -> V_57 ) {
F_68 ( V_50 , L_17 ) ;
V_147 = - V_94 ;
goto V_162;
}
V_2 -> V_30 = V_2 -> V_57 + V_60 ;
V_2 -> V_101 = V_2 -> V_99 + V_165 ;
F_74 ( V_50 , L_18 ,
( unsigned int ) V_2 -> V_99 , ( unsigned int ) V_2 -> V_101 ) ;
V_147 = F_83 ( V_2 ) ;
if ( V_147 ) {
F_68 ( V_50 , L_19 ) ;
goto V_162;
}
V_10 = F_84 ( V_7 , V_143 , F_2 , 0 ,
V_137 ) ;
if ( ! V_10 ) {
F_68 ( V_50 , L_20 ) ;
V_147 = - V_149 ;
goto V_167;
}
F_78 ( V_50 , L_21 ,
V_10 -> V_168 -> V_164 , V_10 -> V_169 ) ;
F_85 ( V_7 , & V_2 -> V_71 , F_34 , V_170 ) ;
V_147 = F_86 ( V_7 ) ;
if ( V_147 ) {
F_68 ( V_50 , L_22 ) ;
goto V_171;
}
F_87 ( V_143 ) ;
return 0 ;
V_171:
F_88 ( & V_2 -> V_71 ) ;
F_89 ( V_10 ) ;
V_167:
F_90 ( V_2 ) ;
V_162:
if ( V_2 -> V_159 )
F_91 ( V_2 -> V_159 ) ;
V_150:
F_87 ( V_143 ) ;
return V_147 ;
}
int F_92 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
F_89 ( V_7 -> V_10 ) ;
F_90 ( V_2 ) ;
F_93 ( V_7 ) ;
F_88 ( & V_2 -> V_71 ) ;
if ( ! F_72 ( V_2 -> V_159 ) )
F_91 ( V_2 -> V_159 ) ;
return 0 ;
}
