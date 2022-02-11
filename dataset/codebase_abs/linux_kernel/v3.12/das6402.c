static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
while ( 1 ) {
if ( ! ( F_2 ( V_2 -> V_5 + 8 ) & 0x01 ) )
return;
F_3 ( V_4 -> V_6 , F_4 ( V_2 -> V_5 ) ) ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_7 ;
unsigned short V_8 ;
V_7 = V_9 | V_10 | V_11 ;
F_6 ( V_7 , V_2 -> V_5 + 15 ) ;
V_8 = 2000 ;
V_7 = ( T_1 ) ( 0xff & V_8 ) ;
F_6 ( V_7 , V_2 -> V_5 + 12 ) ;
V_7 = ( T_1 ) ( 0xff & ( V_8 >> 8 ) ) ;
F_6 ( V_7 , V_2 -> V_5 + 12 ) ;
V_7 = V_12 | V_13 | V_11 ;
F_6 ( V_7 , V_2 -> V_5 + 15 ) ;
V_8 = 10 ;
V_7 = ( T_1 ) ( 0xff & V_8 ) ;
F_6 ( V_7 , V_2 -> V_5 + 13 ) ;
V_7 = ( T_1 ) ( 0xff & ( V_8 >> 8 ) ) ;
F_6 ( V_7 , V_2 -> V_5 + 13 ) ;
V_7 = V_12 | V_14 | V_11 ;
F_6 ( V_7 , V_2 -> V_5 + 15 ) ;
V_8 = 1000 ;
V_7 = ( T_1 ) ( 0xff & V_8 ) ;
F_6 ( V_7 , V_2 -> V_5 + 14 ) ;
V_7 = ( T_1 ) ( 0xff & ( V_8 >> 8 ) ) ;
F_6 ( V_7 , V_2 -> V_5 + 14 ) ;
}
static T_2 F_7 ( int V_15 , void * V_16 )
{
struct V_1 * V_2 = V_16 ;
struct V_17 * V_18 = V_2 -> V_19 ;
struct V_3 * V_4 = & V_2 -> V_20 [ 0 ] ;
if ( ! V_2 -> V_21 || V_18 -> V_22 ) {
F_8 ( V_2 -> V_23 , L_1 ) ;
return V_24 ;
}
#ifdef F_9
F_10 ( L_2 ,
V_18 -> V_25 ) ;
F_10 ( L_3 , F_11 ( V_2 -> V_5 + 2 ) ) ;
#endif
F_1 ( V_2 , V_4 ) ;
if ( V_4 -> V_6 -> V_26 >= V_18 -> V_27 ) {
F_12 ( V_28 , V_2 -> V_5 + 2 ) ;
F_13 ( 0x07 , V_2 -> V_5 + 8 ) ;
#ifdef F_9
F_10 ( L_4 ,
V_18 -> V_29 - V_30 ) ;
#endif
V_4 -> V_6 -> V_31 |= V_32 ;
F_14 ( V_2 , V_4 ) ;
}
F_13 ( 0x01 , V_2 -> V_5 + 8 ) ;
F_14 ( V_2 , V_4 ) ;
return V_24 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
V_18 -> V_22 = 1 ;
F_16 ( V_2 -> V_23 , L_5 ) ;
V_18 -> V_22 = 1 ;
F_6 ( 0x02 , V_2 -> V_5 + 10 ) ;
F_12 ( V_28 , V_2 -> V_5 + 2 ) ;
F_6 ( 0 , V_2 -> V_5 + 9 ) ;
F_12 ( V_28 , V_2 -> V_5 + 2 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_3 * V_33 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
V_18 -> V_22 = 1 ;
F_16 ( V_2 -> V_23 , L_6 ) ;
F_6 ( 0x03 , V_2 -> V_5 + 10 ) ;
F_12 ( V_28 , V_2 -> V_5 + 2 ) ;
F_6 ( V_34 | V_35 | V_36 | V_37 , V_2 -> V_5 + 9 ) ;
V_18 -> V_27 = V_33 -> V_38 * sizeof( short ) ;
V_18 -> V_22 = 0 ;
F_12 ( V_28 , V_2 -> V_5 + 2 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
T_1 V_39 ;
V_18 -> V_22 = 1 ;
F_13 ( 0x07 , V_2 -> V_5 + 8 ) ;
F_6 ( V_40 , V_2 -> V_5 + 11 ) ;
V_39 = V_41 | V_42 | V_40 | V_43 | V_44 ;
F_6 ( V_39 , V_2 -> V_5 + 11 ) ;
F_6 ( V_45 , V_2 -> V_5 + 8 ) ;
V_39 = V_45 | V_46 ;
F_6 ( V_39 , V_2 -> V_5 + 8 ) ;
V_39 = V_46 | V_47 | V_48 | V_49 ;
F_6 ( V_39 , V_2 -> V_5 + 8 ) ;
V_39 = V_34 | V_35 | V_36 | V_37 ;
F_6 ( V_39 , V_2 -> V_5 + 9 ) ;
V_39 = V_50 | V_51 ;
F_6 ( V_39 , V_2 -> V_5 + 10 ) ;
V_39 = 0x07 ;
F_6 ( V_39 , V_2 -> V_5 + 8 ) ;
F_5 ( V_2 ) ;
F_12 ( V_28 , V_2 -> V_5 + 2 ) ;
V_18 -> V_22 = 0 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_52 * V_33 )
{
struct V_17 * V_18 ;
unsigned int V_15 ;
int V_53 ;
struct V_3 * V_4 ;
V_53 = F_20 ( V_2 , V_33 -> V_54 [ 0 ] , V_55 ) ;
if ( V_53 )
return V_53 ;
V_15 = V_33 -> V_54 [ 0 ] ;
F_16 ( V_2 -> V_23 , L_7 , V_15 ) ;
V_53 = F_21 ( V_15 , F_7 , 0 , L_8 , V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
V_2 -> V_15 = V_15 ;
V_18 = F_22 ( V_2 , sizeof( * V_18 ) ) ;
if ( ! V_18 )
return - V_56 ;
V_53 = F_23 ( V_2 , 1 ) ;
if ( V_53 )
return V_53 ;
V_4 = & V_2 -> V_20 [ 0 ] ;
V_4 -> type = V_57 ;
V_4 -> V_58 = V_59 | V_60 ;
V_4 -> V_61 = 8 ;
V_4 -> V_62 = F_15 ;
V_4 -> V_63 = ( 1 << 12 ) - 1 ;
V_4 -> V_64 = 16 ;
V_4 -> V_65 = & V_66 ;
F_18 ( V_2 ) ;
return 0 ;
}
