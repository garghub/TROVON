void
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( ! V_2 -> V_6 )
return;
F_2 ( V_5 -> V_7 , L_1 ) ;
V_2 -> V_6 = false ;
V_2 -> V_8 = false ;
if ( ( F_3 ( V_2 ) == V_9 ) &&
F_4 ( V_2 -> V_5 -> V_10 ) ) {
F_5 ( V_2 ) ;
if ( V_2 -> V_5 -> V_11 )
F_6 ( V_2 ) ;
}
F_7 ( V_2 ) ;
V_2 -> V_12 = 0 ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_22 . V_23 = false ;
V_2 -> V_22 . V_24 = false ;
V_2 -> V_25 = 0 ;
V_2 -> V_22 . V_26 = false ;
V_2 -> V_27 = 0 ;
V_2 -> V_22 . V_28 = false ;
V_2 -> V_22 . V_29 = 0 ;
V_2 -> V_30 = true ;
V_2 -> V_31 = 0 ;
if ( V_2 -> V_32 == V_33 ) {
V_2 -> V_34 = V_35 ;
V_2 -> V_36 = false ;
}
F_2 ( V_5 -> V_7 , L_2 ,
V_2 -> V_37 . V_38 , V_2 -> V_37 . V_39 ) ;
F_2 ( V_5 -> V_7 , L_3 ,
V_2 -> V_40 . V_41 . V_38 . V_38 ,
V_2 -> V_40 . V_41 . V_38 . V_39 ) ;
memcpy ( & V_2 -> V_37 ,
& V_2 -> V_40 . V_41 . V_38 ,
sizeof( struct V_42 ) ) ;
memcpy ( V_2 -> V_43 ,
V_2 -> V_40 . V_41 . V_44 , V_45 ) ;
memset ( & V_2 -> V_40 , 0x00 , sizeof( V_2 -> V_40 ) ) ;
V_5 -> V_46 = false ;
V_5 -> V_47 = false ;
if ( V_5 -> V_48 && V_5 -> V_49 )
return;
V_2 -> V_6 = false ;
F_2 ( V_5 -> V_7 ,
L_4 ,
V_2 -> V_50 , V_3 ) ;
if ( V_2 -> V_32 == V_51 ||
V_2 -> V_32 == V_52 ) {
F_8 ( V_2 -> V_53 , V_3 , NULL , 0 ,
V_54 ) ;
}
memset ( V_2 -> V_50 , 0 , V_45 ) ;
F_9 ( V_2 -> V_53 , V_5 ) ;
if ( F_10 ( V_2 -> V_53 ) )
F_11 ( V_2 -> V_53 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
int V_57 = 0 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_58 * V_59 ;
struct V_60 * V_61 =
( void * ) V_56 -> V_62 + sizeof( V_5 -> V_63 ) ;
if ( V_56 -> V_64 < ( sizeof( struct V_60 ) -
sizeof( T_1 ) - sizeof( V_5 -> V_63 ) ) ) {
F_13 ( V_5 -> V_7 , L_5 ) ;
return - 1 ;
}
V_59 = F_14 ( V_2 , V_61 -> V_65 ) ;
if ( ! V_59 ) {
F_13 ( V_5 -> V_7 , L_6 ) ;
return - 1 ;
}
switch ( F_15 ( V_61 -> type ) ) {
case V_66 :
F_16 ( V_2 -> V_53 ,
V_61 -> V_65 ,
V_67 ,
F_15 ( V_61 -> V_68 . V_3 ) ,
V_54 ) ;
break;
default:
break;
}
return V_57 ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_57 = 0 ;
T_2 V_69 = V_5 -> V_63 ;
T_1 V_70 , V_3 ;
switch ( V_69 ) {
case V_71 :
F_13 ( V_5 -> V_7 ,
L_7 ) ;
break;
case V_72 :
F_2 ( V_5 -> V_7 , L_8 ) ;
if ( ! F_10 ( V_2 -> V_53 ) )
F_18 ( V_2 -> V_53 ) ;
F_19 ( V_2 -> V_53 , V_5 ) ;
break;
case V_73 :
F_2 ( V_5 -> V_7 , L_9 ) ;
if ( V_2 -> V_74 . V_75 ) {
F_2 ( V_5 -> V_7 ,
L_10 ) ;
break;
}
V_5 -> V_76 . V_77 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_15 ( * ( V_78 * ) V_5 -> V_79 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_80 :
F_2 ( V_5 -> V_7 , L_11 ) ;
if ( V_2 -> V_74 . V_75 ) {
F_2 ( V_5 -> V_7 ,
L_12 ) ;
break;
}
V_5 -> V_76 . V_81 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_15 ( * ( V_78 * ) V_5 -> V_79 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_82 :
F_2 ( V_5 -> V_7 , L_13 ) ;
V_5 -> V_76 . V_83 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_15 ( * ( V_78 * ) V_5 -> V_79 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_84 :
F_2 ( V_5 -> V_7 , L_14 ) ;
V_5 -> V_85 = V_86 ;
F_20 ( V_5 ) ;
break;
case V_87 :
F_2 ( V_5 -> V_7 , L_15 ) ;
if ( ! V_5 -> V_47 &&
V_2 -> V_6 && V_5 -> V_88 . V_89 ) {
V_5 -> V_47 = true ;
F_2 ( V_5 -> V_7 ,
L_16 ) ;
}
V_5 -> V_46 = false ;
if ( V_5 -> V_47 && V_5 -> V_90 ) {
if ( F_21 ( V_2 ) ) {
if ( V_5 -> V_91 ) {
V_5 -> V_85 = V_92 ;
V_5 -> V_93 = false ;
V_5 -> V_94 = false ;
break;
}
if ( ! F_22
( V_2 ,
V_95 |
V_96 ) )
V_5 -> V_85 =
V_97 ;
return 0 ;
}
}
V_5 -> V_85 = V_92 ;
V_5 -> V_93 = false ;
V_5 -> V_94 = false ;
break;
case V_98 :
V_5 -> V_99 . V_100 ( V_5 ) ;
F_2 ( V_5 -> V_7 , L_17 ) ;
if ( V_5 -> V_101 )
V_5 -> V_101 = false ;
break;
case V_102 :
F_2 ( V_5 -> V_7 , L_18 ) ;
V_57 = F_23 ( V_2 , V_103 ,
0 , 0 , NULL , false ) ;
break;
case V_104 :
F_2 ( V_5 -> V_7 , L_19 ) ;
F_24 ( V_2 -> V_53 , V_2 -> V_50 ,
V_105 ,
- 1 , NULL , V_54 ) ;
break;
case V_106 :
F_2 ( V_5 -> V_7 , L_20 ) ;
F_24 ( V_2 -> V_53 , V_2 -> V_50 ,
V_107 ,
- 1 , NULL , V_54 ) ;
break;
case V_108 :
case V_109 :
break;
case V_110 :
F_2 ( V_5 -> V_7 , L_21 ) ;
V_2 -> V_36 = false ;
F_7 ( V_2 ) ;
F_9 ( V_2 -> V_53 , V_5 ) ;
if ( F_10 ( V_2 -> V_53 ) )
F_11 ( V_2 -> V_53 ) ;
break;
case V_111 :
F_2 ( V_5 -> V_7 , L_22 ) ;
V_57 = F_23 ( V_2 , V_112 ,
V_113 , 0 , NULL , false ) ;
break;
case V_114 :
F_2 ( V_5 -> V_7 , L_23 ) ;
break;
case V_115 :
F_2 ( V_5 -> V_7 , L_24 ) ;
if ( V_5 -> V_116 )
V_57 = F_25 ( V_2 ,
V_5 -> V_56 -> V_62 ) ;
break;
case V_117 :
F_2 ( V_5 -> V_7 , L_25 ) ;
V_57 = F_23 ( V_2 , V_118 ,
0 , 0 , NULL , false ) ;
break;
case V_119 :
F_26 ( V_2 -> V_53 ,
V_120 ,
V_54 ) ;
F_23 ( V_2 , V_121 ,
V_113 , 0 , NULL , false ) ;
V_2 -> V_122 = V_123 ;
F_2 ( V_5 -> V_7 , L_26 ) ;
break;
case V_124 :
F_2 ( V_5 -> V_7 , L_27 ) ;
break;
case V_125 :
F_2 ( V_5 -> V_7 , L_28 ) ;
break;
case V_126 :
F_26 ( V_2 -> V_53 ,
V_127 ,
V_54 ) ;
F_23 ( V_2 , V_121 ,
V_113 , 0 , NULL , false ) ;
V_2 -> V_122 = V_128 ;
F_2 ( V_5 -> V_7 , L_29 ) ;
break;
case V_129 :
F_2 ( V_5 -> V_7 , L_30 ) ;
break;
case V_130 :
F_2 ( V_5 -> V_7 , L_31 ) ;
break;
case V_131 :
F_2 ( V_5 -> V_7 , L_32 ) ;
break;
case V_132 :
F_2 ( V_5 -> V_7 , L_33 ) ;
break;
case V_133 :
F_2 ( V_5 -> V_7 , L_34 ) ;
break;
case V_134 :
F_2 ( V_5 -> V_7 , L_35 ) ;
break;
case V_135 :
F_2 ( V_5 -> V_7 , L_36 ) ;
break;
case V_136 :
F_2 ( V_5 -> V_7 , L_37 ) ;
V_57 = F_23 ( V_2 ,
V_137 ,
V_113 , 0 , NULL , false ) ;
break;
case V_138 :
F_2 ( V_5 -> V_7 , L_38 ) ;
F_23 ( V_2 , V_139 ,
V_140 , 0 ,
V_5 -> V_79 , false ) ;
break;
case V_141 :
F_2 ( V_5 -> V_7 , L_39 ) ;
F_27 ( V_2 , V_5 -> V_79 ) ;
break;
case V_142 :
F_2 ( V_5 -> V_7 , L_40 ) ;
F_28 ( V_2 ,
(struct V_143
* )
V_5 -> V_79 ) ;
break;
case V_144 :
V_70 = F_15 ( * ( V_78 * ) V_5 -> V_79 ) ;
F_2 ( V_5 -> V_7 , L_41 , V_70 ) ;
V_5 -> V_145 =
F_29 ( T_1 , V_5 -> V_146 , V_70 ) ;
F_2 ( V_5 -> V_7 , L_42 ,
V_5 -> V_145 ) ;
break;
case V_147 :
F_2 ( V_5 -> V_7 , L_43 ) ;
break;
case V_148 :
F_2 ( V_5 -> V_7 , L_44 ) ;
break;
case V_149 :
F_2 ( V_5 -> V_7 , L_45 , V_69 ) ;
break;
case V_150 :
F_2 ( V_5 -> V_7 , L_46 ) ;
F_30 ( V_2 -> V_151 ,
V_2 -> V_152 . V_153 ,
& V_2 -> V_152 . V_154 ,
V_155 ) ;
memset ( & V_2 -> V_152 , 0x00 , sizeof( struct V_156 ) ) ;
break;
case V_157 :
F_2 ( V_5 -> V_7 , L_47 ) ;
V_2 -> V_158 =
V_159 + F_31 ( V_160 ) ;
V_2 -> V_161 = V_2 -> V_40 . V_41 . V_162 ;
V_57 = F_23 ( V_2 , V_163 ,
V_140 , 0 ,
V_2 -> V_40 . V_41 . V_44 ,
false ) ;
break;
case V_164 :
V_57 = F_12 ( V_2 , V_5 -> V_56 ) ;
break;
case V_165 :
F_2 ( V_5 -> V_7 , L_48 ) ;
F_32 ( V_2 , V_5 -> V_79 ) ;
break;
default:
F_2 ( V_5 -> V_7 , L_49 ,
V_69 ) ;
break;
}
return V_57 ;
}
