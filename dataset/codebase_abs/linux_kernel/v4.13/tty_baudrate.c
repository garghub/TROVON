T_1 F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = V_2 -> V_4 & V_5 ;
#ifdef F_2
if ( V_3 == F_2 )
return V_2 -> V_6 ;
#endif
if ( V_3 & V_7 ) {
V_3 &= ~ V_7 ;
if ( V_3 < 1 || V_3 + 15 > V_8 )
V_2 -> V_4 &= ~ V_7 ;
else
V_3 += 15 ;
}
return V_9 [ V_3 ] ;
}
T_1 F_3 ( struct V_1 * V_2 )
{
#ifdef F_4
unsigned int V_3 = ( V_2 -> V_4 >> F_4 ) & V_5 ;
if ( V_3 == V_10 )
return F_1 ( V_2 ) ;
if ( V_3 == F_2 )
return V_2 -> V_11 ;
if ( V_3 & V_7 ) {
V_3 &= ~ V_7 ;
if ( V_3 < 1 || V_3 + 15 > V_8 )
V_2 -> V_4 &= ~ ( V_7 << F_4 ) ;
else
V_3 += 15 ;
}
return V_9 [ V_3 ] ;
#else
return F_1 ( V_2 ) ;
#endif
}
void F_5 ( struct V_1 * V_2 ,
T_1 V_12 , T_1 V_13 )
{
int V_14 = 0 ;
int V_15 = - 1 , V_16 = - 1 ;
int V_17 = V_12 / 50 , V_18 = V_13 / 50 ;
int V_19 = 0 ;
if ( V_13 == 0 )
V_12 = 0 ;
V_2 -> V_11 = V_12 ;
V_2 -> V_6 = V_13 ;
#ifdef F_2
if ( ( V_2 -> V_4 & V_5 ) == F_2 )
V_18 = 0 ;
if ( ( ( V_2 -> V_4 >> F_4 ) & V_5 ) == F_2 )
V_17 = 0 ;
if ( ( V_2 -> V_4 >> F_4 ) & V_5 )
V_19 = 1 ;
#endif
V_2 -> V_4 &= ~ V_5 ;
do {
if ( V_13 - V_18 <= V_9 [ V_14 ] &&
V_13 + V_18 >= V_9 [ V_14 ] ) {
V_2 -> V_4 |= V_20 [ V_14 ] ;
V_16 = V_14 ;
}
if ( V_12 - V_17 <= V_9 [ V_14 ] &&
V_12 + V_17 >= V_9 [ V_14 ] ) {
if ( V_16 == V_14 && ! V_19 )
V_15 = V_14 ;
#ifdef F_4
else {
V_15 = V_14 ;
V_2 -> V_4 |= ( V_20 [ V_14 ] << F_4 ) ;
}
#endif
}
} while ( ++ V_14 < V_8 );
#ifdef F_2
if ( V_16 == - 1 )
V_2 -> V_4 |= F_2 ;
if ( V_15 == - 1 && ( V_12 != V_13 || V_19 ) )
V_2 -> V_4 |= ( F_2 << F_4 ) ;
#else
if ( V_15 == - 1 || V_16 == - 1 )
F_6 ( L_1 ) ;
#endif
}
void F_7 ( struct V_21 * V_22 , T_1 V_12 , T_1 V_13 )
{
F_5 ( & V_22 -> V_2 , V_12 , V_13 ) ;
}
