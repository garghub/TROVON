static void F_1 ( long long V_1 )
{
if ( V_1 ) {
F_2 ( F_3 ( F_4 ( L_1 ) ,
V_2 , V_1 ) ) ;
V_2 = V_1 ;
return;
}
F_2 ( F_3 ( F_4 ( L_2 ) ,
V_2 , V_1 ) ) ;
if ( F_5 ( V_3 ) && ! F_6 ( V_4 ) ) {
struct V_5 * T_1 V_6 = F_7 ( F_8 () ) ;
F_2 ( F_3 ( F_4 ( L_3 ) ,
V_2 , V_1 ) ) ;
F_9 ( V_7 ) ;
F_10 ( 1 , L_4 ,
V_4 -> V_8 , V_4 -> V_9 ,
T_1 -> V_8 , T_1 -> V_9 ) ;
}
F_11 () ;
F_12 () ;
V_2 = V_1 ;
}
void F_13 ( void )
{
unsigned long V_10 ;
long long V_1 ;
F_14 ( V_10 ) ;
F_15 ( ( V_2 & V_11 ) == 0 ) ;
if ( ( V_2 & V_11 ) ==
V_12 )
V_1 = 0 ;
else
V_1 = V_2 - V_12 ;
F_1 ( V_1 ) ;
F_16 ( V_10 ) ;
}
void F_17 ( void )
{
unsigned long V_10 ;
long long V_1 ;
F_14 ( V_10 ) ;
V_1 = V_2 - 1 ;
F_15 ( V_1 < 0 ) ;
F_1 ( V_1 ) ;
F_16 ( V_10 ) ;
}
static void F_18 ( long long V_13 )
{
if ( V_13 ) {
F_2 ( F_3 ( F_4 ( L_5 ) ,
V_13 , V_2 ) ) ;
return;
}
F_2 ( F_3 ( F_4 ( L_6 ) , V_13 , V_2 ) ) ;
if ( F_5 ( V_3 ) && ! F_6 ( V_4 ) ) {
struct V_5 * T_1 V_6 = F_7 ( F_8 () ) ;
F_2 ( F_3 ( F_4 ( L_7 ) ,
V_13 , V_2 ) ) ;
F_9 ( V_7 ) ;
F_10 ( 1 , L_4 ,
V_4 -> V_8 , V_4 -> V_9 ,
T_1 -> V_8 , T_1 -> V_9 ) ;
}
}
void F_19 ( void )
{
unsigned long V_10 ;
long long V_13 ;
F_14 ( V_10 ) ;
V_13 = V_2 ;
F_15 ( V_2 < 0 ) ;
if ( V_2 & V_11 )
V_2 += V_12 ;
else
V_2 = V_14 ;
F_18 ( V_13 ) ;
F_16 ( V_10 ) ;
}
void F_20 ( void )
{
unsigned long V_10 ;
long long V_13 ;
F_14 ( V_10 ) ;
V_13 = V_2 ;
V_2 ++ ;
F_15 ( V_2 == 0 ) ;
F_18 ( V_13 ) ;
F_16 ( V_10 ) ;
}
bool T_2 F_21 ( void )
{
return V_2 ;
}
static int F_22 ( void )
{
return V_2 <= 1 ;
}
static int F_23 ( struct V_15 * V_16 )
{
F_2 ( F_24 ( V_16 ) ) ;
if ( V_16 -> V_17 != NULL &&
V_16 -> V_18 != V_16 -> V_19 ) {
V_16 -> V_18 = V_16 -> V_19 ;
return 1 ;
}
return 0 ;
}
void F_11 ( void )
{
unsigned long V_10 ;
F_14 ( V_10 ) ;
if ( F_23 ( & V_20 ) +
F_23 ( & V_21 ) )
F_25 ( V_22 ) ;
F_16 ( V_10 ) ;
}
void F_26 ( void )
{
unsigned long V_10 ;
F_14 ( V_10 ) ;
if ( F_23 ( & V_21 ) )
F_25 ( V_22 ) ;
F_16 ( V_10 ) ;
}
void F_27 ( int V_23 , int V_24 )
{
F_2 ( F_28 () ) ;
if ( V_24 || F_22 () )
F_11 () ;
else if ( ! F_29 () )
F_26 () ;
if ( V_24 )
F_30 ( V_4 ) ;
}
static void F_31 ( struct V_15 * V_16 )
{
const char * V_25 = NULL ;
struct V_26 * V_27 , * V_28 ;
unsigned long V_10 ;
F_2 (int cb_count = 0 ) ;
if ( & V_16 -> V_17 == V_16 -> V_18 ) {
F_2 ( F_32 ( V_16 -> V_29 , 0 , 0 , - 1 ) ) ;
F_2 ( F_33 ( V_16 -> V_29 , 0 ,
! ! F_34 ( V_16 -> V_17 ) ,
F_35 () ,
F_6 ( V_4 ) ,
false ) ) ;
return;
}
F_14 ( V_10 ) ;
F_2 ( F_32 ( V_16 -> V_29 , 0 , V_16 -> V_30 , - 1 ) ) ;
V_28 = V_16 -> V_17 ;
V_16 -> V_17 = * V_16 -> V_18 ;
* V_16 -> V_18 = NULL ;
if ( V_16 -> V_19 == V_16 -> V_18 )
V_16 -> V_19 = & V_16 -> V_17 ;
V_16 -> V_18 = & V_16 -> V_17 ;
F_16 ( V_10 ) ;
F_2 ( V_25 = V_16 -> V_29 ) ;
while ( V_28 ) {
V_27 = V_28 -> V_27 ;
F_36 ( V_27 ) ;
F_37 ( V_28 ) ;
F_38 () ;
F_39 ( V_25 , V_28 ) ;
F_40 () ;
V_28 = V_27 ;
F_2 ( V_31 ++ ) ;
}
F_2 ( F_41 ( V_16 , V_31 ) ) ;
F_2 ( F_33 ( V_16 -> V_29 ,
V_31 , 0 , F_35 () ,
F_6 ( V_4 ) ,
false ) ) ;
}
static void F_42 ( struct V_32 * V_33 )
{
F_31 ( & V_20 ) ;
F_31 ( & V_21 ) ;
}
void F_43 ( void )
{
F_44 ( ! F_45 ( & V_34 ) &&
! F_45 ( & V_35 ) &&
! F_45 ( & V_36 ) ,
L_8 ) ;
F_46 () ;
}
static void F_47 ( struct V_26 * V_37 ,
void (* F_48)( struct V_26 * V_38 ) ,
struct V_15 * V_16 )
{
unsigned long V_10 ;
F_49 ( V_37 ) ;
V_37 -> F_48 = F_48 ;
V_37 -> V_27 = NULL ;
F_14 ( V_10 ) ;
* V_16 -> V_19 = V_37 ;
V_16 -> V_19 = & V_37 -> V_27 ;
F_2 ( V_16 -> V_30 ++ ) ;
F_16 ( V_10 ) ;
}
void F_50 ( struct V_26 * V_37 , void (* F_48)( struct V_26 * V_38 ) )
{
F_47 ( V_37 , F_48 , & V_20 ) ;
}
void F_51 ( struct V_26 * V_37 , void (* F_48)( struct V_26 * V_38 ) )
{
F_47 ( V_37 , F_48 , & V_21 ) ;
}
void F_52 ( void )
{
F_53 ( V_22 , F_42 ) ;
}
