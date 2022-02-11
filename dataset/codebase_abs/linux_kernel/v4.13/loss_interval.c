static inline T_1 F_1 ( const T_1 V_1 )
{
return V_2 - 1 - ( V_1 % V_2 ) ;
}
static inline struct V_3 * F_2 ( struct V_4 * V_5 )
{
return V_5 -> V_6 ? V_5 -> V_7 [ F_1 ( V_5 -> V_6 - 1 ) ] : NULL ;
}
static inline T_2 F_3 ( struct V_4 * V_5 , const T_1 V_8 )
{
F_4 ( V_8 >= V_5 -> V_6 ) ;
return V_5 -> V_7 [ F_1 ( V_5 -> V_6 - V_8 - 1 ) ] -> V_9 ;
}
static struct V_3 * F_5 ( struct V_4 * V_5 )
{
if ( V_5 -> V_7 [ F_1 ( V_5 -> V_6 ) ] == NULL )
V_5 -> V_7 [ F_1 ( V_5 -> V_6 ) ] = F_6 ( V_10 ,
V_11 ) ;
return V_5 -> V_7 [ F_1 ( V_5 -> V_6 ) ] ;
}
void F_7 ( struct V_4 * V_5 )
{
if ( ! F_8 ( V_5 ) )
return;
for ( V_5 -> V_6 = 0 ; V_5 -> V_6 < V_2 ; V_5 -> V_6 ++ )
if ( V_5 -> V_7 [ F_1 ( V_5 -> V_6 ) ] != NULL ) {
F_9 ( V_10 ,
V_5 -> V_7 [ F_1 ( V_5 -> V_6 ) ] ) ;
V_5 -> V_7 [ F_1 ( V_5 -> V_6 ) ] = NULL ;
}
}
static void F_10 ( struct V_4 * V_5 )
{
T_2 V_12 , V_13 = 0 , V_14 = 0 , V_15 = 0 ;
int V_8 , V_16 = F_11 ( V_5 ) - 1 ;
if ( V_16 <= 0 )
return;
for ( V_8 = 0 ; V_8 <= V_16 ; V_8 ++ ) {
V_12 = F_3 ( V_5 , V_8 ) ;
if ( V_8 < V_16 ) {
V_13 += V_12 * V_17 [ V_8 ] ;
V_15 += V_17 [ V_8 ] ;
}
if ( V_8 > 0 )
V_14 += V_12 * V_17 [ V_8 - 1 ] ;
}
V_5 -> V_18 = F_12 ( V_13 , V_14 ) / V_15 ;
}
T_1 F_13 ( struct V_4 * V_5 , struct V_19 * V_20 )
{
struct V_3 * V_21 = F_2 ( V_5 ) ;
T_2 V_22 = V_5 -> V_18 ;
T_3 V_23 ;
if ( V_21 == NULL )
return 0 ;
V_23 = F_14 ( V_21 -> V_24 , F_15 ( V_20 ) -> V_25 ) + 1 ;
if ( V_23 - ( T_3 ) V_21 -> V_9 <= 0 )
return 0 ;
if ( F_16 ( F_17 ( V_20 ) -> V_26 , V_21 -> V_27 ) > 4 )
V_21 -> V_28 = 1 ;
if ( F_11 ( V_5 ) == 1 )
return 0 ;
V_21 -> V_9 = V_23 ;
F_10 ( V_5 ) ;
return V_5 -> V_18 < V_22 ;
}
static inline T_1 F_18 ( struct V_3 * V_21 ,
struct V_29 * V_30 )
{
return F_14 ( V_21 -> V_24 , V_30 -> V_31 ) > 0 &&
( V_21 -> V_28 || F_16 ( V_30 -> V_32 , V_21 -> V_27 ) > 4 ) ;
}
int F_19 ( struct V_4 * V_5 , struct V_33 * V_34 ,
T_2 (* F_20)( struct V_35 * ) , struct V_35 * V_36 )
{
struct V_3 * V_21 = F_2 ( V_5 ) , * V_37 ;
if ( V_21 != NULL && ! F_18 ( V_21 , F_21 ( V_34 ) ) )
return 0 ;
V_37 = F_5 ( V_5 ) ;
if ( F_22 ( V_37 == NULL ) ) {
F_23 ( L_1 ) ;
return 0 ;
}
V_37 -> V_24 = F_21 ( V_34 ) -> V_31 ;
V_37 -> V_27 = F_21 ( V_34 ) -> V_32 ;
V_37 -> V_28 = 0 ;
if ( ++ V_5 -> V_6 == 1 )
V_5 -> V_18 = V_37 -> V_9 = (* F_20)( V_36 ) ;
else {
V_21 -> V_9 = F_14 ( V_21 -> V_24 , V_37 -> V_24 ) ;
V_37 -> V_9 = F_14 ( V_37 -> V_24 ,
F_24 ( V_34 ) -> V_31 ) + 1 ;
if ( V_5 -> V_6 > ( 2 * V_2 ) )
V_5 -> V_6 -= V_2 ;
F_10 ( V_5 ) ;
}
return 1 ;
}
int T_4 F_25 ( void )
{
V_10 = F_26 ( L_2 ,
sizeof( struct V_3 ) , 0 ,
V_38 , NULL ) ;
return V_10 == NULL ? - V_39 : 0 ;
}
void F_27 ( void )
{
if ( V_10 != NULL ) {
F_28 ( V_10 ) ;
V_10 = NULL ;
}
}
