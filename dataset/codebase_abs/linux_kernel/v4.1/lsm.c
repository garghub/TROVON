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
struct V_34 V_35 = { F_30 ( V_37 ) -> V_40 ,
F_30 ( V_37 ) -> V_41
} ;
return F_25 ( V_31 , & V_32 , V_33 , & V_35 ) ;
}
static int F_31 ( int V_31 , struct V_32 * V_36 ,
struct V_37 * V_37 , T_3 V_33 )
{
struct V_42 * V_42 = F_30 ( V_37 ) ;
struct V_34 V_35 = { } ;
if ( ! V_42 || ! V_36 -> V_38 || ! F_32 ( V_37 ) )
return 0 ;
V_35 . V_43 = V_42 -> V_40 ;
V_35 . V_12 = V_42 -> V_41 ;
return F_28 ( V_31 , V_36 , V_37 , V_33 , & V_35 ) ;
}
static int F_33 ( int V_31 , struct V_32 * V_36 , struct V_37 * V_37 ,
T_3 V_33 , T_4 V_12 )
{
struct V_34 V_35 = { F_34 () , V_12 } ;
if ( ! V_36 -> V_38 || ! F_32 ( V_36 -> V_37 ) )
return 0 ;
return F_28 ( V_31 , V_36 , V_37 , V_33 , & V_35 ) ;
}
static int F_35 ( struct V_32 * V_36 , struct V_37 * V_37 )
{
return F_31 ( V_44 , V_36 , V_37 , V_45 ) ;
}
static int F_36 ( struct V_32 * V_36 , struct V_37 * V_37 ,
T_4 V_12 )
{
return F_33 ( V_46 , V_36 , V_37 , V_47 ,
V_48 ) ;
}
static int F_37 ( struct V_32 * V_36 , struct V_37 * V_37 )
{
return F_31 ( V_49 , V_36 , V_37 , V_45 ) ;
}
static int F_38 ( struct V_32 * V_36 , struct V_37 * V_37 ,
T_4 V_12 , unsigned int V_50 )
{
return F_33 ( V_51 , V_36 , V_37 , V_47 , V_12 ) ;
}
static int F_39 ( struct V_32 * V_32 )
{
struct V_34 V_35 = { F_30 ( V_32 -> V_37 ) -> V_40 ,
F_30 ( V_32 -> V_37 ) -> V_41
} ;
if ( ! V_32 -> V_38 || ! F_32 ( V_32 -> V_37 ) )
return 0 ;
return F_25 ( V_52 , V_32 , V_53 | V_54 ,
& V_35 ) ;
}
static int F_40 ( struct V_32 * V_36 , struct V_37 * V_37 ,
const char * V_55 )
{
return F_33 ( V_56 , V_36 , V_37 , V_47 ,
V_57 ) ;
}
static int F_41 ( struct V_37 * V_58 , struct V_32 * V_59 ,
struct V_37 * V_60 )
{
struct V_20 * V_21 ;
int error = 0 ;
if ( ! F_32 ( V_58 ) )
return 0 ;
V_21 = F_42 () ;
if ( ! F_18 ( V_21 ) )
error = F_43 ( V_21 , V_58 , V_59 , V_60 ) ;
return error ;
}
static int F_44 ( struct V_32 * V_61 , struct V_37 * V_58 ,
struct V_32 * V_59 , struct V_37 * V_60 )
{
struct V_20 * V_21 ;
int error = 0 ;
if ( ! F_32 ( V_58 ) )
return 0 ;
V_21 = F_42 () ;
if ( ! F_18 ( V_21 ) ) {
struct V_32 V_62 = { V_61 -> V_38 , V_58 } ;
struct V_32 V_63 = { V_59 -> V_38 , V_60 } ;
struct V_34 V_35 = { F_30 ( V_58 ) -> V_40 ,
F_30 ( V_58 ) -> V_41
} ;
error = F_27 ( V_64 , V_21 , & V_62 , 0 ,
V_65 | V_66 | V_53 |
V_54 | V_45 ,
& V_35 ) ;
if ( ! error )
error = F_27 ( V_67 , V_21 , & V_63 ,
0 , V_53 | V_54 |
V_47 , & V_35 ) ;
}
return error ;
}
static int F_45 ( struct V_32 * V_32 , T_4 V_12 )
{
if ( ! F_32 ( V_32 -> V_37 ) )
return 0 ;
return F_29 ( V_68 , V_32 -> V_38 , V_32 -> V_37 , V_69 ) ;
}
static int F_46 ( struct V_32 * V_32 , T_5 V_43 , T_6 V_70 )
{
struct V_34 V_35 = { F_30 ( V_32 -> V_37 ) -> V_40 ,
F_30 ( V_32 -> V_37 ) -> V_41
} ;
if ( ! F_32 ( V_32 -> V_37 ) )
return 0 ;
return F_25 ( V_71 , V_32 , V_72 , & V_35 ) ;
}
static int F_47 ( const struct V_32 * V_32 )
{
if ( ! F_32 ( V_32 -> V_37 ) )
return 0 ;
return F_29 ( V_73 , V_32 -> V_38 , V_32 -> V_37 ,
V_66 ) ;
}
static int F_48 ( struct V_74 * V_74 , const struct V_1 * V_1 )
{
struct V_75 * V_76 = V_74 -> V_77 ;
struct V_20 * V_21 ;
int error = 0 ;
if ( ! F_32 ( V_74 -> V_78 . V_37 ) )
return 0 ;
if ( V_13 -> V_79 ) {
V_76 -> V_26 = V_80 | V_65 | V_81 ;
return 0 ;
}
V_21 = F_17 ( V_1 ) ;
if ( ! F_18 ( V_21 ) ) {
struct V_42 * V_42 = F_49 ( V_74 ) ;
struct V_34 V_35 = { V_42 -> V_40 , V_42 -> V_41 } ;
error = F_27 ( V_82 , V_21 , & V_74 -> V_78 , 0 ,
F_50 ( V_74 ) , & V_35 ) ;
V_76 -> V_26 = F_50 ( V_74 ) ;
}
return error ;
}
static int F_51 ( struct V_74 * V_74 )
{
V_74 -> V_77 = F_52 ( V_83 ) ;
if ( ! V_74 -> V_77 )
return - V_5 ;
return 0 ;
}
static void F_53 ( struct V_74 * V_74 )
{
struct V_75 * V_4 = V_74 -> V_77 ;
F_54 ( V_4 ) ;
}
static int F_55 ( int V_31 , struct V_74 * V_74 , T_3 V_33 )
{
struct V_75 * V_76 = V_74 -> V_77 ;
struct V_20 * V_21 , * V_84 = F_17 ( V_74 -> V_85 ) ;
int error = 0 ;
F_56 ( ! V_84 ) ;
if ( ! V_74 -> V_78 . V_38 ||
! F_32 ( V_74 -> V_78 . V_37 ) )
return 0 ;
V_21 = F_26 () ;
if ( ! F_18 ( V_21 ) && ! F_18 ( V_84 ) &&
( ( V_84 != V_21 ) || ( V_33 & ~ V_76 -> V_26 ) ) )
error = F_57 ( V_31 , V_21 , V_74 , V_33 ) ;
return error ;
}
static int F_58 ( struct V_74 * V_74 , int V_33 )
{
return F_55 ( V_86 , V_74 , V_33 ) ;
}
static int F_59 ( struct V_74 * V_74 , unsigned int V_87 )
{
T_3 V_33 = V_88 ;
if ( V_87 == V_89 )
V_33 |= V_53 ;
return F_55 ( V_90 , V_74 , V_33 ) ;
}
static int F_60 ( int V_31 , struct V_74 * V_74 , unsigned long V_91 ,
unsigned long V_92 )
{
int V_33 = 0 ;
if ( ! V_74 || ! V_74 -> V_77 )
return 0 ;
if ( V_91 & V_93 )
V_33 |= V_65 ;
if ( ( V_91 & V_94 ) && ! ( V_92 & V_95 ) )
V_33 |= V_53 ;
if ( V_91 & V_96 )
V_33 |= V_81 ;
return F_55 ( V_31 , V_74 , V_33 ) ;
}
static int F_61 ( struct V_74 * V_74 , unsigned long V_97 ,
unsigned long V_91 , unsigned long V_92 )
{
return F_60 ( V_98 , V_74 , V_91 , V_92 ) ;
}
static int F_62 ( struct V_99 * V_100 ,
unsigned long V_97 , unsigned long V_91 )
{
return F_60 ( V_101 , V_100 -> V_102 , V_91 ,
! ( V_100 -> V_103 & V_104 ) ? V_95 : 0 ) ;
}
static int F_63 ( struct V_10 * V_105 , char * V_106 ,
char * * V_107 )
{
int error = - V_108 ;
const struct V_1 * V_1 = F_64 ( V_105 ) ;
struct V_3 * V_4 = F_3 ( V_1 ) ;
struct V_20 * V_21 = NULL ;
if ( strcmp ( V_106 , L_1 ) == 0 )
V_21 = F_65 ( V_4 -> V_21 ) ;
else if ( strcmp ( V_106 , L_2 ) == 0 && V_4 -> V_109 )
V_21 = F_65 ( V_4 -> V_109 ) ;
else if ( strcmp ( V_106 , L_3 ) == 0 && V_4 -> V_110 )
V_21 = F_65 ( V_4 -> V_110 ) ;
else
error = - V_111 ;
if ( V_21 )
error = F_66 ( V_21 , V_107 ) ;
F_67 ( V_21 ) ;
F_68 ( V_1 ) ;
return error ;
}
static int F_69 ( struct V_10 * V_105 , char * V_106 ,
void * V_107 , T_7 V_112 )
{
struct V_113 V_114 ;
struct V_115 V_116 = { 0 ,} ;
char * V_117 , * args = V_107 ;
T_7 V_118 ;
int error ;
if ( V_112 == 0 )
return - V_111 ;
if ( args [ V_112 - 1 ] != '\0' ) {
if ( V_112 == V_119 )
return - V_111 ;
args [ V_112 ] = '\0' ;
}
if ( V_13 != V_105 )
return - V_120 ;
args = V_107 ;
args = F_70 ( args ) ;
V_117 = F_71 ( & args , L_4 ) ;
if ( ! args )
return - V_111 ;
args = F_72 ( args ) ;
if ( ! * args )
return - V_111 ;
V_118 = V_112 - ( args - ( char * ) V_107 ) ;
if ( strcmp ( V_106 , L_1 ) == 0 ) {
if ( strcmp ( V_117 , L_5 ) == 0 ) {
error = F_73 ( args , V_118 ,
! V_121 ) ;
} else if ( strcmp ( V_117 , L_6 ) == 0 ) {
error = F_73 ( args , V_118 ,
V_121 ) ;
} else if ( strcmp ( V_117 , L_7 ) == 0 ) {
error = F_74 ( args , ! V_122 ,
! V_121 ) ;
} else if ( strcmp ( V_117 , L_8 ) == 0 ) {
error = F_74 ( args , ! V_122 ,
V_121 ) ;
} else
goto V_123;
} else if ( strcmp ( V_106 , L_3 ) == 0 ) {
if ( strcmp ( V_117 , L_3 ) == 0 )
error = F_74 ( args , V_122 ,
! V_121 ) ;
else
goto V_123;
} else
return - V_111 ;
if ( ! error )
error = V_112 ;
return error ;
V_123:
V_114 . type = V_124 ;
V_114 . V_116 = & V_116 ;
V_116 . V_21 = F_42 () ;
V_116 . V_31 = V_125 ;
V_116 . V_126 = V_106 ;
V_116 . error = - V_111 ;
F_75 ( V_127 , & V_114 , NULL ) ;
return - V_111 ;
}
static int F_76 ( struct V_10 * V_105 ,
unsigned int V_128 , struct V_129 * V_130 )
{
struct V_20 * V_21 = F_26 () ;
int error = 0 ;
if ( ! F_18 ( V_21 ) )
error = F_77 ( V_21 , V_105 , V_128 , V_130 ) ;
return error ;
}
static int T_8 F_78 ( char * V_131 )
{
unsigned long V_132 ;
int error = F_79 ( V_131 , 0 , & V_132 ) ;
if ( ! error )
V_133 = V_132 ? 1 : 0 ;
return 1 ;
}
static int F_80 ( const char * V_134 , const struct V_135 * V_136 )
{
if ( ! F_81 ( V_137 ) )
return - V_138 ;
if ( V_139 )
return - V_120 ;
return F_82 ( V_134 , V_136 ) ;
}
static int F_83 ( char * V_140 , const struct V_135 * V_136 )
{
if ( ! F_81 ( V_137 ) )
return - V_138 ;
return F_84 ( V_140 , V_136 ) ;
}
static int F_85 ( const char * V_134 , const struct V_135 * V_136 )
{
if ( ! F_81 ( V_137 ) )
return - V_138 ;
return F_82 ( V_134 , V_136 ) ;
}
static int F_86 ( char * V_140 , const struct V_135 * V_136 )
{
if ( ! F_81 ( V_137 ) )
return - V_138 ;
return F_84 ( V_140 , V_136 ) ;
}
static int F_87 ( const char * V_134 , const struct V_135 * V_136 )
{
if ( ! F_81 ( V_137 ) )
return - V_138 ;
return F_88 ( V_134 , V_136 ) ;
}
static int F_89 ( char * V_140 , const struct V_135 * V_136 )
{
if ( ! F_81 ( V_137 ) )
return - V_138 ;
return F_90 ( V_140 , V_136 ) ;
}
static int F_91 ( char * V_140 , struct V_135 * V_136 )
{
if ( ! F_81 ( V_137 ) )
return - V_138 ;
if ( ! V_133 )
return - V_111 ;
return sprintf ( V_140 , L_9 , V_141 [ V_142 ] ) ;
}
static int F_92 ( const char * V_134 , struct V_135 * V_136 )
{
int V_143 ;
if ( ! F_81 ( V_137 ) )
return - V_138 ;
if ( ! V_133 )
return - V_111 ;
if ( ! V_134 )
return - V_111 ;
for ( V_143 = 0 ; V_143 < V_144 ; V_143 ++ ) {
if ( strcmp ( V_134 , V_141 [ V_143 ] ) == 0 ) {
V_142 = V_143 ;
return 0 ;
}
}
return - V_111 ;
}
static int F_93 ( char * V_140 , struct V_135 * V_136 )
{
if ( ! F_81 ( V_137 ) )
return - V_138 ;
if ( ! V_133 )
return - V_111 ;
return sprintf ( V_140 , L_9 , V_145 [ V_146 ] ) ;
}
static int F_94 ( const char * V_134 , struct V_135 * V_136 )
{
int V_143 ;
if ( ! F_81 ( V_137 ) )
return - V_138 ;
if ( ! V_133 )
return - V_111 ;
if ( ! V_134 )
return - V_111 ;
for ( V_143 = 0 ; V_143 < V_147 ; V_143 ++ ) {
if ( strcmp ( V_134 , V_145 [ V_143 ] ) == 0 ) {
V_146 = V_143 ;
return 0 ;
}
}
return - V_111 ;
}
static int T_8 F_95 ( void )
{
struct V_1 * V_1 = (struct V_1 * ) V_13 -> V_148 ;
struct V_3 * V_4 ;
V_4 = F_5 ( V_83 ) ;
if ( ! V_4 )
return - V_5 ;
V_4 -> V_21 = F_96 ( V_149 -> F_18 ) ;
F_3 ( V_1 ) = V_4 ;
return 0 ;
}
static int T_8 F_97 ( void )
{
int error ;
if ( ! V_133 || ! F_98 ( & V_150 ) ) {
F_99 ( L_10 ) ;
V_133 = 0 ;
return 0 ;
}
error = F_100 () ;
if ( error ) {
F_101 ( L_11 ) ;
goto V_151;
}
error = F_95 () ;
if ( error ) {
F_101 ( L_12 ) ;
goto V_152;
}
error = F_102 ( & V_150 ) ;
if ( error ) {
struct V_1 * V_1 = (struct V_1 * ) V_13 -> V_148 ;
F_2 ( F_3 ( V_1 ) ) ;
F_3 ( V_1 ) = NULL ;
F_101 ( L_13 ) ;
goto V_152;
}
V_153 = 1 ;
if ( V_146 == V_154 )
F_99 ( L_14 ) ;
else if ( V_146 == V_155 )
F_99 ( L_15 ) ;
else
F_99 ( L_16 ) ;
return error ;
V_152:
F_103 () ;
V_151:
F_104 () ;
V_133 = 0 ;
return error ;
}
