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
static unsigned int F_4 ( struct V_12 * V_13 ,
unsigned char * V_14 , unsigned int V_15 , int V_16 )
{
unsigned int V_17 ;
unsigned int V_18 = V_15 >> 1 ;
T_1 * V_19 = ( T_1 * ) V_14 ;
struct V_20 * V_21 = V_13 -> V_4 -> V_2 -> V_21 ;
void T_2 * V_22 = V_21 -> V_23 . V_24 ;
struct V_25 * V_26 = F_5 ( V_21 -> V_27 -> V_4 ) ;
* V_26 -> V_28 &= ~ ( 0x01 ) ;
F_6 ( 100 ) ;
if ( V_16 == V_29 )
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ )
V_19 [ V_17 ] = F_7 ( V_22 ) ;
else
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ )
F_8 ( V_19 [ V_17 ] , V_22 ) ;
if ( F_9 ( V_15 & 0x01 ) ) {
T_1 V_30 [ 1 ] = { 0 } ;
unsigned char * V_31 = V_14 + V_15 - 1 ;
if ( V_16 == V_29 ) {
V_30 [ 0 ] = F_7 ( V_22 ) ;
memcpy ( V_31 , V_30 , 1 ) ;
} else {
memcpy ( V_30 , V_31 , 1 ) ;
F_8 ( V_30 [ 0 ] , V_22 ) ;
}
V_18 ++ ;
}
F_6 ( 100 ) ;
* V_26 -> V_28 |= 0x01 ;
return V_18 << 1 ;
}
static void F_10 ( struct V_20 * V_21 ,
struct V_25 * V_26 ,
unsigned long V_32 , unsigned long V_33 )
{
struct V_34 * V_23 = & V_21 -> V_23 ;
unsigned long V_35 = V_32 ;
unsigned long V_36 = V_33 + 0x06 ;
V_23 -> V_37 = V_26 -> V_38 ;
V_23 -> V_39 = V_26 -> V_40 + 0x06 ;
V_23 -> V_41 = V_26 -> V_40 + 0x06 ;
F_11 ( V_23 ) ;
#ifndef F_12
* ( unsigned long * ) & V_23 -> V_24 ^= 0x02 ;
* ( unsigned long * ) & V_23 -> V_37 ^= 0x03 ;
* ( unsigned long * ) & V_23 -> V_39 ^= 0x03 ;
* ( unsigned long * ) & V_23 -> V_41 ^= 0x03 ;
* ( unsigned long * ) & V_23 -> V_42 ^= 0x03 ;
* ( unsigned long * ) & V_23 -> V_43 ^= 0x03 ;
* ( unsigned long * ) & V_23 -> V_44 ^= 0x03 ;
* ( unsigned long * ) & V_23 -> V_45 ^= 0x03 ;
* ( unsigned long * ) & V_23 -> V_46 ^= 0x03 ;
* ( unsigned long * ) & V_23 -> V_47 ^= 0x03 ;
* ( unsigned long * ) & V_23 -> V_48 ^= 0x03 ;
* ( unsigned long * ) & V_23 -> V_49 ^= 0x03 ;
* ( unsigned long * ) & V_23 -> V_50 ^= 0x03 ;
V_35 ^= 0x03 ;
V_36 ^= 0x03 ;
#endif
F_13 ( V_21 , L_2 , V_35 , V_36 ) ;
}
static int F_14 ( struct V_51 * V_52 )
{
unsigned int V_53 ;
struct V_54 * V_38 , * V_40 ;
struct V_55 * V_27 ;
struct V_20 * V_21 ;
struct V_25 * V_26 = F_5 ( & V_52 -> V_4 ) ;
int V_56 ;
V_38 = F_15 ( V_52 , V_57 , 0 ) ;
V_40 = F_15 ( V_52 , V_57 , 1 ) ;
if ( ! V_38 || ! V_40 )
return - V_58 ;
V_27 = F_16 ( & V_52 -> V_4 , 1 ) ;
if ( ! V_27 )
return - V_59 ;
V_56 = F_17 ( & V_52 -> V_4 , F_18 ( 32 ) ) ;
if ( V_56 )
return V_56 ;
V_26 -> V_38 = F_19 ( & V_52 -> V_4 , V_38 -> V_60 , 0x1000 ) ;
V_26 -> V_40 = F_19 ( & V_52 -> V_4 , V_40 -> V_60 , 0x1000 ) ;
if ( ! V_26 -> V_38 || ! V_26 -> V_40 )
return - V_59 ;
V_53 = F_20 ( V_52 , 0 ) ;
if ( V_53 )
F_21 ( V_53 , V_61 ) ;
* V_26 -> V_28 = V_26 -> V_62 ;
* V_26 -> V_63 = V_26 -> V_64 ;
V_21 = V_27 -> V_65 [ 0 ] ;
V_21 -> V_66 = & V_67 ;
V_21 -> V_68 = V_69 ;
V_21 -> V_10 |= V_70 ;
F_10 ( V_21 , V_26 , V_38 -> V_60 , V_40 -> V_60 ) ;
F_22 ( & V_52 -> V_4 , V_71 ) ;
return F_23 ( V_27 , V_53 , V_72 , 0 , & V_73 ) ;
}
