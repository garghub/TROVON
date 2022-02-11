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
int V_14 = 0 ;
unsigned int V_15 ;
V_2 -> V_11 . V_16 ++ ;
F_5 ( V_2 -> V_6 . V_17 . V_15 ) ;
V_15 = V_2 -> V_6 . V_17 . V_15 ;
if ( ! ( V_15 & V_18 ) )
return 0 ;
if ( V_15 & V_19 ) {
V_14 = F_6 ( V_2 ,
V_20 ) ;
if ( V_14 )
return V_14 ;
}
if ( ! F_7 ( V_2 -> V_21 ) )
F_8 ( V_2 ) ;
return - V_22 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_23 = V_2 -> V_6 . V_5 -> V_24 >> 16 ;
V_2 -> V_11 . V_25 ++ ;
F_10 ( V_2 , V_23 ) ;
F_11 ( true , L_1 , V_23 ) ;
return - V_22 ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_26 ;
V_2 -> V_11 . V_27 ++ ;
F_13 ( V_2 ,
V_2 -> V_6 . V_5 -> V_28 ,
V_2 -> V_6 . V_5 -> V_24 ) ;
V_26 = V_29 [ V_2 -> V_6 . V_5 -> V_28 >> 8 ] ;
if ( V_26 )
return V_26 ( V_2 ) ;
return - V_22 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
memset ( V_31 , 0 , sizeof( struct V_30 ) ) ;
V_31 -> V_32 = V_2 -> V_6 . V_5 -> V_33 ;
switch ( V_2 -> V_6 . V_5 -> V_33 & ~ V_34 ) {
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
V_31 -> V_45 = V_2 -> V_6 . V_5 -> V_46 ;
break;
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
V_31 -> V_53 = V_2 -> V_6 . V_5 -> V_54 ;
break;
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
V_31 -> V_45 = V_2 -> V_6 . V_5 -> V_46 ;
V_31 -> V_53 = V_2 -> V_6 . V_5 -> V_54 ;
V_31 -> V_61 = V_2 -> V_6 . V_5 -> V_62 ;
break;
case V_63 :
V_31 -> V_64 = V_2 -> V_6 . V_5 -> V_65 ;
V_31 -> V_66 = V_2 -> V_6 . V_5 -> V_46 ;
break;
case V_67 :
V_31 -> V_68 = V_2 -> V_6 . V_5 -> V_69 ;
break;
case V_70 :
V_31 -> V_45 = V_2 -> V_6 . V_5 -> V_46 ;
V_31 -> V_53 = V_2 -> V_6 . V_5 -> V_54 ;
break;
default:
break;
}
if ( V_2 -> V_6 . V_5 -> V_33 & V_34 ) {
V_31 -> V_71 = V_2 -> V_6 . V_5 -> V_72 ;
V_31 -> V_73 = V_2 -> V_6 . V_5 -> V_74 ;
V_31 -> V_75 = V_2 -> V_6 . V_5 -> V_76 ;
V_31 -> V_77 = V_2 -> V_6 . V_5 -> V_78 ;
}
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_79 * V_80 ;
int V_14 ;
if ( ! F_16 ( V_2 ) || ! F_17 ( V_2 ) )
return 0 ;
if ( V_81 -> V_82 . V_83 & V_84 )
return 0 ;
V_80 = (struct V_79 * ) V_2 -> V_6 . V_5 -> V_85 ;
V_14 = F_18 ( V_2 , V_86 , V_80 , sizeof( * V_80 ) ) ;
if ( V_14 )
return V_14 ;
memset ( V_80 , 0 , sizeof( * V_80 ) ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_30 V_31 ;
T_2 V_87 ;
int V_14 ;
V_2 -> V_11 . V_88 ++ ;
if ( F_20 ( V_2 ) && F_21 ( V_2 ) ) {
F_22 ( V_2 ) ;
if ( V_2 -> V_6 . V_5 -> V_33 == 0 )
return 0 ;
}
F_23 ( V_2 , V_2 -> V_6 . V_5 -> V_33 ) ;
if ( V_2 -> V_6 . V_5 -> V_33 == V_89 ) {
V_14 = F_24 ( V_2 , V_90 , & V_87 , sizeof( T_2 ) ) ;
if ( V_14 )
return V_14 ;
if ( ! F_25 ( & V_87 ) )
return - V_22 ;
}
V_14 = F_15 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_14 ( V_2 , & V_31 ) ;
return F_26 ( V_2 , & V_31 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_14 , V_91 ;
V_2 -> V_11 . V_92 ++ ;
V_14 = F_12 ( V_2 ) ;
V_91 = F_19 ( V_2 ) ;
if ( V_14 == - V_22 )
V_2 -> V_6 . V_5 -> V_10 = 0x04 ;
if ( V_14 )
return V_14 ;
return V_91 ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_3 V_93 = V_2 -> V_6 . V_5 -> V_93 ;
struct V_94 V_95 ;
T_2 V_96 ;
int V_14 ;
V_2 -> V_11 . V_97 ++ ;
V_14 = F_24 ( V_2 , V_98 , & V_96 , sizeof( T_2 ) ) ;
if ( V_14 )
return V_14 ;
if ( ( V_93 == V_99 || V_93 == V_100 ) &&
( V_96 . V_101 & V_102 ) )
return - V_22 ;
switch ( V_93 ) {
case V_99 :
V_95 . type = V_103 ;
break;
case V_100 :
V_95 . type = V_104 ;
break;
case V_105 :
if ( F_29 ( V_2 ) )
return 0 ;
V_95 . type = V_106 ;
V_95 . V_107 . V_108 . V_32 = V_2 -> V_6 . V_5 -> V_109 ;
break;
default:
return - V_22 ;
}
return F_30 ( V_2 , & V_95 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
unsigned long V_110 , V_111 ;
int V_112 , V_113 , V_14 ;
F_32 ( V_2 , & V_112 , & V_113 ) ;
V_110 = F_33 ( V_2 , V_2 -> V_114 -> V_115 . V_116 . V_117 [ V_113 ] ) ;
if ( F_34 ( V_2 -> V_21 , V_110 ) )
return F_35 ( V_2 , V_118 ) ;
V_14 = F_36 ( V_2 , V_110 , 0 ) ;
if ( V_14 != 0 )
return V_14 ;
V_111 = F_33 ( V_2 , V_2 -> V_114 -> V_115 . V_116 . V_117 [ V_112 ] ) ;
if ( F_34 ( V_2 -> V_21 , V_111 ) )
return F_35 ( V_2 , V_118 ) ;
V_14 = F_36 ( V_2 , V_111 , 1 ) ;
if ( V_14 != 0 )
return V_14 ;
F_1 ( V_2 , 4 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_5 -> V_28 == 0xb254 )
return F_31 ( V_2 ) ;
if ( V_2 -> V_6 . V_5 -> V_28 >> 8 == 0xae )
return F_38 ( V_2 ) ;
return - V_22 ;
}
int F_39 ( struct V_1 * V_2 )
{
T_1 V_119 ;
T_4 V_32 = V_2 -> V_6 . V_5 -> V_10 ;
if ( V_32 & 3 || ( V_32 >> 2 ) >= F_40 ( V_120 ) )
return - V_22 ;
V_119 = V_120 [ V_32 >> 2 ] ;
if ( V_119 )
return V_119 ( V_2 ) ;
return - V_22 ;
}
