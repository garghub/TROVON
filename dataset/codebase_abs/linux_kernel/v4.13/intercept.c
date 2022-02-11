T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
T_1 V_6 = 0 ;
switch ( V_2 -> V_5 . V_4 -> V_7 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
V_6 = F_2 ( V_2 -> V_5 . V_4 -> V_13 >> 8 ) ;
if ( V_4 -> V_14 & 1 ) {
V_6 = ( V_4 -> V_14 >> 4 ) & 0x6 ;
if ( ! V_6 )
V_6 = 4 ;
}
break;
case V_15 :
V_6 = V_2 -> V_5 . V_4 -> V_16 & 0x6 ;
break;
}
return V_6 ;
}
static int F_3 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_5 . V_4 -> V_7 ) {
case 0x10 :
V_2 -> V_17 . V_18 ++ ;
break;
default:
break;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_5 . V_21 ;
int V_22 = 0 ;
T_2 V_23 , V_24 ;
V_2 -> V_17 . V_25 ++ ;
if ( F_5 ( V_2 , 1 ) )
return 0 ;
F_6 ( & V_20 -> V_26 ) ;
V_23 = V_20 -> V_27 . V_28 . V_23 ;
V_24 = F_7 ( V_2 ) ;
F_8 ( & V_20 -> V_26 ) ;
F_9 ( V_24 , V_23 ) ;
if ( ! V_24 )
return 0 ;
if ( V_23 & V_29 ) {
V_22 = F_10 ( V_2 ,
V_30 ) ;
if ( V_22 )
return V_22 ;
}
if ( ! F_11 ( V_2 -> V_31 ) )
F_12 ( V_2 ) ;
return - V_32 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_33 = V_2 -> V_5 . V_4 -> V_34 >> 16 ;
V_2 -> V_17 . V_35 ++ ;
F_14 ( V_2 , V_33 ) ;
F_15 ( 3 , L_1 , V_33 ,
V_36 -> V_37 , V_2 -> V_31 ) ;
F_16 ( V_33 != 0x44 , L_2 ,
V_33 ) ;
return - V_38 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_3 V_39 ;
V_2 -> V_17 . V_40 ++ ;
F_18 ( V_2 ,
V_2 -> V_5 . V_4 -> V_13 ,
V_2 -> V_5 . V_4 -> V_34 ) ;
V_39 = V_41 [ V_2 -> V_5 . V_4 -> V_13 >> 8 ] ;
if ( V_39 )
return V_39 ( V_2 ) ;
return - V_32 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_42 V_43 = {
. V_44 = V_2 -> V_5 . V_4 -> V_45 ,
. V_23 = V_46 ,
} ;
switch ( V_2 -> V_5 . V_4 -> V_45 & ~ V_47 ) {
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
V_43 . V_58 = V_2 -> V_5 . V_4 -> V_59 ;
break;
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
V_43 . V_66 = V_2 -> V_5 . V_4 -> V_67 ;
break;
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
V_43 . V_58 = V_2 -> V_5 . V_4 -> V_59 ;
V_43 . V_66 = V_2 -> V_5 . V_4 -> V_67 ;
V_43 . V_74 = V_2 -> V_5 . V_4 -> V_75 ;
break;
case V_76 :
V_43 . V_77 = V_2 -> V_5 . V_4 -> V_78 ;
V_43 . V_79 = V_2 -> V_5 . V_4 -> V_59 ;
break;
case V_80 :
case V_81 :
V_43 . V_82 = V_2 -> V_5 . V_4 -> V_83 ;
break;
case V_84 :
V_43 . V_58 = V_2 -> V_5 . V_4 -> V_59 ;
V_43 . V_66 = V_2 -> V_5 . V_4 -> V_67 ;
break;
default:
break;
}
if ( V_2 -> V_5 . V_4 -> V_45 & V_47 ) {
V_43 . V_85 = V_2 -> V_5 . V_4 -> V_86 ;
V_43 . V_87 = V_2 -> V_5 . V_4 -> V_88 ;
V_43 . V_89 = V_2 -> V_5 . V_4 -> V_90 ;
V_43 . V_91 = V_2 -> V_5 . V_4 -> V_92 ;
}
return F_20 ( V_2 , & V_43 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_93 * V_94 ;
int V_22 ;
if ( ! F_22 ( V_2 ) || ! F_23 ( V_2 ) )
return 0 ;
if ( V_36 -> V_95 . V_96 & V_97 )
return 0 ;
V_94 = (struct V_93 * ) V_2 -> V_5 . V_4 -> V_98 ;
V_22 = F_24 ( V_2 , V_99 , V_94 , sizeof( * V_94 ) ) ;
if ( V_22 )
return V_22 ;
memset ( V_94 , 0 , sizeof( * V_94 ) ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_4 V_100 ;
int V_22 ;
V_2 -> V_17 . V_101 ++ ;
if ( F_26 ( V_2 ) && F_27 ( V_2 ) ) {
V_22 = F_28 ( V_2 ) ;
if ( V_22 )
return V_22 ;
if ( V_2 -> V_5 . V_4 -> V_45 == 0 )
return 0 ;
}
F_29 ( V_2 , V_2 -> V_5 . V_4 -> V_45 ) ;
if ( V_2 -> V_5 . V_4 -> V_45 == V_102 ) {
V_22 = F_30 ( V_2 , V_103 , & V_100 , sizeof( T_4 ) ) ;
if ( V_22 )
return V_22 ;
if ( ! F_31 ( & V_100 ) )
return - V_32 ;
}
V_22 = F_21 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_19 ( V_2 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
T_5 V_104 = V_2 -> V_5 . V_4 -> V_104 ;
struct V_105 V_27 ;
T_4 V_106 ;
int V_22 ;
V_2 -> V_17 . V_107 ++ ;
V_22 = F_30 ( V_2 , V_108 , & V_106 , sizeof( T_4 ) ) ;
if ( V_22 )
return V_22 ;
if ( ( V_104 == V_109 || V_104 == V_110 ) &&
( V_106 . V_111 & V_112 ) )
return - V_32 ;
switch ( V_104 ) {
case V_109 :
V_27 . type = V_113 ;
break;
case V_110 :
V_27 . type = V_114 ;
break;
case V_115 :
V_27 . type = V_116 ;
V_27 . V_117 . V_118 . V_44 = V_2 -> V_5 . V_4 -> V_119 ;
V_22 = F_33 ( V_2 , & V_27 ) ;
if ( V_22 == - V_120 )
return 0 ;
return V_22 ;
default:
return - V_32 ;
}
return F_33 ( V_2 , & V_27 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
unsigned long V_121 , V_122 ;
int V_123 , V_124 , V_22 ;
F_35 ( V_2 , & V_123 , & V_124 ) ;
V_22 = F_36 ( V_2 , V_2 -> V_125 -> V_126 . V_127 . V_128 [ V_124 ] ,
V_124 , & V_121 , V_129 ) ;
if ( V_22 )
return F_37 ( V_2 , V_22 ) ;
V_22 = F_38 ( V_2 , V_121 , 0 ) ;
if ( V_22 != 0 )
return V_22 ;
V_22 = F_36 ( V_2 , V_2 -> V_125 -> V_126 . V_127 . V_128 [ V_123 ] ,
V_123 , & V_122 , V_130 ) ;
if ( V_22 )
return F_37 ( V_2 , V_22 ) ;
V_22 = F_38 ( V_2 , V_122 , 1 ) ;
if ( V_22 != 0 )
return V_22 ;
F_39 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
V_2 -> V_17 . V_131 ++ ;
if ( V_2 -> V_5 . V_4 -> V_13 == 0xb254 )
return F_34 ( V_2 ) ;
if ( V_2 -> V_5 . V_4 -> V_13 >> 8 == 0xae )
return F_41 ( V_2 ) ;
return - V_32 ;
}
static int F_42 ( struct V_1 * V_2 )
{
T_4 V_132 , V_106 ;
int V_22 ;
V_2 -> V_17 . V_133 ++ ;
F_43 ( V_2 , V_2 -> V_5 . V_4 -> V_13 ,
V_2 -> V_5 . V_4 -> V_34 ) ;
if ( V_2 -> V_5 . V_4 -> V_13 == 0xb256 )
return F_44 ( V_2 ) ;
if ( V_2 -> V_5 . V_4 -> V_13 == 0 && V_2 -> V_31 -> V_5 . V_134 )
return - V_32 ;
V_22 = F_30 ( V_2 , V_103 , & V_106 , sizeof( T_4 ) ) ;
if ( V_22 )
return V_22 ;
V_132 = V_2 -> V_5 . V_4 -> V_135 ;
if ( V_132 . V_136 - V_106 . V_136 <= 6 &&
! ( V_106 . V_111 & V_137 ) &&
! ( V_132 . V_111 & V_138 ) &&
( V_106 . V_111 & V_139 ) == ( V_132 . V_111 & V_139 ) &&
( V_106 . V_111 & V_140 ) == ( V_132 . V_111 & V_140 ) )
return - V_32 ;
return F_45 ( V_2 , V_141 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
int V_22 , V_142 = 0 ;
if ( F_47 ( V_2 -> V_31 ) )
return - V_32 ;
switch ( V_2 -> V_5 . V_4 -> V_7 ) {
case V_143 :
case V_144 :
return F_3 ( V_2 ) ;
case V_8 :
V_22 = F_17 ( V_2 ) ;
break;
case V_15 :
return F_25 ( V_2 ) ;
case V_145 :
return F_32 ( V_2 ) ;
case V_146 :
return F_48 ( V_2 ) ;
case V_147 :
return F_13 ( V_2 ) ;
case V_148 :
return F_4 ( V_2 ) ;
case V_10 :
V_22 = F_42 ( V_2 ) ;
break;
case V_11 :
V_22 = F_40 ( V_2 ) ;
break;
case V_149 :
V_22 = F_49 ( V_2 ) ;
break;
default:
return - V_32 ;
}
if ( V_2 -> V_5 . V_4 -> V_14 & 0x02 &&
( ! V_22 || V_22 == - V_32 ) )
V_142 = F_50 ( V_2 ) ;
return V_142 ? V_142 : V_22 ;
}
