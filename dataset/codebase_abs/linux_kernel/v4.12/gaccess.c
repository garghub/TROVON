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
break;
case V_75 :
V_71 -> V_76 = 1 ;
break;
case V_77 :
V_71 -> V_76 = 1 ;
case V_78 :
V_71 -> V_79 = 1 ;
break;
}
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
V_71 -> V_86 = V_65 >> V_87 ;
V_71 -> V_88 = V_26 == V_62 ? V_89 : V_90 ;
V_71 -> V_91 = F_21 ( V_2 -> V_3 . V_4 -> V_92 ) . V_91 ;
case V_47 :
case V_52 :
case V_54 :
case V_56 :
case V_59 :
V_69 -> V_93 = V_24 ;
break;
}
return V_64 ;
}
static int F_22 ( struct V_1 * V_2 , union V_23 * V_23 ,
unsigned long V_94 , T_1 V_24 , enum V_25 V_26 )
{
int V_7 ;
struct F_21 V_95 = F_21 ( V_2 -> V_3 . V_4 -> V_92 ) ;
if ( ! V_95 . V_96 ) {
V_23 -> V_20 = 0 ;
V_23 -> V_97 = 1 ;
return 0 ;
}
if ( V_26 == V_98 )
V_95 . V_91 = V_95 . V_91 == V_99 ? V_99 : V_100 ;
switch ( V_95 . V_91 ) {
case V_100 :
V_23 -> V_20 = V_2 -> V_3 . V_4 -> V_41 [ 1 ] ;
return 0 ;
case V_101 :
V_23 -> V_20 = V_2 -> V_3 . V_4 -> V_41 [ 7 ] ;
return 0 ;
case V_99 :
V_23 -> V_20 = V_2 -> V_3 . V_4 -> V_41 [ 13 ] ;
return 0 ;
case V_102 :
V_7 = F_17 ( V_2 , V_23 , V_24 , V_26 ) ;
if ( V_7 > 0 )
return F_20 ( V_2 , V_7 , V_94 , V_24 , V_26 , V_77 ) ;
return V_7 ;
}
return 0 ;
}
static int F_23 ( struct V_8 * V_8 , unsigned long V_103 , unsigned long * V_20 )
{
return F_24 ( V_8 , V_103 , V_20 , sizeof( * V_20 ) ) ;
}
static unsigned long F_25 ( struct V_1 * V_2 , unsigned long V_65 ,
unsigned long * V_103 , const union V_23 V_23 ,
enum V_25 V_26 )
{
union V_104 V_105 = { . V_86 = V_65 } ;
union V_106 V_107 = { . V_86 = V_65 } ;
union V_108 V_109 ;
int V_110 = 0 ;
union V_111 V_111 ;
unsigned long V_112 ;
int V_113 , V_114 ;
V_111 . V_20 = V_2 -> V_3 . V_4 -> V_41 [ 0 ] ;
V_113 = V_111 . V_115 && F_26 ( V_2 -> V_8 , 8 ) ;
V_114 = V_113 && F_26 ( V_2 -> V_8 , 78 ) ;
if ( V_23 . V_97 )
goto V_116;
V_112 = V_23 . V_117 * 4096 ;
switch ( V_23 . V_118 ) {
case V_119 :
if ( V_105 . V_120 > V_23 . V_121 )
return V_82 ;
V_112 += V_105 . V_122 * 8 ;
break;
case V_123 :
if ( V_105 . V_122 )
return V_80 ;
if ( V_105 . V_124 > V_23 . V_121 )
return V_83 ;
V_112 += V_105 . V_125 * 8 ;
break;
case V_126 :
if ( V_105 . V_122 || V_105 . V_125 )
return V_80 ;
if ( V_105 . V_127 > V_23 . V_121 )
return V_84 ;
V_112 += V_105 . V_128 * 8 ;
break;
case V_129 :
if ( V_105 . V_122 || V_105 . V_125 || V_105 . V_128 )
return V_80 ;
if ( V_105 . V_130 > V_23 . V_121 )
return V_85 ;
V_112 += V_105 . V_131 * 8 ;
break;
}
switch ( V_23 . V_118 ) {
case V_119 : {
union V_132 V_133 ;
if ( F_27 ( V_2 -> V_8 , V_112 ) )
return V_49 ;
if ( F_23 ( V_2 -> V_8 , V_112 , & V_133 . V_20 ) )
return - V_134 ;
if ( V_133 . V_50 )
return V_82 ;
if ( V_133 . V_135 != V_136 )
return V_137 ;
if ( V_105 . V_124 < V_133 . V_138 || V_105 . V_124 > V_133 . V_121 )
return V_83 ;
if ( V_113 )
V_110 |= V_133 . V_44 ;
V_112 = V_133 . V_139 * 4096 + V_105 . V_125 * 8 ;
}
case V_123 : {
union V_140 V_141 ;
if ( F_27 ( V_2 -> V_8 , V_112 ) )
return V_49 ;
if ( F_23 ( V_2 -> V_8 , V_112 , & V_141 . V_20 ) )
return - V_134 ;
if ( V_141 . V_50 )
return V_83 ;
if ( V_141 . V_135 != V_142 )
return V_137 ;
if ( V_105 . V_127 < V_141 . V_138 || V_105 . V_127 > V_141 . V_121 )
return V_84 ;
if ( V_113 )
V_110 |= V_141 . V_44 ;
V_112 = V_141 . V_139 * 4096 + V_105 . V_128 * 8 ;
}
case V_126 : {
union V_143 V_144 ;
if ( F_27 ( V_2 -> V_8 , V_112 ) )
return V_49 ;
if ( F_23 ( V_2 -> V_8 , V_112 , & V_144 . V_20 ) )
return - V_134 ;
if ( V_144 . V_50 )
return V_84 ;
if ( V_144 . V_135 != V_145 )
return V_137 ;
if ( V_144 . V_146 && V_23 . V_44 && V_114 )
return V_137 ;
if ( V_144 . V_147 && V_114 ) {
V_110 |= V_144 . V_148 . V_44 ;
V_107 . V_149 = V_144 . V_148 . V_149 ;
goto V_150;
}
if ( V_105 . V_130 < V_144 . V_151 . V_138 )
return V_85 ;
if ( V_105 . V_130 > V_144 . V_151 . V_121 )
return V_85 ;
if ( V_113 )
V_110 |= V_144 . V_151 . V_44 ;
V_112 = V_144 . V_151 . V_152 * 4096 + V_105 . V_131 * 8 ;
}
case V_129 : {
union V_153 V_154 ;
if ( F_27 ( V_2 -> V_8 , V_112 ) )
return V_49 ;
if ( F_23 ( V_2 -> V_8 , V_112 , & V_154 . V_20 ) )
return - V_134 ;
if ( V_154 . V_50 )
return V_85 ;
if ( V_154 . V_135 != V_155 )
return V_137 ;
if ( V_154 . V_156 && V_23 . V_44 )
return V_137 ;
if ( V_154 . V_147 && V_113 ) {
V_110 |= V_154 . V_148 . V_44 ;
V_107 . V_157 = V_154 . V_148 . V_157 ;
goto V_150;
}
V_110 |= V_154 . V_151 . V_44 ;
V_112 = V_154 . V_151 . V_158 * 2048 + V_105 . V_159 * 8 ;
}
}
if ( F_27 ( V_2 -> V_8 , V_112 ) )
return V_49 ;
if ( F_23 ( V_2 -> V_8 , V_112 , & V_109 . V_20 ) )
return - V_134 ;
if ( V_109 . V_50 )
return V_81 ;
if ( V_109 . V_160 )
return V_137 ;
V_110 |= V_109 . V_44 ;
V_107 . V_161 = V_109 . V_161 ;
V_116:
V_107 . V_86 = F_28 ( V_2 , V_107 . V_86 ) ;
V_150:
if ( V_26 == V_62 && V_110 )
return V_63 ;
if ( F_27 ( V_2 -> V_8 , V_107 . V_86 ) )
return V_49 ;
* V_103 = V_107 . V_86 ;
return 0 ;
}
static inline int F_29 ( unsigned long V_94 )
{
return ( V_94 & ~ 0x11fful ) == 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
const union V_23 V_23 )
{
union V_111 V_111 = { . V_20 = V_2 -> V_3 . V_4 -> V_41 [ 0 ] } ;
T_2 * V_95 = & V_2 -> V_3 . V_4 -> V_92 ;
if ( ! V_111 . V_162 )
return 0 ;
if ( F_21 ( * V_95 ) . V_96 && V_23 . V_44 )
return 0 ;
return 1 ;
}
static int F_31 ( struct V_1 * V_2 , unsigned long V_94 , T_1 V_24 ,
unsigned long * V_163 , unsigned long V_164 ,
const union V_23 V_23 , enum V_25 V_26 )
{
T_2 * V_95 = & V_2 -> V_3 . V_4 -> V_92 ;
int V_165 , V_7 = 0 ;
V_165 = F_30 ( V_2 , V_23 ) ;
while ( V_164 ) {
V_94 = F_32 ( V_2 , V_94 ) ;
if ( V_26 == V_62 && V_165 && F_29 ( V_94 ) )
return F_20 ( V_2 , V_63 , V_94 , V_24 , V_26 ,
V_73 ) ;
V_94 &= V_166 ;
if ( F_21 ( * V_95 ) . V_96 ) {
V_7 = F_25 ( V_2 , V_94 , V_163 , V_23 , V_26 ) ;
if ( V_7 < 0 )
return V_7 ;
} else {
* V_163 = F_28 ( V_2 , V_94 ) ;
if ( F_27 ( V_2 -> V_8 , * V_163 ) )
V_7 = V_49 ;
}
if ( V_7 )
return F_20 ( V_2 , V_7 , V_94 , V_24 , V_26 , V_78 ) ;
V_94 += V_167 ;
V_163 ++ ;
V_164 -- ;
}
return 0 ;
}
int F_33 ( struct V_1 * V_2 , unsigned long V_94 , T_1 V_24 , void * V_168 ,
unsigned long V_169 , enum V_25 V_26 )
{
T_2 * V_95 = & V_2 -> V_3 . V_4 -> V_92 ;
unsigned long V_170 , V_164 , V_103 , V_171 ;
unsigned long V_172 [ 2 ] ;
unsigned long * V_163 ;
int V_173 ;
union V_23 V_23 ;
int V_7 ;
if ( ! V_169 )
return 0 ;
V_94 = F_32 ( V_2 , V_94 ) ;
V_7 = F_22 ( V_2 , & V_23 , V_94 , V_24 , V_26 ) ;
if ( V_7 )
return V_7 ;
V_164 = ( ( ( V_94 & ~ V_166 ) + V_169 - 1 ) >> V_87 ) + 1 ;
V_163 = V_172 ;
if ( V_164 > F_34 ( V_172 ) )
V_163 = F_35 ( V_164 * sizeof( unsigned long ) ) ;
if ( ! V_163 )
return - V_174 ;
V_173 = F_21 ( * V_95 ) . V_96 && ! V_23 . V_97 ;
if ( V_173 )
F_15 ( V_2 ) ;
V_7 = F_31 ( V_2 , V_94 , V_24 , V_163 , V_164 , V_23 , V_26 ) ;
for ( V_171 = 0 ; V_171 < V_164 && ! V_7 ; V_171 ++ ) {
V_103 = * ( V_163 + V_171 ) + ( V_94 & ~ V_166 ) ;
V_170 = F_36 ( V_167 - ( V_103 & ~ V_166 ) , V_169 ) ;
if ( V_26 == V_62 )
V_7 = F_37 ( V_2 -> V_8 , V_103 , V_168 , V_170 ) ;
else
V_7 = F_24 ( V_2 -> V_8 , V_103 , V_168 , V_170 ) ;
V_169 -= V_170 ;
V_94 += V_170 ;
V_168 += V_170 ;
}
if ( V_173 )
F_16 ( V_2 ) ;
if ( V_164 > F_34 ( V_172 ) )
F_38 ( V_163 ) ;
return V_7 ;
}
int F_39 ( struct V_1 * V_2 , unsigned long V_175 ,
void * V_168 , unsigned long V_169 , enum V_25 V_26 )
{
unsigned long V_170 , V_103 ;
int V_7 = 0 ;
while ( V_169 && ! V_7 ) {
V_103 = F_28 ( V_2 , V_175 ) ;
V_170 = F_36 ( V_167 - ( V_103 & ~ V_166 ) , V_169 ) ;
if ( V_26 )
V_7 = F_40 ( V_2 , V_103 , V_168 , V_170 ) ;
else
V_7 = F_41 ( V_2 , V_103 , V_168 , V_170 ) ;
V_169 -= V_170 ;
V_175 += V_170 ;
V_168 += V_170 ;
}
return V_7 ;
}
int F_42 ( struct V_1 * V_2 , unsigned long V_65 , T_1 V_24 ,
unsigned long * V_103 , enum V_25 V_26 )
{
T_2 * V_95 = & V_2 -> V_3 . V_4 -> V_92 ;
union V_23 V_23 ;
int V_7 ;
V_65 = F_32 ( V_2 , V_65 ) ;
V_7 = F_22 ( V_2 , & V_23 , V_65 , V_24 , V_26 ) ;
if ( V_7 )
return V_7 ;
if ( F_29 ( V_65 ) && F_30 ( V_2 , V_23 ) ) {
if ( V_26 == V_62 )
return F_20 ( V_2 , V_63 , V_65 , 0 ,
V_26 , V_73 ) ;
}
if ( F_21 ( * V_95 ) . V_96 && ! V_23 . V_97 ) {
V_7 = F_25 ( V_2 , V_65 , V_103 , V_23 , V_26 ) ;
if ( V_7 > 0 )
return F_20 ( V_2 , V_7 , V_65 , 0 , V_26 , V_78 ) ;
} else {
* V_103 = F_28 ( V_2 , V_65 ) ;
if ( F_27 ( V_2 -> V_8 , * V_103 ) )
return F_20 ( V_2 , V_7 , V_65 , V_49 , V_26 , 0 ) ;
}
return V_7 ;
}
int F_43 ( struct V_1 * V_2 , unsigned long V_65 , T_1 V_24 ,
unsigned long V_176 , enum V_25 V_26 )
{
unsigned long V_103 ;
unsigned long V_177 ;
int V_7 = 0 ;
F_15 ( V_2 ) ;
while ( V_176 > 0 && ! V_7 ) {
V_177 = F_36 ( V_176 , V_167 - ( V_65 % V_167 ) ) ;
V_7 = F_42 ( V_2 , V_65 , V_24 , & V_103 , V_26 ) ;
V_65 += V_177 ;
V_176 -= V_177 ;
}
F_16 ( V_2 ) ;
return V_7 ;
}
int F_44 ( struct V_1 * V_2 , unsigned long V_175 )
{
union V_111 V_111 = { . V_20 = V_2 -> V_3 . V_4 -> V_41 [ 0 ] } ;
if ( ! V_111 . V_162 || ! F_29 ( V_175 ) )
return 0 ;
return F_20 ( V_2 , V_63 , V_175 , 0 , V_62 , V_73 ) ;
}
static int F_45 ( struct V_178 * V_179 , unsigned long V_180 ,
unsigned long * V_181 , int * V_110 ,
int * V_182 )
{
struct V_178 * V_183 ;
union V_23 V_23 ;
union V_104 V_105 ;
unsigned long V_112 ;
int V_7 ;
* V_182 = 0 ;
* V_110 = 0 ;
V_183 = V_179 -> V_183 ;
V_105 . V_86 = V_180 ;
V_23 . V_20 = V_179 -> V_184 ;
V_112 = V_23 . V_117 * 4096 ;
if ( V_23 . V_97 ) {
* V_182 = 1 ;
V_112 = 0 ;
V_23 . V_118 = V_119 ;
}
switch ( V_23 . V_118 ) {
case V_119 :
if ( V_105 . V_120 > V_23 . V_121 && ! * V_182 )
return V_82 ;
break;
case V_123 :
if ( V_105 . V_122 )
return V_80 ;
if ( V_105 . V_124 > V_23 . V_121 )
return V_83 ;
break;
case V_126 :
if ( V_105 . V_122 || V_105 . V_125 )
return V_80 ;
if ( V_105 . V_127 > V_23 . V_121 )
return V_84 ;
break;
case V_129 :
if ( V_105 . V_122 || V_105 . V_125 || V_105 . V_128 )
return V_80 ;
if ( V_105 . V_130 > V_23 . V_121 )
return V_85 ;
break;
}
switch ( V_23 . V_118 ) {
case V_119 : {
union V_132 V_133 ;
if ( * V_182 ) {
V_112 += ( unsigned long ) V_105 . V_122 << 53 ;
V_133 . V_20 = V_112 ;
goto V_185;
}
V_7 = F_46 ( V_183 , V_112 + V_105 . V_122 * 8 , & V_133 . V_20 ) ;
if ( V_7 )
return V_7 ;
if ( V_133 . V_50 )
return V_82 ;
if ( V_133 . V_135 != V_136 )
return V_137 ;
if ( V_105 . V_124 < V_133 . V_138 || V_105 . V_124 > V_133 . V_121 )
return V_83 ;
if ( V_179 -> V_186 >= 1 )
* V_110 |= V_133 . V_44 ;
V_112 = V_133 . V_139 << 12UL ;
V_185:
V_7 = F_47 ( V_179 , V_180 , V_133 . V_20 , * V_182 ) ;
if ( V_7 )
return V_7 ;
}
case V_123 : {
union V_140 V_141 ;
if ( * V_182 ) {
V_112 += ( unsigned long ) V_105 . V_125 << 42 ;
V_141 . V_20 = V_112 ;
goto V_187;
}
V_7 = F_46 ( V_183 , V_112 + V_105 . V_125 * 8 , & V_141 . V_20 ) ;
if ( V_7 )
return V_7 ;
if ( V_141 . V_50 )
return V_83 ;
if ( V_141 . V_135 != V_142 )
return V_137 ;
if ( V_105 . V_127 < V_141 . V_138 || V_105 . V_127 > V_141 . V_121 )
return V_84 ;
if ( V_179 -> V_186 >= 1 )
* V_110 |= V_141 . V_44 ;
V_112 = V_141 . V_139 << 12UL ;
V_187:
V_141 . V_44 |= * V_110 ;
V_7 = F_48 ( V_179 , V_180 , V_141 . V_20 , * V_182 ) ;
if ( V_7 )
return V_7 ;
}
case V_126 : {
union V_143 V_144 ;
if ( * V_182 ) {
V_112 += ( unsigned long ) V_105 . V_128 << 31 ;
V_144 . V_20 = V_112 ;
goto V_188;
}
V_7 = F_46 ( V_183 , V_112 + V_105 . V_128 * 8 , & V_144 . V_20 ) ;
if ( V_7 )
return V_7 ;
if ( V_144 . V_50 )
return V_84 ;
if ( V_144 . V_135 != V_145 )
return V_137 ;
if ( V_144 . V_146 && V_23 . V_44 && V_179 -> V_186 >= 2 )
return V_137 ;
if ( V_144 . V_147 && V_179 -> V_186 >= 2 ) {
* V_110 |= V_144 . V_151 . V_44 ;
* V_182 = 1 ;
V_112 = V_144 . V_148 . V_149 << 31UL ;
V_144 . V_20 = V_112 ;
goto V_188;
}
if ( V_105 . V_130 < V_144 . V_151 . V_138 || V_105 . V_130 > V_144 . V_151 . V_121 )
return V_85 ;
if ( V_179 -> V_186 >= 1 )
* V_110 |= V_144 . V_151 . V_44 ;
V_112 = V_144 . V_151 . V_152 << 12UL ;
V_188:
V_144 . V_151 . V_44 |= * V_110 ;
V_7 = F_49 ( V_179 , V_180 , V_144 . V_20 , * V_182 ) ;
if ( V_7 )
return V_7 ;
}
case V_129 : {
union V_153 V_154 ;
if ( * V_182 ) {
V_112 += ( unsigned long ) V_105 . V_131 << 20 ;
V_154 . V_20 = V_112 ;
goto V_189;
}
V_7 = F_46 ( V_183 , V_112 + V_105 . V_131 * 8 , & V_154 . V_20 ) ;
if ( V_7 )
return V_7 ;
if ( V_154 . V_50 )
return V_85 ;
if ( V_154 . V_135 != V_155 )
return V_137 ;
if ( V_154 . V_156 && V_23 . V_44 )
return V_137 ;
* V_110 |= V_154 . V_151 . V_44 ;
if ( V_154 . V_147 && V_179 -> V_186 >= 1 ) {
* V_182 = 1 ;
V_112 = V_154 . V_148 . V_157 << 20UL ;
V_154 . V_20 = V_112 ;
goto V_189;
}
V_112 = V_154 . V_151 . V_158 << 11UL ;
V_189:
V_154 . V_151 . V_44 |= * V_110 ;
V_7 = F_50 ( V_179 , V_180 , V_154 . V_20 , * V_182 ) ;
if ( V_7 )
return V_7 ;
}
}
* V_181 = V_112 ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 , struct V_178 * V_179 ,
unsigned long V_180 )
{
union V_104 V_105 ;
union V_108 V_109 ;
unsigned long V_181 ;
int V_110 , V_182 ;
int V_7 ;
F_52 ( & V_179 -> V_190 -> V_191 ) ;
F_15 ( V_2 ) ;
V_7 = F_53 ( V_179 , V_180 , & V_181 , & V_110 , & V_182 ) ;
if ( V_7 )
V_7 = F_45 ( V_179 , V_180 , & V_181 , & V_110 ,
& V_182 ) ;
V_105 . V_86 = V_180 ;
if ( V_182 ) {
V_109 . V_20 = V_181 + ( ( unsigned long ) V_105 . V_159 << 12UL ) ;
goto V_192;
}
if ( ! V_7 )
V_7 = F_46 ( V_179 -> V_183 , V_181 + V_105 . V_159 * 8 , & V_109 . V_20 ) ;
if ( ! V_7 && V_109 . V_50 )
V_7 = V_81 ;
if ( ! V_7 && V_109 . V_160 )
V_7 = V_137 ;
V_192:
V_109 . V_44 |= V_110 ;
if ( ! V_7 )
V_7 = F_54 ( V_179 , V_180 , F_55 ( V_109 . V_20 ) ) ;
F_16 ( V_2 ) ;
F_56 ( & V_179 -> V_190 -> V_191 ) ;
return V_7 ;
}
