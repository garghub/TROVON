int F_1 ( T_1 * V_1 , int V_2 , T_2 * V_3 , T_3 * V_4 )
{
T_4 * V_5 ;
* V_4 = 0 ;
if ( V_1 == NULL ) {
return - 1 ;
}
V_5 = F_2 ( V_1 , V_2 ) ;
if ( V_5 == NULL ) {
return - 1 ;
}
* V_4 = F_3 ( V_5 ) ;
for ( T_3 V_6 = 0 ; V_6 < * V_4 && V_6 < V_7 ; V_6 ++ )
{
V_3 [ V_6 ] = F_4 ( & ( ( V_8 * ) V_5 -> V_9 [ V_6 ] ) -> V_10 ) ;
}
return 0 ;
}
int F_5 ( T_1 * V_1 , int V_2 , T_5 * V_3 , T_3 * V_4 )
{
T_4 * V_5 ;
* V_4 = 0 ;
if ( V_1 == NULL ) {
return - 1 ;
}
V_5 = F_2 ( V_1 , V_2 ) ;
if ( V_5 == NULL ) {
return - 1 ;
}
* V_4 = F_3 ( V_5 ) ;
for ( T_3 V_6 = 0 ; V_6 < * V_4 && V_6 < V_7 ; V_6 ++ )
{
V_3 [ V_6 ] = F_6 ( & ( ( V_8 * ) V_5 -> V_9 [ V_6 ] ) -> V_10 ) ;
}
return 0 ;
}
int F_7 ( T_1 * V_1 , int V_2 , T_5 * V_3 , T_3 * V_4 )
{
T_4 * V_5 ;
* V_4 = 0 ;
if ( V_1 == NULL ) {
return - 1 ;
}
V_5 = F_2 ( V_1 , V_2 ) ;
if ( V_5 == NULL ) {
return - 1 ;
}
* V_4 = F_3 ( V_5 ) ;
for ( T_3 V_6 = 0 ; V_6 < * V_4 && V_6 < V_7 ; V_6 ++ )
{
V_3 [ V_6 ] = F_8 ( & ( ( V_8 * ) V_5 -> V_9 [ V_6 ] ) -> V_10 ) ;
}
return 0 ;
}
int F_9 ( T_1 * V_1 , int V_2 , T_6 * V_3 , T_3 * V_4 )
{
T_4 * V_5 ;
* V_4 = 0 ;
if ( V_1 == NULL ) {
return - 1 ;
}
V_5 = F_2 ( V_1 , V_2 ) ;
if ( V_5 == NULL ) {
return - 1 ;
}
* V_4 = F_3 ( V_5 ) ;
for ( T_3 V_6 = 0 ; V_6 < * V_4 && V_6 < V_7 ; V_6 ++ )
{
T_7 * V_11 = & ( ( ( V_8 * ) V_5 -> V_9 [ V_6 ] ) -> V_10 ) ;
if ( V_11 -> V_10 . V_12 )
V_3 [ V_6 ] = TRUE ;
else
V_3 [ V_6 ] = FALSE ;
}
return 0 ;
}
