static enum V_1 F_1 ( struct V_2 * V_2 )
{
F_2 ( F_3 () , 0 ) ;
F_4 ( V_2 , F_5 ( V_3 ) ) ;
return V_4 ;
}
static void F_6 ( void * V_5 )
{
struct V_2 * V_2 = F_7 ( & V_6 ) ;
if ( ! V_7 )
return;
F_8 ( V_2 , V_8 , V_9 ) ;
V_2 -> V_10 = F_1 ;
F_9 ( V_2 , F_5 ( V_3 ) ,
V_11 ) ;
}
static int F_10 ( void )
{
F_11 () ;
V_7 = 1 ;
F_12 ( F_6 , NULL , 1 ) ;
F_13 () ;
return 0 ;
}
static void F_14 ( int V_12 )
{
struct V_2 * V_2 = & F_15 ( V_6 , V_12 ) ;
if ( ! V_7 )
return;
F_16 ( V_2 ) ;
}
static void F_17 ( void )
{
int V_12 ;
F_11 () ;
F_18 (cpu)
F_14 ( V_12 ) ;
V_7 = 0 ;
F_13 () ;
}
static int F_19 ( unsigned int V_12 )
{
F_20 () ;
F_6 ( NULL ) ;
F_21 () ;
return 0 ;
}
static int F_22 ( unsigned int V_12 )
{
F_14 ( V_12 ) ;
return 0 ;
}
static int F_23 ( void )
{
int V_13 ;
V_13 = F_24 ( V_14 ,
L_1 ,
F_19 ,
F_22 ) ;
if ( V_13 < 0 )
return V_13 ;
V_15 = V_13 ;
return 0 ;
}
static void F_25 ( void )
{
F_26 ( V_15 ) ;
}
int F_27 ( struct V_16 * V_17 )
{
V_17 -> V_18 = NULL ;
V_17 -> V_19 = F_23 ;
V_17 -> V_20 = F_25 ;
V_17 -> V_21 = F_10 ;
V_17 -> V_22 = F_17 ;
V_17 -> V_23 = L_2 ;
F_28 ( V_24 L_3 ) ;
return 0 ;
}
