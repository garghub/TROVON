static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ,
unsigned int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_11 ;
T_2 V_12 = 0 ;
unsigned int V_13 = 16 - V_6 ;
struct V_14 * V_15 = F_4 ( V_4 ) ;
V_11 = F_5 ( V_10 ,
V_15 -> V_16 , ( V_17 * ) & V_12 ) ;
if ( V_11 )
return V_11 ;
if ( V_12 & V_18 )
F_6 ( V_10 ) ;
V_12 = ( T_2 ) ( V_12 << V_13 ) >> V_13 ;
return sprintf ( V_5 , L_1 , V_12 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return F_1 ( V_2 , V_4 , V_5 , 12 ) ;
}
static int F_8 ( struct V_7 * V_8 ,
struct V_19 const * V_20 ,
int * V_12 , int * V_21 ,
long V_22 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_11 ;
int V_6 ;
T_3 V_23 ;
T_2 V_24 ;
switch ( V_22 ) {
case V_25 :
return F_9 ( V_8 , V_20 ,
V_18 , V_12 ) ;
case V_26 :
switch ( V_20 -> type ) {
case V_27 :
if ( V_20 -> V_28 == 0 ) {
* V_12 = 4 ;
* V_21 = 880000 ;
return V_29 ;
}
return - V_30 ;
case V_31 :
* V_12 = 244 ;
* V_21 = 0 ;
return V_29 ;
case V_32 :
* V_12 = 0 ;
* V_21 = F_10 ( 51400 ) ;
return V_29 ;
default:
return - V_30 ;
}
break;
case V_33 :
* V_12 = 0 ;
* V_21 = F_10 ( 51400 ) ;
return V_29 ;
case V_34 :
* V_12 = 25000 / 244 - 0x133 ;
return V_35 ;
case V_36 :
V_6 = 10 ;
V_23 = V_37 [ V_20 -> V_38 ] [ 0 ] ;
V_11 = F_5 ( V_10 , V_23 , & V_24 ) ;
if ( V_11 )
return V_11 ;
V_24 &= ( 1 << V_6 ) - 1 ;
V_24 = ( T_2 ) ( V_24 << ( 16 - V_6 ) ) >> ( 16 - V_6 ) ;
* V_12 = V_24 ;
return V_35 ;
case V_39 :
V_6 = 10 ;
V_23 = V_37 [ V_20 -> V_38 ] [ 1 ] ;
V_11 = F_5 ( V_10 , V_23 , & V_24 ) ;
if ( V_11 )
return V_11 ;
V_24 &= ( 1 << V_6 ) - 1 ;
V_24 = ( T_2 ) ( V_24 << ( 16 - V_6 ) ) >> ( 16 - V_6 ) ;
* V_12 = V_24 ;
return V_35 ;
}
return - V_30 ;
}
static int F_11 ( struct V_7 * V_8 ,
struct V_19 const * V_20 ,
int V_12 ,
int V_21 ,
long V_22 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_6 = 10 ;
T_2 V_24 ;
T_3 V_23 ;
switch ( V_22 ) {
case V_36 :
V_24 = V_12 & ( ( 1 << V_6 ) - 1 ) ;
V_23 = V_37 [ V_20 -> V_38 ] [ 0 ] ;
return F_12 ( V_10 , V_23 , V_24 ) ;
}
return - V_30 ;
}
static int F_13 ( struct V_40 * V_41 )
{
int V_11 ;
struct V_9 * V_10 ;
struct V_7 * V_8 ;
V_8 = F_14 ( & V_41 -> V_2 , sizeof( * V_10 ) ) ;
if ( ! V_8 )
return - V_42 ;
V_10 = F_3 ( V_8 ) ;
F_15 ( V_41 , V_8 ) ;
V_8 -> V_43 = V_41 -> V_2 . V_44 -> V_43 ;
V_8 -> V_2 . V_45 = & V_41 -> V_2 ;
V_8 -> V_46 = & V_47 ;
V_8 -> V_48 = V_49 ;
V_8 -> V_50 = F_16 ( V_49 ) ;
V_8 -> V_51 = V_52 ;
V_11 = F_17 ( V_10 , V_8 , V_41 , & V_53 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_18 ( V_10 , V_8 , NULL ) ;
if ( V_11 )
return V_11 ;
V_11 = F_19 ( V_10 ) ;
if ( V_11 )
goto V_54;
V_11 = F_20 ( V_8 ) ;
if ( V_11 )
goto V_54;
return 0 ;
V_54:
F_21 ( V_10 , V_8 ) ;
return V_11 ;
}
static int F_22 ( struct V_40 * V_41 )
{
struct V_7 * V_8 = F_23 ( V_41 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_24 ( V_8 ) ;
F_21 ( V_10 , V_8 ) ;
return 0 ;
}
