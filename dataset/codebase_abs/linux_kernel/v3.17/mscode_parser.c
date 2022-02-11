int F_1 ( struct V_1 * V_2 )
{
const void * V_3 ;
T_1 V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , & V_3 , & V_4 , 1 ) ;
if ( V_5 ) {
F_3 ( L_1 ) ;
return V_5 ;
}
F_4 ( L_2 , V_4 , ( unsigned ) ( V_4 ) ,
V_3 ) ;
return F_5 ( & V_7 , V_2 , V_3 , V_4 ) ;
}
int F_6 ( void * V_8 , T_1 V_9 ,
unsigned char V_10 ,
const void * V_11 , T_1 V_12 )
{
enum V_13 V_14 ;
V_14 = F_7 ( V_11 , V_12 ) ;
if ( V_14 == V_15 ) {
char V_16 [ 50 ] ;
F_8 ( V_11 , V_12 , V_16 , sizeof( V_16 ) ) ;
F_9 ( L_3 , V_16 ) ;
return - V_17 ;
}
if ( V_14 != V_18 &&
V_14 != V_19 ) {
F_9 ( L_4 , V_14 ) ;
return - V_17 ;
}
return 0 ;
}
int F_10 ( void * V_8 , T_1 V_9 ,
unsigned char V_10 ,
const void * V_11 , T_1 V_12 )
{
struct V_1 * V_2 = V_8 ;
char V_16 [ 50 ] ;
enum V_13 V_14 ;
V_14 = F_7 ( V_11 , V_12 ) ;
switch ( V_14 ) {
case V_20 :
V_2 -> V_21 = V_22 ;
break;
case V_23 :
V_2 -> V_21 = V_24 ;
break;
case V_25 :
V_2 -> V_21 = V_26 ;
break;
case V_27 :
V_2 -> V_21 = V_28 ;
break;
case V_15 :
F_8 ( V_11 , V_12 , V_16 , sizeof( V_16 ) ) ;
F_9 ( L_3 , V_16 ) ;
return - V_17 ;
default:
F_9 ( L_5 , V_14 ) ;
return - V_29 ;
}
return 0 ;
}
int F_11 ( void * V_8 , T_1 V_9 ,
unsigned char V_10 ,
const void * V_11 , T_1 V_12 )
{
struct V_1 * V_2 = V_8 ;
V_2 -> V_30 = V_11 ;
V_2 -> V_31 = V_12 ;
return 0 ;
}
