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
F_47 ( & V_4 -> V_101 ) ;
V_17 -> V_3 = V_4 ;
V_4 -> V_7 = V_17 ;
V_4 -> V_102 = V_5 -> V_103 . V_104 . V_102 ;
V_4 -> V_105 = V_5 -> V_103 . V_104 . V_105 ;
F_7 ( L_18 ,
V_4 -> V_102 , V_4 -> V_105 ) ;
V_4 -> V_106 = F_14 ( V_107 +
V_108 , V_56 ) ;
if ( ! V_4 -> V_106 ) {
F_2 ( L_19 ) ;
V_13 = - V_66 ;
goto V_109;
}
V_4 -> V_110 = V_4 -> V_106 ;
V_4 -> V_111 = V_4 -> V_106 +
V_107 ;
F_7 ( L_20 ,
V_4 -> V_106 , V_4 -> V_110 ,
V_4 -> V_111 ) ;
V_4 -> V_112 = F_15 ( V_10 ,
( void * ) V_4 -> V_110 ,
V_107 , V_59 ) ;
V_13 = F_16 ( V_10 , V_4 -> V_112 ) ;
if ( V_13 ) {
F_2 ( L_21 ,
V_13 ) ;
V_4 -> V_112 = 0 ;
goto V_113;
}
V_4 -> V_114 = F_15 ( V_10 ,
( void * ) V_4 -> V_111 ,
V_108 , V_115 ) ;
V_13 = F_16 ( V_10 , V_4 -> V_114 ) ;
if ( V_13 ) {
F_2 ( L_22 ,
V_13 ) ;
V_4 -> V_114 = 0 ;
goto V_116;
}
V_19 = F_37 ( V_17 ) ;
if ( F_25 ( V_19 ) ) {
V_13 = F_26 ( V_19 ) ;
goto V_117;
}
V_4 -> V_20 = V_19 ;
V_4 -> V_45 = V_19 -> V_72 ;
V_4 -> V_64 = V_19 -> V_81 ;
V_13 = F_8 ( V_4 , V_17 ) ;
if ( V_13 )
goto V_118;
F_9 ( & V_92 -> V_119 ) ;
F_41 ( & V_92 -> V_120 , & V_4 -> V_96 ) ;
F_10 ( & V_92 -> V_119 ) ;
F_7 ( L_23 , V_91 ) ;
F_48 ( & V_92 -> V_121 ) ;
return 0 ;
V_118:
F_35 ( V_19 ) ;
V_117:
F_17 ( V_10 , V_4 -> V_114 ,
V_108 , V_115 ) ;
V_116:
F_17 ( V_10 , V_4 -> V_112 ,
V_107 , V_59 ) ;
V_113:
F_18 ( V_4 -> V_106 ) ;
V_109:
F_18 ( V_4 ) ;
return V_13 ;
}
static void
F_49 ( struct V_4 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_18 * V_19 = V_4 -> V_20 ;
int V_74 ;
F_7 ( L_24 ) ;
if ( V_4 -> V_46 ) {
V_74 = ( (struct V_67 * )
V_4 -> V_46 -> V_32 -> V_122 ) -> V_74 ;
F_7 ( L_25 , V_74 ) ;
V_4 -> V_20 -> V_27 [ V_74 ] -- ;
F_50 ( V_4 -> V_7 ) ;
}
F_19 ( V_4 ) ;
F_51 ( V_4 -> V_7 ) ;
if ( V_4 -> V_106 ) {
F_17 ( V_10 , V_4 -> V_114 ,
V_108 , V_115 ) ;
F_17 ( V_10 , V_4 -> V_112 ,
V_107 ,
V_59 ) ;
F_18 ( V_4 -> V_106 ) ;
}
F_18 ( V_4 ) ;
if ( V_19 )
F_35 ( V_19 ) ;
F_7 ( L_26 ) ;
}
static void
F_52 ( struct V_16 * V_17 )
{
return;
}
static void
F_53 ( struct V_123 * V_123 )
{
struct V_4 * V_4 = F_54 ( V_123 ,
struct V_4 , V_100 ) ;
F_7 ( L_27 ,
V_124 -> V_125 , V_124 -> V_126 ) ;
F_49 ( V_4 ) ;
}
static void
F_55 ( struct V_4 * V_4 )
{
F_56 ( & V_4 -> V_100 , F_53 ) ;
}
static void
F_57 ( struct V_127 * V_128 )
{
struct V_4 * V_4 = F_54 ( V_128 ,
struct V_4 , V_129 ) ;
F_7 ( L_28 ) ;
F_9 ( & V_4 -> V_101 ) ;
V_4 -> V_94 = V_130 ;
if ( V_4 -> V_131 == 0 &&
F_58 ( & V_4 -> V_132 ) == 0 ) {
F_7 ( L_29 ) ;
F_10 ( & V_4 -> V_101 ) ;
goto F_48;
}
if ( ! V_4 -> V_7 ) {
F_10 ( & V_4 -> V_101 ) ;
F_55 ( V_4 ) ;
return;
}
if ( ! V_4 -> V_133 ) {
F_7 ( L_30
L_31 ) ;
F_59 ( V_4 -> V_7 ) ;
F_10 ( & V_4 -> V_101 ) ;
F_60 ( V_4 -> V_104 , 0 ) ;
goto F_48;
}
F_10 ( & V_4 -> V_101 ) ;
F_48:
F_48 ( & V_4 -> V_98 ) ;
F_55 ( V_4 ) ;
}
static void
F_61 ( struct V_16 * V_17 )
{
struct V_4 * V_4 = (struct V_4 * ) V_17 -> V_3 ;
F_62 ( & V_4 -> V_129 , F_57 ) ;
F_63 ( & V_4 -> V_129 ) ;
}
static int
F_64 ( struct V_16 * V_17 , struct V_89 * V_5 )
{
int V_13 = 0 ;
F_7 ( L_32 ,
V_5 -> V_5 , V_5 -> V_134 , V_17 -> V_3 , V_17 ) ;
switch ( V_5 -> V_5 ) {
case V_135 :
F_7 ( L_33 ) ;
V_13 = F_42 ( V_17 , V_5 ) ;
break;
case V_136 :
F_7 ( L_34 ) ;
F_52 ( V_17 ) ;
break;
case V_137 :
F_7 ( L_35 ) ;
F_61 ( V_17 ) ;
break;
case V_138 :
case V_139 :
break;
case V_140 :
default:
F_2 ( L_36 , V_5 -> V_5 ) ;
break;
}
if ( V_13 != 0 ) {
F_2 ( L_37 ,
V_5 -> V_5 , V_13 ) ;
F_65 () ;
}
return V_13 ;
}
static int
F_66 ( struct V_4 * V_4 , T_2 V_141 )
{
struct V_142 * V_143 , * V_144 ;
int V_53 , V_13 ;
unsigned int V_145 = V_4 -> V_65 ;
struct V_48 * V_49 ;
for ( V_143 = V_4 -> V_146 , V_53 = 0 ; V_53 < V_141 ; V_53 ++ , V_143 ++ ) {
V_49 = & V_4 -> V_55 [ V_145 ] ;
V_143 -> V_147 = ( unsigned long ) V_49 ;
V_143 -> V_148 = & V_49 -> V_51 ;
V_143 -> V_149 = 1 ;
V_143 -> V_150 = V_143 + 1 ;
V_145 = ( V_145 + 1 ) & ( V_38 - 1 ) ;
}
V_143 -- ;
V_143 -> V_150 = NULL ;
V_4 -> V_131 += V_141 ;
V_13 = F_67 ( V_4 -> V_46 , V_4 -> V_146 ,
& V_144 ) ;
if ( V_13 ) {
F_2 ( L_38 , V_13 ) ;
V_4 -> V_131 -= V_141 ;
} else {
F_7 ( L_39 , V_141 ) ;
V_4 -> V_65 = V_145 ;
}
return V_13 ;
}
static int
F_68 ( struct V_4 * V_4 , struct V_151 * V_152 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_153 V_154 , * V_155 ;
int V_13 ;
F_69 ( V_10 , V_152 -> V_52 ,
V_156 , V_115 ) ;
V_154 . V_150 = NULL ;
V_154 . V_147 = ( unsigned long ) V_152 ;
V_154 . V_148 = V_152 -> V_157 ;
V_154 . V_149 = V_152 -> V_149 ;
V_154 . V_158 = V_159 ;
V_154 . V_160 = V_161 ;
F_70 ( & V_4 -> V_132 ) ;
V_13 = F_71 ( V_4 -> V_46 , & V_154 , & V_155 ) ;
if ( V_13 ) {
F_2 ( L_40 , V_13 ) ;
F_72 ( & V_4 -> V_132 ) ;
}
return V_13 ;
}
static void
F_73 ( struct V_4 * V_4 ,
struct V_162 * V_162 ,
struct V_151 * V_152 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
F_74 ( V_10 , V_152 -> V_52 ,
V_156 , V_115 ) ;
memset ( & V_152 -> V_163 , 0 , sizeof( struct V_164 ) ) ;
V_152 -> V_163 . V_165 = V_166 ;
V_152 -> V_149 = 1 ;
V_152 -> V_162 = V_162 ;
if ( V_152 -> V_157 [ 0 ] . V_63 != V_4 -> V_64 -> V_63 ) {
V_152 -> V_157 [ 0 ] . V_63 = V_4 -> V_64 -> V_63 ;
F_7 ( L_41 , V_152 ) ;
}
}
static int
F_75 ( struct V_4 * V_4 ,
struct V_151 * V_152 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
T_1 V_52 ;
V_52 = F_15 ( V_10 , ( void * ) V_152 ,
V_156 , V_115 ) ;
if ( F_16 ( V_10 , V_52 ) ) {
F_2 ( L_42 ) ;
return - V_66 ;
}
V_152 -> V_52 = V_52 ;
V_152 -> V_157 [ 0 ] . V_61 = V_152 -> V_52 ;
V_152 -> V_157 [ 0 ] . V_62 = V_156 ;
V_152 -> V_157 [ 0 ] . V_63 = V_4 -> V_64 -> V_63 ;
F_7 ( L_43
L_44 , V_152 -> V_157 [ 0 ] . V_61 ,
V_152 -> V_157 [ 0 ] . V_62 , V_152 -> V_157 [ 0 ] . V_63 ) ;
return 0 ;
}
static void
F_76 ( struct V_162 * V_162 , struct V_153 * V_154 )
{
V_162 -> V_167 . V_168 = V_169 ;
V_154 -> V_147 = ( unsigned long ) & V_162 -> V_152 ;
V_154 -> V_158 = V_159 ;
V_154 -> V_160 = V_161 ;
V_154 -> V_148 = & V_162 -> V_152 . V_157 [ 0 ] ;
V_154 -> V_149 = V_162 -> V_152 . V_149 ;
}
static int
F_77 ( struct V_4 * V_4 )
{
struct V_142 V_143 , * V_170 ;
struct V_50 V_171 ;
int V_13 ;
memset ( & V_171 , 0 , sizeof( struct V_50 ) ) ;
V_171 . V_61 = V_4 -> V_112 ;
V_171 . V_62 = V_108 ;
V_171 . V_63 = V_4 -> V_64 -> V_63 ;
F_7 ( L_45 ,
V_171 . V_61 , V_171 . V_62 , V_171 . V_63 ) ;
memset ( & V_143 , 0 , sizeof( struct V_142 ) ) ;
V_143 . V_147 = ( unsigned long ) V_4 -> V_110 ;
V_143 . V_148 = & V_171 ;
V_143 . V_149 = 1 ;
V_4 -> V_131 ++ ;
V_13 = F_67 ( V_4 -> V_46 , & V_143 , & V_170 ) ;
if ( V_13 ) {
F_2 ( L_46 , V_13 ) ;
V_4 -> V_131 -- ;
}
F_7 ( L_47 ) ;
return V_13 ;
}
static int
F_78 ( struct V_172 * V_104 , struct V_173 * V_174 ,
T_2 V_62 )
{
struct V_4 * V_4 = V_104 -> V_3 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_151 * V_152 = & V_4 -> V_175 ;
int V_13 ;
F_73 ( V_4 , NULL , V_152 ) ;
memcpy ( & V_152 -> V_176 , & V_174 -> V_177 [ 0 ] ,
sizeof( struct V_178 ) ) ;
F_75 ( V_4 , V_152 ) ;
if ( V_62 > 0 ) {
struct V_50 * V_179 = & V_152 -> V_157 [ 1 ] ;
F_74 ( V_10 , V_4 -> V_114 ,
V_62 , V_115 ) ;
memcpy ( V_4 -> V_111 , V_174 -> V_180 , V_62 ) ;
F_69 ( V_10 , V_4 -> V_114 ,
V_62 , V_115 ) ;
V_179 -> V_61 = V_4 -> V_114 ;
V_179 -> V_62 = V_62 ;
V_179 -> V_63 = V_4 -> V_64 -> V_63 ;
V_152 -> V_149 = 2 ;
}
if ( ! V_174 -> V_181 ) {
if ( V_174 -> V_182 ) {
V_13 = F_13 ( V_4 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_66 ( V_4 , V_183 ) ;
if ( V_13 )
return V_13 ;
V_4 -> V_94 = V_184 ;
goto V_185;
}
V_13 = F_77 ( V_4 ) ;
if ( V_13 )
return V_13 ;
}
V_185:
V_13 = F_68 ( V_4 , V_152 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static void
F_79 ( struct V_48 * V_49 , int V_186 ,
struct V_4 * V_4 )
{
struct V_172 * V_104 = V_4 -> V_104 ;
struct V_173 * V_174 = V_104 -> V_187 ;
int V_188 ;
if ( ! V_174 ) {
F_2 ( L_48 ) ;
F_65 () ;
return;
}
if ( V_174 -> V_189 ) {
struct V_190 * V_191 =
(struct V_190 * ) & V_49 -> V_176 ;
V_174 -> V_192 = ( ! V_191 -> V_193 ) ? 1 : 0 ;
V_174 -> V_194 =
( V_191 -> V_165 & V_195 )
>> 2 ;
V_174 -> V_196 = V_191 -> V_197 ;
V_174 -> V_198 = V_191 -> V_199 ;
memcpy ( V_174 -> V_200 , V_191 -> V_200 , 6 ) ;
V_174 -> V_201 = F_80 ( V_191 -> V_202 ) ;
V_174 -> V_203 = V_191 -> V_204 ;
V_174 -> V_205 = F_80 ( V_191 -> V_206 ) ;
V_174 -> V_207 = F_81 ( V_191 -> V_207 ) ;
V_174 -> V_193 = F_81 ( V_191 -> V_193 ) ;
}
memcpy ( & V_174 -> V_208 [ 0 ] , ( void * ) & V_49 -> V_176 , V_209 ) ;
V_188 = F_23 ( V_186 , V_210 ) ;
F_7 ( L_49 ,
V_188 , V_186 , V_210 ) ;
memcpy ( V_174 -> V_211 , & V_49 -> V_212 [ 0 ] , V_188 ) ;
F_82 ( & V_4 -> V_97 ) ;
}
static void
F_83 ( struct V_213 * V_214 )
{
struct V_162 * V_162 = F_54 ( V_214 , struct V_162 ,
V_213 ) ;
F_7 ( L_50 , V_162 ) ;
F_18 ( V_214 -> V_215 ) ;
F_18 ( V_214 -> V_216 ) ;
F_84 ( V_217 , V_162 ) ;
}
static struct V_213
* F_85 ( struct V_172 * V_104 , T_3 V_218 )
{
struct V_4 * V_4 = (struct V_4 * ) V_104 -> V_3 ;
struct V_162 * V_162 ;
V_162 = F_86 ( V_217 , V_218 ) ;
if ( ! V_162 ) {
F_2 ( L_51 ) ;
return NULL ;
}
V_162 -> V_104 = V_4 ;
V_162 -> V_213 . V_219 = & F_83 ;
return & V_162 -> V_213 ;
}
static int
F_87 ( struct V_4 * V_4 ,
struct V_162 * V_162 , struct V_48 * V_49 ,
unsigned char * V_220 )
{
struct V_213 * V_214 = & V_162 -> V_213 ;
struct V_172 * V_104 = V_4 -> V_104 ;
struct V_221 * V_222 = (struct V_221 * ) V_220 ;
struct V_223 * V_224 ;
int V_225 , V_226 , V_227 , V_228 , V_229 ;
bool V_230 = false ;
V_229 = F_88 ( V_104 , V_214 , V_220 ) ;
if ( V_229 < 0 )
return V_229 ;
V_225 = V_214 -> V_231 ;
V_226 = V_214 -> V_232 ;
V_227 = V_214 -> V_233 ;
V_229 = F_89 ( V_104 , V_214 , V_222 ) ;
if ( V_229 < 0 ) {
return 0 ;
} else if ( V_229 > 0 ) {
V_230 = true ;
goto V_234;
}
if ( ! V_225 )
return 0 ;
V_224 = & V_214 -> V_235 . V_236 [ 0 ] ;
V_228 = F_90 ( 1UL , F_91 ( V_226 , V_237 ) ) ;
F_7 ( L_52 ,
V_224 , V_228 , & V_49 -> V_212 [ 0 ] , V_226 ) ;
F_92 ( V_224 , V_228 , & V_49 -> V_212 [ 0 ] , V_226 ) ;
V_214 -> V_238 += V_226 ;
if ( V_214 -> V_238 == V_214 -> V_235 . V_239 ) {
F_93 ( & V_214 -> V_240 ) ;
V_214 -> V_241 |= V_242 ;
V_214 -> V_243 = V_244 ;
F_94 ( & V_214 -> V_240 ) ;
}
V_234:
V_229 = F_95 ( V_104 , V_214 , V_220 , V_222 -> V_202 ) ;
if ( ! V_229 && V_230 == false && V_227 )
F_96 ( V_214 ) ;
return 0 ;
}
static int
F_97 ( struct V_4 * V_4 ,
struct V_48 * V_49 , unsigned char * V_220 )
{
struct V_223 * V_245 ;
struct V_172 * V_104 = V_4 -> V_104 ;
struct V_213 * V_214 = NULL ;
struct V_246 * V_222 = (struct V_246 * ) V_220 ;
T_2 V_247 = F_98 ( V_222 -> V_248 ) ;
int V_229 , V_228 , V_249 , V_250 ;
V_229 = F_99 ( V_104 , V_220 , & V_214 ) ;
if ( V_229 < 0 )
return V_229 ;
else if ( ! V_214 )
return 0 ;
if ( ! V_214 -> V_233 ) {
F_2 ( L_53 ) ;
F_65 () ;
return - 1 ;
}
F_7 ( L_54 ,
V_247 , V_214 -> V_238 , V_214 -> V_235 . V_239 ) ;
V_249 = V_214 -> V_238 / V_237 ;
V_245 = & V_214 -> V_235 . V_236 [ V_249 ] ;
V_228 = F_90 ( 1UL , F_91 ( V_247 , V_237 ) ) ;
V_250 = V_214 -> V_238 % V_237 ;
if ( V_250 ) {
F_2 ( L_55 ) ;
F_65 () ;
return - 1 ;
}
F_7 ( L_56 ,
V_245 , V_249 , V_228 , & V_49 -> V_212 [ 0 ] , V_247 ) ;
F_92 ( V_245 , V_228 , & V_49 -> V_212 [ 0 ] ,
V_247 ) ;
V_229 = F_100 ( V_214 , V_222 , false ) ;
if ( V_229 < 0 )
return V_229 ;
return 0 ;
}
static int
F_101 ( struct V_4 * V_4 , struct V_162 * V_162 ,
struct V_48 * V_49 , unsigned char * V_220 )
{
struct V_213 * V_214 = & V_162 -> V_213 ;
struct V_172 * V_104 = V_4 -> V_104 ;
struct V_251 * V_222 = (struct V_251 * ) V_220 ;
int V_229 ;
V_229 = F_102 ( V_104 , V_214 , V_222 ) ;
if ( V_229 < 0 )
return V_229 ;
return F_103 ( V_104 , V_214 , V_222 ) ;
}
static int
F_104 ( struct V_4 * V_4 , struct V_162 * V_162 ,
struct V_48 * V_49 , struct V_252 * V_222 )
{
struct V_213 * V_214 = & V_162 -> V_213 ;
struct V_172 * V_104 = V_4 -> V_104 ;
T_2 V_253 = F_98 ( V_222 -> V_248 ) ;
int V_229 ;
unsigned char * V_254 ;
V_229 = F_105 ( V_104 , V_214 , V_222 ) ;
if ( V_229 < 0 )
return V_229 ;
V_254 = F_14 ( V_253 , V_56 ) ;
if ( ! V_254 ) {
F_2 ( L_57 ,
V_253 ) ;
return - V_66 ;
}
V_214 -> V_255 = V_254 ;
memcpy ( V_214 -> V_255 , & V_49 -> V_212 [ 0 ] , V_253 ) ;
return F_106 ( V_104 , V_214 , V_222 ) ;
}
static int
F_107 ( struct V_4 * V_4 , struct V_48 * V_49 ,
T_4 V_256 , T_5 V_257 ,
T_4 V_258 , T_5 V_259 )
{
struct V_178 * V_222 = & V_49 -> V_176 ;
struct V_172 * V_104 = V_4 -> V_104 ;
struct V_260 * V_261 = V_104 -> V_261 ;
struct V_213 * V_214 ;
struct V_162 * V_162 ;
int V_13 = - V_262 ;
T_6 V_158 = ( V_222 -> V_158 & V_263 ) ;
if ( V_261 -> V_264 -> V_265 &&
( ! ( V_158 & V_266 ) || ! ( V_158 & V_267 ) ) ) {
F_2 ( L_58
L_59 , V_158 ) ;
return 0 ;
}
switch ( V_158 ) {
case V_268 :
V_214 = F_108 ( V_104 , V_56 ) ;
if ( ! V_214 )
break;
V_162 = F_54 ( V_214 , struct V_162 , V_213 ) ;
V_162 -> V_256 = V_256 ;
V_162 -> V_257 = V_257 ;
V_162 -> V_258 = V_258 ;
V_162 -> V_259 = V_259 ;
V_13 = F_87 ( V_4 , V_162 ,
V_49 , ( unsigned char * ) V_222 ) ;
break;
case V_269 :
V_214 = F_108 ( V_104 , V_56 ) ;
if ( ! V_214 )
break;
V_162 = F_54 ( V_214 , struct V_162 , V_213 ) ;
V_13 = F_101 ( V_4 , V_162 ,
V_49 , ( unsigned char * ) V_222 ) ;
break;
case V_270 :
V_13 = F_97 ( V_4 , V_49 ,
( unsigned char * ) V_222 ) ;
break;
case V_271 :
V_214 = F_108 ( V_104 , V_56 ) ;
if ( ! V_214 )
break;
V_13 = F_109 ( V_104 , V_214 ,
( unsigned char * ) V_222 ) ;
break;
case V_267 :
V_214 = F_108 ( V_104 , V_56 ) ;
if ( ! V_214 )
break;
V_13 = F_110 ( V_104 , V_214 , ( unsigned char * ) V_222 ) ;
if ( V_13 > 0 )
F_111 ( & V_104 -> V_272 ,
V_273 *
V_274 ) ;
break;
case V_266 :
V_214 = F_108 ( V_104 , V_56 ) ;
if ( ! V_214 )
break;
V_162 = F_54 ( V_214 , struct V_162 , V_213 ) ;
V_13 = F_104 ( V_4 , V_162 ,
V_49 , (struct V_252 * ) V_222 ) ;
break;
default:
F_2 ( L_60 , V_158 ) ;
F_65 () ;
break;
}
return V_13 ;
}
static void
F_112 ( struct V_48 * V_49 , struct V_4 * V_4 )
{
struct V_164 * V_164 = & V_49 -> V_163 ;
T_5 V_257 = 0 , V_259 = 0 ;
T_4 V_256 = 0 , V_258 = 0 ;
int V_229 ;
switch ( V_164 -> V_165 & 0xF0 ) {
case V_275 :
if ( V_164 -> V_165 & V_276 ) {
V_256 = F_80 ( V_164 -> V_256 ) ;
V_257 = F_113 ( V_164 -> V_257 ) ;
F_7 ( L_61 ,
V_256 , ( unsigned long long ) V_257 ) ;
}
if ( V_164 -> V_165 & V_277 ) {
V_258 = F_80 ( V_164 -> V_258 ) ;
V_259 = F_113 ( V_164 -> V_259 ) ;
F_7 ( L_62 ,
V_258 , ( unsigned long long ) V_259 ) ;
}
F_7 ( L_63 ) ;
break;
case V_278 :
F_2 ( L_64 ) ;
break;
default:
F_4 ( L_65 , V_164 -> V_165 ) ;
break;
}
V_229 = F_107 ( V_4 , V_49 ,
V_256 , V_257 , V_258 , V_259 ) ;
}
static void
F_114 ( struct V_48 * V_279 , struct V_4 * V_4 ,
unsigned long V_280 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_178 * V_222 ;
T_1 V_281 ;
int V_186 , V_282 ;
if ( ( char * ) V_279 == V_4 -> V_110 ) {
V_281 = V_4 -> V_112 ;
V_186 = V_108 ;
F_7 ( L_66 ,
V_281 , V_186 ) ;
} else {
V_281 = V_279 -> V_52 ;
V_186 = V_58 ;
F_7 ( L_67 ,
V_281 , V_186 ) ;
}
F_74 ( V_10 , V_281 , V_186 , V_59 ) ;
V_222 = & V_279 -> V_176 ;
F_7 ( L_68 ,
V_222 -> V_158 , V_222 -> V_204 , V_222 -> V_165 ,
( int ) ( V_280 - V_156 ) ) ;
if ( ( char * ) V_279 == V_4 -> V_110 )
F_79 ( V_279 , V_280 - V_156 ,
V_4 ) ;
else
F_112 ( V_279 , V_4 ) ;
F_69 ( V_10 , V_281 , V_186 ,
V_59 ) ;
V_4 -> V_131 -- ;
F_7 ( L_69 ,
V_4 -> V_131 ) ;
if ( ( char * ) V_279 == V_4 -> V_110 )
return;
V_282 = V_4 -> V_131 ;
if ( V_282 + V_183 <= V_38 ) {
int V_283 , V_141 = F_23 ( V_38 - V_282 ,
V_183 ) ;
V_283 = F_66 ( V_4 , V_141 ) ;
if ( V_283 ) {
F_2 ( L_70 ,
V_141 , V_283 ) ;
}
}
}
static void
F_115 ( struct V_162 * V_162 , struct V_4 * V_4 )
{
struct V_284 * V_285 = & V_162 -> V_167 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
F_7 ( L_71 ) ;
if ( V_285 -> V_171 ) {
F_116 ( V_10 , V_285 -> V_171 , V_285 -> V_149 , V_115 ) ;
V_285 -> V_171 = NULL ;
}
F_18 ( V_285 -> V_154 ) ;
V_285 -> V_154 = NULL ;
F_18 ( V_162 -> V_50 ) ;
V_162 -> V_50 = NULL ;
}
static void
F_117 ( struct V_162 * V_162 )
{
struct V_213 * V_214 = & V_162 -> V_213 ;
struct V_4 * V_4 = V_162 -> V_104 ;
struct V_172 * V_104 = V_4 -> V_104 ;
F_7 ( L_72 , V_162 ) ;
switch ( V_214 -> V_286 ) {
case V_268 :
F_93 ( & V_104 -> V_287 ) ;
if ( ! F_118 ( & V_214 -> V_288 ) )
F_36 ( & V_214 -> V_288 ) ;
F_94 ( & V_104 -> V_287 ) ;
if ( V_214 -> V_289 == V_115 )
F_119 ( V_214 ) ;
F_115 ( V_162 , V_4 ) ;
F_120 ( & V_214 -> V_235 , 0 ) ;
break;
case V_271 :
F_93 ( & V_104 -> V_287 ) ;
if ( ! F_118 ( & V_214 -> V_288 ) )
F_36 ( & V_214 -> V_288 ) ;
F_94 ( & V_104 -> V_287 ) ;
F_120 ( & V_214 -> V_235 , 0 ) ;
break;
case V_290 :
case V_269 :
case V_266 :
F_93 ( & V_104 -> V_287 ) ;
if ( ! F_118 ( & V_214 -> V_288 ) )
F_36 ( & V_214 -> V_288 ) ;
F_94 ( & V_104 -> V_287 ) ;
if ( V_214 -> V_235 . V_291 != NULL ) {
F_7 ( L_73
L_74 ,
V_214 -> V_286 ) ;
F_120 ( & V_214 -> V_235 , 0 ) ;
break;
}
default:
F_83 ( V_214 ) ;
break;
}
}
static void
F_121 ( struct V_151 * V_152 , struct V_9 * V_10 )
{
if ( V_152 -> V_52 != 0 ) {
F_7 ( L_75 ) ;
F_17 ( V_10 , V_152 -> V_52 ,
V_156 , V_115 ) ;
V_152 -> V_52 = 0 ;
}
}
static void
F_122 ( struct V_151 * V_152 , struct V_162 * V_162 ,
struct V_9 * V_10 )
{
if ( V_162 -> V_292 != 0 ) {
F_7 ( L_76 ) ;
F_17 ( V_10 , V_162 -> V_292 ,
V_162 -> V_293 , V_115 ) ;
V_162 -> V_292 = 0 ;
}
F_121 ( V_152 , V_10 ) ;
F_117 ( V_162 ) ;
}
static void
F_123 ( struct V_151 * V_152 ,
struct V_162 * V_162 )
{
struct V_284 * V_285 = & V_162 -> V_167 ;
struct V_213 * V_214 = & V_162 -> V_213 ;
struct V_235 * V_235 = & V_214 -> V_235 ;
struct V_9 * V_10 = V_162 -> V_104 -> V_7 -> V_19 ;
F_119 ( V_214 ) ;
if ( V_285 -> V_171 ) {
F_7 ( L_77 ) ;
F_116 ( V_10 , V_285 -> V_171 , V_285 -> V_149 , V_115 ) ;
V_285 -> V_171 = NULL ;
}
if ( V_162 -> V_50 ) {
F_7 ( L_78 ) ;
F_18 ( V_162 -> V_50 ) ;
V_162 -> V_50 = NULL ;
}
V_214 -> V_238 = V_235 -> V_239 ;
F_7 ( L_79 ) ;
F_93 ( & V_214 -> V_240 ) ;
V_214 -> V_241 |= V_242 ;
V_214 -> V_243 = V_244 ;
F_94 ( & V_214 -> V_240 ) ;
F_124 ( V_235 ) ;
}
static void
F_125 ( struct V_127 * V_128 )
{
struct V_162 * V_162 = F_54 ( V_128 ,
struct V_162 , V_294 ) ;
struct V_4 * V_4 = V_162 -> V_104 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_213 * V_214 = & V_162 -> V_213 ;
switch ( V_214 -> V_243 ) {
case V_295 :
F_7 ( L_80 ) ;
F_72 ( & V_4 -> V_132 ) ;
F_126 ( V_214 , V_214 -> V_104 ) ;
V_214 -> V_243 = V_296 ;
F_122 ( & V_162 -> V_152 , V_162 , V_10 ) ;
break;
case V_297 :
F_7 ( L_81 ) ;
F_72 ( & V_4 -> V_132 ) ;
V_214 -> V_243 = V_296 ;
F_122 ( & V_162 -> V_152 , V_162 , V_10 ) ;
break;
case V_298 :
F_7 ( L_82 ) ;
V_4 -> V_133 = true ;
F_127 ( V_214 , V_214 -> V_104 ) ;
break;
case V_299 :
F_72 ( & V_4 -> V_132 ) ;
V_214 -> V_243 = V_296 ;
F_122 ( & V_162 -> V_152 , V_162 , V_10 ) ;
break;
default:
F_2 ( L_83 , V_214 -> V_243 ) ;
F_65 () ;
break;
}
}
static void
F_128 ( struct V_151 * V_152 ,
struct V_162 * V_162 ,
struct V_4 * V_4 ,
struct V_9 * V_10 )
{
struct V_213 * V_214 = & V_162 -> V_213 ;
if ( V_214 -> V_243 == V_295 ||
V_214 -> V_243 == V_298 ||
V_214 -> V_243 == V_297 ||
V_214 -> V_243 == V_299 ) {
F_121 ( V_152 , V_10 ) ;
F_62 ( & V_162 -> V_294 , F_125 ) ;
F_129 ( V_300 , & V_162 -> V_294 ) ;
return;
}
F_72 ( & V_4 -> V_132 ) ;
V_214 -> V_243 = V_296 ;
F_122 ( V_152 , V_162 , V_10 ) ;
}
static void
F_130 ( struct V_151 * V_152 ,
struct V_4 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_162 * V_162 = V_152 -> V_162 ;
struct V_284 * V_285 ;
if ( ! V_162 ) {
F_72 ( & V_4 -> V_132 ) ;
F_121 ( V_152 , V_10 ) ;
return;
}
V_285 = & V_162 -> V_167 ;
switch ( V_285 -> V_168 ) {
case V_301 :
F_2 ( L_84 ) ;
F_65 () ;
break;
case V_169 :
F_7 ( L_85 ) ;
F_128 ( V_152 , V_162 ,
V_4 , V_10 ) ;
break;
case V_302 :
F_2 ( L_86 ) ;
F_65 () ;
break;
case V_303 :
F_7 ( L_87 ) ;
F_72 ( & V_4 -> V_132 ) ;
F_123 ( V_152 , V_162 ) ;
break;
default:
F_2 ( L_88 , V_285 -> V_168 ) ;
F_65 () ;
break;
}
}
static void
F_131 ( struct V_151 * V_152 , struct V_4 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
if ( V_152 ) {
struct V_162 * V_162 = V_152 -> V_162 ;
if ( ! V_162 )
F_121 ( V_152 , V_10 ) ;
else
F_122 ( V_152 , V_162 , V_10 ) ;
}
if ( V_4 -> V_131 == 0 &&
F_58 ( & V_4 -> V_132 ) == 0 ) {
F_7 ( L_89 ) ;
F_7 ( L_90 ) ;
F_9 ( & V_4 -> V_101 ) ;
if ( V_4 -> V_94 != V_130 )
V_4 -> V_94 = V_304 ;
F_10 ( & V_4 -> V_101 ) ;
F_48 ( & V_4 -> V_99 ) ;
}
}
static void
F_132 ( struct V_127 * V_128 )
{
struct V_67 * V_68 = F_54 ( V_128 ,
struct V_67 , V_84 ) ;
struct V_18 * V_19 = V_68 -> V_19 ;
int V_74 = V_68 -> V_74 ;
struct V_305 * V_306 = V_19 -> V_31 [ V_74 ] ;
struct V_4 * V_4 ;
struct V_151 * V_152 ;
struct V_307 V_308 ;
while ( F_133 ( V_306 , 1 , & V_308 ) == 1 ) {
V_152 = (struct V_151 * ) ( unsigned long ) V_308 . V_147 ;
V_4 = V_308 . V_47 -> V_29 ;
if ( V_308 . V_134 == V_309 ) {
F_130 ( V_152 , V_4 ) ;
} else {
F_7 ( L_91 ) ;
F_7 ( L_92 , V_308 . V_134 ) ;
F_7 ( L_93 , V_308 . V_310 ) ;
F_72 ( & V_4 -> V_132 ) ;
F_131 ( V_152 , V_4 ) ;
}
}
F_28 ( V_306 , V_80 ) ;
}
static void
V_78 ( struct V_305 * V_311 , void * V_3 )
{
struct V_67 * V_68 = (struct V_67 * ) V_3 ;
F_62 ( & V_68 -> V_84 , F_132 ) ;
F_129 ( V_300 , & V_68 -> V_84 ) ;
}
static void
F_134 ( struct V_127 * V_128 )
{
struct V_67 * V_68 = F_54 ( V_128 ,
struct V_67 , V_83 ) ;
struct V_18 * V_19 = V_68 -> V_19 ;
int V_74 = V_68 -> V_74 ;
struct V_305 * V_312 = V_19 -> V_33 [ V_74 ] ;
struct V_4 * V_4 ;
struct V_48 * V_49 ;
struct V_307 V_308 ;
unsigned long V_280 ;
while ( F_133 ( V_312 , 1 , & V_308 ) == 1 ) {
V_49 = (struct V_48 * ) ( unsigned long ) V_308 . V_147 ;
V_4 = V_308 . V_47 -> V_29 ;
if ( V_308 . V_134 == V_309 ) {
V_280 = ( unsigned long ) V_308 . V_313 ;
F_114 ( V_49 , V_4 , V_280 ) ;
} else {
F_7 ( L_94 ) ;
if ( V_308 . V_134 != V_314 ) {
F_7 ( L_95 , V_308 . V_134 ) ;
F_7 ( L_96 ,
V_308 . V_310 ) ;
}
V_4 -> V_131 -- ;
F_131 ( NULL , V_4 ) ;
}
}
F_28 ( V_312 , V_80 ) ;
}
static void
V_75 ( struct V_305 * V_311 , void * V_3 )
{
struct V_67 * V_68 = (struct V_67 * ) V_3 ;
F_62 ( & V_68 -> V_83 , F_134 ) ;
F_129 ( V_315 , & V_68 -> V_83 ) ;
}
static int
F_135 ( struct V_4 * V_4 , struct V_162 * V_162 )
{
struct V_153 * V_316 ;
int V_13 ;
F_70 ( & V_4 -> V_132 ) ;
V_13 = F_71 ( V_4 -> V_46 , & V_162 -> V_152 . V_154 ,
& V_316 ) ;
if ( V_13 ) {
F_2 ( L_97 , V_13 ) ;
F_72 ( & V_4 -> V_132 ) ;
return V_13 ;
}
return V_13 ;
}
static int
F_136 ( struct V_172 * V_104 , struct V_213 * V_214 )
{
struct V_162 * V_162 = F_54 ( V_214 ,
struct V_162 , V_213 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_104 -> V_3 ;
struct V_153 * V_154 = & V_162 -> V_152 . V_154 ;
struct V_317 * V_222 = (struct V_317 * )
& V_162 -> V_152 . V_176 ;
F_73 ( V_4 , V_162 , & V_162 -> V_152 ) ;
F_137 ( V_214 , V_104 , true , V_222 ) ;
F_75 ( V_4 , & V_162 -> V_152 ) ;
if ( V_214 -> V_235 . V_318 &&
( ( V_214 -> V_235 . V_319 & V_320 ) ||
( V_214 -> V_235 . V_319 & V_321 ) ) ) {
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_50 * V_179 = & V_162 -> V_152 . V_157 [ 1 ] ;
T_2 V_322 , V_323 ;
F_138 ( V_214 -> V_235 . V_324 ,
V_214 -> V_318 ) ;
V_214 -> V_235 . V_324 += sizeof( V_325 ) ;
V_322 = - ( V_214 -> V_235 . V_324 ) & 3 ;
F_139 ( V_222 -> V_248 , ( T_2 ) V_214 -> V_235 . V_324 ) ;
V_323 = V_214 -> V_235 . V_324 + V_322 ;
V_162 -> V_292 = F_15 ( V_10 ,
( void * ) V_214 -> V_318 , V_323 ,
V_115 ) ;
V_162 -> V_293 = V_323 ;
V_179 -> V_61 = V_162 -> V_292 ;
V_179 -> V_62 = V_323 ;
V_179 -> V_63 = V_4 -> V_64 -> V_63 ;
V_162 -> V_152 . V_149 = 2 ;
}
F_76 ( V_162 , V_154 ) ;
F_7 ( L_98 ) ;
return F_135 ( V_4 , V_162 ) ;
}
static int
F_140 ( struct V_213 * V_214 , struct V_172 * V_104 ,
bool V_326 )
{
struct V_162 * V_162 = F_54 ( V_214 ,
struct V_162 , V_213 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_104 -> V_3 ;
struct V_153 * V_154 = & V_162 -> V_152 . V_154 ;
F_73 ( V_4 , V_162 , & V_162 -> V_152 ) ;
F_141 ( V_214 , V_104 , (struct V_327 * )
& V_162 -> V_152 . V_176 ,
V_326 ) ;
F_75 ( V_4 , & V_162 -> V_152 ) ;
F_76 ( V_162 , V_154 ) ;
F_7 ( L_99 ) ;
return F_135 ( V_4 , V_162 ) ;
}
static int
F_142 ( struct V_213 * V_214 , struct V_172 * V_104 )
{
struct V_162 * V_162 = F_54 ( V_214 ,
struct V_162 , V_213 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_104 -> V_3 ;
struct V_153 * V_154 = & V_162 -> V_152 . V_154 ;
F_73 ( V_4 , V_162 , & V_162 -> V_152 ) ;
F_143 ( V_214 , V_104 , (struct V_328 * )
& V_162 -> V_152 . V_176 ) ;
F_75 ( V_4 , & V_162 -> V_152 ) ;
F_76 ( V_162 , V_154 ) ;
F_7 ( L_100 ) ;
return F_135 ( V_4 , V_162 ) ;
}
static int
F_144 ( struct V_213 * V_214 , struct V_172 * V_104 )
{
struct V_162 * V_162 = F_54 ( V_214 ,
struct V_162 , V_213 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_104 -> V_3 ;
struct V_153 * V_154 = & V_162 -> V_152 . V_154 ;
F_73 ( V_4 , V_162 , & V_162 -> V_152 ) ;
F_145 ( V_214 , V_104 , (struct V_329 * )
& V_162 -> V_152 . V_176 ) ;
F_75 ( V_4 , & V_162 -> V_152 ) ;
F_76 ( V_162 , V_154 ) ;
F_7 ( L_101 ) ;
return F_135 ( V_4 , V_162 ) ;
}
static int
F_146 ( struct V_213 * V_214 , struct V_172 * V_104 )
{
struct V_162 * V_162 = F_54 ( V_214 ,
struct V_162 , V_213 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_104 -> V_3 ;
struct V_153 * V_154 = & V_162 -> V_152 . V_154 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_50 * V_179 = & V_162 -> V_152 . V_157 [ 1 ] ;
struct V_330 * V_222 =
(struct V_330 * ) & V_162 -> V_152 . V_176 ;
F_73 ( V_4 , V_162 , & V_162 -> V_152 ) ;
F_147 ( V_214 , V_104 , V_222 ) ;
F_75 ( V_4 , & V_162 -> V_152 ) ;
F_139 ( V_222 -> V_248 , V_209 ) ;
V_162 -> V_292 = F_15 ( V_10 ,
( void * ) V_214 -> V_215 , V_209 ,
V_115 ) ;
V_162 -> V_293 = V_209 ;
V_179 -> V_61 = V_162 -> V_292 ;
V_179 -> V_62 = V_209 ;
V_179 -> V_63 = V_4 -> V_64 -> V_63 ;
V_162 -> V_152 . V_149 = 2 ;
F_76 ( V_162 , V_154 ) ;
F_7 ( L_102 ) ;
return F_135 ( V_4 , V_162 ) ;
}
static int
F_148 ( struct V_213 * V_214 , struct V_172 * V_104 )
{
struct V_162 * V_162 = F_54 ( V_214 ,
struct V_162 , V_213 ) ;
struct V_4 * V_4 = (struct V_4 * ) V_104 -> V_3 ;
struct V_153 * V_154 = & V_162 -> V_152 . V_154 ;
struct V_331 * V_222 =
(struct V_331 * ) & V_162 -> V_152 . V_176 ;
T_2 V_332 ;
int V_229 ;
F_73 ( V_4 , V_162 , & V_162 -> V_152 ) ;
V_229 = F_149 ( V_214 , V_104 , V_222 ) ;
if ( V_229 < 0 )
return V_229 ;
V_332 = V_229 ;
F_75 ( V_4 , & V_162 -> V_152 ) ;
if ( V_332 ) {
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_50 * V_179 = & V_162 -> V_152 . V_157 [ 1 ] ;
void * V_333 = V_214 -> V_215 ;
V_162 -> V_292 = F_15 ( V_10 ,
V_333 , V_332 , V_115 ) ;
V_162 -> V_293 = V_332 ;
V_179 -> V_61 = V_162 -> V_292 ;
V_179 -> V_62 = V_332 ;
V_179 -> V_63 = V_4 -> V_64 -> V_63 ;
V_162 -> V_152 . V_149 = 2 ;
}
F_76 ( V_162 , V_154 ) ;
F_7 ( L_103 ) ;
return F_135 ( V_4 , V_162 ) ;
}
static int
F_150 ( struct V_4 * V_4 , struct V_162 * V_162 ,
struct V_50 * V_50 , struct V_153 * V_154 ,
T_2 V_334 , T_2 V_335 )
{
struct V_213 * V_214 = & V_162 -> V_213 ;
struct V_223 * V_245 , * V_336 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
T_2 V_249 , V_250 ;
int V_53 = 0 , V_228 ;
V_249 = V_335 / V_237 ;
V_245 = & V_214 -> V_235 . V_236 [ V_249 ] ;
V_228 = F_23 ( V_214 -> V_235 . V_337 - V_249 , V_4 -> V_14 ) ;
V_250 = V_335 % V_237 ;
V_154 -> V_148 = V_50 ;
V_154 -> V_149 = V_228 ;
V_154 -> V_147 = ( unsigned long ) & V_162 -> V_152 ;
F_151 (sg_start, tmp_sg, sg_nents, i) {
F_7 ( L_104 ,
( unsigned long long ) V_336 -> V_338 ,
V_336 -> V_62 , V_250 ) ;
V_50 -> V_61 = F_152 ( V_10 , V_336 ) + V_250 ;
V_50 -> V_62 = F_21 ( T_2 , V_334 ,
F_153 ( V_10 , V_336 ) - V_250 ) ;
V_50 -> V_63 = V_4 -> V_64 -> V_63 ;
F_7 ( L_105 ,
V_50 -> V_61 , V_50 -> V_62 ) ;
V_250 = 0 ;
V_334 -= V_50 -> V_62 ;
V_50 ++ ;
F_7 ( L_106 , V_50 ) ;
}
F_7 ( L_107 ,
V_154 -> V_148 , V_154 -> V_149 ) ;
return V_228 ;
}
static int
F_154 ( struct V_172 * V_104 , struct V_213 * V_214 )
{
struct V_235 * V_235 = & V_214 -> V_235 ;
struct V_162 * V_162 = F_54 ( V_214 ,
struct V_162 , V_213 ) ;
struct V_284 * V_285 = & V_162 -> V_167 ;
struct V_4 * V_4 = (struct V_4 * ) V_104 -> V_3 ;
struct V_153 * V_316 , * V_154 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_50 * V_50 ;
struct V_223 * V_224 ;
T_2 V_335 = 0 , V_339 , V_334 , V_340 ;
int V_229 , V_13 = 0 , V_141 , V_228 , V_53 , V_341 ;
F_7 ( L_108 , V_235 -> V_239 ) ;
V_224 = & V_235 -> V_236 [ 0 ] ;
V_228 = V_235 -> V_337 ;
V_141 = F_155 ( V_10 , V_224 , V_228 , V_115 ) ;
if ( F_156 ( ! V_141 ) ) {
F_2 ( L_109 ) ;
return - V_262 ;
}
V_285 -> V_171 = V_224 ;
V_285 -> V_149 = V_228 ;
F_7 ( L_110 ,
V_141 , V_224 , V_228 ) ;
V_50 = F_14 ( sizeof( struct V_50 ) * V_228 , V_56 ) ;
if ( ! V_50 ) {
F_4 ( L_111 ) ;
V_13 = - V_66 ;
goto V_342;
}
V_162 -> V_50 = V_50 ;
F_7 ( L_112 ,
V_50 , V_235 -> V_337 ) ;
V_285 -> V_343 = F_91 ( V_228 , V_4 -> V_14 ) ;
V_285 -> V_154 = F_14 ( sizeof( struct V_153 ) * V_285 -> V_343 ,
V_56 ) ;
if ( ! V_285 -> V_154 ) {
F_2 ( L_113 ) ;
V_13 = - V_66 ;
goto V_342;
}
F_7 ( L_114 ,
V_285 -> V_154 , V_285 -> V_343 ) ;
F_157 ( V_214 , V_104 -> V_261 ) ;
V_214 -> V_344 = V_104 -> V_344 ++ ;
V_285 -> V_162 = V_162 ;
V_340 = V_4 -> V_14 * V_237 ;
V_334 = V_235 -> V_239 ;
for ( V_53 = 0 ; V_53 < V_285 -> V_343 ; V_53 ++ ) {
V_154 = & V_162 -> V_167 . V_154 [ V_53 ] ;
V_339 = F_23 ( V_334 , V_340 ) ;
V_154 -> V_158 = V_345 ;
V_154 -> V_160 = 0 ;
V_154 -> V_285 . V_346 . V_347 = V_162 -> V_257 + V_335 ;
V_154 -> V_285 . V_346 . V_348 = V_162 -> V_256 ;
V_341 = F_150 ( V_4 , V_162 , V_50 ,
V_154 , V_339 , V_335 ) ;
V_50 += V_341 ;
if ( V_53 + 1 == V_285 -> V_343 )
V_154 -> V_150 = & V_162 -> V_152 . V_154 ;
else
V_154 -> V_150 = & V_285 -> V_154 [ V_53 + 1 ] ;
V_335 += V_339 ;
V_334 -= V_339 ;
}
F_73 ( V_4 , V_162 , & V_162 -> V_152 ) ;
F_137 ( V_214 , V_104 , false , (struct V_317 * )
& V_162 -> V_152 . V_176 ) ;
F_75 ( V_4 , & V_162 -> V_152 ) ;
F_76 ( V_162 , & V_162 -> V_152 . V_154 ) ;
F_70 ( & V_4 -> V_132 ) ;
V_229 = F_71 ( V_4 -> V_46 , V_285 -> V_154 , & V_316 ) ;
if ( V_229 ) {
F_4 ( L_115 ) ;
F_72 ( & V_4 -> V_132 ) ;
}
F_7 ( L_116 ) ;
return 1 ;
V_342:
F_116 ( V_10 , V_224 , V_228 , V_115 ) ;
return V_13 ;
}
static int
F_158 ( struct V_172 * V_104 , struct V_213 * V_214 , bool V_349 )
{
struct V_235 * V_235 = & V_214 -> V_235 ;
struct V_162 * V_162 = F_54 ( V_214 ,
struct V_162 , V_213 ) ;
struct V_284 * V_285 = & V_162 -> V_167 ;
struct V_4 * V_4 = (struct V_4 * ) V_104 -> V_3 ;
struct V_153 * V_316 , * V_154 ;
struct V_50 * V_50 ;
struct V_9 * V_10 = V_4 -> V_7 -> V_19 ;
struct V_223 * V_245 ;
T_2 V_249 , V_228 , V_250 , V_350 = 0 ;
T_2 V_335 = 0 , V_339 , V_334 , V_340 ;
int V_229 , V_13 = 0 , V_141 , V_53 , V_341 ;
F_7 ( L_117 ,
V_235 -> V_239 , V_214 -> V_238 ) ;
V_249 = V_214 -> V_238 / V_237 ;
V_245 = & V_214 -> V_235 . V_236 [ V_249 ] ;
V_250 = V_214 -> V_238 % V_237 ;
F_7 ( L_118 ,
V_249 , V_245 , V_250 ) ;
V_334 = V_235 -> V_239 - V_214 -> V_238 ;
V_228 = V_235 -> V_337 - V_249 ;
F_7 ( L_119 ,
V_334 , V_228 ) ;
V_141 = F_155 ( V_10 , V_245 , V_228 , V_59 ) ;
if ( F_156 ( ! V_141 ) ) {
F_2 ( L_120 ) ;
return - V_262 ;
}
V_285 -> V_171 = V_245 ;
V_285 -> V_149 = V_228 ;
F_7 ( L_121 ,
V_141 , V_245 , V_228 ) ;
V_50 = F_14 ( sizeof( struct V_50 ) * V_228 , V_56 ) ;
if ( ! V_50 ) {
F_4 ( L_122 ) ;
V_13 = - V_66 ;
goto V_342;
}
V_162 -> V_50 = V_50 ;
F_7 ( L_123 ,
V_50 , V_228 ) ;
V_285 -> V_343 = F_91 ( V_228 , V_4 -> V_14 ) ;
V_285 -> V_154 = F_14 ( sizeof( struct V_153 ) * V_285 -> V_343 ,
V_56 ) ;
if ( ! V_285 -> V_154 ) {
F_7 ( L_113 ) ;
V_13 = - V_66 ;
goto V_342;
}
F_7 ( L_114 ,
V_285 -> V_154 , V_285 -> V_343 ) ;
V_162 -> V_152 . V_162 = V_162 ;
V_285 -> V_168 = V_303 ;
V_285 -> V_162 = V_162 ;
V_340 = V_4 -> V_14 * V_237 ;
V_335 = V_214 -> V_238 ;
for ( V_53 = 0 ; V_53 < V_285 -> V_343 ; V_53 ++ ) {
V_154 = & V_162 -> V_167 . V_154 [ V_53 ] ;
V_339 = F_23 ( V_334 , V_340 ) ;
V_154 -> V_158 = V_351 ;
V_154 -> V_285 . V_346 . V_347 = V_162 -> V_259 + V_350 ;
V_154 -> V_285 . V_346 . V_348 = V_162 -> V_258 ;
V_341 = F_150 ( V_4 , V_162 , V_50 ,
V_154 , V_339 , V_335 ) ;
V_50 += V_341 ;
if ( V_53 + 1 == V_285 -> V_343 )
V_154 -> V_160 = V_161 ;
else
V_154 -> V_150 = & V_285 -> V_154 [ V_53 + 1 ] ;
V_335 += V_339 ;
V_350 += V_339 ;
V_334 -= V_339 ;
}
F_70 ( & V_4 -> V_132 ) ;
V_229 = F_71 ( V_4 -> V_46 , V_285 -> V_154 , & V_316 ) ;
if ( V_229 ) {
F_4 ( L_124 ) ;
F_72 ( & V_4 -> V_132 ) ;
}
F_7 ( L_125 ) ;
return 0 ;
V_342:
F_116 ( V_10 , V_245 , V_228 , V_59 ) ;
return V_13 ;
}
static int
F_159 ( struct V_172 * V_104 , struct V_213 * V_214 , int V_94 )
{
int V_13 ;
switch ( V_94 ) {
case V_352 :
V_13 = F_140 ( V_214 , V_104 , false ) ;
break;
default:
F_2 ( L_126 , V_94 ) ;
V_13 = - V_262 ;
break;
}
return V_13 ;
}
static int
F_160 ( struct V_172 * V_104 , struct V_213 * V_214 , int V_94 )
{
int V_13 ;
switch ( V_94 ) {
case V_298 :
V_13 = F_142 ( V_214 , V_104 ) ;
if ( ! V_13 ) {
F_7 ( L_127 ) ;
V_13 = - V_353 ;
}
break;
case V_354 :
V_13 = F_140 ( V_214 , V_104 , true ) ;
break;
case V_295 :
V_13 = F_144 ( V_214 , V_104 ) ;
break;
case V_297 :
V_13 = F_146 ( V_214 , V_104 ) ;
break;
case V_299 :
V_13 = F_148 ( V_214 , V_104 ) ;
break;
case V_355 :
V_13 = F_136 ( V_104 , V_214 ) ;
break;
default:
F_2 ( L_128 , V_94 ) ;
V_13 = - V_262 ;
break;
}
return V_13 ;
}
static int
F_161 ( struct V_90 * V_91 ,
struct V_356 * V_357 )
{
struct V_92 * V_92 ;
struct V_16 * V_358 ;
struct V_359 * V_360 ;
int V_13 ;
V_92 = F_14 ( sizeof( struct V_92 ) , V_56 ) ;
if ( ! V_92 ) {
F_2 ( L_129 ) ;
return - V_66 ;
}
F_44 ( & V_92 -> V_121 ) ;
F_47 ( & V_92 -> V_119 ) ;
F_40 ( & V_92 -> V_120 ) ;
F_43 ( & V_92 -> V_361 ) ;
V_360 = (struct V_359 * ) V_357 ;
F_7 ( L_130 , V_357 , V_360 ) ;
memcpy ( & V_91 -> V_362 , V_357 ,
sizeof( struct V_356 ) ) ;
V_358 = F_162 ( F_64 , V_91 , V_363 ,
V_44 ) ;
if ( F_25 ( V_358 ) ) {
F_2 ( L_131 ,
F_26 ( V_358 ) ) ;
V_13 = F_26 ( V_358 ) ;
goto V_109;
}
V_13 = F_163 ( V_358 , V_360 ) ;
if ( V_13 ) {
F_2 ( L_132 , V_13 ) ;
goto V_364;
}
V_13 = F_164 ( V_358 , V_365 ) ;
if ( V_13 ) {
F_2 ( L_133 , V_13 ) ;
goto V_364;
}
V_92 -> V_366 = V_358 ;
V_91 -> V_93 = V_92 ;
F_7 ( L_134 , V_358 -> V_3 ) ;
return 0 ;
V_364:
F_51 ( V_358 ) ;
V_109:
F_18 ( V_92 ) ;
return V_13 ;
}
static int
F_165 ( struct V_92 * V_92 )
{
int V_367 ;
F_9 ( & V_92 -> V_119 ) ;
V_367 = F_118 ( & V_92 -> V_120 ) ;
F_10 ( & V_92 -> V_119 ) ;
return V_367 ;
}
static int
F_166 ( struct V_4 * V_4 )
{
struct V_16 * V_368 = V_4 -> V_7 ;
struct V_369 V_370 ;
int V_13 ;
memset ( & V_370 , 0 , sizeof( struct V_369 ) ) ;
V_370 . V_102 = V_4 -> V_102 ;
V_370 . V_105 = V_4 -> V_105 ;
V_370 . V_371 = 7 ;
V_370 . V_372 = 7 ;
F_7 ( L_135 ) ;
V_13 = F_167 ( V_368 , & V_370 ) ;
if ( V_13 ) {
F_2 ( L_136 , V_13 ) ;
return V_13 ;
}
F_7 ( L_137 ) ;
return 0 ;
}
static int
F_168 ( struct V_172 * V_104 , struct V_173 * V_174 )
{
struct V_4 * V_4 = (struct V_4 * ) V_104 -> V_3 ;
int V_13 ;
F_7 ( L_138 , V_104 ) ;
V_13 = F_169 ( & V_4 -> V_97 ) ;
if ( V_13 )
return V_13 ;
F_7 ( L_139 , V_174 -> V_208 ) ;
return 0 ;
}
static void
F_170 ( struct V_90 * V_91 , struct V_172 * V_104 ,
struct V_4 * V_4 )
{
struct V_16 * V_368 = V_4 -> V_7 ;
struct V_373 * V_374 = & V_368 -> V_375 ;
struct V_376 * V_377 ;
struct V_378 * V_379 ;
V_104 -> V_380 = V_91 -> V_362 . V_381 ;
if ( V_91 -> V_362 . V_381 == V_382 ) {
V_379 = (struct V_378 * ) & V_374 -> V_61 . V_383 ;
snprintf ( V_104 -> V_384 , sizeof( V_104 -> V_384 ) , L_140 ,
& V_379 -> V_385 . V_386 ) ;
V_104 -> V_387 = F_171 ( V_379 -> V_388 ) ;
V_379 = (struct V_378 * ) & V_374 -> V_61 . V_389 ;
snprintf ( V_104 -> V_390 , sizeof( V_104 -> V_390 ) , L_140 ,
& V_379 -> V_385 . V_386 ) ;
V_104 -> V_391 = F_171 ( V_379 -> V_388 ) ;
} else {
V_377 = (struct V_376 * ) & V_374 -> V_61 . V_383 ;
sprintf ( V_104 -> V_384 , L_141 ,
& V_377 -> V_392 . V_393 ) ;
V_104 -> V_387 = F_171 ( V_377 -> V_394 ) ;
V_377 = (struct V_376 * ) & V_374 -> V_61 . V_389 ;
sprintf ( V_104 -> V_390 , L_141 ,
& V_377 -> V_392 . V_393 ) ;
V_104 -> V_391 = F_171 ( V_377 -> V_394 ) ;
}
}
static int
F_172 ( struct V_90 * V_91 , struct V_172 * V_104 )
{
struct V_92 * V_92 = (struct V_92 * ) V_91 -> V_93 ;
struct V_4 * V_4 ;
int V_395 = 0 , V_13 ;
V_396:
V_13 = F_173 ( V_92 -> V_121 ,
! F_165 ( V_92 ) ||
V_91 -> V_397 == V_398 ) ;
if ( V_395 > 5 )
return - V_399 ;
F_93 ( & V_91 -> V_400 ) ;
if ( V_91 -> V_397 == V_398 ) {
F_94 ( & V_91 -> V_400 ) ;
F_2 ( L_142 ) ;
return - V_399 ;
}
F_94 ( & V_91 -> V_400 ) ;
F_9 ( & V_92 -> V_119 ) ;
if ( F_118 ( & V_92 -> V_120 ) ) {
F_10 ( & V_92 -> V_119 ) ;
V_395 ++ ;
goto V_396;
}
V_4 = F_174 ( & V_92 -> V_120 ,
struct V_4 , V_96 ) ;
F_175 ( & V_4 -> V_96 ) ;
F_10 ( & V_92 -> V_119 ) ;
V_104 -> V_3 = V_4 ;
V_4 -> V_104 = V_104 ;
V_395 = 0 ;
V_13 = F_77 ( V_4 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_166 ( V_4 ) ;
if ( V_13 )
return V_13 ;
F_170 ( V_91 , V_104 , V_4 ) ;
F_7 ( L_143 , V_4 ) ;
return 0 ;
}
static void
F_176 ( struct V_90 * V_91 )
{
struct V_92 * V_92 = (struct V_92 * ) V_91 -> V_93 ;
F_51 ( V_92 -> V_366 ) ;
V_91 -> V_93 = NULL ;
F_18 ( V_92 ) ;
}
static int F_177 ( struct V_4 * V_4 , int V_94 )
{
int V_13 ;
F_9 ( & V_4 -> V_101 ) ;
V_13 = ( V_4 -> V_94 == V_94 ) ;
F_10 ( & V_4 -> V_101 ) ;
return V_13 ;
}
static void F_178 ( struct V_172 * V_104 )
{
struct V_4 * V_4 = V_104 -> V_3 ;
F_7 ( L_144 ) ;
F_9 ( & V_4 -> V_101 ) ;
if ( V_4 -> V_133 )
F_72 ( & V_4 -> V_132 ) ;
if ( V_4 -> V_7 && V_4 -> V_94 != V_130 ) {
F_7 ( L_145 ) ;
F_59 ( V_4 -> V_7 ) ;
}
if ( V_4 -> V_94 == V_184 ) {
F_7 ( L_146 ,
V_4 -> V_94 ) ;
F_10 ( & V_4 -> V_101 ) ;
F_179 ( V_4 -> V_99 ,
( F_177 ( V_4 , V_304 ) ) ) ;
F_179 ( V_4 -> V_98 ,
( F_177 ( V_4 , V_130 ) ) ) ;
F_55 ( V_4 ) ;
return;
}
if ( V_4 -> V_94 == V_95 ) {
F_10 ( & V_4 -> V_101 ) ;
F_55 ( V_4 ) ;
return;
}
F_7 ( L_147 ,
V_4 -> V_94 ) ;
F_10 ( & V_4 -> V_101 ) ;
F_179 ( V_4 -> V_98 ,
( F_177 ( V_4 , V_130 ) ) ) ;
F_55 ( V_4 ) ;
}
static int T_7 F_180 ( void )
{
int V_13 ;
V_315 = F_181 ( L_148 , 0 , 0 ) ;
if ( ! V_315 ) {
F_2 ( L_149 ) ;
return - V_66 ;
}
V_300 = F_181 ( L_150 , 0 , 0 ) ;
if ( ! V_300 ) {
F_2 ( L_151 ) ;
V_13 = - V_66 ;
goto V_401;
}
V_217 = F_182 ( L_152 ,
sizeof( struct V_162 ) , F_183 ( struct V_162 ) ,
0 , NULL ) ;
if ( ! V_217 ) {
F_2 ( L_153 ) ;
V_13 = - V_66 ;
goto V_402;
}
F_184 ( & V_403 ) ;
F_7 ( L_154 ) ;
return 0 ;
V_402:
F_185 ( V_300 ) ;
V_401:
F_185 ( V_315 ) ;
return V_13 ;
}
static void T_8 F_186 ( void )
{
F_187 ( V_217 ) ;
F_185 ( V_300 ) ;
F_185 ( V_315 ) ;
F_188 ( & V_403 ) ;
F_7 ( L_155 ) ;
}
