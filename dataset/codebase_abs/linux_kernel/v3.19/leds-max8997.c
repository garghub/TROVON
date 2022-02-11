static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
int V_5 ;
struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
T_1 V_10 = 0 , V_11 ;
switch ( V_4 ) {
case V_12 :
V_10 = V_13 | V_14 ;
V_11 = V_2 -> V_15 ?
V_13 : V_14 ;
V_2 -> V_16 . V_17 = V_18 ;
break;
case V_19 :
V_10 = V_20 | V_21 ;
V_11 = V_2 -> V_15 ?
V_20 : V_21 ;
V_2 -> V_16 . V_17 = V_22 ;
break;
case V_23 :
V_10 = V_24 |
V_25 ;
V_11 = V_2 -> V_15 ?
V_24 : V_25 ;
V_2 -> V_16 . V_17 = V_18 ;
break;
case V_26 :
V_10 = V_27 |
V_28 ;
V_11 = V_2 -> V_15 ?
V_27 : V_28 ;
V_2 -> V_16 . V_17 = V_22 ;
break;
default:
V_2 -> V_16 . V_17 = V_29 ;
break;
}
if ( V_10 ) {
V_5 = F_2 ( V_7 , V_30 , V_11 ,
V_10 ) ;
if ( V_5 )
F_3 ( V_2 -> V_8 -> V_31 ,
L_1 , V_5 ) ;
}
V_2 -> V_32 = V_4 ;
}
static void F_4 ( struct V_1 * V_2 , bool V_33 )
{
int V_5 ;
struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
T_1 V_11 = 0 , V_10 = V_34 ;
if ( V_2 -> V_35 == V_33 )
return;
V_11 = V_33 ? V_34 : 0 ;
V_5 = F_2 ( V_7 , V_36 , V_11 , V_10 ) ;
if ( V_5 )
F_3 ( V_2 -> V_8 -> V_31 ,
L_1 , V_5 ) ;
V_2 -> V_35 = V_33 ;
}
static void F_5 ( struct V_1 * V_2 ,
enum V_37 V_38 )
{
int V_5 ;
struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
T_1 V_11 = 0 , V_10 = 0 , V_39 = 0 ;
switch ( V_2 -> V_32 ) {
case V_12 :
case V_23 :
V_11 = V_38 << V_40 ;
V_10 = V_41 ;
V_39 = V_2 -> V_15 ? V_42 : V_43 ;
break;
case V_19 :
case V_26 :
V_11 = V_38 << V_44 ;
V_10 = V_45 ;
V_39 = V_46 ;
break;
default:
break;
}
if ( V_10 ) {
V_5 = F_2 ( V_7 , V_39 , V_11 , V_10 ) ;
if ( V_5 )
F_3 ( V_2 -> V_8 -> V_31 ,
L_1 , V_5 ) ;
}
}
static void F_6 ( struct V_47 * V_48 ,
enum V_37 V_38 )
{
struct V_1 * V_2 =
F_7 ( V_48 , struct V_1 , V_16 ) ;
if ( V_38 ) {
F_5 ( V_2 , V_38 ) ;
F_4 ( V_2 , true ) ;
} else {
F_5 ( V_2 , V_38 ) ;
F_4 ( V_2 , false ) ;
}
}
static T_2 F_8 ( struct V_49 * V_31 ,
struct V_50 * V_51 , char * V_52 )
{
struct V_47 * V_48 = F_9 ( V_31 ) ;
struct V_1 * V_2 =
F_7 ( V_48 , struct V_1 , V_16 ) ;
T_2 V_5 = 0 ;
F_10 ( & V_2 -> V_53 ) ;
switch ( V_2 -> V_32 ) {
case V_12 :
V_5 += sprintf ( V_52 , L_2 ) ;
break;
case V_19 :
V_5 += sprintf ( V_52 , L_3 ) ;
break;
case V_23 :
V_5 += sprintf ( V_52 , L_4 ) ;
break;
case V_26 :
V_5 += sprintf ( V_52 , L_5 ) ;
break;
default:
V_5 += sprintf ( V_52 , L_6 ) ;
break;
}
F_11 ( & V_2 -> V_53 ) ;
return V_5 ;
}
static T_2 F_12 ( struct V_49 * V_31 ,
struct V_50 * V_51 ,
const char * V_52 , T_3 V_54 )
{
struct V_47 * V_48 = F_9 ( V_31 ) ;
struct V_1 * V_2 =
F_7 ( V_48 , struct V_1 , V_16 ) ;
enum V_3 V_4 ;
F_10 ( & V_2 -> V_53 ) ;
if ( ! strncmp ( V_52 , L_7 , 17 ) )
V_4 = V_23 ;
else if ( ! strncmp ( V_52 , L_8 , 17 ) )
V_4 = V_26 ;
else if ( ! strncmp ( V_52 , L_9 , 5 ) )
V_4 = V_12 ;
else if ( ! strncmp ( V_52 , L_10 , 5 ) )
V_4 = V_19 ;
else
V_4 = V_55 ;
F_1 ( V_2 , V_4 ) ;
F_11 ( & V_2 -> V_53 ) ;
return V_54 ;
}
static int F_13 ( struct V_56 * V_57 )
{
struct V_58 * V_8 = F_9 ( V_57 -> V_31 . V_59 ) ;
struct V_60 * V_61 = F_14 ( V_8 -> V_31 ) ;
struct V_1 * V_2 ;
char V_62 [ 20 ] ;
int V_5 = 0 ;
if ( V_61 == NULL ) {
F_3 ( & V_57 -> V_31 , L_11 ) ;
return - V_63 ;
}
V_2 = F_15 ( & V_57 -> V_31 , sizeof( * V_2 ) , V_64 ) ;
if ( V_2 == NULL )
return - V_65 ;
V_2 -> V_15 = V_57 -> V_15 ;
snprintf ( V_62 , sizeof( V_62 ) , L_12 , V_57 -> V_15 ) ;
V_2 -> V_16 . V_62 = V_62 ;
V_2 -> V_16 . V_66 = F_6 ;
V_2 -> V_16 . V_67 |= V_68 ;
V_2 -> V_16 . V_69 = 0 ;
V_2 -> V_16 . V_70 = V_71 ;
V_2 -> V_8 = V_8 ;
if ( V_61 -> V_72 ) {
T_1 V_4 = 0 , V_69 = 0 ;
V_4 = V_61 -> V_72 -> V_4 [ V_2 -> V_15 ] ;
V_69 = V_61 -> V_72 -> V_69 [ V_2 -> V_15 ] ;
F_1 ( V_2 , V_61 -> V_72 -> V_4 [ V_2 -> V_15 ] ) ;
if ( V_69 > V_2 -> V_16 . V_17 )
V_69 = V_2 -> V_16 . V_17 ;
F_5 ( V_2 , V_69 ) ;
V_2 -> V_16 . V_69 = V_69 ;
} else {
F_1 ( V_2 , V_55 ) ;
F_5 ( V_2 , 0 ) ;
}
F_16 ( & V_2 -> V_53 ) ;
F_17 ( V_57 , V_2 ) ;
V_5 = F_18 ( & V_57 -> V_31 , & V_2 -> V_16 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_19 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_20 ( V_57 ) ;
F_21 ( & V_2 -> V_16 ) ;
return 0 ;
}
