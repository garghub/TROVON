static enum V_1 F_1 ( struct V_2 * V_2 )
{
F_2 ( F_3 () , 0 ) ;
F_4 ( V_2 , F_5 ( V_3 ) ) ;
return V_4 ;
}
static void F_6 ( void * V_5 )
{
struct V_2 * V_2 = & F_7 ( V_6 ) ;
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
static int T_1 F_19 ( struct V_13 * V_14 ,
unsigned long V_15 , void * V_16 )
{
long V_12 = ( long ) V_16 ;
switch ( V_15 ) {
case V_17 :
case V_18 :
F_20 ( V_12 , F_6 ,
NULL , 1 ) ;
break;
case V_19 :
case V_20 :
F_14 ( V_12 ) ;
break;
}
return V_21 ;
}
int F_21 ( struct V_22 * V_23 )
{
int V_24 ;
V_24 = F_22 ( & V_25 ) ;
if ( V_24 )
return V_24 ;
V_23 -> V_26 = NULL ;
V_23 -> V_27 = NULL ;
V_23 -> V_28 = NULL ;
V_23 -> V_29 = F_10 ;
V_23 -> V_30 = F_17 ;
V_23 -> V_31 = L_1 ;
F_23 ( V_32 L_2 ) ;
return 0 ;
}
void F_24 ( void )
{
F_25 ( & V_25 ) ;
}
