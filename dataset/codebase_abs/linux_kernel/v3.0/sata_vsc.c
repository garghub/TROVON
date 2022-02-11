static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 * V_4 )
{
if ( V_3 > V_5 )
return - V_6 ;
* V_4 = F_2 ( V_2 -> V_7 -> V_8 . V_9 + ( V_3 * 4 ) ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 )
{
if ( V_3 > V_5 )
return - V_6 ;
F_4 ( V_4 , V_2 -> V_7 -> V_8 . V_9 + ( V_3 * 4 ) ) ;
return 0 ;
}
static void F_5 ( struct V_10 * V_7 )
{
void T_2 * V_11 ;
V_11 = V_7 -> V_12 -> V_13 [ V_14 ] +
V_15 + V_7 -> V_16 ;
F_6 ( 0 , V_11 ) ;
}
static void F_7 ( struct V_10 * V_7 )
{
void T_2 * V_11 ;
V_11 = V_7 -> V_12 -> V_13 [ V_14 ] +
V_15 + V_7 -> V_16 ;
F_6 ( 0xff , V_11 ) ;
}
static void F_8 ( struct V_10 * V_7 , T_3 V_17 )
{
void T_2 * V_11 ;
T_3 V_18 ;
V_11 = V_7 -> V_12 -> V_13 [ V_14 ] +
V_15 + V_7 -> V_16 ;
V_18 = F_9 ( V_11 ) ;
if ( V_17 & V_19 )
V_18 |= 0x80 ;
else
V_18 &= 0x7F ;
F_6 ( V_18 , V_11 ) ;
}
static void F_10 ( struct V_10 * V_7 , const struct V_20 * V_21 )
{
struct V_22 * V_8 = & V_7 -> V_8 ;
unsigned int V_23 = V_21 -> V_24 & V_25 ;
if ( ( V_21 -> V_17 & V_19 ) != ( V_7 -> V_26 & V_19 ) ) {
V_7 -> V_26 = V_21 -> V_17 ;
F_8 ( V_7 , V_21 -> V_17 & V_19 ) ;
}
if ( V_23 && ( V_21 -> V_24 & V_27 ) ) {
F_11 ( V_21 -> V_28 | ( ( ( V_29 ) V_21 -> V_30 ) << 8 ) ,
V_8 -> V_31 ) ;
F_11 ( V_21 -> V_32 | ( ( ( V_29 ) V_21 -> V_33 ) << 8 ) ,
V_8 -> V_34 ) ;
F_11 ( V_21 -> V_35 | ( ( ( V_29 ) V_21 -> V_36 ) << 8 ) ,
V_8 -> V_37 ) ;
F_11 ( V_21 -> V_38 | ( ( ( V_29 ) V_21 -> V_39 ) << 8 ) ,
V_8 -> V_40 ) ;
F_11 ( V_21 -> V_41 | ( ( ( V_29 ) V_21 -> V_42 ) << 8 ) ,
V_8 -> V_43 ) ;
} else if ( V_23 ) {
F_11 ( V_21 -> V_28 , V_8 -> V_31 ) ;
F_11 ( V_21 -> V_32 , V_8 -> V_34 ) ;
F_11 ( V_21 -> V_35 , V_8 -> V_37 ) ;
F_11 ( V_21 -> V_38 , V_8 -> V_40 ) ;
F_11 ( V_21 -> V_41 , V_8 -> V_43 ) ;
}
if ( V_21 -> V_24 & V_44 )
F_6 ( V_21 -> V_45 , V_8 -> V_46 ) ;
F_12 ( V_7 ) ;
}
static void F_13 ( struct V_10 * V_7 , struct V_20 * V_21 )
{
struct V_22 * V_8 = & V_7 -> V_8 ;
V_29 V_32 , V_35 , V_38 , V_41 , V_28 ;
V_21 -> V_47 = F_14 ( V_7 ) ;
V_21 -> V_45 = F_15 ( V_8 -> V_46 ) ;
V_28 = F_15 ( V_8 -> V_48 ) ;
V_32 = F_15 ( V_8 -> V_34 ) ;
V_35 = F_15 ( V_8 -> V_37 ) ;
V_38 = F_15 ( V_8 -> V_40 ) ;
V_41 = F_15 ( V_8 -> V_43 ) ;
V_21 -> V_28 = V_28 ;
V_21 -> V_32 = V_32 ;
V_21 -> V_35 = V_35 ;
V_21 -> V_38 = V_38 ;
V_21 -> V_41 = V_41 ;
if ( V_21 -> V_24 & V_27 ) {
V_21 -> V_30 = V_28 >> 8 ;
V_21 -> V_33 = V_32 >> 8 ;
V_21 -> V_36 = V_35 >> 8 ;
V_21 -> V_39 = V_38 >> 8 ;
V_21 -> V_42 = V_41 >> 8 ;
}
}
static inline void F_16 ( T_3 V_49 , struct V_10 * V_7 )
{
if ( V_49 & ( V_50 | V_51 ) )
F_17 ( V_7 ) ;
else
F_18 ( V_7 ) ;
}
static void F_19 ( T_3 V_49 , struct V_10 * V_7 )
{
struct V_52 * V_53 ;
int V_54 = 0 ;
if ( F_20 ( V_49 & V_55 ) ) {
F_16 ( V_49 , V_7 ) ;
return;
}
V_53 = F_21 ( V_7 , V_7 -> V_2 . V_56 ) ;
if ( V_53 && F_22 ( ! ( V_53 -> V_21 . V_24 & V_57 ) ) )
V_54 = F_23 ( V_7 , V_53 ) ;
if ( F_20 ( ! V_54 ) )
V_7 -> V_58 -> V_59 ( V_7 ) ;
}
static T_4 F_24 ( int V_60 , void * V_61 )
{
struct V_62 * V_12 = V_61 ;
unsigned int V_63 ;
unsigned int V_54 = 0 ;
T_1 V_64 ;
V_64 = F_2 ( V_12 -> V_13 [ V_14 ] + V_65 ) ;
if ( F_20 ( V_64 == 0xffffffff || V_64 == 0 ) ) {
if ( V_64 )
F_25 ( V_66 , V_12 -> V_67 ,
L_1
L_2 ) ;
goto V_68;
}
F_26 ( & V_12 -> V_69 ) ;
for ( V_63 = 0 ; V_63 < V_12 -> V_70 ; V_63 ++ ) {
T_3 V_49 = ( V_64 >> ( 8 * V_63 ) ) & 0xff ;
if ( V_49 ) {
F_19 ( V_49 , V_12 -> V_71 [ V_63 ] ) ;
V_54 ++ ;
}
}
F_27 ( & V_12 -> V_69 ) ;
V_68:
return F_28 ( V_54 ) ;
}
static void T_5 F_29 ( struct V_22 * V_72 ,
void T_2 * V_73 )
{
V_72 -> V_74 = V_73 + V_75 ;
V_72 -> V_76 = V_73 + V_77 ;
V_72 -> V_48 = V_73 + V_78 ;
V_72 -> V_31 = V_73 + V_79 ;
V_72 -> V_34 = V_73 + V_80 ;
V_72 -> V_37 = V_73 + V_81 ;
V_72 -> V_40 = V_73 + V_82 ;
V_72 -> V_43 = V_73 + V_83 ;
V_72 -> V_46 = V_73 + V_84 ;
V_72 -> V_85 = V_73 + V_86 ;
V_72 -> V_87 = V_73 + V_88 ;
V_72 -> V_89 = V_73 + V_90 ;
V_72 -> V_91 = V_73 + V_92 ;
V_72 -> V_93 = V_73 + V_94 ;
V_72 -> V_9 = V_73 + V_95 ;
F_4 ( 0 , V_73 + V_96 ) ;
F_4 ( 0 , V_73 + V_97 ) ;
}
static int T_5 F_30 ( struct V_98 * V_99 ,
const struct V_100 * V_101 )
{
static const struct V_102 V_103 = {
. V_24 = V_104 ,
. V_105 = V_106 ,
. V_107 = V_108 ,
. V_109 = V_110 ,
. V_111 = & V_112 ,
} ;
const struct V_102 * V_113 [] = { & V_103 , NULL } ;
static int V_114 ;
struct V_62 * V_12 ;
void T_2 * V_115 ;
int V_63 , V_116 ;
T_3 V_117 ;
if ( ! V_114 ++ )
F_25 ( V_118 , & V_99 -> V_67 , L_3 V_119 L_4 ) ;
V_12 = F_31 ( & V_99 -> V_67 , V_113 , 4 ) ;
if ( ! V_12 )
return - V_120 ;
V_116 = F_32 ( V_99 ) ;
if ( V_116 )
return V_116 ;
if ( F_33 ( V_99 , 0 ) == 0 )
return - V_121 ;
V_116 = F_34 ( V_99 , 1 << V_14 , V_122 ) ;
if ( V_116 == - V_123 )
F_35 ( V_99 ) ;
if ( V_116 )
return V_116 ;
V_12 -> V_13 = F_36 ( V_99 ) ;
V_115 = V_12 -> V_13 [ V_14 ] ;
for ( V_63 = 0 ; V_63 < V_12 -> V_70 ; V_63 ++ ) {
struct V_10 * V_7 = V_12 -> V_71 [ V_63 ] ;
unsigned int V_124 = ( V_63 + 1 ) * V_125 ;
F_29 ( & V_7 -> V_8 , V_115 + V_124 ) ;
F_37 ( V_7 , V_14 , - 1 , L_5 ) ;
F_37 ( V_7 , V_14 , V_124 , L_6 ) ;
}
V_116 = F_38 ( V_99 , F_39 ( 32 ) ) ;
if ( V_116 )
return V_116 ;
V_116 = F_40 ( V_99 , F_39 ( 32 ) ) ;
if ( V_116 )
return V_116 ;
F_41 ( V_99 , V_126 , & V_117 ) ;
if ( V_117 == 0x00 )
F_42 ( V_99 , V_126 , 0x80 ) ;
if ( F_43 ( V_99 ) == 0 )
F_44 ( V_99 , 0 ) ;
F_45 ( V_99 , 0x98 , 0 ) ;
F_46 ( V_99 ) ;
return F_47 ( V_12 , V_99 -> V_60 , F_24 ,
V_127 , & V_128 ) ;
}
static int T_6 F_48 ( void )
{
return F_49 ( & V_129 ) ;
}
static void T_7 F_50 ( void )
{
F_51 ( & V_129 ) ;
}
