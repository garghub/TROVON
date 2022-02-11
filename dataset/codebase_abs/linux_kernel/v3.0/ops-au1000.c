void F_1 ( int V_1 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned long V_5 )
{
unsigned long V_6 ;
unsigned long V_7 ;
V_7 = F_2 () & 0xff ;
V_6 = F_3 () ;
F_4 ( V_1 ) ;
F_5 ( V_5 ) ;
F_6 ( V_4 ) ;
F_7 ( V_2 ) ;
F_8 ( V_3 ) ;
F_9 () ;
F_6 ( V_7 ) ;
F_5 ( V_6 ) ;
}
void T_1 F_10 ( void )
{
V_8 = F_11 ( 0x2000 , V_9 ) ;
if ( ! V_8 )
F_12 ( V_10 L_1 ) ;
V_11 = F_13 () ;
F_14 ( 0 , 0 , ( unsigned long ) V_8 -> V_12 , V_13 ) ;
V_14 = V_15 = 0xffffffff ;
}
static int F_15 ( unsigned char V_16 , struct V_17 * V_18 ,
unsigned int V_19 , unsigned char V_20 , T_2 * V_21 )
{
#if F_16 ( V_22 ) || F_16 ( V_23 )
unsigned int V_24 = F_17 ( V_19 ) ;
unsigned int V_25 = F_18 ( V_19 ) ;
unsigned long V_26 , V_27 ;
unsigned long V_28 ;
unsigned long V_29 ;
int error = V_30 ;
unsigned long V_31 , V_32 ;
if ( V_24 > 19 ) {
* V_21 = 0xffffffff ;
return - 1 ;
}
F_19 ( V_29 ) ;
F_20 ( ( ( 0x2000 << 16 ) | ( F_21 ( V_33 ) & 0xffff ) ) ,
V_33 ) ;
F_22 ( 1 ) ;
if ( V_34 && V_34 ( V_24 , 1 ) == 0 ) {
* V_21 = 0xffffffff ;
F_23 ( V_29 ) ;
return - 1 ;
}
if ( V_18 -> V_35 == 0 )
V_28 = ( 1 << V_24 ) << 11 ;
else
V_28 = 0x80000000 | ( V_18 -> V_35 << 16 ) | ( V_24 << 11 ) ;
V_26 = ( V_25 << 8 ) | ( V_20 & ~ 0x3 ) ;
V_26 |= V_28 & ~ V_36 ;
V_28 = V_28 & V_36 ;
V_31 = ( 6 << 26 ) | ( V_28 >> 6 ) | ( 2 << 3 ) | 7 ;
V_32 = ( 6 << 26 ) | ( V_28 >> 6 ) | ( 0x1000 >> 6 ) | ( 2 << 3 ) | 7 ;
if ( ( V_31 != V_14 ) || ( V_32 != V_15 ) ) {
F_1 ( V_11 , V_31 , V_32 ,
( unsigned long ) V_8 -> V_12 , V_13 ) ;
V_14 = V_31 ;
V_15 = V_32 ;
}
if ( V_16 == V_37 )
F_20 ( * V_21 , ( int ) ( V_8 -> V_12 + V_26 ) ) ;
else
* V_21 = F_21 ( ( int ) ( V_8 -> V_12 + V_26 ) ) ;
F_22 ( 2 ) ;
F_24 ( L_2 ,
V_16 , V_18 -> V_35 , V_24 , V_20 , * V_21 , V_26 ) ;
V_27 = F_21 ( V_33 ) ;
if ( V_27 & ( 1 << 29 ) ) {
* V_21 = 0xffffffff ;
error = - 1 ;
F_24 ( L_3 ) ;
} else if ( ( V_27 >> 28 ) & 0xf ) {
F_24 ( L_4 ,
V_24 , ( V_27 >> 28 ) & 0xf ) ;
F_20 ( V_27 & 0xf000ffff , V_33 ) ;
* V_21 = 0xffffffff ;
error = - 1 ;
}
if ( V_34 )
( void ) V_34 ( V_24 , 0 ) ;
F_23 ( V_29 ) ;
return error ;
#endif
}
static int F_25 ( struct V_17 * V_18 , unsigned int V_38 ,
int V_20 , T_3 * V_39 )
{
T_2 V_21 ;
int V_40 ;
V_40 = F_15 ( V_41 , V_18 , V_38 , V_20 , & V_21 ) ;
if ( V_20 & 1 )
V_21 >>= 8 ;
if ( V_20 & 2 )
V_21 >>= 16 ;
* V_39 = V_21 & 0xff ;
return V_40 ;
}
static int F_26 ( struct V_17 * V_18 , unsigned int V_38 ,
int V_20 , T_4 * V_39 )
{
T_2 V_21 ;
int V_40 ;
V_40 = F_15 ( V_41 , V_18 , V_38 , V_20 , & V_21 ) ;
if ( V_20 & 2 )
V_21 >>= 16 ;
* V_39 = V_21 & 0xffff ;
return V_40 ;
}
static int F_27 ( struct V_17 * V_18 , unsigned int V_38 ,
int V_20 , T_2 * V_39 )
{
int V_40 ;
V_40 = F_15 ( V_41 , V_18 , V_38 , V_20 , V_39 ) ;
return V_40 ;
}
static int F_28 ( struct V_17 * V_18 , unsigned int V_38 ,
int V_20 , T_3 V_39 )
{
T_2 V_21 = 0 ;
if ( F_15 ( V_41 , V_18 , V_38 , V_20 , & V_21 ) )
return - 1 ;
V_21 = ( V_21 & ~ ( 0xff << ( ( V_20 & 3 ) << 3 ) ) ) |
( V_39 << ( ( V_20 & 3 ) << 3 ) ) ;
if ( F_15 ( V_37 , V_18 , V_38 , V_20 , & V_21 ) )
return - 1 ;
return V_30 ;
}
static int F_29 ( struct V_17 * V_18 , unsigned int V_38 ,
int V_20 , T_4 V_39 )
{
T_2 V_21 = 0 ;
if ( F_15 ( V_41 , V_18 , V_38 , V_20 , & V_21 ) )
return - 1 ;
V_21 = ( V_21 & ~ ( 0xffff << ( ( V_20 & 3 ) << 3 ) ) ) |
( V_39 << ( ( V_20 & 3 ) << 3 ) ) ;
if ( F_15 ( V_37 , V_18 , V_38 , V_20 , & V_21 ) )
return - 1 ;
return V_30 ;
}
static int F_30 ( struct V_17 * V_18 , unsigned int V_38 ,
int V_20 , T_2 V_39 )
{
if ( F_15 ( V_37 , V_18 , V_38 , V_20 , & V_39 ) )
return - 1 ;
return V_30 ;
}
static int F_31 ( struct V_17 * V_18 , unsigned int V_38 ,
int V_20 , int V_42 , T_2 * V_39 )
{
switch ( V_42 ) {
case 1 : {
T_3 V_43 ;
int V_44 = F_25 ( V_18 , V_38 , V_20 , & V_43 ) ;
* V_39 = V_43 ;
return V_44 ;
}
case 2 : {
T_4 V_43 ;
int V_44 = F_26 ( V_18 , V_38 , V_20 , & V_43 ) ;
* V_39 = V_43 ;
return V_44 ;
}
default:
return F_27 ( V_18 , V_38 , V_20 , V_39 ) ;
}
}
static int F_32 ( struct V_17 * V_18 , unsigned int V_38 ,
int V_20 , int V_42 , T_2 V_39 )
{
switch ( V_42 ) {
case 1 :
return F_28 ( V_18 , V_38 , V_20 , ( T_3 ) V_39 ) ;
case 2 :
return F_29 ( V_18 , V_38 , V_20 , ( T_4 ) V_39 ) ;
default:
return F_30 ( V_18 , V_38 , V_20 , V_39 ) ;
}
}
