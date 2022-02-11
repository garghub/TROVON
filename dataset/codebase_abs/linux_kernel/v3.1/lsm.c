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
static int F_21 ( struct V_11 * V_28 , const struct V_1 * V_1 ,
struct V_29 * V_30 , int V_31 , int V_32 )
{
struct V_21 * V_22 ;
int error = F_22 ( V_28 , V_1 , V_30 , V_31 , V_32 ) ;
if ( ! error ) {
V_22 = F_16 ( V_1 ) ;
if ( ! F_17 ( V_22 ) )
error = F_23 ( V_28 , V_22 , V_31 , V_32 ) ;
}
return error ;
}
static int F_24 ( int V_33 , struct V_34 * V_34 , T_3 V_35 ,
struct V_36 * V_37 )
{
struct V_21 * V_22 ;
int error = 0 ;
V_22 = F_25 () ;
if ( ! F_17 ( V_22 ) )
error = F_26 ( V_33 , V_22 , V_34 , 0 , V_35 , V_37 ) ;
return error ;
}
static int F_27 ( int V_33 , struct V_34 * V_38 ,
struct V_39 * V_39 , T_3 V_35 ,
struct V_36 * V_37 )
{
struct V_34 V_34 = { V_38 -> V_40 , V_39 } ;
return F_24 ( V_33 , & V_34 , V_35 , V_37 ) ;
}
static int F_28 ( int V_33 , struct V_41 * V_40 ,
struct V_39 * V_39 , T_3 V_35 )
{
struct V_34 V_34 = { V_40 , V_39 } ;
struct V_36 V_37 = { V_39 -> V_42 -> V_43 ,
V_39 -> V_42 -> V_44
} ;
return F_24 ( V_33 , & V_34 , V_35 , & V_37 ) ;
}
static int F_29 ( int V_33 , struct V_34 * V_38 ,
struct V_39 * V_39 , T_3 V_35 )
{
struct V_45 * V_45 = V_39 -> V_42 ;
struct V_36 V_37 = { } ;
if ( ! V_45 || ! V_38 -> V_40 || ! F_30 ( V_45 ) )
return 0 ;
V_37 . V_46 = V_45 -> V_43 ;
V_37 . V_13 = V_45 -> V_44 ;
return F_27 ( V_33 , V_38 , V_39 , V_35 , & V_37 ) ;
}
static int F_31 ( int V_33 , struct V_34 * V_38 , struct V_39 * V_39 ,
T_3 V_35 , T_4 V_13 )
{
struct V_36 V_37 = { F_32 () , V_13 } ;
if ( ! V_38 -> V_40 || ! F_30 ( V_38 -> V_39 -> V_42 ) )
return 0 ;
return F_27 ( V_33 , V_38 , V_39 , V_35 , & V_37 ) ;
}
static int F_33 ( struct V_34 * V_38 , struct V_39 * V_39 )
{
return F_29 ( V_47 , V_38 , V_39 , V_48 ) ;
}
static int F_34 ( struct V_34 * V_38 , struct V_39 * V_39 ,
int V_13 )
{
return F_31 ( V_49 , V_38 , V_39 , V_50 ,
V_51 ) ;
}
static int F_35 ( struct V_34 * V_38 , struct V_39 * V_39 )
{
return F_29 ( V_52 , V_38 , V_39 , V_48 ) ;
}
static int F_36 ( struct V_34 * V_38 , struct V_39 * V_39 ,
int V_13 , unsigned int V_53 )
{
return F_31 ( V_54 , V_38 , V_39 , V_50 , V_13 ) ;
}
static int F_37 ( struct V_34 * V_34 )
{
struct V_36 V_37 = { V_34 -> V_39 -> V_42 -> V_43 ,
V_34 -> V_39 -> V_42 -> V_44
} ;
if ( ! V_34 -> V_40 || ! F_30 ( V_34 -> V_39 -> V_42 ) )
return 0 ;
return F_24 ( V_55 , V_34 , V_56 | V_57 ,
& V_37 ) ;
}
static int F_38 ( struct V_34 * V_38 , struct V_39 * V_39 ,
const char * V_58 )
{
return F_31 ( V_59 , V_38 , V_39 , V_50 ,
V_60 ) ;
}
static int F_39 ( struct V_39 * V_61 , struct V_34 * V_62 ,
struct V_39 * V_63 )
{
struct V_21 * V_22 ;
int error = 0 ;
if ( ! F_30 ( V_61 -> V_42 ) )
return 0 ;
V_22 = F_40 () ;
if ( ! F_17 ( V_22 ) )
error = F_41 ( V_22 , V_61 , V_62 , V_63 ) ;
return error ;
}
static int F_42 ( struct V_34 * V_64 , struct V_39 * V_61 ,
struct V_34 * V_62 , struct V_39 * V_63 )
{
struct V_21 * V_22 ;
int error = 0 ;
if ( ! F_30 ( V_61 -> V_42 ) )
return 0 ;
V_22 = F_40 () ;
if ( ! F_17 ( V_22 ) ) {
struct V_34 V_65 = { V_64 -> V_40 , V_61 } ;
struct V_34 V_66 = { V_62 -> V_40 , V_63 } ;
struct V_36 V_37 = { V_61 -> V_42 -> V_43 ,
V_61 -> V_42 -> V_44
} ;
error = F_26 ( V_67 , V_22 , & V_65 , 0 ,
V_68 | V_69 | V_56 |
V_57 | V_48 ,
& V_37 ) ;
if ( ! error )
error = F_26 ( V_70 , V_22 , & V_66 ,
0 , V_56 | V_57 |
V_50 , & V_37 ) ;
}
return error ;
}
static int F_43 ( struct V_39 * V_39 , struct V_41 * V_40 ,
T_5 V_13 )
{
if ( ! F_30 ( V_39 -> V_42 ) )
return 0 ;
return F_28 ( V_71 , V_40 , V_39 , V_72 ) ;
}
static int F_44 ( struct V_34 * V_34 , T_6 V_46 , T_7 V_73 )
{
struct V_36 V_37 = { V_34 -> V_39 -> V_42 -> V_43 ,
V_34 -> V_39 -> V_42 -> V_44
} ;
if ( ! F_30 ( V_34 -> V_39 -> V_42 ) )
return 0 ;
return F_24 ( V_74 , V_34 , V_75 , & V_37 ) ;
}
static int F_45 ( struct V_41 * V_40 , struct V_39 * V_39 )
{
if ( ! F_30 ( V_39 -> V_42 ) )
return 0 ;
return F_28 ( V_76 , V_40 , V_39 ,
V_69 ) ;
}
static int F_46 ( struct V_77 * V_77 , const struct V_1 * V_1 )
{
struct V_78 * V_79 = V_77 -> V_80 ;
struct V_21 * V_22 ;
int error = 0 ;
if ( ! F_30 ( V_77 -> V_81 . V_39 -> V_42 ) )
return 0 ;
if ( V_14 -> V_82 ) {
V_79 -> V_27 = V_83 | V_68 | V_84 ;
return 0 ;
}
V_22 = F_16 ( V_1 ) ;
if ( ! F_17 ( V_22 ) ) {
struct V_45 * V_45 = V_77 -> V_81 . V_39 -> V_42 ;
struct V_36 V_37 = { V_45 -> V_43 , V_45 -> V_44 } ;
error = F_26 ( V_85 , V_22 , & V_77 -> V_81 , 0 ,
F_47 ( V_77 ) , & V_37 ) ;
V_79 -> V_27 = F_47 ( V_77 ) ;
}
return error ;
}
static int F_48 ( struct V_77 * V_77 )
{
V_77 -> V_80 = F_49 ( V_86 ) ;
if ( ! V_77 -> V_80 )
return - V_6 ;
return 0 ;
}
static void F_50 ( struct V_77 * V_77 )
{
struct V_78 * V_5 = V_77 -> V_80 ;
F_51 ( V_5 ) ;
}
static int F_52 ( int V_33 , struct V_77 * V_77 , T_3 V_35 )
{
struct V_78 * V_79 = V_77 -> V_80 ;
struct V_21 * V_22 , * V_87 = F_16 ( V_77 -> V_88 ) ;
int error = 0 ;
F_53 ( ! V_87 ) ;
if ( ! V_77 -> V_81 . V_40 ||
! F_30 ( V_77 -> V_81 . V_39 -> V_42 ) )
return 0 ;
V_22 = F_25 () ;
if ( ! F_17 ( V_22 ) && ! F_17 ( V_87 ) &&
( ( V_87 != V_22 ) || ( V_35 & ~ V_79 -> V_27 ) ) )
error = F_54 ( V_33 , V_22 , V_77 , V_35 ) ;
return error ;
}
static int F_55 ( struct V_77 * V_77 , int V_35 )
{
return F_52 ( V_89 , V_77 , V_35 ) ;
}
static int F_56 ( struct V_77 * V_77 , unsigned int V_90 )
{
T_3 V_35 = V_91 ;
if ( V_90 == V_92 )
V_35 |= V_56 ;
return F_52 ( V_93 , V_77 , V_35 ) ;
}
static int F_57 ( int V_33 , struct V_77 * V_77 , unsigned long V_94 ,
unsigned long V_95 )
{
struct V_39 * V_39 ;
int V_35 = 0 ;
if ( ! V_77 || ! V_77 -> V_80 )
return 0 ;
if ( V_94 & V_96 )
V_35 |= V_68 ;
if ( ( V_94 & V_97 ) && ! ( V_95 & V_98 ) )
V_35 |= V_56 ;
if ( V_94 & V_99 )
V_35 |= V_84 ;
V_39 = V_77 -> V_81 . V_39 ;
return F_52 ( V_33 , V_77 , V_35 ) ;
}
static int F_58 ( struct V_77 * V_77 , unsigned long V_100 ,
unsigned long V_94 , unsigned long V_95 ,
unsigned long V_101 , unsigned long V_102 )
{
int V_103 = 0 ;
V_103 = F_59 ( V_77 , V_100 , V_94 , V_95 , V_101 , V_102 ) ;
if ( V_103 || V_102 )
return V_103 ;
return F_57 ( V_104 , V_77 , V_94 , V_95 ) ;
}
static int F_60 ( struct V_105 * V_106 ,
unsigned long V_100 , unsigned long V_94 )
{
return F_57 ( V_107 , V_106 -> V_108 , V_94 ,
! ( V_106 -> V_109 & V_110 ) ? V_98 : 0 ) ;
}
static int F_61 ( struct V_11 * V_28 , char * V_111 ,
char * * V_112 )
{
int error = - V_113 ;
struct V_21 * V_22 ;
const struct V_1 * V_1 = F_62 ( V_28 ) ;
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
static int F_66 ( struct V_11 * V_28 , char * V_111 ,
void * V_112 , T_8 V_117 )
{
char * V_118 , * args = V_112 ;
T_8 V_119 ;
int error ;
if ( V_117 == 0 )
return - V_116 ;
if ( args [ V_117 - 1 ] != '\0' ) {
if ( V_117 == V_120 )
return - V_116 ;
args [ V_117 ] = '\0' ;
}
if ( V_14 != V_28 )
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
F_73 ( & V_125 , V_126 ) ;
V_125 . V_127 . V_33 = V_128 ;
V_125 . V_127 . V_129 = V_111 ;
V_125 . V_127 . error = - V_116 ;
return F_74 ( V_130 ,
F_25 () , V_86 ,
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
static int F_75 ( struct V_11 * V_28 ,
unsigned int V_131 , struct V_132 * V_133 )
{
struct V_21 * V_22 = F_25 () ;
int error = 0 ;
if ( ! F_17 ( V_22 ) )
error = F_76 ( V_22 , V_28 , V_131 , V_133 ) ;
return error ;
}
static int T_9 F_77 ( char * V_134 )
{
unsigned long V_135 ;
int error = F_78 ( V_134 , 0 , & V_135 ) ;
if ( ! error )
V_136 = V_135 ? 1 : 0 ;
return 1 ;
}
static int F_79 ( const char * V_137 , const struct V_138 * V_139 )
{
if ( ! F_80 ( V_140 ) )
return - V_141 ;
if ( V_142 )
return - V_121 ;
return F_81 ( V_137 , V_139 ) ;
}
static int F_82 ( char * V_143 , const struct V_138 * V_139 )
{
if ( ! F_80 ( V_140 ) )
return - V_141 ;
return F_83 ( V_143 , V_139 ) ;
}
static int F_84 ( const char * V_137 , const struct V_138 * V_139 )
{
if ( ! F_80 ( V_140 ) )
return - V_141 ;
return F_81 ( V_137 , V_139 ) ;
}
static int F_85 ( char * V_143 , const struct V_138 * V_139 )
{
if ( ! F_80 ( V_140 ) )
return - V_141 ;
return F_83 ( V_143 , V_139 ) ;
}
static int F_86 ( const char * V_137 , const struct V_138 * V_139 )
{
if ( ! F_80 ( V_140 ) )
return - V_141 ;
return F_87 ( V_137 , V_139 ) ;
}
static int F_88 ( char * V_143 , const struct V_138 * V_139 )
{
if ( ! F_80 ( V_140 ) )
return - V_141 ;
return F_89 ( V_143 , V_139 ) ;
}
static int F_90 ( char * V_143 , struct V_138 * V_139 )
{
if ( ! F_80 ( V_140 ) )
return - V_141 ;
if ( ! V_136 )
return - V_116 ;
return sprintf ( V_143 , L_10 , V_144 [ V_145 ] ) ;
}
static int F_91 ( const char * V_137 , struct V_138 * V_139 )
{
int V_146 ;
if ( ! F_80 ( V_140 ) )
return - V_141 ;
if ( ! V_136 )
return - V_116 ;
if ( ! V_137 )
return - V_116 ;
for ( V_146 = 0 ; V_146 < V_147 ; V_146 ++ ) {
if ( strcmp ( V_137 , V_144 [ V_146 ] ) == 0 ) {
V_145 = V_146 ;
return 0 ;
}
}
return - V_116 ;
}
static int F_92 ( char * V_143 , struct V_138 * V_139 )
{
if ( ! F_80 ( V_140 ) )
return - V_141 ;
if ( ! V_136 )
return - V_116 ;
return sprintf ( V_143 , L_10 , V_148 [ V_149 ] ) ;
}
static int F_93 ( const char * V_137 , struct V_138 * V_139 )
{
int V_146 ;
if ( ! F_80 ( V_140 ) )
return - V_141 ;
if ( ! V_136 )
return - V_116 ;
if ( ! V_137 )
return - V_116 ;
for ( V_146 = 0 ; V_146 < V_150 ; V_146 ++ ) {
if ( strcmp ( V_137 , V_148 [ V_146 ] ) == 0 ) {
V_149 = V_146 ;
return 0 ;
}
}
return - V_116 ;
}
static int T_9 F_94 ( void )
{
struct V_1 * V_1 = (struct V_1 * ) V_14 -> V_151 ;
struct V_4 * V_5 ;
V_5 = F_4 ( V_86 ) ;
if ( ! V_5 )
return - V_6 ;
V_5 -> V_22 = F_95 ( V_152 -> F_17 ) ;
V_1 -> V_2 = V_5 ;
return 0 ;
}
static int T_9 F_96 ( void )
{
int error ;
if ( ! V_136 || ! F_97 ( & V_153 ) ) {
F_98 ( L_11 ) ;
V_136 = 0 ;
return 0 ;
}
error = F_99 () ;
if ( error ) {
F_100 ( L_12 ) ;
goto V_154;
}
error = F_94 () ;
if ( error ) {
F_100 ( L_13 ) ;
goto V_155;
}
error = F_101 ( & V_153 ) ;
if ( error ) {
F_100 ( L_14 ) ;
goto V_156;
}
V_157 = 1 ;
if ( V_149 == V_158 )
F_98 ( L_15 ) ;
else if ( V_149 == V_159 )
F_98 ( L_16 ) ;
else
F_98 ( L_17 ) ;
return error ;
V_156:
F_2 ( V_14 -> V_151 -> V_2 ) ;
V_155:
F_102 () ;
V_154:
F_103 () ;
V_136 = 0 ;
return error ;
}
