static inline void * F_1 ( unsigned long V_1 )
{
#if F_2 ( V_2 ) && F_2 ( V_3 )
return F_3 ( V_1 , V_4 , F_4 ( V_5 ) ) ;
#else
return F_5 ( V_1 ) ;
#endif
}
static void F_6 ( struct V_6 * V_7 )
{
struct V_8 * V_8 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_7 -> V_10 ; V_9 ++ ) {
V_8 = V_7 -> V_11 [ V_9 ] ;
if ( V_8 )
F_7 ( V_8 ) ;
}
F_8 ( V_7 -> V_12 ) ;
F_9 ( V_7 -> V_13 ) ;
F_9 ( V_7 -> V_11 ) ;
F_9 ( V_7 ) ;
}
void F_10 ( struct V_14 * V_15 )
{
if ( F_11 ( V_15 , V_16 ) && V_15 -> V_17 &&
! F_11 ( V_15 , V_18 ) ) {
F_6 ( V_15 -> V_17 ) ;
V_15 -> V_17 = NULL ;
}
}
int F_12 ( struct V_14 * V_15 , void * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = V_19 ;
struct V_6 * V_7 ;
unsigned long V_10 , V_9 , V_24 ;
F_13 ( L_1 ) ;
if ( F_11 ( V_15 , V_18 ) )
return - V_25 ;
if ( ! F_11 ( V_15 , V_16 ) )
return - V_25 ;
if ( V_15 -> V_17 )
return - V_25 ;
V_7 = F_14 ( sizeof( * V_7 ) , V_4 ) ;
if ( ! V_7 )
return - V_26 ;
V_10 = ( V_23 -> V_1 + V_27 - 1 ) / V_27 ;
F_13 ( L_2 , V_23 -> V_1 , V_10 ) ;
V_7 -> V_10 = V_10 ;
V_7 -> V_11 = F_15 ( V_10 , sizeof( * V_7 -> V_11 ) , V_4 ) ;
if ( ! V_7 -> V_11 ) {
F_9 ( V_7 ) ;
return - V_26 ;
}
V_7 -> V_13 = F_15 ( V_10 , sizeof( * V_7 -> V_13 ) , V_4 ) ;
if ( ! V_7 -> V_13 ) {
F_9 ( V_7 -> V_11 ) ;
F_9 ( V_7 ) ;
return - V_26 ;
}
V_7 -> V_12 = F_1 ( V_10 << V_28 ) ;
if ( ! V_7 -> V_12 ) {
F_9 ( V_7 -> V_13 ) ;
F_9 ( V_7 -> V_11 ) ;
F_9 ( V_7 ) ;
return - V_26 ;
}
memset ( V_7 -> V_12 , 0 , V_10 << V_28 ) ;
V_7 -> V_29 = F_16 ( ( unsigned long ) V_7 -> V_12 ) ;
F_13 ( L_3 , V_7 -> V_29 ) ;
F_13 ( L_4 , V_7 -> V_12 ) ;
for ( V_9 = ( unsigned long ) V_7 -> V_12 , V_24 = 0 ; V_24 < V_10 ;
V_9 += V_27 , V_24 ++ ) {
V_7 -> V_11 [ V_24 ] = F_17 ( ( void * ) V_9 ) ;
if ( ! V_7 -> V_11 [ V_24 ] )
goto V_30;
F_18 ( V_7 -> V_11 [ V_24 ] ) ;
}
V_23 -> V_29 = V_7 -> V_29 ;
V_15 -> V_17 = V_7 ;
#if V_31
{
int error = 0 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
unsigned long * V_32 ;
V_32 = F_19 ( V_7 -> V_11 [ V_9 ] ) ;
for ( V_24 = 0 ;
V_24 < V_27 / sizeof( unsigned long ) ;
V_24 ++ , V_32 ++ ) {
* V_32 = 0xcafebabe ;
}
V_32 = ( unsigned long * ) ( ( V_33 * ) V_7 -> V_12 +
( V_27 * V_9 ) ) ;
for ( V_24 = 0 ;
V_24 < V_27 / sizeof( unsigned long ) ;
V_24 ++ , V_32 ++ ) {
if ( * V_32 != 0xcafebabe && error == 0 ) {
error = 1 ;
F_20 ( L_5
L_6
L_7 ) ;
}
}
V_32 = F_19 ( V_7 -> V_11 [ V_9 ] ) ;
for ( V_24 = 0 ;
V_24 < V_27 / sizeof( unsigned long ) ;
V_24 ++ , V_32 ++ ) {
* V_32 = 0 ;
}
}
if ( error == 0 )
F_20 ( L_8 ) ;
}
#endif
return 0 ;
V_30:
F_6 ( V_7 ) ;
return - V_26 ;
}
int F_21 ( struct V_14 * V_15 , void * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = V_19 ;
struct V_6 * V_7 ;
if ( F_11 ( V_15 , V_18 ) )
return - V_25 ;
if ( ! F_11 ( V_15 , V_16 ) )
return - V_25 ;
V_7 = V_15 -> V_17 ;
V_15 -> V_17 = NULL ;
if ( ! V_7 || V_7 -> V_29 != V_23 -> V_29 )
return - V_25 ;
F_13 ( L_9 , V_7 -> V_12 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
