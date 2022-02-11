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
struct V_22 * V_23 = V_20 ? V_20 -> V_23 : NULL ;
struct V_24 * V_25 = NULL ;
F_8 ( V_5 <= 1 ) ;
if ( V_23 )
V_25 = F_9 ( V_23 -> V_26 , V_5 + 1 , V_27 ) ;
if ( V_25 && F_10 ( V_23 , V_4 , 0 , V_6 ) ) {
struct V_18 * V_28 ;
int V_9 , V_29 ;
F_11 ( L_1 , V_30 , V_6 ) ;
V_25 -> V_6 = V_6 ;
for ( V_9 = 0 , V_29 = 0 ; V_9 < V_5 ; V_9 ++ ) {
if ( ! V_3 [ V_9 ] )
continue;
V_25 -> V_31 ++ ;
V_25 -> V_32 [ V_29 ++ ] = F_12 ( V_23 -> V_26 , V_3 [ V_9 ] ,
V_4 , V_6 , V_33 ) ;
}
V_25 -> V_32 [ V_29 ] = F_12 ( V_23 -> V_26 , V_2 , V_4 , V_6 ,
V_34 ) ;
V_25 -> V_35 = 1 ;
V_28 = F_13 ( V_20 , V_25 , V_8 ) ;
F_14 ( V_25 ) ;
return V_28 ;
} else {
F_14 ( V_25 ) ;
F_11 ( L_2 , V_30 , V_6 ) ;
F_15 ( V_20 , L_3 ,
V_30 ) ;
if ( V_8 -> V_15 & V_36 ) {
V_5 -- ;
V_3 ++ ;
}
F_16 ( & V_8 -> V_37 ) ;
F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_8 ) ;
return NULL ;
}
}
static int F_17 ( struct V_1 * V_38 , unsigned int V_4 , T_1 V_6 )
{
return ! F_18 ( F_2 ( V_38 ) + V_4 , 0 , V_6 ) ;
}
static inline struct V_19 *
F_19 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_1 * * V_3 , int V_5 , T_1 V_6 )
{
#ifdef F_20
return NULL ;
#endif
return F_7 ( V_8 , V_39 , & V_2 , 1 , V_3 ,
V_5 , V_6 ) ;
}
struct V_18 *
F_21 ( struct V_1 * V_2 , struct V_1 * * V_3 , unsigned int V_4 ,
int V_5 , T_1 V_6 , enum V_40 * V_41 ,
struct V_7 * V_8 )
{
struct V_19 * V_20 = F_19 ( V_8 , V_2 , V_3 , V_5 , V_6 ) ;
struct V_22 * V_23 = V_20 ? V_20 -> V_23 : NULL ;
struct V_18 * V_28 = NULL ;
struct V_24 * V_25 = NULL ;
F_8 ( V_5 <= 1 ) ;
if ( V_23 )
V_25 = F_9 ( V_23 -> V_26 , V_5 , V_27 ) ;
if ( V_25 && V_5 <= V_23 -> V_42 &&
F_10 ( V_23 , V_4 , 0 , V_6 ) ) {
unsigned long V_43 = 0 ;
int V_9 ;
F_11 ( L_4 , V_30 , V_6 ) ;
if ( V_8 -> V_44 )
V_43 |= V_45 ;
if ( V_8 -> V_15 & V_46 )
V_43 |= V_47 ;
for ( V_9 = 0 ; V_9 < V_5 ; V_9 ++ ) {
V_25 -> V_32 [ V_9 ] = F_12 ( V_23 -> V_26 , V_3 [ V_9 ] ,
V_4 , V_6 , V_33 ) ;
V_25 -> V_31 ++ ;
}
V_25 -> V_6 = V_6 ;
V_28 = V_23 -> V_48 ( V_20 , V_25 -> V_32 , V_5 ,
V_6 , V_41 ,
V_43 ) ;
if ( F_22 ( ! V_28 ) ) {
F_16 ( & V_8 -> V_37 ) ;
while ( ! V_28 ) {
F_23 ( V_20 ) ;
V_28 = V_23 -> V_48 ( V_20 ,
V_25 -> V_32 , V_5 , V_6 , V_41 ,
V_43 ) ;
}
}
F_24 ( V_28 , V_25 ) ;
F_25 ( V_20 , V_28 , V_8 ) ;
} else {
enum V_49 V_50 = V_8 -> V_15 ;
F_11 ( L_5 , V_30 , V_6 ) ;
F_15 ( V_23 && V_5 <= V_23 -> V_42 ,
L_3 ,
V_30 ) ;
V_8 -> V_15 |= V_36 ;
V_8 -> V_15 &= ~ V_51 ;
V_28 = F_6 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_8 ) ;
F_16 ( & V_28 ) ;
* V_41 = ! F_17 ( V_2 , V_4 , V_6 ) << V_52 ;
F_5 ( V_8 ) ;
V_8 -> V_15 = V_50 ;
}
F_14 ( V_25 ) ;
return V_28 ;
}
