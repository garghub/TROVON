static void F_1 ( struct V_1 * V_1 , int V_2 , int V_3 ,
T_1 V_4 )
{
T_1 * V_5 = V_1 -> V_5 ;
int V_6 ;
int V_7 = 0 ;
for ( V_6 = V_2 ; V_7 < V_3 ; V_6 ++ , V_7 ++ )
V_5 [ V_6 ] = V_4 ;
}
static int F_2 ( struct V_1 * V_1 , int V_2 ,
int V_8 )
{
T_1 * V_5 = V_1 -> V_5 ;
int V_6 ;
int V_9 ;
for ( V_6 = V_2 ; V_6 < V_1 -> V_10 ; ) {
if ( ! V_5 [ V_6 ] ) {
int V_11 ;
int free ;
free = 0 ;
V_9 = V_6 ;
for ( V_11 = V_9 ; V_11 < V_1 -> V_10 ; V_11 ++ ) {
if ( ! V_5 [ V_11 ] ) {
if ( ++ free == V_8 )
return V_9 ;
} else {
V_6 = V_11 + 1 ;
break;
}
}
if ( V_11 >= V_1 -> V_10 )
return - 1 ;
} else
V_6 ++ ;
}
return - 1 ;
}
static inline void F_3 ( struct V_1 * V_1 ,
int V_2 )
{
F_1 ( V_1 , V_2 , V_1 -> V_5 [ V_2 ] , 0 ) ;
if ( ( V_1 -> V_12 > V_2 ) ||
( V_1 -> V_12 < 0 ) )
V_1 -> V_12 = V_2 ;
}
static inline int F_4 ( struct V_1 * V_1 ,
int V_13 )
{
int V_14 ;
if ( V_1 -> V_12 < 0 )
return - 1 ;
V_14 =
F_2 ( V_1 , V_1 -> V_12 ,
V_13 ) ;
if ( V_14 >= 0 )
F_1 ( V_1 , V_14 , V_13 , V_13 ) ;
V_1 -> V_12 =
F_2 ( V_1 , V_1 -> V_12 , 1 ) ;
return V_14 ;
}
int F_5 ( struct V_15 * V_15 , int V_8 )
{
int V_16 ;
unsigned long V_17 ;
F_6 ( & V_15 -> V_18 , V_17 ) ;
V_16 = F_4 ( & V_15 -> V_19 , V_8 ) ;
F_7 ( & V_15 -> V_18 , V_17 ) ;
return V_16 ;
}
static inline T_1 T_2 * F_8 ( struct V_15 * V_15 ,
int V_20 )
{
if ( V_20 < V_15 -> V_21 ) {
return F_9 ( V_15 , V_20 ) ;
}
F_10 ( L_1 , V_20 ) ;
}
void inline
F_11 ( struct V_15 * V_15 , int V_20 , int V_8 ,
volatile T_1 V_5 )
{
while ( V_8 -- > 0 ) {
if ( V_20 < V_15 -> V_21 ) {
F_12 ( V_15 , V_20 , V_5 ) ;
} else {
F_10 ( L_2 , V_20 ) ;
}
V_20 ++ ;
V_5 += V_22 ;
}
F_13 ( V_15 ) ;
}
void F_14 ( struct V_15 * V_15 , int V_6 )
{
volatile T_1 V_5 ;
int V_8 ;
unsigned long V_17 ;
if ( V_23 ) {
V_5 = * F_8 ( V_15 , V_6 ) ;
V_8 = V_15 -> V_19 . V_5 [ V_6 ] ;
F_11 ( V_15 , V_6 , V_8 , ( V_5 & ~ V_24 ) ) ;
}
F_6 ( & V_15 -> V_18 , V_17 ) ;
F_3 ( & V_15 -> V_19 , V_6 ) ;
F_7 ( & V_15 -> V_18 , V_17 ) ;
}
