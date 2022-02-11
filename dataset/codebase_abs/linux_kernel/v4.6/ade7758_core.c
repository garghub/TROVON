int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_5 ( V_3 ) ;
V_9 -> V_11 [ 1 ] = V_4 ;
V_5 = F_6 ( V_9 -> V_12 , V_9 -> V_11 , 2 ) ;
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_13 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_14 V_15 [] = {
{
. V_16 = V_9 -> V_11 ,
. V_17 = 8 ,
. V_18 = 3 ,
}
} ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_5 ( V_3 ) ;
V_9 -> V_11 [ 1 ] = ( V_13 >> 8 ) & 0xFF ;
V_9 -> V_11 [ 2 ] = V_13 & 0xFF ;
V_5 = F_9 ( V_9 -> V_12 , V_15 , F_10 ( V_15 ) ) ;
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_11 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_3 V_13 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_14 V_15 [] = {
{
. V_16 = V_9 -> V_11 ,
. V_17 = 8 ,
. V_18 = 4 ,
}
} ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_5 ( V_3 ) ;
V_9 -> V_11 [ 1 ] = ( V_13 >> 16 ) & 0xFF ;
V_9 -> V_11 [ 2 ] = ( V_13 >> 8 ) & 0xFF ;
V_9 -> V_11 [ 3 ] = V_13 & 0xFF ;
V_5 = F_9 ( V_9 -> V_12 , V_15 , F_10 ( V_15 ) ) ;
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
int F_12 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_5 ;
struct V_14 V_15 [] = {
{
. V_16 = V_9 -> V_11 ,
. V_17 = 8 ,
. V_18 = 1 ,
. V_19 = 4 ,
} ,
{
. V_16 = & V_9 -> V_11 [ 1 ] ,
. V_20 = V_9 -> V_21 ,
. V_17 = 8 ,
. V_18 = 1 ,
} ,
} ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_13 ( V_3 ) ;
V_9 -> V_11 [ 1 ] = 0 ;
V_5 = F_9 ( V_9 -> V_12 , V_15 , F_10 ( V_15 ) ) ;
if ( V_5 ) {
F_14 ( & V_9 -> V_12 -> V_2 , L_1 ,
V_3 ) ;
goto V_22;
}
* V_4 = V_9 -> V_21 [ 0 ] ;
V_22:
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_15 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_5 ;
struct V_14 V_15 [] = {
{
. V_16 = V_9 -> V_11 ,
. V_17 = 8 ,
. V_18 = 1 ,
. V_19 = 4 ,
} ,
{
. V_16 = & V_9 -> V_11 [ 1 ] ,
. V_20 = V_9 -> V_21 ,
. V_17 = 8 ,
. V_18 = 2 ,
} ,
} ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_13 ( V_3 ) ;
V_9 -> V_11 [ 1 ] = 0 ;
V_9 -> V_11 [ 2 ] = 0 ;
V_5 = F_9 ( V_9 -> V_12 , V_15 , F_10 ( V_15 ) ) ;
if ( V_5 ) {
F_14 ( & V_9 -> V_12 -> V_2 , L_2 ,
V_3 ) ;
goto V_22;
}
* V_4 = ( V_9 -> V_21 [ 0 ] << 8 ) | V_9 -> V_21 [ 1 ] ;
V_22:
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_5 ;
struct V_14 V_15 [] = {
{
. V_16 = V_9 -> V_11 ,
. V_17 = 8 ,
. V_18 = 1 ,
. V_19 = 4 ,
} ,
{
. V_16 = & V_9 -> V_11 [ 1 ] ,
. V_20 = V_9 -> V_21 ,
. V_17 = 8 ,
. V_18 = 3 ,
} ,
} ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_13 ( V_3 ) ;
V_9 -> V_11 [ 1 ] = 0 ;
V_9 -> V_11 [ 2 ] = 0 ;
V_9 -> V_11 [ 3 ] = 0 ;
V_5 = F_9 ( V_9 -> V_12 , V_15 , F_10 ( V_15 ) ) ;
if ( V_5 ) {
F_14 ( & V_9 -> V_12 -> V_2 , L_3 ,
V_3 ) ;
goto V_22;
}
* V_4 = ( V_9 -> V_21 [ 0 ] << 16 ) | ( V_9 -> V_21 [ 1 ] << 8 ) | V_9 -> V_21 [ 2 ] ;
V_22:
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static T_4 F_17 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
char * V_25 )
{
int V_5 ;
T_1 V_4 = 0 ;
struct V_26 * V_27 = F_18 ( V_24 ) ;
V_5 = F_12 ( V_2 , V_27 -> V_28 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return sprintf ( V_25 , L_4 , V_4 ) ;
}
static T_4 F_19 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
char * V_25 )
{
int V_5 ;
T_2 V_4 = 0 ;
struct V_26 * V_27 = F_18 ( V_24 ) ;
V_5 = F_15 ( V_2 , V_27 -> V_28 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return sprintf ( V_25 , L_4 , V_4 ) ;
}
static T_4 F_20 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
char * V_25 )
{
int V_5 ;
T_3 V_4 = 0 ;
struct V_26 * V_27 = F_18 ( V_24 ) ;
V_5 = F_16 ( V_2 , V_27 -> V_28 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return sprintf ( V_25 , L_4 , V_4 & 0xFFFFFF ) ;
}
static T_4 F_21 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
const char * V_25 ,
T_5 V_18 )
{
struct V_26 * V_27 = F_18 ( V_24 ) ;
int V_5 ;
T_1 V_4 ;
V_5 = F_22 ( V_25 , 10 , & V_4 ) ;
if ( V_5 )
goto V_22;
V_5 = F_1 ( V_2 , V_27 -> V_28 , V_4 ) ;
V_22:
return V_5 ? V_5 : V_18 ;
}
static T_4 F_23 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
const char * V_25 ,
T_5 V_18 )
{
struct V_26 * V_27 = F_18 ( V_24 ) ;
int V_5 ;
T_2 V_4 ;
V_5 = F_24 ( V_25 , 10 , & V_4 ) ;
if ( V_5 )
goto V_22;
V_5 = F_8 ( V_2 , V_27 -> V_28 , V_4 ) ;
V_22:
return V_5 ? V_5 : V_18 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_5 ;
T_1 V_4 ;
V_5 = F_12 ( V_2 , V_29 , & V_4 ) ;
if ( V_5 < 0 ) {
F_14 ( V_2 , L_5 ) ;
return V_5 ;
}
V_4 |= F_26 ( 6 ) ;
V_5 = F_1 ( V_2 , V_29 , V_4 ) ;
if ( V_5 < 0 )
F_14 ( V_2 , L_6 ) ;
return V_5 ;
}
int F_27 ( struct V_1 * V_2 , bool V_30 )
{
int V_5 ;
T_3 V_31 ;
V_5 = F_16 ( V_2 , V_32 , & V_31 ) ;
if ( V_5 )
return V_5 ;
if ( V_30 )
V_31 |= F_26 ( 16 ) ;
else
V_31 &= ~ F_26 ( 16 ) ;
V_5 = F_11 ( V_2 , V_32 , V_31 ) ;
return V_5 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_5 ;
T_1 V_4 ;
V_5 = F_12 ( V_2 , V_29 , & V_4 ) ;
if ( V_5 < 0 ) {
F_14 ( V_2 , L_5 ) ;
return V_5 ;
}
V_4 |= 7 << 3 ;
V_5 = F_1 ( V_2 , V_29 , V_4 ) ;
if ( V_5 < 0 )
F_14 ( V_2 , L_6 ) ;
return V_5 ;
}
static int F_29 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = & V_7 -> V_2 ;
int V_5 ;
V_9 -> V_12 -> V_33 = V_34 ;
F_30 ( V_9 -> V_12 ) ;
V_5 = F_27 ( V_2 , false ) ;
if ( V_5 ) {
F_14 ( V_2 , L_7 ) ;
goto V_35;
}
F_25 ( V_2 ) ;
F_31 ( V_36 ) ;
V_35:
return V_5 ;
}
static T_4 F_32 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
char * V_25 )
{
int V_5 ;
T_1 V_37 ;
int V_38 ;
V_5 = F_12 ( V_2 ,
V_39 ,
& V_37 ) ;
if ( V_5 )
return V_5 ;
V_37 = ( V_37 >> 5 ) & 0x3 ;
V_38 = 26040 / ( 1 << V_37 ) ;
return sprintf ( V_25 , L_8 , V_38 ) ;
}
static T_4 F_33 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
const char * V_25 ,
T_5 V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_4 ;
int V_5 ;
T_1 V_40 , V_37 ;
V_5 = F_24 ( V_25 , 10 , & V_4 ) ;
if ( V_5 )
return V_5 ;
F_4 ( & V_7 -> V_41 ) ;
switch ( V_4 ) {
case 26040 :
V_37 = 0 ;
break;
case 13020 :
V_37 = 1 ;
break;
case 6510 :
V_37 = 2 ;
break;
case 3255 :
V_37 = 3 ;
break;
default:
V_5 = - V_42 ;
goto V_43;
}
V_5 = F_12 ( V_2 ,
V_39 ,
& V_40 ) ;
if ( V_5 )
goto V_43;
V_40 &= ~ ( 5 << 3 ) ;
V_40 |= V_37 << 5 ;
V_5 = F_1 ( V_2 ,
V_39 ,
V_40 ) ;
V_43:
F_7 ( & V_7 -> V_41 ) ;
return V_5 ? V_5 : V_18 ;
}
static int F_34 ( struct V_44 * V_45 )
{
int V_5 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
V_7 = F_35 ( & V_45 -> V_2 , sizeof( * V_9 ) ) ;
if ( ! V_7 )
return - V_46 ;
V_9 = F_3 ( V_7 ) ;
F_36 ( V_45 , V_7 ) ;
V_9 -> V_21 = F_37 ( V_47 , sizeof( * V_9 -> V_21 ) , V_48 ) ;
if ( ! V_9 -> V_21 )
return - V_46 ;
V_9 -> V_11 = F_37 ( V_49 , sizeof( * V_9 -> V_11 ) , V_48 ) ;
if ( ! V_9 -> V_11 ) {
V_5 = - V_46 ;
goto V_50;
}
V_9 -> V_12 = V_45 ;
F_38 ( & V_9 -> V_10 ) ;
V_7 -> V_51 = V_45 -> V_2 . V_52 -> V_51 ;
V_7 -> V_2 . V_53 = & V_45 -> V_2 ;
V_7 -> V_54 = & V_55 ;
V_7 -> V_56 = V_57 ;
V_7 -> V_58 = V_59 ;
V_7 -> V_60 = F_10 ( V_59 ) ;
V_5 = F_39 ( V_7 ) ;
if ( V_5 )
goto V_61;
V_5 = F_29 ( V_7 ) ;
if ( V_5 )
goto V_62;
if ( V_45 -> V_63 ) {
V_5 = F_40 ( V_7 ) ;
if ( V_5 )
goto V_62;
}
V_5 = F_41 ( V_7 ) ;
if ( V_5 )
goto V_64;
return 0 ;
V_64:
if ( V_45 -> V_63 )
F_42 ( V_7 ) ;
V_62:
F_43 ( V_7 ) ;
V_61:
F_44 ( V_9 -> V_11 ) ;
V_50:
F_44 ( V_9 -> V_21 ) ;
return V_5 ;
}
static int F_45 ( struct V_44 * V_45 )
{
struct V_6 * V_7 = F_46 ( V_45 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_47 ( V_7 ) ;
F_28 ( & V_7 -> V_2 ) ;
F_42 ( V_7 ) ;
F_43 ( V_7 ) ;
F_44 ( V_9 -> V_11 ) ;
F_44 ( V_9 -> V_21 ) ;
return 0 ;
}
