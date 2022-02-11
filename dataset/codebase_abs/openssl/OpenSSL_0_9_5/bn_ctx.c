T_1 * F_1 ( void )
{
T_1 * V_1 ;
V_1 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ;
if ( V_1 == NULL )
{
F_2 ( V_2 , V_3 ) ;
return ( NULL ) ;
}
F_3 ( V_1 ) ;
V_1 -> V_4 = V_5 ;
return ( V_1 ) ;
}
void F_3 ( T_1 * V_6 )
{
int V_7 ;
V_6 -> V_8 = 0 ;
V_6 -> V_4 = 0 ;
V_6 -> V_9 = 0 ;
V_6 -> V_10 = 0 ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ )
F_4 ( & ( V_6 -> V_12 [ V_7 ] ) ) ;
}
void F_5 ( T_1 * V_6 )
{
int V_7 ;
if ( V_6 == NULL ) return;
assert ( V_6 -> V_9 == 0 ) ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ )
F_6 ( & ( V_6 -> V_12 [ V_7 ] ) ) ;
if ( V_6 -> V_4 & V_5 )
Free ( V_6 ) ;
}
void F_7 ( T_1 * V_6 )
{
if ( V_6 -> V_9 < V_13 )
V_6 -> V_14 [ V_6 -> V_9 ] = V_6 -> V_8 ;
V_6 -> V_9 ++ ;
}
T_2 * F_8 ( T_1 * V_6 )
{
if ( V_6 -> V_9 > V_13 || V_6 -> V_8 >= V_11 )
{
if ( ! V_6 -> V_10 )
{
F_2 ( V_15 , V_16 ) ;
V_6 -> V_10 = 1 ;
}
return NULL ;
}
return ( & ( V_6 -> V_12 [ V_6 -> V_8 ++ ] ) ) ;
}
void F_9 ( T_1 * V_6 )
{
if ( V_6 == NULL ) return;
assert ( V_6 -> V_9 > 0 ) ;
if ( V_6 -> V_9 == 0 )
F_7 ( V_6 ) ;
V_6 -> V_10 = 0 ;
V_6 -> V_9 -- ;
if ( V_6 -> V_9 < V_13 )
V_6 -> V_8 = V_6 -> V_14 [ V_6 -> V_9 ] ;
}
