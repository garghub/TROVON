static void F_1 ( T_1 * V_1 , const char * V_2 , T_2 V_3 )
{
char * V_4 = NULL ;
T_2 V_5 ;
V_5 = ( * V_1 ) -> V_6 ( V_1 , V_3 , & V_4 ) ;
if ( V_5 == V_7 ) {
F_2 ( L_1 , V_2 , V_4 ) ;
( * V_1 ) -> V_8 ( V_1 , ( unsigned char * ) V_4 ) ;
} else {
F_2 ( L_2 , V_2 , V_3 ) ;
}
}
static T_2
F_3 ( T_1 * V_1 , void * V_9 , T_3 V_10 , T_4 V_11 ,
T_5 * V_12 , T_4 * V_13 )
{
T_4 V_14 , V_15 = 0 ;
T_4 V_16 = 0 ;
T_6 * V_17 = NULL ;
T_2 V_3 ;
V_3 = ( * V_1 ) -> V_18 ( V_1 , V_10 , & V_16 , & V_17 ) ;
if ( V_3 != V_7 ) {
F_1 ( V_1 , L_3 , V_3 ) ;
return V_3 ;
}
for ( V_14 = 0 ; V_14 < V_16 ; V_14 ++ ) {
if ( V_17 [ V_14 ] . V_19 < V_11 ) {
V_12 [ V_15 ] . V_9 = ( unsigned long ) V_9 ;
V_12 [ V_15 ] . V_20 = V_17 [ V_14 ] . V_20 ;
V_12 [ V_15 ] . V_21 = 0 ;
V_15 ++ ;
} else {
break;
}
}
( * V_1 ) -> V_8 ( V_1 , ( unsigned char * ) V_17 ) ;
* V_13 = V_15 ;
return V_7 ;
}
static T_2
F_4 ( T_1 * V_1 , const void * V_22 , T_5 * * V_12 , int * V_16 )
{
const T_7 * V_23 ;
T_8 * V_24 ;
T_6 * V_25 = NULL ;
T_9 * V_26 ;
T_4 V_13 , V_3 ;
int V_27 = 0 ;
int V_14 , V_28 = 0 ;
if ( ! ( V_12 && V_16 ) )
return V_29 ;
for ( V_23 = V_22 ; V_23 != NULL ; V_23 = V_23 -> V_30 ) {
if ( V_23 -> V_31 == V_32 ) {
V_24 = ( T_8 * ) V_23 ;
for ( V_14 = 0 ; V_14 < V_24 -> V_33 ; V_14 ++ ) {
V_26 = V_24 -> V_34 + V_14 ;
V_13 = 0 ;
V_3 = ( * V_1 ) -> V_18 ( V_1 , V_26 -> V_35 [ 0 ] , & V_13 , & V_25 ) ;
if ( V_3 == V_7 ) {
( * V_1 ) -> V_8 ( V_1 , ( unsigned char * ) V_25 ) ;
V_27 += ( int ) V_13 ;
} else {
F_1 ( V_1 , L_3 , V_3 ) ;
}
}
}
}
if ( V_27 == 0 )
return V_36 ;
* V_12 = malloc ( V_27 * sizeof( * * V_12 ) ) ;
if ( ! * V_12 )
return V_37 ;
for ( V_23 = V_22 ; V_23 != NULL ; V_23 = V_23 -> V_30 ) {
if ( V_23 -> V_31 == V_32 ) {
V_24 = ( T_8 * ) V_23 ;
for ( V_14 = 0 ; V_14 < V_24 -> V_33 ; V_14 ++ ) {
V_26 = V_24 -> V_34 + V_14 ;
V_13 = 0 ;
V_3 = F_3 ( V_1 , V_26 -> V_9 ,
V_26 -> V_35 [ 0 ] ,
V_26 -> V_38 [ 0 ] ,
* V_12 + V_28 ,
& V_13 ) ;
if ( V_3 == V_7 )
V_28 += V_13 ;
}
}
}
* V_16 = V_28 ;
return V_7 ;
}
static void T_10
F_5 ( T_1 * V_1 ,
T_3 V_39 ,
T_4 V_40 ,
void const * V_41 ,
T_4 V_42 ,
T_11 const * V_43 ,
const void * V_22 )
{
T_5 * V_44 = NULL ;
T_12 V_45 ;
char * V_46 = NULL ;
char * V_47 = NULL ;
char * V_48 = NULL ;
char * V_49 = NULL ;
char V_50 [ V_51 ] ;
T_13 V_52 = ( T_13 ) ( V_53 ) V_41 ;
T_2 V_3 ;
int V_16 = 0 ;
T_14 V_54 ;
V_3 = ( * V_1 ) -> V_55 ( V_1 , V_39 ,
& V_45 ) ;
if ( V_3 != V_7 ) {
F_1 ( V_1 , L_4 , V_3 ) ;
return;
}
if ( V_56 && V_43 && V_42 ) {
V_3 = F_4 ( V_1 , V_22 , & V_44 , & V_16 ) ;
if ( V_3 != V_7 ) {
F_2 ( L_5 ) ;
V_16 = 0 ;
}
}
V_3 = ( * V_1 ) -> V_57 ( V_1 , V_45 , & V_49 ) ;
if ( V_3 != V_7 ) {
F_1 ( V_1 , L_6 , V_3 ) ;
goto error;
}
V_3 = ( * V_1 ) -> V_58 ( V_1 , V_45 ,
& V_46 , NULL ) ;
if ( V_3 != V_7 ) {
F_1 ( V_1 , L_7 , V_3 ) ;
goto error;
}
V_3 = ( * V_1 ) -> V_59 ( V_1 , V_39 , & V_47 ,
& V_48 , NULL ) ;
if ( V_3 != V_7 ) {
F_1 ( V_1 , L_8 , V_3 ) ;
goto error;
}
if ( * V_46 == 'L' ) {
int V_60 , V_14 = 0 ;
char * V_61 = strrchr ( V_46 , '/' ) ;
if ( V_61 ) {
for ( V_14 = 0 ; V_14 < ( V_61 - V_46 ) ; V_14 ++ )
V_50 [ V_14 ] = V_46 [ V_14 + 1 ] ;
}
for ( V_60 = 0 ; V_14 < ( V_51 - 1 ) && V_49 && V_60 < strlen ( V_49 ) ; V_60 ++ , V_14 ++ )
V_50 [ V_14 ] = V_49 [ V_60 ] ;
V_50 [ V_14 ] = '\0' ;
} else {
strcpy ( V_50 , V_49 ) ;
}
if ( F_6 ( V_62 , V_52 , V_50 , V_44 , V_16 ) )
F_2 ( L_9 ) ;
V_54 = strlen ( V_47 ) + strlen ( V_46 ) + strlen ( V_48 ) + 2 ;
{
char V_63 [ V_54 ] ;
snprintf ( V_63 , V_54 , L_10 , V_46 , V_47 , V_48 ) ;
if ( F_7 ( V_62 , V_63 , V_52 , V_41 , V_40 ) )
F_2 ( L_11 ) ;
}
error:
( * V_1 ) -> V_8 ( V_1 , ( unsigned char * ) V_47 ) ;
( * V_1 ) -> V_8 ( V_1 , ( unsigned char * ) V_48 ) ;
( * V_1 ) -> V_8 ( V_1 , ( unsigned char * ) V_46 ) ;
( * V_1 ) -> V_8 ( V_1 , ( unsigned char * ) V_49 ) ;
free ( V_44 ) ;
}
static void T_10
F_8 ( T_1 * V_1 ,
char const * V_64 ,
void const * V_41 ,
T_4 V_40 )
{
T_13 V_52 = ( T_13 ) ( unsigned long ) V_41 ;
int V_3 ;
V_3 = F_7 ( V_62 , V_64 , V_52 , V_41 , V_40 ) ;
if ( V_3 )
F_2 ( L_12 ) ;
}
T_15 T_4 T_10
F_9 ( T_16 * V_65 , char * V_66 , void * T_17 V_67 )
{
T_18 V_68 ;
T_19 V_69 ;
T_20 V_70 ;
T_1 * V_1 = NULL ;
T_4 V_3 ;
V_62 = F_10 () ;
if ( ! V_62 ) {
F_2 ( L_13 ) ;
return - 1 ;
}
V_3 = ( * V_65 ) -> GetEnv ( V_65 , ( void * ) & V_1 , V_71 ) ;
if ( V_3 != V_72 ) {
F_2 ( L_14 ) ;
return - 1 ;
}
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_73 = 1 ;
V_3 = ( * V_1 ) -> V_74 ( V_1 , & V_69 ) ;
if ( V_3 != V_7 ) {
F_1 ( V_1 , L_15 , V_3 ) ;
return - 1 ;
}
V_3 = ( * V_1 ) -> V_75 ( V_1 , & V_70 ) ;
if ( V_3 == V_7 && V_70 == V_76 ) {
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_77 = 1 ;
V_69 . V_78 = 1 ;
V_3 = ( * V_1 ) -> V_74 ( V_1 , & V_69 ) ;
if ( V_3 == V_7 )
V_56 = 1 ;
} else if ( V_3 != V_7 )
F_1 ( V_1 , L_16 , V_3 ) ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_68 . V_79 = F_5 ;
V_68 . V_80 = F_8 ;
V_3 = ( * V_1 ) -> V_81 ( V_1 , & V_68 , sizeof( V_68 ) ) ;
if ( V_3 != V_7 ) {
F_1 ( V_1 , L_17 , V_3 ) ;
return - 1 ;
}
V_3 = ( * V_1 ) -> V_82 ( V_1 , V_83 ,
V_84 , NULL ) ;
if ( V_3 != V_7 ) {
F_1 ( V_1 , L_18 , V_3 ) ;
return - 1 ;
}
V_3 = ( * V_1 ) -> V_82 ( V_1 , V_83 ,
V_85 , NULL ) ;
if ( V_3 != V_7 ) {
F_1 ( V_1 , L_19 , V_3 ) ;
return - 1 ;
}
return 0 ;
}
T_15 void T_10
F_11 ( T_16 * V_65 V_67 )
{
int V_3 ;
V_3 = F_12 ( V_62 ) ;
if ( V_3 )
F_13 ( 1 , L_20 ) ;
}
