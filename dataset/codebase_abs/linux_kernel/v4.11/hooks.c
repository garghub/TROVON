static int T_1 F_1 ( char * V_1 )
{
unsigned long V_2 ;
if ( ! F_2 ( V_1 , 0 , & V_2 ) )
V_3 = V_2 ? 1 : 0 ;
return 1 ;
}
static int T_1 F_3 ( char * V_1 )
{
unsigned long V_4 ;
if ( ! F_2 ( V_1 , 0 , & V_4 ) )
V_5 = V_4 ? 1 : 0 ;
return 1 ;
}
static int F_4 ( void )
{
return ( V_6 || F_5 ( & V_7 ) ) ;
}
static int F_6 ( void )
{
return ( V_6 || F_7 () || F_8 () ) ;
}
static int F_9 ( T_2 V_8 )
{
if ( V_8 == V_9 ) {
F_10 () ;
F_11 () ;
F_12 () ;
F_13 () ;
}
return 0 ;
}
static void F_14 ( void )
{
struct V_10 * V_10 = (struct V_10 * ) V_11 -> V_12 ;
struct V_13 * V_14 ;
V_14 = F_15 ( sizeof( struct V_13 ) , V_15 ) ;
if ( ! V_14 )
F_16 ( L_1 ) ;
V_14 -> V_16 = V_14 -> V_17 = V_18 ;
V_10 -> V_19 = V_14 ;
}
static inline T_2 F_17 ( const struct V_10 * V_10 )
{
const struct V_13 * V_14 ;
V_14 = V_10 -> V_19 ;
return V_14 -> V_17 ;
}
static inline T_2 F_18 ( const struct V_20 * V_21 )
{
T_2 V_17 ;
F_19 () ;
V_17 = F_17 ( F_20 ( V_21 ) ) ;
F_21 () ;
return V_17 ;
}
static int F_22 ( struct V_22 * V_22 )
{
struct V_23 * V_24 ;
T_2 V_17 = F_23 () ;
V_24 = F_24 ( V_25 , V_26 ) ;
if ( ! V_24 )
return - V_27 ;
F_25 ( & V_24 -> V_28 ) ;
F_26 ( & V_24 -> V_29 ) ;
V_24 -> V_22 = V_22 ;
V_24 -> V_17 = V_30 ;
V_24 -> V_31 = V_32 ;
V_24 -> F_18 = V_17 ;
V_24 -> V_33 = V_34 ;
V_22 -> V_35 = V_24 ;
return 0 ;
}
static int F_27 ( struct V_22 * V_22 ,
struct V_36 * V_37 ,
bool V_38 )
{
struct V_23 * V_24 = V_22 -> V_35 ;
F_28 ( V_38 ) ;
if ( V_39 && V_24 -> V_33 != V_40 ) {
if ( ! V_38 )
return - V_41 ;
F_29 ( V_22 , V_37 ) ;
}
return 0 ;
}
static struct V_23 * F_30 ( struct V_22 * V_22 )
{
return V_22 -> V_35 ;
}
static struct V_23 * F_31 ( struct V_22 * V_22 , bool V_42 )
{
int error ;
error = F_27 ( V_22 , NULL , ! V_42 ) ;
if ( error )
return F_32 ( error ) ;
return V_22 -> V_35 ;
}
static struct V_23 * F_33 ( struct V_22 * V_22 )
{
F_27 ( V_22 , NULL , true ) ;
return V_22 -> V_35 ;
}
static struct V_23 * F_34 ( struct V_36 * V_36 )
{
struct V_22 * V_22 = F_35 ( V_36 ) ;
return V_22 -> V_35 ;
}
static struct V_23 * F_36 ( struct V_36 * V_36 )
{
struct V_22 * V_22 = F_35 ( V_36 ) ;
F_27 ( V_22 , V_36 , true ) ;
return V_22 -> V_35 ;
}
static void F_37 ( struct V_43 * V_44 )
{
struct V_23 * V_24 ;
V_24 = F_38 ( V_44 , struct V_23 , V_42 ) ;
F_39 ( V_25 , V_24 ) ;
}
static void F_40 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_35 ;
struct V_45 * V_46 = V_22 -> V_47 -> V_48 ;
if ( ! F_41 ( & V_24 -> V_29 ) ) {
F_42 ( & V_46 -> V_49 ) ;
F_43 ( & V_24 -> V_29 ) ;
F_44 ( & V_46 -> V_49 ) ;
}
F_45 ( & V_24 -> V_42 , F_37 ) ;
}
static int F_46 ( struct V_50 * V_50 )
{
struct V_51 * V_52 ;
T_2 V_17 = F_23 () ;
V_52 = F_24 ( V_53 , V_15 ) ;
if ( ! V_52 )
return - V_27 ;
V_52 -> V_17 = V_17 ;
V_52 -> V_54 = V_17 ;
V_50 -> V_55 = V_52 ;
return 0 ;
}
static void F_47 ( struct V_50 * V_50 )
{
struct V_51 * V_52 = V_50 -> V_55 ;
V_50 -> V_55 = NULL ;
F_39 ( V_53 , V_52 ) ;
}
static int F_48 ( struct V_56 * V_57 )
{
struct V_45 * V_46 ;
V_46 = F_15 ( sizeof( struct V_45 ) , V_15 ) ;
if ( ! V_46 )
return - V_27 ;
F_49 ( & V_46 -> V_28 ) ;
F_26 ( & V_46 -> V_58 ) ;
F_25 ( & V_46 -> V_49 ) ;
V_46 -> V_57 = V_57 ;
V_46 -> V_17 = V_30 ;
V_46 -> V_59 = V_60 ;
V_46 -> V_61 = V_30 ;
V_57 -> V_48 = V_46 ;
return 0 ;
}
static void F_50 ( struct V_56 * V_57 )
{
struct V_45 * V_46 = V_57 -> V_48 ;
V_57 -> V_48 = NULL ;
F_51 ( V_46 ) ;
}
static inline int F_52 ( struct V_22 * V_22 )
{
return F_29 ( V_22 , NULL ) ;
}
static int F_53 ( T_2 V_17 ,
struct V_45 * V_46 ,
const struct V_10 * V_10 )
{
const struct V_13 * V_14 = V_10 -> V_19 ;
int V_62 ;
V_62 = F_54 ( V_14 -> V_17 , V_46 -> V_17 , V_63 ,
V_64 , NULL ) ;
if ( V_62 )
return V_62 ;
V_62 = F_54 ( V_14 -> V_17 , V_17 , V_63 ,
V_65 , NULL ) ;
return V_62 ;
}
static int F_55 ( T_2 V_17 ,
struct V_45 * V_46 ,
const struct V_10 * V_10 )
{
const struct V_13 * V_14 = V_10 -> V_19 ;
int V_62 ;
V_62 = F_54 ( V_14 -> V_17 , V_46 -> V_17 , V_63 ,
V_64 , NULL ) ;
if ( V_62 )
return V_62 ;
V_62 = F_54 ( V_17 , V_46 -> V_17 , V_63 ,
V_66 , NULL ) ;
return V_62 ;
}
static int F_56 ( struct V_56 * V_57 )
{
struct V_45 * V_46 = V_57 -> V_48 ;
return V_46 -> V_67 == V_68 ||
V_46 -> V_67 == V_69 ||
V_46 -> V_67 == V_70 ||
V_46 -> V_67 == V_71 ||
! strcmp ( V_57 -> V_72 -> V_73 , L_2 ) ||
! strcmp ( V_57 -> V_72 -> V_73 , L_3 ) ||
! strcmp ( V_57 -> V_72 -> V_73 , L_4 ) ||
! strcmp ( V_57 -> V_72 -> V_73 , L_5 ) ||
! strcmp ( V_57 -> V_72 -> V_73 , L_6 ) ||
( V_74 &&
( ! strcmp ( V_57 -> V_72 -> V_73 , L_7 ) ||
! strcmp ( V_57 -> V_72 -> V_73 , L_8 ) ) ) ;
}
static int F_57 ( struct V_56 * V_57 )
{
struct V_45 * V_46 = V_57 -> V_48 ;
struct V_36 * V_75 = V_57 -> V_76 ;
struct V_22 * V_77 = F_35 ( V_75 ) ;
int V_62 = 0 ;
if ( V_46 -> V_67 == V_68 ) {
if ( ! ( V_77 -> V_78 & V_79 ) ) {
F_58 ( V_80 L_9
L_10 , V_57 -> V_81 , V_57 -> V_72 -> V_73 ) ;
V_62 = - V_82 ;
goto V_83;
}
V_62 = F_59 ( V_75 , V_77 , V_84 , NULL , 0 ) ;
if ( V_62 < 0 && V_62 != - V_85 ) {
if ( V_62 == - V_82 )
F_58 ( V_80 L_11
L_12 ,
V_57 -> V_81 , V_57 -> V_72 -> V_73 ) ;
else
F_58 ( V_80 L_11
L_13 , V_57 -> V_81 ,
V_57 -> V_72 -> V_73 , - V_62 ) ;
goto V_83;
}
}
if ( V_46 -> V_67 > F_60 ( V_86 ) )
F_58 ( V_87 L_14 ,
V_57 -> V_81 , V_57 -> V_72 -> V_73 ) ;
V_46 -> V_88 |= V_89 ;
if ( F_56 ( V_57 ) )
V_46 -> V_88 |= V_90 ;
V_62 = F_29 ( V_77 , V_75 ) ;
F_42 ( & V_46 -> V_49 ) ;
V_91:
if ( ! F_61 ( & V_46 -> V_58 ) ) {
struct V_23 * V_24 =
F_62 ( V_46 -> V_58 . V_92 ,
struct V_23 , V_29 ) ;
struct V_22 * V_22 = V_24 -> V_22 ;
F_43 ( & V_24 -> V_29 ) ;
F_44 ( & V_46 -> V_49 ) ;
V_22 = F_63 ( V_22 ) ;
if ( V_22 ) {
if ( ! F_64 ( V_22 ) )
F_52 ( V_22 ) ;
F_65 ( V_22 ) ;
}
F_42 ( & V_46 -> V_49 ) ;
goto V_91;
}
F_44 ( & V_46 -> V_49 ) ;
V_83:
return V_62 ;
}
static int F_66 ( const struct V_56 * V_57 ,
struct V_93 * V_94 )
{
int V_62 = 0 , V_95 ;
struct V_45 * V_46 = V_57 -> V_48 ;
char * V_96 = NULL ;
T_2 V_97 ;
char V_98 ;
F_67 ( V_94 ) ;
if ( ! ( V_46 -> V_88 & V_89 ) )
return - V_99 ;
if ( ! V_39 )
return - V_99 ;
F_68 ( V_100 >= ( 1 << V_101 ) ) ;
V_98 = V_46 -> V_88 & V_100 ;
for ( V_95 = 0 ; V_95 < V_101 ; V_95 ++ ) {
if ( V_98 & 0x01 )
V_94 -> V_102 ++ ;
V_98 >>= 1 ;
}
if ( V_46 -> V_88 & V_90 )
V_94 -> V_102 ++ ;
V_94 -> V_103 = F_69 ( V_94 -> V_102 , sizeof( char * ) , V_104 ) ;
if ( ! V_94 -> V_103 ) {
V_62 = - V_27 ;
goto V_105;
}
V_94 -> V_106 = F_69 ( V_94 -> V_102 , sizeof( int ) , V_104 ) ;
if ( ! V_94 -> V_106 ) {
V_62 = - V_27 ;
goto V_105;
}
V_95 = 0 ;
if ( V_46 -> V_88 & V_107 ) {
V_62 = F_70 ( V_46 -> V_17 , & V_96 , & V_97 ) ;
if ( V_62 )
goto V_105;
V_94 -> V_103 [ V_95 ] = V_96 ;
V_94 -> V_106 [ V_95 ++ ] = V_107 ;
}
if ( V_46 -> V_88 & V_108 ) {
V_62 = F_70 ( V_46 -> V_61 , & V_96 , & V_97 ) ;
if ( V_62 )
goto V_105;
V_94 -> V_103 [ V_95 ] = V_96 ;
V_94 -> V_106 [ V_95 ++ ] = V_108 ;
}
if ( V_46 -> V_88 & V_109 ) {
V_62 = F_70 ( V_46 -> V_59 , & V_96 , & V_97 ) ;
if ( V_62 )
goto V_105;
V_94 -> V_103 [ V_95 ] = V_96 ;
V_94 -> V_106 [ V_95 ++ ] = V_109 ;
}
if ( V_46 -> V_88 & V_110 ) {
struct V_36 * V_75 = V_46 -> V_57 -> V_76 ;
struct V_23 * V_24 = F_36 ( V_75 ) ;
V_62 = F_70 ( V_24 -> V_17 , & V_96 , & V_97 ) ;
if ( V_62 )
goto V_105;
V_94 -> V_103 [ V_95 ] = V_96 ;
V_94 -> V_106 [ V_95 ++ ] = V_110 ;
}
if ( V_46 -> V_88 & V_90 ) {
V_94 -> V_103 [ V_95 ] = NULL ;
V_94 -> V_106 [ V_95 ++ ] = V_90 ;
}
F_71 ( V_95 != V_94 -> V_102 ) ;
return 0 ;
V_105:
F_72 ( V_94 ) ;
return V_62 ;
}
static int F_73 ( struct V_45 * V_46 , char V_111 ,
T_2 V_112 , T_2 V_113 )
{
char V_114 = V_46 -> V_88 & V_100 ;
if ( V_46 -> V_88 & V_89 )
if ( ! ( V_46 -> V_88 & V_111 ) ||
( V_112 != V_113 ) )
return 1 ;
if ( ! ( V_46 -> V_88 & V_89 ) )
if ( V_114 & V_111 )
return 1 ;
return 0 ;
}
static int F_74 ( struct V_56 * V_57 ,
struct V_93 * V_94 ,
unsigned long V_115 ,
unsigned long * V_116 )
{
const struct V_10 * V_10 = F_75 () ;
int V_62 = 0 , V_95 ;
struct V_45 * V_46 = V_57 -> V_48 ;
const char * V_73 = V_57 -> V_72 -> V_73 ;
struct V_36 * V_75 = V_46 -> V_57 -> V_76 ;
struct V_23 * V_117 ;
T_2 V_118 = 0 , V_119 = 0 , V_120 = 0 ;
T_2 V_121 = 0 ;
char * * V_122 = V_94 -> V_103 ;
int * V_88 = V_94 -> V_106 ;
int V_123 = V_94 -> V_102 ;
F_76 ( & V_46 -> V_28 ) ;
if ( ! V_39 ) {
if ( ! V_123 ) {
goto V_83;
}
V_62 = - V_99 ;
F_58 ( V_80 L_15
L_16 ) ;
goto V_83;
}
if ( V_115 && ! V_116 ) {
V_62 = - V_99 ;
goto V_83;
}
if ( ( V_46 -> V_88 & V_89 ) && ( V_57 -> V_72 -> V_124 & V_125 )
&& ( V_123 == 0 ) )
goto V_83;
V_117 = F_34 ( V_75 ) ;
for ( V_95 = 0 ; V_95 < V_123 ; V_95 ++ ) {
T_2 V_17 ;
if ( V_88 [ V_95 ] == V_90 )
continue;
V_62 = F_77 ( V_122 [ V_95 ] , & V_17 , V_15 ) ;
if ( V_62 ) {
F_58 ( V_80 L_17
L_18 ,
V_122 [ V_95 ] , V_57 -> V_81 , V_73 , V_62 ) ;
goto V_83;
}
switch ( V_88 [ V_95 ] ) {
case V_107 :
V_118 = V_17 ;
if ( F_73 ( V_46 , V_107 , V_46 -> V_17 ,
V_118 ) )
goto V_126;
V_46 -> V_88 |= V_107 ;
break;
case V_108 :
V_119 = V_17 ;
if ( F_73 ( V_46 , V_108 , V_46 -> V_61 ,
V_119 ) )
goto V_126;
V_46 -> V_88 |= V_108 ;
break;
case V_110 :
V_120 = V_17 ;
if ( F_73 ( V_46 , V_110 , V_117 -> V_17 ,
V_120 ) )
goto V_126;
V_46 -> V_88 |= V_110 ;
break;
case V_109 :
V_121 = V_17 ;
if ( F_73 ( V_46 , V_109 , V_46 -> V_59 ,
V_121 ) )
goto V_126;
V_46 -> V_88 |= V_109 ;
break;
default:
V_62 = - V_99 ;
goto V_83;
}
}
if ( V_46 -> V_88 & V_89 ) {
if ( ( V_46 -> V_88 & V_100 ) && ! V_123 )
goto V_126;
V_62 = 0 ;
goto V_83;
}
if ( strcmp ( V_57 -> V_72 -> V_73 , L_19 ) == 0 )
V_46 -> V_88 |= V_127 | V_128 ;
if ( ! strcmp ( V_57 -> V_72 -> V_73 , L_4 ) ||
! strcmp ( V_57 -> V_72 -> V_73 , L_2 ) ||
! strcmp ( V_57 -> V_72 -> V_73 , L_3 ) )
V_46 -> V_88 |= V_128 ;
if ( ! V_46 -> V_67 ) {
V_62 = F_78 ( V_57 ) ;
if ( V_62 ) {
F_58 ( V_80
L_20 ,
V_129 , V_57 -> V_72 -> V_73 , V_62 ) ;
goto V_83;
}
}
if ( V_57 -> V_130 != & V_131 &&
strcmp ( V_57 -> V_72 -> V_73 , L_21 ) &&
strcmp ( V_57 -> V_72 -> V_73 , L_22 ) &&
strcmp ( V_57 -> V_72 -> V_73 , L_23 ) ) {
if ( V_119 || V_118 || V_120 ||
V_121 ) {
V_62 = - V_132 ;
goto V_83;
}
if ( V_46 -> V_67 == V_68 ) {
V_46 -> V_67 = V_133 ;
V_62 = F_79 ( F_23 () , F_23 () ,
V_32 , NULL ,
& V_46 -> V_61 ) ;
if ( V_62 )
goto V_83;
}
goto V_134;
}
if ( V_118 ) {
V_62 = F_53 ( V_118 , V_46 , V_10 ) ;
if ( V_62 )
goto V_83;
V_46 -> V_17 = V_118 ;
}
if ( V_115 & V_135 && ! V_119 ) {
V_46 -> V_67 = V_71 ;
* V_116 |= V_135 ;
}
if ( V_119 ) {
if ( ! V_118 ) {
V_62 = F_53 ( V_119 , V_46 ,
V_10 ) ;
if ( V_62 )
goto V_83;
V_46 -> V_17 = V_119 ;
} else {
V_62 = F_55 ( V_119 , V_46 ,
V_10 ) ;
if ( V_62 )
goto V_83;
}
if ( ! V_120 )
V_120 = V_119 ;
V_46 -> V_61 = V_119 ;
V_46 -> V_67 = V_133 ;
}
if ( V_120 ) {
V_62 = F_55 ( V_120 , V_46 ,
V_10 ) ;
if ( V_62 )
goto V_83;
V_117 -> V_17 = V_120 ;
V_117 -> V_33 = V_40 ;
}
if ( V_121 ) {
if ( V_46 -> V_67 != V_68 &&
V_46 -> V_67 != V_71 ) {
V_62 = - V_99 ;
F_58 ( V_80 L_24
L_25 ) ;
goto V_83;
}
if ( V_121 != V_46 -> V_59 ) {
V_62 = F_55 ( V_121 ,
V_46 , V_10 ) ;
if ( V_62 )
goto V_83;
}
V_46 -> V_59 = V_121 ;
}
V_134:
V_62 = F_57 ( V_57 ) ;
V_83:
F_80 ( & V_46 -> V_28 ) ;
return V_62 ;
V_126:
V_62 = - V_99 ;
F_58 ( V_80 L_26
L_27 , V_57 -> V_81 , V_73 ) ;
goto V_83;
}
static int F_81 ( const struct V_56 * V_136 ,
const struct V_56 * V_137 )
{
struct V_45 * V_138 = V_136 -> V_48 ;
struct V_45 * V_139 = V_137 -> V_48 ;
char V_140 = V_138 -> V_88 & V_100 ;
char V_141 = V_139 -> V_88 & V_100 ;
if ( V_140 != V_141 )
goto V_142;
if ( ( V_140 & V_107 ) && V_138 -> V_17 != V_139 -> V_17 )
goto V_142;
if ( ( V_140 & V_108 ) && V_138 -> V_61 != V_139 -> V_61 )
goto V_142;
if ( ( V_140 & V_109 ) && V_138 -> V_59 != V_139 -> V_59 )
goto V_142;
if ( V_140 & V_110 ) {
struct V_23 * V_143 = F_36 ( V_136 -> V_76 ) ;
struct V_23 * V_144 = F_36 ( V_137 -> V_76 ) ;
if ( V_143 -> V_17 != V_144 -> V_17 )
goto V_142;
}
return 0 ;
V_142:
F_58 ( V_80 L_28
L_29
L_30 , V_137 -> V_81 , V_137 -> V_72 -> V_73 ) ;
return - V_145 ;
}
static int F_82 ( const struct V_56 * V_136 ,
struct V_56 * V_137 )
{
const struct V_45 * V_146 = V_136 -> V_48 ;
struct V_45 * V_147 = V_137 -> V_48 ;
int V_148 = ( V_146 -> V_88 & V_107 ) ;
int V_149 = ( V_146 -> V_88 & V_108 ) ;
int V_150 = ( V_146 -> V_88 & V_110 ) ;
if ( ! V_39 )
return 0 ;
F_71 ( ! ( V_146 -> V_88 & V_89 ) ) ;
if ( V_147 -> V_88 & V_89 )
return F_81 ( V_136 , V_137 ) ;
F_76 ( & V_147 -> V_28 ) ;
V_147 -> V_88 = V_146 -> V_88 ;
V_147 -> V_17 = V_146 -> V_17 ;
V_147 -> V_59 = V_146 -> V_59 ;
V_147 -> V_67 = V_146 -> V_67 ;
if ( V_149 ) {
T_2 V_17 = V_146 -> V_61 ;
if ( ! V_148 )
V_147 -> V_17 = V_17 ;
if ( ! V_150 ) {
struct V_23 * V_151 = F_36 ( V_137 -> V_76 ) ;
V_151 -> V_17 = V_17 ;
}
V_147 -> V_61 = V_17 ;
}
if ( V_150 ) {
const struct V_23 * V_152 = F_36 ( V_136 -> V_76 ) ;
struct V_23 * V_151 = F_36 ( V_137 -> V_76 ) ;
V_151 -> V_17 = V_152 -> V_17 ;
}
F_57 ( V_137 ) ;
F_80 ( & V_147 -> V_28 ) ;
return 0 ;
}
static int F_83 ( char * V_153 ,
struct V_93 * V_94 )
{
char * V_154 ;
char * V_96 = NULL , * V_155 = NULL ;
char * V_156 = NULL , * V_157 = NULL ;
int V_62 , V_102 = 0 ;
V_94 -> V_102 = 0 ;
while ( ( V_154 = F_84 ( & V_153 , L_31 ) ) != NULL ) {
int V_158 ;
T_3 args [ V_159 ] ;
if ( ! * V_154 )
continue;
V_158 = F_85 ( V_154 , V_160 , args ) ;
switch ( V_158 ) {
case V_161 :
if ( V_96 || V_155 ) {
V_62 = - V_99 ;
F_58 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_162;
}
V_96 = F_86 ( & args [ 0 ] ) ;
if ( ! V_96 ) {
V_62 = - V_27 ;
goto V_162;
}
break;
case V_163 :
if ( V_156 ) {
V_62 = - V_99 ;
F_58 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_162;
}
V_156 = F_86 ( & args [ 0 ] ) ;
if ( ! V_156 ) {
V_62 = - V_27 ;
goto V_162;
}
break;
case V_164 :
if ( V_157 ) {
V_62 = - V_99 ;
F_58 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_162;
}
V_157 = F_86 ( & args [ 0 ] ) ;
if ( ! V_157 ) {
V_62 = - V_27 ;
goto V_162;
}
break;
case V_165 :
if ( V_96 || V_155 ) {
V_62 = - V_99 ;
F_58 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_162;
}
V_155 = F_86 ( & args [ 0 ] ) ;
if ( ! V_155 ) {
V_62 = - V_27 ;
goto V_162;
}
break;
case V_166 :
break;
default:
V_62 = - V_99 ;
F_58 ( V_80 L_32 ) ;
goto V_162;
}
}
V_62 = - V_27 ;
V_94 -> V_103 = F_69 ( V_101 , sizeof( char * ) , V_15 ) ;
if ( ! V_94 -> V_103 )
goto V_162;
V_94 -> V_106 = F_69 ( V_101 , sizeof( int ) ,
V_15 ) ;
if ( ! V_94 -> V_106 ) {
F_51 ( V_94 -> V_103 ) ;
goto V_162;
}
if ( V_156 ) {
V_94 -> V_103 [ V_102 ] = V_156 ;
V_94 -> V_106 [ V_102 ++ ] = V_107 ;
}
if ( V_96 ) {
V_94 -> V_103 [ V_102 ] = V_96 ;
V_94 -> V_106 [ V_102 ++ ] = V_108 ;
}
if ( V_157 ) {
V_94 -> V_103 [ V_102 ] = V_157 ;
V_94 -> V_106 [ V_102 ++ ] = V_110 ;
}
if ( V_155 ) {
V_94 -> V_103 [ V_102 ] = V_155 ;
V_94 -> V_106 [ V_102 ++ ] = V_109 ;
}
V_94 -> V_102 = V_102 ;
return 0 ;
V_162:
F_51 ( V_96 ) ;
F_51 ( V_155 ) ;
F_51 ( V_156 ) ;
F_51 ( V_157 ) ;
return V_62 ;
}
static int F_87 ( struct V_56 * V_57 , void * V_167 )
{
int V_62 = 0 ;
char * V_153 = V_167 ;
struct V_93 V_94 ;
F_67 ( & V_94 ) ;
if ( ! V_167 )
goto V_83;
F_71 ( V_57 -> V_72 -> V_124 & V_125 ) ;
V_62 = F_83 ( V_153 , & V_94 ) ;
if ( V_62 )
goto V_162;
V_83:
V_62 = F_74 ( V_57 , & V_94 , 0 , NULL ) ;
V_162:
F_72 ( & V_94 ) ;
return V_62 ;
}
static void F_88 ( struct V_168 * V_169 ,
struct V_93 * V_94 )
{
int V_95 ;
char * V_170 ;
for ( V_95 = 0 ; V_95 < V_94 -> V_102 ; V_95 ++ ) {
char * V_171 ;
if ( V_94 -> V_103 [ V_95 ] )
V_171 = strchr ( V_94 -> V_103 [ V_95 ] , ',' ) ;
else
V_171 = NULL ;
switch ( V_94 -> V_106 [ V_95 ] ) {
case V_108 :
V_170 = V_172 ;
break;
case V_107 :
V_170 = V_173 ;
break;
case V_110 :
V_170 = V_174 ;
break;
case V_109 :
V_170 = V_175 ;
break;
case V_90 :
F_89 ( V_169 , ',' ) ;
F_90 ( V_169 , V_176 ) ;
continue;
default:
F_91 () ;
return;
} ;
F_89 ( V_169 , ',' ) ;
F_90 ( V_169 , V_170 ) ;
if ( V_171 )
F_89 ( V_169 , '\"' ) ;
F_92 ( V_169 , V_94 -> V_103 [ V_95 ] , L_33 ) ;
if ( V_171 )
F_89 ( V_169 , '\"' ) ;
}
}
static int F_93 ( struct V_168 * V_169 , struct V_56 * V_57 )
{
struct V_93 V_94 ;
int V_62 ;
V_62 = F_66 ( V_57 , & V_94 ) ;
if ( V_62 ) {
if ( V_62 == - V_99 )
V_62 = 0 ;
return V_62 ;
}
F_88 ( V_169 , & V_94 ) ;
F_72 ( & V_94 ) ;
return V_62 ;
}
static inline T_4 F_94 ( T_5 V_177 )
{
switch ( V_177 & V_178 ) {
case V_179 :
return V_180 ;
case V_181 :
return V_182 ;
case V_183 :
return V_32 ;
case V_184 :
return V_185 ;
case V_186 :
return V_187 ;
case V_188 :
return V_189 ;
case V_190 :
return V_191 ;
}
return V_32 ;
}
static inline int F_95 ( int V_192 )
{
return ( V_192 == V_193 || V_192 == V_194 ) ;
}
static inline int F_96 ( int V_192 )
{
return ( V_192 == V_193 || V_192 == V_195 ) ;
}
static inline T_4 F_97 ( int V_196 , int type , int V_192 )
{
int V_197 = V_198 ;
switch ( V_196 ) {
case V_199 :
switch ( type ) {
case V_200 :
case V_201 :
return V_202 ;
case V_203 :
return V_204 ;
}
break;
case V_205 :
case V_206 :
switch ( type ) {
case V_200 :
case V_201 :
if ( F_95 ( V_192 ) )
return V_207 ;
else if ( V_197 && V_192 == V_208 )
return V_209 ;
else
return V_210 ;
case V_203 :
if ( F_96 ( V_192 ) )
return V_211 ;
else if ( V_197 && ( V_192 == V_212 ||
V_192 == V_213 ) )
return V_214 ;
else
return V_210 ;
case V_215 :
return V_216 ;
default:
return V_210 ;
}
break;
case V_217 :
switch ( V_192 ) {
case V_218 :
return V_219 ;
case V_220 :
return V_221 ;
case V_222 :
return V_223 ;
case V_224 :
return V_225 ;
case V_226 :
return V_227 ;
case V_228 :
return V_229 ;
case V_230 :
return V_231 ;
case V_232 :
return V_233 ;
case V_234 :
return V_235 ;
case V_236 :
return V_237 ;
case V_238 :
return V_239 ;
case V_240 :
return V_241 ;
case V_242 :
return V_243 ;
case V_244 :
return V_245 ;
case V_246 :
return V_247 ;
case V_248 :
return V_249 ;
default:
return V_250 ;
}
case V_251 :
return V_252 ;
case V_253 :
return V_254 ;
case V_255 :
return V_256 ;
}
if ( V_197 ) {
switch ( V_196 ) {
case V_257 :
return V_258 ;
case V_259 :
return V_260 ;
case V_261 :
return V_262 ;
case V_263 :
return V_264 ;
case V_265 :
return V_266 ;
case V_267 :
return V_268 ;
case V_269 :
return V_270 ;
case V_271 :
return V_272 ;
case V_273 :
return V_274 ;
case V_275 :
return V_276 ;
case V_277 :
return V_278 ;
case V_279 :
return V_280 ;
case V_281 :
return V_282 ;
case V_283 :
return V_284 ;
case V_285 :
return V_286 ;
case V_287 :
return V_288 ;
case V_289 :
return V_290 ;
case V_291 :
return V_292 ;
case V_293 :
return V_294 ;
case V_295 :
return V_296 ;
case V_297 :
return V_298 ;
case V_299 :
return V_300 ;
case V_301 :
return V_302 ;
case V_303 :
return V_304 ;
case V_305 :
return V_306 ;
case V_307 :
return V_308 ;
case V_309 :
return V_310 ;
#if V_311 > 44
#error New address family defined, please update this function.
#endif
}
}
return V_312 ;
}
static int F_98 ( struct V_36 * V_36 ,
T_4 V_313 ,
T_4 V_88 ,
T_2 * V_17 )
{
int V_62 ;
struct V_56 * V_57 = V_36 -> V_314 ;
char * V_315 , * V_316 ;
V_315 = ( char * ) F_99 ( V_15 ) ;
if ( ! V_315 )
return - V_27 ;
V_316 = F_100 ( V_36 , V_315 , V_317 ) ;
if ( F_101 ( V_316 ) )
V_62 = F_102 ( V_316 ) ;
else {
if ( V_88 & V_127 ) {
while ( V_316 [ 1 ] >= '0' && V_316 [ 1 ] <= '9' ) {
V_316 [ 1 ] = '/' ;
V_316 ++ ;
}
}
V_62 = F_103 ( V_57 -> V_72 -> V_73 , V_316 , V_313 , V_17 ) ;
}
F_104 ( ( unsigned long ) V_315 ) ;
return V_62 ;
}
static int F_29 ( struct V_22 * V_22 , struct V_36 * V_37 )
{
struct V_45 * V_46 = NULL ;
struct V_23 * V_24 = V_22 -> V_35 ;
T_2 F_18 , V_17 = 0 ;
T_4 V_31 ;
struct V_36 * V_36 ;
#define F_105 255
char * V_96 = NULL ;
unsigned V_97 = 0 ;
int V_62 = 0 ;
if ( V_24 -> V_33 == V_40 )
return 0 ;
F_42 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_33 == V_40 )
goto V_318;
if ( V_24 -> V_31 == V_32 )
V_24 -> V_31 = F_94 ( V_22 -> V_319 ) ;
V_46 = V_22 -> V_47 -> V_48 ;
if ( ! ( V_46 -> V_88 & V_89 ) ) {
F_42 ( & V_46 -> V_49 ) ;
if ( F_61 ( & V_24 -> V_29 ) )
F_106 ( & V_24 -> V_29 , & V_46 -> V_58 ) ;
F_44 ( & V_46 -> V_49 ) ;
goto V_318;
}
V_31 = V_24 -> V_31 ;
F_18 = V_24 -> F_18 ;
V_17 = V_24 -> V_17 ;
V_24 -> V_33 = V_320 ;
F_44 ( & V_24 -> V_28 ) ;
switch ( V_46 -> V_67 ) {
case V_71 :
break;
case V_68 :
if ( ! ( V_22 -> V_78 & V_79 ) ) {
V_17 = V_46 -> V_59 ;
break;
}
if ( V_37 ) {
V_36 = F_107 ( V_37 ) ;
} else {
V_36 = F_108 ( V_22 ) ;
}
if ( ! V_36 ) {
goto V_83;
}
V_97 = F_105 ;
V_96 = F_109 ( V_97 + 1 , V_26 ) ;
if ( ! V_96 ) {
V_62 = - V_27 ;
F_110 ( V_36 ) ;
goto V_83;
}
V_96 [ V_97 ] = '\0' ;
V_62 = F_59 ( V_36 , V_22 , V_84 , V_96 , V_97 ) ;
if ( V_62 == - V_321 ) {
F_51 ( V_96 ) ;
V_62 = F_59 ( V_36 , V_22 , V_84 , NULL , 0 ) ;
if ( V_62 < 0 ) {
F_110 ( V_36 ) ;
goto V_83;
}
V_97 = V_62 ;
V_96 = F_109 ( V_97 + 1 , V_26 ) ;
if ( ! V_96 ) {
V_62 = - V_27 ;
F_110 ( V_36 ) ;
goto V_83;
}
V_96 [ V_97 ] = '\0' ;
V_62 = F_59 ( V_36 , V_22 , V_84 , V_96 , V_97 ) ;
}
F_110 ( V_36 ) ;
if ( V_62 < 0 ) {
if ( V_62 != - V_85 ) {
F_58 ( V_80 L_34
L_35 , V_129 ,
- V_62 , V_22 -> V_47 -> V_81 , V_22 -> V_322 ) ;
F_51 ( V_96 ) ;
goto V_83;
}
V_17 = V_46 -> V_59 ;
V_62 = 0 ;
} else {
V_62 = F_111 ( V_96 , V_62 , & V_17 ,
V_46 -> V_59 ,
V_26 ) ;
if ( V_62 ) {
char * V_323 = V_22 -> V_47 -> V_81 ;
unsigned long V_324 = V_22 -> V_322 ;
if ( V_62 == - V_99 ) {
if ( F_112 () )
F_58 ( V_325 L_36
L_37
L_38 , V_324 , V_323 , V_96 ) ;
} else {
F_58 ( V_80 L_39
L_40 ,
V_129 , V_96 , - V_62 , V_323 , V_324 ) ;
}
F_51 ( V_96 ) ;
V_62 = 0 ;
break;
}
}
F_51 ( V_96 ) ;
break;
case V_70 :
V_17 = F_18 ;
break;
case V_69 :
V_17 = V_46 -> V_17 ;
V_62 = F_79 ( F_18 , V_17 , V_31 , NULL , & V_17 ) ;
if ( V_62 )
goto V_83;
break;
case V_133 :
V_17 = V_46 -> V_61 ;
break;
default:
V_17 = V_46 -> V_17 ;
if ( ( V_46 -> V_88 & V_128 ) && ! F_113 ( V_22 -> V_319 ) ) {
if ( V_37 )
V_36 = F_107 ( V_37 ) ;
else
V_36 = F_108 ( V_22 ) ;
if ( ! V_36 )
goto V_83;
V_62 = F_98 ( V_36 , V_31 ,
V_46 -> V_88 , & V_17 ) ;
F_110 ( V_36 ) ;
if ( V_62 )
goto V_83;
}
break;
}
V_83:
F_42 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_33 == V_320 ) {
if ( ! V_17 || V_62 ) {
V_24 -> V_33 = V_34 ;
goto V_318;
}
V_24 -> V_33 = V_40 ;
V_24 -> V_17 = V_17 ;
}
V_318:
F_44 ( & V_24 -> V_28 ) ;
return V_62 ;
}
static inline T_2 F_114 ( int V_326 )
{
T_2 V_327 = 0 ;
switch ( V_326 ) {
case V_328 :
V_327 = V_329 ;
break;
case V_330 :
V_327 = V_331 ;
break;
case V_332 :
V_327 = V_333 ;
break;
default:
V_327 = V_334 ;
break;
}
return V_327 ;
}
static int F_115 ( const struct V_10 * V_10 ,
int V_335 , int V_336 , bool V_337 )
{
struct V_338 V_339 ;
struct V_340 V_341 ;
T_4 V_31 ;
T_2 V_17 = F_17 ( V_10 ) ;
T_2 V_342 = F_116 ( V_335 ) ;
int V_62 ;
V_339 . type = V_343 ;
V_339 . V_344 . V_335 = V_335 ;
switch ( F_117 ( V_335 ) ) {
case 0 :
V_31 = V_337 ? V_345 : V_346 ;
break;
case 1 :
V_31 = V_337 ? V_347 : V_348 ;
break;
default:
F_58 ( V_87
L_41 , V_335 ) ;
F_91 () ;
return - V_99 ;
}
V_62 = F_118 ( V_17 , V_17 , V_31 , V_342 , 0 , & V_341 ) ;
if ( V_336 == V_349 ) {
int V_350 = F_119 ( V_17 , V_17 , V_31 , V_342 , & V_341 , V_62 , & V_339 , 0 ) ;
if ( V_350 )
return V_350 ;
}
return V_62 ;
}
static int F_120 ( const struct V_10 * V_10 ,
struct V_22 * V_22 ,
T_2 V_351 ,
struct V_338 * V_352 )
{
struct V_23 * V_24 ;
T_2 V_17 ;
F_121 ( V_10 ) ;
if ( F_122 ( F_64 ( V_22 ) ) )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_35 ;
return F_54 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_351 , V_352 ) ;
}
static inline int F_123 ( const struct V_10 * V_10 ,
struct V_36 * V_36 ,
T_2 V_342 )
{
struct V_22 * V_22 = F_35 ( V_36 ) ;
struct V_338 V_339 ;
V_339 . type = V_353 ;
V_339 . V_344 . V_36 = V_36 ;
F_27 ( V_22 , V_36 , true ) ;
return F_120 ( V_10 , V_22 , V_342 , & V_339 ) ;
}
static inline int F_124 ( const struct V_10 * V_10 ,
const struct V_316 * V_316 ,
T_2 V_342 )
{
struct V_22 * V_22 = F_35 ( V_316 -> V_36 ) ;
struct V_338 V_339 ;
V_339 . type = V_354 ;
V_339 . V_344 . V_316 = * V_316 ;
F_27 ( V_22 , V_316 -> V_36 , true ) ;
return F_120 ( V_10 , V_22 , V_342 , & V_339 ) ;
}
static inline int F_125 ( const struct V_10 * V_10 ,
struct V_50 * V_50 ,
T_2 V_342 )
{
struct V_338 V_339 ;
V_339 . type = V_355 ;
V_339 . V_344 . V_50 = V_50 ;
return F_120 ( V_10 , F_126 ( V_50 ) , V_342 , & V_339 ) ;
}
static int F_127 ( const struct V_10 * V_10 ,
struct V_50 * V_50 ,
T_2 V_342 )
{
struct V_51 * V_52 = V_50 -> V_55 ;
struct V_22 * V_22 = F_126 ( V_50 ) ;
struct V_338 V_339 ;
T_2 V_17 = F_17 ( V_10 ) ;
int V_62 ;
V_339 . type = V_355 ;
V_339 . V_344 . V_50 = V_50 ;
if ( V_17 != V_52 -> V_17 ) {
V_62 = F_54 ( V_17 , V_52 -> V_17 ,
V_356 ,
V_357 ,
& V_339 ) ;
if ( V_62 )
goto V_83;
}
V_62 = 0 ;
if ( V_342 )
V_62 = F_120 ( V_10 , V_22 , V_342 , & V_339 ) ;
V_83:
return V_62 ;
}
static int
F_128 ( const struct V_13 * V_14 ,
struct V_22 * V_358 ,
const struct V_359 * V_73 , T_4 V_313 ,
T_2 * V_360 )
{
const struct V_45 * V_46 = V_358 -> V_47 -> V_48 ;
if ( ( V_46 -> V_88 & V_89 ) &&
( V_46 -> V_67 == V_133 ) ) {
* V_360 = V_46 -> V_61 ;
} else if ( ( V_46 -> V_88 & V_90 ) &&
V_14 -> V_361 ) {
* V_360 = V_14 -> V_361 ;
} else {
const struct V_23 * V_362 = F_33 ( V_358 ) ;
return F_79 ( V_14 -> V_17 , V_362 -> V_17 , V_313 ,
V_73 , V_360 ) ;
}
return 0 ;
}
static int F_129 ( struct V_22 * V_358 ,
struct V_36 * V_36 ,
T_4 V_313 )
{
const struct V_13 * V_14 = F_130 () ;
struct V_23 * V_362 ;
struct V_45 * V_46 ;
T_2 V_17 , V_363 ;
struct V_338 V_339 ;
int V_62 ;
V_362 = F_33 ( V_358 ) ;
V_46 = V_358 -> V_47 -> V_48 ;
V_17 = V_14 -> V_17 ;
V_339 . type = V_353 ;
V_339 . V_344 . V_36 = V_36 ;
V_62 = F_54 ( V_17 , V_362 -> V_17 , V_187 ,
V_364 | V_365 ,
& V_339 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_128 ( F_130 () , V_358 ,
& V_36 -> V_366 , V_313 , & V_363 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_54 ( V_17 , V_363 , V_313 , V_367 , & V_339 ) ;
if ( V_62 )
return V_62 ;
return F_54 ( V_363 , V_46 -> V_17 ,
V_63 ,
V_66 , & V_339 ) ;
}
static int F_131 ( struct V_22 * V_358 ,
struct V_36 * V_36 ,
int V_368 )
{
struct V_23 * V_362 , * V_24 ;
struct V_338 V_339 ;
T_2 V_17 = F_23 () ;
T_2 V_342 ;
int V_62 ;
V_362 = F_33 ( V_358 ) ;
V_24 = F_36 ( V_36 ) ;
V_339 . type = V_353 ;
V_339 . V_344 . V_36 = V_36 ;
V_342 = V_365 ;
V_342 |= ( V_368 ? V_369 : V_364 ) ;
V_62 = F_54 ( V_17 , V_362 -> V_17 , V_187 , V_342 , & V_339 ) ;
if ( V_62 )
return V_62 ;
switch ( V_368 ) {
case V_370 :
V_342 = V_371 ;
break;
case V_372 :
V_342 = V_373 ;
break;
case V_374 :
V_342 = V_375 ;
break;
default:
F_58 ( V_80 L_42 ,
V_129 , V_368 ) ;
return 0 ;
}
V_62 = F_54 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_342 , & V_339 ) ;
return V_62 ;
}
static inline int F_132 ( struct V_22 * V_376 ,
struct V_36 * V_377 ,
struct V_22 * V_378 ,
struct V_36 * V_379 )
{
struct V_23 * V_380 , * V_381 , * V_382 , * V_383 ;
struct V_338 V_339 ;
T_2 V_17 = F_23 () ;
T_2 V_342 ;
int V_384 , V_385 ;
int V_62 ;
V_380 = F_33 ( V_376 ) ;
V_382 = F_36 ( V_377 ) ;
V_384 = F_133 ( V_377 ) ;
V_381 = F_33 ( V_378 ) ;
V_339 . type = V_353 ;
V_339 . V_344 . V_36 = V_377 ;
V_62 = F_54 ( V_17 , V_380 -> V_17 , V_187 ,
V_369 | V_365 , & V_339 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_54 ( V_17 , V_382 -> V_17 ,
V_382 -> V_31 , V_386 , & V_339 ) ;
if ( V_62 )
return V_62 ;
if ( V_384 && V_378 != V_376 ) {
V_62 = F_54 ( V_17 , V_382 -> V_17 ,
V_382 -> V_31 , V_387 , & V_339 ) ;
if ( V_62 )
return V_62 ;
}
V_339 . V_344 . V_36 = V_379 ;
V_342 = V_364 | V_365 ;
if ( F_134 ( V_379 ) )
V_342 |= V_369 ;
V_62 = F_54 ( V_17 , V_381 -> V_17 , V_187 , V_342 , & V_339 ) ;
if ( V_62 )
return V_62 ;
if ( F_134 ( V_379 ) ) {
V_383 = F_36 ( V_379 ) ;
V_385 = F_133 ( V_379 ) ;
V_62 = F_54 ( V_17 , V_383 -> V_17 ,
V_383 -> V_31 ,
( V_385 ? V_375 : V_373 ) , & V_339 ) ;
if ( V_62 )
return V_62 ;
}
return 0 ;
}
static int F_135 ( const struct V_10 * V_10 ,
struct V_56 * V_57 ,
T_2 V_351 ,
struct V_338 * V_339 )
{
struct V_45 * V_46 ;
T_2 V_17 = F_17 ( V_10 ) ;
V_46 = V_57 -> V_48 ;
return F_54 ( V_17 , V_46 -> V_17 , V_63 , V_351 , V_339 ) ;
}
static inline T_2 F_136 ( int V_177 , int V_388 )
{
T_2 V_342 = 0 ;
if ( ! F_137 ( V_177 ) ) {
if ( V_388 & V_389 )
V_342 |= V_390 ;
if ( V_388 & V_391 )
V_342 |= V_392 ;
if ( V_388 & V_393 )
V_342 |= V_394 ;
else if ( V_388 & V_395 )
V_342 |= V_396 ;
} else {
if ( V_388 & V_389 )
V_342 |= V_365 ;
if ( V_388 & V_395 )
V_342 |= V_397 ;
if ( V_388 & V_391 )
V_342 |= V_398 ;
}
return V_342 ;
}
static inline T_2 F_138 ( struct V_50 * V_50 )
{
T_2 V_342 = 0 ;
if ( V_50 -> V_399 & V_400 )
V_342 |= V_392 ;
if ( V_50 -> V_399 & V_401 ) {
if ( V_50 -> V_402 & V_403 )
V_342 |= V_394 ;
else
V_342 |= V_396 ;
}
if ( ! V_342 ) {
V_342 = V_404 ;
}
return V_342 ;
}
static inline T_2 F_139 ( struct V_50 * V_50 )
{
T_2 V_342 = F_138 ( V_50 ) ;
if ( V_405 )
V_342 |= V_406 ;
return V_342 ;
}
static int F_140 ( struct V_20 * V_407 )
{
T_2 V_408 = F_23 () ;
T_2 V_409 = F_18 ( V_407 ) ;
return F_54 ( V_408 , V_409 , V_410 ,
V_411 , NULL ) ;
}
static int F_141 ( struct V_20 * V_412 ,
struct V_20 * V_413 )
{
T_2 V_408 = F_23 () ;
T_2 V_414 = F_18 ( V_412 ) ;
T_2 V_415 = F_18 ( V_413 ) ;
int V_62 ;
if ( V_408 != V_414 ) {
V_62 = F_54 ( V_408 , V_414 , V_410 ,
V_416 , NULL ) ;
if ( V_62 )
return V_62 ;
}
return F_54 ( V_414 , V_415 , V_410 , V_417 ,
NULL ) ;
}
static int F_142 ( struct V_20 * V_412 ,
struct V_20 * V_413 )
{
T_2 V_414 = F_18 ( V_412 ) ;
T_2 V_415 = F_18 ( V_413 ) ;
return F_54 ( V_414 , V_415 , V_410 , V_418 ,
NULL ) ;
}
static int F_143 ( struct V_20 * V_412 ,
struct V_20 * V_413 ,
struct V_50 * V_50 )
{
T_2 V_17 = F_18 ( V_413 ) ;
struct V_51 * V_52 = V_50 -> V_55 ;
struct V_36 * V_36 = V_50 -> V_419 . V_36 ;
struct V_23 * V_24 ;
struct V_338 V_339 ;
int V_62 ;
V_339 . type = V_354 ;
V_339 . V_344 . V_316 = V_50 -> V_419 ;
if ( V_17 != V_52 -> V_17 ) {
V_62 = F_54 ( V_17 , V_52 -> V_17 ,
V_356 ,
V_357 ,
& V_339 ) ;
if ( V_62 )
return V_62 ;
}
if ( F_122 ( F_64 ( F_35 ( V_36 ) ) ) )
return 0 ;
V_24 = F_36 ( V_36 ) ;
return F_54 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , F_138 ( V_50 ) ,
& V_339 ) ;
}
static int F_144 ( struct V_20 * V_420 ,
unsigned int V_177 )
{
T_2 V_17 = F_23 () ;
T_2 V_421 = F_18 ( V_420 ) ;
if ( V_177 & V_422 )
return F_54 ( V_17 , V_421 , V_32 , V_392 , NULL ) ;
return F_54 ( V_17 , V_421 , V_423 , V_424 , NULL ) ;
}
static int F_145 ( struct V_20 * V_425 )
{
return F_54 ( F_18 ( V_425 ) , F_23 () , V_423 ,
V_424 , NULL ) ;
}
static int F_146 ( struct V_20 * V_426 , T_6 * V_427 ,
T_6 * V_428 , T_6 * V_429 )
{
return F_54 ( F_23 () , F_18 ( V_426 ) , V_423 ,
V_430 , NULL ) ;
}
static int F_147 ( struct V_10 * V_139 , const struct V_10 * V_138 ,
const T_6 * V_427 ,
const T_6 * V_428 ,
const T_6 * V_429 )
{
return F_54 ( F_17 ( V_138 ) , F_17 ( V_139 ) , V_423 ,
V_431 , NULL ) ;
}
static int F_148 ( const struct V_10 * V_10 , struct V_432 * V_433 ,
int V_335 , int V_336 )
{
return F_115 ( V_10 , V_335 , V_336 , V_433 == & V_131 ) ;
}
static int F_149 ( int V_434 , int type , int V_435 , struct V_56 * V_57 )
{
const struct V_10 * V_10 = F_75 () ;
int V_62 = 0 ;
if ( ! V_57 )
return 0 ;
switch ( V_434 ) {
case V_436 :
case V_437 :
case V_438 :
case V_439 :
case V_440 :
V_62 = F_135 ( V_10 , V_57 , V_441 , NULL ) ;
break;
case V_442 :
case V_443 :
case V_444 :
V_62 = F_135 ( V_10 , V_57 , V_445 , NULL ) ;
break;
default:
V_62 = 0 ;
break;
}
return V_62 ;
}
static int F_150 ( struct V_36 * V_36 )
{
const struct V_10 * V_10 = F_75 () ;
return F_123 ( V_10 , V_36 , V_446 ) ;
}
static int F_151 ( int type )
{
switch ( type ) {
case V_447 :
case V_448 :
return F_54 ( F_23 () , V_18 ,
V_449 , V_450 , NULL ) ;
case V_451 :
case V_452 :
case V_453 :
return F_54 ( F_23 () , V_18 ,
V_449 , V_454 ,
NULL ) ;
}
return F_54 ( F_23 () , V_18 ,
V_449 , V_455 , NULL ) ;
}
static int F_152 ( struct V_456 * V_457 , long V_458 )
{
int V_62 , V_459 = 0 ;
V_62 = F_115 ( F_75 () , V_460 ,
V_461 , true ) ;
if ( V_62 == 0 )
V_459 = 1 ;
return V_459 ;
}
static T_2 F_153 ( void )
{
T_2 V_17 = 0 ;
struct V_20 * V_462 ;
F_19 () ;
V_462 = F_154 ( V_11 ) ;
if ( V_462 )
V_17 = F_18 ( V_462 ) ;
F_21 () ;
return V_17 ;
}
static int F_155 ( const struct V_463 * V_464 ,
const struct V_13 * V_465 ,
const struct V_13 * V_466 )
{
int V_467 = ( V_464 -> V_468 & V_469 ) ;
int V_470 = ! F_156 ( V_464 -> V_50 -> V_419 . V_471 ) ;
int V_62 ;
if ( ! V_467 && ! V_470 )
return 0 ;
if ( V_466 -> V_17 == V_465 -> V_17 )
return 0 ;
V_62 = F_157 ( V_465 -> V_17 , V_466 -> V_17 ) ;
if ( V_62 ) {
if ( V_467 )
return - V_472 ;
else
return - V_132 ;
}
return 0 ;
}
static int F_158 ( struct V_463 * V_464 )
{
const struct V_13 * V_465 ;
struct V_13 * V_466 ;
struct V_23 * V_24 ;
struct V_338 V_339 ;
struct V_22 * V_22 = F_126 ( V_464 -> V_50 ) ;
int V_62 ;
if ( V_464 -> V_473 )
return 0 ;
V_465 = F_130 () ;
V_466 = V_464 -> V_10 -> V_19 ;
V_24 = F_33 ( V_22 ) ;
V_466 -> V_17 = V_465 -> V_17 ;
V_466 -> V_16 = V_465 -> V_17 ;
V_466 -> V_361 = 0 ;
V_466 -> V_474 = 0 ;
V_466 -> V_475 = 0 ;
if ( V_465 -> V_476 ) {
V_466 -> V_17 = V_465 -> V_476 ;
V_466 -> V_476 = 0 ;
V_62 = F_155 ( V_464 , V_465 , V_466 ) ;
if ( V_62 )
return V_62 ;
} else {
V_62 = F_79 ( V_465 -> V_17 , V_24 -> V_17 ,
V_423 , NULL ,
& V_466 -> V_17 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_155 ( V_464 , V_465 , V_466 ) ;
if ( V_62 )
V_466 -> V_17 = V_465 -> V_17 ;
}
V_339 . type = V_355 ;
V_339 . V_344 . V_50 = V_464 -> V_50 ;
if ( V_466 -> V_17 == V_465 -> V_17 ) {
V_62 = F_54 ( V_465 -> V_17 , V_24 -> V_17 ,
V_32 , V_477 , & V_339 ) ;
if ( V_62 )
return V_62 ;
} else {
V_62 = F_54 ( V_465 -> V_17 , V_466 -> V_17 ,
V_423 , V_478 , & V_339 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_54 ( V_466 -> V_17 , V_24 -> V_17 ,
V_32 , V_479 , & V_339 ) ;
if ( V_62 )
return V_62 ;
if ( V_464 -> V_468 & V_480 ) {
V_62 = F_54 ( V_465 -> V_17 , V_466 -> V_17 ,
V_423 , V_481 ,
NULL ) ;
if ( V_62 )
return - V_472 ;
}
if ( V_464 -> V_468 & V_482 ) {
T_2 V_483 = F_153 () ;
if ( V_483 != 0 ) {
V_62 = F_54 ( V_483 , V_466 -> V_17 ,
V_423 ,
V_424 , NULL ) ;
if ( V_62 )
return - V_472 ;
}
}
V_464 -> V_484 |= V_485 ;
}
return 0 ;
}
static int F_159 ( struct V_463 * V_464 )
{
const struct V_13 * V_14 = F_130 () ;
T_2 V_17 , V_16 ;
int V_486 = 0 ;
V_17 = V_14 -> V_17 ;
V_16 = V_14 -> V_16 ;
if ( V_16 != V_17 ) {
V_486 = F_54 ( V_16 , V_17 ,
V_423 ,
V_487 , NULL ) ;
}
return ! ! V_486 ;
}
static int F_160 ( const void * V_154 , struct V_50 * V_50 , unsigned V_488 )
{
return F_127 ( V_154 , V_50 , F_138 ( V_50 ) ) ? V_488 + 1 : 0 ;
}
static inline void F_161 ( const struct V_10 * V_10 ,
struct V_489 * V_490 )
{
struct V_50 * V_50 , * V_491 = NULL ;
struct V_492 * V_493 ;
int V_494 = 0 ;
unsigned V_495 ;
V_493 = F_162 () ;
if ( V_493 ) {
F_42 ( & V_493 -> V_496 ) ;
if ( ! F_61 ( & V_493 -> V_497 ) ) {
struct V_498 * V_499 ;
V_499 = F_163 ( & V_493 -> V_497 ,
struct V_498 , V_29 ) ;
V_50 = V_499 -> V_50 ;
if ( F_125 ( V_10 , V_50 , V_392 | V_396 ) )
V_494 = 1 ;
}
F_44 ( & V_493 -> V_496 ) ;
F_164 ( V_493 ) ;
}
if ( V_494 )
F_165 () ;
V_495 = F_166 ( V_490 , 0 , F_160 , V_10 ) ;
if ( ! V_495 )
return;
V_491 = F_167 ( & V_500 , V_501 , V_10 ) ;
if ( F_101 ( V_491 ) )
V_491 = NULL ;
do {
F_168 ( V_495 - 1 , V_491 , 0 ) ;
} while ( ( V_495 = F_166 ( V_490 , V_495 , F_160 , V_10 ) ) != 0 );
if ( V_491 )
F_169 ( V_491 ) ;
}
static void F_170 ( struct V_463 * V_464 )
{
struct V_13 * V_466 ;
struct V_502 * V_503 , * V_504 ;
int V_62 , V_95 ;
V_466 = V_464 -> V_10 -> V_19 ;
if ( V_466 -> V_17 == V_466 -> V_16 )
return;
F_161 ( V_464 -> V_10 , V_11 -> V_490 ) ;
V_11 -> V_505 = 0 ;
V_62 = F_54 ( V_466 -> V_16 , V_466 -> V_17 , V_423 ,
V_506 , NULL ) ;
if ( V_62 ) {
F_171 ( V_11 ) ;
for ( V_95 = 0 ; V_95 < V_507 ; V_95 ++ ) {
V_503 = V_11 -> signal -> V_503 + V_95 ;
V_504 = V_508 . signal -> V_503 + V_95 ;
V_503 -> V_509 = F_172 ( V_503 -> V_510 , V_504 -> V_509 ) ;
}
F_173 ( V_11 ) ;
if ( F_174 ( V_511 ) )
F_175 ( V_11 , V_502 ( V_512 ) ) ;
}
}
static void F_176 ( struct V_463 * V_464 )
{
const struct V_13 * V_14 = F_130 () ;
struct V_513 V_514 ;
T_2 V_16 , V_17 ;
int V_62 , V_95 ;
V_16 = V_14 -> V_16 ;
V_17 = V_14 -> V_17 ;
if ( V_17 == V_16 )
return;
V_62 = F_54 ( V_16 , V_17 , V_423 , V_515 , NULL ) ;
if ( V_62 ) {
if ( F_174 ( V_511 ) ) {
memset ( & V_514 , 0 , sizeof V_514 ) ;
for ( V_95 = 0 ; V_95 < 3 ; V_95 ++ )
F_177 ( V_95 , & V_514 , NULL ) ;
}
F_178 ( & V_11 -> V_516 -> V_517 ) ;
if ( ! F_179 ( V_11 ) ) {
F_180 ( & V_11 -> V_518 ) ;
F_180 ( & V_11 -> signal -> V_519 ) ;
F_181 ( V_11 , 1 ) ;
F_182 ( & V_11 -> V_520 ) ;
F_183 () ;
}
F_184 ( & V_11 -> V_516 -> V_517 ) ;
}
F_185 ( & V_521 ) ;
F_186 ( V_11 , V_11 -> V_522 ) ;
F_187 ( & V_521 ) ;
}
static int F_188 ( struct V_56 * V_57 )
{
return F_48 ( V_57 ) ;
}
static void F_189 ( struct V_56 * V_57 )
{
F_50 ( V_57 ) ;
}
static inline int F_190 ( char * V_170 , int V_523 , char * V_524 , int V_525 )
{
if ( V_523 > V_525 )
return 0 ;
return ! memcmp ( V_170 , V_524 , V_523 ) ;
}
static inline int F_191 ( char * V_524 , int V_97 )
{
return ( F_190 ( V_172 , sizeof( V_172 ) - 1 , V_524 , V_97 ) ||
F_190 ( V_173 , sizeof( V_173 ) - 1 , V_524 , V_97 ) ||
F_190 ( V_175 , sizeof( V_175 ) - 1 , V_524 , V_97 ) ||
F_190 ( V_174 , sizeof( V_174 ) - 1 , V_524 , V_97 ) ||
F_190 ( V_176 , sizeof( V_176 ) - 1 , V_524 , V_97 ) ) ;
}
static inline void F_192 ( char * * V_413 , char * V_412 , int * V_526 , int V_97 )
{
if ( ! * V_526 ) {
* * V_413 = ',' ;
* V_413 += 1 ;
} else
* V_526 = 0 ;
memcpy ( * V_413 , V_412 , V_97 ) ;
* V_413 += V_97 ;
}
static inline void F_193 ( char * * V_413 , char * V_412 , int * V_526 ,
int V_97 )
{
int V_527 = 0 ;
if ( ! * V_526 ) {
* * V_413 = '|' ;
* V_413 += 1 ;
} else
* V_526 = 0 ;
while ( V_527 < V_97 ) {
if ( * V_412 != '"' ) {
* * V_413 = * V_412 ;
* V_413 += 1 ;
}
V_412 += 1 ;
V_527 += 1 ;
}
}
static int F_194 ( char * V_528 , char * V_529 )
{
int V_530 , V_52 , V_62 = 0 ;
char * V_531 , * V_532 , * V_533 ;
char * V_534 , * V_535 , * V_536 ;
int V_537 = 0 ;
V_532 = V_528 ;
V_534 = V_529 ;
V_536 = ( char * ) F_195 ( V_15 ) ;
if ( ! V_536 ) {
V_62 = - V_27 ;
goto V_83;
}
V_535 = V_536 ;
V_530 = V_52 = 1 ;
V_531 = V_533 = V_528 ;
do {
if ( * V_533 == '"' )
V_537 = ! V_537 ;
if ( ( * V_533 == ',' && V_537 == 0 ) ||
* V_533 == '\0' ) {
int V_97 = V_533 - V_532 ;
if ( F_191 ( V_532 , V_97 ) )
F_193 ( & V_534 , V_532 , & V_52 , V_97 ) ;
else
F_192 ( & V_536 , V_532 , & V_530 , V_97 ) ;
V_532 = V_533 + 1 ;
}
} while ( * V_533 ++ );
strcpy ( V_531 , V_535 ) ;
F_104 ( ( unsigned long ) V_535 ) ;
V_83:
return V_62 ;
}
static int F_196 ( struct V_56 * V_57 , void * V_167 )
{
int V_62 , V_95 , * V_88 ;
struct V_93 V_94 ;
char * V_538 , * * V_122 ;
struct V_45 * V_46 = V_57 -> V_48 ;
if ( ! ( V_46 -> V_88 & V_89 ) )
return 0 ;
if ( ! V_167 )
return 0 ;
if ( V_57 -> V_72 -> V_124 & V_125 )
return 0 ;
F_67 ( & V_94 ) ;
V_538 = F_197 () ;
if ( ! V_538 )
return - V_27 ;
V_62 = F_194 ( V_167 , V_538 ) ;
if ( V_62 )
goto V_539;
V_62 = F_83 ( V_538 , & V_94 ) ;
if ( V_62 )
goto V_539;
V_122 = V_94 . V_103 ;
V_88 = V_94 . V_106 ;
for ( V_95 = 0 ; V_95 < V_94 . V_102 ; V_95 ++ ) {
T_2 V_17 ;
if ( V_88 [ V_95 ] == V_90 )
continue;
V_62 = F_77 ( V_122 [ V_95 ] , & V_17 , V_15 ) ;
if ( V_62 ) {
F_58 ( V_80 L_17
L_18 ,
V_122 [ V_95 ] , V_57 -> V_81 , V_57 -> V_72 -> V_73 , V_62 ) ;
goto V_540;
}
V_62 = - V_99 ;
switch ( V_88 [ V_95 ] ) {
case V_107 :
if ( F_73 ( V_46 , V_107 , V_46 -> V_17 , V_17 ) )
goto V_541;
break;
case V_108 :
if ( F_73 ( V_46 , V_108 , V_46 -> V_61 , V_17 ) )
goto V_541;
break;
case V_110 : {
struct V_23 * V_117 ;
V_117 = F_36 ( V_57 -> V_76 ) ;
if ( F_73 ( V_46 , V_110 , V_117 -> V_17 , V_17 ) )
goto V_541;
break;
}
case V_109 :
if ( F_73 ( V_46 , V_109 , V_46 -> V_59 , V_17 ) )
goto V_541;
break;
default:
goto V_540;
}
}
V_62 = 0 ;
V_540:
F_72 ( & V_94 ) ;
V_539:
F_198 ( V_538 ) ;
return V_62 ;
V_541:
F_58 ( V_80 L_43
L_44 , V_57 -> V_81 ,
V_57 -> V_72 -> V_73 ) ;
goto V_540;
}
static int F_199 ( struct V_56 * V_57 , int V_88 , void * V_167 )
{
const struct V_10 * V_10 = F_75 () ;
struct V_338 V_339 ;
int V_62 ;
V_62 = F_87 ( V_57 , V_167 ) ;
if ( V_62 )
return V_62 ;
if ( V_88 & V_542 )
return 0 ;
V_339 . type = V_353 ;
V_339 . V_344 . V_36 = V_57 -> V_76 ;
return F_135 ( V_10 , V_57 , V_543 , & V_339 ) ;
}
static int F_200 ( struct V_36 * V_36 )
{
const struct V_10 * V_10 = F_75 () ;
struct V_338 V_339 ;
V_339 . type = V_353 ;
V_339 . V_344 . V_36 = V_36 -> V_314 -> V_76 ;
return F_135 ( V_10 , V_36 -> V_314 , V_544 , & V_339 ) ;
}
static int F_201 ( const char * V_545 ,
const struct V_316 * V_316 ,
const char * type ,
unsigned long V_88 ,
void * V_167 )
{
const struct V_10 * V_10 = F_75 () ;
if ( V_88 & V_546 )
return F_135 ( V_10 , V_316 -> V_36 -> V_314 ,
V_547 , NULL ) ;
else
return F_124 ( V_10 , V_316 , V_548 ) ;
}
static int F_202 ( struct V_549 * V_471 , int V_88 )
{
const struct V_10 * V_10 = F_75 () ;
return F_135 ( V_10 , V_471 -> V_550 ,
V_551 , NULL ) ;
}
static int F_203 ( struct V_22 * V_22 )
{
return F_22 ( V_22 ) ;
}
static void F_204 ( struct V_22 * V_22 )
{
F_40 ( V_22 ) ;
}
static int F_205 ( struct V_36 * V_36 , int V_177 ,
const struct V_359 * V_73 , void * * V_552 ,
T_2 * V_553 )
{
T_2 V_363 ;
int V_62 ;
V_62 = F_128 ( F_130 () ,
F_206 ( V_36 -> V_554 ) , V_73 ,
F_94 ( V_177 ) ,
& V_363 ) ;
if ( V_62 )
return V_62 ;
return F_70 ( V_363 , ( char * * ) V_552 , V_553 ) ;
}
static int F_207 ( struct V_36 * V_36 , int V_177 ,
struct V_359 * V_73 ,
const struct V_10 * V_138 ,
struct V_10 * V_139 )
{
T_2 V_363 ;
int V_62 ;
struct V_13 * V_14 ;
V_62 = F_128 ( V_138 -> V_19 ,
F_206 ( V_36 -> V_554 ) , V_73 ,
F_94 ( V_177 ) ,
& V_363 ) ;
if ( V_62 )
return V_62 ;
V_14 = V_139 -> V_19 ;
V_14 -> V_361 = V_363 ;
return 0 ;
}
static int F_208 ( struct V_22 * V_22 , struct V_22 * V_358 ,
const struct V_359 * V_359 ,
const char * * V_73 ,
void * * V_555 , T_7 * V_97 )
{
const struct V_13 * V_14 = F_130 () ;
struct V_45 * V_46 ;
T_2 V_17 , V_363 , V_556 ;
int V_62 ;
char * V_96 ;
V_46 = V_358 -> V_47 -> V_48 ;
V_17 = V_14 -> V_17 ;
V_363 = V_14 -> V_361 ;
V_62 = F_128 ( F_130 () ,
V_358 , V_359 ,
F_94 ( V_22 -> V_319 ) ,
& V_363 ) ;
if ( V_62 )
return V_62 ;
if ( V_46 -> V_88 & V_89 ) {
struct V_23 * V_24 = V_22 -> V_35 ;
V_24 -> V_31 = F_94 ( V_22 -> V_319 ) ;
V_24 -> V_17 = V_363 ;
V_24 -> V_33 = V_40 ;
}
if ( ! V_39 || ! ( V_46 -> V_88 & V_90 ) )
return - V_82 ;
if ( V_73 )
* V_73 = V_557 ;
if ( V_555 && V_97 ) {
V_62 = F_209 ( V_363 , & V_96 , & V_556 ) ;
if ( V_62 )
return V_62 ;
* V_555 = V_96 ;
* V_97 = V_556 ;
}
return 0 ;
}
static int F_210 ( struct V_22 * V_358 , struct V_36 * V_36 , T_5 V_177 )
{
return F_129 ( V_358 , V_36 , V_32 ) ;
}
static int F_211 ( struct V_36 * V_377 , struct V_22 * V_358 , struct V_36 * V_379 )
{
return F_131 ( V_358 , V_377 , V_370 ) ;
}
static int F_212 ( struct V_22 * V_358 , struct V_36 * V_36 )
{
return F_131 ( V_358 , V_36 , V_372 ) ;
}
static int F_213 ( struct V_22 * V_358 , struct V_36 * V_36 , const char * V_73 )
{
return F_129 ( V_358 , V_36 , V_182 ) ;
}
static int F_214 ( struct V_22 * V_358 , struct V_36 * V_36 , T_5 V_388 )
{
return F_129 ( V_358 , V_36 , V_187 ) ;
}
static int F_215 ( struct V_22 * V_358 , struct V_36 * V_36 )
{
return F_131 ( V_358 , V_36 , V_374 ) ;
}
static int F_216 ( struct V_22 * V_358 , struct V_36 * V_36 , T_5 V_177 , T_8 V_323 )
{
return F_129 ( V_358 , V_36 , F_94 ( V_177 ) ) ;
}
static int F_217 ( struct V_22 * V_558 , struct V_36 * V_377 ,
struct V_22 * V_559 , struct V_36 * V_379 )
{
return F_132 ( V_558 , V_377 , V_559 , V_379 ) ;
}
static int F_218 ( struct V_36 * V_36 )
{
const struct V_10 * V_10 = F_75 () ;
return F_123 ( V_10 , V_36 , V_392 ) ;
}
static int F_219 ( struct V_36 * V_36 , struct V_22 * V_22 ,
bool V_42 )
{
const struct V_10 * V_10 = F_75 () ;
struct V_338 V_339 ;
struct V_23 * V_24 ;
T_2 V_17 ;
F_121 ( V_10 ) ;
V_339 . type = V_353 ;
V_339 . V_344 . V_36 = V_36 ;
V_17 = F_17 ( V_10 ) ;
V_24 = F_31 ( V_22 , V_42 ) ;
if ( F_101 ( V_24 ) )
return F_102 ( V_24 ) ;
return F_220 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_392 , & V_339 ,
V_42 ? V_560 : 0 ) ;
}
static T_9 int F_221 ( struct V_22 * V_22 ,
T_2 V_351 , T_2 V_561 , T_2 V_562 ,
int V_563 ,
unsigned V_88 )
{
struct V_338 V_339 ;
struct V_23 * V_24 = V_22 -> V_35 ;
int V_62 ;
V_339 . type = V_564 ;
V_339 . V_344 . V_22 = V_22 ;
V_62 = F_222 ( F_23 () , V_24 -> V_17 , V_24 -> V_31 , V_351 ,
V_561 , V_562 , V_563 , & V_339 , V_88 ) ;
if ( V_62 )
return V_62 ;
return 0 ;
}
static int F_223 ( struct V_22 * V_22 , int V_388 )
{
const struct V_10 * V_10 = F_75 () ;
T_2 V_351 ;
bool V_565 ;
unsigned V_88 = V_388 & V_560 ;
struct V_23 * V_24 ;
T_2 V_17 ;
struct V_340 V_341 ;
int V_62 , V_350 ;
T_2 V_561 , V_562 ;
V_565 = V_388 & V_566 ;
V_388 &= ( V_391 | V_395 | V_389 | V_393 ) ;
if ( ! V_388 )
return 0 ;
F_121 ( V_10 ) ;
if ( F_122 ( F_64 ( V_22 ) ) )
return 0 ;
V_351 = F_136 ( V_22 -> V_319 , V_388 ) ;
V_17 = F_17 ( V_10 ) ;
V_24 = F_31 ( V_22 , V_88 & V_560 ) ;
if ( F_101 ( V_24 ) )
return F_102 ( V_24 ) ;
V_62 = F_118 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_351 , 0 , & V_341 ) ;
V_561 = F_224 ( V_351 , & V_341 , V_62 ,
V_565 ? V_567 : 0 ,
& V_562 ) ;
if ( F_225 ( ! V_561 ) )
return V_62 ;
V_350 = F_221 ( V_22 , V_351 , V_561 , V_562 , V_62 , V_88 ) ;
if ( V_350 )
return V_350 ;
return V_62 ;
}
static int F_226 ( struct V_36 * V_36 , struct V_568 * V_568 )
{
const struct V_10 * V_10 = F_75 () ;
unsigned int V_569 = V_568 -> V_569 ;
T_10 V_342 = V_396 ;
if ( V_569 & V_570 ) {
V_569 &= ~ ( V_571 | V_572 | V_573 |
V_570 ) ;
if ( ! V_569 )
return 0 ;
}
if ( V_569 & ( V_573 | V_574 | V_575 |
V_576 | V_577 | V_578 ) )
return F_123 ( V_10 , V_36 , V_579 ) ;
if ( V_405 && ( V_569 & V_580 )
&& ! ( V_569 & V_581 ) )
V_342 |= V_406 ;
return F_123 ( V_10 , V_36 , V_342 ) ;
}
static int F_227 ( const struct V_316 * V_316 )
{
return F_124 ( F_75 () , V_316 , V_582 ) ;
}
static int F_228 ( struct V_36 * V_36 , const char * V_73 )
{
const struct V_10 * V_10 = F_75 () ;
if ( ! strncmp ( V_73 , V_583 ,
sizeof V_583 - 1 ) ) {
if ( ! strcmp ( V_73 , V_584 ) ) {
if ( ! F_229 ( V_585 ) )
return - V_472 ;
} else if ( ! F_229 ( V_460 ) ) {
return - V_472 ;
}
}
return F_123 ( V_10 , V_36 , V_579 ) ;
}
static int F_230 ( struct V_36 * V_36 , const char * V_73 ,
const void * V_555 , T_7 V_586 , int V_88 )
{
struct V_22 * V_22 = F_35 ( V_36 ) ;
struct V_23 * V_24 ;
struct V_45 * V_46 ;
struct V_338 V_339 ;
T_2 V_363 , V_17 = F_23 () ;
int V_62 = 0 ;
if ( strcmp ( V_73 , V_84 ) )
return F_228 ( V_36 , V_73 ) ;
V_46 = V_22 -> V_47 -> V_48 ;
if ( ! ( V_46 -> V_88 & V_90 ) )
return - V_82 ;
if ( ! F_231 ( V_22 ) )
return - V_472 ;
V_339 . type = V_353 ;
V_339 . V_344 . V_36 = V_36 ;
V_24 = F_36 ( V_36 ) ;
V_62 = F_54 ( V_17 , V_24 -> V_17 , V_24 -> V_31 ,
V_587 , & V_339 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_232 ( V_555 , V_586 , & V_363 , V_15 ) ;
if ( V_62 == - V_99 ) {
if ( ! F_229 ( V_588 ) ) {
struct V_589 * V_590 ;
T_7 V_591 ;
const char * V_1 ;
if ( V_555 ) {
V_1 = V_555 ;
if ( V_1 [ V_586 - 1 ] == '\0' )
V_591 = V_586 - 1 ;
else
V_591 = V_586 ;
} else {
V_1 = L_45 ;
V_591 = 0 ;
}
V_590 = F_233 ( V_11 -> V_592 , V_104 , V_593 ) ;
F_234 ( V_590 , L_46 ) ;
F_235 ( V_590 , V_555 , V_591 ) ;
F_236 ( V_590 ) ;
return V_62 ;
}
V_62 = F_237 ( V_555 , V_586 , & V_363 ) ;
}
if ( V_62 )
return V_62 ;
V_62 = F_54 ( V_17 , V_363 , V_24 -> V_31 ,
V_594 , & V_339 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_238 ( V_24 -> V_17 , V_363 , V_17 ,
V_24 -> V_31 ) ;
if ( V_62 )
return V_62 ;
return F_54 ( V_363 ,
V_46 -> V_17 ,
V_63 ,
V_66 ,
& V_339 ) ;
}
static void F_239 ( struct V_36 * V_36 , const char * V_73 ,
const void * V_555 , T_7 V_586 ,
int V_88 )
{
struct V_22 * V_22 = F_35 ( V_36 ) ;
struct V_23 * V_24 ;
T_2 V_363 ;
int V_62 ;
if ( strcmp ( V_73 , V_84 ) ) {
return;
}
V_62 = F_237 ( V_555 , V_586 , & V_363 ) ;
if ( V_62 ) {
F_58 ( V_87 L_47
L_48 ,
V_22 -> V_47 -> V_81 , V_22 -> V_322 , - V_62 ) ;
return;
}
V_24 = F_36 ( V_36 ) ;
F_42 ( & V_24 -> V_28 ) ;
V_24 -> V_31 = F_94 ( V_22 -> V_319 ) ;
V_24 -> V_17 = V_363 ;
V_24 -> V_33 = V_40 ;
F_44 ( & V_24 -> V_28 ) ;
return;
}
static int F_240 ( struct V_36 * V_36 , const char * V_73 )
{
const struct V_10 * V_10 = F_75 () ;
return F_123 ( V_10 , V_36 , V_582 ) ;
}
static int F_241 ( struct V_36 * V_36 )
{
const struct V_10 * V_10 = F_75 () ;
return F_123 ( V_10 , V_36 , V_582 ) ;
}
static int F_242 ( struct V_36 * V_36 , const char * V_73 )
{
if ( strcmp ( V_73 , V_84 ) )
return F_228 ( V_36 , V_73 ) ;
return - V_132 ;
}
static int F_243 ( struct V_22 * V_22 , const char * V_73 , void * * V_315 , bool V_595 )
{
T_2 V_586 ;
int error ;
char * V_96 = NULL ;
struct V_23 * V_24 ;
if ( strcmp ( V_73 , V_557 ) )
return - V_82 ;
error = F_244 ( F_75 () , & V_131 , V_588 ,
V_461 ) ;
if ( ! error )
error = F_115 ( F_75 () , V_588 ,
V_461 , true ) ;
V_24 = F_33 ( V_22 ) ;
if ( ! error )
error = F_209 ( V_24 -> V_17 , & V_96 ,
& V_586 ) ;
else
error = F_70 ( V_24 -> V_17 , & V_96 , & V_586 ) ;
if ( error )
return error ;
error = V_586 ;
if ( V_595 ) {
* V_315 = V_96 ;
goto V_596;
}
F_51 ( V_96 ) ;
V_596:
return error ;
}
static int F_245 ( struct V_22 * V_22 , const char * V_73 ,
const void * V_555 , T_7 V_586 , int V_88 )
{
struct V_23 * V_24 = F_30 ( V_22 ) ;
T_2 V_363 ;
int V_62 ;
if ( strcmp ( V_73 , V_557 ) )
return - V_82 ;
if ( ! V_555 || ! V_586 )
return - V_132 ;
V_62 = F_232 ( V_555 , V_586 , & V_363 , V_15 ) ;
if ( V_62 )
return V_62 ;
F_42 ( & V_24 -> V_28 ) ;
V_24 -> V_31 = F_94 ( V_22 -> V_319 ) ;
V_24 -> V_17 = V_363 ;
V_24 -> V_33 = V_40 ;
F_44 ( & V_24 -> V_28 ) ;
return 0 ;
}
static int F_246 ( struct V_22 * V_22 , char * V_315 , T_7 V_597 )
{
const int V_97 = sizeof( V_84 ) ;
if ( V_315 && V_97 <= V_597 )
memcpy ( V_315 , V_84 , V_97 ) ;
return V_97 ;
}
static void F_247 ( struct V_22 * V_22 , T_2 * V_598 )
{
struct V_23 * V_24 = F_30 ( V_22 ) ;
* V_598 = V_24 -> V_17 ;
}
static int F_248 ( struct V_36 * V_599 , struct V_10 * * V_139 )
{
T_2 V_17 ;
struct V_13 * V_14 ;
struct V_10 * V_600 = * V_139 ;
if ( V_600 == NULL ) {
V_600 = F_249 () ;
if ( ! V_600 )
return - V_27 ;
}
V_14 = V_600 -> V_19 ;
F_247 ( F_206 ( V_599 ) , & V_17 ) ;
V_14 -> V_361 = V_17 ;
* V_139 = V_600 ;
return 0 ;
}
static int F_250 ( const char * V_73 )
{
if ( strcmp ( V_73 , V_84 ) == 0 )
return 1 ;
return - V_82 ;
}
static int F_251 ( struct V_50 * V_50 , int V_388 )
{
const struct V_10 * V_10 = F_75 () ;
struct V_22 * V_22 = F_126 ( V_50 ) ;
if ( ( V_50 -> V_402 & V_403 ) && ( V_388 & V_395 ) )
V_388 |= V_393 ;
return F_127 ( V_10 , V_50 ,
F_136 ( V_22 -> V_319 , V_388 ) ) ;
}
static int F_252 ( struct V_50 * V_50 , int V_388 )
{
struct V_22 * V_22 = F_126 ( V_50 ) ;
struct V_51 * V_52 = V_50 -> V_55 ;
struct V_23 * V_24 ;
T_2 V_17 = F_23 () ;
if ( ! V_388 )
return 0 ;
V_24 = F_33 ( V_22 ) ;
if ( V_17 == V_52 -> V_17 && V_52 -> V_601 == V_24 -> V_17 &&
V_52 -> V_602 == F_253 () )
return 0 ;
return F_251 ( V_50 , V_388 ) ;
}
static int F_254 ( struct V_50 * V_50 )
{
return F_46 ( V_50 ) ;
}
static void F_255 ( struct V_50 * V_50 )
{
F_47 ( V_50 ) ;
}
static int F_256 ( const struct V_10 * V_10 , struct V_50 * V_50 ,
T_2 V_603 , T_4 V_604 )
{
struct V_338 V_339 ;
struct V_51 * V_52 = V_50 -> V_55 ;
struct V_22 * V_22 = F_126 ( V_50 ) ;
struct V_23 * V_24 ;
struct V_605 V_606 ;
T_2 V_607 = F_17 ( V_10 ) ;
int V_62 ;
T_11 V_608 = V_604 >> 8 ;
T_11 V_609 = V_604 & 0xff ;
V_339 . type = V_610 ;
V_339 . V_344 . V_611 = & V_606 ;
V_339 . V_344 . V_611 -> V_604 = V_604 ;
V_339 . V_344 . V_611 -> V_316 = V_50 -> V_419 ;
if ( V_607 != V_52 -> V_17 ) {
V_62 = F_54 ( V_607 , V_52 -> V_17 ,
V_356 ,
V_357 ,
& V_339 ) ;
if ( V_62 )
goto V_83;
}
if ( F_122 ( F_64 ( V_22 ) ) )
return 0 ;
V_24 = F_33 ( V_22 ) ;
V_62 = F_257 ( V_607 , V_24 -> V_17 , V_24 -> V_31 ,
V_603 , V_608 , V_609 , & V_339 ) ;
V_83:
return V_62 ;
}
static int F_258 ( struct V_50 * V_50 , unsigned int V_604 ,
unsigned long V_612 )
{
const struct V_10 * V_10 = F_75 () ;
int error = 0 ;
switch ( V_604 ) {
case V_613 :
case V_614 :
case V_615 :
case V_616 :
case V_617 :
error = F_127 ( V_10 , V_50 , V_582 ) ;
break;
case V_618 :
case V_619 :
error = F_127 ( V_10 , V_50 , V_579 ) ;
break;
case V_620 :
case V_621 :
error = F_127 ( V_10 , V_50 , 0 ) ;
break;
case V_622 :
case V_623 :
error = F_115 ( V_10 , V_624 ,
V_349 , true ) ;
break;
default:
error = F_256 ( V_10 , V_50 , V_404 , ( T_4 ) V_604 ) ;
}
return error ;
}
static int F_259 ( struct V_50 * V_50 , unsigned long V_625 , int V_626 )
{
const struct V_10 * V_10 = F_75 () ;
T_2 V_17 = F_17 ( V_10 ) ;
int V_62 = 0 ;
if ( V_627 &&
( V_625 & V_628 ) && ( ! V_50 || F_64 ( F_126 ( V_50 ) ) ||
( ! V_626 && ( V_625 & V_629 ) ) ) ) {
V_62 = F_54 ( V_17 , V_17 , V_423 ,
V_630 , NULL ) ;
if ( V_62 )
goto error;
}
if ( V_50 ) {
T_2 V_342 = V_392 ;
if ( V_626 && ( V_625 & V_629 ) )
V_342 |= V_396 ;
if ( V_625 & V_628 )
V_342 |= V_390 ;
return F_127 ( V_10 , V_50 , V_342 ) ;
}
error:
return V_62 ;
}
static int F_260 ( unsigned long V_631 )
{
int V_62 = 0 ;
if ( V_631 < V_632 ) {
T_2 V_17 = F_23 () ;
V_62 = F_54 ( V_17 , V_17 , V_633 ,
V_634 , NULL ) ;
}
return V_62 ;
}
static int F_261 ( struct V_50 * V_50 , unsigned long V_635 ,
unsigned long V_625 , unsigned long V_88 )
{
if ( V_636 )
V_625 = V_635 ;
return F_259 ( V_50 , V_625 ,
( V_88 & V_637 ) == V_638 ) ;
}
static int F_262 ( struct V_639 * V_640 ,
unsigned long V_635 ,
unsigned long V_625 )
{
const struct V_10 * V_10 = F_75 () ;
T_2 V_17 = F_17 ( V_10 ) ;
if ( V_636 )
V_625 = V_635 ;
if ( V_627 &&
( V_625 & V_628 ) && ! ( V_640 -> V_641 & V_642 ) ) {
int V_62 = 0 ;
if ( V_640 -> V_643 >= V_640 -> V_644 -> V_645 &&
V_640 -> V_646 <= V_640 -> V_644 -> V_647 ) {
V_62 = F_54 ( V_17 , V_17 , V_423 ,
V_648 , NULL ) ;
} else if ( ! V_640 -> V_649 &&
( ( V_640 -> V_643 <= V_640 -> V_644 -> V_650 &&
V_640 -> V_646 >= V_640 -> V_644 -> V_650 ) ||
F_263 ( V_640 ) ) ) {
V_62 = F_54 ( V_17 , V_17 , V_423 ,
V_651 , NULL ) ;
} else if ( V_640 -> V_649 && V_640 -> V_652 ) {
V_62 = F_127 ( V_10 , V_640 -> V_649 , V_653 ) ;
}
if ( V_62 )
return V_62 ;
}
return F_259 ( V_640 -> V_649 , V_625 , V_640 -> V_641 & V_654 ) ;
}
static int F_264 ( struct V_50 * V_50 , unsigned int V_604 )
{
const struct V_10 * V_10 = F_75 () ;
return F_127 ( V_10 , V_50 , V_655 ) ;
}
static int F_265 ( struct V_50 * V_50 , unsigned int V_604 ,
unsigned long V_612 )
{
const struct V_10 * V_10 = F_75 () ;
int V_656 = 0 ;
switch ( V_604 ) {
case V_657 :
if ( ( V_50 -> V_402 & V_403 ) && ! ( V_612 & V_403 ) ) {
V_656 = F_127 ( V_10 , V_50 , V_396 ) ;
break;
}
case V_658 :
case V_659 :
case V_660 :
case V_661 :
case V_662 :
case V_663 :
V_656 = F_127 ( V_10 , V_50 , 0 ) ;
break;
case V_664 :
case V_665 :
case V_666 :
case V_667 :
case V_668 :
case V_669 :
#if V_670 == 32
case V_671 :
case V_672 :
case V_673 :
#endif
V_656 = F_127 ( V_10 , V_50 , V_655 ) ;
break;
}
return V_656 ;
}
static void F_266 ( struct V_50 * V_50 )
{
struct V_51 * V_52 ;
V_52 = V_50 -> V_55 ;
V_52 -> V_54 = F_23 () ;
}
static int F_267 ( struct V_20 * V_674 ,
struct V_675 * V_676 , int V_677 )
{
struct V_50 * V_50 ;
T_2 V_17 = F_18 ( V_674 ) ;
T_2 V_327 ;
struct V_51 * V_52 ;
V_50 = F_38 ( V_676 , struct V_50 , V_678 ) ;
V_52 = V_50 -> V_55 ;
if ( ! V_677 )
V_327 = F_114 ( V_679 ) ;
else
V_327 = F_114 ( V_677 ) ;
return F_54 ( V_52 -> V_54 , V_17 ,
V_423 , V_327 , NULL ) ;
}
static int F_268 ( struct V_50 * V_50 )
{
const struct V_10 * V_10 = F_75 () ;
return F_127 ( V_10 , V_50 , F_138 ( V_50 ) ) ;
}
static int F_269 ( struct V_50 * V_50 , const struct V_10 * V_10 )
{
struct V_51 * V_52 ;
struct V_23 * V_24 ;
V_52 = V_50 -> V_55 ;
V_24 = F_33 ( F_126 ( V_50 ) ) ;
V_52 -> V_601 = V_24 -> V_17 ;
V_52 -> V_602 = F_253 () ;
return F_125 ( V_10 , V_50 , F_139 ( V_50 ) ) ;
}
static int F_270 ( unsigned long V_680 )
{
T_2 V_17 = F_23 () ;
return F_54 ( V_17 , V_17 , V_423 , V_681 , NULL ) ;
}
static int F_271 ( struct V_10 * V_10 , T_12 V_682 )
{
struct V_13 * V_14 ;
V_14 = F_15 ( sizeof( struct V_13 ) , V_682 ) ;
if ( ! V_14 )
return - V_27 ;
V_10 -> V_19 = V_14 ;
return 0 ;
}
static void F_272 ( struct V_10 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_19 ;
F_71 ( V_10 -> V_19 && ( unsigned long ) V_10 -> V_19 < V_317 ) ;
V_10 -> V_19 = ( void * ) 0x7UL ;
F_51 ( V_14 ) ;
}
static int F_273 ( struct V_10 * V_139 , const struct V_10 * V_138 ,
T_12 V_682 )
{
const struct V_13 * V_465 ;
struct V_13 * V_14 ;
V_465 = V_138 -> V_19 ;
V_14 = F_274 ( V_465 , sizeof( struct V_13 ) , V_682 ) ;
if ( ! V_14 )
return - V_27 ;
V_139 -> V_19 = V_14 ;
return 0 ;
}
static void F_275 ( struct V_10 * V_139 , const struct V_10 * V_138 )
{
const struct V_13 * V_465 = V_138 -> V_19 ;
struct V_13 * V_14 = V_139 -> V_19 ;
* V_14 = * V_465 ;
}
static int F_276 ( struct V_10 * V_139 , T_2 V_598 )
{
struct V_13 * V_14 = V_139 -> V_19 ;
T_2 V_17 = F_23 () ;
int V_683 ;
V_683 = F_54 ( V_17 , V_598 ,
V_684 ,
V_685 ,
NULL ) ;
if ( V_683 == 0 ) {
V_14 -> V_17 = V_598 ;
V_14 -> V_361 = 0 ;
V_14 -> V_474 = 0 ;
V_14 -> V_475 = 0 ;
}
return V_683 ;
}
static int F_277 ( struct V_10 * V_139 , struct V_22 * V_22 )
{
struct V_23 * V_24 = F_33 ( V_22 ) ;
struct V_13 * V_14 = V_139 -> V_19 ;
T_2 V_17 = F_23 () ;
int V_683 ;
V_683 = F_54 ( V_17 , V_24 -> V_17 ,
V_684 ,
V_686 ,
NULL ) ;
if ( V_683 == 0 )
V_14 -> V_361 = V_24 -> V_17 ;
return V_683 ;
}
static int F_278 ( char * V_687 )
{
struct V_338 V_339 ;
V_339 . type = V_688 ;
V_339 . V_344 . V_687 = V_687 ;
return F_54 ( F_23 () , V_18 , V_449 ,
V_689 , & V_339 ) ;
}
static int F_279 ( struct V_50 * V_50 )
{
struct V_338 V_339 ;
struct V_23 * V_24 ;
struct V_51 * V_52 ;
T_2 V_17 = F_23 () ;
int V_62 ;
if ( V_50 == NULL )
return F_54 ( V_17 , V_17 , V_449 ,
V_690 , NULL ) ;
V_339 . type = V_355 ;
V_339 . V_344 . V_50 = V_50 ;
V_52 = V_50 -> V_55 ;
if ( V_17 != V_52 -> V_17 ) {
V_62 = F_54 ( V_17 , V_52 -> V_17 , V_356 , V_357 , & V_339 ) ;
if ( V_62 )
return V_62 ;
}
V_24 = F_33 ( F_126 ( V_50 ) ) ;
return F_54 ( V_17 , V_24 -> V_17 , V_449 ,
V_690 , & V_339 ) ;
}
static int F_280 ( struct V_50 * V_50 ,
enum V_691 V_435 )
{
int V_62 = 0 ;
switch ( V_435 ) {
case V_692 :
V_62 = F_279 ( V_50 ) ;
break;
default:
break;
}
return V_62 ;
}
static int F_281 ( struct V_20 * V_154 , T_13 V_693 )
{
return F_54 ( F_23 () , F_18 ( V_154 ) , V_423 ,
V_694 , NULL ) ;
}
static int F_282 ( struct V_20 * V_154 )
{
return F_54 ( F_23 () , F_18 ( V_154 ) , V_423 ,
V_695 , NULL ) ;
}
static int F_283 ( struct V_20 * V_154 )
{
return F_54 ( F_23 () , F_18 ( V_154 ) , V_423 ,
V_696 , NULL ) ;
}
static void F_284 ( struct V_20 * V_154 , T_2 * V_598 )
{
* V_598 = F_18 ( V_154 ) ;
}
static int F_285 ( struct V_20 * V_154 , int V_697 )
{
return F_54 ( F_23 () , F_18 ( V_154 ) , V_423 ,
V_698 , NULL ) ;
}
static int F_286 ( struct V_20 * V_154 , int V_699 )
{
return F_54 ( F_23 () , F_18 ( V_154 ) , V_423 ,
V_698 , NULL ) ;
}
static int F_287 ( struct V_20 * V_154 )
{
return F_54 ( F_23 () , F_18 ( V_154 ) , V_423 ,
V_700 , NULL ) ;
}
static int F_288 ( struct V_20 * V_154 , unsigned int V_701 ,
struct V_502 * V_702 )
{
struct V_502 * V_703 = V_154 -> signal -> V_503 + V_701 ;
if ( V_703 -> V_510 != V_702 -> V_510 )
return F_54 ( F_23 () , F_18 ( V_154 ) ,
V_423 , V_704 , NULL ) ;
return 0 ;
}
static int F_289 ( struct V_20 * V_154 )
{
return F_54 ( F_23 () , F_18 ( V_154 ) , V_423 ,
V_698 , NULL ) ;
}
static int F_290 ( struct V_20 * V_154 )
{
return F_54 ( F_23 () , F_18 ( V_154 ) , V_423 ,
V_700 , NULL ) ;
}
static int F_291 ( struct V_20 * V_154 )
{
return F_54 ( F_23 () , F_18 ( V_154 ) , V_423 ,
V_698 , NULL ) ;
}
static int F_292 ( struct V_20 * V_154 , struct V_705 * V_706 ,
int V_326 , T_2 V_598 )
{
T_2 V_327 ;
if ( ! V_326 )
V_327 = V_707 ;
else
V_327 = F_114 ( V_326 ) ;
if ( ! V_598 )
V_598 = F_23 () ;
return F_54 ( V_598 , F_18 ( V_154 ) , V_423 , V_327 , NULL ) ;
}
static void F_293 ( struct V_20 * V_154 ,
struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_35 ;
T_2 V_17 = F_18 ( V_154 ) ;
F_42 ( & V_24 -> V_28 ) ;
V_24 -> V_31 = F_94 ( V_22 -> V_319 ) ;
V_24 -> V_17 = V_17 ;
V_24 -> V_33 = V_40 ;
F_44 ( & V_24 -> V_28 ) ;
}
static int F_294 ( struct V_708 * V_709 ,
struct V_338 * V_339 , T_11 * V_710 )
{
int V_711 , V_712 , V_683 = - V_99 ;
struct V_713 V_714 , * V_715 ;
V_711 = F_295 ( V_709 ) ;
V_715 = F_296 ( V_709 , V_711 , sizeof( V_714 ) , & V_714 ) ;
if ( V_715 == NULL )
goto V_83;
V_712 = V_715 -> V_716 * 4 ;
if ( V_712 < sizeof( V_714 ) )
goto V_83;
V_339 -> V_344 . V_717 -> V_718 . V_719 = V_715 -> V_719 ;
V_339 -> V_344 . V_717 -> V_718 . V_720 = V_715 -> V_720 ;
V_683 = 0 ;
if ( V_710 )
* V_710 = V_715 -> V_192 ;
switch ( V_715 -> V_192 ) {
case V_194 : {
struct V_721 V_722 , * V_723 ;
if ( F_297 ( V_715 -> V_724 ) & V_725 )
break;
V_711 += V_712 ;
V_723 = F_296 ( V_709 , V_711 , sizeof( V_722 ) , & V_722 ) ;
if ( V_723 == NULL )
break;
V_339 -> V_344 . V_717 -> V_726 = V_723 -> V_727 ;
V_339 -> V_344 . V_717 -> V_728 = V_723 -> V_729 ;
break;
}
case V_195 : {
struct V_730 V_731 , * V_732 ;
if ( F_297 ( V_715 -> V_724 ) & V_725 )
break;
V_711 += V_712 ;
V_732 = F_296 ( V_709 , V_711 , sizeof( V_731 ) , & V_731 ) ;
if ( V_732 == NULL )
break;
V_339 -> V_344 . V_717 -> V_726 = V_732 -> V_727 ;
V_339 -> V_344 . V_717 -> V_728 = V_732 -> V_729 ;
break;
}
case V_733 : {
struct V_734 V_735 , * V_736 ;
if ( F_297 ( V_715 -> V_724 ) & V_725 )
break;
V_711 += V_712 ;
V_736 = F_296 ( V_709 , V_711 , sizeof( V_735 ) , & V_735 ) ;
if ( V_736 == NULL )
break;
V_339 -> V_344 . V_717 -> V_726 = V_736 -> V_737 ;
V_339 -> V_344 . V_717 -> V_728 = V_736 -> V_738 ;
break;
}
default:
break;
}
V_83:
return V_683 ;
}
static int F_298 ( struct V_708 * V_709 ,
struct V_338 * V_339 , T_11 * V_710 )
{
T_11 V_739 ;
int V_683 = - V_99 , V_711 ;
struct V_740 V_741 , * V_742 ;
T_14 V_724 ;
V_711 = F_295 ( V_709 ) ;
V_742 = F_296 ( V_709 , V_711 , sizeof( V_741 ) , & V_741 ) ;
if ( V_742 == NULL )
goto V_83;
V_339 -> V_344 . V_717 -> V_743 . V_719 = V_742 -> V_719 ;
V_339 -> V_344 . V_717 -> V_743 . V_720 = V_742 -> V_720 ;
V_683 = 0 ;
V_739 = V_742 -> V_739 ;
V_711 += sizeof( V_741 ) ;
V_711 = F_299 ( V_709 , V_711 , & V_739 , & V_724 ) ;
if ( V_711 < 0 )
goto V_83;
if ( V_710 )
* V_710 = V_739 ;
switch ( V_739 ) {
case V_194 : {
struct V_721 V_722 , * V_723 ;
V_723 = F_296 ( V_709 , V_711 , sizeof( V_722 ) , & V_722 ) ;
if ( V_723 == NULL )
break;
V_339 -> V_344 . V_717 -> V_726 = V_723 -> V_727 ;
V_339 -> V_344 . V_717 -> V_728 = V_723 -> V_729 ;
break;
}
case V_195 : {
struct V_730 V_731 , * V_732 ;
V_732 = F_296 ( V_709 , V_711 , sizeof( V_731 ) , & V_731 ) ;
if ( V_732 == NULL )
break;
V_339 -> V_344 . V_717 -> V_726 = V_732 -> V_727 ;
V_339 -> V_344 . V_717 -> V_728 = V_732 -> V_729 ;
break;
}
case V_733 : {
struct V_734 V_735 , * V_736 ;
V_736 = F_296 ( V_709 , V_711 , sizeof( V_735 ) , & V_735 ) ;
if ( V_736 == NULL )
break;
V_339 -> V_344 . V_717 -> V_726 = V_736 -> V_737 ;
V_339 -> V_344 . V_717 -> V_728 = V_736 -> V_738 ;
break;
}
default:
break;
}
V_83:
return V_683 ;
}
static int F_300 ( struct V_708 * V_709 , struct V_338 * V_339 ,
char * * V_744 , int V_599 , T_11 * V_710 )
{
char * V_745 ;
int V_683 ;
switch ( V_339 -> V_344 . V_717 -> V_196 ) {
case V_205 :
V_683 = F_294 ( V_709 , V_339 , V_710 ) ;
if ( V_683 )
goto V_746;
V_745 = ( char * ) ( V_599 ? & V_339 -> V_344 . V_717 -> V_718 . V_719 :
& V_339 -> V_344 . V_717 -> V_718 . V_720 ) ;
goto V_747;
#if F_174 ( V_748 )
case V_206 :
V_683 = F_298 ( V_709 , V_339 , V_710 ) ;
if ( V_683 )
goto V_746;
V_745 = ( char * ) ( V_599 ? & V_339 -> V_344 . V_717 -> V_743 . V_719 :
& V_339 -> V_344 . V_717 -> V_743 . V_720 ) ;
goto V_747;
#endif
default:
V_745 = NULL ;
goto V_747;
}
V_746:
F_58 ( V_80
L_49
L_50 ) ;
return V_683 ;
V_747:
if ( V_744 )
* V_744 = V_745 ;
return 0 ;
}
static int F_301 ( struct V_708 * V_709 , T_4 V_196 , T_2 * V_17 )
{
int V_656 ;
T_2 V_749 ;
T_2 V_750 ;
T_2 V_751 ;
V_656 = F_302 ( V_709 , & V_749 ) ;
if ( F_122 ( V_656 ) )
return - V_132 ;
V_656 = F_303 ( V_709 , V_196 , & V_751 , & V_750 ) ;
if ( F_122 ( V_656 ) )
return - V_132 ;
V_656 = F_304 ( V_750 , V_751 , V_749 , V_17 ) ;
if ( F_122 ( V_656 ) ) {
F_58 ( V_80
L_51
L_52 ) ;
return - V_132 ;
}
return 0 ;
}
static int F_305 ( T_2 V_752 , T_2 V_753 , T_2 * V_754 )
{
int V_656 = 0 ;
if ( V_753 != V_755 )
V_656 = F_306 ( V_752 , V_753 , V_754 ) ;
else
* V_754 = V_752 ;
return V_656 ;
}
static int F_307 ( const struct V_13 * V_14 ,
T_4 V_756 , T_2 * V_757 )
{
if ( V_14 -> V_475 > V_755 ) {
* V_757 = V_14 -> V_475 ;
return 0 ;
}
return F_79 ( V_14 -> V_17 , V_14 -> V_17 , V_756 , NULL ,
V_757 ) ;
}
static int F_308 ( struct V_758 * V_759 , T_2 V_351 )
{
struct V_760 * V_761 = V_759 -> V_762 ;
struct V_338 V_339 ;
struct V_763 V_717 = { 0 ,} ;
if ( V_761 -> V_17 == V_18 )
return 0 ;
V_339 . type = V_764 ;
V_339 . V_344 . V_717 = & V_717 ;
V_339 . V_344 . V_717 -> V_759 = V_759 ;
return F_54 ( F_23 () , V_761 -> V_17 , V_761 -> V_31 , V_351 ,
& V_339 ) ;
}
static int F_309 ( int V_196 , int type ,
int V_192 , int V_765 )
{
const struct V_13 * V_14 = F_130 () ;
T_2 V_363 ;
T_4 V_756 ;
int V_62 ;
if ( V_765 )
return 0 ;
V_756 = F_97 ( V_196 , type , V_192 ) ;
V_62 = F_307 ( V_14 , V_756 , & V_363 ) ;
if ( V_62 )
return V_62 ;
return F_54 ( V_14 -> V_17 , V_363 , V_756 , V_766 , NULL ) ;
}
static int F_310 ( struct V_767 * V_758 , int V_196 ,
int type , int V_192 , int V_765 )
{
const struct V_13 * V_14 = F_130 () ;
struct V_23 * V_24 = F_30 ( F_311 ( V_758 ) ) ;
struct V_760 * V_761 ;
T_4 V_31 = F_97 ( V_196 , type , V_192 ) ;
T_2 V_17 = V_18 ;
int V_656 = 0 ;
if ( ! V_765 ) {
V_656 = F_307 ( V_14 , V_31 , & V_17 ) ;
if ( V_656 )
return V_656 ;
}
V_24 -> V_31 = V_31 ;
V_24 -> V_17 = V_17 ;
V_24 -> V_33 = V_40 ;
if ( V_758 -> V_759 ) {
V_761 = V_758 -> V_759 -> V_762 ;
V_761 -> V_31 = V_31 ;
V_761 -> V_17 = V_17 ;
V_656 = F_312 ( V_758 -> V_759 , V_196 ) ;
}
return V_656 ;
}
static int F_313 ( struct V_767 * V_758 , struct V_768 * V_769 , int V_770 )
{
struct V_758 * V_759 = V_758 -> V_759 ;
T_4 V_196 ;
int V_656 ;
V_656 = F_308 ( V_759 , V_771 ) ;
if ( V_656 )
goto V_83;
V_196 = V_759 -> V_772 ;
if ( V_196 == V_205 || V_196 == V_206 ) {
char * V_745 ;
struct V_760 * V_761 = V_759 -> V_762 ;
struct V_338 V_339 ;
struct V_763 V_717 = { 0 ,} ;
struct V_773 * V_774 = NULL ;
struct V_775 * V_776 = NULL ;
unsigned short V_777 ;
T_2 V_17 , V_778 ;
if ( V_196 == V_205 ) {
V_774 = (struct V_773 * ) V_769 ;
V_777 = F_297 ( V_774 -> V_779 ) ;
V_745 = ( char * ) & V_774 -> V_780 . V_781 ;
} else {
V_776 = (struct V_775 * ) V_769 ;
V_777 = F_297 ( V_776 -> V_782 ) ;
V_745 = ( char * ) & V_776 -> V_783 . V_784 ;
}
if ( V_777 ) {
int V_785 , V_786 ;
F_314 ( F_315 ( V_759 ) , & V_785 , & V_786 ) ;
if ( V_777 < V_787 ( V_788 ( F_315 ( V_759 ) ), V_785 ) ||
V_777 > V_786 ) {
V_656 = F_316 ( V_759 -> V_789 ,
V_777 , & V_17 ) ;
if ( V_656 )
goto V_83;
V_339 . type = V_764 ;
V_339 . V_344 . V_717 = & V_717 ;
V_339 . V_344 . V_717 -> V_726 = F_317 ( V_777 ) ;
V_339 . V_344 . V_717 -> V_196 = V_196 ;
V_656 = F_54 ( V_761 -> V_17 , V_17 ,
V_761 -> V_31 ,
V_790 , & V_339 ) ;
if ( V_656 )
goto V_83;
}
}
switch ( V_761 -> V_31 ) {
case V_207 :
V_778 = V_791 ;
break;
case V_211 :
V_778 = V_792 ;
break;
case V_216 :
V_778 = V_793 ;
break;
default:
V_778 = V_794 ;
break;
}
V_656 = F_318 ( V_745 , V_196 , & V_17 ) ;
if ( V_656 )
goto V_83;
V_339 . type = V_764 ;
V_339 . V_344 . V_717 = & V_717 ;
V_339 . V_344 . V_717 -> V_726 = F_317 ( V_777 ) ;
V_339 . V_344 . V_717 -> V_196 = V_196 ;
if ( V_196 == V_205 )
V_339 . V_344 . V_717 -> V_718 . V_719 = V_774 -> V_780 . V_781 ;
else
V_339 . V_344 . V_717 -> V_743 . V_719 = V_776 -> V_783 ;
V_656 = F_54 ( V_761 -> V_17 , V_17 ,
V_761 -> V_31 , V_778 , & V_339 ) ;
if ( V_656 )
goto V_83;
}
V_83:
return V_656 ;
}
static int F_319 ( struct V_767 * V_758 , struct V_768 * V_769 , int V_770 )
{
struct V_758 * V_759 = V_758 -> V_759 ;
struct V_760 * V_761 = V_759 -> V_762 ;
int V_656 ;
V_656 = F_308 ( V_759 , V_795 ) ;
if ( V_656 )
return V_656 ;
if ( V_761 -> V_31 == V_207 ||
V_761 -> V_31 == V_216 ) {
struct V_338 V_339 ;
struct V_763 V_717 = { 0 ,} ;
struct V_773 * V_774 = NULL ;
struct V_775 * V_776 = NULL ;
unsigned short V_777 ;
T_2 V_17 , V_327 ;
if ( V_759 -> V_772 == V_205 ) {
V_774 = (struct V_773 * ) V_769 ;
if ( V_770 < sizeof( struct V_773 ) )
return - V_99 ;
V_777 = F_297 ( V_774 -> V_779 ) ;
} else {
V_776 = (struct V_775 * ) V_769 ;
if ( V_770 < V_796 )
return - V_99 ;
V_777 = F_297 ( V_776 -> V_782 ) ;
}
V_656 = F_316 ( V_759 -> V_789 , V_777 , & V_17 ) ;
if ( V_656 )
goto V_83;
V_327 = ( V_761 -> V_31 == V_207 ) ?
V_797 : V_798 ;
V_339 . type = V_764 ;
V_339 . V_344 . V_717 = & V_717 ;
V_339 . V_344 . V_717 -> V_728 = F_317 ( V_777 ) ;
V_339 . V_344 . V_717 -> V_196 = V_759 -> V_772 ;
V_656 = F_54 ( V_761 -> V_17 , V_17 , V_761 -> V_31 , V_327 , & V_339 ) ;
if ( V_656 )
goto V_83;
}
V_656 = F_320 ( V_759 , V_769 ) ;
V_83:
return V_656 ;
}
static int F_321 ( struct V_767 * V_758 , int V_799 )
{
return F_308 ( V_758 -> V_759 , V_800 ) ;
}
static int F_322 ( struct V_767 * V_758 , struct V_767 * V_801 )
{
int V_656 ;
struct V_23 * V_24 ;
struct V_23 * V_151 ;
T_4 V_31 ;
T_2 V_17 ;
V_656 = F_308 ( V_758 -> V_759 , V_802 ) ;
if ( V_656 )
return V_656 ;
V_24 = F_30 ( F_311 ( V_758 ) ) ;
F_42 ( & V_24 -> V_28 ) ;
V_31 = V_24 -> V_31 ;
V_17 = V_24 -> V_17 ;
F_44 ( & V_24 -> V_28 ) ;
V_151 = F_30 ( F_311 ( V_801 ) ) ;
V_151 -> V_31 = V_31 ;
V_151 -> V_17 = V_17 ;
V_151 -> V_33 = V_40 ;
return 0 ;
}
static int F_323 ( struct V_767 * V_758 , struct V_803 * V_804 ,
int V_586 )
{
return F_308 ( V_758 -> V_759 , V_805 ) ;
}
static int F_324 ( struct V_767 * V_758 , struct V_803 * V_804 ,
int V_586 , int V_88 )
{
return F_308 ( V_758 -> V_759 , V_806 ) ;
}
static int F_325 ( struct V_767 * V_758 )
{
return F_308 ( V_758 -> V_759 , V_807 ) ;
}
static int F_326 ( struct V_767 * V_758 )
{
return F_308 ( V_758 -> V_759 , V_807 ) ;
}
static int F_327 ( struct V_767 * V_758 , int V_808 , int V_809 )
{
int V_656 ;
V_656 = F_308 ( V_758 -> V_759 , V_810 ) ;
if ( V_656 )
return V_656 ;
return F_328 ( V_758 , V_808 , V_809 ) ;
}
static int F_329 ( struct V_767 * V_758 , int V_808 ,
int V_809 )
{
return F_308 ( V_758 -> V_759 , V_811 ) ;
}
static int F_330 ( struct V_767 * V_758 , int V_812 )
{
return F_308 ( V_758 -> V_759 , V_813 ) ;
}
static int F_331 ( struct V_758 * V_758 ,
struct V_758 * V_814 ,
struct V_758 * V_815 )
{
struct V_760 * V_816 = V_758 -> V_762 ;
struct V_760 * V_817 = V_814 -> V_762 ;
struct V_760 * V_818 = V_815 -> V_762 ;
struct V_338 V_339 ;
struct V_763 V_717 = { 0 ,} ;
int V_656 ;
V_339 . type = V_764 ;
V_339 . V_344 . V_717 = & V_717 ;
V_339 . V_344 . V_717 -> V_759 = V_814 ;
V_656 = F_54 ( V_816 -> V_17 , V_817 -> V_17 ,
V_817 -> V_31 ,
V_819 , & V_339 ) ;
if ( V_656 )
return V_656 ;
V_818 -> V_820 = V_816 -> V_17 ;
V_656 = F_306 ( V_817 -> V_17 , V_816 -> V_17 ,
& V_818 -> V_17 ) ;
if ( V_656 )
return V_656 ;
V_816 -> V_820 = V_818 -> V_17 ;
return 0 ;
}
static int F_332 ( struct V_767 * V_758 ,
struct V_767 * V_814 )
{
struct V_760 * V_821 = V_758 -> V_759 -> V_762 ;
struct V_760 * V_822 = V_814 -> V_759 -> V_762 ;
struct V_338 V_339 ;
struct V_763 V_717 = { 0 ,} ;
V_339 . type = V_764 ;
V_339 . V_344 . V_717 = & V_717 ;
V_339 . V_344 . V_717 -> V_759 = V_814 -> V_759 ;
return F_54 ( V_821 -> V_17 , V_822 -> V_17 , V_822 -> V_31 , V_823 ,
& V_339 ) ;
}
static int F_333 ( struct V_717 * V_433 , int V_824 ,
char * V_745 , T_4 V_196 , T_2 V_820 ,
struct V_338 * V_339 )
{
int V_656 ;
T_2 V_825 ;
T_2 V_826 ;
V_656 = F_334 ( V_433 , V_824 , & V_825 ) ;
if ( V_656 )
return V_656 ;
V_656 = F_54 ( V_820 , V_825 ,
V_827 , V_828 , V_339 ) ;
if ( V_656 )
return V_656 ;
V_656 = F_318 ( V_745 , V_196 , & V_826 ) ;
if ( V_656 )
return V_656 ;
return F_54 ( V_820 , V_826 ,
V_829 , V_830 , V_339 ) ;
}
static int F_335 ( struct V_758 * V_759 , struct V_708 * V_709 ,
T_4 V_196 )
{
int V_656 = 0 ;
struct V_760 * V_761 = V_759 -> V_762 ;
T_2 V_752 = V_761 -> V_17 ;
struct V_338 V_339 ;
struct V_763 V_717 = { 0 ,} ;
char * V_745 ;
V_339 . type = V_764 ;
V_339 . V_344 . V_717 = & V_717 ;
V_339 . V_344 . V_717 -> V_831 = V_709 -> V_832 ;
V_339 . V_344 . V_717 -> V_196 = V_196 ;
V_656 = F_300 ( V_709 , & V_339 , & V_745 , 1 , NULL ) ;
if ( V_656 )
return V_656 ;
if ( F_4 () ) {
V_656 = F_54 ( V_752 , V_709 -> V_833 , V_834 ,
V_835 , & V_339 ) ;
if ( V_656 )
return V_656 ;
}
V_656 = F_336 ( V_761 , V_709 , V_196 , & V_339 ) ;
if ( V_656 )
return V_656 ;
V_656 = F_337 ( V_761 -> V_17 , V_709 , & V_339 ) ;
return V_656 ;
}
static int F_338 ( struct V_758 * V_759 , struct V_708 * V_709 )
{
int V_656 ;
struct V_760 * V_761 = V_759 -> V_762 ;
T_4 V_196 = V_759 -> V_772 ;
T_2 V_752 = V_761 -> V_17 ;
struct V_338 V_339 ;
struct V_763 V_717 = { 0 ,} ;
char * V_745 ;
T_11 V_836 ;
T_11 V_837 ;
if ( V_196 != V_205 && V_196 != V_206 )
return 0 ;
if ( V_196 == V_206 && V_709 -> V_192 == F_317 ( V_838 ) )
V_196 = V_205 ;
if ( ! V_839 )
return F_335 ( V_759 , V_709 , V_196 ) ;
V_836 = F_4 () ;
V_837 = F_6 () ;
if ( ! V_836 && ! V_837 )
return 0 ;
V_339 . type = V_764 ;
V_339 . V_344 . V_717 = & V_717 ;
V_339 . V_344 . V_717 -> V_831 = V_709 -> V_832 ;
V_339 . V_344 . V_717 -> V_196 = V_196 ;
V_656 = F_300 ( V_709 , & V_339 , & V_745 , 1 , NULL ) ;
if ( V_656 )
return V_656 ;
if ( V_837 ) {
T_2 V_820 ;
V_656 = F_301 ( V_709 , V_196 , & V_820 ) ;
if ( V_656 )
return V_656 ;
V_656 = F_333 ( F_315 ( V_759 ) , V_709 -> V_832 ,
V_745 , V_196 , V_820 , & V_339 ) ;
if ( V_656 ) {
F_339 ( V_709 , V_196 , V_656 , 0 ) ;
return V_656 ;
}
V_656 = F_54 ( V_752 , V_820 , V_840 ,
V_841 , & V_339 ) ;
if ( V_656 ) {
F_339 ( V_709 , V_196 , V_656 , 0 ) ;
return V_656 ;
}
}
if ( V_836 ) {
V_656 = F_54 ( V_752 , V_709 -> V_833 , V_834 ,
V_835 , & V_339 ) ;
if ( V_656 )
return V_656 ;
}
return V_656 ;
}
static int F_340 ( struct V_767 * V_758 , char T_15 * V_842 ,
int T_15 * V_843 , unsigned V_97 )
{
int V_656 = 0 ;
char * V_844 ;
T_2 V_845 ;
struct V_760 * V_761 = V_758 -> V_759 -> V_762 ;
T_2 V_820 = V_755 ;
if ( V_761 -> V_31 == V_202 ||
V_761 -> V_31 == V_207 )
V_820 = V_761 -> V_820 ;
if ( V_820 == V_755 )
return - V_846 ;
V_656 = F_70 ( V_820 , & V_844 , & V_845 ) ;
if ( V_656 )
return V_656 ;
if ( V_845 > V_97 ) {
V_656 = - V_321 ;
goto V_847;
}
if ( F_341 ( V_842 , V_844 , V_845 ) )
V_656 = - V_848 ;
V_847:
if ( F_342 ( V_845 , V_843 ) )
V_656 = - V_848 ;
F_51 ( V_844 ) ;
return V_656 ;
}
static int F_343 ( struct V_767 * V_758 , struct V_708 * V_709 , T_2 * V_598 )
{
T_2 V_849 = V_755 ;
T_4 V_196 ;
struct V_23 * V_24 ;
if ( V_709 && V_709 -> V_192 == F_317 ( V_838 ) )
V_196 = V_205 ;
else if ( V_709 && V_709 -> V_192 == F_317 ( V_850 ) )
V_196 = V_206 ;
else if ( V_758 )
V_196 = V_758 -> V_759 -> V_772 ;
else
goto V_83;
if ( V_758 && V_196 == V_199 ) {
V_24 = F_30 ( F_311 ( V_758 ) ) ;
V_849 = V_24 -> V_17 ;
} else if ( V_709 )
F_301 ( V_709 , V_196 , & V_849 ) ;
V_83:
* V_598 = V_849 ;
if ( V_849 == V_755 )
return - V_99 ;
return 0 ;
}
static int F_344 ( struct V_758 * V_759 , int V_196 , T_12 V_851 )
{
struct V_760 * V_761 ;
V_761 = F_15 ( sizeof( * V_761 ) , V_851 ) ;
if ( ! V_761 )
return - V_27 ;
V_761 -> V_820 = V_30 ;
V_761 -> V_17 = V_30 ;
V_761 -> V_31 = V_312 ;
F_345 ( V_761 ) ;
V_759 -> V_762 = V_761 ;
return 0 ;
}
static void F_346 ( struct V_758 * V_759 )
{
struct V_760 * V_761 = V_759 -> V_762 ;
V_759 -> V_762 = NULL ;
F_347 ( V_761 ) ;
F_51 ( V_761 ) ;
}
static void F_348 ( const struct V_758 * V_759 , struct V_758 * V_815 )
{
struct V_760 * V_761 = V_759 -> V_762 ;
struct V_760 * V_852 = V_815 -> V_762 ;
V_852 -> V_17 = V_761 -> V_17 ;
V_852 -> V_820 = V_761 -> V_820 ;
V_852 -> V_31 = V_761 -> V_31 ;
F_345 ( V_852 ) ;
}
static void F_349 ( struct V_758 * V_759 , T_2 * V_598 )
{
if ( ! V_759 )
* V_598 = V_853 ;
else {
struct V_760 * V_761 = V_759 -> V_762 ;
* V_598 = V_761 -> V_17 ;
}
}
static void F_350 ( struct V_758 * V_759 , struct V_767 * V_425 )
{
struct V_23 * V_24 =
F_30 ( F_311 ( V_425 ) ) ;
struct V_760 * V_761 = V_759 -> V_762 ;
if ( V_759 -> V_772 == V_205 || V_759 -> V_772 == V_206 ||
V_759 -> V_772 == V_199 )
V_24 -> V_17 = V_761 -> V_17 ;
V_761 -> V_31 = V_24 -> V_31 ;
}
static int F_351 ( struct V_758 * V_759 , struct V_708 * V_709 ,
struct V_854 * V_855 )
{
struct V_760 * V_761 = V_759 -> V_762 ;
int V_656 ;
T_4 V_196 = V_855 -> V_856 -> V_196 ;
T_2 V_857 ;
T_2 V_858 ;
V_656 = F_301 ( V_709 , V_196 , & V_858 ) ;
if ( V_656 )
return V_656 ;
V_656 = F_305 ( V_761 -> V_17 , V_858 , & V_857 ) ;
if ( V_656 )
return V_656 ;
V_855 -> V_598 = V_857 ;
V_855 -> V_849 = V_858 ;
return F_352 ( V_855 , V_196 ) ;
}
static void F_353 ( struct V_758 * V_815 ,
const struct V_854 * V_855 )
{
struct V_760 * V_852 = V_815 -> V_762 ;
V_852 -> V_17 = V_855 -> V_598 ;
V_852 -> V_820 = V_855 -> V_849 ;
F_354 ( V_815 , V_855 -> V_856 -> V_196 ) ;
}
static void F_355 ( struct V_758 * V_759 , struct V_708 * V_709 )
{
T_4 V_196 = V_759 -> V_772 ;
struct V_760 * V_761 = V_759 -> V_762 ;
if ( V_196 == V_206 && V_709 -> V_192 == F_317 ( V_838 ) )
V_196 = V_205 ;
F_301 ( V_709 , V_196 , & V_761 -> V_820 ) ;
}
static int F_356 ( T_2 V_17 )
{
const struct V_13 * V_859 ;
T_2 V_860 ;
V_859 = F_130 () ;
V_860 = V_859 -> V_17 ;
return F_54 ( V_860 , V_17 , V_834 , V_861 , NULL ) ;
}
static void F_357 ( void )
{
F_358 ( & V_7 ) ;
}
static void F_359 ( void )
{
F_360 ( & V_7 ) ;
}
static void F_361 ( const struct V_854 * V_855 ,
struct V_862 * V_863 )
{
V_863 -> V_864 = V_855 -> V_598 ;
}
static int F_362 ( void * * V_19 )
{
struct V_865 * V_866 ;
V_866 = F_15 ( sizeof( * V_866 ) , V_15 ) ;
if ( ! V_866 )
return - V_27 ;
V_866 -> V_17 = F_23 () ;
* V_19 = V_866 ;
return 0 ;
}
static void F_363 ( void * V_19 )
{
F_51 ( V_19 ) ;
}
static int F_364 ( void )
{
T_2 V_17 = F_23 () ;
return F_54 ( V_17 , V_17 , V_867 , V_868 ,
NULL ) ;
}
static int F_365 ( void * V_19 )
{
struct V_865 * V_866 = V_19 ;
return F_54 ( F_23 () , V_866 -> V_17 , V_867 ,
V_869 , NULL ) ;
}
static int F_366 ( struct V_758 * V_759 , void * V_19 )
{
struct V_865 * V_866 = V_19 ;
struct V_760 * V_761 = V_759 -> V_762 ;
V_761 -> V_17 = V_866 -> V_17 ;
V_761 -> V_31 = V_867 ;
return 0 ;
}
static int F_367 ( void * V_19 )
{
struct V_865 * V_866 = V_19 ;
T_2 V_17 = F_23 () ;
int V_656 ;
V_656 = F_54 ( V_17 , V_866 -> V_17 , V_867 ,
V_870 , NULL ) ;
if ( V_656 )
return V_656 ;
V_656 = F_54 ( V_17 , V_17 , V_867 ,
V_871 , NULL ) ;
if ( V_656 )
return V_656 ;
V_866 -> V_17 = V_17 ;
return 0 ;
}
static int F_368 ( struct V_758 * V_759 , struct V_708 * V_709 )
{
int V_656 = 0 ;
T_2 V_327 ;
struct V_872 * V_873 ;
struct V_760 * V_761 = V_759 -> V_762 ;
if ( V_709 -> V_97 < V_874 ) {
V_656 = - V_99 ;
goto V_83;
}
V_873 = F_369 ( V_709 ) ;
V_656 = F_370 ( V_761 -> V_31 , V_873 -> V_875 , & V_327 ) ;
if ( V_656 ) {
if ( V_656 == - V_99 ) {
F_371 ( L_53
L_54
L_55 ,
V_759 -> V_789 , V_873 -> V_875 ,
V_876 [ V_761 -> V_31 - 1 ] . V_73 ,
F_372 ( V_11 ) , V_11 -> V_877 ) ;
if ( ! V_3 || F_373 () )
V_656 = 0 ;
}
if ( V_656 == - V_878 )
V_656 = 0 ;
goto V_83;
}
V_656 = F_308 ( V_759 , V_327 ) ;
V_83:
return V_656 ;
}
static unsigned int F_374 ( struct V_708 * V_709 ,
const struct V_879 * V_880 ,
T_4 V_196 )
{
int V_656 ;
char * V_745 ;
T_2 V_820 ;
struct V_338 V_339 ;
struct V_763 V_717 = { 0 ,} ;
T_11 V_836 ;
T_11 V_881 ;
T_11 V_837 ;
if ( ! V_839 )
return V_882 ;
V_836 = F_4 () ;
V_881 = F_7 () ;
V_837 = F_6 () ;
if ( ! V_836 && ! V_837 )
return V_882 ;
if ( F_301 ( V_709 , V_196 , & V_820 ) != 0 )
return V_883 ;
V_339 . type = V_764 ;
V_339 . V_344 . V_717 = & V_717 ;
V_339 . V_344 . V_717 -> V_831 = V_880 -> V_824 ;
V_339 . V_344 . V_717 -> V_196 = V_196 ;
if ( F_300 ( V_709 , & V_339 , & V_745 , 1 , NULL ) != 0 )
return V_883 ;
if ( V_837 ) {
V_656 = F_333 ( F_375 ( V_880 ) , V_880 -> V_824 ,
V_745 , V_196 , V_820 , & V_339 ) ;
if ( V_656 ) {
F_339 ( V_709 , V_196 , V_656 , 1 ) ;
return V_883 ;
}
}
if ( V_836 )
if ( F_54 ( V_820 , V_709 -> V_833 ,
V_834 , V_884 , & V_339 ) )
return V_883 ;
if ( V_881 )
if ( F_376 ( V_709 , V_196 , V_820 ) != 0 )
return V_883 ;
return V_882 ;
}
static unsigned int F_377 ( void * V_885 ,
struct V_708 * V_709 ,
const struct V_886 * V_887 )
{
return F_374 ( V_709 , V_887 -> V_888 , V_205 ) ;
}
static unsigned int F_378 ( void * V_885 ,
struct V_708 * V_709 ,
const struct V_886 * V_887 )
{
return F_374 ( V_709 , V_887 -> V_888 , V_206 ) ;
}
static unsigned int F_379 ( struct V_708 * V_709 ,
T_4 V_196 )
{
struct V_758 * V_759 ;
T_2 V_17 ;
if ( ! F_7 () )
return V_882 ;
V_759 = V_709 -> V_759 ;
if ( V_759 ) {
struct V_760 * V_761 ;
if ( F_380 ( V_759 ) )
return V_882 ;
V_761 = V_759 -> V_762 ;
V_17 = V_761 -> V_17 ;
} else
V_17 = V_18 ;
if ( F_376 ( V_709 , V_196 , V_17 ) != 0 )
return V_883 ;
return V_882 ;
}
static unsigned int F_381 ( void * V_885 ,
struct V_708 * V_709 ,
const struct V_886 * V_887 )
{
return F_379 ( V_709 , V_205 ) ;
}
static unsigned int F_382 ( void * V_885 ,
struct V_708 * V_709 ,
const struct V_886 * V_887 )
{
return F_379 ( V_709 , V_206 ) ;
}
static unsigned int F_383 ( struct V_708 * V_709 ,
int V_824 ,
T_4 V_196 )
{
struct V_758 * V_759 = F_384 ( V_709 ) ;
struct V_760 * V_761 ;
struct V_338 V_339 ;
struct V_763 V_717 = { 0 ,} ;
char * V_745 ;
T_11 V_710 ;
if ( V_759 == NULL )
return V_882 ;
V_761 = V_759 -> V_762 ;
V_339 . type = V_764 ;
V_339 . V_344 . V_717 = & V_717 ;
V_339 . V_344 . V_717 -> V_831 = V_824 ;
V_339 . V_344 . V_717 -> V_196 = V_196 ;
if ( F_300 ( V_709 , & V_339 , & V_745 , 0 , & V_710 ) )
return V_883 ;
if ( F_4 () )
if ( F_54 ( V_761 -> V_17 , V_709 -> V_833 ,
V_834 , V_889 , & V_339 ) )
return F_385 ( - V_890 ) ;
if ( F_386 ( V_761 -> V_17 , V_709 , & V_339 , V_710 ) )
return F_385 ( - V_890 ) ;
return V_882 ;
}
static unsigned int F_387 ( struct V_708 * V_709 ,
const struct V_879 * V_891 ,
T_4 V_196 )
{
T_2 V_892 ;
T_2 V_820 ;
int V_824 = V_891 -> V_824 ;
struct V_758 * V_759 ;
struct V_338 V_339 ;
struct V_763 V_717 = { 0 ,} ;
char * V_745 ;
T_11 V_836 ;
T_11 V_837 ;
if ( ! V_839 )
return F_383 ( V_709 , V_824 , V_196 ) ;
V_836 = F_4 () ;
V_837 = F_6 () ;
if ( ! V_836 && ! V_837 )
return V_882 ;
V_759 = F_384 ( V_709 ) ;
#ifdef F_388
if ( F_389 ( V_709 ) != NULL && F_389 ( V_709 ) -> V_893 != NULL &&
! ( V_759 && F_380 ( V_759 ) ) )
return V_882 ;
#endif
if ( V_759 == NULL ) {
if ( V_709 -> V_832 ) {
V_892 = V_894 ;
if ( F_301 ( V_709 , V_196 , & V_820 ) )
return V_883 ;
} else {
V_892 = V_889 ;
V_820 = V_18 ;
}
} else if ( F_380 ( V_759 ) ) {
T_2 V_753 ;
struct V_760 * V_761 ;
V_761 = V_759 -> V_762 ;
if ( F_301 ( V_709 , V_196 , & V_753 ) )
return V_883 ;
if ( V_753 == V_755 ) {
switch ( V_196 ) {
case V_205 :
if ( F_390 ( V_709 ) -> V_88 & V_895 )
return V_882 ;
break;
case V_206 :
if ( F_391 ( V_709 ) -> V_88 & V_896 )
return V_882 ;
break;
default:
return F_385 ( - V_890 ) ;
}
}
if ( F_305 ( V_761 -> V_17 , V_753 , & V_820 ) )
return V_883 ;
V_892 = V_889 ;
} else {
struct V_760 * V_761 = V_759 -> V_762 ;
V_820 = V_761 -> V_17 ;
V_892 = V_889 ;
}
V_339 . type = V_764 ;
V_339 . V_344 . V_717 = & V_717 ;
V_339 . V_344 . V_717 -> V_831 = V_824 ;
V_339 . V_344 . V_717 -> V_196 = V_196 ;
if ( F_300 ( V_709 , & V_339 , & V_745 , 0 , NULL ) )
return V_883 ;
if ( V_836 )
if ( F_54 ( V_820 , V_709 -> V_833 ,
V_834 , V_892 , & V_339 ) )
return F_385 ( - V_890 ) ;
if ( V_837 ) {
T_2 V_825 ;
T_2 V_826 ;
if ( F_334 ( F_375 ( V_891 ) , V_824 , & V_825 ) )
return V_883 ;
if ( F_54 ( V_820 , V_825 ,
V_827 , V_897 , & V_339 ) )
return F_385 ( - V_890 ) ;
if ( F_318 ( V_745 , V_196 , & V_826 ) )
return V_883 ;
if ( F_54 ( V_820 , V_826 ,
V_829 , V_898 , & V_339 ) )
return F_385 ( - V_890 ) ;
}
return V_882 ;
}
static unsigned int F_392 ( void * V_885 ,
struct V_708 * V_709 ,
const struct V_886 * V_887 )
{
return F_387 ( V_709 , V_887 -> V_83 , V_205 ) ;
}
static unsigned int F_393 ( void * V_885 ,
struct V_708 * V_709 ,
const struct V_886 * V_887 )
{
return F_387 ( V_709 , V_887 -> V_83 , V_206 ) ;
}
static int F_394 ( struct V_758 * V_759 , struct V_708 * V_709 )
{
return F_368 ( V_759 , V_709 ) ;
}
static int F_395 ( struct V_899 * V_327 ,
T_4 V_31 )
{
struct V_900 * V_24 ;
V_24 = F_15 ( sizeof( struct V_900 ) , V_15 ) ;
if ( ! V_24 )
return - V_27 ;
V_24 -> V_31 = V_31 ;
V_24 -> V_17 = F_23 () ;
V_327 -> V_19 = V_24 ;
return 0 ;
}
static void F_396 ( struct V_899 * V_327 )
{
struct V_900 * V_24 = V_327 -> V_19 ;
V_327 -> V_19 = NULL ;
F_51 ( V_24 ) ;
}
static int F_397 ( struct V_901 * V_804 )
{
struct V_902 * V_903 ;
V_903 = F_15 ( sizeof( struct V_902 ) , V_15 ) ;
if ( ! V_903 )
return - V_27 ;
V_903 -> V_17 = V_30 ;
V_804 -> V_19 = V_903 ;
return 0 ;
}
static void F_398 ( struct V_901 * V_804 )
{
struct V_902 * V_903 = V_804 -> V_19 ;
V_804 -> V_19 = NULL ;
F_51 ( V_903 ) ;
}
static int F_399 ( struct V_899 * V_904 ,
T_2 V_351 )
{
struct V_900 * V_24 ;
struct V_338 V_339 ;
T_2 V_17 = F_23 () ;
V_24 = V_904 -> V_19 ;
V_339 . type = V_905 ;
V_339 . V_344 . V_906 = V_904 -> V_907 ;
return F_54 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_351 , & V_339 ) ;
}
static int F_400 ( struct V_901 * V_804 )
{
return F_397 ( V_804 ) ;
}
static void F_401 ( struct V_901 * V_804 )
{
F_398 ( V_804 ) ;
}
static int F_402 ( struct V_908 * V_909 )
{
struct V_900 * V_24 ;
struct V_338 V_339 ;
T_2 V_17 = F_23 () ;
int V_62 ;
V_62 = F_395 ( & V_909 -> V_910 , V_911 ) ;
if ( V_62 )
return V_62 ;
V_24 = V_909 -> V_910 . V_19 ;
V_339 . type = V_905 ;
V_339 . V_344 . V_906 = V_909 -> V_910 . V_907 ;
V_62 = F_54 ( V_17 , V_24 -> V_17 , V_911 ,
V_912 , & V_339 ) ;
if ( V_62 ) {
F_396 ( & V_909 -> V_910 ) ;
return V_62 ;
}
return 0 ;
}
static void F_403 ( struct V_908 * V_909 )
{
F_396 ( & V_909 -> V_910 ) ;
}
static int F_404 ( struct V_908 * V_909 , int V_913 )
{
struct V_900 * V_24 ;
struct V_338 V_339 ;
T_2 V_17 = F_23 () ;
V_24 = V_909 -> V_910 . V_19 ;
V_339 . type = V_905 ;
V_339 . V_344 . V_906 = V_909 -> V_910 . V_907 ;
return F_54 ( V_17 , V_24 -> V_17 , V_911 ,
V_914 , & V_339 ) ;
}
static int F_405 ( struct V_908 * V_909 , int V_604 )
{
int V_656 ;
int V_351 ;
switch ( V_604 ) {
case V_915 :
case V_916 :
return F_54 ( F_23 () , V_18 ,
V_449 , V_917 , NULL ) ;
case V_918 :
case V_919 :
V_351 = V_920 | V_914 ;
break;
case V_921 :
V_351 = V_922 ;
break;
case V_923 :
V_351 = V_924 ;
break;
default:
return 0 ;
}
V_656 = F_399 ( & V_909 -> V_910 , V_351 ) ;
return V_656 ;
}
static int F_406 ( struct V_908 * V_909 , struct V_901 * V_804 , int V_913 )
{
struct V_900 * V_24 ;
struct V_902 * V_903 ;
struct V_338 V_339 ;
T_2 V_17 = F_23 () ;
int V_62 ;
V_24 = V_909 -> V_910 . V_19 ;
V_903 = V_804 -> V_19 ;
if ( V_903 -> V_17 == V_30 ) {
V_62 = F_79 ( V_17 , V_24 -> V_17 , V_925 ,
NULL , & V_903 -> V_17 ) ;
if ( V_62 )
return V_62 ;
}
V_339 . type = V_905 ;
V_339 . V_344 . V_906 = V_909 -> V_910 . V_907 ;
V_62 = F_54 ( V_17 , V_24 -> V_17 , V_911 ,
V_926 , & V_339 ) ;
if ( ! V_62 )
V_62 = F_54 ( V_17 , V_903 -> V_17 , V_925 ,
V_927 , & V_339 ) ;
if ( ! V_62 )
V_62 = F_54 ( V_903 -> V_17 , V_24 -> V_17 , V_911 ,
V_928 , & V_339 ) ;
return V_62 ;
}
static int F_407 ( struct V_908 * V_909 , struct V_901 * V_804 ,
struct V_20 * V_426 ,
long type , int V_177 )
{
struct V_900 * V_24 ;
struct V_902 * V_903 ;
struct V_338 V_339 ;
T_2 V_17 = F_18 ( V_426 ) ;
int V_62 ;
V_24 = V_909 -> V_910 . V_19 ;
V_903 = V_804 -> V_19 ;
V_339 . type = V_905 ;
V_339 . V_344 . V_906 = V_909 -> V_910 . V_907 ;
V_62 = F_54 ( V_17 , V_24 -> V_17 ,
V_911 , V_929 , & V_339 ) ;
if ( ! V_62 )
V_62 = F_54 ( V_17 , V_903 -> V_17 ,
V_925 , V_930 , & V_339 ) ;
return V_62 ;
}
static int F_408 ( struct V_931 * V_932 )
{
struct V_900 * V_24 ;
struct V_338 V_339 ;
T_2 V_17 = F_23 () ;
int V_62 ;
V_62 = F_395 ( & V_932 -> V_933 , V_934 ) ;
if ( V_62 )
return V_62 ;
V_24 = V_932 -> V_933 . V_19 ;
V_339 . type = V_905 ;
V_339 . V_344 . V_906 = V_932 -> V_933 . V_907 ;
V_62 = F_54 ( V_17 , V_24 -> V_17 , V_934 ,
V_935 , & V_339 ) ;
if ( V_62 ) {
F_396 ( & V_932 -> V_933 ) ;
return V_62 ;
}
return 0 ;
}
static void F_409 ( struct V_931 * V_932 )
{
F_396 ( & V_932 -> V_933 ) ;
}
static int F_410 ( struct V_931 * V_932 , int V_936 )
{
struct V_900 * V_24 ;
struct V_338 V_339 ;
T_2 V_17 = F_23 () ;
V_24 = V_932 -> V_933 . V_19 ;
V_339 . type = V_905 ;
V_339 . V_344 . V_906 = V_932 -> V_933 . V_907 ;
return F_54 ( V_17 , V_24 -> V_17 , V_934 ,
V_937 , & V_339 ) ;
}
static int F_411 ( struct V_931 * V_932 , int V_604 )
{
int V_351 ;
int V_656 ;
switch ( V_604 ) {
case V_915 :
case V_938 :
return F_54 ( F_23 () , V_18 ,
V_449 , V_917 , NULL ) ;
case V_918 :
case V_939 :
V_351 = V_940 | V_937 ;
break;
case V_921 :
V_351 = V_941 ;
break;
case V_942 :
case V_943 :
V_351 = V_944 ;
break;
case V_923 :
V_351 = V_945 ;
break;
default:
return 0 ;
}
V_656 = F_399 ( & V_932 -> V_933 , V_351 ) ;
return V_656 ;
}
static int F_412 ( struct V_931 * V_932 ,
char T_15 * V_946 , int V_936 )
{
T_2 V_351 ;
if ( V_936 & V_947 )
V_351 = V_948 ;
else
V_351 = V_948 | V_949 ;
return F_399 ( & V_932 -> V_933 , V_351 ) ;
}
static int F_413 ( struct V_950 * V_951 )
{
struct V_900 * V_24 ;
struct V_338 V_339 ;
T_2 V_17 = F_23 () ;
int V_62 ;
V_62 = F_395 ( & V_951 -> V_952 , V_953 ) ;
if ( V_62 )
return V_62 ;
V_24 = V_951 -> V_952 . V_19 ;
V_339 . type = V_905 ;
V_339 . V_344 . V_906 = V_951 -> V_952 . V_907 ;
V_62 = F_54 ( V_17 , V_24 -> V_17 , V_953 ,
V_954 , & V_339 ) ;
if ( V_62 ) {
F_396 ( & V_951 -> V_952 ) ;
return V_62 ;
}
return 0 ;
}
static void F_414 ( struct V_950 * V_951 )
{
F_396 ( & V_951 -> V_952 ) ;
}
static int F_415 ( struct V_950 * V_951 , int V_955 )
{
struct V_900 * V_24 ;
struct V_338 V_339 ;
T_2 V_17 = F_23 () ;
V_24 = V_951 -> V_952 . V_19 ;
V_339 . type = V_905 ;
V_339 . V_344 . V_906 = V_951 -> V_952 . V_907 ;
return F_54 ( V_17 , V_24 -> V_17 , V_953 ,
V_956 , & V_339 ) ;
}
static int F_416 ( struct V_950 * V_951 , int V_604 )
{
int V_656 ;
T_2 V_351 ;
switch ( V_604 ) {
case V_915 :
case V_957 :
return F_54 ( F_23 () , V_18 ,
V_449 , V_917 , NULL ) ;
case V_958 :
case V_959 :
case V_960 :
V_351 = V_961 ;
break;
case V_962 :
case V_963 :
V_351 = V_964 ;
break;
case V_965 :
case V_966 :
V_351 = V_967 ;
break;
case V_923 :
V_351 = V_968 ;
break;
case V_921 :
V_351 = V_969 ;
break;
case V_918 :
case V_970 :
V_351 = V_961 | V_956 ;
break;
default:
return 0 ;
}
V_656 = F_399 ( & V_951 -> V_952 , V_351 ) ;
return V_656 ;
}
static int F_417 ( struct V_950 * V_951 ,
struct V_971 * V_972 , unsigned V_973 , int V_974 )
{
T_2 V_351 ;
if ( V_974 )
V_351 = V_964 | V_967 ;
else
V_351 = V_964 ;
return F_399 ( & V_951 -> V_952 , V_351 ) ;
}
static int F_418 ( struct V_899 * V_975 , short V_111 )
{
T_2 V_342 = 0 ;
V_342 = 0 ;
if ( V_111 & V_976 )
V_342 |= V_977 ;
if ( V_111 & V_978 )
V_342 |= V_979 ;
if ( V_342 == 0 )
return 0 ;
return F_399 ( V_975 , V_342 ) ;
}
static void F_419 ( struct V_899 * V_975 , T_2 * V_598 )
{
struct V_900 * V_24 = V_975 -> V_19 ;
* V_598 = V_24 -> V_17 ;
}
static void F_420 ( struct V_36 * V_36 , struct V_22 * V_22 )
{
if ( V_22 )
F_29 ( V_22 , V_36 ) ;
}
static int F_421 ( struct V_20 * V_154 ,
char * V_73 , char * * V_555 )
{
const struct V_13 * V_859 ;
T_2 V_17 ;
int error ;
unsigned V_97 ;
F_19 () ;
V_859 = F_20 ( V_154 ) -> V_19 ;
if ( V_11 != V_154 ) {
error = F_54 ( F_23 () , V_859 -> V_17 ,
V_423 , V_980 , NULL ) ;
if ( error )
goto V_981;
}
if ( ! strcmp ( V_73 , L_56 ) )
V_17 = V_859 -> V_17 ;
else if ( ! strcmp ( V_73 , L_57 ) )
V_17 = V_859 -> V_16 ;
else if ( ! strcmp ( V_73 , L_58 ) )
V_17 = V_859 -> V_476 ;
else if ( ! strcmp ( V_73 , L_59 ) )
V_17 = V_859 -> V_361 ;
else if ( ! strcmp ( V_73 , L_60 ) )
V_17 = V_859 -> V_474 ;
else if ( ! strcmp ( V_73 , L_61 ) )
V_17 = V_859 -> V_475 ;
else {
error = - V_99 ;
goto V_981;
}
F_21 () ;
if ( ! V_17 )
return 0 ;
error = F_70 ( V_17 , V_555 , & V_97 ) ;
if ( error )
return error ;
return V_97 ;
V_981:
F_21 () ;
return error ;
}
static int F_422 ( const char * V_73 , void * V_555 , T_7 V_586 )
{
struct V_13 * V_14 ;
struct V_10 * V_139 ;
T_2 V_408 = F_23 () , V_17 = 0 , V_483 ;
int error ;
char * V_1 = V_555 ;
if ( ! strcmp ( V_73 , L_58 ) )
error = F_54 ( V_408 , V_408 , V_423 ,
V_982 , NULL ) ;
else if ( ! strcmp ( V_73 , L_59 ) )
error = F_54 ( V_408 , V_408 , V_423 ,
V_983 , NULL ) ;
else if ( ! strcmp ( V_73 , L_60 ) )
error = F_54 ( V_408 , V_408 , V_423 ,
V_984 , NULL ) ;
else if ( ! strcmp ( V_73 , L_61 ) )
error = F_54 ( V_408 , V_408 , V_423 ,
V_985 , NULL ) ;
else if ( ! strcmp ( V_73 , L_56 ) )
error = F_54 ( V_408 , V_408 , V_423 ,
V_986 , NULL ) ;
else
error = - V_99 ;
if ( error )
return error ;
if ( V_586 && V_1 [ 0 ] && V_1 [ 0 ] != '\n' ) {
if ( V_1 [ V_586 - 1 ] == '\n' ) {
V_1 [ V_586 - 1 ] = 0 ;
V_586 -- ;
}
error = F_232 ( V_555 , V_586 , & V_17 , V_15 ) ;
if ( error == - V_99 && ! strcmp ( V_73 , L_59 ) ) {
if ( ! F_229 ( V_588 ) ) {
struct V_589 * V_590 ;
T_7 V_591 ;
if ( V_1 [ V_586 - 1 ] == '\0' )
V_591 = V_586 - 1 ;
else
V_591 = V_586 ;
V_590 = F_233 ( V_11 -> V_592 , V_104 , V_593 ) ;
F_234 ( V_590 , L_62 ) ;
F_235 ( V_590 , V_555 , V_591 ) ;
F_236 ( V_590 ) ;
return error ;
}
error = F_237 ( V_555 , V_586 ,
& V_17 ) ;
}
if ( error )
return error ;
}
V_139 = F_249 () ;
if ( ! V_139 )
return - V_27 ;
V_14 = V_139 -> V_19 ;
if ( ! strcmp ( V_73 , L_58 ) ) {
V_14 -> V_476 = V_17 ;
} else if ( ! strcmp ( V_73 , L_59 ) ) {
V_14 -> V_361 = V_17 ;
} else if ( ! strcmp ( V_73 , L_60 ) ) {
error = F_54 ( V_408 , V_17 , V_987 , V_988 ,
NULL ) ;
if ( error )
goto V_989;
V_14 -> V_474 = V_17 ;
} else if ( ! strcmp ( V_73 , L_61 ) ) {
V_14 -> V_475 = V_17 ;
} else if ( ! strcmp ( V_73 , L_56 ) ) {
error = - V_99 ;
if ( V_17 == 0 )
goto V_989;
error = - V_472 ;
if ( ! F_423 () ) {
error = F_157 ( V_14 -> V_17 , V_17 ) ;
if ( error )
goto V_989;
}
error = F_54 ( V_14 -> V_17 , V_17 , V_423 ,
V_990 , NULL ) ;
if ( error )
goto V_989;
V_483 = F_153 () ;
if ( V_483 != 0 ) {
error = F_54 ( V_483 , V_17 , V_423 ,
V_424 , NULL ) ;
if ( error )
goto V_989;
}
V_14 -> V_17 = V_17 ;
} else {
error = - V_99 ;
goto V_989;
}
F_424 ( V_139 ) ;
return V_586 ;
V_989:
F_425 ( V_139 ) ;
return error ;
}
static int F_426 ( const char * V_73 )
{
return ( strcmp ( V_73 , V_557 ) == 0 ) ;
}
static int F_427 ( T_2 V_598 , char * * V_538 , T_2 * V_991 )
{
return F_70 ( V_598 , V_538 , V_991 ) ;
}
static int F_428 ( const char * V_538 , T_2 V_991 , T_2 * V_598 )
{
return F_232 ( V_538 , V_991 , V_598 , V_15 ) ;
}
static void F_429 ( char * V_538 , T_2 V_991 )
{
F_51 ( V_538 ) ;
}
static void F_430 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_35 ;
F_42 ( & V_24 -> V_28 ) ;
V_24 -> V_33 = V_34 ;
F_44 ( & V_24 -> V_28 ) ;
}
static int F_431 ( struct V_22 * V_22 , void * V_552 , T_2 V_553 )
{
return F_245 ( V_22 , V_557 , V_552 , V_553 , 0 ) ;
}
static int F_432 ( struct V_36 * V_36 , void * V_552 , T_2 V_553 )
{
return F_433 ( V_36 , V_84 , V_552 , V_553 , 0 ) ;
}
static int F_434 ( struct V_22 * V_22 , void * * V_552 , T_2 * V_553 )
{
int V_97 = 0 ;
V_97 = F_243 ( V_22 , V_557 ,
V_552 , true ) ;
if ( V_97 < 0 )
return V_97 ;
* V_553 = V_97 ;
return 0 ;
}
static int F_435 ( struct V_907 * V_992 , const struct V_10 * V_10 ,
unsigned long V_88 )
{
const struct V_13 * V_14 ;
struct V_993 * V_994 ;
V_994 = F_15 ( sizeof( struct V_993 ) , V_15 ) ;
if ( ! V_994 )
return - V_27 ;
V_14 = V_10 -> V_19 ;
if ( V_14 -> V_474 )
V_994 -> V_17 = V_14 -> V_474 ;
else
V_994 -> V_17 = V_14 -> V_17 ;
V_992 -> V_19 = V_994 ;
return 0 ;
}
static void F_436 ( struct V_907 * V_992 )
{
struct V_993 * V_994 = V_992 -> V_19 ;
V_992 -> V_19 = NULL ;
F_51 ( V_994 ) ;
}
static int F_437 ( T_16 V_995 ,
const struct V_10 * V_10 ,
unsigned V_327 )
{
struct V_907 * V_907 ;
struct V_993 * V_994 ;
T_2 V_17 ;
if ( V_327 == 0 )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_907 = F_438 ( V_995 ) ;
V_994 = V_907 -> V_19 ;
return F_54 ( V_17 , V_994 -> V_17 , V_987 , V_327 , NULL ) ;
}
static int F_439 ( struct V_907 * V_907 , char * * V_996 )
{
struct V_993 * V_994 = V_907 -> V_19 ;
char * V_96 = NULL ;
unsigned V_97 ;
int V_62 ;
V_62 = F_70 ( V_994 -> V_17 , & V_96 , & V_97 ) ;
if ( ! V_62 )
V_62 = V_97 ;
* V_996 = V_96 ;
return V_62 ;
}
static T_1 int F_440 ( void )
{
if ( ! F_441 ( L_63 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_58 ( V_997 L_64 ) ;
return 0 ;
}
F_58 ( V_997 L_65 ) ;
F_14 () ;
V_627 = ! ( V_998 & V_642 ) ;
V_25 = F_442 ( L_66 ,
sizeof( struct V_23 ) ,
0 , V_999 , NULL ) ;
V_53 = F_442 ( L_67 ,
sizeof( struct V_51 ) ,
0 , V_999 , NULL ) ;
F_443 () ;
F_444 ( V_1000 , F_60 ( V_1000 ) , L_63 ) ;
if ( F_445 ( F_9 , V_9 ) )
F_16 ( L_68 ) ;
if ( V_3 )
F_58 ( V_1001 L_69 ) ;
else
F_58 ( V_1001 L_70 ) ;
return 0 ;
}
static void F_446 ( struct V_56 * V_57 , void * V_1002 )
{
F_87 ( V_57 , NULL ) ;
}
void F_447 ( void )
{
F_58 ( V_1001 L_71 ) ;
F_58 ( V_1001 L_72 ) ;
F_448 ( F_446 , NULL ) ;
}
static int T_1 F_449 ( void )
{
int V_656 ;
if ( ! V_5 )
return 0 ;
F_58 ( V_1001 L_73 ) ;
V_656 = F_450 ( V_1003 , F_60 ( V_1003 ) ) ;
if ( V_656 )
F_16 ( L_74 , V_656 ) ;
return 0 ;
}
static void F_451 ( void )
{
F_58 ( V_1001 L_75 ) ;
F_452 ( V_1003 , F_60 ( V_1003 ) ) ;
}
int F_453 ( void )
{
if ( V_39 ) {
return - V_99 ;
}
if ( V_1004 ) {
return - V_99 ;
}
F_58 ( V_997 L_76 ) ;
V_1004 = 1 ;
V_5 = 0 ;
F_454 ( V_1000 , F_60 ( V_1000 ) ) ;
F_455 () ;
F_451 () ;
F_456 () ;
return 0 ;
}
