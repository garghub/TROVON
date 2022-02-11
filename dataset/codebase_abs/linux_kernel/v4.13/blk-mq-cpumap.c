static int F_1 ( unsigned int V_1 , const int V_2 )
{
if ( ! F_2 ( V_2 ) )
return 0 ;
return V_2 % V_1 ;
}
static int F_3 ( unsigned int V_2 )
{
unsigned int V_3 ;
V_3 = F_4 ( F_5 ( V_2 ) ) ;
if ( V_3 < V_4 )
return V_3 ;
return V_2 ;
}
int F_6 ( struct V_5 * V_6 )
{
unsigned int * V_7 = V_6 -> V_8 ;
unsigned int V_1 = V_6 -> V_9 ;
unsigned int V_2 , V_10 ;
F_7 (cpu) {
if ( V_2 < V_1 ) {
V_7 [ V_2 ] = F_1 ( V_1 , V_2 ) ;
} else {
V_10 = F_3 ( V_2 ) ;
if ( V_10 == V_2 )
V_7 [ V_2 ] = F_1 ( V_1 , V_2 ) ;
else
V_7 [ V_2 ] = V_7 [ V_10 ] ;
}
}
return 0 ;
}
int F_8 ( unsigned int * V_8 , unsigned int V_11 )
{
int V_12 ;
F_7 (i) {
if ( V_11 == V_8 [ V_12 ] )
return F_9 ( F_10 ( V_12 ) ) ;
}
return V_13 ;
}
