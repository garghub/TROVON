T_1 * F_1 ( T_2 * V_1 , T_3 * V_2 ,
T_1 * V_3 )
{
char V_4 [ 256 ] ;
unsigned char * V_5 ;
switch ( V_2 -> type )
{
case V_6 :
F_2 ( L_1 , L_2 , & V_3 ) ;
break;
case V_7 :
F_2 ( L_3 , L_2 , & V_3 ) ;
break;
case V_8 :
F_2 ( L_4 , L_2 , & V_3 ) ;
break;
case V_9 :
F_3 ( L_5 , V_2 -> V_10 . V_11 -> V_12 , & V_3 ) ;
break;
case V_13 :
F_3 ( L_6 , V_2 -> V_10 . V_11 -> V_12 , & V_3 ) ;
break;
case V_14 :
F_3 ( L_7 , V_2 -> V_10 . V_11 -> V_12 , & V_3 ) ;
break;
case V_15 :
F_4 ( V_2 -> V_10 . V_16 , V_4 , 256 ) ;
F_2 ( L_8 , V_4 , & V_3 ) ;
break;
case V_17 :
V_5 = V_2 -> V_10 . V_18 -> V_12 ;
if( V_2 -> V_10 . V_18 -> V_19 != 4 ) {
F_2 ( L_9 , L_10 , & V_3 ) ;
break;
}
sprintf ( V_4 , L_11 , V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] ) ;
F_2 ( L_9 , V_4 , & V_3 ) ;
break;
case V_20 :
F_5 ( V_4 , 256 , V_2 -> V_10 . V_21 ) ;
F_2 ( L_12 , V_4 , & V_3 ) ;
break;
}
return V_3 ;
}
