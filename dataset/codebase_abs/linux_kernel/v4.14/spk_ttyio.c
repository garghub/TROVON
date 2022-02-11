static int F_1 ( int V_1 , T_1 * V_2 )
{
if ( V_1 < 0 || V_1 > ( 255 - 64 ) ) {
F_2 ( L_1 ) ;
return - V_3 ;
}
* V_2 = F_3 ( 4 , ( 64 + V_1 ) ) ;
return 0 ;
}
static int F_4 ( struct V_4 * V_5 , T_1 * V_2 )
{
if ( strcmp ( V_5 -> V_6 , V_7 ) ||
V_5 -> V_1 == V_8 )
return F_5 ( V_5 -> V_6 , V_2 ) ;
return F_1 ( V_5 -> V_1 , V_2 ) ;
}
static int F_6 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
if ( V_10 -> V_13 -> V_14 == NULL )
return - V_15 ;
V_16 = V_10 ;
V_12 = F_7 ( sizeof( struct V_11 ) , V_17 ) ;
if ( ! V_12 ) {
F_2 ( L_2 ) ;
return - V_18 ;
}
F_8 ( & V_12 -> V_19 , 0 ) ;
V_12 -> V_20 = true ;
V_16 -> V_21 = V_12 ;
return 0 ;
}
static void F_9 ( struct V_9 * V_10 )
{
F_10 ( & V_22 ) ;
F_11 ( V_16 -> V_21 ) ;
V_16 = NULL ;
F_12 ( & V_22 ) ;
}
static int F_13 ( struct V_9 * V_10 ,
const unsigned char * V_23 , char * V_24 , int V_25 )
{
struct V_11 * V_12 = V_10 -> V_21 ;
if ( V_26 -> V_27 ) {
int V_28 ;
for ( V_28 = 0 ; V_28 < V_25 ; V_28 ++ )
V_26 -> V_27 ( V_23 [ V_28 ] ) ;
return V_25 ;
}
if ( ! V_12 -> V_20 )
return 0 ;
F_14 () ;
V_12 -> V_29 = V_23 [ 0 ] ;
V_12 -> V_20 = false ;
F_15 ( & V_12 -> V_19 ) ;
return 1 ;
}
static inline void F_16 ( struct V_9 * V_10 , struct V_30 * V_31 )
{
F_17 ( & V_10 -> V_32 ) ;
* V_31 = V_10 -> V_33 ;
F_18 ( & V_10 -> V_32 ) ;
}
static int F_19 ( struct V_4 * V_5 )
{
int V_34 = 0 ;
struct V_9 * V_10 ;
struct V_30 V_35 ;
T_1 V_36 ;
V_34 = F_4 ( V_5 , & V_36 ) ;
if ( V_34 )
return V_34 ;
V_10 = F_20 ( V_36 ) ;
if ( F_21 ( V_10 ) )
return F_22 ( V_10 ) ;
if ( V_10 -> V_13 -> V_37 )
V_34 = V_10 -> V_13 -> V_37 ( V_10 , NULL ) ;
else
V_34 = - V_38 ;
if ( V_34 ) {
F_23 ( V_10 ) ;
return V_34 ;
}
F_24 ( V_39 , & V_10 -> V_40 ) ;
F_16 ( V_10 , & V_35 ) ;
if ( ! ( V_35 . V_41 & V_42 ) ) {
V_35 . V_41 |= V_42 ;
F_25 ( V_10 , & V_35 ) ;
F_16 ( V_10 , & V_35 ) ;
if ( ! ( V_35 . V_41 & V_42 ) )
F_26 ( L_3 ) ;
}
F_23 ( V_10 ) ;
V_34 = F_27 ( V_10 , V_43 ) ;
if ( V_34 )
F_2 ( L_4 ) ;
return V_34 ;
}
void F_28 ( void )
{
if ( F_29 ( V_43 , & V_44 ) )
F_26 ( L_5 ) ;
}
void F_30 ( void )
{
if ( F_31 ( V_43 ) )
F_26 ( L_6 ) ;
}
static int F_32 ( struct V_4 * V_45 , const char V_46 )
{
F_10 ( & V_22 ) ;
if ( V_45 -> V_47 && V_16 && V_16 -> V_13 -> V_14 ) {
int V_34 = V_16 -> V_13 -> V_14 ( V_16 , & V_46 , 1 ) ;
F_12 ( & V_22 ) ;
if ( V_34 == 0 )
return 0 ;
if ( V_34 < 0 ) {
F_26 ( L_7 , V_45 -> V_48 ) ;
V_45 -> V_47 = 0 ;
F_33 () ;
return 0 ;
}
return 1 ;
}
F_12 ( & V_22 ) ;
return 0 ;
}
static int F_34 ( struct V_9 * V_10 )
{
if ( ! V_10 ) {
F_26 ( L_7 ,
V_26 -> V_48 ) ;
V_26 -> V_47 = 0 ;
F_33 () ;
return 1 ;
}
return 0 ;
}
static void F_35 ( char V_46 )
{
F_10 ( & V_22 ) ;
if ( F_34 ( V_16 ) ) {
F_12 ( & V_22 ) ;
return;
}
V_16 -> V_13 -> V_49 ( V_16 , V_46 ) ;
F_12 ( & V_22 ) ;
}
static void F_36 ( unsigned int V_50 , unsigned int V_51 )
{
F_10 ( & V_22 ) ;
if ( F_34 ( V_16 ) ) {
F_12 ( & V_22 ) ;
return;
}
V_16 -> V_13 -> V_52 ( V_16 , V_50 , V_51 ) ;
F_12 ( & V_22 ) ;
}
static unsigned char F_37 ( int V_53 )
{
struct V_11 * V_12 = V_16 -> V_21 ;
char V_54 ;
if ( F_38 ( & V_12 -> V_19 , F_39 ( V_53 ) ) == - V_55 ) {
if ( V_53 )
F_26 ( L_8 ,
V_53 ) ;
return 0xff ;
}
V_54 = V_12 -> V_29 ;
F_14 () ;
V_12 -> V_20 = true ;
F_40 ( V_16 -> V_56 ) ;
return V_54 ;
}
static unsigned char F_41 ( void )
{
return F_37 ( V_57 ) ;
}
static unsigned char F_42 ( void )
{
T_2 V_54 = F_37 ( 0 ) ;
return ( V_54 == 0xff ) ? 0 : V_54 ;
}
static void F_43 ( void )
{
F_10 ( & V_22 ) ;
if ( F_34 ( V_16 ) ) {
F_12 ( & V_22 ) ;
return;
}
if ( V_16 -> V_13 -> V_58 )
V_16 -> V_13 -> V_58 ( V_16 ) ;
F_12 ( & V_22 ) ;
}
int F_44 ( struct V_4 * V_5 )
{
int V_54 = F_19 ( V_5 ) ;
if ( V_54 )
return V_54 ;
V_5 -> V_47 = 1 ;
V_26 = V_5 ;
return 0 ;
}
void F_45 ( void )
{
if ( ! V_16 )
return;
F_46 ( V_16 ) ;
if ( V_16 -> V_13 -> V_59 )
V_16 -> V_13 -> V_59 ( V_16 , NULL ) ;
F_47 ( V_16 ) ;
F_23 ( V_16 ) ;
F_48 ( V_16 ) ;
}
const char * F_49 ( struct V_4 * V_5 , const char * V_60 )
{
T_3 V_46 ;
while ( ( V_46 = * V_60 ) ) {
if ( V_46 == '\n' )
V_46 = V_5 -> V_61 ;
if ( F_50 ( V_16 ) < 1 || ! V_5 -> V_62 -> V_63 ( V_5 , V_46 ) )
return V_60 ;
V_60 ++ ;
}
return NULL ;
}
