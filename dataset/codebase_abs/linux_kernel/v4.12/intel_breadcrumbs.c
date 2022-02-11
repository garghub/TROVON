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
& V_12 -> V_19 ) ) ) ;
F_14 ( V_12 -> V_20 , & V_12 -> V_21 -> V_22 . V_23 ) ;
}
static void F_15 ( unsigned long V_24 )
{
struct V_11 * V_12 = (struct V_11 * ) V_24 ;
struct V_1 * V_2 = & V_12 -> V_13 ;
if ( ! V_2 -> V_25 )
return;
if ( V_2 -> V_26 != F_16 ( & V_12 -> V_27 ) ) {
V_2 -> V_26 = F_16 ( & V_12 -> V_27 ) ;
F_17 ( & V_2 -> V_28 , F_7 () ) ;
return;
}
if ( F_4 ( V_12 ) & V_10 ) {
F_9 ( V_12 ) ;
F_17 ( & V_12 -> V_13 . V_29 , V_15 + 1 ) ;
} else {
F_17 ( & V_2 -> V_28 , F_7 () ) ;
}
}
static void F_18 ( unsigned long V_24 )
{
struct V_11 * V_12 = (struct V_11 * ) V_24 ;
struct V_1 * V_2 = & V_12 -> V_13 ;
F_19 ( & V_2 -> V_6 ) ;
if ( ! F_1 ( V_2 ) )
F_20 ( V_12 ) ;
F_21 ( & V_2 -> V_6 ) ;
if ( ! V_2 -> V_25 )
return;
F_17 ( & V_2 -> V_29 , V_15 + 1 ) ;
F_22 ( V_12 -> V_21 ) ;
}
static void F_23 ( struct V_11 * V_12 )
{
F_14 ( V_18 , & V_12 -> V_19 ) ;
F_24 ( & V_12 -> V_21 -> V_6 ) ;
V_12 -> F_23 ( V_12 ) ;
F_25 ( & V_12 -> V_21 -> V_6 ) ;
}
static void F_26 ( struct V_11 * V_12 )
{
F_24 ( & V_12 -> V_21 -> V_6 ) ;
V_12 -> F_26 ( V_12 ) ;
F_25 ( & V_12 -> V_21 -> V_6 ) ;
}
void F_20 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
F_2 ( & V_2 -> V_6 ) ;
F_27 ( V_2 -> V_7 ) ;
if ( V_2 -> V_30 ) {
F_26 ( V_12 ) ;
V_2 -> V_30 = false ;
}
V_2 -> V_25 = false ;
}
void F_28 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
struct V_3 * V_4 , * V_31 , * V_32 ;
if ( ! V_2 -> V_25 )
return;
F_19 ( & V_2 -> V_33 ) ;
F_24 ( & V_2 -> V_6 ) ;
V_32 = F_29 ( & V_2 -> V_7 ) ;
F_20 ( V_12 ) ;
F_25 ( & V_2 -> V_6 ) ;
F_30 (wait, n, &b->waiters, node) {
F_31 ( & V_4 -> V_34 ) ;
if ( F_3 ( V_4 -> V_9 ) && V_4 == V_32 )
F_9 ( V_12 ) ;
}
V_2 -> V_35 = V_36 ;
F_21 ( & V_2 -> V_33 ) ;
}
static bool F_32 ( const struct V_1 * V_2 )
{
const struct V_11 * V_12 =
F_33 ( V_2 , struct V_11 , V_13 ) ;
if ( ! F_13 ( V_12 -> V_20 , & V_12 -> V_21 -> V_22 . V_23 ) )
return false ;
return F_16 ( & V_12 -> V_27 ) == V_2 -> V_26 ;
}
static void F_34 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_30 || F_32 ( V_2 ) )
F_17 ( & V_2 -> V_29 , V_15 + 1 ) ;
else
F_17 ( & V_2 -> V_28 , F_7 () ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_11 * V_12 =
F_33 ( V_2 , struct V_11 , V_13 ) ;
struct V_37 * V_21 = V_12 -> V_21 ;
F_2 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_25 )
return;
V_2 -> V_25 = true ;
F_27 ( V_2 -> V_30 ) ;
if ( F_36 ( V_2 -> V_38 ) ) {
return;
}
if ( F_37 ( V_21 ) ) {
if ( ! F_13 ( V_12 -> V_20 , & V_21 -> V_22 . V_39 ) )
F_23 ( V_12 ) ;
V_2 -> V_30 = true ;
}
F_34 ( V_2 ) ;
}
static inline struct V_3 * F_38 ( struct V_40 * V_34 )
{
return F_39 ( V_34 , struct V_3 , V_34 ) ;
}
static inline void F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_33 ) ;
F_27 ( V_2 -> V_7 == V_4 ) ;
F_41 ( & V_4 -> V_34 , & V_2 -> V_35 ) ;
F_31 ( & V_4 -> V_34 ) ;
F_3 ( V_4 -> V_9 ) ;
}
static inline void F_42 ( struct V_11 * V_12 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
F_24 ( & V_2 -> V_6 ) ;
F_27 ( ! V_2 -> V_25 ) ;
F_27 ( ! V_2 -> V_7 ) ;
V_2 -> V_7 = F_38 ( V_41 ) ;
F_25 ( & V_2 -> V_6 ) ;
if ( V_41 )
F_3 ( F_38 ( V_41 ) -> V_9 ) ;
}
static bool F_43 ( struct V_11 * V_12 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
struct V_40 * * V_42 , * V_43 , * V_44 ;
bool V_32 ;
T_2 V_45 ;
V_32 = true ;
V_43 = NULL ;
V_44 = NULL ;
V_45 = F_44 ( V_12 ) ;
if ( F_45 ( V_45 , V_4 -> V_45 ) ) {
F_31 ( & V_4 -> V_34 ) ;
return V_32 ;
}
V_42 = & V_2 -> V_35 . V_40 ;
while ( * V_42 ) {
V_43 = * V_42 ;
if ( V_4 -> V_45 == F_38 ( V_43 ) -> V_45 ) {
if ( V_4 -> V_9 -> V_46 > F_38 ( V_43 ) -> V_9 -> V_46 ) {
V_42 = & V_43 -> V_47 ;
V_32 = false ;
} else {
V_42 = & V_43 -> V_48 ;
}
} else if ( F_45 ( V_4 -> V_45 ,
F_38 ( V_43 ) -> V_45 ) ) {
V_42 = & V_43 -> V_47 ;
if ( F_45 ( V_45 , F_38 ( V_43 ) -> V_45 ) )
V_44 = V_43 ;
else
V_32 = false ;
} else {
V_42 = & V_43 -> V_48 ;
}
}
F_46 ( & V_4 -> V_34 , V_43 , V_42 ) ;
F_47 ( & V_4 -> V_34 , & V_2 -> V_35 ) ;
if ( V_32 ) {
F_24 ( & V_2 -> V_6 ) ;
V_2 -> V_7 = V_4 ;
F_35 ( V_2 ) ;
F_25 ( & V_2 -> V_6 ) ;
}
if ( V_44 ) {
if ( ! V_32 ) {
struct V_40 * V_41 = F_48 ( V_44 ) ;
F_27 ( V_41 == & V_4 -> V_34 ) ;
F_42 ( V_12 , V_41 ) ;
}
do {
struct V_3 * V_49 = F_38 ( V_44 ) ;
V_44 = F_49 ( V_44 ) ;
F_40 ( V_2 , V_49 ) ;
} while ( V_44 );
}
F_27 ( ! V_2 -> V_7 ) ;
F_27 ( ! V_2 -> V_25 ) ;
F_27 ( F_50 ( & V_2 -> V_35 ) != & V_2 -> V_7 -> V_34 ) ;
return V_32 ;
}
bool F_51 ( struct V_11 * V_12 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
bool V_32 ;
F_19 ( & V_2 -> V_33 ) ;
V_32 = F_43 ( V_12 , V_4 ) ;
F_21 ( & V_2 -> V_33 ) ;
return V_32 ;
}
static inline bool F_52 ( struct V_40 * V_50 , int V_51 )
{
return V_50 && F_38 ( V_50 ) -> V_9 -> V_46 <= V_51 ;
}
static inline int F_53 ( struct V_1 * V_2 ,
struct V_52 * V_9 )
{
if ( V_9 == V_2 -> V_53 )
return V_54 ;
else
return V_9 -> V_46 ;
}
static void F_54 ( struct V_11 * V_12 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
F_2 ( & V_2 -> V_33 ) ;
if ( F_55 ( & V_4 -> V_34 ) )
goto V_55;
if ( V_2 -> V_7 == V_4 ) {
const int V_51 = F_53 ( V_2 , V_4 -> V_9 ) ;
struct V_40 * V_41 ;
V_41 = F_48 ( & V_4 -> V_34 ) ;
if ( F_52 ( V_41 , V_51 ) ) {
T_2 V_45 = F_44 ( V_12 ) ;
while ( F_45 ( V_45 , F_38 ( V_41 ) -> V_45 ) ) {
struct V_40 * V_31 = F_48 ( V_41 ) ;
F_40 ( V_2 , F_38 ( V_41 ) ) ;
V_41 = V_31 ;
if ( ! F_52 ( V_41 , V_51 ) )
break;
}
}
F_42 ( V_12 , V_41 ) ;
} else {
F_27 ( F_50 ( & V_2 -> V_35 ) == & V_4 -> V_34 ) ;
}
F_27 ( F_55 ( & V_4 -> V_34 ) ) ;
F_41 ( & V_4 -> V_34 , & V_2 -> V_35 ) ;
V_55:
F_27 ( V_2 -> V_7 == V_4 ) ;
F_27 ( F_50 ( & V_2 -> V_35 ) !=
( V_2 -> V_7 ? & V_2 -> V_7 -> V_34 : NULL ) ) ;
}
void F_56 ( struct V_11 * V_12 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
if ( F_55 ( & V_4 -> V_34 ) ) {
F_27 ( F_57 ( V_2 -> V_7 ) == V_4 ) ;
return;
}
F_19 ( & V_2 -> V_33 ) ;
F_54 ( V_12 , V_4 ) ;
F_21 ( & V_2 -> V_33 ) ;
}
static bool F_58 ( const struct V_56 * V_57 )
{
return F_59 ( & V_57 -> V_58 . V_4 , V_57 ) ;
}
static bool F_60 ( const struct V_56 * V_57 )
{
if ( ! V_57 )
return false ;
if ( F_61 ( & V_57 -> V_58 . V_4 ) )
return F_58 ( V_57 ) ;
if ( F_62 ( V_57 ) )
return true ;
return false ;
}
static struct V_56 * F_63 ( struct V_40 * V_50 )
{
return F_39 ( V_50 , struct V_56 , V_58 . V_34 ) ;
}
static void F_64 ( void )
{
struct V_59 V_60 = { . V_61 = 1 } ;
F_65 ( V_62 , V_63 , & V_60 ) ;
}
static int F_66 ( void * V_64 )
{
struct V_11 * V_12 = V_64 ;
struct V_1 * V_2 = & V_12 -> V_13 ;
struct V_56 * V_57 ;
F_64 () ;
do {
bool V_65 = true ;
F_67 ( V_66 ) ;
F_68 () ;
V_57 = F_69 ( V_2 -> V_67 ) ;
if ( V_57 )
V_57 = F_70 ( V_57 ) ;
F_71 () ;
if ( F_60 ( V_57 ) ) {
F_72 () ;
F_73 ( & V_57 -> V_68 ) ;
F_74 () ;
F_19 ( & V_2 -> V_33 ) ;
F_54 ( V_12 ,
& V_57 -> V_58 . V_4 ) ;
if ( V_57 == F_75 ( V_2 -> V_67 ) ) {
struct V_40 * V_50 =
F_48 ( & V_57 -> V_58 . V_34 ) ;
F_76 ( V_2 -> V_67 ,
V_50 ? F_63 ( V_50 ) : NULL ) ;
}
F_41 ( & V_57 -> V_58 . V_34 , & V_2 -> V_69 ) ;
F_31 ( & V_57 -> V_58 . V_34 ) ;
F_21 ( & V_2 -> V_33 ) ;
F_77 ( V_57 ) ;
V_65 = F_78 () ;
}
if ( F_79 ( V_65 ) ) {
F_80 ( V_70 ) ;
if ( F_81 () )
F_82 () ;
if ( F_83 () ) {
F_27 ( V_57 ) ;
break;
}
if ( V_57 )
F_84 ( & V_57 -> V_71 , & V_70 ) ;
F_85 () ;
if ( V_57 )
F_86 ( & V_57 -> V_71 , & V_70 ) ;
}
F_77 ( V_57 ) ;
} while ( 1 );
F_87 ( V_72 ) ;
return 0 ;
}
void F_88 ( struct V_56 * V_57 )
{
struct V_11 * V_12 = V_57 -> V_12 ;
struct V_1 * V_2 = & V_12 -> V_13 ;
struct V_40 * V_43 , * * V_42 ;
bool V_32 , V_73 ;
T_2 V_45 ;
F_27 ( ! F_89 () ) ;
F_2 ( & V_57 -> V_74 ) ;
V_45 = F_90 ( V_57 ) ;
if ( ! V_45 )
return;
V_57 -> V_58 . V_4 . V_9 = V_2 -> V_53 ;
V_57 -> V_58 . V_4 . V_57 = V_57 ;
V_57 -> V_58 . V_4 . V_45 = V_45 ;
F_91 ( V_57 ) ;
F_24 ( & V_2 -> V_33 ) ;
V_73 = F_43 ( V_12 , & V_57 -> V_58 . V_4 ) ;
V_43 = NULL ;
V_32 = true ;
V_42 = & V_2 -> V_69 . V_40 ;
while ( * V_42 ) {
V_43 = * V_42 ;
if ( F_45 ( V_45 ,
F_63 ( V_43 ) -> V_58 . V_4 . V_45 ) ) {
V_42 = & V_43 -> V_47 ;
V_32 = false ;
} else {
V_42 = & V_43 -> V_48 ;
}
}
F_46 ( & V_57 -> V_58 . V_34 , V_43 , V_42 ) ;
F_47 ( & V_57 -> V_58 . V_34 , & V_2 -> V_69 ) ;
if ( V_32 )
F_76 ( V_2 -> V_67 , V_57 ) ;
F_25 ( & V_2 -> V_33 ) ;
if ( V_73 )
F_3 ( V_2 -> V_53 ) ;
}
void F_92 ( struct V_56 * V_57 )
{
struct V_11 * V_12 = V_57 -> V_12 ;
struct V_1 * V_2 = & V_12 -> V_13 ;
F_27 ( ! F_89 () ) ;
F_2 ( & V_57 -> V_74 ) ;
F_27 ( ! V_57 -> V_58 . V_4 . V_45 ) ;
F_24 ( & V_2 -> V_33 ) ;
if ( ! F_55 ( & V_57 -> V_58 . V_34 ) ) {
if ( V_57 == F_75 ( V_2 -> V_67 ) ) {
struct V_40 * V_50 =
F_48 ( & V_57 -> V_58 . V_34 ) ;
F_76 ( V_2 -> V_67 ,
V_50 ? F_63 ( V_50 ) : NULL ) ;
}
F_41 ( & V_57 -> V_58 . V_34 , & V_2 -> V_69 ) ;
F_31 ( & V_57 -> V_58 . V_34 ) ;
F_77 ( V_57 ) ;
}
F_54 ( V_12 , & V_57 -> V_58 . V_4 ) ;
F_25 ( & V_2 -> V_33 ) ;
V_57 -> V_58 . V_4 . V_45 = 0 ;
}
int F_93 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
struct V_52 * V_9 ;
F_94 ( & V_2 -> V_33 ) ;
F_94 ( & V_2 -> V_6 ) ;
F_95 ( & V_2 -> V_29 ,
F_18 ,
( unsigned long ) V_12 ) ;
F_95 ( & V_2 -> V_28 ,
F_15 ,
( unsigned long ) V_12 ) ;
V_9 = F_96 ( F_66 , V_12 ,
L_2 , V_12 -> V_20 ) ;
if ( F_97 ( V_9 ) )
return F_98 ( V_9 ) ;
V_2 -> V_53 = V_9 ;
return 0 ;
}
static void F_99 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
F_100 ( & V_2 -> V_28 ) ;
F_100 ( & V_2 -> V_29 ) ;
F_101 ( V_12 -> V_20 , & V_12 -> V_21 -> V_22 . V_23 ) ;
}
void F_102 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
F_99 ( V_12 ) ;
F_19 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_30 )
F_23 ( V_12 ) ;
else
F_26 ( V_12 ) ;
F_101 ( V_18 , & V_12 -> V_19 ) ;
if ( V_2 -> V_25 )
F_34 ( V_2 ) ;
F_21 ( & V_2 -> V_6 ) ;
}
void F_103 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
F_104 ( F_57 ( V_2 -> V_7 ) ) ;
F_104 ( ! F_105 ( & V_2 -> V_35 ) ) ;
F_104 ( F_75 ( V_2 -> V_67 ) ) ;
F_104 ( ! F_105 ( & V_2 -> V_69 ) ) ;
if ( ! F_106 ( V_2 -> V_53 ) )
F_107 ( V_2 -> V_53 ) ;
F_99 ( V_12 ) ;
}
bool F_108 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_13 ;
bool V_75 = false ;
F_19 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_7 ) {
F_3 ( V_2 -> V_7 -> V_9 ) ;
V_75 = true ;
}
if ( F_75 ( V_2 -> V_67 ) ) {
F_3 ( V_2 -> V_53 ) ;
V_75 = true ;
}
F_21 ( & V_2 -> V_33 ) ;
return V_75 ;
}
