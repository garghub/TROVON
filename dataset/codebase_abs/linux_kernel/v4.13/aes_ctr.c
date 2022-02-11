static int F_1 ( struct V_1 * V_2 )
{
const char * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
V_5 =
F_4 ( V_3 , 0 , V_8 ) ;
if ( F_5 ( V_5 ) ) {
F_6 ( V_9
L_1 ,
V_3 , F_7 ( V_5 ) ) ;
return F_7 ( V_5 ) ;
}
F_6 ( V_10 L_2 ,
F_8 ( (struct V_1 * ) V_5 ) ) ;
F_9 (
V_5 ,
F_10 ( (struct V_4 * ) V_2 ) ) ;
V_7 -> V_5 = V_5 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_7 -> V_5 ) {
F_12 ( V_7 -> V_5 ) ;
V_7 -> V_5 = NULL ;
}
}
static int F_13 ( struct V_1 * V_2 , const T_1 * V_11 ,
unsigned int V_12 )
{
int V_13 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
F_14 () ;
F_15 () ;
F_16 () ;
V_13 = F_17 ( V_11 , V_12 * 8 , & V_7 -> V_14 ) ;
F_18 () ;
F_19 () ;
F_20 () ;
V_13 += F_21 ( V_7 -> V_5 , V_11 , V_12 ) ;
return V_13 ;
}
static void F_22 ( struct V_6 * V_7 ,
struct V_15 * V_16 )
{
T_1 * V_17 = V_16 -> V_18 ;
T_1 V_19 [ V_20 ] ;
T_1 * V_21 = V_16 -> V_21 . V_22 . V_23 ;
T_1 * V_24 = V_16 -> V_24 . V_22 . V_23 ;
unsigned int V_25 = V_16 -> V_25 ;
F_14 () ;
F_15 () ;
F_16 () ;
F_23 ( V_17 , V_19 , & V_7 -> V_14 ) ;
F_18 () ;
F_19 () ;
F_20 () ;
F_24 ( V_19 , V_21 , V_25 ) ;
memcpy ( V_24 , V_19 , V_25 ) ;
F_25 ( V_17 , V_20 ) ;
}
static int F_26 ( struct V_26 * V_27 ,
struct V_28 * V_24 ,
struct V_28 * V_21 , unsigned int V_25 )
{
int V_13 ;
T_2 V_29 ;
struct V_15 V_16 ;
struct V_6 * V_7 =
F_3 ( F_27 ( V_27 -> V_2 ) ) ;
struct V_26 V_30 = {
. V_2 = V_7 -> V_5 ,
. V_31 = V_27 -> V_31 ,
. V_32 = V_27 -> V_32
} ;
if ( F_28 () ) {
V_13 = F_29 ( & V_30 , V_24 , V_21 ,
V_25 ) ;
} else {
F_30 ( & V_16 , V_24 , V_21 , V_25 ) ;
V_13 = F_31 ( V_27 , & V_16 , V_20 ) ;
while ( ( V_25 = V_16 . V_25 ) >= V_20 ) {
F_14 () ;
F_15 () ;
F_16 () ;
F_32 ( V_16 . V_21 . V_22 . V_23 ,
V_16 . V_24 . V_22 . V_23 ,
( V_25 &
V_33 ) /
V_20 ,
& V_7 -> V_14 ,
V_16 . V_18 ) ;
F_18 () ;
F_19 () ;
F_20 () ;
V_29 = ( V_25 & V_33 ) / V_20 ;
if ( V_29 > 0 )
while ( V_29 -- )
F_25 ( V_16 . V_18 , V_20 ) ;
V_25 &= V_20 - 1 ;
V_13 = F_33 ( V_27 , & V_16 , V_25 ) ;
}
if ( V_16 . V_25 ) {
F_22 ( V_7 , & V_16 ) ;
V_13 = F_33 ( V_27 , & V_16 , 0 ) ;
}
}
return V_13 ;
}
