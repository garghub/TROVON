static int T_1 F_1 ( void )
{
F_2 ( NULL , V_1 , NULL ) ;
return 0 ;
}
static int T_1 F_3 ( void )
{
if ( ! F_4 ( L_1 ) )
return 0 ;
V_2 = ~ 0L ;
return 1 ;
}
static int T_1 F_5 ( void )
{
struct V_3 * V_4 ;
void T_2 * V_5 ;
T_3 V_6 , V_7 ;
V_4 = F_6 ( NULL , NULL , L_2 ) ;
if ( V_4 == NULL )
return - V_8 ;
V_5 = F_7 ( V_4 , 0 ) ;
F_8 ( V_4 ) ;
if ( V_5 == NULL )
return - V_8 ;
V_6 = F_9 ( V_5 + 0x40 ) ;
V_7 = F_9 ( V_5 + 0x44 ) ;
F_10 ( V_5 ) ;
if ( V_6 || V_7 )
F_11 ( V_9 L_3 , V_6 , V_7 ) ;
else
F_11 ( V_9 L_4 ) ;
return 0 ;
}
int F_12 ( void (* F_13)( void * V_10 ) , void * V_10 )
{
struct V_11 * V_12 ;
V_12 = F_14 ( sizeof( struct V_11 ) , V_13 ) ;
if ( V_12 == NULL )
return - V_14 ;
V_12 -> F_13 = F_13 ;
V_12 -> V_10 = V_10 ;
F_15 ( & V_12 -> V_15 , & V_16 ) ;
return 0 ;
}
int F_16 ( void (* F_13)( void * V_10 ) , void * V_10 )
{
struct V_11 * V_12 ;
F_17 (shutdown, &dtm_shutdown_list, list)
if ( V_12 -> F_13 == F_13 && V_12 -> V_10 == V_10 ) {
F_18 ( & V_12 -> V_15 ) ;
F_19 ( V_12 ) ;
return 0 ;
}
return - V_17 ;
}
static T_4 F_20 ( int V_18 , void * V_19 )
{
struct V_11 * V_12 ;
int V_20 = 1 ;
F_21 () ;
F_22 ( V_21 , 0 ) ;
F_17 (shutdown, &dtm_shutdown_list, list)
V_12 -> F_13 ( V_12 -> V_10 ) ;
F_11 ( V_22 L_5 ) ;
while ( 1 ) {
if ( V_23 ) {
unsigned V_24 = F_9 ( V_23 + 0x14 ) ;
F_23 ( V_23 + 0x14 , V_24 ) ;
}
F_22 ( V_25 , V_20 ) ;
V_20 ^= 1 ;
F_24 ( 500 ) ;
}
return V_26 ;
}
static int F_25 ( void )
{
struct V_3 * V_4 , * V_27 ;
V_4 = F_6 ( NULL , NULL , L_6 ) ;
if ( ! V_4 ) {
F_11 (KERN_ERR __FILE__ L_7 ) ;
return - V_8 ;
}
F_26 (np, child)
if ( strcmp ( V_27 -> V_28 , L_8 ) == 0 )
V_21 = F_27 ( V_27 , 0 ) ;
else if ( strcmp ( V_27 -> V_28 , L_9 ) == 0 )
V_25 = F_27 ( V_27 , 0 ) ;
F_8 ( V_4 ) ;
return 0 ;
}
static void F_28 ( struct V_3 * V_4 ,
struct V_29 * V_30 )
{
int V_18 , V_31 ;
F_25 () ;
F_29 ( V_30 , 2 , 65 ) ;
F_29 ( V_30 , 3 , 0 ) ;
V_18 = F_30 ( V_4 , 0 ) ;
if ( ! V_18 ) {
F_11 (KERN_ERR __FILE__ L_10 ) ;
return;
}
V_31 = F_31 ( V_18 , F_20 , 0 , L_11 , NULL ) ;
if ( V_31 ) {
F_11 (KERN_ERR __FILE__
L_12 , irq, rc) ;
return;
}
}
static inline void F_32 ( void T_2 * V_5 )
{
static int V_32 ;
T_3 V_33 = F_9 ( V_5 + 0x34 ) & ( 1 << 14 ) ;
if ( V_32 != V_33 ) {
V_32 = V_33 ;
if ( V_33 )
F_11 ( V_34 L_13
L_14 ) ;
}
}
static int F_33 ( void T_2 * V_5 )
{
struct V_3 * V_4 ;
struct V_29 * V_30 ;
V_4 = F_6 ( NULL , NULL , L_15 ) ;
if ( V_4 == NULL )
return - V_8 ;
V_30 = F_34 ( V_4 ) ;
if ( V_30 == NULL ) {
F_8 ( V_4 ) ;
return - V_8 ;
}
F_28 ( V_4 , V_30 ) ;
F_8 ( V_4 ) ;
F_11 ( V_9 L_16 ) ;
while ( ! F_35 () ) {
int V_35 ;
V_35 = F_36 ( V_30 , 0 ) ;
if ( V_35 < 0 )
F_37 ( & V_30 -> V_36 , L_17 ) ;
else {
T_5 V_37 = F_38 ( V_35 ) ;
F_23 ( V_5 + 0x20 , V_37 ) ;
}
F_32 ( V_5 ) ;
F_39 ( V_38 ) ;
F_40 ( V_39 ) ;
}
return 0 ;
}
static int T_1 F_41 ( void )
{
struct V_40 * V_41 ;
struct V_3 * V_4 ;
V_4 = F_6 ( NULL , NULL , L_18 ) ;
if ( V_4 == NULL )
return - V_8 ;
V_23 = F_7 ( V_4 , 0 ) ;
F_8 ( V_4 ) ;
if ( V_23 == NULL )
return - V_8 ;
F_5 () ;
V_41 = F_42 ( F_33 , V_23 , L_19 ) ;
if ( F_43 ( V_41 ) ) {
F_10 ( V_23 ) ;
return F_44 ( V_41 ) ;
}
return 0 ;
}
int F_12 ( void (* F_13)( void * V_10 ) , void * V_10 )
{
return 0 ;
}
int F_16 ( void (* F_13)( void * V_10 ) , void * V_10 )
{
return 0 ;
}
