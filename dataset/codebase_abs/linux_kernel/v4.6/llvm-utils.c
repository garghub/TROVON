int F_1 ( const char * V_1 , const char * V_2 )
{
if ( F_2 ( V_1 , L_1 ) )
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
else
return - 1 ;
V_3 . V_9 = true ;
return 0 ;
}
static int
F_4 ( const char * V_10 , const char * V_11 ,
char * V_12 )
{
char * V_13 , * V_14 , * V_15 = NULL ;
char V_16 [ V_17 ] ;
int V_18 ;
V_12 [ 0 ] = '\0' ;
if ( V_10 && V_10 [ 0 ] != '\0' ) {
if ( V_10 [ 0 ] == '/' ) {
if ( F_5 ( V_10 , V_19 ) == 0 ) {
F_6 ( V_12 , V_10 , V_17 ) ;
return 0 ;
}
} else if ( V_10 [ 0 ] != '\0' )
V_11 = V_10 ;
}
V_13 = getenv ( L_7 ) ;
if ( ! V_13 )
return - 1 ;
V_13 = F_3 ( V_13 ) ;
if ( ! V_13 )
return - 1 ;
V_18 = - V_20 ;
V_14 = strtok_r ( V_13 , L_8 , & V_15 ) ;
while ( V_14 ) {
F_7 ( V_16 , sizeof( V_16 ) , L_9 , V_14 , V_11 ) ;
if ( F_5 ( V_16 , V_19 ) == 0 ) {
F_6 ( V_12 , V_16 , V_17 ) ;
V_18 = 0 ;
break;
}
V_14 = strtok_r ( NULL , L_8 , & V_15 ) ;
}
free ( V_13 ) ;
return V_18 ;
}
static int
F_8 ( const char * V_21 , void * * V_22 , T_1 * V_23 )
{
int V_24 = 0 ;
void * V_16 = NULL ;
T_2 * V_25 = NULL ;
T_1 V_26 = 0 , V_27 = 0 ;
char V_28 [ V_29 ] ;
V_25 = F_9 ( V_21 , L_10 ) ;
if ( ! V_25 ) {
F_10 ( L_11 ,
F_11 ( V_30 , V_28 , sizeof( V_28 ) ) ) ;
return - V_31 ;
}
while ( ! feof ( V_25 ) && ! ferror ( V_25 ) ) {
if ( V_27 - V_26 < V_32 + 1 ) {
void * V_33 ;
V_27 = V_26 + V_32 + 1 ;
V_33 = realloc ( V_16 , V_27 ) ;
if ( ! V_33 ) {
F_10 ( L_12 ) ;
V_24 = - V_34 ;
goto V_35;
}
V_16 = V_33 ;
}
V_26 += fread ( V_16 + V_26 , 1 , V_32 , V_25 ) ;
}
if ( V_27 - V_26 < 1 ) {
F_10 ( L_13 ) ;
V_24 = - V_31 ;
goto V_35;
}
if ( ferror ( V_25 ) ) {
F_10 ( L_14 ,
F_11 ( V_30 , V_28 , sizeof( V_28 ) ) ) ;
V_24 = - V_36 ;
goto V_35;
}
V_24 = F_12 ( F_13 ( V_25 ) ) ;
V_25 = NULL ;
if ( V_24 ) {
V_24 = - V_31 ;
goto V_35;
}
( ( char * ) V_16 ) [ V_26 ] = '\0' ;
if ( ! V_22 )
free ( V_16 ) ;
else
* V_22 = V_16 ;
if ( V_23 )
* V_23 = V_26 ;
return 0 ;
V_35:
if ( V_25 )
F_13 ( V_25 ) ;
free ( V_16 ) ;
if ( V_22 )
* V_22 = NULL ;
if ( V_23 )
* V_23 = 0 ;
return V_24 ;
}
static inline void
F_14 ( const char * V_1 , const char * V_2 )
{
if ( V_2 ) {
F_15 ( V_1 , V_2 , 1 ) ;
F_16 ( L_15 , V_1 , V_2 ) ;
} else {
F_17 ( V_1 ) ;
F_16 ( L_16 , V_1 ) ;
}
}
static void
F_18 ( void )
{
F_10 (
L_17
L_18
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
) ;
}
static int F_19 ( char * * V_7 )
{
const char * V_37 = V_3 . V_7 ;
const char * V_38 = L_31 ;
const char * V_39 = L_31 ;
char * V_40 ;
int V_24 ;
if ( ! V_37 ) {
char V_41 [ 128 ] ;
V_24 = F_20 ( NULL , V_41 ,
sizeof( V_41 ) ) ;
if ( V_24 )
return - V_31 ;
V_37 = V_41 ;
V_38 = L_32 ;
V_39 = L_33 ;
}
V_24 = F_21 ( & V_40 , L_34 ,
V_38 , V_37 , V_39 ) ;
if ( V_24 < 0 )
return - V_34 ;
if ( F_5 ( V_40 , V_42 ) == 0 ) {
free ( V_40 ) ;
V_24 = F_21 ( V_7 , L_35 , V_38 , V_37 ,
V_39 ) ;
if ( V_24 < 0 )
return - V_34 ;
return 0 ;
}
free ( V_40 ) ;
return - V_20 ;
}
static inline void
F_22 ( char * * V_7 , char * * V_43 )
{
int V_24 ;
if ( ! V_7 || ! V_43 )
return;
* V_7 = NULL ;
* V_43 = NULL ;
if ( V_3 . V_7 && ! V_3 . V_7 [ 0 ] ) {
F_16 ( L_36 ) ;
F_16 ( L_37 ) ;
return;
}
V_24 = F_19 ( V_7 ) ;
if ( V_24 ) {
F_23 (
L_38
L_39
L_40
L_41 ) ;
return;
}
F_16 ( L_42 , * V_7 ) ;
F_14 ( L_43 , * V_7 ) ;
F_14 ( L_44 , V_3 . V_8 ) ;
V_24 = F_8 ( V_44 ,
( void * * ) V_43 ,
NULL ) ;
if ( V_24 ) {
F_23 (
L_45
L_46
L_47
L_48 ,
* V_7 ) ;
free ( * V_7 ) ;
* V_7 = NULL ;
return;
}
F_16 ( L_49 , * V_43 ) ;
}
int F_24 ( const char * V_14 , void * * V_45 ,
T_1 * V_46 )
{
T_1 V_47 ;
void * V_48 = NULL ;
int V_24 , V_49 ;
unsigned int V_50 ;
char V_51 [ 64 ] ;
const char * V_6 = V_3 . V_6 ;
char V_4 [ V_17 ] , V_52 [ V_17 ] , V_53 [ 64 ] ;
char V_28 [ V_29 ] ;
char * V_7 = NULL , * V_43 = NULL ;
const char * V_54 = V_3 . V_5 ;
if ( V_14 [ 0 ] != '-' && F_25 ( V_14 , V_52 ) == NULL ) {
V_24 = V_30 ;
F_10 ( L_50 ,
V_14 , F_11 ( V_24 , V_28 , sizeof( V_28 ) ) ) ;
return - V_24 ;
}
if ( ! V_54 )
V_54 = V_55 ;
V_24 = F_4 ( V_3 . V_4 ,
L_51 , V_4 ) ;
if ( V_24 ) {
F_10 (
L_52
L_53
L_54 ) ;
F_18 () ;
return - V_20 ;
}
F_22 ( & V_7 , & V_43 ) ;
V_49 = F_26 ( V_56 ) ;
if ( V_49 <= 0 ) {
F_10 (
L_55
L_56 , F_11 ( V_30 , V_28 , sizeof( V_28 ) ) ) ;
V_49 = 128 ;
}
snprintf ( V_53 , sizeof( V_53 ) , L_57 ,
V_49 ) ;
if ( F_20 ( & V_50 , NULL , 0 ) )
V_50 = 0 ;
snprintf ( V_51 , sizeof( V_51 ) ,
L_58 , V_50 ) ;
F_14 ( L_59 , V_53 ) ;
F_14 ( L_60 , V_51 ) ;
F_14 ( L_61 , V_4 ) ;
F_14 ( L_62 , V_6 ) ;
F_14 ( L_63 , V_43 ) ;
F_14 ( L_64 , V_7 ? : L_65 ) ;
F_14 ( L_66 ,
( V_14 [ 0 ] == '-' ) ? V_14 : V_52 ) ;
F_16 ( L_67 , V_54 ) ;
V_24 = F_8 ( V_54 , & V_48 , & V_47 ) ;
if ( V_24 ) {
F_10 ( L_68 , V_14 ) ;
F_10 ( L_69 ) ;
F_10 ( L_70 ) ;
F_10 ( L_71 , V_14 ) ;
F_10 ( L_72 ) ;
goto V_35;
}
free ( V_7 ) ;
free ( V_43 ) ;
if ( ! V_45 )
free ( V_48 ) ;
else
* V_45 = V_48 ;
if ( V_46 )
* V_46 = V_47 ;
return 0 ;
V_35:
free ( V_7 ) ;
free ( V_43 ) ;
free ( V_48 ) ;
if ( V_45 )
* V_45 = NULL ;
if ( V_46 )
* V_46 = 0 ;
return V_24 ;
}
int F_27 ( void )
{
char V_4 [ V_17 ] ;
return F_4 ( V_3 . V_4 , L_51 , V_4 ) ;
}
