static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
V_5 = F_3 () ;
if ( V_5 != V_6 )
F_4 ( V_5 ) ;
V_4 -> V_7 ( & V_2 -> V_8 ) ;
}
static void F_5 ( struct V_8 * V_9 )
{
unsigned long V_10 ;
unsigned int V_11 = F_6 ( V_9 ) ;
T_1 V_12 ;
F_7 ( & V_13 , V_10 ) ;
V_12 = F_8 ( V_14 + F_9 ( 0 ) ) ;
V_12 &= ~ ( 1 << V_11 ) ;
F_10 ( V_14 + F_9 ( 0 ) , V_12 ) ;
F_11 ( & V_13 , V_10 ) ;
}
static void F_12 ( struct V_8 * V_9 )
{
F_5 ( V_9 ) ;
}
static void F_13 ( struct V_8 * V_9 )
{
unsigned long V_10 ;
unsigned int V_11 = F_6 ( V_9 ) ;
T_1 V_12 ;
F_7 ( & V_13 , V_10 ) ;
V_12 = F_8 ( V_14 + F_9 ( 0 ) ) ;
V_12 |= ( 1 << V_11 ) ;
F_10 ( V_14 + F_9 ( 0 ) , V_12 ) ;
F_11 ( & V_13 , V_10 ) ;
}
static int F_14 ( struct V_15 * V_16 , unsigned int V_17 ,
T_2 V_11 )
{
F_15 ( V_17 , V_18 ) ;
F_16 ( V_17 , & V_19 , V_20 ) ;
return 0 ;
}
static int F_17 ( struct V_15 * V_16 , struct V_21 * V_22 ,
const T_1 * V_23 , unsigned int V_24 ,
T_2 * V_25 , unsigned int * V_26 )
{
* V_25 = V_23 [ 0 ] ;
if ( V_24 > 1 )
* V_26 = V_23 [ 1 ] ;
else
* V_26 = V_27 ;
return 0 ;
}
void T_3 F_18 ( struct V_21 * V_28 )
{
unsigned long V_10 ;
V_14 = F_19 ( V_28 , 0 ) ;
F_7 ( & V_13 , V_10 ) ;
F_10 ( V_14 + V_29 , 0 ) ;
F_10 ( V_14 + V_30 , 0 ) ;
F_10 ( V_14 + V_31 , 0 ) ;
F_10 ( V_14 + V_32 , 0 ) ;
F_11 ( & V_13 , V_10 ) ;
V_33 = F_20 ( V_28 , 0 ) ;
if ( V_33 == V_6 ) {
F_21 ( V_34 L_1 ) ;
return;
}
V_35 = F_22 ( V_28 , V_36 ,
& V_37 , NULL ) ;
if ( V_35 == NULL )
return;
F_23 ( V_33 , F_1 ) ;
}
unsigned int F_3 ( void )
{
T_1 V_38 , V_12 , V_39 ;
unsigned int V_17 = V_6 ;
int V_11 ;
V_38 = F_8 ( V_14 + V_40 ) ;
V_12 = F_8 ( V_14 + F_9 ( 0 ) ) ;
V_39 = V_38 & V_12 ;
if ( V_39 ) {
for ( V_11 = V_36 - 1 ; V_11 > - 1 ; V_11 -- ) {
if ( V_39 & ( 0x1 << V_11 ) )
break;
}
V_17 = F_24 ( V_35 ,
( T_2 ) V_11 ) ;
}
return V_17 ;
}
