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
bool F_5 ( void )
{
if ( F_6 ( V_13 ) == V_14 )
return false ;
if ( F_7 ( V_15 , F_8 ( & V_16 ) ) )
F_9 ( V_17 , V_18 ) ;
else
F_10 ( V_17 ) ;
return true ;
}
void F_11 ( unsigned long V_19 )
{
if ( F_12 ( V_13 , V_19 ) == V_20 )
F_13 ( & V_21 ) ;
F_12 ( V_13 , V_19 ) = V_14 ;
}
unsigned long F_14 ( unsigned long V_22 )
{
if ( ( F_15 ( V_17 ) > 0 ) &&
( F_6 ( V_13 ) == V_20 ) ) {
F_16 () ;
return V_23 ;
}
switch ( F_6 ( V_13 ) ) {
case V_20 :
F_17 ( V_13 , V_24 ) ;
if ( ! F_18 ( 1 , & V_21 ) )
F_19 ( L_1 ) ;
case V_24 :
if ( ! F_20 ( & V_21 ) ) {
F_17 ( V_13 , V_14 ) ;
F_21 () ;
F_22 () ;
}
return V_25 ;
default:
return V_22 ;
}
}
static void F_23 ( void )
{
unsigned long V_26 , * V_27 ;
int V_28 ;
T_1 V_29 ;
F_24 ( & V_30 , V_26 ) ;
V_27 = F_8 ( V_16 ) ;
F_25 (bank, owned, MAX_NR_BANKS) {
F_3 ( F_26 ( V_28 ) , V_29 ) ;
V_29 &= ~ V_31 ;
F_27 ( F_26 ( V_28 ) , V_29 ) ;
}
F_28 ( & V_30 , V_26 ) ;
}
static bool F_29 ( void )
{
unsigned int V_32 = F_6 ( V_33 ) ;
unsigned long V_34 = F_6 ( V_35 ) ;
unsigned long V_36 = V_37 ;
int V_38 ;
if ( F_6 ( V_13 ) != V_14 )
return true ;
if ( F_30 ( V_36 , V_34 + V_23 ) ) {
V_32 ++ ;
} else {
V_32 = 1 ;
F_17 ( V_35 , V_36 ) ;
}
F_17 ( V_33 , V_32 ) ;
if ( V_32 <= V_39 )
return false ;
F_23 () ;
F_17 ( V_13 , V_20 ) ;
V_38 = F_31 ( 1 , & V_21 ) ;
F_32 ( V_23 ) ;
F_9 ( V_17 , V_18 ) ;
if ( V_38 == 1 )
F_19 ( L_2 ) ;
return true ;
}
static void F_33 ( void )
{
if ( F_29 () )
return;
F_7 ( V_15 , F_8 ( & V_16 ) ) ;
F_16 () ;
}
static void F_34 ( int V_1 )
{
unsigned long * V_27 = ( void * ) F_8 ( & V_16 ) ;
unsigned long V_26 ;
int V_40 ;
int V_41 = 0 ;
F_24 ( & V_30 , V_26 ) ;
for ( V_40 = 0 ; V_40 < V_1 ; V_40 ++ ) {
T_1 V_29 ;
int V_42 = 0 ;
if ( F_35 ( V_40 , V_27 ) )
continue;
if ( F_35 ( V_40 , V_43 ) )
continue;
F_3 ( F_26 ( V_40 ) , V_29 ) ;
if ( V_29 & V_31 ) {
F_36 ( V_40 , V_27 ) ;
F_37 ( V_40 , F_8 ( V_44 ) ) ;
continue;
}
if ( ! V_3 . V_45 ) {
V_29 &= ~ V_46 ;
V_29 |= V_47 ;
} else if ( ! ( V_29 & V_46 ) ) {
V_42 = 1 ;
V_29 |= V_47 ;
}
V_29 |= V_31 ;
F_27 ( F_26 ( V_40 ) , V_29 ) ;
F_3 ( F_26 ( V_40 ) , V_29 ) ;
if ( V_29 & V_31 ) {
F_38 ( V_40 , V_27 ) ;
F_37 ( V_40 , F_8 ( V_44 ) ) ;
if ( V_3 . V_45 && V_42 &&
( V_29 & V_46 ) )
V_41 = 1 ;
} else {
F_39 ( ! F_35 ( V_40 , F_8 ( V_44 ) ) ) ;
}
}
F_28 ( & V_30 , V_26 ) ;
if ( V_3 . V_45 && V_41 ) {
F_40 (
L_3 ) ;
F_40 (
L_4 ) ;
}
}
void F_22 ( void )
{
unsigned long V_26 ;
int V_1 ;
if ( ! F_41 ( F_42 ( & V_48 ) ) || ! F_1 ( & V_1 ) )
return;
F_43 ( V_26 ) ;
F_7 ( V_15 , F_8 ( & V_16 ) ) ;
F_44 ( V_26 ) ;
}
static void F_45 ( int V_28 )
{
T_1 V_29 ;
if ( ! F_35 ( V_28 , F_8 ( V_16 ) ) )
return;
F_3 ( F_26 ( V_28 ) , V_29 ) ;
V_29 &= ~ V_31 ;
F_27 ( F_26 ( V_28 ) , V_29 ) ;
F_37 ( V_28 , F_8 ( V_16 ) ) ;
}
void F_46 ( void )
{
unsigned long V_26 ;
int V_40 ;
int V_1 ;
if ( ! F_1 ( & V_1 ) )
return;
F_24 ( & V_30 , V_26 ) ;
for ( V_40 = 0 ; V_40 < V_1 ; V_40 ++ )
F_45 ( V_40 ) ;
F_28 ( & V_30 , V_26 ) ;
}
static void F_47 ( void * V_49 )
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
void F_21 ( void )
{
int V_1 ;
if ( F_1 ( & V_1 ) )
F_34 ( V_1 ) ;
}
void F_50 ( int V_28 )
{
int V_1 ;
unsigned long V_26 ;
if ( ! F_1 ( & V_1 ) )
return;
F_24 ( & V_30 , V_26 ) ;
F_45 ( V_28 ) ;
F_28 ( & V_30 , V_26 ) ;
}
static void F_51 ( void )
{
int V_1 ;
if ( ! F_1 ( & V_1 ) )
return;
V_50 = F_33 ;
F_34 ( V_1 ) ;
F_52 ( V_51 , V_52 | V_53 ) ;
F_22 () ;
}
void F_53 ( struct V_54 * V_55 )
{
F_54 ( V_55 ) ;
F_51 () ;
}
