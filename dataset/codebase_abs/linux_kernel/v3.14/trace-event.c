int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 () ;
if ( V_3 ) {
V_2 -> V_4 = F_3 ( V_3 ) ;
V_2 -> V_3 = V_3 ;
}
return V_3 ? 0 : - 1 ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 -> V_4 , V_2 -> V_3 ) ;
F_6 ( V_2 -> V_3 ) ;
}
static struct V_5 *
F_7 ( const char * V_6 , const char * V_7 )
{
struct V_3 * V_3 = V_8 . V_3 ;
struct V_5 * V_9 = NULL ;
char V_10 [ V_11 ] ;
T_1 V_12 ;
char * V_13 ;
F_8 ( V_10 , V_11 , L_1 ,
V_14 , V_6 , V_7 ) ;
if ( F_9 ( V_10 , & V_13 , & V_12 ) )
return NULL ;
F_10 ( V_3 , & V_9 , V_13 , V_12 , V_6 ) ;
free ( V_13 ) ;
return V_9 ;
}
struct V_5 *
F_11 ( const char * V_6 , const char * V_7 )
{
static bool V_15 ;
if ( ! V_15 ) {
int V_16 = F_12 () ;
struct V_3 * V_3 ;
if ( F_1 ( & V_8 ) )
return NULL ;
V_3 = V_8 . V_3 ;
F_13 ( V_3 , V_17 ) ;
F_14 ( V_3 , V_16 ) ;
F_15 ( V_3 , V_16 ) ;
V_15 = true ;
}
return F_7 ( V_6 , V_7 ) ;
}
