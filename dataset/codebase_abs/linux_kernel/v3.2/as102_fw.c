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
F_3 ( V_12 L_1 ) ;
return - V_13 ;
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
static int F_4 ( struct V_14 * V_15 ,
unsigned char * V_16 ,
const struct V_17 * V_17 ) {
struct V_18 V_19 ;
int V_20 = 0 , V_21 = 0 ;
unsigned char V_10 = 0 ;
F_5 () ;
for ( V_20 = 0 ; V_20 < V_17 -> V_22 ; ) {
int V_23 = 0 , V_24 = 0 ;
V_23 = F_2 (
( V_25 * ) ( V_17 -> V_8 + V_20 ) ,
V_19 . V_26 . V_27 ,
V_19 . V_26 . V_8 ,
& V_24 ,
& V_10 ) ;
if ( V_23 <= 0 )
goto error;
V_20 += V_23 ;
if ( V_20 == V_17 -> V_22 ) {
V_19 . V_28 . V_29 [ 0 ] = 0x00 ;
V_19 . V_28 . V_29 [ 1 ] = 0x03 ;
V_21 = V_15 -> V_30 -> V_31 ( V_15 ,
( V_32 * )
& V_19 , 2 , 0 ) ;
if ( V_21 < 0 )
goto error;
} else {
if ( ! V_10 ) {
V_19 . V_28 . V_29 [ 0 ] = 0x00 ;
V_19 . V_28 . V_29 [ 1 ] = 0x01 ;
V_24 += sizeof( V_19 . V_28 . V_29 ) ;
V_24 += sizeof( V_19 . V_26 . V_27 ) ;
V_21 = V_15 -> V_30 -> V_31 ( V_15 ,
( V_32 * )
& V_19 ,
V_24 ,
0 ) ;
if ( V_21 < 0 )
goto error;
}
}
}
error:
F_6 () ;
return ( V_21 == 0 ) ? V_20 : V_21 ;
}
int F_7 ( struct V_14 * V_15 )
{
int V_21 = - V_13 ;
const struct V_17 * V_17 ;
unsigned char * V_33 = NULL ;
char * V_34 , * V_35 ;
#if F_8 ( V_36 )
struct V_37 * V_38 = V_15 -> V_39 ;
#endif
#if F_8 ( V_40 )
struct V_41 * V_38 = V_15 -> V_42 ;
#endif
F_5 () ;
if ( V_43 ) {
V_34 = V_44 ;
V_35 = V_45 ;
} else {
V_34 = V_46 ;
V_35 = V_47 ;
}
#if F_8 ( V_48 ) || F_8 ( V_49 )
V_33 = F_9 ( V_50 , V_51 ) ;
if ( V_33 == NULL ) {
V_21 = - V_52 ;
goto error;
}
V_21 = F_10 ( & V_17 , V_34 , & V_38 -> V_38 ) ;
if ( V_21 < 0 ) {
F_3 ( V_12 L_2 ,
V_53 , V_34 ) ;
goto error;
}
V_21 = F_4 ( V_15 , V_33 , V_17 ) ;
if ( V_21 < 0 ) {
F_3 ( V_12 L_3 ,
V_53 ) ;
goto error;
}
F_3 ( V_54 L_4 ,
V_53 , V_34 ) ;
F_11 ( V_17 ) ;
F_12 ( 100 ) ;
V_21 = F_10 ( & V_17 , V_35 , & V_38 -> V_38 ) ;
if ( V_21 < 0 ) {
F_3 ( V_12 L_2 ,
V_53 , V_35 ) ;
goto error;
}
V_21 = F_4 ( V_15 , V_33 , V_17 ) ;
if ( V_21 < 0 ) {
F_3 ( V_12 L_5 ,
V_53 ) ;
goto error;
}
F_3 ( V_54 L_4 ,
V_53 , V_35 ) ;
error:
F_13 ( V_33 ) ;
if ( V_17 != NULL )
F_11 ( V_17 ) ;
#endif
F_6 () ;
return V_21 ;
}
