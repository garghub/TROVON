static void
F_1 ( T_1 V_1 , T_1 V_2 )
{
T_2 V_3 = ( T_2 ) V_1 ;
T_3 * V_4 = ( T_3 * ) V_2 ;
if ( strcmp ( V_4 -> V_5 , F_2 ( V_3 ) ) == 0 ) {
V_4 -> V_3 = V_3 ;
}
}
static T_4
F_3 ( T_5 * V_6 , const T_5 * V_7 ,
void * V_2 V_8 ,
T_6 T_7 V_8 )
{
T_5 * V_9 [ 4 ] = { NULL , NULL , NULL , NULL } ;
T_5 V_10 [ 4 ] = { ',' , ',' , ',' , '\0' } ;
T_5 * V_11 ;
T_8 V_12 , V_13 ;
T_9 V_14 ;
T_4 V_15 = V_16 ;
T_6 V_17 = FALSE ;
if ( strcmp ( V_6 , V_18 ) == 0 ) {
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ ) {
V_11 = strchr ( V_7 , V_10 [ V_12 ] ) ;
if ( V_11 == NULL ) {
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
F_4 ( V_9 [ V_13 ] ) ;
}
return V_19 ;
}
V_9 [ V_12 ] = F_5 ( V_7 , V_11 - V_7 ) ;
V_7 = V_11 + 1 ;
}
V_14 = F_6 ( V_9 [ 0 ] ) ;
if ( V_14 != NULL ) {
T_3 V_4 ;
T_10 V_20 ;
V_4 . V_5 = V_9 [ 3 ] ;
V_4 . V_3 = NULL ;
V_20 = F_7 ( V_14 ) ;
F_8 ( F_9 ( V_14 ) ,
F_1 , & V_4 ) ;
if ( V_4 . V_3 != NULL || F_10 ( V_9 [ 3 ] , V_21 ) == 0 ) {
V_17 = TRUE ;
}
if ( V_17 ) {
if ( F_11 ( V_20 ) ) {
F_12 ( V_9 [ 0 ] , V_9 [ 1 ] , V_4 . V_3 ) ;
} else {
F_13 ( V_9 [ 0 ] , atoi ( V_9 [ 1 ] ) , V_4 . V_3 ) ;
}
F_14 ( F_15 ( V_9 [ 0 ] ) , V_20 ,
F_15 ( V_9 [ 1 ] ) , NULL , NULL ) ;
}
} else {
V_15 = V_19 ;
}
} else {
V_15 = V_22 ;
}
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ ) {
F_4 ( V_9 [ V_12 ] ) ;
}
return V_15 ;
}
void
F_16 ( void )
{
char * V_23 ;
T_11 * V_24 ;
if ( V_25 ) {
F_17 () ;
}
V_23 = F_18 ( V_26 , TRUE ) ;
if ( ( V_24 = F_19 ( V_23 , L_1 ) ) != NULL ) {
F_20 ( V_23 , V_24 , F_3 , NULL ) ;
fclose ( V_24 ) ;
}
F_4 ( V_23 ) ;
}
void
F_14 ( const T_5 * V_27 , T_10 V_20 ,
T_1 V_6 , T_1 V_7 V_8 ,
T_1 V_2 V_8 )
{
T_12 * V_1 ;
V_1 = F_21 ( T_12 , 1 ) ;
V_1 -> V_28 = V_27 ;
V_1 -> V_29 = V_20 ;
switch ( V_20 ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
V_1 -> V_34 . V_35 = F_22 ( V_6 ) ;
break;
case V_36 :
case V_37 :
case V_38 :
case V_39 :
V_1 -> V_34 . V_40 = ( char * ) V_6 ;
break;
default:
F_23 () ;
}
V_25 = F_24 ( V_25 , V_1 ) ;
}
void
F_17 ( void )
{
T_12 * V_1 ;
T_13 * V_41 ;
F_25 ( F_14 , NULL ) ;
for ( V_41 = V_25 ; V_41 ; V_41 = F_26 ( V_41 ) ) {
V_1 = ( T_12 * ) V_41 -> V_42 ;
switch ( V_1 -> V_29 ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
F_27 ( V_1 -> V_28 ,
V_1 -> V_34 . V_35 ) ;
break;
case V_36 :
case V_37 :
case V_38 :
case V_39 :
F_28 ( V_1 -> V_28 ,
V_1 -> V_34 . V_40 ) ;
break;
default:
F_23 () ;
}
F_4 ( V_1 ) ;
}
F_29 ( V_25 ) ;
V_25 = NULL ;
F_30 () ;
}
T_11 *
F_31 ( void ) {
char * V_43 ;
char * V_23 ;
T_11 * V_44 ;
if ( F_32 ( & V_43 ) == - 1 ) {
F_33 ( V_45 , V_46 ,
L_2 , V_43 ,
F_34 ( V_47 ) ) ;
F_4 ( V_43 ) ;
return NULL ;
}
V_23 = F_18 ( V_26 , TRUE ) ;
if ( ( V_44 = F_19 ( V_23 , L_3 ) ) == NULL ) {
F_33 ( V_45 , V_46 ,
L_4 , V_23 ,
F_34 ( V_47 ) ) ;
F_4 ( V_23 ) ;
return NULL ;
}
fputs ( L_5 V_48 L_6
L_7
L_8
L_9
L_10 , V_44 ) ;
return V_44 ;
}
void
F_35 ( T_11 * V_44 , const char * V_27 , const char * V_49 , const char * V_50 , const char * V_51 ) {
fprintf ( V_44 ,
V_18 L_11 ,
V_27 , V_49 , V_50 , V_51 ) ;
}
