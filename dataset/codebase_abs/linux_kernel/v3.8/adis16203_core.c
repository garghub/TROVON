static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_5 ,
int V_6 ,
long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_10 = V_11 [ V_4 -> V_12 ] ;
return F_3 ( V_9 , V_10 , V_5 & 0x3FFF ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_6 ,
long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
int V_14 ;
T_1 V_10 ;
T_2 V_15 ;
switch ( V_7 ) {
case V_16 :
return F_5 ( V_2 , V_4 ,
V_17 , V_5 ) ;
case V_18 :
switch ( V_4 -> type ) {
case V_19 :
if ( V_4 -> V_20 == 0 ) {
* V_5 = 1 ;
* V_6 = 220000 ;
} else {
* V_5 = 0 ;
* V_6 = 610000 ;
}
return V_21 ;
case V_22 :
* V_5 = - 470 ;
* V_6 = 0 ;
return V_21 ;
case V_23 :
* V_5 = 0 ;
* V_6 = 25000 ;
return V_21 ;
default:
return - V_24 ;
}
case V_25 :
* V_5 = 25000 / - 470 - 1278 ;
return V_26 ;
case V_27 :
V_14 = 14 ;
F_6 ( & V_2 -> V_28 ) ;
V_10 = V_11 [ V_4 -> V_12 ] ;
V_13 = F_7 ( V_9 , V_10 , & V_15 ) ;
if ( V_13 ) {
F_8 ( & V_2 -> V_28 ) ;
return V_13 ;
}
V_15 &= ( 1 << V_14 ) - 1 ;
V_15 = ( T_2 ) ( V_15 << ( 16 - V_14 ) ) >> ( 16 - V_14 ) ;
* V_5 = V_15 ;
F_8 ( & V_2 -> V_28 ) ;
return V_26 ;
default:
return - V_24 ;
}
}
static int F_9 ( struct V_29 * V_30 )
{
int V_13 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
V_2 = F_10 ( sizeof( * V_9 ) ) ;
if ( V_2 == NULL ) {
V_13 = - V_31 ;
goto V_32;
}
V_9 = F_2 ( V_2 ) ;
F_11 ( V_30 , V_2 ) ;
V_2 -> V_33 = V_30 -> V_34 . V_35 -> V_33 ;
V_2 -> V_34 . V_36 = & V_30 -> V_34 ;
V_2 -> V_37 = V_38 ;
V_2 -> V_39 = F_12 ( V_38 ) ;
V_2 -> V_40 = & V_41 ;
V_2 -> V_42 = V_43 ;
V_13 = F_13 ( V_9 , V_2 , V_30 , & V_44 ) ;
if ( V_13 )
goto V_45;
V_13 = F_14 ( V_9 , V_2 , NULL ) ;
if ( V_13 )
goto V_45;
V_13 = F_15 ( V_9 ) ;
if ( V_13 )
goto V_46;
V_13 = F_16 ( V_2 ) ;
if ( V_13 )
goto V_46;
return 0 ;
V_46:
F_17 ( V_9 , V_2 ) ;
V_45:
F_18 ( V_2 ) ;
V_32:
return V_13 ;
}
static int F_19 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_20 ( V_30 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_21 ( V_2 ) ;
F_17 ( V_9 , V_2 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
