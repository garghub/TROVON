static int F_1 ( struct V_1 * V_2 )
{
const char * V_3 = L_1 ;
struct V_4 * V_5 ;
struct V_4 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_5 = F_4 ( V_3 , 0 , V_9 ) ;
if ( F_5 ( V_5 ) ) {
F_6 ( V_10
L_2 ,
V_3 , F_7 ( V_5 ) ) ;
return F_7 ( V_5 ) ;
}
F_6 ( V_11 L_3 ,
F_8 ( F_9 ( V_5 ) ) ) ;
F_10 ( V_5 ,
F_11 ( (struct V_4
* ) V_2 ) ) ;
if ( V_6 -> V_12 < sizeof( struct V_13 )
+ F_12 ( V_5 ) ) {
F_6 ( V_10
L_4 ,
V_3 ,
V_6 -> V_12 - sizeof( struct V_13 ) ,
F_12 ( V_5 ) ) ;
return - V_14 ;
}
V_8 -> V_5 = V_5 ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_5 ) {
F_14 ( V_8 -> V_5 ) ;
V_8 -> V_5 = NULL ;
}
}
static int F_15 ( struct V_15 * V_16 )
{
struct V_7 * V_8 = F_3 ( F_9 ( V_16 -> V_2 ) ) ;
struct V_13 * V_17 = F_16 ( V_16 ) ;
V_17 -> V_18 = 0 ;
memset ( V_17 -> V_19 , 0 , V_20 ) ;
V_17 -> V_21 . V_2 = V_8 -> V_5 ;
V_17 -> V_21 . V_22 = V_16 -> V_22 ;
return F_17 ( & V_17 -> V_21 ) ;
}
static int F_18 ( struct V_4 * V_2 , const T_1 * V_23 ,
unsigned int V_24 )
{
struct V_7 * V_8 = F_3 ( F_9 ( V_2 ) ) ;
if ( V_24 != V_25 )
return - V_14 ;
F_19 () ;
F_20 () ;
F_21 () ;
F_22 ( V_8 -> V_26 , ( const V_27 * ) V_23 ) ;
F_23 () ;
F_24 () ;
F_25 () ;
return F_26 ( V_8 -> V_5 , V_23 , V_24 ) ;
}
static int F_27 ( struct V_15 * V_16 ,
const T_1 * V_28 , unsigned int V_29 )
{
unsigned int V_30 ;
struct V_7 * V_8 = F_3 ( F_9 ( V_16 -> V_2 ) ) ;
struct V_13 * V_17 = F_16 ( V_16 ) ;
if ( V_31 ) {
return F_28 ( & V_17 -> V_21 , V_28 ,
V_29 ) ;
} else {
if ( V_17 -> V_18 ) {
if ( V_17 -> V_18 + V_29 < V_20 ) {
memcpy ( V_17 -> V_32 + V_17 -> V_18 , V_28 ,
V_29 ) ;
V_17 -> V_18 += V_29 ;
return 0 ;
}
memcpy ( V_17 -> V_32 + V_17 -> V_18 , V_28 ,
V_20 - V_17 -> V_18 ) ;
F_19 () ;
F_20 () ;
F_21 () ;
F_29 ( V_17 -> V_19 , V_8 -> V_26 ,
V_17 -> V_32 , V_20 ) ;
F_23 () ;
F_24 () ;
F_25 () ;
V_28 += V_20 - V_17 -> V_18 ;
V_29 -= V_20 - V_17 -> V_18 ;
V_17 -> V_18 = 0 ;
}
V_30 = V_29 & ~ ( V_20 - 1 ) ;
if ( V_30 ) {
F_19 () ;
F_20 () ;
F_21 () ;
F_29 ( V_17 -> V_19 , V_8 -> V_26 , V_28 , V_30 ) ;
F_23 () ;
F_24 () ;
F_25 () ;
V_28 += V_30 ;
V_29 -= V_30 ;
}
if ( V_29 ) {
memcpy ( V_17 -> V_32 , V_28 , V_29 ) ;
V_17 -> V_18 = V_29 ;
}
return 0 ;
}
}
static int F_30 ( struct V_15 * V_16 , T_1 * V_33 )
{
int V_34 ;
struct V_7 * V_8 = F_3 ( F_9 ( V_16 -> V_2 ) ) ;
struct V_13 * V_17 = F_16 ( V_16 ) ;
if ( V_31 ) {
return F_31 ( & V_17 -> V_21 , V_33 ) ;
} else {
if ( V_17 -> V_18 ) {
for ( V_34 = V_17 -> V_18 ; V_34 < V_20 ; V_34 ++ )
V_17 -> V_32 [ V_34 ] = 0 ;
F_19 () ;
F_20 () ;
F_21 () ;
F_29 ( V_17 -> V_19 , V_8 -> V_26 ,
V_17 -> V_32 , V_20 ) ;
F_23 () ;
F_24 () ;
F_25 () ;
V_17 -> V_18 = 0 ;
}
memcpy ( V_33 , V_17 -> V_19 , V_20 ) ;
return 0 ;
}
}
