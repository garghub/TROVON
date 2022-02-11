struct V_1 * F_1 ( void )
{
return F_2 ( V_2 ) ;
}
struct V_1 * F_3 ( struct V_1 * V_3 )
{
int V_4 = F_4 ( V_3 -> V_5 ) ;
if ( V_4 == V_6 )
return NULL ;
return F_2 ( V_4 ) ;
}
struct V_7 * F_5 ( struct V_7 * V_7 )
{
T_1 * V_3 = V_7 -> V_8 ;
if ( V_7 < V_3 -> V_9 + V_10 - 1 )
V_7 ++ ;
else {
V_3 = F_3 ( V_3 ) ;
if ( V_3 )
V_7 = V_3 -> V_9 ;
else
V_7 = NULL ;
}
return V_7 ;
}
static inline int F_6 ( struct V_11 * V_12 , T_2 * V_13 )
{
#ifdef F_7
return F_8 ( F_9 ( V_12 ) , * V_13 ) ;
#else
return 1 ;
#endif
}
struct V_11 * F_10 ( struct V_11 * V_14 ,
enum V_15 V_16 ,
T_2 * V_13 ,
struct V_7 * * V_7 )
{
if ( F_11 ( V_13 == NULL ) )
while ( F_12 ( V_14 ) > V_16 )
V_14 ++ ;
else
while ( F_12 ( V_14 ) > V_16 ||
( V_14 -> V_7 && ! F_6 ( V_14 , V_13 ) ) )
V_14 ++ ;
* V_7 = F_13 ( V_14 ) ;
return V_14 ;
}
int F_14 ( unsigned long V_17 ,
struct V_18 * V_18 , struct V_7 * V_7 )
{
if ( F_15 ( V_18 ) != V_17 )
return 0 ;
if ( F_16 ( V_18 ) != V_7 )
return 0 ;
return 1 ;
}
void F_17 ( struct V_19 * V_19 )
{
enum V_20 V_21 ;
memset ( V_19 , 0 , sizeof( struct V_19 ) ) ;
F_18 (lru)
F_19 ( & V_19 -> V_22 [ V_21 ] ) ;
}
int F_20 ( struct V_18 * V_18 , int V_23 )
{
unsigned long V_24 , V_25 ;
int V_26 ;
do {
V_24 = V_25 = V_18 -> V_25 ;
V_26 = F_21 ( V_18 ) ;
V_25 &= ~ ( V_27 << V_28 ) ;
V_25 |= ( V_23 & V_27 ) << V_28 ;
} while ( F_22 ( F_23 ( & V_18 -> V_25 , V_24 , V_25 ) != V_24 ) );
return V_26 ;
}
