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
static int F_19 ( struct V_18 * V_19 , struct V_33 * V_34 )
{
struct V_35 * V_36 = V_19 -> V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
int V_10 , V_42 , V_31 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
if ( ! ( F_20 ( V_19 , V_42 ) || F_21 ( V_19 , V_42 ) ) )
continue;
V_39 = V_36 -> V_39 [ V_42 ] ;
if ( F_22 ( V_39 ) ) {
V_10 = F_23 ( V_39 ) ;
if ( V_10 ) {
F_24 ( V_34 ,
L_2 ) ;
return V_10 ;
}
V_41 = F_25 ( V_39 ) ;
V_31 = F_26 ( V_39 ) ;
if ( V_31 < 0 )
V_31 = V_44 ;
V_41 -> V_45 = V_31 ;
F_27 ( V_41 ) ;
F_28 ( V_41 ) ;
if ( V_19 -> V_2 -> V_46 )
V_19 -> V_2 -> V_46 ( V_19 , V_42 , V_41 ) ;
}
}
return 0 ;
}
static int F_29 ( struct V_18 * V_19 , struct V_6 * V_47 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_48 * V_49 = V_19 -> V_49 ;
struct V_35 * V_37 = V_19 -> V_37 ;
bool V_50 = false ;
int V_30 = V_19 -> V_30 ;
int V_51 , V_10 ;
for ( V_51 = 0 ; V_51 < V_43 ; V_51 ++ ) {
char * V_12 ;
V_12 = V_37 -> V_52 [ V_51 ] ;
if ( V_12 == NULL )
continue;
if ( ! strcmp ( V_12 , L_3 ) ) {
if ( V_49 -> V_53 != - 1 ) {
F_24 ( V_49 -> V_54 ,
L_4 ) ;
V_10 = - V_55 ;
goto V_56;
}
V_49 -> V_53 = V_30 ;
V_49 -> V_57 = V_51 ;
} else if ( ! strcmp ( V_12 , L_5 ) ) {
V_19 -> V_58 |= 1 << V_51 ;
} else {
V_19 -> V_59 |= 1 << V_51 ;
}
V_50 = true ;
}
if ( ! V_50 && V_51 == V_43 ) {
V_10 = - V_55 ;
goto V_56;
}
V_19 -> V_60 = V_19 -> V_59 ;
if ( V_49 -> V_53 == V_30 ) {
switch ( V_19 -> V_61 ) {
#ifdef F_30
case V_62 :
V_49 -> V_63 = V_64 . V_63 ;
break;
#endif
#ifdef F_31
case V_65 :
V_49 -> V_63 = V_66 . V_63 ;
break;
#endif
#ifdef F_32
case V_67 :
V_49 -> V_63 = V_68 . V_63 ;
break;
#endif
#ifdef F_33
case V_69 :
V_49 -> V_63 = V_70 . V_63 ;
break;
#endif
case V_71 :
break;
default:
V_10 = - V_72 ;
goto V_56;
}
V_49 -> V_61 = V_19 -> V_61 ;
}
V_10 = V_2 -> V_73 ( V_19 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = V_2 -> V_74 ( V_19 , V_49 -> V_54 -> V_75 ) ;
if ( V_10 < 0 )
goto V_56;
V_19 -> V_76 = F_34 ( V_47 ) ;
if ( V_19 -> V_76 == NULL ) {
V_10 = - V_77 ;
goto V_56;
}
F_35 ( V_19 ) ;
V_10 = F_36 ( V_19 -> V_76 ) ;
if ( V_10 < 0 )
goto V_56;
for ( V_51 = 0 ; V_51 < V_43 ; V_51 ++ ) {
if ( ! ( V_19 -> V_59 & ( 1 << V_51 ) ) )
continue;
V_10 = F_37 ( V_19 , V_47 , V_51 , V_37 -> V_52 [ V_51 ] ) ;
if ( V_10 < 0 ) {
F_24 ( V_49 -> V_54 , L_6 ,
V_30 , V_51 , V_37 -> V_52 [ V_51 ] ) ;
V_10 = 0 ;
}
}
V_10 = F_19 ( V_19 , V_49 -> V_54 ) ;
if ( V_10 < 0 ) {
F_24 ( V_49 -> V_54 , L_7 ,
V_30 ) ;
V_10 = 0 ;
}
#ifdef F_38
if ( V_2 -> V_21 ) {
const char * V_78 = F_39 ( V_49 -> V_54 ) ;
char V_79 [ V_80 + 1 ] ;
int V_51 , V_81 ;
for ( V_51 = V_81 = 0 ; V_51 < V_80 && V_78 [ V_51 ] ; V_51 ++ ) {
if ( isalnum ( V_78 [ V_51 ] ) )
V_79 [ V_81 ++ ] = V_78 [ V_51 ] ;
}
V_79 [ V_81 ] = '\0' ;
F_40 ( V_19 -> V_82 , sizeof( V_19 -> V_82 ) , L_8 ,
V_79 , V_30 ) ;
V_19 -> V_83 = F_41 ( NULL ,
V_19 -> V_82 , V_19 , V_84 ) ;
if ( F_42 ( V_19 -> V_83 ) )
V_19 -> V_83 = NULL ;
}
#endif
return V_10 ;
V_56:
return V_10 ;
}
static struct V_18 *
F_43 ( struct V_48 * V_49 , int V_30 ,
struct V_6 * V_47 , struct V_6 * V_7 )
{
struct V_35 * V_37 = V_49 -> V_37 -> V_85 + V_30 ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
int V_10 ;
char * V_12 ;
V_2 = F_7 ( V_7 , V_37 -> V_8 , & V_12 ) ;
if ( V_2 == NULL ) {
F_24 ( V_49 -> V_54 , L_9 ,
V_30 ) ;
return F_44 ( - V_55 ) ;
}
F_45 ( V_49 -> V_54 , L_10 ,
V_30 , V_12 ) ;
V_19 = F_46 ( V_47 , sizeof( * V_19 ) + V_2 -> V_86 , V_87 ) ;
if ( V_19 == NULL )
return F_44 ( - V_77 ) ;
V_19 -> V_49 = V_49 ;
V_19 -> V_30 = V_30 ;
V_19 -> V_37 = V_37 ;
V_19 -> V_2 = V_2 ;
V_19 -> V_61 = V_2 -> V_61 ;
V_19 -> V_88 = V_7 ;
V_10 = F_29 ( V_19 , V_47 ) ;
if ( V_10 )
return F_44 ( V_10 ) ;
return V_19 ;
}
static void F_47 ( struct V_18 * V_19 )
{
struct V_38 * V_39 ;
struct V_40 * V_41 ;
struct V_35 * V_36 = V_19 -> V_37 ;
int V_42 ;
#ifdef F_38
if ( V_19 -> V_83 )
F_48 ( V_19 -> V_83 ) ;
#endif
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
if ( ! ( F_20 ( V_19 , V_42 ) || F_21 ( V_19 , V_42 ) ) )
continue;
V_39 = V_36 -> V_39 [ V_42 ] ;
if ( F_22 ( V_39 ) ) {
V_41 = F_25 ( V_39 ) ;
if ( V_41 ) {
int V_89 = V_41 -> V_89 ;
F_49 ( V_41 ) ;
F_50 ( V_39 ) ;
F_51 ( V_89 ) ;
}
}
}
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
if ( ! ( V_19 -> V_59 & ( 1 << V_42 ) ) )
continue;
if ( ! V_19 -> V_90 [ V_42 ] )
continue;
F_52 ( V_19 -> V_90 [ V_42 ] ) ;
F_53 ( V_19 -> V_90 [ V_42 ] ) ;
}
F_54 ( V_19 -> V_76 ) ;
}
static int F_55 ( struct V_18 * V_19 )
{
int V_51 , V_10 = 0 ;
for ( V_51 = 0 ; V_51 < V_43 ; V_51 ++ ) {
if ( ! F_56 ( V_19 , V_51 ) )
continue;
V_10 = F_57 ( V_19 -> V_90 [ V_51 ] ) ;
if ( V_10 )
return V_10 ;
}
if ( V_19 -> V_2 -> V_91 )
V_10 = V_19 -> V_2 -> V_91 ( V_19 ) ;
return V_10 ;
}
static int F_58 ( struct V_18 * V_19 )
{
int V_51 , V_10 = 0 ;
if ( V_19 -> V_2 -> V_92 )
V_10 = V_19 -> V_2 -> V_92 ( V_19 ) ;
if ( V_10 )
return V_10 ;
for ( V_51 = 0 ; V_51 < V_43 ; V_51 ++ ) {
if ( ! F_56 ( V_19 , V_51 ) )
continue;
V_10 = F_59 ( V_19 -> V_90 [ V_51 ] ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static void F_60 ( struct V_93 * V_94 )
{
struct V_48 * V_49 ;
int V_51 ;
V_49 = F_18 ( V_94 , struct V_48 , V_95 ) ;
for ( V_51 = 0 ; V_51 < V_49 -> V_37 -> V_96 ; V_51 ++ ) {
struct V_18 * V_19 = V_49 -> V_19 [ V_51 ] ;
if ( V_19 != NULL && V_19 -> V_2 -> V_97 != NULL )
V_19 -> V_2 -> V_97 ( V_19 ) ;
}
F_61 ( & V_49 -> V_98 , F_62 ( V_99 + V_100 ) ) ;
}
static void F_63 ( unsigned long V_101 )
{
struct V_48 * V_49 = ( void * ) V_101 ;
F_64 ( & V_49 -> V_95 ) ;
}
static int F_65 ( struct V_6 * V_14 , void * V_102 )
{
if ( V_14 -> V_102 != NULL && ! strcmp ( V_14 -> V_102 -> V_12 , V_102 ) )
return 1 ;
return 0 ;
}
static struct V_6 * F_66 ( struct V_6 * V_47 , char * V_102 )
{
if ( F_65 ( V_47 , V_102 ) ) {
F_67 ( V_47 ) ;
return V_47 ;
}
return F_68 ( V_47 , V_102 , F_65 ) ;
}
struct V_103 * F_69 ( struct V_6 * V_14 )
{
struct V_6 * V_104 ;
V_104 = F_66 ( V_14 , L_11 ) ;
if ( V_104 != NULL ) {
struct V_103 * V_105 ;
V_105 = F_70 ( V_104 ) ;
F_71 ( V_104 ) ;
return V_105 ;
}
return NULL ;
}
static struct V_33 * F_72 ( struct V_6 * V_14 )
{
struct V_6 * V_104 ;
V_104 = F_66 ( V_14 , L_12 ) ;
if ( V_104 != NULL ) {
struct V_33 * V_106 ;
V_106 = F_73 ( V_104 ) ;
F_74 ( V_106 ) ;
F_71 ( V_104 ) ;
return V_106 ;
}
return NULL ;
}
static int F_75 ( struct V_107 * V_37 ,
struct V_35 * V_36 ,
int V_108 , int V_109 ,
struct V_38 * V_110 )
{
const T_4 * V_111 ;
int V_112 ;
struct V_38 * V_113 ;
int V_114 ;
V_113 = F_76 ( V_110 ) ;
if ( ! V_113 )
return - V_55 ;
V_111 = F_77 ( V_113 , L_13 , & V_114 ) ;
if ( ! V_111 || ( V_114 != sizeof( * V_111 ) * 2 ) )
return - V_55 ;
V_112 = F_78 ( V_111 + 1 ) ;
if ( V_112 >= V_37 -> V_96 )
return - V_55 ;
if ( ! V_36 -> V_115 ) {
V_36 -> V_115 = F_79 ( V_37 -> V_96 , sizeof( V_116 ) ,
V_87 ) ;
if ( ! V_36 -> V_115 )
return - V_77 ;
memset ( V_36 -> V_115 , - 1 , V_37 -> V_96 * sizeof( V_116 ) ) ;
}
V_36 -> V_115 [ V_112 ] = V_109 ;
return 0 ;
}
static int F_80 ( struct V_107 * V_37 ,
struct V_35 * V_36 ,
int V_108 , int V_109 ,
struct V_38 * V_42 ,
const char * V_117 )
{
struct V_38 * V_110 ;
int V_118 ;
int V_10 ;
for ( V_118 = 0 ; ; V_118 ++ ) {
V_110 = F_81 ( V_42 , L_14 , V_118 ) ;
if ( ! V_110 )
break;
if ( ! strcmp ( V_117 , L_5 ) && V_37 -> V_96 > 1 ) {
V_10 = F_75 ( V_37 , V_36 , V_108 ,
V_109 , V_110 ) ;
if ( V_10 )
return V_10 ;
}
}
return 0 ;
}
static void F_82 ( struct V_107 * V_37 )
{
int V_51 ;
int V_109 ;
for ( V_51 = 0 ; V_51 < V_37 -> V_96 ; V_51 ++ ) {
V_109 = 0 ;
while ( V_109 < V_43 ) {
F_83 ( V_37 -> V_85 [ V_51 ] . V_52 [ V_109 ] ) ;
V_109 ++ ;
}
F_83 ( V_37 -> V_85 [ V_51 ] . V_115 ) ;
if ( V_37 -> V_85 [ V_51 ] . V_7 )
F_71 ( V_37 -> V_85 [ V_51 ] . V_7 ) ;
}
F_83 ( V_37 -> V_85 ) ;
}
static int F_84 ( struct V_6 * V_14 )
{
struct V_38 * V_119 = V_14 -> V_120 ;
struct V_38 * V_121 , * V_122 , * V_123 , * V_42 ;
struct V_103 * V_124 , * V_125 ;
struct V_33 * V_126 ;
struct V_107 * V_37 ;
struct V_35 * V_36 ;
const char * V_117 ;
int V_108 , V_109 ;
const unsigned int * V_8 , * V_127 ;
T_5 V_128 ;
int V_10 ;
V_122 = F_81 ( V_119 , L_15 , 0 ) ;
if ( ! V_122 )
return - V_55 ;
V_124 = F_85 ( V_122 ) ;
if ( ! V_124 )
return - V_129 ;
V_123 = F_81 ( V_119 , L_16 , 0 ) ;
if ( ! V_123 ) {
V_10 = - V_55 ;
goto V_130;
}
V_126 = F_86 ( V_123 ) ;
if ( ! V_126 ) {
V_10 = - V_129 ;
goto V_130;
}
V_37 = F_87 ( sizeof( * V_37 ) , V_87 ) ;
if ( ! V_37 ) {
V_10 = - V_77 ;
goto V_131;
}
V_14 -> V_132 = V_37 ;
V_37 -> V_133 = V_126 ;
V_37 -> V_96 = F_88 ( V_119 ) ;
if ( V_37 -> V_96 > V_134 )
V_37 -> V_96 = V_134 ;
V_37 -> V_85 = F_89 ( V_37 -> V_96 , sizeof( struct V_35 ) ,
V_87 ) ;
if ( ! V_37 -> V_85 ) {
V_10 = - V_77 ;
goto V_135;
}
V_108 = - 1 ;
F_90 (np, child) {
V_108 ++ ;
V_36 = & V_37 -> V_85 [ V_108 ] ;
V_36 -> V_120 = V_121 ;
V_36 -> V_7 = F_67 ( & V_124 -> V_14 ) ;
V_8 = F_77 ( V_121 , L_13 , NULL ) ;
if ( ! V_8 )
continue;
V_36 -> V_8 = F_78 ( V_8 ) ;
if ( V_36 -> V_8 >= V_136 )
continue;
if ( ! F_91 ( V_121 , L_17 , & V_128 ) )
V_36 -> V_128 = V_128 ;
V_122 = F_81 ( V_121 , L_18 , 0 ) ;
if ( V_122 ) {
V_125 = F_85 ( V_122 ) ;
if ( ! V_125 ) {
V_10 = - V_129 ;
goto V_137;
}
F_71 ( V_36 -> V_7 ) ;
V_36 -> V_7 = & V_125 -> V_14 ;
}
F_90 (child, port) {
V_127 = F_77 ( V_42 , L_13 , NULL ) ;
if ( ! V_127 )
continue;
V_109 = F_78 ( V_127 ) ;
if ( V_109 >= V_43 )
break;
V_117 = F_77 ( V_42 , L_19 , NULL ) ;
if ( ! V_117 )
continue;
V_36 -> V_39 [ V_109 ] = V_42 ;
V_36 -> V_52 [ V_109 ] = F_92 ( V_117 ,
V_87 ) ;
if ( ! V_36 -> V_52 [ V_109 ] ) {
V_10 = - V_77 ;
goto V_137;
}
V_10 = F_80 ( V_37 , V_36 , V_108 ,
V_109 , V_42 , V_117 ) ;
if ( V_10 )
goto V_137;
}
}
F_71 ( & V_124 -> V_14 ) ;
return 0 ;
V_137:
F_82 ( V_37 ) ;
V_135:
F_83 ( V_37 ) ;
V_14 -> V_132 = NULL ;
V_131:
F_71 ( & V_126 -> V_14 ) ;
V_130:
F_71 ( & V_124 -> V_14 ) ;
return V_10 ;
}
static void F_93 ( struct V_6 * V_14 )
{
struct V_107 * V_37 = V_14 -> V_132 ;
if ( ! V_14 -> V_120 )
return;
F_82 ( V_37 ) ;
F_71 ( & V_37 -> V_133 -> V_14 ) ;
F_83 ( V_37 ) ;
}
static inline int F_84 ( struct V_6 * V_14 )
{
return 0 ;
}
static inline void F_93 ( struct V_6 * V_14 )
{
}
static int F_94 ( struct V_48 * V_49 , struct V_33 * V_14 ,
struct V_6 * V_47 , struct V_107 * V_37 )
{
int V_51 ;
unsigned V_138 = 0 ;
V_49 -> V_37 = V_37 ;
V_49 -> V_54 = V_14 ;
V_49 -> V_53 = - 1 ;
V_49 -> V_57 = - 1 ;
for ( V_51 = 0 ; V_51 < V_37 -> V_96 ; V_51 ++ ) {
struct V_18 * V_19 ;
V_19 = F_43 ( V_49 , V_51 , V_47 , V_37 -> V_85 [ V_51 ] . V_7 ) ;
if ( F_42 ( V_19 ) ) {
F_24 ( V_14 , L_20 ,
V_51 , F_95 ( V_19 ) ) ;
continue;
}
V_49 -> V_19 [ V_51 ] = V_19 ;
if ( V_19 -> V_2 -> V_97 != NULL )
V_49 -> V_139 = 1 ;
++ V_138 ;
}
if ( ! V_138 )
return - V_129 ;
F_96 () ;
V_14 -> V_140 = ( void * ) V_49 ;
if ( V_49 -> V_139 ) {
F_97 ( & V_49 -> V_95 , F_60 ) ;
F_98 ( & V_49 -> V_98 ) ;
V_49 -> V_98 . V_141 = ( unsigned long ) V_49 ;
V_49 -> V_98 . V_142 = F_63 ;
V_49 -> V_98 . V_143 = F_62 ( V_99 + V_100 ) ;
F_99 ( & V_49 -> V_98 ) ;
}
return 0 ;
}
static int F_100 ( struct V_144 * V_145 )
{
struct V_107 * V_37 = V_145 -> V_14 . V_132 ;
struct V_33 * V_14 ;
struct V_48 * V_49 ;
int V_10 ;
F_101 ( L_21 ,
V_146 ) ;
if ( V_145 -> V_14 . V_120 ) {
V_10 = F_84 ( & V_145 -> V_14 ) ;
if ( V_10 )
return V_10 ;
V_37 = V_145 -> V_14 . V_132 ;
}
if ( V_37 == NULL || ( V_37 -> V_147 == NULL && V_37 -> V_133 == NULL ) )
return - V_55 ;
if ( V_37 -> V_133 ) {
V_14 = V_37 -> V_133 ;
F_74 ( V_14 ) ;
} else {
V_14 = F_72 ( V_37 -> V_147 ) ;
}
if ( V_14 == NULL ) {
V_10 = - V_129 ;
goto V_56;
}
if ( V_14 -> V_140 != NULL ) {
F_102 ( V_14 ) ;
V_10 = - V_148 ;
goto V_56;
}
V_49 = F_46 ( & V_145 -> V_14 , sizeof( * V_49 ) , V_87 ) ;
if ( V_49 == NULL ) {
F_102 ( V_14 ) ;
V_10 = - V_77 ;
goto V_56;
}
F_103 ( V_145 , V_49 ) ;
V_10 = F_94 ( V_49 , V_14 , & V_145 -> V_14 , V_37 ) ;
if ( V_10 )
goto V_56;
return 0 ;
V_56:
F_93 ( & V_145 -> V_14 ) ;
return V_10 ;
}
static void F_104 ( struct V_48 * V_49 )
{
int V_51 ;
if ( V_49 -> V_139 )
F_105 ( & V_49 -> V_98 ) ;
F_106 ( & V_49 -> V_95 ) ;
for ( V_51 = 0 ; V_51 < V_49 -> V_37 -> V_96 ; V_51 ++ ) {
struct V_18 * V_19 = V_49 -> V_19 [ V_51 ] ;
if ( V_19 )
F_47 ( V_19 ) ;
}
}
static int F_107 ( struct V_144 * V_145 )
{
struct V_48 * V_49 = F_108 ( V_145 ) ;
F_104 ( V_49 ) ;
F_93 ( & V_145 -> V_14 ) ;
return 0 ;
}
static void F_109 ( struct V_144 * V_145 )
{
}
static int F_110 ( struct V_149 * V_150 , struct V_33 * V_14 ,
struct V_151 * V_152 , struct V_33 * V_153 )
{
struct V_48 * V_49 = V_14 -> V_140 ;
if ( F_111 ( V_49 == NULL ) ) {
F_112 ( V_150 ) ;
return 0 ;
}
return V_49 -> V_63 ( V_150 , V_14 , V_152 , V_153 ) ;
}
static int F_113 ( struct V_6 * V_104 )
{
struct V_144 * V_145 = F_114 ( V_104 ) ;
struct V_48 * V_49 = F_108 ( V_145 ) ;
int V_51 , V_10 = 0 ;
for ( V_51 = 0 ; V_51 < V_49 -> V_37 -> V_96 ; V_51 ++ ) {
struct V_18 * V_19 = V_49 -> V_19 [ V_51 ] ;
if ( V_19 != NULL )
V_10 = F_55 ( V_19 ) ;
}
return V_10 ;
}
static int F_115 ( struct V_6 * V_104 )
{
struct V_144 * V_145 = F_114 ( V_104 ) ;
struct V_48 * V_49 = F_108 ( V_145 ) ;
int V_51 , V_10 = 0 ;
for ( V_51 = 0 ; V_51 < V_49 -> V_37 -> V_96 ; V_51 ++ ) {
struct V_18 * V_19 = V_49 -> V_19 [ V_51 ] ;
if ( V_19 != NULL )
V_10 = F_58 ( V_19 ) ;
}
return V_10 ;
}
static int T_6 F_116 ( void )
{
int V_154 ;
F_117 ( & V_155 ) ;
V_154 = F_118 ( & V_156 ) ;
if ( V_154 )
return V_154 ;
F_119 ( & V_157 ) ;
return 0 ;
}
static void T_7 F_120 ( void )
{
F_121 ( & V_155 ) ;
F_122 ( & V_157 ) ;
F_123 ( & V_156 ) ;
}
