static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_3 , 0 , 0 , 0 ) ;
F_3 () ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
T_1 V_5 ;
F_5 ( 1 ) ;
V_5 = V_6 ;
F_2 ( V_2 , V_3 , 0 , V_4 ? 0 : V_5 , V_5 ) ;
if ( ! V_4 ) {
F_5 ( 2 ) ;
} else {
int V_7 ;
for ( V_7 = V_8 ; V_7 > 0 ; V_7 -= 2 ) {
if ( V_5 & F_2 ( V_2 , V_3 , 0 , 0 , 0 ) )
break;
F_5 ( 2 ) ;
}
if ( V_7 <= 0 )
F_6 ( V_2 , L_1 ,
V_8 ) ;
}
F_1 ( V_2 , V_3 ) ;
}
static T_2 F_7 ( struct V_1 * V_2 , T_1 V_3 , int V_9 )
{
T_1 V_10 , V_5 ;
V_5 = V_6 ;
F_2 ( V_2 , V_3 , 0 , 0 , V_5 ) ;
V_10 = F_2 ( V_2 , V_3 , 0 , 0 , 0 ) ;
if ( V_9 )
F_1 ( V_2 , V_3 ) ;
return ( V_10 & V_5 ) >> V_11 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
T_1 V_5 ;
V_5 = V_12 ;
F_2 ( V_2 , V_3 , 0 , V_4 ? 0 : V_5 , V_5 ) ;
F_1 ( V_2 , V_3 ) ;
F_5 ( 2 ) ;
}
static T_2 F_9 ( struct V_1 * V_2 , T_1 V_3 , int V_9 )
{
T_1 V_10 , V_5 ;
V_5 = V_12 ;
F_2 ( V_2 , V_3 , 0 , 0 , V_5 ) ;
V_10 = F_2 ( V_2 , V_3 , 0 , 0 , 0 ) ;
if ( V_9 )
F_1 ( V_2 , V_3 ) ;
return ( V_10 & V_5 ) >> V_13 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_14 ;
V_14 = F_9 ( V_2 , V_3 , 1 ) ;
F_4 ( V_2 , V_3 , 1 ) ;
V_14 = F_9 ( V_2 , V_3 , 1 ) == 0 ;
F_4 ( V_2 , V_3 , 0 ) ;
return V_14 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 , int V_15 )
{
int V_16 , V_17 ;
V_17 = 0 ;
for ( V_16 = 7 ; V_16 >= 0 ; -- V_16 ) {
V_17 <<= 1 ;
F_4 ( V_2 , V_3 , 1 ) ;
V_17 |= F_9 ( V_2 , V_3 , 0 ) ;
F_4 ( V_2 , V_3 , 0 ) ;
}
if ( V_15 ) {
F_4 ( V_2 , V_3 , 1 ) ;
F_12 ( V_2 , V_3 ) ;
} else {
F_8 ( V_2 , V_3 , 0 ) ;
F_4 ( V_2 , V_3 , 1 ) ;
F_4 ( V_2 , V_3 , 0 ) ;
F_8 ( V_2 , V_3 , 1 ) ;
}
return V_17 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_17 )
{
int V_16 ;
T_2 V_4 ;
for ( V_16 = 7 ; V_16 >= 0 ; V_16 -- ) {
V_4 = ( V_17 >> V_16 ) & 1 ;
F_8 ( V_2 , V_3 , V_4 ) ;
F_4 ( V_2 , V_3 , 1 ) ;
F_4 ( V_2 , V_3 , 0 ) ;
}
return ( ! F_10 ( V_2 , V_3 ) ) ? 1 : 0 ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_3 )
{
F_8 ( V_2 , V_3 , 1 ) ;
F_4 ( V_2 , V_3 , 1 ) ;
F_8 ( V_2 , V_3 , 0 ) ;
F_5 ( 1 ) ;
F_4 ( V_2 , V_3 , 0 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_3 )
{
F_4 ( V_2 , V_3 , 0 ) ;
F_8 ( V_2 , V_3 , 0 ) ;
F_4 ( V_2 , V_3 , 1 ) ;
F_8 ( V_2 , V_3 , 1 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_3 )
{
F_15 ( V_2 , V_3 ) ;
F_5 ( V_18 ) ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_19 = 9 ;
T_1 V_5 ;
V_5 = V_6 | V_12 ;
F_2 ( V_2 , V_3 , 0 , 0 , V_5 ) ;
if ( ! F_7 ( V_2 , V_3 , 0 ) )
return - V_20 ;
while ( V_19 -- ) {
if ( F_9 ( V_2 , V_3 , 0 ) )
return 0 ;
F_4 ( V_2 , V_3 , 0 ) ;
F_4 ( V_2 , V_3 , 1 ) ;
}
return - V_20 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_3 , int V_17 , int V_21 )
{
int V_22 = 1 ;
if ( V_21 & V_23 )
F_14 ( V_2 , V_3 ) ;
V_22 = F_13 ( V_2 , V_3 , V_17 ) ;
if ( V_21 & V_24 )
F_12 ( V_2 , V_3 ) ;
return V_22 ;
}
int F_18 ( struct V_1 * V_2 , T_1 V_3 , int V_25 , int V_26 ,
void * V_27 , int V_28 )
{
T_2 * V_29 = V_27 ;
int V_22 = 1 ;
int V_30 ;
int V_31 ;
V_31 = ( V_25 >> 8 ) & 0xff ;
V_25 &= 0xff ;
if ( V_31 > 2 )
goto V_32;
if ( V_25 == V_33 ) {
V_26 = ( V_26 << 1 ) | V_34 ;
V_22 = F_17 ( V_2 , V_3 , V_26 , V_23 ) ;
} else {
if ( V_31 ) {
V_22 = F_17 ( V_2 , V_3 ,
V_25 | V_35 , V_23 ) ;
if ( V_22 ) {
F_12 ( V_2 , V_3 ) ;
goto V_32;
}
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
V_22 = F_17 ( V_2 , V_3 ,
( V_26 >> ( V_30 * 8 ) ) & 0xff , 0 ) ;
F_5 ( V_18 ) ;
if ( V_22 ) {
F_6 ( V_2 , L_2 ,
V_30 , V_26 ) ;
goto V_32;
}
}
}
V_22 = F_17 ( V_2 , V_3 , V_25 | V_34 , V_23 ) ;
}
if ( V_22 ) {
F_12 ( V_2 , V_3 ) ;
goto V_32;
}
while ( V_28 -- > 0 ) {
* V_29 ++ = F_11 ( V_2 , V_3 , ! V_28 ) ;
}
V_22 = 0 ;
V_32:
return V_22 ;
}
int F_19 ( struct V_1 * V_2 , T_1 V_3 , int V_25 , int V_26 ,
const void * V_27 , int V_28 )
{
const T_2 * V_29 = V_27 ;
int V_22 = 1 ;
int V_30 ;
int V_31 ;
V_31 = ( V_25 >> 8 ) & 0xff ;
V_25 &= 0xff ;
if ( V_31 > 2 )
goto V_32;
if ( V_25 == V_33 ) {
if ( F_17 ( V_2 , V_3 , ( V_26 << 1 ) | V_35 ,
V_23 ) ) {
goto V_36;
}
} else {
if ( F_17 ( V_2 , V_3 , V_25 | V_35 , V_23 ) )
goto V_36;
}
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
V_22 = F_17 ( V_2 , V_3 , ( V_26 >> ( V_30 * 8 ) ) & 0xff , 0 ) ;
F_5 ( V_18 ) ;
if ( V_22 ) {
F_6 ( V_2 , L_2 ,
V_30 , V_26 ) ;
goto V_32;
}
}
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ )
if ( F_17 ( V_2 , V_3 , * V_29 ++ , 0 ) )
goto V_36;
V_22 = 0 ;
V_36:
F_12 ( V_2 , V_3 ) ;
V_32:
return V_22 ;
}
