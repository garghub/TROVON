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
F_12 ( V_2 -> V_6 ) ;
V_24 = V_25 ? V_4 -> V_29 :
V_4 -> V_30 ;
F_13 ( V_2 -> V_31 , & V_2 -> V_32 ,
F_4 ( V_24 ) ) ;
F_13 ( V_2 -> V_31 , & V_2 -> V_21 ,
F_4 ( V_4 -> V_33 ) ) ;
}
static void F_14 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_8 ( V_20 , struct V_1 ,
V_32 . V_20 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_22 * V_23 = F_6 ( V_6 ) ;
bool V_25 = V_2 -> V_13 & V_15 ;
F_5 ( V_23 , V_17 , L_4 ) ;
if ( V_4 -> V_28 == V_34 || V_25 )
F_11 ( V_6 , V_35 ) ;
else if ( V_4 -> V_28 == V_27 )
F_11 ( V_6 , V_34 ) ;
F_12 ( V_2 -> V_6 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
if ( F_16 ( V_2 -> V_6 ) == V_36 )
return;
V_4 -> V_33 = V_37 ;
V_4 -> V_30 = ( 100 - V_38 ) *
V_4 -> V_33 / 100 ;
V_4 -> V_29 = ( 100 - V_39 ) *
V_4 -> V_33 / 100 ;
F_17 ( & V_2 -> V_21 , F_7 ) ;
F_17 ( & V_2 -> V_32 , F_14 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( F_16 ( V_6 ) == V_36 )
return;
F_5 ( F_6 ( V_6 ) , V_17 , L_5 ) ;
V_4 -> V_9 = 0 ;
V_4 -> V_11 = V_10 ;
V_2 -> V_13 &= ~ ( V_14 | V_15 ) ;
F_13 ( V_2 -> V_31 , & V_2 -> V_21 , 0 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
if ( F_16 ( V_2 -> V_6 ) == V_36 )
return;
F_20 ( & V_2 -> V_21 ) ;
F_20 ( & V_2 -> V_32 ) ;
}
void F_21 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_8 ( V_20 ,
struct V_1 ,
V_40 ) ;
F_22 ( V_2 -> V_6 , V_2 -> V_6 -> V_41 ,
( V_2 -> V_42 == V_43 ) ) ;
}
static void F_23 ( struct V_44 * V_45 ,
enum V_46 V_42 )
{
struct V_1 * V_2 = F_8 ( V_45 ,
struct V_1 ,
V_45 ) ;
V_2 -> V_42 = V_42 ;
F_24 ( V_2 -> V_31 , & V_2 -> V_40 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_47 )
return;
F_23 ( & V_2 -> V_45 , V_43 ) ;
F_26 ( & V_2 -> V_45 ) ;
F_27 ( & V_2 -> V_40 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
int V_26 ;
if ( F_29 ( V_2 -> V_6 ) )
V_2 -> V_6 -> V_41 = V_48 ;
else if ( F_30 ( V_2 -> V_6 ) )
V_2 -> V_6 -> V_41 = V_49 ;
else if ( F_31 ( V_2 -> V_6 ) )
V_2 -> V_6 -> V_41 = V_50 ;
else
V_2 -> V_6 -> V_41 = V_51 ;
F_32 ( V_2 -> V_6 , V_2 -> V_6 -> V_41 ,
V_52 ) ;
F_22 ( V_2 -> V_6 , V_2 -> V_6 -> V_41 , 1 ) ;
snprintf ( V_2 -> V_53 , sizeof( V_2 -> V_53 ) ,
L_6 , F_33 ( V_2 -> V_31 -> V_54 ) ) ;
V_2 -> V_45 . V_55 = V_2 -> V_53 ;
V_2 -> V_45 . V_56 = F_23 ;
V_26 = F_34 ( F_35 ( V_2 -> V_31 -> V_54 ) , & V_2 -> V_45 ) ;
if ( V_26 < 0 )
return;
F_36 ( & V_2 -> V_40 , F_21 ) ;
V_2 -> V_47 = true ;
return;
}
static bool F_37 ( struct V_1 * V_2 )
{
bool V_57 ;
F_38 ( V_2 ) ;
V_57 = F_2 ( V_2 -> V_6 , V_2 -> V_6 -> V_58 ) ==
V_2 -> V_6 -> V_59 ;
F_39 ( V_2 ) ;
return V_57 ;
}
void F_40 ( struct V_60 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
bool V_61 = ! ! F_37 ( V_2 ) ;
F_41 ( V_31 -> V_54 , V_61 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_62 . V_63 & V_64 )
F_43 ( V_2 -> V_31 -> V_54 ) ;
}
void F_44 ( struct V_60 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_22 * V_23 = F_6 ( V_6 ) ;
int V_26 ;
T_2 V_65 ;
if ( ! V_6 -> V_66 )
V_6 -> V_66 = F_45 ( V_31 , V_6 ) ;
V_26 = F_46 ( V_6 , V_6 -> V_66 , V_6 -> V_67 , false ) ;
if ( V_26 ) {
F_10 ( V_23 ,
L_7 ,
V_26 , V_6 -> V_66 -> V_68 ) ;
}
F_47 ( V_6 , V_2 -> V_69 , V_2 -> V_70 ,
& V_2 -> V_69 ) ;
F_48 ( V_71 ) ;
F_49 ( V_2 ) ;
F_50 ( V_2 -> V_72 ) ;
F_51 ( & V_2 -> V_73 . V_74 ) ;
V_2 -> V_73 . V_75 &= ~ V_76 ;
F_52 ( & V_2 -> V_73 . V_74 ) ;
F_53 ( V_31 ) ;
F_48 ( V_77 ) ;
F_32 ( V_6 , V_6 -> V_41 ,
V_52 ) ;
F_22 ( V_6 , V_6 -> V_41 , 0 ) ;
}
void F_54 ( struct V_60 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_22 * V_23 = F_6 ( V_6 ) ;
int V_26 ;
T_2 V_65 ;
F_38 ( V_2 ) ;
F_22 ( V_6 , V_6 -> V_41 , 1 ) ;
F_55 ( V_6 , V_6 -> V_41 ) ;
F_48 ( V_78 ) ;
F_56 ( V_31 ) ;
F_57 ( V_2 ) ;
F_48 ( V_79 ) ;
F_48 ( V_80 ) ;
F_58 ( V_2 ) ;
F_59 ( V_6 ) ;
if ( ! V_6 -> V_66 )
V_6 -> V_66 = F_45 ( V_31 , V_6 ) ;
V_26 = F_46 ( V_6 , V_6 -> V_66 , V_6 -> V_67 , false ) ;
if ( V_26 ) {
F_10 ( V_23 ,
L_7 ,
V_26 , V_6 -> V_66 -> V_68 ) ;
}
F_60 ( V_6 ) ;
F_39 ( V_2 ) ;
F_61 ( V_2 , V_81 ) ;
}
