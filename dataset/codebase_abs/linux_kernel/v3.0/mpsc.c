static int F_1 ( void )
{
V_1 = F_2 ( ( V_2 * ) ( V_3 + V_4 ) ) & 0x00ff0000 ;
V_5 = F_2 ( ( V_2 * ) ( V_3 + V_6 ) ) & ~ ( V_7
| V_8 | V_9 | V_10
| V_11 ) ;
F_3 ( ( V_2 * ) ( V_3 + V_12 ) , V_13 ) ;
F_3 ( ( V_2 * ) ( V_3 + V_14 ) ,
V_15 | V_16 ) ;
F_3 ( ( V_2 * ) ( V_3 + V_6 ) , V_5 | V_11 ) ;
return 0 ;
}
static void F_4 ( unsigned char V_17 )
{
while ( F_2 ( ( V_2 * ) ( V_3 + V_6 ) ) & V_8 ) ;
F_3 ( ( V_2 * ) ( V_3 + V_4 ) , V_1 | V_17 ) ;
F_3 ( ( V_2 * ) ( V_3 + V_6 ) , V_5 | V_8 ) ;
}
static unsigned char F_5 ( void )
{
V_2 V_18 = 0 ;
unsigned char V_17 ;
while ( ! ( V_18 & V_19 ) )
V_18 = F_2 ( ( V_2 * ) ( V_20 + V_21 ) ) ;
V_17 = F_6 ( ( V_22 * ) ( V_3 + V_23 + 2 ) ) ;
F_7 ( ( V_22 * ) ( V_3 + V_23 + 2 ) , V_17 ) ;
F_3 ( ( V_2 * ) ( V_20 + V_21 ) ,
V_18 & ~ V_19 ) ;
return V_17 ;
}
static V_22 F_8 ( void )
{
return ( V_22 ) ( ( F_2 ( ( V_2 * ) ( V_20 + V_21 ) )
& V_19 ) != 0 ) ;
}
static void F_9 ( volatile char * V_24 )
{
F_3 ( ( V_2 * ) ( V_3 + V_6 ) , V_7 | V_9 ) ;
F_3 ( ( V_2 * ) ( V_24 + V_25 ) , V_26 | V_27 ) ;
while ( ( F_2 ( ( V_2 * ) ( V_24 + V_25 ) )
& ( V_26 | V_27 ) ) != 0 )
F_10 ( 100 ) ;
}
static volatile char * F_11 ( void * V_28 , char * V_29 )
{
void * V_30 ;
int V_31 ;
V_31 = F_12 ( V_28 , V_29 , & V_30 , sizeof( V_30 ) ) ;
if ( V_31 != sizeof( V_30 ) )
goto V_32;
V_28 = F_13 ( ( V_2 ) V_30 ) ;
if ( V_28 == NULL )
goto V_32;
V_31 = F_12 ( V_28 , L_1 , & V_30 , sizeof( V_30 ) ) ;
if ( V_31 == sizeof( V_30 ) )
return V_30 ;
V_32:
return NULL ;
}
int F_14 ( void * V_28 , struct V_33 * V_34 )
{
void * V_30 ;
int V_31 , V_35 ;
volatile char * V_24 ;
V_31 = F_12 ( V_28 , L_1 , & V_30 , sizeof( V_30 ) ) ;
if ( V_31 != sizeof( V_30 ) )
goto V_32;
V_3 = V_30 ;
V_24 = F_11 ( V_28 , L_2 ) ;
if ( V_24 == NULL )
goto V_32;
V_20 = F_11 ( V_28 , L_3 ) ;
if ( V_20 == NULL )
goto V_32;
V_31 = F_12 ( V_28 , L_4 , & V_30 , sizeof( V_30 ) ) ;
if ( V_31 != sizeof( V_30 ) )
goto V_32;
V_35 = ( int ) V_30 ;
V_20 += ( V_35 == 0 ) ? 0x4 : 0xc ;
F_3 ( ( V_2 * ) ( V_20 + V_21 ) , 0 ) ;
F_3 ( ( V_2 * ) ( V_20 + V_21 ) , 0 ) ;
F_3 ( ( V_2 * ) ( V_20 + V_36 ) , 0 ) ;
F_3 ( ( V_2 * ) ( V_20 + V_36 ) , 0 ) ;
F_9 ( V_24 ) ;
V_34 -> V_37 = F_1 ;
V_34 -> putc = F_4 ;
V_34 -> getc = F_5 ;
V_34 -> V_38 = F_8 ;
V_34 -> V_39 = NULL ;
return 0 ;
V_32:
return - 1 ;
}
