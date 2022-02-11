int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 -> V_5 & V_6 ) {
int V_7 ;
F_2 ( & V_2 -> V_8 -> V_3 . V_9 ) ;
V_7 = F_3 ( V_2 -> V_8 ) -> V_10 != 0 ;
F_4 ( & V_2 -> V_8 -> V_3 . V_9 ) ;
return V_7 ;
}
return V_2 -> V_8 -> V_3 . V_11 != 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
union V_12 V_13 , V_14 , * V_15 ;
F_6 ( & V_2 -> V_8 -> V_3 . V_16 ) ;
V_2 -> V_8 -> V_3 . V_11 ++ ;
if ( V_2 -> V_8 -> V_3 . V_11 > 1 )
goto V_17;
V_18:
F_2 ( & V_2 -> V_8 -> V_3 . V_9 ) ;
V_15 = F_3 ( V_2 -> V_8 ) ;
do {
V_13 = F_7 ( * V_15 ) ;
if ( V_13 . V_19 ) {
F_4 ( & V_2 -> V_8 -> V_3 . V_9 ) ;
F_8 () ;
goto V_18;
}
V_14 = V_13 ;
V_14 . V_19 = 1 ;
} while ( F_9 ( & V_15 -> V_20 , V_13 . V_20 , V_14 . V_20 ) != V_13 . V_20 );
F_4 ( & V_2 -> V_8 -> V_3 . V_9 ) ;
V_17:
F_10 ( & V_2 -> V_8 -> V_3 . V_16 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
union V_12 V_13 , V_14 , * V_15 ;
F_6 ( & V_2 -> V_8 -> V_3 . V_16 ) ;
V_2 -> V_8 -> V_3 . V_11 -- ;
if ( V_2 -> V_8 -> V_3 . V_11 )
goto V_17;
F_2 ( & V_2 -> V_8 -> V_3 . V_9 ) ;
V_15 = F_3 ( V_2 -> V_8 ) ;
do {
V_13 = F_7 ( * V_15 ) ;
V_14 = V_13 ;
V_14 . V_19 = 0 ;
} while ( F_9 ( & V_15 -> V_20 , V_13 . V_20 , V_14 . V_20 ) != V_13 . V_20 );
F_4 ( & V_2 -> V_8 -> V_3 . V_9 ) ;
F_12 ( & V_2 -> V_8 -> V_3 . V_21 ) ;
V_17:
F_10 ( & V_2 -> V_8 -> V_3 . V_16 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
union V_12 V_13 , V_14 , * V_15 ;
V_18:
F_2 ( & V_2 -> V_8 -> V_3 . V_9 ) ;
V_15 = F_3 ( V_2 -> V_8 ) ;
do {
V_13 = F_7 ( * V_15 ) ;
if ( V_13 . V_22 ) {
F_4 ( & V_2 -> V_8 -> V_3 . V_9 ) ;
F_8 () ;
goto V_18;
}
V_14 = V_13 ;
V_14 . V_19 = 1 ;
V_14 . V_10 ++ ;
} while ( F_9 ( & V_15 -> V_20 , V_13 . V_20 , V_14 . V_20 ) != V_13 . V_20 );
F_4 ( & V_2 -> V_8 -> V_3 . V_9 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
union V_12 V_13 , V_14 , * V_15 ;
F_2 ( & V_2 -> V_8 -> V_3 . V_9 ) ;
V_15 = F_3 ( V_2 -> V_8 ) ;
do {
V_13 = F_7 ( * V_15 ) ;
V_14 = V_13 ;
V_14 . V_10 -- ;
if ( ! V_14 . V_10 )
V_14 . V_19 = 0 ;
} while ( F_9 ( & V_15 -> V_20 , V_13 . V_20 , V_14 . V_20 ) != V_13 . V_20 );
F_4 ( & V_2 -> V_8 -> V_3 . V_9 ) ;
if ( ! V_14 . V_10 )
F_12 ( & V_2 -> V_8 -> V_3 . V_21 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 -> V_5 & V_6 )
F_13 ( V_2 ) ;
else
F_5 ( V_2 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 -> V_5 & V_6 )
F_14 ( V_2 ) ;
else
F_11 ( V_2 ) ;
}
static int F_17 ( struct V_1 * V_2 , union V_23 * V_23 , T_1 V_24 ,
enum V_25 V_26 )
{
union V_27 V_27 ;
struct V_28 V_28 ;
struct V_29 V_29 ;
unsigned long V_30 , V_31 ;
union V_32 V_32 ;
int V_33 , V_7 ;
T_1 V_34 ;
if ( V_24 >= V_35 )
return - V_36 ;
F_18 ( V_2 -> V_37 -> V_38 . V_39 . V_40 ) ;
V_27 . V_20 = V_2 -> V_37 -> V_38 . V_39 . V_40 [ V_24 ] ;
if ( V_24 == 0 || V_27 . V_20 == 0 ) {
V_23 -> V_20 = V_2 -> V_3 . V_4 -> V_41 [ 1 ] ;
return 0 ;
} else if ( V_27 . V_20 == 1 ) {
V_23 -> V_20 = V_2 -> V_3 . V_4 -> V_41 [ 7 ] ;
return 0 ;
}
if ( V_27 . V_42 )
return V_43 ;
if ( V_27 . V_44 )
V_30 = V_2 -> V_3 . V_4 -> V_41 [ 5 ] ;
else
V_30 = V_2 -> V_3 . V_4 -> V_41 [ 2 ] ;
V_30 &= 0x7fffffc0 ;
V_7 = F_19 ( V_2 , V_30 + 16 , & V_32 . V_20 , sizeof( union V_32 ) ) ;
if ( V_7 )
return V_7 ;
if ( V_27 . V_45 / 8 > V_32 . V_46 )
return V_47 ;
if ( 0x7fffffff - V_32 . V_48 * 128 < V_27 . V_45 * 16 )
return V_49 ;
V_7 = F_19 ( V_2 , V_32 . V_48 * 128 + V_27 . V_45 * 16 , & V_28 ,
sizeof( struct V_28 ) ) ;
if ( V_7 )
return V_7 ;
if ( V_28 . V_50 == 1 )
return V_47 ;
if ( V_28 . V_51 != V_27 . V_51 )
return V_52 ;
V_7 = F_19 ( V_2 , V_28 . V_53 * 64 , & V_29 , sizeof( struct V_29 ) ) ;
if ( V_7 )
return V_7 ;
if ( V_29 . V_50 )
return V_54 ;
if ( V_29 . V_55 != V_28 . V_55 )
return V_56 ;
if ( V_28 . V_44 == 1 ) {
V_33 = ( V_2 -> V_3 . V_4 -> V_41 [ 8 ] >> 16 ) & 0xffff ;
if ( V_28 . V_57 != V_33 ) {
if ( V_33 / 16 > V_29 . V_58 )
return V_59 ;
V_31 = V_29 . V_60 * 4 + V_33 / 4 ;
V_7 = F_19 ( V_2 , V_31 ,
& V_34 ,
sizeof( T_1 ) ) ;
if ( V_7 )
return V_7 ;
if ( ( V_34 & ( 0x40 >> ( ( V_33 & 3 ) * 2 ) ) ) == 0 )
return V_59 ;
}
}
if ( V_28 . V_61 == 1 && V_26 == V_62 )
return V_63 ;
V_23 -> V_20 = V_29 . V_23 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_64 , unsigned long V_65 ,
T_1 V_24 , enum V_25 V_26 , enum V_66 V_67 )
{
struct V_68 * V_69 = & V_2 -> V_3 . V_69 ;
struct V_70 * V_71 ;
memset ( V_69 , 0 , sizeof( * V_69 ) ) ;
V_69 -> V_64 = V_64 ;
V_71 = (struct V_70 * ) & V_69 -> V_72 ;
switch ( V_64 ) {
case V_63 :
switch ( V_67 ) {
case V_73 :
V_71 -> V_74 = 1 ;
case V_75 :
V_71 -> V_76 = 1 ;
break;
case V_77 :
V_71 -> V_78 = 1 ;
break;
case V_79 :
V_71 -> V_78 = 1 ;
case V_80 :
V_71 -> V_74 = 1 ;
break;
}
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
V_71 -> V_87 = V_65 >> V_88 ;
V_71 -> V_89 = V_26 == V_62 ? V_90 : V_91 ;
V_71 -> V_92 = F_21 ( V_2 -> V_3 . V_4 -> V_93 ) . V_92 ;
case V_47 :
case V_52 :
case V_54 :
case V_56 :
case V_59 :
V_69 -> V_94 = V_24 ;
break;
}
return V_64 ;
}
static int F_22 ( struct V_1 * V_2 , union V_23 * V_23 ,
unsigned long V_95 , T_1 V_24 , enum V_25 V_26 )
{
int V_7 ;
struct F_21 V_96 = F_21 ( V_2 -> V_3 . V_4 -> V_93 ) ;
if ( ! V_96 . V_97 ) {
V_23 -> V_20 = 0 ;
V_23 -> V_98 = 1 ;
return 0 ;
}
if ( ( V_26 == V_99 ) && ( V_96 . V_92 != V_100 ) )
V_96 . V_92 = V_101 ;
switch ( V_96 . V_92 ) {
case V_101 :
V_23 -> V_20 = V_2 -> V_3 . V_4 -> V_41 [ 1 ] ;
return 0 ;
case V_102 :
V_23 -> V_20 = V_2 -> V_3 . V_4 -> V_41 [ 7 ] ;
return 0 ;
case V_100 :
V_23 -> V_20 = V_2 -> V_3 . V_4 -> V_41 [ 13 ] ;
return 0 ;
case V_103 :
V_7 = F_17 ( V_2 , V_23 , V_24 , V_26 ) ;
if ( V_7 > 0 )
return F_20 ( V_2 , V_7 , V_95 , V_24 , V_26 , V_79 ) ;
return V_7 ;
}
return 0 ;
}
static int F_23 ( struct V_8 * V_8 , unsigned long V_104 , unsigned long * V_20 )
{
return F_24 ( V_8 , V_104 , V_20 , sizeof( * V_20 ) ) ;
}
static unsigned long F_25 ( struct V_1 * V_2 , unsigned long V_65 ,
unsigned long * V_104 , const union V_23 V_23 ,
enum V_25 V_26 , enum V_66 * V_67 )
{
union V_105 V_106 = { . V_87 = V_65 } ;
union V_107 V_108 = { . V_87 = V_65 } ;
union V_109 V_110 ;
int V_111 = 0 ;
int V_112 = 0 ;
union V_113 V_113 ;
unsigned long V_114 ;
int V_115 , V_116 , V_117 ;
V_113 . V_20 = V_2 -> V_3 . V_4 -> V_41 [ 0 ] ;
V_115 = V_113 . V_118 && F_26 ( V_2 -> V_8 , 8 ) ;
V_116 = V_115 && F_26 ( V_2 -> V_8 , 78 ) ;
V_117 = V_113 . V_117 && F_26 ( V_2 -> V_8 , 130 ) ;
if ( V_23 . V_98 )
goto V_119;
V_114 = V_23 . V_120 * V_121 ;
switch ( V_23 . V_122 ) {
case V_123 :
if ( V_106 . V_124 > V_23 . V_125 )
return V_83 ;
V_114 += V_106 . V_126 * 8 ;
break;
case V_127 :
if ( V_106 . V_126 )
return V_81 ;
if ( V_106 . V_128 > V_23 . V_125 )
return V_84 ;
V_114 += V_106 . V_129 * 8 ;
break;
case V_130 :
if ( V_106 . V_126 || V_106 . V_129 )
return V_81 ;
if ( V_106 . V_131 > V_23 . V_125 )
return V_85 ;
V_114 += V_106 . V_132 * 8 ;
break;
case V_133 :
if ( V_106 . V_126 || V_106 . V_129 || V_106 . V_132 )
return V_81 ;
if ( V_106 . V_134 > V_23 . V_125 )
return V_86 ;
V_114 += V_106 . V_135 * 8 ;
break;
}
switch ( V_23 . V_122 ) {
case V_123 : {
union V_136 V_137 ;
if ( F_27 ( V_2 -> V_8 , V_114 ) )
return V_49 ;
if ( F_23 ( V_2 -> V_8 , V_114 , & V_137 . V_20 ) )
return - V_138 ;
if ( V_137 . V_50 )
return V_83 ;
if ( V_137 . V_139 != V_140 )
return V_141 ;
if ( V_106 . V_128 < V_137 . V_142 || V_106 . V_128 > V_137 . V_125 )
return V_84 ;
if ( V_115 )
V_111 |= V_137 . V_44 ;
V_114 = V_137 . V_143 * V_121 + V_106 . V_129 * 8 ;
}
case V_127 : {
union V_144 V_145 ;
if ( F_27 ( V_2 -> V_8 , V_114 ) )
return V_49 ;
if ( F_23 ( V_2 -> V_8 , V_114 , & V_145 . V_20 ) )
return - V_138 ;
if ( V_145 . V_50 )
return V_84 ;
if ( V_145 . V_139 != V_146 )
return V_141 ;
if ( V_106 . V_131 < V_145 . V_142 || V_106 . V_131 > V_145 . V_125 )
return V_85 ;
if ( V_115 )
V_111 |= V_145 . V_44 ;
V_114 = V_145 . V_143 * V_121 + V_106 . V_132 * 8 ;
}
case V_130 : {
union V_147 V_148 ;
if ( F_27 ( V_2 -> V_8 , V_114 ) )
return V_49 ;
if ( F_23 ( V_2 -> V_8 , V_114 , & V_148 . V_20 ) )
return - V_138 ;
if ( V_148 . V_50 )
return V_85 ;
if ( V_148 . V_139 != V_149 )
return V_141 ;
if ( V_148 . V_150 && V_23 . V_44 && V_116 )
return V_141 ;
if ( V_148 . V_151 && V_116 ) {
V_111 |= V_148 . V_152 . V_44 ;
V_112 = V_148 . V_152 . V_117 ;
V_108 . V_153 = V_148 . V_152 . V_153 ;
goto V_154;
}
if ( V_106 . V_134 < V_148 . V_155 . V_142 )
return V_86 ;
if ( V_106 . V_134 > V_148 . V_155 . V_125 )
return V_86 ;
if ( V_115 )
V_111 |= V_148 . V_155 . V_44 ;
V_114 = V_148 . V_155 . V_156 * V_121 + V_106 . V_135 * 8 ;
}
case V_133 : {
union V_157 V_158 ;
if ( F_27 ( V_2 -> V_8 , V_114 ) )
return V_49 ;
if ( F_23 ( V_2 -> V_8 , V_114 , & V_158 . V_20 ) )
return - V_138 ;
if ( V_158 . V_50 )
return V_86 ;
if ( V_158 . V_139 != V_159 )
return V_141 ;
if ( V_158 . V_160 && V_23 . V_44 )
return V_141 ;
if ( V_158 . V_151 && V_115 ) {
V_111 |= V_158 . V_152 . V_44 ;
V_112 = V_158 . V_152 . V_117 ;
V_108 . V_161 = V_158 . V_152 . V_161 ;
goto V_154;
}
V_111 |= V_158 . V_155 . V_44 ;
V_114 = V_158 . V_155 . V_162 * ( V_121 / 2 ) + V_106 . V_163 * 8 ;
}
}
if ( F_27 ( V_2 -> V_8 , V_114 ) )
return V_49 ;
if ( F_23 ( V_2 -> V_8 , V_114 , & V_110 . V_20 ) )
return - V_138 ;
if ( V_110 . V_50 )
return V_82 ;
if ( V_110 . V_164 )
return V_141 ;
V_111 |= V_110 . V_44 ;
V_112 = V_110 . V_117 ;
V_108 . V_165 = V_110 . V_165 ;
V_119:
V_108 . V_87 = F_28 ( V_2 , V_108 . V_87 ) ;
V_154:
if ( V_26 == V_62 && V_111 ) {
* V_67 = V_80 ;
return V_63 ;
}
if ( V_26 == V_99 && V_112 && V_117 ) {
* V_67 = V_73 ;
return V_63 ;
}
if ( F_27 ( V_2 -> V_8 , V_108 . V_87 ) )
return V_49 ;
* V_104 = V_108 . V_87 ;
return 0 ;
}
static inline int F_29 ( unsigned long V_95 )
{
return ( V_95 & ~ 0x11fful ) == 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
const union V_23 V_23 )
{
union V_113 V_113 = { . V_20 = V_2 -> V_3 . V_4 -> V_41 [ 0 ] } ;
T_2 * V_96 = & V_2 -> V_3 . V_4 -> V_93 ;
if ( ! V_113 . V_166 )
return 0 ;
if ( F_21 ( * V_96 ) . V_97 && V_23 . V_44 )
return 0 ;
return 1 ;
}
static int F_31 ( struct V_1 * V_2 , unsigned long V_95 , T_1 V_24 ,
unsigned long * V_167 , unsigned long V_168 ,
const union V_23 V_23 , enum V_25 V_26 )
{
T_2 * V_96 = & V_2 -> V_3 . V_4 -> V_93 ;
int V_169 , V_7 = 0 ;
enum V_66 V_67 ;
V_169 = F_30 ( V_2 , V_23 ) ;
while ( V_168 ) {
V_95 = F_32 ( V_2 , V_95 ) ;
if ( V_26 == V_62 && V_169 && F_29 ( V_95 ) )
return F_20 ( V_2 , V_63 , V_95 , V_24 , V_26 ,
V_75 ) ;
V_95 &= V_170 ;
if ( F_21 ( * V_96 ) . V_97 ) {
V_7 = F_25 ( V_2 , V_95 , V_167 , V_23 , V_26 , & V_67 ) ;
if ( V_7 < 0 )
return V_7 ;
} else {
* V_167 = F_28 ( V_2 , V_95 ) ;
if ( F_27 ( V_2 -> V_8 , * V_167 ) )
V_7 = V_49 ;
}
if ( V_7 )
return F_20 ( V_2 , V_7 , V_95 , V_24 , V_26 , V_67 ) ;
V_95 += V_121 ;
V_167 ++ ;
V_168 -- ;
}
return 0 ;
}
int F_33 ( struct V_1 * V_2 , unsigned long V_95 , T_1 V_24 , void * V_171 ,
unsigned long V_172 , enum V_25 V_26 )
{
T_2 * V_96 = & V_2 -> V_3 . V_4 -> V_93 ;
unsigned long V_173 , V_168 , V_104 , V_174 ;
unsigned long V_175 [ 2 ] ;
unsigned long * V_167 ;
int V_176 ;
union V_23 V_23 ;
int V_7 ;
if ( ! V_172 )
return 0 ;
V_95 = F_32 ( V_2 , V_95 ) ;
V_7 = F_22 ( V_2 , & V_23 , V_95 , V_24 , V_26 ) ;
if ( V_7 )
return V_7 ;
V_168 = ( ( ( V_95 & ~ V_170 ) + V_172 - 1 ) >> V_88 ) + 1 ;
V_167 = V_175 ;
if ( V_168 > F_34 ( V_175 ) )
V_167 = F_35 ( V_168 * sizeof( unsigned long ) ) ;
if ( ! V_167 )
return - V_177 ;
V_176 = F_21 ( * V_96 ) . V_97 && ! V_23 . V_98 ;
if ( V_176 )
F_15 ( V_2 ) ;
V_7 = F_31 ( V_2 , V_95 , V_24 , V_167 , V_168 , V_23 , V_26 ) ;
for ( V_174 = 0 ; V_174 < V_168 && ! V_7 ; V_174 ++ ) {
V_104 = * ( V_167 + V_174 ) + ( V_95 & ~ V_170 ) ;
V_173 = F_36 ( V_121 - ( V_104 & ~ V_170 ) , V_172 ) ;
if ( V_26 == V_62 )
V_7 = F_37 ( V_2 -> V_8 , V_104 , V_171 , V_173 ) ;
else
V_7 = F_24 ( V_2 -> V_8 , V_104 , V_171 , V_173 ) ;
V_172 -= V_173 ;
V_95 += V_173 ;
V_171 += V_173 ;
}
if ( V_176 )
F_16 ( V_2 ) ;
if ( V_168 > F_34 ( V_175 ) )
F_38 ( V_167 ) ;
return V_7 ;
}
int F_39 ( struct V_1 * V_2 , unsigned long V_178 ,
void * V_171 , unsigned long V_172 , enum V_25 V_26 )
{
unsigned long V_173 , V_104 ;
int V_7 = 0 ;
while ( V_172 && ! V_7 ) {
V_104 = F_28 ( V_2 , V_178 ) ;
V_173 = F_36 ( V_121 - ( V_104 & ~ V_170 ) , V_172 ) ;
if ( V_26 )
V_7 = F_40 ( V_2 , V_104 , V_171 , V_173 ) ;
else
V_7 = F_41 ( V_2 , V_104 , V_171 , V_173 ) ;
V_172 -= V_173 ;
V_178 += V_173 ;
V_171 += V_173 ;
}
return V_7 ;
}
int F_42 ( struct V_1 * V_2 , unsigned long V_65 , T_1 V_24 ,
unsigned long * V_104 , enum V_25 V_26 )
{
T_2 * V_96 = & V_2 -> V_3 . V_4 -> V_93 ;
enum V_66 V_67 ;
union V_23 V_23 ;
int V_7 ;
V_65 = F_32 ( V_2 , V_65 ) ;
V_7 = F_22 ( V_2 , & V_23 , V_65 , V_24 , V_26 ) ;
if ( V_7 )
return V_7 ;
if ( F_29 ( V_65 ) && F_30 ( V_2 , V_23 ) ) {
if ( V_26 == V_62 )
return F_20 ( V_2 , V_63 , V_65 , 0 ,
V_26 , V_75 ) ;
}
if ( F_21 ( * V_96 ) . V_97 && ! V_23 . V_98 ) {
V_7 = F_25 ( V_2 , V_65 , V_104 , V_23 , V_26 , & V_67 ) ;
if ( V_7 > 0 )
return F_20 ( V_2 , V_7 , V_65 , 0 , V_26 , V_67 ) ;
} else {
* V_104 = F_28 ( V_2 , V_65 ) ;
if ( F_27 ( V_2 -> V_8 , * V_104 ) )
return F_20 ( V_2 , V_7 , V_65 , V_49 , V_26 , 0 ) ;
}
return V_7 ;
}
int F_43 ( struct V_1 * V_2 , unsigned long V_65 , T_1 V_24 ,
unsigned long V_179 , enum V_25 V_26 )
{
unsigned long V_104 ;
unsigned long V_180 ;
int V_7 = 0 ;
F_15 ( V_2 ) ;
while ( V_179 > 0 && ! V_7 ) {
V_180 = F_36 ( V_179 , V_121 - ( V_65 % V_121 ) ) ;
V_7 = F_42 ( V_2 , V_65 , V_24 , & V_104 , V_26 ) ;
V_65 += V_180 ;
V_179 -= V_180 ;
}
F_16 ( V_2 ) ;
return V_7 ;
}
int F_44 ( struct V_1 * V_2 , unsigned long V_178 )
{
union V_113 V_113 = { . V_20 = V_2 -> V_3 . V_4 -> V_41 [ 0 ] } ;
if ( ! V_113 . V_166 || ! F_29 ( V_178 ) )
return 0 ;
return F_20 ( V_2 , V_63 , V_178 , 0 , V_62 , V_75 ) ;
}
static int F_45 ( struct V_181 * V_182 , unsigned long V_183 ,
unsigned long * V_184 , int * V_111 ,
int * V_185 )
{
struct V_181 * V_186 ;
union V_23 V_23 ;
union V_105 V_106 ;
unsigned long V_114 ;
int V_7 ;
* V_185 = 0 ;
* V_111 = 0 ;
V_186 = V_182 -> V_186 ;
V_106 . V_87 = V_183 ;
V_23 . V_20 = V_182 -> V_187 ;
V_114 = V_23 . V_120 * V_121 ;
if ( V_23 . V_98 ) {
* V_185 = 1 ;
V_114 = 0 ;
V_23 . V_122 = V_123 ;
}
switch ( V_23 . V_122 ) {
case V_123 :
if ( V_106 . V_124 > V_23 . V_125 && ! * V_185 )
return V_83 ;
break;
case V_127 :
if ( V_106 . V_126 )
return V_81 ;
if ( V_106 . V_128 > V_23 . V_125 )
return V_84 ;
break;
case V_130 :
if ( V_106 . V_126 || V_106 . V_129 )
return V_81 ;
if ( V_106 . V_131 > V_23 . V_125 )
return V_85 ;
break;
case V_133 :
if ( V_106 . V_126 || V_106 . V_129 || V_106 . V_132 )
return V_81 ;
if ( V_106 . V_134 > V_23 . V_125 )
return V_86 ;
break;
}
switch ( V_23 . V_122 ) {
case V_123 : {
union V_136 V_137 ;
if ( * V_185 ) {
V_114 += V_106 . V_126 * V_188 ;
V_137 . V_20 = V_114 ;
goto V_189;
}
V_7 = F_46 ( V_186 , V_114 + V_106 . V_126 * 8 , & V_137 . V_20 ) ;
if ( V_7 )
return V_7 ;
if ( V_137 . V_50 )
return V_83 ;
if ( V_137 . V_139 != V_140 )
return V_141 ;
if ( V_106 . V_128 < V_137 . V_142 || V_106 . V_128 > V_137 . V_125 )
return V_84 ;
if ( V_182 -> V_190 >= 1 )
* V_111 |= V_137 . V_44 ;
V_114 = V_137 . V_143 * V_121 ;
V_189:
V_7 = F_47 ( V_182 , V_183 , V_137 . V_20 , * V_185 ) ;
if ( V_7 )
return V_7 ;
}
case V_127 : {
union V_144 V_145 ;
if ( * V_185 ) {
V_114 += V_106 . V_129 * V_191 ;
V_145 . V_20 = V_114 ;
goto V_192;
}
V_7 = F_46 ( V_186 , V_114 + V_106 . V_129 * 8 , & V_145 . V_20 ) ;
if ( V_7 )
return V_7 ;
if ( V_145 . V_50 )
return V_84 ;
if ( V_145 . V_139 != V_146 )
return V_141 ;
if ( V_106 . V_131 < V_145 . V_142 || V_106 . V_131 > V_145 . V_125 )
return V_85 ;
if ( V_182 -> V_190 >= 1 )
* V_111 |= V_145 . V_44 ;
V_114 = V_145 . V_143 * V_121 ;
V_192:
V_145 . V_44 |= * V_111 ;
V_7 = F_48 ( V_182 , V_183 , V_145 . V_20 , * V_185 ) ;
if ( V_7 )
return V_7 ;
}
case V_130 : {
union V_147 V_148 ;
if ( * V_185 ) {
V_114 += V_106 . V_132 * V_193 ;
V_148 . V_20 = V_114 ;
goto V_194;
}
V_7 = F_46 ( V_186 , V_114 + V_106 . V_132 * 8 , & V_148 . V_20 ) ;
if ( V_7 )
return V_7 ;
if ( V_148 . V_50 )
return V_85 ;
if ( V_148 . V_139 != V_149 )
return V_141 ;
if ( V_148 . V_150 && V_23 . V_44 && V_182 -> V_190 >= 2 )
return V_141 ;
if ( V_148 . V_151 && V_182 -> V_190 >= 2 ) {
* V_111 |= V_148 . V_155 . V_44 ;
* V_185 = 1 ;
V_114 = V_148 . V_152 . V_153 * V_193 ;
V_148 . V_20 = V_114 ;
goto V_194;
}
if ( V_106 . V_134 < V_148 . V_155 . V_142 || V_106 . V_134 > V_148 . V_155 . V_125 )
return V_86 ;
if ( V_182 -> V_190 >= 1 )
* V_111 |= V_148 . V_155 . V_44 ;
V_114 = V_148 . V_155 . V_156 * V_121 ;
V_194:
V_148 . V_155 . V_44 |= * V_111 ;
V_7 = F_49 ( V_182 , V_183 , V_148 . V_20 , * V_185 ) ;
if ( V_7 )
return V_7 ;
}
case V_133 : {
union V_157 V_158 ;
if ( * V_185 ) {
V_114 += V_106 . V_135 * V_195 ;
V_158 . V_20 = V_114 ;
goto V_196;
}
V_7 = F_46 ( V_186 , V_114 + V_106 . V_135 * 8 , & V_158 . V_20 ) ;
if ( V_7 )
return V_7 ;
if ( V_158 . V_50 )
return V_86 ;
if ( V_158 . V_139 != V_159 )
return V_141 ;
if ( V_158 . V_160 && V_23 . V_44 )
return V_141 ;
* V_111 |= V_158 . V_155 . V_44 ;
if ( V_158 . V_151 && V_182 -> V_190 >= 1 ) {
* V_185 = 1 ;
V_114 = V_158 . V_152 . V_161 * V_195 ;
V_158 . V_20 = V_114 ;
goto V_196;
}
V_114 = V_158 . V_155 . V_162 * ( V_121 / 2 ) ;
V_196:
V_158 . V_155 . V_44 |= * V_111 ;
V_7 = F_50 ( V_182 , V_183 , V_158 . V_20 , * V_185 ) ;
if ( V_7 )
return V_7 ;
}
}
* V_184 = V_114 ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 , struct V_181 * V_182 ,
unsigned long V_183 )
{
union V_105 V_106 ;
union V_109 V_110 ;
unsigned long V_184 ;
int V_111 , V_185 ;
int V_7 ;
F_52 ( & V_182 -> V_197 -> V_198 ) ;
F_15 ( V_2 ) ;
V_7 = F_53 ( V_182 , V_183 , & V_184 , & V_111 , & V_185 ) ;
if ( V_7 )
V_7 = F_45 ( V_182 , V_183 , & V_184 , & V_111 ,
& V_185 ) ;
V_106 . V_87 = V_183 ;
if ( V_185 ) {
V_110 . V_20 = V_184 + V_106 . V_163 * V_121 ;
goto V_199;
}
if ( ! V_7 )
V_7 = F_46 ( V_182 -> V_186 , V_184 + V_106 . V_163 * 8 , & V_110 . V_20 ) ;
if ( ! V_7 && V_110 . V_50 )
V_7 = V_82 ;
if ( ! V_7 && V_110 . V_164 )
V_7 = V_141 ;
V_199:
V_110 . V_44 |= V_111 ;
if ( ! V_7 )
V_7 = F_54 ( V_182 , V_183 , F_55 ( V_110 . V_20 ) ) ;
F_16 ( V_2 ) ;
F_56 ( & V_182 -> V_197 -> V_198 ) ;
return V_7 ;
}
