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
return 0 ;
return F_28 ( V_13 ) -> V_13 -> V_12 <= V_31 ;
}
static void F_31 ( struct V_3 * V_13 )
{
int V_12 = F_24 ( V_13 ) ;
if ( V_13 -> V_12 != V_12 || F_12 ( V_12 ) )
F_32 ( V_13 , V_12 ) ;
}
static void F_33 ( struct V_3 * V_13 )
{
unsigned long V_32 ;
F_34 ( & V_13 -> V_33 , V_32 ) ;
F_31 ( V_13 ) ;
F_35 ( & V_13 -> V_33 , V_32 ) ;
}
static inline struct V_1 * F_36 ( struct V_3 * V_7 )
{
return V_7 -> V_34 ? V_7 -> V_34 -> V_2 : NULL ;
}
static int F_37 ( struct V_3 * V_13 ,
int V_35 ,
struct V_1 * V_36 ,
struct V_1 * V_37 ,
struct V_9 * V_38 ,
struct V_3 * V_39 )
{
struct V_1 * V_2 ;
struct V_9 * V_16 , * V_40 = V_38 ;
int V_41 , V_42 = 0 , V_43 = 0 ;
unsigned long V_32 ;
V_41 = F_38 ( V_38 ,
V_35 ) ;
V_44:
if ( ++ V_43 > V_45 ) {
static int V_46 ;
if ( V_46 != V_45 ) {
V_46 = V_45 ;
F_39 ( V_47 L_1
L_2 , V_45 ,
V_39 -> V_48 , F_40 ( V_39 ) ) ;
}
F_41 ( V_13 ) ;
return - V_49 ;
}
V_50:
F_34 ( & V_13 -> V_33 , V_32 ) ;
V_16 = V_13 -> V_34 ;
if ( ! V_16 )
goto V_51;
if ( V_38 && ! F_8 ( V_36 ) )
goto V_51;
if ( V_37 != V_16 -> V_2 )
goto V_51;
if ( V_40 ) {
if ( ! F_26 ( V_13 ) )
goto V_51;
if ( ! V_41 && V_40 != F_28 ( V_13 ) )
goto V_51;
}
if ( ! V_41 && V_16 -> V_12 == V_13 -> V_12 )
goto V_51;
V_2 = V_16 -> V_2 ;
if ( ! F_42 ( & V_2 -> V_8 ) ) {
F_35 ( & V_13 -> V_33 , V_32 ) ;
F_43 () ;
goto V_50;
}
if ( V_2 == V_36 || F_8 ( V_2 ) == V_39 ) {
F_44 ( V_35 , V_38 , V_2 ) ;
F_9 ( & V_2 -> V_8 ) ;
V_42 = - V_49 ;
goto V_51;
}
V_40 = F_45 ( V_2 ) ;
F_17 ( V_2 , V_16 ) ;
V_16 -> V_12 = V_13 -> V_12 ;
F_13 ( V_2 , V_16 ) ;
F_35 ( & V_13 -> V_33 , V_32 ) ;
if ( ! F_8 ( V_2 ) ) {
if ( V_40 != F_45 ( V_2 ) )
F_46 ( F_45 ( V_2 ) -> V_13 ) ;
F_9 ( & V_2 -> V_8 ) ;
goto V_52;
}
F_41 ( V_13 ) ;
V_13 = F_8 ( V_2 ) ;
F_47 ( V_13 ) ;
F_34 ( & V_13 -> V_33 , V_32 ) ;
if ( V_16 == F_45 ( V_2 ) ) {
F_23 ( V_13 , V_40 ) ;
F_22 ( V_13 , V_16 ) ;
F_31 ( V_13 ) ;
} else if ( V_40 == V_16 ) {
F_23 ( V_13 , V_16 ) ;
V_16 = F_45 ( V_2 ) ;
F_22 ( V_13 , V_16 ) ;
F_31 ( V_13 ) ;
}
V_37 = F_36 ( V_13 ) ;
F_35 ( & V_13 -> V_33 , V_32 ) ;
V_40 = F_45 ( V_2 ) ;
F_9 ( & V_2 -> V_8 ) ;
if ( ! V_37 )
goto V_52;
if ( ! V_41 && V_16 != V_40 )
goto V_52;
goto V_44;
V_51:
F_35 ( & V_13 -> V_33 , V_32 ) ;
V_52:
F_41 ( V_13 ) ;
return V_42 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_3 * V_13 ,
struct V_9 * V_16 )
{
F_5 ( V_2 ) ;
if ( F_8 ( V_2 ) )
return 0 ;
if ( F_2 ( V_2 ) ) {
if ( V_13 -> V_12 >= F_45 ( V_2 ) -> V_12 ) {
if ( ! V_16 || V_16 != F_45 ( V_2 ) )
return 0 ;
}
}
if ( V_16 || F_2 ( V_2 ) ) {
unsigned long V_32 ;
struct V_9 * V_53 ;
F_34 ( & V_13 -> V_33 , V_32 ) ;
if ( V_16 ) {
F_17 ( V_2 , V_16 ) ;
V_13 -> V_34 = NULL ;
}
if ( F_2 ( V_2 ) ) {
V_53 = F_45 ( V_2 ) ;
F_22 ( V_13 , V_53 ) ;
}
F_35 ( & V_13 -> V_33 , V_32 ) ;
}
F_49 ( V_2 ) ;
F_1 ( V_2 , V_13 ) ;
F_50 ( V_2 , V_13 ) ;
return 1 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_9 * V_16 ,
struct V_3 * V_13 ,
int V_41 )
{
struct V_3 * V_4 = F_8 ( V_2 ) ;
struct V_9 * V_40 = V_16 ;
struct V_1 * V_37 ;
int V_54 = 0 , V_55 ;
unsigned long V_32 ;
if ( V_4 == V_13 )
return - V_49 ;
F_34 ( & V_13 -> V_33 , V_32 ) ;
F_31 ( V_13 ) ;
V_16 -> V_13 = V_13 ;
V_16 -> V_2 = V_2 ;
V_16 -> V_12 = V_13 -> V_12 ;
if ( F_2 ( V_2 ) )
V_40 = F_45 ( V_2 ) ;
F_13 ( V_2 , V_16 ) ;
V_13 -> V_34 = V_16 ;
F_35 ( & V_13 -> V_33 , V_32 ) ;
if ( ! V_4 )
return 0 ;
F_34 ( & V_4 -> V_33 , V_32 ) ;
if ( V_16 == F_45 ( V_2 ) ) {
F_23 ( V_4 , V_40 ) ;
F_22 ( V_4 , V_16 ) ;
F_31 ( V_4 ) ;
if ( V_4 -> V_34 )
V_54 = 1 ;
} else if ( F_38 ( V_16 , V_41 ) ) {
V_54 = 1 ;
}
V_37 = F_36 ( V_4 ) ;
F_35 ( & V_4 -> V_33 , V_32 ) ;
if ( ! V_54 || ! V_37 )
return 0 ;
F_47 ( V_4 ) ;
F_9 ( & V_2 -> V_8 ) ;
V_55 = F_37 ( V_4 , V_41 , V_2 ,
V_37 , V_16 , V_13 ) ;
F_52 ( & V_2 -> V_8 ) ;
return V_55 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_9 * V_16 ;
unsigned long V_32 ;
F_34 ( & V_56 -> V_33 , V_32 ) ;
V_16 = F_45 ( V_2 ) ;
F_23 ( V_56 , V_16 ) ;
V_2 -> V_4 = ( void * ) V_6 ;
F_35 ( & V_56 -> V_33 , V_32 ) ;
F_46 ( V_16 -> V_13 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_9 * V_16 )
{
int V_57 = ( V_16 == F_45 ( V_2 ) ) ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
struct V_1 * V_37 = NULL ;
unsigned long V_32 ;
F_34 ( & V_56 -> V_33 , V_32 ) ;
F_17 ( V_2 , V_16 ) ;
V_56 -> V_34 = NULL ;
F_35 ( & V_56 -> V_33 , V_32 ) ;
if ( ! V_4 )
return;
if ( V_57 ) {
F_34 ( & V_4 -> V_33 , V_32 ) ;
F_23 ( V_4 , V_16 ) ;
if ( F_2 ( V_2 ) ) {
struct V_9 * V_58 ;
V_58 = F_45 ( V_2 ) ;
F_22 ( V_4 , V_58 ) ;
}
F_31 ( V_4 ) ;
V_37 = F_36 ( V_4 ) ;
F_35 ( & V_4 -> V_33 , V_32 ) ;
}
if ( ! V_37 )
return;
F_47 ( V_4 ) ;
F_9 ( & V_2 -> V_8 ) ;
F_37 ( V_4 , 0 , V_2 , V_37 , NULL , V_56 ) ;
F_52 ( & V_2 -> V_8 ) ;
}
void F_55 ( struct V_3 * V_13 )
{
struct V_9 * V_16 ;
struct V_1 * V_37 ;
unsigned long V_32 ;
F_34 ( & V_13 -> V_33 , V_32 ) ;
V_16 = V_13 -> V_34 ;
if ( ! V_16 || ( V_16 -> V_12 == V_13 -> V_12 &&
! F_12 ( V_13 -> V_12 ) ) ) {
F_35 ( & V_13 -> V_33 , V_32 ) ;
return;
}
V_37 = V_16 -> V_2 ;
F_35 ( & V_13 -> V_33 , V_32 ) ;
F_47 ( V_13 ) ;
F_37 ( V_13 , 0 , NULL , V_37 , NULL , V_13 ) ;
}
static int T_1
F_56 ( struct V_1 * V_2 , int V_59 ,
struct V_60 * V_61 ,
struct V_9 * V_16 )
{
int V_42 = 0 ;
for (; ; ) {
if ( F_48 ( V_2 , V_56 , V_16 ) )
break;
if ( F_57 ( V_59 == V_62 ) ) {
if ( F_58 ( V_56 ) )
V_42 = - V_63 ;
if ( V_61 && ! V_61 -> V_13 )
V_42 = - V_64 ;
if ( V_42 )
break;
}
F_9 ( & V_2 -> V_8 ) ;
F_59 ( V_16 ) ;
F_60 ( V_2 ) ;
F_52 ( & V_2 -> V_8 ) ;
F_61 ( V_59 ) ;
}
return V_42 ;
}
static void F_62 ( int V_55 , int V_41 ,
struct V_9 * V_65 )
{
if ( V_55 != - V_66 || V_41 )
return;
F_63 ( V_65 ) ;
while ( 1 ) {
F_61 ( V_62 ) ;
F_64 () ;
}
}
static int T_1
F_65 ( struct V_1 * V_2 , int V_59 ,
struct V_60 * V_61 ,
int V_41 )
{
struct V_9 V_16 ;
int V_42 = 0 ;
F_66 ( & V_16 ) ;
F_21 ( & V_16 . V_28 ) ;
F_21 ( & V_16 . V_23 ) ;
F_52 ( & V_2 -> V_8 ) ;
if ( F_48 ( V_2 , V_56 , NULL ) ) {
F_9 ( & V_2 -> V_8 ) ;
return 0 ;
}
F_61 ( V_59 ) ;
if ( F_57 ( V_61 ) ) {
F_67 ( & V_61 -> V_67 , V_68 ) ;
if ( ! F_68 ( & V_61 -> V_67 ) )
V_61 -> V_13 = NULL ;
}
V_42 = F_51 ( V_2 , & V_16 , V_56 , V_41 ) ;
if ( F_25 ( ! V_42 ) )
V_42 = F_56 ( V_2 , V_59 , V_61 , & V_16 ) ;
F_61 ( V_69 ) ;
if ( F_57 ( V_42 ) ) {
F_54 ( V_2 , & V_16 ) ;
F_62 ( V_42 , V_41 , & V_16 ) ;
}
F_4 ( V_2 ) ;
F_9 ( & V_2 -> V_8 ) ;
if ( F_57 ( V_61 ) )
F_69 ( & V_61 -> V_67 ) ;
F_70 ( & V_16 ) ;
return V_42 ;
}
static inline int
F_71 ( struct V_1 * V_2 )
{
int V_42 = 0 ;
F_52 ( & V_2 -> V_8 ) ;
if ( F_25 ( F_8 ( V_2 ) != V_56 ) ) {
V_42 = F_48 ( V_2 , V_56 , NULL ) ;
F_4 ( V_2 ) ;
}
F_9 ( & V_2 -> V_8 ) ;
return V_42 ;
}
static void T_1
F_72 ( struct V_1 * V_2 )
{
F_52 ( & V_2 -> V_8 ) ;
F_73 ( V_2 ) ;
F_74 ( V_56 ) ;
while ( ! F_2 ( V_2 ) ) {
if ( F_7 ( V_2 ) == true )
return;
F_52 ( & V_2 -> V_8 ) ;
}
F_53 ( V_2 ) ;
F_9 ( & V_2 -> V_8 ) ;
F_33 ( V_56 ) ;
}
static inline int
F_75 ( struct V_1 * V_2 , int V_59 ,
int V_41 ,
int (* F_76)( struct V_1 * V_2 , int V_59 ,
struct V_60 * V_61 ,
int V_41 ) )
{
if ( ! V_41 && F_25 ( F_10 ( V_2 , NULL , V_56 ) ) ) {
F_50 ( V_2 , V_56 ) ;
return 0 ;
} else
return F_76 ( V_2 , V_59 , NULL , V_41 ) ;
}
static inline int
F_77 ( struct V_1 * V_2 , int V_59 ,
struct V_60 * V_61 , int V_41 ,
int (* F_76)( struct V_1 * V_2 , int V_59 ,
struct V_60 * V_61 ,
int V_41 ) )
{
if ( ! V_41 && F_25 ( F_10 ( V_2 , NULL , V_56 ) ) ) {
F_50 ( V_2 , V_56 ) ;
return 0 ;
} else
return F_76 ( V_2 , V_59 , V_61 , V_41 ) ;
}
static inline int
F_78 ( struct V_1 * V_2 ,
int (* F_76)( struct V_1 * V_2 ) )
{
if ( F_25 ( F_10 ( V_2 , NULL , V_56 ) ) ) {
F_50 ( V_2 , V_56 ) ;
return 1 ;
}
return F_76 ( V_2 ) ;
}
static inline void
F_79 ( struct V_1 * V_2 ,
void (* F_76)( struct V_1 * V_2 ) )
{
if ( F_25 ( F_10 ( V_2 , V_56 , NULL ) ) )
F_74 ( V_56 ) ;
else
F_76 ( V_2 ) ;
}
void T_1 F_80 ( struct V_1 * V_2 )
{
F_81 () ;
F_75 ( V_2 , V_70 , 0 , F_65 ) ;
}
int T_1 F_82 ( struct V_1 * V_2 ,
int V_41 )
{
F_81 () ;
return F_75 ( V_2 , V_62 ,
V_41 , F_65 ) ;
}
int
F_83 ( struct V_1 * V_2 , struct V_60 * V_61 ,
int V_41 )
{
F_81 () ;
return F_77 ( V_2 , V_62 , V_61 ,
V_41 , F_65 ) ;
}
int T_1 F_84 ( struct V_1 * V_2 )
{
return F_78 ( V_2 , F_71 ) ;
}
void T_1 F_85 ( struct V_1 * V_2 )
{
F_79 ( V_2 , F_72 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
F_87 ( F_88 ( V_2 ) ) ;
#ifdef F_89
V_2 -> V_71 = NULL ;
#endif
}
void F_90 ( struct V_1 * V_2 , const char * V_72 )
{
V_2 -> V_4 = NULL ;
F_91 ( & V_2 -> V_8 ) ;
V_2 -> V_19 = V_73 ;
V_2 -> V_26 = NULL ;
F_92 ( V_2 , V_72 ) ;
}
void F_93 ( struct V_1 * V_2 ,
struct V_3 * V_74 )
{
F_90 ( V_2 , NULL ) ;
F_94 ( V_2 , V_74 ) ;
F_1 ( V_2 , V_74 ) ;
F_50 ( V_2 , V_74 ) ;
}
void F_95 ( struct V_1 * V_2 ,
struct V_3 * V_74 )
{
F_96 ( V_2 ) ;
F_1 ( V_2 , NULL ) ;
F_74 ( V_74 ) ;
}
int F_97 ( struct V_1 * V_2 ,
struct V_9 * V_16 ,
struct V_3 * V_13 , int V_41 )
{
int V_42 ;
F_52 ( & V_2 -> V_8 ) ;
if ( F_48 ( V_2 , V_13 , NULL ) ) {
F_9 ( & V_2 -> V_8 ) ;
return 1 ;
}
V_42 = F_51 ( V_2 , V_16 , V_13 , 1 ) ;
if ( V_42 && ! F_8 ( V_2 ) ) {
V_42 = 0 ;
}
if ( F_57 ( V_42 ) )
F_54 ( V_2 , V_16 ) ;
F_9 ( & V_2 -> V_8 ) ;
F_59 ( V_16 ) ;
return V_42 ;
}
struct V_3 * F_98 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) )
return NULL ;
return F_45 ( V_2 ) -> V_13 ;
}
int F_99 ( struct V_1 * V_2 ,
struct V_60 * V_75 ,
struct V_9 * V_16 ,
int V_41 )
{
int V_42 ;
F_52 ( & V_2 -> V_8 ) ;
F_61 ( V_62 ) ;
V_42 = F_56 ( V_2 , V_62 , V_75 , V_16 ) ;
F_61 ( V_69 ) ;
if ( F_57 ( V_42 ) )
F_54 ( V_2 , V_16 ) ;
F_4 ( V_2 ) ;
F_9 ( & V_2 -> V_8 ) ;
return V_42 ;
}
