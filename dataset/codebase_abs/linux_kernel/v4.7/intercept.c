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
F_15 ( true , L_1 , V_33 ) ;
return - V_32 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_3 V_36 ;
V_2 -> V_17 . V_37 ++ ;
F_17 ( V_2 ,
V_2 -> V_5 . V_4 -> V_13 ,
V_2 -> V_5 . V_4 -> V_34 ) ;
V_36 = V_38 [ V_2 -> V_5 . V_4 -> V_13 >> 8 ] ;
if ( V_36 )
return V_36 ( V_2 ) ;
return - V_32 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_39 V_40 = {
. V_41 = V_2 -> V_5 . V_4 -> V_42 ,
. V_23 = V_43 ,
} ;
switch ( V_2 -> V_5 . V_4 -> V_42 & ~ V_44 ) {
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
V_40 . V_55 = V_2 -> V_5 . V_4 -> V_56 ;
break;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
V_40 . V_63 = V_2 -> V_5 . V_4 -> V_64 ;
break;
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
V_40 . V_55 = V_2 -> V_5 . V_4 -> V_56 ;
V_40 . V_63 = V_2 -> V_5 . V_4 -> V_64 ;
V_40 . V_71 = V_2 -> V_5 . V_4 -> V_72 ;
break;
case V_73 :
V_40 . V_74 = V_2 -> V_5 . V_4 -> V_75 ;
V_40 . V_76 = V_2 -> V_5 . V_4 -> V_56 ;
break;
case V_77 :
case V_78 :
V_40 . V_79 = V_2 -> V_5 . V_4 -> V_80 ;
break;
case V_81 :
V_40 . V_55 = V_2 -> V_5 . V_4 -> V_56 ;
V_40 . V_63 = V_2 -> V_5 . V_4 -> V_64 ;
break;
default:
break;
}
if ( V_2 -> V_5 . V_4 -> V_42 & V_44 ) {
V_40 . V_82 = V_2 -> V_5 . V_4 -> V_83 ;
V_40 . V_84 = V_2 -> V_5 . V_4 -> V_85 ;
V_40 . V_86 = V_2 -> V_5 . V_4 -> V_87 ;
V_40 . V_88 = V_2 -> V_5 . V_4 -> V_89 ;
}
return F_19 ( V_2 , & V_40 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_90 * V_91 ;
int V_22 ;
if ( ! F_21 ( V_2 ) || ! F_22 ( V_2 ) )
return 0 ;
if ( V_92 -> V_93 . V_94 & V_95 )
return 0 ;
V_91 = (struct V_90 * ) V_2 -> V_5 . V_4 -> V_96 ;
V_22 = F_23 ( V_2 , V_97 , V_91 , sizeof( * V_91 ) ) ;
if ( V_22 )
return V_22 ;
memset ( V_91 , 0 , sizeof( * V_91 ) ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
T_4 V_98 ;
int V_22 ;
V_2 -> V_17 . V_99 ++ ;
if ( F_25 ( V_2 ) && F_26 ( V_2 ) ) {
F_27 ( V_2 ) ;
if ( V_2 -> V_5 . V_4 -> V_42 == 0 )
return 0 ;
}
F_28 ( V_2 , V_2 -> V_5 . V_4 -> V_42 ) ;
if ( V_2 -> V_5 . V_4 -> V_42 == V_100 ) {
V_22 = F_29 ( V_2 , V_101 , & V_98 , sizeof( T_4 ) ) ;
if ( V_22 )
return V_22 ;
if ( ! F_30 ( & V_98 ) )
return - V_32 ;
}
V_22 = F_20 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_18 ( V_2 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_5 V_102 = V_2 -> V_5 . V_4 -> V_102 ;
struct V_103 V_27 ;
T_4 V_104 ;
int V_22 ;
V_2 -> V_17 . V_105 ++ ;
V_22 = F_29 ( V_2 , V_106 , & V_104 , sizeof( T_4 ) ) ;
if ( V_22 )
return V_22 ;
if ( ( V_102 == V_107 || V_102 == V_108 ) &&
( V_104 . V_109 & V_110 ) )
return - V_32 ;
switch ( V_102 ) {
case V_107 :
V_27 . type = V_111 ;
break;
case V_108 :
V_27 . type = V_112 ;
break;
case V_113 :
V_27 . type = V_114 ;
V_27 . V_115 . V_116 . V_41 = V_2 -> V_5 . V_4 -> V_117 ;
V_22 = F_32 ( V_2 , & V_27 ) ;
if ( V_22 == - V_118 )
return 0 ;
return V_22 ;
default:
return - V_32 ;
}
return F_32 ( V_2 , & V_27 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
unsigned long V_119 , V_120 ;
int V_121 , V_122 , V_22 ;
F_34 ( V_2 , & V_121 , & V_122 ) ;
V_22 = F_35 ( V_2 , V_2 -> V_123 -> V_124 . V_125 . V_126 [ V_122 ] ,
V_122 , & V_119 , V_127 ) ;
if ( V_22 )
return F_36 ( V_2 , V_22 ) ;
V_22 = F_37 ( V_2 , V_119 , 0 ) ;
if ( V_22 != 0 )
return V_22 ;
V_22 = F_35 ( V_2 , V_2 -> V_123 -> V_124 . V_125 . V_126 [ V_121 ] ,
V_121 , & V_120 , V_128 ) ;
if ( V_22 )
return F_36 ( V_2 , V_22 ) ;
V_22 = F_37 ( V_2 , V_120 , 1 ) ;
if ( V_22 != 0 )
return V_22 ;
F_38 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
V_2 -> V_17 . V_129 ++ ;
if ( V_2 -> V_5 . V_4 -> V_13 == 0xb254 )
return F_33 ( V_2 ) ;
if ( V_2 -> V_5 . V_4 -> V_13 >> 8 == 0xae )
return F_40 ( V_2 ) ;
return - V_32 ;
}
int F_41 ( struct V_1 * V_2 )
{
if ( F_42 ( V_2 -> V_31 ) )
return - V_32 ;
switch ( V_2 -> V_5 . V_4 -> V_7 ) {
case 0x10 :
case 0x18 :
return F_3 ( V_2 ) ;
case 0x04 :
return F_16 ( V_2 ) ;
case 0x08 :
return F_24 ( V_2 ) ;
case 0x14 :
return F_31 ( V_2 ) ;
case 0x1c :
return F_43 ( V_2 ) ;
case 0x20 :
return F_13 ( V_2 ) ;
case 0x28 :
return F_4 ( V_2 ) ;
case 0x38 :
return F_39 ( V_2 ) ;
default:
return - V_32 ;
}
}
