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
F_3 ( V_20 , V_26 , 0x54 ) ;
F_3 ( V_20 , V_27 , 0x00 ) ;
}
static void F_9 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = F_10 ( V_20 ) ;
T_1 V_28 ;
T_1 V_29 ;
V_28 = F_6 ( V_20 , V_30 ) ;
V_29 = F_6 ( V_20 , V_31 ) ;
V_8 -> V_15 = ( V_28 << 4 ) + ( V_29 >> 4 ) ;
}
static void F_11 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = F_10 ( V_20 ) ;
T_1 V_28 ;
T_1 V_29 ;
V_28 = F_6 ( V_20 , V_32 ) ;
V_29 = F_6 ( V_20 , V_33 ) ;
V_8 -> V_17 = V_28 ;
}
static void F_12 ( struct V_19 * V_20 )
{
T_1 V_28 ;
T_1 V_29 ;
V_28 = F_6 ( V_20 , V_34 ) ;
V_29 = F_6 ( V_20 , V_35 ) ;
F_13 ( & V_20 -> V_24 , L_2 , V_28 , V_29 ) ;
}
static void F_14 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = F_10 ( V_20 ) ;
if ( V_8 -> V_36 && V_8 -> V_36 -> V_37 )
V_8 -> V_13 = V_8 -> V_36 -> V_37 () ;
else
V_8 -> V_13 = 1 ;
}
static void F_15 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = F_10 ( V_20 ) ;
if ( ! V_8 -> V_36 || ! V_8 -> V_36 -> V_38
|| ! V_8 -> V_36 -> V_39 ) {
V_8 -> V_11 = V_40 ;
return;
}
if ( V_8 -> V_36 -> V_38 () ) {
if ( V_8 -> V_36 -> V_39 () )
V_8 -> V_11 = V_41 ;
else
V_8 -> V_11 = V_42 ;
} else {
V_8 -> V_11 = V_43 ;
}
if ( V_8 -> V_17 > V_44 )
V_8 -> V_11 = V_45 ;
}
static void F_16 ( struct V_46 * V_47 )
{
struct V_7 * V_8 ;
V_8 = F_17 ( V_47 , struct V_7 , V_47 . V_47 ) ;
F_9 ( V_8 -> V_20 ) ;
F_11 ( V_8 -> V_20 ) ;
F_14 ( V_8 -> V_20 ) ;
F_15 ( V_8 -> V_20 ) ;
F_18 ( V_48 , & V_8 -> V_47 ,
V_49 ) ;
}
static int F_19 ( struct V_19 * V_20 ,
const struct V_50 * V_51 )
{
struct V_52 * V_53 = F_20 ( V_20 -> V_24 . V_54 ) ;
struct V_55 V_56 = {} ;
struct V_7 * V_8 ;
if ( ! F_21 ( V_53 , V_57 ) )
return - V_58 ;
V_8 = F_22 ( & V_20 -> V_24 , sizeof( * V_8 ) , V_59 ) ;
if ( ! V_8 )
return - V_60 ;
V_8 -> V_20 = V_20 ;
V_8 -> V_36 = V_20 -> V_24 . V_61 ;
F_23 ( V_20 , V_8 ) ;
V_56 . V_62 = V_8 ;
V_8 -> V_63 = F_24 ( & V_20 -> V_24 ,
& V_64 , & V_56 ) ;
if ( F_25 ( V_8 -> V_63 ) ) {
F_5 ( & V_20 -> V_24 , L_3 ) ;
return F_26 ( V_8 -> V_63 ) ;
}
F_8 ( V_20 ) ;
F_12 ( V_20 ) ;
F_27 ( & V_8 -> V_47 , F_16 ) ;
F_18 ( V_48 , & V_8 -> V_47 ,
V_49 ) ;
return 0 ;
}
static int F_28 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = F_10 ( V_20 ) ;
F_29 ( V_8 -> V_63 ) ;
F_30 ( & V_8 -> V_47 ) ;
return 0 ;
}
static int F_31 ( struct V_65 * V_24 )
{
struct V_19 * V_20 = F_32 ( V_24 ) ;
struct V_7 * V_8 = F_10 ( V_20 ) ;
F_30 ( & V_8 -> V_47 ) ;
return 0 ;
}
static int F_33 ( struct V_65 * V_24 )
{
struct V_19 * V_20 = F_32 ( V_24 ) ;
struct V_7 * V_8 = F_10 ( V_20 ) ;
F_18 ( V_48 , & V_8 -> V_47 ,
V_49 ) ;
return 0 ;
}
