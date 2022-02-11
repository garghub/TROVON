void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
unsigned int V_6 ;
V_6 = F_3 () ;
if ( V_6 != V_7 )
F_4 ( V_6 ) ;
V_5 -> V_8 ( & V_3 -> V_9 ) ;
}
static void F_5 ( struct V_9 * V_10 )
{
unsigned long V_11 ;
unsigned int V_12 = F_6 ( V_10 ) ;
T_1 V_13 ;
F_7 ( & V_14 , V_11 ) ;
V_13 = F_8 ( V_15 + F_9 ( 0 ) ) ;
V_13 &= ~ ( 1 << V_12 ) ;
F_10 ( V_15 + F_9 ( 0 ) , V_13 ) ;
F_11 ( & V_14 , V_11 ) ;
}
static void F_12 ( struct V_9 * V_10 )
{
F_5 ( V_10 ) ;
}
static void F_13 ( struct V_9 * V_10 )
{
unsigned long V_11 ;
unsigned int V_12 = F_6 ( V_10 ) ;
T_1 V_13 ;
F_7 ( & V_14 , V_11 ) ;
V_13 = F_8 ( V_15 + F_9 ( 0 ) ) ;
V_13 |= ( 1 << V_12 ) ;
F_10 ( V_15 + F_9 ( 0 ) , V_13 ) ;
F_11 ( & V_14 , V_11 ) ;
}
static int F_14 ( struct V_16 * V_17 , unsigned int V_18 ,
T_2 V_12 )
{
F_15 ( V_18 , V_19 ) ;
F_16 ( V_18 , & V_20 , V_21 ) ;
return 0 ;
}
static int F_17 ( struct V_16 * V_17 , struct V_22 * V_23 ,
const T_1 * V_24 , unsigned int V_25 ,
T_2 * V_26 , unsigned int * V_27 )
{
* V_26 = V_24 [ 0 ] ;
if ( V_25 > 1 )
* V_27 = V_24 [ 1 ] ;
else
* V_27 = V_28 ;
return 0 ;
}
void T_3 F_18 ( struct V_22 * V_29 )
{
unsigned long V_11 ;
V_15 = F_19 ( V_29 , 0 ) ;
F_7 ( & V_14 , V_11 ) ;
F_10 ( V_15 + V_30 , 0 ) ;
F_10 ( V_15 + V_31 , 0 ) ;
F_10 ( V_15 + V_32 , 0 ) ;
F_10 ( V_15 + V_33 , 0 ) ;
F_11 ( & V_14 , V_11 ) ;
V_34 = F_20 ( V_29 , 0 ) ;
if ( V_34 == V_7 ) {
F_21 ( V_35 L_1 ) ;
return;
}
V_36 = F_22 ( V_29 , V_37 ,
& V_38 , NULL ) ;
if ( V_36 == NULL )
return;
F_23 ( V_34 , F_1 ) ;
}
unsigned int F_3 ( void )
{
T_1 V_39 , V_13 , V_40 ;
unsigned int V_18 = V_7 ;
int V_12 ;
V_39 = F_8 ( V_15 + V_41 ) ;
V_13 = F_8 ( V_15 + F_9 ( 0 ) ) ;
V_40 = V_39 & V_13 ;
if ( V_40 ) {
for ( V_12 = V_37 - 1 ; V_12 > - 1 ; V_12 -- ) {
if ( V_40 & ( 0x1 << V_12 ) )
break;
}
V_18 = F_24 ( V_36 ,
( T_2 ) V_12 ) ;
}
return V_18 ;
}
