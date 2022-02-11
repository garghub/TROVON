struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( V_4 + V_3 -> V_6 + V_3 -> V_7 ,
V_8 ) ;
if ( V_5 )
F_3 ( V_5 , V_3 -> V_6 ) ;
return V_5 ;
}
void F_4 ( struct V_1 * V_5 , T_1 V_9 , T_2 V_10 ,
T_3 V_11 , T_3 V_12 )
{
T_2 V_13 ;
V_13 = V_9 ( V_10 , V_5 -> V_14 , V_5 -> V_4 ) ;
if ( V_11 )
V_13 = ~ V_13 ;
if ( V_12 )
V_13 = F_5 ( V_13 ) ;
* F_6 ( V_5 , 1 ) = V_13 & 0xFF ;
* F_6 ( V_5 , 1 ) = ( V_13 >> 8 ) & 0xFF ;
}
int F_7 ( struct V_1 * V_5 , T_1 V_9 ,
T_2 V_15 , T_3 V_11 , T_3 V_12 )
{
int V_16 ;
T_2 V_13 ;
if ( V_5 -> V_4 <= 2 )
return - V_17 ;
V_13 = V_9 ( V_15 , V_5 -> V_14 , V_5 -> V_4 - 2 ) ;
if ( V_11 )
V_13 = ~ V_13 ;
if ( V_12 )
V_13 = F_8 ( V_13 ) ;
V_16 = ( V_5 -> V_14 [ V_5 -> V_4 - 2 ] - ( V_13 & 0xFF ) ) +
( V_5 -> V_14 [ V_5 -> V_4 - 1 ] - ( ( V_13 >> 8 ) & 0xFF ) ) ;
if ( V_16 )
return - V_17 ;
F_9 ( V_5 , V_5 -> V_4 - 2 ) ;
return 0 ;
}
static inline void F_10 ( struct V_2 * V_3 , bool V_18 )
{
V_3 -> V_19 -> V_20 ( V_3 , V_18 ) ;
}
static inline void F_11 ( struct V_2 * V_3 )
{
V_3 -> V_19 -> V_21 ( V_3 ) ;
}
static void F_12 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
struct V_2 * V_3 = F_13 ( V_23 ,
struct V_2 ,
V_26 ) ;
F_14 ( & V_3 -> V_27 ) ;
V_25 = F_15 ( & V_3 -> V_28 , struct V_24 ,
V_29 ) ;
if ( ! V_25 ) {
F_16 ( & V_3 -> V_27 ) ;
return;
}
F_17 ( & V_25 -> V_29 ) ;
F_16 ( & V_3 -> V_27 ) ;
if ( ! F_18 ( V_25 -> V_30 ) )
F_19 ( L_1 , V_31 , 16 , 1 ,
V_25 -> V_30 -> V_14 , V_25 -> V_30 -> V_4 , false ) ;
V_25 -> V_32 ( V_3 , V_25 -> V_33 , V_25 -> V_30 ) ;
F_20 ( V_25 -> V_34 ) ;
F_20 ( V_25 ) ;
F_21 ( & V_3 -> V_35 ) ;
}
static void F_22 ( struct V_2 * V_3 ,
void * V_36 , struct V_1 * V_30 )
{
struct V_24 * V_25 = V_36 ;
V_25 -> V_30 = V_30 ;
F_21 ( & V_3 -> V_26 ) ;
}
static void F_23 ( struct V_22 * V_23 )
{
int V_16 ;
struct V_24 * V_25 ;
struct V_37 * V_38 ;
struct V_2 * V_3 = F_13 ( V_23 ,
struct V_2 ,
V_35 ) ;
F_14 ( & V_3 -> V_27 ) ;
V_25 = F_15 ( & V_3 -> V_28 , struct V_24 ,
V_29 ) ;
if ( ! V_25 || V_25 -> V_39 ) {
F_16 ( & V_3 -> V_27 ) ;
return;
}
F_16 ( & V_3 -> V_27 ) ;
if ( V_25 -> V_40 )
F_19 ( L_2 , V_31 , 16 , 1 ,
V_25 -> V_40 -> V_14 , V_25 -> V_40 -> V_4 , false ) ;
switch ( V_25 -> type ) {
case V_41 :
V_16 = V_3 -> V_19 -> V_42 ( V_3 , V_25 -> V_40 , V_25 -> V_43 ,
F_22 , V_25 ) ;
break;
case V_44 :
V_16 = V_3 -> V_19 -> V_45 ( V_3 , V_25 -> V_40 , V_25 -> V_43 ,
F_22 , V_25 ) ;
break;
case V_46 :
V_16 = V_3 -> V_19 -> V_47 ( V_3 , V_25 -> V_43 ,
F_22 , V_25 ) ;
break;
case V_48 :
V_38 = V_25 -> V_34 ;
V_16 = V_3 -> V_19 -> V_49 ( V_3 , V_38 , V_25 -> V_43 ,
F_22 , V_25 ) ;
break;
case V_50 :
V_16 = V_3 -> V_19 -> V_51 ( V_3 , V_25 -> V_43 ,
F_22 , V_25 ) ;
break;
default:
F_24 ( L_3 , V_25 -> type ) ;
return;
}
if ( ! V_16 )
return;
F_24 ( L_4 , V_16 ) ;
F_14 ( & V_3 -> V_27 ) ;
F_17 ( & V_25 -> V_29 ) ;
F_16 ( & V_3 -> V_27 ) ;
F_25 ( V_25 -> V_40 ) ;
F_20 ( V_25 -> V_34 ) ;
F_20 ( V_25 ) ;
F_21 ( & V_3 -> V_35 ) ;
}
int F_26 ( struct V_2 * V_3 , T_3 V_52 ,
struct V_1 * V_5 , struct V_37 * V_38 ,
T_2 V_43 , T_4 V_32 ,
void * V_33 )
{
struct V_24 * V_25 ;
V_25 = F_27 ( sizeof( struct V_24 ) , V_8 ) ;
if ( ! V_25 )
return - V_53 ;
V_25 -> type = V_52 ;
V_25 -> V_43 = V_43 ;
V_25 -> V_40 = V_5 ;
V_25 -> V_34 = V_38 ;
V_25 -> V_32 = V_32 ;
V_25 -> V_33 = V_33 ;
F_28 ( & V_25 -> V_29 ) ;
F_14 ( & V_3 -> V_27 ) ;
F_29 ( & V_25 -> V_29 , & V_3 -> V_28 ) ;
F_16 ( & V_3 -> V_27 ) ;
F_21 ( & V_3 -> V_35 ) ;
return 0 ;
}
int F_30 ( struct V_2 * V_3 , int type , int V_54 )
{
int V_16 ;
V_16 = V_3 -> V_19 -> V_55 ( V_3 , type , V_54 ) ;
if ( V_16 )
F_24 ( L_5 , V_16 ) ;
return V_16 ;
}
int F_31 ( struct V_2 * V_3 , int type , int V_54 )
{
int V_16 ;
V_16 = V_3 -> V_19 -> V_56 ( V_3 , type , V_54 ) ;
if ( V_16 )
F_24 ( L_6 , V_16 ) ;
return V_16 ;
}
static int F_32 ( struct V_2 * V_3 , T_3 V_57 )
{
struct V_37 * V_38 ;
V_38 = F_27 ( sizeof( struct V_37 ) , V_8 ) ;
if ( ! V_38 )
return - V_53 ;
V_38 -> V_58 = V_59 ;
F_33 ( V_38 -> V_60 , sizeof( V_38 -> V_60 ) ) ;
V_38 -> V_61 = V_62 ;
V_38 -> V_63 [ 0 ] = V_64 ;
V_38 -> V_63 [ 1 ] = V_65 ;
F_33 ( V_38 -> V_63 + 2 , V_66 - 2 ) ;
V_38 -> V_67 = V_68 ;
return F_26 ( V_3 , V_48 , NULL , V_38 ,
500 , V_69 , NULL ) ;
}
static int F_34 ( struct V_2 * V_3 , T_3 V_57 )
{
return F_26 ( V_3 , V_50 , NULL , NULL , 500 ,
V_70 , NULL ) ;
}
int F_35 ( struct V_2 * V_3 ,
struct V_71 * V_72 , T_3 V_73 )
{
int V_16 ;
T_3 V_74 ;
T_3 V_57 ;
T_3 V_75 ;
int (* F_36)( struct V_1 * V_5 );
void (* F_37)( struct V_1 * V_5 );
V_57 = V_3 -> V_76 [ V_3 -> V_77 ] . V_57 ;
switch ( V_73 ) {
case V_78 :
V_74 = V_79 ;
F_36 = V_80 ;
F_37 = V_81 ;
break;
case V_82 :
V_74 = V_83 ;
F_36 = V_84 ;
F_37 = V_85 ;
break;
case V_86 :
V_74 = V_87 ;
F_36 = V_88 ;
F_37 = V_89 ;
break;
case V_90 :
if ( V_57 == V_91 ) {
V_74 = V_92 ;
F_36 = V_84 ;
F_37 = V_85 ;
} else {
V_74 = V_93 ;
F_36 = V_88 ;
F_37 = V_89 ;
}
break;
case V_94 :
V_74 = V_95 ;
F_36 = V_80 ;
F_37 = V_81 ;
break;
case V_96 :
V_74 = V_97 ;
F_36 = V_84 ;
F_37 = V_85 ;
break;
case V_98 :
V_74 = V_99 ;
F_36 = V_80 ;
F_37 = V_81 ;
break;
default:
F_24 ( L_7 , V_73 ) ;
return - V_100 ;
}
F_38 ( L_8 , V_57 , V_73 ) ;
V_3 -> V_101 = V_57 ;
if ( F_39 ( V_3 ) ) {
V_3 -> V_102 = V_103 ;
V_3 -> V_104 = V_105 ;
} else {
V_3 -> V_102 = F_37 ;
V_3 -> V_104 = F_36 ;
}
V_16 = F_30 ( V_3 , V_106 , V_74 ) ;
if ( V_16 )
return V_16 ;
V_72 -> V_107 = ( 1 << V_73 ) ;
V_75 = V_3 -> V_75 ;
V_3 -> V_75 = 0 ;
V_16 = F_40 ( V_3 -> V_108 , V_72 , 1 ) ;
if ( V_16 ) {
V_3 -> V_75 = V_75 ;
return V_16 ;
}
return 0 ;
}
void F_41 ( struct V_2 * V_3 )
{
T_3 V_109 ;
F_10 ( V_3 , 0 ) ;
F_14 ( & V_3 -> V_110 ) ;
if ( ! V_3 -> V_75 ) {
F_16 ( & V_3 -> V_110 ) ;
return;
}
F_33 ( & V_109 , sizeof( V_109 ) ) ;
V_3 -> V_77 = V_109 % V_3 -> V_75 ;
F_16 ( & V_3 -> V_110 ) ;
F_21 ( & V_3 -> V_111 ) ;
}
static void F_42 ( struct V_22 * V_23 )
{
int V_16 ;
struct V_112 * V_113 ;
struct V_2 * V_3 = F_13 ( V_23 ,
struct V_2 ,
V_111 ) ;
F_14 ( & V_3 -> V_110 ) ;
if ( ! V_3 -> V_75 ) {
F_16 ( & V_3 -> V_110 ) ;
return;
}
V_113 = & V_3 -> V_76 [ V_3 -> V_77 ] ;
F_16 ( & V_3 -> V_110 ) ;
V_16 = V_113 -> V_114 ( V_3 , V_113 -> V_57 ) ;
if ( V_16 )
F_41 ( V_3 ) ;
}
static void F_43 ( struct V_2 * V_3 , T_3 V_57 ,
T_5 V_114 )
{
struct V_112 * V_113 ;
if ( V_3 -> V_75 >= V_115 )
return;
V_113 = & V_3 -> V_76 [ V_3 -> V_75 ++ ] ;
V_113 -> V_57 = V_57 ;
V_113 -> V_114 = V_114 ;
}
static int F_44 ( struct V_108 * V_108 , T_6 V_116 ,
T_6 V_117 )
{
struct V_2 * V_3 = F_45 ( V_108 ) ;
T_7 V_118 , V_119 ;
F_38 ( L_9 , V_116 ,
V_117 , V_3 -> V_120 ) ;
V_118 = V_3 -> V_120 & V_116 ;
V_119 = V_3 -> V_120 & V_117 ;
if ( ! V_118 && ! V_119 ) {
F_24 ( L_10 ) ;
return - V_100 ;
}
if ( V_3 -> V_75 ) {
F_24 ( L_11 ) ;
return - V_121 ;
}
if ( V_3 -> V_122 ) {
F_24 ( L_12 ) ;
return - V_121 ;
}
V_3 -> V_75 = 0 ;
V_3 -> V_77 = 0 ;
if ( V_118 & V_123 )
F_43 ( V_3 , V_91 ,
V_124 ) ;
if ( V_118 & V_125 )
F_43 ( V_3 , V_126 ,
V_127 ) ;
if ( V_118 & V_128 ) {
F_43 ( V_3 , V_129 ,
V_130 ) ;
F_43 ( V_3 , V_131 ,
V_130 ) ;
}
if ( V_118 & V_132 )
F_43 ( V_3 , V_133 ,
V_134 ) ;
if ( V_119 & V_135 ) {
if ( V_3 -> V_19 -> V_49 ) {
F_43 ( V_3 , 0 ,
F_32 ) ;
} else if ( V_3 -> V_19 -> V_51 ) {
F_43 ( V_3 , 0 ,
F_34 ) ;
} else {
F_43 ( V_3 , V_91 ,
V_136 ) ;
F_43 ( V_3 , V_129 ,
V_137 ) ;
F_43 ( V_3 , V_131 ,
V_137 ) ;
}
}
if ( ! V_3 -> V_75 ) {
F_24 ( L_13 ,
V_118 , V_119 ) ;
return - V_100 ;
}
F_21 ( & V_3 -> V_111 ) ;
return 0 ;
}
static void F_46 ( struct V_108 * V_108 )
{
struct V_2 * V_3 = F_45 ( V_108 ) ;
F_14 ( & V_3 -> V_110 ) ;
if ( ! V_3 -> V_75 ) {
F_24 ( L_14 ) ;
F_16 ( & V_3 -> V_110 ) ;
return;
}
V_3 -> V_75 = 0 ;
F_16 ( & V_3 -> V_110 ) ;
F_47 ( & V_3 -> V_111 ) ;
F_11 ( V_3 ) ;
}
static int F_48 ( struct V_108 * V_108 )
{
struct V_2 * V_3 = F_45 ( V_108 ) ;
F_10 ( V_3 , 1 ) ;
return 0 ;
}
static int F_49 ( struct V_108 * V_108 )
{
struct V_2 * V_3 = F_45 ( V_108 ) ;
F_10 ( V_3 , 0 ) ;
return 0 ;
}
static int F_50 ( struct V_108 * V_108 ,
struct V_71 * V_72 ,
T_8 V_138 , T_8 * V_139 , T_9 V_140 )
{
struct V_2 * V_3 = F_45 ( V_108 ) ;
int V_16 ;
V_16 = F_51 ( V_3 , V_72 , V_138 , V_139 , V_140 ) ;
if ( ! V_16 )
V_3 -> V_122 = V_90 ;
return V_16 ;
}
static int F_52 ( struct V_108 * V_108 )
{
struct V_2 * V_3 = F_45 ( V_108 ) ;
V_3 -> V_122 = 0 ;
return 0 ;
}
static int F_53 ( struct V_108 * V_108 ,
struct V_71 * V_72 , T_6 V_73 )
{
struct V_2 * V_3 = F_45 ( V_108 ) ;
if ( V_3 -> V_75 ) {
F_24 ( L_15 ) ;
return - V_121 ;
}
if ( V_3 -> V_122 ) {
F_24 ( L_12 ) ;
return - V_121 ;
}
V_3 -> V_122 = V_73 ;
return 0 ;
}
static void F_54 ( struct V_108 * V_108 ,
struct V_71 * V_72 )
{
struct V_2 * V_3 = F_45 ( V_108 ) ;
if ( ! V_3 -> V_122 ) {
F_24 ( L_16 ) ;
return;
}
V_3 -> V_122 = 0 ;
}
static int F_55 ( struct V_108 * V_141 , struct V_1 * V_5 )
{
struct V_2 * V_3 = F_45 ( V_141 ) ;
return F_56 ( V_3 , V_5 ) ;
}
static void F_57 ( struct V_2 * V_3 , void * V_36 ,
struct V_1 * V_30 )
{
struct V_142 * V_143 = V_36 ;
int V_16 ;
if ( F_18 ( V_30 ) ) {
V_16 = F_58 ( V_30 ) ;
V_30 = NULL ;
goto V_144;
}
if ( V_3 -> V_122 == V_82 ) {
V_16 = F_59 ( V_30 ) ;
goto V_144;
}
if ( ( V_3 -> V_122 == V_96 ) ||
( V_3 -> V_122 == V_98 ) ) {
V_16 = F_60 ( V_3 , V_30 ) ;
if ( V_16 )
goto V_144;
}
V_16 = V_3 -> V_104 ( V_30 ) ;
V_144:
if ( V_16 ) {
F_25 ( V_30 ) ;
V_30 = NULL ;
}
V_143 -> V_145 ( V_143 -> V_33 , V_30 , V_16 ) ;
F_20 ( V_143 ) ;
}
static int F_61 ( struct V_108 * V_108 , struct V_71 * V_72 ,
struct V_1 * V_5 , T_10 V_145 ,
void * V_33 )
{
struct V_2 * V_3 = F_45 ( V_108 ) ;
struct V_142 * V_143 ;
int V_16 ;
V_143 = F_27 ( sizeof( struct V_142 ) , V_8 ) ;
if ( ! V_143 ) {
F_24 ( L_17 ) ;
return - V_53 ;
}
V_143 -> V_145 = V_145 ;
V_143 -> V_33 = V_33 ;
if ( V_3 -> V_122 == V_90 ) {
V_16 = F_62 ( V_3 , V_72 , V_5 , V_143 ) ;
goto exit;
}
if ( ( V_3 -> V_122 == V_96 ) ||
( V_3 -> V_122 == V_98 ) ) {
V_16 = F_63 ( V_3 , V_5 ) ;
if ( V_16 )
goto exit;
}
V_3 -> V_102 ( V_5 ) ;
V_16 = F_64 ( V_3 , V_5 , 500 , F_57 ,
V_143 ) ;
exit:
if ( V_16 )
F_20 ( V_143 ) ;
return V_16 ;
}
struct V_2 * F_65 ( struct V_146 * V_19 ,
T_6 V_107 ,
T_6 V_147 ,
int V_6 , int V_7 )
{
struct V_2 * V_3 ;
if ( ! V_19 -> V_55 || ! V_19 -> V_42 || ! V_19 -> V_47 ||
! V_19 -> V_56 || ! V_19 -> V_45 || ! V_19 -> V_21 ||
! V_19 -> V_20 || ( V_19 -> V_51 && ! V_19 -> V_148 ) )
return NULL ;
V_3 = F_27 ( sizeof( struct V_2 ) , V_8 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_147 = V_147 ;
V_3 -> V_19 = V_19 ;
F_66 ( & V_3 -> V_27 ) ;
F_28 ( & V_3 -> V_28 ) ;
F_67 ( & V_3 -> V_35 , F_23 ) ;
F_67 ( & V_3 -> V_26 , F_12 ) ;
F_66 ( & V_3 -> V_110 ) ;
F_67 ( & V_3 -> V_111 , F_42 ) ;
if ( V_107 & V_149 )
V_3 -> V_120 |= V_149 ;
if ( V_107 & V_150 )
V_3 -> V_120 |= V_150 ;
if ( V_107 & V_151 )
V_3 -> V_120 |= V_151 ;
if ( V_107 & V_135 )
V_3 -> V_120 |= V_135 ;
if ( V_107 & V_152 )
V_3 -> V_120 |= V_152 ;
if ( V_107 & V_153 )
V_3 -> V_120 |= V_153 ;
if ( V_107 & V_154 )
V_3 -> V_120 |= V_154 ;
V_3 -> V_6 = V_6 + V_155 ;
V_3 -> V_7 = V_7 + V_156 ;
V_3 -> V_108 = F_68 ( & V_157 , V_3 -> V_120 ,
V_3 -> V_6 ,
V_3 -> V_7 ) ;
if ( ! V_3 -> V_108 ) {
F_24 ( L_18 ) ;
goto V_158;
}
F_69 ( V_3 -> V_108 , V_3 ) ;
return V_3 ;
V_158:
F_20 ( V_3 ) ;
return NULL ;
}
void F_70 ( struct V_2 * V_3 )
{
F_71 ( V_3 -> V_108 ) ;
F_20 ( V_3 ) ;
}
int F_72 ( struct V_2 * V_3 )
{
return F_73 ( V_3 -> V_108 ) ;
}
void F_74 ( struct V_2 * V_3 )
{
struct V_24 * V_25 , * V_159 ;
F_75 ( V_3 -> V_108 ) ;
F_14 ( & V_3 -> V_110 ) ;
V_3 -> V_75 = 0 ;
F_16 ( & V_3 -> V_110 ) ;
F_47 ( & V_3 -> V_111 ) ;
F_47 ( & V_3 -> V_35 ) ;
F_47 ( & V_3 -> V_26 ) ;
F_76 (cmd, n, &ddev->cmd_queue, queue) {
F_17 ( & V_25 -> V_29 ) ;
F_20 ( V_25 -> V_34 ) ;
F_20 ( V_25 ) ;
}
}
