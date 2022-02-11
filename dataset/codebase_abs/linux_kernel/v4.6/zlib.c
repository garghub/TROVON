int F_1 ( const char * V_1 , int V_2 )
{
int V_3 = V_4 ;
int V_5 ;
void * V_6 ;
int V_7 ;
struct V_8 V_9 ;
unsigned char V_10 [ V_11 ] ;
T_1 V_12 = {
. V_13 = V_14 ,
. V_15 = V_14 ,
. V_16 = V_14 ,
. V_17 = 0 ,
. V_18 = V_14 ,
} ;
V_5 = F_2 ( V_1 , V_19 ) ;
if ( V_5 < 0 )
return - 1 ;
if ( F_3 ( V_5 , & V_9 ) < 0 )
goto V_20;
V_6 = F_4 ( NULL , V_9 . V_21 , V_22 , V_23 , V_5 , 0 ) ;
if ( V_6 == V_24 )
goto V_20;
if ( F_5 ( & V_12 , 16 + V_25 ) != V_26 )
goto V_27;
V_12 . V_18 = V_6 ;
V_12 . V_17 = V_9 . V_21 ;
do {
V_12 . V_28 = V_10 ;
V_12 . V_29 = V_11 ;
V_3 = F_6 ( & V_12 , V_30 ) ;
switch ( V_3 ) {
case V_31 :
V_3 = V_32 ;
case V_32 :
case V_33 :
goto V_34;
default:
break;
}
V_7 = V_11 - V_12 . V_29 ;
if ( F_7 ( V_2 , V_10 , V_7 ) != V_7 ) {
V_3 = V_32 ;
goto V_34;
}
} while ( V_3 != V_35 );
V_34:
F_8 ( & V_12 ) ;
V_27:
F_9 ( V_6 , V_9 . V_21 ) ;
V_20:
F_10 ( V_5 ) ;
return V_3 == V_35 ? 0 : - 1 ;
}
