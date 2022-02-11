static void
F_1 ( T_1 V_1 , T_1 V_2 )
{
T_2 V_3 = ( T_2 ) V_1 ;
T_3 * V_4 = ( T_3 * ) V_2 ;
const T_4 * V_5 = F_2 ( V_3 ) ;
if ( V_5 && strcmp ( V_4 -> V_6 , V_5 ) == 0 ) {
V_4 -> V_3 = V_3 ;
}
}
static T_5
F_3 ( T_4 * V_7 , const T_4 * V_8 ,
void * V_2 V_9 ,
T_6 T_7 V_9 )
{
T_4 * V_10 [ 4 ] = { NULL , NULL , NULL , NULL } ;
T_4 V_11 [ 4 ] = { ',' , ',' , ',' , '\0' } ;
T_4 * V_12 ;
T_8 V_13 , V_14 ;
T_9 V_15 ;
T_5 V_16 = V_17 ;
T_6 V_18 = FALSE ;
if ( strcmp ( V_7 , V_19 ) == 0 ) {
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
V_12 = strchr ( V_8 , V_11 [ V_13 ] ) ;
if ( V_12 == NULL ) {
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ ) {
F_4 ( V_10 [ V_14 ] ) ;
}
return V_20 ;
}
V_10 [ V_13 ] = F_5 ( V_8 , V_12 - V_8 ) ;
V_8 = V_12 + 1 ;
}
V_15 = F_6 ( V_10 [ 0 ] ) ;
if ( V_15 != NULL ) {
T_3 V_4 ;
T_10 V_21 ;
V_4 . V_6 = V_10 [ 3 ] ;
V_4 . V_3 = NULL ;
V_21 = F_7 ( V_15 ) ;
F_8 ( F_9 ( V_15 ) ,
F_1 , & V_4 ) ;
if ( V_4 . V_3 != NULL || F_10 ( V_10 [ 3 ] , V_22 ) == 0 ) {
V_18 = TRUE ;
}
if ( V_18 ) {
if ( F_11 ( V_21 ) ) {
F_12 ( V_10 [ 0 ] , V_10 [ 1 ] , V_4 . V_3 ) ;
} else {
char * V_23 ;
long V_24 ;
V_24 = strtol ( V_10 [ 1 ] , & V_23 , 0 ) ;
if ( V_23 == V_10 [ 0 ] || * V_23 != '\0' || V_24 < 0 ||
( unsigned long ) V_24 > V_25 ) {
V_16 = V_20 ;
V_18 = FALSE ;
} else
F_13 ( V_10 [ 0 ] , ( T_8 ) V_24 , V_4 . V_3 ) ;
}
}
if ( V_18 ) {
F_14 ( V_10 [ 0 ] , V_21 , V_10 [ 1 ] , NULL , NULL ) ;
}
} else {
V_16 = V_20 ;
}
} else {
V_16 = V_26 ;
}
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
F_4 ( V_10 [ V_13 ] ) ;
}
return V_16 ;
}
void
F_15 ( void )
{
char * V_27 ;
T_11 * V_28 ;
if ( V_29 ) {
F_16 () ;
}
V_27 = F_17 ( V_30 , TRUE ) ;
if ( ( V_28 = F_18 ( V_27 , L_1 ) ) != NULL ) {
F_19 ( V_27 , V_28 , F_3 , NULL ) ;
fclose ( V_28 ) ;
}
F_4 ( V_27 ) ;
}
void
F_14 ( const T_4 * V_31 , T_10 V_21 ,
T_1 V_7 , T_1 V_8 V_9 ,
T_1 V_2 V_9 )
{
T_12 * V_1 ;
V_1 = F_20 ( T_12 , 1 ) ;
V_1 -> V_32 = F_21 ( V_31 ) ;
V_1 -> V_33 = V_21 ;
switch ( V_21 ) {
case V_34 :
case V_35 :
case V_36 :
case V_37 :
V_1 -> V_38 . V_39 = F_22 ( V_7 ) ;
break;
case V_40 :
case V_41 :
case V_42 :
case V_43 :
V_1 -> V_38 . V_44 = F_21 ( ( char * ) V_7 ) ;
break;
default:
F_23 () ;
}
V_29 = F_24 ( V_29 , V_1 ) ;
}
void
F_16 ( void )
{
T_12 * V_1 ;
T_13 * V_45 ;
F_25 ( F_14 , NULL ) ;
for ( V_45 = V_29 ; V_45 ; V_45 = F_26 ( V_45 ) ) {
V_1 = ( T_12 * ) V_45 -> V_46 ;
switch ( V_1 -> V_33 ) {
case V_34 :
case V_35 :
case V_36 :
case V_37 :
F_27 ( V_1 -> V_32 ,
V_1 -> V_38 . V_39 ) ;
break;
case V_40 :
case V_41 :
case V_42 :
case V_43 :
F_28 ( V_1 -> V_32 ,
V_1 -> V_38 . V_44 ) ;
F_4 ( V_1 -> V_38 . V_44 ) ;
break;
default:
F_23 () ;
}
F_4 ( V_1 -> V_32 ) ;
F_4 ( V_1 ) ;
}
F_29 ( V_29 ) ;
V_29 = NULL ;
F_30 () ;
}
static void
F_31 ( const T_4 * V_31 , T_10 V_21 ,
T_1 V_7 , T_1 V_8 , T_1 V_2 )
{
T_11 * V_47 = ( T_11 * ) V_2 ;
T_2 V_48 , V_49 ;
const T_4 * V_50 , * V_51 ;
V_48 = F_32 ( ( V_52 * ) V_8 ) ;
if ( V_48 == NULL )
V_50 = V_22 ;
else
V_50 = F_2 ( V_48 ) ;
V_49 = F_33 ( ( V_52 * ) V_8 ) ;
if ( V_49 == NULL )
V_51 = V_22 ;
else
V_51 = F_2 ( V_49 ) ;
switch ( V_21 ) {
case V_34 :
case V_35 :
case V_36 :
case V_37 :
fprintf ( V_47 ,
V_19 L_2 ,
V_31 , F_22 ( V_7 ) , V_51 ,
V_50 ) ;
break;
case V_40 :
case V_41 :
case V_42 :
case V_43 :
fprintf ( V_47 ,
V_19 L_3 ,
V_31 , ( T_4 * ) V_7 , V_51 ,
V_50 ) ;
break;
default:
F_23 () ;
break;
}
}
int
F_34 ( T_4 * * V_53 )
{
char * V_54 ;
char * V_27 ;
T_11 * V_47 ;
if ( F_35 ( & V_54 ) == - 1 ) {
* V_53 = F_36 ( L_4 ,
V_54 , F_37 ( V_55 ) ) ;
F_4 ( V_54 ) ;
return - 1 ;
}
V_27 = F_17 ( V_30 , TRUE ) ;
if ( ( V_47 = F_18 ( V_27 , L_5 ) ) == NULL ) {
* V_53 = F_36 ( L_6 ,
V_27 , F_37 ( V_55 ) ) ;
F_4 ( V_27 ) ;
return - 1 ;
}
fputs ( L_7 V_56 L_8
L_9
L_10
L_11
L_12 , V_47 ) ;
F_25 ( F_31 , V_47 ) ;
fclose ( V_47 ) ;
return 0 ;
}
