static int F_1 ( struct V_1 * V_2 ,
enum V_3 time )
{
int V_4 ;
switch ( time ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
V_4 = F_2 ( V_2 -> V_9 ,
V_10 ,
time << V_11 ,
V_12 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_13 , L_1 ) ;
return V_4 ;
}
break;
default:
F_3 ( V_2 -> V_13 , L_2 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_15 , bool V_16 )
{
int V_4 = 0 ;
T_1 V_17 , V_18 = 0 ;
if ( V_16 )
V_17 = V_15 ;
else
V_17 = V_19 ;
V_4 = F_2 ( V_2 -> V_9 ,
V_20 , V_17 , V_21 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_3 ) ;
return V_4 ;
}
if ( V_16 )
V_18 |= V_22 ;
else
V_18 |= V_23 ;
V_4 = F_2 ( V_2 -> V_9 ,
V_24 , V_18 ,
V_23 | V_22 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_3 ) ;
return V_4 ;
}
F_5 ( V_2 -> V_13 ,
L_4 ,
V_17 , V_18 , V_16 ? L_5 : L_6 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
enum V_25 V_26 , bool * V_16 )
{
int V_27 = 0 ;
int V_28 ;
int V_29 ;
switch ( V_26 ) {
case V_30 :
V_28 = V_2 -> V_31 [ 0 ] & V_32 ;
V_28 >>= V_33 ;
if ( V_28 == V_34 ) {
* V_16 = false ;
V_27 = V_2 -> V_35 ;
V_2 -> V_35 = V_34 ;
} else {
* V_16 = true ;
V_27 = V_2 -> V_35 = V_28 ;
}
break;
case V_36 :
V_29 = V_2 -> V_31 [ 1 ] & V_37 ;
V_29 >>= V_38 ;
if ( V_29 == V_39 ) {
* V_16 = false ;
V_27 = V_2 -> V_40 ;
V_2 -> V_40 = V_39 ;
} else {
* V_16 = true ;
V_27 = V_2 -> V_40 = V_29 ;
}
break;
default:
F_3 ( V_2 -> V_13 , L_7 , V_26 ) ;
V_27 = - V_14 ;
break;
}
return V_27 ;
}
static int F_7 ( struct V_1 * V_2 ,
enum V_41 V_42 , bool V_16 )
{
int V_4 = 0 ;
if ( V_42 == V_43 ) {
V_4 = F_4 ( V_2 , V_2 -> V_44 , V_16 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_8 ) ;
return V_4 ;
}
}
switch ( V_42 ) {
case V_43 :
F_8 ( V_2 -> V_45 , L_9 , V_16 ) ;
break;
case V_46 :
F_8 ( V_2 -> V_45 , L_10 , V_16 ) ;
break;
default:
F_3 ( V_2 -> V_13 , L_11 ,
V_16 ? L_5 : L_6 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
int V_27 , bool V_16 )
{
int V_4 = 0 ;
V_4 = F_4 ( V_2 , V_47 , V_16 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_13 , L_8 ) ;
return V_4 ;
}
switch ( V_27 ) {
case V_48 :
F_8 ( V_2 -> V_45 , L_12 , V_16 ) ;
break;
case V_49 :
F_8 ( V_2 -> V_45 , L_13 , V_16 ) ;
break;
default:
F_3 ( V_2 -> V_13 , L_14 ,
V_16 ? L_5 : L_6 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
bool V_16 )
{
int V_4 = 0 ;
V_4 = F_4 ( V_2 , V_2 -> V_50 , V_16 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_13 , L_8 ) ;
return V_4 ;
}
F_8 ( V_2 -> V_45 , L_15 , V_16 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_27 ;
bool V_16 ;
int V_4 = 0 ;
V_27 = F_6 ( V_2 ,
V_30 , & V_16 ) ;
switch ( V_27 ) {
case V_51 :
V_4 = F_7 ( V_2 , V_43 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_52 :
F_8 ( V_2 -> V_45 , L_16 , V_16 ) ;
break;
case V_53 :
case V_54 :
V_4 = F_7 ( V_2 ,
V_46 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_48 :
case V_49 :
V_4 = F_9 ( V_2 , V_27 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_55 :
V_4 = F_10 ( V_2 , V_16 ) ;
break;
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
F_5 ( V_2 -> V_13 ,
L_17 ,
V_16 ? L_5 : L_6 , V_27 ) ;
return - V_80 ;
default:
F_3 ( V_2 -> V_13 ,
L_18 ,
V_16 ? L_5 : L_6 , V_27 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_29 ;
bool V_16 ;
int V_28 ;
V_29 = F_6 ( V_2 ,
V_36 , & V_16 ) ;
switch ( V_29 ) {
case V_39 :
break;
case V_81 :
V_28 = V_2 -> V_31 [ 0 ] & V_32 ;
V_28 >>= V_33 ;
if ( ( V_28 & V_32 ) == V_34 ) {
F_7 ( V_2 ,
V_46 , V_16 ) ;
}
break;
case V_82 :
F_8 ( V_2 -> V_45 ,
L_19 , V_16 ) ;
break;
case V_83 :
F_8 ( V_2 -> V_45 , L_20 , V_16 ) ;
break;
case V_84 :
F_8 ( V_2 -> V_45 , L_21 , V_16 ) ;
break;
case V_85 :
F_8 ( V_2 -> V_45 , L_22 , V_16 ) ;
break;
default:
F_3 ( V_2 -> V_13 ,
L_23 ,
V_16 ? L_5 : L_6 , V_29 ) ;
return - V_14 ;
}
return 0 ;
}
static void F_13 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = F_14 ( V_87 ,
struct V_1 , V_88 ) ;
int V_89 = 0 ;
int V_90 , V_4 ;
if ( ! V_2 -> V_45 )
return;
F_15 ( & V_2 -> V_91 ) ;
for ( V_90 = 0 ; V_90 < F_16 ( V_92 ) ; V_90 ++ )
if ( V_2 -> V_93 == V_92 [ V_90 ] . V_94 )
V_89 = V_92 [ V_90 ] . V_93 ;
V_4 = F_17 ( V_2 -> V_9 , V_95 ,
2 , V_2 -> V_31 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_13 , L_24 ) ;
F_18 ( & V_2 -> V_91 ) ;
return;
}
switch ( V_89 ) {
case V_96 :
case V_97 :
case V_98 :
V_4 = F_11 ( V_2 ) ;
break;
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
V_4 = F_12 ( V_2 ) ;
break;
case V_104 :
break;
default:
F_5 ( V_2 -> V_13 , L_25 ,
V_89 ) ;
F_18 ( & V_2 -> V_91 ) ;
return;
}
if ( V_4 < 0 )
F_3 ( V_2 -> V_13 , L_26 ) ;
F_18 ( & V_2 -> V_91 ) ;
return;
}
static T_2 F_19 ( int V_93 , void * V_105 )
{
struct V_1 * V_2 = V_105 ;
F_20 ( V_2 -> V_13 , L_27 , V_93 ) ;
V_2 -> V_93 = V_93 ;
F_21 ( & V_2 -> V_88 ) ;
return V_106 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
int V_28 ;
int V_29 ;
bool V_16 ;
F_15 ( & V_2 -> V_91 ) ;
V_4 = F_17 ( V_2 -> V_9 ,
V_95 , 2 , V_2 -> V_31 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_13 , L_28 ) ;
F_18 ( & V_2 -> V_91 ) ;
return V_4 ;
}
V_28 = F_6 ( V_2 , V_30 ,
& V_16 ) ;
if ( V_16 && V_28 != V_34 ) {
V_4 = F_11 ( V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_29 ) ;
F_18 ( & V_2 -> V_91 ) ;
return V_4 ;
}
}
V_29 = F_6 ( V_2 , V_36 ,
& V_16 ) ;
if ( V_16 && V_29 != V_39 ) {
V_4 = F_12 ( V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_30 ) ;
F_18 ( & V_2 -> V_91 ) ;
return V_4 ;
}
}
F_18 ( & V_2 -> V_91 ) ;
return 0 ;
}
static void F_23 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = F_14 ( F_24 ( V_87 ) ,
struct V_1 , V_107 ) ;
int V_4 ;
V_4 = F_22 ( V_2 ) ;
if ( V_4 < 0 )
F_3 ( V_2 -> V_13 , L_31 ) ;
}
static int F_25 ( struct V_108 * V_109 )
{
struct V_110 * V_111 = F_26 ( V_109 -> V_13 . V_112 ) ;
struct V_113 * V_114 = F_27 ( V_111 -> V_13 ) ;
struct V_1 * V_2 ;
int V_115 ;
int V_4 , V_90 ;
V_2 = F_28 ( & V_109 -> V_13 , sizeof( struct V_1 ) ,
V_116 ) ;
if ( ! V_2 ) {
F_3 ( & V_109 -> V_13 , L_32 ) ;
return - V_117 ;
}
V_2 -> V_13 = & V_109 -> V_13 ;
V_2 -> V_9 = V_111 -> V_9 ;
F_29 ( V_109 , V_2 ) ;
F_30 ( & V_2 -> V_91 ) ;
F_31 ( & V_2 -> V_88 , F_13 ) ;
for ( V_90 = 0 ; V_90 < F_16 ( V_92 ) ; V_90 ++ ) {
struct V_118 * V_119 = & V_92 [ V_90 ] ;
unsigned int V_94 = 0 ;
V_94 = F_32 ( V_111 -> V_120 , V_119 -> V_93 ) ;
if ( ! V_94 ) {
V_4 = - V_14 ;
goto V_121;
}
V_119 -> V_94 = V_94 ;
V_4 = F_33 ( V_94 , NULL ,
F_19 ,
V_122 ,
V_119 -> V_123 , V_2 ) ;
if ( V_4 ) {
F_3 ( & V_109 -> V_13 ,
L_33
L_34 ,
V_119 -> V_93 , V_4 ) ;
goto V_121;
}
}
V_2 -> V_45 = F_34 ( & V_109 -> V_13 , V_124 ) ;
if ( F_35 ( V_2 -> V_45 ) ) {
F_3 ( & V_109 -> V_13 , L_35 ) ;
V_4 = - V_117 ;
goto V_121;
}
V_2 -> V_45 -> V_123 = V_125 ;
V_2 -> V_45 -> V_13 . V_112 = & V_109 -> V_13 ;
V_4 = F_36 ( & V_109 -> V_13 , V_2 -> V_45 ) ;
if ( V_4 ) {
F_3 ( & V_109 -> V_13 , L_36 ) ;
goto V_121;
}
if ( V_114 && V_114 -> V_126 ) {
struct V_127 * V_126
= V_114 -> V_126 ;
for ( V_90 = 0 ; V_90 < V_126 -> V_128 ; V_90 ++ ) {
F_37 ( V_2 -> V_9 ,
V_126 -> V_129 [ V_90 ] . V_130 ,
V_126 -> V_129 [ V_90 ] . V_105 ) ;
}
if ( V_126 -> V_50 )
V_2 -> V_50 = V_126 -> V_50 ;
else
V_2 -> V_50 = V_131 ;
if ( V_126 -> V_44 )
V_2 -> V_44 = V_126 -> V_44 ;
else
V_2 -> V_44 = V_132 ;
if ( V_126 -> V_133 )
V_115 =
F_38 ( V_126 -> V_133 ) ;
else
V_115 = F_38 ( V_134 ) ;
} else {
V_2 -> V_50 = V_131 ;
V_2 -> V_44 = V_132 ;
V_115 = F_38 ( V_134 ) ;
}
F_4 ( V_2 , V_2 -> V_50 , true ) ;
F_1 ( V_2 , V_7 ) ;
F_39 ( & V_2 -> V_107 , F_23 ) ;
F_40 ( V_135 , & V_2 -> V_107 ,
V_115 ) ;
return 0 ;
V_121:
while ( -- V_90 >= 0 )
F_41 ( V_92 [ V_90 ] . V_94 , V_2 ) ;
return V_4 ;
}
static int F_42 ( struct V_108 * V_109 )
{
struct V_1 * V_2 = F_43 ( V_109 ) ;
int V_90 ;
for ( V_90 = 0 ; V_90 < F_16 ( V_92 ) ; V_90 ++ )
F_41 ( V_92 [ V_90 ] . V_94 , V_2 ) ;
F_44 ( & V_2 -> V_88 ) ;
return 0 ;
}
