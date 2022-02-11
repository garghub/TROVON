static int F_1 ( T_1 * V_1 )
{
struct V_2 * V_3 ;
int V_4 , V_5 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
#ifdef F_2
V_8 = ( 0x03 << 5 ) ;
V_4 =
( F_3 ( V_1 -> V_9 , V_10 ) & ~ V_11 ) |
V_12 | V_8 ;
F_4 ( V_1 -> V_9 , V_10 , V_4 ) ;
#else
V_4 =
( F_3 ( V_1 -> V_9 , V_10 ) & ~ V_11 ) &
~ V_12 ;
F_4 ( V_1 -> V_9 , V_10 , V_4 ) ;
#endif
V_5 = 1 ;
V_4 = F_3 ( V_1 -> V_9 , V_13 ) & 0xffff00cf ;
V_4 |= ( V_14 << 8 ) | ( ( V_5 >> 24 ) & 0xff ) << 4 ;
F_4 ( V_1 -> V_9 , V_13 , V_4 ) ;
F_4 ( V_1 -> V_9 , V_15 , V_16 ) ;
V_4 = F_3 ( V_1 -> V_9 , V_17 ) ;
if ( V_4 != V_18 ) {
F_5 ( L_1 ) ;
return - V_19 ;
}
F_4 ( V_1 -> V_9 , V_20 ,
F_3 ( V_1 -> V_9 , V_20 ) | V_21 ) ;
#ifdef F_2
if ( ( V_4 =
F_6 ( V_1 -> V_22 , 0 , V_23 , 0x330 ,
V_24 , - 1 , & V_3 ) ) != 0 ) {
F_4 ( V_1 -> V_9 , V_10 ,
( F_3 ( V_1 -> V_9 , V_10 ) &
~ V_11 ) & ~ V_12 ) ;
return V_4 ;
}
#else
V_8 = ( unsigned long ) ( V_1 -> V_9 + V_17 ) ;
if ( ( V_4 =
F_6 ( V_1 -> V_22 , 0 , V_25 , V_8 ,
V_26 | V_27 |
V_24 , - 1 , & V_3 ) ) != 0 ) {
F_4 ( V_1 -> V_9 , V_10 ,
( F_3 ( V_1 -> V_9 , V_10 ) &
~ V_11 ) & ~ V_12 ) ;
return V_4 ;
}
V_7 = V_3 -> V_28 ;
V_7 -> V_29 = ( unsigned long ) ( V_1 -> V_9 + V_15 ) ;
#endif
snprintf ( V_3 -> V_30 , sizeof( V_3 -> V_30 ) , L_2 , V_31 , V_1 -> V_22 -> V_32 ) ;
V_1 -> V_3 = V_3 ;
return 0 ;
}
