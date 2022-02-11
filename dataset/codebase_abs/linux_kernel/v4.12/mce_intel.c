static int F_1 ( int * V_1 )
{
T_1 V_2 ;
if ( V_3 . V_4 || V_3 . V_5 )
return 0 ;
if ( V_6 . V_7 != V_8 )
return 0 ;
if ( ! F_2 ( V_9 ) || F_3 () < 6 )
return 0 ;
F_4 ( V_10 , V_2 ) ;
* V_1 = F_5 ( unsigned , V_11 , V_2 & 0xff ) ;
return ! ! ( V_2 & V_12 ) ;
}
static bool F_6 ( void )
{
T_1 V_13 ;
if ( V_3 . V_14 )
return false ;
F_4 ( V_10 , V_13 ) ;
if ( ( V_13 & ( V_15 | V_16 ) ) !=
( V_15 | V_16 ) )
return false ;
F_4 ( V_17 , V_13 ) ;
if ( ( V_13 & ( V_18 | V_19 ) ) ==
( V_18 | V_19 ) )
return true ;
return false ;
}
bool F_7 ( void )
{
if ( F_8 ( V_20 ) == V_21 )
return false ;
if ( F_9 ( 0 , F_10 ( & V_22 ) ) )
F_11 ( V_23 , V_24 ) ;
else
F_12 ( V_23 ) ;
return true ;
}
void F_13 ( unsigned long V_25 )
{
if ( F_14 ( V_20 , V_25 ) == V_26 )
F_15 ( & V_27 ) ;
F_14 ( V_20 , V_25 ) = V_21 ;
}
static void F_16 ( bool V_28 )
{
unsigned long V_29 , * V_30 ;
int V_31 ;
T_1 V_32 ;
F_17 ( & V_33 , V_29 ) ;
V_30 = F_10 ( V_22 ) ;
F_18 (bank, owned, MAX_NR_BANKS) {
F_4 ( F_19 ( V_31 ) , V_32 ) ;
if ( V_28 )
V_32 |= V_34 ;
else
V_32 &= ~ V_34 ;
F_20 ( F_19 ( V_31 ) , V_32 ) ;
}
F_21 ( & V_33 , V_29 ) ;
}
unsigned long F_22 ( unsigned long V_35 )
{
if ( ( F_23 ( V_23 ) > 0 ) &&
( F_8 ( V_20 ) == V_26 ) ) {
F_24 () ;
return V_36 ;
}
switch ( F_8 ( V_20 ) ) {
case V_26 :
F_25 ( V_20 , V_37 ) ;
if ( ! F_26 ( 1 , & V_27 ) )
F_27 ( L_1 ) ;
case V_37 :
if ( ! F_28 ( & V_27 ) ) {
F_25 ( V_20 , V_21 ) ;
F_16 ( true ) ;
F_29 () ;
}
return V_38 ;
default:
return V_35 ;
}
}
static bool F_30 ( void )
{
unsigned int V_39 = F_8 ( V_40 ) ;
unsigned long V_41 = F_8 ( V_42 ) ;
unsigned long V_43 = V_44 ;
int V_45 ;
if ( F_8 ( V_20 ) != V_21 )
return true ;
if ( F_31 ( V_43 , V_41 + V_36 ) ) {
V_39 ++ ;
} else {
V_39 = 1 ;
F_25 ( V_42 , V_43 ) ;
}
F_25 ( V_40 , V_39 ) ;
if ( V_39 <= V_46 )
return false ;
F_16 ( false ) ;
F_25 ( V_20 , V_26 ) ;
V_45 = F_32 ( 1 , & V_27 ) ;
F_33 ( V_36 ) ;
F_11 ( V_23 , V_24 ) ;
if ( V_45 == 1 )
F_27 ( L_2 ) ;
return true ;
}
static void F_34 ( void )
{
if ( F_30 () )
return;
F_9 ( V_47 , F_10 ( & V_22 ) ) ;
}
static void F_35 ( int V_1 )
{
unsigned long * V_30 = ( void * ) F_10 ( & V_22 ) ;
unsigned long V_29 ;
int V_48 ;
int V_49 = 0 ;
F_17 ( & V_33 , V_29 ) ;
for ( V_48 = 0 ; V_48 < V_1 ; V_48 ++ ) {
T_1 V_32 ;
int V_50 = 0 ;
if ( F_36 ( V_48 , V_30 ) )
continue;
if ( F_36 ( V_48 , V_51 ) )
continue;
F_4 ( F_19 ( V_48 ) , V_32 ) ;
if ( V_32 & V_34 ) {
F_37 ( V_48 , V_30 ) ;
F_38 ( V_48 , F_10 ( V_52 ) ) ;
continue;
}
if ( ! V_3 . V_53 ) {
V_32 &= ~ V_54 ;
V_32 |= V_55 ;
} else if ( ! ( V_32 & V_54 ) ) {
V_50 = 1 ;
V_32 |= V_55 ;
}
V_32 |= V_34 ;
F_20 ( F_19 ( V_48 ) , V_32 ) ;
F_4 ( F_19 ( V_48 ) , V_32 ) ;
if ( V_32 & V_34 ) {
F_39 ( V_48 , V_30 ) ;
F_38 ( V_48 , F_10 ( V_52 ) ) ;
if ( V_3 . V_53 && V_50 &&
( V_32 & V_54 ) )
V_49 = 1 ;
} else {
F_40 ( ! F_36 ( V_48 , F_10 ( V_52 ) ) ) ;
}
}
F_21 ( & V_33 , V_29 ) ;
if ( V_3 . V_53 && V_49 ) {
F_41 (
L_3 ) ;
F_41 (
L_4 ) ;
}
}
void F_29 ( void )
{
unsigned long V_29 ;
int V_1 ;
if ( ! F_42 ( F_43 ( & V_56 ) ) || ! F_1 ( & V_1 ) )
return;
F_44 ( V_29 ) ;
F_9 ( 0 , F_10 ( & V_22 ) ) ;
F_45 ( V_29 ) ;
}
static void F_46 ( int V_31 )
{
T_1 V_32 ;
if ( ! F_36 ( V_31 , F_10 ( V_22 ) ) )
return;
F_4 ( F_19 ( V_31 ) , V_32 ) ;
V_32 &= ~ V_34 ;
F_20 ( F_19 ( V_31 ) , V_32 ) ;
F_38 ( V_31 , F_10 ( V_22 ) ) ;
}
void F_47 ( void )
{
unsigned long V_29 ;
int V_48 ;
int V_1 ;
if ( ! F_1 ( & V_1 ) )
return;
F_17 ( & V_33 , V_29 ) ;
for ( V_48 = 0 ; V_48 < V_1 ; V_48 ++ )
F_46 ( V_48 ) ;
F_21 ( & V_33 , V_29 ) ;
}
static void F_48 ( void * V_57 )
{
int V_1 ;
if ( F_1 ( & V_1 ) )
F_35 ( V_1 ) ;
}
void F_49 ( void )
{
int V_1 ;
if ( ! F_1 ( & V_1 ) )
return;
F_50 ( F_48 , NULL , 1 ) ;
}
void F_51 ( void )
{
int V_1 ;
if ( F_1 ( & V_1 ) )
F_35 ( V_1 ) ;
}
void F_52 ( int V_31 )
{
int V_1 ;
unsigned long V_29 ;
if ( ! F_1 ( & V_1 ) )
return;
F_17 ( & V_33 , V_29 ) ;
F_46 ( V_31 ) ;
F_21 ( & V_33 , V_29 ) ;
}
static void F_53 ( void )
{
int V_1 ;
if ( ! F_1 ( & V_1 ) )
return;
V_58 = F_34 ;
F_35 ( V_1 ) ;
F_54 ( V_59 , V_60 | V_61 ) ;
F_29 () ;
}
static void F_55 ( void )
{
T_1 V_32 ;
if ( ! F_6 () )
return;
F_4 ( V_62 , V_32 ) ;
if ( ! ( V_32 & V_63 ) )
F_20 ( V_62 , V_32 | V_63 ) ;
}
static void F_56 ( void )
{
T_1 V_32 ;
if ( ! F_6 () )
return;
F_4 ( V_62 , V_32 ) ;
V_32 &= ~ V_63 ;
F_20 ( V_62 , V_32 ) ;
}
static void F_57 ( struct V_64 * V_65 )
{
unsigned long long V_32 ;
switch ( V_65 -> V_66 ) {
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
if ( F_58 ( V_74 , & V_32 ) )
return;
if ( ( V_32 & 3UL ) == 1UL ) {
return;
}
if ( ! ( V_32 & 3UL ) ) {
F_59 ( V_74 , V_32 | 2UL ) ;
F_58 ( V_74 , & V_32 ) ;
}
if ( ( V_32 & 3UL ) == 2UL )
F_60 ( V_65 , V_75 ) ;
}
}
void F_61 ( struct V_64 * V_65 )
{
F_62 ( V_65 ) ;
F_53 () ;
F_55 () ;
F_57 ( V_65 ) ;
}
void F_63 ( struct V_64 * V_65 )
{
F_56 () ;
}
