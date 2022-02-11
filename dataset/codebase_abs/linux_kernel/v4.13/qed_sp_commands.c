int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
T_1 V_5 , T_1 V_6 , struct V_7 * V_8 )
{
T_2 V_9 = V_8 -> V_10 << 16 | V_8 -> V_11 ;
struct V_3 * V_12 = NULL ;
int V_13 ;
if ( ! V_4 )
return - V_14 ;
V_13 = F_2 ( V_2 , V_4 ) ;
if ( V_13 )
return V_13 ;
V_12 = * V_4 ;
V_12 -> V_15 . V_16 . V_11 = F_3 ( V_9 ) ;
V_12 -> V_15 . V_16 . V_17 = V_5 ;
V_12 -> V_15 . V_16 . V_18 = V_6 ;
V_12 -> V_19 = V_20 ;
V_12 -> V_21 = V_8 -> V_21 ;
V_12 -> V_22 . V_23 = 0 ;
switch ( V_12 -> V_21 ) {
case V_24 :
V_12 -> V_25 . V_26 = & V_12 -> V_22 ;
break;
case V_27 :
if ( ! V_8 -> V_28 )
return - V_29 ;
V_12 -> V_25 . V_26 = V_8 -> V_28 -> V_26 ;
break;
case V_30 :
if ( ! V_8 -> V_28 )
V_12 -> V_25 . V_31 = NULL ;
else
V_12 -> V_25 = * V_8 -> V_28 ;
break;
default:
F_4 ( V_2 , L_1 ,
V_12 -> V_21 ) ;
return - V_29 ;
}
F_5 ( V_2 , V_32 ,
L_2 ,
V_9 , V_5 , V_6 ,
( unsigned long ) & V_12 -> V_33 ,
F_6 ( V_12 -> V_21 , V_24 ,
V_27 , L_3 , L_4 ,
L_5 ) ) ;
memset ( & V_12 -> V_33 , 0 , sizeof( V_12 -> V_33 ) ) ;
return 0 ;
}
static enum V_34 F_7 ( T_1 type )
{
switch ( type ) {
case V_35 :
return V_36 ;
case V_37 :
return V_38 ;
case V_39 :
return V_40 ;
case V_41 :
return V_42 ;
case V_43 :
return V_44 ;
default:
return V_36 ;
}
}
static void
F_8 ( struct V_45 * V_46 ,
struct V_45 * V_47 , bool V_48 )
{
if ( V_47 -> V_49 . V_50 || V_48 )
V_46 -> V_49 . V_51 = V_47 -> V_49 . V_51 ;
if ( V_47 -> V_52 . V_50 || V_48 )
V_46 -> V_52 . V_51 = V_47 -> V_52 . V_51 ;
if ( V_47 -> V_53 . V_50 || V_48 )
V_46 -> V_53 . V_51 = V_47 -> V_53 . V_51 ;
if ( V_47 -> V_54 . V_50 || V_48 )
V_46 -> V_54 . V_51 =
V_47 -> V_54 . V_51 ;
if ( V_47 -> V_55 . V_50 || V_48 )
V_46 -> V_55 . V_51 =
V_47 -> V_55 . V_51 ;
}
static void F_9 ( struct V_45 * V_46 ,
struct V_45 * V_47 )
{
enum V_34 type ;
V_46 -> V_56 = V_47 -> V_56 ;
V_46 -> V_57 = V_47 -> V_57 ;
type = F_7 ( V_47 -> V_49 . V_58 ) ;
V_46 -> V_49 . V_58 = type ;
type = F_7 ( V_47 -> V_52 . V_58 ) ;
V_46 -> V_52 . V_58 = type ;
type = F_7 ( V_47 -> V_53 . V_58 ) ;
V_46 -> V_53 . V_58 = type ;
type = F_7 ( V_47 -> V_54 . V_58 ) ;
V_46 -> V_54 . V_58 = type ;
type = F_7 ( V_47 -> V_55 . V_58 ) ;
V_46 -> V_55 . V_58 = type ;
}
static void F_10 ( struct V_45 * V_46 ,
struct V_45 * V_47 )
{
V_46 -> V_59 . V_60 = V_47 -> V_59 . V_60 ;
V_46 -> V_61 . V_60 = V_47 -> V_61 . V_60 ;
if ( V_47 -> V_59 . V_60 )
V_46 -> V_59 . V_62 = V_47 -> V_59 . V_62 ;
if ( V_47 -> V_61 . V_60 )
V_46 -> V_61 . V_62 = V_47 -> V_61 . V_62 ;
}
static void
F_11 ( T_1 * V_63 ,
struct V_64 * V_65 )
{
* V_63 = V_65 -> V_58 ;
}
static void
F_12 ( T_1 * V_63 ,
struct V_64 * V_65 ,
T_1 * V_66 ,
T_3 * V_67 ,
struct V_68 * V_69 )
{
F_11 ( V_63 , V_65 ) ;
if ( V_69 -> V_60 ) {
* V_66 = 1 ;
* V_67 = F_13 ( V_69 -> V_62 ) ;
}
}
static void
F_14 ( struct V_1 * V_2 ,
struct V_45 * V_47 ,
struct V_70 * V_71 )
{
struct V_45 * V_46 = & V_2 -> V_72 -> V_73 ;
F_8 ( V_46 , V_47 , false ) ;
F_9 ( V_46 , V_47 ) ;
F_10 ( V_46 , V_47 ) ;
F_12 ( & V_71 -> V_74 ,
& V_46 -> V_49 ,
& V_71 -> V_75 ,
& V_71 -> V_76 ,
& V_46 -> V_61 ) ;
F_12 ( & V_71 -> V_77 ,
& V_46 -> V_54 ,
& V_71 -> V_78 ,
& V_71 -> V_79 ,
& V_46 -> V_59 ) ;
F_11 ( & V_71 -> V_80 ,
& V_46 -> V_55 ) ;
F_11 ( & V_71 -> V_81 ,
& V_46 -> V_52 ) ;
F_11 ( & V_71 -> V_82 ,
& V_46 -> V_53 ) ;
V_71 -> V_83 = V_46 -> V_56 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
struct V_45 * V_46 )
{
F_16 ( V_2 , V_85 , V_46 -> V_52 . V_51 ,
V_46 -> V_53 . V_51 ) ;
F_17 ( V_2 , V_85 , V_46 -> V_49 . V_51 ) ;
F_18 ( V_2 , V_85 , V_46 -> V_54 . V_51 ,
V_46 -> V_55 . V_51 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
struct V_45 * V_86 )
{
if ( V_86 -> V_61 . V_60 )
F_20 ( V_2 , V_85 ,
V_86 -> V_61 . V_62 ) ;
if ( V_86 -> V_59 . V_60 )
F_21 ( V_2 , V_85 ,
V_86 -> V_59 . V_62 ) ;
F_15 ( V_2 , V_85 , V_86 ) ;
}
static void
F_22 ( struct V_1 * V_2 ,
struct V_45 * V_47 ,
struct V_87 * V_71 )
{
struct V_45 * V_46 = & V_2 -> V_72 -> V_73 ;
if ( ! V_47 )
return;
F_8 ( V_46 , V_47 , true ) ;
F_9 ( V_46 , V_47 ) ;
F_10 ( V_46 , V_47 ) ;
F_12 ( & V_71 -> V_74 ,
& V_46 -> V_49 ,
& V_71 -> V_75 ,
& V_71 -> V_76 ,
& V_46 -> V_61 ) ;
F_12 ( & V_71 -> V_77 ,
& V_46 -> V_54 ,
& V_71 -> V_78 ,
& V_71 -> V_79 ,
& V_46 -> V_59 ) ;
F_11 ( & V_71 -> V_80 ,
& V_46 -> V_55 ) ;
F_11 ( & V_71 -> V_81 ,
& V_46 -> V_52 ) ;
F_11 ( & V_71 -> V_82 ,
& V_46 -> V_53 ) ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
struct V_45 * V_86 ,
enum V_88 V_89 , bool V_90 )
{
struct V_91 * V_92 = NULL ;
T_4 V_93 = F_24 ( V_2 ) ;
T_1 V_94 = V_2 -> V_95 -> V_96 ;
struct V_3 * V_12 = NULL ;
struct V_7 V_97 ;
int V_13 = - V_29 ;
T_1 V_98 ;
F_25 ( V_2 ,
F_26 ( & V_2 -> V_95 -> V_99 ) ) ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_11 = F_27 ( V_2 ) ;
V_97 . V_10 = V_2 -> V_100 . V_10 ;
V_97 . V_21 = V_24 ;
V_13 = F_1 ( V_2 , & V_12 ,
V_101 ,
V_102 , & V_97 ) ;
if ( V_13 )
return V_13 ;
V_92 = & V_12 -> V_33 . V_103 ;
V_92 -> V_104 = F_13 ( V_93 ) ;
V_92 -> V_105 = V_94 ;
V_92 -> V_106 = F_28 ( V_2 ) ;
V_92 -> V_107 = 0 ;
V_92 -> V_108 = F_13 ( 0xf ) ;
switch ( V_89 ) {
case V_109 :
case V_110 :
V_92 -> V_111 = V_112 ;
break;
case V_113 :
V_92 -> V_111 = V_114 ;
break;
default:
F_4 ( V_2 , L_6 ) ;
V_92 -> V_111 = V_112 ;
}
V_92 -> V_115 = V_2 -> V_100 . V_116 ;
F_29 ( V_92 -> V_117 ,
V_2 -> V_95 -> V_99 . V_118 . V_119 ) ;
V_98 = ( T_1 ) F_30 ( & V_2 -> V_95 -> V_99 ) ;
V_92 -> V_120 = V_98 ;
F_29 ( V_92 -> V_121 ,
V_2 -> V_122 -> V_99 . V_118 . V_119 ) ;
F_22 ( V_2 , V_86 , & V_92 -> V_123 ) ;
if ( F_31 ( V_2 ) )
V_92 -> V_124 = V_90 ;
switch ( V_2 -> V_100 . V_125 ) {
case V_126 :
V_92 -> V_125 = V_127 ;
break;
case V_128 :
V_92 -> V_125 = V_129 ;
break;
case V_130 :
V_92 -> V_125 = V_131 ;
break;
case V_132 :
V_92 -> V_125 = V_133 ;
break;
default:
F_4 ( V_2 , L_7 ,
V_2 -> V_100 . V_125 ) ;
V_92 -> V_125 = V_127 ;
}
if ( V_2 -> V_72 -> V_134 ) {
struct V_135 * V_136 = V_2 -> V_72 -> V_134 ;
V_92 -> V_137 = ( T_1 ) V_136 -> V_138 ;
V_92 -> V_139 = ( T_1 ) V_136 -> V_140 ;
}
V_92 -> V_141 . V_142 [ V_143 ] = V_144 ;
V_92 -> V_141 . V_145 [ V_143 ] = V_146 ;
F_5 ( V_2 , V_32 ,
L_8 ,
V_93 , V_94 , V_92 -> V_115 ) ;
V_13 = F_32 ( V_2 , V_12 , NULL ) ;
if ( V_86 )
F_19 ( V_2 , V_85 ,
& V_2 -> V_72 -> V_73 ) ;
return V_13 ;
}
int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_12 = NULL ;
struct V_7 V_97 ;
int V_13 = - V_29 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_11 = F_27 ( V_2 ) ;
V_97 . V_10 = V_2 -> V_100 . V_10 ;
V_97 . V_21 = V_30 ;
V_13 = F_1 ( V_2 , & V_12 ,
V_147 , V_102 ,
& V_97 ) ;
if ( V_13 )
return V_13 ;
F_34 ( & V_2 -> V_148 -> V_149 ,
& V_12 -> V_33 . V_150 ) ;
return F_32 ( V_2 , V_12 , NULL ) ;
}
int F_35 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
struct V_45 * V_86 ,
enum V_151 V_21 ,
struct V_152 * V_28 )
{
struct V_3 * V_12 = NULL ;
struct V_7 V_97 ;
int V_13 = - V_29 ;
if ( F_36 ( V_2 -> V_72 ) )
return F_37 ( V_2 , V_86 ) ;
if ( ! V_86 )
return - V_29 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_11 = F_27 ( V_2 ) ;
V_97 . V_10 = V_2 -> V_100 . V_10 ;
V_97 . V_21 = V_21 ;
V_97 . V_28 = V_28 ;
V_13 = F_1 ( V_2 , & V_12 ,
V_147 , V_102 ,
& V_97 ) ;
if ( V_13 )
return V_13 ;
F_14 ( V_2 , V_86 ,
& V_12 -> V_33 . V_150 . V_123 ) ;
V_13 = F_32 ( V_2 , V_12 , NULL ) ;
if ( V_13 )
return V_13 ;
F_19 ( V_2 , V_85 , & V_2 -> V_72 -> V_73 ) ;
return V_13 ;
}
int F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_12 = NULL ;
struct V_7 V_97 ;
int V_13 = - V_29 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_11 = F_27 ( V_2 ) ;
V_97 . V_10 = V_2 -> V_100 . V_10 ;
V_97 . V_21 = V_24 ;
V_13 = F_1 ( V_2 , & V_12 ,
V_153 , V_102 ,
& V_97 ) ;
if ( V_13 )
return V_13 ;
return F_32 ( V_2 , V_12 , NULL ) ;
}
int F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_12 = NULL ;
struct V_7 V_97 ;
int V_13 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_11 = F_27 ( V_2 ) ;
V_97 . V_10 = V_2 -> V_100 . V_10 ;
V_97 . V_21 = V_24 ;
V_13 = F_1 ( V_2 , & V_12 ,
V_154 , V_102 ,
& V_97 ) ;
if ( V_13 )
return V_13 ;
return F_32 ( V_2 , V_12 , NULL ) ;
}
int F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_12 = NULL ;
struct V_7 V_97 ;
int V_13 = - V_29 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_11 = F_27 ( V_2 ) ;
V_97 . V_10 = V_2 -> V_100 . V_10 ;
V_97 . V_21 = V_30 ;
V_13 = F_1 ( V_2 , & V_12 ,
V_147 , V_102 ,
& V_97 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_33 . V_150 . V_155 = true ;
V_12 -> V_33 . V_150 . V_156 = F_13 ( V_2 -> V_100 . V_116 ) ;
return F_32 ( V_2 , V_12 , NULL ) ;
}
