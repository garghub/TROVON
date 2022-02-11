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
V_2 -> V_7 = V_24 -> V_33 [ 0 ] ;
if ( V_2 -> V_18 . V_7 )
V_2 -> V_7 = V_2 -> V_18 . V_7 ;
break;
}
}
static void F_9 ( struct V_34 * V_35 , unsigned int V_36 ,
struct V_23 * V_24 , int V_37 )
{
int V_38 = V_24 -> V_39 ;
int V_40 = V_24 -> V_41 ;
int V_42 = V_37 ? ( V_40 - V_38 ) / V_37 : 0 ;
F_10 ( V_35 , V_36 , V_38 , V_40 , V_42 , 0 ) ;
}
static int F_11 ( struct V_16 * V_17 , struct V_43 * V_44 ,
struct V_23 * V_24 , struct V_25 * V_26 ,
unsigned long * * V_45 , int * V_46 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
struct V_47 * V_48 = & V_2 -> V_18 ;
if ( V_24 -> V_49 == V_50 )
F_12 ( V_51 , V_44 -> V_35 -> V_52 ) ;
else if ( V_24 -> V_49 == V_53 )
F_12 ( V_54 , V_44 -> V_35 -> V_52 ) ;
else
return 0 ;
if ( V_24 -> V_55 == V_56 )
return - 1 ;
switch ( V_26 -> V_27 & V_57 ) {
case V_58 :
switch ( V_26 -> V_27 ) {
case V_59 :
F_13 ( V_44 , V_26 , V_45 , V_46 ,
V_60 , V_61 ) ;
F_9 ( V_44 -> V_35 , V_61 , V_24 ,
V_48 -> V_62 ) ;
F_9 ( V_44 -> V_35 , V_63 , V_24 , V_48 -> V_62 ) ;
if ( V_2 -> V_64 == V_26 -> V_65 ) {
V_2 -> V_66 = V_26 -> V_27 ;
V_2 -> V_67 = V_24 -> V_68 ;
}
return 1 ;
case V_69 :
F_13 ( V_44 , V_26 , V_45 , V_46 ,
V_60 , V_70 ) ;
F_9 ( V_44 -> V_35 , V_70 , V_24 ,
V_48 -> V_62 ) ;
F_9 ( V_44 -> V_35 , V_71 , V_24 , V_48 -> V_62 ) ;
if ( V_2 -> V_64 == V_26 -> V_65 ) {
V_2 -> V_66 = V_26 -> V_27 ;
V_2 -> V_67 = V_24 -> V_68 ;
}
return 1 ;
}
return 0 ;
case V_72 :
switch ( V_26 -> V_27 ) {
case V_73 :
if ( V_2 -> V_64 == V_26 -> V_65 ) {
V_2 -> V_66 = V_26 -> V_27 ;
V_2 -> V_67 = V_24 -> V_68 ;
}
return 1 ;
case V_74 :
if ( V_2 -> V_64 == V_26 -> V_65 ) {
V_2 -> V_66 = V_26 -> V_27 ;
V_2 -> V_67 = V_24 -> V_68 ;
}
return 1 ;
case V_75 :
F_13 ( V_44 , V_26 , V_45 , V_46 , V_76 , V_77 ) ;
F_14 ( V_44 -> V_35 , V_76 , V_77 ) ;
if ( V_2 -> V_64 == V_26 -> V_65 ) {
V_2 -> V_66 = V_26 -> V_27 ;
V_2 -> V_67 = V_24 -> V_68 ;
}
return 1 ;
case V_78 :
if ( ! V_2 -> V_7 )
V_2 -> V_7 = V_79 ;
F_15 ( V_44 -> V_35 , V_2 -> V_7 ) ;
V_2 -> V_66 = V_26 -> V_27 ;
V_2 -> V_67 = V_24 -> V_68 ;
V_2 -> V_64 = V_26 -> V_65 ;
return 1 ;
case V_80 :
F_13 ( V_44 , V_26 , V_45 , V_46 ,
V_60 , V_81 ) ;
F_9 ( V_44 -> V_35 , V_81 , V_24 ,
V_48 -> V_82 ) ;
if ( V_2 -> V_64 == V_26 -> V_65 ) {
V_2 -> V_66 = V_26 -> V_27 ;
V_2 -> V_67 = V_24 -> V_68 ;
}
return 1 ;
case V_83 :
F_13 ( V_44 , V_26 , V_45 , V_46 ,
V_60 , V_84 ) ;
F_9 ( V_44 -> V_35 , V_84 , V_24 ,
V_48 -> V_85 ) ;
F_10 ( V_44 -> V_35 ,
V_86 , 0 , 1 , 0 , 0 ) ;
if ( V_2 -> V_64 == V_26 -> V_65 ) {
V_2 -> V_66 = V_26 -> V_27 ;
V_2 -> V_67 = V_24 -> V_68 ;
}
return 1 ;
case V_87 :
F_13 ( V_44 , V_26 , V_45 , V_46 ,
V_60 , V_88 ) ;
F_9 ( V_44 -> V_35 , V_88 , V_24 ,
V_48 -> V_89 ) ;
F_9 ( V_44 -> V_35 , V_90 , V_24 ,
V_48 -> V_89 ) ;
if ( V_2 -> V_64 == V_26 -> V_65 ) {
V_2 -> V_66 = V_26 -> V_27 ;
V_2 -> V_67 = V_24 -> V_68 ;
}
return 1 ;
case V_91 :
if ( V_2 -> V_64 == V_26 -> V_65 )
V_2 -> V_67 = V_24 -> V_68 ;
return 1 ;
case V_32 :
if ( V_2 -> V_64 == V_26 -> V_65 )
V_2 -> V_67 = V_24 -> V_68 ;
return - 1 ;
}
return 0 ;
case 0xff000000 :
return - 1 ;
}
return 0 ;
}
static int F_16 ( struct V_16 * V_17 , struct V_43 * V_44 ,
struct V_23 * V_24 , struct V_25 * V_26 ,
unsigned long * * V_45 , int * V_46 )
{
if ( V_26 -> type == V_76 || V_26 -> type == V_60 )
F_12 ( V_26 -> type , V_44 -> V_35 -> V_92 ) ;
return - 1 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_3 V_19 = V_2 -> V_18 . V_19 ;
if ( V_19 & V_93 )
return V_2 -> V_3 . V_4 ;
if ( V_19 & V_94 )
return F_1 ( V_2 ) ;
if ( V_19 & V_95 )
return V_2 -> V_5 ;
if ( V_19 & V_96 )
return V_2 -> V_3 . V_4 - 1 ;
return F_2 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_10 = true ;
if ( V_2 -> V_97 ) {
int V_98 = F_17 ( V_2 ) ;
if ( V_98 >= 0 && V_98 < V_2 -> V_7 )
V_2 -> V_8 [ V_98 ] = V_2 -> V_3 ;
}
V_2 -> V_5 ++ ;
}
static void F_19 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
struct V_99 * V_100 = & ( V_2 -> V_8 [ V_6 ] ) ;
if ( ( V_2 -> V_18 . V_19 & V_101 ) &&
! V_100 -> V_10 ) {
V_100 -> V_9 = false ;
}
F_20 ( V_35 , V_6 ) ;
F_21 ( V_35 , V_102 ,
V_100 -> V_9 ) ;
if ( V_100 -> V_9 ) {
int V_103 = ( V_100 -> V_104 > V_100 -> V_105 ) ;
int V_106 = V_46 ( V_100 -> V_104 , V_100 -> V_105 ) >> 1 ;
int V_107 = F_22 ( V_100 -> V_104 , V_100 -> V_105 ) >> 1 ;
F_23 ( V_35 , V_60 , V_61 , V_100 -> V_108 ) ;
F_23 ( V_35 , V_60 , V_70 , V_100 -> V_109 ) ;
F_23 ( V_35 , V_60 , V_86 , V_103 ) ;
F_23 ( V_35 , V_60 , V_88 , V_100 -> V_110 ) ;
F_23 ( V_35 , V_60 , V_81 , V_106 ) ;
F_23 ( V_35 , V_60 , V_84 , V_107 ) ;
}
V_100 -> V_10 = false ;
}
F_24 ( V_35 , true ) ;
F_25 ( V_35 ) ;
V_2 -> V_5 = 0 ;
}
static int F_26 ( struct V_16 * V_27 , struct V_23 * V_24 ,
struct V_25 * V_26 , T_3 V_33 )
{
struct V_1 * V_2 = F_5 ( V_27 ) ;
T_3 V_19 = V_2 -> V_18 . V_19 ;
if ( V_27 -> V_111 & V_112 && V_2 -> V_8 ) {
switch ( V_26 -> V_27 ) {
case V_73 :
if ( V_19 & V_113 )
V_2 -> V_97 = true ;
else if ( V_19 & V_114 )
V_2 -> V_97 = V_33 ;
break;
case V_75 :
if ( V_19 & V_101 )
V_2 -> V_97 = V_33 ;
V_2 -> V_3 . V_9 = V_33 ;
break;
case V_74 :
if ( V_19 & V_115 )
V_2 -> V_97 = V_33 ;
break;
case V_78 :
V_2 -> V_3 . V_4 = V_33 ;
break;
case V_87 :
V_2 -> V_3 . V_110 = V_33 ;
break;
case V_59 :
V_2 -> V_3 . V_108 = V_33 ;
break;
case V_69 :
V_2 -> V_3 . V_109 = V_33 ;
break;
case V_80 :
V_2 -> V_3 . V_104 = V_33 ;
break;
case V_83 :
V_2 -> V_3 . V_105 = V_33 ;
break;
case V_91 :
if ( V_33 )
V_2 -> V_116 = V_33 ;
break;
default:
return 0 ;
}
if ( V_26 -> V_27 == V_2 -> V_66 ) {
F_18 ( V_2 ) ;
}
if ( V_24 -> V_68 == V_2 -> V_67
&& V_2 -> V_5 >= V_2 -> V_116 )
F_19 ( V_2 , V_24 -> V_117 -> V_35 ) ;
}
if ( V_27 -> V_111 & V_118 && V_27 -> V_119 )
V_27 -> V_119 ( V_27 , V_24 , V_26 , V_33 ) ;
return 1 ;
}
static void F_27 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
struct V_120 * V_121 ;
struct V_122 * V_123 ;
if ( V_2 -> V_29 < 0 )
return;
V_123 = & ( V_17 -> V_124 [ V_125 ] ) ;
V_121 = V_123 -> V_126 [ V_2 -> V_29 ] ;
if ( V_121 ) {
V_121 -> V_24 [ 0 ] -> V_33 [ 0 ] = 0x02 ;
F_28 ( V_17 , V_121 , V_127 ) ;
}
}
static int F_29 ( struct V_16 * V_17 , const struct V_128 * V_31 )
{
int V_129 , V_6 ;
struct V_1 * V_2 ;
struct V_47 * V_18 = V_130 ;
for ( V_6 = 0 ; V_130 [ V_6 ] . V_131 ; V_6 ++ ) {
if ( V_31 -> V_132 == V_130 [ V_6 ] . V_131 ) {
V_18 = & ( V_130 [ V_6 ] ) ;
break;
}
}
V_17 -> V_19 |= V_133 ;
V_2 = F_30 ( sizeof( struct V_1 ) , V_134 ) ;
if ( ! V_2 ) {
F_31 ( & V_17 -> V_12 , L_2 ) ;
return - V_135 ;
}
V_2 -> V_18 = * V_18 ;
V_2 -> V_29 = - 1 ;
V_2 -> V_64 = - 1 ;
F_32 ( V_17 , V_2 ) ;
V_129 = F_33 ( V_17 ) ;
if ( V_129 != 0 )
goto V_136;
V_129 = F_34 ( V_17 , V_137 ) ;
if ( V_129 )
goto V_136;
V_2 -> V_8 = F_30 ( V_2 -> V_7 * sizeof( struct V_99 ) ,
V_134 ) ;
if ( ! V_2 -> V_8 ) {
F_31 ( & V_17 -> V_12 , L_3 ) ;
F_35 ( V_17 ) ;
V_129 = - V_135 ;
goto V_136;
}
V_129 = F_36 ( & V_17 -> V_12 . V_138 , & V_139 ) ;
F_27 ( V_17 ) ;
return 0 ;
V_136:
F_37 ( V_2 ) ;
return V_129 ;
}
static int F_38 ( struct V_16 * V_17 )
{
F_27 ( V_17 ) ;
return 0 ;
}
static void F_39 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
F_40 ( & V_17 -> V_12 . V_138 , & V_139 ) ;
F_35 ( V_17 ) ;
F_37 ( V_2 -> V_8 ) ;
F_37 ( V_2 ) ;
F_32 ( V_17 , NULL ) ;
}
static int T_4 F_41 ( void )
{
return F_42 ( & V_140 ) ;
}
static void T_5 F_43 ( void )
{
F_44 ( & V_140 ) ;
}
