static void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = & V_2 -> V_10 [ 0 ] ;
unsigned long V_11 , V_12 , V_13 , V_14 ;
F_2 ( V_2 -> V_15 , L_1 ,
V_6 -> V_16 , V_3 , V_4 ) ;
V_11 = ( V_4 & 0xffffffffe0000000ul ) >> 29 ;
if ( V_6 -> V_17 == 0x3 )
V_11 = ( V_11 << 1 ) | V_3 ;
V_12 = V_11 >> V_18 ;
V_13 = V_11 & ~ V_19 ;
V_14 = ( V_4 & 0x000000001fe00000ul ) >> 21 ;
F_3 ( V_2 , V_9 -> V_20 + V_12 , V_13 ,
V_14 , 0 , V_3 , L_2 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = & V_2 -> V_10 [ 0 ] ;
unsigned long V_11 , V_12 , V_13 ;
F_2 ( V_2 -> V_15 , L_3 ,
V_6 -> V_16 , V_3 , V_4 ) ;
V_11 = ( V_4 & 0xffffffffe0000000ul ) >> 29 ;
if ( V_6 -> V_17 == 0x3 )
V_11 = ( V_11 << 1 ) | V_3 ;
V_12 = V_11 >> V_18 ;
V_13 = V_11 & ~ V_19 ;
F_5 ( V_2 , V_9 -> V_20 + V_12 , V_13 , 0 , L_2 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_21 , V_22 , V_23 = 0 ;
V_21 = F_7 ( & V_6 -> V_24 -> V_25 ) ;
#ifdef F_8
if ( V_21 != V_6 -> V_26 ) {
F_2 ( V_2 -> V_15 , L_4 , V_21 ) ;
V_6 -> V_26 = V_21 ;
}
#endif
if ( ( V_6 -> V_17 & 0x1 ) && ( V_21 & V_27 ) ) {
V_22 = F_7 ( & V_6 -> V_24 -> V_28 ) ;
V_23 |= V_29 ;
F_1 ( V_2 , 0 , V_22 ) ;
}
if ( ( V_6 -> V_17 & 0x2 ) && ( V_21 & V_30 ) ) {
V_22 = F_7 ( & V_6 -> V_24 -> V_31 ) ;
V_23 |= V_32 ;
F_1 ( V_2 , 1 , V_22 ) ;
}
if ( ( V_6 -> V_17 & 0x1 ) && ( V_21 & V_33 ) ) {
V_22 = F_7 ( & V_6 -> V_24 -> V_28 ) ;
V_23 |= V_34 ;
F_4 ( V_2 , 0 , V_22 ) ;
}
if ( ( V_6 -> V_17 & 0x2 ) && ( V_21 & V_35 ) ) {
V_22 = F_7 ( & V_6 -> V_24 -> V_31 ) ;
V_23 |= V_36 ;
F_4 ( V_2 , 1 , V_22 ) ;
}
if ( V_23 ) {
V_21 &= ~ ( V_37 | V_38 ) ;
V_21 |= V_39 ;
V_21 &= ~ V_23 ;
F_9 ( & V_6 -> V_24 -> V_25 , V_21 ) ;
( void ) F_7 ( & V_6 -> V_24 -> V_25 ) ;
F_10 () ;
#ifdef F_8
V_21 = F_7 ( & V_6 -> V_24 -> V_25 ) ;
F_2 ( V_2 -> V_15 , L_5 , V_21 ) ;
#endif
}
}
static void T_2 F_11 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_10 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_40 * V_41 ;
for ( V_41 = NULL ;
( V_41 = F_12 ( V_41 , L_6 ) ) != NULL ; ) {
struct V_42 V_43 ;
if ( F_13 ( V_41 , 0 , & V_43 ) )
continue;
if ( F_14 ( V_41 ) != V_6 -> V_16 )
continue;
V_9 -> V_20 = V_43 . V_44 >> V_18 ;
V_9 -> V_45 = F_15 ( & V_43 ) >> V_18 ;
V_9 -> V_46 = V_9 -> V_20 + V_9 -> V_45 - 1 ;
V_9 -> V_47 = V_48 ;
V_9 -> V_49 = V_50 ;
F_2 ( V_2 -> V_15 ,
L_7
L_8 ,
V_6 -> V_16 , V_6 -> V_17 ,
V_9 -> V_20 , V_9 -> V_45 ) ;
break;
}
}
static int T_2 F_16 ( struct V_51 * V_52 )
{
struct V_53 T_3 * V_24 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
T_1 V_54 ;
int V_55 , V_17 ;
V_24 = F_17 ( F_18 ( V_52 -> V_56 ) ) ;
if ( V_24 == NULL )
return - V_57 ;
V_58 = V_59 ;
V_54 = F_7 ( & V_24 -> V_60 ) ;
F_2 ( & V_52 -> V_15 , L_9 , V_54 ) ;
V_17 = 0 ;
if ( V_54 & V_61 )
V_17 |= 0x1 ;
if ( V_54 & V_62 )
V_17 |= 0x2 ;
if ( V_17 == 0 ) {
F_19 ( & V_52 -> V_15 ,
L_10 ) ;
return - V_57 ;
}
F_2 ( & V_52 -> V_15 , L_11 ,
F_7 ( & V_24 -> V_25 ) ) ;
V_2 = F_20 ( sizeof( struct V_5 ) , 1 ,
V_17 == 3 ? 2 : 1 , V_52 -> V_56 ) ;
if ( V_2 == NULL )
return - V_63 ;
V_6 = V_2 -> V_7 ;
V_6 -> V_24 = V_24 ;
V_6 -> V_16 = V_52 -> V_56 ;
V_6 -> V_17 = V_17 ;
V_2 -> V_15 = & V_52 -> V_15 ;
V_2 -> V_64 = V_65 ;
V_2 -> V_66 = V_67 | V_68 | V_69 ;
V_2 -> V_70 = V_68 | V_69 ;
V_2 -> V_71 = L_12 ;
V_2 -> V_72 = L_13 ;
V_2 -> V_73 = V_73 ( & V_52 -> V_15 ) ;
V_2 -> V_74 = F_6 ;
F_11 ( V_2 ) ;
V_55 = F_21 ( V_2 ) ;
if ( V_55 ) {
F_22 ( & V_52 -> V_15 , L_14 ) ;
F_23 ( V_2 ) ;
return V_55 ;
}
return 0 ;
}
static int T_4 F_24 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_25 ( & V_52 -> V_15 ) ;
if ( V_2 )
F_23 ( V_2 ) ;
return 0 ;
}
static int T_5 F_26 ( void )
{
F_27 ( F_28 ( struct V_53 ,
V_28 ) != 0xf8 ) ;
F_27 ( F_28 ( struct V_53 ,
V_31 ) != 0x1b8 ) ;
F_27 ( F_28 ( struct V_53 ,
V_75 ) != 0x218 ) ;
F_27 ( F_28 ( struct V_53 ,
V_25 ) != 0x230 ) ;
F_27 ( F_28 ( struct V_53 ,
V_60 ) != 0x210 ) ;
F_27 ( F_28 ( struct V_53 ,
V_76 ) != 0x208 ) ;
return F_29 ( & V_77 ) ;
}
static void T_6 F_30 ( void )
{
F_31 ( & V_77 ) ;
}
