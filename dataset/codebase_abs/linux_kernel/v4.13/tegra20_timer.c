static int F_1 ( unsigned long V_1 ,
struct V_2 * V_3 )
{
T_1 V_4 ;
V_4 = 0x80000000 | ( ( V_1 > 1 ) ? ( V_1 - 1 ) : 0 ) ;
F_2 ( V_4 , V_5 + V_6 ) ;
return 0 ;
}
static inline void F_3 ( struct V_2 * V_3 )
{
F_2 ( 0 , V_5 + V_6 ) ;
}
static int F_4 ( struct V_2 * V_3 )
{
F_3 ( V_3 ) ;
return 0 ;
}
static int F_5 ( struct V_2 * V_3 )
{
T_1 V_4 = 0xC0000000 | ( ( 1000000 / V_7 ) - 1 ) ;
F_3 ( V_3 ) ;
F_2 ( V_4 , V_5 + V_6 ) ;
return 0 ;
}
static T_2 T_3 F_6 ( void )
{
return F_7 ( V_8 ) ;
}
static T_2 F_8 ( void )
{
T_1 V_9 = F_9 ( V_10 + V_11 ) ;
T_1 V_12 = F_9 ( V_10 + V_13 ) ;
return ( T_2 ) V_12 * V_14 + V_9 ;
}
static void F_10 ( struct V_15 * V_16 )
{
T_2 V_17 ;
V_18 = V_19 ;
V_19 = F_8 () ;
V_17 = V_19 - V_18 ;
F_11 ( & V_20 , V_17 * V_21 ) ;
* V_16 = V_20 ;
}
static unsigned long F_12 ( void )
{
return F_9 ( V_22 + V_8 ) ;
}
static T_4 F_13 ( int V_23 , void * V_24 )
{
struct V_2 * V_3 = (struct V_2 * ) V_24 ;
F_2 ( 1 << 30 , V_5 + V_25 ) ;
V_3 -> V_26 ( V_3 ) ;
return V_27 ;
}
static int T_5 F_14 ( struct V_28 * V_29 )
{
struct V_30 * V_30 ;
unsigned long V_31 ;
int V_32 ;
V_22 = F_15 ( V_29 , 0 ) ;
if ( ! V_22 ) {
F_16 ( L_1 ) ;
return - V_33 ;
}
V_34 . V_23 = F_17 ( V_29 , 2 ) ;
if ( V_34 . V_23 <= 0 ) {
F_16 ( L_2 ) ;
return - V_35 ;
}
V_30 = F_18 ( V_29 , 0 ) ;
if ( F_19 ( V_30 ) ) {
F_20 ( L_3 ) ;
V_31 = 12000000 ;
} else {
F_21 ( V_30 ) ;
V_31 = F_22 ( V_30 ) ;
}
switch ( V_31 ) {
case 12000000 :
F_2 ( 0x000b , V_36 ) ;
break;
case 13000000 :
F_2 ( 0x000c , V_36 ) ;
break;
case 19200000 :
F_2 ( 0x045f , V_36 ) ;
break;
case 26000000 :
F_2 ( 0x0019 , V_36 ) ;
break;
default:
F_23 ( 1 , L_4 ) ;
}
F_24 ( F_6 , 32 , 1000000 ) ;
V_32 = F_25 ( V_22 + V_8 ,
L_5 , 1000000 , 300 , 32 ,
V_37 ) ;
if ( V_32 ) {
F_16 ( L_6 ) ;
return V_32 ;
}
V_38 . V_39 =
F_12 ;
V_38 . V_40 = 1000000 ;
F_26 ( & V_38 ) ;
V_32 = F_27 ( V_34 . V_23 , & V_34 ) ;
if ( V_32 ) {
F_16 ( L_7 , V_32 ) ;
return V_32 ;
}
V_41 . V_42 = V_43 ;
V_41 . V_23 = V_34 . V_23 ;
F_28 ( & V_41 , 1000000 ,
0x1 , 0x1fffffff ) ;
return 0 ;
}
static int T_5 F_29 ( struct V_28 * V_29 )
{
struct V_30 * V_30 ;
V_10 = F_15 ( V_29 , 0 ) ;
if ( ! V_10 ) {
F_16 ( L_8 ) ;
return - V_33 ;
}
V_30 = F_18 ( V_29 , 0 ) ;
if ( F_19 ( V_30 ) )
F_20 ( L_9 ) ;
else
F_21 ( V_30 ) ;
return F_30 ( NULL , F_10 ) ;
}
