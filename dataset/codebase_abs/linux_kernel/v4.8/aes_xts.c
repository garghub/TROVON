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
V_14 = F_14 ( V_2 , V_12 , V_13 ) ;
if ( V_14 )
return V_14 ;
F_15 () ;
F_16 () ;
F_17 () ;
V_14 = F_18 ( V_12 + V_13 / 2 , ( V_13 / 2 ) * 8 , & V_7 -> V_15 ) ;
V_14 += F_18 ( V_12 , ( V_13 / 2 ) * 8 , & V_7 -> V_16 ) ;
V_14 += F_19 ( V_12 , ( V_13 / 2 ) * 8 , & V_7 -> V_17 ) ;
F_20 () ;
F_21 () ;
F_22 () ;
V_14 += F_23 ( V_7 -> V_5 , V_12 , V_13 ) ;
return V_14 ;
}
static int F_24 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_20 * V_22 ,
unsigned int V_23 , int V_24 )
{
int V_14 ;
T_1 V_25 [ V_26 ] ;
T_1 * V_27 ;
struct V_28 V_29 ;
struct V_6 * V_7 =
F_2 ( F_25 ( V_19 -> V_2 ) ) ;
struct V_18 V_30 = {
. V_2 = V_7 -> V_5 ,
. V_31 = V_19 -> V_31 ,
. V_32 = V_19 -> V_32
} ;
if ( F_26 () ) {
V_14 = V_24 ? F_27 ( & V_30 , V_21 , V_22 , V_23 ) :
F_28 ( & V_30 , V_21 , V_22 , V_23 ) ;
} else {
F_15 () ;
F_16 () ;
F_17 () ;
F_29 ( & V_29 , V_21 , V_22 , V_23 ) ;
V_14 = F_30 ( V_19 , & V_29 ) ;
V_27 = V_29 . V_27 ;
memset ( V_25 , 0 , V_26 ) ;
F_31 ( V_27 , V_25 , & V_7 -> V_15 ) ;
while ( ( V_23 = V_29 . V_23 ) ) {
if ( V_24 )
F_32 ( V_29 . V_22 . V_33 . V_34 , V_29 . V_21 . V_33 . V_34 ,
V_23 & V_35 , & V_7 -> V_16 , NULL , V_25 ) ;
else
F_33 ( V_29 . V_22 . V_33 . V_34 , V_29 . V_21 . V_33 . V_34 ,
V_23 & V_35 , & V_7 -> V_17 , NULL , V_25 ) ;
V_23 &= V_26 - 1 ;
V_14 = F_34 ( V_19 , & V_29 , V_23 ) ;
}
F_20 () ;
F_21 () ;
F_22 () ;
}
return V_14 ;
}
static int F_35 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_20 * V_22 , unsigned int V_23 )
{
return F_24 ( V_19 , V_21 , V_22 , V_23 , 1 ) ;
}
static int F_36 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_20 * V_22 , unsigned int V_23 )
{
return F_24 ( V_19 , V_21 , V_22 , V_23 , 0 ) ;
}
