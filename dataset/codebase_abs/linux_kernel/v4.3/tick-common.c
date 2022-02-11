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
T_1 V_16 ;
void (* F_30)( struct V_4 * ) = NULL ;
if ( ! V_25 -> V_6 ) {
if ( V_10 == V_28 ) {
if ( ! F_31 ( V_2 ) )
V_10 = V_2 ;
else
V_10 = V_29 ;
V_12 = F_32 () ;
V_13 = F_33 ( 0 , V_30 / V_31 ) ;
}
V_25 -> V_32 = V_33 ;
} else {
F_30 = V_25 -> V_6 -> V_19 ;
V_16 = V_25 -> V_6 -> V_16 ;
V_25 -> V_6 -> V_19 = V_34 ;
}
V_25 -> V_6 = V_26 ;
if ( ! F_34 ( V_26 -> V_27 , V_27 ) )
F_35 ( V_26 -> V_35 , V_27 ) ;
if ( F_36 ( V_26 , V_2 ) )
return;
if ( V_25 -> V_32 == V_33 )
F_22 ( V_26 , 0 ) ;
else
F_37 ( V_26 , F_30 , V_16 ) ;
}
void F_38 ( struct V_4 * V_26 )
{
struct V_1 * V_25 = F_39 ( & V_3 ) ;
int V_2 = F_17 () ;
F_40 ( V_25 -> V_6 , V_26 ) ;
F_29 ( V_25 , V_26 , V_2 , F_41 ( V_2 ) ) ;
if ( V_26 -> V_7 & V_8 )
F_42 () ;
}
static bool F_43 ( struct V_4 * V_36 ,
struct V_4 * V_26 , int V_2 )
{
if ( ! F_44 ( V_2 , V_26 -> V_27 ) )
return false ;
if ( F_34 ( V_26 -> V_27 , F_41 ( V_2 ) ) )
return true ;
if ( V_26 -> V_35 >= 0 && ! F_45 ( V_26 -> V_35 ) )
return false ;
if ( V_36 && F_34 ( V_36 -> V_27 , F_41 ( V_2 ) ) )
return false ;
return true ;
}
static bool F_46 ( struct V_4 * V_36 ,
struct V_4 * V_26 )
{
if ( ! ( V_26 -> V_7 & V_8 ) ) {
if ( V_36 && ( V_36 -> V_7 & V_8 ) )
return false ;
if ( F_47 () )
return false ;
}
return ! V_36 ||
V_26 -> V_37 > V_36 -> V_37 ||
! F_34 ( V_36 -> V_27 , V_26 -> V_27 ) ;
}
bool F_48 ( struct V_4 * V_36 ,
struct V_4 * V_26 )
{
if ( ! F_43 ( V_36 , V_26 , F_17 () ) )
return false ;
return F_46 ( V_36 , V_26 ) ;
}
void F_49 ( struct V_4 * V_26 )
{
struct V_4 * V_36 ;
struct V_1 * V_25 ;
int V_2 ;
V_2 = F_17 () ;
V_25 = & F_2 ( V_3 , V_2 ) ;
V_36 = V_25 -> V_6 ;
if ( ! F_43 ( V_36 , V_26 , V_2 ) )
goto V_38;
if ( ! F_46 ( V_36 , V_26 ) )
goto V_38;
if ( ! F_50 ( V_26 -> V_39 ) )
return;
if ( F_51 ( V_36 ) ) {
F_52 ( V_36 ) ;
V_36 = NULL ;
}
F_40 ( V_36 , V_26 ) ;
F_29 ( V_25 , V_26 , V_2 , F_41 ( V_2 ) ) ;
if ( V_26 -> V_7 & V_8 )
F_42 () ;
return;
V_38:
F_53 ( V_26 ) ;
}
int F_54 ( enum V_40 V_41 )
{
struct V_1 * V_25 = F_39 ( & V_3 ) ;
if ( ! ( V_25 -> V_6 -> V_7 & V_9 ) )
return 0 ;
return F_55 ( V_41 ) ;
}
void F_56 ( void )
{
if ( V_10 == F_17 () ) {
int V_2 = F_57 ( V_42 ) ;
V_10 = ( V_2 < V_43 ) ? V_2 :
V_29 ;
}
}
void F_58 ( unsigned int V_2 )
{
struct V_1 * V_25 = & F_2 ( V_3 , V_2 ) ;
struct V_4 * V_5 = V_25 -> V_6 ;
V_25 -> V_32 = V_33 ;
if ( V_5 ) {
F_59 ( V_5 , V_44 ) ;
F_40 ( V_5 , NULL ) ;
V_5 -> V_19 = V_34 ;
V_25 -> V_6 = NULL ;
}
}
void F_60 ( void )
{
struct V_1 * V_25 = F_39 ( & V_3 ) ;
F_52 ( V_25 -> V_6 ) ;
}
void F_61 ( void )
{
struct V_1 * V_25 = F_39 ( & V_3 ) ;
bool V_20 = F_62 () ;
F_63 ( V_25 -> V_6 ) ;
if ( ! V_20 ) {
if ( V_25 -> V_32 == V_33 )
F_22 ( V_25 -> V_6 , 0 ) ;
else
F_64 () ;
}
}
void F_65 ( void )
{
F_60 () ;
F_66 () ;
}
void F_67 ( void )
{
F_68 () ;
F_61 () ;
}
void F_69 ( void )
{
F_70 ( & V_45 ) ;
V_46 ++ ;
if ( V_46 == F_71 () ) {
F_72 ( F_73 ( L_1 ) ,
F_17 () , true ) ;
F_74 () ;
} else {
F_60 () ;
}
F_75 ( & V_45 ) ;
}
void F_76 ( void )
{
F_70 ( & V_45 ) ;
if ( V_46 == F_71 () ) {
F_77 () ;
F_72 ( F_73 ( L_1 ) ,
F_17 () , false ) ;
} else {
F_61 () ;
}
V_46 -- ;
F_75 ( & V_45 ) ;
}
void T_2 F_78 ( void )
{
F_79 () ;
F_80 () ;
}
