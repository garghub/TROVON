static inline void F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
#define F_3 128
struct V_3 * V_4 ;
T_1 V_5 , V_6 ;
T_1 V_7 , V_8 ;
T_1 V_9 = ( T_1 ) F_4 ( V_10 ) ;
if ( F_5 ( V_2 ) )
return;
if ( V_2 -> V_11 >= V_9 + sizeof( struct V_1 ) + F_3 &&
V_2 -> V_11 <= V_9 + V_12 )
return;
V_5 = ( T_1 ) F_6 ( V_13 . V_14 ) +
F_3 ;
V_6 = ( T_1 ) F_7 ( V_15 ) ;
if ( V_2 -> V_11 >= V_5 && V_2 -> V_11 <= V_6 )
return;
V_4 = F_6 ( & V_3 ) ;
V_7 = ( T_1 ) V_4 -> V_16 [ 0 ] - V_17 + F_3 ;
V_8 = ( T_1 ) V_4 -> V_16 [ V_18 - 1 ] ;
if ( V_2 -> V_11 >= V_7 && V_2 -> V_11 <= V_8 )
return;
F_8 ( 1 , L_1 ,
V_10 -> V_19 , V_9 , V_2 -> V_11 ,
V_5 , V_6 ,
V_7 , V_8 ) ;
if ( V_20 )
F_9 ( L_2 ) ;
#endif
}
bool F_10 ( struct V_21 * V_22 , struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
if ( F_11 ( V_22 ) )
return false ;
F_12 ( V_22 ) ;
return true ;
}
