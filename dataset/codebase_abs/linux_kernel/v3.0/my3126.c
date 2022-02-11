static int F_1 ( struct V_1 * V_1 , int V_2 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_1 )
{
F_3 ( & V_1 -> V_3 , V_4 / 30 ) ;
F_4 ( V_1 -> V_5 , V_6 , & V_1 -> V_7 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 )
{
F_6 ( & V_1 -> V_3 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_8 ( struct V_1 * V_1 )
{
T_1 V_8 ;
T_2 V_9 ;
T_2 V_10 ;
T_1 V_11 ;
T_3 * V_5 ;
V_5 = V_1 -> V_5 ;
if ( V_1 -> V_12 == 50 ) {
F_9 ( V_1 , V_13 , V_14 , & V_8 ) ;
V_9 = ( T_2 ) V_8 ;
V_10 = V_1 -> V_15 ^ V_9 ;
if ( V_10 & V_16 )
F_10 ( V_5 , 0 ) ;
V_1 -> V_15 = V_9 ;
V_1 -> V_12 = 0 ;
}
F_11 ( V_5 , F_12 ( V_17 ) ,
V_18 ) ;
F_4 ( V_5 ,
F_12 ( V_19 ) , & V_11 ) ;
F_4 ( V_5 ,
F_12 ( V_20 ) , & V_8 ) ;
V_11 += V_8 ;
F_4 ( V_5 , V_6 , & V_8 ) ;
V_1 -> V_7 = V_8 ;
if ( ( V_8 & ( 1 << 8 ) ) || ( V_8 & ( 1 << 19 ) ) ||
( V_1 -> V_11 == V_11 ) || V_1 -> V_21 ) {
if ( F_13 ( V_5 ) )
V_8 |= ( 1 << 9 ) ;
else if ( F_14 ( V_5 ) )
V_8 |= ( 1 << 20 ) ;
V_1 -> V_21 = 0 ;
} else {
if ( F_13 ( V_5 ) )
V_8 &= ~ ( 1 << 9 ) ;
else if ( F_14 ( V_5 ) )
V_8 &= ~ ( 1 << 20 ) ;
V_1 -> V_21 = 1 ;
}
F_11 ( V_5 , V_6 , V_8 ) ;
V_1 -> V_7 = V_8 ;
V_1 -> V_11 = V_11 ;
V_1 -> V_12 ++ ;
return V_22 ;
}
static void F_15 ( struct V_23 * V_24 )
{
struct V_1 * V_1 = F_16 ( V_24 , struct V_1 , V_3 . V_24 ) ;
F_8 ( V_1 ) ;
}
static int F_17 ( struct V_1 * V_1 , int V_25 )
{
return 0 ;
}
static int F_18 ( struct V_1 * V_1 ,
int * V_26 , int * V_27 , int * V_28 , int * V_29 )
{
T_1 V_8 ;
T_2 V_9 ;
T_3 * V_5 ;
V_5 = V_1 -> V_5 ;
F_9 ( V_1 , V_13 , V_14 , & V_8 ) ;
V_9 = ( T_2 ) V_8 ;
F_4 ( V_5 , V_6 , & V_8 ) ;
V_1 -> V_7 = V_8 ;
* V_26 = ( V_9 & V_16 ) ;
if ( * V_26 ) {
if ( F_13 ( V_5 ) )
V_8 &= ~ ( 1 << 8 ) ;
else if ( F_14 ( V_5 ) )
V_8 &= ~ ( 1 << 19 ) ;
} else {
if ( F_13 ( V_5 ) )
V_8 |= ( 1 << 8 ) ;
else if ( F_14 ( V_5 ) )
V_8 |= ( 1 << 19 ) ;
}
F_11 ( V_5 , V_6 , V_8 ) ;
V_1 -> V_7 = V_8 ;
* V_27 = V_30 ;
* V_28 = V_31 ;
if ( V_29 )
* V_29 = V_32 | V_33 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_1 )
{
F_20 ( V_1 ) ;
}
static struct V_1 * F_21 ( struct V_34 * V_35 ,
int V_36 , const struct V_37 * V_37 )
{
struct V_1 * V_1 = F_22 ( sizeof ( * V_1 ) , V_38 ) ;
if ( ! V_1 )
return NULL ;
F_23 ( V_1 , V_35 , V_36 , & V_39 , V_37 ) ;
F_24 ( & V_1 -> V_3 , F_15 ) ;
V_1 -> V_15 = 0 ;
return V_1 ;
}
static int F_25 ( T_3 * V_5 )
{
T_1 V_8 ;
F_4 ( V_5 , V_6 , & V_8 ) ;
V_8 &= ~ 4 ;
F_11 ( V_5 , V_6 , V_8 ) ;
F_26 ( 100 ) ;
F_11 ( V_5 , V_6 , V_8 | 4 ) ;
F_26 ( 1000 ) ;
F_4 ( V_5 , V_6 , & V_8 ) ;
V_8 |= 0x8000 ;
F_11 ( V_5 , V_6 , V_8 ) ;
F_27 ( 100 ) ;
return 0 ;
}
