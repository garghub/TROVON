static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_1 * V_7 ;
for ( V_5 -> V_8 = 0 ;
V_5 -> V_8 < V_9 ;
V_5 -> V_8 ++ ) {
V_7 = F_2 (
F_3 ( & V_10 [ V_5 -> V_8 ] ) ) ;
if ( ! F_4 ( V_7 ) )
return V_7 ;
}
return NULL ;
}
static struct V_1 * F_5 ( struct V_2 * V_3 ,
struct V_1 * V_11 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
V_11 = F_2 ( F_6 ( V_11 ) ) ;
while ( F_4 ( V_11 ) ) {
if ( F_7 ( F_8 ( V_11 ) == V_5 -> V_8 ) ) {
if ( ++ V_5 -> V_8 >= V_9 )
return NULL ;
}
V_11 = F_2 (
F_3 ( & V_10 [ V_5 -> V_8 ] ) ) ;
}
return V_11 ;
}
static struct V_1 * F_9 ( struct V_2 * V_3 , T_1 V_12 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
if ( V_11 )
while ( V_12 && ( V_11 = F_5 ( V_3 , V_11 ) ) )
V_12 -- ;
return V_12 ? NULL : V_11 ;
}
static void * F_10 ( struct V_2 * V_3 , T_1 * V_12 )
__acquires( T_2 )
{
F_11 () ;
return F_9 ( V_3 , * V_12 ) ;
}
static void * F_12 ( struct V_2 * V_13 , void * V_14 , T_1 * V_12 )
{
( * V_12 ) ++ ;
return F_5 ( V_13 , V_14 ) ;
}
static void F_13 ( struct V_2 * V_13 , void * V_14 )
__releases( T_2 )
{
F_14 () ;
}
static void F_15 ( struct V_2 * V_13 , const struct V_15 * V_16 )
{
int V_17 ;
T_3 V_18 ;
char * V_19 ;
V_17 = F_16 ( V_16 -> V_20 , & V_19 , & V_18 ) ;
if ( V_17 )
return;
F_17 ( V_13 , L_1 , V_19 ) ;
F_18 ( V_19 , V_18 ) ;
}
static inline void F_15 ( struct V_2 * V_13 , const struct V_15 * V_16 )
{
}
static bool F_19 ( const struct V_15 * V_16 ,
const struct V_21 * V_21 ,
const struct V_22 * V_23 )
{
if ( F_20 ( V_23 ) )
return true ;
if ( F_21 ( V_16 ) != V_24 )
return true ;
if ( ! F_22 ( F_23 ( V_16 ) , V_21 ) )
return true ;
return false ;
}
static int F_24 ( struct V_2 * V_13 , void * V_14 )
{
struct V_22 * V_23 = V_14 ;
struct V_15 * V_16 = F_25 ( V_23 ) ;
const struct V_25 * V_26 ;
const struct V_27 * V_28 ;
int V_17 = 0 ;
F_26 ( V_16 ) ;
if ( F_19 ( V_16 , F_27 ( V_13 ) , V_23 ) )
return 0 ;
if ( F_28 ( ! F_29 ( & V_16 -> V_29 . V_30 ) ) )
return 0 ;
if ( ! F_30 ( V_16 ) ||
F_19 ( V_16 , F_27 ( V_13 ) , V_23 ) )
goto V_31;
V_26 = F_31 ( F_21 ( V_16 ) ) ;
F_26 ( V_26 ) ;
V_28 = F_32 ( F_21 ( V_16 ) , F_33 ( V_16 ) ) ;
F_26 ( V_28 ) ;
V_17 = - V_32 ;
F_17 ( V_13 , L_2 ,
V_28 -> V_33 , F_33 ( V_16 ) ,
F_34 ( & V_16 -> V_34 )
? ( long ) ( V_16 -> V_34 . V_35 - V_36 ) / V_37 : 0 ) ;
if ( V_28 -> V_38 )
V_28 -> V_38 ( V_13 , V_16 ) ;
if ( F_35 ( V_13 ) )
goto V_31;
F_36 ( V_13 , & V_16 -> V_39 [ V_40 ] . V_41 ,
V_26 , V_28 ) ;
if ( F_35 ( V_13 ) )
goto V_31;
if ( F_37 ( V_13 , V_16 , V_40 ) )
goto V_31;
if ( ! ( F_38 ( V_42 , & V_16 -> V_43 ) ) )
F_17 ( V_13 , L_3 ) ;
F_36 ( V_13 , & V_16 -> V_39 [ V_44 ] . V_41 ,
V_26 , V_28 ) ;
if ( F_35 ( V_13 ) )
goto V_31;
if ( F_37 ( V_13 , V_16 , V_44 ) )
goto V_31;
if ( F_38 ( V_45 , & V_16 -> V_43 ) )
F_17 ( V_13 , L_4 ) ;
#ifdef F_39
F_17 ( V_13 , L_5 , V_16 -> V_46 ) ;
#endif
F_15 ( V_13 , V_16 ) ;
F_17 ( V_13 , L_6 , F_40 ( & V_16 -> V_29 . V_30 ) ) ;
if ( F_35 ( V_13 ) )
goto V_31;
V_17 = 0 ;
V_31:
F_41 ( V_16 ) ;
return V_17 ;
}
static int F_42 ( struct V_47 * V_47 , struct V_48 * V_48 )
{
return F_43 ( V_47 , V_48 , & V_49 ,
sizeof( struct V_4 ) ) ;
}
static struct V_50 * F_44 ( struct V_2 * V_3 )
{
struct V_51 * V_5 = V_3 -> V_6 ;
struct V_50 * V_7 ;
for ( V_5 -> V_8 = 0 ; V_5 -> V_8 < V_52 ; V_5 -> V_8 ++ ) {
V_7 = F_2 (
F_45 ( & V_53 [ V_5 -> V_8 ] ) ) ;
if ( V_7 )
return V_7 ;
}
return NULL ;
}
static struct V_50 * F_46 ( struct V_2 * V_3 ,
struct V_50 * V_11 )
{
struct V_51 * V_5 = V_3 -> V_6 ;
V_11 = F_2 ( F_47 ( V_11 ) ) ;
while ( V_11 == NULL ) {
if ( ++ V_5 -> V_8 >= V_52 )
return NULL ;
V_11 = F_2 (
F_45 ( & V_53 [ V_5 -> V_8 ] ) ) ;
}
return V_11 ;
}
static struct V_50 * F_48 ( struct V_2 * V_3 , T_1 V_12 )
{
struct V_50 * V_11 = F_44 ( V_3 ) ;
if ( V_11 )
while ( V_12 && ( V_11 = F_46 ( V_3 , V_11 ) ) )
V_12 -- ;
return V_12 ? NULL : V_11 ;
}
static void * F_49 ( struct V_2 * V_3 , T_1 * V_12 )
__acquires( T_2 )
{
F_11 () ;
return F_48 ( V_3 , * V_12 ) ;
}
static void * F_50 ( struct V_2 * V_3 , void * V_14 , T_1 * V_12 )
{
( * V_12 ) ++ ;
return F_46 ( V_3 , V_14 ) ;
}
static void F_51 ( struct V_2 * V_3 , void * V_14 )
__releases( T_2 )
{
F_14 () ;
}
static int F_52 ( struct V_2 * V_13 , void * V_14 )
{
struct V_54 * exp ;
const struct V_50 * V_7 = V_14 ;
exp = F_53 ( V_7 , struct V_54 , V_55 ) ;
if ( ! F_22 ( F_23 ( exp -> V_56 ) , F_27 ( V_13 ) ) )
return 0 ;
if ( exp -> V_41 . V_57 . V_58 != V_24 )
return 0 ;
if ( exp -> V_34 . V_59 )
F_17 ( V_13 , L_7 , F_34 ( & exp -> V_34 )
? ( long ) ( exp -> V_34 . V_35 - V_36 ) / V_37 : 0 ) ;
else
F_17 ( V_13 , L_8 ) ;
F_17 ( V_13 , L_9 , exp -> V_41 . V_60 . V_61 ) ;
F_36 ( V_13 , & exp -> V_41 ,
F_31 ( exp -> V_41 . V_57 . V_58 ) ,
F_32 ( exp -> V_41 . V_57 . V_58 ,
exp -> V_41 . V_60 . V_61 ) ) ;
F_54 ( V_13 , '\n' ) ;
return 0 ;
}
static int F_55 ( struct V_47 * V_47 , struct V_48 * V_48 )
{
return F_43 ( V_47 , V_48 , & V_62 ,
sizeof( struct V_51 ) ) ;
}
static void * F_56 ( struct V_2 * V_3 , T_1 * V_12 )
{
struct V_21 * V_21 = F_27 ( V_3 ) ;
int V_63 ;
if ( * V_12 == 0 )
return V_64 ;
for ( V_63 = * V_12 - 1 ; V_63 < V_65 ; ++ V_63 ) {
if ( ! F_57 ( V_63 ) )
continue;
* V_12 = V_63 + 1 ;
return F_58 ( V_21 -> V_16 . V_66 , V_63 ) ;
}
return NULL ;
}
static void * F_59 ( struct V_2 * V_3 , void * V_14 , T_1 * V_12 )
{
struct V_21 * V_21 = F_27 ( V_3 ) ;
int V_63 ;
for ( V_63 = * V_12 ; V_63 < V_65 ; ++ V_63 ) {
if ( ! F_57 ( V_63 ) )
continue;
* V_12 = V_63 + 1 ;
return F_58 ( V_21 -> V_16 . V_66 , V_63 ) ;
}
return NULL ;
}
static void F_60 ( struct V_2 * V_3 , void * V_14 )
{
}
static int F_61 ( struct V_2 * V_3 , void * V_14 )
{
struct V_21 * V_21 = F_27 ( V_3 ) ;
unsigned int V_67 = F_40 ( & V_21 -> V_16 . V_68 ) ;
const struct V_69 * V_5 = V_14 ;
if ( V_14 == V_64 ) {
F_17 ( V_3 , L_10 ) ;
return 0 ;
}
F_17 ( V_3 , L_11
L_12 ,
V_67 ,
V_5 -> V_70 ,
V_5 -> V_71 ,
V_5 -> V_72 ,
V_5 -> V_73 ,
V_5 -> V_74 ,
V_5 -> V_75 ,
V_5 -> V_76 ,
V_5 -> V_77 ,
V_5 -> V_78 ,
V_5 -> V_79 ,
V_5 -> V_80 ,
V_5 -> error ,
V_5 -> V_81 ,
V_5 -> V_82 ,
V_5 -> V_83 ,
V_5 -> V_84
) ;
return 0 ;
}
static int F_62 ( struct V_47 * V_47 , struct V_48 * V_48 )
{
return F_43 ( V_47 , V_48 , & V_85 ,
sizeof( struct V_86 ) ) ;
}
static int T_4 F_63 ( struct V_21 * V_21 )
{
struct V_87 * V_88 , * V_89 , * V_90 ;
V_88 = F_64 ( L_13 , 0440 , V_21 -> V_91 , & V_92 ) ;
if ( ! V_88 )
goto V_93;
V_89 = F_64 ( L_14 , 0440 , V_21 -> V_91 ,
& V_94 ) ;
if ( ! V_89 )
goto V_95;
V_90 = F_64 ( L_13 , V_96 ,
V_21 -> V_97 , & V_98 ) ;
if ( ! V_90 )
goto V_99;
return 0 ;
V_99:
F_65 ( L_14 , V_21 -> V_91 ) ;
V_95:
F_65 ( L_13 , V_21 -> V_91 ) ;
V_93:
return - V_100 ;
}
static void T_5 F_66 ( struct V_21 * V_21 )
{
F_65 ( L_13 , V_21 -> V_97 ) ;
F_65 ( L_14 , V_21 -> V_91 ) ;
F_65 ( L_13 , V_21 -> V_91 ) ;
}
int T_6 F_67 ( void )
{
return F_68 ( & V_101 ) ;
}
void T_7 F_69 ( void )
{
F_70 ( & V_101 ) ;
}
