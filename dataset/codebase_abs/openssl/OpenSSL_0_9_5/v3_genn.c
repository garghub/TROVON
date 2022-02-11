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
V_4 = F_4 ( V_1 -> V_7 . V_12 , V_2 ) ;
break;
case V_13 :
V_4 = F_5 ( V_1 -> V_7 . V_14 , V_2 ) ;
break;
case V_15 :
case V_16 :
case V_17 :
V_4 = F_6 ( V_1 -> V_7 . V_18 , V_2 ) ;
break;
case V_19 :
V_4 = F_7 ( V_1 -> V_7 . V_20 , V_2 ) ;
break;
case V_21 :
V_4 = F_8 ( V_1 -> V_7 . V_22 , V_2 ) ;
break;
}
if( V_3 ) * V_3 = ( * V_3 & V_23 ) | V_1 -> type ;
return V_4 ;
}
T_1 * F_9 ()
{
T_1 * V_4 = NULL ;
T_2 V_24 ;
F_10 ( V_4 , T_1 ) ;
V_4 -> type = - 1 ;
V_4 -> V_7 . V_25 = NULL ;
return ( V_4 ) ;
F_11 ( V_26 ) ;
}
T_1 * F_12 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_27 )
{
unsigned char V_28 ;
F_13 ( V_1 , T_1 * , F_9 ) ;
F_14 () ;
V_24 . V_29 = V_27 ;
V_28 = V_30 ;
V_4 -> type = V_28 & ~ V_23 ;
switch( V_4 -> type ) {
case V_10 :
case V_11 :
F_15 ( V_4 -> V_7 . V_12 , V_31 , V_32 ) ;
break;
case V_13 :
F_15 ( V_4 -> V_7 . V_14 , V_33 , V_32 ) ;
break;
case V_15 :
case V_16 :
case V_17 :
F_15 ( V_4 -> V_7 . V_18 , V_34 ,
V_35 ) ;
break;
case V_5 :
F_16 ( V_4 -> V_7 . V_8 , V_36 , 4 ) ;
break;
case V_19 :
F_15 ( V_4 -> V_7 . V_20 , V_37 ,
V_38 ) ;
break;
case V_21 :
F_15 ( V_4 -> V_7 . V_22 , V_39 , V_40 ) ;
break;
default:
V_24 . error = V_41 ;
goto V_42;
}
V_24 . V_29 = 0 ;
F_17 ( V_1 , V_43 , V_44 ) ;
}
void V_43 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
switch( V_1 -> type ) {
case V_10 :
case V_11 :
F_18 ( V_1 -> V_7 . V_12 ) ;
break;
case V_13 :
F_19 ( V_1 -> V_7 . V_14 ) ;
break;
case V_15 :
case V_16 :
case V_17 :
F_20 ( V_1 -> V_7 . V_18 ) ;
break;
case V_5 :
F_21 ( V_1 -> V_7 . V_8 ) ;
break;
case V_19 :
F_22 ( V_1 -> V_7 . V_20 ) ;
break;
case V_21 :
F_23 ( V_1 -> V_7 . V_22 ) ;
break;
}
Free ( V_1 ) ;
}
int F_5 ( T_3 * V_1 , unsigned char * * V_2 )
{
int V_6 = 0 ;
F_24 ( V_1 ) ;
F_25 ( V_1 -> V_45 , F_8 ) ;
F_2 ( V_1 -> V_46 , F_4 , 0 , V_6 ) ;
F_26 () ;
F_27 ( V_1 -> V_45 , F_8 ) ;
F_3 ( V_1 -> V_46 , F_4 , 0 , V_6 ) ;
F_28 () ;
}
T_3 * F_29 ( void )
{
T_3 * V_4 = NULL ;
T_2 V_24 ;
F_10 ( V_4 , T_3 ) ;
V_4 -> V_45 = F_30 ( V_47 ) ;
F_31 ( V_4 -> V_46 , V_48 ) ;
return ( V_4 ) ;
F_11 ( V_49 ) ;
}
T_3 * V_33 ( T_3 * * V_1 , unsigned char * * V_2 , long V_27 )
{
F_13 ( V_1 , T_3 * , F_29 ) ;
F_14 () ;
F_32 () ;
F_33 ( V_4 -> V_45 , V_39 ) ;
F_16 ( V_4 -> V_46 , V_31 , 0 ) ;
F_17 ( V_1 , F_19 , V_50 ) ;
}
void F_19 ( T_3 * V_1 )
{
if ( V_1 == NULL ) return;
F_23 ( V_1 -> V_45 ) ;
F_18 ( V_1 -> V_46 ) ;
Free ( V_1 ) ;
}
