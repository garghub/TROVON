int F_1 ( void * V_1 , const void * V_2 , T_1 V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = V_1 ;
V_2 -= V_4 ;
V_3 += V_4 ;
F_2 ( L_1 , V_3 , ( unsigned ) ( V_3 ) ,
V_2 ) ;
return F_3 ( & V_7 , V_6 , V_2 , V_3 ) ;
}
int F_4 ( void * V_8 , T_1 V_9 ,
unsigned char V_10 ,
const void * V_11 , T_1 V_12 )
{
enum V_13 V_14 ;
V_14 = F_5 ( V_11 , V_12 ) ;
if ( V_14 == V_15 ) {
char V_16 [ 50 ] ;
F_6 ( V_11 , V_12 , V_16 , sizeof( V_16 ) ) ;
F_7 ( L_2 , V_16 ) ;
return - V_17 ;
}
if ( V_14 != V_18 &&
V_14 != V_19 ) {
F_7 ( L_3 , V_14 ) ;
return - V_17 ;
}
return 0 ;
}
int F_8 ( void * V_8 , T_1 V_9 ,
unsigned char V_10 ,
const void * V_11 , T_1 V_12 )
{
struct V_5 * V_6 = V_8 ;
char V_16 [ 50 ] ;
enum V_13 V_14 ;
V_14 = F_5 ( V_11 , V_12 ) ;
switch ( V_14 ) {
case V_20 :
V_6 -> V_21 = L_4 ;
break;
case V_22 :
V_6 -> V_21 = L_5 ;
break;
case V_23 :
V_6 -> V_21 = L_6 ;
break;
case V_24 :
V_6 -> V_21 = L_7 ;
break;
case V_25 :
V_6 -> V_21 = L_8 ;
break;
case V_26 :
V_6 -> V_21 = L_9 ;
break;
case V_27 :
V_6 -> V_21 = L_10 ;
break;
case V_15 :
F_6 ( V_11 , V_12 , V_16 , sizeof( V_16 ) ) ;
F_7 ( L_2 , V_16 ) ;
return - V_17 ;
default:
F_7 ( L_11 , V_14 ) ;
return - V_28 ;
}
return 0 ;
}
int F_9 ( void * V_8 , T_1 V_9 ,
unsigned char V_10 ,
const void * V_11 , T_1 V_12 )
{
struct V_5 * V_6 = V_8 ;
V_6 -> V_29 = F_10 ( V_11 , V_12 , V_30 ) ;
if ( ! V_6 -> V_29 )
return - V_31 ;
V_6 -> V_32 = V_12 ;
return 0 ;
}
