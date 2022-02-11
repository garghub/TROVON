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
enum V_34 V_35 ;
if ( ( V_2 -> V_30 & V_31 ) &&
( V_17 -> V_32 != V_33 ) )
return snprintf ( V_15 , V_21 , L_5 ) ;
V_35 = F_13 ( V_2 ) ;
return snprintf ( V_15 , V_21 , L_1 ,
( V_35 == V_36 ) ? L_6 :
( V_35 == V_37 ) ? L_7 :
( V_35 == V_38 ) ? L_8 :
( V_35 == V_39 ) ? L_9 :
( V_35 == V_40 ) ? L_10 :
( V_35 == V_41 ) ? L_11 :
( V_35 == V_42 ) ? L_12 :
( V_35 == V_43 ) ? L_13 :
L_14 ) ;
}
static T_1 F_14 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
enum V_34 V_35 ;
enum V_34 V_44 ;
int V_45 = 0 ;
if ( ( V_2 -> V_30 & V_31 ) &&
( V_17 -> V_32 != V_33 ) )
return - V_27 ;
V_44 = F_13 ( V_2 ) ;
if ( strncmp ( L_7 , V_15 , strlen ( L_7 ) ) == 0 ) {
V_35 = V_37 ;
} else if ( strncmp ( L_8 , V_15 , strlen ( L_8 ) ) == 0 ) {
V_35 = V_38 ;
} else if ( strncmp ( L_6 , V_15 , strlen ( L_6 ) ) == 0 ) {
V_35 = V_36 ;
} else if ( strncmp ( L_9 , V_15 , strlen ( L_9 ) ) == 0 ) {
V_35 = V_39 ;
} else if ( strncmp ( L_15 , V_15 , strlen ( L_15 ) ) == 0 ) {
V_35 = V_46 ;
} else if ( strncmp ( L_10 , V_15 , strlen ( L_10 ) ) == 0 ) {
V_35 = V_40 ;
} else if ( strncmp ( L_11 , V_15 , strlen ( L_11 ) ) == 0 ) {
V_35 = V_41 ;
} else if ( strncmp ( L_12 , V_15 , strlen ( L_12 ) ) == 0 ) {
V_35 = V_42 ;
} else if ( strncmp ( L_13 , V_15 , strlen ( L_13 ) ) == 0 ) {
V_35 = V_43 ;
} else {
V_24 = - V_27 ;
goto V_28;
}
if ( V_44 == V_35 )
return V_24 ;
if ( V_2 -> V_3 )
F_15 ( V_2 , V_35 ) ;
else {
F_2 ( & V_2 -> V_4 . V_6 ) ;
if ( V_2 -> V_4 . V_7 . V_47 ) {
V_24 = - V_27 ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
goto V_28;
}
V_45 = F_15 ( V_2 , V_35 ) ;
if ( V_45 )
V_24 = - V_27 ;
else
V_2 -> V_4 . V_7 . V_48 = V_35 ;
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
struct V_49 V_50 ;
int V_51 , V_52 ;
if ( V_2 -> V_3 )
F_17 ( V_2 , & V_50 ) ;
V_52 = snprintf ( V_15 , V_21 , L_16 , V_50 . V_53 ) ;
for ( V_51 = 0 ; V_51 < V_50 . V_53 ; V_51 ++ )
V_52 += snprintf ( V_15 + V_52 , V_21 , L_17 , V_51 ,
( V_50 . V_54 [ V_51 ] == V_55 ) ? L_18 :
( V_50 . V_54 [ V_51 ] == V_22 ) ? L_2 :
( V_50 . V_54 [ V_51 ] == V_23 ) ? L_3 :
( V_50 . V_54 [ V_51 ] == V_26 ) ? L_4 : L_19 ) ;
return V_52 ;
}
static T_1 F_18 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_49 V_50 ;
enum V_19 V_4 = 0 ;
int V_51 = 0 ;
if ( V_2 -> V_3 ) {
V_4 = F_8 ( V_2 ) ;
F_17 ( V_2 , & V_50 ) ;
for ( V_51 = 0 ; V_51 < V_50 . V_53 ; V_51 ++ ) {
if ( V_4 == V_50 . V_54 [ V_51 ] )
break;
}
if ( V_51 == V_50 . V_53 )
V_51 = - V_27 ;
}
return snprintf ( V_15 , V_21 , L_20 , V_51 ) ;
}
static T_1 F_19 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_49 V_50 ;
enum V_19 V_4 = 0 ;
int V_51 ;
if ( V_2 -> V_56 && V_2 -> V_3 ) {
V_4 = F_8 ( V_2 ) ;
F_17 ( V_2 , & V_50 ) ;
for ( V_51 = 0 ; V_51 < V_50 . V_53 ; V_51 ++ ) {
if ( V_4 == V_50 . V_54 [ V_51 ] )
break;
}
if ( V_51 == V_50 . V_53 )
V_51 = - V_27 ;
return snprintf ( V_15 , V_21 , L_20 , V_51 ) ;
} else
return snprintf ( V_15 , V_21 , L_21 ) ;
}
static T_1 F_20 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
enum V_19 V_25 = 0 ;
unsigned long V_57 ;
int V_45 ;
if ( strlen ( V_15 ) == 1 )
V_2 -> V_56 = false ;
else if ( V_2 -> V_3 ) {
struct V_49 V_50 ;
V_45 = F_21 ( V_15 , 0 , & V_57 ) ;
if ( V_45 || V_57 >= F_22 ( V_50 . V_54 ) ) {
V_24 = - V_27 ;
goto V_28;
}
F_17 ( V_2 , & V_50 ) ;
V_25 = V_50 . V_54 [ V_57 ] ;
if ( V_25 != V_55 &&
V_25 != V_58 ) {
F_10 ( V_2 ,
V_29 , & V_25 , NULL ) ;
V_2 -> V_56 = true ;
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
char * V_59 = NULL ;
int V_60 ;
if ( V_2 -> V_3 )
V_60 = F_24 ( V_2 , & V_59 ) ;
else
return 0 ;
if ( V_60 >= V_21 )
V_60 = V_21 - 1 ;
memcpy ( V_15 , V_59 , V_60 ) ;
return V_60 ;
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
T_1 V_60 = 0 ;
if ( V_2 -> V_3 )
V_60 = F_28 ( V_2 , V_61 , V_15 ) ;
else if ( V_2 -> V_4 . V_9 -> V_62 )
V_60 = V_2 -> V_4 . V_9 -> V_62 ( V_2 , V_61 , V_15 ) ;
return V_60 ;
}
static T_1 F_29 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_45 ;
long V_35 ;
T_3 V_51 , V_63 = 0 ;
char V_64 [ 2 ] ;
for ( V_51 = 0 ; V_51 < strlen ( V_15 ) ; V_51 ++ ) {
if ( * ( V_15 + V_51 ) == '\n' )
continue;
V_64 [ 0 ] = * ( V_15 + V_51 ) ;
V_64 [ 1 ] = '\0' ;
V_45 = F_30 ( V_64 , 0 , & V_35 ) ;
if ( V_45 ) {
V_24 = - V_27 ;
goto V_28;
}
V_63 |= 1 << V_35 ;
}
if ( V_2 -> V_3 )
F_31 ( V_2 , V_61 , V_63 ) ;
else if ( V_2 -> V_4 . V_9 -> V_65 )
V_2 -> V_4 . V_9 -> V_65 ( V_2 , V_61 , V_63 ) ;
V_28:
return V_24 ;
}
static T_1 F_32 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
T_1 V_60 = 0 ;
if ( V_2 -> V_3 )
V_60 = F_28 ( V_2 , V_66 , V_15 ) ;
else if ( V_2 -> V_4 . V_9 -> V_62 )
V_60 = V_2 -> V_4 . V_9 -> V_62 ( V_2 , V_66 , V_15 ) ;
return V_60 ;
}
static T_1 F_33 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_45 ;
long V_35 ;
T_3 V_51 , V_63 = 0 ;
char V_64 [ 2 ] ;
for ( V_51 = 0 ; V_51 < strlen ( V_15 ) ; V_51 ++ ) {
if ( * ( V_15 + V_51 ) == '\n' )
continue;
V_64 [ 0 ] = * ( V_15 + V_51 ) ;
V_64 [ 1 ] = '\0' ;
V_45 = F_30 ( V_64 , 0 , & V_35 ) ;
if ( V_45 ) {
V_24 = - V_27 ;
goto V_28;
}
V_63 |= 1 << V_35 ;
}
if ( V_2 -> V_3 )
F_31 ( V_2 , V_66 , V_63 ) ;
else if ( V_2 -> V_4 . V_9 -> V_65 )
V_2 -> V_4 . V_9 -> V_65 ( V_2 , V_66 , V_63 ) ;
V_28:
return V_24 ;
}
static T_1 F_34 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
T_1 V_60 = 0 ;
if ( V_2 -> V_3 )
V_60 = F_28 ( V_2 , V_67 , V_15 ) ;
else if ( V_2 -> V_4 . V_9 -> V_62 )
V_60 = V_2 -> V_4 . V_9 -> V_62 ( V_2 , V_67 , V_15 ) ;
return V_60 ;
}
static T_1 F_35 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_45 ;
long V_35 ;
T_3 V_51 , V_63 = 0 ;
char V_64 [ 2 ] ;
for ( V_51 = 0 ; V_51 < strlen ( V_15 ) ; V_51 ++ ) {
if ( * ( V_15 + V_51 ) == '\n' )
continue;
V_64 [ 0 ] = * ( V_15 + V_51 ) ;
V_64 [ 1 ] = '\0' ;
V_45 = F_30 ( V_64 , 0 , & V_35 ) ;
if ( V_45 ) {
V_24 = - V_27 ;
goto V_28;
}
V_63 |= 1 << V_35 ;
}
if ( V_2 -> V_3 )
F_31 ( V_2 , V_67 , V_63 ) ;
else if ( V_2 -> V_4 . V_9 -> V_65 )
V_2 -> V_4 . V_9 -> V_65 ( V_2 , V_67 , V_63 ) ;
V_28:
return V_24 ;
}
static T_1 F_36 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
T_3 V_68 = 0 ;
if ( V_2 -> V_3 )
V_68 = F_37 ( V_2 ) ;
else if ( V_2 -> V_4 . V_9 -> V_69 )
V_68 = V_2 -> V_4 . V_9 -> V_69 ( V_2 ) ;
return snprintf ( V_15 , V_21 , L_20 , V_68 ) ;
}
static T_1 F_38 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_45 ;
long int V_68 ;
V_45 = F_30 ( V_15 , 0 , & V_68 ) ;
if ( V_45 ) {
V_24 = - V_27 ;
goto V_28;
}
if ( V_2 -> V_3 ) {
F_39 ( V_2 , ( T_3 ) V_68 ) ;
F_10 ( V_2 , V_70 , NULL , NULL ) ;
} else if ( V_2 -> V_4 . V_9 -> V_71 ) {
V_2 -> V_4 . V_9 -> V_71 ( V_2 , ( T_3 ) V_68 ) ;
V_2 -> V_4 . V_7 . V_72 = V_2 -> V_4 . V_7 . V_73 ;
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
T_3 V_68 = 0 ;
if ( V_2 -> V_3 )
V_68 = F_41 ( V_2 ) ;
else if ( V_2 -> V_4 . V_9 -> V_74 )
V_68 = V_2 -> V_4 . V_9 -> V_74 ( V_2 ) ;
return snprintf ( V_15 , V_21 , L_20 , V_68 ) ;
}
static T_1 F_42 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_16 * V_17 = F_7 ( V_12 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_45 ;
long int V_68 ;
V_45 = F_30 ( V_15 , 0 , & V_68 ) ;
if ( V_45 ) {
V_24 = - V_27 ;
goto V_28;
}
if ( V_2 -> V_3 ) {
F_43 ( V_2 , ( T_3 ) V_68 ) ;
F_10 ( V_2 , V_70 , NULL , NULL ) ;
} else if ( V_2 -> V_4 . V_9 -> V_75 ) {
V_2 -> V_4 . V_9 -> V_75 ( V_2 , ( T_3 ) V_68 ) ;
V_2 -> V_4 . V_7 . V_72 = V_2 -> V_4 . V_7 . V_73 ;
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
int V_76 ;
if ( ( V_2 -> V_30 & V_31 ) &&
( V_17 -> V_32 != V_33 ) )
return - V_27 ;
if ( ! V_2 -> V_3 && ! V_2 -> V_4 . V_9 -> V_77 )
V_76 = 0 ;
else
V_76 = F_45 ( V_2 ) ;
return snprintf ( V_15 , V_21 , L_20 , V_76 ) ;
}
static T_1 F_46 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_78 = F_47 ( V_14 ) -> V_79 ;
int V_76 ;
if ( V_78 )
V_76 = V_2 -> V_4 . V_7 . V_80 . V_81 ;
else
V_76 = V_2 -> V_4 . V_7 . V_80 . V_82 ;
return snprintf ( V_15 , V_21 , L_20 , V_76 ) ;
}
static T_1 F_48 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_4 V_83 = 0 ;
if ( ! V_2 -> V_3 && ! V_2 -> V_4 . V_9 -> V_84 )
return - V_27 ;
V_83 = F_49 ( V_2 ) ;
return sprintf ( V_15 , L_22 , V_83 == V_85 ? 1 : 2 ) ;
}
static T_1 F_50 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_24 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_86 ;
int V_68 ;
if ( ! V_2 -> V_3 && ! V_2 -> V_4 . V_9 -> V_87 )
return - V_27 ;
V_86 = F_51 ( V_15 , 10 , & V_68 ) ;
if ( V_86 )
return V_86 ;
switch ( V_68 ) {
case 1 :
F_52 ( V_2 , V_85 ) ;
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
return sprintf ( V_15 , L_22 , 0 ) ;
}
static T_1 F_54 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
return sprintf ( V_15 , L_22 , 255 ) ;
}
static T_1 F_55 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 , T_2 V_24 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_86 ;
T_4 V_68 ;
V_86 = F_56 ( V_15 , 10 , & V_68 ) ;
if ( V_86 )
return V_86 ;
V_68 = ( V_68 * 100 ) / 255 ;
V_86 = F_57 ( V_2 , V_68 ) ;
if ( V_86 )
return V_86 ;
return V_24 ;
}
static T_1 F_58 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_86 ;
T_4 V_88 ;
V_86 = F_59 ( V_2 , & V_88 ) ;
if ( V_86 )
return V_86 ;
V_88 = ( V_88 * 255 ) / 100 ;
return sprintf ( V_15 , L_22 , V_88 ) ;
}
static T_1 F_60 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_86 ;
T_4 V_88 ;
V_86 = F_61 ( V_2 , & V_88 ) ;
if ( V_86 )
return V_86 ;
return sprintf ( V_15 , L_22 , V_88 ) ;
}
static T_5 F_62 ( struct V_89 * V_90 ,
struct V_91 * V_14 , int V_79 )
{
struct V_11 * V_12 = F_63 ( V_90 ) ;
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_5 V_92 = V_14 -> V_93 ;
if ( ! V_2 -> V_4 . V_5 &&
( V_14 == & V_94 . V_95 . V_14 ||
V_14 == & V_96 . V_95 . V_14 ||
V_14 == & V_97 . V_95 . V_14 ||
V_14 == & V_98 . V_95 . V_14 ||
V_14 == & V_99 . V_95 . V_14 ||
V_14 == & V_100 . V_95 . V_14 ) )
return 0 ;
if ( V_2 -> V_3 )
return V_92 ;
if ( V_2 -> V_4 . V_101 &&
( V_14 == & V_97 . V_95 . V_14 ||
V_14 == & V_98 . V_95 . V_14 ||
V_14 == & V_99 . V_95 . V_14 ||
V_14 == & V_100 . V_95 . V_14 ) )
return 0 ;
if ( ( ! V_2 -> V_4 . V_9 -> V_102 &&
V_14 == & V_97 . V_95 . V_14 ) ||
( ! V_2 -> V_4 . V_9 -> V_84 &&
V_14 == & V_98 . V_95 . V_14 ) )
V_92 &= ~ V_103 ;
if ( ( ! V_2 -> V_4 . V_9 -> V_104 &&
V_14 == & V_97 . V_95 . V_14 ) ||
( ! V_2 -> V_4 . V_9 -> V_87 &&
V_14 == & V_98 . V_95 . V_14 ) )
V_92 &= ~ V_105 ;
if ( ( ! V_2 -> V_4 . V_9 -> V_104 &&
! V_2 -> V_4 . V_9 -> V_102 ) &&
( V_14 == & V_99 . V_95 . V_14 ||
V_14 == & V_100 . V_95 . V_14 ) )
return 0 ;
if ( V_14 == & V_106 . V_95 . V_14 )
return 0 ;
return V_92 ;
}
void F_64 ( struct V_107 * V_108 )
{
struct V_1 * V_2 =
F_65 ( V_108 , struct V_1 ,
V_4 . V_7 . V_80 . V_108 ) ;
enum V_19 V_109 = V_110 ;
if ( ! V_2 -> V_4 . V_5 )
return;
if ( V_2 -> V_4 . V_9 -> V_77 ) {
int V_76 = F_45 ( V_2 ) ;
if ( V_76 < V_2 -> V_4 . V_7 . V_80 . V_81 )
V_109 = V_2 -> V_4 . V_7 . V_20 ;
} else {
if ( V_2 -> V_4 . V_7 . V_80 . V_111 )
V_109 = V_2 -> V_4 . V_7 . V_20 ;
}
F_2 ( & V_2 -> V_4 . V_6 ) ;
if ( V_109 == V_110 )
V_2 -> V_4 . V_7 . V_47 = true ;
else
V_2 -> V_4 . V_7 . V_47 = false ;
V_2 -> V_4 . V_7 . V_25 = V_109 ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
F_11 ( V_2 ) ;
}
static struct V_112 * F_66 ( struct V_1 * V_2 ,
enum V_19 V_109 )
{
int V_51 ;
struct V_112 * V_113 ;
T_4 V_114 ;
bool V_115 = ( V_2 -> V_4 . V_7 . V_116 < 2 ) ?
true : false ;
if ( V_115 && V_2 -> V_4 . V_9 -> V_117 ) {
if ( F_67 ( V_2 ) )
V_115 = false ;
}
if ( V_109 == V_26 )
V_109 = V_118 ;
if ( V_109 == V_23 )
V_109 = V_26 ;
V_119:
for ( V_51 = 0 ; V_51 < V_2 -> V_4 . V_7 . V_120 ; V_51 ++ ) {
V_113 = & V_2 -> V_4 . V_7 . V_113 [ V_51 ] ;
V_114 = V_113 -> V_121 & V_122 ;
switch ( V_109 ) {
case V_22 :
if ( V_114 == V_123 ) {
if ( V_113 -> V_124 & V_125 ) {
if ( V_115 )
return V_113 ;
} else
return V_113 ;
}
break;
case V_23 :
if ( V_114 == V_126 ) {
if ( V_113 -> V_124 & V_125 ) {
if ( V_115 )
return V_113 ;
} else
return V_113 ;
}
break;
case V_26 :
if ( V_114 == V_127 ) {
if ( V_113 -> V_124 & V_125 ) {
if ( V_115 )
return V_113 ;
} else
return V_113 ;
}
break;
case V_128 :
if ( V_2 -> V_4 . V_7 . V_129 )
return V_2 -> V_4 . V_7 . V_129 ;
else
break;
case V_130 :
if ( V_113 -> V_121 & V_131 )
return V_113 ;
break;
case V_132 :
if ( V_113 -> V_121 & V_133 )
return V_113 ;
break;
case V_134 :
if ( V_113 -> V_121 & V_135 )
return V_113 ;
break;
case V_136 :
if ( V_113 -> V_137 & V_138 )
return V_113 ;
break;
case V_55 :
return V_2 -> V_4 . V_7 . V_73 ;
case V_110 :
if ( V_113 -> V_121 & V_139 )
return V_113 ;
break;
case V_140 :
if ( V_113 -> V_121 & V_141 )
return V_113 ;
break;
case V_142 :
if ( V_113 -> V_137 & V_143 )
return V_113 ;
break;
case V_118 :
if ( V_113 -> V_121 & V_144 )
return V_113 ;
break;
default:
break;
}
}
switch ( V_109 ) {
case V_130 :
V_109 = V_132 ;
goto V_119;
case V_132 :
case V_134 :
case V_136 :
if ( V_2 -> V_4 . V_7 . V_129 ) {
return V_2 -> V_4 . V_7 . V_129 ;
} else {
V_109 = V_26 ;
goto V_119;
}
case V_110 :
V_109 = V_140 ;
goto V_119;
case V_140 :
V_109 = V_22 ;
goto V_119;
case V_22 :
case V_23 :
case V_118 :
V_109 = V_26 ;
goto V_119;
default:
break;
}
return NULL ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_112 * V_113 ;
enum V_19 V_109 ;
int V_45 ;
bool V_145 ;
if ( ! V_2 -> V_4 . V_5 )
return;
if ( V_2 -> V_4 . V_7 . V_20 != V_2 -> V_4 . V_7 . V_25 ) {
if ( ( ! V_2 -> V_4 . V_7 . V_47 ) &&
( ! V_2 -> V_4 . V_7 . V_146 ) )
V_2 -> V_4 . V_7 . V_25 = V_2 -> V_4 . V_7 . V_20 ;
}
V_109 = V_2 -> V_4 . V_7 . V_25 ;
V_113 = F_66 ( V_2 , V_109 ) ;
if ( V_113 )
V_2 -> V_4 . V_7 . V_147 = V_113 ;
else
return;
if ( V_148 == 1 ) {
F_69 ( L_23 ) ;
F_70 ( V_2 , V_2 -> V_4 . V_7 . V_72 ) ;
F_69 ( L_24 ) ;
F_70 ( V_2 , V_2 -> V_4 . V_7 . V_147 ) ;
}
V_113 -> V_149 = V_2 -> V_4 . V_7 . V_149 ;
F_71 ( V_2 ) ;
V_45 = F_72 ( V_2 ) ;
if ( V_45 )
return;
if ( ( 0 != F_73 ( V_2 , V_2 -> V_4 . V_7 . V_72 , V_2 -> V_4 . V_7 . V_147 , & V_145 ) ) )
V_145 = false ;
if ( V_145 )
return;
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
V_2 -> V_4 . V_7 . V_150 = V_2 -> V_4 . V_7 . V_151 ;
V_2 -> V_4 . V_7 . V_152 = V_2 -> V_4 . V_7 . V_116 ;
if ( V_2 -> V_4 . V_9 -> V_153 ) {
if ( V_2 -> V_4 . V_7 . V_47 ) {
enum V_34 V_35 = V_2 -> V_4 . V_7 . V_48 ;
F_15 ( V_2 , V_37 ) ;
V_2 -> V_4 . V_7 . V_48 = V_35 ;
} else {
F_15 ( V_2 , V_2 -> V_4 . V_7 . V_48 ) ;
}
}
}
void F_76 ( struct V_1 * V_2 , bool V_154 )
{
if ( V_2 -> V_3 || V_2 -> V_4 . V_9 -> V_155 ) {
F_2 ( & V_2 -> V_4 . V_6 ) ;
F_77 ( V_2 , ! V_154 ) ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
} else {
if ( V_154 ) {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_146 = true ;
V_2 -> V_4 . V_7 . V_25 = V_128 ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
} else {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_146 = false ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
}
F_11 ( V_2 ) ;
}
}
void F_78 ( struct V_1 * V_2 , bool V_154 )
{
if ( V_2 -> V_3 || V_2 -> V_4 . V_9 -> V_156 ) {
F_2 ( & V_2 -> V_4 . V_6 ) ;
F_79 ( V_2 , ! V_154 ) ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
} else {
if ( V_154 ) {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_149 = true ;
V_2 -> V_4 . V_7 . V_157 = V_158 ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
F_11 ( V_2 ) ;
F_80 ( V_2 , V_159 ,
V_160 ) ;
F_81 ( V_2 , V_159 ,
V_161 ) ;
} else {
F_80 ( V_2 , V_159 ,
V_162 ) ;
F_81 ( V_2 , V_159 ,
V_163 ) ;
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_149 = false ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
F_11 ( V_2 ) ;
}
}
}
void F_82 ( struct V_1 * V_2 )
{
int V_51 ;
if ( V_2 -> V_3 )
return;
for ( V_51 = 0 ; V_51 < V_2 -> V_4 . V_7 . V_120 ; V_51 ++ )
F_70 ( V_2 , & V_2 -> V_4 . V_7 . V_113 [ V_51 ] ) ;
}
int F_83 ( struct V_1 * V_2 )
{
int V_45 ;
if ( V_2 -> V_4 . V_164 )
return 0 ;
if ( ! V_2 -> V_3 ) {
if ( V_2 -> V_4 . V_9 -> V_77 == NULL )
return 0 ;
}
V_2 -> V_4 . V_165 = F_84 ( V_2 -> V_12 ,
V_166 , V_2 ,
V_167 ) ;
if ( F_85 ( V_2 -> V_4 . V_165 ) ) {
V_45 = F_86 ( V_2 -> V_4 . V_165 ) ;
F_87 ( V_2 -> V_12 ,
L_25 , V_45 ) ;
return V_45 ;
}
V_45 = F_88 ( V_2 -> V_12 , & V_168 ) ;
if ( V_45 ) {
F_89 ( L_26 ) ;
return V_45 ;
}
V_45 = F_88 ( V_2 -> V_12 , & V_169 ) ;
if ( V_45 ) {
F_89 ( L_26 ) ;
return V_45 ;
}
if ( V_2 -> V_3 ) {
V_45 = F_88 ( V_2 -> V_12 , & V_170 ) ;
if ( V_45 ) {
F_89 ( L_27 ) ;
return V_45 ;
}
V_45 = F_88 ( V_2 -> V_12 , & V_171 ) ;
if ( V_45 ) {
F_89 ( L_28 ) ;
return V_45 ;
}
V_45 = F_88 ( V_2 -> V_12 , & V_172 ) ;
if ( V_45 ) {
F_89 ( L_29 ) ;
return V_45 ;
}
V_45 = F_88 ( V_2 -> V_12 , & V_173 ) ;
if ( V_45 ) {
F_89 ( L_30 ) ;
return V_45 ;
}
}
V_45 = F_88 ( V_2 -> V_12 , & V_174 ) ;
if ( V_45 ) {
F_89 ( L_31 ) ;
return V_45 ;
}
V_45 = F_88 ( V_2 -> V_12 , & V_175 ) ;
if ( V_45 ) {
F_89 ( L_32 ) ;
return V_45 ;
}
V_45 = F_88 ( V_2 -> V_12 , & V_176 ) ;
if ( V_45 ) {
F_89 ( L_33 ) ;
return V_45 ;
}
V_45 = F_88 ( V_2 -> V_12 , & V_177 ) ;
if ( V_45 ) {
F_89 ( L_34 ) ;
return V_45 ;
}
V_45 = F_88 ( V_2 -> V_12 , & V_178 ) ;
if ( V_45 ) {
F_89 ( L_35 ) ;
return V_45 ;
}
V_45 = F_90 ( V_2 ) ;
if ( V_45 ) {
F_89 ( L_36 ) ;
return V_45 ;
}
V_2 -> V_4 . V_164 = true ;
return 0 ;
}
void F_91 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . V_165 )
F_92 ( V_2 -> V_4 . V_165 ) ;
F_93 ( V_2 -> V_12 , & V_168 ) ;
F_93 ( V_2 -> V_12 , & V_169 ) ;
if ( V_2 -> V_3 ) {
F_93 ( V_2 -> V_12 , & V_170 ) ;
F_93 ( V_2 -> V_12 , & V_171 ) ;
F_93 ( V_2 -> V_12 , & V_172 ) ;
F_93 ( V_2 -> V_12 , & V_173 ) ;
}
F_93 ( V_2 -> V_12 , & V_174 ) ;
F_93 ( V_2 -> V_12 , & V_175 ) ;
F_93 ( V_2 -> V_12 , & V_176 ) ;
F_93 ( V_2 -> V_12 , & V_177 ) ;
F_93 ( V_2 -> V_12 , & V_178 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
struct V_179 * V_180 ;
struct V_181 * V_181 ;
int V_51 = 0 ;
if ( ! V_2 -> V_4 . V_5 )
return;
if ( V_2 -> V_182 . V_183 )
F_94 ( V_2 ) ;
for ( V_51 = 0 ; V_51 < V_184 ; V_51 ++ ) {
struct V_185 * V_186 = V_2 -> V_187 [ V_51 ] ;
if ( V_186 && V_186 -> V_188 )
F_95 ( V_186 ) ;
}
if ( V_2 -> V_3 ) {
F_10 ( V_2 , V_189 , NULL , NULL ) ;
} else {
F_2 ( & V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_7 . V_151 = 0 ;
V_2 -> V_4 . V_7 . V_116 = 0 ;
if ( V_2 -> V_182 . V_183 && V_2 -> V_182 . V_190 ) {
F_96 (crtc,
&ddev->mode_config.crtc_list, head) {
V_181 = F_97 ( V_180 ) ;
if ( V_180 -> V_191 ) {
V_2 -> V_4 . V_7 . V_151 |= ( 1 << V_181 -> V_192 ) ;
V_2 -> V_4 . V_7 . V_116 ++ ;
}
}
}
if ( F_3 () > 0 )
V_2 -> V_4 . V_7 . V_8 = true ;
else
V_2 -> V_4 . V_7 . V_8 = false ;
F_68 ( V_2 ) ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
}
}
static int F_98 ( struct V_193 * V_194 , struct V_1 * V_2 )
{
T_6 V_68 ;
if ( ! ( V_2 -> V_195 . V_196 &&
V_2 -> V_195 . V_196 -> V_197 ) )
return - V_27 ;
F_99 ( V_194 , L_37 ) ;
if ( ! F_100 ( V_2 , V_198 , & V_68 ) )
F_99 ( V_194 , L_38 , V_68 / 100 ) ;
if ( ! F_100 ( V_2 , V_199 , & V_68 ) )
F_99 ( V_194 , L_39 , V_68 / 100 ) ;
if ( ! F_100 ( V_2 , V_200 , & V_68 ) )
F_99 ( V_194 , L_40 , V_68 ) ;
if ( ! F_100 ( V_2 , V_201 , & V_68 ) )
F_99 ( V_194 , L_41 , V_68 ) ;
F_99 ( V_194 , L_21 ) ;
if ( ! F_100 ( V_2 , V_202 , & V_68 ) )
F_99 ( V_194 , L_42 , V_68 / 1000 ) ;
if ( ! F_100 ( V_2 , V_203 , & V_68 ) )
F_99 ( V_194 , L_43 , V_68 ) ;
F_99 ( V_194 , L_21 ) ;
if ( ! F_100 ( V_2 , V_204 , & V_68 ) ) {
if ( ! V_68 ) {
F_99 ( V_194 , L_44 ) ;
} else {
F_99 ( V_194 , L_45 ) ;
if ( ! F_100 ( V_2 , V_205 , & V_68 ) )
F_99 ( V_194 , L_46 , V_68 / 100 ) ;
if ( ! F_100 ( V_2 , V_206 , & V_68 ) )
F_99 ( V_194 , L_47 , V_68 / 100 ) ;
}
}
F_99 ( V_194 , L_21 ) ;
if ( ! F_100 ( V_2 , V_207 , & V_68 ) ) {
if ( ! V_68 ) {
F_99 ( V_194 , L_48 ) ;
} else {
F_99 ( V_194 , L_49 ) ;
if ( ! F_100 ( V_2 , V_208 , & V_68 ) )
F_99 ( V_194 , L_50 , V_68 / 100 ) ;
}
}
return 0 ;
}
static void F_101 ( struct V_193 * V_194 , T_4 V_30 )
{
int V_51 ;
for ( V_51 = 0 ; V_209 [ V_51 ] . V_210 ; V_51 ++ )
F_99 ( V_194 , L_51 , V_209 [ V_51 ] . V_211 ,
( V_30 & V_209 [ V_51 ] . V_210 ) ? L_52 : L_53 ) ;
}
static int F_102 ( struct V_193 * V_194 , void * V_50 )
{
struct V_212 * V_213 = (struct V_212 * ) V_194 -> V_214 ;
struct V_16 * V_12 = V_213 -> V_215 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_18 ;
struct V_16 * V_17 = V_2 -> V_17 ;
T_4 V_30 = 0 ;
F_103 ( V_2 , & V_30 ) ;
F_99 ( V_194 , L_54 , V_30 ) ;
F_101 ( V_194 , V_30 ) ;
F_99 ( V_194 , L_21 ) ;
if ( ! V_2 -> V_4 . V_5 ) {
F_99 ( V_194 , L_55 ) ;
return 0 ;
}
if ( ( V_2 -> V_30 & V_31 ) &&
( V_17 -> V_32 != V_33 ) ) {
F_99 ( V_194 , L_56 ) ;
} else if ( V_2 -> V_3 ) {
return F_98 ( V_194 , V_2 ) ;
} else {
F_2 ( & V_2 -> V_4 . V_6 ) ;
if ( V_2 -> V_4 . V_9 -> V_216 )
V_2 -> V_4 . V_9 -> V_216 ( V_2 , V_194 ) ;
else
F_99 ( V_194 , L_57 ) ;
F_5 ( & V_2 -> V_4 . V_6 ) ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
#if F_104 ( V_217 )
return F_105 ( V_2 , V_218 , F_22 ( V_218 ) ) ;
#else
return 0 ;
#endif
}
