static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
T_1 V_9 = 0 , V_10 = 0 ;
int V_11 ;
switch ( V_4 ) {
case V_12 :
V_10 = V_2 -> V_13 ?
V_14 : V_15 ;
break;
case V_16 :
V_10 = V_2 -> V_13 ?
V_17 : V_18 ;
break;
case V_19 :
V_10 = V_2 -> V_13 ?
V_20 : V_21 ;
break;
case V_22 :
V_10 = V_2 -> V_13 ?
V_23 : V_24 ;
break;
default:
break;
}
if ( V_10 ) {
V_11 = F_2 ( V_6 ,
V_25 , V_9 , V_10 ) ;
if ( V_11 )
F_3 ( V_2 -> V_7 -> V_26 ,
L_1 , V_11 ) ;
}
}
static void F_4 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
int V_11 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
T_1 V_10 = 0 ;
F_1 ( V_2 , V_2 -> V_27 ) ;
switch ( V_4 ) {
case V_12 :
V_10 = V_2 -> V_13 ?
V_14 : V_15 ;
V_2 -> V_28 . V_29 = V_30 ;
break;
case V_16 :
V_10 = V_2 -> V_13 ?
V_17 : V_18 ;
V_2 -> V_28 . V_29 = V_31 ;
break;
case V_19 :
V_10 = V_2 -> V_13 ?
V_20 : V_21 ;
V_2 -> V_28 . V_29 = V_30 ;
break;
case V_22 :
V_10 = V_2 -> V_13 ?
V_23 : V_24 ;
V_2 -> V_28 . V_29 = V_31 ;
break;
default:
V_2 -> V_28 . V_29 = V_32 ;
break;
}
if ( V_10 ) {
V_11 = F_2 ( V_6 ,
V_25 , V_10 , V_10 ) ;
if ( V_11 )
F_3 ( V_2 -> V_7 -> V_26 ,
L_1 , V_11 ) ;
}
V_2 -> V_27 = V_4 ;
}
static void F_5 ( struct V_1 * V_2 , bool V_33 )
{
int V_11 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
T_1 V_9 = 0 , V_10 = V_34 ;
if ( V_2 -> V_35 == V_33 )
return;
V_9 = V_33 ? V_34 : 0 ;
V_11 = F_2 ( V_6 , V_36 , V_9 , V_10 ) ;
if ( V_11 )
F_3 ( V_2 -> V_7 -> V_26 ,
L_1 , V_11 ) ;
V_2 -> V_35 = V_33 ;
}
static void F_6 ( struct V_1 * V_2 ,
enum V_37 V_38 )
{
int V_11 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
T_1 V_9 = 0 , V_10 = 0 , V_39 = 0 ;
switch ( V_2 -> V_27 ) {
case V_12 :
case V_19 :
V_9 = V_38 << V_40 ;
V_10 = V_41 ;
V_39 = V_2 -> V_13 ? V_42 : V_43 ;
break;
case V_16 :
case V_22 :
V_9 = V_38 << V_44 ;
V_10 = V_45 ;
V_39 = V_46 ;
break;
default:
break;
}
if ( V_10 ) {
V_11 = F_2 ( V_6 , V_39 , V_9 , V_10 ) ;
if ( V_11 )
F_3 ( V_2 -> V_7 -> V_26 ,
L_1 , V_11 ) ;
}
}
static void F_7 ( struct V_47 * V_48 ,
enum V_37 V_38 )
{
struct V_1 * V_2 =
F_8 ( V_48 , struct V_1 , V_28 ) ;
if ( V_38 ) {
F_6 ( V_2 , V_38 ) ;
F_5 ( V_2 , true ) ;
} else {
F_6 ( V_2 , V_38 ) ;
F_5 ( V_2 , false ) ;
}
}
static T_2 F_9 ( struct V_49 * V_26 ,
struct V_50 * V_51 , char * V_52 )
{
struct V_47 * V_48 = F_10 ( V_26 ) ;
struct V_1 * V_2 =
F_8 ( V_48 , struct V_1 , V_28 ) ;
T_2 V_11 = 0 ;
F_11 ( & V_2 -> V_53 ) ;
switch ( V_2 -> V_27 ) {
case V_12 :
V_11 += sprintf ( V_52 , L_2 ) ;
break;
case V_16 :
V_11 += sprintf ( V_52 , L_3 ) ;
break;
case V_19 :
V_11 += sprintf ( V_52 , L_4 ) ;
break;
case V_22 :
V_11 += sprintf ( V_52 , L_5 ) ;
break;
default:
V_11 += sprintf ( V_52 , L_6 ) ;
break;
}
F_12 ( & V_2 -> V_53 ) ;
return V_11 ;
}
static T_2 F_13 ( struct V_49 * V_26 ,
struct V_50 * V_51 ,
const char * V_52 , T_3 V_54 )
{
struct V_47 * V_48 = F_10 ( V_26 ) ;
struct V_1 * V_2 =
F_8 ( V_48 , struct V_1 , V_28 ) ;
enum V_3 V_4 ;
F_11 ( & V_2 -> V_53 ) ;
if ( ! strncmp ( V_52 , L_7 , 17 ) )
V_4 = V_19 ;
else if ( ! strncmp ( V_52 , L_8 , 17 ) )
V_4 = V_22 ;
else if ( ! strncmp ( V_52 , L_9 , 5 ) )
V_4 = V_12 ;
else if ( ! strncmp ( V_52 , L_10 , 5 ) )
V_4 = V_16 ;
else
V_4 = V_55 ;
F_4 ( V_2 , V_4 ) ;
F_12 ( & V_2 -> V_53 ) ;
return V_54 ;
}
static int T_4 F_14 ( struct V_56 * V_57 )
{
struct V_58 * V_7 = F_10 ( V_57 -> V_26 . V_59 ) ;
struct V_60 * V_61 = F_15 ( V_7 -> V_26 ) ;
struct V_1 * V_2 ;
char V_62 [ 20 ] ;
int V_11 = 0 ;
if ( V_61 == NULL ) {
F_3 ( & V_57 -> V_26 , L_11 ) ;
return - V_63 ;
}
V_2 = F_16 ( sizeof( * V_2 ) , V_64 ) ;
if ( V_2 == NULL ) {
V_11 = - V_65 ;
goto V_66;
}
V_2 -> V_13 = V_57 -> V_13 ;
snprintf ( V_62 , sizeof( V_62 ) , L_12 , V_57 -> V_13 ) ;
V_2 -> V_28 . V_62 = V_62 ;
V_2 -> V_28 . V_67 = F_7 ;
V_2 -> V_28 . V_68 |= V_69 ;
V_2 -> V_28 . V_70 = 0 ;
V_2 -> V_7 = V_7 ;
if ( V_61 -> V_71 ) {
T_1 V_4 = 0 , V_70 = 0 ;
V_4 = V_61 -> V_71 -> V_4 [ V_2 -> V_13 ] ;
V_70 = V_61 -> V_71 -> V_70 [ V_2 -> V_13 ] ;
F_4 ( V_2 , V_61 -> V_71 -> V_4 [ V_2 -> V_13 ] ) ;
if ( V_70 > V_2 -> V_28 . V_29 )
V_70 = V_2 -> V_28 . V_29 ;
F_6 ( V_2 , V_70 ) ;
V_2 -> V_28 . V_70 = V_70 ;
} else {
F_4 ( V_2 , V_55 ) ;
F_6 ( V_2 , 0 ) ;
}
F_17 ( & V_2 -> V_53 ) ;
F_18 ( V_57 , V_2 ) ;
V_11 = F_19 ( & V_57 -> V_26 , & V_2 -> V_28 ) ;
if ( V_11 < 0 )
goto V_72;
V_11 = F_20 ( V_2 -> V_28 . V_26 , & V_73 ) ;
if ( V_11 != 0 ) {
F_3 ( & V_57 -> V_26 ,
L_13 , V_11 ) ;
goto V_74;
}
return 0 ;
V_74:
F_21 ( & V_2 -> V_28 ) ;
V_72:
F_22 ( V_2 ) ;
V_66:
return V_11 ;
}
static int T_5 F_23 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_24 ( V_57 ) ;
F_25 ( V_2 -> V_28 . V_26 , & V_73 ) ;
F_21 ( & V_2 -> V_28 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int T_6 F_26 ( void )
{
return F_27 ( & V_75 ) ;
}
static void T_7 F_28 ( void )
{
F_29 ( & V_75 ) ;
}
