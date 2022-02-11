static void F_1 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int * V_3 , unsigned int * V_4 )
{
switch ( V_2 ) {
case 32000 :
* V_4 = 4096 ;
break;
case 44100 :
* V_4 = 6272 ;
break;
case 48000 :
* V_4 = 6144 ;
break;
}
* V_3 = ( ( V_1 * * V_4 ) / ( 128 * V_2 ) ) * 1000 ;
}
static int F_2 ( struct V_5 * V_5 )
{
unsigned int V_3 = 0 ;
unsigned int V_4 = 0 ;
F_1 ( V_5 -> V_1 , V_5 -> V_6 , & V_3 , & V_4 ) ;
F_3 ( V_5 -> V_7 , V_8 , ( V_4 >> 16 ) & 0xf ) ;
F_3 ( V_5 -> V_7 , V_9 , ( V_4 >> 8 ) & 0xff ) ;
F_3 ( V_5 -> V_7 , V_10 , V_4 & 0xff ) ;
F_3 ( V_5 -> V_7 , V_11 ,
( V_3 >> 16 ) & 0xf ) ;
F_3 ( V_5 -> V_7 , V_12 ,
( V_3 >> 8 ) & 0xff ) ;
F_3 ( V_5 -> V_7 , V_13 ,
V_3 & 0xff ) ;
return 0 ;
}
int F_4 ( struct V_14 * V_15 , void * V_16 ,
struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_5 * V_5 = F_5 ( V_15 ) ;
unsigned int V_21 , V_22 = 0 ;
unsigned int V_23 ;
unsigned int V_24 ;
unsigned int V_25 ;
switch ( V_20 -> V_26 ) {
case 32000 :
V_24 = V_27 ;
break;
case 44100 :
V_24 = V_28 ;
break;
case 48000 :
V_24 = V_29 ;
break;
case 88200 :
V_24 = V_30 ;
break;
case 96000 :
V_24 = V_31 ;
break;
case 176400 :
V_24 = V_32 ;
break;
case 192000 :
V_24 = V_33 ;
break;
default:
return - V_34 ;
}
switch ( V_20 -> V_35 ) {
case 16 :
V_25 = V_36 ;
break;
case 18 :
V_25 = V_37 ;
break;
case 20 :
V_25 = V_38 ;
break;
case 24 :
V_25 = V_39 ;
break;
default:
return - V_34 ;
}
switch ( V_18 -> V_18 ) {
case V_40 :
V_21 = V_41 ;
V_22 = V_42 ;
break;
case V_43 :
V_21 = V_41 ;
V_22 = V_44 ;
break;
case V_45 :
V_21 = V_41 ;
V_22 = V_46 ;
break;
default:
return - V_34 ;
}
V_23 = V_18 -> V_47 ;
F_6 ( V_5 -> V_7 , V_48 , 0x70 ,
V_21 << 4 ) ;
F_6 ( V_5 -> V_7 , V_49 , F_7 ( 6 ) ,
V_23 << 6 ) ;
F_6 ( V_5 -> V_7 , V_50 , 0x03 ,
V_22 ) ;
V_5 -> V_21 = V_21 ;
V_5 -> V_6 = V_20 -> V_26 ;
F_2 ( V_5 ) ;
F_6 ( V_5 -> V_7 , V_51 ,
V_52 , V_25 ) ;
F_6 ( V_5 -> V_7 , V_53 ,
V_54 , V_24 << 4 ) ;
F_3 ( V_5 -> V_7 , 0x73 , 0x1 ) ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 , void * V_16 )
{
struct V_5 * V_5 = F_5 ( V_15 ) ;
F_6 ( V_5 -> V_7 , V_49 ,
F_7 ( 7 ) , 0 ) ;
F_6 ( V_5 -> V_7 , V_55 ,
F_7 ( 5 ) , F_7 ( 5 ) ) ;
F_6 ( V_5 -> V_7 , V_56 ,
F_7 ( 5 ) , F_7 ( 5 ) ) ;
F_6 ( V_5 -> V_7 , V_56 ,
F_7 ( 6 ) , F_7 ( 6 ) ) ;
F_6 ( V_5 -> V_7 , V_57 ,
F_7 ( 5 ) , F_7 ( 5 ) ) ;
F_6 ( V_5 -> V_7 , V_56 ,
F_7 ( 3 ) , F_7 ( 3 ) ) ;
F_6 ( V_5 -> V_7 , F_9 ( 0 ) ,
F_7 ( 7 ) | F_7 ( 6 ) , F_7 ( 7 ) ) ;
F_6 ( V_5 -> V_7 , F_9 ( 1 ) ,
F_7 ( 5 ) , 0 ) ;
return 0 ;
}
static void F_10 ( struct V_14 * V_15 , void * V_16 )
{
}
int F_11 ( struct V_14 * V_15 , struct V_5 * V_5 )
{
V_5 -> V_58 = F_12 ( V_15 ,
V_59 ,
V_60 ,
& V_61 ,
sizeof( V_61 ) ) ;
return F_13 ( V_5 -> V_58 ) ;
}
void F_14 ( struct V_5 * V_5 )
{
if ( V_5 -> V_58 ) {
F_15 ( V_5 -> V_58 ) ;
V_5 -> V_58 = NULL ;
}
}
