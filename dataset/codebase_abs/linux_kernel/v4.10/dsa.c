static struct V_1 * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return V_2 ;
}
void F_2 ( struct V_5 * V_6 )
{
F_3 ( & V_7 ) ;
F_4 ( & V_6 -> V_8 , & V_9 ) ;
F_5 ( & V_7 ) ;
}
void F_6 ( struct V_5 * V_6 )
{
F_3 ( & V_7 ) ;
F_7 ( & V_6 -> V_8 ) ;
F_5 ( & V_7 ) ;
}
static struct V_5 *
F_8 ( struct V_10 * V_11 , struct V_10 * V_12 , int V_13 ,
const char * * V_14 , void * * V_15 )
{
struct V_5 * V_16 ;
struct V_17 * V_8 ;
const char * V_18 ;
V_16 = NULL ;
V_18 = NULL ;
F_3 ( & V_7 ) ;
F_9 (list, &dsa_switch_drivers) {
struct V_5 * V_6 ;
V_6 = F_10 ( V_8 , struct V_5 , V_8 ) ;
V_18 = V_6 -> V_19 ( V_11 , V_12 , V_13 , V_15 ) ;
if ( V_18 != NULL ) {
V_16 = V_6 ;
break;
}
}
F_5 ( & V_7 ) ;
* V_14 = V_18 ;
return V_16 ;
}
static T_1 F_11 ( struct V_10 * V_4 ,
struct V_20 * V_21 , char * V_22 )
{
struct V_23 * V_24 = F_12 ( V_4 ) ;
int V_25 , V_16 ;
V_16 = V_24 -> V_6 -> V_26 ( V_24 , & V_25 ) ;
if ( V_16 < 0 )
return V_16 ;
return sprintf ( V_22 , L_1 , V_25 * 1000 ) ;
}
static T_1 F_13 ( struct V_10 * V_4 ,
struct V_20 * V_21 , char * V_22 )
{
struct V_23 * V_24 = F_12 ( V_4 ) ;
int V_25 , V_16 ;
V_16 = V_24 -> V_6 -> V_27 ( V_24 , & V_25 ) ;
if ( V_16 < 0 )
return V_16 ;
return sprintf ( V_22 , L_1 , V_25 * 1000 ) ;
}
static T_1 F_14 ( struct V_10 * V_4 ,
struct V_20 * V_21 , const char * V_22 ,
T_2 V_28 )
{
struct V_23 * V_24 = F_12 ( V_4 ) ;
int V_25 , V_16 ;
V_16 = F_15 ( V_22 , 0 , & V_25 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = V_24 -> V_6 -> V_29 ( V_24 , F_16 ( V_25 , 1000 ) ) ;
if ( V_16 < 0 )
return V_16 ;
return V_28 ;
}
static T_1 F_17 ( struct V_10 * V_4 ,
struct V_20 * V_21 , char * V_22 )
{
struct V_23 * V_24 = F_12 ( V_4 ) ;
bool V_30 ;
int V_16 ;
V_16 = V_24 -> V_6 -> V_31 ( V_24 , & V_30 ) ;
if ( V_16 < 0 )
return V_16 ;
return sprintf ( V_22 , L_1 , V_30 ) ;
}
static T_3 F_18 ( struct V_32 * V_33 ,
struct V_34 * V_21 , int V_35 )
{
struct V_10 * V_4 = F_19 ( V_33 , struct V_10 , V_33 ) ;
struct V_23 * V_24 = F_12 ( V_4 ) ;
struct V_5 * V_6 = V_24 -> V_6 ;
T_3 V_36 = V_21 -> V_36 ;
if ( V_35 == 1 ) {
if ( ! V_6 -> V_27 )
V_36 = 0 ;
else if ( ! V_6 -> V_29 )
V_36 &= ~ V_37 ;
} else if ( V_35 == 2 && ! V_6 -> V_31 ) {
V_36 = 0 ;
}
return V_36 ;
}
int F_20 ( struct V_23 * V_24 , struct V_10 * V_4 ,
struct V_38 * V_39 , int V_40 )
{
struct V_41 * V_42 ;
int V_16 , V_36 ;
if ( F_21 ( V_39 ) ) {
V_16 = F_22 ( V_39 ) ;
if ( V_16 ) {
F_23 ( V_4 , L_2 ) ;
return V_16 ;
}
V_42 = F_24 ( V_39 ) ;
V_36 = F_25 ( V_39 ) ;
if ( V_36 < 0 )
V_36 = V_43 ;
V_42 -> V_44 = V_36 ;
F_26 ( V_42 ) ;
F_27 ( V_42 ) ;
if ( V_24 -> V_6 -> V_45 )
V_24 -> V_6 -> V_45 ( V_24 , V_40 , V_42 ) ;
F_28 ( & V_42 -> V_46 . V_4 ) ;
}
return 0 ;
}
static int F_29 ( struct V_23 * V_24 , struct V_10 * V_4 )
{
struct V_38 * V_39 ;
int V_16 , V_40 ;
for ( V_40 = 0 ; V_40 < V_47 ; V_40 ++ ) {
if ( ! ( F_30 ( V_24 , V_40 ) || F_31 ( V_24 , V_40 ) ) )
continue;
V_39 = V_24 -> V_48 [ V_40 ] . V_49 ;
V_16 = F_20 ( V_24 , V_4 , V_39 , V_40 ) ;
if ( V_16 )
return V_16 ;
}
return 0 ;
}
const struct V_50 * F_32 ( int V_51 )
{
const struct V_50 * V_6 ;
if ( V_51 >= V_52 )
return F_33 ( - V_53 ) ;
V_6 = V_50 [ V_51 ] ;
if ( ! V_6 )
return F_33 ( - V_54 ) ;
return V_6 ;
}
int F_34 ( struct V_23 * V_24 )
{
struct V_3 * V_55 ;
struct V_56 * V_57 ;
V_55 = V_24 -> V_58 -> V_59 ;
if ( V_24 -> V_59 )
V_55 = V_24 -> V_59 ;
V_57 = F_35 ( V_24 -> V_4 , sizeof( * V_57 ) , V_60 ) ;
if ( ! V_57 )
return - V_61 ;
memcpy ( & V_24 -> V_58 -> V_62 , V_55 -> V_56 ,
sizeof( struct V_56 ) ) ;
V_24 -> V_58 -> V_63 = V_55 -> V_56 ;
memcpy ( V_57 , & V_24 -> V_58 -> V_62 ,
sizeof( struct V_56 ) ) ;
F_36 ( V_57 ) ;
V_55 -> V_56 = V_57 ;
return 0 ;
}
void F_37 ( struct V_23 * V_24 )
{
struct V_3 * V_55 ;
V_55 = V_24 -> V_58 -> V_59 ;
if ( V_24 -> V_59 )
V_55 = V_24 -> V_59 ;
V_55 -> V_56 = V_24 -> V_58 -> V_63 ;
}
static int F_38 ( struct V_23 * V_24 , struct V_10 * V_11 )
{
struct V_5 * V_6 = V_24 -> V_6 ;
struct V_64 * V_58 = V_24 -> V_58 ;
struct V_65 * V_66 = V_24 -> V_66 ;
bool V_67 = false ;
int V_35 = V_24 -> V_35 ;
int V_68 , V_16 ;
for ( V_68 = 0 ; V_68 < V_47 ; V_68 ++ ) {
char * V_18 ;
V_18 = V_66 -> V_69 [ V_68 ] ;
if ( V_18 == NULL )
continue;
if ( ! strcmp ( V_18 , L_3 ) ) {
if ( V_58 -> V_70 != - 1 ) {
F_39 ( V_58 -> V_59 ,
L_4 ) ;
V_16 = - V_53 ;
goto V_71;
}
V_58 -> V_70 = V_35 ;
V_58 -> V_72 = V_68 ;
V_24 -> V_73 |= 1 << V_68 ;
} else if ( ! strcmp ( V_18 , L_5 ) ) {
V_24 -> V_74 |= 1 << V_68 ;
} else {
V_24 -> V_75 |= 1 << V_68 ;
}
V_67 = true ;
}
if ( ! V_67 && V_68 == V_47 ) {
V_16 = - V_53 ;
goto V_71;
}
V_24 -> V_76 = V_24 -> V_75 ;
if ( V_58 -> V_70 == V_35 ) {
enum V_77 V_51 ;
V_51 = V_6 -> V_78 ( V_24 ) ;
V_58 -> V_79 = F_32 ( V_51 ) ;
if ( F_40 ( V_58 -> V_79 ) ) {
V_16 = F_41 ( V_58 -> V_79 ) ;
goto V_71;
}
V_58 -> V_80 = V_58 -> V_79 -> V_80 ;
}
memcpy ( V_24 -> V_81 , V_66 -> V_81 , sizeof( V_24 -> V_81 ) ) ;
V_16 = V_6 -> V_82 ( V_24 ) ;
if ( V_16 < 0 )
goto V_71;
if ( V_6 -> V_83 ) {
V_16 = V_6 -> V_83 ( V_24 , V_58 -> V_59 -> V_84 ) ;
if ( V_16 < 0 )
goto V_71;
}
if ( ! V_24 -> V_85 && V_6 -> V_86 ) {
V_24 -> V_85 = F_42 ( V_11 ) ;
if ( ! V_24 -> V_85 ) {
V_16 = - V_61 ;
goto V_71;
}
F_43 ( V_24 ) ;
V_16 = F_44 ( V_24 -> V_85 ) ;
if ( V_16 < 0 )
goto V_71;
}
for ( V_68 = 0 ; V_68 < V_47 ; V_68 ++ ) {
V_24 -> V_48 [ V_68 ] . V_49 = V_66 -> V_39 [ V_68 ] ;
if ( ! ( V_24 -> V_75 & ( 1 << V_68 ) ) )
continue;
V_16 = F_45 ( V_24 , V_11 , V_68 , V_66 -> V_69 [ V_68 ] ) ;
if ( V_16 < 0 ) {
F_39 ( V_58 -> V_59 , L_6 ,
V_35 , V_68 , V_66 -> V_69 [ V_68 ] , V_16 ) ;
V_16 = 0 ;
}
}
V_16 = F_29 ( V_24 , V_11 ) ;
if ( V_16 < 0 ) {
F_39 ( V_58 -> V_59 , L_7 ,
V_35 ) ;
V_16 = 0 ;
}
V_16 = F_34 ( V_24 ) ;
if ( V_16 )
return V_16 ;
#ifdef F_46
if ( V_6 -> V_26 ) {
const char * V_87 = F_47 ( V_58 -> V_59 ) ;
char V_88 [ V_89 + 1 ] ;
int V_68 , V_90 ;
for ( V_68 = V_90 = 0 ; V_68 < V_89 && V_87 [ V_68 ] ; V_68 ++ ) {
if ( isalnum ( V_87 [ V_68 ] ) )
V_88 [ V_90 ++ ] = V_87 [ V_68 ] ;
}
V_88 [ V_90 ] = '\0' ;
F_48 ( V_24 -> V_91 , sizeof( V_24 -> V_91 ) , L_8 ,
V_88 , V_35 ) ;
V_24 -> V_92 = F_49 ( NULL ,
V_24 -> V_91 , V_24 , V_93 ) ;
if ( F_40 ( V_24 -> V_92 ) )
V_24 -> V_92 = NULL ;
}
#endif
return V_16 ;
V_71:
return V_16 ;
}
static struct V_23 *
F_50 ( struct V_64 * V_58 , int V_35 ,
struct V_10 * V_11 , struct V_10 * V_12 )
{
struct V_65 * V_66 = V_58 -> V_94 -> V_95 + V_35 ;
struct V_5 * V_6 ;
struct V_23 * V_24 ;
int V_16 ;
const char * V_18 ;
void * V_15 ;
V_6 = F_8 ( V_11 , V_12 , V_66 -> V_13 , & V_18 , & V_15 ) ;
if ( ! V_6 ) {
F_39 ( V_58 -> V_59 , L_9 ,
V_35 ) ;
return F_33 ( - V_53 ) ;
}
F_51 ( V_58 -> V_59 , L_10 ,
V_35 , V_18 ) ;
V_24 = F_35 ( V_11 , sizeof( * V_24 ) , V_60 ) ;
if ( V_24 == NULL )
return F_33 ( - V_61 ) ;
V_24 -> V_58 = V_58 ;
V_24 -> V_35 = V_35 ;
V_24 -> V_66 = V_66 ;
V_24 -> V_6 = V_6 ;
V_24 -> V_15 = V_15 ;
V_24 -> V_4 = V_11 ;
V_16 = F_38 ( V_24 , V_11 ) ;
if ( V_16 )
return F_33 ( V_16 ) ;
return V_24 ;
}
void F_52 ( struct V_38 * V_39 )
{
if ( F_21 ( V_39 ) )
F_53 ( V_39 ) ;
}
static void F_54 ( struct V_23 * V_24 )
{
int V_40 ;
#ifdef F_46
if ( V_24 -> V_92 )
F_55 ( V_24 -> V_92 ) ;
#endif
for ( V_40 = 0 ; V_40 < V_47 ; V_40 ++ ) {
if ( ! ( V_24 -> V_75 & ( 1 << V_40 ) ) )
continue;
if ( ! V_24 -> V_48 [ V_40 ] . V_96 )
continue;
F_56 ( V_24 -> V_48 [ V_40 ] . V_96 ) ;
}
for ( V_40 = 0 ; V_40 < V_47 ; V_40 ++ ) {
if ( ! ( F_30 ( V_24 , V_40 ) || F_31 ( V_24 , V_40 ) ) )
continue;
F_52 ( V_24 -> V_48 [ V_40 ] . V_49 ) ;
V_24 -> V_73 |= ~ ( 1 << V_40 ) ;
V_24 -> V_74 |= ~ ( 1 << V_40 ) ;
}
if ( V_24 -> V_85 && V_24 -> V_6 -> V_86 )
F_57 ( V_24 -> V_85 ) ;
}
int F_58 ( struct V_23 * V_24 )
{
int V_68 , V_16 = 0 ;
for ( V_68 = 0 ; V_68 < V_47 ; V_68 ++ ) {
if ( ! F_59 ( V_24 , V_68 ) )
continue;
V_16 = F_60 ( V_24 -> V_48 [ V_68 ] . V_96 ) ;
if ( V_16 )
return V_16 ;
}
if ( V_24 -> V_6 -> V_97 )
V_16 = V_24 -> V_6 -> V_97 ( V_24 ) ;
return V_16 ;
}
int F_61 ( struct V_23 * V_24 )
{
int V_68 , V_16 = 0 ;
if ( V_24 -> V_6 -> V_98 )
V_16 = V_24 -> V_6 -> V_98 ( V_24 ) ;
if ( V_16 )
return V_16 ;
for ( V_68 = 0 ; V_68 < V_47 ; V_68 ++ ) {
if ( ! F_59 ( V_24 , V_68 ) )
continue;
V_16 = F_62 ( V_24 -> V_48 [ V_68 ] . V_96 ) ;
if ( V_16 )
return V_16 ;
}
return 0 ;
}
static int F_63 ( struct V_10 * V_4 , void * V_99 )
{
if ( V_4 -> V_99 != NULL && ! strcmp ( V_4 -> V_99 -> V_18 , V_99 ) )
return 1 ;
return 0 ;
}
static struct V_10 * F_64 ( struct V_10 * V_11 , char * V_99 )
{
if ( F_63 ( V_11 , V_99 ) ) {
F_65 ( V_11 ) ;
return V_11 ;
}
return F_66 ( V_11 , V_99 , F_63 ) ;
}
struct V_100 * F_67 ( struct V_10 * V_4 )
{
struct V_10 * V_101 ;
V_101 = F_64 ( V_4 , L_11 ) ;
if ( V_101 != NULL ) {
struct V_100 * V_102 ;
V_102 = F_68 ( V_101 ) ;
F_28 ( V_101 ) ;
return V_102 ;
}
return NULL ;
}
static struct V_3 * F_69 ( struct V_10 * V_4 )
{
struct V_10 * V_101 ;
V_101 = F_64 ( V_4 , L_12 ) ;
if ( V_101 != NULL ) {
struct V_3 * V_103 ;
V_103 = F_70 ( V_101 ) ;
F_71 ( V_103 ) ;
F_28 ( V_101 ) ;
return V_103 ;
}
return NULL ;
}
static int F_72 ( struct V_104 * V_94 ,
struct V_65 * V_66 ,
int V_105 , int V_106 ,
struct V_38 * V_107 )
{
const T_4 * V_108 ;
int V_109 ;
struct V_38 * V_110 ;
int V_111 ;
V_110 = F_73 ( V_107 ) ;
if ( ! V_110 )
return - V_53 ;
V_108 = F_74 ( V_110 , L_13 , & V_111 ) ;
if ( ! V_108 || ( V_111 != sizeof( * V_108 ) * 2 ) )
return - V_53 ;
V_109 = F_75 ( V_108 + 1 ) ;
if ( V_109 >= V_94 -> V_112 )
return - V_53 ;
V_66 -> V_81 [ V_109 ] = V_106 ;
return 0 ;
}
static int F_76 ( struct V_104 * V_94 ,
struct V_65 * V_66 ,
int V_105 , int V_106 ,
struct V_38 * V_40 ,
const char * V_113 )
{
struct V_38 * V_107 ;
int V_114 ;
int V_16 ;
for ( V_114 = 0 ; ; V_114 ++ ) {
V_107 = F_77 ( V_40 , L_14 , V_114 ) ;
if ( ! V_107 )
break;
if ( ! strcmp ( V_113 , L_5 ) && V_94 -> V_112 > 1 ) {
V_16 = F_72 ( V_94 , V_66 , V_105 ,
V_106 , V_107 ) ;
if ( V_16 )
return V_16 ;
}
}
return 0 ;
}
static void F_78 ( struct V_104 * V_94 )
{
int V_68 ;
int V_106 ;
for ( V_68 = 0 ; V_68 < V_94 -> V_112 ; V_68 ++ ) {
V_106 = 0 ;
while ( V_106 < V_47 ) {
F_79 ( V_94 -> V_95 [ V_68 ] . V_69 [ V_106 ] ) ;
V_106 ++ ;
}
if ( V_94 -> V_95 [ V_68 ] . V_12 )
F_28 ( V_94 -> V_95 [ V_68 ] . V_12 ) ;
}
F_79 ( V_94 -> V_95 ) ;
}
static int F_80 ( struct V_10 * V_4 )
{
struct V_38 * V_115 = V_4 -> V_116 ;
struct V_38 * V_117 , * V_46 , * V_118 , * V_40 ;
struct V_100 * V_119 , * V_120 ;
struct V_3 * V_121 ;
struct V_104 * V_94 ;
struct V_65 * V_66 ;
const char * V_113 ;
int V_105 , V_106 ;
const unsigned int * V_13 , * V_122 ;
T_5 V_123 ;
int V_16 ;
V_46 = F_77 ( V_115 , L_15 , 0 ) ;
if ( ! V_46 )
return - V_53 ;
V_119 = F_81 ( V_46 ) ;
if ( ! V_119 )
return - V_124 ;
V_118 = F_77 ( V_115 , L_16 , 0 ) ;
if ( ! V_118 ) {
V_16 = - V_53 ;
goto V_125;
}
V_121 = F_82 ( V_118 ) ;
if ( ! V_121 ) {
V_16 = - V_124 ;
goto V_125;
}
V_94 = F_83 ( sizeof( * V_94 ) , V_60 ) ;
if ( ! V_94 ) {
V_16 = - V_61 ;
goto V_126;
}
V_4 -> V_127 = V_94 ;
V_94 -> V_128 = V_121 ;
V_94 -> V_112 = F_84 ( V_115 ) ;
if ( V_94 -> V_112 > V_129 )
V_94 -> V_112 = V_129 ;
V_94 -> V_95 = F_85 ( V_94 -> V_112 , sizeof( struct V_65 ) ,
V_60 ) ;
if ( ! V_94 -> V_95 ) {
V_16 = - V_61 ;
goto V_130;
}
V_105 = - 1 ;
F_86 (np, child) {
int V_68 ;
V_105 ++ ;
V_66 = & V_94 -> V_95 [ V_105 ] ;
V_66 -> V_116 = V_117 ;
for ( V_68 = 0 ; V_68 < V_129 ; ++ V_68 )
V_66 -> V_81 [ V_68 ] = V_131 ;
V_66 -> V_12 = F_65 ( & V_119 -> V_4 ) ;
V_13 = F_74 ( V_117 , L_13 , NULL ) ;
if ( ! V_13 )
continue;
V_66 -> V_13 = F_75 ( V_13 ) ;
if ( V_66 -> V_13 >= V_132 )
continue;
if ( ! F_87 ( V_117 , L_17 , & V_123 ) )
V_66 -> V_123 = V_123 ;
V_46 = F_77 ( V_117 , L_18 , 0 ) ;
if ( V_46 ) {
V_120 = F_81 ( V_46 ) ;
if ( ! V_120 ) {
V_16 = - V_124 ;
goto V_133;
}
F_28 ( V_66 -> V_12 ) ;
V_66 -> V_12 = & V_120 -> V_4 ;
}
F_86 (child, port) {
V_122 = F_74 ( V_40 , L_13 , NULL ) ;
if ( ! V_122 )
continue;
V_106 = F_75 ( V_122 ) ;
if ( V_106 >= V_47 )
break;
V_113 = F_74 ( V_40 , L_19 , NULL ) ;
if ( ! V_113 )
continue;
V_66 -> V_39 [ V_106 ] = V_40 ;
V_66 -> V_69 [ V_106 ] = F_88 ( V_113 ,
V_60 ) ;
if ( ! V_66 -> V_69 [ V_106 ] ) {
V_16 = - V_61 ;
goto V_133;
}
V_16 = F_76 ( V_94 , V_66 , V_105 ,
V_106 , V_40 , V_113 ) ;
if ( V_16 )
goto V_133;
}
}
F_28 ( & V_119 -> V_4 ) ;
return 0 ;
V_133:
F_78 ( V_94 ) ;
V_130:
F_79 ( V_94 ) ;
V_4 -> V_127 = NULL ;
V_126:
F_28 ( & V_121 -> V_4 ) ;
V_125:
F_28 ( & V_119 -> V_4 ) ;
return V_16 ;
}
static void F_89 ( struct V_10 * V_4 )
{
struct V_104 * V_94 = V_4 -> V_127 ;
if ( ! V_4 -> V_116 )
return;
F_78 ( V_94 ) ;
F_28 ( & V_94 -> V_128 -> V_4 ) ;
F_79 ( V_94 ) ;
}
static inline int F_80 ( struct V_10 * V_4 )
{
return 0 ;
}
static inline void F_89 ( struct V_10 * V_4 )
{
}
static int F_90 ( struct V_64 * V_58 , struct V_3 * V_4 ,
struct V_10 * V_11 , struct V_104 * V_94 )
{
int V_68 ;
unsigned V_134 = 0 ;
V_58 -> V_94 = V_94 ;
V_58 -> V_59 = V_4 ;
V_58 -> V_70 = - 1 ;
V_58 -> V_72 = - 1 ;
for ( V_68 = 0 ; V_68 < V_94 -> V_112 ; V_68 ++ ) {
struct V_23 * V_24 ;
V_24 = F_50 ( V_58 , V_68 , V_11 , V_94 -> V_95 [ V_68 ] . V_12 ) ;
if ( F_40 ( V_24 ) ) {
F_39 ( V_4 , L_20 ,
V_68 , F_41 ( V_24 ) ) ;
continue;
}
V_58 -> V_24 [ V_68 ] = V_24 ;
++ V_134 ;
}
if ( ! V_134 )
return - V_124 ;
F_91 () ;
V_4 -> V_135 = ( void * ) V_58 ;
return 0 ;
}
static int F_92 ( struct V_136 * V_137 )
{
struct V_104 * V_94 = V_137 -> V_4 . V_127 ;
struct V_3 * V_4 ;
struct V_64 * V_58 ;
int V_16 ;
F_93 ( L_21 ,
V_138 ) ;
if ( V_137 -> V_4 . V_116 ) {
V_16 = F_80 ( & V_137 -> V_4 ) ;
if ( V_16 )
return V_16 ;
V_94 = V_137 -> V_4 . V_127 ;
}
if ( V_94 == NULL || ( V_94 -> V_96 == NULL && V_94 -> V_128 == NULL ) )
return - V_53 ;
if ( V_94 -> V_128 ) {
V_4 = V_94 -> V_128 ;
F_71 ( V_4 ) ;
} else {
V_4 = F_69 ( V_94 -> V_96 ) ;
}
if ( V_4 == NULL ) {
V_16 = - V_124 ;
goto V_71;
}
if ( V_4 -> V_135 != NULL ) {
F_94 ( V_4 ) ;
V_16 = - V_139 ;
goto V_71;
}
V_58 = F_35 ( & V_137 -> V_4 , sizeof( * V_58 ) , V_60 ) ;
if ( V_58 == NULL ) {
F_94 ( V_4 ) ;
V_16 = - V_61 ;
goto V_71;
}
F_95 ( V_137 , V_58 ) ;
V_16 = F_90 ( V_58 , V_4 , & V_137 -> V_4 , V_94 ) ;
if ( V_16 ) {
F_94 ( V_4 ) ;
goto V_71;
}
return 0 ;
V_71:
F_89 ( & V_137 -> V_4 ) ;
return V_16 ;
}
static void F_96 ( struct V_64 * V_58 )
{
int V_68 ;
V_58 -> V_59 -> V_135 = NULL ;
F_91 () ;
for ( V_68 = 0 ; V_68 < V_58 -> V_94 -> V_112 ; V_68 ++ ) {
struct V_23 * V_24 = V_58 -> V_24 [ V_68 ] ;
if ( V_24 )
F_54 ( V_24 ) ;
}
F_37 ( V_58 -> V_24 [ 0 ] ) ;
F_94 ( V_58 -> V_59 ) ;
}
static int F_97 ( struct V_136 * V_137 )
{
struct V_64 * V_58 = F_98 ( V_137 ) ;
F_96 ( V_58 ) ;
F_89 ( & V_137 -> V_4 ) ;
return 0 ;
}
static void F_99 ( struct V_136 * V_137 )
{
}
static int F_100 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_140 * V_141 , struct V_3 * V_142 )
{
struct V_64 * V_58 = V_4 -> V_135 ;
if ( F_101 ( V_58 == NULL ) ) {
F_102 ( V_2 ) ;
return 0 ;
}
return V_58 -> V_80 ( V_2 , V_4 , V_141 , V_142 ) ;
}
static int F_103 ( struct V_10 * V_101 )
{
struct V_136 * V_137 = F_104 ( V_101 ) ;
struct V_64 * V_58 = F_98 ( V_137 ) ;
int V_68 , V_16 = 0 ;
for ( V_68 = 0 ; V_68 < V_58 -> V_94 -> V_112 ; V_68 ++ ) {
struct V_23 * V_24 = V_58 -> V_24 [ V_68 ] ;
if ( V_24 != NULL )
V_16 = F_58 ( V_24 ) ;
}
return V_16 ;
}
static int F_105 ( struct V_10 * V_101 )
{
struct V_136 * V_137 = F_104 ( V_101 ) ;
struct V_64 * V_58 = F_98 ( V_137 ) ;
int V_68 , V_16 = 0 ;
for ( V_68 = 0 ; V_68 < V_58 -> V_94 -> V_112 ; V_68 ++ ) {
struct V_23 * V_24 = V_58 -> V_24 [ V_68 ] ;
if ( V_24 != NULL )
V_16 = F_61 ( V_24 ) ;
}
return V_16 ;
}
static int T_6 F_106 ( void )
{
int V_143 ;
F_107 ( & V_144 ) ;
V_143 = F_108 ( & V_145 ) ;
if ( V_143 )
return V_143 ;
F_109 ( & V_146 ) ;
return 0 ;
}
static void T_7 F_110 ( void )
{
F_111 ( & V_144 ) ;
F_112 ( & V_146 ) ;
F_113 ( & V_145 ) ;
}
