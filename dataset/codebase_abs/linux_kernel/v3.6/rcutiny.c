static void F_1 ( long long V_1 )
{
if ( V_2 ) {
F_2 ( F_3 ( L_1 ,
V_1 , V_2 ) ) ;
return;
}
F_2 ( F_3 ( L_2 , V_1 , V_2 ) ) ;
if ( ! F_4 ( V_3 ) ) {
struct V_4 * V_5 = F_5 ( F_6 () ) ;
F_2 ( F_3 ( L_3 ,
V_1 , V_2 ) ) ;
F_7 ( V_6 ) ;
F_8 ( 1 , L_4 ,
V_3 -> V_7 , V_3 -> V_8 ,
V_5 -> V_7 , V_5 -> V_8 ) ;
}
F_9 ( 0 ) ;
}
void F_10 ( void )
{
unsigned long V_9 ;
long long V_1 ;
F_11 ( V_9 ) ;
V_1 = V_2 ;
F_12 ( ( V_2 & V_10 ) == 0 ) ;
if ( ( V_2 & V_10 ) ==
V_11 )
V_2 = 0 ;
else
V_2 -= V_11 ;
F_1 ( V_1 ) ;
F_13 ( V_9 ) ;
}
void F_14 ( void )
{
unsigned long V_9 ;
long long V_1 ;
F_11 ( V_9 ) ;
V_1 = V_2 ;
V_2 -- ;
F_12 ( V_2 < 0 ) ;
F_1 ( V_1 ) ;
F_13 ( V_9 ) ;
}
static void F_15 ( long long V_1 )
{
if ( V_1 ) {
F_2 ( F_3 ( L_5 ,
V_1 , V_2 ) ) ;
return;
}
F_2 ( F_3 ( L_6 , V_1 , V_2 ) ) ;
if ( ! F_4 ( V_3 ) ) {
struct V_4 * V_5 = F_5 ( F_6 () ) ;
F_2 ( F_3 ( L_7 ,
V_1 , V_2 ) ) ;
F_7 ( V_6 ) ;
F_8 ( 1 , L_4 ,
V_3 -> V_7 , V_3 -> V_8 ,
V_5 -> V_7 , V_5 -> V_8 ) ;
}
}
void F_16 ( void )
{
unsigned long V_9 ;
long long V_1 ;
F_11 ( V_9 ) ;
V_1 = V_2 ;
F_12 ( V_2 < 0 ) ;
if ( V_2 & V_10 )
V_2 += V_11 ;
else
V_2 = V_12 ;
F_15 ( V_1 ) ;
F_13 ( V_9 ) ;
}
void F_17 ( void )
{
unsigned long V_9 ;
long long V_1 ;
F_11 ( V_9 ) ;
V_1 = V_2 ;
V_2 ++ ;
F_12 ( V_2 == 0 ) ;
F_15 ( V_1 ) ;
F_13 ( V_9 ) ;
}
int F_18 ( void )
{
return ! V_2 ;
}
int F_19 ( void )
{
return V_2 <= 0 ;
}
static int F_20 ( struct V_13 * V_14 )
{
if ( V_14 -> V_15 != NULL &&
V_14 -> V_16 != V_14 -> V_17 ) {
V_14 -> V_16 = V_14 -> V_17 ;
return 1 ;
}
return 0 ;
}
void F_9 ( int V_18 )
{
unsigned long V_9 ;
F_11 ( V_9 ) ;
if ( F_20 ( & V_19 ) +
F_20 ( & V_20 ) )
F_21 () ;
F_13 ( V_9 ) ;
}
void F_22 ( int V_18 )
{
unsigned long V_9 ;
F_11 ( V_9 ) ;
if ( F_20 ( & V_20 ) )
F_21 () ;
F_13 ( V_9 ) ;
}
void F_23 ( int V_18 , int V_21 )
{
if ( V_21 || F_19 () )
F_9 ( V_18 ) ;
else if ( ! F_24 () )
F_22 ( V_18 ) ;
F_25 () ;
}
static void F_26 ( struct V_13 * V_14 )
{
char * V_22 = NULL ;
struct V_23 * V_24 , * V_25 ;
unsigned long V_9 ;
F_2 (int cb_count = 0 ) ;
if ( & V_14 -> V_15 == V_14 -> V_16 ) {
F_2 ( F_27 ( V_14 -> V_26 , 0 , 0 , - 1 ) ) ;
F_2 ( F_28 ( V_14 -> V_26 , 0 ,
F_29 ( V_14 -> V_15 ) ,
F_30 () ,
F_4 ( V_3 ) ,
F_31 () ) ) ;
return;
}
F_11 ( V_9 ) ;
F_2 ( F_27 ( V_14 -> V_26 , 0 , V_14 -> V_27 , - 1 ) ) ;
V_25 = V_14 -> V_15 ;
V_14 -> V_15 = * V_14 -> V_16 ;
* V_14 -> V_16 = NULL ;
if ( V_14 -> V_17 == V_14 -> V_16 )
V_14 -> V_17 = & V_14 -> V_15 ;
F_32 ( V_14 ) ;
V_14 -> V_16 = & V_14 -> V_15 ;
F_13 ( V_9 ) ;
F_2 ( V_22 = V_14 -> V_26 ) ;
while ( V_25 ) {
V_24 = V_25 -> V_24 ;
F_33 ( V_24 ) ;
F_34 ( V_25 ) ;
F_35 () ;
F_36 ( V_22 , V_25 ) ;
F_37 () ;
V_25 = V_24 ;
F_2 ( V_28 ++ ) ;
}
F_2 ( F_38 ( V_14 , V_28 ) ) ;
F_2 ( F_28 ( V_14 -> V_26 , V_28 , 0 , F_30 () ,
F_4 ( V_3 ) ,
F_31 () ) ) ;
}
static void F_39 ( struct V_29 * V_30 )
{
F_26 ( & V_19 ) ;
F_26 ( & V_20 ) ;
F_40 () ;
}
void F_41 ( void )
{
F_42 ( ! F_43 ( & V_31 ) &&
! F_43 ( & V_32 ) &&
! F_43 ( & V_33 ) ,
L_8 ) ;
F_44 () ;
}
static void F_45 ( struct V_23 * V_34 ,
void (* F_46)( struct V_23 * V_35 ) ,
struct V_13 * V_14 )
{
unsigned long V_9 ;
F_47 ( V_34 ) ;
V_34 -> F_46 = F_46 ;
V_34 -> V_24 = NULL ;
F_11 ( V_9 ) ;
* V_14 -> V_17 = V_34 ;
V_14 -> V_17 = & V_34 -> V_24 ;
F_2 ( V_14 -> V_27 ++ ) ;
F_13 ( V_9 ) ;
}
void F_48 ( struct V_23 * V_34 , void (* F_46)( struct V_23 * V_35 ) )
{
F_45 ( V_34 , F_46 , & V_19 ) ;
}
void F_49 ( struct V_23 * V_34 , void (* F_46)( struct V_23 * V_35 ) )
{
F_45 ( V_34 , F_46 , & V_20 ) ;
}
