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
V_5 -> V_1 == V_8 ) {
if ( strncmp ( V_5 -> V_6 , V_9 ,
strlen ( V_9 ) ) == 0 )
if ( F_5 ( V_10 , F_6 ( V_10 ) ,
V_5 -> V_11 ) < 0 ) {
int V_12 ;
F_2 ( L_2 ) ;
for ( V_12 = 0 ; V_12 < F_6 ( V_10 ) ; V_12 ++ )
F_7 ( L_3 , V_10 [ V_12 ] ) ;
F_7 ( L_4 ) ;
return - V_13 ;
}
return F_8 ( V_5 -> V_6 , V_2 ) ;
}
return F_1 ( V_5 -> V_1 , V_2 ) ;
}
static int F_9 ( struct V_14 * V_15 )
{
struct V_16 * V_17 ;
if ( V_15 -> V_18 -> V_19 == NULL )
return - V_20 ;
V_21 = V_15 ;
V_17 = F_10 ( sizeof( struct V_16 ) , V_22 ) ;
if ( ! V_17 ) {
F_2 ( L_5 ) ;
return - V_23 ;
}
F_11 ( & V_17 -> V_24 , 0 ) ;
V_17 -> V_25 = true ;
V_21 -> V_26 = V_17 ;
return 0 ;
}
static void F_12 ( struct V_14 * V_15 )
{
F_13 ( V_21 -> V_26 ) ;
V_21 = NULL ;
}
static int F_14 ( struct V_14 * V_15 ,
const unsigned char * V_27 , char * V_28 , int V_29 )
{
struct V_16 * V_17 = V_15 -> V_26 ;
if ( V_30 -> V_31 ) {
int V_12 ;
for ( V_12 = 0 ; V_12 < V_29 ; V_12 ++ )
V_30 -> V_31 ( V_27 [ V_12 ] ) ;
return V_29 ;
}
if ( ! V_17 -> V_25 )
return 0 ;
F_15 () ;
V_17 -> V_32 = V_27 [ 0 ] ;
V_17 -> V_25 = false ;
F_16 ( & V_17 -> V_24 ) ;
return 1 ;
}
static inline void F_17 ( struct V_14 * V_15 , struct V_33 * V_34 )
{
F_18 ( & V_15 -> V_35 ) ;
* V_34 = V_15 -> V_36 ;
F_19 ( & V_15 -> V_35 ) ;
}
static int F_20 ( struct V_4 * V_5 )
{
int V_37 = 0 ;
struct V_14 * V_15 ;
struct V_33 V_38 ;
T_1 V_39 ;
V_37 = F_4 ( V_5 , & V_39 ) ;
if ( V_37 )
return V_37 ;
V_15 = F_21 ( V_39 , NULL , NULL ) ;
if ( F_22 ( V_15 ) )
return F_23 ( V_15 ) ;
if ( V_15 -> V_18 -> V_40 )
V_37 = V_15 -> V_18 -> V_40 ( V_15 , NULL ) ;
else
V_37 = - V_41 ;
if ( V_37 ) {
F_24 ( V_15 ) ;
return V_37 ;
}
F_25 ( V_42 , & V_15 -> V_43 ) ;
F_17 ( V_15 , & V_38 ) ;
if ( ! ( V_38 . V_44 & V_45 ) ) {
V_38 . V_44 |= V_45 ;
F_26 ( V_15 , & V_38 ) ;
F_17 ( V_15 , & V_38 ) ;
if ( ! ( V_38 . V_44 & V_45 ) )
F_27 ( L_6 ) ;
}
F_24 ( V_15 ) ;
V_37 = F_28 ( V_15 , V_46 ) ;
if ( V_37 )
F_2 ( L_7 ) ;
return V_37 ;
}
void F_29 ( void )
{
if ( F_30 ( V_46 , & V_47 ) )
F_27 ( L_8 ) ;
}
void F_31 ( void )
{
if ( F_32 ( V_46 ) )
F_27 ( L_9 ) ;
}
static int F_33 ( struct V_4 * V_48 , const char V_49 )
{
if ( V_48 -> V_50 && V_21 && V_21 -> V_18 -> V_19 ) {
int V_37 = V_21 -> V_18 -> V_19 ( V_21 , & V_49 , 1 ) ;
if ( V_37 == 0 )
return 0 ;
if ( V_37 < 0 ) {
F_27 ( L_10 , V_48 -> V_51 ) ;
V_48 -> V_50 = 0 ;
F_34 () ;
return 0 ;
}
return 1 ;
}
return 0 ;
}
static void F_35 ( char V_49 )
{
V_21 -> V_18 -> V_52 ( V_21 , V_49 ) ;
}
static void F_36 ( unsigned int V_53 , unsigned int V_54 )
{
V_21 -> V_18 -> V_55 ( V_21 , V_53 , V_54 ) ;
}
static unsigned char F_37 ( int V_56 )
{
struct V_16 * V_17 = V_21 -> V_26 ;
char V_57 ;
if ( F_38 ( & V_17 -> V_24 , F_39 ( V_56 ) ) == - V_58 ) {
if ( V_56 )
F_27 ( L_11 ,
V_56 ) ;
return 0xff ;
}
V_57 = V_17 -> V_32 ;
F_15 () ;
V_17 -> V_25 = true ;
F_40 ( V_21 -> V_59 ) ;
return V_57 ;
}
static unsigned char F_41 ( void )
{
return F_37 ( V_60 ) ;
}
static unsigned char F_42 ( void )
{
T_2 V_57 = F_37 ( 0 ) ;
return ( V_57 == 0xff ) ? 0 : V_57 ;
}
static void F_43 ( void )
{
if ( V_21 -> V_18 -> V_61 )
V_21 -> V_18 -> V_61 ( V_21 ) ;
}
int F_44 ( struct V_4 * V_5 )
{
int V_57 = F_20 ( V_5 ) ;
if ( V_57 )
return V_57 ;
V_5 -> V_50 = 1 ;
V_30 = V_5 ;
return 0 ;
}
void F_45 ( void )
{
if ( ! V_21 )
return;
F_46 ( V_21 ) ;
if ( V_21 -> V_18 -> V_62 )
V_21 -> V_18 -> V_62 ( V_21 , NULL ) ;
F_47 ( V_21 ) ;
F_24 ( V_21 ) ;
F_48 ( V_21 , V_21 -> V_63 ) ;
}
const char * F_49 ( struct V_4 * V_5 , const char * V_64 )
{
T_3 V_49 ;
while ( ( V_49 = * V_64 ) ) {
if ( V_49 == '\n' )
V_49 = V_5 -> V_65 ;
if ( F_50 ( V_21 ) < 1 || ! V_5 -> V_66 -> V_67 ( V_5 , V_49 ) )
return V_64 ;
V_64 ++ ;
}
return NULL ;
}
