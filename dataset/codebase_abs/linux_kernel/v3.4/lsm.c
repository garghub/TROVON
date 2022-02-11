static void F_1 ( struct V_1 * V_1 )
{
F_2 ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
}
static int F_3 ( struct V_1 * V_1 , T_1 V_3 )
{
struct V_4 * V_5 = F_4 ( V_3 ) ;
if ( ! V_5 )
return - V_6 ;
V_1 -> V_2 = V_5 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_7 , const struct V_1 * V_8 ,
T_1 V_3 )
{
struct V_4 * V_5 = F_4 ( V_3 ) ;
if ( ! V_5 )
return - V_6 ;
F_6 ( V_5 , V_8 -> V_2 ) ;
V_7 -> V_2 = V_5 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_7 , const struct V_1 * V_8 )
{
const struct V_4 * V_9 = V_8 -> V_2 ;
struct V_4 * V_10 = V_7 -> V_2 ;
F_6 ( V_10 , V_9 ) ;
}
static int F_8 ( struct V_11 * V_12 ,
unsigned int V_13 )
{
int error = F_9 ( V_12 , V_13 ) ;
if ( error )
return error ;
return F_10 ( V_14 , V_12 , V_13 ) ;
}
static int F_11 ( struct V_11 * V_15 )
{
int error = F_12 ( V_15 ) ;
if ( error )
return error ;
return F_10 ( V_15 , V_14 , V_16 ) ;
}
static int F_13 ( struct V_11 * V_17 , T_2 * V_18 ,
T_2 * V_19 , T_2 * V_20 )
{
struct V_21 * V_22 ;
const struct V_1 * V_1 ;
F_14 () ;
V_1 = F_15 ( V_17 ) ;
V_22 = F_16 ( V_1 ) ;
* V_18 = V_1 -> V_23 ;
* V_19 = V_1 -> V_24 ;
* V_20 = V_1 -> V_25 ;
if ( ! F_17 ( V_22 ) && ! F_18 ( V_22 ) ) {
* V_18 = F_19 ( * V_18 , V_22 -> V_26 . V_27 ) ;
* V_20 = F_19 ( * V_20 , V_22 -> V_26 . V_27 ) ;
}
F_20 () ;
return 0 ;
}
static int F_21 ( const struct V_1 * V_1 , struct V_28 * V_29 ,
int V_30 , int V_31 )
{
struct V_21 * V_22 ;
int error = F_22 ( V_1 , V_29 , V_30 , V_31 ) ;
if ( ! error ) {
V_22 = F_16 ( V_1 ) ;
if ( ! F_17 ( V_22 ) )
error = F_23 ( V_14 , V_22 , V_30 , V_31 ) ;
}
return error ;
}
static int F_24 ( int V_32 , struct V_33 * V_33 , T_3 V_34 ,
struct V_35 * V_36 )
{
struct V_21 * V_22 ;
int error = 0 ;
V_22 = F_25 () ;
if ( ! F_17 ( V_22 ) )
error = F_26 ( V_32 , V_22 , V_33 , 0 , V_34 , V_36 ) ;
return error ;
}
static int F_27 ( int V_32 , struct V_33 * V_37 ,
struct V_38 * V_38 , T_3 V_34 ,
struct V_35 * V_36 )
{
struct V_33 V_33 = { V_37 -> V_39 , V_38 } ;
return F_24 ( V_32 , & V_33 , V_34 , V_36 ) ;
}
static int F_28 ( int V_32 , struct V_40 * V_39 ,
struct V_38 * V_38 , T_3 V_34 )
{
struct V_33 V_33 = { V_39 , V_38 } ;
struct V_35 V_36 = { V_38 -> V_41 -> V_42 ,
V_38 -> V_41 -> V_43
} ;
return F_24 ( V_32 , & V_33 , V_34 , & V_36 ) ;
}
static int F_29 ( int V_32 , struct V_33 * V_37 ,
struct V_38 * V_38 , T_3 V_34 )
{
struct V_44 * V_44 = V_38 -> V_41 ;
struct V_35 V_36 = { } ;
if ( ! V_44 || ! V_37 -> V_39 || ! F_30 ( V_44 ) )
return 0 ;
V_36 . V_45 = V_44 -> V_42 ;
V_36 . V_13 = V_44 -> V_43 ;
return F_27 ( V_32 , V_37 , V_38 , V_34 , & V_36 ) ;
}
static int F_31 ( int V_32 , struct V_33 * V_37 , struct V_38 * V_38 ,
T_3 V_34 , T_4 V_13 )
{
struct V_35 V_36 = { F_32 () , V_13 } ;
if ( ! V_37 -> V_39 || ! F_30 ( V_37 -> V_38 -> V_41 ) )
return 0 ;
return F_27 ( V_32 , V_37 , V_38 , V_34 , & V_36 ) ;
}
static int F_33 ( struct V_33 * V_37 , struct V_38 * V_38 )
{
return F_29 ( V_46 , V_37 , V_38 , V_47 ) ;
}
static int F_34 ( struct V_33 * V_37 , struct V_38 * V_38 ,
T_4 V_13 )
{
return F_31 ( V_48 , V_37 , V_38 , V_49 ,
V_50 ) ;
}
static int F_35 ( struct V_33 * V_37 , struct V_38 * V_38 )
{
return F_29 ( V_51 , V_37 , V_38 , V_47 ) ;
}
static int F_36 ( struct V_33 * V_37 , struct V_38 * V_38 ,
T_4 V_13 , unsigned int V_52 )
{
return F_31 ( V_53 , V_37 , V_38 , V_49 , V_13 ) ;
}
static int F_37 ( struct V_33 * V_33 )
{
struct V_35 V_36 = { V_33 -> V_38 -> V_41 -> V_42 ,
V_33 -> V_38 -> V_41 -> V_43
} ;
if ( ! V_33 -> V_39 || ! F_30 ( V_33 -> V_38 -> V_41 ) )
return 0 ;
return F_24 ( V_54 , V_33 , V_55 | V_56 ,
& V_36 ) ;
}
static int F_38 ( struct V_33 * V_37 , struct V_38 * V_38 ,
const char * V_57 )
{
return F_31 ( V_58 , V_37 , V_38 , V_49 ,
V_59 ) ;
}
static int F_39 ( struct V_38 * V_60 , struct V_33 * V_61 ,
struct V_38 * V_62 )
{
struct V_21 * V_22 ;
int error = 0 ;
if ( ! F_30 ( V_60 -> V_41 ) )
return 0 ;
V_22 = F_40 () ;
if ( ! F_17 ( V_22 ) )
error = F_41 ( V_22 , V_60 , V_61 , V_62 ) ;
return error ;
}
static int F_42 ( struct V_33 * V_63 , struct V_38 * V_60 ,
struct V_33 * V_61 , struct V_38 * V_62 )
{
struct V_21 * V_22 ;
int error = 0 ;
if ( ! F_30 ( V_60 -> V_41 ) )
return 0 ;
V_22 = F_40 () ;
if ( ! F_17 ( V_22 ) ) {
struct V_33 V_64 = { V_63 -> V_39 , V_60 } ;
struct V_33 V_65 = { V_61 -> V_39 , V_62 } ;
struct V_35 V_36 = { V_60 -> V_41 -> V_42 ,
V_60 -> V_41 -> V_43
} ;
error = F_26 ( V_66 , V_22 , & V_64 , 0 ,
V_67 | V_68 | V_55 |
V_56 | V_47 ,
& V_36 ) ;
if ( ! error )
error = F_26 ( V_69 , V_22 , & V_65 ,
0 , V_55 | V_56 |
V_49 , & V_36 ) ;
}
return error ;
}
static int F_43 ( struct V_33 * V_33 , T_4 V_13 )
{
if ( ! F_30 ( V_33 -> V_38 -> V_41 ) )
return 0 ;
return F_28 ( V_70 , V_33 -> V_39 , V_33 -> V_38 , V_71 ) ;
}
static int F_44 ( struct V_33 * V_33 , T_5 V_45 , T_6 V_72 )
{
struct V_35 V_36 = { V_33 -> V_38 -> V_41 -> V_42 ,
V_33 -> V_38 -> V_41 -> V_43
} ;
if ( ! F_30 ( V_33 -> V_38 -> V_41 ) )
return 0 ;
return F_24 ( V_73 , V_33 , V_74 , & V_36 ) ;
}
static int F_45 ( struct V_40 * V_39 , struct V_38 * V_38 )
{
if ( ! F_30 ( V_38 -> V_41 ) )
return 0 ;
return F_28 ( V_75 , V_39 , V_38 ,
V_68 ) ;
}
static int F_46 ( struct V_76 * V_76 , const struct V_1 * V_1 )
{
struct V_77 * V_78 = V_76 -> V_79 ;
struct V_21 * V_22 ;
int error = 0 ;
if ( ! F_30 ( V_76 -> V_80 . V_38 -> V_41 ) )
return 0 ;
if ( V_14 -> V_81 ) {
V_78 -> V_27 = V_82 | V_67 | V_83 ;
return 0 ;
}
V_22 = F_16 ( V_1 ) ;
if ( ! F_17 ( V_22 ) ) {
struct V_44 * V_44 = V_76 -> V_80 . V_38 -> V_41 ;
struct V_35 V_36 = { V_44 -> V_42 , V_44 -> V_43 } ;
error = F_26 ( V_84 , V_22 , & V_76 -> V_80 , 0 ,
F_47 ( V_76 ) , & V_36 ) ;
V_78 -> V_27 = F_47 ( V_76 ) ;
}
return error ;
}
static int F_48 ( struct V_76 * V_76 )
{
V_76 -> V_79 = F_49 ( V_85 ) ;
if ( ! V_76 -> V_79 )
return - V_6 ;
return 0 ;
}
static void F_50 ( struct V_76 * V_76 )
{
struct V_77 * V_5 = V_76 -> V_79 ;
F_51 ( V_5 ) ;
}
static int F_52 ( int V_32 , struct V_76 * V_76 , T_3 V_34 )
{
struct V_77 * V_78 = V_76 -> V_79 ;
struct V_21 * V_22 , * V_86 = F_16 ( V_76 -> V_87 ) ;
int error = 0 ;
F_53 ( ! V_86 ) ;
if ( ! V_76 -> V_80 . V_39 ||
! F_30 ( V_76 -> V_80 . V_38 -> V_41 ) )
return 0 ;
V_22 = F_25 () ;
if ( ! F_17 ( V_22 ) && ! F_17 ( V_86 ) &&
( ( V_86 != V_22 ) || ( V_34 & ~ V_78 -> V_27 ) ) )
error = F_54 ( V_32 , V_22 , V_76 , V_34 ) ;
return error ;
}
static int F_55 ( struct V_76 * V_76 , int V_34 )
{
return F_52 ( V_88 , V_76 , V_34 ) ;
}
static int F_56 ( struct V_76 * V_76 , unsigned int V_89 )
{
T_3 V_34 = V_90 ;
if ( V_89 == V_91 )
V_34 |= V_55 ;
return F_52 ( V_92 , V_76 , V_34 ) ;
}
static int F_57 ( int V_32 , struct V_76 * V_76 , unsigned long V_93 ,
unsigned long V_94 )
{
struct V_38 * V_38 ;
int V_34 = 0 ;
if ( ! V_76 || ! V_76 -> V_79 )
return 0 ;
if ( V_93 & V_95 )
V_34 |= V_67 ;
if ( ( V_93 & V_96 ) && ! ( V_94 & V_97 ) )
V_34 |= V_55 ;
if ( V_93 & V_98 )
V_34 |= V_83 ;
V_38 = V_76 -> V_80 . V_38 ;
return F_52 ( V_32 , V_76 , V_34 ) ;
}
static int F_58 ( struct V_76 * V_76 , unsigned long V_99 ,
unsigned long V_93 , unsigned long V_94 ,
unsigned long V_100 , unsigned long V_101 )
{
int V_102 = 0 ;
V_102 = F_59 ( V_76 , V_99 , V_93 , V_94 , V_100 , V_101 ) ;
if ( V_102 || V_101 )
return V_102 ;
return F_57 ( V_103 , V_76 , V_93 , V_94 ) ;
}
static int F_60 ( struct V_104 * V_105 ,
unsigned long V_99 , unsigned long V_93 )
{
return F_57 ( V_106 , V_105 -> V_107 , V_93 ,
! ( V_105 -> V_108 & V_109 ) ? V_97 : 0 ) ;
}
static int F_61 ( struct V_11 * V_110 , char * V_111 ,
char * * V_112 )
{
int error = - V_113 ;
struct V_21 * V_22 ;
const struct V_1 * V_1 = F_62 ( V_110 ) ;
struct V_4 * V_5 = V_1 -> V_2 ;
V_22 = F_16 ( V_1 ) ;
if ( strcmp ( V_111 , L_1 ) == 0 )
error = F_63 ( F_64 ( V_5 -> V_22 ) ,
V_112 ) ;
else if ( strcmp ( V_111 , L_2 ) == 0 && V_5 -> V_114 )
error = F_63 ( F_64 ( V_5 -> V_114 ) ,
V_112 ) ;
else if ( strcmp ( V_111 , L_3 ) == 0 && V_5 -> V_115 )
error = F_63 ( F_64 ( V_5 -> V_115 ) ,
V_112 ) ;
else
error = - V_116 ;
F_65 ( V_1 ) ;
return error ;
}
static int F_66 ( struct V_11 * V_110 , char * V_111 ,
void * V_112 , T_7 V_117 )
{
char * V_118 , * args = V_112 ;
T_7 V_119 ;
int error ;
if ( V_117 == 0 )
return - V_116 ;
if ( args [ V_117 - 1 ] != '\0' ) {
if ( V_117 == V_120 )
return - V_116 ;
args [ V_117 ] = '\0' ;
}
if ( V_14 != V_110 )
return - V_121 ;
args = V_112 ;
args = F_67 ( args ) ;
V_118 = F_68 ( & args , L_4 ) ;
if ( ! args )
return - V_116 ;
args = F_69 ( args ) ;
if ( ! * args )
return - V_116 ;
V_119 = V_117 - ( args - ( char * ) V_112 ) ;
if ( strcmp ( V_111 , L_1 ) == 0 ) {
if ( strcmp ( V_118 , L_5 ) == 0 ) {
error = F_70 ( args , V_119 ,
! V_122 ) ;
} else if ( strcmp ( V_118 , L_6 ) == 0 ) {
error = F_70 ( args , V_119 ,
V_122 ) ;
} else if ( strcmp ( V_118 , L_7 ) == 0 ) {
error = F_71 ( args , ! V_123 ,
! V_122 ) ;
} else if ( strcmp ( V_118 , L_8 ) == 0 ) {
error = F_71 ( args , ! V_123 ,
V_122 ) ;
} else if ( strcmp ( V_118 , L_9 ) == 0 ) {
error = F_72 ( args ) ;
} else {
struct V_124 V_125 ;
struct V_126 V_127 = { 0 ,} ;
F_73 ( & V_125 , V_128 ) ;
V_125 . V_127 = & V_127 ;
V_127 . V_32 = V_129 ;
V_127 . V_130 = V_111 ;
V_127 . error = - V_116 ;
return F_74 ( V_131 ,
F_25 () , V_85 ,
& V_125 , NULL ) ;
}
} else if ( strcmp ( V_111 , L_3 ) == 0 ) {
error = F_71 ( args , V_123 ,
! V_122 ) ;
} else {
return - V_116 ;
}
if ( ! error )
error = V_117 ;
return error ;
}
static int F_75 ( struct V_11 * V_110 ,
unsigned int V_132 , struct V_133 * V_134 )
{
struct V_21 * V_22 = F_25 () ;
int error = 0 ;
if ( ! F_17 ( V_22 ) )
error = F_76 ( V_22 , V_110 , V_132 , V_134 ) ;
return error ;
}
static int T_8 F_77 ( char * V_135 )
{
unsigned long V_136 ;
int error = F_78 ( V_135 , 0 , & V_136 ) ;
if ( ! error )
V_137 = V_136 ? 1 : 0 ;
return 1 ;
}
static int F_79 ( const char * V_138 , const struct V_139 * V_140 )
{
if ( ! F_80 ( V_141 ) )
return - V_142 ;
if ( V_143 )
return - V_121 ;
return F_81 ( V_138 , V_140 ) ;
}
static int F_82 ( char * V_144 , const struct V_139 * V_140 )
{
if ( ! F_80 ( V_141 ) )
return - V_142 ;
return F_83 ( V_144 , V_140 ) ;
}
static int F_84 ( const char * V_138 , const struct V_139 * V_140 )
{
if ( ! F_80 ( V_141 ) )
return - V_142 ;
return F_81 ( V_138 , V_140 ) ;
}
static int F_85 ( char * V_144 , const struct V_139 * V_140 )
{
if ( ! F_80 ( V_141 ) )
return - V_142 ;
return F_83 ( V_144 , V_140 ) ;
}
static int F_86 ( const char * V_138 , const struct V_139 * V_140 )
{
if ( ! F_80 ( V_141 ) )
return - V_142 ;
return F_87 ( V_138 , V_140 ) ;
}
static int F_88 ( char * V_144 , const struct V_139 * V_140 )
{
if ( ! F_80 ( V_141 ) )
return - V_142 ;
return F_89 ( V_144 , V_140 ) ;
}
static int F_90 ( char * V_144 , struct V_139 * V_140 )
{
if ( ! F_80 ( V_141 ) )
return - V_142 ;
if ( ! V_137 )
return - V_116 ;
return sprintf ( V_144 , L_10 , V_145 [ V_146 ] ) ;
}
static int F_91 ( const char * V_138 , struct V_139 * V_140 )
{
int V_147 ;
if ( ! F_80 ( V_141 ) )
return - V_142 ;
if ( ! V_137 )
return - V_116 ;
if ( ! V_138 )
return - V_116 ;
for ( V_147 = 0 ; V_147 < V_148 ; V_147 ++ ) {
if ( strcmp ( V_138 , V_145 [ V_147 ] ) == 0 ) {
V_146 = V_147 ;
return 0 ;
}
}
return - V_116 ;
}
static int F_92 ( char * V_144 , struct V_139 * V_140 )
{
if ( ! F_80 ( V_141 ) )
return - V_142 ;
if ( ! V_137 )
return - V_116 ;
return sprintf ( V_144 , L_10 , V_149 [ V_150 ] ) ;
}
static int F_93 ( const char * V_138 , struct V_139 * V_140 )
{
int V_147 ;
if ( ! F_80 ( V_141 ) )
return - V_142 ;
if ( ! V_137 )
return - V_116 ;
if ( ! V_138 )
return - V_116 ;
for ( V_147 = 0 ; V_147 < V_151 ; V_147 ++ ) {
if ( strcmp ( V_138 , V_149 [ V_147 ] ) == 0 ) {
V_150 = V_147 ;
return 0 ;
}
}
return - V_116 ;
}
static int T_8 F_94 ( void )
{
struct V_1 * V_1 = (struct V_1 * ) V_14 -> V_152 ;
struct V_4 * V_5 ;
V_5 = F_4 ( V_85 ) ;
if ( ! V_5 )
return - V_6 ;
V_5 -> V_22 = F_95 ( V_153 -> F_17 ) ;
V_1 -> V_2 = V_5 ;
return 0 ;
}
static int T_8 F_96 ( void )
{
int error ;
if ( ! V_137 || ! F_97 ( & V_154 ) ) {
F_98 ( L_11 ) ;
V_137 = 0 ;
return 0 ;
}
error = F_99 () ;
if ( error ) {
F_100 ( L_12 ) ;
goto V_155;
}
error = F_94 () ;
if ( error ) {
F_100 ( L_13 ) ;
goto V_156;
}
error = F_101 ( & V_154 ) ;
if ( error ) {
F_100 ( L_14 ) ;
goto V_157;
}
V_158 = 1 ;
if ( V_150 == V_159 )
F_98 ( L_15 ) ;
else if ( V_150 == V_160 )
F_98 ( L_16 ) ;
else
F_98 ( L_17 ) ;
return error ;
V_157:
F_2 ( V_14 -> V_152 -> V_2 ) ;
V_156:
F_102 () ;
V_155:
F_103 () ;
V_137 = 0 ;
return error ;
}
