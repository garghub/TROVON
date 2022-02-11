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
void F_11 ( struct V_3 * V_4 ,
bool V_23 )
{
struct V_1 * V_2 ;
F_12 ( & V_4 -> V_24 ) ;
F_13 (sdata, &local->interfaces, list) {
if ( ! F_14 ( V_2 ) )
continue;
if ( V_2 -> V_25 . type != V_26 )
F_15 ( V_27 , & V_2 -> V_28 ) ;
if ( V_2 -> V_25 . type == V_29 ||
V_2 -> V_25 . type == V_30 ||
V_2 -> V_25 . type == V_31 )
F_16 (
V_2 , V_32 ) ;
if ( V_2 -> V_25 . type != V_26 ) {
F_17 ( V_2 -> V_33 ) ;
if ( V_23 &&
( V_2 -> V_25 . type == V_34 ) &&
V_2 -> V_7 . V_8 . V_35 )
F_1 ( V_2 ) ;
}
}
F_18 ( & V_4 -> V_24 ) ;
}
void F_19 ( struct V_3 * V_4 ,
bool V_36 )
{
struct V_1 * V_2 ;
F_12 ( & V_4 -> V_24 ) ;
F_13 (sdata, &local->interfaces, list) {
if ( V_2 -> V_25 . type != V_26 )
F_20 ( V_27 , & V_2 -> V_28 ) ;
if ( ! F_14 ( V_2 ) )
continue;
if ( V_36 &&
V_2 -> V_25 . type == V_34 ) {
if ( V_2 -> V_7 . V_8 . V_35 )
F_6 ( V_2 ) ;
}
if ( V_2 -> V_25 . type != V_26 ) {
F_21 ( V_2 -> V_33 ) ;
}
if ( V_2 -> V_25 . type == V_29 ||
V_2 -> V_25 . type == V_30 ||
V_2 -> V_25 . type == V_31 )
F_16 (
V_2 , V_32 ) ;
}
F_18 ( & V_4 -> V_24 ) ;
}
void F_22 ( struct V_37 * V_38 )
{
if ( V_38 -> V_39 )
return;
if ( V_38 -> V_40 ) {
if ( ! F_23 ( ! V_38 -> V_41 ) ) {
F_24 ( V_38 -> V_2 , V_38 -> V_41 ) ;
V_38 -> V_41 = NULL ;
}
} else {
F_25 ( & V_38 -> V_2 -> V_42 , ( unsigned long ) V_38 ,
V_38 -> V_43 , V_38 -> V_44 ,
V_38 -> V_45 , V_46 ) ;
}
V_38 -> V_39 = true ;
}
static void F_26 ( struct V_47 * V_48 )
{
struct V_3 * V_4 =
F_27 ( V_48 , struct V_3 , V_49 ) ;
struct V_37 * V_38 , * V_50 , * V_51 ;
F_12 ( & V_4 -> V_52 ) ;
if ( F_28 ( & V_4 -> V_53 ) )
goto V_54;
V_38 = F_29 ( & V_4 -> V_53 , struct V_37 ,
V_55 ) ;
if ( ! V_38 -> V_56 )
goto V_54;
V_38 -> V_57 = true ;
V_38 -> V_58 = V_4 -> V_59 ;
F_22 ( V_38 ) ;
F_30 (dep, tmp, &roc->dependents, list) {
F_22 ( V_50 ) ;
if ( V_50 -> V_60 > V_38 -> V_60 ) {
T_1 V_61 = V_50 -> V_60 ;
V_50 -> V_60 = V_61 - V_38 -> V_60 ;
V_38 -> V_60 = V_61 ;
F_31 ( & V_50 -> V_55 ) ;
F_32 ( & V_50 -> V_55 , & V_38 -> V_55 ) ;
}
}
V_54:
F_18 ( & V_4 -> V_52 ) ;
}
void F_33 ( struct V_62 * V_14 )
{
struct V_3 * V_4 = F_34 ( V_14 ) ;
V_4 -> V_59 = V_22 ;
F_35 ( V_4 ) ;
F_36 ( V_14 , & V_4 -> V_49 ) ;
}
void F_37 ( struct V_3 * V_4 )
{
struct V_37 * V_38 ;
F_38 ( & V_4 -> V_52 ) ;
if ( F_28 ( & V_4 -> V_53 ) ) {
F_39 ( V_4 ) ;
return;
}
V_38 = F_29 ( & V_4 -> V_53 , struct V_37 ,
V_55 ) ;
if ( F_40 ( V_38 -> V_56 ) )
return;
if ( V_4 -> V_63 -> V_64 ) {
int V_65 , V_60 = V_38 -> V_60 ;
if ( ! V_60 )
V_60 = 10 ;
V_65 = F_41 ( V_4 , V_38 -> V_43 ,
V_38 -> V_44 ,
V_60 ) ;
V_38 -> V_56 = true ;
if ( V_65 ) {
F_42 ( V_4 -> V_14 . V_66 ,
L_1 , V_65 ) ;
F_43 ( & V_4 -> V_14 ) ;
}
} else {
F_44 ( & V_4 -> V_14 , & V_38 -> V_48 ,
F_45 ( V_67 / 2 ) ) ;
}
}
void F_46 ( struct V_37 * V_38 )
{
struct V_37 * V_50 , * V_51 ;
if ( V_38 -> V_41 ) {
F_47 ( & V_38 -> V_2 -> V_42 ,
( unsigned long ) V_38 -> V_41 ,
V_38 -> V_41 -> V_68 , V_38 -> V_41 -> V_69 ,
false , V_46 ) ;
F_48 ( V_38 -> V_41 ) ;
}
if ( ! V_38 -> V_40 )
F_49 ( & V_38 -> V_2 -> V_42 ,
( unsigned long ) V_38 ,
V_38 -> V_43 , V_38 -> V_44 ,
V_46 ) ;
F_30 (dep, tmp, &roc->dependents, list)
F_46 ( V_50 ) ;
F_50 ( V_38 ) ;
}
void F_51 ( struct V_47 * V_48 )
{
struct V_37 * V_38 =
F_27 ( V_48 , struct V_37 , V_48 . V_48 ) ;
struct V_1 * V_2 = V_38 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_56 ;
F_12 ( & V_4 -> V_52 ) ;
if ( V_38 -> abort )
goto V_70;
if ( F_23 ( F_28 ( & V_4 -> V_53 ) ) )
goto V_54;
if ( F_23 ( V_38 != F_29 ( & V_4 -> V_53 ,
struct V_37 ,
V_55 ) ) )
goto V_54;
if ( ! V_38 -> V_56 ) {
struct V_37 * V_50 ;
F_52 ( V_4 ) ;
V_4 -> V_71 = V_38 -> V_43 ;
V_4 -> V_72 = V_38 -> V_44 ;
F_4 ( V_4 , 0 ) ;
F_22 ( V_38 ) ;
F_13 (dep, &roc->dependents, list)
F_22 ( V_50 ) ;
if ( ! V_38 -> V_60 )
goto V_70;
V_38 -> V_56 = true ;
F_44 ( & V_4 -> V_14 , & V_38 -> V_48 ,
F_8 ( V_38 -> V_60 ) ) ;
} else {
V_70:
F_31 ( & V_38 -> V_55 ) ;
V_56 = V_38 -> V_56 ;
F_46 ( V_38 ) ;
if ( V_56 ) {
F_53 ( V_4 , false ) ;
V_4 -> V_71 = NULL ;
F_4 ( V_4 , 0 ) ;
F_19 ( V_4 , true ) ;
}
F_52 ( V_4 ) ;
if ( V_56 )
F_37 ( V_4 ) ;
}
V_54:
F_18 ( & V_4 -> V_52 ) ;
}
static void F_54 ( struct V_47 * V_48 )
{
struct V_3 * V_4 =
F_27 ( V_48 , struct V_3 , V_73 ) ;
struct V_37 * V_38 ;
F_12 ( & V_4 -> V_52 ) ;
if ( F_28 ( & V_4 -> V_53 ) )
goto V_54;
V_38 = F_29 ( & V_4 -> V_53 , struct V_37 ,
V_55 ) ;
if ( ! V_38 -> V_56 )
goto V_54;
F_31 ( & V_38 -> V_55 ) ;
F_46 ( V_38 ) ;
F_37 ( V_4 ) ;
V_54:
F_18 ( & V_4 -> V_52 ) ;
}
void F_43 ( struct V_62 * V_14 )
{
struct V_3 * V_4 = F_34 ( V_14 ) ;
F_55 ( V_4 ) ;
F_36 ( V_14 , & V_4 -> V_73 ) ;
}
void F_56 ( struct V_3 * V_4 )
{
F_57 ( & V_4 -> V_49 , F_26 ) ;
F_57 ( & V_4 -> V_73 , F_54 ) ;
F_58 ( & V_4 -> V_53 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_37 * V_38 , * V_51 ;
F_60 ( V_74 ) ;
F_12 ( & V_4 -> V_52 ) ;
F_30 (roc, tmp, &local->roc_list, list) {
if ( V_38 -> V_2 != V_2 )
continue;
if ( V_38 -> V_56 && V_4 -> V_63 -> V_64 ) {
F_61 ( V_4 ) ;
}
F_62 ( & V_38 -> V_55 , & V_74 ) ;
V_38 -> abort = true ;
}
F_37 ( V_4 ) ;
F_18 ( & V_4 -> V_52 ) ;
F_30 (roc, tmp, &tmp_list, list) {
if ( V_4 -> V_63 -> V_64 ) {
F_31 ( & V_38 -> V_55 ) ;
F_46 ( V_38 ) ;
} else {
F_44 ( & V_4 -> V_14 , & V_38 -> V_48 , 0 ) ;
F_63 ( & V_38 -> V_48 ) ;
}
}
F_40 ( ! F_28 ( & V_74 ) ) ;
}
