void F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
V_2 -> V_5 = F_2 ( V_4 ) ;
V_2 -> V_6 = F_3 ( V_4 ) ;
V_2 -> V_7 = F_4 ( V_4 ) ;
V_2 -> V_8 |= V_9 | V_10 ;
}
void F_5 ( struct V_1 * V_2 , struct V_11 * V_12 , T_1 V_13 )
{
T_1 V_14 = 0 ;
if ( V_13 & ( V_15 | V_16 ) )
F_6 ( V_17 , L_1 ,
V_13 , F_7 ( V_12 -> V_18 ) ,
F_7 ( V_12 -> V_19 ) ) ;
if ( V_13 & V_20 ) {
V_2 -> V_21 = F_7 ( V_12 -> V_22 ) ;
V_14 |= V_20 ;
}
if ( V_13 & V_16 ) {
V_2 -> V_23 = F_7 ( V_12 -> V_18 ) ;
V_14 |= V_16 ;
}
if ( V_13 & V_15 ) {
V_2 -> V_24 = F_7 ( V_12 -> V_19 ) ;
V_14 |= V_15 ;
}
if ( V_13 & V_25 ) {
V_2 -> V_26 = F_8 ( V_12 ) ;
V_14 |= V_25 ;
}
if ( V_13 & V_27 ) {
V_2 -> V_28 = V_12 -> V_29 ;
V_14 |= V_27 ;
}
if ( V_13 & V_30 ) {
V_2 -> V_31 = 1 << V_12 -> V_32 ;
V_14 |= V_30 ;
}
if ( V_13 & V_33 ) {
V_2 -> V_34 = ( V_2 -> V_34 & V_35 ) |
( V_12 -> V_36 & V_37 ) ;
V_14 |= V_33 ;
}
if ( V_13 & V_38 ) {
V_2 -> V_34 = ( V_2 -> V_34 & V_37 ) |
( V_12 -> V_36 & V_35 ) ;
V_14 |= V_38 ;
}
if ( V_13 & V_39 ) {
V_2 -> V_40 = F_9 ( & V_41 , V_12 -> V_42 ) ;
V_14 |= V_39 ;
}
if ( V_13 & V_43 ) {
V_2 -> V_44 = F_10 ( & V_41 , V_12 -> V_45 ) ;
V_14 |= V_43 ;
}
if ( V_13 & V_46 ) {
V_2 -> V_47 = V_12 -> V_48 ;
V_14 |= V_46 ;
}
V_2 -> V_8 |= V_14 ;
}
void F_11 ( const struct V_1 * V_49 , struct V_50 * V_51 )
{
V_51 -> V_52 = V_49 -> V_53 ;
if ( F_12 ( ! ( V_49 -> V_8 & V_54 ) ) )
F_13 ( & V_51 -> V_52 ) ;
V_51 -> V_55 = 0 ;
}
void F_14 ( const struct V_56 * V_57 ,
struct V_1 * V_58 , const struct V_1 * V_59 )
{
* V_58 = * V_59 ;
V_58 -> V_47 &= ~ V_60 ;
if ( ! V_57 )
return;
if ( F_12 ( ! ( V_57 -> V_61 & V_62 ) ) &&
F_15 ( F_16 ( & V_59 -> V_53 ) ) ) {
V_58 -> V_53 . V_63 . V_64 = F_2 ( & V_59 -> V_53 . V_65 ) ;
V_58 -> V_53 . V_63 . V_66 = F_3 ( & V_59 -> V_53 . V_65 ) ;
}
}
void F_17 ( const struct V_56 * V_57 ,
struct V_1 * V_59 , const struct V_1 * V_58 )
{
T_1 V_67 = 0 ;
if ( V_59 -> V_8 & V_46 )
V_67 = V_59 -> V_47 & V_60 ;
* V_59 = * V_58 ;
if ( V_67 ) {
V_59 -> V_8 |= V_46 ;
V_59 -> V_47 &= ~ V_60 ;
V_59 -> V_47 |= V_67 ;
}
if ( ! V_57 )
return;
if ( F_12 ( ! ( V_57 -> V_61 & V_62 ) ) &&
F_15 ( V_58 -> V_53 . V_63 . V_66 ) ) {
V_59 -> V_53 . V_65 . V_68 = V_58 -> V_53 . V_63 . V_66 ;
V_59 -> V_53 . V_65 . V_69 = V_58 -> V_53 . V_63 . V_64 ;
V_59 -> V_53 . V_65 . V_70 = 0 ;
}
}
