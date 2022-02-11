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
unsigned int F_13 ( int type )
{
switch ( type ) {
case V_13 :
return V_24 ;
case V_14 :
return V_25 ;
case V_26 :
return V_27 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int type , int V_3 , T_1 V_4 ,
struct V_28 * V_28 )
{
if ( ! V_2 -> V_18 -> V_29 && ! V_2 -> V_18 -> V_30 )
return - V_31 ;
if ( V_2 -> V_18 -> V_30 )
return V_2 -> V_18 -> V_30 ( V_2 , F_13 ( type ) ) ;
if ( F_15 ( V_28 ) )
return F_16 ( V_28 ) ;
return V_2 -> V_18 -> V_29 ( V_2 , type , V_4 , V_28 ) ;
}
static int F_17 ( struct V_1 * V_2 , int type )
{
if ( ! V_2 -> V_18 -> V_32 && ! V_2 -> V_18 -> V_33 )
return - V_31 ;
if ( V_2 -> V_18 -> V_33 )
return V_2 -> V_18 -> V_33 ( V_2 , F_13 ( type ) ) ;
return V_2 -> V_18 -> V_32 ( V_2 , type ) ;
}
static int F_18 ( struct V_1 * V_2 , int type , void T_2 * V_34 )
{
T_3 V_35 ;
F_19 ( & F_20 ( V_2 ) -> V_36 ) ;
if ( ! F_21 ( V_2 , type ) ) {
F_22 ( & F_20 ( V_2 ) -> V_36 ) ;
return - V_37 ;
}
V_35 = F_20 ( V_2 ) -> V_38 [ type ] . V_39 -> V_40 ;
F_22 ( & F_20 ( V_2 ) -> V_36 ) ;
if ( F_23 ( V_34 , & V_35 , sizeof( V_35 ) ) )
return - V_41 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int type , void T_2 * V_34 )
{
struct V_42 V_38 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_43 )
return - V_31 ;
V_21 = V_2 -> V_18 -> V_43 ( V_2 , type , & V_38 ) ;
if ( ! V_21 && F_23 ( V_34 , & V_38 , sizeof( V_38 ) ) )
return - V_41 ;
return V_21 ;
}
static int F_25 ( struct V_1 * V_2 , int type , void T_2 * V_34 )
{
struct V_42 V_38 ;
if ( F_26 ( & V_38 , V_34 , sizeof( V_38 ) ) )
return - V_41 ;
if ( ! V_2 -> V_18 -> V_44 )
return - V_31 ;
return V_2 -> V_18 -> V_44 ( V_2 , type , & V_38 ) ;
}
static inline T_4 F_27 ( T_4 V_45 )
{
return V_45 << V_46 ;
}
static inline T_4 F_28 ( T_4 V_47 )
{
return ( V_47 + V_48 - 1 ) >> V_46 ;
}
static void F_29 ( struct V_49 * V_50 , struct V_51 * V_52 )
{
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_53 = F_28 ( V_52 -> V_54 ) ;
V_50 -> V_55 = F_28 ( V_52 -> V_56 ) ;
V_50 -> V_57 = V_52 -> V_58 ;
V_50 -> V_59 = V_52 -> V_60 ;
V_50 -> V_61 = V_52 -> V_62 ;
V_50 -> V_63 = V_52 -> V_64 ;
V_50 -> V_65 = V_52 -> V_66 ;
V_50 -> V_67 = V_52 -> V_68 ;
V_50 -> V_69 = V_70 ;
}
static int F_30 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_34 )
{
struct V_71 V_72 ;
struct V_51 V_73 ;
struct V_49 V_74 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_75 )
return - V_31 ;
V_72 = F_31 ( F_5 () , type , V_4 ) ;
if ( ! F_32 ( V_72 ) )
return - V_23 ;
V_21 = V_2 -> V_18 -> V_75 ( V_2 , V_72 , & V_73 ) ;
if ( V_21 )
return V_21 ;
F_29 ( & V_74 , & V_73 ) ;
if ( F_23 ( V_34 , & V_74 , sizeof( V_74 ) ) )
return - V_41 ;
return 0 ;
}
static void F_33 ( struct V_51 * V_50 , struct V_49 * V_52 )
{
V_50 -> V_54 = F_27 ( V_52 -> V_53 ) ;
V_50 -> V_56 = F_27 ( V_52 -> V_55 ) ;
V_50 -> V_58 = V_52 -> V_57 ;
V_50 -> V_60 = V_52 -> V_59 ;
V_50 -> V_62 = V_52 -> V_61 ;
V_50 -> V_64 = V_52 -> V_63 ;
V_50 -> V_66 = V_52 -> V_65 ;
V_50 -> V_68 = V_52 -> V_67 ;
V_50 -> V_76 = 0 ;
if ( V_52 -> V_69 & V_77 )
V_50 -> V_76 |= V_78 | V_79 ;
if ( V_52 -> V_69 & V_80 )
V_50 -> V_76 |= V_81 ;
if ( V_52 -> V_69 & V_82 )
V_50 -> V_76 |= V_83 | V_84 ;
if ( V_52 -> V_69 & V_85 )
V_50 -> V_76 |= V_86 ;
if ( V_52 -> V_69 & V_87 )
V_50 -> V_76 |= V_88 ;
if ( V_52 -> V_69 & V_89 )
V_50 -> V_76 |= V_90 ;
}
static int F_34 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_34 )
{
struct V_51 V_73 ;
struct V_49 V_74 ;
struct V_71 V_72 ;
if ( F_26 ( & V_74 , V_34 , sizeof( V_74 ) ) )
return - V_41 ;
if ( ! V_2 -> V_18 -> V_91 )
return - V_31 ;
V_72 = F_31 ( F_5 () , type , V_4 ) ;
if ( ! F_32 ( V_72 ) )
return - V_23 ;
F_33 ( & V_73 , & V_74 ) ;
return V_2 -> V_18 -> V_91 ( V_2 , V_72 , & V_73 ) ;
}
static int V_30 ( struct V_1 * V_2 , void T_2 * V_34 )
{
T_3 V_92 ;
if ( F_26 ( & V_92 , V_34 , sizeof( V_92 ) ) )
return - V_41 ;
if ( ! V_2 -> V_18 -> V_30 )
return - V_31 ;
return V_2 -> V_18 -> V_30 ( V_2 , V_92 ) ;
}
static int V_33 ( struct V_1 * V_2 , void T_2 * V_34 )
{
T_3 V_92 ;
if ( F_26 ( & V_92 , V_34 , sizeof( V_92 ) ) )
return - V_41 ;
if ( ! V_2 -> V_18 -> V_33 )
return - V_31 ;
return V_2 -> V_18 -> V_33 ( V_2 , V_92 ) ;
}
static int F_35 ( struct V_1 * V_2 , void T_2 * V_34 )
{
struct V_93 V_94 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_95 )
return - V_31 ;
V_21 = V_2 -> V_18 -> V_95 ( V_2 , & V_94 ) ;
if ( ! V_21 && F_23 ( V_34 , & V_94 , sizeof( V_94 ) ) )
return - V_41 ;
return V_21 ;
}
static int F_36 ( struct V_1 * V_2 , void T_2 * V_34 )
{
struct V_96 V_94 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_97 )
return - V_31 ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
if ( F_26 ( & V_94 , V_34 , 1 ) )
return - V_41 ;
switch ( V_94 . V_98 ) {
case V_99 :
break;
default:
return - V_23 ;
}
V_21 = V_2 -> V_18 -> V_97 ( V_2 , & V_94 ) ;
if ( ! V_21 && F_23 ( V_34 , & V_94 , sizeof( V_94 ) ) )
return - V_41 ;
return V_21 ;
}
static inline T_5 F_37 ( T_5 V_45 )
{
return V_45 << V_100 ;
}
static inline T_5 F_38 ( T_5 V_101 )
{
return ( V_101 + ( 1 << V_100 ) - 1 ) >> V_100 ;
}
static void F_39 ( struct V_51 * V_50 , struct V_102 * V_52 )
{
V_50 -> V_54 = F_37 ( V_52 -> V_103 ) ;
V_50 -> V_56 = F_37 ( V_52 -> V_104 ) ;
V_50 -> V_60 = V_52 -> V_60 ;
V_50 -> V_62 = V_52 -> V_62 ;
V_50 -> V_58 = F_37 ( V_52 -> V_105 ) ;
V_50 -> V_64 = V_52 -> V_106 ;
V_50 -> V_68 = V_52 -> V_107 ;
V_50 -> V_66 = V_52 -> V_108 ;
V_50 -> V_109 = V_52 -> V_110 ;
V_50 -> V_111 = V_52 -> V_112 ;
V_50 -> V_113 = F_37 ( V_52 -> V_114 ) ;
V_50 -> V_115 = F_37 ( V_52 -> V_116 ) ;
V_50 -> V_117 = F_37 ( V_52 -> V_118 ) ;
V_50 -> V_119 = V_52 -> V_120 ;
V_50 -> V_121 = V_52 -> V_122 ;
V_50 -> V_76 = 0 ;
if ( V_52 -> V_76 & V_123 )
V_50 -> V_76 |= V_83 ;
if ( V_52 -> V_76 & V_124 )
V_50 -> V_76 |= V_84 ;
if ( V_52 -> V_76 & V_125 )
V_50 -> V_76 |= V_78 ;
if ( V_52 -> V_76 & V_126 )
V_50 -> V_76 |= V_79 ;
if ( V_52 -> V_76 & V_127 )
V_50 -> V_76 |= V_128 ;
if ( V_52 -> V_76 & V_129 )
V_50 -> V_76 |= V_130 ;
if ( V_52 -> V_76 & V_131 )
V_50 -> V_76 |= V_88 ;
if ( V_52 -> V_76 & V_132 )
V_50 -> V_76 |= V_90 ;
if ( V_52 -> V_76 & V_133 )
V_50 -> V_76 |= V_134 ;
if ( V_52 -> V_76 & V_135 )
V_50 -> V_76 |= V_136 ;
if ( V_52 -> V_76 & V_137 )
V_50 -> V_76 |= V_138 ;
if ( V_52 -> V_76 & V_139 )
V_50 -> V_76 |= V_140 ;
if ( V_52 -> V_76 & V_141 )
V_50 -> V_76 |= V_81 ;
if ( V_52 -> V_76 & V_142 )
V_50 -> V_76 |= V_86 ;
if ( V_52 -> V_76 & V_143 )
V_50 -> V_76 |= V_144 ;
}
static int F_40 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_34 )
{
struct V_102 V_73 ;
struct V_51 V_145 ;
struct V_71 V_72 ;
if ( F_26 ( & V_73 , V_34 , sizeof( V_73 ) ) )
return - V_41 ;
if ( ! V_2 -> V_18 -> V_91 )
return - V_31 ;
V_72 = F_31 ( F_5 () , type , V_4 ) ;
if ( ! F_32 ( V_72 ) )
return - V_23 ;
F_39 ( & V_145 , & V_73 ) ;
return V_2 -> V_18 -> V_91 ( V_2 , V_72 , & V_145 ) ;
}
static void F_41 ( struct V_102 * V_50 , struct V_51 * V_52 ,
int type , T_1 V_4 )
{
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_146 = V_147 ;
V_50 -> V_148 = V_4 ;
if ( type == V_13 )
V_50 -> V_149 = V_150 ;
else if ( type == V_26 )
V_50 -> V_149 = V_151 ;
else
V_50 -> V_149 = V_152 ;
V_50 -> V_103 = F_38 ( V_52 -> V_54 ) ;
V_50 -> V_104 = F_38 ( V_52 -> V_56 ) ;
V_50 -> V_60 = V_52 -> V_60 ;
V_50 -> V_62 = V_52 -> V_62 ;
V_50 -> V_105 = F_38 ( V_52 -> V_58 ) ;
V_50 -> V_106 = V_52 -> V_64 ;
V_50 -> V_107 = V_52 -> V_68 ;
V_50 -> V_108 = V_52 -> V_66 ;
V_50 -> V_110 = V_52 -> V_109 ;
V_50 -> V_112 = V_52 -> V_111 ;
V_50 -> V_114 = F_38 ( V_52 -> V_113 ) ;
V_50 -> V_116 = F_38 ( V_52 -> V_115 ) ;
V_50 -> V_118 = F_38 ( V_52 -> V_117 ) ;
V_50 -> V_120 = V_52 -> V_119 ;
V_50 -> V_122 = V_52 -> V_121 ;
}
static int F_42 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_34 )
{
struct V_102 V_73 ;
struct V_51 V_145 ;
struct V_71 V_72 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_75 )
return - V_31 ;
V_72 = F_31 ( F_5 () , type , V_4 ) ;
if ( ! F_32 ( V_72 ) )
return - V_23 ;
V_21 = V_2 -> V_18 -> V_75 ( V_2 , V_72 , & V_145 ) ;
if ( V_21 )
return V_21 ;
F_41 ( & V_73 , & V_145 , type , V_4 ) ;
if ( F_23 ( V_34 , & V_73 , sizeof( V_73 ) ) )
return - V_41 ;
return V_21 ;
}
static int F_43 ( struct V_1 * V_2 , void T_2 * V_34 )
{
T_3 V_92 ;
if ( F_26 ( & V_92 , V_34 , sizeof( V_92 ) ) )
return - V_41 ;
if ( ! V_2 -> V_18 -> V_153 )
return - V_31 ;
return V_2 -> V_18 -> V_153 ( V_2 , V_92 ) ;
}
static int F_44 ( struct V_1 * V_2 , int type , int V_3 , T_1 V_4 ,
void T_2 * V_34 , struct V_28 * V_28 )
{
int V_21 ;
if ( type >= ( F_45 ( V_3 ) ? V_154 : V_22 ) )
return - V_23 ;
if ( ! V_2 -> V_18 )
return - V_31 ;
if ( ! ( V_2 -> V_20 & ( 1 << type ) ) )
return - V_23 ;
V_21 = F_1 ( V_2 , type , V_3 , V_4 ) ;
if ( V_21 < 0 )
return V_21 ;
switch ( V_3 ) {
case V_155 :
return F_14 ( V_2 , type , V_3 , V_4 , V_28 ) ;
case V_156 :
return F_17 ( V_2 , type ) ;
case V_5 :
return F_18 ( V_2 , type , V_34 ) ;
case V_7 :
return F_24 ( V_2 , type , V_34 ) ;
case V_157 :
return F_25 ( V_2 , type , V_34 ) ;
case V_11 :
return F_30 ( V_2 , type , V_4 , V_34 ) ;
case V_158 :
return F_34 ( V_2 , type , V_4 , V_34 ) ;
case V_6 :
if ( ! V_2 -> V_18 -> V_19 )
return - V_31 ;
return V_2 -> V_18 -> V_19 ( V_2 , type ) ;
case V_159 :
return V_30 ( V_2 , V_34 ) ;
case V_160 :
return V_33 ( V_2 , V_34 ) ;
case V_161 :
return F_43 ( V_2 , V_34 ) ;
case V_8 :
return F_35 ( V_2 , V_34 ) ;
case V_9 :
return F_36 ( V_2 , V_34 ) ;
case V_162 :
return F_40 ( V_2 , type , V_4 , V_34 ) ;
case V_12 :
return F_42 ( V_2 , type , V_4 , V_34 ) ;
case V_10 :
if ( V_2 -> V_163 & V_164 )
return - V_165 ;
return 0 ;
default:
return - V_23 ;
}
}
static int F_46 ( int V_3 )
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
static struct V_1 * F_47 ( const char T_2 * V_166 , int V_3 )
{
#ifdef F_48
struct V_167 * V_168 ;
struct V_1 * V_2 ;
struct V_169 * V_170 = F_49 ( V_166 ) ;
if ( F_15 ( V_170 ) )
return F_50 ( V_170 ) ;
V_168 = F_51 ( V_170 -> V_171 ) ;
F_52 ( V_170 ) ;
if ( F_15 ( V_168 ) )
return F_50 ( V_168 ) ;
if ( F_46 ( V_3 ) )
V_2 = F_53 ( V_168 ) ;
else
V_2 = F_54 ( V_168 ) ;
F_55 ( V_168 ) ;
if ( ! V_2 )
return F_56 ( - V_172 ) ;
return V_2 ;
#else
return F_56 ( - V_172 ) ;
#endif
}
