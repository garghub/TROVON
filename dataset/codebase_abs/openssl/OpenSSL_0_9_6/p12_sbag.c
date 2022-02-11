int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
int V_3 , V_4 = 0 ;
F_2 ( V_1 ) ;
V_3 = F_3 ( V_1 -> type ) ;
F_4 ( V_1 -> type , V_5 ) ;
switch ( V_3 ) {
case V_6 :
F_5 ( V_1 -> V_7 . V_8 ,
V_9 , 0 , V_4 ) ;
break;
case V_10 :
F_5 ( V_1 -> V_7 . V_11 ,
V_12 , 0 , V_4 ) ;
break;
case V_13 :
F_6
( T_1 , V_1 -> V_7 . V_14 , F_1 ,
0 , V_15 , V_4 ) ;
break;
case V_16 :
case V_17 :
case V_18 :
F_5 ( V_1 -> V_7 . V_19 ,
V_20 , 0 , V_4 ) ;
break;
default:
F_5 ( V_1 -> V_7 . V_21 ,
V_22 , 0 , V_4 ) ;
break;
}
F_7 ( V_23 , V_1 -> V_24 , V_25 ) ;
F_8 () ;
F_9 ( V_1 -> type , V_5 ) ;
switch ( V_3 ) {
case V_6 :
F_10 ( V_1 -> V_7 . V_8 ,
V_9 , 0 , V_4 ) ;
break;
case V_10 :
F_10 ( V_1 -> V_7 . V_11 ,
V_12 , 0 , V_4 ) ;
break;
case V_13 :
F_11
( T_1 , V_1 -> V_7 . V_14 , F_1 ,
0 , V_15 , V_4 ) ;
break;
case V_16 :
case V_17 :
case V_18 :
F_10 ( V_1 -> V_7 . V_19 ,
V_20 , 0 , V_4 ) ;
break;
default:
F_10 ( V_1 -> V_7 . V_21 ,
V_22 , 0 , V_4 ) ;
break;
}
F_12 ( V_23 , V_1 -> V_24 , V_25 ) ;
F_13 () ;
}
T_1 * F_14 ( void )
{
T_1 * V_26 = NULL ;
T_2 V_27 ;
F_15 ( V_26 , T_1 ) ;
V_26 -> type = NULL ;
V_26 -> V_7 . V_21 = NULL ;
F_16 ( V_26 -> V_24 , V_28 ) ;
V_26 -> V_29 = NULL ;
return ( V_26 ) ;
F_17 ( V_30 ) ;
}
T_1 * F_18 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_31 )
{
int V_3 ;
F_19 ( V_1 , T_1 * , F_14 ) ;
F_20 () ;
F_21 () ;
F_22 ( V_26 -> type , V_32 ) ;
V_3 = F_3 ( V_26 -> type ) ;
switch ( V_3 ) {
case V_6 :
F_23 ( V_26 -> V_7 . V_8 ,
V_33 , 0 ) ;
break;
case V_10 :
F_23 ( V_26 -> V_7 . V_11 ,
V_34 , 0 ) ;
break;
case V_13 :
F_24
( T_1 , V_26 -> V_7 . V_14 ,
F_18 , V_35 , 0 ,
V_15 ) ;
break;
case V_16 :
case V_17 :
case V_18 :
F_23 ( V_26 -> V_7 . V_19 ,
V_36 , 0 ) ;
break;
default:
F_23 ( V_26 -> V_7 . V_21 ,
V_37 , 0 ) ;
break;
}
F_25 ( V_23 , V_26 -> V_24 ,
V_38 , V_39 ) ;
F_26 ( V_1 , V_35 , V_40 ) ;
}
void V_35 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
switch ( F_3 ( V_1 -> type ) ) {
case V_6 :
F_27 ( V_1 -> V_7 . V_8 ) ;
break;
case V_10 :
F_28 ( V_1 -> V_7 . V_11 ) ;
break;
case V_16 :
case V_17 :
case V_18 :
F_29 ( V_1 -> V_7 . V_19 ) ;
break;
default:
F_30 ( V_1 -> V_7 . V_21 ) ;
break;
}
F_31 ( V_1 -> type ) ;
F_32 ( V_1 -> V_24 , V_39 ) ;
F_33 ( V_1 ) ;
}
