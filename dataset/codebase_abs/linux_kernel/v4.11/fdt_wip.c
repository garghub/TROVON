int F_1 ( void * V_1 , int V_2 ,
const char * V_3 , int V_4 ,
T_1 V_5 , const void * V_6 ,
int V_7 )
{
void * V_8 ;
int V_9 ;
V_8 = F_2 ( V_1 , V_2 , V_3 , V_4 ,
& V_9 ) ;
if ( ! V_8 )
return V_9 ;
if ( V_9 < ( V_7 + V_5 ) )
return - V_10 ;
memcpy ( ( char * ) V_8 + V_5 , V_6 , V_7 ) ;
return 0 ;
}
int F_3 ( void * V_1 , int V_2 , const char * V_3 ,
const void * V_6 , int V_7 )
{
const void * V_8 ;
int V_9 ;
V_8 = F_4 ( V_1 , V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return V_9 ;
if ( V_9 != V_7 )
return - V_10 ;
return F_1 ( V_1 , V_2 , V_3 ,
strlen ( V_3 ) , 0 ,
V_6 , V_7 ) ;
}
static void F_5 ( void * V_11 , int V_7 )
{
T_2 * V_12 ;
for ( V_12 = V_11 ; ( char * ) V_12 < ( ( char * ) V_11 + V_7 ) ; V_12 ++ )
* V_12 = F_6 ( V_13 ) ;
}
int F_7 ( void * V_1 , int V_2 , const char * V_3 )
{
struct V_14 * V_15 ;
int V_7 ;
V_15 = F_8 ( V_1 , V_2 , V_3 , & V_7 ) ;
if ( ! V_15 )
return V_7 ;
F_5 ( V_15 , V_7 + sizeof( * V_15 ) ) ;
return 0 ;
}
int F_9 ( void * V_1 , int V_16 )
{
int V_17 = 0 ;
while ( ( V_16 >= 0 ) && ( V_17 >= 0 ) )
V_16 = F_10 ( V_1 , V_16 , & V_17 ) ;
return V_16 ;
}
int F_11 ( void * V_1 , int V_2 )
{
int V_18 ;
V_18 = F_9 ( V_1 , V_2 ) ;
if ( V_18 < 0 )
return V_18 ;
F_5 ( F_12 ( V_1 , V_2 , 0 ) ,
V_18 - V_2 ) ;
return 0 ;
}
