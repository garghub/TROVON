int F_1 ( void * V_1 , int V_2 , const char * V_3 ,
const void * V_4 , int V_5 )
{
void * V_6 ;
int V_7 ;
V_6 = F_2 ( V_1 , V_2 , V_3 , & V_7 ) ;
if ( ! V_6 )
return V_7 ;
if ( V_7 != V_5 )
return - V_8 ;
memcpy ( V_6 , V_4 , V_5 ) ;
return 0 ;
}
static void F_3 ( void * V_9 , int V_5 )
{
T_1 * V_10 ;
for ( V_10 = V_9 ; ( char * ) V_10 < ( ( char * ) V_9 + V_5 ) ; V_10 ++ )
* V_10 = F_4 ( V_11 ) ;
}
int F_5 ( void * V_1 , int V_2 , const char * V_3 )
{
struct V_12 * V_13 ;
int V_5 ;
V_13 = F_6 ( V_1 , V_2 , V_3 , & V_5 ) ;
if ( ! V_13 )
return V_5 ;
F_3 ( V_13 , V_5 + sizeof( * V_13 ) ) ;
return 0 ;
}
int F_7 ( void * V_1 , int V_14 )
{
int V_15 = 0 ;
while ( ( V_14 >= 0 ) && ( V_15 >= 0 ) )
V_14 = F_8 ( V_1 , V_14 , & V_15 ) ;
return V_14 ;
}
int F_9 ( void * V_1 , int V_2 )
{
int V_16 ;
V_16 = F_7 ( V_1 , V_2 ) ;
if ( V_16 < 0 )
return V_16 ;
F_3 ( F_10 ( V_1 , V_2 , 0 ) ,
V_16 - V_2 ) ;
return 0 ;
}
