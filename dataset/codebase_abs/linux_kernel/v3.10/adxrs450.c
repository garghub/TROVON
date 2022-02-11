static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * V_4 )
{
struct V_5 V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_3 V_9 ;
int V_10 ;
struct V_11 V_12 [] = {
{
. V_13 = & V_8 -> V_9 ,
. V_14 = 8 ,
. V_15 = sizeof( V_8 -> V_9 ) ,
. V_16 = 1 ,
} , {
. V_17 = & V_8 -> V_18 ,
. V_14 = 8 ,
. V_15 = sizeof( V_8 -> V_18 ) ,
} ,
} ;
F_3 ( & V_8 -> V_19 ) ;
V_9 = V_20 | ( V_3 << 17 ) ;
if ( ! ( F_4 ( V_9 ) & 1 ) )
V_9 |= V_21 ;
V_8 -> V_9 = F_5 ( V_9 ) ;
F_6 ( & V_6 ) ;
F_7 ( & V_12 [ 0 ] , & V_6 ) ;
F_7 ( & V_12 [ 1 ] , & V_6 ) ;
V_10 = F_8 ( V_8 -> V_22 , & V_6 ) ;
if ( V_10 ) {
F_9 ( & V_8 -> V_22 -> V_23 , L_1 ,
V_3 ) ;
goto V_24;
}
* V_4 = ( F_10 ( V_8 -> V_18 ) >> 5 ) & 0xFFFF ;
V_24:
F_11 ( & V_8 -> V_19 ) ;
return V_10 ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_3 V_9 ;
int V_10 ;
F_3 ( & V_8 -> V_19 ) ;
V_9 = V_25 | ( V_3 << 17 ) | ( V_4 << 1 ) ;
if ( ! ( F_4 ( V_9 ) & 1 ) )
V_9 |= V_21 ;
V_8 -> V_9 = F_5 ( V_9 ) ;
V_10 = F_13 ( V_8 -> V_22 , & V_8 -> V_9 , sizeof( V_8 -> V_9 ) ) ;
if ( V_10 )
F_9 ( & V_8 -> V_22 -> V_23 , L_2 ,
V_3 ) ;
F_14 ( 100 , 1000 ) ;
F_11 ( & V_8 -> V_19 ) ;
return V_10 ;
}
static int F_15 ( struct V_1 * V_2 , T_4 * V_4 )
{
struct V_5 V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_10 ;
struct V_11 V_12 [] = {
{
. V_13 = & V_8 -> V_9 ,
. V_14 = 8 ,
. V_15 = sizeof( V_8 -> V_9 ) ,
. V_16 = 1 ,
} , {
. V_17 = & V_8 -> V_18 ,
. V_14 = 8 ,
. V_15 = sizeof( V_8 -> V_18 ) ,
} ,
} ;
F_3 ( & V_8 -> V_19 ) ;
V_8 -> V_9 = F_5 ( V_26 ) ;
F_6 ( & V_6 ) ;
F_7 ( & V_12 [ 0 ] , & V_6 ) ;
F_7 ( & V_12 [ 1 ] , & V_6 ) ;
V_10 = F_8 ( V_8 -> V_22 , & V_6 ) ;
if ( V_10 ) {
F_9 ( & V_8 -> V_22 -> V_23 , L_3 ) ;
goto V_24;
}
* V_4 = ( F_10 ( V_8 -> V_18 ) >> 10 ) & 0xFFFF ;
V_24:
F_11 ( & V_8 -> V_19 ) ;
return V_10 ;
}
static int F_16 ( struct V_7 * V_8 ,
T_3 * V_4 , char V_27 )
{
int V_10 ;
T_3 V_9 ;
struct V_11 V_12 = {
. V_13 = & V_8 -> V_9 ,
. V_17 = & V_8 -> V_18 ,
. V_14 = 8 ,
. V_15 = sizeof( V_8 -> V_9 ) ,
} ;
F_3 ( & V_8 -> V_19 ) ;
V_9 = V_26 ;
if ( V_27 )
V_9 |= ( V_28 | V_21 ) ;
V_8 -> V_9 = F_5 ( V_9 ) ;
V_10 = F_17 ( V_8 -> V_22 , & V_12 , 1 ) ;
if ( V_10 ) {
F_9 ( & V_8 -> V_22 -> V_23 , L_4 ) ;
goto V_24;
}
* V_4 = F_10 ( V_8 -> V_18 ) ;
V_24:
F_11 ( & V_8 -> V_19 ) ;
return V_10 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_3 V_29 ;
T_2 V_30 ;
int V_10 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_19 ( V_31 * 2 ) ;
V_10 = F_16 ( V_8 , & V_29 , 1 ) ;
if ( V_10 )
return V_10 ;
if ( V_29 != 0x01 )
F_20 ( & V_8 -> V_22 -> V_23 , L_5 ) ;
F_19 ( V_31 ) ;
V_10 = F_16 ( V_8 , & V_29 , 0 ) ;
if ( V_10 )
return V_10 ;
F_19 ( V_31 ) ;
V_10 = F_16 ( V_8 , & V_29 , 0 ) ;
if ( V_10 )
return V_10 ;
if ( ( ( V_29 & 0xff ) | 0x01 ) != 0xff || F_21 ( V_29 ) != 2 ) {
F_9 ( & V_8 -> V_22 -> V_23 , L_6 ) ;
return - V_32 ;
}
V_10 = F_16 ( V_8 , & V_29 , 0 ) ;
if ( V_10 )
return V_10 ;
if ( ( ( V_29 & 0xff ) | 0x01 ) != 0xff || F_21 ( V_29 ) != 2 ) {
F_9 ( & V_8 -> V_22 -> V_23 , L_7 ) ;
return - V_32 ;
}
V_10 = F_1 ( V_2 , V_33 , & V_30 ) ;
if ( V_10 )
return V_10 ;
if ( V_30 & 0x0fff ) {
F_9 ( & V_8 -> V_22 -> V_23 , L_8 ) ;
return - V_34 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_35 const * V_36 ,
int V_4 ,
int V_37 ,
long V_38 )
{
int V_10 ;
switch ( V_38 ) {
case V_39 :
if ( V_4 < - 0x400 || V_4 >= 0x400 )
return - V_34 ;
V_10 = F_12 ( V_2 ,
V_40 , V_4 ) ;
break;
default:
V_10 = - V_34 ;
break;
}
return V_10 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_35 const * V_36 ,
int * V_4 ,
int * V_37 ,
long V_38 )
{
int V_10 ;
T_4 V_29 ;
switch ( V_38 ) {
case V_41 :
switch ( V_36 -> type ) {
case V_42 :
V_10 = F_15 ( V_2 , & V_29 ) ;
if ( V_10 )
break;
* V_4 = V_29 ;
V_10 = V_43 ;
break;
case V_44 :
V_10 = F_1 ( V_2 ,
V_45 , & V_29 ) ;
if ( V_10 )
break;
* V_4 = ( V_29 >> 6 ) + 225 ;
V_10 = V_43 ;
break;
default:
V_10 = - V_34 ;
break;
}
break;
case V_46 :
switch ( V_36 -> type ) {
case V_42 :
* V_4 = 0 ;
* V_37 = 218166 ;
return V_47 ;
case V_44 :
* V_4 = 200 ;
* V_37 = 0 ;
return V_43 ;
default:
return - V_34 ;
}
break;
case V_48 :
V_10 = F_1 ( V_2 , V_49 , & V_29 ) ;
if ( V_10 )
break;
* V_4 = V_29 ;
V_10 = V_43 ;
break;
case V_39 :
V_10 = F_1 ( V_2 , V_40 , & V_29 ) ;
if ( V_10 )
break;
* V_4 = F_24 ( V_29 , 9 ) ;
V_10 = V_43 ;
break;
default:
V_10 = - V_34 ;
break;
}
return V_10 ;
}
static int F_25 ( struct V_50 * V_51 )
{
int V_10 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
V_2 = F_26 ( sizeof( * V_8 ) ) ;
if ( V_2 == NULL ) {
V_10 = - V_52 ;
goto V_24;
}
V_8 = F_2 ( V_2 ) ;
V_8 -> V_22 = V_51 ;
F_27 ( & V_8 -> V_19 ) ;
F_28 ( V_51 , V_2 ) ;
V_2 -> V_23 . V_53 = & V_51 -> V_23 ;
V_2 -> V_54 = & V_55 ;
V_2 -> V_56 = V_57 ;
V_2 -> V_58 =
V_59 [ F_29 ( V_51 ) -> V_60 ] ;
V_2 -> V_61 = F_30 ( V_59 ) ;
V_2 -> V_62 = V_51 -> V_23 . V_63 -> V_62 ;
V_10 = F_31 ( V_2 ) ;
if ( V_10 )
goto V_64;
V_10 = F_18 ( V_2 ) ;
if ( V_10 )
goto V_65;
return 0 ;
V_65:
F_32 ( V_2 ) ;
V_64:
F_33 ( V_2 ) ;
V_24:
return V_10 ;
}
static int F_34 ( struct V_50 * V_51 )
{
F_32 ( F_35 ( V_51 ) ) ;
F_33 ( F_35 ( V_51 ) ) ;
return 0 ;
}
