struct V_1 * F_1 ( int V_2 , const char * V_3 )
{
struct V_1 * V_4 ;
int V_5 ;
if ( V_2 < 0 )
return NULL ;
V_4 = F_2 ( sizeof( * V_4 ) , V_6 ) ;
if ( ! V_4 )
return V_4 ;
V_4 -> V_7 = V_2 ;
if ( V_4 -> V_7 >= F_3 ( V_8 ) )
goto V_9;
V_4 -> V_10 = V_8 [ V_4 -> V_7 ] ;
V_5 = F_4 ( V_4 -> V_10 , V_3 ) ;
if ( V_5 )
goto V_9;
return V_4 ;
V_9:
F_5 ( V_4 ) ;
return NULL ;
}
void F_6 ( struct V_1 * V_4 )
{
F_7 ( V_4 -> V_10 ) ;
F_5 ( V_4 ) ;
}
int F_8 ( struct V_1 * V_4 , int V_11 , int V_12 )
{
unsigned long V_13 , V_14 ;
unsigned long long V_15 ;
if ( V_11 < 0 || V_11 > V_12 )
return - V_16 ;
V_15 = ( unsigned long long ) F_9 () * V_12 ;
F_10 ( V_15 , V_17 ) ;
V_13 = V_15 ;
V_15 = ( unsigned long long ) V_13 * V_11 ;
F_10 ( V_15 , V_12 ) ;
V_14 = V_13 - V_15 ;
if ( V_14 >= V_13 )
V_14 = V_13 - 1 ;
F_11 ( V_4 -> V_7 , V_18 | V_19 ) ;
F_12 ( V_4 -> V_7 , V_14 ) ;
F_13 ( V_4 -> V_7 , V_13 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_4 )
{
F_15 ( V_4 -> V_7 ) ;
return 0 ;
}
void F_16 ( struct V_1 * V_4 )
{
F_17 ( V_4 -> V_7 ) ;
}
