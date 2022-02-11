static inline int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 + V_4 - V_2 -> V_5 - 1 ) % V_4 ;
}
static void F_2 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned int V_10 , V_11 = 0 ;
if ( V_2 -> V_12 != V_9 -> V_12 ) {
V_2 -> V_12 = V_9 -> V_12 ;
V_11 = 1 ;
}
if ( V_2 -> V_13 != V_9 -> V_13 ) {
V_2 -> V_13 = V_9 -> V_13 ;
V_11 = 1 ;
if ( V_2 -> V_14 )
V_2 -> V_14 ( V_2 , V_2 -> V_13 ) ;
}
if ( V_2 -> V_15 != V_9 -> V_15 ) {
V_10 = F_4 ( V_2 , V_16 ) ;
if ( V_17 == V_9 -> V_15 )
V_10 |= V_18 ;
else
V_10 &= ~ V_18 ;
F_5 ( V_2 , V_16 , V_10 ) ;
V_2 -> V_15 = V_9 -> V_15 ;
V_11 = 1 ;
}
if ( V_11 )
F_6 ( V_9 ) ;
}
static int F_7 ( struct V_6 * V_7 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
return F_8 ( V_2 -> V_9 , V_20 ) ;
}
static int F_9 ( struct V_6 * V_7 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
if ( ! F_10 ( V_21 ) )
return - V_22 ;
return F_11 ( V_2 -> V_9 , V_20 ) ;
}
static void F_12 ( struct V_6 * V_7 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
F_13 ( V_24 -> V_25 , V_2 -> V_26 , sizeof( V_24 -> V_25 ) ) ;
F_13 ( V_24 -> V_27 , V_2 -> V_28 , sizeof( V_24 -> V_27 ) ) ;
}
static void F_14 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
struct V_29 * V_30 = & V_7 -> V_30 ;
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < V_4 ; V_31 ++ ) {
unsigned int * V_3 = & V_2 -> V_3 ;
struct V_32 * V_33 = & V_2 -> V_33 [ * V_3 ] ;
struct V_34 * V_35 = & V_2 -> V_35 [ * V_3 ] ;
struct V_36 * V_37 = V_35 -> V_37 ;
unsigned int V_24 = F_15 ( V_33 -> V_24 ) ;
if ( ( V_24 & V_38 ) || ! V_33 -> V_39 )
break;
if ( F_16 ( V_24 & ( V_40 | V_41 | V_42 | V_43 ) ) ) {
V_30 -> V_44 ++ ;
V_30 -> V_45 ++ ;
if ( V_24 & V_41 )
V_30 -> V_46 ++ ;
if ( V_24 & V_42 )
V_30 -> V_47 ++ ;
if ( V_24 & V_43 )
V_30 -> V_48 ++ ;
} else if ( F_17 ( V_24 & V_49 ) ) {
V_30 -> V_50 ++ ;
V_30 -> V_51 += V_37 -> V_52 ;
}
F_18 ( & V_7 -> V_53 , F_19 ( V_35 , V_54 ) ,
F_20 ( V_35 , V_52 ) , V_55 ) ;
F_21 ( V_37 ) ;
V_33 -> V_39 = 0 ;
V_33 -> V_24 = 0 ;
* V_3 = ( * V_3 + 1 ) % V_4 ;
}
F_22 () ;
if ( F_23 ( V_7 ) && F_1 ( V_2 ) )
F_24 ( V_7 ) ;
}
static int F_25 ( struct V_6 * V_7 , int V_56 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
unsigned int V_57 ;
for ( V_57 = 0 ; V_57 < V_56 ; V_57 ++ ) {
unsigned int * V_58 = & V_2 -> V_58 ;
struct V_29 * V_30 = & V_7 -> V_30 ;
struct V_34 * V_59 = & V_2 -> V_59 [ * V_58 ] ;
struct V_32 * V_60 = & V_2 -> V_60 [ * V_58 ] ;
unsigned int V_61 , V_24 = F_15 ( V_60 -> V_24 ) ;
struct V_36 * V_37 ;
T_1 V_54 ;
if ( F_16 ( ( V_24 & V_62 ) == V_38 ) )
break;
* V_58 = ( * V_58 + 1 ) % V_63 ;
if ( F_16 ( ( V_24 & V_49 ) !=
V_49 ) ) {
if ( F_26 () )
F_27 ( V_7 , L_1 ) ;
V_60 -> V_24 = F_28 ( V_38 | V_64 ) ;
V_30 -> V_65 ++ ;
V_30 -> V_66 ++ ;
continue;
}
V_61 = V_24 & V_67 ;
V_30 -> V_68 ++ ;
V_30 -> V_69 += V_61 ;
V_37 = V_59 -> V_37 ;
F_29 ( V_37 , V_61 ) ;
V_37 -> V_53 = V_7 ;
V_37 -> V_70 = F_30 ( V_37 , V_7 ) ;
F_18 ( & V_7 -> V_53 , F_19 ( V_59 , V_54 ) ,
F_20 ( V_59 , V_52 ) , V_71 ) ;
V_59 -> V_37 = F_31 ( V_7 ,
V_64 ) ;
if ( F_16 ( ! V_59 -> V_37 ) ) {
V_30 -> V_65 ++ ;
V_30 -> V_72 ++ ;
continue;
}
F_32 ( V_37 ) ;
V_54 = F_33 ( & V_7 -> V_53 , ( void * ) V_59 -> V_37 -> V_39 ,
V_64 , V_71 ) ;
if ( F_34 ( & V_7 -> V_53 , V_54 ) ) {
if ( F_26 () )
F_27 ( V_7 , L_2 ) ;
F_35 ( V_59 -> V_37 ) ;
V_30 -> V_65 ++ ;
continue;
}
F_36 ( V_59 , V_54 , V_54 ) ;
F_37 ( V_59 , V_52 , V_64 ) ;
V_60 -> V_39 = F_28 ( V_54 ) ;
F_38 () ;
V_60 -> V_24 = F_28 ( V_38 | V_64 ) ;
}
return V_57 ;
}
static int F_39 ( struct V_73 * V_74 , int V_56 )
{
struct V_6 * V_7 = V_74 -> V_53 ;
struct V_1 * V_2 = F_3 ( V_7 ) ;
unsigned int V_57 ;
F_14 ( V_7 ) ;
V_57 = F_25 ( V_7 , V_56 ) ;
if ( V_57 < V_56 ) {
F_40 ( V_74 ) ;
F_41 ( V_2 , V_75 , V_76 | V_77 ) ;
}
return V_57 ;
}
static T_2 F_42 ( int V_78 , void * V_79 )
{
struct V_6 * V_7 = V_79 ;
struct V_1 * V_2 = F_3 ( V_7 ) ;
struct V_29 * V_30 = & V_7 -> V_30 ;
unsigned int V_80 ;
V_80 = F_4 ( V_2 , V_81 ) ;
V_80 &= ~ V_82 ;
F_5 ( V_2 , V_81 , V_80 ) ;
if ( V_80 & ( V_76 | V_77 ) ) {
if ( F_17 ( F_43 ( & V_2 -> V_74 ) ) ) {
F_44 ( V_2 , V_75 , V_76 | V_77 ) ;
F_45 ( & V_2 -> V_74 ) ;
}
}
if ( V_80 & V_83 ) {
if ( V_80 & V_84 ) {
V_30 -> V_85 += 0x100 ;
V_30 -> V_65 += 0x100 ;
}
if ( V_80 & V_86 ) {
V_30 -> V_87 += 0x100 ;
V_30 -> V_65 += 0x100 ;
}
if ( V_80 & V_88 ) {
V_30 -> V_89 += 0x100 ;
V_30 -> V_65 += 0x100 ;
}
if ( V_80 & V_90 ) {
V_30 -> V_91 += 0x100 ;
V_30 -> V_65 += 0x100 ;
}
}
return V_92 ;
}
static void F_46 ( struct V_6 * V_53 )
{
F_47 ( V_53 -> V_78 ) ;
F_42 ( V_53 -> V_78 , V_53 ) ;
F_48 ( V_53 -> V_78 ) ;
}
static int F_49 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
int V_31 ;
V_9 -> V_93 = V_94 ;
V_9 -> V_13 = 0 ;
V_9 -> V_15 = 0 ;
V_9 -> V_95 &= V_9 -> V_96 ;
V_2 -> V_58 = 0 ;
for ( V_31 = 0 ; V_31 < V_63 ; V_31 ++ ) {
T_1 V_54 ;
unsigned int * V_58 = & V_2 -> V_58 ;
struct V_32 * V_60 = & V_2 -> V_60 [ * V_58 ] ;
struct V_34 * V_59 = & V_2 -> V_59 [ * V_58 ] ;
V_59 -> V_37 = F_31 ( V_7 ,
V_64 ) ;
if ( F_16 ( ! V_59 -> V_37 ) )
return - V_97 ;
V_54 = F_33 ( & V_7 -> V_53 , ( void * ) V_59 -> V_37 -> V_39 ,
V_64 , V_71 ) ;
if ( F_34 ( & V_7 -> V_53 , V_54 ) ) {
F_27 ( V_7 , L_2 ) ;
F_35 ( V_59 -> V_37 ) ;
return - V_97 ;
}
F_36 ( V_59 , V_54 , V_54 ) ;
F_37 ( V_59 , V_52 , V_64 ) ;
V_60 -> V_39 = F_28 ( V_54 ) ;
F_38 () ;
V_60 -> V_24 = F_28 ( V_38 | V_64 ) ;
* V_58 = ( * V_58 + 1 ) % V_63 ;
}
memset ( V_2 -> V_33 , 0 , V_98 ) ;
F_5 ( V_2 , V_99 , 0 ) ;
F_5 ( V_2 , V_100 , 0 ) ;
F_5 ( V_2 , V_101 , ( unsigned int ) V_2 -> V_102 ) ;
F_5 ( V_2 , V_103 , ( unsigned int ) V_2 -> V_104 ) ;
F_5 ( V_2 , V_75 , V_76 | V_77 | V_83 ) ;
F_5 ( V_2 , V_16 ,
( V_63 << 24 ) |
( V_4 << 16 ) |
V_105 | V_106 ) ;
F_50 ( & V_2 -> V_74 ) ;
F_41 ( V_2 , V_16 , V_107 ) ;
F_51 ( V_2 -> V_9 ) ;
F_52 ( V_7 ) ;
return 0 ;
}
static void F_53 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
if ( V_7 -> V_108 & V_109 ) {
F_41 ( V_2 , V_16 , V_110 ) ;
} else {
F_44 ( V_2 , V_16 , V_110 ) ;
if ( V_7 -> V_108 & V_111 ) {
F_5 ( V_2 , V_99 , ~ 0 ) ;
F_5 ( V_2 , V_100 , ~ 0 ) ;
} else {
struct V_112 * V_113 ;
unsigned int V_114 [ 2 ] = { 0 , 0 } ;
int V_115 ;
F_54 (ha, ndev) {
V_115 = F_55 ( V_116 , V_113 -> V_54 ) >> 26 ;
V_114 [ V_115 >> 5 ] |= 1 << ( V_115 & 31 ) ;
}
F_5 ( V_2 , V_99 , V_114 [ 0 ] ) ;
F_5 ( V_2 , V_100 , V_114 [ 1 ] ) ;
}
}
}
static int F_56 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
F_57 ( & V_2 -> V_74 ) ;
F_58 ( V_7 ) ;
F_44 ( V_2 , V_75 , V_76 | V_77 | V_83 ) ;
F_44 ( V_2 , V_16 , V_107 ) ;
return 0 ;
}
static struct V_29 * F_59 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
struct V_29 * V_30 = & V_7 -> V_30 ;
unsigned long V_117 , V_118 ;
T_3 V_119 , V_120 , V_121 ;
V_118 = F_4 ( V_2 , V_122 ) ;
V_117 = F_4 ( V_2 , V_123 ) ;
V_119 = V_118 ;
V_120 = V_118 >> 8 ;
V_121 = V_118 >> 16 ;
V_30 -> V_65 += V_117 ;
V_30 -> V_65 += V_119 + V_120 + V_121 ;
V_30 -> V_91 += V_121 ;
V_30 -> V_89 += V_120 ;
V_30 -> V_87 += V_119 ;
V_30 -> V_85 += V_117 ;
return V_30 ;
}
static int F_60 ( struct V_36 * V_37 , struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
unsigned int V_52 , * V_5 = & V_2 -> V_5 ;
struct V_29 * V_30 = & V_7 -> V_30 ;
T_4 * V_24 = & V_2 -> V_33 [ * V_5 ] . V_24 ;
T_1 V_54 ;
if ( F_61 ( V_37 , V_124 ) )
return V_125 ;
V_52 = F_62 (unsigned int, ETH_ZLEN, skb->len) ;
if ( F_16 ( ! F_1 ( V_2 ) ) ) {
F_58 ( V_7 ) ;
F_27 ( V_7 , L_3 ) ;
return V_126 ;
}
V_54 = F_33 ( & V_7 -> V_53 , ( void * ) V_37 -> V_39 , V_52 ,
V_55 ) ;
if ( F_16 ( F_34 ( & V_7 -> V_53 , V_54 ) ) ) {
V_30 -> V_45 ++ ;
V_30 -> V_44 ++ ;
F_35 ( V_37 ) ;
return V_125 ;
}
F_36 ( & V_2 -> V_35 [ * V_5 ] , V_54 , V_54 ) ;
F_37 ( & V_2 -> V_35 [ * V_5 ] , V_52 , V_52 ) ;
V_2 -> V_35 [ * V_5 ] . V_37 = V_37 ;
V_2 -> V_33 [ * V_5 ] . V_39 = F_28 ( V_54 ) ;
F_38 () ;
F_63 ( V_37 ) ;
* V_24 = F_28 ( V_38 | V_49 | V_52 ) ;
* V_5 = ( * V_5 + 1 ) % V_4 ;
F_22 () ;
if ( ! F_1 ( V_2 ) ) {
F_58 ( V_7 ) ;
F_22 () ;
if ( F_1 ( V_2 ) )
F_52 ( V_7 ) ;
}
F_5 ( V_2 , V_81 , V_127 ) ;
return V_125 ;
}
static void F_64 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
unsigned int V_128 , V_129 ;
V_128 = F_15 ( * ( T_4 * ) & V_7 -> V_130 [ 0 ] ) ;
V_129 = F_65 ( * ( V_131 * ) & V_7 -> V_130 [ 4 ] ) ;
F_5 ( V_2 , V_132 , V_128 ) ;
F_5 ( V_2 , V_133 , V_129 ) ;
}
static int F_66 ( struct V_6 * V_7 , void * V_134 )
{
struct V_135 * V_54 = V_134 ;
if ( F_67 ( V_7 ) )
return - V_136 ;
if ( ! F_68 ( V_54 -> V_137 ) )
return - V_138 ;
memcpy ( V_7 -> V_130 , V_54 -> V_137 , V_7 -> V_139 ) ;
F_64 ( V_7 ) ;
return 0 ;
}
int F_69 ( struct V_6 * V_7 , int V_140 )
{
struct V_141 * V_53 = V_7 -> V_53 . V_142 ;
struct V_143 V_144 ;
struct V_145 * V_146 ;
struct V_1 * V_2 ;
const char * V_147 ;
unsigned int V_148 , V_149 , V_78 ;
int V_150 ;
V_146 = F_70 ( V_53 -> V_151 , L_4 , 0 ) ;
if ( ! V_146 ) {
F_71 ( V_53 , L_5 ) ;
return - V_152 ;
}
V_150 = F_72 ( V_53 -> V_151 , 0 , & V_144 ) ;
if ( V_150 ) {
F_71 ( V_53 , L_6 ) ;
return - V_152 ;
}
V_78 = F_73 ( V_53 -> V_151 , 0 ) ;
if ( ! V_78 ) {
F_71 ( V_53 , L_7 ) ;
return - V_152 ;
}
V_7 -> V_153 = & V_154 ;
V_7 -> V_155 = & V_156 ;
V_7 -> V_157 = V_158 ;
V_7 -> V_108 &= ~ V_159 ;
V_2 = F_3 ( V_7 ) ;
V_2 -> V_53 = V_53 ;
V_2 -> V_160 = F_74 ( V_53 , & V_144 ) ;
if ( F_75 ( V_2 -> V_160 ) ) {
return F_76 ( V_2 -> V_160 ) ;
}
F_77 ( V_53 , L_8 , V_2 -> V_160 ) ;
if ( V_2 -> V_161 ) {
V_150 = F_78 ( V_2 -> V_161 ) ;
if ( V_150 ) {
F_71 ( V_53 , L_9 ) ;
return V_150 ;
}
V_149 = F_79 ( V_2 -> V_161 ) ;
} else {
if ( F_80 ( V_53 -> V_151 , L_10 ,
& V_149 ) ) {
F_71 ( V_53 , L_11 ) ;
return - V_162 ;
}
}
V_148 = F_4 ( V_2 , V_163 ) ;
if ( ! ( V_148 == 0x0005fd02 || V_148 == 0x0007fd02 ) ) {
F_71 ( V_53 , L_12 , V_148 ) ;
V_150 = - V_152 ;
goto V_164;
}
F_81 ( V_53 , L_13 , V_148 ) ;
F_5 ( V_2 , V_165 , V_149 / 1000000 ) ;
V_7 -> V_78 = V_78 ;
F_81 ( V_53 , L_14 , V_7 -> V_78 ) ;
V_150 = F_82 ( V_53 , V_7 -> V_78 , F_42 , 0 ,
V_7 -> V_166 , V_7 ) ;
if ( V_150 ) {
F_71 ( V_53 , L_15 ) ;
goto V_164;
}
V_147 = F_83 ( V_53 -> V_151 ) ;
if ( V_147 )
memcpy ( V_7 -> V_130 , V_147 , V_116 ) ;
else
F_84 ( V_7 ) ;
F_64 ( V_7 ) ;
F_81 ( V_53 , L_16 , V_7 -> V_130 ) ;
V_2 -> V_60 = F_85 ( V_53 , V_167 + V_98 ,
& V_2 -> V_102 , V_168 ) ;
if ( ! V_2 -> V_60 ) {
F_71 ( V_53 , L_17 ) ;
V_150 = - V_97 ;
goto V_164;
}
V_2 -> V_33 = V_2 -> V_60 + V_63 ;
V_2 -> V_104 = V_2 -> V_102 + V_167 ;
F_77 ( V_53 , L_18 ,
( unsigned int ) V_2 -> V_102 , ( unsigned int ) V_2 -> V_104 ) ;
V_150 = F_86 ( V_2 ) ;
if ( V_150 ) {
F_71 ( V_53 , L_19 ) ;
goto V_164;
}
V_2 -> V_9 = F_87 ( V_7 , V_146 , F_2 , 0 ,
V_140 ) ;
if ( ! V_2 -> V_9 ) {
F_71 ( V_53 , L_20 ) ;
V_150 = - V_152 ;
goto V_169;
}
F_81 ( V_53 , L_21 ,
V_2 -> V_9 -> V_170 -> V_166 , V_2 -> V_9 -> V_171 ) ;
F_88 ( V_7 , & V_2 -> V_74 , F_39 , V_172 ) ;
V_150 = F_89 ( V_7 ) ;
if ( V_150 ) {
F_71 ( V_53 , L_22 ) ;
goto V_173;
}
return 0 ;
V_173:
F_90 ( & V_2 -> V_74 ) ;
F_91 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
V_169:
F_92 ( V_2 ) ;
V_164:
if ( V_2 -> V_161 )
F_93 ( V_2 -> V_161 ) ;
return V_150 ;
}
int F_94 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
F_91 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
F_92 ( V_2 ) ;
F_95 ( V_7 ) ;
F_90 ( & V_2 -> V_74 ) ;
if ( ! F_75 ( V_2 -> V_161 ) ) {
F_93 ( V_2 -> V_161 ) ;
}
return 0 ;
}
