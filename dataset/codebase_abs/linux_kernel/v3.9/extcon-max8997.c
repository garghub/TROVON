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
return - V_14 ;
}
break;
default:
F_3 ( V_2 -> V_13 , L_2 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_16 , bool V_17 )
{
int V_4 = 0 ;
T_1 V_18 , V_19 = 0 ;
if ( V_17 )
V_18 = V_16 ;
else
V_18 = V_20 ;
V_4 = F_2 ( V_2 -> V_9 ,
V_21 , V_18 , V_22 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_3 ) ;
return - V_14 ;
}
if ( V_17 )
V_19 |= V_23 ;
else
V_19 |= V_24 ;
V_4 = F_2 ( V_2 -> V_9 ,
V_25 , V_19 ,
V_24 | V_23 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_3 ) ;
return - V_14 ;
}
F_5 ( V_2 -> V_13 ,
L_4 ,
V_18 , V_19 , V_17 ? L_5 : L_6 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
enum V_26 V_27 , bool * V_17 )
{
int V_28 = 0 ;
int V_29 ;
int V_30 ;
switch ( V_27 ) {
case V_31 :
V_29 = V_2 -> V_32 [ 0 ] & V_33 ;
V_29 >>= V_34 ;
if ( V_29 == V_35 ) {
* V_17 = false ;
V_28 = V_2 -> V_36 ;
V_2 -> V_36 = V_35 ;
} else {
* V_17 = true ;
V_28 = V_2 -> V_36 = V_29 ;
}
break;
case V_37 :
V_30 = V_2 -> V_32 [ 1 ] & V_38 ;
V_30 >>= V_39 ;
if ( V_30 == V_40 ) {
* V_17 = false ;
V_28 = V_2 -> V_41 ;
V_2 -> V_41 = V_40 ;
} else {
* V_17 = true ;
V_28 = V_2 -> V_41 = V_30 ;
}
break;
default:
F_3 ( V_2 -> V_13 , L_7 , V_27 ) ;
V_28 = - V_15 ;
break;
}
return V_28 ;
}
static int F_7 ( struct V_1 * V_2 ,
enum V_42 V_43 , bool V_17 )
{
int V_4 = 0 ;
if ( V_43 == V_44 ) {
V_4 = F_4 ( V_2 , V_2 -> V_45 , V_17 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_8 ) ;
return V_4 ;
}
}
switch ( V_43 ) {
case V_44 :
F_8 ( V_2 -> V_46 , L_9 , V_17 ) ;
break;
case V_47 :
F_8 ( V_2 -> V_46 , L_10 , V_17 ) ;
break;
default:
F_3 ( V_2 -> V_13 , L_11 ,
V_17 ? L_5 : L_6 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
int V_28 , bool V_17 )
{
int V_4 = 0 ;
V_4 = F_4 ( V_2 , V_48 , V_17 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_13 , L_8 ) ;
return V_4 ;
}
switch ( V_28 ) {
case V_49 :
F_8 ( V_2 -> V_46 , L_12 , V_17 ) ;
break;
case V_50 :
F_8 ( V_2 -> V_46 , L_13 , V_17 ) ;
break;
default:
F_3 ( V_2 -> V_13 , L_14 ,
V_17 ? L_5 : L_6 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
bool V_17 )
{
int V_4 = 0 ;
V_4 = F_4 ( V_2 , V_2 -> V_51 , V_17 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_13 , L_8 ) ;
return - V_15 ;
}
F_8 ( V_2 -> V_46 , L_15 , V_17 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_28 ;
bool V_17 ;
int V_4 = 0 ;
V_28 = F_6 ( V_2 ,
V_31 , & V_17 ) ;
switch ( V_28 ) {
case V_52 :
V_4 = F_7 ( V_2 , V_44 , V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_53 :
F_8 ( V_2 -> V_46 , L_16 , V_17 ) ;
break;
case V_54 :
case V_55 :
V_4 = F_7 ( V_2 , V_47 , V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_49 :
case V_50 :
V_4 = F_9 ( V_2 , V_28 , V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_56 :
V_4 = F_10 ( V_2 , V_17 ) ;
break;
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
case V_80 :
F_5 ( V_2 -> V_13 ,
L_17 ,
V_17 ? L_5 : L_6 , V_28 ) ;
return - V_14 ;
default:
F_3 ( V_2 -> V_13 ,
L_18 ,
V_17 ? L_5 : L_6 , V_28 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_30 ;
bool V_17 ;
int V_29 ;
V_30 = F_6 ( V_2 ,
V_37 , & V_17 ) ;
switch ( V_30 ) {
case V_40 :
break;
case V_81 :
V_29 = V_2 -> V_32 [ 0 ] & V_33 ;
V_29 >>= V_34 ;
if ( ( V_29 & V_33 ) == V_35 ) {
F_7 ( V_2 ,
V_47 , V_17 ) ;
}
break;
case V_82 :
F_8 ( V_2 -> V_46 , L_19 , V_17 ) ;
break;
case V_83 :
F_8 ( V_2 -> V_46 , L_20 , V_17 ) ;
break;
case V_84 :
F_8 ( V_2 -> V_46 , L_21 , V_17 ) ;
break;
case V_85 :
F_8 ( V_2 -> V_46 , L_22 , V_17 ) ;
break;
default:
F_3 ( V_2 -> V_13 ,
L_23 ,
V_17 ? L_5 : L_6 , V_30 ) ;
return - V_15 ;
}
return 0 ;
}
static void F_13 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = F_14 ( V_87 ,
struct V_1 , V_88 ) ;
int V_89 = 0 ;
int V_90 , V_4 ;
if ( ! V_2 -> V_46 )
return;
F_15 ( & V_2 -> V_91 ) ;
for ( V_90 = 0 ; V_90 < F_16 ( V_92 ) ; V_90 ++ )
if ( V_2 -> V_93 == V_92 [ V_90 ] . V_94 )
V_89 = V_92 [ V_90 ] . V_93 ;
V_4 = F_17 ( V_2 -> V_9 , V_95 ,
2 , V_2 -> V_32 ) ;
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
int V_29 ;
int V_30 ;
bool V_17 ;
F_15 ( & V_2 -> V_91 ) ;
V_4 = F_17 ( V_2 -> V_9 ,
V_95 , 2 , V_2 -> V_32 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_13 , L_28 ) ;
F_18 ( & V_2 -> V_91 ) ;
return - V_15 ;
}
V_29 = F_6 ( V_2 , V_31 ,
& V_17 ) ;
if ( V_17 && V_29 != V_35 ) {
V_4 = F_11 ( V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_29 ) ;
F_18 ( & V_2 -> V_91 ) ;
return V_4 ;
}
}
V_30 = F_6 ( V_2 , V_37 ,
& V_17 ) ;
if ( V_17 && V_30 != V_40 ) {
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
F_25 ( L_31 ) ;
}
static int F_26 ( struct V_108 * V_109 )
{
struct V_110 * V_111 = F_27 ( V_109 -> V_13 . V_112 ) ;
struct V_113 * V_114 = F_28 ( V_111 -> V_13 ) ;
struct V_1 * V_2 ;
int V_115 ;
int V_4 , V_90 ;
V_2 = F_29 ( & V_109 -> V_13 , sizeof( struct V_1 ) ,
V_116 ) ;
if ( ! V_2 ) {
F_3 ( & V_109 -> V_13 , L_32 ) ;
return - V_117 ;
}
V_2 -> V_13 = & V_109 -> V_13 ;
V_2 -> V_9 = V_111 -> V_9 ;
F_30 ( V_109 , V_2 ) ;
F_31 ( & V_2 -> V_91 ) ;
F_32 ( & V_2 -> V_88 , F_13 ) ;
for ( V_90 = 0 ; V_90 < F_16 ( V_92 ) ; V_90 ++ ) {
struct V_118 * V_119 = & V_92 [ V_90 ] ;
unsigned int V_94 = 0 ;
V_94 = F_33 ( V_111 -> V_120 , V_119 -> V_93 ) ;
if ( ! V_94 ) {
V_4 = - V_15 ;
goto V_121;
}
V_119 -> V_94 = V_94 ;
V_4 = F_34 ( V_94 , NULL ,
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
V_2 -> V_46 = F_29 ( & V_109 -> V_13 , sizeof( struct V_124 ) ,
V_116 ) ;
if ( ! V_2 -> V_46 ) {
F_3 ( & V_109 -> V_13 , L_35 ) ;
V_4 = - V_117 ;
goto V_121;
}
V_2 -> V_46 -> V_123 = V_125 ;
V_2 -> V_46 -> V_126 = V_127 ;
V_4 = F_35 ( V_2 -> V_46 , NULL ) ;
if ( V_4 ) {
F_3 ( & V_109 -> V_13 , L_36 ) ;
goto V_121;
}
if ( V_114 -> V_128 ) {
struct V_129 * V_128
= V_114 -> V_128 ;
for ( V_90 = 0 ; V_90 < V_128 -> V_130 ; V_90 ++ ) {
F_36 ( V_2 -> V_9 ,
V_128 -> V_131 [ V_90 ] . V_132 ,
V_128 -> V_131 [ V_90 ] . V_105 ) ;
}
if ( V_128 -> V_51 )
V_2 -> V_51 = V_128 -> V_51 ;
else
V_2 -> V_51 = V_133 ;
if ( V_128 -> V_45 )
V_2 -> V_45 = V_128 -> V_45 ;
else
V_2 -> V_45 = V_134 ;
if ( V_128 -> V_135 )
V_115 =
F_37 ( V_128 -> V_135 ) ;
else
V_115 = F_37 ( V_136 ) ;
} else {
V_2 -> V_51 = V_133 ;
V_2 -> V_45 = V_134 ;
V_115 = F_37 ( V_136 ) ;
}
F_4 ( V_2 , V_2 -> V_51 , true ) ;
F_1 ( V_2 , V_7 ) ;
F_38 ( & V_2 -> V_107 , F_23 ) ;
F_39 ( & V_2 -> V_107 , V_115 ) ;
return 0 ;
V_121:
while ( -- V_90 >= 0 )
F_40 ( V_92 [ V_90 ] . V_94 , V_2 ) ;
return V_4 ;
}
static int F_41 ( struct V_108 * V_109 )
{
struct V_1 * V_2 = F_42 ( V_109 ) ;
int V_90 ;
for ( V_90 = 0 ; V_90 < F_16 ( V_92 ) ; V_90 ++ )
F_40 ( V_92 [ V_90 ] . V_94 , V_2 ) ;
F_43 ( & V_2 -> V_88 ) ;
F_44 ( V_2 -> V_46 ) ;
return 0 ;
}
