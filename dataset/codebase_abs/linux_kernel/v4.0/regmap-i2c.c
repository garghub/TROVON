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
static int F_10 ( void * V_1 , unsigned int V_2 ,
unsigned int * V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
int V_8 ;
if ( V_2 > 0xff )
return - V_9 ;
V_8 = F_11 ( V_7 , V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
* V_3 = V_8 ;
return 0 ;
}
static int F_12 ( void * V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
if ( V_3 > 0xffff || V_2 > 0xff )
return - V_9 ;
return F_13 ( V_7 , V_2 , V_3 ) ;
}
static int F_14 ( void * V_1 , const void * V_10 , T_1 V_11 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
int V_8 ;
V_8 = F_15 ( V_7 , V_10 , V_11 ) ;
if ( V_8 == V_11 )
return 0 ;
else if ( V_8 < 0 )
return V_8 ;
else
return - V_12 ;
}
static int F_16 ( void * V_1 ,
const void * V_2 , T_1 V_13 ,
const void * V_3 , T_1 V_14 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_15 V_16 [ 2 ] ;
int V_8 ;
if ( ! F_17 ( V_7 -> V_17 , V_18 ) )
return - V_19 ;
V_16 [ 0 ] . V_20 = V_7 -> V_20 ;
V_16 [ 0 ] . V_21 = 0 ;
V_16 [ 0 ] . V_22 = V_13 ;
V_16 [ 0 ] . V_23 = ( void * ) V_2 ;
V_16 [ 1 ] . V_20 = V_7 -> V_20 ;
V_16 [ 1 ] . V_21 = V_24 ;
V_16 [ 1 ] . V_22 = V_14 ;
V_16 [ 1 ] . V_23 = ( void * ) V_3 ;
V_8 = F_18 ( V_7 -> V_17 , V_16 , 2 ) ;
if ( V_8 == 2 )
return 0 ;
if ( V_8 < 0 )
return V_8 ;
else
return - V_12 ;
}
static int F_19 ( void * V_1 ,
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
V_8 = F_18 ( V_7 -> V_17 , V_16 , 2 ) ;
if ( V_8 == 2 )
return 0 ;
else if ( V_8 < 0 )
return V_8 ;
else
return - V_12 ;
}
static const struct V_26 * F_20 ( struct V_6 * V_7 ,
const struct V_27 * V_28 )
{
if ( F_17 ( V_7 -> V_17 , V_29 ) )
return & V_30 ;
else if ( V_28 -> V_31 == 16 && V_28 -> V_32 == 8 &&
F_17 ( V_7 -> V_17 ,
V_33 ) )
switch ( F_21 ( & V_7 -> V_5 , NULL , V_28 ) ) {
case V_34 :
return & V_35 ;
case V_36 :
return & V_37 ;
default:
break;
}
else if ( V_28 -> V_31 == 8 && V_28 -> V_32 == 8 &&
F_17 ( V_7 -> V_17 ,
V_38 ) )
return & V_39 ;
return F_22 ( - V_19 ) ;
}
struct V_40 * F_23 ( struct V_6 * V_7 ,
const struct V_27 * V_28 )
{
const struct V_26 * V_41 = F_20 ( V_7 , V_28 ) ;
if ( F_24 ( V_41 ) )
return F_25 ( V_41 ) ;
return F_26 ( & V_7 -> V_5 , V_41 , & V_7 -> V_5 , V_28 ) ;
}
struct V_40 * F_27 ( struct V_6 * V_7 ,
const struct V_27 * V_28 )
{
const struct V_26 * V_41 = F_20 ( V_7 , V_28 ) ;
if ( F_24 ( V_41 ) )
return F_25 ( V_41 ) ;
return F_28 ( & V_7 -> V_5 , V_41 , & V_7 -> V_5 , V_28 ) ;
}
