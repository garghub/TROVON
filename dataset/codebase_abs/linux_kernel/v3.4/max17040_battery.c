static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 , V_9 ) ;
switch ( V_4 ) {
case V_10 :
V_6 -> V_11 = V_8 -> V_12 ;
break;
case V_13 :
V_6 -> V_11 = V_8 -> V_14 ;
break;
case V_15 :
V_6 -> V_11 = V_8 -> V_16 ;
break;
case V_17 :
V_6 -> V_11 = V_8 -> V_18 ;
break;
default:
return - V_19 ;
}
return 0 ;
}
static int F_3 ( struct V_20 * V_21 , int V_22 , T_1 V_23 )
{
int V_24 ;
V_24 = F_4 ( V_21 , V_22 , V_23 ) ;
if ( V_24 < 0 )
F_5 ( & V_21 -> V_25 , L_1 , V_26 , V_24 ) ;
return V_24 ;
}
static int F_6 ( struct V_20 * V_21 , int V_22 )
{
int V_24 ;
V_24 = F_7 ( V_21 , V_22 ) ;
if ( V_24 < 0 )
F_5 ( & V_21 -> V_25 , L_1 , V_26 , V_24 ) ;
return V_24 ;
}
static void F_8 ( struct V_20 * V_21 )
{
F_3 ( V_21 , V_27 , 0x54 ) ;
F_3 ( V_21 , V_28 , 0x00 ) ;
}
static void F_9 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = F_10 ( V_21 ) ;
T_1 V_29 ;
T_1 V_30 ;
V_29 = F_6 ( V_21 , V_31 ) ;
V_30 = F_6 ( V_21 , V_32 ) ;
V_8 -> V_16 = ( V_29 << 4 ) + ( V_30 >> 4 ) ;
}
static void F_11 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = F_10 ( V_21 ) ;
T_1 V_29 ;
T_1 V_30 ;
V_29 = F_6 ( V_21 , V_33 ) ;
V_30 = F_6 ( V_21 , V_34 ) ;
V_8 -> V_18 = V_29 ;
}
static void F_12 ( struct V_20 * V_21 )
{
T_1 V_29 ;
T_1 V_30 ;
V_29 = F_6 ( V_21 , V_35 ) ;
V_30 = F_6 ( V_21 , V_36 ) ;
F_13 ( & V_21 -> V_25 , L_2 , V_29 , V_30 ) ;
}
static void F_14 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = F_10 ( V_21 ) ;
if ( V_8 -> V_37 -> V_38 )
V_8 -> V_14 = V_8 -> V_37 -> V_38 () ;
else
V_8 -> V_14 = 1 ;
}
static void F_15 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = F_10 ( V_21 ) ;
if ( ! V_8 -> V_37 -> V_39 || ! V_8 -> V_37 -> V_40 ) {
V_8 -> V_12 = V_41 ;
return;
}
if ( V_8 -> V_37 -> V_39 () ) {
if ( V_8 -> V_37 -> V_40 () )
V_8 -> V_12 = V_42 ;
else
V_8 -> V_12 = V_43 ;
} else {
V_8 -> V_12 = V_44 ;
}
if ( V_8 -> V_18 > V_45 )
V_8 -> V_12 = V_46 ;
}
static void F_16 ( struct V_47 * V_48 )
{
struct V_7 * V_8 ;
V_8 = F_2 ( V_48 , struct V_7 , V_48 . V_48 ) ;
F_9 ( V_8 -> V_21 ) ;
F_11 ( V_8 -> V_21 ) ;
F_14 ( V_8 -> V_21 ) ;
F_15 ( V_8 -> V_21 ) ;
F_17 ( & V_8 -> V_48 , V_49 ) ;
}
static int T_2 F_18 ( struct V_20 * V_21 ,
const struct V_50 * V_51 )
{
struct V_52 * V_53 = F_19 ( V_21 -> V_25 . V_54 ) ;
struct V_7 * V_8 ;
int V_24 ;
if ( ! F_20 ( V_53 , V_55 ) )
return - V_56 ;
V_8 = F_21 ( sizeof( * V_8 ) , V_57 ) ;
if ( ! V_8 )
return - V_58 ;
V_8 -> V_21 = V_21 ;
V_8 -> V_37 = V_21 -> V_25 . V_59 ;
F_22 ( V_21 , V_8 ) ;
V_8 -> V_9 . V_60 = L_3 ;
V_8 -> V_9 . type = V_61 ;
V_8 -> V_9 . V_62 = F_1 ;
V_8 -> V_9 . V_63 = V_64 ;
V_8 -> V_9 . V_65 = F_23 ( V_64 ) ;
V_24 = F_24 ( & V_21 -> V_25 , & V_8 -> V_9 ) ;
if ( V_24 ) {
F_5 ( & V_21 -> V_25 , L_4 ) ;
F_25 ( V_8 ) ;
return V_24 ;
}
F_8 ( V_21 ) ;
F_12 ( V_21 ) ;
F_26 ( & V_8 -> V_48 , F_16 ) ;
F_17 ( & V_8 -> V_48 , V_49 ) ;
return 0 ;
}
static int T_3 F_27 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = F_10 ( V_21 ) ;
F_28 ( & V_8 -> V_9 ) ;
F_29 ( & V_8 -> V_48 ) ;
F_25 ( V_8 ) ;
return 0 ;
}
static int F_30 ( struct V_20 * V_21 ,
T_4 V_66 )
{
struct V_7 * V_8 = F_10 ( V_21 ) ;
F_29 ( & V_8 -> V_48 ) ;
return 0 ;
}
static int F_31 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = F_10 ( V_21 ) ;
F_17 ( & V_8 -> V_48 , V_49 ) ;
return 0 ;
}
