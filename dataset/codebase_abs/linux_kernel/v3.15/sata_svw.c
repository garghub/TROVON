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
static int F_21 ( struct V_70 * V_71 , struct V_72 * V_73 )
{
struct V_29 * V_5 ;
struct V_74 * V_75 ;
int V_76 ;
V_5 = F_22 ( V_73 ) ;
if ( V_5 == NULL )
return 0 ;
V_75 = F_23 ( F_24 ( V_5 -> V_77 -> V_78 ) ) ;
if ( V_75 == NULL )
return 0 ;
V_76 = ( V_5 == V_5 -> V_77 -> V_79 [ 0 ] ) ? 0 : 1 ;
for ( V_75 = V_75 -> V_80 ; V_75 != NULL ; V_75 = V_75 -> V_81 ) {
const T_2 * V_82 = F_25 ( V_75 , L_1 , NULL ) ;
if ( ! V_82 )
continue;
if ( V_76 == * V_82 ) {
F_26 ( V_71 , L_2 , V_75 -> V_83 ) ;
break;
}
}
return 0 ;
}
static void F_27 ( struct V_32 * V_84 , void T_3 * V_85 )
{
V_84 -> V_86 = V_85 + V_87 ;
V_84 -> V_88 = V_85 + V_89 ;
V_84 -> V_42 =
V_84 -> V_59 = V_85 + V_90 ;
V_84 -> V_45 = V_85 + V_91 ;
V_84 -> V_48 = V_85 + V_92 ;
V_84 -> V_51 = V_85 + V_93 ;
V_84 -> V_54 = V_85 + V_94 ;
V_84 -> V_57 = V_85 + V_95 ;
V_84 -> V_96 =
V_84 -> V_69 = V_85 + V_97 ;
V_84 -> V_98 =
V_84 -> V_37 = V_85 + V_99 ;
V_84 -> V_26 = V_85 + V_100 ;
V_84 -> V_21 = V_85 + V_101 ;
}
static int F_28 ( struct V_102 * V_103 , const struct V_104 * V_105 )
{
const struct V_106 * V_107 [] =
{ & V_108 [ V_105 -> V_109 ] , NULL } ;
struct V_110 * V_77 ;
void T_3 * V_111 ;
int V_112 , V_113 , V_114 , V_115 ;
F_29 ( & V_103 -> V_78 , V_116 ) ;
V_112 = 4 ;
if ( V_107 [ 0 ] -> V_6 & V_117 )
V_112 = 8 ;
V_77 = F_30 ( & V_103 -> V_78 , V_107 , V_112 ) ;
if ( ! V_77 )
return - V_118 ;
V_115 = 5 ;
if ( V_107 [ 0 ] -> V_6 & V_119 )
V_115 = 3 ;
V_114 = F_31 ( V_103 ) ;
if ( V_114 )
return V_114 ;
if ( F_32 ( V_103 , V_115 ) == 0 ) {
F_33 ( V_103 ) ;
return - V_120 ;
}
V_114 = F_34 ( V_103 , 1 << V_115 , V_121 ) ;
if ( V_114 == - V_122 )
F_33 ( V_103 ) ;
if ( V_114 )
return V_114 ;
V_77 -> V_123 = F_35 ( V_103 ) ;
V_111 = V_77 -> V_123 [ V_115 ] ;
for ( V_113 = 0 ; V_113 < V_77 -> V_112 ; V_113 ++ ) {
struct V_29 * V_5 = V_77 -> V_79 [ V_113 ] ;
unsigned int V_124 = V_113 * V_125 ;
F_27 ( & V_5 -> V_20 , V_111 + V_124 ) ;
F_36 ( V_5 , 5 , - 1 , L_3 ) ;
F_36 ( V_5 , 5 , V_124 , L_4 ) ;
}
V_114 = F_37 ( V_103 , V_126 ) ;
if ( V_114 )
return V_114 ;
V_114 = F_38 ( V_103 , V_126 ) ;
if ( V_114 )
return V_114 ;
F_5 ( F_3 ( V_111 + V_127 ) & ~ 0x00040000 ,
V_111 + V_127 ) ;
F_5 ( 0xffffffff , V_111 + V_128 ) ;
F_5 ( 0x0 , V_111 + V_129 ) ;
F_39 ( V_103 ) ;
return F_40 ( V_77 , V_103 -> V_130 , V_131 ,
V_132 , & V_133 ) ;
}
