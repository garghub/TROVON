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
switch ( V_6 -> V_17 . V_18 -> V_19 ) {
case V_20 :
if ( V_6 -> V_17 . V_18 -> V_21 )
F_5 ( V_6 -> V_17 . V_18 -> V_21 ) ;
V_6 -> V_17 . V_18 -> V_19 = V_22 ;
F_6 ( & V_6 -> V_17 , V_23 ) ;
break;
case V_24 :
V_6 -> V_17 . V_18 -> V_19 = V_25 ;
break;
default:
break;
}
F_7 ( & V_6 -> V_10 -> V_11 , L_4 ) ;
} else {
switch ( V_6 -> V_17 . V_18 -> V_19 ) {
case V_22 :
if ( V_6 -> V_17 . V_18 -> V_21 )
F_8 ( V_6 -> V_17 . V_18 -> V_21 ) ;
V_6 -> V_17 . V_18 -> V_19 = V_20 ;
F_6 ( & V_6 -> V_17 , V_26 ) ;
break;
case V_25 :
V_6 -> V_17 . V_18 -> V_19 = V_24 ;
break;
default:
break;
}
F_7 ( & V_6 -> V_10 -> V_11 , L_5 ) ;
}
V_14 = V_6 -> V_7 ;
V_6 -> V_7 = V_13 & V_16 ;
if ( V_14 != V_6 -> V_7 ) {
F_9 ( V_6 -> V_27 , V_28 , V_6 -> V_7 ) ;
F_10 ( & V_6 -> V_10 -> V_11 . V_29 , NULL , L_6 ) ;
}
}
static void F_11 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 -> V_10 -> V_11 . V_12 ) ;
F_9 ( V_6 -> V_27 , V_30 , true ) ;
F_12 ( V_9 , V_31 , V_32 | V_33 |
V_34 | V_35 ) ;
V_6 -> V_17 . V_18 -> V_19 = V_24 ;
F_3 ( V_6 ) ;
}
static void F_13 ( struct V_5 * V_6 )
{
V_6 -> V_17 . V_18 -> V_19 = V_24 ;
}
static void F_14 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 -> V_10 -> V_11 . V_12 ) ;
F_9 ( V_6 -> V_27 , V_30 , false ) ;
F_12 ( V_9 , V_31 , V_36 | V_32 |
V_33 | V_37 ) ;
V_6 -> V_17 . V_18 -> V_19 = V_20 ;
F_3 ( V_6 ) ;
}
static void F_15 ( struct V_5 * V_6 )
{
if ( V_6 -> V_17 . V_18 -> V_21 )
F_8 ( V_6 -> V_17 . V_18 -> V_21 ) ;
V_6 -> V_17 . V_18 -> V_19 = V_20 ;
}
static void F_16 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 -> V_10 -> V_11 . V_12 ) ;
if ( V_6 -> V_17 . V_18 -> V_21 )
F_8 ( V_6 -> V_17 . V_18 -> V_21 ) ;
F_12 ( V_9 , V_31 , 0 ) ;
V_6 -> V_17 . V_18 -> V_19 = V_38 ;
}
static int F_17 ( struct V_39 * V_11 , int V_40 )
{
struct V_5 * V_6 = F_18 ( V_11 , struct V_5 , V_17 ) ;
struct V_8 * V_9 = F_2 ( V_6 -> V_10 -> V_11 . V_12 ) ;
T_2 V_41 ;
F_19 ( & V_6 -> V_10 -> V_11 , L_1 , V_42 ) ;
V_41 = F_4 ( V_9 , V_31 ) ;
if ( V_40 )
V_41 &= ~ V_33 ;
else
V_41 |= V_33 ;
F_12 ( V_9 , V_31 , V_41 ) ;
return 0 ;
}
static int F_20 ( struct V_43 * V_18 , struct V_44 * V_45 )
{
struct V_5 * V_6 = F_18 ( V_18 -> V_39 , struct V_5 ,
V_17 ) ;
F_19 ( & V_6 -> V_10 -> V_11 , L_7 , V_42 , V_45 ) ;
F_21 ( & V_6 -> V_46 ) ;
if ( V_45 == NULL ) {
if ( V_6 -> V_47 == V_48 )
F_16 ( V_6 ) ;
V_18 -> V_45 = NULL ;
F_22 ( & V_6 -> V_46 ) ;
return 0 ;
}
if ( V_6 -> V_47 == V_48 ) {
V_18 -> V_45 = NULL ;
F_11 ( V_6 ) ;
}
V_18 -> V_45 = V_45 ;
F_22 ( & V_6 -> V_46 ) ;
return 0 ;
}
static int F_23 ( struct V_43 * V_18 ,
struct V_49 * V_21 )
{
struct V_5 * V_6 = F_18 ( V_18 -> V_39 , struct V_5 ,
V_17 ) ;
F_19 ( & V_6 -> V_10 -> V_11 , L_7 , V_42 , V_21 ) ;
F_21 ( & V_6 -> V_46 ) ;
if ( ! V_21 ) {
if ( V_6 -> V_47 == V_50 )
F_16 ( V_6 ) ;
V_6 -> V_17 . V_18 -> V_21 = NULL ;
F_22 ( & V_6 -> V_46 ) ;
return 0 ;
}
V_6 -> V_17 . V_18 -> V_21 = V_21 ;
if ( V_6 -> V_47 == V_50 )
F_14 ( V_6 ) ;
F_22 ( & V_6 -> V_46 ) ;
return 0 ;
}
static T_3 F_24 ( int V_51 , void * V_52 )
{
struct V_5 * V_6 = V_52 ;
F_21 ( & V_6 -> V_46 ) ;
F_3 ( V_6 ) ;
F_22 ( & V_6 -> V_46 ) ;
return V_53 ;
}
static T_1 F_25 ( struct V_1 * V_1 ,
struct V_2 * V_3 , char * V_4 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
switch ( V_6 -> V_47 ) {
case V_48 :
return sprintf ( V_4 , L_8 ) ;
case V_50 :
return sprintf ( V_4 , L_9 ) ;
}
return - V_54 ;
}
static T_1 F_26 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
const char * V_4 , T_4 V_55 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
int V_56 ;
F_21 ( & V_6 -> V_46 ) ;
if ( V_55 >= 4 && strncmp ( V_4 , L_10 , 4 ) == 0 ) {
if ( V_6 -> V_47 == V_50 )
F_15 ( V_6 ) ;
V_6 -> V_47 = V_48 ;
if ( V_6 -> V_17 . V_18 -> V_45 ) {
F_7 ( V_1 , L_11 ) ;
F_11 ( V_6 ) ;
} else {
F_7 ( V_1 , L_12 ) ;
F_16 ( V_6 ) ;
}
V_56 = strlen ( V_4 ) ;
} else if ( V_55 >= 10 && strncmp ( V_4 , L_13 , 10 ) == 0 ) {
if ( V_6 -> V_47 == V_48 )
F_13 ( V_6 ) ;
V_6 -> V_47 = V_50 ;
if ( V_6 -> V_17 . V_18 -> V_21 ) {
F_7 ( V_1 , L_14 ) ;
F_14 ( V_6 ) ;
} else {
F_7 ( V_1 , L_15 ) ;
F_16 ( V_6 ) ;
}
V_56 = strlen ( V_4 ) ;
} else {
V_56 = - V_54 ;
}
F_22 ( & V_6 -> V_46 ) ;
return V_56 ;
}
static int F_27 ( struct V_57 * V_58 )
{
struct V_8 * V_9 = F_2 ( V_58 -> V_11 . V_12 ) ;
struct V_5 * V_6 ;
int V_59 ;
V_6 = F_28 ( & V_58 -> V_11 , sizeof( * V_6 ) , V_60 ) ;
if ( ! V_6 )
return - V_61 ;
V_6 -> V_17 . V_18 = F_28 ( & V_58 -> V_11 , sizeof( * V_6 -> V_17 . V_18 ) ,
V_60 ) ;
if ( ! V_6 -> V_17 . V_18 )
return - V_61 ;
V_6 -> V_10 = V_58 ;
#ifdef F_29
V_6 -> V_47 = V_48 ;
#else
V_6 -> V_47 = V_50 ;
#endif
F_30 ( & V_6 -> V_46 ) ;
V_6 -> V_62 = F_31 ( & V_58 -> V_11 , L_16 ) ;
if ( ! F_32 ( V_6 -> V_62 ) )
F_33 ( V_6 -> V_62 ) ;
V_6 -> V_7 = F_4 ( V_9 , V_15 ) & V_16 ;
V_6 -> V_27 = F_34 ( & V_58 -> V_11 , V_63 ) ;
if ( F_32 ( V_6 -> V_27 ) ) {
F_35 ( & V_58 -> V_11 , L_17 ) ;
return - V_61 ;
}
V_59 = F_36 ( & V_58 -> V_11 , V_6 -> V_27 ) ;
if ( V_59 ) {
F_35 ( & V_58 -> V_11 , L_18 ,
V_59 ) ;
goto V_64;
}
F_9 ( V_6 -> V_27 , V_30 ,
V_6 -> V_47 == V_48 ) ;
F_9 ( V_6 -> V_27 , V_28 , V_6 -> V_7 ) ;
F_16 ( V_6 ) ;
V_6 -> V_17 . V_11 = & V_58 -> V_11 ;
V_6 -> V_17 . V_18 -> V_19 = V_38 ;
V_6 -> V_17 . V_65 = V_66 ;
V_6 -> V_17 . V_67 = F_17 ;
V_6 -> V_17 . V_18 -> V_39 = & V_6 -> V_17 ;
V_6 -> V_17 . V_18 -> V_68 = F_20 ;
V_6 -> V_17 . V_18 -> V_69 = F_23 ;
V_59 = F_37 ( & V_6 -> V_17 , V_70 ) ;
if ( V_59 < 0 ) {
F_35 ( & V_58 -> V_11 , L_19 ,
V_59 ) ;
goto V_64;
}
F_38 ( & V_58 -> V_11 , V_6 ) ;
V_6 -> V_51 = F_39 ( V_58 , 0 ) ;
V_59 = F_40 ( V_6 -> V_51 , NULL , F_24 ,
V_71 ,
L_20 , V_6 ) ;
if ( V_59 ) {
F_35 ( & V_58 -> V_11 , L_21 ,
V_59 ) ;
goto V_72;
}
V_59 = F_41 ( & V_58 -> V_11 . V_29 , & V_73 ) ;
if ( V_59 ) {
F_35 ( & V_58 -> V_11 , L_22 , V_59 ) ;
goto V_74;
}
return 0 ;
V_74:
F_42 ( V_6 -> V_51 , V_6 ) ;
V_72:
F_43 ( & V_6 -> V_17 ) ;
V_64:
if ( ! F_32 ( V_6 -> V_62 ) )
F_44 ( V_6 -> V_62 ) ;
return V_59 ;
}
static int F_45 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_46 ( V_58 ) ;
F_47 ( & V_58 -> V_11 . V_29 , & V_73 ) ;
F_42 ( V_6 -> V_51 , V_6 ) ;
F_43 ( & V_6 -> V_17 ) ;
if ( ! F_32 ( V_6 -> V_62 ) )
F_44 ( V_6 -> V_62 ) ;
return 0 ;
}
