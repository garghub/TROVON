int F_1 ( T_1 V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
unsigned long V_6 ;
T_1 V_7 = 0x0 ;
V_6 =
F_2 ( F_3
( V_4 , ( unsigned long ) V_2 ) ) ;
memcpy ( ( void * ) V_6 , ( void * ) & V_7 , sizeof( T_1 ) ) ;
F_4 ( V_6 , V_6 + 32 ) ;
return V_5 ;
}
int F_5 ( T_1 V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
unsigned long V_6 ;
T_1 V_7 = V_8 , V_9 , V_10 ;
V_9 = ( V_1 >> 21 ) & 0x1f ;
V_10 = V_1 & 0xffff ;
V_7 |= ( V_9 << 21 ) ;
V_7 |= V_10 ;
V_6 =
F_2 ( F_3
( V_4 , ( unsigned long ) V_2 ) ) ;
memcpy ( ( void * ) V_6 , ( void * ) & V_7 , sizeof( T_1 ) ) ;
F_4 ( V_6 , V_6 + 32 ) ;
return V_5 ;
}
int F_6 ( T_1 V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_11 , V_12 , V_13 ;
T_1 V_14 ;
unsigned long V_6 , V_15 ;
V_11 = ( V_1 >> 16 ) & 0x1f ;
V_12 = ( V_1 >> 11 ) & 0x1f ;
V_13 = V_1 & 0x7 ;
if ( ( V_12 == V_16 ) && ( V_13 == 0 ) ) {
V_14 = V_17 ;
V_14 |= ( ( V_11 & 0x1f ) << 16 ) ;
} else {
V_14 = V_18 ;
V_14 |= ( ( V_11 & 0x1f ) << 16 ) ;
V_14 |= F_7 ( struct V_19 ,
V_20 . V_21 [ V_12 ] [ V_13 ] ) ;
}
if ( F_8 ( V_2 ) == V_22 ) {
V_6 =
F_2 ( F_3
( V_4 , ( unsigned long ) V_2 ) ) ;
memcpy ( ( void * ) V_6 , ( void * ) & V_14 , sizeof( T_1 ) ) ;
F_4 ( V_6 , V_6 + 32 ) ;
} else if ( F_8 ( ( unsigned long ) V_2 ) == V_23 ) {
F_9 ( V_15 ) ;
memcpy ( ( void * ) V_2 , ( void * ) & V_14 , sizeof( T_1 ) ) ;
F_4 ( ( unsigned long ) V_2 ,
( unsigned long ) V_2 + 32 ) ;
F_10 ( V_15 ) ;
} else {
F_11 ( L_1 , V_24 , V_2 ) ;
return - V_25 ;
}
return 0 ;
}
int F_12 ( T_1 V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_11 , V_12 , V_13 ;
T_1 V_26 = V_27 ;
unsigned long V_6 , V_15 ;
V_11 = ( V_1 >> 16 ) & 0x1f ;
V_12 = ( V_1 >> 11 ) & 0x1f ;
V_13 = V_1 & 0x7 ;
V_26 |= ( ( V_11 & 0x1f ) << 16 ) ;
V_26 |= F_7 ( struct V_19 , V_20 . V_21 [ V_12 ] [ V_13 ] ) ;
if ( F_8 ( V_2 ) == V_22 ) {
V_6 =
F_2 ( F_3
( V_4 , ( unsigned long ) V_2 ) ) ;
memcpy ( ( void * ) V_6 , ( void * ) & V_26 , sizeof( T_1 ) ) ;
F_4 ( V_6 , V_6 + 32 ) ;
} else if ( F_8 ( ( unsigned long ) V_2 ) == V_23 ) {
F_9 ( V_15 ) ;
memcpy ( ( void * ) V_2 , ( void * ) & V_26 , sizeof( T_1 ) ) ;
F_4 ( ( unsigned long ) V_2 ,
( unsigned long ) V_2 + 32 ) ;
F_10 ( V_15 ) ;
} else {
F_11 ( L_1 , V_24 , V_2 ) ;
return - V_25 ;
}
return 0 ;
}
