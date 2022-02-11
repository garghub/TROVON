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
static int F_20 ( void * V_1 , const void * V_10 ,
T_1 V_11 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
if ( V_11 < 1 )
return - V_9 ;
if ( V_11 >= V_26 )
return - V_27 ;
-- V_11 ;
return F_21 ( V_7 , ( ( V_28 * ) V_10 ) [ 0 ] , V_11 ,
( ( V_28 * ) V_10 + 1 ) ) ;
}
static int F_22 ( void * V_1 , const void * V_2 ,
T_1 V_13 , void * V_3 ,
T_1 V_14 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
int V_8 ;
if ( V_13 != 1 || V_14 < 1 )
return - V_9 ;
if ( V_14 >= V_26 )
return - V_27 ;
V_8 = F_23 ( V_7 , ( ( V_28 * ) V_2 ) [ 0 ] , V_14 , V_3 ) ;
if ( V_8 == V_14 )
return 0 ;
else if ( V_8 < 0 )
return V_8 ;
else
return - V_12 ;
}
static const struct V_29 * F_24 ( struct V_6 * V_7 ,
const struct V_30 * V_31 )
{
if ( F_17 ( V_7 -> V_17 , V_32 ) )
return & V_33 ;
else if ( V_31 -> V_34 == 8 &&
F_17 ( V_7 -> V_17 ,
V_35 ) )
return & V_36 ;
else if ( V_31 -> V_37 == 16 && V_31 -> V_34 == 8 &&
F_17 ( V_7 -> V_17 ,
V_38 ) )
switch ( F_25 ( & V_7 -> V_5 , NULL , V_31 ) ) {
case V_39 :
return & V_40 ;
case V_41 :
return & V_42 ;
default:
break;
}
else if ( V_31 -> V_37 == 8 && V_31 -> V_34 == 8 &&
F_17 ( V_7 -> V_17 ,
V_43 ) )
return & V_44 ;
return F_26 ( - V_19 ) ;
}
struct V_45 * F_27 ( struct V_6 * V_7 ,
const struct V_30 * V_31 ,
struct V_46 * V_47 ,
const char * V_48 )
{
const struct V_29 * V_49 = F_24 ( V_7 , V_31 ) ;
if ( F_28 ( V_49 ) )
return F_29 ( V_49 ) ;
return F_30 ( & V_7 -> V_5 , V_49 , & V_7 -> V_5 , V_31 ,
V_47 , V_48 ) ;
}
struct V_45 * F_31 ( struct V_6 * V_7 ,
const struct V_30 * V_31 ,
struct V_46 * V_47 ,
const char * V_48 )
{
const struct V_29 * V_49 = F_24 ( V_7 , V_31 ) ;
if ( F_28 ( V_49 ) )
return F_29 ( V_49 ) ;
return F_32 ( & V_7 -> V_5 , V_49 , & V_7 -> V_5 , V_31 ,
V_47 , V_48 ) ;
}
