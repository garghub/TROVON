static int F_1 ( unsigned int V_1 , unsigned int V_2 ,
const int V_3 )
{
return V_3 / ( ( V_1 + V_2 - 1 ) / V_2 ) ;
}
static int F_2 ( unsigned int V_3 )
{
unsigned int V_4 ;
V_4 = F_3 ( F_4 ( V_3 ) ) ;
if ( V_4 < V_5 )
return V_4 ;
return V_3 ;
}
int F_5 ( unsigned int * V_6 , unsigned int V_2 )
{
unsigned int V_7 , V_1 , V_8 , V_9 , V_10 ;
T_1 V_11 ;
if ( ! F_6 ( & V_11 , V_12 ) )
return 1 ;
F_7 ( V_11 ) ;
V_1 = V_8 = 0 ;
F_8 (i) {
V_1 ++ ;
V_10 = F_2 ( V_7 ) ;
if ( ! F_9 ( V_10 , V_11 ) )
V_8 ++ ;
F_10 ( V_7 , V_11 ) ;
}
V_9 = 0 ;
F_11 (i) {
if ( ! F_12 ( V_7 ) ) {
V_6 [ V_7 ] = 0 ;
continue;
}
if ( V_2 >= V_1 || V_1 == V_8 ) {
V_6 [ V_7 ] = F_1 ( V_1 , V_2 , V_9 ) ;
V_9 ++ ;
continue;
}
V_10 = F_2 ( V_7 ) ;
if ( V_10 == V_7 ) {
V_6 [ V_7 ] = F_1 ( V_8 , V_2 ,
V_9 ) ;
V_9 ++ ;
} else
V_6 [ V_7 ] = V_6 [ V_10 ] ;
}
F_13 ( V_11 ) ;
return 0 ;
}
unsigned int * F_14 ( struct V_13 * V_14 )
{
unsigned int * V_6 ;
V_6 = F_15 ( sizeof( * V_6 ) * F_16 () , V_15 ,
V_14 -> V_16 ) ;
if ( ! V_6 )
return NULL ;
if ( ! F_5 ( V_6 , V_14 -> V_17 ) )
return V_6 ;
F_17 ( V_6 ) ;
return NULL ;
}
