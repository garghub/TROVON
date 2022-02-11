static inline void F_1 ( struct V_1 * V_2 )
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
if ( V_3 -> V_40 && V_3 -> V_40 -> V_50 )
V_3 -> V_40 -> V_50 ( V_46 , V_3 ) ;
F_45 ( V_3 ) ;
F_46 ( V_3 ) ;
if ( F_44 ( F_47 ( V_46 -> V_42 ) && V_46 -> V_51 != NULL &&
! ( V_3 -> V_39 & V_52 ) ) ) {
F_48 ( V_46 -> V_51 ) ;
}
F_49 ( V_3 -> V_40 ) ;
F_50 ( V_3 -> V_27 . V_53 ) ;
F_51 ( V_3 ) ;
if ( ( V_3 -> V_39 & ( V_44 | V_41 ) ) == V_44 )
F_52 ( V_46 ) ;
if ( V_3 -> V_39 & V_41 )
F_34 ( V_3 ) ;
V_3 -> V_34 . V_36 = NULL ;
V_3 -> V_34 . V_43 = NULL ;
F_5 ( V_3 ) ;
F_53 ( V_36 ) ;
F_54 ( V_43 ) ;
}
void F_55 ( struct V_3 * V_3 )
{
if ( F_56 ( & V_3 -> V_26 ) )
F_39 ( V_3 ) ;
}
struct V_3 * F_57 ( unsigned int V_54 )
{
struct V_3 * V_3 ;
struct V_55 * V_56 = V_57 -> V_56 ;
F_58 () ;
V_3 = F_59 ( V_56 , V_54 ) ;
if ( V_3 ) {
if ( V_3 -> V_39 & V_52 ||
! F_60 ( & V_3 -> V_26 ) )
V_3 = NULL ;
}
F_61 () ;
return V_3 ;
}
struct V_3 * F_62 ( unsigned int V_54 )
{
struct V_3 * V_3 ;
struct V_55 * V_56 = V_57 -> V_56 ;
F_58 () ;
V_3 = F_59 ( V_56 , V_54 ) ;
if ( V_3 ) {
if ( ! F_60 ( & V_3 -> V_26 ) )
V_3 = NULL ;
}
F_61 () ;
return V_3 ;
}
struct V_3 * F_63 ( unsigned int V_54 , int * V_58 )
{
struct V_3 * V_3 ;
struct V_55 * V_56 = V_57 -> V_56 ;
* V_58 = 0 ;
if ( F_64 ( & V_56 -> V_59 ) == 1 ) {
V_3 = F_59 ( V_56 , V_54 ) ;
if ( V_3 && ( V_3 -> V_39 & V_52 ) )
V_3 = NULL ;
} else {
F_58 () ;
V_3 = F_59 ( V_56 , V_54 ) ;
if ( V_3 ) {
if ( ! ( V_3 -> V_39 & V_52 ) &&
F_60 ( & V_3 -> V_26 ) )
* V_58 = 1 ;
else
V_3 = NULL ;
}
F_61 () ;
}
return V_3 ;
}
struct V_3 * F_65 ( unsigned int V_54 , int * V_58 )
{
struct V_3 * V_3 ;
struct V_55 * V_56 = V_57 -> V_56 ;
* V_58 = 0 ;
if ( F_64 ( & V_56 -> V_59 ) == 1 ) {
V_3 = F_59 ( V_56 , V_54 ) ;
} else {
F_58 () ;
V_3 = F_59 ( V_56 , V_54 ) ;
if ( V_3 ) {
if ( F_60 ( & V_3 -> V_26 ) )
* V_58 = 1 ;
else
V_3 = NULL ;
}
F_61 () ;
}
return V_3 ;
}
void F_66 ( struct V_3 * V_3 )
{
if ( F_56 ( & V_3 -> V_26 ) ) {
F_45 ( V_3 ) ;
F_51 ( V_3 ) ;
F_5 ( V_3 ) ;
}
}
static inline int F_67 ( struct V_3 * V_3 )
{
#ifdef F_68
return V_3 -> V_60 ;
#else
return F_69 () ;
#endif
}
static inline void F_70 ( struct V_3 * V_3 , struct V_61 * V_62 )
{
struct V_63 * V_64 ;
#ifdef F_68
int V_65 ;
V_65 = F_69 () ;
V_3 -> V_60 = V_65 ;
V_64 = F_71 ( V_62 -> V_66 , V_65 ) ;
#else
V_64 = & V_62 -> V_66 ;
#endif
F_72 ( & V_3 -> V_5 . V_25 , V_64 ) ;
}
void F_73 ( struct V_3 * V_3 , struct V_61 * V_62 )
{
F_74 ( & V_67 ) ;
F_70 ( V_3 , V_62 ) ;
F_75 ( & V_67 ) ;
}
void F_51 ( struct V_3 * V_3 )
{
if ( ! F_76 ( & V_3 -> V_5 . V_25 ) ) {
F_77 ( & V_67 , F_67 ( V_3 ) ) ;
F_78 ( & V_3 -> V_5 . V_25 ) ;
F_79 ( & V_67 , F_67 ( V_3 ) ) ;
}
}
void F_80 ( struct V_61 * V_62 )
{
struct V_3 * V_4 ;
V_68:
F_81 ( & V_67 ) ;
F_82 (sb, f) {
struct V_45 * V_43 ;
if ( ! F_83 ( V_4 -> V_34 . V_36 -> V_37 -> V_42 ) )
continue;
if ( ! F_84 ( V_4 ) )
continue;
if ( ! ( V_4 -> V_39 & V_41 ) )
continue;
F_85 ( & V_4 -> V_29 ) ;
V_4 -> V_39 &= ~ V_41 ;
F_86 ( & V_4 -> V_29 ) ;
if ( F_36 ( V_4 ) != 0 )
continue;
F_38 ( V_4 ) ;
V_43 = F_87 ( V_4 -> V_34 . V_43 ) ;
F_88 ( & V_67 ) ;
F_37 ( V_43 ) ;
F_54 ( V_43 ) ;
goto V_68;
} V_69 ;
F_88 ( & V_67 ) ;
}
void T_6 F_89 ( unsigned long V_70 )
{
unsigned long V_71 ;
V_8 = F_90 ( L_2 , sizeof( struct V_3 ) , 0 ,
V_72 | V_73 , NULL ) ;
V_71 = ( V_70 * ( V_74 / 1024 ) ) / 10 ;
V_10 . V_11 = F_91 (unsigned long, n, NR_FILE) ;
F_92 () ;
F_93 ( & V_67 , L_3 ) ;
F_94 ( & V_9 , 0 ) ;
}
