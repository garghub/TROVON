static inline T_1 F_1 ( T_1 V_1 )
{
F_2 ( V_2 + V_3 , V_1 ) ;
F_2 ( V_2 + V_4 , V_5 ) ;
while ( ! ( F_3 ( V_2 + V_6 ) & V_7 ) )
;
return F_3 ( V_2 + V_8 ) ;
}
static T_2 F_4 ( int V_9 , void * V_10 )
{
T_1 V_11 = F_3 ( V_2 + V_6 ) ;
if ( V_11 & V_12 ) {
T_1 V_1 = F_1 ( 0x42000000 ) ;
F_5 ( V_13 L_1 ,
V_1 ) ;
}
if ( V_11 & V_14 ) {
T_1 V_1 = F_1 ( 0x82000000 ) >> 16 ;
F_5 ( V_13 L_2 ,
V_1 ) ;
}
if ( V_11 & ( V_12 | V_14 ) ) {
F_2 ( V_2 + V_3 , 0 ) ;
F_2 ( V_2 + V_4 , V_15 | V_16 ) ;
} else {
F_5 ( V_13 L_3 ) ;
}
return V_17 ;
}
static int T_3 F_6 ( void )
{
struct V_18 * V_19 ;
T_1 V_20 ;
unsigned long V_21 ;
int V_9 ;
const T_1 * V_22 ;
T_1 V_23 ;
int V_24 ;
const T_1 * V_25 ;
T_1 V_26 ;
V_19 = F_7 ( NULL , NULL , L_4 ) ;
if ( ! V_19 )
return 0 ;
V_25 = F_8 ( V_19 , L_5 , NULL ) ;
if ( V_25 == NULL ) {
F_5 ( V_27 L_6 , V_19 -> V_28 ) ;
F_9 ( V_19 ) ;
return - V_29 ;
}
V_26 = V_25 [ 0 ] ;
V_22 = F_8 ( V_19 , L_7 , & V_24 ) ;
if ( ! V_22 || ( V_24 != 4 * sizeof( T_1 ) ) ) {
F_5 ( V_27 L_8 ,
V_19 -> V_28 ) ;
F_9 ( V_19 ) ;
return - V_29 ;
}
V_23 = V_22 [ 0 ] ;
V_2 = V_22 [ 2 ] ;
V_9 = F_10 ( V_19 , 0 ) ;
if ( V_9 == V_30 ) {
F_5 ( V_27 L_9 ) ;
F_9 ( V_19 ) ;
return - V_29 ;
}
if ( F_11 ( V_9 , F_4 , 0 , L_10 , 0 ) < 0 ) {
F_5 ( V_27 L_11
L_12 ) ;
F_9 ( V_19 ) ;
return - V_29 ;
}
F_12 ( V_21 ) ;
asm volatile ("sync" ::: "memory");
F_2 ( V_23 + V_31 ,
F_3 ( V_23 + V_31 ) & ~ V_32 ) ;
F_2 ( V_23 + V_33 ,
F_3 ( V_23 + V_33 ) & ~ V_34 ) ;
F_2 ( V_23 + V_35 ,
F_3 ( V_23 + V_35 ) & ~ V_34 ) ;
F_2 ( V_23 + V_36 ,
F_3 ( V_23 + V_36 ) & ~ V_34 ) ;
F_2 ( V_23 + V_37 ,
F_3 ( V_23 + V_37 ) & ~ V_34 ) ;
V_20 = F_3 ( V_2 + V_38 ) &
~ ( V_39 | V_40 | V_41 ) ;
V_20 |= V_42 | V_43 ;
F_2 ( V_2 + V_38 , V_20 ) ;
F_2 ( V_2 + V_3 , 0 ) ;
F_2 ( V_2 + V_4 , V_44 ) ;
while ( ! ( F_3 ( V_2 + V_6 ) & V_7 ) )
;
F_2 ( V_2 + V_4 , V_15 | V_16 ) ;
V_20 = F_3 ( V_2 + V_45 ) &
~ ( V_46 | V_47 ) ;
V_20 |= V_48 | V_49 ;
F_2 ( V_2 + V_45 , V_20 ) ;
V_20 = F_3 ( V_2 + V_50 ) &
~ ( V_46 | V_47 ) ;
V_20 |= 0x80000000 | V_48 | V_49 ;
F_2 ( V_2 + V_50 , V_20 ) ;
asm volatile ("sync" ::: "memory");
V_20 = F_3 ( V_2 + V_38 ) ;
V_20 &= ~ ( V_51 | V_52 | V_53
| V_54 | V_55 | V_56 | V_57 ) ;
V_20 |= V_39 | V_40 | V_58 | V_59 | V_60
| V_61 | V_62 | V_63 | V_64 ;
if ( F_13 ( V_19 , L_13 ) ||
F_13 ( V_19 , L_14 ) )
V_20 |= V_65 ;
F_2 ( V_2 + V_38 , V_20 ) ;
asm volatile ("sync; isync" ::: "memory");
F_14 ( V_21 ) ;
F_5 ( V_66 L_15 , V_26 >> 10 ) ;
F_9 ( V_19 ) ;
return 0 ;
}
void F_15 ( char * V_67 )
{
struct V_18 * V_19 ;
T_1 V_68 = V_69 ;
const T_1 * V_25 ;
V_19 = F_16 ( NULL , L_16 ) ;
if ( V_19 ) {
V_25 = F_8 ( V_19 , L_17 , NULL ) ;
if ( ( V_25 ) && ( ( V_25 [ 0 ] >= 1 ) && ( V_25 [ 0 ] <= 3 ) ) )
V_68 = V_25 [ 0 ] << 28 ;
}
F_17 ( V_70 , F_18 ( V_70 ) | V_68 ) ;
while ( 1 )
;
}
