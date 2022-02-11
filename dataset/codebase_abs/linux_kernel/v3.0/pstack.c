struct V_1 * F_1 ( unsigned short V_2 )
{
struct V_1 * V_3 = F_2 ( ( sizeof( * V_3 ) +
V_2 * sizeof( void * ) ) ) ;
if ( V_3 != NULL )
V_3 -> V_2 = V_2 ;
return V_3 ;
}
void F_3 ( struct V_1 * V_3 )
{
free ( V_3 ) ;
}
bool F_4 ( const struct V_1 * V_3 )
{
return V_3 -> V_4 == 0 ;
}
void F_5 ( struct V_1 * V_3 , void * V_5 )
{
unsigned short V_6 = V_3 -> V_4 , V_7 = V_3 -> V_4 - 1 ;
while ( V_6 -- != 0 ) {
if ( V_3 -> V_8 [ V_6 ] == V_5 ) {
if ( V_6 < V_7 )
memmove ( V_3 -> V_8 + V_6 ,
V_3 -> V_8 + V_6 + 1 ,
( V_7 - V_6 ) * sizeof( void * ) ) ;
-- V_3 -> V_4 ;
return;
}
}
F_6 ( L_1 , V_9 , V_5 ) ;
}
void F_7 ( struct V_1 * V_3 , void * V_5 )
{
if ( V_3 -> V_4 == V_3 -> V_2 ) {
F_6 ( L_2 , V_9 , V_3 -> V_4 ) ;
return;
}
V_3 -> V_8 [ V_3 -> V_4 ++ ] = V_5 ;
}
void * F_8 ( struct V_1 * V_3 )
{
void * V_10 ;
if ( V_3 -> V_4 == 0 ) {
F_6 ( L_3 , V_9 ) ;
return NULL ;
}
V_10 = V_3 -> V_8 [ -- V_3 -> V_4 ] ;
V_3 -> V_8 [ V_3 -> V_4 ] = NULL ;
return V_10 ;
}
