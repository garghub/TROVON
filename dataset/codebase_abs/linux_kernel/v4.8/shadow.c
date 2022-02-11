void * F_1 ( unsigned long V_1 )
{
T_1 * V_2 ;
struct V_3 * V_3 ;
if ( ! F_2 ( V_1 ) )
return NULL ;
V_2 = F_3 ( V_1 ) ;
if ( ! V_2 )
return NULL ;
V_3 = F_4 ( V_1 ) ;
if ( ! V_3 -> V_4 )
return NULL ;
return V_3 -> V_4 + ( V_1 & ( V_5 - 1 ) ) ;
}
static void F_5 ( void * V_1 , unsigned int V_6 ,
enum V_7 V_8 )
{
unsigned long V_9 = ( unsigned long ) V_1 ;
unsigned long V_10 = V_9 + V_6 - 1 ;
unsigned long V_3 = V_9 & V_11 ;
unsigned long V_12 = V_10 & V_11 ;
unsigned int V_13 ;
void * V_4 ;
if ( V_3 == V_12 )
V_13 = V_6 ;
else
V_13 = V_3 + V_5 - V_9 ;
V_4 = F_1 ( V_9 ) ;
if ( V_4 )
memset ( V_4 , V_8 , V_13 ) ;
V_9 += V_13 ;
V_6 -= V_13 ;
while ( V_6 >= V_5 ) {
V_4 = F_1 ( V_9 ) ;
if ( V_4 )
memset ( V_4 , V_8 , V_5 ) ;
V_9 += V_5 ;
V_6 -= V_5 ;
}
if ( V_6 > 0 ) {
V_4 = F_1 ( V_9 ) ;
if ( V_4 )
memset ( V_4 , V_8 , V_6 ) ;
}
}
void F_6 ( void * V_1 , unsigned int V_6 )
{
F_5 ( V_1 , V_6 , V_14 ) ;
}
void F_7 ( void * V_1 , unsigned int V_6 )
{
F_5 ( V_1 , V_6 , V_15 ) ;
}
void F_8 ( void * V_1 , unsigned int V_6 )
{
F_5 ( V_1 , V_6 , V_16 ) ;
}
void F_9 ( void * V_1 , unsigned int V_6 )
{
F_5 ( V_1 , V_6 , V_17 ) ;
}
void F_10 ( struct V_3 * V_18 , unsigned int V_6 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_6 ; ++ V_19 )
F_6 ( F_11 ( & V_18 [ V_19 ] ) , V_5 ) ;
}
void F_12 ( struct V_3 * V_18 , unsigned int V_6 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_6 ; ++ V_19 )
F_7 ( F_11 ( & V_18 [ V_19 ] ) , V_5 ) ;
}
void F_13 ( struct V_3 * V_18 , unsigned int V_6 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_6 ; ++ V_19 )
F_8 ( F_11 ( & V_18 [ V_19 ] ) , V_5 ) ;
}
enum V_7 F_14 ( void * V_4 , unsigned int V_20 )
{
#ifdef F_15
T_2 * V_21 ;
unsigned int V_19 ;
V_21 = V_4 ;
for ( V_19 = 0 ; V_19 < V_20 ; ++ V_19 ) {
if ( V_21 [ V_19 ] == V_16 )
return V_21 [ V_19 ] ;
}
return V_21 [ 0 ] ;
#else
return F_16 ( V_4 , V_20 ) ;
#endif
}
enum V_7 F_16 ( void * V_4 , unsigned int V_20 )
{
T_2 * V_21 ;
unsigned int V_19 ;
V_21 = V_4 ;
for ( V_19 = 0 ; V_19 < V_20 ; ++ V_19 ) {
if ( V_21 [ V_19 ] != V_16 )
return V_21 [ V_19 ] ;
}
return V_21 [ 0 ] ;
}
void F_17 ( void * V_4 , unsigned int V_20 )
{
T_2 * V_21 ;
unsigned int V_19 ;
V_21 = V_4 ;
for ( V_19 = 0 ; V_19 < V_20 ; ++ V_19 )
V_21 [ V_19 ] = V_16 ;
}
