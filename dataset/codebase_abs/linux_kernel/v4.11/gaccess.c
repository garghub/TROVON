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
enum V_24 V_25 )
{
union V_26 V_26 ;
struct V_27 V_27 ;
struct V_28 V_28 ;
unsigned long V_29 , V_30 ;
union V_31 V_31 ;
int V_32 , V_6 ;
T_1 V_33 ;
if ( V_23 >= V_34 )
return - V_35 ;
F_18 ( V_2 -> V_36 -> V_37 . V_38 . V_39 ) ;
V_26 . V_19 = V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_23 ] ;
if ( V_23 == 0 || V_26 . V_19 == 0 ) {
V_22 -> V_19 = V_2 -> V_3 . V_4 -> V_40 [ 1 ] ;
return 0 ;
} else if ( V_26 . V_19 == 1 ) {
V_22 -> V_19 = V_2 -> V_3 . V_4 -> V_40 [ 7 ] ;
return 0 ;
}
if ( V_26 . V_41 )
return V_42 ;
if ( V_26 . V_43 )
V_29 = V_2 -> V_3 . V_4 -> V_40 [ 5 ] ;
else
V_29 = V_2 -> V_3 . V_4 -> V_40 [ 2 ] ;
V_29 &= 0x7fffffc0 ;
V_6 = F_19 ( V_2 , V_29 + 16 , & V_31 . V_19 , sizeof( union V_31 ) ) ;
if ( V_6 )
return V_6 ;
if ( V_26 . V_44 / 8 > V_31 . V_45 )
return V_46 ;
if ( 0x7fffffff - V_31 . V_47 * 128 < V_26 . V_44 * 16 )
return V_48 ;
V_6 = F_19 ( V_2 , V_31 . V_47 * 128 + V_26 . V_44 * 16 , & V_27 ,
sizeof( struct V_27 ) ) ;
if ( V_6 )
return V_6 ;
if ( V_27 . V_49 == 1 )
return V_46 ;
if ( V_27 . V_50 != V_26 . V_50 )
return V_51 ;
V_6 = F_19 ( V_2 , V_27 . V_52 * 64 , & V_28 , sizeof( struct V_28 ) ) ;
if ( V_6 )
return V_6 ;
if ( V_28 . V_49 )
return V_53 ;
if ( V_28 . V_54 != V_27 . V_54 )
return V_55 ;
if ( V_27 . V_43 == 1 ) {
V_32 = ( V_2 -> V_3 . V_4 -> V_40 [ 8 ] >> 16 ) & 0xffff ;
if ( V_27 . V_56 != V_32 ) {
if ( V_32 / 16 > V_28 . V_57 )
return V_58 ;
V_30 = V_28 . V_59 * 4 + V_32 / 4 ;
V_6 = F_19 ( V_2 , V_30 ,
& V_33 ,
sizeof( T_1 ) ) ;
if ( V_6 )
return V_6 ;
if ( ( V_33 & ( 0x40 >> ( ( V_32 & 3 ) * 2 ) ) ) == 0 )
return V_58 ;
}
}
if ( V_27 . V_60 == 1 && V_25 == V_61 )
return V_62 ;
V_22 -> V_19 = V_28 . V_22 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_63 , unsigned long V_64 ,
T_1 V_23 , enum V_24 V_25 , enum V_65 V_66 )
{
struct V_67 * V_68 = & V_2 -> V_3 . V_68 ;
struct V_69 * V_70 ;
memset ( V_68 , 0 , sizeof( * V_68 ) ) ;
V_68 -> V_63 = V_63 ;
V_70 = (struct V_69 * ) & V_68 -> V_71 ;
switch ( V_63 ) {
case V_62 :
switch ( V_66 ) {
case V_72 :
V_70 -> V_73 = 1 ;
break;
case V_74 :
V_70 -> V_75 = 1 ;
break;
case V_76 :
V_70 -> V_75 = 1 ;
case V_77 :
V_70 -> V_78 = 1 ;
break;
}
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
V_70 -> V_85 = V_64 >> V_86 ;
V_70 -> V_87 = V_25 == V_61 ? V_88 : V_89 ;
V_70 -> V_90 = F_21 ( V_2 -> V_3 . V_4 -> V_91 ) . V_90 ;
case V_46 :
case V_51 :
case V_53 :
case V_55 :
case V_58 :
V_68 -> V_92 = V_23 ;
break;
}
return V_63 ;
}
static int F_22 ( struct V_1 * V_2 , union V_22 * V_22 ,
unsigned long V_93 , T_1 V_23 , enum V_24 V_25 )
{
int V_6 ;
struct F_21 V_94 = F_21 ( V_2 -> V_3 . V_4 -> V_91 ) ;
if ( ! V_94 . V_95 ) {
V_22 -> V_19 = 0 ;
V_22 -> V_96 = 1 ;
return 0 ;
}
if ( V_25 == V_97 )
V_94 . V_90 = V_94 . V_90 == V_98 ? V_98 : V_99 ;
switch ( V_94 . V_90 ) {
case V_99 :
V_22 -> V_19 = V_2 -> V_3 . V_4 -> V_40 [ 1 ] ;
return 0 ;
case V_100 :
V_22 -> V_19 = V_2 -> V_3 . V_4 -> V_40 [ 7 ] ;
return 0 ;
case V_98 :
V_22 -> V_19 = V_2 -> V_3 . V_4 -> V_40 [ 13 ] ;
return 0 ;
case V_101 :
V_6 = F_17 ( V_2 , V_22 , V_23 , V_25 ) ;
if ( V_6 > 0 )
return F_20 ( V_2 , V_6 , V_93 , V_23 , V_25 , V_76 ) ;
return V_6 ;
}
return 0 ;
}
static int F_23 ( struct V_7 * V_7 , unsigned long V_102 , unsigned long * V_19 )
{
return F_24 ( V_7 , V_102 , V_19 , sizeof( * V_19 ) ) ;
}
static unsigned long F_25 ( struct V_1 * V_2 , unsigned long V_64 ,
unsigned long * V_102 , const union V_22 V_22 ,
enum V_24 V_25 )
{
union V_103 V_104 = { . V_85 = V_64 } ;
union V_105 V_106 = { . V_85 = V_64 } ;
union V_107 V_108 ;
int V_109 = 0 ;
union V_110 V_110 ;
unsigned long V_111 ;
int V_112 , V_113 ;
V_110 . V_19 = V_2 -> V_3 . V_4 -> V_40 [ 0 ] ;
V_112 = V_110 . V_114 && F_26 ( V_2 -> V_7 , 8 ) ;
V_113 = V_112 && F_26 ( V_2 -> V_7 , 78 ) ;
if ( V_22 . V_96 )
goto V_115;
V_111 = V_22 . V_116 * 4096 ;
switch ( V_22 . V_117 ) {
case V_118 :
if ( V_104 . V_119 > V_22 . V_120 )
return V_81 ;
V_111 += V_104 . V_121 * 8 ;
break;
case V_122 :
if ( V_104 . V_121 )
return V_79 ;
if ( V_104 . V_123 > V_22 . V_120 )
return V_82 ;
V_111 += V_104 . V_124 * 8 ;
break;
case V_125 :
if ( V_104 . V_121 || V_104 . V_124 )
return V_79 ;
if ( V_104 . V_126 > V_22 . V_120 )
return V_83 ;
V_111 += V_104 . V_127 * 8 ;
break;
case V_128 :
if ( V_104 . V_121 || V_104 . V_124 || V_104 . V_127 )
return V_79 ;
if ( V_104 . V_129 > V_22 . V_120 )
return V_84 ;
V_111 += V_104 . V_130 * 8 ;
break;
}
switch ( V_22 . V_117 ) {
case V_118 : {
union V_131 V_132 ;
if ( F_27 ( V_2 -> V_7 , V_111 ) )
return V_48 ;
if ( F_23 ( V_2 -> V_7 , V_111 , & V_132 . V_19 ) )
return - V_133 ;
if ( V_132 . V_49 )
return V_81 ;
if ( V_132 . V_134 != V_135 )
return V_136 ;
if ( V_104 . V_123 < V_132 . V_137 || V_104 . V_123 > V_132 . V_120 )
return V_82 ;
if ( V_112 )
V_109 |= V_132 . V_43 ;
V_111 = V_132 . V_138 * 4096 + V_104 . V_124 * 8 ;
}
case V_122 : {
union V_139 V_140 ;
if ( F_27 ( V_2 -> V_7 , V_111 ) )
return V_48 ;
if ( F_23 ( V_2 -> V_7 , V_111 , & V_140 . V_19 ) )
return - V_133 ;
if ( V_140 . V_49 )
return V_82 ;
if ( V_140 . V_134 != V_141 )
return V_136 ;
if ( V_104 . V_126 < V_140 . V_137 || V_104 . V_126 > V_140 . V_120 )
return V_83 ;
if ( V_112 )
V_109 |= V_140 . V_43 ;
V_111 = V_140 . V_138 * 4096 + V_104 . V_127 * 8 ;
}
case V_125 : {
union V_142 V_143 ;
if ( F_27 ( V_2 -> V_7 , V_111 ) )
return V_48 ;
if ( F_23 ( V_2 -> V_7 , V_111 , & V_143 . V_19 ) )
return - V_133 ;
if ( V_143 . V_49 )
return V_83 ;
if ( V_143 . V_134 != V_144 )
return V_136 ;
if ( V_143 . V_145 && V_22 . V_43 && V_113 )
return V_136 ;
if ( V_143 . V_146 && V_113 ) {
V_109 |= V_143 . V_147 . V_43 ;
V_106 . V_148 = V_143 . V_147 . V_148 ;
goto V_149;
}
if ( V_104 . V_129 < V_143 . V_150 . V_137 )
return V_84 ;
if ( V_104 . V_129 > V_143 . V_150 . V_120 )
return V_84 ;
if ( V_112 )
V_109 |= V_143 . V_150 . V_43 ;
V_111 = V_143 . V_150 . V_151 * 4096 + V_104 . V_130 * 8 ;
}
case V_128 : {
union V_152 V_153 ;
if ( F_27 ( V_2 -> V_7 , V_111 ) )
return V_48 ;
if ( F_23 ( V_2 -> V_7 , V_111 , & V_153 . V_19 ) )
return - V_133 ;
if ( V_153 . V_49 )
return V_84 ;
if ( V_153 . V_134 != V_154 )
return V_136 ;
if ( V_153 . V_155 && V_22 . V_43 )
return V_136 ;
if ( V_153 . V_146 && V_112 ) {
V_109 |= V_153 . V_147 . V_43 ;
V_106 . V_156 = V_153 . V_147 . V_156 ;
goto V_149;
}
V_109 |= V_153 . V_150 . V_43 ;
V_111 = V_153 . V_150 . V_157 * 2048 + V_104 . V_158 * 8 ;
}
}
if ( F_27 ( V_2 -> V_7 , V_111 ) )
return V_48 ;
if ( F_23 ( V_2 -> V_7 , V_111 , & V_108 . V_19 ) )
return - V_133 ;
if ( V_108 . V_49 )
return V_80 ;
if ( V_108 . V_159 )
return V_136 ;
V_109 |= V_108 . V_43 ;
V_106 . V_160 = V_108 . V_160 ;
V_115:
V_106 . V_85 = F_28 ( V_2 , V_106 . V_85 ) ;
V_149:
if ( V_25 == V_61 && V_109 )
return V_62 ;
if ( F_27 ( V_2 -> V_7 , V_106 . V_85 ) )
return V_48 ;
* V_102 = V_106 . V_85 ;
return 0 ;
}
static inline int F_29 ( unsigned long V_93 )
{
return ( V_93 & ~ 0x11fful ) == 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
const union V_22 V_22 )
{
union V_110 V_110 = { . V_19 = V_2 -> V_3 . V_4 -> V_40 [ 0 ] } ;
T_2 * V_94 = & V_2 -> V_3 . V_4 -> V_91 ;
if ( ! V_110 . V_161 )
return 0 ;
if ( F_21 ( * V_94 ) . V_95 && V_22 . V_43 )
return 0 ;
return 1 ;
}
static int F_31 ( struct V_1 * V_2 , unsigned long V_93 , T_1 V_23 ,
unsigned long * V_162 , unsigned long V_163 ,
const union V_22 V_22 , enum V_24 V_25 )
{
T_2 * V_94 = & V_2 -> V_3 . V_4 -> V_91 ;
int V_164 , V_6 = 0 ;
V_164 = F_30 ( V_2 , V_22 ) ;
while ( V_163 ) {
V_93 = F_32 ( V_2 , V_93 ) ;
if ( V_25 == V_61 && V_164 && F_29 ( V_93 ) )
return F_20 ( V_2 , V_62 , V_93 , V_23 , V_25 ,
V_72 ) ;
V_93 &= V_165 ;
if ( F_21 ( * V_94 ) . V_95 ) {
V_6 = F_25 ( V_2 , V_93 , V_162 , V_22 , V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
} else {
* V_162 = F_28 ( V_2 , V_93 ) ;
if ( F_27 ( V_2 -> V_7 , * V_162 ) )
V_6 = V_48 ;
}
if ( V_6 )
return F_20 ( V_2 , V_6 , V_93 , V_23 , V_25 , V_77 ) ;
V_93 += V_166 ;
V_162 ++ ;
V_163 -- ;
}
return 0 ;
}
int F_33 ( struct V_1 * V_2 , unsigned long V_93 , T_1 V_23 , void * V_167 ,
unsigned long V_168 , enum V_24 V_25 )
{
T_2 * V_94 = & V_2 -> V_3 . V_4 -> V_91 ;
unsigned long V_169 , V_163 , V_102 , V_170 ;
unsigned long V_171 [ 2 ] ;
unsigned long * V_162 ;
int V_172 ;
union V_22 V_22 ;
int V_6 ;
if ( ! V_168 )
return 0 ;
V_93 = F_32 ( V_2 , V_93 ) ;
V_6 = F_22 ( V_2 , & V_22 , V_93 , V_23 , V_25 ) ;
if ( V_6 )
return V_6 ;
V_163 = ( ( ( V_93 & ~ V_165 ) + V_168 - 1 ) >> V_86 ) + 1 ;
V_162 = V_171 ;
if ( V_163 > F_34 ( V_171 ) )
V_162 = F_35 ( V_163 * sizeof( unsigned long ) ) ;
if ( ! V_162 )
return - V_173 ;
V_172 = F_21 ( * V_94 ) . V_95 && ! V_22 . V_96 ;
if ( V_172 )
F_15 ( V_2 ) ;
V_6 = F_31 ( V_2 , V_93 , V_23 , V_162 , V_163 , V_22 , V_25 ) ;
for ( V_170 = 0 ; V_170 < V_163 && ! V_6 ; V_170 ++ ) {
V_102 = * ( V_162 + V_170 ) + ( V_93 & ~ V_165 ) ;
V_169 = F_36 ( V_166 - ( V_102 & ~ V_165 ) , V_168 ) ;
if ( V_25 == V_61 )
V_6 = F_37 ( V_2 -> V_7 , V_102 , V_167 , V_169 ) ;
else
V_6 = F_24 ( V_2 -> V_7 , V_102 , V_167 , V_169 ) ;
V_168 -= V_169 ;
V_93 += V_169 ;
V_167 += V_169 ;
}
if ( V_172 )
F_16 ( V_2 ) ;
if ( V_163 > F_34 ( V_171 ) )
F_38 ( V_162 ) ;
return V_6 ;
}
int F_39 ( struct V_1 * V_2 , unsigned long V_174 ,
void * V_167 , unsigned long V_168 , enum V_24 V_25 )
{
unsigned long V_169 , V_102 ;
int V_6 = 0 ;
while ( V_168 && ! V_6 ) {
V_102 = F_28 ( V_2 , V_174 ) ;
V_169 = F_36 ( V_166 - ( V_102 & ~ V_165 ) , V_168 ) ;
if ( V_25 )
V_6 = F_40 ( V_2 , V_102 , V_167 , V_169 ) ;
else
V_6 = F_41 ( V_2 , V_102 , V_167 , V_169 ) ;
V_168 -= V_169 ;
V_174 += V_169 ;
V_167 += V_169 ;
}
return V_6 ;
}
int F_42 ( struct V_1 * V_2 , unsigned long V_64 , T_1 V_23 ,
unsigned long * V_102 , enum V_24 V_25 )
{
T_2 * V_94 = & V_2 -> V_3 . V_4 -> V_91 ;
union V_22 V_22 ;
int V_6 ;
V_64 = F_32 ( V_2 , V_64 ) ;
V_6 = F_22 ( V_2 , & V_22 , V_64 , V_23 , V_25 ) ;
if ( V_6 )
return V_6 ;
if ( F_29 ( V_64 ) && F_30 ( V_2 , V_22 ) ) {
if ( V_25 == V_61 )
return F_20 ( V_2 , V_62 , V_64 , 0 ,
V_25 , V_72 ) ;
}
if ( F_21 ( * V_94 ) . V_95 && ! V_22 . V_96 ) {
V_6 = F_25 ( V_2 , V_64 , V_102 , V_22 , V_25 ) ;
if ( V_6 > 0 )
return F_20 ( V_2 , V_6 , V_64 , 0 , V_25 , V_77 ) ;
} else {
* V_102 = F_28 ( V_2 , V_64 ) ;
if ( F_27 ( V_2 -> V_7 , * V_102 ) )
return F_20 ( V_2 , V_6 , V_64 , V_48 , V_25 , 0 ) ;
}
return V_6 ;
}
int F_43 ( struct V_1 * V_2 , unsigned long V_64 , T_1 V_23 ,
unsigned long V_175 , enum V_24 V_25 )
{
unsigned long V_102 ;
unsigned long V_176 ;
int V_6 = 0 ;
F_15 ( V_2 ) ;
while ( V_175 > 0 && ! V_6 ) {
V_176 = F_36 ( V_175 , V_166 - ( V_64 % V_166 ) ) ;
V_6 = F_42 ( V_2 , V_64 , V_23 , & V_102 , V_25 ) ;
V_64 += V_176 ;
V_175 -= V_176 ;
}
F_16 ( V_2 ) ;
return V_6 ;
}
int F_44 ( struct V_1 * V_2 , unsigned long V_174 )
{
union V_110 V_110 = { . V_19 = V_2 -> V_3 . V_4 -> V_40 [ 0 ] } ;
if ( ! V_110 . V_161 || ! F_29 ( V_174 ) )
return 0 ;
return F_20 ( V_2 , V_62 , V_174 , 0 , V_61 , V_72 ) ;
}
static int F_45 ( struct V_177 * V_178 , unsigned long V_179 ,
unsigned long * V_180 , int * V_109 ,
int * V_181 )
{
struct V_177 * V_182 ;
union V_22 V_22 ;
union V_103 V_104 ;
unsigned long V_111 ;
int V_6 ;
* V_181 = 0 ;
* V_109 = 0 ;
V_182 = V_178 -> V_182 ;
V_104 . V_85 = V_179 ;
V_22 . V_19 = V_178 -> V_183 ;
V_111 = V_22 . V_116 * 4096 ;
if ( V_22 . V_96 ) {
* V_181 = 1 ;
V_22 . V_117 = V_118 ;
}
switch ( V_22 . V_117 ) {
case V_118 :
if ( V_104 . V_119 > V_22 . V_120 && ! V_22 . V_96 )
return V_81 ;
break;
case V_122 :
if ( V_104 . V_121 )
return V_79 ;
if ( V_104 . V_123 > V_22 . V_120 )
return V_82 ;
break;
case V_125 :
if ( V_104 . V_121 || V_104 . V_124 )
return V_79 ;
if ( V_104 . V_126 > V_22 . V_120 )
return V_83 ;
break;
case V_128 :
if ( V_104 . V_121 || V_104 . V_124 || V_104 . V_127 )
return V_79 ;
if ( V_104 . V_129 > V_22 . V_120 )
return V_84 ;
break;
}
switch ( V_22 . V_117 ) {
case V_118 : {
union V_131 V_132 ;
if ( * V_181 ) {
V_111 = V_111 + ( ( unsigned long ) V_104 . V_124 << 53UL ) ;
V_132 . V_19 = V_111 ;
goto V_184;
}
V_6 = F_46 ( V_182 , V_111 + V_104 . V_121 * 8 , & V_132 . V_19 ) ;
if ( V_6 )
return V_6 ;
if ( V_132 . V_49 )
return V_81 ;
if ( V_132 . V_134 != V_135 )
return V_136 ;
if ( V_104 . V_123 < V_132 . V_137 || V_104 . V_123 > V_132 . V_120 )
return V_82 ;
if ( V_178 -> V_185 >= 1 )
* V_109 |= V_132 . V_43 ;
V_111 = V_132 . V_138 << 12UL ;
V_184:
V_6 = F_47 ( V_178 , V_179 , V_132 . V_19 , * V_181 ) ;
if ( V_6 )
return V_6 ;
}
case V_122 : {
union V_139 V_140 ;
if ( * V_181 ) {
V_111 = V_111 + ( ( unsigned long ) V_104 . V_127 << 42UL ) ;
V_140 . V_19 = V_111 ;
goto V_186;
}
V_6 = F_46 ( V_182 , V_111 + V_104 . V_124 * 8 , & V_140 . V_19 ) ;
if ( V_6 )
return V_6 ;
if ( V_140 . V_49 )
return V_82 ;
if ( V_140 . V_134 != V_141 )
return V_136 ;
if ( V_104 . V_126 < V_140 . V_137 || V_104 . V_126 > V_140 . V_120 )
return V_83 ;
if ( V_178 -> V_185 >= 1 )
* V_109 |= V_140 . V_43 ;
V_111 = V_140 . V_138 << 12UL ;
V_186:
V_140 . V_43 |= * V_109 ;
V_6 = F_48 ( V_178 , V_179 , V_140 . V_19 , * V_181 ) ;
if ( V_6 )
return V_6 ;
}
case V_125 : {
union V_142 V_143 ;
if ( * V_181 ) {
V_111 = V_111 + ( ( unsigned long ) V_104 . V_130 << 31UL ) ;
V_143 . V_19 = V_111 ;
goto V_187;
}
V_6 = F_46 ( V_182 , V_111 + V_104 . V_127 * 8 , & V_143 . V_19 ) ;
if ( V_6 )
return V_6 ;
if ( V_143 . V_49 )
return V_83 ;
if ( V_143 . V_134 != V_144 )
return V_136 ;
if ( V_143 . V_145 && V_22 . V_43 && V_178 -> V_185 >= 2 )
return V_136 ;
if ( V_143 . V_146 && V_178 -> V_185 >= 2 ) {
* V_109 |= V_143 . V_150 . V_43 ;
* V_181 = 1 ;
V_111 = V_143 . V_147 . V_148 << 31UL ;
V_143 . V_19 = V_111 ;
goto V_187;
}
if ( V_104 . V_129 < V_143 . V_150 . V_137 || V_104 . V_129 > V_143 . V_150 . V_120 )
return V_84 ;
if ( V_178 -> V_185 >= 1 )
* V_109 |= V_143 . V_150 . V_43 ;
V_111 = V_143 . V_150 . V_151 << 12UL ;
V_187:
V_143 . V_150 . V_43 |= * V_109 ;
V_6 = F_49 ( V_178 , V_179 , V_143 . V_19 , * V_181 ) ;
if ( V_6 )
return V_6 ;
}
case V_128 : {
union V_152 V_153 ;
if ( * V_181 ) {
V_111 = V_111 + ( ( unsigned long ) V_104 . V_130 << 20UL ) ;
V_153 . V_19 = V_111 ;
goto V_188;
}
V_6 = F_46 ( V_182 , V_111 + V_104 . V_130 * 8 , & V_153 . V_19 ) ;
if ( V_6 )
return V_6 ;
if ( V_153 . V_49 )
return V_84 ;
if ( V_153 . V_134 != V_154 )
return V_136 ;
if ( V_153 . V_155 && V_22 . V_43 )
return V_136 ;
* V_109 |= V_153 . V_150 . V_43 ;
if ( V_153 . V_146 && V_178 -> V_185 >= 1 ) {
* V_181 = 1 ;
V_111 = V_153 . V_147 . V_156 << 20UL ;
V_153 . V_19 = V_111 ;
goto V_188;
}
V_111 = V_153 . V_150 . V_157 << 11UL ;
V_188:
V_153 . V_150 . V_43 |= * V_109 ;
V_6 = F_50 ( V_178 , V_179 , V_153 . V_19 , * V_181 ) ;
if ( V_6 )
return V_6 ;
}
}
* V_180 = V_111 ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 , struct V_177 * V_178 ,
unsigned long V_179 )
{
union V_103 V_104 ;
union V_107 V_108 ;
unsigned long V_180 ;
int V_109 , V_181 ;
int V_6 ;
F_52 ( & V_178 -> V_189 -> V_190 ) ;
F_15 ( V_2 ) ;
V_6 = F_53 ( V_178 , V_179 , & V_180 , & V_109 , & V_181 ) ;
if ( V_6 )
V_6 = F_45 ( V_178 , V_179 , & V_180 , & V_109 ,
& V_181 ) ;
V_104 . V_85 = V_179 ;
if ( V_181 ) {
V_108 . V_19 = V_180 + ( ( unsigned long ) V_104 . V_158 << 12UL ) ;
goto V_191;
}
if ( ! V_6 )
V_6 = F_46 ( V_178 -> V_182 , V_180 + V_104 . V_158 * 8 , & V_108 . V_19 ) ;
if ( ! V_6 && V_108 . V_49 )
V_6 = V_80 ;
if ( ! V_6 && V_108 . V_159 )
V_6 = V_136 ;
V_191:
V_108 . V_43 |= V_109 ;
if ( ! V_6 )
V_6 = F_54 ( V_178 , V_179 , F_55 ( V_108 . V_19 ) ) ;
F_16 ( V_2 ) ;
F_56 ( & V_178 -> V_189 -> V_190 ) ;
return V_6 ;
}
