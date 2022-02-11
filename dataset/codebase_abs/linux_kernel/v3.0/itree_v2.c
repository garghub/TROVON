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
char V_8 [ V_9 ] ;
struct V_10 * V_11 = V_2 -> V_12 ;
if ( V_5 < 0 ) {
F_6 ( L_1 ,
V_5 , F_7 ( V_11 -> V_13 , V_8 ) ) ;
} else if ( V_5 >= ( F_8 ( V_2 -> V_12 ) -> V_14 / V_11 -> V_15 ) ) {
if ( F_9 () )
F_6 ( L_2
L_3 ,
V_5 , F_7 ( V_11 -> V_13 , V_8 ) ) ;
} else if ( V_5 < V_16 ) {
V_6 [ V_1 ++ ] = V_5 ;
} else if ( ( V_5 -= V_16 ) < F_10 ( V_11 ) ) {
V_6 [ V_1 ++ ] = V_16 ;
V_6 [ V_1 ++ ] = V_5 ;
} else if ( ( V_5 -= F_10 ( V_11 ) ) < F_10 ( V_11 ) * F_10 ( V_11 ) ) {
V_6 [ V_1 ++ ] = V_16 + 1 ;
V_6 [ V_1 ++ ] = V_5 / F_10 ( V_11 ) ;
V_6 [ V_1 ++ ] = V_5 % F_10 ( V_11 ) ;
} else {
V_5 -= F_10 ( V_11 ) * F_10 ( V_11 ) ;
V_6 [ V_1 ++ ] = V_16 + 2 ;
V_6 [ V_1 ++ ] = ( V_5 / F_10 ( V_11 ) ) / F_10 ( V_11 ) ;
V_6 [ V_1 ++ ] = ( V_5 / F_10 ( V_11 ) ) % F_10 ( V_11 ) ;
V_6 [ V_1 ++ ] = V_5 % F_10 ( V_11 ) ;
}
return V_1 ;
}
int F_11 ( struct V_2 * V_2 , long V_5 ,
struct V_17 * V_18 , int V_19 )
{
return F_12 ( V_2 , V_5 , V_18 , V_19 ) ;
}
void F_13 ( struct V_2 * V_2 )
{
F_14 ( V_2 ) ;
}
unsigned F_15 ( T_2 V_20 , struct V_10 * V_11 )
{
return F_16 ( V_20 , V_11 ) ;
}
