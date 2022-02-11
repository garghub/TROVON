static unsigned char F_1 ( unsigned char * V_1 , char * V_2 )
{
unsigned char V_3 = 0 ;
char V_4 = tolower ( * V_2 ) - '0' ;
char V_5 = tolower ( * ( V_2 + 1 ) ) - '0' ;
if ( V_4 > 9 )
V_4 -= 7 ;
if ( V_5 > 9 )
V_5 -= 7 ;
* V_1 = V_3 = ( ( V_4 & 0xF ) << 4 ) | ( V_5 & 0xF ) ;
return V_3 ;
}
static int F_2 ( unsigned char * V_6 , unsigned char * V_7 ,
unsigned char * V_8 , int * V_9 ,
unsigned char * V_10 ) {
int V_11 = 0 ;
unsigned char * V_2 , V_1 ;
if ( * V_6 ++ != ':' ) {
F_3 ( L_1 ) ;
return - V_12 ;
}
for ( V_2 = V_6 ; * V_2 != '\n' ; V_2 += 2 ) {
F_1 ( & V_1 , V_2 ) ;
switch ( V_11 ) {
case 0 :
* V_9 = V_1 ;
break;
case 1 :
V_7 [ 2 ] = V_1 ;
break;
case 2 :
V_7 [ 3 ] = V_1 ;
break;
case 3 :
if ( V_1 == 0x04 )
* V_10 = 1 ;
else
* V_10 = 0 ;
break;
case 4 :
case 5 :
if ( * V_10 )
V_7 [ ( V_11 - 4 ) ] = V_1 ;
else
V_8 [ ( V_11 - 4 ) ] = V_1 ;
break;
default:
V_8 [ ( V_11 - 4 ) ] = V_1 ;
break;
}
V_11 ++ ;
}
return ( V_11 * 2 ) + 2 ;
}
static int F_4 ( struct V_13 * V_14 ,
unsigned char * V_15 ,
const struct V_16 * V_16 ) {
struct V_17 V_18 ;
int V_19 = 0 , V_20 = 0 ;
unsigned char V_10 = 0 ;
F_5 () ;
for ( V_19 = 0 ; V_19 < V_16 -> V_21 ; ) {
int V_22 = 0 , V_23 = 0 ;
V_22 = F_2 (
( V_24 * ) ( V_16 -> V_8 + V_19 ) ,
V_18 . V_25 . V_26 ,
V_18 . V_25 . V_8 ,
& V_23 ,
& V_10 ) ;
if ( V_22 <= 0 )
goto error;
V_19 += V_22 ;
if ( V_19 == V_16 -> V_21 ) {
V_18 . V_27 . V_28 [ 0 ] = 0x00 ;
V_18 . V_27 . V_28 [ 1 ] = 0x03 ;
V_20 = V_14 -> V_29 -> V_30 ( V_14 ,
( V_31 * )
& V_18 , 2 , 0 ) ;
if ( V_20 < 0 )
goto error;
} else {
if ( ! V_10 ) {
V_18 . V_27 . V_28 [ 0 ] = 0x00 ;
V_18 . V_27 . V_28 [ 1 ] = 0x01 ;
V_23 += sizeof( V_18 . V_27 . V_28 ) ;
V_23 += sizeof( V_18 . V_25 . V_26 ) ;
V_20 = V_14 -> V_29 -> V_30 ( V_14 ,
( V_31 * )
& V_18 ,
V_23 ,
0 ) ;
if ( V_20 < 0 )
goto error;
}
}
}
error:
F_6 () ;
return ( V_20 == 0 ) ? V_19 : V_20 ;
}
int F_7 ( struct V_13 * V_14 )
{
int V_20 = - V_12 ;
const struct V_16 * V_16 = NULL ;
unsigned char * V_32 = NULL ;
char * V_33 , * V_34 ;
struct V_35 * V_36 = V_14 -> V_37 ;
F_5 () ;
if ( V_38 ) {
V_33 = V_39 ;
V_34 = V_40 ;
} else {
V_33 = V_41 ;
V_34 = V_42 ;
}
V_32 = F_8 ( V_43 , V_44 ) ;
if ( V_32 == NULL ) {
V_20 = - V_45 ;
goto error;
}
V_20 = F_9 ( & V_16 , V_33 , & V_36 -> V_36 ) ;
if ( V_20 < 0 ) {
F_3 ( L_2 ,
V_46 , V_33 ) ;
goto error;
}
V_20 = F_4 ( V_14 , V_32 , V_16 ) ;
if ( V_20 < 0 ) {
F_3 ( L_3 ,
V_46 ) ;
goto error;
}
F_10 ( L_4 ,
V_46 , V_33 ) ;
F_11 ( V_16 ) ;
F_12 ( 100 ) ;
V_20 = F_9 ( & V_16 , V_34 , & V_36 -> V_36 ) ;
if ( V_20 < 0 ) {
F_3 ( L_2 ,
V_46 , V_34 ) ;
goto error;
}
V_20 = F_4 ( V_14 , V_32 , V_16 ) ;
if ( V_20 < 0 ) {
F_3 ( L_5 ,
V_46 ) ;
goto error;
}
F_10 ( L_4 ,
V_46 , V_34 ) ;
error:
F_13 ( V_32 ) ;
F_11 ( V_16 ) ;
F_6 () ;
return V_20 ;
}
