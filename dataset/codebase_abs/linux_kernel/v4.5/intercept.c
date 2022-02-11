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
case 0x10 :
V_2 -> V_11 . V_12 ++ ;
break;
default:
break;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_6 . V_15 ;
int V_16 = 0 ;
T_1 V_17 , V_18 ;
V_2 -> V_11 . V_19 ++ ;
if ( F_5 ( V_2 , 1 ) )
return 0 ;
F_6 ( & V_14 -> V_20 ) ;
V_17 = V_14 -> V_21 . V_22 . V_17 ;
V_18 = F_7 ( V_2 ) ;
F_8 ( & V_14 -> V_20 ) ;
F_9 ( V_18 , V_17 ) ;
if ( ! V_18 )
return 0 ;
if ( V_17 & V_23 ) {
V_16 = F_10 ( V_2 ,
V_24 ) ;
if ( V_16 )
return V_16 ;
}
if ( ! F_11 ( V_2 -> V_25 ) )
F_12 ( V_2 ) ;
return - V_26 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_27 = V_2 -> V_6 . V_5 -> V_28 >> 16 ;
V_2 -> V_11 . V_29 ++ ;
F_14 ( V_2 , V_27 ) ;
F_15 ( true , L_1 , V_27 ) ;
return - V_26 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_2 V_30 ;
V_2 -> V_11 . V_31 ++ ;
F_17 ( V_2 ,
V_2 -> V_6 . V_5 -> V_32 ,
V_2 -> V_6 . V_5 -> V_28 ) ;
V_30 = V_33 [ V_2 -> V_6 . V_5 -> V_32 >> 8 ] ;
if ( V_30 )
return V_30 ( V_2 ) ;
return - V_26 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
memset ( V_35 , 0 , sizeof( struct V_34 ) ) ;
V_35 -> V_36 = V_2 -> V_6 . V_5 -> V_37 ;
switch ( V_2 -> V_6 . V_5 -> V_37 & ~ V_38 ) {
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
V_35 -> V_49 = V_2 -> V_6 . V_5 -> V_50 ;
break;
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
V_35 -> V_57 = V_2 -> V_6 . V_5 -> V_58 ;
break;
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
V_35 -> V_49 = V_2 -> V_6 . V_5 -> V_50 ;
V_35 -> V_57 = V_2 -> V_6 . V_5 -> V_58 ;
V_35 -> V_65 = V_2 -> V_6 . V_5 -> V_66 ;
break;
case V_67 :
V_35 -> V_68 = V_2 -> V_6 . V_5 -> V_69 ;
V_35 -> V_70 = V_2 -> V_6 . V_5 -> V_50 ;
break;
case V_71 :
case V_72 :
V_35 -> V_73 = V_2 -> V_6 . V_5 -> V_74 ;
break;
case V_75 :
V_35 -> V_49 = V_2 -> V_6 . V_5 -> V_50 ;
V_35 -> V_57 = V_2 -> V_6 . V_5 -> V_58 ;
break;
default:
break;
}
if ( V_2 -> V_6 . V_5 -> V_37 & V_38 ) {
V_35 -> V_76 = V_2 -> V_6 . V_5 -> V_77 ;
V_35 -> V_78 = V_2 -> V_6 . V_5 -> V_79 ;
V_35 -> V_80 = V_2 -> V_6 . V_5 -> V_81 ;
V_35 -> V_82 = V_2 -> V_6 . V_5 -> V_83 ;
}
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_84 * V_85 ;
int V_16 ;
if ( ! F_20 ( V_2 ) || ! F_21 ( V_2 ) )
return 0 ;
if ( V_86 -> V_87 . V_88 & V_89 )
return 0 ;
V_85 = (struct V_84 * ) V_2 -> V_6 . V_5 -> V_90 ;
V_16 = F_22 ( V_2 , V_91 , V_85 , sizeof( * V_85 ) ) ;
if ( V_16 )
return V_16 ;
memset ( V_85 , 0 , sizeof( * V_85 ) ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_34 V_35 ;
T_3 V_92 ;
int V_16 ;
V_2 -> V_11 . V_93 ++ ;
if ( F_24 ( V_2 ) && F_25 ( V_2 ) ) {
F_26 ( V_2 ) ;
if ( V_2 -> V_6 . V_5 -> V_37 == 0 )
return 0 ;
}
F_27 ( V_2 , V_2 -> V_6 . V_5 -> V_37 ) ;
if ( V_2 -> V_6 . V_5 -> V_37 == V_94 ) {
V_16 = F_28 ( V_2 , V_95 , & V_92 , sizeof( T_3 ) ) ;
if ( V_16 )
return V_16 ;
if ( ! F_29 ( & V_92 ) )
return - V_26 ;
}
V_16 = F_19 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_18 ( V_2 , & V_35 ) ;
return F_30 ( V_2 , & V_35 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_4 V_96 = V_2 -> V_6 . V_5 -> V_96 ;
struct V_97 V_21 ;
T_3 V_98 ;
int V_16 ;
V_2 -> V_11 . V_99 ++ ;
V_16 = F_28 ( V_2 , V_100 , & V_98 , sizeof( T_3 ) ) ;
if ( V_16 )
return V_16 ;
if ( ( V_96 == V_101 || V_96 == V_102 ) &&
( V_98 . V_103 & V_104 ) )
return - V_26 ;
switch ( V_96 ) {
case V_101 :
V_21 . type = V_105 ;
break;
case V_102 :
V_21 . type = V_106 ;
break;
case V_107 :
V_21 . type = V_108 ;
V_21 . V_109 . V_110 . V_36 = V_2 -> V_6 . V_5 -> V_111 ;
V_16 = F_32 ( V_2 , & V_21 ) ;
if ( V_16 == - V_112 )
return 0 ;
return V_16 ;
default:
return - V_26 ;
}
return F_32 ( V_2 , & V_21 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
unsigned long V_113 , V_114 ;
int V_115 , V_116 , V_16 ;
F_34 ( V_2 , & V_115 , & V_116 ) ;
V_16 = F_35 ( V_2 , V_2 -> V_117 -> V_118 . V_119 . V_120 [ V_116 ] ,
V_116 , & V_113 , 0 ) ;
if ( V_16 )
return F_36 ( V_2 , V_16 ) ;
V_16 = F_37 ( V_2 , V_113 , 0 ) ;
if ( V_16 != 0 )
return V_16 ;
V_16 = F_35 ( V_2 , V_2 -> V_117 -> V_118 . V_119 . V_120 [ V_115 ] ,
V_115 , & V_114 , 1 ) ;
if ( V_16 )
return F_36 ( V_2 , V_16 ) ;
V_16 = F_37 ( V_2 , V_114 , 1 ) ;
if ( V_16 != 0 )
return V_16 ;
F_1 ( V_2 , 4 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_5 -> V_32 == 0xb254 )
return F_33 ( V_2 ) ;
if ( V_2 -> V_6 . V_5 -> V_32 >> 8 == 0xae )
return F_39 ( V_2 ) ;
return - V_26 ;
}
int F_40 ( struct V_1 * V_2 )
{
if ( F_41 ( V_2 -> V_25 ) )
return - V_26 ;
switch ( V_2 -> V_6 . V_5 -> V_10 ) {
case 0x10 :
case 0x18 :
return F_3 ( V_2 ) ;
case 0x04 :
return F_16 ( V_2 ) ;
case 0x08 :
return F_23 ( V_2 ) ;
case 0x14 :
return F_31 ( V_2 ) ;
case 0x1c :
return F_42 ( V_2 ) ;
case 0x20 :
return F_13 ( V_2 ) ;
case 0x28 :
return F_4 ( V_2 ) ;
case 0x38 :
return F_38 ( V_2 ) ;
default:
return - V_26 ;
}
}
