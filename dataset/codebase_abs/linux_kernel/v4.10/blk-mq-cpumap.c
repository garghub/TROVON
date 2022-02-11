static int F_1 ( unsigned int V_1 , unsigned int V_2 ,
const int V_3 )
{
return V_3 * V_2 / V_1 ;
}
static int F_2 ( unsigned int V_3 )
{
unsigned int V_4 ;
V_4 = F_3 ( F_4 ( V_3 ) ) ;
if ( V_4 < V_5 )
return V_4 ;
return V_3 ;
}
int F_5 ( struct V_6 * V_7 )
{
unsigned int * V_8 = V_7 -> V_9 ;
unsigned int V_2 = V_7 -> V_10 ;
const struct V_11 * V_12 = V_13 ;
unsigned int V_14 , V_1 , V_15 , V_16 , V_17 ;
T_1 V_18 ;
if ( ! F_6 ( & V_18 , V_19 ) )
return - V_20 ;
F_7 ( V_18 ) ;
V_1 = V_15 = 0 ;
F_8 (i, online_mask) {
V_1 ++ ;
V_17 = F_2 ( V_14 ) ;
if ( ! F_9 ( V_17 , V_18 ) )
V_15 ++ ;
F_10 ( V_14 , V_18 ) ;
}
V_16 = 0 ;
F_11 (i) {
if ( ! F_9 ( V_14 , V_12 ) ) {
V_8 [ V_14 ] = 0 ;
continue;
}
if ( V_2 >= V_1 || V_1 == V_15 ) {
V_8 [ V_14 ] = F_1 ( V_1 , V_2 , V_16 ) ;
V_16 ++ ;
continue;
}
V_17 = F_2 ( V_14 ) ;
if ( V_17 == V_14 ) {
V_8 [ V_14 ] = F_1 ( V_15 , V_2 ,
V_16 ) ;
V_16 ++ ;
} else
V_8 [ V_14 ] = V_8 [ V_17 ] ;
}
F_12 ( V_18 ) ;
return 0 ;
}
int F_13 ( unsigned int * V_9 , unsigned int V_21 )
{
int V_14 ;
F_11 (i) {
if ( V_21 == V_9 [ V_14 ] )
return F_14 ( F_15 ( V_14 ) ) ;
}
return V_22 ;
}
