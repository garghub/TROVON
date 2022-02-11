static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
void T_1 * V_5 [ 8 ] ;
void T_1 * V_6 [ 4 ] ;
void T_1 * V_7 [ 4 ] ;
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , V_10 , 0 ) ;
V_5 [ 0 ] = F_3 ( & V_2 -> V_11 , V_9 ) ;
if ( F_4 ( V_5 [ 0 ] ) )
return F_5 ( V_5 [ 0 ] ) ;
V_9 = F_2 ( V_2 , V_10 , 1 ) ;
V_6 [ 0 ] = F_3 ( & V_2 -> V_11 , V_9 ) ;
if ( F_4 ( V_6 [ 0 ] ) )
return F_5 ( V_6 [ 0 ] ) ;
V_9 = F_2 ( V_2 , V_10 , 2 ) ;
V_6 [ 3 ] = F_3 ( & V_2 -> V_11 , V_9 ) ;
if ( F_4 ( V_6 [ 3 ] ) )
return F_5 ( V_6 [ 3 ] ) ;
V_9 = F_2 ( V_2 , V_10 , 3 ) ;
V_7 [ 0 ] = F_3 ( & V_2 -> V_11 , V_9 ) ;
if ( F_4 ( V_7 [ 0 ] ) )
return F_5 ( V_7 [ 0 ] ) ;
for ( V_4 = 0 ; V_4 < F_6 ( V_5 ) ; V_4 ++ )
V_5 [ V_4 ] = V_5 [ 0 ] + sizeof( V_5 [ 0 ] ) * V_4 ;
for ( V_4 = 0 ; V_4 < 3 ; V_4 ++ )
V_6 [ V_4 ] = V_6 [ 0 ] + sizeof( V_6 [ 0 ] ) * V_4 ;
for ( V_4 = 0 ; V_4 < F_6 ( V_7 ) ; V_4 ++ )
V_7 [ V_4 ] = V_7 [ 0 ] + sizeof( V_5 [ 0 ] ) * V_4 ;
V_3 = F_7 ( V_2 , V_12 , F_6 ( V_12 ) ,
V_5 , V_6 , V_7 ) ;
return V_3 ;
}
