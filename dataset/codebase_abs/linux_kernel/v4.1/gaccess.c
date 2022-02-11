int F_1 ( struct V_1 * V_2 )
{
union V_3 * V_4 = & V_2 -> V_5 -> V_6 . V_7 -> V_3 ;
if ( V_2 -> V_6 . V_8 -> V_9 & 1 )
return V_4 -> V_10 != 0 ;
return V_2 -> V_5 -> V_6 . V_11 != 0 ;
}
static void F_2 ( struct V_1 * V_2 )
{
union V_3 V_12 , V_13 , * V_4 ;
F_3 ( & V_2 -> V_5 -> V_6 . V_14 ) ;
V_2 -> V_5 -> V_6 . V_11 ++ ;
if ( V_2 -> V_5 -> V_6 . V_11 > 1 )
goto V_15;
V_4 = & V_2 -> V_5 -> V_6 . V_7 -> V_3 ;
do {
V_12 = F_4 ( * V_4 ) ;
while ( V_12 . V_16 ) {
F_5 () ;
V_12 = F_4 ( * V_4 ) ;
}
V_13 = V_12 ;
V_13 . V_16 = 1 ;
} while ( F_6 ( & V_4 -> V_17 , V_12 . V_17 , V_13 . V_17 ) != V_12 . V_17 );
V_15:
F_7 ( & V_2 -> V_5 -> V_6 . V_14 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
union V_3 V_12 , V_13 , * V_4 ;
F_3 ( & V_2 -> V_5 -> V_6 . V_14 ) ;
V_2 -> V_5 -> V_6 . V_11 -- ;
if ( V_2 -> V_5 -> V_6 . V_11 )
goto V_15;
V_4 = & V_2 -> V_5 -> V_6 . V_7 -> V_3 ;
do {
V_12 = F_4 ( * V_4 ) ;
V_13 = V_12 ;
V_13 . V_16 = 0 ;
} while ( F_6 ( & V_4 -> V_17 , V_12 . V_17 , V_13 . V_17 ) != V_12 . V_17 );
F_9 ( & V_2 -> V_5 -> V_6 . V_18 ) ;
V_15:
F_7 ( & V_2 -> V_5 -> V_6 . V_14 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
union V_3 V_12 , V_13 , * V_4 ;
V_4 = & V_2 -> V_5 -> V_6 . V_7 -> V_3 ;
do {
V_12 = F_4 ( * V_4 ) ;
while ( V_12 . V_19 ) {
F_5 () ;
V_12 = F_4 ( * V_4 ) ;
}
V_13 = V_12 ;
V_13 . V_16 = 1 ;
V_13 . V_10 ++ ;
} while ( F_6 ( & V_4 -> V_17 , V_12 . V_17 , V_13 . V_17 ) != V_12 . V_17 );
}
static void F_11 ( struct V_1 * V_2 )
{
union V_3 V_12 , V_13 , * V_4 ;
V_4 = & V_2 -> V_5 -> V_6 . V_7 -> V_3 ;
do {
V_12 = F_4 ( * V_4 ) ;
V_13 = V_12 ;
V_13 . V_10 -- ;
if ( ! V_13 . V_10 )
V_13 . V_16 = 0 ;
} while ( F_6 ( & V_4 -> V_17 , V_12 . V_17 , V_13 . V_17 ) != V_12 . V_17 );
if ( ! V_13 . V_10 )
F_9 ( & V_2 -> V_5 -> V_6 . V_18 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_8 -> V_9 & 1 )
F_10 ( V_2 ) ;
else
F_2 ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_8 -> V_9 & 1 )
F_11 ( V_2 ) ;
else
F_8 ( V_2 ) ;
}
static int F_14 ( struct V_1 * V_2 , union V_20 * V_20 , T_1 V_21 ,
int V_22 )
{
union V_23 V_23 ;
struct V_24 V_24 ;
struct V_25 V_25 ;
unsigned long V_26 , V_27 ;
union V_28 V_28 ;
int V_29 , V_30 ;
T_2 V_31 ;
if ( V_21 >= V_32 )
return - V_33 ;
F_15 ( V_2 -> V_34 -> V_35 . V_36 . V_37 ) ;
V_23 . V_17 = V_2 -> V_34 -> V_35 . V_36 . V_37 [ V_21 ] ;
if ( V_21 == 0 || V_23 . V_17 == 0 ) {
V_20 -> V_17 = V_2 -> V_6 . V_8 -> V_38 [ 1 ] ;
return 0 ;
} else if ( V_23 . V_17 == 1 ) {
V_20 -> V_17 = V_2 -> V_6 . V_8 -> V_38 [ 7 ] ;
return 0 ;
}
if ( V_23 . V_39 )
return V_40 ;
if ( V_23 . V_41 )
V_26 = V_2 -> V_6 . V_8 -> V_38 [ 5 ] ;
else
V_26 = V_2 -> V_6 . V_8 -> V_38 [ 2 ] ;
V_26 &= 0x7fffffc0 ;
V_30 = F_16 ( V_2 , V_26 + 16 , & V_28 . V_17 , sizeof( union V_28 ) ) ;
if ( V_30 )
return V_30 ;
if ( V_23 . V_42 / 8 > V_28 . V_43 )
return V_44 ;
if ( 0x7fffffff - V_28 . V_45 * 128 < V_23 . V_42 * 16 )
return V_46 ;
V_30 = F_16 ( V_2 , V_28 . V_45 * 128 + V_23 . V_42 * 16 , & V_24 ,
sizeof( struct V_24 ) ) ;
if ( V_30 )
return V_30 ;
if ( V_24 . V_47 == 1 )
return V_44 ;
if ( V_24 . V_48 != V_23 . V_48 )
return V_49 ;
V_30 = F_16 ( V_2 , V_24 . V_50 * 64 , & V_25 , sizeof( struct V_25 ) ) ;
if ( V_30 )
return V_30 ;
if ( V_25 . V_47 )
return V_51 ;
if ( V_25 . V_52 != V_24 . V_52 )
return V_53 ;
if ( V_24 . V_41 == 1 ) {
V_29 = ( V_2 -> V_6 . V_8 -> V_38 [ 8 ] >> 16 ) & 0xffff ;
if ( V_24 . V_54 != V_29 ) {
if ( V_29 / 16 > V_25 . V_55 )
return V_56 ;
V_27 = V_25 . V_57 * 4 + V_29 / 4 ;
V_30 = F_16 ( V_2 , V_27 ,
& V_31 ,
sizeof( T_2 ) ) ;
if ( V_30 )
return V_30 ;
if ( ( V_31 & ( 0x40 >> ( ( V_29 & 3 ) * 2 ) ) ) == 0 )
return V_56 ;
}
}
if ( V_24 . V_58 == 1 && V_22 )
return V_59 ;
V_20 -> V_17 = V_25 . V_20 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , union V_20 * V_20 ,
T_1 V_21 , int V_22 )
{
int V_30 ;
T_3 * V_60 = & V_2 -> V_6 . V_8 -> V_61 ;
struct V_62 * V_63 = & V_2 -> V_6 . V_63 ;
struct V_64 * V_65 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_65 = (struct V_64 * ) & V_63 -> V_66 ;
V_65 -> V_67 = V_22 ? V_68 : V_69 ;
V_65 -> V_70 = F_18 ( * V_60 ) . V_70 ;
if ( ! F_18 ( * V_60 ) . V_71 ) {
V_20 -> V_17 = 0 ;
V_20 -> V_72 = 1 ;
return 0 ;
}
switch ( F_18 ( V_2 -> V_6 . V_8 -> V_61 ) . V_70 ) {
case V_73 :
V_20 -> V_17 = V_2 -> V_6 . V_8 -> V_38 [ 1 ] ;
return 0 ;
case V_74 :
V_20 -> V_17 = V_2 -> V_6 . V_8 -> V_38 [ 7 ] ;
return 0 ;
case V_75 :
V_20 -> V_17 = V_2 -> V_6 . V_8 -> V_38 [ 13 ] ;
return 0 ;
case V_76 :
V_30 = F_14 ( V_2 , V_20 , V_21 , V_22 ) ;
switch ( V_30 ) {
case V_44 :
case V_49 :
case V_51 :
case V_53 :
case V_56 :
V_2 -> V_6 . V_63 . V_77 = V_21 ;
break;
case V_59 :
V_65 -> V_78 = 1 ;
V_65 -> V_79 = 1 ;
break;
}
if ( V_30 > 0 )
V_63 -> V_80 = V_30 ;
return V_30 ;
}
return 0 ;
}
static int F_19 ( struct V_5 * V_5 , unsigned long V_81 , unsigned long * V_17 )
{
return F_20 ( V_5 , V_81 , V_17 , sizeof( * V_17 ) ) ;
}
static unsigned long F_21 ( struct V_1 * V_2 , unsigned long V_82 ,
unsigned long * V_81 , const union V_20 V_20 ,
int V_22 )
{
union V_83 V_84 = { . V_85 = V_82 } ;
union V_86 V_87 = { . V_85 = V_82 } ;
union V_88 V_89 ;
int V_90 = 0 ;
union V_91 V_91 ;
unsigned long V_92 ;
int V_93 , V_94 ;
V_91 . V_17 = V_2 -> V_6 . V_8 -> V_38 [ 0 ] ;
V_93 = V_91 . V_95 && F_22 ( V_2 -> V_5 , 8 ) ;
V_94 = V_93 && F_22 ( V_2 -> V_5 , 78 ) ;
if ( V_20 . V_72 )
goto V_96;
V_92 = V_20 . V_97 * 4096 ;
switch ( V_20 . V_98 ) {
case V_99 :
if ( V_84 . V_100 > V_20 . V_101 )
return V_102 ;
V_92 += V_84 . V_103 * 8 ;
break;
case V_104 :
if ( V_84 . V_103 )
return V_105 ;
if ( V_84 . V_106 > V_20 . V_101 )
return V_107 ;
V_92 += V_84 . V_108 * 8 ;
break;
case V_109 :
if ( V_84 . V_103 || V_84 . V_108 )
return V_105 ;
if ( V_84 . V_110 > V_20 . V_101 )
return V_111 ;
V_92 += V_84 . V_112 * 8 ;
break;
case V_113 :
if ( V_84 . V_103 || V_84 . V_108 || V_84 . V_112 )
return V_105 ;
if ( V_84 . V_114 > V_20 . V_101 )
return V_115 ;
V_92 += V_84 . V_116 * 8 ;
break;
}
switch ( V_20 . V_98 ) {
case V_99 : {
union V_117 V_118 ;
if ( F_23 ( V_2 -> V_5 , V_92 ) )
return V_46 ;
if ( F_19 ( V_2 -> V_5 , V_92 , & V_118 . V_17 ) )
return - V_119 ;
if ( V_118 . V_47 )
return V_102 ;
if ( V_118 . V_120 != V_121 )
return V_122 ;
if ( V_84 . V_106 < V_118 . V_123 || V_84 . V_106 > V_118 . V_101 )
return V_107 ;
if ( V_93 )
V_90 |= V_118 . V_41 ;
V_92 = V_118 . V_124 * 4096 + V_84 . V_108 * 8 ;
}
case V_104 : {
union V_125 V_126 ;
if ( F_23 ( V_2 -> V_5 , V_92 ) )
return V_46 ;
if ( F_19 ( V_2 -> V_5 , V_92 , & V_126 . V_17 ) )
return - V_119 ;
if ( V_126 . V_47 )
return V_107 ;
if ( V_126 . V_120 != V_127 )
return V_122 ;
if ( V_84 . V_110 < V_126 . V_123 || V_84 . V_110 > V_126 . V_101 )
return V_111 ;
if ( V_93 )
V_90 |= V_126 . V_41 ;
V_92 = V_126 . V_124 * 4096 + V_84 . V_112 * 8 ;
}
case V_109 : {
union V_128 V_129 ;
if ( F_23 ( V_2 -> V_5 , V_92 ) )
return V_46 ;
if ( F_19 ( V_2 -> V_5 , V_92 , & V_129 . V_17 ) )
return - V_119 ;
if ( V_129 . V_47 )
return V_111 ;
if ( V_129 . V_120 != V_130 )
return V_122 ;
if ( V_129 . V_131 && V_20 . V_41 && V_94 )
return V_122 ;
if ( V_129 . V_132 && V_94 ) {
V_90 |= V_129 . V_133 . V_41 ;
V_87 . V_134 = V_129 . V_133 . V_134 ;
goto V_135;
}
if ( V_84 . V_114 < V_129 . V_136 . V_123 )
return V_115 ;
if ( V_84 . V_114 > V_129 . V_136 . V_101 )
return V_115 ;
if ( V_93 )
V_90 |= V_129 . V_136 . V_41 ;
V_92 = V_129 . V_136 . V_137 * 4096 + V_84 . V_116 * 8 ;
}
case V_113 : {
union V_138 V_139 ;
if ( F_23 ( V_2 -> V_5 , V_92 ) )
return V_46 ;
if ( F_19 ( V_2 -> V_5 , V_92 , & V_139 . V_17 ) )
return - V_119 ;
if ( V_139 . V_47 )
return V_115 ;
if ( V_139 . V_120 != V_140 )
return V_122 ;
if ( V_139 . V_141 && V_20 . V_41 )
return V_122 ;
if ( V_139 . V_132 && V_93 ) {
V_90 |= V_139 . V_133 . V_41 ;
V_87 . V_142 = V_139 . V_133 . V_142 ;
goto V_135;
}
V_90 |= V_139 . V_136 . V_41 ;
V_92 = V_139 . V_136 . V_143 * 2048 + V_84 . V_144 * 8 ;
}
}
if ( F_23 ( V_2 -> V_5 , V_92 ) )
return V_46 ;
if ( F_19 ( V_2 -> V_5 , V_92 , & V_89 . V_17 ) )
return - V_119 ;
if ( V_89 . V_47 )
return V_145 ;
if ( V_89 . V_146 )
return V_122 ;
if ( V_89 . V_147 && ! V_93 )
return V_122 ;
V_90 |= V_89 . V_41 ;
V_87 . V_148 = V_89 . V_148 ;
V_96:
V_87 . V_85 = F_24 ( V_2 , V_87 . V_85 ) ;
V_135:
if ( V_22 && V_90 )
return V_59 ;
if ( F_23 ( V_2 -> V_5 , V_87 . V_85 ) )
return V_46 ;
* V_81 = V_87 . V_85 ;
return 0 ;
}
static inline int F_25 ( unsigned long V_149 )
{
return ( V_149 & ~ 0x11fful ) == 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
const union V_20 V_20 )
{
union V_91 V_91 = { . V_17 = V_2 -> V_6 . V_8 -> V_38 [ 0 ] } ;
T_3 * V_60 = & V_2 -> V_6 . V_8 -> V_61 ;
if ( ! V_91 . V_150 )
return 0 ;
if ( F_18 ( * V_60 ) . V_71 && V_20 . V_41 )
return 0 ;
return 1 ;
}
static int F_27 ( struct V_1 * V_2 , unsigned long V_149 ,
unsigned long * V_151 , unsigned long V_152 ,
const union V_20 V_20 , int V_22 )
{
struct V_62 * V_63 = & V_2 -> V_6 . V_63 ;
T_3 * V_60 = & V_2 -> V_6 . V_8 -> V_61 ;
struct V_64 * V_65 ;
int V_153 , V_30 ;
V_65 = (struct V_64 * ) & V_63 -> V_66 ;
V_153 = F_26 ( V_2 , V_20 ) ;
while ( V_152 ) {
V_149 = F_28 ( V_2 , V_149 ) ;
V_65 -> V_85 = V_149 >> V_154 ;
if ( V_22 && V_153 && F_25 ( V_149 ) ) {
V_63 -> V_80 = V_59 ;
return V_63 -> V_80 ;
}
V_149 &= V_155 ;
if ( F_18 ( * V_60 ) . V_71 ) {
V_30 = F_21 ( V_2 , V_149 , V_151 , V_20 , V_22 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_30 == V_59 )
V_65 -> V_79 = 1 ;
if ( V_30 )
V_63 -> V_80 = V_30 ;
} else {
* V_151 = F_24 ( V_2 , V_149 ) ;
if ( F_23 ( V_2 -> V_5 , * V_151 ) )
V_63 -> V_80 = V_46 ;
}
if ( V_63 -> V_80 )
return V_63 -> V_80 ;
V_149 += V_156 ;
V_151 ++ ;
V_152 -- ;
}
return 0 ;
}
int F_29 ( struct V_1 * V_2 , unsigned long V_149 , T_1 V_21 , void * V_157 ,
unsigned long V_158 , int V_22 )
{
T_3 * V_60 = & V_2 -> V_6 . V_8 -> V_61 ;
unsigned long V_159 , V_152 , V_81 , V_160 ;
unsigned long V_161 [ 2 ] ;
unsigned long * V_151 ;
int V_162 ;
union V_20 V_20 ;
int V_30 ;
if ( ! V_158 )
return 0 ;
V_30 = F_17 ( V_2 , & V_20 , V_21 , V_22 ) ;
if ( V_30 )
return V_30 ;
V_152 = ( ( ( V_149 & ~ V_155 ) + V_158 - 1 ) >> V_154 ) + 1 ;
V_151 = V_161 ;
if ( V_152 > F_30 ( V_161 ) )
V_151 = F_31 ( V_152 * sizeof( unsigned long ) ) ;
if ( ! V_151 )
return - V_163 ;
V_162 = F_18 ( * V_60 ) . V_71 && ! V_20 . V_72 ;
if ( V_162 )
F_12 ( V_2 ) ;
V_30 = F_27 ( V_2 , V_149 , V_151 , V_152 , V_20 , V_22 ) ;
for ( V_160 = 0 ; V_160 < V_152 && ! V_30 ; V_160 ++ ) {
V_81 = * ( V_151 + V_160 ) + ( V_149 & ~ V_155 ) ;
V_159 = F_32 ( V_156 - ( V_81 & ~ V_155 ) , V_158 ) ;
if ( V_22 )
V_30 = F_33 ( V_2 -> V_5 , V_81 , V_157 , V_159 ) ;
else
V_30 = F_20 ( V_2 -> V_5 , V_81 , V_157 , V_159 ) ;
V_158 -= V_159 ;
V_149 += V_159 ;
V_157 += V_159 ;
}
if ( V_162 )
F_13 ( V_2 ) ;
if ( V_152 > F_30 ( V_161 ) )
F_34 ( V_151 ) ;
return V_30 ;
}
int F_35 ( struct V_1 * V_2 , unsigned long V_164 ,
void * V_157 , unsigned long V_158 , int V_22 )
{
unsigned long V_159 , V_81 ;
int V_30 = 0 ;
while ( V_158 && ! V_30 ) {
V_81 = F_24 ( V_2 , V_164 ) ;
V_159 = F_32 ( V_156 - ( V_81 & ~ V_155 ) , V_158 ) ;
if ( V_22 )
V_30 = F_36 ( V_2 , V_81 , V_157 , V_159 ) ;
else
V_30 = F_37 ( V_2 , V_81 , V_157 , V_159 ) ;
V_158 -= V_159 ;
V_164 += V_159 ;
V_157 += V_159 ;
}
return V_30 ;
}
int F_38 ( struct V_1 * V_2 , unsigned long V_82 , T_1 V_21 ,
unsigned long * V_81 , int V_22 )
{
struct V_62 * V_63 = & V_2 -> V_6 . V_63 ;
T_3 * V_60 = & V_2 -> V_6 . V_8 -> V_61 ;
struct V_64 * V_165 ;
union V_20 V_20 ;
int V_30 ;
V_82 = F_28 ( V_2 , V_82 ) ;
V_165 = (struct V_64 * ) & V_63 -> V_66 ;
V_30 = F_17 ( V_2 , & V_20 , V_21 , V_22 ) ;
V_165 -> V_85 = V_82 >> V_154 ;
if ( V_30 )
return V_30 ;
if ( F_25 ( V_82 ) && F_26 ( V_2 , V_20 ) ) {
if ( V_22 ) {
V_30 = V_63 -> V_80 = V_59 ;
return V_30 ;
}
}
if ( F_18 ( * V_60 ) . V_71 && ! V_20 . V_72 ) {
V_30 = F_21 ( V_2 , V_82 , V_81 , V_20 , V_22 ) ;
if ( V_30 > 0 ) {
if ( V_30 == V_59 )
V_165 -> V_79 = 1 ;
V_63 -> V_80 = V_30 ;
}
} else {
V_30 = 0 ;
* V_81 = F_24 ( V_2 , V_82 ) ;
if ( F_23 ( V_2 -> V_5 , * V_81 ) )
V_30 = V_63 -> V_80 = V_46 ;
}
return V_30 ;
}
int F_39 ( struct V_1 * V_2 , unsigned long V_82 , T_1 V_21 ,
unsigned long V_166 , int V_167 )
{
unsigned long V_81 ;
unsigned long V_168 ;
int V_30 = 0 ;
F_12 ( V_2 ) ;
while ( V_166 > 0 && ! V_30 ) {
V_168 = F_32 ( V_166 , V_156 - ( V_82 % V_156 ) ) ;
V_30 = F_38 ( V_2 , V_82 , V_21 , & V_81 , V_167 ) ;
V_82 += V_168 ;
V_166 -= V_168 ;
}
F_13 ( V_2 ) ;
return V_30 ;
}
int F_40 ( struct V_1 * V_2 , unsigned long V_164 )
{
struct V_62 * V_63 = & V_2 -> V_6 . V_63 ;
T_3 * V_60 = & V_2 -> V_6 . V_8 -> V_61 ;
struct V_64 * V_65 ;
union V_91 V_91 = { . V_17 = V_2 -> V_6 . V_8 -> V_38 [ 0 ] } ;
if ( ! V_91 . V_150 || ! F_25 ( V_164 ) )
return 0 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_65 = (struct V_64 * ) & V_63 -> V_66 ;
V_65 -> V_67 = V_68 ;
V_65 -> V_70 = F_18 ( * V_60 ) . V_70 ;
V_65 -> V_85 = V_164 >> V_154 ;
V_63 -> V_80 = V_59 ;
return V_63 -> V_80 ;
}
