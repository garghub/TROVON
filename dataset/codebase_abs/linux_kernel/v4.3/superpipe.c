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
V_34 = F_18 ( & V_14 -> V_42 ) ;
if ( V_34 )
goto V_43;
V_27 = V_14 -> V_20 [ V_28 ] ;
if ( V_27 )
if ( ( V_26 && ( V_27 -> V_26 != V_26 ) ) ||
( ! V_26 && ( V_27 -> V_28 != V_25 ) ) )
V_27 = NULL ;
if ( ( V_30 & V_44 ) ||
( ! V_27 && ( V_30 & V_45 ) ) )
V_27 = F_13 ( V_14 , V_25 , V_26 ) ;
if ( ! V_27 ) {
F_6 ( & V_14 -> V_42 ) ;
goto V_43;
}
V_34 = F_19 ( & V_27 -> V_11 ) ;
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
goto V_43;
goto V_47;
}
}
V_43:
F_10 ( V_16 , L_2
L_3 , V_22 , V_25 , V_27 , V_38 , V_35 ,
V_30 ) ;
return V_27 ;
V_47:
F_6 ( & V_27 -> V_11 ) ;
V_27 = NULL ;
goto V_43;
}
void F_20 ( struct V_24 * V_27 )
{
F_6 ( & V_27 -> V_11 ) ;
}
static int F_21 ( struct V_13 * V_14 , struct V_24 * V_27 )
{
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_49 * V_49 = V_14 -> V_49 ;
struct V_50 * V_51 = V_27 -> V_51 ;
int V_34 = 0 ;
T_1 V_52 ;
F_22 ( & V_51 -> V_53 ) ;
V_52 = ( V_54 | V_55 ) ;
F_23 ( V_52 , & V_51 -> V_56 ) ;
V_52 = F_22 ( & V_51 -> V_56 ) ;
if ( V_52 != ( V_54 | V_55 ) ) {
F_24 ( V_16 , L_4 ,
V_22 , V_52 ) ;
V_34 = - V_57 ;
goto V_43;
}
F_23 ( ( T_1 ) V_27 -> V_58 , & V_51 -> V_58 ) ;
V_52 = F_25 ( ( T_1 ) V_59 , ( T_1 ) ( V_49 -> V_60 ) ) ;
F_23 ( V_52 , & V_51 -> V_61 ) ;
V_43:
F_10 ( V_16 , L_5 , V_22 , V_34 ) ;
return V_34 ;
}
static int F_26 ( struct V_62 * V_63 , struct V_32 * V_33 )
{
struct V_13 * V_14 = (struct V_13 * ) V_63 -> V_64 -> V_65 ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_66 * V_67 = V_33 -> V_41 ;
T_3 * V_68 = NULL ;
T_3 * V_69 = NULL ;
T_3 * V_70 = NULL ;
int V_34 = 0 ;
int V_71 = 0 ;
int V_72 = 0 ;
T_4 V_73 = ( V_74 * V_75 ) ;
V_76:
V_68 = F_27 ( V_77 , V_78 ) ;
V_69 = F_27 ( V_79 , V_78 ) ;
V_70 = F_27 ( V_80 , V_78 ) ;
if ( F_28 ( ! V_68 || ! V_69 || ! V_70 ) ) {
V_34 = - V_81 ;
goto V_43;
}
V_69 [ 0 ] = V_82 ;
V_69 [ 1 ] = V_83 ;
F_29 ( V_77 , & V_69 [ 10 ] ) ;
F_10 ( V_16 , L_6 , V_22 ,
V_72 ? L_7 : L_8 , V_69 [ 0 ] ) ;
V_71 = F_30 ( V_63 , V_69 , V_84 , V_68 ,
V_77 , V_70 , V_73 , 5 , 0 , NULL ) ;
if ( F_31 ( V_71 ) == V_85 ) {
V_71 &= ~ ( 0xFF << 24 ) ;
if ( V_71 & V_86 ) {
struct V_87 V_88 ;
F_32 ( V_70 , V_80 ,
& V_88 ) ;
switch ( V_88 . V_89 ) {
case V_90 :
case V_91 :
case V_92 :
V_71 &= ~ V_86 ;
break;
case V_93 :
switch ( V_88 . V_94 ) {
case 0x29 :
case 0x2A :
case 0x3F :
if ( V_72 ++ < 1 ) {
F_33 ( V_68 ) ;
F_33 ( V_69 ) ;
F_33 ( V_70 ) ;
goto V_76;
}
}
break;
default:
break;
}
}
}
if ( V_71 ) {
F_24 ( V_16 , L_9 ,
V_22 , V_71 ) ;
V_34 = - V_95 ;
goto V_43;
}
F_4 ( & V_67 -> V_11 ) ;
V_67 -> V_96 = F_34 ( * ( ( T_1 * ) & V_68 [ 0 ] ) ) ;
V_67 -> V_97 = F_35 ( * ( ( T_4 * ) & V_68 [ 8 ] ) ) ;
F_6 ( & V_67 -> V_11 ) ;
V_43:
F_33 ( V_68 ) ;
F_33 ( V_69 ) ;
F_33 ( V_70 ) ;
F_10 ( V_16 , L_10 ,
V_22 , V_67 -> V_96 , V_67 -> V_97 , V_34 ) ;
return V_34 ;
}
struct V_98 * F_36 ( struct V_24 * V_27 , T_5 V_99 ,
struct V_32 * V_33 )
{
struct V_98 * V_100 = NULL ;
if ( F_28 ( ! V_27 -> V_58 ) ) {
F_37 ( L_11 ,
V_22 ) ;
goto V_43;
}
if ( F_28 ( V_99 >= V_59 ) ) {
F_37 ( L_12 , V_22 , V_99 ) ;
goto V_43;
}
if ( F_28 ( V_27 -> V_101 [ V_99 ] != V_33 ) ) {
F_37 ( L_13 ,
V_22 , V_99 ) ;
goto V_43;
}
V_100 = & V_27 -> V_58 [ V_99 ] ;
if ( F_28 ( V_100 -> V_102 == 0 ) ) {
F_37 ( L_14 ,
V_22 , V_99 ) ;
V_100 = NULL ;
goto V_43;
}
V_43:
return V_100 ;
}
struct V_98 * F_38 ( struct V_24 * V_27 ,
struct V_32 * V_33 )
{
struct V_98 * V_100 = NULL ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_59 ; V_17 ++ )
if ( V_27 -> V_58 [ V_17 ] . V_102 == 0 ) {
V_100 = & V_27 -> V_58 [ V_17 ] ;
V_27 -> V_103 ++ ;
break;
}
if ( F_17 ( V_100 ) )
V_27 -> V_101 [ V_17 ] = V_33 ;
F_37 ( L_15 , V_22 , V_100 , V_17 ) ;
return V_100 ;
}
void F_39 ( struct V_24 * V_27 ,
struct V_98 * V_100 )
{
T_4 V_7 = V_100 - V_27 -> V_58 ;
V_100 -> V_102 = 0 ;
V_100 -> V_104 = 0 ;
V_27 -> V_103 -- ;
V_27 -> V_101 [ V_7 ] = NULL ;
V_27 -> V_105 [ V_7 ] = false ;
}
static void F_40 ( struct V_98 * V_100 , T_1 V_106 , T_4 V_107 ,
T_4 V_108 )
{
struct V_109 V_110 = { 0 } ;
struct V_109 * V_111 = (struct V_109 * ) V_100 ;
memset ( V_111 , 0 , sizeof( * V_111 ) ) ;
V_111 -> V_104 = F_41 ( 1U , 0 ) ;
F_42 () ;
V_111 -> V_106 = V_106 ;
F_42 () ;
V_110 . V_112 = 0x80 ;
V_110 . V_104 = F_41 ( 1U , V_107 ) ;
V_110 . V_108 = V_108 ;
V_111 -> V_113 = V_110 . V_113 ;
F_42 () ;
}
int F_43 ( struct V_66 * V_67 , enum V_114 V_115 , bool V_116 )
{
int V_34 = 0 ;
if ( ! V_116 )
F_4 ( & V_67 -> V_11 ) ;
if ( V_67 -> V_115 == V_117 )
V_67 -> V_115 = V_115 ;
else if ( V_67 -> V_115 != V_115 ) {
F_37 ( L_16 ,
V_22 , V_67 -> V_115 , V_115 ) ;
V_34 = - V_118 ;
goto V_43;
}
V_67 -> V_119 ++ ;
F_44 ( V_67 -> V_119 <= 0 ) ;
V_43:
F_37 ( L_17 ,
V_22 , V_34 , V_67 -> V_115 , V_67 -> V_119 ) ;
if ( ! V_116 )
F_6 ( & V_67 -> V_11 ) ;
return V_34 ;
}
void F_45 ( struct V_66 * V_67 )
{
F_4 ( & V_67 -> V_11 ) ;
F_44 ( V_67 -> V_115 == V_117 ) ;
if ( -- V_67 -> V_119 == 0 ) {
V_67 -> V_115 = V_117 ;
F_46 ( & V_67 -> V_120 . V_121 ) ;
}
F_37 ( L_18 , V_22 , V_67 -> V_119 ) ;
F_44 ( V_67 -> V_119 < 0 ) ;
F_6 ( & V_67 -> V_11 ) ;
}
int F_47 ( struct V_62 * V_63 ,
struct V_24 * V_27 ,
struct V_1 * V_2 )
{
struct V_13 * V_14 = (struct V_13 * ) V_63 -> V_64 -> V_65 ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_32 * V_33 = V_63 -> V_65 ;
struct V_66 * V_67 = V_33 -> V_41 ;
struct V_49 * V_49 = V_14 -> V_49 ;
bool V_122 = false ;
struct V_3 V_123 ;
T_5 V_99 = V_2 -> V_7 ;
int V_34 = 0 ;
T_1 V_28 = F_16 ( V_2 -> V_6 ) ,
V_25 = V_2 -> V_6 ;
struct V_98 * V_100 ;
struct V_109 * V_111 ;
F_10 ( V_16 , L_19 ,
V_22 , V_28 , V_2 -> V_7 , V_67 -> V_115 , V_67 -> V_119 ) ;
if ( ! V_27 ) {
V_27 = F_15 ( V_14 , V_25 , V_33 , V_45 ) ;
if ( F_28 ( ! V_27 ) ) {
F_10 ( V_16 , L_20 ,
V_22 , V_28 ) ;
V_34 = - V_118 ;
goto V_43;
}
V_122 = true ;
}
V_100 = F_36 ( V_27 , V_99 , V_33 ) ;
if ( F_28 ( ! V_100 ) ) {
F_10 ( V_16 , L_12 ,
V_22 , V_99 ) ;
V_34 = - V_118 ;
goto V_43;
}
switch ( V_67 -> V_115 ) {
case V_124 :
F_1 ( V_2 , & V_123 ) ;
V_123 . V_125 = 0 ;
V_34 = F_48 ( V_63 , V_27 , & V_123 ) ;
if ( V_34 ) {
F_10 ( V_16 , L_21 , V_22 , V_34 ) ;
goto V_43;
}
break;
case V_126 :
V_111 = (struct V_109 * ) V_100 ;
V_111 -> V_112 = 0 ;
F_42 () ;
V_111 -> V_106 = 0 ;
F_42 () ;
V_111 -> V_113 = 0 ;
F_42 () ;
if ( ! V_27 -> V_127 )
F_49 ( V_49 , V_28 , V_99 , V_128 ) ;
break;
default:
F_50 ( 1 , L_22 ) ;
goto V_43;
}
F_39 ( V_27 , V_100 ) ;
F_45 ( V_67 ) ;
V_43:
if ( V_122 )
F_20 ( V_27 ) ;
F_10 ( V_16 , L_5 , V_22 , V_34 ) ;
return V_34 ;
}
int F_51 ( struct V_62 * V_63 ,
struct V_1 * V_2 )
{
return F_47 ( V_63 , NULL , V_2 ) ;
}
static void F_52 ( struct V_13 * V_14 ,
struct V_24 * V_27 )
{
struct V_49 * V_49 = V_14 -> V_49 ;
F_44 ( ! F_9 ( & V_27 -> V_129 ) ) ;
if ( V_49 -> V_130 && V_27 -> V_51 ) {
F_23 ( 0 , & V_27 -> V_51 -> V_58 ) ;
F_23 ( 0 , & V_27 -> V_51 -> V_61 ) ;
F_23 ( 0 , & V_27 -> V_51 -> V_56 ) ;
}
F_53 ( ( V_131 ) V_27 -> V_58 ) ;
F_33 ( V_27 -> V_105 ) ;
F_33 ( V_27 -> V_101 ) ;
F_33 ( V_27 ) ;
F_54 ( & V_14 -> V_132 ) ;
}
static struct V_24 * F_55 ( struct V_13 * V_14 ,
struct V_133 * V_134 , int V_28 ,
int V_135 , struct V_26 * V_26 ,
T_4 V_136 )
{
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_49 * V_49 = V_14 -> V_49 ;
struct V_24 * V_27 = NULL ;
struct V_32 * * V_33 = NULL ;
bool * V_137 = NULL ;
struct V_98 * V_100 ;
V_27 = F_27 ( sizeof( * V_27 ) , V_78 ) ;
V_33 = F_27 ( ( V_59 * sizeof( * V_33 ) ) , V_78 ) ;
V_137 = F_27 ( ( V_59 * sizeof( * V_137 ) ) , V_78 ) ;
if ( F_28 ( ! V_27 || ! V_33 || ! V_137 ) ) {
F_24 ( V_16 , L_23 , V_22 ) ;
goto V_138;
}
V_100 = (struct V_98 * ) F_56 ( V_78 ) ;
if ( F_28 ( ! V_100 ) ) {
F_24 ( V_16 , L_24 , V_22 ) ;
goto V_138;
}
V_27 -> V_101 = V_33 ;
V_27 -> V_105 = V_137 ;
V_27 -> V_58 = V_100 ;
V_27 -> V_139 = V_136 ;
V_27 -> V_51 = & V_49 -> V_130 -> V_140 [ V_28 ] . V_141 ;
V_27 -> V_28 = F_57 ( V_27 , V_28 ) ;
V_27 -> V_142 = V_135 ;
V_27 -> V_35 = V_36 -> V_37 ;
V_27 -> V_134 = V_134 ;
V_27 -> V_26 = V_26 ;
F_58 ( & V_27 -> V_11 ) ;
F_59 ( & V_27 -> V_129 ) ;
F_59 ( & V_27 -> V_143 ) ;
F_60 ( & V_14 -> V_132 ) ;
F_4 ( & V_27 -> V_11 ) ;
V_43:
return V_27 ;
V_138:
F_33 ( V_137 ) ;
F_33 ( V_33 ) ;
F_33 ( V_27 ) ;
V_27 = NULL ;
goto V_43;
}
static int F_61 ( struct V_62 * V_63 ,
struct V_24 * V_27 ,
struct V_8 * V_9 )
{
struct V_13 * V_14 = (struct V_13 * ) V_63 -> V_64 -> V_65 ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_32 * V_33 = V_63 -> V_65 ;
struct V_31 * V_31 , * V_144 ;
struct V_1 V_145 ;
bool V_122 = false ;
int V_17 ;
int V_34 = 0 ;
int V_142 ;
T_1 V_28 = F_16 ( V_9 -> V_6 ) ,
V_25 = V_9 -> V_6 ;
F_10 ( V_16 , L_25 , V_22 , V_28 ) ;
if ( ! V_27 ) {
V_27 = F_15 ( V_14 , V_25 , V_33 , V_45 ) ;
if ( F_28 ( ! V_27 ) ) {
F_10 ( V_16 , L_20 ,
V_22 , V_28 ) ;
V_34 = - V_118 ;
goto V_43;
}
V_122 = true ;
}
if ( V_27 -> V_103 ) {
F_2 ( V_9 , & V_145 ) ;
for ( V_17 = 0 ; V_17 < V_59 ; V_17 ++ ) {
if ( V_27 -> V_101 [ V_17 ] == V_33 ) {
V_145 . V_7 = V_17 ;
F_47 ( V_63 , V_27 , & V_145 ) ;
}
if ( V_27 -> V_103 == 0 )
break;
}
}
F_62 (lun_access, t, &ctxi->luns, list)
if ( V_31 -> V_33 == V_33 ) {
F_63 ( & V_31 -> V_143 ) ;
F_33 ( V_31 ) ;
V_31 = NULL ;
break;
}
if ( F_9 ( & V_27 -> V_129 ) ) {
V_27 -> V_46 = true ;
F_6 ( & V_27 -> V_11 ) ;
F_4 ( & V_14 -> V_42 ) ;
F_4 ( & V_27 -> V_11 ) ;
if ( ! F_9 ( & V_27 -> V_143 ) )
F_63 ( & V_27 -> V_143 ) ;
V_14 -> V_20 [ V_28 ] = NULL ;
F_6 ( & V_14 -> V_42 ) ;
F_6 ( & V_27 -> V_11 ) ;
V_142 = V_27 -> V_142 ;
F_52 ( V_14 , V_27 ) ;
V_27 = NULL ;
V_122 = false ;
if ( V_142 != - 1 )
F_64 ( V_142 ) ;
}
V_43:
if ( V_122 )
F_20 ( V_27 ) ;
F_10 ( V_16 , L_5 , V_22 , V_34 ) ;
return V_34 ;
}
static int F_65 ( struct V_62 * V_63 ,
struct V_8 * V_9 )
{
return F_61 ( V_63 , NULL , V_9 ) ;
}
static int F_66 ( struct V_146 * V_146 , struct V_26 * V_26 )
{
struct V_133 * V_134 = F_67 ( V_26 ) ;
struct V_13 * V_14 = F_68 ( V_26 -> V_147 , struct V_13 ,
V_148 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_24 * V_27 = NULL ;
struct V_8 V_9 = { { 0 } , 0 } ;
struct V_31 * V_31 , * V_144 ;
enum V_30 V_141 = V_45 | V_39 ;
int V_28 ;
V_28 = F_69 ( V_134 ) ;
if ( F_28 ( V_28 < 0 ) ) {
F_24 ( V_16 , L_26 ,
V_22 , V_134 , V_28 ) ;
goto V_43;
}
V_27 = F_15 ( V_14 , V_28 , V_26 , V_141 ) ;
if ( F_28 ( ! V_27 ) ) {
V_27 = F_15 ( V_14 , V_28 , V_26 , V_141 | V_40 ) ;
if ( ! V_27 ) {
F_10 ( V_16 , L_27 ,
V_22 , V_28 ) ;
goto V_149;
}
F_10 ( V_16 , L_28 ,
V_22 , V_28 ) ;
F_20 ( V_27 ) ;
goto V_43;
}
F_10 ( V_16 , L_29 ,
V_22 , V_27 -> V_142 , V_28 ) ;
V_27 -> V_142 = - 1 ;
V_9 . V_6 = V_27 -> V_28 ;
F_62 (lun_access, t, &ctxi->luns, list)
F_61 ( V_31 -> V_63 , V_27 , & V_9 ) ;
V_149:
F_70 ( V_146 , V_26 ) ;
V_43:
F_10 ( V_16 , L_30 , V_22 ) ;
return 0 ;
}
static void F_71 ( struct V_24 * V_27 )
{
F_72 ( V_27 -> V_26 -> V_150 , 0 , 0 , 1 ) ;
}
static struct V_151 * F_73 ( void )
{
struct V_151 * V_12 = V_10 . V_12 ;
if ( F_28 ( ! V_12 ) ) {
V_12 = F_74 ( V_78 ) ;
if ( F_28 ( ! V_12 ) ) {
F_75 ( L_31 , V_22 ) ;
goto V_43;
}
memset ( F_76 ( V_12 ) , - 1 , V_152 ) ;
F_4 ( & V_10 . V_11 ) ;
if ( F_17 ( ! V_10 . V_12 ) )
V_10 . V_12 = V_12 ;
else {
F_5 ( V_12 ) ;
V_12 = V_10 . V_12 ;
}
F_6 ( & V_10 . V_11 ) ;
}
V_43:
F_37 ( L_32 , V_22 , V_12 ) ;
return V_12 ;
}
static int F_77 ( struct V_153 * V_154 , struct V_155 * V_156 )
{
struct V_26 * V_26 = V_154 -> V_157 ;
struct V_133 * V_134 = F_67 ( V_26 ) ;
struct V_13 * V_14 = F_68 ( V_26 -> V_147 , struct V_13 ,
V_148 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_24 * V_27 = NULL ;
struct V_151 * V_12 = NULL ;
enum V_30 V_141 = V_45 | V_39 ;
int V_34 = 0 ;
int V_28 ;
V_28 = F_69 ( V_134 ) ;
if ( F_28 ( V_28 < 0 ) ) {
F_24 ( V_16 , L_26 ,
V_22 , V_134 , V_28 ) ;
goto V_138;
}
V_27 = F_15 ( V_14 , V_28 , V_26 , V_141 ) ;
if ( F_28 ( ! V_27 ) ) {
F_10 ( V_16 , L_33 , V_22 , V_28 ) ;
goto V_138;
}
F_10 ( V_16 , L_34 ,
V_22 , V_27 -> V_142 , V_28 ) ;
if ( F_17 ( ! V_27 -> V_127 ) ) {
V_154 -> V_158 = F_78 ( V_154 -> V_158 ) ;
V_34 = V_27 -> V_159 -> V_160 ( V_154 , V_156 ) ;
} else {
F_10 ( V_16 , L_35 ,
V_22 ) ;
V_12 = F_73 () ;
if ( F_28 ( ! V_12 ) ) {
F_24 ( V_16 , L_36 ,
V_22 ) ;
V_34 = V_161 ;
goto V_43;
}
F_79 ( V_12 ) ;
V_156 -> V_151 = V_12 ;
V_154 -> V_158 = F_80 ( V_154 -> V_158 ) ;
}
V_43:
if ( F_17 ( V_27 ) )
F_20 ( V_27 ) ;
F_10 ( V_16 , L_5 , V_22 , V_34 ) ;
return V_34 ;
V_138:
V_34 = V_162 ;
goto V_43;
}
static int F_81 ( struct V_26 * V_26 , struct V_153 * V_154 )
{
struct V_133 * V_134 = F_67 ( V_26 ) ;
struct V_13 * V_14 = F_68 ( V_26 -> V_147 , struct V_13 ,
V_148 ) ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_24 * V_27 = NULL ;
enum V_30 V_141 = V_45 | V_39 ;
int V_28 ;
int V_34 = 0 ;
V_28 = F_69 ( V_134 ) ;
if ( F_28 ( V_28 < 0 ) ) {
F_24 ( V_16 , L_26 ,
V_22 , V_134 , V_28 ) ;
V_34 = - V_95 ;
goto V_43;
}
V_27 = F_15 ( V_14 , V_28 , V_26 , V_141 ) ;
if ( F_28 ( ! V_27 ) ) {
F_10 ( V_16 , L_33 , V_22 , V_28 ) ;
V_34 = - V_95 ;
goto V_43;
}
F_10 ( V_16 , L_37 ,
V_22 , V_27 -> V_142 , V_28 ) ;
V_34 = F_82 ( V_26 , V_154 ) ;
if ( F_17 ( ! V_34 ) ) {
V_27 -> V_159 = V_154 -> V_163 ;
V_154 -> V_163 = & V_164 ;
}
V_43:
if ( F_17 ( V_27 ) )
F_20 ( V_27 ) ;
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
F_83 ( & V_27 -> V_143 , & V_14 -> V_21 ) ;
V_27 -> V_127 = true ;
V_27 -> V_51 = NULL ;
F_71 ( V_27 ) ;
F_6 ( & V_27 -> V_11 ) ;
}
}
F_6 ( & V_14 -> V_42 ) ;
return V_34 ;
}
static int F_84 ( struct V_62 * V_63 ,
struct V_165 * V_166 )
{
struct V_13 * V_14 = (struct V_13 * ) V_63 -> V_64 -> V_65 ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_49 * V_49 = V_14 -> V_49 ;
struct V_32 * V_33 = V_63 -> V_65 ;
struct V_66 * V_67 = V_33 -> V_41 ;
struct V_167 * V_168 ;
struct V_24 * V_27 = NULL ;
struct V_31 * V_31 = NULL ;
int V_34 = 0 ;
T_4 V_136 ;
int V_28 = - 1 ;
T_1 V_25 = 0UL ;
struct V_26 * V_26 ;
struct V_133 * V_134 ;
int V_169 = - 1 ;
if ( F_85 ( & V_14 -> V_132 ) == 0 )
V_14 -> V_148 = V_170 ;
if ( V_166 -> V_171 > 4 ) {
F_10 ( V_16 , L_38 ,
V_22 , V_166 -> V_171 ) ;
V_34 = - V_118 ;
goto V_43;
}
if ( V_67 -> V_96 == 0 ) {
F_10 ( V_16 , L_39 ,
V_22 , V_33 -> V_106 [ V_63 -> V_172 ] ) ;
V_34 = F_26 ( V_63 , V_33 ) ;
if ( V_34 ) {
F_24 ( V_16 , L_40 ,
V_22 , V_34 ) ;
V_34 = - V_173 ;
goto V_43;
}
F_10 ( V_16 , L_41 , V_22 , V_67 -> V_96 ) ;
F_10 ( V_16 , L_42 , V_22 , V_67 -> V_97 ) ;
}
if ( V_166 -> V_5 . V_174 & V_175 ) {
V_25 = V_166 -> V_6 ;
V_27 = F_15 ( V_14 , V_25 , NULL , 0 ) ;
if ( ! V_27 ) {
F_10 ( V_16 , L_43 ,
V_22 , V_25 ) ;
V_34 = - V_118 ;
goto V_43;
}
F_14 (lun_access, &ctxi->luns, list)
if ( V_31 -> V_33 == V_33 ) {
F_10 ( V_16 , L_44 ,
V_22 ) ;
V_34 = - V_118 ;
goto V_43;
}
}
V_31 = F_27 ( sizeof( * V_31 ) , V_78 ) ;
if ( F_28 ( ! V_31 ) ) {
F_24 ( V_16 , L_45 , V_22 ) ;
V_34 = - V_81 ;
goto V_43;
}
V_31 -> V_33 = V_33 ;
V_31 -> V_63 = V_63 ;
if ( V_27 ) {
F_10 ( V_16 , L_46 ,
V_22 , V_25 ) ;
F_83 ( & V_31 -> V_143 , & V_27 -> V_129 ) ;
V_169 = V_27 -> V_142 ;
goto V_176;
}
V_134 = F_86 ( V_14 -> V_16 ) ;
if ( F_28 ( F_87 ( V_134 ) ) ) {
F_24 ( V_16 , L_47 ,
V_22 , V_134 ) ;
V_34 = - V_173 ;
goto V_177;
}
V_28 = F_69 ( V_134 ) ;
if ( F_28 ( ( V_28 > V_19 ) || ( V_28 < 0 ) ) ) {
F_24 ( V_16 , L_48 , V_22 , V_28 ) ;
V_34 = - V_178 ;
goto V_179;
}
V_26 = F_88 ( V_134 , & V_14 -> V_148 , & V_169 ) ;
if ( F_28 ( V_169 < 0 ) ) {
V_34 = - V_173 ;
F_24 ( V_16 , L_49 , V_22 ) ;
goto V_179;
}
V_136 = F_89 ( V_166 -> V_5 . V_174 + 1 ) ;
V_27 = F_55 ( V_14 , V_134 , V_28 , V_169 , V_26 , V_136 ) ;
if ( F_28 ( ! V_27 ) ) {
F_24 ( V_16 , L_50 ,
V_22 , V_28 ) ;
goto V_180;
}
V_168 = & V_27 -> V_168 ;
V_168 -> V_171 = V_166 -> V_171 ;
V_168 -> V_174 = V_181 ;
V_34 = F_90 ( V_134 , V_168 ) ;
if ( F_28 ( V_34 ) ) {
F_10 ( V_16 , L_51 ,
V_22 , V_34 ) ;
goto V_182;
}
V_34 = F_21 ( V_14 , V_27 ) ;
if ( F_28 ( V_34 ) ) {
F_24 ( V_16 , L_52 , V_22 , V_34 ) ;
goto V_183;
}
F_83 ( & V_31 -> V_143 , & V_27 -> V_129 ) ;
F_6 ( & V_27 -> V_11 ) ;
F_4 ( & V_14 -> V_42 ) ;
F_4 ( & V_27 -> V_11 ) ;
V_14 -> V_20 [ V_28 ] = V_27 ;
F_6 ( & V_14 -> V_42 ) ;
F_91 ( V_169 , V_26 ) ;
V_176:
V_166 -> V_5 . V_184 = 0 ;
V_166 -> V_6 = V_27 -> V_28 ;
V_166 -> V_185 = V_67 -> V_97 ;
V_166 -> V_186 = sizeof( V_49 -> V_130 -> V_187 [ 0 ] . V_188 ) ;
V_166 -> V_189 = V_67 -> V_96 ;
V_166 -> V_190 = ( V_63 -> V_64 -> V_191 * 512 ) / V_67 -> V_97 ;
V_43:
V_166 -> V_135 = V_169 ;
if ( V_27 )
F_20 ( V_27 ) ;
F_10 ( V_16 , L_53 ,
V_22 , V_28 , V_169 , V_166 -> V_185 , V_34 , V_166 -> V_189 ) ;
return V_34 ;
V_183:
F_92 ( V_134 ) ;
V_182:
F_20 ( V_27 ) ;
F_52 ( V_14 , V_27 ) ;
V_27 = NULL ;
V_180:
V_26 -> V_147 = & V_192 ;
F_93 ( V_26 ) ;
F_94 ( V_169 ) ;
V_169 = - 1 ;
V_179:
F_95 ( V_134 ) ;
V_177:
F_33 ( V_31 ) ;
goto V_43;
}
static int F_96 ( struct V_13 * V_14 , struct V_24 * V_27 )
{
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
int V_34 = 0 ;
int V_193 , V_169 = - 1 ;
int V_28 = - 1 ;
struct V_26 * V_26 ;
struct V_133 * V_134 ;
struct V_49 * V_49 = V_14 -> V_49 ;
V_134 = F_86 ( V_14 -> V_16 ) ;
if ( F_28 ( F_87 ( V_134 ) ) ) {
F_24 ( V_16 , L_47 ,
V_22 , V_134 ) ;
V_34 = - V_173 ;
goto V_43;
}
V_28 = F_69 ( V_134 ) ;
if ( F_28 ( ( V_28 > V_19 ) || ( V_28 < 0 ) ) ) {
F_24 ( V_16 , L_48 , V_22 , V_28 ) ;
V_34 = - V_178 ;
goto V_179;
}
V_26 = F_88 ( V_134 , & V_14 -> V_148 , & V_169 ) ;
if ( F_28 ( V_169 < 0 ) ) {
V_34 = - V_173 ;
F_24 ( V_16 , L_49 , V_22 ) ;
goto V_179;
}
V_34 = F_90 ( V_134 , & V_27 -> V_168 ) ;
if ( F_28 ( V_34 ) ) {
F_10 ( V_16 , L_51 ,
V_22 , V_34 ) ;
goto V_180;
}
V_27 -> V_51 = & V_49 -> V_130 -> V_140 [ V_28 ] . V_141 ;
V_34 = F_21 ( V_14 , V_27 ) ;
if ( V_34 ) {
F_24 ( V_16 , L_52 , V_22 , V_34 ) ;
goto V_182;
}
V_193 = V_27 -> V_142 ;
V_27 -> V_28 = F_57 ( V_27 , V_28 ) ;
V_27 -> V_142 = V_169 ;
V_27 -> V_134 = V_134 ;
V_27 -> V_26 = V_26 ;
F_6 ( & V_27 -> V_11 ) ;
F_4 ( & V_14 -> V_42 ) ;
F_4 ( & V_27 -> V_11 ) ;
F_97 ( & V_27 -> V_143 ) ;
V_14 -> V_20 [ V_28 ] = V_27 ;
F_6 ( & V_14 -> V_42 ) ;
F_91 ( V_169 , V_26 ) ;
F_64 ( V_193 ) ;
V_43:
F_10 ( V_16 , L_54 ,
V_22 , V_28 , V_169 , V_34 ) ;
return V_34 ;
V_182:
F_92 ( V_134 ) ;
V_180:
F_93 ( V_26 ) ;
F_94 ( V_169 ) ;
V_179:
F_95 ( V_134 ) ;
goto V_43;
}
static int F_98 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
int V_34 = 0 ;
V_76:
switch ( V_14 -> V_194 ) {
case V_195 :
F_10 ( V_16 , L_55 , V_22 ) ;
V_34 = F_99 ( V_14 -> V_23 ,
V_14 -> V_194 != V_195 ) ;
if ( F_28 ( V_34 ) )
break;
goto V_76;
case V_196 :
F_10 ( V_16 , L_56 , V_22 ) ;
V_34 = - V_173 ;
break;
default:
break;
}
return V_34 ;
}
static int F_100 ( struct V_62 * V_63 ,
struct V_197 * V_198 )
{
struct V_13 * V_14 = (struct V_13 * ) V_63 -> V_64 -> V_65 ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_32 * V_33 = V_63 -> V_65 ;
struct V_49 * V_49 = V_14 -> V_49 ;
struct V_24 * V_27 = NULL ;
struct V_11 * V_11 = & V_14 -> V_199 ;
T_1 V_28 = F_16 ( V_198 -> V_6 ) ,
V_25 = V_198 -> V_6 ;
long V_200 ;
int V_201 = 20 ;
int V_34 = 0 ;
F_60 ( & V_14 -> V_202 ) ;
V_34 = F_18 ( V_11 ) ;
if ( V_34 )
goto V_43;
F_10 ( V_16 , L_57 ,
V_22 , V_198 -> V_203 , V_25 ) ;
V_76:
V_27 = F_15 ( V_14 , V_25 , V_33 , V_45 ) ;
if ( F_28 ( ! V_27 ) ) {
F_10 ( V_16 , L_20 , V_22 , V_28 ) ;
V_34 = - V_118 ;
goto V_43;
}
if ( V_27 -> V_127 ) {
V_204:
V_34 = F_96 ( V_14 , V_27 ) ;
if ( F_28 ( V_34 ) ) {
F_24 ( V_16 , L_58 ,
V_22 , V_28 , V_34 ) ;
if ( ( V_34 == - V_173 ) &&
( ( F_85 ( & V_14 -> V_202 ) > 1 ) ||
( V_201 -- ) ) ) {
F_10 ( V_16 , L_59 ,
V_22 ) ;
F_6 ( V_11 ) ;
F_101 ( 100 ) ;
V_34 = F_18 ( V_11 ) ;
if ( V_34 )
goto V_43;
goto V_204;
}
goto V_43;
}
V_27 -> V_127 = false ;
V_198 -> V_6 = V_27 -> V_28 ;
V_198 -> V_135 = V_27 -> V_142 ;
V_198 -> V_186 = sizeof( V_49 -> V_130 -> V_187 [ 0 ] . V_188 ) ;
V_198 -> V_5 . V_184 |=
V_205 ;
goto V_43;
}
V_200 = F_22 ( & V_49 -> V_51 -> V_53 ) ;
if ( V_200 == - 1 ) {
F_10 ( V_16 , L_60 ,
V_22 ) ;
F_6 ( & V_27 -> V_11 ) ;
V_27 = NULL ;
F_12 ( 1 ) ;
V_34 = F_98 ( V_14 ) ;
if ( F_28 ( V_34 ) )
goto V_43;
goto V_76;
}
F_10 ( V_16 , L_61 , V_22 ) ;
V_43:
if ( F_17 ( V_27 ) )
F_20 ( V_27 ) ;
F_6 ( V_11 ) ;
F_54 ( & V_14 -> V_202 ) ;
return V_34 ;
}
static int F_102 ( struct V_62 * V_63 ,
struct V_206 * V_207 )
{
struct V_13 * V_14 = (struct V_13 * ) V_63 -> V_64 -> V_65 ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_32 * V_33 = V_63 -> V_65 ;
struct V_66 * V_67 = V_33 -> V_41 ;
T_1 V_208 = V_67 -> V_96 ;
struct V_87 V_88 = { 0 } ;
int V_34 = 0 ;
V_34 = F_32 ( ( const T_3 * ) & V_207 -> V_209 ,
V_210 , & V_88 ) ;
if ( ! V_34 ) {
F_24 ( V_16 , L_62 , V_22 ) ;
V_34 = - V_118 ;
goto V_43;
}
switch ( V_88 . V_89 ) {
case V_90 :
case V_91 :
case V_92 :
break;
case V_93 :
switch ( V_88 . V_94 ) {
case 0x29 :
case 0x2A :
V_34 = F_26 ( V_63 , V_33 ) ;
if ( V_34 ) {
V_34 = - V_173 ;
break;
}
if ( V_208 != V_67 -> V_96 )
F_10 ( V_16 , L_63
L_64 , V_22 , V_208 ,
V_67 -> V_96 ) ;
break;
case 0x3F :
F_103 ( V_14 -> V_64 ) ;
break;
default:
V_34 = - V_95 ;
break;
}
break;
default:
V_34 = - V_95 ;
break;
}
V_43:
F_10 ( V_16 , L_65 , V_22 ,
V_88 . V_89 , V_88 . V_94 , V_88 . V_211 , V_34 ) ;
return V_34 ;
}
static int F_104 ( struct V_62 * V_63 ,
struct V_206 * V_207 )
{
int V_34 = 0 ;
struct V_24 * V_27 = NULL ;
struct V_13 * V_14 = (struct V_13 * ) V_63 -> V_64 -> V_65 ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_32 * V_33 = V_63 -> V_65 ;
struct V_66 * V_67 = V_33 -> V_41 ;
struct V_98 * V_100 = NULL ;
T_5 V_99 = V_207 -> V_7 ;
T_1 V_28 = F_16 ( V_207 -> V_6 ) ,
V_25 = V_207 -> V_6 ;
T_1 V_189 = 0 ;
F_10 ( V_16 , L_66
L_67 , V_22 , V_28 , V_207 -> V_7 ,
V_207 -> V_212 , V_207 -> V_5 . V_174 ) ;
V_27 = F_15 ( V_14 , V_25 , V_33 , 0 ) ;
if ( F_28 ( ! V_27 ) ) {
F_10 ( V_16 , L_20 , V_22 , V_28 ) ;
V_34 = - V_118 ;
goto V_43;
}
V_100 = F_36 ( V_27 , V_99 , V_33 ) ;
if ( F_28 ( ! V_100 ) ) {
F_10 ( V_16 , L_12 ,
V_22 , V_99 ) ;
V_34 = - V_118 ;
goto V_43;
}
if ( V_207 -> V_212 & V_213 ) {
V_34 = F_102 ( V_63 , V_207 ) ;
if ( F_28 ( V_34 ) ) {
F_24 ( V_16 , L_68 ,
V_22 , V_34 ) ;
goto V_43;
}
}
switch ( V_67 -> V_115 ) {
case V_126 :
V_189 = V_67 -> V_96 ;
break;
case V_124 :
V_189 = ( ( T_1 ) V_100 -> V_214 * V_215 * V_67 -> V_97 ) ;
V_189 /= V_216 ;
V_189 -- ;
break;
default:
F_50 ( 1 , L_22 ) ;
}
V_207 -> V_189 = V_189 ;
V_43:
if ( F_17 ( V_27 ) )
F_20 ( V_27 ) ;
F_10 ( V_16 , L_69 ,
V_22 , V_34 , V_207 -> V_189 ) ;
return V_34 ;
}
static char * F_105 ( int V_217 )
{
switch ( V_217 ) {
case V_218 :
return F_106 ( V_218 ) ;
case V_219 :
return F_106 ( V_219 ) ;
case V_220 :
return F_106 ( V_220 ) ;
case V_221 :
return F_106 ( V_221 ) ;
case V_222 :
return F_106 ( V_222 ) ;
case V_223 :
return F_106 ( V_223 ) ;
case V_224 :
return F_106 ( V_224 ) ;
case V_225 :
return F_106 ( V_225 ) ;
case V_226 :
return F_106 ( V_226 ) ;
case V_227 :
return F_106 ( V_227 ) ;
}
return L_70 ;
}
static int F_107 ( struct V_62 * V_63 , void * V_29 )
{
struct V_13 * V_14 = (struct V_13 * ) V_63 -> V_64 -> V_65 ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_49 * V_49 = V_14 -> V_49 ;
struct V_32 * V_33 = V_63 -> V_65 ;
struct V_66 * V_67 = V_33 -> V_41 ;
struct V_228 * V_229 = (struct V_228 * ) V_29 ;
T_1 V_28 = F_16 ( V_229 -> V_6 ) ,
V_25 = V_229 -> V_6 ;
T_1 V_230 = 0 ;
T_1 V_189 = 0 ;
T_1 V_7 = - 1 ;
T_4 V_231 = F_108 ( V_63 -> V_172 ) ;
int V_34 = 0 ;
struct V_24 * V_27 = NULL ;
struct V_98 * V_100 = NULL ;
F_37 ( L_71 , V_22 , V_28 , V_230 ) ;
V_34 = F_43 ( V_67 , V_126 , false ) ;
if ( F_28 ( V_34 ) ) {
F_10 ( V_16 , L_72 ,
V_22 ) ;
goto V_43;
}
V_27 = F_15 ( V_14 , V_25 , V_33 , 0 ) ;
if ( F_28 ( ! V_27 ) ) {
F_10 ( V_16 , L_20 , V_22 , V_28 ) ;
V_34 = - V_118 ;
goto V_179;
}
V_100 = F_38 ( V_27 , V_33 ) ;
if ( F_28 ( ! V_100 ) ) {
F_10 ( V_16 , L_73 , V_22 ) ;
V_34 = - V_232 ;
goto V_179;
}
V_7 = ( V_100 - V_27 -> V_58 ) ;
F_40 ( V_100 , V_33 -> V_106 [ V_63 -> V_172 ] , V_27 -> V_139 , V_231 ) ;
F_49 ( V_49 , V_28 , V_7 , V_233 ) ;
V_189 = V_67 -> V_96 ;
V_229 -> V_5 . V_184 = 0 ;
V_229 -> V_189 = V_189 ;
V_229 -> V_7 = V_7 ;
V_43:
if ( F_17 ( V_27 ) )
F_20 ( V_27 ) ;
F_10 ( V_16 , L_74 ,
V_22 , V_7 , V_34 , V_189 ) ;
return V_34 ;
V_179:
F_45 ( V_67 ) ;
goto V_43;
}
static int F_109 ( struct V_62 * V_63 , int V_217 )
{
struct V_13 * V_14 = (struct V_13 * ) V_63 -> V_64 -> V_65 ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_32 * V_33 = V_63 -> V_65 ;
int V_34 = 0 ;
if ( F_28 ( ! V_33 ) ) {
F_10 ( V_16 , L_75 , V_22 ) ;
V_34 = - V_118 ;
goto V_43;
}
V_34 = F_98 ( V_14 ) ;
if ( F_28 ( V_34 ) && ( V_14 -> V_194 == V_196 ) ) {
switch ( V_217 ) {
case V_221 :
case V_222 :
case V_223 :
F_10 ( V_16 , L_76 ,
V_22 , V_34 ) ;
V_34 = 0 ;
break;
}
}
V_43:
return V_34 ;
}
int F_110 ( struct V_62 * V_63 , int V_217 , void T_6 * V_29 )
{
typedef int (* F_111) ( struct V_62 * , void * );
struct V_13 * V_14 = (struct V_13 * ) V_63 -> V_64 -> V_65 ;
struct V_15 * V_16 = & V_14 -> V_16 -> V_16 ;
struct V_49 * V_49 = V_14 -> V_49 ;
struct V_234 * V_5 ;
char V_235 [ sizeof( union V_236 ) ] ;
T_7 V_123 = 0 ;
bool V_237 = false ;
int V_238 ;
int V_34 = 0 ;
struct V_239 * V_240 = V_63 -> V_64 ;
F_111 V_241 = NULL ;
static const struct {
T_7 V_123 ;
F_111 V_242 ;
} V_243 [] = {
{ sizeof( struct V_165 ) , ( F_111 ) F_84 } ,
{ sizeof( struct V_228 ) , F_107 } ,
{ sizeof( struct V_1 ) , ( F_111 ) F_51 } ,
{ sizeof( struct V_8 ) , ( F_111 ) F_65 } ,
{ sizeof( struct V_206 ) , ( F_111 ) F_104 } ,
{ sizeof( struct V_197 ) , ( F_111 ) F_100 } ,
{ sizeof( struct V_244 ) , ( F_111 ) V_245 } ,
{ sizeof( struct V_246 ) , V_247 } ,
{ sizeof( struct V_3 ) , ( F_111 ) V_248 } ,
{ sizeof( struct V_249 ) , ( F_111 ) V_250 } ,
} ;
if ( V_49 -> V_251 )
switch ( V_217 ) {
case V_222 :
case V_220 :
case V_221 :
case V_225 :
F_10 ( V_16 , L_77 ,
V_22 , F_105 ( V_217 ) , V_49 -> V_251 ) ;
V_34 = - V_118 ;
goto V_252;
}
switch ( V_217 ) {
case V_218 :
case V_219 :
case V_222 :
case V_223 :
case V_224 :
case V_226 :
case V_220 :
case V_221 :
case V_225 :
F_10 ( V_16 , L_78 ,
V_22 , F_105 ( V_217 ) , V_217 , V_240 -> V_253 ,
V_63 -> V_172 , V_63 -> V_254 , V_63 -> V_255 ) ;
V_34 = F_109 ( V_63 , V_217 ) ;
if ( F_28 ( V_34 ) )
goto V_252;
case V_227 :
V_237 = true ;
V_238 = F_112 ( V_217 ) - F_112 ( V_218 ) ;
V_123 = V_243 [ V_238 ] . V_123 ;
V_241 = V_243 [ V_238 ] . V_242 ;
if ( F_17 ( V_241 ) )
break;
default:
V_34 = - V_118 ;
goto V_252;
}
if ( F_28 ( F_113 ( & V_235 , V_29 , V_123 ) ) ) {
F_24 ( V_16 , L_79
L_80 ,
V_22 , V_123 , V_217 , F_105 ( V_217 ) , V_29 ) ;
V_34 = - V_256 ;
goto V_252;
}
V_5 = (struct V_234 * ) & V_235 ;
if ( V_5 -> V_257 != V_258 ) {
F_10 ( V_16 , L_81 ,
V_22 , V_5 -> V_257 , F_105 ( V_217 ) ) ;
V_34 = - V_118 ;
goto V_252;
}
if ( V_5 -> V_259 [ 0 ] || V_5 -> V_259 [ 1 ] || V_5 -> V_259 [ 2 ] || V_5 -> V_184 ) {
F_10 ( V_16 , L_82 , V_22 ) ;
V_34 = - V_118 ;
goto V_252;
}
V_34 = V_241 ( V_63 , ( void * ) & V_235 ) ;
if ( F_17 ( ! V_34 ) )
if ( F_28 ( F_114 ( V_29 , & V_235 , V_123 ) ) ) {
F_24 ( V_16 , L_83
L_80 ,
V_22 , V_123 , V_217 , F_105 ( V_217 ) , V_29 ) ;
V_34 = - V_256 ;
}
V_252:
if ( F_28 ( V_34 && V_237 ) )
F_24 ( V_16 , L_84
L_85 , V_22 ,
F_105 ( V_217 ) , V_217 , V_240 -> V_253 ,
V_63 -> V_172 , V_63 -> V_254 , V_63 -> V_255 , V_34 ) ;
else
F_10 ( V_16 , L_84
L_85 , V_22 , F_105 ( V_217 ) ,
V_217 , V_240 -> V_253 , V_63 -> V_172 , V_63 -> V_254 ,
V_63 -> V_255 , V_34 ) ;
return V_34 ;
}
