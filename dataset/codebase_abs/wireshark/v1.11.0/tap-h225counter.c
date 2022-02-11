static void
F_1 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
char * V_3 = V_2 -> V_4 ;
memset ( V_2 , 0 , sizeof( T_1 ) ) ;
V_2 -> V_4 = V_3 ;
}
static int
F_2 ( void * V_1 , T_2 * T_3 V_5 , T_4 * T_5 V_5 , const void * V_6 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
const T_6 * V_7 = ( const T_6 * ) V_6 ;
switch ( V_7 -> V_8 ) {
case V_9 :
if( V_7 -> V_10 == - 1 ) {
return 0 ;
}
else if ( V_7 -> V_10 >= V_11 ) {
V_2 -> V_12 [ V_11 ] ++ ;
}
else {
V_2 -> V_12 [ V_7 -> V_10 ] ++ ;
}
if( V_7 -> V_13 == - 1 ) {
break;
}
switch( V_7 -> V_10 ) {
case 2 :
if( V_7 -> V_13 < V_14 )
V_2 -> V_15 [ V_7 -> V_13 ] ++ ;
else
V_2 -> V_15 [ V_14 ] ++ ;
break;
case 5 :
if( V_7 -> V_13 < V_16 )
V_2 -> V_17 [ V_7 -> V_13 ] ++ ;
else
V_2 -> V_17 [ V_16 ] ++ ;
break;
case 6 :
if( V_7 -> V_13 < V_18 )
V_2 -> V_19 [ V_7 -> V_13 ] ++ ;
else
V_2 -> V_19 [ V_18 ] ++ ;
break;
case 8 :
if( V_7 -> V_13 < V_20 )
V_2 -> V_21 [ V_7 -> V_13 ] ++ ;
else
V_2 -> V_21 [ V_20 ] ++ ;
break;
case 11 :
if( V_7 -> V_13 < V_22 )
V_2 -> V_23 [ V_7 -> V_13 ] ++ ;
else
V_2 -> V_23 [ V_22 ] ++ ;
break;
case 14 :
if( V_7 -> V_13 < V_24 )
V_2 -> V_25 [ V_7 -> V_13 ] ++ ;
else
V_2 -> V_25 [ V_24 ] ++ ;
break;
case 15 :
if( V_7 -> V_13 < V_26 )
V_2 -> V_27 [ V_7 -> V_13 ] ++ ;
else
V_2 -> V_27 [ V_26 ] ++ ;
break;
case 17 :
if( V_7 -> V_13 < V_28 )
V_2 -> V_29 [ V_7 -> V_13 ] ++ ;
else
V_2 -> V_29 [ V_28 ] ++ ;
break;
case 20 :
if( V_7 -> V_13 < V_30 )
V_2 -> V_31 [ V_7 -> V_13 ] ++ ;
else
V_2 -> V_31 [ V_30 ] ++ ;
break;
case 29 :
if( V_7 -> V_13 < V_32 )
V_2 -> V_33 [ V_7 -> V_13 ] ++ ;
else
V_2 -> V_33 [ V_32 ] ++ ;
break;
default:
break;
}
break;
case V_34 :
if( V_7 -> V_10 == - 1 ) {
return 0 ;
}
else if ( V_7 -> V_10 >= V_35 ) {
V_2 -> V_36 [ V_35 ] ++ ;
}
else {
V_2 -> V_36 [ V_7 -> V_10 ] ++ ;
}
if( V_7 -> V_13 == - 1 ) {
break;
}
switch( V_7 -> V_10 ) {
case 5 :
if( V_7 -> V_13 < V_37 )
V_2 -> V_38 [ V_7 -> V_13 ] ++ ;
else
V_2 -> V_38 [ V_37 ] ++ ;
break;
case 6 :
if( V_7 -> V_13 < V_39 )
V_2 -> V_40 [ V_7 -> V_13 ] ++ ;
else
V_2 -> V_40 [ V_39 ] ++ ;
break;
default:
break;
}
break;
default:
return 0 ;
}
return 1 ;
}
static void
F_3 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
int V_41 , V_42 ;
printf ( L_1 ) ;
printf ( L_2 ) ;
for( V_41 = 0 ; V_41 <= V_11 ; V_41 ++ ) {
if( V_2 -> V_12 [ V_41 ] != 0 ) {
printf ( L_3 , F_4 ( V_41 , V_43 , L_4 ) , V_2 -> V_12 [ V_41 ] ) ;
switch( V_41 ) {
case 2 :
for( V_42 = 0 ; V_42 <= V_14 ; V_42 ++ ) {
if( V_2 -> V_15 [ V_42 ] != 0 ) {
printf ( L_5 , F_4 ( V_42 , V_44 , L_6 ) , V_2 -> V_15 [ V_42 ] ) ;
}
}
break;
case 5 :
for( V_42 = 0 ; V_42 <= V_16 ; V_42 ++ ) {
if( V_2 -> V_17 [ V_42 ] != 0 ) {
printf ( L_5 , F_4 ( V_42 , V_45 , L_6 ) , V_2 -> V_17 [ V_42 ] ) ;
}
}
break;
case 6 :
for( V_42 = 0 ; V_42 <= V_18 ; V_42 ++ ) {
if( V_2 -> V_19 [ V_42 ] != 0 ) {
printf ( L_5 , F_4 ( V_42 , V_46 , L_6 ) , V_2 -> V_19 [ V_42 ] ) ;
}
}
break;
case 8 :
for( V_42 = 0 ; V_42 <= V_20 ; V_42 ++ ) {
if( V_2 -> V_21 [ V_42 ] != 0 ) {
printf ( L_5 , F_4 ( V_42 , V_47 , L_6 ) , V_2 -> V_21 [ V_42 ] ) ;
}
}
break;
case 11 :
for( V_42 = 0 ; V_42 <= V_22 ; V_42 ++ ) {
if( V_2 -> V_23 [ V_42 ] != 0 ) {
printf ( L_5 , F_4 ( V_42 , V_48 , L_6 ) , V_2 -> V_23 [ V_42 ] ) ;
}
}
break;
case 14 :
for( V_42 = 0 ; V_42 <= V_24 ; V_42 ++ ) {
if( V_2 -> V_25 [ V_42 ] != 0 ) {
printf ( L_5 , F_4 ( V_42 , V_49 , L_6 ) , V_2 -> V_25 [ V_42 ] ) ;
}
}
break;
case 15 :
for( V_42 = 0 ; V_42 <= V_26 ; V_42 ++ ) {
if( V_2 -> V_27 [ V_42 ] != 0 ) {
printf ( L_5 , F_4 ( V_42 , V_50 , L_6 ) , V_2 -> V_27 [ V_42 ] ) ;
}
}
break;
case 17 :
for( V_42 = 0 ; V_42 <= V_28 ; V_42 ++ ) {
if( V_2 -> V_29 [ V_42 ] != 0 ) {
printf ( L_5 , F_4 ( V_42 , V_51 , L_6 ) , V_2 -> V_29 [ V_42 ] ) ;
}
}
break;
case 20 :
for( V_42 = 0 ; V_42 <= V_30 ; V_42 ++ ) {
if( V_2 -> V_31 [ V_42 ] != 0 ) {
printf ( L_5 , F_4 ( V_42 , V_52 , L_6 ) , V_2 -> V_31 [ V_42 ] ) ;
}
}
break;
case 29 :
for( V_42 = 0 ; V_42 <= V_32 ; V_42 ++ ) {
if( V_2 -> V_33 [ V_42 ] != 0 ) {
printf ( L_5 , F_4 ( V_42 , V_53 , L_6 ) , V_2 -> V_33 [ V_42 ] ) ;
}
}
break;
default:
break;
}
}
}
printf ( L_7 ) ;
for( V_41 = 0 ; V_41 <= V_35 ; V_41 ++ ) {
if( V_2 -> V_36 [ V_41 ] != 0 ) {
printf ( L_3 , F_4 ( V_41 , V_54 , L_8 ) , V_2 -> V_36 [ V_41 ] ) ;
switch( V_41 ) {
case 5 :
for( V_42 = 0 ; V_42 <= V_37 ; V_42 ++ ) {
if( V_2 -> V_38 [ V_42 ] != 0 ) {
printf ( L_5 , F_4 ( V_42 , V_55 , L_6 ) , V_2 -> V_38 [ V_42 ] ) ;
}
}
break;
case 6 :
for( V_42 = 0 ; V_42 <= V_39 ; V_42 ++ ) {
if( V_2 -> V_40 [ V_42 ] != 0 ) {
printf ( L_5 , F_4 ( V_42 , V_56 , L_6 ) , V_2 -> V_40 [ V_42 ] ) ;
}
}
break;
default:
break;
}
}
}
printf ( L_9 ) ;
}
static void
F_5 ( const char * V_57 , void * T_7 V_5 )
{
T_1 * V_2 ;
T_8 * V_58 ;
V_2 = F_6 ( T_1 , 1 ) ;
if( ! strncmp ( V_57 , L_10 , 13 ) ) {
V_2 -> V_4 = F_7 ( V_57 + 13 ) ;
} else {
V_2 -> V_4 = NULL ;
}
F_1 ( V_2 ) ;
V_58 = F_8 ( L_11 , V_2 , V_2 -> V_4 , 0 , NULL , F_2 , F_3 ) ;
if( V_58 ) {
F_9 ( V_2 -> V_4 ) ;
F_9 ( V_2 ) ;
fprintf ( V_59 , L_12 ,
V_58 -> V_60 ) ;
F_10 ( V_58 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_11 ( void )
{
F_12 ( L_13 , F_5 , NULL ) ;
}
