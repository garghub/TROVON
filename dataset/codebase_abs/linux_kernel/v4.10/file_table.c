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
if ( ( V_32 & V_41 ) &&
F_31 ( V_34 -> V_42 || V_34 -> V_43 ) )
V_32 |= V_44 ;
if ( ( V_32 & V_45 ) &&
F_31 ( V_34 -> V_14 || V_34 -> V_46 ) )
V_32 |= V_47 ;
V_3 -> V_48 = V_32 ;
V_3 -> V_49 = V_34 ;
if ( ( V_32 & ( V_41 | V_45 ) ) == V_41 )
F_32 ( V_31 -> V_37 -> V_38 ) ;
return V_3 ;
}
static void F_33 ( struct V_3 * V_3 )
{
struct V_37 * V_37 = V_3 -> V_35 . V_37 ;
struct V_50 * V_51 = V_3 -> V_35 . V_51 ;
struct V_52 * V_52 = V_3 -> V_36 ;
F_34 () ;
F_35 ( V_3 ) ;
F_36 ( V_3 ) ;
F_37 ( V_3 ) ;
if ( F_18 ( V_3 -> V_53 & V_54 ) ) {
if ( V_3 -> V_49 -> V_55 )
V_3 -> V_49 -> V_55 ( - 1 , V_3 , 0 ) ;
}
F_38 ( V_3 ) ;
if ( V_3 -> V_49 -> V_56 )
V_3 -> V_49 -> V_56 ( V_52 , V_3 ) ;
F_39 ( V_3 ) ;
if ( F_18 ( F_40 ( V_52 -> V_57 ) && V_52 -> V_58 != NULL &&
! ( V_3 -> V_48 & V_59 ) ) ) {
F_41 ( V_52 -> V_58 ) ;
}
F_42 ( V_3 -> V_49 ) ;
F_43 ( V_3 -> V_26 . V_60 ) ;
if ( ( V_3 -> V_48 & ( V_41 | V_45 ) ) == V_41 )
F_44 ( V_52 ) ;
if ( V_3 -> V_48 & V_61 ) {
F_45 ( V_52 ) ;
F_46 ( V_51 ) ;
}
V_3 -> V_35 . V_37 = NULL ;
V_3 -> V_35 . V_51 = NULL ;
V_3 -> V_36 = NULL ;
F_5 ( V_3 ) ;
F_47 ( V_37 ) ;
F_48 ( V_51 ) ;
}
static void F_49 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = F_50 ( & V_66 ) ;
struct V_64 * V_67 ;
for (; V_65 ; V_65 = V_67 ) {
V_67 = F_51 ( V_65 ) ;
F_33 ( F_52 ( V_65 , struct V_3 , V_5 . V_68 ) ) ;
}
}
static void F_53 ( struct V_69 * V_70 )
{
F_33 ( F_2 ( V_70 , struct V_3 , V_5 . V_6 ) ) ;
}
void F_54 ( void )
{
F_49 ( NULL ) ;
}
void F_55 ( struct V_3 * V_3 )
{
if ( F_56 ( & V_3 -> V_25 ) ) {
struct V_71 * V_72 = V_73 ;
if ( F_31 ( ! F_57 () && ! ( V_72 -> V_74 & V_75 ) ) ) {
F_58 ( & V_3 -> V_5 . V_6 , F_53 ) ;
if ( ! F_59 ( V_72 , & V_3 -> V_5 . V_6 , true ) )
return;
}
if ( F_60 ( & V_3 -> V_5 . V_68 , & V_66 ) )
F_61 ( & V_76 , 1 ) ;
}
}
void F_62 ( struct V_3 * V_3 )
{
if ( F_56 ( & V_3 -> V_25 ) ) {
struct V_71 * V_72 = V_73 ;
F_63 ( ! ( V_72 -> V_74 & V_75 ) ) ;
F_33 ( V_3 ) ;
}
}
void F_64 ( struct V_3 * V_3 )
{
if ( F_56 ( & V_3 -> V_25 ) ) {
F_39 ( V_3 ) ;
F_5 ( V_3 ) ;
}
}
void T_5 F_65 ( void )
{
V_8 = F_66 ( L_2 , sizeof( struct V_3 ) , 0 ,
V_77 | V_78 , NULL ) ;
F_67 ( & V_9 , 0 , V_23 ) ;
}
void T_5 F_68 ( void )
{
unsigned long V_79 ;
unsigned long V_80 = ( V_81 - F_69 () ) * 3 / 2 ;
V_80 = F_70 ( V_80 , V_81 - 1 ) ;
V_79 = ( ( V_81 - V_80 ) * ( V_82 / 1024 ) ) / 10 ;
V_10 . V_11 = F_71 (unsigned long, n, NR_FILE) ;
}
