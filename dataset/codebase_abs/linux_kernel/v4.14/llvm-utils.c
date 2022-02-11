int F_1 ( const char * V_1 , const char * V_2 )
{
if ( ! F_2 ( V_1 , L_1 ) )
return 0 ;
V_1 += sizeof( L_1 ) - 1 ;
if ( ! strcmp ( V_1 , L_2 ) )
V_3 . V_4 = F_3 ( V_2 ) ;
else if ( ! strcmp ( V_1 , L_3 ) )
V_3 . V_5 = F_3 ( V_2 ) ;
else if ( ! strcmp ( V_1 , L_4 ) )
V_3 . V_6 = F_3 ( V_2 ) ;
else if ( ! strcmp ( V_1 , L_5 ) )
V_3 . V_7 = F_3 ( V_2 ) ;
else if ( ! strcmp ( V_1 , L_6 ) )
V_3 . V_8 = F_3 ( V_2 ) ;
else if ( ! strcmp ( V_1 , L_7 ) )
V_3 . V_9 = ! ! F_4 ( V_1 , V_2 ) ;
else {
F_5 ( L_8 , V_2 ) ;
return - 1 ;
}
V_3 . V_10 = true ;
return 0 ;
}
static int
F_6 ( const char * V_11 , const char * V_12 ,
char * V_13 )
{
char * V_14 , * V_15 , * V_16 = NULL ;
char V_17 [ V_18 ] ;
int V_19 ;
V_13 [ 0 ] = '\0' ;
if ( V_11 && V_11 [ 0 ] != '\0' ) {
if ( V_11 [ 0 ] == '/' ) {
if ( F_7 ( V_11 , V_20 ) == 0 ) {
F_8 ( V_13 , V_11 , V_18 ) ;
return 0 ;
}
} else if ( V_11 [ 0 ] != '\0' )
V_12 = V_11 ;
}
V_14 = getenv ( L_9 ) ;
if ( ! V_14 )
return - 1 ;
V_14 = F_3 ( V_14 ) ;
if ( ! V_14 )
return - 1 ;
V_19 = - V_21 ;
V_15 = strtok_r ( V_14 , L_10 , & V_16 ) ;
while ( V_15 ) {
F_9 ( V_17 , sizeof( V_17 ) , L_11 , V_15 , V_12 ) ;
if ( F_7 ( V_17 , V_20 ) == 0 ) {
F_8 ( V_13 , V_17 , V_18 ) ;
V_19 = 0 ;
break;
}
V_15 = strtok_r ( NULL , L_10 , & V_16 ) ;
}
free ( V_14 ) ;
return V_19 ;
}
static int
F_10 ( const char * V_22 , void * * V_23 , T_1 * V_24 )
{
int V_25 = 0 ;
void * V_17 = NULL ;
T_2 * V_26 = NULL ;
T_1 V_27 = 0 , V_28 = 0 ;
char V_29 [ V_30 ] ;
V_26 = F_11 ( V_22 , L_12 ) ;
if ( ! V_26 ) {
F_12 ( L_13 ,
F_13 ( V_31 , V_29 , sizeof( V_29 ) ) ) ;
return - V_32 ;
}
while ( ! feof ( V_26 ) && ! ferror ( V_26 ) ) {
if ( V_28 - V_27 < V_33 + 1 ) {
void * V_34 ;
V_28 = V_27 + V_33 + 1 ;
V_34 = realloc ( V_17 , V_28 ) ;
if ( ! V_34 ) {
F_12 ( L_14 ) ;
V_25 = - V_35 ;
goto V_36;
}
V_17 = V_34 ;
}
V_27 += fread ( V_17 + V_27 , 1 , V_33 , V_26 ) ;
}
if ( V_28 - V_27 < 1 ) {
F_12 ( L_15 ) ;
V_25 = - V_32 ;
goto V_36;
}
if ( ferror ( V_26 ) ) {
F_12 ( L_16 ,
F_13 ( V_31 , V_29 , sizeof( V_29 ) ) ) ;
V_25 = - V_37 ;
goto V_36;
}
V_25 = F_14 ( F_15 ( V_26 ) ) ;
V_26 = NULL ;
if ( V_25 ) {
V_25 = - V_32 ;
goto V_36;
}
( ( char * ) V_17 ) [ V_27 ] = '\0' ;
if ( ! V_23 )
free ( V_17 ) ;
else
* V_23 = V_17 ;
if ( V_24 )
* V_24 = V_27 ;
return 0 ;
V_36:
if ( V_26 )
F_15 ( V_26 ) ;
free ( V_17 ) ;
if ( V_23 )
* V_23 = NULL ;
if ( V_24 )
* V_24 = 0 ;
return V_25 ;
}
static inline void
F_16 ( const char * V_1 , const char * V_2 )
{
if ( V_2 ) {
F_17 ( V_1 , V_2 , 1 ) ;
F_5 ( L_17 , V_1 , V_2 ) ;
} else {
F_18 ( V_1 ) ;
F_5 ( L_18 , V_1 ) ;
}
}
static void
F_19 ( void )
{
F_12 (
L_19
L_20
L_21
L_22
L_23
L_24
L_25
L_26
L_27
L_28
L_29
L_30
L_31
L_32
) ;
}
static int F_20 ( char * * V_7 )
{
const char * V_38 = V_3 . V_7 ;
const char * V_39 = L_33 ;
const char * V_40 = L_33 ;
char * V_41 ;
int V_25 ;
if ( ! V_38 ) {
char V_42 [ 128 ] ;
V_25 = F_21 ( NULL , V_42 ,
sizeof( V_42 ) ) ;
if ( V_25 )
return - V_32 ;
V_38 = V_42 ;
V_39 = L_34 ;
V_40 = L_35 ;
}
V_25 = F_22 ( & V_41 , L_36 ,
V_39 , V_38 , V_40 ) ;
if ( V_25 < 0 )
return - V_35 ;
if ( F_7 ( V_41 , V_43 ) == 0 ) {
free ( V_41 ) ;
V_25 = F_22 ( V_7 , L_37 , V_39 , V_38 ,
V_40 ) ;
if ( V_25 < 0 )
return - V_35 ;
return 0 ;
}
free ( V_41 ) ;
return - V_21 ;
}
void F_23 ( char * * V_7 , char * * V_44 )
{
static char * V_45 ;
static char * V_46 ;
int V_25 ;
if ( ! V_7 || ! V_44 )
return;
* V_7 = NULL ;
* V_44 = NULL ;
if ( V_45 && V_46 &&
! F_24 ( V_45 ) && ! F_24 ( V_46 ) ) {
* V_7 = F_3 ( V_45 ) ;
* V_44 = F_3 ( V_46 ) ;
if ( * V_7 && * V_44 )
return;
F_25 ( V_7 ) ;
F_25 ( V_44 ) ;
return;
}
if ( V_3 . V_7 && ! V_3 . V_7 [ 0 ] ) {
F_5 ( L_38 ) ;
F_5 ( L_39 ) ;
goto V_36;
}
V_25 = F_20 ( V_7 ) ;
if ( V_25 ) {
F_26 (
L_40
L_41
L_42
L_43 ) ;
goto V_36;
}
F_5 ( L_44 , * V_7 ) ;
F_16 ( L_45 , * V_7 ) ;
F_16 ( L_46 , V_3 . V_8 ) ;
V_25 = F_10 ( V_47 ,
( void * * ) V_44 ,
NULL ) ;
if ( V_25 ) {
F_26 (
L_47
L_48
L_49
L_50 ,
* V_7 ) ;
free ( * V_7 ) ;
* V_7 = NULL ;
goto V_36;
}
F_5 ( L_51 , * V_44 ) ;
V_45 = F_3 ( * V_7 ) ;
V_46 = F_3 ( * V_44 ) ;
if ( ! V_45 || ! V_46 ) {
F_25 ( & V_45 ) ;
F_25 ( & V_46 ) ;
}
return;
V_36:
V_45 = F_27 ( - V_32 ) ;
V_46 = F_27 ( - V_32 ) ;
}
int F_28 ( void )
{
static int V_48 = 0 ;
char V_29 [ V_30 ] ;
if ( V_48 > 0 )
return V_48 ;
V_48 = F_29 ( V_49 ) ;
if ( V_48 <= 0 ) {
F_12 (
L_52
L_53 , F_13 ( V_31 , V_29 , sizeof( V_29 ) ) ) ;
V_48 = 128 ;
}
return V_48 ;
}
void F_30 ( const char * V_15 , void * V_50 , T_1 V_51 )
{
char * V_52 = F_3 ( V_15 ) ;
T_2 * V_53 ;
char * V_54 ;
if ( ! V_52 ) {
F_26 ( L_54 ) ;
return;
}
V_54 = strrchr ( V_52 , '.' ) ;
if ( ! V_54 || ( strcmp ( V_54 , L_55 ) != 0 ) ) {
F_26 ( L_56 ,
V_52 ) ;
goto V_55;
}
V_54 [ 1 ] = 'o' ;
V_53 = fopen ( V_52 , L_57 ) ;
if ( ! V_53 ) {
F_26 ( L_58 ,
V_52 , strerror ( V_31 ) ) ;
goto V_55;
}
F_31 ( L_59 , V_52 ) ;
if ( fwrite ( V_50 , V_51 , 1 , V_53 ) != 1 )
F_26 ( L_60 ,
V_52 , strerror ( V_31 ) ) ;
fclose ( V_53 ) ;
V_55:
free ( V_52 ) ;
}
int F_32 ( const char * V_15 , void * * V_56 ,
T_1 * V_57 )
{
T_1 V_58 ;
void * V_50 = NULL ;
int V_25 , V_48 ;
unsigned int V_59 ;
char V_60 [ 64 ] ;
const char * V_6 = V_3 . V_6 ;
char V_4 [ V_18 ] , V_61 [ V_18 ] , V_62 [ 64 ] ;
char V_29 [ V_30 ] ;
char * V_7 = NULL , * V_44 = NULL ;
const char * V_63 = V_3 . V_5 ;
if ( V_15 [ 0 ] != '-' && F_33 ( V_15 , V_61 ) == NULL ) {
V_25 = V_31 ;
F_12 ( L_61 ,
V_15 , F_13 ( V_25 , V_29 , sizeof( V_29 ) ) ) ;
return - V_25 ;
}
if ( ! V_63 )
V_63 = V_64 ;
V_25 = F_6 ( V_3 . V_4 ,
L_62 , V_4 ) ;
if ( V_25 ) {
F_12 (
L_63
L_64
L_65 ) ;
F_19 () ;
return - V_21 ;
}
F_23 ( & V_7 , & V_44 ) ;
V_48 = F_28 () ;
snprintf ( V_62 , sizeof( V_62 ) , L_66 ,
V_48 ) ;
if ( F_21 ( & V_59 , NULL , 0 ) )
V_59 = 0 ;
snprintf ( V_60 , sizeof( V_60 ) ,
L_67 , V_59 ) ;
F_16 ( L_68 , V_62 ) ;
F_16 ( L_69 , V_60 ) ;
F_16 ( L_70 , V_4 ) ;
F_16 ( L_71 , V_6 ) ;
F_16 ( L_72 , V_44 ) ;
F_16 ( L_73 , V_7 ? : L_74 ) ;
F_16 ( L_75 ,
( V_15 [ 0 ] == '-' ) ? V_15 : V_61 ) ;
F_5 ( L_76 , V_63 ) ;
V_25 = F_10 ( V_63 , & V_50 , & V_58 ) ;
if ( V_25 ) {
F_12 ( L_77 , V_15 ) ;
F_12 ( L_78 ) ;
F_12 ( L_79 ) ;
F_12 ( L_80 , V_15 ) ;
F_12 ( L_81 ) ;
goto V_36;
}
free ( V_7 ) ;
free ( V_44 ) ;
if ( ! V_56 )
free ( V_50 ) ;
else
* V_56 = V_50 ;
if ( V_57 )
* V_57 = V_58 ;
return 0 ;
V_36:
free ( V_7 ) ;
free ( V_44 ) ;
free ( V_50 ) ;
if ( V_56 )
* V_56 = NULL ;
if ( V_57 )
* V_57 = 0 ;
return V_25 ;
}
int F_34 ( void )
{
char V_4 [ V_18 ] ;
return F_6 ( V_3 . V_4 , L_62 , V_4 ) ;
}
