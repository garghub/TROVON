static int F_1 ( struct V_1 * V_1 , int V_2 ,
union V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_1 , V_6 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 & V_2 )
V_4 -> V_7 = 1 ;
else
V_4 -> V_7 = 0 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_1 ,
enum V_8 V_9 ,
union V_3 * V_4 )
{
int V_5 ;
V_5 = F_4 ( V_1 , V_9 ) ;
if ( V_5 >= 0 )
V_4 -> V_7 = V_5 ;
return V_5 ;
}
static int F_5 ( struct V_10 * V_11 ,
enum V_12 V_13 ,
union V_3 * V_4 )
{
struct V_14 * V_14 = F_6 ( V_11 -> V_15 . V_16 ) ;
struct V_1 * V_1 = V_14 -> V_1 ;
int V_5 = 0 ;
switch ( V_13 ) {
case V_17 :
V_5 = F_1 ( V_1 , V_18 , V_4 ) ;
break;
case V_19 :
V_5 = F_3 ( V_1 , V_20 , V_4 ) ;
break;
default:
V_5 = - V_21 ;
break;
}
return V_5 ;
}
static int F_7 ( struct V_10 * V_11 ,
enum V_12 V_13 ,
union V_3 * V_4 )
{
struct V_14 * V_14 = F_6 ( V_11 -> V_15 . V_16 ) ;
struct V_1 * V_1 = V_14 -> V_1 ;
int V_5 = 0 ;
switch ( V_13 ) {
case V_17 :
V_5 = F_1 ( V_1 , V_22 , V_4 ) ;
break;
case V_19 :
V_5 = F_3 ( V_1 , V_23 , V_4 ) ;
break;
default:
V_5 = - V_21 ;
break;
}
return V_5 ;
}
static int F_8 ( struct V_24 * V_25 ,
unsigned long V_26 , void * V_27 )
{
struct V_14 * V_14 = F_9 ( V_25 ,
struct V_14 ,
V_28 ) ;
unsigned int V_29 , V_30 ;
V_30 = 0 ;
for ( V_29 = 0 ; V_29 < F_10 ( V_31 ) ; V_29 ++ ) {
if ( V_26 >= V_31 [ V_29 ] &&
V_31 [ V_30 ] < V_31 [ V_29 ] )
V_30 = V_29 ;
}
F_11 ( V_14 -> V_1 -> V_15 ,
L_1 , V_31 [ V_30 ] ) ;
F_12 ( V_14 -> V_1 , V_32 ,
V_33 , V_30 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_1 ,
struct V_34 * V_35 , int V_36 , int V_4 ,
int * V_37 , const char * V_38 ,
const char * V_39 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_36 ; V_29 ++ )
if ( V_4 == V_35 [ V_29 ] . V_4 )
break;
if ( V_29 == V_36 ) {
F_14 ( V_1 -> V_15 , L_2 ,
V_38 , V_4 , V_39 ) ;
} else {
* V_37 |= V_35 [ V_29 ] . V_40 ;
F_11 ( V_1 -> V_15 , L_3 , V_38 , V_4 , V_39 ) ;
}
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_41 * V_41 = V_1 -> V_15 -> V_42 ;
struct V_43 * V_44 ;
int V_5 , V_45 , V_46 ;
if ( ! V_41 || ! V_41 -> V_47 ) {
F_16 ( V_1 -> V_15 ,
L_4 ) ;
return;
}
V_44 = V_41 -> V_47 ;
V_45 = 0 ;
V_46 = 0 ;
if ( ! V_44 -> V_48 ) {
F_17 ( V_1 -> V_15 , L_5 ) ;
return;
}
V_45 |= V_49 ;
if ( V_44 -> V_50 )
V_46 |= V_51 ;
if ( V_44 -> V_52 )
V_45 |= V_53 ;
F_13 ( V_1 , V_54 ,
F_10 ( V_54 ) ,
V_44 -> V_55 , & V_46 ,
L_6 , L_7 ) ;
F_13 ( V_1 , V_56 , F_10 ( V_56 ) ,
V_44 -> V_57 , & V_46 ,
L_8 , L_9 ) ;
F_13 ( V_1 , V_58 , F_10 ( V_58 ) ,
V_44 -> V_59 , & V_46 ,
L_10 , L_7 ) ;
F_13 ( V_1 , V_60 , F_10 ( V_60 ) ,
V_44 -> V_61 , & V_45 ,
L_11 , L_7 ) ;
F_13 ( V_1 , V_62 , F_10 ( V_62 ) ,
V_44 -> V_63 , & V_46 ,
L_12 , L_13 ) ;
V_5 = F_18 ( V_1 ) ;
if ( V_5 != 0 ) {
F_14 ( V_1 -> V_15 , L_14 , V_5 ) ;
return;
}
V_5 = F_12 ( V_1 , V_64 ,
V_65 |
V_66 |
V_67 ,
V_45 ) ;
if ( V_5 != 0 )
F_14 ( V_1 -> V_15 , L_15 ,
V_5 ) ;
V_5 = F_12 ( V_1 , V_68 ,
V_51 |
V_69 |
V_70 |
V_71 |
V_72 ,
V_46 ) ;
if ( V_5 != 0 )
F_14 ( V_1 -> V_15 , L_16 ,
V_5 ) ;
F_19 ( V_1 ) ;
}
static int F_20 ( struct V_1 * V_1 , int * V_73 )
{
int V_5 ;
V_5 = F_2 ( V_1 , V_6 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 & V_74 ) {
* V_73 = V_75 ;
return 0 ;
}
V_5 = F_2 ( V_1 , V_76 ) ;
if ( V_5 < 0 )
return V_5 ;
switch ( V_5 & V_77 ) {
case V_78 :
* V_73 = V_79 ;
break;
case V_80 :
case V_81 :
* V_73 = V_82 ;
break;
default:
* V_73 = V_83 ;
break;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_1 , int * type )
{
int V_5 ;
V_5 = F_2 ( V_1 , V_76 ) ;
if ( V_5 < 0 )
return V_5 ;
switch ( V_5 & V_77 ) {
case V_80 :
case V_84 :
* type = V_85 ;
break;
case V_81 :
case V_86 :
* type = V_87 ;
break;
default:
* type = V_88 ;
break;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_1 , int * V_89 )
{
int V_5 ;
V_5 = F_2 ( V_1 , V_76 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 & V_90 ) {
* V_89 = V_91 ;
return 0 ;
}
if ( V_5 & V_92 ) {
* V_89 = V_93 ;
return 0 ;
}
if ( V_5 & V_94 ) {
* V_89 = V_95 ;
return 0 ;
}
switch ( V_5 & V_77 ) {
case V_84 :
case V_86 :
* V_89 = V_91 ;
break;
case V_96 :
* V_89 = V_97 ;
break;
default:
* V_89 = V_98 ;
break;
}
return 0 ;
}
static int F_23 ( struct V_10 * V_11 ,
enum V_12 V_13 ,
union V_3 * V_4 )
{
struct V_14 * V_14 = F_6 ( V_11 -> V_15 . V_16 ) ;
struct V_1 * V_1 = V_14 -> V_1 ;
int V_5 = 0 ;
switch ( V_13 ) {
case V_99 :
V_5 = F_20 ( V_1 , & V_4 -> V_7 ) ;
break;
case V_17 :
V_5 = F_1 ( V_1 , V_74 ,
V_4 ) ;
break;
case V_19 :
V_5 = F_3 ( V_1 , V_100 , V_4 ) ;
break;
case V_101 :
V_5 = F_22 ( V_1 , & V_4 -> V_7 ) ;
break;
case V_102 :
V_5 = F_21 ( V_1 , & V_4 -> V_7 ) ;
break;
default:
V_5 = - V_21 ;
break;
}
return V_5 ;
}
static T_1 F_24 ( int V_103 , void * V_27 )
{
struct V_14 * V_14 = V_27 ;
struct V_1 * V_1 = V_14 -> V_1 ;
F_11 ( V_1 -> V_15 , L_17 , V_103 ) ;
if ( V_14 -> V_104 )
F_25 ( V_14 -> V_47 ) ;
return V_105 ;
}
static T_1 F_26 ( int V_103 , void * V_27 )
{
struct V_14 * V_14 = V_27 ;
struct V_1 * V_1 = V_14 -> V_1 ;
F_27 ( V_1 -> V_15 , L_18 ) ;
return V_105 ;
}
static T_1 F_28 ( int V_103 , void * V_27 )
{
struct V_14 * V_14 = V_27 ;
struct V_1 * V_1 = V_14 -> V_1 ;
F_11 ( V_1 -> V_15 , L_19 ) ;
if ( V_14 -> V_104 )
F_25 ( V_14 -> V_47 ) ;
F_25 ( V_14 -> V_106 ) ;
F_25 ( V_14 -> V_107 ) ;
return V_105 ;
}
static int F_29 ( struct V_108 * V_109 )
{
struct V_1 * V_1 = F_6 ( V_109 -> V_15 . V_16 ) ;
struct V_41 * V_41 = V_1 -> V_15 -> V_42 ;
struct V_14 * V_110 ;
int V_5 , V_103 , V_29 ;
V_110 = F_30 ( & V_109 -> V_15 , sizeof( struct V_14 ) ,
V_111 ) ;
if ( V_110 == NULL )
return - V_112 ;
V_110 -> V_1 = V_1 ;
F_31 ( V_109 , V_110 ) ;
if ( V_41 && V_41 -> V_113 ) {
snprintf ( V_110 -> V_114 , sizeof( V_110 -> V_114 ) ,
L_20 , V_41 -> V_113 ) ;
snprintf ( V_110 -> V_115 , sizeof( V_110 -> V_114 ) ,
L_21 , V_41 -> V_113 ) ;
snprintf ( V_110 -> V_116 , sizeof( V_110 -> V_114 ) ,
L_22 , V_41 -> V_113 ) ;
} else {
snprintf ( V_110 -> V_114 , sizeof( V_110 -> V_114 ) ,
L_23 ) ;
snprintf ( V_110 -> V_115 , sizeof( V_110 -> V_114 ) ,
L_24 ) ;
snprintf ( V_110 -> V_116 , sizeof( V_110 -> V_114 ) ,
L_25 ) ;
}
F_15 ( V_1 ) ;
V_110 -> V_117 . V_38 = V_110 -> V_114 ;
V_110 -> V_117 . type = V_118 ;
V_110 -> V_117 . V_119 = V_120 ;
V_110 -> V_117 . V_121 = F_10 ( V_120 ) ;
V_110 -> V_117 . V_122 = F_5 ;
V_110 -> V_107 = F_32 ( & V_109 -> V_15 , & V_110 -> V_117 ,
NULL ) ;
if ( F_33 ( V_110 -> V_107 ) ) {
V_5 = F_34 ( V_110 -> V_107 ) ;
goto V_123;
}
V_110 -> V_124 . V_38 = V_110 -> V_116 ,
V_110 -> V_124 . type = V_125 ;
V_110 -> V_124 . V_119 = V_126 ;
V_110 -> V_124 . V_121 = F_10 ( V_126 ) ;
V_110 -> V_124 . V_122 = F_7 ;
V_110 -> V_106 = F_32 ( & V_109 -> V_15 , & V_110 -> V_124 , NULL ) ;
if ( F_33 ( V_110 -> V_106 ) ) {
V_5 = F_34 ( V_110 -> V_106 ) ;
goto V_127;
}
V_5 = F_2 ( V_1 , V_64 ) ;
if ( V_5 < 0 )
goto V_127;
V_110 -> V_104 = V_5 & V_49 ;
if ( V_110 -> V_104 ) {
V_110 -> V_128 . V_38 = V_110 -> V_115 ;
V_110 -> V_128 . V_119 = V_129 ;
V_110 -> V_128 . V_121 = F_10 ( V_129 ) ;
V_110 -> V_128 . V_122 = F_23 ;
V_110 -> V_128 . V_130 = 1 ;
V_110 -> V_47 = F_32 ( & V_109 -> V_15 ,
& V_110 -> V_128 ,
NULL ) ;
if ( F_33 ( V_110 -> V_47 ) ) {
V_5 = F_34 ( V_110 -> V_47 ) ;
goto V_131;
}
}
V_103 = F_35 ( V_1 , F_36 ( V_109 , L_26 ) ) ;
V_5 = F_37 ( V_103 , NULL , F_26 ,
V_132 | V_133 , L_27 ,
V_110 ) ;
if ( V_5 != 0 ) {
F_14 ( & V_109 -> V_15 , L_28 ,
V_103 , V_5 ) ;
goto V_134;
}
V_103 = F_35 ( V_1 , F_36 ( V_109 , L_29 ) ) ;
V_5 = F_37 ( V_103 , NULL , F_28 ,
V_132 | V_133 , L_30 ,
V_110 ) ;
if ( V_5 != 0 ) {
F_14 ( & V_109 -> V_15 , L_31 ,
V_103 , V_5 ) ;
goto V_135;
}
for ( V_29 = 0 ; V_29 < F_10 ( V_136 ) ; V_29 ++ ) {
V_103 = F_35 ( V_1 ,
F_36 ( V_109 ,
V_136 [ V_29 ] ) ) ;
V_5 = F_37 ( V_103 , NULL , F_24 ,
V_132 | V_133 ,
V_136 [ V_29 ] ,
V_110 ) ;
if ( V_5 != 0 ) {
F_14 ( & V_109 -> V_15 ,
L_32 ,
V_136 [ V_29 ] , V_103 , V_5 ) ;
goto V_137;
}
}
V_110 -> V_138 = F_38 ( & V_109 -> V_15 , L_33 , 0 ) ;
V_5 = F_39 ( V_110 -> V_138 ) ;
switch ( V_5 ) {
case 0 :
V_110 -> V_28 . V_139 = F_8 ;
V_5 = F_40 ( V_110 -> V_138 , & V_110 -> V_28 ) ;
if ( V_5 ) {
F_14 ( & V_109 -> V_15 , L_34 ,
V_5 ) ;
goto V_137;
}
break;
case - V_21 :
case - V_140 :
V_110 -> V_138 = NULL ;
V_5 = 0 ;
break;
default:
F_14 ( & V_109 -> V_15 , L_35 , V_5 ) ;
case - V_141 :
goto V_137;
break;
}
return V_5 ;
V_137:
-- V_29 ;
for (; V_29 >= 0 ; V_29 -- ) {
V_103 = F_36 ( V_109 , V_136 [ V_29 ] ) ;
F_41 ( V_103 , V_110 ) ;
}
V_103 = F_35 ( V_1 , F_36 ( V_109 , L_29 ) ) ;
F_41 ( V_103 , V_110 ) ;
V_135:
V_103 = F_35 ( V_1 , F_36 ( V_109 , L_26 ) ) ;
F_41 ( V_103 , V_110 ) ;
V_134:
if ( V_110 -> V_104 )
F_42 ( V_110 -> V_47 ) ;
V_131:
F_42 ( V_110 -> V_106 ) ;
V_127:
F_42 ( V_110 -> V_107 ) ;
V_123:
return V_5 ;
}
static int F_43 ( struct V_108 * V_109 )
{
struct V_14 * V_14 = F_44 ( V_109 ) ;
struct V_1 * V_1 = V_14 -> V_1 ;
int V_103 , V_29 ;
if ( V_14 -> V_138 ) {
F_45 ( V_14 -> V_138 ,
& V_14 -> V_28 ) ;
}
for ( V_29 = 0 ; V_29 < F_10 ( V_136 ) ; V_29 ++ ) {
V_103 = F_35 ( V_1 ,
F_36 ( V_109 ,
V_136 [ V_29 ] ) ) ;
F_41 ( V_103 , V_14 ) ;
}
V_103 = F_35 ( V_1 , F_36 ( V_109 , L_29 ) ) ;
F_41 ( V_103 , V_14 ) ;
V_103 = F_35 ( V_1 , F_36 ( V_109 , L_26 ) ) ;
F_41 ( V_103 , V_14 ) ;
if ( V_14 -> V_104 )
F_42 ( V_14 -> V_47 ) ;
F_42 ( V_14 -> V_107 ) ;
F_42 ( V_14 -> V_106 ) ;
return 0 ;
}
