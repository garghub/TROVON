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
V_17 . V_37 = ( V_18 & V_38 ) >> V_39 ;
V_17 . V_40 = ( V_18 & V_41 ) >> V_42 ;
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
V_18 |= ( V_17 . V_37 << V_39 ) & V_38 ;
V_18 |= ( V_17 . V_40 << V_42 ) & V_41 ;
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
V_17 . V_43 = ( V_4 -> V_20 & V_44 ) >> V_45 ;
F_3 ( V_2 , & V_17 ) ;
} else {
V_4 -> V_20 = ( V_17 . V_43 << V_45 ) & V_44 ;
}
return true ;
}
static bool F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_16 V_17 ;
F_2 ( V_2 , & V_17 ) ;
if ( V_4 -> V_19 ) {
V_17 . V_46 = ( V_4 -> V_20 & V_47 ) >>
V_48 ;
F_3 ( V_2 , & V_17 ) ;
} else {
V_4 -> V_20 = ( V_17 . V_46 << V_48 ) &
V_47 ;
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
if ( ! V_17 . V_37 ) {
if ( V_4 -> V_19 ) {
V_17 . V_49 = ( V_4 -> V_20 & V_50 ) >>
V_51 ;
F_3 ( V_2 , & V_17 ) ;
} else {
V_4 -> V_20 = ( V_17 . V_49 << V_51 ) &
V_50 ;
}
} else {
if ( ! V_4 -> V_19 )
V_4 -> V_20 = F_7 ( ( V_17 . V_46 + 1 ) , 7U ) ;
}
return true ;
}
static bool F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_16 V_17 ;
F_2 ( V_2 , & V_17 ) ;
if ( V_4 -> V_19 ) {
V_17 . V_52 = ( V_4 -> V_20 & V_53 ) >>
V_54 ;
F_3 ( V_2 , & V_17 ) ;
} else {
V_4 -> V_20 = ( V_17 . V_52 << V_54 ) &
V_53 ;
}
return true ;
}
static bool F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_16 V_17 ;
F_2 ( V_2 , & V_17 ) ;
if ( V_4 -> V_19 ) {
V_17 . V_55 = ( V_4 -> V_20 & V_56 ) >>
V_57 ;
F_3 ( V_2 , & V_17 ) ;
} else {
V_4 -> V_20 = ( V_17 . V_55 << V_57 ) &
V_56 ;
}
return true ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_3 V_58 , T_3 V_59 )
{
struct V_60 * V_61 = & V_2 -> V_15 . V_13 . V_62 ;
T_4 * V_63 ;
if ( V_58 )
V_63 = & V_61 -> V_64 [ V_59 ] ;
else
V_63 = & V_61 -> V_65 [ V_59 ] ;
if ( V_4 -> V_19 )
* V_63 = V_4 -> V_20 ;
else
V_4 -> V_20 = * V_63 ;
}
static bool F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 , T_3 V_58 )
{
T_3 V_59 = V_6 -> V_66 & 3 ;
if ( V_59 > F_12 ( V_2 ) )
goto V_67;
F_10 ( V_2 , V_4 , V_58 , V_59 ) ;
return true ;
V_67:
if ( ! V_4 -> V_19 )
V_4 -> V_20 = 0 ;
return false ;
}
static bool F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
return F_11 ( V_2 , V_4 , V_6 , 0 ) ;
}
static bool F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
return F_11 ( V_2 , V_4 , V_6 , 1 ) ;
}
static bool F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_60 * V_61 = & V_2 -> V_15 . V_13 . V_62 ;
if ( V_4 -> V_19 ) {
if ( ! ( V_4 -> V_20 & V_68 ) )
return false ;
} else {
V_4 -> V_20 = V_61 -> V_69 ;
}
return true ;
}
int F_16 ( struct V_1 * V_2 , bool V_19 , T_2 V_70 ,
T_2 * V_71 )
{
struct V_3 V_72 ;
T_2 V_73 = ( V_70 & V_74 ) | V_75 ;
V_72 . V_20 = * V_71 ;
V_72 . V_19 = V_19 ;
V_72 . V_76 = false ;
V_72 . V_77 = false ;
if ( F_17 ( V_73 , & V_72 , V_78 ,
F_18 ( V_78 ) ) )
return 0 ;
return - V_79 ;
}
int F_19 ( struct V_1 * V_2 , bool V_19 , T_2 V_70 ,
T_2 * V_71 )
{
struct V_3 V_72 ;
const struct V_5 * V_6 ;
T_2 V_73 = ( V_70 & V_74 ) | V_75 ;
if ( V_19 )
V_72 . V_20 = * V_71 ;
V_72 . V_19 = V_19 ;
V_72 . V_76 = false ;
V_72 . V_77 = false ;
V_6 = F_17 ( V_73 , & V_72 , V_78 ,
F_18 ( V_78 ) ) ;
if ( ! V_6 )
return - V_79 ;
if ( ! V_6 -> V_80 ( V_2 , & V_72 , V_6 ) )
return - V_81 ;
if ( ! V_19 )
* V_71 = V_72 . V_20 ;
return 0 ;
}
