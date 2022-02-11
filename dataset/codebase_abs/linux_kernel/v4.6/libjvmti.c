static T_1
F_1 ( T_2 * V_1 , void * V_2 , T_3 V_3 , T_4 V_4 ,
T_5 * V_5 , T_4 * V_6 )
{
T_4 V_7 , V_8 = 0 ;
T_4 V_9 = 0 ;
T_6 * V_10 = NULL ;
T_1 V_11 ;
V_11 = ( * V_1 ) -> V_12 ( V_1 , V_3 , & V_9 , & V_10 ) ;
if ( V_11 != V_13 )
return V_11 ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
if ( V_10 [ V_7 ] . V_14 < V_4 ) {
V_5 [ V_8 ] . V_2 = ( unsigned long ) V_2 ;
V_5 [ V_8 ] . V_15 = V_10 [ V_7 ] . V_15 ;
V_5 [ V_8 ] . V_16 = 0 ;
V_8 ++ ;
} else {
break;
}
}
( * V_1 ) -> V_17 ( V_1 , ( unsigned char * ) V_10 ) ;
* V_6 = V_8 ;
return V_13 ;
}
static T_1
F_2 ( T_2 * V_1 , const void * V_18 , T_5 * * V_5 , int * V_9 )
{
const T_7 * V_19 ;
T_8 * V_20 ;
T_6 * V_21 = NULL ;
T_9 * V_22 ;
T_4 V_6 , V_11 ;
int V_23 = 0 ;
int V_7 , V_24 = 0 ;
if ( ! ( V_5 && V_9 ) )
return V_25 ;
for ( V_19 = V_18 ; V_19 != NULL ; V_19 = V_19 -> V_26 ) {
if ( V_19 -> V_27 == V_28 ) {
V_20 = ( T_8 * ) V_19 ;
for ( V_7 = 0 ; V_7 < V_20 -> V_29 ; V_7 ++ ) {
V_22 = V_20 -> V_30 + V_7 ;
V_6 = 0 ;
V_11 = ( * V_1 ) -> V_12 ( V_1 , V_22 -> V_31 [ 0 ] , & V_6 , & V_21 ) ;
if ( V_11 == V_13 ) {
( * V_1 ) -> V_17 ( V_1 , ( unsigned char * ) V_21 ) ;
V_23 += ( int ) V_6 ;
}
}
}
}
if ( V_23 == 0 )
return V_32 ;
* V_5 = malloc ( V_23 * sizeof( * * V_5 ) ) ;
if ( ! * V_5 )
return V_33 ;
for ( V_19 = V_18 ; V_19 != NULL ; V_19 = V_19 -> V_26 ) {
if ( V_19 -> V_27 == V_28 ) {
V_20 = ( T_8 * ) V_19 ;
for ( V_7 = 0 ; V_7 < V_20 -> V_29 ; V_7 ++ ) {
V_22 = V_20 -> V_30 + V_7 ;
V_6 = 0 ;
V_11 = F_1 ( V_1 , V_22 -> V_2 ,
V_22 -> V_31 [ 0 ] ,
V_22 -> V_34 [ 0 ] ,
* V_5 + V_24 ,
& V_6 ) ;
if ( V_11 == V_13 )
V_24 += V_6 ;
}
}
}
* V_9 = V_24 ;
return V_13 ;
}
static void T_10
F_3 ( T_2 * V_1 ,
T_3 V_35 ,
T_4 V_36 ,
void const * V_37 ,
T_4 V_38 ,
T_11 const * V_39 ,
const void * V_18 )
{
T_5 * V_40 = NULL ;
T_12 V_41 ;
char * V_42 = NULL ;
char * V_43 = NULL ;
char * V_44 = NULL ;
char * V_45 = NULL ;
char V_46 [ V_47 ] ;
T_13 V_48 = ( T_13 ) ( V_49 ) V_37 ;
T_1 V_11 ;
int V_9 = 0 ;
T_14 V_50 ;
V_11 = ( * V_1 ) -> V_51 ( V_1 , V_35 ,
& V_41 ) ;
if ( V_11 != V_13 ) {
F_4 ( L_1 ) ;
return;
}
if ( V_52 && V_39 && V_38 ) {
V_11 = F_2 ( V_1 , V_18 , & V_40 , & V_9 ) ;
if ( V_11 != V_13 ) {
F_4 ( L_2 ) ;
V_9 = 0 ;
}
}
V_11 = ( * V_1 ) -> V_53 ( V_1 , V_41 , & V_45 ) ;
if ( V_11 != V_13 ) {
F_4 ( L_3 , V_11 ) ;
goto error;
}
V_11 = ( * V_1 ) -> V_54 ( V_1 , V_41 ,
& V_42 , NULL ) ;
if ( V_11 != V_13 ) {
F_4 ( L_4 ) ;
goto error;
}
V_11 = ( * V_1 ) -> V_55 ( V_1 , V_35 , & V_43 ,
& V_44 , NULL ) ;
if ( V_11 != V_13 ) {
F_4 ( L_5 ) ;
goto error;
}
if ( * V_42 == 'L' ) {
int V_56 , V_7 = 0 ;
char * V_57 = strrchr ( V_42 , '/' ) ;
if ( V_57 ) {
for ( V_7 = 0 ; V_7 < ( V_57 - V_42 ) ; V_7 ++ )
V_46 [ V_7 ] = V_42 [ V_7 + 1 ] ;
}
for ( V_56 = 0 ; V_7 < ( V_47 - 1 ) && V_45 && V_56 < strlen ( V_45 ) ; V_56 ++ , V_7 ++ )
V_46 [ V_7 ] = V_45 [ V_56 ] ;
V_46 [ V_7 ] = '\0' ;
} else {
strcpy ( V_46 , V_45 ) ;
}
if ( F_5 ( V_58 , V_48 , V_46 , V_40 , V_9 ) )
F_4 ( L_6 ) ;
V_50 = strlen ( V_43 ) + strlen ( V_42 ) + strlen ( V_44 ) + 2 ;
{
char V_59 [ V_50 ] ;
snprintf ( V_59 , V_50 , L_7 , V_42 , V_43 , V_44 ) ;
if ( F_6 ( V_58 , V_59 , V_48 , V_37 , V_36 ) )
F_4 ( L_8 ) ;
}
error:
( * V_1 ) -> V_17 ( V_1 , ( unsigned char * ) V_43 ) ;
( * V_1 ) -> V_17 ( V_1 , ( unsigned char * ) V_44 ) ;
( * V_1 ) -> V_17 ( V_1 , ( unsigned char * ) V_42 ) ;
( * V_1 ) -> V_17 ( V_1 , ( unsigned char * ) V_45 ) ;
free ( V_40 ) ;
}
static void T_10
F_7 ( T_2 * V_1 ,
char const * V_60 ,
void const * V_37 ,
T_4 V_36 )
{
T_13 V_48 = ( T_13 ) ( unsigned long ) V_37 ;
int V_11 ;
V_11 = F_6 ( V_58 , V_60 , V_48 , V_37 , V_36 ) ;
if ( V_11 )
F_4 ( L_9 ) ;
}
T_15 T_4 T_10
F_8 ( T_16 * V_61 , char * V_62 , void * T_17 V_63 )
{
T_18 V_64 ;
T_19 V_65 ;
T_20 V_66 ;
T_2 * V_1 = NULL ;
T_4 V_11 ;
V_58 = F_9 () ;
if ( ! V_58 ) {
F_4 ( L_10 ) ;
return - 1 ;
}
V_11 = ( * V_61 ) -> GetEnv ( V_61 , ( void * ) & V_1 , V_67 ) ;
if ( V_11 != V_68 ) {
F_4 ( L_11 ) ;
return - 1 ;
}
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_69 = 1 ;
V_11 = ( * V_1 ) -> V_70 ( V_1 , & V_65 ) ;
if ( V_11 != V_13 ) {
F_4 ( L_12 ) ;
return - 1 ;
}
V_11 = ( * V_1 ) -> V_71 ( V_1 , & V_66 ) ;
if ( V_11 == V_13 && V_66 == V_72 ) {
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_73 = 1 ;
V_65 . V_74 = 1 ;
V_11 = ( * V_1 ) -> V_70 ( V_1 , & V_65 ) ;
if ( V_11 == V_13 )
V_52 = 1 ;
}
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . V_75 = F_3 ;
V_64 . V_76 = F_7 ;
V_11 = ( * V_1 ) -> V_77 ( V_1 , & V_64 , sizeof( V_64 ) ) ;
if ( V_11 != V_13 ) {
F_4 ( L_13 ) ;
return - 1 ;
}
V_11 = ( * V_1 ) -> V_78 ( V_1 , V_79 ,
V_80 , NULL ) ;
if ( V_11 != V_13 ) {
F_4 ( L_14 ) ;
return - 1 ;
}
V_11 = ( * V_1 ) -> V_78 ( V_1 , V_79 ,
V_81 , NULL ) ;
if ( V_11 != V_13 ) {
F_4 ( L_15 ) ;
return - 1 ;
}
return 0 ;
}
T_15 void T_10
F_10 ( T_16 * V_61 V_63 )
{
int V_11 ;
V_11 = F_11 ( V_58 ) ;
if ( V_11 )
F_12 ( 1 , L_16 ) ;
}
