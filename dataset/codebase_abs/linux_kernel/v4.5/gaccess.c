int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 -> V_5 & 1 ) {
int V_6 ;
F_2 ( & V_2 -> V_7 -> V_3 . V_8 ) ;
V_6 = F_3 ( V_2 -> V_7 ) -> V_9 != 0 ;
F_4 ( & V_2 -> V_7 -> V_3 . V_8 ) ;
return V_6 ;
}
return V_2 -> V_7 -> V_3 . V_10 != 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
union V_11 V_12 , V_13 , * V_14 ;
F_6 ( & V_2 -> V_7 -> V_3 . V_15 ) ;
V_2 -> V_7 -> V_3 . V_10 ++ ;
if ( V_2 -> V_7 -> V_3 . V_10 > 1 )
goto V_16;
V_17:
F_2 ( & V_2 -> V_7 -> V_3 . V_8 ) ;
V_14 = F_3 ( V_2 -> V_7 ) ;
do {
V_12 = F_7 ( * V_14 ) ;
if ( V_12 . V_18 ) {
F_4 ( & V_2 -> V_7 -> V_3 . V_8 ) ;
F_8 () ;
goto V_17;
}
V_13 = V_12 ;
V_13 . V_18 = 1 ;
} while ( F_9 ( & V_14 -> V_19 , V_12 . V_19 , V_13 . V_19 ) != V_12 . V_19 );
F_4 ( & V_2 -> V_7 -> V_3 . V_8 ) ;
V_16:
F_10 ( & V_2 -> V_7 -> V_3 . V_15 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
union V_11 V_12 , V_13 , * V_14 ;
F_6 ( & V_2 -> V_7 -> V_3 . V_15 ) ;
V_2 -> V_7 -> V_3 . V_10 -- ;
if ( V_2 -> V_7 -> V_3 . V_10 )
goto V_16;
F_2 ( & V_2 -> V_7 -> V_3 . V_8 ) ;
V_14 = F_3 ( V_2 -> V_7 ) ;
do {
V_12 = F_7 ( * V_14 ) ;
V_13 = V_12 ;
V_13 . V_18 = 0 ;
} while ( F_9 ( & V_14 -> V_19 , V_12 . V_19 , V_13 . V_19 ) != V_12 . V_19 );
F_4 ( & V_2 -> V_7 -> V_3 . V_8 ) ;
F_12 ( & V_2 -> V_7 -> V_3 . V_20 ) ;
V_16:
F_10 ( & V_2 -> V_7 -> V_3 . V_15 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
union V_11 V_12 , V_13 , * V_14 ;
V_17:
F_2 ( & V_2 -> V_7 -> V_3 . V_8 ) ;
V_14 = F_3 ( V_2 -> V_7 ) ;
do {
V_12 = F_7 ( * V_14 ) ;
if ( V_12 . V_21 ) {
F_4 ( & V_2 -> V_7 -> V_3 . V_8 ) ;
F_8 () ;
goto V_17;
}
V_13 = V_12 ;
V_13 . V_18 = 1 ;
V_13 . V_9 ++ ;
} while ( F_9 ( & V_14 -> V_19 , V_12 . V_19 , V_13 . V_19 ) != V_12 . V_19 );
F_4 ( & V_2 -> V_7 -> V_3 . V_8 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
union V_11 V_12 , V_13 , * V_14 ;
F_2 ( & V_2 -> V_7 -> V_3 . V_8 ) ;
V_14 = F_3 ( V_2 -> V_7 ) ;
do {
V_12 = F_7 ( * V_14 ) ;
V_13 = V_12 ;
V_13 . V_9 -- ;
if ( ! V_13 . V_9 )
V_13 . V_18 = 0 ;
} while ( F_9 ( & V_14 -> V_19 , V_12 . V_19 , V_13 . V_19 ) != V_12 . V_19 );
F_4 ( & V_2 -> V_7 -> V_3 . V_8 ) ;
if ( ! V_13 . V_9 )
F_12 ( & V_2 -> V_7 -> V_3 . V_20 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 -> V_5 & 1 )
F_13 ( V_2 ) ;
else
F_5 ( V_2 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 -> V_5 & 1 )
F_14 ( V_2 ) ;
else
F_11 ( V_2 ) ;
}
static int F_17 ( struct V_1 * V_2 , union V_22 * V_22 , T_1 V_23 ,
int V_24 )
{
union V_25 V_25 ;
struct V_26 V_26 ;
struct V_27 V_27 ;
unsigned long V_28 , V_29 ;
union V_30 V_30 ;
int V_31 , V_6 ;
T_2 V_32 ;
if ( V_23 >= V_33 )
return - V_34 ;
F_18 ( V_2 -> V_35 -> V_36 . V_37 . V_38 ) ;
V_25 . V_19 = V_2 -> V_35 -> V_36 . V_37 . V_38 [ V_23 ] ;
if ( V_23 == 0 || V_25 . V_19 == 0 ) {
V_22 -> V_19 = V_2 -> V_3 . V_4 -> V_39 [ 1 ] ;
return 0 ;
} else if ( V_25 . V_19 == 1 ) {
V_22 -> V_19 = V_2 -> V_3 . V_4 -> V_39 [ 7 ] ;
return 0 ;
}
if ( V_25 . V_40 )
return V_41 ;
if ( V_25 . V_42 )
V_28 = V_2 -> V_3 . V_4 -> V_39 [ 5 ] ;
else
V_28 = V_2 -> V_3 . V_4 -> V_39 [ 2 ] ;
V_28 &= 0x7fffffc0 ;
V_6 = F_19 ( V_2 , V_28 + 16 , & V_30 . V_19 , sizeof( union V_30 ) ) ;
if ( V_6 )
return V_6 ;
if ( V_25 . V_43 / 8 > V_30 . V_44 )
return V_45 ;
if ( 0x7fffffff - V_30 . V_46 * 128 < V_25 . V_43 * 16 )
return V_47 ;
V_6 = F_19 ( V_2 , V_30 . V_46 * 128 + V_25 . V_43 * 16 , & V_26 ,
sizeof( struct V_26 ) ) ;
if ( V_6 )
return V_6 ;
if ( V_26 . V_48 == 1 )
return V_45 ;
if ( V_26 . V_49 != V_25 . V_49 )
return V_50 ;
V_6 = F_19 ( V_2 , V_26 . V_51 * 64 , & V_27 , sizeof( struct V_27 ) ) ;
if ( V_6 )
return V_6 ;
if ( V_27 . V_48 )
return V_52 ;
if ( V_27 . V_53 != V_26 . V_53 )
return V_54 ;
if ( V_26 . V_42 == 1 ) {
V_31 = ( V_2 -> V_3 . V_4 -> V_39 [ 8 ] >> 16 ) & 0xffff ;
if ( V_26 . V_55 != V_31 ) {
if ( V_31 / 16 > V_27 . V_56 )
return V_57 ;
V_29 = V_27 . V_58 * 4 + V_31 / 4 ;
V_6 = F_19 ( V_2 , V_29 ,
& V_32 ,
sizeof( T_2 ) ) ;
if ( V_6 )
return V_6 ;
if ( ( V_32 & ( 0x40 >> ( ( V_31 & 3 ) * 2 ) ) ) == 0 )
return V_57 ;
}
}
if ( V_26 . V_59 == 1 && V_24 )
return V_60 ;
V_22 -> V_19 = V_27 . V_22 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , union V_22 * V_22 ,
T_1 V_23 , int V_24 )
{
int V_6 ;
T_3 * V_61 = & V_2 -> V_3 . V_4 -> V_62 ;
struct V_63 * V_64 = & V_2 -> V_3 . V_64 ;
struct V_65 * V_66 ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
V_66 = (struct V_65 * ) & V_64 -> V_67 ;
V_66 -> V_68 = V_24 ? V_69 : V_70 ;
V_66 -> V_71 = F_21 ( * V_61 ) . V_71 ;
if ( ! F_21 ( * V_61 ) . V_72 ) {
V_22 -> V_19 = 0 ;
V_22 -> V_73 = 1 ;
return 0 ;
}
switch ( F_21 ( V_2 -> V_3 . V_4 -> V_62 ) . V_71 ) {
case V_74 :
V_22 -> V_19 = V_2 -> V_3 . V_4 -> V_39 [ 1 ] ;
return 0 ;
case V_75 :
V_22 -> V_19 = V_2 -> V_3 . V_4 -> V_39 [ 7 ] ;
return 0 ;
case V_76 :
V_22 -> V_19 = V_2 -> V_3 . V_4 -> V_39 [ 13 ] ;
return 0 ;
case V_77 :
V_6 = F_17 ( V_2 , V_22 , V_23 , V_24 ) ;
switch ( V_6 ) {
case V_45 :
case V_50 :
case V_52 :
case V_54 :
case V_57 :
V_2 -> V_3 . V_64 . V_78 = V_23 ;
break;
case V_60 :
V_66 -> V_79 = 1 ;
V_66 -> V_80 = 1 ;
break;
}
if ( V_6 > 0 )
V_64 -> V_81 = V_6 ;
return V_6 ;
}
return 0 ;
}
static int F_22 ( struct V_7 * V_7 , unsigned long V_82 , unsigned long * V_19 )
{
return F_23 ( V_7 , V_82 , V_19 , sizeof( * V_19 ) ) ;
}
static unsigned long F_24 ( struct V_1 * V_2 , unsigned long V_83 ,
unsigned long * V_82 , const union V_22 V_22 ,
int V_24 )
{
union V_84 V_85 = { . V_86 = V_83 } ;
union V_87 V_88 = { . V_86 = V_83 } ;
union V_89 V_90 ;
int V_91 = 0 ;
union V_92 V_92 ;
unsigned long V_93 ;
int V_94 , V_95 ;
V_92 . V_19 = V_2 -> V_3 . V_4 -> V_39 [ 0 ] ;
V_94 = V_92 . V_96 && F_25 ( V_2 -> V_7 , 8 ) ;
V_95 = V_94 && F_25 ( V_2 -> V_7 , 78 ) ;
if ( V_22 . V_73 )
goto V_97;
V_93 = V_22 . V_98 * 4096 ;
switch ( V_22 . V_99 ) {
case V_100 :
if ( V_85 . V_101 > V_22 . V_102 )
return V_103 ;
V_93 += V_85 . V_104 * 8 ;
break;
case V_105 :
if ( V_85 . V_104 )
return V_106 ;
if ( V_85 . V_107 > V_22 . V_102 )
return V_108 ;
V_93 += V_85 . V_109 * 8 ;
break;
case V_110 :
if ( V_85 . V_104 || V_85 . V_109 )
return V_106 ;
if ( V_85 . V_111 > V_22 . V_102 )
return V_112 ;
V_93 += V_85 . V_113 * 8 ;
break;
case V_114 :
if ( V_85 . V_104 || V_85 . V_109 || V_85 . V_113 )
return V_106 ;
if ( V_85 . V_115 > V_22 . V_102 )
return V_116 ;
V_93 += V_85 . V_117 * 8 ;
break;
}
switch ( V_22 . V_99 ) {
case V_100 : {
union V_118 V_119 ;
if ( F_26 ( V_2 -> V_7 , V_93 ) )
return V_47 ;
if ( F_22 ( V_2 -> V_7 , V_93 , & V_119 . V_19 ) )
return - V_120 ;
if ( V_119 . V_48 )
return V_103 ;
if ( V_119 . V_121 != V_122 )
return V_123 ;
if ( V_85 . V_107 < V_119 . V_124 || V_85 . V_107 > V_119 . V_102 )
return V_108 ;
if ( V_94 )
V_91 |= V_119 . V_42 ;
V_93 = V_119 . V_125 * 4096 + V_85 . V_109 * 8 ;
}
case V_105 : {
union V_126 V_127 ;
if ( F_26 ( V_2 -> V_7 , V_93 ) )
return V_47 ;
if ( F_22 ( V_2 -> V_7 , V_93 , & V_127 . V_19 ) )
return - V_120 ;
if ( V_127 . V_48 )
return V_108 ;
if ( V_127 . V_121 != V_128 )
return V_123 ;
if ( V_85 . V_111 < V_127 . V_124 || V_85 . V_111 > V_127 . V_102 )
return V_112 ;
if ( V_94 )
V_91 |= V_127 . V_42 ;
V_93 = V_127 . V_125 * 4096 + V_85 . V_113 * 8 ;
}
case V_110 : {
union V_129 V_130 ;
if ( F_26 ( V_2 -> V_7 , V_93 ) )
return V_47 ;
if ( F_22 ( V_2 -> V_7 , V_93 , & V_130 . V_19 ) )
return - V_120 ;
if ( V_130 . V_48 )
return V_112 ;
if ( V_130 . V_121 != V_131 )
return V_123 ;
if ( V_130 . V_132 && V_22 . V_42 && V_95 )
return V_123 ;
if ( V_130 . V_133 && V_95 ) {
V_91 |= V_130 . V_134 . V_42 ;
V_88 . V_135 = V_130 . V_134 . V_135 ;
goto V_136;
}
if ( V_85 . V_115 < V_130 . V_137 . V_124 )
return V_116 ;
if ( V_85 . V_115 > V_130 . V_137 . V_102 )
return V_116 ;
if ( V_94 )
V_91 |= V_130 . V_137 . V_42 ;
V_93 = V_130 . V_137 . V_138 * 4096 + V_85 . V_117 * 8 ;
}
case V_114 : {
union V_139 V_140 ;
if ( F_26 ( V_2 -> V_7 , V_93 ) )
return V_47 ;
if ( F_22 ( V_2 -> V_7 , V_93 , & V_140 . V_19 ) )
return - V_120 ;
if ( V_140 . V_48 )
return V_116 ;
if ( V_140 . V_121 != V_141 )
return V_123 ;
if ( V_140 . V_142 && V_22 . V_42 )
return V_123 ;
if ( V_140 . V_133 && V_94 ) {
V_91 |= V_140 . V_134 . V_42 ;
V_88 . V_143 = V_140 . V_134 . V_143 ;
goto V_136;
}
V_91 |= V_140 . V_137 . V_42 ;
V_93 = V_140 . V_137 . V_144 * 2048 + V_85 . V_145 * 8 ;
}
}
if ( F_26 ( V_2 -> V_7 , V_93 ) )
return V_47 ;
if ( F_22 ( V_2 -> V_7 , V_93 , & V_90 . V_19 ) )
return - V_120 ;
if ( V_90 . V_48 )
return V_146 ;
if ( V_90 . V_147 )
return V_123 ;
if ( V_90 . V_148 && ! V_94 )
return V_123 ;
V_91 |= V_90 . V_42 ;
V_88 . V_149 = V_90 . V_149 ;
V_97:
V_88 . V_86 = F_27 ( V_2 , V_88 . V_86 ) ;
V_136:
if ( V_24 && V_91 )
return V_60 ;
if ( F_26 ( V_2 -> V_7 , V_88 . V_86 ) )
return V_47 ;
* V_82 = V_88 . V_86 ;
return 0 ;
}
static inline int F_28 ( unsigned long V_150 )
{
return ( V_150 & ~ 0x11fful ) == 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
const union V_22 V_22 )
{
union V_92 V_92 = { . V_19 = V_2 -> V_3 . V_4 -> V_39 [ 0 ] } ;
T_3 * V_61 = & V_2 -> V_3 . V_4 -> V_62 ;
if ( ! V_92 . V_151 )
return 0 ;
if ( F_21 ( * V_61 ) . V_72 && V_22 . V_42 )
return 0 ;
return 1 ;
}
static int F_30 ( struct V_1 * V_2 , unsigned long V_150 ,
unsigned long * V_152 , unsigned long V_153 ,
const union V_22 V_22 , int V_24 )
{
struct V_63 * V_64 = & V_2 -> V_3 . V_64 ;
T_3 * V_61 = & V_2 -> V_3 . V_4 -> V_62 ;
struct V_65 * V_66 ;
int V_154 , V_6 ;
V_66 = (struct V_65 * ) & V_64 -> V_67 ;
V_154 = F_29 ( V_2 , V_22 ) ;
while ( V_153 ) {
V_150 = F_31 ( V_2 , V_150 ) ;
V_66 -> V_86 = V_150 >> V_155 ;
if ( V_24 && V_154 && F_28 ( V_150 ) ) {
V_64 -> V_81 = V_60 ;
return V_64 -> V_81 ;
}
V_150 &= V_156 ;
if ( F_21 ( * V_61 ) . V_72 ) {
V_6 = F_24 ( V_2 , V_150 , V_152 , V_22 , V_24 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 == V_60 )
V_66 -> V_80 = 1 ;
if ( V_6 )
V_64 -> V_81 = V_6 ;
} else {
* V_152 = F_27 ( V_2 , V_150 ) ;
if ( F_26 ( V_2 -> V_7 , * V_152 ) )
V_64 -> V_81 = V_47 ;
}
if ( V_64 -> V_81 )
return V_64 -> V_81 ;
V_150 += V_157 ;
V_152 ++ ;
V_153 -- ;
}
return 0 ;
}
int F_32 ( struct V_1 * V_2 , unsigned long V_150 , T_1 V_23 , void * V_158 ,
unsigned long V_159 , int V_24 )
{
T_3 * V_61 = & V_2 -> V_3 . V_4 -> V_62 ;
unsigned long V_160 , V_153 , V_82 , V_161 ;
unsigned long V_162 [ 2 ] ;
unsigned long * V_152 ;
int V_163 ;
union V_22 V_22 ;
int V_6 ;
if ( ! V_159 )
return 0 ;
V_6 = F_20 ( V_2 , & V_22 , V_23 , V_24 ) ;
if ( V_6 )
return V_6 ;
V_153 = ( ( ( V_150 & ~ V_156 ) + V_159 - 1 ) >> V_155 ) + 1 ;
V_152 = V_162 ;
if ( V_153 > F_33 ( V_162 ) )
V_152 = F_34 ( V_153 * sizeof( unsigned long ) ) ;
if ( ! V_152 )
return - V_164 ;
V_163 = F_21 ( * V_61 ) . V_72 && ! V_22 . V_73 ;
if ( V_163 )
F_15 ( V_2 ) ;
V_6 = F_30 ( V_2 , V_150 , V_152 , V_153 , V_22 , V_24 ) ;
for ( V_161 = 0 ; V_161 < V_153 && ! V_6 ; V_161 ++ ) {
V_82 = * ( V_152 + V_161 ) + ( V_150 & ~ V_156 ) ;
V_160 = F_35 ( V_157 - ( V_82 & ~ V_156 ) , V_159 ) ;
if ( V_24 )
V_6 = F_36 ( V_2 -> V_7 , V_82 , V_158 , V_160 ) ;
else
V_6 = F_23 ( V_2 -> V_7 , V_82 , V_158 , V_160 ) ;
V_159 -= V_160 ;
V_150 += V_160 ;
V_158 += V_160 ;
}
if ( V_163 )
F_16 ( V_2 ) ;
if ( V_153 > F_33 ( V_162 ) )
F_37 ( V_152 ) ;
return V_6 ;
}
int F_38 ( struct V_1 * V_2 , unsigned long V_165 ,
void * V_158 , unsigned long V_159 , int V_24 )
{
unsigned long V_160 , V_82 ;
int V_6 = 0 ;
while ( V_159 && ! V_6 ) {
V_82 = F_27 ( V_2 , V_165 ) ;
V_160 = F_35 ( V_157 - ( V_82 & ~ V_156 ) , V_159 ) ;
if ( V_24 )
V_6 = F_39 ( V_2 , V_82 , V_158 , V_160 ) ;
else
V_6 = F_40 ( V_2 , V_82 , V_158 , V_160 ) ;
V_159 -= V_160 ;
V_165 += V_160 ;
V_158 += V_160 ;
}
return V_6 ;
}
int F_41 ( struct V_1 * V_2 , unsigned long V_83 , T_1 V_23 ,
unsigned long * V_82 , int V_24 )
{
struct V_63 * V_64 = & V_2 -> V_3 . V_64 ;
T_3 * V_61 = & V_2 -> V_3 . V_4 -> V_62 ;
struct V_65 * V_166 ;
union V_22 V_22 ;
int V_6 ;
V_83 = F_31 ( V_2 , V_83 ) ;
V_166 = (struct V_65 * ) & V_64 -> V_67 ;
V_6 = F_20 ( V_2 , & V_22 , V_23 , V_24 ) ;
V_166 -> V_86 = V_83 >> V_155 ;
if ( V_6 )
return V_6 ;
if ( F_28 ( V_83 ) && F_29 ( V_2 , V_22 ) ) {
if ( V_24 ) {
V_6 = V_64 -> V_81 = V_60 ;
return V_6 ;
}
}
if ( F_21 ( * V_61 ) . V_72 && ! V_22 . V_73 ) {
V_6 = F_24 ( V_2 , V_83 , V_82 , V_22 , V_24 ) ;
if ( V_6 > 0 ) {
if ( V_6 == V_60 )
V_166 -> V_80 = 1 ;
V_64 -> V_81 = V_6 ;
}
} else {
V_6 = 0 ;
* V_82 = F_27 ( V_2 , V_83 ) ;
if ( F_26 ( V_2 -> V_7 , * V_82 ) )
V_6 = V_64 -> V_81 = V_47 ;
}
return V_6 ;
}
int F_42 ( struct V_1 * V_2 , unsigned long V_83 , T_1 V_23 ,
unsigned long V_167 , int V_168 )
{
unsigned long V_82 ;
unsigned long V_169 ;
int V_6 = 0 ;
F_15 ( V_2 ) ;
while ( V_167 > 0 && ! V_6 ) {
V_169 = F_35 ( V_167 , V_157 - ( V_83 % V_157 ) ) ;
V_6 = F_41 ( V_2 , V_83 , V_23 , & V_82 , V_168 ) ;
V_83 += V_169 ;
V_167 -= V_169 ;
}
F_16 ( V_2 ) ;
return V_6 ;
}
int F_43 ( struct V_1 * V_2 , unsigned long V_165 )
{
struct V_63 * V_64 = & V_2 -> V_3 . V_64 ;
T_3 * V_61 = & V_2 -> V_3 . V_4 -> V_62 ;
struct V_65 * V_66 ;
union V_92 V_92 = { . V_19 = V_2 -> V_3 . V_4 -> V_39 [ 0 ] } ;
if ( ! V_92 . V_151 || ! F_28 ( V_165 ) )
return 0 ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
V_66 = (struct V_65 * ) & V_64 -> V_67 ;
V_66 -> V_68 = V_69 ;
V_66 -> V_71 = F_21 ( * V_61 ) . V_71 ;
V_66 -> V_86 = V_165 >> V_155 ;
V_64 -> V_81 = V_60 ;
return V_64 -> V_81 ;
}
