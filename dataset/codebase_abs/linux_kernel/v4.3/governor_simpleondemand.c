static int F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
int V_4 ;
struct V_5 * V_6 ;
unsigned long long V_7 , V_8 ;
unsigned int V_9 = V_10 ;
unsigned int V_11 = V_12 ;
struct V_13 * V_14 = V_2 -> V_14 ;
unsigned long V_15 = ( V_2 -> V_16 ) ? V_2 -> V_16 : V_17 ;
V_4 = F_2 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_6 = & V_2 -> V_18 ;
if ( V_14 ) {
if ( V_14 -> V_19 )
V_9 = V_14 -> V_19 ;
if ( V_14 -> V_20 )
V_11 = V_14 -> V_20 ;
}
if ( V_9 > 100 ||
V_9 < V_11 )
return - V_21 ;
if ( V_6 -> V_22 == 0 ) {
* V_3 = V_15 ;
return 0 ;
}
if ( V_6 -> V_23 >= ( 1 << 24 ) || V_6 -> V_22 >= ( 1 << 24 ) ) {
V_6 -> V_23 >>= 7 ;
V_6 -> V_22 >>= 7 ;
}
if ( V_6 -> V_23 * 100 >
V_6 -> V_22 * V_9 ) {
* V_3 = V_15 ;
return 0 ;
}
if ( V_6 -> V_24 == 0 ) {
* V_3 = V_15 ;
return 0 ;
}
if ( V_6 -> V_23 * 100 >
V_6 -> V_22 * ( V_9 - V_11 ) ) {
* V_3 = V_6 -> V_24 ;
return 0 ;
}
V_7 = V_6 -> V_23 ;
V_7 *= V_6 -> V_24 ;
V_8 = F_3 ( V_7 , V_6 -> V_22 ) ;
V_8 *= 100 ;
V_8 = F_3 ( V_8 , ( V_9 - V_11 / 2 ) ) ;
* V_3 = ( unsigned long ) V_8 ;
if ( V_2 -> V_25 && * V_3 < V_2 -> V_25 )
* V_3 = V_2 -> V_25 ;
if ( V_2 -> V_16 && * V_3 > V_2 -> V_16 )
* V_3 = V_2 -> V_16 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 ,
unsigned int V_26 , void * V_14 )
{
switch ( V_26 ) {
case V_27 :
F_5 ( V_1 ) ;
break;
case V_28 :
F_6 ( V_1 ) ;
break;
case V_29 :
F_7 ( V_1 , ( unsigned int * ) V_14 ) ;
break;
case V_30 :
F_8 ( V_1 ) ;
break;
case V_31 :
F_9 ( V_1 ) ;
break;
default:
break;
}
return 0 ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_32 ) ;
}
static void T_2 F_12 ( void )
{
int V_33 ;
V_33 = F_13 ( & V_32 ) ;
if ( V_33 )
F_14 ( L_1 , V_34 , V_33 ) ;
return;
}
