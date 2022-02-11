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
F_24 ( & V_4 -> V_24 , 1 ) ;
F_25 ( & V_4 -> V_25 . V_26 ) ;
F_26 ( & V_4 -> V_27 ) ;
F_27 ( V_4 ) ;
return V_4 ;
V_21:
if ( F_9 () > V_19 ) {
F_28 ( L_1 , F_11 () ) ;
V_19 = F_9 () ;
}
return F_20 ( - V_28 ) ;
}
struct V_3 * F_29 ( struct V_29 * V_29 , T_5 V_30 ,
const struct V_31 * V_32 )
{
struct V_3 * V_3 ;
V_3 = F_14 () ;
if ( F_30 ( V_3 ) )
return V_3 ;
V_3 -> V_33 = * V_29 ;
V_3 -> V_34 = V_29 -> V_35 -> V_36 ;
V_3 -> V_37 = V_29 -> V_35 -> V_36 -> V_38 ;
V_3 -> V_39 = V_30 ;
V_3 -> V_40 = V_32 ;
if ( ( V_30 & V_41 ) && ! F_31 ( V_29 -> V_35 -> V_36 -> V_42 ) ) {
F_32 ( V_3 ) ;
F_33 ( F_34 ( V_29 -> V_43 ) ) ;
}
if ( ( V_30 & ( V_44 | V_41 ) ) == V_44 )
F_35 ( V_29 -> V_35 -> V_36 ) ;
return V_3 ;
}
static void F_36 ( struct V_3 * V_3 )
{
struct V_45 * V_43 = V_3 -> V_33 . V_43 ;
struct V_35 * V_35 = V_3 -> V_33 . V_35 ;
struct V_46 * V_46 = V_35 -> V_36 ;
F_37 ( V_46 ) ;
if ( F_31 ( V_46 -> V_42 ) )
return;
if ( F_38 ( V_3 ) != 0 )
return;
F_39 ( V_43 ) ;
F_40 ( V_3 ) ;
}
static void F_41 ( struct V_3 * V_3 )
{
struct V_35 * V_35 = V_3 -> V_33 . V_35 ;
struct V_45 * V_43 = V_3 -> V_33 . V_43 ;
struct V_46 * V_46 = V_3 -> V_34 ;
F_42 () ;
F_43 ( V_3 ) ;
F_44 ( V_3 ) ;
F_45 ( V_3 ) ;
if ( F_19 ( V_3 -> V_47 & V_48 ) ) {
if ( V_3 -> V_40 -> V_49 )
V_3 -> V_40 -> V_49 ( - 1 , V_3 , 0 ) ;
}
F_46 ( V_3 ) ;
if ( V_3 -> V_40 -> V_50 )
V_3 -> V_40 -> V_50 ( V_46 , V_3 ) ;
F_47 ( V_3 ) ;
if ( F_19 ( F_48 ( V_46 -> V_42 ) && V_46 -> V_51 != NULL &&
! ( V_3 -> V_39 & V_52 ) ) ) {
F_49 ( V_46 -> V_51 ) ;
}
F_50 ( V_3 -> V_40 ) ;
F_51 ( V_3 -> V_25 . V_53 ) ;
if ( ( V_3 -> V_39 & ( V_44 | V_41 ) ) == V_44 )
F_52 ( V_46 ) ;
if ( V_3 -> V_39 & V_41 )
F_36 ( V_3 ) ;
V_3 -> V_33 . V_35 = NULL ;
V_3 -> V_33 . V_43 = NULL ;
V_3 -> V_34 = NULL ;
F_5 ( V_3 ) ;
F_53 ( V_35 ) ;
F_54 ( V_43 ) ;
}
static void F_55 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = F_56 ( & V_58 ) ;
struct V_56 * V_59 ;
for (; V_57 ; V_57 = V_59 ) {
V_59 = F_57 ( V_57 ) ;
F_41 ( F_58 ( V_57 , struct V_3 , V_5 . V_60 ) ) ;
}
}
static void F_59 ( struct V_61 * V_62 )
{
F_41 ( F_2 ( V_62 , struct V_3 , V_5 . V_6 ) ) ;
}
void F_60 ( void )
{
F_55 ( NULL ) ;
}
void F_61 ( struct V_3 * V_3 )
{
if ( F_62 ( & V_3 -> V_24 ) ) {
struct V_63 * V_64 = V_65 ;
if ( F_63 ( ! F_64 () && ! ( V_64 -> V_66 & V_67 ) ) ) {
F_65 ( & V_3 -> V_5 . V_6 , F_59 ) ;
if ( ! F_66 ( V_64 , & V_3 -> V_5 . V_6 , true ) )
return;
}
if ( F_67 ( & V_3 -> V_5 . V_60 , & V_58 ) )
F_68 ( & V_68 , 1 ) ;
}
}
void F_69 ( struct V_3 * V_3 )
{
if ( F_62 ( & V_3 -> V_24 ) ) {
struct V_63 * V_64 = V_65 ;
F_70 ( ! ( V_64 -> V_66 & V_67 ) ) ;
F_41 ( V_3 ) ;
}
}
void F_71 ( struct V_3 * V_3 )
{
if ( F_62 ( & V_3 -> V_24 ) ) {
F_47 ( V_3 ) ;
F_5 ( V_3 ) ;
}
}
void T_6 F_72 ( unsigned long V_69 )
{
unsigned long V_70 ;
V_8 = F_73 ( L_2 , sizeof( struct V_3 ) , 0 ,
V_71 | V_72 , NULL ) ;
V_70 = ( V_69 * ( V_73 / 1024 ) ) / 10 ;
V_10 . V_11 = F_74 (unsigned long, n, NR_FILE) ;
F_75 () ;
F_76 ( & V_9 , 0 ) ;
}
