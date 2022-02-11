static int T_1 F_1 ( void )
{
F_2 ( NULL , V_1 , NULL ) ;
return 0 ;
}
static int T_1 F_3 ( void )
{
unsigned long V_2 = F_4 () ;
if ( ! F_5 ( V_2 , L_1 ) )
return 0 ;
V_3 = ~ 0L ;
return 1 ;
}
static int T_1 F_6 ( void )
{
struct V_4 * V_5 ;
void T_2 * V_6 ;
T_3 V_7 , V_8 ;
V_5 = F_7 ( NULL , NULL , L_2 ) ;
if ( V_5 == NULL )
return - V_9 ;
V_6 = F_8 ( V_5 , 0 ) ;
F_9 ( V_5 ) ;
if ( V_6 == NULL )
return - V_9 ;
V_7 = F_10 ( V_6 + 0x40 ) ;
V_8 = F_10 ( V_6 + 0x44 ) ;
F_11 ( V_6 ) ;
if ( V_7 || V_8 )
F_12 ( V_10 L_3 , V_7 , V_8 ) ;
else
F_12 ( V_10 L_4 ) ;
return 0 ;
}
int F_13 ( void (* F_14)( void * V_11 ) , void * V_11 )
{
struct V_12 * V_13 ;
V_13 = F_15 ( sizeof( struct V_12 ) , V_14 ) ;
if ( V_13 == NULL )
return - V_15 ;
V_13 -> F_14 = F_14 ;
V_13 -> V_11 = V_11 ;
F_16 ( & V_13 -> V_16 , & V_17 ) ;
return 0 ;
}
int F_17 ( void (* F_14)( void * V_11 ) , void * V_11 )
{
struct V_12 * V_13 ;
F_18 (shutdown, &dtm_shutdown_list, list)
if ( V_13 -> F_14 == F_14 && V_13 -> V_11 == V_11 ) {
F_19 ( & V_13 -> V_16 ) ;
F_20 ( V_13 ) ;
return 0 ;
}
return - V_18 ;
}
static T_4 F_21 ( int V_19 , void * V_20 )
{
struct V_12 * V_13 ;
int V_21 = 1 ;
F_22 () ;
F_23 ( V_22 , 0 ) ;
F_18 (shutdown, &dtm_shutdown_list, list)
V_13 -> F_14 ( V_13 -> V_11 ) ;
F_12 ( V_23 L_5 ) ;
while ( 1 ) {
if ( V_24 ) {
unsigned V_25 = F_10 ( V_24 + 0x14 ) ;
F_24 ( V_24 + 0x14 , V_25 ) ;
}
F_23 ( V_26 , V_21 ) ;
V_21 ^= 1 ;
F_25 ( 500 ) ;
}
return V_27 ;
}
static int F_26 ( void )
{
struct V_4 * V_5 , * V_28 ;
V_5 = F_7 ( NULL , NULL , L_6 ) ;
if ( ! V_5 ) {
F_12 (KERN_ERR __FILE__ L_7 ) ;
return - V_9 ;
}
F_27 (np, child)
if ( strcmp ( V_28 -> V_29 , L_8 ) == 0 )
V_22 = F_28 ( V_28 , 0 ) ;
else if ( strcmp ( V_28 -> V_29 , L_9 ) == 0 )
V_26 = F_28 ( V_28 , 0 ) ;
F_9 ( V_5 ) ;
return 0 ;
}
static void F_29 ( struct V_4 * V_5 ,
struct V_30 * V_31 )
{
int V_19 , V_32 ;
F_26 () ;
F_30 ( V_31 , 2 , 65 ) ;
F_30 ( V_31 , 3 , 0 ) ;
V_19 = F_31 ( V_5 , 0 ) ;
if ( V_19 == V_33 ) {
F_12 (KERN_ERR __FILE__ L_10 ) ;
return;
}
V_32 = F_32 ( V_19 , F_21 , 0 , L_11 , NULL ) ;
if ( V_32 ) {
F_12 (KERN_ERR __FILE__
L_12 , irq, rc) ;
return;
}
}
static inline void F_33 ( void T_2 * V_6 )
{
static int V_34 ;
T_3 V_35 = F_10 ( V_6 + 0x34 ) & ( 1 << 14 ) ;
if ( V_34 != V_35 ) {
V_34 = V_35 ;
if ( V_35 )
F_12 ( V_36 L_13
L_14 ) ;
}
}
static int F_34 ( void T_2 * V_6 )
{
struct V_4 * V_5 ;
struct V_30 * V_31 ;
V_5 = F_7 ( NULL , NULL , L_15 ) ;
if ( V_5 == NULL )
return - V_9 ;
V_31 = F_35 ( V_5 ) ;
if ( V_31 == NULL ) {
F_9 ( V_5 ) ;
return - V_9 ;
}
F_29 ( V_5 , V_31 ) ;
F_9 ( V_5 ) ;
F_12 ( V_10 L_16 ) ;
while ( ! F_36 () ) {
int V_37 ;
V_37 = F_37 ( V_31 , 0 ) ;
if ( V_37 < 0 )
F_38 ( & V_31 -> V_38 , L_17 ) ;
else {
T_5 V_39 = F_39 ( V_37 ) ;
F_24 ( V_6 + 0x20 , V_39 ) ;
}
F_33 ( V_6 ) ;
F_40 ( V_40 ) ;
F_41 ( V_41 ) ;
}
return 0 ;
}
static int T_1 F_42 ( void )
{
struct V_42 * V_43 ;
struct V_4 * V_5 ;
V_5 = F_7 ( NULL , NULL , L_18 ) ;
if ( V_5 == NULL )
return - V_9 ;
V_24 = F_8 ( V_5 , 0 ) ;
F_9 ( V_5 ) ;
if ( V_24 == NULL )
return - V_9 ;
F_6 () ;
V_43 = F_43 ( F_34 , V_24 , L_19 ) ;
if ( F_44 ( V_43 ) ) {
F_11 ( V_24 ) ;
return F_45 ( V_43 ) ;
}
return 0 ;
}
int F_13 ( void (* F_14)( void * V_11 ) , void * V_11 )
{
return 0 ;
}
int F_17 ( void (* F_14)( void * V_11 ) , void * V_11 )
{
return 0 ;
}
