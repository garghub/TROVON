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
V_13 = F_8 ( V_2 , V_24 ) ;
if ( V_13 )
return V_13 ;
V_4 = & V_2 -> V_28 . V_4 [ V_24 ] ;
if ( V_4 -> V_36 & V_37 )
V_34 = true ;
if ( V_34 == V_32 )
return 0 ;
V_35 = V_4 -> V_35 ;
if ( V_32 )
V_35 |= V_38 ;
else
V_35 &= ~ V_38 ;
F_2 ( V_2 , & V_10 , V_39 , - 1 , - 1 ) ;
V_10 . V_40 = F_3 ( V_4 -> V_16 ) ;
V_10 . V_36 = F_12 ( V_35 ) ;
V_13 = F_13 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) ;
if ( ! V_13 ) {
V_4 -> V_35 = V_35 ;
if ( V_32 )
V_4 -> V_36 |= V_37 ;
else
V_4 -> V_36 &= ~ V_37 ;
}
return V_13 ;
}
int F_14 ( struct V_31 * V_21 , int V_24 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_11 ( V_21 ) ;
struct V_3 * V_4 ;
int V_13 ;
V_13 = F_8 ( V_2 , V_24 ) ;
if ( V_13 )
return V_13 ;
V_42 -> V_4 = V_24 ;
V_4 = & V_2 -> V_28 . V_4 [ V_24 ] ;
memcpy ( & V_42 -> V_43 , V_4 -> V_44 , V_45 ) ;
V_42 -> V_46 = V_4 -> V_46 ;
V_42 -> V_47 = V_4 -> V_47 ;
V_42 -> V_48 = V_4 -> V_48 ;
V_42 -> V_49 = V_4 -> V_36 & V_50 ;
V_42 -> V_51 = V_4 -> V_36 & V_37 ;
if ( ! ( V_4 -> V_36 & V_52 ) )
V_42 -> V_53 = V_54 ;
else if ( V_4 -> V_36 & V_55 )
V_42 -> V_53 = V_56 ;
else
V_42 -> V_53 = V_57 ;
return 0 ;
}
int F_15 ( struct V_31 * V_21 , int V_24 , T_3 * V_43 )
{
struct V_33 V_10 = { 0 } ;
struct V_1 * V_2 = F_11 ( V_21 ) ;
struct V_3 * V_4 ;
int V_13 ;
V_13 = F_8 ( V_2 , V_24 ) ;
if ( V_13 )
return V_13 ;
if ( F_16 ( V_43 ) ) {
F_6 ( V_21 , L_6 ) ;
return - V_27 ;
}
V_4 = & V_2 -> V_28 . V_4 [ V_24 ] ;
memcpy ( V_4 -> V_44 , V_43 , V_45 ) ;
F_2 ( V_2 , & V_10 , V_39 , - 1 , - 1 ) ;
V_10 . V_40 = F_3 ( V_4 -> V_16 ) ;
V_10 . V_36 = F_12 ( V_4 -> V_35 ) ;
V_10 . V_58 = F_12 ( V_59 ) ;
memcpy ( V_10 . V_60 , V_43 , V_45 ) ;
return F_13 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) ;
}
int F_17 ( struct V_31 * V_21 , int V_24 , T_1 V_61 , T_3 V_49 ,
T_4 V_62 )
{
struct V_33 V_10 = { 0 } ;
struct V_1 * V_2 = F_11 ( V_21 ) ;
struct V_3 * V_4 ;
T_1 V_63 ;
int V_13 ;
if ( V_2 -> V_64 < 0x10201 )
return - V_65 ;
if ( V_62 != F_18 ( V_66 ) )
return - V_67 ;
V_13 = F_8 ( V_2 , V_24 ) ;
if ( V_13 )
return V_13 ;
if ( V_61 > 4095 || V_49 )
return - V_27 ;
V_4 = & V_2 -> V_28 . V_4 [ V_24 ] ;
V_63 = V_61 ;
if ( V_63 == V_4 -> V_48 )
return 0 ;
F_2 ( V_2 , & V_10 , V_39 , - 1 , - 1 ) ;
V_10 . V_40 = F_3 ( V_4 -> V_16 ) ;
V_10 . V_36 = F_12 ( V_4 -> V_35 ) ;
V_10 . V_68 = F_3 ( V_63 ) ;
V_10 . V_58 = F_12 ( V_69 ) ;
V_13 = F_13 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) ;
if ( ! V_13 )
V_4 -> V_48 = V_63 ;
return V_13 ;
}
int F_19 ( struct V_31 * V_21 , int V_24 , int V_47 ,
int V_46 )
{
struct V_33 V_10 = { 0 } ;
struct V_1 * V_2 = F_11 ( V_21 ) ;
struct V_3 * V_4 ;
T_2 V_70 ;
int V_13 ;
V_13 = F_8 ( V_2 , V_24 ) ;
if ( V_13 )
return V_13 ;
V_4 = & V_2 -> V_28 . V_4 [ V_24 ] ;
V_70 = F_20 ( V_2 -> V_71 . V_72 ) ;
if ( V_46 > V_70 ) {
F_21 ( V_2 -> V_21 , L_7 ,
V_46 , V_24 ) ;
return - V_27 ;
}
if ( V_47 > V_70 || V_47 > V_46 ) {
F_21 ( V_2 -> V_21 , L_8 ,
V_47 , V_24 ) ;
return - V_27 ;
}
if ( V_47 == V_4 -> V_47 && V_46 == V_4 -> V_46 )
return 0 ;
F_2 ( V_2 , & V_10 , V_39 , - 1 , - 1 ) ;
V_10 . V_40 = F_3 ( V_4 -> V_16 ) ;
V_10 . V_36 = F_12 ( V_4 -> V_35 ) ;
V_10 . V_58 = F_12 ( V_73 ) ;
V_10 . V_74 = F_12 ( V_46 ) ;
V_10 . V_58 |= F_12 ( V_75 ) ;
V_10 . V_76 = F_12 ( V_47 ) ;
V_13 = F_13 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) ;
if ( ! V_13 ) {
V_4 -> V_47 = V_47 ;
V_4 -> V_46 = V_46 ;
}
return V_13 ;
}
int F_22 ( struct V_31 * V_21 , int V_24 , int V_77 )
{
struct V_1 * V_2 = F_11 ( V_21 ) ;
struct V_3 * V_4 ;
int V_13 ;
V_13 = F_8 ( V_2 , V_24 ) ;
if ( V_13 )
return V_13 ;
V_4 = & V_2 -> V_28 . V_4 [ V_24 ] ;
V_4 -> V_36 &= ~ ( V_55 | V_52 ) ;
switch ( V_77 ) {
case V_54 :
V_4 -> V_36 |= V_55 ;
break;
case V_57 :
V_4 -> V_36 |= V_52 ;
break;
case V_56 :
V_4 -> V_36 |= V_55 | V_52 ;
break;
default:
F_6 ( V_2 -> V_21 , L_9 ) ;
V_13 = - V_27 ;
break;
}
if ( V_4 -> V_36 & ( V_55 | V_52 ) )
V_13 = F_1 ( V_2 , V_4 ,
V_78 ) ;
return V_13 ;
}
static int F_23 ( struct V_1 * V_2 , int V_79 )
{
int V_80 ;
struct V_3 * V_4 ;
for ( V_80 = 0 ; V_80 < V_79 ; V_80 ++ ) {
V_4 = & V_2 -> V_28 . V_4 [ V_80 ] ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_36 = V_50 | V_55 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int V_79 )
{
int V_80 , V_13 = 0 ;
struct V_81 * V_28 = & V_2 -> V_28 ;
struct V_82 V_10 = { 0 } ;
F_2 ( V_2 , & V_10 , V_83 , - 1 , - 1 ) ;
F_4 ( & V_2 -> V_19 ) ;
for ( V_80 = V_28 -> V_84 ; V_80 < V_28 -> V_84 + V_79 ; V_80 ++ ) {
V_10 . V_24 = F_3 ( V_80 ) ;
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
struct V_85 * V_86 = V_2 -> V_86 ;
int V_80 ;
F_26 ( V_2 -> V_28 . V_87 ) ;
V_2 -> V_28 . V_87 = NULL ;
for ( V_80 = 0 ; V_80 < 4 ; V_80 ++ ) {
if ( V_2 -> V_28 . V_88 [ V_80 ] ) {
F_27 ( & V_86 -> V_21 , V_89 ,
V_2 -> V_28 . V_88 [ V_80 ] ,
V_2 -> V_28 . V_90 [ V_80 ] ) ;
V_2 -> V_28 . V_88 [ V_80 ] = NULL ;
}
}
F_26 ( V_2 -> V_28 . V_4 ) ;
V_2 -> V_28 . V_4 = NULL ;
}
static int F_28 ( struct V_1 * V_2 , int V_79 )
{
struct V_85 * V_86 = V_2 -> V_86 ;
T_2 V_91 , V_92 , V_80 , V_93 , V_94 = 0 ;
V_2 -> V_28 . V_4 = F_29 ( V_79 , sizeof( struct V_3 ) , V_95 ) ;
if ( ! V_2 -> V_28 . V_4 )
return - V_96 ;
F_23 ( V_2 , V_79 ) ;
V_92 = V_79 * V_97 ;
V_91 = V_92 / V_89 ;
if ( V_92 & ( V_89 - 1 ) )
V_91 ++ ;
for ( V_80 = 0 ; V_80 < V_91 ; V_80 ++ ) {
V_2 -> V_28 . V_88 [ V_80 ] =
F_30 ( & V_86 -> V_21 , V_89 ,
& V_2 -> V_28 . V_90 [ V_80 ] ,
V_95 ) ;
if ( ! V_2 -> V_28 . V_88 [ V_80 ] )
return - V_96 ;
for ( V_93 = 0 ; V_93 < V_98 && V_94 < V_79 ; V_93 ++ ) {
struct V_3 * V_4 = & V_2 -> V_28 . V_4 [ V_94 ] ;
V_4 -> V_88 = V_2 -> V_28 . V_88 [ V_80 ] +
V_93 * V_97 ;
V_4 -> V_90 =
V_2 -> V_28 . V_90 [ V_80 ] + V_93 *
V_97 ;
V_94 ++ ;
}
}
V_2 -> V_28 . V_87 = F_31 ( 16 , V_95 ) ;
if ( ! V_2 -> V_28 . V_87 )
return - V_96 ;
V_2 -> V_28 . V_99 = V_91 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_100 V_10 = { 0 } ;
F_2 ( V_2 , & V_10 , V_101 , - 1 , - 1 ) ;
V_10 . V_102 = F_3 ( V_2 -> V_28 . V_99 ) ;
V_10 . V_103 = F_3 ( V_104 ) ;
V_10 . V_105 = F_3 ( V_97 ) ;
V_10 . V_106 = F_33 ( V_2 -> V_28 . V_90 [ 0 ] ) ;
V_10 . V_107 = F_33 ( V_2 -> V_28 . V_90 [ 1 ] ) ;
V_10 . V_108 = F_33 ( V_2 -> V_28 . V_90 [ 2 ] ) ;
V_10 . V_109 = F_33 ( V_2 -> V_28 . V_90 [ 3 ] ) ;
return F_13 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) ;
}
static int F_34 ( struct V_1 * V_2 , int V_79 )
{
T_2 V_13 = 0 , V_110 , V_80 ;
T_1 V_111 , V_112 , V_113 , V_114 , V_115 ;
T_1 V_116 ;
struct V_33 V_10 = { 0 } ;
struct V_81 * V_28 = & V_2 -> V_28 ;
F_2 ( V_2 , & V_10 , V_39 , - 1 , - 1 ) ;
V_113 = ( V_28 -> V_117 - V_2 -> V_118 ) / V_79 ;
V_114 = ( V_28 -> V_119 - V_2 -> V_120 ) / V_79 ;
if ( V_2 -> V_36 & V_121 )
V_112 = ( V_28 -> V_122 - V_2 -> V_123 * 2 ) /
V_79 ;
else
V_112 = ( V_28 -> V_122 - V_2 -> V_123 ) / V_79 ;
V_116 = ( V_2 -> V_28 . V_124 - V_2 -> V_123 ) / V_79 ;
V_111 = ( V_28 -> V_125 - V_2 -> V_126 ) / V_79 ;
V_10 . V_58 = F_12 ( V_127 |
V_128 |
V_129 |
V_130 |
V_131 |
V_132 |
V_133 |
V_134 |
V_135 |
V_136 ) ;
V_110 = V_2 -> V_21 -> V_110 + V_137 + V_138 + V_139 ;
V_10 . V_140 = F_3 ( V_110 ) ;
V_10 . V_110 = F_3 ( V_110 ) ;
V_10 . V_141 = F_3 ( 1 ) ;
V_10 . V_142 = F_3 ( V_113 ) ;
V_10 . V_143 = F_3 ( V_111 ) ;
V_10 . V_144 = F_3 ( V_112 ) ;
V_10 . V_145 = F_3 ( V_116 ) ;
V_10 . V_146 = F_3 ( 4 ) ;
V_115 = 1 ;
V_10 . V_147 = F_3 ( V_115 ) ;
V_10 . V_120 = F_3 ( V_114 ) ;
F_4 ( & V_2 -> V_19 ) ;
for ( V_80 = 0 ; V_80 < V_79 ; V_80 ++ ) {
V_10 . V_40 = F_3 ( V_28 -> V_84 + V_80 ) ;
V_13 = F_5 ( V_2 , & V_10 , sizeof( V_10 ) ,
V_20 ) ;
if ( V_13 )
break;
V_28 -> V_29 = V_80 + 1 ;
V_28 -> V_4 [ V_80 ] . V_16 = F_35 ( V_10 . V_40 ) ;
}
F_7 ( & V_2 -> V_19 ) ;
if ( ! V_13 ) {
V_28 -> V_125 -= V_111 * V_79 ;
V_28 -> V_122 -= V_112 * V_79 ;
V_28 -> V_124 -= V_116 * V_79 ;
V_28 -> V_117 -= V_113 * V_79 ;
V_28 -> V_148 -= V_79 ;
V_28 -> V_119 -= V_114 * V_79 ;
V_28 -> V_149 -= V_115 * V_79 ;
}
return V_13 ;
}
static int F_36 ( struct V_1 * V_2 , int * V_79 )
{
int V_13 = 0 , V_150 ;
int V_151 , V_152 , V_153 ;
int V_154 = 0 , V_155 = 0 , V_156 = 0 ;
V_150 = * V_79 ;
while ( V_150 ) {
V_151 = V_150 ;
V_152 = V_150 ;
V_153 = V_150 ;
if ( V_2 -> V_36 & V_121 ) {
if ( V_2 -> V_28 . V_122 - V_2 -> V_123 * 2 >=
V_151 )
V_155 = 1 ;
} else {
if ( V_2 -> V_28 . V_122 - V_2 -> V_123 >=
V_151 )
V_155 = 1 ;
}
if ( V_2 -> V_28 . V_125 - V_2 -> V_126 >= V_152 )
V_154 = 1 ;
if ( V_2 -> V_28 . V_148 - V_2 -> V_157 >= V_153 )
V_156 = 1 ;
if ( V_154 && V_155 && V_156 )
break;
V_150 -- ;
}
if ( ! V_150 ) {
F_6 ( V_2 -> V_21 , L_10 ) ;
return - V_27 ;
}
if ( V_150 != * V_79 ) {
F_21 ( V_2 -> V_21 , L_11 ,
* V_79 , V_150 ) ;
* V_79 = V_150 ;
}
V_13 = F_28 ( V_2 , * V_79 ) ;
if ( V_13 )
goto V_158;
V_13 = F_34 ( V_2 , * V_79 ) ;
if ( V_13 )
goto V_159;
V_13 = F_32 ( V_2 ) ;
if ( V_13 )
goto V_159;
V_13 = F_37 ( V_2 -> V_86 , * V_79 ) ;
if ( V_13 )
goto V_159;
return 0 ;
V_159:
F_24 ( V_2 , * V_79 ) ;
V_158:
F_25 ( V_2 ) ;
return V_13 ;
}
void F_38 ( struct V_1 * V_2 )
{
T_1 V_79 = F_39 ( V_2 -> V_86 ) ;
if ( ! V_79 )
return;
if ( F_40 ( V_2 -> V_86 ) ) {
F_1 (
V_2 , NULL , V_160 ) ;
F_41 ( V_2 -> V_21 , L_12 ,
V_79 ) ;
} else {
F_42 ( V_2 -> V_86 ) ;
F_24 ( V_2 , V_79 ) ;
}
F_25 ( V_2 ) ;
V_2 -> V_28 . V_29 = 0 ;
F_43 () ;
F_44 ( V_2 ) ;
F_45 () ;
}
int F_46 ( struct V_85 * V_86 , int V_79 )
{
struct V_31 * V_21 = F_47 ( V_86 ) ;
struct V_1 * V_2 = F_11 ( V_21 ) ;
if ( ! ( V_2 -> V_36 & V_161 ) ) {
F_41 ( V_21 , L_13 ) ;
return 0 ;
}
F_43 () ;
if ( ! F_48 ( V_21 ) ) {
F_41 ( V_21 , L_14 ) ;
F_45 () ;
return 0 ;
}
V_2 -> V_162 = true ;
F_45 () ;
if ( F_40 ( V_2 -> V_86 ) ) {
F_41 ( V_21 , L_15 ) ;
V_79 = 0 ;
goto V_163;
}
if ( V_79 && V_79 == V_2 -> V_28 . V_29 )
goto V_163;
F_38 ( V_2 ) ;
if ( ! V_79 )
goto V_163;
F_36 ( V_2 , & V_79 ) ;
V_163:
V_2 -> V_162 = false ;
F_49 ( & V_2 -> V_164 ) ;
return V_79 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_165 , T_5 V_166 ,
T_6 V_167 , T_2 V_168 )
{
int V_13 = 0 ;
struct V_169 V_10 = { 0 } ;
struct V_170 * V_7 = V_2 -> V_8 ;
F_2 ( V_2 , & V_10 , V_171 , - 1 , - 1 ) ;
V_10 . V_172 = F_3 ( V_4 -> V_16 ) ;
V_10 . V_173 = F_3 ( V_4 -> V_16 ) ;
V_10 . V_174 = F_3 ( V_168 ) ;
V_10 . V_166 = V_166 ;
V_10 . V_175 = V_167 ;
memcpy ( V_10 . V_165 , V_165 , V_168 ) ;
F_4 ( & V_2 -> V_19 ) ;
V_13 = F_5 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) ;
if ( V_13 ) {
F_6 ( V_2 -> V_21 , L_16 , V_13 ) ;
goto V_176;
}
if ( V_7 -> V_23 ) {
F_6 ( V_2 -> V_21 , L_17 ,
V_7 -> V_23 ) ;
V_13 = - 1 ;
}
V_176:
F_7 ( & V_2 -> V_19 ) ;
return V_13 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_168 )
{
int V_13 = 0 ;
struct V_177 V_10 = { 0 } ;
struct V_178 * V_7 = V_2 -> V_8 ;
F_2 ( V_2 , & V_10 , V_179 , - 1 , - 1 ) ;
V_10 . V_172 = F_3 ( V_4 -> V_16 ) ;
V_10 . V_173 = F_3 ( V_4 -> V_16 ) ;
memcpy ( V_10 . V_180 , V_4 -> V_88 , V_168 ) ;
F_4 ( & V_2 -> V_19 ) ;
V_13 = F_5 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) ;
if ( V_13 ) {
F_6 ( V_2 -> V_21 , L_18 , V_13 ) ;
goto V_181;
}
if ( V_7 -> V_23 ) {
F_6 ( V_2 -> V_21 , L_19 ,
V_7 -> V_23 ) ;
V_13 = - 1 ;
}
V_181:
F_7 ( & V_2 -> V_19 ) ;
return V_13 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_168 )
{
int V_13 = 0 ;
struct V_182 V_10 = { 0 } ;
struct V_183 * V_7 = V_2 -> V_8 ;
F_2 ( V_2 , & V_10 , V_184 , - 1 , - 1 ) ;
V_10 . V_172 = F_3 ( V_4 -> V_16 ) ;
V_10 . V_173 = F_3 ( V_4 -> V_16 ) ;
memcpy ( V_10 . V_180 , V_4 -> V_88 , V_168 ) ;
F_4 ( & V_2 -> V_19 ) ;
V_13 = F_5 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) ;
if ( V_13 ) {
F_6 ( V_2 -> V_21 , L_20 , V_13 ) ;
goto V_185;
}
if ( V_7 -> V_23 ) {
F_6 ( V_2 -> V_21 , L_21 ,
V_7 -> V_23 ) ;
V_13 = - 1 ;
}
V_185:
F_7 ( & V_2 -> V_19 ) ;
return V_13 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_168 = sizeof( struct V_186 ) ;
struct V_186 * V_10 =
(struct V_186 * ) V_4 -> V_88 ;
if ( ! F_54 ( V_4 -> V_44 ) ||
F_55 ( ( const T_3 * ) V_10 -> V_187 , V_4 -> V_44 ) )
return F_52 ( V_2 , V_4 , V_168 ) ;
else
return F_51 ( V_2 , V_4 , V_168 ) ;
}
static int F_56 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_13 = 0 ;
if ( ! ( V_4 -> V_36 & V_52 ) ) {
V_13 = F_52 (
V_2 , V_4 , sizeof( struct V_188 ) ) ;
} else {
struct V_189 V_190 ;
struct V_188 * V_191 ;
V_191 =
(struct V_188 * ) V_4 -> V_88 ;
F_4 ( & V_2 -> V_19 ) ;
memcpy ( & V_190 , & V_2 -> V_71 . V_190 ,
sizeof( V_190 ) ) ;
F_7 ( & V_2 -> V_19 ) ;
V_190 . V_192 = V_191 -> V_192 ;
if ( V_4 -> V_36 & V_55 ) {
if ( V_190 . V_77 !=
V_193 ) {
V_190 . V_77 =
V_193 ;
V_190 . V_72 = F_3 (
V_194 ) ;
V_190 . V_195 =
V_196 ;
V_190 . V_197 =
( V_198 |
V_199 ) ;
}
} else {
V_190 . V_77 = V_200 ;
V_190 . V_72 = 0 ;
V_190 . V_195 = V_201 ;
V_190 . V_197 = 0 ;
}
V_13 = F_50 ( V_2 , V_4 , & V_190 ,
V_191 -> V_202 ,
V_191 -> V_203 ,
sizeof( V_190 ) ) ;
}
return V_13 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_13 = 0 ;
struct V_204 * V_205 = V_4 -> V_88 ;
T_2 V_206 = F_35 ( V_205 -> V_206 ) ;
switch ( V_206 ) {
case V_207 :
V_13 = F_53 ( V_2 , V_4 ) ;
break;
case V_39 :
V_13 = F_52 (
V_2 , V_4 , sizeof( struct V_33 ) ) ;
break;
case V_208 :
V_13 = F_56 ( V_2 , V_4 ) ;
break;
default:
break;
}
return V_13 ;
}
void F_58 ( struct V_1 * V_2 )
{
T_2 V_80 = 0 , V_29 = V_2 -> V_28 . V_29 , V_24 ;
while ( 1 ) {
V_24 = F_59 ( V_2 -> V_28 . V_87 , V_29 , V_80 ) ;
if ( V_24 >= V_29 )
break;
F_60 ( V_24 , V_2 -> V_28 . V_87 ) ;
F_57 ( V_2 , & V_2 -> V_28 . V_4 [ V_24 ] ) ;
V_80 = V_24 + 1 ;
}
}
void F_61 ( struct V_1 * V_2 )
{
struct V_209 V_10 = { 0 } ;
struct V_210 * V_7 = V_2 -> V_8 ;
F_2 ( V_2 , & V_10 , V_211 , - 1 , - 1 ) ;
V_10 . V_40 = F_3 ( 0xffff ) ;
F_4 ( & V_2 -> V_19 ) ;
if ( F_5 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) )
goto V_212;
if ( ! F_55 ( V_7 -> V_213 , V_2 -> V_4 . V_44 ) )
memcpy ( V_2 -> V_4 . V_44 , V_7 -> V_213 , V_45 ) ;
if ( F_54 ( V_2 -> V_4 . V_44 ) )
memcpy ( V_2 -> V_21 -> V_214 , V_2 -> V_4 . V_44 , V_45 ) ;
V_212:
F_7 ( & V_2 -> V_19 ) ;
}
int F_62 ( struct V_1 * V_2 , T_3 * V_43 )
{
struct V_215 V_10 = { 0 } ;
int V_13 = 0 ;
if ( ! F_63 ( V_2 ) )
return 0 ;
if ( V_2 -> V_64 < 0x10202 ) {
if ( F_54 ( V_2 -> V_4 . V_44 ) )
V_13 = - V_216 ;
goto V_217;
}
F_2 ( V_2 , & V_10 , V_218 , - 1 , - 1 ) ;
V_10 . V_58 = F_12 ( V_219 ) ;
memcpy ( V_10 . V_60 , V_43 , V_45 ) ;
V_13 = F_13 ( V_2 , & V_10 , sizeof( V_10 ) , V_20 ) ;
V_217:
if ( V_13 ) {
V_13 = - V_216 ;
F_41 ( V_2 -> V_21 , L_22 ,
V_43 ) ;
}
return V_13 ;
}
void F_38 ( struct V_1 * V_2 )
{
}
void F_58 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_21 , L_23 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
}
int F_62 ( struct V_1 * V_2 , T_3 * V_43 )
{
return 0 ;
}
