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
static void F_26 ( struct V_3 * V_12 )
{
int V_11 = F_20 ( V_12 ) ;
if ( V_12 -> V_11 != V_11 || F_8 ( V_11 ) )
F_27 ( V_12 , V_11 ) ;
}
static void F_28 ( struct V_3 * V_12 )
{
unsigned long V_30 ;
F_29 ( & V_12 -> V_31 , V_30 ) ;
F_26 ( V_12 ) ;
F_30 ( & V_12 -> V_31 , V_30 ) ;
}
static int F_31 ( struct V_3 * V_12 ,
int V_32 ,
struct V_1 * V_33 ,
struct V_8 * V_34 ,
struct V_3 * V_35 )
{
struct V_1 * V_2 ;
struct V_8 * V_15 , * V_36 = V_34 ;
int V_37 , V_38 = 0 , V_39 = 0 ;
unsigned long V_30 ;
V_37 = F_32 ( V_34 ,
V_32 ) ;
V_40:
if ( ++ V_39 > V_41 ) {
static int V_42 ;
if ( V_42 != V_41 ) {
V_42 = V_41 ;
F_33 ( V_43 L_1
L_2 , V_41 ,
V_35 -> V_44 , F_34 ( V_35 ) ) ;
}
F_35 ( V_12 ) ;
return V_32 ? - V_45 : 0 ;
}
V_46:
F_29 ( & V_12 -> V_31 , V_30 ) ;
V_15 = V_12 -> V_47 ;
if ( ! V_15 )
goto V_48;
if ( V_34 && ! F_36 ( V_33 ) )
goto V_48;
if ( V_36 && ( ! F_22 ( V_12 ) ||
V_36 != F_24 ( V_12 ) ) )
goto V_48;
if ( ! V_37 && V_15 -> V_11 == V_12 -> V_11 )
goto V_48;
V_2 = V_15 -> V_2 ;
if ( ! F_37 ( & V_2 -> V_49 ) ) {
F_30 ( & V_12 -> V_31 , V_30 ) ;
F_38 () ;
goto V_46;
}
if ( V_2 == V_33 || F_36 ( V_2 ) == V_35 ) {
F_39 ( V_32 , V_34 , V_2 ) ;
F_40 ( & V_2 -> V_49 ) ;
V_38 = V_32 ? - V_45 : 0 ;
goto V_48;
}
V_36 = F_41 ( V_2 ) ;
F_13 ( V_2 , V_15 ) ;
V_15 -> V_11 = V_12 -> V_11 ;
F_9 ( V_2 , V_15 ) ;
F_30 ( & V_12 -> V_31 , V_30 ) ;
if ( ! F_36 ( V_2 ) ) {
if ( V_36 != F_41 ( V_2 ) )
F_42 ( F_41 ( V_2 ) -> V_12 ) ;
F_40 ( & V_2 -> V_49 ) ;
goto V_50;
}
F_35 ( V_12 ) ;
V_12 = F_36 ( V_2 ) ;
F_43 ( V_12 ) ;
F_29 ( & V_12 -> V_31 , V_30 ) ;
if ( V_15 == F_41 ( V_2 ) ) {
F_19 ( V_12 , V_36 ) ;
F_18 ( V_12 , V_15 ) ;
F_26 ( V_12 ) ;
} else if ( V_36 == V_15 ) {
F_19 ( V_12 , V_15 ) ;
V_15 = F_41 ( V_2 ) ;
F_18 ( V_12 , V_15 ) ;
F_26 ( V_12 ) ;
}
F_30 ( & V_12 -> V_31 , V_30 ) ;
V_36 = F_41 ( V_2 ) ;
F_40 ( & V_2 -> V_49 ) ;
if ( ! V_37 && V_15 != V_36 )
goto V_50;
goto V_40;
V_48:
F_30 ( & V_12 -> V_31 , V_30 ) ;
V_50:
F_35 ( V_12 ) ;
return V_38 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_3 * V_12 ,
struct V_8 * V_15 )
{
F_5 ( V_2 ) ;
if ( F_36 ( V_2 ) )
return 0 ;
if ( F_2 ( V_2 ) ) {
if ( V_12 -> V_11 >= F_41 ( V_2 ) -> V_11 ) {
if ( ! V_15 || V_15 != F_41 ( V_2 ) )
return 0 ;
}
}
if ( V_15 || F_2 ( V_2 ) ) {
unsigned long V_30 ;
struct V_8 * V_51 ;
F_29 ( & V_12 -> V_31 , V_30 ) ;
if ( V_15 ) {
F_13 ( V_2 , V_15 ) ;
V_12 -> V_47 = NULL ;
}
if ( F_2 ( V_2 ) ) {
V_51 = F_41 ( V_2 ) ;
F_18 ( V_12 , V_51 ) ;
}
F_30 ( & V_12 -> V_31 , V_30 ) ;
}
F_45 ( V_2 ) ;
F_1 ( V_2 , V_12 ) ;
F_46 ( V_2 , V_12 ) ;
return 1 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_8 * V_15 ,
struct V_3 * V_12 ,
int V_37 )
{
struct V_3 * V_4 = F_36 ( V_2 ) ;
struct V_8 * V_36 = V_15 ;
unsigned long V_30 ;
int V_52 = 0 , V_53 ;
F_29 ( & V_12 -> V_31 , V_30 ) ;
F_26 ( V_12 ) ;
V_15 -> V_12 = V_12 ;
V_15 -> V_2 = V_2 ;
V_15 -> V_11 = V_12 -> V_11 ;
if ( F_2 ( V_2 ) )
V_36 = F_41 ( V_2 ) ;
F_9 ( V_2 , V_15 ) ;
V_12 -> V_47 = V_15 ;
F_30 ( & V_12 -> V_31 , V_30 ) ;
if ( ! V_4 )
return 0 ;
if ( V_15 == F_41 ( V_2 ) ) {
F_29 ( & V_4 -> V_31 , V_30 ) ;
F_19 ( V_4 , V_36 ) ;
F_18 ( V_4 , V_15 ) ;
F_26 ( V_4 ) ;
if ( V_4 -> V_47 )
V_52 = 1 ;
F_30 ( & V_4 -> V_31 , V_30 ) ;
}
else if ( F_32 ( V_15 , V_37 ) )
V_52 = 1 ;
if ( ! V_52 )
return 0 ;
F_43 ( V_4 ) ;
F_40 ( & V_2 -> V_49 ) ;
V_53 = F_31 ( V_4 , V_37 , V_2 , V_15 ,
V_12 ) ;
F_48 ( & V_2 -> V_49 ) ;
return V_53 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_8 * V_15 ;
unsigned long V_30 ;
F_29 ( & V_54 -> V_31 , V_30 ) ;
V_15 = F_41 ( V_2 ) ;
F_19 ( V_54 , V_15 ) ;
F_1 ( V_2 , NULL ) ;
F_30 ( & V_54 -> V_31 , V_30 ) ;
F_42 ( V_15 -> V_12 ) ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_8 * V_15 )
{
int V_55 = ( V_15 == F_41 ( V_2 ) ) ;
struct V_3 * V_4 = F_36 ( V_2 ) ;
unsigned long V_30 ;
int V_52 = 0 ;
F_29 ( & V_54 -> V_31 , V_30 ) ;
F_13 ( V_2 , V_15 ) ;
V_54 -> V_47 = NULL ;
F_30 ( & V_54 -> V_31 , V_30 ) ;
if ( ! V_4 )
return;
if ( V_55 ) {
F_29 ( & V_4 -> V_31 , V_30 ) ;
F_19 ( V_4 , V_15 ) ;
if ( F_2 ( V_2 ) ) {
struct V_8 * V_56 ;
V_56 = F_41 ( V_2 ) ;
F_18 ( V_4 , V_56 ) ;
}
F_26 ( V_4 ) ;
if ( V_4 -> V_47 )
V_52 = 1 ;
F_30 ( & V_4 -> V_31 , V_30 ) ;
}
if ( ! V_52 )
return;
F_43 ( V_4 ) ;
F_40 ( & V_2 -> V_49 ) ;
F_31 ( V_4 , 0 , V_2 , NULL , V_54 ) ;
F_48 ( & V_2 -> V_49 ) ;
}
void F_51 ( struct V_3 * V_12 )
{
struct V_8 * V_15 ;
unsigned long V_30 ;
F_29 ( & V_12 -> V_31 , V_30 ) ;
V_15 = V_12 -> V_47 ;
if ( ! V_15 || ( V_15 -> V_11 == V_12 -> V_11 &&
! F_8 ( V_12 -> V_11 ) ) ) {
F_30 ( & V_12 -> V_31 , V_30 ) ;
return;
}
F_30 ( & V_12 -> V_31 , V_30 ) ;
F_43 ( V_12 ) ;
F_31 ( V_12 , 0 , NULL , NULL , V_12 ) ;
}
static int T_1
F_52 ( struct V_1 * V_2 , int V_57 ,
struct V_58 * V_59 ,
struct V_8 * V_15 )
{
int V_38 = 0 ;
for (; ; ) {
if ( F_44 ( V_2 , V_54 , V_15 ) )
break;
if ( F_53 ( V_57 == V_60 ) ) {
if ( F_54 ( V_54 ) )
V_38 = - V_61 ;
if ( V_59 && ! V_59 -> V_12 )
V_38 = - V_62 ;
if ( V_38 )
break;
}
F_40 ( & V_2 -> V_49 ) ;
F_55 ( V_15 ) ;
F_56 ( V_2 ) ;
F_48 ( & V_2 -> V_49 ) ;
F_57 ( V_57 ) ;
}
return V_38 ;
}
static int T_1
F_58 ( struct V_1 * V_2 , int V_57 ,
struct V_58 * V_59 ,
int V_37 )
{
struct V_8 V_15 ;
int V_38 = 0 ;
F_59 ( & V_15 ) ;
F_17 ( & V_15 . V_27 ) ;
F_17 ( & V_15 . V_22 ) ;
F_48 ( & V_2 -> V_49 ) ;
if ( F_44 ( V_2 , V_54 , NULL ) ) {
F_40 ( & V_2 -> V_49 ) ;
return 0 ;
}
F_57 ( V_57 ) ;
if ( F_53 ( V_59 ) ) {
F_60 ( & V_59 -> V_63 , V_64 ) ;
if ( ! F_61 ( & V_59 -> V_63 ) )
V_59 -> V_12 = NULL ;
}
V_38 = F_47 ( V_2 , & V_15 , V_54 , V_37 ) ;
if ( F_21 ( ! V_38 ) )
V_38 = F_52 ( V_2 , V_57 , V_59 , & V_15 ) ;
F_57 ( V_65 ) ;
if ( F_53 ( V_38 ) )
F_50 ( V_2 , & V_15 ) ;
F_4 ( V_2 ) ;
F_40 ( & V_2 -> V_49 ) ;
if ( F_53 ( V_59 ) )
F_62 ( & V_59 -> V_63 ) ;
F_63 ( & V_15 ) ;
return V_38 ;
}
static inline int
F_64 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
F_48 ( & V_2 -> V_49 ) ;
if ( F_21 ( F_36 ( V_2 ) != V_54 ) ) {
V_38 = F_44 ( V_2 , V_54 , NULL ) ;
F_4 ( V_2 ) ;
}
F_40 ( & V_2 -> V_49 ) ;
return V_38 ;
}
static void T_1
F_65 ( struct V_1 * V_2 )
{
F_48 ( & V_2 -> V_49 ) ;
F_66 ( V_2 ) ;
F_67 ( V_54 ) ;
if ( ! F_2 ( V_2 ) ) {
V_2 -> V_4 = NULL ;
F_40 ( & V_2 -> V_49 ) ;
return;
}
F_49 ( V_2 ) ;
F_40 ( & V_2 -> V_49 ) ;
F_28 ( V_54 ) ;
}
static inline int
F_68 ( struct V_1 * V_2 , int V_57 ,
int V_37 ,
int (* F_69)( struct V_1 * V_2 , int V_57 ,
struct V_58 * V_59 ,
int V_37 ) )
{
if ( ! V_37 && F_21 ( F_70 ( V_2 , NULL , V_54 ) ) ) {
F_46 ( V_2 , V_54 ) ;
return 0 ;
} else
return F_69 ( V_2 , V_57 , NULL , V_37 ) ;
}
static inline int
F_71 ( struct V_1 * V_2 , int V_57 ,
struct V_58 * V_59 , int V_37 ,
int (* F_69)( struct V_1 * V_2 , int V_57 ,
struct V_58 * V_59 ,
int V_37 ) )
{
if ( ! V_37 && F_21 ( F_70 ( V_2 , NULL , V_54 ) ) ) {
F_46 ( V_2 , V_54 ) ;
return 0 ;
} else
return F_69 ( V_2 , V_57 , V_59 , V_37 ) ;
}
static inline int
F_72 ( struct V_1 * V_2 ,
int (* F_69)( struct V_1 * V_2 ) )
{
if ( F_21 ( F_70 ( V_2 , NULL , V_54 ) ) ) {
F_46 ( V_2 , V_54 ) ;
return 1 ;
}
return F_69 ( V_2 ) ;
}
static inline void
F_73 ( struct V_1 * V_2 ,
void (* F_69)( struct V_1 * V_2 ) )
{
if ( F_21 ( F_70 ( V_2 , V_54 , NULL ) ) )
F_67 ( V_54 ) ;
else
F_69 ( V_2 ) ;
}
void T_1 F_74 ( struct V_1 * V_2 )
{
F_75 () ;
F_68 ( V_2 , V_66 , 0 , F_58 ) ;
}
int T_1 F_76 ( struct V_1 * V_2 ,
int V_37 )
{
F_75 () ;
return F_68 ( V_2 , V_60 ,
V_37 , F_58 ) ;
}
int
F_77 ( struct V_1 * V_2 , struct V_58 * V_59 ,
int V_37 )
{
F_75 () ;
return F_71 ( V_2 , V_60 , V_59 ,
V_37 , F_58 ) ;
}
int T_1 F_78 ( struct V_1 * V_2 )
{
return F_72 ( V_2 , F_64 ) ;
}
void T_1 F_79 ( struct V_1 * V_2 )
{
F_73 ( V_2 , F_65 ) ;
}
void F_80 ( struct V_1 * V_2 )
{
F_81 ( F_82 ( V_2 ) ) ;
#ifdef F_83
V_2 -> V_67 = NULL ;
#endif
}
void F_84 ( struct V_1 * V_2 , const char * V_68 )
{
V_2 -> V_4 = NULL ;
F_85 ( & V_2 -> V_49 ) ;
V_2 -> V_18 = V_69 ;
V_2 -> V_25 = NULL ;
F_86 ( V_2 , V_68 ) ;
}
void F_87 ( struct V_1 * V_2 ,
struct V_3 * V_70 )
{
F_84 ( V_2 , NULL ) ;
F_88 ( V_2 , V_70 ) ;
F_1 ( V_2 , V_70 ) ;
F_46 ( V_2 , V_70 ) ;
}
void F_89 ( struct V_1 * V_2 ,
struct V_3 * V_70 )
{
F_90 ( V_2 ) ;
F_1 ( V_2 , NULL ) ;
F_67 ( V_70 ) ;
}
int F_91 ( struct V_1 * V_2 ,
struct V_8 * V_15 ,
struct V_3 * V_12 , int V_37 )
{
int V_38 ;
F_48 ( & V_2 -> V_49 ) ;
if ( F_44 ( V_2 , V_12 , NULL ) ) {
F_40 ( & V_2 -> V_49 ) ;
return 1 ;
}
V_38 = F_47 ( V_2 , V_15 , V_12 , V_37 ) ;
if ( V_38 && ! F_36 ( V_2 ) ) {
V_38 = 0 ;
}
if ( F_53 ( V_38 ) )
F_50 ( V_2 , V_15 ) ;
F_40 ( & V_2 -> V_49 ) ;
F_55 ( V_15 ) ;
return V_38 ;
}
struct V_3 * F_92 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) )
return NULL ;
return F_41 ( V_2 ) -> V_12 ;
}
int F_93 ( struct V_1 * V_2 ,
struct V_58 * V_71 ,
struct V_8 * V_15 ,
int V_37 )
{
int V_38 ;
F_48 ( & V_2 -> V_49 ) ;
F_57 ( V_60 ) ;
V_38 = F_52 ( V_2 , V_60 , V_71 , V_15 ) ;
F_57 ( V_65 ) ;
if ( F_53 ( V_38 ) )
F_50 ( V_2 , V_15 ) ;
F_4 ( V_2 ) ;
F_40 ( & V_2 -> V_49 ) ;
return V_38 ;
}
