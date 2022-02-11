void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
static void F_3 ( struct V_4 * V_3 )
{
struct V_1 * V_5 =
F_4 ( V_3 , struct V_1 , V_3 ) ;
if ( V_5 -> type -> V_6 -> V_7 )
F_5 ( V_5 , V_8 ) ;
else
F_6 ( V_5 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_3 , F_3 ) ;
}
static int F_9 ( struct V_1 * V_5 , bool V_9 )
{
if ( ! V_9 )
return F_10 ( & V_5 -> V_10 , 1 , - 1 ) == - 1 ?
- V_11 : 0 ;
return F_11 ( & V_5 -> V_10 , 0 , - 1 ) == 0 ? 0 : - V_11 ;
}
static struct V_1 * F_12 ( struct V_12 * V_13 ,
const struct V_14 * type )
{
struct V_1 * V_5 = F_13 ( type -> V_15 , V_16 ) ;
if ( ! V_5 )
return F_14 ( - V_17 ) ;
V_5 -> V_13 = V_13 ;
V_5 -> type = type ;
F_15 ( & V_5 -> V_10 , 0 ) ;
F_16 ( & V_5 -> V_3 ) ;
return V_5 ;
}
static int F_17 ( struct V_1 * V_5 )
{
int V_18 ;
F_18 ( V_16 ) ;
F_19 ( & V_5 -> V_13 -> V_19 -> V_20 ) ;
V_18 = F_20 ( & V_5 -> V_13 -> V_19 -> V_21 , NULL , 0 ,
F_21 (unsigned long, U32_MAX - 1 , INT_MAX) , V_22 ) ;
if ( V_18 >= 0 )
V_5 -> V_23 = V_18 ;
F_22 ( & V_5 -> V_13 -> V_19 -> V_20 ) ;
F_23 () ;
return V_18 < 0 ? V_18 : 0 ;
}
static void F_24 ( struct V_1 * V_5 )
{
F_19 ( & V_5 -> V_13 -> V_19 -> V_20 ) ;
F_25 ( & V_5 -> V_13 -> V_19 -> V_21 , V_5 -> V_23 ) ;
F_22 ( & V_5 -> V_13 -> V_19 -> V_20 ) ;
}
static struct V_1 * F_26 ( const struct V_14 * type ,
struct V_12 * V_24 ,
int V_23 , bool V_9 )
{
struct V_1 * V_5 ;
F_27 () ;
V_5 = F_28 ( & V_24 -> V_19 -> V_21 , V_23 ) ;
if ( ! V_5 ) {
V_5 = F_14 ( - V_25 ) ;
goto free;
}
F_1 ( V_5 ) ;
free:
F_29 () ;
return V_5 ;
}
static struct V_1 * F_30 ( const struct V_14 * type ,
struct V_12 * V_24 ,
int V_23 , bool V_9 )
{
struct V_26 * V_27 ;
struct V_1 * V_2 ;
const struct V_28 * V_29 =
F_4 ( type , struct V_28 , type ) ;
if ( V_9 )
return F_14 ( - V_30 ) ;
V_27 = F_31 ( V_23 ) ;
if ( ! V_27 )
return F_14 ( - V_31 ) ;
V_2 = V_27 -> V_32 ;
if ( V_27 -> V_33 != V_29 -> V_34 ) {
F_32 ( V_27 ) ;
return F_14 ( - V_31 ) ;
}
F_1 ( V_2 ) ;
return V_2 ;
}
struct V_1 * F_33 ( const struct V_14 * type ,
struct V_12 * V_24 ,
int V_23 , bool V_9 )
{
struct V_1 * V_5 ;
int V_18 ;
V_5 = type -> V_6 -> V_35 ( type , V_24 , V_23 , V_9 ) ;
if ( F_34 ( V_5 ) )
return V_5 ;
if ( V_5 -> type != type ) {
V_18 = - V_36 ;
goto free;
}
V_18 = F_9 ( V_5 , V_9 ) ;
if ( V_18 ) {
F_35 ( V_24 -> V_37 ,
L_1 ) ;
goto free;
}
return V_5 ;
free:
V_5 -> type -> V_6 -> V_38 ( V_5 , V_9 ) ;
F_7 ( V_5 ) ;
return F_14 ( V_18 ) ;
}
static struct V_1 * F_36 ( const struct V_14 * type ,
struct V_12 * V_24 )
{
int V_18 ;
struct V_1 * V_5 ;
V_5 = F_12 ( V_24 , type ) ;
if ( F_34 ( V_5 ) )
return V_5 ;
V_18 = F_17 ( V_5 ) ;
if ( V_18 )
goto V_39;
V_18 = F_37 ( & V_5 -> V_40 , V_24 -> V_41 ,
V_42 ) ;
if ( V_18 )
goto F_25;
return V_5 ;
F_25:
F_24 ( V_5 ) ;
V_39:
F_7 ( V_5 ) ;
return F_14 ( V_18 ) ;
}
static struct V_1 * F_38 ( const struct V_14 * type ,
struct V_12 * V_24 )
{
const struct V_28 * V_29 =
F_4 ( type , struct V_28 , type ) ;
int V_43 ;
struct V_1 * V_5 ;
struct V_44 * V_45 ;
struct V_26 * V_46 ;
V_43 = F_39 ( V_47 ) ;
if ( V_43 < 0 )
return F_14 ( V_43 ) ;
V_5 = F_12 ( V_24 , type ) ;
if ( F_34 ( V_5 ) ) {
F_40 ( V_43 ) ;
return V_5 ;
}
V_45 = F_4 ( V_5 , struct V_44 , V_5 ) ;
V_46 = F_41 ( V_29 -> V_48 ,
V_29 -> V_34 ,
V_45 ,
V_29 -> V_49 ) ;
if ( F_34 ( V_46 ) ) {
F_40 ( V_43 ) ;
F_7 ( V_5 ) ;
return ( void * ) V_46 ;
}
V_45 -> V_5 . V_23 = V_43 ;
V_45 -> V_5 . V_50 = V_46 ;
V_45 -> V_19 = V_24 -> V_19 ;
F_42 ( & V_5 -> V_51 ) ;
F_2 ( & V_45 -> V_19 -> V_3 ) ;
return V_5 ;
}
struct V_1 * F_43 ( const struct V_14 * type ,
struct V_12 * V_24 )
{
return type -> V_6 -> V_52 ( type , V_24 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_45 ( & V_2 -> V_13 -> V_53 ) ;
F_46 ( & V_2 -> V_51 , & V_2 -> V_13 -> V_54 ) ;
F_47 ( & V_2 -> V_13 -> V_53 ) ;
}
static int T_1 F_48 ( struct V_1 * V_5 ,
enum V_55 V_56 )
{
const struct V_57 * V_58 =
F_4 ( V_5 -> type , struct V_57 ,
type ) ;
int V_18 = V_58 -> V_59 ( V_5 , V_56 ) ;
if ( V_56 == V_60 && V_18 )
return V_18 ;
F_49 ( & V_5 -> V_40 , V_5 -> V_13 -> V_41 ,
V_42 ) ;
F_24 ( V_5 ) ;
return V_18 ;
}
static void F_50 ( struct V_1 * V_5 )
{
struct V_44 * V_45 =
F_4 ( V_5 , struct V_44 , V_5 ) ;
struct V_26 * V_46 = V_5 -> V_50 ;
int V_23 = V_45 -> V_5 . V_23 ;
F_32 ( V_46 ) ;
F_40 ( V_23 ) ;
}
static int T_1 F_51 ( struct V_1 * V_5 ,
enum V_55 V_56 )
{
const struct V_28 * V_29 =
F_4 ( V_5 -> type , struct V_28 , type ) ;
struct V_44 * V_45 =
F_4 ( V_5 , struct V_44 , V_5 ) ;
int V_18 = V_29 -> V_61 ( V_45 , V_56 ) ;
if ( V_56 == V_60 && V_18 )
return V_18 ;
if ( V_56 == V_62 ) {
F_50 ( V_5 ) ;
return V_18 ;
}
V_45 -> V_5 . V_13 = NULL ;
return V_18 ;
}
static void F_52 ( struct V_1 * V_5 , bool V_9 )
{
#ifdef F_53
if ( V_9 )
F_54 ( F_55 ( & V_5 -> V_10 ) > 0 ) ;
else
F_54 ( F_55 ( & V_5 -> V_10 ) == - 1 ) ;
#endif
}
static int T_1 F_56 ( struct V_1 * V_5 ,
enum V_55 V_56 )
{
int V_18 ;
struct V_12 * V_24 = V_5 -> V_13 ;
V_18 = V_5 -> type -> V_6 -> V_63 ( V_5 , V_56 ) ;
if ( V_18 && V_56 == V_60 ) {
F_15 ( & V_5 -> V_10 , 0 ) ;
V_5 -> type -> V_6 -> V_38 ( V_5 , true ) ;
} else {
F_45 ( & V_24 -> V_53 ) ;
F_57 ( & V_5 -> V_51 ) ;
F_47 ( & V_24 -> V_53 ) ;
F_7 ( V_5 ) ;
}
return V_18 ;
}
int T_1 F_58 ( struct V_1 * V_5 )
{
int V_18 ;
struct V_12 * V_24 = V_5 -> V_13 ;
F_7 ( V_5 ) ;
if ( ! F_59 ( & V_24 -> V_64 ) ) {
F_35 ( true , L_2 ) ;
return 0 ;
}
F_52 ( V_5 , true ) ;
V_18 = F_56 ( V_5 , V_60 ) ;
F_60 ( & V_24 -> V_64 ) ;
return V_18 ;
}
static void F_61 ( struct V_1 * V_5 )
{
F_44 ( V_5 ) ;
F_19 ( & V_5 -> V_13 -> V_19 -> V_20 ) ;
F_54 ( F_62 ( & V_5 -> V_13 -> V_19 -> V_21 ,
V_5 , V_5 -> V_23 ) ) ;
F_22 ( & V_5 -> V_13 -> V_19 -> V_20 ) ;
}
static void F_63 ( struct V_1 * V_5 )
{
struct V_44 * V_45 =
F_4 ( V_5 , struct V_44 , V_5 ) ;
F_44 ( & V_45 -> V_5 ) ;
F_64 ( V_45 -> V_5 . V_23 , V_5 -> V_50 ) ;
V_45 -> V_5 . V_23 = 0 ;
F_1 ( & V_45 -> V_5 ) ;
}
int F_65 ( struct V_1 * V_5 )
{
if ( ! F_59 ( & V_5 -> V_13 -> V_64 ) ) {
int V_18 ;
F_35 ( true , L_3 ) ;
V_18 = V_5 -> type -> V_6 -> V_63 ( V_5 ,
V_62 ) ;
if ( V_18 )
F_66 ( L_4 ,
V_5 -> V_23 ) ;
return V_18 ;
}
V_5 -> type -> V_6 -> V_65 ( V_5 ) ;
F_60 ( & V_5 -> V_13 -> V_64 ) ;
return 0 ;
}
static void F_67 ( struct V_1 * V_5 )
{
F_24 ( V_5 ) ;
F_49 ( & V_5 -> V_40 , V_5 -> V_13 -> V_41 ,
V_42 ) ;
F_7 ( V_5 ) ;
}
void F_68 ( struct V_1 * V_5 )
{
V_5 -> type -> V_6 -> V_66 ( V_5 ) ;
}
static void F_69 ( struct V_1 * V_5 , bool V_9 )
{
}
static void F_70 ( struct V_1 * V_5 , bool V_9 )
{
struct V_26 * V_46 = V_5 -> V_50 ;
F_54 ( V_9 ) ;
F_32 ( V_46 ) ;
}
void F_71 ( struct V_1 * V_5 , bool V_9 )
{
F_52 ( V_5 , V_9 ) ;
V_5 -> type -> V_6 -> V_38 ( V_5 , V_9 ) ;
if ( ! V_9 )
F_72 ( & V_5 -> V_10 ) ;
else
F_15 ( & V_5 -> V_10 , 0 ) ;
F_7 ( V_5 ) ;
}
static void F_73 ( struct V_44 * V_45 )
{
struct V_12 * V_24 ;
struct V_67 * V_19 = V_45 -> V_19 ;
int V_18 ;
F_45 ( & V_45 -> V_19 -> V_68 ) ;
if ( ! V_45 -> V_5 . V_13 ||
! F_59 ( & V_45 -> V_5 . V_13 -> V_64 ) )
goto V_69;
V_24 = V_45 -> V_5 . V_13 ;
V_18 = F_56 ( & V_45 -> V_5 , V_70 ) ;
F_60 ( & V_24 -> V_64 ) ;
if ( V_18 )
F_66 ( L_5 ) ;
V_69:
F_47 ( & V_19 -> V_68 ) ;
}
void F_74 ( struct V_26 * V_27 )
{
struct V_44 * V_45 = V_27 -> V_32 ;
struct V_4 * V_71 = & V_45 -> V_19 -> V_3 ;
F_73 ( V_45 ) ;
F_7 ( & V_45 -> V_5 ) ;
F_8 ( V_71 , V_72 ) ;
}
void F_75 ( struct V_12 * V_24 , bool V_73 )
{
enum V_55 V_74 = V_73 ?
V_75 : V_70 ;
unsigned int V_76 = 0 ;
V_24 -> V_37 = V_74 ;
F_76 ( & V_24 -> V_64 ) ;
while ( ! F_77 ( & V_24 -> V_54 ) ) {
struct V_1 * V_77 , * V_78 ;
unsigned int V_79 = V_80 ;
F_45 ( & V_24 -> V_53 ) ;
F_78 (obj, next_obj, &ucontext->uobjects,
list) {
if ( V_77 -> type -> V_81 == V_76 ) {
int V_18 ;
F_54 ( F_9 ( V_77 , true ) ) ;
V_18 = V_77 -> type -> V_6 -> V_63 ( V_77 ,
V_74 ) ;
F_57 ( & V_77 -> V_51 ) ;
if ( V_18 )
F_66 ( L_6 ,
V_77 -> V_23 , V_76 ) ;
F_7 ( V_77 ) ;
} else {
V_79 = F_79 ( V_79 ,
V_77 -> type -> V_81 ) ;
}
}
F_47 ( & V_24 -> V_53 ) ;
V_76 = V_79 ;
}
F_80 ( & V_24 -> V_64 ) ;
}
void F_81 ( struct V_12 * V_24 )
{
V_24 -> V_37 = 0 ;
F_82 ( & V_24 -> V_53 ) ;
F_42 ( & V_24 -> V_54 ) ;
F_83 ( & V_24 -> V_64 ) ;
}
