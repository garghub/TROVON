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
F_9 ( & V_6 -> V_27 , L_6 , V_6 -> V_7 ) ;
F_10 ( & V_6 -> V_10 -> V_11 . V_28 , NULL , L_7 ) ;
}
}
static void F_11 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 -> V_10 -> V_11 . V_12 ) ;
F_9 ( & V_6 -> V_27 , L_8 , true ) ;
F_12 ( V_9 , V_29 , V_30 | V_31 |
V_32 | V_33 ) ;
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
F_9 ( & V_6 -> V_27 , L_8 , false ) ;
F_12 ( V_9 , V_29 , V_34 | V_30 |
V_31 | V_35 ) ;
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
F_12 ( V_9 , V_29 , 0 ) ;
V_6 -> V_17 . V_18 -> V_19 = V_36 ;
}
static int F_17 ( struct V_37 * V_11 , int V_38 )
{
struct V_5 * V_6 = F_18 ( V_11 , struct V_5 , V_17 ) ;
struct V_8 * V_9 = F_2 ( V_6 -> V_10 -> V_11 . V_12 ) ;
T_2 V_39 ;
F_19 ( & V_6 -> V_10 -> V_11 , L_1 , V_40 ) ;
V_39 = F_4 ( V_9 , V_29 ) ;
if ( V_38 )
V_39 &= ~ V_31 ;
else
V_39 |= V_31 ;
F_12 ( V_9 , V_29 , V_39 ) ;
return 0 ;
}
static int F_20 ( struct V_41 * V_18 , struct V_42 * V_43 )
{
struct V_5 * V_6 = F_18 ( V_18 -> V_37 , struct V_5 ,
V_17 ) ;
F_19 ( & V_6 -> V_10 -> V_11 , L_9 , V_40 , V_43 ) ;
F_21 ( & V_6 -> V_44 ) ;
if ( V_43 == NULL ) {
if ( V_6 -> V_45 == V_46 )
F_16 ( V_6 ) ;
V_18 -> V_43 = NULL ;
F_22 ( & V_6 -> V_44 ) ;
return 0 ;
}
if ( V_6 -> V_45 == V_46 ) {
V_18 -> V_43 = NULL ;
F_11 ( V_6 ) ;
}
V_18 -> V_43 = V_43 ;
F_22 ( & V_6 -> V_44 ) ;
return 0 ;
}
static int F_23 ( struct V_41 * V_18 ,
struct V_47 * V_21 )
{
struct V_5 * V_6 = F_18 ( V_18 -> V_37 , struct V_5 ,
V_17 ) ;
F_19 ( & V_6 -> V_10 -> V_11 , L_9 , V_40 , V_21 ) ;
F_21 ( & V_6 -> V_44 ) ;
if ( ! V_21 ) {
if ( V_6 -> V_45 == V_48 )
F_16 ( V_6 ) ;
V_6 -> V_17 . V_18 -> V_21 = NULL ;
F_22 ( & V_6 -> V_44 ) ;
return 0 ;
}
V_6 -> V_17 . V_18 -> V_21 = V_21 ;
if ( V_6 -> V_45 == V_48 )
F_14 ( V_6 ) ;
F_22 ( & V_6 -> V_44 ) ;
return 0 ;
}
static T_3 F_24 ( int V_49 , void * V_50 )
{
struct V_5 * V_6 = V_50 ;
F_21 ( & V_6 -> V_44 ) ;
F_3 ( V_6 ) ;
F_22 ( & V_6 -> V_44 ) ;
return V_51 ;
}
static T_1 F_25 ( struct V_1 * V_1 ,
struct V_2 * V_3 , char * V_4 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
switch ( V_6 -> V_45 ) {
case V_46 :
return sprintf ( V_4 , L_10 ) ;
case V_48 :
return sprintf ( V_4 , L_11 ) ;
}
return - V_52 ;
}
static T_1 F_26 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
const char * V_4 , T_4 V_53 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
int V_54 ;
F_21 ( & V_6 -> V_44 ) ;
if ( V_53 >= 4 && strncmp ( V_4 , L_12 , 4 ) == 0 ) {
if ( V_6 -> V_45 == V_48 )
F_15 ( V_6 ) ;
V_6 -> V_45 = V_46 ;
if ( V_6 -> V_17 . V_18 -> V_43 ) {
F_7 ( V_1 , L_13 ) ;
F_11 ( V_6 ) ;
} else {
F_7 ( V_1 , L_14 ) ;
F_16 ( V_6 ) ;
}
V_54 = strlen ( V_4 ) ;
} else if ( V_53 >= 10 && strncmp ( V_4 , L_15 , 10 ) == 0 ) {
if ( V_6 -> V_45 == V_46 )
F_13 ( V_6 ) ;
V_6 -> V_45 = V_48 ;
if ( V_6 -> V_17 . V_18 -> V_21 ) {
F_7 ( V_1 , L_16 ) ;
F_14 ( V_6 ) ;
} else {
F_7 ( V_1 , L_17 ) ;
F_16 ( V_6 ) ;
}
V_54 = strlen ( V_4 ) ;
} else {
V_54 = - V_52 ;
}
F_22 ( & V_6 -> V_44 ) ;
return V_54 ;
}
static int F_27 ( struct V_55 * V_56 )
{
struct V_8 * V_9 = F_2 ( V_56 -> V_11 . V_12 ) ;
struct V_5 * V_6 ;
int V_57 ;
V_6 = F_28 ( & V_56 -> V_11 , sizeof( * V_6 ) , V_58 ) ;
if ( ! V_6 )
return - V_59 ;
V_6 -> V_17 . V_18 = F_28 ( & V_56 -> V_11 , sizeof( * V_6 -> V_17 . V_18 ) ,
V_58 ) ;
if ( ! V_6 -> V_17 . V_18 )
return - V_59 ;
V_6 -> V_10 = V_56 ;
#ifdef F_29
V_6 -> V_45 = V_46 ;
#else
V_6 -> V_45 = V_48 ;
#endif
F_30 ( & V_6 -> V_44 ) ;
V_6 -> V_60 = F_31 ( & V_56 -> V_11 , L_18 ) ;
if ( ! F_32 ( V_6 -> V_60 ) )
F_33 ( V_6 -> V_60 ) ;
V_6 -> V_7 = F_4 ( V_9 , V_15 ) & V_16 ;
V_6 -> V_27 . V_61 = V_62 ;
V_6 -> V_27 . V_63 = V_64 ;
V_6 -> V_27 . V_11 . V_12 = & V_56 -> V_11 ;
V_57 = F_34 ( & V_6 -> V_27 ) ;
if ( V_57 ) {
F_35 ( & V_56 -> V_11 , L_19 ,
V_57 ) ;
goto V_65;
}
F_9 ( & V_6 -> V_27 , L_8 ,
V_6 -> V_45 == V_46 ) ;
F_9 ( & V_6 -> V_27 , L_6 , V_6 -> V_7 ) ;
F_16 ( V_6 ) ;
V_6 -> V_17 . V_11 = & V_56 -> V_11 ;
V_6 -> V_17 . V_18 -> V_19 = V_36 ;
V_6 -> V_17 . V_66 = V_62 ;
V_6 -> V_17 . V_67 = F_17 ;
V_6 -> V_17 . V_18 -> V_37 = & V_6 -> V_17 ;
V_6 -> V_17 . V_18 -> V_68 = F_20 ;
V_6 -> V_17 . V_18 -> V_69 = F_23 ;
V_57 = F_36 ( & V_6 -> V_17 , V_70 ) ;
if ( V_57 < 0 ) {
F_35 ( & V_56 -> V_11 , L_20 ,
V_57 ) ;
goto V_71;
}
F_37 ( & V_56 -> V_11 , V_6 ) ;
V_6 -> V_49 = F_38 ( V_56 , 0 ) ;
V_57 = F_39 ( V_6 -> V_49 , NULL , F_24 , 0 ,
L_21 , V_6 ) ;
if ( V_57 ) {
F_35 ( & V_56 -> V_11 , L_22 ,
V_57 ) ;
goto V_72;
}
V_57 = F_40 ( & V_56 -> V_11 . V_28 , & V_73 ) ;
if ( V_57 ) {
F_35 ( & V_56 -> V_11 , L_23 , V_57 ) ;
goto V_74;
}
return 0 ;
V_74:
F_41 ( V_6 -> V_49 , V_6 ) ;
V_72:
F_42 ( & V_6 -> V_17 ) ;
V_71:
F_43 ( & V_6 -> V_27 ) ;
V_65:
if ( ! F_32 ( V_6 -> V_60 ) )
F_44 ( V_6 -> V_60 ) ;
return V_57 ;
}
static int F_45 ( struct V_55 * V_56 )
{
struct V_5 * V_6 = F_46 ( V_56 ) ;
F_47 ( & V_56 -> V_11 . V_28 , & V_73 ) ;
F_41 ( V_6 -> V_49 , V_6 ) ;
F_42 ( & V_6 -> V_17 ) ;
F_43 ( & V_6 -> V_27 ) ;
if ( ! F_32 ( V_6 -> V_60 ) )
F_44 ( V_6 -> V_60 ) ;
return 0 ;
}
