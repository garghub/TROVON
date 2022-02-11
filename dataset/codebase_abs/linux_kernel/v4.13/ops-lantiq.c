static int F_1 ( unsigned char V_1 , struct V_2 * V_3 ,
unsigned int V_4 , unsigned int V_5 , T_1 * V_6 )
{
unsigned long V_7 ;
unsigned long V_8 ;
T_1 V_9 ;
if ( ( V_3 -> V_10 != 0 ) || ( ( V_4 & 0xf8 ) > 0x78 )
|| ( ( V_4 & 0xf8 ) == 0 ) || ( ( V_4 & 0xf8 ) == 0x68 ) )
return 1 ;
F_2 ( & V_11 , V_8 ) ;
V_7 = ( unsigned long ) V_12 ;
V_7 |= ( V_3 -> V_10 << V_13 ) | ( V_4 <<
V_14 ) | ( V_5 & ~ 0x3 ) ;
if ( V_1 == V_15 ) {
F_3 ( F_4 ( * V_6 ) , ( ( T_1 * ) V_7 ) ) ;
} else {
* V_6 = F_5 ( ( ( T_1 * ) ( V_7 ) ) ) ;
* V_6 = F_4 ( * V_6 ) ;
}
F_6 () ;
V_7 = ( unsigned long ) V_12 ;
V_7 |= ( 0x0 << V_14 ) + 4 ;
V_9 = F_5 ( ( ( T_1 * ) ( V_7 ) ) ) ;
V_9 = F_4 ( V_9 ) ;
V_7 = ( unsigned long ) V_12 ;
V_7 |= ( 0x68 << V_14 ) + 4 ;
F_3 ( V_9 , ( ( T_1 * ) V_7 ) ) ;
F_7 ( & V_11 , V_8 ) ;
if ( ( ( * V_6 ) == 0xffffffff ) && ( V_1 == V_16 ) )
return 1 ;
return 0 ;
}
int F_8 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , int V_17 , T_1 * V_18 )
{
T_1 V_6 = 0 ;
if ( F_1 ( V_16 , V_3 , V_4 , V_5 , & V_6 ) )
return V_19 ;
if ( V_17 == 1 )
* V_18 = ( V_6 >> ( ( V_5 & 3 ) << 3 ) ) & 0xff ;
else if ( V_17 == 2 )
* V_18 = ( V_6 >> ( ( V_5 & 3 ) << 3 ) ) & 0xffff ;
else
* V_18 = V_6 ;
return V_20 ;
}
int F_9 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , int V_17 , T_1 V_18 )
{
T_1 V_6 = 0 ;
if ( V_17 == 4 ) {
V_6 = V_18 ;
} else {
if ( F_1 ( V_16 , V_3 ,
V_4 , V_5 , & V_6 ) )
return V_19 ;
if ( V_17 == 1 )
V_6 = ( V_6 & ~ ( 0xff << ( ( V_5 & 3 ) << 3 ) ) ) |
( V_18 << ( ( V_5 & 3 ) << 3 ) ) ;
else if ( V_17 == 2 )
V_6 = ( V_6 & ~ ( 0xffff << ( ( V_5 & 3 ) << 3 ) ) ) |
( V_18 << ( ( V_5 & 3 ) << 3 ) ) ;
}
if ( F_1 ( V_15 , V_3 , V_4 , V_5 , & V_6 ) )
return V_19 ;
return V_20 ;
}
