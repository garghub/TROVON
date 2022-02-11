static int F_1 ( struct V_1 * V_2 , int type , int V_3 ,
T_1 V_4 )
{
switch ( V_3 ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
break;
case V_11 :
case V_12 :
if ( ( type == V_13 && F_2 ( F_3 () , F_4 ( F_5 () , V_4 ) ) ) ||
( type == V_14 && F_6 ( F_7 ( F_5 () , V_4 ) ) ) )
break;
default:
if ( ! F_8 ( V_15 ) )
return - V_16 ;
}
return F_9 ( V_3 , type , V_4 , V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 , void * V_17 )
{
int type = * ( int * ) V_17 ;
if ( V_2 -> V_18 && V_2 -> V_18 -> V_19 &&
( V_2 -> V_20 & ( 1 << type ) ) )
V_2 -> V_18 -> V_19 ( V_2 , type ) ;
}
static int F_11 ( int type )
{
int V_21 ;
if ( type >= V_22 )
return - V_23 ;
V_21 = F_9 ( V_6 , type , 0 , NULL ) ;
if ( ! V_21 )
F_12 ( F_10 , & type ) ;
return V_21 ;
}
static int F_13 ( struct V_1 * V_2 , int type , int V_3 , T_1 V_4 ,
struct V_24 * V_24 )
{
if ( ! V_2 -> V_18 -> V_25 && ! V_2 -> V_18 -> V_26 )
return - V_27 ;
if ( V_2 -> V_18 -> V_26 )
return V_2 -> V_18 -> V_26 ( V_2 , type , V_4 ) ;
if ( F_14 ( V_24 ) )
return F_15 ( V_24 ) ;
return V_2 -> V_18 -> V_25 ( V_2 , type , V_4 , V_24 ) ;
}
static int F_16 ( struct V_1 * V_2 , int type , void T_2 * V_28 )
{
T_3 V_29 ;
F_17 ( & F_18 ( V_2 ) -> V_30 ) ;
if ( ! F_19 ( V_2 , type ) ) {
F_20 ( & F_18 ( V_2 ) -> V_30 ) ;
return - V_31 ;
}
V_29 = F_18 ( V_2 ) -> V_32 [ type ] . V_33 -> V_34 ;
F_20 ( & F_18 ( V_2 ) -> V_30 ) ;
if ( F_21 ( V_28 , & V_29 , sizeof( V_29 ) ) )
return - V_35 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , int type , void T_2 * V_28 )
{
struct V_36 V_32 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_37 )
return - V_27 ;
V_21 = V_2 -> V_18 -> V_37 ( V_2 , type , & V_32 ) ;
if ( ! V_21 && F_21 ( V_28 , & V_32 , sizeof( V_32 ) ) )
return - V_35 ;
return V_21 ;
}
static int F_23 ( struct V_1 * V_2 , int type , void T_2 * V_28 )
{
struct V_36 V_32 ;
if ( F_24 ( & V_32 , V_28 , sizeof( V_32 ) ) )
return - V_35 ;
if ( ! V_2 -> V_18 -> V_38 )
return - V_27 ;
return V_2 -> V_18 -> V_38 ( V_2 , type , & V_32 ) ;
}
static inline T_4 F_25 ( T_4 V_39 )
{
return V_39 << V_40 ;
}
static inline T_4 F_26 ( T_4 V_41 )
{
return ( V_41 + V_42 - 1 ) >> V_40 ;
}
static void F_27 ( struct V_43 * V_44 , struct V_45 * V_46 )
{
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_44 -> V_47 = F_26 ( V_46 -> V_48 ) ;
V_44 -> V_49 = F_26 ( V_46 -> V_50 ) ;
V_44 -> V_51 = V_46 -> V_52 ;
V_44 -> V_53 = V_46 -> V_54 ;
V_44 -> V_55 = V_46 -> V_56 ;
V_44 -> V_57 = V_46 -> V_58 ;
V_44 -> V_59 = V_46 -> V_60 ;
V_44 -> V_61 = V_46 -> V_62 ;
V_44 -> V_63 = V_64 ;
}
static int F_28 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_28 )
{
struct V_65 V_66 ;
struct V_45 V_67 ;
struct V_43 V_68 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_69 )
return - V_27 ;
V_66 = F_29 ( F_5 () , type , V_4 ) ;
if ( ! F_30 ( V_66 ) )
return - V_23 ;
V_21 = V_2 -> V_18 -> V_69 ( V_2 , V_66 , & V_67 ) ;
if ( V_21 )
return V_21 ;
F_27 ( & V_68 , & V_67 ) ;
if ( F_21 ( V_28 , & V_68 , sizeof( V_68 ) ) )
return - V_35 ;
return 0 ;
}
static void F_31 ( struct V_45 * V_44 , struct V_43 * V_46 )
{
V_44 -> V_48 = F_25 ( V_46 -> V_47 ) ;
V_44 -> V_50 = F_25 ( V_46 -> V_49 ) ;
V_44 -> V_52 = V_46 -> V_51 ;
V_44 -> V_54 = V_46 -> V_53 ;
V_44 -> V_56 = V_46 -> V_55 ;
V_44 -> V_58 = V_46 -> V_57 ;
V_44 -> V_60 = V_46 -> V_59 ;
V_44 -> V_62 = V_46 -> V_61 ;
V_44 -> V_70 = 0 ;
if ( V_46 -> V_63 & V_71 )
V_44 -> V_70 |= V_72 | V_73 ;
if ( V_46 -> V_63 & V_74 )
V_44 -> V_70 |= V_75 ;
if ( V_46 -> V_63 & V_76 )
V_44 -> V_70 |= V_77 | V_78 ;
if ( V_46 -> V_63 & V_79 )
V_44 -> V_70 |= V_80 ;
if ( V_46 -> V_63 & V_81 )
V_44 -> V_70 |= V_82 ;
if ( V_46 -> V_63 & V_83 )
V_44 -> V_70 |= V_84 ;
}
static int F_32 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_28 )
{
struct V_45 V_67 ;
struct V_43 V_68 ;
struct V_65 V_66 ;
if ( F_24 ( & V_68 , V_28 , sizeof( V_68 ) ) )
return - V_35 ;
if ( ! V_2 -> V_18 -> V_85 )
return - V_27 ;
V_66 = F_29 ( F_5 () , type , V_4 ) ;
if ( ! F_30 ( V_66 ) )
return - V_23 ;
F_31 ( & V_67 , & V_68 ) ;
return V_2 -> V_18 -> V_85 ( V_2 , V_66 , & V_67 ) ;
}
static int F_33 ( struct V_1 * V_2 , int V_3 , void T_2 * V_28 )
{
T_3 V_86 ;
if ( F_24 ( & V_86 , V_28 , sizeof( V_86 ) ) )
return - V_35 ;
if ( ! V_2 -> V_18 -> V_87 )
return - V_27 ;
return V_2 -> V_18 -> V_87 ( V_2 , V_86 , V_3 ) ;
}
static int F_34 ( struct V_1 * V_2 , void T_2 * V_28 )
{
struct V_88 V_89 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_90 )
return - V_27 ;
V_21 = V_2 -> V_18 -> V_90 ( V_2 , & V_89 ) ;
if ( ! V_21 && F_21 ( V_28 , & V_89 , sizeof( V_89 ) ) )
return - V_35 ;
return V_21 ;
}
static int F_35 ( struct V_1 * V_2 , void T_2 * V_28 )
{
struct V_91 V_89 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_92 )
return - V_27 ;
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
if ( F_24 ( & V_89 , V_28 , 1 ) )
return - V_35 ;
switch ( V_89 . V_93 ) {
case V_94 :
break;
default:
return - V_23 ;
}
V_21 = V_2 -> V_18 -> V_92 ( V_2 , & V_89 ) ;
if ( ! V_21 && F_21 ( V_28 , & V_89 , sizeof( V_89 ) ) )
return - V_35 ;
return V_21 ;
}
static inline T_5 F_36 ( T_5 V_39 )
{
return V_39 << V_95 ;
}
static inline T_5 F_37 ( T_5 V_96 )
{
return ( V_96 + ( 1 << V_95 ) - 1 ) >> V_95 ;
}
static void F_38 ( struct V_45 * V_44 , struct V_97 * V_46 )
{
V_44 -> V_48 = F_36 ( V_46 -> V_98 ) ;
V_44 -> V_50 = F_36 ( V_46 -> V_99 ) ;
V_44 -> V_54 = V_46 -> V_54 ;
V_44 -> V_56 = V_46 -> V_56 ;
V_44 -> V_52 = F_36 ( V_46 -> V_100 ) ;
V_44 -> V_58 = V_46 -> V_101 ;
V_44 -> V_62 = V_46 -> V_102 ;
V_44 -> V_60 = V_46 -> V_103 ;
V_44 -> V_104 = V_46 -> V_105 ;
V_44 -> V_106 = V_46 -> V_107 ;
V_44 -> V_108 = F_36 ( V_46 -> V_109 ) ;
V_44 -> V_110 = F_36 ( V_46 -> V_111 ) ;
V_44 -> V_112 = F_36 ( V_46 -> V_113 ) ;
V_44 -> V_114 = V_46 -> V_115 ;
V_44 -> V_116 = V_46 -> V_117 ;
V_44 -> V_70 = 0 ;
if ( V_46 -> V_70 & V_118 )
V_44 -> V_70 |= V_77 ;
if ( V_46 -> V_70 & V_119 )
V_44 -> V_70 |= V_78 ;
if ( V_46 -> V_70 & V_120 )
V_44 -> V_70 |= V_72 ;
if ( V_46 -> V_70 & V_121 )
V_44 -> V_70 |= V_73 ;
if ( V_46 -> V_70 & V_122 )
V_44 -> V_70 |= V_123 ;
if ( V_46 -> V_70 & V_124 )
V_44 -> V_70 |= V_125 ;
if ( V_46 -> V_70 & V_126 )
V_44 -> V_70 |= V_82 ;
if ( V_46 -> V_70 & V_127 )
V_44 -> V_70 |= V_84 ;
if ( V_46 -> V_70 & V_128 )
V_44 -> V_70 |= V_129 ;
if ( V_46 -> V_70 & V_130 )
V_44 -> V_70 |= V_131 ;
if ( V_46 -> V_70 & V_132 )
V_44 -> V_70 |= V_133 ;
if ( V_46 -> V_70 & V_134 )
V_44 -> V_70 |= V_135 ;
if ( V_46 -> V_70 & V_136 )
V_44 -> V_70 |= V_75 ;
if ( V_46 -> V_70 & V_137 )
V_44 -> V_70 |= V_80 ;
if ( V_46 -> V_70 & V_138 )
V_44 -> V_70 |= V_139 ;
}
static int F_39 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_28 )
{
struct V_97 V_67 ;
struct V_45 V_140 ;
struct V_65 V_66 ;
if ( F_24 ( & V_67 , V_28 , sizeof( V_67 ) ) )
return - V_35 ;
if ( ! V_2 -> V_18 -> V_85 )
return - V_27 ;
V_66 = F_29 ( F_5 () , type , V_4 ) ;
if ( ! F_30 ( V_66 ) )
return - V_23 ;
F_38 ( & V_140 , & V_67 ) ;
return V_2 -> V_18 -> V_85 ( V_2 , V_66 , & V_140 ) ;
}
static void F_40 ( struct V_97 * V_44 , struct V_45 * V_46 ,
int type , T_1 V_4 )
{
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_44 -> V_141 = V_142 ;
V_44 -> V_143 = V_4 ;
if ( type == V_13 )
V_44 -> V_144 = V_145 ;
else if ( type == V_146 )
V_44 -> V_144 = V_147 ;
else
V_44 -> V_144 = V_148 ;
V_44 -> V_98 = F_37 ( V_46 -> V_48 ) ;
V_44 -> V_99 = F_37 ( V_46 -> V_50 ) ;
V_44 -> V_54 = V_46 -> V_54 ;
V_44 -> V_56 = V_46 -> V_56 ;
V_44 -> V_100 = F_37 ( V_46 -> V_52 ) ;
V_44 -> V_101 = V_46 -> V_58 ;
V_44 -> V_102 = V_46 -> V_62 ;
V_44 -> V_103 = V_46 -> V_60 ;
V_44 -> V_105 = V_46 -> V_104 ;
V_44 -> V_107 = V_46 -> V_106 ;
V_44 -> V_109 = F_37 ( V_46 -> V_108 ) ;
V_44 -> V_111 = F_37 ( V_46 -> V_110 ) ;
V_44 -> V_113 = F_37 ( V_46 -> V_112 ) ;
V_44 -> V_115 = V_46 -> V_114 ;
V_44 -> V_117 = V_46 -> V_116 ;
}
static int F_41 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_28 )
{
struct V_97 V_67 ;
struct V_45 V_140 ;
struct V_65 V_66 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_69 )
return - V_27 ;
V_66 = F_29 ( F_5 () , type , V_4 ) ;
if ( ! F_30 ( V_66 ) )
return - V_23 ;
V_21 = V_2 -> V_18 -> V_69 ( V_2 , V_66 , & V_140 ) ;
if ( V_21 )
return V_21 ;
F_40 ( & V_67 , & V_140 , type , V_4 ) ;
if ( F_21 ( V_28 , & V_67 , sizeof( V_67 ) ) )
return - V_35 ;
return V_21 ;
}
static int F_42 ( struct V_1 * V_2 , void T_2 * V_28 )
{
T_3 V_86 ;
if ( F_24 ( & V_86 , V_28 , sizeof( V_86 ) ) )
return - V_35 ;
if ( ! V_2 -> V_18 -> V_149 )
return - V_27 ;
return V_2 -> V_18 -> V_149 ( V_2 , V_86 ) ;
}
static int F_43 ( struct V_1 * V_2 , int type , int V_3 , T_1 V_4 ,
void T_2 * V_28 , struct V_24 * V_24 )
{
int V_21 ;
if ( type >= ( F_44 ( V_3 ) ? V_150 : V_22 ) )
return - V_23 ;
if ( ! V_2 -> V_18 )
return - V_27 ;
if ( ! ( V_2 -> V_20 & ( 1 << type ) ) )
return - V_23 ;
V_21 = F_1 ( V_2 , type , V_3 , V_4 ) ;
if ( V_21 < 0 )
return V_21 ;
switch ( V_3 ) {
case V_151 :
return F_13 ( V_2 , type , V_3 , V_4 , V_24 ) ;
case V_152 :
if ( ! V_2 -> V_18 -> V_153 )
return - V_27 ;
return V_2 -> V_18 -> V_153 ( V_2 , type ) ;
case V_5 :
return F_16 ( V_2 , type , V_28 ) ;
case V_7 :
return F_22 ( V_2 , type , V_28 ) ;
case V_154 :
return F_23 ( V_2 , type , V_28 ) ;
case V_11 :
return F_28 ( V_2 , type , V_4 , V_28 ) ;
case V_155 :
return F_32 ( V_2 , type , V_4 , V_28 ) ;
case V_6 :
if ( ! V_2 -> V_18 -> V_19 )
return - V_27 ;
return V_2 -> V_18 -> V_19 ( V_2 , type ) ;
case V_156 :
case V_157 :
return F_33 ( V_2 , V_3 , V_28 ) ;
case V_158 :
return F_42 ( V_2 , V_28 ) ;
case V_8 :
return F_34 ( V_2 , V_28 ) ;
case V_9 :
return F_35 ( V_2 , V_28 ) ;
case V_159 :
return F_39 ( V_2 , type , V_4 , V_28 ) ;
case V_12 :
return F_41 ( V_2 , type , V_4 , V_28 ) ;
case V_10 :
if ( V_2 -> V_160 & V_161 )
return - V_162 ;
return 0 ;
default:
return - V_23 ;
}
}
static int F_45 ( int V_3 )
{
switch ( V_3 ) {
case V_5 :
case V_7 :
case V_6 :
case V_8 :
case V_9 :
case V_12 :
case V_10 :
return 0 ;
}
return 1 ;
}
static struct V_1 * F_46 ( const char T_2 * V_163 , int V_3 )
{
#ifdef F_47
struct V_164 * V_165 ;
struct V_1 * V_2 ;
struct V_166 * V_167 = F_48 ( V_163 ) ;
if ( F_14 ( V_167 ) )
return F_49 ( V_167 ) ;
V_165 = F_50 ( V_167 -> V_168 ) ;
F_51 ( V_167 ) ;
if ( F_14 ( V_165 ) )
return F_49 ( V_165 ) ;
if ( F_45 ( V_3 ) )
V_2 = F_52 ( V_165 ) ;
else
V_2 = F_53 ( V_165 ) ;
F_54 ( V_165 ) ;
if ( ! V_2 )
return F_55 ( - V_169 ) ;
return V_2 ;
#else
return F_55 ( - V_169 ) ;
#endif
}
