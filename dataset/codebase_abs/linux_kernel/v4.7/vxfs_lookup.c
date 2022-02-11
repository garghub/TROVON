static inline T_1
F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 -> V_5 ;
return ( V_2 -> V_6 + V_3 - 1 ) & ~ ( V_3 - 1 ) ;
}
static inline int
F_2 ( int V_7 , const char * const V_8 , struct V_9 * V_10 )
{
if ( V_7 != V_10 -> V_11 )
return 0 ;
if ( ! V_10 -> V_12 )
return 0 ;
return ! memcmp ( V_8 , V_10 -> V_13 , V_7 ) ;
}
static inline struct V_9 *
F_3 ( struct V_9 * V_10 )
{
return ( (struct V_9 * ) ( ( char * ) V_10 + V_10 -> V_14 ) ) ;
}
static struct V_9 *
F_4 ( struct V_1 * V_2 , struct V_15 * V_16 , struct V_17 * * V_18 )
{
T_1 V_19 , V_17 , V_20 , V_21 , V_22 ;
T_1 V_3 = V_2 -> V_4 -> V_5 ;
const char * V_8 = V_16 -> V_13 . V_8 ;
int V_23 = V_16 -> V_13 . V_7 ;
V_19 = F_5 ( V_2 ) ;
V_20 = F_1 ( V_2 ) ;
V_21 = F_6 ( V_2 -> V_4 ) ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ ) {
T_2 V_24 ;
struct V_17 * V_25 ;
V_25 = F_7 ( V_2 -> V_26 , V_17 ) ;
if ( F_8 ( V_25 ) )
continue;
V_24 = ( T_2 ) F_9 ( V_25 ) ;
for ( V_22 = 0 ; V_22 <= V_20 && V_22 <= V_21 ; V_22 ++ ) {
T_2 V_27 , V_28 ;
struct V_29 * V_30 ;
struct V_9 * V_10 ;
V_27 = V_24 + ( V_22 * V_3 ) ;
V_28 = V_27 + V_3 - F_10 ( 1 ) ;
V_30 = (struct V_29 * ) V_27 ;
V_10 = (struct V_9 * ) ( V_27 + F_11 ( V_30 ) ) ;
for (; ( T_2 ) V_10 <= V_28 ; V_10 = F_3 ( V_10 ) ) {
if ( ! V_10 -> V_14 )
break;
if ( ! V_10 -> V_12 )
continue;
if ( F_2 ( V_23 , V_8 , V_10 ) ) {
* V_18 = V_25 ;
return ( V_10 ) ;
}
}
}
F_12 ( V_25 ) ;
}
return NULL ;
}
static T_3
F_13 ( struct V_1 * V_31 , struct V_15 * V_16 )
{
struct V_9 * V_10 ;
struct V_17 * V_25 ;
T_3 V_32 = 0 ;
V_10 = F_4 ( V_31 , V_16 , & V_25 ) ;
if ( V_10 ) {
V_32 = V_10 -> V_12 ;
F_14 ( V_25 ) ;
F_15 ( V_25 ) ;
}
return ( V_32 ) ;
}
static struct V_15 *
F_16 ( struct V_1 * V_31 , struct V_15 * V_16 , unsigned int V_33 )
{
struct V_1 * V_2 = NULL ;
T_3 V_32 ;
if ( V_16 -> V_13 . V_7 > V_34 )
return F_17 ( - V_35 ) ;
V_32 = F_13 ( V_31 , V_16 ) ;
if ( V_32 ) {
V_2 = F_18 ( V_31 -> V_4 , V_32 ) ;
if ( F_8 ( V_2 ) )
return F_19 ( V_2 ) ;
}
F_20 ( V_16 , V_2 ) ;
return NULL ;
}
static int
F_21 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_1 * V_2 = F_22 ( V_37 ) ;
struct V_40 * V_41 = V_2 -> V_4 ;
T_1 V_3 = V_41 -> V_5 ;
T_1 V_17 , V_19 , V_22 , V_21 , V_20 , V_42 ;
T_4 V_43 ;
if ( V_39 -> V_43 == 0 ) {
if ( ! F_23 ( V_37 , V_39 ) )
return 0 ;
V_39 -> V_43 = 1 ;
}
if ( V_39 -> V_43 == 1 ) {
if ( ! F_24 ( V_39 , L_1 , 2 , F_25 ( V_2 ) -> V_44 , V_45 ) )
return 0 ;
V_39 -> V_43 = 2 ;
}
V_43 = V_39 -> V_43 - 2 ;
if ( V_43 > F_26 ( V_2 -> V_6 ) )
return 0 ;
V_19 = F_5 ( V_2 ) ;
V_20 = F_1 ( V_2 ) ;
V_21 = F_6 ( V_41 ) ;
V_17 = V_43 >> V_46 ;
V_42 = V_43 & ~ V_47 ;
V_22 = ( T_1 ) ( V_43 >> V_41 -> V_48 ) % V_21 ;
for (; V_17 < V_19 ; V_17 ++ , V_22 = 0 ) {
char * V_24 ;
struct V_17 * V_25 ;
V_25 = F_7 ( V_2 -> V_26 , V_17 ) ;
if ( F_8 ( V_25 ) )
continue;
V_24 = ( char * ) F_9 ( V_25 ) ;
for (; V_22 <= V_20 && V_22 <= V_21 ; V_22 ++ ) {
char * V_27 , * V_28 ;
struct V_29 * V_30 ;
struct V_9 * V_10 ;
V_27 = V_24 + ( V_22 * V_3 ) ;
V_28 = V_27 + V_3 - F_10 ( 1 ) ;
V_30 = (struct V_29 * ) V_27 ;
V_10 = (struct V_9 * )
( V_42 ?
( V_24 + V_42 ) :
( V_27 + F_11 ( V_30 ) ) ) ;
for (; ( char * ) V_10 <= V_28 ; V_10 = F_3 ( V_10 ) ) {
if ( ! V_10 -> V_14 )
break;
if ( ! V_10 -> V_12 )
continue;
V_42 = ( char * ) V_10 - V_24 ;
V_39 -> V_43 = ( ( V_17 << V_46 ) | V_42 ) + 2 ;
if ( ! F_24 ( V_39 , V_10 -> V_13 , V_10 -> V_11 ,
V_10 -> V_12 , V_49 ) ) {
F_12 ( V_25 ) ;
return 0 ;
}
}
V_42 = 0 ;
}
F_12 ( V_25 ) ;
V_42 = 0 ;
}
V_39 -> V_43 = ( ( V_17 << V_46 ) | V_42 ) + 2 ;
return 0 ;
}
