static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 . V_6 ) ;
F_3 ( V_4 -> V_7 ) ;
F_4 ( V_8 , V_4 ) ;
}
static inline void F_5 ( struct V_3 * V_4 )
{
F_6 ( & V_9 ) ;
F_7 ( V_4 ) ;
F_8 ( & V_4 -> V_5 . V_6 , F_1 ) ;
}
static long F_9 ( void )
{
return F_10 ( & V_9 ) ;
}
unsigned long F_11 ( void )
{
return V_10 . V_11 ;
}
int F_12 ( T_1 * V_12 , int V_13 ,
void T_2 * V_14 , T_3 * V_15 , T_4 * V_16 )
{
V_10 . V_9 = F_9 () ;
return F_13 ( V_12 , V_13 , V_14 , V_15 , V_16 ) ;
}
int F_12 ( T_1 * V_12 , int V_13 ,
void T_2 * V_14 , T_3 * V_15 , T_4 * V_16 )
{
return - V_17 ;
}
struct V_3 * F_14 ( void )
{
const struct V_18 * V_18 = F_15 () ;
static long V_19 ;
struct V_3 * V_4 ;
int error ;
if ( F_9 () >= V_10 . V_11 && ! F_16 ( V_20 ) ) {
if ( F_17 ( & V_9 ) >= V_10 . V_11 )
goto V_21;
}
V_4 = F_18 ( V_8 , V_22 ) ;
if ( F_19 ( ! V_4 ) )
return F_20 ( - V_23 ) ;
F_21 ( & V_9 ) ;
V_4 -> V_7 = F_22 ( V_18 ) ;
error = F_23 ( V_4 ) ;
if ( F_19 ( error ) ) {
F_5 ( V_4 ) ;
return F_20 ( error ) ;
}
F_24 ( & V_4 -> V_5 . V_24 ) ;
F_25 ( & V_4 -> V_25 , 1 ) ;
F_26 ( & V_4 -> V_26 . V_27 ) ;
F_27 ( & V_4 -> V_28 ) ;
F_28 ( V_4 ) ;
return V_4 ;
V_21:
if ( F_9 () > V_19 ) {
F_29 ( L_1 , F_11 () ) ;
V_19 = F_9 () ;
}
return F_20 ( - V_29 ) ;
}
struct V_3 * F_30 ( struct V_30 * V_30 , T_5 V_31 ,
const struct V_32 * V_33 )
{
struct V_3 * V_3 ;
V_3 = F_14 () ;
if ( F_31 ( V_3 ) )
return V_3 ;
V_3 -> V_34 = * V_30 ;
V_3 -> V_35 = V_30 -> V_36 -> V_37 ;
V_3 -> V_38 = V_30 -> V_36 -> V_37 -> V_39 ;
V_3 -> V_40 = V_31 ;
V_3 -> V_41 = V_33 ;
if ( ( V_31 & V_42 ) && ! F_32 ( V_30 -> V_36 -> V_37 -> V_43 ) ) {
F_33 ( V_3 ) ;
F_34 ( F_35 ( V_30 -> V_44 ) ) ;
}
if ( ( V_31 & ( V_45 | V_42 ) ) == V_45 )
F_36 ( V_30 -> V_36 -> V_37 ) ;
return V_3 ;
}
static void F_37 ( struct V_3 * V_3 )
{
struct V_46 * V_44 = V_3 -> V_34 . V_44 ;
struct V_36 * V_36 = V_3 -> V_34 . V_36 ;
struct V_47 * V_47 = V_36 -> V_37 ;
F_38 ( V_47 ) ;
if ( F_32 ( V_47 -> V_43 ) )
return;
if ( F_39 ( V_3 ) != 0 )
return;
F_40 ( V_44 ) ;
F_41 ( V_3 ) ;
}
static void F_42 ( struct V_3 * V_3 )
{
struct V_36 * V_36 = V_3 -> V_34 . V_36 ;
struct V_46 * V_44 = V_3 -> V_34 . V_44 ;
struct V_47 * V_47 = V_3 -> V_35 ;
F_43 () ;
F_44 ( V_3 ) ;
F_45 ( V_3 ) ;
F_46 ( V_3 ) ;
if ( F_19 ( V_3 -> V_48 & V_49 ) ) {
if ( V_3 -> V_41 && V_3 -> V_41 -> V_50 )
V_3 -> V_41 -> V_50 ( - 1 , V_3 , 0 ) ;
}
F_47 ( V_3 ) ;
if ( V_3 -> V_41 && V_3 -> V_41 -> V_51 )
V_3 -> V_41 -> V_51 ( V_47 , V_3 ) ;
F_48 ( V_3 ) ;
if ( F_19 ( F_49 ( V_47 -> V_43 ) && V_47 -> V_52 != NULL &&
! ( V_3 -> V_40 & V_53 ) ) ) {
F_50 ( V_47 -> V_52 ) ;
}
F_51 ( V_3 -> V_41 ) ;
F_52 ( V_3 -> V_26 . V_54 ) ;
if ( ( V_3 -> V_40 & ( V_45 | V_42 ) ) == V_45 )
F_53 ( V_47 ) ;
if ( V_3 -> V_40 & V_42 )
F_37 ( V_3 ) ;
V_3 -> V_34 . V_36 = NULL ;
V_3 -> V_34 . V_44 = NULL ;
V_3 -> V_35 = NULL ;
F_5 ( V_3 ) ;
F_54 ( V_36 ) ;
F_55 ( V_44 ) ;
}
static void F_56 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = F_57 ( & V_59 ) ;
struct V_57 * V_60 ;
for (; V_58 ; V_58 = V_60 ) {
V_60 = F_58 ( V_58 ) ;
F_42 ( F_59 ( V_58 , struct V_3 , V_5 . V_61 ) ) ;
}
}
static void F_60 ( struct V_62 * V_63 )
{
F_42 ( F_2 ( V_63 , struct V_3 , V_5 . V_6 ) ) ;
}
void F_61 ( void )
{
F_56 ( NULL ) ;
}
void F_62 ( struct V_3 * V_3 )
{
if ( F_63 ( & V_3 -> V_25 ) ) {
struct V_64 * V_65 = V_66 ;
F_64 ( V_3 ) ;
if ( F_65 ( ! F_66 () && ! ( V_65 -> V_67 & V_68 ) ) ) {
F_67 ( & V_3 -> V_5 . V_6 , F_60 ) ;
if ( ! F_68 ( V_65 , & V_3 -> V_5 . V_6 , true ) )
return;
}
if ( F_69 ( & V_3 -> V_5 . V_61 , & V_59 ) )
F_70 ( & V_69 ) ;
}
}
void F_71 ( struct V_3 * V_3 )
{
if ( F_63 ( & V_3 -> V_25 ) ) {
struct V_64 * V_65 = V_66 ;
F_64 ( V_3 ) ;
F_72 ( ! ( V_65 -> V_67 & V_68 ) ) ;
F_42 ( V_3 ) ;
}
}
void F_73 ( struct V_3 * V_3 )
{
if ( F_63 ( & V_3 -> V_25 ) ) {
F_48 ( V_3 ) ;
F_64 ( V_3 ) ;
F_5 ( V_3 ) ;
}
}
static inline int F_74 ( struct V_3 * V_3 )
{
#ifdef F_75
return V_3 -> V_70 ;
#else
return F_76 () ;
#endif
}
static inline void F_77 ( struct V_3 * V_3 , struct V_71 * V_72 )
{
struct V_73 * V_74 ;
#ifdef F_75
int V_75 ;
V_75 = F_76 () ;
V_3 -> V_70 = V_75 ;
V_74 = F_78 ( V_72 -> V_76 , V_75 ) ;
#else
V_74 = & V_72 -> V_76 ;
#endif
F_79 ( & V_3 -> V_5 . V_24 , V_74 ) ;
}
void F_80 ( struct V_3 * V_3 , struct V_71 * V_72 )
{
F_81 ( & V_77 ) ;
F_77 ( V_3 , V_72 ) ;
F_82 ( & V_77 ) ;
}
void F_64 ( struct V_3 * V_3 )
{
if ( ! F_83 ( & V_3 -> V_5 . V_24 ) ) {
F_84 ( & V_77 , F_74 ( V_3 ) ) ;
F_85 ( & V_3 -> V_5 . V_24 ) ;
F_86 ( & V_77 , F_74 ( V_3 ) ) ;
}
}
void F_87 ( struct V_71 * V_72 )
{
struct V_3 * V_4 ;
F_88 ( & V_77 ) ;
F_89 (sb, f) {
if ( ! F_90 ( F_91 ( V_4 ) -> V_43 ) )
continue;
if ( ! F_92 ( V_4 ) )
continue;
if ( ! ( V_4 -> V_40 & V_42 ) )
continue;
F_93 ( & V_4 -> V_28 ) ;
V_4 -> V_40 &= ~ V_42 ;
F_94 ( & V_4 -> V_28 ) ;
if ( F_39 ( V_4 ) != 0 )
continue;
F_40 ( V_4 -> V_34 . V_44 ) ;
F_41 ( V_4 ) ;
} V_78 ;
F_95 ( & V_77 ) ;
}
void T_6 F_96 ( unsigned long V_79 )
{
unsigned long V_80 ;
V_8 = F_97 ( L_2 , sizeof( struct V_3 ) , 0 ,
V_81 | V_82 , NULL ) ;
V_80 = ( V_79 * ( V_83 / 1024 ) ) / 10 ;
V_10 . V_11 = F_98 (unsigned long, n, NR_FILE) ;
F_99 () ;
F_100 ( & V_77 , L_3 ) ;
F_101 ( & V_9 , 0 ) ;
}
