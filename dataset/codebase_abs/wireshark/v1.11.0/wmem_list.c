T_1
F_1 ( const T_2 * V_1 )
{
return V_1 -> V_2 ;
}
T_3 *
F_2 ( const T_2 * V_1 )
{
return V_1 -> V_3 ;
}
T_3 *
F_3 ( const T_2 * V_1 )
{
return V_1 -> V_4 ;
}
T_3 *
F_4 ( const T_3 * V_5 )
{
return V_5 -> V_6 ;
}
T_3 *
F_5 ( const T_3 * V_5 )
{
return V_5 -> V_7 ;
}
void *
F_6 ( const T_3 * V_5 )
{
return V_5 -> V_8 ;
}
void
F_7 ( T_2 * V_1 , void * V_8 )
{
T_3 * V_5 ;
V_5 = V_1 -> V_3 ;
while ( V_5 && V_5 -> V_8 != V_8 ) {
V_5 = V_5 -> V_6 ;
}
if ( V_5 == NULL ) {
return;
}
if ( V_5 -> V_7 ) {
V_5 -> V_7 -> V_6 = V_5 -> V_6 ;
}
else {
V_1 -> V_3 = V_5 -> V_6 ;
}
if ( V_5 -> V_6 ) {
V_5 -> V_6 -> V_7 = V_5 -> V_7 ;
}
else {
V_1 -> V_4 = V_5 -> V_7 ;
}
V_1 -> V_2 -- ;
F_8 ( V_1 -> V_9 , V_5 ) ;
}
void
F_9 ( T_2 * V_1 , void * V_8 )
{
T_3 * V_10 ;
V_10 = F_10 ( V_1 -> V_9 , T_3 ) ;
V_10 -> V_8 = V_8 ;
V_10 -> V_6 = V_1 -> V_3 ;
V_10 -> V_7 = NULL ;
if ( V_1 -> V_3 ) {
V_1 -> V_3 -> V_7 = V_10 ;
}
else {
V_1 -> V_4 = V_10 ;
}
V_1 -> V_3 = V_10 ;
V_1 -> V_2 ++ ;
}
void
F_11 ( T_2 * V_1 , void * V_8 )
{
T_3 * V_10 ;
V_10 = F_10 ( V_1 -> V_9 , T_3 ) ;
V_10 -> V_8 = V_8 ;
V_10 -> V_6 = NULL ;
V_10 -> V_7 = V_1 -> V_4 ;
if ( V_1 -> V_4 ) {
V_1 -> V_4 -> V_6 = V_10 ;
}
else {
V_1 -> V_3 = V_10 ;
}
V_1 -> V_4 = V_10 ;
V_1 -> V_2 ++ ;
}
T_2 *
F_12 ( T_4 * V_9 )
{
T_2 * V_1 ;
V_1 = F_10 ( V_9 , T_2 ) ;
V_1 -> V_2 = 0 ;
V_1 -> V_3 = NULL ;
V_1 -> V_4 = NULL ;
V_1 -> V_9 = V_9 ;
return V_1 ;
}
