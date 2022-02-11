static void
F_1 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
int V_3 ;
for( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_2 -> V_5 [ V_3 ] . V_6 . V_7 = 0 ;
V_2 -> V_5 [ V_3 ] . V_6 . V_8 = 0 ;
V_2 -> V_5 [ V_3 ] . V_6 . V_9 = 0 ;
V_2 -> V_5 [ V_3 ] . V_6 . V_10 . V_11 = 0 ;
V_2 -> V_5 [ V_3 ] . V_6 . V_10 . V_12 = 0 ;
V_2 -> V_5 [ V_3 ] . V_6 . V_13 . V_11 = 0 ;
V_2 -> V_5 [ V_3 ] . V_6 . V_13 . V_12 = 0 ;
V_2 -> V_5 [ V_3 ] . V_6 . V_14 . V_11 = 0 ;
V_2 -> V_5 [ V_3 ] . V_6 . V_14 . V_12 = 0 ;
V_2 -> V_5 [ V_3 ] . V_15 = 0 ;
V_2 -> V_5 [ V_3 ] . V_16 = 0 ;
V_2 -> V_5 [ V_3 ] . V_17 = 0 ;
V_2 -> V_5 [ V_3 ] . V_18 = 0 ;
}
}
static int
F_2 ( void * V_1 , T_2 * T_3 V_19 , T_4 * T_5 V_19 , const void * V_20 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
const T_6 * V_21 = V_20 ;
T_7 V_22 = V_23 ;
T_8 V_24 = V_25 ;
if ( V_21 -> V_26 != V_27 || V_21 -> V_28 == - 1 ) {
return 0 ;
}
if ( V_21 -> V_28 < 21 ) {
V_24 = V_21 -> V_28 / 3 ;
V_22 = V_21 -> V_28 % 3 ;
}
else {
return 0 ;
}
switch( V_22 ) {
case V_29 :
if( V_21 -> V_30 ) {
V_2 -> V_5 [ V_24 ] . V_17 ++ ;
}
else {
V_2 -> V_5 [ V_24 ] . V_15 ++ ;
}
break;
case V_31 :
case V_32 :
if( V_21 -> V_30 ) {
V_2 -> V_5 [ V_24 ] . V_18 ++ ;
}
else if ( ! V_21 -> V_33 ) {
V_2 -> V_5 [ V_24 ] . V_16 ++ ;
}
else {
V_2 -> V_5 [ V_24 ] . V_15 -- ;
F_3 ( & ( V_2 -> V_5 [ V_24 ] . V_6 ) , & ( V_21 -> V_34 ) , T_3 ) ;
}
break;
default:
return 0 ;
}
return 1 ;
}
static void
F_4 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
int V_3 ;
T_9 * V_35 ;
printf ( L_1 ) ;
printf ( L_2 ) ;
printf ( L_3 ) ;
for( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_35 = & ( V_2 -> V_5 [ V_3 ] . V_6 ) ;
if( V_35 -> V_7 ) {
printf ( L_4 ,
F_5 ( V_3 , V_36 , L_5 ) , V_35 -> V_7 ,
F_6 ( & ( V_35 -> V_10 ) ) , F_6 ( & ( V_35 -> V_13 ) ) ,
F_7 ( & ( V_35 -> V_14 ) , V_35 -> V_7 ) ,
V_35 -> V_8 , V_35 -> V_9
) ;
}
}
printf ( L_6 ) ;
printf ( L_7 ) ;
for( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_35 = & ( V_2 -> V_5 [ V_3 ] . V_6 ) ;
if( V_35 -> V_7 ) {
printf ( L_8 ,
F_5 ( V_3 , V_36 , L_5 ) ,
V_2 -> V_5 [ V_3 ] . V_15 , V_2 -> V_5 [ V_3 ] . V_16 ,
V_2 -> V_5 [ V_3 ] . V_17 , V_2 -> V_5 [ V_3 ] . V_18
) ;
}
}
printf ( L_6 ) ;
}
static void
F_8 ( const char * V_37 , void * T_10 V_19 )
{
T_1 * V_2 ;
T_11 * V_38 ;
V_2 = F_9 ( sizeof( T_1 ) ) ;
if( ! strncmp ( V_37 , L_9 , 9 ) ) {
V_2 -> V_39 = F_10 ( V_37 + 9 ) ;
} else {
V_2 -> V_39 = NULL ;
}
F_1 ( V_2 ) ;
V_38 = F_11 ( L_10 , V_2 , V_2 -> V_39 , 0 , NULL , F_2 , F_4 ) ;
if( V_38 ) {
F_12 ( V_2 -> V_39 ) ;
F_12 ( V_2 ) ;
fprintf ( V_40 , L_11 ,
V_38 -> V_41 ) ;
F_13 ( V_38 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_14 ( void )
{
F_15 ( L_12 , F_8 , NULL ) ;
}
