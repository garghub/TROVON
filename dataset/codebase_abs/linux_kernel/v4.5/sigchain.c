static void F_1 ( int V_1 )
{
if ( V_1 < 1 || V_1 >= V_2 )
F_2 ( L_1 , V_1 ) ;
}
static int F_3 ( int V_1 , T_1 V_3 )
{
struct V_4 * V_5 = V_6 + V_1 ;
F_1 ( V_1 ) ;
F_4 ( V_5 -> V_7 , V_5 -> V_8 + 1 , V_5 -> V_9 ) ;
V_5 -> V_7 [ V_5 -> V_8 ] = signal ( V_1 , V_3 ) ;
if ( V_5 -> V_7 [ V_5 -> V_8 ] == V_10 )
return - 1 ;
V_5 -> V_8 ++ ;
return 0 ;
}
int F_5 ( int V_1 )
{
struct V_4 * V_5 = V_6 + V_1 ;
F_1 ( V_1 ) ;
if ( V_5 -> V_8 < 1 )
return 0 ;
if ( signal ( V_1 , V_5 -> V_7 [ V_5 -> V_8 - 1 ] ) == V_10 )
return - 1 ;
V_5 -> V_8 -- ;
return 0 ;
}
void F_6 ( T_1 V_3 )
{
F_3 ( V_11 , V_3 ) ;
F_3 ( V_12 , V_3 ) ;
F_3 ( V_13 , V_3 ) ;
F_3 ( V_14 , V_3 ) ;
F_3 ( V_15 , V_3 ) ;
}
