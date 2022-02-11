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
F_7 ( struct V_6 * V_7 , struct V_6 * V_8 , int V_9 ,
const char * * V_10 , void * * V_11 )
{
struct V_1 * V_12 ;
struct V_13 * V_4 ;
const char * V_14 ;
V_12 = NULL ;
V_14 = NULL ;
F_2 ( & V_3 ) ;
F_8 (list, &dsa_switch_drivers) {
struct V_1 * V_2 ;
V_2 = F_9 ( V_4 , struct V_1 , V_4 ) ;
V_14 = V_2 -> V_15 ( V_7 , V_8 , V_9 , V_11 ) ;
if ( V_14 != NULL ) {
V_12 = V_2 ;
break;
}
}
F_4 ( & V_3 ) ;
* V_10 = V_14 ;
return V_12 ;
}
static T_1 F_10 ( struct V_6 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
struct V_20 * V_21 = F_11 ( V_16 ) ;
int V_22 , V_12 ;
V_12 = V_21 -> V_2 -> V_23 ( V_21 , & V_22 ) ;
if ( V_12 < 0 )
return V_12 ;
return sprintf ( V_19 , L_1 , V_22 * 1000 ) ;
}
static T_1 F_12 ( struct V_6 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
struct V_20 * V_21 = F_11 ( V_16 ) ;
int V_22 , V_12 ;
V_12 = V_21 -> V_2 -> V_24 ( V_21 , & V_22 ) ;
if ( V_12 < 0 )
return V_12 ;
return sprintf ( V_19 , L_1 , V_22 * 1000 ) ;
}
static T_1 F_13 ( struct V_6 * V_16 ,
struct V_17 * V_18 , const char * V_19 ,
T_2 V_25 )
{
struct V_20 * V_21 = F_11 ( V_16 ) ;
int V_22 , V_12 ;
V_12 = F_14 ( V_19 , 0 , & V_22 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = V_21 -> V_2 -> V_26 ( V_21 , F_15 ( V_22 , 1000 ) ) ;
if ( V_12 < 0 )
return V_12 ;
return V_25 ;
}
static T_1 F_16 ( struct V_6 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
struct V_20 * V_21 = F_11 ( V_16 ) ;
bool V_27 ;
int V_12 ;
V_12 = V_21 -> V_2 -> V_28 ( V_21 , & V_27 ) ;
if ( V_12 < 0 )
return V_12 ;
return sprintf ( V_19 , L_1 , V_27 ) ;
}
static T_3 F_17 ( struct V_29 * V_30 ,
struct V_31 * V_18 , int V_32 )
{
struct V_6 * V_16 = F_18 ( V_30 , struct V_6 , V_30 ) ;
struct V_20 * V_21 = F_11 ( V_16 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
T_3 V_33 = V_18 -> V_33 ;
if ( V_32 == 1 ) {
if ( ! V_2 -> V_24 )
V_33 = 0 ;
else if ( ! V_2 -> V_26 )
V_33 &= ~ V_34 ;
} else if ( V_32 == 2 && ! V_2 -> V_28 ) {
V_33 = 0 ;
}
return V_33 ;
}
static int F_19 ( struct V_20 * V_21 , struct V_35 * V_36 )
{
struct V_37 * V_38 = V_21 -> V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
int V_12 , V_43 , V_33 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( ! ( F_20 ( V_21 , V_43 ) || F_21 ( V_21 , V_43 ) ) )
continue;
V_40 = V_38 -> V_40 [ V_43 ] ;
if ( F_22 ( V_40 ) ) {
V_12 = F_23 ( V_40 ) ;
if ( V_12 ) {
F_24 ( V_36 ,
L_2 ) ;
return V_12 ;
}
V_42 = F_25 ( V_40 ) ;
V_33 = F_26 ( V_40 ) ;
if ( V_33 < 0 )
V_33 = V_45 ;
V_42 -> V_46 = V_33 ;
F_27 ( V_42 ) ;
F_28 ( V_42 ) ;
if ( V_21 -> V_2 -> V_47 )
V_21 -> V_2 -> V_47 ( V_21 , V_43 , V_42 ) ;
}
}
return 0 ;
}
static int F_29 ( struct V_20 * V_21 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_48 * V_49 = V_21 -> V_49 ;
struct V_37 * V_38 = V_21 -> V_38 ;
bool V_50 = false ;
int V_32 = V_21 -> V_32 ;
int V_51 , V_12 ;
for ( V_51 = 0 ; V_51 < V_44 ; V_51 ++ ) {
char * V_14 ;
V_14 = V_38 -> V_52 [ V_51 ] ;
if ( V_14 == NULL )
continue;
if ( ! strcmp ( V_14 , L_3 ) ) {
if ( V_49 -> V_53 != - 1 ) {
F_24 ( V_49 -> V_54 ,
L_4 ) ;
V_12 = - V_55 ;
goto V_56;
}
V_49 -> V_53 = V_32 ;
V_49 -> V_57 = V_51 ;
} else if ( ! strcmp ( V_14 , L_5 ) ) {
V_21 -> V_58 |= 1 << V_51 ;
} else {
V_21 -> V_59 |= 1 << V_51 ;
}
V_50 = true ;
}
if ( ! V_50 && V_51 == V_44 ) {
V_12 = - V_55 ;
goto V_56;
}
V_21 -> V_60 = V_21 -> V_59 ;
if ( V_49 -> V_53 == V_32 ) {
switch ( V_2 -> V_61 ) {
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
V_12 = - V_72 ;
goto V_56;
}
V_49 -> V_61 = V_2 -> V_61 ;
}
V_12 = V_2 -> V_73 ( V_21 ) ;
if ( V_12 < 0 )
goto V_56;
V_12 = V_2 -> V_74 ( V_21 , V_49 -> V_54 -> V_75 ) ;
if ( V_12 < 0 )
goto V_56;
V_21 -> V_76 = F_34 ( V_7 ) ;
if ( V_21 -> V_76 == NULL ) {
V_12 = - V_77 ;
goto V_56;
}
F_35 ( V_21 ) ;
V_12 = F_36 ( V_21 -> V_76 ) ;
if ( V_12 < 0 )
goto V_56;
for ( V_51 = 0 ; V_51 < V_44 ; V_51 ++ ) {
if ( ! ( V_21 -> V_59 & ( 1 << V_51 ) ) )
continue;
V_12 = F_37 ( V_21 , V_7 , V_51 , V_38 -> V_52 [ V_51 ] ) ;
if ( V_12 < 0 ) {
F_24 ( V_49 -> V_54 , L_6 ,
V_32 , V_51 , V_38 -> V_52 [ V_51 ] , V_12 ) ;
V_12 = 0 ;
}
}
V_12 = F_19 ( V_21 , V_49 -> V_54 ) ;
if ( V_12 < 0 ) {
F_24 ( V_49 -> V_54 , L_7 ,
V_32 ) ;
V_12 = 0 ;
}
#ifdef F_38
if ( V_2 -> V_23 ) {
const char * V_78 = F_39 ( V_49 -> V_54 ) ;
char V_79 [ V_80 + 1 ] ;
int V_51 , V_81 ;
for ( V_51 = V_81 = 0 ; V_51 < V_80 && V_78 [ V_51 ] ; V_51 ++ ) {
if ( isalnum ( V_78 [ V_51 ] ) )
V_79 [ V_81 ++ ] = V_78 [ V_51 ] ;
}
V_79 [ V_81 ] = '\0' ;
F_40 ( V_21 -> V_82 , sizeof( V_21 -> V_82 ) , L_8 ,
V_79 , V_32 ) ;
V_21 -> V_83 = F_41 ( NULL ,
V_21 -> V_82 , V_21 , V_84 ) ;
if ( F_42 ( V_21 -> V_83 ) )
V_21 -> V_83 = NULL ;
}
#endif
return V_12 ;
V_56:
return V_12 ;
}
static struct V_20 *
F_43 ( struct V_48 * V_49 , int V_32 ,
struct V_6 * V_7 , struct V_6 * V_8 )
{
struct V_37 * V_38 = V_49 -> V_85 -> V_86 + V_32 ;
struct V_1 * V_2 ;
struct V_20 * V_21 ;
int V_12 ;
const char * V_14 ;
void * V_11 ;
V_2 = F_7 ( V_7 , V_8 , V_38 -> V_9 , & V_14 , & V_11 ) ;
if ( V_2 == NULL ) {
F_24 ( V_49 -> V_54 , L_9 ,
V_32 ) ;
return F_44 ( - V_55 ) ;
}
F_45 ( V_49 -> V_54 , L_10 ,
V_32 , V_14 ) ;
V_21 = F_46 ( V_7 , sizeof( * V_21 ) , V_87 ) ;
if ( V_21 == NULL )
return F_44 ( - V_77 ) ;
V_21 -> V_49 = V_49 ;
V_21 -> V_32 = V_32 ;
V_21 -> V_38 = V_38 ;
V_21 -> V_2 = V_2 ;
V_21 -> V_11 = V_11 ;
V_21 -> V_16 = V_7 ;
V_12 = F_29 ( V_21 , V_7 ) ;
if ( V_12 )
return F_44 ( V_12 ) ;
return V_21 ;
}
static void F_47 ( struct V_20 * V_21 )
{
struct V_39 * V_40 ;
struct V_41 * V_42 ;
struct V_37 * V_38 = V_21 -> V_38 ;
int V_43 ;
#ifdef F_38
if ( V_21 -> V_83 )
F_48 ( V_21 -> V_83 ) ;
#endif
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( ! ( V_21 -> V_59 & ( 1 << V_43 ) ) )
continue;
if ( ! V_21 -> V_88 [ V_43 ] )
continue;
F_49 ( V_21 -> V_88 [ V_43 ] ) ;
}
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
V_40 = V_38 -> V_40 [ V_43 ] ;
if ( F_22 ( V_40 ) ) {
V_42 = F_25 ( V_40 ) ;
if ( V_42 ) {
F_50 ( V_42 ) ;
F_51 ( V_40 ) ;
F_52 ( V_42 ) ;
}
}
}
F_53 ( V_21 -> V_76 ) ;
}
static int F_54 ( struct V_20 * V_21 )
{
int V_51 , V_12 = 0 ;
for ( V_51 = 0 ; V_51 < V_44 ; V_51 ++ ) {
if ( ! F_55 ( V_21 , V_51 ) )
continue;
V_12 = F_56 ( V_21 -> V_88 [ V_51 ] ) ;
if ( V_12 )
return V_12 ;
}
if ( V_21 -> V_2 -> V_89 )
V_12 = V_21 -> V_2 -> V_89 ( V_21 ) ;
return V_12 ;
}
static int F_57 ( struct V_20 * V_21 )
{
int V_51 , V_12 = 0 ;
if ( V_21 -> V_2 -> V_90 )
V_12 = V_21 -> V_2 -> V_90 ( V_21 ) ;
if ( V_12 )
return V_12 ;
for ( V_51 = 0 ; V_51 < V_44 ; V_51 ++ ) {
if ( ! F_55 ( V_21 , V_51 ) )
continue;
V_12 = F_58 ( V_21 -> V_88 [ V_51 ] ) ;
if ( V_12 )
return V_12 ;
}
return 0 ;
}
static int F_59 ( struct V_6 * V_16 , void * V_91 )
{
if ( V_16 -> V_91 != NULL && ! strcmp ( V_16 -> V_91 -> V_14 , V_91 ) )
return 1 ;
return 0 ;
}
static struct V_6 * F_60 ( struct V_6 * V_7 , char * V_91 )
{
if ( F_59 ( V_7 , V_91 ) ) {
F_61 ( V_7 ) ;
return V_7 ;
}
return F_62 ( V_7 , V_91 , F_59 ) ;
}
struct V_92 * F_63 ( struct V_6 * V_16 )
{
struct V_6 * V_93 ;
V_93 = F_60 ( V_16 , L_11 ) ;
if ( V_93 != NULL ) {
struct V_92 * V_94 ;
V_94 = F_64 ( V_93 ) ;
F_65 ( V_93 ) ;
return V_94 ;
}
return NULL ;
}
static struct V_35 * F_66 ( struct V_6 * V_16 )
{
struct V_6 * V_93 ;
V_93 = F_60 ( V_16 , L_12 ) ;
if ( V_93 != NULL ) {
struct V_35 * V_95 ;
V_95 = F_67 ( V_93 ) ;
F_68 ( V_95 ) ;
F_65 ( V_93 ) ;
return V_95 ;
}
return NULL ;
}
static int F_69 ( struct V_96 * V_85 ,
struct V_37 * V_38 ,
int V_97 , int V_98 ,
struct V_39 * V_99 )
{
const T_4 * V_100 ;
int V_101 ;
struct V_39 * V_102 ;
int V_103 ;
V_102 = F_70 ( V_99 ) ;
if ( ! V_102 )
return - V_55 ;
V_100 = F_71 ( V_102 , L_13 , & V_103 ) ;
if ( ! V_100 || ( V_103 != sizeof( * V_100 ) * 2 ) )
return - V_55 ;
V_101 = F_72 ( V_100 + 1 ) ;
if ( V_101 >= V_85 -> V_104 )
return - V_55 ;
if ( ! V_38 -> V_105 ) {
V_38 -> V_105 = F_73 ( V_85 -> V_104 , sizeof( V_106 ) ,
V_87 ) ;
if ( ! V_38 -> V_105 )
return - V_77 ;
memset ( V_38 -> V_105 , - 1 , V_85 -> V_104 * sizeof( V_106 ) ) ;
}
V_38 -> V_105 [ V_101 ] = V_98 ;
return 0 ;
}
static int F_74 ( struct V_96 * V_85 ,
struct V_37 * V_38 ,
int V_97 , int V_98 ,
struct V_39 * V_43 ,
const char * V_107 )
{
struct V_39 * V_99 ;
int V_108 ;
int V_12 ;
for ( V_108 = 0 ; ; V_108 ++ ) {
V_99 = F_75 ( V_43 , L_14 , V_108 ) ;
if ( ! V_99 )
break;
if ( ! strcmp ( V_107 , L_5 ) && V_85 -> V_104 > 1 ) {
V_12 = F_69 ( V_85 , V_38 , V_97 ,
V_98 , V_99 ) ;
if ( V_12 )
return V_12 ;
}
}
return 0 ;
}
static void F_76 ( struct V_96 * V_85 )
{
int V_51 ;
int V_98 ;
for ( V_51 = 0 ; V_51 < V_85 -> V_104 ; V_51 ++ ) {
V_98 = 0 ;
while ( V_98 < V_44 ) {
F_77 ( V_85 -> V_86 [ V_51 ] . V_52 [ V_98 ] ) ;
V_98 ++ ;
}
F_77 ( V_85 -> V_86 [ V_51 ] . V_105 ) ;
if ( V_85 -> V_86 [ V_51 ] . V_8 )
F_65 ( V_85 -> V_86 [ V_51 ] . V_8 ) ;
}
F_77 ( V_85 -> V_86 ) ;
}
static int F_78 ( struct V_6 * V_16 )
{
struct V_39 * V_109 = V_16 -> V_110 ;
struct V_39 * V_111 , * V_112 , * V_113 , * V_43 ;
struct V_92 * V_114 , * V_115 ;
struct V_35 * V_116 ;
struct V_96 * V_85 ;
struct V_37 * V_38 ;
const char * V_107 ;
int V_97 , V_98 ;
const unsigned int * V_9 , * V_117 ;
T_5 V_118 ;
int V_12 ;
V_112 = F_75 ( V_109 , L_15 , 0 ) ;
if ( ! V_112 )
return - V_55 ;
V_114 = F_79 ( V_112 ) ;
if ( ! V_114 )
return - V_119 ;
V_113 = F_75 ( V_109 , L_16 , 0 ) ;
if ( ! V_113 ) {
V_12 = - V_55 ;
goto V_120;
}
V_116 = F_80 ( V_113 ) ;
if ( ! V_116 ) {
V_12 = - V_119 ;
goto V_120;
}
V_85 = F_81 ( sizeof( * V_85 ) , V_87 ) ;
if ( ! V_85 ) {
V_12 = - V_77 ;
goto V_121;
}
V_16 -> V_122 = V_85 ;
V_85 -> V_123 = V_116 ;
V_85 -> V_104 = F_82 ( V_109 ) ;
if ( V_85 -> V_104 > V_124 )
V_85 -> V_104 = V_124 ;
V_85 -> V_86 = F_83 ( V_85 -> V_104 , sizeof( struct V_37 ) ,
V_87 ) ;
if ( ! V_85 -> V_86 ) {
V_12 = - V_77 ;
goto V_125;
}
V_97 = - 1 ;
F_84 (np, child) {
V_97 ++ ;
V_38 = & V_85 -> V_86 [ V_97 ] ;
V_38 -> V_110 = V_111 ;
V_38 -> V_8 = F_61 ( & V_114 -> V_16 ) ;
V_9 = F_71 ( V_111 , L_13 , NULL ) ;
if ( ! V_9 )
continue;
V_38 -> V_9 = F_72 ( V_9 ) ;
if ( V_38 -> V_9 >= V_126 )
continue;
if ( ! F_85 ( V_111 , L_17 , & V_118 ) )
V_38 -> V_118 = V_118 ;
V_112 = F_75 ( V_111 , L_18 , 0 ) ;
if ( V_112 ) {
V_115 = F_79 ( V_112 ) ;
if ( ! V_115 ) {
V_12 = - V_119 ;
goto V_127;
}
F_65 ( V_38 -> V_8 ) ;
V_38 -> V_8 = & V_115 -> V_16 ;
}
F_84 (child, port) {
V_117 = F_71 ( V_43 , L_13 , NULL ) ;
if ( ! V_117 )
continue;
V_98 = F_72 ( V_117 ) ;
if ( V_98 >= V_44 )
break;
V_107 = F_71 ( V_43 , L_19 , NULL ) ;
if ( ! V_107 )
continue;
V_38 -> V_40 [ V_98 ] = V_43 ;
V_38 -> V_52 [ V_98 ] = F_86 ( V_107 ,
V_87 ) ;
if ( ! V_38 -> V_52 [ V_98 ] ) {
V_12 = - V_77 ;
goto V_127;
}
V_12 = F_74 ( V_85 , V_38 , V_97 ,
V_98 , V_43 , V_107 ) ;
if ( V_12 )
goto V_127;
}
}
F_65 ( & V_114 -> V_16 ) ;
return 0 ;
V_127:
F_76 ( V_85 ) ;
V_125:
F_77 ( V_85 ) ;
V_16 -> V_122 = NULL ;
V_121:
F_65 ( & V_116 -> V_16 ) ;
V_120:
F_65 ( & V_114 -> V_16 ) ;
return V_12 ;
}
static void F_87 ( struct V_6 * V_16 )
{
struct V_96 * V_85 = V_16 -> V_122 ;
if ( ! V_16 -> V_110 )
return;
F_76 ( V_85 ) ;
F_65 ( & V_85 -> V_123 -> V_16 ) ;
F_77 ( V_85 ) ;
}
static inline int F_78 ( struct V_6 * V_16 )
{
return 0 ;
}
static inline void F_87 ( struct V_6 * V_16 )
{
}
static int F_88 ( struct V_48 * V_49 , struct V_35 * V_16 ,
struct V_6 * V_7 , struct V_96 * V_85 )
{
int V_51 ;
unsigned V_128 = 0 ;
V_49 -> V_85 = V_85 ;
V_49 -> V_54 = V_16 ;
V_49 -> V_53 = - 1 ;
V_49 -> V_57 = - 1 ;
for ( V_51 = 0 ; V_51 < V_85 -> V_104 ; V_51 ++ ) {
struct V_20 * V_21 ;
V_21 = F_43 ( V_49 , V_51 , V_7 , V_85 -> V_86 [ V_51 ] . V_8 ) ;
if ( F_42 ( V_21 ) ) {
F_24 ( V_16 , L_20 ,
V_51 , F_89 ( V_21 ) ) ;
continue;
}
V_49 -> V_21 [ V_51 ] = V_21 ;
++ V_128 ;
}
if ( ! V_128 )
return - V_119 ;
F_90 () ;
V_16 -> V_129 = ( void * ) V_49 ;
return 0 ;
}
static int F_91 ( struct V_130 * V_131 )
{
struct V_96 * V_85 = V_131 -> V_16 . V_122 ;
struct V_35 * V_16 ;
struct V_48 * V_49 ;
int V_12 ;
F_92 ( L_21 ,
V_132 ) ;
if ( V_131 -> V_16 . V_110 ) {
V_12 = F_78 ( & V_131 -> V_16 ) ;
if ( V_12 )
return V_12 ;
V_85 = V_131 -> V_16 . V_122 ;
}
if ( V_85 == NULL || ( V_85 -> V_133 == NULL && V_85 -> V_123 == NULL ) )
return - V_55 ;
if ( V_85 -> V_123 ) {
V_16 = V_85 -> V_123 ;
F_68 ( V_16 ) ;
} else {
V_16 = F_66 ( V_85 -> V_133 ) ;
}
if ( V_16 == NULL ) {
V_12 = - V_119 ;
goto V_56;
}
if ( V_16 -> V_129 != NULL ) {
F_93 ( V_16 ) ;
V_12 = - V_134 ;
goto V_56;
}
V_49 = F_46 ( & V_131 -> V_16 , sizeof( * V_49 ) , V_87 ) ;
if ( V_49 == NULL ) {
F_93 ( V_16 ) ;
V_12 = - V_77 ;
goto V_56;
}
F_94 ( V_131 , V_49 ) ;
V_12 = F_88 ( V_49 , V_16 , & V_131 -> V_16 , V_85 ) ;
if ( V_12 ) {
F_93 ( V_16 ) ;
goto V_56;
}
return 0 ;
V_56:
F_87 ( & V_131 -> V_16 ) ;
return V_12 ;
}
static void F_95 ( struct V_48 * V_49 )
{
int V_51 ;
V_49 -> V_54 -> V_129 = NULL ;
F_90 () ;
for ( V_51 = 0 ; V_51 < V_49 -> V_85 -> V_104 ; V_51 ++ ) {
struct V_20 * V_21 = V_49 -> V_21 [ V_51 ] ;
if ( V_21 )
F_47 ( V_21 ) ;
}
F_93 ( V_49 -> V_54 ) ;
}
static int F_96 ( struct V_130 * V_131 )
{
struct V_48 * V_49 = F_97 ( V_131 ) ;
F_95 ( V_49 ) ;
F_87 ( & V_131 -> V_16 ) ;
return 0 ;
}
static void F_98 ( struct V_130 * V_131 )
{
}
static int F_99 ( struct V_135 * V_136 , struct V_35 * V_16 ,
struct V_137 * V_138 , struct V_35 * V_139 )
{
struct V_48 * V_49 = V_16 -> V_129 ;
if ( F_100 ( V_49 == NULL ) ) {
F_101 ( V_136 ) ;
return 0 ;
}
return V_49 -> V_63 ( V_136 , V_16 , V_138 , V_139 ) ;
}
static int F_102 ( struct V_6 * V_93 )
{
struct V_130 * V_131 = F_103 ( V_93 ) ;
struct V_48 * V_49 = F_97 ( V_131 ) ;
int V_51 , V_12 = 0 ;
for ( V_51 = 0 ; V_51 < V_49 -> V_85 -> V_104 ; V_51 ++ ) {
struct V_20 * V_21 = V_49 -> V_21 [ V_51 ] ;
if ( V_21 != NULL )
V_12 = F_54 ( V_21 ) ;
}
return V_12 ;
}
static int F_104 ( struct V_6 * V_93 )
{
struct V_130 * V_131 = F_103 ( V_93 ) ;
struct V_48 * V_49 = F_97 ( V_131 ) ;
int V_51 , V_12 = 0 ;
for ( V_51 = 0 ; V_51 < V_49 -> V_85 -> V_104 ; V_51 ++ ) {
struct V_20 * V_21 = V_49 -> V_21 [ V_51 ] ;
if ( V_21 != NULL )
V_12 = F_57 ( V_21 ) ;
}
return V_12 ;
}
static int T_6 F_105 ( void )
{
int V_140 ;
F_106 ( & V_141 ) ;
V_140 = F_107 ( & V_142 ) ;
if ( V_140 )
return V_140 ;
F_108 ( & V_143 ) ;
return 0 ;
}
static void T_7 F_109 ( void )
{
F_110 ( & V_141 ) ;
F_111 ( & V_143 ) ;
F_112 ( & V_142 ) ;
}
