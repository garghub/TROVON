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
if ( ! F_12 ( V_26 -> V_27 , V_45 -> V_36 -> V_46 ) )
V_2 -> V_47 = V_26 -> V_27 ;
}
static int F_13 ( struct V_16 * V_17 , struct V_44 * V_45 ,
struct V_23 * V_24 , struct V_25 * V_26 ,
unsigned long * * V_48 , int * V_49 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
struct V_50 * V_51 = & V_2 -> V_18 ;
int V_37 ;
if ( V_24 -> V_52 == V_53 )
F_14 ( V_54 , V_45 -> V_36 -> V_55 ) ;
else if ( V_24 -> V_52 != V_56 )
return 0 ;
if ( V_24 -> V_52 == V_56 ||
( V_26 -> V_27 & V_57 ) == V_58 ||
V_51 -> V_59 ) {
F_14 ( V_60 , V_45 -> V_36 -> V_55 ) ;
F_14 ( V_61 , V_45 -> V_36 -> V_62 ) ;
F_14 ( V_63 , V_45 -> V_36 -> V_62 ) ;
F_14 ( V_64 , V_45 -> V_36 -> V_62 ) ;
F_14 ( V_65 , V_45 -> V_36 -> V_62 ) ;
}
if ( V_24 -> V_66 == V_67 )
return - 1 ;
switch ( V_26 -> V_27 & V_57 ) {
case V_68 :
switch ( V_26 -> V_27 ) {
case V_69 :
F_15 ( V_45 , V_26 , V_48 , V_49 ,
V_70 , V_71 ) ;
F_9 ( V_45 -> V_36 , V_71 , V_24 ,
V_51 -> V_72 ) ;
F_9 ( V_45 -> V_36 , V_73 , V_24 , V_51 -> V_72 ) ;
F_11 ( V_26 , V_2 , V_45 ) ;
V_2 -> V_74 = V_24 -> V_75 ;
return 1 ;
case V_76 :
F_15 ( V_45 , V_26 , V_48 , V_49 ,
V_70 , V_77 ) ;
F_9 ( V_45 -> V_36 , V_77 , V_24 ,
V_51 -> V_72 ) ;
F_9 ( V_45 -> V_36 , V_78 , V_24 , V_51 -> V_72 ) ;
F_11 ( V_26 , V_2 , V_45 ) ;
V_2 -> V_74 = V_24 -> V_75 ;
return 1 ;
}
return 0 ;
case V_79 :
switch ( V_26 -> V_27 ) {
case V_80 :
F_11 ( V_26 , V_2 , V_45 ) ;
V_2 -> V_74 = V_24 -> V_75 ;
return 1 ;
case V_81 :
F_11 ( V_26 , V_2 , V_45 ) ;
V_2 -> V_74 = V_24 -> V_75 ;
return 1 ;
case V_82 :
F_15 ( V_45 , V_26 , V_48 , V_49 , V_83 , V_84 ) ;
F_16 ( V_45 -> V_36 , V_83 , V_84 ) ;
F_11 ( V_26 , V_2 , V_45 ) ;
V_2 -> V_74 = V_24 -> V_75 ;
return 1 ;
case V_85 :
if ( ! V_2 -> V_7 )
V_2 -> V_7 = V_86 ;
F_17 ( V_45 -> V_36 , V_2 -> V_7 ) ;
V_2 -> V_47 = V_26 -> V_27 ;
V_2 -> V_74 = V_24 -> V_75 ;
V_2 -> V_87 ++ ;
return 1 ;
case V_88 :
F_15 ( V_45 , V_26 , V_48 , V_49 ,
V_70 , V_89 ) ;
F_9 ( V_45 -> V_36 , V_89 , V_24 ,
V_51 -> V_90 ) ;
F_11 ( V_26 , V_2 , V_45 ) ;
V_2 -> V_74 = V_24 -> V_75 ;
return 1 ;
case V_91 :
F_15 ( V_45 , V_26 , V_48 , V_49 ,
V_70 , V_92 ) ;
F_9 ( V_45 -> V_36 , V_92 , V_24 ,
V_51 -> V_93 ) ;
F_10 ( V_45 -> V_36 ,
V_94 , 0 , 1 , 0 , 0 ) ;
F_11 ( V_26 , V_2 , V_45 ) ;
V_2 -> V_74 = V_24 -> V_75 ;
return 1 ;
case V_95 :
F_15 ( V_45 , V_26 , V_48 , V_49 ,
V_70 , V_96 ) ;
F_9 ( V_45 -> V_36 , V_96 , V_24 ,
V_51 -> V_97 ) ;
F_9 ( V_45 -> V_36 , V_98 , V_24 ,
V_51 -> V_97 ) ;
F_11 ( V_26 , V_2 , V_45 ) ;
V_2 -> V_74 = V_24 -> V_75 ;
return 1 ;
case V_99 :
V_2 -> V_74 = V_24 -> V_75 ;
return 1 ;
case V_32 :
V_2 -> V_74 = V_24 -> V_75 ;
return - 1 ;
}
case V_100 :
return - 1 ;
return 0 ;
case V_58 :
V_37 = V_101 + ( ( V_26 -> V_27 - 1 ) & V_102 ) ;
F_15 ( V_45 , V_26 , V_48 , V_49 , V_83 , V_37 ) ;
F_16 ( V_45 -> V_36 , V_83 , V_37 ) ;
return 1 ;
case 0xff000000 :
return - 1 ;
}
return 0 ;
}
static int F_18 ( struct V_16 * V_17 , struct V_44 * V_45 ,
struct V_23 * V_24 , struct V_25 * V_26 ,
unsigned long * * V_48 , int * V_49 )
{
if ( V_26 -> type == V_83 || V_26 -> type == V_70 )
F_14 ( V_26 -> type , V_45 -> V_36 -> V_103 ) ;
return - 1 ;
}
static int F_19 ( struct V_1 * V_2 )
{
T_3 V_19 = V_2 -> V_18 . V_19 ;
if ( V_19 & V_104 )
return V_2 -> V_3 . V_4 ;
if ( V_19 & V_105 )
return F_1 ( V_2 ) ;
if ( V_19 & V_106 )
return V_2 -> V_5 ;
if ( V_19 & V_107 )
return V_2 -> V_3 . V_4 - 1 ;
return F_2 ( V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_10 = true ;
if ( V_2 -> V_108 ) {
int V_109 = F_19 ( V_2 ) ;
if ( V_109 >= 0 && V_109 < V_2 -> V_7 )
V_2 -> V_8 [ V_109 ] = V_2 -> V_3 ;
}
V_2 -> V_5 ++ ;
}
static void F_21 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
struct V_110 * V_111 = & ( V_2 -> V_8 [ V_6 ] ) ;
if ( ( V_2 -> V_18 . V_19 & V_112 ) &&
! V_111 -> V_10 ) {
V_111 -> V_9 = false ;
}
F_22 ( V_36 , V_6 ) ;
F_23 ( V_36 , V_113 ,
V_111 -> V_9 ) ;
if ( V_111 -> V_9 ) {
int V_114 = ( V_111 -> V_115 > V_111 -> V_116 ) ;
int V_117 = V_49 ( V_111 -> V_115 , V_111 -> V_116 ) >> 1 ;
int V_118 = F_24 ( V_111 -> V_115 , V_111 -> V_116 ) >> 1 ;
F_25 ( V_36 , V_70 , V_71 , V_111 -> V_119 ) ;
F_25 ( V_36 , V_70 , V_77 , V_111 -> V_120 ) ;
F_25 ( V_36 , V_70 , V_94 , V_114 ) ;
F_25 ( V_36 , V_70 , V_96 , V_111 -> V_121 ) ;
F_25 ( V_36 , V_70 , V_89 , V_117 ) ;
F_25 ( V_36 , V_70 , V_92 , V_118 ) ;
}
V_111 -> V_10 = false ;
}
F_26 ( V_36 , true ) ;
F_27 ( V_36 ) ;
V_2 -> V_5 = 0 ;
}
static int F_28 ( struct V_16 * V_27 , struct V_23 * V_24 ,
struct V_25 * V_26 , T_3 V_34 )
{
struct V_1 * V_2 = F_5 ( V_27 ) ;
T_3 V_19 = V_2 -> V_18 . V_19 ;
if ( V_27 -> V_122 & V_123 && V_2 -> V_8 ) {
switch ( V_26 -> V_27 ) {
case V_80 :
if ( V_19 & V_124 )
V_2 -> V_108 = true ;
else if ( V_19 & V_125 )
V_2 -> V_108 = V_34 ;
break;
case V_82 :
if ( V_19 & V_112 )
V_2 -> V_108 = V_34 ;
V_2 -> V_3 . V_9 = V_34 ;
break;
case V_81 :
if ( V_19 & V_126 )
V_2 -> V_108 = V_34 ;
break;
case V_85 :
V_2 -> V_3 . V_4 = V_34 ;
break;
case V_95 :
V_2 -> V_3 . V_121 = V_34 ;
break;
case V_69 :
V_2 -> V_3 . V_119 = V_34 ;
break;
case V_76 :
V_2 -> V_3 . V_120 = V_34 ;
break;
case V_88 :
V_2 -> V_3 . V_115 = V_34 ;
break;
case V_91 :
V_2 -> V_3 . V_116 = V_34 ;
break;
case V_99 :
if ( V_34 )
V_2 -> V_127 = V_34 ;
break;
case V_100 :
break;
default:
return 0 ;
}
if ( V_26 -> V_27 == V_2 -> V_47 )
F_20 ( V_2 ) ;
if ( V_24 -> V_75 == V_2 -> V_74
&& V_2 -> V_5 >= V_2 -> V_127 )
F_21 ( V_2 , V_24 -> V_128 -> V_36 ) ;
}
if ( V_27 -> V_122 & V_129 && V_27 -> V_130 )
V_27 -> V_130 ( V_27 , V_24 , V_26 , V_34 ) ;
return 1 ;
}
static void F_29 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
if ( V_2 -> V_29 < 0 )
return;
V_134 = & ( V_17 -> V_135 [ V_136 ] ) ;
V_132 = V_134 -> V_137 [ V_2 -> V_29 ] ;
if ( V_132 ) {
V_132 -> V_24 [ 0 ] -> V_34 [ 0 ] = 0x02 ;
F_30 ( V_17 , V_132 , V_138 ) ;
}
}
static void F_31 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
int V_139 , V_49 ;
if ( V_2 -> V_33 < 0 )
return;
if ( ! V_2 -> V_18 . V_7 )
return;
V_134 = & V_17 -> V_135 [ V_136 ] ;
V_132 = V_134 -> V_137 [ V_2 -> V_33 ] ;
if ( V_132 ) {
V_49 = V_2 -> V_18 . V_7 ;
V_139 = V_132 -> V_24 [ 0 ] -> V_42 ;
V_49 = F_24 ( V_139 , V_49 ) ;
if ( V_132 -> V_24 [ 0 ] -> V_34 [ 0 ] != V_49 ) {
V_132 -> V_24 [ 0 ] -> V_34 [ 0 ] = V_49 ;
F_30 ( V_17 , V_132 , V_138 ) ;
}
}
}
static int F_32 ( struct V_16 * V_17 , const struct V_140 * V_31 )
{
int V_141 , V_6 ;
struct V_1 * V_2 ;
struct V_50 * V_18 = V_142 ;
if ( V_31 ) {
for ( V_6 = 0 ; V_142 [ V_6 ] . V_143 ; V_6 ++ ) {
if ( V_31 -> V_144 == V_142 [ V_6 ] . V_143 ) {
V_18 = & ( V_142 [ V_6 ] ) ;
break;
}
}
}
V_17 -> V_19 |= V_145 ;
V_17 -> V_19 &= ~ V_146 ;
V_2 = F_33 ( sizeof( struct V_1 ) , V_147 ) ;
if ( ! V_2 ) {
F_34 ( & V_17 -> V_12 , L_2 ) ;
return - V_148 ;
}
V_2 -> V_18 = * V_18 ;
V_2 -> V_29 = - 1 ;
V_2 -> V_33 = - 1 ;
F_35 ( V_17 , V_2 ) ;
V_141 = F_36 ( V_17 ) ;
if ( V_141 != 0 )
goto V_149;
V_141 = F_37 ( V_17 , V_150 ) ;
if ( V_141 )
goto V_149;
if ( ! V_31 && V_2 -> V_87 == 1 ) {
V_18 = & V_2 -> V_18 ;
V_18 -> V_19 |= V_124 ;
V_18 -> V_19 &= ~ V_112 ;
V_18 -> V_19 &= ~ V_125 ;
V_18 -> V_19 &= ~ V_126 ;
}
V_2 -> V_8 = F_33 ( V_2 -> V_7 * sizeof( struct V_110 ) ,
V_147 ) ;
if ( ! V_2 -> V_8 ) {
F_34 ( & V_17 -> V_12 , L_3 ) ;
F_38 ( V_17 ) ;
V_141 = - V_148 ;
goto V_149;
}
V_141 = F_39 ( & V_17 -> V_12 . V_151 , & V_152 ) ;
F_31 ( V_17 ) ;
F_29 ( V_17 ) ;
return 0 ;
V_149:
F_40 ( V_2 ) ;
return V_141 ;
}
static int F_41 ( struct V_16 * V_17 )
{
F_31 ( V_17 ) ;
F_29 ( V_17 ) ;
return 0 ;
}
static void F_42 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
F_43 ( & V_17 -> V_12 . V_151 , & V_152 ) ;
F_38 ( V_17 ) ;
F_40 ( V_2 -> V_8 ) ;
F_40 ( V_2 ) ;
F_35 ( V_17 , NULL ) ;
}
static int T_4 F_44 ( void )
{
return F_45 ( & V_153 ) ;
}
static void T_5 F_46 ( void )
{
F_47 ( & V_153 ) ;
}
