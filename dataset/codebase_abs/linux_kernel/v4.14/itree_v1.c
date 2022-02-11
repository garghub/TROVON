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
if ( V_5 < 0 ) {
F_6 ( L_1 ,
V_5 , V_2 -> V_8 -> V_9 ) ;
} else if ( V_5 >= ( F_7 ( V_2 -> V_8 ) -> V_10 / V_11 ) ) {
if ( F_8 () )
F_6 ( L_2
L_3 ,
V_5 , V_2 -> V_8 -> V_9 ) ;
} else if ( V_5 < 7 ) {
V_6 [ V_1 ++ ] = V_5 ;
} else if ( ( V_5 -= 7 ) < 512 ) {
V_6 [ V_1 ++ ] = 7 ;
V_6 [ V_1 ++ ] = V_5 ;
} else {
V_5 -= 512 ;
V_6 [ V_1 ++ ] = 8 ;
V_6 [ V_1 ++ ] = V_5 >> 9 ;
V_6 [ V_1 ++ ] = V_5 & 511 ;
}
return V_1 ;
}
int F_9 ( struct V_2 * V_2 , long V_5 ,
struct V_12 * V_13 , int V_14 )
{
return F_10 ( V_2 , V_5 , V_13 , V_14 ) ;
}
void F_11 ( struct V_2 * V_2 )
{
F_12 ( V_2 ) ;
}
unsigned F_13 ( T_2 V_15 , struct V_16 * V_17 )
{
return F_14 ( V_15 , V_17 ) ;
}
