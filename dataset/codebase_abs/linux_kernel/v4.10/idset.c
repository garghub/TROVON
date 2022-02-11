static inline unsigned long F_1 ( int V_1 , int V_2 )
{
return F_2 ( V_1 * V_2 ) * sizeof( unsigned long ) ;
}
static struct V_3 * F_3 ( int V_1 , int V_2 )
{
struct V_3 * V_4 ;
V_4 = F_4 ( sizeof( struct V_3 ) + F_1 ( V_1 , V_2 ) ) ;
if ( V_4 ) {
V_4 -> V_1 = V_1 ;
V_4 -> V_2 = V_2 ;
memset ( V_4 -> V_5 , 0 , F_1 ( V_1 , V_2 ) ) ;
}
return V_4 ;
}
void F_5 ( struct V_3 * V_4 )
{
F_6 ( V_4 ) ;
}
void F_7 ( struct V_3 * V_4 )
{
memset ( V_4 -> V_5 , 0xff , F_1 ( V_4 -> V_1 , V_4 -> V_2 ) ) ;
}
static inline void F_8 ( struct V_3 * V_4 , int V_6 , int V_7 )
{
F_9 ( V_6 * V_4 -> V_2 + V_7 , V_4 -> V_5 ) ;
}
static inline void F_10 ( struct V_3 * V_4 , int V_6 , int V_7 )
{
F_11 ( V_6 * V_4 -> V_2 + V_7 , V_4 -> V_5 ) ;
}
static inline int F_12 ( struct V_3 * V_4 , int V_6 , int V_7 )
{
return F_13 ( V_6 * V_4 -> V_2 + V_7 , V_4 -> V_5 ) ;
}
static inline int F_14 ( struct V_3 * V_4 , int * V_6 , int * V_7 )
{
int V_8 ;
V_8 = F_15 ( V_4 -> V_5 , V_4 -> V_1 * V_4 -> V_2 ) ;
if ( V_8 >= V_4 -> V_1 * V_4 -> V_2 )
return 0 ;
* V_6 = V_8 / V_4 -> V_2 ;
* V_7 = V_8 % V_4 -> V_2 ;
return 1 ;
}
struct V_3 * F_16 ( void )
{
return F_3 ( V_9 + 1 , V_10 + 1 ) ;
}
void F_17 ( struct V_3 * V_4 , struct V_11 V_12 )
{
F_8 ( V_4 , V_12 . V_6 , V_12 . V_13 ) ;
}
void F_18 ( struct V_3 * V_4 , struct V_11 V_12 )
{
F_10 ( V_4 , V_12 . V_6 , V_12 . V_13 ) ;
}
void F_19 ( struct V_3 * V_4 , struct V_11 V_12 )
{
int V_14 = V_12 . V_6 * V_4 -> V_2 + V_12 . V_13 ;
F_20 ( V_4 -> V_5 , V_14 , V_4 -> V_2 - V_12 . V_13 ) ;
}
int F_21 ( struct V_3 * V_4 , struct V_11 V_12 )
{
return F_12 ( V_4 , V_12 . V_6 , V_12 . V_13 ) ;
}
int F_22 ( struct V_3 * V_4 )
{
return F_23 ( V_4 -> V_5 , V_4 -> V_1 * V_4 -> V_2 ) ;
}
void F_24 ( struct V_3 * V_15 , struct V_3 * V_16 )
{
int V_17 = F_25 ( V_15 -> V_1 * V_15 -> V_2 , V_16 -> V_1 * V_16 -> V_2 ) ;
F_26 ( V_15 -> V_5 , V_15 -> V_5 , V_16 -> V_5 , V_17 ) ;
}
