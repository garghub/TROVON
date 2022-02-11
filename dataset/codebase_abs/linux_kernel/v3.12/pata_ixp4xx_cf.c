static int F_1 ( struct V_1 * V_2 , struct V_3 * * error )
{
struct V_3 * V_4 ;
F_2 (dev, link, ENABLED) {
F_3 ( V_4 , L_1 ) ;
V_4 -> V_5 = V_6 ;
V_4 -> V_7 = V_6 ;
V_4 -> V_8 = V_9 ;
V_4 -> V_10 |= V_11 ;
}
return 0 ;
}
static unsigned int F_4 ( struct V_3 * V_4 ,
unsigned char * V_12 , unsigned int V_13 , int V_14 )
{
unsigned int V_15 ;
unsigned int V_16 = V_13 >> 1 ;
T_1 * V_17 = ( T_1 * ) V_12 ;
struct V_18 * V_19 = V_4 -> V_2 -> V_19 ;
void T_2 * V_20 = V_19 -> V_21 . V_22 ;
struct V_23 * V_24 = F_5 ( V_19 -> V_25 -> V_4 ) ;
* V_24 -> V_26 &= ~ ( 0x01 ) ;
F_6 ( 100 ) ;
if ( V_14 == V_27 )
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
V_17 [ V_15 ] = F_7 ( V_20 ) ;
else
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
F_8 ( V_17 [ V_15 ] , V_20 ) ;
if ( F_9 ( V_13 & 0x01 ) ) {
T_1 V_28 [ 1 ] = { 0 } ;
unsigned char * V_29 = V_12 + V_13 - 1 ;
if ( V_14 == V_27 ) {
V_28 [ 0 ] = F_7 ( V_20 ) ;
memcpy ( V_29 , V_28 , 1 ) ;
} else {
memcpy ( V_28 , V_29 , 1 ) ;
F_8 ( V_28 [ 0 ] , V_20 ) ;
}
V_16 ++ ;
}
F_6 ( 100 ) ;
* V_24 -> V_26 |= 0x01 ;
return V_16 << 1 ;
}
static void F_10 ( struct V_18 * V_19 ,
struct V_23 * V_24 ,
unsigned long V_30 , unsigned long V_31 )
{
struct V_32 * V_21 = & V_19 -> V_21 ;
unsigned long V_33 = V_30 ;
unsigned long V_34 = V_31 + 0x06 ;
V_21 -> V_35 = V_24 -> V_36 ;
V_21 -> V_37 = V_24 -> V_38 + 0x06 ;
V_21 -> V_39 = V_24 -> V_38 + 0x06 ;
F_11 ( V_21 ) ;
#ifndef F_12
* ( unsigned long * ) & V_21 -> V_22 ^= 0x02 ;
* ( unsigned long * ) & V_21 -> V_35 ^= 0x03 ;
* ( unsigned long * ) & V_21 -> V_37 ^= 0x03 ;
* ( unsigned long * ) & V_21 -> V_39 ^= 0x03 ;
* ( unsigned long * ) & V_21 -> V_40 ^= 0x03 ;
* ( unsigned long * ) & V_21 -> V_41 ^= 0x03 ;
* ( unsigned long * ) & V_21 -> V_42 ^= 0x03 ;
* ( unsigned long * ) & V_21 -> V_43 ^= 0x03 ;
* ( unsigned long * ) & V_21 -> V_44 ^= 0x03 ;
* ( unsigned long * ) & V_21 -> V_45 ^= 0x03 ;
* ( unsigned long * ) & V_21 -> V_46 ^= 0x03 ;
* ( unsigned long * ) & V_21 -> V_47 ^= 0x03 ;
* ( unsigned long * ) & V_21 -> V_48 ^= 0x03 ;
V_33 ^= 0x03 ;
V_34 ^= 0x03 ;
#endif
F_13 ( V_19 , L_2 , V_33 , V_34 ) ;
}
static int F_14 ( struct V_49 * V_50 )
{
unsigned int V_51 ;
struct V_52 * V_36 , * V_38 ;
struct V_53 * V_25 ;
struct V_18 * V_19 ;
struct V_23 * V_24 = F_5 ( & V_50 -> V_4 ) ;
V_36 = F_15 ( V_50 , V_54 , 0 ) ;
V_38 = F_15 ( V_50 , V_54 , 1 ) ;
if ( ! V_36 || ! V_38 )
return - V_55 ;
V_25 = F_16 ( & V_50 -> V_4 , 1 ) ;
if ( ! V_25 )
return - V_56 ;
V_50 -> V_4 . V_57 = F_17 ( 32 ) ;
V_24 -> V_36 = F_18 ( & V_50 -> V_4 , V_36 -> V_58 , 0x1000 ) ;
V_24 -> V_38 = F_18 ( & V_50 -> V_4 , V_38 -> V_58 , 0x1000 ) ;
if ( ! V_24 -> V_36 || ! V_24 -> V_38 )
return - V_56 ;
V_51 = F_19 ( V_50 , 0 ) ;
if ( V_51 )
F_20 ( V_51 , V_59 ) ;
* V_24 -> V_26 = V_24 -> V_60 ;
* V_24 -> V_61 = V_24 -> V_62 ;
V_19 = V_25 -> V_63 [ 0 ] ;
V_19 -> V_64 = & V_65 ;
V_19 -> V_66 = V_67 ;
V_19 -> V_10 |= V_68 ;
F_10 ( V_19 , V_24 , V_36 -> V_58 , V_38 -> V_58 ) ;
F_21 ( & V_50 -> V_4 , V_69 ) ;
return F_22 ( V_25 , V_51 , V_70 , 0 , & V_71 ) ;
}
