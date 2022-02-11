static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
V_2 -> V_7 . V_8 = 0 ;
F_2 ( V_6 , 0 ) ;
}
static int F_3 ( int V_9 )
{
struct V_1 * V_2 = F_4 ( V_10 , V_9 ) ;
if ( ! V_2 ) {
V_2 = F_5 ( & V_11 , V_9 , NULL ,
F_1 , NULL ) ;
if ( F_6 ( V_2 ) )
return F_7 ( V_2 ) ;
F_4 ( V_10 , V_9 ) = V_2 ;
}
if ( V_2 && V_12 )
F_8 ( V_2 ) ;
return 0 ;
}
static void F_9 ( int V_9 )
{
struct V_1 * V_2 = F_4 ( V_10 , V_9 ) ;
if ( V_2 && V_12 )
F_10 ( V_2 ) ;
}
static int F_11 ( unsigned int V_9 )
{
F_3 ( V_9 ) ;
return 0 ;
}
static int F_12 ( unsigned int V_9 )
{
F_9 ( V_9 ) ;
return 0 ;
}
static int F_13 ( void )
{
int V_9 ;
F_14 () ;
V_12 = 1 ;
F_15 (cpu)
F_3 ( V_9 ) ;
F_16 () ;
return 0 ;
}
static void F_17 ( void )
{
int V_9 ;
F_14 () ;
F_15 (cpu)
F_9 ( V_9 ) ;
V_12 = 0 ;
F_16 () ;
}
static void F_18 ( void )
{
struct V_1 * V_2 ;
int V_9 ;
F_19 ( V_13 ) ;
F_20 (cpu) {
V_2 = F_4 ( V_10 , V_9 ) ;
if ( ! V_2 )
continue;
F_10 ( V_2 ) ;
F_4 ( V_10 , V_9 ) = NULL ;
F_21 ( V_2 ) ;
}
}
static int F_22 ( void )
{
int V_14 ;
T_1 V_15 ;
V_15 = ( T_1 ) V_16 * 1000 ;
F_23 ( V_15 , V_17 ) ;
V_11 . V_18 = V_15 ;
V_14 = F_24 ( V_19 , L_1 ,
F_11 , F_12 ) ;
if ( V_14 < 0 ) {
F_18 () ;
return V_14 ;
}
V_13 = V_14 ;
return 0 ;
}
int T_2 F_25 ( struct V_20 * V_21 )
{
int V_14 = 0 ;
V_14 = F_22 () ;
if ( V_14 )
return V_14 ;
F_18 () ;
V_21 -> V_22 = NULL ;
V_21 -> V_23 = F_22 ;
V_21 -> V_24 = F_18 ;
V_21 -> V_25 = F_13 ;
V_21 -> V_26 = F_17 ;
V_21 -> V_27 = L_2 ;
F_26 ( V_28 L_3 ) ;
return 0 ;
}
