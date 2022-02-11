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
else if ( ! V_2 -> V_24 )
V_31 &= ~ V_32 ;
} else if ( V_30 == 2 && ! V_2 -> V_26 ) {
V_31 = 0 ;
}
return V_31 ;
}
static int F_19 ( struct V_18 * V_19 , struct V_6 * V_33 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_34 * V_35 = V_19 -> V_35 ;
struct V_36 * V_37 = V_19 -> V_37 ;
bool V_38 = false ;
int V_30 = V_19 -> V_30 ;
int V_39 , V_10 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
char * V_12 ;
V_12 = V_37 -> V_41 [ V_39 ] ;
if ( V_12 == NULL )
continue;
if ( ! strcmp ( V_12 , L_2 ) ) {
if ( V_35 -> V_42 != - 1 ) {
F_20 ( V_35 -> V_43 ,
L_3 ) ;
V_10 = - V_44 ;
goto V_45;
}
V_35 -> V_42 = V_30 ;
V_35 -> V_46 = V_39 ;
} else if ( ! strcmp ( V_12 , L_4 ) ) {
V_19 -> V_47 |= 1 << V_39 ;
} else {
V_19 -> V_48 |= 1 << V_39 ;
}
V_38 = true ;
}
if ( ! V_38 && V_39 == V_40 ) {
V_10 = - V_44 ;
goto V_45;
}
V_19 -> V_49 = V_19 -> V_48 ;
if ( V_35 -> V_42 == V_30 ) {
switch ( V_19 -> V_50 ) {
#ifdef F_21
case V_51 :
V_35 -> V_52 = V_53 . V_52 ;
break;
#endif
#ifdef F_22
case V_54 :
V_35 -> V_52 = V_55 . V_52 ;
break;
#endif
#ifdef F_23
case V_56 :
V_35 -> V_52 = V_57 . V_52 ;
break;
#endif
#ifdef F_24
case V_58 :
V_35 -> V_52 = V_59 . V_52 ;
break;
#endif
case V_60 :
break;
default:
V_10 = - V_61 ;
goto V_45;
}
V_35 -> V_50 = V_19 -> V_50 ;
}
V_10 = V_2 -> V_62 ( V_19 ) ;
if ( V_10 < 0 )
goto V_45;
V_10 = V_2 -> V_63 ( V_19 , V_35 -> V_43 -> V_64 ) ;
if ( V_10 < 0 )
goto V_45;
V_19 -> V_65 = F_25 () ;
if ( V_19 -> V_65 == NULL ) {
V_10 = - V_66 ;
goto V_45;
}
F_26 ( V_19 ) ;
V_10 = F_27 ( V_19 -> V_65 ) ;
if ( V_10 < 0 )
goto V_67;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
if ( ! ( V_19 -> V_48 & ( 1 << V_39 ) ) )
continue;
V_10 = F_28 ( V_19 , V_33 , V_39 , V_37 -> V_41 [ V_39 ] ) ;
if ( V_10 < 0 ) {
F_20 ( V_35 -> V_43 , L_5 ,
V_30 , V_39 , V_37 -> V_41 [ V_39 ] ) ;
V_10 = 0 ;
}
}
#ifdef F_29
if ( V_2 -> V_21 ) {
const char * V_68 = F_30 ( V_35 -> V_43 ) ;
char V_69 [ V_70 + 1 ] ;
int V_39 , V_71 ;
for ( V_39 = V_71 = 0 ; V_39 < V_70 && V_68 [ V_39 ] ; V_39 ++ ) {
if ( isalnum ( V_68 [ V_39 ] ) )
V_69 [ V_71 ++ ] = V_68 [ V_39 ] ;
}
V_69 [ V_71 ] = '\0' ;
F_31 ( V_19 -> V_72 , sizeof( V_19 -> V_72 ) , L_6 ,
V_69 , V_30 ) ;
V_19 -> V_73 = F_32 ( NULL ,
V_19 -> V_72 , V_19 , V_74 ) ;
if ( F_33 ( V_19 -> V_73 ) )
V_19 -> V_73 = NULL ;
}
#endif
return V_10 ;
V_67:
F_34 ( V_19 -> V_65 ) ;
V_45:
F_35 ( V_19 ) ;
return V_10 ;
}
static struct V_18 *
F_36 ( struct V_34 * V_35 , int V_30 ,
struct V_6 * V_33 , struct V_6 * V_7 )
{
struct V_36 * V_37 = V_35 -> V_37 -> V_75 + V_30 ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
int V_10 ;
char * V_12 ;
V_2 = F_7 ( V_7 , V_37 -> V_8 , & V_12 ) ;
if ( V_2 == NULL ) {
F_20 ( V_35 -> V_43 , L_7 ,
V_30 ) ;
return F_37 ( - V_44 ) ;
}
F_38 ( V_35 -> V_43 , L_8 ,
V_30 , V_12 ) ;
V_19 = F_39 ( sizeof( * V_19 ) + V_2 -> V_76 , V_77 ) ;
if ( V_19 == NULL )
return F_37 ( - V_66 ) ;
V_19 -> V_35 = V_35 ;
V_19 -> V_30 = V_30 ;
V_19 -> V_37 = V_37 ;
V_19 -> V_2 = V_2 ;
V_19 -> V_50 = V_2 -> V_50 ;
V_19 -> V_78 = V_7 ;
V_10 = F_19 ( V_19 , V_33 ) ;
if ( V_10 )
return F_37 ( V_10 ) ;
return V_19 ;
}
static void F_40 ( struct V_18 * V_19 )
{
#ifdef F_29
if ( V_19 -> V_73 )
F_41 ( V_19 -> V_73 ) ;
#endif
}
static int F_42 ( struct V_18 * V_19 )
{
int V_39 , V_10 = 0 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
if ( ! F_43 ( V_19 , V_39 ) )
continue;
V_10 = F_44 ( V_19 -> V_79 [ V_39 ] ) ;
if ( V_10 )
return V_10 ;
}
if ( V_19 -> V_2 -> V_80 )
V_10 = V_19 -> V_2 -> V_80 ( V_19 ) ;
return V_10 ;
}
static int F_45 ( struct V_18 * V_19 )
{
int V_39 , V_10 = 0 ;
if ( V_19 -> V_2 -> V_81 )
V_10 = V_19 -> V_2 -> V_81 ( V_19 ) ;
if ( V_10 )
return V_10 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
if ( ! F_43 ( V_19 , V_39 ) )
continue;
V_10 = F_46 ( V_19 -> V_79 [ V_39 ] ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static void F_47 ( struct V_82 * V_83 )
{
struct V_34 * V_35 ;
int V_39 ;
V_35 = F_18 ( V_83 , struct V_34 , V_84 ) ;
for ( V_39 = 0 ; V_39 < V_35 -> V_37 -> V_85 ; V_39 ++ ) {
struct V_18 * V_19 = V_35 -> V_19 [ V_39 ] ;
if ( V_19 != NULL && V_19 -> V_2 -> V_86 != NULL )
V_19 -> V_2 -> V_86 ( V_19 ) ;
}
F_48 ( & V_35 -> V_87 , F_49 ( V_88 + V_89 ) ) ;
}
static void F_50 ( unsigned long V_90 )
{
struct V_34 * V_35 = ( void * ) V_90 ;
F_51 ( & V_35 -> V_84 ) ;
}
static int F_52 ( struct V_6 * V_14 , void * V_91 )
{
if ( V_14 -> V_91 != NULL && ! strcmp ( V_14 -> V_91 -> V_12 , V_91 ) )
return 1 ;
return 0 ;
}
static struct V_6 * F_53 ( struct V_6 * V_33 , char * V_91 )
{
if ( F_52 ( V_33 , V_91 ) ) {
F_54 ( V_33 ) ;
return V_33 ;
}
return F_55 ( V_33 , V_91 , F_52 ) ;
}
struct V_92 * F_56 ( struct V_6 * V_14 )
{
struct V_6 * V_93 ;
V_93 = F_53 ( V_14 , L_9 ) ;
if ( V_93 != NULL ) {
struct V_92 * V_94 ;
V_94 = F_57 ( V_93 ) ;
F_58 ( V_93 ) ;
return V_94 ;
}
return NULL ;
}
static struct V_95 * F_59 ( struct V_6 * V_14 )
{
struct V_6 * V_93 ;
V_93 = F_53 ( V_14 , L_10 ) ;
if ( V_93 != NULL ) {
struct V_95 * V_96 ;
V_96 = F_60 ( V_93 ) ;
F_61 ( V_96 ) ;
F_58 ( V_93 ) ;
return V_96 ;
}
return NULL ;
}
static int F_62 ( struct V_97 * V_37 ,
struct V_36 * V_98 ,
int V_99 , int V_100 ,
struct V_101 * V_102 )
{
const T_4 * V_103 ;
int V_104 ;
struct V_101 * V_105 ;
int V_106 ;
V_105 = F_63 ( V_102 ) ;
if ( ! V_105 )
return - V_44 ;
V_103 = F_64 ( V_105 , L_11 , & V_106 ) ;
if ( ! V_103 || ( V_106 != sizeof( * V_103 ) * 2 ) )
return - V_44 ;
V_104 = F_65 ( V_103 + 1 ) ;
if ( V_104 >= V_37 -> V_85 )
return - V_44 ;
if ( ! V_98 -> V_107 ) {
V_98 -> V_107 = F_66 ( V_37 -> V_85 , sizeof( V_108 ) ,
V_77 ) ;
if ( ! V_98 -> V_107 )
return - V_66 ;
memset ( V_98 -> V_107 , - 1 , V_37 -> V_85 * sizeof( V_108 ) ) ;
}
V_98 -> V_107 [ V_104 ] = V_100 ;
return 0 ;
}
static void F_67 ( struct V_97 * V_37 )
{
int V_39 ;
int V_100 ;
for ( V_39 = 0 ; V_39 < V_37 -> V_85 ; V_39 ++ ) {
V_100 = 0 ;
while ( V_100 < V_40 ) {
F_35 ( V_37 -> V_75 [ V_39 ] . V_41 [ V_100 ] ) ;
V_100 ++ ;
}
F_35 ( V_37 -> V_75 [ V_39 ] . V_107 ) ;
}
F_35 ( V_37 -> V_75 ) ;
}
static int F_68 ( struct V_6 * V_14 )
{
struct V_101 * V_109 = V_14 -> V_110 ;
struct V_101 * V_111 , * V_112 , * V_113 , * V_114 , * V_102 ;
struct V_92 * V_115 ;
struct V_95 * V_116 ;
struct V_97 * V_37 ;
struct V_36 * V_98 ;
const char * V_117 ;
int V_99 , V_100 ;
const unsigned int * V_8 , * V_118 ;
T_5 V_119 ;
int V_10 ;
V_112 = F_69 ( V_109 , L_12 , 0 ) ;
if ( ! V_112 )
return - V_44 ;
V_115 = F_70 ( V_112 ) ;
if ( ! V_115 )
return - V_120 ;
V_113 = F_69 ( V_109 , L_13 , 0 ) ;
if ( ! V_113 )
return - V_44 ;
V_116 = F_71 ( V_113 ) ;
if ( ! V_116 )
return - V_120 ;
V_37 = F_39 ( sizeof( * V_37 ) , V_77 ) ;
if ( ! V_37 )
return - V_66 ;
V_14 -> V_121 = V_37 ;
V_37 -> V_122 = V_116 ;
V_37 -> V_85 = F_72 ( V_109 ) ;
if ( V_37 -> V_85 > V_123 )
V_37 -> V_85 = V_123 ;
V_37 -> V_75 = F_73 ( V_37 -> V_85 , sizeof( struct V_36 ) ,
V_77 ) ;
if ( ! V_37 -> V_75 ) {
V_10 = - V_66 ;
goto V_67;
}
V_99 = - 1 ;
F_74 (np, child) {
V_99 ++ ;
V_98 = & V_37 -> V_75 [ V_99 ] ;
V_98 -> V_110 = V_111 ;
V_98 -> V_7 = & V_115 -> V_14 ;
V_8 = F_64 ( V_111 , L_11 , NULL ) ;
if ( ! V_8 )
continue;
V_98 -> V_8 = F_65 ( V_8 ) ;
if ( V_98 -> V_8 > V_124 )
continue;
if ( ! F_75 ( V_111 , L_14 , & V_119 ) )
V_98 -> V_119 = V_119 ;
F_74 (child, port) {
V_118 = F_64 ( V_114 , L_11 , NULL ) ;
if ( ! V_118 )
continue;
V_100 = F_65 ( V_118 ) ;
V_117 = F_64 ( V_114 , L_15 , NULL ) ;
if ( ! V_117 )
continue;
V_98 -> V_125 [ V_100 ] = V_114 ;
V_98 -> V_41 [ V_100 ] = F_76 ( V_117 ,
V_77 ) ;
if ( ! V_98 -> V_41 [ V_100 ] ) {
V_10 = - V_66 ;
goto V_126;
}
V_102 = F_69 ( V_114 , L_16 , 0 ) ;
if ( ! strcmp ( V_117 , L_4 ) && V_102 &&
V_37 -> V_85 > 1 ) {
V_10 = F_62 ( V_37 , V_98 ,
V_99 , V_100 , V_102 ) ;
if ( V_10 )
goto V_126;
}
if ( V_100 == V_40 )
break;
}
}
return 0 ;
V_126:
F_67 ( V_37 ) ;
V_67:
F_35 ( V_37 ) ;
V_14 -> V_121 = NULL ;
return V_10 ;
}
static void F_77 ( struct V_6 * V_14 )
{
struct V_97 * V_37 = V_14 -> V_121 ;
if ( ! V_14 -> V_110 )
return;
F_67 ( V_37 ) ;
F_35 ( V_37 ) ;
}
static inline int F_68 ( struct V_6 * V_14 )
{
return 0 ;
}
static inline void F_77 ( struct V_6 * V_14 )
{
}
static void F_78 ( struct V_34 * V_35 , struct V_95 * V_14 ,
struct V_6 * V_33 , struct V_97 * V_37 )
{
int V_39 ;
V_35 -> V_37 = V_37 ;
V_35 -> V_43 = V_14 ;
V_35 -> V_42 = - 1 ;
V_35 -> V_46 = - 1 ;
for ( V_39 = 0 ; V_39 < V_37 -> V_85 ; V_39 ++ ) {
struct V_18 * V_19 ;
V_19 = F_36 ( V_35 , V_39 , V_33 , V_37 -> V_75 [ V_39 ] . V_7 ) ;
if ( F_33 ( V_19 ) ) {
F_20 ( V_14 , L_17 ,
V_39 , F_79 ( V_19 ) ) ;
continue;
}
V_35 -> V_19 [ V_39 ] = V_19 ;
if ( V_19 -> V_2 -> V_86 != NULL )
V_35 -> V_127 = 1 ;
}
F_80 () ;
V_14 -> V_128 = ( void * ) V_35 ;
if ( V_35 -> V_127 ) {
F_81 ( & V_35 -> V_84 , F_47 ) ;
F_82 ( & V_35 -> V_87 ) ;
V_35 -> V_87 . V_129 = ( unsigned long ) V_35 ;
V_35 -> V_87 . V_130 = F_50 ;
V_35 -> V_87 . V_131 = F_49 ( V_88 + V_89 ) ;
F_83 ( & V_35 -> V_87 ) ;
}
}
static int F_84 ( struct V_132 * V_133 )
{
struct V_97 * V_37 = V_133 -> V_14 . V_121 ;
struct V_95 * V_14 ;
struct V_34 * V_35 ;
int V_10 ;
F_85 ( L_18 ,
V_134 ) ;
if ( V_133 -> V_14 . V_110 ) {
V_10 = F_68 ( & V_133 -> V_14 ) ;
if ( V_10 )
return V_10 ;
V_37 = V_133 -> V_14 . V_121 ;
}
if ( V_37 == NULL || ( V_37 -> V_135 == NULL && V_37 -> V_122 == NULL ) )
return - V_44 ;
if ( V_37 -> V_122 ) {
V_14 = V_37 -> V_122 ;
F_61 ( V_14 ) ;
} else {
V_14 = F_59 ( V_37 -> V_135 ) ;
}
if ( V_14 == NULL ) {
V_10 = - V_120 ;
goto V_45;
}
if ( V_14 -> V_128 != NULL ) {
F_86 ( V_14 ) ;
V_10 = - V_136 ;
goto V_45;
}
V_35 = F_39 ( sizeof( * V_35 ) , V_77 ) ;
if ( V_35 == NULL ) {
F_86 ( V_14 ) ;
V_10 = - V_66 ;
goto V_45;
}
F_87 ( V_133 , V_35 ) ;
F_78 ( V_35 , V_14 , & V_133 -> V_14 , V_37 ) ;
return 0 ;
V_45:
F_77 ( & V_133 -> V_14 ) ;
return V_10 ;
}
static void F_88 ( struct V_34 * V_35 )
{
int V_39 ;
if ( V_35 -> V_127 )
F_89 ( & V_35 -> V_87 ) ;
F_90 ( & V_35 -> V_84 ) ;
for ( V_39 = 0 ; V_39 < V_35 -> V_37 -> V_85 ; V_39 ++ ) {
struct V_18 * V_19 = V_35 -> V_19 [ V_39 ] ;
if ( V_19 != NULL )
F_40 ( V_19 ) ;
}
}
static int F_91 ( struct V_132 * V_133 )
{
struct V_34 * V_35 = F_92 ( V_133 ) ;
F_88 ( V_35 ) ;
F_77 ( & V_133 -> V_14 ) ;
return 0 ;
}
static void F_93 ( struct V_132 * V_133 )
{
}
static int F_94 ( struct V_137 * V_138 , struct V_95 * V_14 ,
struct V_139 * V_140 , struct V_95 * V_141 )
{
struct V_34 * V_35 = V_14 -> V_128 ;
if ( F_95 ( V_35 == NULL ) ) {
F_96 ( V_138 ) ;
return 0 ;
}
return V_35 -> V_52 ( V_138 , V_14 , V_140 , V_141 ) ;
}
static int F_97 ( struct V_6 * V_93 )
{
struct V_132 * V_133 = F_98 ( V_93 ) ;
struct V_34 * V_35 = F_92 ( V_133 ) ;
int V_39 , V_10 = 0 ;
for ( V_39 = 0 ; V_39 < V_35 -> V_37 -> V_85 ; V_39 ++ ) {
struct V_18 * V_19 = V_35 -> V_19 [ V_39 ] ;
if ( V_19 != NULL )
V_10 = F_42 ( V_19 ) ;
}
return V_10 ;
}
static int F_99 ( struct V_6 * V_93 )
{
struct V_132 * V_133 = F_98 ( V_93 ) ;
struct V_34 * V_35 = F_92 ( V_133 ) ;
int V_39 , V_10 = 0 ;
for ( V_39 = 0 ; V_39 < V_35 -> V_37 -> V_85 ; V_39 ++ ) {
struct V_18 * V_19 = V_35 -> V_19 [ V_39 ] ;
if ( V_19 != NULL )
V_10 = F_45 ( V_19 ) ;
}
return V_10 ;
}
static int T_6 F_100 ( void )
{
int V_142 ;
F_101 ( & V_143 ) ;
V_142 = F_102 ( & V_144 ) ;
if ( V_142 )
return V_142 ;
F_103 ( & V_145 ) ;
return 0 ;
}
static void T_7 F_104 ( void )
{
F_105 ( & V_143 ) ;
F_106 ( & V_145 ) ;
F_107 ( & V_144 ) ;
}
