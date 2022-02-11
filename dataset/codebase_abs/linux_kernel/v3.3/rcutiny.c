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
V_2 = 0 ;
F_1 ( V_1 ) ;
F_12 ( V_9 ) ;
}
void F_13 ( void )
{
unsigned long V_9 ;
long long V_1 ;
F_11 ( V_9 ) ;
V_1 = V_2 ;
V_2 -- ;
F_14 ( V_2 < 0 ) ;
F_1 ( V_1 ) ;
F_12 ( V_9 ) ;
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
F_14 ( V_1 != 0 ) ;
V_2 = V_10 ;
F_15 ( V_1 ) ;
F_12 ( V_9 ) ;
}
void F_17 ( void )
{
unsigned long V_9 ;
long long V_1 ;
F_11 ( V_9 ) ;
V_1 = V_2 ;
V_2 ++ ;
F_14 ( V_2 == 0 ) ;
F_15 ( V_1 ) ;
F_12 ( V_9 ) ;
}
int F_18 ( void )
{
return ! V_2 ;
}
int F_19 ( void )
{
return V_2 <= 0 ;
}
static int F_20 ( struct V_11 * V_12 )
{
if ( V_12 -> V_13 != NULL &&
V_12 -> V_14 != V_12 -> V_15 ) {
V_12 -> V_14 = V_12 -> V_15 ;
return 1 ;
}
return 0 ;
}
void F_9 ( int V_16 )
{
unsigned long V_9 ;
F_11 ( V_9 ) ;
if ( F_20 ( & V_17 ) +
F_20 ( & V_18 ) )
F_21 () ;
F_12 ( V_9 ) ;
}
void F_22 ( int V_16 )
{
unsigned long V_9 ;
F_11 ( V_9 ) ;
if ( F_20 ( & V_18 ) )
F_21 () ;
F_12 ( V_9 ) ;
}
void F_23 ( int V_16 , int V_19 )
{
if ( V_19 || F_19 () )
F_9 ( V_16 ) ;
else if ( ! F_24 () )
F_22 ( V_16 ) ;
F_25 () ;
}
static void F_26 ( struct V_11 * V_12 )
{
char * V_20 = NULL ;
struct V_21 * V_22 , * V_23 ;
unsigned long V_9 ;
F_2 (int cb_count = 0 ) ;
if ( & V_12 -> V_13 == V_12 -> V_14 ) {
F_2 ( F_27 ( V_12 -> V_24 , 0 , - 1 ) ) ;
F_2 ( F_28 ( V_12 -> V_24 , 0 ,
F_29 ( V_12 -> V_13 ) ,
F_30 () ,
F_4 ( V_3 ) ,
F_31 () ) ) ;
return;
}
F_11 ( V_9 ) ;
F_2 ( F_27 ( V_12 -> V_24 , 0 , - 1 ) ) ;
V_23 = V_12 -> V_13 ;
V_12 -> V_13 = * V_12 -> V_14 ;
* V_12 -> V_14 = NULL ;
if ( V_12 -> V_15 == V_12 -> V_14 )
V_12 -> V_15 = & V_12 -> V_13 ;
F_32 ( V_12 ) ;
V_12 -> V_14 = & V_12 -> V_13 ;
F_12 ( V_9 ) ;
F_2 ( V_20 = V_12 -> V_24 ) ;
while ( V_23 ) {
V_22 = V_23 -> V_22 ;
F_33 ( V_22 ) ;
F_34 ( V_23 ) ;
F_35 () ;
F_36 ( V_20 , V_23 ) ;
F_37 () ;
V_23 = V_22 ;
F_2 ( V_25 ++ ) ;
}
F_2 ( F_38 ( V_12 , V_25 ) ) ;
F_2 ( F_28 ( V_12 -> V_24 , V_25 , 0 , F_30 () ,
F_4 ( V_3 ) ,
F_31 () ) ) ;
}
static void F_39 ( struct V_26 * V_27 )
{
F_26 ( & V_17 ) ;
F_26 ( & V_18 ) ;
F_40 () ;
}
void F_41 ( void )
{
F_42 () ;
}
static void F_43 ( struct V_21 * V_28 ,
void (* F_44)( struct V_21 * V_29 ) ,
struct V_11 * V_12 )
{
unsigned long V_9 ;
F_45 ( V_28 ) ;
V_28 -> F_44 = F_44 ;
V_28 -> V_22 = NULL ;
F_11 ( V_9 ) ;
* V_12 -> V_15 = V_28 ;
V_12 -> V_15 = & V_28 -> V_22 ;
F_2 ( V_12 -> V_30 ++ ) ;
F_12 ( V_9 ) ;
}
void F_46 ( struct V_21 * V_28 , void (* F_44)( struct V_21 * V_29 ) )
{
F_43 ( V_28 , F_44 , & V_17 ) ;
}
void F_47 ( struct V_21 * V_28 , void (* F_44)( struct V_21 * V_29 ) )
{
F_43 ( V_28 , F_44 , & V_18 ) ;
}
