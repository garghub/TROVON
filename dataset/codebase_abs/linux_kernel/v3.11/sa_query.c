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
return 0 ;
}
static int F_37 ( struct V_56 * V_57 , T_3 V_84 )
{
unsigned long V_43 ;
F_19 ( & V_57 -> V_9 -> V_32 , V_43 ) ;
if ( ! V_57 -> V_9 -> V_3 ) {
F_20 ( & V_57 -> V_9 -> V_32 , V_43 ) ;
return - V_85 ;
}
F_38 ( & V_57 -> V_9 -> V_3 -> V_4 ) ;
V_57 -> V_3 = V_57 -> V_9 -> V_3 ;
F_20 ( & V_57 -> V_9 -> V_32 , V_43 ) ;
V_57 -> V_60 = F_39 ( V_57 -> V_9 -> V_16 , 1 ,
V_57 -> V_3 -> V_23 ,
0 , V_86 , V_87 ,
V_84 ) ;
if ( F_12 ( V_57 -> V_60 ) ) {
F_14 ( & V_57 -> V_3 -> V_4 , F_1 ) ;
return - V_88 ;
}
V_57 -> V_60 -> V_5 = V_57 -> V_3 -> V_5 ;
return 0 ;
}
static void F_40 ( struct V_56 * V_57 )
{
F_41 ( V_57 -> V_60 ) ;
F_14 ( & V_57 -> V_3 -> V_4 , F_1 ) ;
}
static void F_42 ( struct V_89 * V_90 , struct V_58 * V_16 )
{
unsigned long V_43 ;
memset ( V_90 , 0 , sizeof *V_90 ) ;
V_90 -> V_91 . V_92 = V_93 ;
V_90 -> V_91 . V_94 = V_95 ;
V_90 -> V_91 . V_96 = V_97 ;
F_19 ( & V_98 , V_43 ) ;
V_90 -> V_91 . V_99 =
F_43 ( ( ( V_100 ) V_16 -> V_101 ) << 32 | V_99 ++ ) ;
F_20 ( & V_98 , V_43 ) ;
}
static int F_44 ( struct V_56 * V_57 , int V_102 , T_3 V_84 )
{
bool V_103 = V_84 & V_104 ;
unsigned long V_43 ;
int V_67 , V_55 ;
if ( V_103 )
F_45 ( V_84 ) ;
F_19 ( & V_61 , V_43 ) ;
V_55 = F_46 ( & V_62 , V_57 , 0 , 0 , V_105 ) ;
F_20 ( & V_61 , V_43 ) ;
if ( V_103 )
F_47 () ;
if ( V_55 < 0 )
return V_55 ;
V_57 -> V_60 -> V_102 = V_102 ;
V_57 -> V_60 -> V_106 [ 0 ] = V_57 ;
V_57 -> V_55 = V_55 ;
V_67 = F_48 ( V_57 -> V_60 , NULL ) ;
if ( V_67 ) {
F_19 ( & V_61 , V_43 ) ;
F_49 ( & V_62 , V_55 ) ;
F_20 ( & V_61 , V_43 ) ;
}
return V_67 ? V_67 : V_55 ;
}
void F_50 ( void * V_107 , struct V_65 * V_66 )
{
F_51 ( V_108 , F_52 ( V_108 ) , V_107 , V_66 ) ;
}
void F_53 ( struct V_65 * V_66 , void * V_107 )
{
F_54 ( V_108 , F_52 ( V_108 ) , V_66 , V_107 ) ;
}
static void F_55 ( struct V_56 * V_109 ,
int V_110 ,
struct V_89 * V_90 )
{
struct V_111 * V_57 =
F_2 ( V_109 , struct V_111 , V_109 ) ;
if ( V_90 ) {
struct V_65 V_66 ;
F_51 ( V_108 , F_52 ( V_108 ) ,
V_90 -> V_112 , & V_66 ) ;
V_57 -> V_113 ( V_110 , & V_66 , V_57 -> V_106 ) ;
} else
V_57 -> V_113 ( V_110 , NULL , V_57 -> V_106 ) ;
}
static void F_56 ( struct V_56 * V_109 )
{
F_4 ( F_2 ( V_109 , struct V_111 , V_109 ) ) ;
}
int F_57 ( struct V_51 * V_52 ,
struct V_63 * V_17 , T_1 V_18 ,
struct V_65 * V_66 ,
T_4 V_114 ,
int V_102 , T_3 V_84 ,
void (* V_113)( int V_110 ,
struct V_65 * V_115 ,
void * V_106 ) ,
void * V_106 ,
struct V_56 * * V_109 )
{
struct V_111 * V_57 ;
struct V_44 * V_45 = F_32 ( V_17 , & V_64 ) ;
struct V_8 * V_9 ;
struct V_58 * V_16 ;
struct V_89 * V_90 ;
int V_67 ;
if ( ! V_45 )
return - V_116 ;
V_9 = & V_45 -> V_9 [ V_18 - V_45 -> V_48 ] ;
V_16 = V_9 -> V_16 ;
V_57 = F_8 ( sizeof *V_57 , V_84 ) ;
if ( ! V_57 )
return - V_88 ;
V_57 -> V_109 . V_9 = V_9 ;
V_67 = F_37 ( & V_57 -> V_109 , V_84 ) ;
if ( V_67 )
goto V_117;
F_58 ( V_52 ) ;
V_57 -> V_109 . V_52 = V_52 ;
V_57 -> V_113 = V_113 ;
V_57 -> V_106 = V_106 ;
V_90 = V_57 -> V_109 . V_60 -> V_90 ;
F_42 ( V_90 , V_16 ) ;
V_57 -> V_109 . V_113 = V_113 ? F_55 : NULL ;
V_57 -> V_109 . V_118 = F_56 ;
V_90 -> V_91 . V_119 = V_120 ;
V_90 -> V_91 . V_121 = F_59 ( V_122 ) ;
V_90 -> V_123 . V_114 = V_114 ;
F_54 ( V_108 , F_52 ( V_108 ) , V_66 , V_90 -> V_112 ) ;
* V_109 = & V_57 -> V_109 ;
V_67 = F_44 ( & V_57 -> V_109 , V_102 , V_84 ) ;
if ( V_67 < 0 )
goto V_124;
return V_67 ;
V_124:
* V_109 = NULL ;
F_26 ( V_57 -> V_109 . V_52 ) ;
F_40 ( & V_57 -> V_109 ) ;
V_117:
F_4 ( V_57 ) ;
return V_67 ;
}
static void F_60 ( struct V_56 * V_109 ,
int V_110 ,
struct V_89 * V_90 )
{
struct V_125 * V_57 =
F_2 ( V_109 , struct V_125 , V_109 ) ;
if ( V_90 ) {
struct V_126 V_66 ;
F_51 ( V_127 , F_52 ( V_127 ) ,
V_90 -> V_112 , & V_66 ) ;
V_57 -> V_113 ( V_110 , & V_66 , V_57 -> V_106 ) ;
} else
V_57 -> V_113 ( V_110 , NULL , V_57 -> V_106 ) ;
}
static void F_61 ( struct V_56 * V_109 )
{
F_4 ( F_2 ( V_109 , struct V_125 , V_109 ) ) ;
}
int F_62 ( struct V_51 * V_52 ,
struct V_63 * V_17 , T_1 V_18 , T_1 V_119 ,
struct V_126 * V_66 ,
T_4 V_114 ,
int V_102 , T_3 V_84 ,
void (* V_113)( int V_110 ,
struct V_126 * V_115 ,
void * V_106 ) ,
void * V_106 ,
struct V_56 * * V_109 )
{
struct V_125 * V_57 ;
struct V_44 * V_45 = F_32 ( V_17 , & V_64 ) ;
struct V_8 * V_9 ;
struct V_58 * V_16 ;
struct V_89 * V_90 ;
int V_67 ;
if ( ! V_45 )
return - V_116 ;
V_9 = & V_45 -> V_9 [ V_18 - V_45 -> V_48 ] ;
V_16 = V_9 -> V_16 ;
if ( V_119 != V_120 &&
V_119 != V_128 &&
V_119 != V_129 )
return - V_130 ;
V_57 = F_8 ( sizeof *V_57 , V_84 ) ;
if ( ! V_57 )
return - V_88 ;
V_57 -> V_109 . V_9 = V_9 ;
V_67 = F_37 ( & V_57 -> V_109 , V_84 ) ;
if ( V_67 )
goto V_117;
F_58 ( V_52 ) ;
V_57 -> V_109 . V_52 = V_52 ;
V_57 -> V_113 = V_113 ;
V_57 -> V_106 = V_106 ;
V_90 = V_57 -> V_109 . V_60 -> V_90 ;
F_42 ( V_90 , V_16 ) ;
V_57 -> V_109 . V_113 = V_113 ? F_60 : NULL ;
V_57 -> V_109 . V_118 = F_61 ;
V_90 -> V_91 . V_119 = V_119 ;
V_90 -> V_91 . V_121 = F_59 ( V_131 ) ;
V_90 -> V_123 . V_114 = V_114 ;
F_54 ( V_127 , F_52 ( V_127 ) ,
V_66 , V_90 -> V_112 ) ;
* V_109 = & V_57 -> V_109 ;
V_67 = F_44 ( & V_57 -> V_109 , V_102 , V_84 ) ;
if ( V_67 < 0 )
goto V_124;
return V_67 ;
V_124:
* V_109 = NULL ;
F_26 ( V_57 -> V_109 . V_52 ) ;
F_40 ( & V_57 -> V_109 ) ;
V_117:
F_4 ( V_57 ) ;
return V_67 ;
}
static void F_63 ( struct V_56 * V_109 ,
int V_110 ,
struct V_89 * V_90 )
{
struct V_132 * V_57 =
F_2 ( V_109 , struct V_132 , V_109 ) ;
if ( V_90 ) {
struct V_133 V_66 ;
F_51 ( V_134 , F_52 ( V_134 ) ,
V_90 -> V_112 , & V_66 ) ;
V_57 -> V_113 ( V_110 , & V_66 , V_57 -> V_106 ) ;
} else
V_57 -> V_113 ( V_110 , NULL , V_57 -> V_106 ) ;
}
static void F_64 ( struct V_56 * V_109 )
{
F_4 ( F_2 ( V_109 , struct V_132 , V_109 ) ) ;
}
int F_65 ( struct V_51 * V_52 ,
struct V_63 * V_17 , T_1 V_18 ,
T_1 V_119 ,
struct V_133 * V_66 ,
T_4 V_114 ,
int V_102 , T_3 V_84 ,
void (* V_113)( int V_110 ,
struct V_133 * V_115 ,
void * V_106 ) ,
void * V_106 ,
struct V_56 * * V_109 )
{
struct V_132 * V_57 ;
struct V_44 * V_45 = F_32 ( V_17 , & V_64 ) ;
struct V_8 * V_9 ;
struct V_58 * V_16 ;
struct V_89 * V_90 ;
int V_67 ;
if ( ! V_45 )
return - V_116 ;
V_9 = & V_45 -> V_9 [ V_18 - V_45 -> V_48 ] ;
V_16 = V_9 -> V_16 ;
V_57 = F_8 ( sizeof *V_57 , V_84 ) ;
if ( ! V_57 )
return - V_88 ;
V_57 -> V_109 . V_9 = V_9 ;
V_67 = F_37 ( & V_57 -> V_109 , V_84 ) ;
if ( V_67 )
goto V_117;
F_58 ( V_52 ) ;
V_57 -> V_109 . V_52 = V_52 ;
V_57 -> V_113 = V_113 ;
V_57 -> V_106 = V_106 ;
V_90 = V_57 -> V_109 . V_60 -> V_90 ;
F_42 ( V_90 , V_16 ) ;
V_57 -> V_109 . V_113 = V_113 ? F_63 : NULL ;
V_57 -> V_109 . V_118 = F_64 ;
V_90 -> V_91 . V_119 = V_119 ;
V_90 -> V_91 . V_121 = F_59 ( V_135 ) ;
V_90 -> V_123 . V_114 = V_114 ;
F_54 ( V_134 , F_52 ( V_134 ) ,
V_66 , V_90 -> V_112 ) ;
* V_109 = & V_57 -> V_109 ;
V_67 = F_44 ( & V_57 -> V_109 , V_102 , V_84 ) ;
if ( V_67 < 0 )
goto V_124;
return V_67 ;
V_124:
* V_109 = NULL ;
F_26 ( V_57 -> V_109 . V_52 ) ;
F_40 ( & V_57 -> V_109 ) ;
V_117:
F_4 ( V_57 ) ;
return V_67 ;
}
static void F_66 ( struct V_56 * V_109 ,
int V_110 ,
struct V_89 * V_90 )
{
struct V_136 * V_57 =
F_2 ( V_109 , struct V_136 , V_109 ) ;
if ( V_90 ) {
struct V_137 V_66 ;
F_51 ( V_138 , F_52 ( V_138 ) ,
V_90 -> V_112 , & V_66 ) ;
V_57 -> V_113 ( V_110 , & V_66 , V_57 -> V_106 ) ;
} else
V_57 -> V_113 ( V_110 , NULL , V_57 -> V_106 ) ;
}
static void F_67 ( struct V_56 * V_109 )
{
F_4 ( F_2 ( V_109 , struct V_136 , V_109 ) ) ;
}
int F_68 ( struct V_51 * V_52 ,
struct V_63 * V_17 , T_1 V_18 ,
struct V_137 * V_66 ,
T_4 V_114 , T_1 V_119 ,
int V_102 , T_3 V_84 ,
void (* V_113)( int V_110 ,
struct V_137 * V_115 ,
void * V_106 ) ,
void * V_106 ,
struct V_56 * * V_109 )
{
struct V_136 * V_57 ;
struct V_44 * V_45 = F_32 ( V_17 , & V_64 ) ;
struct V_8 * V_9 ;
struct V_58 * V_16 ;
struct V_89 * V_90 ;
int V_67 ;
if ( ! V_45 )
return - V_116 ;
if ( V_119 != V_120 &&
V_119 != V_128 &&
V_119 != V_129 ) {
return - V_130 ;
}
V_9 = & V_45 -> V_9 [ V_18 - V_45 -> V_48 ] ;
V_16 = V_9 -> V_16 ;
V_57 = F_8 ( sizeof *V_57 , V_84 ) ;
if ( ! V_57 )
return - V_88 ;
V_57 -> V_109 . V_9 = V_9 ;
V_67 = F_37 ( & V_57 -> V_109 , V_84 ) ;
if ( V_67 )
goto V_117;
F_58 ( V_52 ) ;
V_57 -> V_109 . V_52 = V_52 ;
V_57 -> V_113 = V_113 ;
V_57 -> V_106 = V_106 ;
V_90 = V_57 -> V_109 . V_60 -> V_90 ;
F_42 ( V_90 , V_16 ) ;
V_57 -> V_109 . V_113 = V_113 ? F_66 : NULL ;
V_57 -> V_109 . V_118 = F_67 ;
V_90 -> V_91 . V_119 = V_119 ;
V_90 -> V_91 . V_121 = F_59 ( V_139 ) ;
V_90 -> V_123 . V_114 = V_114 ;
F_54 ( V_138 , F_52 ( V_138 ) , V_66 ,
V_90 -> V_112 ) ;
* V_109 = & V_57 -> V_109 ;
V_67 = F_44 ( & V_57 -> V_109 , V_102 , V_84 ) ;
if ( V_67 < 0 )
goto V_124;
return V_67 ;
V_124:
* V_109 = NULL ;
F_26 ( V_57 -> V_109 . V_52 ) ;
F_40 ( & V_57 -> V_109 ) ;
V_117:
F_4 ( V_57 ) ;
return V_67 ;
}
static void F_69 ( struct V_58 * V_16 ,
struct V_140 * V_141 )
{
struct V_56 * V_57 = V_141 -> V_142 -> V_106 [ 0 ] ;
unsigned long V_43 ;
if ( V_57 -> V_113 )
switch ( V_141 -> V_110 ) {
case V_143 :
break;
case V_144 :
V_57 -> V_113 ( V_57 , - V_145 , NULL ) ;
break;
case V_146 :
V_57 -> V_113 ( V_57 , - V_147 , NULL ) ;
break;
default:
V_57 -> V_113 ( V_57 , - V_148 , NULL ) ;
break;
}
F_19 ( & V_61 , V_43 ) ;
F_49 ( & V_62 , V_57 -> V_55 ) ;
F_20 ( & V_61 , V_43 ) ;
F_40 ( V_57 ) ;
F_26 ( V_57 -> V_52 ) ;
V_57 -> V_118 ( V_57 ) ;
}
static void F_70 ( struct V_58 * V_149 ,
struct V_150 * V_151 )
{
struct V_56 * V_57 ;
struct V_59 * V_60 ;
V_60 = ( void * ) ( unsigned long ) V_151 -> V_152 -> V_153 ;
V_57 = V_60 -> V_106 [ 0 ] ;
if ( V_57 -> V_113 ) {
if ( V_151 -> V_152 -> V_110 == V_143 )
V_57 -> V_113 ( V_57 ,
V_151 -> V_154 . V_90 -> V_91 . V_110 ?
- V_130 : 0 ,
(struct V_89 * ) V_151 -> V_154 . V_90 ) ;
else
V_57 -> V_113 ( V_57 , - V_148 , NULL ) ;
}
F_71 ( V_151 ) ;
}
static void F_72 ( struct V_63 * V_17 )
{
struct V_44 * V_45 ;
int V_155 , V_156 , V_157 ;
if ( F_73 ( V_17 -> V_158 ) != V_159 )
return;
if ( V_17 -> V_158 == V_160 )
V_155 = V_156 = 0 ;
else {
V_155 = 1 ;
V_156 = V_17 -> V_161 ;
}
V_45 = F_74 ( sizeof *V_45 +
( V_156 - V_155 + 1 ) * sizeof ( struct V_8 ) ,
V_20 ) ;
if ( ! V_45 )
return;
V_45 -> V_48 = V_155 ;
V_45 -> V_162 = V_156 ;
for ( V_157 = 0 ; V_157 <= V_156 - V_155 ; ++ V_157 ) {
F_75 ( & V_45 -> V_9 [ V_157 ] . V_32 ) ;
if ( F_18 ( V_17 , V_157 + 1 ) != V_49 )
continue;
V_45 -> V_9 [ V_157 ] . V_3 = NULL ;
V_45 -> V_9 [ V_157 ] . V_18 = V_157 + V_155 ;
V_45 -> V_9 [ V_157 ] . V_16 =
F_76 ( V_17 , V_157 + V_155 , V_163 ,
NULL , 0 , F_69 ,
F_70 , V_45 ) ;
if ( F_12 ( V_45 -> V_9 [ V_157 ] . V_16 ) )
goto V_164;
F_77 ( & V_45 -> V_9 [ V_157 ] . V_10 , F_5 ) ;
}
F_78 ( V_17 , & V_64 , V_45 ) ;
F_79 ( & V_45 -> V_46 , V_17 , F_16 ) ;
if ( F_80 ( & V_45 -> V_46 ) )
goto V_164;
for ( V_157 = 0 ; V_157 <= V_156 - V_155 ; ++ V_157 )
if ( F_18 ( V_17 , V_157 + 1 ) == V_49 )
F_5 ( & V_45 -> V_9 [ V_157 ] . V_10 ) ;
return;
V_164:
while ( -- V_157 >= 0 )
if ( F_18 ( V_17 , V_157 + 1 ) == V_49 )
F_81 ( V_45 -> V_9 [ V_157 ] . V_16 ) ;
F_4 ( V_45 ) ;
return;
}
static void F_82 ( struct V_63 * V_17 )
{
struct V_44 * V_45 = F_32 ( V_17 , & V_64 ) ;
int V_157 ;
if ( ! V_45 )
return;
F_83 ( & V_45 -> V_46 ) ;
F_84 ( V_50 ) ;
for ( V_157 = 0 ; V_157 <= V_45 -> V_162 - V_45 -> V_48 ; ++ V_157 ) {
if ( F_18 ( V_17 , V_157 + 1 ) == V_49 ) {
F_81 ( V_45 -> V_9 [ V_157 ] . V_16 ) ;
if ( V_45 -> V_9 [ V_157 ] . V_3 )
F_14 ( & V_45 -> V_9 [ V_157 ] . V_3 -> V_4 , F_1 ) ;
}
}
F_4 ( V_45 ) ;
}
static int T_5 F_85 ( void )
{
int V_67 ;
F_86 ( & V_99 , sizeof V_99 ) ;
V_67 = F_87 ( & V_64 ) ;
if ( V_67 ) {
F_7 ( V_25 L_5 ) ;
goto V_117;
}
V_67 = F_88 () ;
if ( V_67 ) {
F_7 ( V_25 L_6 ) ;
goto V_124;
}
return 0 ;
V_124:
F_89 ( & V_64 ) ;
V_117:
return V_67 ;
}
static void T_6 F_90 ( void )
{
F_91 () ;
F_89 ( & V_64 ) ;
F_92 ( & V_62 ) ;
}
