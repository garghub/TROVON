static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 -> V_3 [ 0 ] ;
if ( V_2 -> V_5 -> V_6 & V_7 )
return - 1 ;
else {
switch ( V_3 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
return 0 ;
default:
return - 1 ;
}
}
}
static int F_2 ( struct V_14 * V_15 ,
unsigned int V_16 , T_2 * V_17 )
{
if ( V_16 > V_18 )
return - V_19 ;
* V_17 = F_3 ( V_15 -> V_5 -> V_20 . V_21 + ( V_16 * 4 ) ) ;
return 0 ;
}
static int F_4 ( struct V_14 * V_15 ,
unsigned int V_16 , T_2 V_17 )
{
if ( V_16 > V_18 )
return - V_19 ;
F_5 ( V_17 , V_15 -> V_5 -> V_20 . V_21 + ( V_16 * 4 ) ) ;
return 0 ;
}
static int F_6 ( struct V_14 * V_15 ,
unsigned int * V_22 , unsigned long V_23 )
{
T_1 V_24 ;
void T_3 * V_25 = V_15 -> V_5 -> V_20 . V_26 ;
V_24 = F_7 ( V_25 + V_27 ) ;
if ( V_24 & V_28 ) {
V_24 &= ~ V_28 ;
F_8 ( V_24 , V_25 + V_27 ) ;
}
return F_9 ( V_15 , V_22 , V_23 ) ;
}
static int F_10 ( struct V_14 * V_15 ,
unsigned int * V_22 , unsigned long V_23 )
{
T_1 V_24 ;
void T_3 * V_25 = V_15 -> V_5 -> V_20 . V_26 ;
V_24 = F_7 ( V_25 + V_27 ) ;
if ( V_24 & V_28 ) {
V_24 &= ~ V_28 ;
F_8 ( V_24 , V_25 + V_27 ) ;
}
return F_11 ( V_15 , V_22 , V_23 ) ;
}
static void F_12 ( struct V_29 * V_5 , const struct V_30 * V_31 )
{
struct V_32 * V_20 = & V_5 -> V_20 ;
unsigned int V_33 = V_31 -> V_6 & V_34 ;
if ( V_31 -> V_35 != V_5 -> V_36 ) {
F_8 ( V_31 -> V_35 , V_20 -> V_37 ) ;
V_5 -> V_36 = V_31 -> V_35 ;
F_13 ( V_5 ) ;
}
if ( V_33 && ( V_31 -> V_6 & V_38 ) ) {
F_14 ( V_31 -> V_39 | ( ( ( V_40 ) V_31 -> V_41 ) << 8 ) ,
V_20 -> V_42 ) ;
F_14 ( V_31 -> V_43 | ( ( ( V_40 ) V_31 -> V_44 ) << 8 ) ,
V_20 -> V_45 ) ;
F_14 ( V_31 -> V_46 | ( ( ( V_40 ) V_31 -> V_47 ) << 8 ) ,
V_20 -> V_48 ) ;
F_14 ( V_31 -> V_49 | ( ( ( V_40 ) V_31 -> V_50 ) << 8 ) ,
V_20 -> V_51 ) ;
F_14 ( V_31 -> V_52 | ( ( ( V_40 ) V_31 -> V_53 ) << 8 ) ,
V_20 -> V_54 ) ;
} else if ( V_33 ) {
F_14 ( V_31 -> V_39 , V_20 -> V_42 ) ;
F_14 ( V_31 -> V_43 , V_20 -> V_45 ) ;
F_14 ( V_31 -> V_46 , V_20 -> V_48 ) ;
F_14 ( V_31 -> V_49 , V_20 -> V_51 ) ;
F_14 ( V_31 -> V_52 , V_20 -> V_54 ) ;
}
if ( V_31 -> V_6 & V_55 )
F_8 ( V_31 -> V_56 , V_20 -> V_57 ) ;
F_13 ( V_5 ) ;
}
static void F_15 ( struct V_29 * V_5 , struct V_30 * V_31 )
{
struct V_32 * V_20 = & V_5 -> V_20 ;
V_40 V_43 , V_46 , V_49 , V_52 , V_39 ;
V_31 -> V_58 = F_16 ( V_5 ) ;
V_31 -> V_56 = F_17 ( V_20 -> V_57 ) ;
V_39 = F_17 ( V_20 -> V_59 ) ;
V_43 = F_17 ( V_20 -> V_45 ) ;
V_46 = F_17 ( V_20 -> V_48 ) ;
V_49 = F_17 ( V_20 -> V_51 ) ;
V_52 = F_17 ( V_20 -> V_54 ) ;
V_31 -> V_39 = V_39 ;
V_31 -> V_43 = V_43 ;
V_31 -> V_46 = V_46 ;
V_31 -> V_49 = V_49 ;
V_31 -> V_52 = V_52 ;
if ( V_31 -> V_6 & V_38 ) {
V_31 -> V_41 = V_39 >> 8 ;
V_31 -> V_44 = V_43 >> 8 ;
V_31 -> V_47 = V_46 >> 8 ;
V_31 -> V_50 = V_49 >> 8 ;
V_31 -> V_53 = V_52 >> 8 ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_29 * V_5 = V_2 -> V_5 ;
unsigned int V_60 = ( V_2 -> V_31 . V_6 & V_61 ) ;
T_1 V_24 ;
void T_3 * V_25 = V_5 -> V_20 . V_26 ;
F_19 () ;
F_5 ( V_5 -> V_62 , V_25 + V_63 ) ;
V_24 = F_7 ( V_25 + V_27 ) ;
V_24 &= ~ ( V_64 | V_28 ) ;
if ( ! V_60 )
V_24 |= V_64 ;
F_8 ( V_24 , V_25 + V_27 ) ;
if ( V_2 -> V_31 . V_65 != V_66 )
V_5 -> V_67 -> V_68 ( V_5 , & V_2 -> V_31 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_29 * V_5 = V_2 -> V_5 ;
void T_3 * V_25 = V_5 -> V_20 . V_26 ;
T_1 V_24 ;
V_24 = F_7 ( V_25 + V_27 ) ;
F_8 ( V_24 | V_28 , V_25 + V_27 ) ;
if ( V_2 -> V_31 . V_65 == V_66 )
V_5 -> V_67 -> V_68 ( V_5 , & V_2 -> V_31 ) ;
}
static T_1 F_16 ( struct V_29 * V_5 )
{
return F_3 ( V_5 -> V_20 . V_69 ) ;
}
static int F_21 ( struct V_70 * V_71 , char * V_72 , char * * V_73 ,
T_4 V_74 , int V_75 , int V_76 )
{
struct V_29 * V_5 ;
struct V_77 * V_78 ;
int V_79 , V_80 ;
V_5 = F_22 ( V_71 ) ;
if ( V_5 == NULL )
return 0 ;
V_78 = F_23 ( F_24 ( V_5 -> V_81 -> V_82 ) ) ;
if ( V_78 == NULL )
return 0 ;
V_80 = ( V_5 == V_5 -> V_81 -> V_83 [ 0 ] ) ? 0 : 1 ;
for ( V_78 = V_78 -> V_84 ; V_78 != NULL ; V_78 = V_78 -> V_85 ) {
const T_2 * V_86 = F_25 ( V_78 , L_1 , NULL ) ;
if ( ! V_86 )
continue;
if ( V_80 == * V_86 )
break;
}
if ( V_78 == NULL )
return 0 ;
V_79 = sprintf ( V_72 , L_2 , V_78 -> V_87 ) ;
return V_79 ;
}
static void F_26 ( struct V_32 * V_88 , void T_3 * V_89 )
{
V_88 -> V_90 = V_89 + V_91 ;
V_88 -> V_92 = V_89 + V_93 ;
V_88 -> V_42 =
V_88 -> V_59 = V_89 + V_94 ;
V_88 -> V_45 = V_89 + V_95 ;
V_88 -> V_48 = V_89 + V_96 ;
V_88 -> V_51 = V_89 + V_97 ;
V_88 -> V_54 = V_89 + V_98 ;
V_88 -> V_57 = V_89 + V_99 ;
V_88 -> V_100 =
V_88 -> V_69 = V_89 + V_101 ;
V_88 -> V_102 =
V_88 -> V_37 = V_89 + V_103 ;
V_88 -> V_26 = V_89 + V_104 ;
V_88 -> V_21 = V_89 + V_105 ;
}
static int F_27 ( struct V_106 * V_107 , const struct V_108 * V_109 )
{
const struct V_110 * V_111 [] =
{ & V_112 [ V_109 -> V_113 ] , NULL } ;
struct V_114 * V_81 ;
void T_3 * V_115 ;
int V_116 , V_117 , V_118 , V_119 ;
F_28 ( & V_107 -> V_82 , V_120 ) ;
V_116 = 4 ;
if ( V_111 [ 0 ] -> V_6 & V_121 )
V_116 = 8 ;
V_81 = F_29 ( & V_107 -> V_82 , V_111 , V_116 ) ;
if ( ! V_81 )
return - V_122 ;
V_119 = 5 ;
if ( V_111 [ 0 ] -> V_6 & V_123 )
V_119 = 3 ;
V_118 = F_30 ( V_107 ) ;
if ( V_118 )
return V_118 ;
if ( F_31 ( V_107 , V_119 ) == 0 ) {
F_32 ( V_107 ) ;
return - V_124 ;
}
V_118 = F_33 ( V_107 , 1 << V_119 , V_125 ) ;
if ( V_118 == - V_126 )
F_32 ( V_107 ) ;
if ( V_118 )
return V_118 ;
V_81 -> V_127 = F_34 ( V_107 ) ;
V_115 = V_81 -> V_127 [ V_119 ] ;
for ( V_117 = 0 ; V_117 < V_81 -> V_116 ; V_117 ++ ) {
struct V_29 * V_5 = V_81 -> V_83 [ V_117 ] ;
unsigned int V_74 = V_117 * V_128 ;
F_26 ( & V_5 -> V_20 , V_115 + V_74 ) ;
F_35 ( V_5 , 5 , - 1 , L_3 ) ;
F_35 ( V_5 , 5 , V_74 , L_4 ) ;
}
V_118 = F_36 ( V_107 , V_129 ) ;
if ( V_118 )
return V_118 ;
V_118 = F_37 ( V_107 , V_129 ) ;
if ( V_118 )
return V_118 ;
F_5 ( F_3 ( V_115 + V_130 ) & ~ 0x00040000 ,
V_115 + V_130 ) ;
F_5 ( 0xffffffff , V_115 + V_131 ) ;
F_5 ( 0x0 , V_115 + V_132 ) ;
F_38 ( V_107 ) ;
return F_39 ( V_81 , V_107 -> V_133 , V_134 ,
V_135 , & V_136 ) ;
}
