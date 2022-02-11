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
int V_14 ;
switch ( V_7 ) {
case V_15 :
return F_3 ( V_2 , V_4 ,
V_16 , V_5 ) ;
case V_17 :
switch ( V_4 -> type ) {
case V_18 :
if ( V_4 -> V_19 == 0 ) {
* V_5 = 1 ;
* V_6 = 220000 ;
} else {
* V_5 = 0 ;
* V_6 = 610000 ;
}
return V_20 ;
case V_21 :
* V_5 = - 470 ;
* V_6 = 0 ;
return V_20 ;
case V_22 :
* V_5 = 0 ;
switch ( V_4 -> V_23 ) {
case V_24 :
case V_25 :
* V_6 = F_4 ( 17125 ) ;
break;
case V_26 :
case V_27 :
* V_6 = F_4 ( 8407 ) ;
break;
}
return V_20 ;
default:
return - V_28 ;
}
break;
case V_29 :
* V_5 = 25000 / - 470 - 1278 ;
return V_30 ;
case V_31 :
case V_32 :
if ( V_7 == V_31 ) {
V_11 = 12 ;
V_14 = 0 ;
} else {
V_11 = 14 ;
V_14 = 1 ;
}
F_5 ( & V_2 -> V_33 ) ;
V_12 = V_34 [ V_4 -> V_35 ] [ V_14 ] ;
V_10 = F_6 ( V_9 , V_12 , & V_13 ) ;
if ( V_10 ) {
F_7 ( & V_2 -> V_33 ) ;
return V_10 ;
}
V_13 &= ( 1 << V_11 ) - 1 ;
V_13 = ( T_2 ) ( V_13 << ( 16 - V_11 ) ) >> ( 16 - V_11 ) ;
* V_5 = V_13 ;
F_7 ( & V_2 -> V_33 ) ;
return V_30 ;
}
return - V_28 ;
}
static int F_8 ( struct V_1 * V_2 ,
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
case V_31 :
switch ( V_4 -> type ) {
case V_22 :
V_11 = 12 ;
break;
default:
return - V_28 ;
}
V_13 = V_5 & ( ( 1 << V_11 ) - 1 ) ;
V_12 = V_34 [ V_4 -> V_35 ] [ 1 ] ;
return F_9 ( V_9 , V_12 , V_13 ) ;
}
return - V_28 ;
}
static int F_10 ( struct V_36 * V_37 )
{
int V_10 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
V_2 = F_11 ( sizeof( * V_9 ) ) ;
if ( V_2 == NULL ) {
V_10 = - V_38 ;
goto V_39;
}
V_9 = F_2 ( V_2 ) ;
F_12 ( V_37 , V_2 ) ;
V_2 -> V_40 = V_37 -> V_41 . V_42 -> V_40 ;
V_2 -> V_41 . V_43 = & V_37 -> V_41 ;
V_2 -> V_44 = & V_45 ;
V_2 -> V_46 = V_47 ;
V_2 -> V_48 = F_13 ( V_47 ) ;
V_2 -> V_49 = V_50 ;
V_10 = F_14 ( V_9 , V_2 , V_37 , & V_51 ) ;
if ( V_10 )
goto V_52;
V_10 = F_15 ( V_9 , V_2 , NULL ) ;
if ( V_10 )
goto V_52;
V_10 = F_16 ( V_9 ) ;
if ( V_10 )
goto V_53;
V_10 = F_17 ( V_2 ) ;
if ( V_10 )
goto V_53;
return 0 ;
V_53:
F_18 ( V_9 , V_2 ) ;
V_52:
F_19 ( V_2 ) ;
V_39:
return V_10 ;
}
static int F_20 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_21 ( V_37 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_22 ( V_2 ) ;
F_18 ( V_9 , V_2 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
