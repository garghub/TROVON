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
if ( V_5 < 0 ) {
F_6 ( L_1 ,
V_5 , F_7 ( V_2 -> V_10 -> V_11 , V_8 ) ) ;
} else if ( V_5 >= ( F_8 ( V_2 -> V_10 ) -> V_12 / V_13 ) ) {
if ( F_9 () )
F_6 ( L_2
L_3 ,
V_5 , F_7 ( V_2 -> V_10 -> V_11 , V_8 ) ) ;
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
int F_10 ( struct V_2 * V_2 , long V_5 ,
struct V_14 * V_15 , int V_16 )
{
return F_11 ( V_2 , V_5 , V_15 , V_16 ) ;
}
void F_12 ( struct V_2 * V_2 )
{
F_13 ( V_2 ) ;
}
unsigned F_14 ( T_2 V_17 , struct V_18 * V_19 )
{
return F_15 ( V_17 , V_19 ) ;
}
