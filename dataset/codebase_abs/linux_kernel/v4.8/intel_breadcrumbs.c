static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 () ;
if ( F_3 ( V_3 ) )
F_4 ( & V_3 -> V_4 . V_5 , V_6 + 1 ) ;
F_5 () ;
}
static void F_6 ( struct V_2 * V_3 )
{
V_3 -> V_4 . V_7 = true ;
F_7 ( & V_3 -> V_8 -> V_9 ) ;
V_3 -> F_6 ( V_3 ) ;
F_8 ( & V_3 -> V_8 -> V_9 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
F_7 ( & V_3 -> V_8 -> V_9 ) ;
V_3 -> F_9 ( V_3 ) ;
F_8 ( & V_3 -> V_8 -> V_9 ) ;
V_3 -> V_4 . V_7 = false ;
}
static void F_10 ( struct V_10 * V_11 )
{
struct V_2 * V_3 =
F_11 ( V_11 , struct V_2 , V_4 ) ;
struct V_12 * V_8 = V_3 -> V_8 ;
F_12 ( & V_11 -> V_13 ) ;
if ( V_11 -> V_14 )
return;
F_13 ( V_8 ) ;
V_11 -> V_14 = true ;
if ( F_14 ( V_8 ) ) {
if ( ! F_15 ( V_3 -> V_15 , & V_8 -> V_16 . V_17 ) )
F_6 ( V_3 ) ;
V_11 -> V_18 = true ;
}
if ( ! V_11 -> V_18 ||
F_15 ( V_3 -> V_15 , & V_8 -> V_16 . V_19 ) )
F_4 ( & V_11 -> V_5 , V_6 + 1 ) ;
F_16 ( V_8 ) ;
}
static void F_17 ( struct V_10 * V_11 )
{
struct V_2 * V_3 =
F_11 ( V_11 , struct V_2 , V_4 ) ;
F_12 ( & V_11 -> V_13 ) ;
if ( ! V_11 -> V_14 )
return;
if ( V_11 -> V_18 ) {
F_9 ( V_3 ) ;
V_11 -> V_18 = false ;
}
F_18 ( V_3 -> V_8 ) ;
V_11 -> V_14 = false ;
}
static inline struct V_20 * F_19 ( struct V_21 * V_22 )
{
return F_11 ( V_22 , struct V_20 , V_22 ) ;
}
static inline void F_20 ( struct V_10 * V_11 ,
struct V_20 * V_23 )
{
F_12 ( & V_11 -> V_13 ) ;
F_21 ( & V_23 -> V_22 , & V_11 -> V_24 ) ;
F_22 ( & V_23 -> V_22 ) ;
F_23 ( V_23 -> V_25 ) ;
}
static bool F_24 ( struct V_2 * V_3 ,
struct V_20 * V_23 )
{
struct V_10 * V_11 = & V_3 -> V_4 ;
struct V_21 * * V_26 , * V_27 , * V_28 ;
bool V_29 ;
T_1 V_30 ;
V_29 = true ;
V_27 = NULL ;
V_28 = NULL ;
V_30 = F_25 ( V_3 ) ;
if ( F_26 ( V_30 , V_23 -> V_30 ) ) {
F_22 ( & V_23 -> V_22 ) ;
return V_29 ;
}
V_26 = & V_11 -> V_24 . V_21 ;
while ( * V_26 ) {
V_27 = * V_26 ;
if ( V_23 -> V_30 == F_19 ( V_27 ) -> V_30 ) {
if ( V_23 -> V_25 -> V_31 > F_19 ( V_27 ) -> V_25 -> V_31 ) {
V_26 = & V_27 -> V_32 ;
V_29 = false ;
} else {
V_26 = & V_27 -> V_33 ;
}
} else if ( F_26 ( V_23 -> V_30 ,
F_19 ( V_27 ) -> V_30 ) ) {
V_26 = & V_27 -> V_32 ;
if ( F_26 ( V_30 , F_19 ( V_27 ) -> V_30 ) )
V_28 = V_27 ;
else
V_29 = false ;
} else {
V_26 = & V_27 -> V_33 ;
}
}
F_27 ( & V_23 -> V_22 , V_27 , V_26 ) ;
F_28 ( & V_23 -> V_22 , & V_11 -> V_24 ) ;
F_29 ( ! V_29 && ! V_11 -> V_34 ) ;
if ( V_28 ) {
struct V_21 * V_35 = F_30 ( V_28 ) ;
F_29 ( ! V_35 && ! V_29 ) ;
if ( V_35 && V_35 != & V_23 -> V_22 ) {
F_29 ( V_29 ) ;
V_11 -> V_36 = F_19 ( V_35 ) ;
F_31 ( V_11 -> V_34 , V_11 -> V_36 -> V_25 ) ;
F_10 ( V_11 ) ;
if ( F_32 ( V_11 -> V_7 ) )
F_23 ( F_19 ( V_35 ) -> V_25 ) ;
}
do {
struct V_20 * V_37 = F_19 ( V_28 ) ;
V_28 = F_33 ( V_28 ) ;
F_20 ( V_11 , V_37 ) ;
} while ( V_28 );
}
if ( V_29 ) {
F_29 ( F_34 ( & V_11 -> V_24 ) != & V_23 -> V_22 ) ;
V_11 -> V_36 = V_23 ;
F_31 ( V_11 -> V_34 , V_23 -> V_25 ) ;
F_10 ( V_11 ) ;
}
F_29 ( ! V_11 -> V_34 ) ;
F_29 ( ! V_11 -> V_36 ) ;
F_29 ( F_34 ( & V_11 -> V_24 ) != & V_11 -> V_36 -> V_22 ) ;
return V_29 ;
}
bool F_35 ( struct V_2 * V_3 ,
struct V_20 * V_23 )
{
struct V_10 * V_11 = & V_3 -> V_4 ;
bool V_29 ;
F_36 ( & V_11 -> V_13 ) ;
V_29 = F_24 ( V_3 , V_23 ) ;
F_37 ( & V_11 -> V_13 ) ;
return V_29 ;
}
void F_38 ( struct V_2 * V_3 )
{
F_4 ( & V_3 -> V_4 . V_5 , V_6 + 1 ) ;
}
static inline bool F_39 ( struct V_21 * V_38 , int V_39 )
{
return V_38 && F_19 ( V_38 ) -> V_25 -> V_31 <= V_39 ;
}
static inline int F_40 ( struct V_10 * V_11 ,
struct V_40 * V_25 )
{
if ( V_25 == V_11 -> V_41 )
return V_42 ;
else
return V_25 -> V_31 ;
}
void F_41 ( struct V_2 * V_3 ,
struct V_20 * V_23 )
{
struct V_10 * V_11 = & V_3 -> V_4 ;
if ( F_42 ( & V_23 -> V_22 ) )
return;
F_36 ( & V_11 -> V_13 ) ;
if ( F_42 ( & V_23 -> V_22 ) )
goto V_43;
if ( V_11 -> V_36 == V_23 ) {
const int V_39 = F_40 ( V_11 , V_23 -> V_25 ) ;
struct V_21 * V_35 ;
F_29 ( V_11 -> V_34 != V_23 -> V_25 ) ;
V_35 = F_30 ( & V_23 -> V_22 ) ;
if ( F_39 ( V_35 , V_39 ) ) {
T_1 V_30 = F_25 ( V_3 ) ;
while ( F_26 ( V_30 , F_19 ( V_35 ) -> V_30 ) ) {
struct V_21 * V_44 = F_30 ( V_35 ) ;
F_20 ( V_11 , F_19 ( V_35 ) ) ;
V_35 = V_44 ;
if ( ! F_39 ( V_35 , V_39 ) )
break;
}
}
if ( V_35 ) {
V_11 -> V_36 = F_19 ( V_35 ) ;
F_31 ( V_11 -> V_34 , V_11 -> V_36 -> V_25 ) ;
if ( V_11 -> V_36 -> V_30 != V_23 -> V_30 )
F_10 ( V_11 ) ;
F_23 ( V_11 -> V_34 ) ;
} else {
V_11 -> V_36 = NULL ;
F_43 ( V_11 -> V_34 , NULL ) ;
F_17 ( V_11 ) ;
}
} else {
F_29 ( F_34 ( & V_11 -> V_24 ) == & V_23 -> V_22 ) ;
}
F_29 ( F_42 ( & V_23 -> V_22 ) ) ;
F_21 ( & V_23 -> V_22 , & V_11 -> V_24 ) ;
V_43:
F_29 ( V_11 -> V_36 == V_23 ) ;
F_29 ( F_34 ( & V_11 -> V_24 ) !=
( V_11 -> V_36 ? & V_11 -> V_36 -> V_22 : NULL ) ) ;
F_29 ( ! V_11 -> V_34 ^ F_44 ( & V_11 -> V_24 ) ) ;
F_37 ( & V_11 -> V_13 ) ;
}
static bool F_45 ( struct V_45 * V_46 )
{
if ( ! V_46 )
return false ;
if ( F_46 ( & V_46 -> V_47 . V_23 ) )
return true ;
if ( F_47 ( V_46 ) )
return true ;
return false ;
}
static struct V_45 * F_48 ( struct V_21 * V_38 )
{
return F_11 ( V_38 , struct V_45 , V_47 . V_22 ) ;
}
static void F_49 ( void )
{
struct V_48 V_49 = { . V_50 = 1 } ;
F_50 ( V_51 , V_52 , & V_49 ) ;
}
static int F_51 ( void * V_53 )
{
struct V_2 * V_3 = V_53 ;
struct V_10 * V_11 = & V_3 -> V_4 ;
struct V_45 * V_46 ;
F_49 () ;
do {
F_52 ( V_54 ) ;
V_46 = F_32 ( V_11 -> V_55 ) ;
if ( F_45 ( V_46 ) ) {
F_41 ( V_3 ,
& V_46 -> V_47 . V_23 ) ;
F_36 ( & V_11 -> V_13 ) ;
if ( V_46 == V_11 -> V_55 ) {
struct V_21 * V_38 =
F_30 ( & V_46 -> V_47 . V_22 ) ;
V_11 -> V_55 = V_38 ? F_48 ( V_38 ) : NULL ;
}
F_21 ( & V_46 -> V_47 . V_22 , & V_11 -> V_56 ) ;
F_37 ( & V_11 -> V_13 ) ;
F_53 ( V_46 ) ;
} else {
if ( F_54 () )
break;
F_55 () ;
}
} while ( 1 );
F_56 ( V_57 ) ;
return 0 ;
}
void F_57 ( struct V_45 * V_46 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
struct V_10 * V_11 = & V_3 -> V_4 ;
struct V_21 * V_27 , * * V_26 ;
bool V_29 , V_58 ;
if ( F_58 ( F_32 ( V_46 -> V_47 . V_23 . V_25 ) ) )
return;
F_36 ( & V_11 -> V_13 ) ;
if ( F_58 ( V_46 -> V_47 . V_23 . V_25 ) ) {
V_58 = false ;
goto V_59;
}
V_46 -> V_47 . V_23 . V_25 = V_11 -> V_41 ;
V_46 -> V_47 . V_23 . V_30 = V_46 -> V_30 ;
F_59 ( V_46 ) ;
V_58 = F_24 ( V_3 , & V_46 -> V_47 . V_23 ) ;
V_27 = NULL ;
V_29 = true ;
V_26 = & V_11 -> V_56 . V_21 ;
while ( * V_26 ) {
V_27 = * V_26 ;
if ( F_26 ( V_46 -> V_30 ,
F_48 ( V_27 ) -> V_30 ) ) {
V_26 = & V_27 -> V_32 ;
V_29 = false ;
} else {
V_26 = & V_27 -> V_33 ;
}
}
F_27 ( & V_46 -> V_47 . V_22 , V_27 , V_26 ) ;
F_28 ( & V_46 -> V_47 . V_22 , & V_11 -> V_56 ) ;
if ( V_29 )
F_31 ( V_11 -> V_55 , V_46 ) ;
V_59:
F_37 ( & V_11 -> V_13 ) ;
if ( V_58 )
F_23 ( V_11 -> V_41 ) ;
}
int F_60 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = & V_3 -> V_4 ;
struct V_40 * V_25 ;
F_61 ( & V_11 -> V_13 ) ;
F_62 ( & V_11 -> V_5 ,
F_1 ,
( unsigned long ) V_3 ) ;
V_25 = F_63 ( F_51 , V_3 ,
L_1 , V_3 -> V_15 ) ;
if ( F_64 ( V_25 ) )
return F_65 ( V_25 ) ;
V_11 -> V_41 = V_25 ;
return 0 ;
}
void F_66 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = & V_3 -> V_4 ;
if ( ! F_67 ( V_11 -> V_41 ) )
F_68 ( V_11 -> V_41 ) ;
F_69 ( & V_11 -> V_5 ) ;
}
unsigned int F_70 ( struct V_12 * V_8 )
{
struct V_2 * V_3 ;
unsigned int V_60 = 0 ;
F_2 () ;
F_71 (engine, i915)
if ( F_58 ( F_3 ( V_3 ) ) )
V_60 |= F_72 ( V_3 ) ;
F_5 () ;
return V_60 ;
}
unsigned int F_73 ( struct V_12 * V_8 )
{
struct V_2 * V_3 ;
unsigned int V_60 = 0 ;
F_71 (engine, i915) {
if ( F_58 ( F_32 ( V_3 -> V_4 . V_55 ) ) ) {
F_23 ( V_3 -> V_4 . V_41 ) ;
V_60 |= F_72 ( V_3 ) ;
}
}
return V_60 ;
}
