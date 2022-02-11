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
int V_6 ;
switch ( V_26 -> V_27 ) {
case V_28 :
V_2 -> V_29 = V_24 -> V_30 -> V_31 ;
V_2 -> V_32 = 0 ;
for ( V_6 = 0 ; V_6 < V_24 -> V_33 ; V_6 ++ ) {
if ( V_24 -> V_26 [ V_6 ] . V_27 == V_26 -> V_27 ) {
V_2 -> V_32 = V_6 ;
break;
}
}
break;
case V_34 :
V_2 -> V_35 = V_24 -> V_30 -> V_31 ;
V_2 -> V_7 = V_24 -> V_36 [ 0 ] ;
if ( V_2 -> V_18 . V_7 )
V_2 -> V_7 = V_2 -> V_18 . V_7 ;
break;
}
}
static void F_9 ( struct V_37 * V_38 , unsigned int V_39 ,
struct V_23 * V_24 , int V_40 )
{
int V_41 = V_24 -> V_42 ;
int V_43 = V_24 -> V_44 ;
int V_45 = V_40 ? ( V_43 - V_41 ) / V_40 : 0 ;
F_10 ( V_38 , V_39 , V_41 , V_43 , V_45 , 0 ) ;
}
static void F_11 ( struct V_25 * V_26 , struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_48 * V_49 = V_2 -> V_50 ;
if ( V_49 -> V_51 >= V_52 )
return;
V_49 -> V_53 [ V_49 -> V_51 ++ ] = V_26 -> V_27 ;
}
static int F_12 ( struct V_16 * V_17 , struct V_46 * V_47 ,
struct V_23 * V_24 , struct V_25 * V_26 ,
unsigned long * * V_54 , int * V_55 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
struct V_56 * V_57 = & V_2 -> V_18 ;
int V_39 ;
if ( V_24 -> V_58 == V_59 )
F_13 ( V_60 , V_47 -> V_38 -> V_61 ) ;
else if ( V_24 -> V_58 != V_62 )
return 0 ;
if ( V_24 -> V_58 == V_62 ||
( V_26 -> V_27 & V_63 ) == V_64 ||
V_57 -> V_65 ) {
F_13 ( V_66 , V_47 -> V_38 -> V_61 ) ;
F_13 ( V_67 , V_47 -> V_38 -> V_68 ) ;
F_13 ( V_69 , V_47 -> V_38 -> V_68 ) ;
F_13 ( V_70 , V_47 -> V_38 -> V_68 ) ;
F_13 ( V_71 , V_47 -> V_38 -> V_68 ) ;
}
if ( V_24 -> V_72 == V_73 )
return - 1 ;
switch ( V_26 -> V_27 & V_63 ) {
case V_74 :
switch ( V_26 -> V_27 ) {
case V_75 :
F_14 ( V_47 , V_26 , V_54 , V_55 ,
V_76 , V_77 ) ;
F_9 ( V_47 -> V_38 , V_77 , V_24 ,
V_57 -> V_78 ) ;
F_9 ( V_47 -> V_38 , V_79 , V_24 , V_57 -> V_78 ) ;
F_11 ( V_26 , V_2 , V_47 ) ;
V_2 -> V_80 = V_24 -> V_81 ;
return 1 ;
case V_82 :
F_14 ( V_47 , V_26 , V_54 , V_55 ,
V_76 , V_83 ) ;
F_9 ( V_47 -> V_38 , V_83 , V_24 ,
V_57 -> V_78 ) ;
F_9 ( V_47 -> V_38 , V_84 , V_24 , V_57 -> V_78 ) ;
F_11 ( V_26 , V_2 , V_47 ) ;
V_2 -> V_80 = V_24 -> V_81 ;
return 1 ;
}
return 0 ;
case V_85 :
switch ( V_26 -> V_27 ) {
case V_86 :
F_11 ( V_26 , V_2 , V_47 ) ;
V_2 -> V_80 = V_24 -> V_81 ;
return 1 ;
case V_87 :
F_11 ( V_26 , V_2 , V_47 ) ;
V_2 -> V_80 = V_24 -> V_81 ;
return 1 ;
case V_88 :
F_14 ( V_47 , V_26 , V_54 , V_55 , V_89 , V_90 ) ;
F_15 ( V_47 -> V_38 , V_89 , V_90 ) ;
F_11 ( V_26 , V_2 , V_47 ) ;
V_2 -> V_80 = V_24 -> V_81 ;
return 1 ;
case V_91 :
if ( ! V_2 -> V_7 )
V_2 -> V_7 = V_92 ;
F_16 ( V_47 -> V_38 , V_2 -> V_7 ) ;
F_11 ( V_26 , V_2 , V_47 ) ;
V_2 -> V_80 = V_24 -> V_81 ;
V_2 -> V_93 ++ ;
return 1 ;
case V_94 :
F_14 ( V_47 , V_26 , V_54 , V_55 ,
V_76 , V_95 ) ;
F_9 ( V_47 -> V_38 , V_95 , V_24 ,
V_57 -> V_96 ) ;
F_11 ( V_26 , V_2 , V_47 ) ;
V_2 -> V_80 = V_24 -> V_81 ;
return 1 ;
case V_97 :
F_14 ( V_47 , V_26 , V_54 , V_55 ,
V_76 , V_98 ) ;
F_9 ( V_47 -> V_38 , V_98 , V_24 ,
V_57 -> V_99 ) ;
F_10 ( V_47 -> V_38 ,
V_100 , 0 , 1 , 0 , 0 ) ;
F_11 ( V_26 , V_2 , V_47 ) ;
V_2 -> V_80 = V_24 -> V_81 ;
return 1 ;
case V_101 :
F_14 ( V_47 , V_26 , V_54 , V_55 ,
V_76 , V_102 ) ;
F_9 ( V_47 -> V_38 , V_102 , V_24 ,
V_57 -> V_103 ) ;
F_9 ( V_47 -> V_38 , V_104 , V_24 ,
V_57 -> V_103 ) ;
F_11 ( V_26 , V_2 , V_47 ) ;
V_2 -> V_80 = V_24 -> V_81 ;
return 1 ;
case V_105 :
V_2 -> V_80 = V_24 -> V_81 ;
return 1 ;
case V_34 :
V_2 -> V_80 = V_24 -> V_81 ;
return - 1 ;
}
case V_106 :
return - 1 ;
return 0 ;
case V_64 :
V_39 = V_107 + ( ( V_26 -> V_27 - 1 ) & V_108 ) ;
F_14 ( V_47 , V_26 , V_54 , V_55 , V_89 , V_39 ) ;
F_15 ( V_47 -> V_38 , V_89 , V_39 ) ;
return 1 ;
case 0xff000000 :
return - 1 ;
}
return 0 ;
}
static int F_17 ( struct V_16 * V_17 , struct V_46 * V_47 ,
struct V_23 * V_24 , struct V_25 * V_26 ,
unsigned long * * V_54 , int * V_55 )
{
if ( V_26 -> type == V_89 || V_26 -> type == V_76 )
F_13 ( V_26 -> type , V_47 -> V_38 -> V_109 ) ;
return - 1 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_3 V_19 = V_2 -> V_18 . V_19 ;
if ( V_19 & V_110 )
return V_2 -> V_3 . V_4 ;
if ( V_19 & V_111 )
return F_1 ( V_2 ) ;
if ( V_19 & V_112 )
return V_2 -> V_5 ;
if ( V_19 & V_113 )
return V_2 -> V_3 . V_4 - 1 ;
return F_2 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_10 = true ;
if ( V_2 -> V_114 ) {
int V_115 = F_18 ( V_2 ) ;
if ( V_115 >= 0 && V_115 < V_2 -> V_7 )
V_2 -> V_8 [ V_115 ] = V_2 -> V_3 ;
}
V_2 -> V_5 ++ ;
}
static void F_20 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
struct V_116 * V_117 = & ( V_2 -> V_8 [ V_6 ] ) ;
if ( ( V_2 -> V_18 . V_19 & V_118 ) &&
! V_117 -> V_10 ) {
V_117 -> V_9 = false ;
}
F_21 ( V_38 , V_6 ) ;
F_22 ( V_38 , V_119 ,
V_117 -> V_9 ) ;
if ( V_117 -> V_9 ) {
int V_120 = ( V_117 -> V_121 > V_117 -> V_122 ) ;
int V_123 = V_55 ( V_117 -> V_121 , V_117 -> V_122 ) >> 1 ;
int V_124 = F_23 ( V_117 -> V_121 , V_117 -> V_122 ) >> 1 ;
F_24 ( V_38 , V_76 , V_77 , V_117 -> V_125 ) ;
F_24 ( V_38 , V_76 , V_83 , V_117 -> V_126 ) ;
F_24 ( V_38 , V_76 , V_100 , V_120 ) ;
F_24 ( V_38 , V_76 , V_102 , V_117 -> V_127 ) ;
F_24 ( V_38 , V_76 , V_95 , V_123 ) ;
F_24 ( V_38 , V_76 , V_98 , V_124 ) ;
}
V_117 -> V_10 = false ;
}
F_25 ( V_38 , true ) ;
F_26 ( V_38 ) ;
V_2 -> V_5 = 0 ;
}
static int F_27 ( struct V_16 * V_27 , struct V_23 * V_24 ,
struct V_25 * V_26 , T_3 V_36 )
{
struct V_1 * V_2 = F_5 ( V_27 ) ;
T_3 V_19 = V_2 -> V_18 . V_19 ;
if ( V_27 -> V_128 & V_129 && V_2 -> V_8 ) {
switch ( V_26 -> V_27 ) {
case V_86 :
if ( V_19 & V_130 )
V_2 -> V_114 = true ;
else if ( V_19 & V_131 )
V_2 -> V_114 = V_36 ;
break;
case V_88 :
if ( V_19 & V_118 )
V_2 -> V_114 = V_36 ;
V_2 -> V_3 . V_9 = V_36 ;
break;
case V_87 :
if ( V_19 & V_132 )
V_2 -> V_114 = V_36 ;
break;
case V_91 :
V_2 -> V_3 . V_4 = V_36 ;
break;
case V_101 :
V_2 -> V_3 . V_127 = V_36 ;
break;
case V_75 :
V_2 -> V_3 . V_125 = V_36 ;
break;
case V_82 :
V_2 -> V_3 . V_126 = V_36 ;
break;
case V_94 :
V_2 -> V_3 . V_121 = V_36 ;
break;
case V_97 :
V_2 -> V_3 . V_122 = V_36 ;
break;
case V_105 :
if ( V_36 )
V_2 -> V_133 = V_36 ;
break;
case V_106 :
break;
default:
return 0 ;
}
if ( V_26 -> V_27 == V_2 -> V_134 )
F_19 ( V_2 ) ;
if ( V_24 -> V_81 == V_2 -> V_80
&& V_2 -> V_5 >= V_2 -> V_133 )
F_20 ( V_2 , V_24 -> V_135 -> V_38 ) ;
}
if ( V_27 -> V_128 & V_136 && V_27 -> V_137 )
V_27 -> V_137 ( V_27 , V_24 , V_26 , V_36 ) ;
return 1 ;
}
static void F_28 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
struct V_138 * V_139 ;
struct V_140 * V_141 ;
if ( V_2 -> V_29 < 0 )
return;
V_141 = & ( V_17 -> V_142 [ V_143 ] ) ;
V_139 = V_141 -> V_144 [ V_2 -> V_29 ] ;
if ( V_139 ) {
V_139 -> V_24 [ 0 ] -> V_36 [ V_2 -> V_32 ] = 0x02 ;
F_29 ( V_17 , V_139 , V_145 ) ;
}
}
static void F_30 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
struct V_138 * V_139 ;
struct V_140 * V_141 ;
int V_146 , V_55 ;
if ( V_2 -> V_35 < 0 )
return;
if ( ! V_2 -> V_18 . V_7 )
return;
V_141 = & V_17 -> V_142 [ V_143 ] ;
V_139 = V_141 -> V_144 [ V_2 -> V_35 ] ;
if ( V_139 ) {
V_55 = V_2 -> V_18 . V_7 ;
V_146 = V_139 -> V_24 [ 0 ] -> V_44 ;
V_55 = F_23 ( V_146 , V_55 ) ;
if ( V_139 -> V_24 [ 0 ] -> V_36 [ 0 ] != V_55 ) {
V_139 -> V_24 [ 0 ] -> V_36 [ 0 ] = V_55 ;
F_29 ( V_17 , V_139 , V_145 ) ;
}
}
}
static void F_31 ( struct V_1 * V_2 )
{
T_3 V_19 = V_2 -> V_18 . V_19 ;
if ( V_2 -> V_93 == 1 ) {
V_19 |= V_130 ;
V_19 &= ~ V_118 ;
V_19 &= ~ V_131 ;
V_19 &= ~ V_132 ;
}
V_2 -> V_18 . V_19 = V_19 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_50 ;
if ( V_2 -> V_93 > 0 ) {
int V_147 = V_49 -> V_51 / V_2 -> V_93 ;
V_2 -> V_134 = V_49 -> V_53 [ V_147 - 1 ] ;
}
}
static int F_33 ( struct V_16 * V_17 , const struct V_148 * V_31 )
{
int V_149 , V_6 ;
struct V_1 * V_2 ;
struct V_56 * V_18 = V_150 ;
if ( V_31 ) {
for ( V_6 = 0 ; V_150 [ V_6 ] . V_151 ; V_6 ++ ) {
if ( V_31 -> V_152 == V_150 [ V_6 ] . V_151 ) {
V_18 = & ( V_150 [ V_6 ] ) ;
break;
}
}
}
V_17 -> V_19 |= V_153 ;
V_2 = F_34 ( sizeof( struct V_1 ) , V_154 ) ;
if ( ! V_2 ) {
F_35 ( & V_17 -> V_12 , L_2 ) ;
return - V_155 ;
}
V_2 -> V_18 = * V_18 ;
V_2 -> V_29 = - 1 ;
V_2 -> V_35 = - 1 ;
F_36 ( V_17 , V_2 ) ;
V_2 -> V_50 = F_34 ( sizeof( struct V_48 ) , V_154 ) ;
if ( ! V_2 -> V_50 ) {
F_35 ( & V_17 -> V_12 , L_3 ) ;
V_149 = - V_155 ;
goto V_156;
}
V_149 = F_37 ( V_17 ) ;
if ( V_149 != 0 )
goto V_156;
V_149 = F_38 ( V_17 , V_157 ) ;
if ( V_149 )
goto V_156;
F_32 ( V_2 ) ;
if ( V_31 -> V_158 == V_159 && V_31 -> V_160 == V_159 )
F_31 ( V_2 ) ;
V_2 -> V_8 = F_34 ( V_2 -> V_7 * sizeof( struct V_116 ) ,
V_154 ) ;
if ( ! V_2 -> V_8 ) {
F_35 ( & V_17 -> V_12 , L_4 ) ;
F_39 ( V_17 ) ;
V_149 = - V_155 ;
goto V_156;
}
V_149 = F_40 ( & V_17 -> V_12 . V_161 , & V_162 ) ;
F_30 ( V_17 ) ;
F_28 ( V_17 ) ;
F_41 ( V_2 -> V_50 ) ;
V_2 -> V_50 = NULL ;
return 0 ;
V_156:
F_41 ( V_2 -> V_50 ) ;
F_41 ( V_2 ) ;
return V_149 ;
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
F_44 ( & V_17 -> V_12 . V_161 , & V_162 ) ;
F_39 ( V_17 ) ;
F_41 ( V_2 -> V_8 ) ;
F_41 ( V_2 ) ;
F_36 ( V_17 , NULL ) ;
}
static int T_4 F_45 ( void )
{
return F_46 ( & V_163 ) ;
}
static void T_5 F_47 ( void )
{
F_48 ( & V_163 ) ;
}
