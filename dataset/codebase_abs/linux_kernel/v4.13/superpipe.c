static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = V_2 -> V_5 ;
V_4 -> V_6 = V_2 -> V_6 ;
V_4 -> V_7 = V_2 -> V_7 ;
}
static void F_2 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
V_2 -> V_5 = V_9 -> V_5 ;
V_2 -> V_6 = V_9 -> V_6 ;
}
static void F_3 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
V_2 -> V_5 = V_11 -> V_5 ;
V_2 -> V_6 = V_11 -> V_6 ;
V_2 -> V_7 = V_11 -> V_7 ;
}
void F_4 ( void )
{
F_5 ( & V_12 . V_13 ) ;
if ( V_12 . V_14 ) {
F_6 ( V_12 . V_14 ) ;
V_12 . V_14 = NULL ;
}
F_7 ( & V_12 . V_13 ) ;
}
void F_8 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
int V_19 , V_20 = true ;
F_9 ( V_16 ) ;
while ( true ) {
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ )
if ( V_16 -> V_22 [ V_19 ] ) {
V_20 = true ;
break;
}
if ( ! V_20 && F_10 ( & V_16 -> V_23 ) )
return;
F_11 ( V_18 , L_1 ,
V_24 ) ;
F_12 ( & V_16 -> V_25 ) ;
F_13 ( 1 ) ;
V_20 = false ;
}
}
static struct V_26 * F_14 ( struct V_15 * V_16 , T_1 V_27 ,
struct V_28 * V_28 )
{
struct V_26 * V_29 ;
F_15 (ctxi, &cfg->ctx_err_recovery, list)
if ( ( V_29 -> V_30 == V_27 ) || ( V_29 -> V_28 == V_28 ) )
return V_29 ;
return NULL ;
}
struct V_26 * F_16 ( struct V_15 * V_16 , T_1 V_27 ,
void * V_31 , enum V_32 V_32 )
{
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
struct V_26 * V_29 = NULL ;
struct V_33 * V_33 = NULL ;
struct V_28 * V_28 = NULL ;
struct V_34 * V_35 = V_31 ;
T_1 V_30 = F_17 ( V_27 ) ;
int V_36 ;
T_2 V_37 = V_38 -> V_39 , V_40 = 0 ;
if ( V_32 & V_41 ) {
V_35 = NULL ;
V_28 = (struct V_28 * ) V_31 ;
}
if ( V_32 & V_42 )
V_37 = V_38 -> V_43 -> V_39 ;
if ( F_18 ( V_30 < V_21 ) ) {
while ( true ) {
F_5 ( & V_16 -> V_44 ) ;
V_29 = V_16 -> V_22 [ V_30 ] ;
if ( V_29 )
if ( ( V_28 && ( V_29 -> V_28 != V_28 ) ) ||
( ! V_28 && ( V_29 -> V_30 != V_27 ) ) )
V_29 = NULL ;
if ( ( V_32 & V_45 ) ||
( ! V_29 && ( V_32 & V_46 ) ) )
V_29 = F_14 ( V_16 , V_27 , V_28 ) ;
if ( ! V_29 ) {
F_7 ( & V_16 -> V_44 ) ;
goto V_47;
}
V_36 = F_19 ( & V_29 -> V_13 ) ;
F_7 ( & V_16 -> V_44 ) ;
if ( V_36 )
break;
}
if ( V_29 -> V_48 )
goto V_49;
V_40 = V_29 -> V_37 ;
if ( F_18 ( ! ( V_32 & V_50 ) ) )
if ( V_37 != V_40 )
goto V_49;
if ( V_35 ) {
F_15 (lun_access, &ctxi->luns, list)
if ( V_33 -> V_35 == V_35 )
goto V_47;
goto V_49;
}
}
V_47:
F_11 ( V_18 , L_2
L_3 , V_24 , V_27 , V_29 , V_40 , V_37 ,
V_32 ) ;
return V_29 ;
V_49:
F_7 ( & V_29 -> V_13 ) ;
V_29 = NULL ;
goto V_47;
}
void F_20 ( struct V_26 * V_29 )
{
F_7 ( & V_29 -> V_13 ) ;
}
static int F_21 ( struct V_15 * V_16 , struct V_26 * V_29 )
{
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
struct V_51 * V_51 = V_16 -> V_51 ;
struct V_52 T_3 * V_53 = V_29 -> V_53 ;
int V_36 = 0 ;
struct V_54 * V_54 = F_22 ( V_51 , V_55 ) ;
T_1 V_56 ;
F_23 ( & V_53 -> V_57 ) ;
V_56 = ( V_58 | V_59 ) ;
F_24 ( V_56 , & V_53 -> V_60 ) ;
V_56 = F_23 ( & V_53 -> V_60 ) ;
if ( V_56 != ( V_58 | V_59 ) ) {
F_25 ( V_18 , L_4 ,
V_24 , V_56 ) ;
V_36 = - V_61 ;
goto V_47;
}
F_24 ( ( T_1 ) V_29 -> V_62 , & V_53 -> V_62 ) ;
V_56 = F_26 ( ( T_1 ) V_63 , ( T_1 ) ( V_54 -> V_64 ) ) ;
F_24 ( V_56 , & V_53 -> V_65 ) ;
V_47:
F_11 ( V_18 , L_5 , V_24 , V_36 ) ;
return V_36 ;
}
static int F_27 ( struct V_66 * V_67 , struct V_34 * V_35 )
{
struct V_15 * V_16 = F_28 ( V_67 -> V_68 ) ;
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
struct V_69 * V_70 = V_35 -> V_43 ;
struct V_71 V_72 ;
T_4 * V_73 = NULL ;
T_4 * V_74 = NULL ;
T_4 * V_75 = NULL ;
int V_36 = 0 ;
int V_76 = 0 ;
int V_77 = 0 ;
T_5 V_78 = V_79 * V_80 ;
V_81:
V_73 = F_29 ( V_82 , V_83 ) ;
V_74 = F_29 ( V_84 , V_83 ) ;
V_75 = F_29 ( V_85 , V_83 ) ;
if ( F_30 ( ! V_73 || ! V_74 || ! V_75 ) ) {
V_36 = - V_86 ;
goto V_47;
}
V_74 [ 0 ] = V_87 ;
V_74 [ 1 ] = V_88 ;
F_31 ( V_82 , & V_74 [ 10 ] ) ;
F_11 ( V_18 , L_6 , V_24 ,
V_77 ? L_7 : L_8 , V_74 [ 0 ] ) ;
F_32 ( & V_16 -> V_89 ) ;
V_76 = F_33 ( V_67 , V_74 , V_90 , V_73 ,
V_82 , V_75 , & V_72 , V_78 , V_91 ,
0 , 0 , NULL ) ;
F_34 ( & V_16 -> V_89 ) ;
V_36 = F_35 ( V_16 ) ;
if ( V_36 ) {
F_25 ( V_18 , L_9 ,
V_24 , V_76 ) ;
V_36 = - V_92 ;
goto V_47;
}
if ( F_36 ( V_76 ) == V_93 ) {
V_76 &= ~ ( 0xFF << 24 ) ;
if ( V_76 & V_94 ) {
switch ( V_72 . V_95 ) {
case V_96 :
case V_97 :
case V_98 :
V_76 &= ~ V_94 ;
break;
case V_99 :
switch ( V_72 . V_100 ) {
case 0x29 :
case 0x2A :
case 0x3F :
if ( V_77 ++ < 1 ) {
F_37 ( V_73 ) ;
F_37 ( V_74 ) ;
F_37 ( V_75 ) ;
goto V_81;
}
}
break;
default:
break;
}
}
}
if ( V_76 ) {
F_25 ( V_18 , L_10 ,
V_24 , V_76 ) ;
V_36 = - V_101 ;
goto V_47;
}
F_5 ( & V_70 -> V_13 ) ;
V_70 -> V_102 = F_38 ( * ( ( V_103 * ) & V_73 [ 0 ] ) ) ;
V_70 -> V_104 = F_39 ( * ( ( V_105 * ) & V_73 [ 8 ] ) ) ;
F_7 ( & V_70 -> V_13 ) ;
V_47:
F_37 ( V_73 ) ;
F_37 ( V_74 ) ;
F_37 ( V_75 ) ;
F_11 ( V_18 , L_11 ,
V_24 , V_70 -> V_102 , V_70 -> V_104 , V_36 ) ;
return V_36 ;
}
struct V_106 * F_40 ( struct V_26 * V_29 , T_6 V_107 ,
struct V_34 * V_35 )
{
struct V_15 * V_16 = V_29 -> V_16 ;
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
struct V_106 * V_108 = NULL ;
if ( F_30 ( ! V_29 -> V_62 ) ) {
F_11 ( V_18 , L_12 ,
V_24 ) ;
goto V_47;
}
if ( F_30 ( V_107 >= V_63 ) ) {
F_11 ( V_18 , L_13 ,
V_24 , V_107 ) ;
goto V_47;
}
if ( F_30 ( V_29 -> V_109 [ V_107 ] != V_35 ) ) {
F_11 ( V_18 , L_14 ,
V_24 , V_107 ) ;
goto V_47;
}
V_108 = & V_29 -> V_62 [ V_107 ] ;
if ( F_30 ( V_108 -> V_110 == 0 ) ) {
F_11 ( V_18 , L_15 ,
V_24 , V_107 ) ;
V_108 = NULL ;
goto V_47;
}
V_47:
return V_108 ;
}
struct V_106 * F_41 ( struct V_26 * V_29 ,
struct V_34 * V_35 )
{
struct V_15 * V_16 = V_29 -> V_16 ;
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
struct V_106 * V_108 = NULL ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_63 ; V_19 ++ )
if ( V_29 -> V_62 [ V_19 ] . V_110 == 0 ) {
V_108 = & V_29 -> V_62 [ V_19 ] ;
V_29 -> V_111 ++ ;
break;
}
if ( F_18 ( V_108 ) )
V_29 -> V_109 [ V_19 ] = V_35 ;
F_11 ( V_18 , L_16 , V_24 , V_108 , V_19 ) ;
return V_108 ;
}
void F_42 ( struct V_26 * V_29 ,
struct V_106 * V_108 )
{
T_5 V_7 = V_108 - V_29 -> V_62 ;
V_108 -> V_110 = 0 ;
V_108 -> V_112 = 0 ;
V_29 -> V_111 -- ;
V_29 -> V_109 [ V_7 ] = NULL ;
V_29 -> V_113 [ V_7 ] = false ;
}
static void F_43 ( struct V_106 * V_108 , T_1 V_114 , T_5 V_115 ,
T_5 V_116 )
{
struct V_117 V_118 = { 0 } ;
struct V_117 * V_119 = (struct V_117 * ) V_108 ;
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
V_119 -> V_112 = F_44 ( 1U , 0 ) ;
F_45 () ;
V_119 -> V_114 = V_114 ;
F_45 () ;
V_118 . V_120 = 0x80 ;
V_118 . V_112 = F_44 ( 1U , V_115 ) ;
V_118 . V_116 = V_116 ;
V_119 -> V_121 = V_118 . V_121 ;
F_45 () ;
}
int F_46 ( struct V_69 * V_70 , enum V_122 V_123 , bool V_124 )
{
int V_36 = 0 ;
if ( ! V_124 )
F_5 ( & V_70 -> V_13 ) ;
if ( V_70 -> V_123 == V_125 )
V_70 -> V_123 = V_123 ;
else if ( V_70 -> V_123 != V_123 ) {
F_47 ( L_17 ,
V_24 , V_70 -> V_123 , V_123 ) ;
V_36 = - V_126 ;
goto V_47;
}
V_70 -> V_127 ++ ;
F_48 ( V_70 -> V_127 <= 0 ) ;
V_47:
F_47 ( L_18 ,
V_24 , V_36 , V_70 -> V_123 , V_70 -> V_127 ) ;
if ( ! V_124 )
F_7 ( & V_70 -> V_13 ) ;
return V_36 ;
}
void F_49 ( struct V_69 * V_70 )
{
F_5 ( & V_70 -> V_13 ) ;
F_48 ( V_70 -> V_123 == V_125 ) ;
if ( -- V_70 -> V_127 == 0 ) {
V_70 -> V_123 = V_125 ;
F_50 ( & V_70 -> V_128 . V_129 ) ;
}
F_47 ( L_19 , V_24 , V_70 -> V_127 ) ;
F_48 ( V_70 -> V_127 < 0 ) ;
F_7 ( & V_70 -> V_13 ) ;
}
int F_51 ( struct V_66 * V_67 ,
struct V_26 * V_29 ,
struct V_1 * V_2 )
{
struct V_15 * V_16 = F_28 ( V_67 -> V_68 ) ;
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
struct V_34 * V_35 = V_67 -> V_130 ;
struct V_69 * V_70 = V_35 -> V_43 ;
struct V_51 * V_51 = V_16 -> V_51 ;
bool V_131 = false ;
struct V_3 V_132 ;
T_6 V_107 = V_2 -> V_7 ;
int V_36 = 0 ;
int V_133 = 0 ;
T_1 V_30 = F_17 ( V_2 -> V_6 ) ,
V_27 = V_2 -> V_6 ;
struct V_106 * V_108 ;
struct V_117 * V_119 ;
F_11 ( V_18 , L_20 ,
V_24 , V_30 , V_2 -> V_7 , V_70 -> V_123 , V_70 -> V_127 ) ;
if ( ! V_29 ) {
V_29 = F_16 ( V_16 , V_27 , V_35 , V_46 ) ;
if ( F_30 ( ! V_29 ) ) {
F_11 ( V_18 , L_21 ,
V_24 , V_30 ) ;
V_36 = - V_126 ;
goto V_47;
}
V_131 = true ;
}
V_108 = F_40 ( V_29 , V_107 , V_35 ) ;
if ( F_30 ( ! V_108 ) ) {
F_11 ( V_18 , L_13 ,
V_24 , V_107 ) ;
V_36 = - V_126 ;
goto V_47;
}
switch ( V_70 -> V_123 ) {
case V_134 :
F_1 ( V_2 , & V_132 ) ;
V_132 . V_135 = 0 ;
V_36 = F_52 ( V_67 , V_29 , & V_132 ) ;
if ( V_36 ) {
F_11 ( V_18 , L_22 , V_24 , V_36 ) ;
goto V_47;
}
break;
case V_136 :
V_119 = (struct V_117 * ) V_108 ;
V_119 -> V_120 = 0 ;
F_45 () ;
V_119 -> V_114 = 0 ;
F_45 () ;
V_119 -> V_121 = 0 ;
F_45 () ;
if ( ! V_29 -> V_137 ) {
V_133 = F_53 ( V_51 , V_30 , V_107 , V_138 ) ;
if ( F_30 ( V_133 ) )
F_11 ( V_18 , L_23 ,
V_24 , V_133 ) ;
}
break;
default:
F_54 ( 1 , L_24 ) ;
goto V_47;
}
F_42 ( V_29 , V_108 ) ;
F_49 ( V_70 ) ;
V_47:
if ( V_131 )
F_20 ( V_29 ) ;
F_11 ( V_18 , L_5 , V_24 , V_36 ) ;
return V_36 ;
}
int F_55 ( struct V_66 * V_67 ,
struct V_1 * V_2 )
{
return F_51 ( V_67 , NULL , V_2 ) ;
}
static void F_56 ( struct V_15 * V_16 ,
struct V_26 * V_29 )
{
struct V_51 * V_51 = V_16 -> V_51 ;
if ( V_29 -> V_139 ) {
F_48 ( ! F_10 ( & V_29 -> V_140 ) ) ;
if ( V_51 -> V_141 && V_29 -> V_53 ) {
F_24 ( 0 , & V_29 -> V_53 -> V_62 ) ;
F_24 ( 0 , & V_29 -> V_53 -> V_65 ) ;
F_24 ( 0 , & V_29 -> V_53 -> V_60 ) ;
}
}
F_57 ( ( V_142 ) V_29 -> V_62 ) ;
F_37 ( V_29 -> V_113 ) ;
F_37 ( V_29 -> V_109 ) ;
F_37 ( V_29 ) ;
}
static struct V_26 * F_58 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
struct V_26 * V_29 = NULL ;
struct V_34 * * V_35 = NULL ;
T_4 * V_143 = NULL ;
struct V_106 * V_108 ;
V_29 = F_29 ( sizeof( * V_29 ) , V_83 ) ;
V_35 = F_29 ( ( V_63 * sizeof( * V_35 ) ) , V_83 ) ;
V_143 = F_29 ( ( V_63 * sizeof( * V_143 ) ) , V_83 ) ;
if ( F_30 ( ! V_29 || ! V_35 || ! V_143 ) ) {
F_25 ( V_18 , L_25 , V_24 ) ;
goto V_144;
}
V_108 = (struct V_106 * ) F_59 ( V_83 ) ;
if ( F_30 ( ! V_108 ) ) {
F_25 ( V_18 , L_26 , V_24 ) ;
goto V_144;
}
V_29 -> V_109 = V_35 ;
V_29 -> V_113 = V_143 ;
V_29 -> V_62 = V_108 ;
V_47:
return V_29 ;
V_144:
F_37 ( V_143 ) ;
F_37 ( V_35 ) ;
F_37 ( V_29 ) ;
V_29 = NULL ;
goto V_47;
}
static void F_60 ( struct V_26 * V_29 , struct V_15 * V_16 ,
struct V_145 * V_146 , int V_30 , struct V_28 * V_28 ,
T_5 V_147 )
{
struct V_51 * V_51 = V_16 -> V_51 ;
V_29 -> V_148 = V_147 ;
V_29 -> V_53 = & V_51 -> V_141 -> V_149 [ V_30 ] . V_150 ;
V_29 -> V_30 = F_61 ( V_29 , V_30 ) ;
V_29 -> V_37 = V_38 -> V_39 ;
V_29 -> V_146 = V_146 ;
V_29 -> V_16 = V_16 ;
V_29 -> V_28 = V_28 ;
V_29 -> V_139 = true ;
F_62 ( & V_29 -> V_13 ) ;
F_63 ( & V_29 -> V_151 ) ;
F_64 ( & V_29 -> V_140 ) ;
F_64 ( & V_29 -> V_152 ) ;
}
static void F_65 ( struct V_151 * V_151 )
{
struct V_26 * V_29 = F_66 ( V_151 , struct V_26 , V_151 ) ;
struct V_15 * V_16 = V_29 -> V_16 ;
T_1 V_30 = F_17 ( V_29 -> V_30 ) ;
F_48 ( ! F_67 ( & V_29 -> V_13 ) ) ;
V_29 -> V_48 = true ;
F_7 ( & V_29 -> V_13 ) ;
F_5 ( & V_16 -> V_44 ) ;
F_5 ( & V_29 -> V_13 ) ;
if ( ! F_10 ( & V_29 -> V_152 ) )
F_68 ( & V_29 -> V_152 ) ;
V_16 -> V_22 [ V_30 ] = NULL ;
F_7 ( & V_16 -> V_44 ) ;
F_7 ( & V_29 -> V_13 ) ;
F_56 ( V_16 , V_29 ) ;
}
static int F_69 ( struct V_66 * V_67 ,
struct V_26 * V_29 ,
struct V_8 * V_9 )
{
struct V_15 * V_16 = F_28 ( V_67 -> V_68 ) ;
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
struct V_34 * V_35 = V_67 -> V_130 ;
struct V_33 * V_33 , * V_153 ;
struct V_1 V_154 ;
bool V_131 = false ;
int V_19 ;
int V_36 = 0 ;
T_1 V_30 = F_17 ( V_9 -> V_6 ) ,
V_27 = V_9 -> V_6 ;
F_11 ( V_18 , L_27 , V_24 , V_30 ) ;
if ( ! V_29 ) {
V_29 = F_16 ( V_16 , V_27 , V_35 , V_46 ) ;
if ( F_30 ( ! V_29 ) ) {
F_11 ( V_18 , L_21 ,
V_24 , V_30 ) ;
V_36 = - V_126 ;
goto V_47;
}
V_131 = true ;
}
if ( V_29 -> V_111 ) {
F_2 ( V_9 , & V_154 ) ;
for ( V_19 = 0 ; V_19 < V_63 ; V_19 ++ ) {
if ( V_29 -> V_109 [ V_19 ] == V_35 ) {
V_154 . V_7 = V_19 ;
F_51 ( V_67 , V_29 , & V_154 ) ;
}
if ( V_29 -> V_111 == 0 )
break;
}
}
F_70 (lun_access, t, &ctxi->luns, list)
if ( V_33 -> V_35 == V_35 ) {
F_68 ( & V_33 -> V_152 ) ;
F_37 ( V_33 ) ;
V_33 = NULL ;
break;
}
if ( F_71 ( & V_29 -> V_151 , F_65 ) )
V_131 = false ;
F_72 ( V_67 ) ;
V_47:
if ( V_131 )
F_20 ( V_29 ) ;
F_11 ( V_18 , L_5 , V_24 , V_36 ) ;
return V_36 ;
}
static int F_73 ( struct V_66 * V_67 ,
struct V_8 * V_9 )
{
return F_69 ( V_67 , NULL , V_9 ) ;
}
static int F_74 ( struct V_155 * V_155 , struct V_28 * V_28 )
{
struct V_145 * V_146 = F_75 ( V_28 ) ;
struct V_15 * V_16 = F_66 ( V_28 -> V_156 , struct V_15 ,
V_157 ) ;
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
struct V_26 * V_29 = NULL ;
struct V_8 V_9 = { { 0 } , 0 } ;
struct V_33 * V_33 , * V_153 ;
enum V_32 V_150 = V_46 | V_41 ;
int V_30 ;
V_30 = F_76 ( V_146 ) ;
if ( F_30 ( V_30 < 0 ) ) {
F_25 ( V_18 , L_28 ,
V_24 , V_146 , V_30 ) ;
goto V_47;
}
V_29 = F_16 ( V_16 , V_30 , V_28 , V_150 ) ;
if ( F_30 ( ! V_29 ) ) {
V_29 = F_16 ( V_16 , V_30 , V_28 , V_150 | V_42 ) ;
if ( ! V_29 ) {
F_11 ( V_18 , L_29 ,
V_24 , V_30 ) ;
goto V_158;
}
F_11 ( V_18 , L_30 ,
V_24 , V_30 ) ;
F_20 ( V_29 ) ;
goto V_47;
}
F_11 ( V_18 , L_31 , V_24 , V_30 ) ;
V_9 . V_6 = V_29 -> V_30 ;
F_70 (lun_access, t, &ctxi->luns, list)
F_69 ( V_33 -> V_67 , V_29 , & V_9 ) ;
V_158:
F_77 ( V_155 , V_28 ) ;
V_47:
F_11 ( V_18 , L_32 , V_24 ) ;
return 0 ;
}
static void F_78 ( struct V_26 * V_29 )
{
F_79 ( V_29 -> V_28 -> V_159 , 0 , 0 , 1 ) ;
}
static struct V_160 * F_80 ( struct V_15 * V_16 )
{
struct V_160 * V_14 = V_12 . V_14 ;
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
if ( F_30 ( ! V_14 ) ) {
V_14 = F_81 ( V_83 ) ;
if ( F_30 ( ! V_14 ) ) {
F_25 ( V_18 , L_33 ,
V_24 ) ;
goto V_47;
}
memset ( F_82 ( V_14 ) , - 1 , V_161 ) ;
F_5 ( & V_12 . V_13 ) ;
if ( F_18 ( ! V_12 . V_14 ) )
V_12 . V_14 = V_14 ;
else {
F_6 ( V_14 ) ;
V_14 = V_12 . V_14 ;
}
F_7 ( & V_12 . V_13 ) ;
}
V_47:
F_11 ( V_18 , L_34 , V_24 , V_14 ) ;
return V_14 ;
}
static int F_83 ( struct V_162 * V_163 )
{
struct V_164 * V_165 = V_163 -> V_165 ;
struct V_28 * V_28 = V_165 -> V_166 ;
struct V_145 * V_146 = F_75 ( V_28 ) ;
struct V_15 * V_16 = F_66 ( V_28 -> V_156 , struct V_15 ,
V_157 ) ;
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
struct V_26 * V_29 = NULL ;
struct V_160 * V_14 = NULL ;
enum V_32 V_150 = V_46 | V_41 ;
int V_36 = 0 ;
int V_30 ;
V_30 = F_76 ( V_146 ) ;
if ( F_30 ( V_30 < 0 ) ) {
F_25 ( V_18 , L_28 ,
V_24 , V_146 , V_30 ) ;
goto V_144;
}
V_29 = F_16 ( V_16 , V_30 , V_28 , V_150 ) ;
if ( F_30 ( ! V_29 ) ) {
F_11 ( V_18 , L_35 , V_24 , V_30 ) ;
goto V_144;
}
F_11 ( V_18 , L_36 , V_24 , V_30 ) ;
if ( F_18 ( ! V_29 -> V_137 ) ) {
V_165 -> V_167 = F_84 ( V_165 -> V_167 ) ;
V_36 = V_29 -> V_168 -> V_169 ( V_163 ) ;
} else {
F_11 ( V_18 , L_37 ,
V_24 ) ;
V_14 = F_80 ( V_16 ) ;
if ( F_30 ( ! V_14 ) ) {
F_25 ( V_18 , L_38 , V_24 ) ;
V_36 = V_170 ;
goto V_47;
}
F_85 ( V_14 ) ;
V_163 -> V_160 = V_14 ;
V_165 -> V_167 = F_86 ( V_165 -> V_167 ) ;
}
V_47:
if ( F_18 ( V_29 ) )
F_20 ( V_29 ) ;
F_11 ( V_18 , L_5 , V_24 , V_36 ) ;
return V_36 ;
V_144:
V_36 = V_171 ;
goto V_47;
}
static int F_87 ( struct V_28 * V_28 , struct V_164 * V_165 )
{
struct V_145 * V_146 = F_75 ( V_28 ) ;
struct V_15 * V_16 = F_66 ( V_28 -> V_156 , struct V_15 ,
V_157 ) ;
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
struct V_26 * V_29 = NULL ;
enum V_32 V_150 = V_46 | V_41 ;
int V_30 ;
int V_36 = 0 ;
V_30 = F_76 ( V_146 ) ;
if ( F_30 ( V_30 < 0 ) ) {
F_25 ( V_18 , L_28 ,
V_24 , V_146 , V_30 ) ;
V_36 = - V_101 ;
goto V_47;
}
V_29 = F_16 ( V_16 , V_30 , V_28 , V_150 ) ;
if ( F_30 ( ! V_29 ) ) {
F_11 ( V_18 , L_35 , V_24 , V_30 ) ;
V_36 = - V_101 ;
goto V_47;
}
F_11 ( V_18 , L_39 , V_24 , V_30 ) ;
V_36 = F_88 ( V_28 , V_165 ) ;
if ( F_18 ( ! V_36 ) ) {
V_29 -> V_168 = V_165 -> V_172 ;
V_165 -> V_172 = & V_173 ;
}
V_47:
if ( F_18 ( V_29 ) )
F_20 ( V_29 ) ;
return V_36 ;
}
int F_9 ( struct V_15 * V_16 )
{
int V_19 , V_36 = 0 ;
struct V_26 * V_29 = NULL ;
F_5 ( & V_16 -> V_44 ) ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
V_29 = V_16 -> V_22 [ V_19 ] ;
if ( V_29 ) {
F_5 ( & V_29 -> V_13 ) ;
V_16 -> V_22 [ V_19 ] = NULL ;
F_89 ( & V_29 -> V_152 , & V_16 -> V_23 ) ;
V_29 -> V_137 = true ;
V_29 -> V_53 = NULL ;
F_78 ( V_29 ) ;
F_7 ( & V_29 -> V_13 ) ;
}
}
F_7 ( & V_16 -> V_44 ) ;
return V_36 ;
}
int F_35 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
int V_36 = 0 ;
V_81:
switch ( V_16 -> V_174 ) {
case V_175 :
F_11 ( V_18 , L_40 , V_24 ) ;
F_32 ( & V_16 -> V_89 ) ;
V_36 = F_90 ( V_16 -> V_25 ,
V_16 -> V_174 != V_175 ) ;
F_34 ( & V_16 -> V_89 ) ;
if ( F_30 ( V_36 ) )
break;
goto V_81;
case V_176 :
F_11 ( V_18 , L_41 , V_24 ) ;
V_36 = - V_92 ;
break;
default:
break;
}
return V_36 ;
}
static int F_91 ( struct V_66 * V_67 ,
struct V_177 * V_178 )
{
struct V_15 * V_16 = F_28 ( V_67 -> V_68 ) ;
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
struct V_51 * V_51 = V_16 -> V_51 ;
struct V_34 * V_35 = V_67 -> V_130 ;
struct V_69 * V_70 = V_35 -> V_43 ;
struct V_179 * V_180 ;
struct V_26 * V_29 = NULL ;
struct V_33 * V_33 = NULL ;
int V_36 = 0 ;
T_5 V_147 ;
int V_30 = - 1 ;
T_1 V_181 = 0UL ;
T_1 V_27 = 0UL ;
struct V_28 * V_28 = NULL ;
struct V_145 * V_146 = NULL ;
int V_182 = - 1 ;
if ( V_178 -> V_183 > 4 ) {
F_11 ( V_18 , L_42 ,
V_24 , V_178 -> V_183 ) ;
V_36 = - V_126 ;
goto V_47;
}
if ( V_70 -> V_102 == 0 ) {
F_11 ( V_18 , L_43 ,
V_24 , V_35 -> V_114 [ V_67 -> V_184 ] ) ;
V_36 = F_27 ( V_67 , V_35 ) ;
if ( V_36 ) {
F_25 ( V_18 , L_44 ,
V_24 , V_36 ) ;
V_36 = - V_92 ;
goto V_47;
}
F_11 ( V_18 , L_45 , V_24 , V_70 -> V_102 ) ;
F_11 ( V_18 , L_46 , V_24 , V_70 -> V_104 ) ;
}
if ( V_178 -> V_5 . V_181 & V_185 ) {
V_27 = V_178 -> V_6 ;
V_29 = F_16 ( V_16 , V_27 , NULL , 0 ) ;
if ( ! V_29 ) {
F_11 ( V_18 , L_47 ,
V_24 , V_27 ) ;
V_36 = - V_126 ;
goto V_47;
}
F_15 (lun_access, &ctxi->luns, list)
if ( V_33 -> V_35 == V_35 ) {
F_11 ( V_18 , L_48 ,
V_24 ) ;
V_36 = - V_126 ;
goto V_47;
}
}
V_36 = F_92 ( V_67 ) ;
if ( F_30 ( V_36 ) ) {
F_25 ( V_18 , L_49 , V_24 ) ;
goto V_47;
}
V_33 = F_29 ( sizeof( * V_33 ) , V_83 ) ;
if ( F_30 ( ! V_33 ) ) {
F_25 ( V_18 , L_50 , V_24 ) ;
V_36 = - V_86 ;
goto V_144;
}
V_33 -> V_35 = V_35 ;
V_33 -> V_67 = V_67 ;
if ( V_29 ) {
F_11 ( V_18 , L_51 ,
V_24 , V_27 ) ;
F_93 ( & V_29 -> V_151 ) ;
F_89 ( & V_33 -> V_152 , & V_29 -> V_140 ) ;
goto V_186;
}
V_29 = F_58 ( V_16 ) ;
if ( F_30 ( ! V_29 ) ) {
F_25 ( V_18 , L_52 ,
V_24 , V_30 ) ;
goto V_144;
}
V_146 = F_94 ( V_16 -> V_18 ) ;
if ( F_95 ( V_146 ) ) {
F_25 ( V_18 , L_53 ,
V_24 , V_146 ) ;
V_36 = - V_92 ;
goto V_144;
}
V_180 = & V_29 -> V_180 ;
V_180 -> V_183 = V_178 -> V_183 ;
V_180 -> V_181 = V_187 ;
V_36 = F_96 ( V_146 , V_180 ) ;
if ( F_30 ( V_36 ) ) {
F_11 ( V_18 , L_54 ,
V_24 , V_36 ) ;
goto V_144;
}
V_30 = F_76 ( V_146 ) ;
if ( F_30 ( ( V_30 >= V_21 ) || ( V_30 < 0 ) ) ) {
F_25 ( V_18 , L_55 , V_24 , V_30 ) ;
V_36 = - V_188 ;
goto V_144;
}
V_28 = F_97 ( V_146 , & V_16 -> V_157 , & V_182 ) ;
if ( F_30 ( V_182 < 0 ) ) {
V_36 = - V_92 ;
F_25 ( V_18 , L_56 , V_24 ) ;
goto V_144;
}
V_147 = F_98 ( V_178 -> V_5 . V_181 + 1 ) ;
F_60 ( V_29 , V_16 , V_146 , V_30 , V_28 , V_147 ) ;
V_36 = F_21 ( V_16 , V_29 ) ;
if ( F_30 ( V_36 ) ) {
F_25 ( V_18 , L_57 , V_24 , V_36 ) ;
goto V_144;
}
F_89 ( & V_33 -> V_152 , & V_29 -> V_140 ) ;
F_5 ( & V_16 -> V_44 ) ;
F_5 ( & V_29 -> V_13 ) ;
V_16 -> V_22 [ V_30 ] = V_29 ;
F_7 ( & V_16 -> V_44 ) ;
F_99 ( V_182 , V_28 ) ;
V_186:
if ( V_182 != - 1 )
V_181 |= V_189 ;
if ( F_100 ( V_51 ) )
V_181 |= V_190 ;
V_178 -> V_5 . V_191 = V_181 ;
V_178 -> V_6 = V_29 -> V_30 ;
V_178 -> V_192 = V_70 -> V_104 ;
V_178 -> V_193 = sizeof( V_51 -> V_141 -> V_194 [ 0 ] . V_195 ) ;
V_178 -> V_196 = V_70 -> V_102 ;
V_178 -> V_197 = V_67 -> V_68 -> V_198 * V_199 ;
V_178 -> V_197 /= V_70 -> V_104 ;
V_47:
V_178 -> V_200 = V_182 ;
if ( V_29 )
F_20 ( V_29 ) ;
F_11 ( V_18 , L_58 ,
V_24 , V_30 , V_182 , V_178 -> V_192 , V_36 , V_178 -> V_196 ) ;
return V_36 ;
V_144:
if ( ! F_95 ( V_146 ) ) {
F_101 ( V_146 ) ;
F_102 ( V_146 ) ;
V_146 = NULL ;
}
if ( V_182 > 0 ) {
V_28 -> V_156 = & V_201 ;
F_103 ( V_28 ) ;
F_104 ( V_182 ) ;
V_182 = - 1 ;
V_28 = NULL ;
}
if ( V_29 ) {
F_56 ( V_16 , V_29 ) ;
V_29 = NULL ;
}
F_37 ( V_33 ) ;
F_72 ( V_67 ) ;
goto V_47;
}
static int F_105 ( struct V_15 * V_16 ,
struct V_26 * V_29 ,
int * V_200 )
{
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
int V_36 = 0 ;
int V_182 = - 1 ;
int V_30 = - 1 ;
struct V_28 * V_28 ;
struct V_145 * V_146 ;
struct V_51 * V_51 = V_16 -> V_51 ;
V_146 = F_94 ( V_16 -> V_18 ) ;
if ( F_95 ( V_146 ) ) {
F_25 ( V_18 , L_53 ,
V_24 , V_146 ) ;
V_36 = - V_92 ;
goto V_47;
}
V_36 = F_96 ( V_146 , & V_29 -> V_180 ) ;
if ( F_30 ( V_36 ) ) {
F_11 ( V_18 , L_54 ,
V_24 , V_36 ) ;
goto V_202;
}
V_30 = F_76 ( V_146 ) ;
if ( F_30 ( ( V_30 >= V_21 ) || ( V_30 < 0 ) ) ) {
F_25 ( V_18 , L_55 , V_24 , V_30 ) ;
V_36 = - V_188 ;
goto V_203;
}
V_28 = F_97 ( V_146 , & V_16 -> V_157 , & V_182 ) ;
if ( F_30 ( V_182 < 0 ) ) {
V_36 = - V_92 ;
F_25 ( V_18 , L_56 , V_24 ) ;
goto V_203;
}
V_29 -> V_53 = & V_51 -> V_141 -> V_149 [ V_30 ] . V_150 ;
V_36 = F_21 ( V_16 , V_29 ) ;
if ( V_36 ) {
F_25 ( V_18 , L_57 , V_24 , V_36 ) ;
goto V_204;
}
V_29 -> V_30 = F_61 ( V_29 , V_30 ) ;
V_29 -> V_146 = V_146 ;
V_29 -> V_28 = V_28 ;
F_7 ( & V_29 -> V_13 ) ;
F_5 ( & V_16 -> V_44 ) ;
F_5 ( & V_29 -> V_13 ) ;
F_106 ( & V_29 -> V_152 ) ;
V_16 -> V_22 [ V_30 ] = V_29 ;
F_7 ( & V_16 -> V_44 ) ;
F_99 ( V_182 , V_28 ) ;
* V_200 = V_182 ;
V_47:
F_11 ( V_18 , L_59 ,
V_24 , V_30 , V_182 , V_36 ) ;
return V_36 ;
V_204:
F_103 ( V_28 ) ;
F_104 ( V_182 ) ;
V_203:
F_101 ( V_146 ) ;
V_202:
F_102 ( V_146 ) ;
goto V_47;
}
static int F_107 ( struct V_66 * V_67 ,
struct V_205 * V_206 )
{
struct V_15 * V_16 = F_28 ( V_67 -> V_68 ) ;
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
struct V_34 * V_35 = V_67 -> V_130 ;
struct V_51 * V_51 = V_16 -> V_51 ;
struct V_26 * V_29 = NULL ;
struct V_13 * V_13 = & V_16 -> V_207 ;
struct V_54 * V_54 = F_22 ( V_51 , V_55 ) ;
T_1 V_181 ;
T_1 V_30 = F_17 ( V_206 -> V_6 ) ,
V_27 = V_206 -> V_6 ;
long V_208 ;
int V_209 = 20 ;
int V_210 = - 1 ;
int V_36 = 0 ;
F_108 ( & V_16 -> V_211 ) ;
F_32 ( & V_16 -> V_89 ) ;
V_36 = F_109 ( V_13 ) ;
F_34 ( & V_16 -> V_89 ) ;
if ( V_36 )
goto V_47;
V_36 = F_35 ( V_16 ) ;
if ( V_36 ) {
F_25 ( V_18 , L_60 , V_24 , V_36 ) ;
V_36 = - V_92 ;
goto V_47;
}
F_11 ( V_18 , L_61 ,
V_24 , V_206 -> V_212 , V_27 ) ;
V_81:
V_29 = F_16 ( V_16 , V_27 , V_35 , V_46 ) ;
if ( F_30 ( ! V_29 ) ) {
F_11 ( V_18 , L_21 , V_24 , V_30 ) ;
V_36 = - V_126 ;
goto V_47;
}
if ( V_29 -> V_137 ) {
V_213:
V_36 = F_105 ( V_16 , V_29 , & V_210 ) ;
if ( F_30 ( V_36 ) ) {
F_25 ( V_18 , L_62 ,
V_24 , V_30 , V_36 ) ;
if ( ( V_36 == - V_92 ) &&
( ( F_110 ( & V_16 -> V_211 ) > 1 ) ||
( V_209 -- ) ) ) {
F_11 ( V_18 , L_63 ,
V_24 ) ;
F_7 ( V_13 ) ;
F_111 ( 100 ) ;
V_36 = F_109 ( V_13 ) ;
if ( V_36 )
goto V_47;
goto V_213;
}
goto V_47;
}
V_29 -> V_137 = false ;
V_181 = V_189 |
V_214 ;
if ( F_100 ( V_51 ) )
V_181 |= V_190 ;
V_206 -> V_5 . V_191 = V_181 ;
V_206 -> V_6 = V_29 -> V_30 ;
V_206 -> V_200 = V_210 ;
V_206 -> V_193 = sizeof( V_51 -> V_141 -> V_194 [ 0 ] . V_195 ) ;
goto V_47;
}
V_208 = F_23 ( & V_54 -> V_53 -> V_57 ) ;
if ( V_208 == - 1 ) {
F_11 ( V_18 , L_64 , V_24 ) ;
F_20 ( V_29 ) ;
V_29 = NULL ;
F_13 ( 1 ) ;
V_36 = F_35 ( V_16 ) ;
if ( F_30 ( V_36 ) )
goto V_47;
goto V_81;
}
F_11 ( V_18 , L_65 , V_24 ) ;
V_47:
if ( F_18 ( V_29 ) )
F_20 ( V_29 ) ;
F_7 ( V_13 ) ;
F_112 ( & V_16 -> V_211 ) ;
return V_36 ;
}
static int F_113 ( struct V_66 * V_67 ,
struct V_215 * V_216 )
{
struct V_15 * V_16 = F_28 ( V_67 -> V_68 ) ;
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
struct V_34 * V_35 = V_67 -> V_130 ;
struct V_69 * V_70 = V_35 -> V_43 ;
T_1 V_217 = V_70 -> V_102 ;
struct V_71 V_72 = { 0 } ;
int V_36 = 0 ;
V_36 = F_114 ( ( const T_4 * ) & V_216 -> V_218 ,
V_219 , & V_72 ) ;
if ( ! V_36 ) {
F_25 ( V_18 , L_66 , V_24 ) ;
V_36 = - V_126 ;
goto V_47;
}
switch ( V_72 . V_95 ) {
case V_96 :
case V_97 :
case V_98 :
break;
case V_99 :
switch ( V_72 . V_100 ) {
case 0x29 :
case 0x2A :
V_36 = F_27 ( V_67 , V_35 ) ;
if ( V_36 ) {
V_36 = - V_92 ;
break;
}
if ( V_217 != V_70 -> V_102 )
F_11 ( V_18 , L_67
L_68 , V_24 , V_217 ,
V_70 -> V_102 ) ;
break;
case 0x3F :
F_115 ( V_16 -> V_68 ) ;
break;
default:
V_36 = - V_101 ;
break;
}
break;
default:
V_36 = - V_101 ;
break;
}
V_47:
F_11 ( V_18 , L_69 , V_24 ,
V_72 . V_95 , V_72 . V_100 , V_72 . V_220 , V_36 ) ;
return V_36 ;
}
static int F_116 ( struct V_66 * V_67 ,
struct V_215 * V_216 )
{
int V_36 = 0 ;
struct V_26 * V_29 = NULL ;
struct V_15 * V_16 = F_28 ( V_67 -> V_68 ) ;
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
struct V_34 * V_35 = V_67 -> V_130 ;
struct V_69 * V_70 = V_35 -> V_43 ;
struct V_106 * V_108 = NULL ;
T_6 V_107 = V_216 -> V_7 ;
T_1 V_30 = F_17 ( V_216 -> V_6 ) ,
V_27 = V_216 -> V_6 ;
T_1 V_196 = 0 ;
F_11 ( V_18 , L_70
L_71 , V_24 , V_30 , V_216 -> V_7 ,
V_216 -> V_221 , V_216 -> V_5 . V_181 ) ;
V_29 = F_16 ( V_16 , V_27 , V_35 , 0 ) ;
if ( F_30 ( ! V_29 ) ) {
F_11 ( V_18 , L_21 , V_24 , V_30 ) ;
V_36 = - V_126 ;
goto V_47;
}
V_108 = F_40 ( V_29 , V_107 , V_35 ) ;
if ( F_30 ( ! V_108 ) ) {
F_11 ( V_18 , L_13 ,
V_24 , V_107 ) ;
V_36 = - V_126 ;
goto V_47;
}
if ( V_216 -> V_221 & V_222 ) {
V_29 -> V_48 = true ;
F_7 ( & V_29 -> V_13 ) ;
V_36 = F_113 ( V_67 , V_216 ) ;
if ( F_30 ( V_36 ) ) {
F_25 ( V_18 , L_72 ,
V_24 , V_36 ) ;
F_5 ( & V_29 -> V_13 ) ;
V_29 -> V_48 = false ;
goto V_47;
}
F_5 ( & V_29 -> V_13 ) ;
V_29 -> V_48 = false ;
}
switch ( V_70 -> V_123 ) {
case V_136 :
V_196 = V_70 -> V_102 ;
break;
case V_134 :
V_196 = ( ( T_1 ) V_108 -> V_223 * V_224 * V_70 -> V_104 ) ;
V_196 /= V_225 ;
V_196 -- ;
break;
default:
F_54 ( 1 , L_24 ) ;
}
V_216 -> V_196 = V_196 ;
V_47:
if ( F_18 ( V_29 ) )
F_20 ( V_29 ) ;
F_11 ( V_18 , L_73 ,
V_24 , V_36 , V_216 -> V_196 ) ;
return V_36 ;
}
static char * F_117 ( int V_226 )
{
switch ( V_226 ) {
case V_227 :
return F_118 ( V_227 ) ;
case V_228 :
return F_118 ( V_228 ) ;
case V_229 :
return F_118 ( V_229 ) ;
case V_230 :
return F_118 ( V_230 ) ;
case V_231 :
return F_118 ( V_231 ) ;
case V_232 :
return F_118 ( V_232 ) ;
case V_233 :
return F_118 ( V_233 ) ;
case V_234 :
return F_118 ( V_234 ) ;
case V_235 :
return F_118 ( V_235 ) ;
case V_236 :
return F_118 ( V_236 ) ;
}
return L_74 ;
}
static int F_119 ( struct V_66 * V_67 , void * V_31 )
{
struct V_15 * V_16 = F_28 ( V_67 -> V_68 ) ;
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
struct V_51 * V_51 = V_16 -> V_51 ;
struct V_34 * V_35 = V_67 -> V_130 ;
struct V_69 * V_70 = V_35 -> V_43 ;
struct V_1 V_154 = { { 0 } , 0 } ;
struct V_10 * V_237 = (struct V_10 * ) V_31 ;
T_1 V_30 = F_17 ( V_237 -> V_6 ) ,
V_27 = V_237 -> V_6 ;
T_1 V_238 = 0 ;
T_1 V_196 = 0 ;
T_1 V_7 = - 1 ;
T_5 V_239 = F_120 ( V_67 -> V_184 ) ;
int V_36 = 0 ;
struct V_26 * V_29 = NULL ;
struct V_106 * V_108 = NULL ;
F_11 ( V_18 , L_75 , V_24 , V_30 , V_238 ) ;
V_36 = F_46 ( V_70 , V_136 , false ) ;
if ( F_30 ( V_36 ) ) {
F_11 ( V_18 , L_76 , V_24 ) ;
goto V_47;
}
V_29 = F_16 ( V_16 , V_27 , V_35 , 0 ) ;
if ( F_30 ( ! V_29 ) ) {
F_11 ( V_18 , L_21 , V_24 , V_30 ) ;
V_36 = - V_126 ;
goto V_202;
}
V_108 = F_41 ( V_29 , V_35 ) ;
if ( F_30 ( ! V_108 ) ) {
F_11 ( V_18 , L_77 ,
V_24 , V_30 ) ;
V_36 = - V_240 ;
goto V_202;
}
V_7 = ( V_108 - V_29 -> V_62 ) ;
F_43 ( V_108 , V_35 -> V_114 [ V_67 -> V_184 ] , V_29 -> V_148 , V_239 ) ;
V_196 = V_70 -> V_102 ;
V_237 -> V_5 . V_191 = 0 ;
V_237 -> V_196 = V_196 ;
V_237 -> V_7 = V_7 ;
V_36 = F_53 ( V_51 , V_30 , V_7 , V_241 ) ;
if ( F_30 ( V_36 ) ) {
F_11 ( V_18 , L_23 , V_24 , V_36 ) ;
goto V_203;
}
V_47:
if ( F_18 ( V_29 ) )
F_20 ( V_29 ) ;
F_11 ( V_18 , L_78 ,
V_24 , V_7 , V_36 , V_196 ) ;
return V_36 ;
V_203:
F_3 ( V_237 , & V_154 ) ;
F_51 ( V_67 , V_29 , & V_154 ) ;
goto V_47;
V_202:
F_49 ( V_70 ) ;
goto V_47;
}
static int F_121 ( struct V_66 * V_67 , int V_226 )
{
struct V_15 * V_16 = F_28 ( V_67 -> V_68 ) ;
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
struct V_34 * V_35 = V_67 -> V_130 ;
int V_36 = 0 ;
if ( F_30 ( ! V_35 ) ) {
F_11 ( V_18 , L_79 , V_24 ) ;
V_36 = - V_126 ;
goto V_47;
}
V_36 = F_35 ( V_16 ) ;
if ( F_30 ( V_36 ) && ( V_16 -> V_174 == V_176 ) ) {
switch ( V_226 ) {
case V_230 :
case V_231 :
case V_232 :
F_11 ( V_18 , L_80 ,
V_24 , V_36 ) ;
V_36 = 0 ;
break;
}
}
V_47:
return V_36 ;
}
int F_122 ( struct V_66 * V_67 , int V_226 , void T_7 * V_31 )
{
typedef int (* F_123) ( struct V_66 * , void * );
struct V_15 * V_16 = F_28 ( V_67 -> V_68 ) ;
struct V_17 * V_18 = & V_16 -> V_18 -> V_18 ;
struct V_51 * V_51 = V_16 -> V_51 ;
struct V_242 * V_5 ;
char V_243 [ sizeof( union V_244 ) ] ;
T_8 V_132 = 0 ;
bool V_245 = false ;
int V_246 ;
int V_36 = 0 ;
struct V_247 * V_248 = V_67 -> V_68 ;
F_123 V_249 = NULL ;
static const struct {
T_8 V_132 ;
F_123 V_250 ;
} V_251 [] = {
{ sizeof( struct V_177 ) , ( F_123 ) F_91 } ,
{ sizeof( struct V_10 ) , F_119 } ,
{ sizeof( struct V_1 ) , ( F_123 ) F_55 } ,
{ sizeof( struct V_8 ) , ( F_123 ) F_73 } ,
{ sizeof( struct V_215 ) , ( F_123 ) F_116 } ,
{ sizeof( struct V_205 ) , ( F_123 ) F_107 } ,
{ sizeof( struct V_252 ) , ( F_123 ) V_253 } ,
{ sizeof( struct V_254 ) , V_255 } ,
{ sizeof( struct V_3 ) , ( F_123 ) V_256 } ,
{ sizeof( struct V_257 ) , ( F_123 ) V_258 } ,
} ;
F_34 ( & V_16 -> V_89 ) ;
if ( V_51 -> V_259 )
switch ( V_226 ) {
case V_231 :
case V_229 :
case V_230 :
case V_234 :
F_11 ( V_18 , L_81 ,
V_24 , F_117 ( V_226 ) , V_51 -> V_259 ) ;
V_36 = - V_126 ;
goto V_260;
}
switch ( V_226 ) {
case V_227 :
case V_228 :
case V_231 :
case V_232 :
case V_233 :
case V_235 :
case V_229 :
case V_230 :
case V_234 :
F_11 ( V_18 , L_82 ,
V_24 , F_117 ( V_226 ) , V_226 , V_248 -> V_261 ,
V_67 -> V_184 , V_67 -> V_262 , V_67 -> V_263 ) ;
V_36 = F_121 ( V_67 , V_226 ) ;
if ( F_30 ( V_36 ) )
goto V_260;
case V_236 :
V_245 = true ;
V_246 = F_124 ( V_226 ) - F_124 ( V_227 ) ;
V_132 = V_251 [ V_246 ] . V_132 ;
V_249 = V_251 [ V_246 ] . V_250 ;
if ( F_18 ( V_249 ) )
break;
default:
V_36 = - V_126 ;
goto V_260;
}
if ( F_30 ( F_125 ( & V_243 , V_31 , V_132 ) ) ) {
F_25 ( V_18 , L_83
L_84 ,
V_24 , V_132 , V_226 , F_117 ( V_226 ) , V_31 ) ;
V_36 = - V_264 ;
goto V_260;
}
V_5 = (struct V_242 * ) & V_243 ;
if ( V_5 -> V_265 != V_266 ) {
F_11 ( V_18 , L_85 ,
V_24 , V_5 -> V_265 , F_117 ( V_226 ) ) ;
V_36 = - V_126 ;
goto V_260;
}
if ( V_5 -> V_267 [ 0 ] || V_5 -> V_267 [ 1 ] || V_5 -> V_267 [ 2 ] || V_5 -> V_191 ) {
F_11 ( V_18 , L_86 , V_24 ) ;
V_36 = - V_126 ;
goto V_260;
}
V_36 = V_249 ( V_67 , ( void * ) & V_243 ) ;
if ( F_18 ( ! V_36 ) )
if ( F_30 ( F_126 ( V_31 , & V_243 , V_132 ) ) ) {
F_25 ( V_18 , L_87
L_84 ,
V_24 , V_132 , V_226 , F_117 ( V_226 ) , V_31 ) ;
V_36 = - V_264 ;
}
V_260:
F_32 ( & V_16 -> V_89 ) ;
if ( F_30 ( V_36 && V_245 ) )
F_25 ( V_18 , L_88
L_89 , V_24 ,
F_117 ( V_226 ) , V_226 , V_248 -> V_261 ,
V_67 -> V_184 , V_67 -> V_262 , V_67 -> V_263 , V_36 ) ;
else
F_11 ( V_18 , L_88
L_89 , V_24 , F_117 ( V_226 ) ,
V_226 , V_248 -> V_261 , V_67 -> V_184 , V_67 -> V_262 ,
V_67 -> V_263 , V_36 ) ;
return V_36 ;
}
