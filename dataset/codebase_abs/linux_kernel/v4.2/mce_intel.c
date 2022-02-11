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
unsigned long F_15 ( unsigned long V_29 )
{
if ( ( F_16 ( V_24 ) > 0 ) &&
( F_7 ( V_20 ) == V_27 ) ) {
F_17 () ;
return V_30 ;
}
switch ( F_7 ( V_20 ) ) {
case V_27 :
F_18 ( V_20 , V_31 ) ;
if ( ! F_19 ( 1 , & V_28 ) )
F_20 ( L_1 ) ;
case V_31 :
if ( ! F_21 ( & V_28 ) ) {
F_18 ( V_20 , V_21 ) ;
F_22 () ;
F_23 () ;
}
return V_32 ;
default:
return V_29 ;
}
}
static void F_24 ( void )
{
unsigned long V_33 , * V_34 ;
int V_35 ;
T_1 V_36 ;
F_25 ( & V_37 , V_33 ) ;
V_34 = F_9 ( V_23 ) ;
F_26 (bank, owned, MAX_NR_BANKS) {
F_3 ( F_27 ( V_35 ) , V_36 ) ;
V_36 &= ~ V_38 ;
F_28 ( F_27 ( V_35 ) , V_36 ) ;
}
F_29 ( & V_37 , V_33 ) ;
}
static bool F_30 ( void )
{
unsigned int V_39 = F_7 ( V_40 ) ;
unsigned long V_41 = F_7 ( V_42 ) ;
unsigned long V_43 = V_44 ;
int V_45 ;
if ( F_7 ( V_20 ) != V_21 )
return true ;
if ( F_31 ( V_43 , V_41 + V_30 ) ) {
V_39 ++ ;
} else {
V_39 = 1 ;
F_18 ( V_42 , V_43 ) ;
}
F_18 ( V_40 , V_39 ) ;
if ( V_39 <= V_46 )
return false ;
F_24 () ;
F_18 ( V_20 , V_27 ) ;
V_45 = F_32 ( 1 , & V_28 ) ;
F_33 ( V_30 ) ;
F_10 ( V_24 , V_25 ) ;
if ( V_45 == 1 )
F_20 ( L_2 ) ;
return true ;
}
static void F_34 ( void )
{
if ( F_30 () )
return;
F_8 ( V_22 , F_9 ( & V_23 ) ) ;
F_17 () ;
}
static void F_35 ( int V_1 )
{
unsigned long * V_34 = ( void * ) F_9 ( & V_23 ) ;
unsigned long V_33 ;
int V_47 ;
int V_48 = 0 ;
F_25 ( & V_37 , V_33 ) ;
for ( V_47 = 0 ; V_47 < V_1 ; V_47 ++ ) {
T_1 V_36 ;
int V_49 = 0 ;
if ( F_36 ( V_47 , V_34 ) )
continue;
if ( F_36 ( V_47 , V_50 ) )
continue;
F_3 ( F_27 ( V_47 ) , V_36 ) ;
if ( V_36 & V_38 ) {
F_37 ( V_47 , V_34 ) ;
F_38 ( V_47 , F_9 ( V_51 ) ) ;
continue;
}
if ( ! V_3 . V_52 ) {
V_36 &= ~ V_53 ;
V_36 |= V_54 ;
} else if ( ! ( V_36 & V_53 ) ) {
V_49 = 1 ;
V_36 |= V_54 ;
}
V_36 |= V_38 ;
F_28 ( F_27 ( V_47 ) , V_36 ) ;
F_3 ( F_27 ( V_47 ) , V_36 ) ;
if ( V_36 & V_38 ) {
F_39 ( V_47 , V_34 ) ;
F_38 ( V_47 , F_9 ( V_51 ) ) ;
if ( V_3 . V_52 && V_49 &&
( V_36 & V_53 ) )
V_48 = 1 ;
} else {
F_40 ( ! F_36 ( V_47 , F_9 ( V_51 ) ) ) ;
}
}
F_29 ( & V_37 , V_33 ) ;
if ( V_3 . V_52 && V_48 ) {
F_41 (
L_3 ) ;
F_41 (
L_4 ) ;
}
}
void F_23 ( void )
{
unsigned long V_33 ;
int V_1 ;
if ( ! F_42 ( F_43 ( & V_55 ) ) || ! F_1 ( & V_1 ) )
return;
F_44 ( V_33 ) ;
F_8 ( V_22 , F_9 ( & V_23 ) ) ;
F_45 ( V_33 ) ;
}
static void F_46 ( int V_35 )
{
T_1 V_36 ;
if ( ! F_36 ( V_35 , F_9 ( V_23 ) ) )
return;
F_3 ( F_27 ( V_35 ) , V_36 ) ;
V_36 &= ~ V_38 ;
F_28 ( F_27 ( V_35 ) , V_36 ) ;
F_38 ( V_35 , F_9 ( V_23 ) ) ;
}
void F_47 ( void )
{
unsigned long V_33 ;
int V_47 ;
int V_1 ;
if ( ! F_1 ( & V_1 ) )
return;
F_25 ( & V_37 , V_33 ) ;
for ( V_47 = 0 ; V_47 < V_1 ; V_47 ++ )
F_46 ( V_47 ) ;
F_29 ( & V_37 , V_33 ) ;
}
static void F_48 ( void * V_56 )
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
void F_22 ( void )
{
int V_1 ;
if ( F_1 ( & V_1 ) )
F_35 ( V_1 ) ;
}
void F_51 ( int V_35 )
{
int V_1 ;
unsigned long V_33 ;
if ( ! F_1 ( & V_1 ) )
return;
F_25 ( & V_37 , V_33 ) ;
F_46 ( V_35 ) ;
F_29 ( & V_37 , V_33 ) ;
}
static void F_52 ( void )
{
int V_1 ;
if ( ! F_1 ( & V_1 ) )
return;
V_57 = F_34 ;
F_35 ( V_1 ) ;
F_53 ( V_58 , V_59 | V_60 ) ;
F_23 () ;
}
void F_54 ( void )
{
T_1 V_36 ;
if ( ! F_5 () )
return;
F_3 ( V_61 , V_36 ) ;
if ( ! ( V_36 & V_62 ) )
F_28 ( V_61 , V_36 | V_62 ) ;
}
void F_55 ( struct V_63 * V_64 )
{
F_56 ( V_64 ) ;
F_52 () ;
F_54 () ;
}
