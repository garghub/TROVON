static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_1 * V_8 ;
for ( V_6 -> V_9 = 0 ;
V_6 -> V_9 < V_4 -> V_10 . V_11 ;
V_6 -> V_9 ++ ) {
V_8 = F_3 (
F_4 ( & V_4 -> V_10 . V_12 [ V_6 -> V_9 ] ) ) ;
if ( ! F_5 ( V_8 ) )
return V_8 ;
}
return NULL ;
}
static struct V_1 * F_6 ( struct V_2 * V_3 ,
struct V_1 * V_13 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
V_13 = F_3 ( F_7 ( V_13 ) ) ;
while ( F_5 ( V_13 ) ) {
if ( F_8 ( F_9 ( V_13 ) == V_6 -> V_9 ) ) {
if ( ++ V_6 -> V_9 >= V_4 -> V_10 . V_11 )
return NULL ;
}
V_13 = F_3 (
F_4 ( & V_4 -> V_10 . V_12 [ V_6 -> V_9 ] ) ) ;
}
return V_13 ;
}
static struct V_1 * F_10 ( struct V_2 * V_3 , T_1 V_14 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( V_13 )
while ( V_14 && ( V_13 = F_6 ( V_3 , V_13 ) ) )
V_14 -- ;
return V_14 ? NULL : V_13 ;
}
static void * F_11 ( struct V_2 * V_3 , T_1 * V_14 )
__acquires( T_2 )
{
F_12 () ;
return F_10 ( V_3 , * V_14 ) ;
}
static void * F_13 ( struct V_2 * V_15 , void * V_16 , T_1 * V_14 )
{
( * V_14 ) ++ ;
return F_6 ( V_15 , V_16 ) ;
}
static void F_14 ( struct V_2 * V_15 , void * V_16 )
__releases( T_2 )
{
F_15 () ;
}
static void F_16 ( struct V_2 * V_15 , const struct V_17 * V_10 )
{
int V_18 ;
T_3 V_19 ;
char * V_20 ;
V_18 = F_17 ( V_10 -> V_21 , & V_20 , & V_19 ) ;
if ( V_18 )
return;
F_18 ( V_15 , L_1 , V_20 ) ;
F_19 ( V_20 , V_19 ) ;
}
static inline void F_16 ( struct V_2 * V_15 , const struct V_17 * V_10 )
{
}
static int F_20 ( struct V_2 * V_15 , void * V_16 )
{
struct V_22 * V_12 = V_16 ;
struct V_17 * V_10 = F_21 ( V_12 ) ;
const struct V_23 * V_24 ;
const struct V_25 * V_26 ;
int V_18 = 0 ;
F_22 ( V_10 ) ;
if ( F_23 ( ! F_24 ( & V_10 -> V_27 . V_28 ) ) )
return 0 ;
if ( F_25 ( V_12 ) )
goto V_29;
if ( F_26 ( V_10 ) != V_30 )
goto V_29;
V_24 = F_27 ( F_26 ( V_10 ) ) ;
F_22 ( V_24 ) ;
V_26 = F_28 ( F_26 ( V_10 ) , F_29 ( V_10 ) ) ;
F_22 ( V_26 ) ;
V_18 = - V_31 ;
F_18 ( V_15 , L_2 ,
V_26 -> V_32 , F_29 ( V_10 ) ,
F_30 ( & V_10 -> V_33 )
? ( long ) ( V_10 -> V_33 . V_34 - V_35 ) / V_36 : 0 ) ;
if ( V_26 -> V_37 )
V_26 -> V_37 ( V_15 , V_10 ) ;
if ( F_31 ( V_15 ) )
goto V_29;
F_32 ( V_15 , & V_10 -> V_38 [ V_39 ] . V_40 ,
V_24 , V_26 ) ;
if ( F_31 ( V_15 ) )
goto V_29;
if ( F_33 ( V_15 , V_10 , V_39 ) )
goto V_29;
if ( ! ( F_34 ( V_41 , & V_10 -> V_42 ) ) )
F_18 ( V_15 , L_3 ) ;
F_32 ( V_15 , & V_10 -> V_38 [ V_43 ] . V_40 ,
V_24 , V_26 ) ;
if ( F_31 ( V_15 ) )
goto V_29;
if ( F_33 ( V_15 , V_10 , V_43 ) )
goto V_29;
if ( F_34 ( V_44 , & V_10 -> V_42 ) )
F_18 ( V_15 , L_4 ) ;
#ifdef F_35
F_18 ( V_15 , L_5 , V_10 -> V_45 ) ;
#endif
F_16 ( V_15 , V_10 ) ;
F_18 ( V_15 , L_6 , F_36 ( & V_10 -> V_27 . V_28 ) ) ;
if ( F_31 ( V_15 ) )
goto V_29;
V_18 = 0 ;
V_29:
F_37 ( V_10 ) ;
return V_18 ;
}
static int F_38 ( struct V_46 * V_46 , struct V_47 * V_47 )
{
return F_39 ( V_46 , V_47 , & V_48 ,
sizeof( struct V_5 ) ) ;
}
static struct V_49 * F_40 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_50 * V_6 = V_3 -> V_7 ;
struct V_49 * V_8 ;
for ( V_6 -> V_9 = 0 ; V_6 -> V_9 < V_51 ; V_6 -> V_9 ++ ) {
V_8 = F_3 (
F_41 ( & V_4 -> V_10 . V_52 [ V_6 -> V_9 ] ) ) ;
if ( V_8 )
return V_8 ;
}
return NULL ;
}
static struct V_49 * F_42 ( struct V_2 * V_3 ,
struct V_49 * V_13 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_50 * V_6 = V_3 -> V_7 ;
V_13 = F_3 ( F_43 ( V_13 ) ) ;
while ( V_13 == NULL ) {
if ( ++ V_6 -> V_9 >= V_51 )
return NULL ;
V_13 = F_3 (
F_41 ( & V_4 -> V_10 . V_52 [ V_6 -> V_9 ] ) ) ;
}
return V_13 ;
}
static struct V_49 * F_44 ( struct V_2 * V_3 , T_1 V_14 )
{
struct V_49 * V_13 = F_40 ( V_3 ) ;
if ( V_13 )
while ( V_14 && ( V_13 = F_42 ( V_3 , V_13 ) ) )
V_14 -- ;
return V_14 ? NULL : V_13 ;
}
static void * F_45 ( struct V_2 * V_3 , T_1 * V_14 )
__acquires( T_2 )
{
F_12 () ;
return F_44 ( V_3 , * V_14 ) ;
}
static void * F_46 ( struct V_2 * V_3 , void * V_16 , T_1 * V_14 )
{
( * V_14 ) ++ ;
return F_42 ( V_3 , V_16 ) ;
}
static void F_47 ( struct V_2 * V_3 , void * V_16 )
__releases( T_2 )
{
F_15 () ;
}
static int F_48 ( struct V_2 * V_15 , void * V_16 )
{
struct V_53 * exp ;
const struct V_49 * V_8 = V_16 ;
exp = F_49 ( V_8 , struct V_53 , V_54 ) ;
if ( exp -> V_40 . V_55 . V_56 != V_30 )
return 0 ;
if ( exp -> V_33 . V_57 )
F_18 ( V_15 , L_7 , F_30 ( & exp -> V_33 )
? ( long ) ( exp -> V_33 . V_34 - V_35 ) / V_36 : 0 ) ;
else
F_18 ( V_15 , L_8 ) ;
F_18 ( V_15 , L_9 , exp -> V_40 . V_58 . V_59 ) ;
F_32 ( V_15 , & exp -> V_40 ,
F_27 ( exp -> V_40 . V_55 . V_56 ) ,
F_28 ( exp -> V_40 . V_55 . V_56 ,
exp -> V_40 . V_58 . V_59 ) ) ;
return F_50 ( V_15 , '\n' ) ;
}
static int F_51 ( struct V_46 * V_46 , struct V_47 * V_47 )
{
return F_39 ( V_46 , V_47 , & V_60 ,
sizeof( struct V_50 ) ) ;
}
static void * F_52 ( struct V_2 * V_3 , T_1 * V_14 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
int V_61 ;
if ( * V_14 == 0 )
return V_62 ;
for ( V_61 = * V_14 - 1 ; V_61 < V_63 ; ++ V_61 ) {
if ( ! F_53 ( V_61 ) )
continue;
* V_14 = V_61 + 1 ;
return F_54 ( V_4 -> V_10 . V_64 , V_61 ) ;
}
return NULL ;
}
static void * F_55 ( struct V_2 * V_3 , void * V_16 , T_1 * V_14 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
int V_61 ;
for ( V_61 = * V_14 ; V_61 < V_63 ; ++ V_61 ) {
if ( ! F_53 ( V_61 ) )
continue;
* V_14 = V_61 + 1 ;
return F_54 ( V_4 -> V_10 . V_64 , V_61 ) ;
}
return NULL ;
}
static void F_56 ( struct V_2 * V_3 , void * V_16 )
{
}
static int F_57 ( struct V_2 * V_3 , void * V_16 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
unsigned int V_65 = F_36 ( & V_4 -> V_10 . V_66 ) ;
const struct V_67 * V_6 = V_16 ;
if ( V_16 == V_62 ) {
F_18 ( V_3 , L_10 ) ;
return 0 ;
}
F_18 ( V_3 , L_11
L_12 ,
V_65 ,
V_6 -> V_68 ,
V_6 -> V_69 ,
V_6 -> V_70 ,
V_6 -> V_71 ,
V_6 -> V_72 ,
V_6 -> V_73 ,
V_6 -> V_74 ,
V_6 -> V_75 ,
V_6 -> V_76 ,
V_6 -> V_77 ,
V_6 -> V_78 ,
V_6 -> error ,
V_6 -> V_79 ,
V_6 -> V_80 ,
V_6 -> V_81 ,
V_6 -> V_82
) ;
return 0 ;
}
static int F_58 ( struct V_46 * V_46 , struct V_47 * V_47 )
{
return F_39 ( V_46 , V_47 , & V_83 ,
sizeof( struct V_84 ) ) ;
}
static int T_4 F_59 ( struct V_4 * V_4 )
{
struct V_85 * V_86 , * V_87 , * V_88 ;
V_86 = F_60 ( L_13 , 0440 , V_4 -> V_89 , & V_90 ) ;
if ( ! V_86 )
goto V_91;
V_87 = F_60 ( L_14 , 0440 , V_4 -> V_89 ,
& V_92 ) ;
if ( ! V_87 )
goto V_93;
V_88 = F_60 ( L_13 , V_94 ,
V_4 -> V_95 , & V_96 ) ;
if ( ! V_88 )
goto V_97;
return 0 ;
V_97:
F_61 ( L_14 , V_4 -> V_89 ) ;
V_93:
F_61 ( L_13 , V_4 -> V_89 ) ;
V_91:
return - V_98 ;
}
static void T_5 F_62 ( struct V_4 * V_4 )
{
F_61 ( L_13 , V_4 -> V_95 ) ;
F_61 ( L_14 , V_4 -> V_89 ) ;
F_61 ( L_13 , V_4 -> V_89 ) ;
}
int T_6 F_63 ( void )
{
return F_64 ( & V_99 ) ;
}
void T_7 F_65 ( void )
{
F_66 ( & V_99 ) ;
}
