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
if ( V_2 -> V_25 . type == V_26 )
continue;
if ( V_2 -> V_25 . type != V_27 )
F_15 ( V_28 , & V_2 -> V_29 ) ;
if ( V_2 -> V_25 . type == V_30 ||
V_2 -> V_25 . type == V_31 ||
V_2 -> V_25 . type == V_32 )
F_16 (
V_2 , V_33 ) ;
if ( V_2 -> V_25 . type != V_27 ) {
F_17 ( V_2 -> V_34 ) ;
if ( V_23 &&
( V_2 -> V_25 . type == V_35 ) &&
V_2 -> V_7 . V_8 . V_36 )
F_1 ( V_2 ) ;
}
}
F_18 ( & V_4 -> V_24 ) ;
}
void F_19 ( struct V_3 * V_4 ,
bool V_37 )
{
struct V_1 * V_2 ;
F_12 ( & V_4 -> V_24 ) ;
F_13 (sdata, &local->interfaces, list) {
if ( V_2 -> V_25 . type == V_26 )
continue;
if ( V_2 -> V_25 . type != V_27 )
F_20 ( V_28 , & V_2 -> V_29 ) ;
if ( ! F_14 ( V_2 ) )
continue;
if ( V_37 &&
V_2 -> V_25 . type == V_35 ) {
if ( V_2 -> V_7 . V_8 . V_36 )
F_6 ( V_2 ) ;
}
if ( V_2 -> V_25 . type != V_27 ) {
F_21 ( V_2 -> V_34 ) ;
}
if ( V_2 -> V_25 . type == V_30 ||
V_2 -> V_25 . type == V_31 ||
V_2 -> V_25 . type == V_32 )
F_16 (
V_2 , V_33 ) ;
}
F_18 ( & V_4 -> V_24 ) ;
}
void F_22 ( struct V_38 * V_39 )
{
if ( V_39 -> V_40 )
return;
if ( V_39 -> V_41 ) {
if ( ! F_23 ( ! V_39 -> V_42 ) ) {
F_24 ( V_39 -> V_2 , V_39 -> V_42 ) ;
V_39 -> V_42 = NULL ;
}
} else {
F_25 ( & V_39 -> V_2 -> V_43 , ( unsigned long ) V_39 ,
V_39 -> V_44 , V_39 -> V_45 ,
V_39 -> V_46 , V_47 ) ;
}
V_39 -> V_40 = true ;
}
static void F_26 ( struct V_48 * V_49 )
{
struct V_3 * V_4 =
F_27 ( V_49 , struct V_3 , V_50 ) ;
struct V_38 * V_39 , * V_51 , * V_52 ;
F_12 ( & V_4 -> V_53 ) ;
if ( F_28 ( & V_4 -> V_54 ) )
goto V_55;
V_39 = F_29 ( & V_4 -> V_54 , struct V_38 ,
V_56 ) ;
if ( ! V_39 -> V_57 )
goto V_55;
V_39 -> V_58 = true ;
V_39 -> V_59 = V_4 -> V_60 ;
F_22 ( V_39 ) ;
F_30 (dep, tmp, &roc->dependents, list) {
F_22 ( V_51 ) ;
if ( V_51 -> V_61 > V_39 -> V_61 ) {
T_1 V_62 = V_51 -> V_61 ;
V_51 -> V_61 = V_62 - V_39 -> V_61 ;
V_39 -> V_61 = V_62 ;
F_31 ( & V_51 -> V_56 , & V_39 -> V_56 ) ;
}
}
V_55:
F_18 ( & V_4 -> V_53 ) ;
}
void F_32 ( struct V_63 * V_14 )
{
struct V_3 * V_4 = F_33 ( V_14 ) ;
V_4 -> V_60 = V_22 ;
F_34 ( V_4 ) ;
F_35 ( V_14 , & V_4 -> V_50 ) ;
}
void F_36 ( struct V_3 * V_4 )
{
struct V_38 * V_39 ;
F_37 ( & V_4 -> V_53 ) ;
if ( F_28 ( & V_4 -> V_54 ) ) {
F_38 ( V_4 ) ;
return;
}
V_39 = F_29 ( & V_4 -> V_54 , struct V_38 ,
V_56 ) ;
if ( F_39 ( V_39 -> V_57 ) )
return;
if ( V_4 -> V_64 -> V_65 ) {
int V_66 , V_61 = V_39 -> V_61 ;
if ( ! V_61 )
V_61 = 10 ;
V_66 = F_40 ( V_4 , V_39 -> V_44 ,
V_39 -> V_45 ,
V_61 ) ;
V_39 -> V_57 = true ;
if ( V_66 ) {
F_41 ( V_4 -> V_14 . V_67 ,
L_1 , V_66 ) ;
F_42 ( & V_4 -> V_14 ) ;
}
} else {
F_43 ( & V_4 -> V_14 , & V_39 -> V_49 ,
F_44 ( V_68 / 2 ) ) ;
}
}
void F_45 ( struct V_38 * V_39 )
{
struct V_38 * V_51 , * V_52 ;
if ( V_39 -> V_42 ) {
F_46 ( & V_39 -> V_2 -> V_43 ,
( unsigned long ) V_39 -> V_42 ,
V_39 -> V_42 -> V_69 , V_39 -> V_42 -> V_70 ,
false , V_47 ) ;
F_47 ( V_39 -> V_42 ) ;
}
if ( ! V_39 -> V_41 )
F_48 ( & V_39 -> V_2 -> V_43 ,
( unsigned long ) V_39 ,
V_39 -> V_44 , V_39 -> V_45 ,
V_47 ) ;
F_30 (dep, tmp, &roc->dependents, list)
F_45 ( V_51 ) ;
F_49 ( V_39 ) ;
}
void F_50 ( struct V_48 * V_49 )
{
struct V_38 * V_39 =
F_27 ( V_49 , struct V_38 , V_49 . V_49 ) ;
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_57 ;
F_12 ( & V_4 -> V_53 ) ;
if ( V_39 -> abort )
goto V_71;
if ( F_23 ( F_28 ( & V_4 -> V_54 ) ) )
goto V_55;
if ( F_23 ( V_39 != F_29 ( & V_4 -> V_54 ,
struct V_38 ,
V_56 ) ) )
goto V_55;
if ( ! V_39 -> V_57 ) {
struct V_38 * V_51 ;
F_51 ( V_4 ) ;
V_4 -> V_72 = V_39 -> V_44 ;
V_4 -> V_73 = V_39 -> V_45 ;
F_4 ( V_4 , 0 ) ;
F_22 ( V_39 ) ;
F_13 (dep, &roc->dependents, list)
F_22 ( V_51 ) ;
if ( ! V_39 -> V_61 )
goto V_71;
V_39 -> V_57 = true ;
F_43 ( & V_4 -> V_14 , & V_39 -> V_49 ,
F_8 ( V_39 -> V_61 ) ) ;
} else {
V_71:
F_52 ( & V_39 -> V_56 ) ;
V_57 = V_39 -> V_57 ;
F_45 ( V_39 ) ;
if ( V_57 ) {
F_53 ( V_4 , false ) ;
V_4 -> V_72 = NULL ;
F_4 ( V_4 , 0 ) ;
F_19 ( V_4 , true ) ;
}
F_51 ( V_4 ) ;
if ( V_57 )
F_36 ( V_4 ) ;
}
V_55:
F_18 ( & V_4 -> V_53 ) ;
}
static void F_54 ( struct V_48 * V_49 )
{
struct V_3 * V_4 =
F_27 ( V_49 , struct V_3 , V_74 ) ;
struct V_38 * V_39 ;
F_12 ( & V_4 -> V_53 ) ;
if ( F_28 ( & V_4 -> V_54 ) )
goto V_55;
V_39 = F_29 ( & V_4 -> V_54 , struct V_38 ,
V_56 ) ;
if ( ! V_39 -> V_57 )
goto V_55;
F_52 ( & V_39 -> V_56 ) ;
F_45 ( V_39 ) ;
F_36 ( V_4 ) ;
V_55:
F_18 ( & V_4 -> V_53 ) ;
}
void F_42 ( struct V_63 * V_14 )
{
struct V_3 * V_4 = F_33 ( V_14 ) ;
F_55 ( V_4 ) ;
F_35 ( V_14 , & V_4 -> V_74 ) ;
}
void F_56 ( struct V_3 * V_4 )
{
F_57 ( & V_4 -> V_50 , F_26 ) ;
F_57 ( & V_4 -> V_74 , F_54 ) ;
F_58 ( & V_4 -> V_54 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_38 * V_39 , * V_52 ;
F_60 ( V_75 ) ;
F_12 ( & V_4 -> V_53 ) ;
F_30 (roc, tmp, &local->roc_list, list) {
if ( V_39 -> V_2 != V_2 )
continue;
if ( V_39 -> V_57 && V_4 -> V_64 -> V_65 ) {
F_61 ( V_4 ) ;
}
F_62 ( & V_39 -> V_56 , & V_75 ) ;
V_39 -> abort = true ;
}
F_18 ( & V_4 -> V_53 ) ;
F_30 (roc, tmp, &tmp_list, list) {
if ( V_4 -> V_64 -> V_65 ) {
F_52 ( & V_39 -> V_56 ) ;
F_45 ( V_39 ) ;
} else {
F_43 ( & V_4 -> V_14 , & V_39 -> V_49 , 0 ) ;
F_63 ( & V_39 -> V_49 ) ;
}
}
F_39 ( ! F_28 ( & V_75 ) ) ;
}
