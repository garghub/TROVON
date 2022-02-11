void F_1 ( void * V_1 )
{
#ifdef F_2
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
int V_4 ;
int V_5 ;
switch ( V_3 -> V_6 . V_7 ) {
case V_8 :
{
V_3 -> V_9 [ 0 ] = F_3 ( V_3 -> V_9 [ 0 ] ) ;
break;
}
default:
V_5 = ( V_3 -> V_6 . V_10 -
sizeof( struct V_11 ) ) / 4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ )
V_3 -> V_9 [ V_4 ] = F_3 ( V_3 -> V_9 [ V_4 ] ) ;
break;
}
#endif
}
void F_4 ( void * V_1 )
{
#ifdef F_2
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
int V_4 ;
int V_5 ;
switch ( V_3 -> V_6 . V_7 ) {
case V_12 :
{
struct V_13 * V_14 =
(struct V_13 * ) V_3 ;
V_14 -> V_15 = F_5 ( V_14 -> V_15 ) ;
break;
}
case V_16 :
case V_17 :
case V_18 :
{
break;
}
default:
{
V_5 = ( V_3 -> V_6 . V_10 -
sizeof( struct V_11 ) ) / 4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ )
V_3 -> V_9 [ V_4 ] = F_3 ( V_3 -> V_9 [ V_4 ] ) ;
break;
}
}
#endif
}
void F_6 ( void * V_3 )
{
#ifdef F_2
struct V_11 * V_19 = (struct V_11 * ) V_3 ;
V_19 -> V_7 = F_5 ( V_19 -> V_7 ) ;
V_19 -> V_10 = F_5 ( V_19 -> V_10 ) ;
V_19 -> V_20 = F_5 ( V_19 -> V_20 ) ;
#endif
}
