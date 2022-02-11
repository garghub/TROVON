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
int F_11 ( T_1 * V_12 , int V_13 ,
void T_2 * V_14 , T_3 * V_15 , T_4 * V_16 )
{
V_10 . V_9 = F_8 () ;
return F_12 ( V_12 , V_13 , V_14 , V_15 , V_16 ) ;
}
int F_11 ( T_1 * V_12 , int V_13 ,
void T_2 * V_14 , T_3 * V_15 , T_4 * V_16 )
{
return - V_17 ;
}
struct V_3 * F_13 ( void )
{
const struct V_18 * V_18 = F_14 () ;
static long V_19 ;
struct V_3 * V_4 ;
int error ;
if ( F_8 () >= V_10 . V_11 && ! F_15 ( V_20 ) ) {
if ( F_16 ( & V_9 ) >= V_10 . V_11 )
goto V_21;
}
V_4 = F_17 ( V_8 , V_22 ) ;
if ( F_18 ( ! V_4 ) )
return F_19 ( - V_23 ) ;
F_20 ( & V_9 ) ;
V_4 -> V_7 = F_21 ( V_18 ) ;
error = F_22 ( V_4 ) ;
if ( F_18 ( error ) ) {
F_5 ( V_4 ) ;
return F_19 ( error ) ;
}
F_23 ( & V_4 -> V_24 , 1 ) ;
F_24 ( & V_4 -> V_25 . V_26 ) ;
F_25 ( & V_4 -> V_27 ) ;
F_26 ( & V_4 -> V_28 ) ;
F_27 ( V_4 ) ;
return V_4 ;
V_21:
if ( F_8 () > V_19 ) {
F_28 ( L_1 , F_10 () ) ;
V_19 = F_8 () ;
}
return F_19 ( - V_29 ) ;
}
struct V_3 * F_29 ( struct V_30 * V_30 , T_5 V_31 ,
const struct V_32 * V_33 )
{
struct V_3 * V_3 ;
V_3 = F_13 () ;
if ( F_30 ( V_3 ) )
return V_3 ;
V_3 -> V_34 = * V_30 ;
V_3 -> V_35 = V_30 -> V_36 -> V_37 ;
V_3 -> V_38 = V_30 -> V_36 -> V_37 -> V_39 ;
V_3 -> V_40 = V_31 ;
V_3 -> V_41 = V_33 ;
if ( ( V_31 & ( V_42 | V_43 ) ) == V_42 )
F_31 ( V_30 -> V_36 -> V_37 ) ;
return V_3 ;
}
static void F_32 ( struct V_3 * V_3 )
{
struct V_36 * V_36 = V_3 -> V_34 . V_36 ;
struct V_44 * V_45 = V_3 -> V_34 . V_45 ;
struct V_46 * V_46 = V_3 -> V_35 ;
F_33 () ;
F_34 ( V_3 ) ;
F_35 ( V_3 ) ;
F_36 ( V_3 ) ;
if ( F_18 ( V_3 -> V_47 & V_48 ) ) {
if ( V_3 -> V_41 -> V_49 )
V_3 -> V_41 -> V_49 ( - 1 , V_3 , 0 ) ;
}
F_37 ( V_3 ) ;
if ( V_3 -> V_41 -> V_50 )
V_3 -> V_41 -> V_50 ( V_46 , V_3 ) ;
F_38 ( V_3 ) ;
if ( F_18 ( F_39 ( V_46 -> V_51 ) && V_46 -> V_52 != NULL &&
! ( V_3 -> V_40 & V_53 ) ) ) {
F_40 ( V_46 -> V_52 ) ;
}
F_41 ( V_3 -> V_41 ) ;
F_42 ( V_3 -> V_25 . V_54 ) ;
if ( ( V_3 -> V_40 & ( V_42 | V_43 ) ) == V_42 )
F_43 ( V_46 ) ;
if ( V_3 -> V_40 & V_55 ) {
F_44 ( V_46 ) ;
F_45 ( V_45 ) ;
}
V_3 -> V_34 . V_36 = NULL ;
V_3 -> V_34 . V_45 = NULL ;
V_3 -> V_35 = NULL ;
F_5 ( V_3 ) ;
F_46 ( V_36 ) ;
F_47 ( V_45 ) ;
}
static void F_48 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_49 ( & V_60 ) ;
struct V_58 * V_61 ;
for (; V_59 ; V_59 = V_61 ) {
V_61 = F_50 ( V_59 ) ;
F_32 ( F_51 ( V_59 , struct V_3 , V_5 . V_62 ) ) ;
}
}
static void F_52 ( struct V_63 * V_64 )
{
F_32 ( F_2 ( V_64 , struct V_3 , V_5 . V_6 ) ) ;
}
void F_53 ( void )
{
F_48 ( NULL ) ;
}
void F_54 ( struct V_3 * V_3 )
{
if ( F_55 ( & V_3 -> V_24 ) ) {
struct V_65 * V_66 = V_67 ;
if ( F_56 ( ! F_57 () && ! ( V_66 -> V_68 & V_69 ) ) ) {
F_58 ( & V_3 -> V_5 . V_6 , F_52 ) ;
if ( ! F_59 ( V_66 , & V_3 -> V_5 . V_6 , true ) )
return;
}
if ( F_60 ( & V_3 -> V_5 . V_62 , & V_60 ) )
F_61 ( & V_70 , 1 ) ;
}
}
void F_62 ( struct V_3 * V_3 )
{
if ( F_55 ( & V_3 -> V_24 ) ) {
struct V_65 * V_66 = V_67 ;
F_63 ( ! ( V_66 -> V_68 & V_69 ) ) ;
F_32 ( V_3 ) ;
}
}
void F_64 ( struct V_3 * V_3 )
{
if ( F_55 ( & V_3 -> V_24 ) ) {
F_38 ( V_3 ) ;
F_5 ( V_3 ) ;
}
}
void T_6 F_65 ( unsigned long V_71 )
{
unsigned long V_72 ;
V_8 = F_66 ( L_2 , sizeof( struct V_3 ) , 0 ,
V_73 | V_74 , NULL ) ;
V_72 = ( V_71 * ( V_75 / 1024 ) ) / 10 ;
V_10 . V_11 = F_67 (unsigned long, n, NR_FILE) ;
F_68 ( & V_9 , 0 ) ;
}
