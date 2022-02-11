static inline bool F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return V_5 -> V_6 [ V_3 ] -> V_7 == V_2 -> V_7 ;
}
static inline bool F_2 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_8 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return V_8 < V_5 -> V_6 [ V_3 ] -> V_9 ;
}
static inline bool F_3 ( struct V_1 * V_2 , T_1 V_10 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return V_10 < V_5 -> V_11 . V_12 . V_13 ;
}
static T_2 F_4 ( struct V_1 * V_2 , T_1 V_14 ,
T_1 V_15 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 = V_5 -> V_6 [ V_14 ] ;
T_2 V_17 = V_18 ;
if ( F_5 ( V_6 -> V_19 . V_20 ) &
V_21 )
V_17 =
F_5 ( V_6 -> V_19 . V_22 [ V_15 ] ) ;
else
V_17 = F_5 ( V_6 -> V_19 . V_22 [ 0 ] ) +
V_15 ;
return V_17 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_14 ,
T_2 V_15 ,
enum V_23 V_24 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
bool V_26 = false ;
T_2 V_17 ;
int V_27 = 0 ;
T_3 V_28 ;
V_17 = F_4 ( V_2 , V_14 , V_15 ) ;
V_28 = F_7 ( V_11 , F_8 ( V_17 ) ) ;
switch ( V_24 ) {
case V_29 :
V_28 |= V_30 ;
V_26 = true ;
break;
case V_31 :
V_27 = ( V_28 & V_32 ) ? 0 : - V_33 ;
break;
case V_34 :
V_28 &= ~ V_30 ;
V_26 = true ;
break;
case V_35 :
V_27 = ( V_28 & V_32 ) ? - V_33 : 0 ;
break;
case V_36 :
V_28 |= V_37 ;
V_26 = true ;
break;
case V_38 :
V_27 = ( V_28 & V_32 ) ? - V_33 : 0 ;
if ( ! V_27 ) {
V_28 &= ~ V_37 ;
V_26 = true ;
}
break;
default:
V_27 = - V_39 ;
break;
}
if ( V_26 ) {
F_9 ( V_11 , F_8 ( V_17 ) , V_28 ) ;
F_10 ( V_11 ) ;
}
return V_27 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_14 ,
T_2 V_15 ,
enum V_23 V_24 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
bool V_26 = false ;
T_2 V_17 ;
int V_27 = 0 ;
T_3 V_28 ;
V_17 = F_4 ( V_2 , V_14 , V_15 ) ;
V_28 = F_7 ( V_11 , F_12 ( V_17 ) ) ;
switch ( V_24 ) {
case V_29 :
V_28 |= V_40 ;
V_26 = true ;
break;
case V_31 :
V_27 = ( V_28 & V_41 ) ? 0 : - V_33 ;
break;
case V_34 :
V_28 &= ~ V_40 ;
V_26 = true ;
break;
case V_35 :
V_27 = ( V_28 & V_41 ) ? - V_33 : 0 ;
break;
case V_36 :
V_28 |= V_42 ;
V_26 = true ;
break;
case V_38 :
V_27 = ( V_28 & V_41 ) ? - V_33 : 0 ;
if ( ! V_27 ) {
V_28 &= ~ V_42 ;
V_26 = true ;
}
break;
default:
V_27 = - V_39 ;
break;
}
if ( V_26 ) {
F_9 ( V_11 , F_12 ( V_17 ) , V_28 ) ;
F_10 ( V_11 ) ;
}
return V_27 ;
}
static void F_13 ( struct V_1 * V_2 , T_2 V_14 ,
struct V_43 * V_44 )
{
unsigned long V_45 = 0 , V_46 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
T_2 V_15 , V_17 ;
enum V_47 V_48 ;
T_2 V_49 , V_10 ;
T_3 V_28 , V_50 ;
T_2 V_51 = 0 ;
V_10 = V_44 -> V_10 ;
if ( 0 == V_10 )
V_50 = F_14 ( V_2 -> V_7 ) ;
else
V_50 = F_15 (
( V_5 -> V_11 . V_12 . V_13
* V_2 -> V_7 ) + ( V_10 - 1 ) ) ;
if ( V_44 -> V_52 == 0 && V_44 -> V_53 == 0 ) {
F_9 ( V_11 , V_50 , V_54 ) ;
goto V_55;
}
V_46 = V_44 -> V_52 ;
V_15 = F_16 ( & V_46 , V_56 ) ;
while ( V_15 < V_56 ) {
V_45 |= ( 1 <<
( V_57 *
V_15 ) ) ;
V_15 =
F_17 ( & V_46 , V_56 , V_15 + 1 ) ;
}
V_46 = V_44 -> V_53 ;
V_15 = F_16 ( & V_46 , V_56 ) ;
while ( V_15 < V_56 ) {
V_45 |= ( 1 <<
( V_57 * V_15
+ 1 ) ) ;
V_15 = F_17 ( & V_46 , V_56 ,
V_15 + 1 ) ;
}
V_49 = F_16 ( & V_45 ,
( V_56 *
V_57 ) ) ;
V_15 = V_49 / V_57 ;
V_48 = V_49 % V_57 ;
V_17 = F_4 ( V_2 , V_14 , V_15 ) ;
V_28 = ( ( V_48 << V_58 ) | V_17 ) ;
F_9 ( V_11 , V_50 , V_28 ) ;
while ( V_49 < ( V_56 * V_57 ) ) {
switch ( V_48 ) {
case V_59 :
V_50 = F_18 ( V_17 ) ;
V_51 = V_44 -> V_60 ;
break;
case V_61 :
V_50 = F_19 ( V_17 ) ;
V_51 = V_44 -> V_62 ;
break;
default:
break;
}
V_49 = F_17 ( & V_45 ,
( V_56 *
V_57 ) ,
V_49 + 1 ) ;
if ( V_49 < ( V_56 * V_57 ) ) {
V_15 = V_49 / V_57 ;
V_48 = V_49 % V_57 ;
V_17 = F_4 ( V_2 , V_14 ,
V_15 ) ;
} else {
V_17 = V_18 ;
V_48 = 0 ;
}
V_28 = ( V_10 ) |
( V_48 << V_63 ) |
( V_17 << V_64 ) |
( 1 << V_65 ) |
( V_51 << V_66 ) ;
F_9 ( V_11 , V_50 , V_28 ) ;
}
V_55:
F_10 ( V_11 ) ;
}
static int F_20 ( struct V_1 * V_2 , T_2 V_14 ,
T_2 V_15 ,
struct V_67 * V_19 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
struct V_68 V_69 ;
T_2 V_17 ;
T_3 V_70 ;
int V_27 = 0 ;
V_17 = F_4 ( V_2 , V_14 , V_15 ) ;
memset ( & V_69 , 0 , sizeof( struct V_68 ) ) ;
V_69 . V_71 = V_19 -> V_72 / 128 ;
V_69 . V_73 = V_19 -> V_74 ;
V_69 . V_75 = F_5 ( V_5 -> V_6 [ V_14 ] -> V_19 . V_76 [ 0 ] ) ;
V_69 . V_77 = 0 ;
V_27 = F_21 ( V_11 , V_17 ) ;
if ( V_27 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_1 ,
V_17 , V_27 ) ;
V_27 = - V_80 ;
goto V_81;
}
V_27 = F_23 ( V_11 , V_17 , & V_69 ) ;
if ( V_27 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_2 ,
V_17 , V_27 ) ;
V_27 = - V_80 ;
goto V_81;
}
V_70 = V_82 ;
V_70 |= ( ( V_11 -> V_83 << V_84 )
& V_85 ) ;
V_70 |= ( ( ( V_2 -> V_7 + V_11 -> V_12 . V_86 )
<< V_87 )
& V_88 ) ;
F_9 ( V_11 , F_24 ( V_17 ) , V_70 ) ;
F_10 ( V_11 ) ;
V_81:
return V_27 ;
}
static int F_25 ( struct V_1 * V_2 , T_2 V_14 ,
T_2 V_15 ,
struct V_89 * V_19 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
struct V_90 V_91 ;
T_2 V_17 ;
int V_27 = 0 ;
V_17 = F_4 ( V_2 , V_14 , V_15 ) ;
memset ( & V_91 , 0 , sizeof( struct V_90 ) ) ;
V_91 . V_71 = V_19 -> V_72 / 128 ;
V_91 . V_73 = V_19 -> V_74 ;
if ( V_19 -> V_92 ) {
V_91 . V_93 = V_94 |
V_95 |
V_96 |
V_97 ;
if ( V_19 -> V_98 > ( ( 2 * 1024 ) - 64 ) ) {
V_27 = - V_39 ;
goto V_99;
}
V_91 . V_100 = V_19 -> V_98 >> V_101 ;
V_91 . V_102 = 0x2 ;
}
if ( V_19 -> V_103 > ( ( 16 * 1024 ) - 128 ) ) {
V_27 = - V_39 ;
goto V_99;
}
V_91 . V_104 = V_19 -> V_103 >> V_105 ;
if ( V_19 -> V_106 >= ( 16 * 1024 ) || V_19 -> V_106 < 64 ) {
V_27 = - V_39 ;
goto V_99;
}
V_91 . V_107 = V_19 -> V_106 ;
V_91 . V_108 = 1 ;
V_91 . V_109 = 1 ;
V_91 . V_110 = 1 ;
V_91 . V_111 = 1 ;
V_91 . V_112 = 1 ;
V_91 . V_113 = 2 ;
V_91 . V_114 = 1 ;
V_27 = F_26 ( V_11 , V_17 ) ;
if ( V_27 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_3 ,
V_17 , V_27 ) ;
V_27 = - V_80 ;
goto V_99;
}
V_27 = F_27 ( V_11 , V_17 , & V_91 ) ;
if ( V_27 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_4 ,
V_17 , V_27 ) ;
V_27 = - V_80 ;
goto V_99;
}
V_99:
return V_27 ;
}
static int F_28 ( struct V_1 * V_2 , enum V_115 type )
{
struct V_116 * V_117 = NULL ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
struct V_16 * V_6 ;
int V_27 = 0 ;
V_6 = F_29 ( V_5 , type , V_5 -> V_6 [ V_5 -> V_118 ] -> V_119 , V_2 -> V_7 ) ;
if ( ! V_6 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_5 ,
V_2 -> V_7 , V_5 -> V_11 . V_120 . V_121 ) ;
V_27 = - V_80 ;
goto V_122;
}
if ( type == V_123 ) {
V_2 -> V_124 = V_6 -> V_125 ;
V_2 -> V_126 = V_6 -> V_127 ;
F_30 ( & V_5 -> V_78 -> V_79 ,
L_6 ,
V_6 -> V_125 , V_6 -> V_127 ) ;
V_117 = F_31 ( V_6 , V_2 -> V_128 . V_129 ,
0 , true , false ) ;
}
if ( ! V_117 ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_7 ) ;
V_27 = - V_130 ;
goto V_122;
}
V_27 = F_32 ( V_6 ) ;
if ( V_27 ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_8 ) ;
goto V_122;
}
V_27 = F_33 ( V_11 , V_6 -> V_119 , true , NULL ) ;
if ( V_27 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_9 ,
V_2 -> V_7 , V_6 -> V_125 , V_5 -> V_11 . V_120 . V_121 ) ;
V_27 = - V_39 ;
}
V_122:
return V_27 ;
}
int F_34 ( struct V_1 * V_2 , bool V_131 )
{
int V_27 = - V_80 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
T_3 V_28 , V_50 , V_132 ;
bool V_133 = false ;
T_2 V_17 ;
int V_134 , V_135 ;
F_9 ( V_11 , F_35 ( V_2 -> V_7 ) , V_136 ) ;
F_36 ( V_137 , & V_2 -> V_138 ) ;
if ( ! V_131 ) {
V_28 = V_139 ;
F_9 ( V_11 , F_37 ( V_2 -> V_7 ) , V_28 ) ;
F_10 ( V_11 ) ;
}
for ( V_134 = 0 ; V_134 < 4 ; V_134 ++ ) {
F_38 ( 10 ) ;
V_28 = F_7 ( V_11 , F_39 ( V_2 -> V_7 ) ) ;
if ( V_28 & V_140 ) {
V_133 = true ;
break;
}
}
if ( ! V_133 )
F_22 ( & V_5 -> V_78 -> V_79 , L_10 ,
V_2 -> V_7 ) ;
for ( V_135 = 0 ; V_135 < V_5 -> V_6 [ V_2 -> V_124 ] -> V_9 ; V_135 ++ ) {
V_27 = F_6 ( V_2 , V_2 -> V_124 , V_135 ,
V_36 ) ;
V_27 = F_11 ( V_2 , V_2 -> V_124 , V_135 ,
V_36 ) ;
}
F_38 ( 10 ) ;
for ( V_135 = 0 ; V_135 < V_5 -> V_6 [ V_2 -> V_124 ] -> V_9 ; V_135 ++ ) {
V_27 = F_6 ( V_2 , V_2 -> V_124 , V_135 ,
V_38 ) ;
if ( V_27 )
F_30 ( & V_5 -> V_78 -> V_79 ,
L_11 ,
V_2 -> V_124 , V_135 , V_2 -> V_7 ) ;
V_27 = F_11 ( V_2 , V_2 -> V_124 , V_135 ,
V_38 ) ;
if ( V_27 )
F_30 ( & V_5 -> V_78 -> V_79 ,
L_12 ,
V_2 -> V_124 , V_135 , V_2 -> V_7 ) ;
}
V_132 = V_5 -> V_11 . V_12 . V_13 ;
for ( V_134 = 0 ; V_134 < V_132 ; V_134 ++ ) {
if ( 0 == V_134 )
V_50 = F_14 ( V_2 -> V_7 ) ;
else
V_50 = F_15 ( ( ( V_132 - 1 ) *
( V_2 -> V_7 ) )
+ ( V_134 - 1 ) ) ;
V_28 = ( V_141 |
V_142 ) ;
F_9 ( V_11 , V_50 , V_28 ) ;
F_10 ( V_11 ) ;
}
for ( V_134 = 0 ; V_134 < V_132 ; V_134 ++ ) {
if ( 0 == V_134 )
V_50 = F_40 ( V_2 -> V_7 ) ;
else
V_50 = F_41 ( ( ( V_132 - 1 ) *
( V_2 -> V_7 ) )
+ ( V_134 - 1 ) ) ;
F_9 ( V_11 , V_50 , V_143 ) ;
F_10 ( V_11 ) ;
}
V_28 = ( V_144 | V_145 |
V_146 ) ;
for ( V_135 = 0 ; V_135 < V_5 -> V_6 [ V_2 -> V_124 ] -> V_9 ; V_135 ++ ) {
V_17 = F_4 ( V_2 , V_2 -> V_124 , V_135 ) ;
F_9 ( V_11 , F_18 ( V_17 ) , V_28 ) ;
F_9 ( V_11 , F_19 ( V_17 ) , V_28 ) ;
}
V_28 = F_7 ( V_11 , F_37 ( V_2 -> V_7 ) ) ;
V_28 &= ~ V_139 ;
F_9 ( V_11 , F_37 ( V_2 -> V_7 ) , V_28 ) ;
F_9 ( V_11 , F_35 ( V_2 -> V_7 ) , V_147 ) ;
F_10 ( V_11 ) ;
return V_27 ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
T_3 V_28 , V_148 = 0 ;
int V_135 ;
F_9 ( V_11 , F_43 ( V_2 -> V_126 ) ,
V_149 ) ;
V_28 = V_150 ;
F_9 ( V_11 , F_44 ( V_2 -> V_7 ) , V_28 ) ;
for ( V_135 = 0 ; V_135 < V_5 -> V_6 [ V_2 -> V_124 ] -> V_9 ; V_135 ++ ) {
T_2 V_8 = F_4 ( V_2 , V_2 -> V_124 , V_135 ) ;
V_28 = ( V_8 & V_151 ) ;
F_9 ( V_11 , F_45 ( V_148 , V_2 -> V_7 ) , V_28 ) ;
V_148 ++ ;
}
for ( V_135 = 0 ; V_135 < 7 ; V_135 ++ ) {
if ( V_135 * 2 >= V_5 -> V_6 [ V_2 -> V_124 ] -> V_9 ) {
V_28 = 0x07FF07FF ;
} else {
T_2 V_8 = F_4 ( V_2 , V_2 -> V_124 ,
V_135 * 2 ) ;
V_28 = V_8 ;
V_8 = F_4 ( V_2 , V_2 -> V_124 ,
( V_135 * 2 ) + 1 ) ;
V_28 |= V_8 << 16 ;
}
F_9 ( V_11 , F_46 ( V_135 , V_2 -> V_126 ) , V_28 ) ;
}
F_10 ( V_11 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
int V_134 ;
F_9 ( V_11 , F_44 ( V_2 -> V_7 ) , 0 ) ;
for ( V_134 = 0 ; V_134 < V_56 ; V_134 ++ )
F_9 ( V_11 , F_45 ( V_134 , V_2 -> V_7 ) ,
V_18 ) ;
F_10 ( V_11 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_2 -> V_124 ) {
F_49 ( V_5 -> V_6 [ V_2 -> V_124 ] ) ;
V_2 -> V_124 = 0 ;
V_2 -> V_126 = 0 ;
}
V_2 -> V_9 = 0 ;
V_2 -> V_138 = 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_148 = 0 ;
int V_27 ;
V_27 = F_28 ( V_2 , V_123 ) ;
if ( V_27 )
goto V_152;
V_148 += V_5 -> V_6 [ V_2 -> V_124 ] -> V_9 ;
F_51 ( V_153 , & V_2 -> V_154 ) ;
V_2 -> V_9 = V_148 ;
F_51 ( V_155 , & V_2 -> V_138 ) ;
V_152:
if ( V_27 )
F_48 ( V_2 ) ;
return V_27 ;
}
static bool F_52 ( struct V_4 * V_5 )
{
struct V_156 * V_78 = V_5 -> V_78 ;
struct V_156 * V_157 ;
V_157 = F_53 ( V_158 , V_159 , NULL ) ;
while ( V_157 ) {
if ( V_157 -> V_160 && F_54 ( V_157 ) == V_78 ) {
if ( V_157 -> V_161 & V_162 )
return true ;
}
V_157 = F_53 ( V_158 ,
V_159 ,
V_157 ) ;
}
return false ;
}
void F_55 ( struct V_4 * V_5 )
{
struct V_25 * V_11 = & V_5 -> V_11 ;
int V_134 ;
if ( ! V_5 -> V_2 )
return;
F_9 ( V_11 , V_163 , 0 ) ;
F_10 ( V_11 ) ;
for ( V_134 = 0 ; V_134 < V_5 -> V_164 ; V_134 ++ ) {
if ( F_56 ( V_155 , & V_5 -> V_2 [ V_134 ] . V_138 ) )
F_48 ( & V_5 -> V_2 [ V_134 ] ) ;
F_47 ( & V_5 -> V_2 [ V_134 ] ) ;
}
F_57 ( V_5 -> V_2 ) ;
V_5 -> V_2 = NULL ;
V_5 -> V_164 = 0 ;
if ( ! F_52 ( V_5 ) )
F_58 ( V_5 -> V_78 ) ;
else
F_59 ( & V_5 -> V_78 -> V_79 ,
L_13 ) ;
F_9 ( V_11 , V_163 ,
V_165 |
V_166 |
( V_167 << V_168 ) ) ;
F_10 ( V_11 ) ;
}
static int F_60 ( struct V_4 * V_5 , T_2 V_164 )
{
struct V_1 * V_169 ;
int V_134 , V_27 = 0 ;
V_27 = F_61 ( V_5 -> V_78 , V_164 ) ;
if ( V_27 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_14 , V_27 ) ;
V_5 -> V_164 = 0 ;
goto V_170;
}
V_169 = F_62 ( V_164 * sizeof( struct V_1 ) , V_171 ) ;
if ( ! V_169 ) {
V_27 = - V_130 ;
goto V_172;
}
for ( V_134 = 0 ; V_134 < V_164 ; V_134 ++ ) {
V_169 [ V_134 ] . V_5 = V_5 ;
V_169 [ V_134 ] . V_173 = V_174 ;
V_169 [ V_134 ] . V_7 = V_134 ;
F_51 ( V_175 , & V_169 [ V_134 ] . V_154 ) ;
V_27 = F_50 ( & V_169 [ V_134 ] ) ;
F_34 ( & V_169 [ V_134 ] , true ) ;
if ( V_27 )
break;
F_42 ( & V_169 [ V_134 ] ) ;
}
V_5 -> V_2 = V_169 ;
V_5 -> V_164 = V_164 ;
V_172:
if ( V_27 )
F_55 ( V_5 ) ;
V_170:
return V_27 ;
}
static int F_63 ( struct V_156 * V_78 , int V_176 )
{
#ifdef F_64
struct V_4 * V_5 = F_65 ( V_78 ) ;
int V_177 = F_66 ( V_78 ) ;
int V_178 = 0 ;
F_30 ( & V_78 -> V_79 , L_15 , V_176 ) ;
if ( V_177 && V_177 != V_176 )
F_55 ( V_5 ) ;
else if ( V_177 && V_177 == V_176 )
goto V_179;
if ( V_176 > V_5 -> V_180 ) {
V_178 = - V_33 ;
goto V_181;
}
V_178 = F_60 ( V_5 , V_176 ) ;
if ( V_178 ) {
F_59 ( & V_78 -> V_79 , L_16 , V_178 ) ;
goto V_181;
}
V_179:
return V_176 ;
V_181:
return V_178 ;
#endif
return 0 ;
}
int F_67 ( struct V_156 * V_78 , int V_176 )
{
struct V_4 * V_5 = F_65 ( V_78 ) ;
if ( V_176 )
return F_63 ( V_78 , V_176 ) ;
F_55 ( V_5 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , T_3 V_182 ,
T_3 V_183 , T_1 * V_184 , T_2 V_185 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
T_4 V_186 ;
if ( V_183 ) {
V_2 -> V_187 ++ ;
F_22 ( & V_5 -> V_78 -> V_79 , L_17 ,
V_182 , V_183 ) ;
if ( V_2 -> V_187 >
V_188 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_18 ,
V_2 -> V_7 ) ;
F_22 ( & V_5 -> V_78 -> V_79 , L_19 ) ;
F_51 ( V_189 , & V_2 -> V_138 ) ;
}
} else {
V_2 -> V_190 ++ ;
}
V_186 = F_69 ( V_11 , V_2 -> V_7 , V_182 , V_183 ,
V_184 , V_185 , NULL ) ;
if ( V_186 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_20 ,
V_2 -> V_7 , V_5 -> V_11 . V_120 . V_121 ) ;
return - V_191 ;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 ,
enum V_192 V_193 ,
T_4 V_194 )
{
return F_68 ( V_2 , V_193 , V_194 , NULL , 0 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_195 V_19 = {
V_196 , V_197
} ;
return F_68 ( V_2 , V_198 ,
V_199 , ( T_1 * ) & V_19 ,
sizeof( struct
V_195 ) ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_200 * V_201 = NULL ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_4 V_186 = 0 ;
struct V_16 * V_6 ;
int V_134 = 0 , V_202 = 0 ;
int V_203 = 1 ;
int V_27 ;
if ( ! F_56 ( V_155 , & V_2 -> V_138 ) ) {
V_186 = V_204 ;
goto V_178;
}
V_202 = ( sizeof( struct V_200 ) +
sizeof( struct V_205 ) * V_203 ) ;
V_201 = F_62 ( V_202 , V_171 ) ;
if ( ! V_201 ) {
V_186 = V_206 ;
V_202 = 0 ;
goto V_178;
}
V_201 -> V_207 = V_208 ;
V_6 = V_5 -> V_6 [ V_2 -> V_124 ] ;
if ( ! V_6 -> V_19 . V_209 )
V_201 -> V_207 |= V_210 ;
V_201 -> V_203 = V_203 ;
V_201 -> V_9 = V_2 -> V_9 ;
V_201 -> V_211 = V_5 -> V_11 . V_12 . V_13 ;
if ( V_2 -> V_124 ) {
V_201 -> V_212 [ V_134 ] . V_3 = V_2 -> V_124 ;
V_201 -> V_212 [ V_134 ] . V_213 = V_123 ;
V_201 -> V_212 [ V_134 ] . V_9 =
V_5 -> V_6 [ V_2 -> V_124 ] -> V_9 ;
memcpy ( V_201 -> V_212 [ V_134 ] . V_214 ,
V_2 -> V_128 . V_129 , V_215 ) ;
V_134 ++ ;
}
F_51 ( V_137 , & V_2 -> V_138 ) ;
V_178:
V_27 = F_68 ( V_2 , V_216 ,
V_186 , ( T_1 * ) V_201 , V_202 ) ;
F_57 ( V_201 ) ;
return V_27 ;
}
static int F_73 ( struct V_1 * V_2 )
{
if ( ! F_56 ( V_137 , & V_2 -> V_138 ) )
return - V_80 ;
return F_34 ( V_2 , false ) ;
}
static int F_74 ( struct V_1 * V_2 ,
T_1 * V_184 , T_2 V_185 )
{
struct V_217 * V_19 =
(struct V_217 * ) V_184 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
bool V_218 = false ;
bool V_219 = false ;
T_4 V_186 ;
if ( ! F_56 ( V_137 , & V_2 -> V_138 ) ||
! F_56 ( V_153 , & V_2 -> V_154 ) ||
! F_1 ( V_2 , V_19 -> V_3 ) ||
( V_5 -> V_6 [ V_19 -> V_3 ] -> type != V_220 ) ) {
V_186 = V_204 ;
goto V_99;
}
if ( V_19 -> V_221 & V_222 )
V_219 = true ;
V_186 = F_75 ( V_11 , V_19 -> V_3 ,
V_219 , NULL ) ;
if ( V_186 )
goto V_99;
if ( V_19 -> V_221 & V_223 )
V_218 = true ;
V_186 = F_76 ( V_11 , V_19 -> V_3 ,
V_218 , NULL ) ;
V_99:
return F_70 ( V_2 ,
V_224 ,
V_186 ) ;
}
static int F_77 ( struct V_1 * V_2 , T_1 * V_184 , T_2 V_185 )
{
struct V_225 * V_226 =
(struct V_225 * ) V_184 ;
struct V_227 * V_228 ;
T_2 V_3 , V_15 ;
T_4 V_186 = 0 ;
int V_134 ;
if ( ! F_56 ( V_137 , & V_2 -> V_138 ) ) {
V_186 = V_204 ;
goto V_99;
}
V_3 = V_226 -> V_3 ;
if ( ! F_1 ( V_2 , V_3 ) ) {
V_186 = V_204 ;
goto V_99;
}
for ( V_134 = 0 ; V_134 < V_226 -> V_9 ; V_134 ++ ) {
V_228 = & V_226 -> V_229 [ V_134 ] ;
V_15 = V_228 -> V_230 . V_231 ;
if ( ( V_228 -> V_230 . V_3 != V_3 ) ||
( V_228 -> V_232 . V_3 != V_3 ) ||
( V_228 -> V_232 . V_231 != V_15 ) ||
! F_2 ( V_2 , V_3 , V_15 ) ) {
V_186 = V_204 ;
goto V_99;
}
if ( F_25 ( V_2 , V_3 , V_15 ,
& V_228 -> V_232 ) ||
F_20 ( V_2 , V_3 , V_15 ,
& V_228 -> V_230 ) ) {
V_186 = V_204 ;
goto V_99;
}
}
V_99:
return F_70 ( V_2 , V_233 ,
V_186 ) ;
}
static int F_78 ( struct V_1 * V_2 , T_1 * V_184 , T_2 V_185 )
{
struct V_234 * V_235 =
(struct V_234 * ) V_184 ;
struct V_43 * V_236 ;
T_2 V_3 , V_15 , V_10 ;
T_4 V_186 = 0 ;
unsigned long V_46 ;
int V_134 ;
if ( ! F_56 ( V_137 , & V_2 -> V_138 ) ) {
V_186 = V_204 ;
goto V_99;
}
for ( V_134 = 0 ; V_134 < V_235 -> V_237 ; V_134 ++ ) {
V_236 = & V_235 -> V_44 [ V_134 ] ;
V_10 = V_236 -> V_10 ;
V_3 = V_236 -> V_3 ;
if ( ! F_3 ( V_2 , V_10 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_186 = V_204 ;
goto V_99;
}
V_46 = V_236 -> V_52 ;
V_15 = F_16 ( & V_46 , V_56 ) ;
while ( V_15 < V_56 ) {
if ( ! F_2 ( V_2 , V_3 ,
V_15 ) ) {
V_186 = V_204 ;
goto V_99;
}
V_15 = F_17 ( & V_46 , V_56 ,
V_15 + 1 ) ;
}
V_46 = V_236 -> V_53 ;
V_15 = F_16 ( & V_46 , V_56 ) ;
while ( V_15 < V_56 ) {
if ( ! F_2 ( V_2 , V_3 ,
V_15 ) ) {
V_186 = V_204 ;
goto V_99;
}
V_15 = F_17 ( & V_46 , V_56 ,
V_15 + 1 ) ;
}
F_13 ( V_2 , V_3 , V_236 ) ;
}
V_99:
return F_70 ( V_2 , V_238 ,
V_186 ) ;
}
static int F_79 ( struct V_1 * V_2 , T_1 * V_184 , T_2 V_185 )
{
struct V_239 * V_240 =
(struct V_239 * ) V_184 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_3 = V_240 -> V_3 ;
T_4 V_186 = 0 ;
unsigned long V_46 ;
T_2 V_231 ;
if ( ! F_56 ( V_137 , & V_2 -> V_138 ) ) {
V_186 = V_204 ;
goto V_99;
}
if ( ! F_1 ( V_2 , V_3 ) ) {
V_186 = V_204 ;
goto V_99;
}
if ( ( 0 == V_240 -> V_241 ) && ( 0 == V_240 -> V_242 ) ) {
V_186 = V_204 ;
goto V_99;
}
V_46 = V_240 -> V_241 ;
V_231 = F_16 ( & V_46 , V_56 ) ;
while ( V_231 < V_56 ) {
if ( ! F_2 ( V_2 , V_3 , V_231 ) ) {
V_186 = V_204 ;
goto V_99;
}
F_11 ( V_2 , V_3 , V_231 ,
V_29 ) ;
V_231 = F_17 ( & V_46 , V_56 ,
V_231 + 1 ) ;
}
V_46 = V_240 -> V_242 ;
V_231 = F_16 ( & V_46 , V_56 ) ;
while ( V_231 < V_56 ) {
if ( ! F_2 ( V_2 , V_3 , V_231 ) ) {
V_186 = V_204 ;
goto V_99;
}
F_6 ( V_2 , V_3 , V_231 ,
V_29 ) ;
V_231 = F_17 ( & V_46 , V_56 ,
V_231 + 1 ) ;
}
F_38 ( 10 ) ;
V_46 = V_240 -> V_241 ;
V_231 = F_16 ( & V_46 , V_56 ) ;
while ( V_231 < V_56 ) {
if ( F_11 ( V_2 , V_3 , V_231 ,
V_31 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_21 ,
V_231 , V_3 , V_2 -> V_7 ) ;
}
V_231 = F_17 ( & V_46 , V_56 ,
V_231 + 1 ) ;
}
V_46 = V_240 -> V_242 ;
V_231 = F_16 ( & V_46 , V_56 ) ;
while ( V_231 < V_56 ) {
if ( F_6 ( V_2 , V_3 , V_231 ,
V_31 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_22 ,
V_231 , V_3 , V_2 -> V_7 ) ;
}
V_231 = F_17 ( & V_46 , V_56 ,
V_231 + 1 ) ;
}
V_99:
return F_70 ( V_2 , V_243 ,
V_186 ) ;
}
static int F_80 ( struct V_1 * V_2 , T_1 * V_184 , T_2 V_185 )
{
struct V_239 * V_240 =
(struct V_239 * ) V_184 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_3 = V_240 -> V_3 ;
T_4 V_186 = 0 ;
unsigned long V_46 ;
T_2 V_231 ;
if ( ! F_56 ( V_137 , & V_2 -> V_138 ) ) {
V_186 = V_204 ;
goto V_99;
}
if ( ! F_1 ( V_2 , V_240 -> V_3 ) ) {
V_186 = V_204 ;
goto V_99;
}
if ( ( 0 == V_240 -> V_241 ) && ( 0 == V_240 -> V_242 ) ) {
V_186 = V_204 ;
goto V_99;
}
V_46 = V_240 -> V_241 ;
V_231 = F_16 ( & V_46 , V_56 ) ;
while ( V_231 < V_56 ) {
if ( ! F_2 ( V_2 , V_3 , V_231 ) ) {
V_186 = V_204 ;
goto V_99;
}
F_11 ( V_2 , V_3 , V_231 ,
V_34 ) ;
V_231 = F_17 ( & V_46 , V_56 ,
V_231 + 1 ) ;
}
V_46 = V_240 -> V_242 ;
V_231 = F_16 ( & V_46 , V_56 ) ;
while ( V_231 < V_56 ) {
if ( ! F_2 ( V_2 , V_3 , V_231 ) ) {
V_186 = V_204 ;
goto V_99;
}
F_6 ( V_2 , V_3 , V_231 ,
V_34 ) ;
V_231 = F_17 ( & V_46 , V_56 ,
V_231 + 1 ) ;
}
F_38 ( 10 ) ;
V_46 = V_240 -> V_241 ;
V_231 = F_16 ( & V_46 , V_56 ) ;
while ( V_231 < V_56 ) {
if ( F_11 ( V_2 , V_3 , V_231 ,
V_35 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_21 ,
V_231 , V_3 , V_2 -> V_7 ) ;
}
V_231 = F_17 ( & V_46 , V_56 ,
V_231 + 1 ) ;
}
V_46 = V_240 -> V_242 ;
V_231 = F_16 ( & V_46 , V_56 ) ;
while ( V_231 < V_56 ) {
if ( F_6 ( V_2 , V_3 , V_231 ,
V_35 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_22 ,
V_231 , V_3 , V_2 -> V_7 ) ;
}
V_231 = F_17 ( & V_46 , V_56 ,
V_231 + 1 ) ;
}
V_99:
return F_70 ( V_2 , V_244 ,
V_186 ) ;
}
static int F_81 ( struct V_1 * V_2 , T_1 * V_184 , T_2 V_185 )
{
struct V_239 * V_240 =
(struct V_239 * ) V_184 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_245 V_246 ;
T_4 V_186 = 0 ;
struct V_16 * V_6 ;
memset ( & V_246 , 0 , sizeof( struct V_245 ) ) ;
if ( ! F_56 ( V_137 , & V_2 -> V_138 ) ) {
V_186 = V_204 ;
goto V_99;
}
if ( ! F_1 ( V_2 , V_240 -> V_3 ) ) {
V_186 = V_204 ;
goto V_99;
}
V_6 = V_5 -> V_6 [ V_240 -> V_3 ] ;
if ( ! V_6 ) {
V_186 = V_204 ;
goto V_99;
}
F_82 ( V_6 ) ;
memcpy ( & V_246 , & V_6 -> V_247 , sizeof( struct V_245 ) ) ;
V_99:
return F_68 ( V_2 , V_248 , V_186 ,
( T_1 * ) & V_246 , sizeof( V_246 ) ) ;
}
static int F_83 ( struct V_1 * V_2 , T_1 * V_184 , T_2 V_185 )
{
struct V_249 * V_250 =
(struct V_249 * ) V_184 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 = NULL ;
T_2 V_3 = V_250 -> V_3 ;
T_4 V_186 = 0 ;
int V_134 ;
if ( ! F_56 ( V_137 , & V_2 -> V_138 ) ||
! F_56 ( V_153 , & V_2 -> V_154 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_186 = V_204 ;
goto V_99;
}
for ( V_134 = 0 ; V_134 < V_250 -> V_251 ; V_134 ++ ) {
if ( F_84 ( V_250 -> V_252 [ V_134 ] . V_129 ) ||
F_85 ( V_250 -> V_252 [ V_134 ] . V_129 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_23 ,
V_250 -> V_252 [ V_134 ] . V_129 ) ;
V_186 = V_204 ;
goto V_99;
}
}
V_6 = V_5 -> V_6 [ V_3 ] ;
for ( V_134 = 0 ; V_134 < V_250 -> V_251 ; V_134 ++ ) {
struct V_116 * V_117 ;
V_117 = F_86 ( V_6 , V_250 -> V_252 [ V_134 ] . V_129 , true , false ) ;
if ( V_117 ) {
if ( F_87 ( V_6 ) )
V_117 = F_88 ( V_6 , V_250 -> V_252 [ V_134 ] . V_129 ,
true , false ) ;
else
V_117 = F_31 ( V_6 , V_250 -> V_252 [ V_134 ] . V_129 , - 1 ,
true , false ) ;
}
if ( ! V_117 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_24 ) ;
V_186 = V_204 ;
goto V_99;
}
}
if ( F_32 ( V_6 ) )
F_22 ( & V_5 -> V_78 -> V_79 , L_25 ) ;
V_99:
return F_70 ( V_2 , V_253 ,
V_186 ) ;
}
static int F_89 ( struct V_1 * V_2 , T_1 * V_184 , T_2 V_185 )
{
struct V_249 * V_250 =
(struct V_249 * ) V_184 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 = NULL ;
T_2 V_3 = V_250 -> V_3 ;
T_4 V_186 = 0 ;
int V_134 ;
if ( ! F_56 ( V_137 , & V_2 -> V_138 ) ||
! F_56 ( V_153 , & V_2 -> V_154 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_186 = V_204 ;
goto V_99;
}
V_6 = V_5 -> V_6 [ V_3 ] ;
for ( V_134 = 0 ; V_134 < V_250 -> V_251 ; V_134 ++ )
F_90 ( V_6 , V_250 -> V_252 [ V_134 ] . V_129 ,
V_254 , true , false ) ;
if ( F_32 ( V_6 ) )
F_22 ( & V_5 -> V_78 -> V_79 , L_25 ) ;
V_99:
return F_70 ( V_2 , V_255 ,
V_186 ) ;
}
static int F_91 ( struct V_1 * V_2 , T_1 * V_184 , T_2 V_185 )
{
struct V_256 * V_257 =
(struct V_256 * ) V_184 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 = NULL ;
T_2 V_3 = V_257 -> V_3 ;
T_4 V_186 = 0 ;
int V_134 ;
if ( ! F_56 ( V_137 , & V_2 -> V_138 ) ||
! F_56 ( V_153 , & V_2 -> V_154 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_186 = V_204 ;
goto V_99;
}
for ( V_134 = 0 ; V_134 < V_257 -> V_251 ; V_134 ++ ) {
if ( V_257 -> V_258 [ V_134 ] > V_259 ) {
V_186 = V_204 ;
F_22 ( & V_5 -> V_78 -> V_79 ,
L_26 , V_257 -> V_258 [ V_134 ] ) ;
goto V_99;
}
}
V_6 = V_5 -> V_6 [ V_3 ] ;
if ( V_6 -> V_19 . V_209 ) {
V_186 = V_204 ;
goto V_99;
}
F_92 ( V_6 ) ;
for ( V_134 = 0 ; V_134 < V_257 -> V_251 ; V_134 ++ ) {
int V_27 = F_93 ( V_6 , V_257 -> V_258 [ V_134 ] ) ;
if ( V_27 )
F_22 ( & V_5 -> V_78 -> V_79 ,
L_27 ,
V_257 -> V_258 [ V_134 ] , V_27 ) ;
}
V_99:
return F_70 ( V_2 , V_260 , V_186 ) ;
}
static int F_94 ( struct V_1 * V_2 , T_1 * V_184 , T_2 V_185 )
{
struct V_256 * V_257 =
(struct V_256 * ) V_184 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 = NULL ;
T_2 V_3 = V_257 -> V_3 ;
T_4 V_186 = 0 ;
int V_134 ;
if ( ! F_56 ( V_137 , & V_2 -> V_138 ) ||
! F_56 ( V_153 , & V_2 -> V_154 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_186 = V_204 ;
goto V_99;
}
for ( V_134 = 0 ; V_134 < V_257 -> V_251 ; V_134 ++ ) {
if ( V_257 -> V_258 [ V_134 ] > V_259 ) {
V_186 = V_204 ;
goto V_99;
}
}
V_6 = V_5 -> V_6 [ V_3 ] ;
if ( V_6 -> V_19 . V_209 ) {
V_186 = V_204 ;
goto V_99;
}
for ( V_134 = 0 ; V_134 < V_257 -> V_251 ; V_134 ++ ) {
int V_27 = F_95 ( V_6 , V_257 -> V_258 [ V_134 ] ) ;
if ( V_27 )
F_22 ( & V_5 -> V_78 -> V_79 ,
L_28 ,
V_257 -> V_258 [ V_134 ] , V_27 ) ;
}
V_99:
return F_70 ( V_2 , V_261 , V_186 ) ;
}
static int F_96 ( struct V_1 * V_2 , T_1 * V_184 , T_2 V_185 )
{
T_4 V_186 = 0 ;
if ( ! F_56 ( V_137 , & V_2 -> V_138 ) ||
! F_56 ( V_262 , & V_2 -> V_138 ) ) {
V_186 = V_204 ;
goto V_99;
}
V_186 = V_263 ;
V_99:
return F_70 ( V_2 , V_264 , V_186 ) ;
}
static int F_97 ( struct V_1 * V_2 , T_3 V_182 ,
T_3 V_183 , T_1 * V_184 , T_2 V_185 )
{
bool V_265 = false ;
int V_266 ;
if ( F_56 ( V_189 , & V_2 -> V_138 ) )
return V_204 ;
switch ( V_182 ) {
case V_198 :
V_266 = sizeof( struct V_195 ) ;
break;
case V_267 :
case V_216 :
V_266 = 0 ;
break;
case V_268 :
V_266 = sizeof( struct V_67 ) ;
break;
case V_269 :
V_266 = sizeof( struct V_89 ) ;
break;
case V_233 :
V_266 = sizeof( struct V_225 ) ;
if ( V_185 >= V_266 ) {
struct V_225 * V_270 =
(struct V_225 * ) V_184 ;
V_266 += ( V_270 -> V_9 *
sizeof( struct
V_227 ) ) ;
if ( V_270 -> V_9 == 0 )
V_265 = true ;
}
break;
case V_238 :
V_266 = sizeof( struct V_234 ) ;
if ( V_185 >= V_266 ) {
struct V_234 * V_271 =
(struct V_234 * ) V_184 ;
V_266 += ( V_271 -> V_237 *
sizeof( struct V_43 ) ) ;
if ( V_271 -> V_237 == 0 )
V_265 = true ;
}
break;
case V_243 :
case V_244 :
V_266 = sizeof( struct V_239 ) ;
break;
case V_253 :
case V_255 :
V_266 = sizeof( struct V_249 ) ;
if ( V_185 >= V_266 ) {
struct V_249 * V_272 =
(struct V_249 * ) V_184 ;
V_266 += V_272 -> V_251 *
sizeof( struct V_273 ) ;
if ( V_272 -> V_251 == 0 )
V_265 = true ;
}
break;
case V_260 :
case V_261 :
V_266 = sizeof( struct V_256 ) ;
if ( V_185 >= V_266 ) {
struct V_256 * V_257 =
(struct V_256 * ) V_184 ;
V_266 += V_257 -> V_251 * sizeof( T_2 ) ;
if ( V_257 -> V_251 == 0 )
V_265 = true ;
}
break;
case V_224 :
V_266 = sizeof( struct V_217 ) ;
break;
case V_248 :
V_266 = sizeof( struct V_239 ) ;
break;
case V_274 :
case V_275 :
default:
return - V_33 ;
break;
}
if ( ( V_266 != V_185 ) || ( V_265 ) ) {
F_70 ( V_2 , V_182 , V_204 ) ;
return - V_39 ;
} else {
return 0 ;
}
}
int F_98 ( struct V_4 * V_5 , T_2 V_7 , T_3 V_182 ,
T_3 V_183 , T_1 * V_184 , T_2 V_185 )
{
struct V_1 * V_2 = & ( V_5 -> V_2 [ V_7 ] ) ;
struct V_25 * V_11 = & V_5 -> V_11 ;
int V_27 ;
V_5 -> V_276 ++ ;
V_27 = F_97 ( V_2 , V_182 , V_183 , V_184 , V_185 ) ;
if ( V_27 ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_29 , V_7 ) ;
return V_27 ;
}
F_9 ( V_11 , F_35 ( V_7 ) , V_277 ) ;
switch ( V_182 ) {
case V_198 :
V_27 = F_71 ( V_2 ) ;
break;
case V_216 :
V_27 = F_72 ( V_2 ) ;
break;
case V_267 :
V_27 = F_73 ( V_2 ) ;
break;
case V_224 :
V_27 = F_74 ( V_2 , V_184 , V_185 ) ;
break;
case V_233 :
V_27 = F_77 ( V_2 , V_184 , V_185 ) ;
break;
case V_238 :
V_27 = F_78 ( V_2 , V_184 , V_185 ) ;
break;
case V_243 :
V_27 = F_79 ( V_2 , V_184 , V_185 ) ;
break;
case V_244 :
V_27 = F_80 ( V_2 , V_184 , V_185 ) ;
break;
case V_253 :
V_27 = F_83 ( V_2 , V_184 , V_185 ) ;
break;
case V_255 :
V_27 = F_89 ( V_2 , V_184 , V_185 ) ;
break;
case V_260 :
V_27 = F_91 ( V_2 , V_184 , V_185 ) ;
break;
case V_261 :
V_27 = F_94 ( V_2 , V_184 , V_185 ) ;
break;
case V_248 :
V_27 = F_81 ( V_2 , V_184 , V_185 ) ;
break;
case V_264 :
V_27 = F_96 ( V_2 , V_184 , V_185 ) ;
break;
case V_275 :
default:
F_22 ( & V_5 -> V_78 -> V_79 ,
L_30 , V_182 , V_7 ) ;
V_27 = F_70 ( V_2 , V_182 ,
V_263 ) ;
break;
}
return V_27 ;
}
int F_99 ( struct V_4 * V_5 )
{
T_3 V_28 , V_50 , V_278 , V_7 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
struct V_1 * V_2 ;
if ( ! F_56 ( V_279 , & V_5 -> V_280 ) )
return 0 ;
F_36 ( V_279 , & V_5 -> V_280 ) ;
for ( V_7 = 0 ; V_7 < V_5 -> V_164 ; V_7 ++ ) {
V_50 = ( V_11 -> V_12 . V_86 + V_7 ) / 32 ;
V_278 = ( V_11 -> V_12 . V_86 + V_7 ) % 32 ;
V_2 = & V_5 -> V_2 [ V_7 ] ;
V_28 = F_7 ( V_11 , F_100 ( V_50 ) ) ;
if ( V_28 & ( 1 << V_278 ) ) {
F_9 ( V_11 , F_100 ( V_50 ) , ( 1 << V_278 ) ) ;
if ( F_34 ( V_2 , true ) )
F_22 ( & V_5 -> V_78 -> V_79 ,
L_31 , V_7 ) ;
F_48 ( V_2 ) ;
if ( F_50 ( V_2 ) )
F_22 ( & V_5 -> V_78 -> V_79 ,
L_32 ,
V_7 ) ;
F_42 ( V_2 ) ;
}
}
V_28 = F_7 ( V_11 , V_281 ) ;
V_28 |= V_282 ;
F_9 ( V_11 , V_281 , V_28 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static void F_101 ( struct V_4 * V_5 ,
enum V_192 V_182 ,
T_4 V_183 , T_1 * V_184 ,
T_2 V_185 )
{
struct V_25 * V_11 = & V_5 -> V_11 ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_134 ;
for ( V_134 = 0 ; V_134 < V_5 -> V_164 ; V_134 ++ ) {
F_69 ( V_11 , V_2 -> V_7 , V_182 , V_183 ,
V_184 , V_185 , NULL ) ;
V_2 ++ ;
}
}
void F_102 ( struct V_4 * V_5 )
{
struct V_283 V_284 ;
V_284 . V_285 = V_286 ;
V_284 . V_287 = V_288 ;
V_284 . V_289 . V_290 . V_291 =
V_5 -> V_11 . V_292 . V_293 . V_293 & V_294 ;
V_284 . V_289 . V_290 . V_295 = V_5 -> V_11 . V_292 . V_293 . V_295 ;
F_101 ( V_5 , V_274 , V_199 ,
( T_1 * ) & V_284 , sizeof( struct V_283 ) ) ;
}
void F_103 ( struct V_4 * V_5 )
{
struct V_283 V_284 ;
V_284 . V_285 = V_296 ;
V_284 . V_287 = V_297 ;
F_101 ( V_5 , V_274 , V_199 ,
( T_1 * ) & V_284 , sizeof( struct V_283 ) ) ;
}
void F_104 ( struct V_1 * V_2 )
{
struct V_283 V_284 ;
V_284 . V_285 = V_296 ;
V_284 . V_287 = V_297 ;
F_69 ( & V_2 -> V_5 -> V_11 , V_2 -> V_7 , V_274 ,
V_199 , ( T_1 * ) & V_284 ,
sizeof( struct V_283 ) , NULL ) ;
}
int F_105 ( struct V_298 * V_299 , int V_7 , T_1 * V_300 )
{
struct V_301 * V_302 = F_106 ( V_299 ) ;
struct V_16 * V_6 = V_302 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_303 ;
struct V_116 * V_117 ;
struct V_1 * V_2 ;
int V_27 = 0 ;
if ( V_7 >= V_5 -> V_164 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_33 , V_7 ) ;
V_27 = - V_39 ;
goto V_99;
}
V_2 = & ( V_5 -> V_2 [ V_7 ] ) ;
V_6 = V_5 -> V_6 [ V_2 -> V_124 ] ;
if ( ! F_56 ( V_155 , & V_2 -> V_138 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_34 , V_7 ) ;
V_27 = - V_39 ;
goto V_99;
}
if ( ! F_107 ( V_300 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_35 ) ;
V_27 = - V_39 ;
goto V_99;
}
F_90 ( V_6 , V_2 -> V_128 . V_129 , 0 , true , false ) ;
V_117 = F_31 ( V_6 , V_300 , 0 , true , false ) ;
if ( ! V_117 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_36 ) ;
V_27 = - V_130 ;
goto V_99;
}
F_30 ( & V_5 -> V_78 -> V_79 , L_37 , V_300 , V_7 ) ;
if ( F_32 ( V_6 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_8 ) ;
V_27 = - V_191 ;
goto V_99;
}
memcpy ( V_2 -> V_128 . V_129 , V_300 , V_215 ) ;
F_30 ( & V_5 -> V_78 -> V_79 , L_38 ) ;
V_27 = 0 ;
V_99:
return V_27 ;
}
int F_108 ( struct V_298 * V_299 ,
int V_7 , T_2 V_258 , T_1 V_304 )
{
struct V_301 * V_302 = F_106 ( V_299 ) ;
struct V_4 * V_5 = V_302 -> V_6 -> V_303 ;
struct V_16 * V_6 ;
struct V_1 * V_2 ;
int V_27 = 0 ;
if ( V_7 >= V_5 -> V_164 ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_33 , V_7 ) ;
V_27 = - V_39 ;
goto V_305;
}
if ( ( V_258 > V_259 ) || ( V_304 > 7 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_39 ) ;
V_27 = - V_39 ;
goto V_305;
}
V_2 = & ( V_5 -> V_2 [ V_7 ] ) ;
V_6 = V_5 -> V_6 [ V_2 -> V_124 ] ;
if ( ! F_56 ( V_155 , & V_2 -> V_138 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_34 , V_7 ) ;
V_27 = - V_39 ;
goto V_305;
}
if ( V_6 -> V_19 . V_209 ) {
V_27 = F_95 ( V_6 , ( F_5 ( V_6 -> V_19 . V_209 ) &
V_306 ) ) ;
if ( V_27 ) {
F_30 ( & V_6 -> V_303 -> V_78 -> V_79 ,
L_40 ,
V_27 , V_5 -> V_11 . V_120 . V_121 ) ;
}
}
if ( V_258 || V_304 )
V_27 = F_109 ( V_6 ,
V_258 | ( V_304 << V_307 ) ) ;
else
F_110 ( V_6 ) ;
if ( V_258 ) {
F_30 ( & V_5 -> V_78 -> V_79 , L_41 ,
V_258 , V_304 , V_7 ) ;
V_27 = F_93 ( V_6 , V_258 ) ;
if ( V_27 ) {
F_30 ( & V_6 -> V_303 -> V_78 -> V_79 ,
L_42 , V_27 ,
V_6 -> V_303 -> V_11 . V_120 . V_121 ) ;
goto V_305;
}
}
if ( V_27 ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_43 ) ;
goto V_305;
}
V_27 = 0 ;
V_305:
return V_27 ;
}
int F_111 ( struct V_298 * V_299 , int V_7 , int V_308 )
{
return - V_309 ;
}
int F_112 ( struct V_298 * V_299 ,
int V_7 , struct V_310 * V_311 )
{
struct V_301 * V_302 = F_106 ( V_299 ) ;
struct V_116 * V_117 , * V_312 ;
struct V_16 * V_6 = V_302 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_303 ;
struct V_1 * V_2 ;
int V_27 = 0 ;
if ( V_7 >= V_5 -> V_164 ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_33 , V_7 ) ;
V_27 = - V_39 ;
goto V_99;
}
V_2 = & ( V_5 -> V_2 [ V_7 ] ) ;
V_6 = V_5 -> V_6 [ V_2 -> V_124 ] ;
if ( ! F_56 ( V_155 , & V_2 -> V_138 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_34 , V_7 ) ;
V_27 = - V_39 ;
goto V_99;
}
V_311 -> V_2 = V_7 ;
F_113 (f, ftmp, &vsi->mac_filter_list, list) {
memcpy ( & V_311 -> V_300 , V_117 -> V_313 , V_314 ) ;
break;
}
V_311 -> V_308 = 0 ;
V_311 -> V_315 = F_5 ( V_6 -> V_19 . V_209 ) & V_316 ;
V_311 -> V_304 = ( F_5 ( V_6 -> V_19 . V_209 ) & V_317 ) >>
V_307 ;
V_27 = 0 ;
V_99:
return V_27 ;
}
