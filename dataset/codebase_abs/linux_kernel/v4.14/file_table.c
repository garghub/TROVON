static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 . V_6 ) ;
F_3 ( V_4 -> V_7 ) ;
F_4 ( V_8 , V_4 ) ;
}
static inline void F_5 ( struct V_3 * V_4 )
{
F_6 ( & V_9 ) ;
F_7 ( & V_4 -> V_5 . V_6 , F_1 ) ;
}
static long F_8 ( void )
{
return F_9 ( & V_9 ) ;
}
unsigned long F_10 ( void )
{
return V_10 . V_11 ;
}
int F_11 ( struct V_12 * V_13 , int V_14 ,
void T_1 * V_15 , T_2 * V_16 , T_3 * V_17 )
{
V_10 . V_9 = F_8 () ;
return F_12 ( V_13 , V_14 , V_15 , V_16 , V_17 ) ;
}
int F_11 ( struct V_12 * V_13 , int V_14 ,
void T_1 * V_15 , T_2 * V_16 , T_3 * V_17 )
{
return - V_18 ;
}
struct V_3 * F_13 ( void )
{
const struct V_19 * V_19 = F_14 () ;
static long V_20 ;
struct V_3 * V_4 ;
int error ;
if ( F_8 () >= V_10 . V_11 && ! F_15 ( V_21 ) ) {
if ( F_16 ( & V_9 ) >= V_10 . V_11 )
goto V_22;
}
V_4 = F_17 ( V_8 , V_23 ) ;
if ( F_18 ( ! V_4 ) )
return F_19 ( - V_24 ) ;
F_20 ( & V_9 ) ;
V_4 -> V_7 = F_21 ( V_19 ) ;
error = F_22 ( V_4 ) ;
if ( F_18 ( error ) ) {
F_5 ( V_4 ) ;
return F_19 ( error ) ;
}
F_23 ( & V_4 -> V_25 , 1 ) ;
F_24 ( & V_4 -> V_26 . V_27 ) ;
F_25 ( & V_4 -> V_28 ) ;
F_26 ( & V_4 -> V_29 ) ;
F_27 ( V_4 ) ;
return V_4 ;
V_22:
if ( F_8 () > V_20 ) {
F_28 ( L_1 , F_10 () ) ;
V_20 = F_8 () ;
}
return F_19 ( - V_30 ) ;
}
struct V_3 * F_29 ( const struct V_31 * V_31 , T_4 V_32 ,
const struct V_33 * V_34 )
{
struct V_3 * V_3 ;
V_3 = F_13 () ;
if ( F_30 ( V_3 ) )
return V_3 ;
V_3 -> V_35 = * V_31 ;
V_3 -> V_36 = V_31 -> V_37 -> V_38 ;
V_3 -> V_39 = V_31 -> V_37 -> V_38 -> V_40 ;
V_3 -> V_41 = F_31 ( V_3 -> V_39 ) ;
if ( ( V_32 & V_42 ) &&
F_32 ( V_34 -> V_43 || V_34 -> V_44 ) )
V_32 |= V_45 ;
if ( ( V_32 & V_46 ) &&
F_32 ( V_34 -> V_14 || V_34 -> V_47 ) )
V_32 |= V_48 ;
V_3 -> V_49 = V_32 ;
V_3 -> V_50 = V_34 ;
if ( ( V_32 & ( V_42 | V_46 ) ) == V_42 )
F_33 ( V_31 -> V_37 -> V_38 ) ;
return V_3 ;
}
static void F_34 ( struct V_3 * V_3 )
{
struct V_37 * V_37 = V_3 -> V_35 . V_37 ;
struct V_51 * V_52 = V_3 -> V_35 . V_52 ;
struct V_53 * V_53 = V_3 -> V_36 ;
F_35 () ;
F_36 ( V_3 ) ;
F_37 ( V_3 ) ;
F_38 ( V_3 ) ;
if ( F_18 ( V_3 -> V_54 & V_55 ) ) {
if ( V_3 -> V_50 -> V_56 )
V_3 -> V_50 -> V_56 ( - 1 , V_3 , 0 ) ;
}
F_39 ( V_3 ) ;
if ( V_3 -> V_50 -> V_57 )
V_3 -> V_50 -> V_57 ( V_53 , V_3 ) ;
F_40 ( V_3 ) ;
if ( F_18 ( F_41 ( V_53 -> V_58 ) && V_53 -> V_59 != NULL &&
! ( V_3 -> V_49 & V_60 ) ) ) {
F_42 ( V_53 -> V_59 ) ;
}
F_43 ( V_3 -> V_50 ) ;
F_44 ( V_3 -> V_26 . V_61 ) ;
if ( ( V_3 -> V_49 & ( V_42 | V_46 ) ) == V_42 )
F_45 ( V_53 ) ;
if ( V_3 -> V_49 & V_62 ) {
F_46 ( V_53 ) ;
F_47 ( V_52 ) ;
}
V_3 -> V_35 . V_37 = NULL ;
V_3 -> V_35 . V_52 = NULL ;
V_3 -> V_36 = NULL ;
F_5 ( V_3 ) ;
F_48 ( V_37 ) ;
F_49 ( V_52 ) ;
}
static void F_50 ( struct V_63 * V_64 )
{
struct V_65 * V_66 = F_51 ( & V_67 ) ;
struct V_3 * V_4 , * V_68 ;
F_52 (f, t, node, f_u.fu_llist)
F_34 ( V_4 ) ;
}
static void F_53 ( struct V_69 * V_70 )
{
F_34 ( F_2 ( V_70 , struct V_3 , V_5 . V_6 ) ) ;
}
void F_54 ( void )
{
F_50 ( NULL ) ;
}
void F_55 ( struct V_3 * V_3 )
{
if ( F_56 ( & V_3 -> V_25 ) ) {
struct V_71 * V_72 = V_73 ;
if ( F_32 ( ! F_57 () && ! ( V_72 -> V_74 & V_75 ) ) ) {
F_58 ( & V_3 -> V_5 . V_6 , F_53 ) ;
if ( ! F_59 ( V_72 , & V_3 -> V_5 . V_6 , true ) )
return;
}
if ( F_60 ( & V_3 -> V_5 . V_76 , & V_67 ) )
F_61 ( & V_77 , 1 ) ;
}
}
void F_62 ( struct V_3 * V_3 )
{
if ( F_56 ( & V_3 -> V_25 ) ) {
struct V_71 * V_72 = V_73 ;
F_63 ( ! ( V_72 -> V_74 & V_75 ) ) ;
F_34 ( V_3 ) ;
}
}
void F_64 ( struct V_3 * V_3 )
{
if ( F_56 ( & V_3 -> V_25 ) ) {
F_40 ( V_3 ) ;
F_5 ( V_3 ) ;
}
}
void T_5 F_65 ( void )
{
V_8 = F_66 ( L_2 , sizeof( struct V_3 ) , 0 ,
V_78 | V_79 , NULL ) ;
F_67 ( & V_9 , 0 , V_23 ) ;
}
void T_5 F_68 ( void )
{
unsigned long V_80 ;
unsigned long V_81 = ( V_82 - F_69 () ) * 3 / 2 ;
V_81 = F_70 ( V_81 , V_82 - 1 ) ;
V_80 = ( ( V_82 - V_81 ) * ( V_83 / 1024 ) ) / 10 ;
V_10 . V_11 = F_71 (unsigned long, n, NR_FILE) ;
}
