int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
unsigned char * V_3 ;
int V_4 ;
V_4 = 0 ;
if( V_2 ) V_3 = * V_2 ;
else V_3 = NULL ;
if( V_1 -> type == V_5 ) {
int V_6 = 0 ;
F_2 ( V_1 -> V_7 . V_8 , V_9 , 4 , V_6 ) ;
if( ! V_3 ) return V_4 ;
F_3 ( V_1 -> V_7 . V_8 , V_9 , 4 , V_6 ) ;
* V_2 = V_3 ;
return V_4 ;
}
switch( V_1 -> type ) {
case V_10 :
case V_11 :
case V_12 :
V_4 = F_4 ( V_1 -> V_7 . V_13 , V_2 ) ;
break;
case V_14 :
case V_15 :
case V_16 :
V_4 = F_5 ( V_1 -> V_7 . V_17 , V_2 ) ;
break;
case V_18 :
V_4 = F_6 ( V_1 -> V_7 . V_19 , V_2 ) ;
break;
case V_20 :
V_4 = F_7 ( V_1 -> V_7 . V_21 , V_2 ) ;
break;
}
if( V_3 ) * V_3 = ( * V_3 & V_22 ) | V_1 -> type ;
return V_4 ;
}
T_1 * F_8 ()
{
T_1 * V_4 = NULL ;
T_2 V_23 ;
F_9 ( V_4 , T_1 ) ;
V_4 -> type = - 1 ;
V_4 -> V_7 . V_24 = NULL ;
return ( V_4 ) ;
F_10 ( V_25 ) ;
}
T_1 * F_11 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_26 )
{
unsigned char V_27 ;
F_12 ( V_1 , T_1 * , F_8 ) ;
F_13 () ;
V_23 . V_28 = V_26 ;
V_27 = V_29 ;
V_4 -> type = V_27 & ~ V_22 ;
switch( V_4 -> type ) {
case V_10 :
case V_11 :
case V_12 :
F_14 ( V_4 -> V_7 . V_13 , V_30 , V_31 ) ;
break;
case V_14 :
case V_15 :
case V_16 :
F_14 ( V_4 -> V_7 . V_17 , V_32 ,
V_33 ) ;
break;
case V_5 :
F_15 ( V_4 -> V_7 . V_8 , V_34 , 4 ) ;
break;
case V_18 :
F_14 ( V_4 -> V_7 . V_19 , V_35 ,
V_36 ) ;
break;
case V_20 :
F_14 ( V_4 -> V_7 . V_21 , V_37 , V_38 ) ;
break;
default:
V_23 . error = V_39 ;
goto V_40;
}
V_23 . V_28 = 0 ;
F_16 ( V_1 , V_41 , V_42 ) ;
}
void V_41 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
switch( V_1 -> type ) {
case V_10 :
case V_11 :
case V_12 :
F_17 ( V_1 -> V_7 . V_13 ) ;
break;
case V_14 :
case V_15 :
case V_16 :
F_18 ( V_1 -> V_7 . V_17 ) ;
break;
case V_5 :
F_19 ( V_1 -> V_7 . V_8 ) ;
break;
case V_18 :
F_20 ( V_1 -> V_7 . V_19 ) ;
break;
case V_20 :
F_21 ( V_1 -> V_7 . V_21 ) ;
break;
}
Free ( ( char * ) V_1 ) ;
}
