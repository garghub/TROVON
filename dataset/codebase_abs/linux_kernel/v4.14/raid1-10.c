static inline int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
V_2 -> V_6 [ V_4 ] = F_2 ( V_3 ) ;
if ( ! V_2 -> V_6 [ V_4 ] )
goto V_7;
}
return 0 ;
V_7:
while ( -- V_4 >= 0 )
F_3 ( V_2 -> V_6 [ V_4 ] ) ;
return - V_8 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ )
F_3 ( V_2 -> V_6 [ V_4 ] ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ )
F_6 ( V_2 -> V_6 [ V_4 ] ) ;
}
static inline struct V_9 * F_7 ( struct V_1 * V_2 ,
unsigned V_10 )
{
if ( F_8 ( V_10 >= V_5 ) )
return NULL ;
return V_2 -> V_6 [ V_10 ] ;
}
static inline struct V_1 * F_9 ( struct V_11 * V_11 )
{
return V_11 -> V_12 ;
}
static void F_10 ( struct V_11 * V_11 , struct V_1 * V_2 ,
int V_13 )
{
int V_10 = 0 ;
do {
struct V_9 * V_9 = F_7 ( V_2 , V_10 ) ;
int V_14 = F_11 ( int , V_13 , V_15 ) ;
F_12 ( V_11 , V_9 , V_14 , 0 ) ;
V_13 -= V_14 ;
} while ( V_10 ++ < V_5 && V_13 > 0 );
}
