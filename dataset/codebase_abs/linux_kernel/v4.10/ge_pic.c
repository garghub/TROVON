static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
V_5 = F_3 () ;
if ( V_5 )
F_4 ( V_5 ) ;
V_4 -> V_6 ( & V_2 -> V_7 ) ;
}
static void F_5 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
unsigned int V_10 = F_6 ( V_8 ) ;
T_1 V_11 ;
F_7 ( & V_12 , V_9 ) ;
V_11 = F_8 ( V_13 + F_9 ( 0 ) ) ;
V_11 &= ~ ( 1 << V_10 ) ;
F_10 ( V_13 + F_9 ( 0 ) , V_11 ) ;
F_11 ( & V_12 , V_9 ) ;
}
static void F_12 ( struct V_7 * V_8 )
{
F_5 ( V_8 ) ;
}
static void F_13 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
unsigned int V_10 = F_6 ( V_8 ) ;
T_1 V_11 ;
F_7 ( & V_12 , V_9 ) ;
V_11 = F_8 ( V_13 + F_9 ( 0 ) ) ;
V_11 |= ( 1 << V_10 ) ;
F_10 ( V_13 + F_9 ( 0 ) , V_11 ) ;
F_11 ( & V_12 , V_9 ) ;
}
static int F_14 ( struct V_14 * V_15 , unsigned int V_16 ,
T_2 V_10 )
{
F_15 ( V_16 , V_17 ) ;
F_16 ( V_16 , & V_18 , V_19 ) ;
return 0 ;
}
static int F_17 ( struct V_14 * V_15 , struct V_20 * V_21 ,
const T_1 * V_22 , unsigned int V_23 ,
T_2 * V_24 , unsigned int * V_25 )
{
* V_24 = V_22 [ 0 ] ;
if ( V_23 > 1 )
* V_25 = V_22 [ 1 ] ;
else
* V_25 = V_26 ;
return 0 ;
}
void T_3 F_18 ( struct V_20 * V_27 )
{
unsigned long V_9 ;
V_13 = F_19 ( V_27 , 0 ) ;
F_7 ( & V_12 , V_9 ) ;
F_10 ( V_13 + V_28 , 0 ) ;
F_10 ( V_13 + V_29 , 0 ) ;
F_10 ( V_13 + V_30 , 0 ) ;
F_10 ( V_13 + V_31 , 0 ) ;
F_11 ( & V_12 , V_9 ) ;
V_32 = F_20 ( V_27 , 0 ) ;
if ( ! V_32 ) {
F_21 ( V_33 L_1 ) ;
return;
}
V_34 = F_22 ( V_27 , V_35 ,
& V_36 , NULL ) ;
if ( V_34 == NULL )
return;
F_23 ( V_32 , F_1 ) ;
}
unsigned int F_3 ( void )
{
T_1 V_37 , V_11 , V_38 ;
unsigned int V_16 = 0 ;
int V_10 ;
V_37 = F_8 ( V_13 + V_39 ) ;
V_11 = F_8 ( V_13 + F_9 ( 0 ) ) ;
V_38 = V_37 & V_11 ;
if ( V_38 ) {
for ( V_10 = V_35 - 1 ; V_10 > - 1 ; V_10 -- ) {
if ( V_38 & ( 0x1 << V_10 ) )
break;
}
V_16 = F_24 ( V_34 ,
( T_2 ) V_10 ) ;
}
return V_16 ;
}
