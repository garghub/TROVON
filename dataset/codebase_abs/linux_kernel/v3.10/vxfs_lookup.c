static inline T_1
F_1 ( struct V_1 * V_1 )
{
return ( V_1 -> V_2 + V_3 - 1 ) >> V_4 ;
}
static inline T_1
F_2 ( struct V_1 * V_5 )
{
T_1 V_6 = V_5 -> V_7 -> V_8 ;
return ( V_5 -> V_2 + V_6 - 1 ) & ~ ( V_6 - 1 ) ;
}
static inline int
F_3 ( int V_9 , const char * const V_10 , struct V_11 * V_12 )
{
if ( V_9 != V_12 -> V_13 )
return 0 ;
if ( ! V_12 -> V_14 )
return 0 ;
return ! memcmp ( V_10 , V_12 -> V_15 , V_9 ) ;
}
static inline struct V_11 *
F_4 ( struct V_11 * V_12 )
{
return ( (struct V_11 * ) ( ( char * ) V_12 + V_12 -> V_16 ) ) ;
}
static struct V_11 *
F_5 ( struct V_1 * V_5 , struct V_17 * V_18 , struct V_19 * * V_20 )
{
T_1 V_21 , V_19 , V_22 , V_23 , V_24 ;
T_1 V_6 = V_5 -> V_7 -> V_8 ;
const char * V_10 = V_18 -> V_15 . V_10 ;
int V_25 = V_18 -> V_15 . V_9 ;
V_21 = F_1 ( V_5 ) ;
V_22 = F_2 ( V_5 ) ;
V_23 = F_6 ( V_5 -> V_7 ) ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
T_2 V_26 ;
struct V_19 * V_27 ;
V_27 = F_7 ( V_5 -> V_28 , V_19 ) ;
if ( F_8 ( V_27 ) )
continue;
V_26 = ( T_2 ) F_9 ( V_27 ) ;
for ( V_24 = 0 ; V_24 <= V_22 && V_24 <= V_23 ; V_24 ++ ) {
T_2 V_29 , V_30 ;
struct V_31 * V_32 ;
struct V_11 * V_12 ;
V_29 = V_26 + ( V_24 * V_6 ) ;
V_30 = V_29 + V_6 - F_10 ( 1 ) ;
V_32 = (struct V_31 * ) V_29 ;
V_12 = (struct V_11 * ) ( V_29 + F_11 ( V_32 ) ) ;
for (; ( T_2 ) V_12 <= V_30 ; V_12 = F_4 ( V_12 ) ) {
if ( ! V_12 -> V_16 )
break;
if ( ! V_12 -> V_14 )
continue;
if ( F_3 ( V_25 , V_10 , V_12 ) ) {
* V_20 = V_27 ;
return ( V_12 ) ;
}
}
}
F_12 ( V_27 ) ;
}
return NULL ;
}
static T_3
F_13 ( struct V_1 * V_33 , struct V_17 * V_18 )
{
struct V_11 * V_12 ;
struct V_19 * V_27 ;
T_3 V_34 = 0 ;
V_12 = F_5 ( V_33 , V_18 , & V_27 ) ;
if ( V_12 ) {
V_34 = V_12 -> V_14 ;
F_14 ( V_27 ) ;
F_15 ( V_27 ) ;
}
return ( V_34 ) ;
}
static struct V_17 *
F_16 ( struct V_1 * V_33 , struct V_17 * V_18 , unsigned int V_35 )
{
struct V_1 * V_5 = NULL ;
T_3 V_34 ;
if ( V_18 -> V_15 . V_9 > V_36 )
return F_17 ( - V_37 ) ;
V_34 = F_13 ( V_33 , V_18 ) ;
if ( V_34 ) {
V_5 = F_18 ( V_33 -> V_7 , V_34 ) ;
if ( F_8 ( V_5 ) )
return F_19 ( V_5 ) ;
}
F_20 ( V_18 , V_5 ) ;
return NULL ;
}
static int
F_21 ( struct V_38 * V_39 , void * V_40 , T_4 V_41 )
{
struct V_1 * V_5 = F_22 ( V_39 ) ;
struct V_42 * V_43 = V_5 -> V_7 ;
T_1 V_6 = V_43 -> V_8 ;
T_1 V_19 , V_21 , V_24 , V_23 , V_22 , V_44 ;
T_5 V_45 ;
switch ( ( long ) V_39 -> V_46 ) {
case 0 :
if ( V_41 ( V_40 , L_1 , 1 , V_39 -> V_46 , V_5 -> V_47 , V_48 ) < 0 )
goto V_49;
V_39 -> V_46 ++ ;
case 1 :
if ( V_41 ( V_40 , L_2 , 2 , V_39 -> V_46 , F_23 ( V_5 ) -> V_50 , V_48 ) < 0 )
goto V_49;
V_39 -> V_46 ++ ;
}
V_45 = V_39 -> V_46 - 2 ;
if ( V_45 > F_24 ( V_5 -> V_2 ) )
return 0 ;
V_21 = F_1 ( V_5 ) ;
V_22 = F_2 ( V_5 ) ;
V_23 = F_6 ( V_43 ) ;
V_19 = V_45 >> V_4 ;
V_44 = V_45 & ~ V_51 ;
V_24 = ( T_1 ) ( V_45 >> V_43 -> V_52 ) % V_23 ;
for (; V_19 < V_21 ; V_19 ++ , V_24 = 0 ) {
T_2 V_26 ;
struct V_19 * V_27 ;
V_27 = F_7 ( V_5 -> V_28 , V_19 ) ;
if ( F_8 ( V_27 ) )
continue;
V_26 = ( T_2 ) F_9 ( V_27 ) ;
for (; V_24 <= V_22 && V_24 <= V_23 ; V_24 ++ ) {
T_2 V_29 , V_30 ;
struct V_31 * V_32 ;
struct V_11 * V_12 ;
V_29 = V_26 + ( V_24 * V_6 ) ;
V_30 = V_29 + V_6 - F_10 ( 1 ) ;
V_32 = (struct V_31 * ) V_29 ;
V_12 = (struct V_11 * )
( V_44 ?
( V_26 + V_44 ) :
( V_29 + F_11 ( V_32 ) ) ) ;
for (; ( T_2 ) V_12 <= V_30 ; V_12 = F_4 ( V_12 ) ) {
int V_53 ;
if ( ! V_12 -> V_16 )
break;
if ( ! V_12 -> V_14 )
continue;
V_44 = ( T_2 ) V_12 - V_26 ;
V_53 = V_41 ( V_40 , V_12 -> V_15 , V_12 -> V_13 ,
( ( V_19 << V_4 ) | V_44 ) + 2 ,
V_12 -> V_14 , V_54 ) ;
if ( V_53 ) {
F_12 ( V_27 ) ;
goto V_55;
}
}
V_44 = 0 ;
}
F_12 ( V_27 ) ;
V_44 = 0 ;
}
V_55:
V_39 -> V_46 = ( ( V_19 << V_4 ) | V_44 ) + 2 ;
V_49:
return 0 ;
}
