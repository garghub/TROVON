void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_5 ;
if ( V_5 -> V_7 & 1 ) {
V_3 = ( V_5 -> V_7 >> 4 ) & 0x6 ;
if ( ! V_3 )
V_3 = 4 ;
}
V_5 -> V_8 . V_9 = F_2 ( V_5 -> V_8 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_6 . V_5 -> V_10 ) {
case 0x0 :
V_2 -> V_11 . V_12 ++ ;
break;
case 0x10 :
V_2 -> V_11 . V_13 ++ ;
break;
default:
break;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_6 . V_16 ;
int V_17 = 0 ;
T_1 V_18 , V_19 ;
V_2 -> V_11 . V_20 ++ ;
if ( F_5 ( V_2 , 1 ) )
return 0 ;
F_6 ( & V_15 -> V_21 ) ;
V_18 = V_15 -> V_22 . V_23 . V_18 ;
V_19 = F_7 ( V_2 ) ;
F_8 ( & V_15 -> V_21 ) ;
F_9 ( V_19 , V_18 ) ;
if ( ! V_19 )
return 0 ;
if ( V_18 & V_24 ) {
V_17 = F_10 ( V_2 ,
V_25 ) ;
if ( V_17 )
return V_17 ;
}
if ( ! F_11 ( V_2 -> V_26 ) )
F_12 ( V_2 ) ;
return - V_27 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_28 = V_2 -> V_6 . V_5 -> V_29 >> 16 ;
V_2 -> V_11 . V_30 ++ ;
F_14 ( V_2 , V_28 ) ;
F_15 ( true , L_1 , V_28 ) ;
return - V_27 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_2 V_31 ;
V_2 -> V_11 . V_32 ++ ;
F_17 ( V_2 ,
V_2 -> V_6 . V_5 -> V_33 ,
V_2 -> V_6 . V_5 -> V_29 ) ;
V_31 = V_34 [ V_2 -> V_6 . V_5 -> V_33 >> 8 ] ;
if ( V_31 )
return V_31 ( V_2 ) ;
return - V_27 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
memset ( V_36 , 0 , sizeof( struct V_35 ) ) ;
V_36 -> V_37 = V_2 -> V_6 . V_5 -> V_38 ;
switch ( V_2 -> V_6 . V_5 -> V_38 & ~ V_39 ) {
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
V_36 -> V_50 = V_2 -> V_6 . V_5 -> V_51 ;
break;
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
V_36 -> V_58 = V_2 -> V_6 . V_5 -> V_59 ;
break;
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
V_36 -> V_50 = V_2 -> V_6 . V_5 -> V_51 ;
V_36 -> V_58 = V_2 -> V_6 . V_5 -> V_59 ;
V_36 -> V_66 = V_2 -> V_6 . V_5 -> V_67 ;
break;
case V_68 :
V_36 -> V_69 = V_2 -> V_6 . V_5 -> V_70 ;
V_36 -> V_71 = V_2 -> V_6 . V_5 -> V_51 ;
break;
case V_72 :
case V_73 :
V_36 -> V_74 = V_2 -> V_6 . V_5 -> V_75 ;
break;
case V_76 :
V_36 -> V_50 = V_2 -> V_6 . V_5 -> V_51 ;
V_36 -> V_58 = V_2 -> V_6 . V_5 -> V_59 ;
break;
default:
break;
}
if ( V_2 -> V_6 . V_5 -> V_38 & V_39 ) {
V_36 -> V_77 = V_2 -> V_6 . V_5 -> V_78 ;
V_36 -> V_79 = V_2 -> V_6 . V_5 -> V_80 ;
V_36 -> V_81 = V_2 -> V_6 . V_5 -> V_82 ;
V_36 -> V_83 = V_2 -> V_6 . V_5 -> V_84 ;
}
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_85 * V_86 ;
int V_17 ;
if ( ! F_20 ( V_2 ) || ! F_21 ( V_2 ) )
return 0 ;
if ( V_87 -> V_88 . V_89 & V_90 )
return 0 ;
V_86 = (struct V_85 * ) V_2 -> V_6 . V_5 -> V_91 ;
V_17 = F_22 ( V_2 , V_92 , V_86 , sizeof( * V_86 ) ) ;
if ( V_17 )
return V_17 ;
memset ( V_86 , 0 , sizeof( * V_86 ) ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_35 V_36 ;
T_3 V_93 ;
int V_17 ;
V_2 -> V_11 . V_94 ++ ;
if ( F_24 ( V_2 ) && F_25 ( V_2 ) ) {
F_26 ( V_2 ) ;
if ( V_2 -> V_6 . V_5 -> V_38 == 0 )
return 0 ;
}
F_27 ( V_2 , V_2 -> V_6 . V_5 -> V_38 ) ;
if ( V_2 -> V_6 . V_5 -> V_38 == V_95 ) {
V_17 = F_28 ( V_2 , V_96 , & V_93 , sizeof( T_3 ) ) ;
if ( V_17 )
return V_17 ;
if ( ! F_29 ( & V_93 ) )
return - V_27 ;
}
V_17 = F_19 ( V_2 ) ;
if ( V_17 )
return V_17 ;
F_18 ( V_2 , & V_36 ) ;
return F_30 ( V_2 , & V_36 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_17 , V_97 ;
V_2 -> V_11 . V_98 ++ ;
V_17 = F_16 ( V_2 ) ;
V_97 = F_23 ( V_2 ) ;
if ( V_17 == - V_27 )
V_2 -> V_6 . V_5 -> V_10 = 0x04 ;
if ( V_17 )
return V_17 ;
return V_97 ;
}
static int F_32 ( struct V_1 * V_2 )
{
T_4 V_99 = V_2 -> V_6 . V_5 -> V_99 ;
struct V_100 V_22 ;
T_3 V_101 ;
int V_17 ;
V_2 -> V_11 . V_102 ++ ;
V_17 = F_28 ( V_2 , V_103 , & V_101 , sizeof( T_3 ) ) ;
if ( V_17 )
return V_17 ;
if ( ( V_99 == V_104 || V_99 == V_105 ) &&
( V_101 . V_106 & V_107 ) )
return - V_27 ;
switch ( V_99 ) {
case V_104 :
V_22 . type = V_108 ;
break;
case V_105 :
V_22 . type = V_109 ;
break;
case V_110 :
V_22 . type = V_111 ;
V_22 . V_112 . V_113 . V_37 = V_2 -> V_6 . V_5 -> V_114 ;
V_17 = F_33 ( V_2 , & V_22 ) ;
if ( V_17 == - V_115 )
return 0 ;
return V_17 ;
default:
return - V_27 ;
}
return F_33 ( V_2 , & V_22 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
unsigned long V_116 , V_117 ;
int V_118 , V_119 , V_17 ;
F_35 ( V_2 , & V_118 , & V_119 ) ;
V_17 = F_36 ( V_2 , V_2 -> V_120 -> V_121 . V_122 . V_123 [ V_119 ] ,
V_119 , & V_116 , 0 ) ;
if ( V_17 )
return F_37 ( V_2 , V_17 ) ;
V_17 = F_38 ( V_2 , V_116 , 0 ) ;
if ( V_17 != 0 )
return V_17 ;
V_17 = F_36 ( V_2 , V_2 -> V_120 -> V_121 . V_122 . V_123 [ V_118 ] ,
V_118 , & V_117 , 1 ) ;
if ( V_17 )
return F_37 ( V_2 , V_17 ) ;
V_17 = F_38 ( V_2 , V_117 , 1 ) ;
if ( V_17 != 0 )
return V_17 ;
F_1 ( V_2 , 4 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_5 -> V_33 == 0xb254 )
return F_34 ( V_2 ) ;
if ( V_2 -> V_6 . V_5 -> V_33 >> 8 == 0xae )
return F_40 ( V_2 ) ;
return - V_27 ;
}
int F_41 ( struct V_1 * V_2 )
{
T_2 V_124 ;
T_5 V_37 = V_2 -> V_6 . V_5 -> V_10 ;
if ( V_37 & 3 || ( V_37 >> 2 ) >= F_42 ( V_125 ) )
return - V_27 ;
V_124 = V_125 [ V_37 >> 2 ] ;
if ( V_124 )
return V_124 ( V_2 ) ;
return - V_27 ;
}
