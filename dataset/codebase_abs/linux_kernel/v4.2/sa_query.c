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
if ( ! F_18 ( V_34 -> V_17 , V_9 -> V_18 ) )
return;
F_19 ( & V_9 -> V_32 , V_43 ) ;
if ( V_9 -> V_3 )
F_14 ( & V_9 -> V_3 -> V_4 , F_1 ) ;
V_9 -> V_3 = NULL ;
F_20 ( & V_9 -> V_32 , V_43 ) ;
F_21 ( V_49 , & V_45 -> V_9 [ V_36 -> V_47 . V_18 -
V_45 -> V_48 ] . V_10 ) ;
}
}
void F_22 ( struct V_50 * V_51 )
{
F_23 ( & V_51 -> V_52 , 1 ) ;
F_24 ( & V_51 -> V_53 ) ;
}
void F_25 ( struct V_50 * V_51 )
{
F_26 ( V_51 ) ;
F_27 ( & V_51 -> V_53 ) ;
}
void F_28 ( int V_54 , struct V_55 * V_56 )
{
unsigned long V_43 ;
struct V_57 * V_16 ;
struct V_58 * V_59 ;
F_19 ( & V_60 , V_43 ) ;
if ( F_29 ( & V_61 , V_54 ) != V_56 ) {
F_20 ( & V_60 , V_43 ) ;
return;
}
V_16 = V_56 -> V_9 -> V_16 ;
V_59 = V_56 -> V_59 ;
F_20 ( & V_60 , V_43 ) ;
F_30 ( V_16 , V_59 ) ;
}
static T_1 F_31 ( struct V_62 * V_17 , T_1 V_18 )
{
struct V_44 * V_45 ;
struct V_8 * V_9 ;
unsigned long V_43 ;
T_1 V_21 ;
V_45 = F_32 ( V_17 , & V_63 ) ;
if ( ! V_45 )
return 0x7f ;
V_9 = & V_45 -> V_9 [ V_18 - V_45 -> V_48 ] ;
F_19 ( & V_9 -> V_32 , V_43 ) ;
V_21 = V_9 -> V_3 ? V_9 -> V_3 -> V_21 : 0x7f ;
F_20 ( & V_9 -> V_32 , V_43 ) ;
return V_21 ;
}
int F_33 ( struct V_62 * V_17 , T_1 V_18 ,
struct V_64 * V_65 , struct V_14 * V_15 )
{
int V_66 ;
T_2 V_67 ;
int V_68 ;
memset ( V_15 , 0 , sizeof *V_15 ) ;
V_15 -> V_26 = F_34 ( V_65 -> V_26 ) ;
V_15 -> V_28 = V_65 -> V_28 ;
V_15 -> V_69 = F_34 ( V_65 -> V_70 ) &
F_31 ( V_17 , V_18 ) ;
V_15 -> V_18 = V_18 ;
V_15 -> V_71 = V_65 -> V_72 ;
V_68 = F_35 ( V_17 , V_18 ) ;
if ( V_65 -> V_73 > 1 || V_68 ) {
V_15 -> V_74 = V_75 ;
V_15 -> V_76 . V_77 = V_65 -> V_77 ;
V_66 = F_36 ( V_17 , & V_65 -> V_78 , & V_18 ,
& V_67 ) ;
if ( V_66 )
return V_66 ;
V_15 -> V_76 . V_79 = V_67 ;
V_15 -> V_76 . V_80 = F_37 ( V_65 -> V_80 ) ;
V_15 -> V_76 . V_73 = V_65 -> V_73 ;
V_15 -> V_76 . V_81 = V_65 -> V_81 ;
}
if ( V_68 ) {
memcpy ( V_15 -> V_82 , V_65 -> V_82 , V_83 ) ;
V_15 -> V_84 = V_65 -> V_84 ;
} else {
V_15 -> V_84 = 0xffff ;
}
return 0 ;
}
static int F_38 ( struct V_55 * V_56 , T_3 V_85 )
{
unsigned long V_43 ;
F_19 ( & V_56 -> V_9 -> V_32 , V_43 ) ;
if ( ! V_56 -> V_9 -> V_3 ) {
F_20 ( & V_56 -> V_9 -> V_32 , V_43 ) ;
return - V_86 ;
}
F_39 ( & V_56 -> V_9 -> V_3 -> V_4 ) ;
V_56 -> V_3 = V_56 -> V_9 -> V_3 ;
F_20 ( & V_56 -> V_9 -> V_32 , V_43 ) ;
V_56 -> V_59 = F_40 ( V_56 -> V_9 -> V_16 , 1 ,
V_56 -> V_3 -> V_23 ,
0 , V_87 , V_88 ,
V_85 ,
V_89 ) ;
if ( F_12 ( V_56 -> V_59 ) ) {
F_14 ( & V_56 -> V_3 -> V_4 , F_1 ) ;
return - V_90 ;
}
V_56 -> V_59 -> V_5 = V_56 -> V_3 -> V_5 ;
return 0 ;
}
static void F_41 ( struct V_55 * V_56 )
{
F_42 ( V_56 -> V_59 ) ;
F_14 ( & V_56 -> V_3 -> V_4 , F_1 ) ;
}
static void F_43 ( struct V_91 * V_92 , struct V_57 * V_16 )
{
unsigned long V_43 ;
memset ( V_92 , 0 , sizeof *V_92 ) ;
V_92 -> V_93 . V_94 = V_89 ;
V_92 -> V_93 . V_95 = V_96 ;
V_92 -> V_93 . V_97 = V_98 ;
F_19 ( & V_99 , V_43 ) ;
V_92 -> V_93 . V_100 =
F_44 ( ( ( V_101 ) V_16 -> V_102 ) << 32 | V_100 ++ ) ;
F_20 ( & V_99 , V_43 ) ;
}
static int F_45 ( struct V_55 * V_56 , int V_103 , T_3 V_85 )
{
bool V_104 = ! ! ( V_85 & V_105 ) ;
unsigned long V_43 ;
int V_66 , V_54 ;
if ( V_104 )
F_46 ( V_85 ) ;
F_19 ( & V_60 , V_43 ) ;
V_54 = F_47 ( & V_61 , V_56 , 0 , 0 , V_106 ) ;
F_20 ( & V_60 , V_43 ) ;
if ( V_104 )
F_48 () ;
if ( V_54 < 0 )
return V_54 ;
V_56 -> V_59 -> V_103 = V_103 ;
V_56 -> V_59 -> V_107 [ 0 ] = V_56 ;
V_56 -> V_54 = V_54 ;
V_66 = F_49 ( V_56 -> V_59 , NULL ) ;
if ( V_66 ) {
F_19 ( & V_60 , V_43 ) ;
F_50 ( & V_61 , V_54 ) ;
F_20 ( & V_60 , V_43 ) ;
}
return V_66 ? V_66 : V_54 ;
}
void F_51 ( void * V_108 , struct V_64 * V_65 )
{
F_52 ( V_109 , F_53 ( V_109 ) , V_108 , V_65 ) ;
}
void F_54 ( struct V_64 * V_65 , void * V_108 )
{
F_55 ( V_109 , F_53 ( V_109 ) , V_65 , V_108 ) ;
}
static void F_56 ( struct V_55 * V_110 ,
int V_111 ,
struct V_91 * V_92 )
{
struct V_112 * V_56 =
F_2 ( V_110 , struct V_112 , V_110 ) ;
if ( V_92 ) {
struct V_64 V_65 ;
F_52 ( V_109 , F_53 ( V_109 ) ,
V_92 -> V_113 , & V_65 ) ;
V_65 . V_84 = 0xffff ;
memset ( V_65 . V_82 , 0 , V_83 ) ;
memset ( V_65 . V_114 , 0 , V_83 ) ;
V_56 -> V_115 ( V_111 , & V_65 , V_56 -> V_107 ) ;
} else
V_56 -> V_115 ( V_111 , NULL , V_56 -> V_107 ) ;
}
static void F_57 ( struct V_55 * V_110 )
{
F_4 ( F_2 ( V_110 , struct V_112 , V_110 ) ) ;
}
int F_58 ( struct V_50 * V_51 ,
struct V_62 * V_17 , T_1 V_18 ,
struct V_64 * V_65 ,
T_4 V_116 ,
int V_103 , T_3 V_85 ,
void (* V_115)( int V_111 ,
struct V_64 * V_117 ,
void * V_107 ) ,
void * V_107 ,
struct V_55 * * V_110 )
{
struct V_112 * V_56 ;
struct V_44 * V_45 = F_32 ( V_17 , & V_63 ) ;
struct V_8 * V_9 ;
struct V_57 * V_16 ;
struct V_91 * V_92 ;
int V_66 ;
if ( ! V_45 )
return - V_118 ;
V_9 = & V_45 -> V_9 [ V_18 - V_45 -> V_48 ] ;
V_16 = V_9 -> V_16 ;
V_56 = F_8 ( sizeof *V_56 , V_85 ) ;
if ( ! V_56 )
return - V_90 ;
V_56 -> V_110 . V_9 = V_9 ;
V_66 = F_38 ( & V_56 -> V_110 , V_85 ) ;
if ( V_66 )
goto V_119;
F_59 ( V_51 ) ;
V_56 -> V_110 . V_51 = V_51 ;
V_56 -> V_115 = V_115 ;
V_56 -> V_107 = V_107 ;
V_92 = V_56 -> V_110 . V_59 -> V_92 ;
F_43 ( V_92 , V_16 ) ;
V_56 -> V_110 . V_115 = V_115 ? F_56 : NULL ;
V_56 -> V_110 . V_120 = F_57 ;
V_92 -> V_93 . V_121 = V_122 ;
V_92 -> V_93 . V_123 = F_60 ( V_124 ) ;
V_92 -> V_125 . V_116 = V_116 ;
F_55 ( V_109 , F_53 ( V_109 ) , V_65 , V_92 -> V_113 ) ;
* V_110 = & V_56 -> V_110 ;
V_66 = F_45 ( & V_56 -> V_110 , V_103 , V_85 ) ;
if ( V_66 < 0 )
goto V_126;
return V_66 ;
V_126:
* V_110 = NULL ;
F_26 ( V_56 -> V_110 . V_51 ) ;
F_41 ( & V_56 -> V_110 ) ;
V_119:
F_4 ( V_56 ) ;
return V_66 ;
}
static void F_61 ( struct V_55 * V_110 ,
int V_111 ,
struct V_91 * V_92 )
{
struct V_127 * V_56 =
F_2 ( V_110 , struct V_127 , V_110 ) ;
if ( V_92 ) {
struct V_128 V_65 ;
F_52 ( V_129 , F_53 ( V_129 ) ,
V_92 -> V_113 , & V_65 ) ;
V_56 -> V_115 ( V_111 , & V_65 , V_56 -> V_107 ) ;
} else
V_56 -> V_115 ( V_111 , NULL , V_56 -> V_107 ) ;
}
static void F_62 ( struct V_55 * V_110 )
{
F_4 ( F_2 ( V_110 , struct V_127 , V_110 ) ) ;
}
int F_63 ( struct V_50 * V_51 ,
struct V_62 * V_17 , T_1 V_18 , T_1 V_121 ,
struct V_128 * V_65 ,
T_4 V_116 ,
int V_103 , T_3 V_85 ,
void (* V_115)( int V_111 ,
struct V_128 * V_117 ,
void * V_107 ) ,
void * V_107 ,
struct V_55 * * V_110 )
{
struct V_127 * V_56 ;
struct V_44 * V_45 = F_32 ( V_17 , & V_63 ) ;
struct V_8 * V_9 ;
struct V_57 * V_16 ;
struct V_91 * V_92 ;
int V_66 ;
if ( ! V_45 )
return - V_118 ;
V_9 = & V_45 -> V_9 [ V_18 - V_45 -> V_48 ] ;
V_16 = V_9 -> V_16 ;
if ( V_121 != V_122 &&
V_121 != V_130 &&
V_121 != V_131 )
return - V_132 ;
V_56 = F_8 ( sizeof *V_56 , V_85 ) ;
if ( ! V_56 )
return - V_90 ;
V_56 -> V_110 . V_9 = V_9 ;
V_66 = F_38 ( & V_56 -> V_110 , V_85 ) ;
if ( V_66 )
goto V_119;
F_59 ( V_51 ) ;
V_56 -> V_110 . V_51 = V_51 ;
V_56 -> V_115 = V_115 ;
V_56 -> V_107 = V_107 ;
V_92 = V_56 -> V_110 . V_59 -> V_92 ;
F_43 ( V_92 , V_16 ) ;
V_56 -> V_110 . V_115 = V_115 ? F_61 : NULL ;
V_56 -> V_110 . V_120 = F_62 ;
V_92 -> V_93 . V_121 = V_121 ;
V_92 -> V_93 . V_123 = F_60 ( V_133 ) ;
V_92 -> V_125 . V_116 = V_116 ;
F_55 ( V_129 , F_53 ( V_129 ) ,
V_65 , V_92 -> V_113 ) ;
* V_110 = & V_56 -> V_110 ;
V_66 = F_45 ( & V_56 -> V_110 , V_103 , V_85 ) ;
if ( V_66 < 0 )
goto V_126;
return V_66 ;
V_126:
* V_110 = NULL ;
F_26 ( V_56 -> V_110 . V_51 ) ;
F_41 ( & V_56 -> V_110 ) ;
V_119:
F_4 ( V_56 ) ;
return V_66 ;
}
static void F_64 ( struct V_55 * V_110 ,
int V_111 ,
struct V_91 * V_92 )
{
struct V_134 * V_56 =
F_2 ( V_110 , struct V_134 , V_110 ) ;
if ( V_92 ) {
struct V_135 V_65 ;
F_52 ( V_136 , F_53 ( V_136 ) ,
V_92 -> V_113 , & V_65 ) ;
V_56 -> V_115 ( V_111 , & V_65 , V_56 -> V_107 ) ;
} else
V_56 -> V_115 ( V_111 , NULL , V_56 -> V_107 ) ;
}
static void F_65 ( struct V_55 * V_110 )
{
F_4 ( F_2 ( V_110 , struct V_134 , V_110 ) ) ;
}
int F_66 ( struct V_50 * V_51 ,
struct V_62 * V_17 , T_1 V_18 ,
T_1 V_121 ,
struct V_135 * V_65 ,
T_4 V_116 ,
int V_103 , T_3 V_85 ,
void (* V_115)( int V_111 ,
struct V_135 * V_117 ,
void * V_107 ) ,
void * V_107 ,
struct V_55 * * V_110 )
{
struct V_134 * V_56 ;
struct V_44 * V_45 = F_32 ( V_17 , & V_63 ) ;
struct V_8 * V_9 ;
struct V_57 * V_16 ;
struct V_91 * V_92 ;
int V_66 ;
if ( ! V_45 )
return - V_118 ;
V_9 = & V_45 -> V_9 [ V_18 - V_45 -> V_48 ] ;
V_16 = V_9 -> V_16 ;
V_56 = F_8 ( sizeof *V_56 , V_85 ) ;
if ( ! V_56 )
return - V_90 ;
V_56 -> V_110 . V_9 = V_9 ;
V_66 = F_38 ( & V_56 -> V_110 , V_85 ) ;
if ( V_66 )
goto V_119;
F_59 ( V_51 ) ;
V_56 -> V_110 . V_51 = V_51 ;
V_56 -> V_115 = V_115 ;
V_56 -> V_107 = V_107 ;
V_92 = V_56 -> V_110 . V_59 -> V_92 ;
F_43 ( V_92 , V_16 ) ;
V_56 -> V_110 . V_115 = V_115 ? F_64 : NULL ;
V_56 -> V_110 . V_120 = F_65 ;
V_92 -> V_93 . V_121 = V_121 ;
V_92 -> V_93 . V_123 = F_60 ( V_137 ) ;
V_92 -> V_125 . V_116 = V_116 ;
F_55 ( V_136 , F_53 ( V_136 ) ,
V_65 , V_92 -> V_113 ) ;
* V_110 = & V_56 -> V_110 ;
V_66 = F_45 ( & V_56 -> V_110 , V_103 , V_85 ) ;
if ( V_66 < 0 )
goto V_126;
return V_66 ;
V_126:
* V_110 = NULL ;
F_26 ( V_56 -> V_110 . V_51 ) ;
F_41 ( & V_56 -> V_110 ) ;
V_119:
F_4 ( V_56 ) ;
return V_66 ;
}
static void F_67 ( struct V_55 * V_110 ,
int V_111 ,
struct V_91 * V_92 )
{
struct V_138 * V_56 =
F_2 ( V_110 , struct V_138 , V_110 ) ;
if ( V_92 ) {
struct V_139 V_65 ;
F_52 ( V_140 , F_53 ( V_140 ) ,
V_92 -> V_113 , & V_65 ) ;
V_56 -> V_115 ( V_111 , & V_65 , V_56 -> V_107 ) ;
} else
V_56 -> V_115 ( V_111 , NULL , V_56 -> V_107 ) ;
}
static void F_68 ( struct V_55 * V_110 )
{
F_4 ( F_2 ( V_110 , struct V_138 , V_110 ) ) ;
}
int F_69 ( struct V_50 * V_51 ,
struct V_62 * V_17 , T_1 V_18 ,
struct V_139 * V_65 ,
T_4 V_116 , T_1 V_121 ,
int V_103 , T_3 V_85 ,
void (* V_115)( int V_111 ,
struct V_139 * V_117 ,
void * V_107 ) ,
void * V_107 ,
struct V_55 * * V_110 )
{
struct V_138 * V_56 ;
struct V_44 * V_45 = F_32 ( V_17 , & V_63 ) ;
struct V_8 * V_9 ;
struct V_57 * V_16 ;
struct V_91 * V_92 ;
int V_66 ;
if ( ! V_45 )
return - V_118 ;
if ( V_121 != V_122 &&
V_121 != V_130 &&
V_121 != V_131 ) {
return - V_132 ;
}
V_9 = & V_45 -> V_9 [ V_18 - V_45 -> V_48 ] ;
V_16 = V_9 -> V_16 ;
V_56 = F_8 ( sizeof *V_56 , V_85 ) ;
if ( ! V_56 )
return - V_90 ;
V_56 -> V_110 . V_9 = V_9 ;
V_66 = F_38 ( & V_56 -> V_110 , V_85 ) ;
if ( V_66 )
goto V_119;
F_59 ( V_51 ) ;
V_56 -> V_110 . V_51 = V_51 ;
V_56 -> V_115 = V_115 ;
V_56 -> V_107 = V_107 ;
V_92 = V_56 -> V_110 . V_59 -> V_92 ;
F_43 ( V_92 , V_16 ) ;
V_56 -> V_110 . V_115 = V_115 ? F_67 : NULL ;
V_56 -> V_110 . V_120 = F_68 ;
V_92 -> V_93 . V_121 = V_121 ;
V_92 -> V_93 . V_123 = F_60 ( V_141 ) ;
V_92 -> V_125 . V_116 = V_116 ;
F_55 ( V_140 , F_53 ( V_140 ) , V_65 ,
V_92 -> V_113 ) ;
* V_110 = & V_56 -> V_110 ;
V_66 = F_45 ( & V_56 -> V_110 , V_103 , V_85 ) ;
if ( V_66 < 0 )
goto V_126;
return V_66 ;
V_126:
* V_110 = NULL ;
F_26 ( V_56 -> V_110 . V_51 ) ;
F_41 ( & V_56 -> V_110 ) ;
V_119:
F_4 ( V_56 ) ;
return V_66 ;
}
static void F_70 ( struct V_57 * V_16 ,
struct V_142 * V_143 )
{
struct V_55 * V_56 = V_143 -> V_144 -> V_107 [ 0 ] ;
unsigned long V_43 ;
if ( V_56 -> V_115 )
switch ( V_143 -> V_111 ) {
case V_145 :
break;
case V_146 :
V_56 -> V_115 ( V_56 , - V_147 , NULL ) ;
break;
case V_148 :
V_56 -> V_115 ( V_56 , - V_149 , NULL ) ;
break;
default:
V_56 -> V_115 ( V_56 , - V_150 , NULL ) ;
break;
}
F_19 ( & V_60 , V_43 ) ;
F_50 ( & V_61 , V_56 -> V_54 ) ;
F_20 ( & V_60 , V_43 ) ;
F_41 ( V_56 ) ;
F_26 ( V_56 -> V_51 ) ;
V_56 -> V_120 ( V_56 ) ;
}
static void F_71 ( struct V_57 * V_151 ,
struct V_152 * V_153 )
{
struct V_55 * V_56 ;
struct V_58 * V_59 ;
V_59 = ( void * ) ( unsigned long ) V_153 -> V_154 -> V_155 ;
V_56 = V_59 -> V_107 [ 0 ] ;
if ( V_56 -> V_115 ) {
if ( V_153 -> V_154 -> V_111 == V_145 )
V_56 -> V_115 ( V_56 ,
V_153 -> V_156 . V_92 -> V_93 . V_111 ?
- V_132 : 0 ,
(struct V_91 * ) V_153 -> V_156 . V_92 ) ;
else
V_56 -> V_115 ( V_56 , - V_150 , NULL ) ;
}
F_72 ( V_153 ) ;
}
static void F_73 ( struct V_62 * V_17 )
{
struct V_44 * V_45 ;
int V_157 , V_158 , V_159 ;
int V_160 = 0 ;
V_157 = F_74 ( V_17 ) ;
V_158 = F_75 ( V_17 ) ;
V_45 = F_76 ( sizeof *V_45 +
( V_158 - V_157 + 1 ) * sizeof ( struct V_8 ) ,
V_20 ) ;
if ( ! V_45 )
return;
V_45 -> V_48 = V_157 ;
V_45 -> V_161 = V_158 ;
for ( V_159 = 0 ; V_159 <= V_158 - V_157 ; ++ V_159 ) {
F_77 ( & V_45 -> V_9 [ V_159 ] . V_32 ) ;
if ( ! F_18 ( V_17 , V_159 + 1 ) )
continue;
V_45 -> V_9 [ V_159 ] . V_3 = NULL ;
V_45 -> V_9 [ V_159 ] . V_18 = V_159 + V_157 ;
V_45 -> V_9 [ V_159 ] . V_16 =
F_78 ( V_17 , V_159 + V_157 , V_162 ,
NULL , 0 , F_70 ,
F_71 , V_45 , 0 ) ;
if ( F_12 ( V_45 -> V_9 [ V_159 ] . V_16 ) )
goto V_163;
F_79 ( & V_45 -> V_9 [ V_159 ] . V_10 , F_5 ) ;
V_160 ++ ;
}
if ( ! V_160 )
goto free;
F_80 ( V_17 , & V_63 , V_45 ) ;
F_81 ( & V_45 -> V_46 , V_17 , F_16 ) ;
if ( F_82 ( & V_45 -> V_46 ) )
goto V_163;
for ( V_159 = 0 ; V_159 <= V_158 - V_157 ; ++ V_159 ) {
if ( F_18 ( V_17 , V_159 + 1 ) )
F_5 ( & V_45 -> V_9 [ V_159 ] . V_10 ) ;
}
return;
V_163:
while ( -- V_159 >= 0 ) {
if ( F_18 ( V_17 , V_159 + 1 ) )
F_83 ( V_45 -> V_9 [ V_159 ] . V_16 ) ;
}
free:
F_4 ( V_45 ) ;
return;
}
static void F_84 ( struct V_62 * V_17 )
{
struct V_44 * V_45 = F_32 ( V_17 , & V_63 ) ;
int V_159 ;
if ( ! V_45 )
return;
F_85 ( & V_45 -> V_46 ) ;
F_86 ( V_49 ) ;
for ( V_159 = 0 ; V_159 <= V_45 -> V_161 - V_45 -> V_48 ; ++ V_159 ) {
if ( F_18 ( V_17 , V_159 + 1 ) ) {
F_83 ( V_45 -> V_9 [ V_159 ] . V_16 ) ;
if ( V_45 -> V_9 [ V_159 ] . V_3 )
F_14 ( & V_45 -> V_9 [ V_159 ] . V_3 -> V_4 , F_1 ) ;
}
}
F_4 ( V_45 ) ;
}
static int T_5 F_87 ( void )
{
int V_66 ;
F_88 ( & V_100 , sizeof V_100 ) ;
V_66 = F_89 ( & V_63 ) ;
if ( V_66 ) {
F_7 ( V_25 L_5 ) ;
goto V_119;
}
V_66 = F_90 () ;
if ( V_66 ) {
F_7 ( V_25 L_6 ) ;
goto V_126;
}
return 0 ;
V_126:
F_91 ( & V_63 ) ;
V_119:
return V_66 ;
}
static void T_6 F_92 ( void )
{
F_93 () ;
F_91 ( & V_63 ) ;
F_94 ( & V_61 ) ;
}
