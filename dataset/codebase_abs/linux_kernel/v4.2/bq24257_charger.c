static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
return false ;
default:
return true ;
}
}
static int F_2 ( struct V_6 * V_7 ,
enum V_8 V_9 )
{
int V_10 ;
int V_11 ;
V_10 = F_3 ( V_7 -> V_12 [ V_9 ] , & V_11 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_11 ;
}
static int F_4 ( struct V_6 * V_7 ,
enum V_8 V_9 , T_1 V_11 )
{
return F_5 ( V_7 -> V_12 [ V_9 ] , V_11 ) ;
}
static T_1 F_6 ( T_2 V_13 , const T_2 * V_14 , T_1 V_15 )
{
T_1 V_16 ;
for ( V_16 = 1 ; V_16 < V_15 ; V_16 ++ )
if ( V_13 < V_14 [ V_16 ] )
break;
return V_16 - 1 ;
}
static int F_7 ( struct V_17 * V_18 ,
enum V_19 V_20 ,
union V_21 * V_11 )
{
struct V_6 * V_7 = F_8 ( V_18 ) ;
struct V_22 V_23 ;
F_9 ( & V_7 -> V_24 ) ;
V_23 = V_7 -> V_23 ;
F_10 ( & V_7 -> V_24 ) ;
switch ( V_20 ) {
case V_25 :
if ( ! V_23 . V_26 )
V_11 -> V_27 = V_28 ;
else if ( V_23 . V_29 == V_30 )
V_11 -> V_27 = V_31 ;
else if ( V_23 . V_29 == V_32 )
V_11 -> V_27 = V_33 ;
else if ( V_23 . V_29 == V_34 )
V_11 -> V_27 = V_35 ;
else
V_11 -> V_27 = V_36 ;
break;
case V_37 :
V_11 -> V_38 = V_39 ;
break;
case V_40 :
V_11 -> V_27 = V_23 . V_26 ;
break;
case V_41 :
switch ( V_23 . V_42 ) {
case V_43 :
V_11 -> V_27 = V_44 ;
break;
case V_45 :
case V_46 :
V_11 -> V_27 = V_47 ;
break;
case V_48 :
case V_49 :
V_11 -> V_27 = V_50 ;
break;
case V_51 :
V_11 -> V_27 = V_52 ;
break;
default:
V_11 -> V_27 = V_53 ;
break;
}
break;
case V_54 :
V_11 -> V_27 = V_55 [ V_7 -> V_56 . V_57 ] ;
break;
case V_58 :
V_11 -> V_27 = V_55 [ V_59 - 1 ] ;
break;
case V_60 :
V_11 -> V_27 = V_61 [ V_7 -> V_56 . V_62 ] ;
break;
case V_63 :
V_11 -> V_27 = V_61 [ V_64 - 1 ] ;
break;
case V_65 :
V_11 -> V_27 = V_66 [ V_7 -> V_56 . V_67 ] ;
break;
default:
return - V_68 ;
}
return 0 ;
}
static int F_11 ( struct V_6 * V_7 ,
struct V_22 * V_23 )
{
int V_10 ;
V_10 = F_2 ( V_7 , V_69 ) ;
if ( V_10 < 0 )
return V_10 ;
V_23 -> V_29 = V_10 ;
V_10 = F_2 ( V_7 , V_70 ) ;
if ( V_10 < 0 )
return V_10 ;
V_23 -> V_42 = V_10 ;
V_23 -> V_26 = ! F_12 ( V_7 -> V_71 ) ;
return 0 ;
}
static bool F_13 ( struct V_6 * V_7 ,
struct V_22 * V_72 )
{
int V_10 ;
F_9 ( & V_7 -> V_24 ) ;
V_10 = ( V_7 -> V_23 . V_29 != V_72 -> V_29 ||
V_7 -> V_23 . V_42 != V_72 -> V_42 ||
V_7 -> V_23 . V_26 != V_72 -> V_26 ) ;
F_10 ( & V_7 -> V_24 ) ;
return V_10 ;
}
static int F_14 ( struct V_6 * V_7 )
{
int V_73 ;
int V_74 ;
int V_75 ;
int V_10 ;
const T_1 V_76 [] = {
[ V_77 ] = V_78 ,
[ V_79 ] = V_78 ,
[ V_80 ] = V_81 ,
[ V_82 ] = V_81
} ;
V_10 = F_2 ( V_7 , V_83 ) ;
if ( V_10 < 0 )
goto error;
V_73 = V_10 ;
V_10 = F_2 ( V_7 , V_84 ) ;
if ( V_10 < 0 )
goto error;
V_74 = V_10 ;
if ( V_73 == V_85 && V_74 == V_81 )
return 0 ;
V_10 = F_2 ( V_7 , V_86 ) ;
if ( V_10 < 0 )
goto error;
V_75 = V_10 ;
V_10 = F_4 ( V_7 , V_84 , V_76 [ V_75 ] ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_4 ( V_7 , V_87 , V_88 ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_4 ( V_7 , V_89 , 1 ) ;
if ( V_10 < 0 )
goto error;
F_15 ( V_7 -> V_2 , L_1 ,
V_75 , V_73 , V_76 [ V_75 ] ) ;
return 0 ;
error:
F_16 ( V_7 -> V_2 , L_2 , V_90 ) ;
return V_10 ;
}
static void F_17 ( struct V_91 * V_92 )
{
struct V_6 * V_7 = F_18 ( V_92 , struct V_6 ,
V_93 . V_92 ) ;
F_14 ( V_7 ) ;
}
static void F_19 ( struct V_6 * V_7 ,
struct V_22 * V_72 )
{
int V_10 ;
struct V_22 V_94 ;
bool V_95 = false ;
bool V_96 = false ;
F_9 ( & V_7 -> V_24 ) ;
V_94 = V_7 -> V_23 ;
F_10 ( & V_7 -> V_24 ) ;
if ( ! V_72 -> V_26 ) {
F_20 ( & V_7 -> V_93 ) ;
V_10 = F_4 ( V_7 , V_97 , 1 ) ;
if ( V_10 < 0 )
goto error;
V_95 = true ;
} else if ( ! V_94 . V_26 ) {
V_96 = true ;
} else if ( V_72 -> V_42 == V_98 ) {
F_20 ( & V_7 -> V_93 ) ;
V_95 = true ;
} else if ( V_94 . V_42 == V_98 ) {
V_96 = true ;
} else if ( V_72 -> V_42 == V_51 ) {
F_16 ( V_7 -> V_2 , L_3 ) ;
}
if ( V_95 ) {
V_10 = F_4 ( V_7 , V_84 , V_81 ) ;
if ( V_10 < 0 )
goto error;
} else if ( V_96 ) {
F_21 ( & V_7 -> V_93 ,
F_22 ( V_99 ) ) ;
}
return;
error:
F_16 ( V_7 -> V_2 , L_2 , V_90 ) ;
}
static T_3 F_23 ( int V_100 , void * V_101 )
{
int V_10 ;
struct V_6 * V_7 = V_101 ;
struct V_22 V_23 ;
V_10 = F_11 ( V_7 , & V_23 ) ;
if ( V_10 < 0 )
return V_102 ;
if ( ! F_13 ( V_7 , & V_23 ) )
return V_102 ;
F_15 ( V_7 -> V_2 , L_4 ,
V_23 . V_29 , V_23 . V_42 , V_23 . V_26 ) ;
F_19 ( V_7 , & V_23 ) ;
F_9 ( & V_7 -> V_24 ) ;
V_7 -> V_23 = V_23 ;
F_10 ( & V_7 -> V_24 ) ;
F_24 ( V_7 -> V_103 ) ;
return V_102 ;
}
static int F_25 ( struct V_6 * V_7 )
{
int V_10 ;
int V_104 ;
struct V_22 V_23 ;
const struct {
int V_105 ;
T_2 V_13 ;
} V_56 [] = {
{ V_106 , V_7 -> V_56 . V_57 } ,
{ V_107 , V_7 -> V_56 . V_62 } ,
{ V_108 , V_7 -> V_56 . V_67 }
} ;
V_10 = F_4 ( V_7 , V_109 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
for ( V_104 = 0 ; V_104 < F_26 ( V_56 ) ; V_104 ++ ) {
V_10 = F_4 ( V_7 , V_56 [ V_104 ] . V_105 ,
V_56 [ V_104 ] . V_13 ) ;
if ( V_10 < 0 )
return V_10 ;
}
V_10 = F_11 ( V_7 , & V_23 ) ;
if ( V_10 < 0 )
return V_10 ;
F_9 ( & V_7 -> V_24 ) ;
V_7 -> V_23 = V_23 ;
F_10 ( & V_7 -> V_24 ) ;
if ( ! V_23 . V_26 )
V_10 = F_4 ( V_7 , V_97 , 1 ) ;
else if ( V_23 . V_42 != V_98 )
V_10 = F_14 ( V_7 ) ;
return V_10 ;
}
static int F_27 ( struct V_6 * V_7 )
{
struct V_110 V_111 = { . V_112 = V_7 , } ;
V_111 . V_113 = V_114 ;
V_111 . V_115 = F_26 ( V_114 ) ;
V_7 -> V_103 = F_28 ( V_7 -> V_2 , & V_116 ,
& V_111 ) ;
if ( F_29 ( V_7 -> V_103 ) )
return F_30 ( V_7 -> V_103 ) ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 )
{
struct V_117 * V_118 ;
V_118 = F_32 ( V_7 -> V_2 , V_119 , 0 , V_120 ) ;
if ( F_29 ( V_118 ) ) {
F_16 ( V_7 -> V_2 , L_5 ) ;
return F_30 ( V_118 ) ;
}
return F_33 ( V_118 ) ;
}
static int F_34 ( struct V_6 * V_7 )
{
V_7 -> V_71 = F_32 ( V_7 -> V_2 , V_121 , 0 , V_120 ) ;
if ( F_29 ( V_7 -> V_71 ) ) {
F_16 ( V_7 -> V_2 , L_6 ) ;
return F_30 ( V_7 -> V_71 ) ;
}
return 0 ;
}
static int F_35 ( struct V_6 * V_7 )
{
int V_10 ;
T_2 V_122 ;
V_10 = F_36 ( V_7 -> V_2 , L_7 , & V_122 ) ;
if ( V_10 < 0 )
return V_10 ;
V_7 -> V_56 . V_57 = F_6 ( V_122 , V_55 ,
V_59 ) ;
V_10 = F_36 ( V_7 -> V_2 , L_8 ,
& V_122 ) ;
if ( V_10 < 0 )
return V_10 ;
V_7 -> V_56 . V_62 = F_6 ( V_122 , V_61 ,
V_64 ) ;
V_10 = F_36 ( V_7 -> V_2 , L_9 ,
& V_122 ) ;
if ( V_10 < 0 )
return V_10 ;
V_7 -> V_56 . V_67 = F_6 ( V_122 , V_66 ,
V_123 ) ;
return 0 ;
}
static int F_37 ( struct V_124 * V_125 ,
const struct V_126 * V_127 )
{
struct V_128 * V_129 = F_38 ( V_125 -> V_2 . V_130 ) ;
struct V_1 * V_2 = & V_125 -> V_2 ;
struct V_6 * V_7 ;
int V_10 ;
int V_104 ;
if ( ! F_39 ( V_129 , V_131 ) ) {
F_16 ( V_2 , L_10 ) ;
return - V_132 ;
}
V_7 = F_40 ( V_2 , sizeof( * V_7 ) , V_133 ) ;
if ( ! V_7 )
return - V_134 ;
V_7 -> V_125 = V_125 ;
V_7 -> V_2 = V_2 ;
F_41 ( & V_7 -> V_24 ) ;
V_7 -> V_135 = F_42 ( V_125 , & V_136 ) ;
if ( F_29 ( V_7 -> V_135 ) ) {
F_16 ( V_2 , L_11 ) ;
return F_30 ( V_7 -> V_135 ) ;
}
for ( V_104 = 0 ; V_104 < F_26 ( V_137 ) ; V_104 ++ ) {
const struct V_138 * V_139 = V_137 ;
V_7 -> V_12 [ V_104 ] = F_43 ( V_2 , V_7 -> V_135 ,
V_139 [ V_104 ] ) ;
if ( F_29 ( V_7 -> V_12 [ V_104 ] ) ) {
F_16 ( V_2 , L_12 ) ;
return F_30 ( V_7 -> V_12 [ V_104 ] ) ;
}
}
F_44 ( V_125 , V_7 ) ;
F_45 ( & V_7 -> V_93 , F_17 ) ;
if ( ! V_2 -> V_140 ) {
V_10 = F_35 ( V_7 ) ;
if ( V_10 < 0 ) {
F_16 ( V_2 , L_13 ) ;
return V_10 ;
}
} else {
return - V_132 ;
}
V_10 = F_34 ( V_7 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_4 ( V_7 , V_141 , 1 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_4 ( V_7 , V_141 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_25 ( V_7 ) ;
if ( V_10 < 0 ) {
F_16 ( V_2 , L_14 ) ;
return V_10 ;
}
if ( V_125 -> V_100 <= 0 )
V_125 -> V_100 = F_31 ( V_7 ) ;
if ( V_125 -> V_100 < 0 ) {
F_16 ( V_2 , L_15 ) ;
return V_125 -> V_100 ;
}
V_10 = F_46 ( V_2 , V_125 -> V_100 , NULL ,
F_23 ,
V_142 |
V_143 | V_144 ,
V_119 , V_7 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_27 ( V_7 ) ;
if ( V_10 < 0 )
F_16 ( V_2 , L_16 ) ;
return V_10 ;
}
static int F_47 ( struct V_124 * V_125 )
{
struct V_6 * V_7 = F_48 ( V_125 ) ;
F_20 ( & V_7 -> V_93 ) ;
F_49 ( V_7 -> V_103 ) ;
F_4 ( V_7 , V_141 , 1 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_51 ( V_2 ) ;
int V_10 = 0 ;
F_20 ( & V_7 -> V_93 ) ;
V_10 = F_4 ( V_7 , V_141 , 1 ) ;
if ( V_10 < 0 )
F_16 ( V_7 -> V_2 , L_17 ) ;
return V_10 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_10 ;
struct V_6 * V_7 = F_51 ( V_2 ) ;
V_10 = F_53 ( V_7 -> V_135 , V_145 , V_146 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_4 ( V_7 , V_141 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_25 ( V_7 ) ;
if ( V_10 < 0 ) {
F_16 ( V_7 -> V_2 , L_18 ) ;
return V_10 ;
}
F_24 ( V_7 -> V_103 ) ;
return 0 ;
}
