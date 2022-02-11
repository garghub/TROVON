static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
T_2 V_10 , V_11 ;
int V_12 ;
F_3 ( V_9 ) ;
V_10 = ( ( V_3 & 0x7f ) << 9 ) | ( V_4 & 0x1ff ) ;
F_4 ( V_9 , V_9 -> V_13 . V_14 | V_15 ) ;
F_5 ( V_9 , V_9 -> V_13 . V_16 & ~ V_15 ) ;
V_11 = F_6 ( V_9 ) & ~ V_15 ;
F_7 ( V_9 , V_11 ) ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
F_8 ( V_17 ) ;
V_11 &= ~ V_18 ;
V_10 <<= 1 ;
if ( V_10 & 0x10000 )
V_11 |= V_19 ;
else
V_11 &= ~ V_19 ;
F_7 ( V_9 , V_11 ) ;
F_8 ( V_17 ) ;
V_11 |= V_18 ;
F_7 ( V_9 , V_11 ) ;
}
F_8 ( V_17 ) ;
V_11 |= V_20 ;
F_7 ( V_9 , V_11 ) ;
F_8 ( V_17 ) ;
V_11 |= ( V_19 | V_18 ) ;
F_7 ( V_9 , V_11 ) ;
F_9 ( V_9 ) ;
}
static void F_10 ( struct V_21 * V_2 , T_3 V_3 , T_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_22 ) ;
F_11 ( V_6 -> V_9 , 0x34 , V_3 , V_4 ) ;
}
static void F_12 ( struct V_8 * V_9 , bool V_23 )
{
unsigned int V_11 = F_6 ( V_9 ) ;
struct V_5 * V_6 = V_9 -> V_6 ;
V_6 -> V_24 = ! V_23 ;
if ( V_23 )
V_11 &= ~ ( V_25 | V_26 ) ;
else
V_11 |= V_25 | V_26 ;
F_7 ( V_9 , V_11 ) ;
}
static bool F_13 ( struct V_8 * V_9 )
{
struct V_5 * V_6 = V_9 -> V_6 ;
return ! V_6 -> V_24 ;
}
static void F_14 ( struct V_8 * V_9 , bool V_27 )
{
struct V_5 * V_6 = V_9 -> V_6 ;
struct V_28 V_29 ;
struct V_30 * V_31 ;
T_1 V_32 = V_6 -> V_22 . V_33 [ V_34 ] & ~ V_35 ;
F_12 ( V_9 , ! V_27 ) ;
if ( ! V_27 )
V_32 |= V_35 ;
F_15 ( & V_6 -> V_22 , V_32 ) ;
V_6 -> V_27 = V_27 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_36 = V_37 ;
strncpy ( V_29 . V_38 , L_1 ,
sizeof( V_29 . V_38 ) ) ;
V_31 = F_16 ( V_9 -> V_39 , & V_29 ) ;
F_17 ( V_9 -> V_39 , V_40 , & V_31 -> V_41 ) ;
strncpy ( V_29 . V_38 , V_6 -> V_22 . V_42 [ V_43 ] . V_38 ,
sizeof( V_29 . V_38 ) ) ;
V_31 = F_16 ( V_9 -> V_39 , & V_29 ) ;
F_17 ( V_9 -> V_39 , V_40 , & V_31 -> V_41 ) ;
}
static void F_18 ( struct V_44 * V_45 )
{
struct V_5 * V_6 = F_2 ( V_45 , struct V_5 ,
V_46 . V_45 ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
bool V_27 = F_6 ( V_9 ) & V_47 ;
F_19 ( & V_6 -> V_46 , F_20 ( V_48 ) ) ;
if ( V_27 == V_6 -> V_27 )
return;
F_14 ( V_9 , V_27 ) ;
}
static void F_21 ( struct V_8 * V_9 , bool V_23 )
{
struct V_5 * V_6 = V_9 -> V_6 ;
if ( V_6 -> V_49 == V_23 )
return;
V_6 -> V_49 = V_23 ;
if ( V_23 ) {
bool V_27 = F_6 ( V_9 ) & V_47 ;
F_14 ( V_9 , V_27 ) ;
F_19 ( & V_6 -> V_46 ,
F_20 ( V_48 ) ) ;
} else
F_22 ( & V_6 -> V_46 ) ;
}
static bool F_23 ( struct V_8 * V_9 )
{
struct V_5 * V_6 = V_9 -> V_6 ;
return V_6 -> V_49 ;
}
static int F_24 ( struct V_30 * V_50 ,
struct V_51 * V_52 )
{
struct V_8 * V_9 = F_25 ( V_50 ) ;
int V_53 = V_50 -> V_54 ;
V_52 -> V_55 . integer . V_55 [ 0 ] = V_56 [ V_53 ] . F_26 ( V_9 ) ;
return 0 ;
}
static int F_27 ( struct V_30 * V_50 ,
struct V_51 * V_52 )
{
struct V_8 * V_9 = F_25 ( V_50 ) ;
int V_53 = V_50 -> V_54 ;
V_56 [ V_53 ] . F_28 ( V_9 , V_52 -> V_55 . integer . V_55 [ 0 ] ) ;
return 0 ;
}
static int F_29 ( struct V_8 * V_9 )
{
struct V_57 V_58 ;
struct V_30 * V_42 ;
int V_59 , V_12 ;
struct V_5 * V_6 = V_9 -> V_6 ;
V_6 -> V_22 . V_42 [ V_60 ] . V_38 = V_61 ;
V_6 -> V_22 . V_42 [ V_62 ] . V_38 = V_63 ;
V_6 -> V_22 . V_42 [ V_64 ] . V_38 = V_65 ;
V_6 -> V_22 . V_42 [ V_66 ] . V_38 = NULL ;
V_6 -> V_22 . V_42 [ V_67 ] . V_38 = V_68 ;
V_6 -> V_22 . V_42 [ V_69 ] . V_38 = V_70 ;
V_6 -> V_22 . V_42 [ V_71 ] . V_38 = V_72 ;
V_6 -> V_22 . V_42 [ V_73 ] . V_38 = V_74 ;
V_6 -> V_22 . V_42 [ V_75 ] . V_38 = V_76 ;
V_6 -> V_22 . V_42 [ V_77 ] . V_38 = V_78 ;
V_6 -> V_22 . V_42 [ V_79 ] . V_38 = V_80 ;
V_6 -> V_22 . V_42 [ V_81 ] . V_38 = V_82 ;
F_30 ( & V_6 -> V_22 ) ;
V_6 -> V_7 . V_42 [ V_83 ] . V_38 = V_84 ;
V_6 -> V_7 . V_42 [ V_85 ] . V_38 = V_86 ;
V_6 -> V_7 . V_42 [ V_87 ] . V_38 = NULL ;
V_6 -> V_7 . V_42 [ V_88 ] . V_38 = V_89 ;
V_6 -> V_7 . V_42 [ V_90 ] . V_38 = V_91 ;
V_6 -> V_7 . V_42 [ V_92 ] . V_38 = NULL ;
V_6 -> V_7 . V_42 [ V_93 ] . V_38 = V_94 ;
V_6 -> V_7 . V_42 [ V_95 ] . V_38 = V_96 ;
V_6 -> V_7 . V_42 [ V_97 ] . V_38 = NULL ;
V_6 -> V_7 . V_42 [ V_98 ] . V_38 = V_99 ;
V_6 -> V_7 . V_42 [ V_100 ] . V_38 = V_101 ;
V_6 -> V_7 . V_42 [ V_102 ] . V_38 = NULL ;
V_6 -> V_7 . V_42 [ V_103 ] . V_38 = V_104 ;
V_6 -> V_7 . V_42 [ V_105 ] . V_38 = V_106 ;
F_31 ( & V_6 -> V_7 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_36 = V_37 ;
for ( V_12 = 0 ; V_12 < F_32 ( V_56 ) ; V_12 ++ ) {
V_58 . V_54 = V_12 ;
V_58 . V_38 = V_56 [ V_12 ] . V_38 ;
V_58 . V_107 = V_108 ;
V_58 . V_109 = V_110 ;
V_58 . F_26 = F_24 ;
V_58 . V_111 = F_27 ;
V_42 = F_33 ( & V_58 , V_9 ) ;
if ( ! V_42 )
return - V_112 ;
V_59 = F_34 ( V_9 -> V_39 , V_42 ) ;
if ( V_59 < 0 )
return V_59 ;
}
return 0 ;
}
static void F_35 ( struct V_8 * V_9 , unsigned int V_113 )
{
struct V_5 * V_6 = V_9 -> V_6 ;
F_36 ( & V_6 -> V_22 ) ;
F_37 ( & V_6 -> V_7 ) ;
}
static int F_38 ( struct V_8 * V_9 )
{
struct V_5 * V_6 = V_9 -> V_6 ;
F_39 ( & V_6 -> V_22 ) ;
F_40 ( & V_6 -> V_7 ) ;
return 0 ;
}
static int F_41 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
V_6 = F_42 ( sizeof( * V_6 ) , V_114 ) ;
if ( ! V_6 )
return - V_112 ;
V_9 -> V_6 = V_6 ;
V_6 -> V_9 = V_9 ;
V_9 -> V_115 = 6 ;
V_9 -> V_116 = 2 ;
V_6 -> V_22 . V_117 . V_118 = F_10 ;
V_6 -> V_22 . V_39 = V_9 -> V_39 ;
F_43 ( & V_6 -> V_22 ) ;
V_6 -> V_7 . V_117 . V_118 = F_1 ;
V_6 -> V_7 . V_39 = V_9 -> V_39 ;
#ifdef F_44
V_9 -> V_119 = F_38 ;
V_9 -> V_120 = 1 ;
#endif
F_45 ( & V_6 -> V_7 ) ;
F_46 ( & V_6 -> V_7 ,
V_121 | V_122 ) ;
V_9 -> V_13 . V_123 = F_35 ;
F_47 ( & V_6 -> V_46 , F_18 ) ;
F_21 ( V_9 , true ) ;
return 0 ;
}
static void F_48 ( struct V_8 * V_9 )
{
struct V_5 * V_6 = V_9 -> V_6 ;
F_22 ( & V_6 -> V_46 ) ;
}
