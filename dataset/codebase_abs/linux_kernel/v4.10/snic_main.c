static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( F_3 ( V_2 ) ) ;
if ( ! V_4 || F_4 ( V_4 ) )
return - V_5 ;
return 0 ;
}
static int
F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_6 ( V_2 -> V_7 ) ;
T_1 V_8 = 0 , V_9 = 0 ;
int V_10 = V_11 * V_12 ;
V_9 = V_13 ;
V_8 = F_7 ( T_1 , V_9 , V_14 ) ;
F_8 ( V_2 , V_8 ) ;
if ( V_6 -> V_15 . V_16 > 1 )
V_10 = V_6 -> V_15 . V_16 * V_12 ;
F_9 ( V_2 -> V_17 , V_10 ) ;
return 0 ;
}
static int
F_10 ( struct V_1 * V_2 , int V_8 )
{
struct V_6 * V_6 = F_6 ( V_2 -> V_7 ) ;
int V_18 = 0 ;
V_18 = F_7 ( T_1 , V_8 , V_14 ) ;
if ( V_18 < V_2 -> V_19 )
F_11 ( & V_6 -> V_20 . V_21 . V_22 ) ;
else if ( V_18 > V_2 -> V_19 )
F_11 ( & V_6 -> V_20 . V_21 . V_23 ) ;
F_12 ( & V_6 -> V_20 . V_21 . V_24 , V_2 -> V_19 ) ;
F_8 ( V_2 , V_18 ) ;
return V_2 -> V_19 ;
}
void
F_13 ( struct V_6 * V_6 )
{
unsigned long V_25 ;
F_14 ( & V_6 -> V_26 , V_25 ) ;
if ( V_6 -> V_27 ) {
F_15 ( & V_6 -> V_26 , V_25 ) ;
return;
}
F_15 ( & V_6 -> V_26 , V_25 ) ;
F_16 ( V_28 -> V_29 , & V_6 -> V_30 ) ;
}
static int
F_17 ( struct V_6 * V_6 )
{
int V_31 = 0 ;
enum V_32 V_33 ;
V_33 = F_18 ( V_6 -> V_34 ) ;
if ( V_33 == V_35 ) {
V_31 = F_19 ( V_6 -> V_34 , V_36 ) ;
} else {
F_20 ( V_6 -> V_37 ,
L_1 ,
V_33 ) ;
V_31 = - 1 ;
}
return V_31 ;
}
static int
F_21 ( struct V_38 * V_34 ,
int (* F_22)( struct V_38 * , int ) ,
int (* F_23)( struct V_38 * , int * ) ,
int V_39 )
{
unsigned long time ;
int V_31 , V_40 ;
int V_41 = 0 ;
V_31 = F_22 ( V_34 , V_39 ) ;
if ( V_31 )
return V_31 ;
time = V_42 + ( V_12 * 2 ) ;
do {
V_31 = F_23 ( V_34 , & V_40 ) ;
if ( V_31 )
return V_31 ;
if ( V_40 )
return 0 ;
F_24 ( V_12 / 10 ) ;
++ V_41 ;
} while ( F_25 ( time , V_42 ) || ( V_41 < 3 ) );
return - V_43 ;
}
static int
F_26 ( struct V_6 * V_6 )
{
unsigned int V_44 ;
int V_31 ;
F_27 ( V_6 -> V_34 ) ;
for ( V_44 = 0 ; V_44 < V_6 -> V_45 ; V_44 ++ )
F_28 ( & V_6 -> V_46 [ V_44 ] ) ;
for ( V_44 = 0 ; V_44 < V_6 -> V_47 ; V_44 ++ ) {
V_31 = F_29 ( & V_6 -> V_48 [ V_44 ] ) ;
if ( V_31 )
return V_31 ;
}
F_30 ( V_6 , - 1 ) ;
F_31 ( V_6 , - 1 ) ;
for ( V_44 = 0 ; V_44 < V_6 -> V_47 ; V_44 ++ )
F_32 ( & V_6 -> V_48 [ V_44 ] , V_49 ) ;
for ( V_44 = 0 ; V_44 < V_6 -> V_50 ; V_44 ++ )
F_33 ( & V_6 -> V_51 [ V_44 ] ) ;
for ( V_44 = 0 ; V_44 < V_6 -> V_45 ; V_44 ++ )
F_34 ( & V_6 -> V_46 [ V_44 ] ) ;
F_35 ( V_6 ) ;
F_36 ( V_6 ) ;
for ( V_44 = 0 ; V_44 < V_52 ; V_44 ++ )
F_37 ( V_6 -> V_53 [ V_44 ] ) ;
return 0 ;
}
static void
F_38 ( struct V_6 * V_6 )
{
if ( V_6 -> V_54 . V_55 )
F_39 ( V_6 -> V_54 . V_55 ) ;
}
static int
F_40 ( struct V_38 * V_34 , int * V_40 )
{
struct V_6 * V_6 = F_41 ( V_34 ) ;
int V_31 ;
int V_56 = 5 ;
do {
V_31 = F_42 ( V_34 , V_40 ) ;
if ( V_31 == 0 )
break;
F_43 ( V_6 -> V_37 , L_2 ) ;
} while ( V_56 -- );
return V_31 ;
}
static int
F_44 ( struct V_57 * V_37 , struct V_58 * V_59 )
{
int V_31 = 0 ;
V_31 = F_45 ( V_37 , & V_59 -> V_60 ) ;
if ( V_31 ) {
F_20 ( V_37 ,
L_3 ,
V_31 ) ;
return V_31 ;
}
F_46 ( V_37 -> V_61 != NULL ) ;
snprintf ( V_37 -> V_62 , sizeof( V_37 -> V_62 ) , L_4 ,
V_37 -> V_63 ) ;
V_37 -> V_61 = F_47 ( V_37 -> V_62 ) ;
if ( ! V_37 -> V_61 ) {
F_20 ( V_37 , L_5 ) ;
V_31 = - V_64 ;
}
return V_31 ;
}
static void
F_48 ( struct V_57 * V_37 )
{
if ( ! V_37 -> V_61 )
return;
F_49 ( V_37 -> V_61 ) ;
V_37 -> V_61 = NULL ;
F_50 ( V_37 ) ;
}
int
F_51 ( struct V_6 * V_6 )
{
return F_52 ( & V_6 -> V_65 ) ;
}
void
F_53 ( struct V_6 * V_6 , enum V_66 V_65 )
{
F_43 ( V_6 -> V_37 , L_6 ,
F_54 ( F_51 ( V_6 ) ) ,
F_54 ( V_65 ) ) ;
F_55 ( & V_6 -> V_65 , V_65 ) ;
}
static int
F_56 ( struct V_58 * V_59 , const struct V_67 * V_68 )
{
struct V_57 * V_37 ;
struct V_6 * V_6 ;
T_2 * V_69 ;
unsigned long V_25 ;
T_1 V_9 = 0 ;
int V_31 , V_44 ;
F_57 ( L_7 ,
V_59 -> V_70 , V_59 -> V_71 , V_59 -> V_72 ,
V_59 -> V_73 ) ;
F_57 ( L_8 ,
V_59 -> V_74 -> V_75 , F_58 ( V_59 -> V_76 ) ,
F_59 ( V_59 -> V_76 ) ) ;
V_37 = F_60 ( & V_77 , sizeof( struct V_6 ) ) ;
if ( ! V_37 ) {
F_61 ( L_9 ) ;
V_31 = - V_64 ;
goto V_78;
}
V_6 = F_6 ( V_37 ) ;
V_6 -> V_37 = V_37 ;
snprintf ( V_6 -> V_79 , sizeof( V_6 -> V_79 ) - 1 , L_10 , V_80 ,
V_37 -> V_63 ) ;
F_43 ( V_37 ,
L_11 ,
V_37 -> V_63 , V_6 , V_37 , V_59 -> V_74 -> V_75 ,
F_58 ( V_59 -> V_76 ) , F_59 ( V_59 -> V_76 ) ) ;
#ifdef F_62
V_31 = F_63 ( V_6 ) ;
if ( V_31 ) {
F_20 ( V_6 -> V_37 ,
L_12 ) ;
F_64 ( V_6 ) ;
}
#endif
F_65 ( V_59 , V_6 ) ;
V_6 -> V_59 = V_59 ;
V_31 = F_66 ( V_59 ) ;
if ( V_31 ) {
F_20 ( V_37 ,
L_13 ,
V_31 ) ;
goto V_81;
}
V_31 = F_67 ( V_59 , V_80 ) ;
if ( V_31 ) {
F_20 ( V_37 ,
L_14 ,
V_31 ) ;
goto V_82;
}
F_68 ( V_59 ) ;
V_31 = F_69 ( V_59 , F_70 ( 43 ) ) ;
if ( V_31 ) {
V_31 = F_69 ( V_59 , F_70 ( 32 ) ) ;
if ( V_31 ) {
F_20 ( V_37 ,
L_15 ,
V_31 ) ;
goto V_83;
}
V_31 = F_71 ( V_59 , F_70 ( 32 ) ) ;
if ( V_31 ) {
F_20 ( V_37 ,
L_16 ,
V_31 ) ;
goto V_83;
}
} else {
V_31 = F_71 ( V_59 , F_70 ( 43 ) ) ;
if ( V_31 ) {
F_20 ( V_37 ,
L_17 ,
V_31 ) ;
goto V_83;
}
}
if ( ! ( F_72 ( V_59 , 0 ) & V_84 ) ) {
F_20 ( V_37 , L_18 ) ;
V_31 = - V_85 ;
goto V_83;
}
V_6 -> V_54 . V_55 = F_73 ( V_59 , 0 , 0 ) ;
if ( ! V_6 -> V_54 . V_55 ) {
F_20 ( V_37 ,
L_19 ) ;
V_31 = - V_85 ;
goto V_83;
}
V_6 -> V_54 . V_86 = F_74 ( V_59 , 0 ) ;
V_6 -> V_54 . V_87 = F_75 ( V_59 , 0 ) ;
F_46 ( V_6 -> V_54 . V_86 == 0 ) ;
V_6 -> V_34 = F_76 ( NULL , V_6 , V_59 , & V_6 -> V_54 , 1 ) ;
if ( ! V_6 -> V_34 ) {
F_20 ( V_37 , L_20 ) ;
V_31 = - V_85 ;
goto V_88;
}
V_31 = F_77 ( V_6 -> V_34 , 0 ) ;
if ( V_31 ) {
F_43 ( V_37 , L_21 , V_31 ) ;
goto V_89;
}
V_31 = F_21 ( V_6 -> V_34 , V_90 , F_40 , 0 ) ;
if ( V_31 ) {
F_20 ( V_37 ,
L_22 ,
V_31 ) ;
goto V_89;
}
V_31 = F_78 ( V_6 -> V_34 , 0 ) ;
if ( V_31 ) {
F_20 ( V_37 ,
L_23 ,
V_31 ) ;
goto V_91;
}
V_31 = F_79 ( V_6 ) ;
if ( V_31 ) {
F_20 ( V_37 ,
L_24 ,
V_31 ) ;
goto V_91;
}
V_9 = V_6 -> V_92 . V_93 ;
if ( V_9 != V_94 )
V_37 -> V_95 = F_7 ( T_1 , V_96 ,
F_80 ( T_1 , V_97 , V_9 ) ) ;
V_6 -> V_98 = V_37 -> V_95 ;
V_37 -> V_99 = V_6 -> V_92 . V_100 ;
V_37 -> V_101 = V_102 ;
V_37 -> V_103 = V_104 ;
F_81 ( V_6 ) ;
V_31 = F_82 ( V_6 ) ;
if ( V_31 ) {
F_20 ( V_37 ,
L_25 ,
V_31 ) ;
goto V_91;
}
V_31 = F_83 ( V_6 ) ;
if ( V_31 ) {
F_20 ( V_37 ,
L_26 ,
V_31 ) ;
goto V_105;
}
F_84 ( & V_6 -> V_106 ) ;
F_84 ( & V_6 -> V_107 ) ;
F_85 ( & V_6 -> V_108 ) ;
F_85 ( & V_6 -> V_26 ) ;
for ( V_44 = 0 ; V_44 < V_109 ; V_44 ++ )
F_85 ( & V_6 -> V_110 [ V_44 ] ) ;
for ( V_44 = 0 ; V_44 < V_111 ; V_44 ++ )
F_85 ( & V_6 -> V_112 [ V_44 ] ) ;
V_69 = F_86 ( 2 ,
V_28 -> V_113 [ V_114 ] ) ;
if ( ! V_69 ) {
F_20 ( V_37 , L_27 ) ;
V_31 = - V_64 ;
goto V_115;
}
V_6 -> V_53 [ V_114 ] = V_69 ;
V_69 = F_86 ( 2 ,
V_28 -> V_113 [ V_116 ] ) ;
if ( ! V_69 ) {
F_20 ( V_37 , L_28 ) ;
V_31 = - V_64 ;
goto V_117;
}
V_6 -> V_53 [ V_116 ] = V_69 ;
V_69 = F_86 ( 2 ,
V_28 -> V_113 [ V_118 ] ) ;
if ( ! V_69 ) {
F_20 ( V_37 , L_29 ) ;
V_31 = - V_64 ;
goto V_119;
}
V_6 -> V_53 [ V_118 ] = V_69 ;
F_55 ( & V_6 -> V_65 , V_120 ) ;
F_55 ( & V_6 -> V_121 , 0 ) ;
V_31 = F_17 ( V_6 ) ;
if ( V_31 ) {
F_20 ( V_37 ,
L_30 ,
V_31 ) ;
goto V_122;
}
F_14 ( & V_28 -> V_123 , V_25 ) ;
F_87 ( & V_6 -> V_106 , & V_28 -> V_124 ) ;
F_15 ( & V_28 -> V_123 , V_25 ) ;
F_88 ( & V_6 -> V_125 ) ;
F_89 ( & V_6 -> V_126 , V_127 ) ;
F_89 ( & V_6 -> V_128 , V_129 ) ;
F_89 ( & V_6 -> V_30 , V_130 ) ;
for ( V_44 = 0 ; V_44 < V_6 -> V_47 ; V_44 ++ )
F_90 ( & V_6 -> V_48 [ V_44 ] ) ;
V_31 = F_91 ( V_6 -> V_34 ) ;
if ( V_31 ) {
F_20 ( V_37 ,
L_31 ,
V_31 ) ;
goto V_131;
}
V_31 = F_92 ( V_6 ) ;
if ( V_31 ) {
F_20 ( V_37 , L_32 , V_31 ) ;
goto V_132;
}
for ( V_44 = 0 ; V_44 < V_6 -> V_45 ; V_44 ++ )
F_93 ( & V_6 -> V_46 [ V_44 ] ) ;
V_31 = F_94 ( V_6 ) ;
if ( V_31 ) {
F_20 ( V_37 ,
L_33 ,
V_31 ) ;
goto V_133;
}
V_31 = F_44 ( V_37 , V_59 ) ;
if ( V_31 ) {
F_20 ( V_37 ,
L_34 ,
V_31 ) ;
goto V_133;
}
F_53 ( V_6 , V_134 ) ;
V_31 = F_95 ( V_6 ) ;
if ( V_31 ) {
F_20 ( V_37 , L_35 ,
V_31 ) ;
goto V_133;
}
F_43 ( V_37 , L_36 ) ;
return 0 ;
V_133:
F_35 ( V_6 ) ;
for ( V_44 = 0 ; V_44 < V_6 -> V_45 ; V_44 ++ )
F_28 ( & V_6 -> V_46 [ V_44 ] ) ;
F_96 ( V_6 ) ;
V_132:
F_27 ( V_6 -> V_34 ) ;
V_131:
F_97 ( V_6 -> V_34 ) ;
for ( V_44 = 0 ; V_44 < V_6 -> V_47 ; V_44 ++ ) {
int V_135 = 0 ;
V_135 = F_29 ( & V_6 -> V_48 [ V_44 ] ) ;
if ( V_135 ) {
F_20 ( V_37 ,
L_37 , V_135 ) ;
break;
}
}
F_48 ( V_6 -> V_37 ) ;
V_122:
F_37 ( V_6 -> V_53 [ V_118 ] ) ;
V_119:
F_37 ( V_6 -> V_53 [ V_116 ] ) ;
V_117:
F_37 ( V_6 -> V_53 [ V_114 ] ) ;
V_115:
F_98 ( V_6 ) ;
V_105:
F_99 ( V_6 ) ;
V_91:
F_100 ( V_6 -> V_34 ) ;
V_89:
F_101 ( V_6 -> V_34 ) ;
V_88:
F_38 ( V_6 ) ;
V_83:
F_102 ( V_59 ) ;
V_82:
F_103 ( V_59 ) ;
V_81:
#ifdef F_62
F_64 ( V_6 ) ;
#endif
F_104 ( V_37 ) ;
F_65 ( V_59 , NULL ) ;
V_78:
F_57 ( L_38 ,
V_59 -> V_74 -> V_75 , F_58 ( V_59 -> V_76 ) ,
F_59 ( V_59 -> V_76 ) ) ;
return V_31 ;
}
static void
F_105 ( struct V_58 * V_59 )
{
struct V_6 * V_6 = F_106 ( V_59 ) ;
unsigned long V_25 ;
if ( ! V_6 ) {
F_57 ( L_39 ,
V_59 -> V_74 -> V_75 , F_58 ( V_59 -> V_76 ) ,
F_59 ( V_59 -> V_76 ) ) ;
return;
}
F_53 ( V_6 , V_136 ) ;
F_14 ( & V_6 -> V_26 , V_25 ) ;
V_6 -> V_27 = 1 ;
F_15 ( & V_6 -> V_26 , V_25 ) ;
F_107 ( V_28 -> V_29 ) ;
F_108 ( V_6 ) ;
F_14 ( & V_6 -> V_26 , V_25 ) ;
V_6 -> V_137 = 1 ;
F_15 ( & V_6 -> V_26 , V_25 ) ;
F_26 ( V_6 ) ;
F_14 ( & V_28 -> V_123 , V_25 ) ;
F_109 ( & V_6 -> V_106 ) ;
F_15 ( & V_28 -> V_123 , V_25 ) ;
F_110 ( V_6 ) ;
#ifdef F_62
F_64 ( V_6 ) ;
#endif
F_48 ( V_6 -> V_37 ) ;
F_97 ( V_6 -> V_34 ) ;
F_96 ( V_6 ) ;
F_98 ( V_6 ) ;
F_99 ( V_6 ) ;
F_100 ( V_6 -> V_34 ) ;
F_101 ( V_6 -> V_34 ) ;
F_38 ( V_6 ) ;
F_102 ( V_59 ) ;
F_103 ( V_59 ) ;
F_65 ( V_59 , NULL ) ;
F_104 ( V_6 -> V_37 ) ;
}
static int
F_111 ( void )
{
int V_31 = 0 ;
struct V_138 * V_139 ;
T_3 V_87 = 0 ;
V_28 = F_112 ( sizeof( * V_28 ) , V_140 ) ;
if ( ! V_28 ) {
F_61 ( L_40 ) ;
V_31 = - V_64 ;
goto V_141;
}
#ifdef F_62
V_31 = F_113 () ;
if ( V_31 < 0 ) {
F_61 ( L_41 ) ;
F_114 () ;
}
V_31 = F_115 () ;
if ( V_31 < 0 ) {
F_61 ( L_42 ) ;
F_116 () ;
}
#endif
F_84 ( & V_28 -> V_124 ) ;
F_85 ( & V_28 -> V_123 ) ;
V_87 = sizeof( struct V_142 ) ;
V_87 += sizeof( struct V_143 ) + sizeof( struct V_144 ) ;
V_139 = F_117 ( L_43 , V_87 , V_145 ,
V_146 , NULL ) ;
if ( ! V_139 ) {
F_61 ( L_44 ) ;
V_31 = - V_64 ;
goto V_147;
}
V_28 -> V_113 [ V_114 ] = V_139 ;
V_87 = sizeof( struct V_142 ) ;
V_87 += sizeof( struct V_143 ) + sizeof( struct V_148 ) ;
V_139 = F_117 ( L_45 , V_87 , V_145 ,
V_146 , NULL ) ;
if ( ! V_139 ) {
F_61 ( L_46 ) ;
V_31 = - V_64 ;
goto V_149;
}
V_28 -> V_113 [ V_116 ] = V_139 ;
V_87 = sizeof( struct V_143 ) ;
V_139 = F_117 ( L_45 , V_87 , V_145 ,
V_146 , NULL ) ;
if ( ! V_139 ) {
F_61 ( L_47 ) ;
V_31 = - V_64 ;
goto V_150;
}
V_28 -> V_113 [ V_118 ] = V_139 ;
V_28 -> V_29 = F_47 ( L_48 ) ;
if ( ! V_28 -> V_29 ) {
F_61 ( L_49 ) ;
V_31 = - V_64 ;
goto V_151;
}
return V_31 ;
V_151:
F_118 ( V_28 -> V_113 [ V_118 ] ) ;
V_150:
F_118 ( V_28 -> V_113 [ V_116 ] ) ;
V_149:
F_118 ( V_28 -> V_113 [ V_114 ] ) ;
V_147:
#ifdef F_62
F_116 () ;
F_114 () ;
#endif
F_119 ( V_28 ) ;
V_28 = NULL ;
V_141:
return V_31 ;
}
static void
F_120 ( void )
{
F_46 ( V_28 == NULL ) ;
F_49 ( V_28 -> V_29 ) ;
F_118 ( V_28 -> V_113 [ V_118 ] ) ;
F_118 ( V_28 -> V_113 [ V_116 ] ) ;
F_118 ( V_28 -> V_113 [ V_114 ] ) ;
#ifdef F_62
F_116 () ;
F_114 () ;
#endif
F_119 ( V_28 ) ;
V_28 = NULL ;
}
static int T_4
F_121 ( void )
{
int V_31 = 0 ;
#ifndef F_122
F_57 ( L_50 ) ;
F_123 ( V_152 , V_153 ) ;
#endif
F_57 ( L_51 , V_154 , V_155 ) ;
V_31 = F_111 () ;
if ( V_31 ) {
F_61 ( L_52 ) ;
return V_31 ;
}
V_31 = F_124 ( & V_156 ) ;
if ( V_31 < 0 ) {
F_61 ( L_53 ) ;
goto V_157;
}
return V_31 ;
V_157:
F_120 () ;
return V_31 ;
}
static void T_5
F_125 ( void )
{
F_126 ( & V_156 ) ;
F_120 () ;
}
