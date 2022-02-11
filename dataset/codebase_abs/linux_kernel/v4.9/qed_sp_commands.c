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
default:
return V_36 ;
}
}
static void
F_8 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_45 * V_46 )
{
unsigned long V_47 = V_2 -> V_48 -> V_49 ;
unsigned long V_50 = V_44 -> V_51 ;
unsigned long V_49 = V_44 -> V_49 ;
unsigned long V_52 = 0 ;
if ( F_9 ( V_53 , & V_50 ) ) {
if ( F_9 ( V_53 , & V_49 ) )
F_10 ( V_53 , & V_52 ) ;
} else {
if ( F_9 ( V_53 , & V_47 ) )
F_10 ( V_53 , & V_52 ) ;
}
if ( F_9 ( V_54 , & V_50 ) ) {
if ( F_9 ( V_54 , & V_49 ) )
F_10 ( V_54 , & V_52 ) ;
} else {
if ( F_9 ( V_54 , & V_47 ) )
F_10 ( V_54 , & V_52 ) ;
}
if ( F_9 ( V_55 , & V_50 ) ) {
if ( F_9 ( V_55 , & V_49 ) )
F_10 ( V_55 , & V_52 ) ;
} else {
if ( F_9 ( V_55 , & V_47 ) )
F_10 ( V_55 , & V_52 ) ;
}
if ( V_44 -> V_56 ) {
V_46 -> V_57 = 1 ;
V_46 -> V_58 =
F_11 ( V_44 -> V_58 ) ;
}
if ( F_9 ( V_59 , & V_50 ) ) {
if ( F_9 ( V_59 , & V_49 ) )
F_10 ( V_59 , & V_52 ) ;
} else {
if ( F_9 ( V_59 , & V_47 ) )
F_10 ( V_59 , & V_52 ) ;
}
if ( F_9 ( V_60 , & V_50 ) ) {
if ( F_9 ( V_60 , & V_49 ) )
F_10 ( V_60 , & V_52 ) ;
} else {
if ( F_9 ( V_60 , & V_47 ) )
F_10 ( V_60 , & V_52 ) ;
}
V_44 -> V_49 = V_52 ;
}
static void
F_12 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_45 * V_46 )
{
unsigned long V_49 = V_44 -> V_49 ;
enum V_34 type ;
F_8 ( V_2 , V_44 , V_46 ) ;
V_46 -> V_61 = V_44 -> V_61 ;
V_46 -> V_62 = V_44 -> V_62 ;
type = F_7 ( V_44 -> V_63 ) ;
V_46 -> V_64 = type ;
type = F_7 ( V_44 -> V_65 ) ;
V_46 -> V_66 = type ;
type = F_7 ( V_44 -> V_67 ) ;
V_46 -> V_68 = type ;
if ( V_44 -> V_69 ) {
V_46 -> V_70 = 1 ;
V_46 -> V_71 = F_11 ( V_44 -> V_71 ) ;
}
if ( F_9 ( V_53 , & V_49 ) )
V_46 -> V_72 = 1 ;
if ( F_9 ( V_54 , & V_49 ) )
V_46 -> V_73 = 1 ;
if ( F_9 ( V_55 , & V_49 ) )
V_46 -> V_74 = 1 ;
if ( V_44 -> V_56 ) {
V_46 -> V_57 = 1 ;
V_46 -> V_58 =
F_11 ( V_44 -> V_58 ) ;
}
if ( F_9 ( V_59 , & V_49 ) )
V_46 -> V_75 = 1 ;
if ( F_9 ( V_60 , & V_49 ) )
V_46 -> V_76 = 1 ;
type = F_7 ( V_44 -> V_77 ) ;
V_46 -> V_78 = type ;
type = F_7 ( V_44 -> V_79 ) ;
V_46 -> V_80 = type ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_81 * V_82 ,
unsigned long V_49 )
{
T_1 V_83 = 0 , V_84 = 0 , V_85 = 0 ;
T_1 V_86 = 0 , V_87 = 0 ;
if ( F_9 ( V_53 , & V_49 ) )
V_83 = 1 ;
if ( F_9 ( V_54 , & V_49 ) )
V_84 = 1 ;
if ( F_9 ( V_55 , & V_49 ) )
V_85 = 1 ;
F_14 ( V_2 , V_82 , V_83 , V_84 ) ;
F_15 ( V_2 , V_82 , V_85 ) ;
if ( F_9 ( V_59 , & V_49 ) )
V_86 = 1 ;
if ( F_9 ( V_60 , & V_49 ) )
V_87 = 1 ;
F_16 ( V_2 , V_82 , V_86 ,
V_87 ) ;
}
static void
F_17 ( struct V_1 * V_2 ,
struct V_88 * V_44 ,
struct V_89 * V_46 )
{
unsigned long V_49 ;
enum V_34 type ;
if ( ! V_44 )
return;
V_49 = V_44 -> V_49 ;
type = F_7 ( V_44 -> V_63 ) ;
V_46 -> V_64 = type ;
type = F_7 ( V_44 -> V_65 ) ;
V_46 -> V_66 = type ;
type = F_7 ( V_44 -> V_67 ) ;
V_46 -> V_68 = type ;
if ( V_44 -> V_69 ) {
V_46 -> V_70 = 1 ;
V_46 -> V_71 = F_11 ( V_44 -> V_71 ) ;
}
if ( F_9 ( V_53 , & V_49 ) )
V_46 -> V_72 = 1 ;
if ( F_9 ( V_54 , & V_49 ) )
V_46 -> V_73 = 1 ;
if ( F_9 ( V_55 , & V_49 ) )
V_46 -> V_74 = 1 ;
if ( V_44 -> V_56 ) {
V_46 -> V_57 = 1 ;
V_46 -> V_58 =
F_11 ( V_44 -> V_58 ) ;
}
if ( F_9 ( V_59 , & V_49 ) )
V_46 -> V_75 = 1 ;
if ( F_9 ( V_60 , & V_49 ) )
V_46 -> V_76 = 1 ;
type = F_7 ( V_44 -> V_77 ) ;
V_46 -> V_78 = type ;
type = F_7 ( V_44 -> V_79 ) ;
V_46 -> V_80 = type ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_88 * V_90 ,
enum V_91 V_92 , bool V_93 )
{
struct V_94 * V_95 = NULL ;
T_3 V_96 = F_19 ( V_2 ) ;
T_1 V_97 = V_2 -> V_98 -> V_99 ;
struct V_3 * V_12 = NULL ;
struct V_7 V_100 ;
int V_13 = - V_29 ;
T_1 V_101 ;
F_20 ( V_2 ,
F_21 ( & V_2 -> V_98 -> V_102 ) ) ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_11 = F_22 ( V_2 ) ;
V_100 . V_10 = V_2 -> V_103 . V_10 ;
V_100 . V_21 = V_24 ;
V_13 = F_1 ( V_2 , & V_12 ,
V_104 ,
V_105 , & V_100 ) ;
if ( V_13 )
return V_13 ;
V_95 = & V_12 -> V_33 . V_106 ;
V_95 -> V_107 = F_11 ( V_96 ) ;
V_95 -> V_108 = V_97 ;
V_95 -> V_109 = F_23 ( V_2 ) ;
V_95 -> V_110 = 0 ;
V_95 -> V_111 = F_11 ( 0xf ) ;
switch ( V_92 ) {
case V_112 :
case V_113 :
V_95 -> V_114 = V_115 ;
break;
case V_116 :
V_95 -> V_114 = V_117 ;
break;
default:
F_4 ( V_2 , L_6 ) ;
V_95 -> V_114 = V_115 ;
}
V_95 -> V_118 = V_2 -> V_103 . V_119 ;
F_24 ( V_95 -> V_120 ,
V_2 -> V_98 -> V_102 . V_121 . V_122 ) ;
V_101 = ( T_1 ) F_25 ( & V_2 -> V_98 -> V_102 ) ;
V_95 -> V_123 = V_101 ;
F_24 ( V_95 -> V_124 ,
V_2 -> V_125 -> V_102 . V_121 . V_122 ) ;
F_17 ( V_2 , V_90 , & V_95 -> V_126 ) ;
if ( F_26 ( V_2 ) )
V_95 -> V_127 = V_93 ;
switch ( V_2 -> V_103 . V_128 ) {
case V_129 :
V_95 -> V_128 = V_130 ;
break;
case V_131 :
V_95 -> V_128 = V_132 ;
break;
case V_133 :
V_95 -> V_128 = V_134 ;
break;
default:
F_4 ( V_2 , L_7 ,
V_2 -> V_103 . V_128 ) ;
V_95 -> V_128 = V_130 ;
}
if ( V_2 -> V_48 -> V_135 ) {
struct V_136 * V_137 = V_2 -> V_48 -> V_135 ;
V_95 -> V_138 = ( T_1 ) V_137 -> V_139 ;
V_95 -> V_140 = ( T_1 ) V_137 -> V_141 ;
}
V_95 -> V_142 . V_143 [ V_144 ] = V_145 ;
V_95 -> V_142 . V_146 [ V_144 ] = V_147 ;
F_5 ( V_2 , V_32 ,
L_8 ,
V_96 , V_97 , V_95 -> V_118 ) ;
V_13 = F_27 ( V_2 , V_12 , NULL ) ;
if ( V_90 ) {
F_13 ( V_2 , V_2 -> V_148 ,
V_90 -> V_49 ) ;
V_2 -> V_48 -> V_49 = V_90 -> V_49 ;
}
return V_13 ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_12 = NULL ;
struct V_7 V_100 ;
int V_13 = - V_29 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_11 = F_22 ( V_2 ) ;
V_100 . V_10 = V_2 -> V_103 . V_10 ;
V_100 . V_21 = V_30 ;
V_13 = F_1 ( V_2 , & V_12 ,
V_149 , V_105 ,
& V_100 ) ;
if ( V_13 )
return V_13 ;
F_29 ( & V_2 -> V_150 -> V_151 ,
& V_12 -> V_33 . V_152 ) ;
return F_27 ( V_2 , V_12 , NULL ) ;
}
int F_30 ( struct V_1 * V_2 ,
struct V_43 * V_90 ,
enum V_153 V_21 ,
struct V_154 * V_28 )
{
struct V_3 * V_12 = NULL ;
struct V_7 V_100 ;
int V_13 = - V_29 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_11 = F_22 ( V_2 ) ;
V_100 . V_10 = V_2 -> V_103 . V_10 ;
V_100 . V_21 = V_21 ;
V_100 . V_28 = V_28 ;
V_13 = F_1 ( V_2 , & V_12 ,
V_149 , V_105 ,
& V_100 ) ;
if ( V_13 )
return V_13 ;
F_12 ( V_2 , V_90 ,
& V_12 -> V_33 . V_152 . V_126 ) ;
V_13 = F_27 ( V_2 , V_12 , NULL ) ;
if ( V_13 )
return V_13 ;
if ( V_90 -> V_69 )
F_31 ( V_2 , V_2 -> V_148 ,
V_90 -> V_71 ) ;
if ( V_90 -> V_56 )
F_32 ( V_2 , V_2 -> V_148 ,
V_90 -> V_58 ) ;
F_13 ( V_2 , V_2 -> V_148 , V_90 -> V_49 ) ;
V_2 -> V_48 -> V_49 = V_90 -> V_49 ;
return V_13 ;
}
int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_12 = NULL ;
struct V_7 V_100 ;
int V_13 = - V_29 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_11 = F_22 ( V_2 ) ;
V_100 . V_10 = V_2 -> V_103 . V_10 ;
V_100 . V_21 = V_24 ;
V_13 = F_1 ( V_2 , & V_12 ,
V_155 , V_105 ,
& V_100 ) ;
if ( V_13 )
return V_13 ;
return F_27 ( V_2 , V_12 , NULL ) ;
}
int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_12 = NULL ;
struct V_7 V_100 ;
int V_13 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_11 = F_22 ( V_2 ) ;
V_100 . V_10 = V_2 -> V_103 . V_10 ;
V_100 . V_21 = V_24 ;
V_13 = F_1 ( V_2 , & V_12 ,
V_156 , V_105 ,
& V_100 ) ;
if ( V_13 )
return V_13 ;
return F_27 ( V_2 , V_12 , NULL ) ;
}
