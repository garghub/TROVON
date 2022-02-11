static int F_1 ( const void * V_1 , const void * V_2 )
{
const struct V_3 * V_4 = V_2 ;
return strcmp ( V_1 , V_4 -> V_1 ) ;
}
static struct V_3 * F_2 ( const char * V_1 )
{
const int V_5 = F_3 ( V_6 ) ;
return bsearch ( V_1 , V_6 , V_5 , sizeof( struct V_3 ) , F_1 ) ;
}
static int F_4 ( struct V_7 * V_7 , int V_8 )
{
char V_9 [ 128 ] ;
struct V_10 * V_11 ;
const char * V_1 = F_5 ( V_8 , V_7 -> V_12 ) ;
if ( V_1 == NULL )
return - 1 ;
if ( V_8 > V_7 -> V_13 . V_14 ) {
struct V_10 * V_15 = realloc ( V_7 -> V_13 . V_16 , ( V_8 + 1 ) * sizeof( * V_11 ) ) ;
if ( V_15 == NULL )
return - 1 ;
if ( V_7 -> V_13 . V_14 != - 1 ) {
memset ( V_15 + V_7 -> V_13 . V_14 + 1 , 0 ,
( V_8 - V_7 -> V_13 . V_14 ) * sizeof( * V_11 ) ) ;
} else {
memset ( V_15 , 0 , ( V_8 + 1 ) * sizeof( * V_11 ) ) ;
}
V_7 -> V_13 . V_16 = V_15 ;
V_7 -> V_13 . V_14 = V_8 ;
}
V_11 = V_7 -> V_13 . V_16 + V_8 ;
V_11 -> V_1 = V_1 ;
V_11 -> V_4 = F_2 ( V_11 -> V_1 ) ;
snprintf ( V_9 , sizeof( V_9 ) , L_1 , V_11 -> V_1 ) ;
V_11 -> V_17 = F_6 ( L_2 , V_9 ) ;
if ( V_11 -> V_17 == NULL && V_11 -> V_4 && V_11 -> V_4 -> V_18 ) {
snprintf ( V_9 , sizeof( V_9 ) , L_1 , V_11 -> V_4 -> V_18 ) ;
V_11 -> V_17 = F_6 ( L_2 , V_9 ) ;
}
return V_11 -> V_17 != NULL ? 0 : - 1 ;
}
static T_1 F_7 ( struct V_10 * V_11 , unsigned long * args , T_2 * V_19 )
{
int V_20 = 0 ;
T_1 V_21 = 0 ;
if ( V_11 -> V_17 != NULL ) {
struct V_22 * V_23 ;
for ( V_23 = V_11 -> V_17 -> V_24 . V_25 -> V_26 ; V_23 ; V_23 = V_23 -> V_26 ) {
V_21 += fprintf ( V_19 , L_3 , V_21 ? L_4 : L_5 ,
V_23 -> V_1 , args [ V_20 ++ ] ) ;
}
} else {
while ( V_20 < 6 ) {
V_21 += fprintf ( V_19 , L_6 , V_21 ? L_4 : L_5 , V_20 , args [ V_20 ] ) ;
++ V_20 ;
}
}
return V_21 ;
}
static struct V_10 * F_8 ( struct V_7 * V_7 ,
struct V_27 * V_28 ,
struct V_29 * V_30 )
{
int V_8 = F_9 ( V_28 , V_30 , L_7 ) ;
if ( V_8 < 0 ) {
printf ( L_8 , V_8 ) ;
return NULL ;
}
if ( ( V_8 > V_7 -> V_13 . V_14 || V_7 -> V_13 . V_16 [ V_8 ] . V_1 == NULL ) &&
F_4 ( V_7 , V_8 ) )
goto V_31;
if ( ( V_8 > V_7 -> V_13 . V_14 || V_7 -> V_13 . V_16 [ V_8 ] . V_1 == NULL ) )
goto V_31;
return & V_7 -> V_13 . V_16 [ V_8 ] ;
V_31:
printf ( L_9 , V_8 ) ;
return NULL ;
}
static int F_10 ( struct V_7 * V_7 , struct V_27 * V_28 ,
struct V_29 * V_30 )
{
void * args ;
struct V_10 * V_11 = F_8 ( V_7 , V_28 , V_30 ) ;
if ( V_11 == NULL )
return - 1 ;
args = F_11 ( V_28 , V_30 , L_10 ) ;
if ( args == NULL ) {
printf ( L_11 ) ;
return - 1 ;
}
printf ( L_12 , V_11 -> V_1 ) ;
F_7 ( V_11 , args , stdout ) ;
return 0 ;
}
static int F_12 ( struct V_7 * V_7 , struct V_27 * V_28 ,
struct V_29 * V_30 )
{
int V_32 ;
struct V_10 * V_11 = F_8 ( V_7 , V_28 , V_30 ) ;
if ( V_11 == NULL )
return - 1 ;
V_32 = F_9 ( V_28 , V_30 , L_13 ) ;
if ( V_32 < 0 && V_11 -> V_4 && V_11 -> V_4 -> V_33 ) {
char V_34 [ 256 ] ;
const char * V_35 = F_13 ( - V_32 , V_34 , sizeof( V_34 ) ) ,
* V_36 = F_14 ( - V_32 ) ;
printf ( L_14 , V_36 , V_35 ) ;
} else if ( V_32 == 0 && V_11 -> V_4 && V_11 -> V_4 -> V_37 )
printf ( L_15 ) ;
else
printf ( L_16 , V_32 ) ;
putchar ( '\n' ) ;
return 0 ;
}
static int F_15 ( struct V_7 * V_7 )
{
struct V_38 * V_39 = F_16 ( NULL , NULL ) ;
struct V_27 * V_28 ;
int V_40 = - 1 , V_20 , V_41 = 0 , V_42 ;
if ( V_39 == NULL ) {
printf ( L_17 ) ;
goto V_43;
}
if ( F_17 ( V_39 , L_18 , L_19 , F_10 ) ||
F_17 ( V_39 , L_18 , L_20 , F_12 ) ) {
printf ( L_21 ) ;
goto V_44;
}
V_40 = F_18 ( V_39 , & V_7 -> V_45 . V_46 ) ;
if ( V_40 < 0 ) {
printf ( L_22 ) ;
goto V_44;
}
F_19 ( V_39 , & V_7 -> V_45 ) ;
V_40 = F_20 ( V_39 ) ;
if ( V_40 < 0 ) {
printf ( L_23 , strerror ( V_47 ) ) ;
goto V_44;
}
V_40 = F_21 ( V_39 , V_48 , false ) ;
if ( V_40 < 0 ) {
printf ( L_24 , strerror ( V_47 ) ) ;
goto V_44;
}
F_22 ( V_39 ) ;
V_49:
V_42 = V_41 ;
for ( V_20 = 0 ; V_20 < V_39 -> V_50 ; V_20 ++ ) {
union V_51 * V_52 ;
while ( ( V_52 = F_23 ( V_39 , V_20 ) ) != NULL ) {
const T_3 type = V_52 -> V_53 . type ;
T_4 V_54 ;
struct V_29 V_30 ;
++ V_41 ;
switch ( type ) {
case V_55 :
break;
case V_56 :
printf ( L_25 V_57 L_26 , V_52 -> V_58 . V_58 ) ;
continue;
default:
printf ( L_27 ,
F_24 ( type ) ) ;
continue;
}
V_40 = F_25 ( V_39 , V_52 , & V_30 ) ;
if ( V_40 ) {
printf ( L_28 , V_40 ) ;
continue;
}
V_28 = F_26 ( V_39 , V_30 . V_8 ) ;
if ( V_28 == NULL ) {
printf ( L_29 V_57 L_30 , V_30 . V_8 ) ;
continue;
}
if ( V_39 -> V_59 -> V_60 [ 0 ] == - 1 || V_39 -> V_59 -> V_61 > 1 )
printf ( L_31 , V_30 . V_62 ) ;
if ( V_30 . V_63 == NULL ) {
printf ( L_32 ,
F_27 ( V_28 ) , V_30 . V_62 ,
V_30 . V_64 , V_30 . V_65 ) ;
continue;
}
V_54 = V_28 -> V_54 . V_66 ;
V_54 ( V_7 , V_28 , & V_30 ) ;
}
}
if ( V_41 == V_42 )
F_28 ( V_39 -> V_67 , V_39 -> V_68 , - 1 ) ;
goto V_49;
V_44:
F_29 ( V_39 ) ;
V_43:
return V_40 ;
}
int F_30 ( int V_69 , const char * * V_70 , const char * T_5 V_71 )
{
const char * const V_72 [] = {
L_33 ,
NULL
} ;
struct V_7 V_7 = {
. V_12 = F_31 () ,
. V_13 = {
. V_14 = - 1 ,
} ,
. V_45 = {
. V_46 = {
. V_73 = V_48 ,
. V_74 = true ,
} ,
. V_75 = V_48 ,
. V_76 = V_77 ,
. V_78 = true ,
. V_79 = 1024 ,
} ,
} ;
const struct V_80 V_81 [] = {
F_32 ( 'p' , L_34 , & V_7 . V_45 . V_46 . V_82 , L_34 ,
L_35 ) ,
F_32 ( 0 , L_36 , & V_7 . V_45 . V_46 . V_62 , L_36 ,
L_37 ) ,
F_33 ( 0 , L_38 , & V_7 . V_45 . V_46 . V_83 ,
L_39 ) ,
F_32 ( 0 , L_40 , & V_7 . V_45 . V_46 . V_84 , L_40 ,
L_41 ) ,
F_33 ( 0 , L_42 , & V_7 . V_45 . V_85 ,
L_43 ) ,
F_34 ( 0 , L_44 , & V_7 . V_45 . V_79 ,
L_45 ) ,
F_32 ( 0 , L_46 , & V_7 . V_45 . V_46 . V_86 , L_47 ,
L_48 ) ,
F_35 ()
} ;
int V_40 ;
V_69 = F_36 ( V_69 , V_70 , V_81 , V_72 , 0 ) ;
if ( V_69 )
F_37 ( V_72 , V_81 ) ;
V_40 = F_38 ( & V_7 . V_45 . V_46 ) ;
if ( V_40 ) {
char V_34 [ V_87 ] ;
F_39 ( & V_7 . V_45 . V_46 , V_40 , V_34 , sizeof( V_34 ) ) ;
printf ( L_49 , V_34 ) ;
return V_40 ;
}
return F_15 ( & V_7 ) ;
}
