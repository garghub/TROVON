static inline void * F_1 ( unsigned long V_1 )
{
#if F_2 ( V_2 ) && F_2 ( V_3 )
return F_3 ( V_1 , V_4 , V_5 | V_6 ) ;
#else
return F_4 ( V_1 ) ;
#endif
}
static void F_5 ( struct V_7 * V_8 )
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
void F_9 ( struct V_15 * V_16 )
{
if ( F_10 ( V_16 , V_17 ) && V_16 -> V_18 &&
! F_10 ( V_16 , V_19 ) ) {
F_5 ( V_16 -> V_18 ) ;
V_16 -> V_18 = NULL ;
}
}
int F_11 ( struct V_15 * V_16 , void * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = V_20 ;
struct V_7 * V_8 ;
unsigned long V_11 , V_10 , V_25 ;
F_12 ( L_1 ) ;
if ( F_10 ( V_16 , V_19 ) )
return - V_26 ;
if ( ! F_10 ( V_16 , V_17 ) )
return - V_26 ;
if ( V_16 -> V_18 )
return - V_26 ;
V_8 = F_13 ( sizeof( * V_8 ) , V_4 ) ;
if ( ! V_8 )
return - V_27 ;
V_11 = ( V_24 -> V_1 + V_28 - 1 ) / V_28 ;
F_12 ( L_2 , V_24 -> V_1 , V_11 ) ;
V_8 -> V_11 = V_11 ;
V_8 -> V_12 = F_14 ( V_11 , sizeof( * V_8 -> V_12 ) , V_4 ) ;
if ( ! V_8 -> V_12 ) {
F_8 ( V_8 ) ;
return - V_27 ;
}
V_8 -> V_14 = F_14 ( V_11 , sizeof( * V_8 -> V_14 ) , V_4 ) ;
if ( ! V_8 -> V_14 ) {
F_8 ( V_8 -> V_12 ) ;
F_8 ( V_8 ) ;
return - V_27 ;
}
V_8 -> V_13 = F_1 ( V_11 << V_29 ) ;
if ( ! V_8 -> V_13 ) {
F_8 ( V_8 -> V_14 ) ;
F_8 ( V_8 -> V_12 ) ;
F_8 ( V_8 ) ;
return - V_27 ;
}
memset ( V_8 -> V_13 , 0 , V_11 << V_29 ) ;
V_8 -> V_30 = F_15 ( ( unsigned long ) V_8 -> V_13 ) ;
F_12 ( L_3 , V_8 -> V_30 ) ;
F_12 ( L_4 , V_8 -> V_13 ) ;
for ( V_10 = ( unsigned long ) V_8 -> V_13 , V_25 = 0 ; V_25 < V_11 ;
V_10 += V_28 , V_25 ++ ) {
V_8 -> V_12 [ V_25 ] = F_16 ( ( void * ) V_10 ) ;
if ( ! V_8 -> V_12 [ V_25 ] )
goto V_31;
F_17 ( V_8 -> V_12 [ V_25 ] ) ;
}
V_24 -> V_30 = V_8 -> V_30 ;
V_16 -> V_18 = V_8 ;
#if V_32
{
int error = 0 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
unsigned long * V_33 ;
V_33 = F_18 ( V_8 -> V_12 [ V_10 ] ) ;
for ( V_25 = 0 ;
V_25 < V_28 / sizeof( unsigned long ) ;
V_25 ++ , V_33 ++ ) {
* V_33 = 0xcafebabe ;
}
V_33 = ( unsigned long * ) ( ( V_34 * ) V_8 -> V_13 +
( V_28 * V_10 ) ) ;
for ( V_25 = 0 ;
V_25 < V_28 / sizeof( unsigned long ) ;
V_25 ++ , V_33 ++ ) {
if ( * V_33 != 0xcafebabe && error == 0 ) {
error = 1 ;
F_19 ( L_5
L_6
L_7 ) ;
}
}
V_33 = F_18 ( V_8 -> V_12 [ V_10 ] ) ;
for ( V_25 = 0 ;
V_25 < V_28 / sizeof( unsigned long ) ;
V_25 ++ , V_33 ++ ) {
* V_33 = 0 ;
}
}
if ( error == 0 )
F_19 ( L_8 ) ;
}
#endif
return 0 ;
V_31:
F_5 ( V_8 ) ;
return - V_27 ;
}
int F_20 ( struct V_15 * V_16 , void * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = V_20 ;
struct V_7 * V_8 ;
if ( F_10 ( V_16 , V_19 ) )
return - V_26 ;
if ( ! F_10 ( V_16 , V_17 ) )
return - V_26 ;
V_8 = V_16 -> V_18 ;
V_16 -> V_18 = NULL ;
if ( ! V_8 || V_8 -> V_30 != V_24 -> V_30 )
return - V_26 ;
F_12 ( L_9 , V_8 -> V_13 ) ;
F_5 ( V_8 ) ;
return 0 ;
}
