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
T_1 V_39 , T_1 V_40 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
struct V_27 * V_32 ;
struct V_1 * V_12 ;
struct V_17 V_41 ;
char V_42 [ 16 ] ;
T_1 V_35 ;
T_1 V_43 ;
T_1 V_3 ;
int V_44 = - V_45 ;
if ( ! V_30 -> V_46 ) {
F_18 ( L_4 ,
V_2 ) ;
return - V_47 ;
}
if ( ! F_5 ( V_2 , & V_41 ) ) {
F_18 ( L_5 , V_2 ) ;
return - V_45 ;
}
if ( F_19 ( V_39 ) &&
( V_39 != V_30 -> V_46 ) ) {
if ( F_20 ( V_39 , V_30 -> V_46 ) ) {
V_39 = V_30 -> V_46 & V_48 ;
V_44 = 0 ;
} else if ( F_21 ( V_28 , V_39 ) )
V_44 = 0 ;
}
if ( V_44 ) {
F_18 ( L_6 ,
V_2 ) ;
return - V_45 ;
}
if ( ( V_40 > V_49 ) &&
( V_40 != V_50 ) ) {
F_18 ( L_7 , V_2 ) ;
return - V_45 ;
}
V_12 = F_1 ( V_41 . V_21 ) ;
if ( ! V_12 ) {
F_18 ( L_8 ,
V_2 , V_41 . V_21 ) ;
return - V_45 ;
}
if ( V_40 == V_50 )
V_40 = V_12 -> V_40 ;
V_51:
V_35 = V_33 ;
V_43 = 1 ;
for ( V_3 = V_33 ; V_3 -- != 0 ; ) {
V_32 = F_8 ( V_30 -> V_34 [ V_3 ] ) ;
if ( ! V_32 ) {
V_35 = V_3 ;
continue;
}
if ( ! strcmp ( V_2 , V_32 -> V_2 ) ) {
F_18 ( L_9 ,
V_2 ) ;
return - V_45 ;
}
if ( ( V_32 -> V_40 == V_40 ) &&
( ++ V_43 > 2 ) ) {
if ( V_40 -- == 0 ) {
F_18 ( L_10 ,
V_2 ) ;
return - V_45 ;
}
F_18 ( L_11 ,
V_2 , V_40 + 1 , V_40 ) ;
goto V_51;
}
}
if ( V_35 >= V_33 ) {
F_18 ( L_12 ,
V_2 , V_33 ) ;
return - V_45 ;
}
V_32 = F_22 ( sizeof( * V_32 ) , V_52 ) ;
if ( ! V_32 )
return - V_53 ;
strcpy ( V_32 -> V_2 , V_2 ) ;
V_32 -> V_54 = V_12 ;
V_44 = V_12 -> V_55 ( V_28 , V_32 ) ;
if ( V_44 ) {
F_18 ( L_13 ,
V_2 , - V_44 ) ;
return - V_45 ;
}
V_32 -> V_56 = V_35 ;
V_32 -> V_57 = V_12 -> V_57 ;
V_32 -> V_58 = V_12 -> V_58 ;
V_32 -> V_59 = V_39 ;
V_32 -> V_60 = V_35 + 'A' ;
V_32 -> V_40 = V_40 ;
V_44 = F_23 ( V_28 , V_32 , & V_32 -> V_61 ) ;
if ( V_44 ) {
F_24 ( V_28 , V_32 , false ) ;
F_18 ( L_14 ,
V_2 ) ;
return - V_45 ;
}
F_25 ( V_30 -> V_34 [ V_35 ] , V_32 ) ;
F_26 ( L_15 ,
V_2 ,
F_27 ( V_42 , V_39 ) , V_40 ) ;
return V_44 ;
}
static int F_28 ( struct V_28 * V_28 , struct V_27 * V_32 )
{
F_26 ( L_16 , V_32 -> V_2 ) ;
F_29 ( V_28 , V_32 -> V_56 ) ;
F_30 ( V_28 , V_32 ) ;
return 0 ;
}
static void F_24 ( struct V_28 * V_28 , struct V_27 * V_32 ,
bool V_62 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
T_1 V_3 ;
F_26 ( L_17 , V_32 -> V_2 ) ;
V_32 -> V_54 -> V_63 ( V_32 ) ;
F_31 ( V_28 , V_32 -> V_56 , V_62 ) ;
if ( V_32 -> V_38 )
F_32 ( V_32 -> V_38 ) ;
for ( V_3 = 0 ; V_3 < V_33 ; V_3 ++ ) {
if ( V_32 == F_8 ( V_30 -> V_34 [ V_3 ] ) ) {
F_33 ( V_30 -> V_34 [ V_3 ] , NULL ) ;
break;
}
}
F_34 ( V_32 , V_64 ) ;
}
int F_35 ( struct V_28 * V_28 , struct V_27 * V_65 )
{
struct V_66 * V_67 ;
char * V_68 = strchr ( ( const char * ) V_65 -> V_2 , ':' ) + 1 ;
V_67 = F_36 ( V_28 , V_68 ) ;
if ( ! V_67 )
return - V_69 ;
F_25 ( V_65 -> V_70 , V_67 ) ;
memset ( & V_65 -> V_61 , 0 , sizeof( V_65 -> V_61 ) ) ;
memcpy ( V_65 -> V_61 . V_16 , V_67 -> V_71 , V_65 -> V_54 -> V_72 ) ;
V_65 -> V_61 . V_14 = V_65 -> V_54 -> V_5 ;
V_65 -> V_61 . V_71 = 1 ;
V_65 -> V_73 = V_67 -> V_73 ;
V_65 -> V_54 -> V_74 ( V_65 , & V_65 -> V_75 , ( char * ) V_67 -> V_76 ) ;
F_25 ( V_67 -> V_77 , V_65 ) ;
return 0 ;
}
void F_37 ( struct V_27 * V_65 )
{
struct V_66 * V_67 ;
V_67 = (struct V_66 * ) F_8 ( V_65 -> V_70 ) ;
F_33 ( V_65 -> V_70 , NULL ) ;
F_33 ( V_67 -> V_77 , NULL ) ;
F_38 () ;
F_39 ( V_67 ) ;
}
int F_40 ( struct V_28 * V_28 , struct V_78 * V_6 ,
struct V_27 * V_65 , struct V_8 * V_36 )
{
struct V_78 * V_79 ;
struct V_66 * V_67 ;
int V_80 ;
V_67 = (struct V_66 * ) F_11 ( V_65 -> V_70 ) ;
if ( ! V_67 )
return 0 ;
V_79 = F_41 ( V_6 , V_52 ) ;
if ( ! V_79 )
return 0 ;
V_80 = V_67 -> V_81 - F_42 ( V_6 ) ;
if ( ( V_80 > 0 ) &&
F_43 ( V_79 , F_44 ( V_80 ) , 0 , V_52 ) ) {
F_45 ( V_79 ) ;
return 0 ;
}
F_46 ( V_79 ) ;
V_79 -> V_67 = V_67 ;
V_79 -> V_82 = F_47 ( V_83 ) ;
F_48 ( V_79 , V_67 , V_83 , V_36 -> V_16 ,
V_67 -> V_76 , V_79 -> V_7 ) ;
F_49 ( V_79 ) ;
return 0 ;
}
void F_50 ( struct V_28 * V_28 , T_1 V_35 , struct V_78 * V_6 ,
struct V_8 * V_36 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
struct V_27 * V_32 ;
F_10 () ;
V_32 = F_11 ( V_30 -> V_34 [ V_35 ] ) ;
if ( F_51 ( V_32 ) )
V_32 -> V_54 -> V_84 ( V_28 , V_6 , V_32 , V_36 ) ;
F_14 () ;
}
static int F_52 ( struct V_78 * V_6 , struct V_66 * V_67 ,
struct V_85 * V_86 , struct V_66 * V_87 )
{
struct V_27 * V_32 ;
F_10 () ;
V_32 = F_11 ( V_67 -> V_77 ) ;
if ( F_51 ( V_32 ) ) {
if ( F_51 ( V_6 -> V_88 <= V_89 ) ) {
V_6 -> V_90 = NULL ;
F_53 ( F_54 ( V_67 ) , V_6 , V_32 ) ;
F_14 () ;
return V_91 ;
}
}
F_14 () ;
F_45 ( V_6 ) ;
return V_92 ;
}
static int F_55 ( struct V_93 * V_94 , unsigned long V_95 ,
void * V_96 )
{
struct V_66 * V_67 = F_56 ( V_96 ) ;
struct V_28 * V_28 = F_54 ( V_67 ) ;
struct V_27 * V_32 ;
V_32 = F_8 ( V_67 -> V_77 ) ;
if ( ! V_32 )
return V_97 ;
V_32 -> V_73 = V_67 -> V_73 ;
switch ( V_95 ) {
case V_98 :
if ( F_57 ( V_67 ) )
break;
case V_99 :
case V_100 :
F_28 ( V_28 , V_32 ) ;
break;
case V_101 :
V_32 -> V_54 -> V_74 ( V_32 , & V_32 -> V_75 ,
( char * ) V_67 -> V_76 ) ;
F_28 ( V_28 , V_32 ) ;
break;
case V_102 :
case V_103 :
F_24 ( F_54 ( V_67 ) , V_32 , false ) ;
break;
}
return V_104 ;
}
int F_58 ( void )
{
int V_105 ;
V_105 = F_59 ( & V_106 ) ;
if ( V_105 )
return V_105 ;
F_60 ( & V_107 ) ;
return 0 ;
}
void F_61 ( void )
{
F_62 ( & V_106 ) ;
F_63 ( & V_107 ) ;
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
static int F_65 ( struct V_108 * V_109 ,
struct V_27 * V_110 )
{
void * V_111 ;
struct V_112 * V_113 ;
struct V_112 * V_114 ;
V_111 = F_66 ( V_109 -> V_115 , V_109 -> V_116 , V_109 -> V_117 , & V_118 ,
V_119 , V_120 ) ;
if ( ! V_111 )
return - V_121 ;
V_113 = F_67 ( V_109 -> V_115 , V_122 ) ;
if ( ! V_113 )
goto V_123;
if ( F_68 ( V_109 -> V_115 , V_124 , V_110 -> V_2 ) )
goto V_125;
V_114 = F_67 ( V_109 -> V_115 , V_126 ) ;
if ( ! V_114 )
goto V_127;
if ( F_69 ( V_109 -> V_115 , V_128 , V_110 -> V_40 ) )
goto V_127;
if ( F_69 ( V_109 -> V_115 , V_129 , V_110 -> V_57 ) )
goto V_127;
if ( F_69 ( V_109 -> V_115 , V_130 , V_110 -> V_58 ) )
goto V_127;
F_70 ( V_109 -> V_115 , V_114 ) ;
F_70 ( V_109 -> V_115 , V_113 ) ;
F_71 ( V_109 -> V_115 , V_111 ) ;
return 0 ;
V_127:
F_72 ( V_109 -> V_115 , V_114 ) ;
V_125:
F_72 ( V_109 -> V_115 , V_113 ) ;
V_123:
F_73 ( V_109 -> V_115 , V_111 ) ;
return - V_121 ;
}
int F_74 ( struct V_78 * V_115 , struct V_131 * V_132 )
{
int V_105 ;
int V_3 = V_132 -> args [ 0 ] ;
struct V_27 * V_110 ;
struct V_108 V_109 ;
struct V_28 * V_28 = F_75 ( V_115 -> V_133 ) ;
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
if ( V_3 == V_33 )
return 0 ;
V_109 . V_115 = V_115 ;
V_109 . V_116 = F_76 ( V_132 -> V_115 ) . V_116 ;
V_109 . V_117 = V_132 -> V_134 -> V_135 ;
F_77 () ;
for ( V_3 = 0 ; V_3 < V_33 ; V_3 ++ ) {
V_110 = F_8 ( V_30 -> V_34 [ V_3 ] ) ;
if ( ! V_110 )
continue;
V_105 = F_65 ( & V_109 , V_110 ) ;
if ( V_105 )
break;
}
F_78 () ;
V_132 -> args [ 0 ] = V_3 ;
return V_115 -> V_7 ;
}
int F_79 ( struct V_78 * V_115 , struct V_136 * V_137 )
{
int V_105 ;
char * V_2 ;
struct V_78 * V_138 ;
struct V_27 * V_110 ;
struct V_108 V_109 ;
struct V_112 * V_113 [ V_139 + 1 ] ;
struct V_28 * V_28 = F_80 ( V_137 ) ;
if ( ! V_137 -> V_113 [ V_122 ] )
return - V_45 ;
V_105 = F_81 ( V_113 , V_139 ,
V_137 -> V_113 [ V_122 ] ,
V_140 ) ;
if ( V_105 )
return V_105 ;
if ( ! V_113 [ V_124 ] )
return - V_45 ;
V_2 = F_82 ( V_113 [ V_124 ] ) ;
V_138 = F_83 ( V_141 , V_142 ) ;
if ( ! V_138 )
return - V_53 ;
V_109 . V_115 = V_138 ;
V_109 . V_116 = V_137 -> V_143 ;
V_109 . V_117 = V_137 -> V_144 ;
F_77 () ;
V_110 = F_6 ( V_28 , V_2 ) ;
if ( ! V_110 ) {
V_105 = - V_45 ;
goto V_145;
}
V_105 = F_65 ( & V_109 , V_110 ) ;
if ( V_105 )
goto V_145;
F_78 () ;
return F_84 ( V_138 , V_137 ) ;
V_145:
F_78 () ;
F_85 ( V_138 ) ;
return V_105 ;
}
int F_86 ( struct V_78 * V_115 , struct V_136 * V_137 )
{
int V_105 ;
char * V_2 ;
struct V_27 * V_110 ;
struct V_112 * V_113 [ V_139 + 1 ] ;
struct V_28 * V_28 = F_75 ( V_115 -> V_133 ) ;
if ( ! V_137 -> V_113 [ V_122 ] )
return - V_45 ;
V_105 = F_81 ( V_113 , V_139 ,
V_137 -> V_113 [ V_122 ] ,
V_140 ) ;
if ( V_105 )
return V_105 ;
if ( ! V_113 [ V_124 ] )
return - V_45 ;
V_2 = F_82 ( V_113 [ V_124 ] ) ;
F_77 () ;
V_110 = F_6 ( V_28 , V_2 ) ;
if ( ! V_110 ) {
F_78 () ;
return - V_45 ;
}
F_24 ( V_28 , V_110 , false ) ;
F_78 () ;
return 0 ;
}
int F_87 ( struct V_78 * V_115 , struct V_136 * V_137 )
{
int V_105 ;
char * V_110 ;
struct V_112 * V_113 [ V_139 + 1 ] ;
struct V_28 * V_28 = F_75 ( V_115 -> V_133 ) ;
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
T_1 V_59 ;
T_1 V_146 ;
V_146 = V_50 ;
V_59 = V_30 -> V_46 & V_48 ;
if ( ! V_137 -> V_113 [ V_122 ] )
return - V_45 ;
V_105 = F_81 ( V_113 , V_139 ,
V_137 -> V_113 [ V_122 ] ,
V_140 ) ;
if ( V_105 )
return V_105 ;
if ( ! V_113 [ V_124 ] )
return - V_45 ;
V_110 = F_82 ( V_113 [ V_124 ] ) ;
if ( V_113 [ V_147 ] )
V_59 = F_88 ( V_113 [ V_147 ] ) ;
if ( V_113 [ V_126 ] ) {
struct V_112 * V_148 [ V_149 + 1 ] ;
V_105 = F_89 ( V_113 [ V_126 ] ,
V_148 ) ;
if ( V_105 )
return V_105 ;
if ( V_148 [ V_128 ] )
V_146 = F_88 ( V_148 [ V_128 ] ) ;
}
F_77 () ;
V_105 = F_17 ( V_28 , V_110 , V_59 , V_146 ) ;
if ( V_105 ) {
F_78 () ;
return V_105 ;
}
F_78 () ;
return 0 ;
}
int F_90 ( struct V_78 * V_115 , struct V_136 * V_137 )
{
int V_105 ;
char * V_2 ;
struct V_27 * V_65 ;
struct V_112 * V_113 [ V_139 + 1 ] ;
struct V_28 * V_28 = F_80 ( V_137 ) ;
if ( ! V_137 -> V_113 [ V_122 ] )
return - V_45 ;
V_105 = F_81 ( V_113 , V_139 ,
V_137 -> V_113 [ V_122 ] ,
V_140 ) ;
if ( V_105 )
return V_105 ;
if ( ! V_113 [ V_124 ] )
return - V_45 ;
V_2 = F_82 ( V_113 [ V_124 ] ) ;
F_77 () ;
V_65 = F_6 ( V_28 , V_2 ) ;
if ( ! V_65 ) {
F_78 () ;
return - V_45 ;
}
if ( V_113 [ V_126 ] ) {
struct V_112 * V_148 [ V_149 + 1 ] ;
V_105 = F_89 ( V_113 [ V_126 ] ,
V_148 ) ;
if ( V_105 ) {
F_78 () ;
return V_105 ;
}
if ( V_148 [ V_129 ] )
V_65 -> V_57 = F_88 ( V_148 [ V_129 ] ) ;
if ( V_148 [ V_128 ] )
V_65 -> V_40 = F_88 ( V_148 [ V_128 ] ) ;
if ( V_148 [ V_130 ] )
V_65 -> V_58 = F_88 ( V_148 [ V_130 ] ) ;
}
F_78 () ;
return 0 ;
}
static int F_91 ( struct V_108 * V_109 ,
struct V_1 * V_54 )
{
void * V_111 ;
struct V_112 * V_113 ;
struct V_112 * V_114 ;
V_111 = F_66 ( V_109 -> V_115 , V_109 -> V_116 , V_109 -> V_117 , & V_118 ,
V_119 , V_150 ) ;
if ( ! V_111 )
return - V_121 ;
V_113 = F_67 ( V_109 -> V_115 , V_151 ) ;
if ( ! V_113 )
goto V_123;
if ( F_68 ( V_109 -> V_115 , V_152 , V_54 -> V_2 ) )
goto V_125;
V_114 = F_67 ( V_109 -> V_115 , V_153 ) ;
if ( ! V_114 )
goto V_127;
if ( F_69 ( V_109 -> V_115 , V_128 , V_54 -> V_40 ) )
goto V_127;
if ( F_69 ( V_109 -> V_115 , V_129 , V_54 -> V_57 ) )
goto V_127;
if ( F_69 ( V_109 -> V_115 , V_130 , V_54 -> V_58 ) )
goto V_127;
F_70 ( V_109 -> V_115 , V_114 ) ;
F_70 ( V_109 -> V_115 , V_113 ) ;
F_71 ( V_109 -> V_115 , V_111 ) ;
return 0 ;
V_127:
F_72 ( V_109 -> V_115 , V_114 ) ;
V_125:
F_72 ( V_109 -> V_115 , V_113 ) ;
V_123:
F_73 ( V_109 -> V_115 , V_111 ) ;
return - V_121 ;
}
int F_92 ( struct V_78 * V_115 , struct V_131 * V_132 )
{
int V_105 ;
int V_3 = V_132 -> args [ 0 ] ;
struct V_108 V_109 ;
if ( V_3 == V_154 )
return 0 ;
V_109 . V_115 = V_115 ;
V_109 . V_116 = F_76 ( V_132 -> V_115 ) . V_116 ;
V_109 . V_117 = V_132 -> V_134 -> V_135 ;
F_77 () ;
for (; V_4 [ V_3 ] != NULL ; V_3 ++ ) {
V_105 = F_91 ( & V_109 , V_4 [ V_3 ] ) ;
if ( V_105 )
break;
}
F_78 () ;
V_132 -> args [ 0 ] = V_3 ;
return V_115 -> V_7 ;
}
int F_93 ( struct V_78 * V_115 , struct V_136 * V_137 )
{
int V_105 ;
char * V_2 ;
struct V_108 V_109 ;
struct V_1 * V_54 ;
struct V_78 * V_138 ;
struct V_112 * V_113 [ V_139 + 1 ] ;
if ( ! V_137 -> V_113 [ V_151 ] )
return - V_45 ;
V_105 = F_81 ( V_113 , V_155 ,
V_137 -> V_113 [ V_151 ] ,
V_156 ) ;
if ( V_105 )
return V_105 ;
if ( ! V_113 [ V_152 ] )
return - V_45 ;
V_2 = F_82 ( V_113 [ V_152 ] ) ;
V_138 = F_83 ( V_141 , V_142 ) ;
if ( ! V_138 )
return - V_53 ;
V_109 . V_115 = V_138 ;
V_109 . V_116 = V_137 -> V_143 ;
V_109 . V_117 = V_137 -> V_144 ;
F_77 () ;
V_54 = F_1 ( V_2 ) ;
if ( ! V_54 ) {
V_105 = - V_45 ;
goto V_145;
}
V_105 = F_91 ( & V_109 , V_54 ) ;
if ( V_105 )
goto V_145;
F_78 () ;
return F_84 ( V_138 , V_137 ) ;
V_145:
F_78 () ;
F_85 ( V_138 ) ;
return V_105 ;
}
int F_94 ( struct V_78 * V_115 , struct V_136 * V_137 )
{
int V_105 ;
char * V_2 ;
struct V_1 * V_157 ;
struct V_112 * V_113 [ V_139 + 1 ] ;
if ( ! V_137 -> V_113 [ V_151 ] )
return - V_45 ;
V_105 = F_81 ( V_113 , V_155 ,
V_137 -> V_113 [ V_151 ] ,
V_156 ) ;
if ( ! V_113 [ V_152 ] )
return - V_45 ;
V_2 = F_82 ( V_113 [ V_152 ] ) ;
F_77 () ;
V_157 = F_1 ( V_2 ) ;
if ( ! V_157 ) {
F_78 () ;
return - V_45 ;
}
if ( V_113 [ V_153 ] ) {
struct V_112 * V_148 [ V_149 + 1 ] ;
V_105 = F_89 ( V_113 [ V_153 ] ,
V_148 ) ;
if ( V_105 ) {
F_78 () ;
return V_105 ;
}
if ( V_148 [ V_129 ] )
V_157 -> V_57 = F_88 ( V_148 [ V_129 ] ) ;
if ( V_148 [ V_128 ] )
V_157 -> V_40 = F_88 ( V_148 [ V_128 ] ) ;
if ( V_148 [ V_130 ] )
V_157 -> V_58 = F_88 ( V_148 [ V_130 ] ) ;
}
F_78 () ;
return 0 ;
}
