struct V_1 * F_1 ( int V_2 )
{
return & F_2 ( V_3 , V_2 ) ;
}
int F_3 ( void )
{
struct V_4 * V_5 = F_4 ( V_3 . V_6 ) ;
if ( ! V_5 || ! ( V_5 -> V_7 & V_8 ) )
return 0 ;
if ( ! ( V_5 -> V_7 & V_9 ) )
return 1 ;
return F_5 () ;
}
static void F_6 ( int V_2 )
{
if ( V_10 == V_2 ) {
F_7 ( & V_11 ) ;
V_12 = F_8 ( V_12 , V_13 ) ;
F_9 ( 1 ) ;
F_10 ( & V_11 ) ;
F_11 () ;
}
F_12 ( F_13 ( F_14 () ) ) ;
F_15 ( V_14 ) ;
}
void F_16 ( struct V_4 * V_5 )
{
int V_2 = F_17 () ;
T_1 V_15 = V_5 -> V_16 ;
F_6 ( V_2 ) ;
#if F_18 ( V_17 ) || F_18 ( V_18 )
if ( V_5 -> V_19 != F_16 )
return;
#endif
if ( ! F_19 ( V_5 ) )
return;
for (; ; ) {
V_15 = F_8 ( V_15 , V_13 ) ;
if ( ! F_20 ( V_5 , V_15 , false ) )
return;
if ( F_21 () )
F_6 ( V_2 ) ;
}
}
void F_22 ( struct V_4 * V_5 , int V_20 )
{
F_23 ( V_5 , V_20 ) ;
if ( ! F_24 ( V_5 ) )
return;
if ( ( V_5 -> V_7 & V_21 ) &&
! F_25 () ) {
F_26 ( V_5 , V_22 ) ;
} else {
unsigned long V_23 ;
T_1 V_15 ;
do {
V_23 = F_27 ( & V_11 ) ;
V_15 = V_12 ;
} while ( F_28 ( & V_11 , V_23 ) );
F_26 ( V_5 , V_24 ) ;
for (; ; ) {
if ( ! F_20 ( V_5 , V_15 , false ) )
return;
V_15 = F_8 ( V_15 , V_13 ) ;
}
}
}
static void F_29 ( struct V_1 * V_25 ,
struct V_4 * V_26 , int V_2 ,
const struct V_27 * V_27 )
{
void (* F_30)( struct V_4 * ) = NULL ;
T_1 V_16 = 0 ;
if ( ! V_25 -> V_6 ) {
if ( V_10 == V_28 ) {
if ( ! F_31 ( V_2 ) )
V_10 = V_2 ;
else
V_10 = V_29 ;
V_12 = F_32 () ;
V_13 = V_30 / V_31 ;
}
V_25 -> V_32 = V_33 ;
} else {
F_30 = V_25 -> V_6 -> V_19 ;
V_16 = V_25 -> V_6 -> V_16 ;
V_25 -> V_6 -> V_19 = V_34 ;
}
V_25 -> V_6 = V_26 ;
if ( ! F_33 ( V_26 -> V_27 , V_27 ) )
F_34 ( V_26 -> V_35 , V_27 ) ;
if ( F_35 ( V_26 , V_2 ) )
return;
if ( V_25 -> V_32 == V_33 )
F_22 ( V_26 , 0 ) ;
else
F_36 ( V_26 , F_30 , V_16 ) ;
}
void F_37 ( struct V_4 * V_26 )
{
struct V_1 * V_25 = F_38 ( & V_3 ) ;
int V_2 = F_17 () ;
F_39 ( V_25 -> V_6 , V_26 ) ;
F_29 ( V_25 , V_26 , V_2 , F_40 ( V_2 ) ) ;
if ( V_26 -> V_7 & V_8 )
F_41 () ;
}
static bool F_42 ( struct V_4 * V_36 ,
struct V_4 * V_26 , int V_2 )
{
if ( ! F_43 ( V_2 , V_26 -> V_27 ) )
return false ;
if ( F_33 ( V_26 -> V_27 , F_40 ( V_2 ) ) )
return true ;
if ( V_26 -> V_35 >= 0 && ! F_44 ( V_26 -> V_35 ) )
return false ;
if ( V_36 && F_33 ( V_36 -> V_27 , F_40 ( V_2 ) ) )
return false ;
return true ;
}
static bool F_45 ( struct V_4 * V_36 ,
struct V_4 * V_26 )
{
if ( ! ( V_26 -> V_7 & V_8 ) ) {
if ( V_36 && ( V_36 -> V_7 & V_8 ) )
return false ;
if ( F_46 () )
return false ;
}
return ! V_36 ||
V_26 -> V_37 > V_36 -> V_37 ||
! F_33 ( V_36 -> V_27 , V_26 -> V_27 ) ;
}
bool F_47 ( struct V_4 * V_36 ,
struct V_4 * V_26 )
{
if ( ! F_42 ( V_36 , V_26 , F_17 () ) )
return false ;
return F_45 ( V_36 , V_26 ) ;
}
void F_48 ( struct V_4 * V_26 )
{
struct V_4 * V_36 ;
struct V_1 * V_25 ;
int V_2 ;
V_2 = F_17 () ;
V_25 = & F_2 ( V_3 , V_2 ) ;
V_36 = V_25 -> V_6 ;
if ( ! F_42 ( V_36 , V_26 , V_2 ) )
goto V_38;
if ( ! F_45 ( V_36 , V_26 ) )
goto V_38;
if ( ! F_49 ( V_26 -> V_39 ) )
return;
if ( F_50 ( V_36 ) ) {
F_51 ( V_36 ) ;
V_36 = NULL ;
}
F_39 ( V_36 , V_26 ) ;
F_29 ( V_25 , V_26 , V_2 , F_40 ( V_2 ) ) ;
if ( V_26 -> V_7 & V_8 )
F_41 () ;
return;
V_38:
F_52 ( V_26 ) ;
}
int F_53 ( enum V_40 V_41 )
{
struct V_1 * V_25 = F_38 ( & V_3 ) ;
if ( ! ( V_25 -> V_6 -> V_7 & V_9 ) )
return 0 ;
return F_54 ( V_41 ) ;
}
void F_55 ( void )
{
if ( V_10 == F_17 () ) {
int V_2 = F_56 ( V_42 ) ;
V_10 = ( V_2 < V_43 ) ? V_2 :
V_29 ;
}
}
void F_57 ( unsigned int V_2 )
{
struct V_1 * V_25 = & F_2 ( V_3 , V_2 ) ;
struct V_4 * V_5 = V_25 -> V_6 ;
V_25 -> V_32 = V_33 ;
if ( V_5 ) {
F_58 ( V_5 , V_44 ) ;
F_39 ( V_5 , NULL ) ;
V_5 -> V_19 = V_34 ;
V_25 -> V_6 = NULL ;
}
}
void F_59 ( void )
{
struct V_1 * V_25 = F_38 ( & V_3 ) ;
F_51 ( V_25 -> V_6 ) ;
}
void F_60 ( void )
{
struct V_1 * V_25 = F_38 ( & V_3 ) ;
bool V_20 = F_61 () ;
F_62 ( V_25 -> V_6 ) ;
if ( ! V_20 ) {
if ( V_25 -> V_32 == V_33 )
F_22 ( V_25 -> V_6 , 0 ) ;
else
F_63 () ;
}
}
void F_64 ( void )
{
F_59 () ;
F_65 () ;
}
void F_66 ( void )
{
F_67 () ;
F_60 () ;
}
void F_68 ( void )
{
F_69 ( & V_45 ) ;
V_46 ++ ;
if ( V_46 == F_70 () ) {
F_71 ( F_72 ( L_1 ) ,
F_17 () , true ) ;
F_73 () ;
} else {
F_59 () ;
}
F_74 ( & V_45 ) ;
}
void F_75 ( void )
{
F_69 ( & V_45 ) ;
if ( V_46 == F_70 () ) {
F_76 () ;
F_71 ( F_72 ( L_1 ) ,
F_17 () , false ) ;
} else {
F_60 () ;
}
V_46 -- ;
F_74 ( & V_45 ) ;
}
void T_2 F_77 ( void )
{
F_78 () ;
F_79 () ;
}
