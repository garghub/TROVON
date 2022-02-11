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
int F_5 ( unsigned int * V_6 , unsigned int V_2 ,
const struct V_7 * V_8 )
{
unsigned int V_9 , V_1 , V_10 , V_11 , V_12 ;
T_1 V_13 ;
if ( ! F_6 ( & V_13 , V_14 ) )
return 1 ;
F_7 ( V_13 ) ;
V_1 = V_10 = 0 ;
F_8 (i, online_mask) {
V_1 ++ ;
V_12 = F_2 ( V_9 ) ;
if ( ! F_9 ( V_12 , V_13 ) )
V_10 ++ ;
F_10 ( V_9 , V_13 ) ;
}
V_11 = 0 ;
F_11 (i) {
if ( ! F_9 ( V_9 , V_8 ) ) {
V_6 [ V_9 ] = 0 ;
continue;
}
if ( V_2 >= V_1 || V_1 == V_10 ) {
V_6 [ V_9 ] = F_1 ( V_1 , V_2 , V_11 ) ;
V_11 ++ ;
continue;
}
V_12 = F_2 ( V_9 ) ;
if ( V_12 == V_9 ) {
V_6 [ V_9 ] = F_1 ( V_10 , V_2 ,
V_11 ) ;
V_11 ++ ;
} else
V_6 [ V_9 ] = V_6 [ V_12 ] ;
}
F_12 ( V_13 ) ;
return 0 ;
}
unsigned int * F_13 ( struct V_15 * V_16 )
{
unsigned int * V_6 ;
V_6 = F_14 ( sizeof( * V_6 ) * V_5 , V_17 ,
V_16 -> V_18 ) ;
if ( ! V_6 )
return NULL ;
if ( ! F_5 ( V_6 , V_16 -> V_19 , V_20 ) )
return V_6 ;
F_15 ( V_6 ) ;
return NULL ;
}
int F_16 ( unsigned int * V_21 , unsigned int V_22 )
{
int V_9 ;
F_11 (i) {
if ( V_22 == V_21 [ V_9 ] )
return F_17 ( V_9 ) ;
}
return V_23 ;
}
