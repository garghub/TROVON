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
struct V_16 * V_47 ;
if ( ! V_14 )
goto V_40;
for ( V_47 = V_14 -> V_48 ; V_47 ; V_47 = V_47 -> V_49 ) {
if ( ! V_47 -> V_19 )
continue;
if ( ! ( V_47 -> V_20 & V_50 ) )
continue;
V_42 = F_33 ( & V_47 -> V_19 -> V_51 ) ;
break;
}
V_40:
return V_42 ;
}
static unsigned long
F_36 ( struct V_13 * V_14 , unsigned long V_12 , T_1 * V_52 )
{
unsigned long V_42 = V_46 ;
struct V_16 * V_47 ;
for ( V_47 = F_10 ( V_14 , V_12 ) ; V_47 ; V_47 = V_47 -> V_49 ) {
if ( V_12 < V_47 -> V_53 || V_12 >= V_47 -> V_54 )
continue;
if ( V_47 -> V_19 ) {
V_42 = F_33 ( & V_47 -> V_19 -> V_51 ) ;
* V_52 = ( V_47 -> V_55 << V_56 ) + V_12 -
V_47 -> V_53 ;
} else {
* V_52 = V_12 ;
}
break;
}
if ( ! V_47 )
V_42 = V_57 ;
return V_42 ;
}
static void F_37 ( int V_58 )
{
F_15 ( V_24 ) ;
F_15 ( V_59 ) ;
F_15 ( V_58 ) ;
V_60 = V_57 ;
}
static void F_38 ( unsigned int V_61 )
{
F_15 ( V_24 ) ;
if ( V_61 )
F_15 ( V_62 ) ;
else
F_15 ( V_63 ) ;
}
static void
F_39 ( struct V_6 const * V_7 , unsigned long V_42 )
{
F_15 ( V_24 ) ;
F_15 ( V_64 ) ;
F_15 ( V_7 -> V_65 ) ;
F_15 ( V_42 ) ;
F_15 ( V_24 ) ;
F_15 ( V_66 ) ;
F_15 ( V_7 -> V_67 ) ;
}
static void F_40 ( unsigned long V_42 )
{
F_15 ( V_24 ) ;
F_15 ( V_68 ) ;
F_15 ( V_42 ) ;
}
static void F_41 ( void )
{
F_15 ( V_24 ) ;
F_15 ( V_69 ) ;
}
static void F_42 ( struct V_70 * V_71 , struct V_13 * V_14 )
{
unsigned long V_72 , V_73 , V_3 ;
unsigned long V_42 ;
T_1 V_52 ;
if ( ! F_43 ( V_71 , & V_72 ) )
return;
if ( ! F_43 ( V_71 , & V_73 ) )
return;
if ( ! F_44 ( V_71 ) )
return;
if ( V_14 ) {
V_42 = F_36 ( V_14 , V_73 , & V_52 ) ;
if ( V_42 == V_46 )
V_52 = V_73 ;
if ( V_42 == V_57 ) {
F_45 ( & V_74 . V_75 ) ;
V_52 = V_73 ;
}
if ( V_42 != V_60 ) {
F_40 ( V_42 ) ;
V_60 = V_42 ;
}
} else
V_52 = V_73 ;
F_15 ( V_24 ) ;
F_15 ( V_72 ) ;
F_15 ( V_52 ) ;
while ( F_43 ( V_71 , & V_3 ) )
F_15 ( V_3 ) ;
}
static inline void F_46 ( unsigned long V_52 , unsigned long V_76 )
{
F_15 ( V_52 ) ;
F_15 ( V_76 ) ;
}
static int
F_47 ( struct V_13 * V_14 , struct V_77 * V_78 , int V_61 )
{
unsigned long V_42 ;
T_1 V_52 ;
if ( V_61 ) {
F_46 ( V_78 -> V_79 , V_78 -> V_76 ) ;
return 1 ;
}
if ( ! V_14 ) {
F_45 ( & V_74 . V_80 ) ;
return 0 ;
}
V_42 = F_36 ( V_14 , V_78 -> V_79 , & V_52 ) ;
if ( V_42 == V_57 ) {
F_45 ( & V_74 . V_75 ) ;
return 0 ;
}
if ( V_42 != V_60 ) {
F_40 ( V_42 ) ;
V_60 = V_42 ;
}
F_46 ( V_52 , V_78 -> V_76 ) ;
return 1 ;
}
static void F_48 ( struct V_13 * V_14 )
{
if ( ! V_14 )
return;
F_11 ( & V_14 -> V_18 ) ;
F_49 ( V_14 ) ;
}
static struct V_13 * F_50 ( struct V_6 * V_7 )
{
struct V_13 * V_14 = F_51 ( V_7 ) ;
if ( V_14 )
F_9 ( & V_14 -> V_18 ) ;
return V_14 ;
}
static inline int F_52 ( unsigned long V_3 )
{
return V_3 == V_24 ;
}
static void F_18 ( void )
{
unsigned long V_5 ;
F_53 ( V_81 ) ;
struct V_6 * V_7 ;
struct V_6 * V_82 ;
F_2 ( & V_8 , V_5 ) ;
F_54 ( & V_83 , & V_81 ) ;
F_54 ( & V_10 , & V_83 ) ;
F_4 ( & V_8 , V_5 ) ;
F_55 (task, ttask, &local_dead_tasks, tasks) {
F_56 ( & V_7 -> V_9 ) ;
F_57 ( V_7 ) ;
}
}
static void F_58 ( int V_84 )
{
int V_58 ;
F_59 ( V_84 , V_27 ) ;
F_60 (i) {
if ( ! F_61 ( V_58 , V_27 ) )
return;
}
F_18 () ;
F_62 ( V_27 ) ;
}
void F_6 ( int V_84 )
{
struct V_13 * V_14 = NULL ;
struct V_13 * V_85 ;
unsigned long V_3 ;
struct V_6 * V_86 ;
unsigned long V_42 = 0 ;
int V_61 = 1 ;
T_2 V_87 = V_88 ;
unsigned int V_58 ;
unsigned long V_89 ;
unsigned long V_5 ;
struct V_70 V_71 ;
struct V_77 * V_90 ;
F_14 ( & V_23 ) ;
F_37 ( V_84 ) ;
F_63 ( V_84 ) ;
V_89 = F_64 ( V_84 ) ;
for ( V_58 = 0 ; V_58 < V_89 ; ++ V_58 ) {
V_90 = F_65 ( & V_71 , V_84 ) ;
if ( ! V_90 )
break;
if ( F_52 ( V_90 -> V_79 ) ) {
V_5 = V_90 -> V_76 ;
if ( V_5 & V_91 ) {
V_87 = V_92 ;
F_41 () ;
}
if ( V_5 & V_93 ) {
V_61 = V_5 & V_94 ;
if ( V_87 == V_88 )
V_87 = V_95 ;
F_38 ( V_5 & V_94 ) ;
}
if ( V_5 & V_96
&& F_43 ( & V_71 , & V_3 ) ) {
V_86 = (struct V_6 * ) V_3 ;
V_85 = V_14 ;
F_48 ( V_85 ) ;
V_14 = F_50 ( V_86 ) ;
if ( V_14 != V_85 )
V_42 = F_35 ( V_14 ) ;
F_39 ( V_86 , V_42 ) ;
}
if ( F_44 ( & V_71 ) )
F_42 ( & V_71 , V_14 ) ;
continue;
}
if ( V_87 < V_92 )
continue;
if ( F_47 ( V_14 , V_90 , V_61 ) )
continue;
if ( V_87 == V_92 ) {
V_87 = V_97 ;
F_45 ( & V_74 . V_98 ) ;
}
}
F_48 ( V_14 ) ;
F_58 ( V_84 ) ;
F_16 ( & V_23 ) ;
}
void F_66 ( unsigned long * V_99 , unsigned int V_100 ,
unsigned int V_101 , unsigned int V_102 )
{
int V_58 ;
V_58 = V_100 ;
F_14 ( & V_23 ) ;
while ( V_58 != V_101 ) {
F_15 ( V_99 [ V_58 ++ ] ) ;
if ( V_58 >= V_102 )
V_58 = 0 ;
}
F_16 ( & V_23 ) ;
}
