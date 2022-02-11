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
int F_9 ( struct V_28 * V_28 , char * V_2 , T_1 V_35 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_27 * V_32 ;
if ( V_35 >= V_33 )
return - V_36 ;
V_32 = F_8 ( V_30 -> V_34 [ V_35 ] ) ;
if ( ! V_32 )
return - V_36 ;
strcpy ( V_2 , V_32 -> V_2 ) ;
return 0 ;
}
void F_10 ( struct V_28 * V_28 , T_1 V_35 , T_1 V_37 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
struct V_27 * V_32 ;
F_11 () ;
V_32 = F_12 ( V_30 -> V_34 [ V_35 ] ) ;
if ( V_32 )
F_13 ( V_32 -> V_38 ) ;
F_14 () ;
}
void F_15 ( struct V_28 * V_28 , T_1 V_35 , T_1 V_37 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
struct V_27 * V_32 ;
F_11 () ;
V_32 = F_12 ( V_30 -> V_34 [ V_35 ] ) ;
if ( V_32 )
F_16 ( V_32 -> V_38 ) ;
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
struct V_44 * V_45 ;
char V_46 [ 16 ] ;
T_1 V_35 ;
T_1 V_47 ;
T_1 V_3 ;
int V_48 = - V_36 ;
if ( ! V_30 -> V_49 ) {
F_18 ( L_4 ,
V_2 ) ;
return - V_50 ;
}
if ( ! F_5 ( V_2 , & V_43 ) ) {
F_18 ( L_5 , V_2 ) ;
return - V_36 ;
}
if ( F_19 ( V_39 ) &&
( V_39 != V_30 -> V_49 ) ) {
if ( F_20 ( V_39 , V_30 -> V_49 ) ) {
V_39 = V_30 -> V_49 & V_51 ;
V_48 = 0 ;
} else if ( F_21 ( V_28 , V_39 ) )
V_48 = 0 ;
}
if ( V_48 ) {
F_18 ( L_6 ,
V_2 ) ;
return - V_36 ;
}
if ( ( V_40 > V_52 ) &&
( V_40 != V_53 ) ) {
F_18 ( L_7 , V_2 ) ;
return - V_36 ;
}
V_12 = F_1 ( V_43 . V_21 ) ;
if ( ! V_12 ) {
F_18 ( L_8 ,
V_2 , V_43 . V_21 ) ;
return - V_36 ;
}
if ( V_40 == V_53 )
V_40 = V_12 -> V_40 ;
V_54:
V_35 = V_33 ;
V_47 = 1 ;
for ( V_3 = V_33 ; V_3 -- != 0 ; ) {
V_32 = F_8 ( V_30 -> V_34 [ V_3 ] ) ;
if ( ! V_32 ) {
V_35 = V_3 ;
continue;
}
if ( ! strcmp ( V_2 , V_32 -> V_2 ) ) {
F_18 ( L_9 ,
V_2 ) ;
return - V_36 ;
}
if ( ( V_32 -> V_40 == V_40 ) &&
( ++ V_47 > 2 ) ) {
if ( V_40 -- == 0 ) {
F_18 ( L_10 ,
V_2 ) ;
return - V_36 ;
}
F_18 ( L_11 ,
V_2 , V_40 + 1 , V_40 ) ;
goto V_54;
}
}
if ( V_35 >= V_33 ) {
F_18 ( L_12 ,
V_2 , V_33 ) ;
return - V_36 ;
}
V_32 = F_22 ( sizeof( * V_32 ) , V_55 ) ;
if ( ! V_32 )
return - V_56 ;
strcpy ( V_32 -> V_2 , V_2 ) ;
V_32 -> V_57 = V_12 ;
V_48 = V_12 -> V_58 ( V_28 , V_32 , V_42 ) ;
if ( V_48 ) {
F_18 ( L_13 ,
V_2 , - V_48 ) ;
return - V_36 ;
}
V_32 -> V_59 = V_35 ;
V_32 -> V_60 = V_12 -> V_60 ;
V_32 -> V_61 = V_12 -> V_61 ;
V_32 -> V_62 = V_39 ;
V_32 -> V_63 = V_35 + 'A' ;
V_32 -> V_40 = V_40 ;
V_48 = F_23 ( V_28 , V_32 , & V_32 -> V_64 , & V_45 ) ;
if ( V_48 ) {
F_24 ( V_28 , V_32 ) ;
F_18 ( L_14 ,
V_2 ) ;
return - V_36 ;
}
F_25 ( V_30 -> V_34 [ V_35 ] , V_32 ) ;
if ( V_45 )
F_26 ( V_28 , V_35 , V_45 , & V_32 -> V_64 ) ;
if ( F_27 ( V_28 , V_35 ) )
return - V_56 ;
F_28 ( L_15 ,
V_2 ,
F_29 ( V_46 , V_39 ) , V_40 ) ;
return V_48 ;
}
static int F_30 ( struct V_28 * V_28 , struct V_27 * V_32 )
{
F_28 ( L_16 , V_32 -> V_2 ) ;
F_31 ( V_28 , V_32 -> V_59 ) ;
F_32 ( V_28 , V_32 ) ;
return 0 ;
}
void F_33 ( struct V_28 * V_28 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_27 * V_32 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_33 ; V_3 ++ ) {
V_32 = F_12 ( V_30 -> V_34 [ V_3 ] ) ;
if ( V_32 )
F_30 ( V_28 , V_32 ) ;
}
}
static void F_24 ( struct V_28 * V_28 , struct V_27 * V_32 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
int V_35 = V_32 -> V_59 ;
F_28 ( L_17 , V_32 -> V_2 ) ;
V_32 -> V_57 -> V_65 ( V_32 ) ;
F_31 ( V_28 , V_35 ) ;
F_34 ( V_32 -> V_66 , NULL ) ;
if ( V_32 -> V_38 )
F_35 ( V_32 -> V_38 ) ;
F_34 ( V_30 -> V_34 [ V_35 ] , NULL ) ;
F_36 ( V_32 , V_67 ) ;
F_37 ( V_28 , V_35 ) ;
}
int F_38 ( struct V_28 * V_28 , struct V_27 * V_32 ,
struct V_41 * V_42 [] )
{
struct V_68 * V_69 ;
char * V_70 = strchr ( ( const char * ) V_32 -> V_2 , ':' ) + 1 ;
V_69 = F_39 ( V_28 , V_70 ) ;
if ( ! V_69 )
return - V_71 ;
F_25 ( V_32 -> V_66 , V_69 ) ;
memset ( & V_32 -> V_64 , 0 , sizeof( V_32 -> V_64 ) ) ;
memcpy ( V_32 -> V_64 . V_16 , V_69 -> V_72 , V_32 -> V_57 -> V_73 ) ;
V_32 -> V_64 . V_14 = V_32 -> V_57 -> V_5 ;
V_32 -> V_64 . V_72 = 1 ;
V_32 -> V_74 = V_69 -> V_74 ;
V_32 -> V_57 -> V_75 ( V_32 , & V_32 -> V_76 , ( char * ) V_69 -> V_77 ) ;
F_25 ( V_69 -> V_78 , V_32 ) ;
return 0 ;
}
void F_40 ( struct V_27 * V_32 )
{
struct V_68 * V_69 ;
V_69 = (struct V_68 * ) F_8 ( V_32 -> V_66 ) ;
F_34 ( V_69 -> V_78 , NULL ) ;
F_41 () ;
F_42 ( V_69 ) ;
}
int F_43 ( struct V_28 * V_28 , struct V_44 * V_45 ,
struct V_27 * V_32 , struct V_8 * V_37 )
{
struct V_68 * V_69 ;
int V_79 ;
void * V_78 ;
V_69 = (struct V_68 * ) F_12 ( V_32 -> V_66 ) ;
if ( ! V_69 )
return 0 ;
V_78 = F_12 ( V_69 -> V_78 ) ;
if ( F_44 ( ! V_78 && ! F_45 ( F_46 ( V_45 ) ) ) )
goto V_80;
V_79 = V_69 -> V_81 - F_47 ( V_45 ) ;
if ( ( V_79 > 0 ) &&
F_48 ( V_45 , F_49 ( V_79 ) , 0 , V_55 ) )
goto V_80;
F_50 ( V_45 ) ;
V_45 -> V_69 = V_69 ;
V_45 -> V_82 = F_51 ( V_83 ) ;
F_52 ( V_45 , V_69 , V_83 , V_37 -> V_16 ,
V_69 -> V_77 , V_45 -> V_7 ) ;
F_53 ( V_45 ) ;
return 0 ;
V_80:
F_54 ( V_45 ) ;
return 0 ;
}
int F_55 ( struct V_28 * V_28 , T_1 V_35 )
{
int V_74 = 0 ;
struct V_27 * V_32 ;
F_11 () ;
V_32 = F_12 ( V_29 ( V_28 ) -> V_34 [ V_35 ] ) ;
if ( V_32 )
V_74 = V_32 -> V_74 ;
F_14 () ;
return V_74 ;
}
void F_26 ( struct V_28 * V_28 , T_1 V_35 ,
struct V_44 * V_45 ,
struct V_8 * V_37 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_27 * V_32 ;
F_11 () ;
V_32 = F_12 ( V_30 -> V_34 [ V_35 ] ) ;
if ( F_56 ( V_32 ) )
V_32 -> V_57 -> V_84 ( V_28 , V_45 , V_32 , V_37 ) ;
else
F_54 ( V_45 ) ;
F_14 () ;
}
void F_57 ( struct V_28 * V_28 , T_1 V_35 ,
struct V_85 * V_86 ,
struct V_8 * V_87 )
{
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
struct V_27 * V_32 ;
struct V_44 * V_45 , * V_88 ;
if ( F_58 ( V_86 ) )
return;
F_11 () ;
V_32 = F_12 ( V_30 -> V_34 [ V_35 ] ) ;
if ( F_44 ( ! V_32 ) )
F_59 ( V_86 ) ;
F_60 (xmitq, skb, tmp) {
F_61 ( V_86 ) ;
V_32 -> V_57 -> V_84 ( V_28 , V_45 , V_32 , V_87 ) ;
}
F_14 () ;
}
void F_62 ( struct V_28 * V_28 , T_1 V_35 ,
struct V_85 * V_86 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
int V_89 = V_30 -> V_89 ;
struct V_27 * V_32 ;
struct V_44 * V_45 , * V_88 ;
struct V_90 * V_91 ;
F_11 () ;
V_32 = F_12 ( V_30 -> V_34 [ V_35 ] ) ;
if ( F_44 ( ! V_32 ) )
F_59 ( V_86 ) ;
F_60 (xmitq, skb, tmp) {
V_91 = F_46 ( V_45 ) ;
F_63 ( V_91 , 1 ) ;
F_64 ( V_91 , V_89 ) ;
F_61 ( V_86 ) ;
V_32 -> V_57 -> V_84 ( V_28 , V_45 , V_32 , & V_32 -> V_64 ) ;
}
F_14 () ;
}
static int F_65 ( struct V_44 * V_45 , struct V_68 * V_69 ,
struct V_92 * V_93 , struct V_68 * V_94 )
{
struct V_27 * V_32 ;
F_11 () ;
V_32 = F_12 ( V_69 -> V_78 ) ;
if ( F_56 ( V_32 && ( V_45 -> V_95 <= V_96 ) ) ) {
V_45 -> V_97 = NULL ;
F_66 ( F_67 ( V_69 ) , V_45 , V_32 ) ;
F_14 () ;
return V_98 ;
}
F_14 () ;
F_54 ( V_45 ) ;
return V_99 ;
}
static int F_68 ( struct V_100 * V_101 , unsigned long V_102 ,
void * V_103 )
{
struct V_68 * V_69 = F_69 ( V_103 ) ;
struct V_28 * V_28 = F_67 ( V_69 ) ;
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_27 * V_32 ;
int V_3 ;
V_32 = F_8 ( V_69 -> V_78 ) ;
if ( ! V_32 ) {
for ( V_3 = 0 ; V_3 < V_33 ; V_32 = NULL , V_3 ++ ) {
V_32 = F_8 ( V_30 -> V_34 [ V_3 ] ) ;
if ( V_32 && ( V_32 -> V_66 == V_69 ) )
break;
}
}
if ( ! V_32 )
return V_104 ;
V_32 -> V_74 = V_69 -> V_74 ;
switch ( V_102 ) {
case V_105 :
if ( F_70 ( V_69 ) )
break;
case V_106 :
F_25 ( V_69 -> V_78 , V_32 ) ;
break;
case V_107 :
F_34 ( V_69 -> V_78 , NULL ) ;
F_41 () ;
F_30 ( V_28 , V_32 ) ;
break;
case V_108 :
F_30 ( V_28 , V_32 ) ;
break;
case V_109 :
V_32 -> V_57 -> V_75 ( V_32 , & V_32 -> V_76 ,
( char * ) V_69 -> V_77 ) ;
F_30 ( V_28 , V_32 ) ;
break;
case V_110 :
case V_111 :
F_24 ( F_67 ( V_69 ) , V_32 ) ;
break;
}
return V_112 ;
}
int F_71 ( void )
{
int V_113 ;
V_113 = F_72 ( & V_114 ) ;
if ( V_113 )
return V_113 ;
F_73 ( & V_115 ) ;
return 0 ;
}
void F_74 ( void )
{
F_75 ( & V_114 ) ;
F_76 ( & V_115 ) ;
}
void F_77 ( struct V_28 * V_28 )
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
static int F_78 ( struct V_116 * V_117 ,
struct V_27 * V_118 , int V_119 )
{
void * V_91 ;
struct V_41 * V_120 ;
struct V_41 * V_121 ;
V_91 = F_79 ( V_117 -> V_45 , V_117 -> V_122 , V_117 -> V_123 , & V_124 ,
V_119 , V_125 ) ;
if ( ! V_91 )
return - V_126 ;
V_120 = F_80 ( V_117 -> V_45 , V_127 ) ;
if ( ! V_120 )
goto V_128;
if ( F_81 ( V_117 -> V_45 , V_129 , V_118 -> V_2 ) )
goto V_130;
V_121 = F_80 ( V_117 -> V_45 , V_131 ) ;
if ( ! V_121 )
goto V_132;
if ( F_82 ( V_117 -> V_45 , V_133 , V_118 -> V_40 ) )
goto V_132;
if ( F_82 ( V_117 -> V_45 , V_134 , V_118 -> V_60 ) )
goto V_132;
if ( F_82 ( V_117 -> V_45 , V_135 , V_118 -> V_61 ) )
goto V_132;
F_83 ( V_117 -> V_45 , V_121 ) ;
F_83 ( V_117 -> V_45 , V_120 ) ;
F_84 ( V_117 -> V_45 , V_91 ) ;
return 0 ;
V_132:
F_85 ( V_117 -> V_45 , V_121 ) ;
V_130:
F_85 ( V_117 -> V_45 , V_120 ) ;
V_128:
F_86 ( V_117 -> V_45 , V_91 ) ;
return - V_126 ;
}
int F_87 ( struct V_44 * V_45 , struct V_136 * V_137 )
{
int V_113 ;
int V_3 = V_137 -> args [ 0 ] ;
struct V_27 * V_118 ;
struct V_116 V_117 ;
struct V_28 * V_28 = F_88 ( V_45 -> V_138 ) ;
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
if ( V_3 == V_33 )
return 0 ;
V_117 . V_45 = V_45 ;
V_117 . V_122 = F_89 ( V_137 -> V_45 ) . V_122 ;
V_117 . V_123 = V_137 -> V_139 -> V_140 ;
F_90 () ;
for ( V_3 = 0 ; V_3 < V_33 ; V_3 ++ ) {
V_118 = F_8 ( V_30 -> V_34 [ V_3 ] ) ;
if ( ! V_118 )
continue;
V_113 = F_78 ( & V_117 , V_118 , V_141 ) ;
if ( V_113 )
break;
}
F_91 () ;
V_137 -> args [ 0 ] = V_3 ;
return V_45 -> V_7 ;
}
int F_92 ( struct V_44 * V_45 , struct V_142 * V_143 )
{
int V_113 ;
char * V_2 ;
struct V_44 * V_144 ;
struct V_27 * V_118 ;
struct V_116 V_117 ;
struct V_41 * V_120 [ V_145 + 1 ] ;
struct V_28 * V_28 = F_93 ( V_143 ) ;
if ( ! V_143 -> V_120 [ V_127 ] )
return - V_36 ;
V_113 = F_94 ( V_120 , V_145 ,
V_143 -> V_120 [ V_127 ] ,
V_146 ) ;
if ( V_113 )
return V_113 ;
if ( ! V_120 [ V_129 ] )
return - V_36 ;
V_2 = F_95 ( V_120 [ V_129 ] ) ;
V_144 = F_96 ( V_147 , V_148 ) ;
if ( ! V_144 )
return - V_56 ;
V_117 . V_45 = V_144 ;
V_117 . V_122 = V_143 -> V_149 ;
V_117 . V_123 = V_143 -> V_150 ;
F_90 () ;
V_118 = F_6 ( V_28 , V_2 ) ;
if ( ! V_118 ) {
V_113 = - V_36 ;
goto V_151;
}
V_113 = F_78 ( & V_117 , V_118 , 0 ) ;
if ( V_113 )
goto V_151;
F_91 () ;
return F_97 ( V_144 , V_143 ) ;
V_151:
F_91 () ;
F_98 ( V_144 ) ;
return V_113 ;
}
int F_99 ( struct V_44 * V_45 , struct V_142 * V_143 )
{
int V_113 ;
char * V_2 ;
struct V_27 * V_118 ;
struct V_41 * V_120 [ V_145 + 1 ] ;
struct V_28 * V_28 = F_88 ( V_45 -> V_138 ) ;
if ( ! V_143 -> V_120 [ V_127 ] )
return - V_36 ;
V_113 = F_94 ( V_120 , V_145 ,
V_143 -> V_120 [ V_127 ] ,
V_146 ) ;
if ( V_113 )
return V_113 ;
if ( ! V_120 [ V_129 ] )
return - V_36 ;
V_2 = F_95 ( V_120 [ V_129 ] ) ;
F_90 () ;
V_118 = F_6 ( V_28 , V_2 ) ;
if ( ! V_118 ) {
F_91 () ;
return - V_36 ;
}
F_24 ( V_28 , V_118 ) ;
F_91 () ;
return 0 ;
}
int F_100 ( struct V_44 * V_45 , struct V_142 * V_143 )
{
int V_113 ;
char * V_118 ;
struct V_41 * V_120 [ V_145 + 1 ] ;
struct V_28 * V_28 = F_88 ( V_45 -> V_138 ) ;
struct V_29 * V_30 = F_7 ( V_28 , V_31 ) ;
T_1 V_62 ;
T_1 V_152 ;
V_152 = V_53 ;
V_62 = V_30 -> V_49 & V_51 ;
if ( ! V_143 -> V_120 [ V_127 ] )
return - V_36 ;
V_113 = F_94 ( V_120 , V_145 ,
V_143 -> V_120 [ V_127 ] ,
V_146 ) ;
if ( V_113 )
return V_113 ;
if ( ! V_120 [ V_129 ] )
return - V_36 ;
V_118 = F_95 ( V_120 [ V_129 ] ) ;
if ( V_120 [ V_153 ] )
V_62 = F_101 ( V_120 [ V_153 ] ) ;
if ( V_120 [ V_131 ] ) {
struct V_41 * V_154 [ V_155 + 1 ] ;
V_113 = F_102 ( V_120 [ V_131 ] ,
V_154 ) ;
if ( V_113 )
return V_113 ;
if ( V_154 [ V_133 ] )
V_152 = F_101 ( V_154 [ V_133 ] ) ;
}
F_90 () ;
V_113 = F_17 ( V_28 , V_118 , V_62 , V_152 , V_120 ) ;
if ( V_113 ) {
F_91 () ;
return V_113 ;
}
F_91 () ;
return 0 ;
}
int F_103 ( struct V_44 * V_45 , struct V_142 * V_143 )
{
int V_113 ;
char * V_2 ;
struct V_27 * V_32 ;
struct V_41 * V_120 [ V_145 + 1 ] ;
struct V_28 * V_28 = F_88 ( V_45 -> V_138 ) ;
if ( ! V_143 -> V_120 [ V_127 ] )
return - V_36 ;
V_113 = F_94 ( V_120 , V_145 ,
V_143 -> V_120 [ V_127 ] ,
V_146 ) ;
if ( V_113 )
return V_113 ;
if ( ! V_120 [ V_129 ] )
return - V_36 ;
V_2 = F_95 ( V_120 [ V_129 ] ) ;
F_90 () ;
V_32 = F_6 ( V_28 , V_2 ) ;
if ( ! V_32 ) {
F_91 () ;
return - V_36 ;
}
if ( V_120 [ V_131 ] ) {
struct V_41 * V_154 [ V_155 + 1 ] ;
V_113 = F_102 ( V_120 [ V_131 ] ,
V_154 ) ;
if ( V_113 ) {
F_91 () ;
return V_113 ;
}
if ( V_154 [ V_134 ] )
V_32 -> V_60 = F_101 ( V_154 [ V_134 ] ) ;
if ( V_154 [ V_133 ] )
V_32 -> V_40 = F_101 ( V_154 [ V_133 ] ) ;
if ( V_154 [ V_135 ] )
V_32 -> V_61 = F_101 ( V_154 [ V_135 ] ) ;
}
F_91 () ;
return 0 ;
}
static int F_104 ( struct V_116 * V_117 ,
struct V_1 * V_57 , int V_119 )
{
void * V_91 ;
struct V_41 * V_120 ;
struct V_41 * V_121 ;
V_91 = F_79 ( V_117 -> V_45 , V_117 -> V_122 , V_117 -> V_123 , & V_124 ,
V_119 , V_156 ) ;
if ( ! V_91 )
return - V_126 ;
V_120 = F_80 ( V_117 -> V_45 , V_157 ) ;
if ( ! V_120 )
goto V_128;
if ( F_81 ( V_117 -> V_45 , V_158 , V_57 -> V_2 ) )
goto V_130;
V_121 = F_80 ( V_117 -> V_45 , V_159 ) ;
if ( ! V_121 )
goto V_132;
if ( F_82 ( V_117 -> V_45 , V_133 , V_57 -> V_40 ) )
goto V_132;
if ( F_82 ( V_117 -> V_45 , V_134 , V_57 -> V_60 ) )
goto V_132;
if ( F_82 ( V_117 -> V_45 , V_135 , V_57 -> V_61 ) )
goto V_132;
F_83 ( V_117 -> V_45 , V_121 ) ;
F_83 ( V_117 -> V_45 , V_120 ) ;
F_84 ( V_117 -> V_45 , V_91 ) ;
return 0 ;
V_132:
F_85 ( V_117 -> V_45 , V_121 ) ;
V_130:
F_85 ( V_117 -> V_45 , V_120 ) ;
V_128:
F_86 ( V_117 -> V_45 , V_91 ) ;
return - V_126 ;
}
int F_105 ( struct V_44 * V_45 , struct V_136 * V_137 )
{
int V_113 ;
int V_3 = V_137 -> args [ 0 ] ;
struct V_116 V_117 ;
if ( V_3 == V_160 )
return 0 ;
V_117 . V_45 = V_45 ;
V_117 . V_122 = F_89 ( V_137 -> V_45 ) . V_122 ;
V_117 . V_123 = V_137 -> V_139 -> V_140 ;
F_90 () ;
for (; V_4 [ V_3 ] != NULL ; V_3 ++ ) {
V_113 = F_104 ( & V_117 , V_4 [ V_3 ] ,
V_141 ) ;
if ( V_113 )
break;
}
F_91 () ;
V_137 -> args [ 0 ] = V_3 ;
return V_45 -> V_7 ;
}
int F_106 ( struct V_44 * V_45 , struct V_142 * V_143 )
{
int V_113 ;
char * V_2 ;
struct V_116 V_117 ;
struct V_1 * V_57 ;
struct V_44 * V_144 ;
struct V_41 * V_120 [ V_145 + 1 ] ;
if ( ! V_143 -> V_120 [ V_157 ] )
return - V_36 ;
V_113 = F_94 ( V_120 , V_161 ,
V_143 -> V_120 [ V_157 ] ,
V_162 ) ;
if ( V_113 )
return V_113 ;
if ( ! V_120 [ V_158 ] )
return - V_36 ;
V_2 = F_95 ( V_120 [ V_158 ] ) ;
V_144 = F_96 ( V_147 , V_148 ) ;
if ( ! V_144 )
return - V_56 ;
V_117 . V_45 = V_144 ;
V_117 . V_122 = V_143 -> V_149 ;
V_117 . V_123 = V_143 -> V_150 ;
F_90 () ;
V_57 = F_1 ( V_2 ) ;
if ( ! V_57 ) {
V_113 = - V_36 ;
goto V_151;
}
V_113 = F_104 ( & V_117 , V_57 , 0 ) ;
if ( V_113 )
goto V_151;
F_91 () ;
return F_97 ( V_144 , V_143 ) ;
V_151:
F_91 () ;
F_98 ( V_144 ) ;
return V_113 ;
}
int F_107 ( struct V_44 * V_45 , struct V_142 * V_143 )
{
int V_113 ;
char * V_2 ;
struct V_1 * V_12 ;
struct V_41 * V_120 [ V_145 + 1 ] ;
if ( ! V_143 -> V_120 [ V_157 ] )
return - V_36 ;
V_113 = F_94 ( V_120 , V_161 ,
V_143 -> V_120 [ V_157 ] ,
V_162 ) ;
if ( ! V_120 [ V_158 ] )
return - V_36 ;
V_2 = F_95 ( V_120 [ V_158 ] ) ;
F_90 () ;
V_12 = F_1 ( V_2 ) ;
if ( ! V_12 ) {
F_91 () ;
return - V_36 ;
}
if ( V_120 [ V_159 ] ) {
struct V_41 * V_154 [ V_155 + 1 ] ;
V_113 = F_102 ( V_120 [ V_159 ] ,
V_154 ) ;
if ( V_113 ) {
F_91 () ;
return V_113 ;
}
if ( V_154 [ V_134 ] )
V_12 -> V_60 = F_101 ( V_154 [ V_134 ] ) ;
if ( V_154 [ V_133 ] )
V_12 -> V_40 = F_101 ( V_154 [ V_133 ] ) ;
if ( V_154 [ V_135 ] )
V_12 -> V_61 = F_101 ( V_154 [ V_135 ] ) ;
}
F_91 () ;
return 0 ;
}
