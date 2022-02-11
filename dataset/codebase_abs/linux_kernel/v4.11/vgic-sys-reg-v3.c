static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
T_1 V_7 , V_8 , V_9 , V_10 , V_11 , V_12 ;
struct V_13 * V_14 = & V_2 -> V_15 . V_13 ;
struct V_16 V_17 ;
T_2 V_18 ;
F_2 ( V_2 , & V_17 ) ;
if ( V_4 -> V_19 ) {
V_18 = V_4 -> V_20 ;
V_7 = ( ( V_18 & V_21 ) >>
V_22 ) + 1 ;
if ( V_7 > V_14 -> V_23 )
return false ;
V_14 -> V_23 = V_7 ;
V_8 = ( V_18 & V_24 ) >>
V_25 ;
if ( V_8 > V_14 -> V_26 )
return false ;
V_14 -> V_26 = V_8 ;
V_9 = ( ( V_27 . V_28 &
V_29 ) >> V_30 ) ;
V_11 = ( V_18 & V_31 ) >>
V_32 ;
if ( V_9 != V_11 )
return false ;
V_10 = ( ( V_27 . V_28 &
V_33 ) >> V_34 ) ;
V_12 = ( V_18 & V_35 ) >> V_36 ;
if ( V_10 != V_12 )
return false ;
V_17 . V_37 = V_18 & V_38 ;
V_17 . V_37 |= V_18 & V_39 ;
F_3 ( V_2 , & V_17 ) ;
} else {
V_18 = 0 ;
V_18 |= ( V_14 -> V_23 - 1 ) <<
V_22 ;
V_18 |= V_14 -> V_26 << V_25 ;
V_18 |= ( ( V_27 . V_28 &
V_29 ) >> V_30 ) <<
V_32 ;
V_18 |= ( ( V_27 . V_28 &
V_33 ) >> V_34 ) <<
V_36 ;
V_18 |= V_17 . V_37 & V_38 ;
V_18 |= V_17 . V_37 & V_39 ;
V_4 -> V_20 = V_18 ;
}
return true ;
}
static bool F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_16 V_17 ;
F_2 ( V_2 , & V_17 ) ;
if ( V_4 -> V_19 ) {
V_17 . V_40 = ( V_4 -> V_20 & V_41 ) >> V_42 ;
F_3 ( V_2 , & V_17 ) ;
} else {
V_4 -> V_20 = ( V_17 . V_40 << V_42 ) & V_41 ;
}
return true ;
}
static bool F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_16 V_17 ;
F_2 ( V_2 , & V_17 ) ;
if ( V_4 -> V_19 ) {
V_17 . V_43 = ( V_4 -> V_20 & V_44 ) >>
V_45 ;
F_3 ( V_2 , & V_17 ) ;
} else {
V_4 -> V_20 = ( V_17 . V_43 << V_45 ) &
V_44 ;
}
return true ;
}
static bool F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_16 V_17 ;
if ( ! V_4 -> V_19 )
V_4 -> V_20 = 0 ;
F_2 ( V_2 , & V_17 ) ;
if ( ! ( ( V_17 . V_37 & V_46 ) >> V_47 ) ) {
if ( V_4 -> V_19 ) {
V_17 . V_48 = ( V_4 -> V_20 & V_49 ) >>
V_50 ;
F_3 ( V_2 , & V_17 ) ;
} else {
V_4 -> V_20 = ( V_17 . V_48 << V_50 ) &
V_49 ;
}
} else {
if ( ! V_4 -> V_19 )
V_4 -> V_20 = F_7 ( ( V_17 . V_43 + 1 ) , 7U ) ;
}
return true ;
}
static bool F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_16 V_17 ;
F_2 ( V_2 , & V_17 ) ;
if ( V_4 -> V_19 ) {
V_17 . V_51 = ( V_4 -> V_20 & V_52 ) >>
V_53 ;
F_3 ( V_2 , & V_17 ) ;
} else {
V_4 -> V_20 = ( V_17 . V_51 << V_53 ) &
V_52 ;
}
return true ;
}
static bool F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_16 V_17 ;
F_2 ( V_2 , & V_17 ) ;
if ( V_4 -> V_19 ) {
V_17 . V_54 = ( V_4 -> V_20 & V_55 ) >>
V_56 ;
F_3 ( V_2 , & V_17 ) ;
} else {
V_4 -> V_20 = ( V_17 . V_54 << V_56 ) &
V_55 ;
}
return true ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_3 V_57 , T_3 V_58 )
{
struct V_59 * V_60 = & V_2 -> V_15 . V_13 . V_61 ;
T_4 * V_62 ;
if ( V_57 )
V_62 = & V_60 -> V_63 [ V_58 ] ;
else
V_62 = & V_60 -> V_64 [ V_58 ] ;
if ( V_4 -> V_19 )
* V_62 = V_4 -> V_20 ;
else
V_4 -> V_20 = * V_62 ;
}
static bool F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 , T_3 V_57 )
{
struct V_13 * V_14 = & V_2 -> V_15 . V_13 ;
T_3 V_58 = V_6 -> V_65 & 3 ;
switch ( V_14 -> V_23 ) {
case 7 :
F_10 ( V_2 , V_4 , V_57 , V_58 ) ;
break;
case 6 :
if ( V_58 > 1 )
goto V_66;
F_10 ( V_2 , V_4 , V_57 , V_58 ) ;
break;
default:
if ( V_58 > 0 )
goto V_66;
F_10 ( V_2 , V_4 , V_57 , V_58 ) ;
}
return true ;
V_66:
if ( ! V_4 -> V_19 )
V_4 -> V_20 = 0 ;
return false ;
}
static bool F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
return F_11 ( V_2 , V_4 , V_6 , 0 ) ;
}
static bool F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
return F_11 ( V_2 , V_4 , V_6 , 1 ) ;
}
static bool F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_59 * V_60 = & V_2 -> V_15 . V_13 . V_61 ;
if ( V_4 -> V_19 ) {
if ( ! ( V_4 -> V_20 & V_67 ) )
return false ;
} else {
V_4 -> V_20 = V_60 -> V_68 ;
}
return true ;
}
int F_15 ( struct V_1 * V_2 , bool V_19 , T_2 V_69 ,
T_2 * V_70 )
{
struct V_3 V_71 ;
T_2 V_72 = ( V_69 & V_73 ) | V_74 ;
V_71 . V_20 = * V_70 ;
V_71 . V_19 = V_19 ;
V_71 . V_75 = false ;
V_71 . V_76 = false ;
if ( F_16 ( V_72 , & V_71 , V_77 ,
F_17 ( V_77 ) ) )
return 0 ;
return - V_78 ;
}
int F_18 ( struct V_1 * V_2 , bool V_19 , T_2 V_69 ,
T_2 * V_70 )
{
struct V_3 V_71 ;
const struct V_5 * V_6 ;
T_2 V_72 = ( V_69 & V_73 ) | V_74 ;
if ( V_19 )
V_71 . V_20 = * V_70 ;
V_71 . V_19 = V_19 ;
V_71 . V_75 = false ;
V_71 . V_76 = false ;
V_6 = F_16 ( V_72 , & V_71 , V_77 ,
F_17 ( V_77 ) ) ;
if ( ! V_6 )
return - V_78 ;
if ( ! V_6 -> V_79 ( V_2 , & V_71 , V_6 ) )
return - V_80 ;
if ( ! V_19 )
* V_70 = V_71 . V_20 ;
return 0 ;
}
