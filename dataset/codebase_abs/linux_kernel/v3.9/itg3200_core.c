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
switch ( V_24 ) {
case V_26 :
V_25 = ( T_1 ) V_22 -> V_27 ;
V_8 = F_6 ( V_2 , V_25 , V_4 ) ;
return V_28 ;
case V_29 :
* V_4 = 0 ;
if ( V_22 -> type == V_30 )
* V_23 = 1000000000 / 280 ;
else
* V_23 = 1214142 ;
return V_31 ;
case V_32 :
* V_4 = 23000 ;
return V_28 ;
default:
return - V_33 ;
}
return V_8 ;
}
static T_3 F_10 ( struct V_34 * V_35 ,
struct V_36 * V_37 , char * V_18 )
{
struct V_1 * V_2 = F_11 ( V_35 ) ;
int V_8 , V_38 ;
T_1 V_4 ;
V_8 = F_4 ( V_2 , V_39 , & V_4 ) ;
if ( V_8 )
return V_8 ;
V_38 = ( V_4 & V_40 ) ? 1000 : 8000 ;
V_8 = F_4 ( V_2 , V_41 , & V_4 ) ;
if ( V_8 )
return V_8 ;
V_38 /= V_4 + 1 ;
return sprintf ( V_18 , L_1 , V_38 ) ;
}
static T_3 F_12 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
const char * V_18 ,
T_4 V_17 )
{
struct V_1 * V_2 = F_11 ( V_35 ) ;
unsigned V_4 ;
int V_8 ;
T_1 V_42 ;
V_8 = F_13 ( V_18 , 10 , & V_4 ) ;
if ( V_8 )
return V_8 ;
F_14 ( & V_2 -> V_43 ) ;
V_8 = F_4 ( V_2 , V_39 , & V_42 ) ;
if ( V_8 )
goto V_44;
if ( V_4 == 0 ) {
V_8 = - V_33 ;
goto V_44;
}
V_42 = ( ( V_42 & V_40 ) ? 1000u : 8000u ) / V_4 - 1 ;
V_8 = F_1 ( V_2 , V_41 , V_42 ) ;
V_44:
F_15 ( & V_2 -> V_43 ) ;
return V_8 ? V_8 : V_17 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_8 ;
F_17 ( & V_6 -> V_7 -> V_35 , L_2 ) ;
V_8 = F_1 ( V_2 ,
V_45 ,
V_46 ) ;
if ( V_8 ) {
F_18 ( & V_6 -> V_7 -> V_35 , L_3 ) ;
goto V_47;
}
F_19 ( 1500 ) ;
V_8 = F_1 ( V_2 ,
V_48 ,
V_49 |
V_50 |
V_51 |
V_52 ) ;
if ( V_8 )
F_18 ( & V_6 -> V_7 -> V_35 , L_4 ) ;
V_47:
return V_8 ;
}
static int F_20 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_8 ;
V_8 = F_4 ( V_2 , V_39 , & V_4 ) ;
if ( V_8 )
goto V_44;
V_4 |= V_53 ;
return F_1 ( V_2 , V_39 , V_4 ) ;
V_44:
return V_8 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_8 ;
T_1 V_4 ;
V_8 = F_4 ( V_2 , V_54 , & V_4 ) ;
if ( V_8 )
goto V_44;
if ( ( ( V_4 >> 1 ) & 0x3f ) != 0x34 ) {
F_18 ( & V_6 -> V_7 -> V_35 , L_5 , V_4 ) ;
V_8 = - V_55 ;
goto V_44;
}
V_8 = F_16 ( V_2 ) ;
if ( V_8 )
goto V_44;
V_8 = F_20 ( V_2 ) ;
V_44:
return V_8 ;
}
static int F_22 ( struct V_10 * V_11 ,
const struct V_56 * V_57 )
{
int V_8 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
F_17 ( & V_11 -> V_35 , L_6 , V_11 -> V_58 ) ;
V_2 = F_23 ( sizeof( * V_6 ) ) ;
if ( V_2 == NULL ) {
V_8 = - V_59 ;
goto V_47;
}
V_6 = F_2 ( V_2 ) ;
F_24 ( V_11 , V_2 ) ;
V_6 -> V_7 = V_11 ;
V_2 -> V_35 . V_60 = & V_11 -> V_35 ;
V_2 -> V_61 = V_11 -> V_35 . V_62 -> V_61 ;
V_2 -> V_63 = V_64 ;
V_2 -> V_65 = F_25 ( V_64 ) ;
V_2 -> V_66 = V_67 ;
V_2 -> V_24 = & V_68 ;
V_2 -> V_69 = V_70 ;
V_8 = F_26 ( V_2 ) ;
if ( V_8 )
goto V_71;
if ( V_11 -> V_58 ) {
V_8 = F_27 ( V_2 ) ;
if ( V_8 )
goto V_72;
}
V_8 = F_21 ( V_2 ) ;
if ( V_8 )
goto V_73;
V_8 = F_28 ( V_2 ) ;
if ( V_8 )
goto V_73;
return 0 ;
V_73:
if ( V_11 -> V_58 )
F_29 ( V_2 ) ;
V_72:
F_30 ( V_2 ) ;
V_71:
F_31 ( V_2 ) ;
V_47:
return V_8 ;
}
static int F_32 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_33 ( V_11 ) ;
F_34 ( V_2 ) ;
if ( V_11 -> V_58 )
F_29 ( V_2 ) ;
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
return 0 ;
}
