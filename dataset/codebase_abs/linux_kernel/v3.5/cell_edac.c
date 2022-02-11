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
F_3 ( V_20 , V_2 ,
V_9 -> V_21 + V_12 , V_13 , V_14 ,
0 , V_3 , - 1 , L_2 , L_2 , NULL ) ;
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
F_3 ( V_22 , V_2 ,
V_9 -> V_21 + V_12 , V_13 , 0 ,
0 , V_3 , - 1 , L_2 , L_2 , NULL ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_23 , V_24 , V_25 = 0 ;
V_23 = F_6 ( & V_6 -> V_26 -> V_27 ) ;
#ifdef F_7
if ( V_23 != V_6 -> V_28 ) {
F_2 ( V_2 -> V_15 , L_4 , V_23 ) ;
V_6 -> V_28 = V_23 ;
}
#endif
if ( ( V_6 -> V_17 & 0x1 ) && ( V_23 & V_29 ) ) {
V_24 = F_6 ( & V_6 -> V_26 -> V_30 ) ;
V_25 |= V_31 ;
F_1 ( V_2 , 0 , V_24 ) ;
}
if ( ( V_6 -> V_17 & 0x2 ) && ( V_23 & V_32 ) ) {
V_24 = F_6 ( & V_6 -> V_26 -> V_33 ) ;
V_25 |= V_34 ;
F_1 ( V_2 , 1 , V_24 ) ;
}
if ( ( V_6 -> V_17 & 0x1 ) && ( V_23 & V_35 ) ) {
V_24 = F_6 ( & V_6 -> V_26 -> V_30 ) ;
V_25 |= V_36 ;
F_4 ( V_2 , 0 , V_24 ) ;
}
if ( ( V_6 -> V_17 & 0x2 ) && ( V_23 & V_37 ) ) {
V_24 = F_6 ( & V_6 -> V_26 -> V_33 ) ;
V_25 |= V_38 ;
F_4 ( V_2 , 1 , V_24 ) ;
}
if ( V_25 ) {
V_23 &= ~ ( V_39 | V_40 ) ;
V_23 |= V_41 ;
V_23 &= ~ V_25 ;
F_8 ( & V_6 -> V_26 -> V_27 , V_23 ) ;
( void ) F_6 ( & V_6 -> V_26 -> V_27 ) ;
F_9 () ;
#ifdef F_7
V_23 = F_6 ( & V_6 -> V_26 -> V_27 ) ;
F_2 ( V_2 -> V_15 , L_5 , V_23 ) ;
#endif
}
}
static void T_2 F_10 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_10 [ 0 ] ;
struct V_42 * V_43 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_44 * V_45 ;
int V_46 ;
T_3 V_47 ;
for ( V_45 = NULL ;
( V_45 = F_11 ( V_45 , L_6 ) ) != NULL ; ) {
struct V_48 V_49 ;
if ( F_12 ( V_45 , 0 , & V_49 ) )
continue;
if ( F_13 ( V_45 ) != V_6 -> V_16 )
continue;
V_9 -> V_21 = V_49 . V_50 >> V_18 ;
V_47 = F_14 ( & V_49 ) >> V_18 ;
V_9 -> V_51 = V_9 -> V_21 + V_47 - 1 ;
for ( V_46 = 0 ; V_46 < V_9 -> V_52 ; V_46 ++ ) {
V_43 = V_9 -> V_53 [ V_46 ] . V_43 ;
V_43 -> V_54 = V_55 ;
V_43 -> V_56 = V_57 ;
V_43 -> V_47 = V_47 / V_9 -> V_52 ;
}
F_2 ( V_2 -> V_15 ,
L_7
L_8 ,
V_6 -> V_16 , V_6 -> V_17 ,
V_9 -> V_21 , V_47 ) ;
break;
}
}
static int T_2 F_15 ( struct V_58 * V_59 )
{
struct V_60 T_4 * V_26 ;
struct V_1 * V_2 ;
struct V_61 V_62 [ 2 ] ;
struct V_5 * V_6 ;
T_1 V_63 ;
int V_64 , V_17 , V_65 ;
V_26 = F_16 ( F_17 ( V_59 -> V_66 ) ) ;
if ( V_26 == NULL )
return - V_67 ;
V_68 = V_69 ;
V_63 = F_6 ( & V_26 -> V_70 ) ;
F_2 ( & V_59 -> V_15 , L_9 , V_63 ) ;
V_17 = 0 ;
if ( V_63 & V_71 )
V_17 |= 0x1 ;
if ( V_63 & V_72 )
V_17 |= 0x2 ;
if ( V_17 == 0 ) {
F_18 ( & V_59 -> V_15 ,
L_10 ) ;
return - V_67 ;
}
F_2 ( & V_59 -> V_15 , L_11 ,
F_6 ( & V_26 -> V_27 ) ) ;
V_65 = V_17 == 3 ? 2 : 1 ;
V_62 [ 0 ] . type = V_73 ;
V_62 [ 0 ] . V_74 = 1 ;
V_62 [ 0 ] . V_75 = true ;
V_62 [ 1 ] . type = V_76 ;
V_62 [ 1 ] . V_74 = V_65 ;
V_62 [ 1 ] . V_75 = false ;
V_2 = F_19 ( V_59 -> V_66 , F_20 ( V_62 ) , V_62 ,
sizeof( struct V_5 ) ) ;
if ( V_2 == NULL )
return - V_77 ;
V_6 = V_2 -> V_7 ;
V_6 -> V_26 = V_26 ;
V_6 -> V_16 = V_59 -> V_66 ;
V_6 -> V_17 = V_17 ;
V_2 -> V_15 = & V_59 -> V_15 ;
V_2 -> V_78 = V_79 ;
V_2 -> V_80 = V_81 | V_82 | V_83 ;
V_2 -> V_84 = V_82 | V_83 ;
V_2 -> V_85 = L_12 ;
V_2 -> V_86 = L_13 ;
V_2 -> V_87 = V_87 ( & V_59 -> V_15 ) ;
V_2 -> V_88 = F_5 ;
F_10 ( V_2 ) ;
V_64 = F_21 ( V_2 ) ;
if ( V_64 ) {
F_22 ( & V_59 -> V_15 , L_14 ) ;
F_23 ( V_2 ) ;
return V_64 ;
}
return 0 ;
}
static int T_5 F_24 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = F_25 ( & V_59 -> V_15 ) ;
if ( V_2 )
F_23 ( V_2 ) ;
return 0 ;
}
static int T_6 F_26 ( void )
{
F_27 ( F_28 ( struct V_60 ,
V_30 ) != 0xf8 ) ;
F_27 ( F_28 ( struct V_60 ,
V_33 ) != 0x1b8 ) ;
F_27 ( F_28 ( struct V_60 ,
V_89 ) != 0x218 ) ;
F_27 ( F_28 ( struct V_60 ,
V_27 ) != 0x230 ) ;
F_27 ( F_28 ( struct V_60 ,
V_70 ) != 0x210 ) ;
F_27 ( F_28 ( struct V_60 ,
V_90 ) != 0x208 ) ;
return F_29 ( & V_91 ) ;
}
static void T_7 F_30 ( void )
{
F_31 ( & V_91 ) ;
}
