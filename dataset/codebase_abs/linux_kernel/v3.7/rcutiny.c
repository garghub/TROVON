static void F_1 ( long long V_1 )
{
if ( V_1 ) {
F_2 ( F_3 ( L_1 ,
V_2 , V_1 ) ) ;
V_2 = V_1 ;
return;
}
F_2 ( F_3 ( L_2 , V_2 , V_1 ) ) ;
if ( ! F_4 ( V_3 ) ) {
struct V_4 * V_5 = F_5 ( F_6 () ) ;
F_2 ( F_3 ( L_3 ,
V_2 , V_1 ) ) ;
F_7 ( V_6 ) ;
F_8 ( 1 , L_4 ,
V_3 -> V_7 , V_3 -> V_8 ,
V_5 -> V_7 , V_5 -> V_8 ) ;
}
F_9 ( 0 ) ;
F_10 () ;
V_2 = V_1 ;
}
void F_11 ( void )
{
unsigned long V_9 ;
long long V_1 ;
F_12 ( V_9 ) ;
F_13 ( ( V_2 & V_10 ) == 0 ) ;
if ( ( V_2 & V_10 ) ==
V_11 )
V_1 = 0 ;
else
V_1 = V_2 - V_11 ;
F_1 ( V_1 ) ;
F_14 ( V_9 ) ;
}
void F_15 ( void )
{
unsigned long V_9 ;
long long V_1 ;
F_12 ( V_9 ) ;
V_1 = V_2 - 1 ;
F_13 ( V_1 < 0 ) ;
F_1 ( V_1 ) ;
F_14 ( V_9 ) ;
}
static void F_16 ( long long V_12 )
{
if ( V_12 ) {
F_2 ( F_3 ( L_5 ,
V_12 , V_2 ) ) ;
return;
}
F_2 ( F_3 ( L_6 , V_12 , V_2 ) ) ;
if ( ! F_4 ( V_3 ) ) {
struct V_4 * V_5 = F_5 ( F_6 () ) ;
F_2 ( F_3 ( L_7 ,
V_12 , V_2 ) ) ;
F_7 ( V_6 ) ;
F_8 ( 1 , L_4 ,
V_3 -> V_7 , V_3 -> V_8 ,
V_5 -> V_7 , V_5 -> V_8 ) ;
}
}
void F_17 ( void )
{
unsigned long V_9 ;
long long V_12 ;
F_12 ( V_9 ) ;
V_12 = V_2 ;
F_13 ( V_2 < 0 ) ;
if ( V_2 & V_10 )
V_2 += V_11 ;
else
V_2 = V_13 ;
F_16 ( V_12 ) ;
F_14 ( V_9 ) ;
}
void F_18 ( void )
{
unsigned long V_9 ;
long long V_12 ;
F_12 ( V_9 ) ;
V_12 = V_2 ;
V_2 ++ ;
F_13 ( V_2 == 0 ) ;
F_16 ( V_12 ) ;
F_14 ( V_9 ) ;
}
int F_19 ( void )
{
return ! V_2 ;
}
int F_20 ( void )
{
return V_2 <= 0 ;
}
static int F_21 ( struct V_14 * V_15 )
{
if ( V_15 -> V_16 != NULL &&
V_15 -> V_17 != V_15 -> V_18 ) {
V_15 -> V_17 = V_15 -> V_18 ;
return 1 ;
}
return 0 ;
}
void F_9 ( int V_19 )
{
unsigned long V_9 ;
F_12 ( V_9 ) ;
if ( F_21 ( & V_20 ) +
F_21 ( & V_21 ) )
F_22 () ;
F_14 ( V_9 ) ;
}
void F_23 ( int V_19 )
{
unsigned long V_9 ;
F_12 ( V_9 ) ;
if ( F_21 ( & V_21 ) )
F_22 () ;
F_14 ( V_9 ) ;
}
void F_24 ( int V_19 , int V_22 )
{
if ( V_22 || F_20 () )
F_9 ( V_19 ) ;
else if ( ! F_25 () )
F_23 ( V_19 ) ;
F_26 () ;
}
static void F_27 ( struct V_14 * V_15 )
{
char * V_23 = NULL ;
struct V_24 * V_25 , * V_26 ;
unsigned long V_9 ;
F_2 (int cb_count = 0 ) ;
if ( & V_15 -> V_16 == V_15 -> V_17 ) {
F_2 ( F_28 ( V_15 -> V_27 , 0 , 0 , - 1 ) ) ;
F_2 ( F_29 ( V_15 -> V_27 , 0 ,
F_30 ( V_15 -> V_16 ) ,
F_31 () ,
F_4 ( V_3 ) ,
F_32 () ) ) ;
return;
}
F_12 ( V_9 ) ;
F_2 ( F_28 ( V_15 -> V_27 , 0 , V_15 -> V_28 , - 1 ) ) ;
V_26 = V_15 -> V_16 ;
V_15 -> V_16 = * V_15 -> V_17 ;
* V_15 -> V_17 = NULL ;
if ( V_15 -> V_18 == V_15 -> V_17 )
V_15 -> V_18 = & V_15 -> V_16 ;
F_33 ( V_15 ) ;
V_15 -> V_17 = & V_15 -> V_16 ;
F_14 ( V_9 ) ;
F_2 ( V_23 = V_15 -> V_27 ) ;
while ( V_26 ) {
V_25 = V_26 -> V_25 ;
F_34 ( V_25 ) ;
F_35 ( V_26 ) ;
F_36 () ;
F_37 ( V_23 , V_26 ) ;
F_38 () ;
V_26 = V_25 ;
F_2 ( V_29 ++ ) ;
}
F_2 ( F_39 ( V_15 , V_29 ) ) ;
F_2 ( F_29 ( V_15 -> V_27 , V_29 , 0 , F_31 () ,
F_4 ( V_3 ) ,
F_32 () ) ) ;
}
static void F_40 ( struct V_30 * V_31 )
{
F_27 ( & V_20 ) ;
F_27 ( & V_21 ) ;
F_41 () ;
}
void F_42 ( void )
{
F_43 ( ! F_44 ( & V_32 ) &&
! F_44 ( & V_33 ) &&
! F_44 ( & V_34 ) ,
L_8 ) ;
F_45 () ;
}
static void F_46 ( struct V_24 * V_35 ,
void (* F_47)( struct V_24 * V_36 ) ,
struct V_14 * V_15 )
{
unsigned long V_9 ;
F_48 ( V_35 ) ;
V_35 -> F_47 = F_47 ;
V_35 -> V_25 = NULL ;
F_12 ( V_9 ) ;
* V_15 -> V_18 = V_35 ;
V_15 -> V_18 = & V_35 -> V_25 ;
F_2 ( V_15 -> V_28 ++ ) ;
F_14 ( V_9 ) ;
}
void F_49 ( struct V_24 * V_35 , void (* F_47)( struct V_24 * V_36 ) )
{
F_46 ( V_35 , F_47 , & V_20 ) ;
}
void F_50 ( struct V_24 * V_35 , void (* F_47)( struct V_24 * V_36 ) )
{
F_46 ( V_35 , F_47 , & V_21 ) ;
}
