static void
F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = (struct V_4 * ) V_3 ;
F_2 ( L_1 , V_2 -> V_5 ) ;
switch ( V_2 -> V_5 ) {
case V_6 :
F_3 ( V_4 -> V_7 , V_6 ) ;
break;
case V_8 :
F_4 ( L_2 ) ;
break;
default:
break;
}
}
static int
F_5 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
int V_13 ;
V_13 = F_6 ( V_10 , V_12 ) ;
if ( V_13 ) {
F_2 ( L_3 , V_13 ) ;
return V_13 ;
}
F_7 ( L_4 , V_12 -> V_14 ) ;
F_7 ( L_5 , V_12 -> V_15 ) ;
return 0 ;
}
static int
F_8 ( struct V_4 * V_4 , struct V_16 * V_17 )
{
struct V_18 * V_19 = V_4 -> V_20 ;
struct V_21 V_22 ;
struct V_11 V_12 ;
int V_13 , V_23 , V_24 = 0 ;
memset ( & V_12 , 0 , sizeof( struct V_11 ) ) ;
V_13 = F_5 ( V_17 -> V_19 , & V_12 ) ;
if ( V_13 )
return V_13 ;
F_9 ( & V_25 ) ;
for ( V_23 = 0 ; V_23 < V_19 -> V_26 ; V_23 ++ )
if ( V_19 -> V_27 [ V_23 ] <
V_19 -> V_27 [ V_24 ] )
V_24 = V_23 ;
V_19 -> V_27 [ V_24 ] ++ ;
F_7 ( L_6 , V_24 ) ;
F_10 ( & V_25 ) ;
memset ( & V_22 , 0 , sizeof( struct V_21 ) ) ;
V_22 . V_28 = F_1 ;
V_22 . V_29 = V_4 ;
V_22 . V_30 = V_19 -> V_31 [ V_24 ] ;
V_22 . V_32 = V_19 -> V_33 [ V_24 ] ;
V_22 . V_34 . V_35 = V_36 ;
V_22 . V_34 . V_37 = V_38 ;
V_22 . V_34 . V_39 = V_12 . V_14 - 2 ;
V_4 -> V_14 = V_22 . V_34 . V_39 ;
V_22 . V_34 . V_40 = 1 ;
V_22 . V_41 = V_42 ;
V_22 . V_43 = V_44 ;
F_7 ( L_7 ,
V_17 -> V_19 ) ;
F_7 ( L_8 ,
V_4 -> V_45 -> V_19 ) ;
V_13 = F_11 ( V_17 , V_4 -> V_45 , & V_22 ) ;
if ( V_13 ) {
F_2 ( L_9 , V_13 ) ;
return V_13 ;
}
V_4 -> V_46 = V_17 -> V_47 ;
F_7 ( L_10 ) ;
return 0 ;
}
static void
F_12 ( struct V_1 * V_2 , void * V_3 )
{
F_7 ( L_11 , V_2 -> V_5 ) ;
}
static int
F_13 ( struct V_4 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
T_1 V_52 ;
int V_53 , V_54 ;
V_4 -> V_55 = F_14 ( V_38 *
sizeof( struct V_48 ) , V_56 ) ;
if ( ! V_4 -> V_55 )
goto V_57;
V_49 = V_4 -> V_55 ;
for ( V_53 = 0 ; V_53 < V_38 ; V_53 ++ , V_49 ++ ) {
V_52 = F_15 ( V_10 , ( void * ) V_49 ,
V_58 , V_59 ) ;
if ( F_16 ( V_10 , V_52 ) )
goto V_60;
V_49 -> V_52 = V_52 ;
V_51 = & V_49 -> V_51 ;
V_51 -> V_61 = V_49 -> V_52 ;
V_51 -> V_62 = V_58 ;
V_51 -> V_63 = V_4 -> V_64 -> V_63 ;
}
V_4 -> V_65 = 0 ;
return 0 ;
V_60:
V_49 = V_4 -> V_55 ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ , V_49 ++ ) {
F_17 ( V_10 , V_49 -> V_52 ,
V_58 , V_59 ) ;
}
F_18 ( V_4 -> V_55 ) ;
V_4 -> V_55 = NULL ;
V_57:
return - V_66 ;
}
static void
F_19 ( struct V_4 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_48 * V_49 ;
int V_53 ;
if ( ! V_4 -> V_55 )
return;
V_49 = V_4 -> V_55 ;
for ( V_53 = 0 ; V_53 < V_38 ; V_53 ++ , V_49 ++ ) {
F_17 ( V_10 , V_49 -> V_52 ,
V_58 , V_59 ) ;
}
F_18 ( V_4 -> V_55 ) ;
V_4 -> V_55 = NULL ;
}
static int
F_20 ( struct V_18 * V_19 )
{
struct V_9 * V_10 = V_19 -> V_9 ;
struct V_67 * V_68 ;
int V_13 = 0 , V_53 , V_54 ;
V_19 -> V_26 = F_21 ( int , F_22 () ,
V_19 -> V_9 -> V_69 ) ;
V_19 -> V_26 = F_23 ( V_70 , V_19 -> V_26 ) ;
F_7 ( L_12 ,
V_19 -> V_26 , V_19 -> V_9 -> V_71 ,
V_19 -> V_9 -> V_69 ) ;
V_19 -> V_68 = F_14 ( sizeof( struct V_67 ) *
V_19 -> V_26 , V_56 ) ;
if ( ! V_19 -> V_68 ) {
F_2 ( L_13 ) ;
return - V_66 ;
}
V_68 = V_19 -> V_68 ;
V_19 -> V_72 = F_24 ( V_10 ) ;
if ( F_25 ( V_19 -> V_72 ) ) {
V_13 = F_26 ( V_19 -> V_72 ) ;
F_2 ( L_14 , V_13 ) ;
goto V_73;
}
for ( V_53 = 0 ; V_53 < V_19 -> V_26 ; V_53 ++ ) {
V_68 [ V_53 ] . V_19 = V_19 ;
V_68 [ V_53 ] . V_74 = V_53 ;
V_19 -> V_33 [ V_53 ] = F_27 ( V_19 -> V_9 ,
V_75 ,
F_12 ,
( void * ) & V_68 [ V_53 ] ,
V_76 , V_53 ) ;
if ( F_25 ( V_19 -> V_33 [ V_53 ] ) )
goto V_77;
V_19 -> V_31 [ V_53 ] = F_27 ( V_19 -> V_9 ,
V_78 ,
F_12 ,
( void * ) & V_68 [ V_53 ] ,
V_79 , V_53 ) ;
if ( F_25 ( V_19 -> V_31 [ V_53 ] ) )
goto V_77;
if ( F_28 ( V_19 -> V_33 [ V_53 ] , V_80 ) )
goto V_77;
if ( F_28 ( V_19 -> V_31 [ V_53 ] , V_80 ) )
goto V_77;
}
V_19 -> V_81 = F_29 ( V_19 -> V_72 , V_82 ) ;
if ( F_25 ( V_19 -> V_81 ) ) {
V_13 = F_26 ( V_19 -> V_81 ) ;
F_2 ( L_15 , V_13 ) ;
goto V_77;
}
return 0 ;
V_77:
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ ) {
V_68 = & V_19 -> V_68 [ V_54 ] ;
if ( V_19 -> V_33 [ V_54 ] ) {
F_30 ( & V_68 -> V_83 ) ;
F_31 ( V_19 -> V_33 [ V_54 ] ) ;
}
if ( V_19 -> V_31 [ V_54 ] ) {
F_30 ( & V_68 -> V_84 ) ;
F_31 ( V_19 -> V_31 [ V_54 ] ) ;
}
}
F_32 ( V_19 -> V_72 ) ;
V_73:
F_18 ( V_19 -> V_68 ) ;
return V_13 ;
}
static void
F_33 ( struct V_18 * V_19 )
{
struct V_67 * V_68 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_19 -> V_26 ; V_53 ++ ) {
V_68 = & V_19 -> V_68 [ V_53 ] ;
F_30 ( & V_68 -> V_83 ) ;
F_30 ( & V_68 -> V_84 ) ;
F_31 ( V_19 -> V_33 [ V_53 ] ) ;
F_31 ( V_19 -> V_31 [ V_53 ] ) ;
V_19 -> V_33 [ V_53 ] = NULL ;
V_19 -> V_31 [ V_53 ] = NULL ;
}
F_34 ( V_19 -> V_81 ) ;
F_32 ( V_19 -> V_72 ) ;
F_18 ( V_19 -> V_68 ) ;
}
static void
F_35 ( struct V_18 * V_19 )
{
F_9 ( & V_25 ) ;
V_19 -> V_85 -- ;
if ( ! V_19 -> V_85 ) {
F_33 ( V_19 ) ;
F_36 ( & V_19 -> V_86 ) ;
F_18 ( V_19 ) ;
}
F_10 ( & V_25 ) ;
}
static struct V_18 *
F_37 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
int V_13 ;
F_9 ( & V_25 ) ;
F_38 (device, &device_list, dev_node) {
if ( V_19 -> V_9 -> V_87 == V_17 -> V_19 -> V_87 ) {
V_19 -> V_85 ++ ;
F_10 ( & V_25 ) ;
return V_19 ;
}
}
V_19 = F_14 ( sizeof( struct V_18 ) , V_56 ) ;
if ( ! V_19 ) {
F_10 ( & V_25 ) ;
return F_39 ( - V_66 ) ;
}
F_40 ( & V_19 -> V_86 ) ;
V_19 -> V_9 = V_17 -> V_19 ;
V_13 = F_20 ( V_19 ) ;
if ( V_13 ) {
F_18 ( V_19 ) ;
F_10 ( & V_25 ) ;
return F_39 ( V_13 ) ;
}
V_19 -> V_85 ++ ;
F_41 ( & V_19 -> V_86 , & V_88 ) ;
F_10 ( & V_25 ) ;
return V_19 ;
}
static int
F_42 ( struct V_16 * V_17 , struct V_89 * V_5 )
{
struct V_90 * V_91 = V_17 -> V_3 ;
struct V_92 * V_92 = V_91 -> V_93 ;
struct V_4 * V_4 ;
struct V_18 * V_19 ;
struct V_9 * V_10 = V_17 -> V_19 ;
int V_13 = 0 ;
F_7 ( L_16 ,
V_17 , V_17 -> V_3 ) ;
V_4 = F_14 ( sizeof( struct V_4 ) , V_56 ) ;
if ( ! V_4 ) {
F_2 ( L_17 ) ;
return - V_66 ;
}
V_4 -> V_94 = V_95 ;
F_40 ( & V_4 -> V_96 ) ;
F_43 ( & V_4 -> V_97 ) ;
F_44 ( & V_4 -> V_98 ) ;
F_44 ( & V_4 -> V_99 ) ;
F_45 ( & V_4 -> V_100 ) ;
F_46 ( & V_4 -> V_100 ) ;
V_17 -> V_3 = V_4 ;
V_4 -> V_7 = V_17 ;
V_4 -> V_101 = V_5 -> V_102 . V_103 . V_101 ;
V_4 -> V_104 = V_5 -> V_102 . V_103 . V_104 ;
F_7 ( L_18 ,
V_4 -> V_101 , V_4 -> V_104 ) ;
V_4 -> V_105 = F_14 ( V_106 +
V_107 , V_56 ) ;
if ( ! V_4 -> V_105 ) {
F_2 ( L_19 ) ;
V_13 = - V_66 ;
goto V_108;
}
V_4 -> V_109 = V_4 -> V_105 ;
V_4 -> V_110 = V_4 -> V_105 +
V_106 ;
F_7 ( L_20 ,
V_4 -> V_105 , V_4 -> V_109 ,
V_4 -> V_110 ) ;
V_4 -> V_111 = F_15 ( V_10 ,
( void * ) V_4 -> V_109 ,
V_106 , V_59 ) ;
V_13 = F_16 ( V_10 , V_4 -> V_111 ) ;
if ( V_13 ) {
F_2 ( L_21 ,
V_13 ) ;
V_4 -> V_111 = 0 ;
goto V_112;
}
V_4 -> V_113 = F_15 ( V_10 ,
( void * ) V_4 -> V_110 ,
V_107 , V_114 ) ;
V_13 = F_16 ( V_10 , V_4 -> V_113 ) ;
if ( V_13 ) {
F_2 ( L_22 ,
V_13 ) ;
V_4 -> V_113 = 0 ;
goto V_115;
}
V_19 = F_37 ( V_17 ) ;
if ( F_25 ( V_19 ) ) {
V_13 = F_26 ( V_19 ) ;
goto V_116;
}
V_4 -> V_20 = V_19 ;
V_4 -> V_45 = V_19 -> V_72 ;
V_4 -> V_64 = V_19 -> V_81 ;
V_13 = F_8 ( V_4 , V_17 ) ;
if ( V_13 )
goto V_117;
F_9 ( & V_92 -> V_118 ) ;
F_41 ( & V_92 -> V_119 , & V_4 -> V_96 ) ;
F_10 ( & V_92 -> V_118 ) ;
F_7 ( L_23 , V_91 ) ;
F_47 ( & V_92 -> V_120 ) ;
return 0 ;
V_117:
F_35 ( V_19 ) ;
V_116:
F_17 ( V_10 , V_4 -> V_113 ,
V_107 , V_114 ) ;
V_115:
F_17 ( V_10 , V_4 -> V_111 ,
V_106 , V_59 ) ;
V_112:
F_18 ( V_4 -> V_105 ) ;
V_108:
F_18 ( V_4 ) ;
return V_13 ;
}
static void
F_48 ( struct V_4 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_18 * V_19 = V_4 -> V_20 ;
int V_74 ;
F_7 ( L_24 ) ;
if ( V_4 -> V_46 ) {
V_74 = ( (struct V_67 * )
V_4 -> V_46 -> V_32 -> V_121 ) -> V_74 ;
F_7 ( L_25 , V_74 ) ;
V_4 -> V_20 -> V_27 [ V_74 ] -- ;
F_49 ( V_4 -> V_7 ) ;
}
F_19 ( V_4 ) ;
F_50 ( V_4 -> V_7 ) ;
if ( V_4 -> V_105 ) {
F_17 ( V_10 , V_4 -> V_113 ,
V_107 , V_114 ) ;
F_17 ( V_10 , V_4 -> V_111 ,
V_106 ,
V_59 ) ;
F_18 ( V_4 -> V_105 ) ;
}
F_18 ( V_4 ) ;
if ( V_19 )
F_35 ( V_19 ) ;
F_7 ( L_26 ) ;
}
static void
F_51 ( struct V_16 * V_17 )
{
return;
}
static void
F_52 ( struct V_122 * V_122 )
{
struct V_4 * V_4 = F_53 ( V_122 ,
struct V_4 , V_100 ) ;
F_7 ( L_27 ,
V_123 -> V_124 , V_123 -> V_125 ) ;
F_48 ( V_4 ) ;
}
static void
F_54 ( struct V_4 * V_4 )
{
F_55 ( & V_4 -> V_100 , F_52 ) ;
}
static void
F_56 ( struct V_126 * V_127 )
{
struct V_4 * V_4 = F_53 ( V_127 ,
struct V_4 , V_128 ) ;
F_7 ( L_28 ) ;
V_4 -> V_94 = V_129 ;
if ( V_4 -> V_130 == 0 &&
F_57 ( & V_4 -> V_131 ) == 0 ) {
F_7 ( L_29 ) ;
F_47 ( & V_4 -> V_98 ) ;
}
F_54 ( V_4 ) ;
}
static void
F_58 ( struct V_16 * V_17 )
{
struct V_4 * V_4 = (struct V_4 * ) V_17 -> V_3 ;
F_59 ( & V_4 -> V_128 , F_56 ) ;
F_60 ( & V_4 -> V_128 ) ;
}
static int
F_61 ( struct V_16 * V_17 , struct V_89 * V_5 )
{
int V_13 = 0 ;
F_7 ( L_30 ,
V_5 -> V_5 , V_5 -> V_132 , V_17 -> V_3 , V_17 ) ;
switch ( V_5 -> V_5 ) {
case V_133 :
F_7 ( L_31 ) ;
V_13 = F_42 ( V_17 , V_5 ) ;
break;
case V_134 :
F_7 ( L_32 ) ;
F_51 ( V_17 ) ;
break;
case V_135 :
F_7 ( L_33 ) ;
F_58 ( V_17 ) ;
break;
case V_136 :
case V_137 :
break;
case V_138 :
default:
F_2 ( L_34 , V_5 -> V_5 ) ;
break;
}
if ( V_13 != 0 ) {
F_2 ( L_35 ,
V_5 -> V_5 , V_13 ) ;
F_62 () ;
}
return V_13 ;
}
static int
F_63 ( struct V_4 * V_4 , T_2 V_139 )
{
struct V_140 * V_141 , * V_142 ;
int V_53 , V_13 ;
unsigned int V_143 = V_4 -> V_65 ;
struct V_48 * V_49 ;
for ( V_141 = V_4 -> V_144 , V_53 = 0 ; V_53 < V_139 ; V_53 ++ , V_141 ++ ) {
V_49 = & V_4 -> V_55 [ V_143 ] ;
V_141 -> V_145 = ( unsigned long ) V_49 ;
V_141 -> V_146 = & V_49 -> V_51 ;
V_141 -> V_147 = 1 ;
V_141 -> V_148 = V_141 + 1 ;
V_143 = ( V_143 + 1 ) & ( V_38 - 1 ) ;
}
V_141 -- ;
V_141 -> V_148 = NULL ;
V_4 -> V_130 += V_139 ;
V_13 = F_64 ( V_4 -> V_46 , V_4 -> V_144 ,
& V_142 ) ;
if ( V_13 ) {
F_2 ( L_36 , V_13 ) ;
V_4 -> V_130 -= V_139 ;
} else {
F_7 ( L_37 , V_139 ) ;
V_4 -> V_65 = V_143 ;
}
return V_13 ;
}
static int
F_65 ( struct V_4 * V_4 , struct V_149 * V_150 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_151 V_152 , * V_153 ;
int V_13 ;
F_66 ( V_10 , V_150 -> V_52 ,
V_154 , V_114 ) ;
V_152 . V_148 = NULL ;
V_152 . V_145 = ( unsigned long ) V_150 ;
V_152 . V_146 = V_150 -> V_155 ;
V_152 . V_147 = V_150 -> V_147 ;
V_152 . V_156 = V_157 ;
V_152 . V_158 = V_159 ;
F_67 ( & V_4 -> V_131 ) ;
V_13 = F_68 ( V_4 -> V_46 , & V_152 , & V_153 ) ;
if ( V_13 ) {
F_2 ( L_38 , V_13 ) ;
F_69 ( & V_4 -> V_131 ) ;
}
return V_13 ;
}
static void
F_70 ( struct V_4 * V_4 ,
struct V_160 * V_160 ,
struct V_149 * V_150 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
F_71 ( V_10 , V_150 -> V_52 ,
V_154 , V_114 ) ;
memset ( & V_150 -> V_161 , 0 , sizeof( struct V_162 ) ) ;
V_150 -> V_161 . V_163 = V_164 ;
V_150 -> V_147 = 1 ;
V_150 -> V_160 = V_160 ;
if ( V_150 -> V_155 [ 0 ] . V_63 != V_4 -> V_64 -> V_63 ) {
V_150 -> V_155 [ 0 ] . V_63 = V_4 -> V_64 -> V_63 ;
F_7 ( L_39 , V_150 ) ;
}
}
static int
F_72 ( struct V_4 * V_4 ,
struct V_149 * V_150 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
T_1 V_52 ;
V_52 = F_15 ( V_10 , ( void * ) V_150 ,
V_154 , V_114 ) ;
if ( F_16 ( V_10 , V_52 ) ) {
F_2 ( L_40 ) ;
return - V_66 ;
}
V_150 -> V_52 = V_52 ;
V_150 -> V_155 [ 0 ] . V_61 = V_150 -> V_52 ;
V_150 -> V_155 [ 0 ] . V_62 = V_154 ;
V_150 -> V_155 [ 0 ] . V_63 = V_4 -> V_64 -> V_63 ;
F_7 ( L_41
L_42 , V_150 -> V_155 [ 0 ] . V_61 ,
V_150 -> V_155 [ 0 ] . V_62 , V_150 -> V_155 [ 0 ] . V_63 ) ;
return 0 ;
}
static void
F_73 ( struct V_160 * V_160 , struct V_151 * V_152 )
{
V_160 -> V_165 . V_166 = V_167 ;
V_152 -> V_145 = ( unsigned long ) & V_160 -> V_150 ;
V_152 -> V_156 = V_157 ;
V_152 -> V_158 = V_159 ;
V_152 -> V_146 = & V_160 -> V_150 . V_155 [ 0 ] ;
V_152 -> V_147 = V_160 -> V_150 . V_147 ;
}
static int
F_74 ( struct V_4 * V_4 )
{
struct V_140 V_141 , * V_168 ;
struct V_50 V_169 ;
int V_13 ;
memset ( & V_169 , 0 , sizeof( struct V_50 ) ) ;
V_169 . V_61 = V_4 -> V_111 ;
V_169 . V_62 = V_107 ;
V_169 . V_63 = V_4 -> V_64 -> V_63 ;
F_7 ( L_43 ,
V_169 . V_61 , V_169 . V_62 , V_169 . V_63 ) ;
memset ( & V_141 , 0 , sizeof( struct V_140 ) ) ;
V_141 . V_145 = ( unsigned long ) V_4 -> V_109 ;
V_141 . V_146 = & V_169 ;
V_141 . V_147 = 1 ;
V_4 -> V_130 ++ ;
V_13 = F_64 ( V_4 -> V_46 , & V_141 , & V_168 ) ;
if ( V_13 ) {
F_2 ( L_44 , V_13 ) ;
V_4 -> V_130 -- ;
}
F_7 ( L_45 ) ;
return V_13 ;
}
static int
F_75 ( struct V_170 * V_103 , struct V_171 * V_172 ,
T_2 V_62 )
{
struct V_4 * V_4 = V_103 -> V_3 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_149 * V_150 = & V_4 -> V_173 ;
int V_13 ;
F_70 ( V_4 , NULL , V_150 ) ;
memcpy ( & V_150 -> V_174 , & V_172 -> V_175 [ 0 ] ,
sizeof( struct V_176 ) ) ;
F_72 ( V_4 , V_150 ) ;
if ( V_62 > 0 ) {
struct V_50 * V_177 = & V_150 -> V_155 [ 1 ] ;
F_71 ( V_10 , V_4 -> V_113 ,
V_62 , V_114 ) ;
memcpy ( V_4 -> V_110 , V_172 -> V_178 , V_62 ) ;
F_66 ( V_10 , V_4 -> V_113 ,
V_62 , V_114 ) ;
V_177 -> V_61 = V_4 -> V_113 ;
V_177 -> V_62 = V_62 ;
V_177 -> V_63 = V_4 -> V_64 -> V_63 ;
V_150 -> V_147 = 2 ;
}
if ( ! V_172 -> V_179 ) {
if ( V_172 -> V_180 ) {
V_13 = F_13 ( V_4 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_63 ( V_4 , V_181 ) ;
if ( V_13 )
return V_13 ;
V_4 -> V_94 = V_182 ;
goto V_183;
}
V_13 = F_74 ( V_4 ) ;
if ( V_13 )
return V_13 ;
}
V_183:
V_13 = F_65 ( V_4 , V_150 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static void
F_76 ( struct V_48 * V_49 , int V_184 ,
struct V_4 * V_4 )
{
struct V_170 * V_103 = V_4 -> V_103 ;
struct V_171 * V_172 = V_103 -> V_185 ;
int V_186 ;
if ( ! V_172 ) {
F_2 ( L_46 ) ;
F_62 () ;
return;
}
if ( V_172 -> V_187 ) {
struct V_188 * V_189 =
(struct V_188 * ) & V_49 -> V_174 ;
V_172 -> V_190 = ( ! V_189 -> V_191 ) ? 1 : 0 ;
V_172 -> V_192 =
( V_189 -> V_163 & V_193 )
>> 2 ;
V_172 -> V_194 = V_189 -> V_195 ;
V_172 -> V_196 = V_189 -> V_197 ;
memcpy ( V_172 -> V_198 , V_189 -> V_198 , 6 ) ;
V_172 -> V_199 = F_77 ( V_189 -> V_200 ) ;
V_172 -> V_201 = V_189 -> V_202 ;
V_172 -> V_203 = F_77 ( V_189 -> V_204 ) ;
V_172 -> V_205 = F_78 ( V_189 -> V_205 ) ;
V_172 -> V_191 = F_78 ( V_189 -> V_191 ) ;
}
memcpy ( & V_172 -> V_206 [ 0 ] , ( void * ) & V_49 -> V_174 , V_207 ) ;
V_186 = F_23 ( V_184 , V_208 ) ;
F_7 ( L_47 ,
V_186 , V_184 , V_208 ) ;
memcpy ( V_172 -> V_209 , & V_49 -> V_210 [ 0 ] , V_186 ) ;
F_79 ( & V_4 -> V_97 ) ;
}
static void
F_80 ( struct V_211 * V_212 )
{
struct V_160 * V_160 = F_53 ( V_212 , struct V_160 ,
V_211 ) ;
F_7 ( L_48 , V_160 ) ;
F_18 ( V_212 -> V_213 ) ;
F_18 ( V_212 -> V_214 ) ;
F_81 ( V_215 , V_160 ) ;
}
static struct V_211
* F_82 ( struct V_170 * V_103 , T_3 V_216 )
{
struct V_4 * V_4 = (struct V_4 * ) V_103 -> V_3 ;
struct V_160 * V_160 ;
V_160 = F_83 ( V_215 , V_216 ) ;
if ( ! V_160 ) {
F_2 ( L_49 ) ;
return NULL ;
}
V_160 -> V_103 = V_4 ;
V_160 -> V_211 . V_217 = & F_80 ;
return & V_160 -> V_211 ;
}
static int
F_84 ( struct V_4 * V_4 ,
struct V_160 * V_160 , struct V_48 * V_49 ,
unsigned char * V_218 )
{
struct V_211 * V_212 = & V_160 -> V_211 ;
struct V_170 * V_103 = V_4 -> V_103 ;
struct V_219 * V_220 = (struct V_219 * ) V_218 ;
struct V_221 * V_222 ;
int V_223 , V_224 , V_225 , V_226 , V_227 ;
bool V_228 = false ;
V_227 = F_85 ( V_103 , V_212 , V_218 ) ;
if ( V_227 < 0 )
return V_227 ;
V_223 = V_212 -> V_229 ;
V_224 = V_212 -> V_230 ;
V_225 = V_212 -> V_231 ;
V_227 = F_86 ( V_103 , V_212 , V_220 ) ;
if ( V_227 < 0 ) {
return 0 ;
} else if ( V_227 > 0 ) {
V_228 = true ;
goto V_232;
}
if ( ! V_223 )
return 0 ;
V_222 = & V_212 -> V_233 . V_234 [ 0 ] ;
V_226 = F_87 ( 1UL , F_88 ( V_224 , V_235 ) ) ;
F_7 ( L_50 ,
V_222 , V_226 , & V_49 -> V_210 [ 0 ] , V_224 ) ;
F_89 ( V_222 , V_226 , & V_49 -> V_210 [ 0 ] , V_224 ) ;
V_212 -> V_236 += V_224 ;
if ( V_212 -> V_236 == V_212 -> V_233 . V_237 ) {
F_90 ( & V_212 -> V_238 ) ;
V_212 -> V_239 |= V_240 ;
V_212 -> V_241 = V_242 ;
F_91 ( & V_212 -> V_238 ) ;
}
V_232:
V_227 = F_92 ( V_103 , V_212 , V_220 -> V_200 ) ;
if ( ! V_227 && V_228 == false && V_225 )
F_93 ( V_212 ) ;
if ( V_227 == V_243 )
return F_94 (
V_244 ,
1 , 0 , ( unsigned char * ) V_220 , V_212 ) ;
return 0 ;
}
static int
F_95 ( struct V_4 * V_4 ,
struct V_48 * V_49 , unsigned char * V_218 )
{
struct V_221 * V_245 ;
struct V_170 * V_103 = V_4 -> V_103 ;
struct V_211 * V_212 = NULL ;
struct V_246 * V_220 = (struct V_246 * ) V_218 ;
T_2 V_247 = F_96 ( V_220 -> V_248 ) ;
int V_227 , V_226 , V_249 , V_250 ;
V_227 = F_97 ( V_103 , V_218 , & V_212 ) ;
if ( V_227 < 0 )
return V_227 ;
else if ( ! V_212 )
return 0 ;
if ( ! V_212 -> V_231 ) {
F_2 ( L_51 ) ;
F_62 () ;
return - 1 ;
}
F_7 ( L_52 ,
V_247 , V_212 -> V_236 , V_212 -> V_233 . V_237 ) ;
V_249 = V_212 -> V_236 / V_235 ;
V_245 = & V_212 -> V_233 . V_234 [ V_249 ] ;
V_226 = F_87 ( 1UL , F_88 ( V_247 , V_235 ) ) ;
V_250 = V_212 -> V_236 % V_235 ;
if ( V_250 ) {
F_2 ( L_53 ) ;
F_62 () ;
return - 1 ;
}
F_7 ( L_54 ,
V_245 , V_249 , V_226 , & V_49 -> V_210 [ 0 ] , V_247 ) ;
F_89 ( V_245 , V_226 , & V_49 -> V_210 [ 0 ] ,
V_247 ) ;
V_227 = F_98 ( V_212 , V_220 , false ) ;
if ( V_227 < 0 )
return V_227 ;
return 0 ;
}
static int
F_99 ( struct V_4 * V_4 , struct V_48 * V_49 ,
T_4 V_251 , T_5 V_252 ,
T_4 V_253 , T_5 V_254 )
{
struct V_176 * V_220 = & V_49 -> V_174 ;
struct V_170 * V_103 = V_4 -> V_103 ;
struct V_211 * V_212 ;
struct V_160 * V_160 ;
int V_13 = - V_255 ;
T_6 V_156 = ( V_220 -> V_156 & V_256 ) ;
switch ( V_156 ) {
case V_257 :
V_212 = F_100 ( V_103 , V_56 ) ;
if ( ! V_212 )
break;
V_160 = F_53 ( V_212 , struct V_160 , V_211 ) ;
V_160 -> V_251 = V_251 ;
V_160 -> V_252 = V_252 ;
V_160 -> V_253 = V_253 ;
V_160 -> V_254 = V_254 ;
V_13 = F_84 ( V_4 , V_160 ,
V_49 , ( unsigned char * ) V_220 ) ;
break;
case V_258 :
V_212 = F_100 ( V_103 , V_56 ) ;
if ( ! V_212 )
break;
V_13 = F_101 ( V_103 , V_212 , ( unsigned char * ) V_220 ) ;
break;
case V_259 :
V_13 = F_95 ( V_4 , V_49 ,
( unsigned char * ) V_220 ) ;
break;
case V_260 :
V_212 = F_100 ( V_103 , V_56 ) ;
if ( ! V_212 )
break;
V_13 = F_102 ( V_103 , V_212 ,
( unsigned char * ) V_220 ) ;
break;
case V_261 :
V_212 = F_100 ( V_103 , V_56 ) ;
if ( ! V_212 )
break;
V_13 = F_103 ( V_103 , V_212 , ( unsigned char * ) V_220 ) ;
if ( V_13 > 0 )
F_104 ( & V_103 -> V_262 ,
V_263 *
V_264 ) ;
break;
default:
F_2 ( L_55 , V_156 ) ;
F_62 () ;
break;
}
return V_13 ;
}
static void
F_105 ( struct V_48 * V_49 , struct V_4 * V_4 )
{
struct V_162 * V_162 = & V_49 -> V_161 ;
T_5 V_252 = 0 , V_254 = 0 ;
T_4 V_251 = 0 , V_253 = 0 ;
int V_227 ;
switch ( V_162 -> V_163 & 0xF0 ) {
case V_265 :
if ( V_162 -> V_163 & V_266 ) {
V_251 = F_77 ( V_162 -> V_251 ) ;
V_252 = F_106 ( V_162 -> V_252 ) ;
F_7 ( L_56 ,
V_251 , ( unsigned long long ) V_252 ) ;
}
if ( V_162 -> V_163 & V_267 ) {
V_253 = F_77 ( V_162 -> V_253 ) ;
V_254 = F_106 ( V_162 -> V_254 ) ;
F_7 ( L_57 ,
V_253 , ( unsigned long long ) V_254 ) ;
}
F_7 ( L_58 ) ;
break;
case V_268 :
F_2 ( L_59 ) ;
break;
default:
F_4 ( L_60 , V_162 -> V_163 ) ;
break;
}
V_227 = F_99 ( V_4 , V_49 ,
V_251 , V_252 , V_253 , V_254 ) ;
}
static void
F_107 ( struct V_48 * V_269 , struct V_4 * V_4 ,
unsigned long V_270 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_176 * V_220 ;
T_1 V_271 ;
int V_184 , V_272 ;
if ( ( char * ) V_269 == V_4 -> V_109 ) {
V_271 = V_4 -> V_111 ;
V_184 = V_107 ;
F_7 ( L_61 ,
V_271 , V_184 ) ;
} else {
V_271 = V_269 -> V_52 ;
V_184 = V_58 ;
F_7 ( L_62 ,
V_271 , V_184 ) ;
}
F_71 ( V_10 , V_271 , V_184 , V_59 ) ;
V_220 = & V_269 -> V_174 ;
F_7 ( L_63 ,
V_220 -> V_156 , V_220 -> V_202 , V_220 -> V_163 ,
( int ) ( V_270 - V_154 ) ) ;
if ( ( char * ) V_269 == V_4 -> V_109 )
F_76 ( V_269 , V_270 - V_154 ,
V_4 ) ;
else
F_105 ( V_269 , V_4 ) ;
F_66 ( V_10 , V_271 , V_184 ,
V_59 ) ;
V_4 -> V_130 -- ;
F_7 ( L_64 ,
V_4 -> V_130 ) ;
if ( ( char * ) V_269 == V_4 -> V_109 )
return;
V_272 = V_4 -> V_130 ;
if ( V_272 + V_181 <= V_38 ) {
int V_273 , V_139 = F_23 ( V_38 - V_272 ,
V_181 ) ;
V_273 = F_63 ( V_4 , V_139 ) ;
if ( V_273 ) {
F_2 ( L_65 ,
V_139 , V_273 ) ;
}
}
}
static void
F_108 ( struct V_160 * V_160 , struct V_4 * V_4 )
{
struct V_274 * V_275 = & V_160 -> V_165 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
F_7 ( L_66 ) ;
if ( V_275 -> V_169 ) {
F_109 ( V_10 , V_275 -> V_169 , V_275 -> V_147 , V_114 ) ;
V_275 -> V_169 = NULL ;
}
F_18 ( V_275 -> V_152 ) ;
V_275 -> V_152 = NULL ;
F_18 ( V_160 -> V_50 ) ;
V_160 -> V_50 = NULL ;
}
static void
F_110 ( struct V_160 * V_160 )
{
struct V_211 * V_212 = & V_160 -> V_211 ;
struct V_4 * V_4 = V_160 -> V_103 ;
struct V_170 * V_103 ;
F_7 ( L_67 , V_160 ) ;
switch ( V_212 -> V_276 ) {
case V_257 :
V_103 = V_4 -> V_103 ;
F_90 ( & V_103 -> V_277 ) ;
if ( ! F_111 ( & V_212 -> V_278 ) )
F_36 ( & V_212 -> V_278 ) ;
F_91 ( & V_103 -> V_277 ) ;
if ( V_212 -> V_279 == V_114 )
F_112 ( V_212 ) ;
F_108 ( V_160 , V_4 ) ;
case V_260 :
F_113 ( & V_212 -> V_233 , 0 ) ;
break;
case V_280 :
case V_258 :
V_103 = V_4 -> V_103 ;
F_90 ( & V_103 -> V_277 ) ;
if ( ! F_111 ( & V_212 -> V_278 ) )
F_36 ( & V_212 -> V_278 ) ;
F_91 ( & V_103 -> V_277 ) ;
if ( V_212 -> V_233 . V_281 != NULL ) {
F_113 ( & V_212 -> V_233 , 0 ) ;
break;
}
default:
F_80 ( V_212 ) ;
break;
}
}
static void
F_114 ( struct V_149 * V_150 , struct V_9 * V_10 )
{
if ( V_150 -> V_52 != 0 ) {
F_7 ( L_68 ) ;
F_17 ( V_10 , V_150 -> V_52 ,
V_154 , V_114 ) ;
V_150 -> V_52 = 0 ;
}
}
static void
F_115 ( struct V_149 * V_150 , struct V_160 * V_160 ,
struct V_9 * V_10 )
{
if ( V_160 -> V_282 != 0 ) {
F_7 ( L_69 ) ;
F_17 ( V_10 , V_160 -> V_282 ,
V_160 -> V_283 , V_114 ) ;
V_160 -> V_282 = 0 ;
}
F_114 ( V_150 , V_10 ) ;
F_110 ( V_160 ) ;
}
static void
F_116 ( struct V_149 * V_150 ,
struct V_160 * V_160 )
{
struct V_274 * V_275 = & V_160 -> V_165 ;
struct V_211 * V_212 = & V_160 -> V_211 ;
struct V_233 * V_233 = & V_212 -> V_233 ;
struct V_9 * V_10 = V_160 -> V_103 -> V_7 -> V_19 ;
F_112 ( V_212 ) ;
if ( V_275 -> V_169 ) {
F_7 ( L_70 ) ;
F_109 ( V_10 , V_275 -> V_169 , V_275 -> V_147 , V_114 ) ;
V_275 -> V_169 = NULL ;
}
if ( V_160 -> V_50 ) {
F_7 ( L_71 ) ;
F_18 ( V_160 -> V_50 ) ;
V_160 -> V_50 = NULL ;
}
V_212 -> V_236 = V_233 -> V_237 ;
F_7 ( L_72 ) ;
F_90 ( & V_212 -> V_238 ) ;
V_212 -> V_239 |= V_240 ;
V_212 -> V_241 = V_242 ;
F_91 ( & V_212 -> V_238 ) ;
F_117 ( V_233 ) ;
}
static void
F_118 ( struct V_126 * V_127 )
{
struct V_160 * V_160 = F_53 ( V_127 ,
struct V_160 , V_284 ) ;
struct V_4 * V_4 = V_160 -> V_103 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_211 * V_212 = & V_160 -> V_211 ;
switch ( V_212 -> V_241 ) {
case V_285 :
F_7 ( L_73 ) ;
F_69 ( & V_4 -> V_131 ) ;
F_119 ( V_212 , V_212 -> V_103 ) ;
V_212 -> V_241 = V_286 ;
F_115 ( & V_160 -> V_150 , V_160 , V_10 ) ;
break;
case V_287 :
F_7 ( L_74 ) ;
F_69 ( & V_4 -> V_131 ) ;
V_212 -> V_241 = V_286 ;
F_79 ( & V_212 -> V_288 ) ;
F_115 ( & V_160 -> V_150 , V_160 , V_10 ) ;
case V_289 :
F_7 ( L_75 ) ;
V_4 -> V_290 = true ;
F_120 ( V_212 , V_212 -> V_103 ) ;
break;
default:
F_2 ( L_76 , V_212 -> V_241 ) ;
F_62 () ;
break;
}
}
static void
F_121 ( struct V_149 * V_150 ,
struct V_160 * V_160 ,
struct V_4 * V_4 ,
struct V_9 * V_10 )
{
struct V_211 * V_212 = & V_160 -> V_211 ;
if ( V_212 -> V_241 == V_285 ||
V_212 -> V_241 == V_289 ) {
F_114 ( V_150 , V_10 ) ;
F_59 ( & V_160 -> V_284 , F_118 ) ;
F_122 ( V_291 , & V_160 -> V_284 ) ;
return;
}
F_69 ( & V_4 -> V_131 ) ;
V_212 -> V_241 = V_286 ;
F_115 ( V_150 , V_160 , V_10 ) ;
}
static void
F_123 ( struct V_149 * V_150 ,
struct V_4 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_160 * V_160 = V_150 -> V_160 ;
struct V_274 * V_275 ;
if ( ! V_160 ) {
F_69 ( & V_4 -> V_131 ) ;
F_114 ( V_150 , V_10 ) ;
return;
}
V_275 = & V_160 -> V_165 ;
switch ( V_275 -> V_166 ) {
case V_292 :
F_2 ( L_77 ) ;
F_62 () ;
break;
case V_167 :
F_7 ( L_78 ) ;
F_121 ( V_150 , V_160 ,
V_4 , V_10 ) ;
break;
case V_293 :
F_2 ( L_79 ) ;
F_62 () ;
break;
case V_294 :
F_7 ( L_80 ) ;
F_69 ( & V_4 -> V_131 ) ;
F_116 ( V_150 , V_160 ) ;
break;
default:
F_2 ( L_81 , V_275 -> V_166 ) ;
F_62 () ;
break;
}
}
static void
F_124 ( struct V_149 * V_150 , struct V_4 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
if ( V_150 ) {
struct V_160 * V_160 = V_150 -> V_160 ;
if ( ! V_160 )
F_114 ( V_150 , V_10 ) ;
else
F_115 ( V_150 , V_160 , V_10 ) ;
}
if ( V_4 -> V_130 == 0 &&
F_57 ( & V_4 -> V_131 ) == 0 ) {
F_7 ( L_82 ) ;
F_7 ( L_83 ) ;
V_4 -> V_94 = V_295 ;
F_47 ( & V_4 -> V_99 ) ;
}
}
static void
F_125 ( struct V_126 * V_127 )
{
struct V_67 * V_68 = F_53 ( V_127 ,
struct V_67 , V_84 ) ;
struct V_18 * V_19 = V_68 -> V_19 ;
int V_74 = V_68 -> V_74 ;
struct V_296 * V_297 = V_19 -> V_31 [ V_74 ] ;
struct V_4 * V_4 ;
struct V_149 * V_150 ;
struct V_298 V_299 ;
while ( F_126 ( V_297 , 1 , & V_299 ) == 1 ) {
V_150 = (struct V_149 * ) ( unsigned long ) V_299 . V_145 ;
V_4 = V_299 . V_47 -> V_29 ;
if ( V_299 . V_132 == V_300 ) {
F_123 ( V_150 , V_4 ) ;
} else {
F_7 ( L_84 ) ;
F_7 ( L_85 , V_299 . V_132 ) ;
F_69 ( & V_4 -> V_131 ) ;
F_124 ( V_150 , V_4 ) ;
}
}
F_28 ( V_297 , V_80 ) ;
}
static void
V_78 ( struct V_296 * V_301 , void * V_3 )
{
struct V_67 * V_68 = (struct V_67 * ) V_3 ;
F_59 ( & V_68 -> V_84 , F_125 ) ;
F_122 ( V_291 , & V_68 -> V_84 ) ;
}
static void
F_127 ( struct V_126 * V_127 )
{
struct V_67 * V_68 = F_53 ( V_127 ,
struct V_67 , V_83 ) ;
struct V_18 * V_19 = V_68 -> V_19 ;
int V_74 = V_68 -> V_74 ;
struct V_296 * V_302 = V_19 -> V_33 [ V_74 ] ;
struct V_4 * V_4 ;
struct V_48 * V_49 ;
struct V_298 V_299 ;
unsigned long V_270 ;
while ( F_126 ( V_302 , 1 , & V_299 ) == 1 ) {
V_49 = (struct V_48 * ) ( unsigned long ) V_299 . V_145 ;
V_4 = V_299 . V_47 -> V_29 ;
if ( V_299 . V_132 == V_300 ) {
V_270 = ( unsigned long ) V_299 . V_303 ;
F_107 ( V_49 , V_4 , V_270 ) ;
} else {
F_7 ( L_86 ) ;
if ( V_299 . V_132 != V_304 )
F_7 ( L_87 , V_299 . V_132 ) ;
V_4 -> V_130 -- ;
F_124 ( NULL , V_4 ) ;
}
}
F_28 ( V_302 , V_80 ) ;
}
static void
V_75 ( struct V_296 * V_301 , void * V_3 )
{
struct V_67 * V_68 = (struct V_67 * ) V_3 ;
F_59 ( & V_68 -> V_83 , F_127 ) ;
F_122 ( V_305 , & V_68 -> V_83 ) ;
}
static int
F_128 ( struct V_4 * V_4 , struct V_160 * V_160 )
{
struct V_151 * V_306 ;
int V_13 ;
F_67 ( & V_4 -> V_131 ) ;
V_13 = F_68 ( V_4 -> V_46 , & V_160 -> V_150 . V_152 ,
& V_306 ) ;
if ( V_13 ) {
F_2 ( L_88 , V_13 ) ;
F_69 ( & V_4 -> V_131 ) ;
return V_13 ;
}
return V_13 ;
}
static int
F_129 ( struct V_170 * V_103 , struct V_211 * V_212 )
{
struct V_160 * V_160 = F_53 ( V_212 ,
struct V_160 , V_211 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_103 -> V_3 ;
struct V_151 * V_152 = & V_160 -> V_150 . V_152 ;
struct V_307 * V_220 = (struct V_307 * )
& V_160 -> V_150 . V_174 ;
F_70 ( V_4 , V_160 , & V_160 -> V_150 ) ;
F_130 ( V_212 , V_103 , true , V_220 ) ;
F_72 ( V_4 , & V_160 -> V_150 ) ;
if ( V_212 -> V_233 . V_308 &&
( ( V_212 -> V_233 . V_309 & V_310 ) ||
( V_212 -> V_233 . V_309 & V_311 ) ) ) {
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_50 * V_177 = & V_160 -> V_150 . V_155 [ 1 ] ;
T_2 V_312 , V_313 ;
F_131 ( V_212 -> V_233 . V_314 ,
V_212 -> V_308 ) ;
V_212 -> V_233 . V_314 += sizeof( V_315 ) ;
V_312 = - ( V_212 -> V_233 . V_314 ) & 3 ;
F_132 ( V_220 -> V_248 , ( T_2 ) V_212 -> V_233 . V_314 ) ;
V_313 = V_212 -> V_233 . V_314 + V_312 ;
V_160 -> V_282 = F_15 ( V_10 ,
( void * ) V_212 -> V_308 , V_313 ,
V_114 ) ;
V_160 -> V_283 = V_313 ;
V_177 -> V_61 = V_160 -> V_282 ;
V_177 -> V_62 = V_313 ;
V_177 -> V_63 = V_4 -> V_64 -> V_63 ;
V_160 -> V_150 . V_147 = 2 ;
}
F_73 ( V_160 , V_152 ) ;
F_7 ( L_89 ) ;
return F_128 ( V_4 , V_160 ) ;
}
static int
F_133 ( struct V_211 * V_212 , struct V_170 * V_103 ,
bool V_316 )
{
struct V_160 * V_160 = F_53 ( V_212 ,
struct V_160 , V_211 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_103 -> V_3 ;
struct V_151 * V_152 = & V_160 -> V_150 . V_152 ;
F_70 ( V_4 , V_160 , & V_160 -> V_150 ) ;
F_134 ( V_212 , V_103 , (struct V_317 * )
& V_160 -> V_150 . V_174 ,
V_316 ) ;
F_72 ( V_4 , & V_160 -> V_150 ) ;
F_73 ( V_160 , V_152 ) ;
F_7 ( L_90 ) ;
return F_128 ( V_4 , V_160 ) ;
}
static int
F_135 ( struct V_211 * V_212 , struct V_170 * V_103 )
{
struct V_160 * V_160 = F_53 ( V_212 ,
struct V_160 , V_211 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_103 -> V_3 ;
struct V_151 * V_152 = & V_160 -> V_150 . V_152 ;
F_70 ( V_4 , V_160 , & V_160 -> V_150 ) ;
F_136 ( V_212 , V_103 , (struct V_318 * )
& V_160 -> V_150 . V_174 ) ;
F_72 ( V_4 , & V_160 -> V_150 ) ;
F_73 ( V_160 , V_152 ) ;
F_7 ( L_91 ) ;
return F_128 ( V_4 , V_160 ) ;
}
static int
F_137 ( struct V_211 * V_212 , struct V_170 * V_103 )
{
struct V_160 * V_160 = F_53 ( V_212 ,
struct V_160 , V_211 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_103 -> V_3 ;
struct V_151 * V_152 = & V_160 -> V_150 . V_152 ;
F_70 ( V_4 , V_160 , & V_160 -> V_150 ) ;
F_138 ( V_212 , V_103 , (struct V_319 * )
& V_160 -> V_150 . V_174 ) ;
F_72 ( V_4 , & V_160 -> V_150 ) ;
F_73 ( V_160 , V_152 ) ;
F_7 ( L_92 ) ;
return F_128 ( V_4 , V_160 ) ;
}
static int
F_139 ( struct V_211 * V_212 , struct V_170 * V_103 )
{
struct V_160 * V_160 = F_53 ( V_212 ,
struct V_160 , V_211 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_103 -> V_3 ;
struct V_151 * V_152 = & V_160 -> V_150 . V_152 ;
F_70 ( V_4 , V_160 , & V_160 -> V_150 ) ;
F_140 ( V_212 , V_103 , (struct V_320 * )
& V_160 -> V_150 . V_174 ) ;
F_72 ( V_4 , & V_160 -> V_150 ) ;
F_73 ( V_160 , V_152 ) ;
F_7 ( L_93 ) ;
return F_128 ( V_4 , V_160 ) ;
}
static int
F_141 ( struct V_4 * V_4 , struct V_160 * V_160 ,
struct V_50 * V_50 , struct V_151 * V_152 ,
T_2 V_321 , T_2 V_322 )
{
struct V_211 * V_212 = & V_160 -> V_211 ;
struct V_221 * V_245 , * V_323 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
T_2 V_249 , V_250 ;
int V_53 = 0 , V_226 ;
V_249 = V_322 / V_235 ;
V_245 = & V_212 -> V_233 . V_234 [ V_249 ] ;
V_226 = F_23 ( V_212 -> V_233 . V_324 - V_249 , V_4 -> V_14 ) ;
V_250 = V_322 % V_235 ;
V_152 -> V_146 = V_50 ;
V_152 -> V_147 = V_226 ;
V_152 -> V_145 = ( unsigned long ) & V_160 -> V_150 ;
F_142 (sg_start, tmp_sg, sg_nents, i) {
F_7 ( L_94 ,
( unsigned long long ) V_323 -> V_325 ,
V_323 -> V_62 , V_250 ) ;
V_50 -> V_61 = F_143 ( V_10 , V_323 ) + V_250 ;
V_50 -> V_62 = F_21 ( T_2 , V_321 ,
F_144 ( V_10 , V_323 ) - V_250 ) ;
V_50 -> V_63 = V_4 -> V_64 -> V_63 ;
F_7 ( L_95 ,
V_50 -> V_61 , V_50 -> V_62 ) ;
V_250 = 0 ;
V_321 -= V_50 -> V_62 ;
V_50 ++ ;
F_7 ( L_96 , V_50 ) ;
}
F_7 ( L_97 ,
V_152 -> V_146 , V_152 -> V_147 ) ;
return V_226 ;
}
static int
F_145 ( struct V_170 * V_103 , struct V_211 * V_212 )
{
struct V_233 * V_233 = & V_212 -> V_233 ;
struct V_160 * V_160 = F_53 ( V_212 ,
struct V_160 , V_211 ) ;
struct V_274 * V_275 = & V_160 -> V_165 ;
struct V_4 * V_4 = (struct V_4 * ) V_103 -> V_3 ;
struct V_151 * V_306 , * V_152 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_50 * V_50 ;
struct V_221 * V_222 ;
T_2 V_322 = 0 , V_326 , V_321 , V_327 ;
int V_227 , V_13 = 0 , V_139 , V_226 , V_53 , V_328 ;
F_7 ( L_98 , V_233 -> V_237 ) ;
V_222 = & V_233 -> V_234 [ 0 ] ;
V_226 = V_233 -> V_324 ;
V_139 = F_146 ( V_10 , V_222 , V_226 , V_114 ) ;
if ( F_147 ( ! V_139 ) ) {
F_2 ( L_99 ) ;
return - V_255 ;
}
V_275 -> V_169 = V_222 ;
V_275 -> V_147 = V_226 ;
F_7 ( L_100 ,
V_139 , V_222 , V_226 ) ;
V_50 = F_14 ( sizeof( struct V_50 ) * V_226 , V_56 ) ;
if ( ! V_50 ) {
F_4 ( L_101 ) ;
V_13 = - V_66 ;
goto V_329;
}
V_160 -> V_50 = V_50 ;
F_7 ( L_102 ,
V_50 , V_233 -> V_324 ) ;
V_275 -> V_330 = F_88 ( V_226 , V_4 -> V_14 ) ;
V_275 -> V_152 = F_14 ( sizeof( struct V_151 ) * V_275 -> V_330 ,
V_56 ) ;
if ( ! V_275 -> V_152 ) {
F_2 ( L_103 ) ;
V_13 = - V_66 ;
goto V_329;
}
F_7 ( L_104 ,
V_275 -> V_152 , V_275 -> V_330 ) ;
F_148 ( V_212 , V_103 -> V_331 ) ;
V_212 -> V_332 = V_103 -> V_332 ++ ;
V_275 -> V_160 = V_160 ;
V_327 = V_4 -> V_14 * V_235 ;
V_321 = V_233 -> V_237 ;
for ( V_53 = 0 ; V_53 < V_275 -> V_330 ; V_53 ++ ) {
V_152 = & V_160 -> V_165 . V_152 [ V_53 ] ;
V_326 = F_23 ( V_321 , V_327 ) ;
V_152 -> V_156 = V_333 ;
V_152 -> V_158 = 0 ;
V_152 -> V_275 . V_334 . V_335 = V_160 -> V_252 + V_322 ;
V_152 -> V_275 . V_334 . V_336 = V_160 -> V_251 ;
V_328 = F_141 ( V_4 , V_160 , V_50 ,
V_152 , V_326 , V_322 ) ;
V_50 += V_328 ;
if ( V_53 + 1 == V_275 -> V_330 )
V_152 -> V_148 = & V_160 -> V_150 . V_152 ;
else
V_152 -> V_148 = & V_275 -> V_152 [ V_53 + 1 ] ;
V_322 += V_326 ;
V_321 -= V_326 ;
}
F_70 ( V_4 , V_160 , & V_160 -> V_150 ) ;
F_130 ( V_212 , V_103 , false , (struct V_307 * )
& V_160 -> V_150 . V_174 ) ;
F_72 ( V_4 , & V_160 -> V_150 ) ;
F_73 ( V_160 , & V_160 -> V_150 . V_152 ) ;
F_67 ( & V_4 -> V_131 ) ;
V_227 = F_68 ( V_4 -> V_46 , V_275 -> V_152 , & V_306 ) ;
if ( V_227 ) {
F_4 ( L_105 ) ;
F_69 ( & V_4 -> V_131 ) ;
}
F_7 ( L_106 ) ;
return 1 ;
V_329:
F_109 ( V_10 , V_222 , V_226 , V_114 ) ;
return V_13 ;
}
static int
F_149 ( struct V_170 * V_103 , struct V_211 * V_212 , bool V_337 )
{
struct V_233 * V_233 = & V_212 -> V_233 ;
struct V_160 * V_160 = F_53 ( V_212 ,
struct V_160 , V_211 ) ;
struct V_274 * V_275 = & V_160 -> V_165 ;
struct V_4 * V_4 = (struct V_4 * ) V_103 -> V_3 ;
struct V_151 * V_306 , * V_152 ;
struct V_50 * V_50 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_221 * V_245 ;
T_2 V_249 , V_226 , V_250 , V_338 = 0 ;
T_2 V_322 = 0 , V_326 , V_321 , V_327 ;
int V_227 , V_13 = 0 , V_139 , V_53 , V_328 ;
F_7 ( L_107 ,
V_233 -> V_237 , V_212 -> V_236 ) ;
V_249 = V_212 -> V_236 / V_235 ;
V_245 = & V_212 -> V_233 . V_234 [ V_249 ] ;
V_250 = V_212 -> V_236 % V_235 ;
F_7 ( L_108 ,
V_249 , V_245 , V_250 ) ;
V_321 = V_233 -> V_237 - V_212 -> V_236 ;
V_226 = V_233 -> V_324 - V_249 ;
F_7 ( L_109 ,
V_321 , V_226 ) ;
V_139 = F_146 ( V_10 , V_245 , V_226 , V_59 ) ;
if ( F_147 ( ! V_139 ) ) {
F_2 ( L_110 ) ;
return - V_255 ;
}
V_275 -> V_169 = V_245 ;
V_275 -> V_147 = V_226 ;
F_7 ( L_111 ,
V_139 , V_245 , V_226 ) ;
V_50 = F_14 ( sizeof( struct V_50 ) * V_226 , V_56 ) ;
if ( ! V_50 ) {
F_4 ( L_112 ) ;
V_13 = - V_66 ;
goto V_329;
}
V_160 -> V_50 = V_50 ;
F_7 ( L_113 ,
V_50 , V_226 ) ;
V_275 -> V_330 = F_88 ( V_226 , V_4 -> V_14 ) ;
V_275 -> V_152 = F_14 ( sizeof( struct V_151 ) * V_275 -> V_330 ,
V_56 ) ;
if ( ! V_275 -> V_152 ) {
F_7 ( L_103 ) ;
V_13 = - V_66 ;
goto V_329;
}
F_7 ( L_104 ,
V_275 -> V_152 , V_275 -> V_330 ) ;
V_160 -> V_150 . V_160 = V_160 ;
V_275 -> V_166 = V_294 ;
V_275 -> V_160 = V_160 ;
V_327 = V_4 -> V_14 * V_235 ;
V_322 = V_212 -> V_236 ;
for ( V_53 = 0 ; V_53 < V_275 -> V_330 ; V_53 ++ ) {
V_152 = & V_160 -> V_165 . V_152 [ V_53 ] ;
V_326 = F_23 ( V_321 , V_327 ) ;
V_152 -> V_156 = V_339 ;
V_152 -> V_275 . V_334 . V_335 = V_160 -> V_254 + V_338 ;
V_152 -> V_275 . V_334 . V_336 = V_160 -> V_253 ;
V_328 = F_141 ( V_4 , V_160 , V_50 ,
V_152 , V_326 , V_322 ) ;
V_50 += V_328 ;
if ( V_53 + 1 == V_275 -> V_330 )
V_152 -> V_158 = V_159 ;
else
V_152 -> V_148 = & V_275 -> V_152 [ V_53 + 1 ] ;
V_322 += V_326 ;
V_338 += V_326 ;
V_321 -= V_326 ;
}
F_67 ( & V_4 -> V_131 ) ;
V_227 = F_68 ( V_4 -> V_46 , V_275 -> V_152 , & V_306 ) ;
if ( V_227 ) {
F_4 ( L_114 ) ;
F_69 ( & V_4 -> V_131 ) ;
}
F_7 ( L_115 ) ;
return 0 ;
V_329:
F_109 ( V_10 , V_245 , V_226 , V_59 ) ;
return V_13 ;
}
static int
F_150 ( struct V_170 * V_103 , struct V_211 * V_212 , int V_94 )
{
int V_13 ;
switch ( V_94 ) {
case V_340 :
V_13 = F_133 ( V_212 , V_103 , false ) ;
break;
default:
F_2 ( L_116 , V_94 ) ;
V_13 = - V_255 ;
break;
}
return V_13 ;
}
static int
F_151 ( struct V_170 * V_103 , struct V_211 * V_212 , int V_94 )
{
int V_13 ;
switch ( V_94 ) {
case V_289 :
V_13 = F_135 ( V_212 , V_103 ) ;
if ( ! V_13 ) {
F_7 ( L_117 ) ;
V_13 = - V_341 ;
}
break;
case V_342 :
V_13 = F_133 ( V_212 , V_103 , true ) ;
break;
case V_285 :
V_13 = F_137 ( V_212 , V_103 ) ;
break;
case V_287 :
V_13 = F_139 ( V_212 , V_103 ) ;
break;
case V_343 :
V_13 = F_129 ( V_103 , V_212 ) ;
break;
default:
F_2 ( L_118 , V_94 ) ;
V_13 = - V_255 ;
break;
}
return V_13 ;
}
static int
F_152 ( struct V_90 * V_91 ,
struct V_344 * V_345 )
{
struct V_92 * V_92 ;
struct V_16 * V_346 ;
struct V_347 * V_348 ;
int V_13 ;
V_92 = F_14 ( sizeof( struct V_92 ) , V_56 ) ;
if ( ! V_92 ) {
F_2 ( L_119 ) ;
return - V_66 ;
}
F_44 ( & V_92 -> V_120 ) ;
F_153 ( & V_92 -> V_118 ) ;
F_40 ( & V_92 -> V_119 ) ;
F_43 ( & V_92 -> V_349 ) ;
V_348 = (struct V_347 * ) V_345 ;
F_7 ( L_120 , V_345 , V_348 ) ;
memcpy ( & V_91 -> V_350 , V_345 ,
sizeof( struct V_344 ) ) ;
V_346 = F_154 ( F_61 , V_91 , V_351 ,
V_44 ) ;
if ( F_25 ( V_346 ) ) {
F_2 ( L_121 ,
F_26 ( V_346 ) ) ;
V_13 = F_26 ( V_346 ) ;
goto V_108;
}
V_13 = F_155 ( V_346 , V_348 ) ;
if ( V_13 ) {
F_2 ( L_122 , V_13 ) ;
goto V_352;
}
V_13 = F_156 ( V_346 , V_353 ) ;
if ( V_13 ) {
F_2 ( L_123 , V_13 ) ;
goto V_352;
}
V_92 -> V_354 = V_346 ;
V_91 -> V_93 = V_92 ;
F_7 ( L_124 , V_346 -> V_3 ) ;
return 0 ;
V_352:
F_50 ( V_346 ) ;
V_108:
F_18 ( V_92 ) ;
return V_13 ;
}
static int
F_157 ( struct V_92 * V_92 )
{
int V_355 ;
F_9 ( & V_92 -> V_118 ) ;
V_355 = F_111 ( & V_92 -> V_119 ) ;
F_10 ( & V_92 -> V_118 ) ;
return V_355 ;
}
static int
F_158 ( struct V_4 * V_4 )
{
struct V_16 * V_356 = V_4 -> V_7 ;
struct V_357 V_358 ;
int V_13 ;
memset ( & V_358 , 0 , sizeof( struct V_357 ) ) ;
V_358 . V_101 = V_4 -> V_101 ;
V_358 . V_104 = V_4 -> V_104 ;
V_358 . V_359 = 7 ;
V_358 . V_360 = 7 ;
F_7 ( L_125 ) ;
V_13 = F_159 ( V_356 , & V_358 ) ;
if ( V_13 ) {
F_2 ( L_126 , V_13 ) ;
return V_13 ;
}
F_7 ( L_127 ) ;
return 0 ;
}
static int
F_160 ( struct V_170 * V_103 , struct V_171 * V_172 )
{
struct V_4 * V_4 = (struct V_4 * ) V_103 -> V_3 ;
int V_13 ;
F_7 ( L_128 , V_103 ) ;
V_13 = F_161 ( & V_4 -> V_97 ) ;
if ( V_13 )
return V_13 ;
F_7 ( L_129 , V_172 -> V_206 ) ;
return 0 ;
}
static void
F_162 ( struct V_90 * V_91 , struct V_170 * V_103 ,
struct V_4 * V_4 )
{
struct V_16 * V_356 = V_4 -> V_7 ;
struct V_361 * V_362 = & V_356 -> V_363 ;
struct V_364 * V_365 ;
struct V_366 * V_367 ;
V_103 -> V_368 = V_91 -> V_350 . V_369 ;
if ( V_91 -> V_350 . V_369 == V_370 ) {
V_367 = (struct V_366 * ) & V_362 -> V_61 . V_371 ;
snprintf ( V_103 -> V_372 , sizeof( V_103 -> V_372 ) , L_130 ,
& V_367 -> V_373 . V_374 ) ;
V_103 -> V_375 = F_163 ( V_367 -> V_376 ) ;
V_367 = (struct V_366 * ) & V_362 -> V_61 . V_377 ;
snprintf ( V_103 -> V_378 , sizeof( V_103 -> V_378 ) , L_130 ,
& V_367 -> V_373 . V_374 ) ;
V_103 -> V_379 = F_163 ( V_367 -> V_376 ) ;
} else {
V_365 = (struct V_364 * ) & V_362 -> V_61 . V_371 ;
sprintf ( V_103 -> V_372 , L_131 ,
& V_365 -> V_380 . V_381 ) ;
V_103 -> V_375 = F_163 ( V_365 -> V_382 ) ;
V_365 = (struct V_364 * ) & V_362 -> V_61 . V_377 ;
sprintf ( V_103 -> V_378 , L_131 ,
& V_365 -> V_380 . V_381 ) ;
V_103 -> V_379 = F_163 ( V_365 -> V_382 ) ;
}
}
static int
F_164 ( struct V_90 * V_91 , struct V_170 * V_103 )
{
struct V_92 * V_92 = (struct V_92 * ) V_91 -> V_93 ;
struct V_4 * V_4 ;
int V_383 = 0 , V_13 ;
V_384:
V_13 = F_165 ( V_92 -> V_120 ,
! F_157 ( V_92 ) ||
V_91 -> V_385 == V_386 ) ;
if ( V_383 > 5 )
return - V_387 ;
F_90 ( & V_91 -> V_388 ) ;
if ( V_91 -> V_385 == V_386 ) {
F_91 ( & V_91 -> V_388 ) ;
F_2 ( L_132 ) ;
return - V_387 ;
}
F_91 ( & V_91 -> V_388 ) ;
F_9 ( & V_92 -> V_118 ) ;
if ( F_111 ( & V_92 -> V_119 ) ) {
F_10 ( & V_92 -> V_118 ) ;
V_383 ++ ;
goto V_384;
}
V_4 = F_166 ( & V_92 -> V_119 ,
struct V_4 , V_96 ) ;
F_167 ( & V_4 -> V_96 ) ;
F_10 ( & V_92 -> V_118 ) ;
V_103 -> V_3 = V_4 ;
V_4 -> V_103 = V_103 ;
V_383 = 0 ;
V_13 = F_74 ( V_4 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_158 ( V_4 ) ;
if ( V_13 )
return V_13 ;
F_162 ( V_91 , V_103 , V_4 ) ;
F_7 ( L_133 , V_4 ) ;
return 0 ;
}
static void
F_168 ( struct V_90 * V_91 )
{
struct V_92 * V_92 = (struct V_92 * ) V_91 -> V_93 ;
F_50 ( V_92 -> V_354 ) ;
V_91 -> V_93 = NULL ;
F_18 ( V_92 ) ;
}
static void F_169 ( struct V_170 * V_103 )
{
struct V_4 * V_4 = V_103 -> V_3 ;
F_7 ( L_134 ) ;
if ( V_4 -> V_290 )
F_69 ( & V_4 -> V_131 ) ;
if ( V_4 -> V_7 )
F_170 ( V_4 -> V_7 ) ;
if ( V_4 -> V_94 > V_95 ) {
F_7 ( L_135 ,
V_4 -> V_94 ) ;
F_171 ( V_4 -> V_99 ,
V_4 -> V_94 == V_295 ) ;
F_7 ( L_136 ) ;
}
F_7 ( L_137 , V_4 -> V_94 ) ;
F_171 ( V_4 -> V_98 , V_4 -> V_94 == V_129 ) ;
F_7 ( L_138 ) ;
F_54 ( V_4 ) ;
}
static int T_7 F_172 ( void )
{
int V_13 ;
V_305 = F_173 ( L_139 , 0 , 0 ) ;
if ( ! V_305 ) {
F_2 ( L_140 ) ;
return - V_66 ;
}
V_291 = F_173 ( L_141 , 0 , 0 ) ;
if ( ! V_291 ) {
F_2 ( L_142 ) ;
V_13 = - V_66 ;
goto V_389;
}
V_215 = F_174 ( L_143 ,
sizeof( struct V_160 ) , F_175 ( struct V_160 ) ,
0 , NULL ) ;
if ( ! V_215 ) {
F_2 ( L_144 ) ;
V_13 = - V_66 ;
goto V_390;
}
F_176 ( & V_391 ) ;
F_7 ( L_145 ) ;
return 0 ;
V_390:
F_177 ( V_291 ) ;
V_389:
F_177 ( V_305 ) ;
return V_13 ;
}
static void T_8 F_178 ( void )
{
F_179 ( V_215 ) ;
F_177 ( V_291 ) ;
F_177 ( V_305 ) ;
F_180 ( & V_391 ) ;
F_7 ( L_146 ) ;
}
