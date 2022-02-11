static void F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_2 * * V_4 , struct V_2 * * V_5 )
{
struct V_6 * V_7 , * V_8 ;
F_2 ( F_3 ( & V_1 -> V_9 ) ) ;
V_7 = V_3 -> V_10 . V_4 ;
if ( V_7 == & V_1 -> V_9 )
V_7 = V_7 -> V_4 ;
V_8 = V_3 -> V_10 . V_5 ;
if ( V_8 == & V_1 -> V_9 )
V_8 = V_8 -> V_5 ;
* V_4 = F_4 ( V_7 , struct V_2 , V_10 ) ;
* V_5 = F_4 ( V_8 , struct V_2 , V_10 ) ;
}
static void F_5 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
F_6 ( & V_3 -> V_10 , & V_1 -> V_9 ) ;
V_3 -> V_11 = true ;
}
static void F_7 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_2 * V_4 , * V_5 ;
F_8 ( V_1 , V_3 ) ;
F_1 ( V_1 , V_3 , & V_4 , & V_5 ) ;
F_9 ( & V_3 -> V_12 . V_13 , V_4 -> V_14 ) ;
F_9 ( & V_5 -> V_12 . V_13 , V_3 -> V_14 ) ;
V_3 -> V_15 = true ;
}
static void F_10 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_2 * V_5 , * V_4 ;
F_1 ( V_1 , V_3 , & V_4 , & V_5 ) ;
F_6 ( & V_3 -> V_10 , & V_1 -> V_16 ) ;
V_3 -> V_11 = false ;
if ( F_3 ( & V_1 -> V_9 ) )
return;
F_9 ( & V_5 -> V_12 . V_13 , V_4 -> V_14 ) ;
V_3 -> V_15 = false ;
}
static T_1 F_11 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
enum V_17 V_18 = 0 ;
T_1 V_19 = 0 ;
while ( V_3 -> V_20 ) {
struct V_21 * V_22 ;
int V_23 ;
V_23 = V_3 -> V_24 ;
V_22 = & V_3 -> V_25 [ V_3 -> V_24 ] ;
V_19 = F_12 ( V_22 -> V_19 ) ;
if ( V_19 & V_26 )
break;
if ( V_19 & V_27 ) {
F_13 ( V_1 , V_3 , V_22 ) ;
V_18 |= V_28 ;
goto V_29;
}
F_14 ( V_1 , V_3 , V_22 ) ;
}
if ( ! V_3 -> remove )
V_18 |= F_15 ( V_1 , V_3 ) ;
V_29:
if ( V_3 -> remove && V_3 -> V_20 == 0 ) {
F_10 ( V_1 , V_3 ) ;
V_18 |= V_30 ;
}
return V_18 ;
}
void F_16 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = F_17 ( & V_1 -> V_9 , struct V_2 , V_10 ) ;
F_18 ( V_3 -> V_14 | F_19 ( 8 ) , V_1 -> V_31 + V_32 ) ;
F_20 ( V_1 , V_33 , V_33 ) ;
F_21 ( & V_1 -> V_34 -> V_35 , V_1 -> V_31 + V_36 ,
V_37 , V_37 ,
1000 , L_1 ) ;
}
void F_22 ( struct V_1 * V_1 )
{
F_20 ( V_1 , V_33 , 0 ) ;
F_21 ( & V_1 -> V_34 -> V_35 , V_1 -> V_31 + V_36 ,
V_37 , 0 ,
1000 , L_2 ) ;
}
void F_23 ( struct V_1 * V_1 , T_1 V_38 )
{
struct V_39 * V_39 = & V_1 -> V_39 ;
long V_23 ;
F_24 ( & V_39 -> V_40 ) ;
if ( V_39 -> V_41 ) {
F_20 ( V_1 , V_38 , V_38 ) ;
V_23 = F_25 (
V_1 -> V_42 ,
( F_26 ( V_1 -> V_31 + V_43 ) & V_44 ) == 0 ,
F_27 ( 1000 ) ) ;
if ( V_23 == 0 )
F_28 ( V_1 , L_3 ) ;
}
F_29 ( & V_39 -> V_40 ) ;
}
void F_30 ( struct V_45 * V_46 )
{
struct V_1 * V_1 = F_4 ( V_46 , struct V_1 , V_47 ) ;
struct V_2 * V_3 , * V_23 ;
enum V_17 V_18 = 0 ;
F_31 ( & V_1 -> V_48 ) ;
F_32 (qset, t, &whc->async_list, list_node) {
if ( ! V_3 -> V_15 ) {
F_7 ( V_1 , V_3 ) ;
V_18 |= V_49 ;
}
V_18 |= F_11 ( V_1 , V_3 ) ;
}
F_33 ( & V_1 -> V_48 ) ;
if ( V_18 ) {
T_1 V_38 = V_44 | V_50 ;
if ( V_18 & V_30 )
V_38 |= V_51 ;
F_23 ( V_1 , V_38 ) ;
}
F_31 ( & V_1 -> V_48 ) ;
F_34 (qset, t, &whc->async_removed_list, list_node) {
F_35 ( V_1 , V_3 ) ;
if ( V_3 -> V_52 ) {
F_36 ( V_1 , V_3 ) ;
if ( ! F_3 ( & V_3 -> V_53 ) ) {
F_5 ( V_1 , V_3 ) ;
F_37 ( V_1 -> V_54 , & V_1 -> V_47 ) ;
}
}
}
F_33 ( & V_1 -> V_48 ) ;
}
int F_38 ( struct V_1 * V_1 , struct V_55 * V_55 , T_2 V_56 )
{
struct V_2 * V_3 ;
int V_57 ;
unsigned long V_58 ;
F_39 ( & V_1 -> V_48 , V_58 ) ;
V_57 = F_40 ( & V_1 -> V_39 . V_59 , V_55 ) ;
if ( V_57 < 0 ) {
F_41 ( & V_1 -> V_48 , V_58 ) ;
return V_57 ;
}
V_3 = F_42 ( V_1 , V_55 , V_60 ) ;
if ( V_3 == NULL )
V_57 = - V_61 ;
else
V_57 = F_43 ( V_1 , V_3 , V_55 , V_60 ) ;
if ( ! V_57 ) {
if ( ! V_3 -> V_11 && ! V_3 -> remove )
F_5 ( V_1 , V_3 ) ;
} else
F_44 ( & V_1 -> V_39 . V_59 , V_55 ) ;
F_41 ( & V_1 -> V_48 , V_58 ) ;
if ( ! V_57 )
F_37 ( V_1 -> V_54 , & V_1 -> V_47 ) ;
return V_57 ;
}
int F_45 ( struct V_1 * V_1 , struct V_55 * V_55 , int V_19 )
{
struct V_62 * V_63 = V_55 -> V_64 ;
struct V_2 * V_3 = V_63 -> V_3 ;
struct V_65 * V_66 , * V_23 ;
bool V_67 = false ;
int V_68 ;
unsigned long V_58 ;
F_39 ( & V_1 -> V_48 , V_58 ) ;
V_68 = F_46 ( & V_1 -> V_39 . V_59 , V_55 , V_19 ) ;
if ( V_68 < 0 )
goto V_69;
F_34 (std, t, &qset->stds, list_node) {
if ( V_66 -> V_55 == V_55 ) {
if ( V_66 -> V_25 )
V_67 = true ;
F_47 ( V_1 , V_66 ) ;
} else
V_66 -> V_25 = NULL ;
}
if ( V_67 ) {
F_10 ( V_1 , V_3 ) ;
V_63 -> V_19 = V_19 ;
V_63 -> V_70 = true ;
F_37 ( V_1 -> V_54 , & V_63 -> V_71 ) ;
} else
F_48 ( V_1 , V_3 , V_55 , V_19 ) ;
V_69:
F_41 ( & V_1 -> V_48 , V_58 ) ;
return V_68 ;
}
void F_49 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
V_3 -> remove = 1 ;
F_37 ( V_1 -> V_54 , & V_1 -> V_47 ) ;
F_50 ( V_1 , V_3 ) ;
}
int F_51 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = F_52 ( V_1 , V_72 ) ;
if ( V_3 == NULL )
return - V_61 ;
F_5 ( V_1 , V_3 ) ;
F_7 ( V_1 , V_3 ) ;
return 0 ;
}
void F_53 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
if ( ! F_3 ( & V_1 -> V_9 ) ) {
V_3 = F_17 ( & V_1 -> V_9 , struct V_2 , V_10 ) ;
F_54 ( & V_3 -> V_10 ) ;
F_55 ( V_1 , V_3 ) ;
}
}
