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
if ( F_9 () >= V_10 . V_11 && ! F_16 ( V_20 ) ) {
if ( F_17 ( & V_9 ) >= V_10 . V_11 )
goto V_21;
}
V_4 = F_18 ( V_8 , V_22 ) ;
if ( V_4 == NULL )
goto V_23;
F_19 ( & V_9 ) ;
V_4 -> V_7 = F_20 ( V_18 ) ;
if ( F_21 ( V_4 ) )
goto V_24;
F_22 ( & V_4 -> V_5 . V_25 ) ;
F_23 ( & V_4 -> V_26 , 1 ) ;
F_24 ( & V_4 -> V_27 . V_28 ) ;
F_25 ( & V_4 -> V_29 ) ;
F_26 ( V_4 ) ;
return V_4 ;
V_21:
if ( F_9 () > V_19 ) {
F_27 ( L_1 , F_11 () ) ;
V_19 = F_9 () ;
}
goto V_23;
V_24:
F_5 ( V_4 ) ;
V_23:
return NULL ;
}
struct V_3 * F_28 ( struct V_30 * V_30 , T_5 V_31 ,
const struct V_32 * V_33 )
{
struct V_3 * V_3 ;
V_3 = F_14 () ;
if ( ! V_3 )
return NULL ;
V_3 -> V_34 = * V_30 ;
V_3 -> V_35 = V_30 -> V_36 -> V_37 -> V_38 ;
V_3 -> V_39 = V_31 ;
V_3 -> V_40 = V_33 ;
if ( ( V_31 & V_41 ) && ! F_29 ( V_30 -> V_36 -> V_37 -> V_42 ) ) {
F_30 ( V_3 ) ;
F_31 ( F_32 ( V_30 -> V_43 ) ) ;
}
if ( ( V_31 & ( V_44 | V_41 ) ) == V_44 )
F_33 ( V_30 -> V_36 -> V_37 ) ;
return V_3 ;
}
static void F_34 ( struct V_3 * V_3 )
{
struct V_45 * V_43 = V_3 -> V_34 . V_43 ;
struct V_36 * V_36 = V_3 -> V_34 . V_36 ;
struct V_46 * V_46 = V_36 -> V_37 ;
F_35 ( V_46 ) ;
if ( F_29 ( V_46 -> V_42 ) )
return;
if ( F_36 ( V_3 ) != 0 )
return;
F_37 ( V_43 ) ;
F_38 ( V_3 ) ;
}
static void F_39 ( struct V_3 * V_3 )
{
struct V_36 * V_36 = V_3 -> V_34 . V_36 ;
struct V_45 * V_43 = V_3 -> V_34 . V_43 ;
struct V_46 * V_46 = V_36 -> V_37 ;
F_40 () ;
F_41 ( V_3 ) ;
F_42 ( V_3 ) ;
F_43 ( V_3 ) ;
if ( F_44 ( V_3 -> V_47 & V_48 ) ) {
if ( V_3 -> V_40 && V_3 -> V_40 -> V_49 )
V_3 -> V_40 -> V_49 ( - 1 , V_3 , 0 ) ;
}
F_45 ( V_3 ) ;
if ( V_3 -> V_40 && V_3 -> V_40 -> V_50 )
V_3 -> V_40 -> V_50 ( V_46 , V_3 ) ;
F_46 ( V_3 ) ;
if ( F_44 ( F_47 ( V_46 -> V_42 ) && V_46 -> V_51 != NULL &&
! ( V_3 -> V_39 & V_52 ) ) ) {
F_48 ( V_46 -> V_51 ) ;
}
F_49 ( V_3 -> V_40 ) ;
F_50 ( V_3 -> V_27 . V_53 ) ;
if ( ( V_3 -> V_39 & ( V_44 | V_41 ) ) == V_44 )
F_51 ( V_46 ) ;
if ( V_3 -> V_39 & V_41 )
F_34 ( V_3 ) ;
V_3 -> V_34 . V_36 = NULL ;
V_3 -> V_34 . V_43 = NULL ;
F_5 ( V_3 ) ;
F_52 ( V_36 ) ;
F_53 ( V_43 ) ;
}
static void F_54 ( struct V_54 * V_55 )
{
F_55 ( V_2 ) ;
F_56 ( & V_56 ) ;
F_57 ( & V_57 , & V_2 ) ;
F_58 ( & V_56 ) ;
while ( ! F_59 ( & V_2 ) ) {
struct V_3 * V_4 = F_60 ( & V_2 , struct V_3 , V_5 . V_25 ) ;
F_61 ( & V_4 -> V_5 . V_25 ) ;
F_39 ( V_4 ) ;
}
}
static void F_62 ( struct V_58 * V_59 )
{
F_39 ( F_2 ( V_59 , struct V_3 , V_5 . V_6 ) ) ;
}
void F_63 ( void )
{
F_54 ( NULL ) ;
}
void F_64 ( struct V_3 * V_3 )
{
if ( F_65 ( & V_3 -> V_26 ) ) {
struct V_60 * V_61 = V_62 ;
F_66 ( V_3 ) ;
if ( F_44 ( F_67 () || V_61 -> V_63 & V_64 ) ) {
unsigned long V_63 ;
F_68 ( & V_56 , V_63 ) ;
F_69 ( & V_3 -> V_5 . V_25 , & V_57 ) ;
F_70 ( & V_65 ) ;
F_71 ( & V_56 , V_63 ) ;
return;
}
F_72 ( & V_3 -> V_5 . V_6 , F_62 ) ;
F_73 ( V_61 , & V_3 -> V_5 . V_6 , true ) ;
}
}
void F_74 ( struct V_3 * V_3 )
{
if ( F_65 ( & V_3 -> V_26 ) ) {
struct V_60 * V_61 = V_62 ;
F_66 ( V_3 ) ;
F_75 ( ! ( V_61 -> V_63 & V_64 ) ) ;
F_39 ( V_3 ) ;
}
}
void F_76 ( struct V_3 * V_3 )
{
if ( F_65 ( & V_3 -> V_26 ) ) {
F_46 ( V_3 ) ;
F_66 ( V_3 ) ;
F_5 ( V_3 ) ;
}
}
static inline int F_77 ( struct V_3 * V_3 )
{
#ifdef F_78
return V_3 -> V_66 ;
#else
return F_79 () ;
#endif
}
static inline void F_80 ( struct V_3 * V_3 , struct V_67 * V_68 )
{
struct V_69 * V_70 ;
#ifdef F_78
int V_71 ;
V_71 = F_79 () ;
V_3 -> V_66 = V_71 ;
V_70 = F_81 ( V_68 -> V_72 , V_71 ) ;
#else
V_70 = & V_68 -> V_72 ;
#endif
F_69 ( & V_3 -> V_5 . V_25 , V_70 ) ;
}
void F_82 ( struct V_3 * V_3 , struct V_67 * V_68 )
{
F_83 ( & V_73 ) ;
F_80 ( V_3 , V_68 ) ;
F_84 ( & V_73 ) ;
}
void F_66 ( struct V_3 * V_3 )
{
if ( ! F_59 ( & V_3 -> V_5 . V_25 ) ) {
F_85 ( & V_73 , F_77 ( V_3 ) ) ;
F_61 ( & V_3 -> V_5 . V_25 ) ;
F_86 ( & V_73 , F_77 ( V_3 ) ) ;
}
}
void F_87 ( struct V_67 * V_68 )
{
struct V_3 * V_4 ;
F_88 ( & V_73 ) ;
F_89 (sb, f) {
if ( ! F_90 ( V_4 -> V_34 . V_36 -> V_37 -> V_42 ) )
continue;
if ( ! F_91 ( V_4 ) )
continue;
if ( ! ( V_4 -> V_39 & V_41 ) )
continue;
F_92 ( & V_4 -> V_29 ) ;
V_4 -> V_39 &= ~ V_41 ;
F_93 ( & V_4 -> V_29 ) ;
if ( F_36 ( V_4 ) != 0 )
continue;
F_37 ( V_4 -> V_34 . V_43 ) ;
F_38 ( V_4 ) ;
} V_74 ;
F_94 ( & V_73 ) ;
}
void T_6 F_95 ( unsigned long V_75 )
{
unsigned long V_76 ;
V_8 = F_96 ( L_2 , sizeof( struct V_3 ) , 0 ,
V_77 | V_78 , NULL ) ;
V_76 = ( V_75 * ( V_79 / 1024 ) ) / 10 ;
V_10 . V_11 = F_97 (unsigned long, n, NR_FILE) ;
F_98 () ;
F_99 ( & V_73 , L_3 ) ;
F_100 ( & V_9 , 0 ) ;
}
