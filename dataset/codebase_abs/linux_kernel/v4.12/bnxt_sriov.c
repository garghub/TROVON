static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 V_10 = { 0 } ;
struct V_11 * V_12 ;
int V_13 = 0 ;
F_2 ( V_2 , & V_10 , V_14 , - 1 , - 1 ) ;
if ( V_4 )
V_10 . V_15 = F_3 ( V_4 -> V_16 ) ;
else
V_10 . V_15 = F_3 ( 0xffff ) ;
V_12 = (struct V_11 * ) V_10 . V_17 ;
V_12 -> type = F_3 ( V_18 ) ;
V_12 -> V_5 = F_3 ( V_5 ) ;
F_4 ( & V_2 -> V_19 ) ;
V_13 = F_5 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) ;
if ( V_13 ) {
F_6 ( V_2 -> V_21 , L_1 ,
V_13 ) ;
goto V_22;
}
if ( V_7 -> V_23 ) {
F_6 ( V_2 -> V_21 , L_2 ,
V_7 -> V_23 ) ;
V_13 = - 1 ;
}
V_22:
F_7 ( & V_2 -> V_19 ) ;
return V_13 ;
}
static int F_8 ( struct V_1 * V_2 , int V_24 )
{
if ( ! F_9 ( V_25 , & V_2 -> V_26 ) ) {
F_6 ( V_2 -> V_21 , L_3 ) ;
return - V_27 ;
}
if ( ! V_2 -> V_28 . V_29 ) {
F_6 ( V_2 -> V_21 , L_4 ) ;
return - V_27 ;
}
if ( V_24 >= V_2 -> V_28 . V_30 ) {
F_6 ( V_2 -> V_21 , L_5 , V_24 ) ;
return - V_27 ;
}
return 0 ;
}
int F_10 ( struct V_31 * V_21 , int V_24 , bool V_32 )
{
struct V_33 V_10 = { 0 } ;
struct V_1 * V_2 = F_11 ( V_21 ) ;
struct V_3 * V_4 ;
bool V_34 = false ;
T_2 V_35 ;
int V_13 ;
if ( V_2 -> V_36 < 0x10701 )
return - V_37 ;
V_13 = F_8 ( V_2 , V_24 ) ;
if ( V_13 )
return V_13 ;
V_4 = & V_2 -> V_28 . V_4 [ V_24 ] ;
if ( V_4 -> V_38 & V_39 )
V_34 = true ;
if ( V_34 == V_32 )
return 0 ;
V_35 = V_4 -> V_35 ;
if ( V_32 )
V_35 |= V_40 ;
else
V_35 |= V_41 ;
F_2 ( V_2 , & V_10 , V_42 , - 1 , - 1 ) ;
V_10 . V_43 = F_3 ( V_4 -> V_16 ) ;
V_10 . V_38 = F_12 ( V_35 ) ;
V_13 = F_13 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) ;
if ( ! V_13 ) {
V_4 -> V_35 = V_35 ;
if ( V_32 )
V_4 -> V_38 |= V_39 ;
else
V_4 -> V_38 &= ~ V_39 ;
}
return V_13 ;
}
int F_14 ( struct V_31 * V_21 , int V_24 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = F_11 ( V_21 ) ;
struct V_3 * V_4 ;
int V_13 ;
V_13 = F_8 ( V_2 , V_24 ) ;
if ( V_13 )
return V_13 ;
V_45 -> V_4 = V_24 ;
V_4 = & V_2 -> V_28 . V_4 [ V_24 ] ;
memcpy ( & V_45 -> V_46 , V_4 -> V_47 , V_48 ) ;
V_45 -> V_49 = V_4 -> V_49 ;
V_45 -> V_50 = V_4 -> V_50 ;
V_45 -> V_51 = V_4 -> V_51 ;
if ( V_4 -> V_38 & V_52 )
V_45 -> V_53 = V_4 -> V_51 >> V_54 ;
else
V_45 -> V_53 = 0 ;
V_45 -> V_55 = ! ! ( V_4 -> V_38 & V_39 ) ;
if ( ! ( V_4 -> V_38 & V_56 ) )
V_45 -> V_57 = V_58 ;
else if ( V_4 -> V_38 & V_59 )
V_45 -> V_57 = V_60 ;
else
V_45 -> V_57 = V_61 ;
return 0 ;
}
int F_15 ( struct V_31 * V_21 , int V_24 , T_3 * V_46 )
{
struct V_33 V_10 = { 0 } ;
struct V_1 * V_2 = F_11 ( V_21 ) ;
struct V_3 * V_4 ;
int V_13 ;
V_13 = F_8 ( V_2 , V_24 ) ;
if ( V_13 )
return V_13 ;
if ( F_16 ( V_46 ) ) {
F_6 ( V_21 , L_6 ) ;
return - V_27 ;
}
V_4 = & V_2 -> V_28 . V_4 [ V_24 ] ;
memcpy ( V_4 -> V_47 , V_46 , V_48 ) ;
F_2 ( V_2 , & V_10 , V_42 , - 1 , - 1 ) ;
V_10 . V_43 = F_3 ( V_4 -> V_16 ) ;
V_10 . V_38 = F_12 ( V_4 -> V_35 ) ;
V_10 . V_62 = F_12 ( V_63 ) ;
memcpy ( V_10 . V_64 , V_46 , V_48 ) ;
return F_13 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) ;
}
int F_17 ( struct V_31 * V_21 , int V_24 , T_1 V_65 , T_3 V_53 ,
T_4 V_66 )
{
struct V_33 V_10 = { 0 } ;
struct V_1 * V_2 = F_11 ( V_21 ) ;
struct V_3 * V_4 ;
T_1 V_67 ;
int V_13 ;
if ( V_2 -> V_36 < 0x10201 )
return - V_37 ;
if ( V_66 != F_18 ( V_68 ) )
return - V_69 ;
V_13 = F_8 ( V_2 , V_24 ) ;
if ( V_13 )
return V_13 ;
if ( V_65 > 4095 || V_53 )
return - V_27 ;
V_4 = & V_2 -> V_28 . V_4 [ V_24 ] ;
V_67 = V_65 ;
if ( V_67 == V_4 -> V_51 )
return 0 ;
F_2 ( V_2 , & V_10 , V_42 , - 1 , - 1 ) ;
V_10 . V_43 = F_3 ( V_4 -> V_16 ) ;
V_10 . V_38 = F_12 ( V_4 -> V_35 ) ;
V_10 . V_70 = F_3 ( V_67 ) ;
V_10 . V_62 = F_12 ( V_71 ) ;
V_13 = F_13 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) ;
if ( ! V_13 )
V_4 -> V_51 = V_67 ;
return V_13 ;
}
int F_19 ( struct V_31 * V_21 , int V_24 , int V_50 ,
int V_49 )
{
struct V_33 V_10 = { 0 } ;
struct V_1 * V_2 = F_11 ( V_21 ) ;
struct V_3 * V_4 ;
T_2 V_72 ;
int V_13 ;
V_13 = F_8 ( V_2 , V_24 ) ;
if ( V_13 )
return V_13 ;
V_4 = & V_2 -> V_28 . V_4 [ V_24 ] ;
V_72 = F_20 ( V_2 -> V_73 . V_74 ) ;
if ( V_49 > V_72 ) {
F_21 ( V_2 -> V_21 , L_7 ,
V_49 , V_24 ) ;
return - V_27 ;
}
if ( V_50 > V_72 || V_50 > V_49 ) {
F_21 ( V_2 -> V_21 , L_8 ,
V_50 , V_24 ) ;
return - V_27 ;
}
if ( V_50 == V_4 -> V_50 && V_49 == V_4 -> V_49 )
return 0 ;
F_2 ( V_2 , & V_10 , V_42 , - 1 , - 1 ) ;
V_10 . V_43 = F_3 ( V_4 -> V_16 ) ;
V_10 . V_38 = F_12 ( V_4 -> V_35 ) ;
V_10 . V_62 = F_12 ( V_75 ) ;
V_10 . V_76 = F_12 ( V_49 ) ;
V_10 . V_62 |= F_12 ( V_77 ) ;
V_10 . V_78 = F_12 ( V_50 ) ;
V_13 = F_13 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) ;
if ( ! V_13 ) {
V_4 -> V_50 = V_50 ;
V_4 -> V_49 = V_49 ;
}
return V_13 ;
}
int F_22 ( struct V_31 * V_21 , int V_24 , int V_79 )
{
struct V_1 * V_2 = F_11 ( V_21 ) ;
struct V_3 * V_4 ;
int V_13 ;
V_13 = F_8 ( V_2 , V_24 ) ;
if ( V_13 )
return V_13 ;
V_4 = & V_2 -> V_28 . V_4 [ V_24 ] ;
V_4 -> V_38 &= ~ ( V_59 | V_56 ) ;
switch ( V_79 ) {
case V_58 :
V_4 -> V_38 |= V_59 ;
break;
case V_61 :
V_4 -> V_38 |= V_56 ;
break;
case V_60 :
V_4 -> V_38 |= V_59 | V_56 ;
break;
default:
F_6 ( V_2 -> V_21 , L_9 ) ;
V_13 = - V_27 ;
break;
}
if ( V_4 -> V_38 & ( V_59 | V_56 ) )
V_13 = F_1 ( V_2 , V_4 ,
V_80 ) ;
return V_13 ;
}
static int F_23 ( struct V_1 * V_2 , int V_81 )
{
int V_82 ;
struct V_3 * V_4 ;
for ( V_82 = 0 ; V_82 < V_81 ; V_82 ++ ) {
V_4 = & V_2 -> V_28 . V_4 [ V_82 ] ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int V_81 )
{
int V_82 , V_13 = 0 ;
struct V_83 * V_28 = & V_2 -> V_28 ;
struct V_84 V_10 = { 0 } ;
F_2 ( V_2 , & V_10 , V_85 , - 1 , - 1 ) ;
F_4 ( & V_2 -> V_19 ) ;
for ( V_82 = V_28 -> V_86 ; V_82 < V_28 -> V_86 + V_81 ; V_82 ++ ) {
V_10 . V_24 = F_3 ( V_82 ) ;
V_13 = F_5 ( V_2 , & V_10 , sizeof( V_10 ) ,
V_20 ) ;
if ( V_13 )
break;
}
F_7 ( & V_2 -> V_19 ) ;
return V_13 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_87 * V_88 = V_2 -> V_88 ;
int V_82 ;
F_26 ( V_2 -> V_28 . V_89 ) ;
V_2 -> V_28 . V_89 = NULL ;
for ( V_82 = 0 ; V_82 < 4 ; V_82 ++ ) {
if ( V_2 -> V_28 . V_90 [ V_82 ] ) {
F_27 ( & V_88 -> V_21 , V_91 ,
V_2 -> V_28 . V_90 [ V_82 ] ,
V_2 -> V_28 . V_92 [ V_82 ] ) ;
V_2 -> V_28 . V_90 [ V_82 ] = NULL ;
}
}
F_26 ( V_2 -> V_28 . V_4 ) ;
V_2 -> V_28 . V_4 = NULL ;
}
static int F_28 ( struct V_1 * V_2 , int V_81 )
{
struct V_87 * V_88 = V_2 -> V_88 ;
T_2 V_93 , V_94 , V_82 , V_95 , V_96 = 0 ;
V_2 -> V_28 . V_4 = F_29 ( V_81 , sizeof( struct V_3 ) , V_97 ) ;
if ( ! V_2 -> V_28 . V_4 )
return - V_98 ;
F_23 ( V_2 , V_81 ) ;
V_94 = V_81 * V_99 ;
V_93 = V_94 / V_91 ;
if ( V_94 & ( V_91 - 1 ) )
V_93 ++ ;
for ( V_82 = 0 ; V_82 < V_93 ; V_82 ++ ) {
V_2 -> V_28 . V_90 [ V_82 ] =
F_30 ( & V_88 -> V_21 , V_91 ,
& V_2 -> V_28 . V_92 [ V_82 ] ,
V_97 ) ;
if ( ! V_2 -> V_28 . V_90 [ V_82 ] )
return - V_98 ;
for ( V_95 = 0 ; V_95 < V_100 && V_96 < V_81 ; V_95 ++ ) {
struct V_3 * V_4 = & V_2 -> V_28 . V_4 [ V_96 ] ;
V_4 -> V_90 = V_2 -> V_28 . V_90 [ V_82 ] +
V_95 * V_99 ;
V_4 -> V_92 =
V_2 -> V_28 . V_92 [ V_82 ] + V_95 *
V_99 ;
V_96 ++ ;
}
}
V_2 -> V_28 . V_89 = F_31 ( 16 , V_97 ) ;
if ( ! V_2 -> V_28 . V_89 )
return - V_98 ;
V_2 -> V_28 . V_101 = V_93 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_102 V_10 = { 0 } ;
F_2 ( V_2 , & V_10 , V_103 , - 1 , - 1 ) ;
V_10 . V_104 = F_3 ( V_2 -> V_28 . V_101 ) ;
V_10 . V_105 = F_3 ( V_106 ) ;
V_10 . V_107 = F_3 ( V_99 ) ;
V_10 . V_108 = F_33 ( V_2 -> V_28 . V_92 [ 0 ] ) ;
V_10 . V_109 = F_33 ( V_2 -> V_28 . V_92 [ 1 ] ) ;
V_10 . V_110 = F_33 ( V_2 -> V_28 . V_92 [ 2 ] ) ;
V_10 . V_111 = F_33 ( V_2 -> V_28 . V_92 [ 3 ] ) ;
return F_13 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) ;
}
static int F_34 ( struct V_1 * V_2 , int V_81 )
{
T_2 V_13 = 0 , V_112 , V_82 ;
T_1 V_113 , V_114 , V_115 , V_116 , V_117 ;
T_1 V_118 ;
struct V_33 V_10 = { 0 } ;
struct V_83 * V_28 = & V_2 -> V_28 ;
int V_119 = 0 ;
F_2 ( V_2 , & V_10 , V_42 , - 1 , - 1 ) ;
V_115 = ( V_28 -> V_120 - V_2 -> V_121 ) / V_81 ;
V_116 = ( V_28 -> V_122 - V_2 -> V_123 ) / V_81 ;
if ( V_2 -> V_38 & V_124 )
V_114 = ( V_28 -> V_125 - V_2 -> V_126 * 2 ) /
V_81 ;
else
V_114 = ( V_28 -> V_125 - V_2 -> V_126 ) / V_81 ;
V_118 = ( V_2 -> V_28 . V_127 - V_2 -> V_126 ) / V_81 ;
V_113 = ( V_28 -> V_128 - V_2 -> V_129 ) / V_81 ;
V_117 = ( V_28 -> V_130 - V_2 -> V_131 ) / V_81 ;
V_117 = F_35 ( T_1 , V_117 , V_114 ) ;
V_10 . V_62 = F_12 ( V_132 |
V_133 |
V_134 |
V_135 |
V_136 |
V_137 |
V_138 |
V_139 |
V_140 |
V_141 ) ;
V_112 = V_2 -> V_21 -> V_112 + V_142 + V_143 + V_144 ;
V_10 . V_145 = F_3 ( V_112 ) ;
V_10 . V_112 = F_3 ( V_112 ) ;
V_10 . V_146 = F_3 ( 1 ) ;
V_10 . V_147 = F_3 ( V_115 ) ;
V_10 . V_148 = F_3 ( V_113 ) ;
V_10 . V_149 = F_3 ( V_114 ) ;
V_10 . V_150 = F_3 ( V_118 ) ;
V_10 . V_151 = F_3 ( 4 ) ;
V_10 . V_152 = F_3 ( V_117 ) ;
V_10 . V_123 = F_3 ( V_116 ) ;
F_4 ( & V_2 -> V_19 ) ;
for ( V_82 = 0 ; V_82 < V_81 ; V_82 ++ ) {
int V_153 = V_113 ;
V_10 . V_43 = F_3 ( V_28 -> V_86 + V_82 ) ;
V_13 = F_5 ( V_2 , & V_10 , sizeof( V_10 ) ,
V_20 ) ;
if ( V_13 )
break;
V_28 -> V_29 = V_82 + 1 ;
V_28 -> V_4 [ V_82 ] . V_16 = F_36 ( V_10 . V_43 ) ;
V_13 = F_37 ( V_2 , V_28 -> V_4 [ V_82 ] . V_16 ,
& V_153 ) ;
if ( V_13 )
break;
V_119 += V_153 ;
}
F_7 ( & V_2 -> V_19 ) ;
if ( ! V_13 ) {
V_28 -> V_128 -= V_119 ;
V_28 -> V_125 -= V_114 * V_81 ;
V_28 -> V_127 -= V_118 * V_81 ;
V_28 -> V_120 -= V_115 * V_81 ;
V_28 -> V_154 -= V_81 ;
V_28 -> V_122 -= V_116 * V_81 ;
V_28 -> V_130 -= V_117 * V_81 ;
}
return V_13 ;
}
static int F_38 ( struct V_1 * V_2 , int * V_81 )
{
int V_13 = 0 , V_155 ;
int V_156 , V_157 , V_158 ;
int V_159 = 0 , V_160 = 0 , V_161 = 0 ;
V_155 = * V_81 ;
while ( V_155 ) {
V_156 = V_155 ;
V_157 = V_155 ;
V_158 = V_155 ;
if ( V_2 -> V_38 & V_124 ) {
if ( V_2 -> V_28 . V_125 - V_2 -> V_126 * 2 >=
V_156 )
V_160 = 1 ;
} else {
if ( V_2 -> V_28 . V_125 - V_2 -> V_126 >=
V_156 )
V_160 = 1 ;
}
if ( V_2 -> V_28 . V_130 - V_2 -> V_131 < V_156 )
V_160 = 0 ;
if ( V_2 -> V_28 . V_128 - V_2 -> V_129 >= V_157 )
V_159 = 1 ;
if ( V_2 -> V_28 . V_154 - V_2 -> V_162 >= V_158 )
V_161 = 1 ;
if ( V_159 && V_160 && V_161 )
break;
V_155 -- ;
}
if ( ! V_155 ) {
F_6 ( V_2 -> V_21 , L_10 ) ;
return - V_27 ;
}
if ( V_155 != * V_81 ) {
F_21 ( V_2 -> V_21 , L_11 ,
* V_81 , V_155 ) ;
* V_81 = V_155 ;
}
V_13 = F_28 ( V_2 , * V_81 ) ;
if ( V_13 )
goto V_163;
V_13 = F_34 ( V_2 , * V_81 ) ;
if ( V_13 )
goto V_164;
V_13 = F_32 ( V_2 ) ;
if ( V_13 )
goto V_164;
F_39 ( V_2 , * V_81 ) ;
V_13 = F_40 ( V_2 -> V_88 , * V_81 ) ;
if ( V_13 )
goto V_164;
return 0 ;
V_164:
F_24 ( V_2 , * V_81 ) ;
V_163:
F_25 ( V_2 ) ;
return V_13 ;
}
void F_41 ( struct V_1 * V_2 )
{
T_1 V_81 = F_42 ( V_2 -> V_88 ) ;
if ( ! V_81 )
return;
if ( F_43 ( V_2 -> V_88 ) ) {
F_1 (
V_2 , NULL , V_165 ) ;
F_44 ( V_2 -> V_21 , L_12 ,
V_81 ) ;
} else {
F_45 ( V_2 -> V_88 ) ;
F_24 ( V_2 , V_81 ) ;
}
F_25 ( V_2 ) ;
V_2 -> V_28 . V_29 = 0 ;
F_46 () ;
F_47 ( V_2 ) ;
F_48 () ;
F_39 ( V_2 , 0 ) ;
}
int F_49 ( struct V_87 * V_88 , int V_81 )
{
struct V_31 * V_21 = F_50 ( V_88 ) ;
struct V_1 * V_2 = F_11 ( V_21 ) ;
if ( ! ( V_2 -> V_38 & V_166 ) ) {
F_44 ( V_21 , L_13 ) ;
return 0 ;
}
F_46 () ;
if ( ! F_51 ( V_21 ) ) {
F_44 ( V_21 , L_14 ) ;
F_48 () ;
return 0 ;
}
V_2 -> V_167 = true ;
F_48 () ;
if ( F_43 ( V_2 -> V_88 ) ) {
F_44 ( V_21 , L_15 ) ;
V_81 = 0 ;
goto V_168;
}
if ( V_81 && V_81 == V_2 -> V_28 . V_29 )
goto V_168;
F_41 ( V_2 ) ;
if ( ! V_81 )
goto V_168;
F_38 ( V_2 , & V_81 ) ;
V_168:
V_2 -> V_167 = false ;
F_52 ( & V_2 -> V_169 ) ;
return V_81 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_170 , T_5 V_171 ,
T_6 V_172 , T_2 V_173 )
{
int V_13 = 0 ;
struct V_174 V_10 = { 0 } ;
struct V_175 * V_7 = V_2 -> V_8 ;
F_2 ( V_2 , & V_10 , V_176 , - 1 , - 1 ) ;
V_10 . V_177 = F_3 ( V_4 -> V_16 ) ;
V_10 . V_178 = F_3 ( V_4 -> V_16 ) ;
V_10 . V_179 = F_3 ( V_173 ) ;
V_10 . V_171 = V_171 ;
V_10 . V_180 = V_172 ;
memcpy ( V_10 . V_170 , V_170 , V_173 ) ;
F_4 ( & V_2 -> V_19 ) ;
V_13 = F_5 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) ;
if ( V_13 ) {
F_6 ( V_2 -> V_21 , L_16 , V_13 ) ;
goto V_181;
}
if ( V_7 -> V_23 ) {
F_6 ( V_2 -> V_21 , L_17 ,
V_7 -> V_23 ) ;
V_13 = - 1 ;
}
V_181:
F_7 ( & V_2 -> V_19 ) ;
return V_13 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_173 )
{
int V_13 = 0 ;
struct V_182 V_10 = { 0 } ;
struct V_183 * V_7 = V_2 -> V_8 ;
F_2 ( V_2 , & V_10 , V_184 , - 1 , - 1 ) ;
V_10 . V_177 = F_3 ( V_4 -> V_16 ) ;
V_10 . V_178 = F_3 ( V_4 -> V_16 ) ;
memcpy ( V_10 . V_185 , V_4 -> V_90 , V_173 ) ;
F_4 ( & V_2 -> V_19 ) ;
V_13 = F_5 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) ;
if ( V_13 ) {
F_6 ( V_2 -> V_21 , L_18 , V_13 ) ;
goto V_186;
}
if ( V_7 -> V_23 ) {
F_6 ( V_2 -> V_21 , L_19 ,
V_7 -> V_23 ) ;
V_13 = - 1 ;
}
V_186:
F_7 ( & V_2 -> V_19 ) ;
return V_13 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_173 )
{
int V_13 = 0 ;
struct V_187 V_10 = { 0 } ;
struct V_188 * V_7 = V_2 -> V_8 ;
F_2 ( V_2 , & V_10 , V_189 , - 1 , - 1 ) ;
V_10 . V_177 = F_3 ( V_4 -> V_16 ) ;
V_10 . V_178 = F_3 ( V_4 -> V_16 ) ;
memcpy ( V_10 . V_185 , V_4 -> V_90 , V_173 ) ;
F_4 ( & V_2 -> V_19 ) ;
V_13 = F_5 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) ;
if ( V_13 ) {
F_6 ( V_2 -> V_21 , L_20 , V_13 ) ;
goto V_190;
}
if ( V_7 -> V_23 ) {
F_6 ( V_2 -> V_21 , L_21 ,
V_7 -> V_23 ) ;
V_13 = - 1 ;
}
V_190:
F_7 ( & V_2 -> V_19 ) ;
return V_13 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_173 = sizeof( struct V_191 ) ;
struct V_191 * V_10 =
(struct V_191 * ) V_4 -> V_90 ;
if ( ! F_57 ( V_4 -> V_47 ) ||
F_58 ( ( const T_3 * ) V_10 -> V_192 , V_4 -> V_47 ) )
return F_55 ( V_2 , V_4 , V_173 ) ;
else
return F_54 ( V_2 , V_4 , V_173 ) ;
}
static int F_59 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_13 = 0 ;
if ( ! ( V_4 -> V_38 & V_56 ) ) {
V_13 = F_55 (
V_2 , V_4 , sizeof( struct V_193 ) ) ;
} else {
struct V_194 V_195 ;
struct V_193 * V_196 ;
V_196 =
(struct V_193 * ) V_4 -> V_90 ;
F_4 ( & V_2 -> V_19 ) ;
memcpy ( & V_195 , & V_2 -> V_73 . V_195 ,
sizeof( V_195 ) ) ;
F_7 ( & V_2 -> V_19 ) ;
V_195 . V_197 = V_196 -> V_197 ;
if ( V_4 -> V_38 & V_59 ) {
if ( V_195 . V_79 !=
V_198 ) {
V_195 . V_79 =
V_198 ;
V_195 . V_74 = F_3 (
V_199 ) ;
V_195 . V_200 =
V_201 ;
V_195 . V_202 =
( V_203 |
V_204 ) ;
}
} else {
V_195 . V_79 = V_205 ;
V_195 . V_74 = 0 ;
V_195 . V_200 = V_206 ;
V_195 . V_202 = 0 ;
}
V_13 = F_53 ( V_2 , V_4 , & V_195 ,
V_196 -> V_207 ,
V_196 -> V_208 ,
sizeof( V_195 ) ) ;
}
return V_13 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_13 = 0 ;
struct V_209 * V_210 = V_4 -> V_90 ;
T_2 V_211 = F_36 ( V_210 -> V_211 ) ;
switch ( V_211 ) {
case V_212 :
V_13 = F_56 ( V_2 , V_4 ) ;
break;
case V_42 :
V_13 = F_55 (
V_2 , V_4 , sizeof( struct V_33 ) ) ;
break;
case V_213 :
V_13 = F_59 ( V_2 , V_4 ) ;
break;
default:
break;
}
return V_13 ;
}
void F_61 ( struct V_1 * V_2 )
{
T_2 V_82 = 0 , V_29 = V_2 -> V_28 . V_29 , V_24 ;
while ( 1 ) {
V_24 = F_62 ( V_2 -> V_28 . V_89 , V_29 , V_82 ) ;
if ( V_24 >= V_29 )
break;
F_63 ( V_24 , V_2 -> V_28 . V_89 ) ;
F_60 ( V_2 , & V_2 -> V_28 . V_4 [ V_24 ] ) ;
V_82 = V_24 + 1 ;
}
}
void F_64 ( struct V_1 * V_2 )
{
struct V_214 V_10 = { 0 } ;
struct V_215 * V_7 = V_2 -> V_8 ;
F_2 ( V_2 , & V_10 , V_216 , - 1 , - 1 ) ;
V_10 . V_43 = F_3 ( 0xffff ) ;
F_4 ( & V_2 -> V_19 ) ;
if ( F_5 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) )
goto V_217;
if ( ! F_58 ( V_7 -> V_218 , V_2 -> V_4 . V_47 ) )
memcpy ( V_2 -> V_4 . V_47 , V_7 -> V_218 , V_48 ) ;
if ( F_57 ( V_2 -> V_4 . V_47 ) )
memcpy ( V_2 -> V_21 -> V_219 , V_2 -> V_4 . V_47 , V_48 ) ;
V_217:
F_7 ( & V_2 -> V_19 ) ;
}
int F_65 ( struct V_1 * V_2 , T_3 * V_46 )
{
struct V_220 V_10 = { 0 } ;
int V_13 = 0 ;
if ( ! F_66 ( V_2 ) )
return 0 ;
if ( V_2 -> V_36 < 0x10202 ) {
if ( F_57 ( V_2 -> V_4 . V_47 ) )
V_13 = - V_221 ;
goto V_222;
}
F_2 ( V_2 , & V_10 , V_223 , - 1 , - 1 ) ;
V_10 . V_62 = F_12 ( V_224 ) ;
memcpy ( V_10 . V_64 , V_46 , V_48 ) ;
V_13 = F_13 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) ;
V_222:
if ( V_13 ) {
V_13 = - V_221 ;
F_44 ( V_2 -> V_21 , L_22 ,
V_46 ) ;
}
return V_13 ;
}
void F_41 ( struct V_1 * V_2 )
{
}
void F_61 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_21 , L_23 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
}
int F_65 ( struct V_1 * V_2 , T_3 * V_46 )
{
return 0 ;
}
