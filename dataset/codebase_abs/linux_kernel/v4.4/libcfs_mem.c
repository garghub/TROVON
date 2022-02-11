void
F_1 ( void * V_1 )
{
struct V_2 * V_3 ;
int V_4 ;
V_3 = F_2 ( V_1 , struct V_2 , V_5 [ 0 ] ) ;
for ( V_4 = 0 ; V_4 < V_3 -> V_6 ; V_4 ++ ) {
if ( V_3 -> V_5 [ V_4 ] != NULL )
F_3 ( V_3 -> V_5 [ V_4 ] , V_3 -> V_7 ) ;
}
F_3 ( V_3 , F_4 ( struct V_2 ,
V_5 [ V_3 -> V_6 ] ) ) ;
}
void *
F_5 ( struct V_8 * V_9 , unsigned int V_10 )
{
struct V_2 * V_3 ;
int V_11 ;
int V_4 ;
V_11 = F_6 ( V_9 ) ;
F_7 ( V_3 , F_4 ( struct V_2 , V_5 [ V_11 ] ) ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_7 = V_10 = F_8 ( V_10 ) ;
V_3 -> V_6 = V_11 ;
V_3 -> V_12 = V_9 ;
for ( V_4 = 0 ; V_4 < V_11 ; V_4 ++ ) {
F_9 ( V_3 -> V_5 [ V_4 ] , V_9 , V_4 , V_10 ) ;
if ( ! V_3 -> V_5 [ V_4 ] ) {
F_1 ( ( void * ) & V_3 -> V_5 [ 0 ] ) ;
return NULL ;
}
}
return ( void * ) & V_3 -> V_5 [ 0 ] ;
}
int
F_10 ( void * V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( V_1 , struct V_2 , V_5 [ 0 ] ) ;
return V_3 -> V_6 ;
}
void *
F_11 ( void * V_1 )
{
struct V_2 * V_3 ;
int V_13 ;
V_3 = F_2 ( V_1 , struct V_2 , V_5 [ 0 ] ) ;
V_13 = F_12 ( V_3 -> V_12 , 0 ) ;
if ( V_13 < 0 )
return NULL ;
return V_3 -> V_5 [ V_13 ] ;
}
void *
F_13 ( void * V_1 , int V_14 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( V_1 , struct V_2 , V_5 [ 0 ] ) ;
F_14 ( V_14 >= 0 && V_14 < V_3 -> V_6 ) ;
return V_3 -> V_5 [ V_14 ] ;
}
void
F_15 ( void * V_1 )
{
struct V_2 * V_3 ;
int V_4 ;
V_3 = F_2 ( V_1 , struct V_2 , V_5 [ 0 ] ) ;
for ( V_4 = 0 ; V_4 < V_3 -> V_6 ; V_4 ++ ) {
if ( ! V_3 -> V_5 [ V_4 ] )
continue;
F_3 ( V_3 -> V_5 [ V_4 ] , V_3 -> V_7 ) ;
}
F_3 ( V_3 , F_4 ( struct V_2 ,
V_5 [ V_3 -> V_6 ] ) ) ;
}
void *
F_16 ( int V_11 , unsigned int V_10 )
{
struct V_2 * V_3 ;
int V_4 ;
F_7 ( V_3 , F_4 ( struct V_2 , V_5 [ V_11 ] ) ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_6 = V_11 ;
V_3 -> V_7 = V_10 ;
for ( V_4 = 0 ; V_4 < V_11 ; V_4 ++ ) {
F_7 ( V_3 -> V_5 [ V_4 ] , V_10 ) ;
if ( ! V_3 -> V_5 [ V_4 ] ) {
F_15 ( ( void * ) & V_3 -> V_5 [ 0 ] ) ;
return NULL ;
}
}
return ( void * ) & V_3 -> V_5 [ 0 ] ;
}
