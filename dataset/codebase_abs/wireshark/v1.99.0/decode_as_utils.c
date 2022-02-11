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
char * V_22 ;
long V_23 ;
V_23 = strtol ( V_9 [ 1 ] , & V_22 , 0 ) ;
if ( V_22 == V_9 [ 0 ] || * V_22 != '\0' || V_23 < 0 ||
( unsigned long ) V_23 > V_24 ) {
V_15 = V_19 ;
V_17 = FALSE ;
} else
F_13 ( V_9 [ 0 ] , ( T_8 ) V_23 , V_4 . V_3 ) ;
}
}
if ( V_17 ) {
F_14 ( F_15 ( V_9 [ 0 ] ) , V_20 ,
F_15 ( V_9 [ 1 ] ) , NULL , NULL ) ;
}
} else {
V_15 = V_19 ;
}
} else {
V_15 = V_25 ;
}
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ ) {
F_4 ( V_9 [ V_12 ] ) ;
}
return V_15 ;
}
void
F_16 ( void )
{
char * V_26 ;
T_11 * V_27 ;
if ( V_28 ) {
F_17 () ;
}
V_26 = F_18 ( V_29 , TRUE ) ;
if ( ( V_27 = F_19 ( V_26 , L_1 ) ) != NULL ) {
F_20 ( V_26 , V_27 , F_3 , NULL ) ;
fclose ( V_27 ) ;
}
F_4 ( V_26 ) ;
}
void
F_14 ( const T_5 * V_30 , T_10 V_20 ,
T_1 V_6 , T_1 V_7 V_8 ,
T_1 V_2 V_8 )
{
T_12 * V_1 ;
V_1 = F_21 ( T_12 , 1 ) ;
V_1 -> V_31 = V_30 ;
V_1 -> V_32 = V_20 ;
switch ( V_20 ) {
case V_33 :
case V_34 :
case V_35 :
case V_36 :
V_1 -> V_37 . V_38 = F_22 ( V_6 ) ;
break;
case V_39 :
case V_40 :
case V_41 :
case V_42 :
V_1 -> V_37 . V_43 = ( char * ) V_6 ;
break;
default:
F_23 () ;
}
V_28 = F_24 ( V_28 , V_1 ) ;
}
void
F_17 ( void )
{
T_12 * V_1 ;
T_13 * V_44 ;
F_25 ( F_14 , NULL ) ;
for ( V_44 = V_28 ; V_44 ; V_44 = F_26 ( V_44 ) ) {
V_1 = ( T_12 * ) V_44 -> V_45 ;
switch ( V_1 -> V_32 ) {
case V_33 :
case V_34 :
case V_35 :
case V_36 :
F_27 ( V_1 -> V_31 ,
V_1 -> V_37 . V_38 ) ;
break;
case V_39 :
case V_40 :
case V_41 :
case V_42 :
F_28 ( V_1 -> V_31 ,
V_1 -> V_37 . V_43 ) ;
break;
default:
F_23 () ;
}
F_4 ( V_1 ) ;
}
F_29 ( V_28 ) ;
V_28 = NULL ;
F_30 () ;
}
static void
F_31 ( const T_5 * V_30 , T_10 V_20 ,
T_1 V_6 , T_1 V_7 , T_1 V_2 )
{
T_11 * V_46 = ( T_11 * ) V_2 ;
T_2 V_47 , V_48 ;
const T_5 * V_49 , * V_50 ;
V_47 = F_32 ( ( V_51 * ) V_7 ) ;
if ( V_47 == NULL )
V_49 = V_21 ;
else
V_49 = F_2 ( V_47 ) ;
V_48 = F_33 ( ( V_51 * ) V_7 ) ;
if ( V_48 == NULL )
V_50 = V_21 ;
else
V_50 = F_2 ( V_48 ) ;
switch ( V_20 ) {
case V_33 :
case V_34 :
case V_35 :
case V_36 :
fprintf ( V_46 ,
V_18 L_2 ,
V_30 , F_22 ( V_6 ) , V_50 ,
V_49 ) ;
break;
case V_39 :
case V_40 :
case V_41 :
case V_42 :
fprintf ( V_46 ,
V_18 L_3 ,
V_30 , ( T_5 * ) V_6 , V_50 ,
V_49 ) ;
break;
default:
F_23 () ;
break;
}
}
void
F_34 ( void )
{
char * V_52 ;
char * V_26 ;
T_11 * V_46 ;
if ( F_35 ( & V_52 ) == - 1 ) {
F_36 ( V_53 , V_54 ,
L_4 , V_52 ,
F_37 ( V_55 ) ) ;
F_4 ( V_52 ) ;
return;
}
V_26 = F_18 ( V_29 , TRUE ) ;
if ( ( V_46 = F_19 ( V_26 , L_5 ) ) == NULL ) {
F_36 ( V_53 , V_54 ,
L_6 , V_26 ,
F_37 ( V_55 ) ) ;
F_4 ( V_26 ) ;
return;
}
fputs ( L_7 V_56 L_8
L_9
L_10
L_11
L_12 , V_46 ) ;
F_25 ( F_31 , V_46 ) ;
fclose ( V_46 ) ;
}
