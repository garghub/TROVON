static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
T_1 V_12 ;
T_2 V_13 ;
F_5 ( & V_9 -> V_14 ) ;
V_12 = F_6 ( & V_11 -> V_15 , V_7 -> V_16 , & V_13 ) ;
F_7 ( & V_9 -> V_14 ) ;
if ( V_12 )
return V_12 ;
return sprintf ( V_5 , L_1 , V_13 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_3 V_17 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
int V_12 ;
T_2 V_13 ;
V_12 = F_9 ( V_5 , 10 , & V_13 ) ;
if ( V_12 )
goto V_18;
V_12 = F_10 ( & V_11 -> V_15 , V_7 -> V_16 , V_13 ) ;
V_18:
return V_12 ? V_12 : V_17 ;
}
static int F_11 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
int V_12 ;
V_12 = F_10 ( & V_11 -> V_15 , V_19 , 0xBF08 ) ;
if ( V_12 )
F_12 ( & V_9 -> V_2 , L_2 ) ;
F_13 ( 10000 , 11000 ) ;
return V_12 ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_17 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
bool V_13 ;
int V_12 ;
V_12 = F_15 ( V_5 , & V_13 ) ;
if ( V_12 )
return V_12 ;
if ( ! V_13 )
return - V_20 ;
V_12 = F_11 ( V_9 ) ;
if ( V_12 )
return V_12 ;
return V_17 ;
}
static T_1 F_16 ( struct V_8 * V_9 ,
char * V_5 ,
T_4 V_21 ,
T_3 V_22 ,
int V_23 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_24 V_25 [] = {
{
. V_26 = V_11 -> V_27 ,
. V_28 = 8 ,
. V_17 = 2 ,
. V_29 = 1 ,
. V_30 = 25 ,
} , {
. V_26 = V_11 -> V_27 ,
. V_31 = V_11 -> V_32 ,
. V_28 = 8 ,
. V_29 = 1 ,
. V_30 = 25 ,
} ,
} ;
int V_12 ;
int V_33 ;
if ( F_17 ( ! V_22 ) )
return V_22 ;
if ( ( V_21 >= V_34 ) || ( V_22 & 1 ) || ( V_21 & 1 ) )
return - V_20 ;
if ( V_21 + V_22 > V_34 )
V_22 = V_34 - V_21 ;
V_12 = F_10 ( & V_11 -> V_15 ,
V_35 ,
V_21 > 1 ) ;
if ( V_12 )
return - V_36 ;
F_5 ( & V_11 -> V_37 ) ;
for ( V_33 = 0 ; V_33 < V_22 ; V_33 += 2 ) {
V_11 -> V_27 [ V_33 ] = F_18 ( V_23 ) ;
V_11 -> V_27 [ V_33 + 1 ] = 0 ;
}
V_25 [ 1 ] . V_17 = V_22 ;
V_12 = F_19 ( V_11 -> V_15 . V_38 , V_25 , F_20 ( V_25 ) ) ;
if ( V_12 ) {
F_7 ( & V_11 -> V_37 ) ;
return - V_36 ;
}
memcpy ( V_5 , V_11 -> V_32 , V_22 ) ;
F_7 ( & V_11 -> V_37 ) ;
return V_22 ;
}
static T_1 F_21 ( struct V_39 * V_40 , struct V_41 * V_42 ,
struct V_43 * V_4 ,
char * V_5 ,
T_4 V_21 ,
T_3 V_22 )
{
struct V_8 * V_9 = F_3 ( F_22 ( V_42 ) ) ;
return F_16 ( V_9 , V_5 ,
V_21 , V_22 ,
V_44 ) ;
}
static T_1 F_23 ( struct V_39 * V_40 , struct V_41 * V_42 ,
struct V_43 * V_4 ,
char * V_5 , T_4 V_21 ,
T_3 V_22 )
{
struct V_8 * V_9 = F_3 ( F_22 ( V_42 ) ) ;
return F_16 ( V_9 , V_5 ,
V_21 , V_22 ,
V_45 ) ;
}
static T_1 F_24 ( struct V_39 * V_40 , struct V_41 * V_42 ,
struct V_43 * V_4 ,
char * V_5 , T_4 V_21 ,
T_3 V_22 )
{
struct V_8 * V_9 = F_3 ( F_22 ( V_42 ) ) ;
return F_16 ( V_9 , V_5 ,
V_21 , V_22 ,
V_46 ) ;
}
static int F_25 ( struct V_8 * V_9 ,
struct V_47 const * V_48 ,
int * V_13 , int * V_49 ,
long V_50 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
const struct V_51 * V_23 ;
int V_12 = - V_20 ;
int V_52 = 0 ;
T_2 V_53 ;
T_5 V_54 ;
T_6 V_55 ;
switch ( V_50 ) {
case V_56 :
V_52 = 0 ;
break;
case V_57 :
if ( V_48 -> type == V_58 ) {
* V_13 = 25000 / - 470 - 1278 ;
return V_59 ;
}
V_52 = 1 ;
break;
case V_60 :
V_52 = 2 ;
break;
case V_61 :
switch ( V_48 -> type ) {
case V_58 :
* V_13 = - 470 ;
* V_49 = 0 ;
return V_62 ;
case V_63 :
* V_49 = F_26 ( 19073 ) ;
return V_62 ;
case V_64 :
if ( V_48 -> V_65 == 0 ) {
* V_13 = 1 ;
* V_49 = 220700 ;
} else {
* V_49 = 305180 ;
}
return V_62 ;
default:
return - V_20 ;
}
default:
return - V_20 ;
}
V_23 = & V_66 [ V_48 -> V_16 ] [ V_52 ] ;
if ( V_23 -> V_67 ) {
V_12 = F_6 ( & V_11 -> V_15 , V_23 -> V_23 , & V_54 ) ;
if ( V_12 )
return V_12 ;
V_55 = V_23 -> V_55 ;
V_54 &= ( 1 << V_55 ) - 1 ;
V_54 = ( T_5 ) ( V_54 << ( 16 - V_55 ) ) >> ( 16 - V_55 ) ;
* V_13 = V_54 ;
return V_59 ;
}
V_12 = F_6 ( & V_11 -> V_15 , V_23 -> V_23 , & V_53 ) ;
if ( V_12 )
return V_12 ;
V_55 = V_23 -> V_55 ;
V_53 &= ( 1 << V_55 ) - 1 ;
* V_13 = V_53 ;
return V_59 ;
}
static int F_27 ( struct V_68 * V_38 )
{
int V_12 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
V_9 = F_28 ( & V_38 -> V_2 , sizeof( * V_11 ) ) ;
if ( ! V_9 )
return - V_69 ;
V_11 = F_4 ( V_9 ) ;
F_29 ( V_38 , V_9 ) ;
V_9 -> V_70 = V_38 -> V_2 . V_71 -> V_70 ;
V_9 -> V_2 . V_72 = & V_38 -> V_2 ;
V_9 -> V_73 = & V_74 ;
V_9 -> V_75 = V_76 ;
V_9 -> V_77 = V_78 ;
V_9 -> V_79 = F_20 ( V_78 ) ;
V_12 = F_30 ( & V_38 -> V_2 , V_9 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_31 ( & V_9 -> V_2 . V_42 , & V_80 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_31 ( & V_9 -> V_2 . V_42 , & V_81 ) ;
if ( V_12 )
goto V_82;
V_12 = F_31 ( & V_9 -> V_2 . V_42 , & V_83 ) ;
if ( V_12 )
goto V_84;
V_12 = F_32 ( & V_11 -> V_15 , V_9 , V_38 , & V_85 ) ;
if ( V_12 )
goto V_86;
V_12 = F_33 ( & V_11 -> V_15 ) ;
if ( V_12 )
goto V_86;
return 0 ;
V_86:
F_34 ( & V_9 -> V_2 . V_42 , & V_83 ) ;
V_84:
F_34 ( & V_9 -> V_2 . V_42 , & V_81 ) ;
V_82:
F_34 ( & V_9 -> V_2 . V_42 , & V_80 ) ;
return V_12 ;
}
static int F_35 ( struct V_68 * V_38 )
{
struct V_8 * V_9 = F_36 ( V_38 ) ;
F_34 ( & V_9 -> V_2 . V_42 , & V_83 ) ;
F_34 ( & V_9 -> V_2 . V_42 , & V_81 ) ;
F_34 ( & V_9 -> V_2 . V_42 , & V_80 ) ;
return 0 ;
}
