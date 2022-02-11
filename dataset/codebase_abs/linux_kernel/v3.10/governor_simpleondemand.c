static int F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
struct V_4 V_5 ;
int V_6 = V_2 -> V_7 -> V_8 ( V_2 -> V_9 . V_10 , & V_5 ) ;
unsigned long long V_11 , V_12 ;
unsigned int V_13 = V_14 ;
unsigned int V_15 = V_16 ;
struct V_17 * V_18 = V_2 -> V_18 ;
unsigned long V_19 = ( V_2 -> V_20 ) ? V_2 -> V_20 : V_21 ;
if ( V_6 )
return V_6 ;
if ( V_18 ) {
if ( V_18 -> V_22 )
V_13 = V_18 -> V_22 ;
if ( V_18 -> V_23 )
V_15 = V_18 -> V_23 ;
}
if ( V_13 > 100 ||
V_13 < V_15 )
return - V_24 ;
if ( V_5 . V_25 == 0 ) {
* V_3 = V_19 ;
return 0 ;
}
if ( V_5 . V_26 >= ( 1 << 24 ) || V_5 . V_25 >= ( 1 << 24 ) ) {
V_5 . V_26 >>= 7 ;
V_5 . V_25 >>= 7 ;
}
if ( V_5 . V_26 * 100 >
V_5 . V_25 * V_13 ) {
* V_3 = V_19 ;
return 0 ;
}
if ( V_5 . V_27 == 0 ) {
* V_3 = V_19 ;
return 0 ;
}
if ( V_5 . V_26 * 100 >
V_5 . V_25 * ( V_13 - V_15 ) ) {
* V_3 = V_5 . V_27 ;
return 0 ;
}
V_11 = V_5 . V_26 ;
V_11 *= V_5 . V_27 ;
V_12 = F_2 ( V_11 , V_5 . V_25 ) ;
V_12 *= 100 ;
V_12 = F_2 ( V_12 , ( V_13 - V_15 / 2 ) ) ;
* V_3 = ( unsigned long ) V_12 ;
if ( V_2 -> V_28 && * V_3 < V_2 -> V_28 )
* V_3 = V_2 -> V_28 ;
if ( V_2 -> V_20 && * V_3 > V_2 -> V_20 )
* V_3 = V_2 -> V_20 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_1 ,
unsigned int V_29 , void * V_18 )
{
switch ( V_29 ) {
case V_30 :
F_4 ( V_1 ) ;
break;
case V_31 :
F_5 ( V_1 ) ;
break;
case V_32 :
F_6 ( V_1 , ( unsigned int * ) V_18 ) ;
break;
case V_33 :
F_7 ( V_1 ) ;
break;
case V_34 :
F_8 ( V_1 ) ;
break;
default:
break;
}
return 0 ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_35 ) ;
}
static void T_2 F_11 ( void )
{
int V_36 ;
V_36 = F_12 ( & V_35 ) ;
if ( V_36 )
F_13 ( L_1 , V_37 , V_36 ) ;
return;
}
