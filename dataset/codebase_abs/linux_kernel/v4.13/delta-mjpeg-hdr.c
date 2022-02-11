static char * F_1 ( struct V_1 * V_2 ,
char * V_3 ,
unsigned int V_4 )
{
char * V_5 = V_3 ;
unsigned int V_6 = V_4 ;
if ( ! V_2 )
return L_1 ;
snprintf ( V_5 , V_6 , L_2
L_3
L_4
L_5
L_6
L_7 ,
V_2 -> V_7 ,
V_2 -> V_8 ,
V_2 -> V_9 ,
V_2 -> V_10 ,
V_2 -> V_11 ) ;
return V_3 ;
}
static int F_2 ( struct V_12 * V_13 ,
unsigned char * V_14 , unsigned int V_15 ,
struct V_1 * V_2 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
unsigned int V_19 = 0 ;
if ( V_15 < 64 )
goto V_20;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_7 = F_3 ( * ( V_21 * ) ( V_14 + V_19 ) ) ;
V_19 += sizeof( V_22 ) ;
V_2 -> V_8 = * ( V_23 * ) ( V_14 + V_19 ) ;
V_19 += sizeof( V_23 ) ;
V_2 -> V_10 = F_3 ( * ( V_21 * ) ( V_14 + V_19 ) ) ;
V_19 += sizeof( V_22 ) ;
V_2 -> V_9 = F_3 ( * ( V_21 * ) ( V_14 + V_19 ) ) ;
V_19 += sizeof( V_22 ) ;
V_2 -> V_11 = * ( V_23 * ) ( V_14 + V_19 ) ;
V_19 += sizeof( V_23 ) ;
if ( V_2 -> V_11 >= V_24 ) {
F_4 ( V_17 -> V_18 ,
L_8 ,
V_13 -> V_25 , V_2 -> V_11 ,
V_24 ) ;
return - V_26 ;
}
if ( ( V_19 + V_2 -> V_11 *
sizeof( V_2 -> V_27 [ 0 ] ) ) > V_15 )
goto V_20;
return 0 ;
V_20:
F_4 ( V_17 -> V_18 ,
L_9 ,
V_13 -> V_25 , V_15 ) ;
return - V_28 ;
}
int F_5 ( struct V_12 * V_13 ,
unsigned char * V_14 , unsigned int V_15 ,
struct V_1 * V_2 ,
unsigned int * V_29 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
unsigned char V_3 [ 200 ] ;
unsigned int V_30 = 0 ;
unsigned int V_19 = 0 ;
unsigned int V_31 = 0 ;
if ( V_15 < 2 )
goto V_20;
V_19 = 0 ;
while ( 1 ) {
if ( V_14 [ V_19 ] == V_32 )
switch ( V_14 [ V_19 + 1 ] ) {
case V_33 :
V_31 = 1 ;
* V_29 = V_19 ;
break;
case V_34 :
case V_35 :
if ( ! V_31 ) {
F_4 ( V_17 -> V_18 ,
L_10 ,
V_13 -> V_25 ) ;
return - V_26 ;
}
V_30 = F_2 ( V_13 ,
& V_14 [ V_19 + 2 ] ,
V_15 - ( V_19 + 2 ) ,
V_2 ) ;
if ( V_30 )
goto V_36;
goto V_37;
default:
break;
}
V_19 ++ ;
if ( ( V_19 + 2 ) >= V_15 )
goto V_20;
}
V_37:
F_6 ( V_17 -> V_18 ,
L_11 , V_13 -> V_25 ,
* V_29 ,
F_1 ( V_2 , V_3 , sizeof( V_3 ) ) ) ;
return 0 ;
V_20:
F_4 ( V_17 -> V_18 ,
L_12 ,
V_13 -> V_25 , V_15 ) ;
return - V_28 ;
V_36:
return V_30 ;
}
