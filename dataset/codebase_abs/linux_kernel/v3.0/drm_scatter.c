static inline void * F_1 ( unsigned long V_1 )
{
#if F_2 ( V_2 ) && F_2 ( V_3 )
return F_3 ( V_1 , V_4 , V_5 | V_6 ) ;
#else
return F_4 ( V_1 ) ;
#endif
}
void F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_9 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_11 ; V_10 ++ ) {
V_9 = V_8 -> V_12 [ V_10 ] ;
if ( V_9 )
F_6 ( V_9 ) ;
}
F_7 ( V_8 -> V_13 ) ;
F_8 ( V_8 -> V_14 ) ;
F_8 ( V_8 -> V_12 ) ;
F_8 ( V_8 ) ;
}
int F_9 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_7 * V_8 ;
unsigned long V_11 , V_10 , V_19 ;
F_10 ( L_1 ) ;
if ( ! F_11 ( V_16 , V_20 ) )
return - V_21 ;
if ( V_16 -> V_22 )
return - V_21 ;
V_8 = F_12 ( sizeof( * V_8 ) , V_4 ) ;
if ( ! V_8 )
return - V_23 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_11 = ( V_18 -> V_1 + V_24 - 1 ) / V_24 ;
F_10 ( L_2 , V_18 -> V_1 , V_11 ) ;
V_8 -> V_11 = V_11 ;
V_8 -> V_12 = F_12 ( V_11 * sizeof( * V_8 -> V_12 ) , V_4 ) ;
if ( ! V_8 -> V_12 ) {
F_8 ( V_8 ) ;
return - V_23 ;
}
memset ( V_8 -> V_12 , 0 , V_11 * sizeof( * V_8 -> V_12 ) ) ;
V_8 -> V_14 = F_12 ( V_11 * sizeof( * V_8 -> V_14 ) , V_4 ) ;
if ( ! V_8 -> V_14 ) {
F_8 ( V_8 -> V_12 ) ;
F_8 ( V_8 ) ;
return - V_23 ;
}
memset ( ( void * ) V_8 -> V_14 , 0 , V_11 * sizeof( * V_8 -> V_14 ) ) ;
V_8 -> V_13 = F_1 ( V_11 << V_25 ) ;
if ( ! V_8 -> V_13 ) {
F_8 ( V_8 -> V_14 ) ;
F_8 ( V_8 -> V_12 ) ;
F_8 ( V_8 ) ;
return - V_23 ;
}
memset ( V_8 -> V_13 , 0 , V_11 << V_25 ) ;
V_8 -> V_26 = F_13 ( ( unsigned long ) V_8 -> V_13 ) ;
F_10 ( L_3 , V_8 -> V_26 ) ;
F_10 ( L_4 , V_8 -> V_13 ) ;
for ( V_10 = ( unsigned long ) V_8 -> V_13 , V_19 = 0 ; V_19 < V_11 ;
V_10 += V_24 , V_19 ++ ) {
V_8 -> V_12 [ V_19 ] = F_14 ( ( void * ) V_10 ) ;
if ( ! V_8 -> V_12 [ V_19 ] )
goto V_27;
F_15 ( V_8 -> V_12 [ V_19 ] ) ;
}
V_18 -> V_26 = V_8 -> V_26 ;
V_16 -> V_22 = V_8 ;
#if V_28
{
int error = 0 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
unsigned long * V_29 ;
V_29 = F_16 ( V_8 -> V_12 [ V_10 ] ) ;
for ( V_19 = 0 ;
V_19 < V_24 / sizeof( unsigned long ) ;
V_19 ++ , V_29 ++ ) {
* V_29 = 0xcafebabe ;
}
V_29 = ( unsigned long * ) ( ( V_30 * ) V_8 -> V_13 +
( V_24 * V_10 ) ) ;
for ( V_19 = 0 ;
V_19 < V_24 / sizeof( unsigned long ) ;
V_19 ++ , V_29 ++ ) {
if ( * V_29 != 0xcafebabe && error == 0 ) {
error = 1 ;
F_17 ( L_5
L_6
L_7 ) ;
}
}
V_29 = F_16 ( V_8 -> V_12 [ V_10 ] ) ;
for ( V_19 = 0 ;
V_19 < V_24 / sizeof( unsigned long ) ;
V_19 ++ , V_29 ++ ) {
* V_29 = 0 ;
}
}
if ( error == 0 )
F_17 ( L_8 ) ;
}
#endif
return 0 ;
V_27:
F_5 ( V_8 ) ;
return - V_23 ;
}
int F_18 ( struct V_15 * V_16 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_17 * V_18 = V_31 ;
return F_9 ( V_16 , V_18 ) ;
}
int F_19 ( struct V_15 * V_16 , void * V_31 ,
struct V_32 * V_33 )
{
struct V_17 * V_18 = V_31 ;
struct V_7 * V_8 ;
if ( ! F_11 ( V_16 , V_20 ) )
return - V_21 ;
V_8 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
if ( ! V_8 || V_8 -> V_26 != V_18 -> V_26 )
return - V_21 ;
F_10 ( L_9 , V_8 -> V_13 ) ;
F_5 ( V_8 ) ;
return 0 ;
}
