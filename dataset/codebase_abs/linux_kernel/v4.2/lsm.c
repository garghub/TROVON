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
return F_10 ( V_13 , V_11 , V_12 ) ;
}
static int F_11 ( struct V_10 * V_14 )
{
return F_10 ( V_14 , V_13 , V_15 ) ;
}
static int F_12 ( struct V_10 * V_16 , T_2 * V_17 ,
T_2 * V_18 , T_2 * V_19 )
{
struct V_20 * V_21 ;
const struct V_1 * V_1 ;
F_13 () ;
V_1 = F_14 ( V_16 ) ;
V_21 = F_15 ( V_1 ) ;
if ( ! F_16 ( V_21 ) && ! F_17 ( V_21 ) ) {
* V_17 = F_18 ( * V_17 , V_21 -> V_22 . V_23 ) ;
* V_19 = F_18 ( * V_19 , V_21 -> V_22 . V_23 ) ;
}
F_19 () ;
return 0 ;
}
static int F_20 ( const struct V_1 * V_1 , struct V_24 * V_25 ,
int V_26 , int V_27 )
{
struct V_20 * V_21 ;
int error = 0 ;
V_21 = F_15 ( V_1 ) ;
if ( ! F_16 ( V_21 ) )
error = F_21 ( V_21 , V_26 , V_27 ) ;
return error ;
}
static int F_22 ( int V_28 , struct V_29 * V_29 , T_3 V_30 ,
struct V_31 * V_32 )
{
struct V_20 * V_21 ;
int error = 0 ;
V_21 = F_23 () ;
if ( ! F_16 ( V_21 ) )
error = F_24 ( V_28 , V_21 , V_29 , 0 , V_30 , V_32 ) ;
return error ;
}
static int F_25 ( int V_28 , struct V_29 * V_33 ,
struct V_34 * V_34 , T_3 V_30 ,
struct V_31 * V_32 )
{
struct V_29 V_29 = { V_33 -> V_35 , V_34 } ;
return F_22 ( V_28 , & V_29 , V_30 , V_32 ) ;
}
static int F_26 ( int V_28 , struct V_36 * V_35 ,
struct V_34 * V_34 , T_3 V_30 )
{
struct V_29 V_29 = { V_35 , V_34 } ;
struct V_31 V_32 = { F_27 ( V_34 ) -> V_37 ,
F_27 ( V_34 ) -> V_38
} ;
return F_22 ( V_28 , & V_29 , V_30 , & V_32 ) ;
}
static int F_28 ( int V_28 , struct V_29 * V_33 ,
struct V_34 * V_34 , T_3 V_30 )
{
struct V_39 * V_39 = F_27 ( V_34 ) ;
struct V_31 V_32 = { } ;
if ( ! V_39 || ! V_33 -> V_35 || ! F_29 ( V_34 ) )
return 0 ;
V_32 . V_40 = V_39 -> V_37 ;
V_32 . V_12 = V_39 -> V_38 ;
return F_25 ( V_28 , V_33 , V_34 , V_30 , & V_32 ) ;
}
static int F_30 ( int V_28 , struct V_29 * V_33 , struct V_34 * V_34 ,
T_3 V_30 , T_4 V_12 )
{
struct V_31 V_32 = { F_31 () , V_12 } ;
if ( ! V_33 -> V_35 || ! F_29 ( V_33 -> V_34 ) )
return 0 ;
return F_25 ( V_28 , V_33 , V_34 , V_30 , & V_32 ) ;
}
static int F_32 ( struct V_29 * V_33 , struct V_34 * V_34 )
{
return F_28 ( V_41 , V_33 , V_34 , V_42 ) ;
}
static int F_33 ( struct V_29 * V_33 , struct V_34 * V_34 ,
T_4 V_12 )
{
return F_30 ( V_43 , V_33 , V_34 , V_44 ,
V_45 ) ;
}
static int F_34 ( struct V_29 * V_33 , struct V_34 * V_34 )
{
return F_28 ( V_46 , V_33 , V_34 , V_42 ) ;
}
static int F_35 ( struct V_29 * V_33 , struct V_34 * V_34 ,
T_4 V_12 , unsigned int V_47 )
{
return F_30 ( V_48 , V_33 , V_34 , V_44 , V_12 ) ;
}
static int F_36 ( struct V_29 * V_29 )
{
struct V_31 V_32 = { F_27 ( V_29 -> V_34 ) -> V_37 ,
F_27 ( V_29 -> V_34 ) -> V_38
} ;
if ( ! V_29 -> V_35 || ! F_29 ( V_29 -> V_34 ) )
return 0 ;
return F_22 ( V_49 , V_29 , V_50 | V_51 ,
& V_32 ) ;
}
static int F_37 ( struct V_29 * V_33 , struct V_34 * V_34 ,
const char * V_52 )
{
return F_30 ( V_53 , V_33 , V_34 , V_44 ,
V_54 ) ;
}
static int F_38 ( struct V_34 * V_55 , struct V_29 * V_56 ,
struct V_34 * V_57 )
{
struct V_20 * V_21 ;
int error = 0 ;
if ( ! F_29 ( V_55 ) )
return 0 ;
V_21 = F_39 () ;
if ( ! F_16 ( V_21 ) )
error = F_40 ( V_21 , V_55 , V_56 , V_57 ) ;
return error ;
}
static int F_41 ( struct V_29 * V_58 , struct V_34 * V_55 ,
struct V_29 * V_56 , struct V_34 * V_57 )
{
struct V_20 * V_21 ;
int error = 0 ;
if ( ! F_29 ( V_55 ) )
return 0 ;
V_21 = F_39 () ;
if ( ! F_16 ( V_21 ) ) {
struct V_29 V_59 = { V_58 -> V_35 , V_55 } ;
struct V_29 V_60 = { V_56 -> V_35 , V_57 } ;
struct V_31 V_32 = { F_27 ( V_55 ) -> V_37 ,
F_27 ( V_55 ) -> V_38
} ;
error = F_24 ( V_61 , V_21 , & V_59 , 0 ,
V_62 | V_63 | V_50 |
V_51 | V_42 ,
& V_32 ) ;
if ( ! error )
error = F_24 ( V_64 , V_21 , & V_60 ,
0 , V_50 | V_51 |
V_44 , & V_32 ) ;
}
return error ;
}
static int F_42 ( struct V_29 * V_29 , T_4 V_12 )
{
if ( ! F_29 ( V_29 -> V_34 ) )
return 0 ;
return F_26 ( V_65 , V_29 -> V_35 , V_29 -> V_34 , V_66 ) ;
}
static int F_43 ( struct V_29 * V_29 , T_5 V_40 , T_6 V_67 )
{
struct V_31 V_32 = { F_27 ( V_29 -> V_34 ) -> V_37 ,
F_27 ( V_29 -> V_34 ) -> V_38
} ;
if ( ! F_29 ( V_29 -> V_34 ) )
return 0 ;
return F_22 ( V_68 , V_29 , V_69 , & V_32 ) ;
}
static int F_44 ( const struct V_29 * V_29 )
{
if ( ! F_29 ( V_29 -> V_34 ) )
return 0 ;
return F_26 ( V_70 , V_29 -> V_35 , V_29 -> V_34 ,
V_63 ) ;
}
static int F_45 ( struct V_71 * V_71 , const struct V_1 * V_1 )
{
struct V_72 * V_73 = V_71 -> V_74 ;
struct V_20 * V_21 ;
int error = 0 ;
if ( ! F_29 ( V_71 -> V_75 . V_34 ) )
return 0 ;
if ( V_13 -> V_76 ) {
V_73 -> V_23 = V_77 | V_62 | V_78 ;
return 0 ;
}
V_21 = F_15 ( V_1 ) ;
if ( ! F_16 ( V_21 ) ) {
struct V_39 * V_39 = F_46 ( V_71 ) ;
struct V_31 V_32 = { V_39 -> V_37 , V_39 -> V_38 } ;
error = F_24 ( V_79 , V_21 , & V_71 -> V_75 , 0 ,
F_47 ( V_71 ) , & V_32 ) ;
V_73 -> V_23 = F_47 ( V_71 ) ;
}
return error ;
}
static int F_48 ( struct V_71 * V_71 )
{
V_71 -> V_74 = F_49 ( V_80 ) ;
if ( ! V_71 -> V_74 )
return - V_5 ;
return 0 ;
}
static void F_50 ( struct V_71 * V_71 )
{
struct V_72 * V_4 = V_71 -> V_74 ;
F_51 ( V_4 ) ;
}
static int F_52 ( int V_28 , struct V_71 * V_71 , T_3 V_30 )
{
struct V_72 * V_73 = V_71 -> V_74 ;
struct V_20 * V_21 , * V_81 = F_15 ( V_71 -> V_82 ) ;
int error = 0 ;
F_53 ( ! V_81 ) ;
if ( ! V_71 -> V_75 . V_35 ||
! F_29 ( V_71 -> V_75 . V_34 ) )
return 0 ;
V_21 = F_23 () ;
if ( ! F_16 ( V_21 ) && ! F_16 ( V_81 ) &&
( ( V_81 != V_21 ) || ( V_30 & ~ V_73 -> V_23 ) ) )
error = F_54 ( V_28 , V_21 , V_71 , V_30 ) ;
return error ;
}
static int F_55 ( struct V_71 * V_71 , int V_30 )
{
return F_52 ( V_83 , V_71 , V_30 ) ;
}
static int F_56 ( struct V_71 * V_71 , unsigned int V_84 )
{
T_3 V_30 = V_85 ;
if ( V_84 == V_86 )
V_30 |= V_50 ;
return F_52 ( V_87 , V_71 , V_30 ) ;
}
static int F_57 ( int V_28 , struct V_71 * V_71 , unsigned long V_88 ,
unsigned long V_89 )
{
int V_30 = 0 ;
if ( ! V_71 || ! V_71 -> V_74 )
return 0 ;
if ( V_88 & V_90 )
V_30 |= V_62 ;
if ( ( V_88 & V_91 ) && ! ( V_89 & V_92 ) )
V_30 |= V_50 ;
if ( V_88 & V_93 )
V_30 |= V_78 ;
return F_52 ( V_28 , V_71 , V_30 ) ;
}
static int F_58 ( struct V_71 * V_71 , unsigned long V_94 ,
unsigned long V_88 , unsigned long V_89 )
{
return F_57 ( V_95 , V_71 , V_88 , V_89 ) ;
}
static int F_59 ( struct V_96 * V_97 ,
unsigned long V_94 , unsigned long V_88 )
{
return F_57 ( V_98 , V_97 -> V_99 , V_88 ,
! ( V_97 -> V_100 & V_101 ) ? V_92 : 0 ) ;
}
static int F_60 ( struct V_10 * V_102 , char * V_103 ,
char * * V_104 )
{
int error = - V_105 ;
const struct V_1 * V_1 = F_61 ( V_102 ) ;
struct V_3 * V_4 = F_3 ( V_1 ) ;
struct V_20 * V_21 = NULL ;
if ( strcmp ( V_103 , L_1 ) == 0 )
V_21 = F_62 ( V_4 -> V_21 ) ;
else if ( strcmp ( V_103 , L_2 ) == 0 && V_4 -> V_106 )
V_21 = F_62 ( V_4 -> V_106 ) ;
else if ( strcmp ( V_103 , L_3 ) == 0 && V_4 -> V_107 )
V_21 = F_62 ( V_4 -> V_107 ) ;
else
error = - V_108 ;
if ( V_21 )
error = F_63 ( V_21 , V_104 ) ;
F_64 ( V_21 ) ;
F_65 ( V_1 ) ;
return error ;
}
static int F_66 ( struct V_10 * V_102 , char * V_103 ,
void * V_104 , T_7 V_109 )
{
struct V_110 V_111 ;
struct V_112 V_113 = { 0 ,} ;
char * V_114 , * args = V_104 ;
T_7 V_115 ;
int error ;
if ( V_109 == 0 )
return - V_108 ;
if ( args [ V_109 - 1 ] != '\0' ) {
if ( V_109 == V_116 )
return - V_108 ;
args [ V_109 ] = '\0' ;
}
if ( V_13 != V_102 )
return - V_117 ;
args = V_104 ;
args = F_67 ( args ) ;
V_114 = F_68 ( & args , L_4 ) ;
if ( ! args )
return - V_108 ;
args = F_69 ( args ) ;
if ( ! * args )
return - V_108 ;
V_115 = V_109 - ( args - ( char * ) V_104 ) ;
if ( strcmp ( V_103 , L_1 ) == 0 ) {
if ( strcmp ( V_114 , L_5 ) == 0 ) {
error = F_70 ( args , V_115 ,
! V_118 ) ;
} else if ( strcmp ( V_114 , L_6 ) == 0 ) {
error = F_70 ( args , V_115 ,
V_118 ) ;
} else if ( strcmp ( V_114 , L_7 ) == 0 ) {
error = F_71 ( args , ! V_119 ,
! V_118 ) ;
} else if ( strcmp ( V_114 , L_8 ) == 0 ) {
error = F_71 ( args , ! V_119 ,
V_118 ) ;
} else
goto V_120;
} else if ( strcmp ( V_103 , L_3 ) == 0 ) {
if ( strcmp ( V_114 , L_3 ) == 0 )
error = F_71 ( args , V_119 ,
! V_118 ) ;
else
goto V_120;
} else
return - V_108 ;
if ( ! error )
error = V_109 ;
return error ;
V_120:
V_111 . type = V_121 ;
V_111 . V_113 = & V_113 ;
V_113 . V_21 = F_39 () ;
V_113 . V_28 = V_122 ;
V_113 . V_123 = V_103 ;
V_113 . error = - V_108 ;
F_72 ( V_124 , & V_111 , NULL ) ;
return - V_108 ;
}
static int F_73 ( struct V_10 * V_102 ,
unsigned int V_125 , struct V_126 * V_127 )
{
struct V_20 * V_21 = F_23 () ;
int error = 0 ;
if ( ! F_16 ( V_21 ) )
error = F_74 ( V_21 , V_102 , V_125 , V_127 ) ;
return error ;
}
static int T_8 F_75 ( char * V_128 )
{
unsigned long V_129 ;
int error = F_76 ( V_128 , 0 , & V_129 ) ;
if ( ! error )
V_130 = V_129 ? 1 : 0 ;
return 1 ;
}
static int F_77 ( const char * V_131 , const struct V_132 * V_133 )
{
if ( ! F_78 ( V_134 ) )
return - V_135 ;
if ( V_136 )
return - V_117 ;
return F_79 ( V_131 , V_133 ) ;
}
static int F_80 ( char * V_137 , const struct V_132 * V_133 )
{
if ( ! F_78 ( V_134 ) )
return - V_135 ;
return F_81 ( V_137 , V_133 ) ;
}
static int F_82 ( const char * V_131 , const struct V_132 * V_133 )
{
if ( ! F_78 ( V_134 ) )
return - V_135 ;
return F_79 ( V_131 , V_133 ) ;
}
static int F_83 ( char * V_137 , const struct V_132 * V_133 )
{
if ( ! F_78 ( V_134 ) )
return - V_135 ;
return F_81 ( V_137 , V_133 ) ;
}
static int F_84 ( const char * V_131 , const struct V_132 * V_133 )
{
if ( ! F_78 ( V_134 ) )
return - V_135 ;
return F_85 ( V_131 , V_133 ) ;
}
static int F_86 ( char * V_137 , const struct V_132 * V_133 )
{
if ( ! F_78 ( V_134 ) )
return - V_135 ;
return F_87 ( V_137 , V_133 ) ;
}
static int F_88 ( char * V_137 , struct V_132 * V_133 )
{
if ( ! F_78 ( V_134 ) )
return - V_135 ;
if ( ! V_130 )
return - V_108 ;
return sprintf ( V_137 , L_9 , V_138 [ V_139 ] ) ;
}
static int F_89 ( const char * V_131 , struct V_132 * V_133 )
{
int V_140 ;
if ( ! F_78 ( V_134 ) )
return - V_135 ;
if ( ! V_130 )
return - V_108 ;
if ( ! V_131 )
return - V_108 ;
for ( V_140 = 0 ; V_140 < V_141 ; V_140 ++ ) {
if ( strcmp ( V_131 , V_138 [ V_140 ] ) == 0 ) {
V_139 = V_140 ;
return 0 ;
}
}
return - V_108 ;
}
static int F_90 ( char * V_137 , struct V_132 * V_133 )
{
if ( ! F_78 ( V_134 ) )
return - V_135 ;
if ( ! V_130 )
return - V_108 ;
return sprintf ( V_137 , L_9 , V_142 [ V_143 ] ) ;
}
static int F_91 ( const char * V_131 , struct V_132 * V_133 )
{
int V_140 ;
if ( ! F_78 ( V_134 ) )
return - V_135 ;
if ( ! V_130 )
return - V_108 ;
if ( ! V_131 )
return - V_108 ;
for ( V_140 = 0 ; V_140 < V_144 ; V_140 ++ ) {
if ( strcmp ( V_131 , V_142 [ V_140 ] ) == 0 ) {
V_143 = V_140 ;
return 0 ;
}
}
return - V_108 ;
}
static int T_8 F_92 ( void )
{
struct V_1 * V_1 = (struct V_1 * ) V_13 -> V_145 ;
struct V_3 * V_4 ;
V_4 = F_5 ( V_80 ) ;
if ( ! V_4 )
return - V_5 ;
V_4 -> V_21 = F_93 ( V_146 -> F_16 ) ;
F_3 ( V_1 ) = V_4 ;
return 0 ;
}
static int T_8 F_94 ( void )
{
int error ;
if ( ! V_130 || ! F_95 ( L_10 ) ) {
F_96 ( L_11 ) ;
V_130 = 0 ;
return 0 ;
}
error = F_97 () ;
if ( error ) {
F_98 ( L_12 ) ;
goto V_147;
}
error = F_92 () ;
if ( error ) {
F_98 ( L_13 ) ;
F_99 () ;
goto V_147;
}
F_100 ( V_148 , F_101 ( V_148 ) ) ;
V_149 = 1 ;
if ( V_143 == V_150 )
F_96 ( L_14 ) ;
else if ( V_143 == V_151 )
F_96 ( L_15 ) ;
else
F_96 ( L_16 ) ;
return error ;
V_147:
F_102 () ;
V_130 = 0 ;
return error ;
}
