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
( ( V_5 -> V_11 . V_12 . V_13 - 1 )
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
V_70 |= ( ( V_11 -> V_83 . V_84 << V_85 )
& V_86 ) ;
V_70 |= ( ( ( V_2 -> V_7 + V_11 -> V_12 . V_87 )
<< V_88 )
& V_89 ) ;
F_9 ( V_11 , F_24 ( V_17 ) , V_70 ) ;
F_10 ( V_11 ) ;
V_81:
return V_27 ;
}
static int F_25 ( struct V_1 * V_2 , T_2 V_14 ,
T_2 V_15 ,
struct V_90 * V_19 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
struct V_91 V_92 ;
T_2 V_17 ;
int V_27 = 0 ;
V_17 = F_4 ( V_2 , V_14 , V_15 ) ;
memset ( & V_92 , 0 , sizeof( struct V_91 ) ) ;
V_92 . V_71 = V_19 -> V_72 / 128 ;
V_92 . V_73 = V_19 -> V_74 ;
if ( V_19 -> V_93 ) {
V_92 . V_94 = V_95 |
V_96 |
V_97 |
V_98 ;
if ( V_19 -> V_99 > ( ( 2 * 1024 ) - 64 ) ) {
V_27 = - V_39 ;
goto V_100;
}
V_92 . V_101 = V_19 -> V_99 >> V_102 ;
V_92 . V_103 = 0x2 ;
}
if ( V_19 -> V_104 > ( ( 16 * 1024 ) - 128 ) ) {
V_27 = - V_39 ;
goto V_100;
}
V_92 . V_105 = V_19 -> V_104 >> V_106 ;
if ( V_19 -> V_107 >= ( 16 * 1024 ) || V_19 -> V_107 < 64 ) {
V_27 = - V_39 ;
goto V_100;
}
V_92 . V_108 = V_19 -> V_107 ;
V_92 . V_109 = 1 ;
V_92 . V_110 = 1 ;
V_92 . V_111 = 1 ;
V_92 . V_112 = 1 ;
V_92 . V_113 = 1 ;
V_92 . V_114 = 2 ;
V_92 . V_115 = 1 ;
V_27 = F_26 ( V_11 , V_17 ) ;
if ( V_27 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_3 ,
V_17 , V_27 ) ;
V_27 = - V_80 ;
goto V_100;
}
V_27 = F_27 ( V_11 , V_17 , & V_92 ) ;
if ( V_27 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_4 ,
V_17 , V_27 ) ;
V_27 = - V_80 ;
goto V_100;
}
V_100:
return V_27 ;
}
static int F_28 ( struct V_1 * V_2 , enum V_116 type )
{
struct V_117 * V_118 = NULL ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
struct V_16 * V_6 ;
int V_27 = 0 ;
V_6 = F_29 ( V_5 , type , V_5 -> V_6 [ V_5 -> V_119 ] -> V_120 , V_2 -> V_7 ) ;
if ( ! V_6 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_5 ,
V_2 -> V_7 , V_5 -> V_11 . V_121 . V_122 ) ;
V_27 = - V_80 ;
goto V_123;
}
if ( type == V_124 ) {
V_2 -> V_125 = V_6 -> V_126 ;
V_2 -> V_127 = V_6 -> V_128 ;
F_30 ( & V_5 -> V_78 -> V_79 ,
L_6 ,
V_6 -> V_126 , V_6 -> V_128 ) ;
V_118 = F_31 ( V_6 , V_2 -> V_129 . V_130 ,
0 , true , false ) ;
}
if ( ! V_118 ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_7 ) ;
V_27 = - V_131 ;
goto V_123;
}
V_27 = F_32 ( V_6 ) ;
if ( V_27 ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_8 ) ;
goto V_123;
}
V_27 = F_33 ( V_11 , V_6 -> V_120 , true , NULL ) ;
if ( V_27 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_9 ,
V_2 -> V_7 , V_6 -> V_126 , V_5 -> V_11 . V_121 . V_122 ) ;
V_27 = - V_39 ;
}
V_123:
return V_27 ;
}
int F_34 ( struct V_1 * V_2 , bool V_132 )
{
int V_27 = - V_80 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
T_3 V_28 , V_50 , V_133 ;
bool V_134 = false ;
T_2 V_17 ;
int V_135 , V_136 ;
F_9 ( V_11 , F_35 ( V_2 -> V_7 ) , V_137 ) ;
F_36 ( V_138 , & V_2 -> V_139 ) ;
if ( ! V_132 ) {
V_28 = V_140 ;
F_9 ( V_11 , F_37 ( V_2 -> V_7 ) , V_28 ) ;
F_10 ( V_11 ) ;
}
for ( V_135 = 0 ; V_135 < 4 ; V_135 ++ ) {
F_38 ( 10 ) ;
V_28 = F_7 ( V_11 , F_39 ( V_2 -> V_7 ) ) ;
if ( V_28 & V_141 ) {
V_134 = true ;
break;
}
}
if ( ! V_134 )
F_22 ( & V_5 -> V_78 -> V_79 , L_10 ,
V_2 -> V_7 ) ;
for ( V_136 = 0 ; V_136 < V_5 -> V_6 [ V_2 -> V_125 ] -> V_9 ; V_136 ++ ) {
V_27 = F_6 ( V_2 , V_2 -> V_125 , V_136 ,
V_36 ) ;
V_27 = F_11 ( V_2 , V_2 -> V_125 , V_136 ,
V_36 ) ;
}
F_38 ( 10 ) ;
for ( V_136 = 0 ; V_136 < V_5 -> V_6 [ V_2 -> V_125 ] -> V_9 ; V_136 ++ ) {
V_27 = F_6 ( V_2 , V_2 -> V_125 , V_136 ,
V_38 ) ;
if ( V_27 )
F_30 ( & V_5 -> V_78 -> V_79 ,
L_11 ,
V_2 -> V_125 , V_136 , V_2 -> V_7 ) ;
V_27 = F_11 ( V_2 , V_2 -> V_125 , V_136 ,
V_38 ) ;
if ( V_27 )
F_30 ( & V_5 -> V_78 -> V_79 ,
L_12 ,
V_2 -> V_125 , V_136 , V_2 -> V_7 ) ;
}
V_133 = V_5 -> V_11 . V_12 . V_13 ;
for ( V_135 = 0 ; V_135 < V_133 ; V_135 ++ ) {
if ( 0 == V_135 )
V_50 = F_14 ( V_2 -> V_7 ) ;
else
V_50 = F_15 ( ( ( V_133 - 1 ) *
( V_2 -> V_7 ) )
+ ( V_135 - 1 ) ) ;
V_28 = ( V_142 |
V_143 ) ;
F_9 ( V_11 , V_50 , V_28 ) ;
F_10 ( V_11 ) ;
}
for ( V_135 = 0 ; V_135 < V_133 ; V_135 ++ ) {
if ( 0 == V_135 )
V_50 = F_40 ( V_2 -> V_7 ) ;
else
V_50 = F_41 ( ( ( V_133 - 1 ) *
( V_2 -> V_7 ) )
+ ( V_135 - 1 ) ) ;
F_9 ( V_11 , V_50 , V_144 ) ;
F_10 ( V_11 ) ;
}
V_28 = ( V_145 | V_146 |
V_147 ) ;
for ( V_136 = 0 ; V_136 < V_5 -> V_6 [ V_2 -> V_125 ] -> V_9 ; V_136 ++ ) {
V_17 = F_4 ( V_2 , V_2 -> V_125 , V_136 ) ;
F_9 ( V_11 , F_18 ( V_17 ) , V_28 ) ;
F_9 ( V_11 , F_19 ( V_17 ) , V_28 ) ;
}
V_28 = F_7 ( V_11 , F_37 ( V_2 -> V_7 ) ) ;
V_28 &= ~ V_140 ;
F_9 ( V_11 , F_37 ( V_2 -> V_7 ) , V_28 ) ;
F_9 ( V_11 , F_35 ( V_2 -> V_7 ) , V_148 ) ;
F_10 ( V_11 ) ;
return V_27 ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
T_3 V_28 , V_149 = 0 ;
int V_136 ;
F_9 ( V_11 , F_43 ( V_2 -> V_127 ) ,
V_150 ) ;
V_28 = V_151 ;
F_9 ( V_11 , F_44 ( V_2 -> V_7 ) , V_28 ) ;
for ( V_136 = 0 ; V_136 < V_5 -> V_6 [ V_2 -> V_125 ] -> V_9 ; V_136 ++ ) {
T_2 V_8 = F_4 ( V_2 , V_2 -> V_125 , V_136 ) ;
V_28 = ( V_8 & V_152 ) ;
F_9 ( V_11 , F_45 ( V_149 , V_2 -> V_7 ) , V_28 ) ;
V_149 ++ ;
}
for ( V_136 = 0 ; V_136 < 7 ; V_136 ++ ) {
if ( V_136 * 2 >= V_5 -> V_6 [ V_2 -> V_125 ] -> V_9 ) {
V_28 = 0x07FF07FF ;
} else {
T_2 V_8 = F_4 ( V_2 , V_2 -> V_125 ,
V_136 * 2 ) ;
V_28 = V_8 ;
V_8 = F_4 ( V_2 , V_2 -> V_125 ,
( V_136 * 2 ) + 1 ) ;
V_28 |= V_8 << 16 ;
}
F_9 ( V_11 , F_46 ( V_136 , V_2 -> V_127 ) , V_28 ) ;
}
F_10 ( V_11 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
int V_135 ;
F_9 ( V_11 , F_44 ( V_2 -> V_7 ) , 0 ) ;
for ( V_135 = 0 ; V_135 < V_56 ; V_135 ++ )
F_9 ( V_11 , F_45 ( V_135 , V_2 -> V_7 ) ,
V_18 ) ;
F_10 ( V_11 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_2 -> V_125 ) {
F_49 ( V_5 -> V_6 [ V_2 -> V_125 ] ) ;
V_2 -> V_125 = 0 ;
V_2 -> V_127 = 0 ;
}
V_2 -> V_9 = 0 ;
V_2 -> V_139 = 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_149 = 0 ;
int V_27 ;
V_27 = F_28 ( V_2 , V_124 ) ;
if ( V_27 )
goto V_153;
V_149 += V_5 -> V_6 [ V_2 -> V_125 ] -> V_9 ;
F_51 ( V_154 , & V_2 -> V_155 ) ;
V_2 -> V_9 = V_149 ;
F_51 ( V_156 , & V_2 -> V_139 ) ;
V_153:
if ( V_27 )
F_48 ( V_2 ) ;
return V_27 ;
}
static bool F_52 ( struct V_4 * V_5 )
{
struct V_157 * V_78 = V_5 -> V_78 ;
struct V_157 * V_158 ;
V_158 = F_53 ( V_159 , V_160 , NULL ) ;
while ( V_158 ) {
if ( V_158 -> V_161 && F_54 ( V_158 ) == V_78 ) {
if ( V_158 -> V_162 & V_163 )
return true ;
}
V_158 = F_53 ( V_159 ,
V_160 ,
V_158 ) ;
}
return false ;
}
void F_55 ( struct V_4 * V_5 )
{
struct V_25 * V_11 = & V_5 -> V_11 ;
int V_135 ;
if ( ! V_5 -> V_2 )
return;
F_9 ( V_11 , V_164 , 0 ) ;
F_10 ( V_11 ) ;
for ( V_135 = 0 ; V_135 < V_5 -> V_165 ; V_135 ++ ) {
if ( F_56 ( V_156 , & V_5 -> V_2 [ V_135 ] . V_139 ) )
F_48 ( & V_5 -> V_2 [ V_135 ] ) ;
F_47 ( & V_5 -> V_2 [ V_135 ] ) ;
}
F_57 ( V_5 -> V_2 ) ;
V_5 -> V_2 = NULL ;
V_5 -> V_165 = 0 ;
if ( ! F_52 ( V_5 ) )
F_58 ( V_5 -> V_78 ) ;
else
F_59 ( & V_5 -> V_78 -> V_79 ,
L_13 ) ;
F_9 ( V_11 , V_164 ,
V_166 |
V_167 |
( V_168 << V_169 ) ) ;
F_10 ( V_11 ) ;
}
static int F_60 ( struct V_4 * V_5 , T_2 V_165 )
{
struct V_1 * V_170 ;
int V_135 , V_27 = 0 ;
V_27 = F_61 ( V_5 -> V_78 , V_165 ) ;
if ( V_27 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_14 , V_27 ) ;
V_5 -> V_165 = 0 ;
goto V_171;
}
V_170 = F_62 ( V_165 * sizeof( struct V_1 ) , V_172 ) ;
if ( ! V_170 ) {
V_27 = - V_131 ;
goto V_173;
}
for ( V_135 = 0 ; V_135 < V_165 ; V_135 ++ ) {
V_170 [ V_135 ] . V_5 = V_5 ;
V_170 [ V_135 ] . V_174 = V_175 ;
V_170 [ V_135 ] . V_7 = V_135 ;
F_51 ( V_176 , & V_170 [ V_135 ] . V_155 ) ;
V_27 = F_50 ( & V_170 [ V_135 ] ) ;
F_34 ( & V_170 [ V_135 ] , true ) ;
if ( V_27 )
break;
F_42 ( & V_170 [ V_135 ] ) ;
}
V_5 -> V_2 = V_170 ;
V_5 -> V_165 = V_165 ;
V_173:
if ( V_27 )
F_55 ( V_5 ) ;
V_171:
return V_27 ;
}
static int F_63 ( struct V_157 * V_78 , int V_177 )
{
#ifdef F_64
struct V_4 * V_5 = F_65 ( V_78 ) ;
int V_178 = F_66 ( V_78 ) ;
int V_179 = 0 ;
F_30 ( & V_78 -> V_79 , L_15 , V_177 ) ;
if ( V_178 && V_178 != V_177 )
F_55 ( V_5 ) ;
else if ( V_178 && V_178 == V_177 )
goto V_180;
if ( V_177 > V_5 -> V_181 ) {
V_179 = - V_33 ;
goto V_182;
}
V_179 = F_60 ( V_5 , V_177 ) ;
if ( V_179 ) {
F_59 ( & V_78 -> V_79 , L_16 , V_179 ) ;
goto V_182;
}
V_180:
return V_177 ;
V_182:
return V_179 ;
#endif
return 0 ;
}
int F_67 ( struct V_157 * V_78 , int V_177 )
{
struct V_4 * V_5 = F_65 ( V_78 ) ;
if ( V_177 )
return F_63 ( V_78 , V_177 ) ;
F_55 ( V_5 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , T_3 V_183 ,
T_3 V_184 , T_1 * V_185 , T_2 V_186 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
T_4 V_187 ;
if ( V_184 ) {
V_2 -> V_188 ++ ;
F_22 ( & V_5 -> V_78 -> V_79 , L_17 ,
V_183 , V_184 ) ;
if ( V_2 -> V_188 >
V_189 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_18 ,
V_2 -> V_7 ) ;
F_22 ( & V_5 -> V_78 -> V_79 , L_19 ) ;
F_51 ( V_190 , & V_2 -> V_139 ) ;
}
} else {
V_2 -> V_191 ++ ;
}
V_187 = F_69 ( V_11 , V_2 -> V_7 , V_183 , V_184 ,
V_185 , V_186 , NULL ) ;
if ( V_187 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_20 ,
V_2 -> V_7 , V_5 -> V_11 . V_121 . V_122 ) ;
return - V_192 ;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 ,
enum V_193 V_194 ,
T_4 V_195 )
{
return F_68 ( V_2 , V_194 , V_195 , NULL , 0 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_196 V_19 = {
V_197 , V_198
} ;
return F_68 ( V_2 , V_199 ,
V_200 , ( T_1 * ) & V_19 ,
sizeof( struct
V_196 ) ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_201 * V_202 = NULL ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_4 V_187 = 0 ;
struct V_16 * V_6 ;
int V_135 = 0 , V_203 = 0 ;
int V_204 = 1 ;
int V_27 ;
if ( ! F_56 ( V_156 , & V_2 -> V_139 ) ) {
V_187 = V_205 ;
goto V_179;
}
V_203 = ( sizeof( struct V_201 ) +
sizeof( struct V_206 ) * V_204 ) ;
V_202 = F_62 ( V_203 , V_172 ) ;
if ( ! V_202 ) {
V_187 = V_207 ;
V_203 = 0 ;
goto V_179;
}
V_202 -> V_208 = V_209 ;
V_6 = V_5 -> V_6 [ V_2 -> V_125 ] ;
if ( ! V_6 -> V_19 . V_210 )
V_202 -> V_208 |= V_211 ;
V_202 -> V_204 = V_204 ;
V_202 -> V_9 = V_2 -> V_9 ;
V_202 -> V_212 = V_5 -> V_11 . V_12 . V_13 ;
if ( V_2 -> V_125 ) {
V_202 -> V_213 [ V_135 ] . V_3 = V_2 -> V_125 ;
V_202 -> V_213 [ V_135 ] . V_214 = V_124 ;
V_202 -> V_213 [ V_135 ] . V_9 =
V_5 -> V_6 [ V_2 -> V_125 ] -> V_9 ;
memcpy ( V_202 -> V_213 [ V_135 ] . V_215 ,
V_2 -> V_129 . V_130 , V_216 ) ;
V_135 ++ ;
}
F_51 ( V_138 , & V_2 -> V_139 ) ;
V_179:
V_27 = F_68 ( V_2 , V_217 ,
V_187 , ( T_1 * ) V_202 , V_203 ) ;
F_57 ( V_202 ) ;
return V_27 ;
}
static int F_73 ( struct V_1 * V_2 )
{
if ( ! F_56 ( V_138 , & V_2 -> V_139 ) )
return - V_80 ;
return F_34 ( V_2 , false ) ;
}
static int F_74 ( struct V_1 * V_2 ,
T_1 * V_185 , T_2 V_186 )
{
struct V_218 * V_19 =
(struct V_218 * ) V_185 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
bool V_219 = false ;
bool V_220 = false ;
T_4 V_187 ;
if ( ! F_56 ( V_138 , & V_2 -> V_139 ) ||
! F_56 ( V_154 , & V_2 -> V_155 ) ||
! F_1 ( V_2 , V_19 -> V_3 ) ||
( V_5 -> V_6 [ V_19 -> V_3 ] -> type != V_221 ) ) {
V_187 = V_205 ;
goto V_100;
}
if ( V_19 -> V_222 & V_223 )
V_220 = true ;
V_187 = F_75 ( V_11 , V_19 -> V_3 ,
V_220 , NULL ) ;
if ( V_187 )
goto V_100;
if ( V_19 -> V_222 & V_224 )
V_219 = true ;
V_187 = F_76 ( V_11 , V_19 -> V_3 ,
V_219 , NULL ) ;
V_100:
return F_70 ( V_2 ,
V_225 ,
V_187 ) ;
}
static int F_77 ( struct V_1 * V_2 , T_1 * V_185 , T_2 V_186 )
{
struct V_226 * V_227 =
(struct V_226 * ) V_185 ;
struct V_228 * V_229 ;
T_2 V_3 , V_15 ;
T_4 V_187 = 0 ;
int V_135 ;
if ( ! F_56 ( V_138 , & V_2 -> V_139 ) ) {
V_187 = V_205 ;
goto V_100;
}
V_3 = V_227 -> V_3 ;
if ( ! F_1 ( V_2 , V_3 ) ) {
V_187 = V_205 ;
goto V_100;
}
for ( V_135 = 0 ; V_135 < V_227 -> V_9 ; V_135 ++ ) {
V_229 = & V_227 -> V_230 [ V_135 ] ;
V_15 = V_229 -> V_231 . V_232 ;
if ( ( V_229 -> V_231 . V_3 != V_3 ) ||
( V_229 -> V_233 . V_3 != V_3 ) ||
( V_229 -> V_233 . V_232 != V_15 ) ||
! F_2 ( V_2 , V_3 , V_15 ) ) {
V_187 = V_205 ;
goto V_100;
}
if ( F_25 ( V_2 , V_3 , V_15 ,
& V_229 -> V_233 ) ||
F_20 ( V_2 , V_3 , V_15 ,
& V_229 -> V_231 ) ) {
V_187 = V_205 ;
goto V_100;
}
}
V_100:
return F_70 ( V_2 , V_234 ,
V_187 ) ;
}
static int F_78 ( struct V_1 * V_2 , T_1 * V_185 , T_2 V_186 )
{
struct V_235 * V_236 =
(struct V_235 * ) V_185 ;
struct V_43 * V_237 ;
T_2 V_3 , V_15 , V_10 ;
T_4 V_187 = 0 ;
unsigned long V_46 ;
int V_135 ;
if ( ! F_56 ( V_138 , & V_2 -> V_139 ) ) {
V_187 = V_205 ;
goto V_100;
}
for ( V_135 = 0 ; V_135 < V_236 -> V_238 ; V_135 ++ ) {
V_237 = & V_236 -> V_44 [ V_135 ] ;
V_10 = V_237 -> V_10 ;
V_3 = V_237 -> V_3 ;
if ( ! F_3 ( V_2 , V_10 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_187 = V_205 ;
goto V_100;
}
V_46 = V_237 -> V_52 ;
V_15 = F_16 ( & V_46 , V_56 ) ;
while ( V_15 < V_56 ) {
if ( ! F_2 ( V_2 , V_3 ,
V_15 ) ) {
V_187 = V_205 ;
goto V_100;
}
V_15 = F_17 ( & V_46 , V_56 ,
V_15 + 1 ) ;
}
V_46 = V_237 -> V_53 ;
V_15 = F_16 ( & V_46 , V_56 ) ;
while ( V_15 < V_56 ) {
if ( ! F_2 ( V_2 , V_3 ,
V_15 ) ) {
V_187 = V_205 ;
goto V_100;
}
V_15 = F_17 ( & V_46 , V_56 ,
V_15 + 1 ) ;
}
F_13 ( V_2 , V_3 , V_237 ) ;
}
V_100:
return F_70 ( V_2 , V_239 ,
V_187 ) ;
}
static int F_79 ( struct V_1 * V_2 , T_1 * V_185 , T_2 V_186 )
{
struct V_240 * V_241 =
(struct V_240 * ) V_185 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_3 = V_241 -> V_3 ;
T_4 V_187 = 0 ;
unsigned long V_46 ;
T_2 V_232 ;
if ( ! F_56 ( V_138 , & V_2 -> V_139 ) ) {
V_187 = V_205 ;
goto V_100;
}
if ( ! F_1 ( V_2 , V_3 ) ) {
V_187 = V_205 ;
goto V_100;
}
if ( ( 0 == V_241 -> V_242 ) && ( 0 == V_241 -> V_243 ) ) {
V_187 = V_205 ;
goto V_100;
}
V_46 = V_241 -> V_242 ;
V_232 = F_16 ( & V_46 , V_56 ) ;
while ( V_232 < V_56 ) {
if ( ! F_2 ( V_2 , V_3 , V_232 ) ) {
V_187 = V_205 ;
goto V_100;
}
F_11 ( V_2 , V_3 , V_232 ,
V_29 ) ;
V_232 = F_17 ( & V_46 , V_56 ,
V_232 + 1 ) ;
}
V_46 = V_241 -> V_243 ;
V_232 = F_16 ( & V_46 , V_56 ) ;
while ( V_232 < V_56 ) {
if ( ! F_2 ( V_2 , V_3 , V_232 ) ) {
V_187 = V_205 ;
goto V_100;
}
F_6 ( V_2 , V_3 , V_232 ,
V_29 ) ;
V_232 = F_17 ( & V_46 , V_56 ,
V_232 + 1 ) ;
}
F_38 ( 10 ) ;
V_46 = V_241 -> V_242 ;
V_232 = F_16 ( & V_46 , V_56 ) ;
while ( V_232 < V_56 ) {
if ( F_11 ( V_2 , V_3 , V_232 ,
V_31 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_21 ,
V_232 , V_3 , V_2 -> V_7 ) ;
}
V_232 = F_17 ( & V_46 , V_56 ,
V_232 + 1 ) ;
}
V_46 = V_241 -> V_243 ;
V_232 = F_16 ( & V_46 , V_56 ) ;
while ( V_232 < V_56 ) {
if ( F_6 ( V_2 , V_3 , V_232 ,
V_31 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_22 ,
V_232 , V_3 , V_2 -> V_7 ) ;
}
V_232 = F_17 ( & V_46 , V_56 ,
V_232 + 1 ) ;
}
V_100:
return F_70 ( V_2 , V_244 ,
V_187 ) ;
}
static int F_80 ( struct V_1 * V_2 , T_1 * V_185 , T_2 V_186 )
{
struct V_240 * V_241 =
(struct V_240 * ) V_185 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_3 = V_241 -> V_3 ;
T_4 V_187 = 0 ;
unsigned long V_46 ;
T_2 V_232 ;
if ( ! F_56 ( V_138 , & V_2 -> V_139 ) ) {
V_187 = V_205 ;
goto V_100;
}
if ( ! F_1 ( V_2 , V_241 -> V_3 ) ) {
V_187 = V_205 ;
goto V_100;
}
if ( ( 0 == V_241 -> V_242 ) && ( 0 == V_241 -> V_243 ) ) {
V_187 = V_205 ;
goto V_100;
}
V_46 = V_241 -> V_242 ;
V_232 = F_16 ( & V_46 , V_56 ) ;
while ( V_232 < V_56 ) {
if ( ! F_2 ( V_2 , V_3 , V_232 ) ) {
V_187 = V_205 ;
goto V_100;
}
F_11 ( V_2 , V_3 , V_232 ,
V_34 ) ;
V_232 = F_17 ( & V_46 , V_56 ,
V_232 + 1 ) ;
}
V_46 = V_241 -> V_243 ;
V_232 = F_16 ( & V_46 , V_56 ) ;
while ( V_232 < V_56 ) {
if ( ! F_2 ( V_2 , V_3 , V_232 ) ) {
V_187 = V_205 ;
goto V_100;
}
F_6 ( V_2 , V_3 , V_232 ,
V_34 ) ;
V_232 = F_17 ( & V_46 , V_56 ,
V_232 + 1 ) ;
}
F_38 ( 10 ) ;
V_46 = V_241 -> V_242 ;
V_232 = F_16 ( & V_46 , V_56 ) ;
while ( V_232 < V_56 ) {
if ( F_11 ( V_2 , V_3 , V_232 ,
V_35 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_21 ,
V_232 , V_3 , V_2 -> V_7 ) ;
}
V_232 = F_17 ( & V_46 , V_56 ,
V_232 + 1 ) ;
}
V_46 = V_241 -> V_243 ;
V_232 = F_16 ( & V_46 , V_56 ) ;
while ( V_232 < V_56 ) {
if ( F_6 ( V_2 , V_3 , V_232 ,
V_35 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_22 ,
V_232 , V_3 , V_2 -> V_7 ) ;
}
V_232 = F_17 ( & V_46 , V_56 ,
V_232 + 1 ) ;
}
V_100:
return F_70 ( V_2 , V_245 ,
V_187 ) ;
}
static int F_81 ( struct V_1 * V_2 , T_1 * V_185 , T_2 V_186 )
{
struct V_240 * V_241 =
(struct V_240 * ) V_185 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_246 V_247 ;
T_4 V_187 = 0 ;
struct V_16 * V_6 ;
memset ( & V_247 , 0 , sizeof( struct V_246 ) ) ;
if ( ! F_56 ( V_138 , & V_2 -> V_139 ) ) {
V_187 = V_205 ;
goto V_100;
}
if ( ! F_1 ( V_2 , V_241 -> V_3 ) ) {
V_187 = V_205 ;
goto V_100;
}
V_6 = V_5 -> V_6 [ V_241 -> V_3 ] ;
if ( ! V_6 ) {
V_187 = V_205 ;
goto V_100;
}
F_82 ( V_6 ) ;
memcpy ( & V_247 , & V_6 -> V_248 , sizeof( struct V_246 ) ) ;
V_100:
return F_68 ( V_2 , V_249 , V_187 ,
( T_1 * ) & V_247 , sizeof( V_247 ) ) ;
}
static int F_83 ( struct V_1 * V_2 , T_1 * V_185 , T_2 V_186 )
{
struct V_250 * V_251 =
(struct V_250 * ) V_185 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 = NULL ;
T_2 V_3 = V_251 -> V_3 ;
T_4 V_187 = 0 ;
int V_135 ;
if ( ! F_56 ( V_138 , & V_2 -> V_139 ) ||
! F_56 ( V_154 , & V_2 -> V_155 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_187 = V_205 ;
goto V_100;
}
for ( V_135 = 0 ; V_135 < V_251 -> V_252 ; V_135 ++ ) {
if ( F_84 ( V_251 -> V_253 [ V_135 ] . V_130 ) ||
F_85 ( V_251 -> V_253 [ V_135 ] . V_130 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_23 ,
V_251 -> V_253 [ V_135 ] . V_130 ) ;
V_187 = V_205 ;
goto V_100;
}
}
V_6 = V_5 -> V_6 [ V_3 ] ;
for ( V_135 = 0 ; V_135 < V_251 -> V_252 ; V_135 ++ ) {
struct V_117 * V_118 ;
V_118 = F_86 ( V_6 , V_251 -> V_253 [ V_135 ] . V_130 , true , false ) ;
if ( V_118 ) {
if ( F_87 ( V_6 ) )
V_118 = F_88 ( V_6 , V_251 -> V_253 [ V_135 ] . V_130 ,
true , false ) ;
else
V_118 = F_31 ( V_6 , V_251 -> V_253 [ V_135 ] . V_130 , - 1 ,
true , false ) ;
}
if ( ! V_118 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_24 ) ;
V_187 = V_205 ;
goto V_100;
}
}
if ( F_32 ( V_6 ) )
F_22 ( & V_5 -> V_78 -> V_79 , L_25 ) ;
V_100:
return F_70 ( V_2 , V_254 ,
V_187 ) ;
}
static int F_89 ( struct V_1 * V_2 , T_1 * V_185 , T_2 V_186 )
{
struct V_250 * V_251 =
(struct V_250 * ) V_185 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 = NULL ;
T_2 V_3 = V_251 -> V_3 ;
T_4 V_187 = 0 ;
int V_135 ;
if ( ! F_56 ( V_138 , & V_2 -> V_139 ) ||
! F_56 ( V_154 , & V_2 -> V_155 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_187 = V_205 ;
goto V_100;
}
V_6 = V_5 -> V_6 [ V_3 ] ;
for ( V_135 = 0 ; V_135 < V_251 -> V_252 ; V_135 ++ )
F_90 ( V_6 , V_251 -> V_253 [ V_135 ] . V_130 ,
V_255 , true , false ) ;
if ( F_32 ( V_6 ) )
F_22 ( & V_5 -> V_78 -> V_79 , L_25 ) ;
V_100:
return F_70 ( V_2 , V_256 ,
V_187 ) ;
}
static int F_91 ( struct V_1 * V_2 , T_1 * V_185 , T_2 V_186 )
{
struct V_257 * V_258 =
(struct V_257 * ) V_185 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 = NULL ;
T_2 V_3 = V_258 -> V_3 ;
T_4 V_187 = 0 ;
int V_135 ;
if ( ! F_56 ( V_138 , & V_2 -> V_139 ) ||
! F_56 ( V_154 , & V_2 -> V_155 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_187 = V_205 ;
goto V_100;
}
for ( V_135 = 0 ; V_135 < V_258 -> V_252 ; V_135 ++ ) {
if ( V_258 -> V_259 [ V_135 ] > V_260 ) {
V_187 = V_205 ;
F_22 ( & V_5 -> V_78 -> V_79 ,
L_26 , V_258 -> V_259 [ V_135 ] ) ;
goto V_100;
}
}
V_6 = V_5 -> V_6 [ V_3 ] ;
if ( V_6 -> V_19 . V_210 ) {
V_187 = V_205 ;
goto V_100;
}
F_92 ( V_6 ) ;
for ( V_135 = 0 ; V_135 < V_258 -> V_252 ; V_135 ++ ) {
int V_27 = F_93 ( V_6 , V_258 -> V_259 [ V_135 ] ) ;
if ( V_27 )
F_22 ( & V_5 -> V_78 -> V_79 ,
L_27 ,
V_258 -> V_259 [ V_135 ] , V_27 ) ;
}
V_100:
return F_70 ( V_2 , V_261 , V_187 ) ;
}
static int F_94 ( struct V_1 * V_2 , T_1 * V_185 , T_2 V_186 )
{
struct V_257 * V_258 =
(struct V_257 * ) V_185 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 = NULL ;
T_2 V_3 = V_258 -> V_3 ;
T_4 V_187 = 0 ;
int V_135 ;
if ( ! F_56 ( V_138 , & V_2 -> V_139 ) ||
! F_56 ( V_154 , & V_2 -> V_155 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_187 = V_205 ;
goto V_100;
}
for ( V_135 = 0 ; V_135 < V_258 -> V_252 ; V_135 ++ ) {
if ( V_258 -> V_259 [ V_135 ] > V_260 ) {
V_187 = V_205 ;
goto V_100;
}
}
V_6 = V_5 -> V_6 [ V_3 ] ;
if ( V_6 -> V_19 . V_210 ) {
V_187 = V_205 ;
goto V_100;
}
for ( V_135 = 0 ; V_135 < V_258 -> V_252 ; V_135 ++ ) {
int V_27 = F_95 ( V_6 , V_258 -> V_259 [ V_135 ] ) ;
if ( V_27 )
F_22 ( & V_5 -> V_78 -> V_79 ,
L_28 ,
V_258 -> V_259 [ V_135 ] , V_27 ) ;
}
V_100:
return F_70 ( V_2 , V_262 , V_187 ) ;
}
static int F_96 ( struct V_1 * V_2 , T_1 * V_185 , T_2 V_186 )
{
T_4 V_187 = 0 ;
if ( ! F_56 ( V_138 , & V_2 -> V_139 ) ||
! F_56 ( V_263 , & V_2 -> V_139 ) ) {
V_187 = V_205 ;
goto V_100;
}
V_187 = V_264 ;
V_100:
return F_70 ( V_2 , V_265 , V_187 ) ;
}
static int F_97 ( struct V_1 * V_2 , T_3 V_183 ,
T_3 V_184 , T_1 * V_185 , T_2 V_186 )
{
bool V_266 = false ;
int V_267 ;
if ( F_56 ( V_190 , & V_2 -> V_139 ) )
return V_205 ;
switch ( V_183 ) {
case V_199 :
V_267 = sizeof( struct V_196 ) ;
break;
case V_268 :
case V_217 :
V_267 = 0 ;
break;
case V_269 :
V_267 = sizeof( struct V_67 ) ;
break;
case V_270 :
V_267 = sizeof( struct V_90 ) ;
break;
case V_234 :
V_267 = sizeof( struct V_226 ) ;
if ( V_186 >= V_267 ) {
struct V_226 * V_271 =
(struct V_226 * ) V_185 ;
V_267 += ( V_271 -> V_9 *
sizeof( struct
V_228 ) ) ;
if ( V_271 -> V_9 == 0 )
V_266 = true ;
}
break;
case V_239 :
V_267 = sizeof( struct V_235 ) ;
if ( V_186 >= V_267 ) {
struct V_235 * V_272 =
(struct V_235 * ) V_185 ;
V_267 += ( V_272 -> V_238 *
sizeof( struct V_43 ) ) ;
if ( V_272 -> V_238 == 0 )
V_266 = true ;
}
break;
case V_244 :
case V_245 :
V_267 = sizeof( struct V_240 ) ;
break;
case V_254 :
case V_256 :
V_267 = sizeof( struct V_250 ) ;
if ( V_186 >= V_267 ) {
struct V_250 * V_273 =
(struct V_250 * ) V_185 ;
V_267 += V_273 -> V_252 *
sizeof( struct V_274 ) ;
if ( V_273 -> V_252 == 0 )
V_266 = true ;
}
break;
case V_261 :
case V_262 :
V_267 = sizeof( struct V_257 ) ;
if ( V_186 >= V_267 ) {
struct V_257 * V_258 =
(struct V_257 * ) V_185 ;
V_267 += V_258 -> V_252 * sizeof( T_2 ) ;
if ( V_258 -> V_252 == 0 )
V_266 = true ;
}
break;
case V_225 :
V_267 = sizeof( struct V_218 ) ;
break;
case V_249 :
V_267 = sizeof( struct V_240 ) ;
break;
case V_275 :
case V_276 :
default:
return - V_33 ;
break;
}
if ( ( V_267 != V_186 ) || ( V_266 ) ) {
F_70 ( V_2 , V_183 , V_205 ) ;
return - V_39 ;
} else {
return 0 ;
}
}
int F_98 ( struct V_4 * V_5 , T_2 V_7 , T_3 V_183 ,
T_3 V_184 , T_1 * V_185 , T_2 V_186 )
{
struct V_1 * V_2 = & ( V_5 -> V_2 [ V_7 ] ) ;
struct V_25 * V_11 = & V_5 -> V_11 ;
int V_27 ;
V_5 -> V_277 ++ ;
V_27 = F_97 ( V_2 , V_183 , V_184 , V_185 , V_186 ) ;
if ( V_27 ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_29 , V_7 ) ;
return V_27 ;
}
F_9 ( V_11 , F_35 ( V_7 ) , V_278 ) ;
switch ( V_183 ) {
case V_199 :
V_27 = F_71 ( V_2 ) ;
break;
case V_217 :
V_27 = F_72 ( V_2 ) ;
break;
case V_268 :
V_27 = F_73 ( V_2 ) ;
break;
case V_225 :
V_27 = F_74 ( V_2 , V_185 , V_186 ) ;
break;
case V_234 :
V_27 = F_77 ( V_2 , V_185 , V_186 ) ;
break;
case V_239 :
V_27 = F_78 ( V_2 , V_185 , V_186 ) ;
break;
case V_244 :
V_27 = F_79 ( V_2 , V_185 , V_186 ) ;
break;
case V_245 :
V_27 = F_80 ( V_2 , V_185 , V_186 ) ;
break;
case V_254 :
V_27 = F_83 ( V_2 , V_185 , V_186 ) ;
break;
case V_256 :
V_27 = F_89 ( V_2 , V_185 , V_186 ) ;
break;
case V_261 :
V_27 = F_91 ( V_2 , V_185 , V_186 ) ;
break;
case V_262 :
V_27 = F_94 ( V_2 , V_185 , V_186 ) ;
break;
case V_249 :
V_27 = F_81 ( V_2 , V_185 , V_186 ) ;
break;
case V_265 :
V_27 = F_96 ( V_2 , V_185 , V_186 ) ;
break;
case V_276 :
default:
F_22 ( & V_5 -> V_78 -> V_79 ,
L_30 , V_183 , V_7 ) ;
V_27 = F_70 ( V_2 , V_183 ,
V_264 ) ;
break;
}
return V_27 ;
}
int F_99 ( struct V_4 * V_5 )
{
T_3 V_28 , V_50 , V_279 , V_7 ;
struct V_25 * V_11 = & V_5 -> V_11 ;
struct V_1 * V_2 ;
if ( ! F_56 ( V_280 , & V_5 -> V_281 ) )
return 0 ;
F_36 ( V_280 , & V_5 -> V_281 ) ;
for ( V_7 = 0 ; V_7 < V_5 -> V_165 ; V_7 ++ ) {
V_50 = ( V_11 -> V_12 . V_87 + V_7 ) / 32 ;
V_279 = ( V_11 -> V_12 . V_87 + V_7 ) % 32 ;
V_2 = & V_5 -> V_2 [ V_7 ] ;
V_28 = F_7 ( V_11 , F_100 ( V_50 ) ) ;
if ( V_28 & ( 1 << V_279 ) ) {
F_9 ( V_11 , F_100 ( V_50 ) , ( 1 << V_279 ) ) ;
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
V_28 = F_7 ( V_11 , V_282 ) ;
V_28 |= V_283 ;
F_9 ( V_11 , V_282 , V_28 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static void F_101 ( struct V_4 * V_5 ,
enum V_193 V_183 ,
T_4 V_184 , T_1 * V_185 ,
T_2 V_186 )
{
struct V_25 * V_11 = & V_5 -> V_11 ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_135 ;
for ( V_135 = 0 ; V_135 < V_5 -> V_165 ; V_135 ++ ) {
F_69 ( V_11 , V_2 -> V_7 , V_183 , V_184 ,
V_185 , V_186 , NULL ) ;
V_2 ++ ;
}
}
void F_102 ( struct V_4 * V_5 )
{
struct V_284 V_285 ;
V_285 . V_286 = V_287 ;
V_285 . V_288 = V_289 ;
V_285 . V_290 . V_291 . V_292 =
V_5 -> V_11 . V_293 . V_294 . V_294 & V_295 ;
V_285 . V_290 . V_291 . V_296 = V_5 -> V_11 . V_293 . V_294 . V_296 ;
F_101 ( V_5 , V_275 , V_200 ,
( T_1 * ) & V_285 , sizeof( struct V_284 ) ) ;
}
void F_103 ( struct V_4 * V_5 )
{
struct V_284 V_285 ;
V_285 . V_286 = V_297 ;
V_285 . V_288 = V_298 ;
F_101 ( V_5 , V_275 , V_200 ,
( T_1 * ) & V_285 , sizeof( struct V_284 ) ) ;
}
void F_104 ( struct V_1 * V_2 )
{
struct V_284 V_285 ;
V_285 . V_286 = V_297 ;
V_285 . V_288 = V_298 ;
F_69 ( & V_2 -> V_5 -> V_11 , V_2 -> V_7 , V_275 ,
V_200 , ( T_1 * ) & V_285 ,
sizeof( struct V_284 ) , NULL ) ;
}
int F_105 ( struct V_299 * V_300 , int V_7 , T_1 * V_301 )
{
struct V_302 * V_303 = F_106 ( V_300 ) ;
struct V_16 * V_6 = V_303 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_304 ;
struct V_117 * V_118 ;
struct V_1 * V_2 ;
int V_27 = 0 ;
if ( V_7 >= V_5 -> V_165 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_33 , V_7 ) ;
V_27 = - V_39 ;
goto V_100;
}
V_2 = & ( V_5 -> V_2 [ V_7 ] ) ;
V_6 = V_5 -> V_6 [ V_2 -> V_125 ] ;
if ( ! F_56 ( V_156 , & V_2 -> V_139 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_34 , V_7 ) ;
V_27 = - V_39 ;
goto V_100;
}
if ( ! F_107 ( V_301 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_35 ) ;
V_27 = - V_39 ;
goto V_100;
}
F_90 ( V_6 , V_2 -> V_129 . V_130 , 0 , true , false ) ;
V_118 = F_31 ( V_6 , V_301 , 0 , true , false ) ;
if ( ! V_118 ) {
F_22 ( & V_5 -> V_78 -> V_79 ,
L_36 ) ;
V_27 = - V_131 ;
goto V_100;
}
F_30 ( & V_5 -> V_78 -> V_79 , L_37 , V_301 , V_7 ) ;
if ( F_32 ( V_6 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_8 ) ;
V_27 = - V_192 ;
goto V_100;
}
memcpy ( V_2 -> V_129 . V_130 , V_301 , V_216 ) ;
F_30 ( & V_5 -> V_78 -> V_79 , L_38 ) ;
V_27 = 0 ;
V_100:
return V_27 ;
}
int F_108 ( struct V_299 * V_300 ,
int V_7 , T_2 V_259 , T_1 V_305 )
{
struct V_302 * V_303 = F_106 ( V_300 ) ;
struct V_4 * V_5 = V_303 -> V_6 -> V_304 ;
struct V_16 * V_6 ;
struct V_1 * V_2 ;
int V_27 = 0 ;
if ( V_7 >= V_5 -> V_165 ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_33 , V_7 ) ;
V_27 = - V_39 ;
goto V_306;
}
if ( ( V_259 > V_260 ) || ( V_305 > 7 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_39 ) ;
V_27 = - V_39 ;
goto V_306;
}
V_2 = & ( V_5 -> V_2 [ V_7 ] ) ;
V_6 = V_5 -> V_6 [ V_2 -> V_125 ] ;
if ( ! F_56 ( V_156 , & V_2 -> V_139 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_34 , V_7 ) ;
V_27 = - V_39 ;
goto V_306;
}
if ( V_6 -> V_19 . V_210 ) {
V_27 = F_95 ( V_6 , ( F_5 ( V_6 -> V_19 . V_210 ) &
V_307 ) ) ;
if ( V_27 ) {
F_30 ( & V_6 -> V_304 -> V_78 -> V_79 ,
L_40 ,
V_27 , V_5 -> V_11 . V_121 . V_122 ) ;
}
}
if ( V_259 || V_305 )
V_27 = F_109 ( V_6 ,
V_259 | ( V_305 << V_308 ) ) ;
else
F_110 ( V_6 ) ;
if ( V_259 ) {
F_30 ( & V_5 -> V_78 -> V_79 , L_41 ,
V_259 , V_305 , V_7 ) ;
V_27 = F_93 ( V_6 , V_259 ) ;
if ( V_27 ) {
F_30 ( & V_6 -> V_304 -> V_78 -> V_79 ,
L_42 , V_27 ,
V_6 -> V_304 -> V_11 . V_121 . V_122 ) ;
goto V_306;
}
}
if ( V_27 ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_43 ) ;
goto V_306;
}
V_27 = 0 ;
V_306:
return V_27 ;
}
int F_111 ( struct V_299 * V_300 , int V_7 , int V_309 )
{
return - V_310 ;
}
int F_112 ( struct V_299 * V_300 ,
int V_7 , struct V_311 * V_312 )
{
struct V_302 * V_303 = F_106 ( V_300 ) ;
struct V_117 * V_118 , * V_313 ;
struct V_16 * V_6 = V_303 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_304 ;
struct V_1 * V_2 ;
int V_27 = 0 ;
if ( V_7 >= V_5 -> V_165 ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_33 , V_7 ) ;
V_27 = - V_39 ;
goto V_100;
}
V_2 = & ( V_5 -> V_2 [ V_7 ] ) ;
V_6 = V_5 -> V_6 [ V_2 -> V_125 ] ;
if ( ! F_56 ( V_156 , & V_2 -> V_139 ) ) {
F_22 ( & V_5 -> V_78 -> V_79 , L_34 , V_7 ) ;
V_27 = - V_39 ;
goto V_100;
}
V_312 -> V_2 = V_7 ;
F_113 (f, ftmp, &vsi->mac_filter_list, list) {
memcpy ( & V_312 -> V_301 , V_118 -> V_314 , V_315 ) ;
break;
}
V_312 -> V_309 = 0 ;
V_312 -> V_316 = F_5 ( V_6 -> V_19 . V_210 ) & V_317 ;
V_312 -> V_305 = ( F_5 ( V_6 -> V_19 . V_210 ) & V_318 ) >>
V_308 ;
V_27 = 0 ;
V_100:
return V_27 ;
}
