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
F_24 ( V_28 , V_32 ) ;
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
static void F_24 ( struct V_28 * V_28 , struct V_27 * V_32 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
T_1 V_3 ;
F_26 ( L_17 , V_32 -> V_2 ) ;
V_32 -> V_56 -> V_64 ( V_32 ) ;
F_29 ( V_28 , V_32 -> V_58 ) ;
if ( V_32 -> V_38 )
F_31 ( V_32 -> V_38 ) ;
for ( V_3 = 0 ; V_3 < V_33 ; V_3 ++ ) {
if ( V_32 == F_8 ( V_30 -> V_34 [ V_3 ] ) ) {
F_32 ( V_30 -> V_34 [ V_3 ] , NULL ) ;
break;
}
}
F_33 ( V_32 , V_65 ) ;
}
int F_34 ( struct V_28 * V_28 , struct V_27 * V_66 ,
struct V_41 * V_42 [] )
{
struct V_67 * V_68 ;
char * V_69 = strchr ( ( const char * ) V_66 -> V_2 , ':' ) + 1 ;
V_68 = F_35 ( V_28 , V_69 ) ;
if ( ! V_68 )
return - V_70 ;
F_25 ( V_66 -> V_71 , V_68 ) ;
memset ( & V_66 -> V_63 , 0 , sizeof( V_66 -> V_63 ) ) ;
memcpy ( V_66 -> V_63 . V_16 , V_68 -> V_72 , V_66 -> V_56 -> V_73 ) ;
V_66 -> V_63 . V_14 = V_66 -> V_56 -> V_5 ;
V_66 -> V_63 . V_72 = 1 ;
V_66 -> V_74 = V_68 -> V_74 ;
V_66 -> V_56 -> V_75 ( V_66 , & V_66 -> V_76 , ( char * ) V_68 -> V_77 ) ;
F_25 ( V_68 -> V_78 , V_66 ) ;
return 0 ;
}
void F_36 ( struct V_27 * V_66 )
{
struct V_67 * V_68 ;
V_68 = (struct V_67 * ) F_8 ( V_66 -> V_71 ) ;
F_32 ( V_66 -> V_71 , NULL ) ;
F_32 ( V_68 -> V_78 , NULL ) ;
F_37 () ;
F_38 ( V_68 ) ;
}
int F_39 ( struct V_28 * V_28 , struct V_79 * V_6 ,
struct V_27 * V_66 , struct V_8 * V_36 )
{
struct V_79 * V_80 ;
struct V_67 * V_68 ;
int V_81 ;
V_68 = (struct V_67 * ) F_11 ( V_66 -> V_71 ) ;
if ( ! V_68 )
return 0 ;
V_80 = F_40 ( V_6 , V_54 ) ;
if ( ! V_80 )
return 0 ;
V_81 = V_68 -> V_82 - F_41 ( V_6 ) ;
if ( ( V_81 > 0 ) &&
F_42 ( V_80 , F_43 ( V_81 ) , 0 , V_54 ) ) {
F_44 ( V_80 ) ;
return 0 ;
}
F_45 ( V_80 ) ;
V_80 -> V_68 = V_68 ;
V_80 -> V_83 = F_46 ( V_84 ) ;
F_47 ( V_80 , V_68 , V_84 , V_36 -> V_16 ,
V_68 -> V_77 , V_80 -> V_7 ) ;
F_48 ( V_80 ) ;
return 0 ;
}
void F_49 ( struct V_28 * V_28 , T_1 V_35 , struct V_79 * V_6 ,
struct V_8 * V_36 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
struct V_27 * V_32 ;
F_10 () ;
V_32 = F_11 ( V_30 -> V_34 [ V_35 ] ) ;
if ( F_50 ( V_32 ) )
V_32 -> V_56 -> V_85 ( V_28 , V_6 , V_32 , V_36 ) ;
F_14 () ;
}
void F_51 ( struct V_28 * V_28 , T_1 V_35 ,
struct V_86 * V_87 ,
struct V_8 * V_88 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
struct V_27 * V_66 ;
struct V_79 * V_89 , * V_90 ;
if ( F_52 ( V_87 ) )
return;
F_10 () ;
V_66 = F_11 ( V_30 -> V_34 [ V_35 ] ) ;
if ( F_50 ( V_66 ) ) {
F_53 (xmitq, skb, tmp) {
F_54 ( V_87 ) ;
V_66 -> V_56 -> V_85 ( V_28 , V_89 , V_66 , V_88 ) ;
F_44 ( V_89 ) ;
}
}
F_14 () ;
}
static int F_55 ( struct V_79 * V_6 , struct V_67 * V_68 ,
struct V_91 * V_92 , struct V_67 * V_93 )
{
struct V_27 * V_32 ;
F_10 () ;
V_32 = F_11 ( V_68 -> V_78 ) ;
if ( F_50 ( V_32 ) ) {
if ( F_50 ( V_6 -> V_94 <= V_95 ) ) {
V_6 -> V_96 = NULL ;
F_56 ( F_57 ( V_68 ) , V_6 , V_32 ) ;
F_14 () ;
return V_97 ;
}
}
F_14 () ;
F_44 ( V_6 ) ;
return V_98 ;
}
static int F_58 ( struct V_99 * V_100 , unsigned long V_101 ,
void * V_102 )
{
struct V_67 * V_68 = F_59 ( V_102 ) ;
struct V_28 * V_28 = F_57 ( V_68 ) ;
struct V_27 * V_32 ;
V_32 = F_8 ( V_68 -> V_78 ) ;
if ( ! V_32 )
return V_103 ;
V_32 -> V_74 = V_68 -> V_74 ;
switch ( V_101 ) {
case V_104 :
if ( F_60 ( V_68 ) )
break;
case V_105 :
case V_106 :
F_28 ( V_28 , V_32 ) ;
break;
case V_107 :
V_32 -> V_56 -> V_75 ( V_32 , & V_32 -> V_76 ,
( char * ) V_68 -> V_77 ) ;
F_28 ( V_28 , V_32 ) ;
break;
case V_108 :
case V_109 :
F_24 ( F_57 ( V_68 ) , V_32 ) ;
break;
}
return V_110 ;
}
int F_61 ( void )
{
int V_111 ;
V_111 = F_62 ( & V_112 ) ;
if ( V_111 )
return V_111 ;
F_63 ( & V_113 ) ;
return 0 ;
}
void F_64 ( void )
{
F_65 ( & V_112 ) ;
F_66 ( & V_113 ) ;
}
void F_67 ( struct V_28 * V_28 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
struct V_27 * V_32 ;
T_1 V_3 ;
for ( V_3 = 0 ; V_3 < V_33 ; V_3 ++ ) {
V_32 = F_8 ( V_30 -> V_34 [ V_3 ] ) ;
if ( V_32 ) {
F_24 ( V_28 , V_32 ) ;
V_30 -> V_34 [ V_3 ] = NULL ;
}
}
}
static int F_68 ( struct V_114 * V_115 ,
struct V_27 * V_116 , int V_117 )
{
void * V_118 ;
struct V_41 * V_119 ;
struct V_41 * V_120 ;
V_118 = F_69 ( V_115 -> V_89 , V_115 -> V_121 , V_115 -> V_122 , & V_123 ,
V_117 , V_124 ) ;
if ( ! V_118 )
return - V_125 ;
V_119 = F_70 ( V_115 -> V_89 , V_126 ) ;
if ( ! V_119 )
goto V_127;
if ( F_71 ( V_115 -> V_89 , V_128 , V_116 -> V_2 ) )
goto V_129;
V_120 = F_70 ( V_115 -> V_89 , V_130 ) ;
if ( ! V_120 )
goto V_131;
if ( F_72 ( V_115 -> V_89 , V_132 , V_116 -> V_40 ) )
goto V_131;
if ( F_72 ( V_115 -> V_89 , V_133 , V_116 -> V_59 ) )
goto V_131;
if ( F_72 ( V_115 -> V_89 , V_134 , V_116 -> V_60 ) )
goto V_131;
F_73 ( V_115 -> V_89 , V_120 ) ;
F_73 ( V_115 -> V_89 , V_119 ) ;
F_74 ( V_115 -> V_89 , V_118 ) ;
return 0 ;
V_131:
F_75 ( V_115 -> V_89 , V_120 ) ;
V_129:
F_75 ( V_115 -> V_89 , V_119 ) ;
V_127:
F_76 ( V_115 -> V_89 , V_118 ) ;
return - V_125 ;
}
int F_77 ( struct V_79 * V_89 , struct V_135 * V_136 )
{
int V_111 ;
int V_3 = V_136 -> args [ 0 ] ;
struct V_27 * V_116 ;
struct V_114 V_115 ;
struct V_28 * V_28 = F_78 ( V_89 -> V_137 ) ;
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
if ( V_3 == V_33 )
return 0 ;
V_115 . V_89 = V_89 ;
V_115 . V_121 = F_79 ( V_136 -> V_89 ) . V_121 ;
V_115 . V_122 = V_136 -> V_138 -> V_139 ;
F_80 () ;
for ( V_3 = 0 ; V_3 < V_33 ; V_3 ++ ) {
V_116 = F_8 ( V_30 -> V_34 [ V_3 ] ) ;
if ( ! V_116 )
continue;
V_111 = F_68 ( & V_115 , V_116 , V_140 ) ;
if ( V_111 )
break;
}
F_81 () ;
V_136 -> args [ 0 ] = V_3 ;
return V_89 -> V_7 ;
}
int F_82 ( struct V_79 * V_89 , struct V_141 * V_142 )
{
int V_111 ;
char * V_2 ;
struct V_79 * V_143 ;
struct V_27 * V_116 ;
struct V_114 V_115 ;
struct V_41 * V_119 [ V_144 + 1 ] ;
struct V_28 * V_28 = F_83 ( V_142 ) ;
if ( ! V_142 -> V_119 [ V_126 ] )
return - V_47 ;
V_111 = F_84 ( V_119 , V_144 ,
V_142 -> V_119 [ V_126 ] ,
V_145 ) ;
if ( V_111 )
return V_111 ;
if ( ! V_119 [ V_128 ] )
return - V_47 ;
V_2 = F_85 ( V_119 [ V_128 ] ) ;
V_143 = F_86 ( V_146 , V_147 ) ;
if ( ! V_143 )
return - V_55 ;
V_115 . V_89 = V_143 ;
V_115 . V_121 = V_142 -> V_148 ;
V_115 . V_122 = V_142 -> V_149 ;
F_80 () ;
V_116 = F_6 ( V_28 , V_2 ) ;
if ( ! V_116 ) {
V_111 = - V_47 ;
goto V_150;
}
V_111 = F_68 ( & V_115 , V_116 , 0 ) ;
if ( V_111 )
goto V_150;
F_81 () ;
return F_87 ( V_143 , V_142 ) ;
V_150:
F_81 () ;
F_88 ( V_143 ) ;
return V_111 ;
}
int F_89 ( struct V_79 * V_89 , struct V_141 * V_142 )
{
int V_111 ;
char * V_2 ;
struct V_27 * V_116 ;
struct V_41 * V_119 [ V_144 + 1 ] ;
struct V_28 * V_28 = F_78 ( V_89 -> V_137 ) ;
if ( ! V_142 -> V_119 [ V_126 ] )
return - V_47 ;
V_111 = F_84 ( V_119 , V_144 ,
V_142 -> V_119 [ V_126 ] ,
V_145 ) ;
if ( V_111 )
return V_111 ;
if ( ! V_119 [ V_128 ] )
return - V_47 ;
V_2 = F_85 ( V_119 [ V_128 ] ) ;
F_80 () ;
V_116 = F_6 ( V_28 , V_2 ) ;
if ( ! V_116 ) {
F_81 () ;
return - V_47 ;
}
F_24 ( V_28 , V_116 ) ;
F_81 () ;
return 0 ;
}
int F_90 ( struct V_79 * V_89 , struct V_141 * V_142 )
{
int V_111 ;
char * V_116 ;
struct V_41 * V_119 [ V_144 + 1 ] ;
struct V_28 * V_28 = F_78 ( V_89 -> V_137 ) ;
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
T_1 V_61 ;
T_1 V_151 ;
V_151 = V_52 ;
V_61 = V_30 -> V_48 & V_50 ;
if ( ! V_142 -> V_119 [ V_126 ] )
return - V_47 ;
V_111 = F_84 ( V_119 , V_144 ,
V_142 -> V_119 [ V_126 ] ,
V_145 ) ;
if ( V_111 )
return V_111 ;
if ( ! V_119 [ V_128 ] )
return - V_47 ;
V_116 = F_85 ( V_119 [ V_128 ] ) ;
if ( V_119 [ V_152 ] )
V_61 = F_91 ( V_119 [ V_152 ] ) ;
if ( V_119 [ V_130 ] ) {
struct V_41 * V_153 [ V_154 + 1 ] ;
V_111 = F_92 ( V_119 [ V_130 ] ,
V_153 ) ;
if ( V_111 )
return V_111 ;
if ( V_153 [ V_132 ] )
V_151 = F_91 ( V_153 [ V_132 ] ) ;
}
F_80 () ;
V_111 = F_17 ( V_28 , V_116 , V_61 , V_151 , V_119 ) ;
if ( V_111 ) {
F_81 () ;
return V_111 ;
}
F_81 () ;
return 0 ;
}
int F_93 ( struct V_79 * V_89 , struct V_141 * V_142 )
{
int V_111 ;
char * V_2 ;
struct V_27 * V_66 ;
struct V_41 * V_119 [ V_144 + 1 ] ;
struct V_28 * V_28 = F_78 ( V_89 -> V_137 ) ;
if ( ! V_142 -> V_119 [ V_126 ] )
return - V_47 ;
V_111 = F_84 ( V_119 , V_144 ,
V_142 -> V_119 [ V_126 ] ,
V_145 ) ;
if ( V_111 )
return V_111 ;
if ( ! V_119 [ V_128 ] )
return - V_47 ;
V_2 = F_85 ( V_119 [ V_128 ] ) ;
F_80 () ;
V_66 = F_6 ( V_28 , V_2 ) ;
if ( ! V_66 ) {
F_81 () ;
return - V_47 ;
}
if ( V_119 [ V_130 ] ) {
struct V_41 * V_153 [ V_154 + 1 ] ;
V_111 = F_92 ( V_119 [ V_130 ] ,
V_153 ) ;
if ( V_111 ) {
F_81 () ;
return V_111 ;
}
if ( V_153 [ V_133 ] )
V_66 -> V_59 = F_91 ( V_153 [ V_133 ] ) ;
if ( V_153 [ V_132 ] )
V_66 -> V_40 = F_91 ( V_153 [ V_132 ] ) ;
if ( V_153 [ V_134 ] )
V_66 -> V_60 = F_91 ( V_153 [ V_134 ] ) ;
}
F_81 () ;
return 0 ;
}
static int F_94 ( struct V_114 * V_115 ,
struct V_1 * V_56 , int V_117 )
{
void * V_118 ;
struct V_41 * V_119 ;
struct V_41 * V_120 ;
V_118 = F_69 ( V_115 -> V_89 , V_115 -> V_121 , V_115 -> V_122 , & V_123 ,
V_117 , V_155 ) ;
if ( ! V_118 )
return - V_125 ;
V_119 = F_70 ( V_115 -> V_89 , V_156 ) ;
if ( ! V_119 )
goto V_127;
if ( F_71 ( V_115 -> V_89 , V_157 , V_56 -> V_2 ) )
goto V_129;
V_120 = F_70 ( V_115 -> V_89 , V_158 ) ;
if ( ! V_120 )
goto V_131;
if ( F_72 ( V_115 -> V_89 , V_132 , V_56 -> V_40 ) )
goto V_131;
if ( F_72 ( V_115 -> V_89 , V_133 , V_56 -> V_59 ) )
goto V_131;
if ( F_72 ( V_115 -> V_89 , V_134 , V_56 -> V_60 ) )
goto V_131;
F_73 ( V_115 -> V_89 , V_120 ) ;
F_73 ( V_115 -> V_89 , V_119 ) ;
F_74 ( V_115 -> V_89 , V_118 ) ;
return 0 ;
V_131:
F_75 ( V_115 -> V_89 , V_120 ) ;
V_129:
F_75 ( V_115 -> V_89 , V_119 ) ;
V_127:
F_76 ( V_115 -> V_89 , V_118 ) ;
return - V_125 ;
}
int F_95 ( struct V_79 * V_89 , struct V_135 * V_136 )
{
int V_111 ;
int V_3 = V_136 -> args [ 0 ] ;
struct V_114 V_115 ;
if ( V_3 == V_159 )
return 0 ;
V_115 . V_89 = V_89 ;
V_115 . V_121 = F_79 ( V_136 -> V_89 ) . V_121 ;
V_115 . V_122 = V_136 -> V_138 -> V_139 ;
F_80 () ;
for (; V_4 [ V_3 ] != NULL ; V_3 ++ ) {
V_111 = F_94 ( & V_115 , V_4 [ V_3 ] ,
V_140 ) ;
if ( V_111 )
break;
}
F_81 () ;
V_136 -> args [ 0 ] = V_3 ;
return V_89 -> V_7 ;
}
int F_96 ( struct V_79 * V_89 , struct V_141 * V_142 )
{
int V_111 ;
char * V_2 ;
struct V_114 V_115 ;
struct V_1 * V_56 ;
struct V_79 * V_143 ;
struct V_41 * V_119 [ V_144 + 1 ] ;
if ( ! V_142 -> V_119 [ V_156 ] )
return - V_47 ;
V_111 = F_84 ( V_119 , V_160 ,
V_142 -> V_119 [ V_156 ] ,
V_161 ) ;
if ( V_111 )
return V_111 ;
if ( ! V_119 [ V_157 ] )
return - V_47 ;
V_2 = F_85 ( V_119 [ V_157 ] ) ;
V_143 = F_86 ( V_146 , V_147 ) ;
if ( ! V_143 )
return - V_55 ;
V_115 . V_89 = V_143 ;
V_115 . V_121 = V_142 -> V_148 ;
V_115 . V_122 = V_142 -> V_149 ;
F_80 () ;
V_56 = F_1 ( V_2 ) ;
if ( ! V_56 ) {
V_111 = - V_47 ;
goto V_150;
}
V_111 = F_94 ( & V_115 , V_56 , 0 ) ;
if ( V_111 )
goto V_150;
F_81 () ;
return F_87 ( V_143 , V_142 ) ;
V_150:
F_81 () ;
F_88 ( V_143 ) ;
return V_111 ;
}
int F_97 ( struct V_79 * V_89 , struct V_141 * V_142 )
{
int V_111 ;
char * V_2 ;
struct V_1 * V_162 ;
struct V_41 * V_119 [ V_144 + 1 ] ;
if ( ! V_142 -> V_119 [ V_156 ] )
return - V_47 ;
V_111 = F_84 ( V_119 , V_160 ,
V_142 -> V_119 [ V_156 ] ,
V_161 ) ;
if ( ! V_119 [ V_157 ] )
return - V_47 ;
V_2 = F_85 ( V_119 [ V_157 ] ) ;
F_80 () ;
V_162 = F_1 ( V_2 ) ;
if ( ! V_162 ) {
F_81 () ;
return - V_47 ;
}
if ( V_119 [ V_158 ] ) {
struct V_41 * V_153 [ V_154 + 1 ] ;
V_111 = F_92 ( V_119 [ V_158 ] ,
V_153 ) ;
if ( V_111 ) {
F_81 () ;
return V_111 ;
}
if ( V_153 [ V_133 ] )
V_162 -> V_59 = F_91 ( V_153 [ V_133 ] ) ;
if ( V_153 [ V_132 ] )
V_162 -> V_40 = F_91 ( V_153 [ V_132 ] ) ;
if ( V_153 [ V_134 ] )
V_162 -> V_60 = F_91 ( V_153 [ V_134 ] ) ;
}
F_81 () ;
return 0 ;
}
