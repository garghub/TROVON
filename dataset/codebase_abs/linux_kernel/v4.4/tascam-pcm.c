static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 4 * V_2 -> V_4 ;
V_2 -> V_5 = V_2 -> V_3 * 2048 ;
V_2 -> V_6 = V_2 -> V_5 * 2 ;
V_2 -> V_7 = 2 ;
V_2 -> V_8 = V_9 ;
}
static int F_2 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
static const struct V_1 V_14 = {
. V_15 = V_16 |
V_17 |
V_18 |
V_19 |
V_20 |
V_21 ,
. V_22 = V_23 |
V_24 |
V_25 |
V_26 ,
. V_27 = 44100 ,
. V_28 = 96000 ,
. V_4 = 10 ,
. V_29 = 18 ,
} ;
struct V_30 * V_31 = V_13 -> V_31 ;
struct V_32 * V_33 ;
unsigned int V_34 ;
V_31 -> V_2 = V_14 ;
if ( V_13 -> V_33 == V_35 ) {
V_31 -> V_2 . V_36 = V_37 ;
V_33 = & V_11 -> V_38 ;
V_34 = V_11 -> V_39 -> V_40 ;
} else {
V_31 -> V_2 . V_36 =
V_41 | V_37 ;
V_33 = & V_11 -> V_42 ;
V_34 = V_11 -> V_39 -> V_43 ;
}
if ( V_11 -> V_39 -> V_44 )
V_34 += 8 ;
if ( V_11 -> V_39 -> V_45 )
V_34 += 2 ;
V_31 -> V_2 . V_4 = V_31 -> V_2 . V_29 = V_34 ;
F_1 ( & V_31 -> V_2 ) ;
return F_3 ( V_33 , V_31 ) ;
}
static int F_4 ( struct V_12 * V_13 )
{
struct V_10 * V_11 = V_13 -> V_46 ;
enum V_47 clock ;
unsigned int V_48 ;
int V_49 ;
V_49 = F_5 ( V_11 ) ;
if ( V_49 < 0 )
goto V_50;
V_49 = F_2 ( V_11 , V_13 ) ;
if ( V_49 < 0 )
goto V_51;
V_49 = F_6 ( V_11 , & clock ) ;
if ( clock != V_52 ||
F_7 ( & V_11 -> V_42 ) ||
F_7 ( & V_11 -> V_38 ) ) {
V_49 = F_8 ( V_11 , & V_48 ) ;
if ( V_49 < 0 )
goto V_51;
V_13 -> V_31 -> V_2 . V_27 = V_48 ;
V_13 -> V_31 -> V_2 . V_28 = V_48 ;
}
F_9 ( V_13 ) ;
V_50:
return V_49 ;
V_51:
F_10 ( V_11 ) ;
return V_49 ;
}
static int F_11 ( struct V_12 * V_13 )
{
struct V_10 * V_11 = V_13 -> V_46 ;
F_10 ( V_11 ) ;
return 0 ;
}
static int F_12 ( struct V_12 * V_13 ,
struct V_53 * V_54 )
{
struct V_10 * V_11 = V_13 -> V_46 ;
int V_49 ;
V_49 = F_13 ( V_13 ,
F_14 ( V_54 ) ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_13 -> V_31 -> V_55 -> V_56 == V_57 ) {
F_15 ( & V_11 -> V_58 ) ;
V_11 -> V_59 ++ ;
F_16 ( & V_11 -> V_58 ) ;
}
F_17 ( & V_11 -> V_38 , F_18 ( V_54 ) ) ;
return 0 ;
}
static int F_19 ( struct V_12 * V_13 ,
struct V_53 * V_54 )
{
struct V_10 * V_11 = V_13 -> V_46 ;
int V_49 ;
V_49 = F_13 ( V_13 ,
F_14 ( V_54 ) ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_13 -> V_31 -> V_55 -> V_56 == V_57 ) {
F_15 ( & V_11 -> V_58 ) ;
V_11 -> V_59 ++ ;
F_16 ( & V_11 -> V_58 ) ;
}
F_17 ( & V_11 -> V_42 , F_18 ( V_54 ) ) ;
return 0 ;
}
static int F_20 ( struct V_12 * V_13 )
{
struct V_10 * V_11 = V_13 -> V_46 ;
F_15 ( & V_11 -> V_58 ) ;
if ( V_13 -> V_31 -> V_55 -> V_56 != V_57 )
V_11 -> V_59 -- ;
F_21 ( V_11 ) ;
F_16 ( & V_11 -> V_58 ) ;
return F_22 ( V_13 ) ;
}
static int F_23 ( struct V_12 * V_13 )
{
struct V_10 * V_11 = V_13 -> V_46 ;
F_15 ( & V_11 -> V_58 ) ;
if ( V_13 -> V_31 -> V_55 -> V_56 != V_57 )
V_11 -> V_59 -- ;
F_21 ( V_11 ) ;
F_16 ( & V_11 -> V_58 ) ;
return F_22 ( V_13 ) ;
}
static int F_24 ( struct V_12 * V_13 )
{
struct V_10 * V_11 = V_13 -> V_46 ;
struct V_30 * V_31 = V_13 -> V_31 ;
int V_49 ;
F_15 ( & V_11 -> V_58 ) ;
V_49 = F_25 ( V_11 , V_31 -> V_48 ) ;
if ( V_49 >= 0 )
F_26 ( & V_11 -> V_38 ) ;
F_16 ( & V_11 -> V_58 ) ;
return V_49 ;
}
static int F_27 ( struct V_12 * V_13 )
{
struct V_10 * V_11 = V_13 -> V_46 ;
struct V_30 * V_31 = V_13 -> V_31 ;
int V_49 ;
F_15 ( & V_11 -> V_58 ) ;
V_49 = F_25 ( V_11 , V_31 -> V_48 ) ;
if ( V_49 >= 0 )
F_26 ( & V_11 -> V_42 ) ;
F_16 ( & V_11 -> V_58 ) ;
return V_49 ;
}
static int F_28 ( struct V_12 * V_13 , int V_60 )
{
struct V_10 * V_11 = V_13 -> V_46 ;
switch ( V_60 ) {
case V_61 :
F_29 ( & V_11 -> V_38 , V_13 ) ;
break;
case V_62 :
F_29 ( & V_11 -> V_38 , NULL ) ;
break;
default:
return - V_63 ;
}
return 0 ;
}
static int F_30 ( struct V_12 * V_13 , int V_60 )
{
struct V_10 * V_11 = V_13 -> V_46 ;
switch ( V_60 ) {
case V_61 :
F_29 ( & V_11 -> V_42 , V_13 ) ;
break;
case V_62 :
F_29 ( & V_11 -> V_42 , NULL ) ;
break;
default:
return - V_63 ;
}
return 0 ;
}
static T_1 F_31 ( struct V_12 * V_64 )
{
struct V_10 * V_11 = V_64 -> V_46 ;
return F_32 ( & V_11 -> V_38 ) ;
}
static T_1 F_33 ( struct V_12 * V_64 )
{
struct V_10 * V_11 = V_64 -> V_46 ;
return F_32 ( & V_11 -> V_42 ) ;
}
int F_34 ( struct V_10 * V_11 )
{
struct V_65 * V_66 ;
int V_49 ;
V_49 = F_35 ( V_11 -> V_67 , V_11 -> V_67 -> V_68 , 0 , 1 , 1 , & V_66 ) ;
if ( V_49 < 0 )
return V_49 ;
V_66 -> V_46 = V_11 ;
snprintf ( V_66 -> V_69 , sizeof( V_66 -> V_69 ) ,
L_1 , V_11 -> V_67 -> V_70 ) ;
F_36 ( V_66 , V_71 , & V_72 ) ;
F_36 ( V_66 , V_35 , & V_73 ) ;
return 0 ;
}
