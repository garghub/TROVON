static unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned int V_5 = 0 ;
F_2 ( & V_2 -> V_6 ) ;
V_4 = V_2 -> V_7 ;
if ( V_4 ) {
V_5 = V_8 ;
if ( F_3 ( V_4 -> V_9 ) )
V_5 |= V_10 ;
}
return V_5 ;
}
unsigned int F_4 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
unsigned long V_14 ;
unsigned int V_5 ;
F_5 ( & V_2 -> V_6 , V_14 ) ;
V_5 = F_1 ( V_2 ) ;
F_6 ( & V_2 -> V_6 , V_14 ) ;
return V_5 ;
}
static unsigned long F_7 ( void )
{
return F_8 ( V_15 + V_16 ) ;
}
static T_1 void F_9 ( struct V_11 * V_12 )
{
F_10 ( L_1 ,
V_12 -> V_17 , F_11 ( 0 ) ,
F_12 ( F_13 ( V_18 ,
& V_12 -> V_19 ) ) ,
F_14 ( V_12 ) ,
F_15 ( V_12 ) ) ;
F_16 ( V_12 -> V_20 , & V_12 -> V_21 -> V_22 . V_23 ) ;
}
static void F_17 ( unsigned long V_24 )
{
struct V_11 * V_12 = (struct V_11 * ) V_24 ;
struct V_1 * V_2 = & V_12 -> V_13 ;
if ( ! V_2 -> V_25 )
return;
if ( V_2 -> V_26 != F_18 ( & V_12 -> V_27 ) ) {
V_2 -> V_26 = F_18 ( & V_12 -> V_27 ) ;
F_19 ( & V_2 -> V_28 , F_7 () ) ;
return;
}
if ( F_4 ( V_12 ) & V_10 ) {
F_9 ( V_12 ) ;
F_19 ( & V_12 -> V_13 . V_29 , V_15 + 1 ) ;
} else {
F_19 ( & V_2 -> V_28 , F_7 () ) ;
}
}
static void F_20 ( unsigned long V_24 )
{
struct V_11 * V_12 = (struct V_11 * ) V_24 ;
struct V_1 * V_2 = & V_12 -> V_13 ;
F_21 ( & V_2 -> V_6 ) ;
if ( ! F_1 ( V_2 ) )
F_22 ( V_12 ) ;
F_23 ( & V_2 -> V_6 ) ;
if ( ! V_2 -> V_25 )
return;
F_19 ( & V_2 -> V_29 , V_15 + 1 ) ;
F_24 ( V_12 -> V_21 ) ;
}
static void F_25 ( struct V_11 * V_12 )
{
F_16 ( V_18 , & V_12 -> V_19 ) ;
F_26 ( & V_12 -> V_21 -> V_6 ) ;
V_12 -> F_25 ( V_12 ) ;
F_27 ( & V_12 -> V_21 -> V_6 ) ;
}
static void F_28 ( struct V_11 * V_12 )
{
F_26 ( & V_12 -> V_21 -> V_6 ) ;
V_12 -> F_28 ( V_12 ) ;
F_27 ( & V_12 -> V_21 -> V_6 ) ;
}
void F_22 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
F_2 ( & V_2 -> V_6 ) ;
F_29 ( V_2 -> V_7 ) ;
if ( V_2 -> V_30 ) {
F_28 ( V_12 ) ;
V_2 -> V_30 = false ;
}
V_2 -> V_25 = false ;
}
void F_30 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
struct V_3 * V_4 , * V_31 , * V_32 ;
if ( ! V_2 -> V_25 )
return;
F_21 ( & V_2 -> V_33 ) ;
F_26 ( & V_2 -> V_6 ) ;
V_32 = F_31 ( & V_2 -> V_7 ) ;
F_22 ( V_12 ) ;
F_27 ( & V_2 -> V_6 ) ;
F_32 (wait, n, &b->waiters, node) {
F_33 ( & V_4 -> V_34 ) ;
if ( F_3 ( V_4 -> V_9 ) && V_4 == V_32 )
F_9 ( V_12 ) ;
}
V_2 -> V_35 = V_36 ;
F_23 ( & V_2 -> V_33 ) ;
}
static bool F_34 ( const struct V_1 * V_2 )
{
const struct V_11 * V_12 =
F_35 ( V_2 , struct V_11 , V_13 ) ;
if ( ! F_13 ( V_12 -> V_20 , & V_12 -> V_21 -> V_22 . V_23 ) )
return false ;
return F_18 ( & V_12 -> V_27 ) == V_2 -> V_26 ;
}
static void F_36 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_30 || F_34 ( V_2 ) )
F_19 ( & V_2 -> V_29 , V_15 + 1 ) ;
else
F_19 ( & V_2 -> V_28 , F_7 () ) ;
}
static bool F_37 ( struct V_1 * V_2 )
{
struct V_11 * V_12 =
F_35 ( V_2 , struct V_11 , V_13 ) ;
struct V_37 * V_21 = V_12 -> V_21 ;
F_2 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_25 )
return false ;
V_2 -> V_25 = true ;
F_29 ( V_2 -> V_30 ) ;
if ( F_38 ( V_2 -> V_38 ) ) {
return true ;
}
if ( F_39 ( V_21 ) ) {
if ( ! F_13 ( V_12 -> V_20 , & V_21 -> V_22 . V_39 ) )
F_25 ( V_12 ) ;
V_2 -> V_30 = true ;
}
F_36 ( V_2 ) ;
return true ;
}
static inline struct V_3 * F_40 ( struct V_40 * V_34 )
{
return F_41 ( V_34 , struct V_3 , V_34 ) ;
}
static inline void F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_33 ) ;
F_29 ( V_2 -> V_7 == V_4 ) ;
F_43 ( & V_4 -> V_34 , & V_2 -> V_35 ) ;
F_33 ( & V_4 -> V_34 ) ;
F_3 ( V_4 -> V_9 ) ;
}
static inline void F_44 ( struct V_11 * V_12 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
F_26 ( & V_2 -> V_6 ) ;
F_29 ( ! V_2 -> V_25 ) ;
F_29 ( ! V_2 -> V_7 ) ;
V_2 -> V_7 = F_40 ( V_41 ) ;
F_27 ( & V_2 -> V_6 ) ;
if ( V_41 )
F_3 ( F_40 ( V_41 ) -> V_9 ) ;
}
static bool F_45 ( struct V_11 * V_12 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
struct V_40 * * V_42 , * V_43 , * V_44 ;
bool V_32 , V_45 ;
T_2 V_46 ;
V_45 = false ;
V_32 = true ;
V_43 = NULL ;
V_44 = NULL ;
V_46 = F_14 ( V_12 ) ;
if ( F_46 ( V_46 , V_4 -> V_46 ) ) {
F_33 ( & V_4 -> V_34 ) ;
return V_32 ;
}
V_42 = & V_2 -> V_35 . V_40 ;
while ( * V_42 ) {
V_43 = * V_42 ;
if ( V_4 -> V_46 == F_40 ( V_43 ) -> V_46 ) {
if ( V_4 -> V_9 -> V_47 > F_40 ( V_43 ) -> V_9 -> V_47 ) {
V_42 = & V_43 -> V_48 ;
V_32 = false ;
} else {
V_42 = & V_43 -> V_49 ;
}
} else if ( F_46 ( V_4 -> V_46 ,
F_40 ( V_43 ) -> V_46 ) ) {
V_42 = & V_43 -> V_48 ;
if ( F_46 ( V_46 , F_40 ( V_43 ) -> V_46 ) )
V_44 = V_43 ;
else
V_32 = false ;
} else {
V_42 = & V_43 -> V_49 ;
}
}
F_47 ( & V_4 -> V_34 , V_43 , V_42 ) ;
F_48 ( & V_4 -> V_34 , & V_2 -> V_35 ) ;
if ( V_32 ) {
F_26 ( & V_2 -> V_6 ) ;
V_2 -> V_7 = V_4 ;
V_45 = F_37 ( V_2 ) ;
F_27 ( & V_2 -> V_6 ) ;
}
if ( V_44 ) {
if ( ! V_32 ) {
struct V_40 * V_41 = F_49 ( V_44 ) ;
F_29 ( V_41 == & V_4 -> V_34 ) ;
F_44 ( V_12 , V_41 ) ;
}
do {
struct V_3 * V_50 = F_40 ( V_44 ) ;
V_44 = F_50 ( V_44 ) ;
F_42 ( V_2 , V_50 ) ;
} while ( V_44 );
}
F_29 ( ! V_2 -> V_7 ) ;
F_29 ( ! V_2 -> V_25 ) ;
F_29 ( F_51 ( & V_2 -> V_35 ) != & V_2 -> V_7 -> V_34 ) ;
return V_45 ;
}
bool F_52 ( struct V_11 * V_12 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
bool V_45 ;
F_21 ( & V_2 -> V_33 ) ;
V_45 = F_45 ( V_12 , V_4 ) ;
F_23 ( & V_2 -> V_33 ) ;
if ( V_45 )
return V_45 ;
return F_46 ( F_14 ( V_12 ) ,
V_4 -> V_46 - 1 ) ;
}
static inline bool F_53 ( struct V_40 * V_51 , int V_52 )
{
return V_51 && F_40 ( V_51 ) -> V_9 -> V_47 <= V_52 ;
}
static inline int F_54 ( struct V_1 * V_2 ,
struct V_53 * V_9 )
{
if ( V_9 == V_2 -> V_54 )
return V_55 ;
else
return V_9 -> V_47 ;
}
static void F_55 ( struct V_11 * V_12 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
F_2 ( & V_2 -> V_33 ) ;
if ( F_56 ( & V_4 -> V_34 ) )
goto V_56;
if ( V_2 -> V_7 == V_4 ) {
const int V_52 = F_54 ( V_2 , V_4 -> V_9 ) ;
struct V_40 * V_41 ;
V_41 = F_49 ( & V_4 -> V_34 ) ;
if ( F_53 ( V_41 , V_52 ) ) {
T_2 V_46 = F_14 ( V_12 ) ;
while ( F_46 ( V_46 , F_40 ( V_41 ) -> V_46 ) ) {
struct V_40 * V_31 = F_49 ( V_41 ) ;
F_42 ( V_2 , F_40 ( V_41 ) ) ;
V_41 = V_31 ;
if ( ! F_53 ( V_41 , V_52 ) )
break;
}
}
F_44 ( V_12 , V_41 ) ;
} else {
F_29 ( F_51 ( & V_2 -> V_35 ) == & V_4 -> V_34 ) ;
}
F_29 ( F_56 ( & V_4 -> V_34 ) ) ;
F_43 ( & V_4 -> V_34 , & V_2 -> V_35 ) ;
V_56:
F_29 ( V_2 -> V_7 == V_4 ) ;
F_29 ( F_51 ( & V_2 -> V_35 ) !=
( V_2 -> V_7 ? & V_2 -> V_7 -> V_34 : NULL ) ) ;
}
void F_57 ( struct V_11 * V_12 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
if ( F_56 ( & V_4 -> V_34 ) ) {
F_29 ( F_58 ( V_2 -> V_7 ) == V_4 ) ;
return;
}
F_21 ( & V_2 -> V_33 ) ;
F_55 ( V_12 , V_4 ) ;
F_23 ( & V_2 -> V_33 ) ;
}
static bool F_59 ( const struct V_57 * V_58 )
{
return F_60 ( & V_58 -> V_59 . V_4 , V_58 ) ;
}
static bool F_61 ( const struct V_57 * V_58 )
{
if ( ! V_58 )
return false ;
if ( F_62 ( & V_58 -> V_59 . V_4 ) )
return F_59 ( V_58 ) ;
if ( F_63 ( V_58 ) )
return true ;
return false ;
}
static struct V_57 * F_64 ( struct V_40 * V_51 )
{
return F_41 ( V_51 , struct V_57 , V_59 . V_34 ) ;
}
static void F_65 ( void )
{
struct V_60 V_61 = { . V_62 = 1 } ;
F_66 ( V_63 , V_64 , & V_61 ) ;
}
static int F_67 ( void * V_65 )
{
struct V_11 * V_12 = V_65 ;
struct V_1 * V_2 = & V_12 -> V_13 ;
struct V_57 * V_58 ;
F_65 () ;
do {
bool V_66 = true ;
F_68 ( V_67 ) ;
F_69 () ;
V_58 = F_70 ( V_2 -> V_68 ) ;
if ( V_58 )
V_58 = F_71 ( V_58 ) ;
F_72 () ;
if ( F_61 ( V_58 ) ) {
F_73 () ;
F_74 ( & V_58 -> V_69 ) ;
F_75 () ;
F_21 ( & V_2 -> V_33 ) ;
F_55 ( V_12 ,
& V_58 -> V_59 . V_4 ) ;
if ( V_58 == F_76 ( V_2 -> V_68 ) ) {
struct V_40 * V_51 =
F_49 ( & V_58 -> V_59 . V_34 ) ;
F_77 ( V_2 -> V_68 ,
V_51 ? F_64 ( V_51 ) : NULL ) ;
}
F_43 ( & V_58 -> V_59 . V_34 , & V_2 -> V_70 ) ;
F_33 ( & V_58 -> V_59 . V_34 ) ;
F_23 ( & V_2 -> V_33 ) ;
F_78 ( V_58 ) ;
V_66 = F_79 () ;
}
if ( F_80 ( V_66 ) ) {
F_81 ( V_71 ) ;
if ( F_82 () )
F_83 () ;
if ( F_84 () ) {
F_29 ( V_58 ) ;
break;
}
if ( V_58 )
F_85 ( & V_58 -> V_72 , & V_71 ) ;
F_86 () ;
if ( V_58 )
F_87 ( & V_58 -> V_72 , & V_71 ) ;
}
F_78 ( V_58 ) ;
} while ( 1 );
F_88 ( V_73 ) ;
return 0 ;
}
void F_89 ( struct V_57 * V_58 ,
bool V_74 )
{
struct V_11 * V_12 = V_58 -> V_12 ;
struct V_1 * V_2 = & V_12 -> V_13 ;
T_2 V_46 ;
F_29 ( ! F_90 () ) ;
F_2 ( & V_58 -> V_75 ) ;
V_46 = F_91 ( V_58 ) ;
if ( ! V_46 )
return;
V_58 -> V_59 . V_4 . V_9 = V_2 -> V_54 ;
V_58 -> V_59 . V_4 . V_58 = V_58 ;
V_58 -> V_59 . V_4 . V_46 = V_46 ;
F_92 ( V_58 ) ;
F_26 ( & V_2 -> V_33 ) ;
V_74 &= F_45 ( V_12 , & V_58 -> V_59 . V_4 ) ;
if ( ! F_93 ( V_58 , V_46 ) ) {
struct V_40 * V_43 , * * V_42 ;
bool V_32 ;
V_43 = NULL ;
V_32 = true ;
V_42 = & V_2 -> V_70 . V_40 ;
while ( * V_42 ) {
V_43 = * V_42 ;
if ( F_46 ( V_46 ,
F_64 ( V_43 ) -> V_59 . V_4 . V_46 ) ) {
V_42 = & V_43 -> V_48 ;
V_32 = false ;
} else {
V_42 = & V_43 -> V_49 ;
}
}
F_47 ( & V_58 -> V_59 . V_34 , V_43 , V_42 ) ;
F_48 ( & V_58 -> V_59 . V_34 , & V_2 -> V_70 ) ;
if ( V_32 )
F_77 ( V_2 -> V_68 , V_58 ) ;
} else {
F_55 ( V_12 , & V_58 -> V_59 . V_4 ) ;
F_78 ( V_58 ) ;
V_74 = false ;
}
F_27 ( & V_2 -> V_33 ) ;
if ( V_74 )
F_3 ( V_2 -> V_54 ) ;
}
void F_94 ( struct V_57 * V_58 )
{
struct V_11 * V_12 = V_58 -> V_12 ;
struct V_1 * V_2 = & V_12 -> V_13 ;
F_29 ( ! F_90 () ) ;
F_2 ( & V_58 -> V_75 ) ;
F_29 ( ! V_58 -> V_59 . V_4 . V_46 ) ;
F_26 ( & V_2 -> V_33 ) ;
if ( ! F_56 ( & V_58 -> V_59 . V_34 ) ) {
if ( V_58 == F_76 ( V_2 -> V_68 ) ) {
struct V_40 * V_51 =
F_49 ( & V_58 -> V_59 . V_34 ) ;
F_77 ( V_2 -> V_68 ,
V_51 ? F_64 ( V_51 ) : NULL ) ;
}
F_43 ( & V_58 -> V_59 . V_34 , & V_2 -> V_70 ) ;
F_33 ( & V_58 -> V_59 . V_34 ) ;
F_78 ( V_58 ) ;
}
F_55 ( V_12 , & V_58 -> V_59 . V_4 ) ;
F_27 ( & V_2 -> V_33 ) ;
V_58 -> V_59 . V_4 . V_46 = 0 ;
}
int F_95 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
struct V_53 * V_9 ;
F_96 ( & V_2 -> V_33 ) ;
F_96 ( & V_2 -> V_6 ) ;
F_97 ( & V_2 -> V_29 ,
F_20 ,
( unsigned long ) V_12 ) ;
F_97 ( & V_2 -> V_28 ,
F_17 ,
( unsigned long ) V_12 ) ;
V_9 = F_98 ( F_67 , V_12 ,
L_2 , V_12 -> V_20 ) ;
if ( F_99 ( V_9 ) )
return F_100 ( V_9 ) ;
V_2 -> V_54 = V_9 ;
return 0 ;
}
static void F_101 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
F_102 ( & V_2 -> V_28 ) ;
F_102 ( & V_2 -> V_29 ) ;
F_103 ( V_12 -> V_20 , & V_12 -> V_21 -> V_22 . V_23 ) ;
}
void F_104 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
F_101 ( V_12 ) ;
F_21 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_30 )
F_25 ( V_12 ) ;
else
F_28 ( V_12 ) ;
F_103 ( V_18 , & V_12 -> V_19 ) ;
if ( V_2 -> V_25 )
F_36 ( V_2 ) ;
F_23 ( & V_2 -> V_6 ) ;
}
void F_105 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
F_106 ( F_58 ( V_2 -> V_7 ) ) ;
F_106 ( ! F_107 ( & V_2 -> V_35 ) ) ;
F_106 ( F_76 ( V_2 -> V_68 ) ) ;
F_106 ( ! F_107 ( & V_2 -> V_70 ) ) ;
if ( ! F_108 ( V_2 -> V_54 ) )
F_109 ( V_2 -> V_54 ) ;
F_101 ( V_12 ) ;
}
bool F_110 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
bool V_76 = false ;
F_21 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_7 ) {
F_3 ( V_2 -> V_7 -> V_9 ) ;
V_76 = true ;
}
if ( F_76 ( V_2 -> V_68 ) ) {
F_3 ( V_2 -> V_54 ) ;
V_76 = true ;
}
F_23 ( & V_2 -> V_33 ) ;
return V_76 ;
}
