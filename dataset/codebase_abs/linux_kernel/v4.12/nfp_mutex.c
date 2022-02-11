static T_1 F_1 ( T_2 V_1 )
{
return ( T_1 ) V_1 << 16 | 0x000f ;
}
static T_1 F_2 ( T_2 V_1 )
{
return ( T_1 ) V_1 << 16 | 0x0000 ;
}
static bool F_3 ( T_1 V_2 )
{
return ( V_2 & 0xffff ) == 0x000f ;
}
static bool F_4 ( T_1 V_2 )
{
return ( V_2 & 0xffff ) == 0000 ;
}
static int
F_5 ( T_2 V_1 , int * V_3 , unsigned long long V_4 )
{
if ( F_6 ( V_1 ) ==
V_5 )
return - V_6 ;
if ( V_4 & 7 )
return - V_6 ;
if ( * V_3 != V_7 )
return - V_6 ;
return 0 ;
}
int F_7 ( struct V_8 * V_9 ,
int V_3 , unsigned long long V_4 , T_1 V_10 )
{
const T_1 V_11 = F_8 ( V_3 , 4 , 0 ) ;
T_2 V_1 = F_9 ( V_9 ) ;
int V_12 ;
V_12 = F_5 ( V_1 , & V_3 , V_4 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_10 ( V_9 , V_11 , V_4 + 4 , V_10 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_10 ( V_9 , V_11 , V_4 , F_1 ( V_1 ) ) ;
if ( V_12 )
return V_12 ;
return 0 ;
}
struct V_13 * F_11 ( struct V_8 * V_9 , int V_3 ,
unsigned long long V_4 , T_1 V_10 )
{
const T_1 V_14 = F_8 ( V_3 , 3 , 0 ) ;
T_2 V_1 = F_9 ( V_9 ) ;
struct V_13 * V_15 ;
int V_12 ;
T_1 V_16 ;
V_12 = F_5 ( V_1 , & V_3 , V_4 ) ;
if ( V_12 )
return NULL ;
V_12 = F_12 ( V_9 , V_14 , V_4 + 4 , & V_16 ) ;
if ( V_12 < 0 )
return NULL ;
if ( V_16 != V_10 )
return NULL ;
V_15 = F_13 ( sizeof( * V_15 ) , V_17 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_9 = V_9 ;
V_15 -> V_3 = V_3 ;
V_15 -> V_4 = V_4 ;
V_15 -> V_10 = V_10 ;
V_15 -> V_18 = 0 ;
return V_15 ;
}
void F_14 ( struct V_13 * V_15 )
{
F_15 ( V_15 ) ;
}
int F_16 ( struct V_13 * V_15 )
{
unsigned long V_19 = V_20 + 15 * V_21 ;
unsigned int V_22 = 1 ;
int V_12 ;
for (; ; ) {
V_12 = F_17 ( V_15 ) ;
if ( V_12 != - V_23 )
break;
V_12 = F_18 ( V_22 ) ;
if ( V_12 != 0 )
return - V_24 ;
if ( F_19 ( V_19 ) ) {
V_19 = V_20 + 60 * V_21 ;
F_20 ( V_15 -> V_9 ,
L_1 ,
V_15 -> V_18 ,
V_15 -> V_3 , V_15 -> V_4 , V_15 -> V_10 ) ;
}
}
return V_12 ;
}
int F_21 ( struct V_13 * V_15 )
{
const T_1 V_11 = F_8 ( V_15 -> V_3 , 4 , 0 ) ;
const T_1 V_14 = F_8 ( V_15 -> V_3 , 3 , 0 ) ;
struct V_8 * V_9 = V_15 -> V_9 ;
T_1 V_10 , V_25 ;
T_2 V_1 ;
int V_12 ;
V_1 = F_9 ( V_9 ) ;
if ( V_15 -> V_18 > 1 ) {
V_15 -> V_18 -- ;
return 0 ;
}
V_12 = F_12 ( V_15 -> V_9 , V_14 , V_15 -> V_4 + 4 , & V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_10 != V_15 -> V_10 )
return - V_26 ;
V_12 = F_12 ( V_15 -> V_9 , V_14 , V_15 -> V_4 , & V_25 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_25 != F_1 ( V_1 ) )
return - V_27 ;
V_12 = F_10 ( V_9 , V_11 , V_15 -> V_4 ,
F_2 ( V_1 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_15 -> V_18 = 0 ;
return 0 ;
}
int F_17 ( struct V_13 * V_15 )
{
const T_1 V_11 = F_8 ( V_15 -> V_3 , 4 , 0 ) ;
const T_1 V_28 = F_8 ( V_15 -> V_3 , 5 , 3 ) ;
const T_1 V_14 = F_8 ( V_15 -> V_3 , 3 , 0 ) ;
struct V_8 * V_9 = V_15 -> V_9 ;
T_1 V_10 , V_25 , V_16 ;
int V_12 ;
if ( V_15 -> V_18 > 0 ) {
if ( V_15 -> V_18 == V_29 )
return - V_30 ;
V_15 -> V_18 ++ ;
return 0 ;
}
V_12 = F_12 ( V_9 , V_14 , V_15 -> V_4 + 4 , & V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_10 != V_15 -> V_10 )
return - V_26 ;
V_25 = F_1 ( F_9 ( V_9 ) ) ;
V_12 = F_12 ( V_9 , V_28 , V_15 -> V_4 , & V_16 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( F_4 ( V_16 ) ) {
V_12 = F_10 ( V_9 , V_11 , V_15 -> V_4 , V_25 ) ;
if ( V_12 < 0 )
return V_12 ;
V_15 -> V_18 = 1 ;
return 0 ;
}
return F_3 ( V_16 ) ? - V_23 : - V_6 ;
}
