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
V_9 , 0 , V_4 ) ;
break;
case V_12 :
F_5 ( V_1 -> V_7 . V_13 ,
V_14 , 0 , V_4 ) ;
break;
default:
F_5 ( V_1 -> V_7 . V_15 ,
V_16 , 0 , V_4 ) ;
break;
}
F_6 () ;
F_7 ( V_1 -> type , V_5 ) ;
switch ( V_3 ) {
case V_6 :
F_8 ( V_1 -> V_7 . V_8 ,
V_9 , 0 , V_4 ) ;
break;
case V_10 :
F_8 ( V_1 -> V_7 . V_11 ,
V_9 , 0 , V_4 ) ;
break;
case V_12 :
F_8 ( V_1 -> V_7 . V_13 ,
V_14 , 0 , V_4 ) ;
break;
default:
F_8 ( V_1 -> V_7 . V_15 , V_16 , 0 , V_4 ) ;
break;
}
F_9 () ;
}
T_1 * F_10 ( void )
{
T_1 * V_17 = NULL ;
T_2 V_18 ;
F_11 ( V_17 , T_1 ) ;
V_17 -> type = NULL ;
V_17 -> V_7 . V_15 = NULL ;
return ( V_17 ) ;
F_12 ( V_19 ) ;
}
T_1 * F_13 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_20 )
{
int V_3 ;
F_14 ( V_1 , T_1 * , F_10 ) ;
F_15 () ;
F_16 () ;
F_17 ( V_17 -> type , V_21 ) ;
V_3 = F_3 ( V_17 -> type ) ;
switch ( V_3 ) {
case V_6 :
F_18 ( V_17 -> V_7 . V_8 ,
V_22 , 0 ) ;
break;
case V_10 :
F_18 ( V_17 -> V_7 . V_11 ,
V_22 , 0 ) ;
break;
case V_12 :
F_18 ( V_17 -> V_7 . V_13 ,
V_23 , 0 ) ;
break;
default:
F_18 ( V_17 -> V_7 . V_15 ,
V_24 , 0 ) ;
break;
}
F_19 ( V_1 , V_25 , V_26 ) ;
}
void V_25 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
switch ( F_3 ( V_1 -> type ) ) {
case V_6 :
F_20 ( V_1 -> V_7 . V_8 ) ;
break;
case V_10 :
F_20 ( V_1 -> V_7 . V_11 ) ;
break;
case V_12 :
F_21 ( V_1 -> V_7 . V_13 ) ;
break;
default:
F_22 ( V_1 -> V_7 . V_15 ) ;
break;
}
F_23 ( V_1 -> type ) ;
F_24 ( V_1 ) ;
}
