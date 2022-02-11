struct V_1 * F_1 ( const char * V_2 )
{
T_1 V_3 ;
for ( V_3 = 0 ; V_4 [ V_3 ] != NULL ; V_3 ++ ) {
if ( ! strcmp ( V_4 [ V_3 ] -> V_2 , V_2 ) )
break;
}
return V_4 [ V_3 ] ;
}
static struct V_1 * F_2 ( T_2 type )
{
T_1 V_3 ;
for ( V_3 = 0 ; V_4 [ V_3 ] != NULL ; V_3 ++ ) {
if ( V_4 [ V_3 ] -> V_5 == type )
break;
}
return V_4 [ V_3 ] ;
}
void F_3 ( char * V_6 , int V_7 , struct V_8 * V_9 )
{
char V_10 [ V_11 ] ;
struct V_1 * V_12 ;
int V_13 ;
V_12 = F_2 ( V_9 -> V_14 ) ;
if ( V_12 && ! V_12 -> V_15 ( V_9 , V_10 , sizeof( V_10 ) ) )
V_13 = F_4 ( V_6 , V_7 , L_1 , V_12 -> V_2 , V_10 ) ;
else {
T_1 V_3 ;
V_13 = F_4 ( V_6 , V_7 , L_2 , V_9 -> V_14 ) ;
for ( V_3 = 0 ; V_3 < sizeof( V_9 -> V_16 ) ; V_3 ++ )
V_13 += F_4 ( V_6 - V_13 , V_7 + V_13 ,
L_3 , V_9 -> V_16 [ V_3 ] ) ;
}
}
static int F_5 ( const char * V_2 ,
struct V_17 * V_18 )
{
char V_19 [ V_20 ] ;
char * V_21 ;
char * V_22 ;
T_1 V_23 ;
T_1 V_24 ;
V_19 [ V_20 - 1 ] = 0 ;
strncpy ( V_19 , V_2 , V_20 ) ;
if ( V_19 [ V_20 - 1 ] != 0 )
return 0 ;
V_21 = V_19 ;
V_22 = strchr ( V_21 , ':' ) ;
if ( V_22 == NULL )
return 0 ;
* ( V_22 ++ ) = 0 ;
V_23 = V_22 - V_21 ;
V_24 = strlen ( V_22 ) + 1 ;
if ( ( V_23 <= 1 ) || ( V_23 > V_25 ) ||
( V_24 <= 1 ) || ( V_24 > V_26 ) )
return 0 ;
if ( V_18 ) {
strcpy ( V_18 -> V_21 , V_21 ) ;
strcpy ( V_18 -> V_22 , V_22 ) ;
}
return 1 ;
}
struct V_27 * F_6 ( struct V_28 * V_28 , const char * V_2 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
struct V_27 * V_32 ;
T_1 V_3 ;
for ( V_3 = 0 ; V_3 < V_33 ; V_3 ++ ) {
V_32 = F_8 ( V_30 -> V_34 [ V_3 ] ) ;
if ( V_32 && ( ! strcmp ( V_32 -> V_2 , V_2 ) ) )
return V_32 ;
}
return NULL ;
}
void F_9 ( struct V_28 * V_28 , T_1 V_35 , T_1 V_36 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
struct V_27 * V_32 ;
F_10 () ;
V_32 = F_11 ( V_30 -> V_34 [ V_35 ] ) ;
if ( V_32 ) {
F_12 ( V_28 , & V_32 -> V_37 , V_36 , true ) ;
F_13 ( V_32 -> V_38 ) ;
}
F_14 () ;
}
void F_15 ( struct V_28 * V_28 , T_1 V_35 , T_1 V_36 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
struct V_27 * V_32 ;
F_10 () ;
V_32 = F_11 ( V_30 -> V_34 [ V_35 ] ) ;
if ( V_32 ) {
F_12 ( V_28 , & V_32 -> V_37 , V_36 , false ) ;
F_16 ( V_32 -> V_38 ) ;
}
F_14 () ;
}
static int F_17 ( struct V_28 * V_28 , const char * V_2 ,
T_1 V_39 , T_1 V_40 ,
struct V_41 * V_42 [] )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
struct V_27 * V_32 ;
struct V_1 * V_12 ;
struct V_17 V_43 ;
char V_44 [ 16 ] ;
T_1 V_35 ;
T_1 V_45 ;
T_1 V_3 ;
int V_46 = - V_47 ;
if ( ! V_30 -> V_48 ) {
F_18 ( L_4 ,
V_2 ) ;
return - V_49 ;
}
if ( ! F_5 ( V_2 , & V_43 ) ) {
F_18 ( L_5 , V_2 ) ;
return - V_47 ;
}
if ( F_19 ( V_39 ) &&
( V_39 != V_30 -> V_48 ) ) {
if ( F_20 ( V_39 , V_30 -> V_48 ) ) {
V_39 = V_30 -> V_48 & V_50 ;
V_46 = 0 ;
} else if ( F_21 ( V_28 , V_39 ) )
V_46 = 0 ;
}
if ( V_46 ) {
F_18 ( L_6 ,
V_2 ) ;
return - V_47 ;
}
if ( ( V_40 > V_51 ) &&
( V_40 != V_52 ) ) {
F_18 ( L_7 , V_2 ) ;
return - V_47 ;
}
V_12 = F_1 ( V_43 . V_21 ) ;
if ( ! V_12 ) {
F_18 ( L_8 ,
V_2 , V_43 . V_21 ) ;
return - V_47 ;
}
if ( V_40 == V_52 )
V_40 = V_12 -> V_40 ;
V_53:
V_35 = V_33 ;
V_45 = 1 ;
for ( V_3 = V_33 ; V_3 -- != 0 ; ) {
V_32 = F_8 ( V_30 -> V_34 [ V_3 ] ) ;
if ( ! V_32 ) {
V_35 = V_3 ;
continue;
}
if ( ! strcmp ( V_2 , V_32 -> V_2 ) ) {
F_18 ( L_9 ,
V_2 ) ;
return - V_47 ;
}
if ( ( V_32 -> V_40 == V_40 ) &&
( ++ V_45 > 2 ) ) {
if ( V_40 -- == 0 ) {
F_18 ( L_10 ,
V_2 ) ;
return - V_47 ;
}
F_18 ( L_11 ,
V_2 , V_40 + 1 , V_40 ) ;
goto V_53;
}
}
if ( V_35 >= V_33 ) {
F_18 ( L_12 ,
V_2 , V_33 ) ;
return - V_47 ;
}
V_32 = F_22 ( sizeof( * V_32 ) , V_54 ) ;
if ( ! V_32 )
return - V_55 ;
strcpy ( V_32 -> V_2 , V_2 ) ;
V_32 -> V_56 = V_12 ;
V_46 = V_12 -> V_57 ( V_28 , V_32 , V_42 ) ;
if ( V_46 ) {
F_18 ( L_13 ,
V_2 , - V_46 ) ;
return - V_47 ;
}
V_32 -> V_58 = V_35 ;
V_32 -> V_59 = V_12 -> V_59 ;
V_32 -> V_60 = V_12 -> V_60 ;
V_32 -> V_61 = V_39 ;
V_32 -> V_62 = V_35 + 'A' ;
V_32 -> V_40 = V_40 ;
V_46 = F_23 ( V_28 , V_32 , & V_32 -> V_63 ) ;
if ( V_46 ) {
F_24 ( V_28 , V_32 , false ) ;
F_18 ( L_14 ,
V_2 ) ;
return - V_47 ;
}
F_25 ( V_30 -> V_34 [ V_35 ] , V_32 ) ;
F_26 ( L_15 ,
V_2 ,
F_27 ( V_44 , V_39 ) , V_40 ) ;
return V_46 ;
}
static int F_28 ( struct V_28 * V_28 , struct V_27 * V_32 )
{
F_26 ( L_16 , V_32 -> V_2 ) ;
F_29 ( V_28 , V_32 -> V_58 ) ;
F_30 ( V_28 , V_32 ) ;
return 0 ;
}
static void F_24 ( struct V_28 * V_28 , struct V_27 * V_32 ,
bool V_64 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
T_1 V_3 ;
F_26 ( L_17 , V_32 -> V_2 ) ;
V_32 -> V_56 -> V_65 ( V_32 ) ;
F_31 ( V_28 , V_32 -> V_58 , V_64 ) ;
if ( V_32 -> V_38 )
F_32 ( V_32 -> V_38 ) ;
for ( V_3 = 0 ; V_3 < V_33 ; V_3 ++ ) {
if ( V_32 == F_8 ( V_30 -> V_34 [ V_3 ] ) ) {
F_33 ( V_30 -> V_34 [ V_3 ] , NULL ) ;
break;
}
}
F_34 ( V_32 , V_66 ) ;
}
int F_35 ( struct V_28 * V_28 , struct V_27 * V_67 ,
struct V_41 * V_42 [] )
{
struct V_68 * V_69 ;
char * V_70 = strchr ( ( const char * ) V_67 -> V_2 , ':' ) + 1 ;
V_69 = F_36 ( V_28 , V_70 ) ;
if ( ! V_69 )
return - V_71 ;
F_25 ( V_67 -> V_72 , V_69 ) ;
memset ( & V_67 -> V_63 , 0 , sizeof( V_67 -> V_63 ) ) ;
memcpy ( V_67 -> V_63 . V_16 , V_69 -> V_73 , V_67 -> V_56 -> V_74 ) ;
V_67 -> V_63 . V_14 = V_67 -> V_56 -> V_5 ;
V_67 -> V_63 . V_73 = 1 ;
V_67 -> V_75 = V_69 -> V_75 ;
V_67 -> V_56 -> V_76 ( V_67 , & V_67 -> V_77 , ( char * ) V_69 -> V_78 ) ;
F_25 ( V_69 -> V_79 , V_67 ) ;
return 0 ;
}
void F_37 ( struct V_27 * V_67 )
{
struct V_68 * V_69 ;
V_69 = (struct V_68 * ) F_8 ( V_67 -> V_72 ) ;
F_33 ( V_67 -> V_72 , NULL ) ;
F_33 ( V_69 -> V_79 , NULL ) ;
F_38 () ;
F_39 ( V_69 ) ;
}
int F_40 ( struct V_28 * V_28 , struct V_80 * V_6 ,
struct V_27 * V_67 , struct V_8 * V_36 )
{
struct V_80 * V_81 ;
struct V_68 * V_69 ;
int V_82 ;
V_69 = (struct V_68 * ) F_11 ( V_67 -> V_72 ) ;
if ( ! V_69 )
return 0 ;
V_81 = F_41 ( V_6 , V_54 ) ;
if ( ! V_81 )
return 0 ;
V_82 = V_69 -> V_83 - F_42 ( V_6 ) ;
if ( ( V_82 > 0 ) &&
F_43 ( V_81 , F_44 ( V_82 ) , 0 , V_54 ) ) {
F_45 ( V_81 ) ;
return 0 ;
}
F_46 ( V_81 ) ;
V_81 -> V_69 = V_69 ;
V_81 -> V_84 = F_47 ( V_85 ) ;
F_48 ( V_81 , V_69 , V_85 , V_36 -> V_16 ,
V_69 -> V_78 , V_81 -> V_7 ) ;
F_49 ( V_81 ) ;
return 0 ;
}
void F_50 ( struct V_28 * V_28 , T_1 V_35 , struct V_80 * V_6 ,
struct V_8 * V_36 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
struct V_27 * V_32 ;
F_10 () ;
V_32 = F_11 ( V_30 -> V_34 [ V_35 ] ) ;
if ( F_51 ( V_32 ) )
V_32 -> V_56 -> V_86 ( V_28 , V_6 , V_32 , V_36 ) ;
F_14 () ;
}
static int F_52 ( struct V_80 * V_6 , struct V_68 * V_69 ,
struct V_87 * V_88 , struct V_68 * V_89 )
{
struct V_27 * V_32 ;
F_10 () ;
V_32 = F_11 ( V_69 -> V_79 ) ;
if ( F_51 ( V_32 ) ) {
if ( F_51 ( V_6 -> V_90 <= V_91 ) ) {
V_6 -> V_92 = NULL ;
F_53 ( F_54 ( V_69 ) , V_6 , V_32 ) ;
F_14 () ;
return V_93 ;
}
}
F_14 () ;
F_45 ( V_6 ) ;
return V_94 ;
}
static int F_55 ( struct V_95 * V_96 , unsigned long V_97 ,
void * V_98 )
{
struct V_68 * V_69 = F_56 ( V_98 ) ;
struct V_28 * V_28 = F_54 ( V_69 ) ;
struct V_27 * V_32 ;
V_32 = F_8 ( V_69 -> V_79 ) ;
if ( ! V_32 )
return V_99 ;
V_32 -> V_75 = V_69 -> V_75 ;
switch ( V_97 ) {
case V_100 :
if ( F_57 ( V_69 ) )
break;
case V_101 :
case V_102 :
F_28 ( V_28 , V_32 ) ;
break;
case V_103 :
V_32 -> V_56 -> V_76 ( V_32 , & V_32 -> V_77 ,
( char * ) V_69 -> V_78 ) ;
F_28 ( V_28 , V_32 ) ;
break;
case V_104 :
case V_105 :
F_24 ( F_54 ( V_69 ) , V_32 , false ) ;
break;
}
return V_106 ;
}
int F_58 ( void )
{
int V_107 ;
V_107 = F_59 ( & V_108 ) ;
if ( V_107 )
return V_107 ;
F_60 ( & V_109 ) ;
return 0 ;
}
void F_61 ( void )
{
F_62 ( & V_108 ) ;
F_63 ( & V_109 ) ;
}
void F_64 ( struct V_28 * V_28 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
struct V_27 * V_32 ;
T_1 V_3 ;
for ( V_3 = 0 ; V_3 < V_33 ; V_3 ++ ) {
V_32 = F_8 ( V_30 -> V_34 [ V_3 ] ) ;
if ( V_32 ) {
F_24 ( V_28 , V_32 , true ) ;
V_30 -> V_34 [ V_3 ] = NULL ;
}
}
}
static int F_65 ( struct V_110 * V_111 ,
struct V_27 * V_112 , int V_113 )
{
void * V_114 ;
struct V_41 * V_115 ;
struct V_41 * V_116 ;
V_114 = F_66 ( V_111 -> V_117 , V_111 -> V_118 , V_111 -> V_119 , & V_120 ,
V_113 , V_121 ) ;
if ( ! V_114 )
return - V_122 ;
V_115 = F_67 ( V_111 -> V_117 , V_123 ) ;
if ( ! V_115 )
goto V_124;
if ( F_68 ( V_111 -> V_117 , V_125 , V_112 -> V_2 ) )
goto V_126;
V_116 = F_67 ( V_111 -> V_117 , V_127 ) ;
if ( ! V_116 )
goto V_128;
if ( F_69 ( V_111 -> V_117 , V_129 , V_112 -> V_40 ) )
goto V_128;
if ( F_69 ( V_111 -> V_117 , V_130 , V_112 -> V_59 ) )
goto V_128;
if ( F_69 ( V_111 -> V_117 , V_131 , V_112 -> V_60 ) )
goto V_128;
F_70 ( V_111 -> V_117 , V_116 ) ;
F_70 ( V_111 -> V_117 , V_115 ) ;
F_71 ( V_111 -> V_117 , V_114 ) ;
return 0 ;
V_128:
F_72 ( V_111 -> V_117 , V_116 ) ;
V_126:
F_72 ( V_111 -> V_117 , V_115 ) ;
V_124:
F_73 ( V_111 -> V_117 , V_114 ) ;
return - V_122 ;
}
int F_74 ( struct V_80 * V_117 , struct V_132 * V_133 )
{
int V_107 ;
int V_3 = V_133 -> args [ 0 ] ;
struct V_27 * V_112 ;
struct V_110 V_111 ;
struct V_28 * V_28 = F_75 ( V_117 -> V_134 ) ;
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
if ( V_3 == V_33 )
return 0 ;
V_111 . V_117 = V_117 ;
V_111 . V_118 = F_76 ( V_133 -> V_117 ) . V_118 ;
V_111 . V_119 = V_133 -> V_135 -> V_136 ;
F_77 () ;
for ( V_3 = 0 ; V_3 < V_33 ; V_3 ++ ) {
V_112 = F_8 ( V_30 -> V_34 [ V_3 ] ) ;
if ( ! V_112 )
continue;
V_107 = F_65 ( & V_111 , V_112 , V_137 ) ;
if ( V_107 )
break;
}
F_78 () ;
V_133 -> args [ 0 ] = V_3 ;
return V_117 -> V_7 ;
}
int F_79 ( struct V_80 * V_117 , struct V_138 * V_139 )
{
int V_107 ;
char * V_2 ;
struct V_80 * V_140 ;
struct V_27 * V_112 ;
struct V_110 V_111 ;
struct V_41 * V_115 [ V_141 + 1 ] ;
struct V_28 * V_28 = F_80 ( V_139 ) ;
if ( ! V_139 -> V_115 [ V_123 ] )
return - V_47 ;
V_107 = F_81 ( V_115 , V_141 ,
V_139 -> V_115 [ V_123 ] ,
V_142 ) ;
if ( V_107 )
return V_107 ;
if ( ! V_115 [ V_125 ] )
return - V_47 ;
V_2 = F_82 ( V_115 [ V_125 ] ) ;
V_140 = F_83 ( V_143 , V_144 ) ;
if ( ! V_140 )
return - V_55 ;
V_111 . V_117 = V_140 ;
V_111 . V_118 = V_139 -> V_145 ;
V_111 . V_119 = V_139 -> V_146 ;
F_77 () ;
V_112 = F_6 ( V_28 , V_2 ) ;
if ( ! V_112 ) {
V_107 = - V_47 ;
goto V_147;
}
V_107 = F_65 ( & V_111 , V_112 , 0 ) ;
if ( V_107 )
goto V_147;
F_78 () ;
return F_84 ( V_140 , V_139 ) ;
V_147:
F_78 () ;
F_85 ( V_140 ) ;
return V_107 ;
}
int F_86 ( struct V_80 * V_117 , struct V_138 * V_139 )
{
int V_107 ;
char * V_2 ;
struct V_27 * V_112 ;
struct V_41 * V_115 [ V_141 + 1 ] ;
struct V_28 * V_28 = F_75 ( V_117 -> V_134 ) ;
if ( ! V_139 -> V_115 [ V_123 ] )
return - V_47 ;
V_107 = F_81 ( V_115 , V_141 ,
V_139 -> V_115 [ V_123 ] ,
V_142 ) ;
if ( V_107 )
return V_107 ;
if ( ! V_115 [ V_125 ] )
return - V_47 ;
V_2 = F_82 ( V_115 [ V_125 ] ) ;
F_77 () ;
V_112 = F_6 ( V_28 , V_2 ) ;
if ( ! V_112 ) {
F_78 () ;
return - V_47 ;
}
F_24 ( V_28 , V_112 , false ) ;
F_78 () ;
return 0 ;
}
int F_87 ( struct V_80 * V_117 , struct V_138 * V_139 )
{
int V_107 ;
char * V_112 ;
struct V_41 * V_115 [ V_141 + 1 ] ;
struct V_28 * V_28 = F_75 ( V_117 -> V_134 ) ;
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
T_1 V_61 ;
T_1 V_148 ;
V_148 = V_52 ;
V_61 = V_30 -> V_48 & V_50 ;
if ( ! V_139 -> V_115 [ V_123 ] )
return - V_47 ;
V_107 = F_81 ( V_115 , V_141 ,
V_139 -> V_115 [ V_123 ] ,
V_142 ) ;
if ( V_107 )
return V_107 ;
if ( ! V_115 [ V_125 ] )
return - V_47 ;
V_112 = F_82 ( V_115 [ V_125 ] ) ;
if ( V_115 [ V_149 ] )
V_61 = F_88 ( V_115 [ V_149 ] ) ;
if ( V_115 [ V_127 ] ) {
struct V_41 * V_150 [ V_151 + 1 ] ;
V_107 = F_89 ( V_115 [ V_127 ] ,
V_150 ) ;
if ( V_107 )
return V_107 ;
if ( V_150 [ V_129 ] )
V_148 = F_88 ( V_150 [ V_129 ] ) ;
}
F_77 () ;
V_107 = F_17 ( V_28 , V_112 , V_61 , V_148 , V_115 ) ;
if ( V_107 ) {
F_78 () ;
return V_107 ;
}
F_78 () ;
return 0 ;
}
int F_90 ( struct V_80 * V_117 , struct V_138 * V_139 )
{
int V_107 ;
char * V_2 ;
struct V_27 * V_67 ;
struct V_41 * V_115 [ V_141 + 1 ] ;
struct V_28 * V_28 = F_80 ( V_139 ) ;
if ( ! V_139 -> V_115 [ V_123 ] )
return - V_47 ;
V_107 = F_81 ( V_115 , V_141 ,
V_139 -> V_115 [ V_123 ] ,
V_142 ) ;
if ( V_107 )
return V_107 ;
if ( ! V_115 [ V_125 ] )
return - V_47 ;
V_2 = F_82 ( V_115 [ V_125 ] ) ;
F_77 () ;
V_67 = F_6 ( V_28 , V_2 ) ;
if ( ! V_67 ) {
F_78 () ;
return - V_47 ;
}
if ( V_115 [ V_127 ] ) {
struct V_41 * V_150 [ V_151 + 1 ] ;
V_107 = F_89 ( V_115 [ V_127 ] ,
V_150 ) ;
if ( V_107 ) {
F_78 () ;
return V_107 ;
}
if ( V_150 [ V_130 ] )
V_67 -> V_59 = F_88 ( V_150 [ V_130 ] ) ;
if ( V_150 [ V_129 ] )
V_67 -> V_40 = F_88 ( V_150 [ V_129 ] ) ;
if ( V_150 [ V_131 ] )
V_67 -> V_60 = F_88 ( V_150 [ V_131 ] ) ;
}
F_78 () ;
return 0 ;
}
static int F_91 ( struct V_110 * V_111 ,
struct V_1 * V_56 , int V_113 )
{
void * V_114 ;
struct V_41 * V_115 ;
struct V_41 * V_116 ;
V_114 = F_66 ( V_111 -> V_117 , V_111 -> V_118 , V_111 -> V_119 , & V_120 ,
V_113 , V_152 ) ;
if ( ! V_114 )
return - V_122 ;
V_115 = F_67 ( V_111 -> V_117 , V_153 ) ;
if ( ! V_115 )
goto V_124;
if ( F_68 ( V_111 -> V_117 , V_154 , V_56 -> V_2 ) )
goto V_126;
V_116 = F_67 ( V_111 -> V_117 , V_155 ) ;
if ( ! V_116 )
goto V_128;
if ( F_69 ( V_111 -> V_117 , V_129 , V_56 -> V_40 ) )
goto V_128;
if ( F_69 ( V_111 -> V_117 , V_130 , V_56 -> V_59 ) )
goto V_128;
if ( F_69 ( V_111 -> V_117 , V_131 , V_56 -> V_60 ) )
goto V_128;
F_70 ( V_111 -> V_117 , V_116 ) ;
F_70 ( V_111 -> V_117 , V_115 ) ;
F_71 ( V_111 -> V_117 , V_114 ) ;
return 0 ;
V_128:
F_72 ( V_111 -> V_117 , V_116 ) ;
V_126:
F_72 ( V_111 -> V_117 , V_115 ) ;
V_124:
F_73 ( V_111 -> V_117 , V_114 ) ;
return - V_122 ;
}
int F_92 ( struct V_80 * V_117 , struct V_132 * V_133 )
{
int V_107 ;
int V_3 = V_133 -> args [ 0 ] ;
struct V_110 V_111 ;
if ( V_3 == V_156 )
return 0 ;
V_111 . V_117 = V_117 ;
V_111 . V_118 = F_76 ( V_133 -> V_117 ) . V_118 ;
V_111 . V_119 = V_133 -> V_135 -> V_136 ;
F_77 () ;
for (; V_4 [ V_3 ] != NULL ; V_3 ++ ) {
V_107 = F_91 ( & V_111 , V_4 [ V_3 ] ,
V_137 ) ;
if ( V_107 )
break;
}
F_78 () ;
V_133 -> args [ 0 ] = V_3 ;
return V_117 -> V_7 ;
}
int F_93 ( struct V_80 * V_117 , struct V_138 * V_139 )
{
int V_107 ;
char * V_2 ;
struct V_110 V_111 ;
struct V_1 * V_56 ;
struct V_80 * V_140 ;
struct V_41 * V_115 [ V_141 + 1 ] ;
if ( ! V_139 -> V_115 [ V_153 ] )
return - V_47 ;
V_107 = F_81 ( V_115 , V_157 ,
V_139 -> V_115 [ V_153 ] ,
V_158 ) ;
if ( V_107 )
return V_107 ;
if ( ! V_115 [ V_154 ] )
return - V_47 ;
V_2 = F_82 ( V_115 [ V_154 ] ) ;
V_140 = F_83 ( V_143 , V_144 ) ;
if ( ! V_140 )
return - V_55 ;
V_111 . V_117 = V_140 ;
V_111 . V_118 = V_139 -> V_145 ;
V_111 . V_119 = V_139 -> V_146 ;
F_77 () ;
V_56 = F_1 ( V_2 ) ;
if ( ! V_56 ) {
V_107 = - V_47 ;
goto V_147;
}
V_107 = F_91 ( & V_111 , V_56 , 0 ) ;
if ( V_107 )
goto V_147;
F_78 () ;
return F_84 ( V_140 , V_139 ) ;
V_147:
F_78 () ;
F_85 ( V_140 ) ;
return V_107 ;
}
int F_94 ( struct V_80 * V_117 , struct V_138 * V_139 )
{
int V_107 ;
char * V_2 ;
struct V_1 * V_159 ;
struct V_41 * V_115 [ V_141 + 1 ] ;
if ( ! V_139 -> V_115 [ V_153 ] )
return - V_47 ;
V_107 = F_81 ( V_115 , V_157 ,
V_139 -> V_115 [ V_153 ] ,
V_158 ) ;
if ( ! V_115 [ V_154 ] )
return - V_47 ;
V_2 = F_82 ( V_115 [ V_154 ] ) ;
F_77 () ;
V_159 = F_1 ( V_2 ) ;
if ( ! V_159 ) {
F_78 () ;
return - V_47 ;
}
if ( V_115 [ V_155 ] ) {
struct V_41 * V_150 [ V_151 + 1 ] ;
V_107 = F_89 ( V_115 [ V_155 ] ,
V_150 ) ;
if ( V_107 ) {
F_78 () ;
return V_107 ;
}
if ( V_150 [ V_130 ] )
V_159 -> V_59 = F_88 ( V_150 [ V_130 ] ) ;
if ( V_150 [ V_129 ] )
V_159 -> V_40 = F_88 ( V_150 [ V_129 ] ) ;
if ( V_150 [ V_131 ] )
V_159 -> V_60 = F_88 ( V_150 [ V_131 ] ) ;
}
F_78 () ;
return 0 ;
}
