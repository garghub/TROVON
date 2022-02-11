static void F_1 ( T_1 V_1 , T_1 V_2 , int V_3 )
{
if ( V_4 ) {
unsigned long V_5 ;
T_1 V_6 , V_7 ;
F_2 ( & V_8 , V_5 ) ;
V_6 = ( V_3 ?
( T_1 ) F_3 ( V_4 ) :
F_4 ( V_4 ) ) ;
V_7 = V_6 | V_1 ;
V_7 &= ~ V_2 ;
if ( ! V_3 )
V_7 &= ~ V_9 ;
if ( V_3 )
F_5 ( ( V_10 ) V_7 , V_4 ) ;
else
F_6 ( V_7 , V_4 ) ;
F_7 ( & V_8 , V_5 ) ;
}
}
static void F_8 ( T_1 V_11 , int V_12 , int V_3 )
{
T_1 V_1 = ( V_3 ? V_13 : V_14 ) ;
T_1 V_2 = 0 ;
if ( ! V_12 ) {
T_1 V_15 = V_2 ;
V_2 = V_1 ;
V_1 = V_15 ;
}
F_1 ( V_1 , V_2 , V_3 ) ;
}
void F_9 ( int V_12 )
{
int V_3 = V_16 == V_17 ;
T_1 V_11 ;
V_11 = ( V_3 ? V_13 : V_14 ) ;
F_8 ( V_11 , V_12 , V_3 ) ;
}
static void F_10 ( int V_12 )
{
F_8 ( V_18 , V_12 , 0 ) ;
}
void F_11 ( int V_12 )
{
switch( V_16 ) {
case V_19 :
F_10 ( V_12 ) ;
break;
case V_17 :
default:
break;
}
}
static int T_2 F_12 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_21 . V_24 ;
unsigned long V_25 ;
if ( ! strcmp ( V_23 -> V_26 -> V_27 , L_1 ) ) {
V_16 = V_17 ;
V_25 = sizeof( V_10 ) ;
} else if ( ! strcmp ( V_23 -> V_26 -> V_27 , L_2 ) ) {
V_16 = V_19 ;
V_25 = 1 ;
} else {
F_13 ( L_3 ,
V_23 -> V_26 -> V_27 ) ;
return - V_28 ;
}
V_4 = F_14 ( & V_21 -> V_29 [ 0 ] , 0 , V_25 , L_4 ) ;
if ( ! V_4 )
return - V_28 ;
F_13 ( V_30 L_5 ,
V_23 -> V_31 ) ;
if ( V_16 == V_17 )
F_9 ( V_32 ) ;
return 0 ;
}
static int T_3 F_15 ( void )
{
return F_16 ( & V_33 ) ;
}
