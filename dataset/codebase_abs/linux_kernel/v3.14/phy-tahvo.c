static T_1 F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 , char * V_4 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
return sprintf ( V_4 , L_1 , V_6 -> V_7 ? L_2 : L_3 ) ;
}
static void F_3 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 -> V_10 -> V_11 . V_12 ) ;
int V_13 , V_14 ;
V_13 = F_4 ( V_9 , V_15 ) ;
if ( V_13 & V_16 ) {
switch ( V_6 -> V_17 . V_18 ) {
case V_19 :
if ( V_6 -> V_17 . V_20 -> V_21 )
F_5 ( V_6 -> V_17 . V_20 -> V_21 ) ;
V_6 -> V_17 . V_18 = V_22 ;
break;
case V_23 :
V_6 -> V_17 . V_18 = V_24 ;
break;
default:
break;
}
F_6 ( & V_6 -> V_10 -> V_11 , L_4 ) ;
} else {
switch ( V_6 -> V_17 . V_18 ) {
case V_22 :
if ( V_6 -> V_17 . V_20 -> V_21 )
F_7 ( V_6 -> V_17 . V_20 -> V_21 ) ;
V_6 -> V_17 . V_18 = V_19 ;
break;
case V_24 :
V_6 -> V_17 . V_18 = V_23 ;
break;
default:
break;
}
F_6 ( & V_6 -> V_10 -> V_11 , L_5 ) ;
}
V_14 = V_6 -> V_7 ;
V_6 -> V_7 = V_13 & V_16 ;
if ( V_14 != V_6 -> V_7 ) {
F_8 ( & V_6 -> V_25 , L_6 , V_6 -> V_7 ) ;
F_9 ( & V_6 -> V_10 -> V_11 . V_26 , NULL , L_7 ) ;
}
}
static void F_10 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 -> V_10 -> V_11 . V_12 ) ;
F_8 ( & V_6 -> V_25 , L_8 , true ) ;
F_11 ( V_9 , V_27 , V_28 | V_29 |
V_30 | V_31 ) ;
V_6 -> V_17 . V_18 = V_23 ;
F_3 ( V_6 ) ;
}
static void F_12 ( struct V_5 * V_6 )
{
V_6 -> V_17 . V_18 = V_23 ;
}
static void F_13 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 -> V_10 -> V_11 . V_12 ) ;
F_8 ( & V_6 -> V_25 , L_8 , false ) ;
F_11 ( V_9 , V_27 , V_32 | V_28 |
V_29 | V_33 ) ;
V_6 -> V_17 . V_18 = V_19 ;
F_3 ( V_6 ) ;
}
static void F_14 ( struct V_5 * V_6 )
{
if ( V_6 -> V_17 . V_20 -> V_21 )
F_7 ( V_6 -> V_17 . V_20 -> V_21 ) ;
V_6 -> V_17 . V_18 = V_19 ;
}
static void F_15 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 -> V_10 -> V_11 . V_12 ) ;
if ( V_6 -> V_17 . V_20 -> V_21 )
F_7 ( V_6 -> V_17 . V_20 -> V_21 ) ;
F_11 ( V_9 , V_27 , 0 ) ;
V_6 -> V_17 . V_18 = V_34 ;
}
static int F_16 ( struct V_35 * V_11 , int V_36 )
{
struct V_5 * V_6 = F_17 ( V_11 , struct V_5 , V_17 ) ;
struct V_8 * V_9 = F_2 ( V_6 -> V_10 -> V_11 . V_12 ) ;
T_2 V_37 ;
F_18 ( & V_6 -> V_10 -> V_11 , L_1 , V_38 ) ;
V_37 = F_4 ( V_9 , V_27 ) ;
if ( V_36 )
V_37 &= ~ V_29 ;
else
V_37 |= V_29 ;
F_11 ( V_9 , V_27 , V_37 ) ;
return 0 ;
}
static int F_19 ( struct V_39 * V_20 , struct V_40 * V_41 )
{
struct V_5 * V_6 = F_17 ( V_20 -> V_17 , struct V_5 , V_17 ) ;
F_18 ( & V_6 -> V_10 -> V_11 , L_9 , V_38 , V_41 ) ;
F_20 ( & V_6 -> V_42 ) ;
if ( V_41 == NULL ) {
if ( V_6 -> V_43 == V_44 )
F_15 ( V_6 ) ;
V_20 -> V_41 = NULL ;
F_21 ( & V_6 -> V_42 ) ;
return 0 ;
}
if ( V_6 -> V_43 == V_44 ) {
V_20 -> V_41 = NULL ;
F_10 ( V_6 ) ;
}
V_20 -> V_41 = V_41 ;
F_21 ( & V_6 -> V_42 ) ;
return 0 ;
}
static int F_22 ( struct V_39 * V_20 ,
struct V_45 * V_21 )
{
struct V_5 * V_6 = F_17 ( V_20 -> V_17 , struct V_5 , V_17 ) ;
F_18 ( & V_6 -> V_10 -> V_11 , L_9 , V_38 , V_21 ) ;
F_20 ( & V_6 -> V_42 ) ;
if ( ! V_21 ) {
if ( V_6 -> V_43 == V_46 )
F_15 ( V_6 ) ;
V_6 -> V_17 . V_20 -> V_21 = NULL ;
F_21 ( & V_6 -> V_42 ) ;
return 0 ;
}
V_6 -> V_17 . V_20 -> V_21 = V_21 ;
if ( V_6 -> V_43 == V_46 )
F_13 ( V_6 ) ;
F_21 ( & V_6 -> V_42 ) ;
return 0 ;
}
static T_3 F_23 ( int V_47 , void * V_48 )
{
struct V_5 * V_6 = V_48 ;
F_20 ( & V_6 -> V_42 ) ;
F_3 ( V_6 ) ;
F_21 ( & V_6 -> V_42 ) ;
return V_49 ;
}
static T_1 F_24 ( struct V_1 * V_1 ,
struct V_2 * V_3 , char * V_4 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
switch ( V_6 -> V_43 ) {
case V_44 :
return sprintf ( V_4 , L_10 ) ;
case V_46 :
return sprintf ( V_4 , L_11 ) ;
}
return - V_50 ;
}
static T_1 F_25 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
const char * V_4 , T_4 V_51 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
int V_52 ;
F_20 ( & V_6 -> V_42 ) ;
if ( V_51 >= 4 && strncmp ( V_4 , L_12 , 4 ) == 0 ) {
if ( V_6 -> V_43 == V_46 )
F_14 ( V_6 ) ;
V_6 -> V_43 = V_44 ;
if ( V_6 -> V_17 . V_20 -> V_41 ) {
F_6 ( V_1 , L_13 ) ;
F_10 ( V_6 ) ;
} else {
F_6 ( V_1 , L_14 ) ;
F_15 ( V_6 ) ;
}
V_52 = strlen ( V_4 ) ;
} else if ( V_51 >= 10 && strncmp ( V_4 , L_15 , 10 ) == 0 ) {
if ( V_6 -> V_43 == V_44 )
F_12 ( V_6 ) ;
V_6 -> V_43 = V_46 ;
if ( V_6 -> V_17 . V_20 -> V_21 ) {
F_6 ( V_1 , L_16 ) ;
F_13 ( V_6 ) ;
} else {
F_6 ( V_1 , L_17 ) ;
F_15 ( V_6 ) ;
}
V_52 = strlen ( V_4 ) ;
} else {
V_52 = - V_50 ;
}
F_21 ( & V_6 -> V_42 ) ;
return V_52 ;
}
static int F_26 ( struct V_53 * V_54 )
{
struct V_8 * V_9 = F_2 ( V_54 -> V_11 . V_12 ) ;
struct V_5 * V_6 ;
int V_55 ;
V_6 = F_27 ( & V_54 -> V_11 , sizeof( * V_6 ) , V_56 ) ;
if ( ! V_6 )
return - V_57 ;
V_6 -> V_17 . V_20 = F_27 ( & V_54 -> V_11 , sizeof( * V_6 -> V_17 . V_20 ) ,
V_56 ) ;
if ( ! V_6 -> V_17 . V_20 )
return - V_57 ;
V_6 -> V_10 = V_54 ;
#ifdef F_28
V_6 -> V_43 = V_44 ;
#else
V_6 -> V_43 = V_46 ;
#endif
F_29 ( & V_6 -> V_42 ) ;
V_6 -> V_58 = F_30 ( & V_54 -> V_11 , L_18 ) ;
if ( ! F_31 ( V_6 -> V_58 ) )
F_32 ( V_6 -> V_58 ) ;
V_6 -> V_7 = F_4 ( V_9 , V_15 ) & V_16 ;
V_6 -> V_25 . V_59 = V_60 ;
V_6 -> V_25 . V_61 = V_62 ;
V_6 -> V_25 . V_11 . V_12 = & V_54 -> V_11 ;
V_55 = F_33 ( & V_6 -> V_25 ) ;
if ( V_55 ) {
F_34 ( & V_54 -> V_11 , L_19 ,
V_55 ) ;
goto V_63;
}
F_8 ( & V_6 -> V_25 , L_8 ,
V_6 -> V_43 == V_44 ) ;
F_8 ( & V_6 -> V_25 , L_6 , V_6 -> V_7 ) ;
F_15 ( V_6 ) ;
V_6 -> V_17 . V_11 = & V_54 -> V_11 ;
V_6 -> V_17 . V_18 = V_34 ;
V_6 -> V_17 . V_64 = V_60 ;
V_6 -> V_17 . V_65 = F_16 ;
V_6 -> V_17 . V_20 -> V_17 = & V_6 -> V_17 ;
V_6 -> V_17 . V_20 -> V_66 = F_19 ;
V_6 -> V_17 . V_20 -> V_67 = F_22 ;
V_55 = F_35 ( & V_6 -> V_17 , V_68 ) ;
if ( V_55 < 0 ) {
F_34 ( & V_54 -> V_11 , L_20 ,
V_55 ) ;
goto V_69;
}
F_36 ( & V_54 -> V_11 , V_6 ) ;
V_6 -> V_47 = F_37 ( V_54 , 0 ) ;
V_55 = F_38 ( V_6 -> V_47 , NULL , F_23 , 0 ,
L_21 , V_6 ) ;
if ( V_55 ) {
F_34 ( & V_54 -> V_11 , L_22 ,
V_55 ) ;
goto V_70;
}
V_55 = F_39 ( & V_54 -> V_11 . V_26 , & V_71 ) ;
if ( V_55 ) {
F_34 ( & V_54 -> V_11 , L_23 , V_55 ) ;
goto V_72;
}
return 0 ;
V_72:
F_40 ( V_6 -> V_47 , V_6 ) ;
V_70:
F_41 ( & V_6 -> V_17 ) ;
V_69:
F_42 ( & V_6 -> V_25 ) ;
V_63:
if ( ! F_31 ( V_6 -> V_58 ) )
F_43 ( V_6 -> V_58 ) ;
return V_55 ;
}
static int F_44 ( struct V_53 * V_54 )
{
struct V_5 * V_6 = F_45 ( V_54 ) ;
F_46 ( & V_54 -> V_11 . V_26 , & V_71 ) ;
F_40 ( V_6 -> V_47 , V_6 ) ;
F_41 ( & V_6 -> V_17 ) ;
F_42 ( & V_6 -> V_25 ) ;
if ( ! F_31 ( V_6 -> V_58 ) )
F_43 ( V_6 -> V_58 ) ;
return 0 ;
}
