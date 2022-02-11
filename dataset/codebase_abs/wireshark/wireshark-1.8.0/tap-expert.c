static void
F_1 ( void * V_1 )
{
T_1 V_2 ;
T_2 * V_3 = V_1 ;
F_2 ( V_3 -> V_4 ) ;
V_3 -> V_4 = F_3 ( 100 ) ;
for ( V_2 = 0 ; V_2 < V_5 ; V_2 ++ ) {
F_4 ( V_3 -> V_6 [ V_2 ] , 0 ) ;
}
}
static int
F_5 ( void * V_1 , T_3 * T_4 V_7 , T_5 * T_6 V_7 ,
const void * V_8 )
{
T_7 * V_9 = ( T_7 * ) V_8 ;
T_2 * V_10 = V_1 ;
T_8 V_11 ;
T_9 V_12 ;
T_9 * V_13 ;
T_10 V_2 ;
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
return 0 ;
}
if ( V_11 < V_23 ) {
return 1 ;
}
for ( V_2 = 0 ; V_2 < V_10 -> V_6 [ V_11 ] -> V_24 ; V_2 ++ ) {
V_13 = & F_7 ( V_10 -> V_6 [ V_11 ] , T_9 , V_2 ) ;
if ( ( strcmp ( V_9 -> V_25 , V_13 -> V_25 ) == 0 ) &&
( strcmp ( V_9 -> V_26 , V_13 -> V_26 ) == 0 ) ) {
V_13 -> V_27 ++ ;
return 1 ;
}
}
F_8 ( V_10 -> V_6 [ V_11 ] , V_12 ) ;
V_13 = & F_7 ( V_10 -> V_6 [ V_11 ] , T_9 ,
V_10 -> V_6 [ V_11 ] -> V_24 - 1 ) ;
V_13 -> V_25 = F_9 ( V_10 -> V_4 , V_9 -> V_25 ) ;
V_13 -> V_26 = F_9 ( V_10 -> V_4 , V_9 -> V_26 ) ;
V_13 -> V_28 = V_9 -> V_28 ;
V_13 -> V_27 = 1 ;
return 1 ;
}
static void F_10 ( T_11 * V_29 , const T_12 * V_30 )
{
T_10 V_2 ;
T_9 * V_9 ;
int V_31 = 0 ;
if ( V_29 -> V_24 == 0 ) {
return;
}
for ( V_2 = 0 ; V_2 < V_29 -> V_24 ; V_2 ++ ) {
V_9 = & F_7 ( V_29 , T_9 , V_2 ) ;
V_31 += V_9 -> V_27 ;
}
printf ( L_1 , V_30 , V_31 ) ;
printf ( L_2 ) ;
printf ( L_3 ) ;
for ( V_2 = 0 ; V_2 < V_29 -> V_24 ; V_2 ++ ) {
V_9 = & F_7 ( V_29 , T_9 , V_2 ) ;
printf ( L_4 ,
V_9 -> V_27 ,
F_11 ( V_9 -> V_28 , V_32 , L_5 ) ,
V_9 -> V_25 , V_9 -> V_26 ) ;
}
}
static void
F_12 ( void * T_13 V_7 )
{
T_2 * V_33 = ( T_2 * ) T_13 ;
F_10 ( V_33 -> V_6 [ V_22 ] , L_6 ) ;
F_10 ( V_33 -> V_6 [ V_20 ] , L_7 ) ;
F_10 ( V_33 -> V_6 [ V_18 ] , L_8 ) ;
F_10 ( V_33 -> V_6 [ V_16 ] , L_9 ) ;
}
static void F_13 ( const char * V_34 , void * T_14 V_7 )
{
const char * args = NULL ;
const char * V_35 = NULL ;
T_15 * V_36 ;
T_2 * V_33 ;
int V_2 ;
if ( strncmp ( V_34 , L_10 , 6 ) == 0 ) {
args = V_34 + 6 ;
}
else {
V_23 = V_5 ;
}
if ( args != NULL ) {
if ( F_14 ( args , L_11 , 6 ) == 0 ) {
V_23 = V_22 ;
args += 6 ;
}
else if ( F_14 ( args , L_12 , 5 ) == 0 ) {
V_23 = V_20 ;
args += 5 ;
} else if ( F_14 ( args , L_13 , 5 ) == 0 ) {
V_23 = V_18 ;
args += 5 ;
} else if ( F_14 ( args , L_14 , 5 ) == 0 ) {
V_23 = V_16 ;
args += 5 ;
}
}
if ( args != NULL ) {
if ( args [ 0 ] == ',' ) {
V_35 = args + 1 ;
}
}
V_33 = F_15 ( sizeof( T_2 ) ) ;
memset ( V_33 , 0 , sizeof( T_2 ) ) ;
V_33 -> V_4 = F_3 ( 100 ) ;
for ( V_2 = 0 ; V_2 < V_5 ; V_2 ++ ) {
V_33 -> V_6 [ V_2 ] = F_16 ( FALSE , FALSE , sizeof( T_7 ) , 1000 ) ;
}
V_36 = F_17 ( L_10 , V_33 ,
V_35 , 0 ,
F_1 ,
F_5 ,
F_12 ) ;
if ( V_36 ) {
printf ( L_15 , V_36 -> V_37 ) ;
F_18 ( V_36 , TRUE ) ;
F_19 ( V_33 ) ;
exit ( 1 ) ;
}
}
void
F_20 ( void )
{
F_21 ( L_10 , F_13 , NULL ) ;
}
