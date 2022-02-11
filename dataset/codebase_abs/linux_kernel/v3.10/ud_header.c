void F_1 ( int V_1 ,
int V_2 ,
int V_3 ,
int V_4 ,
int V_5 ,
int V_6 ,
struct V_7 * V_8 )
{
memset ( V_8 , 0 , sizeof *V_8 ) ;
if ( V_2 ) {
T_1 V_9 ;
V_8 -> V_10 . V_11 = 0 ;
V_8 -> V_10 . V_12 =
V_5 ? V_13 : V_14 ;
V_9 = ( V_15 +
V_16 +
V_17 +
( V_5 ? V_18 : 0 ) +
V_1 +
4 +
3 ) / 4 ;
V_8 -> V_10 . V_9 = F_2 ( V_9 ) ;
}
if ( V_4 )
V_8 -> V_19 . type = F_2 ( V_20 ) ;
if ( V_5 ) {
V_8 -> V_21 . V_22 = 6 ;
V_8 -> V_21 . V_23 =
F_2 ( ( V_16 +
V_17 +
V_1 +
4 +
3 ) & ~ 3 ) ;
V_8 -> V_21 . V_24 = 0x1b ;
}
if ( V_6 )
V_8 -> V_25 . V_26 = V_27 ;
else
V_8 -> V_25 . V_26 = V_28 ;
V_8 -> V_25 . V_29 = ( 4 - V_1 ) & 3 ;
V_8 -> V_25 . V_30 = 0 ;
V_8 -> V_2 = V_2 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_5 = V_5 ;
V_8 -> V_6 = V_6 ;
}
int F_3 ( struct V_7 * V_8 ,
void * V_31 )
{
int V_32 = 0 ;
if ( V_8 -> V_2 ) {
F_4 ( V_33 , F_5 ( V_33 ) ,
& V_8 -> V_10 , V_31 + V_32 ) ;
V_32 += V_15 ;
}
if ( V_8 -> V_3 ) {
F_4 ( V_34 , F_5 ( V_34 ) ,
& V_8 -> V_19 , V_31 + V_32 ) ;
V_32 += V_35 ;
}
if ( V_8 -> V_4 ) {
F_4 ( V_36 , F_5 ( V_36 ) ,
& V_8 -> V_37 , V_31 + V_32 ) ;
V_32 += V_38 ;
}
if ( V_8 -> V_5 ) {
F_4 ( V_39 , F_5 ( V_39 ) ,
& V_8 -> V_21 , V_31 + V_32 ) ;
V_32 += V_18 ;
}
F_4 ( V_40 , F_5 ( V_40 ) ,
& V_8 -> V_25 , V_31 + V_32 ) ;
V_32 += V_16 ;
F_4 ( V_41 , F_5 ( V_41 ) ,
& V_8 -> V_42 , V_31 + V_32 ) ;
V_32 += V_17 ;
if ( V_8 -> V_6 ) {
memcpy ( V_31 + V_32 , & V_8 -> V_43 , sizeof V_8 -> V_43 ) ;
V_32 += sizeof V_8 -> V_43 ;
}
return V_32 ;
}
int F_6 ( void * V_31 ,
struct V_7 * V_8 )
{
F_7 ( V_33 , F_5 ( V_33 ) ,
V_31 , & V_8 -> V_10 ) ;
V_31 += V_15 ;
if ( V_8 -> V_10 . V_11 != 0 ) {
F_8 ( V_44 L_1 ,
V_8 -> V_10 . V_11 ) ;
return - V_45 ;
}
switch ( V_8 -> V_10 . V_12 ) {
case V_14 :
V_8 -> V_5 = 0 ;
break;
case V_13 :
V_8 -> V_5 = 1 ;
F_7 ( V_39 , F_5 ( V_39 ) ,
V_31 , & V_8 -> V_21 ) ;
V_31 += V_18 ;
if ( V_8 -> V_21 . V_22 != 6 ) {
F_8 ( V_44 L_2 ,
V_8 -> V_21 . V_22 ) ;
return - V_45 ;
}
if ( V_8 -> V_21 . V_24 != 0x1b ) {
F_8 ( V_44 L_3 ,
V_8 -> V_21 . V_24 ) ;
return - V_45 ;
}
break;
default:
F_8 ( V_44 L_4 ,
V_8 -> V_10 . V_12 ) ;
return - V_45 ;
}
F_7 ( V_40 , F_5 ( V_40 ) ,
V_31 , & V_8 -> V_25 ) ;
V_31 += V_16 ;
switch ( V_8 -> V_25 . V_26 ) {
case V_28 :
V_8 -> V_6 = 0 ;
break;
case V_27 :
V_8 -> V_6 = 1 ;
break;
default:
F_8 ( V_44 L_5 ,
V_8 -> V_25 . V_26 ) ;
return - V_45 ;
}
if ( V_8 -> V_25 . V_30 != 0 ) {
F_8 ( V_44 L_6 ,
V_8 -> V_25 . V_30 ) ;
return - V_45 ;
}
F_7 ( V_41 , F_5 ( V_41 ) ,
V_31 , & V_8 -> V_42 ) ;
V_31 += V_17 ;
if ( V_8 -> V_6 )
memcpy ( & V_8 -> V_43 , V_31 , sizeof V_8 -> V_43 ) ;
return 0 ;
}
