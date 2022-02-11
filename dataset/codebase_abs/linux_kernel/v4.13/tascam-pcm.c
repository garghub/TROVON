static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = & V_6 -> V_8 ;
struct V_9 * V_10 ;
unsigned int V_11 ;
if ( V_4 -> V_10 == V_12 ) {
V_6 -> V_8 . V_13 = V_14 ;
V_10 = & V_2 -> V_15 ;
V_11 = V_2 -> V_16 -> V_17 ;
} else {
V_6 -> V_8 . V_13 = V_14 ;
V_10 = & V_2 -> V_18 ;
V_11 = V_2 -> V_16 -> V_19 ;
}
if ( V_2 -> V_16 -> V_20 )
V_11 += 8 ;
if ( V_2 -> V_16 -> V_21 )
V_11 += 2 ;
V_6 -> V_8 . V_22 = V_6 -> V_8 . V_23 = V_11 ;
V_8 -> V_24 = V_25 |
V_26 |
V_27 |
V_28 ;
F_2 ( V_6 ) ;
return F_3 ( V_10 , V_6 ) ;
}
static int F_4 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_29 ;
enum V_30 clock ;
unsigned int V_31 ;
int V_32 ;
V_32 = F_5 ( V_2 ) ;
if ( V_32 < 0 )
goto V_33;
V_32 = F_1 ( V_2 , V_4 ) ;
if ( V_32 < 0 )
goto V_34;
V_32 = F_6 ( V_2 , & clock ) ;
if ( clock != V_35 ||
F_7 ( & V_2 -> V_18 ) ||
F_7 ( & V_2 -> V_15 ) ) {
V_32 = F_8 ( V_2 , & V_31 ) ;
if ( V_32 < 0 )
goto V_34;
V_4 -> V_6 -> V_8 . V_36 = V_31 ;
V_4 -> V_6 -> V_8 . V_37 = V_31 ;
}
F_9 ( V_4 ) ;
V_33:
return V_32 ;
V_34:
F_10 ( V_2 ) ;
return V_32 ;
}
static int F_11 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_29 ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_3 * V_4 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = V_4 -> V_29 ;
int V_32 ;
V_32 = F_13 ( V_4 ,
F_14 ( V_39 ) ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_4 -> V_6 -> V_40 -> V_41 == V_42 ) {
F_15 ( & V_2 -> V_43 ) ;
V_2 -> V_44 ++ ;
F_16 ( & V_2 -> V_43 ) ;
}
return 0 ;
}
static int F_17 ( struct V_3 * V_4 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = V_4 -> V_29 ;
int V_32 ;
V_32 = F_13 ( V_4 ,
F_14 ( V_39 ) ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_4 -> V_6 -> V_40 -> V_41 == V_42 ) {
F_15 ( & V_2 -> V_43 ) ;
V_2 -> V_44 ++ ;
F_16 ( & V_2 -> V_43 ) ;
}
return 0 ;
}
static int F_18 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_29 ;
F_15 ( & V_2 -> V_43 ) ;
if ( V_4 -> V_6 -> V_40 -> V_41 != V_42 )
V_2 -> V_44 -- ;
F_19 ( V_2 ) ;
F_16 ( & V_2 -> V_43 ) ;
return F_20 ( V_4 ) ;
}
static int F_21 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_29 ;
F_15 ( & V_2 -> V_43 ) ;
if ( V_4 -> V_6 -> V_40 -> V_41 != V_42 )
V_2 -> V_44 -- ;
F_19 ( V_2 ) ;
F_16 ( & V_2 -> V_43 ) ;
return F_20 ( V_4 ) ;
}
static int F_22 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_29 ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_32 ;
F_15 ( & V_2 -> V_43 ) ;
V_32 = F_23 ( V_2 , V_6 -> V_31 ) ;
if ( V_32 >= 0 )
F_24 ( & V_2 -> V_15 ) ;
F_16 ( & V_2 -> V_43 ) ;
return V_32 ;
}
static int F_25 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_29 ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_32 ;
F_15 ( & V_2 -> V_43 ) ;
V_32 = F_23 ( V_2 , V_6 -> V_31 ) ;
if ( V_32 >= 0 )
F_24 ( & V_2 -> V_18 ) ;
F_16 ( & V_2 -> V_43 ) ;
return V_32 ;
}
static int F_26 ( struct V_3 * V_4 , int V_45 )
{
struct V_1 * V_2 = V_4 -> V_29 ;
switch ( V_45 ) {
case V_46 :
F_27 ( & V_2 -> V_15 , V_4 ) ;
break;
case V_47 :
F_27 ( & V_2 -> V_15 , NULL ) ;
break;
default:
return - V_48 ;
}
return 0 ;
}
static int F_28 ( struct V_3 * V_4 , int V_45 )
{
struct V_1 * V_2 = V_4 -> V_29 ;
switch ( V_45 ) {
case V_46 :
F_27 ( & V_2 -> V_18 , V_4 ) ;
break;
case V_47 :
F_27 ( & V_2 -> V_18 , NULL ) ;
break;
default:
return - V_48 ;
}
return 0 ;
}
static T_1 F_29 ( struct V_3 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_29 ;
return F_30 ( & V_2 -> V_15 ) ;
}
static T_1 F_31 ( struct V_3 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_29 ;
return F_30 ( & V_2 -> V_18 ) ;
}
static int F_32 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_29 ;
return F_33 ( & V_2 -> V_15 ) ;
}
static int F_34 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_29 ;
return F_33 ( & V_2 -> V_18 ) ;
}
int F_35 ( struct V_1 * V_2 )
{
static const struct V_50 V_51 = {
. V_52 = F_4 ,
. V_53 = F_11 ,
. V_54 = V_55 ,
. V_39 = F_12 ,
. V_56 = F_18 ,
. V_57 = F_22 ,
. V_58 = F_26 ,
. V_59 = F_29 ,
. V_60 = F_32 ,
. V_61 = V_62 ,
} ;
static const struct V_50 V_63 = {
. V_52 = F_4 ,
. V_53 = F_11 ,
. V_54 = V_55 ,
. V_39 = F_17 ,
. V_56 = F_21 ,
. V_57 = F_25 ,
. V_58 = F_28 ,
. V_59 = F_31 ,
. V_60 = F_34 ,
. V_61 = V_62 ,
. V_64 = V_65 ,
} ;
struct V_66 * V_67 ;
int V_32 ;
V_32 = F_36 ( V_2 -> V_68 , V_2 -> V_68 -> V_69 , 0 , 1 , 1 , & V_67 ) ;
if ( V_32 < 0 )
return V_32 ;
V_67 -> V_29 = V_2 ;
snprintf ( V_67 -> V_70 , sizeof( V_67 -> V_70 ) ,
L_1 , V_2 -> V_68 -> V_71 ) ;
F_37 ( V_67 , V_72 , & V_63 ) ;
F_37 ( V_67 , V_12 , & V_51 ) ;
return 0 ;
}
