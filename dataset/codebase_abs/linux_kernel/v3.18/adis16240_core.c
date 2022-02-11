static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ,
unsigned V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_11 ;
T_2 V_12 = 0 ;
unsigned V_13 = 16 - V_6 ;
struct V_14 * V_15 = F_4 ( V_4 ) ;
V_11 = F_5 ( V_10 ,
V_15 -> V_16 , ( V_17 * ) & V_12 ) ;
if ( V_11 )
return V_11 ;
if ( V_12 & V_18 )
F_6 ( V_10 ) ;
V_12 = ( ( T_2 ) ( V_12 << V_13 ) >> V_13 ) ;
return sprintf ( V_5 , L_1 , V_12 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
T_1 V_11 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_8 ( & V_8 -> V_19 ) ;
V_11 = F_1 ( V_2 , V_4 , V_5 , 12 ) ;
F_9 ( & V_8 -> V_19 ) ;
return V_11 ;
}
static int F_10 ( struct V_7 * V_8 ,
struct V_20 const * V_21 ,
int * V_12 , int * V_22 ,
long V_23 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_11 ;
int V_6 ;
T_3 V_24 ;
T_2 V_25 ;
switch ( V_23 ) {
case V_26 :
return F_11 ( V_8 , V_21 ,
V_18 , V_12 ) ;
case V_27 :
switch ( V_21 -> type ) {
case V_28 :
if ( V_21 -> V_29 == 0 ) {
* V_12 = 4 ;
* V_22 = 880000 ;
return V_30 ;
}
return - V_31 ;
case V_32 :
* V_12 = 244 ;
* V_22 = 0 ;
return V_30 ;
case V_33 :
* V_12 = 0 ;
* V_22 = F_12 ( 51400 ) ;
return V_30 ;
default:
return - V_31 ;
}
break;
case V_34 :
* V_12 = 0 ;
* V_22 = F_12 ( 51400 ) ;
return V_30 ;
case V_35 :
* V_12 = 25000 / 244 - 0x133 ;
return V_36 ;
case V_37 :
V_6 = 10 ;
F_8 ( & V_8 -> V_19 ) ;
V_24 = V_38 [ V_21 -> V_39 ] [ 0 ] ;
V_11 = F_5 ( V_10 , V_24 , & V_25 ) ;
if ( V_11 ) {
F_9 ( & V_8 -> V_19 ) ;
return V_11 ;
}
V_25 &= ( 1 << V_6 ) - 1 ;
V_25 = ( T_2 ) ( V_25 << ( 16 - V_6 ) ) >> ( 16 - V_6 ) ;
* V_12 = V_25 ;
F_9 ( & V_8 -> V_19 ) ;
return V_36 ;
case V_40 :
V_6 = 10 ;
F_8 ( & V_8 -> V_19 ) ;
V_24 = V_38 [ V_21 -> V_39 ] [ 1 ] ;
V_11 = F_5 ( V_10 , V_24 , & V_25 ) ;
if ( V_11 ) {
F_9 ( & V_8 -> V_19 ) ;
return V_11 ;
}
V_25 &= ( 1 << V_6 ) - 1 ;
V_25 = ( T_2 ) ( V_25 << ( 16 - V_6 ) ) >> ( 16 - V_6 ) ;
* V_12 = V_25 ;
F_9 ( & V_8 -> V_19 ) ;
return V_36 ;
}
return - V_31 ;
}
static int F_13 ( struct V_7 * V_8 ,
struct V_20 const * V_21 ,
int V_12 ,
int V_22 ,
long V_23 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_6 = 10 ;
T_2 V_25 ;
T_3 V_24 ;
switch ( V_23 ) {
case V_37 :
V_25 = V_12 & ( ( 1 << V_6 ) - 1 ) ;
V_24 = V_38 [ V_21 -> V_39 ] [ 0 ] ;
return F_14 ( V_10 , V_24 , V_25 ) ;
}
return - V_31 ;
}
static int F_15 ( struct V_41 * V_42 )
{
int V_11 ;
struct V_9 * V_10 ;
struct V_7 * V_8 ;
V_8 = F_16 ( & V_42 -> V_2 , sizeof( * V_10 ) ) ;
if ( ! V_8 )
return - V_43 ;
V_10 = F_3 ( V_8 ) ;
F_17 ( V_42 , V_8 ) ;
V_8 -> V_44 = V_42 -> V_2 . V_45 -> V_44 ;
V_8 -> V_2 . V_46 = & V_42 -> V_2 ;
V_8 -> V_47 = & V_48 ;
V_8 -> V_49 = V_50 ;
V_8 -> V_51 = F_18 ( V_50 ) ;
V_8 -> V_52 = V_53 ;
V_11 = F_19 ( V_10 , V_8 , V_42 , & V_54 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_20 ( V_10 , V_8 , NULL ) ;
if ( V_11 )
return V_11 ;
V_11 = F_21 ( V_10 ) ;
if ( V_11 )
goto V_55;
V_11 = F_22 ( V_8 ) ;
if ( V_11 )
goto V_55;
return 0 ;
V_55:
F_23 ( V_10 , V_8 ) ;
return V_11 ;
}
static int F_24 ( struct V_41 * V_42 )
{
struct V_7 * V_8 = F_25 ( V_42 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_26 ( V_8 ) ;
F_23 ( V_10 , V_8 ) ;
return 0 ;
}
