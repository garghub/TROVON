static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_4 T_1 * V_5 )
{
struct V_4 V_6 ;
if ( F_2 ( & V_6 , V_5 , sizeof( V_6 ) ) )
return - V_7 ;
if ( V_6 . V_8 != V_9 ) {
F_3 ( 1 , L_1 , V_6 . V_8 ) ;
return - V_10 ;
}
F_4 ( V_6 . V_11 , F_5 ( F_6 () , V_2 -> V_12 . V_11 ) ) ;
V_6 . V_13 = V_2 -> V_13 ;
V_6 . V_14 = V_2 -> V_14 ;
V_6 . V_15 = F_7 ( V_3 ) -> V_16 ;
V_6 . V_17 = F_7 ( V_3 ) -> V_18 ;
if ( F_8 ( V_5 , & V_6 , sizeof( V_6 ) ) )
return - V_7 ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_19 T_1 * V_5 )
{
struct V_19 V_20 ;
if ( F_2 ( & V_20 , V_5 , sizeof( V_20 ) ) )
return - V_7 ;
if ( V_20 . V_8 != V_21 ) {
F_3 ( 1 , L_1 , V_20 . V_8 ) ;
return - V_10 ;
}
V_20 . V_11 = F_5 ( F_6 () , V_2 -> V_12 . V_11 ) ;
V_20 . V_13 = V_2 -> V_13 ;
V_20 . V_14 = V_2 -> V_14 ;
V_20 . V_15 = F_7 ( V_3 ) -> V_16 ;
V_20 . V_17 = F_7 ( V_3 ) -> V_18 ;
V_20 . V_22 = V_20 . V_23 = V_20 . V_24 = 0 ;
if ( F_8 ( V_5 , & V_20 , sizeof( V_20 ) ) )
return - V_7 ;
return 0 ;
}
static int
F_10 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_25 T_1 * V_5 )
{
struct V_25 V_20 ;
if ( F_2 ( & V_20 , V_5 , sizeof( V_20 ) ) )
return - V_7 ;
if ( V_20 . V_8 != V_21 ) {
F_3 ( 1 , L_1 , V_20 . V_8 ) ;
return - V_10 ;
}
V_20 . V_11 = F_5 ( F_6 () , V_2 -> V_12 . V_11 ) ;
V_20 . V_13 = V_2 -> V_13 ;
V_20 . V_14 = V_2 -> V_14 ;
V_20 . V_15 = F_7 ( V_3 ) -> V_16 ;
V_20 . V_17 = F_7 ( V_3 ) -> V_18 ;
V_20 . V_22 = V_20 . V_23 = V_20 . V_24 = 0 ;
if ( F_8 ( V_5 , & V_20 , sizeof( V_20 ) ) )
return - V_7 ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 , struct V_26 T_1 * V_5 )
{
struct V_26 V_27 ;
struct V_28 * V_29 ;
struct V_28 * V_30 ;
struct V_28 * V_31 ;
struct V_28 * V_32 ;
int V_33 ;
int V_34 ;
if ( F_2 ( & V_27 , V_5 , sizeof( V_27 ) ) )
return - V_7 ;
V_29 = NULL ;
V_27 . V_29 [ V_35 ] = 0 ;
if ( ! V_27 . V_29 [ 0 ] || ! strcmp ( V_27 . V_29 , L_2 ) )
V_29 = F_12 () ;
else {
V_29 = F_13 ( V_27 . V_29 ) ;
if ( ! V_29 ) {
return - V_36 ;
}
}
V_30 = NULL ;
V_27 . V_30 [ V_35 ] = 0 ;
if ( ! V_27 . V_30 [ 0 ] || ! strcmp ( V_27 . V_30 , L_2 ) ) {
V_30 = F_12 () ;
V_33 = 0 ;
} else if ( ! strcmp ( V_27 . V_30 , L_3 ) ) {
V_30 = F_12 () ;
V_33 = 1 ;
} else {
V_30 = F_13 ( V_27 . V_30 ) ;
if ( ! V_30 ) {
F_14 ( V_29 ) ;
return - V_36 ;
}
V_33 = 0 ;
}
F_15 ( & V_2 -> V_37 ) ;
if ( V_2 -> V_38 ) {
V_32 = V_29 ;
V_31 = V_30 ;
V_34 = - V_39 ;
} else {
if ( V_33 )
F_16 ( V_2 , V_40 ) ;
else
F_17 ( V_2 , V_40 ) ;
V_32 = V_2 -> V_41 ;
V_2 -> V_41 = V_29 ;
V_31 = V_2 -> V_42 ;
V_2 -> V_42 = V_30 ;
V_34 = 0 ;
}
F_18 ( & V_2 -> V_37 ) ;
F_14 ( V_32 ) ;
F_14 ( V_31 ) ;
return V_34 ;
}
static int
F_19 ( struct V_1 * V_2 , struct V_26 T_1 * V_5 )
{
struct V_26 V_27 ;
int V_43 ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
F_15 ( & V_2 -> V_37 ) ;
if ( V_2 -> V_41 && V_2 -> V_41 -> V_44 ) {
V_43 = strlen ( V_2 -> V_41 -> V_44 ) ;
if ( V_43 > V_35 )
V_43 = V_35 ;
strncpy ( V_27 . V_29 , V_2 -> V_41 -> V_44 , V_43 ) ;
V_27 . V_29 [ V_43 ] = 0 ;
}
if ( F_20 ( V_2 , V_40 ) )
strcpy ( V_27 . V_30 , L_3 ) ;
else if ( V_2 -> V_42 && V_2 -> V_42 -> V_44 ) {
V_43 = strlen ( V_2 -> V_42 -> V_44 ) ;
if ( V_43 > V_35 )
V_43 = V_35 ;
strncpy ( V_27 . V_30 , V_2 -> V_42 -> V_44 , V_43 ) ;
V_27 . V_30 [ V_43 ] = 0 ;
}
F_18 ( & V_2 -> V_37 ) ;
if ( F_8 ( V_5 , & V_27 , sizeof( V_27 ) ) )
return - V_7 ;
return 0 ;
}
static long F_21 ( struct V_3 * V_3 , unsigned int V_45 , unsigned long V_5 )
{
struct V_1 * V_2 = F_22 ( V_3 ) ;
int V_46 ;
struct V_47 V_48 ;
char * V_49 ;
void T_1 * V_50 = ( void T_1 * ) V_5 ;
switch ( V_45 ) {
#ifdef F_23
case V_51 :
#endif
case V_52 :
#ifdef F_23
if ( V_45 == V_51 ) {
struct V_53 V_54 ;
if ( F_2 ( & V_54 , V_50 , sizeof( V_54 ) ) )
return - V_7 ;
V_48 . V_55 = V_54 . V_55 ;
V_48 . V_56 = V_54 . V_56 ;
V_48 . V_57 = F_24 ( V_54 . V_57 ) ;
} else
#endif
if ( F_2 ( & V_48 , V_50 , sizeof( V_48 ) ) )
return - V_7 ;
if ( ( V_48 . V_55 > 255 )
|| ( V_48 . V_56 >
V_58 - sizeof( struct V_59 ) ) ) {
return - V_10 ;
}
V_49 = F_25 ( V_60 ) ;
if ( ! V_49 )
return - V_61 ;
if ( F_2 ( V_49 , V_48 . V_57 , V_48 . V_56 ) ) {
F_26 ( V_49 ) ;
return - V_7 ;
}
F_27 ( V_2 ) ;
V_2 -> V_62 = 0 ;
V_2 -> V_63 = V_48 . V_56 ;
memcpy ( V_2 -> V_64 , V_49 , V_48 . V_56 ) ;
V_46 = F_28 ( V_2 , V_48 . V_55 ,
V_49 , V_60 ) ;
if ( V_46 < 0 )
V_46 = - V_65 ;
else
V_46 = V_2 -> V_66 ;
F_29 ( V_2 ) ;
F_3 ( 1 , L_4 , V_46 ) ;
if ( V_46 >= 0 )
if ( F_8 ( V_48 . V_57 , V_49 , V_46 ) )
V_46 = - V_7 ;
F_26 ( V_49 ) ;
return V_46 ;
case V_67 :
if ( ! ( V_2 -> V_12 . V_68 & V_69 ) )
return - V_10 ;
F_15 ( & V_2 -> V_37 ) ;
if ( V_2 -> V_38 )
V_46 = - V_39 ;
else {
V_46 = F_30 ( V_3 -> V_70 ) ;
if ( V_46 == 0 )
V_2 -> V_38 = 1 ;
}
F_18 ( & V_2 -> V_37 ) ;
return V_46 ;
case V_71 :
return F_1 ( V_2 , V_3 , V_50 ) ;
case V_72 :
return F_9 ( V_2 , V_3 , V_50 ) ;
#ifdef F_23
case V_73 :
return F_10 ( V_2 , V_3 , V_50 ) ;
#endif
case V_74 :
{
T_2 V_75 ;
F_4 ( V_75 , F_5 ( F_6 () , V_2 -> V_12 . V_11 ) ) ;
if ( F_31 ( V_75 , ( T_2 T_1 * ) V_50 ) )
return - V_7 ;
return 0 ;
}
case V_76 :
{
T_3 V_75 = F_5 ( F_6 () , V_2 -> V_12 . V_11 ) ;
if ( F_31 ( V_75 , ( V_77 T_1 * ) V_50 ) )
return - V_7 ;
return 0 ;
}
case V_78 :
{
T_3 V_75 = F_5 ( F_6 () , V_2 -> V_12 . V_11 ) ;
if ( F_31 ( V_75 , ( V_79 T_1 * ) V_50 ) )
return - V_7 ;
return 0 ;
}
case V_80 :
{
struct V_81 V_82 ;
V_46 = - V_83 ;
F_15 ( & V_2 -> V_37 ) ;
if ( V_2 -> V_12 . V_84 [ 0 ] ) {
struct V_85 * V_85 = V_3 -> V_70 -> V_86 ;
if ( V_85 ) {
struct V_3 * V_87 = F_32 ( V_85 ) ;
if ( V_87 ) {
V_82 . V_16 = F_7 ( V_87 ) -> V_16 ;
V_82 . V_88 = F_7 ( V_87 ) -> V_88 ;
V_82 . V_89 = V_2 -> V_90 [ V_82 . V_16 ] ;
V_46 = 0 ;
} else
F_3 ( 1 , L_5 ) ;
} else
F_3 ( 1 , L_6 ) ;
} else {
V_82 . V_16 = - 1 ;
V_82 . V_89 = 0 ;
V_82 . V_88 = 0 ;
V_46 = 0 ;
}
F_18 ( & V_2 -> V_37 ) ;
if ( ! V_46 && F_8 ( V_50 , & V_82 , sizeof( V_82 ) ) )
V_46 = - V_7 ;
return V_46 ;
}
case V_91 :
{
struct V_81 V_82 ;
T_4 V_92 ;
T_5 V_93 ;
T_5 V_94 ;
struct V_85 * V_85 ;
if ( F_2 ( & V_82 , V_50 , sizeof( V_82 ) ) )
return - V_7 ;
F_15 ( & V_2 -> V_37 ) ;
if ( V_2 -> V_38 )
V_46 = - V_39 ;
else {
if ( V_82 . V_16 < 0 ) {
V_2 -> V_12 . V_84 [ 0 ] = 0 ;
V_92 = V_95 ;
V_93 = 0 ;
V_94 = 0 ;
V_46 = 0 ;
} else if ( V_82 . V_16 >= V_95 ) {
V_46 = - V_10 ;
} else if ( F_33 ( V_2 , V_82 . V_16 ,
V_82 . V_89 , V_82 . V_88 ,
& V_92 , & V_93 , & V_94 ) ) {
V_46 = - V_96 ;
} else
V_46 = 0 ;
if ( V_46 == 0 ) {
V_85 = V_3 -> V_70 -> V_86 ;
if ( V_85 ) {
struct V_3 * V_87 = F_32 ( V_85 ) ;
if ( V_87 ) {
F_7 ( V_87 ) -> V_16 = V_92 ;
F_7 ( V_87 ) -> V_88 = V_93 ;
F_7 ( V_87 ) -> V_18 = V_94 ;
V_2 -> V_38 = 1 ;
} else {
F_3 ( 1 , L_5 ) ;
V_46 = - V_65 ;
}
} else {
F_3 ( 1 , L_6 ) ;
V_46 = - V_65 ;
}
}
}
F_18 ( & V_2 -> V_37 ) ;
return V_46 ;
}
#ifdef F_34
case V_97 :
{
struct V_98 V_99 ;
if ( V_50 )
if ( F_2 ( & V_99 , V_50 , sizeof( V_99 ) ) )
return - V_7 ;
F_27 ( V_2 ) ;
F_15 ( & V_2 -> V_100 . V_101 ) ;
if ( V_50 ) {
if ( V_2 -> V_102 ) {
memcpy ( V_2 -> V_103 , V_99 . V_103 , 8 ) ;
memcpy ( V_2 -> V_104 , V_99 . V_104 , 16 ) ;
V_2 -> V_105 = 1 ;
}
} else {
V_2 -> V_105 = 0 ;
}
F_18 ( & V_2 -> V_100 . V_101 ) ;
F_29 ( V_2 ) ;
return 0 ;
}
case V_106 :
{
int V_107 ;
F_27 ( V_2 ) ;
V_107 = V_2 -> V_102 ;
F_29 ( V_2 ) ;
if ( F_31 ( V_107 , ( int T_1 * ) V_50 ) )
return - V_7 ;
return 0 ;
}
case V_108 :
{
int V_109 ;
if ( F_35 ( V_109 , ( unsigned char T_1 * ) V_50 ) )
return - V_7 ;
V_46 = 0 ;
F_27 ( V_2 ) ;
if ( V_2 -> V_105 ) {
if ( ! V_109 )
V_46 = - V_10 ;
} else {
V_2 -> V_102 = V_109 != 0 ;
}
F_29 ( V_2 ) ;
return V_46 ;
}
#endif
#ifdef F_36
case V_110 :
{
struct V_111 V_112 ;
if ( F_2 ( & V_112 , V_50 , sizeof( V_112 ) ) )
return - V_7 ;
if ( V_112 . V_113 != 0 )
return - V_10 ;
switch ( V_112 . V_45 ) {
case V_114 :
case V_115 :
if ( V_112 . V_116 < 0 )
return - V_10 ;
if ( V_112 . V_116 == 0 )
V_112 . V_116 = V_117 ;
else if ( V_112 . V_116 > V_118 )
V_112 . V_116 = V_118 ;
break;
case V_119 :
V_112 . V_116 = V_117 ;
case V_120 :
break;
default:
return - V_10 ;
}
if ( ( V_46 = F_37 ( V_3 , V_121 ) ) != 0 )
{
return V_46 ;
}
V_46 = - V_122 ;
if ( ! F_38 ( V_3 -> V_123 ) )
goto V_124;
if ( V_112 . V_45 == V_120 )
{
V_46 = F_39 ( F_22 ( V_3 ) ,
F_7 ( V_3 ) -> V_125 ,
V_112 . V_126 ,
V_112 . V_127 ) ;
if ( V_46 > 0 ) V_46 = 0 ;
}
else
{
int V_128 ;
switch ( V_112 . V_45 )
{
case V_114 : V_128 = 1 ; break;
case V_115 : V_128 = 3 ; break;
default: V_128 = 0 ; break;
}
V_46 = F_40 ( F_22 ( V_3 ) ,
F_7 ( V_3 ) -> V_125 ,
V_128 ,
V_112 . V_126 ,
V_112 . V_127 ,
V_112 . V_116 ) ;
if ( V_46 > 0 ) V_46 = - V_129 ;
}
V_124:
F_41 ( V_3 ) ;
return V_46 ;
}
#endif
#ifdef F_23
case V_130 :
{
struct V_131 V_27 ;
T_6 V_132 ;
if ( F_2 ( & V_27 , V_50 , sizeof( V_27 ) ) )
return - V_7 ;
F_42 ( & V_2 -> V_133 ) ;
V_27 . V_134 = V_2 -> V_135 . V_134 ;
V_132 = V_27 . V_136 ;
V_27 . V_136 = V_2 -> V_135 . V_136 ;
if ( V_132 > V_27 . V_136 )
V_132 = V_27 . V_136 ;
V_46 = 0 ;
if ( V_132 ) {
if ( F_8 ( F_24 ( V_27 . V_137 ) ,
V_2 -> V_135 . V_137 ,
V_132 ) )
V_46 = - V_7 ;
}
F_43 ( & V_2 -> V_133 ) ;
if ( ! V_46 && F_8 ( V_50 , & V_27 , sizeof( V_27 ) ) )
V_46 = - V_7 ;
return V_46 ;
}
#endif
case V_138 :
{
struct V_139 V_27 ;
T_6 V_132 ;
if ( F_2 ( & V_27 , V_50 , sizeof( V_27 ) ) )
return - V_7 ;
F_42 ( & V_2 -> V_133 ) ;
V_27 . V_134 = V_2 -> V_135 . V_134 ;
V_132 = V_27 . V_136 ;
V_27 . V_136 = V_2 -> V_135 . V_136 ;
if ( V_132 > V_27 . V_136 )
V_132 = V_27 . V_136 ;
V_46 = 0 ;
if ( V_132 ) {
if ( F_8 ( V_27 . V_137 ,
V_2 -> V_135 . V_137 ,
V_132 ) )
V_46 = - V_7 ;
}
F_43 ( & V_2 -> V_133 ) ;
if ( ! V_46 && F_8 ( V_50 , & V_27 , sizeof( V_27 ) ) )
V_46 = - V_7 ;
return V_46 ;
}
#ifdef F_23
case V_140 :
#endif
case V_141 :
{
struct V_139 V_27 ;
void * V_142 ;
void * V_143 ;
T_6 V_144 ;
void * V_145 ;
T_6 V_146 ;
#ifdef F_23
if ( V_45 == V_140 ) {
struct V_131 V_147 ;
if ( F_2 ( & V_147 , V_50 , sizeof( V_147 ) ) )
return - V_7 ;
V_27 . V_134 = V_147 . V_134 ;
V_27 . V_136 = V_147 . V_136 ;
V_27 . V_137 = F_24 ( V_147 . V_137 ) ;
} else
#endif
if ( F_2 ( & V_27 , V_50 , sizeof( V_27 ) ) )
return - V_7 ;
if ( V_27 . V_136 > V_148 )
return - V_61 ;
if ( V_27 . V_136 ) {
V_142 = F_44 ( V_27 . V_137 ,
V_27 . V_136 ) ;
if ( F_45 ( V_142 ) )
return F_46 ( V_142 ) ;
} else {
V_142 = NULL ;
}
F_47 ( & V_2 -> V_133 ) ;
V_143 = V_2 -> V_135 . V_137 ;
V_144 = V_2 -> V_135 . V_136 ;
V_145 = V_2 -> V_149 . V_57 ;
V_146 = V_2 -> V_149 . V_43 ;
V_2 -> V_135 . V_134 = V_27 . V_134 ;
V_2 -> V_135 . V_136 = V_27 . V_136 ;
V_2 -> V_135 . V_137 = V_142 ;
V_2 -> V_149 . V_43 = 0 ;
V_2 -> V_149 . V_57 = NULL ;
F_48 ( & V_2 -> V_133 ) ;
F_49 ( V_145 ) ;
F_49 ( V_143 ) ;
return 0 ;
}
#ifdef F_23
case V_150 :
#endif
case V_151 :
{
struct V_152 V_27 ;
T_6 V_132 ;
#ifdef F_23
if ( V_45 == V_150 ) {
struct V_153 V_147 ;
if ( F_2 ( & V_147 , V_50 , sizeof( V_147 ) ) )
return - V_7 ;
V_27 . V_43 = V_147 . V_43 ;
V_27 . V_57 = F_24 ( V_147 . V_57 ) ;
} else
#endif
if ( F_2 ( & V_27 , V_50 , sizeof( V_27 ) ) )
return - V_7 ;
F_42 ( & V_2 -> V_133 ) ;
V_132 = V_27 . V_43 ;
V_27 . V_43 = V_2 -> V_149 . V_43 ;
if ( V_132 > V_27 . V_43 ) V_132 = V_27 . V_43 ;
V_46 = 0 ;
if ( V_132 ) {
if ( F_8 ( V_27 . V_57 ,
V_2 -> V_149 . V_57 ,
V_132 ) )
V_46 = - V_7 ;
}
F_43 ( & V_2 -> V_133 ) ;
if ( V_46 )
return V_46 ;
#ifdef F_23
if ( V_45 == V_150 ) {
struct V_153 V_147 ;
V_147 . V_43 = V_27 . V_43 ;
V_147 . V_57 = ( unsigned long ) V_27 . V_57 ;
if ( F_8 ( V_50 , & V_147 , sizeof( V_147 ) ) )
return - V_7 ;
} else
#endif
if ( F_8 ( V_50 , & V_27 , sizeof( V_27 ) ) )
return - V_7 ;
return 0 ;
}
#ifdef F_23
case V_154 :
#endif
case V_155 :
{
struct V_152 V_27 ;
void * V_156 ;
void * V_157 ;
T_6 V_158 ;
#ifdef F_23
if ( V_45 == V_154 ) {
struct V_153 V_147 ;
if ( F_2 ( & V_147 , V_50 , sizeof( V_147 ) ) )
return - V_7 ;
V_27 . V_43 = V_147 . V_43 ;
V_27 . V_57 = F_24 ( V_147 . V_57 ) ;
} else
#endif
if ( F_2 ( & V_27 , V_50 , sizeof( V_27 ) ) )
return - V_7 ;
if ( V_27 . V_43 > V_159 )
return - V_61 ;
if ( V_27 . V_43 ) {
V_156 = F_44 ( V_27 . V_57 , V_27 . V_43 ) ;
if ( F_45 ( V_156 ) )
return F_46 ( V_156 ) ;
} else {
V_156 = NULL ;
}
F_47 ( & V_2 -> V_133 ) ;
V_157 = V_2 -> V_149 . V_57 ;
V_158 = V_2 -> V_149 . V_43 ;
V_2 -> V_149 . V_43 = V_27 . V_43 ;
V_2 -> V_149 . V_57 = V_156 ;
F_48 ( & V_2 -> V_133 ) ;
F_49 ( V_157 ) ;
return 0 ;
}
#ifdef F_50
case V_160 :
return F_11 ( V_2 , V_50 ) ;
case V_161 :
return F_19 ( V_2 , V_50 ) ;
#endif
case V_162 :
{
T_7 V_27 ;
if ( F_2 ( & V_27 , V_50 , sizeof( V_27 ) ) )
return - V_7 ;
if ( V_27 > 20000 )
return - V_10 ;
V_27 = ( V_27 * V_163 ) / 1000 ;
F_51 ( & V_2 -> V_164 , V_27 ) ;
return 0 ;
}
case V_165 :
{
T_7 V_27 = ( F_52 ( & V_2 -> V_164 ) * 1000 ) / V_163 ;
if ( F_8 ( V_50 , & V_27 , sizeof( V_27 ) ) )
return - V_7 ;
return 0 ;
}
}
return - V_10 ;
}
long F_53 ( struct V_166 * V_167 , unsigned int V_45 , unsigned long V_5 )
{
struct V_3 * V_3 = F_54 ( V_167 ) ;
struct V_1 * V_2 = F_22 ( V_3 ) ;
T_8 V_75 = F_55 () ;
int V_168 = 0 ;
long V_169 ;
switch ( V_45 ) {
case V_160 :
case V_67 :
case V_91 :
if ( ! F_56 ( V_170 ) ) {
V_169 = - V_171 ;
goto V_172;
}
break;
}
if ( ! F_57 ( V_2 -> V_12 . V_11 , V_75 ) ) {
switch ( V_45 ) {
case V_138 :
case V_141 :
case V_151 :
case V_155 :
#ifdef F_23
case V_130 :
case V_140 :
case V_150 :
case V_154 :
#endif
V_169 = - V_83 ;
goto V_172;
case V_71 :
case V_72 :
case V_52 :
case V_162 :
case V_97 :
case V_110 :
case V_108 :
#ifdef F_23
case V_73 :
case V_51 :
#endif
V_169 = F_58 ( V_167 ) ;
if ( V_169 )
goto V_172;
V_168 = 1 ;
V_169 = F_59 ( V_3 , V_173 ) ;
if ( V_169 )
goto V_174;
break;
case V_74 :
case V_76 :
case V_78 :
case V_80 :
case V_106 :
V_169 = F_59 ( V_3 , V_175 ) ;
if ( V_169 )
goto V_172;
break;
case V_161 :
case V_165 :
default:
case V_160 :
case V_67 :
case V_91 :
break;
}
}
V_169 = F_21 ( V_3 , V_45 , V_5 ) ;
V_174:
if ( V_168 )
F_60 ( V_167 ) ;
V_172:
return V_169 ;
}
long F_61 ( struct V_166 * V_166 , unsigned int V_45 , unsigned long V_5 )
{
long V_169 ;
V_5 = ( unsigned long ) F_24 ( V_5 ) ;
V_169 = F_53 ( V_166 , V_45 , V_5 ) ;
return V_169 ;
}
