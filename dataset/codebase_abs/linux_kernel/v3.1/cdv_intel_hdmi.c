static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_13 ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = F_3 ( V_15 ) ;
V_13 = ( 2 << 10 ) ;
if ( V_5 -> V_18 & V_19 )
V_13 |= V_20 ;
if ( V_5 -> V_18 & V_21 )
V_13 |= V_22 ;
if ( V_17 -> V_23 == 1 )
V_13 |= V_24 ;
if ( V_11 -> V_25 ) {
V_13 |= V_26 ;
V_13 |= V_27 ;
}
F_4 ( V_11 -> V_28 , V_13 ) ;
F_5 ( V_11 -> V_28 ) ;
}
static bool F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 )
{
return true ;
}
static void F_7 ( struct V_1 * V_2 , int V_4 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_13 ;
V_13 = F_5 ( V_11 -> V_28 ) ;
if ( V_4 != V_29 )
F_4 ( V_11 -> V_28 , V_13 & ~ V_30 ) ;
else
F_4 ( V_11 -> V_28 , V_13 | V_30 ) ;
F_5 ( V_11 -> V_28 ) ;
}
static void F_8 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = V_32 -> V_7 ;
struct V_8 * V_9 = F_9 ( V_32 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_11 -> V_33 = F_5 ( V_11 -> V_28 ) ;
}
static void F_10 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = V_32 -> V_7 ;
struct V_8 * V_9 = F_9 ( V_32 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
F_4 ( V_11 -> V_28 , V_11 -> V_33 ) ;
F_5 ( V_11 -> V_28 ) ;
}
static enum V_34 F_11 (
struct V_31 * V_32 , bool V_35 )
{
struct V_8 * V_8 =
F_9 ( V_32 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_36 * V_36 = NULL ;
enum V_34 V_37 = V_38 ;
V_36 = F_12 ( & V_8 -> V_39 ,
V_8 -> V_40 ) ;
V_11 -> V_41 = false ;
V_11 -> V_25 = false ;
if ( V_36 ) {
if ( V_36 -> V_42 & V_43 ) {
V_37 = V_44 ;
V_11 -> V_41 =
F_13 ( V_36 ) ;
V_11 -> V_25 =
F_14 ( V_36 ) ;
}
V_8 -> V_39 . V_45 . V_46 = NULL ;
F_15 ( V_36 ) ;
}
return V_37 ;
}
static int F_16 ( struct V_31 * V_32 ,
struct V_47 * V_48 ,
T_2 V_49 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
if ( ! strcmp ( V_48 -> V_50 , L_1 ) && V_2 ) {
struct V_16 * V_15 = F_3 ( V_2 -> V_15 ) ;
bool V_51 ;
T_2 V_52 ;
if ( ! V_15 )
return - 1 ;
switch ( V_49 ) {
case V_53 :
break;
case V_54 :
break;
case V_55 :
break;
default:
return - 1 ;
}
if ( F_17 ( V_32 ,
V_48 , & V_52 ) )
return - 1 ;
if ( V_52 == V_49 )
return 0 ;
if ( F_18 ( V_32 ,
V_48 , V_49 ) )
return - 1 ;
V_51 = ( V_52 == V_54 ) ||
( V_49 == V_54 ) ;
if ( V_15 -> V_56 . V_57 != 0 &&
V_15 -> V_56 . V_58 != 0 ) {
if ( V_51 ) {
if ( ! F_19 ( V_2 -> V_15 , & V_15 -> V_56 ,
V_2 -> V_15 -> V_59 , V_2 -> V_15 -> V_60 , V_2 -> V_15 -> V_61 ) )
return - 1 ;
} else {
struct V_62 * V_63
= V_2 -> V_64 ;
V_63 -> V_65 ( V_2 , & V_15 -> V_56 ,
& V_15 -> V_66 ) ;
}
}
}
return 0 ;
}
static int F_20 ( struct V_31 * V_32 )
{
struct V_8 * V_8 =
F_9 ( V_32 ) ;
struct V_36 * V_36 = NULL ;
int V_67 = 0 ;
V_36 = F_12 ( & V_8 -> V_39 ,
V_8 -> V_40 ) ;
if ( V_36 ) {
F_21 ( & V_8 ->
V_39 , V_36 ) ;
V_67 = F_22 ( & V_8 -> V_39 , V_36 ) ;
F_15 ( V_36 ) ;
}
return V_67 ;
}
static int F_23 ( struct V_31 * V_32 ,
struct V_3 * V_4 )
{
if ( V_4 -> clock > 165000 )
return V_68 ;
if ( V_4 -> clock < 20000 )
return V_68 ;
if ( V_4 -> V_18 & V_69 )
return V_70 ;
if ( V_4 -> V_18 & V_71 )
return V_72 ;
if ( V_4 -> V_57 > 1680 )
return V_73 ;
if ( V_4 -> V_58 > 1050 )
return V_73 ;
return V_74 ;
}
static void F_24 ( struct V_31 * V_32 )
{
struct V_8 * V_8 =
F_9 ( V_32 ) ;
if ( V_8 -> V_75 )
F_25 ( V_8 -> V_75 ) ;
F_26 ( V_32 ) ;
F_27 ( V_32 ) ;
F_15 ( V_32 ) ;
}
void F_28 ( struct V_6 * V_7 ,
struct V_76 * V_77 , int V_78 )
{
struct V_8 * V_8 ;
struct V_31 * V_32 ;
struct V_1 * V_2 ;
struct V_10 * V_11 ;
int V_75 ;
V_8 = F_29 ( sizeof( struct V_8 ) +
sizeof( struct V_10 ) , V_79 ) ;
if ( ! V_8 )
return;
V_11 = (struct V_10 * ) ( V_8 + 1 ) ;
V_8 -> V_77 = V_77 ;
V_32 = & V_8 -> V_39 ;
V_2 = & V_8 -> V_80 ;
F_30 ( V_7 , & V_8 -> V_39 ,
& V_81 ,
V_82 ) ;
F_31 ( V_7 , & V_8 -> V_80 , & V_83 ,
V_84 ) ;
F_32 ( & V_8 -> V_39 ,
& V_8 -> V_80 ) ;
V_8 -> type = V_85 ;
V_11 -> V_28 = V_78 ;
V_11 -> V_41 = false ;
V_8 -> V_12 = V_11 ;
F_33 ( V_2 , & V_86 ) ;
F_34 ( V_32 ,
& V_87 ) ;
V_32 -> V_45 . V_88 = V_89 ;
V_32 -> V_90 = false ;
V_32 -> V_91 = false ;
F_35 ( V_32 ,
V_7 -> V_92 . V_93 , V_53 ) ;
switch ( V_78 ) {
case V_94 :
V_75 = V_95 ;
break;
case V_96 :
V_75 = V_97 ;
break;
default:
F_36 ( L_2 , V_78 ) ;
goto V_98;
break;
}
V_8 -> V_75 = F_37 ( V_7 ,
V_75 , ( V_78 == V_94 ) ? L_3 : L_4 ) ;
if ( ! V_8 -> V_75 ) {
F_38 ( V_7 -> V_7 , L_5 ) ;
goto V_98;
}
V_8 -> V_40 =
& ( V_8 -> V_75 -> V_99 ) ;
V_11 -> V_7 = V_7 ;
F_39 ( V_32 ) ;
return;
V_98:
F_40 ( & V_8 -> V_80 ) ;
F_27 ( & V_8 -> V_39 ) ;
F_15 ( V_8 ) ;
}
