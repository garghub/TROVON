static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 = * ( V_5 * ) V_3 ;
if ( V_4 < V_6 ) {
if ( V_4 == 0 )
F_2 ( V_2 , L_1 ) ;
F_3 ( V_2 , V_4 ) ;
}
#ifdef F_4
else {
V_4 -= V_6 ;
if ( V_4 == 0 )
F_2 ( V_2 , L_2 ) ;
F_5 ( V_2 , V_4 ) ;
}
#endif
return 0 ;
}
static void * F_6 ( struct V_1 * V_2 , V_5 * V_7 )
{
if ( * V_7 < ( V_8 + V_6 ) )
return V_7 ;
return NULL ;
}
static void * F_7 ( struct V_1 * V_2 , void * V_3 , V_5 * V_7 )
{
( * V_7 ) ++ ;
if ( * V_7 >= ( V_8 + V_6 ) )
return NULL ;
return V_7 ;
}
static void F_8 ( struct V_1 * V_2 , void * V_3 )
{
}
static int F_9 ( struct V_9 * V_9 , struct V_10 * V_11 )
{
return F_10 ( V_11 , & V_12 ) ;
}
static int T_1 F_11 ( void )
{
F_12 ( L_3 , 0 , NULL , & V_13 ) ;
return 0 ;
}
