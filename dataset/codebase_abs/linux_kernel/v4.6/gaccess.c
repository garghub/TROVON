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
static int F_20 ( struct V_1 * V_2 , union V_22 * V_22 ,
T_1 V_23 , enum V_24 V_25 )
{
int V_6 ;
struct V_63 V_64 = V_63 ( V_2 -> V_3 . V_4 -> V_65 ) ;
struct V_66 * V_67 = & V_2 -> V_3 . V_67 ;
struct V_68 * V_69 ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
V_69 = (struct V_68 * ) & V_67 -> V_70 ;
V_69 -> V_71 = V_25 == V_61 ? V_72 : V_73 ;
V_69 -> V_74 = V_64 . V_74 ;
if ( ! V_64 . V_75 ) {
V_22 -> V_19 = 0 ;
V_22 -> V_76 = 1 ;
return 0 ;
}
if ( V_25 == V_77 )
V_64 . V_74 = V_64 . V_74 == V_78 ? V_78 : V_79 ;
switch ( V_64 . V_74 ) {
case V_79 :
V_22 -> V_19 = V_2 -> V_3 . V_4 -> V_40 [ 1 ] ;
return 0 ;
case V_80 :
V_22 -> V_19 = V_2 -> V_3 . V_4 -> V_40 [ 7 ] ;
return 0 ;
case V_78 :
V_22 -> V_19 = V_2 -> V_3 . V_4 -> V_40 [ 13 ] ;
return 0 ;
case V_81 :
V_6 = F_17 ( V_2 , V_22 , V_23 , V_25 ) ;
switch ( V_6 ) {
case V_46 :
case V_51 :
case V_53 :
case V_55 :
case V_58 :
V_2 -> V_3 . V_67 . V_82 = V_23 ;
break;
case V_62 :
V_69 -> V_83 = 1 ;
V_69 -> V_84 = 1 ;
break;
}
if ( V_6 > 0 )
V_67 -> V_85 = V_6 ;
return V_6 ;
}
return 0 ;
}
static int F_21 ( struct V_7 * V_7 , unsigned long V_86 , unsigned long * V_19 )
{
return F_22 ( V_7 , V_86 , V_19 , sizeof( * V_19 ) ) ;
}
static unsigned long F_23 ( struct V_1 * V_2 , unsigned long V_87 ,
unsigned long * V_86 , const union V_22 V_22 ,
enum V_24 V_25 )
{
union V_88 V_89 = { . V_90 = V_87 } ;
union V_91 V_92 = { . V_90 = V_87 } ;
union V_93 V_94 ;
int V_95 = 0 ;
union V_96 V_96 ;
unsigned long V_97 ;
int V_98 , V_99 ;
V_96 . V_19 = V_2 -> V_3 . V_4 -> V_40 [ 0 ] ;
V_98 = V_96 . V_100 && F_24 ( V_2 -> V_7 , 8 ) ;
V_99 = V_98 && F_24 ( V_2 -> V_7 , 78 ) ;
if ( V_22 . V_76 )
goto V_101;
V_97 = V_22 . V_102 * 4096 ;
switch ( V_22 . V_103 ) {
case V_104 :
if ( V_89 . V_105 > V_22 . V_106 )
return V_107 ;
V_97 += V_89 . V_108 * 8 ;
break;
case V_109 :
if ( V_89 . V_108 )
return V_110 ;
if ( V_89 . V_111 > V_22 . V_106 )
return V_112 ;
V_97 += V_89 . V_113 * 8 ;
break;
case V_114 :
if ( V_89 . V_108 || V_89 . V_113 )
return V_110 ;
if ( V_89 . V_115 > V_22 . V_106 )
return V_116 ;
V_97 += V_89 . V_117 * 8 ;
break;
case V_118 :
if ( V_89 . V_108 || V_89 . V_113 || V_89 . V_117 )
return V_110 ;
if ( V_89 . V_119 > V_22 . V_106 )
return V_120 ;
V_97 += V_89 . V_121 * 8 ;
break;
}
switch ( V_22 . V_103 ) {
case V_104 : {
union V_122 V_123 ;
if ( F_25 ( V_2 -> V_7 , V_97 ) )
return V_48 ;
if ( F_21 ( V_2 -> V_7 , V_97 , & V_123 . V_19 ) )
return - V_124 ;
if ( V_123 . V_49 )
return V_107 ;
if ( V_123 . V_125 != V_126 )
return V_127 ;
if ( V_89 . V_111 < V_123 . V_128 || V_89 . V_111 > V_123 . V_106 )
return V_112 ;
if ( V_98 )
V_95 |= V_123 . V_43 ;
V_97 = V_123 . V_129 * 4096 + V_89 . V_113 * 8 ;
}
case V_109 : {
union V_130 V_131 ;
if ( F_25 ( V_2 -> V_7 , V_97 ) )
return V_48 ;
if ( F_21 ( V_2 -> V_7 , V_97 , & V_131 . V_19 ) )
return - V_124 ;
if ( V_131 . V_49 )
return V_112 ;
if ( V_131 . V_125 != V_132 )
return V_127 ;
if ( V_89 . V_115 < V_131 . V_128 || V_89 . V_115 > V_131 . V_106 )
return V_116 ;
if ( V_98 )
V_95 |= V_131 . V_43 ;
V_97 = V_131 . V_129 * 4096 + V_89 . V_117 * 8 ;
}
case V_114 : {
union V_133 V_134 ;
if ( F_25 ( V_2 -> V_7 , V_97 ) )
return V_48 ;
if ( F_21 ( V_2 -> V_7 , V_97 , & V_134 . V_19 ) )
return - V_124 ;
if ( V_134 . V_49 )
return V_116 ;
if ( V_134 . V_125 != V_135 )
return V_127 ;
if ( V_134 . V_136 && V_22 . V_43 && V_99 )
return V_127 ;
if ( V_134 . V_137 && V_99 ) {
V_95 |= V_134 . V_138 . V_43 ;
V_92 . V_139 = V_134 . V_138 . V_139 ;
goto V_140;
}
if ( V_89 . V_119 < V_134 . V_141 . V_128 )
return V_120 ;
if ( V_89 . V_119 > V_134 . V_141 . V_106 )
return V_120 ;
if ( V_98 )
V_95 |= V_134 . V_141 . V_43 ;
V_97 = V_134 . V_141 . V_142 * 4096 + V_89 . V_121 * 8 ;
}
case V_118 : {
union V_143 V_144 ;
if ( F_25 ( V_2 -> V_7 , V_97 ) )
return V_48 ;
if ( F_21 ( V_2 -> V_7 , V_97 , & V_144 . V_19 ) )
return - V_124 ;
if ( V_144 . V_49 )
return V_120 ;
if ( V_144 . V_125 != V_145 )
return V_127 ;
if ( V_144 . V_146 && V_22 . V_43 )
return V_127 ;
if ( V_144 . V_137 && V_98 ) {
V_95 |= V_144 . V_138 . V_43 ;
V_92 . V_147 = V_144 . V_138 . V_147 ;
goto V_140;
}
V_95 |= V_144 . V_141 . V_43 ;
V_97 = V_144 . V_141 . V_148 * 2048 + V_89 . V_149 * 8 ;
}
}
if ( F_25 ( V_2 -> V_7 , V_97 ) )
return V_48 ;
if ( F_21 ( V_2 -> V_7 , V_97 , & V_94 . V_19 ) )
return - V_124 ;
if ( V_94 . V_49 )
return V_150 ;
if ( V_94 . V_151 )
return V_127 ;
if ( V_94 . V_152 && ! V_98 )
return V_127 ;
V_95 |= V_94 . V_43 ;
V_92 . V_153 = V_94 . V_153 ;
V_101:
V_92 . V_90 = F_26 ( V_2 , V_92 . V_90 ) ;
V_140:
if ( V_25 == V_61 && V_95 )
return V_62 ;
if ( F_25 ( V_2 -> V_7 , V_92 . V_90 ) )
return V_48 ;
* V_86 = V_92 . V_90 ;
return 0 ;
}
static inline int F_27 ( unsigned long V_154 )
{
return ( V_154 & ~ 0x11fful ) == 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
const union V_22 V_22 )
{
union V_96 V_96 = { . V_19 = V_2 -> V_3 . V_4 -> V_40 [ 0 ] } ;
T_3 * V_64 = & V_2 -> V_3 . V_4 -> V_65 ;
if ( ! V_96 . V_155 )
return 0 ;
if ( V_63 ( * V_64 ) . V_75 && V_22 . V_43 )
return 0 ;
return 1 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned long V_154 ,
unsigned long * V_156 , unsigned long V_157 ,
const union V_22 V_22 , enum V_24 V_25 )
{
struct V_66 * V_67 = & V_2 -> V_3 . V_67 ;
T_3 * V_64 = & V_2 -> V_3 . V_4 -> V_65 ;
struct V_68 * V_69 ;
int V_158 , V_6 ;
V_69 = (struct V_68 * ) & V_67 -> V_70 ;
V_158 = F_28 ( V_2 , V_22 ) ;
while ( V_157 ) {
V_154 = F_30 ( V_2 , V_154 ) ;
V_69 -> V_90 = V_154 >> V_159 ;
if ( V_25 == V_61 && V_158 && F_27 ( V_154 ) ) {
V_67 -> V_85 = V_62 ;
return V_67 -> V_85 ;
}
V_154 &= V_160 ;
if ( V_63 ( * V_64 ) . V_75 ) {
V_6 = F_23 ( V_2 , V_154 , V_156 , V_22 , V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 == V_62 )
V_69 -> V_84 = 1 ;
if ( V_6 )
V_67 -> V_85 = V_6 ;
} else {
* V_156 = F_26 ( V_2 , V_154 ) ;
if ( F_25 ( V_2 -> V_7 , * V_156 ) )
V_67 -> V_85 = V_48 ;
}
if ( V_67 -> V_85 )
return V_67 -> V_85 ;
V_154 += V_161 ;
V_156 ++ ;
V_157 -- ;
}
return 0 ;
}
int F_31 ( struct V_1 * V_2 , unsigned long V_154 , T_1 V_23 , void * V_162 ,
unsigned long V_163 , enum V_24 V_25 )
{
T_3 * V_64 = & V_2 -> V_3 . V_4 -> V_65 ;
unsigned long V_164 , V_157 , V_86 , V_165 ;
unsigned long V_166 [ 2 ] ;
unsigned long * V_156 ;
int V_167 ;
union V_22 V_22 ;
int V_6 ;
if ( ! V_163 )
return 0 ;
V_6 = F_20 ( V_2 , & V_22 , V_23 , V_25 ) ;
if ( V_6 )
return V_6 ;
V_157 = ( ( ( V_154 & ~ V_160 ) + V_163 - 1 ) >> V_159 ) + 1 ;
V_156 = V_166 ;
if ( V_157 > F_32 ( V_166 ) )
V_156 = F_33 ( V_157 * sizeof( unsigned long ) ) ;
if ( ! V_156 )
return - V_168 ;
V_167 = V_63 ( * V_64 ) . V_75 && ! V_22 . V_76 ;
if ( V_167 )
F_15 ( V_2 ) ;
V_6 = F_29 ( V_2 , V_154 , V_156 , V_157 , V_22 , V_25 ) ;
for ( V_165 = 0 ; V_165 < V_157 && ! V_6 ; V_165 ++ ) {
V_86 = * ( V_156 + V_165 ) + ( V_154 & ~ V_160 ) ;
V_164 = F_34 ( V_161 - ( V_86 & ~ V_160 ) , V_163 ) ;
if ( V_25 == V_61 )
V_6 = F_35 ( V_2 -> V_7 , V_86 , V_162 , V_164 ) ;
else
V_6 = F_22 ( V_2 -> V_7 , V_86 , V_162 , V_164 ) ;
V_163 -= V_164 ;
V_154 += V_164 ;
V_162 += V_164 ;
}
if ( V_167 )
F_16 ( V_2 ) ;
if ( V_157 > F_32 ( V_166 ) )
F_36 ( V_156 ) ;
return V_6 ;
}
int F_37 ( struct V_1 * V_2 , unsigned long V_169 ,
void * V_162 , unsigned long V_163 , enum V_24 V_25 )
{
unsigned long V_164 , V_86 ;
int V_6 = 0 ;
while ( V_163 && ! V_6 ) {
V_86 = F_26 ( V_2 , V_169 ) ;
V_164 = F_34 ( V_161 - ( V_86 & ~ V_160 ) , V_163 ) ;
if ( V_25 )
V_6 = F_38 ( V_2 , V_86 , V_162 , V_164 ) ;
else
V_6 = F_39 ( V_2 , V_86 , V_162 , V_164 ) ;
V_163 -= V_164 ;
V_169 += V_164 ;
V_162 += V_164 ;
}
return V_6 ;
}
int F_40 ( struct V_1 * V_2 , unsigned long V_87 , T_1 V_23 ,
unsigned long * V_86 , enum V_24 V_25 )
{
struct V_66 * V_67 = & V_2 -> V_3 . V_67 ;
T_3 * V_64 = & V_2 -> V_3 . V_4 -> V_65 ;
struct V_68 * V_170 ;
union V_22 V_22 ;
int V_6 ;
V_87 = F_30 ( V_2 , V_87 ) ;
V_170 = (struct V_68 * ) & V_67 -> V_70 ;
V_6 = F_20 ( V_2 , & V_22 , V_23 , V_25 ) ;
V_170 -> V_90 = V_87 >> V_159 ;
if ( V_6 )
return V_6 ;
if ( F_27 ( V_87 ) && F_28 ( V_2 , V_22 ) ) {
if ( V_25 == V_61 ) {
V_6 = V_67 -> V_85 = V_62 ;
return V_6 ;
}
}
if ( V_63 ( * V_64 ) . V_75 && ! V_22 . V_76 ) {
V_6 = F_23 ( V_2 , V_87 , V_86 , V_22 , V_25 ) ;
if ( V_6 > 0 ) {
if ( V_6 == V_62 )
V_170 -> V_84 = 1 ;
V_67 -> V_85 = V_6 ;
}
} else {
V_6 = 0 ;
* V_86 = F_26 ( V_2 , V_87 ) ;
if ( F_25 ( V_2 -> V_7 , * V_86 ) )
V_6 = V_67 -> V_85 = V_48 ;
}
return V_6 ;
}
int F_41 ( struct V_1 * V_2 , unsigned long V_87 , T_1 V_23 ,
unsigned long V_171 , enum V_24 V_25 )
{
unsigned long V_86 ;
unsigned long V_172 ;
int V_6 = 0 ;
F_15 ( V_2 ) ;
while ( V_171 > 0 && ! V_6 ) {
V_172 = F_34 ( V_171 , V_161 - ( V_87 % V_161 ) ) ;
V_6 = F_40 ( V_2 , V_87 , V_23 , & V_86 , V_25 ) ;
V_87 += V_172 ;
V_171 -= V_172 ;
}
F_16 ( V_2 ) ;
return V_6 ;
}
int F_42 ( struct V_1 * V_2 , unsigned long V_169 )
{
struct V_66 * V_67 = & V_2 -> V_3 . V_67 ;
T_3 * V_64 = & V_2 -> V_3 . V_4 -> V_65 ;
struct V_68 * V_69 ;
union V_96 V_96 = { . V_19 = V_2 -> V_3 . V_4 -> V_40 [ 0 ] } ;
if ( ! V_96 . V_155 || ! F_27 ( V_169 ) )
return 0 ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
V_69 = (struct V_68 * ) & V_67 -> V_70 ;
V_69 -> V_71 = V_72 ;
V_69 -> V_74 = V_63 ( * V_64 ) . V_74 ;
V_69 -> V_90 = V_169 >> V_159 ;
V_67 -> V_85 = V_62 ;
return V_67 -> V_85 ;
}
