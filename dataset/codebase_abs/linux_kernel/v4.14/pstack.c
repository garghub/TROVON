struct V_1 * F_1 ( unsigned short V_2 )
{
struct V_1 * V_1 = F_2 ( ( sizeof( * V_1 ) +
V_2 * sizeof( void * ) ) ) ;
if ( V_1 != NULL )
V_1 -> V_2 = V_2 ;
return V_1 ;
}
void F_3 ( struct V_1 * V_1 )
{
free ( V_1 ) ;
}
bool F_4 ( const struct V_1 * V_1 )
{
return V_1 -> V_3 == 0 ;
}
void F_5 ( struct V_1 * V_1 , void * V_4 )
{
unsigned short V_5 = V_1 -> V_3 , V_6 = V_1 -> V_3 - 1 ;
while ( V_5 -- != 0 ) {
if ( V_1 -> V_7 [ V_5 ] == V_4 ) {
if ( V_5 < V_6 )
memmove ( V_1 -> V_7 + V_5 ,
V_1 -> V_7 + V_5 + 1 ,
( V_6 - V_5 ) * sizeof( void * ) ) ;
-- V_1 -> V_3 ;
return;
}
}
F_6 ( L_1 , V_8 , V_4 ) ;
}
void F_7 ( struct V_1 * V_1 , void * V_4 )
{
if ( V_1 -> V_3 == V_1 -> V_2 ) {
F_6 ( L_2 , V_8 , V_1 -> V_3 ) ;
return;
}
V_1 -> V_7 [ V_1 -> V_3 ++ ] = V_4 ;
}
void * F_8 ( struct V_1 * V_1 )
{
void * V_9 ;
if ( V_1 -> V_3 == 0 ) {
F_6 ( L_3 , V_8 ) ;
return NULL ;
}
V_9 = V_1 -> V_7 [ -- V_1 -> V_3 ] ;
V_1 -> V_7 [ V_1 -> V_3 ] = NULL ;
return V_9 ;
}
void * F_9 ( struct V_1 * V_1 )
{
if ( V_1 -> V_3 == 0 )
return NULL ;
return V_1 -> V_7 [ V_1 -> V_3 - 1 ] ;
}
