static inline unsigned long F_1 ( T_1 V_1 )
{
return V_1 ;
}
static inline T_1 F_2 ( unsigned long V_1 )
{
return V_1 ;
}
static inline T_1 * F_3 ( struct V_2 * V_2 )
{
return ( T_1 * ) F_4 ( V_2 ) -> V_3 . V_4 ;
}
static int F_5 ( struct V_2 * V_2 , long V_5 , int V_6 [ V_7 ] )
{
int V_1 = 0 ;
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_5 < 0 ) {
F_6 ( L_1 ,
V_5 , V_9 -> V_11 ) ;
} else if ( ( V_12 ) V_5 * ( V_12 ) V_9 -> V_13 >=
F_7 ( V_9 ) -> V_14 ) {
if ( F_8 () )
F_6 ( L_2
L_3 ,
V_5 , V_9 -> V_11 ) ;
} else if ( V_5 < V_15 ) {
V_6 [ V_1 ++ ] = V_5 ;
} else if ( ( V_5 -= V_15 ) < F_9 ( V_9 ) ) {
V_6 [ V_1 ++ ] = V_15 ;
V_6 [ V_1 ++ ] = V_5 ;
} else if ( ( V_5 -= F_9 ( V_9 ) ) < F_9 ( V_9 ) * F_9 ( V_9 ) ) {
V_6 [ V_1 ++ ] = V_15 + 1 ;
V_6 [ V_1 ++ ] = V_5 / F_9 ( V_9 ) ;
V_6 [ V_1 ++ ] = V_5 % F_9 ( V_9 ) ;
} else {
V_5 -= F_9 ( V_9 ) * F_9 ( V_9 ) ;
V_6 [ V_1 ++ ] = V_15 + 2 ;
V_6 [ V_1 ++ ] = ( V_5 / F_9 ( V_9 ) ) / F_9 ( V_9 ) ;
V_6 [ V_1 ++ ] = ( V_5 / F_9 ( V_9 ) ) % F_9 ( V_9 ) ;
V_6 [ V_1 ++ ] = V_5 % F_9 ( V_9 ) ;
}
return V_1 ;
}
int F_10 ( struct V_2 * V_2 , long V_5 ,
struct V_16 * V_17 , int V_18 )
{
return F_11 ( V_2 , V_5 , V_17 , V_18 ) ;
}
void F_12 ( struct V_2 * V_2 )
{
F_13 ( V_2 ) ;
}
unsigned F_14 ( T_2 V_19 , struct V_8 * V_9 )
{
return F_15 ( V_19 , V_9 ) ;
}
