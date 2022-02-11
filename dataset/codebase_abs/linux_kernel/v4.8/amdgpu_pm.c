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
int V_59 ;
if ( V_2 -> V_3 )
V_59 = F_24 ( V_2 , & V_58 ) ;
else
return 0 ;
if ( V_59 >= V_21 )
V_59 = V_21 - 1 ;
memcpy ( V_15 , V_58 , V_59 ) ;
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
else if ( V_2 -> V_4 . V_9 -> V_61 )
V_59 = V_2 -> V_4 . V_9 -> V_61 ( V_2 , V_60 , V_15 ) ;
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
T_3 V_50 , V_62 = 0 ;
char V_63 [ 2 ] ;
for ( V_50 = 0 ; V_50 < strlen ( V_15 ) ; V_50 ++ ) {
if ( * ( V_15 + V_50 ) == '\n' )
continue;
V_63 [ 0 ] = * ( V_15 + V_50 ) ;
V_63 [ 1 ] = '\0' ;
V_44 = F_30 ( V_63 , 0 , & V_35 ) ;
if ( V_44 ) {
V_24 = - V_27 ;
goto V_28;
}
V_62 |= 1 << V_35 ;
}
if ( V_2 -> V_3 )
F_31 ( V_2 , V_60 , V_62 ) ;
else if ( V_2 -> V_4 . V_9 -> V_64 )
V_2 -> V_4 . V_9 -> V_64 ( V_2 , V_60 , V_62 ) ;
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
V_59 = F_28 ( V_2 , V_65 , V_15 ) ;
else if ( V_2 -> V_4 . V_9 -> V_61 )
V_59 = V_2 -> V_4 . V_9 -> V_61 ( V_2 , V_65 , V_15 ) ;
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
T_3 V_50 , V_62 = 0 ;
char V_63 [ 2 ] ;
for ( V_50 = 0 ; V_50 < strlen ( V_15 ) ; V_50 ++ ) {
if ( * ( V_15 + V_50 ) == '\n' )
continue;
V_63 [ 0 ] = * ( V_15 + V_50 ) ;
V_63 [ 1 ] = '\0' ;
V_44 = F_30 ( V_63 , 0 , & V_35 ) ;
if ( V_44 ) {
V_24 = - V_27 ;
goto V_28;
}
V_62 |= 1 << V_35 ;
}
if ( V_2 -> V_3 )
F_31 ( V_2 , V_65 , V_62 ) ;
else if ( V_2 -> V_4 . V_9 -> V_64 )
V_2 -> V_4 . V_9 -> V_64 ( V_2 , V_65 , V_62 ) ;
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
V_59 = F_28 ( V_2 , V_66 , V_15 ) ;
else if ( V_2 -> V_4 . V_9 -> V_61 )
V_59 = V_2 -> V_4 . V_9 -> V_61 ( V_2 , V_66 , V_15 ) ;
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
T_3 V_50 , V_62 = 0 ;
char V_63 [ 2 ] ;
for ( V_50 = 0 ; V_50 < strlen ( V_15 ) ; V_50 ++ ) {
if ( * ( V_15 + V_50 ) == '\n' )
continue;
V_63 [ 0 ] = * ( V_15 + V_50 ) ;
V_63 [ 1 ] = '\0' ;
V_44 = F_30 ( V_63 , 0 , & V_35 ) ;
if ( V_44 ) {
V_24 = - V_27 ;
goto V_28;
}
V_62 |= 1 << V_35 ;
}
if ( V_2 -> V_3 )
F_31 ( V_2 , V_66 , V_62 ) ;
else if ( V_2 -> V_4 . V_9 -> V_64 )
V_2 -> V_4 . V_9 -> V_64 ( V_2 , V_66 , V_62 ) ;
V_28:
return V_24 ;
}
static T_1 F_36 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
T_3 V_67 = 0 ;
if ( V_2 -> V_3 )
V_67 = F_37 ( V_2 ) ;
else if ( V_2 -> V_4 . V_9 -> V_68 )
V_67 = V_2 -> V_4 . V_9 -> V_68 ( V_2 ) ;
return snprintf ( V_15 , V_21 , L_15 , V_67 ) ;
}
static T_1 F_38 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_44 ;
long int V_67 ;
V_44 = F_30 ( V_15 , 0 , & V_67 ) ;
if ( V_44 ) {
V_24 = - V_27 ;
goto V_28;
}
if ( V_2 -> V_3 ) {
F_39 ( V_2 , ( T_3 ) V_67 ) ;
F_10 ( V_2 , V_69 , NULL , NULL ) ;
} else if ( V_2 -> V_4 . V_9 -> V_70 ) {
V_2 -> V_4 . V_9 -> V_70 ( V_2 , ( T_3 ) V_67 ) ;
V_2 -> V_4 . V_7 . V_71 = V_2 -> V_4 . V_7 . V_72 ;
F_11 ( V_2 ) ;
}
V_28:
return V_24 ;
}
static T_1 F_40 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
T_3 V_67 = 0 ;
if ( V_2 -> V_3 )
V_67 = F_41 ( V_2 ) ;
else if ( V_2 -> V_4 . V_9 -> V_73 )
V_67 = V_2 -> V_4 . V_9 -> V_73 ( V_2 ) ;
return snprintf ( V_15 , V_21 , L_15 , V_67 ) ;
}
static T_1 F_42 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_44 ;
long int V_67 ;
V_44 = F_30 ( V_15 , 0 , & V_67 ) ;
if ( V_44 ) {
V_24 = - V_27 ;
goto V_28;
}
if ( V_2 -> V_3 ) {
F_43 ( V_2 , ( T_3 ) V_67 ) ;
F_10 ( V_2 , V_69 , NULL , NULL ) ;
} else if ( V_2 -> V_4 . V_9 -> V_74 ) {
V_2 -> V_4 . V_9 -> V_74 ( V_2 , ( T_3 ) V_67 ) ;
V_2 -> V_4 . V_7 . V_71 = V_2 -> V_4 . V_7 . V_72 ;
F_11 ( V_2 ) ;
}
V_28:
return V_24 ;
}
static T_1 F_44 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
struct V_16 * V_17 = V_2 -> V_17 ;
int V_75 ;
if ( ( V_2 -> V_30 & V_31 ) &&
( V_17 -> V_32 != V_33 ) )
return - V_27 ;
if ( ! V_2 -> V_3 && ! V_2 -> V_4 . V_9 -> V_76 )
V_75 = 0 ;
else
V_75 = F_45 ( V_2 ) ;
return snprintf ( V_15 , V_21 , L_15 , V_75 ) ;
}
static T_1 F_46 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_77 = F_47 ( V_14 ) -> V_78 ;
int V_75 ;
if ( V_77 )
V_75 = V_2 -> V_4 . V_7 . V_79 . V_80 ;
else
V_75 = V_2 -> V_4 . V_7 . V_79 . V_81 ;
return snprintf ( V_15 , V_21 , L_15 , V_75 ) ;
}
static T_1 F_48 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_4 V_82 = 0 ;
if ( ! V_2 -> V_3 && ! V_2 -> V_4 . V_9 -> V_83 )
return - V_27 ;
V_82 = F_49 ( V_2 ) ;
return sprintf ( V_15 , L_17 , V_82 == V_84 ? 1 : 2 ) ;
}
static T_1 F_50 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_85 ;
int V_67 ;
if ( ! V_2 -> V_3 && ! V_2 -> V_4 . V_9 -> V_86 )
return - V_27 ;
V_85 = F_51 ( V_15 , 10 , & V_67 ) ;
if ( V_85 )
return V_85 ;
switch ( V_67 ) {
case 1 :
F_52 ( V_2 , V_84 ) ;
break;
default:
F_52 ( V_2 , 0 ) ;
break;
}
return V_24 ;
}
static T_1 F_53 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
return sprintf ( V_15 , L_17 , 0 ) ;
}
static T_1 F_54 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
return sprintf ( V_15 , L_17 , 255 ) ;
}
static T_1 F_55 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 , T_2 V_24 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_85 ;
T_4 V_67 ;
V_85 = F_56 ( V_15 , 10 , & V_67 ) ;
if ( V_85 )
return V_85 ;
V_67 = ( V_67 * 100 ) / 255 ;
V_85 = F_57 ( V_2 , V_67 ) ;
if ( V_85 )
return V_85 ;
return V_24 ;
}
static T_1 F_58 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_85 ;
T_4 V_87 ;
V_85 = F_59 ( V_2 , & V_87 ) ;
if ( V_85 )
return V_85 ;
V_87 = ( V_87 * 255 ) / 100 ;
return sprintf ( V_15 , L_17 , V_87 ) ;
}
static T_5 F_60 ( struct V_88 * V_89 ,
struct V_90 * V_14 , int V_78 )
{
struct V_11 * V_12 = F_61 ( V_89 ) ;
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_5 V_91 = V_14 -> V_92 ;
if ( ! V_2 -> V_4 . V_5 &&
( V_14 == & V_93 . V_94 . V_14 ||
V_14 == & V_95 . V_94 . V_14 ||
V_14 == & V_96 . V_94 . V_14 ||
V_14 == & V_97 . V_94 . V_14 ||
V_14 == & V_98 . V_94 . V_14 ||
V_14 == & V_99 . V_94 . V_14 ) )
return 0 ;
if ( V_2 -> V_3 )
return V_91 ;
if ( V_2 -> V_4 . V_100 &&
( V_14 == & V_96 . V_94 . V_14 ||
V_14 == & V_97 . V_94 . V_14 ||
V_14 == & V_98 . V_94 . V_14 ||
V_14 == & V_99 . V_94 . V_14 ) )
return 0 ;
if ( ( ! V_2 -> V_4 . V_9 -> V_101 &&
V_14 == & V_96 . V_94 . V_14 ) ||
( ! V_2 -> V_4 . V_9 -> V_83 &&
V_14 == & V_97 . V_94 . V_14 ) )
V_91 &= ~ V_102 ;
if ( ( ! V_2 -> V_4 . V_9 -> V_103 &&
V_14 == & V_96 . V_94 . V_14 ) ||
( ! V_2 -> V_4 . V_9 -> V_86 &&
V_14 == & V_97 . V_94 . V_14 ) )
V_91 &= ~ V_104 ;
if ( ( ! V_2 -> V_4 . V_9 -> V_103 &&
! V_2 -> V_4 . V_9 -> V_101 ) &&
( V_14 == & V_98 . V_94 . V_14 ||
V_14 == & V_99 . V_94 . V_14 ) )
return 0 ;
return V_91 ;
}
void F_62 ( struct V_105 * V_106 )
{
struct V_1 * V_2 =
F_63 ( V_106 , struct V_1 ,
V_4 . V_7 . V_79 . V_106 ) ;
enum V_19 V_107 = V_108 ;
if ( ! V_2 -> V_4 . V_5 )
return;
if ( V_2 -> V_4 . V_9 -> V_76 ) {
int V_75 = F_45 ( V_2 ) ;
if ( V_75 < V_2 -> V_4 . V_7 . V_79 . V_80 )
V_107 = V_2 -> V_4 . V_7 . V_20 ;
} else {
if ( V_2 -> V_4 . V_7 . V_79 . V_109 )
V_107 = V_2 -> V_4 . V_7 . V_20 ;
}
F_2 ( & V_2 -> V_4 . V_6 ) ;
if ( V_107 == V_108 )
V_2 -> V_4 . V_7 . V_47 = true ;
else
V_2 -> V_4 . V_7 . V_47 = false ;
V_2 -> V_4 . V_7 . V_25 = V_107 ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
F_11 ( V_2 ) ;
}
static struct V_110 * F_64 ( struct V_1 * V_2 ,
enum V_19 V_107 )
{
int V_50 ;
struct V_110 * V_111 ;
T_4 V_112 ;
bool V_113 = ( V_2 -> V_4 . V_7 . V_114 < 2 ) ?
true : false ;
if ( V_113 && V_2 -> V_4 . V_9 -> V_115 ) {
if ( F_65 ( V_2 ) )
V_113 = false ;
}
if ( V_107 == V_26 )
V_107 = V_116 ;
if ( V_107 == V_23 )
V_107 = V_26 ;
V_117:
for ( V_50 = 0 ; V_50 < V_2 -> V_4 . V_7 . V_118 ; V_50 ++ ) {
V_111 = & V_2 -> V_4 . V_7 . V_111 [ V_50 ] ;
V_112 = V_111 -> V_119 & V_120 ;
switch ( V_107 ) {
case V_22 :
if ( V_112 == V_121 ) {
if ( V_111 -> V_122 & V_123 ) {
if ( V_113 )
return V_111 ;
} else
return V_111 ;
}
break;
case V_23 :
if ( V_112 == V_124 ) {
if ( V_111 -> V_122 & V_123 ) {
if ( V_113 )
return V_111 ;
} else
return V_111 ;
}
break;
case V_26 :
if ( V_112 == V_125 ) {
if ( V_111 -> V_122 & V_123 ) {
if ( V_113 )
return V_111 ;
} else
return V_111 ;
}
break;
case V_126 :
if ( V_2 -> V_4 . V_7 . V_127 )
return V_2 -> V_4 . V_7 . V_127 ;
else
break;
case V_128 :
if ( V_111 -> V_119 & V_129 )
return V_111 ;
break;
case V_130 :
if ( V_111 -> V_119 & V_131 )
return V_111 ;
break;
case V_132 :
if ( V_111 -> V_119 & V_133 )
return V_111 ;
break;
case V_134 :
if ( V_111 -> V_135 & V_136 )
return V_111 ;
break;
case V_54 :
return V_2 -> V_4 . V_7 . V_72 ;
case V_108 :
if ( V_111 -> V_119 & V_137 )
return V_111 ;
break;
case V_138 :
if ( V_111 -> V_119 & V_139 )
return V_111 ;
break;
case V_140 :
if ( V_111 -> V_135 & V_141 )
return V_111 ;
break;
case V_116 :
if ( V_111 -> V_119 & V_142 )
return V_111 ;
break;
default:
break;
}
}
switch ( V_107 ) {
case V_128 :
V_107 = V_130 ;
goto V_117;
case V_130 :
case V_132 :
case V_134 :
if ( V_2 -> V_4 . V_7 . V_127 ) {
return V_2 -> V_4 . V_7 . V_127 ;
} else {
V_107 = V_26 ;
goto V_117;
}
case V_108 :
V_107 = V_138 ;
goto V_117;
case V_138 :
V_107 = V_22 ;
goto V_117;
case V_22 :
case V_23 :
case V_116 :
V_107 = V_26 ;
goto V_117;
default:
break;
}
return NULL ;
}
static void F_66 ( struct V_1 * V_2 )
{
int V_50 ;
struct V_110 * V_111 ;
enum V_19 V_107 ;
int V_44 ;
if ( ! V_2 -> V_4 . V_5 )
return;
if ( V_2 -> V_4 . V_7 . V_20 != V_2 -> V_4 . V_7 . V_25 ) {
if ( ( ! V_2 -> V_4 . V_7 . V_47 ) &&
( ! V_2 -> V_4 . V_7 . V_143 ) )
V_2 -> V_4 . V_7 . V_25 = V_2 -> V_4 . V_7 . V_20 ;
}
V_107 = V_2 -> V_4 . V_7 . V_25 ;
V_111 = F_64 ( V_2 , V_107 ) ;
if ( V_111 )
V_2 -> V_4 . V_7 . V_144 = V_111 ;
else
return;
if ( V_2 -> V_4 . V_7 . V_71 == V_2 -> V_4 . V_7 . V_144 ) {
if ( V_111 -> V_145 != V_2 -> V_4 . V_7 . V_145 )
goto V_146;
if ( V_2 -> V_30 & V_147 ) {
if ( V_2 -> V_4 . V_7 . V_148 != V_2 -> V_4 . V_7 . V_149 ) {
F_67 ( V_2 ) ;
F_68 ( V_2 ) ;
V_2 -> V_4 . V_7 . V_149 = V_2 -> V_4 . V_7 . V_148 ;
V_2 -> V_4 . V_7 . V_150 = V_2 -> V_4 . V_7 . V_114 ;
}
return;
} else {
if ( V_2 -> V_4 . V_7 . V_148 ==
V_2 -> V_4 . V_7 . V_149 ) {
return;
} else if ( ( V_2 -> V_4 . V_7 . V_150 > 1 ) &&
( V_2 -> V_4 . V_7 . V_114 > 1 ) ) {
F_67 ( V_2 ) ;
F_68 ( V_2 ) ;
V_2 -> V_4 . V_7 . V_149 = V_2 -> V_4 . V_7 . V_148 ;
V_2 -> V_4 . V_7 . V_150 = V_2 -> V_4 . V_7 . V_114 ;
return;
}
}
}
V_146:
if ( V_151 == 1 ) {
F_69 ( L_18 ) ;
F_70 ( V_2 , V_2 -> V_4 . V_7 . V_71 ) ;
F_69 ( L_19 ) ;
F_70 ( V_2 , V_2 -> V_4 . V_7 . V_144 ) ;
}
V_111 -> V_145 = V_2 -> V_4 . V_7 . V_145 ;
V_44 = F_71 ( V_2 ) ;
if ( V_44 )
return;
F_67 ( V_2 ) ;
for ( V_50 = 0 ; V_50 < V_152 ; V_50 ++ ) {
struct V_153 * V_154 = V_2 -> V_155 [ V_50 ] ;
if ( V_154 && V_154 -> V_156 )
F_72 ( V_154 ) ;
}
F_73 ( V_2 ) ;
V_2 -> V_4 . V_7 . V_71 = V_2 -> V_4 . V_7 . V_144 ;
F_74 ( V_2 ) ;
F_68 ( V_2 ) ;
V_2 -> V_4 . V_7 . V_149 = V_2 -> V_4 . V_7 . V_148 ;
V_2 -> V_4 . V_7 . V_150 = V_2 -> V_4 . V_7 . V_114 ;
if ( V_2 -> V_4 . V_9 -> V_157 ) {
if ( V_2 -> V_4 . V_7 . V_47 ) {
enum V_40 V_35 = V_2 -> V_4 . V_7 . V_41 ;
F_15 ( V_2 , V_43 ) ;
V_2 -> V_4 . V_7 . V_41 = V_35 ;
} else {
F_15 ( V_2 , V_2 -> V_4 . V_7 . V_41 ) ;
}
}
}
void F_75 ( struct V_1 * V_2 , bool V_158 )
{
if ( V_2 -> V_3 )
F_76 ( V_2 , ! V_158 ) ;
else {
if ( V_2 -> V_4 . V_9 -> V_159 ) {
F_2 ( & V_2 -> V_4 . V_6 ) ;
F_76 ( V_2 , ! V_158 ) ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
} else {
if ( V_158 ) {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_143 = true ;
V_2 -> V_4 . V_7 . V_25 = V_126 ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
} else {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_143 = false ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
}
F_11 ( V_2 ) ;
}
}
}
void F_77 ( struct V_1 * V_2 , bool V_158 )
{
if ( V_2 -> V_3 )
F_78 ( V_2 , ! V_158 ) ;
else {
if ( V_2 -> V_4 . V_9 -> V_160 ) {
F_2 ( & V_2 -> V_4 . V_6 ) ;
F_78 ( V_2 , ! V_158 ) ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
} else {
if ( V_158 ) {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_145 = true ;
V_2 -> V_4 . V_7 . V_161 = V_162 ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
} else {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_145 = false ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
}
F_11 ( V_2 ) ;
}
}
}
void F_79 ( struct V_1 * V_2 )
{
int V_50 ;
if ( V_2 -> V_3 )
return;
for ( V_50 = 0 ; V_50 < V_2 -> V_4 . V_7 . V_118 ; V_50 ++ )
F_70 ( V_2 , & V_2 -> V_4 . V_7 . V_111 [ V_50 ] ) ;
}
int F_80 ( struct V_1 * V_2 )
{
int V_44 ;
if ( V_2 -> V_4 . V_163 )
return 0 ;
if ( ! V_2 -> V_3 ) {
if ( V_2 -> V_4 . V_9 -> V_76 == NULL )
return 0 ;
}
V_2 -> V_4 . V_164 = F_81 ( V_2 -> V_12 ,
V_165 , V_2 ,
V_166 ) ;
if ( F_82 ( V_2 -> V_4 . V_164 ) ) {
V_44 = F_83 ( V_2 -> V_4 . V_164 ) ;
F_84 ( V_2 -> V_12 ,
L_20 , V_44 ) ;
return V_44 ;
}
V_44 = F_85 ( V_2 -> V_12 , & V_167 ) ;
if ( V_44 ) {
F_86 ( L_21 ) ;
return V_44 ;
}
V_44 = F_85 ( V_2 -> V_12 , & V_168 ) ;
if ( V_44 ) {
F_86 ( L_21 ) ;
return V_44 ;
}
if ( V_2 -> V_3 ) {
V_44 = F_85 ( V_2 -> V_12 , & V_169 ) ;
if ( V_44 ) {
F_86 ( L_22 ) ;
return V_44 ;
}
V_44 = F_85 ( V_2 -> V_12 , & V_170 ) ;
if ( V_44 ) {
F_86 ( L_23 ) ;
return V_44 ;
}
V_44 = F_85 ( V_2 -> V_12 , & V_171 ) ;
if ( V_44 ) {
F_86 ( L_24 ) ;
return V_44 ;
}
V_44 = F_85 ( V_2 -> V_12 , & V_172 ) ;
if ( V_44 ) {
F_86 ( L_25 ) ;
return V_44 ;
}
}
V_44 = F_85 ( V_2 -> V_12 , & V_173 ) ;
if ( V_44 ) {
F_86 ( L_26 ) ;
return V_44 ;
}
V_44 = F_85 ( V_2 -> V_12 , & V_174 ) ;
if ( V_44 ) {
F_86 ( L_27 ) ;
return V_44 ;
}
V_44 = F_85 ( V_2 -> V_12 , & V_175 ) ;
if ( V_44 ) {
F_86 ( L_28 ) ;
return V_44 ;
}
V_44 = F_85 ( V_2 -> V_12 , & V_176 ) ;
if ( V_44 ) {
F_86 ( L_29 ) ;
return V_44 ;
}
V_44 = F_85 ( V_2 -> V_12 , & V_177 ) ;
if ( V_44 ) {
F_86 ( L_30 ) ;
return V_44 ;
}
V_44 = F_87 ( V_2 ) ;
if ( V_44 ) {
F_86 ( L_31 ) ;
return V_44 ;
}
V_2 -> V_4 . V_163 = true ;
return 0 ;
}
void F_88 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . V_164 )
F_89 ( V_2 -> V_4 . V_164 ) ;
F_90 ( V_2 -> V_12 , & V_167 ) ;
F_90 ( V_2 -> V_12 , & V_168 ) ;
if ( V_2 -> V_3 ) {
F_90 ( V_2 -> V_12 , & V_169 ) ;
F_90 ( V_2 -> V_12 , & V_170 ) ;
F_90 ( V_2 -> V_12 , & V_171 ) ;
F_90 ( V_2 -> V_12 , & V_172 ) ;
}
F_90 ( V_2 -> V_12 , & V_173 ) ;
F_90 ( V_2 -> V_12 , & V_174 ) ;
F_90 ( V_2 -> V_12 , & V_175 ) ;
F_90 ( V_2 -> V_12 , & V_176 ) ;
F_90 ( V_2 -> V_12 , & V_177 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
struct V_178 * V_179 ;
struct V_180 * V_180 ;
if ( ! V_2 -> V_4 . V_5 )
return;
if ( V_2 -> V_3 ) {
int V_50 = 0 ;
F_67 ( V_2 ) ;
for ( V_50 = 0 ; V_50 < V_152 ; V_50 ++ ) {
struct V_153 * V_154 = V_2 -> V_155 [ V_50 ] ;
if ( V_154 && V_154 -> V_156 )
F_72 ( V_154 ) ;
}
F_10 ( V_2 , V_181 , NULL , NULL ) ;
} else {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_148 = 0 ;
V_2 -> V_4 . V_7 . V_114 = 0 ;
if ( V_2 -> V_182 . V_183 && V_2 -> V_182 . V_184 ) {
F_91 (crtc,
&ddev->mode_config.crtc_list, head) {
V_180 = F_92 ( V_179 ) ;
if ( V_179 -> V_185 ) {
V_2 -> V_4 . V_7 . V_148 |= ( 1 << V_180 -> V_186 ) ;
V_2 -> V_4 . V_7 . V_114 ++ ;
}
}
}
if ( F_3 () > 0 )
V_2 -> V_4 . V_7 . V_8 = true ;
else
V_2 -> V_4 . V_7 . V_8 = false ;
F_66 ( V_2 ) ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
}
}
static int F_93 ( struct V_187 * V_188 , void * V_49 )
{
struct V_189 * V_190 = (struct V_189 * ) V_188 -> V_191 ;
struct V_16 * V_12 = V_190 -> V_192 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_18 ;
struct V_16 * V_17 = V_2 -> V_17 ;
if ( ! V_2 -> V_4 . V_5 ) {
F_94 ( V_188 , L_32 ) ;
return 0 ;
}
if ( ( V_2 -> V_30 & V_31 ) &&
( V_17 -> V_32 != V_33 ) ) {
F_94 ( V_188 , L_33 ) ;
} else if ( V_2 -> V_3 ) {
F_95 ( V_2 , V_188 ) ;
} else {
F_2 ( & V_2 -> V_4 . V_6 ) ;
if ( V_2 -> V_4 . V_9 -> V_193 )
F_95 ( V_2 , V_188 ) ;
else
F_94 ( V_188 , L_34 ) ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
}
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
#if F_96 ( V_194 )
return F_97 ( V_2 , V_195 , F_22 ( V_195 ) ) ;
#else
return 0 ;
#endif
}
