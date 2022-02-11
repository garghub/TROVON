static int F_1 ( int * V_1 )
{
T_1 V_2 ;
if ( V_3 . V_4 || V_3 . V_5 )
return 0 ;
if ( V_6 . V_7 != V_8 )
return 0 ;
if ( ! V_9 || F_2 () < 6 )
return 0 ;
F_3 ( V_10 , V_2 ) ;
* V_1 = F_4 ( unsigned , V_11 , V_2 & 0xff ) ;
return ! ! ( V_2 & V_12 ) ;
}
static bool F_5 ( void )
{
T_1 V_13 ;
if ( V_3 . V_14 )
return false ;
F_3 ( V_10 , V_13 ) ;
if ( ( V_13 & ( V_15 | V_16 ) ) !=
( V_15 | V_16 ) )
return false ;
F_3 ( V_17 , V_13 ) ;
if ( ( V_13 & ( V_18 | V_19 ) ) ==
( V_18 | V_19 ) )
return true ;
return false ;
}
bool F_6 ( void )
{
if ( F_7 ( V_20 ) == V_21 )
return false ;
if ( F_8 ( V_22 , F_9 ( & V_23 ) ) )
F_10 ( V_24 , V_25 ) ;
else
F_11 ( V_24 ) ;
return true ;
}
void F_12 ( unsigned long V_26 )
{
if ( F_13 ( V_20 , V_26 ) == V_27 )
F_14 ( & V_28 ) ;
F_13 ( V_20 , V_26 ) = V_21 ;
}
static void F_15 ( bool V_29 )
{
unsigned long V_30 , * V_31 ;
int V_32 ;
T_1 V_33 ;
F_16 ( & V_34 , V_30 ) ;
V_31 = F_9 ( V_23 ) ;
F_17 (bank, owned, MAX_NR_BANKS) {
F_3 ( F_18 ( V_32 ) , V_33 ) ;
if ( V_29 )
V_33 |= V_35 ;
else
V_33 &= ~ V_35 ;
F_19 ( F_18 ( V_32 ) , V_33 ) ;
}
F_20 ( & V_34 , V_30 ) ;
}
unsigned long F_21 ( unsigned long V_36 )
{
if ( ( F_22 ( V_24 ) > 0 ) &&
( F_7 ( V_20 ) == V_27 ) ) {
F_23 () ;
return V_37 ;
}
switch ( F_7 ( V_20 ) ) {
case V_27 :
F_24 ( V_20 , V_38 ) ;
if ( ! F_25 ( 1 , & V_28 ) )
F_26 ( L_1 ) ;
case V_38 :
if ( ! F_27 ( & V_28 ) ) {
F_24 ( V_20 , V_21 ) ;
F_15 ( true ) ;
F_28 () ;
}
return V_39 ;
default:
return V_36 ;
}
}
static bool F_29 ( void )
{
unsigned int V_40 = F_7 ( V_41 ) ;
unsigned long V_42 = F_7 ( V_43 ) ;
unsigned long V_44 = V_45 ;
int V_46 ;
if ( F_7 ( V_20 ) != V_21 )
return true ;
if ( F_30 ( V_44 , V_42 + V_37 ) ) {
V_40 ++ ;
} else {
V_40 = 1 ;
F_24 ( V_43 , V_44 ) ;
}
F_24 ( V_41 , V_40 ) ;
if ( V_40 <= V_47 )
return false ;
F_15 ( false ) ;
F_24 ( V_20 , V_27 ) ;
V_46 = F_31 ( 1 , & V_28 ) ;
F_32 ( V_37 ) ;
F_10 ( V_24 , V_25 ) ;
if ( V_46 == 1 )
F_26 ( L_2 ) ;
return true ;
}
static void F_33 ( void )
{
if ( F_29 () )
return;
F_8 ( V_22 , F_9 ( & V_23 ) ) ;
}
static void F_34 ( int V_1 )
{
unsigned long * V_31 = ( void * ) F_9 ( & V_23 ) ;
unsigned long V_30 ;
int V_48 ;
int V_49 = 0 ;
F_16 ( & V_34 , V_30 ) ;
for ( V_48 = 0 ; V_48 < V_1 ; V_48 ++ ) {
T_1 V_33 ;
int V_50 = 0 ;
if ( F_35 ( V_48 , V_31 ) )
continue;
if ( F_35 ( V_48 , V_51 ) )
continue;
F_3 ( F_18 ( V_48 ) , V_33 ) ;
if ( V_33 & V_35 ) {
F_36 ( V_48 , V_31 ) ;
F_37 ( V_48 , F_9 ( V_52 ) ) ;
continue;
}
if ( ! V_3 . V_53 ) {
V_33 &= ~ V_54 ;
V_33 |= V_55 ;
} else if ( ! ( V_33 & V_54 ) ) {
V_50 = 1 ;
V_33 |= V_55 ;
}
V_33 |= V_35 ;
F_19 ( F_18 ( V_48 ) , V_33 ) ;
F_3 ( F_18 ( V_48 ) , V_33 ) ;
if ( V_33 & V_35 ) {
F_38 ( V_48 , V_31 ) ;
F_37 ( V_48 , F_9 ( V_52 ) ) ;
if ( V_3 . V_53 && V_50 &&
( V_33 & V_54 ) )
V_49 = 1 ;
} else {
F_39 ( ! F_35 ( V_48 , F_9 ( V_52 ) ) ) ;
}
}
F_20 ( & V_34 , V_30 ) ;
if ( V_3 . V_53 && V_49 ) {
F_40 (
L_3 ) ;
F_40 (
L_4 ) ;
}
}
void F_28 ( void )
{
unsigned long V_30 ;
int V_1 ;
if ( ! F_41 ( F_42 ( & V_56 ) ) || ! F_1 ( & V_1 ) )
return;
F_43 ( V_30 ) ;
F_8 ( V_22 , F_9 ( & V_23 ) ) ;
F_44 ( V_30 ) ;
}
static void F_45 ( int V_32 )
{
T_1 V_33 ;
if ( ! F_35 ( V_32 , F_9 ( V_23 ) ) )
return;
F_3 ( F_18 ( V_32 ) , V_33 ) ;
V_33 &= ~ V_35 ;
F_19 ( F_18 ( V_32 ) , V_33 ) ;
F_37 ( V_32 , F_9 ( V_23 ) ) ;
}
void F_46 ( void )
{
unsigned long V_30 ;
int V_48 ;
int V_1 ;
if ( ! F_1 ( & V_1 ) )
return;
F_16 ( & V_34 , V_30 ) ;
for ( V_48 = 0 ; V_48 < V_1 ; V_48 ++ )
F_45 ( V_48 ) ;
F_20 ( & V_34 , V_30 ) ;
}
static void F_47 ( void * V_57 )
{
int V_1 ;
if ( F_1 ( & V_1 ) )
F_34 ( V_1 ) ;
}
void F_48 ( void )
{
int V_1 ;
if ( ! F_1 ( & V_1 ) )
return;
F_49 ( F_47 , NULL , 1 ) ;
}
void F_50 ( void )
{
int V_1 ;
if ( F_1 ( & V_1 ) )
F_34 ( V_1 ) ;
}
void F_51 ( int V_32 )
{
int V_1 ;
unsigned long V_30 ;
if ( ! F_1 ( & V_1 ) )
return;
F_16 ( & V_34 , V_30 ) ;
F_45 ( V_32 ) ;
F_20 ( & V_34 , V_30 ) ;
}
static void F_52 ( void )
{
int V_1 ;
if ( ! F_1 ( & V_1 ) )
return;
V_58 = F_33 ;
F_34 ( V_1 ) ;
F_53 ( V_59 , V_60 | V_61 ) ;
F_28 () ;
}
static void F_54 ( void )
{
T_1 V_33 ;
if ( ! F_5 () )
return;
F_3 ( V_62 , V_33 ) ;
if ( ! ( V_33 & V_63 ) )
F_19 ( V_62 , V_33 | V_63 ) ;
}
static void F_55 ( void )
{
T_1 V_33 ;
if ( ! F_5 () )
return;
F_3 ( V_62 , V_33 ) ;
V_33 &= ~ V_63 ;
F_19 ( V_62 , V_33 ) ;
}
void F_56 ( struct V_64 * V_65 )
{
F_57 ( V_65 ) ;
F_52 () ;
F_54 () ;
}
void F_58 ( struct V_64 * V_65 )
{
F_55 () ;
}
