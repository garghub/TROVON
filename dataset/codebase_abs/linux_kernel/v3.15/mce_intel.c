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
static void F_19 ( void )
{
unsigned long V_24 , * V_25 ;
int V_26 ;
T_1 V_27 ;
F_20 ( & V_28 , V_24 ) ;
V_25 = F_8 ( V_16 ) ;
F_21 (bank, owned, MAX_NR_BANKS) {
F_3 ( F_22 ( V_26 ) , V_27 ) ;
V_27 &= ~ V_29 ;
F_23 ( F_22 ( V_26 ) , V_27 ) ;
}
F_24 ( & V_28 , V_24 ) ;
}
static bool F_25 ( void )
{
unsigned int V_30 = F_6 ( V_31 ) ;
unsigned long V_32 = F_6 ( V_33 ) ;
unsigned long V_34 = V_35 ;
int V_21 ;
if ( F_6 ( V_13 ) != V_14 )
return true ;
if ( F_26 ( V_34 , V_32 + V_36 ) ) {
V_30 ++ ;
} else {
V_30 = 1 ;
F_13 ( V_33 , V_34 ) ;
}
F_13 ( V_31 , V_30 ) ;
if ( V_30 <= V_37 )
return false ;
F_19 () ;
F_13 ( V_13 , V_18 ) ;
V_21 = F_27 ( 1 , & V_19 ) ;
F_28 ( V_22 ) ;
if ( V_21 == 1 )
F_15 ( L_2 ) ;
return true ;
}
static void F_29 ( void )
{
if ( F_25 () )
return;
F_7 ( V_15 , & F_8 ( V_16 ) ) ;
F_30 () ;
}
static void F_31 ( int V_1 )
{
unsigned long * V_25 = ( void * ) & F_8 ( V_16 ) ;
unsigned long V_24 ;
int V_38 ;
int V_39 = 0 ;
F_20 ( & V_28 , V_24 ) ;
for ( V_38 = 0 ; V_38 < V_1 ; V_38 ++ ) {
T_1 V_27 ;
int V_40 = 0 ;
if ( F_32 ( V_38 , V_25 ) )
continue;
if ( F_32 ( V_38 , V_41 ) )
continue;
F_3 ( F_22 ( V_38 ) , V_27 ) ;
if ( V_27 & V_29 ) {
F_33 ( V_38 , V_25 ) ;
F_34 ( V_38 , F_8 ( V_42 ) ) ;
continue;
}
if ( ! V_3 . V_43 ) {
V_27 &= ~ V_44 ;
V_27 |= V_45 ;
} else if ( ! ( V_27 & V_44 ) ) {
V_40 = 1 ;
V_27 |= V_45 ;
}
V_27 |= V_29 ;
F_23 ( F_22 ( V_38 ) , V_27 ) ;
F_3 ( F_22 ( V_38 ) , V_27 ) ;
if ( V_27 & V_29 ) {
F_35 ( V_38 , V_25 ) ;
F_34 ( V_38 , F_8 ( V_42 ) ) ;
if ( V_3 . V_43 && V_40 &&
( V_27 & V_44 ) )
V_39 = 1 ;
} else {
F_36 ( ! F_32 ( V_38 , F_8 ( V_42 ) ) ) ;
}
}
F_24 ( & V_28 , V_24 ) ;
if ( V_3 . V_43 && V_39 ) {
F_37 (
L_3 ) ;
F_37 (
L_4 ) ;
}
}
void F_18 ( void )
{
unsigned long V_24 ;
int V_1 ;
if ( ! F_38 ( F_39 ( & V_46 ) ) || ! F_1 ( & V_1 ) )
return;
F_40 ( V_24 ) ;
F_7 ( V_15 , & F_8 ( V_16 ) ) ;
F_41 ( V_24 ) ;
}
static void F_42 ( int V_26 )
{
T_1 V_27 ;
if ( ! F_32 ( V_26 , F_8 ( V_16 ) ) )
return;
F_3 ( F_22 ( V_26 ) , V_27 ) ;
V_27 &= ~ V_29 ;
F_23 ( F_22 ( V_26 ) , V_27 ) ;
F_34 ( V_26 , F_8 ( V_16 ) ) ;
}
void F_43 ( void )
{
unsigned long V_24 ;
int V_38 ;
int V_1 ;
if ( ! F_1 ( & V_1 ) )
return;
F_20 ( & V_28 , V_24 ) ;
for ( V_38 = 0 ; V_38 < V_1 ; V_38 ++ )
F_42 ( V_38 ) ;
F_24 ( & V_28 , V_24 ) ;
}
static void F_44 ( void * V_47 )
{
int V_1 ;
if ( F_1 ( & V_1 ) )
F_31 ( V_1 ) ;
}
void F_45 ( void )
{
int V_1 ;
if ( ! F_1 ( & V_1 ) )
return;
F_46 ( F_44 , NULL , 1 ) ;
}
void F_17 ( void )
{
int V_1 ;
if ( F_1 ( & V_1 ) )
F_31 ( V_1 ) ;
}
void F_47 ( int V_26 )
{
int V_1 ;
unsigned long V_24 ;
if ( ! F_1 ( & V_1 ) )
return;
F_20 ( & V_28 , V_24 ) ;
F_42 ( V_26 ) ;
F_24 ( & V_28 , V_24 ) ;
}
static void F_48 ( void )
{
int V_1 ;
if ( ! F_1 ( & V_1 ) )
return;
V_48 = F_29 ;
F_31 ( V_1 ) ;
F_49 ( V_49 , V_50 | V_51 ) ;
F_18 () ;
}
void F_50 ( struct V_52 * V_53 )
{
F_51 ( V_53 ) ;
F_48 () ;
}
