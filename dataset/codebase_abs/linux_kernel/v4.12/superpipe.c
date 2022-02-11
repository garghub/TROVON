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
void F_3 ( void )
{
F_4 ( & V_10 . V_11 ) ;
if ( V_10 . V_12 ) {
F_5 ( V_10 . V_12 ) ;
V_10 . V_12 = NULL ;
}
F_6 ( & V_10 . V_11 ) ;
}
void F_7 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
int V_17 , V_18 = true ;
F_8 ( V_14 ) ;
while ( true ) {
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ )
if ( V_14 -> V_20 [ V_17 ] ) {
V_18 = true ;
break;
}
if ( ! V_18 && F_9 ( & V_14 -> V_21 ) )
return;
F_10 ( V_16 , L_1 ,
V_22 ) ;
F_11 ( & V_14 -> V_23 ) ;
F_12 ( 1 ) ;
V_18 = false ;
}
}
static struct V_24 * F_13 ( struct V_13 * V_14 , T_1 V_25 ,
struct V_26 * V_26 )
{
struct V_24 * V_27 ;
F_14 (ctxi, &cfg->ctx_err_recovery, list)
if ( ( V_27 -> V_28 == V_25 ) || ( V_27 -> V_26 == V_26 ) )
return V_27 ;
return NULL ;
}
struct V_24 * F_15 ( struct V_13 * V_14 , T_1 V_25 ,
void * V_29 , enum V_30 V_30 )
{
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_24 * V_27 = NULL ;
struct V_31 * V_31 = NULL ;
struct V_26 * V_26 = NULL ;
struct V_32 * V_33 = V_29 ;
T_1 V_28 = F_16 ( V_25 ) ;
int V_34 ;
T_2 V_35 = V_36 -> V_37 , V_38 = 0 ;
if ( V_30 & V_39 ) {
V_33 = NULL ;
V_26 = (struct V_26 * ) V_29 ;
}
if ( V_30 & V_40 )
V_35 = V_36 -> V_41 -> V_37 ;
if ( F_17 ( V_28 < V_19 ) ) {
while ( true ) {
F_4 ( & V_14 -> V_42 ) ;
V_27 = V_14 -> V_20 [ V_28 ] ;
if ( V_27 )
if ( ( V_26 && ( V_27 -> V_26 != V_26 ) ) ||
( ! V_26 && ( V_27 -> V_28 != V_25 ) ) )
V_27 = NULL ;
if ( ( V_30 & V_43 ) ||
( ! V_27 && ( V_30 & V_44 ) ) )
V_27 = F_13 ( V_14 , V_25 , V_26 ) ;
if ( ! V_27 ) {
F_6 ( & V_14 -> V_42 ) ;
goto V_45;
}
V_34 = F_18 ( & V_27 -> V_11 ) ;
F_6 ( & V_14 -> V_42 ) ;
if ( V_34 )
break;
}
if ( V_27 -> V_46 )
goto V_47;
V_38 = V_27 -> V_35 ;
if ( F_17 ( ! ( V_30 & V_48 ) ) )
if ( V_35 != V_38 )
goto V_47;
if ( V_33 ) {
F_14 (lun_access, &ctxi->luns, list)
if ( V_31 -> V_33 == V_33 )
goto V_45;
goto V_47;
}
}
V_45:
F_10 ( V_16 , L_2
L_3 , V_22 , V_25 , V_27 , V_38 , V_35 ,
V_30 ) ;
return V_27 ;
V_47:
F_6 ( & V_27 -> V_11 ) ;
V_27 = NULL ;
goto V_45;
}
void F_19 ( struct V_24 * V_27 )
{
F_6 ( & V_27 -> V_11 ) ;
}
static int F_20 ( struct V_13 * V_14 , struct V_24 * V_27 )
{
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_49 * V_49 = V_14 -> V_49 ;
struct V_50 T_3 * V_51 = V_27 -> V_51 ;
int V_34 = 0 ;
struct V_52 * V_52 = F_21 ( V_49 , V_53 ) ;
T_1 V_54 ;
F_22 ( & V_51 -> V_55 ) ;
V_54 = ( V_56 | V_57 ) ;
F_23 ( V_54 , & V_51 -> V_58 ) ;
V_54 = F_22 ( & V_51 -> V_58 ) ;
if ( V_54 != ( V_56 | V_57 ) ) {
F_24 ( V_16 , L_4 ,
V_22 , V_54 ) ;
V_34 = - V_59 ;
goto V_45;
}
F_23 ( ( T_1 ) V_27 -> V_60 , & V_51 -> V_60 ) ;
V_54 = F_25 ( ( T_1 ) V_61 , ( T_1 ) ( V_52 -> V_62 ) ) ;
F_23 ( V_54 , & V_51 -> V_63 ) ;
V_45:
F_10 ( V_16 , L_5 , V_22 , V_34 ) ;
return V_34 ;
}
static int F_26 ( struct V_64 * V_65 , struct V_32 * V_33 )
{
struct V_13 * V_14 = F_27 ( V_65 -> V_66 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_67 * V_68 = V_33 -> V_41 ;
struct V_69 V_70 ;
T_4 * V_71 = NULL ;
T_4 * V_72 = NULL ;
T_4 * V_73 = NULL ;
int V_34 = 0 ;
int V_74 = 0 ;
int V_75 = 0 ;
T_5 V_76 = V_77 * V_78 ;
V_79:
V_71 = F_28 ( V_80 , V_81 ) ;
V_72 = F_28 ( V_82 , V_81 ) ;
V_73 = F_28 ( V_83 , V_81 ) ;
if ( F_29 ( ! V_71 || ! V_72 || ! V_73 ) ) {
V_34 = - V_84 ;
goto V_45;
}
V_72 [ 0 ] = V_85 ;
V_72 [ 1 ] = V_86 ;
F_30 ( V_80 , & V_72 [ 10 ] ) ;
F_10 ( V_16 , L_6 , V_22 ,
V_75 ? L_7 : L_8 , V_72 [ 0 ] ) ;
F_31 ( & V_14 -> V_87 ) ;
V_74 = F_32 ( V_65 , V_72 , V_88 , V_71 ,
V_80 , V_73 , & V_70 , V_76 , V_89 ,
0 , 0 , NULL ) ;
F_33 ( & V_14 -> V_87 ) ;
V_34 = F_34 ( V_14 ) ;
if ( V_34 ) {
F_24 ( V_16 , L_9 ,
V_22 , V_74 ) ;
V_34 = - V_90 ;
goto V_45;
}
if ( F_35 ( V_74 ) == V_91 ) {
V_74 &= ~ ( 0xFF << 24 ) ;
if ( V_74 & V_92 ) {
switch ( V_70 . V_93 ) {
case V_94 :
case V_95 :
case V_96 :
V_74 &= ~ V_92 ;
break;
case V_97 :
switch ( V_70 . V_98 ) {
case 0x29 :
case 0x2A :
case 0x3F :
if ( V_75 ++ < 1 ) {
F_36 ( V_71 ) ;
F_36 ( V_72 ) ;
F_36 ( V_73 ) ;
goto V_79;
}
}
break;
default:
break;
}
}
}
if ( V_74 ) {
F_24 ( V_16 , L_10 ,
V_22 , V_74 ) ;
V_34 = - V_99 ;
goto V_45;
}
F_4 ( & V_68 -> V_11 ) ;
V_68 -> V_100 = F_37 ( * ( ( V_101 * ) & V_71 [ 0 ] ) ) ;
V_68 -> V_102 = F_38 ( * ( ( V_103 * ) & V_71 [ 8 ] ) ) ;
F_6 ( & V_68 -> V_11 ) ;
V_45:
F_36 ( V_71 ) ;
F_36 ( V_72 ) ;
F_36 ( V_73 ) ;
F_10 ( V_16 , L_11 ,
V_22 , V_68 -> V_100 , V_68 -> V_102 , V_34 ) ;
return V_34 ;
}
struct V_104 * F_39 ( struct V_24 * V_27 , T_6 V_105 ,
struct V_32 * V_33 )
{
struct V_13 * V_14 = V_27 -> V_14 ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_104 * V_106 = NULL ;
if ( F_29 ( ! V_27 -> V_60 ) ) {
F_10 ( V_16 , L_12 ,
V_22 ) ;
goto V_45;
}
if ( F_29 ( V_105 >= V_61 ) ) {
F_10 ( V_16 , L_13 ,
V_22 , V_105 ) ;
goto V_45;
}
if ( F_29 ( V_27 -> V_107 [ V_105 ] != V_33 ) ) {
F_10 ( V_16 , L_14 ,
V_22 , V_105 ) ;
goto V_45;
}
V_106 = & V_27 -> V_60 [ V_105 ] ;
if ( F_29 ( V_106 -> V_108 == 0 ) ) {
F_10 ( V_16 , L_15 ,
V_22 , V_105 ) ;
V_106 = NULL ;
goto V_45;
}
V_45:
return V_106 ;
}
struct V_104 * F_40 ( struct V_24 * V_27 ,
struct V_32 * V_33 )
{
struct V_13 * V_14 = V_27 -> V_14 ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_104 * V_106 = NULL ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_61 ; V_17 ++ )
if ( V_27 -> V_60 [ V_17 ] . V_108 == 0 ) {
V_106 = & V_27 -> V_60 [ V_17 ] ;
V_27 -> V_109 ++ ;
break;
}
if ( F_17 ( V_106 ) )
V_27 -> V_107 [ V_17 ] = V_33 ;
F_10 ( V_16 , L_16 , V_22 , V_106 , V_17 ) ;
return V_106 ;
}
void F_41 ( struct V_24 * V_27 ,
struct V_104 * V_106 )
{
T_5 V_7 = V_106 - V_27 -> V_60 ;
V_106 -> V_108 = 0 ;
V_106 -> V_110 = 0 ;
V_27 -> V_109 -- ;
V_27 -> V_107 [ V_7 ] = NULL ;
V_27 -> V_111 [ V_7 ] = false ;
}
static void F_42 ( struct V_104 * V_106 , T_1 V_112 , T_5 V_113 ,
T_5 V_114 )
{
struct V_115 V_116 = { 0 } ;
struct V_115 * V_117 = (struct V_115 * ) V_106 ;
memset ( V_117 , 0 , sizeof( * V_117 ) ) ;
V_117 -> V_110 = F_43 ( 1U , 0 ) ;
F_44 () ;
V_117 -> V_112 = V_112 ;
F_44 () ;
V_116 . V_118 = 0x80 ;
V_116 . V_110 = F_43 ( 1U , V_113 ) ;
V_116 . V_114 = V_114 ;
V_117 -> V_119 = V_116 . V_119 ;
F_44 () ;
}
int F_45 ( struct V_67 * V_68 , enum V_120 V_121 , bool V_122 )
{
int V_34 = 0 ;
if ( ! V_122 )
F_4 ( & V_68 -> V_11 ) ;
if ( V_68 -> V_121 == V_123 )
V_68 -> V_121 = V_121 ;
else if ( V_68 -> V_121 != V_121 ) {
F_46 ( L_17 ,
V_22 , V_68 -> V_121 , V_121 ) ;
V_34 = - V_124 ;
goto V_45;
}
V_68 -> V_125 ++ ;
F_47 ( V_68 -> V_125 <= 0 ) ;
V_45:
F_46 ( L_18 ,
V_22 , V_34 , V_68 -> V_121 , V_68 -> V_125 ) ;
if ( ! V_122 )
F_6 ( & V_68 -> V_11 ) ;
return V_34 ;
}
void F_48 ( struct V_67 * V_68 )
{
F_4 ( & V_68 -> V_11 ) ;
F_47 ( V_68 -> V_121 == V_123 ) ;
if ( -- V_68 -> V_125 == 0 ) {
V_68 -> V_121 = V_123 ;
F_49 ( & V_68 -> V_126 . V_127 ) ;
}
F_46 ( L_19 , V_22 , V_68 -> V_125 ) ;
F_47 ( V_68 -> V_125 < 0 ) ;
F_6 ( & V_68 -> V_11 ) ;
}
int F_50 ( struct V_64 * V_65 ,
struct V_24 * V_27 ,
struct V_1 * V_2 )
{
struct V_13 * V_14 = F_27 ( V_65 -> V_66 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_32 * V_33 = V_65 -> V_128 ;
struct V_67 * V_68 = V_33 -> V_41 ;
struct V_49 * V_49 = V_14 -> V_49 ;
bool V_129 = false ;
struct V_3 V_130 ;
T_6 V_105 = V_2 -> V_7 ;
int V_34 = 0 ;
T_1 V_28 = F_16 ( V_2 -> V_6 ) ,
V_25 = V_2 -> V_6 ;
struct V_104 * V_106 ;
struct V_115 * V_117 ;
F_10 ( V_16 , L_20 ,
V_22 , V_28 , V_2 -> V_7 , V_68 -> V_121 , V_68 -> V_125 ) ;
if ( ! V_27 ) {
V_27 = F_15 ( V_14 , V_25 , V_33 , V_44 ) ;
if ( F_29 ( ! V_27 ) ) {
F_10 ( V_16 , L_21 ,
V_22 , V_28 ) ;
V_34 = - V_124 ;
goto V_45;
}
V_129 = true ;
}
V_106 = F_39 ( V_27 , V_105 , V_33 ) ;
if ( F_29 ( ! V_106 ) ) {
F_10 ( V_16 , L_13 ,
V_22 , V_105 ) ;
V_34 = - V_124 ;
goto V_45;
}
switch ( V_68 -> V_121 ) {
case V_131 :
F_1 ( V_2 , & V_130 ) ;
V_130 . V_132 = 0 ;
V_34 = F_51 ( V_65 , V_27 , & V_130 ) ;
if ( V_34 ) {
F_10 ( V_16 , L_22 , V_22 , V_34 ) ;
goto V_45;
}
break;
case V_133 :
V_117 = (struct V_115 * ) V_106 ;
V_117 -> V_118 = 0 ;
F_44 () ;
V_117 -> V_112 = 0 ;
F_44 () ;
V_117 -> V_119 = 0 ;
F_44 () ;
if ( ! V_27 -> V_134 )
F_52 ( V_49 , V_28 , V_105 , V_135 ) ;
break;
default:
F_53 ( 1 , L_23 ) ;
goto V_45;
}
F_41 ( V_27 , V_106 ) ;
F_48 ( V_68 ) ;
V_45:
if ( V_129 )
F_19 ( V_27 ) ;
F_10 ( V_16 , L_5 , V_22 , V_34 ) ;
return V_34 ;
}
int F_54 ( struct V_64 * V_65 ,
struct V_1 * V_2 )
{
return F_50 ( V_65 , NULL , V_2 ) ;
}
static void F_55 ( struct V_13 * V_14 ,
struct V_24 * V_27 )
{
struct V_49 * V_49 = V_14 -> V_49 ;
if ( V_27 -> V_136 ) {
F_47 ( ! F_9 ( & V_27 -> V_137 ) ) ;
if ( V_49 -> V_138 && V_27 -> V_51 ) {
F_23 ( 0 , & V_27 -> V_51 -> V_60 ) ;
F_23 ( 0 , & V_27 -> V_51 -> V_63 ) ;
F_23 ( 0 , & V_27 -> V_51 -> V_58 ) ;
}
}
F_56 ( ( V_139 ) V_27 -> V_60 ) ;
F_36 ( V_27 -> V_111 ) ;
F_36 ( V_27 -> V_107 ) ;
F_36 ( V_27 ) ;
}
static struct V_24 * F_57 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_24 * V_27 = NULL ;
struct V_32 * * V_33 = NULL ;
T_4 * V_140 = NULL ;
struct V_104 * V_106 ;
V_27 = F_28 ( sizeof( * V_27 ) , V_81 ) ;
V_33 = F_28 ( ( V_61 * sizeof( * V_33 ) ) , V_81 ) ;
V_140 = F_28 ( ( V_61 * sizeof( * V_140 ) ) , V_81 ) ;
if ( F_29 ( ! V_27 || ! V_33 || ! V_140 ) ) {
F_24 ( V_16 , L_24 , V_22 ) ;
goto V_141;
}
V_106 = (struct V_104 * ) F_58 ( V_81 ) ;
if ( F_29 ( ! V_106 ) ) {
F_24 ( V_16 , L_25 , V_22 ) ;
goto V_141;
}
V_27 -> V_107 = V_33 ;
V_27 -> V_111 = V_140 ;
V_27 -> V_60 = V_106 ;
V_45:
return V_27 ;
V_141:
F_36 ( V_140 ) ;
F_36 ( V_33 ) ;
F_36 ( V_27 ) ;
V_27 = NULL ;
goto V_45;
}
static void F_59 ( struct V_24 * V_27 , struct V_13 * V_14 ,
struct V_142 * V_143 , int V_28 , struct V_26 * V_26 ,
T_5 V_144 )
{
struct V_49 * V_49 = V_14 -> V_49 ;
V_27 -> V_145 = V_144 ;
V_27 -> V_51 = & V_49 -> V_138 -> V_146 [ V_28 ] . V_147 ;
V_27 -> V_28 = F_60 ( V_27 , V_28 ) ;
V_27 -> V_35 = V_36 -> V_37 ;
V_27 -> V_143 = V_143 ;
V_27 -> V_14 = V_14 ;
V_27 -> V_26 = V_26 ;
V_27 -> V_136 = true ;
F_61 ( & V_27 -> V_11 ) ;
F_62 ( & V_27 -> V_148 ) ;
F_63 ( & V_27 -> V_137 ) ;
F_63 ( & V_27 -> V_149 ) ;
}
static void F_64 ( struct V_148 * V_148 )
{
struct V_24 * V_27 = F_65 ( V_148 , struct V_24 , V_148 ) ;
struct V_13 * V_14 = V_27 -> V_14 ;
T_1 V_28 = F_16 ( V_27 -> V_28 ) ;
F_47 ( ! F_66 ( & V_27 -> V_11 ) ) ;
V_27 -> V_46 = true ;
F_6 ( & V_27 -> V_11 ) ;
F_4 ( & V_14 -> V_42 ) ;
F_4 ( & V_27 -> V_11 ) ;
if ( ! F_9 ( & V_27 -> V_149 ) )
F_67 ( & V_27 -> V_149 ) ;
V_14 -> V_20 [ V_28 ] = NULL ;
F_6 ( & V_14 -> V_42 ) ;
F_6 ( & V_27 -> V_11 ) ;
F_55 ( V_14 , V_27 ) ;
}
static int F_68 ( struct V_64 * V_65 ,
struct V_24 * V_27 ,
struct V_8 * V_9 )
{
struct V_13 * V_14 = F_27 ( V_65 -> V_66 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_32 * V_33 = V_65 -> V_128 ;
struct V_31 * V_31 , * V_150 ;
struct V_1 V_151 ;
bool V_129 = false ;
int V_17 ;
int V_34 = 0 ;
T_1 V_28 = F_16 ( V_9 -> V_6 ) ,
V_25 = V_9 -> V_6 ;
F_10 ( V_16 , L_26 , V_22 , V_28 ) ;
if ( ! V_27 ) {
V_27 = F_15 ( V_14 , V_25 , V_33 , V_44 ) ;
if ( F_29 ( ! V_27 ) ) {
F_10 ( V_16 , L_21 ,
V_22 , V_28 ) ;
V_34 = - V_124 ;
goto V_45;
}
V_129 = true ;
}
if ( V_27 -> V_109 ) {
F_2 ( V_9 , & V_151 ) ;
for ( V_17 = 0 ; V_17 < V_61 ; V_17 ++ ) {
if ( V_27 -> V_107 [ V_17 ] == V_33 ) {
V_151 . V_7 = V_17 ;
F_50 ( V_65 , V_27 , & V_151 ) ;
}
if ( V_27 -> V_109 == 0 )
break;
}
}
F_69 (lun_access, t, &ctxi->luns, list)
if ( V_31 -> V_33 == V_33 ) {
F_67 ( & V_31 -> V_149 ) ;
F_36 ( V_31 ) ;
V_31 = NULL ;
break;
}
if ( F_70 ( & V_27 -> V_148 , F_64 ) )
V_129 = false ;
F_71 ( V_65 ) ;
V_45:
if ( V_129 )
F_19 ( V_27 ) ;
F_10 ( V_16 , L_5 , V_22 , V_34 ) ;
return V_34 ;
}
static int F_72 ( struct V_64 * V_65 ,
struct V_8 * V_9 )
{
return F_68 ( V_65 , NULL , V_9 ) ;
}
static int F_73 ( struct V_152 * V_152 , struct V_26 * V_26 )
{
struct V_142 * V_143 = F_74 ( V_26 ) ;
struct V_13 * V_14 = F_65 ( V_26 -> V_153 , struct V_13 ,
V_154 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_24 * V_27 = NULL ;
struct V_8 V_9 = { { 0 } , 0 } ;
struct V_31 * V_31 , * V_150 ;
enum V_30 V_147 = V_44 | V_39 ;
int V_28 ;
V_28 = F_75 ( V_143 ) ;
if ( F_29 ( V_28 < 0 ) ) {
F_24 ( V_16 , L_27 ,
V_22 , V_143 , V_28 ) ;
goto V_45;
}
V_27 = F_15 ( V_14 , V_28 , V_26 , V_147 ) ;
if ( F_29 ( ! V_27 ) ) {
V_27 = F_15 ( V_14 , V_28 , V_26 , V_147 | V_40 ) ;
if ( ! V_27 ) {
F_10 ( V_16 , L_28 ,
V_22 , V_28 ) ;
goto V_155;
}
F_10 ( V_16 , L_29 ,
V_22 , V_28 ) ;
F_19 ( V_27 ) ;
goto V_45;
}
F_10 ( V_16 , L_30 , V_22 , V_28 ) ;
V_9 . V_6 = V_27 -> V_28 ;
F_69 (lun_access, t, &ctxi->luns, list)
F_68 ( V_31 -> V_65 , V_27 , & V_9 ) ;
V_155:
F_76 ( V_152 , V_26 ) ;
V_45:
F_10 ( V_16 , L_31 , V_22 ) ;
return 0 ;
}
static void F_77 ( struct V_24 * V_27 )
{
F_78 ( V_27 -> V_26 -> V_156 , 0 , 0 , 1 ) ;
}
static struct V_157 * F_79 ( struct V_13 * V_14 )
{
struct V_157 * V_12 = V_10 . V_12 ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
if ( F_29 ( ! V_12 ) ) {
V_12 = F_80 ( V_81 ) ;
if ( F_29 ( ! V_12 ) ) {
F_24 ( V_16 , L_32 ,
V_22 ) ;
goto V_45;
}
memset ( F_81 ( V_12 ) , - 1 , V_158 ) ;
F_4 ( & V_10 . V_11 ) ;
if ( F_17 ( ! V_10 . V_12 ) )
V_10 . V_12 = V_12 ;
else {
F_5 ( V_12 ) ;
V_12 = V_10 . V_12 ;
}
F_6 ( & V_10 . V_11 ) ;
}
V_45:
F_10 ( V_16 , L_33 , V_22 , V_12 ) ;
return V_12 ;
}
static int F_82 ( struct V_159 * V_160 )
{
struct V_161 * V_162 = V_160 -> V_162 ;
struct V_26 * V_26 = V_162 -> V_163 ;
struct V_142 * V_143 = F_74 ( V_26 ) ;
struct V_13 * V_14 = F_65 ( V_26 -> V_153 , struct V_13 ,
V_154 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_24 * V_27 = NULL ;
struct V_157 * V_12 = NULL ;
enum V_30 V_147 = V_44 | V_39 ;
int V_34 = 0 ;
int V_28 ;
V_28 = F_75 ( V_143 ) ;
if ( F_29 ( V_28 < 0 ) ) {
F_24 ( V_16 , L_27 ,
V_22 , V_143 , V_28 ) ;
goto V_141;
}
V_27 = F_15 ( V_14 , V_28 , V_26 , V_147 ) ;
if ( F_29 ( ! V_27 ) ) {
F_10 ( V_16 , L_34 , V_22 , V_28 ) ;
goto V_141;
}
F_10 ( V_16 , L_35 , V_22 , V_28 ) ;
if ( F_17 ( ! V_27 -> V_134 ) ) {
V_162 -> V_164 = F_83 ( V_162 -> V_164 ) ;
V_34 = V_27 -> V_165 -> V_166 ( V_160 ) ;
} else {
F_10 ( V_16 , L_36 ,
V_22 ) ;
V_12 = F_79 ( V_14 ) ;
if ( F_29 ( ! V_12 ) ) {
F_24 ( V_16 , L_37 , V_22 ) ;
V_34 = V_167 ;
goto V_45;
}
F_84 ( V_12 ) ;
V_160 -> V_157 = V_12 ;
V_162 -> V_164 = F_85 ( V_162 -> V_164 ) ;
}
V_45:
if ( F_17 ( V_27 ) )
F_19 ( V_27 ) ;
F_10 ( V_16 , L_5 , V_22 , V_34 ) ;
return V_34 ;
V_141:
V_34 = V_168 ;
goto V_45;
}
static int F_86 ( struct V_26 * V_26 , struct V_161 * V_162 )
{
struct V_142 * V_143 = F_74 ( V_26 ) ;
struct V_13 * V_14 = F_65 ( V_26 -> V_153 , struct V_13 ,
V_154 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_24 * V_27 = NULL ;
enum V_30 V_147 = V_44 | V_39 ;
int V_28 ;
int V_34 = 0 ;
V_28 = F_75 ( V_143 ) ;
if ( F_29 ( V_28 < 0 ) ) {
F_24 ( V_16 , L_27 ,
V_22 , V_143 , V_28 ) ;
V_34 = - V_99 ;
goto V_45;
}
V_27 = F_15 ( V_14 , V_28 , V_26 , V_147 ) ;
if ( F_29 ( ! V_27 ) ) {
F_10 ( V_16 , L_34 , V_22 , V_28 ) ;
V_34 = - V_99 ;
goto V_45;
}
F_10 ( V_16 , L_38 , V_22 , V_28 ) ;
V_34 = F_87 ( V_26 , V_162 ) ;
if ( F_17 ( ! V_34 ) ) {
V_27 -> V_165 = V_162 -> V_169 ;
V_162 -> V_169 = & V_170 ;
}
V_45:
if ( F_17 ( V_27 ) )
F_19 ( V_27 ) ;
return V_34 ;
}
int F_8 ( struct V_13 * V_14 )
{
int V_17 , V_34 = 0 ;
struct V_24 * V_27 = NULL ;
F_4 ( & V_14 -> V_42 ) ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ ) {
V_27 = V_14 -> V_20 [ V_17 ] ;
if ( V_27 ) {
F_4 ( & V_27 -> V_11 ) ;
V_14 -> V_20 [ V_17 ] = NULL ;
F_88 ( & V_27 -> V_149 , & V_14 -> V_21 ) ;
V_27 -> V_134 = true ;
V_27 -> V_51 = NULL ;
F_77 ( V_27 ) ;
F_6 ( & V_27 -> V_11 ) ;
}
}
F_6 ( & V_14 -> V_42 ) ;
return V_34 ;
}
int F_34 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
int V_34 = 0 ;
V_79:
switch ( V_14 -> V_171 ) {
case V_172 :
F_10 ( V_16 , L_39 , V_22 ) ;
F_31 ( & V_14 -> V_87 ) ;
V_34 = F_89 ( V_14 -> V_23 ,
V_14 -> V_171 != V_172 ) ;
F_33 ( & V_14 -> V_87 ) ;
if ( F_29 ( V_34 ) )
break;
goto V_79;
case V_173 :
F_10 ( V_16 , L_40 , V_22 ) ;
V_34 = - V_90 ;
break;
default:
break;
}
return V_34 ;
}
static int F_90 ( struct V_64 * V_65 ,
struct V_174 * V_175 )
{
struct V_13 * V_14 = F_27 ( V_65 -> V_66 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_49 * V_49 = V_14 -> V_49 ;
struct V_32 * V_33 = V_65 -> V_128 ;
struct V_67 * V_68 = V_33 -> V_41 ;
struct V_176 * V_177 ;
struct V_24 * V_27 = NULL ;
struct V_31 * V_31 = NULL ;
int V_34 = 0 ;
T_5 V_144 ;
int V_28 = - 1 ;
T_1 V_178 = 0UL ;
T_1 V_25 = 0UL ;
struct V_26 * V_26 = NULL ;
struct V_142 * V_143 = NULL ;
int V_179 = - 1 ;
if ( V_175 -> V_180 > 4 ) {
F_10 ( V_16 , L_41 ,
V_22 , V_175 -> V_180 ) ;
V_34 = - V_124 ;
goto V_45;
}
if ( V_68 -> V_100 == 0 ) {
F_10 ( V_16 , L_42 ,
V_22 , V_33 -> V_112 [ V_65 -> V_181 ] ) ;
V_34 = F_26 ( V_65 , V_33 ) ;
if ( V_34 ) {
F_24 ( V_16 , L_43 ,
V_22 , V_34 ) ;
V_34 = - V_90 ;
goto V_45;
}
F_10 ( V_16 , L_44 , V_22 , V_68 -> V_100 ) ;
F_10 ( V_16 , L_45 , V_22 , V_68 -> V_102 ) ;
}
if ( V_175 -> V_5 . V_178 & V_182 ) {
V_25 = V_175 -> V_6 ;
V_27 = F_15 ( V_14 , V_25 , NULL , 0 ) ;
if ( ! V_27 ) {
F_10 ( V_16 , L_46 ,
V_22 , V_25 ) ;
V_34 = - V_124 ;
goto V_45;
}
F_14 (lun_access, &ctxi->luns, list)
if ( V_31 -> V_33 == V_33 ) {
F_10 ( V_16 , L_47 ,
V_22 ) ;
V_34 = - V_124 ;
goto V_45;
}
}
V_34 = F_91 ( V_65 ) ;
if ( F_29 ( V_34 ) ) {
F_24 ( V_16 , L_48 , V_22 ) ;
goto V_45;
}
V_31 = F_28 ( sizeof( * V_31 ) , V_81 ) ;
if ( F_29 ( ! V_31 ) ) {
F_24 ( V_16 , L_49 , V_22 ) ;
V_34 = - V_84 ;
goto V_141;
}
V_31 -> V_33 = V_33 ;
V_31 -> V_65 = V_65 ;
if ( V_27 ) {
F_10 ( V_16 , L_50 ,
V_22 , V_25 ) ;
F_92 ( & V_27 -> V_148 ) ;
F_88 ( & V_31 -> V_149 , & V_27 -> V_137 ) ;
goto V_183;
}
V_27 = F_57 ( V_14 ) ;
if ( F_29 ( ! V_27 ) ) {
F_24 ( V_16 , L_51 ,
V_22 , V_28 ) ;
goto V_141;
}
V_143 = F_93 ( V_14 -> V_16 ) ;
if ( F_94 ( V_143 ) ) {
F_24 ( V_16 , L_52 ,
V_22 , V_143 ) ;
V_34 = - V_90 ;
goto V_141;
}
V_177 = & V_27 -> V_177 ;
V_177 -> V_180 = V_175 -> V_180 ;
V_177 -> V_178 = V_184 ;
V_34 = F_95 ( V_143 , V_177 ) ;
if ( F_29 ( V_34 ) ) {
F_10 ( V_16 , L_53 ,
V_22 , V_34 ) ;
goto V_141;
}
V_28 = F_75 ( V_143 ) ;
if ( F_29 ( ( V_28 >= V_19 ) || ( V_28 < 0 ) ) ) {
F_24 ( V_16 , L_54 , V_22 , V_28 ) ;
V_34 = - V_185 ;
goto V_141;
}
V_26 = F_96 ( V_143 , & V_14 -> V_154 , & V_179 ) ;
if ( F_29 ( V_179 < 0 ) ) {
V_34 = - V_90 ;
F_24 ( V_16 , L_55 , V_22 ) ;
goto V_141;
}
V_144 = F_97 ( V_175 -> V_5 . V_178 + 1 ) ;
F_59 ( V_27 , V_14 , V_143 , V_28 , V_26 , V_144 ) ;
V_34 = F_20 ( V_14 , V_27 ) ;
if ( F_29 ( V_34 ) ) {
F_24 ( V_16 , L_56 , V_22 , V_34 ) ;
goto V_141;
}
F_88 ( & V_31 -> V_149 , & V_27 -> V_137 ) ;
F_4 ( & V_14 -> V_42 ) ;
F_4 ( & V_27 -> V_11 ) ;
V_14 -> V_20 [ V_28 ] = V_27 ;
F_6 ( & V_14 -> V_42 ) ;
F_98 ( V_179 , V_26 ) ;
V_183:
if ( V_179 != - 1 )
V_178 |= V_186 ;
if ( F_99 ( V_49 ) )
V_178 |= V_187 ;
V_175 -> V_5 . V_188 = V_178 ;
V_175 -> V_6 = V_27 -> V_28 ;
V_175 -> V_189 = V_68 -> V_102 ;
V_175 -> V_190 = sizeof( V_49 -> V_138 -> V_191 [ 0 ] . V_192 ) ;
V_175 -> V_193 = V_68 -> V_100 ;
V_175 -> V_194 = V_65 -> V_66 -> V_195 * V_196 ;
V_175 -> V_194 /= V_68 -> V_102 ;
V_45:
V_175 -> V_197 = V_179 ;
if ( V_27 )
F_19 ( V_27 ) ;
F_10 ( V_16 , L_57 ,
V_22 , V_28 , V_179 , V_175 -> V_189 , V_34 , V_175 -> V_193 ) ;
return V_34 ;
V_141:
if ( ! F_94 ( V_143 ) ) {
F_100 ( V_143 ) ;
F_101 ( V_143 ) ;
V_143 = NULL ;
}
if ( V_179 > 0 ) {
V_26 -> V_153 = & V_198 ;
F_102 ( V_26 ) ;
F_103 ( V_179 ) ;
V_179 = - 1 ;
V_26 = NULL ;
}
if ( V_27 ) {
F_55 ( V_14 , V_27 ) ;
V_27 = NULL ;
}
F_36 ( V_31 ) ;
F_71 ( V_65 ) ;
goto V_45;
}
static int F_104 ( struct V_13 * V_14 ,
struct V_24 * V_27 ,
int * V_197 )
{
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
int V_34 = 0 ;
int V_179 = - 1 ;
int V_28 = - 1 ;
struct V_26 * V_26 ;
struct V_142 * V_143 ;
struct V_49 * V_49 = V_14 -> V_49 ;
V_143 = F_93 ( V_14 -> V_16 ) ;
if ( F_94 ( V_143 ) ) {
F_24 ( V_16 , L_52 ,
V_22 , V_143 ) ;
V_34 = - V_90 ;
goto V_45;
}
V_34 = F_95 ( V_143 , & V_27 -> V_177 ) ;
if ( F_29 ( V_34 ) ) {
F_10 ( V_16 , L_53 ,
V_22 , V_34 ) ;
goto V_199;
}
V_28 = F_75 ( V_143 ) ;
if ( F_29 ( ( V_28 >= V_19 ) || ( V_28 < 0 ) ) ) {
F_24 ( V_16 , L_54 , V_22 , V_28 ) ;
V_34 = - V_185 ;
goto V_200;
}
V_26 = F_96 ( V_143 , & V_14 -> V_154 , & V_179 ) ;
if ( F_29 ( V_179 < 0 ) ) {
V_34 = - V_90 ;
F_24 ( V_16 , L_55 , V_22 ) ;
goto V_200;
}
V_27 -> V_51 = & V_49 -> V_138 -> V_146 [ V_28 ] . V_147 ;
V_34 = F_20 ( V_14 , V_27 ) ;
if ( V_34 ) {
F_24 ( V_16 , L_56 , V_22 , V_34 ) ;
goto V_201;
}
V_27 -> V_28 = F_60 ( V_27 , V_28 ) ;
V_27 -> V_143 = V_143 ;
V_27 -> V_26 = V_26 ;
F_6 ( & V_27 -> V_11 ) ;
F_4 ( & V_14 -> V_42 ) ;
F_4 ( & V_27 -> V_11 ) ;
F_105 ( & V_27 -> V_149 ) ;
V_14 -> V_20 [ V_28 ] = V_27 ;
F_6 ( & V_14 -> V_42 ) ;
F_98 ( V_179 , V_26 ) ;
* V_197 = V_179 ;
V_45:
F_10 ( V_16 , L_58 ,
V_22 , V_28 , V_179 , V_34 ) ;
return V_34 ;
V_201:
F_102 ( V_26 ) ;
F_103 ( V_179 ) ;
V_200:
F_100 ( V_143 ) ;
V_199:
F_101 ( V_143 ) ;
goto V_45;
}
static int F_106 ( struct V_64 * V_65 ,
struct V_202 * V_203 )
{
struct V_13 * V_14 = F_27 ( V_65 -> V_66 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_32 * V_33 = V_65 -> V_128 ;
struct V_49 * V_49 = V_14 -> V_49 ;
struct V_24 * V_27 = NULL ;
struct V_11 * V_11 = & V_14 -> V_204 ;
struct V_52 * V_52 = F_21 ( V_49 , V_53 ) ;
T_1 V_178 ;
T_1 V_28 = F_16 ( V_203 -> V_6 ) ,
V_25 = V_203 -> V_6 ;
long V_205 ;
int V_206 = 20 ;
int V_207 = - 1 ;
int V_34 = 0 ;
F_107 ( & V_14 -> V_208 ) ;
F_31 ( & V_14 -> V_87 ) ;
V_34 = F_108 ( V_11 ) ;
F_33 ( & V_14 -> V_87 ) ;
if ( V_34 )
goto V_45;
V_34 = F_34 ( V_14 ) ;
if ( V_34 ) {
F_24 ( V_16 , L_59 , V_22 , V_34 ) ;
V_34 = - V_90 ;
goto V_45;
}
F_10 ( V_16 , L_60 ,
V_22 , V_203 -> V_209 , V_25 ) ;
V_79:
V_27 = F_15 ( V_14 , V_25 , V_33 , V_44 ) ;
if ( F_29 ( ! V_27 ) ) {
F_10 ( V_16 , L_21 , V_22 , V_28 ) ;
V_34 = - V_124 ;
goto V_45;
}
if ( V_27 -> V_134 ) {
V_210:
V_34 = F_104 ( V_14 , V_27 , & V_207 ) ;
if ( F_29 ( V_34 ) ) {
F_24 ( V_16 , L_61 ,
V_22 , V_28 , V_34 ) ;
if ( ( V_34 == - V_90 ) &&
( ( F_109 ( & V_14 -> V_208 ) > 1 ) ||
( V_206 -- ) ) ) {
F_10 ( V_16 , L_62 ,
V_22 ) ;
F_6 ( V_11 ) ;
F_110 ( 100 ) ;
V_34 = F_108 ( V_11 ) ;
if ( V_34 )
goto V_45;
goto V_210;
}
goto V_45;
}
V_27 -> V_134 = false ;
V_178 = V_186 |
V_211 ;
if ( F_99 ( V_49 ) )
V_178 |= V_187 ;
V_203 -> V_5 . V_188 = V_178 ;
V_203 -> V_6 = V_27 -> V_28 ;
V_203 -> V_197 = V_207 ;
V_203 -> V_190 = sizeof( V_49 -> V_138 -> V_191 [ 0 ] . V_192 ) ;
goto V_45;
}
V_205 = F_22 ( & V_52 -> V_51 -> V_55 ) ;
if ( V_205 == - 1 ) {
F_10 ( V_16 , L_63 , V_22 ) ;
F_19 ( V_27 ) ;
V_27 = NULL ;
F_12 ( 1 ) ;
V_34 = F_34 ( V_14 ) ;
if ( F_29 ( V_34 ) )
goto V_45;
goto V_79;
}
F_10 ( V_16 , L_64 , V_22 ) ;
V_45:
if ( F_17 ( V_27 ) )
F_19 ( V_27 ) ;
F_6 ( V_11 ) ;
F_111 ( & V_14 -> V_208 ) ;
return V_34 ;
}
static int F_112 ( struct V_64 * V_65 ,
struct V_212 * V_213 )
{
struct V_13 * V_14 = F_27 ( V_65 -> V_66 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_32 * V_33 = V_65 -> V_128 ;
struct V_67 * V_68 = V_33 -> V_41 ;
T_1 V_214 = V_68 -> V_100 ;
struct V_69 V_70 = { 0 } ;
int V_34 = 0 ;
V_34 = F_113 ( ( const T_4 * ) & V_213 -> V_215 ,
V_216 , & V_70 ) ;
if ( ! V_34 ) {
F_24 ( V_16 , L_65 , V_22 ) ;
V_34 = - V_124 ;
goto V_45;
}
switch ( V_70 . V_93 ) {
case V_94 :
case V_95 :
case V_96 :
break;
case V_97 :
switch ( V_70 . V_98 ) {
case 0x29 :
case 0x2A :
V_34 = F_26 ( V_65 , V_33 ) ;
if ( V_34 ) {
V_34 = - V_90 ;
break;
}
if ( V_214 != V_68 -> V_100 )
F_10 ( V_16 , L_66
L_67 , V_22 , V_214 ,
V_68 -> V_100 ) ;
break;
case 0x3F :
F_114 ( V_14 -> V_66 ) ;
break;
default:
V_34 = - V_99 ;
break;
}
break;
default:
V_34 = - V_99 ;
break;
}
V_45:
F_10 ( V_16 , L_68 , V_22 ,
V_70 . V_93 , V_70 . V_98 , V_70 . V_217 , V_34 ) ;
return V_34 ;
}
static int F_115 ( struct V_64 * V_65 ,
struct V_212 * V_213 )
{
int V_34 = 0 ;
struct V_24 * V_27 = NULL ;
struct V_13 * V_14 = F_27 ( V_65 -> V_66 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_32 * V_33 = V_65 -> V_128 ;
struct V_67 * V_68 = V_33 -> V_41 ;
struct V_104 * V_106 = NULL ;
T_6 V_105 = V_213 -> V_7 ;
T_1 V_28 = F_16 ( V_213 -> V_6 ) ,
V_25 = V_213 -> V_6 ;
T_1 V_193 = 0 ;
F_10 ( V_16 , L_69
L_70 , V_22 , V_28 , V_213 -> V_7 ,
V_213 -> V_218 , V_213 -> V_5 . V_178 ) ;
V_27 = F_15 ( V_14 , V_25 , V_33 , 0 ) ;
if ( F_29 ( ! V_27 ) ) {
F_10 ( V_16 , L_21 , V_22 , V_28 ) ;
V_34 = - V_124 ;
goto V_45;
}
V_106 = F_39 ( V_27 , V_105 , V_33 ) ;
if ( F_29 ( ! V_106 ) ) {
F_10 ( V_16 , L_13 ,
V_22 , V_105 ) ;
V_34 = - V_124 ;
goto V_45;
}
if ( V_213 -> V_218 & V_219 ) {
V_27 -> V_46 = true ;
F_6 ( & V_27 -> V_11 ) ;
V_34 = F_112 ( V_65 , V_213 ) ;
if ( F_29 ( V_34 ) ) {
F_24 ( V_16 , L_71 ,
V_22 , V_34 ) ;
F_4 ( & V_27 -> V_11 ) ;
V_27 -> V_46 = false ;
goto V_45;
}
F_4 ( & V_27 -> V_11 ) ;
V_27 -> V_46 = false ;
}
switch ( V_68 -> V_121 ) {
case V_133 :
V_193 = V_68 -> V_100 ;
break;
case V_131 :
V_193 = ( ( T_1 ) V_106 -> V_220 * V_221 * V_68 -> V_102 ) ;
V_193 /= V_222 ;
V_193 -- ;
break;
default:
F_53 ( 1 , L_23 ) ;
}
V_213 -> V_193 = V_193 ;
V_45:
if ( F_17 ( V_27 ) )
F_19 ( V_27 ) ;
F_10 ( V_16 , L_72 ,
V_22 , V_34 , V_213 -> V_193 ) ;
return V_34 ;
}
static char * F_116 ( int V_223 )
{
switch ( V_223 ) {
case V_224 :
return F_117 ( V_224 ) ;
case V_225 :
return F_117 ( V_225 ) ;
case V_226 :
return F_117 ( V_226 ) ;
case V_227 :
return F_117 ( V_227 ) ;
case V_228 :
return F_117 ( V_228 ) ;
case V_229 :
return F_117 ( V_229 ) ;
case V_230 :
return F_117 ( V_230 ) ;
case V_231 :
return F_117 ( V_231 ) ;
case V_232 :
return F_117 ( V_232 ) ;
case V_233 :
return F_117 ( V_233 ) ;
}
return L_73 ;
}
static int F_118 ( struct V_64 * V_65 , void * V_29 )
{
struct V_13 * V_14 = F_27 ( V_65 -> V_66 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_49 * V_49 = V_14 -> V_49 ;
struct V_32 * V_33 = V_65 -> V_128 ;
struct V_67 * V_68 = V_33 -> V_41 ;
struct V_234 * V_235 = (struct V_234 * ) V_29 ;
T_1 V_28 = F_16 ( V_235 -> V_6 ) ,
V_25 = V_235 -> V_6 ;
T_1 V_236 = 0 ;
T_1 V_193 = 0 ;
T_1 V_7 = - 1 ;
T_5 V_237 = F_119 ( V_65 -> V_181 ) ;
int V_34 = 0 ;
struct V_24 * V_27 = NULL ;
struct V_104 * V_106 = NULL ;
F_10 ( V_16 , L_74 , V_22 , V_28 , V_236 ) ;
V_34 = F_45 ( V_68 , V_133 , false ) ;
if ( F_29 ( V_34 ) ) {
F_10 ( V_16 , L_75 , V_22 ) ;
goto V_45;
}
V_27 = F_15 ( V_14 , V_25 , V_33 , 0 ) ;
if ( F_29 ( ! V_27 ) ) {
F_10 ( V_16 , L_21 , V_22 , V_28 ) ;
V_34 = - V_124 ;
goto V_199;
}
V_106 = F_40 ( V_27 , V_33 ) ;
if ( F_29 ( ! V_106 ) ) {
F_10 ( V_16 , L_76 ,
V_22 , V_28 ) ;
V_34 = - V_238 ;
goto V_199;
}
V_7 = ( V_106 - V_27 -> V_60 ) ;
F_42 ( V_106 , V_33 -> V_112 [ V_65 -> V_181 ] , V_27 -> V_145 , V_237 ) ;
F_52 ( V_49 , V_28 , V_7 , V_239 ) ;
V_193 = V_68 -> V_100 ;
V_235 -> V_5 . V_188 = 0 ;
V_235 -> V_193 = V_193 ;
V_235 -> V_7 = V_7 ;
V_45:
if ( F_17 ( V_27 ) )
F_19 ( V_27 ) ;
F_10 ( V_16 , L_77 ,
V_22 , V_7 , V_34 , V_193 ) ;
return V_34 ;
V_199:
F_48 ( V_68 ) ;
goto V_45;
}
static int F_120 ( struct V_64 * V_65 , int V_223 )
{
struct V_13 * V_14 = F_27 ( V_65 -> V_66 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_32 * V_33 = V_65 -> V_128 ;
int V_34 = 0 ;
if ( F_29 ( ! V_33 ) ) {
F_10 ( V_16 , L_78 , V_22 ) ;
V_34 = - V_124 ;
goto V_45;
}
V_34 = F_34 ( V_14 ) ;
if ( F_29 ( V_34 ) && ( V_14 -> V_171 == V_173 ) ) {
switch ( V_223 ) {
case V_227 :
case V_228 :
case V_229 :
F_10 ( V_16 , L_79 ,
V_22 , V_34 ) ;
V_34 = 0 ;
break;
}
}
V_45:
return V_34 ;
}
int F_121 ( struct V_64 * V_65 , int V_223 , void T_7 * V_29 )
{
typedef int (* F_122) ( struct V_64 * , void * );
struct V_13 * V_14 = F_27 ( V_65 -> V_66 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_49 * V_49 = V_14 -> V_49 ;
struct V_240 * V_5 ;
char V_241 [ sizeof( union V_242 ) ] ;
T_8 V_130 = 0 ;
bool V_243 = false ;
int V_244 ;
int V_34 = 0 ;
struct V_245 * V_246 = V_65 -> V_66 ;
F_122 V_247 = NULL ;
static const struct {
T_8 V_130 ;
F_122 V_248 ;
} V_249 [] = {
{ sizeof( struct V_174 ) , ( F_122 ) F_90 } ,
{ sizeof( struct V_234 ) , F_118 } ,
{ sizeof( struct V_1 ) , ( F_122 ) F_54 } ,
{ sizeof( struct V_8 ) , ( F_122 ) F_72 } ,
{ sizeof( struct V_212 ) , ( F_122 ) F_115 } ,
{ sizeof( struct V_202 ) , ( F_122 ) F_106 } ,
{ sizeof( struct V_250 ) , ( F_122 ) V_251 } ,
{ sizeof( struct V_252 ) , V_253 } ,
{ sizeof( struct V_3 ) , ( F_122 ) V_254 } ,
{ sizeof( struct V_255 ) , ( F_122 ) V_256 } ,
} ;
F_33 ( & V_14 -> V_87 ) ;
if ( V_49 -> V_257 )
switch ( V_223 ) {
case V_228 :
case V_226 :
case V_227 :
case V_231 :
F_10 ( V_16 , L_80 ,
V_22 , F_116 ( V_223 ) , V_49 -> V_257 ) ;
V_34 = - V_124 ;
goto V_258;
}
switch ( V_223 ) {
case V_224 :
case V_225 :
case V_228 :
case V_229 :
case V_230 :
case V_232 :
case V_226 :
case V_227 :
case V_231 :
F_10 ( V_16 , L_81 ,
V_22 , F_116 ( V_223 ) , V_223 , V_246 -> V_259 ,
V_65 -> V_181 , V_65 -> V_260 , V_65 -> V_261 ) ;
V_34 = F_120 ( V_65 , V_223 ) ;
if ( F_29 ( V_34 ) )
goto V_258;
case V_233 :
V_243 = true ;
V_244 = F_123 ( V_223 ) - F_123 ( V_224 ) ;
V_130 = V_249 [ V_244 ] . V_130 ;
V_247 = V_249 [ V_244 ] . V_248 ;
if ( F_17 ( V_247 ) )
break;
default:
V_34 = - V_124 ;
goto V_258;
}
if ( F_29 ( F_124 ( & V_241 , V_29 , V_130 ) ) ) {
F_24 ( V_16 , L_82
L_83 ,
V_22 , V_130 , V_223 , F_116 ( V_223 ) , V_29 ) ;
V_34 = - V_262 ;
goto V_258;
}
V_5 = (struct V_240 * ) & V_241 ;
if ( V_5 -> V_263 != V_264 ) {
F_10 ( V_16 , L_84 ,
V_22 , V_5 -> V_263 , F_116 ( V_223 ) ) ;
V_34 = - V_124 ;
goto V_258;
}
if ( V_5 -> V_265 [ 0 ] || V_5 -> V_265 [ 1 ] || V_5 -> V_265 [ 2 ] || V_5 -> V_188 ) {
F_10 ( V_16 , L_85 , V_22 ) ;
V_34 = - V_124 ;
goto V_258;
}
V_34 = V_247 ( V_65 , ( void * ) & V_241 ) ;
if ( F_17 ( ! V_34 ) )
if ( F_29 ( F_125 ( V_29 , & V_241 , V_130 ) ) ) {
F_24 ( V_16 , L_86
L_83 ,
V_22 , V_130 , V_223 , F_116 ( V_223 ) , V_29 ) ;
V_34 = - V_262 ;
}
V_258:
F_31 ( & V_14 -> V_87 ) ;
if ( F_29 ( V_34 && V_243 ) )
F_24 ( V_16 , L_87
L_88 , V_22 ,
F_116 ( V_223 ) , V_223 , V_246 -> V_259 ,
V_65 -> V_181 , V_65 -> V_260 , V_65 -> V_261 , V_34 ) ;
else
F_10 ( V_16 , L_87
L_88 , V_22 , F_116 ( V_223 ) ,
V_223 , V_246 -> V_259 , V_65 -> V_181 , V_65 -> V_260 ,
V_65 -> V_261 , V_34 ) ;
return V_34 ;
}
