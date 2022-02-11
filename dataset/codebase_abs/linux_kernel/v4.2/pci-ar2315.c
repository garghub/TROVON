static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
return F_2 ( V_5 , struct V_1 , V_7 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_8 , T_1 V_9 )
{
return F_4 ( V_8 -> V_10 + V_9 ) ;
}
static inline void F_5 ( struct V_1 * V_8 , T_1 V_9 ,
T_1 V_11 )
{
F_6 ( V_11 , V_8 -> V_10 + V_9 ) ;
}
static inline void F_7 ( struct V_1 * V_8 , T_1 V_9 ,
T_1 V_12 , T_1 V_11 )
{
T_1 V_13 = F_3 ( V_8 , V_9 ) ;
V_13 &= ~ V_12 ;
V_13 |= V_11 ;
F_5 ( V_8 , V_9 , V_13 ) ;
}
static int F_8 ( struct V_1 * V_8 , unsigned V_14 ,
int V_15 , int V_16 , T_1 * V_17 , bool V_18 )
{
int V_19 = F_9 ( V_14 ) ;
int V_20 = F_10 ( V_14 ) ;
T_1 V_21 = ( 1 << ( 13 + V_20 ) ) | ( V_19 << 8 ) | ( V_15 & ~ 3 ) ;
T_1 V_12 = 0xffffffff >> 8 * ( 4 - V_16 ) ;
T_1 V_22 = ( V_15 & 3 ) * 8 ;
T_1 V_23 , V_24 ;
if ( V_21 >= V_25 || V_20 > 18 )
return V_26 ;
F_5 ( V_8 , V_27 , V_28 ) ;
F_7 ( V_8 , V_29 , 0 ,
V_30 ) ;
F_11 () ;
V_23 = F_4 ( V_8 -> V_31 + V_21 ) ;
V_24 = F_3 ( V_8 , V_27 ) ;
if ( V_24 & V_28 )
goto V_32;
if ( V_18 ) {
V_23 = ( V_23 & ~ ( V_12 << V_22 ) ) | * V_17 << V_22 ;
F_6 ( V_23 , V_8 -> V_31 + V_21 ) ;
V_24 = F_3 ( V_8 , V_27 ) ;
if ( V_24 & V_28 )
goto V_32;
} else {
* V_17 = ( V_23 >> V_22 ) & V_12 ;
}
goto exit;
V_32:
F_5 ( V_8 , V_27 , V_28 ) ;
if ( ! V_18 )
* V_17 = 0xffffffff ;
exit:
F_7 ( V_8 , V_29 , V_30 ,
0 ) ;
return V_24 & V_28 ? V_26 :
V_33 ;
}
static inline int F_12 ( struct V_1 * V_8 ,
unsigned V_14 , int V_15 , T_1 * V_11 )
{
return F_8 ( V_8 , V_14 , V_15 , sizeof( T_1 ) , V_11 ,
false ) ;
}
static inline int F_13 ( struct V_1 * V_8 ,
unsigned V_14 , int V_15 , T_1 V_11 )
{
return F_8 ( V_8 , V_14 , V_15 , sizeof( T_1 ) , & V_11 ,
true ) ;
}
static int F_14 ( struct V_2 * V_3 , unsigned V_14 , int V_15 ,
int V_16 , T_1 * V_23 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( F_10 ( V_14 ) == V_34 )
return V_26 ;
return F_8 ( V_8 , V_14 , V_15 , V_16 , V_23 , false ) ;
}
static int F_15 ( struct V_2 * V_3 , unsigned V_14 , int V_15 ,
int V_16 , T_1 V_23 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( F_10 ( V_14 ) == V_34 )
return V_26 ;
return F_8 ( V_8 , V_14 , V_15 , V_16 , & V_23 , true ) ;
}
static int F_16 ( struct V_1 * V_8 )
{
unsigned V_14 = F_17 ( V_34 , 0 ) ;
int V_35 ;
T_1 V_36 ;
V_35 = F_12 ( V_8 , V_14 , V_37 , & V_36 ) ;
if ( V_35 != V_33 || V_36 != V_38 )
return - V_39 ;
F_13 ( V_8 , V_14 , V_40 ,
V_41 ) ;
F_13 ( V_8 , V_14 , V_42 ,
V_43 ) ;
F_13 ( V_8 , V_14 , V_44 ,
V_45 ) ;
F_13 ( V_8 , V_14 , V_46 , V_47 |
V_48 | V_49 |
V_50 | V_51 |
V_52 | V_53 ) ;
return 0 ;
}
static void F_18 ( unsigned V_54 , struct V_55 * V_56 )
{
struct V_1 * V_8 = F_19 ( V_56 ) ;
T_1 V_57 = F_3 ( V_8 , V_27 ) &
F_3 ( V_8 , V_58 ) ;
unsigned V_59 = 0 ;
if ( V_57 )
V_59 = F_20 ( V_8 -> V_60 , F_21 ( V_57 ) ) ;
if ( V_59 )
F_22 ( V_59 ) ;
else
F_23 () ;
}
static void F_24 ( struct V_61 * V_62 )
{
struct V_1 * V_8 = F_25 ( V_62 ) ;
F_7 ( V_8 , V_58 , F_26 ( V_62 -> V_63 ) , 0 ) ;
}
static void F_27 ( struct V_61 * V_62 )
{
struct V_1 * V_8 = F_25 ( V_62 ) ;
T_1 V_64 = F_26 ( V_62 -> V_63 ) ;
F_7 ( V_8 , V_58 , V_64 , 0 ) ;
F_5 ( V_8 , V_27 , V_64 ) ;
}
static void F_28 ( struct V_61 * V_62 )
{
struct V_1 * V_8 = F_25 ( V_62 ) ;
F_7 ( V_8 , V_58 , 0 , F_26 ( V_62 -> V_63 ) ) ;
}
static int F_29 ( struct V_65 * V_62 , unsigned V_54 ,
T_2 V_66 )
{
F_30 ( V_54 , & V_67 , V_68 ) ;
F_31 ( V_54 , V_62 -> V_69 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_8 )
{
F_7 ( V_8 , V_70 , V_71 , 0 ) ;
F_7 ( V_8 , V_58 , ( V_28 |
V_72 ) , 0 ) ;
V_8 -> V_73 = F_33 ( V_8 -> V_60 , V_74 ) ;
F_34 ( V_8 -> V_54 , F_18 ,
V_8 ) ;
F_5 ( V_8 , V_27 , V_28 |
V_72 ) ;
F_7 ( V_8 , V_70 , 0 , V_71 ) ;
}
static int F_35 ( struct V_75 * V_76 )
{
struct V_1 * V_8 ;
struct V_77 * V_20 = & V_76 -> V_20 ;
struct V_78 * V_35 ;
int V_54 , V_79 ;
V_8 = F_36 ( V_20 , sizeof( * V_8 ) , V_80 ) ;
if ( ! V_8 )
return - V_81 ;
V_54 = F_37 ( V_76 , 0 ) ;
if ( V_54 < 0 )
return - V_82 ;
V_8 -> V_54 = V_54 ;
V_35 = F_38 ( V_76 , V_83 ,
L_1 ) ;
V_8 -> V_10 = F_39 ( V_20 , V_35 ) ;
if ( F_40 ( V_8 -> V_10 ) )
return F_41 ( V_8 -> V_10 ) ;
V_35 = F_38 ( V_76 , V_83 ,
L_2 ) ;
if ( ! V_35 )
return - V_82 ;
V_8 -> V_84 . V_85 = L_3 ;
V_8 -> V_84 . V_86 = V_35 ;
V_8 -> V_84 . V_87 = V_35 -> V_87 ;
V_8 -> V_84 . V_88 = V_35 -> V_88 ;
V_8 -> V_84 . V_89 = V_83 ;
V_8 -> V_31 = F_42 ( V_20 , V_35 -> V_87 ,
V_25 ) ;
if ( ! V_8 -> V_31 ) {
F_43 ( V_20 , L_4 ) ;
return - V_81 ;
}
F_7 ( V_8 , V_29 ,
V_90 ,
V_91 ) ;
F_44 ( 100 ) ;
F_7 ( V_8 , V_29 ,
V_90 ,
V_92 | V_93 | 0x8 ) ;
F_5 ( V_8 , V_94 ,
0x1E |
( 1 << 5 ) |
( 0x2 << 30 ) ) ;
F_3 ( V_8 , V_94 ) ;
F_44 ( 500 ) ;
V_79 = F_16 ( V_8 ) ;
if ( V_79 )
return V_79 ;
V_8 -> V_60 = F_45 ( NULL , V_95 ,
& V_96 , V_8 ) ;
if ( ! V_8 -> V_60 ) {
F_43 ( V_20 , L_5 ) ;
return - V_81 ;
}
F_32 ( V_8 ) ;
V_8 -> V_97 . V_85 = L_6 ;
V_8 -> V_97 . V_87 = 0 ;
V_8 -> V_97 . V_88 = 0 ;
V_8 -> V_97 . V_89 = V_98 ,
V_8 -> V_7 . V_99 = & V_100 ;
V_8 -> V_7 . V_101 = & V_8 -> V_84 ,
V_8 -> V_7 . V_102 = & V_8 -> V_97 ,
F_46 ( & V_8 -> V_7 ) ;
F_47 ( V_20 , L_7 ) ;
return 0 ;
}
static int T_3 F_48 ( void )
{
return F_49 ( & V_103 ) ;
}
int F_50 ( const struct V_104 * V_20 , T_4 V_105 , T_4 V_106 )
{
struct V_1 * V_8 = F_1 ( V_20 -> V_3 ) ;
return V_105 ? 0 : V_8 -> V_73 ;
}
int F_51 ( struct V_104 * V_20 )
{
return 0 ;
}
