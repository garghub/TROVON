static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 * V_5 = & V_3 -> V_6 ;
if ( ! V_5 -> V_7 )
return;
if ( F_2 ( V_8 , V_5 -> V_9 ) ) {
F_3 ( & V_5 -> V_10 , V_5 -> V_9 ) ;
return;
}
F_4 ( L_1 , V_3 -> V_11 ) ;
F_5 ( V_3 -> V_12 , & V_3 -> V_13 -> V_14 . V_15 ) ;
F_3 ( & V_3 -> V_6 . V_16 , V_8 + 1 ) ;
F_6 ( V_3 -> V_13 ) ;
}
static unsigned long F_7 ( void )
{
return F_8 ( V_8 + V_17 ) ;
}
static void F_9 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
if ( F_10 ( V_3 ) )
F_3 ( & V_3 -> V_6 . V_16 , V_8 + 1 ) ;
}
static void F_11 ( struct V_2 * V_3 )
{
V_3 -> V_6 . V_18 = true ;
F_12 ( & V_3 -> V_13 -> V_19 ) ;
V_3 -> F_11 ( V_3 ) ;
F_13 ( & V_3 -> V_13 -> V_19 ) ;
}
static void F_14 ( struct V_2 * V_3 )
{
F_12 ( & V_3 -> V_13 -> V_19 ) ;
V_3 -> F_14 ( V_3 ) ;
F_13 ( & V_3 -> V_13 -> V_19 ) ;
V_3 -> V_6 . V_18 = false ;
}
static void F_15 ( struct V_4 * V_5 )
{
struct V_2 * V_3 =
F_16 ( V_5 , struct V_2 , V_6 ) ;
struct V_20 * V_13 = V_3 -> V_13 ;
F_17 ( & V_5 -> V_21 ) ;
if ( V_5 -> V_22 )
return;
F_18 ( V_13 ) ;
V_5 -> V_22 = true ;
if ( F_19 ( V_13 ) ) {
if ( ! F_20 ( V_3 -> V_12 , & V_13 -> V_14 . V_23 ) )
F_11 ( V_3 ) ;
V_5 -> V_7 = true ;
}
if ( ! V_5 -> V_7 ||
F_20 ( V_3 -> V_12 , & V_13 -> V_14 . V_15 ) ) {
F_3 ( & V_5 -> V_16 , V_8 + 1 ) ;
} else {
F_21 ( ! F_22 ( V_5 -> V_9 , V_8 ) ) ;
F_3 ( & V_5 -> V_10 , V_5 -> V_9 ) ;
}
}
static void F_23 ( struct V_4 * V_5 )
{
struct V_2 * V_3 =
F_16 ( V_5 , struct V_2 , V_6 ) ;
F_17 ( & V_5 -> V_21 ) ;
if ( ! V_5 -> V_22 )
return;
if ( V_5 -> V_7 ) {
F_14 ( V_3 ) ;
V_5 -> V_7 = false ;
}
F_24 ( V_3 -> V_13 ) ;
V_5 -> V_22 = false ;
}
static inline struct V_24 * F_25 ( struct V_25 * V_26 )
{
return F_26 ( V_26 , struct V_24 , V_26 ) ;
}
static inline void F_27 ( struct V_4 * V_5 ,
struct V_24 * V_27 )
{
F_17 ( & V_5 -> V_21 ) ;
F_28 ( & V_27 -> V_26 , & V_5 -> V_28 ) ;
F_29 ( & V_27 -> V_26 ) ;
F_30 ( V_27 -> V_29 ) ;
}
static bool F_31 ( struct V_2 * V_3 ,
struct V_24 * V_27 )
{
struct V_4 * V_5 = & V_3 -> V_6 ;
struct V_25 * * V_30 , * V_31 , * V_32 ;
bool V_33 ;
T_1 V_34 ;
V_33 = true ;
V_31 = NULL ;
V_32 = NULL ;
V_34 = F_32 ( V_3 ) ;
if ( F_33 ( V_34 , V_27 -> V_34 ) ) {
F_29 ( & V_27 -> V_26 ) ;
return V_33 ;
}
V_30 = & V_5 -> V_28 . V_25 ;
while ( * V_30 ) {
V_31 = * V_30 ;
if ( V_27 -> V_34 == F_25 ( V_31 ) -> V_34 ) {
if ( V_27 -> V_29 -> V_35 > F_25 ( V_31 ) -> V_29 -> V_35 ) {
V_30 = & V_31 -> V_36 ;
V_33 = false ;
} else {
V_30 = & V_31 -> V_37 ;
}
} else if ( F_33 ( V_27 -> V_34 ,
F_25 ( V_31 ) -> V_34 ) ) {
V_30 = & V_31 -> V_36 ;
if ( F_33 ( V_34 , F_25 ( V_31 ) -> V_34 ) )
V_32 = V_31 ;
else
V_33 = false ;
} else {
V_30 = & V_31 -> V_37 ;
}
}
F_34 ( & V_27 -> V_26 , V_31 , V_30 ) ;
F_35 ( & V_27 -> V_26 , & V_5 -> V_28 ) ;
F_21 ( ! V_33 && ! F_36 ( V_5 -> V_38 ) ) ;
if ( V_32 ) {
struct V_25 * V_39 = F_37 ( V_32 ) ;
F_21 ( ! V_39 && ! V_33 ) ;
if ( V_39 && V_39 != & V_27 -> V_26 ) {
F_21 ( V_33 ) ;
V_5 -> V_9 = F_7 () ;
V_5 -> V_40 = F_25 ( V_39 ) ;
F_38 ( V_5 -> V_38 , V_5 -> V_40 -> V_29 ) ;
F_15 ( V_5 ) ;
if ( F_39 ( V_5 -> V_18 ) )
F_30 ( F_25 ( V_39 ) -> V_29 ) ;
}
do {
struct V_24 * V_41 = F_25 ( V_32 ) ;
V_32 = F_40 ( V_32 ) ;
F_27 ( V_5 , V_41 ) ;
} while ( V_32 );
}
if ( V_33 ) {
F_21 ( F_41 ( & V_5 -> V_28 ) != & V_27 -> V_26 ) ;
V_5 -> V_9 = F_7 () ;
V_5 -> V_40 = V_27 ;
F_38 ( V_5 -> V_38 , V_27 -> V_29 ) ;
F_15 ( V_5 ) ;
}
F_21 ( ! F_36 ( V_5 -> V_38 ) ) ;
F_21 ( ! V_5 -> V_40 ) ;
F_21 ( F_41 ( & V_5 -> V_28 ) != & V_5 -> V_40 -> V_26 ) ;
return V_33 ;
}
bool F_42 ( struct V_2 * V_3 ,
struct V_24 * V_27 )
{
struct V_4 * V_5 = & V_3 -> V_6 ;
bool V_33 ;
F_43 ( & V_5 -> V_21 ) ;
V_33 = F_31 ( V_3 , V_27 ) ;
F_44 ( & V_5 -> V_21 ) ;
return V_33 ;
}
static inline bool F_45 ( struct V_25 * V_42 , int V_43 )
{
return V_42 && F_25 ( V_42 ) -> V_29 -> V_35 <= V_43 ;
}
static inline int F_46 ( struct V_4 * V_5 ,
struct V_44 * V_29 )
{
if ( V_29 == V_5 -> V_45 )
return V_46 ;
else
return V_29 -> V_35 ;
}
void F_47 ( struct V_2 * V_3 ,
struct V_24 * V_27 )
{
struct V_4 * V_5 = & V_3 -> V_6 ;
if ( F_48 ( & V_27 -> V_26 ) )
return;
F_43 ( & V_5 -> V_21 ) ;
if ( F_48 ( & V_27 -> V_26 ) )
goto V_47;
if ( V_5 -> V_40 == V_27 ) {
const int V_43 = F_46 ( V_5 , V_27 -> V_29 ) ;
struct V_25 * V_39 ;
F_21 ( F_36 ( V_5 -> V_38 ) != V_27 -> V_29 ) ;
V_39 = F_37 ( & V_27 -> V_26 ) ;
if ( F_45 ( V_39 , V_43 ) ) {
T_1 V_34 = F_32 ( V_3 ) ;
while ( F_33 ( V_34 , F_25 ( V_39 ) -> V_34 ) ) {
struct V_25 * V_48 = F_37 ( V_39 ) ;
F_27 ( V_5 , F_25 ( V_39 ) ) ;
V_39 = V_48 ;
if ( ! F_45 ( V_39 , V_43 ) )
break;
}
}
if ( V_39 ) {
V_5 -> V_9 = F_7 () ;
V_5 -> V_40 = F_25 ( V_39 ) ;
F_38 ( V_5 -> V_38 , V_5 -> V_40 -> V_29 ) ;
if ( V_5 -> V_40 -> V_34 != V_27 -> V_34 )
F_15 ( V_5 ) ;
F_30 ( V_5 -> V_40 -> V_29 ) ;
} else {
V_5 -> V_40 = NULL ;
F_38 ( V_5 -> V_38 , NULL ) ;
F_23 ( V_5 ) ;
}
} else {
F_21 ( F_41 ( & V_5 -> V_28 ) == & V_27 -> V_26 ) ;
}
F_21 ( F_48 ( & V_27 -> V_26 ) ) ;
F_28 ( & V_27 -> V_26 , & V_5 -> V_28 ) ;
V_47:
F_21 ( V_5 -> V_40 == V_27 ) ;
F_21 ( F_41 ( & V_5 -> V_28 ) !=
( V_5 -> V_40 ? & V_5 -> V_40 -> V_26 : NULL ) ) ;
F_21 ( ! F_36 ( V_5 -> V_38 ) ^ F_49 ( & V_5 -> V_28 ) ) ;
F_44 ( & V_5 -> V_21 ) ;
}
static bool F_50 ( struct V_49 * V_50 )
{
if ( ! V_50 )
return false ;
if ( F_51 ( & V_50 -> V_51 . V_27 ) )
return true ;
if ( F_52 ( V_50 ) )
return true ;
return false ;
}
static struct V_49 * F_53 ( struct V_25 * V_42 )
{
return F_26 ( V_42 , struct V_49 , V_51 . V_26 ) ;
}
static void F_54 ( void )
{
struct V_52 V_53 = { . V_54 = 1 } ;
F_55 ( V_55 , V_56 , & V_53 ) ;
}
static int F_56 ( void * V_57 )
{
struct V_2 * V_3 = V_57 ;
struct V_4 * V_5 = & V_3 -> V_6 ;
struct V_49 * V_50 ;
F_54 () ;
do {
F_57 ( V_58 ) ;
V_50 = F_39 ( V_5 -> V_59 ) ;
if ( F_50 ( V_50 ) ) {
F_47 ( V_3 ,
& V_50 -> V_51 . V_27 ) ;
F_58 () ;
F_59 ( & V_50 -> V_60 ) ;
F_60 () ;
F_43 ( & V_5 -> V_21 ) ;
if ( V_50 == V_5 -> V_59 ) {
struct V_25 * V_42 =
F_37 ( & V_50 -> V_51 . V_26 ) ;
V_5 -> V_59 = V_42 ? F_53 ( V_42 ) : NULL ;
}
F_28 ( & V_50 -> V_51 . V_26 , & V_5 -> V_61 ) ;
F_44 ( & V_5 -> V_21 ) ;
F_61 ( V_50 ) ;
} else {
if ( F_62 () )
break;
F_63 () ;
}
} while ( 1 );
F_64 ( V_62 ) ;
return 0 ;
}
void F_65 ( struct V_49 * V_50 )
{
struct V_2 * V_3 = V_50 -> V_3 ;
struct V_4 * V_5 = & V_3 -> V_6 ;
struct V_25 * V_31 , * * V_30 ;
bool V_33 , V_63 ;
F_17 ( & V_50 -> V_21 ) ;
if ( ! V_50 -> V_64 )
return;
V_50 -> V_51 . V_27 . V_29 = V_5 -> V_45 ;
V_50 -> V_51 . V_27 . V_34 = V_50 -> V_64 ;
F_66 ( V_50 ) ;
F_12 ( & V_5 -> V_21 ) ;
V_63 = F_31 ( V_3 , & V_50 -> V_51 . V_27 ) ;
V_31 = NULL ;
V_33 = true ;
V_30 = & V_5 -> V_61 . V_25 ;
while ( * V_30 ) {
V_31 = * V_30 ;
if ( F_33 ( V_50 -> V_64 ,
F_53 ( V_31 ) -> V_64 ) ) {
V_30 = & V_31 -> V_36 ;
V_33 = false ;
} else {
V_30 = & V_31 -> V_37 ;
}
}
F_34 ( & V_50 -> V_51 . V_26 , V_31 , V_30 ) ;
F_35 ( & V_50 -> V_51 . V_26 , & V_5 -> V_61 ) ;
if ( V_33 )
F_67 ( V_5 -> V_59 , V_50 ) ;
F_13 ( & V_5 -> V_21 ) ;
if ( V_63 )
F_30 ( V_5 -> V_45 ) ;
}
int F_68 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_6 ;
struct V_44 * V_29 ;
F_69 ( & V_5 -> V_21 ) ;
F_70 ( & V_5 -> V_16 ,
F_9 ,
( unsigned long ) V_3 ) ;
F_70 ( & V_5 -> V_10 ,
F_1 ,
( unsigned long ) V_3 ) ;
V_29 = F_71 ( F_56 , V_3 ,
L_2 , V_3 -> V_12 ) ;
if ( F_72 ( V_29 ) )
return F_73 ( V_29 ) ;
V_5 -> V_45 = V_29 ;
return 0 ;
}
static void F_74 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_6 ;
F_75 ( & V_5 -> V_10 ) ;
F_75 ( & V_5 -> V_16 ) ;
F_76 ( V_3 -> V_12 , & V_3 -> V_13 -> V_14 . V_15 ) ;
}
void F_77 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_6 ;
F_74 ( V_3 ) ;
F_43 ( & V_5 -> V_21 ) ;
F_23 ( V_5 ) ;
if ( F_78 ( V_3 ) ) {
V_5 -> V_9 = F_7 () ;
F_15 ( V_5 ) ;
if ( F_39 ( V_5 -> V_18 ) )
F_30 ( V_5 -> V_40 -> V_29 ) ;
} else {
F_14 ( V_3 ) ;
}
F_44 ( & V_5 -> V_21 ) ;
}
void F_79 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_6 ;
F_80 ( F_39 ( V_5 -> V_40 ) ) ;
F_80 ( ! F_49 ( & V_5 -> V_28 ) ) ;
F_80 ( F_39 ( V_5 -> V_59 ) ) ;
F_80 ( ! F_49 ( & V_5 -> V_61 ) ) ;
if ( ! F_81 ( V_5 -> V_45 ) )
F_82 ( V_5 -> V_45 ) ;
F_74 ( V_3 ) ;
}
unsigned int F_83 ( struct V_20 * V_13 )
{
struct V_2 * V_3 ;
enum V_65 V_12 ;
unsigned int V_66 = 0 ;
F_84 (engine, i915, id) {
struct V_4 * V_5 = & V_3 -> V_6 ;
F_43 ( & V_5 -> V_21 ) ;
if ( V_5 -> V_40 ) {
F_30 ( V_5 -> V_40 -> V_29 ) ;
V_66 |= F_85 ( V_3 ) ;
}
if ( V_5 -> V_59 ) {
F_30 ( V_5 -> V_45 ) ;
V_66 |= F_85 ( V_3 ) ;
}
F_44 ( & V_5 -> V_21 ) ;
}
return V_66 ;
}
