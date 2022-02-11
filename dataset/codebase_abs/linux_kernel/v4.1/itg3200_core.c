int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_3 ( V_6 -> V_7 , 0x80 | V_3 , V_4 ) ;
}
int F_4 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_8 ;
V_8 = F_5 ( V_6 -> V_7 , V_3 ) ;
if ( V_8 < 0 )
return V_8 ;
* V_4 = V_8 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_9 ,
int * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_6 -> V_7 ;
int V_8 ;
T_2 V_12 ;
struct V_13 V_14 [ 2 ] = {
{
. V_15 = V_11 -> V_15 ,
. V_16 = V_11 -> V_16 ,
. V_17 = 1 ,
. V_18 = ( char * ) & V_9 ,
} ,
{
. V_15 = V_11 -> V_15 ,
. V_16 = V_11 -> V_16 | V_19 ,
. V_17 = 2 ,
. V_18 = ( char * ) & V_12 ,
} ,
} ;
V_9 |= 0x80 ;
V_8 = F_7 ( V_11 -> V_20 , V_14 , 2 ) ;
F_8 ( & V_12 ) ;
* V_4 = V_12 ;
return ( V_8 == 2 ) ? 0 : V_8 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_21 * V_22 ,
int * V_4 , int * V_23 , long V_24 )
{
int V_8 = 0 ;
T_1 V_25 ;
T_1 V_26 ;
switch ( V_24 ) {
case V_27 :
V_25 = ( T_1 ) V_22 -> V_28 ;
V_8 = F_6 ( V_2 , V_25 , V_4 ) ;
return V_29 ;
case V_30 :
* V_4 = 0 ;
if ( V_22 -> type == V_31 )
* V_23 = 1000000000 / 280 ;
else
* V_23 = 1214142 ;
return V_32 ;
case V_33 :
* V_4 = 23000 ;
return V_29 ;
case V_34 :
V_8 = F_4 ( V_2 , V_35 , & V_26 ) ;
if ( V_8 )
return V_8 ;
* V_4 = ( V_26 & V_36 ) ? 1000 : 8000 ;
V_8 = F_4 ( V_2 ,
V_37 ,
& V_26 ) ;
if ( V_8 )
return V_8 ;
* V_4 /= V_26 + 1 ;
return V_29 ;
default:
return - V_38 ;
}
}
static int F_10 ( struct V_1 * V_2 ,
struct V_21 const * V_22 ,
int V_4 ,
int V_23 ,
long V_39 )
{
int V_8 ;
T_1 V_40 ;
switch ( V_39 ) {
case V_34 :
if ( V_4 == 0 || V_23 != 0 )
return - V_38 ;
F_11 ( & V_2 -> V_41 ) ;
V_8 = F_4 ( V_2 , V_35 , & V_40 ) ;
if ( V_8 ) {
F_12 ( & V_2 -> V_41 ) ;
return V_8 ;
}
V_40 = ( ( V_40 & V_36 ) ? 1000u : 8000u ) / V_4 - 1 ;
V_8 = F_1 ( V_2 ,
V_37 ,
V_40 ) ;
F_12 ( & V_2 -> V_41 ) ;
return V_8 ;
default:
return - V_38 ;
}
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_8 ;
F_14 ( & V_6 -> V_7 -> V_42 , L_1 ) ;
V_8 = F_1 ( V_2 ,
V_43 ,
V_44 ) ;
if ( V_8 ) {
F_15 ( & V_6 -> V_7 -> V_42 , L_2 ) ;
goto V_45;
}
F_16 ( 1500 ) ;
V_8 = F_1 ( V_2 ,
V_46 ,
V_47 |
V_48 |
V_49 |
V_50 ) ;
if ( V_8 )
F_15 ( & V_6 -> V_7 -> V_42 , L_3 ) ;
V_45:
return V_8 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_8 ;
V_8 = F_4 ( V_2 , V_35 , & V_4 ) ;
if ( V_8 )
goto V_51;
V_4 |= V_52 ;
return F_1 ( V_2 , V_35 , V_4 ) ;
V_51:
return V_8 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_8 ;
T_1 V_4 ;
V_8 = F_13 ( V_2 ) ;
if ( V_8 )
goto V_51;
V_8 = F_4 ( V_2 , V_53 , & V_4 ) ;
if ( V_8 )
goto V_51;
if ( ( ( V_4 >> 1 ) & 0x3f ) != 0x34 ) {
F_15 ( & V_6 -> V_7 -> V_42 , L_4 , V_4 ) ;
V_8 = - V_54 ;
goto V_51;
}
V_8 = F_17 ( V_2 ) ;
V_51:
return V_8 ;
}
static int F_19 ( struct V_10 * V_11 ,
const struct V_55 * V_56 )
{
int V_8 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
F_14 ( & V_11 -> V_42 , L_5 , V_11 -> V_57 ) ;
V_2 = F_20 ( & V_11 -> V_42 , sizeof( * V_6 ) ) ;
if ( ! V_2 )
return - V_58 ;
V_6 = F_2 ( V_2 ) ;
F_21 ( V_11 , V_2 ) ;
V_6 -> V_7 = V_11 ;
V_2 -> V_42 . V_59 = & V_11 -> V_42 ;
V_2 -> V_60 = V_11 -> V_42 . V_61 -> V_60 ;
V_2 -> V_62 = V_63 ;
V_2 -> V_64 = F_22 ( V_63 ) ;
V_2 -> V_65 = V_66 ;
V_2 -> V_24 = & V_67 ;
V_2 -> V_68 = V_69 ;
V_8 = F_23 ( V_2 ) ;
if ( V_8 )
return V_8 ;
if ( V_11 -> V_57 ) {
V_8 = F_24 ( V_2 ) ;
if ( V_8 )
goto V_70;
}
V_8 = F_18 ( V_2 ) ;
if ( V_8 )
goto V_71;
V_8 = F_25 ( V_2 ) ;
if ( V_8 )
goto V_71;
return 0 ;
V_71:
if ( V_11 -> V_57 )
F_26 ( V_2 ) ;
V_70:
F_27 ( V_2 ) ;
return V_8 ;
}
static int F_28 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_29 ( V_11 ) ;
F_30 ( V_2 ) ;
if ( V_11 -> V_57 )
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
static int T_3 F_31 ( struct V_72 * V_42 )
{
struct V_1 * V_2 = F_32 ( V_42 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_14 ( & V_6 -> V_7 -> V_42 , L_6 ) ;
return F_1 ( V_2 , V_43 ,
V_73 ) ;
}
static int T_3 F_33 ( struct V_72 * V_42 )
{
struct V_1 * V_2 = F_32 ( V_42 ) ;
return F_18 ( V_2 ) ;
}
