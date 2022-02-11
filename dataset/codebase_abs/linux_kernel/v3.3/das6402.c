static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
T_3 V_4 ;
unsigned short V_5 ;
V_4 = V_6 | V_7 | V_8 ;
F_6 ( V_4 , V_3 -> V_9 + 15 ) ;
V_5 = 2000 ;
V_4 = ( T_3 ) ( 0xff & V_5 ) ;
F_6 ( V_4 , V_3 -> V_9 + 12 ) ;
V_4 = ( T_3 ) ( 0xff & ( V_5 >> 8 ) ) ;
F_6 ( V_4 , V_3 -> V_9 + 12 ) ;
V_4 = V_10 | V_11 | V_8 ;
F_6 ( V_4 , V_3 -> V_9 + 15 ) ;
V_5 = 10 ;
V_4 = ( T_3 ) ( 0xff & V_5 ) ;
F_6 ( V_4 , V_3 -> V_9 + 13 ) ;
V_4 = ( T_3 ) ( 0xff & ( V_5 >> 8 ) ) ;
F_6 ( V_4 , V_3 -> V_9 + 13 ) ;
V_4 = V_10 | V_12 | V_8 ;
F_6 ( V_4 , V_3 -> V_9 + 15 ) ;
V_5 = 1000 ;
V_4 = ( T_3 ) ( 0xff & V_5 ) ;
F_6 ( V_4 , V_3 -> V_9 + 14 ) ;
V_4 = ( T_3 ) ( 0xff & ( V_5 >> 8 ) ) ;
F_6 ( V_4 , V_3 -> V_9 + 14 ) ;
}
static T_4 F_7 ( int V_13 , void * V_14 )
{
struct V_2 * V_3 = V_14 ;
struct V_15 * V_16 = V_3 -> V_17 ;
if ( ! V_3 -> V_18 || V_19 -> V_20 ) {
F_8 ( V_3 -> V_21 , L_1 ) ;
return V_22 ;
}
#ifdef F_9
F_10 ( L_2 ,
V_19 -> V_23 ) ;
F_10 ( L_3 , F_11 ( V_3 -> V_9 + 2 ) ) ;
#endif
F_12 ( V_3 , V_16 ) ;
if ( V_16 -> V_24 -> V_25 >= V_19 -> V_26 ) {
F_13 ( V_27 , V_3 -> V_9 + 2 ) ;
F_14 ( 0x07 , V_3 -> V_9 + 8 ) ;
#ifdef F_9
F_10 ( L_4 ,
V_19 -> V_28 - V_29 ) ;
#endif
V_16 -> V_24 -> V_30 |= V_31 ;
F_15 ( V_3 , V_16 ) ;
}
F_14 ( 0x01 , V_3 -> V_9 + 8 ) ;
F_15 ( V_3 , V_16 ) ;
return V_22 ;
}
static void F_12 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
while ( 1 ) {
if ( ! ( F_16 ( V_3 -> V_9 + 8 ) & 0x01 ) )
return;
F_17 ( V_16 -> V_24 , F_18 ( V_3 -> V_9 ) ) ;
}
}
static int F_19 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
V_19 -> V_20 = 1 ;
F_20 ( V_3 -> V_21 , L_5 ) ;
V_19 -> V_20 = 1 ;
F_6 ( 0x02 , V_3 -> V_9 + 10 ) ;
F_13 ( V_27 , V_3 -> V_9 + 2 ) ;
F_6 ( 0 , V_3 -> V_9 + 9 ) ;
F_13 ( V_27 , V_3 -> V_9 + 2 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 ,
struct V_15 * V_16 , T_5 * V_32 )
{
V_19 -> V_20 = 1 ;
F_20 ( V_3 -> V_21 , L_6 ) ;
F_6 ( 0x03 , V_3 -> V_9 + 10 ) ;
F_13 ( V_27 , V_3 -> V_9 + 2 ) ;
F_6 ( V_33 | V_34 | V_35 | V_36 , V_3 -> V_9 + 9 ) ;
V_19 -> V_26 = V_32 -> V_37 * sizeof( short ) ;
V_19 -> V_20 = 0 ;
F_13 ( V_27 , V_3 -> V_9 + 2 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 )
{
T_3 V_38 ;
V_19 -> V_20 = 1 ;
F_14 ( 0x07 , V_3 -> V_9 + 8 ) ;
F_6 ( V_39 , V_3 -> V_9 + 11 ) ;
V_38 = V_40 | V_41 | V_39 | V_42 | V_43 ;
F_6 ( V_38 , V_3 -> V_9 + 11 ) ;
F_6 ( V_44 , V_3 -> V_9 + 8 ) ;
V_38 = V_44 | V_45 ;
F_6 ( V_38 , V_3 -> V_9 + 8 ) ;
V_38 = V_45 | V_46 | V_47 | V_48 ;
F_6 ( V_38 , V_3 -> V_9 + 8 ) ;
V_38 = V_33 | V_34 | V_35 | V_36 ;
F_6 ( V_38 , V_3 -> V_9 + 9 ) ;
V_38 = V_49 | V_50 ;
F_6 ( V_38 , V_3 -> V_9 + 10 ) ;
V_38 = 0x07 ;
F_6 ( V_38 , V_3 -> V_9 + 8 ) ;
F_5 ( V_3 ) ;
F_13 ( V_27 , V_3 -> V_9 + 2 ) ;
V_19 -> V_20 = 0 ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 )
{
if ( V_3 -> V_13 )
F_24 ( V_3 -> V_13 , V_3 ) ;
if ( V_3 -> V_9 )
F_25 ( V_3 -> V_9 , V_51 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_52 * V_32 )
{
unsigned int V_13 ;
unsigned long V_9 ;
int V_53 ;
struct V_15 * V_16 ;
V_3 -> V_54 = L_7 ;
V_9 = V_32 -> V_55 [ 0 ] ;
if ( V_9 == 0 )
V_9 = 0x300 ;
if ( ! F_27 ( V_9 , V_51 , L_7 ) ) {
F_28 ( V_3 -> V_21 , L_8 ) ;
return - V_56 ;
}
V_3 -> V_9 = V_9 ;
V_13 = V_32 -> V_55 [ 0 ] ;
F_20 ( V_3 -> V_21 , L_9 , V_13 ) ;
V_53 = F_29 ( V_13 , F_7 , 0 , L_7 , V_3 ) ;
if ( V_53 < 0 )
return V_53 ;
V_3 -> V_13 = V_13 ;
V_53 = F_30 ( V_3 , sizeof( struct V_57 ) ) ;
if ( V_53 < 0 )
return V_53 ;
V_53 = F_31 ( V_3 , 1 ) ;
if ( V_53 < 0 )
return V_53 ;
V_16 = V_3 -> V_17 + 0 ;
V_16 -> type = V_58 ;
V_16 -> V_59 = V_60 | V_61 ;
V_16 -> V_62 = 8 ;
V_16 -> V_63 = F_19 ;
V_16 -> V_64 = ( 1 << 12 ) - 1 ;
V_16 -> V_65 = 16 ;
V_16 -> V_66 = & V_67 ;
F_22 ( V_3 ) ;
return 0 ;
}
