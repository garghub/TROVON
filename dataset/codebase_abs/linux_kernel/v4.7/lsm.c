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
static int F_22 ( int V_28 , const struct V_29 * V_29 , T_3 V_30 ,
struct V_31 * V_32 )
{
struct V_20 * V_21 ;
int error = 0 ;
V_21 = F_23 () ;
if ( ! F_16 ( V_21 ) )
error = F_24 ( V_28 , V_21 , V_29 , 0 , V_30 , V_32 ) ;
return error ;
}
static int F_25 ( int V_28 , const struct V_29 * V_33 ,
struct V_34 * V_34 , T_3 V_30 ,
struct V_31 * V_32 )
{
struct V_29 V_29 = { V_33 -> V_35 , V_34 } ;
return F_22 ( V_28 , & V_29 , V_30 , V_32 ) ;
}
static inline int F_26 ( int V_28 , const struct V_29 * V_29 , T_3 V_30 )
{
struct V_31 V_32 = { F_27 ( V_29 -> V_34 ) -> V_36 ,
F_27 ( V_29 -> V_34 ) -> V_37
} ;
if ( ! F_28 ( V_29 -> V_34 ) )
return 0 ;
return F_22 ( V_28 , V_29 , V_30 , & V_32 ) ;
}
static int F_29 ( int V_28 , const struct V_29 * V_33 ,
struct V_34 * V_34 , T_3 V_30 )
{
struct V_38 * V_38 = F_27 ( V_34 ) ;
struct V_31 V_32 = { } ;
if ( ! V_38 || ! F_28 ( V_34 ) )
return 0 ;
V_32 . V_39 = V_38 -> V_36 ;
V_32 . V_12 = V_38 -> V_37 ;
return F_25 ( V_28 , V_33 , V_34 , V_30 , & V_32 ) ;
}
static int F_30 ( int V_28 , const struct V_29 * V_33 ,
struct V_34 * V_34 , T_3 V_30 , T_4 V_12 )
{
struct V_31 V_32 = { F_31 () , V_12 } ;
if ( ! F_28 ( V_33 -> V_34 ) )
return 0 ;
return F_25 ( V_28 , V_33 , V_34 , V_30 , & V_32 ) ;
}
static int F_32 ( const struct V_29 * V_33 , struct V_34 * V_34 )
{
return F_29 ( V_40 , V_33 , V_34 , V_41 ) ;
}
static int F_33 ( const struct V_29 * V_33 , struct V_34 * V_34 ,
T_4 V_12 )
{
return F_30 ( V_42 , V_33 , V_34 , V_43 ,
V_44 ) ;
}
static int F_34 ( const struct V_29 * V_33 , struct V_34 * V_34 )
{
return F_29 ( V_45 , V_33 , V_34 , V_41 ) ;
}
static int F_35 ( const struct V_29 * V_33 , struct V_34 * V_34 ,
T_4 V_12 , unsigned int V_46 )
{
return F_30 ( V_47 , V_33 , V_34 , V_43 , V_12 ) ;
}
static int F_36 ( const struct V_29 * V_29 )
{
return F_26 ( V_48 , V_29 , V_49 | V_50 ) ;
}
static int F_37 ( const struct V_29 * V_33 , struct V_34 * V_34 ,
const char * V_51 )
{
return F_30 ( V_52 , V_33 , V_34 , V_43 ,
V_53 ) ;
}
static int F_38 ( struct V_34 * V_54 , const struct V_29 * V_55 ,
struct V_34 * V_56 )
{
struct V_20 * V_21 ;
int error = 0 ;
if ( ! F_28 ( V_54 ) )
return 0 ;
V_21 = F_39 () ;
if ( ! F_16 ( V_21 ) )
error = F_40 ( V_21 , V_54 , V_55 , V_56 ) ;
return error ;
}
static int F_41 ( const struct V_29 * V_57 , struct V_34 * V_54 ,
const struct V_29 * V_55 , struct V_34 * V_56 )
{
struct V_20 * V_21 ;
int error = 0 ;
if ( ! F_28 ( V_54 ) )
return 0 ;
V_21 = F_39 () ;
if ( ! F_16 ( V_21 ) ) {
struct V_29 V_58 = { V_57 -> V_35 , V_54 } ;
struct V_29 V_59 = { V_55 -> V_35 , V_56 } ;
struct V_31 V_32 = { F_27 ( V_54 ) -> V_36 ,
F_27 ( V_54 ) -> V_37
} ;
error = F_24 ( V_60 , V_21 , & V_58 , 0 ,
V_61 | V_62 | V_49 |
V_50 | V_41 ,
& V_32 ) ;
if ( ! error )
error = F_24 ( V_63 , V_21 , & V_59 ,
0 , V_49 | V_50 |
V_43 , & V_32 ) ;
}
return error ;
}
static int F_42 ( const struct V_29 * V_29 , T_4 V_12 )
{
return F_26 ( V_64 , V_29 , V_65 ) ;
}
static int F_43 ( const struct V_29 * V_29 , T_5 V_39 , T_6 V_66 )
{
return F_26 ( V_67 , V_29 , V_68 ) ;
}
static int F_44 ( const struct V_29 * V_29 )
{
return F_26 ( V_69 , V_29 , V_62 ) ;
}
static int F_45 ( struct V_70 * V_70 , const struct V_1 * V_1 )
{
struct V_71 * V_72 = V_70 -> V_73 ;
struct V_20 * V_21 ;
int error = 0 ;
if ( ! F_28 ( V_70 -> V_74 . V_34 ) )
return 0 ;
if ( V_13 -> V_75 ) {
V_72 -> V_23 = V_76 | V_61 | V_77 ;
return 0 ;
}
V_21 = F_15 ( V_1 ) ;
if ( ! F_16 ( V_21 ) ) {
struct V_38 * V_38 = F_46 ( V_70 ) ;
struct V_31 V_32 = { V_38 -> V_36 , V_38 -> V_37 } ;
error = F_24 ( V_78 , V_21 , & V_70 -> V_74 , 0 ,
F_47 ( V_70 ) , & V_32 ) ;
V_72 -> V_23 = F_47 ( V_70 ) ;
}
return error ;
}
static int F_48 ( struct V_70 * V_70 )
{
V_70 -> V_73 = F_49 ( V_79 ) ;
if ( ! V_70 -> V_73 )
return - V_5 ;
return 0 ;
}
static void F_50 ( struct V_70 * V_70 )
{
struct V_71 * V_4 = V_70 -> V_73 ;
F_51 ( V_4 ) ;
}
static int F_52 ( int V_28 , struct V_70 * V_70 , T_3 V_30 )
{
struct V_71 * V_72 = V_70 -> V_73 ;
struct V_20 * V_21 , * V_80 = F_15 ( V_70 -> V_81 ) ;
int error = 0 ;
F_53 ( ! V_80 ) ;
if ( ! V_70 -> V_74 . V_35 ||
! F_28 ( V_70 -> V_74 . V_34 ) )
return 0 ;
V_21 = F_23 () ;
if ( ! F_16 ( V_21 ) && ! F_16 ( V_80 ) &&
( ( V_80 != V_21 ) || ( V_30 & ~ V_72 -> V_23 ) ) )
error = F_54 ( V_28 , V_21 , V_70 , V_30 ) ;
return error ;
}
static int F_55 ( struct V_70 * V_70 , int V_30 )
{
return F_52 ( V_82 , V_70 , V_30 ) ;
}
static int F_56 ( struct V_70 * V_70 , unsigned int V_83 )
{
T_3 V_30 = V_84 ;
if ( V_83 == V_85 )
V_30 |= V_49 ;
return F_52 ( V_86 , V_70 , V_30 ) ;
}
static int F_57 ( int V_28 , struct V_70 * V_70 , unsigned long V_87 ,
unsigned long V_88 )
{
int V_30 = 0 ;
if ( ! V_70 || ! V_70 -> V_73 )
return 0 ;
if ( V_87 & V_89 )
V_30 |= V_61 ;
if ( ( V_87 & V_90 ) && ! ( V_88 & V_91 ) )
V_30 |= V_49 ;
if ( V_87 & V_92 )
V_30 |= V_77 ;
return F_52 ( V_28 , V_70 , V_30 ) ;
}
static int F_58 ( struct V_70 * V_70 , unsigned long V_93 ,
unsigned long V_87 , unsigned long V_88 )
{
return F_57 ( V_94 , V_70 , V_87 , V_88 ) ;
}
static int F_59 ( struct V_95 * V_96 ,
unsigned long V_93 , unsigned long V_87 )
{
return F_57 ( V_97 , V_96 -> V_98 , V_87 ,
! ( V_96 -> V_99 & V_100 ) ? V_91 : 0 ) ;
}
static int F_60 ( struct V_10 * V_101 , char * V_102 ,
char * * V_103 )
{
int error = - V_104 ;
const struct V_1 * V_1 = F_61 ( V_101 ) ;
struct V_3 * V_4 = F_3 ( V_1 ) ;
struct V_20 * V_21 = NULL ;
if ( strcmp ( V_102 , L_1 ) == 0 )
V_21 = F_62 ( V_4 -> V_21 ) ;
else if ( strcmp ( V_102 , L_2 ) == 0 && V_4 -> V_105 )
V_21 = F_62 ( V_4 -> V_105 ) ;
else if ( strcmp ( V_102 , L_3 ) == 0 && V_4 -> V_106 )
V_21 = F_62 ( V_4 -> V_106 ) ;
else
error = - V_107 ;
if ( V_21 )
error = F_63 ( V_21 , V_103 ) ;
F_64 ( V_21 ) ;
F_65 ( V_1 ) ;
return error ;
}
static int F_66 ( struct V_10 * V_101 , char * V_102 ,
void * V_103 , T_7 V_108 )
{
struct V_109 V_110 ;
struct V_111 V_112 = { 0 ,} ;
char * V_113 , * V_114 = NULL , * args = V_103 ;
T_7 V_115 ;
int error ;
if ( V_108 == 0 )
return - V_107 ;
if ( V_13 != V_101 )
return - V_116 ;
if ( args [ V_108 - 1 ] != '\0' ) {
V_114 = args = F_67 ( V_108 + 1 , V_79 ) ;
if ( ! args )
return - V_5 ;
memcpy ( args , V_103 , V_108 ) ;
args [ V_108 ] = '\0' ;
}
error = - V_107 ;
args = F_68 ( args ) ;
V_113 = F_69 ( & args , L_4 ) ;
if ( ! args )
goto V_117;
args = F_70 ( args ) ;
if ( ! * args )
goto V_117;
V_115 = V_108 - ( args - ( char * ) V_103 ) ;
if ( strcmp ( V_102 , L_1 ) == 0 ) {
if ( strcmp ( V_113 , L_5 ) == 0 ) {
error = F_71 ( args , V_115 ,
! V_118 ) ;
} else if ( strcmp ( V_113 , L_6 ) == 0 ) {
error = F_71 ( args , V_115 ,
V_118 ) ;
} else if ( strcmp ( V_113 , L_7 ) == 0 ) {
error = F_72 ( args , ! V_119 ,
! V_118 ) ;
} else if ( strcmp ( V_113 , L_8 ) == 0 ) {
error = F_72 ( args , ! V_119 ,
V_118 ) ;
} else
goto V_120;
} else if ( strcmp ( V_102 , L_3 ) == 0 ) {
if ( strcmp ( V_113 , L_3 ) == 0 )
error = F_72 ( args , V_119 ,
! V_118 ) ;
else
goto V_120;
} else
goto V_120;
if ( ! error )
error = V_108 ;
V_117:
F_73 ( V_114 ) ;
return error ;
V_120:
V_110 . type = V_121 ;
V_110 . V_112 = & V_112 ;
V_112 . V_21 = F_39 () ;
V_112 . V_28 = V_122 ;
V_112 . V_123 = V_102 ;
V_112 . error = error = - V_107 ;
F_74 ( V_124 , & V_110 , NULL ) ;
goto V_117;
}
static int F_75 ( struct V_10 * V_101 ,
unsigned int V_125 , struct V_126 * V_127 )
{
struct V_20 * V_21 = F_23 () ;
int error = 0 ;
if ( ! F_16 ( V_21 ) )
error = F_76 ( V_21 , V_101 , V_125 , V_127 ) ;
return error ;
}
static int T_8 F_77 ( char * V_128 )
{
unsigned long V_129 ;
int error = F_78 ( V_128 , 0 , & V_129 ) ;
if ( ! error )
V_130 = V_129 ? 1 : 0 ;
return 1 ;
}
static int F_79 ( const char * V_131 , const struct V_132 * V_133 )
{
if ( ! F_80 ( V_134 ) )
return - V_135 ;
if ( V_136 )
return - V_116 ;
return F_81 ( V_131 , V_133 ) ;
}
static int F_82 ( char * V_137 , const struct V_132 * V_133 )
{
if ( ! F_80 ( V_134 ) )
return - V_135 ;
return F_83 ( V_137 , V_133 ) ;
}
static int F_84 ( const char * V_131 , const struct V_132 * V_133 )
{
if ( ! F_80 ( V_134 ) )
return - V_135 ;
return F_81 ( V_131 , V_133 ) ;
}
static int F_85 ( char * V_137 , const struct V_132 * V_133 )
{
if ( ! F_80 ( V_134 ) )
return - V_135 ;
return F_83 ( V_137 , V_133 ) ;
}
static int F_86 ( const char * V_131 , const struct V_132 * V_133 )
{
if ( ! F_80 ( V_134 ) )
return - V_135 ;
return F_87 ( V_131 , V_133 ) ;
}
static int F_88 ( char * V_137 , const struct V_132 * V_133 )
{
if ( ! F_80 ( V_134 ) )
return - V_135 ;
return F_89 ( V_137 , V_133 ) ;
}
static int F_90 ( char * V_137 , struct V_132 * V_133 )
{
if ( ! F_80 ( V_134 ) )
return - V_135 ;
if ( ! V_130 )
return - V_107 ;
return sprintf ( V_137 , L_9 , V_138 [ V_139 ] ) ;
}
static int F_91 ( const char * V_131 , struct V_132 * V_133 )
{
int V_140 ;
if ( ! F_80 ( V_134 ) )
return - V_135 ;
if ( ! V_130 )
return - V_107 ;
if ( ! V_131 )
return - V_107 ;
for ( V_140 = 0 ; V_140 < V_141 ; V_140 ++ ) {
if ( strcmp ( V_131 , V_138 [ V_140 ] ) == 0 ) {
V_139 = V_140 ;
return 0 ;
}
}
return - V_107 ;
}
static int F_92 ( char * V_137 , struct V_132 * V_133 )
{
if ( ! F_80 ( V_134 ) )
return - V_135 ;
if ( ! V_130 )
return - V_107 ;
return sprintf ( V_137 , L_9 , V_142 [ V_143 ] ) ;
}
static int F_93 ( const char * V_131 , struct V_132 * V_133 )
{
int V_140 ;
if ( ! F_80 ( V_134 ) )
return - V_135 ;
if ( ! V_130 )
return - V_107 ;
if ( ! V_131 )
return - V_107 ;
for ( V_140 = 0 ; V_140 < V_144 ; V_140 ++ ) {
if ( strcmp ( V_131 , V_142 [ V_140 ] ) == 0 ) {
V_143 = V_140 ;
return 0 ;
}
}
return - V_107 ;
}
static int T_8 F_94 ( void )
{
struct V_1 * V_1 = (struct V_1 * ) V_13 -> V_145 ;
struct V_3 * V_4 ;
V_4 = F_5 ( V_79 ) ;
if ( ! V_4 )
return - V_5 ;
V_4 -> V_21 = F_95 ( V_146 -> F_16 ) ;
F_3 ( V_1 ) = V_4 ;
return 0 ;
}
static int T_8 F_96 ( void )
{
int error ;
if ( ! V_130 || ! F_97 ( L_10 ) ) {
F_98 ( L_11 ) ;
V_130 = 0 ;
return 0 ;
}
error = F_99 () ;
if ( error ) {
F_100 ( L_12 ) ;
goto V_147;
}
error = F_94 () ;
if ( error ) {
F_100 ( L_13 ) ;
F_101 () ;
goto V_147;
}
F_102 ( V_148 , F_103 ( V_148 ) ) ;
V_149 = 1 ;
if ( V_143 == V_150 )
F_98 ( L_14 ) ;
else if ( V_143 == V_151 )
F_98 ( L_15 ) ;
else
F_98 ( L_16 ) ;
return error ;
V_147:
F_104 () ;
V_130 = 0 ;
return error ;
}
