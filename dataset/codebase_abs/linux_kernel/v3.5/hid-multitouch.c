static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 != 0 || V_2 -> V_5 == 0 )
return V_2 -> V_3 . V_4 ;
else
return - 1 ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_8 [ V_6 ] . V_4 == V_2 -> V_3 . V_4 &&
V_2 -> V_8 [ V_6 ] . V_9 )
return V_6 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( ! V_2 -> V_8 [ V_6 ] . V_10 &&
! V_2 -> V_8 [ V_6 ] . V_9 )
return V_6 ;
}
return - 1 ;
}
static T_1 F_3 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_4 ( V_12 , struct V_16 , V_12 ) ;
struct V_1 * V_2 = F_5 ( V_17 ) ;
return sprintf ( V_15 , L_1 , V_2 -> V_18 . V_19 ) ;
}
static T_1 F_6 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 , T_2 V_20 )
{
struct V_16 * V_17 = F_4 ( V_12 , struct V_16 , V_12 ) ;
struct V_1 * V_2 = F_5 ( V_17 ) ;
unsigned long V_21 ;
if ( F_7 ( V_15 , 0 , & V_21 ) )
return - V_22 ;
V_2 -> V_18 . V_19 = V_21 ;
return V_20 ;
}
static void F_8 ( struct V_16 * V_17 ,
struct V_23 * V_24 , struct V_25 * V_26 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
switch ( V_26 -> V_27 ) {
case V_28 :
V_2 -> V_29 = V_24 -> V_30 -> V_31 ;
break;
case V_32 :
V_2 -> V_33 = V_24 -> V_30 -> V_31 ;
V_2 -> V_7 = V_24 -> V_34 [ 0 ] ;
if ( V_2 -> V_18 . V_7 )
V_2 -> V_7 = V_2 -> V_18 . V_7 ;
break;
}
}
static void F_9 ( struct V_35 * V_36 , unsigned int V_37 ,
struct V_23 * V_24 , int V_38 )
{
int V_39 = V_24 -> V_40 ;
int V_41 = V_24 -> V_42 ;
int V_43 = V_38 ? ( V_41 - V_39 ) / V_38 : 0 ;
F_10 ( V_36 , V_37 , V_39 , V_41 , V_43 , 0 ) ;
}
static void F_11 ( struct V_25 * V_26 , struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_46 * V_47 = V_2 -> V_48 ;
if ( V_47 -> V_49 >= V_50 )
return;
V_47 -> V_51 [ V_47 -> V_49 ++ ] = V_26 -> V_27 ;
}
static int F_12 ( struct V_16 * V_17 , struct V_44 * V_45 ,
struct V_23 * V_24 , struct V_25 * V_26 ,
unsigned long * * V_52 , int * V_53 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
struct V_54 * V_55 = & V_2 -> V_18 ;
int V_37 ;
if ( V_24 -> V_56 == V_57 )
F_13 ( V_58 , V_45 -> V_36 -> V_59 ) ;
else if ( V_24 -> V_56 != V_60 )
return 0 ;
if ( V_24 -> V_56 == V_60 ||
( V_26 -> V_27 & V_61 ) == V_62 ||
V_55 -> V_63 ) {
F_13 ( V_64 , V_45 -> V_36 -> V_59 ) ;
F_13 ( V_65 , V_45 -> V_36 -> V_66 ) ;
F_13 ( V_67 , V_45 -> V_36 -> V_66 ) ;
F_13 ( V_68 , V_45 -> V_36 -> V_66 ) ;
F_13 ( V_69 , V_45 -> V_36 -> V_66 ) ;
}
if ( V_24 -> V_70 == V_71 )
return - 1 ;
switch ( V_26 -> V_27 & V_61 ) {
case V_72 :
switch ( V_26 -> V_27 ) {
case V_73 :
F_14 ( V_45 , V_26 , V_52 , V_53 ,
V_74 , V_75 ) ;
F_9 ( V_45 -> V_36 , V_75 , V_24 ,
V_55 -> V_76 ) ;
F_9 ( V_45 -> V_36 , V_77 , V_24 , V_55 -> V_76 ) ;
F_11 ( V_26 , V_2 , V_45 ) ;
V_2 -> V_78 = V_24 -> V_79 ;
return 1 ;
case V_80 :
F_14 ( V_45 , V_26 , V_52 , V_53 ,
V_74 , V_81 ) ;
F_9 ( V_45 -> V_36 , V_81 , V_24 ,
V_55 -> V_76 ) ;
F_9 ( V_45 -> V_36 , V_82 , V_24 , V_55 -> V_76 ) ;
F_11 ( V_26 , V_2 , V_45 ) ;
V_2 -> V_78 = V_24 -> V_79 ;
return 1 ;
}
return 0 ;
case V_83 :
switch ( V_26 -> V_27 ) {
case V_84 :
F_11 ( V_26 , V_2 , V_45 ) ;
V_2 -> V_78 = V_24 -> V_79 ;
return 1 ;
case V_85 :
F_11 ( V_26 , V_2 , V_45 ) ;
V_2 -> V_78 = V_24 -> V_79 ;
return 1 ;
case V_86 :
F_14 ( V_45 , V_26 , V_52 , V_53 , V_87 , V_88 ) ;
F_15 ( V_45 -> V_36 , V_87 , V_88 ) ;
F_11 ( V_26 , V_2 , V_45 ) ;
V_2 -> V_78 = V_24 -> V_79 ;
return 1 ;
case V_89 :
if ( ! V_2 -> V_7 )
V_2 -> V_7 = V_90 ;
F_16 ( V_45 -> V_36 , V_2 -> V_7 ) ;
F_11 ( V_26 , V_2 , V_45 ) ;
V_2 -> V_78 = V_24 -> V_79 ;
V_2 -> V_91 ++ ;
return 1 ;
case V_92 :
F_14 ( V_45 , V_26 , V_52 , V_53 ,
V_74 , V_93 ) ;
F_9 ( V_45 -> V_36 , V_93 , V_24 ,
V_55 -> V_94 ) ;
F_11 ( V_26 , V_2 , V_45 ) ;
V_2 -> V_78 = V_24 -> V_79 ;
return 1 ;
case V_95 :
F_14 ( V_45 , V_26 , V_52 , V_53 ,
V_74 , V_96 ) ;
F_9 ( V_45 -> V_36 , V_96 , V_24 ,
V_55 -> V_97 ) ;
F_10 ( V_45 -> V_36 ,
V_98 , 0 , 1 , 0 , 0 ) ;
F_11 ( V_26 , V_2 , V_45 ) ;
V_2 -> V_78 = V_24 -> V_79 ;
return 1 ;
case V_99 :
F_14 ( V_45 , V_26 , V_52 , V_53 ,
V_74 , V_100 ) ;
F_9 ( V_45 -> V_36 , V_100 , V_24 ,
V_55 -> V_101 ) ;
F_9 ( V_45 -> V_36 , V_102 , V_24 ,
V_55 -> V_101 ) ;
F_11 ( V_26 , V_2 , V_45 ) ;
V_2 -> V_78 = V_24 -> V_79 ;
return 1 ;
case V_103 :
V_2 -> V_78 = V_24 -> V_79 ;
return 1 ;
case V_32 :
V_2 -> V_78 = V_24 -> V_79 ;
return - 1 ;
}
case V_104 :
return - 1 ;
return 0 ;
case V_62 :
V_37 = V_105 + ( ( V_26 -> V_27 - 1 ) & V_106 ) ;
F_14 ( V_45 , V_26 , V_52 , V_53 , V_87 , V_37 ) ;
F_15 ( V_45 -> V_36 , V_87 , V_37 ) ;
return 1 ;
case 0xff000000 :
return - 1 ;
}
return 0 ;
}
static int F_17 ( struct V_16 * V_17 , struct V_44 * V_45 ,
struct V_23 * V_24 , struct V_25 * V_26 ,
unsigned long * * V_52 , int * V_53 )
{
if ( V_26 -> type == V_87 || V_26 -> type == V_74 )
F_13 ( V_26 -> type , V_45 -> V_36 -> V_107 ) ;
return - 1 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_3 V_19 = V_2 -> V_18 . V_19 ;
if ( V_19 & V_108 )
return V_2 -> V_3 . V_4 ;
if ( V_19 & V_109 )
return F_1 ( V_2 ) ;
if ( V_19 & V_110 )
return V_2 -> V_5 ;
if ( V_19 & V_111 )
return V_2 -> V_3 . V_4 - 1 ;
return F_2 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_10 = true ;
if ( V_2 -> V_112 ) {
int V_113 = F_18 ( V_2 ) ;
if ( V_113 >= 0 && V_113 < V_2 -> V_7 )
V_2 -> V_8 [ V_113 ] = V_2 -> V_3 ;
}
V_2 -> V_5 ++ ;
}
static void F_20 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
struct V_114 * V_115 = & ( V_2 -> V_8 [ V_6 ] ) ;
if ( ( V_2 -> V_18 . V_19 & V_116 ) &&
! V_115 -> V_10 ) {
V_115 -> V_9 = false ;
}
F_21 ( V_36 , V_6 ) ;
F_22 ( V_36 , V_117 ,
V_115 -> V_9 ) ;
if ( V_115 -> V_9 ) {
int V_118 = ( V_115 -> V_119 > V_115 -> V_120 ) ;
int V_121 = V_53 ( V_115 -> V_119 , V_115 -> V_120 ) >> 1 ;
int V_122 = F_23 ( V_115 -> V_119 , V_115 -> V_120 ) >> 1 ;
F_24 ( V_36 , V_74 , V_75 , V_115 -> V_123 ) ;
F_24 ( V_36 , V_74 , V_81 , V_115 -> V_124 ) ;
F_24 ( V_36 , V_74 , V_98 , V_118 ) ;
F_24 ( V_36 , V_74 , V_100 , V_115 -> V_125 ) ;
F_24 ( V_36 , V_74 , V_93 , V_121 ) ;
F_24 ( V_36 , V_74 , V_96 , V_122 ) ;
}
V_115 -> V_10 = false ;
}
F_25 ( V_36 , true ) ;
F_26 ( V_36 ) ;
V_2 -> V_5 = 0 ;
}
static int F_27 ( struct V_16 * V_27 , struct V_23 * V_24 ,
struct V_25 * V_26 , T_3 V_34 )
{
struct V_1 * V_2 = F_5 ( V_27 ) ;
T_3 V_19 = V_2 -> V_18 . V_19 ;
if ( V_27 -> V_126 & V_127 && V_2 -> V_8 ) {
switch ( V_26 -> V_27 ) {
case V_84 :
if ( V_19 & V_128 )
V_2 -> V_112 = true ;
else if ( V_19 & V_129 )
V_2 -> V_112 = V_34 ;
break;
case V_86 :
if ( V_19 & V_116 )
V_2 -> V_112 = V_34 ;
V_2 -> V_3 . V_9 = V_34 ;
break;
case V_85 :
if ( V_19 & V_130 )
V_2 -> V_112 = V_34 ;
break;
case V_89 :
V_2 -> V_3 . V_4 = V_34 ;
break;
case V_99 :
V_2 -> V_3 . V_125 = V_34 ;
break;
case V_73 :
V_2 -> V_3 . V_123 = V_34 ;
break;
case V_80 :
V_2 -> V_3 . V_124 = V_34 ;
break;
case V_92 :
V_2 -> V_3 . V_119 = V_34 ;
break;
case V_95 :
V_2 -> V_3 . V_120 = V_34 ;
break;
case V_103 :
if ( V_34 )
V_2 -> V_131 = V_34 ;
break;
case V_104 :
break;
default:
return 0 ;
}
if ( V_26 -> V_27 == V_2 -> V_132 )
F_19 ( V_2 ) ;
if ( V_24 -> V_79 == V_2 -> V_78
&& V_2 -> V_5 >= V_2 -> V_131 )
F_20 ( V_2 , V_24 -> V_133 -> V_36 ) ;
}
if ( V_27 -> V_126 & V_134 && V_27 -> V_135 )
V_27 -> V_135 ( V_27 , V_24 , V_26 , V_34 ) ;
return 1 ;
}
static void F_28 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
struct V_136 * V_137 ;
struct V_138 * V_139 ;
if ( V_2 -> V_29 < 0 )
return;
V_139 = & ( V_17 -> V_140 [ V_141 ] ) ;
V_137 = V_139 -> V_142 [ V_2 -> V_29 ] ;
if ( V_137 ) {
V_137 -> V_24 [ 0 ] -> V_34 [ 0 ] = 0x02 ;
F_29 ( V_17 , V_137 , V_143 ) ;
}
}
static void F_30 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
struct V_136 * V_137 ;
struct V_138 * V_139 ;
int V_144 , V_53 ;
if ( V_2 -> V_33 < 0 )
return;
if ( ! V_2 -> V_18 . V_7 )
return;
V_139 = & V_17 -> V_140 [ V_141 ] ;
V_137 = V_139 -> V_142 [ V_2 -> V_33 ] ;
if ( V_137 ) {
V_53 = V_2 -> V_18 . V_7 ;
V_144 = V_137 -> V_24 [ 0 ] -> V_42 ;
V_53 = F_23 ( V_144 , V_53 ) ;
if ( V_137 -> V_24 [ 0 ] -> V_34 [ 0 ] != V_53 ) {
V_137 -> V_24 [ 0 ] -> V_34 [ 0 ] = V_53 ;
F_29 ( V_17 , V_137 , V_143 ) ;
}
}
}
static void F_31 ( struct V_1 * V_2 )
{
T_3 V_19 = V_2 -> V_18 . V_19 ;
if ( V_2 -> V_91 == 1 ) {
V_19 |= V_128 ;
V_19 &= ~ V_116 ;
V_19 &= ~ V_129 ;
V_19 &= ~ V_130 ;
}
V_2 -> V_18 . V_19 = V_19 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_48 ;
if ( V_2 -> V_91 > 0 ) {
int V_145 = V_47 -> V_49 / V_2 -> V_91 ;
V_2 -> V_132 = V_47 -> V_51 [ V_145 - 1 ] ;
}
}
static int F_33 ( struct V_16 * V_17 , const struct V_146 * V_31 )
{
int V_147 , V_6 ;
struct V_1 * V_2 ;
struct V_54 * V_18 = V_148 ;
if ( V_31 ) {
for ( V_6 = 0 ; V_148 [ V_6 ] . V_149 ; V_6 ++ ) {
if ( V_31 -> V_150 == V_148 [ V_6 ] . V_149 ) {
V_18 = & ( V_148 [ V_6 ] ) ;
break;
}
}
}
V_17 -> V_19 |= V_151 ;
V_2 = F_34 ( sizeof( struct V_1 ) , V_152 ) ;
if ( ! V_2 ) {
F_35 ( & V_17 -> V_12 , L_2 ) ;
return - V_153 ;
}
V_2 -> V_18 = * V_18 ;
V_2 -> V_29 = - 1 ;
V_2 -> V_33 = - 1 ;
F_36 ( V_17 , V_2 ) ;
V_2 -> V_48 = F_34 ( sizeof( struct V_46 ) , V_152 ) ;
if ( ! V_2 -> V_48 ) {
F_35 ( & V_17 -> V_12 , L_3 ) ;
V_147 = - V_153 ;
goto V_154;
}
V_147 = F_37 ( V_17 ) ;
if ( V_147 != 0 )
goto V_154;
V_147 = F_38 ( V_17 , V_155 ) ;
if ( V_147 )
goto V_154;
F_32 ( V_2 ) ;
if ( V_31 -> V_156 == V_157 && V_31 -> V_158 == V_157 )
F_31 ( V_2 ) ;
V_2 -> V_8 = F_34 ( V_2 -> V_7 * sizeof( struct V_114 ) ,
V_152 ) ;
if ( ! V_2 -> V_8 ) {
F_35 ( & V_17 -> V_12 , L_4 ) ;
F_39 ( V_17 ) ;
V_147 = - V_153 ;
goto V_154;
}
V_147 = F_40 ( & V_17 -> V_12 . V_159 , & V_160 ) ;
F_30 ( V_17 ) ;
F_28 ( V_17 ) ;
F_41 ( V_2 -> V_48 ) ;
V_2 -> V_48 = NULL ;
return 0 ;
V_154:
F_41 ( V_2 -> V_48 ) ;
F_41 ( V_2 ) ;
return V_147 ;
}
static int F_42 ( struct V_16 * V_17 )
{
F_30 ( V_17 ) ;
F_28 ( V_17 ) ;
return 0 ;
}
static void F_43 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
F_44 ( & V_17 -> V_12 . V_159 , & V_160 ) ;
F_39 ( V_17 ) ;
F_41 ( V_2 -> V_8 ) ;
F_41 ( V_2 ) ;
F_36 ( V_17 , NULL ) ;
}
static int T_4 F_45 ( void )
{
return F_46 ( & V_161 ) ;
}
static void T_5 F_47 ( void )
{
F_48 ( & V_161 ) ;
}
