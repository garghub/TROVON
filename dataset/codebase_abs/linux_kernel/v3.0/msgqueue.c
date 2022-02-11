static struct V_1 * F_1 ( T_1 * V_2 )
{
struct V_1 * V_3 ;
if ( ( V_3 = V_2 -> free ) != NULL )
V_2 -> free = V_3 -> V_4 ;
return V_3 ;
}
static void F_2 ( T_1 * V_2 , struct V_1 * V_3 )
{
if ( V_3 ) {
V_3 -> V_4 = V_2 -> free ;
V_2 -> free = V_3 ;
}
}
void F_3 ( T_1 * V_2 )
{
int V_5 ;
V_2 -> V_6 = NULL ;
V_2 -> free = & V_2 -> V_7 [ 0 ] ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ )
V_2 -> V_7 [ V_5 ] . V_4 = & V_2 -> V_7 [ V_5 + 1 ] ;
V_2 -> V_7 [ V_8 - 1 ] . V_4 = NULL ;
}
void F_4 ( T_1 * V_2 )
{
}
int F_5 ( T_1 * V_2 )
{
struct V_1 * V_3 = V_2 -> V_6 ;
int V_9 = 0 ;
for ( V_3 = V_2 -> V_6 ; V_3 ; V_3 = V_3 -> V_4 )
V_9 += V_3 -> V_10 . V_9 ;
return V_9 ;
}
struct V_11 * F_6 ( T_1 * V_2 , int V_12 )
{
struct V_1 * V_3 ;
for ( V_3 = V_2 -> V_6 ; V_3 && V_12 ; V_3 = V_3 -> V_4 , V_12 -- ) ;
return V_3 ? & V_3 -> V_10 : NULL ;
}
int F_7 ( T_1 * V_2 , int V_9 , ... )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
T_2 V_13 ;
if ( V_3 ) {
struct V_1 * * V_14 ;
int V_5 ;
va_start ( V_13 , V_9 ) ;
for ( V_5 = 0 ; V_5 < V_9 ; V_5 ++ )
V_3 -> V_10 . V_10 [ V_5 ] = va_arg (ap, unsigned int) ;
va_end ( V_13 ) ;
V_3 -> V_10 . V_9 = V_9 ;
V_3 -> V_10 . V_15 = 0 ;
V_3 -> V_4 = NULL ;
V_14 = & V_2 -> V_6 ;
while ( * V_14 )
V_14 = & ( * V_14 ) -> V_4 ;
* V_14 = V_3 ;
}
return V_3 != NULL ;
}
void F_8 ( T_1 * V_2 )
{
struct V_1 * V_3 , * V_16 ;
for ( V_3 = V_2 -> V_6 ; V_3 ; V_3 = V_16 ) {
V_16 = V_3 -> V_4 ;
F_2 ( V_2 , V_3 ) ;
}
V_2 -> V_6 = NULL ;
}
