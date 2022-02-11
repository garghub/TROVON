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
static inline void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_4 = (struct V_3 * )
( ( unsigned long ) V_2 -> V_4 | V_6 ) ;
}
static inline int
F_7 ( struct V_8 * V_9 ,
struct V_8 * V_10 )
{
if ( V_9 -> V_11 < V_10 -> V_11 )
return 1 ;
if ( F_8 ( V_9 -> V_11 ) )
return ( V_9 -> V_12 -> V_13 . V_14 < V_10 -> V_12 -> V_13 . V_14 ) ;
return 0 ;
}
static void
F_9 ( struct V_1 * V_2 , struct V_8 * V_15 )
{
struct V_16 * * V_17 = & V_2 -> V_18 . V_16 ;
struct V_16 * V_19 = NULL ;
struct V_8 * V_20 ;
int V_21 = 1 ;
while ( * V_17 ) {
V_19 = * V_17 ;
V_20 = F_10 ( V_19 , struct V_8 , V_22 ) ;
if ( F_7 ( V_15 , V_20 ) ) {
V_17 = & V_19 -> V_23 ;
} else {
V_17 = & V_19 -> V_24 ;
V_21 = 0 ;
}
}
if ( V_21 )
V_2 -> V_25 = & V_15 -> V_22 ;
F_11 ( & V_15 -> V_22 , V_19 , V_17 ) ;
F_12 ( & V_15 -> V_22 , & V_2 -> V_18 ) ;
}
static void
F_13 ( struct V_1 * V_2 , struct V_8 * V_15 )
{
if ( F_14 ( & V_15 -> V_22 ) )
return;
if ( V_2 -> V_25 == & V_15 -> V_22 )
V_2 -> V_25 = F_15 ( & V_15 -> V_22 ) ;
F_16 ( & V_15 -> V_22 , & V_2 -> V_18 ) ;
F_17 ( & V_15 -> V_22 ) ;
}
static void
F_18 ( struct V_3 * V_12 , struct V_8 * V_15 )
{
struct V_16 * * V_17 = & V_12 -> V_26 . V_16 ;
struct V_16 * V_19 = NULL ;
struct V_8 * V_20 ;
int V_21 = 1 ;
while ( * V_17 ) {
V_19 = * V_17 ;
V_20 = F_10 ( V_19 , struct V_8 , V_27 ) ;
if ( F_7 ( V_15 , V_20 ) ) {
V_17 = & V_19 -> V_23 ;
} else {
V_17 = & V_19 -> V_24 ;
V_21 = 0 ;
}
}
if ( V_21 )
V_12 -> V_28 = & V_15 -> V_27 ;
F_11 ( & V_15 -> V_27 , V_19 , V_17 ) ;
F_12 ( & V_15 -> V_27 , & V_12 -> V_26 ) ;
}
static void
F_19 ( struct V_3 * V_12 , struct V_8 * V_15 )
{
if ( F_14 ( & V_15 -> V_27 ) )
return;
if ( V_12 -> V_28 == & V_15 -> V_27 )
V_12 -> V_28 = F_15 ( & V_15 -> V_27 ) ;
F_16 ( & V_15 -> V_27 , & V_12 -> V_26 ) ;
F_17 ( & V_15 -> V_27 ) ;
}
int F_20 ( struct V_3 * V_12 )
{
if ( F_21 ( ! F_22 ( V_12 ) ) )
return V_12 -> V_29 ;
return F_23 ( F_24 ( V_12 ) -> V_11 ,
V_12 -> V_29 ) ;
}
struct V_3 * F_25 ( struct V_3 * V_12 )
{
if ( F_21 ( ! F_22 ( V_12 ) ) )
return NULL ;
return F_24 ( V_12 ) -> V_12 ;
}
int F_26 ( struct V_3 * V_12 , int V_30 )
{
if ( ! F_22 ( V_12 ) )
return 0 ;
return F_24 ( V_12 ) -> V_12 -> V_11 <= V_30 ;
}
static void F_27 ( struct V_3 * V_12 )
{
int V_11 = F_20 ( V_12 ) ;
if ( V_12 -> V_11 != V_11 || F_8 ( V_11 ) )
F_28 ( V_12 , V_11 ) ;
}
static void F_29 ( struct V_3 * V_12 )
{
unsigned long V_31 ;
F_30 ( & V_12 -> V_32 , V_31 ) ;
F_27 ( V_12 ) ;
F_31 ( & V_12 -> V_32 , V_31 ) ;
}
static int F_32 ( struct V_3 * V_12 ,
int V_33 ,
struct V_1 * V_34 ,
struct V_8 * V_35 ,
struct V_3 * V_36 )
{
struct V_1 * V_2 ;
struct V_8 * V_15 , * V_37 = V_35 ;
int V_38 , V_39 = 0 , V_40 = 0 ;
unsigned long V_31 ;
V_38 = F_33 ( V_35 ,
V_33 ) ;
V_41:
if ( ++ V_40 > V_42 ) {
static int V_43 ;
if ( V_43 != V_42 ) {
V_43 = V_42 ;
F_34 ( V_44 L_1
L_2 , V_42 ,
V_36 -> V_45 , F_35 ( V_36 ) ) ;
}
F_36 ( V_12 ) ;
return V_33 ? - V_46 : 0 ;
}
V_47:
F_30 ( & V_12 -> V_32 , V_31 ) ;
V_15 = V_12 -> V_48 ;
if ( ! V_15 )
goto V_49;
if ( V_35 && ! F_37 ( V_34 ) )
goto V_49;
if ( V_37 ) {
if ( ! F_22 ( V_12 ) )
goto V_49;
if ( ! V_38 && V_37 != F_24 ( V_12 ) )
goto V_49;
}
if ( ! V_38 && V_15 -> V_11 == V_12 -> V_11 )
goto V_49;
V_2 = V_15 -> V_2 ;
if ( ! F_38 ( & V_2 -> V_50 ) ) {
F_31 ( & V_12 -> V_32 , V_31 ) ;
F_39 () ;
goto V_47;
}
if ( V_2 == V_34 || F_37 ( V_2 ) == V_36 ) {
F_40 ( V_33 , V_35 , V_2 ) ;
F_41 ( & V_2 -> V_50 ) ;
V_39 = V_33 ? - V_46 : 0 ;
goto V_49;
}
V_37 = F_42 ( V_2 ) ;
F_13 ( V_2 , V_15 ) ;
V_15 -> V_11 = V_12 -> V_11 ;
F_9 ( V_2 , V_15 ) ;
F_31 ( & V_12 -> V_32 , V_31 ) ;
if ( ! F_37 ( V_2 ) ) {
if ( V_37 != F_42 ( V_2 ) )
F_43 ( F_42 ( V_2 ) -> V_12 ) ;
F_41 ( & V_2 -> V_50 ) ;
goto V_51;
}
F_36 ( V_12 ) ;
V_12 = F_37 ( V_2 ) ;
F_44 ( V_12 ) ;
F_30 ( & V_12 -> V_32 , V_31 ) ;
if ( V_15 == F_42 ( V_2 ) ) {
F_19 ( V_12 , V_37 ) ;
F_18 ( V_12 , V_15 ) ;
F_27 ( V_12 ) ;
} else if ( V_37 == V_15 ) {
F_19 ( V_12 , V_15 ) ;
V_15 = F_42 ( V_2 ) ;
F_18 ( V_12 , V_15 ) ;
F_27 ( V_12 ) ;
}
F_31 ( & V_12 -> V_32 , V_31 ) ;
V_37 = F_42 ( V_2 ) ;
F_41 ( & V_2 -> V_50 ) ;
if ( ! V_38 && V_15 != V_37 )
goto V_51;
goto V_41;
V_49:
F_31 ( & V_12 -> V_32 , V_31 ) ;
V_51:
F_36 ( V_12 ) ;
return V_39 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_3 * V_12 ,
struct V_8 * V_15 )
{
F_5 ( V_2 ) ;
if ( F_37 ( V_2 ) )
return 0 ;
if ( F_2 ( V_2 ) ) {
if ( V_12 -> V_11 >= F_42 ( V_2 ) -> V_11 ) {
if ( ! V_15 || V_15 != F_42 ( V_2 ) )
return 0 ;
}
}
if ( V_15 || F_2 ( V_2 ) ) {
unsigned long V_31 ;
struct V_8 * V_52 ;
F_30 ( & V_12 -> V_32 , V_31 ) ;
if ( V_15 ) {
F_13 ( V_2 , V_15 ) ;
V_12 -> V_48 = NULL ;
}
if ( F_2 ( V_2 ) ) {
V_52 = F_42 ( V_2 ) ;
F_18 ( V_12 , V_52 ) ;
}
F_31 ( & V_12 -> V_32 , V_31 ) ;
}
F_46 ( V_2 ) ;
F_1 ( V_2 , V_12 ) ;
F_47 ( V_2 , V_12 ) ;
return 1 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_8 * V_15 ,
struct V_3 * V_12 ,
int V_38 )
{
struct V_3 * V_4 = F_37 ( V_2 ) ;
struct V_8 * V_37 = V_15 ;
unsigned long V_31 ;
int V_53 = 0 , V_54 ;
if ( V_38 && V_4 == V_12 )
return - V_46 ;
F_30 ( & V_12 -> V_32 , V_31 ) ;
F_27 ( V_12 ) ;
V_15 -> V_12 = V_12 ;
V_15 -> V_2 = V_2 ;
V_15 -> V_11 = V_12 -> V_11 ;
if ( F_2 ( V_2 ) )
V_37 = F_42 ( V_2 ) ;
F_9 ( V_2 , V_15 ) ;
V_12 -> V_48 = V_15 ;
F_31 ( & V_12 -> V_32 , V_31 ) ;
if ( ! V_4 )
return 0 ;
if ( V_15 == F_42 ( V_2 ) ) {
F_30 ( & V_4 -> V_32 , V_31 ) ;
F_19 ( V_4 , V_37 ) ;
F_18 ( V_4 , V_15 ) ;
F_27 ( V_4 ) ;
if ( V_4 -> V_48 )
V_53 = 1 ;
F_31 ( & V_4 -> V_32 , V_31 ) ;
}
else if ( F_33 ( V_15 , V_38 ) )
V_53 = 1 ;
if ( ! V_53 )
return 0 ;
F_44 ( V_4 ) ;
F_41 ( & V_2 -> V_50 ) ;
V_54 = F_32 ( V_4 , V_38 , V_2 , V_15 ,
V_12 ) ;
F_49 ( & V_2 -> V_50 ) ;
return V_54 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_8 * V_15 ;
unsigned long V_31 ;
F_30 ( & V_55 -> V_32 , V_31 ) ;
V_15 = F_42 ( V_2 ) ;
F_19 ( V_55 , V_15 ) ;
F_1 ( V_2 , NULL ) ;
F_31 ( & V_55 -> V_32 , V_31 ) ;
F_43 ( V_15 -> V_12 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_8 * V_15 )
{
int V_56 = ( V_15 == F_42 ( V_2 ) ) ;
struct V_3 * V_4 = F_37 ( V_2 ) ;
unsigned long V_31 ;
int V_53 = 0 ;
F_30 ( & V_55 -> V_32 , V_31 ) ;
F_13 ( V_2 , V_15 ) ;
V_55 -> V_48 = NULL ;
F_31 ( & V_55 -> V_32 , V_31 ) ;
if ( ! V_4 )
return;
if ( V_56 ) {
F_30 ( & V_4 -> V_32 , V_31 ) ;
F_19 ( V_4 , V_15 ) ;
if ( F_2 ( V_2 ) ) {
struct V_8 * V_57 ;
V_57 = F_42 ( V_2 ) ;
F_18 ( V_4 , V_57 ) ;
}
F_27 ( V_4 ) ;
if ( V_4 -> V_48 )
V_53 = 1 ;
F_31 ( & V_4 -> V_32 , V_31 ) ;
}
if ( ! V_53 )
return;
F_44 ( V_4 ) ;
F_41 ( & V_2 -> V_50 ) ;
F_32 ( V_4 , 0 , V_2 , NULL , V_55 ) ;
F_49 ( & V_2 -> V_50 ) ;
}
void F_52 ( struct V_3 * V_12 )
{
struct V_8 * V_15 ;
unsigned long V_31 ;
F_30 ( & V_12 -> V_32 , V_31 ) ;
V_15 = V_12 -> V_48 ;
if ( ! V_15 || ( V_15 -> V_11 == V_12 -> V_11 &&
! F_8 ( V_12 -> V_11 ) ) ) {
F_31 ( & V_12 -> V_32 , V_31 ) ;
return;
}
F_31 ( & V_12 -> V_32 , V_31 ) ;
F_44 ( V_12 ) ;
F_32 ( V_12 , 0 , NULL , NULL , V_12 ) ;
}
static int T_1
F_53 ( struct V_1 * V_2 , int V_58 ,
struct V_59 * V_60 ,
struct V_8 * V_15 )
{
int V_39 = 0 ;
for (; ; ) {
if ( F_45 ( V_2 , V_55 , V_15 ) )
break;
if ( F_54 ( V_58 == V_61 ) ) {
if ( F_55 ( V_55 ) )
V_39 = - V_62 ;
if ( V_60 && ! V_60 -> V_12 )
V_39 = - V_63 ;
if ( V_39 )
break;
}
F_41 ( & V_2 -> V_50 ) ;
F_56 ( V_15 ) ;
F_57 ( V_2 ) ;
F_49 ( & V_2 -> V_50 ) ;
F_58 ( V_58 ) ;
}
return V_39 ;
}
static int T_1
F_59 ( struct V_1 * V_2 , int V_58 ,
struct V_59 * V_60 ,
int V_38 )
{
struct V_8 V_15 ;
int V_39 = 0 ;
F_60 ( & V_15 ) ;
F_17 ( & V_15 . V_27 ) ;
F_17 ( & V_15 . V_22 ) ;
F_49 ( & V_2 -> V_50 ) ;
if ( F_45 ( V_2 , V_55 , NULL ) ) {
F_41 ( & V_2 -> V_50 ) ;
return 0 ;
}
F_58 ( V_58 ) ;
if ( F_54 ( V_60 ) ) {
F_61 ( & V_60 -> V_64 , V_65 ) ;
if ( ! F_62 ( & V_60 -> V_64 ) )
V_60 -> V_12 = NULL ;
}
V_39 = F_48 ( V_2 , & V_15 , V_55 , V_38 ) ;
if ( F_21 ( ! V_39 ) )
V_39 = F_53 ( V_2 , V_58 , V_60 , & V_15 ) ;
F_58 ( V_66 ) ;
if ( F_54 ( V_39 ) )
F_51 ( V_2 , & V_15 ) ;
F_4 ( V_2 ) ;
F_41 ( & V_2 -> V_50 ) ;
if ( F_54 ( V_60 ) )
F_63 ( & V_60 -> V_64 ) ;
F_64 ( & V_15 ) ;
return V_39 ;
}
static inline int
F_65 ( struct V_1 * V_2 )
{
int V_39 = 0 ;
F_49 ( & V_2 -> V_50 ) ;
if ( F_21 ( F_37 ( V_2 ) != V_55 ) ) {
V_39 = F_45 ( V_2 , V_55 , NULL ) ;
F_4 ( V_2 ) ;
}
F_41 ( & V_2 -> V_50 ) ;
return V_39 ;
}
static void T_1
F_66 ( struct V_1 * V_2 )
{
F_49 ( & V_2 -> V_50 ) ;
F_67 ( V_2 ) ;
F_68 ( V_55 ) ;
if ( ! F_2 ( V_2 ) ) {
V_2 -> V_4 = NULL ;
F_41 ( & V_2 -> V_50 ) ;
return;
}
F_50 ( V_2 ) ;
F_41 ( & V_2 -> V_50 ) ;
F_29 ( V_55 ) ;
}
static inline int
F_69 ( struct V_1 * V_2 , int V_58 ,
int V_38 ,
int (* F_70)( struct V_1 * V_2 , int V_58 ,
struct V_59 * V_60 ,
int V_38 ) )
{
if ( ! V_38 && F_21 ( F_71 ( V_2 , NULL , V_55 ) ) ) {
F_47 ( V_2 , V_55 ) ;
return 0 ;
} else
return F_70 ( V_2 , V_58 , NULL , V_38 ) ;
}
static inline int
F_72 ( struct V_1 * V_2 , int V_58 ,
struct V_59 * V_60 , int V_38 ,
int (* F_70)( struct V_1 * V_2 , int V_58 ,
struct V_59 * V_60 ,
int V_38 ) )
{
if ( ! V_38 && F_21 ( F_71 ( V_2 , NULL , V_55 ) ) ) {
F_47 ( V_2 , V_55 ) ;
return 0 ;
} else
return F_70 ( V_2 , V_58 , V_60 , V_38 ) ;
}
static inline int
F_73 ( struct V_1 * V_2 ,
int (* F_70)( struct V_1 * V_2 ) )
{
if ( F_21 ( F_71 ( V_2 , NULL , V_55 ) ) ) {
F_47 ( V_2 , V_55 ) ;
return 1 ;
}
return F_70 ( V_2 ) ;
}
static inline void
F_74 ( struct V_1 * V_2 ,
void (* F_70)( struct V_1 * V_2 ) )
{
if ( F_21 ( F_71 ( V_2 , V_55 , NULL ) ) )
F_68 ( V_55 ) ;
else
F_70 ( V_2 ) ;
}
void T_1 F_75 ( struct V_1 * V_2 )
{
F_76 () ;
F_69 ( V_2 , V_67 , 0 , F_59 ) ;
}
int T_1 F_77 ( struct V_1 * V_2 ,
int V_38 )
{
F_76 () ;
return F_69 ( V_2 , V_61 ,
V_38 , F_59 ) ;
}
int
F_78 ( struct V_1 * V_2 , struct V_59 * V_60 ,
int V_38 )
{
F_76 () ;
return F_72 ( V_2 , V_61 , V_60 ,
V_38 , F_59 ) ;
}
int T_1 F_79 ( struct V_1 * V_2 )
{
return F_73 ( V_2 , F_65 ) ;
}
void T_1 F_80 ( struct V_1 * V_2 )
{
F_74 ( V_2 , F_66 ) ;
}
void F_81 ( struct V_1 * V_2 )
{
F_82 ( F_83 ( V_2 ) ) ;
#ifdef F_84
V_2 -> V_68 = NULL ;
#endif
}
void F_85 ( struct V_1 * V_2 , const char * V_69 )
{
V_2 -> V_4 = NULL ;
F_86 ( & V_2 -> V_50 ) ;
V_2 -> V_18 = V_70 ;
V_2 -> V_25 = NULL ;
F_87 ( V_2 , V_69 ) ;
}
void F_88 ( struct V_1 * V_2 ,
struct V_3 * V_71 )
{
F_85 ( V_2 , NULL ) ;
F_89 ( V_2 , V_71 ) ;
F_1 ( V_2 , V_71 ) ;
F_47 ( V_2 , V_71 ) ;
}
void F_90 ( struct V_1 * V_2 ,
struct V_3 * V_71 )
{
F_91 ( V_2 ) ;
F_1 ( V_2 , NULL ) ;
F_68 ( V_71 ) ;
}
int F_92 ( struct V_1 * V_2 ,
struct V_8 * V_15 ,
struct V_3 * V_12 , int V_38 )
{
int V_39 ;
F_49 ( & V_2 -> V_50 ) ;
if ( F_45 ( V_2 , V_12 , NULL ) ) {
F_41 ( & V_2 -> V_50 ) ;
return 1 ;
}
V_39 = F_48 ( V_2 , V_15 , V_12 , V_38 ) ;
if ( V_39 && ! F_37 ( V_2 ) ) {
V_39 = 0 ;
}
if ( F_54 ( V_39 ) )
F_51 ( V_2 , V_15 ) ;
F_41 ( & V_2 -> V_50 ) ;
F_56 ( V_15 ) ;
return V_39 ;
}
struct V_3 * F_93 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) )
return NULL ;
return F_42 ( V_2 ) -> V_12 ;
}
int F_94 ( struct V_1 * V_2 ,
struct V_59 * V_72 ,
struct V_8 * V_15 ,
int V_38 )
{
int V_39 ;
F_49 ( & V_2 -> V_50 ) ;
F_58 ( V_61 ) ;
V_39 = F_53 ( V_2 , V_61 , V_72 , V_15 ) ;
F_58 ( V_66 ) ;
if ( F_54 ( V_39 ) )
F_51 ( V_2 , V_15 ) ;
F_4 ( V_2 ) ;
F_41 ( & V_2 -> V_50 ) ;
return V_39 ;
}
