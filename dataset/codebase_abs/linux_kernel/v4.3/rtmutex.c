static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 = ( unsigned long ) V_4 ;
if ( F_2 ( V_2 ) )
V_5 |= V_6 ;
V_2 -> V_4 = (struct V_3 * ) V_5 ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_4 = (struct V_3 * )
( ( unsigned long ) V_2 -> V_4 & ~ V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) )
F_3 ( V_2 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
unsigned long V_4 , * V_7 = ( unsigned long * ) & V_2 -> V_4 ;
do {
V_4 = * V_7 ;
} while ( F_6 ( V_7 , V_4 , V_4 | V_6 ) != V_4 );
}
static inline bool F_7 ( struct V_1 * V_2 )
__releases( V_2 -> V_8 )
{
struct V_3 * V_4 = F_8 ( V_2 ) ;
F_3 ( V_2 ) ;
F_9 ( & V_2 -> V_8 ) ;
return F_10 ( V_2 , V_4 , NULL ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_4 = (struct V_3 * )
( ( unsigned long ) V_2 -> V_4 | V_6 ) ;
}
static inline bool F_7 ( struct V_1 * V_2 )
__releases( V_2 -> V_8 )
{
V_2 -> V_4 = NULL ;
F_9 ( & V_2 -> V_8 ) ;
return true ;
}
static inline int
F_11 ( struct V_9 * V_10 ,
struct V_9 * V_11 )
{
if ( V_10 -> V_12 < V_11 -> V_12 )
return 1 ;
if ( F_12 ( V_10 -> V_12 ) )
return ( V_10 -> V_13 -> V_14 . V_15 < V_11 -> V_13 -> V_14 . V_15 ) ;
return 0 ;
}
static void
F_13 ( struct V_1 * V_2 , struct V_9 * V_16 )
{
struct V_17 * * V_18 = & V_2 -> V_19 . V_17 ;
struct V_17 * V_20 = NULL ;
struct V_9 * V_21 ;
int V_22 = 1 ;
while ( * V_18 ) {
V_20 = * V_18 ;
V_21 = F_14 ( V_20 , struct V_9 , V_23 ) ;
if ( F_11 ( V_16 , V_21 ) ) {
V_18 = & V_20 -> V_24 ;
} else {
V_18 = & V_20 -> V_25 ;
V_22 = 0 ;
}
}
if ( V_22 )
V_2 -> V_26 = & V_16 -> V_23 ;
F_15 ( & V_16 -> V_23 , V_20 , V_18 ) ;
F_16 ( & V_16 -> V_23 , & V_2 -> V_19 ) ;
}
static void
F_17 ( struct V_1 * V_2 , struct V_9 * V_16 )
{
if ( F_18 ( & V_16 -> V_23 ) )
return;
if ( V_2 -> V_26 == & V_16 -> V_23 )
V_2 -> V_26 = F_19 ( & V_16 -> V_23 ) ;
F_20 ( & V_16 -> V_23 , & V_2 -> V_19 ) ;
F_21 ( & V_16 -> V_23 ) ;
}
static void
F_22 ( struct V_3 * V_13 , struct V_9 * V_16 )
{
struct V_17 * * V_18 = & V_13 -> V_27 . V_17 ;
struct V_17 * V_20 = NULL ;
struct V_9 * V_21 ;
int V_22 = 1 ;
while ( * V_18 ) {
V_20 = * V_18 ;
V_21 = F_14 ( V_20 , struct V_9 , V_28 ) ;
if ( F_11 ( V_16 , V_21 ) ) {
V_18 = & V_20 -> V_24 ;
} else {
V_18 = & V_20 -> V_25 ;
V_22 = 0 ;
}
}
if ( V_22 )
V_13 -> V_29 = & V_16 -> V_28 ;
F_15 ( & V_16 -> V_28 , V_20 , V_18 ) ;
F_16 ( & V_16 -> V_28 , & V_13 -> V_27 ) ;
}
static void
F_23 ( struct V_3 * V_13 , struct V_9 * V_16 )
{
if ( F_18 ( & V_16 -> V_28 ) )
return;
if ( V_13 -> V_29 == & V_16 -> V_28 )
V_13 -> V_29 = F_19 ( & V_16 -> V_28 ) ;
F_20 ( & V_16 -> V_28 , & V_13 -> V_27 ) ;
F_21 ( & V_16 -> V_28 ) ;
}
int F_24 ( struct V_3 * V_13 )
{
if ( F_25 ( ! F_26 ( V_13 ) ) )
return V_13 -> V_30 ;
return F_27 ( F_28 ( V_13 ) -> V_12 ,
V_13 -> V_30 ) ;
}
struct V_3 * F_29 ( struct V_3 * V_13 )
{
if ( F_25 ( ! F_26 ( V_13 ) ) )
return NULL ;
return F_28 ( V_13 ) -> V_13 ;
}
int F_30 ( struct V_3 * V_13 , int V_31 )
{
if ( ! F_26 ( V_13 ) )
return V_31 ;
if ( F_28 ( V_13 ) -> V_13 -> V_12 <= V_31 )
return F_28 ( V_13 ) -> V_13 -> V_12 ;
return V_31 ;
}
static void F_31 ( struct V_3 * V_13 )
{
int V_12 = F_24 ( V_13 ) ;
if ( V_13 -> V_12 != V_12 || F_12 ( V_12 ) )
F_32 ( V_13 , V_12 ) ;
}
void F_33 ( struct V_3 * V_13 )
{
unsigned long V_32 ;
F_34 ( & V_13 -> V_33 , V_32 ) ;
F_31 ( V_13 ) ;
F_35 ( & V_13 -> V_33 , V_32 ) ;
}
static bool F_36 ( struct V_9 * V_16 ,
enum V_34 V_35 )
{
return F_37 ( V_16 , V_35 ) ;
}
static inline struct V_1 * F_38 ( struct V_3 * V_7 )
{
return V_7 -> V_36 ? V_7 -> V_36 -> V_2 : NULL ;
}
static int F_39 ( struct V_3 * V_13 ,
enum V_34 V_35 ,
struct V_1 * V_37 ,
struct V_1 * V_38 ,
struct V_9 * V_39 ,
struct V_3 * V_40 )
{
struct V_9 * V_16 , * V_41 = V_39 ;
struct V_9 * V_42 ;
int V_43 = 0 , V_44 = 0 ;
struct V_1 * V_2 ;
bool V_45 ;
unsigned long V_32 ;
bool V_46 = true ;
V_45 = F_36 ( V_39 , V_35 ) ;
V_47:
if ( ++ V_44 > V_48 ) {
static int V_49 ;
if ( V_49 != V_48 ) {
V_49 = V_48 ;
F_40 ( V_50 L_1
L_2 , V_48 ,
V_40 -> V_51 , F_41 ( V_40 ) ) ;
}
F_42 ( V_13 ) ;
return - V_52 ;
}
V_53:
F_34 ( & V_13 -> V_33 , V_32 ) ;
V_16 = V_13 -> V_36 ;
if ( ! V_16 )
goto V_54;
if ( V_39 && ! F_8 ( V_37 ) )
goto V_54;
if ( V_38 != V_16 -> V_2 )
goto V_54;
if ( V_41 ) {
if ( ! F_26 ( V_13 ) )
goto V_54;
if ( V_41 != F_28 ( V_13 ) ) {
if ( ! V_45 )
goto V_54;
else
V_46 = false ;
}
}
if ( V_16 -> V_12 == V_13 -> V_12 ) {
if ( ! V_45 )
goto V_54;
else
V_46 = false ;
}
V_2 = V_16 -> V_2 ;
if ( ! F_43 ( & V_2 -> V_8 ) ) {
F_35 ( & V_13 -> V_33 , V_32 ) ;
F_44 () ;
goto V_53;
}
if ( V_2 == V_37 || F_8 ( V_2 ) == V_40 ) {
F_45 ( V_35 , V_39 , V_2 ) ;
F_9 ( & V_2 -> V_8 ) ;
V_43 = - V_52 ;
goto V_54;
}
if ( ! V_46 ) {
F_35 ( & V_13 -> V_33 , V_32 ) ;
F_42 ( V_13 ) ;
if ( ! F_8 ( V_2 ) ) {
F_9 ( & V_2 -> V_8 ) ;
return 0 ;
}
V_13 = F_8 ( V_2 ) ;
F_46 ( V_13 ) ;
F_34 ( & V_13 -> V_33 , V_32 ) ;
V_38 = F_38 ( V_13 ) ;
V_41 = F_47 ( V_2 ) ;
F_35 ( & V_13 -> V_33 , V_32 ) ;
F_9 ( & V_2 -> V_8 ) ;
if ( ! V_38 )
goto V_55;
goto V_47;
}
V_42 = F_47 ( V_2 ) ;
F_17 ( V_2 , V_16 ) ;
V_16 -> V_12 = V_13 -> V_12 ;
F_13 ( V_2 , V_16 ) ;
F_35 ( & V_13 -> V_33 , V_32 ) ;
F_42 ( V_13 ) ;
if ( ! F_8 ( V_2 ) ) {
if ( V_42 != F_47 ( V_2 ) )
F_48 ( F_47 ( V_2 ) -> V_13 ) ;
F_9 ( & V_2 -> V_8 ) ;
return 0 ;
}
V_13 = F_8 ( V_2 ) ;
F_46 ( V_13 ) ;
F_34 ( & V_13 -> V_33 , V_32 ) ;
if ( V_16 == F_47 ( V_2 ) ) {
F_23 ( V_13 , V_42 ) ;
F_22 ( V_13 , V_16 ) ;
F_31 ( V_13 ) ;
} else if ( V_42 == V_16 ) {
F_23 ( V_13 , V_16 ) ;
V_16 = F_47 ( V_2 ) ;
F_22 ( V_13 , V_16 ) ;
F_31 ( V_13 ) ;
} else {
}
V_38 = F_38 ( V_13 ) ;
V_41 = F_47 ( V_2 ) ;
F_35 ( & V_13 -> V_33 , V_32 ) ;
F_9 ( & V_2 -> V_8 ) ;
if ( ! V_38 )
goto V_55;
if ( ! V_45 && V_16 != V_41 )
goto V_55;
goto V_47;
V_54:
F_35 ( & V_13 -> V_33 , V_32 ) ;
V_55:
F_42 ( V_13 ) ;
return V_43 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_3 * V_13 ,
struct V_9 * V_16 )
{
unsigned long V_32 ;
F_5 ( V_2 ) ;
if ( F_8 ( V_2 ) )
return 0 ;
if ( V_16 ) {
if ( V_16 != F_47 ( V_2 ) )
return 0 ;
F_17 ( V_2 , V_16 ) ;
} else {
if ( F_2 ( V_2 ) ) {
if ( V_13 -> V_12 >= F_47 ( V_2 ) -> V_12 )
return 0 ;
} else {
goto V_56;
}
}
F_34 ( & V_13 -> V_33 , V_32 ) ;
V_13 -> V_36 = NULL ;
if ( F_2 ( V_2 ) )
F_22 ( V_13 , F_47 ( V_2 ) ) ;
F_35 ( & V_13 -> V_33 , V_32 ) ;
V_56:
F_50 ( V_2 ) ;
F_1 ( V_2 , V_13 ) ;
F_51 ( V_2 , V_13 ) ;
return 1 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_9 * V_16 ,
struct V_3 * V_13 ,
enum V_34 V_35 )
{
struct V_3 * V_4 = F_8 ( V_2 ) ;
struct V_9 * V_41 = V_16 ;
struct V_1 * V_38 ;
int V_57 = 0 , V_58 ;
unsigned long V_32 ;
if ( V_4 == V_13 )
return - V_52 ;
F_34 ( & V_13 -> V_33 , V_32 ) ;
F_31 ( V_13 ) ;
V_16 -> V_13 = V_13 ;
V_16 -> V_2 = V_2 ;
V_16 -> V_12 = V_13 -> V_12 ;
if ( F_2 ( V_2 ) )
V_41 = F_47 ( V_2 ) ;
F_13 ( V_2 , V_16 ) ;
V_13 -> V_36 = V_16 ;
F_35 ( & V_13 -> V_33 , V_32 ) ;
if ( ! V_4 )
return 0 ;
F_34 ( & V_4 -> V_33 , V_32 ) ;
if ( V_16 == F_47 ( V_2 ) ) {
F_23 ( V_4 , V_41 ) ;
F_22 ( V_4 , V_16 ) ;
F_31 ( V_4 ) ;
if ( V_4 -> V_36 )
V_57 = 1 ;
} else if ( F_36 ( V_16 , V_35 ) ) {
V_57 = 1 ;
}
V_38 = F_38 ( V_4 ) ;
F_35 ( & V_4 -> V_33 , V_32 ) ;
if ( ! V_57 || ! V_38 )
return 0 ;
F_46 ( V_4 ) ;
F_9 ( & V_2 -> V_8 ) ;
V_58 = F_39 ( V_4 , V_35 , V_2 ,
V_38 , V_16 , V_13 ) ;
F_53 ( & V_2 -> V_8 ) ;
return V_58 ;
}
static void F_54 ( struct V_59 * V_60 ,
struct V_1 * V_2 )
{
struct V_9 * V_16 ;
unsigned long V_32 ;
F_34 ( & V_61 -> V_33 , V_32 ) ;
V_16 = F_47 ( V_2 ) ;
F_23 ( V_61 , V_16 ) ;
V_2 -> V_4 = ( void * ) V_6 ;
F_35 ( & V_61 -> V_33 , V_32 ) ;
F_55 ( V_60 , V_16 -> V_13 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_9 * V_16 )
{
bool V_62 = ( V_16 == F_47 ( V_2 ) ) ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
struct V_1 * V_38 ;
unsigned long V_32 ;
F_34 ( & V_61 -> V_33 , V_32 ) ;
F_17 ( V_2 , V_16 ) ;
V_61 -> V_36 = NULL ;
F_35 ( & V_61 -> V_33 , V_32 ) ;
if ( ! V_4 || ! V_62 )
return;
F_34 ( & V_4 -> V_33 , V_32 ) ;
F_23 ( V_4 , V_16 ) ;
if ( F_2 ( V_2 ) )
F_22 ( V_4 , F_47 ( V_2 ) ) ;
F_31 ( V_4 ) ;
V_38 = F_38 ( V_4 ) ;
F_35 ( & V_4 -> V_33 , V_32 ) ;
if ( ! V_38 )
return;
F_46 ( V_4 ) ;
F_9 ( & V_2 -> V_8 ) ;
F_39 ( V_4 , V_63 , V_2 ,
V_38 , NULL , V_61 ) ;
F_53 ( & V_2 -> V_8 ) ;
}
void F_57 ( struct V_3 * V_13 )
{
struct V_9 * V_16 ;
struct V_1 * V_38 ;
unsigned long V_32 ;
F_34 ( & V_13 -> V_33 , V_32 ) ;
V_16 = V_13 -> V_36 ;
if ( ! V_16 || ( V_16 -> V_12 == V_13 -> V_12 &&
! F_12 ( V_13 -> V_12 ) ) ) {
F_35 ( & V_13 -> V_33 , V_32 ) ;
return;
}
V_38 = V_16 -> V_2 ;
F_35 ( & V_13 -> V_33 , V_32 ) ;
F_46 ( V_13 ) ;
F_39 ( V_13 , V_63 , NULL ,
V_38 , NULL , V_13 ) ;
}
static int T_1
F_58 ( struct V_1 * V_2 , int V_64 ,
struct V_65 * V_66 ,
struct V_9 * V_16 )
{
int V_43 = 0 ;
for (; ; ) {
if ( F_49 ( V_2 , V_61 , V_16 ) )
break;
if ( F_59 ( V_64 == V_67 ) ) {
if ( F_60 ( V_61 ) )
V_43 = - V_68 ;
if ( V_66 && ! V_66 -> V_13 )
V_43 = - V_69 ;
if ( V_43 )
break;
}
F_9 ( & V_2 -> V_8 ) ;
F_61 ( V_16 ) ;
F_62 () ;
F_53 ( & V_2 -> V_8 ) ;
F_63 ( V_64 ) ;
}
F_64 ( V_70 ) ;
return V_43 ;
}
static void F_65 ( int V_58 , int V_45 ,
struct V_9 * V_71 )
{
if ( V_58 != - V_72 || V_45 )
return;
F_66 ( V_71 ) ;
while ( 1 ) {
F_63 ( V_67 ) ;
F_62 () ;
}
}
static int T_1
F_67 ( struct V_1 * V_2 , int V_64 ,
struct V_65 * V_66 ,
enum V_34 V_35 )
{
struct V_9 V_16 ;
int V_43 = 0 ;
F_68 ( & V_16 ) ;
F_21 ( & V_16 . V_28 ) ;
F_21 ( & V_16 . V_23 ) ;
F_53 ( & V_2 -> V_8 ) ;
if ( F_49 ( V_2 , V_61 , NULL ) ) {
F_9 ( & V_2 -> V_8 ) ;
return 0 ;
}
F_63 ( V_64 ) ;
if ( F_59 ( V_66 ) )
F_69 ( & V_66 -> V_73 , V_74 ) ;
V_43 = F_52 ( V_2 , & V_16 , V_61 , V_35 ) ;
if ( F_25 ( ! V_43 ) )
V_43 = F_58 ( V_2 , V_64 , V_66 , & V_16 ) ;
if ( F_59 ( V_43 ) ) {
F_64 ( V_70 ) ;
if ( F_2 ( V_2 ) )
F_56 ( V_2 , & V_16 ) ;
F_65 ( V_43 , V_35 , & V_16 ) ;
}
F_4 ( V_2 ) ;
F_9 ( & V_2 -> V_8 ) ;
if ( F_59 ( V_66 ) )
F_70 ( & V_66 -> V_73 ) ;
F_71 ( & V_16 ) ;
return V_43 ;
}
static inline int F_72 ( struct V_1 * V_2 )
{
int V_43 ;
if ( F_8 ( V_2 ) )
return 0 ;
F_53 ( & V_2 -> V_8 ) ;
V_43 = F_49 ( V_2 , V_61 , NULL ) ;
F_4 ( V_2 ) ;
F_9 ( & V_2 -> V_8 ) ;
return V_43 ;
}
static bool T_1 F_73 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
F_53 ( & V_2 -> V_8 ) ;
F_74 ( V_2 ) ;
F_75 ( V_61 ) ;
while ( ! F_2 ( V_2 ) ) {
if ( F_7 ( V_2 ) == true )
return false ;
F_53 ( & V_2 -> V_8 ) ;
}
F_54 ( V_60 , V_2 ) ;
F_9 ( & V_2 -> V_8 ) ;
return true ;
}
static inline int
F_76 ( struct V_1 * V_2 , int V_64 ,
int (* F_77)( struct V_1 * V_2 , int V_64 ,
struct V_65 * V_66 ,
enum V_34 V_35 ) )
{
if ( F_25 ( F_10 ( V_2 , NULL , V_61 ) ) ) {
F_51 ( V_2 , V_61 ) ;
return 0 ;
} else
return F_77 ( V_2 , V_64 , NULL , V_63 ) ;
}
static inline int
F_78 ( struct V_1 * V_2 , int V_64 ,
struct V_65 * V_66 ,
enum V_34 V_35 ,
int (* F_77)( struct V_1 * V_2 , int V_64 ,
struct V_65 * V_66 ,
enum V_34 V_35 ) )
{
if ( V_35 == V_63 &&
F_25 ( F_10 ( V_2 , NULL , V_61 ) ) ) {
F_51 ( V_2 , V_61 ) ;
return 0 ;
} else
return F_77 ( V_2 , V_64 , V_66 , V_35 ) ;
}
static inline int
F_79 ( struct V_1 * V_2 ,
int (* F_77)( struct V_1 * V_2 ) )
{
if ( F_25 ( F_10 ( V_2 , NULL , V_61 ) ) ) {
F_51 ( V_2 , V_61 ) ;
return 1 ;
}
return F_77 ( V_2 ) ;
}
static inline void
F_80 ( struct V_1 * V_2 ,
bool (* F_77)( struct V_1 * V_2 ,
struct V_59 * V_75 ) )
{
F_81 ( V_60 ) ;
if ( F_25 ( F_10 ( V_2 , V_61 , NULL ) ) ) {
F_75 ( V_61 ) ;
} else {
bool V_76 = F_77 ( V_2 , & V_60 ) ;
F_82 ( & V_60 ) ;
if ( V_76 )
F_33 ( V_61 ) ;
}
}
void T_1 F_83 ( struct V_1 * V_2 )
{
F_84 () ;
F_76 ( V_2 , V_77 , F_67 ) ;
}
int T_1 F_85 ( struct V_1 * V_2 )
{
F_84 () ;
return F_76 ( V_2 , V_67 , F_67 ) ;
}
int F_86 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
F_84 () ;
return F_78 ( V_2 , V_67 , V_66 ,
V_78 ,
F_67 ) ;
}
int
F_87 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
F_84 () ;
return F_78 ( V_2 , V_67 , V_66 ,
V_63 ,
F_67 ) ;
}
int T_1 F_88 ( struct V_1 * V_2 )
{
if ( F_89 ( F_90 () || F_91 () || F_92 () ) )
return 0 ;
return F_79 ( V_2 , F_72 ) ;
}
void T_1 F_93 ( struct V_1 * V_2 )
{
F_80 ( V_2 , F_73 ) ;
}
bool T_1 F_94 ( struct V_1 * V_2 ,
struct V_59 * V_75 )
{
if ( F_25 ( F_10 ( V_2 , V_61 , NULL ) ) ) {
F_75 ( V_61 ) ;
return false ;
}
return F_73 ( V_2 , V_75 ) ;
}
void F_95 ( struct V_1 * V_2 )
{
F_89 ( F_96 ( V_2 ) ) ;
#ifdef F_97
V_2 -> V_79 = NULL ;
#endif
}
void F_98 ( struct V_1 * V_2 , const char * V_80 )
{
V_2 -> V_4 = NULL ;
F_99 ( & V_2 -> V_8 ) ;
V_2 -> V_19 = V_81 ;
V_2 -> V_26 = NULL ;
F_100 ( V_2 , V_80 ) ;
}
void F_101 ( struct V_1 * V_2 ,
struct V_3 * V_82 )
{
F_98 ( V_2 , NULL ) ;
F_102 ( V_2 , V_82 ) ;
F_1 ( V_2 , V_82 ) ;
F_51 ( V_2 , V_82 ) ;
}
void F_103 ( struct V_1 * V_2 ,
struct V_3 * V_82 )
{
F_104 ( V_2 ) ;
F_1 ( V_2 , NULL ) ;
F_75 ( V_82 ) ;
}
int F_105 ( struct V_1 * V_2 ,
struct V_9 * V_16 ,
struct V_3 * V_13 )
{
int V_43 ;
F_53 ( & V_2 -> V_8 ) ;
if ( F_49 ( V_2 , V_13 , NULL ) ) {
F_9 ( & V_2 -> V_8 ) ;
return 1 ;
}
V_43 = F_52 ( V_2 , V_16 , V_13 ,
V_78 ) ;
if ( V_43 && ! F_8 ( V_2 ) ) {
V_43 = 0 ;
}
if ( F_59 ( V_43 ) )
F_56 ( V_2 , V_16 ) ;
F_9 ( & V_2 -> V_8 ) ;
F_61 ( V_16 ) ;
return V_43 ;
}
struct V_3 * F_106 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) )
return NULL ;
return F_47 ( V_2 ) -> V_13 ;
}
int F_107 ( struct V_1 * V_2 ,
struct V_65 * V_83 ,
struct V_9 * V_16 )
{
int V_43 ;
F_53 ( & V_2 -> V_8 ) ;
F_63 ( V_67 ) ;
V_43 = F_58 ( V_2 , V_67 , V_83 , V_16 ) ;
if ( F_59 ( V_43 ) )
F_56 ( V_2 , V_16 ) ;
F_4 ( V_2 ) ;
F_9 ( & V_2 -> V_8 ) ;
return V_43 ;
}
