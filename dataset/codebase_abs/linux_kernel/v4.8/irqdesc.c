static int T_1 F_1 ( char * V_1 )
{
F_2 ( & V_2 , V_3 ) ;
F_3 ( V_1 , V_2 ) ;
F_4 ( F_5 () , V_2 ) ;
return 1 ;
}
static void T_1 F_6 ( void )
{
#ifdef F_7
if ( ! V_2 )
F_2 ( & V_2 , V_3 ) ;
#endif
if ( F_8 ( V_2 ) )
F_9 ( V_2 ) ;
}
static void T_1 F_6 ( void )
{
}
static int F_10 ( struct V_4 * V_5 , T_2 V_6 , int V_7 )
{
if ( ! F_11 ( & V_5 -> V_8 . V_9 ,
V_6 , V_7 ) )
return - V_10 ;
#ifdef F_12
if ( ! F_11 ( & V_5 -> V_11 , V_6 , V_7 ) ) {
F_13 ( V_5 -> V_8 . V_9 ) ;
return - V_10 ;
}
#endif
return 0 ;
}
static void F_14 ( struct V_4 * V_5 , int V_7 ,
const struct V_12 * V_9 )
{
if ( ! V_9 )
V_9 = V_2 ;
F_15 ( V_5 -> V_8 . V_9 , V_9 ) ;
#ifdef F_12
F_16 ( V_5 -> V_11 ) ;
#endif
#ifdef F_17
V_5 -> V_8 . V_7 = V_7 ;
#endif
}
static inline int
F_10 ( struct V_4 * V_5 , T_2 V_6 , int V_7 ) { return 0 ; }
static inline void
F_14 ( struct V_4 * V_5 , int V_7 , const struct V_12 * V_9 ) { }
static void F_18 ( unsigned int V_13 , struct V_4 * V_5 , int V_7 ,
const struct V_12 * V_9 , struct V_14 * V_15 )
{
int V_16 ;
V_5 -> V_8 . V_17 = NULL ;
V_5 -> V_8 . V_18 = NULL ;
V_5 -> V_19 . V_20 = & V_5 -> V_8 ;
V_5 -> V_19 . V_13 = V_13 ;
V_5 -> V_19 . V_21 = & V_22 ;
V_5 -> V_19 . V_23 = NULL ;
F_19 ( V_5 , ~ 0 , V_24 ) ;
F_20 ( & V_5 -> V_19 , V_25 ) ;
V_5 -> V_26 = V_27 ;
V_5 -> V_28 = 1 ;
V_5 -> V_29 = 0 ;
V_5 -> V_30 = 0 ;
V_5 -> V_31 = NULL ;
V_5 -> V_15 = V_15 ;
F_21 ( V_16 )
* F_22 ( V_5 -> V_32 , V_16 ) = 0 ;
F_14 ( V_5 , V_7 , V_9 ) ;
}
static void F_23 ( unsigned int V_13 , struct V_4 * V_5 )
{
F_24 ( & V_33 , V_13 , V_5 ) ;
}
struct V_4 * F_25 ( unsigned int V_13 )
{
return F_26 ( & V_33 , V_13 ) ;
}
static void F_27 ( unsigned int V_13 )
{
F_28 ( & V_33 , V_13 ) ;
}
static void F_29 ( struct V_4 * V_5 )
{
#ifdef F_12
F_13 ( V_5 -> V_11 ) ;
#endif
F_13 ( V_5 -> V_8 . V_9 ) ;
}
static inline void F_29 ( struct V_4 * V_5 ) { }
void F_30 ( void )
{
F_31 ( & V_34 ) ;
}
void F_32 ( void )
{
F_33 ( & V_34 ) ;
}
static struct V_4 * F_34 ( int V_13 , int V_7 , unsigned int V_35 ,
const struct V_12 * V_9 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 ;
T_2 V_6 = V_36 ;
V_5 = F_35 ( sizeof( * V_5 ) , V_6 , V_7 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_32 = F_36 (unsigned int) ;
if ( ! V_5 -> V_32 )
goto V_37;
if ( F_10 ( V_5 , V_6 , V_7 ) )
goto V_38;
F_37 ( & V_5 -> V_39 ) ;
F_38 ( & V_5 -> V_39 , & V_40 ) ;
F_39 ( & V_5 -> V_41 ) ;
F_18 ( V_13 , V_5 , V_7 , V_9 , V_15 ) ;
F_20 ( & V_5 -> V_19 , V_35 ) ;
return V_5 ;
V_38:
F_40 ( V_5 -> V_32 ) ;
V_37:
F_41 ( V_5 ) ;
return NULL ;
}
static void F_42 ( struct V_42 * V_43 )
{
struct V_4 * V_5 = F_43 ( V_43 , struct V_4 , V_41 ) ;
F_29 ( V_5 ) ;
F_40 ( V_5 -> V_32 ) ;
F_41 ( V_5 ) ;
}
static void F_44 ( unsigned int V_13 )
{
struct V_4 * V_5 = F_25 ( V_13 ) ;
F_45 ( V_13 , V_5 ) ;
F_31 ( & V_34 ) ;
F_27 ( V_13 ) ;
F_33 ( & V_34 ) ;
F_46 ( & V_5 -> V_41 , F_42 ) ;
}
static int F_47 ( unsigned int V_44 , unsigned int V_45 , int V_7 ,
const struct V_12 * V_9 , struct V_14 * V_15 )
{
const struct V_12 * V_46 = NULL ;
struct V_4 * V_5 ;
unsigned int V_35 ;
int V_47 , V_16 = - 1 ;
if ( V_9 && F_8 ( V_9 ) )
return - V_48 ;
V_35 = V_9 ? V_49 : 0 ;
for ( V_47 = 0 ; V_47 < V_45 ; V_47 ++ ) {
if ( V_9 ) {
V_16 = F_48 ( V_16 , V_9 ) ;
if ( V_16 >= V_50 )
V_16 = F_49 ( V_9 ) ;
V_7 = F_50 ( V_16 ) ;
V_46 = V_45 == 1 ? V_9 : F_51 ( V_16 ) ;
}
V_5 = F_34 ( V_44 + V_47 , V_7 , V_35 , V_46 , V_15 ) ;
if ( ! V_5 )
goto V_51;
F_31 ( & V_34 ) ;
F_23 ( V_44 + V_47 , V_5 ) ;
F_33 ( & V_34 ) ;
}
return V_44 ;
V_51:
for ( V_47 -- ; V_47 >= 0 ; V_47 -- )
F_44 ( V_44 + V_47 ) ;
F_31 ( & V_34 ) ;
F_52 ( V_52 , V_44 , V_45 ) ;
F_33 ( & V_34 ) ;
return - V_10 ;
}
static int F_53 ( unsigned int V_53 )
{
if ( V_53 > V_54 )
return - V_10 ;
V_55 = V_53 ;
return 0 ;
}
int T_1 F_54 ( void )
{
int V_47 , V_56 , V_7 = V_57 ;
struct V_4 * V_5 ;
F_6 () ;
V_56 = F_55 () ;
F_56 ( V_58 L_1 , V_59 , V_55 , V_56 ) ;
if ( F_57 ( V_55 > V_54 ) )
V_55 = V_54 ;
if ( F_57 ( V_56 > V_54 ) )
V_56 = V_54 ;
if ( V_56 > V_55 )
V_55 = V_56 ;
for ( V_47 = 0 ; V_47 < V_56 ; V_47 ++ ) {
V_5 = F_34 ( V_47 , V_7 , 0 , NULL , NULL ) ;
F_58 ( V_47 , V_52 ) ;
F_23 ( V_47 , V_5 ) ;
}
return F_59 () ;
}
int T_1 F_54 ( void )
{
int V_60 , V_47 , V_7 = V_57 ;
struct V_4 * V_5 ;
F_6 () ;
F_56 ( V_58 L_2 , V_59 ) ;
V_5 = V_4 ;
V_60 = F_60 ( V_4 ) ;
for ( V_47 = 0 ; V_47 < V_60 ; V_47 ++ ) {
V_5 [ V_47 ] . V_32 = F_36 (unsigned int) ;
F_10 ( & V_5 [ V_47 ] , V_36 , V_7 ) ;
F_37 ( & V_5 [ V_47 ] . V_39 ) ;
F_38 ( & V_5 [ V_47 ] . V_39 , & V_40 ) ;
F_18 ( V_47 , & V_5 [ V_47 ] , V_7 , NULL , NULL ) ;
}
return F_59 () ;
}
struct V_4 * F_25 ( unsigned int V_13 )
{
return ( V_13 < V_59 ) ? V_4 + V_13 : NULL ;
}
static void F_44 ( unsigned int V_13 )
{
struct V_4 * V_5 = F_25 ( V_13 ) ;
unsigned long V_35 ;
F_61 ( & V_5 -> V_39 , V_35 ) ;
F_18 ( V_13 , V_5 , F_62 ( V_5 ) , NULL , NULL ) ;
F_63 ( & V_5 -> V_39 , V_35 ) ;
}
static inline int F_47 ( unsigned int V_44 , unsigned int V_45 , int V_7 ,
const struct V_12 * V_9 ,
struct V_14 * V_15 )
{
T_3 V_47 ;
for ( V_47 = 0 ; V_47 < V_45 ; V_47 ++ ) {
struct V_4 * V_5 = F_25 ( V_44 + V_47 ) ;
V_5 -> V_15 = V_15 ;
}
return V_44 ;
}
static int F_53 ( unsigned int V_53 )
{
return - V_10 ;
}
void F_64 ( unsigned int V_13 )
{
F_31 ( & V_34 ) ;
F_65 ( V_52 , V_13 , 1 ) ;
F_33 ( & V_34 ) ;
}
void F_66 ( unsigned int V_13 )
{
F_44 ( V_13 ) ;
}
int F_67 ( unsigned int V_13 )
{
struct V_4 * V_5 = F_25 ( V_13 ) ;
if ( ! V_5 )
return - V_48 ;
F_68 ( V_5 ) ;
return 0 ;
}
int F_69 ( struct V_61 * V_62 , unsigned int V_63 ,
bool V_64 , struct V_65 * V_66 )
{
struct V_65 * V_67 = F_70 ( V_66 ) ;
unsigned int V_13 = V_63 ;
int V_68 = 0 ;
F_71 () ;
#ifdef F_72
if ( V_64 )
V_13 = F_73 ( V_62 , V_63 ) ;
#endif
if ( F_74 ( ! V_13 || V_13 >= V_55 ) ) {
F_75 ( V_13 ) ;
V_68 = - V_48 ;
} else {
F_67 ( V_13 ) ;
}
F_76 () ;
F_70 ( V_67 ) ;
return V_68 ;
}
void F_77 ( unsigned int V_69 , unsigned int V_45 )
{
int V_47 ;
if ( V_69 >= V_55 || ( V_69 + V_45 ) > V_55 )
return;
for ( V_47 = 0 ; V_47 < V_45 ; V_47 ++ )
F_44 ( V_69 + V_47 ) ;
F_31 ( & V_34 ) ;
F_52 ( V_52 , V_69 , V_45 ) ;
F_33 ( & V_34 ) ;
}
int T_4
F_78 ( int V_13 , unsigned int V_69 , unsigned int V_45 , int V_7 ,
struct V_14 * V_15 , const struct V_12 * V_9 )
{
int V_44 , V_68 ;
if ( ! V_45 )
return - V_48 ;
if ( V_13 >= 0 ) {
if ( V_69 > V_13 )
return - V_48 ;
V_69 = V_13 ;
} else {
V_69 = F_79 ( V_69 ) ;
}
F_31 ( & V_34 ) ;
V_44 = F_80 ( V_52 , V_54 ,
V_69 , V_45 , 0 ) ;
V_68 = - V_70 ;
if ( V_13 >= 0 && V_44 != V_13 )
goto V_51;
if ( V_44 + V_45 > V_55 ) {
V_68 = F_53 ( V_44 + V_45 ) ;
if ( V_68 )
goto V_51;
}
F_65 ( V_52 , V_44 , V_45 ) ;
F_33 ( & V_34 ) ;
return F_47 ( V_44 , V_45 , V_7 , V_9 , V_15 ) ;
V_51:
F_33 ( & V_34 ) ;
return V_68 ;
}
unsigned int F_81 ( int V_45 , int V_7 )
{
int V_47 , V_13 = F_78 ( - 1 , 0 , V_45 , V_7 , NULL , NULL ) ;
if ( V_13 < 0 )
return 0 ;
for ( V_47 = V_13 ; V_45 > 0 ; V_47 ++ , V_45 -- ) {
if ( F_82 ( V_47 , V_7 ) )
goto V_51;
F_83 ( V_47 , V_71 ) ;
}
return V_13 ;
V_51:
for ( V_47 -- ; V_47 >= V_13 ; V_47 -- ) {
F_84 ( V_47 , V_71 | V_72 ) ;
F_85 ( V_47 ) ;
}
F_77 ( V_13 , V_45 ) ;
return 0 ;
}
void F_86 ( unsigned int V_69 , int V_45 )
{
int V_47 , V_73 ;
for ( V_47 = V_69 , V_73 = V_45 ; V_73 > 0 ; V_47 ++ , V_73 -- ) {
F_84 ( V_47 , V_71 | V_72 ) ;
F_85 ( V_47 ) ;
}
F_77 ( V_69 , V_45 ) ;
}
unsigned int F_87 ( unsigned int V_74 )
{
return F_88 ( V_52 , V_55 , V_74 ) ;
}
struct V_4 *
F_89 ( unsigned int V_13 , unsigned long * V_35 , bool V_75 ,
unsigned int V_76 )
{
struct V_4 * V_5 = F_25 ( V_13 ) ;
if ( V_5 ) {
if ( V_76 & V_77 ) {
if ( ( V_76 & V_78 ) &&
! F_90 ( V_5 ) )
return NULL ;
if ( ! ( V_76 & V_78 ) &&
F_90 ( V_5 ) )
return NULL ;
}
if ( V_75 )
F_91 ( V_5 ) ;
F_61 ( & V_5 -> V_39 , * V_35 ) ;
}
return V_5 ;
}
void F_92 ( struct V_4 * V_5 , unsigned long V_35 , bool V_75 )
{
F_63 ( & V_5 -> V_39 , V_35 ) ;
if ( V_75 )
F_93 ( V_5 ) ;
}
int F_94 ( unsigned int V_13 ,
const struct V_12 * V_9 )
{
struct V_4 * V_5 = F_25 ( V_13 ) ;
if ( ! V_5 )
return - V_48 ;
if ( V_5 -> V_79 )
return - V_48 ;
V_5 -> V_79 = F_95 ( sizeof( * V_5 -> V_79 ) , V_36 ) ;
if ( ! V_5 -> V_79 )
return - V_10 ;
if ( V_9 )
V_5 -> V_80 = V_9 ;
else
V_5 -> V_80 = V_81 ;
F_96 ( V_13 ) ;
return 0 ;
}
int F_97 ( unsigned int V_13 )
{
return F_94 ( V_13 , NULL ) ;
}
int F_98 ( unsigned int V_13 , struct V_12 * V_9 )
{
struct V_4 * V_5 = F_25 ( V_13 ) ;
if ( ! V_5 || ! V_5 -> V_79 )
return - V_48 ;
if ( V_9 )
F_15 ( V_9 , V_5 -> V_80 ) ;
return 0 ;
}
void F_99 ( unsigned int V_13 )
{
F_100 ( F_25 ( V_13 ) ) ;
}
unsigned int F_101 ( unsigned int V_13 , int V_16 )
{
struct V_4 * V_5 = F_25 ( V_13 ) ;
return V_5 && V_5 -> V_32 ?
* F_22 ( V_5 -> V_32 , V_16 ) : 0 ;
}
unsigned int V_32 ( unsigned int V_13 )
{
struct V_4 * V_5 = F_25 ( V_13 ) ;
int V_16 ;
unsigned int V_82 = 0 ;
if ( ! V_5 || ! V_5 -> V_32 )
return 0 ;
F_21 (cpu)
V_82 += * F_22 ( V_5 -> V_32 , V_16 ) ;
return V_82 ;
}
unsigned int F_102 ( unsigned int V_13 )
{
unsigned int V_82 ;
F_30 () ;
V_82 = V_32 ( V_13 ) ;
F_32 () ;
return V_82 ;
}
