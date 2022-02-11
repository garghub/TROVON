void
F_1 ( struct V_1 * V_2 , struct V_1 * * V_3 , unsigned int V_4 ,
int V_5 , T_1 V_6 , struct V_7 * V_8 )
{
int V_9 ;
int V_10 = 0 ;
int V_11 = 0 ;
void * V_12 ;
void * * V_13 ;
if ( V_8 -> V_14 )
V_13 = V_8 -> V_14 ;
else
V_13 = ( void * * ) V_3 ;
for ( V_9 = 0 ; V_9 < V_5 ; V_9 ++ )
if ( V_3 [ V_9 ] )
V_13 [ V_10 ++ ] = F_2 ( V_3 [ V_9 ] ) + V_4 ;
V_5 = V_10 ;
V_12 = F_2 ( V_2 ) + V_4 ;
if ( V_8 -> V_15 & V_16 )
memset ( V_12 , 0 , V_6 ) ;
while ( V_5 > 0 ) {
V_10 = F_3 ( V_5 , V_17 ) ;
F_4 ( V_10 , V_6 , V_12 , & V_13 [ V_11 ] ) ;
V_5 -= V_10 ;
V_11 += V_10 ;
}
F_5 ( V_8 ) ;
}
struct V_18 *
F_6 ( struct V_1 * V_2 , struct V_1 * * V_3 , unsigned int V_4 ,
int V_5 , T_1 V_6 , struct V_7 * V_8 )
{
struct V_19 * V_20 = F_7 ( V_8 , V_21 ,
& V_2 , 1 , V_3 ,
V_5 , V_6 ) ;
T_2 * V_22 = NULL ;
F_8 ( V_5 <= 1 ) ;
if ( V_8 -> V_14 )
V_22 = V_8 -> V_14 ;
else if ( sizeof( T_2 ) <= sizeof( struct V_1 * ) )
V_22 = ( T_2 * ) V_3 ;
if ( V_22 && V_20 && F_9 ( V_20 -> V_23 , V_4 , 0 , V_6 ) ) {
F_10 ( L_1 , V_24 , V_6 ) ;
return F_11 ( V_20 , V_2 , V_3 , V_4 , V_5 , V_6 ,
V_22 , V_8 ) ;
} else {
F_10 ( L_2 , V_24 , V_6 ) ;
F_12 ( V_20 , L_3 ,
V_24 ) ;
if ( V_8 -> V_15 & V_25 ) {
V_5 -- ;
V_3 ++ ;
}
F_13 ( & V_8 -> V_26 ) ;
F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_8 ) ;
return NULL ;
}
}
static int F_14 ( struct V_1 * V_27 , unsigned int V_4 , T_1 V_6 )
{
char * V_28 = F_2 ( V_27 ) + V_4 ;
return ( ( * ( V_29 * ) V_28 ) == 0 &&
memcmp ( V_28 , V_28 + 4 , V_6 - 4 ) == 0 ) ;
}
static inline struct V_19 *
F_15 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_1 * * V_3 , int V_5 , T_1 V_6 )
{
#ifdef F_16
return NULL ;
#endif
return F_7 ( V_8 , V_30 , & V_2 , 1 , V_3 ,
V_5 , V_6 ) ;
}
struct V_18 *
F_17 ( struct V_1 * V_2 , struct V_1 * * V_3 , unsigned int V_4 ,
int V_5 , T_1 V_6 , enum V_31 * V_32 ,
struct V_7 * V_8 )
{
struct V_19 * V_20 = F_15 ( V_8 , V_2 , V_3 , V_5 , V_6 ) ;
struct V_33 * V_23 = V_20 ? V_20 -> V_23 : NULL ;
struct V_18 * V_34 = NULL ;
T_2 * V_22 = NULL ;
F_8 ( V_5 <= 1 ) ;
if ( V_8 -> V_14 )
V_22 = V_8 -> V_14 ;
else if ( sizeof( T_2 ) <= sizeof( struct V_1 * ) )
V_22 = ( T_2 * ) V_3 ;
if ( V_22 && V_23 && V_5 <= V_23 -> V_35 &&
F_9 ( V_23 , V_4 , 0 , V_6 ) ) {
unsigned long V_36 = 0 ;
int V_9 ;
F_10 ( L_4 , V_24 , V_6 ) ;
if ( V_8 -> V_37 )
V_36 |= V_38 ;
if ( V_8 -> V_15 & V_39 )
V_36 |= V_40 ;
for ( V_9 = 0 ; V_9 < V_5 ; V_9 ++ )
V_22 [ V_9 ] = F_18 ( V_23 -> V_41 , V_3 [ V_9 ] ,
V_4 , V_6 , V_42 ) ;
V_34 = V_23 -> V_43 ( V_20 , V_22 , V_5 ,
V_6 , V_32 ,
V_36 ) ;
if ( F_19 ( ! V_34 ) ) {
F_13 ( & V_8 -> V_26 ) ;
while ( ! V_34 ) {
F_20 ( V_20 ) ;
V_34 = V_23 -> V_43 ( V_20 ,
V_22 , V_5 , V_6 , V_32 ,
V_36 ) ;
}
}
F_21 ( V_20 , V_34 , V_8 ) ;
} else {
enum V_44 V_45 = V_8 -> V_15 ;
F_10 ( L_5 , V_24 , V_6 ) ;
F_12 ( V_23 && V_5 <= V_23 -> V_35 ,
L_3 ,
V_24 ) ;
V_8 -> V_15 |= V_25 ;
V_8 -> V_15 &= ~ V_46 ;
V_34 = F_6 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_8 ) ;
F_13 ( & V_34 ) ;
* V_32 = ! F_14 ( V_2 , V_4 , V_6 ) << V_47 ;
F_5 ( V_8 ) ;
V_8 -> V_15 = V_45 ;
}
return V_34 ;
}
