static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_3 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 V_11 ;
unsigned long V_12 ;
if ( ! F_3 ( & V_5 -> V_13 ) )
return V_14 ;
F_4 ( & V_11 ) ;
if ( V_7 -> V_15 == V_16 )
V_5 -> V_17 = V_11 . V_18 & 0xffff ;
else
V_5 -> V_17 = V_11 . V_19 & 0xffff ;
if ( V_5 -> V_17 >= V_5 -> V_20 )
V_12 = V_5 -> V_17 - V_5 -> V_20 ;
else
V_12 = V_9 -> V_21 + V_5 -> V_17
- V_5 -> V_20 ;
if ( V_12 >= V_5 -> V_22 ) {
F_5 ( V_7 ) ;
V_5 -> V_20 = V_5 -> V_17 ;
}
F_6 ( V_3 , F_7 ( V_5 -> V_23 ) ) ;
return V_24 ;
}
static int F_8 ( struct V_6 * V_7 ,
struct V_25 * V_26 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_4 * V_5 = V_9 -> V_27 ;
V_5 -> V_28 = F_9 ( V_26 ) ;
V_5 -> V_29 = F_10 ( V_26 ) ;
V_5 -> V_22 = F_11 ( V_26 ) ;
V_5 -> V_17 = 0 ;
V_5 -> V_20 = 0 ;
V_5 -> V_23 = 1000000000 / F_12 ( V_26 ) *
F_13 ( V_26 ) ;
F_14 ( V_7 , & V_7 -> V_30 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_4 * V_5 = V_9 -> V_27 ;
struct V_10 V_11 ;
F_4 ( & V_11 ) ;
if ( V_7 -> V_15 == V_16 )
V_11 . V_18 = ( V_5 -> V_22 * V_5 -> V_29 - 1 ) << 16 ;
else
V_11 . V_19 = ( V_5 -> V_22 * V_5 -> V_29 - 1 ) << 16 ;
F_16 ( & V_11 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , int V_31 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_4 * V_5 = V_9 -> V_27 ;
switch ( V_31 ) {
case V_32 :
case V_33 :
case V_34 :
F_18 ( & V_5 -> V_13 , 1 ) ;
F_19 ( & V_5 -> V_3 , F_7 ( V_5 -> V_23 ) ,
V_35 ) ;
if ( ++ V_36 == 1 )
F_20 ( V_37 ) ;
break;
case V_38 :
case V_39 :
case V_40 :
F_18 ( & V_5 -> V_13 , 0 ) ;
if ( -- V_36 == 0 )
F_21 ( V_37 ) ;
break;
default:
return - V_41 ;
}
return 0 ;
}
static T_1 F_22 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_4 * V_5 = V_9 -> V_27 ;
return F_23 ( V_7 -> V_9 , V_5 -> V_17 ) ;
}
static int F_24 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_4 * V_5 ;
int V_42 ;
V_5 = F_25 ( sizeof( * V_5 ) , V_43 ) ;
if ( V_5 == NULL )
return - V_44 ;
V_9 -> V_27 = V_5 ;
V_5 -> V_7 = V_7 ;
F_18 ( & V_5 -> V_13 , 0 ) ;
F_26 ( & V_5 -> V_3 , V_45 , V_35 ) ;
V_5 -> V_3 . V_46 = F_1 ;
V_42 = F_27 ( V_7 -> V_9 ,
V_47 ) ;
if ( V_42 < 0 ) {
F_28 ( V_5 ) ;
return V_42 ;
}
F_29 ( V_7 , & V_48 ) ;
return 0 ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_4 * V_5 = V_9 -> V_27 ;
F_31 ( & V_5 -> V_3 ) ;
F_28 ( V_5 ) ;
return 0 ;
}
static int F_32 ( struct V_49 * V_50 )
{
struct V_51 * V_52 = V_50 -> V_52 ;
struct V_6 * V_7 ;
int V_42 ;
V_42 = F_33 ( V_50 ) ;
if ( V_42 )
return V_42 ;
V_7 = V_52 -> V_53 [ V_16 ] . V_7 ;
if ( V_7 ) {
struct V_54 * V_55 = & V_7 -> V_30 ;
V_56 = ( unsigned long ) V_55 -> V_57 ;
}
V_7 = V_52 -> V_53 [ V_58 ] . V_7 ;
if ( V_7 ) {
struct V_54 * V_55 = & V_7 -> V_30 ;
V_59 = ( unsigned long ) V_55 -> V_57 ;
}
F_34 ( & V_60 ,
& V_61 - & V_60 ) ;
return 0 ;
}
static void F_35 ( struct V_51 * V_52 )
{
F_36 ( V_62 , 0 ) ;
F_37 ( & V_63 ) ;
F_38 ( V_52 ) ;
}
static int T_2 F_39 ( struct V_64 * V_65 )
{
struct V_66 * V_67 = F_40 ( V_65 ) ;
int V_42 ;
V_42 = F_41 ( & V_63 ) ;
if ( V_42 ) {
F_42 ( & V_65 -> V_68 , L_1 , V_42 ) ;
return V_42 ;
}
F_36 ( V_67 -> V_69 , 1 ) ;
V_62 = V_67 -> V_69 ;
V_37 = V_67 -> V_69 ;
V_70 = ( unsigned long ) V_67 -> V_71 ;
V_67 -> V_72 . V_73 = 4 ;
V_67 -> V_74 . V_73 = 6 ;
V_42 = F_43 ( & V_65 -> V_68 , & V_75 ) ;
if ( V_42 )
goto V_76;
return 0 ;
V_76:
F_36 ( V_62 , 0 ) ;
F_37 ( & V_63 ) ;
return V_42 ;
}
static int T_3 F_44 ( struct V_64 * V_65 )
{
F_45 ( & V_65 -> V_68 ) ;
return 0 ;
}
