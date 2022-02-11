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
struct V_3 * V_4 = V_2 -> V_17 ;
if ( ! V_2 -> V_18 || V_19 -> V_20 ) {
F_8 ( V_2 -> V_21 , L_1 ) ;
return V_22 ;
}
#ifdef F_9
F_10 ( L_2 ,
V_19 -> V_23 ) ;
F_10 ( L_3 , F_11 ( V_2 -> V_5 + 2 ) ) ;
#endif
F_1 ( V_2 , V_4 ) ;
if ( V_4 -> V_6 -> V_24 >= V_19 -> V_25 ) {
F_12 ( V_26 , V_2 -> V_5 + 2 ) ;
F_13 ( 0x07 , V_2 -> V_5 + 8 ) ;
#ifdef F_9
F_10 ( L_4 ,
V_19 -> V_27 - V_28 ) ;
#endif
V_4 -> V_6 -> V_29 |= V_30 ;
F_14 ( V_2 , V_4 ) ;
}
F_13 ( 0x01 , V_2 -> V_5 + 8 ) ;
F_14 ( V_2 , V_4 ) ;
return V_22 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_19 -> V_20 = 1 ;
F_16 ( V_2 -> V_21 , L_5 ) ;
V_19 -> V_20 = 1 ;
F_6 ( 0x02 , V_2 -> V_5 + 10 ) ;
F_12 ( V_26 , V_2 -> V_5 + 2 ) ;
F_6 ( 0 , V_2 -> V_5 + 9 ) ;
F_12 ( V_26 , V_2 -> V_5 + 2 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_3 * V_31 )
{
V_19 -> V_20 = 1 ;
F_16 ( V_2 -> V_21 , L_6 ) ;
F_6 ( 0x03 , V_2 -> V_5 + 10 ) ;
F_12 ( V_26 , V_2 -> V_5 + 2 ) ;
F_6 ( V_32 | V_33 | V_34 | V_35 , V_2 -> V_5 + 9 ) ;
V_19 -> V_25 = V_31 -> V_36 * sizeof( short ) ;
V_19 -> V_20 = 0 ;
F_12 ( V_26 , V_2 -> V_5 + 2 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_1 V_37 ;
V_19 -> V_20 = 1 ;
F_13 ( 0x07 , V_2 -> V_5 + 8 ) ;
F_6 ( V_38 , V_2 -> V_5 + 11 ) ;
V_37 = V_39 | V_40 | V_38 | V_41 | V_42 ;
F_6 ( V_37 , V_2 -> V_5 + 11 ) ;
F_6 ( V_43 , V_2 -> V_5 + 8 ) ;
V_37 = V_43 | V_44 ;
F_6 ( V_37 , V_2 -> V_5 + 8 ) ;
V_37 = V_44 | V_45 | V_46 | V_47 ;
F_6 ( V_37 , V_2 -> V_5 + 8 ) ;
V_37 = V_32 | V_33 | V_34 | V_35 ;
F_6 ( V_37 , V_2 -> V_5 + 9 ) ;
V_37 = V_48 | V_49 ;
F_6 ( V_37 , V_2 -> V_5 + 10 ) ;
V_37 = 0x07 ;
F_6 ( V_37 , V_2 -> V_5 + 8 ) ;
F_5 ( V_2 ) ;
F_12 ( V_26 , V_2 -> V_5 + 2 ) ;
V_19 -> V_20 = 0 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_50 * V_31 )
{
unsigned int V_15 ;
unsigned long V_5 ;
int V_51 ;
struct V_3 * V_4 ;
V_2 -> V_52 = L_7 ;
V_5 = V_31 -> V_53 [ 0 ] ;
if ( V_5 == 0 )
V_5 = 0x300 ;
if ( ! F_20 ( V_5 , V_54 , L_7 ) ) {
F_21 ( V_2 -> V_21 , L_8 ) ;
return - V_55 ;
}
V_2 -> V_5 = V_5 ;
V_15 = V_31 -> V_53 [ 0 ] ;
F_16 ( V_2 -> V_21 , L_9 , V_15 ) ;
V_51 = F_22 ( V_15 , F_7 , 0 , L_7 , V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
V_2 -> V_15 = V_15 ;
V_51 = F_23 ( V_2 , sizeof( struct V_56 ) ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 = F_24 ( V_2 , 1 ) ;
if ( V_51 < 0 )
return V_51 ;
V_4 = V_2 -> V_17 + 0 ;
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
static void F_25 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 )
F_26 ( V_2 -> V_15 , V_2 ) ;
if ( V_2 -> V_5 )
F_27 ( V_2 -> V_5 , V_54 ) ;
}
