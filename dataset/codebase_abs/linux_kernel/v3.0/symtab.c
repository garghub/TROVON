static unsigned int F_1 ( struct V_1 * V_2 , const void * V_3 )
{
const char * V_4 , * V_5 ;
unsigned int V_6 ;
unsigned int V_7 ;
V_7 = 0 ;
V_5 = V_3 ;
V_6 = strlen ( V_5 ) ;
for ( V_4 = V_5 ; ( V_4 - V_5 ) < V_6 ; V_4 ++ )
V_7 = ( V_7 << 4 | ( V_7 >> ( 8 *sizeof( unsigned int ) - 4 ) ) ) ^ ( * V_4 ) ;
return V_7 & ( V_2 -> V_6 - 1 ) ;
}
static int F_2 ( struct V_1 * V_2 , const void * V_8 , const void * V_9 )
{
const char * V_10 , * V_11 ;
V_10 = V_8 ;
V_11 = V_9 ;
return strcmp ( V_10 , V_11 ) ;
}
int F_3 ( struct V_12 * V_13 , unsigned int V_6 )
{
V_13 -> V_14 = F_4 ( F_1 , F_2 , V_6 ) ;
if ( ! V_13 -> V_14 )
return - V_15 ;
V_13 -> V_16 = 0 ;
return 0 ;
}
