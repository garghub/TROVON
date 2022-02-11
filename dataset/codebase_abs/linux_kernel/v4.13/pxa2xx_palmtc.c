static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_4 ,
F_3 ( V_4 ) ) ;
V_2 -> V_5 [ V_6 ] . V_7 = V_8 ;
V_2 -> V_5 [ V_6 ] . V_9 = L_1 ;
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_4 , F_3 ( V_4 ) ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
V_11 -> V_12 = 1 ;
V_11 -> V_13 = 1 ;
V_11 -> V_14 = 0 ;
}
static int F_7 ( void )
{
F_8 ( V_15 , 1 ) ;
F_8 ( V_16 , 0 ) ;
F_9 ( 40 ) ;
F_8 ( V_17 , 0 ) ;
return 0 ;
}
static int F_10 ( void )
{
int V_18 = 50 ;
F_8 ( V_19 , 1 ) ;
F_9 ( 50 ) ;
F_8 ( V_17 , 1 ) ;
F_9 ( 100 ) ;
F_8 ( V_16 , 1 ) ;
while ( ! F_11 ( V_20 ) &&
V_18 ) {
F_9 ( 1 ) ;
V_18 -- ;
}
if ( ! V_18 ) {
F_7 () ;
return 1 ;
}
F_8 ( V_15 , 1 ) ;
F_9 ( 20 ) ;
F_8 ( V_15 , 0 ) ;
F_9 ( 25 ) ;
F_8 ( V_19 , 0 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
const T_1 * V_11 )
{
int V_3 = 1 ;
if ( V_11 -> V_21 == 0 )
V_3 = F_7 () ;
else if ( V_11 -> V_21 == 33 )
V_3 = F_10 () ;
return V_3 ;
}
static int T_2 F_13 ( void )
{
int V_3 ;
if ( ! F_14 () )
return - V_22 ;
V_23 = F_15 ( L_2 , - 1 ) ;
if ( ! V_23 )
return - V_24 ;
V_3 = F_16 ( V_23 , & V_25 ,
sizeof( V_25 ) ) ;
if ( ! V_3 )
V_3 = F_17 ( V_23 ) ;
if ( V_3 )
F_18 ( V_23 ) ;
return V_3 ;
}
static void T_3 F_19 ( void )
{
F_20 ( V_23 ) ;
}
