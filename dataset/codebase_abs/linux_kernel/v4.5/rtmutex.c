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
} while ( F_6 ( V_7 , V_4 ,
V_4 | V_6 ) != V_4 );
}
static inline bool F_7 ( struct V_1 * V_2 ,
unsigned long V_8 )
__releases( V_2 -> V_9 )
{
struct V_3 * V_4 = F_8 ( V_2 ) ;
F_3 ( V_2 ) ;
F_9 ( & V_2 -> V_9 , V_8 ) ;
return F_10 ( V_2 , V_4 , NULL ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_4 = (struct V_3 * )
( ( unsigned long ) V_2 -> V_4 | V_6 ) ;
}
static inline bool F_7 ( struct V_1 * V_2 ,
unsigned long V_8 )
__releases( V_2 -> V_9 )
{
V_2 -> V_4 = NULL ;
F_9 ( & V_2 -> V_9 , V_8 ) ;
return true ;
}
static inline int
F_11 ( struct V_10 * V_11 ,
struct V_10 * V_12 )
{
if ( V_11 -> V_13 < V_12 -> V_13 )
return 1 ;
if ( F_12 ( V_11 -> V_13 ) )
return F_13 ( V_11 -> V_14 -> V_15 . V_16 ,
V_12 -> V_14 -> V_15 . V_16 ) ;
return 0 ;
}
static void
F_14 ( struct V_1 * V_2 , struct V_10 * V_17 )
{
struct V_18 * * V_19 = & V_2 -> V_20 . V_18 ;
struct V_18 * V_21 = NULL ;
struct V_10 * V_22 ;
int V_23 = 1 ;
while ( * V_19 ) {
V_21 = * V_19 ;
V_22 = F_15 ( V_21 , struct V_10 , V_24 ) ;
if ( F_11 ( V_17 , V_22 ) ) {
V_19 = & V_21 -> V_25 ;
} else {
V_19 = & V_21 -> V_26 ;
V_23 = 0 ;
}
}
if ( V_23 )
V_2 -> V_27 = & V_17 -> V_24 ;
F_16 ( & V_17 -> V_24 , V_21 , V_19 ) ;
F_17 ( & V_17 -> V_24 , & V_2 -> V_20 ) ;
}
static void
F_18 ( struct V_1 * V_2 , struct V_10 * V_17 )
{
if ( F_19 ( & V_17 -> V_24 ) )
return;
if ( V_2 -> V_27 == & V_17 -> V_24 )
V_2 -> V_27 = F_20 ( & V_17 -> V_24 ) ;
F_21 ( & V_17 -> V_24 , & V_2 -> V_20 ) ;
F_22 ( & V_17 -> V_24 ) ;
}
static void
F_23 ( struct V_3 * V_14 , struct V_10 * V_17 )
{
struct V_18 * * V_19 = & V_14 -> V_28 . V_18 ;
struct V_18 * V_21 = NULL ;
struct V_10 * V_22 ;
int V_23 = 1 ;
while ( * V_19 ) {
V_21 = * V_19 ;
V_22 = F_15 ( V_21 , struct V_10 , V_29 ) ;
if ( F_11 ( V_17 , V_22 ) ) {
V_19 = & V_21 -> V_25 ;
} else {
V_19 = & V_21 -> V_26 ;
V_23 = 0 ;
}
}
if ( V_23 )
V_14 -> V_30 = & V_17 -> V_29 ;
F_16 ( & V_17 -> V_29 , V_21 , V_19 ) ;
F_17 ( & V_17 -> V_29 , & V_14 -> V_28 ) ;
}
static void
F_24 ( struct V_3 * V_14 , struct V_10 * V_17 )
{
if ( F_19 ( & V_17 -> V_29 ) )
return;
if ( V_14 -> V_30 == & V_17 -> V_29 )
V_14 -> V_30 = F_20 ( & V_17 -> V_29 ) ;
F_21 ( & V_17 -> V_29 , & V_14 -> V_28 ) ;
F_22 ( & V_17 -> V_29 ) ;
}
int F_25 ( struct V_3 * V_14 )
{
if ( F_26 ( ! F_27 ( V_14 ) ) )
return V_14 -> V_31 ;
return F_28 ( F_29 ( V_14 ) -> V_13 ,
V_14 -> V_31 ) ;
}
struct V_3 * F_30 ( struct V_3 * V_14 )
{
if ( F_26 ( ! F_27 ( V_14 ) ) )
return NULL ;
return F_29 ( V_14 ) -> V_14 ;
}
int F_31 ( struct V_3 * V_14 , int V_32 )
{
if ( ! F_27 ( V_14 ) )
return V_32 ;
if ( F_29 ( V_14 ) -> V_14 -> V_13 <= V_32 )
return F_29 ( V_14 ) -> V_14 -> V_13 ;
return V_32 ;
}
static void F_32 ( struct V_3 * V_14 )
{
int V_13 = F_25 ( V_14 ) ;
if ( V_14 -> V_13 != V_13 || F_12 ( V_13 ) )
F_33 ( V_14 , V_13 ) ;
}
void F_34 ( struct V_3 * V_14 )
{
unsigned long V_8 ;
F_35 ( & V_14 -> V_33 , V_8 ) ;
F_32 ( V_14 ) ;
F_9 ( & V_14 -> V_33 , V_8 ) ;
}
static bool F_36 ( struct V_10 * V_17 ,
enum V_34 V_35 )
{
return F_37 ( V_17 , V_35 ) ;
}
static inline struct V_1 * F_38 ( struct V_3 * V_7 )
{
return V_7 -> V_36 ? V_7 -> V_36 -> V_2 : NULL ;
}
static int F_39 ( struct V_3 * V_14 ,
enum V_34 V_35 ,
struct V_1 * V_37 ,
struct V_1 * V_38 ,
struct V_10 * V_39 ,
struct V_3 * V_40 )
{
struct V_10 * V_17 , * V_41 = V_39 ;
struct V_10 * V_42 ;
int V_43 = 0 , V_44 = 0 ;
struct V_1 * V_2 ;
bool V_45 ;
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
F_42 ( V_14 ) ;
return - V_52 ;
}
V_53:
F_43 ( & V_14 -> V_33 ) ;
V_17 = V_14 -> V_36 ;
if ( ! V_17 )
goto V_54;
if ( V_39 && ! F_8 ( V_37 ) )
goto V_54;
if ( V_38 != V_17 -> V_2 )
goto V_54;
if ( V_41 ) {
if ( ! F_27 ( V_14 ) )
goto V_54;
if ( V_41 != F_29 ( V_14 ) ) {
if ( ! V_45 )
goto V_54;
else
V_46 = false ;
}
}
if ( V_17 -> V_13 == V_14 -> V_13 ) {
if ( ! V_45 )
goto V_54;
else
V_46 = false ;
}
V_2 = V_17 -> V_2 ;
if ( ! F_44 ( & V_2 -> V_9 ) ) {
F_45 ( & V_14 -> V_33 ) ;
F_46 () ;
goto V_53;
}
if ( V_2 == V_37 || F_8 ( V_2 ) == V_40 ) {
F_47 ( V_35 , V_39 , V_2 ) ;
F_48 ( & V_2 -> V_9 ) ;
V_43 = - V_52 ;
goto V_54;
}
if ( ! V_46 ) {
F_48 ( & V_14 -> V_33 ) ;
F_42 ( V_14 ) ;
if ( ! F_8 ( V_2 ) ) {
F_45 ( & V_2 -> V_9 ) ;
return 0 ;
}
V_14 = F_8 ( V_2 ) ;
F_49 ( V_14 ) ;
F_50 ( & V_14 -> V_33 ) ;
V_38 = F_38 ( V_14 ) ;
V_41 = F_51 ( V_2 ) ;
F_48 ( & V_14 -> V_33 ) ;
F_45 ( & V_2 -> V_9 ) ;
if ( ! V_38 )
goto V_55;
goto V_47;
}
V_42 = F_51 ( V_2 ) ;
F_18 ( V_2 , V_17 ) ;
V_17 -> V_13 = V_14 -> V_13 ;
F_14 ( V_2 , V_17 ) ;
F_48 ( & V_14 -> V_33 ) ;
F_42 ( V_14 ) ;
if ( ! F_8 ( V_2 ) ) {
if ( V_42 != F_51 ( V_2 ) )
F_52 ( F_51 ( V_2 ) -> V_14 ) ;
F_45 ( & V_2 -> V_9 ) ;
return 0 ;
}
V_14 = F_8 ( V_2 ) ;
F_49 ( V_14 ) ;
F_50 ( & V_14 -> V_33 ) ;
if ( V_17 == F_51 ( V_2 ) ) {
F_24 ( V_14 , V_42 ) ;
F_23 ( V_14 , V_17 ) ;
F_32 ( V_14 ) ;
} else if ( V_42 == V_17 ) {
F_24 ( V_14 , V_17 ) ;
V_17 = F_51 ( V_2 ) ;
F_23 ( V_14 , V_17 ) ;
F_32 ( V_14 ) ;
} else {
}
V_38 = F_38 ( V_14 ) ;
V_41 = F_51 ( V_2 ) ;
F_48 ( & V_14 -> V_33 ) ;
F_45 ( & V_2 -> V_9 ) ;
if ( ! V_38 )
goto V_55;
if ( ! V_45 && V_17 != V_41 )
goto V_55;
goto V_47;
V_54:
F_45 ( & V_14 -> V_33 ) ;
V_55:
F_42 ( V_14 ) ;
return V_43 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_3 * V_14 ,
struct V_10 * V_17 )
{
F_5 ( V_2 ) ;
if ( F_8 ( V_2 ) )
return 0 ;
if ( V_17 ) {
if ( V_17 != F_51 ( V_2 ) )
return 0 ;
F_18 ( V_2 , V_17 ) ;
} else {
if ( F_2 ( V_2 ) ) {
if ( V_14 -> V_13 >= F_51 ( V_2 ) -> V_13 )
return 0 ;
} else {
goto V_56;
}
}
F_50 ( & V_14 -> V_33 ) ;
V_14 -> V_36 = NULL ;
if ( F_2 ( V_2 ) )
F_23 ( V_14 , F_51 ( V_2 ) ) ;
F_48 ( & V_14 -> V_33 ) ;
V_56:
F_54 ( V_2 ) ;
F_1 ( V_2 , V_14 ) ;
F_55 ( V_2 , V_14 ) ;
return 1 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_10 * V_17 ,
struct V_3 * V_14 ,
enum V_34 V_35 )
{
struct V_3 * V_4 = F_8 ( V_2 ) ;
struct V_10 * V_41 = V_17 ;
struct V_1 * V_38 ;
int V_57 = 0 , V_58 ;
if ( V_4 == V_14 )
return - V_52 ;
F_50 ( & V_14 -> V_33 ) ;
F_32 ( V_14 ) ;
V_17 -> V_14 = V_14 ;
V_17 -> V_2 = V_2 ;
V_17 -> V_13 = V_14 -> V_13 ;
if ( F_2 ( V_2 ) )
V_41 = F_51 ( V_2 ) ;
F_14 ( V_2 , V_17 ) ;
V_14 -> V_36 = V_17 ;
F_48 ( & V_14 -> V_33 ) ;
if ( ! V_4 )
return 0 ;
F_50 ( & V_4 -> V_33 ) ;
if ( V_17 == F_51 ( V_2 ) ) {
F_24 ( V_4 , V_41 ) ;
F_23 ( V_4 , V_17 ) ;
F_32 ( V_4 ) ;
if ( V_4 -> V_36 )
V_57 = 1 ;
} else if ( F_36 ( V_17 , V_35 ) ) {
V_57 = 1 ;
}
V_38 = F_38 ( V_4 ) ;
F_48 ( & V_4 -> V_33 ) ;
if ( ! V_57 || ! V_38 )
return 0 ;
F_49 ( V_4 ) ;
F_45 ( & V_2 -> V_9 ) ;
V_58 = F_39 ( V_4 , V_35 , V_2 ,
V_38 , V_17 , V_14 ) ;
F_43 ( & V_2 -> V_9 ) ;
return V_58 ;
}
static void F_57 ( struct V_59 * V_60 ,
struct V_1 * V_2 )
{
struct V_10 * V_17 ;
F_50 ( & V_61 -> V_33 ) ;
V_17 = F_51 ( V_2 ) ;
F_24 ( V_61 , V_17 ) ;
V_2 -> V_4 = ( void * ) V_6 ;
F_48 ( & V_61 -> V_33 ) ;
F_58 ( V_60 , V_17 -> V_14 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_10 * V_17 )
{
bool V_62 = ( V_17 == F_51 ( V_2 ) ) ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
struct V_1 * V_38 ;
F_50 ( & V_61 -> V_33 ) ;
F_18 ( V_2 , V_17 ) ;
V_61 -> V_36 = NULL ;
F_48 ( & V_61 -> V_33 ) ;
if ( ! V_4 || ! V_62 )
return;
F_50 ( & V_4 -> V_33 ) ;
F_24 ( V_4 , V_17 ) ;
if ( F_2 ( V_2 ) )
F_23 ( V_4 , F_51 ( V_2 ) ) ;
F_32 ( V_4 ) ;
V_38 = F_38 ( V_4 ) ;
F_48 ( & V_4 -> V_33 ) ;
if ( ! V_38 )
return;
F_49 ( V_4 ) ;
F_45 ( & V_2 -> V_9 ) ;
F_39 ( V_4 , V_63 , V_2 ,
V_38 , NULL , V_61 ) ;
F_43 ( & V_2 -> V_9 ) ;
}
void F_60 ( struct V_3 * V_14 )
{
struct V_10 * V_17 ;
struct V_1 * V_38 ;
unsigned long V_8 ;
F_35 ( & V_14 -> V_33 , V_8 ) ;
V_17 = V_14 -> V_36 ;
if ( ! V_17 || ( V_17 -> V_13 == V_14 -> V_13 &&
! F_12 ( V_14 -> V_13 ) ) ) {
F_9 ( & V_14 -> V_33 , V_8 ) ;
return;
}
V_38 = V_17 -> V_2 ;
F_9 ( & V_14 -> V_33 , V_8 ) ;
F_49 ( V_14 ) ;
F_39 ( V_14 , V_63 , NULL ,
V_38 , NULL , V_14 ) ;
}
static int T_1
F_61 ( struct V_1 * V_2 , int V_64 ,
struct V_65 * V_66 ,
struct V_10 * V_17 )
{
int V_43 = 0 ;
for (; ; ) {
if ( F_53 ( V_2 , V_61 , V_17 ) )
break;
if ( F_62 ( V_64 == V_67 ) ) {
if ( F_63 ( V_61 ) )
V_43 = - V_68 ;
if ( V_66 && ! V_66 -> V_14 )
V_43 = - V_69 ;
if ( V_43 )
break;
}
F_45 ( & V_2 -> V_9 ) ;
F_64 ( V_17 ) ;
F_65 () ;
F_43 ( & V_2 -> V_9 ) ;
F_66 ( V_64 ) ;
}
F_67 ( V_70 ) ;
return V_43 ;
}
static void F_68 ( int V_58 , int V_45 ,
struct V_10 * V_71 )
{
if ( V_58 != - V_72 || V_45 )
return;
F_69 ( V_71 ) ;
while ( 1 ) {
F_66 ( V_67 ) ;
F_65 () ;
}
}
static int T_1
F_70 ( struct V_1 * V_2 , int V_64 ,
struct V_65 * V_66 ,
enum V_34 V_35 )
{
struct V_10 V_17 ;
unsigned long V_8 ;
int V_43 = 0 ;
F_71 ( & V_17 ) ;
F_22 ( & V_17 . V_29 ) ;
F_22 ( & V_17 . V_24 ) ;
F_35 ( & V_2 -> V_9 , V_8 ) ;
if ( F_53 ( V_2 , V_61 , NULL ) ) {
F_9 ( & V_2 -> V_9 , V_8 ) ;
return 0 ;
}
F_66 ( V_64 ) ;
if ( F_62 ( V_66 ) )
F_72 ( & V_66 -> V_73 , V_74 ) ;
V_43 = F_56 ( V_2 , & V_17 , V_61 , V_35 ) ;
if ( F_26 ( ! V_43 ) )
V_43 = F_61 ( V_2 , V_64 , V_66 , & V_17 ) ;
if ( F_62 ( V_43 ) ) {
F_67 ( V_70 ) ;
if ( F_2 ( V_2 ) )
F_59 ( V_2 , & V_17 ) ;
F_68 ( V_43 , V_35 , & V_17 ) ;
}
F_4 ( V_2 ) ;
F_9 ( & V_2 -> V_9 , V_8 ) ;
if ( F_62 ( V_66 ) )
F_73 ( & V_66 -> V_73 ) ;
F_74 ( & V_17 ) ;
return V_43 ;
}
static inline int F_75 ( struct V_1 * V_2 )
{
unsigned long V_8 ;
int V_43 ;
if ( F_8 ( V_2 ) )
return 0 ;
F_35 ( & V_2 -> V_9 , V_8 ) ;
V_43 = F_53 ( V_2 , V_61 , NULL ) ;
F_4 ( V_2 ) ;
F_9 ( & V_2 -> V_9 , V_8 ) ;
return V_43 ;
}
static bool T_1 F_76 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
unsigned long V_8 ;
F_35 ( & V_2 -> V_9 , V_8 ) ;
F_77 ( V_2 ) ;
F_78 ( V_61 ) ;
while ( ! F_2 ( V_2 ) ) {
if ( F_7 ( V_2 , V_8 ) == true )
return false ;
F_35 ( & V_2 -> V_9 , V_8 ) ;
}
F_57 ( V_60 , V_2 ) ;
F_9 ( & V_2 -> V_9 , V_8 ) ;
return true ;
}
static inline int
F_79 ( struct V_1 * V_2 , int V_64 ,
int (* F_80)( struct V_1 * V_2 , int V_64 ,
struct V_65 * V_66 ,
enum V_34 V_35 ) )
{
if ( F_26 ( F_81 ( V_2 , NULL , V_61 ) ) ) {
F_55 ( V_2 , V_61 ) ;
return 0 ;
} else
return F_80 ( V_2 , V_64 , NULL , V_63 ) ;
}
static inline int
F_82 ( struct V_1 * V_2 , int V_64 ,
struct V_65 * V_66 ,
enum V_34 V_35 ,
int (* F_80)( struct V_1 * V_2 , int V_64 ,
struct V_65 * V_66 ,
enum V_34 V_35 ) )
{
if ( V_35 == V_63 &&
F_26 ( F_81 ( V_2 , NULL , V_61 ) ) ) {
F_55 ( V_2 , V_61 ) ;
return 0 ;
} else
return F_80 ( V_2 , V_64 , V_66 , V_35 ) ;
}
static inline int
F_83 ( struct V_1 * V_2 ,
int (* F_80)( struct V_1 * V_2 ) )
{
if ( F_26 ( F_81 ( V_2 , NULL , V_61 ) ) ) {
F_55 ( V_2 , V_61 ) ;
return 1 ;
}
return F_80 ( V_2 ) ;
}
static inline void
F_84 ( struct V_1 * V_2 ,
bool (* F_80)( struct V_1 * V_2 ,
struct V_59 * V_75 ) )
{
F_85 ( V_60 ) ;
if ( F_26 ( F_10 ( V_2 , V_61 , NULL ) ) ) {
F_78 ( V_61 ) ;
} else {
bool V_76 = F_80 ( V_2 , & V_60 ) ;
F_86 ( & V_60 ) ;
if ( V_76 )
F_34 ( V_61 ) ;
}
}
void T_1 F_87 ( struct V_1 * V_2 )
{
F_88 () ;
F_79 ( V_2 , V_77 , F_70 ) ;
}
int T_1 F_89 ( struct V_1 * V_2 )
{
F_88 () ;
return F_79 ( V_2 , V_67 , F_70 ) ;
}
int F_90 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
F_88 () ;
return F_82 ( V_2 , V_67 , V_66 ,
V_78 ,
F_70 ) ;
}
int
F_91 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
F_88 () ;
return F_82 ( V_2 , V_67 , V_66 ,
V_63 ,
F_70 ) ;
}
int T_1 F_92 ( struct V_1 * V_2 )
{
if ( F_93 ( F_94 () || F_95 () || F_96 () ) )
return 0 ;
return F_83 ( V_2 , F_75 ) ;
}
void T_1 F_97 ( struct V_1 * V_2 )
{
F_84 ( V_2 , F_76 ) ;
}
bool T_1 F_98 ( struct V_1 * V_2 ,
struct V_59 * V_75 )
{
if ( F_26 ( F_10 ( V_2 , V_61 , NULL ) ) ) {
F_78 ( V_61 ) ;
return false ;
}
return F_76 ( V_2 , V_75 ) ;
}
void F_99 ( struct V_1 * V_2 )
{
F_93 ( F_100 ( V_2 ) ) ;
#ifdef F_101
V_2 -> V_79 = NULL ;
#endif
}
void F_102 ( struct V_1 * V_2 , const char * V_80 )
{
V_2 -> V_4 = NULL ;
F_103 ( & V_2 -> V_9 ) ;
V_2 -> V_20 = V_81 ;
V_2 -> V_27 = NULL ;
F_104 ( V_2 , V_80 ) ;
}
void F_105 ( struct V_1 * V_2 ,
struct V_3 * V_82 )
{
F_102 ( V_2 , NULL ) ;
F_106 ( V_2 , V_82 ) ;
F_1 ( V_2 , V_82 ) ;
F_55 ( V_2 , V_82 ) ;
}
void F_107 ( struct V_1 * V_2 ,
struct V_3 * V_82 )
{
F_108 ( V_2 ) ;
F_1 ( V_2 , NULL ) ;
F_78 ( V_82 ) ;
}
int F_109 ( struct V_1 * V_2 ,
struct V_10 * V_17 ,
struct V_3 * V_14 )
{
int V_43 ;
F_43 ( & V_2 -> V_9 ) ;
if ( F_53 ( V_2 , V_14 , NULL ) ) {
F_45 ( & V_2 -> V_9 ) ;
return 1 ;
}
V_43 = F_56 ( V_2 , V_17 , V_14 ,
V_78 ) ;
if ( V_43 && ! F_8 ( V_2 ) ) {
V_43 = 0 ;
}
if ( F_62 ( V_43 ) )
F_59 ( V_2 , V_17 ) ;
F_45 ( & V_2 -> V_9 ) ;
F_64 ( V_17 ) ;
return V_43 ;
}
struct V_3 * F_110 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) )
return NULL ;
return F_51 ( V_2 ) -> V_14 ;
}
int F_111 ( struct V_1 * V_2 ,
struct V_65 * V_83 ,
struct V_10 * V_17 )
{
int V_43 ;
F_43 ( & V_2 -> V_9 ) ;
F_66 ( V_67 ) ;
V_43 = F_61 ( V_2 , V_67 , V_83 , V_17 ) ;
if ( F_62 ( V_43 ) )
F_59 ( V_2 , V_17 ) ;
F_4 ( V_2 ) ;
F_45 ( & V_2 -> V_9 ) ;
return V_43 ;
}
