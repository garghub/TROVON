static inline void F_1 ( void )
{
volatile T_1 * V_1 = ( void * ) F_2 ( V_2 ) ;
volatile T_1 * V_3 = ( void * ) F_2 ( V_4 ) ;
* V_1 = V_5 ;
* V_3 = 0 ;
F_3 () ;
}
static int F_4 ( struct V_6 * V_7 , int V_8 ,
int V_9 )
{
volatile T_1 * V_10 = ( void * ) F_2 ( V_2 ) ;
volatile T_1 * V_11 = ( void * ) F_2 ( V_12 ) ;
static const char V_13 [] = L_1 ;
static const char V_14 [] = L_2 ;
static const char V_15 [] = L_3 ;
static const char V_16 [] = L_4 ;
static const char V_17 [] = L_5 ;
static const char V_18 [] = L_6 ;
static const char V_19 [] = L_7 ;
static const char V_20 [] = L_8 ;
static const char V_21 [] [ 4 ] = { L_9 , L_10 } ;
const char * V_22 , * V_23 , * V_24 , * V_25 ;
unsigned long V_26 ;
T_1 V_1 = * V_10 ;
T_1 V_27 = * V_11 ;
int V_28 = V_29 ;
F_1 () ;
V_22 = V_9 ? V_14 : V_13 ;
V_23 = V_15 ;
V_26 = V_27 & V_30 ;
if ( V_26 < 0x10000000 ) {
V_24 = V_16 ;
V_25 = V_20 ;
} else {
V_24 = V_9 ? V_18 : V_17 ;
V_25 = V_19 ;
}
if ( V_8 )
V_28 = V_31 ;
if ( V_28 != V_31 )
F_5 ( V_32 L_11 ,
V_22 , V_23 , V_24 , V_25 , V_26 ) ;
if ( V_28 != V_31 && V_26 < 0x10000000 )
F_5 ( V_32 L_12
L_13 ,
( V_1 & V_33 ) >> 8 ,
V_21 [ ( V_1 & V_34 ) != 0 ] ,
V_21 [ ( V_1 & V_35 ) != 0 ] ,
V_21 [ ( V_1 & V_36 ) != 0 ] ,
V_21 [ ( V_1 & V_37 ) != 0 ] ) ;
return V_28 ;
}
int F_6 ( struct V_6 * V_7 , int V_8 )
{
return F_4 ( V_7 , V_8 , 0 ) ;
}
T_2 F_7 ( int V_38 , void * V_39 )
{
struct V_6 * V_7 = F_8 () ;
int V_28 = F_4 ( V_7 , 0 , 1 ) ;
if ( V_28 == V_40 )
return V_41 ;
F_5 ( V_32 L_14 ,
V_7 -> V_42 , V_7 -> V_7 [ 31 ] ) ;
F_9 ( L_15 , V_7 ) ;
}
void T_3 F_10 ( void )
{
volatile T_1 * V_43 = ( void * ) F_2 ( V_44 + V_45 ) ;
if ( F_11 () == V_46 )
* V_43 |= V_47 ;
F_12 () ;
F_1 () ;
}
