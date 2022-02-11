unsigned char * F_1 ( struct V_1 * V_2 )
{
unsigned char * V_3 = F_2 ( 66 , V_4 ) ;
if ( V_3 ) {
struct V_1 * V_5 = V_2 -> V_6 ;
T_1 V_7 ;
void * V_8 = F_3 ( V_5 , 0 , & V_7 ) ;
if ( V_8 ) {
memcpy ( V_3 , V_8 + 0x1be , 66 ) ;
F_4 ( V_7 ) ;
} else {
F_5 ( V_3 ) ;
V_3 = NULL ;
}
}
return V_3 ;
}
int F_6 ( struct V_1 * V_5 , T_2 V_9 , int * V_10 )
{
unsigned char * V_11 ;
T_3 V_12 = V_9 ;
int V_13 ;
V_11 = F_1 ( V_5 ) ;
if ( ! V_11 )
return - 1 ;
V_13 = F_7 ( V_11 , ( unsigned long ) V_9 , ( unsigned int * ) V_10 + 2 ,
( unsigned int * ) V_10 + 0 , ( unsigned int * ) V_10 + 1 ) ;
F_5 ( V_11 ) ;
if ( V_13 == - 1 && V_12 < ( 1ULL << 32 ) ) {
V_13 = F_8 ( ( unsigned long ) V_9 , ( unsigned int * ) V_10 + 2 ,
( unsigned int * ) V_10 + 0 , ( unsigned int * ) V_10 + 1 ) ;
}
if ( V_13 || V_10 [ 0 ] > 255 || V_10 [ 1 ] > 63 ) {
if ( ( V_9 >> 11 ) > 65534 ) {
V_10 [ 0 ] = 255 ;
V_10 [ 1 ] = 63 ;
} else {
V_10 [ 0 ] = 64 ;
V_10 [ 1 ] = 32 ;
}
if ( V_9 > 65535 * 63 * 255 )
V_10 [ 2 ] = 65535 ;
else
V_10 [ 2 ] = ( unsigned long ) V_9 / ( V_10 [ 0 ] * V_10 [ 1 ] ) ;
}
return 0 ;
}
int F_7 ( unsigned char * V_14 , unsigned long V_9 ,
unsigned int * V_15 , unsigned int * V_16 , unsigned int * V_17 )
{
struct V_18 * V_11 = (struct V_18 * ) V_14 , * V_19 = NULL ;
int V_20 , V_21 ;
int V_22 , V_23 , V_24 , V_25 , V_26 ;
unsigned int V_27 , V_28 , V_29 ;
if ( * ( unsigned short * ) ( V_14 + 64 ) == 0xAA55 ) {
for ( V_21 = - 1 , V_20 = 0 ; V_20 < 4 ; ++ V_20 , ++ V_11 ) {
if ( ! V_11 -> V_30 )
continue;
#ifdef F_9
F_10 ( L_1 ,
V_20 ) ;
#endif
V_22 = V_11 -> V_22 + ( ( V_11 -> V_31 & 0xc0 ) << 2 ) ;
if ( V_22 > V_21 ) {
V_21 = V_22 ;
V_19 = V_11 ;
}
}
}
if ( V_19 ) {
V_25 = V_19 -> V_25 + ( ( V_19 -> V_26 & 0xc0 ) << 2 ) ;
V_24 = V_19 -> V_24 ;
V_26 = V_19 -> V_26 & 0x3f ;
if ( V_24 + 1 == 0 || V_26 == 0 )
return - 1 ;
#ifdef F_9
F_10 ( L_2 ,
V_24 , V_25 , V_26 ) ;
#endif
V_28 = V_25 * ( V_24 + 1 ) * V_26 +
V_24 * V_26 + V_26 ;
V_27 = F_11 ( & V_19 -> V_32 )
+ F_11 ( & V_19 -> V_33 ) ;
V_23 = ( V_27 - ( V_24 * V_26 + V_26 ) )
/ ( V_24 + 1 ) / V_26 ;
V_29 = V_23 * ( V_24 + 1 ) * V_26 +
V_24 * V_26 + V_26 ;
#ifdef F_9
F_10 ( L_3
, V_27 , V_28 , V_29 , V_23 ) ;
#endif
if ( ( V_27 == V_28 ) ||
( V_25 == 1023 && V_29 == V_27 ) ) {
* V_17 = V_26 ;
* V_16 = V_24 + 1 ;
* V_15 = V_9 / ( ( V_24 + 1 ) * V_26 ) ;
return 0 ;
}
#ifdef F_9
F_10 ( L_4 ,
V_27 , V_28 ) ;
#endif
}
return - 1 ;
}
static int F_8 ( unsigned long V_9 , unsigned int * V_15 , unsigned int * V_16 ,
unsigned int * V_17 )
{
unsigned int V_34 = 0 ;
unsigned long V_35 , V_36 , V_37 , V_38 ;
V_37 = 1024L ;
V_36 = 62L ;
V_38 = V_37 * V_36 ;
V_35 = V_9 / V_38 ;
if ( V_9 % V_38 ) {
V_35 ++ ;
V_38 = V_37 * V_35 ;
V_36 = V_9 / V_38 ;
if ( V_9 % V_38 ) {
V_36 ++ ;
V_38 = V_35 * V_36 ;
V_37 = V_9 / V_38 ;
}
}
if ( V_37 == 0 )
V_34 = ( unsigned ) - 1 ;
* V_15 = ( unsigned int ) V_37 ;
* V_17 = ( unsigned int ) V_36 ;
* V_16 = ( unsigned int ) V_35 ;
return ( V_34 ) ;
}
