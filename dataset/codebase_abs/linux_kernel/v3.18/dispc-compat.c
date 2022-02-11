static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
struct V_4 V_5 ;
F_2 ( & V_6 . V_7 , V_3 ) ;
V_5 = V_6 . V_8 ;
memset ( & V_6 . V_8 , 0 , sizeof( V_6 . V_8 ) ) ;
V_6 . V_8 . V_9 = V_10 ;
F_3 ( & V_6 . V_7 , V_3 ) ;
F_4 ( V_2 , L_1 ,
F_5 ( V_10 - V_5 . V_9 ) ) ;
F_4 ( V_2 , L_2 , V_5 . V_11 ) ;
#define F_6 ( T_1 ) \
seq_printf(s, "%-20s %10d\n", #x, stats.irqs[ffs(DISPC_IRQ_##x)-1]);
F_6 ( V_12 ) ;
F_6 ( V_13 ) ;
F_6 ( V_14 ) ;
F_6 ( V_15 ) ;
F_6 ( V_16 ) ;
F_6 ( V_17 ) ;
F_6 ( V_18 ) ;
F_6 ( V_19 ) ;
F_6 ( V_20 ) ;
F_6 ( V_21 ) ;
F_6 ( V_22 ) ;
F_6 ( V_23 ) ;
F_6 ( V_24 ) ;
F_6 ( V_25 ) ;
if ( F_7 () > 3 ) {
F_6 ( V_26 ) ;
F_6 ( V_27 ) ;
}
F_6 ( V_28 ) ;
F_6 ( V_29 ) ;
F_6 ( V_30 ) ;
if ( F_8 ( V_31 ) ) {
F_6 ( V_32 ) ;
F_6 ( V_33 ) ;
F_6 ( V_34 ) ;
F_6 ( V_35 ) ;
}
if ( F_8 ( V_36 ) ) {
F_6 ( V_37 ) ;
F_6 ( V_38 ) ;
F_6 ( V_39 ) ;
F_6 ( V_40 ) ;
}
#undef F_6
}
static void F_9 ( void )
{
T_2 V_41 ;
int V_42 ;
struct V_43 * V_44 ;
V_41 = V_6 . V_45 ;
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ ) {
V_44 = & V_6 . V_47 [ V_42 ] ;
if ( V_44 -> V_48 == NULL )
continue;
V_41 |= V_44 -> V_41 ;
}
F_10 ( V_41 ) ;
}
int F_11 ( T_3 V_48 , void * V_49 , T_2 V_41 )
{
int V_42 ;
int V_50 ;
unsigned long V_3 ;
struct V_43 * V_44 ;
if ( V_48 == NULL )
return - V_51 ;
F_2 ( & V_6 . V_52 , V_3 ) ;
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ ) {
V_44 = & V_6 . V_47 [ V_42 ] ;
if ( V_44 -> V_48 == V_48 && V_44 -> V_49 == V_49 &&
V_44 -> V_41 == V_41 ) {
V_50 = - V_51 ;
goto V_53;
}
}
V_44 = NULL ;
V_50 = - V_54 ;
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ ) {
V_44 = & V_6 . V_47 [ V_42 ] ;
if ( V_44 -> V_48 != NULL )
continue;
V_44 -> V_48 = V_48 ;
V_44 -> V_49 = V_49 ;
V_44 -> V_41 = V_41 ;
V_50 = 0 ;
break;
}
if ( V_50 )
goto V_53;
F_9 () ;
F_3 ( & V_6 . V_52 , V_3 ) ;
return 0 ;
V_53:
F_3 ( & V_6 . V_52 , V_3 ) ;
return V_50 ;
}
int F_12 ( T_3 V_48 , void * V_49 , T_2 V_41 )
{
int V_42 ;
unsigned long V_3 ;
int V_50 = - V_51 ;
struct V_43 * V_44 ;
F_2 ( & V_6 . V_52 , V_3 ) ;
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ ) {
V_44 = & V_6 . V_47 [ V_42 ] ;
if ( V_44 -> V_48 != V_48 || V_44 -> V_49 != V_49 ||
V_44 -> V_41 != V_41 )
continue;
V_44 -> V_48 = NULL ;
V_44 -> V_49 = NULL ;
V_44 -> V_41 = 0 ;
V_50 = 0 ;
break;
}
if ( V_50 == 0 )
F_9 () ;
F_3 ( & V_6 . V_52 , V_3 ) ;
return V_50 ;
}
static void F_13 ( T_2 V_55 )
{
if ( ( V_55 & V_6 . V_45 ) == 0 )
return;
#define F_6 ( T_1 ) (status & DISPC_IRQ_##x) ? (#x " ") : ""
F_14 ( L_3 ,
V_55 ,
F_6 ( V_21 ) ,
F_6 ( V_18 ) ,
F_6 ( V_22 ) ,
F_6 ( V_24 ) ,
F_7 () > 3 ? F_6 ( V_26 ) : L_4 ,
F_6 ( V_28 ) ,
F_6 ( V_29 ) ,
F_8 ( V_31 ) ? F_6 ( V_35 ) : L_4 ,
F_8 ( V_36 ) ? F_6 ( V_40 ) : L_4 ) ;
#undef F_6
}
static T_4 F_15 ( int V_56 , void * V_49 )
{
int V_42 ;
T_2 V_57 , V_58 ;
T_2 V_59 = 0 ;
T_2 V_60 ;
struct V_43 * V_44 ;
struct V_43 V_47 [ V_46 ] ;
F_16 ( & V_6 . V_52 ) ;
V_57 = F_17 () ;
V_58 = F_18 () ;
if ( ! ( V_57 & V_58 ) ) {
F_19 ( & V_6 . V_52 ) ;
return V_61 ;
}
#ifdef F_20
F_16 ( & V_6 . V_7 ) ;
V_6 . V_8 . V_11 ++ ;
F_21 ( V_57 , V_6 . V_8 . V_62 ) ;
F_19 ( & V_6 . V_7 ) ;
#endif
F_13 ( V_57 ) ;
F_22 ( V_57 ) ;
F_17 () ;
memcpy ( V_47 , V_6 . V_47 ,
sizeof( V_47 ) ) ;
F_19 ( & V_6 . V_52 ) ;
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ ) {
V_44 = & V_47 [ V_42 ] ;
if ( ! V_44 -> V_48 )
continue;
if ( V_44 -> V_41 & V_57 ) {
V_44 -> V_48 ( V_44 -> V_49 , V_57 ) ;
V_59 |= V_44 -> V_41 ;
}
}
F_16 ( & V_6 . V_52 ) ;
V_60 = V_57 & ~ V_59 & V_6 . V_45 ;
if ( V_60 ) {
V_6 . V_63 |= V_60 ;
V_6 . V_45 &= ~ V_60 ;
F_9 () ;
F_23 ( & V_6 . V_64 ) ;
}
F_19 ( & V_6 . V_52 ) ;
return V_65 ;
}
static void F_24 ( struct V_66 * V_67 )
{
int V_42 ;
T_2 V_68 ;
unsigned long V_3 ;
static const unsigned V_69 [] = {
V_70 ,
V_71 ,
V_72 ,
V_73 ,
} ;
F_2 ( & V_6 . V_52 , V_3 ) ;
V_68 = V_6 . V_63 ;
V_6 . V_63 = 0 ;
F_3 ( & V_6 . V_52 , V_3 ) ;
F_25 () ;
for ( V_42 = 0 ; V_42 < F_26 () ; ++ V_42 ) {
struct V_74 * V_75 ;
unsigned V_76 ;
V_75 = F_27 ( V_42 ) ;
V_76 = V_69 [ V_42 ] ;
if ( V_76 & V_68 ) {
F_28 ( L_5 ,
V_75 -> V_77 ) ;
V_75 -> V_78 ( V_75 ) ;
F_29 ( 50 ) ;
}
}
for ( V_42 = 0 ; V_42 < F_30 () ; ++ V_42 ) {
struct V_79 * V_80 ;
unsigned V_76 ;
V_80 = F_31 ( V_42 ) ;
V_76 = F_32 ( V_42 ) ;
if ( V_76 & V_68 ) {
int V_81 ;
F_28 ( L_6
L_7 ,
V_80 -> V_77 ) ;
F_33 ( V_80 ) ;
for ( V_81 = 0 ; V_81 < F_26 () ; ++ V_81 ) {
struct V_74 * V_75 ;
V_75 = F_27 ( V_81 ) ;
if ( V_75 -> V_82 != V_83 &&
V_75 -> V_84 == V_80 )
V_75 -> V_78 ( V_75 ) ;
}
F_34 ( V_80 ) ;
}
}
if ( V_68 & V_85 ) {
F_28 ( L_8 ) ;
for ( V_42 = 0 ; V_42 < F_30 () ; ++ V_42 ) {
struct V_79 * V_80 ;
V_80 = F_31 ( V_42 ) ;
F_33 ( V_80 ) ;
}
}
F_2 ( & V_6 . V_52 , V_3 ) ;
V_6 . V_45 |= V_68 ;
F_9 () ;
F_3 ( & V_6 . V_52 , V_3 ) ;
F_35 () ;
}
int F_36 ( void )
{
int V_86 ;
#ifdef F_20
F_37 ( & V_6 . V_7 ) ;
V_6 . V_8 . V_9 = V_10 ;
F_38 ( L_9 , F_1 ) ;
#endif
F_37 ( & V_6 . V_52 ) ;
memset ( V_6 . V_47 , 0 ,
sizeof( V_6 . V_47 ) ) ;
V_6 . V_45 = V_87 ;
if ( F_8 ( V_31 ) )
V_6 . V_45 |= V_88 ;
if ( F_8 ( V_36 ) )
V_6 . V_45 |= V_89 ;
if ( F_7 () > 3 )
V_6 . V_45 |= V_73 ;
F_22 ( F_17 () ) ;
F_39 ( & V_6 . V_64 , F_24 ) ;
F_9 () ;
V_86 = F_40 ( F_15 , & V_6 ) ;
if ( V_86 ) {
F_28 ( L_10 ) ;
return V_86 ;
}
return 0 ;
}
void F_41 ( void )
{
F_42 ( & V_6 ) ;
}
static void F_43 ( void * V_90 , T_2 V_41 )
{
struct V_91 * V_92 = V_90 ;
F_44 ( V_92 ) ;
}
static void F_45 ( enum V_93 V_94 )
{
F_46 ( V_94 , true ) ;
}
static void F_47 ( enum V_93 V_94 )
{
F_48 ( V_95 ) ;
int V_86 ;
T_2 V_56 ;
if ( F_49 ( V_94 ) == false )
return;
V_56 = F_50 ( V_94 ) ;
V_86 = F_11 ( F_43 , & V_95 ,
V_56 ) ;
if ( V_86 )
F_28 ( L_11 ) ;
F_46 ( V_94 , false ) ;
if ( V_86 ) {
F_29 ( 100 ) ;
return;
}
if ( ! F_51 ( & V_95 ,
F_52 ( 100 ) ) )
F_28 ( L_12 ) ;
V_86 = F_12 ( F_43 , & V_95 ,
V_56 ) ;
if ( V_86 )
F_28 ( L_13 ) ;
}
static void F_53 ( void * V_90 , T_2 V_41 )
{
struct V_91 * V_92 = V_90 ;
if ( V_41 & ( V_96 | V_97 ) )
F_44 ( V_92 ) ;
}
static void F_54 ( void )
{
F_48 ( V_98 ) ;
int V_86 ;
T_2 V_99 ;
if ( F_49 ( V_100 ) == true )
return;
V_99 = F_55 ( V_100 ) |
F_32 ( V_100 ) ;
V_86 = F_11 ( F_53 , & V_98 ,
V_99 ) ;
if ( V_86 ) {
F_28 ( L_14 , V_99 ) ;
return;
}
F_46 ( V_100 , true ) ;
if ( ! F_51 ( & V_98 , F_52 ( 100 ) ) )
F_28 ( L_15 ) ;
V_86 = F_12 ( F_53 , & V_98 ,
V_99 ) ;
if ( V_86 )
F_28 ( L_16 , V_99 ) ;
}
static void F_56 ( void )
{
F_48 ( V_95 ) ;
int V_86 , V_42 ;
T_2 V_99 ;
int V_101 ;
if ( F_49 ( V_100 ) == false )
return;
V_99 = F_50 ( V_100 ) ;
V_101 = 1 ;
if ( ! V_99 ) {
V_99 = F_55 ( V_100 ) ;
V_101 = 2 ;
}
V_86 = F_11 ( F_43 , & V_95 ,
V_99 ) ;
if ( V_86 )
F_28 ( L_14 , V_99 ) ;
F_46 ( V_100 , false ) ;
if ( V_86 ) {
F_29 ( 100 ) ;
return;
}
for ( V_42 = 0 ; V_42 < V_101 ; ++ V_42 ) {
if ( ! F_51 ( & V_95 ,
F_52 ( 100 ) ) )
F_28 ( L_17 ) ;
}
V_86 = F_12 ( F_43 , & V_95 ,
V_99 ) ;
if ( V_86 )
F_28 ( L_16 , V_99 ) ;
}
void F_57 ( enum V_93 V_94 )
{
if ( F_58 ( V_94 ) )
F_45 ( V_94 ) ;
else if ( V_94 == V_100 )
F_54 () ;
else
F_59 ( 1 ) ;
}
void F_60 ( enum V_93 V_94 )
{
if ( F_58 ( V_94 ) )
F_47 ( V_94 ) ;
else if ( V_94 == V_100 )
F_56 () ;
else
F_59 ( 1 ) ;
}
static inline void F_61 ( void * V_90 , T_2 V_41 )
{
F_44 ( (struct V_91 * ) V_90 ) ;
}
int F_62 ( T_2 V_102 ,
unsigned long V_103 )
{
int V_86 ;
F_48 ( V_91 ) ;
V_86 = F_11 ( F_61 , & V_91 ,
V_102 ) ;
if ( V_86 )
return V_86 ;
V_103 = F_63 ( & V_91 ,
V_103 ) ;
F_12 ( F_61 , & V_91 , V_102 ) ;
if ( V_103 == 0 )
return - V_104 ;
if ( V_103 == - V_105 )
return - V_105 ;
return 0 ;
}
