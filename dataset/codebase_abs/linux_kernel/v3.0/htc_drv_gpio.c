static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( F_2 ( V_6 , V_6 -> V_7 . V_8 ) )
V_4 -> V_9 ++ ;
if ( F_3 ( V_10 , V_4 -> V_11 +
F_4 ( V_12 ) ) ) {
V_2 -> V_13 &= ~ ( V_14 | V_15 ) ;
if ( V_4 -> V_9 >= V_16 ) {
F_5 ( F_6 ( V_6 ) , V_17 ,
L_1 ) ;
V_2 -> V_13 |= ( V_15 |
V_14 ) ;
} else if ( V_4 -> V_9 >= V_18 ) {
F_5 ( F_6 ( V_6 ) , V_17 ,
L_2 ) ;
V_2 -> V_13 |= V_14 ;
}
V_4 -> V_9 = 0 ;
V_4 -> V_11 = V_10 ;
}
}
static void F_7 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_8 ( V_20 , struct V_1 ,
V_21 . V_20 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_22 * V_23 = F_6 ( V_2 -> V_6 ) ;
T_1 V_24 ;
bool V_25 ;
int V_26 ;
F_1 ( V_2 ) ;
V_25 = ! ! ( V_2 -> V_13 & V_15 ) ;
V_26 = F_9 ( V_2 ,
! ! ( V_2 -> V_13 & V_14 ) ) ;
if ( V_26 ) {
F_10 ( V_23 , L_3 ) ;
return;
}
F_11 ( V_2 -> V_6 , V_25 ? V_27 :
V_4 -> V_28 ) ;
V_24 = V_25 ? V_4 -> V_29 :
V_4 -> V_30 ;
F_12 ( V_2 -> V_31 , & V_2 -> V_32 ,
F_4 ( V_24 ) ) ;
F_12 ( V_2 -> V_31 , & V_2 -> V_21 ,
F_4 ( V_4 -> V_33 ) ) ;
}
static void F_13 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_8 ( V_20 , struct V_1 ,
V_32 . V_20 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_22 * V_23 = F_6 ( V_6 ) ;
bool V_25 = V_2 -> V_13 & V_15 ;
F_5 ( V_23 , V_17 ,
L_4 ) ;
if ( V_4 -> V_28 == V_34 || V_25 )
F_11 ( V_6 , V_35 ) ;
else if ( V_4 -> V_28 == V_27 )
F_11 ( V_6 , V_34 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
V_4 -> V_33 = V_36 ;
V_4 -> V_30 = ( 100 - V_37 ) *
V_4 -> V_33 / 100 ;
V_4 -> V_29 = ( 100 - V_38 ) *
V_4 -> V_33 / 100 ;
F_15 ( & V_2 -> V_21 , F_7 ) ;
F_15 ( & V_2 -> V_32 , F_13 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_5 ( F_6 ( V_6 ) , V_17 , L_5 ) ;
V_4 -> V_9 = 0 ;
V_4 -> V_11 = V_10 ;
V_2 -> V_13 &= ~ ( V_14 | V_15 ) ;
F_12 ( V_2 -> V_31 , & V_2 -> V_21 , 0 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_21 ) ;
F_18 ( & V_2 -> V_32 ) ;
}
void F_19 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_8 ( V_20 ,
struct V_1 ,
V_39 ) ;
F_20 ( V_2 -> V_6 , V_2 -> V_6 -> V_40 ,
( V_2 -> V_41 == V_42 ) ) ;
}
static void F_21 ( struct V_43 * V_44 ,
enum V_45 V_41 )
{
struct V_1 * V_2 = F_8 ( V_44 ,
struct V_1 ,
V_44 ) ;
V_2 -> V_41 = V_41 ;
F_22 ( V_2 -> V_31 , & V_2 -> V_39 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_46 )
return;
F_21 ( & V_2 -> V_44 , V_42 ) ;
F_24 ( & V_2 -> V_44 ) ;
F_25 ( & V_2 -> V_39 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
int V_26 ;
if ( F_27 ( V_2 -> V_6 ) )
V_2 -> V_6 -> V_40 = V_47 ;
else if ( F_28 ( V_2 -> V_6 ) )
V_2 -> V_6 -> V_40 = V_48 ;
else if ( F_29 ( V_2 -> V_6 ) )
V_2 -> V_6 -> V_40 = V_49 ;
else
V_2 -> V_6 -> V_40 = V_50 ;
F_30 ( V_2 -> V_6 , V_2 -> V_6 -> V_40 ,
V_51 ) ;
F_20 ( V_2 -> V_6 , V_2 -> V_6 -> V_40 , 1 ) ;
snprintf ( V_2 -> V_52 , sizeof( V_2 -> V_52 ) ,
L_6 , F_31 ( V_2 -> V_31 -> V_53 ) ) ;
V_2 -> V_44 . V_54 = V_2 -> V_52 ;
V_2 -> V_44 . V_55 = F_21 ;
V_26 = F_32 ( F_33 ( V_2 -> V_31 -> V_53 ) , & V_2 -> V_44 ) ;
if ( V_26 < 0 )
return;
F_34 ( & V_2 -> V_39 , F_19 ) ;
V_2 -> V_46 = true ;
return;
}
static bool F_35 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_6 , V_2 -> V_6 -> V_56 ) ==
V_2 -> V_6 -> V_57 ;
}
void F_36 ( struct V_58 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
bool V_59 = ! ! F_35 ( V_2 ) ;
F_37 ( V_31 -> V_53 , V_59 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_60 . V_61 & V_62 )
F_39 ( V_2 -> V_31 -> V_53 ) ;
}
void F_40 ( struct V_58 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_22 * V_23 = F_6 ( V_6 ) ;
int V_26 ;
T_2 V_63 ;
if ( ! V_6 -> V_64 )
V_6 -> V_64 = F_41 ( V_31 , V_6 ) ;
V_26 = F_42 ( V_6 , V_6 -> V_64 , V_6 -> V_65 , false ) ;
if ( V_26 ) {
F_10 ( V_23 ,
L_7 ,
V_26 , V_6 -> V_64 -> V_66 ) ;
}
F_43 ( V_6 , V_2 -> V_67 , V_2 -> V_68 ,
& V_2 -> V_67 ) ;
F_44 ( V_69 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 -> V_70 ) ;
F_47 ( & V_2 -> V_71 . V_72 ) ;
V_2 -> V_71 . V_73 &= ~ V_74 ;
F_48 ( & V_2 -> V_71 . V_72 ) ;
F_49 ( V_31 ) ;
F_44 ( V_75 ) ;
F_30 ( V_6 , V_6 -> V_40 ,
V_51 ) ;
F_20 ( V_6 , V_6 -> V_40 , 0 ) ;
}
void F_50 ( struct V_58 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_22 * V_23 = F_6 ( V_6 ) ;
int V_26 ;
T_2 V_63 ;
F_51 ( V_2 ) ;
F_20 ( V_6 , V_6 -> V_40 , 1 ) ;
F_52 ( V_6 , V_6 -> V_40 ) ;
F_44 ( V_76 ) ;
F_53 ( V_31 ) ;
F_54 ( V_2 ) ;
F_44 ( V_77 ) ;
F_44 ( V_78 ) ;
F_55 ( V_2 ) ;
F_56 ( V_6 ) ;
if ( ! V_6 -> V_64 )
V_6 -> V_64 = F_41 ( V_31 , V_6 ) ;
V_26 = F_42 ( V_6 , V_6 -> V_64 , V_6 -> V_65 , false ) ;
if ( V_26 ) {
F_10 ( V_23 ,
L_7 ,
V_26 , V_6 -> V_64 -> V_66 ) ;
}
F_57 ( V_6 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 , V_79 ) ;
}
