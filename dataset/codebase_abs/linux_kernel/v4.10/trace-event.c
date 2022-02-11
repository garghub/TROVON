int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 () ;
if ( V_3 ) {
V_2 -> V_4 = F_3 ( V_3 ) ;
V_2 -> V_3 = V_3 ;
}
return V_3 ? 0 : - 1 ;
}
static int F_4 ( void )
{
int V_5 = F_5 () ;
struct V_3 * V_3 ;
if ( F_1 ( & V_6 ) )
return - 1 ;
V_3 = V_6 . V_3 ;
F_6 ( V_3 , V_7 ) ;
F_7 ( V_3 , V_5 ) ;
F_8 ( V_3 , V_5 ) ;
V_8 = true ;
return 0 ;
}
int F_9 ( struct V_9 * V_9 ,
T_1 * V_10 )
{
if ( ! V_8 && F_4 () )
return - 1 ;
return F_10 ( V_6 . V_3 , V_10 , V_9 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 -> V_4 , V_2 -> V_3 ) ;
F_13 ( V_2 -> V_3 ) ;
}
static struct V_11 *
F_14 ( const char * V_12 , const char * V_13 )
{
struct V_3 * V_3 = V_6 . V_3 ;
struct V_11 * V_14 = NULL ;
char V_15 [ V_16 ] ;
T_2 V_17 ;
char * V_18 ;
int V_19 ;
F_15 ( V_15 , V_16 , L_1 ,
V_20 , V_12 , V_13 ) ;
V_19 = F_16 ( V_15 , & V_18 , & V_17 ) ;
if ( V_19 )
return F_17 ( V_19 ) ;
F_18 ( V_3 , & V_14 , V_18 , V_17 , V_12 ) ;
free ( V_18 ) ;
return V_14 ;
}
struct V_11 *
F_19 ( const char * V_12 , const char * V_13 )
{
if ( ! V_8 && F_4 () )
return F_17 ( - V_21 ) ;
return F_14 ( V_12 , V_13 ) ;
}
struct V_11 * F_20 ( int V_22 )
{
if ( ! V_8 && F_4 () )
return F_17 ( - V_21 ) ;
return F_21 ( V_6 . V_3 , V_22 ) ;
}
