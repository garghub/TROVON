static void F_1 ( struct V_1 * V_1 )
{
F_2 ( F_3 ( V_1 ) ) ;
F_3 ( V_1 ) = NULL ;
}
static int F_4 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
if ( ! V_4 )
return - V_5 ;
F_3 ( V_1 ) = V_4 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_6 , const struct V_1 * V_7 ,
T_1 V_2 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
if ( ! V_4 )
return - V_5 ;
F_7 ( V_4 , F_3 ( V_7 ) ) ;
F_3 ( V_6 ) = V_4 ;
return 0 ;
}
static void F_8 ( struct V_1 * V_6 , const struct V_1 * V_7 )
{
const struct V_3 * V_8 = F_3 ( V_7 ) ;
struct V_3 * V_9 = F_3 ( V_6 ) ;
F_7 ( V_9 , V_8 ) ;
}
static int F_9 ( struct V_10 * V_11 ,
unsigned int V_12 )
{
int error = F_10 ( V_11 , V_12 ) ;
if ( error )
return error ;
return F_11 ( V_13 , V_11 , V_12 ) ;
}
static int F_12 ( struct V_10 * V_14 )
{
int error = F_13 ( V_14 ) ;
if ( error )
return error ;
return F_11 ( V_14 , V_13 , V_15 ) ;
}
static int F_14 ( struct V_10 * V_16 , T_2 * V_17 ,
T_2 * V_18 , T_2 * V_19 )
{
struct V_20 * V_21 ;
const struct V_1 * V_1 ;
F_15 () ;
V_1 = F_16 ( V_16 ) ;
V_21 = F_17 ( V_1 ) ;
* V_17 = V_1 -> V_22 ;
* V_18 = V_1 -> V_23 ;
* V_19 = V_1 -> V_24 ;
if ( ! F_18 ( V_21 ) && ! F_19 ( V_21 ) ) {
* V_17 = F_20 ( * V_17 , V_21 -> V_25 . V_26 ) ;
* V_19 = F_20 ( * V_19 , V_21 -> V_25 . V_26 ) ;
}
F_21 () ;
return 0 ;
}
static int F_22 ( const struct V_1 * V_1 , struct V_27 * V_28 ,
int V_29 , int V_30 )
{
struct V_20 * V_21 ;
int error = F_23 ( V_1 , V_28 , V_29 , V_30 ) ;
if ( ! error ) {
V_21 = F_17 ( V_1 ) ;
if ( ! F_18 ( V_21 ) )
error = F_24 ( V_21 , V_29 , V_30 ) ;
}
return error ;
}
static int F_25 ( int V_31 , struct V_32 * V_32 , T_3 V_33 ,
struct V_34 * V_35 )
{
struct V_20 * V_21 ;
int error = 0 ;
V_21 = F_26 () ;
if ( ! F_18 ( V_21 ) )
error = F_27 ( V_31 , V_21 , V_32 , 0 , V_33 , V_35 ) ;
return error ;
}
static int F_28 ( int V_31 , struct V_32 * V_36 ,
struct V_37 * V_37 , T_3 V_33 ,
struct V_34 * V_35 )
{
struct V_32 V_32 = { V_36 -> V_38 , V_37 } ;
return F_25 ( V_31 , & V_32 , V_33 , V_35 ) ;
}
static int F_29 ( int V_31 , struct V_39 * V_38 ,
struct V_37 * V_37 , T_3 V_33 )
{
struct V_32 V_32 = { V_38 , V_37 } ;
struct V_34 V_35 = { V_37 -> V_40 -> V_41 ,
V_37 -> V_40 -> V_42
} ;
return F_25 ( V_31 , & V_32 , V_33 , & V_35 ) ;
}
static int F_30 ( int V_31 , struct V_32 * V_36 ,
struct V_37 * V_37 , T_3 V_33 )
{
struct V_43 * V_43 = V_37 -> V_40 ;
struct V_34 V_35 = { } ;
if ( ! V_43 || ! V_36 -> V_38 || ! F_31 ( V_37 ) )
return 0 ;
V_35 . V_44 = V_43 -> V_41 ;
V_35 . V_12 = V_43 -> V_42 ;
return F_28 ( V_31 , V_36 , V_37 , V_33 , & V_35 ) ;
}
static int F_32 ( int V_31 , struct V_32 * V_36 , struct V_37 * V_37 ,
T_3 V_33 , T_4 V_12 )
{
struct V_34 V_35 = { F_33 () , V_12 } ;
if ( ! V_36 -> V_38 || ! F_31 ( V_36 -> V_37 ) )
return 0 ;
return F_28 ( V_31 , V_36 , V_37 , V_33 , & V_35 ) ;
}
static int F_34 ( struct V_32 * V_36 , struct V_37 * V_37 )
{
return F_30 ( V_45 , V_36 , V_37 , V_46 ) ;
}
static int F_35 ( struct V_32 * V_36 , struct V_37 * V_37 ,
T_4 V_12 )
{
return F_32 ( V_47 , V_36 , V_37 , V_48 ,
V_49 ) ;
}
static int F_36 ( struct V_32 * V_36 , struct V_37 * V_37 )
{
return F_30 ( V_50 , V_36 , V_37 , V_46 ) ;
}
static int F_37 ( struct V_32 * V_36 , struct V_37 * V_37 ,
T_4 V_12 , unsigned int V_51 )
{
return F_32 ( V_52 , V_36 , V_37 , V_48 , V_12 ) ;
}
static int F_38 ( struct V_32 * V_32 )
{
struct V_34 V_35 = { V_32 -> V_37 -> V_40 -> V_41 ,
V_32 -> V_37 -> V_40 -> V_42
} ;
if ( ! V_32 -> V_38 || ! F_31 ( V_32 -> V_37 ) )
return 0 ;
return F_25 ( V_53 , V_32 , V_54 | V_55 ,
& V_35 ) ;
}
static int F_39 ( struct V_32 * V_36 , struct V_37 * V_37 ,
const char * V_56 )
{
return F_32 ( V_57 , V_36 , V_37 , V_48 ,
V_58 ) ;
}
static int F_40 ( struct V_37 * V_59 , struct V_32 * V_60 ,
struct V_37 * V_61 )
{
struct V_20 * V_21 ;
int error = 0 ;
if ( ! F_31 ( V_59 ) )
return 0 ;
V_21 = F_41 () ;
if ( ! F_18 ( V_21 ) )
error = F_42 ( V_21 , V_59 , V_60 , V_61 ) ;
return error ;
}
static int F_43 ( struct V_32 * V_62 , struct V_37 * V_59 ,
struct V_32 * V_60 , struct V_37 * V_61 )
{
struct V_20 * V_21 ;
int error = 0 ;
if ( ! F_31 ( V_59 ) )
return 0 ;
V_21 = F_41 () ;
if ( ! F_18 ( V_21 ) ) {
struct V_32 V_63 = { V_62 -> V_38 , V_59 } ;
struct V_32 V_64 = { V_60 -> V_38 , V_61 } ;
struct V_34 V_35 = { V_59 -> V_40 -> V_41 ,
V_59 -> V_40 -> V_42
} ;
error = F_27 ( V_65 , V_21 , & V_63 , 0 ,
V_66 | V_67 | V_54 |
V_55 | V_46 ,
& V_35 ) ;
if ( ! error )
error = F_27 ( V_68 , V_21 , & V_64 ,
0 , V_54 | V_55 |
V_48 , & V_35 ) ;
}
return error ;
}
static int F_44 ( struct V_32 * V_32 , T_4 V_12 )
{
if ( ! F_31 ( V_32 -> V_37 ) )
return 0 ;
return F_29 ( V_69 , V_32 -> V_38 , V_32 -> V_37 , V_70 ) ;
}
static int F_45 ( struct V_32 * V_32 , T_5 V_44 , T_6 V_71 )
{
struct V_34 V_35 = { V_32 -> V_37 -> V_40 -> V_41 ,
V_32 -> V_37 -> V_40 -> V_42
} ;
if ( ! F_31 ( V_32 -> V_37 ) )
return 0 ;
return F_25 ( V_72 , V_32 , V_73 , & V_35 ) ;
}
static int F_46 ( struct V_39 * V_38 , struct V_37 * V_37 )
{
if ( ! F_31 ( V_37 ) )
return 0 ;
return F_29 ( V_74 , V_38 , V_37 ,
V_67 ) ;
}
static int F_47 ( struct V_75 * V_75 , const struct V_1 * V_1 )
{
struct V_76 * V_77 = V_75 -> V_78 ;
struct V_20 * V_21 ;
int error = 0 ;
if ( ! F_31 ( V_75 -> V_79 . V_37 ) )
return 0 ;
if ( V_13 -> V_80 ) {
V_77 -> V_26 = V_81 | V_66 | V_82 ;
return 0 ;
}
V_21 = F_17 ( V_1 ) ;
if ( ! F_18 ( V_21 ) ) {
struct V_43 * V_43 = F_48 ( V_75 ) ;
struct V_34 V_35 = { V_43 -> V_41 , V_43 -> V_42 } ;
error = F_27 ( V_83 , V_21 , & V_75 -> V_79 , 0 ,
F_49 ( V_75 ) , & V_35 ) ;
V_77 -> V_26 = F_49 ( V_75 ) ;
}
return error ;
}
static int F_50 ( struct V_75 * V_75 )
{
V_75 -> V_78 = F_51 ( V_84 ) ;
if ( ! V_75 -> V_78 )
return - V_5 ;
return 0 ;
}
static void F_52 ( struct V_75 * V_75 )
{
struct V_76 * V_4 = V_75 -> V_78 ;
F_53 ( V_4 ) ;
}
static int F_54 ( int V_31 , struct V_75 * V_75 , T_3 V_33 )
{
struct V_76 * V_77 = V_75 -> V_78 ;
struct V_20 * V_21 , * V_85 = F_17 ( V_75 -> V_86 ) ;
int error = 0 ;
F_55 ( ! V_85 ) ;
if ( ! V_75 -> V_79 . V_38 ||
! F_31 ( V_75 -> V_79 . V_37 ) )
return 0 ;
V_21 = F_26 () ;
if ( ! F_18 ( V_21 ) && ! F_18 ( V_85 ) &&
( ( V_85 != V_21 ) || ( V_33 & ~ V_77 -> V_26 ) ) )
error = F_56 ( V_31 , V_21 , V_75 , V_33 ) ;
return error ;
}
static int F_57 ( struct V_75 * V_75 , int V_33 )
{
return F_54 ( V_87 , V_75 , V_33 ) ;
}
static int F_58 ( struct V_75 * V_75 , unsigned int V_88 )
{
T_3 V_33 = V_89 ;
if ( V_88 == V_90 )
V_33 |= V_54 ;
return F_54 ( V_91 , V_75 , V_33 ) ;
}
static int F_59 ( int V_31 , struct V_75 * V_75 , unsigned long V_92 ,
unsigned long V_93 )
{
int V_33 = 0 ;
if ( ! V_75 || ! V_75 -> V_78 )
return 0 ;
if ( V_92 & V_94 )
V_33 |= V_66 ;
if ( ( V_92 & V_95 ) && ! ( V_93 & V_96 ) )
V_33 |= V_54 ;
if ( V_92 & V_97 )
V_33 |= V_82 ;
return F_54 ( V_31 , V_75 , V_33 ) ;
}
static int F_60 ( struct V_75 * V_75 , unsigned long V_98 ,
unsigned long V_92 , unsigned long V_93 )
{
return F_59 ( V_99 , V_75 , V_92 , V_93 ) ;
}
static int F_61 ( struct V_100 * V_101 ,
unsigned long V_98 , unsigned long V_92 )
{
return F_59 ( V_102 , V_101 -> V_103 , V_92 ,
! ( V_101 -> V_104 & V_105 ) ? V_96 : 0 ) ;
}
static int F_62 ( struct V_10 * V_106 , char * V_107 ,
char * * V_108 )
{
int error = - V_109 ;
const struct V_1 * V_1 = F_63 ( V_106 ) ;
struct V_3 * V_4 = F_3 ( V_1 ) ;
struct V_20 * V_21 = NULL ;
if ( strcmp ( V_107 , L_1 ) == 0 )
V_21 = F_64 ( V_4 -> V_21 ) ;
else if ( strcmp ( V_107 , L_2 ) == 0 && V_4 -> V_110 )
V_21 = F_64 ( V_4 -> V_110 ) ;
else if ( strcmp ( V_107 , L_3 ) == 0 && V_4 -> V_111 )
V_21 = F_64 ( V_4 -> V_111 ) ;
else
error = - V_112 ;
if ( V_21 )
error = F_65 ( V_21 , V_108 ) ;
F_66 ( V_21 ) ;
F_67 ( V_1 ) ;
return error ;
}
static int F_68 ( struct V_10 * V_106 , char * V_107 ,
void * V_108 , T_7 V_113 )
{
struct V_114 V_115 ;
struct V_116 V_117 = { 0 ,} ;
char * V_118 , * args = V_108 ;
T_7 V_119 ;
int error ;
if ( V_113 == 0 )
return - V_112 ;
if ( args [ V_113 - 1 ] != '\0' ) {
if ( V_113 == V_120 )
return - V_112 ;
args [ V_113 ] = '\0' ;
}
if ( V_13 != V_106 )
return - V_121 ;
args = V_108 ;
args = F_69 ( args ) ;
V_118 = F_70 ( & args , L_4 ) ;
if ( ! args )
return - V_112 ;
args = F_71 ( args ) ;
if ( ! * args )
return - V_112 ;
V_119 = V_113 - ( args - ( char * ) V_108 ) ;
if ( strcmp ( V_107 , L_1 ) == 0 ) {
if ( strcmp ( V_118 , L_5 ) == 0 ) {
error = F_72 ( args , V_119 ,
! V_122 ) ;
} else if ( strcmp ( V_118 , L_6 ) == 0 ) {
error = F_72 ( args , V_119 ,
V_122 ) ;
} else if ( strcmp ( V_118 , L_7 ) == 0 ) {
error = F_73 ( args , ! V_123 ,
! V_122 ) ;
} else if ( strcmp ( V_118 , L_8 ) == 0 ) {
error = F_73 ( args , ! V_123 ,
V_122 ) ;
} else
goto V_124;
} else if ( strcmp ( V_107 , L_3 ) == 0 ) {
if ( strcmp ( V_118 , L_3 ) == 0 )
error = F_73 ( args , V_123 ,
! V_122 ) ;
else
goto V_124;
} else
return - V_112 ;
if ( ! error )
error = V_113 ;
return error ;
V_124:
V_115 . type = V_125 ;
V_115 . V_117 = & V_117 ;
V_117 . V_21 = F_41 () ;
V_117 . V_31 = V_126 ;
V_117 . V_127 = V_107 ;
V_117 . error = - V_112 ;
F_74 ( V_128 , & V_115 , NULL ) ;
return - V_112 ;
}
static int F_75 ( struct V_10 * V_106 ,
unsigned int V_129 , struct V_130 * V_131 )
{
struct V_20 * V_21 = F_26 () ;
int error = 0 ;
if ( ! F_18 ( V_21 ) )
error = F_76 ( V_21 , V_106 , V_129 , V_131 ) ;
return error ;
}
static int T_8 F_77 ( char * V_132 )
{
unsigned long V_133 ;
int error = F_78 ( V_132 , 0 , & V_133 ) ;
if ( ! error )
V_134 = V_133 ? 1 : 0 ;
return 1 ;
}
static int F_79 ( const char * V_135 , const struct V_136 * V_137 )
{
if ( ! F_80 ( V_138 ) )
return - V_139 ;
if ( V_140 )
return - V_121 ;
return F_81 ( V_135 , V_137 ) ;
}
static int F_82 ( char * V_141 , const struct V_136 * V_137 )
{
if ( ! F_80 ( V_138 ) )
return - V_139 ;
return F_83 ( V_141 , V_137 ) ;
}
static int F_84 ( const char * V_135 , const struct V_136 * V_137 )
{
if ( ! F_80 ( V_138 ) )
return - V_139 ;
return F_81 ( V_135 , V_137 ) ;
}
static int F_85 ( char * V_141 , const struct V_136 * V_137 )
{
if ( ! F_80 ( V_138 ) )
return - V_139 ;
return F_83 ( V_141 , V_137 ) ;
}
static int F_86 ( const char * V_135 , const struct V_136 * V_137 )
{
if ( ! F_80 ( V_138 ) )
return - V_139 ;
return F_87 ( V_135 , V_137 ) ;
}
static int F_88 ( char * V_141 , const struct V_136 * V_137 )
{
if ( ! F_80 ( V_138 ) )
return - V_139 ;
return F_89 ( V_141 , V_137 ) ;
}
static int F_90 ( char * V_141 , struct V_136 * V_137 )
{
if ( ! F_80 ( V_138 ) )
return - V_139 ;
if ( ! V_134 )
return - V_112 ;
return sprintf ( V_141 , L_9 , V_142 [ V_143 ] ) ;
}
static int F_91 ( const char * V_135 , struct V_136 * V_137 )
{
int V_144 ;
if ( ! F_80 ( V_138 ) )
return - V_139 ;
if ( ! V_134 )
return - V_112 ;
if ( ! V_135 )
return - V_112 ;
for ( V_144 = 0 ; V_144 < V_145 ; V_144 ++ ) {
if ( strcmp ( V_135 , V_142 [ V_144 ] ) == 0 ) {
V_143 = V_144 ;
return 0 ;
}
}
return - V_112 ;
}
static int F_92 ( char * V_141 , struct V_136 * V_137 )
{
if ( ! F_80 ( V_138 ) )
return - V_139 ;
if ( ! V_134 )
return - V_112 ;
return sprintf ( V_141 , L_9 , V_146 [ V_147 ] ) ;
}
static int F_93 ( const char * V_135 , struct V_136 * V_137 )
{
int V_144 ;
if ( ! F_80 ( V_138 ) )
return - V_139 ;
if ( ! V_134 )
return - V_112 ;
if ( ! V_135 )
return - V_112 ;
for ( V_144 = 0 ; V_144 < V_148 ; V_144 ++ ) {
if ( strcmp ( V_135 , V_146 [ V_144 ] ) == 0 ) {
V_147 = V_144 ;
return 0 ;
}
}
return - V_112 ;
}
static int T_8 F_94 ( void )
{
struct V_1 * V_1 = (struct V_1 * ) V_13 -> V_149 ;
struct V_3 * V_4 ;
V_4 = F_5 ( V_84 ) ;
if ( ! V_4 )
return - V_5 ;
V_4 -> V_21 = F_95 ( V_150 -> F_18 ) ;
F_3 ( V_1 ) = V_4 ;
return 0 ;
}
static int T_8 F_96 ( void )
{
int error ;
if ( ! V_134 || ! F_97 ( & V_151 ) ) {
F_98 ( L_10 ) ;
V_134 = 0 ;
return 0 ;
}
error = F_99 () ;
if ( error ) {
F_100 ( L_11 ) ;
goto V_152;
}
error = F_94 () ;
if ( error ) {
F_100 ( L_12 ) ;
goto V_153;
}
error = F_101 ( & V_151 ) ;
if ( error ) {
struct V_1 * V_1 = (struct V_1 * ) V_13 -> V_149 ;
F_2 ( F_3 ( V_1 ) ) ;
F_3 ( V_1 ) = NULL ;
F_100 ( L_13 ) ;
goto V_153;
}
V_154 = 1 ;
if ( V_147 == V_155 )
F_98 ( L_14 ) ;
else if ( V_147 == V_156 )
F_98 ( L_15 ) ;
else
F_98 ( L_16 ) ;
return error ;
V_153:
F_102 () ;
V_152:
F_103 () ;
V_134 = 0 ;
return error ;
}
