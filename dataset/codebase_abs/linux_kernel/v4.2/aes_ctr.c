static int F_1 ( struct V_1 * V_2 )
{
const char * V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! ( V_3 = F_3 ( V_2 ) ) ) {
F_4 ( V_8 L_1 ) ;
return - V_9 ;
}
V_5 =
F_5 ( V_3 , 0 , V_10 ) ;
if ( F_6 ( V_5 ) ) {
F_4 ( V_8
L_2 ,
V_3 , F_7 ( V_5 ) ) ;
return F_7 ( V_5 ) ;
}
F_4 ( V_11 L_3 ,
F_8 ( (struct V_1 * ) V_5 ) ) ;
F_9 (
V_5 ,
F_10 ( (struct V_4 * ) V_2 ) ) ;
V_7 -> V_5 = V_5 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_5 ) {
F_12 ( V_7 -> V_5 ) ;
V_7 -> V_5 = NULL ;
}
}
static int F_13 ( struct V_1 * V_2 , const T_1 * V_12 ,
unsigned int V_13 )
{
int V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_14 () ;
F_15 () ;
V_14 = F_16 ( V_12 , V_13 * 8 , & V_7 -> V_15 ) ;
F_17 () ;
V_14 += F_18 ( V_7 -> V_5 , V_12 , V_13 ) ;
return V_14 ;
}
static void F_19 ( struct V_6 * V_7 ,
struct V_16 * V_17 )
{
T_1 * V_18 = V_17 -> V_19 ;
T_1 V_20 [ V_21 ] ;
T_1 * V_22 = V_17 -> V_22 . V_23 . V_24 ;
T_1 * V_25 = V_17 -> V_25 . V_23 . V_24 ;
unsigned int V_26 = V_17 -> V_26 ;
F_14 () ;
F_15 () ;
F_20 ( V_18 , V_20 , & V_7 -> V_15 ) ;
F_17 () ;
F_21 ( V_20 , V_22 , V_26 ) ;
memcpy ( V_25 , V_20 , V_26 ) ;
F_22 ( V_18 , V_21 ) ;
}
static int F_23 ( struct V_27 * V_28 ,
struct V_29 * V_25 ,
struct V_29 * V_22 , unsigned int V_26 )
{
int V_14 ;
struct V_16 V_17 ;
struct V_6 * V_7 =
F_2 ( F_24 ( V_28 -> V_2 ) ) ;
struct V_27 V_30 = {
. V_2 = V_7 -> V_5 ,
. V_31 = V_28 -> V_31 ,
. V_32 = V_28 -> V_32
} ;
if ( F_25 () ) {
V_14 = F_26 ( & V_30 , V_25 , V_22 ,
V_26 ) ;
} else {
F_27 ( & V_17 , V_25 , V_22 , V_26 ) ;
V_14 = F_28 ( V_28 , & V_17 , V_21 ) ;
while ( ( V_26 = V_17 . V_26 ) >= V_21 ) {
F_14 () ;
F_15 () ;
F_29 ( V_17 . V_22 . V_23 . V_24 ,
V_17 . V_25 . V_23 . V_24 ,
( V_26 &
V_33 ) /
V_21 ,
& V_7 -> V_15 ,
V_17 . V_19 ) ;
F_17 () ;
F_22 ( V_17 . V_19 , V_21 ) ;
V_26 &= V_21 - 1 ;
V_14 = F_30 ( V_28 , & V_17 , V_26 ) ;
}
if ( V_17 . V_26 ) {
F_19 ( V_7 , & V_17 ) ;
V_14 = F_30 ( V_28 , & V_17 , 0 ) ;
}
}
return V_14 ;
}
