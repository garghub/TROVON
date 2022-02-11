static int
F_1 ( struct V_1 * V_2 , unsigned long V_3 , void * V_4 )
{
unsigned long V_5 ;
struct V_6 * V_7 = V_4 ;
F_2 ( & V_8 , V_5 ) ;
F_3 ( & V_7 -> V_9 , & V_10 ) ;
F_4 ( & V_8 , V_5 ) ;
return V_11 ;
}
static int
F_5 ( struct V_1 * V_2 , unsigned long V_3 , void * V_4 )
{
F_6 ( F_7 () ) ;
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 , unsigned long V_3 , void * V_4 )
{
unsigned long V_12 = ( unsigned long ) V_4 ;
struct V_13 * V_14 = V_15 -> V_14 ;
struct V_16 * V_17 ;
F_9 ( & V_14 -> V_18 ) ;
V_17 = F_10 ( V_14 , V_12 ) ;
if ( V_17 && V_17 -> V_19 && ( V_17 -> V_20 & V_21 ) ) {
F_11 ( & V_14 -> V_18 ) ;
F_6 ( F_7 () ) ;
return 0 ;
}
F_11 ( & V_14 -> V_18 ) ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 , unsigned long V_3 , void * V_4 )
{
#ifdef F_13
if ( V_3 != V_22 )
return 0 ;
F_14 ( & V_23 ) ;
F_15 ( V_24 ) ;
F_15 ( V_25 ) ;
F_16 ( & V_23 ) ;
#endif
return 0 ;
}
static void F_17 ( void )
{
F_18 () ;
F_18 () ;
}
int F_19 ( void )
{
int V_26 ;
if ( ! F_20 ( & V_27 , V_28 ) )
return - V_29 ;
V_26 = F_21 ( & V_30 ) ;
if ( V_26 )
goto V_31;
V_26 = F_22 ( V_32 , & V_33 ) ;
if ( V_26 )
goto V_34;
V_26 = F_22 ( V_35 , & V_36 ) ;
if ( V_26 )
goto V_37;
V_26 = F_23 ( & V_38 ) ;
if ( V_26 )
goto V_39;
F_24 () ;
V_40:
return V_26 ;
V_39:
F_25 ( V_35 , & V_36 ) ;
V_37:
F_25 ( V_32 , & V_33 ) ;
V_34:
F_26 ( & V_30 ) ;
F_17 () ;
V_31:
F_27 ( V_27 ) ;
goto V_40;
}
void F_28 ( void )
{
F_29 () ;
F_30 ( & V_38 ) ;
F_25 ( V_35 , & V_36 ) ;
F_25 ( V_32 , & V_33 ) ;
F_26 ( & V_30 ) ;
F_31 () ;
F_32 () ;
F_17 () ;
F_27 ( V_27 ) ;
}
static inline unsigned long F_33 ( struct V_41 * V_41 )
{
unsigned long V_42 ;
if ( V_41 -> V_43 -> V_44 & V_45 )
return ( unsigned long ) V_41 -> V_43 ;
F_34 ( V_41 , & V_42 ) ;
return V_42 ;
}
static unsigned long F_35 ( struct V_13 * V_14 )
{
unsigned long V_42 = V_46 ;
struct V_47 * V_48 ;
if ( ! V_14 )
goto V_49;
V_48 = F_36 ( V_14 ) ;
if ( ! V_48 )
goto V_49;
V_42 = F_33 ( & V_48 -> V_50 ) ;
F_37 ( V_48 ) ;
V_49:
return V_42 ;
}
static unsigned long
F_38 ( struct V_13 * V_14 , unsigned long V_12 , T_1 * V_51 )
{
unsigned long V_42 = V_46 ;
struct V_16 * V_52 ;
F_9 ( & V_14 -> V_18 ) ;
for ( V_52 = F_10 ( V_14 , V_12 ) ; V_52 ; V_52 = V_52 -> V_53 ) {
if ( V_12 < V_52 -> V_54 || V_12 >= V_52 -> V_55 )
continue;
if ( V_52 -> V_19 ) {
V_42 = F_33 ( & V_52 -> V_19 -> V_50 ) ;
* V_51 = ( V_52 -> V_56 << V_57 ) + V_12 -
V_52 -> V_54 ;
} else {
* V_51 = V_12 ;
}
break;
}
if ( ! V_52 )
V_42 = V_58 ;
F_11 ( & V_14 -> V_18 ) ;
return V_42 ;
}
static void F_39 ( int V_59 )
{
F_15 ( V_24 ) ;
F_15 ( V_60 ) ;
F_15 ( V_59 ) ;
V_61 = V_58 ;
}
static void F_40 ( unsigned int V_62 )
{
F_15 ( V_24 ) ;
if ( V_62 )
F_15 ( V_63 ) ;
else
F_15 ( V_64 ) ;
}
static void
F_41 ( struct V_6 const * V_7 , unsigned long V_42 )
{
F_15 ( V_24 ) ;
F_15 ( V_65 ) ;
F_15 ( V_7 -> V_66 ) ;
F_15 ( V_42 ) ;
F_15 ( V_24 ) ;
F_15 ( V_67 ) ;
F_15 ( V_7 -> V_68 ) ;
}
static void F_42 ( unsigned long V_42 )
{
F_15 ( V_24 ) ;
F_15 ( V_69 ) ;
F_15 ( V_42 ) ;
}
static void F_43 ( void )
{
F_15 ( V_24 ) ;
F_15 ( V_70 ) ;
}
static void F_44 ( struct V_71 * V_72 , struct V_13 * V_14 )
{
unsigned long V_73 , V_74 , V_3 ;
unsigned long V_42 ;
T_1 V_51 ;
if ( ! F_45 ( V_72 , & V_73 ) )
return;
if ( ! F_45 ( V_72 , & V_74 ) )
return;
if ( ! F_46 ( V_72 ) )
return;
if ( V_14 ) {
V_42 = F_38 ( V_14 , V_74 , & V_51 ) ;
if ( V_42 == V_46 )
V_51 = V_74 ;
if ( V_42 == V_58 ) {
F_47 ( & V_75 . V_76 ) ;
V_51 = V_74 ;
}
if ( V_42 != V_61 ) {
F_42 ( V_42 ) ;
V_61 = V_42 ;
}
} else
V_51 = V_74 ;
F_15 ( V_24 ) ;
F_15 ( V_73 ) ;
F_15 ( V_51 ) ;
while ( F_45 ( V_72 , & V_3 ) )
F_15 ( V_3 ) ;
}
static inline void F_48 ( unsigned long V_51 , unsigned long V_77 )
{
F_15 ( V_51 ) ;
F_15 ( V_77 ) ;
}
static int
F_49 ( struct V_13 * V_14 , struct V_78 * V_79 , int V_62 )
{
unsigned long V_42 ;
T_1 V_51 ;
if ( V_62 ) {
F_48 ( V_79 -> V_80 , V_79 -> V_77 ) ;
return 1 ;
}
if ( ! V_14 ) {
F_47 ( & V_75 . V_81 ) ;
return 0 ;
}
V_42 = F_38 ( V_14 , V_79 -> V_80 , & V_51 ) ;
if ( V_42 == V_58 ) {
F_47 ( & V_75 . V_76 ) ;
return 0 ;
}
if ( V_42 != V_61 ) {
F_42 ( V_42 ) ;
V_61 = V_42 ;
}
F_48 ( V_51 , V_79 -> V_77 ) ;
return 1 ;
}
static void F_50 ( struct V_13 * V_14 )
{
if ( ! V_14 )
return;
F_51 ( V_14 ) ;
}
static inline int F_52 ( unsigned long V_3 )
{
return V_3 == V_24 ;
}
static void F_18 ( void )
{
unsigned long V_5 ;
F_53 ( V_82 ) ;
struct V_6 * V_7 ;
struct V_6 * V_83 ;
F_2 ( & V_8 , V_5 ) ;
F_54 ( & V_84 , & V_82 ) ;
F_54 ( & V_10 , & V_84 ) ;
F_4 ( & V_8 , V_5 ) ;
F_55 (task, ttask, &local_dead_tasks, tasks) {
F_56 ( & V_7 -> V_9 ) ;
F_57 ( V_7 ) ;
}
}
static void F_58 ( int V_85 )
{
int V_59 ;
F_59 ( V_85 , V_27 ) ;
F_60 (i) {
if ( ! F_61 ( V_59 , V_27 ) )
return;
}
F_18 () ;
F_62 ( V_27 ) ;
}
void F_6 ( int V_85 )
{
struct V_13 * V_14 = NULL ;
struct V_13 * V_86 ;
unsigned long V_3 ;
struct V_6 * V_87 ;
unsigned long V_42 = 0 ;
int V_62 = 1 ;
T_2 V_88 = V_89 ;
unsigned int V_59 ;
unsigned long V_90 ;
unsigned long V_5 ;
struct V_71 V_72 ;
struct V_78 * V_91 ;
F_14 ( & V_23 ) ;
F_39 ( V_85 ) ;
F_63 ( V_85 ) ;
V_90 = F_64 ( V_85 ) ;
for ( V_59 = 0 ; V_59 < V_90 ; ++ V_59 ) {
V_91 = F_65 ( & V_72 , V_85 ) ;
if ( ! V_91 )
break;
if ( F_52 ( V_91 -> V_80 ) ) {
V_5 = V_91 -> V_77 ;
if ( V_5 & V_92 ) {
V_88 = V_93 ;
F_43 () ;
}
if ( V_5 & V_94 ) {
V_62 = V_5 & V_95 ;
if ( V_88 == V_89 )
V_88 = V_96 ;
F_40 ( V_5 & V_95 ) ;
}
if ( V_5 & V_97
&& F_45 ( & V_72 , & V_3 ) ) {
V_87 = (struct V_6 * ) V_3 ;
V_86 = V_14 ;
F_50 ( V_86 ) ;
V_14 = F_66 ( V_87 ) ;
if ( V_14 != V_86 )
V_42 = F_35 ( V_14 ) ;
F_41 ( V_87 , V_42 ) ;
}
if ( F_46 ( & V_72 ) )
F_44 ( & V_72 , V_14 ) ;
continue;
}
if ( V_88 < V_93 )
continue;
if ( F_49 ( V_14 , V_91 , V_62 ) )
continue;
if ( V_88 == V_93 ) {
V_88 = V_98 ;
F_47 ( & V_75 . V_99 ) ;
}
}
F_50 ( V_14 ) ;
F_58 ( V_85 ) ;
F_16 ( & V_23 ) ;
}
void F_67 ( unsigned long * V_100 , unsigned int V_101 ,
unsigned int V_102 , unsigned int V_103 )
{
int V_59 ;
V_59 = V_101 ;
F_14 ( & V_23 ) ;
while ( V_59 != V_102 ) {
F_15 ( V_100 [ V_59 ++ ] ) ;
if ( V_59 >= V_103 )
V_59 = 0 ;
}
F_16 ( & V_23 ) ;
}
