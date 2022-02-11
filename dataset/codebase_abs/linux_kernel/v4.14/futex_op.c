static T_1 F_1 ( char * V_1 , T_1 V_2 , struct V_3 * V_4 )
{
enum T_2 {
V_5 = ( 1 << 0 ) ,
V_6 = ( 1 << 1 ) ,
V_7 = ( 1 << 2 ) ,
V_8 = ( 1 << 3 ) ,
V_9 = ( 1 << 4 ) ,
V_10 = ( 1 << 5 ) ,
};
int V_11 = V_4 -> V_12 ;
int V_13 = V_11 & V_14 ;
T_1 V_15 = 0 ;
switch ( V_13 ) {
#define F_2 ( T_3 ) case FUTEX_##n: printed = scnprintf(bf, size, #n);
F_2 ( V_16 ) ; V_4 -> V_17 |= V_10 | V_9 ; break;
F_2 ( V_18 ) ; V_4 -> V_17 |= V_10 | V_9 | V_8 ; break;
F_2 ( V_19 ) ; V_4 -> V_17 |= V_10 | V_9 | V_8 ; break;
F_2 ( V_20 ) ; V_4 -> V_17 |= V_10 | V_8 ; break;
F_2 ( V_21 ) ; V_4 -> V_17 |= V_8 ; break;
F_2 ( V_22 ) ; V_4 -> V_17 |= V_8 ; break;
F_2 ( V_23 ) ; break;
F_2 ( V_24 ) ; V_4 -> V_17 |= V_10 | V_9 | V_8 ; break;
F_2 ( V_25 ) ; V_4 -> V_17 |= V_10 | V_9 | V_8 ; break;
F_2 ( V_26 ) ; V_4 -> V_17 |= V_10 | V_9 ; break;
F_2 ( V_27 ) ; V_4 -> V_17 |= V_9 ; break;
F_2 ( V_28 ) ; V_4 -> V_17 |= V_9 ; break;
F_2 ( V_29 ) ; break;
default: V_15 = F_3 ( V_1 , V_2 , L_1 , V_13 ) ; break;
}
if ( V_11 & V_30 )
V_15 += F_3 ( V_1 + V_15 , V_2 - V_15 , L_2 ) ;
if ( V_11 & V_31 )
V_15 += F_3 ( V_1 + V_15 , V_2 - V_15 , L_3 ) ;
return V_15 ;
}
