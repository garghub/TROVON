static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , struct V_2 , V_4 ) ;
F_3 ( V_3 -> V_5 ) ;
F_4 ( V_3 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 =
F_2 ( V_7 , struct V_8 , V_10 ) ;
struct V_2 * V_11 ;
struct V_12 V_13 ;
struct V_14 V_15 ;
if ( F_6 ( V_9 -> V_16 -> V_17 , V_9 -> V_18 , & V_13 ) ) {
F_7 ( V_19 L_1 ) ;
return;
}
V_11 = F_8 ( sizeof *V_11 , V_20 ) ;
if ( ! V_11 ) {
F_7 ( V_19 L_2 ) ;
return;
}
F_9 ( & V_11 -> V_4 ) ;
V_11 -> V_21 = ( 1 << V_13 . V_22 ) - 1 ;
V_11 -> V_23 = 0 ;
if ( F_10 ( V_9 -> V_16 -> V_17 , V_9 -> V_18 ,
V_24 , & V_11 -> V_23 ) )
F_7 ( V_25 L_3 ) ;
memset ( & V_15 , 0 , sizeof V_15 ) ;
V_15 . V_26 = V_13 . V_27 ;
V_15 . V_28 = V_13 . V_29 ;
V_15 . V_18 = V_9 -> V_18 ;
V_11 -> V_5 = F_11 ( V_9 -> V_16 -> V_30 -> V_31 , & V_15 ) ;
if ( F_12 ( V_11 -> V_5 ) ) {
F_7 ( V_19 L_4 ) ;
F_4 ( V_11 ) ;
return;
}
F_13 ( & V_9 -> V_32 ) ;
if ( V_9 -> V_3 )
F_14 ( & V_9 -> V_3 -> V_4 , F_1 ) ;
V_9 -> V_3 = V_11 ;
F_15 ( & V_9 -> V_32 ) ;
}
static void F_16 ( struct V_33 * V_34 , struct V_35 * V_36 )
{
if ( V_36 -> V_36 == V_37 ||
V_36 -> V_36 == V_38 ||
V_36 -> V_36 == V_39 ||
V_36 -> V_36 == V_40 ||
V_36 -> V_36 == V_41 ||
V_36 -> V_36 == V_42 ) {
unsigned long V_43 ;
struct V_44 * V_45 =
F_2 ( V_34 , F_17 ( * V_45 ) , V_46 ) ;
struct V_8 * V_9 =
& V_45 -> V_9 [ V_36 -> V_47 . V_18 - V_45 -> V_48 ] ;
if ( F_18 ( V_34 -> V_17 , V_9 -> V_18 ) != V_49 )
return;
F_19 ( & V_9 -> V_32 , V_43 ) ;
if ( V_9 -> V_3 )
F_14 ( & V_9 -> V_3 -> V_4 , F_1 ) ;
V_9 -> V_3 = NULL ;
F_20 ( & V_9 -> V_32 , V_43 ) ;
F_21 ( V_50 , & V_45 -> V_9 [ V_36 -> V_47 . V_18 -
V_45 -> V_48 ] . V_10 ) ;
}
}
void F_22 ( struct V_51 * V_52 )
{
F_23 ( & V_52 -> V_53 , 1 ) ;
F_24 ( & V_52 -> V_54 ) ;
}
void F_25 ( struct V_51 * V_52 )
{
F_26 ( V_52 ) ;
F_27 ( & V_52 -> V_54 ) ;
}
void F_28 ( int V_55 , struct V_56 * V_57 )
{
unsigned long V_43 ;
struct V_58 * V_16 ;
struct V_59 * V_60 ;
F_19 ( & V_61 , V_43 ) ;
if ( F_29 ( & V_62 , V_55 ) != V_57 ) {
F_20 ( & V_61 , V_43 ) ;
return;
}
V_16 = V_57 -> V_9 -> V_16 ;
V_60 = V_57 -> V_60 ;
F_20 ( & V_61 , V_43 ) ;
F_30 ( V_16 , V_60 ) ;
}
static T_1 F_31 ( struct V_63 * V_17 , T_1 V_18 )
{
struct V_44 * V_45 ;
struct V_8 * V_9 ;
unsigned long V_43 ;
T_1 V_21 ;
V_45 = F_32 ( V_17 , & V_64 ) ;
if ( ! V_45 )
return 0x7f ;
V_9 = & V_45 -> V_9 [ V_18 - V_45 -> V_48 ] ;
F_19 ( & V_9 -> V_32 , V_43 ) ;
V_21 = V_9 -> V_3 ? V_9 -> V_3 -> V_21 : 0x7f ;
F_20 ( & V_9 -> V_32 , V_43 ) ;
return V_21 ;
}
int F_33 ( struct V_63 * V_17 , T_1 V_18 ,
struct V_65 * V_66 , struct V_14 * V_15 )
{
int V_67 ;
T_2 V_68 ;
int V_69 ;
memset ( V_15 , 0 , sizeof *V_15 ) ;
V_15 -> V_26 = F_34 ( V_66 -> V_26 ) ;
V_15 -> V_28 = V_66 -> V_28 ;
V_15 -> V_70 = F_34 ( V_66 -> V_71 ) &
F_31 ( V_17 , V_18 ) ;
V_15 -> V_18 = V_18 ;
V_15 -> V_72 = V_66 -> V_73 ;
V_69 = F_18 ( V_17 , V_18 ) == V_74 ;
if ( V_66 -> V_75 > 1 || V_69 ) {
V_15 -> V_76 = V_77 ;
V_15 -> V_78 . V_79 = V_66 -> V_79 ;
V_67 = F_35 ( V_17 , & V_66 -> V_80 , & V_18 ,
& V_68 ) ;
if ( V_67 )
return V_67 ;
V_15 -> V_78 . V_81 = V_68 ;
V_15 -> V_78 . V_82 = F_36 ( V_66 -> V_82 ) ;
V_15 -> V_78 . V_75 = V_66 -> V_75 ;
V_15 -> V_78 . V_83 = V_66 -> V_83 ;
}
if ( V_69 ) {
memcpy ( V_15 -> V_84 , V_66 -> V_84 , V_85 ) ;
V_15 -> V_86 = V_66 -> V_86 ;
} else {
V_15 -> V_86 = 0xffff ;
}
return 0 ;
}
static int F_37 ( struct V_56 * V_57 , T_3 V_87 )
{
unsigned long V_43 ;
F_19 ( & V_57 -> V_9 -> V_32 , V_43 ) ;
if ( ! V_57 -> V_9 -> V_3 ) {
F_20 ( & V_57 -> V_9 -> V_32 , V_43 ) ;
return - V_88 ;
}
F_38 ( & V_57 -> V_9 -> V_3 -> V_4 ) ;
V_57 -> V_3 = V_57 -> V_9 -> V_3 ;
F_20 ( & V_57 -> V_9 -> V_32 , V_43 ) ;
V_57 -> V_60 = F_39 ( V_57 -> V_9 -> V_16 , 1 ,
V_57 -> V_3 -> V_23 ,
0 , V_89 , V_90 ,
V_87 ) ;
if ( F_12 ( V_57 -> V_60 ) ) {
F_14 ( & V_57 -> V_3 -> V_4 , F_1 ) ;
return - V_91 ;
}
V_57 -> V_60 -> V_5 = V_57 -> V_3 -> V_5 ;
return 0 ;
}
static void F_40 ( struct V_56 * V_57 )
{
F_41 ( V_57 -> V_60 ) ;
F_14 ( & V_57 -> V_3 -> V_4 , F_1 ) ;
}
static void F_42 ( struct V_92 * V_93 , struct V_58 * V_16 )
{
unsigned long V_43 ;
memset ( V_93 , 0 , sizeof *V_93 ) ;
V_93 -> V_94 . V_95 = V_96 ;
V_93 -> V_94 . V_97 = V_98 ;
V_93 -> V_94 . V_99 = V_100 ;
F_19 ( & V_101 , V_43 ) ;
V_93 -> V_94 . V_102 =
F_43 ( ( ( V_103 ) V_16 -> V_104 ) << 32 | V_102 ++ ) ;
F_20 ( & V_101 , V_43 ) ;
}
static int F_44 ( struct V_56 * V_57 , int V_105 , T_3 V_87 )
{
bool V_106 = ! ! ( V_87 & V_107 ) ;
unsigned long V_43 ;
int V_67 , V_55 ;
if ( V_106 )
F_45 ( V_87 ) ;
F_19 ( & V_61 , V_43 ) ;
V_55 = F_46 ( & V_62 , V_57 , 0 , 0 , V_108 ) ;
F_20 ( & V_61 , V_43 ) ;
if ( V_106 )
F_47 () ;
if ( V_55 < 0 )
return V_55 ;
V_57 -> V_60 -> V_105 = V_105 ;
V_57 -> V_60 -> V_109 [ 0 ] = V_57 ;
V_57 -> V_55 = V_55 ;
V_67 = F_48 ( V_57 -> V_60 , NULL ) ;
if ( V_67 ) {
F_19 ( & V_61 , V_43 ) ;
F_49 ( & V_62 , V_55 ) ;
F_20 ( & V_61 , V_43 ) ;
}
return V_67 ? V_67 : V_55 ;
}
void F_50 ( void * V_110 , struct V_65 * V_66 )
{
F_51 ( V_111 , F_52 ( V_111 ) , V_110 , V_66 ) ;
}
void F_53 ( struct V_65 * V_66 , void * V_110 )
{
F_54 ( V_111 , F_52 ( V_111 ) , V_66 , V_110 ) ;
}
static void F_55 ( struct V_56 * V_112 ,
int V_113 ,
struct V_92 * V_93 )
{
struct V_114 * V_57 =
F_2 ( V_112 , struct V_114 , V_112 ) ;
if ( V_93 ) {
struct V_65 V_66 ;
F_51 ( V_111 , F_52 ( V_111 ) ,
V_93 -> V_115 , & V_66 ) ;
V_66 . V_86 = 0xffff ;
memset ( V_66 . V_84 , 0 , V_85 ) ;
memset ( V_66 . V_116 , 0 , V_85 ) ;
V_57 -> V_117 ( V_113 , & V_66 , V_57 -> V_109 ) ;
} else
V_57 -> V_117 ( V_113 , NULL , V_57 -> V_109 ) ;
}
static void F_56 ( struct V_56 * V_112 )
{
F_4 ( F_2 ( V_112 , struct V_114 , V_112 ) ) ;
}
int F_57 ( struct V_51 * V_52 ,
struct V_63 * V_17 , T_1 V_18 ,
struct V_65 * V_66 ,
T_4 V_118 ,
int V_105 , T_3 V_87 ,
void (* V_117)( int V_113 ,
struct V_65 * V_119 ,
void * V_109 ) ,
void * V_109 ,
struct V_56 * * V_112 )
{
struct V_114 * V_57 ;
struct V_44 * V_45 = F_32 ( V_17 , & V_64 ) ;
struct V_8 * V_9 ;
struct V_58 * V_16 ;
struct V_92 * V_93 ;
int V_67 ;
if ( ! V_45 )
return - V_120 ;
V_9 = & V_45 -> V_9 [ V_18 - V_45 -> V_48 ] ;
V_16 = V_9 -> V_16 ;
V_57 = F_8 ( sizeof *V_57 , V_87 ) ;
if ( ! V_57 )
return - V_91 ;
V_57 -> V_112 . V_9 = V_9 ;
V_67 = F_37 ( & V_57 -> V_112 , V_87 ) ;
if ( V_67 )
goto V_121;
F_58 ( V_52 ) ;
V_57 -> V_112 . V_52 = V_52 ;
V_57 -> V_117 = V_117 ;
V_57 -> V_109 = V_109 ;
V_93 = V_57 -> V_112 . V_60 -> V_93 ;
F_42 ( V_93 , V_16 ) ;
V_57 -> V_112 . V_117 = V_117 ? F_55 : NULL ;
V_57 -> V_112 . V_122 = F_56 ;
V_93 -> V_94 . V_123 = V_124 ;
V_93 -> V_94 . V_125 = F_59 ( V_126 ) ;
V_93 -> V_127 . V_118 = V_118 ;
F_54 ( V_111 , F_52 ( V_111 ) , V_66 , V_93 -> V_115 ) ;
* V_112 = & V_57 -> V_112 ;
V_67 = F_44 ( & V_57 -> V_112 , V_105 , V_87 ) ;
if ( V_67 < 0 )
goto V_128;
return V_67 ;
V_128:
* V_112 = NULL ;
F_26 ( V_57 -> V_112 . V_52 ) ;
F_40 ( & V_57 -> V_112 ) ;
V_121:
F_4 ( V_57 ) ;
return V_67 ;
}
static void F_60 ( struct V_56 * V_112 ,
int V_113 ,
struct V_92 * V_93 )
{
struct V_129 * V_57 =
F_2 ( V_112 , struct V_129 , V_112 ) ;
if ( V_93 ) {
struct V_130 V_66 ;
F_51 ( V_131 , F_52 ( V_131 ) ,
V_93 -> V_115 , & V_66 ) ;
V_57 -> V_117 ( V_113 , & V_66 , V_57 -> V_109 ) ;
} else
V_57 -> V_117 ( V_113 , NULL , V_57 -> V_109 ) ;
}
static void F_61 ( struct V_56 * V_112 )
{
F_4 ( F_2 ( V_112 , struct V_129 , V_112 ) ) ;
}
int F_62 ( struct V_51 * V_52 ,
struct V_63 * V_17 , T_1 V_18 , T_1 V_123 ,
struct V_130 * V_66 ,
T_4 V_118 ,
int V_105 , T_3 V_87 ,
void (* V_117)( int V_113 ,
struct V_130 * V_119 ,
void * V_109 ) ,
void * V_109 ,
struct V_56 * * V_112 )
{
struct V_129 * V_57 ;
struct V_44 * V_45 = F_32 ( V_17 , & V_64 ) ;
struct V_8 * V_9 ;
struct V_58 * V_16 ;
struct V_92 * V_93 ;
int V_67 ;
if ( ! V_45 )
return - V_120 ;
V_9 = & V_45 -> V_9 [ V_18 - V_45 -> V_48 ] ;
V_16 = V_9 -> V_16 ;
if ( V_123 != V_124 &&
V_123 != V_132 &&
V_123 != V_133 )
return - V_134 ;
V_57 = F_8 ( sizeof *V_57 , V_87 ) ;
if ( ! V_57 )
return - V_91 ;
V_57 -> V_112 . V_9 = V_9 ;
V_67 = F_37 ( & V_57 -> V_112 , V_87 ) ;
if ( V_67 )
goto V_121;
F_58 ( V_52 ) ;
V_57 -> V_112 . V_52 = V_52 ;
V_57 -> V_117 = V_117 ;
V_57 -> V_109 = V_109 ;
V_93 = V_57 -> V_112 . V_60 -> V_93 ;
F_42 ( V_93 , V_16 ) ;
V_57 -> V_112 . V_117 = V_117 ? F_60 : NULL ;
V_57 -> V_112 . V_122 = F_61 ;
V_93 -> V_94 . V_123 = V_123 ;
V_93 -> V_94 . V_125 = F_59 ( V_135 ) ;
V_93 -> V_127 . V_118 = V_118 ;
F_54 ( V_131 , F_52 ( V_131 ) ,
V_66 , V_93 -> V_115 ) ;
* V_112 = & V_57 -> V_112 ;
V_67 = F_44 ( & V_57 -> V_112 , V_105 , V_87 ) ;
if ( V_67 < 0 )
goto V_128;
return V_67 ;
V_128:
* V_112 = NULL ;
F_26 ( V_57 -> V_112 . V_52 ) ;
F_40 ( & V_57 -> V_112 ) ;
V_121:
F_4 ( V_57 ) ;
return V_67 ;
}
static void F_63 ( struct V_56 * V_112 ,
int V_113 ,
struct V_92 * V_93 )
{
struct V_136 * V_57 =
F_2 ( V_112 , struct V_136 , V_112 ) ;
if ( V_93 ) {
struct V_137 V_66 ;
F_51 ( V_138 , F_52 ( V_138 ) ,
V_93 -> V_115 , & V_66 ) ;
V_57 -> V_117 ( V_113 , & V_66 , V_57 -> V_109 ) ;
} else
V_57 -> V_117 ( V_113 , NULL , V_57 -> V_109 ) ;
}
static void F_64 ( struct V_56 * V_112 )
{
F_4 ( F_2 ( V_112 , struct V_136 , V_112 ) ) ;
}
int F_65 ( struct V_51 * V_52 ,
struct V_63 * V_17 , T_1 V_18 ,
T_1 V_123 ,
struct V_137 * V_66 ,
T_4 V_118 ,
int V_105 , T_3 V_87 ,
void (* V_117)( int V_113 ,
struct V_137 * V_119 ,
void * V_109 ) ,
void * V_109 ,
struct V_56 * * V_112 )
{
struct V_136 * V_57 ;
struct V_44 * V_45 = F_32 ( V_17 , & V_64 ) ;
struct V_8 * V_9 ;
struct V_58 * V_16 ;
struct V_92 * V_93 ;
int V_67 ;
if ( ! V_45 )
return - V_120 ;
V_9 = & V_45 -> V_9 [ V_18 - V_45 -> V_48 ] ;
V_16 = V_9 -> V_16 ;
V_57 = F_8 ( sizeof *V_57 , V_87 ) ;
if ( ! V_57 )
return - V_91 ;
V_57 -> V_112 . V_9 = V_9 ;
V_67 = F_37 ( & V_57 -> V_112 , V_87 ) ;
if ( V_67 )
goto V_121;
F_58 ( V_52 ) ;
V_57 -> V_112 . V_52 = V_52 ;
V_57 -> V_117 = V_117 ;
V_57 -> V_109 = V_109 ;
V_93 = V_57 -> V_112 . V_60 -> V_93 ;
F_42 ( V_93 , V_16 ) ;
V_57 -> V_112 . V_117 = V_117 ? F_63 : NULL ;
V_57 -> V_112 . V_122 = F_64 ;
V_93 -> V_94 . V_123 = V_123 ;
V_93 -> V_94 . V_125 = F_59 ( V_139 ) ;
V_93 -> V_127 . V_118 = V_118 ;
F_54 ( V_138 , F_52 ( V_138 ) ,
V_66 , V_93 -> V_115 ) ;
* V_112 = & V_57 -> V_112 ;
V_67 = F_44 ( & V_57 -> V_112 , V_105 , V_87 ) ;
if ( V_67 < 0 )
goto V_128;
return V_67 ;
V_128:
* V_112 = NULL ;
F_26 ( V_57 -> V_112 . V_52 ) ;
F_40 ( & V_57 -> V_112 ) ;
V_121:
F_4 ( V_57 ) ;
return V_67 ;
}
static void F_66 ( struct V_56 * V_112 ,
int V_113 ,
struct V_92 * V_93 )
{
struct V_140 * V_57 =
F_2 ( V_112 , struct V_140 , V_112 ) ;
if ( V_93 ) {
struct V_141 V_66 ;
F_51 ( V_142 , F_52 ( V_142 ) ,
V_93 -> V_115 , & V_66 ) ;
V_57 -> V_117 ( V_113 , & V_66 , V_57 -> V_109 ) ;
} else
V_57 -> V_117 ( V_113 , NULL , V_57 -> V_109 ) ;
}
static void F_67 ( struct V_56 * V_112 )
{
F_4 ( F_2 ( V_112 , struct V_140 , V_112 ) ) ;
}
int F_68 ( struct V_51 * V_52 ,
struct V_63 * V_17 , T_1 V_18 ,
struct V_141 * V_66 ,
T_4 V_118 , T_1 V_123 ,
int V_105 , T_3 V_87 ,
void (* V_117)( int V_113 ,
struct V_141 * V_119 ,
void * V_109 ) ,
void * V_109 ,
struct V_56 * * V_112 )
{
struct V_140 * V_57 ;
struct V_44 * V_45 = F_32 ( V_17 , & V_64 ) ;
struct V_8 * V_9 ;
struct V_58 * V_16 ;
struct V_92 * V_93 ;
int V_67 ;
if ( ! V_45 )
return - V_120 ;
if ( V_123 != V_124 &&
V_123 != V_132 &&
V_123 != V_133 ) {
return - V_134 ;
}
V_9 = & V_45 -> V_9 [ V_18 - V_45 -> V_48 ] ;
V_16 = V_9 -> V_16 ;
V_57 = F_8 ( sizeof *V_57 , V_87 ) ;
if ( ! V_57 )
return - V_91 ;
V_57 -> V_112 . V_9 = V_9 ;
V_67 = F_37 ( & V_57 -> V_112 , V_87 ) ;
if ( V_67 )
goto V_121;
F_58 ( V_52 ) ;
V_57 -> V_112 . V_52 = V_52 ;
V_57 -> V_117 = V_117 ;
V_57 -> V_109 = V_109 ;
V_93 = V_57 -> V_112 . V_60 -> V_93 ;
F_42 ( V_93 , V_16 ) ;
V_57 -> V_112 . V_117 = V_117 ? F_66 : NULL ;
V_57 -> V_112 . V_122 = F_67 ;
V_93 -> V_94 . V_123 = V_123 ;
V_93 -> V_94 . V_125 = F_59 ( V_143 ) ;
V_93 -> V_127 . V_118 = V_118 ;
F_54 ( V_142 , F_52 ( V_142 ) , V_66 ,
V_93 -> V_115 ) ;
* V_112 = & V_57 -> V_112 ;
V_67 = F_44 ( & V_57 -> V_112 , V_105 , V_87 ) ;
if ( V_67 < 0 )
goto V_128;
return V_67 ;
V_128:
* V_112 = NULL ;
F_26 ( V_57 -> V_112 . V_52 ) ;
F_40 ( & V_57 -> V_112 ) ;
V_121:
F_4 ( V_57 ) ;
return V_67 ;
}
static void F_69 ( struct V_58 * V_16 ,
struct V_144 * V_145 )
{
struct V_56 * V_57 = V_145 -> V_146 -> V_109 [ 0 ] ;
unsigned long V_43 ;
if ( V_57 -> V_117 )
switch ( V_145 -> V_113 ) {
case V_147 :
break;
case V_148 :
V_57 -> V_117 ( V_57 , - V_149 , NULL ) ;
break;
case V_150 :
V_57 -> V_117 ( V_57 , - V_151 , NULL ) ;
break;
default:
V_57 -> V_117 ( V_57 , - V_152 , NULL ) ;
break;
}
F_19 ( & V_61 , V_43 ) ;
F_49 ( & V_62 , V_57 -> V_55 ) ;
F_20 ( & V_61 , V_43 ) ;
F_40 ( V_57 ) ;
F_26 ( V_57 -> V_52 ) ;
V_57 -> V_122 ( V_57 ) ;
}
static void F_70 ( struct V_58 * V_153 ,
struct V_154 * V_155 )
{
struct V_56 * V_57 ;
struct V_59 * V_60 ;
V_60 = ( void * ) ( unsigned long ) V_155 -> V_156 -> V_157 ;
V_57 = V_60 -> V_109 [ 0 ] ;
if ( V_57 -> V_117 ) {
if ( V_155 -> V_156 -> V_113 == V_147 )
V_57 -> V_117 ( V_57 ,
V_155 -> V_158 . V_93 -> V_94 . V_113 ?
- V_134 : 0 ,
(struct V_92 * ) V_155 -> V_158 . V_93 ) ;
else
V_57 -> V_117 ( V_57 , - V_152 , NULL ) ;
}
F_71 ( V_155 ) ;
}
static void F_72 ( struct V_63 * V_17 )
{
struct V_44 * V_45 ;
int V_159 , V_160 , V_161 ;
if ( F_73 ( V_17 -> V_162 ) != V_163 )
return;
if ( V_17 -> V_162 == V_164 )
V_159 = V_160 = 0 ;
else {
V_159 = 1 ;
V_160 = V_17 -> V_165 ;
}
V_45 = F_74 ( sizeof *V_45 +
( V_160 - V_159 + 1 ) * sizeof ( struct V_8 ) ,
V_20 ) ;
if ( ! V_45 )
return;
V_45 -> V_48 = V_159 ;
V_45 -> V_166 = V_160 ;
for ( V_161 = 0 ; V_161 <= V_160 - V_159 ; ++ V_161 ) {
F_75 ( & V_45 -> V_9 [ V_161 ] . V_32 ) ;
if ( F_18 ( V_17 , V_161 + 1 ) != V_49 )
continue;
V_45 -> V_9 [ V_161 ] . V_3 = NULL ;
V_45 -> V_9 [ V_161 ] . V_18 = V_161 + V_159 ;
V_45 -> V_9 [ V_161 ] . V_16 =
F_76 ( V_17 , V_161 + V_159 , V_167 ,
NULL , 0 , F_69 ,
F_70 , V_45 , 0 ) ;
if ( F_12 ( V_45 -> V_9 [ V_161 ] . V_16 ) )
goto V_168;
F_77 ( & V_45 -> V_9 [ V_161 ] . V_10 , F_5 ) ;
}
F_78 ( V_17 , & V_64 , V_45 ) ;
F_79 ( & V_45 -> V_46 , V_17 , F_16 ) ;
if ( F_80 ( & V_45 -> V_46 ) )
goto V_168;
for ( V_161 = 0 ; V_161 <= V_160 - V_159 ; ++ V_161 )
if ( F_18 ( V_17 , V_161 + 1 ) == V_49 )
F_5 ( & V_45 -> V_9 [ V_161 ] . V_10 ) ;
return;
V_168:
while ( -- V_161 >= 0 )
if ( F_18 ( V_17 , V_161 + 1 ) == V_49 )
F_81 ( V_45 -> V_9 [ V_161 ] . V_16 ) ;
F_4 ( V_45 ) ;
return;
}
static void F_82 ( struct V_63 * V_17 )
{
struct V_44 * V_45 = F_32 ( V_17 , & V_64 ) ;
int V_161 ;
if ( ! V_45 )
return;
F_83 ( & V_45 -> V_46 ) ;
F_84 ( V_50 ) ;
for ( V_161 = 0 ; V_161 <= V_45 -> V_166 - V_45 -> V_48 ; ++ V_161 ) {
if ( F_18 ( V_17 , V_161 + 1 ) == V_49 ) {
F_81 ( V_45 -> V_9 [ V_161 ] . V_16 ) ;
if ( V_45 -> V_9 [ V_161 ] . V_3 )
F_14 ( & V_45 -> V_9 [ V_161 ] . V_3 -> V_4 , F_1 ) ;
}
}
F_4 ( V_45 ) ;
}
static int T_5 F_85 ( void )
{
int V_67 ;
F_86 ( & V_102 , sizeof V_102 ) ;
V_67 = F_87 ( & V_64 ) ;
if ( V_67 ) {
F_7 ( V_25 L_5 ) ;
goto V_121;
}
V_67 = F_88 () ;
if ( V_67 ) {
F_7 ( V_25 L_6 ) ;
goto V_128;
}
return 0 ;
V_128:
F_89 ( & V_64 ) ;
V_121:
return V_67 ;
}
static void T_6 F_90 ( void )
{
F_91 () ;
F_89 ( & V_64 ) ;
F_92 ( & V_62 ) ;
}
