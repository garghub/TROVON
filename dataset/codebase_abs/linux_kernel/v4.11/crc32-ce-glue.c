static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
* V_3 = 0 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
* V_3 = ~ 0 ;
return 0 ;
}
static int F_4 ( struct V_4 * V_5 , const T_2 * V_3 ,
unsigned int V_6 )
{
T_1 * V_7 = F_5 ( V_5 ) ;
if ( V_6 != sizeof( T_1 ) ) {
F_6 ( V_5 , V_8 ) ;
return - V_9 ;
}
* V_7 = F_7 ( ( V_10 * ) V_3 ) ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 )
{
T_1 * V_7 = F_5 ( V_12 -> V_2 ) ;
T_1 * V_13 = F_9 ( V_12 ) ;
* V_13 = * V_7 ;
return 0 ;
}
static int F_10 ( struct V_11 * V_12 , const T_2 * V_14 ,
unsigned int V_15 )
{
T_1 * V_13 = F_9 ( V_12 ) ;
* V_13 = F_11 ( * V_13 , V_14 , V_15 ) ;
return 0 ;
}
static int F_12 ( struct V_11 * V_12 , const T_2 * V_14 ,
unsigned int V_15 )
{
T_1 * V_13 = F_9 ( V_12 ) ;
* V_13 = F_13 ( * V_13 , V_14 , V_15 ) ;
return 0 ;
}
static int F_14 ( struct V_11 * V_12 , const T_2 * V_14 ,
unsigned int V_15 )
{
T_1 * V_13 = F_9 ( V_12 ) ;
unsigned int V_16 ;
if ( ( V_17 ) V_14 % V_18 ) {
V_16 = F_15 ( T_1 , V_15 , V_18 - ( ( V_17 ) V_14 % V_18 ) ) ;
* V_13 = F_16 ( * V_13 , V_14 , V_16 ) ;
V_14 += V_16 ;
V_15 -= V_16 ;
}
if ( V_15 >= V_19 ) {
V_16 = F_17 ( V_15 , V_18 ) ;
F_18 ( 10 ) ;
* V_13 = F_19 ( V_14 , V_16 , * V_13 ) ;
F_20 () ;
V_14 += V_16 ;
V_15 -= V_16 ;
}
if ( V_15 > 0 )
* V_13 = F_16 ( * V_13 , V_14 , V_15 ) ;
return 0 ;
}
static int F_21 ( struct V_11 * V_12 , const T_2 * V_14 ,
unsigned int V_15 )
{
T_1 * V_13 = F_9 ( V_12 ) ;
unsigned int V_16 ;
if ( ( V_17 ) V_14 % V_18 ) {
V_16 = F_15 ( T_1 , V_15 , V_18 - ( ( V_17 ) V_14 % V_18 ) ) ;
* V_13 = F_22 ( * V_13 , V_14 , V_16 ) ;
V_14 += V_16 ;
V_15 -= V_16 ;
}
if ( V_15 >= V_19 ) {
V_16 = F_17 ( V_15 , V_18 ) ;
F_18 ( 10 ) ;
* V_13 = F_23 ( V_14 , V_16 , * V_13 ) ;
F_20 () ;
V_14 += V_16 ;
V_15 -= V_16 ;
}
if ( V_15 > 0 ) {
* V_13 = F_22 ( * V_13 , V_14 , V_15 ) ;
}
return 0 ;
}
static int F_24 ( struct V_11 * V_12 , T_2 * V_20 )
{
T_1 * V_13 = F_9 ( V_12 ) ;
F_25 ( * V_13 , V_20 ) ;
return 0 ;
}
static int F_26 ( struct V_11 * V_12 , T_2 * V_20 )
{
T_1 * V_13 = F_9 ( V_12 ) ;
F_25 ( ~ * V_13 , V_20 ) ;
return 0 ;
}
static int T_3 F_27 ( void )
{
if ( F_28 ( V_21 ) && ( V_22 & V_23 ) ) {
V_24 [ 0 ] . V_25 = F_14 ;
V_24 [ 1 ] . V_25 = F_21 ;
if ( V_22 & V_26 ) {
F_16 = F_11 ;
F_22 = F_13 ;
} else {
F_16 = V_27 ;
F_22 = V_28 ;
}
} else if ( ! ( V_22 & V_26 ) ) {
return - V_29 ;
}
return F_29 ( V_24 ,
F_30 ( V_24 ) ) ;
}
static void T_4 F_31 ( void )
{
F_32 ( V_24 ,
F_30 ( V_24 ) ) ;
}
