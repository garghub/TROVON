static int F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . V_4 -> V_5 ) {
case 0x0 :
V_2 -> V_6 . V_7 ++ ;
break;
case 0x10 :
V_2 -> V_6 . V_8 ++ ;
break;
default:
break;
}
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
V_2 -> V_6 . V_10 ++ ;
F_3 ( & V_2 -> V_3 . V_11 . V_12 ) ;
F_4 ( V_2 -> V_3 . V_11 . V_13 ) ;
if ( V_2 -> V_3 . V_11 . V_13 & V_14 ) {
F_5 ( V_2 ) ;
V_2 -> V_3 . V_11 . V_13 &= ~ V_14 ;
F_6 ( V_2 , 3 , L_1 , L_2 ) ;
V_9 = - V_15 ;
}
if ( V_2 -> V_3 . V_11 . V_13 & V_16 ) {
V_2 -> V_3 . V_11 . V_13 &= ~ V_16 ;
F_7 ( & V_2 -> V_3 . V_11 . V_12 ) ;
V_9 = F_8 ( V_2 ,
V_17 ) ;
if ( V_9 >= 0 )
V_9 = - V_15 ;
} else
F_7 ( & V_2 -> V_3 . V_11 . V_12 ) ;
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_18 = V_2 -> V_3 . V_4 -> V_19 >> 16 ;
V_2 -> V_6 . V_20 ++ ;
F_10 ( V_2 , V_18 ) ;
F_11 ( true , L_3 , V_18 ) ;
return - V_15 ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_21 ;
V_2 -> V_6 . V_22 ++ ;
F_13 ( V_2 ,
V_2 -> V_3 . V_4 -> V_23 ,
V_2 -> V_3 . V_4 -> V_19 ) ;
V_21 = V_24 [ V_2 -> V_3 . V_4 -> V_23 >> 8 ] ;
if ( V_21 )
return V_21 ( V_2 ) ;
return - V_15 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
memset ( V_26 , 0 , sizeof( struct V_25 ) ) ;
V_26 -> V_27 = V_2 -> V_3 . V_4 -> V_28 ;
switch ( V_2 -> V_3 . V_4 -> V_28 & ~ V_29 ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
V_26 -> V_40 = V_2 -> V_3 . V_4 -> V_41 ;
break;
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
V_26 -> V_48 = V_2 -> V_3 . V_4 -> V_49 ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
V_26 -> V_40 = V_2 -> V_3 . V_4 -> V_41 ;
V_26 -> V_48 = V_2 -> V_3 . V_4 -> V_49 ;
V_26 -> V_56 = V_2 -> V_3 . V_4 -> V_57 ;
break;
case V_58 :
V_26 -> V_59 = V_2 -> V_3 . V_4 -> V_60 ;
V_26 -> V_61 = V_2 -> V_3 . V_4 -> V_41 ;
break;
case V_62 :
V_26 -> V_63 = V_2 -> V_3 . V_4 -> V_64 ;
break;
case V_65 :
V_26 -> V_40 = V_2 -> V_3 . V_4 -> V_41 ;
V_26 -> V_48 = V_2 -> V_3 . V_4 -> V_49 ;
break;
default:
break;
}
if ( V_2 -> V_3 . V_4 -> V_28 & V_29 ) {
V_26 -> V_66 = V_2 -> V_3 . V_4 -> V_67 ;
V_26 -> V_68 = V_2 -> V_3 . V_4 -> V_69 ;
V_26 -> V_70 = V_2 -> V_3 . V_4 -> V_71 ;
V_26 -> V_72 = V_2 -> V_3 . V_4 -> V_73 ;
}
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_74 * V_75 ;
int V_9 ;
if ( ! F_16 ( V_2 ) || ! F_17 ( V_2 ) )
return 0 ;
if ( V_76 -> V_77 . V_78 & V_79 )
return 0 ;
V_75 = (struct V_74 * ) V_2 -> V_3 . V_4 -> V_80 ;
V_9 = F_18 ( V_2 , V_81 , V_75 , sizeof( * V_75 ) ) ;
if ( V_9 )
return V_9 ;
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_25 V_26 ;
T_2 V_82 ;
int V_9 ;
V_2 -> V_6 . V_83 ++ ;
if ( F_20 ( V_2 ) && F_21 ( V_2 ) ) {
F_22 ( V_2 ) ;
if ( V_2 -> V_3 . V_4 -> V_28 == 0 )
return 0 ;
}
F_23 ( V_2 , V_2 -> V_3 . V_4 -> V_28 ) ;
if ( V_2 -> V_3 . V_4 -> V_28 == V_84 ) {
V_9 = F_24 ( V_2 , V_85 , & V_82 , sizeof( T_2 ) ) ;
if ( V_9 )
return V_9 ;
if ( ! F_25 ( & V_82 ) )
return - V_15 ;
}
V_9 = F_15 ( V_2 ) ;
if ( V_9 )
return V_9 ;
F_14 ( V_2 , & V_26 ) ;
return F_26 ( V_2 , & V_26 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_9 , V_86 ;
V_2 -> V_6 . V_87 ++ ;
V_9 = F_12 ( V_2 ) ;
V_86 = F_19 ( V_2 ) ;
if ( V_9 == - V_15 )
V_2 -> V_3 . V_4 -> V_5 = 0x04 ;
if ( V_9 )
return V_9 ;
return V_86 ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_3 V_88 = V_2 -> V_3 . V_4 -> V_88 ;
struct V_89 V_90 ;
T_2 V_91 ;
int V_9 ;
V_2 -> V_6 . V_92 ++ ;
V_9 = F_24 ( V_2 , V_93 , & V_91 , sizeof( T_2 ) ) ;
if ( V_9 )
return V_9 ;
if ( ( V_88 == V_94 || V_88 == V_95 ) &&
( V_91 . V_96 & V_97 ) )
return - V_15 ;
switch ( V_88 ) {
case V_94 :
V_90 . type = V_98 ;
break;
case V_95 :
V_90 . type = V_99 ;
break;
case V_100 :
if ( F_29 ( V_2 ) )
return 0 ;
V_90 . type = V_101 ;
V_90 . V_102 = V_2 -> V_3 . V_4 -> V_103 ;
break;
default:
return - V_15 ;
}
return F_30 ( V_2 , & V_90 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_2 * V_82 = & V_2 -> V_3 . V_4 -> V_104 ;
unsigned long V_105 , V_106 ;
int V_107 , V_108 , V_9 ;
F_32 ( V_2 , & V_107 , & V_108 ) ;
V_105 = F_33 ( V_2 , V_2 -> V_109 -> V_110 . V_111 . V_112 [ V_108 ] ) ;
if ( F_34 ( V_2 -> V_113 , V_105 ) )
return F_35 ( V_2 , V_114 ) ;
V_9 = F_36 ( V_2 , V_105 , 0 ) ;
if ( V_9 != 0 )
return V_9 ;
V_106 = F_33 ( V_2 , V_2 -> V_109 -> V_110 . V_111 . V_112 [ V_107 ] ) ;
if ( F_34 ( V_2 -> V_113 , V_106 ) )
return F_35 ( V_2 , V_114 ) ;
V_9 = F_36 ( V_2 , V_106 , 1 ) ;
if ( V_9 != 0 )
return V_9 ;
V_82 -> V_115 = F_37 ( * V_82 , 4 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 -> V_23 == 0xb254 )
return F_31 ( V_2 ) ;
if ( V_2 -> V_3 . V_4 -> V_23 >> 8 == 0xae )
return F_39 ( V_2 ) ;
return - V_15 ;
}
int F_40 ( struct V_1 * V_2 )
{
T_1 V_116 ;
T_4 V_27 = V_2 -> V_3 . V_4 -> V_5 ;
if ( V_27 & 3 || ( V_27 >> 2 ) >= F_41 ( V_117 ) )
return - V_15 ;
V_116 = V_117 [ V_27 >> 2 ] ;
if ( V_116 )
return V_116 ( V_2 ) ;
return - V_15 ;
}
