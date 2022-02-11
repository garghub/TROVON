static int F_1 ( void * V_1 , unsigned int V_2 ,
unsigned int * V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
int V_8 ;
if ( V_2 > 0xff )
return - V_9 ;
V_8 = F_3 ( V_7 , V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
* V_3 = V_8 ;
return 0 ;
}
static int F_4 ( void * V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
if ( V_3 > 0xff || V_2 > 0xff )
return - V_9 ;
return F_5 ( V_7 , V_2 , V_3 ) ;
}
static int F_6 ( void * V_1 , unsigned int V_2 ,
unsigned int * V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
int V_8 ;
if ( V_2 > 0xff )
return - V_9 ;
V_8 = F_7 ( V_7 , V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
* V_3 = V_8 ;
return 0 ;
}
static int F_8 ( void * V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
if ( V_3 > 0xffff || V_2 > 0xff )
return - V_9 ;
return F_9 ( V_7 , V_2 , V_3 ) ;
}
static int F_10 ( void * V_1 , const void * V_10 , T_1 V_11 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
int V_8 ;
V_8 = F_11 ( V_7 , V_10 , V_11 ) ;
if ( V_8 == V_11 )
return 0 ;
else if ( V_8 < 0 )
return V_8 ;
else
return - V_12 ;
}
static int F_12 ( void * V_1 ,
const void * V_2 , T_1 V_13 ,
const void * V_3 , T_1 V_14 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_15 V_16 [ 2 ] ;
int V_8 ;
if ( ! F_13 ( V_7 -> V_17 , V_18 ) )
return - V_19 ;
V_16 [ 0 ] . V_20 = V_7 -> V_20 ;
V_16 [ 0 ] . V_21 = 0 ;
V_16 [ 0 ] . V_22 = V_13 ;
V_16 [ 0 ] . V_23 = ( void * ) V_2 ;
V_16 [ 1 ] . V_20 = V_7 -> V_20 ;
V_16 [ 1 ] . V_21 = V_24 ;
V_16 [ 1 ] . V_22 = V_14 ;
V_16 [ 1 ] . V_23 = ( void * ) V_3 ;
V_8 = F_14 ( V_7 -> V_17 , V_16 , 2 ) ;
if ( V_8 == 2 )
return 0 ;
if ( V_8 < 0 )
return V_8 ;
else
return - V_12 ;
}
static int F_15 ( void * V_1 ,
const void * V_2 , T_1 V_13 ,
void * V_3 , T_1 V_14 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_15 V_16 [ 2 ] ;
int V_8 ;
V_16 [ 0 ] . V_20 = V_7 -> V_20 ;
V_16 [ 0 ] . V_21 = 0 ;
V_16 [ 0 ] . V_22 = V_13 ;
V_16 [ 0 ] . V_23 = ( void * ) V_2 ;
V_16 [ 1 ] . V_20 = V_7 -> V_20 ;
V_16 [ 1 ] . V_21 = V_25 ;
V_16 [ 1 ] . V_22 = V_14 ;
V_16 [ 1 ] . V_23 = V_3 ;
V_8 = F_14 ( V_7 -> V_17 , V_16 , 2 ) ;
if ( V_8 == 2 )
return 0 ;
else if ( V_8 < 0 )
return V_8 ;
else
return - V_12 ;
}
static const struct V_26 * F_16 ( struct V_6 * V_7 ,
const struct V_27 * V_28 )
{
if ( F_13 ( V_7 -> V_17 , V_29 ) )
return & V_30 ;
else if ( V_28 -> V_31 == 16 && V_28 -> V_32 == 8 &&
F_13 ( V_7 -> V_17 ,
V_33 ) )
return & V_34 ;
else if ( V_28 -> V_31 == 8 && V_28 -> V_32 == 8 &&
F_13 ( V_7 -> V_17 ,
V_35 ) )
return & V_36 ;
return F_17 ( - V_19 ) ;
}
struct V_37 * F_18 ( struct V_6 * V_7 ,
const struct V_27 * V_28 )
{
const struct V_26 * V_38 = F_16 ( V_7 , V_28 ) ;
if ( F_19 ( V_38 ) )
return F_20 ( V_38 ) ;
return F_21 ( & V_7 -> V_5 , V_38 , & V_7 -> V_5 , V_28 ) ;
}
struct V_37 * F_22 ( struct V_6 * V_7 ,
const struct V_27 * V_28 )
{
const struct V_26 * V_38 = F_16 ( V_7 , V_28 ) ;
if ( F_19 ( V_38 ) )
return F_20 ( V_38 ) ;
return F_23 ( & V_7 -> V_5 , V_38 , & V_7 -> V_5 , V_28 ) ;
}
