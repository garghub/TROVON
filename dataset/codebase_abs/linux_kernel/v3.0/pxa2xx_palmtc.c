static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_4 ,
F_3 ( V_4 ) ) ;
V_2 -> V_5 . V_6 = F_4 ( V_7 ) ;
return V_3 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_4 , F_3 ( V_4 ) ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
V_9 -> V_10 = 1 ;
V_9 -> V_11 = ! ! F_8 ( V_7 ) ;
V_9 -> V_12 = 1 ;
V_9 -> V_13 = 1 ;
V_9 -> V_14 = 0 ;
V_9 -> V_15 = 1 ;
V_9 -> V_16 = 0 ;
}
static int F_9 ( void )
{
F_10 ( V_17 , 1 ) ;
F_10 ( V_18 , 0 ) ;
F_11 ( 40 ) ;
F_10 ( V_19 , 0 ) ;
return 0 ;
}
static int F_12 ( void )
{
int V_20 = 50 ;
F_10 ( V_21 , 1 ) ;
F_11 ( 50 ) ;
F_10 ( V_19 , 1 ) ;
F_11 ( 100 ) ;
F_10 ( V_18 , 1 ) ;
while ( ! F_8 ( V_22 ) &&
V_20 ) {
F_11 ( 1 ) ;
V_20 -- ;
}
if ( ! V_20 ) {
F_9 () ;
return 1 ;
}
F_10 ( V_17 , 1 ) ;
F_11 ( 20 ) ;
F_10 ( V_17 , 0 ) ;
F_11 ( 25 ) ;
F_10 ( V_21 , 0 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
const T_1 * V_9 )
{
int V_3 = 1 ;
if ( V_9 -> V_23 == 0 )
V_3 = F_9 () ;
else if ( V_9 -> V_23 == 33 )
V_3 = F_12 () ;
return V_3 ;
}
static void F_14 ( struct V_1 * V_2 )
{
}
static void F_15 ( struct V_1 * V_2 )
{
}
static int T_2 F_16 ( void )
{
int V_3 ;
if ( ! F_17 () )
return - V_24 ;
V_25 = F_18 ( L_1 , - 1 ) ;
if ( ! V_25 )
return - V_26 ;
V_3 = F_19 ( V_25 , & V_27 ,
sizeof( V_27 ) ) ;
if ( ! V_3 )
V_3 = F_20 ( V_25 ) ;
if ( V_3 )
F_21 ( V_25 ) ;
return V_3 ;
}
static void T_3 F_22 ( void )
{
F_23 ( V_25 ) ;
}
