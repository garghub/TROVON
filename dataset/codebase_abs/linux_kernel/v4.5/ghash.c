static int F_1 ( struct V_1 * V_2 )
{
const char * V_3 ;
struct V_4 * V_5 ;
struct V_4 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! ( V_3 = F_4 ( V_2 ) ) ) {
F_5 ( V_9 L_1 ) ;
return - V_10 ;
}
V_5 = F_6 ( V_3 , 0 , V_11 ) ;
if ( F_7 ( V_5 ) ) {
F_5 ( V_9
L_2 ,
V_3 , F_8 ( V_5 ) ) ;
return F_8 ( V_5 ) ;
}
F_5 ( V_12 L_3 ,
F_9 ( F_10 ( V_5 ) ) ) ;
F_11 ( V_5 ,
F_12 ( (struct V_4
* ) V_2 ) ) ;
V_8 -> V_5 = V_5 ;
V_6 -> V_13 = sizeof( struct V_14 )
+ F_13 ( V_5 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_5 ) {
F_15 ( V_8 -> V_5 ) ;
V_8 -> V_5 = NULL ;
}
}
static int F_16 ( struct V_15 * V_16 )
{
struct V_7 * V_8 = F_3 ( F_10 ( V_16 -> V_2 ) ) ;
struct V_14 * V_17 = F_17 ( V_16 ) ;
V_17 -> V_18 = 0 ;
memset ( V_17 -> V_19 , 0 , V_20 ) ;
V_17 -> V_21 . V_2 = V_8 -> V_5 ;
V_17 -> V_21 . V_22 = V_16 -> V_22 ;
return F_18 ( & V_17 -> V_21 ) ;
}
static int F_19 ( struct V_4 * V_2 , const T_1 * V_23 ,
unsigned int V_24 )
{
struct V_7 * V_8 = F_3 ( F_10 ( V_2 ) ) ;
if ( V_24 != V_25 )
return - V_26 ;
F_20 () ;
F_21 () ;
F_22 () ;
F_23 ( V_8 -> V_27 , ( const V_28 * ) V_23 ) ;
F_24 () ;
F_25 () ;
F_26 () ;
return F_27 ( V_8 -> V_5 , V_23 , V_24 ) ;
}
static int F_28 ( struct V_15 * V_16 ,
const T_1 * V_29 , unsigned int V_30 )
{
unsigned int V_31 ;
struct V_7 * V_8 = F_3 ( F_10 ( V_16 -> V_2 ) ) ;
struct V_14 * V_17 = F_17 ( V_16 ) ;
if ( V_32 ) {
return F_29 ( & V_17 -> V_21 , V_29 ,
V_30 ) ;
} else {
if ( V_17 -> V_18 ) {
if ( V_17 -> V_18 + V_30 < V_20 ) {
memcpy ( V_17 -> V_33 + V_17 -> V_18 , V_29 ,
V_30 ) ;
V_17 -> V_18 += V_30 ;
return 0 ;
}
memcpy ( V_17 -> V_33 + V_17 -> V_18 , V_29 ,
V_20 - V_17 -> V_18 ) ;
F_20 () ;
F_21 () ;
F_22 () ;
F_30 ( V_17 -> V_19 , V_8 -> V_27 ,
V_17 -> V_33 , V_20 ) ;
F_24 () ;
F_25 () ;
F_26 () ;
V_29 += V_20 - V_17 -> V_18 ;
V_30 -= V_20 - V_17 -> V_18 ;
V_17 -> V_18 = 0 ;
}
V_31 = V_30 & ~ ( V_20 - 1 ) ;
if ( V_31 ) {
F_20 () ;
F_21 () ;
F_22 () ;
F_30 ( V_17 -> V_19 , V_8 -> V_27 , V_29 , V_31 ) ;
F_24 () ;
F_25 () ;
F_26 () ;
V_29 += V_31 ;
V_30 -= V_31 ;
}
if ( V_30 ) {
memcpy ( V_17 -> V_33 , V_29 , V_30 ) ;
V_17 -> V_18 = V_30 ;
}
return 0 ;
}
}
static int F_31 ( struct V_15 * V_16 , T_1 * V_34 )
{
int V_35 ;
struct V_7 * V_8 = F_3 ( F_10 ( V_16 -> V_2 ) ) ;
struct V_14 * V_17 = F_17 ( V_16 ) ;
if ( V_32 ) {
return F_32 ( & V_17 -> V_21 , V_34 ) ;
} else {
if ( V_17 -> V_18 ) {
for ( V_35 = V_17 -> V_18 ; V_35 < V_20 ; V_35 ++ )
V_17 -> V_33 [ V_35 ] = 0 ;
F_20 () ;
F_21 () ;
F_22 () ;
F_30 ( V_17 -> V_19 , V_8 -> V_27 ,
V_17 -> V_33 , V_20 ) ;
F_24 () ;
F_25 () ;
F_26 () ;
V_17 -> V_18 = 0 ;
}
memcpy ( V_34 , V_17 -> V_19 , V_20 ) ;
return 0 ;
}
}
