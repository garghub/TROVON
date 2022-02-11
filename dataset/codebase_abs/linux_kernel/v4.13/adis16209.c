static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_5 ,
int V_6 ,
long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 ;
T_1 V_11 ;
T_2 V_12 ;
switch ( V_7 ) {
case V_13 :
switch ( V_4 -> type ) {
case V_14 :
case V_15 :
V_10 = 14 ;
break;
default:
return - V_16 ;
}
V_11 = V_5 & ( ( 1 << V_10 ) - 1 ) ;
V_12 = V_17 [ V_4 -> V_18 ] [ 0 ] ;
return F_3 ( V_9 , V_12 , V_11 ) ;
}
return - V_16 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_6 ,
long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_19 ;
int V_10 ;
T_2 V_12 ;
T_1 V_11 ;
switch ( V_7 ) {
case V_20 :
return F_5 ( V_2 , V_4 ,
V_21 , V_5 ) ;
case V_22 :
switch ( V_4 -> type ) {
case V_23 :
* V_5 = 0 ;
if ( V_4 -> V_24 == 0 )
* V_6 = 305180 ;
else
* V_6 = 610500 ;
return V_25 ;
case V_26 :
* V_5 = - 470 ;
* V_6 = 0 ;
return V_25 ;
case V_14 :
* V_5 = 0 ;
* V_6 = F_6 ( 244140 ) ;
return V_27 ;
case V_15 :
case V_28 :
* V_5 = 0 ;
* V_6 = 25000 ;
return V_25 ;
default:
return - V_16 ;
}
break;
case V_29 :
* V_5 = 25000 / - 470 - 0x4FE ;
return V_30 ;
case V_13 :
switch ( V_4 -> type ) {
case V_14 :
V_10 = 14 ;
break;
default:
return - V_16 ;
}
V_12 = V_17 [ V_4 -> V_18 ] [ 0 ] ;
V_19 = F_7 ( V_9 , V_12 , & V_11 ) ;
if ( V_19 )
return V_19 ;
V_11 &= ( 1 << V_10 ) - 1 ;
V_11 = ( T_1 ) ( V_11 << ( 16 - V_10 ) ) >> ( 16 - V_10 ) ;
* V_5 = V_11 ;
return V_30 ;
}
return - V_16 ;
}
static int F_8 ( struct V_31 * V_32 )
{
int V_19 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
V_2 = F_9 ( & V_32 -> V_33 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_34 ;
V_9 = F_2 ( V_2 ) ;
F_10 ( V_32 , V_2 ) ;
V_2 -> V_35 = V_32 -> V_33 . V_36 -> V_35 ;
V_2 -> V_33 . V_37 = & V_32 -> V_33 ;
V_2 -> V_38 = & V_39 ;
V_2 -> V_40 = V_41 ;
V_2 -> V_42 = F_11 ( V_41 ) ;
V_2 -> V_43 = V_44 ;
V_19 = F_12 ( V_9 , V_2 , V_32 , & V_45 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_13 ( V_9 , V_2 , NULL ) ;
if ( V_19 )
return V_19 ;
V_19 = F_14 ( V_9 ) ;
if ( V_19 )
goto V_46;
V_19 = F_15 ( V_2 ) ;
if ( V_19 )
goto V_46;
return 0 ;
V_46:
F_16 ( V_9 , V_2 ) ;
return V_19 ;
}
static int F_17 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_19 ( V_2 ) ;
F_16 ( V_9 , V_2 ) ;
return 0 ;
}
