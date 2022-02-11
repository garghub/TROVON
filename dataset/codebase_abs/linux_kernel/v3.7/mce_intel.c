static int F_1 ( int * V_1 )
{
T_1 V_2 ;
if ( V_3 || V_4 )
return 0 ;
if ( V_5 . V_6 != V_7 )
return 0 ;
if ( ! V_8 || F_2 () < 6 )
return 0 ;
F_3 ( V_9 , V_2 ) ;
* V_1 = F_4 ( unsigned , V_10 , V_2 & 0xff ) ;
return ! ! ( V_2 & V_11 ) ;
}
void F_5 ( void )
{
if ( F_6 ( V_12 ) == V_13 )
return;
F_7 ( V_14 , & F_8 ( V_15 ) ) ;
}
void F_9 ( unsigned long V_16 )
{
if ( F_10 ( V_12 , V_16 ) == V_17 )
F_11 ( & V_18 ) ;
F_10 ( V_12 , V_16 ) = V_13 ;
}
unsigned long F_12 ( unsigned long V_19 )
{
int V_20 ;
if ( V_19 < V_21 )
return V_19 ;
switch ( F_6 ( V_12 ) ) {
case V_17 :
F_13 ( V_12 , V_22 ) ;
V_20 = F_14 ( 1 , & V_18 ) ;
if ( V_20 == 0 )
F_15 ( L_1 ) ;
case V_22 :
if ( ! F_16 ( & V_18 ) ) {
F_13 ( V_12 , V_13 ) ;
F_17 () ;
F_18 () ;
}
return V_21 ;
default:
return V_19 ;
}
}
static bool F_19 ( void )
{
unsigned int V_23 = F_6 ( V_24 ) ;
unsigned long V_25 = F_6 ( V_26 ) ;
unsigned long V_27 = V_28 ;
int V_20 ;
if ( F_6 ( V_12 ) != V_13 )
return true ;
if ( F_20 ( V_27 , V_25 + V_29 ) ) {
V_23 ++ ;
} else {
V_23 = 1 ;
F_13 ( V_26 , V_27 ) ;
}
F_13 ( V_24 , V_23 ) ;
if ( V_23 <= V_30 )
return false ;
F_21 () ;
F_13 ( V_12 , V_17 ) ;
V_20 = F_22 ( 1 , & V_18 ) ;
F_23 ( V_21 ) ;
if ( V_20 == 1 )
F_15 ( L_2 ) ;
return true ;
}
static void F_24 ( void )
{
if ( F_19 () )
return;
F_7 ( V_14 , & F_8 ( V_15 ) ) ;
F_25 () ;
}
static void F_26 ( int V_1 )
{
unsigned long * V_31 = ( void * ) & F_8 ( V_15 ) ;
unsigned long V_32 ;
int V_33 ;
int V_34 = 0 ;
F_27 ( & V_35 , V_32 ) ;
for ( V_33 = 0 ; V_33 < V_1 ; V_33 ++ ) {
T_1 V_36 ;
int V_37 = 0 ;
if ( F_28 ( V_33 , V_31 ) )
continue;
F_3 ( F_29 ( V_33 ) , V_36 ) ;
if ( V_36 & V_38 ) {
F_30 ( V_33 , V_31 ) ;
F_31 ( V_33 , F_8 ( V_39 ) ) ;
continue;
}
if ( ! V_40 ) {
V_36 &= ~ V_41 ;
V_36 |= V_42 ;
} else if ( ! ( V_36 & V_41 ) ) {
V_37 = 1 ;
V_36 |= V_42 ;
}
V_36 |= V_38 ;
F_32 ( F_29 ( V_33 ) , V_36 ) ;
F_3 ( F_29 ( V_33 ) , V_36 ) ;
if ( V_36 & V_38 ) {
F_33 ( V_33 , V_31 ) ;
F_31 ( V_33 , F_8 ( V_39 ) ) ;
if ( V_40 && V_37 &&
( V_36 & V_41 ) )
V_34 = 1 ;
} else {
F_34 ( ! F_28 ( V_33 , F_8 ( V_39 ) ) ) ;
}
}
F_35 ( & V_35 , V_32 ) ;
if ( V_40 && V_34 ) {
F_36 (
L_3 ) ;
F_36 (
L_4 ) ;
}
}
void F_18 ( void )
{
unsigned long V_32 ;
int V_1 ;
if ( ! F_37 ( F_38 ( & V_43 ) ) || ! F_1 ( & V_1 ) )
return;
F_39 ( V_32 ) ;
F_7 ( V_14 , & F_8 ( V_15 ) ) ;
F_40 ( V_32 ) ;
}
void F_21 ( void )
{
unsigned long V_32 ;
int V_33 ;
int V_1 ;
T_1 V_36 ;
if ( ! F_1 ( & V_1 ) )
return;
F_27 ( & V_35 , V_32 ) ;
for ( V_33 = 0 ; V_33 < V_1 ; V_33 ++ ) {
if ( ! F_28 ( V_33 , F_8 ( V_15 ) ) )
continue;
F_3 ( F_29 ( V_33 ) , V_36 ) ;
V_36 &= ~ V_38 ;
F_32 ( F_29 ( V_33 ) , V_36 ) ;
F_31 ( V_33 , F_8 ( V_15 ) ) ;
}
F_35 ( & V_35 , V_32 ) ;
}
static long F_41 ( void * V_44 )
{
int V_1 ;
if ( F_1 ( & V_1 ) )
F_26 ( V_1 ) ;
return 0 ;
}
void F_42 ( int V_45 )
{
int V_16 , V_1 ;
if ( ! F_1 ( & V_1 ) )
return;
F_43 (cpu) {
if ( V_16 == V_45 )
continue;
if ( V_16 == F_44 () ) {
F_41 ( NULL ) ;
continue;
}
F_45 ( V_16 , F_41 , NULL ) ;
}
}
void F_17 ( void )
{
int V_1 ;
if ( F_1 ( & V_1 ) )
F_26 ( V_1 ) ;
}
static void F_46 ( void )
{
int V_1 ;
if ( ! F_1 ( & V_1 ) )
return;
V_46 = F_24 ;
F_26 ( V_1 ) ;
F_47 ( V_47 , V_48 | V_49 ) ;
F_18 () ;
}
void F_48 ( struct V_50 * V_51 )
{
F_49 ( V_51 ) ;
F_46 () ;
}
