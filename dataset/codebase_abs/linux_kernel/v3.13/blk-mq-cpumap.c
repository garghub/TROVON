static void F_1 ( unsigned int * V_1 , unsigned int V_2 )
{
int V_3 ;
F_2 ( L_1 ) ;
F_3 (i)
F_2 ( L_2 , V_3 , V_1 [ V_3 ] ) ;
}
static int F_4 ( unsigned int V_4 , unsigned int V_5 ,
const int V_6 )
{
return V_6 / ( ( V_4 + V_5 - 1 ) / V_5 ) ;
}
static int F_5 ( unsigned int V_6 )
{
unsigned int V_7 ;
V_7 = F_6 ( F_7 ( V_6 ) ) ;
if ( V_7 < V_8 )
return V_7 ;
return V_6 ;
}
int F_8 ( unsigned int * V_1 , unsigned int V_5 )
{
unsigned int V_3 , V_4 , V_9 , V_10 , V_11 ;
T_1 V_12 ;
if ( ! F_9 ( & V_12 , V_13 ) )
return 1 ;
F_10 ( V_12 ) ;
V_4 = V_9 = 0 ;
F_3 (i) {
V_4 ++ ;
V_11 = F_5 ( V_3 ) ;
if ( ! F_11 ( V_11 , V_12 ) )
V_9 ++ ;
F_12 ( V_3 , V_12 ) ;
}
V_10 = 0 ;
F_13 (i) {
if ( ! F_14 ( V_3 ) ) {
V_1 [ V_3 ] = 0 ;
continue;
}
if ( V_5 >= V_4 || V_4 == V_9 ) {
V_1 [ V_3 ] = F_4 ( V_4 , V_5 , V_10 ) ;
V_10 ++ ;
continue;
}
V_11 = F_5 ( V_3 ) ;
if ( V_11 == V_3 ) {
V_1 [ V_3 ] = F_4 ( V_9 , V_5 ,
V_10 ) ;
V_10 ++ ;
} else
V_1 [ V_3 ] = V_1 [ V_11 ] ;
}
F_1 ( V_1 , V_4 ) ;
F_15 ( V_12 ) ;
return 0 ;
}
unsigned int * F_16 ( struct V_14 * V_15 )
{
unsigned int * V_1 ;
V_1 = F_17 ( sizeof( * V_1 ) * F_18 () , V_16 ,
V_15 -> V_17 ) ;
if ( ! V_1 )
return NULL ;
if ( ! F_8 ( V_1 , V_15 -> V_18 ) )
return V_1 ;
F_19 ( V_1 ) ;
return NULL ;
}
