void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 , & V_5 ) ;
F_4 ( & V_3 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_6 ( & V_2 -> V_4 ) ;
F_4 ( & V_3 ) ;
}
static struct V_1 *
F_7 ( struct V_6 * V_7 , int V_8 , char * * V_9 )
{
struct V_1 * V_10 ;
struct V_11 * V_4 ;
char * V_12 ;
V_10 = NULL ;
V_12 = NULL ;
F_2 ( & V_3 ) ;
F_8 (list, &dsa_switch_drivers) {
struct V_1 * V_2 ;
V_2 = F_9 ( V_4 , struct V_1 , V_4 ) ;
V_12 = V_2 -> V_13 ( V_7 , V_8 ) ;
if ( V_12 != NULL ) {
V_10 = V_2 ;
break;
}
}
F_4 ( & V_3 ) ;
* V_9 = V_12 ;
return V_10 ;
}
static T_1 F_10 ( struct V_6 * V_14 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_18 * V_19 = F_11 ( V_14 ) ;
int V_20 , V_10 ;
V_10 = V_19 -> V_2 -> V_21 ( V_19 , & V_20 ) ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_17 , L_1 , V_20 * 1000 ) ;
}
static T_1 F_12 ( struct V_6 * V_14 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_18 * V_19 = F_11 ( V_14 ) ;
int V_20 , V_10 ;
V_10 = V_19 -> V_2 -> V_22 ( V_19 , & V_20 ) ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_17 , L_1 , V_20 * 1000 ) ;
}
static T_1 F_13 ( struct V_6 * V_14 ,
struct V_15 * V_16 , const char * V_17 ,
T_2 V_23 )
{
struct V_18 * V_19 = F_11 ( V_14 ) ;
int V_20 , V_10 ;
V_10 = F_14 ( V_17 , 0 , & V_20 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = V_19 -> V_2 -> V_24 ( V_19 , F_15 ( V_20 , 1000 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return V_23 ;
}
static T_1 F_16 ( struct V_6 * V_14 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_18 * V_19 = F_11 ( V_14 ) ;
bool V_25 ;
int V_10 ;
V_10 = V_19 -> V_2 -> V_26 ( V_19 , & V_25 ) ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_17 , L_1 , V_25 ) ;
}
static T_3 F_17 ( struct V_27 * V_28 ,
struct V_29 * V_16 , int V_30 )
{
struct V_6 * V_14 = F_18 ( V_28 , struct V_6 , V_28 ) ;
struct V_18 * V_19 = F_11 ( V_14 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
T_3 V_31 = V_16 -> V_31 ;
if ( V_30 == 1 ) {
if ( ! V_2 -> V_22 )
V_31 = 0 ;
else if ( V_2 -> V_24 )
V_31 |= V_32 ;
} else if ( V_30 == 2 && ! V_2 -> V_26 ) {
V_31 = 0 ;
}
return V_31 ;
}
static struct V_18 *
F_19 ( struct V_33 * V_34 , int V_30 ,
struct V_6 * V_35 , struct V_6 * V_7 )
{
struct V_36 * V_37 = V_34 -> V_37 -> V_38 + V_30 ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
int V_10 ;
char * V_12 ;
int V_39 ;
bool V_40 = false ;
V_2 = F_7 ( V_7 , V_37 -> V_8 , & V_12 ) ;
if ( V_2 == NULL ) {
F_20 ( V_34 -> V_41 , L_2 ,
V_30 ) ;
return F_21 ( - V_42 ) ;
}
F_22 ( V_34 -> V_41 , L_3 ,
V_30 , V_12 ) ;
V_19 = F_23 ( sizeof( * V_19 ) + V_2 -> V_43 , V_44 ) ;
if ( V_19 == NULL )
return F_21 ( - V_45 ) ;
V_19 -> V_34 = V_34 ;
V_19 -> V_30 = V_30 ;
V_19 -> V_37 = V_34 -> V_37 -> V_38 + V_30 ;
V_19 -> V_2 = V_2 ;
V_19 -> V_46 = V_7 ;
for ( V_39 = 0 ; V_39 < V_47 ; V_39 ++ ) {
char * V_12 ;
V_12 = V_37 -> V_48 [ V_39 ] ;
if ( V_12 == NULL )
continue;
if ( ! strcmp ( V_12 , L_4 ) ) {
if ( V_34 -> V_49 != - 1 ) {
F_20 ( V_34 -> V_41 ,
L_5 ) ;
V_10 = - V_42 ;
goto V_50;
}
V_34 -> V_49 = V_30 ;
V_34 -> V_51 = V_39 ;
} else if ( ! strcmp ( V_12 , L_6 ) ) {
V_19 -> V_52 |= 1 << V_39 ;
} else {
V_19 -> V_53 |= 1 << V_39 ;
}
V_40 = true ;
}
if ( ! V_40 && V_39 == V_47 ) {
V_10 = - V_42 ;
goto V_50;
}
V_19 -> V_54 = V_19 -> V_53 ;
if ( V_34 -> V_49 == V_30 ) {
switch ( V_2 -> V_55 ) {
#ifdef F_24
case V_56 :
V_34 -> V_57 = V_58 . V_57 ;
break;
#endif
#ifdef F_25
case V_59 :
V_34 -> V_57 = V_60 . V_57 ;
break;
#endif
#ifdef F_26
case V_61 :
V_34 -> V_57 = V_62 . V_57 ;
break;
#endif
#ifdef F_27
case V_63 :
V_34 -> V_57 = V_64 . V_57 ;
break;
#endif
case V_65 :
break;
default:
V_10 = - V_66 ;
goto V_50;
}
V_34 -> V_55 = V_2 -> V_55 ;
}
V_10 = V_2 -> V_67 ( V_19 ) ;
if ( V_10 < 0 )
goto V_50;
V_10 = V_2 -> V_68 ( V_19 , V_34 -> V_41 -> V_69 ) ;
if ( V_10 < 0 )
goto V_50;
V_19 -> V_70 = F_28 () ;
if ( V_19 -> V_70 == NULL ) {
V_10 = - V_45 ;
goto V_50;
}
F_29 ( V_19 ) ;
V_10 = F_30 ( V_19 -> V_70 ) ;
if ( V_10 < 0 )
goto V_71;
for ( V_39 = 0 ; V_39 < V_47 ; V_39 ++ ) {
struct V_72 * V_73 ;
if ( ! ( V_19 -> V_53 & ( 1 << V_39 ) ) )
continue;
V_73 = F_31 ( V_19 , V_35 , V_39 , V_37 -> V_48 [ V_39 ] ) ;
if ( V_73 == NULL ) {
F_20 ( V_34 -> V_41 , L_7 ,
V_30 , V_39 , V_37 -> V_48 [ V_39 ] ) ;
continue;
}
V_19 -> V_74 [ V_39 ] = V_73 ;
}
#ifdef F_32
if ( V_2 -> V_21 ) {
const char * V_75 = F_33 ( V_34 -> V_41 ) ;
char V_76 [ V_77 + 1 ] ;
int V_39 , V_78 ;
for ( V_39 = V_78 = 0 ; V_39 < V_77 && V_75 [ V_39 ] ; V_39 ++ ) {
if ( isalnum ( V_75 [ V_39 ] ) )
V_76 [ V_78 ++ ] = V_75 [ V_39 ] ;
}
V_76 [ V_78 ] = '\0' ;
F_34 ( V_19 -> V_79 , sizeof( V_19 -> V_79 ) , L_8 ,
V_76 , V_30 ) ;
V_19 -> V_80 = F_35 ( NULL ,
V_19 -> V_79 , V_19 , V_81 ) ;
if ( F_36 ( V_19 -> V_80 ) )
V_19 -> V_80 = NULL ;
}
#endif
return V_19 ;
V_71:
F_37 ( V_19 -> V_70 ) ;
V_50:
F_38 ( V_19 ) ;
return F_21 ( V_10 ) ;
}
static void F_39 ( struct V_18 * V_19 )
{
#ifdef F_32
if ( V_19 -> V_80 )
F_40 ( V_19 -> V_80 ) ;
#endif
}
static int F_41 ( struct V_18 * V_19 )
{
int V_39 , V_10 = 0 ;
for ( V_39 = 0 ; V_39 < V_47 ; V_39 ++ ) {
if ( ! ( V_19 -> V_53 & ( 1 << V_39 ) ) )
continue;
V_10 = F_42 ( V_19 -> V_74 [ V_39 ] ) ;
if ( V_10 )
return V_10 ;
}
if ( V_19 -> V_2 -> V_82 )
V_10 = V_19 -> V_2 -> V_82 ( V_19 ) ;
return V_10 ;
}
static int F_43 ( struct V_18 * V_19 )
{
int V_39 , V_10 = 0 ;
if ( V_19 -> V_2 -> V_83 )
V_10 = V_19 -> V_2 -> V_83 ( V_19 ) ;
if ( V_10 )
return V_10 ;
for ( V_39 = 0 ; V_39 < V_47 ; V_39 ++ ) {
if ( ! ( V_19 -> V_53 & ( 1 << V_39 ) ) )
continue;
V_10 = F_44 ( V_19 -> V_74 [ V_39 ] ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static void F_45 ( struct V_84 * V_85 )
{
struct V_33 * V_34 ;
int V_39 ;
V_34 = F_18 ( V_85 , struct V_33 , V_86 ) ;
for ( V_39 = 0 ; V_39 < V_34 -> V_37 -> V_87 ; V_39 ++ ) {
struct V_18 * V_19 = V_34 -> V_19 [ V_39 ] ;
if ( V_19 != NULL && V_19 -> V_2 -> V_88 != NULL )
V_19 -> V_2 -> V_88 ( V_19 ) ;
}
F_46 ( & V_34 -> V_89 , F_47 ( V_90 + V_91 ) ) ;
}
static void F_48 ( unsigned long V_92 )
{
struct V_33 * V_34 = ( void * ) V_92 ;
F_49 ( & V_34 -> V_86 ) ;
}
static int F_50 ( struct V_6 * V_14 , void * V_93 )
{
if ( V_14 -> V_93 != NULL && ! strcmp ( V_14 -> V_93 -> V_12 , V_93 ) )
return 1 ;
return 0 ;
}
static struct V_6 * F_51 ( struct V_6 * V_35 , char * V_93 )
{
if ( F_50 ( V_35 , V_93 ) ) {
F_52 ( V_35 ) ;
return V_35 ;
}
return F_53 ( V_35 , V_93 , F_50 ) ;
}
struct V_94 * F_54 ( struct V_6 * V_14 )
{
struct V_6 * V_95 ;
V_95 = F_51 ( V_14 , L_9 ) ;
if ( V_95 != NULL ) {
struct V_94 * V_96 ;
V_96 = F_55 ( V_95 ) ;
F_56 ( V_95 ) ;
return V_96 ;
}
return NULL ;
}
static struct V_72 * F_57 ( struct V_6 * V_14 )
{
struct V_6 * V_95 ;
V_95 = F_51 ( V_14 , L_10 ) ;
if ( V_95 != NULL ) {
struct V_72 * V_97 ;
V_97 = F_58 ( V_95 ) ;
F_59 ( V_97 ) ;
F_56 ( V_95 ) ;
return V_97 ;
}
return NULL ;
}
static int F_60 ( struct V_98 * V_37 ,
struct V_36 * V_99 ,
int V_100 ,
struct V_101 * V_102 )
{
int V_10 ;
const T_4 * V_103 ;
int V_104 ;
int V_105 ;
struct V_101 * V_106 ;
int V_107 ;
V_106 = F_61 ( V_102 ) ;
if ( ! V_106 )
return - V_42 ;
V_103 = F_62 ( V_106 , L_11 , & V_107 ) ;
if ( ! V_103 || ( V_107 != sizeof( * V_103 ) * 2 ) )
return - V_42 ;
V_105 = F_63 ( V_103 + 1 ) ;
if ( V_105 >= V_37 -> V_87 )
return - V_42 ;
if ( ! V_99 -> V_108 ) {
V_99 -> V_108 = F_64 ( V_37 -> V_87 , sizeof( V_109 ) ,
V_44 ) ;
if ( ! V_99 -> V_108 )
return - V_45 ;
memset ( V_99 -> V_108 , - 1 , V_37 -> V_87 * sizeof( V_109 ) ) ;
}
V_103 = F_62 ( V_102 , L_11 , NULL ) ;
if ( ! V_103 ) {
V_10 = - V_42 ;
goto V_50;
}
V_104 = F_63 ( V_103 ) ;
V_99 -> V_108 [ V_105 ] = V_104 ;
return 0 ;
V_50:
F_38 ( V_99 -> V_108 ) ;
return V_10 ;
}
static void F_65 ( struct V_98 * V_37 )
{
int V_39 ;
int V_110 ;
for ( V_39 = 0 ; V_39 < V_37 -> V_87 ; V_39 ++ ) {
V_110 = 0 ;
while ( V_110 < V_47 ) {
F_38 ( V_37 -> V_38 [ V_39 ] . V_48 [ V_110 ] ) ;
V_110 ++ ;
}
F_38 ( V_37 -> V_38 [ V_39 ] . V_108 ) ;
}
F_38 ( V_37 -> V_38 ) ;
}
static int F_66 ( struct V_111 * V_112 )
{
struct V_101 * V_113 = V_112 -> V_14 . V_114 ;
struct V_101 * V_115 , * V_116 , * V_117 , * V_118 , * V_102 ;
struct V_94 * V_119 ;
struct V_111 * V_120 ;
struct V_98 * V_37 ;
struct V_36 * V_99 ;
const char * V_121 ;
int V_100 , V_110 ;
const unsigned int * V_8 , * V_122 ;
T_5 V_123 ;
int V_10 ;
V_116 = F_67 ( V_113 , L_12 , 0 ) ;
if ( ! V_116 )
return - V_42 ;
V_119 = F_68 ( V_116 ) ;
if ( ! V_119 )
return - V_42 ;
V_117 = F_67 ( V_113 , L_13 , 0 ) ;
if ( ! V_117 )
return - V_42 ;
V_120 = F_69 ( V_117 ) ;
if ( ! V_120 )
return - V_124 ;
V_37 = F_23 ( sizeof( * V_37 ) , V_44 ) ;
if ( ! V_37 )
return - V_45 ;
V_112 -> V_14 . V_125 = V_37 ;
V_37 -> V_126 = & V_120 -> V_14 ;
V_37 -> V_87 = F_70 ( V_113 ) ;
if ( V_37 -> V_87 > V_127 )
V_37 -> V_87 = V_127 ;
V_37 -> V_38 = F_71 ( V_37 -> V_87 , sizeof( struct V_36 ) ,
V_44 ) ;
if ( ! V_37 -> V_38 ) {
V_10 = - V_45 ;
goto V_71;
}
V_100 = - 1 ;
F_72 (np, child) {
V_100 ++ ;
V_99 = & V_37 -> V_38 [ V_100 ] ;
V_99 -> V_114 = V_115 ;
V_99 -> V_7 = & V_119 -> V_14 ;
V_8 = F_62 ( V_115 , L_11 , NULL ) ;
if ( ! V_8 )
continue;
V_99 -> V_8 = F_63 ( V_8 ) ;
if ( V_99 -> V_8 > V_128 )
continue;
if ( ! F_73 ( V_113 , L_14 , & V_123 ) )
V_99 -> V_123 = V_123 ;
F_72 (child, port) {
V_122 = F_62 ( V_118 , L_11 , NULL ) ;
if ( ! V_122 )
continue;
V_110 = F_63 ( V_122 ) ;
V_121 = F_62 ( V_118 , L_15 , NULL ) ;
if ( ! V_121 )
continue;
V_99 -> V_129 [ V_110 ] = V_118 ;
V_99 -> V_48 [ V_110 ] = F_74 ( V_121 ,
V_44 ) ;
if ( ! V_99 -> V_48 [ V_110 ] ) {
V_10 = - V_45 ;
goto V_130;
}
V_102 = F_67 ( V_118 , L_16 , 0 ) ;
if ( ! strcmp ( V_121 , L_6 ) && V_102 &&
V_37 -> V_87 > 1 ) {
V_10 = F_60 ( V_37 , V_99 ,
V_100 , V_102 ) ;
if ( V_10 )
goto V_130;
}
if ( V_110 == V_47 )
break;
}
}
return 0 ;
V_130:
F_65 ( V_37 ) ;
V_71:
F_38 ( V_37 ) ;
V_112 -> V_14 . V_125 = NULL ;
return V_10 ;
}
static void F_75 ( struct V_111 * V_112 )
{
struct V_98 * V_37 = V_112 -> V_14 . V_125 ;
if ( ! V_112 -> V_14 . V_114 )
return;
F_65 ( V_37 ) ;
F_38 ( V_37 ) ;
}
static inline int F_66 ( struct V_111 * V_112 )
{
return 0 ;
}
static inline void F_75 ( struct V_111 * V_112 )
{
}
static int F_76 ( struct V_111 * V_112 )
{
struct V_98 * V_37 = V_112 -> V_14 . V_125 ;
struct V_72 * V_14 ;
struct V_33 * V_34 ;
int V_39 , V_10 ;
F_77 ( L_17 ,
V_131 ) ;
if ( V_112 -> V_14 . V_114 ) {
V_10 = F_66 ( V_112 ) ;
if ( V_10 )
return V_10 ;
V_37 = V_112 -> V_14 . V_125 ;
}
if ( V_37 == NULL || V_37 -> V_126 == NULL )
return - V_42 ;
V_14 = F_57 ( V_37 -> V_126 ) ;
if ( V_14 == NULL ) {
V_10 = - V_42 ;
goto V_50;
}
if ( V_14 -> V_132 != NULL ) {
F_78 ( V_14 ) ;
V_10 = - V_133 ;
goto V_50;
}
V_34 = F_23 ( sizeof( * V_34 ) , V_44 ) ;
if ( V_34 == NULL ) {
F_78 ( V_14 ) ;
V_10 = - V_45 ;
goto V_50;
}
F_79 ( V_112 , V_34 ) ;
V_34 -> V_37 = V_37 ;
V_34 -> V_41 = V_14 ;
V_34 -> V_49 = - 1 ;
V_34 -> V_51 = - 1 ;
for ( V_39 = 0 ; V_39 < V_37 -> V_87 ; V_39 ++ ) {
struct V_18 * V_19 ;
V_19 = F_19 ( V_34 , V_39 , & V_112 -> V_14 , V_37 -> V_38 [ V_39 ] . V_7 ) ;
if ( F_36 ( V_19 ) ) {
F_20 ( V_14 , L_18 ,
V_39 , F_80 ( V_19 ) ) ;
continue;
}
V_34 -> V_19 [ V_39 ] = V_19 ;
if ( V_19 -> V_2 -> V_88 != NULL )
V_34 -> V_134 = 1 ;
}
F_81 () ;
V_14 -> V_132 = ( void * ) V_34 ;
if ( V_34 -> V_134 ) {
F_82 ( & V_34 -> V_86 , F_45 ) ;
F_83 ( & V_34 -> V_89 ) ;
V_34 -> V_89 . V_135 = ( unsigned long ) V_34 ;
V_34 -> V_89 . V_136 = F_48 ;
V_34 -> V_89 . V_137 = F_47 ( V_90 + V_91 ) ;
F_84 ( & V_34 -> V_89 ) ;
}
return 0 ;
V_50:
F_75 ( V_112 ) ;
return V_10 ;
}
static int F_85 ( struct V_111 * V_112 )
{
struct V_33 * V_34 = F_86 ( V_112 ) ;
int V_39 ;
if ( V_34 -> V_134 )
F_87 ( & V_34 -> V_89 ) ;
F_88 ( & V_34 -> V_86 ) ;
for ( V_39 = 0 ; V_39 < V_34 -> V_37 -> V_87 ; V_39 ++ ) {
struct V_18 * V_19 = V_34 -> V_19 [ V_39 ] ;
if ( V_19 != NULL )
F_39 ( V_19 ) ;
}
F_75 ( V_112 ) ;
return 0 ;
}
static void F_89 ( struct V_111 * V_112 )
{
}
static int F_90 ( struct V_138 * V_139 , struct V_72 * V_14 ,
struct V_140 * V_141 , struct V_72 * V_142 )
{
struct V_33 * V_34 = V_14 -> V_132 ;
if ( F_91 ( V_34 == NULL ) ) {
F_92 ( V_139 ) ;
return 0 ;
}
return V_34 -> V_57 ( V_139 , V_14 , V_141 , V_142 ) ;
}
static int F_93 ( struct V_6 * V_95 )
{
struct V_111 * V_112 = F_94 ( V_95 ) ;
struct V_33 * V_34 = F_86 ( V_112 ) ;
int V_39 , V_10 = 0 ;
for ( V_39 = 0 ; V_39 < V_34 -> V_37 -> V_87 ; V_39 ++ ) {
struct V_18 * V_19 = V_34 -> V_19 [ V_39 ] ;
if ( V_19 != NULL )
V_10 = F_41 ( V_19 ) ;
}
return V_10 ;
}
static int F_95 ( struct V_6 * V_95 )
{
struct V_111 * V_112 = F_94 ( V_95 ) ;
struct V_33 * V_34 = F_86 ( V_112 ) ;
int V_39 , V_10 = 0 ;
for ( V_39 = 0 ; V_39 < V_34 -> V_37 -> V_87 ; V_39 ++ ) {
struct V_18 * V_19 = V_34 -> V_19 [ V_39 ] ;
if ( V_19 != NULL )
V_10 = F_43 ( V_19 ) ;
}
return V_10 ;
}
static int T_6 F_96 ( void )
{
int V_143 ;
V_143 = F_97 ( & V_144 ) ;
if ( V_143 )
return V_143 ;
F_98 ( & V_145 ) ;
return 0 ;
}
static void T_7 F_99 ( void )
{
F_100 ( & V_145 ) ;
F_101 ( & V_144 ) ;
}
