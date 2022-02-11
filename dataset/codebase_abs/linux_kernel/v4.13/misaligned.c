static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
T_2 * V_4 = ( ( T_2 * ) V_2 ) + V_5 [ V_3 ] ;
return * ( T_1 * ) V_4 ;
}
static inline void F_2 ( struct V_1 * V_2 , int V_3 , T_1 V_6 )
{
T_2 * V_4 = ( ( T_2 * ) V_2 ) + V_5 [ V_3 ] ;
* ( T_1 * ) V_4 = V_6 ;
}
T_3 void F_3 ( struct V_1 * V_2 , int V_7 )
{
T_1 V_8 , V_9 , V_6 ;
int V_10 ;
T_2 V_11 , V_12 , V_13 , V_14 , V_15 , V_16 ;
T_4 V_17 ;
unsigned int V_18 ;
V_2 -> V_19 -= 4 ;
if ( F_4 ( V_2 ) ) {
return;
}
V_10 = ! F_5 ( V_2 ) ;
V_8 = * ( unsigned long * ) ( V_2 -> V_19 ) ;
V_18 = 0 ;
if ( V_10 || ( V_20 & V_21 ) ) {
V_11 = ( V_8 >> 27 ) & 0x1f ;
V_12 = ( V_8 >> 22 ) & 0x1f ;
V_17 = ( V_8 >> 6 ) & 0xffff ;
V_9 = F_1 ( V_2 , V_11 ) + V_17 ;
switch ( V_8 & 0x3f ) {
case V_22 :
V_18 |= F_6 ( V_13 , ( T_2 * ) ( V_9 + 0 ) ) ;
V_18 |= F_6 ( V_14 , ( T_2 * ) ( V_9 + 1 ) ) ;
V_6 = ( V_14 << 8 ) | V_13 ;
F_2 ( V_2 , V_12 , V_6 ) ;
break;
case V_23 :
V_6 = F_1 ( V_2 , V_12 ) ;
V_14 = V_6 >> 8 ;
V_13 = V_6 >> 0 ;
if ( V_10 ) {
* ( T_2 * ) ( V_9 + 0 ) = V_13 ;
* ( T_2 * ) ( V_9 + 1 ) = V_14 ;
} else {
V_18 |= F_7 ( V_13 , ( T_2 * ) ( V_9 + 0 ) ) ;
V_18 |= F_7 ( V_14 , ( T_2 * ) ( V_9 + 1 ) ) ;
}
break;
case V_24 :
V_18 |= F_6 ( V_13 , ( T_2 * ) ( V_9 + 0 ) ) ;
V_18 |= F_6 ( V_14 , ( T_2 * ) ( V_9 + 1 ) ) ;
V_6 = ( short ) ( ( V_14 << 8 ) | V_13 ) ;
F_2 ( V_2 , V_12 , V_6 ) ;
break;
case V_25 :
V_6 = F_1 ( V_2 , V_12 ) ;
V_16 = V_6 >> 24 ;
V_15 = V_6 >> 16 ;
V_14 = V_6 >> 8 ;
V_13 = V_6 >> 0 ;
if ( V_10 ) {
* ( T_2 * ) ( V_9 + 0 ) = V_13 ;
* ( T_2 * ) ( V_9 + 1 ) = V_14 ;
* ( T_2 * ) ( V_9 + 2 ) = V_15 ;
* ( T_2 * ) ( V_9 + 3 ) = V_16 ;
} else {
V_18 |= F_7 ( V_13 , ( T_2 * ) ( V_9 + 0 ) ) ;
V_18 |= F_7 ( V_14 , ( T_2 * ) ( V_9 + 1 ) ) ;
V_18 |= F_7 ( V_15 , ( T_2 * ) ( V_9 + 2 ) ) ;
V_18 |= F_7 ( V_16 , ( T_2 * ) ( V_9 + 3 ) ) ;
}
break;
case V_26 :
V_18 |= F_6 ( V_13 , ( T_2 * ) ( V_9 + 0 ) ) ;
V_18 |= F_6 ( V_14 , ( T_2 * ) ( V_9 + 1 ) ) ;
V_18 |= F_6 ( V_15 , ( T_2 * ) ( V_9 + 2 ) ) ;
V_18 |= F_6 ( V_16 , ( T_2 * ) ( V_9 + 3 ) ) ;
V_6 = ( V_16 << 24 ) | ( V_15 << 16 ) | ( V_14 << 8 ) | V_13 ;
F_2 ( V_2 , V_12 , V_6 ) ;
break;
}
}
V_9 = F_8 ( V_27 ) ;
V_7 >>= 2 ;
if ( V_18 ) {
if ( V_10 ) {
F_9 ( L_1 ,
V_2 -> V_19 , ( unsigned int ) V_9 ,
( unsigned int ) V_8 ) ;
} else {
F_9 ( L_2 ,
V_2 -> V_19 ,
( unsigned int ) V_8 , V_9 , V_2 -> V_28 ,
V_29 -> V_30 ) ;
F_10 ( V_31 , V_2 , V_32 , V_2 -> V_19 ) ;
return;
}
}
if ( V_10 ) {
V_2 -> V_19 += 4 ;
if ( V_20 & V_33 ) {
F_9 ( L_3 ,
V_2 -> V_19 ,
( unsigned int ) V_9 , V_7 ,
( unsigned int ) V_8 ) ;
}
return;
}
if ( V_20 & V_34 ) {
F_9 ( L_4 ,
( unsigned long ) V_9 , ( unsigned long ) V_8 ,
V_2 -> V_19 , V_2 -> V_35 , V_2 -> V_28 ) ;
}
if ( V_20 & V_36 )
F_10 ( V_37 , V_2 , V_38 , V_2 -> V_19 ) ;
else
V_2 -> V_19 += 4 ;
}
static void T_5 F_11 ( void )
{
int V_39 , V_40 , V_41 ;
V_41 = 0 ;
for ( V_39 = 0 ; V_39 < 16 ; V_39 ++ ) {
V_40 = V_42 [ V_39 ] ;
V_5 [ V_40 ] = V_41 ;
V_41 += 4 ;
}
V_41 = - sizeof( struct V_43 ) ;
for ( V_39 = 16 ; V_39 < 32 ; V_39 ++ ) {
V_40 = V_42 [ V_39 ] ;
V_5 [ V_40 ] = V_41 ;
V_41 += 4 ;
}
}
static int T_5 F_12 ( void )
{
V_20 = V_21 | V_33 ;
F_11 () ;
return 0 ;
}
