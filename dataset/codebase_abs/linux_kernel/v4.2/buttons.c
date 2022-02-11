static int T_1 F_1 ( const struct V_1 * V_2 ,
T_2 V_3 )
{
T_2 V_4 = V_3 * sizeof( * V_2 ) ;
V_5 . V_2 = F_2 ( V_4 , V_6 ) ;
if ( ! V_5 . V_2 )
return - V_7 ;
memcpy ( V_5 . V_2 , V_2 , V_4 ) ;
V_5 . V_3 = V_3 ;
return 0 ;
}
int T_1 F_3 ( void )
{
enum V_8 V_9 = F_4 () ;
int V_10 ;
switch ( V_9 ) {
case V_11 :
V_10 = F_5 ( V_12 ) ;
break;
case V_13 :
V_10 = F_5 ( V_14 ) ;
break;
case V_15 :
V_10 = F_5 ( V_16 ) ;
break;
case V_17 :
V_10 = F_5 ( V_18 ) ;
break;
case V_19 :
V_10 = F_5 ( V_20 ) ;
break;
case V_21 :
V_10 = F_5 ( V_22 ) ;
break;
case V_23 :
V_10 = F_5 ( V_24 ) ;
break;
case V_25 :
V_10 = F_5 ( V_26 ) ;
break;
case V_27 :
V_10 = F_5 ( V_28 ) ;
break;
case V_29 :
V_10 = F_5 ( V_30 ) ;
break;
case V_31 :
V_10 = F_5 ( V_32 ) ;
break;
case V_33 :
V_10 = F_5 ( V_34 ) ;
break;
case V_35 :
V_10 = F_5 ( V_36 ) ;
break;
case V_37 :
V_10 = F_5 ( V_38 ) ;
break;
case V_39 :
V_10 = F_5 ( V_40 ) ;
break;
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
V_10 = F_5 ( V_46 ) ;
break;
case V_47 :
V_10 = F_5 ( V_48 ) ;
break;
case V_49 :
V_10 = F_5 ( V_50 ) ;
break;
case V_51 :
V_10 = F_5 ( V_52 ) ;
break;
case V_53 :
V_10 = F_5 ( V_54 ) ;
break;
case V_55 :
V_10 = F_5 ( V_56 ) ;
break;
case V_57 :
V_10 = F_5 ( V_58 ) ;
break;
case V_59 :
V_10 = F_5 ( V_60 ) ;
break;
case V_61 :
V_10 = F_5 ( V_62 ) ;
break;
case V_63 :
V_10 = F_5 ( V_64 ) ;
break;
case V_65 :
V_10 = F_5 ( V_66 ) ;
break;
case V_67 :
V_10 = F_5 ( V_68 ) ;
break;
case V_69 :
V_10 = F_5 ( V_70 ) ;
break;
case V_71 :
V_10 = F_5 ( V_72 ) ;
break;
case V_73 :
V_10 = F_5 ( V_74 ) ;
break;
case V_75 :
V_10 = F_5 ( V_76 ) ;
break;
case V_77 :
V_10 = F_5 ( V_78 ) ;
break;
case V_79 :
V_10 = F_5 ( V_80 ) ;
break;
case V_81 :
V_10 = F_5 ( V_82 ) ;
break;
case V_83 :
V_10 = F_5 ( V_84 ) ;
break;
case V_85 :
V_10 = F_5 ( V_86 ) ;
break;
case V_87 :
V_10 = F_5 ( V_88 ) ;
break;
case V_89 :
V_10 = F_5 ( V_90 ) ;
break;
case V_91 :
V_10 = F_5 ( V_92 ) ;
break;
case V_93 :
V_10 = F_5 ( V_94 ) ;
break;
case V_95 :
V_10 = F_5 ( V_96 ) ;
break;
case V_97 :
case V_98 :
case V_99 :
V_10 = F_5 ( V_100 ) ;
break;
case V_101 :
V_10 = F_5 ( V_102 ) ;
break;
case V_103 :
V_10 = F_5 ( V_104 ) ;
break;
case V_105 :
V_10 = F_5 ( V_106 ) ;
break;
case V_107 :
V_10 = F_5 ( V_108 ) ;
break;
case V_109 :
V_10 = F_5 ( V_110 ) ;
break;
case V_111 :
V_10 = F_5 ( V_112 ) ;
break;
case V_113 :
V_10 = F_5 ( V_114 ) ;
break;
case V_115 :
V_10 = F_5 ( V_116 ) ;
break;
case V_117 :
V_10 = F_5 ( V_118 ) ;
break;
case V_119 :
V_10 = F_5 ( V_120 ) ;
break;
case V_121 :
V_10 = F_5 ( V_122 ) ;
break;
case V_123 :
V_10 = F_5 ( V_124 ) ;
break;
case V_125 :
V_10 = F_5 ( V_126 ) ;
break;
case V_127 :
V_10 = F_5 ( V_128 ) ;
break;
case V_129 :
V_10 = F_5 ( V_130 ) ;
break;
default:
F_6 ( L_1 ) ;
return - V_131 ;
}
if ( V_10 )
return - V_7 ;
V_10 = F_7 ( & V_132 ) ;
if ( V_10 ) {
F_8 ( L_2 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
