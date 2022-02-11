static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
switch ( V_4 ) {
case V_9 :
V_6 -> V_10 = V_8 -> V_11 ;
break;
case V_12 :
V_6 -> V_10 = V_8 -> V_13 ;
break;
case V_14 :
V_6 -> V_10 = V_8 -> V_15 ;
break;
case V_16 :
V_6 -> V_10 = V_8 -> V_17 ;
break;
default:
return - V_18 ;
}
return 0 ;
}
static int F_3 ( struct V_19 * V_20 , int V_21 , T_1 V_22 )
{
int V_23 ;
V_23 = F_4 ( V_20 , V_21 , V_22 ) ;
if ( V_23 < 0 )
F_5 ( & V_20 -> V_24 , L_1 , V_25 , V_23 ) ;
return V_23 ;
}
static int F_6 ( struct V_19 * V_20 , int V_21 )
{
int V_23 ;
V_23 = F_7 ( V_20 , V_21 ) ;
if ( V_23 < 0 )
F_5 ( & V_20 -> V_24 , L_1 , V_25 , V_23 ) ;
return V_23 ;
}
static void F_8 ( struct V_19 * V_20 )
{
F_3 ( V_20 , V_26 , 0x0054 ) ;
}
static void F_9 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = F_10 ( V_20 ) ;
T_1 V_15 ;
V_15 = F_6 ( V_20 , V_27 ) ;
V_8 -> V_15 = V_15 ;
}
static void F_11 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = F_10 ( V_20 ) ;
T_1 V_17 ;
V_17 = F_6 ( V_20 , V_28 ) ;
V_8 -> V_17 = ( V_17 >> 8 ) ;
}
static void F_12 ( struct V_19 * V_20 )
{
T_1 V_29 ;
V_29 = F_6 ( V_20 , V_30 ) ;
F_13 ( & V_20 -> V_24 , L_2 , V_29 ) ;
}
static void F_14 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = F_10 ( V_20 ) ;
if ( V_8 -> V_31 && V_8 -> V_31 -> V_32 )
V_8 -> V_13 = V_8 -> V_31 -> V_32 () ;
else
V_8 -> V_13 = 1 ;
}
static void F_15 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = F_10 ( V_20 ) ;
if ( ! V_8 -> V_31 || ! V_8 -> V_31 -> V_33
|| ! V_8 -> V_31 -> V_34 ) {
V_8 -> V_11 = V_35 ;
return;
}
if ( V_8 -> V_31 -> V_33 () ) {
if ( V_8 -> V_31 -> V_34 () )
V_8 -> V_11 = V_36 ;
else
V_8 -> V_11 = V_37 ;
} else {
V_8 -> V_11 = V_38 ;
}
if ( V_8 -> V_17 > V_39 )
V_8 -> V_11 = V_40 ;
}
static void F_16 ( struct V_41 * V_42 )
{
struct V_7 * V_8 ;
V_8 = F_17 ( V_42 , struct V_7 , V_42 . V_42 ) ;
F_9 ( V_8 -> V_20 ) ;
F_11 ( V_8 -> V_20 ) ;
F_14 ( V_8 -> V_20 ) ;
F_15 ( V_8 -> V_20 ) ;
F_18 ( V_43 , & V_8 -> V_42 ,
V_44 ) ;
}
static int F_19 ( struct V_19 * V_20 ,
const struct V_45 * V_46 )
{
struct V_47 * V_48 = F_20 ( V_20 -> V_24 . V_49 ) ;
struct V_50 V_51 = {} ;
struct V_7 * V_8 ;
if ( ! F_21 ( V_48 , V_52 ) )
return - V_53 ;
V_8 = F_22 ( & V_20 -> V_24 , sizeof( * V_8 ) , V_54 ) ;
if ( ! V_8 )
return - V_55 ;
V_8 -> V_20 = V_20 ;
V_8 -> V_31 = V_20 -> V_24 . V_56 ;
F_23 ( V_20 , V_8 ) ;
V_51 . V_57 = V_8 ;
V_8 -> V_58 = F_24 ( & V_20 -> V_24 ,
& V_59 , & V_51 ) ;
if ( F_25 ( V_8 -> V_58 ) ) {
F_5 ( & V_20 -> V_24 , L_3 ) ;
return F_26 ( V_8 -> V_58 ) ;
}
F_8 ( V_20 ) ;
F_12 ( V_20 ) ;
F_27 ( & V_8 -> V_42 , F_16 ) ;
F_18 ( V_43 , & V_8 -> V_42 ,
V_44 ) ;
return 0 ;
}
static int F_28 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = F_10 ( V_20 ) ;
F_29 ( V_8 -> V_58 ) ;
F_30 ( & V_8 -> V_42 ) ;
return 0 ;
}
static int F_31 ( struct V_60 * V_24 )
{
struct V_19 * V_20 = F_32 ( V_24 ) ;
struct V_7 * V_8 = F_10 ( V_20 ) ;
F_30 ( & V_8 -> V_42 ) ;
return 0 ;
}
static int F_33 ( struct V_60 * V_24 )
{
struct V_19 * V_20 = F_32 ( V_24 ) ;
struct V_7 * V_8 = F_10 ( V_20 ) ;
F_18 ( V_43 , & V_8 -> V_42 ,
V_44 ) ;
return 0 ;
}
