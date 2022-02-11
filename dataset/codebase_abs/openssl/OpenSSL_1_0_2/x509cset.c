int F_1 ( T_1 * V_1 , long V_2 )
{
if ( V_1 == NULL )
return ( 0 ) ;
if ( V_1 -> V_3 -> V_2 == NULL ) {
if ( ( V_1 -> V_3 -> V_2 = F_2 () ) == NULL )
return ( 0 ) ;
}
return ( F_3 ( V_1 -> V_3 -> V_2 , V_2 ) ) ;
}
int F_4 ( T_1 * V_1 , T_2 * V_4 )
{
if ( ( V_1 == NULL ) || ( V_1 -> V_3 == NULL ) )
return ( 0 ) ;
return ( F_5 ( & V_1 -> V_3 -> V_5 , V_4 ) ) ;
}
int F_6 ( T_1 * V_1 , const T_3 * V_6 )
{
T_3 * V_7 ;
if ( V_1 == NULL )
return ( 0 ) ;
V_7 = V_1 -> V_3 -> V_8 ;
if ( V_7 != V_6 ) {
V_7 = F_7 ( V_6 ) ;
if ( V_7 != NULL ) {
F_8 ( V_1 -> V_3 -> V_8 ) ;
V_1 -> V_3 -> V_8 = V_7 ;
}
}
return ( V_7 != NULL ) ;
}
int F_9 ( T_1 * V_1 , const T_3 * V_6 )
{
T_3 * V_7 ;
if ( V_1 == NULL )
return ( 0 ) ;
V_7 = V_1 -> V_3 -> V_9 ;
if ( V_7 != V_6 ) {
V_7 = F_7 ( V_6 ) ;
if ( V_7 != NULL ) {
F_8 ( V_1 -> V_3 -> V_9 ) ;
V_1 -> V_3 -> V_9 = V_7 ;
}
}
return ( V_7 != NULL ) ;
}
int F_10 ( T_1 * V_10 )
{
int V_11 ;
T_4 * V_12 ;
F_11 ( V_10 -> V_3 -> V_13 ) ;
for ( V_11 = 0 ; V_11 < F_12 ( V_10 -> V_3 -> V_13 ) ; V_11 ++ ) {
V_12 = F_13 ( V_10 -> V_3 -> V_13 , V_11 ) ;
V_12 -> V_14 = V_11 ;
}
V_10 -> V_3 -> V_15 . V_16 = 1 ;
return 1 ;
}
int F_14 ( T_4 * V_1 , T_3 * V_6 )
{
T_3 * V_7 ;
if ( V_1 == NULL )
return ( 0 ) ;
V_7 = V_1 -> V_17 ;
if ( V_7 != V_6 ) {
V_7 = F_7 ( V_6 ) ;
if ( V_7 != NULL ) {
F_8 ( V_1 -> V_17 ) ;
V_1 -> V_17 = V_7 ;
}
}
return ( V_7 != NULL ) ;
}
int F_15 ( T_4 * V_1 , T_5 * V_18 )
{
T_5 * V_7 ;
if ( V_1 == NULL )
return ( 0 ) ;
V_7 = V_1 -> V_19 ;
if ( V_7 != V_18 ) {
V_7 = F_16 ( V_18 ) ;
if ( V_7 != NULL ) {
F_17 ( V_1 -> V_19 ) ;
V_1 -> V_19 = V_7 ;
}
}
return ( V_7 != NULL ) ;
}
