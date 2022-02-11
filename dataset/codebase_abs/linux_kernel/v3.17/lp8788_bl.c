static inline bool F_1 ( enum V_1 V_2 )
{
return V_2 == V_3 ;
}
static inline bool F_2 ( enum V_1 V_2 )
{
return V_2 == V_4 ||
V_2 == V_5 ;
}
static int F_3 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = & V_12 ;
int V_13 ;
T_1 V_14 ;
if ( V_9 ) {
V_11 -> V_15 = V_9 -> V_15 ;
V_11 -> V_16 = V_9 -> V_16 ;
V_11 -> V_17 = V_9 -> V_17 ;
V_11 -> V_18 = V_9 -> V_18 ;
V_11 -> V_19 = V_9 -> V_19 ;
V_11 -> V_20 = V_9 -> V_20 ;
}
V_14 = ( V_11 -> V_18 << V_21 ) | V_11 -> V_19 ;
V_13 = F_4 ( V_7 -> V_22 , V_23 , V_14 ) ;
if ( V_13 )
return V_13 ;
V_14 = ( V_11 -> V_17 << V_24 ) |
( V_11 -> V_16 << V_25 ) ;
switch ( V_11 -> V_15 ) {
case V_4 :
V_14 |= V_26 ;
break;
case V_3 :
case V_5 :
V_14 |= V_26 | V_27 |
( V_11 -> V_20 << V_28 ) ;
break;
default:
F_5 ( V_7 -> V_22 -> V_29 , L_1 , V_11 -> V_15 ) ;
return - V_30 ;
}
V_7 -> V_2 = V_11 -> V_15 ;
return F_4 ( V_7 -> V_22 , V_31 , V_14 ) ;
}
static void F_6 ( struct V_6 * V_7 , int V_32 , int V_33 )
{
unsigned int V_34 ;
unsigned int V_35 ;
struct V_36 * V_29 ;
struct V_37 * V_38 ;
if ( ! V_7 -> V_9 )
return;
V_34 = V_7 -> V_9 -> V_39 ;
V_35 = V_32 * V_34 / V_33 ;
V_29 = V_7 -> V_22 -> V_29 ;
if ( ! V_7 -> V_38 ) {
V_38 = F_7 ( V_29 , V_40 ) ;
if ( F_8 ( V_38 ) ) {
F_5 ( V_29 , L_2 ) ;
return;
}
V_7 -> V_38 = V_38 ;
}
F_9 ( V_7 -> V_38 , V_35 , V_34 ) ;
if ( V_35 )
F_10 ( V_7 -> V_38 ) ;
else
F_11 ( V_7 -> V_38 ) ;
}
static int F_12 ( struct V_41 * V_42 )
{
struct V_6 * V_7 = F_13 ( V_42 ) ;
enum V_1 V_2 = V_7 -> V_2 ;
if ( V_42 -> V_43 . V_44 & V_45 )
V_42 -> V_43 . V_46 = 0 ;
if ( F_1 ( V_2 ) ) {
int V_47 = V_42 -> V_43 . V_46 ;
int V_48 = V_42 -> V_43 . V_49 ;
F_6 ( V_7 , V_47 , V_48 ) ;
} else if ( F_2 ( V_2 ) ) {
T_1 V_47 = V_42 -> V_43 . V_46 ;
F_4 ( V_7 -> V_22 , V_50 , V_47 ) ;
}
return 0 ;
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_41 * V_42 ;
struct V_51 V_43 ;
struct V_8 * V_9 = V_7 -> V_9 ;
int V_52 ;
char * V_53 ;
V_43 . type = V_54 ;
V_43 . V_49 = V_55 ;
if ( V_9 )
V_52 = F_15 ( int , V_9 -> V_56 ,
V_43 . V_49 ) ;
else
V_52 = 0 ;
V_43 . V_46 = V_52 ;
if ( ! V_9 || ! V_9 -> V_53 )
V_53 = V_57 ;
else
V_53 = V_9 -> V_53 ;
V_42 = F_16 ( V_53 , V_7 -> V_22 -> V_29 , V_7 ,
& V_58 , & V_43 ) ;
if ( F_8 ( V_42 ) )
return F_17 ( V_42 ) ;
V_7 -> V_42 = V_42 ;
return 0 ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_41 * V_42 = V_7 -> V_42 ;
if ( V_42 )
F_19 ( V_42 ) ;
}
static T_2 F_20 ( struct V_36 * V_29 ,
struct V_59 * V_60 , char * V_61 )
{
struct V_6 * V_7 = F_21 ( V_29 ) ;
enum V_1 V_2 = V_7 -> V_2 ;
char * V_62 ;
if ( F_1 ( V_2 ) )
V_62 = L_3 ;
else if ( F_2 ( V_2 ) )
V_62 = L_4 ;
else
V_62 = L_5 ;
return F_22 ( V_61 , V_63 , L_6 , V_62 ) ;
}
static int F_23 ( struct V_64 * V_65 )
{
struct V_66 * V_22 = F_21 ( V_65 -> V_29 . V_67 ) ;
struct V_6 * V_7 ;
int V_13 ;
V_7 = F_24 ( V_22 -> V_29 , sizeof( struct V_6 ) , V_68 ) ;
if ( ! V_7 )
return - V_69 ;
V_7 -> V_22 = V_22 ;
if ( V_22 -> V_9 )
V_7 -> V_9 = V_22 -> V_9 -> V_70 ;
F_25 ( V_65 , V_7 ) ;
V_13 = F_3 ( V_7 ) ;
if ( V_13 ) {
F_5 ( V_22 -> V_29 , L_7 , V_13 ) ;
goto V_71;
}
V_13 = F_14 ( V_7 ) ;
if ( V_13 ) {
F_5 ( V_22 -> V_29 , L_8 , V_13 ) ;
goto V_71;
}
V_13 = F_26 ( & V_65 -> V_29 . V_72 , & V_73 ) ;
if ( V_13 ) {
F_5 ( V_22 -> V_29 , L_9 , V_13 ) ;
goto V_74;
}
F_27 ( V_7 -> V_42 ) ;
return 0 ;
V_74:
F_18 ( V_7 ) ;
V_71:
return V_13 ;
}
static int F_28 ( struct V_64 * V_65 )
{
struct V_6 * V_7 = F_29 ( V_65 ) ;
struct V_41 * V_42 = V_7 -> V_42 ;
V_42 -> V_43 . V_46 = 0 ;
F_27 ( V_42 ) ;
F_30 ( & V_65 -> V_29 . V_72 , & V_73 ) ;
F_18 ( V_7 ) ;
return 0 ;
}
