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
unsigned long V_56 ;
int V_44 ;
if ( strlen ( V_15 ) == 1 )
V_2 -> V_55 = false ;
else if ( V_2 -> V_3 ) {
struct V_48 V_49 ;
V_44 = F_21 ( V_15 , 0 , & V_56 ) ;
if ( V_44 || V_56 >= F_22 ( V_49 . V_53 ) ) {
V_24 = - V_27 ;
goto V_28;
}
F_17 ( V_2 , & V_49 ) ;
V_25 = V_49 . V_53 [ V_56 ] ;
if ( V_25 != V_54 &&
V_25 != V_57 ) {
F_10 ( V_2 ,
V_29 , & V_25 , NULL ) ;
V_2 -> V_55 = true ;
}
}
V_28:
return V_24 ;
}
static T_1 F_23 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
char * V_58 = NULL ;
int V_59 , V_50 ;
if ( V_2 -> V_3 )
V_59 = F_24 ( V_2 , & V_58 ) ;
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
static T_1 F_25 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
if ( V_2 -> V_3 )
F_26 ( V_2 , V_15 , V_24 ) ;
return V_24 ;
}
static T_1 F_27 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
T_1 V_59 = 0 ;
if ( V_2 -> V_3 )
V_59 = F_28 ( V_2 , V_60 , V_15 ) ;
return V_59 ;
}
static T_1 F_29 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_44 ;
long V_35 ;
T_3 V_50 , V_61 = 0 ;
char V_62 [ 2 ] ;
for ( V_50 = 0 ; V_50 < strlen ( V_15 ) - 1 ; V_50 ++ ) {
V_62 [ 0 ] = * ( V_15 + V_50 ) ;
V_62 [ 1 ] = '\0' ;
V_44 = F_30 ( V_62 , 0 , & V_35 ) ;
if ( V_44 ) {
V_24 = - V_27 ;
goto V_28;
}
V_61 |= 1 << V_35 ;
}
if ( V_2 -> V_3 )
F_31 ( V_2 , V_60 , V_61 ) ;
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
V_59 = F_28 ( V_2 , V_63 , V_15 ) ;
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
T_3 V_50 , V_61 = 0 ;
char V_62 [ 2 ] ;
for ( V_50 = 0 ; V_50 < strlen ( V_15 ) - 1 ; V_50 ++ ) {
V_62 [ 0 ] = * ( V_15 + V_50 ) ;
V_62 [ 1 ] = '\0' ;
V_44 = F_30 ( V_62 , 0 , & V_35 ) ;
if ( V_44 ) {
V_24 = - V_27 ;
goto V_28;
}
V_61 |= 1 << V_35 ;
}
if ( V_2 -> V_3 )
F_31 ( V_2 , V_63 , V_61 ) ;
V_28:
return V_24 ;
}
static T_1 F_34 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
T_1 V_59 = 0 ;
if ( V_2 -> V_3 )
V_59 = F_28 ( V_2 , V_64 , V_15 ) ;
return V_59 ;
}
static T_1 F_35 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_44 ;
long V_35 ;
T_3 V_50 , V_61 = 0 ;
char V_62 [ 2 ] ;
for ( V_50 = 0 ; V_50 < strlen ( V_15 ) - 1 ; V_50 ++ ) {
V_62 [ 0 ] = * ( V_15 + V_50 ) ;
V_62 [ 1 ] = '\0' ;
V_44 = F_30 ( V_62 , 0 , & V_35 ) ;
if ( V_44 ) {
V_24 = - V_27 ;
goto V_28;
}
V_61 |= 1 << V_35 ;
}
if ( V_2 -> V_3 )
F_31 ( V_2 , V_64 , V_61 ) ;
V_28:
return V_24 ;
}
static T_1 F_36 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
struct V_16 * V_17 = V_2 -> V_17 ;
int V_65 ;
if ( ( V_2 -> V_30 & V_31 ) &&
( V_17 -> V_32 != V_33 ) )
return - V_27 ;
if ( ! V_2 -> V_3 && ! V_2 -> V_4 . V_9 -> V_66 )
V_65 = 0 ;
else
V_65 = F_37 ( V_2 ) ;
return snprintf ( V_15 , V_21 , L_15 , V_65 ) ;
}
static T_1 F_38 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_67 = F_39 ( V_14 ) -> V_68 ;
int V_65 ;
if ( V_67 )
V_65 = V_2 -> V_4 . V_7 . V_69 . V_70 ;
else
V_65 = V_2 -> V_4 . V_7 . V_69 . V_71 ;
return snprintf ( V_15 , V_21 , L_15 , V_65 ) ;
}
static T_1 F_40 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_4 V_72 = 0 ;
if ( ! V_2 -> V_3 && ! V_2 -> V_4 . V_9 -> V_73 )
return - V_27 ;
V_72 = F_41 ( V_2 ) ;
return sprintf ( V_15 , L_18 , V_72 == V_74 ? 1 : 2 ) ;
}
static T_1 F_42 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_75 ;
int V_76 ;
if ( ! V_2 -> V_3 && ! V_2 -> V_4 . V_9 -> V_77 )
return - V_27 ;
V_75 = F_43 ( V_15 , 10 , & V_76 ) ;
if ( V_75 )
return V_75 ;
switch ( V_76 ) {
case 1 :
F_44 ( V_2 , V_74 ) ;
break;
default:
F_44 ( V_2 , 0 ) ;
break;
}
return V_24 ;
}
static T_1 F_45 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
return sprintf ( V_15 , L_18 , 0 ) ;
}
static T_1 F_46 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
return sprintf ( V_15 , L_18 , 255 ) ;
}
static T_1 F_47 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 , T_2 V_24 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_75 ;
T_4 V_76 ;
V_75 = F_48 ( V_15 , 10 , & V_76 ) ;
if ( V_75 )
return V_75 ;
V_76 = ( V_76 * 100 ) / 255 ;
V_75 = F_49 ( V_2 , V_76 ) ;
if ( V_75 )
return V_75 ;
return V_24 ;
}
static T_1 F_50 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_75 ;
T_4 V_78 ;
V_75 = F_51 ( V_2 , & V_78 ) ;
if ( V_75 )
return V_75 ;
V_78 = ( V_78 * 255 ) / 100 ;
return sprintf ( V_15 , L_18 , V_78 ) ;
}
static T_5 F_52 ( struct V_79 * V_80 ,
struct V_81 * V_14 , int V_68 )
{
struct V_11 * V_12 = F_53 ( V_80 ) ;
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_5 V_82 = V_14 -> V_83 ;
if ( ! V_2 -> V_4 . V_5 &&
( V_14 == & V_84 . V_85 . V_14 ||
V_14 == & V_86 . V_85 . V_14 ||
V_14 == & V_87 . V_85 . V_14 ||
V_14 == & V_88 . V_85 . V_14 ||
V_14 == & V_89 . V_85 . V_14 ||
V_14 == & V_90 . V_85 . V_14 ) )
return 0 ;
if ( V_2 -> V_3 )
return V_82 ;
if ( V_2 -> V_4 . V_91 &&
( V_14 == & V_87 . V_85 . V_14 ||
V_14 == & V_88 . V_85 . V_14 ||
V_14 == & V_89 . V_85 . V_14 ||
V_14 == & V_90 . V_85 . V_14 ) )
return 0 ;
if ( ( ! V_2 -> V_4 . V_9 -> V_92 &&
V_14 == & V_87 . V_85 . V_14 ) ||
( ! V_2 -> V_4 . V_9 -> V_73 &&
V_14 == & V_88 . V_85 . V_14 ) )
V_82 &= ~ V_93 ;
if ( ( ! V_2 -> V_4 . V_9 -> V_94 &&
V_14 == & V_87 . V_85 . V_14 ) ||
( ! V_2 -> V_4 . V_9 -> V_77 &&
V_14 == & V_88 . V_85 . V_14 ) )
V_82 &= ~ V_95 ;
if ( ( ! V_2 -> V_4 . V_9 -> V_94 &&
! V_2 -> V_4 . V_9 -> V_92 ) &&
( V_14 == & V_89 . V_85 . V_14 ||
V_14 == & V_90 . V_85 . V_14 ) )
return 0 ;
return V_82 ;
}
void F_54 ( struct V_96 * V_97 )
{
struct V_1 * V_2 =
F_55 ( V_97 , struct V_1 ,
V_4 . V_7 . V_69 . V_97 ) ;
enum V_19 V_98 = V_99 ;
if ( ! V_2 -> V_4 . V_5 )
return;
if ( V_2 -> V_4 . V_9 -> V_66 ) {
int V_65 = F_37 ( V_2 ) ;
if ( V_65 < V_2 -> V_4 . V_7 . V_69 . V_70 )
V_98 = V_2 -> V_4 . V_7 . V_20 ;
} else {
if ( V_2 -> V_4 . V_7 . V_69 . V_100 )
V_98 = V_2 -> V_4 . V_7 . V_20 ;
}
F_2 ( & V_2 -> V_4 . V_6 ) ;
if ( V_98 == V_99 )
V_2 -> V_4 . V_7 . V_47 = true ;
else
V_2 -> V_4 . V_7 . V_47 = false ;
V_2 -> V_4 . V_7 . V_25 = V_98 ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
F_11 ( V_2 ) ;
}
static struct V_101 * F_56 ( struct V_1 * V_2 ,
enum V_19 V_98 )
{
int V_50 ;
struct V_101 * V_102 ;
T_4 V_103 ;
bool V_104 = ( V_2 -> V_4 . V_7 . V_105 < 2 ) ?
true : false ;
if ( V_104 && V_2 -> V_4 . V_9 -> V_106 ) {
if ( F_57 ( V_2 ) )
V_104 = false ;
}
if ( V_98 == V_26 )
V_98 = V_107 ;
if ( V_98 == V_23 )
V_98 = V_26 ;
V_108:
for ( V_50 = 0 ; V_50 < V_2 -> V_4 . V_7 . V_109 ; V_50 ++ ) {
V_102 = & V_2 -> V_4 . V_7 . V_102 [ V_50 ] ;
V_103 = V_102 -> V_110 & V_111 ;
switch ( V_98 ) {
case V_22 :
if ( V_103 == V_112 ) {
if ( V_102 -> V_113 & V_114 ) {
if ( V_104 )
return V_102 ;
} else
return V_102 ;
}
break;
case V_23 :
if ( V_103 == V_115 ) {
if ( V_102 -> V_113 & V_114 ) {
if ( V_104 )
return V_102 ;
} else
return V_102 ;
}
break;
case V_26 :
if ( V_103 == V_116 ) {
if ( V_102 -> V_113 & V_114 ) {
if ( V_104 )
return V_102 ;
} else
return V_102 ;
}
break;
case V_117 :
if ( V_2 -> V_4 . V_7 . V_118 )
return V_2 -> V_4 . V_7 . V_118 ;
else
break;
case V_119 :
if ( V_102 -> V_110 & V_120 )
return V_102 ;
break;
case V_121 :
if ( V_102 -> V_110 & V_122 )
return V_102 ;
break;
case V_123 :
if ( V_102 -> V_110 & V_124 )
return V_102 ;
break;
case V_125 :
if ( V_102 -> V_126 & V_127 )
return V_102 ;
break;
case V_54 :
return V_2 -> V_4 . V_7 . V_128 ;
case V_99 :
if ( V_102 -> V_110 & V_129 )
return V_102 ;
break;
case V_130 :
if ( V_102 -> V_110 & V_131 )
return V_102 ;
break;
case V_132 :
if ( V_102 -> V_126 & V_133 )
return V_102 ;
break;
case V_107 :
if ( V_102 -> V_110 & V_134 )
return V_102 ;
break;
default:
break;
}
}
switch ( V_98 ) {
case V_119 :
V_98 = V_121 ;
goto V_108;
case V_121 :
case V_123 :
case V_125 :
if ( V_2 -> V_4 . V_7 . V_118 ) {
return V_2 -> V_4 . V_7 . V_118 ;
} else {
V_98 = V_26 ;
goto V_108;
}
case V_99 :
V_98 = V_130 ;
goto V_108;
case V_130 :
V_98 = V_22 ;
goto V_108;
case V_22 :
case V_23 :
case V_107 :
V_98 = V_26 ;
goto V_108;
default:
break;
}
return NULL ;
}
static void F_58 ( struct V_1 * V_2 )
{
int V_50 ;
struct V_101 * V_102 ;
enum V_19 V_98 ;
int V_44 ;
if ( ! V_2 -> V_4 . V_5 )
return;
if ( V_2 -> V_4 . V_7 . V_20 != V_2 -> V_4 . V_7 . V_25 ) {
if ( ( ! V_2 -> V_4 . V_7 . V_47 ) &&
( ! V_2 -> V_4 . V_7 . V_135 ) )
V_2 -> V_4 . V_7 . V_25 = V_2 -> V_4 . V_7 . V_20 ;
}
V_98 = V_2 -> V_4 . V_7 . V_25 ;
V_102 = F_56 ( V_2 , V_98 ) ;
if ( V_102 )
V_2 -> V_4 . V_7 . V_136 = V_102 ;
else
return;
if ( V_2 -> V_4 . V_7 . V_137 == V_2 -> V_4 . V_7 . V_136 ) {
if ( V_102 -> V_138 != V_2 -> V_4 . V_7 . V_138 )
goto V_139;
if ( V_2 -> V_30 & V_140 ) {
if ( V_2 -> V_4 . V_7 . V_141 != V_2 -> V_4 . V_7 . V_142 ) {
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
V_2 -> V_4 . V_7 . V_142 = V_2 -> V_4 . V_7 . V_141 ;
V_2 -> V_4 . V_7 . V_143 = V_2 -> V_4 . V_7 . V_105 ;
}
return;
} else {
if ( V_2 -> V_4 . V_7 . V_141 ==
V_2 -> V_4 . V_7 . V_142 ) {
return;
} else if ( ( V_2 -> V_4 . V_7 . V_143 > 1 ) &&
( V_2 -> V_4 . V_7 . V_105 > 1 ) ) {
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
V_2 -> V_4 . V_7 . V_142 = V_2 -> V_4 . V_7 . V_141 ;
V_2 -> V_4 . V_7 . V_143 = V_2 -> V_4 . V_7 . V_105 ;
return;
}
}
}
V_139:
if ( V_144 == 1 ) {
F_61 ( L_19 ) ;
F_62 ( V_2 , V_2 -> V_4 . V_7 . V_137 ) ;
F_61 ( L_20 ) ;
F_62 ( V_2 , V_2 -> V_4 . V_7 . V_136 ) ;
}
V_102 -> V_138 = V_2 -> V_4 . V_7 . V_138 ;
V_44 = F_63 ( V_2 ) ;
if ( V_44 )
return;
F_59 ( V_2 ) ;
for ( V_50 = 0 ; V_50 < V_145 ; V_50 ++ ) {
struct V_146 * V_147 = V_2 -> V_148 [ V_50 ] ;
if ( V_147 && V_147 -> V_149 )
F_64 ( V_147 ) ;
}
F_65 ( V_2 ) ;
V_2 -> V_4 . V_7 . V_137 = V_2 -> V_4 . V_7 . V_136 ;
F_66 ( V_2 ) ;
F_60 ( V_2 ) ;
V_2 -> V_4 . V_7 . V_142 = V_2 -> V_4 . V_7 . V_141 ;
V_2 -> V_4 . V_7 . V_143 = V_2 -> V_4 . V_7 . V_105 ;
if ( V_2 -> V_4 . V_9 -> V_150 ) {
if ( V_2 -> V_4 . V_7 . V_47 ) {
enum V_40 V_35 = V_2 -> V_4 . V_7 . V_41 ;
F_15 ( V_2 , V_43 ) ;
V_2 -> V_4 . V_7 . V_41 = V_35 ;
} else {
F_15 ( V_2 , V_2 -> V_4 . V_7 . V_41 ) ;
}
}
}
void F_67 ( struct V_1 * V_2 , bool V_151 )
{
if ( V_2 -> V_3 )
F_68 ( V_2 , ! V_151 ) ;
else {
if ( V_2 -> V_4 . V_9 -> V_152 ) {
F_2 ( & V_2 -> V_4 . V_6 ) ;
F_68 ( V_2 , ! V_151 ) ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
} else {
if ( V_151 ) {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_135 = true ;
V_2 -> V_4 . V_7 . V_25 = V_117 ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
} else {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_135 = false ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
}
F_11 ( V_2 ) ;
}
}
}
void F_69 ( struct V_1 * V_2 , bool V_151 )
{
if ( V_2 -> V_3 )
F_70 ( V_2 , ! V_151 ) ;
else {
if ( V_2 -> V_4 . V_9 -> V_153 ) {
F_2 ( & V_2 -> V_4 . V_6 ) ;
F_70 ( V_2 , ! V_151 ) ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
} else {
if ( V_151 ) {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_138 = true ;
V_2 -> V_4 . V_7 . V_154 = V_155 ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
} else {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_138 = false ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
}
F_11 ( V_2 ) ;
}
}
}
void F_71 ( struct V_1 * V_2 )
{
int V_50 ;
if ( V_2 -> V_3 )
return;
for ( V_50 = 0 ; V_50 < V_2 -> V_4 . V_7 . V_109 ; V_50 ++ )
F_62 ( V_2 , & V_2 -> V_4 . V_7 . V_102 [ V_50 ] ) ;
}
int F_72 ( struct V_1 * V_2 )
{
int V_44 ;
if ( V_2 -> V_4 . V_156 )
return 0 ;
if ( ! V_2 -> V_3 ) {
if ( V_2 -> V_4 . V_9 -> V_66 == NULL )
return 0 ;
}
V_2 -> V_4 . V_157 = F_73 ( V_2 -> V_12 ,
V_158 , V_2 ,
V_159 ) ;
if ( F_74 ( V_2 -> V_4 . V_157 ) ) {
V_44 = F_75 ( V_2 -> V_4 . V_157 ) ;
F_76 ( V_2 -> V_12 ,
L_21 , V_44 ) ;
return V_44 ;
}
V_44 = F_77 ( V_2 -> V_12 , & V_160 ) ;
if ( V_44 ) {
F_78 ( L_22 ) ;
return V_44 ;
}
V_44 = F_77 ( V_2 -> V_12 , & V_161 ) ;
if ( V_44 ) {
F_78 ( L_22 ) ;
return V_44 ;
}
if ( V_2 -> V_3 ) {
V_44 = F_77 ( V_2 -> V_12 , & V_162 ) ;
if ( V_44 ) {
F_78 ( L_23 ) ;
return V_44 ;
}
V_44 = F_77 ( V_2 -> V_12 , & V_163 ) ;
if ( V_44 ) {
F_78 ( L_24 ) ;
return V_44 ;
}
V_44 = F_77 ( V_2 -> V_12 , & V_164 ) ;
if ( V_44 ) {
F_78 ( L_25 ) ;
return V_44 ;
}
V_44 = F_77 ( V_2 -> V_12 , & V_165 ) ;
if ( V_44 ) {
F_78 ( L_26 ) ;
return V_44 ;
}
V_44 = F_77 ( V_2 -> V_12 , & V_166 ) ;
if ( V_44 ) {
F_78 ( L_27 ) ;
return V_44 ;
}
V_44 = F_77 ( V_2 -> V_12 , & V_167 ) ;
if ( V_44 ) {
F_78 ( L_28 ) ;
return V_44 ;
}
V_44 = F_77 ( V_2 -> V_12 , & V_168 ) ;
if ( V_44 ) {
F_78 ( L_29 ) ;
return V_44 ;
}
}
V_44 = F_79 ( V_2 ) ;
if ( V_44 ) {
F_78 ( L_30 ) ;
return V_44 ;
}
V_2 -> V_4 . V_156 = true ;
return 0 ;
}
void F_80 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . V_157 )
F_81 ( V_2 -> V_4 . V_157 ) ;
F_82 ( V_2 -> V_12 , & V_160 ) ;
F_82 ( V_2 -> V_12 , & V_161 ) ;
if ( V_2 -> V_3 ) {
F_82 ( V_2 -> V_12 , & V_162 ) ;
F_82 ( V_2 -> V_12 , & V_163 ) ;
F_82 ( V_2 -> V_12 , & V_164 ) ;
F_82 ( V_2 -> V_12 , & V_165 ) ;
F_82 ( V_2 -> V_12 , & V_166 ) ;
F_82 ( V_2 -> V_12 , & V_167 ) ;
F_82 ( V_2 -> V_12 , & V_168 ) ;
}
}
void F_11 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
struct V_169 * V_170 ;
struct V_171 * V_171 ;
if ( ! V_2 -> V_4 . V_5 )
return;
if ( V_2 -> V_3 ) {
int V_50 = 0 ;
F_59 ( V_2 ) ;
for ( V_50 = 0 ; V_50 < V_145 ; V_50 ++ ) {
struct V_146 * V_147 = V_2 -> V_148 [ V_50 ] ;
if ( V_147 && V_147 -> V_149 )
F_64 ( V_147 ) ;
}
F_10 ( V_2 , V_172 , NULL , NULL ) ;
} else {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_141 = 0 ;
V_2 -> V_4 . V_7 . V_105 = 0 ;
if ( V_2 -> V_173 . V_174 && V_2 -> V_173 . V_175 ) {
F_83 (crtc,
&ddev->mode_config.crtc_list, head) {
V_171 = F_84 ( V_170 ) ;
if ( V_170 -> V_176 ) {
V_2 -> V_4 . V_7 . V_141 |= ( 1 << V_171 -> V_177 ) ;
V_2 -> V_4 . V_7 . V_105 ++ ;
}
}
}
if ( F_3 () > 0 )
V_2 -> V_4 . V_7 . V_8 = true ;
else
V_2 -> V_4 . V_7 . V_8 = false ;
F_58 ( V_2 ) ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
}
}
static int F_85 ( struct V_178 * V_179 , void * V_49 )
{
struct V_180 * V_181 = (struct V_180 * ) V_179 -> V_182 ;
struct V_16 * V_12 = V_181 -> V_183 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_18 ;
struct V_16 * V_17 = V_2 -> V_17 ;
if ( ! V_2 -> V_4 . V_5 ) {
F_86 ( V_179 , L_31 ) ;
return 0 ;
}
if ( ( V_2 -> V_30 & V_31 ) &&
( V_17 -> V_32 != V_33 ) ) {
F_86 ( V_179 , L_32 ) ;
} else if ( V_2 -> V_3 ) {
F_87 ( V_2 , V_179 ) ;
} else {
F_2 ( & V_2 -> V_4 . V_6 ) ;
if ( V_2 -> V_4 . V_9 -> V_184 )
F_87 ( V_2 , V_179 ) ;
else
F_86 ( V_179 , L_33 ) ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
#if F_88 ( V_185 )
return F_89 ( V_2 , V_186 , F_22 ( V_186 ) ) ;
#else
return 0 ;
#endif
}
