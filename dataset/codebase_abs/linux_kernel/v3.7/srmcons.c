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
struct V_13 * V_14 = & V_12 -> V_14 ;
unsigned long V_15 ;
int V_16 = 10 ;
F_6 ( V_15 ) ;
if ( F_7 ( & V_17 ) ) {
if ( ! F_1 ( V_14 -> V_2 ) )
V_16 = 100 ;
F_8 ( & V_17 ) ;
}
F_9 ( & V_14 -> V_18 ) ;
if ( V_14 -> V_2 )
F_10 ( & V_12 -> V_19 , V_20 + V_16 ) ;
F_8 ( & V_14 -> V_18 ) ;
F_11 ( V_15 ) ;
}
static int
F_12 ( struct V_1 * V_2 , const char * V_21 , int V_4 )
{
static char V_22 [ 1 ] = L_1 ;
long V_9 , V_23 = V_4 ;
T_1 V_3 ;
char * V_24 ;
int V_25 ;
for ( V_24 = ( char * ) V_21 ; V_23 > 0 ; ) {
V_25 = 0 ;
for ( V_9 = 0 ; V_9 < F_13 ( long , 128L , V_23 ) && ! V_25 ; V_9 ++ )
if ( V_24 [ V_9 ] == '\n' )
V_25 = 1 ;
while ( V_9 > 0 ) {
V_3 . V_6 = F_14 ( 0 , V_24 , V_9 ) ;
V_9 -= V_3 . V_7 . V_9 ;
V_23 -= V_3 . V_7 . V_9 ;
V_24 += V_3 . V_7 . V_9 ;
if ( V_2 )
F_1 ( V_2 ) ;
}
while ( V_25 ) {
V_3 . V_6 = F_14 ( 0 , V_22 , 1 ) ;
if ( V_3 . V_7 . V_9 > 0 )
V_25 = 0 ;
}
}
return V_4 ;
}
static int
F_15 ( struct V_1 * V_2 ,
const unsigned char * V_21 , int V_4 )
{
unsigned long V_15 ;
F_16 ( & V_17 , V_15 ) ;
F_12 ( V_2 , ( const char * ) V_21 , V_4 ) ;
F_17 ( & V_17 , V_15 ) ;
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
F_20 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_11 * V_12 = & V_28 ;
struct V_13 * V_14 = & V_12 -> V_14 ;
unsigned long V_15 ;
F_16 ( & V_14 -> V_18 , V_15 ) ;
if ( ! V_14 -> V_2 ) {
V_2 -> V_29 = V_12 ;
V_2 -> V_14 = V_14 ;
V_14 -> V_2 = V_2 ;
F_10 ( & V_12 -> V_19 , V_20 + 10 ) ;
}
F_17 ( & V_14 -> V_18 , V_15 ) ;
return 0 ;
}
static void
F_21 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_11 * V_12 = V_2 -> V_29 ;
struct V_13 * V_14 = & V_12 -> V_14 ;
unsigned long V_15 ;
F_16 ( & V_14 -> V_18 , V_15 ) ;
if ( V_2 -> V_4 == 1 ) {
V_14 -> V_2 = NULL ;
F_22 ( & V_12 -> V_19 ) ;
}
F_17 ( & V_14 -> V_18 , V_15 ) ;
}
static int T_2
F_23 ( void )
{
F_24 ( & V_28 . V_14 ) ;
F_25 ( & V_28 . V_19 , F_5 ,
( unsigned long ) & V_28 ) ;
if ( V_30 ) {
struct V_31 * V_32 ;
int V_33 ;
V_32 = F_26 ( V_34 ) ;
if ( ! V_32 )
return - V_35 ;
V_32 -> V_36 = L_2 ;
V_32 -> V_37 = L_2 ;
V_32 -> V_38 = 0 ;
V_32 -> V_39 = 0 ;
V_32 -> type = V_40 ;
V_32 -> V_41 = V_42 ;
V_32 -> V_43 = V_44 ;
F_27 ( V_32 , & V_45 ) ;
F_28 ( & V_28 . V_14 , V_32 , 0 ) ;
V_33 = F_29 ( V_32 ) ;
if ( V_33 ) {
F_30 ( V_32 ) ;
return V_33 ;
}
V_46 = V_32 ;
}
return - V_47 ;
}
static void
F_31 ( struct V_48 * V_49 , const char * V_50 , unsigned V_4 )
{
unsigned long V_15 ;
F_16 ( & V_17 , V_15 ) ;
F_12 ( NULL , V_50 , V_4 ) ;
F_17 ( & V_17 , V_15 ) ;
}
static struct V_31 *
F_32 ( struct V_48 * V_49 , int * V_51 )
{
* V_51 = V_49 -> V_51 ;
return V_46 ;
}
static int
F_33 ( struct V_48 * V_49 , char * V_52 )
{
return 0 ;
}
void T_2
F_34 ( void )
{
if ( ! V_30 ) {
F_35 () ;
F_36 ( & V_53 ) ;
V_30 = 1 ;
}
}
void T_2
F_37 ( void )
{
if ( V_30 ) {
F_38 () ;
F_39 ( & V_53 ) ;
V_30 = 0 ;
}
}
