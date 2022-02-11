static struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
struct V_4 * * V_5 ;
T_1 V_6 ;
V_6 = F_2 ( V_2 , V_7 ) ;
V_3 = F_3 ( sizeof( * V_3 ) + V_6 , V_8 ) ;
if ( V_3 == NULL )
return NULL ;
V_3 -> V_9 = NULL ;
V_3 -> V_10 = NULL ;
V_2 -= V_6 ;
V_5 = & V_3 -> V_9 ;
while ( V_2 > 0 ) {
struct V_4 * V_11 ;
V_6 = F_2 ( V_2 , V_12 ) ;
V_11 = F_3 ( sizeof( * V_11 ) + V_6 , V_8 ) ;
if ( V_11 == NULL )
goto V_13;
* V_5 = V_11 ;
V_11 -> V_9 = NULL ;
V_5 = & V_11 -> V_9 ;
V_2 -= V_6 ;
}
return V_3 ;
V_13:
F_4 ( V_3 ) ;
return NULL ;
}
struct V_1 * F_5 ( const void T_2 * V_14 , T_1 V_2 )
{
struct V_1 * V_3 ;
struct V_4 * V_11 ;
int V_15 = - V_16 ;
T_1 V_6 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 == NULL )
return F_6 ( - V_17 ) ;
V_6 = F_2 ( V_2 , V_7 ) ;
if ( F_7 ( V_3 + 1 , V_14 , V_6 ) )
goto V_13;
for ( V_11 = V_3 -> V_9 ; V_11 != NULL ; V_11 = V_11 -> V_9 ) {
V_2 -= V_6 ;
V_14 = ( char T_2 * ) V_14 + V_6 ;
V_6 = F_2 ( V_2 , V_12 ) ;
if ( F_7 ( V_11 + 1 , V_14 , V_6 ) )
goto V_13;
}
V_15 = F_8 ( V_3 ) ;
if ( V_15 )
goto V_13;
return V_3 ;
V_13:
F_4 ( V_3 ) ;
return F_6 ( V_15 ) ;
}
struct V_1 * F_9 ( struct V_1 * V_14 , struct V_1 * V_18 )
{
struct V_4 * V_19 , * V_20 ;
T_1 V_2 = V_14 -> V_21 ;
T_1 V_6 ;
F_10 ( V_18 == NULL ) ;
if ( V_14 -> V_21 > V_18 -> V_21 )
return F_6 ( - V_22 ) ;
V_6 = F_2 ( V_2 , V_7 ) ;
memcpy ( V_18 + 1 , V_14 + 1 , V_6 ) ;
for ( V_19 = V_18 -> V_9 , V_20 = V_14 -> V_9 ;
V_20 != NULL ;
V_19 = V_19 -> V_9 , V_20 = V_20 -> V_9 ) {
V_2 -= V_6 ;
V_6 = F_2 ( V_2 , V_12 ) ;
memcpy ( V_19 + 1 , V_20 + 1 , V_6 ) ;
}
V_18 -> V_23 = V_14 -> V_23 ;
V_18 -> V_21 = V_14 -> V_21 ;
return V_18 ;
}
struct V_1 * F_9 ( struct V_1 * V_14 , struct V_1 * V_18 )
{
return F_6 ( - V_24 ) ;
}
int F_11 ( void T_2 * V_25 , struct V_1 * V_3 , T_1 V_2 )
{
T_1 V_6 ;
struct V_4 * V_11 ;
V_6 = F_2 ( V_2 , V_7 ) ;
if ( F_12 ( V_25 , V_3 + 1 , V_6 ) )
return - 1 ;
for ( V_11 = V_3 -> V_9 ; V_11 != NULL ; V_11 = V_11 -> V_9 ) {
V_2 -= V_6 ;
V_25 = ( char T_2 * ) V_25 + V_6 ;
V_6 = F_2 ( V_2 , V_12 ) ;
if ( F_12 ( V_25 , V_11 + 1 , V_6 ) )
return - 1 ;
}
return 0 ;
}
void F_4 ( struct V_1 * V_3 )
{
struct V_4 * V_11 ;
F_13 ( V_3 ) ;
V_11 = V_3 -> V_9 ;
F_14 ( V_3 ) ;
while ( V_11 != NULL ) {
struct V_4 * V_26 = V_11 -> V_9 ;
F_14 ( V_11 ) ;
V_11 = V_26 ;
}
}
