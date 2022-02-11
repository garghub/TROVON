static struct V_1 * F_1 ( struct V_2 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
return F_2 ( V_5 -> V_6 [ V_3 ] ) ;
}
struct V_7 * F_3 ( const char * V_8 )
{
T_1 V_9 ;
for ( V_9 = 0 ; V_10 [ V_9 ] != NULL ; V_9 ++ ) {
if ( ! strcmp ( V_10 [ V_9 ] -> V_8 , V_8 ) )
break;
}
return V_10 [ V_9 ] ;
}
static struct V_7 * F_4 ( T_2 type )
{
T_1 V_9 ;
for ( V_9 = 0 ; V_10 [ V_9 ] != NULL ; V_9 ++ ) {
if ( V_10 [ V_9 ] -> V_11 == type )
break;
}
return V_10 [ V_9 ] ;
}
void F_5 ( char * V_12 , int V_13 , struct V_14 * V_15 )
{
char V_16 [ V_17 ] ;
struct V_7 * V_18 ;
int V_19 ;
V_18 = F_4 ( V_15 -> V_20 ) ;
if ( V_18 && ! V_18 -> V_21 ( V_15 , V_16 , sizeof( V_16 ) ) )
V_19 = F_6 ( V_12 , V_13 , L_1 , V_18 -> V_8 , V_16 ) ;
else {
T_1 V_9 ;
V_19 = F_6 ( V_12 , V_13 , L_2 , V_15 -> V_20 ) ;
for ( V_9 = 0 ; V_9 < sizeof( V_15 -> V_22 ) ; V_9 ++ )
V_19 += F_6 ( V_12 - V_19 , V_13 + V_19 ,
L_3 , V_15 -> V_22 [ V_9 ] ) ;
}
}
static int F_7 ( const char * V_8 ,
struct V_23 * V_24 )
{
char V_25 [ V_26 ] ;
char * V_27 ;
char * V_28 ;
T_1 V_29 ;
T_1 V_30 ;
V_25 [ V_26 - 1 ] = 0 ;
strncpy ( V_25 , V_8 , V_26 ) ;
if ( V_25 [ V_26 - 1 ] != 0 )
return 0 ;
V_27 = V_25 ;
V_28 = strchr ( V_27 , ':' ) ;
if ( V_28 == NULL )
return 0 ;
* ( V_28 ++ ) = 0 ;
V_29 = V_28 - V_27 ;
V_30 = strlen ( V_28 ) + 1 ;
if ( ( V_29 <= 1 ) || ( V_29 > V_31 ) ||
( V_30 <= 1 ) || ( V_30 > V_32 ) )
return 0 ;
if ( V_24 ) {
strcpy ( V_24 -> V_27 , V_27 ) ;
strcpy ( V_24 -> V_28 , V_28 ) ;
}
return 1 ;
}
struct V_1 * F_8 ( struct V_2 * V_2 , const char * V_8 )
{
struct V_4 * V_5 = F_9 ( V_2 , V_33 ) ;
struct V_1 * V_34 ;
T_1 V_9 ;
for ( V_9 = 0 ; V_9 < V_35 ; V_9 ++ ) {
V_34 = F_10 ( V_5 -> V_6 [ V_9 ] ) ;
if ( V_34 && ( ! strcmp ( V_34 -> V_8 , V_8 ) ) )
return V_34 ;
}
return NULL ;
}
int F_11 ( struct V_2 * V_2 , char * V_8 , T_1 V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_1 * V_34 ;
if ( V_3 >= V_35 )
return - V_36 ;
V_34 = F_10 ( V_5 -> V_6 [ V_3 ] ) ;
if ( ! V_34 )
return - V_36 ;
strcpy ( V_8 , V_34 -> V_8 ) ;
return 0 ;
}
void F_12 ( struct V_2 * V_2 , T_1 V_3 , T_1 V_37 )
{
struct V_4 * V_5 = F_9 ( V_2 , V_33 ) ;
struct V_1 * V_34 ;
F_13 () ;
V_34 = F_2 ( V_5 -> V_6 [ V_3 ] ) ;
if ( V_34 )
F_14 ( V_34 -> V_38 ) ;
F_15 () ;
}
void F_16 ( struct V_2 * V_2 , T_1 V_3 , T_1 V_37 )
{
struct V_4 * V_5 = F_9 ( V_2 , V_33 ) ;
struct V_1 * V_34 ;
F_13 () ;
V_34 = F_2 ( V_5 -> V_6 [ V_3 ] ) ;
if ( V_34 )
F_17 ( V_34 -> V_38 ) ;
F_15 () ;
}
static int F_18 ( struct V_2 * V_2 , const char * V_8 ,
T_1 V_39 , T_1 V_40 ,
struct V_41 * V_42 [] )
{
struct V_4 * V_5 = F_9 ( V_2 , V_33 ) ;
struct V_1 * V_34 ;
struct V_7 * V_18 ;
struct V_23 V_43 ;
struct V_44 * V_45 ;
char V_46 [ 16 ] ;
T_1 V_3 ;
T_1 V_47 ;
T_1 V_9 ;
int V_48 = - V_36 ;
if ( ! V_5 -> V_49 ) {
F_19 ( L_4 ,
V_8 ) ;
return - V_50 ;
}
if ( ! F_7 ( V_8 , & V_43 ) ) {
F_19 ( L_5 , V_8 ) ;
return - V_36 ;
}
if ( F_20 ( V_39 ) &&
( V_39 != V_5 -> V_49 ) ) {
if ( F_21 ( V_39 , V_5 -> V_49 ) ) {
V_39 = V_5 -> V_49 & V_51 ;
V_48 = 0 ;
} else if ( F_22 ( V_2 , V_39 ) )
V_48 = 0 ;
}
if ( V_48 ) {
F_19 ( L_6 ,
V_8 ) ;
return - V_36 ;
}
if ( ( V_40 > V_52 ) &&
( V_40 != V_53 ) ) {
F_19 ( L_7 , V_8 ) ;
return - V_36 ;
}
V_18 = F_3 ( V_43 . V_27 ) ;
if ( ! V_18 ) {
F_19 ( L_8 ,
V_8 , V_43 . V_27 ) ;
return - V_36 ;
}
if ( V_40 == V_53 )
V_40 = V_18 -> V_40 ;
V_54:
V_3 = V_35 ;
V_47 = 1 ;
for ( V_9 = V_35 ; V_9 -- != 0 ; ) {
V_34 = F_10 ( V_5 -> V_6 [ V_9 ] ) ;
if ( ! V_34 ) {
V_3 = V_9 ;
continue;
}
if ( ! strcmp ( V_8 , V_34 -> V_8 ) ) {
F_19 ( L_9 ,
V_8 ) ;
return - V_36 ;
}
if ( ( V_34 -> V_40 == V_40 ) &&
( ++ V_47 > 2 ) ) {
if ( V_40 -- == 0 ) {
F_19 ( L_10 ,
V_8 ) ;
return - V_36 ;
}
F_19 ( L_11 ,
V_8 , V_40 + 1 , V_40 ) ;
goto V_54;
}
}
if ( V_3 >= V_35 ) {
F_19 ( L_12 ,
V_8 , V_35 ) ;
return - V_36 ;
}
V_34 = F_23 ( sizeof( * V_34 ) , V_55 ) ;
if ( ! V_34 )
return - V_56 ;
strcpy ( V_34 -> V_8 , V_8 ) ;
V_34 -> V_57 = V_18 ;
V_48 = V_18 -> V_58 ( V_2 , V_34 , V_42 ) ;
if ( V_48 ) {
F_19 ( L_13 ,
V_8 , - V_48 ) ;
return - V_36 ;
}
V_34 -> V_59 = V_3 ;
V_34 -> V_60 = V_18 -> V_60 ;
V_34 -> V_61 = V_18 -> V_61 ;
V_34 -> V_62 = V_39 ;
V_34 -> V_63 = V_3 + 'A' ;
V_34 -> V_40 = V_40 ;
F_24 ( 0 , & V_34 -> V_64 ) ;
V_48 = F_25 ( V_2 , V_34 , & V_34 -> V_65 , & V_45 ) ;
if ( V_48 ) {
F_26 ( V_2 , V_34 ) ;
F_19 ( L_14 ,
V_8 ) ;
return - V_36 ;
}
F_27 ( V_5 -> V_6 [ V_3 ] , V_34 ) ;
if ( V_45 )
F_28 ( V_2 , V_3 , V_45 , & V_34 -> V_65 ) ;
if ( F_29 ( V_2 , V_3 ) )
return - V_56 ;
F_30 ( L_15 ,
V_8 ,
F_31 ( V_46 , V_39 ) , V_40 ) ;
return V_48 ;
}
static int F_32 ( struct V_2 * V_2 , struct V_1 * V_34 )
{
F_30 ( L_16 , V_34 -> V_8 ) ;
F_33 ( V_2 , V_34 -> V_59 ) ;
F_34 ( V_2 , V_34 ) ;
return 0 ;
}
static void F_26 ( struct V_2 * V_2 , struct V_1 * V_34 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
int V_3 = V_34 -> V_59 ;
F_30 ( L_17 , V_34 -> V_8 ) ;
F_35 ( 0 , & V_34 -> V_64 ) ;
F_33 ( V_2 , V_3 ) ;
V_34 -> V_57 -> V_66 ( V_34 ) ;
F_36 ( V_34 -> V_67 , NULL ) ;
if ( V_34 -> V_38 )
F_37 ( V_34 -> V_38 ) ;
F_36 ( V_5 -> V_6 [ V_3 ] , NULL ) ;
F_38 ( V_34 , V_68 ) ;
F_39 ( V_2 , V_3 ) ;
}
int F_40 ( struct V_2 * V_2 , struct V_1 * V_34 ,
struct V_41 * V_42 [] )
{
struct V_69 * V_70 ;
char * V_71 = strchr ( ( const char * ) V_34 -> V_8 , ':' ) + 1 ;
V_70 = F_41 ( V_2 , V_71 ) ;
if ( ! V_70 )
return - V_72 ;
if ( F_42 ( V_70 , 0 ) ) {
F_43 ( V_70 ) ;
return - V_36 ;
}
F_27 ( V_34 -> V_67 , V_70 ) ;
V_34 -> V_73 . V_70 = V_70 ;
V_34 -> V_73 . type = F_44 ( V_74 ) ;
V_34 -> V_73 . V_75 = V_76 ;
F_45 ( & V_34 -> V_73 ) ;
memset ( & V_34 -> V_65 , 0 , sizeof( V_34 -> V_65 ) ) ;
memcpy ( V_34 -> V_65 . V_22 , V_70 -> V_77 , V_34 -> V_57 -> V_78 ) ;
V_34 -> V_65 . V_20 = V_34 -> V_57 -> V_11 ;
V_34 -> V_65 . V_77 = V_79 ;
V_34 -> V_80 = V_70 -> V_80 ;
V_34 -> V_57 -> V_81 ( V_34 , & V_34 -> V_82 , ( char * ) V_70 -> V_83 ) ;
F_27 ( V_70 -> V_84 , V_34 ) ;
return 0 ;
}
void F_46 ( struct V_1 * V_34 )
{
struct V_69 * V_70 ;
V_70 = (struct V_69 * ) F_10 ( V_34 -> V_67 ) ;
F_47 ( & V_34 -> V_73 ) ;
F_36 ( V_70 -> V_84 , NULL ) ;
F_48 () ;
F_43 ( V_70 ) ;
}
int F_49 ( struct V_2 * V_2 , struct V_44 * V_45 ,
struct V_1 * V_34 , struct V_14 * V_37 )
{
struct V_69 * V_70 ;
int V_85 ;
V_70 = (struct V_69 * ) F_2 ( V_34 -> V_67 ) ;
if ( ! V_70 )
return 0 ;
V_85 = F_50 ( V_70 -> V_86 - F_51 ( V_45 ) ) ;
if ( ( V_85 > 0 ) && F_52 ( V_45 , V_85 , 0 , V_55 ) ) {
F_53 ( V_45 ) ;
return 0 ;
}
F_54 ( V_45 ) ;
V_45 -> V_70 = V_70 ;
V_45 -> V_87 = F_44 ( V_74 ) ;
F_55 ( V_45 , V_70 , V_74 , V_37 -> V_22 ,
V_70 -> V_83 , V_45 -> V_13 ) ;
F_56 ( V_45 ) ;
return 0 ;
}
bool F_57 ( struct V_2 * V_2 , T_1 V_3 )
{
bool V_88 = false ;
struct V_1 * V_34 ;
F_13 () ;
V_34 = F_1 ( V_2 , V_3 ) ;
if ( V_34 )
V_88 = ( V_34 -> V_65 . V_77 == V_79 ) ;
F_15 () ;
return V_88 ;
}
int F_58 ( struct V_2 * V_2 , T_1 V_3 )
{
int V_80 = 0 ;
struct V_1 * V_34 ;
F_13 () ;
V_34 = F_2 ( V_4 ( V_2 ) -> V_6 [ V_3 ] ) ;
if ( V_34 )
V_80 = V_34 -> V_80 ;
F_15 () ;
return V_80 ;
}
void F_28 ( struct V_2 * V_2 , T_1 V_3 ,
struct V_44 * V_45 ,
struct V_14 * V_37 )
{
struct V_89 * V_90 = F_59 ( V_45 ) ;
struct V_1 * V_34 ;
F_13 () ;
V_34 = F_1 ( V_2 , V_3 ) ;
if ( F_60 ( V_34 && ( F_61 ( 0 , & V_34 -> V_64 ) || F_62 ( V_90 ) ) ) )
V_34 -> V_57 -> V_91 ( V_2 , V_45 , V_34 , V_37 ) ;
else
F_53 ( V_45 ) ;
F_15 () ;
}
void F_63 ( struct V_2 * V_2 , T_1 V_3 ,
struct V_92 * V_93 ,
struct V_14 * V_94 )
{
struct V_1 * V_34 ;
struct V_44 * V_45 , * V_95 ;
if ( F_64 ( V_93 ) )
return;
F_13 () ;
V_34 = F_1 ( V_2 , V_3 ) ;
if ( F_65 ( ! V_34 ) )
F_66 ( V_93 ) ;
F_67 (xmitq, skb, tmp) {
F_68 ( V_93 ) ;
if ( F_60 ( F_61 ( 0 , & V_34 -> V_64 ) || F_62 ( F_59 ( V_45 ) ) ) )
V_34 -> V_57 -> V_91 ( V_2 , V_45 , V_34 , V_94 ) ;
else
F_53 ( V_45 ) ;
}
F_15 () ;
}
void F_69 ( struct V_2 * V_2 , T_1 V_3 ,
struct V_92 * V_93 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
int V_96 = V_5 -> V_96 ;
struct V_1 * V_34 ;
struct V_44 * V_45 , * V_95 ;
struct V_89 * V_90 ;
F_13 () ;
V_34 = F_1 ( V_2 , V_3 ) ;
if ( F_65 ( ! V_34 || ! F_61 ( 0 , & V_34 -> V_64 ) ) )
F_66 ( V_93 ) ;
F_67 (xmitq, skb, tmp) {
V_90 = F_59 ( V_45 ) ;
F_70 ( V_90 , 1 ) ;
F_71 ( V_90 , V_96 ) ;
F_68 ( V_93 ) ;
V_34 -> V_57 -> V_91 ( V_2 , V_45 , V_34 , & V_34 -> V_65 ) ;
}
F_15 () ;
}
static int V_76 ( struct V_44 * V_45 , struct V_69 * V_70 ,
struct V_97 * V_73 , struct V_69 * V_98 )
{
struct V_1 * V_34 ;
F_13 () ;
V_34 = F_2 ( V_70 -> V_84 ) ? :
F_2 ( V_98 -> V_84 ) ;
if ( F_60 ( V_34 && F_61 ( 0 , & V_34 -> V_64 ) &&
( V_45 -> V_99 <= V_100 ) ) ) {
V_45 -> V_101 = NULL ;
F_72 ( F_73 ( V_34 -> V_73 . V_70 ) , V_45 , V_34 ) ;
F_15 () ;
return V_102 ;
}
F_15 () ;
F_53 ( V_45 ) ;
return V_103 ;
}
static int F_74 ( struct V_104 * V_105 , unsigned long V_106 ,
void * V_107 )
{
struct V_69 * V_70 = F_75 ( V_107 ) ;
struct V_2 * V_2 = F_73 ( V_70 ) ;
struct V_1 * V_34 ;
V_34 = F_10 ( V_70 -> V_84 ) ;
if ( ! V_34 )
return V_108 ;
switch ( V_106 ) {
case V_109 :
if ( F_76 ( V_70 ) )
break;
case V_110 :
F_24 ( 0 , & V_34 -> V_64 ) ;
break;
case V_111 :
F_35 ( 0 , & V_34 -> V_64 ) ;
F_32 ( V_2 , V_34 ) ;
break;
case V_112 :
if ( F_42 ( V_70 , 0 ) ) {
F_26 ( V_2 , V_34 ) ;
break;
}
V_34 -> V_80 = V_70 -> V_80 ;
F_32 ( V_2 , V_34 ) ;
break;
case V_113 :
V_34 -> V_57 -> V_81 ( V_34 , & V_34 -> V_82 ,
( char * ) V_70 -> V_83 ) ;
F_32 ( V_2 , V_34 ) ;
break;
case V_114 :
case V_115 :
F_26 ( V_2 , V_34 ) ;
break;
}
return V_116 ;
}
int F_77 ( void )
{
return F_78 ( & V_117 ) ;
}
void F_79 ( void )
{
F_80 ( & V_117 ) ;
}
void F_81 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = F_9 ( V_2 , V_33 ) ;
struct V_1 * V_34 ;
T_1 V_9 ;
for ( V_9 = 0 ; V_9 < V_35 ; V_9 ++ ) {
V_34 = F_10 ( V_5 -> V_6 [ V_9 ] ) ;
if ( V_34 ) {
F_26 ( V_2 , V_34 ) ;
V_5 -> V_6 [ V_9 ] = NULL ;
}
}
}
static int F_82 ( struct V_118 * V_119 ,
struct V_1 * V_120 , int V_121 )
{
void * V_90 ;
struct V_41 * V_122 ;
struct V_41 * V_123 ;
V_90 = F_83 ( V_119 -> V_45 , V_119 -> V_124 , V_119 -> V_125 , & V_126 ,
V_121 , V_127 ) ;
if ( ! V_90 )
return - V_128 ;
V_122 = F_84 ( V_119 -> V_45 , V_129 ) ;
if ( ! V_122 )
goto V_130;
if ( F_85 ( V_119 -> V_45 , V_131 , V_120 -> V_8 ) )
goto V_132;
V_123 = F_84 ( V_119 -> V_45 , V_133 ) ;
if ( ! V_123 )
goto V_134;
if ( F_86 ( V_119 -> V_45 , V_135 , V_120 -> V_40 ) )
goto V_134;
if ( F_86 ( V_119 -> V_45 , V_136 , V_120 -> V_60 ) )
goto V_134;
if ( F_86 ( V_119 -> V_45 , V_137 , V_120 -> V_61 ) )
goto V_134;
F_87 ( V_119 -> V_45 , V_123 ) ;
#ifdef F_88
if ( V_120 -> V_57 -> V_11 == V_138 ) {
if ( F_89 ( V_119 , V_120 ) )
goto V_132;
}
#endif
F_87 ( V_119 -> V_45 , V_122 ) ;
F_90 ( V_119 -> V_45 , V_90 ) ;
return 0 ;
V_134:
F_91 ( V_119 -> V_45 , V_123 ) ;
V_132:
F_91 ( V_119 -> V_45 , V_122 ) ;
V_130:
F_92 ( V_119 -> V_45 , V_90 ) ;
return - V_128 ;
}
int F_93 ( struct V_44 * V_45 , struct V_139 * V_140 )
{
int V_141 ;
int V_9 = V_140 -> args [ 0 ] ;
struct V_1 * V_120 ;
struct V_118 V_119 ;
struct V_2 * V_2 = F_94 ( V_45 -> V_142 ) ;
struct V_4 * V_5 = F_9 ( V_2 , V_33 ) ;
if ( V_9 == V_35 )
return 0 ;
V_119 . V_45 = V_45 ;
V_119 . V_124 = F_95 ( V_140 -> V_45 ) . V_124 ;
V_119 . V_125 = V_140 -> V_143 -> V_144 ;
F_96 () ;
for ( V_9 = 0 ; V_9 < V_35 ; V_9 ++ ) {
V_120 = F_10 ( V_5 -> V_6 [ V_9 ] ) ;
if ( ! V_120 )
continue;
V_141 = F_82 ( & V_119 , V_120 , V_145 ) ;
if ( V_141 )
break;
}
F_97 () ;
V_140 -> args [ 0 ] = V_9 ;
return V_45 -> V_13 ;
}
int F_98 ( struct V_44 * V_45 , struct V_146 * V_147 )
{
int V_141 ;
char * V_8 ;
struct V_44 * V_148 ;
struct V_1 * V_120 ;
struct V_118 V_119 ;
struct V_41 * V_122 [ V_149 + 1 ] ;
struct V_2 * V_2 = F_99 ( V_147 ) ;
if ( ! V_147 -> V_122 [ V_129 ] )
return - V_36 ;
V_141 = F_100 ( V_122 , V_149 ,
V_147 -> V_122 [ V_129 ] ,
V_150 , V_147 -> V_151 ) ;
if ( V_141 )
return V_141 ;
if ( ! V_122 [ V_131 ] )
return - V_36 ;
V_8 = F_101 ( V_122 [ V_131 ] ) ;
V_148 = F_102 ( V_152 , V_153 ) ;
if ( ! V_148 )
return - V_56 ;
V_119 . V_45 = V_148 ;
V_119 . V_124 = V_147 -> V_154 ;
V_119 . V_125 = V_147 -> V_155 ;
F_96 () ;
V_120 = F_8 ( V_2 , V_8 ) ;
if ( ! V_120 ) {
V_141 = - V_36 ;
goto V_156;
}
V_141 = F_82 ( & V_119 , V_120 , 0 ) ;
if ( V_141 )
goto V_156;
F_97 () ;
return F_103 ( V_148 , V_147 ) ;
V_156:
F_97 () ;
F_104 ( V_148 ) ;
return V_141 ;
}
int F_105 ( struct V_44 * V_45 , struct V_146 * V_147 )
{
int V_141 ;
char * V_8 ;
struct V_1 * V_120 ;
struct V_41 * V_122 [ V_149 + 1 ] ;
struct V_2 * V_2 = F_94 ( V_45 -> V_142 ) ;
if ( ! V_147 -> V_122 [ V_129 ] )
return - V_36 ;
V_141 = F_100 ( V_122 , V_149 ,
V_147 -> V_122 [ V_129 ] ,
V_150 , V_147 -> V_151 ) ;
if ( V_141 )
return V_141 ;
if ( ! V_122 [ V_131 ] )
return - V_36 ;
V_8 = F_101 ( V_122 [ V_131 ] ) ;
F_96 () ;
V_120 = F_8 ( V_2 , V_8 ) ;
if ( ! V_120 ) {
F_97 () ;
return - V_36 ;
}
F_26 ( V_2 , V_120 ) ;
F_97 () ;
return 0 ;
}
int F_106 ( struct V_44 * V_45 , struct V_146 * V_147 )
{
int V_141 ;
char * V_120 ;
struct V_41 * V_122 [ V_149 + 1 ] ;
struct V_2 * V_2 = F_94 ( V_45 -> V_142 ) ;
struct V_4 * V_5 = F_9 ( V_2 , V_33 ) ;
T_1 V_62 ;
T_1 V_157 ;
V_157 = V_53 ;
V_62 = V_5 -> V_49 & V_51 ;
if ( ! V_147 -> V_122 [ V_129 ] )
return - V_36 ;
V_141 = F_100 ( V_122 , V_149 ,
V_147 -> V_122 [ V_129 ] ,
V_150 , V_147 -> V_151 ) ;
if ( V_141 )
return V_141 ;
if ( ! V_122 [ V_131 ] )
return - V_36 ;
V_120 = F_101 ( V_122 [ V_131 ] ) ;
if ( V_122 [ V_158 ] )
V_62 = F_107 ( V_122 [ V_158 ] ) ;
if ( V_122 [ V_133 ] ) {
struct V_41 * V_159 [ V_160 + 1 ] ;
V_141 = F_108 ( V_122 [ V_133 ] ,
V_159 ) ;
if ( V_141 )
return V_141 ;
if ( V_159 [ V_135 ] )
V_157 = F_107 ( V_159 [ V_135 ] ) ;
}
F_96 () ;
V_141 = F_18 ( V_2 , V_120 , V_62 , V_157 , V_122 ) ;
if ( V_141 ) {
F_97 () ;
return V_141 ;
}
F_97 () ;
return 0 ;
}
int F_109 ( struct V_44 * V_45 , struct V_146 * V_147 )
{
int V_141 ;
char * V_8 ;
struct V_1 * V_34 ;
struct V_41 * V_122 [ V_149 + 1 ] ;
struct V_2 * V_2 = F_94 ( V_45 -> V_142 ) ;
if ( ! V_147 -> V_122 [ V_129 ] )
return - V_36 ;
V_141 = F_100 ( V_122 , V_149 ,
V_147 -> V_122 [ V_129 ] ,
V_150 , V_147 -> V_151 ) ;
if ( V_141 )
return V_141 ;
if ( ! V_122 [ V_131 ] )
return - V_36 ;
V_8 = F_101 ( V_122 [ V_131 ] ) ;
F_96 () ;
V_34 = F_8 ( V_2 , V_8 ) ;
if ( ! V_34 ) {
F_97 () ;
return - V_36 ;
}
#ifdef F_88
if ( V_122 [ V_161 ] ) {
V_141 = F_110 ( V_34 ,
V_122 [ V_161 ] ) ;
if ( V_141 ) {
F_97 () ;
return V_141 ;
}
}
#endif
F_97 () ;
return 0 ;
}
int F_111 ( struct V_44 * V_45 , struct V_146 * V_147 )
{
int V_141 ;
char * V_8 ;
struct V_1 * V_34 ;
struct V_41 * V_122 [ V_149 + 1 ] ;
struct V_2 * V_2 = F_94 ( V_45 -> V_142 ) ;
if ( ! V_147 -> V_122 [ V_129 ] )
return - V_36 ;
V_141 = F_100 ( V_122 , V_149 ,
V_147 -> V_122 [ V_129 ] ,
V_150 , V_147 -> V_151 ) ;
if ( V_141 )
return V_141 ;
if ( ! V_122 [ V_131 ] )
return - V_36 ;
V_8 = F_101 ( V_122 [ V_131 ] ) ;
F_96 () ;
V_34 = F_8 ( V_2 , V_8 ) ;
if ( ! V_34 ) {
F_97 () ;
return - V_36 ;
}
if ( V_122 [ V_133 ] ) {
struct V_41 * V_159 [ V_160 + 1 ] ;
V_141 = F_108 ( V_122 [ V_133 ] ,
V_159 ) ;
if ( V_141 ) {
F_97 () ;
return V_141 ;
}
if ( V_159 [ V_136 ] )
V_34 -> V_60 = F_107 ( V_159 [ V_136 ] ) ;
if ( V_159 [ V_135 ] )
V_34 -> V_40 = F_107 ( V_159 [ V_135 ] ) ;
if ( V_159 [ V_137 ] )
V_34 -> V_61 = F_107 ( V_159 [ V_137 ] ) ;
}
F_97 () ;
return 0 ;
}
static int F_112 ( struct V_118 * V_119 ,
struct V_7 * V_57 , int V_121 )
{
void * V_90 ;
struct V_41 * V_122 ;
struct V_41 * V_123 ;
V_90 = F_83 ( V_119 -> V_45 , V_119 -> V_124 , V_119 -> V_125 , & V_126 ,
V_121 , V_162 ) ;
if ( ! V_90 )
return - V_128 ;
V_122 = F_84 ( V_119 -> V_45 , V_163 ) ;
if ( ! V_122 )
goto V_130;
if ( F_85 ( V_119 -> V_45 , V_164 , V_57 -> V_8 ) )
goto V_132;
V_123 = F_84 ( V_119 -> V_45 , V_165 ) ;
if ( ! V_123 )
goto V_134;
if ( F_86 ( V_119 -> V_45 , V_135 , V_57 -> V_40 ) )
goto V_134;
if ( F_86 ( V_119 -> V_45 , V_136 , V_57 -> V_60 ) )
goto V_134;
if ( F_86 ( V_119 -> V_45 , V_137 , V_57 -> V_61 ) )
goto V_134;
F_87 ( V_119 -> V_45 , V_123 ) ;
F_87 ( V_119 -> V_45 , V_122 ) ;
F_90 ( V_119 -> V_45 , V_90 ) ;
return 0 ;
V_134:
F_91 ( V_119 -> V_45 , V_123 ) ;
V_132:
F_91 ( V_119 -> V_45 , V_122 ) ;
V_130:
F_92 ( V_119 -> V_45 , V_90 ) ;
return - V_128 ;
}
int F_113 ( struct V_44 * V_45 , struct V_139 * V_140 )
{
int V_141 ;
int V_9 = V_140 -> args [ 0 ] ;
struct V_118 V_119 ;
if ( V_9 == V_166 )
return 0 ;
V_119 . V_45 = V_45 ;
V_119 . V_124 = F_95 ( V_140 -> V_45 ) . V_124 ;
V_119 . V_125 = V_140 -> V_143 -> V_144 ;
F_96 () ;
for (; V_10 [ V_9 ] != NULL ; V_9 ++ ) {
V_141 = F_112 ( & V_119 , V_10 [ V_9 ] ,
V_145 ) ;
if ( V_141 )
break;
}
F_97 () ;
V_140 -> args [ 0 ] = V_9 ;
return V_45 -> V_13 ;
}
int F_114 ( struct V_44 * V_45 , struct V_146 * V_147 )
{
int V_141 ;
char * V_8 ;
struct V_118 V_119 ;
struct V_7 * V_57 ;
struct V_44 * V_148 ;
struct V_41 * V_122 [ V_149 + 1 ] ;
if ( ! V_147 -> V_122 [ V_163 ] )
return - V_36 ;
V_141 = F_100 ( V_122 , V_167 ,
V_147 -> V_122 [ V_163 ] ,
V_168 , V_147 -> V_151 ) ;
if ( V_141 )
return V_141 ;
if ( ! V_122 [ V_164 ] )
return - V_36 ;
V_8 = F_101 ( V_122 [ V_164 ] ) ;
V_148 = F_102 ( V_152 , V_153 ) ;
if ( ! V_148 )
return - V_56 ;
V_119 . V_45 = V_148 ;
V_119 . V_124 = V_147 -> V_154 ;
V_119 . V_125 = V_147 -> V_155 ;
F_96 () ;
V_57 = F_3 ( V_8 ) ;
if ( ! V_57 ) {
V_141 = - V_36 ;
goto V_156;
}
V_141 = F_112 ( & V_119 , V_57 , 0 ) ;
if ( V_141 )
goto V_156;
F_97 () ;
return F_103 ( V_148 , V_147 ) ;
V_156:
F_97 () ;
F_104 ( V_148 ) ;
return V_141 ;
}
int F_115 ( struct V_44 * V_45 , struct V_146 * V_147 )
{
int V_141 ;
char * V_8 ;
struct V_7 * V_18 ;
struct V_41 * V_122 [ V_149 + 1 ] ;
if ( ! V_147 -> V_122 [ V_163 ] )
return - V_36 ;
V_141 = F_100 ( V_122 , V_167 ,
V_147 -> V_122 [ V_163 ] ,
V_168 , V_147 -> V_151 ) ;
if ( ! V_122 [ V_164 ] )
return - V_36 ;
V_8 = F_101 ( V_122 [ V_164 ] ) ;
F_96 () ;
V_18 = F_3 ( V_8 ) ;
if ( ! V_18 ) {
F_97 () ;
return - V_36 ;
}
if ( V_122 [ V_165 ] ) {
struct V_41 * V_159 [ V_160 + 1 ] ;
V_141 = F_108 ( V_122 [ V_165 ] ,
V_159 ) ;
if ( V_141 ) {
F_97 () ;
return V_141 ;
}
if ( V_159 [ V_136 ] )
V_18 -> V_60 = F_107 ( V_159 [ V_136 ] ) ;
if ( V_159 [ V_135 ] )
V_18 -> V_40 = F_107 ( V_159 [ V_135 ] ) ;
if ( V_159 [ V_137 ] )
V_18 -> V_61 = F_107 ( V_159 [ V_137 ] ) ;
}
F_97 () ;
return 0 ;
}
