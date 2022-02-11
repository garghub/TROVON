void F_1 ( struct V_1 * V_2 )
{
F_2 ( ! F_3 ( & V_2 -> V_3 ) ) ;
F_4 ( & V_2 -> V_3 ) ;
}
static bool F_5 ( struct V_1 * V_2 )
{
return F_6 ( & V_2 -> V_3 ) ;
}
static void F_7 ( struct V_4 * V_5 )
{
T_1 V_6 = 0 ;
struct V_1 * V_2 ;
F_8 ( & V_5 -> V_7 ) ;
F_9 (mark, &conn->list, obj_list) {
if ( V_2 -> V_8 & V_9 )
V_6 |= V_2 -> V_10 ;
}
if ( V_5 -> V_8 & V_11 )
V_5 -> V_12 -> V_13 = V_6 ;
else if ( V_5 -> V_8 & V_14 )
F_10 ( V_5 -> V_15 ) -> V_16 = V_6 ;
}
void F_11 ( struct V_4 * V_5 )
{
if ( ! V_5 )
return;
F_12 ( & V_5 -> V_7 ) ;
F_7 ( V_5 ) ;
F_13 ( & V_5 -> V_7 ) ;
if ( V_5 -> V_8 & V_11 )
F_14 ( V_5 -> V_12 ) ;
}
static void F_15 ( struct V_17 * V_18 )
{
struct V_4 * V_5 , * free ;
F_12 ( & V_19 ) ;
V_5 = V_20 ;
V_20 = NULL ;
F_13 ( & V_19 ) ;
F_16 ( & V_21 ) ;
while ( V_5 ) {
free = V_5 ;
V_5 = V_5 -> V_22 ;
F_17 ( V_23 , free ) ;
}
}
static struct V_12 * F_18 (
struct V_4 * V_5 )
{
struct V_12 * V_12 = NULL ;
if ( V_5 -> V_8 & V_11 ) {
V_12 = V_5 -> V_12 ;
F_19 ( V_12 -> V_24 , NULL ) ;
V_12 -> V_13 = 0 ;
V_5 -> V_12 = NULL ;
V_5 -> V_8 &= ~ V_11 ;
} else if ( V_5 -> V_8 & V_14 ) {
F_19 ( F_10 ( V_5 -> V_15 ) -> V_25 ,
NULL ) ;
F_10 ( V_5 -> V_15 ) -> V_16 = 0 ;
V_5 -> V_15 = NULL ;
V_5 -> V_8 &= ~ V_14 ;
}
return V_12 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
if ( F_2 ( ! V_27 ) )
return;
V_27 -> V_28 -> V_29 ( V_2 ) ;
F_21 ( V_27 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_12 * V_12 = NULL ;
bool V_30 = false ;
if ( ! V_2 -> V_31 ) {
if ( F_23 ( & V_2 -> V_3 ) )
F_20 ( V_2 ) ;
return;
}
if ( ! F_24 ( & V_2 -> V_3 , & V_2 -> V_31 -> V_7 ) )
return;
V_5 = V_2 -> V_31 ;
F_25 ( & V_2 -> V_32 ) ;
if ( F_26 ( & V_5 -> V_33 ) ) {
V_12 = F_18 ( V_5 ) ;
V_30 = true ;
} else {
F_7 ( V_5 ) ;
}
V_2 -> V_31 = NULL ;
F_13 ( & V_5 -> V_7 ) ;
F_27 ( V_12 ) ;
if ( V_30 ) {
F_12 ( & V_19 ) ;
V_5 -> V_22 = V_20 ;
V_20 = V_5 ;
F_13 ( & V_19 ) ;
F_28 ( V_34 , & V_35 ) ;
}
F_12 ( & V_19 ) ;
F_29 ( & V_2 -> V_36 , & V_37 ) ;
F_13 ( & V_19 ) ;
F_30 ( V_34 , & V_38 ,
V_39 ) ;
}
bool F_31 ( struct V_40 * V_41 )
{
struct V_26 * V_27 ;
if ( F_2 ( ! V_41 -> V_42 && ! V_41 -> V_43 ) )
return false ;
if ( V_41 -> V_42 )
V_27 = V_41 -> V_42 -> V_27 ;
else
V_27 = V_41 -> V_43 -> V_27 ;
F_4 ( & V_27 -> V_44 ) ;
if ( V_41 -> V_42 ) {
if ( ! F_5 ( V_41 -> V_42 ) )
goto V_45;
}
if ( V_41 -> V_43 ) {
if ( ! F_5 ( V_41 -> V_43 ) )
goto V_46;
}
F_32 ( & V_21 , V_41 -> V_47 ) ;
return true ;
V_46:
if ( V_41 -> V_42 )
F_22 ( V_41 -> V_42 ) ;
V_45:
if ( F_23 ( & V_27 -> V_44 ) && V_27 -> V_48 )
F_33 ( & V_27 -> V_49 ) ;
return false ;
}
void F_34 ( struct V_40 * V_41 )
{
struct V_26 * V_27 = NULL ;
V_41 -> V_47 = F_35 ( & V_21 ) ;
if ( V_41 -> V_42 ) {
V_27 = V_41 -> V_42 -> V_27 ;
F_22 ( V_41 -> V_42 ) ;
}
if ( V_41 -> V_43 ) {
V_27 = V_41 -> V_43 -> V_27 ;
F_22 ( V_41 -> V_43 ) ;
}
if ( F_23 ( & V_27 -> V_44 ) && V_27 -> V_48 )
F_33 ( & V_27 -> V_49 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
F_2 ( ! F_37 ( & V_27 -> V_50 ) ) ;
F_2 ( ! F_38 ( & V_21 ) &&
F_3 ( & V_2 -> V_3 ) < 1 +
! ! ( V_2 -> V_8 & V_9 ) ) ;
F_12 ( & V_2 -> V_7 ) ;
if ( ! ( V_2 -> V_8 & V_9 ) ) {
F_13 ( & V_2 -> V_7 ) ;
return;
}
V_2 -> V_8 &= ~ V_9 ;
F_39 ( & V_2 -> V_36 ) ;
F_13 ( & V_2 -> V_7 ) ;
F_40 ( & V_27 -> V_51 ) ;
F_22 ( V_2 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
F_12 ( & V_2 -> V_7 ) ;
if ( ! ( V_2 -> V_8 & V_52 ) ) {
F_13 ( & V_2 -> V_7 ) ;
return;
}
V_2 -> V_8 &= ~ V_52 ;
F_13 ( & V_2 -> V_7 ) ;
if ( V_27 -> V_28 -> V_53 )
V_27 -> V_28 -> V_53 ( V_2 , V_27 ) ;
}
void F_42 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
F_43 ( & V_27 -> V_50 , V_54 ) ;
F_36 ( V_2 ) ;
F_44 ( & V_27 -> V_50 ) ;
F_41 ( V_2 ) ;
}
int F_45 ( struct V_26 * V_55 , struct V_26 * V_56 )
{
if ( V_55 == V_56 )
return 0 ;
if ( ! V_55 )
return 1 ;
if ( ! V_56 )
return - 1 ;
if ( V_55 -> V_57 < V_56 -> V_57 )
return 1 ;
if ( V_55 -> V_57 > V_56 -> V_57 )
return - 1 ;
if ( V_55 < V_56 )
return 1 ;
return - 1 ;
}
static int F_46 (
struct V_4 T_2 * * V_58 ,
struct V_12 * V_12 ,
struct V_59 * V_15 )
{
struct V_4 * V_5 ;
V_5 = F_47 ( V_23 , V_60 ) ;
if ( ! V_5 )
return - V_61 ;
F_48 ( & V_5 -> V_7 ) ;
F_49 ( & V_5 -> V_33 ) ;
if ( V_12 ) {
V_5 -> V_8 = V_11 ;
V_5 -> V_12 = F_50 ( V_12 ) ;
} else {
V_5 -> V_8 = V_14 ;
V_5 -> V_15 = V_15 ;
}
if ( F_51 ( V_58 , NULL , V_5 ) ) {
if ( V_12 )
F_27 ( V_12 ) ;
F_17 ( V_23 , V_5 ) ;
}
return 0 ;
}
static struct V_4 * F_52 (
struct V_4 T_2 * * V_58 )
{
struct V_4 * V_5 ;
int V_62 ;
V_62 = F_35 ( & V_21 ) ;
V_5 = F_53 ( * V_58 , & V_21 ) ;
if ( ! V_5 )
goto V_63;
F_12 ( & V_5 -> V_7 ) ;
if ( ! ( V_5 -> V_8 & ( V_11 |
V_14 ) ) ) {
F_13 ( & V_5 -> V_7 ) ;
F_32 ( & V_21 , V_62 ) ;
return NULL ;
}
V_63:
F_32 ( & V_21 , V_62 ) ;
return V_5 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_12 * V_12 , struct V_59 * V_15 ,
int V_64 )
{
struct V_1 * V_65 , * V_66 = NULL ;
struct V_4 * V_5 ;
struct V_4 T_2 * * V_58 ;
int V_67 ;
int V_68 = 0 ;
if ( F_55 ( ! V_12 && ! V_15 ) )
return - V_69 ;
if ( V_12 )
V_58 = & V_12 -> V_24 ;
else
V_58 = & F_10 ( V_15 ) -> V_25 ;
V_70:
F_12 ( & V_2 -> V_7 ) ;
V_5 = F_52 ( V_58 ) ;
if ( ! V_5 ) {
F_13 ( & V_2 -> V_7 ) ;
V_68 = F_46 ( V_58 , V_12 , V_15 ) ;
if ( V_68 )
return V_68 ;
goto V_70;
}
if ( F_26 ( & V_5 -> V_33 ) ) {
F_56 ( & V_2 -> V_32 , & V_5 -> V_33 ) ;
goto V_71;
}
F_9 (lmark, &conn->list, obj_list) {
V_66 = V_65 ;
if ( ( V_65 -> V_27 == V_2 -> V_27 ) &&
( V_65 -> V_8 & V_9 ) &&
! V_64 ) {
V_68 = - V_72 ;
goto V_73;
}
V_67 = F_45 ( V_65 -> V_27 , V_2 -> V_27 ) ;
if ( V_67 >= 0 ) {
F_57 ( & V_2 -> V_32 , & V_65 -> V_32 ) ;
goto V_71;
}
}
F_58 ( V_66 == NULL ) ;
F_59 ( & V_2 -> V_32 , & V_66 -> V_32 ) ;
V_71:
V_2 -> V_31 = V_5 ;
V_73:
F_13 ( & V_5 -> V_7 ) ;
F_13 ( & V_2 -> V_7 ) ;
return V_68 ;
}
int F_60 ( struct V_1 * V_2 , struct V_12 * V_12 ,
struct V_59 * V_15 , int V_64 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
int V_74 = 0 ;
F_58 ( V_12 && V_15 ) ;
F_58 ( ! V_12 && ! V_15 ) ;
F_58 ( ! F_37 ( & V_27 -> V_50 ) ) ;
F_12 ( & V_2 -> V_7 ) ;
V_2 -> V_8 |= V_52 | V_9 ;
F_29 ( & V_2 -> V_36 , & V_27 -> V_75 ) ;
F_4 ( & V_27 -> V_51 ) ;
F_1 ( V_2 ) ;
F_13 ( & V_2 -> V_7 ) ;
V_74 = F_54 ( V_2 , V_12 , V_15 , V_64 ) ;
if ( V_74 )
goto V_68;
if ( V_2 -> V_10 )
F_11 ( V_2 -> V_31 ) ;
return V_74 ;
V_68:
V_2 -> V_8 &= ~ ( V_52 |
V_9 ) ;
F_39 ( & V_2 -> V_36 ) ;
F_40 ( & V_27 -> V_51 ) ;
F_22 ( V_2 ) ;
return V_74 ;
}
int F_61 ( struct V_1 * V_2 , struct V_12 * V_12 ,
struct V_59 * V_15 , int V_64 )
{
int V_74 ;
struct V_26 * V_27 = V_2 -> V_27 ;
F_62 ( & V_27 -> V_50 ) ;
V_74 = F_60 ( V_2 , V_12 , V_15 , V_64 ) ;
F_44 ( & V_27 -> V_50 ) ;
return V_74 ;
}
struct V_1 * F_63 (
struct V_4 T_2 * * V_58 ,
struct V_26 * V_27 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
V_5 = F_52 ( V_58 ) ;
if ( ! V_5 )
return NULL ;
F_9 (mark, &conn->list, obj_list) {
if ( V_2 -> V_27 == V_27 &&
( V_2 -> V_8 & V_9 ) ) {
F_1 ( V_2 ) ;
F_13 ( & V_5 -> V_7 ) ;
return V_2 ;
}
}
F_13 ( & V_5 -> V_7 ) ;
return NULL ;
}
void F_64 ( struct V_26 * V_27 ,
unsigned int type )
{
struct V_1 * V_65 , * V_2 ;
F_65 ( V_76 ) ;
struct V_77 * V_78 = & V_76 ;
if ( type == V_79 ) {
V_78 = & V_27 -> V_75 ;
goto V_80;
}
F_43 ( & V_27 -> V_50 , V_54 ) ;
F_66 (mark, lmark, &group->marks_list, g_list) {
if ( V_2 -> V_31 -> V_8 & type )
F_67 ( & V_2 -> V_36 , & V_76 ) ;
}
F_44 ( & V_27 -> V_50 ) ;
V_80:
while ( 1 ) {
F_43 ( & V_27 -> V_50 , V_54 ) ;
if ( F_68 ( V_78 ) ) {
F_44 ( & V_27 -> V_50 ) ;
break;
}
V_2 = F_69 ( V_78 , struct V_1 , V_36 ) ;
F_1 ( V_2 ) ;
F_36 ( V_2 ) ;
F_44 ( & V_27 -> V_50 ) ;
F_41 ( V_2 ) ;
F_22 ( V_2 ) ;
}
}
void F_70 ( struct V_4 T_2 * * V_58 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 , * V_81 = NULL ;
struct V_12 * V_12 ;
V_5 = F_52 ( V_58 ) ;
if ( ! V_5 )
return;
F_9 (mark, &conn->list, obj_list) {
F_1 ( V_2 ) ;
F_13 ( & V_5 -> V_7 ) ;
if ( V_81 )
F_22 ( V_81 ) ;
V_81 = V_2 ;
F_42 ( V_2 , V_2 -> V_27 ) ;
F_12 ( & V_5 -> V_7 ) ;
}
V_12 = F_18 ( V_5 ) ;
F_13 ( & V_5 -> V_7 ) ;
if ( V_81 )
F_22 ( V_81 ) ;
F_27 ( V_12 ) ;
}
void F_71 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_48 ( & V_2 -> V_7 ) ;
F_72 ( & V_2 -> V_3 , 1 ) ;
F_73 ( V_27 ) ;
V_2 -> V_27 = V_27 ;
}
static void F_74 ( struct V_17 * V_18 )
{
struct V_1 * V_2 , * V_82 ;
struct V_77 V_83 ;
F_12 ( & V_19 ) ;
F_75 ( & V_37 , & V_83 ) ;
F_13 ( & V_19 ) ;
F_16 ( & V_21 ) ;
F_66 (mark, next, &private_destroy_list, g_list) {
F_39 ( & V_2 -> V_36 ) ;
F_20 ( V_2 ) ;
}
}
void F_76 ( void )
{
F_77 ( & V_38 ) ;
}
