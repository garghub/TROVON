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
int V_17 , V_18 ;
F_8 ( V_14 ) ;
while ( true ) {
V_18 = false ;
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
T_1 V_52 ;
F_21 ( & V_51 -> V_53 ) ;
V_52 = ( V_54 | V_55 ) ;
F_22 ( V_52 , & V_51 -> V_56 ) ;
V_52 = F_21 ( & V_51 -> V_56 ) ;
if ( V_52 != ( V_54 | V_55 ) ) {
F_23 ( V_16 , L_4 ,
V_22 , V_52 ) ;
V_34 = - V_57 ;
goto V_45;
}
F_22 ( ( T_1 ) V_27 -> V_58 , & V_51 -> V_58 ) ;
V_52 = F_24 ( ( T_1 ) V_59 , ( T_1 ) ( V_49 -> V_60 ) ) ;
F_22 ( V_52 , & V_51 -> V_61 ) ;
V_45:
F_10 ( V_16 , L_5 , V_22 , V_34 ) ;
return V_34 ;
}
static int F_25 ( struct V_62 * V_63 , struct V_32 * V_33 )
{
struct V_13 * V_14 = F_26 ( V_63 -> V_64 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_65 * V_66 = V_33 -> V_41 ;
struct V_67 V_68 ;
T_4 * V_69 = NULL ;
T_4 * V_70 = NULL ;
T_4 * V_71 = NULL ;
int V_34 = 0 ;
int V_72 = 0 ;
int V_73 = 0 ;
T_5 V_74 = V_75 * V_76 ;
V_77:
V_69 = F_27 ( V_78 , V_79 ) ;
V_70 = F_27 ( V_80 , V_79 ) ;
V_71 = F_27 ( V_81 , V_79 ) ;
if ( F_28 ( ! V_69 || ! V_70 || ! V_71 ) ) {
V_34 = - V_82 ;
goto V_45;
}
V_70 [ 0 ] = V_83 ;
V_70 [ 1 ] = V_84 ;
F_29 ( V_78 , & V_70 [ 10 ] ) ;
F_10 ( V_16 , L_6 , V_22 ,
V_73 ? L_7 : L_8 , V_70 [ 0 ] ) ;
F_30 ( & V_14 -> V_85 ) ;
V_72 = F_31 ( V_63 , V_70 , V_86 , V_69 ,
V_78 , V_71 , & V_68 , V_74 , V_87 ,
0 , 0 , NULL ) ;
F_32 ( & V_14 -> V_85 ) ;
V_34 = F_33 ( V_14 ) ;
if ( V_34 ) {
F_23 ( V_16 , L_9 ,
V_22 , V_72 ) ;
V_34 = - V_88 ;
goto V_45;
}
if ( F_34 ( V_72 ) == V_89 ) {
V_72 &= ~ ( 0xFF << 24 ) ;
if ( V_72 & V_90 ) {
switch ( V_68 . V_91 ) {
case V_92 :
case V_93 :
case V_94 :
V_72 &= ~ V_90 ;
break;
case V_95 :
switch ( V_68 . V_96 ) {
case 0x29 :
case 0x2A :
case 0x3F :
if ( V_73 ++ < 1 ) {
F_35 ( V_69 ) ;
F_35 ( V_70 ) ;
F_35 ( V_71 ) ;
goto V_77;
}
}
break;
default:
break;
}
}
}
if ( V_72 ) {
F_23 ( V_16 , L_10 ,
V_22 , V_72 ) ;
V_34 = - V_97 ;
goto V_45;
}
F_4 ( & V_66 -> V_11 ) ;
V_66 -> V_98 = F_36 ( * ( ( V_99 * ) & V_69 [ 0 ] ) ) ;
V_66 -> V_100 = F_37 ( * ( ( V_101 * ) & V_69 [ 8 ] ) ) ;
F_6 ( & V_66 -> V_11 ) ;
V_45:
F_35 ( V_69 ) ;
F_35 ( V_70 ) ;
F_35 ( V_71 ) ;
F_10 ( V_16 , L_11 ,
V_22 , V_66 -> V_98 , V_66 -> V_100 , V_34 ) ;
return V_34 ;
}
struct V_102 * F_38 ( struct V_24 * V_27 , T_6 V_103 ,
struct V_32 * V_33 )
{
struct V_13 * V_14 = V_27 -> V_14 ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_102 * V_104 = NULL ;
if ( F_28 ( ! V_27 -> V_58 ) ) {
F_10 ( V_16 , L_12 ,
V_22 ) ;
goto V_45;
}
if ( F_28 ( V_103 >= V_59 ) ) {
F_10 ( V_16 , L_13 ,
V_22 , V_103 ) ;
goto V_45;
}
if ( F_28 ( V_27 -> V_105 [ V_103 ] != V_33 ) ) {
F_10 ( V_16 , L_14 ,
V_22 , V_103 ) ;
goto V_45;
}
V_104 = & V_27 -> V_58 [ V_103 ] ;
if ( F_28 ( V_104 -> V_106 == 0 ) ) {
F_10 ( V_16 , L_15 ,
V_22 , V_103 ) ;
V_104 = NULL ;
goto V_45;
}
V_45:
return V_104 ;
}
struct V_102 * F_39 ( struct V_24 * V_27 ,
struct V_32 * V_33 )
{
struct V_13 * V_14 = V_27 -> V_14 ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_102 * V_104 = NULL ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_59 ; V_17 ++ )
if ( V_27 -> V_58 [ V_17 ] . V_106 == 0 ) {
V_104 = & V_27 -> V_58 [ V_17 ] ;
V_27 -> V_107 ++ ;
break;
}
if ( F_17 ( V_104 ) )
V_27 -> V_105 [ V_17 ] = V_33 ;
F_10 ( V_16 , L_16 , V_22 , V_104 , V_17 ) ;
return V_104 ;
}
void F_40 ( struct V_24 * V_27 ,
struct V_102 * V_104 )
{
T_5 V_7 = V_104 - V_27 -> V_58 ;
V_104 -> V_106 = 0 ;
V_104 -> V_108 = 0 ;
V_27 -> V_107 -- ;
V_27 -> V_105 [ V_7 ] = NULL ;
V_27 -> V_109 [ V_7 ] = false ;
}
static void F_41 ( struct V_102 * V_104 , T_1 V_110 , T_5 V_111 ,
T_5 V_112 )
{
struct V_113 V_114 = { 0 } ;
struct V_113 * V_115 = (struct V_113 * ) V_104 ;
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
V_115 -> V_108 = F_42 ( 1U , 0 ) ;
F_43 () ;
V_115 -> V_110 = V_110 ;
F_43 () ;
V_114 . V_116 = 0x80 ;
V_114 . V_108 = F_42 ( 1U , V_111 ) ;
V_114 . V_112 = V_112 ;
V_115 -> V_117 = V_114 . V_117 ;
F_43 () ;
}
int F_44 ( struct V_65 * V_66 , enum V_118 V_119 , bool V_120 )
{
int V_34 = 0 ;
if ( ! V_120 )
F_4 ( & V_66 -> V_11 ) ;
if ( V_66 -> V_119 == V_121 )
V_66 -> V_119 = V_119 ;
else if ( V_66 -> V_119 != V_119 ) {
F_45 ( L_17 ,
V_22 , V_66 -> V_119 , V_119 ) ;
V_34 = - V_122 ;
goto V_45;
}
V_66 -> V_123 ++ ;
F_46 ( V_66 -> V_123 <= 0 ) ;
V_45:
F_45 ( L_18 ,
V_22 , V_34 , V_66 -> V_119 , V_66 -> V_123 ) ;
if ( ! V_120 )
F_6 ( & V_66 -> V_11 ) ;
return V_34 ;
}
void F_47 ( struct V_65 * V_66 )
{
F_4 ( & V_66 -> V_11 ) ;
F_46 ( V_66 -> V_119 == V_121 ) ;
if ( -- V_66 -> V_123 == 0 ) {
V_66 -> V_119 = V_121 ;
F_48 ( & V_66 -> V_124 . V_125 ) ;
}
F_45 ( L_19 , V_22 , V_66 -> V_123 ) ;
F_46 ( V_66 -> V_123 < 0 ) ;
F_6 ( & V_66 -> V_11 ) ;
}
int F_49 ( struct V_62 * V_63 ,
struct V_24 * V_27 ,
struct V_1 * V_2 )
{
struct V_13 * V_14 = F_26 ( V_63 -> V_64 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_32 * V_33 = V_63 -> V_126 ;
struct V_65 * V_66 = V_33 -> V_41 ;
struct V_49 * V_49 = V_14 -> V_49 ;
bool V_127 = false ;
struct V_3 V_128 ;
T_6 V_103 = V_2 -> V_7 ;
int V_34 = 0 ;
T_1 V_28 = F_16 ( V_2 -> V_6 ) ,
V_25 = V_2 -> V_6 ;
struct V_102 * V_104 ;
struct V_113 * V_115 ;
F_10 ( V_16 , L_20 ,
V_22 , V_28 , V_2 -> V_7 , V_66 -> V_119 , V_66 -> V_123 ) ;
if ( ! V_27 ) {
V_27 = F_15 ( V_14 , V_25 , V_33 , V_44 ) ;
if ( F_28 ( ! V_27 ) ) {
F_10 ( V_16 , L_21 ,
V_22 , V_28 ) ;
V_34 = - V_122 ;
goto V_45;
}
V_127 = true ;
}
V_104 = F_38 ( V_27 , V_103 , V_33 ) ;
if ( F_28 ( ! V_104 ) ) {
F_10 ( V_16 , L_13 ,
V_22 , V_103 ) ;
V_34 = - V_122 ;
goto V_45;
}
switch ( V_66 -> V_119 ) {
case V_129 :
F_1 ( V_2 , & V_128 ) ;
V_128 . V_130 = 0 ;
V_34 = F_50 ( V_63 , V_27 , & V_128 ) ;
if ( V_34 ) {
F_10 ( V_16 , L_22 , V_22 , V_34 ) ;
goto V_45;
}
break;
case V_131 :
V_115 = (struct V_113 * ) V_104 ;
V_115 -> V_116 = 0 ;
F_43 () ;
V_115 -> V_110 = 0 ;
F_43 () ;
V_115 -> V_117 = 0 ;
F_43 () ;
if ( ! V_27 -> V_132 )
F_51 ( V_49 , V_28 , V_103 , V_133 ) ;
break;
default:
F_52 ( 1 , L_23 ) ;
goto V_45;
}
F_40 ( V_27 , V_104 ) ;
F_47 ( V_66 ) ;
V_45:
if ( V_127 )
F_19 ( V_27 ) ;
F_10 ( V_16 , L_5 , V_22 , V_34 ) ;
return V_34 ;
}
int F_53 ( struct V_62 * V_63 ,
struct V_1 * V_2 )
{
return F_49 ( V_63 , NULL , V_2 ) ;
}
static void F_54 ( struct V_13 * V_14 ,
struct V_24 * V_27 )
{
struct V_49 * V_49 = V_14 -> V_49 ;
if ( V_27 -> V_134 ) {
F_46 ( ! F_9 ( & V_27 -> V_135 ) ) ;
if ( V_49 -> V_136 && V_27 -> V_51 ) {
F_22 ( 0 , & V_27 -> V_51 -> V_58 ) ;
F_22 ( 0 , & V_27 -> V_51 -> V_61 ) ;
F_22 ( 0 , & V_27 -> V_51 -> V_56 ) ;
}
}
F_55 ( ( V_137 ) V_27 -> V_58 ) ;
F_35 ( V_27 -> V_109 ) ;
F_35 ( V_27 -> V_105 ) ;
F_35 ( V_27 ) ;
}
static struct V_24 * F_56 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_24 * V_27 = NULL ;
struct V_32 * * V_33 = NULL ;
T_4 * V_138 = NULL ;
struct V_102 * V_104 ;
V_27 = F_27 ( sizeof( * V_27 ) , V_79 ) ;
V_33 = F_27 ( ( V_59 * sizeof( * V_33 ) ) , V_79 ) ;
V_138 = F_27 ( ( V_59 * sizeof( * V_138 ) ) , V_79 ) ;
if ( F_28 ( ! V_27 || ! V_33 || ! V_138 ) ) {
F_23 ( V_16 , L_24 , V_22 ) ;
goto V_139;
}
V_104 = (struct V_102 * ) F_57 ( V_79 ) ;
if ( F_28 ( ! V_104 ) ) {
F_23 ( V_16 , L_25 , V_22 ) ;
goto V_139;
}
V_27 -> V_105 = V_33 ;
V_27 -> V_109 = V_138 ;
V_27 -> V_58 = V_104 ;
V_45:
return V_27 ;
V_139:
F_35 ( V_138 ) ;
F_35 ( V_33 ) ;
F_35 ( V_27 ) ;
V_27 = NULL ;
goto V_45;
}
static void F_58 ( struct V_24 * V_27 , struct V_13 * V_14 ,
struct V_140 * V_141 , int V_28 , struct V_26 * V_26 ,
T_5 V_142 )
{
struct V_49 * V_49 = V_14 -> V_49 ;
V_27 -> V_143 = V_142 ;
V_27 -> V_51 = & V_49 -> V_136 -> V_144 [ V_28 ] . V_145 ;
V_27 -> V_28 = F_59 ( V_27 , V_28 ) ;
V_27 -> V_35 = V_36 -> V_37 ;
V_27 -> V_141 = V_141 ;
V_27 -> V_14 = V_14 ;
V_27 -> V_26 = V_26 ;
V_27 -> V_134 = true ;
F_60 ( & V_27 -> V_11 ) ;
F_61 ( & V_27 -> V_146 ) ;
F_62 ( & V_27 -> V_135 ) ;
F_62 ( & V_27 -> V_147 ) ;
}
static void F_63 ( struct V_146 * V_146 )
{
struct V_24 * V_27 = F_64 ( V_146 , struct V_24 , V_146 ) ;
struct V_13 * V_14 = V_27 -> V_14 ;
T_1 V_28 = F_16 ( V_27 -> V_28 ) ;
F_46 ( ! F_65 ( & V_27 -> V_11 ) ) ;
V_27 -> V_46 = true ;
F_6 ( & V_27 -> V_11 ) ;
F_4 ( & V_14 -> V_42 ) ;
F_4 ( & V_27 -> V_11 ) ;
if ( ! F_9 ( & V_27 -> V_147 ) )
F_66 ( & V_27 -> V_147 ) ;
V_14 -> V_20 [ V_28 ] = NULL ;
F_6 ( & V_14 -> V_42 ) ;
F_6 ( & V_27 -> V_11 ) ;
F_54 ( V_14 , V_27 ) ;
}
static int F_67 ( struct V_62 * V_63 ,
struct V_24 * V_27 ,
struct V_8 * V_9 )
{
struct V_13 * V_14 = F_26 ( V_63 -> V_64 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_32 * V_33 = V_63 -> V_126 ;
struct V_31 * V_31 , * V_148 ;
struct V_1 V_149 ;
bool V_127 = false ;
int V_17 ;
int V_34 = 0 ;
T_1 V_28 = F_16 ( V_9 -> V_6 ) ,
V_25 = V_9 -> V_6 ;
F_10 ( V_16 , L_26 , V_22 , V_28 ) ;
if ( ! V_27 ) {
V_27 = F_15 ( V_14 , V_25 , V_33 , V_44 ) ;
if ( F_28 ( ! V_27 ) ) {
F_10 ( V_16 , L_21 ,
V_22 , V_28 ) ;
V_34 = - V_122 ;
goto V_45;
}
V_127 = true ;
}
if ( V_27 -> V_107 ) {
F_2 ( V_9 , & V_149 ) ;
for ( V_17 = 0 ; V_17 < V_59 ; V_17 ++ ) {
if ( V_27 -> V_105 [ V_17 ] == V_33 ) {
V_149 . V_7 = V_17 ;
F_49 ( V_63 , V_27 , & V_149 ) ;
}
if ( V_27 -> V_107 == 0 )
break;
}
}
F_68 (lun_access, t, &ctxi->luns, list)
if ( V_31 -> V_33 == V_33 ) {
F_66 ( & V_31 -> V_147 ) ;
F_35 ( V_31 ) ;
V_31 = NULL ;
break;
}
if ( F_69 ( & V_27 -> V_146 , F_63 ) )
V_127 = false ;
F_70 ( V_63 ) ;
V_45:
if ( V_127 )
F_19 ( V_27 ) ;
F_10 ( V_16 , L_5 , V_22 , V_34 ) ;
return V_34 ;
}
static int F_71 ( struct V_62 * V_63 ,
struct V_8 * V_9 )
{
return F_67 ( V_63 , NULL , V_9 ) ;
}
static int F_72 ( struct V_150 * V_150 , struct V_26 * V_26 )
{
struct V_140 * V_141 = F_73 ( V_26 ) ;
struct V_13 * V_14 = F_64 ( V_26 -> V_151 , struct V_13 ,
V_152 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_24 * V_27 = NULL ;
struct V_8 V_9 = { { 0 } , 0 } ;
struct V_31 * V_31 , * V_148 ;
enum V_30 V_145 = V_44 | V_39 ;
int V_28 ;
V_28 = F_74 ( V_141 ) ;
if ( F_28 ( V_28 < 0 ) ) {
F_23 ( V_16 , L_27 ,
V_22 , V_141 , V_28 ) ;
goto V_45;
}
V_27 = F_15 ( V_14 , V_28 , V_26 , V_145 ) ;
if ( F_28 ( ! V_27 ) ) {
V_27 = F_15 ( V_14 , V_28 , V_26 , V_145 | V_40 ) ;
if ( ! V_27 ) {
F_10 ( V_16 , L_28 ,
V_22 , V_28 ) ;
goto V_153;
}
F_10 ( V_16 , L_29 ,
V_22 , V_28 ) ;
F_19 ( V_27 ) ;
goto V_45;
}
F_10 ( V_16 , L_30 , V_22 , V_28 ) ;
V_9 . V_6 = V_27 -> V_28 ;
F_68 (lun_access, t, &ctxi->luns, list)
F_67 ( V_31 -> V_63 , V_27 , & V_9 ) ;
V_153:
F_75 ( V_150 , V_26 ) ;
V_45:
F_10 ( V_16 , L_31 , V_22 ) ;
return 0 ;
}
static void F_76 ( struct V_24 * V_27 )
{
F_77 ( V_27 -> V_26 -> V_154 , 0 , 0 , 1 ) ;
}
static struct V_155 * F_78 ( struct V_13 * V_14 )
{
struct V_155 * V_12 = V_10 . V_12 ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
if ( F_28 ( ! V_12 ) ) {
V_12 = F_79 ( V_79 ) ;
if ( F_28 ( ! V_12 ) ) {
F_23 ( V_16 , L_32 ,
V_22 ) ;
goto V_45;
}
memset ( F_80 ( V_12 ) , - 1 , V_156 ) ;
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
static int F_81 ( struct V_157 * V_158 )
{
struct V_159 * V_160 = V_158 -> V_160 ;
struct V_26 * V_26 = V_160 -> V_161 ;
struct V_140 * V_141 = F_73 ( V_26 ) ;
struct V_13 * V_14 = F_64 ( V_26 -> V_151 , struct V_13 ,
V_152 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_24 * V_27 = NULL ;
struct V_155 * V_12 = NULL ;
enum V_30 V_145 = V_44 | V_39 ;
int V_34 = 0 ;
int V_28 ;
V_28 = F_74 ( V_141 ) ;
if ( F_28 ( V_28 < 0 ) ) {
F_23 ( V_16 , L_27 ,
V_22 , V_141 , V_28 ) ;
goto V_139;
}
V_27 = F_15 ( V_14 , V_28 , V_26 , V_145 ) ;
if ( F_28 ( ! V_27 ) ) {
F_10 ( V_16 , L_34 , V_22 , V_28 ) ;
goto V_139;
}
F_10 ( V_16 , L_35 , V_22 , V_28 ) ;
if ( F_17 ( ! V_27 -> V_132 ) ) {
V_160 -> V_162 = F_82 ( V_160 -> V_162 ) ;
V_34 = V_27 -> V_163 -> V_164 ( V_158 ) ;
} else {
F_10 ( V_16 , L_36 ,
V_22 ) ;
V_12 = F_78 ( V_14 ) ;
if ( F_28 ( ! V_12 ) ) {
F_23 ( V_16 , L_37 , V_22 ) ;
V_34 = V_165 ;
goto V_45;
}
F_83 ( V_12 ) ;
V_158 -> V_155 = V_12 ;
V_160 -> V_162 = F_84 ( V_160 -> V_162 ) ;
}
V_45:
if ( F_17 ( V_27 ) )
F_19 ( V_27 ) ;
F_10 ( V_16 , L_5 , V_22 , V_34 ) ;
return V_34 ;
V_139:
V_34 = V_166 ;
goto V_45;
}
static int F_85 ( struct V_26 * V_26 , struct V_159 * V_160 )
{
struct V_140 * V_141 = F_73 ( V_26 ) ;
struct V_13 * V_14 = F_64 ( V_26 -> V_151 , struct V_13 ,
V_152 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_24 * V_27 = NULL ;
enum V_30 V_145 = V_44 | V_39 ;
int V_28 ;
int V_34 = 0 ;
V_28 = F_74 ( V_141 ) ;
if ( F_28 ( V_28 < 0 ) ) {
F_23 ( V_16 , L_27 ,
V_22 , V_141 , V_28 ) ;
V_34 = - V_97 ;
goto V_45;
}
V_27 = F_15 ( V_14 , V_28 , V_26 , V_145 ) ;
if ( F_28 ( ! V_27 ) ) {
F_10 ( V_16 , L_34 , V_22 , V_28 ) ;
V_34 = - V_97 ;
goto V_45;
}
F_10 ( V_16 , L_38 , V_22 , V_28 ) ;
V_34 = F_86 ( V_26 , V_160 ) ;
if ( F_17 ( ! V_34 ) ) {
V_27 -> V_163 = V_160 -> V_167 ;
V_160 -> V_167 = & V_168 ;
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
F_87 ( & V_27 -> V_147 , & V_14 -> V_21 ) ;
V_27 -> V_132 = true ;
V_27 -> V_51 = NULL ;
F_76 ( V_27 ) ;
F_6 ( & V_27 -> V_11 ) ;
}
}
F_6 ( & V_14 -> V_42 ) ;
return V_34 ;
}
int F_33 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
int V_34 = 0 ;
V_77:
switch ( V_14 -> V_169 ) {
case V_170 :
F_10 ( V_16 , L_39 , V_22 ) ;
F_30 ( & V_14 -> V_85 ) ;
V_34 = F_88 ( V_14 -> V_23 ,
V_14 -> V_169 != V_170 ) ;
F_32 ( & V_14 -> V_85 ) ;
if ( F_28 ( V_34 ) )
break;
goto V_77;
case V_171 :
F_10 ( V_16 , L_40 , V_22 ) ;
V_34 = - V_88 ;
break;
default:
break;
}
return V_34 ;
}
static int F_89 ( struct V_62 * V_63 ,
struct V_172 * V_173 )
{
struct V_13 * V_14 = F_26 ( V_63 -> V_64 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_49 * V_49 = V_14 -> V_49 ;
struct V_32 * V_33 = V_63 -> V_126 ;
struct V_65 * V_66 = V_33 -> V_41 ;
struct V_174 * V_175 ;
struct V_24 * V_27 = NULL ;
struct V_31 * V_31 = NULL ;
int V_34 = 0 ;
T_5 V_142 ;
int V_28 = - 1 ;
T_1 V_176 = 0UL ;
T_1 V_25 = 0UL ;
struct V_26 * V_26 = NULL ;
struct V_140 * V_141 = NULL ;
int V_177 = - 1 ;
if ( V_173 -> V_178 > 4 ) {
F_10 ( V_16 , L_41 ,
V_22 , V_173 -> V_178 ) ;
V_34 = - V_122 ;
goto V_45;
}
if ( V_66 -> V_98 == 0 ) {
F_10 ( V_16 , L_42 ,
V_22 , V_33 -> V_110 [ V_63 -> V_179 ] ) ;
V_34 = F_25 ( V_63 , V_33 ) ;
if ( V_34 ) {
F_23 ( V_16 , L_43 ,
V_22 , V_34 ) ;
V_34 = - V_88 ;
goto V_45;
}
F_10 ( V_16 , L_44 , V_22 , V_66 -> V_98 ) ;
F_10 ( V_16 , L_45 , V_22 , V_66 -> V_100 ) ;
}
if ( V_173 -> V_5 . V_176 & V_180 ) {
V_25 = V_173 -> V_6 ;
V_27 = F_15 ( V_14 , V_25 , NULL , 0 ) ;
if ( ! V_27 ) {
F_10 ( V_16 , L_46 ,
V_22 , V_25 ) ;
V_34 = - V_122 ;
goto V_45;
}
F_14 (lun_access, &ctxi->luns, list)
if ( V_31 -> V_33 == V_33 ) {
F_10 ( V_16 , L_47 ,
V_22 ) ;
V_34 = - V_122 ;
goto V_45;
}
}
V_34 = F_90 ( V_63 ) ;
if ( F_28 ( V_34 ) ) {
F_23 ( V_16 , L_48 , V_22 ) ;
goto V_45;
}
V_31 = F_27 ( sizeof( * V_31 ) , V_79 ) ;
if ( F_28 ( ! V_31 ) ) {
F_23 ( V_16 , L_49 , V_22 ) ;
V_34 = - V_82 ;
goto V_139;
}
V_31 -> V_33 = V_33 ;
V_31 -> V_63 = V_63 ;
if ( V_27 ) {
F_10 ( V_16 , L_50 ,
V_22 , V_25 ) ;
F_91 ( & V_27 -> V_146 ) ;
F_87 ( & V_31 -> V_147 , & V_27 -> V_135 ) ;
goto V_181;
}
V_27 = F_56 ( V_14 ) ;
if ( F_28 ( ! V_27 ) ) {
F_23 ( V_16 , L_51 ,
V_22 , V_28 ) ;
goto V_139;
}
V_141 = F_92 ( V_14 -> V_16 ) ;
if ( F_93 ( V_141 ) ) {
F_23 ( V_16 , L_52 ,
V_22 , V_141 ) ;
V_34 = - V_88 ;
goto V_139;
}
V_175 = & V_27 -> V_175 ;
V_175 -> V_178 = V_173 -> V_178 ;
V_175 -> V_176 = V_182 ;
V_34 = F_94 ( V_141 , V_175 ) ;
if ( F_28 ( V_34 ) ) {
F_10 ( V_16 , L_53 ,
V_22 , V_34 ) ;
goto V_139;
}
V_28 = F_74 ( V_141 ) ;
if ( F_28 ( ( V_28 >= V_19 ) || ( V_28 < 0 ) ) ) {
F_23 ( V_16 , L_54 , V_22 , V_28 ) ;
V_34 = - V_183 ;
goto V_139;
}
V_26 = F_95 ( V_141 , & V_14 -> V_152 , & V_177 ) ;
if ( F_28 ( V_177 < 0 ) ) {
V_34 = - V_88 ;
F_23 ( V_16 , L_55 , V_22 ) ;
goto V_139;
}
V_142 = F_96 ( V_173 -> V_5 . V_176 + 1 ) ;
F_58 ( V_27 , V_14 , V_141 , V_28 , V_26 , V_142 ) ;
V_34 = F_20 ( V_14 , V_27 ) ;
if ( F_28 ( V_34 ) ) {
F_23 ( V_16 , L_56 , V_22 , V_34 ) ;
goto V_139;
}
F_87 ( & V_31 -> V_147 , & V_27 -> V_135 ) ;
F_4 ( & V_14 -> V_42 ) ;
F_4 ( & V_27 -> V_11 ) ;
V_14 -> V_20 [ V_28 ] = V_27 ;
F_6 ( & V_14 -> V_42 ) ;
F_97 ( V_177 , V_26 ) ;
V_181:
if ( V_177 != - 1 )
V_176 |= V_184 ;
if ( F_98 ( V_49 ) )
V_176 |= V_185 ;
V_173 -> V_5 . V_186 = V_176 ;
V_173 -> V_6 = V_27 -> V_28 ;
V_173 -> V_187 = V_66 -> V_100 ;
V_173 -> V_188 = sizeof( V_49 -> V_136 -> V_189 [ 0 ] . V_190 ) ;
V_173 -> V_191 = V_66 -> V_98 ;
V_173 -> V_192 = V_63 -> V_64 -> V_193 * V_194 ;
V_173 -> V_192 /= V_66 -> V_100 ;
V_45:
V_173 -> V_195 = V_177 ;
if ( V_27 )
F_19 ( V_27 ) ;
F_10 ( V_16 , L_57 ,
V_22 , V_28 , V_177 , V_173 -> V_187 , V_34 , V_173 -> V_191 ) ;
return V_34 ;
V_139:
if ( ! F_93 ( V_141 ) ) {
F_99 ( V_141 ) ;
F_100 ( V_141 ) ;
V_141 = NULL ;
}
if ( V_177 > 0 ) {
V_26 -> V_151 = & V_196 ;
F_101 ( V_26 ) ;
F_102 ( V_177 ) ;
V_177 = - 1 ;
V_26 = NULL ;
}
if ( V_27 ) {
F_54 ( V_14 , V_27 ) ;
V_27 = NULL ;
}
F_35 ( V_31 ) ;
F_70 ( V_63 ) ;
goto V_45;
}
static int F_103 ( struct V_13 * V_14 ,
struct V_24 * V_27 ,
int * V_195 )
{
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
int V_34 = 0 ;
int V_177 = - 1 ;
int V_28 = - 1 ;
struct V_26 * V_26 ;
struct V_140 * V_141 ;
struct V_49 * V_49 = V_14 -> V_49 ;
V_141 = F_92 ( V_14 -> V_16 ) ;
if ( F_93 ( V_141 ) ) {
F_23 ( V_16 , L_52 ,
V_22 , V_141 ) ;
V_34 = - V_88 ;
goto V_45;
}
V_34 = F_94 ( V_141 , & V_27 -> V_175 ) ;
if ( F_28 ( V_34 ) ) {
F_10 ( V_16 , L_53 ,
V_22 , V_34 ) ;
goto V_197;
}
V_28 = F_74 ( V_141 ) ;
if ( F_28 ( ( V_28 >= V_19 ) || ( V_28 < 0 ) ) ) {
F_23 ( V_16 , L_54 , V_22 , V_28 ) ;
V_34 = - V_183 ;
goto V_198;
}
V_26 = F_95 ( V_141 , & V_14 -> V_152 , & V_177 ) ;
if ( F_28 ( V_177 < 0 ) ) {
V_34 = - V_88 ;
F_23 ( V_16 , L_55 , V_22 ) ;
goto V_198;
}
V_27 -> V_51 = & V_49 -> V_136 -> V_144 [ V_28 ] . V_145 ;
V_34 = F_20 ( V_14 , V_27 ) ;
if ( V_34 ) {
F_23 ( V_16 , L_56 , V_22 , V_34 ) ;
goto V_199;
}
V_27 -> V_28 = F_59 ( V_27 , V_28 ) ;
V_27 -> V_141 = V_141 ;
V_27 -> V_26 = V_26 ;
F_6 ( & V_27 -> V_11 ) ;
F_4 ( & V_14 -> V_42 ) ;
F_4 ( & V_27 -> V_11 ) ;
F_104 ( & V_27 -> V_147 ) ;
V_14 -> V_20 [ V_28 ] = V_27 ;
F_6 ( & V_14 -> V_42 ) ;
F_97 ( V_177 , V_26 ) ;
* V_195 = V_177 ;
V_45:
F_10 ( V_16 , L_58 ,
V_22 , V_28 , V_177 , V_34 ) ;
return V_34 ;
V_199:
F_101 ( V_26 ) ;
F_102 ( V_177 ) ;
V_198:
F_99 ( V_141 ) ;
V_197:
F_100 ( V_141 ) ;
goto V_45;
}
static int F_105 ( struct V_62 * V_63 ,
struct V_200 * V_201 )
{
struct V_13 * V_14 = F_26 ( V_63 -> V_64 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_32 * V_33 = V_63 -> V_126 ;
struct V_49 * V_49 = V_14 -> V_49 ;
struct V_24 * V_27 = NULL ;
struct V_11 * V_11 = & V_14 -> V_202 ;
T_1 V_176 ;
T_1 V_28 = F_16 ( V_201 -> V_6 ) ,
V_25 = V_201 -> V_6 ;
long V_203 ;
int V_204 = 20 ;
int V_205 = - 1 ;
int V_34 = 0 ;
F_106 ( & V_14 -> V_206 ) ;
F_30 ( & V_14 -> V_85 ) ;
V_34 = F_107 ( V_11 ) ;
F_32 ( & V_14 -> V_85 ) ;
if ( V_34 )
goto V_45;
V_34 = F_33 ( V_14 ) ;
if ( V_34 ) {
F_23 ( V_16 , L_59 , V_22 , V_34 ) ;
V_34 = - V_88 ;
goto V_45;
}
F_10 ( V_16 , L_60 ,
V_22 , V_201 -> V_207 , V_25 ) ;
V_77:
V_27 = F_15 ( V_14 , V_25 , V_33 , V_44 ) ;
if ( F_28 ( ! V_27 ) ) {
F_10 ( V_16 , L_21 , V_22 , V_28 ) ;
V_34 = - V_122 ;
goto V_45;
}
if ( V_27 -> V_132 ) {
V_208:
V_34 = F_103 ( V_14 , V_27 , & V_205 ) ;
if ( F_28 ( V_34 ) ) {
F_23 ( V_16 , L_61 ,
V_22 , V_28 , V_34 ) ;
if ( ( V_34 == - V_88 ) &&
( ( F_108 ( & V_14 -> V_206 ) > 1 ) ||
( V_204 -- ) ) ) {
F_10 ( V_16 , L_62 ,
V_22 ) ;
F_6 ( V_11 ) ;
F_109 ( 100 ) ;
V_34 = F_107 ( V_11 ) ;
if ( V_34 )
goto V_45;
goto V_208;
}
goto V_45;
}
V_27 -> V_132 = false ;
V_176 = V_184 |
V_209 ;
if ( F_98 ( V_49 ) )
V_176 |= V_185 ;
V_201 -> V_5 . V_186 = V_176 ;
V_201 -> V_6 = V_27 -> V_28 ;
V_201 -> V_195 = V_205 ;
V_201 -> V_188 = sizeof( V_49 -> V_136 -> V_189 [ 0 ] . V_190 ) ;
goto V_45;
}
V_203 = F_21 ( & V_49 -> V_51 -> V_53 ) ;
if ( V_203 == - 1 ) {
F_10 ( V_16 , L_63 , V_22 ) ;
F_19 ( V_27 ) ;
V_27 = NULL ;
F_12 ( 1 ) ;
V_34 = F_33 ( V_14 ) ;
if ( F_28 ( V_34 ) )
goto V_45;
goto V_77;
}
F_10 ( V_16 , L_64 , V_22 ) ;
V_45:
if ( F_17 ( V_27 ) )
F_19 ( V_27 ) ;
F_6 ( V_11 ) ;
F_110 ( & V_14 -> V_206 ) ;
return V_34 ;
}
static int F_111 ( struct V_62 * V_63 ,
struct V_210 * V_211 )
{
struct V_13 * V_14 = F_26 ( V_63 -> V_64 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_32 * V_33 = V_63 -> V_126 ;
struct V_65 * V_66 = V_33 -> V_41 ;
T_1 V_212 = V_66 -> V_98 ;
struct V_67 V_68 = { 0 } ;
int V_34 = 0 ;
V_34 = F_112 ( ( const T_4 * ) & V_211 -> V_213 ,
V_214 , & V_68 ) ;
if ( ! V_34 ) {
F_23 ( V_16 , L_65 , V_22 ) ;
V_34 = - V_122 ;
goto V_45;
}
switch ( V_68 . V_91 ) {
case V_92 :
case V_93 :
case V_94 :
break;
case V_95 :
switch ( V_68 . V_96 ) {
case 0x29 :
case 0x2A :
V_34 = F_25 ( V_63 , V_33 ) ;
if ( V_34 ) {
V_34 = - V_88 ;
break;
}
if ( V_212 != V_66 -> V_98 )
F_10 ( V_16 , L_66
L_67 , V_22 , V_212 ,
V_66 -> V_98 ) ;
break;
case 0x3F :
F_113 ( V_14 -> V_64 ) ;
break;
default:
V_34 = - V_97 ;
break;
}
break;
default:
V_34 = - V_97 ;
break;
}
V_45:
F_10 ( V_16 , L_68 , V_22 ,
V_68 . V_91 , V_68 . V_96 , V_68 . V_215 , V_34 ) ;
return V_34 ;
}
static int F_114 ( struct V_62 * V_63 ,
struct V_210 * V_211 )
{
int V_34 = 0 ;
struct V_24 * V_27 = NULL ;
struct V_13 * V_14 = F_26 ( V_63 -> V_64 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_32 * V_33 = V_63 -> V_126 ;
struct V_65 * V_66 = V_33 -> V_41 ;
struct V_102 * V_104 = NULL ;
T_6 V_103 = V_211 -> V_7 ;
T_1 V_28 = F_16 ( V_211 -> V_6 ) ,
V_25 = V_211 -> V_6 ;
T_1 V_191 = 0 ;
F_10 ( V_16 , L_69
L_70 , V_22 , V_28 , V_211 -> V_7 ,
V_211 -> V_216 , V_211 -> V_5 . V_176 ) ;
V_27 = F_15 ( V_14 , V_25 , V_33 , 0 ) ;
if ( F_28 ( ! V_27 ) ) {
F_10 ( V_16 , L_21 , V_22 , V_28 ) ;
V_34 = - V_122 ;
goto V_45;
}
V_104 = F_38 ( V_27 , V_103 , V_33 ) ;
if ( F_28 ( ! V_104 ) ) {
F_10 ( V_16 , L_13 ,
V_22 , V_103 ) ;
V_34 = - V_122 ;
goto V_45;
}
if ( V_211 -> V_216 & V_217 ) {
V_27 -> V_46 = true ;
F_6 ( & V_27 -> V_11 ) ;
V_34 = F_111 ( V_63 , V_211 ) ;
if ( F_28 ( V_34 ) ) {
F_23 ( V_16 , L_71 ,
V_22 , V_34 ) ;
F_4 ( & V_27 -> V_11 ) ;
V_27 -> V_46 = false ;
goto V_45;
}
F_4 ( & V_27 -> V_11 ) ;
V_27 -> V_46 = false ;
}
switch ( V_66 -> V_119 ) {
case V_131 :
V_191 = V_66 -> V_98 ;
break;
case V_129 :
V_191 = ( ( T_1 ) V_104 -> V_218 * V_219 * V_66 -> V_100 ) ;
V_191 /= V_220 ;
V_191 -- ;
break;
default:
F_52 ( 1 , L_23 ) ;
}
V_211 -> V_191 = V_191 ;
V_45:
if ( F_17 ( V_27 ) )
F_19 ( V_27 ) ;
F_10 ( V_16 , L_72 ,
V_22 , V_34 , V_211 -> V_191 ) ;
return V_34 ;
}
static char * F_115 ( int V_221 )
{
switch ( V_221 ) {
case V_222 :
return F_116 ( V_222 ) ;
case V_223 :
return F_116 ( V_223 ) ;
case V_224 :
return F_116 ( V_224 ) ;
case V_225 :
return F_116 ( V_225 ) ;
case V_226 :
return F_116 ( V_226 ) ;
case V_227 :
return F_116 ( V_227 ) ;
case V_228 :
return F_116 ( V_228 ) ;
case V_229 :
return F_116 ( V_229 ) ;
case V_230 :
return F_116 ( V_230 ) ;
case V_231 :
return F_116 ( V_231 ) ;
}
return L_73 ;
}
static int F_117 ( struct V_62 * V_63 , void * V_29 )
{
struct V_13 * V_14 = F_26 ( V_63 -> V_64 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_49 * V_49 = V_14 -> V_49 ;
struct V_32 * V_33 = V_63 -> V_126 ;
struct V_65 * V_66 = V_33 -> V_41 ;
struct V_232 * V_233 = (struct V_232 * ) V_29 ;
T_1 V_28 = F_16 ( V_233 -> V_6 ) ,
V_25 = V_233 -> V_6 ;
T_1 V_234 = 0 ;
T_1 V_191 = 0 ;
T_1 V_7 = - 1 ;
T_5 V_235 = F_118 ( V_63 -> V_179 ) ;
int V_34 = 0 ;
struct V_24 * V_27 = NULL ;
struct V_102 * V_104 = NULL ;
F_10 ( V_16 , L_74 , V_22 , V_28 , V_234 ) ;
V_34 = F_44 ( V_66 , V_131 , false ) ;
if ( F_28 ( V_34 ) ) {
F_10 ( V_16 , L_75 , V_22 ) ;
goto V_45;
}
V_27 = F_15 ( V_14 , V_25 , V_33 , 0 ) ;
if ( F_28 ( ! V_27 ) ) {
F_10 ( V_16 , L_21 , V_22 , V_28 ) ;
V_34 = - V_122 ;
goto V_197;
}
V_104 = F_39 ( V_27 , V_33 ) ;
if ( F_28 ( ! V_104 ) ) {
F_10 ( V_16 , L_76 ,
V_22 , V_28 ) ;
V_34 = - V_236 ;
goto V_197;
}
V_7 = ( V_104 - V_27 -> V_58 ) ;
F_41 ( V_104 , V_33 -> V_110 [ V_63 -> V_179 ] , V_27 -> V_143 , V_235 ) ;
F_51 ( V_49 , V_28 , V_7 , V_237 ) ;
V_191 = V_66 -> V_98 ;
V_233 -> V_5 . V_186 = 0 ;
V_233 -> V_191 = V_191 ;
V_233 -> V_7 = V_7 ;
V_45:
if ( F_17 ( V_27 ) )
F_19 ( V_27 ) ;
F_10 ( V_16 , L_77 ,
V_22 , V_7 , V_34 , V_191 ) ;
return V_34 ;
V_197:
F_47 ( V_66 ) ;
goto V_45;
}
static int F_119 ( struct V_62 * V_63 , int V_221 )
{
struct V_13 * V_14 = F_26 ( V_63 -> V_64 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_32 * V_33 = V_63 -> V_126 ;
int V_34 = 0 ;
if ( F_28 ( ! V_33 ) ) {
F_10 ( V_16 , L_78 , V_22 ) ;
V_34 = - V_122 ;
goto V_45;
}
V_34 = F_33 ( V_14 ) ;
if ( F_28 ( V_34 ) && ( V_14 -> V_169 == V_171 ) ) {
switch ( V_221 ) {
case V_225 :
case V_226 :
case V_227 :
F_10 ( V_16 , L_79 ,
V_22 , V_34 ) ;
V_34 = 0 ;
break;
}
}
V_45:
return V_34 ;
}
int F_120 ( struct V_62 * V_63 , int V_221 , void T_7 * V_29 )
{
typedef int (* F_121) ( struct V_62 * , void * );
struct V_13 * V_14 = F_26 ( V_63 -> V_64 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_49 * V_49 = V_14 -> V_49 ;
struct V_238 * V_5 ;
char V_239 [ sizeof( union V_240 ) ] ;
T_8 V_128 = 0 ;
bool V_241 = false ;
int V_242 ;
int V_34 = 0 ;
struct V_243 * V_244 = V_63 -> V_64 ;
F_121 V_245 = NULL ;
static const struct {
T_8 V_128 ;
F_121 V_246 ;
} V_247 [] = {
{ sizeof( struct V_172 ) , ( F_121 ) F_89 } ,
{ sizeof( struct V_232 ) , F_117 } ,
{ sizeof( struct V_1 ) , ( F_121 ) F_53 } ,
{ sizeof( struct V_8 ) , ( F_121 ) F_71 } ,
{ sizeof( struct V_210 ) , ( F_121 ) F_114 } ,
{ sizeof( struct V_200 ) , ( F_121 ) F_105 } ,
{ sizeof( struct V_248 ) , ( F_121 ) V_249 } ,
{ sizeof( struct V_250 ) , V_251 } ,
{ sizeof( struct V_3 ) , ( F_121 ) V_252 } ,
{ sizeof( struct V_253 ) , ( F_121 ) V_254 } ,
} ;
F_32 ( & V_14 -> V_85 ) ;
if ( V_49 -> V_255 )
switch ( V_221 ) {
case V_226 :
case V_224 :
case V_225 :
case V_229 :
F_10 ( V_16 , L_80 ,
V_22 , F_115 ( V_221 ) , V_49 -> V_255 ) ;
V_34 = - V_122 ;
goto V_256;
}
switch ( V_221 ) {
case V_222 :
case V_223 :
case V_226 :
case V_227 :
case V_228 :
case V_230 :
case V_224 :
case V_225 :
case V_229 :
F_10 ( V_16 , L_81 ,
V_22 , F_115 ( V_221 ) , V_221 , V_244 -> V_257 ,
V_63 -> V_179 , V_63 -> V_258 , V_63 -> V_259 ) ;
V_34 = F_119 ( V_63 , V_221 ) ;
if ( F_28 ( V_34 ) )
goto V_256;
case V_231 :
V_241 = true ;
V_242 = F_122 ( V_221 ) - F_122 ( V_222 ) ;
V_128 = V_247 [ V_242 ] . V_128 ;
V_245 = V_247 [ V_242 ] . V_246 ;
if ( F_17 ( V_245 ) )
break;
default:
V_34 = - V_122 ;
goto V_256;
}
if ( F_28 ( F_123 ( & V_239 , V_29 , V_128 ) ) ) {
F_23 ( V_16 , L_82
L_83 ,
V_22 , V_128 , V_221 , F_115 ( V_221 ) , V_29 ) ;
V_34 = - V_260 ;
goto V_256;
}
V_5 = (struct V_238 * ) & V_239 ;
if ( V_5 -> V_261 != V_262 ) {
F_10 ( V_16 , L_84 ,
V_22 , V_5 -> V_261 , F_115 ( V_221 ) ) ;
V_34 = - V_122 ;
goto V_256;
}
if ( V_5 -> V_263 [ 0 ] || V_5 -> V_263 [ 1 ] || V_5 -> V_263 [ 2 ] || V_5 -> V_186 ) {
F_10 ( V_16 , L_85 , V_22 ) ;
V_34 = - V_122 ;
goto V_256;
}
V_34 = V_245 ( V_63 , ( void * ) & V_239 ) ;
if ( F_17 ( ! V_34 ) )
if ( F_28 ( F_124 ( V_29 , & V_239 , V_128 ) ) ) {
F_23 ( V_16 , L_86
L_83 ,
V_22 , V_128 , V_221 , F_115 ( V_221 ) , V_29 ) ;
V_34 = - V_260 ;
}
V_256:
F_30 ( & V_14 -> V_85 ) ;
if ( F_28 ( V_34 && V_241 ) )
F_23 ( V_16 , L_87
L_88 , V_22 ,
F_115 ( V_221 ) , V_221 , V_244 -> V_257 ,
V_63 -> V_179 , V_63 -> V_258 , V_63 -> V_259 , V_34 ) ;
else
F_10 ( V_16 , L_87
L_88 , V_22 , F_115 ( V_221 ) ,
V_221 , V_244 -> V_257 , V_63 -> V_179 , V_63 -> V_258 ,
V_63 -> V_259 , V_34 ) ;
return V_34 ;
}
