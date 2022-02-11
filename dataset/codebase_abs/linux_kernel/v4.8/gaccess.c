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
T_2 V_33 ;
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
sizeof( T_2 ) ) ;
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
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
V_70 -> V_78 = V_64 >> V_79 ;
V_70 -> V_80 = V_25 == V_61 ? V_81 : V_82 ;
V_70 -> V_83 = F_21 ( V_2 -> V_3 . V_4 -> V_84 ) . V_83 ;
case V_46 :
case V_51 :
case V_53 :
case V_55 :
case V_58 :
V_68 -> V_85 = V_23 ;
break;
case V_62 :
switch ( V_66 ) {
case V_86 :
V_70 -> V_87 = 1 ;
case V_88 :
V_70 -> V_89 = 1 ;
V_70 -> V_78 = V_64 >> V_79 ;
V_70 -> V_80 = V_25 == V_61 ? V_81 : V_82 ;
V_70 -> V_83 = F_21 ( V_2 -> V_3 . V_4 -> V_84 ) . V_83 ;
V_68 -> V_85 = V_23 ;
break;
default:
break;
}
break;
}
return V_63 ;
}
static int F_22 ( struct V_1 * V_2 , union V_22 * V_22 ,
unsigned long V_90 , T_1 V_23 , enum V_24 V_25 )
{
int V_6 ;
struct F_21 V_91 = F_21 ( V_2 -> V_3 . V_4 -> V_84 ) ;
if ( ! V_91 . V_92 ) {
V_22 -> V_19 = 0 ;
V_22 -> V_93 = 1 ;
return 0 ;
}
if ( V_25 == V_94 )
V_91 . V_83 = V_91 . V_83 == V_95 ? V_95 : V_96 ;
switch ( V_91 . V_83 ) {
case V_96 :
V_22 -> V_19 = V_2 -> V_3 . V_4 -> V_40 [ 1 ] ;
return 0 ;
case V_97 :
V_22 -> V_19 = V_2 -> V_3 . V_4 -> V_40 [ 7 ] ;
return 0 ;
case V_95 :
V_22 -> V_19 = V_2 -> V_3 . V_4 -> V_40 [ 13 ] ;
return 0 ;
case V_98 :
V_6 = F_17 ( V_2 , V_22 , V_23 , V_25 ) ;
if ( V_6 > 0 )
return F_20 ( V_2 , V_6 , V_90 , V_23 , V_25 , V_86 ) ;
return V_6 ;
}
return 0 ;
}
static int F_23 ( struct V_7 * V_7 , unsigned long V_99 , unsigned long * V_19 )
{
return F_24 ( V_7 , V_99 , V_19 , sizeof( * V_19 ) ) ;
}
static unsigned long F_25 ( struct V_1 * V_2 , unsigned long V_64 ,
unsigned long * V_99 , const union V_22 V_22 ,
enum V_24 V_25 )
{
union V_100 V_101 = { . V_78 = V_64 } ;
union V_102 V_103 = { . V_78 = V_64 } ;
union V_104 V_105 ;
int V_106 = 0 ;
union V_107 V_107 ;
unsigned long V_108 ;
int V_109 , V_110 ;
V_107 . V_19 = V_2 -> V_3 . V_4 -> V_40 [ 0 ] ;
V_109 = V_107 . V_111 && F_26 ( V_2 -> V_7 , 8 ) ;
V_110 = V_109 && F_26 ( V_2 -> V_7 , 78 ) ;
if ( V_22 . V_93 )
goto V_112;
V_108 = V_22 . V_113 * 4096 ;
switch ( V_22 . V_114 ) {
case V_115 :
if ( V_101 . V_116 > V_22 . V_117 )
return V_74 ;
V_108 += V_101 . V_118 * 8 ;
break;
case V_119 :
if ( V_101 . V_118 )
return V_72 ;
if ( V_101 . V_120 > V_22 . V_117 )
return V_75 ;
V_108 += V_101 . V_121 * 8 ;
break;
case V_122 :
if ( V_101 . V_118 || V_101 . V_121 )
return V_72 ;
if ( V_101 . V_123 > V_22 . V_117 )
return V_76 ;
V_108 += V_101 . V_124 * 8 ;
break;
case V_125 :
if ( V_101 . V_118 || V_101 . V_121 || V_101 . V_124 )
return V_72 ;
if ( V_101 . V_126 > V_22 . V_117 )
return V_77 ;
V_108 += V_101 . V_127 * 8 ;
break;
}
switch ( V_22 . V_114 ) {
case V_115 : {
union V_128 V_129 ;
if ( F_27 ( V_2 -> V_7 , V_108 ) )
return V_48 ;
if ( F_23 ( V_2 -> V_7 , V_108 , & V_129 . V_19 ) )
return - V_130 ;
if ( V_129 . V_49 )
return V_74 ;
if ( V_129 . V_131 != V_132 )
return V_133 ;
if ( V_101 . V_120 < V_129 . V_134 || V_101 . V_120 > V_129 . V_117 )
return V_75 ;
if ( V_109 )
V_106 |= V_129 . V_43 ;
V_108 = V_129 . V_135 * 4096 + V_101 . V_121 * 8 ;
}
case V_119 : {
union V_136 V_137 ;
if ( F_27 ( V_2 -> V_7 , V_108 ) )
return V_48 ;
if ( F_23 ( V_2 -> V_7 , V_108 , & V_137 . V_19 ) )
return - V_130 ;
if ( V_137 . V_49 )
return V_75 ;
if ( V_137 . V_131 != V_138 )
return V_133 ;
if ( V_101 . V_123 < V_137 . V_134 || V_101 . V_123 > V_137 . V_117 )
return V_76 ;
if ( V_109 )
V_106 |= V_137 . V_43 ;
V_108 = V_137 . V_135 * 4096 + V_101 . V_124 * 8 ;
}
case V_122 : {
union V_139 V_140 ;
if ( F_27 ( V_2 -> V_7 , V_108 ) )
return V_48 ;
if ( F_23 ( V_2 -> V_7 , V_108 , & V_140 . V_19 ) )
return - V_130 ;
if ( V_140 . V_49 )
return V_76 ;
if ( V_140 . V_131 != V_141 )
return V_133 ;
if ( V_140 . V_142 && V_22 . V_43 && V_110 )
return V_133 ;
if ( V_140 . V_143 && V_110 ) {
V_106 |= V_140 . V_144 . V_43 ;
V_103 . V_145 = V_140 . V_144 . V_145 ;
goto V_146;
}
if ( V_101 . V_126 < V_140 . V_147 . V_134 )
return V_77 ;
if ( V_101 . V_126 > V_140 . V_147 . V_117 )
return V_77 ;
if ( V_109 )
V_106 |= V_140 . V_147 . V_43 ;
V_108 = V_140 . V_147 . V_148 * 4096 + V_101 . V_127 * 8 ;
}
case V_125 : {
union V_149 V_150 ;
if ( F_27 ( V_2 -> V_7 , V_108 ) )
return V_48 ;
if ( F_23 ( V_2 -> V_7 , V_108 , & V_150 . V_19 ) )
return - V_130 ;
if ( V_150 . V_49 )
return V_77 ;
if ( V_150 . V_131 != V_151 )
return V_133 ;
if ( V_150 . V_152 && V_22 . V_43 )
return V_133 ;
if ( V_150 . V_143 && V_109 ) {
V_106 |= V_150 . V_144 . V_43 ;
V_103 . V_153 = V_150 . V_144 . V_153 ;
goto V_146;
}
V_106 |= V_150 . V_147 . V_43 ;
V_108 = V_150 . V_147 . V_154 * 2048 + V_101 . V_155 * 8 ;
}
}
if ( F_27 ( V_2 -> V_7 , V_108 ) )
return V_48 ;
if ( F_23 ( V_2 -> V_7 , V_108 , & V_105 . V_19 ) )
return - V_130 ;
if ( V_105 . V_49 )
return V_73 ;
if ( V_105 . V_156 )
return V_133 ;
if ( V_105 . V_157 && ! V_109 )
return V_133 ;
V_106 |= V_105 . V_43 ;
V_103 . V_158 = V_105 . V_158 ;
V_112:
V_103 . V_78 = F_28 ( V_2 , V_103 . V_78 ) ;
V_146:
if ( V_25 == V_61 && V_106 )
return V_62 ;
if ( F_27 ( V_2 -> V_7 , V_103 . V_78 ) )
return V_48 ;
* V_99 = V_103 . V_78 ;
return 0 ;
}
static inline int F_29 ( unsigned long V_90 )
{
return ( V_90 & ~ 0x11fful ) == 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
const union V_22 V_22 )
{
union V_107 V_107 = { . V_19 = V_2 -> V_3 . V_4 -> V_40 [ 0 ] } ;
T_3 * V_91 = & V_2 -> V_3 . V_4 -> V_84 ;
if ( ! V_107 . V_159 )
return 0 ;
if ( F_21 ( * V_91 ) . V_92 && V_22 . V_43 )
return 0 ;
return 1 ;
}
static int F_31 ( struct V_1 * V_2 , unsigned long V_90 , T_1 V_23 ,
unsigned long * V_160 , unsigned long V_161 ,
const union V_22 V_22 , enum V_24 V_25 )
{
T_3 * V_91 = & V_2 -> V_3 . V_4 -> V_84 ;
int V_162 , V_6 = 0 ;
V_162 = F_30 ( V_2 , V_22 ) ;
while ( V_161 ) {
V_90 = F_32 ( V_2 , V_90 ) ;
if ( V_25 == V_61 && V_162 && F_29 ( V_90 ) )
return F_20 ( V_2 , V_62 , V_90 , V_23 , V_25 ,
V_163 ) ;
V_90 &= V_164 ;
if ( F_21 ( * V_91 ) . V_92 ) {
V_6 = F_25 ( V_2 , V_90 , V_160 , V_22 , V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
} else {
* V_160 = F_28 ( V_2 , V_90 ) ;
if ( F_27 ( V_2 -> V_7 , * V_160 ) )
V_6 = V_48 ;
}
if ( V_6 )
return F_20 ( V_2 , V_6 , V_90 , V_23 , V_25 , V_88 ) ;
V_90 += V_165 ;
V_160 ++ ;
V_161 -- ;
}
return 0 ;
}
int F_33 ( struct V_1 * V_2 , unsigned long V_90 , T_1 V_23 , void * V_166 ,
unsigned long V_167 , enum V_24 V_25 )
{
T_3 * V_91 = & V_2 -> V_3 . V_4 -> V_84 ;
unsigned long V_168 , V_161 , V_99 , V_169 ;
unsigned long V_170 [ 2 ] ;
unsigned long * V_160 ;
int V_171 ;
union V_22 V_22 ;
int V_6 ;
if ( ! V_167 )
return 0 ;
V_90 = F_32 ( V_2 , V_90 ) ;
V_6 = F_22 ( V_2 , & V_22 , V_90 , V_23 , V_25 ) ;
if ( V_6 )
return V_6 ;
V_161 = ( ( ( V_90 & ~ V_164 ) + V_167 - 1 ) >> V_79 ) + 1 ;
V_160 = V_170 ;
if ( V_161 > F_34 ( V_170 ) )
V_160 = F_35 ( V_161 * sizeof( unsigned long ) ) ;
if ( ! V_160 )
return - V_172 ;
V_171 = F_21 ( * V_91 ) . V_92 && ! V_22 . V_93 ;
if ( V_171 )
F_15 ( V_2 ) ;
V_6 = F_31 ( V_2 , V_90 , V_23 , V_160 , V_161 , V_22 , V_25 ) ;
for ( V_169 = 0 ; V_169 < V_161 && ! V_6 ; V_169 ++ ) {
V_99 = * ( V_160 + V_169 ) + ( V_90 & ~ V_164 ) ;
V_168 = F_36 ( V_165 - ( V_99 & ~ V_164 ) , V_167 ) ;
if ( V_25 == V_61 )
V_6 = F_37 ( V_2 -> V_7 , V_99 , V_166 , V_168 ) ;
else
V_6 = F_24 ( V_2 -> V_7 , V_99 , V_166 , V_168 ) ;
V_167 -= V_168 ;
V_90 += V_168 ;
V_166 += V_168 ;
}
if ( V_171 )
F_16 ( V_2 ) ;
if ( V_161 > F_34 ( V_170 ) )
F_38 ( V_160 ) ;
return V_6 ;
}
int F_39 ( struct V_1 * V_2 , unsigned long V_173 ,
void * V_166 , unsigned long V_167 , enum V_24 V_25 )
{
unsigned long V_168 , V_99 ;
int V_6 = 0 ;
while ( V_167 && ! V_6 ) {
V_99 = F_28 ( V_2 , V_173 ) ;
V_168 = F_36 ( V_165 - ( V_99 & ~ V_164 ) , V_167 ) ;
if ( V_25 )
V_6 = F_40 ( V_2 , V_99 , V_166 , V_168 ) ;
else
V_6 = F_41 ( V_2 , V_99 , V_166 , V_168 ) ;
V_167 -= V_168 ;
V_173 += V_168 ;
V_166 += V_168 ;
}
return V_6 ;
}
int F_42 ( struct V_1 * V_2 , unsigned long V_64 , T_1 V_23 ,
unsigned long * V_99 , enum V_24 V_25 )
{
T_3 * V_91 = & V_2 -> V_3 . V_4 -> V_84 ;
union V_22 V_22 ;
int V_6 ;
V_64 = F_32 ( V_2 , V_64 ) ;
V_6 = F_22 ( V_2 , & V_22 , V_64 , V_23 , V_25 ) ;
if ( V_6 )
return V_6 ;
if ( F_29 ( V_64 ) && F_30 ( V_2 , V_22 ) ) {
if ( V_25 == V_61 )
return F_20 ( V_2 , V_62 , V_64 , 0 ,
V_25 , V_163 ) ;
}
if ( F_21 ( * V_91 ) . V_92 && ! V_22 . V_93 ) {
V_6 = F_25 ( V_2 , V_64 , V_99 , V_22 , V_25 ) ;
if ( V_6 > 0 )
return F_20 ( V_2 , V_6 , V_64 , 0 , V_25 , V_88 ) ;
} else {
* V_99 = F_28 ( V_2 , V_64 ) ;
if ( F_27 ( V_2 -> V_7 , * V_99 ) )
return F_20 ( V_2 , V_6 , V_64 , V_48 , V_25 , 0 ) ;
}
return V_6 ;
}
int F_43 ( struct V_1 * V_2 , unsigned long V_64 , T_1 V_23 ,
unsigned long V_174 , enum V_24 V_25 )
{
unsigned long V_99 ;
unsigned long V_175 ;
int V_6 = 0 ;
F_15 ( V_2 ) ;
while ( V_174 > 0 && ! V_6 ) {
V_175 = F_36 ( V_174 , V_165 - ( V_64 % V_165 ) ) ;
V_6 = F_42 ( V_2 , V_64 , V_23 , & V_99 , V_25 ) ;
V_64 += V_175 ;
V_174 -= V_175 ;
}
F_16 ( V_2 ) ;
return V_6 ;
}
int F_44 ( struct V_1 * V_2 , unsigned long V_173 )
{
union V_107 V_107 = { . V_19 = V_2 -> V_3 . V_4 -> V_40 [ 0 ] } ;
if ( ! V_107 . V_159 || ! F_29 ( V_173 ) )
return 0 ;
return F_20 ( V_2 , V_62 , V_173 , 0 , V_61 , V_163 ) ;
}
static int F_45 ( struct V_176 * V_177 , unsigned long V_178 ,
unsigned long * V_179 , int * V_106 ,
int * V_180 )
{
struct V_176 * V_181 ;
union V_22 V_22 ;
union V_100 V_101 ;
unsigned long V_108 ;
int V_6 ;
* V_180 = 0 ;
* V_106 = 0 ;
V_181 = V_177 -> V_181 ;
V_101 . V_78 = V_178 ;
V_22 . V_19 = V_177 -> V_182 ;
V_108 = V_22 . V_113 * 4096 ;
if ( V_22 . V_93 ) {
* V_180 = 1 ;
V_22 . V_114 = V_115 ;
}
switch ( V_22 . V_114 ) {
case V_115 :
if ( V_101 . V_116 > V_22 . V_117 && ! V_22 . V_93 )
return V_74 ;
break;
case V_119 :
if ( V_101 . V_118 )
return V_72 ;
if ( V_101 . V_120 > V_22 . V_117 )
return V_75 ;
break;
case V_122 :
if ( V_101 . V_118 || V_101 . V_121 )
return V_72 ;
if ( V_101 . V_123 > V_22 . V_117 )
return V_76 ;
break;
case V_125 :
if ( V_101 . V_118 || V_101 . V_121 || V_101 . V_124 )
return V_72 ;
if ( V_101 . V_126 > V_22 . V_117 )
return V_77 ;
break;
}
switch ( V_22 . V_114 ) {
case V_115 : {
union V_128 V_129 ;
if ( * V_180 ) {
V_108 = V_108 + ( ( unsigned long ) V_101 . V_121 << 53UL ) ;
V_129 . V_19 = V_108 ;
goto V_183;
}
V_6 = F_46 ( V_181 , V_108 + V_101 . V_118 * 8 , & V_129 . V_19 ) ;
if ( V_6 )
return V_6 ;
if ( V_129 . V_49 )
return V_74 ;
if ( V_129 . V_131 != V_132 )
return V_133 ;
if ( V_101 . V_120 < V_129 . V_134 || V_101 . V_120 > V_129 . V_117 )
return V_75 ;
if ( V_177 -> V_184 >= 1 )
* V_106 |= V_129 . V_43 ;
V_108 = V_129 . V_135 << 12UL ;
V_183:
V_6 = F_47 ( V_177 , V_178 , V_129 . V_19 , * V_180 ) ;
if ( V_6 )
return V_6 ;
}
case V_119 : {
union V_136 V_137 ;
if ( * V_180 ) {
V_108 = V_108 + ( ( unsigned long ) V_101 . V_124 << 42UL ) ;
V_137 . V_19 = V_108 ;
goto V_185;
}
V_6 = F_46 ( V_181 , V_108 + V_101 . V_121 * 8 , & V_137 . V_19 ) ;
if ( V_6 )
return V_6 ;
if ( V_137 . V_49 )
return V_75 ;
if ( V_137 . V_131 != V_138 )
return V_133 ;
if ( V_101 . V_123 < V_137 . V_134 || V_101 . V_123 > V_137 . V_117 )
return V_76 ;
if ( V_177 -> V_184 >= 1 )
* V_106 |= V_137 . V_43 ;
V_108 = V_137 . V_135 << 12UL ;
V_185:
V_137 . V_43 |= * V_106 ;
V_6 = F_48 ( V_177 , V_178 , V_137 . V_19 , * V_180 ) ;
if ( V_6 )
return V_6 ;
}
case V_122 : {
union V_139 V_140 ;
if ( * V_180 ) {
V_108 = V_108 + ( ( unsigned long ) V_101 . V_127 << 31UL ) ;
V_140 . V_19 = V_108 ;
goto V_186;
}
V_6 = F_46 ( V_181 , V_108 + V_101 . V_124 * 8 , & V_140 . V_19 ) ;
if ( V_6 )
return V_6 ;
if ( V_140 . V_49 )
return V_76 ;
if ( V_140 . V_131 != V_141 )
return V_133 ;
if ( V_140 . V_142 && V_22 . V_43 && V_177 -> V_184 >= 2 )
return V_133 ;
if ( V_140 . V_143 && V_177 -> V_184 >= 2 ) {
* V_106 |= V_140 . V_147 . V_43 ;
* V_180 = 1 ;
V_108 = V_140 . V_144 . V_145 << 31UL ;
V_140 . V_19 = V_108 ;
goto V_186;
}
if ( V_101 . V_126 < V_140 . V_147 . V_134 || V_101 . V_126 > V_140 . V_147 . V_117 )
return V_77 ;
if ( V_177 -> V_184 >= 1 )
* V_106 |= V_140 . V_147 . V_43 ;
V_108 = V_140 . V_147 . V_148 << 12UL ;
V_186:
V_140 . V_147 . V_43 |= * V_106 ;
V_6 = F_49 ( V_177 , V_178 , V_140 . V_19 , * V_180 ) ;
if ( V_6 )
return V_6 ;
}
case V_125 : {
union V_149 V_150 ;
if ( * V_180 ) {
V_108 = V_108 + ( ( unsigned long ) V_101 . V_127 << 20UL ) ;
V_150 . V_19 = V_108 ;
goto V_187;
}
V_6 = F_46 ( V_181 , V_108 + V_101 . V_127 * 8 , & V_150 . V_19 ) ;
if ( V_6 )
return V_6 ;
if ( V_150 . V_49 )
return V_77 ;
if ( V_150 . V_131 != V_151 )
return V_133 ;
if ( V_150 . V_152 && V_22 . V_43 )
return V_133 ;
* V_106 |= V_150 . V_147 . V_43 ;
if ( V_150 . V_143 && V_177 -> V_184 >= 1 ) {
* V_180 = 1 ;
V_108 = V_150 . V_144 . V_153 << 20UL ;
V_150 . V_19 = V_108 ;
goto V_187;
}
V_108 = V_150 . V_147 . V_154 << 11UL ;
V_187:
V_150 . V_147 . V_43 |= * V_106 ;
V_6 = F_50 ( V_177 , V_178 , V_150 . V_19 , * V_180 ) ;
if ( V_6 )
return V_6 ;
}
}
* V_179 = V_108 ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 , struct V_176 * V_177 ,
unsigned long V_178 )
{
union V_100 V_101 ;
union V_104 V_105 ;
unsigned long V_179 ;
int V_106 , V_180 ;
int V_6 ;
F_52 ( & V_177 -> V_188 -> V_189 ) ;
F_15 ( V_2 ) ;
V_6 = F_53 ( V_177 , V_178 , & V_179 , & V_106 , & V_180 ) ;
if ( V_6 )
V_6 = F_45 ( V_177 , V_178 , & V_179 , & V_106 ,
& V_180 ) ;
V_101 . V_78 = V_178 ;
if ( V_180 ) {
V_105 . V_19 = V_179 + ( ( unsigned long ) V_101 . V_155 << 12UL ) ;
goto V_190;
}
if ( ! V_6 )
V_6 = F_46 ( V_177 -> V_181 , V_179 + V_101 . V_155 * 8 , & V_105 . V_19 ) ;
if ( ! V_6 && V_105 . V_49 )
V_6 = V_73 ;
if ( ! V_6 && ( V_105 . V_156 || ( V_105 . V_157 && V_177 -> V_184 < 1 ) ) )
V_6 = V_133 ;
V_190:
V_105 . V_43 |= V_106 ;
if ( ! V_6 )
V_6 = F_54 ( V_177 , V_178 , F_55 ( V_105 . V_19 ) ) ;
F_16 ( V_2 ) ;
F_56 ( & V_177 -> V_188 -> V_189 ) ;
return V_6 ;
}
