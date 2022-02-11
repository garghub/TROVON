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
static void F_8 ( struct V_1 * V_1 ,
struct V_24 * V_25 , int V_26 , int V_4 ,
int * V_27 , const char * V_28 ,
const char * V_29 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_26 ; V_30 ++ )
if ( V_4 == V_25 [ V_30 ] . V_4 )
break;
if ( V_30 == V_26 ) {
F_9 ( V_1 -> V_15 , L_1 ,
V_28 , V_4 , V_29 ) ;
} else {
* V_27 |= V_25 [ V_30 ] . V_31 ;
F_10 ( V_1 -> V_15 , L_2 , V_28 , V_4 , V_29 ) ;
}
}
static void F_11 ( struct V_1 * V_1 )
{
struct V_32 * V_32 = V_1 -> V_15 -> V_33 ;
struct V_34 * V_35 ;
int V_5 , V_36 , V_37 ;
if ( ! V_32 || ! V_32 -> V_38 ) {
F_12 ( V_1 -> V_15 ,
L_3 ) ;
return;
}
V_35 = V_32 -> V_38 ;
V_36 = 0 ;
V_37 = 0 ;
if ( ! V_35 -> V_39 ) {
F_13 ( V_1 -> V_15 , L_4 ) ;
return;
}
V_36 |= V_40 ;
if ( V_35 -> V_41 )
V_37 |= V_42 ;
if ( V_35 -> V_43 )
V_36 |= V_44 ;
F_8 ( V_1 , V_45 ,
F_14 ( V_45 ) ,
V_35 -> V_46 , & V_37 ,
L_5 , L_6 ) ;
F_8 ( V_1 , V_47 , F_14 ( V_47 ) ,
V_35 -> V_48 , & V_37 ,
L_7 , L_8 ) ;
F_8 ( V_1 , V_49 , F_14 ( V_49 ) ,
V_35 -> V_50 , & V_37 ,
L_9 , L_6 ) ;
F_8 ( V_1 , V_51 , F_14 ( V_51 ) ,
V_35 -> V_52 , & V_36 ,
L_10 , L_6 ) ;
F_8 ( V_1 , V_53 , F_14 ( V_53 ) ,
V_35 -> V_54 , & V_37 ,
L_11 , L_12 ) ;
V_5 = F_15 ( V_1 ) ;
if ( V_5 != 0 ) {
F_9 ( V_1 -> V_15 , L_13 , V_5 ) ;
return;
}
V_5 = F_16 ( V_1 , V_55 ,
V_56 |
V_57 |
V_58 ,
V_36 ) ;
if ( V_5 != 0 )
F_9 ( V_1 -> V_15 , L_14 ,
V_5 ) ;
V_5 = F_16 ( V_1 , V_59 ,
V_42 |
V_60 |
V_61 |
V_62 |
V_63 ,
V_37 ) ;
if ( V_5 != 0 )
F_9 ( V_1 -> V_15 , L_15 ,
V_5 ) ;
F_17 ( V_1 ) ;
}
static int F_18 ( struct V_1 * V_1 , int * V_64 )
{
int V_5 ;
V_5 = F_2 ( V_1 , V_6 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 & V_65 ) {
* V_64 = V_66 ;
return 0 ;
}
V_5 = F_2 ( V_1 , V_67 ) ;
if ( V_5 < 0 )
return V_5 ;
switch ( V_5 & V_68 ) {
case V_69 :
* V_64 = V_70 ;
break;
case V_71 :
case V_72 :
* V_64 = V_73 ;
break;
default:
* V_64 = V_74 ;
break;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_1 , int * type )
{
int V_5 ;
V_5 = F_2 ( V_1 , V_67 ) ;
if ( V_5 < 0 )
return V_5 ;
switch ( V_5 & V_68 ) {
case V_71 :
case V_75 :
* type = V_76 ;
break;
case V_72 :
case V_77 :
* type = V_78 ;
break;
default:
* type = V_79 ;
break;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_1 , int * V_80 )
{
int V_5 ;
V_5 = F_2 ( V_1 , V_67 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 & V_81 ) {
* V_80 = V_82 ;
return 0 ;
}
if ( V_5 & V_83 ) {
* V_80 = V_84 ;
return 0 ;
}
if ( V_5 & V_85 ) {
* V_80 = V_86 ;
return 0 ;
}
switch ( V_5 & V_68 ) {
case V_75 :
case V_77 :
* V_80 = V_82 ;
break;
case V_87 :
* V_80 = V_88 ;
break;
default:
* V_80 = V_89 ;
break;
}
return 0 ;
}
static int F_21 ( struct V_10 * V_11 ,
enum V_12 V_13 ,
union V_3 * V_4 )
{
struct V_14 * V_14 = F_6 ( V_11 -> V_15 . V_16 ) ;
struct V_1 * V_1 = V_14 -> V_1 ;
int V_5 = 0 ;
switch ( V_13 ) {
case V_90 :
V_5 = F_18 ( V_1 , & V_4 -> V_7 ) ;
break;
case V_17 :
V_5 = F_1 ( V_1 , V_65 ,
V_4 ) ;
break;
case V_19 :
V_5 = F_3 ( V_1 , V_91 , V_4 ) ;
break;
case V_92 :
V_5 = F_20 ( V_1 , & V_4 -> V_7 ) ;
break;
case V_93 :
V_5 = F_19 ( V_1 , & V_4 -> V_7 ) ;
break;
default:
V_5 = - V_21 ;
break;
}
return V_5 ;
}
static T_1 F_22 ( int V_94 , void * V_95 )
{
struct V_14 * V_14 = V_95 ;
struct V_1 * V_1 = V_14 -> V_1 ;
F_10 ( V_1 -> V_15 , L_16 , V_94 ) ;
if ( V_14 -> V_96 )
F_23 ( V_14 -> V_38 ) ;
return V_97 ;
}
static T_1 F_24 ( int V_94 , void * V_95 )
{
struct V_14 * V_14 = V_95 ;
struct V_1 * V_1 = V_14 -> V_1 ;
F_25 ( V_1 -> V_15 , L_17 ) ;
return V_97 ;
}
static T_1 F_26 ( int V_94 , void * V_95 )
{
struct V_14 * V_14 = V_95 ;
struct V_1 * V_1 = V_14 -> V_1 ;
F_10 ( V_1 -> V_15 , L_18 ) ;
if ( V_14 -> V_96 )
F_23 ( V_14 -> V_38 ) ;
F_23 ( V_14 -> V_98 ) ;
F_23 ( V_14 -> V_99 ) ;
return V_97 ;
}
static int F_27 ( struct V_100 * V_101 )
{
struct V_1 * V_1 = F_6 ( V_101 -> V_15 . V_16 ) ;
struct V_32 * V_32 = V_1 -> V_15 -> V_33 ;
struct V_14 * V_102 ;
int V_5 , V_94 , V_30 ;
V_102 = F_28 ( sizeof( struct V_14 ) , V_103 ) ;
if ( V_102 == NULL )
return - V_104 ;
V_102 -> V_1 = V_1 ;
F_29 ( V_101 , V_102 ) ;
if ( V_32 && V_32 -> V_105 ) {
snprintf ( V_102 -> V_106 , sizeof( V_102 -> V_106 ) ,
L_19 , V_32 -> V_105 ) ;
snprintf ( V_102 -> V_107 , sizeof( V_102 -> V_106 ) ,
L_20 , V_32 -> V_105 ) ;
snprintf ( V_102 -> V_108 , sizeof( V_102 -> V_106 ) ,
L_21 , V_32 -> V_105 ) ;
} else {
snprintf ( V_102 -> V_106 , sizeof( V_102 -> V_106 ) ,
L_22 ) ;
snprintf ( V_102 -> V_107 , sizeof( V_102 -> V_106 ) ,
L_23 ) ;
snprintf ( V_102 -> V_108 , sizeof( V_102 -> V_106 ) ,
L_24 ) ;
}
F_11 ( V_1 ) ;
V_102 -> V_109 . V_28 = V_102 -> V_106 ;
V_102 -> V_109 . type = V_110 ;
V_102 -> V_109 . V_111 = V_112 ;
V_102 -> V_109 . V_113 = F_14 ( V_112 ) ;
V_102 -> V_109 . V_114 = F_5 ;
V_102 -> V_99 = F_30 ( & V_101 -> V_15 , & V_102 -> V_109 ,
NULL ) ;
if ( F_31 ( V_102 -> V_99 ) ) {
V_5 = F_32 ( V_102 -> V_99 ) ;
goto V_115;
}
V_102 -> V_116 . V_28 = V_102 -> V_108 ,
V_102 -> V_116 . type = V_117 ;
V_102 -> V_116 . V_111 = V_118 ;
V_102 -> V_116 . V_113 = F_14 ( V_118 ) ;
V_102 -> V_116 . V_114 = F_7 ;
V_102 -> V_98 = F_30 ( & V_101 -> V_15 , & V_102 -> V_116 , NULL ) ;
if ( F_31 ( V_102 -> V_98 ) ) {
V_5 = F_32 ( V_102 -> V_98 ) ;
goto V_119;
}
V_5 = F_2 ( V_1 , V_55 ) ;
if ( V_5 < 0 )
goto V_119;
V_102 -> V_96 = V_5 & V_40 ;
if ( V_102 -> V_96 ) {
V_102 -> V_120 . V_28 = V_102 -> V_107 ;
V_102 -> V_120 . V_111 = V_121 ;
V_102 -> V_120 . V_113 = F_14 ( V_121 ) ;
V_102 -> V_120 . V_114 = F_21 ;
V_102 -> V_120 . V_122 = 1 ;
V_102 -> V_38 = F_30 ( & V_101 -> V_15 ,
& V_102 -> V_120 ,
NULL ) ;
if ( F_31 ( V_102 -> V_38 ) ) {
V_5 = F_32 ( V_102 -> V_38 ) ;
goto V_123;
}
}
V_94 = F_33 ( V_1 , F_34 ( V_101 , L_25 ) ) ;
V_5 = F_35 ( V_94 , NULL , F_24 ,
V_124 , L_26 ,
V_102 ) ;
if ( V_5 != 0 ) {
F_9 ( & V_101 -> V_15 , L_27 ,
V_94 , V_5 ) ;
goto V_125;
}
V_94 = F_33 ( V_1 , F_34 ( V_101 , L_28 ) ) ;
V_5 = F_35 ( V_94 , NULL , F_26 ,
V_124 , L_29 ,
V_102 ) ;
if ( V_5 != 0 ) {
F_9 ( & V_101 -> V_15 , L_30 ,
V_94 , V_5 ) ;
goto V_126;
}
for ( V_30 = 0 ; V_30 < F_14 ( V_127 ) ; V_30 ++ ) {
V_94 = F_33 ( V_1 ,
F_34 ( V_101 ,
V_127 [ V_30 ] ) ) ;
V_5 = F_35 ( V_94 , NULL , F_22 ,
V_124 ,
V_127 [ V_30 ] ,
V_102 ) ;
if ( V_5 != 0 ) {
F_9 ( & V_101 -> V_15 ,
L_31 ,
V_127 [ V_30 ] , V_94 , V_5 ) ;
goto V_128;
}
}
return V_5 ;
V_128:
for (; V_30 >= 0 ; V_30 -- ) {
V_94 = F_34 ( V_101 , V_127 [ V_30 ] ) ;
F_36 ( V_94 , V_102 ) ;
}
V_94 = F_33 ( V_1 , F_34 ( V_101 , L_28 ) ) ;
F_36 ( V_94 , V_102 ) ;
V_126:
V_94 = F_33 ( V_1 , F_34 ( V_101 , L_25 ) ) ;
F_36 ( V_94 , V_102 ) ;
V_125:
if ( V_102 -> V_96 )
F_37 ( V_102 -> V_38 ) ;
V_123:
F_37 ( V_102 -> V_98 ) ;
V_119:
F_37 ( V_102 -> V_99 ) ;
V_115:
F_38 ( V_102 ) ;
return V_5 ;
}
static int F_39 ( struct V_100 * V_101 )
{
struct V_14 * V_14 = F_40 ( V_101 ) ;
struct V_1 * V_1 = V_14 -> V_1 ;
int V_94 , V_30 ;
for ( V_30 = 0 ; V_30 < F_14 ( V_127 ) ; V_30 ++ ) {
V_94 = F_33 ( V_1 ,
F_34 ( V_101 ,
V_127 [ V_30 ] ) ) ;
F_36 ( V_94 , V_14 ) ;
}
V_94 = F_33 ( V_1 , F_34 ( V_101 , L_28 ) ) ;
F_36 ( V_94 , V_14 ) ;
V_94 = F_33 ( V_1 , F_34 ( V_101 , L_25 ) ) ;
F_36 ( V_94 , V_14 ) ;
if ( V_14 -> V_96 )
F_37 ( V_14 -> V_38 ) ;
F_37 ( V_14 -> V_99 ) ;
F_37 ( V_14 -> V_98 ) ;
F_38 ( V_14 ) ;
return 0 ;
}
