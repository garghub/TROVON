static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_6 ,
long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 ;
int V_11 ;
T_1 V_12 ;
T_2 V_13 ;
switch ( V_7 ) {
case V_14 :
return F_3 ( V_2 , V_4 ,
V_15 , V_5 ) ;
case V_16 :
switch ( V_4 -> type ) {
case V_17 :
if ( V_4 -> V_18 == 0 ) {
* V_5 = 1 ;
* V_6 = 220000 ;
} else {
* V_5 = 0 ;
* V_6 = 610000 ;
}
return V_19 ;
case V_20 :
* V_5 = - 470 ;
* V_6 = 0 ;
return V_19 ;
case V_21 :
* V_5 = 0 ;
* V_6 = F_4 ( 462400 ) ;
return V_22 ;
case V_23 :
* V_5 = 0 ;
* V_6 = 100000 ;
return V_19 ;
default:
return - V_24 ;
}
break;
case V_25 :
* V_5 = 25000 / - 470 - 1278 ;
return V_26 ;
case V_27 :
switch ( V_4 -> type ) {
case V_21 :
V_11 = 12 ;
break;
case V_23 :
V_11 = 9 ;
break;
default:
return - V_24 ;
}
V_12 = V_28 [ V_4 -> V_29 ] ;
V_10 = F_5 ( V_9 , V_12 , & V_13 ) ;
if ( V_10 )
return V_10 ;
V_13 &= ( 1 << V_11 ) - 1 ;
V_13 = ( T_2 ) ( V_13 << ( 16 - V_11 ) ) >> ( 16 - V_11 ) ;
* V_5 = V_13 ;
return V_26 ;
}
return - V_24 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_5 ,
int V_6 ,
long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_11 ;
T_2 V_13 ;
T_1 V_12 ;
switch ( V_7 ) {
case V_27 :
switch ( V_4 -> type ) {
case V_21 :
V_11 = 12 ;
break;
case V_23 :
V_11 = 9 ;
break;
default:
return - V_24 ;
}
V_13 = V_5 & ( ( 1 << V_11 ) - 1 ) ;
V_12 = V_28 [ V_4 -> V_29 ] ;
return F_7 ( V_9 , V_12 , V_13 ) ;
}
return - V_24 ;
}
static int F_8 ( struct V_30 * V_31 )
{
int V_10 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
V_2 = F_9 ( & V_31 -> V_32 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_33 ;
V_9 = F_2 ( V_2 ) ;
F_10 ( V_31 , V_2 ) ;
V_2 -> V_34 = V_31 -> V_32 . V_35 -> V_34 ;
V_2 -> V_32 . V_36 = & V_31 -> V_32 ;
V_2 -> V_37 = & V_38 ;
V_2 -> V_39 = V_40 ;
V_2 -> V_41 = F_11 ( V_40 ) ;
V_2 -> V_42 = V_43 ;
V_10 = F_12 ( V_9 , V_2 , V_31 , & V_44 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_13 ( V_9 , V_2 , NULL ) ;
if ( V_10 )
return V_10 ;
V_10 = F_14 ( V_9 ) ;
if ( V_10 )
goto V_45;
V_10 = F_15 ( V_2 ) ;
if ( V_10 < 0 )
goto V_45;
return 0 ;
V_45:
F_16 ( V_9 , V_2 ) ;
return V_10 ;
}
static int F_17 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_18 ( V_31 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_19 ( V_2 ) ;
F_16 ( V_9 , V_2 ) ;
return 0 ;
}
