static void F_1 ( void * V_1 )
{
F_2 ( V_2 L_1 ) ;
F_3 ( NULL ) ;
}
static void F_4 ( void * V_1 )
{
F_2 ( V_2 L_2 ) ;
}
static void F_5 ( void * V_1 )
{
F_2 ( V_2 L_3 ) ;
}
static void F_6 ( void * V_1 )
{
F_2 ( V_2
L_4 ) ;
}
static T_1 F_7 ( int V_3 , void * V_1 )
{
struct V_4 * V_5 = V_1 ;
unsigned long V_6 = * V_7 ;
if ( F_8 ( V_6 , V_5 -> V_8 ) ) {
F_9 ( V_6 , V_5 -> V_8 ) ;
V_5 -> V_9 ( V_5 -> V_1 ) ;
} else {
F_10 ( V_6 , V_5 -> V_8 ) ;
V_5 -> V_10 ( V_5 -> V_1 ) ;
}
* V_7 = V_6 ;
return V_11 ;
}
static int F_11 ( struct V_4 * V_5 )
{
unsigned long V_6 ;
if ( V_5 -> V_9 == NULL || V_5 -> V_10 == NULL )
return - V_12 ;
V_6 = * V_7 ;
F_12 ( V_6 , V_5 -> V_8 ) ;
if ( V_5 -> V_13 == V_14 )
F_9 ( V_6 , V_5 -> V_8 ) ;
else
F_10 ( V_6 , V_5 -> V_8 ) ;
* V_7 = V_6 ;
return F_13 ( V_5 -> V_3 , F_7 , V_15 ,
V_5 -> V_16 , V_5 ) ;
}
static int T_2 F_14 ( void )
{
#ifdef F_15
F_11 ( & V_17 ) ;
F_11 ( & V_18 ) ;
#endif
return 0 ;
}
