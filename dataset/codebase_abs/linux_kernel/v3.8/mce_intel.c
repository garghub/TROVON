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
void F_5 ( void )
{
if ( F_6 ( V_13 ) == V_14 )
return;
F_7 ( V_15 , & F_8 ( V_16 ) ) ;
}
void F_9 ( unsigned long V_17 )
{
if ( F_10 ( V_13 , V_17 ) == V_18 )
F_11 ( & V_19 ) ;
F_10 ( V_13 , V_17 ) = V_14 ;
}
unsigned long F_12 ( unsigned long V_20 )
{
int V_21 ;
if ( V_20 < V_22 )
return V_20 ;
switch ( F_6 ( V_13 ) ) {
case V_18 :
F_13 ( V_13 , V_23 ) ;
V_21 = F_14 ( 1 , & V_19 ) ;
if ( V_21 == 0 )
F_15 ( L_1 ) ;
case V_23 :
if ( ! F_16 ( & V_19 ) ) {
F_13 ( V_13 , V_14 ) ;
F_17 () ;
F_18 () ;
}
return V_22 ;
default:
return V_20 ;
}
}
static bool F_19 ( void )
{
unsigned int V_24 = F_6 ( V_25 ) ;
unsigned long V_26 = F_6 ( V_27 ) ;
unsigned long V_28 = V_29 ;
int V_21 ;
if ( F_6 ( V_13 ) != V_14 )
return true ;
if ( F_20 ( V_28 , V_26 + V_30 ) ) {
V_24 ++ ;
} else {
V_24 = 1 ;
F_13 ( V_27 , V_28 ) ;
}
F_13 ( V_25 , V_24 ) ;
if ( V_24 <= V_31 )
return false ;
F_21 () ;
F_13 ( V_13 , V_18 ) ;
V_21 = F_22 ( 1 , & V_19 ) ;
F_23 ( V_22 ) ;
if ( V_21 == 1 )
F_15 ( L_2 ) ;
return true ;
}
static void F_24 ( void )
{
if ( F_19 () )
return;
F_7 ( V_15 , & F_8 ( V_16 ) ) ;
F_25 () ;
}
static void F_26 ( int V_1 )
{
unsigned long * V_32 = ( void * ) & F_8 ( V_16 ) ;
unsigned long V_33 ;
int V_34 ;
int V_35 = 0 ;
F_27 ( & V_36 , V_33 ) ;
for ( V_34 = 0 ; V_34 < V_1 ; V_34 ++ ) {
T_1 V_37 ;
int V_38 = 0 ;
if ( F_28 ( V_34 , V_32 ) )
continue;
F_3 ( F_29 ( V_34 ) , V_37 ) ;
if ( V_37 & V_39 ) {
F_30 ( V_34 , V_32 ) ;
F_31 ( V_34 , F_8 ( V_40 ) ) ;
continue;
}
if ( ! V_3 . V_41 ) {
V_37 &= ~ V_42 ;
V_37 |= V_43 ;
} else if ( ! ( V_37 & V_42 ) ) {
V_38 = 1 ;
V_37 |= V_43 ;
}
V_37 |= V_39 ;
F_32 ( F_29 ( V_34 ) , V_37 ) ;
F_3 ( F_29 ( V_34 ) , V_37 ) ;
if ( V_37 & V_39 ) {
F_33 ( V_34 , V_32 ) ;
F_31 ( V_34 , F_8 ( V_40 ) ) ;
if ( V_3 . V_41 && V_38 &&
( V_37 & V_42 ) )
V_35 = 1 ;
} else {
F_34 ( ! F_28 ( V_34 , F_8 ( V_40 ) ) ) ;
}
}
F_35 ( & V_36 , V_33 ) ;
if ( V_3 . V_41 && V_35 ) {
F_36 (
L_3 ) ;
F_36 (
L_4 ) ;
}
}
void F_18 ( void )
{
unsigned long V_33 ;
int V_1 ;
if ( ! F_37 ( F_38 ( & V_44 ) ) || ! F_1 ( & V_1 ) )
return;
F_39 ( V_33 ) ;
F_7 ( V_15 , & F_8 ( V_16 ) ) ;
F_40 ( V_33 ) ;
}
void F_21 ( void )
{
unsigned long V_33 ;
int V_34 ;
int V_1 ;
T_1 V_37 ;
if ( ! F_1 ( & V_1 ) )
return;
F_27 ( & V_36 , V_33 ) ;
for ( V_34 = 0 ; V_34 < V_1 ; V_34 ++ ) {
if ( ! F_28 ( V_34 , F_8 ( V_16 ) ) )
continue;
F_3 ( F_29 ( V_34 ) , V_37 ) ;
V_37 &= ~ V_39 ;
F_32 ( F_29 ( V_34 ) , V_37 ) ;
F_31 ( V_34 , F_8 ( V_16 ) ) ;
}
F_35 ( & V_36 , V_33 ) ;
}
static long F_41 ( void * V_45 )
{
int V_1 ;
if ( F_1 ( & V_1 ) )
F_26 ( V_1 ) ;
return 0 ;
}
void F_42 ( int V_46 )
{
int V_17 , V_1 ;
if ( ! F_1 ( & V_1 ) )
return;
F_43 (cpu) {
if ( V_17 == V_46 )
continue;
if ( V_17 == F_44 () ) {
F_41 ( NULL ) ;
continue;
}
F_45 ( V_17 , F_41 , NULL ) ;
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
V_47 = F_24 ;
F_26 ( V_1 ) ;
F_47 ( V_48 , V_49 | V_50 ) ;
F_18 () ;
}
void F_48 ( struct V_51 * V_52 )
{
F_49 ( V_52 ) ;
F_46 () ;
}
