static int
F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 = 0 , V_5 = 0 ;
do {
V_3 . V_6 = F_2 ( 0 ) ;
if ( V_3 . V_7 . V_8 < 2 ) {
F_3 ( V_2 , ( char ) V_3 . V_7 . V_9 , 0 ) ;
V_4 ++ ;
}
} while( ( V_3 . V_7 . V_8 & 1 ) && ( ++ V_5 < 10 ) );
if ( V_4 )
F_4 ( V_2 ) ;
return V_4 ;
}
static void
F_5 ( unsigned long V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_10 ;
unsigned long V_13 ;
int V_14 = 10 ;
F_6 ( V_13 ) ;
if ( F_7 ( & V_15 ) ) {
if ( ! F_1 ( V_12 -> V_2 ) )
V_14 = 100 ;
F_8 ( & V_15 ) ;
}
F_9 ( & V_12 -> V_16 ) ;
if ( V_12 -> V_2 ) {
V_12 -> V_17 . V_18 = V_19 + V_14 ;
F_10 ( & V_12 -> V_17 ) ;
}
F_8 ( & V_12 -> V_16 ) ;
F_11 ( V_13 ) ;
}
static int
F_12 ( struct V_1 * V_2 , const char * V_20 , int V_4 )
{
static char V_21 [ 1 ] = L_1 ;
long V_9 , V_22 = V_4 ;
T_1 V_3 ;
char * V_23 ;
int V_24 ;
for ( V_23 = ( char * ) V_20 ; V_22 > 0 ; ) {
V_24 = 0 ;
for ( V_9 = 0 ; V_9 < F_13 ( long , 128L , V_22 ) && ! V_24 ; V_9 ++ )
if ( V_23 [ V_9 ] == '\n' )
V_24 = 1 ;
while ( V_9 > 0 ) {
V_3 . V_6 = F_14 ( 0 , V_23 , V_9 ) ;
V_9 -= V_3 . V_7 . V_9 ;
V_22 -= V_3 . V_7 . V_9 ;
V_23 += V_3 . V_7 . V_9 ;
if ( V_2 )
F_1 ( V_2 ) ;
}
while ( V_24 ) {
V_3 . V_6 = F_14 ( 0 , V_21 , 1 ) ;
if ( V_3 . V_7 . V_9 > 0 )
V_24 = 0 ;
}
}
return V_4 ;
}
static int
F_15 ( struct V_1 * V_2 ,
const unsigned char * V_20 , int V_4 )
{
unsigned long V_13 ;
F_16 ( & V_15 , V_13 ) ;
F_12 ( V_2 , ( const char * ) V_20 , V_4 ) ;
F_17 ( & V_15 , V_13 ) ;
return V_4 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
return 512 ;
}
static int
F_19 ( struct V_1 * V_2 )
{
return 0 ;
}
static int
F_20 ( struct V_11 * * V_25 )
{
static struct V_11 * V_12 = NULL ;
static F_21 ( V_26 ) ;
unsigned long V_13 ;
int V_27 = 0 ;
if ( V_12 == NULL ) {
V_12 = F_22 ( sizeof( * V_12 ) , V_28 ) ;
F_16 ( & V_26 , V_13 ) ;
if ( V_12 == NULL )
V_27 = - V_29 ;
else {
V_12 -> V_2 = NULL ;
F_23 ( & V_12 -> V_16 ) ;
F_24 ( & V_12 -> V_17 ) ;
}
F_17 ( & V_26 , V_13 ) ;
}
* V_25 = V_12 ;
return V_27 ;
}
static int
F_25 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
struct V_11 * V_12 ;
unsigned long V_13 ;
int V_27 ;
V_27 = F_20 ( & V_12 ) ;
if ( V_27 )
return V_27 ;
F_16 ( & V_12 -> V_16 , V_13 ) ;
if ( ! V_12 -> V_2 ) {
V_2 -> V_32 = V_12 ;
V_12 -> V_2 = V_2 ;
V_12 -> V_17 . V_33 = F_5 ;
V_12 -> V_17 . V_10 = ( unsigned long ) V_12 ;
V_12 -> V_17 . V_18 = V_19 + 10 ;
F_10 ( & V_12 -> V_17 ) ;
}
F_17 ( & V_12 -> V_16 , V_13 ) ;
return 0 ;
}
static void
F_26 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
struct V_11 * V_12 = V_2 -> V_32 ;
unsigned long V_13 ;
F_16 ( & V_12 -> V_16 , V_13 ) ;
if ( V_2 -> V_4 == 1 ) {
V_12 -> V_2 = NULL ;
F_27 ( & V_12 -> V_17 ) ;
}
F_17 ( & V_12 -> V_16 , V_13 ) ;
}
static int T_2
F_28 ( void )
{
if ( V_34 ) {
struct V_35 * V_36 ;
int V_37 ;
V_36 = F_29 ( V_38 ) ;
if ( ! V_36 )
return - V_29 ;
V_36 -> V_39 = L_2 ;
V_36 -> V_40 = L_2 ;
V_36 -> V_41 = 0 ;
V_36 -> V_42 = 0 ;
V_36 -> type = V_43 ;
V_36 -> V_44 = V_45 ;
V_36 -> V_46 = V_47 ;
F_30 ( V_36 , & V_48 ) ;
V_37 = F_31 ( V_36 ) ;
if ( V_37 ) {
F_32 ( V_36 ) ;
return V_37 ;
}
V_49 = V_36 ;
}
return - V_50 ;
}
static void
F_33 ( struct V_51 * V_52 , const char * V_53 , unsigned V_4 )
{
unsigned long V_13 ;
F_16 ( & V_15 , V_13 ) ;
F_12 ( NULL , V_53 , V_4 ) ;
F_17 ( & V_15 , V_13 ) ;
}
static struct V_35 *
F_34 ( struct V_51 * V_52 , int * V_54 )
{
* V_54 = V_52 -> V_54 ;
return V_49 ;
}
static int
F_35 ( struct V_51 * V_52 , char * V_55 )
{
return 0 ;
}
void T_2
F_36 ( void )
{
if ( ! V_34 ) {
F_37 () ;
F_38 ( & V_56 ) ;
V_34 = 1 ;
}
}
void T_2
F_39 ( void )
{
if ( V_34 ) {
F_40 () ;
F_41 ( & V_56 ) ;
V_34 = 0 ;
}
}
