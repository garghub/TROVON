struct V_1 * F_1 ( const void T_1 * V_2 , int V_3 )
{
struct V_1 * V_4 ;
struct V_5 * * V_6 ;
int V_7 ;
int V_8 ;
V_8 = V_3 ;
if ( V_8 > V_9 )
V_8 = V_9 ;
V_4 = F_2 ( sizeof( * V_4 ) + V_8 , V_10 ) ;
if ( V_4 == NULL )
return F_3 ( - V_11 ) ;
V_4 -> V_12 = NULL ;
V_4 -> V_13 = NULL ;
if ( F_4 ( V_4 + 1 , V_2 , V_8 ) ) {
V_7 = - V_14 ;
goto V_15;
}
V_3 -= V_8 ;
V_2 = ( ( char T_1 * ) V_2 ) + V_8 ;
V_6 = & V_4 -> V_12 ;
while ( V_3 > 0 ) {
struct V_5 * V_16 ;
V_8 = V_3 ;
if ( V_8 > V_17 )
V_8 = V_17 ;
V_16 = F_2 ( sizeof( * V_16 ) + V_8 ,
V_10 ) ;
if ( V_16 == NULL ) {
V_7 = - V_11 ;
goto V_15;
}
* V_6 = V_16 ;
V_16 -> V_12 = NULL ;
if ( F_4 ( V_16 + 1 , V_2 , V_8 ) ) {
V_7 = - V_14 ;
goto V_15;
}
V_6 = & V_16 -> V_12 ;
V_3 -= V_8 ;
V_2 = ( ( char T_1 * ) V_2 ) + V_8 ;
}
V_7 = F_5 ( V_4 ) ;
if ( V_7 )
goto V_15;
return V_4 ;
V_15:
F_6 ( V_4 ) ;
return F_3 ( V_7 ) ;
}
int F_7 ( void T_1 * V_18 , struct V_1 * V_4 , int V_3 )
{
int V_8 ;
struct V_5 * V_16 ;
V_8 = V_3 ;
if ( V_8 > V_9 )
V_8 = V_9 ;
if ( F_8 ( V_18 , V_4 + 1 , V_8 ) )
return - 1 ;
V_3 -= V_8 ;
V_18 = ( ( char T_1 * ) V_18 ) + V_8 ;
V_16 = V_4 -> V_12 ;
while ( V_3 > 0 ) {
V_8 = V_3 ;
if ( V_8 > V_17 )
V_8 = V_17 ;
if ( F_8 ( V_18 , V_16 + 1 , V_8 ) )
return - 1 ;
V_3 -= V_8 ;
V_18 = ( ( char T_1 * ) V_18 ) + V_8 ;
V_16 = V_16 -> V_12 ;
}
return 0 ;
}
void F_6 ( struct V_1 * V_4 )
{
struct V_5 * V_16 ;
F_9 ( V_4 ) ;
V_16 = V_4 -> V_12 ;
F_10 ( V_4 ) ;
while ( V_16 != NULL ) {
struct V_5 * V_19 = V_16 -> V_12 ;
F_10 ( V_16 ) ;
V_16 = V_19 ;
}
}
