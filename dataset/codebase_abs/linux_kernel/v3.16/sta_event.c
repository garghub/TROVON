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
F_4 ( V_2 -> V_5 -> V_10 ) )
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = 0 ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_21 . V_22 = false ;
V_2 -> V_21 . V_23 = false ;
V_2 -> V_24 = 0 ;
V_2 -> V_21 . V_25 = false ;
V_2 -> V_26 = 0 ;
V_2 -> V_21 . V_27 = false ;
V_2 -> V_21 . V_28 = 0 ;
V_2 -> V_29 = true ;
V_2 -> V_30 = 0 ;
if ( V_2 -> V_31 == V_32 ) {
V_2 -> V_33 = V_34 ;
V_2 -> V_35 = false ;
}
F_2 ( V_5 -> V_7 , L_2 ,
V_2 -> V_36 . V_37 , V_2 -> V_36 . V_38 ) ;
F_2 ( V_5 -> V_7 , L_3 ,
V_2 -> V_39 . V_40 . V_37 . V_37 ,
V_2 -> V_39 . V_40 . V_37 . V_38 ) ;
memcpy ( & V_2 -> V_36 ,
& V_2 -> V_39 . V_40 . V_37 ,
sizeof( struct V_41 ) ) ;
memcpy ( V_2 -> V_42 ,
V_2 -> V_39 . V_40 . V_43 , V_44 ) ;
memset ( & V_2 -> V_39 , 0x00 , sizeof( V_2 -> V_39 ) ) ;
V_5 -> V_45 = false ;
V_5 -> V_46 = false ;
if ( V_5 -> V_47 && V_5 -> V_48 )
return;
V_2 -> V_6 = false ;
F_2 ( V_5 -> V_7 ,
L_4 ,
V_2 -> V_49 , V_3 ) ;
if ( V_2 -> V_31 == V_50 ||
V_2 -> V_31 == V_51 ) {
F_7 ( V_2 -> V_52 , V_3 , NULL , 0 ,
V_53 ) ;
}
memset ( V_2 -> V_49 , 0 , V_44 ) ;
F_8 ( V_2 -> V_52 , V_5 ) ;
if ( F_9 ( V_2 -> V_52 ) )
F_10 ( V_2 -> V_52 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
int V_56 = 0 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_57 * V_58 ;
struct V_59 * V_60 =
( void * ) V_55 -> V_61 + sizeof( V_5 -> V_62 ) ;
if ( V_55 -> V_63 < ( sizeof( struct V_59 ) -
sizeof( T_1 ) - sizeof( V_5 -> V_62 ) ) ) {
F_12 ( V_5 -> V_7 , L_5 ) ;
return - 1 ;
}
V_58 = F_13 ( V_2 , V_60 -> V_64 ) ;
if ( ! V_58 ) {
F_12 ( V_5 -> V_7 , L_6 ) ;
return - 1 ;
}
switch ( F_14 ( V_60 -> type ) ) {
case V_65 :
F_15 ( V_2 -> V_52 ,
V_60 -> V_64 ,
V_66 ,
F_14 ( V_60 -> V_67 . V_3 ) ,
V_53 ) ;
V_56 = F_16 ( V_2 , V_60 -> V_64 ,
V_68 ) ;
F_17 ( V_5 -> V_69 , & V_5 -> V_70 ) ;
break;
default:
break;
}
return V_56 ;
}
int F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_56 = 0 ;
T_2 V_71 = V_5 -> V_62 ;
T_1 V_72 , V_3 ;
switch ( V_71 ) {
case V_73 :
F_12 ( V_5 -> V_7 ,
L_7 ) ;
break;
case V_74 :
F_2 ( V_5 -> V_7 , L_8 ) ;
if ( ! F_9 ( V_2 -> V_52 ) )
F_19 ( V_2 -> V_52 ) ;
F_20 ( V_2 -> V_52 , V_5 ) ;
break;
case V_75 :
F_2 ( V_5 -> V_7 , L_9 ) ;
if ( V_2 -> V_76 . V_77 ) {
F_2 ( V_5 -> V_7 ,
L_10 ) ;
break;
}
V_5 -> V_78 . V_79 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_14 ( * ( V_80 * ) V_5 -> V_81 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_82 :
F_2 ( V_5 -> V_7 , L_11 ) ;
if ( V_2 -> V_76 . V_77 ) {
F_2 ( V_5 -> V_7 ,
L_12 ) ;
break;
}
V_5 -> V_78 . V_83 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_14 ( * ( V_80 * ) V_5 -> V_81 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_84 :
F_2 ( V_5 -> V_7 , L_13 ) ;
V_5 -> V_78 . V_85 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_14 ( * ( V_80 * ) V_5 -> V_81 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_86 :
F_2 ( V_5 -> V_7 , L_14 ) ;
V_5 -> V_87 = V_88 ;
F_21 ( V_5 ) ;
break;
case V_89 :
F_2 ( V_5 -> V_7 , L_15 ) ;
if ( ! V_5 -> V_46 &&
V_2 -> V_6 && V_5 -> V_90 . V_91 ) {
V_5 -> V_46 = true ;
F_2 ( V_5 -> V_7 ,
L_16 ) ;
}
V_5 -> V_45 = false ;
if ( V_5 -> V_46 && V_5 -> V_92 ) {
if ( F_22 ( V_2 ) ) {
if ( V_5 -> V_93 ) {
V_5 -> V_87 = V_94 ;
V_5 -> V_95 = false ;
V_5 -> V_96 = false ;
break;
}
if ( ! F_23
( V_2 ,
V_97 |
V_98 ) )
V_5 -> V_87 =
V_99 ;
return 0 ;
}
}
V_5 -> V_87 = V_94 ;
V_5 -> V_95 = false ;
V_5 -> V_96 = false ;
break;
case V_100 :
V_5 -> V_101 . V_102 ( V_5 ) ;
F_2 ( V_5 -> V_7 , L_17 ) ;
if ( V_5 -> V_103 )
V_5 -> V_103 = false ;
break;
case V_104 :
F_2 ( V_5 -> V_7 , L_18 ) ;
V_56 = F_24 ( V_2 , V_105 ,
0 , 0 , NULL , false ) ;
break;
case V_106 :
F_2 ( V_5 -> V_7 , L_19 ) ;
F_25 ( V_2 -> V_52 , V_2 -> V_49 ,
V_107 ,
- 1 , NULL , V_53 ) ;
break;
case V_108 :
F_2 ( V_5 -> V_7 , L_20 ) ;
F_25 ( V_2 -> V_52 , V_2 -> V_49 ,
V_109 ,
- 1 , NULL , V_53 ) ;
break;
case V_110 :
case V_111 :
break;
case V_112 :
F_2 ( V_5 -> V_7 , L_21 ) ;
V_2 -> V_35 = false ;
F_6 ( V_2 ) ;
F_8 ( V_2 -> V_52 , V_5 ) ;
if ( F_9 ( V_2 -> V_52 ) )
F_10 ( V_2 -> V_52 ) ;
break;
case V_113 :
F_2 ( V_5 -> V_7 , L_22 ) ;
V_56 = F_24 ( V_2 , V_114 ,
V_115 , 0 , NULL , false ) ;
break;
case V_116 :
F_2 ( V_5 -> V_7 , L_23 ) ;
break;
case V_117 :
F_2 ( V_5 -> V_7 , L_24 ) ;
if ( V_5 -> V_118 )
V_56 = F_26 ( V_2 ,
V_5 -> V_55 -> V_61 ) ;
break;
case V_119 :
F_2 ( V_5 -> V_7 , L_25 ) ;
V_56 = F_24 ( V_2 , V_120 ,
0 , 0 , NULL , false ) ;
break;
case V_121 :
F_27 ( V_2 -> V_52 ,
V_122 ,
V_53 ) ;
F_24 ( V_2 , V_123 ,
V_115 , 0 , NULL , false ) ;
V_2 -> V_124 = V_125 ;
F_2 ( V_5 -> V_7 , L_26 ) ;
break;
case V_126 :
F_2 ( V_5 -> V_7 , L_27 ) ;
break;
case V_127 :
F_2 ( V_5 -> V_7 , L_28 ) ;
break;
case V_128 :
F_27 ( V_2 -> V_52 ,
V_129 ,
V_53 ) ;
F_24 ( V_2 , V_123 ,
V_115 , 0 , NULL , false ) ;
V_2 -> V_124 = V_130 ;
F_2 ( V_5 -> V_7 , L_29 ) ;
break;
case V_131 :
F_2 ( V_5 -> V_7 , L_30 ) ;
break;
case V_132 :
F_2 ( V_5 -> V_7 , L_31 ) ;
break;
case V_133 :
F_2 ( V_5 -> V_7 , L_32 ) ;
break;
case V_134 :
F_2 ( V_5 -> V_7 , L_33 ) ;
break;
case V_135 :
F_2 ( V_5 -> V_7 , L_34 ) ;
break;
case V_136 :
F_2 ( V_5 -> V_7 , L_35 ) ;
break;
case V_137 :
F_2 ( V_5 -> V_7 , L_36 ) ;
break;
case V_138 :
F_2 ( V_5 -> V_7 , L_37 ) ;
V_56 = F_24 ( V_2 ,
V_139 ,
V_115 , 0 , NULL , false ) ;
break;
case V_140 :
F_2 ( V_5 -> V_7 , L_38 ) ;
F_24 ( V_2 , V_141 ,
V_142 , 0 ,
V_5 -> V_81 , false ) ;
break;
case V_143 :
F_2 ( V_5 -> V_7 , L_39 ) ;
F_28 ( V_2 , V_5 -> V_81 ) ;
break;
case V_144 :
F_2 ( V_5 -> V_7 , L_40 ) ;
F_29 ( V_2 ,
(struct V_145
* )
V_5 -> V_81 ) ;
break;
case V_146 :
V_72 = F_14 ( * ( V_80 * ) V_5 -> V_81 ) ;
F_2 ( V_5 -> V_7 , L_41 , V_72 ) ;
V_5 -> V_147 =
F_30 ( T_1 , V_5 -> V_148 , V_72 ) ;
F_2 ( V_5 -> V_7 , L_42 ,
V_5 -> V_147 ) ;
break;
case V_149 :
F_2 ( V_5 -> V_7 , L_43 ) ;
break;
case V_150 :
F_2 ( V_5 -> V_7 , L_44 ) ;
break;
case V_151 :
F_2 ( V_5 -> V_7 , L_45 , V_71 ) ;
break;
case V_152 :
F_2 ( V_5 -> V_7 , L_46 ) ;
F_31 ( V_2 -> V_153 ,
V_2 -> V_154 . V_155 ,
& V_2 -> V_154 . V_156 ,
V_157 ) ;
memset ( & V_2 -> V_154 , 0x00 , sizeof( struct V_158 ) ) ;
break;
case V_159 :
F_2 ( V_5 -> V_7 , L_47 ) ;
V_2 -> V_160 =
V_161 + F_32 ( V_162 ) ;
V_2 -> V_163 = V_2 -> V_39 . V_40 . V_164 ;
V_56 = F_24 ( V_2 , V_165 ,
V_142 , 0 ,
V_2 -> V_39 . V_40 . V_43 ,
false ) ;
break;
case V_166 :
V_56 = F_11 ( V_2 , V_5 -> V_55 ) ;
break;
default:
F_2 ( V_5 -> V_7 , L_48 ,
V_71 ) ;
break;
}
return V_56 ;
}
