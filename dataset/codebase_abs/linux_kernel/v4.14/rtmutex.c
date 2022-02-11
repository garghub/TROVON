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
unsigned long V_4 , * V_7 = ( unsigned long * ) & V_2 -> V_4 ;
if ( F_2 ( V_2 ) )
return;
V_4 = F_5 ( * V_7 ) ;
if ( V_4 & V_6 )
F_6 ( * V_7 , V_4 & ~ V_6 ) ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
unsigned long V_4 , * V_7 = ( unsigned long * ) & V_2 -> V_4 ;
do {
V_4 = * V_7 ;
} while ( F_8 ( V_7 , V_4 ,
V_4 | V_6 ) != V_4 );
}
static inline bool F_9 ( struct V_1 * V_2 ,
unsigned long V_8 )
__releases( V_2 -> V_9 )
{
struct V_3 * V_4 = F_10 ( V_2 ) ;
F_3 ( V_2 ) ;
F_11 ( & V_2 -> V_9 , V_8 ) ;
return F_12 ( V_2 , V_4 , NULL ) ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
V_2 -> V_4 = (struct V_3 * )
( ( unsigned long ) V_2 -> V_4 | V_6 ) ;
}
static inline bool F_9 ( struct V_1 * V_2 ,
unsigned long V_8 )
__releases( V_2 -> V_9 )
{
V_2 -> V_4 = NULL ;
F_11 ( & V_2 -> V_9 , V_8 ) ;
return true ;
}
static inline int
F_13 ( struct V_10 * V_11 ,
struct V_10 * V_12 )
{
if ( V_11 -> V_13 < V_12 -> V_13 )
return 1 ;
if ( F_14 ( V_11 -> V_13 ) )
return F_15 ( V_11 -> V_14 , V_12 -> V_14 ) ;
return 0 ;
}
static inline int
F_16 ( struct V_10 * V_11 ,
struct V_10 * V_12 )
{
if ( V_11 -> V_13 != V_12 -> V_13 )
return 0 ;
if ( F_14 ( V_11 -> V_13 ) )
return V_11 -> V_14 == V_12 -> V_14 ;
return 1 ;
}
static void
F_17 ( struct V_1 * V_2 , struct V_10 * V_15 )
{
struct V_16 * * V_17 = & V_2 -> V_18 . V_19 . V_16 ;
struct V_16 * V_20 = NULL ;
struct V_10 * V_21 ;
bool V_22 = true ;
while ( * V_17 ) {
V_20 = * V_17 ;
V_21 = F_18 ( V_20 , struct V_10 , V_23 ) ;
if ( F_13 ( V_15 , V_21 ) ) {
V_17 = & V_20 -> V_24 ;
} else {
V_17 = & V_20 -> V_25 ;
V_22 = false ;
}
}
F_19 ( & V_15 -> V_23 , V_20 , V_17 ) ;
F_20 ( & V_15 -> V_23 , & V_2 -> V_18 , V_22 ) ;
}
static void
F_21 ( struct V_1 * V_2 , struct V_10 * V_15 )
{
if ( F_22 ( & V_15 -> V_23 ) )
return;
F_23 ( & V_15 -> V_23 , & V_2 -> V_18 ) ;
F_24 ( & V_15 -> V_23 ) ;
}
static void
F_25 ( struct V_3 * V_26 , struct V_10 * V_15 )
{
struct V_16 * * V_17 = & V_26 -> V_27 . V_19 . V_16 ;
struct V_16 * V_20 = NULL ;
struct V_10 * V_21 ;
bool V_22 = true ;
while ( * V_17 ) {
V_20 = * V_17 ;
V_21 = F_18 ( V_20 , struct V_10 , V_28 ) ;
if ( F_13 ( V_15 , V_21 ) ) {
V_17 = & V_20 -> V_24 ;
} else {
V_17 = & V_20 -> V_25 ;
V_22 = false ;
}
}
F_19 ( & V_15 -> V_28 , V_20 , V_17 ) ;
F_20 ( & V_15 -> V_28 , & V_26 -> V_27 , V_22 ) ;
}
static void
F_26 ( struct V_3 * V_26 , struct V_10 * V_15 )
{
if ( F_22 ( & V_15 -> V_28 ) )
return;
F_23 ( & V_15 -> V_28 , & V_26 -> V_27 ) ;
F_24 ( & V_15 -> V_28 ) ;
}
static void F_27 ( struct V_3 * V_7 )
{
struct V_3 * V_29 = NULL ;
F_28 ( & V_7 -> V_30 ) ;
if ( F_29 ( V_7 ) )
V_29 = F_30 ( V_7 ) -> V_26 ;
F_31 ( V_7 , V_29 ) ;
}
static bool F_32 ( struct V_10 * V_15 ,
enum V_31 V_32 )
{
return F_33 ( V_15 , V_32 ) ;
}
static inline struct V_1 * F_34 ( struct V_3 * V_7 )
{
return V_7 -> V_33 ? V_7 -> V_33 -> V_2 : NULL ;
}
static int F_35 ( struct V_3 * V_26 ,
enum V_31 V_32 ,
struct V_1 * V_34 ,
struct V_1 * V_35 ,
struct V_10 * V_36 ,
struct V_3 * V_37 )
{
struct V_10 * V_15 , * V_38 = V_36 ;
struct V_10 * V_39 ;
int V_40 = 0 , V_41 = 0 ;
struct V_1 * V_2 ;
bool V_42 ;
bool V_43 = true ;
V_42 = F_32 ( V_36 , V_32 ) ;
V_44:
if ( ++ V_41 > V_45 ) {
static int V_46 ;
if ( V_46 != V_45 ) {
V_46 = V_45 ;
F_36 ( V_47 L_1
L_2 , V_45 ,
V_37 -> V_48 , F_37 ( V_37 ) ) ;
}
F_38 ( V_26 ) ;
return - V_49 ;
}
V_50:
F_39 ( & V_26 -> V_30 ) ;
V_15 = V_26 -> V_33 ;
if ( ! V_15 )
goto V_51;
if ( V_36 && ! F_10 ( V_34 ) )
goto V_51;
if ( V_35 != V_15 -> V_2 )
goto V_51;
if ( V_38 ) {
if ( ! F_29 ( V_26 ) )
goto V_51;
if ( V_38 != F_30 ( V_26 ) ) {
if ( ! V_42 )
goto V_51;
else
V_43 = false ;
}
}
if ( F_16 ( V_15 , F_40 ( V_26 ) ) ) {
if ( ! V_42 )
goto V_51;
else
V_43 = false ;
}
V_2 = V_15 -> V_2 ;
if ( ! F_41 ( & V_2 -> V_9 ) ) {
F_42 ( & V_26 -> V_30 ) ;
F_43 () ;
goto V_50;
}
if ( V_2 == V_34 || F_10 ( V_2 ) == V_37 ) {
F_44 ( V_32 , V_36 , V_2 ) ;
F_45 ( & V_2 -> V_9 ) ;
V_40 = - V_49 ;
goto V_51;
}
if ( ! V_43 ) {
F_45 ( & V_26 -> V_30 ) ;
F_38 ( V_26 ) ;
if ( ! F_10 ( V_2 ) ) {
F_42 ( & V_2 -> V_9 ) ;
return 0 ;
}
V_26 = F_10 ( V_2 ) ;
F_46 ( V_26 ) ;
F_47 ( & V_26 -> V_30 ) ;
V_35 = F_34 ( V_26 ) ;
V_38 = F_48 ( V_2 ) ;
F_45 ( & V_26 -> V_30 ) ;
F_42 ( & V_2 -> V_9 ) ;
if ( ! V_35 )
goto V_52;
goto V_44;
}
V_39 = F_48 ( V_2 ) ;
F_21 ( V_2 , V_15 ) ;
V_15 -> V_13 = V_26 -> V_13 ;
V_15 -> V_14 = V_26 -> V_53 . V_14 ;
F_17 ( V_2 , V_15 ) ;
F_45 ( & V_26 -> V_30 ) ;
F_38 ( V_26 ) ;
if ( ! F_10 ( V_2 ) ) {
if ( V_39 != F_48 ( V_2 ) )
F_49 ( F_48 ( V_2 ) -> V_26 ) ;
F_42 ( & V_2 -> V_9 ) ;
return 0 ;
}
V_26 = F_10 ( V_2 ) ;
F_46 ( V_26 ) ;
F_47 ( & V_26 -> V_30 ) ;
if ( V_15 == F_48 ( V_2 ) ) {
F_26 ( V_26 , V_39 ) ;
F_25 ( V_26 , V_15 ) ;
F_27 ( V_26 ) ;
} else if ( V_39 == V_15 ) {
F_26 ( V_26 , V_15 ) ;
V_15 = F_48 ( V_2 ) ;
F_25 ( V_26 , V_15 ) ;
F_27 ( V_26 ) ;
} else {
}
V_35 = F_34 ( V_26 ) ;
V_38 = F_48 ( V_2 ) ;
F_45 ( & V_26 -> V_30 ) ;
F_42 ( & V_2 -> V_9 ) ;
if ( ! V_35 )
goto V_52;
if ( ! V_42 && V_15 != V_38 )
goto V_52;
goto V_44;
V_51:
F_42 ( & V_26 -> V_30 ) ;
V_52:
F_38 ( V_26 ) ;
return V_40 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_3 * V_26 ,
struct V_10 * V_15 )
{
F_28 ( & V_2 -> V_9 ) ;
F_7 ( V_2 ) ;
if ( F_10 ( V_2 ) )
return 0 ;
if ( V_15 ) {
if ( V_15 != F_48 ( V_2 ) )
return 0 ;
F_21 ( V_2 , V_15 ) ;
} else {
if ( F_2 ( V_2 ) ) {
if ( ! F_13 ( F_40 ( V_26 ) ,
F_48 ( V_2 ) ) )
return 0 ;
} else {
goto V_54;
}
}
F_47 ( & V_26 -> V_30 ) ;
V_26 -> V_33 = NULL ;
if ( F_2 ( V_2 ) )
F_25 ( V_26 , F_48 ( V_2 ) ) ;
F_45 ( & V_26 -> V_30 ) ;
V_54:
F_51 ( V_2 ) ;
F_1 ( V_2 , V_26 ) ;
return 1 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_10 * V_15 ,
struct V_3 * V_26 ,
enum V_31 V_32 )
{
struct V_3 * V_4 = F_10 ( V_2 ) ;
struct V_10 * V_38 = V_15 ;
struct V_1 * V_35 ;
int V_55 = 0 , V_56 ;
F_28 ( & V_2 -> V_9 ) ;
if ( V_4 == V_26 )
return - V_49 ;
F_47 ( & V_26 -> V_30 ) ;
V_15 -> V_26 = V_26 ;
V_15 -> V_2 = V_2 ;
V_15 -> V_13 = V_26 -> V_13 ;
V_15 -> V_14 = V_26 -> V_53 . V_14 ;
if ( F_2 ( V_2 ) )
V_38 = F_48 ( V_2 ) ;
F_17 ( V_2 , V_15 ) ;
V_26 -> V_33 = V_15 ;
F_45 ( & V_26 -> V_30 ) ;
if ( ! V_4 )
return 0 ;
F_47 ( & V_4 -> V_30 ) ;
if ( V_15 == F_48 ( V_2 ) ) {
F_26 ( V_4 , V_38 ) ;
F_25 ( V_4 , V_15 ) ;
F_27 ( V_4 ) ;
if ( V_4 -> V_33 )
V_55 = 1 ;
} else if ( F_32 ( V_15 , V_32 ) ) {
V_55 = 1 ;
}
V_35 = F_34 ( V_4 ) ;
F_45 ( & V_4 -> V_30 ) ;
if ( ! V_55 || ! V_35 )
return 0 ;
F_46 ( V_4 ) ;
F_42 ( & V_2 -> V_9 ) ;
V_56 = F_35 ( V_4 , V_32 , V_2 ,
V_35 , V_15 , V_26 ) ;
F_39 ( & V_2 -> V_9 ) ;
return V_56 ;
}
static void F_53 ( struct V_57 * V_58 ,
struct V_1 * V_2 )
{
struct V_10 * V_15 ;
F_47 ( & V_59 -> V_30 ) ;
V_15 = F_48 ( V_2 ) ;
F_26 ( V_59 , V_15 ) ;
F_27 ( V_59 ) ;
V_2 -> V_4 = ( void * ) V_6 ;
F_54 () ;
F_55 ( V_58 , V_15 -> V_26 ) ;
F_45 ( & V_59 -> V_30 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_10 * V_15 )
{
bool V_60 = ( V_15 == F_48 ( V_2 ) ) ;
struct V_3 * V_4 = F_10 ( V_2 ) ;
struct V_1 * V_35 ;
F_28 ( & V_2 -> V_9 ) ;
F_47 ( & V_59 -> V_30 ) ;
F_21 ( V_2 , V_15 ) ;
V_59 -> V_33 = NULL ;
F_45 ( & V_59 -> V_30 ) ;
if ( ! V_4 || ! V_60 )
return;
F_47 ( & V_4 -> V_30 ) ;
F_26 ( V_4 , V_15 ) ;
if ( F_2 ( V_2 ) )
F_25 ( V_4 , F_48 ( V_2 ) ) ;
F_27 ( V_4 ) ;
V_35 = F_34 ( V_4 ) ;
F_45 ( & V_4 -> V_30 ) ;
if ( ! V_35 )
return;
F_46 ( V_4 ) ;
F_42 ( & V_2 -> V_9 ) ;
F_35 ( V_4 , V_61 , V_2 ,
V_35 , NULL , V_59 ) ;
F_39 ( & V_2 -> V_9 ) ;
}
void F_57 ( struct V_3 * V_26 )
{
struct V_10 * V_15 ;
struct V_1 * V_35 ;
unsigned long V_8 ;
F_58 ( & V_26 -> V_30 , V_8 ) ;
V_15 = V_26 -> V_33 ;
if ( ! V_15 || F_16 ( V_15 , F_40 ( V_26 ) ) ) {
F_11 ( & V_26 -> V_30 , V_8 ) ;
return;
}
V_35 = V_15 -> V_2 ;
F_11 ( & V_26 -> V_30 , V_8 ) ;
F_46 ( V_26 ) ;
F_35 ( V_26 , V_61 , NULL ,
V_35 , NULL , V_26 ) ;
}
void F_59 ( struct V_10 * V_15 )
{
F_60 ( V_15 ) ;
F_24 ( & V_15 -> V_28 ) ;
F_24 ( & V_15 -> V_23 ) ;
V_15 -> V_26 = NULL ;
}
static int T_1
F_61 ( struct V_1 * V_2 , int V_62 ,
struct V_63 * V_64 ,
struct V_10 * V_15 )
{
int V_40 = 0 ;
for (; ; ) {
if ( F_50 ( V_2 , V_59 , V_15 ) )
break;
if ( F_62 ( V_62 == V_65 ) ) {
if ( F_63 ( V_59 ) )
V_40 = - V_66 ;
if ( V_64 && ! V_64 -> V_26 )
V_40 = - V_67 ;
if ( V_40 )
break;
}
F_42 ( & V_2 -> V_9 ) ;
F_64 ( V_15 ) ;
F_65 () ;
F_39 ( & V_2 -> V_9 ) ;
F_66 ( V_62 ) ;
}
F_67 ( V_68 ) ;
return V_40 ;
}
static void F_68 ( int V_56 , int V_42 ,
struct V_10 * V_69 )
{
if ( V_56 != - V_70 || V_42 )
return;
F_69 ( V_69 ) ;
while ( 1 ) {
F_66 ( V_65 ) ;
F_65 () ;
}
}
static int T_1
F_70 ( struct V_1 * V_2 , int V_62 ,
struct V_63 * V_64 ,
enum V_31 V_32 )
{
struct V_10 V_15 ;
unsigned long V_8 ;
int V_40 = 0 ;
F_59 ( & V_15 ) ;
F_58 ( & V_2 -> V_9 , V_8 ) ;
if ( F_50 ( V_2 , V_59 , NULL ) ) {
F_11 ( & V_2 -> V_9 , V_8 ) ;
return 0 ;
}
F_66 ( V_62 ) ;
if ( F_71 ( V_64 ) )
F_72 ( & V_64 -> V_71 , V_72 ) ;
V_40 = F_52 ( V_2 , & V_15 , V_59 , V_32 ) ;
if ( F_62 ( ! V_40 ) )
V_40 = F_61 ( V_2 , V_62 , V_64 , & V_15 ) ;
if ( F_71 ( V_40 ) ) {
F_67 ( V_68 ) ;
if ( F_2 ( V_2 ) )
F_56 ( V_2 , & V_15 ) ;
F_68 ( V_40 , V_32 , & V_15 ) ;
}
F_4 ( V_2 ) ;
F_11 ( & V_2 -> V_9 , V_8 ) ;
if ( F_71 ( V_64 ) )
F_73 ( & V_64 -> V_71 ) ;
F_74 ( & V_15 ) ;
return V_40 ;
}
static inline int F_75 ( struct V_1 * V_2 )
{
unsigned long V_8 ;
int V_40 ;
if ( F_10 ( V_2 ) )
return 0 ;
F_58 ( & V_2 -> V_9 , V_8 ) ;
V_40 = F_50 ( V_2 , V_59 , NULL ) ;
F_4 ( V_2 ) ;
F_11 ( & V_2 -> V_9 , V_8 ) ;
return V_40 ;
}
static bool T_1 F_76 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
unsigned long V_8 ;
F_58 ( & V_2 -> V_9 , V_8 ) ;
F_77 ( V_2 ) ;
while ( ! F_2 ( V_2 ) ) {
if ( F_9 ( V_2 , V_8 ) == true )
return false ;
F_58 ( & V_2 -> V_9 , V_8 ) ;
}
F_53 ( V_58 , V_2 ) ;
F_11 ( & V_2 -> V_9 , V_8 ) ;
return true ;
}
static inline int
F_78 ( struct V_1 * V_2 , int V_62 ,
int (* F_79)( struct V_1 * V_2 , int V_62 ,
struct V_63 * V_64 ,
enum V_31 V_32 ) )
{
if ( F_62 ( F_80 ( V_2 , NULL , V_59 ) ) )
return 0 ;
return F_79 ( V_2 , V_62 , NULL , V_61 ) ;
}
static inline int
F_81 ( struct V_1 * V_2 , int V_62 ,
struct V_63 * V_64 ,
enum V_31 V_32 ,
int (* F_79)( struct V_1 * V_2 , int V_62 ,
struct V_63 * V_64 ,
enum V_31 V_32 ) )
{
if ( V_32 == V_61 &&
F_62 ( F_80 ( V_2 , NULL , V_59 ) ) )
return 0 ;
return F_79 ( V_2 , V_62 , V_64 , V_32 ) ;
}
static inline int
F_82 ( struct V_1 * V_2 ,
int (* F_79)( struct V_1 * V_2 ) )
{
if ( F_62 ( F_80 ( V_2 , NULL , V_59 ) ) )
return 1 ;
return F_79 ( V_2 ) ;
}
void F_83 ( struct V_57 * V_58 )
{
F_84 ( V_58 ) ;
F_85 () ;
}
static inline void
F_86 ( struct V_1 * V_2 ,
bool (* F_79)( struct V_1 * V_2 ,
struct V_57 * V_73 ) )
{
F_87 ( V_58 ) ;
if ( F_62 ( F_12 ( V_2 , V_59 , NULL ) ) )
return;
if ( F_79 ( V_2 , & V_58 ) )
F_83 ( & V_58 ) ;
}
void T_1 F_88 ( struct V_1 * V_2 )
{
F_89 () ;
F_90 ( & V_2 -> V_74 , 0 , 0 , V_75 ) ;
F_78 ( V_2 , V_76 , F_70 ) ;
}
int T_1 F_91 ( struct V_1 * V_2 )
{
int V_40 ;
F_89 () ;
F_90 ( & V_2 -> V_74 , 0 , 0 , V_75 ) ;
V_40 = F_78 ( V_2 , V_65 , F_70 ) ;
if ( V_40 )
F_92 ( & V_2 -> V_74 , 1 , V_75 ) ;
return V_40 ;
}
int T_1 F_93 ( struct V_1 * V_2 )
{
return F_75 ( V_2 ) ;
}
int
F_94 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
int V_40 ;
F_89 () ;
F_90 ( & V_2 -> V_74 , 0 , 0 , V_75 ) ;
V_40 = F_81 ( V_2 , V_65 , V_64 ,
V_61 ,
F_70 ) ;
if ( V_40 )
F_92 ( & V_2 -> V_74 , 1 , V_75 ) ;
return V_40 ;
}
int T_1 F_95 ( struct V_1 * V_2 )
{
int V_40 ;
if ( F_96 ( F_97 () || F_98 () || F_99 () ) )
return 0 ;
V_40 = F_82 ( V_2 , F_75 ) ;
if ( V_40 )
F_90 ( & V_2 -> V_74 , 0 , 1 , V_75 ) ;
return V_40 ;
}
void T_1 F_100 ( struct V_1 * V_2 )
{
F_92 ( & V_2 -> V_74 , 1 , V_75 ) ;
F_86 ( V_2 , F_76 ) ;
}
bool T_1 F_101 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
F_28 ( & V_2 -> V_9 ) ;
F_77 ( V_2 ) ;
if ( ! F_2 ( V_2 ) ) {
V_2 -> V_4 = NULL ;
return false ;
}
F_53 ( V_58 , V_2 ) ;
return true ;
}
void T_1 F_102 ( struct V_1 * V_2 )
{
F_87 ( V_58 ) ;
bool V_77 ;
F_39 ( & V_2 -> V_9 ) ;
V_77 = F_101 ( V_2 , & V_58 ) ;
F_42 ( & V_2 -> V_9 ) ;
if ( V_77 )
F_83 ( & V_58 ) ;
}
void F_103 ( struct V_1 * V_2 )
{
F_104 ( F_105 ( V_2 ) ) ;
#ifdef F_106
V_2 -> V_78 = NULL ;
#endif
}
void F_107 ( struct V_1 * V_2 , const char * V_79 ,
struct V_80 * V_81 )
{
V_2 -> V_4 = NULL ;
F_108 ( & V_2 -> V_9 ) ;
V_2 -> V_18 = V_82 ;
if ( V_79 && V_81 )
F_109 ( V_2 , V_79 , V_81 ) ;
}
void F_110 ( struct V_1 * V_2 ,
struct V_3 * V_83 )
{
F_107 ( V_2 , NULL , NULL ) ;
F_111 ( V_2 , V_83 ) ;
F_1 ( V_2 , V_83 ) ;
}
void F_112 ( struct V_1 * V_2 ,
struct V_3 * V_83 )
{
F_113 ( V_2 ) ;
F_1 ( V_2 , NULL ) ;
}
int F_114 ( struct V_1 * V_2 ,
struct V_10 * V_15 ,
struct V_3 * V_26 )
{
int V_40 ;
if ( F_50 ( V_2 , V_26 , NULL ) )
return 1 ;
V_40 = F_52 ( V_2 , V_15 , V_26 ,
V_84 ) ;
if ( V_40 && ! F_10 ( V_2 ) ) {
V_40 = 0 ;
}
if ( F_71 ( V_40 ) )
F_56 ( V_2 , V_15 ) ;
F_64 ( V_15 ) ;
return V_40 ;
}
int F_115 ( struct V_1 * V_2 ,
struct V_10 * V_15 ,
struct V_3 * V_26 )
{
int V_40 ;
F_39 ( & V_2 -> V_9 ) ;
V_40 = F_114 ( V_2 , V_15 , V_26 ) ;
F_42 ( & V_2 -> V_9 ) ;
return V_40 ;
}
struct V_3 * F_116 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) )
return NULL ;
return F_48 ( V_2 ) -> V_26 ;
}
int F_117 ( struct V_1 * V_2 ,
struct V_63 * V_85 ,
struct V_10 * V_15 )
{
int V_40 ;
F_39 ( & V_2 -> V_9 ) ;
F_66 ( V_65 ) ;
V_40 = F_61 ( V_2 , V_65 , V_85 , V_15 ) ;
F_4 ( V_2 ) ;
F_42 ( & V_2 -> V_9 ) ;
return V_40 ;
}
bool F_118 ( struct V_1 * V_2 ,
struct V_10 * V_15 )
{
bool V_86 = false ;
F_39 ( & V_2 -> V_9 ) ;
F_50 ( V_2 , V_59 , V_15 ) ;
if ( F_10 ( V_2 ) != V_59 ) {
F_56 ( V_2 , V_15 ) ;
V_86 = true ;
}
F_4 ( V_2 ) ;
F_42 ( & V_2 -> V_9 ) ;
return V_86 ;
}
