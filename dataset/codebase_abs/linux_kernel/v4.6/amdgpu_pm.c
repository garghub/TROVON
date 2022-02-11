void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
return;
if ( V_2 -> V_4 . V_5 ) {
F_2 ( & V_2 -> V_4 . V_6 ) ;
if ( F_3 () > 0 )
V_2 -> V_4 . V_7 . V_8 = true ;
else
V_2 -> V_4 . V_7 . V_8 = false ;
if ( V_2 -> V_4 . V_9 -> V_10 )
F_4 ( V_2 , V_2 -> V_4 . V_7 . V_8 ) ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
}
}
static T_1 F_6 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
enum V_19 V_4 ;
if ( V_2 -> V_3 ) {
V_4 = F_8 ( V_2 ) ;
} else
V_4 = V_2 -> V_4 . V_7 . V_20 ;
return snprintf ( V_15 , V_21 , L_1 ,
( V_4 == V_22 ) ? L_2 :
( V_4 == V_23 ) ? L_3 : L_4 ) ;
}
static T_1 F_9 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
enum V_19 V_25 ;
if ( strncmp ( L_2 , V_15 , strlen ( L_2 ) ) == 0 )
V_25 = V_22 ;
else if ( strncmp ( L_3 , V_15 , strlen ( L_3 ) ) == 0 )
V_25 = V_23 ;
else if ( strncmp ( L_4 , V_15 , strlen ( L_4 ) ) == 0 )
V_25 = V_26 ;
else {
V_24 = - V_27 ;
goto V_28;
}
if ( V_2 -> V_3 ) {
F_10 ( V_2 , V_29 , & V_25 , NULL ) ;
} else {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_20 = V_25 ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
if ( ! ( V_2 -> V_30 & V_31 ) ||
( V_17 -> V_32 == V_33 ) )
F_11 ( V_2 ) ;
}
V_28:
return V_24 ;
}
static T_1 F_12 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
if ( ( V_2 -> V_30 & V_31 ) &&
( V_17 -> V_32 != V_33 ) )
return snprintf ( V_15 , V_21 , L_5 ) ;
if ( V_2 -> V_3 ) {
enum V_34 V_35 ;
V_35 = F_13 ( V_2 ) ;
return snprintf ( V_15 , V_21 , L_1 ,
( V_35 == V_36 ) ? L_6 :
( V_35 == V_37 ) ? L_7 :
( V_35 == V_38 ) ? L_8 :
( V_35 == V_39 ) ? L_9 : L_10 ) ;
} else {
enum V_40 V_35 ;
V_35 = V_2 -> V_4 . V_7 . V_41 ;
return snprintf ( V_15 , V_21 , L_1 ,
( V_35 == V_42 ) ? L_6 :
( V_35 == V_43 ) ? L_7 : L_8 ) ;
}
}
static T_1 F_14 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
enum V_40 V_35 ;
int V_44 = 0 ;
if ( ( V_2 -> V_30 & V_31 ) &&
( V_17 -> V_32 != V_33 ) )
return - V_27 ;
if ( strncmp ( L_7 , V_15 , strlen ( L_7 ) ) == 0 ) {
V_35 = V_43 ;
} else if ( strncmp ( L_8 , V_15 , strlen ( L_8 ) ) == 0 ) {
V_35 = V_45 ;
} else if ( strncmp ( L_6 , V_15 , strlen ( L_6 ) ) == 0 ) {
V_35 = V_42 ;
} else if ( strncmp ( L_9 , V_15 , strlen ( L_9 ) ) == 0 ) {
V_35 = V_46 ;
} else {
V_24 = - V_27 ;
goto V_28;
}
if ( V_2 -> V_3 )
F_15 ( V_2 , V_35 ) ;
else {
F_2 ( & V_2 -> V_4 . V_6 ) ;
if ( V_2 -> V_4 . V_7 . V_47 ) {
V_24 = - V_27 ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
goto V_28;
}
V_44 = F_15 ( V_2 , V_35 ) ;
if ( V_44 )
V_24 = - V_27 ;
else
V_2 -> V_4 . V_7 . V_41 = V_35 ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
}
V_28:
return V_24 ;
}
static T_1 F_16 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_48 V_49 ;
int V_50 , V_51 ;
if ( V_2 -> V_3 )
F_17 ( V_2 , & V_49 ) ;
V_51 = snprintf ( V_15 , V_21 , L_11 , V_49 . V_52 ) ;
for ( V_50 = 0 ; V_50 < V_49 . V_52 ; V_50 ++ )
V_51 += snprintf ( V_15 + V_51 , V_21 , L_12 , V_50 ,
( V_49 . V_53 [ V_50 ] == V_54 ) ? L_13 :
( V_49 . V_53 [ V_50 ] == V_22 ) ? L_2 :
( V_49 . V_53 [ V_50 ] == V_23 ) ? L_3 :
( V_49 . V_53 [ V_50 ] == V_26 ) ? L_4 : L_14 ) ;
return V_51 ;
}
static T_1 F_18 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_48 V_49 ;
enum V_19 V_4 = 0 ;
int V_50 = 0 ;
if ( V_2 -> V_3 ) {
V_4 = F_8 ( V_2 ) ;
F_17 ( V_2 , & V_49 ) ;
for ( V_50 = 0 ; V_50 < V_49 . V_52 ; V_50 ++ ) {
if ( V_4 == V_49 . V_53 [ V_50 ] )
break;
}
if ( V_50 == V_49 . V_52 )
V_50 = - V_27 ;
}
return snprintf ( V_15 , V_21 , L_15 , V_50 ) ;
}
static T_1 F_19 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_48 V_49 ;
enum V_19 V_4 = 0 ;
int V_50 ;
if ( V_2 -> V_55 && V_2 -> V_3 ) {
V_4 = F_8 ( V_2 ) ;
F_17 ( V_2 , & V_49 ) ;
for ( V_50 = 0 ; V_50 < V_49 . V_52 ; V_50 ++ ) {
if ( V_4 == V_49 . V_53 [ V_50 ] )
break;
}
if ( V_50 == V_49 . V_52 )
V_50 = - V_27 ;
return snprintf ( V_15 , V_21 , L_15 , V_50 ) ;
} else
return snprintf ( V_15 , V_21 , L_16 ) ;
}
static T_1 F_20 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
enum V_19 V_25 = 0 ;
long V_56 ;
int V_44 ;
if ( strlen ( V_15 ) == 1 )
V_2 -> V_55 = false ;
else {
V_44 = F_21 ( V_15 , 0 , & V_56 ) ;
if ( V_44 ) {
V_24 = - V_27 ;
goto V_28;
}
if ( V_2 -> V_3 ) {
struct V_48 V_49 ;
F_17 ( V_2 , & V_49 ) ;
V_25 = V_49 . V_53 [ V_56 ] ;
if ( V_25 != V_54 &&
V_25 != V_57 ) {
F_10 ( V_2 ,
V_29 , & V_25 , NULL ) ;
V_2 -> V_55 = true ;
}
}
}
V_28:
return V_24 ;
}
static T_1 F_22 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
char * V_58 = NULL ;
int V_59 , V_50 ;
if ( V_2 -> V_3 )
V_59 = F_23 ( V_2 , & V_58 ) ;
else
return 0 ;
if ( V_59 >= V_21 )
V_59 = V_21 - 1 ;
for ( V_50 = 0 ; V_50 < V_59 ; V_50 ++ ) {
sprintf ( V_15 + V_50 , L_17 , V_58 [ V_50 ] ) ;
}
sprintf ( V_15 + V_50 , L_16 ) ;
return V_59 ;
}
static T_1 F_24 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
if ( V_2 -> V_3 )
F_25 ( V_2 , V_15 , V_24 ) ;
return V_24 ;
}
static T_1 F_26 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
T_1 V_59 = 0 ;
if ( V_2 -> V_3 )
V_59 = F_27 ( V_2 , V_60 , V_15 ) ;
return V_59 ;
}
static T_1 F_28 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_44 ;
long V_35 ;
V_44 = F_21 ( V_15 , 0 , & V_35 ) ;
if ( V_44 ) {
V_24 = - V_27 ;
goto V_28;
}
if ( V_2 -> V_3 )
F_29 ( V_2 , V_60 , V_35 ) ;
V_28:
return V_24 ;
}
static T_1 F_30 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
T_1 V_59 = 0 ;
if ( V_2 -> V_3 )
V_59 = F_27 ( V_2 , V_61 , V_15 ) ;
return V_59 ;
}
static T_1 F_31 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_44 ;
long V_35 ;
V_44 = F_21 ( V_15 , 0 , & V_35 ) ;
if ( V_44 ) {
V_24 = - V_27 ;
goto V_28;
}
if ( V_2 -> V_3 )
F_29 ( V_2 , V_61 , V_35 ) ;
V_28:
return V_24 ;
}
static T_1 F_32 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
T_1 V_59 = 0 ;
if ( V_2 -> V_3 )
V_59 = F_27 ( V_2 , V_62 , V_15 ) ;
return V_59 ;
}
static T_1 F_33 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_44 ;
long V_35 ;
V_44 = F_21 ( V_15 , 0 , & V_35 ) ;
if ( V_44 ) {
V_24 = - V_27 ;
goto V_28;
}
if ( V_2 -> V_3 )
F_29 ( V_2 , V_62 , V_35 ) ;
V_28:
return V_24 ;
}
static T_1 F_34 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
struct V_16 * V_17 = V_2 -> V_17 ;
int V_63 ;
if ( ( V_2 -> V_30 & V_31 ) &&
( V_17 -> V_32 != V_33 ) )
return - V_27 ;
if ( ! V_2 -> V_3 && ! V_2 -> V_4 . V_9 -> V_64 )
V_63 = 0 ;
else
V_63 = F_35 ( V_2 ) ;
return snprintf ( V_15 , V_21 , L_15 , V_63 ) ;
}
static T_1 F_36 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_65 = F_37 ( V_14 ) -> V_66 ;
int V_63 ;
if ( V_65 )
V_63 = V_2 -> V_4 . V_7 . V_67 . V_68 ;
else
V_63 = V_2 -> V_4 . V_7 . V_67 . V_69 ;
return snprintf ( V_15 , V_21 , L_15 , V_63 ) ;
}
static T_1 F_38 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_3 V_70 = 0 ;
if ( ! V_2 -> V_3 && ! V_2 -> V_4 . V_9 -> V_71 )
return - V_27 ;
V_70 = F_39 ( V_2 ) ;
return sprintf ( V_15 , L_18 , V_70 == V_72 ? 1 : 2 ) ;
}
static T_1 F_40 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_73 ;
int V_74 ;
if ( ! V_2 -> V_3 && ! V_2 -> V_4 . V_9 -> V_75 )
return - V_27 ;
V_73 = F_41 ( V_15 , 10 , & V_74 ) ;
if ( V_73 )
return V_73 ;
switch ( V_74 ) {
case 1 :
F_42 ( V_2 , V_72 ) ;
break;
default:
F_42 ( V_2 , 0 ) ;
break;
}
return V_24 ;
}
static T_1 F_43 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
return sprintf ( V_15 , L_18 , 0 ) ;
}
static T_1 F_44 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
return sprintf ( V_15 , L_18 , 255 ) ;
}
static T_1 F_45 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 , T_2 V_24 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_73 ;
T_3 V_74 ;
V_73 = F_46 ( V_15 , 10 , & V_74 ) ;
if ( V_73 )
return V_73 ;
V_74 = ( V_74 * 100 ) / 255 ;
V_73 = F_47 ( V_2 , V_74 ) ;
if ( V_73 )
return V_73 ;
return V_24 ;
}
static T_1 F_48 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_73 ;
T_3 V_76 ;
V_73 = F_49 ( V_2 , & V_76 ) ;
if ( V_73 )
return V_73 ;
V_76 = ( V_76 * 255 ) / 100 ;
return sprintf ( V_15 , L_18 , V_76 ) ;
}
static T_4 F_50 ( struct V_77 * V_78 ,
struct V_79 * V_14 , int V_66 )
{
struct V_11 * V_12 = F_51 ( V_78 ) ;
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_4 V_80 = V_14 -> V_81 ;
if ( ! V_2 -> V_4 . V_5 &&
( V_14 == & V_82 . V_83 . V_14 ||
V_14 == & V_84 . V_83 . V_14 ||
V_14 == & V_85 . V_83 . V_14 ||
V_14 == & V_86 . V_83 . V_14 ||
V_14 == & V_87 . V_83 . V_14 ||
V_14 == & V_88 . V_83 . V_14 ) )
return 0 ;
if ( V_2 -> V_3 )
return V_80 ;
if ( V_2 -> V_4 . V_89 &&
( V_14 == & V_85 . V_83 . V_14 ||
V_14 == & V_86 . V_83 . V_14 ||
V_14 == & V_87 . V_83 . V_14 ||
V_14 == & V_88 . V_83 . V_14 ) )
return 0 ;
if ( ( ! V_2 -> V_4 . V_9 -> V_90 &&
V_14 == & V_85 . V_83 . V_14 ) ||
( ! V_2 -> V_4 . V_9 -> V_71 &&
V_14 == & V_86 . V_83 . V_14 ) )
V_80 &= ~ V_91 ;
if ( ( ! V_2 -> V_4 . V_9 -> V_92 &&
V_14 == & V_85 . V_83 . V_14 ) ||
( ! V_2 -> V_4 . V_9 -> V_75 &&
V_14 == & V_86 . V_83 . V_14 ) )
V_80 &= ~ V_93 ;
if ( ( ! V_2 -> V_4 . V_9 -> V_92 &&
! V_2 -> V_4 . V_9 -> V_90 ) &&
( V_14 == & V_87 . V_83 . V_14 ||
V_14 == & V_88 . V_83 . V_14 ) )
return 0 ;
return V_80 ;
}
void F_52 ( struct V_94 * V_95 )
{
struct V_1 * V_2 =
F_53 ( V_95 , struct V_1 ,
V_4 . V_7 . V_67 . V_95 ) ;
enum V_19 V_96 = V_97 ;
if ( ! V_2 -> V_4 . V_5 )
return;
if ( V_2 -> V_4 . V_9 -> V_64 ) {
int V_63 = F_35 ( V_2 ) ;
if ( V_63 < V_2 -> V_4 . V_7 . V_67 . V_68 )
V_96 = V_2 -> V_4 . V_7 . V_20 ;
} else {
if ( V_2 -> V_4 . V_7 . V_67 . V_98 )
V_96 = V_2 -> V_4 . V_7 . V_20 ;
}
F_2 ( & V_2 -> V_4 . V_6 ) ;
if ( V_96 == V_97 )
V_2 -> V_4 . V_7 . V_47 = true ;
else
V_2 -> V_4 . V_7 . V_47 = false ;
V_2 -> V_4 . V_7 . V_25 = V_96 ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
F_11 ( V_2 ) ;
}
static struct V_99 * F_54 ( struct V_1 * V_2 ,
enum V_19 V_96 )
{
int V_50 ;
struct V_99 * V_100 ;
T_3 V_101 ;
bool V_102 = ( V_2 -> V_4 . V_7 . V_103 < 2 ) ?
true : false ;
if ( V_102 && V_2 -> V_4 . V_9 -> V_104 ) {
if ( F_55 ( V_2 ) )
V_102 = false ;
}
if ( V_96 == V_26 )
V_96 = V_105 ;
if ( V_96 == V_23 )
V_96 = V_26 ;
V_106:
for ( V_50 = 0 ; V_50 < V_2 -> V_4 . V_7 . V_107 ; V_50 ++ ) {
V_100 = & V_2 -> V_4 . V_7 . V_100 [ V_50 ] ;
V_101 = V_100 -> V_108 & V_109 ;
switch ( V_96 ) {
case V_22 :
if ( V_101 == V_110 ) {
if ( V_100 -> V_111 & V_112 ) {
if ( V_102 )
return V_100 ;
} else
return V_100 ;
}
break;
case V_23 :
if ( V_101 == V_113 ) {
if ( V_100 -> V_111 & V_112 ) {
if ( V_102 )
return V_100 ;
} else
return V_100 ;
}
break;
case V_26 :
if ( V_101 == V_114 ) {
if ( V_100 -> V_111 & V_112 ) {
if ( V_102 )
return V_100 ;
} else
return V_100 ;
}
break;
case V_115 :
if ( V_2 -> V_4 . V_7 . V_116 )
return V_2 -> V_4 . V_7 . V_116 ;
else
break;
case V_117 :
if ( V_100 -> V_108 & V_118 )
return V_100 ;
break;
case V_119 :
if ( V_100 -> V_108 & V_120 )
return V_100 ;
break;
case V_121 :
if ( V_100 -> V_108 & V_122 )
return V_100 ;
break;
case V_123 :
if ( V_100 -> V_124 & V_125 )
return V_100 ;
break;
case V_54 :
return V_2 -> V_4 . V_7 . V_126 ;
case V_97 :
if ( V_100 -> V_108 & V_127 )
return V_100 ;
break;
case V_128 :
if ( V_100 -> V_108 & V_129 )
return V_100 ;
break;
case V_130 :
if ( V_100 -> V_124 & V_131 )
return V_100 ;
break;
case V_105 :
if ( V_100 -> V_108 & V_132 )
return V_100 ;
break;
default:
break;
}
}
switch ( V_96 ) {
case V_117 :
V_96 = V_119 ;
goto V_106;
case V_119 :
case V_121 :
case V_123 :
if ( V_2 -> V_4 . V_7 . V_116 ) {
return V_2 -> V_4 . V_7 . V_116 ;
} else {
V_96 = V_26 ;
goto V_106;
}
case V_97 :
V_96 = V_128 ;
goto V_106;
case V_128 :
V_96 = V_22 ;
goto V_106;
case V_22 :
case V_23 :
case V_105 :
V_96 = V_26 ;
goto V_106;
default:
break;
}
return NULL ;
}
static void F_56 ( struct V_1 * V_2 )
{
int V_50 ;
struct V_99 * V_100 ;
enum V_19 V_96 ;
int V_44 ;
if ( ! V_2 -> V_4 . V_5 )
return;
if ( V_2 -> V_4 . V_7 . V_20 != V_2 -> V_4 . V_7 . V_25 ) {
if ( ( ! V_2 -> V_4 . V_7 . V_47 ) &&
( ! V_2 -> V_4 . V_7 . V_133 ) )
V_2 -> V_4 . V_7 . V_25 = V_2 -> V_4 . V_7 . V_20 ;
}
V_96 = V_2 -> V_4 . V_7 . V_25 ;
V_100 = F_54 ( V_2 , V_96 ) ;
if ( V_100 )
V_2 -> V_4 . V_7 . V_134 = V_100 ;
else
return;
if ( V_2 -> V_4 . V_7 . V_135 == V_2 -> V_4 . V_7 . V_134 ) {
if ( V_100 -> V_136 != V_2 -> V_4 . V_7 . V_136 )
goto V_137;
if ( V_2 -> V_30 & V_138 ) {
if ( V_2 -> V_4 . V_7 . V_139 != V_2 -> V_4 . V_7 . V_140 ) {
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
V_2 -> V_4 . V_7 . V_140 = V_2 -> V_4 . V_7 . V_139 ;
V_2 -> V_4 . V_7 . V_141 = V_2 -> V_4 . V_7 . V_103 ;
}
return;
} else {
if ( V_2 -> V_4 . V_7 . V_139 ==
V_2 -> V_4 . V_7 . V_140 ) {
return;
} else if ( ( V_2 -> V_4 . V_7 . V_141 > 1 ) &&
( V_2 -> V_4 . V_7 . V_103 > 1 ) ) {
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
V_2 -> V_4 . V_7 . V_140 = V_2 -> V_4 . V_7 . V_139 ;
V_2 -> V_4 . V_7 . V_141 = V_2 -> V_4 . V_7 . V_103 ;
return;
}
}
}
V_137:
if ( V_142 == 1 ) {
F_59 ( L_19 ) ;
F_60 ( V_2 , V_2 -> V_4 . V_7 . V_135 ) ;
F_59 ( L_20 ) ;
F_60 ( V_2 , V_2 -> V_4 . V_7 . V_134 ) ;
}
V_100 -> V_136 = V_2 -> V_4 . V_7 . V_136 ;
V_44 = F_61 ( V_2 ) ;
if ( V_44 )
return;
F_57 ( V_2 ) ;
for ( V_50 = 0 ; V_50 < V_143 ; V_50 ++ ) {
struct V_144 * V_145 = V_2 -> V_146 [ V_50 ] ;
if ( V_145 && V_145 -> V_147 )
F_62 ( V_145 ) ;
}
F_63 ( V_2 ) ;
V_2 -> V_4 . V_7 . V_135 = V_2 -> V_4 . V_7 . V_134 ;
F_64 ( V_2 ) ;
F_58 ( V_2 ) ;
V_2 -> V_4 . V_7 . V_140 = V_2 -> V_4 . V_7 . V_139 ;
V_2 -> V_4 . V_7 . V_141 = V_2 -> V_4 . V_7 . V_103 ;
if ( V_2 -> V_4 . V_9 -> V_148 ) {
if ( V_2 -> V_4 . V_7 . V_47 ) {
enum V_40 V_35 = V_2 -> V_4 . V_7 . V_41 ;
F_15 ( V_2 , V_43 ) ;
V_2 -> V_4 . V_7 . V_41 = V_35 ;
} else {
F_15 ( V_2 , V_2 -> V_4 . V_7 . V_41 ) ;
}
}
}
void F_65 ( struct V_1 * V_2 , bool V_149 )
{
if ( V_2 -> V_3 )
F_66 ( V_2 , ! V_149 ) ;
else {
if ( V_2 -> V_4 . V_9 -> V_150 ) {
F_2 ( & V_2 -> V_4 . V_6 ) ;
F_66 ( V_2 , ! V_149 ) ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
} else {
if ( V_149 ) {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_133 = true ;
V_2 -> V_4 . V_7 . V_25 = V_115 ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
} else {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_133 = false ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
}
F_11 ( V_2 ) ;
}
}
}
void F_67 ( struct V_1 * V_2 , bool V_149 )
{
if ( V_2 -> V_3 )
F_68 ( V_2 , ! V_149 ) ;
else {
if ( V_2 -> V_4 . V_9 -> V_151 ) {
F_2 ( & V_2 -> V_4 . V_6 ) ;
F_68 ( V_2 , ! V_149 ) ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
} else {
if ( V_149 ) {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_136 = true ;
V_2 -> V_4 . V_7 . V_152 = V_153 ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
} else {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_136 = false ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
}
F_11 ( V_2 ) ;
}
}
}
void F_69 ( struct V_1 * V_2 )
{
int V_50 ;
if ( V_2 -> V_3 )
return;
for ( V_50 = 0 ; V_50 < V_2 -> V_4 . V_7 . V_107 ; V_50 ++ )
F_60 ( V_2 , & V_2 -> V_4 . V_7 . V_100 [ V_50 ] ) ;
}
int F_70 ( struct V_1 * V_2 )
{
int V_44 ;
if ( V_2 -> V_4 . V_154 )
return 0 ;
if ( ! V_2 -> V_3 ) {
if ( V_2 -> V_4 . V_9 -> V_64 == NULL )
return 0 ;
}
V_2 -> V_4 . V_155 = F_71 ( V_2 -> V_12 ,
V_156 , V_2 ,
V_157 ) ;
if ( F_72 ( V_2 -> V_4 . V_155 ) ) {
V_44 = F_73 ( V_2 -> V_4 . V_155 ) ;
F_74 ( V_2 -> V_12 ,
L_21 , V_44 ) ;
return V_44 ;
}
V_44 = F_75 ( V_2 -> V_12 , & V_158 ) ;
if ( V_44 ) {
F_76 ( L_22 ) ;
return V_44 ;
}
V_44 = F_75 ( V_2 -> V_12 , & V_159 ) ;
if ( V_44 ) {
F_76 ( L_22 ) ;
return V_44 ;
}
if ( V_2 -> V_3 ) {
V_44 = F_75 ( V_2 -> V_12 , & V_160 ) ;
if ( V_44 ) {
F_76 ( L_23 ) ;
return V_44 ;
}
V_44 = F_75 ( V_2 -> V_12 , & V_161 ) ;
if ( V_44 ) {
F_76 ( L_24 ) ;
return V_44 ;
}
V_44 = F_75 ( V_2 -> V_12 , & V_162 ) ;
if ( V_44 ) {
F_76 ( L_25 ) ;
return V_44 ;
}
V_44 = F_75 ( V_2 -> V_12 , & V_163 ) ;
if ( V_44 ) {
F_76 ( L_26 ) ;
return V_44 ;
}
V_44 = F_75 ( V_2 -> V_12 , & V_164 ) ;
if ( V_44 ) {
F_76 ( L_27 ) ;
return V_44 ;
}
V_44 = F_75 ( V_2 -> V_12 , & V_165 ) ;
if ( V_44 ) {
F_76 ( L_28 ) ;
return V_44 ;
}
V_44 = F_75 ( V_2 -> V_12 , & V_166 ) ;
if ( V_44 ) {
F_76 ( L_29 ) ;
return V_44 ;
}
}
V_44 = F_77 ( V_2 ) ;
if ( V_44 ) {
F_76 ( L_30 ) ;
return V_44 ;
}
V_2 -> V_4 . V_154 = true ;
return 0 ;
}
void F_78 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . V_155 )
F_79 ( V_2 -> V_4 . V_155 ) ;
F_80 ( V_2 -> V_12 , & V_158 ) ;
F_80 ( V_2 -> V_12 , & V_159 ) ;
if ( V_2 -> V_3 ) {
F_80 ( V_2 -> V_12 , & V_160 ) ;
F_80 ( V_2 -> V_12 , & V_161 ) ;
F_80 ( V_2 -> V_12 , & V_162 ) ;
F_80 ( V_2 -> V_12 , & V_163 ) ;
F_80 ( V_2 -> V_12 , & V_164 ) ;
F_80 ( V_2 -> V_12 , & V_165 ) ;
F_80 ( V_2 -> V_12 , & V_166 ) ;
}
}
void F_11 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
struct V_167 * V_168 ;
struct V_169 * V_169 ;
if ( ! V_2 -> V_4 . V_5 )
return;
if ( V_2 -> V_3 ) {
int V_50 = 0 ;
F_57 ( V_2 ) ;
for ( V_50 = 0 ; V_50 < V_143 ; V_50 ++ ) {
struct V_144 * V_145 = V_2 -> V_146 [ V_50 ] ;
if ( V_145 && V_145 -> V_147 )
F_62 ( V_145 ) ;
}
F_10 ( V_2 , V_170 , NULL , NULL ) ;
} else {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_139 = 0 ;
V_2 -> V_4 . V_7 . V_103 = 0 ;
if ( V_2 -> V_171 . V_172 && V_2 -> V_171 . V_173 ) {
F_81 (crtc,
&ddev->mode_config.crtc_list, head) {
V_169 = F_82 ( V_168 ) ;
if ( V_168 -> V_174 ) {
V_2 -> V_4 . V_7 . V_139 |= ( 1 << V_169 -> V_175 ) ;
V_2 -> V_4 . V_7 . V_103 ++ ;
}
}
}
if ( F_3 () > 0 )
V_2 -> V_4 . V_7 . V_8 = true ;
else
V_2 -> V_4 . V_7 . V_8 = false ;
F_56 ( V_2 ) ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
}
}
static int F_83 ( struct V_176 * V_177 , void * V_49 )
{
struct V_178 * V_179 = (struct V_178 * ) V_177 -> V_180 ;
struct V_16 * V_12 = V_179 -> V_181 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_18 ;
struct V_16 * V_17 = V_2 -> V_17 ;
if ( ! V_2 -> V_4 . V_5 ) {
F_84 ( V_177 , L_31 ) ;
return 0 ;
}
if ( ( V_2 -> V_30 & V_31 ) &&
( V_17 -> V_32 != V_33 ) ) {
F_84 ( V_177 , L_32 ) ;
} else if ( V_2 -> V_3 ) {
F_85 ( V_2 , V_177 ) ;
} else {
F_2 ( & V_2 -> V_4 . V_6 ) ;
if ( V_2 -> V_4 . V_9 -> V_182 )
F_85 ( V_2 , V_177 ) ;
else
F_84 ( V_177 , L_33 ) ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
}
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
#if F_86 ( V_183 )
return F_87 ( V_2 , V_184 , F_88 ( V_184 ) ) ;
#else
return 0 ;
#endif
}
