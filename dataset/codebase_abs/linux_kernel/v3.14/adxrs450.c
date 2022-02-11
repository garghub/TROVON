static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_3 V_7 ;
int V_8 ;
struct V_9 V_10 [] = {
{
. V_11 = & V_6 -> V_7 ,
. V_12 = 8 ,
. V_13 = sizeof( V_6 -> V_7 ) ,
. V_14 = 1 ,
} , {
. V_15 = & V_6 -> V_16 ,
. V_12 = 8 ,
. V_13 = sizeof( V_6 -> V_16 ) ,
} ,
} ;
F_3 ( & V_6 -> V_17 ) ;
V_7 = V_18 | ( V_3 << 17 ) ;
if ( ! ( F_4 ( V_7 ) & 1 ) )
V_7 |= V_19 ;
V_6 -> V_7 = F_5 ( V_7 ) ;
V_8 = F_6 ( V_6 -> V_20 , V_10 , F_7 ( V_10 ) ) ;
if ( V_8 ) {
F_8 ( & V_6 -> V_20 -> V_21 , L_1 ,
V_3 ) ;
goto V_22;
}
* V_4 = ( F_9 ( V_6 -> V_16 ) >> 5 ) & 0xFFFF ;
V_22:
F_10 ( & V_6 -> V_17 ) ;
return V_8 ;
}
static int F_11 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_3 V_7 ;
int V_8 ;
F_3 ( & V_6 -> V_17 ) ;
V_7 = V_23 | ( V_3 << 17 ) | ( V_4 << 1 ) ;
if ( ! ( F_4 ( V_7 ) & 1 ) )
V_7 |= V_19 ;
V_6 -> V_7 = F_5 ( V_7 ) ;
V_8 = F_12 ( V_6 -> V_20 , & V_6 -> V_7 , sizeof( V_6 -> V_7 ) ) ;
if ( V_8 )
F_8 ( & V_6 -> V_20 -> V_21 , L_2 ,
V_3 ) ;
F_13 ( 100 , 1000 ) ;
F_10 ( & V_6 -> V_17 ) ;
return V_8 ;
}
static int F_14 ( struct V_1 * V_2 , T_4 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_8 ;
struct V_9 V_10 [] = {
{
. V_11 = & V_6 -> V_7 ,
. V_12 = 8 ,
. V_13 = sizeof( V_6 -> V_7 ) ,
. V_14 = 1 ,
} , {
. V_15 = & V_6 -> V_16 ,
. V_12 = 8 ,
. V_13 = sizeof( V_6 -> V_16 ) ,
} ,
} ;
F_3 ( & V_6 -> V_17 ) ;
V_6 -> V_7 = F_5 ( V_24 ) ;
V_8 = F_6 ( V_6 -> V_20 , V_10 , F_7 ( V_10 ) ) ;
if ( V_8 ) {
F_8 ( & V_6 -> V_20 -> V_21 , L_3 ) ;
goto V_22;
}
* V_4 = ( F_9 ( V_6 -> V_16 ) >> 10 ) & 0xFFFF ;
V_22:
F_10 ( & V_6 -> V_17 ) ;
return V_8 ;
}
static int F_15 ( struct V_5 * V_6 ,
T_3 * V_4 , char V_25 )
{
int V_8 ;
T_3 V_7 ;
struct V_9 V_10 = {
. V_11 = & V_6 -> V_7 ,
. V_15 = & V_6 -> V_16 ,
. V_12 = 8 ,
. V_13 = sizeof( V_6 -> V_7 ) ,
} ;
F_3 ( & V_6 -> V_17 ) ;
V_7 = V_24 ;
if ( V_25 )
V_7 |= ( V_26 | V_19 ) ;
V_6 -> V_7 = F_5 ( V_7 ) ;
V_8 = F_6 ( V_6 -> V_20 , & V_10 , 1 ) ;
if ( V_8 ) {
F_8 ( & V_6 -> V_20 -> V_21 , L_4 ) ;
goto V_22;
}
* V_4 = F_9 ( V_6 -> V_16 ) ;
V_22:
F_10 ( & V_6 -> V_17 ) ;
return V_8 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_3 V_27 ;
T_2 V_28 ;
int V_8 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_17 ( V_29 * 2 ) ;
V_8 = F_15 ( V_6 , & V_27 , 1 ) ;
if ( V_8 )
return V_8 ;
if ( V_27 != 0x01 )
F_18 ( & V_6 -> V_20 -> V_21 , L_5 ) ;
F_17 ( V_29 ) ;
V_8 = F_15 ( V_6 , & V_27 , 0 ) ;
if ( V_8 )
return V_8 ;
F_17 ( V_29 ) ;
V_8 = F_15 ( V_6 , & V_27 , 0 ) ;
if ( V_8 )
return V_8 ;
if ( ( ( V_27 & 0xff ) | 0x01 ) != 0xff || F_19 ( V_27 ) != 2 ) {
F_8 ( & V_6 -> V_20 -> V_21 , L_6 ) ;
return - V_30 ;
}
V_8 = F_15 ( V_6 , & V_27 , 0 ) ;
if ( V_8 )
return V_8 ;
if ( ( ( V_27 & 0xff ) | 0x01 ) != 0xff || F_19 ( V_27 ) != 2 ) {
F_8 ( & V_6 -> V_20 -> V_21 , L_7 ) ;
return - V_30 ;
}
V_8 = F_1 ( V_2 , V_31 , & V_28 ) ;
if ( V_8 )
return V_8 ;
if ( V_28 & 0x0fff ) {
F_8 ( & V_6 -> V_20 -> V_21 , L_8 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_33 const * V_34 ,
int V_4 ,
int V_35 ,
long V_36 )
{
int V_8 ;
switch ( V_36 ) {
case V_37 :
if ( V_4 < - 0x400 || V_4 >= 0x400 )
return - V_32 ;
V_8 = F_11 ( V_2 ,
V_38 , V_4 ) ;
break;
default:
V_8 = - V_32 ;
break;
}
return V_8 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_33 const * V_34 ,
int * V_4 ,
int * V_35 ,
long V_36 )
{
int V_8 ;
T_4 V_27 ;
switch ( V_36 ) {
case V_39 :
switch ( V_34 -> type ) {
case V_40 :
V_8 = F_14 ( V_2 , & V_27 ) ;
if ( V_8 )
break;
* V_4 = V_27 ;
V_8 = V_41 ;
break;
case V_42 :
V_8 = F_1 ( V_2 ,
V_43 , & V_27 ) ;
if ( V_8 )
break;
* V_4 = ( V_27 >> 6 ) + 225 ;
V_8 = V_41 ;
break;
default:
V_8 = - V_32 ;
break;
}
break;
case V_44 :
switch ( V_34 -> type ) {
case V_40 :
* V_4 = 0 ;
* V_35 = 218166 ;
return V_45 ;
case V_42 :
* V_4 = 200 ;
* V_35 = 0 ;
return V_41 ;
default:
return - V_32 ;
}
case V_46 :
V_8 = F_1 ( V_2 , V_47 , & V_27 ) ;
if ( V_8 )
break;
* V_4 = V_27 ;
V_8 = V_41 ;
break;
case V_37 :
V_8 = F_1 ( V_2 , V_38 , & V_27 ) ;
if ( V_8 )
break;
* V_4 = F_22 ( V_27 , 9 ) ;
V_8 = V_41 ;
break;
default:
V_8 = - V_32 ;
break;
}
return V_8 ;
}
static int F_23 ( struct V_48 * V_49 )
{
int V_8 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_24 ( & V_49 -> V_21 , sizeof( * V_6 ) ) ;
if ( ! V_2 )
return - V_50 ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_20 = V_49 ;
F_25 ( & V_6 -> V_17 ) ;
F_26 ( V_49 , V_2 ) ;
V_2 -> V_21 . V_51 = & V_49 -> V_21 ;
V_2 -> V_52 = & V_53 ;
V_2 -> V_54 = V_55 ;
V_2 -> V_56 =
V_57 [ F_27 ( V_49 ) -> V_58 ] ;
V_2 -> V_59 = F_7 ( V_57 ) ;
V_2 -> V_60 = V_49 -> V_21 . V_61 -> V_60 ;
V_8 = F_28 ( & V_49 -> V_21 , V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_16 ( V_2 ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
