static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_1 V_4 [] = { V_5 , V_6 , V_7 ,
V_8 , V_9 , V_10 } ;
unsigned char V_11 [ 6 ] ;
T_2 V_12 = ( T_2 ) V_3 * V_13 * 2 ;
int V_14 = 0 ;
int V_15 ;
V_11 [ 0 ] = ( V_12 ) & 0xFF ;
V_11 [ 1 ] = ( V_12 >> 8 ) & 0xFF ;
V_11 [ 2 ] = ( V_12 >> 16 ) & 0xFF ;
V_11 [ 3 ] = ( V_12 >> 24 ) & 0xFF ;
V_11 [ 4 ] = ( V_12 >> 32 ) & 0xFF ;
V_11 [ 5 ] = ( V_12 >> 40 ) & 0xFF ;
for ( V_15 = 0 ; V_15 < 6 ; V_15 ++ ) {
V_14 = F_2 ( V_2 , 0 ,
V_4 [ V_15 ] , V_11 [ V_15 ] ) ;
if ( V_14 )
return V_14 ;
}
return F_3 ( V_2 , 0 ,
V_16 ,
0x01 , 0x01 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
unsigned long time ;
T_1 V_19 ;
int V_14 ;
V_14 = F_5 ( V_2 , 0 ,
V_16 , & V_19 ) ;
if ( V_14 )
return V_14 ;
if ( ! ( V_19 & 0x01 ) ) {
F_6 ( V_2 , L_1 ) ;
return - V_20 ;
} else {
T_2 V_12 ;
T_1 V_11 [ 6 ] ;
V_14 = F_7 ( V_2 , 0 ,
V_5 ,
V_11 , 6 ) ;
if ( V_14 != 0 )
return V_14 ;
V_12 = ( ( T_2 ) V_11 [ 5 ] << 40 ) | ( ( T_2 ) V_11 [ 4 ] << 32 ) |
( ( T_2 ) V_11 [ 3 ] << 24 ) | ( ( T_2 ) V_11 [ 2 ] << 16 ) |
( ( T_2 ) V_11 [ 1 ] << 8 ) | ( T_2 ) V_11 [ 0 ] ;
time = ( unsigned long ) ( V_12 /
( T_2 ) ( V_13 * 2 ) ) ;
}
F_8 ( time , V_18 ) ;
return F_9 ( V_18 ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
unsigned long time ;
T_2 V_12 ;
T_1 V_11 [ 6 ] ;
T_1 V_19 ;
int V_14 ;
V_14 = F_5 ( V_2 , 0 ,
V_16 , & V_19 ) ;
if ( V_14 )
return V_14 ;
if ( V_19 & 0x04 )
V_22 -> V_23 = 1 ;
else
V_22 -> V_23 = 0 ;
V_22 -> V_24 = 0 ;
V_14 = F_7 ( V_2 , 0 ,
V_25 , V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
V_12 = ( ( T_2 ) V_11 [ 3 ] << 40 ) | ( ( T_2 ) V_11 [ 2 ] << 32 ) |
( ( T_2 ) V_11 [ 1 ] << 24 ) | ( ( T_2 ) V_11 [ 0 ] << 16 ) ;
time = ( unsigned long ) ( V_12 / ( T_2 ) ( V_13 * 2 ) ) ;
F_8 ( time , & V_22 -> time ) ;
return F_9 ( & V_22 -> time ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
T_1 V_4 [] = { V_25 , V_26 , V_27 , V_28 } ;
unsigned char V_11 [ 4 ] ;
unsigned long V_3 ;
T_2 V_12 ;
int V_14 ;
int V_15 ;
F_12 ( & V_22 -> time , & V_3 ) ;
V_12 = ( T_2 ) V_3 * V_13 * 2 ;
V_11 [ 0 ] = ( V_12 >> 16 ) & 0xFF ;
V_11 [ 1 ] = ( V_12 >> 24 ) & 0xFF ;
V_11 [ 2 ] = ( V_12 >> 32 ) & 0xFF ;
V_11 [ 3 ] = ( V_12 >> 40 ) & 0xFF ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
V_14 = F_2 ( V_2 , 0 ,
V_4 [ V_15 ] , V_11 [ V_15 ] ) ;
if ( V_14 )
return V_14 ;
}
return F_3 ( V_2 , 0 ,
V_16 , ( 1 << 2 ) ,
V_22 -> V_23 << 2 ) ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_23 )
{
if ( V_23 )
return F_3 ( V_2 , 0 ,
V_16 , ( 1 << 2 ) ,
1 << 2 ) ;
else
return F_3 ( V_2 , 0 ,
V_16 , ( 1 << 2 ) ,
0 ) ;
}
static int T_3 F_14 ( struct V_29 * V_30 )
{
int V_14 ;
T_1 V_31 ;
struct V_32 * V_33 ;
V_14 = F_5 ( & V_30 -> V_2 , 0 ,
V_16 , & V_31 ) ;
if ( V_14 ) {
F_15 ( & V_30 -> V_2 , L_2 ) ;
return - V_34 ;
}
if ( ( V_31 & 0xFE ) != V_35 ) {
F_16 ( & V_30 -> V_2 , L_3 ,
V_31 ) ;
}
if ( ( V_31 & 1 ) == 0 ) {
V_31 = 1 | V_35 ;
V_14 = F_2 ( & V_30 -> V_2 , 0 ,
V_16 , V_31 ) ;
}
V_33 = F_17 ( & V_30 -> V_2 , L_4 ,
& V_36 , V_37 ) ;
if ( F_18 ( V_33 ) ) {
V_14 = F_19 ( V_33 ) ;
return V_14 ;
}
F_20 ( V_30 , V_33 ) ;
return 0 ;
}
static int T_4 F_21 ( struct V_29 * V_30 )
{
F_20 ( V_30 , NULL ) ;
return 0 ;
}
