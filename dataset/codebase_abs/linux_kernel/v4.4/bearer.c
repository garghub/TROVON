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
if ( V_32 )
F_12 ( V_32 -> V_37 ) ;
F_13 () ;
}
void F_14 ( struct V_28 * V_28 , T_1 V_35 , T_1 V_36 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
struct V_27 * V_32 ;
F_10 () ;
V_32 = F_11 ( V_30 -> V_34 [ V_35 ] ) ;
if ( V_32 )
F_15 ( V_32 -> V_37 ) ;
F_13 () ;
}
static int F_16 ( struct V_28 * V_28 , const char * V_2 ,
T_1 V_38 , T_1 V_39 ,
struct V_40 * V_41 [] )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
struct V_27 * V_32 ;
struct V_1 * V_12 ;
struct V_17 V_42 ;
char V_43 [ 16 ] ;
T_1 V_35 ;
T_1 V_44 ;
T_1 V_3 ;
int V_45 = - V_46 ;
if ( ! V_30 -> V_47 ) {
F_17 ( L_4 ,
V_2 ) ;
return - V_48 ;
}
if ( ! F_5 ( V_2 , & V_42 ) ) {
F_17 ( L_5 , V_2 ) ;
return - V_46 ;
}
if ( F_18 ( V_38 ) &&
( V_38 != V_30 -> V_47 ) ) {
if ( F_19 ( V_38 , V_30 -> V_47 ) ) {
V_38 = V_30 -> V_47 & V_49 ;
V_45 = 0 ;
} else if ( F_20 ( V_28 , V_38 ) )
V_45 = 0 ;
}
if ( V_45 ) {
F_17 ( L_6 ,
V_2 ) ;
return - V_46 ;
}
if ( ( V_39 > V_50 ) &&
( V_39 != V_51 ) ) {
F_17 ( L_7 , V_2 ) ;
return - V_46 ;
}
V_12 = F_1 ( V_42 . V_21 ) ;
if ( ! V_12 ) {
F_17 ( L_8 ,
V_2 , V_42 . V_21 ) ;
return - V_46 ;
}
if ( V_39 == V_51 )
V_39 = V_12 -> V_39 ;
V_52:
V_35 = V_33 ;
V_44 = 1 ;
for ( V_3 = V_33 ; V_3 -- != 0 ; ) {
V_32 = F_8 ( V_30 -> V_34 [ V_3 ] ) ;
if ( ! V_32 ) {
V_35 = V_3 ;
continue;
}
if ( ! strcmp ( V_2 , V_32 -> V_2 ) ) {
F_17 ( L_9 ,
V_2 ) ;
return - V_46 ;
}
if ( ( V_32 -> V_39 == V_39 ) &&
( ++ V_44 > 2 ) ) {
if ( V_39 -- == 0 ) {
F_17 ( L_10 ,
V_2 ) ;
return - V_46 ;
}
F_17 ( L_11 ,
V_2 , V_39 + 1 , V_39 ) ;
goto V_52;
}
}
if ( V_35 >= V_33 ) {
F_17 ( L_12 ,
V_2 , V_33 ) ;
return - V_46 ;
}
V_32 = F_21 ( sizeof( * V_32 ) , V_53 ) ;
if ( ! V_32 )
return - V_54 ;
strcpy ( V_32 -> V_2 , V_2 ) ;
V_32 -> V_55 = V_12 ;
V_45 = V_12 -> V_56 ( V_28 , V_32 , V_41 ) ;
if ( V_45 ) {
F_17 ( L_13 ,
V_2 , - V_45 ) ;
return - V_46 ;
}
V_32 -> V_57 = V_35 ;
V_32 -> V_58 = V_12 -> V_58 ;
V_32 -> V_59 = V_12 -> V_59 ;
V_32 -> V_60 = V_38 ;
V_32 -> V_61 = V_35 + 'A' ;
V_32 -> V_39 = V_39 ;
V_45 = F_22 ( V_28 , V_32 , & V_32 -> V_62 ) ;
if ( V_45 ) {
F_23 ( V_28 , V_32 ) ;
F_17 ( L_14 ,
V_2 ) ;
return - V_46 ;
}
F_24 ( V_30 -> V_34 [ V_35 ] , V_32 ) ;
F_25 ( L_15 ,
V_2 ,
F_26 ( V_43 , V_38 ) , V_39 ) ;
return V_45 ;
}
static int F_27 ( struct V_28 * V_28 , struct V_27 * V_32 )
{
F_25 ( L_16 , V_32 -> V_2 ) ;
F_28 ( V_28 , V_32 -> V_57 ) ;
F_29 ( V_28 , V_32 ) ;
return 0 ;
}
static void F_23 ( struct V_28 * V_28 , struct V_27 * V_32 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
T_1 V_3 ;
F_25 ( L_17 , V_32 -> V_2 ) ;
V_32 -> V_55 -> V_63 ( V_32 ) ;
F_28 ( V_28 , V_32 -> V_57 ) ;
F_30 ( V_32 -> V_64 , NULL ) ;
if ( V_32 -> V_37 )
F_31 ( V_32 -> V_37 ) ;
for ( V_3 = 0 ; V_3 < V_33 ; V_3 ++ ) {
if ( V_32 == F_8 ( V_30 -> V_34 [ V_3 ] ) ) {
F_30 ( V_30 -> V_34 [ V_3 ] , NULL ) ;
break;
}
}
F_32 ( V_32 , V_65 ) ;
}
int F_33 ( struct V_28 * V_28 , struct V_27 * V_66 ,
struct V_40 * V_41 [] )
{
struct V_67 * V_68 ;
char * V_69 = strchr ( ( const char * ) V_66 -> V_2 , ':' ) + 1 ;
V_68 = F_34 ( V_28 , V_69 ) ;
if ( ! V_68 )
return - V_70 ;
F_24 ( V_66 -> V_64 , V_68 ) ;
memset ( & V_66 -> V_62 , 0 , sizeof( V_66 -> V_62 ) ) ;
memcpy ( V_66 -> V_62 . V_16 , V_68 -> V_71 , V_66 -> V_55 -> V_72 ) ;
V_66 -> V_62 . V_14 = V_66 -> V_55 -> V_5 ;
V_66 -> V_62 . V_71 = 1 ;
V_66 -> V_73 = V_68 -> V_73 ;
V_66 -> V_55 -> V_74 ( V_66 , & V_66 -> V_75 , ( char * ) V_68 -> V_76 ) ;
F_24 ( V_68 -> V_77 , V_66 ) ;
return 0 ;
}
void F_35 ( struct V_27 * V_66 )
{
struct V_67 * V_68 ;
V_68 = (struct V_67 * ) F_8 ( V_66 -> V_64 ) ;
F_30 ( V_68 -> V_77 , NULL ) ;
F_36 () ;
F_37 ( V_68 ) ;
}
int F_38 ( struct V_28 * V_28 , struct V_78 * V_79 ,
struct V_27 * V_66 , struct V_8 * V_36 )
{
struct V_67 * V_68 ;
int V_80 ;
V_68 = (struct V_67 * ) F_11 ( V_66 -> V_64 ) ;
if ( ! V_68 )
return 0 ;
V_80 = V_68 -> V_81 - F_39 ( V_79 ) ;
if ( ( V_80 > 0 ) &&
F_40 ( V_79 , F_41 ( V_80 ) , 0 , V_53 ) ) {
F_42 ( V_79 ) ;
return 0 ;
}
F_43 ( V_79 ) ;
V_79 -> V_68 = V_68 ;
V_79 -> V_82 = F_44 ( V_83 ) ;
F_45 ( V_79 , V_68 , V_83 , V_36 -> V_16 ,
V_68 -> V_76 , V_79 -> V_7 ) ;
F_46 ( V_79 ) ;
return 0 ;
}
int F_47 ( struct V_28 * V_28 , T_1 V_35 )
{
int V_73 = 0 ;
struct V_27 * V_66 ;
F_10 () ;
V_66 = F_11 ( V_29 ( V_28 ) -> V_34 [ V_35 ] ) ;
if ( V_66 )
V_73 = V_66 -> V_73 ;
F_13 () ;
return V_73 ;
}
void F_48 ( struct V_28 * V_28 , T_1 V_35 ,
struct V_78 * V_79 ,
struct V_8 * V_36 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_27 * V_66 ;
F_10 () ;
V_66 = F_11 ( V_30 -> V_34 [ V_35 ] ) ;
if ( F_49 ( V_66 ) )
V_66 -> V_55 -> V_84 ( V_28 , V_79 , V_66 , V_36 ) ;
F_13 () ;
}
void F_50 ( struct V_28 * V_28 , T_1 V_35 ,
struct V_85 * V_86 ,
struct V_8 * V_87 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
struct V_27 * V_66 ;
struct V_78 * V_79 , * V_88 ;
if ( F_51 ( V_86 ) )
return;
F_10 () ;
V_66 = F_11 ( V_30 -> V_34 [ V_35 ] ) ;
if ( F_49 ( V_66 ) ) {
F_52 (xmitq, skb, tmp) {
F_53 ( V_86 ) ;
V_66 -> V_55 -> V_84 ( V_28 , V_79 , V_66 , V_87 ) ;
}
}
F_13 () ;
}
void F_54 ( struct V_28 * V_28 , T_1 V_35 ,
struct V_85 * V_86 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
int V_89 = V_30 -> V_89 ;
struct V_27 * V_66 ;
struct V_78 * V_79 , * V_88 ;
struct V_90 * V_91 ;
F_10 () ;
V_66 = F_11 ( V_30 -> V_34 [ V_35 ] ) ;
if ( F_49 ( V_66 ) ) {
F_52 (xmitq, skb, tmp) {
V_91 = F_55 ( V_79 ) ;
F_56 ( V_91 , 1 ) ;
F_57 ( V_91 , V_89 ) ;
F_53 ( V_86 ) ;
V_66 -> V_55 -> V_84 ( V_28 , V_79 , V_66 , & V_66 -> V_62 ) ;
}
}
F_13 () ;
}
static int F_58 ( struct V_78 * V_6 , struct V_67 * V_68 ,
struct V_92 * V_93 , struct V_67 * V_94 )
{
struct V_27 * V_32 ;
F_10 () ;
V_32 = F_11 ( V_68 -> V_77 ) ;
if ( F_49 ( V_32 ) ) {
if ( F_49 ( V_6 -> V_95 <= V_96 ) ) {
V_6 -> V_97 = NULL ;
F_59 ( F_60 ( V_68 ) , V_6 , V_32 ) ;
F_13 () ;
return V_98 ;
}
}
F_13 () ;
F_42 ( V_6 ) ;
return V_99 ;
}
static int F_61 ( struct V_100 * V_101 , unsigned long V_102 ,
void * V_103 )
{
struct V_67 * V_68 = F_62 ( V_103 ) ;
struct V_28 * V_28 = F_60 ( V_68 ) ;
struct V_27 * V_32 ;
V_32 = F_8 ( V_68 -> V_77 ) ;
if ( ! V_32 )
return V_104 ;
V_32 -> V_73 = V_68 -> V_73 ;
switch ( V_102 ) {
case V_105 :
if ( F_63 ( V_68 ) )
break;
case V_106 :
case V_107 :
F_27 ( V_28 , V_32 ) ;
break;
case V_108 :
V_32 -> V_55 -> V_74 ( V_32 , & V_32 -> V_75 ,
( char * ) V_68 -> V_76 ) ;
F_27 ( V_28 , V_32 ) ;
break;
case V_109 :
case V_110 :
F_23 ( F_60 ( V_68 ) , V_32 ) ;
break;
}
return V_111 ;
}
int F_64 ( void )
{
int V_112 ;
V_112 = F_65 ( & V_113 ) ;
if ( V_112 )
return V_112 ;
F_66 ( & V_114 ) ;
return 0 ;
}
void F_67 ( void )
{
F_68 ( & V_113 ) ;
F_69 ( & V_114 ) ;
}
void F_70 ( struct V_28 * V_28 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
struct V_27 * V_32 ;
T_1 V_3 ;
for ( V_3 = 0 ; V_3 < V_33 ; V_3 ++ ) {
V_32 = F_8 ( V_30 -> V_34 [ V_3 ] ) ;
if ( V_32 ) {
F_23 ( V_28 , V_32 ) ;
V_30 -> V_34 [ V_3 ] = NULL ;
}
}
}
static int F_71 ( struct V_115 * V_116 ,
struct V_27 * V_117 , int V_118 )
{
void * V_91 ;
struct V_40 * V_119 ;
struct V_40 * V_120 ;
V_91 = F_72 ( V_116 -> V_79 , V_116 -> V_121 , V_116 -> V_122 , & V_123 ,
V_118 , V_124 ) ;
if ( ! V_91 )
return - V_125 ;
V_119 = F_73 ( V_116 -> V_79 , V_126 ) ;
if ( ! V_119 )
goto V_127;
if ( F_74 ( V_116 -> V_79 , V_128 , V_117 -> V_2 ) )
goto V_129;
V_120 = F_73 ( V_116 -> V_79 , V_130 ) ;
if ( ! V_120 )
goto V_131;
if ( F_75 ( V_116 -> V_79 , V_132 , V_117 -> V_39 ) )
goto V_131;
if ( F_75 ( V_116 -> V_79 , V_133 , V_117 -> V_58 ) )
goto V_131;
if ( F_75 ( V_116 -> V_79 , V_134 , V_117 -> V_59 ) )
goto V_131;
F_76 ( V_116 -> V_79 , V_120 ) ;
F_76 ( V_116 -> V_79 , V_119 ) ;
F_77 ( V_116 -> V_79 , V_91 ) ;
return 0 ;
V_131:
F_78 ( V_116 -> V_79 , V_120 ) ;
V_129:
F_78 ( V_116 -> V_79 , V_119 ) ;
V_127:
F_79 ( V_116 -> V_79 , V_91 ) ;
return - V_125 ;
}
int F_80 ( struct V_78 * V_79 , struct V_135 * V_136 )
{
int V_112 ;
int V_3 = V_136 -> args [ 0 ] ;
struct V_27 * V_117 ;
struct V_115 V_116 ;
struct V_28 * V_28 = F_81 ( V_79 -> V_137 ) ;
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
if ( V_3 == V_33 )
return 0 ;
V_116 . V_79 = V_79 ;
V_116 . V_121 = F_82 ( V_136 -> V_79 ) . V_121 ;
V_116 . V_122 = V_136 -> V_138 -> V_139 ;
F_83 () ;
for ( V_3 = 0 ; V_3 < V_33 ; V_3 ++ ) {
V_117 = F_8 ( V_30 -> V_34 [ V_3 ] ) ;
if ( ! V_117 )
continue;
V_112 = F_71 ( & V_116 , V_117 , V_140 ) ;
if ( V_112 )
break;
}
F_84 () ;
V_136 -> args [ 0 ] = V_3 ;
return V_79 -> V_7 ;
}
int F_85 ( struct V_78 * V_79 , struct V_141 * V_142 )
{
int V_112 ;
char * V_2 ;
struct V_78 * V_143 ;
struct V_27 * V_117 ;
struct V_115 V_116 ;
struct V_40 * V_119 [ V_144 + 1 ] ;
struct V_28 * V_28 = F_86 ( V_142 ) ;
if ( ! V_142 -> V_119 [ V_126 ] )
return - V_46 ;
V_112 = F_87 ( V_119 , V_144 ,
V_142 -> V_119 [ V_126 ] ,
V_145 ) ;
if ( V_112 )
return V_112 ;
if ( ! V_119 [ V_128 ] )
return - V_46 ;
V_2 = F_88 ( V_119 [ V_128 ] ) ;
V_143 = F_89 ( V_146 , V_147 ) ;
if ( ! V_143 )
return - V_54 ;
V_116 . V_79 = V_143 ;
V_116 . V_121 = V_142 -> V_148 ;
V_116 . V_122 = V_142 -> V_149 ;
F_83 () ;
V_117 = F_6 ( V_28 , V_2 ) ;
if ( ! V_117 ) {
V_112 = - V_46 ;
goto V_150;
}
V_112 = F_71 ( & V_116 , V_117 , 0 ) ;
if ( V_112 )
goto V_150;
F_84 () ;
return F_90 ( V_143 , V_142 ) ;
V_150:
F_84 () ;
F_91 ( V_143 ) ;
return V_112 ;
}
int F_92 ( struct V_78 * V_79 , struct V_141 * V_142 )
{
int V_112 ;
char * V_2 ;
struct V_27 * V_117 ;
struct V_40 * V_119 [ V_144 + 1 ] ;
struct V_28 * V_28 = F_81 ( V_79 -> V_137 ) ;
if ( ! V_142 -> V_119 [ V_126 ] )
return - V_46 ;
V_112 = F_87 ( V_119 , V_144 ,
V_142 -> V_119 [ V_126 ] ,
V_145 ) ;
if ( V_112 )
return V_112 ;
if ( ! V_119 [ V_128 ] )
return - V_46 ;
V_2 = F_88 ( V_119 [ V_128 ] ) ;
F_83 () ;
V_117 = F_6 ( V_28 , V_2 ) ;
if ( ! V_117 ) {
F_84 () ;
return - V_46 ;
}
F_23 ( V_28 , V_117 ) ;
F_84 () ;
return 0 ;
}
int F_93 ( struct V_78 * V_79 , struct V_141 * V_142 )
{
int V_112 ;
char * V_117 ;
struct V_40 * V_119 [ V_144 + 1 ] ;
struct V_28 * V_28 = F_81 ( V_79 -> V_137 ) ;
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
T_1 V_60 ;
T_1 V_151 ;
V_151 = V_51 ;
V_60 = V_30 -> V_47 & V_49 ;
if ( ! V_142 -> V_119 [ V_126 ] )
return - V_46 ;
V_112 = F_87 ( V_119 , V_144 ,
V_142 -> V_119 [ V_126 ] ,
V_145 ) ;
if ( V_112 )
return V_112 ;
if ( ! V_119 [ V_128 ] )
return - V_46 ;
V_117 = F_88 ( V_119 [ V_128 ] ) ;
if ( V_119 [ V_152 ] )
V_60 = F_94 ( V_119 [ V_152 ] ) ;
if ( V_119 [ V_130 ] ) {
struct V_40 * V_153 [ V_154 + 1 ] ;
V_112 = F_95 ( V_119 [ V_130 ] ,
V_153 ) ;
if ( V_112 )
return V_112 ;
if ( V_153 [ V_132 ] )
V_151 = F_94 ( V_153 [ V_132 ] ) ;
}
F_83 () ;
V_112 = F_16 ( V_28 , V_117 , V_60 , V_151 , V_119 ) ;
if ( V_112 ) {
F_84 () ;
return V_112 ;
}
F_84 () ;
return 0 ;
}
int F_96 ( struct V_78 * V_79 , struct V_141 * V_142 )
{
int V_112 ;
char * V_2 ;
struct V_27 * V_66 ;
struct V_40 * V_119 [ V_144 + 1 ] ;
struct V_28 * V_28 = F_81 ( V_79 -> V_137 ) ;
if ( ! V_142 -> V_119 [ V_126 ] )
return - V_46 ;
V_112 = F_87 ( V_119 , V_144 ,
V_142 -> V_119 [ V_126 ] ,
V_145 ) ;
if ( V_112 )
return V_112 ;
if ( ! V_119 [ V_128 ] )
return - V_46 ;
V_2 = F_88 ( V_119 [ V_128 ] ) ;
F_83 () ;
V_66 = F_6 ( V_28 , V_2 ) ;
if ( ! V_66 ) {
F_84 () ;
return - V_46 ;
}
if ( V_119 [ V_130 ] ) {
struct V_40 * V_153 [ V_154 + 1 ] ;
V_112 = F_95 ( V_119 [ V_130 ] ,
V_153 ) ;
if ( V_112 ) {
F_84 () ;
return V_112 ;
}
if ( V_153 [ V_133 ] )
V_66 -> V_58 = F_94 ( V_153 [ V_133 ] ) ;
if ( V_153 [ V_132 ] )
V_66 -> V_39 = F_94 ( V_153 [ V_132 ] ) ;
if ( V_153 [ V_134 ] )
V_66 -> V_59 = F_94 ( V_153 [ V_134 ] ) ;
}
F_84 () ;
return 0 ;
}
static int F_97 ( struct V_115 * V_116 ,
struct V_1 * V_55 , int V_118 )
{
void * V_91 ;
struct V_40 * V_119 ;
struct V_40 * V_120 ;
V_91 = F_72 ( V_116 -> V_79 , V_116 -> V_121 , V_116 -> V_122 , & V_123 ,
V_118 , V_155 ) ;
if ( ! V_91 )
return - V_125 ;
V_119 = F_73 ( V_116 -> V_79 , V_156 ) ;
if ( ! V_119 )
goto V_127;
if ( F_74 ( V_116 -> V_79 , V_157 , V_55 -> V_2 ) )
goto V_129;
V_120 = F_73 ( V_116 -> V_79 , V_158 ) ;
if ( ! V_120 )
goto V_131;
if ( F_75 ( V_116 -> V_79 , V_132 , V_55 -> V_39 ) )
goto V_131;
if ( F_75 ( V_116 -> V_79 , V_133 , V_55 -> V_58 ) )
goto V_131;
if ( F_75 ( V_116 -> V_79 , V_134 , V_55 -> V_59 ) )
goto V_131;
F_76 ( V_116 -> V_79 , V_120 ) ;
F_76 ( V_116 -> V_79 , V_119 ) ;
F_77 ( V_116 -> V_79 , V_91 ) ;
return 0 ;
V_131:
F_78 ( V_116 -> V_79 , V_120 ) ;
V_129:
F_78 ( V_116 -> V_79 , V_119 ) ;
V_127:
F_79 ( V_116 -> V_79 , V_91 ) ;
return - V_125 ;
}
int F_98 ( struct V_78 * V_79 , struct V_135 * V_136 )
{
int V_112 ;
int V_3 = V_136 -> args [ 0 ] ;
struct V_115 V_116 ;
if ( V_3 == V_159 )
return 0 ;
V_116 . V_79 = V_79 ;
V_116 . V_121 = F_82 ( V_136 -> V_79 ) . V_121 ;
V_116 . V_122 = V_136 -> V_138 -> V_139 ;
F_83 () ;
for (; V_4 [ V_3 ] != NULL ; V_3 ++ ) {
V_112 = F_97 ( & V_116 , V_4 [ V_3 ] ,
V_140 ) ;
if ( V_112 )
break;
}
F_84 () ;
V_136 -> args [ 0 ] = V_3 ;
return V_79 -> V_7 ;
}
int F_99 ( struct V_78 * V_79 , struct V_141 * V_142 )
{
int V_112 ;
char * V_2 ;
struct V_115 V_116 ;
struct V_1 * V_55 ;
struct V_78 * V_143 ;
struct V_40 * V_119 [ V_144 + 1 ] ;
if ( ! V_142 -> V_119 [ V_156 ] )
return - V_46 ;
V_112 = F_87 ( V_119 , V_160 ,
V_142 -> V_119 [ V_156 ] ,
V_161 ) ;
if ( V_112 )
return V_112 ;
if ( ! V_119 [ V_157 ] )
return - V_46 ;
V_2 = F_88 ( V_119 [ V_157 ] ) ;
V_143 = F_89 ( V_146 , V_147 ) ;
if ( ! V_143 )
return - V_54 ;
V_116 . V_79 = V_143 ;
V_116 . V_121 = V_142 -> V_148 ;
V_116 . V_122 = V_142 -> V_149 ;
F_83 () ;
V_55 = F_1 ( V_2 ) ;
if ( ! V_55 ) {
V_112 = - V_46 ;
goto V_150;
}
V_112 = F_97 ( & V_116 , V_55 , 0 ) ;
if ( V_112 )
goto V_150;
F_84 () ;
return F_90 ( V_143 , V_142 ) ;
V_150:
F_84 () ;
F_91 ( V_143 ) ;
return V_112 ;
}
int F_100 ( struct V_78 * V_79 , struct V_141 * V_142 )
{
int V_112 ;
char * V_2 ;
struct V_1 * V_162 ;
struct V_40 * V_119 [ V_144 + 1 ] ;
if ( ! V_142 -> V_119 [ V_156 ] )
return - V_46 ;
V_112 = F_87 ( V_119 , V_160 ,
V_142 -> V_119 [ V_156 ] ,
V_161 ) ;
if ( ! V_119 [ V_157 ] )
return - V_46 ;
V_2 = F_88 ( V_119 [ V_157 ] ) ;
F_83 () ;
V_162 = F_1 ( V_2 ) ;
if ( ! V_162 ) {
F_84 () ;
return - V_46 ;
}
if ( V_119 [ V_158 ] ) {
struct V_40 * V_153 [ V_154 + 1 ] ;
V_112 = F_95 ( V_119 [ V_158 ] ,
V_153 ) ;
if ( V_112 ) {
F_84 () ;
return V_112 ;
}
if ( V_153 [ V_133 ] )
V_162 -> V_58 = F_94 ( V_153 [ V_133 ] ) ;
if ( V_153 [ V_132 ] )
V_162 -> V_39 = F_94 ( V_153 [ V_132 ] ) ;
if ( V_153 [ V_134 ] )
V_162 -> V_59 = F_94 ( V_153 [ V_134 ] ) ;
}
F_84 () ;
return 0 ;
}
