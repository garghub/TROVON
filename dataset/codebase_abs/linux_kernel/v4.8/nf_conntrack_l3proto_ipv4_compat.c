static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_1 * V_7 ;
for ( V_5 -> V_8 = 0 ;
V_5 -> V_8 < V_5 -> V_9 ;
V_5 -> V_8 ++ ) {
V_7 = F_2 (
F_3 ( & V_5 -> V_10 [ V_5 -> V_8 ] ) ) ;
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
if ( ++ V_5 -> V_8 >= V_5 -> V_9 )
return NULL ;
}
V_11 = F_2 (
F_3 ( & V_5 -> V_10 [ V_5 -> V_8 ] ) ) ;
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
struct V_4 * V_5 = V_3 -> V_6 ;
F_11 () ;
F_12 ( & V_5 -> V_10 , & V_5 -> V_9 ) ;
return F_9 ( V_3 , * V_12 ) ;
}
static void * F_13 ( struct V_2 * V_13 , void * V_14 , T_1 * V_12 )
{
( * V_12 ) ++ ;
return F_5 ( V_13 , V_14 ) ;
}
static void F_14 ( struct V_2 * V_13 , void * V_14 )
__releases( T_2 )
{
F_15 () ;
}
static void F_16 ( struct V_2 * V_13 , const struct V_15 * V_16 )
{
int V_17 ;
T_3 V_18 ;
char * V_19 ;
V_17 = F_17 ( V_16 -> V_20 , & V_19 , & V_18 ) ;
if ( V_17 )
return;
F_18 ( V_13 , L_1 , V_19 ) ;
F_19 ( V_19 , V_18 ) ;
}
static inline void F_16 ( struct V_2 * V_13 , const struct V_15 * V_16 )
{
}
static bool F_20 ( const struct V_15 * V_16 ,
const struct V_21 * V_21 ,
const struct V_22 * V_10 )
{
if ( F_21 ( V_10 ) )
return true ;
if ( F_22 ( V_16 ) != V_23 )
return true ;
if ( ! F_23 ( F_24 ( V_16 ) , V_21 ) )
return true ;
return false ;
}
static int F_25 ( struct V_2 * V_13 , void * V_14 )
{
struct V_22 * V_10 = V_14 ;
struct V_15 * V_16 = F_26 ( V_10 ) ;
const struct V_24 * V_25 ;
const struct V_26 * V_27 ;
int V_17 = 0 ;
F_27 ( V_16 ) ;
if ( F_20 ( V_16 , F_28 ( V_13 ) , V_10 ) )
return 0 ;
if ( F_29 ( ! F_30 ( & V_16 -> V_28 . V_29 ) ) )
return 0 ;
if ( ! F_31 ( V_16 ) ||
F_20 ( V_16 , F_28 ( V_13 ) , V_10 ) )
goto V_30;
V_25 = F_32 ( F_22 ( V_16 ) ) ;
F_27 ( V_25 ) ;
V_27 = F_33 ( F_22 ( V_16 ) , F_34 ( V_16 ) ) ;
F_27 ( V_27 ) ;
V_17 = - V_31 ;
F_18 ( V_13 , L_2 ,
V_27 -> V_32 , F_34 ( V_16 ) ,
F_35 ( & V_16 -> V_33 )
? ( long ) ( V_16 -> V_33 . V_34 - V_35 ) / V_36 : 0 ) ;
if ( V_27 -> V_37 )
V_27 -> V_37 ( V_13 , V_16 ) ;
if ( F_36 ( V_13 ) )
goto V_30;
F_37 ( V_13 , & V_16 -> V_38 [ V_39 ] . V_40 ,
V_25 , V_27 ) ;
if ( F_36 ( V_13 ) )
goto V_30;
if ( F_38 ( V_13 , V_16 , V_39 ) )
goto V_30;
if ( ! ( F_39 ( V_41 , & V_16 -> V_42 ) ) )
F_18 ( V_13 , L_3 ) ;
F_37 ( V_13 , & V_16 -> V_38 [ V_43 ] . V_40 ,
V_25 , V_27 ) ;
if ( F_36 ( V_13 ) )
goto V_30;
if ( F_38 ( V_13 , V_16 , V_43 ) )
goto V_30;
if ( F_39 ( V_44 , & V_16 -> V_42 ) )
F_18 ( V_13 , L_4 ) ;
#ifdef F_40
F_18 ( V_13 , L_5 , V_16 -> V_45 ) ;
#endif
F_16 ( V_13 , V_16 ) ;
F_18 ( V_13 , L_6 , F_41 ( & V_16 -> V_28 . V_29 ) ) ;
if ( F_36 ( V_13 ) )
goto V_30;
V_17 = 0 ;
V_30:
F_42 ( V_16 ) ;
return V_17 ;
}
static int F_43 ( struct V_46 * V_46 , struct V_47 * V_47 )
{
return F_44 ( V_46 , V_47 , & V_48 ,
sizeof( struct V_4 ) ) ;
}
static struct V_49 * F_45 ( struct V_2 * V_3 )
{
struct V_50 * V_5 = V_3 -> V_6 ;
struct V_49 * V_7 ;
for ( V_5 -> V_8 = 0 ; V_5 -> V_8 < V_51 ; V_5 -> V_8 ++ ) {
V_7 = F_2 (
F_46 ( & V_52 [ V_5 -> V_8 ] ) ) ;
if ( V_7 )
return V_7 ;
}
return NULL ;
}
static struct V_49 * F_47 ( struct V_2 * V_3 ,
struct V_49 * V_11 )
{
struct V_50 * V_5 = V_3 -> V_6 ;
V_11 = F_2 ( F_48 ( V_11 ) ) ;
while ( V_11 == NULL ) {
if ( ++ V_5 -> V_8 >= V_51 )
return NULL ;
V_11 = F_2 (
F_46 ( & V_52 [ V_5 -> V_8 ] ) ) ;
}
return V_11 ;
}
static struct V_49 * F_49 ( struct V_2 * V_3 , T_1 V_12 )
{
struct V_49 * V_11 = F_45 ( V_3 ) ;
if ( V_11 )
while ( V_12 && ( V_11 = F_47 ( V_3 , V_11 ) ) )
V_12 -- ;
return V_12 ? NULL : V_11 ;
}
static void * F_50 ( struct V_2 * V_3 , T_1 * V_12 )
__acquires( T_2 )
{
F_11 () ;
return F_49 ( V_3 , * V_12 ) ;
}
static void * F_51 ( struct V_2 * V_3 , void * V_14 , T_1 * V_12 )
{
( * V_12 ) ++ ;
return F_47 ( V_3 , V_14 ) ;
}
static void F_52 ( struct V_2 * V_3 , void * V_14 )
__releases( T_2 )
{
F_15 () ;
}
static int F_53 ( struct V_2 * V_13 , void * V_14 )
{
struct V_53 * exp ;
const struct V_49 * V_7 = V_14 ;
exp = F_54 ( V_7 , struct V_53 , V_54 ) ;
if ( ! F_23 ( F_24 ( exp -> V_55 ) , F_28 ( V_13 ) ) )
return 0 ;
if ( exp -> V_40 . V_56 . V_57 != V_23 )
return 0 ;
if ( exp -> V_33 . V_58 )
F_18 ( V_13 , L_7 , F_35 ( & exp -> V_33 )
? ( long ) ( exp -> V_33 . V_34 - V_35 ) / V_36 : 0 ) ;
else
F_18 ( V_13 , L_8 ) ;
F_18 ( V_13 , L_9 , exp -> V_40 . V_59 . V_60 ) ;
F_37 ( V_13 , & exp -> V_40 ,
F_32 ( exp -> V_40 . V_56 . V_57 ) ,
F_33 ( exp -> V_40 . V_56 . V_57 ,
exp -> V_40 . V_59 . V_60 ) ) ;
F_55 ( V_13 , '\n' ) ;
return 0 ;
}
static int F_56 ( struct V_46 * V_46 , struct V_47 * V_47 )
{
return F_44 ( V_46 , V_47 , & V_61 ,
sizeof( struct V_50 ) ) ;
}
static void * F_57 ( struct V_2 * V_3 , T_1 * V_12 )
{
struct V_21 * V_21 = F_28 ( V_3 ) ;
int V_62 ;
if ( * V_12 == 0 )
return V_63 ;
for ( V_62 = * V_12 - 1 ; V_62 < V_64 ; ++ V_62 ) {
if ( ! F_58 ( V_62 ) )
continue;
* V_12 = V_62 + 1 ;
return F_59 ( V_21 -> V_16 . V_65 , V_62 ) ;
}
return NULL ;
}
static void * F_60 ( struct V_2 * V_3 , void * V_14 , T_1 * V_12 )
{
struct V_21 * V_21 = F_28 ( V_3 ) ;
int V_62 ;
for ( V_62 = * V_12 ; V_62 < V_64 ; ++ V_62 ) {
if ( ! F_58 ( V_62 ) )
continue;
* V_12 = V_62 + 1 ;
return F_59 ( V_21 -> V_16 . V_65 , V_62 ) ;
}
return NULL ;
}
static void F_61 ( struct V_2 * V_3 , void * V_14 )
{
}
static int F_62 ( struct V_2 * V_3 , void * V_14 )
{
struct V_21 * V_21 = F_28 ( V_3 ) ;
unsigned int V_66 = F_41 ( & V_21 -> V_16 . V_67 ) ;
const struct V_68 * V_5 = V_14 ;
if ( V_14 == V_63 ) {
F_18 ( V_3 , L_10 ) ;
return 0 ;
}
F_18 ( V_3 , L_11
L_12 ,
V_66 ,
V_5 -> V_69 ,
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
V_5 -> error ,
V_5 -> V_80 ,
V_5 -> V_81 ,
V_5 -> V_82 ,
V_5 -> V_83
) ;
return 0 ;
}
static int F_63 ( struct V_46 * V_46 , struct V_47 * V_47 )
{
return F_44 ( V_46 , V_47 , & V_84 ,
sizeof( struct V_85 ) ) ;
}
static int T_4 F_64 ( struct V_21 * V_21 )
{
struct V_86 * V_87 , * V_88 , * V_89 ;
V_87 = F_65 ( L_13 , 0440 , V_21 -> V_90 , & V_91 ) ;
if ( ! V_87 )
goto V_92;
V_88 = F_65 ( L_14 , 0440 , V_21 -> V_90 ,
& V_93 ) ;
if ( ! V_88 )
goto V_94;
V_89 = F_65 ( L_13 , V_95 ,
V_21 -> V_96 , & V_97 ) ;
if ( ! V_89 )
goto V_98;
return 0 ;
V_98:
F_66 ( L_14 , V_21 -> V_90 ) ;
V_94:
F_66 ( L_13 , V_21 -> V_90 ) ;
V_92:
return - V_99 ;
}
static void T_5 F_67 ( struct V_21 * V_21 )
{
F_66 ( L_13 , V_21 -> V_96 ) ;
F_66 ( L_14 , V_21 -> V_90 ) ;
F_66 ( L_13 , V_21 -> V_90 ) ;
}
int T_6 F_68 ( void )
{
return F_69 ( & V_100 ) ;
}
void T_7 F_70 ( void )
{
F_71 ( & V_100 ) ;
}
