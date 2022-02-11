int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
return V_6 -> F_1 ( V_2 , V_4 ) || V_8 -> F_1 ( V_2 , V_4 ) ;
}
static struct V_9 * F_2 ( struct V_1 * V_10 )
{
struct V_11 * V_11 = F_3 ( V_10 ) ;
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_9 * V_15 ;
for ( V_13 -> V_16 = 0 ;
V_13 -> V_16 < V_11 -> V_17 . V_18 ;
V_13 -> V_16 ++ ) {
V_15 = F_4 ( F_5 ( & V_11 -> V_17 . V_19 [ V_13 -> V_16 ] ) ) ;
if ( ! F_6 ( V_15 ) )
return V_15 ;
}
return NULL ;
}
static struct V_9 * F_7 ( struct V_1 * V_10 ,
struct V_9 * V_20 )
{
struct V_11 * V_11 = F_3 ( V_10 ) ;
struct V_12 * V_13 = V_10 -> V_14 ;
V_20 = F_4 ( F_8 ( V_20 ) ) ;
while ( F_6 ( V_20 ) ) {
if ( F_9 ( F_10 ( V_20 ) == V_13 -> V_16 ) ) {
if ( ++ V_13 -> V_16 >= V_11 -> V_17 . V_18 )
return NULL ;
}
V_20 = F_4 (
F_5 (
& V_11 -> V_17 . V_19 [ V_13 -> V_16 ] ) ) ;
}
return V_20 ;
}
static struct V_9 * F_11 ( struct V_1 * V_10 , T_1 V_21 )
{
struct V_9 * V_20 = F_2 ( V_10 ) ;
if ( V_20 )
while ( V_21 && ( V_20 = F_7 ( V_10 , V_20 ) ) )
V_21 -- ;
return V_21 ? NULL : V_20 ;
}
static void * F_12 ( struct V_1 * V_10 , T_1 * V_21 )
__acquires( T_2 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
V_13 -> V_22 = F_13 ( F_14 () ) ;
F_15 () ;
return F_11 ( V_10 , * V_21 ) ;
}
static void * F_16 ( struct V_1 * V_2 , void * V_23 , T_1 * V_21 )
{
( * V_21 ) ++ ;
return F_7 ( V_2 , V_23 ) ;
}
static void F_17 ( struct V_1 * V_2 , void * V_23 )
__releases( T_2 )
{
F_18 () ;
}
static int F_19 ( struct V_1 * V_2 , const struct V_24 * V_17 )
{
int V_25 ;
T_3 V_26 ;
char * V_27 ;
V_25 = F_20 ( V_17 -> V_28 , & V_27 , & V_26 ) ;
if ( V_25 )
return 0 ;
V_25 = F_21 ( V_2 , L_1 , V_27 ) ;
F_22 ( V_27 , V_26 ) ;
return V_25 ;
}
static inline int F_19 ( struct V_1 * V_2 , const struct V_24 * V_17 )
{
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , const struct V_24 * V_17 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_29 * V_30 ;
T_4 V_31 ;
V_30 = F_24 ( V_17 ) ;
if ( V_30 ) {
V_31 = V_13 -> V_22 - V_30 -> V_32 ;
if ( V_31 > 0 )
V_31 = F_25 ( V_31 , V_33 ) ;
else
V_31 = 0 ;
return F_21 ( V_2 , L_2 ,
( unsigned long long ) V_31 ) ;
}
return 0 ;
}
static inline int
F_23 ( struct V_1 * V_2 , const struct V_24 * V_17 )
{
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , void * V_23 )
{
struct V_34 * V_19 = V_23 ;
struct V_24 * V_17 = F_27 ( V_19 ) ;
const struct V_5 * V_6 ;
const struct V_7 * V_8 ;
int V_25 = 0 ;
F_28 ( V_17 ) ;
if ( F_29 ( ! F_30 ( & V_17 -> V_35 . V_36 ) ) )
return 0 ;
if ( F_31 ( V_19 ) )
goto V_37;
V_6 = F_32 ( F_33 ( V_17 ) ) ;
F_28 ( V_6 ) ;
V_8 = F_34 ( F_33 ( V_17 ) , F_35 ( V_17 ) ) ;
F_28 ( V_8 ) ;
V_25 = - V_38 ;
if ( F_21 ( V_2 , L_3 ,
V_6 -> V_39 , F_33 ( V_17 ) ,
V_8 -> V_39 , F_35 ( V_17 ) ,
F_36 ( & V_17 -> V_40 )
? ( long ) ( V_17 -> V_40 . V_41 - V_42 ) / V_43 : 0 ) != 0 )
goto V_37;
if ( V_8 -> V_44 && V_8 -> V_44 ( V_2 , V_17 ) )
goto V_37;
if ( F_1 ( V_2 , & V_17 -> V_45 [ V_46 ] . V_4 ,
V_6 , V_8 ) )
goto V_37;
if ( F_37 ( V_2 , V_17 , V_46 ) )
goto V_37;
if ( ! ( F_38 ( V_47 , & V_17 -> V_48 ) ) )
if ( F_21 ( V_2 , L_4 ) )
goto V_37;
if ( F_1 ( V_2 , & V_17 -> V_45 [ V_49 ] . V_4 ,
V_6 , V_8 ) )
goto V_37;
if ( F_37 ( V_2 , V_17 , V_49 ) )
goto V_37;
if ( F_38 ( V_50 , & V_17 -> V_48 ) )
if ( F_21 ( V_2 , L_5 ) )
goto V_37;
#if F_39 ( V_51 )
if ( F_21 ( V_2 , L_6 , V_17 -> V_52 ) )
goto V_37;
#endif
if ( F_19 ( V_2 , V_17 ) )
goto V_37;
#ifdef F_40
if ( F_21 ( V_2 , L_7 , F_41 ( V_17 ) ) )
goto V_37;
#endif
if ( F_23 ( V_2 , V_17 ) )
goto V_37;
if ( F_21 ( V_2 , L_8 , F_42 ( & V_17 -> V_35 . V_36 ) ) )
goto V_37;
V_25 = 0 ;
V_37:
F_43 ( V_17 ) ;
return V_25 ;
}
static int F_44 ( struct V_53 * V_53 , struct V_54 * V_54 )
{
return F_45 ( V_53 , V_54 , & V_55 ,
sizeof( struct V_12 ) ) ;
}
static void * F_46 ( struct V_1 * V_10 , T_1 * V_21 )
{
struct V_11 * V_11 = F_3 ( V_10 ) ;
int V_56 ;
if ( * V_21 == 0 )
return V_57 ;
for ( V_56 = * V_21 - 1 ; V_56 < V_58 ; ++ V_56 ) {
if ( ! F_47 ( V_56 ) )
continue;
* V_21 = V_56 + 1 ;
return F_48 ( V_11 -> V_17 . V_59 , V_56 ) ;
}
return NULL ;
}
static void * F_49 ( struct V_1 * V_10 , void * V_23 , T_1 * V_21 )
{
struct V_11 * V_11 = F_3 ( V_10 ) ;
int V_56 ;
for ( V_56 = * V_21 ; V_56 < V_58 ; ++ V_56 ) {
if ( ! F_47 ( V_56 ) )
continue;
* V_21 = V_56 + 1 ;
return F_48 ( V_11 -> V_17 . V_59 , V_56 ) ;
}
return NULL ;
}
static void F_50 ( struct V_1 * V_10 , void * V_23 )
{
}
static int F_51 ( struct V_1 * V_10 , void * V_23 )
{
struct V_11 * V_11 = F_3 ( V_10 ) ;
unsigned int V_60 = F_42 ( & V_11 -> V_17 . V_61 ) ;
const struct V_62 * V_13 = V_23 ;
if ( V_23 == V_57 ) {
F_21 ( V_10 , L_9 ) ;
return 0 ;
}
F_21 ( V_10 , L_10
L_11 ,
V_60 ,
V_13 -> V_63 ,
V_13 -> V_64 ,
V_13 -> V_65 ,
V_13 -> V_66 ,
V_13 -> V_67 ,
V_13 -> V_68 ,
V_13 -> V_69 ,
V_13 -> V_70 ,
V_13 -> V_71 ,
V_13 -> V_72 ,
V_13 -> V_73 ,
V_13 -> error ,
V_13 -> V_74 ,
V_13 -> V_75 ,
V_13 -> V_76 ,
V_13 -> V_77
) ;
return 0 ;
}
static int F_52 ( struct V_53 * V_53 , struct V_54 * V_54 )
{
return F_45 ( V_53 , V_54 , & V_78 ,
sizeof( struct V_79 ) ) ;
}
static int F_53 ( struct V_11 * V_11 )
{
struct V_80 * V_81 ;
V_81 = F_54 ( V_11 , L_12 , 0440 , & V_82 ) ;
if ( ! V_81 )
goto V_83;
V_81 = F_55 ( L_12 , V_84 , V_11 -> V_85 ,
& V_86 ) ;
if ( ! V_81 )
goto V_87;
return 0 ;
V_87:
F_56 ( V_11 , L_12 ) ;
V_83:
return - V_88 ;
}
static void F_57 ( struct V_11 * V_11 )
{
F_58 ( L_12 , V_11 -> V_85 ) ;
F_56 ( V_11 , L_12 ) ;
}
static int F_53 ( struct V_11 * V_11 )
{
return 0 ;
}
static void F_57 ( struct V_11 * V_11 )
{
}
static int F_59 ( struct V_11 * V_11 )
{
struct V_89 * V_90 ;
if ( F_60 ( V_11 , & V_91 ) ) {
V_92 =
F_61 ( & V_91 , L_13 , V_93 ) ;
if ( ! V_92 )
goto V_94;
}
V_90 = F_62 ( V_95 , sizeof( V_95 ) ,
V_96 ) ;
if ( ! V_90 )
goto V_97;
V_90 [ 1 ] . V_98 = & V_11 -> V_17 . V_61 ;
V_90 [ 2 ] . V_98 = & V_11 -> V_17 . V_18 ;
V_90 [ 3 ] . V_98 = & V_11 -> V_17 . V_99 ;
V_90 [ 4 ] . V_98 = & V_11 -> V_17 . V_100 ;
V_11 -> V_17 . V_101 = F_61 ( V_11 , L_14 , V_90 ) ;
if ( ! V_11 -> V_17 . V_101 )
goto V_102;
return 0 ;
V_102:
F_63 ( V_90 ) ;
V_97:
if ( F_60 ( V_11 , & V_91 ) )
F_64 ( V_92 ) ;
V_94:
F_65 ( V_103 L_15 ) ;
return - V_88 ;
}
static void F_66 ( struct V_11 * V_11 )
{
struct V_89 * V_90 ;
if ( F_60 ( V_11 , & V_91 ) )
F_64 ( V_92 ) ;
V_90 = V_11 -> V_17 . V_101 -> V_104 ;
F_64 ( V_11 -> V_17 . V_101 ) ;
F_63 ( V_90 ) ;
}
static int F_59 ( struct V_11 * V_11 )
{
return 0 ;
}
static void F_66 ( struct V_11 * V_11 )
{
}
static int F_67 ( struct V_11 * V_11 )
{
int V_25 ;
V_25 = F_68 ( V_11 ) ;
if ( V_25 < 0 )
goto V_105;
V_25 = F_53 ( V_11 ) ;
if ( V_25 < 0 )
goto V_106;
V_11 -> V_17 . V_99 = 1 ;
V_11 -> V_17 . V_100 = 0 ;
V_25 = F_59 ( V_11 ) ;
if ( V_25 < 0 )
goto V_107;
return 0 ;
V_107:
F_57 ( V_11 ) ;
V_106:
F_69 ( V_11 ) ;
V_105:
return V_25 ;
}
static void F_70 ( struct V_11 * V_11 )
{
F_66 ( V_11 ) ;
F_57 ( V_11 ) ;
F_69 ( V_11 ) ;
}
static int T_5 F_71 ( void )
{
return F_72 ( & V_108 ) ;
}
static void T_6 F_73 ( void )
{
F_74 ( & V_108 ) ;
}
void F_75 ( void )
{
}
