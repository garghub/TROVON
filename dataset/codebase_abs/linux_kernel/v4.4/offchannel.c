static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_2 -> V_7 . V_8 ;
V_4 -> V_9 = false ;
F_2 ( & V_4 -> V_10 ) ;
F_2 ( & V_6 -> V_11 ) ;
F_2 ( & V_6 -> V_12 ) ;
F_3 ( & V_4 -> V_13 ) ;
if ( V_4 -> V_14 . V_15 . V_16 & V_17 ) {
V_4 -> V_9 = true ;
V_4 -> V_14 . V_15 . V_16 &= ~ V_17 ;
F_4 ( V_4 , V_18 ) ;
}
if ( ! V_4 -> V_9 ||
! F_5 ( & V_4 -> V_14 , V_19 ) )
F_6 ( V_4 , V_2 , true ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! V_4 -> V_20 )
F_6 ( V_4 , V_2 , false ) ;
else if ( V_4 -> V_9 ) {
V_4 -> V_14 . V_15 . V_16 |= V_17 ;
F_4 ( V_4 , V_18 ) ;
} else if ( V_4 -> V_14 . V_15 . V_21 > 0 ) {
F_6 ( V_4 , V_2 , false ) ;
F_8 ( & V_4 -> V_10 , V_22 +
F_9 ( V_4 -> V_14 . V_15 . V_21 ) ) ;
}
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
}
void F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
if ( F_13 ( V_4 -> V_23 ) )
return;
F_14 ( & V_4 -> V_14 , V_24 ,
V_25 ,
false ) ;
F_15 ( V_4 , NULL , false ) ;
F_16 ( & V_4 -> V_26 ) ;
F_17 (sdata, &local->interfaces, list) {
if ( ! F_18 ( V_2 ) )
continue;
if ( V_2 -> V_27 . type == V_28 )
continue;
if ( V_2 -> V_27 . type != V_29 )
F_19 ( V_30 , & V_2 -> V_31 ) ;
if ( V_2 -> V_27 . V_32 . V_33 ) {
F_19 ( V_34 ,
& V_2 -> V_31 ) ;
V_2 -> V_27 . V_32 . V_33 = false ;
F_20 (
V_2 , V_35 ) ;
}
if ( V_2 -> V_27 . type == V_36 &&
V_2 -> V_7 . V_8 . V_37 )
F_1 ( V_2 ) ;
}
F_21 ( & V_4 -> V_26 ) ;
}
void F_22 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
if ( F_13 ( V_4 -> V_23 ) )
return;
F_16 ( & V_4 -> V_26 ) ;
F_17 (sdata, &local->interfaces, list) {
if ( V_2 -> V_27 . type == V_28 )
continue;
if ( V_2 -> V_27 . type != V_29 )
F_23 ( V_30 , & V_2 -> V_31 ) ;
if ( ! F_18 ( V_2 ) )
continue;
if ( V_2 -> V_27 . type == V_36 &&
V_2 -> V_7 . V_8 . V_37 )
F_7 ( V_2 ) ;
if ( F_24 ( V_34 ,
& V_2 -> V_31 ) ) {
V_2 -> V_27 . V_32 . V_33 = true ;
F_20 (
V_2 , V_35 ) ;
}
}
F_21 ( & V_4 -> V_26 ) ;
F_25 ( & V_4 -> V_14 , V_24 ,
V_25 ,
false ) ;
}
void F_26 ( struct V_38 * V_39 )
{
if ( V_39 -> V_40 )
return;
if ( V_39 -> V_41 ) {
if ( ! F_13 ( ! V_39 -> V_42 ) ) {
F_27 ( V_39 -> V_2 , V_39 -> V_42 , 7 ,
V_39 -> V_43 -> V_44 ) ;
V_39 -> V_42 = NULL ;
}
} else {
F_28 ( & V_39 -> V_2 -> V_45 , V_39 -> V_46 ,
V_39 -> V_43 , V_39 -> V_47 ,
V_48 ) ;
}
V_39 -> V_40 = true ;
}
static void F_29 ( struct V_49 * V_50 )
{
struct V_3 * V_4 =
F_30 ( V_50 , struct V_3 , V_51 ) ;
struct V_38 * V_39 , * V_52 , * V_53 ;
F_16 ( & V_4 -> V_54 ) ;
if ( F_31 ( & V_4 -> V_55 ) )
goto V_56;
V_39 = F_32 ( & V_4 -> V_55 , struct V_38 ,
V_57 ) ;
if ( ! V_39 -> V_58 )
goto V_56;
V_39 -> V_59 = true ;
V_39 -> V_60 = V_4 -> V_61 ;
F_26 ( V_39 ) ;
F_33 (dep, tmp, &roc->dependents, list) {
F_26 ( V_52 ) ;
if ( V_52 -> V_62 > V_39 -> V_62 ) {
T_1 V_63 = V_52 -> V_62 ;
V_52 -> V_62 = V_63 - V_39 -> V_62 ;
V_39 -> V_62 = V_63 ;
F_34 ( & V_52 -> V_57 , & V_39 -> V_57 ) ;
}
}
V_56:
F_21 ( & V_4 -> V_54 ) ;
}
void F_35 ( struct V_64 * V_14 )
{
struct V_3 * V_4 = F_36 ( V_14 ) ;
V_4 -> V_61 = V_22 ;
F_37 ( V_4 ) ;
F_38 ( V_14 , & V_4 -> V_51 ) ;
}
void F_39 ( struct V_3 * V_4 )
{
struct V_38 * V_39 ;
F_40 ( & V_4 -> V_54 ) ;
if ( F_31 ( & V_4 -> V_55 ) ) {
F_41 ( V_4 ) ;
return;
}
V_39 = F_32 ( & V_4 -> V_55 , struct V_38 ,
V_57 ) ;
if ( F_42 ( V_39 -> V_58 ) )
return;
if ( V_4 -> V_65 -> V_66 ) {
int V_67 , V_62 = V_39 -> V_62 ;
if ( ! V_62 )
V_62 = 10 ;
V_67 = F_43 ( V_4 , V_39 -> V_2 , V_39 -> V_43 ,
V_62 , V_39 -> type ) ;
V_39 -> V_58 = true ;
if ( V_67 ) {
F_44 ( V_4 -> V_14 . V_68 ,
L_1 , V_67 ) ;
F_45 ( & V_4 -> V_14 ) ;
}
} else {
F_46 ( & V_4 -> V_14 , & V_39 -> V_50 ,
F_47 ( V_69 / 2 ) ) ;
}
}
void F_48 ( struct V_38 * V_39 , bool free )
{
struct V_38 * V_52 , * V_53 ;
if ( F_13 ( V_39 -> V_70 ) )
return;
if ( V_39 -> V_42 ) {
F_49 ( & V_39 -> V_2 -> V_45 ,
( unsigned long ) V_39 -> V_42 ,
V_39 -> V_42 -> V_71 , V_39 -> V_42 -> V_72 ,
false , V_48 ) ;
F_50 ( V_39 -> V_42 ) ;
}
if ( ! V_39 -> V_41 )
F_51 ( & V_39 -> V_2 -> V_45 ,
V_39 -> V_46 , V_39 -> V_43 ,
V_48 ) ;
F_33 (dep, tmp, &roc->dependents, list)
F_48 ( V_52 , true ) ;
if ( free )
F_52 ( V_39 ) ;
else
V_39 -> V_70 = true ;
}
void F_53 ( struct V_49 * V_50 )
{
struct V_38 * V_39 =
F_30 ( V_50 , struct V_38 , V_50 . V_50 ) ;
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_58 , V_73 ;
F_16 ( & V_4 -> V_54 ) ;
if ( V_39 -> V_70 )
goto V_56;
if ( V_39 -> abort )
goto V_74;
if ( F_13 ( F_31 ( & V_4 -> V_55 ) ) )
goto V_56;
if ( F_13 ( V_39 != F_32 ( & V_4 -> V_55 ,
struct V_38 ,
V_57 ) ) )
goto V_56;
if ( ! V_39 -> V_58 ) {
struct V_38 * V_52 ;
F_13 ( V_4 -> V_23 ) ;
V_39 -> V_73 = V_39 -> V_43 == V_4 -> V_75 . V_43 &&
V_4 -> V_75 . V_76 != V_77 &&
V_4 -> V_75 . V_76 != V_78 ;
F_54 ( V_4 ) ;
if ( ! V_39 -> V_73 ) {
F_12 ( V_4 ) ;
V_4 -> V_79 = V_39 -> V_43 ;
F_4 ( V_4 , 0 ) ;
}
F_26 ( V_39 ) ;
F_17 (dep, &roc->dependents, list)
F_26 ( V_52 ) ;
if ( ! V_39 -> V_62 )
goto V_74;
V_39 -> V_58 = true ;
F_46 ( & V_4 -> V_14 , & V_39 -> V_50 ,
F_9 ( V_39 -> V_62 ) ) ;
} else {
V_74:
F_55 ( & V_39 -> V_57 ) ;
V_58 = V_39 -> V_58 ;
V_73 = V_39 -> V_73 ;
F_48 ( V_39 , ! V_39 -> abort ) ;
if ( V_58 && ! V_73 ) {
F_15 ( V_4 , NULL , false ) ;
V_4 -> V_79 = NULL ;
F_4 ( V_4 , 0 ) ;
F_22 ( V_4 ) ;
}
F_54 ( V_4 ) ;
if ( V_58 )
F_39 ( V_4 ) ;
else if ( F_31 ( & V_4 -> V_55 ) )
F_41 ( V_4 ) ;
}
V_56:
F_21 ( & V_4 -> V_54 ) ;
}
static void F_56 ( struct V_49 * V_50 )
{
struct V_3 * V_4 =
F_30 ( V_50 , struct V_3 , V_80 ) ;
struct V_38 * V_39 ;
F_16 ( & V_4 -> V_54 ) ;
if ( F_31 ( & V_4 -> V_55 ) )
goto V_56;
V_39 = F_32 ( & V_4 -> V_55 , struct V_38 ,
V_57 ) ;
if ( ! V_39 -> V_58 )
goto V_56;
F_55 ( & V_39 -> V_57 ) ;
F_48 ( V_39 , true ) ;
F_39 ( V_4 ) ;
V_56:
F_21 ( & V_4 -> V_54 ) ;
}
void F_45 ( struct V_64 * V_14 )
{
struct V_3 * V_4 = F_36 ( V_14 ) ;
F_57 ( V_4 ) ;
F_38 ( V_14 , & V_4 -> V_80 ) ;
}
void F_58 ( struct V_3 * V_4 )
{
F_59 ( & V_4 -> V_51 , F_29 ) ;
F_59 ( & V_4 -> V_80 , F_56 ) ;
F_60 ( & V_4 -> V_55 ) ;
}
void F_61 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_38 * V_39 , * V_53 ;
F_62 ( V_81 ) ;
F_16 ( & V_4 -> V_54 ) ;
F_33 (roc, tmp, &local->roc_list, list) {
if ( V_2 && V_39 -> V_2 != V_2 )
continue;
if ( V_39 -> V_58 && V_4 -> V_65 -> V_66 ) {
F_63 ( V_4 ) ;
}
F_64 ( & V_39 -> V_57 , & V_81 ) ;
V_39 -> abort = true ;
}
F_21 ( & V_4 -> V_54 ) ;
F_33 (roc, tmp, &tmp_list, list) {
if ( V_4 -> V_65 -> V_66 ) {
F_55 ( & V_39 -> V_57 ) ;
F_48 ( V_39 , true ) ;
} else {
F_46 ( & V_4 -> V_14 , & V_39 -> V_50 , 0 ) ;
F_65 ( & V_39 -> V_50 ) ;
F_13 ( ! V_39 -> V_70 ) ;
F_52 ( V_39 ) ;
}
}
F_42 ( ! F_31 ( & V_81 ) ) ;
}
