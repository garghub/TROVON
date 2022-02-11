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
F_13 ( 10 ) ;
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
struct V_25 V_26 ;
struct V_27 V_28 [] = {
{
. V_29 = V_11 -> V_30 ,
. V_31 = 8 ,
. V_18 = 2 ,
. V_32 = 1 ,
. V_33 = 25 ,
} , {
. V_29 = V_11 -> V_30 ,
. V_34 = V_11 -> V_35 ,
. V_31 = 8 ,
. V_32 = 1 ,
. V_33 = 25 ,
} ,
} ;
int V_12 ;
int V_36 ;
if ( F_17 ( ! V_23 ) )
return V_23 ;
if ( ( V_22 >= V_37 ) || ( V_23 & 1 ) || ( V_22 & 1 ) )
return - V_21 ;
if ( V_22 + V_23 > V_37 )
V_23 = V_37 - V_22 ;
V_12 = F_10 ( & V_11 -> V_15 ,
V_38 ,
V_22 > 1 ) ;
if ( V_12 )
return - V_39 ;
F_5 ( & V_11 -> V_40 ) ;
for ( V_36 = 0 ; V_36 < V_23 ; V_36 += 2 ) {
V_11 -> V_30 [ V_36 ] = F_18 ( V_24 ) ;
V_11 -> V_30 [ V_36 + 1 ] = 0 ;
}
V_28 [ 1 ] . V_18 = V_23 ;
F_19 ( & V_26 ) ;
F_20 ( & V_28 [ 0 ] , & V_26 ) ;
F_20 ( & V_28 [ 1 ] , & V_26 ) ;
V_12 = F_21 ( V_11 -> V_15 . V_41 , & V_26 ) ;
if ( V_12 ) {
F_7 ( & V_11 -> V_40 ) ;
return - V_39 ;
}
memcpy ( V_5 , V_11 -> V_35 , V_23 ) ;
F_7 ( & V_11 -> V_40 ) ;
return V_23 ;
}
static T_1 F_22 ( struct V_42 * V_43 , struct V_44 * V_45 ,
struct V_46 * V_4 ,
char * V_5 ,
T_4 V_22 ,
T_3 V_23 )
{
struct V_8 * V_9 = F_3 ( F_23 ( V_45 ) ) ;
return F_16 ( V_9 , V_5 ,
V_22 , V_23 ,
V_47 ) ;
}
static T_1 F_24 ( struct V_42 * V_43 , struct V_44 * V_45 ,
struct V_46 * V_4 ,
char * V_5 , T_4 V_22 ,
T_3 V_23 )
{
struct V_8 * V_9 = F_3 ( F_23 ( V_45 ) ) ;
return F_16 ( V_9 , V_5 ,
V_22 , V_23 ,
V_48 ) ;
}
static T_1 F_25 ( struct V_42 * V_43 , struct V_44 * V_45 ,
struct V_46 * V_4 ,
char * V_5 , T_4 V_22 ,
T_3 V_23 )
{
struct V_8 * V_9 = F_3 ( F_23 ( V_45 ) ) ;
return F_16 ( V_9 , V_5 ,
V_22 , V_23 ,
V_49 ) ;
}
static int F_26 ( struct V_8 * V_9 ,
struct V_50 const * V_51 ,
int * V_13 , int * V_52 ,
long V_53 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
const struct V_54 * V_24 ;
int V_12 = - V_21 ;
int V_55 = 0 ;
V_17 V_56 ;
T_2 V_57 ;
T_5 V_58 ;
switch ( V_53 ) {
case V_59 :
V_55 = 0 ;
break;
case V_60 :
if ( V_51 -> type == V_61 ) {
* V_13 = 25000 / - 470 - 1278 ;
return V_62 ;
}
V_55 = 1 ;
break;
case V_63 :
V_55 = 2 ;
break;
case V_64 :
switch ( V_51 -> type ) {
case V_61 :
* V_13 = - 470 ;
* V_52 = 0 ;
return V_65 ;
case V_66 :
* V_52 = F_27 ( 19073 ) ;
return V_65 ;
case V_67 :
if ( V_51 -> V_68 == 0 ) {
* V_13 = 1 ;
* V_52 = 220700 ;
} else {
* V_52 = 305180 ;
}
return V_65 ;
default:
return - V_21 ;
}
default:
return - V_21 ;
}
V_24 = & V_69 [ V_51 -> V_16 ] [ V_55 ] ;
if ( V_24 -> V_70 ) {
V_12 = F_6 ( & V_11 -> V_15 , V_24 -> V_24 , & V_57 ) ;
if ( V_12 )
return V_12 ;
V_58 = V_24 -> V_58 ;
V_57 &= ( 1 << V_58 ) - 1 ;
V_57 = ( T_2 ) ( V_57 << ( 16 - V_58 ) ) >> ( 16 - V_58 ) ;
* V_13 = V_57 ;
return V_62 ;
} else {
V_12 = F_6 ( & V_11 -> V_15 , V_24 -> V_24 , & V_56 ) ;
if ( V_12 )
return V_12 ;
V_58 = V_24 -> V_58 ;
V_56 &= ( 1 << V_58 ) - 1 ;
* V_13 = V_56 ;
return V_62 ;
}
}
static int F_28 ( struct V_71 * V_41 )
{
int V_12 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
V_9 = F_29 ( sizeof( * V_11 ) ) ;
if ( V_9 == NULL ) {
V_12 = - V_72 ;
goto V_19;
}
V_11 = F_4 ( V_9 ) ;
F_30 ( V_41 , V_9 ) ;
V_9 -> V_73 = V_41 -> V_2 . V_74 -> V_73 ;
V_9 -> V_2 . V_75 = & V_41 -> V_2 ;
V_9 -> V_76 = & V_77 ;
V_9 -> V_78 = V_79 ;
V_9 -> V_80 = V_81 ;
V_9 -> V_82 = F_31 ( V_81 ) ;
V_12 = F_32 ( V_9 ) ;
if ( V_12 )
goto V_83;
V_12 = F_33 ( & V_9 -> V_2 . V_45 , & V_84 ) ;
if ( V_12 )
goto V_85;
V_12 = F_33 ( & V_9 -> V_2 . V_45 , & V_86 ) ;
if ( V_12 )
goto V_87;
V_12 = F_33 ( & V_9 -> V_2 . V_45 , & V_88 ) ;
if ( V_12 )
goto V_89;
V_12 = F_34 ( & V_11 -> V_15 , V_9 , V_41 , & V_90 ) ;
if ( V_12 )
goto V_91;
V_12 = F_35 ( & V_11 -> V_15 ) ;
if ( V_12 )
goto V_91;
return 0 ;
V_91:
F_36 ( & V_9 -> V_2 . V_45 , & V_88 ) ;
V_89:
F_36 ( & V_9 -> V_2 . V_45 , & V_86 ) ;
V_87:
F_36 ( & V_9 -> V_2 . V_45 , & V_84 ) ;
V_85:
F_37 ( V_9 ) ;
V_83:
F_38 ( V_9 ) ;
V_19:
return V_12 ;
}
static int F_39 ( struct V_71 * V_41 )
{
struct V_8 * V_9 = F_40 ( V_41 ) ;
F_36 ( & V_9 -> V_2 . V_45 , & V_88 ) ;
F_36 ( & V_9 -> V_2 . V_45 , & V_86 ) ;
F_36 ( & V_9 -> V_2 . V_45 , & V_84 ) ;
F_37 ( V_9 ) ;
F_38 ( V_9 ) ;
return 0 ;
}
