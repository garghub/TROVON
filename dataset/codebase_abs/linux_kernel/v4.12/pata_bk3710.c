static void F_1 ( void T_1 * V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
T_2 V_4 ;
T_3 V_5 ;
T_4 V_6 , V_7 , V_8 ;
V_8 = F_2 ( V_9 [ V_3 ] . V_10 ,
V_11 ) - 1 ;
V_6 = F_2 ( 20 , V_11 ) - 1 ;
V_7 = F_2 ( V_9 [ V_3 ] . V_12 ,
V_11 ) - 1 ;
V_4 = F_3 ( V_1 + V_13 ) & ( 0xFF << ( V_2 ? 0 : 8 ) ) ;
V_4 |= V_8 << ( V_2 ? 8 : 0 ) ;
F_4 ( V_4 , V_1 + V_13 ) ;
V_4 = F_3 ( V_1 + V_14 ) & ( 0xFF << ( V_2 ? 0 : 8 ) ) ;
V_4 |= V_7 << ( V_2 ? 8 : 0 ) ;
F_4 ( V_4 , V_1 + V_14 ) ;
V_4 = F_3 ( V_1 + V_15 ) & ( 0xFF << ( V_2 ? 0 : 8 ) ) ;
V_4 |= V_6 << ( V_2 ? 8 : 0 ) ;
F_4 ( V_4 , V_1 + V_15 ) ;
V_5 = F_5 ( V_1 + V_16 ) | ( 1 << V_2 ) ;
F_6 ( V_5 , V_1 + V_16 ) ;
}
static void F_7 ( void T_1 * V_1 , unsigned int V_2 ,
unsigned short V_17 ,
unsigned int V_3 )
{
const struct V_18 * V_19 ;
int V_10 ;
T_2 V_4 ;
T_3 V_5 ;
T_4 V_20 , V_21 , V_8 ;
V_19 = F_8 ( V_3 ) ;
V_10 = F_9 ( int , V_19 -> V_22 , V_17 ) ;
V_8 = F_2 ( V_10 , V_11 ) ;
V_20 = F_2 ( V_19 -> V_23 , V_11 ) ;
V_21 = V_8 - V_20 - 1 ;
V_20 -- ;
V_4 = F_3 ( V_1 + V_24 ) & ( 0xFF << ( V_2 ? 0 : 8 ) ) ;
V_4 |= V_20 << ( V_2 ? 8 : 0 ) ;
F_4 ( V_4 , V_1 + V_24 ) ;
V_4 = F_3 ( V_1 + V_25 ) & ( 0xFF << ( V_2 ? 0 : 8 ) ) ;
V_4 |= V_21 << ( V_2 ? 8 : 0 ) ;
F_4 ( V_4 , V_1 + V_25 ) ;
V_5 = F_5 ( V_1 + V_16 ) & ~ ( 1 << V_2 ) ;
F_6 ( V_5 , V_1 + V_16 ) ;
}
static void F_10 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
void T_1 * V_1 = ( void T_1 * ) V_27 -> V_30 . V_31 ;
int V_32 = V_29 -> V_33 ;
const T_4 V_34 = V_29 -> V_35 ;
if ( V_34 >= V_36 )
F_1 ( V_1 , V_32 ,
V_34 - V_36 ) ;
else
F_7 ( V_1 , V_32 ,
V_29 -> V_37 [ V_38 ] ,
V_34 ) ;
}
static void F_11 ( void T_1 * V_1 , struct V_28 * V_39 ,
unsigned int V_2 , unsigned int V_10 ,
unsigned int V_3 )
{
const struct V_18 * V_19 ;
T_2 V_4 ;
T_4 V_40 , V_41 , V_8 ;
V_19 = F_8 ( V_42 + V_3 ) ;
V_8 = F_2 ( V_10 , V_11 ) ;
V_40 = F_2 ( V_19 -> V_23 , V_11 ) ;
V_41 = V_8 - V_40 - 1 ;
V_40 -- ;
V_4 = F_3 ( V_1 + V_43 ) & ( 0xFF << ( V_2 ? 0 : 8 ) ) ;
V_4 |= V_40 << ( V_2 ? 8 : 0 ) ;
F_4 ( V_4 , V_1 + V_43 ) ;
V_4 = F_3 ( V_1 + V_44 ) & ( 0xFF << ( V_2 ? 0 : 8 ) ) ;
V_4 |= V_41 << ( V_2 ? 8 : 0 ) ;
F_4 ( V_4 , V_1 + V_44 ) ;
if ( V_39 ) {
T_4 V_45 = V_39 -> V_46 - V_42 ;
if ( V_45 < V_3 )
V_3 = V_45 ;
}
V_8 = F_2 ( V_19 -> V_47 , V_11 ) ;
V_40 = F_2 ( V_19 -> V_48 , V_11 ) ;
V_41 = V_8 - V_40 - 1 ;
V_40 -- ;
V_4 = F_3 ( V_1 + V_49 ) & ( 0xFF << ( V_2 ? 0 : 8 ) ) ;
V_4 |= V_40 << ( V_2 ? 8 : 0 ) ;
F_4 ( V_4 , V_1 + V_49 ) ;
V_4 = F_3 ( V_1 + V_50 ) & ( 0xFF << ( V_2 ? 0 : 8 ) ) ;
V_4 |= V_41 << ( V_2 ? 8 : 0 ) ;
F_4 ( V_4 , V_1 + V_50 ) ;
}
static void F_12 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
void T_1 * V_1 = ( void T_1 * ) V_27 -> V_30 . V_31 ;
struct V_28 * V_39 = F_13 ( V_29 ) ;
const struct V_18 * V_19 = F_8 ( V_29 -> V_46 ) ;
const T_3 * V_37 = V_29 -> V_37 ;
unsigned int V_51 = 0 ;
int V_32 = V_29 -> V_33 ;
const T_4 V_52 = V_29 -> V_46 - V_42 ;
if ( V_37 [ V_53 ] & 2 ) {
if ( F_14 ( V_37 ) )
V_51 = V_37 [ V_54 ] ;
else
V_51 = V_37 [ V_55 ] ;
if ( V_52 < 3 && V_51 < V_19 -> V_22 )
V_51 = 0 ;
}
if ( ! V_51 )
V_51 = V_19 -> V_22 ;
F_11 ( V_1 , V_39 , V_32 , V_51 , V_52 ) ;
}
static void F_15 ( void T_1 * V_1 )
{
F_6 ( F_16 ( 15 ) , V_1 + V_56 ) ;
F_6 ( 0 , V_1 + V_16 ) ;
F_4 ( 0x001 , V_1 + V_57 ) ;
F_4 ( 0 , V_1 + V_58 ) ;
F_6 ( 0xE , V_1 + V_59 ) ;
F_11 ( V_1 , NULL , 0 , 600 , 0 ) ;
F_11 ( V_1 , NULL , 1 , 600 , 0 ) ;
}
static int T_5 F_17 ( struct V_60 * V_61 )
{
struct V_62 * V_62 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_26 * V_27 ;
void T_1 * V_1 ;
unsigned long V_67 ;
int V_68 ;
V_62 = F_18 ( & V_61 -> V_2 , NULL ) ;
if ( F_19 ( V_62 ) )
return - V_69 ;
F_20 ( V_62 ) ;
V_67 = F_21 ( V_62 ) ;
if ( ! V_67 )
return - V_70 ;
V_11 = 1000000000UL / V_67 ;
V_64 = F_22 ( V_61 , V_71 , 0 ) ;
V_68 = F_23 ( V_61 , 0 ) ;
if ( V_68 < 0 ) {
F_24 ( V_72 L_1 ) ;
return V_68 ;
}
V_1 = F_25 ( & V_61 -> V_2 , V_64 ) ;
if ( F_19 ( V_1 ) )
return F_26 ( V_1 ) ;
F_15 ( V_1 ) ;
V_66 = F_27 ( & V_61 -> V_2 , 1 ) ;
if ( ! V_66 )
return - V_73 ;
V_27 = V_66 -> V_74 [ 0 ] ;
V_27 -> V_75 = & V_76 ;
V_27 -> V_77 = V_78 ;
V_27 -> V_79 = V_80 ;
V_27 -> V_81 = V_67 < 100000000 ? V_82 : V_83 ;
V_27 -> V_84 |= V_85 ;
V_27 -> V_30 . V_86 = V_1 + V_87 ;
V_27 -> V_30 . V_88 = V_1 + V_87 + 1 ;
V_27 -> V_30 . V_89 = V_1 + V_87 + 1 ;
V_27 -> V_30 . V_90 = V_1 + V_87 + 2 ;
V_27 -> V_30 . V_91 = V_1 + V_87 + 3 ;
V_27 -> V_30 . V_92 = V_1 + V_87 + 4 ;
V_27 -> V_30 . V_93 = V_1 + V_87 + 5 ;
V_27 -> V_30 . V_94 = V_1 + V_87 + 6 ;
V_27 -> V_30 . V_95 = V_1 + V_87 + 7 ;
V_27 -> V_30 . V_96 = V_1 + V_87 + 7 ;
V_27 -> V_30 . V_97 = V_1 + V_98 ;
V_27 -> V_30 . V_99 = V_1 + V_98 ;
V_27 -> V_30 . V_31 = V_1 ;
F_28 ( V_27 , L_2 ,
( unsigned long ) V_1 + V_87 ,
( unsigned long ) V_1 + V_98 ) ;
return F_29 ( V_66 , V_68 , V_100 , 0 ,
& V_101 ) ;
}
static int T_5 F_30 ( void )
{
return F_31 ( & V_102 , F_17 ) ;
}
