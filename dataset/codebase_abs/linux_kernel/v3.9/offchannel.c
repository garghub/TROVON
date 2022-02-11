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
! ( V_4 -> V_14 . V_16 & V_19 ) )
F_5 ( V_4 , V_2 , 1 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! V_4 -> V_20 )
F_5 ( V_4 , V_2 , 0 ) ;
else if ( V_4 -> V_9 ) {
V_4 -> V_14 . V_15 . V_16 |= V_17 ;
F_4 ( V_4 , V_18 ) ;
} else if ( V_4 -> V_14 . V_15 . V_21 > 0 ) {
F_5 ( V_4 , V_2 , 0 ) ;
F_7 ( & V_4 -> V_10 , V_22 +
F_8 ( V_4 -> V_14 . V_15 . V_21 ) ) ;
}
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
}
void F_11 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
if ( F_12 ( V_4 -> V_23 ) )
return;
F_13 ( & V_4 -> V_14 ,
V_24 ) ;
F_14 ( V_4 , false ) ;
F_15 ( & V_4 -> V_25 ) ;
F_16 (sdata, &local->interfaces, list) {
if ( ! F_17 ( V_2 ) )
continue;
if ( V_2 -> V_26 . type == V_27 )
continue;
if ( V_2 -> V_26 . type != V_28 )
F_18 ( V_29 , & V_2 -> V_30 ) ;
if ( V_2 -> V_26 . V_31 . V_32 ) {
F_18 ( V_33 ,
& V_2 -> V_30 ) ;
V_2 -> V_26 . V_31 . V_32 = false ;
F_19 (
V_2 , V_34 ) ;
}
if ( V_2 -> V_26 . type == V_35 &&
V_2 -> V_7 . V_8 . V_36 )
F_1 ( V_2 ) ;
}
F_20 ( & V_4 -> V_25 ) ;
}
void F_21 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
if ( F_12 ( V_4 -> V_23 ) )
return;
F_15 ( & V_4 -> V_25 ) ;
F_16 (sdata, &local->interfaces, list) {
if ( V_2 -> V_26 . type == V_27 )
continue;
if ( V_2 -> V_26 . type != V_28 )
F_22 ( V_29 , & V_2 -> V_30 ) ;
if ( ! F_17 ( V_2 ) )
continue;
if ( V_2 -> V_26 . type == V_35 &&
V_2 -> V_7 . V_8 . V_36 )
F_6 ( V_2 ) ;
if ( F_23 ( V_33 ,
& V_2 -> V_30 ) ) {
V_2 -> V_26 . V_31 . V_32 = true ;
F_19 (
V_2 , V_34 ) ;
}
}
F_20 ( & V_4 -> V_25 ) ;
F_24 ( & V_4 -> V_14 ,
V_24 ) ;
}
void F_25 ( struct V_37 * V_38 )
{
if ( V_38 -> V_39 )
return;
if ( V_38 -> V_40 ) {
if ( ! F_12 ( ! V_38 -> V_41 ) ) {
F_26 ( V_38 -> V_2 , V_38 -> V_41 , 7 ,
V_38 -> V_42 -> V_43 ) ;
V_38 -> V_41 = NULL ;
}
} else {
F_27 ( & V_38 -> V_2 -> V_44 , V_38 -> V_45 ,
V_38 -> V_42 , V_38 -> V_46 ,
V_47 ) ;
}
V_38 -> V_39 = true ;
}
static void F_28 ( struct V_48 * V_49 )
{
struct V_3 * V_4 =
F_29 ( V_49 , struct V_3 , V_50 ) ;
struct V_37 * V_38 , * V_51 , * V_52 ;
F_15 ( & V_4 -> V_53 ) ;
if ( F_30 ( & V_4 -> V_54 ) )
goto V_55;
V_38 = F_31 ( & V_4 -> V_54 , struct V_37 ,
V_56 ) ;
if ( ! V_38 -> V_57 )
goto V_55;
V_38 -> V_58 = true ;
V_38 -> V_59 = V_4 -> V_60 ;
F_25 ( V_38 ) ;
F_32 (dep, tmp, &roc->dependents, list) {
F_25 ( V_51 ) ;
if ( V_51 -> V_61 > V_38 -> V_61 ) {
T_1 V_62 = V_51 -> V_61 ;
V_51 -> V_61 = V_62 - V_38 -> V_61 ;
V_38 -> V_61 = V_62 ;
F_33 ( & V_51 -> V_56 , & V_38 -> V_56 ) ;
}
}
V_55:
F_20 ( & V_4 -> V_53 ) ;
}
void F_34 ( struct V_63 * V_14 )
{
struct V_3 * V_4 = F_35 ( V_14 ) ;
V_4 -> V_60 = V_22 ;
F_36 ( V_4 ) ;
F_37 ( V_14 , & V_4 -> V_50 ) ;
}
void F_38 ( struct V_3 * V_4 )
{
struct V_37 * V_38 ;
F_39 ( & V_4 -> V_53 ) ;
if ( F_30 ( & V_4 -> V_54 ) ) {
F_40 ( V_4 ) ;
return;
}
V_38 = F_31 ( & V_4 -> V_54 , struct V_37 ,
V_56 ) ;
if ( F_41 ( V_38 -> V_57 ) )
return;
if ( V_4 -> V_64 -> V_65 ) {
int V_66 , V_61 = V_38 -> V_61 ;
if ( ! V_61 )
V_61 = 10 ;
V_66 = F_42 ( V_4 , V_38 -> V_2 , V_38 -> V_42 ,
V_61 ) ;
V_38 -> V_57 = true ;
if ( V_66 ) {
F_43 ( V_4 -> V_14 . V_67 ,
L_1 , V_66 ) ;
F_44 ( & V_4 -> V_14 ) ;
}
} else {
F_45 ( & V_4 -> V_14 , & V_38 -> V_49 ,
F_46 ( V_68 / 2 ) ) ;
}
}
void F_47 ( struct V_37 * V_38 , bool free )
{
struct V_37 * V_51 , * V_52 ;
if ( F_12 ( V_38 -> V_69 ) )
return;
if ( V_38 -> V_41 ) {
F_48 ( & V_38 -> V_2 -> V_44 ,
( unsigned long ) V_38 -> V_41 ,
V_38 -> V_41 -> V_70 , V_38 -> V_41 -> V_71 ,
false , V_47 ) ;
F_49 ( V_38 -> V_41 ) ;
}
if ( ! V_38 -> V_40 )
F_50 ( & V_38 -> V_2 -> V_44 ,
V_38 -> V_45 , V_38 -> V_42 ,
V_47 ) ;
F_32 (dep, tmp, &roc->dependents, list)
F_47 ( V_51 , true ) ;
if ( free )
F_51 ( V_38 ) ;
else
V_38 -> V_69 = true ;
}
void F_52 ( struct V_48 * V_49 )
{
struct V_37 * V_38 =
F_29 ( V_49 , struct V_37 , V_49 . V_49 ) ;
struct V_1 * V_2 = V_38 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_57 ;
F_15 ( & V_4 -> V_53 ) ;
if ( V_38 -> V_69 )
goto V_55;
if ( V_38 -> abort )
goto V_72;
if ( F_12 ( F_30 ( & V_4 -> V_54 ) ) )
goto V_55;
if ( F_12 ( V_38 != F_31 ( & V_4 -> V_54 ,
struct V_37 ,
V_56 ) ) )
goto V_55;
if ( ! V_38 -> V_57 ) {
struct V_37 * V_51 ;
F_53 ( V_4 ) ;
V_4 -> V_73 = V_38 -> V_42 ;
F_4 ( V_4 , 0 ) ;
F_25 ( V_38 ) ;
F_16 (dep, &roc->dependents, list)
F_25 ( V_51 ) ;
if ( ! V_38 -> V_61 )
goto V_72;
V_38 -> V_57 = true ;
F_45 ( & V_4 -> V_14 , & V_38 -> V_49 ,
F_8 ( V_38 -> V_61 ) ) ;
} else {
V_72:
F_54 ( & V_38 -> V_56 ) ;
V_57 = V_38 -> V_57 ;
F_47 ( V_38 , ! V_38 -> abort ) ;
if ( V_57 ) {
F_14 ( V_4 , false ) ;
V_4 -> V_73 = NULL ;
F_4 ( V_4 , 0 ) ;
F_21 ( V_4 ) ;
}
F_53 ( V_4 ) ;
if ( V_57 )
F_38 ( V_4 ) ;
}
V_55:
F_20 ( & V_4 -> V_53 ) ;
}
static void F_55 ( struct V_48 * V_49 )
{
struct V_3 * V_4 =
F_29 ( V_49 , struct V_3 , V_74 ) ;
struct V_37 * V_38 ;
F_15 ( & V_4 -> V_53 ) ;
if ( F_30 ( & V_4 -> V_54 ) )
goto V_55;
V_38 = F_31 ( & V_4 -> V_54 , struct V_37 ,
V_56 ) ;
if ( ! V_38 -> V_57 )
goto V_55;
F_54 ( & V_38 -> V_56 ) ;
F_47 ( V_38 , true ) ;
F_38 ( V_4 ) ;
V_55:
F_20 ( & V_4 -> V_53 ) ;
}
void F_44 ( struct V_63 * V_14 )
{
struct V_3 * V_4 = F_35 ( V_14 ) ;
F_56 ( V_4 ) ;
F_37 ( V_14 , & V_4 -> V_74 ) ;
}
void F_57 ( struct V_3 * V_4 )
{
F_58 ( & V_4 -> V_50 , F_28 ) ;
F_58 ( & V_4 -> V_74 , F_55 ) ;
F_59 ( & V_4 -> V_54 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_37 * V_38 , * V_52 ;
F_61 ( V_75 ) ;
F_15 ( & V_4 -> V_53 ) ;
F_32 (roc, tmp, &local->roc_list, list) {
if ( V_38 -> V_2 != V_2 )
continue;
if ( V_38 -> V_57 && V_4 -> V_64 -> V_65 ) {
F_62 ( V_4 ) ;
}
F_63 ( & V_38 -> V_56 , & V_75 ) ;
V_38 -> abort = true ;
}
F_20 ( & V_4 -> V_53 ) ;
F_32 (roc, tmp, &tmp_list, list) {
if ( V_4 -> V_64 -> V_65 ) {
F_54 ( & V_38 -> V_56 ) ;
F_47 ( V_38 , true ) ;
} else {
F_45 ( & V_4 -> V_14 , & V_38 -> V_49 , 0 ) ;
F_64 ( & V_38 -> V_49 ) ;
F_12 ( ! V_38 -> V_69 ) ;
F_51 ( V_38 ) ;
}
}
F_41 ( ! F_30 ( & V_75 ) ) ;
}
