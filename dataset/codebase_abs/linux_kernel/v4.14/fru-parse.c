static struct V_1 *
F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 ;
struct V_1 * V_7 ;
V_6 = F_2 ( V_3 ) ;
V_7 = V_6 -> V_7 ;
while ( V_4 > 0 && ! F_3 ( V_7 ) ) {
V_7 = F_4 ( V_7 ) ;
V_4 -- ;
}
if ( F_3 ( V_7 ) )
return NULL ;
return V_7 ;
}
static char * F_5 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_7 ;
char * V_8 ;
V_7 = F_1 ( V_3 , V_4 ) ;
if ( ! V_7 )
return NULL ;
V_8 = F_6 ( F_7 ( V_7 ) + 1 ) ;
if ( ! V_8 )
return NULL ;
return F_8 ( V_8 , V_7 ) ;
}
int F_9 ( struct V_2 * V_3 )
{
T_1 * V_9 = ( void * ) V_3 ;
int V_10 , V_11 ;
for ( V_10 = V_11 = 0 ; V_10 < sizeof( * V_3 ) ; V_10 ++ )
V_11 += V_9 [ V_10 ] ;
return ( V_11 & 0xff ) == 0 ;
}
int F_10 ( struct V_5 * V_6 )
{
T_1 * V_9 = ( void * ) V_6 ;
int V_10 , V_11 ;
for ( V_10 = V_11 = 0 ; V_10 < 8 * V_6 -> V_12 ; V_10 ++ )
V_11 += V_9 [ V_10 ] ;
return ( V_11 & 0xff ) == 0 ;
}
char * F_11 ( struct V_2 * V_3 )
{
return F_5 ( V_3 , 0 ) ;
}
char * F_12 ( struct V_2 * V_3 )
{
return F_5 ( V_3 , 1 ) ;
}
char * F_13 ( struct V_2 * V_3 )
{
return F_5 ( V_3 , 2 ) ;
}
char * F_14 ( struct V_2 * V_3 )
{
return F_5 ( V_3 , 3 ) ;
}
