static void
F_1 ( void * V_1 )
{
T_1 * V_2 = V_1 ;
T_2 V_3 ;
for( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
V_2 -> V_5 [ V_3 ] . V_6 = 0 ;
V_2 -> V_5 [ V_3 ] . V_7 . V_8 = 0 ;
V_2 -> V_5 [ V_3 ] . V_7 . V_9 = 0 ;
V_2 -> V_5 [ V_3 ] . V_10 . V_8 = 0 ;
V_2 -> V_5 [ V_3 ] . V_10 . V_9 = 0 ;
V_2 -> V_5 [ V_3 ] . V_11 . V_8 = 0 ;
V_2 -> V_5 [ V_3 ] . V_11 . V_9 = 0 ;
}
}
static int
F_2 ( void * V_1 , T_3 * V_12 , T_4 * T_5 V_13 , const void * V_14 )
{
T_1 * V_2 = V_1 ;
const T_6 * V_15 = V_14 ;
T_7 V_16 ;
T_8 * V_17 ;
if( V_15 -> V_18 >= V_2 -> V_4 ) {
return 0 ;
}
if( V_15 -> V_19 ) {
return 0 ;
}
if( ( V_15 -> V_20 != V_2 -> V_21 ) || ( V_15 -> V_22 != V_2 -> V_23 ) ) {
return 0 ;
}
V_17 = & ( V_2 -> V_5 [ V_15 -> V_18 ] ) ;
F_3 ( & V_16 , & V_12 -> V_24 -> V_25 , & V_15 -> V_26 ) ;
if( V_17 -> V_6 == 0 ) {
V_17 -> V_10 . V_8 = V_16 . V_8 ;
V_17 -> V_10 . V_9 = V_16 . V_9 ;
}
if( V_17 -> V_6 == 0 ) {
V_17 -> V_7 . V_8 = V_16 . V_8 ;
V_17 -> V_7 . V_9 = V_16 . V_9 ;
}
if( ( V_16 . V_8 < V_17 -> V_7 . V_8 )
|| ( ( V_16 . V_8 == V_17 -> V_7 . V_8 )
&& ( V_16 . V_9 < V_17 -> V_7 . V_9 ) ) ) {
V_17 -> V_7 . V_8 = V_16 . V_8 ;
V_17 -> V_7 . V_9 = V_16 . V_9 ;
}
if( ( V_16 . V_8 > V_17 -> V_10 . V_8 )
|| ( ( V_16 . V_8 == V_17 -> V_10 . V_8 )
&& ( V_16 . V_9 > V_17 -> V_10 . V_9 ) ) ) {
V_17 -> V_10 . V_8 = V_16 . V_8 ;
V_17 -> V_10 . V_9 = V_16 . V_9 ;
}
V_17 -> V_11 . V_8 += V_16 . V_8 ;
V_17 -> V_11 . V_9 += V_16 . V_9 ;
if( V_17 -> V_11 . V_9 > V_27 ) {
V_17 -> V_11 . V_9 -= V_27 ;
V_17 -> V_11 . V_8 ++ ;
}
V_17 -> V_6 ++ ;
return 1 ;
}
static void
F_4 ( void * V_1 )
{
T_1 * V_2 = V_1 ;
T_2 V_3 ;
T_9 V_28 ;
printf ( L_1 ) ;
printf ( L_2 ) ;
printf ( L_3 , V_2 -> V_20 , V_2 -> V_23 ) ;
printf ( L_4 , V_2 -> V_29 ? V_2 -> V_29 : L_5 ) ;
printf ( L_6 ) ;
for( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
if( V_2 -> V_5 [ V_3 ] . V_6 == 0 ) {
continue;
}
V_28 = ( ( T_9 ) ( V_2 -> V_5 [ V_3 ] . V_11 . V_8 ) ) * V_27 + V_2 -> V_5 [ V_3 ] . V_11 . V_9 ;
V_28 = ( ( V_28 / V_2 -> V_5 [ V_3 ] . V_6 ) + 500 ) / 1000 ;
printf ( L_7 V_30 L_8 V_30 L_9 ,
V_2 -> V_5 [ V_3 ] . V_18 ,
V_2 -> V_5 [ V_3 ] . V_6 ,
( int ) ( V_2 -> V_5 [ V_3 ] . V_7 . V_8 ) , ( V_2 -> V_5 [ V_3 ] . V_7 . V_9 + 500 ) / 1000 ,
( int ) ( V_2 -> V_5 [ V_3 ] . V_10 . V_8 ) , ( V_2 -> V_5 [ V_3 ] . V_10 . V_9 + 500 ) / 1000 ,
V_28 / V_31 , V_28 % V_31
) ;
}
printf ( L_2 ) ;
}
static void *
F_5 ( T_10 * V_32 , T_10 * T_11 V_13 , T_10 * T_12 V_13 )
{
T_13 * V_33 = ( T_13 * ) V_32 ;
if( V_33 -> V_20 != V_34 ) {
return NULL ;
}
if( V_33 -> V_22 != V_35 ) {
return NULL ;
}
if( V_36 == - 1 ) {
V_36 = V_33 -> V_18 ;
V_37 = V_33 -> V_18 ;
}
if( ( V_38 ) V_33 -> V_18 < V_36 ) {
V_36 = V_33 -> V_18 ;
}
if( ( V_38 ) V_33 -> V_18 > V_37 ) {
V_37 = V_33 -> V_18 ;
}
return NULL ;
}
static void
F_6 ( const char * V_39 , void * T_14 V_13 )
{
T_1 * V_2 ;
T_2 V_3 ;
int V_21 , V_23 ;
int V_40 = 0 ;
const char * V_29 = NULL ;
T_15 * V_41 ;
if( sscanf ( V_39 , L_10 , & V_21 , & V_23 , & V_40 ) == 2 ) {
if( V_40 ) {
V_29 = V_39 + V_40 ;
} else {
V_29 = NULL ;
}
} else {
fprintf ( V_42 , L_11 ) ;
exit ( 1 ) ;
}
V_2 = F_7 ( sizeof( T_1 ) ) ;
V_2 -> V_20 = F_8 ( V_21 ) ;
V_2 -> V_21 = V_21 ;
V_2 -> V_23 = V_23 ;
if( V_29 ) {
V_2 -> V_29 = F_9 ( V_29 ) ;
} else {
V_2 -> V_29 = NULL ;
}
V_34 = V_21 ;
V_35 = V_23 ;
V_36 = - 1 ;
V_37 = - 1 ;
F_10 ( V_43 , ( V_44 ) F_5 , NULL ) ;
if( V_36 == - 1 ) {
fprintf ( V_42 , L_12 , V_34 , V_35 ) ;
fprintf ( V_42 , L_13 , V_34 , V_35 ) ;
exit ( 1 ) ;
}
V_2 -> V_4 = V_37 + 1 ;
V_2 -> V_5 = F_7 ( sizeof( T_8 ) * ( V_2 -> V_4 + 1 ) ) ;
for( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
V_2 -> V_5 [ V_3 ] . V_18 = F_11 ( V_21 , V_23 , V_3 ) ;
V_2 -> V_5 [ V_3 ] . V_6 = 0 ;
V_2 -> V_5 [ V_3 ] . V_7 . V_8 = 0 ;
V_2 -> V_5 [ V_3 ] . V_7 . V_9 = 0 ;
V_2 -> V_5 [ V_3 ] . V_10 . V_8 = 0 ;
V_2 -> V_5 [ V_3 ] . V_10 . V_9 = 0 ;
V_2 -> V_5 [ V_3 ] . V_11 . V_8 = 0 ;
V_2 -> V_5 [ V_3 ] . V_11 . V_9 = 0 ;
}
V_41 = F_12 ( L_14 , V_2 , V_29 , 0 , F_1 , F_2 , F_4 ) ;
if( V_41 ) {
F_13 ( V_2 -> V_5 ) ;
F_13 ( V_2 -> V_29 ) ;
F_13 ( V_2 ) ;
fprintf ( V_42 , L_15 ,
V_41 -> V_45 ) ;
F_14 ( V_41 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_15 ( void )
{
F_16 ( L_16 , F_6 , NULL ) ;
}
