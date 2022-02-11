static int F_1 ( struct V_1 * V_2 , struct V_3 * * error )
{
struct V_3 * V_4 ;
F_2 (dev, link, ENABLED) {
F_3 ( V_4 , V_5 , L_1 ) ;
V_4 -> V_6 = V_7 ;
V_4 -> V_8 = V_7 ;
V_4 -> V_9 = V_10 ;
V_4 -> V_11 |= V_12 ;
}
return 0 ;
}
static unsigned int F_4 ( struct V_3 * V_4 ,
unsigned char * V_13 , unsigned int V_14 , int V_15 )
{
unsigned int V_16 ;
unsigned int V_17 = V_14 >> 1 ;
T_1 * V_18 = ( T_1 * ) V_13 ;
struct V_19 * V_20 = V_4 -> V_2 -> V_20 ;
void T_2 * V_21 = V_20 -> V_22 . V_23 ;
struct V_24 * V_25 = V_20 -> V_26 -> V_4 -> V_27 ;
* V_25 -> V_28 &= ~ ( 0x01 ) ;
F_5 ( 100 ) ;
if ( V_15 == V_29 )
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
V_18 [ V_16 ] = F_6 ( V_21 ) ;
else
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
F_7 ( V_18 [ V_16 ] , V_21 ) ;
if ( F_8 ( V_14 & 0x01 ) ) {
T_1 V_30 [ 1 ] = { 0 } ;
unsigned char * V_31 = V_13 + V_14 - 1 ;
if ( V_15 == V_29 ) {
V_30 [ 0 ] = F_6 ( V_21 ) ;
memcpy ( V_31 , V_30 , 1 ) ;
} else {
memcpy ( V_30 , V_31 , 1 ) ;
F_7 ( V_30 [ 0 ] , V_21 ) ;
}
V_17 ++ ;
}
F_5 ( 100 ) ;
* V_25 -> V_28 |= 0x01 ;
return V_17 << 1 ;
}
static void F_9 ( struct V_19 * V_20 ,
struct V_24 * V_25 ,
unsigned long V_32 , unsigned long V_33 )
{
struct V_34 * V_22 = & V_20 -> V_22 ;
unsigned long V_35 = V_32 ;
unsigned long V_36 = V_33 + 0x06 ;
V_22 -> V_37 = V_25 -> V_38 ;
V_22 -> V_39 = V_25 -> V_40 + 0x06 ;
V_22 -> V_41 = V_25 -> V_40 + 0x06 ;
F_10 ( V_22 ) ;
#ifndef F_11
* ( unsigned long * ) & V_22 -> V_23 ^= 0x02 ;
* ( unsigned long * ) & V_22 -> V_37 ^= 0x03 ;
* ( unsigned long * ) & V_22 -> V_39 ^= 0x03 ;
* ( unsigned long * ) & V_22 -> V_41 ^= 0x03 ;
* ( unsigned long * ) & V_22 -> V_42 ^= 0x03 ;
* ( unsigned long * ) & V_22 -> V_43 ^= 0x03 ;
* ( unsigned long * ) & V_22 -> V_44 ^= 0x03 ;
* ( unsigned long * ) & V_22 -> V_45 ^= 0x03 ;
* ( unsigned long * ) & V_22 -> V_46 ^= 0x03 ;
* ( unsigned long * ) & V_22 -> V_47 ^= 0x03 ;
* ( unsigned long * ) & V_22 -> V_48 ^= 0x03 ;
* ( unsigned long * ) & V_22 -> V_49 ^= 0x03 ;
* ( unsigned long * ) & V_22 -> V_50 ^= 0x03 ;
V_35 ^= 0x03 ;
V_36 ^= 0x03 ;
#endif
F_12 ( V_20 , L_2 , V_35 , V_36 ) ;
}
static T_3 int F_13 ( struct V_51 * V_52 )
{
unsigned int V_53 ;
struct V_54 * V_38 , * V_40 ;
struct V_55 * V_26 ;
struct V_19 * V_20 ;
struct V_24 * V_25 = V_52 -> V_4 . V_27 ;
V_38 = F_14 ( V_52 , V_56 , 0 ) ;
V_40 = F_14 ( V_52 , V_56 , 1 ) ;
if ( ! V_38 || ! V_40 )
return - V_57 ;
V_26 = F_15 ( & V_52 -> V_4 , 1 ) ;
if ( ! V_26 )
return - V_58 ;
V_52 -> V_4 . V_59 = F_16 ( 32 ) ;
V_25 -> V_38 = F_17 ( & V_52 -> V_4 , V_38 -> V_60 , 0x1000 ) ;
V_25 -> V_40 = F_17 ( & V_52 -> V_4 , V_40 -> V_60 , 0x1000 ) ;
if ( ! V_25 -> V_38 || ! V_25 -> V_40 )
return - V_58 ;
V_53 = F_18 ( V_52 , 0 ) ;
if ( V_53 )
F_19 ( V_53 , V_61 ) ;
* V_25 -> V_28 = V_25 -> V_62 ;
* V_25 -> V_63 = V_25 -> V_64 ;
V_20 = V_26 -> V_65 [ 0 ] ;
V_20 -> V_66 = & V_67 ;
V_20 -> V_68 = V_69 ;
V_20 -> V_11 |= V_70 ;
F_9 ( V_20 , V_25 , V_38 -> V_60 , V_40 -> V_60 ) ;
F_20 ( V_5 , & V_52 -> V_4 , L_3 V_71 L_4 ) ;
return F_21 ( V_26 , V_53 , V_72 , 0 , & V_73 ) ;
}
static T_4 int F_22 ( struct V_51 * V_4 )
{
struct V_55 * V_26 = F_23 ( V_4 ) ;
F_24 ( V_26 ) ;
return 0 ;
}
static int T_5 F_25 ( void )
{
return F_26 ( & V_74 ) ;
}
static void T_6 F_27 ( void )
{
F_28 ( & V_74 ) ;
}
