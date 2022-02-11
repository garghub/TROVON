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
if ( ! F_5 ( V_3 ) ) {
struct V_4 * T_1 V_5 = F_6 ( F_7 () ) ;
F_2 ( F_3 ( F_4 ( L_3 ) ,
V_2 , V_1 ) ) ;
F_8 ( V_6 ) ;
F_9 ( 1 , L_4 ,
V_3 -> V_7 , V_3 -> V_8 ,
T_1 -> V_7 , T_1 -> V_8 ) ;
}
F_10 ( 0 ) ;
F_11 () ;
V_2 = V_1 ;
}
void F_12 ( void )
{
unsigned long V_9 ;
long long V_1 ;
F_13 ( V_9 ) ;
F_14 ( ( V_2 & V_10 ) == 0 ) ;
if ( ( V_2 & V_10 ) ==
V_11 )
V_1 = 0 ;
else
V_1 = V_2 - V_11 ;
F_1 ( V_1 ) ;
F_15 ( V_9 ) ;
}
void F_16 ( void )
{
unsigned long V_9 ;
long long V_1 ;
F_13 ( V_9 ) ;
V_1 = V_2 - 1 ;
F_14 ( V_1 < 0 ) ;
F_1 ( V_1 ) ;
F_15 ( V_9 ) ;
}
static void F_17 ( long long V_12 )
{
if ( V_12 ) {
F_2 ( F_3 ( F_4 ( L_5 ) ,
V_12 , V_2 ) ) ;
return;
}
F_2 ( F_3 ( F_4 ( L_6 ) , V_12 , V_2 ) ) ;
if ( ! F_5 ( V_3 ) ) {
struct V_4 * T_1 V_5 = F_6 ( F_7 () ) ;
F_2 ( F_3 ( F_4 ( L_7 ) ,
V_12 , V_2 ) ) ;
F_8 ( V_6 ) ;
F_9 ( 1 , L_4 ,
V_3 -> V_7 , V_3 -> V_8 ,
T_1 -> V_7 , T_1 -> V_8 ) ;
}
}
void F_18 ( void )
{
unsigned long V_9 ;
long long V_12 ;
F_13 ( V_9 ) ;
V_12 = V_2 ;
F_14 ( V_2 < 0 ) ;
if ( V_2 & V_10 )
V_2 += V_11 ;
else
V_2 = V_13 ;
F_17 ( V_12 ) ;
F_15 ( V_9 ) ;
}
void F_19 ( void )
{
unsigned long V_9 ;
long long V_12 ;
F_13 ( V_9 ) ;
V_12 = V_2 ;
V_2 ++ ;
F_14 ( V_2 == 0 ) ;
F_17 ( V_12 ) ;
F_15 ( V_9 ) ;
}
bool T_2 F_20 ( void )
{
return V_2 ;
}
static int F_21 ( void )
{
return V_2 <= 1 ;
}
static int F_22 ( struct V_14 * V_15 )
{
F_2 ( F_23 ( V_15 ) ) ;
if ( V_15 -> V_16 != NULL &&
V_15 -> V_17 != V_15 -> V_18 ) {
V_15 -> V_17 = V_15 -> V_18 ;
return 1 ;
}
return 0 ;
}
void F_10 ( int V_19 )
{
unsigned long V_9 ;
F_13 ( V_9 ) ;
if ( F_22 ( & V_20 ) +
F_22 ( & V_21 ) )
F_24 ( V_22 ) ;
F_15 ( V_9 ) ;
}
void F_25 ( int V_19 )
{
unsigned long V_9 ;
F_13 ( V_9 ) ;
if ( F_22 ( & V_21 ) )
F_24 ( V_22 ) ;
F_15 ( V_9 ) ;
}
void F_26 ( int V_19 , int V_23 )
{
F_2 ( F_27 () ) ;
if ( V_23 || F_21 () )
F_10 ( V_19 ) ;
else if ( ! F_28 () )
F_25 ( V_19 ) ;
}
static void F_29 ( struct V_14 * V_15 )
{
const char * V_24 = NULL ;
struct V_25 * V_26 , * V_27 ;
unsigned long V_9 ;
F_2 (int cb_count = 0 ) ;
if ( & V_15 -> V_16 == V_15 -> V_17 ) {
F_2 ( F_30 ( V_15 -> V_28 , 0 , 0 , - 1 ) ) ;
F_2 ( F_31 ( V_15 -> V_28 , 0 ,
! ! F_32 ( V_15 -> V_16 ) ,
F_33 () ,
F_5 ( V_3 ) ,
false ) ) ;
return;
}
F_13 ( V_9 ) ;
F_2 ( F_30 ( V_15 -> V_28 , 0 , V_15 -> V_29 , - 1 ) ) ;
V_27 = V_15 -> V_16 ;
V_15 -> V_16 = * V_15 -> V_17 ;
* V_15 -> V_17 = NULL ;
if ( V_15 -> V_18 == V_15 -> V_17 )
V_15 -> V_18 = & V_15 -> V_16 ;
V_15 -> V_17 = & V_15 -> V_16 ;
F_15 ( V_9 ) ;
F_2 ( V_24 = V_15 -> V_28 ) ;
while ( V_27 ) {
V_26 = V_27 -> V_26 ;
F_34 ( V_26 ) ;
F_35 ( V_27 ) ;
F_36 () ;
F_37 ( V_24 , V_27 ) ;
F_38 () ;
V_27 = V_26 ;
F_2 ( V_30 ++ ) ;
}
F_2 ( F_39 ( V_15 , V_30 ) ) ;
F_2 ( F_31 ( V_15 -> V_28 ,
V_30 , 0 , F_33 () ,
F_5 ( V_3 ) ,
false ) ) ;
}
static void F_40 ( struct V_31 * V_32 )
{
F_29 ( & V_20 ) ;
F_29 ( & V_21 ) ;
}
void F_41 ( void )
{
F_42 ( ! F_43 ( & V_33 ) &&
! F_43 ( & V_34 ) &&
! F_43 ( & V_35 ) ,
L_8 ) ;
F_44 () ;
}
static void F_45 ( struct V_25 * V_36 ,
void (* F_46)( struct V_25 * V_37 ) ,
struct V_14 * V_15 )
{
unsigned long V_9 ;
F_47 ( V_36 ) ;
V_36 -> F_46 = F_46 ;
V_36 -> V_26 = NULL ;
F_13 ( V_9 ) ;
* V_15 -> V_18 = V_36 ;
V_15 -> V_18 = & V_36 -> V_26 ;
F_2 ( V_15 -> V_29 ++ ) ;
F_15 ( V_9 ) ;
}
void F_48 ( struct V_25 * V_36 , void (* F_46)( struct V_25 * V_37 ) )
{
F_45 ( V_36 , F_46 , & V_20 ) ;
}
void F_49 ( struct V_25 * V_36 , void (* F_46)( struct V_25 * V_37 ) )
{
F_45 ( V_36 , F_46 , & V_21 ) ;
}
void F_50 ( void )
{
F_51 ( V_22 , F_40 ) ;
}
