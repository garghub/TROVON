static bool F_1 ( T_1 V_1 ,
const T_1 V_2 [] ,
T_2 V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
if ( V_1 == V_2 [ V_4 ] )
return true ;
return false ;
}
static bool F_2 ( T_1 V_1 ,
const struct V_5 V_6 [] ,
T_2 V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
if ( V_1 <= V_6 [ V_4 ] . V_7 && V_1 >= V_6 [ V_4 ] . V_8 )
return true ;
return false ;
}
static bool F_3 ( struct V_9 * V_10 ,
T_1 V_11 )
{
static const T_1 V_12 [] = {
0x0000 ,
0x0500 , 0x0501 ,
0x0600 ,
0x0709 , 0x070C , 0x070D , 0x70E , 0x710 ,
0x0718 ,
0x1207 , 0x1208 ,
0x2007 ,
0x2300 ,
} ;
static const struct V_5 V_13 [] = {
{ 0x0200 , 0x0203 } ,
{ 0x0300 , 0x0303 } ,
{ 0x0400 , 0x0404 } ,
{ 0x0700 , 0x0707 } ,
{ 0x1100 , 0x1102 } ,
{ 0x1200 , 0x1204 } ,
{ 0x1300 , 0x1306 } ,
{ 0x2000 , 0x2005 } ,
{ 0x2100 , 0x2104 } ,
{ 0x2106 , 0x2106 } ,
{ 0x2200 , 0x220E } ,
{ 0x3100 , 0x3104 } ,
{ 0x3207 , 0x320F } ,
{ 0x3300 , 0x3304 } ,
{ 0x3500 , 0x3517 } ,
{ 0x3600 , 0x3617 } ,
{ 0x3700 , 0x3717 } ,
{ 0x4000 , 0x4003 } ,
} ;
return F_2 ( V_11 , V_13 ,
F_4 ( V_13 ) ) ||
F_1 ( V_11 , V_12 ,
F_4 ( V_12 ) ) ;
}
static bool F_5 ( struct V_9 * V_10 ,
T_1 V_11 )
{
static const T_1 V_12 [] = {
0x071B ,
0x1006 ,
0x2210 ,
0x3401 ,
} ;
static const struct V_5 V_13 [] = {
{ 0x2215 , 0x2219 } ,
} ;
return F_3 ( V_10 , V_11 ) ||
F_2 ( V_11 , V_13 ,
F_4 ( V_13 ) ) ||
F_1 ( V_11 , V_12 ,
F_4 ( V_12 ) ) ;
}
static bool F_6 ( struct V_9 * V_10 ,
T_1 V_11 )
{
static const T_1 V_12 [] = {
0x071C , 0x071D ,
0x1007 , 0x1008 ,
0x220F , 0x2214 ,
0x2301 ,
0x3105 , 0x3106 ,
0x3402 ,
} ;
static const struct V_5 V_13 [] = {
{ 0x0405 , 0x0411 } ,
{ 0x2008 , 0x200B } ,
{ 0x2220 , 0x2223 } ,
{ 0x3100 , 0x3106 } ,
} ;
return F_5 ( V_10 , V_11 ) ||
F_2 ( V_11 , V_13 ,
F_4 ( V_13 ) ) ||
F_1 ( V_11 , V_12 ,
F_4 ( V_12 ) ) ;
}
static bool F_7 ( struct V_9 * V_10 ,
T_1 V_11 )
{
static const T_3 V_14 [] = {
[ V_15 ] = F_3 ,
[ V_16 ] = F_5 ,
[ V_17 ] = F_6 ,
} ;
F_8 ( V_10 -> V_18 > V_17 ||
V_10 -> V_18 == - 1 ) ;
return V_14 [ V_10 -> V_18 ] ( V_10 , V_11 ) ;
}
static bool F_9 ( struct V_9 * V_10 ,
T_1 V_11 )
{
F_8 ( V_10 -> V_18 > V_17 ||
V_10 -> V_18 == - 1 ) ;
switch ( V_10 -> V_18 ) {
case V_15 :
return ( V_11 == 0x3200 ) ;
case V_16 :
return ( V_11 == 0x1006 ||
V_11 == 0x2210 ||
V_11 == 0x3200 ) ;
case V_17 :
return false ;
}
return false ;
}
static bool F_10 ( struct V_19 * V_20 ,
unsigned int V_21 )
{
struct V_22 * V_23 = F_11 ( V_20 ) ;
struct V_9 * V_10 = F_12 ( V_23 ) ;
return F_7 ( V_10 , ( T_1 ) V_21 ) ;
}
static bool F_13 ( struct V_19 * V_20 ,
unsigned int V_21 )
{
struct V_22 * V_23 = F_11 ( V_20 ) ;
struct V_9 * V_10 = F_12 ( V_23 ) ;
return F_7 ( V_10 , ( T_1 ) V_21 ) &&
! F_9 ( V_10 , ( T_1 ) V_21 ) ;
}
static int F_14 ( void * V_24 , unsigned int V_21 ,
unsigned int V_25 )
{
return F_15 ( V_24 , V_21 , V_25 ) ;
}
static int F_16 ( void * V_24 , unsigned int V_21 ,
unsigned * V_25 )
{
struct V_9 * V_10 = V_24 ;
int V_26 ;
V_26 = F_17 ( V_10 , V_21 ) ;
if ( V_26 < 0 )
return V_26 ;
* V_25 = V_26 ;
return 0 ;
}
struct V_27 * F_18 ( struct V_9 * V_10 )
{
return F_19 ( & V_10 -> V_23 -> V_20 , NULL ,
V_10 , & V_28 ) ;
}
