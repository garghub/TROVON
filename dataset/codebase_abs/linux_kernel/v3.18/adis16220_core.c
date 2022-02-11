static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
T_1 V_12 ;
T_2 V_13 = 0 ;
F_5 ( & V_9 -> V_14 ) ;
V_12 = F_6 ( & V_11 -> V_15 , V_7 -> V_16 ,
( V_17 * ) & V_13 ) ;
F_7 ( & V_9 -> V_14 ) ;
if ( V_12 )
return V_12 ;
return sprintf ( V_5 , L_1 , V_13 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_3 V_18 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
int V_12 ;
V_17 V_13 ;
V_12 = F_9 ( V_5 , 10 , & V_13 ) ;
if ( V_12 )
goto V_19;
V_12 = F_10 ( & V_11 -> V_15 , V_7 -> V_16 , V_13 ) ;
V_19:
return V_12 ? V_12 : V_18 ;
}
static int F_11 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
int V_12 ;
V_12 = F_10 ( & V_11 -> V_15 , V_20 , 0xBF08 ) ;
if ( V_12 )
F_12 ( & V_9 -> V_2 , L_2 ) ;
F_13 ( 10000 , 11000 ) ;
return V_12 ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_18 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
bool V_13 ;
int V_12 ;
V_12 = F_15 ( V_5 , & V_13 ) ;
if ( V_12 )
return V_12 ;
if ( ! V_13 )
return - V_21 ;
V_12 = F_11 ( V_9 ) ;
if ( V_12 )
return V_12 ;
return V_18 ;
}
static T_1 F_16 ( struct V_8 * V_9 ,
char * V_5 ,
T_4 V_22 ,
T_3 V_23 ,
int V_24 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_25 V_26 [] = {
{
. V_27 = V_11 -> V_28 ,
. V_29 = 8 ,
. V_18 = 2 ,
. V_30 = 1 ,
. V_31 = 25 ,
} , {
. V_27 = V_11 -> V_28 ,
. V_32 = V_11 -> V_33 ,
. V_29 = 8 ,
. V_30 = 1 ,
. V_31 = 25 ,
} ,
} ;
int V_12 ;
int V_34 ;
if ( F_17 ( ! V_23 ) )
return V_23 ;
if ( ( V_22 >= V_35 ) || ( V_23 & 1 ) || ( V_22 & 1 ) )
return - V_21 ;
if ( V_22 + V_23 > V_35 )
V_23 = V_35 - V_22 ;
V_12 = F_10 ( & V_11 -> V_15 ,
V_36 ,
V_22 > 1 ) ;
if ( V_12 )
return - V_37 ;
F_5 ( & V_11 -> V_38 ) ;
for ( V_34 = 0 ; V_34 < V_23 ; V_34 += 2 ) {
V_11 -> V_28 [ V_34 ] = F_18 ( V_24 ) ;
V_11 -> V_28 [ V_34 + 1 ] = 0 ;
}
V_26 [ 1 ] . V_18 = V_23 ;
V_12 = F_19 ( V_11 -> V_15 . V_39 , V_26 , F_20 ( V_26 ) ) ;
if ( V_12 ) {
F_7 ( & V_11 -> V_38 ) ;
return - V_37 ;
}
memcpy ( V_5 , V_11 -> V_33 , V_23 ) ;
F_7 ( & V_11 -> V_38 ) ;
return V_23 ;
}
static T_1 F_21 ( struct V_40 * V_41 , struct V_42 * V_43 ,
struct V_44 * V_4 ,
char * V_5 ,
T_4 V_22 ,
T_3 V_23 )
{
struct V_8 * V_9 = F_3 ( F_22 ( V_43 ) ) ;
return F_16 ( V_9 , V_5 ,
V_22 , V_23 ,
V_45 ) ;
}
static T_1 F_23 ( struct V_40 * V_41 , struct V_42 * V_43 ,
struct V_44 * V_4 ,
char * V_5 , T_4 V_22 ,
T_3 V_23 )
{
struct V_8 * V_9 = F_3 ( F_22 ( V_43 ) ) ;
return F_16 ( V_9 , V_5 ,
V_22 , V_23 ,
V_46 ) ;
}
static T_1 F_24 ( struct V_40 * V_41 , struct V_42 * V_43 ,
struct V_44 * V_4 ,
char * V_5 , T_4 V_22 ,
T_3 V_23 )
{
struct V_8 * V_9 = F_3 ( F_22 ( V_43 ) ) ;
return F_16 ( V_9 , V_5 ,
V_22 , V_23 ,
V_47 ) ;
}
static int F_25 ( struct V_8 * V_9 ,
struct V_48 const * V_49 ,
int * V_13 , int * V_50 ,
long V_51 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
const struct V_52 * V_24 ;
int V_12 = - V_21 ;
int V_53 = 0 ;
V_17 V_54 ;
T_2 V_55 ;
T_5 V_56 ;
switch ( V_51 ) {
case V_57 :
V_53 = 0 ;
break;
case V_58 :
if ( V_49 -> type == V_59 ) {
* V_13 = 25000 / - 470 - 1278 ;
return V_60 ;
}
V_53 = 1 ;
break;
case V_61 :
V_53 = 2 ;
break;
case V_62 :
switch ( V_49 -> type ) {
case V_59 :
* V_13 = - 470 ;
* V_50 = 0 ;
return V_63 ;
case V_64 :
* V_50 = F_26 ( 19073 ) ;
return V_63 ;
case V_65 :
if ( V_49 -> V_66 == 0 ) {
* V_13 = 1 ;
* V_50 = 220700 ;
} else {
* V_50 = 305180 ;
}
return V_63 ;
default:
return - V_21 ;
}
default:
return - V_21 ;
}
V_24 = & V_67 [ V_49 -> V_16 ] [ V_53 ] ;
if ( V_24 -> V_68 ) {
V_12 = F_6 ( & V_11 -> V_15 , V_24 -> V_24 , & V_55 ) ;
if ( V_12 )
return V_12 ;
V_56 = V_24 -> V_56 ;
V_55 &= ( 1 << V_56 ) - 1 ;
V_55 = ( T_2 ) ( V_55 << ( 16 - V_56 ) ) >> ( 16 - V_56 ) ;
* V_13 = V_55 ;
return V_60 ;
}
V_12 = F_6 ( & V_11 -> V_15 , V_24 -> V_24 , & V_54 ) ;
if ( V_12 )
return V_12 ;
V_56 = V_24 -> V_56 ;
V_54 &= ( 1 << V_56 ) - 1 ;
* V_13 = V_54 ;
return V_60 ;
}
static int F_27 ( struct V_69 * V_39 )
{
int V_12 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
V_9 = F_28 ( & V_39 -> V_2 , sizeof( * V_11 ) ) ;
if ( ! V_9 )
return - V_70 ;
V_11 = F_4 ( V_9 ) ;
F_29 ( V_39 , V_9 ) ;
V_9 -> V_71 = V_39 -> V_2 . V_72 -> V_71 ;
V_9 -> V_2 . V_73 = & V_39 -> V_2 ;
V_9 -> V_74 = & V_75 ;
V_9 -> V_76 = V_77 ;
V_9 -> V_78 = V_79 ;
V_9 -> V_80 = F_20 ( V_79 ) ;
V_12 = F_30 ( & V_39 -> V_2 , V_9 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_31 ( & V_9 -> V_2 . V_43 , & V_81 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_31 ( & V_9 -> V_2 . V_43 , & V_82 ) ;
if ( V_12 )
goto V_83;
V_12 = F_31 ( & V_9 -> V_2 . V_43 , & V_84 ) ;
if ( V_12 )
goto V_85;
V_12 = F_32 ( & V_11 -> V_15 , V_9 , V_39 , & V_86 ) ;
if ( V_12 )
goto V_87;
V_12 = F_33 ( & V_11 -> V_15 ) ;
if ( V_12 )
goto V_87;
return 0 ;
V_87:
F_34 ( & V_9 -> V_2 . V_43 , & V_84 ) ;
V_85:
F_34 ( & V_9 -> V_2 . V_43 , & V_82 ) ;
V_83:
F_34 ( & V_9 -> V_2 . V_43 , & V_81 ) ;
return V_12 ;
}
static int F_35 ( struct V_69 * V_39 )
{
struct V_8 * V_9 = F_36 ( V_39 ) ;
F_34 ( & V_9 -> V_2 . V_43 , & V_84 ) ;
F_34 ( & V_9 -> V_2 . V_43 , & V_82 ) ;
F_34 ( & V_9 -> V_2 . V_43 , & V_81 ) ;
return 0 ;
}
