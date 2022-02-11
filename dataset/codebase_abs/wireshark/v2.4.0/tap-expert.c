static void
F_1 ( void * V_1 )
{
T_1 V_2 ;
T_2 * V_3 = ( T_2 * ) V_1 ;
F_2 ( V_3 -> V_4 ) ;
V_3 -> V_4 = F_3 ( 100 ) ;
for ( V_2 = 0 ; V_2 < V_5 ; V_2 ++ ) {
F_4 ( V_3 -> V_6 [ V_2 ] , 0 ) ;
}
}
static T_3
F_5 ( void * V_1 , T_4 * T_5 V_7 , T_6 * T_7 V_7 ,
const void * V_8 )
{
const T_8 * V_9 = ( const T_8 * ) V_8 ;
T_2 * V_10 = ( T_2 * ) V_1 ;
T_9 V_11 ;
T_10 V_12 ;
T_10 * V_13 ;
T_11 V_2 ;
switch ( V_9 -> V_14 ) {
case V_15 :
V_11 = V_16 ;
break;
case V_17 :
V_11 = V_18 ;
break;
case V_19 :
V_11 = V_20 ;
break;
case V_21 :
V_11 = V_22 ;
break;
default:
F_6 () ;
return FALSE ;
}
if ( V_11 < V_23 ) {
return TRUE ;
}
for ( V_2 = 0 ; V_2 < V_10 -> V_6 [ V_11 ] -> V_24 ; V_2 ++ ) {
V_13 = & F_7 ( V_10 -> V_6 [ V_11 ] , T_10 , V_2 ) ;
if ( ( strcmp ( V_9 -> V_25 , V_13 -> V_25 ) == 0 ) &&
( strcmp ( V_9 -> V_26 , V_13 -> V_26 ) == 0 ) ) {
V_13 -> V_27 ++ ;
return TRUE ;
}
}
V_13 = & V_12 ;
V_13 -> V_25 = F_8 ( V_10 -> V_4 , V_9 -> V_25 ) ;
V_13 -> V_26 = F_8 ( V_10 -> V_4 , V_9 -> V_26 ) ;
V_13 -> V_28 = V_9 -> V_28 ;
V_13 -> V_27 = 1 ;
F_9 ( V_10 -> V_6 [ V_11 ] , V_12 ) ;
return TRUE ;
}
static void F_10 ( T_12 * V_29 , const T_13 * V_30 )
{
T_11 V_2 ;
T_10 * V_9 ;
int V_31 = 0 ;
T_13 * V_32 ;
if ( V_29 -> V_24 == 0 ) {
return;
}
for ( V_2 = 0 ; V_2 < V_29 -> V_24 ; V_2 ++ ) {
V_9 = & F_7 ( V_29 , T_10 , V_2 ) ;
V_31 += V_9 -> V_27 ;
}
printf ( L_1 , V_30 , V_31 ) ;
printf ( L_2 ) ;
printf ( L_3 ) ;
for ( V_2 = 0 ; V_2 < V_29 -> V_24 ; V_2 ++ ) {
V_9 = & F_7 ( V_29 , T_10 , V_2 ) ;
V_32 = F_11 ( NULL , V_9 -> V_28 , V_33 , L_4 ) ;
printf ( L_5 ,
V_9 -> V_27 ,
V_32 ,
V_9 -> V_25 , V_9 -> V_26 ) ;
F_12 ( NULL , V_32 ) ;
}
}
static void
F_13 ( void * T_14 V_7 )
{
T_2 * V_34 = ( T_2 * ) T_14 ;
F_10 ( V_34 -> V_6 [ V_22 ] , L_6 ) ;
F_10 ( V_34 -> V_6 [ V_20 ] , L_7 ) ;
F_10 ( V_34 -> V_6 [ V_18 ] , L_8 ) ;
F_10 ( V_34 -> V_6 [ V_16 ] , L_9 ) ;
}
static void F_14 ( const char * V_35 , void * T_15 V_7 )
{
const char * args = NULL ;
const char * V_36 = NULL ;
T_16 * V_37 ;
T_2 * V_34 ;
int V_2 ;
if ( strncmp ( V_35 , L_10 , 6 ) == 0 ) {
args = V_35 + 6 ;
}
else {
V_23 = V_5 ;
}
if ( args != NULL ) {
if ( F_15 ( args , L_11 , 6 ) == 0 ) {
V_23 = V_22 ;
args += 6 ;
}
else if ( F_15 ( args , L_12 , 5 ) == 0 ) {
V_23 = V_20 ;
args += 5 ;
} else if ( F_15 ( args , L_13 , 5 ) == 0 ) {
V_23 = V_18 ;
args += 5 ;
} else if ( F_15 ( args , L_14 , 5 ) == 0 ) {
V_23 = V_16 ;
args += 5 ;
}
}
if ( args != NULL ) {
if ( args [ 0 ] == ',' ) {
V_36 = args + 1 ;
}
}
V_34 = F_16 ( T_2 , 1 ) ;
V_34 -> V_4 = F_3 ( 100 ) ;
for ( V_2 = 0 ; V_2 < V_5 ; V_2 ++ ) {
V_34 -> V_6 [ V_2 ] = F_17 ( FALSE , FALSE , sizeof( T_10 ) , 1000 ) ;
}
V_37 = F_18 ( L_10 , V_34 ,
V_36 , 0 ,
F_1 ,
F_5 ,
F_13 ) ;
if ( V_37 ) {
printf ( L_15 , V_37 -> V_38 ) ;
F_19 ( V_37 , TRUE ) ;
F_20 ( V_34 ) ;
exit ( 1 ) ;
}
}
void
F_21 ( void )
{
F_22 ( & V_39 , NULL ) ;
}
