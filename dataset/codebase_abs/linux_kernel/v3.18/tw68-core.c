static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , 0 ) ;
F_2 ( V_4 , 0xffffffff ) ;
F_2 ( V_5 , 0x1600 ) ;
F_3 ( V_6 , 0x80 ) ;
F_4 ( 100 ) ;
F_3 ( V_7 , 0x40 ) ;
F_3 ( V_8 , 0x04 ) ;
F_3 ( V_9 , 0 ) ;
F_3 ( V_6 , 0x42 ) ;
F_3 ( V_10 , 0x02 ) ;
F_3 ( V_11 , 0x12 ) ;
F_3 ( V_12 , 0xf0 ) ;
F_3 ( V_13 , 0x0f ) ;
F_3 ( V_14 , 0xd0 ) ;
F_3 ( V_15 , 0xcd ) ;
F_3 ( V_16 , 0 ) ;
F_3 ( V_17 , 0x11 ) ;
F_3 ( V_18 , 0 ) ;
F_3 ( V_19 , 0 ) ;
F_3 ( V_20 , 0x5c ) ;
F_3 ( V_21 , 0x51 ) ;
F_3 ( V_22 , 0x80 ) ;
F_3 ( V_23 , 0x80 ) ;
F_3 ( V_24 , 0x00 ) ;
F_3 ( V_25 , 0x53 ) ;
F_3 ( V_26 , 0x80 ) ;
F_3 ( V_27 , 0x44 ) ;
F_3 ( V_28 , 0x00 ) ;
F_3 ( V_29 , 0x07 ) ;
F_3 ( V_30 , 0x7f ) ;
F_3 ( V_31 , 0x50 ) ;
F_3 ( V_32 , 0x22 ) ;
F_3 ( V_33 , 0xf0 ) ;
F_3 ( V_34 , 0xd8 ) ;
F_3 ( V_35 , 0x3c ) ;
F_3 ( V_36 , 0x30 ) ;
F_3 ( V_37 , 0x44 ) ;
F_3 ( V_38 , 0x28 ) ;
F_3 ( V_39 , 0x04 ) ;
F_3 ( V_40 , 0 ) ;
F_3 ( V_41 , 0x68 ) ;
F_3 ( V_42 , 0x44 ) ;
F_3 ( V_43 , 0x30 ) ;
F_3 ( V_44 , 0x14 ) ;
F_3 ( V_45 , 0xa5 ) ;
F_3 ( V_46 , 0xe0 ) ;
F_3 ( V_47 , 0 ) ;
F_3 ( V_48 , 0x05 ) ;
F_3 ( V_49 , 0 ) ;
F_3 ( V_50 , 0 ) ;
F_2 ( V_51 , 0x03 ) ;
F_2 ( V_52 , 0x03 ) ;
F_2 ( V_5 , 0x2000 ) ;
F_2 ( V_53 , 0 ) ;
F_2 ( V_54 , 0 ) ;
F_2 ( V_55 , 0x0f ) ;
F_2 ( V_56 , 0 ) ;
F_5 ( & V_2 -> V_57 ) ;
F_6 ( & V_2 -> V_58 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static T_1 F_8 ( int V_59 , void * V_60 )
{
struct V_1 * V_2 = V_60 ;
T_2 V_61 , V_62 ;
int V_63 ;
V_61 = V_62 = F_9 ( V_4 ) & V_2 -> V_64 ;
if ( 0 == V_61 )
return V_65 ;
for ( V_63 = 0 ; V_63 < 10 ; V_63 ++ ) {
if ( V_61 & V_2 -> V_66 )
F_10 ( V_2 , V_61 ) ;
V_61 = F_9 ( V_4 ) & V_2 -> V_64 ;
if ( 0 == V_61 )
return V_67 ;
}
F_11 ( & V_2 -> V_68 -> V_2 , L_1 ,
V_2 -> V_69 , V_62 , F_9 ( V_4 ) ) ;
F_11 ( & V_2 -> V_68 -> V_2 , L_2 ,
V_2 -> V_69 , V_2 -> V_64 , V_2 -> V_66 ) ;
F_12 ( V_3 , V_2 -> V_64 ) ;
return V_67 ;
}
static int F_13 ( struct V_70 * V_70 ,
const struct V_71 * V_72 )
{
struct V_1 * V_2 ;
int V_73 = - 1 ;
int V_74 ;
V_2 = F_14 ( & V_70 -> V_2 , sizeof( * V_2 ) , V_75 ) ;
if ( NULL == V_2 )
return - V_76 ;
V_2 -> V_77 = F_15 ( & V_2 -> V_78 , L_3 ,
& V_79 ) ;
V_74 = F_16 ( & V_70 -> V_2 , & V_2 -> V_78 ) ;
if ( V_74 )
return V_74 ;
V_2 -> V_68 = V_70 ;
if ( F_17 ( V_70 ) ) {
V_74 = - V_80 ;
goto V_81;
}
V_2 -> V_69 = V_2 -> V_78 . V_69 ;
if ( V_82 != V_83 ) {
F_18 ( L_4 ,
V_2 -> V_69 , V_83 ) ;
F_19 ( V_70 , V_84 , V_83 ) ;
}
F_20 ( V_70 , V_85 , & V_2 -> V_86 ) ;
F_20 ( V_70 , V_84 , & V_2 -> V_87 ) ;
F_18 ( L_5 ,
V_2 -> V_69 , F_21 ( V_70 ) , V_2 -> V_86 , V_70 -> V_59 ,
V_2 -> V_87 , ( V_88 ) F_22 ( V_70 , 0 ) ) ;
F_23 ( V_70 ) ;
if ( ! F_24 ( V_70 , F_25 ( 32 ) ) ) {
F_18 ( L_6 , V_2 -> V_69 ) ;
V_74 = - V_80 ;
goto V_81;
}
switch ( V_72 -> V_89 ) {
case V_90 :
V_2 -> V_91 = V_92 ;
V_2 -> V_66 = V_93 ;
break;
case V_94 :
V_2 -> V_91 = V_95 ;
V_2 -> V_66 = V_93 | V_96 ;
break;
case V_97 :
V_2 -> V_91 = V_98 ;
V_2 -> V_66 = V_93 | V_96 ;
break;
default:
V_2 -> V_91 = V_99 ;
V_2 -> V_66 = V_93 | V_96 ;
break;
}
if ( ! F_26 ( F_22 ( V_70 , 0 ) ,
F_27 ( V_70 , 0 ) ,
V_2 -> V_69 ) ) {
V_74 = - V_100 ;
F_28 ( L_7 ,
V_2 -> V_69 ,
( unsigned long long ) F_22 ( V_70 , 0 ) ) ;
goto V_81;
}
V_2 -> V_101 = F_29 ( F_22 ( V_70 , 0 ) ,
F_27 ( V_70 , 0 ) ) ;
V_2 -> V_102 = ( V_103 V_104 * ) V_2 -> V_101 ;
if ( NULL == V_2 -> V_101 ) {
V_74 = - V_80 ;
F_28 ( L_8 ,
V_2 -> V_69 ) ;
goto V_105;
}
F_1 ( V_2 ) ;
V_74 = F_30 ( & V_70 -> V_2 , V_70 -> V_59 , F_8 ,
V_106 , V_2 -> V_69 , V_2 ) ;
if ( V_74 < 0 ) {
F_28 ( L_9 ,
V_2 -> V_69 , V_70 -> V_59 ) ;
goto V_107;
}
if ( V_2 -> V_77 < V_108 )
V_73 = V_109 [ V_2 -> V_77 ] ;
V_74 = F_31 ( V_2 , V_73 ) ;
if ( V_74 < 0 ) {
F_28 ( L_10 ,
V_2 -> V_69 ) ;
goto V_110;
}
F_32 ( V_3 , V_2 -> V_64 ) ;
F_18 ( L_11 ,
V_2 -> V_69 , F_33 ( & V_2 -> V_111 ) ) ;
return 0 ;
V_110:
F_34 ( & V_2 -> V_111 ) ;
V_107:
F_35 ( V_2 -> V_101 ) ;
V_105:
F_36 ( F_22 ( V_70 , 0 ) ,
F_27 ( V_70 , 0 ) ) ;
V_81:
F_37 ( & V_2 -> V_78 ) ;
return V_74 ;
}
static void F_38 ( struct V_70 * V_70 )
{
struct V_112 * V_78 = F_39 ( V_70 ) ;
struct V_1 * V_2 =
F_40 ( V_78 , struct V_1 , V_78 ) ;
F_12 ( V_5 , V_113 | V_114 ) ;
F_2 ( V_3 , 0 ) ;
F_34 ( & V_2 -> V_111 ) ;
F_41 ( & V_2 -> V_115 ) ;
F_35 ( V_2 -> V_101 ) ;
F_36 ( F_22 ( V_70 , 0 ) ,
F_27 ( V_70 , 0 ) ) ;
F_37 ( & V_2 -> V_78 ) ;
}
static int F_42 ( struct V_70 * V_70 , T_3 V_116 )
{
struct V_112 * V_78 = F_39 ( V_70 ) ;
struct V_1 * V_2 = F_40 ( V_78 ,
struct V_1 , V_78 ) ;
F_12 ( V_5 , V_113 | V_114 ) ;
V_2 -> V_64 &= ~ V_93 ;
F_2 ( V_3 , 0 ) ;
F_43 ( V_70 -> V_59 ) ;
F_44 ( V_70 ) ;
F_45 ( V_70 , F_46 ( V_70 , V_116 ) ) ;
F_47 ( & V_2 -> V_117 ) ;
return 0 ;
}
static int F_48 ( struct V_70 * V_70 )
{
struct V_112 * V_78 = F_39 ( V_70 ) ;
struct V_1 * V_2 = F_40 ( V_78 ,
struct V_1 , V_78 ) ;
struct V_118 * V_119 ;
unsigned long V_120 ;
F_45 ( V_70 , V_121 ) ;
F_49 ( V_70 ) ;
F_4 ( 100 ) ;
F_50 ( V_2 ) ;
F_51 ( & V_2 -> V_58 , V_120 ) ;
V_119 = F_40 ( V_2 -> V_122 . V_123 , struct V_118 , V_124 ) ;
F_52 ( V_2 , V_119 ) ;
F_53 ( & V_2 -> V_58 , V_120 ) ;
return 0 ;
}
