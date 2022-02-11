static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static T_2 F_3 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_4 ( V_2 -> V_4 + V_3 ) ;
}
static T_3 F_5 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_6 ( V_2 -> V_4 + V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_2 V_3 ,
T_1 V_5 )
{
F_8 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_2 V_3 ,
T_2 V_5 )
{
F_10 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_2 V_3 ,
T_3 V_5 )
{
F_12 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_13 ( struct V_1 * V_2 , void * V_6 ,
T_4 V_7 , T_2 V_3 , T_1 V_8 )
{
void T_5 * V_9 = V_2 -> V_4 + V_3 ;
switch ( V_8 ) {
case sizeof( T_1 ) : {
T_1 * V_10 = V_6 ;
while ( V_7 ) {
* V_10 = F_14 ( V_9 ) ;
V_10 ++ ;
V_7 -- ;
}
break;
}
case sizeof( T_2 ) : {
T_6 * V_10 = V_6 ;
F_15 ( V_7 & 1 ) ;
while ( V_7 ) {
* V_10 = ( V_11 T_6 ) F_16 ( V_9 ) ;
V_10 ++ ;
V_7 -= 2 ;
}
break;
}
case sizeof( T_3 ) : {
T_7 * V_10 = V_6 ;
F_15 ( V_7 & 3 ) ;
while ( V_7 ) {
* V_10 = ( V_11 T_7 ) F_17 ( V_9 ) ;
V_10 ++ ;
V_7 -= 4 ;
}
break;
}
default:
F_15 ( 1 ) ;
}
}
static void F_18 ( struct V_1 * V_2 ,
const void * V_6 ,
T_4 V_7 , T_2 V_3 , T_1 V_8 )
{
void T_5 * V_9 = V_2 -> V_4 + V_3 ;
switch ( V_8 ) {
case sizeof( T_1 ) : {
const T_1 * V_10 = V_6 ;
while ( V_7 ) {
F_19 ( * V_10 , V_9 ) ;
V_10 ++ ;
V_7 -- ;
}
break;
}
case sizeof( T_2 ) : {
const T_6 * V_10 = V_6 ;
F_15 ( V_7 & 1 ) ;
while ( V_7 ) {
F_20 ( ( V_11 T_2 ) ( * V_10 ) , V_9 ) ;
V_10 ++ ;
V_7 -= 2 ;
}
break;
}
case sizeof( T_3 ) : {
const T_7 * V_10 = V_6 ;
F_15 ( V_7 & 3 ) ;
while ( V_7 ) {
F_21 ( ( V_11 T_3 ) ( * V_10 ) , V_9 ) ;
V_10 ++ ;
V_7 -= 4 ;
}
break;
}
default:
F_15 ( 1 ) ;
}
}
static T_3 F_22 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_6 ( V_2 -> V_12 + V_3 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_2 V_3 ,
T_3 V_5 )
{
F_12 ( V_5 , V_2 -> V_12 + V_3 ) ;
}
int T_8 F_24 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
int V_17 ;
V_16 -> V_18 = F_25 ( V_19 , V_20 * 1 ) ;
if ( ! V_16 -> V_18 )
return - V_21 ;
V_16 -> V_22 = V_23 ;
V_16 -> V_24 = & V_25 ;
V_17 = F_26 ( V_16 , & V_14 -> V_26 , & V_14 -> V_27 ) ;
if ( V_17 )
F_27 ( V_16 -> V_18 ) ;
return V_17 ;
}
