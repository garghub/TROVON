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
}
return 0 ;
}
static int F_28 ( struct V_23 * V_24 , struct V_10 * V_4 )
{
struct V_38 * V_39 ;
int V_16 , V_40 ;
for ( V_40 = 0 ; V_40 < V_46 ; V_40 ++ ) {
if ( ! ( F_29 ( V_24 , V_40 ) || F_30 ( V_24 , V_40 ) ) )
continue;
V_39 = V_24 -> V_47 [ V_40 ] . V_48 ;
V_16 = F_20 ( V_24 , V_4 , V_39 , V_40 ) ;
if ( V_16 )
return V_16 ;
}
return 0 ;
}
const struct V_49 * F_31 ( int V_50 )
{
const struct V_49 * V_51 ;
if ( V_50 >= V_52 )
return F_32 ( - V_53 ) ;
V_51 = V_49 [ V_50 ] ;
if ( ! V_51 )
return F_32 ( - V_54 ) ;
return V_51 ;
}
int F_33 ( struct V_23 * V_24 )
{
struct V_3 * V_55 ;
struct V_56 * V_57 ;
V_55 = V_24 -> V_58 -> V_59 ;
if ( V_24 -> V_59 )
V_55 = V_24 -> V_59 ;
V_57 = F_34 ( V_24 -> V_4 , sizeof( * V_57 ) , V_60 ) ;
if ( ! V_57 )
return - V_61 ;
memcpy ( & V_24 -> V_58 -> V_62 , V_55 -> V_56 ,
sizeof( struct V_56 ) ) ;
V_24 -> V_58 -> V_63 = V_55 -> V_56 ;
memcpy ( V_57 , & V_24 -> V_58 -> V_62 ,
sizeof( struct V_56 ) ) ;
F_35 ( V_57 ) ;
V_55 -> V_56 = V_57 ;
return 0 ;
}
void F_36 ( struct V_23 * V_24 )
{
struct V_3 * V_55 ;
V_55 = V_24 -> V_58 -> V_59 ;
if ( V_24 -> V_59 )
V_55 = V_24 -> V_59 ;
V_55 -> V_56 = V_24 -> V_58 -> V_63 ;
}
static int F_37 ( struct V_23 * V_24 , struct V_10 * V_11 )
{
struct V_5 * V_6 = V_24 -> V_6 ;
struct V_64 * V_58 = V_24 -> V_58 ;
struct V_65 * V_66 = V_24 -> V_66 ;
bool V_67 = false ;
int V_35 = V_24 -> V_35 ;
int V_68 , V_16 ;
for ( V_68 = 0 ; V_68 < V_46 ; V_68 ++ ) {
char * V_18 ;
V_18 = V_66 -> V_69 [ V_68 ] ;
if ( V_18 == NULL )
continue;
if ( ! strcmp ( V_18 , L_3 ) ) {
if ( V_58 -> V_70 != - 1 ) {
F_38 ( V_58 -> V_59 ,
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
if ( ! V_67 && V_68 == V_46 ) {
V_16 = - V_53 ;
goto V_71;
}
V_24 -> V_76 = V_24 -> V_75 ;
if ( V_58 -> V_70 == V_35 ) {
V_58 -> V_77 = F_31 ( V_6 -> V_50 ) ;
if ( F_39 ( V_58 -> V_77 ) ) {
V_16 = F_40 ( V_58 -> V_77 ) ;
goto V_71;
}
V_58 -> V_78 = V_58 -> V_77 -> V_78 ;
}
memcpy ( V_24 -> V_79 , V_66 -> V_79 , sizeof( V_24 -> V_79 ) ) ;
V_16 = V_6 -> V_80 ( V_24 ) ;
if ( V_16 < 0 )
goto V_71;
V_16 = V_6 -> V_81 ( V_24 , V_58 -> V_59 -> V_82 ) ;
if ( V_16 < 0 )
goto V_71;
if ( ! V_24 -> V_83 && V_6 -> V_84 ) {
V_24 -> V_83 = F_41 ( V_11 ) ;
if ( ! V_24 -> V_83 ) {
V_16 = - V_61 ;
goto V_71;
}
F_42 ( V_24 ) ;
V_16 = F_43 ( V_24 -> V_83 ) ;
if ( V_16 < 0 )
goto V_71;
}
for ( V_68 = 0 ; V_68 < V_46 ; V_68 ++ ) {
V_24 -> V_47 [ V_68 ] . V_48 = V_66 -> V_39 [ V_68 ] ;
if ( ! ( V_24 -> V_75 & ( 1 << V_68 ) ) )
continue;
V_16 = F_44 ( V_24 , V_11 , V_68 , V_66 -> V_69 [ V_68 ] ) ;
if ( V_16 < 0 ) {
F_38 ( V_58 -> V_59 , L_6 ,
V_35 , V_68 , V_66 -> V_69 [ V_68 ] , V_16 ) ;
V_16 = 0 ;
}
}
V_16 = F_28 ( V_24 , V_11 ) ;
if ( V_16 < 0 ) {
F_38 ( V_58 -> V_59 , L_7 ,
V_35 ) ;
V_16 = 0 ;
}
V_16 = F_33 ( V_24 ) ;
if ( V_16 )
return V_16 ;
#ifdef F_45
if ( V_6 -> V_26 ) {
const char * V_85 = F_46 ( V_58 -> V_59 ) ;
char V_86 [ V_87 + 1 ] ;
int V_68 , V_88 ;
for ( V_68 = V_88 = 0 ; V_68 < V_87 && V_85 [ V_68 ] ; V_68 ++ ) {
if ( isalnum ( V_85 [ V_68 ] ) )
V_86 [ V_88 ++ ] = V_85 [ V_68 ] ;
}
V_86 [ V_88 ] = '\0' ;
F_47 ( V_24 -> V_89 , sizeof( V_24 -> V_89 ) , L_8 ,
V_86 , V_35 ) ;
V_24 -> V_90 = F_48 ( NULL ,
V_24 -> V_89 , V_24 , V_91 ) ;
if ( F_39 ( V_24 -> V_90 ) )
V_24 -> V_90 = NULL ;
}
#endif
return V_16 ;
V_71:
return V_16 ;
}
static struct V_23 *
F_49 ( struct V_64 * V_58 , int V_35 ,
struct V_10 * V_11 , struct V_10 * V_12 )
{
struct V_65 * V_66 = V_58 -> V_92 -> V_93 + V_35 ;
struct V_5 * V_6 ;
struct V_23 * V_24 ;
int V_16 ;
const char * V_18 ;
void * V_15 ;
V_6 = F_8 ( V_11 , V_12 , V_66 -> V_13 , & V_18 , & V_15 ) ;
if ( V_6 == NULL ) {
F_38 ( V_58 -> V_59 , L_9 ,
V_35 ) ;
return F_32 ( - V_53 ) ;
}
F_50 ( V_58 -> V_59 , L_10 ,
V_35 , V_18 ) ;
V_24 = F_34 ( V_11 , sizeof( * V_24 ) , V_60 ) ;
if ( V_24 == NULL )
return F_32 ( - V_61 ) ;
V_24 -> V_58 = V_58 ;
V_24 -> V_35 = V_35 ;
V_24 -> V_66 = V_66 ;
V_24 -> V_6 = V_6 ;
V_24 -> V_15 = V_15 ;
V_24 -> V_4 = V_11 ;
V_16 = F_37 ( V_24 , V_11 ) ;
if ( V_16 )
return F_32 ( V_16 ) ;
return V_24 ;
}
void F_51 ( struct V_38 * V_39 )
{
struct V_41 * V_42 ;
if ( F_21 ( V_39 ) ) {
V_42 = F_24 ( V_39 ) ;
if ( V_42 ) {
F_52 ( V_42 ) ;
F_53 ( V_42 ) ;
}
}
}
static void F_54 ( struct V_23 * V_24 )
{
int V_40 ;
#ifdef F_45
if ( V_24 -> V_90 )
F_55 ( V_24 -> V_90 ) ;
#endif
for ( V_40 = 0 ; V_40 < V_46 ; V_40 ++ ) {
if ( ! ( V_24 -> V_75 & ( 1 << V_40 ) ) )
continue;
if ( ! V_24 -> V_47 [ V_40 ] . V_94 )
continue;
F_56 ( V_24 -> V_47 [ V_40 ] . V_94 ) ;
}
for ( V_40 = 0 ; V_40 < V_46 ; V_40 ++ ) {
if ( ! ( F_29 ( V_24 , V_40 ) || F_30 ( V_24 , V_40 ) ) )
continue;
F_51 ( V_24 -> V_47 [ V_40 ] . V_48 ) ;
V_24 -> V_73 |= ~ ( 1 << V_40 ) ;
V_24 -> V_74 |= ~ ( 1 << V_40 ) ;
}
if ( V_24 -> V_83 && V_24 -> V_6 -> V_84 )
F_57 ( V_24 -> V_83 ) ;
}
static int F_58 ( struct V_23 * V_24 )
{
int V_68 , V_16 = 0 ;
for ( V_68 = 0 ; V_68 < V_46 ; V_68 ++ ) {
if ( ! F_59 ( V_24 , V_68 ) )
continue;
V_16 = F_60 ( V_24 -> V_47 [ V_68 ] . V_94 ) ;
if ( V_16 )
return V_16 ;
}
if ( V_24 -> V_6 -> V_95 )
V_16 = V_24 -> V_6 -> V_95 ( V_24 ) ;
return V_16 ;
}
static int F_61 ( struct V_23 * V_24 )
{
int V_68 , V_16 = 0 ;
if ( V_24 -> V_6 -> V_96 )
V_16 = V_24 -> V_6 -> V_96 ( V_24 ) ;
if ( V_16 )
return V_16 ;
for ( V_68 = 0 ; V_68 < V_46 ; V_68 ++ ) {
if ( ! F_59 ( V_24 , V_68 ) )
continue;
V_16 = F_62 ( V_24 -> V_47 [ V_68 ] . V_94 ) ;
if ( V_16 )
return V_16 ;
}
return 0 ;
}
static int F_63 ( struct V_10 * V_4 , void * V_97 )
{
if ( V_4 -> V_97 != NULL && ! strcmp ( V_4 -> V_97 -> V_18 , V_97 ) )
return 1 ;
return 0 ;
}
static struct V_10 * F_64 ( struct V_10 * V_11 , char * V_97 )
{
if ( F_63 ( V_11 , V_97 ) ) {
F_65 ( V_11 ) ;
return V_11 ;
}
return F_66 ( V_11 , V_97 , F_63 ) ;
}
struct V_98 * F_67 ( struct V_10 * V_4 )
{
struct V_10 * V_99 ;
V_99 = F_64 ( V_4 , L_11 ) ;
if ( V_99 != NULL ) {
struct V_98 * V_100 ;
V_100 = F_68 ( V_99 ) ;
F_69 ( V_99 ) ;
return V_100 ;
}
return NULL ;
}
static struct V_3 * F_70 ( struct V_10 * V_4 )
{
struct V_10 * V_99 ;
V_99 = F_64 ( V_4 , L_12 ) ;
if ( V_99 != NULL ) {
struct V_3 * V_101 ;
V_101 = F_71 ( V_99 ) ;
F_72 ( V_101 ) ;
F_69 ( V_99 ) ;
return V_101 ;
}
return NULL ;
}
static int F_73 ( struct V_102 * V_92 ,
struct V_65 * V_66 ,
int V_103 , int V_104 ,
struct V_38 * V_105 )
{
const T_4 * V_106 ;
int V_107 ;
struct V_38 * V_108 ;
int V_109 ;
V_108 = F_74 ( V_105 ) ;
if ( ! V_108 )
return - V_53 ;
V_106 = F_75 ( V_108 , L_13 , & V_109 ) ;
if ( ! V_106 || ( V_109 != sizeof( * V_106 ) * 2 ) )
return - V_53 ;
V_107 = F_76 ( V_106 + 1 ) ;
if ( V_107 >= V_92 -> V_110 )
return - V_53 ;
V_66 -> V_79 [ V_107 ] = V_104 ;
return 0 ;
}
static int F_77 ( struct V_102 * V_92 ,
struct V_65 * V_66 ,
int V_103 , int V_104 ,
struct V_38 * V_40 ,
const char * V_111 )
{
struct V_38 * V_105 ;
int V_112 ;
int V_16 ;
for ( V_112 = 0 ; ; V_112 ++ ) {
V_105 = F_78 ( V_40 , L_14 , V_112 ) ;
if ( ! V_105 )
break;
if ( ! strcmp ( V_111 , L_5 ) && V_92 -> V_110 > 1 ) {
V_16 = F_73 ( V_92 , V_66 , V_103 ,
V_104 , V_105 ) ;
if ( V_16 )
return V_16 ;
}
}
return 0 ;
}
static void F_79 ( struct V_102 * V_92 )
{
int V_68 ;
int V_104 ;
for ( V_68 = 0 ; V_68 < V_92 -> V_110 ; V_68 ++ ) {
V_104 = 0 ;
while ( V_104 < V_46 ) {
F_80 ( V_92 -> V_93 [ V_68 ] . V_69 [ V_104 ] ) ;
V_104 ++ ;
}
if ( V_92 -> V_93 [ V_68 ] . V_12 )
F_69 ( V_92 -> V_93 [ V_68 ] . V_12 ) ;
}
F_80 ( V_92 -> V_93 ) ;
}
static int F_81 ( struct V_10 * V_4 )
{
struct V_38 * V_113 = V_4 -> V_114 ;
struct V_38 * V_115 , * V_116 , * V_117 , * V_40 ;
struct V_98 * V_118 , * V_119 ;
struct V_3 * V_120 ;
struct V_102 * V_92 ;
struct V_65 * V_66 ;
const char * V_111 ;
int V_103 , V_104 ;
const unsigned int * V_13 , * V_121 ;
T_5 V_122 ;
int V_16 ;
V_116 = F_78 ( V_113 , L_15 , 0 ) ;
if ( ! V_116 )
return - V_53 ;
V_118 = F_82 ( V_116 ) ;
if ( ! V_118 )
return - V_123 ;
V_117 = F_78 ( V_113 , L_16 , 0 ) ;
if ( ! V_117 ) {
V_16 = - V_53 ;
goto V_124;
}
V_120 = F_83 ( V_117 ) ;
if ( ! V_120 ) {
V_16 = - V_123 ;
goto V_124;
}
V_92 = F_84 ( sizeof( * V_92 ) , V_60 ) ;
if ( ! V_92 ) {
V_16 = - V_61 ;
goto V_125;
}
V_4 -> V_126 = V_92 ;
V_92 -> V_127 = V_120 ;
V_92 -> V_110 = F_85 ( V_113 ) ;
if ( V_92 -> V_110 > V_128 )
V_92 -> V_110 = V_128 ;
V_92 -> V_93 = F_86 ( V_92 -> V_110 , sizeof( struct V_65 ) ,
V_60 ) ;
if ( ! V_92 -> V_93 ) {
V_16 = - V_61 ;
goto V_129;
}
V_103 = - 1 ;
F_87 (np, child) {
int V_68 ;
V_103 ++ ;
V_66 = & V_92 -> V_93 [ V_103 ] ;
V_66 -> V_114 = V_115 ;
for ( V_68 = 0 ; V_68 < V_128 ; ++ V_68 )
V_66 -> V_79 [ V_68 ] = V_130 ;
V_66 -> V_12 = F_65 ( & V_118 -> V_4 ) ;
V_13 = F_75 ( V_115 , L_13 , NULL ) ;
if ( ! V_13 )
continue;
V_66 -> V_13 = F_76 ( V_13 ) ;
if ( V_66 -> V_13 >= V_131 )
continue;
if ( ! F_88 ( V_115 , L_17 , & V_122 ) )
V_66 -> V_122 = V_122 ;
V_116 = F_78 ( V_115 , L_18 , 0 ) ;
if ( V_116 ) {
V_119 = F_82 ( V_116 ) ;
if ( ! V_119 ) {
V_16 = - V_123 ;
goto V_132;
}
F_69 ( V_66 -> V_12 ) ;
V_66 -> V_12 = & V_119 -> V_4 ;
}
F_87 (child, port) {
V_121 = F_75 ( V_40 , L_13 , NULL ) ;
if ( ! V_121 )
continue;
V_104 = F_76 ( V_121 ) ;
if ( V_104 >= V_46 )
break;
V_111 = F_75 ( V_40 , L_19 , NULL ) ;
if ( ! V_111 )
continue;
V_66 -> V_39 [ V_104 ] = V_40 ;
V_66 -> V_69 [ V_104 ] = F_89 ( V_111 ,
V_60 ) ;
if ( ! V_66 -> V_69 [ V_104 ] ) {
V_16 = - V_61 ;
goto V_132;
}
V_16 = F_77 ( V_92 , V_66 , V_103 ,
V_104 , V_40 , V_111 ) ;
if ( V_16 )
goto V_132;
}
}
F_69 ( & V_118 -> V_4 ) ;
return 0 ;
V_132:
F_79 ( V_92 ) ;
V_129:
F_80 ( V_92 ) ;
V_4 -> V_126 = NULL ;
V_125:
F_69 ( & V_120 -> V_4 ) ;
V_124:
F_69 ( & V_118 -> V_4 ) ;
return V_16 ;
}
static void F_90 ( struct V_10 * V_4 )
{
struct V_102 * V_92 = V_4 -> V_126 ;
if ( ! V_4 -> V_114 )
return;
F_79 ( V_92 ) ;
F_69 ( & V_92 -> V_127 -> V_4 ) ;
F_80 ( V_92 ) ;
}
static inline int F_81 ( struct V_10 * V_4 )
{
return 0 ;
}
static inline void F_90 ( struct V_10 * V_4 )
{
}
static int F_91 ( struct V_64 * V_58 , struct V_3 * V_4 ,
struct V_10 * V_11 , struct V_102 * V_92 )
{
int V_68 ;
unsigned V_133 = 0 ;
V_58 -> V_92 = V_92 ;
V_58 -> V_59 = V_4 ;
V_58 -> V_70 = - 1 ;
V_58 -> V_72 = - 1 ;
for ( V_68 = 0 ; V_68 < V_92 -> V_110 ; V_68 ++ ) {
struct V_23 * V_24 ;
V_24 = F_49 ( V_58 , V_68 , V_11 , V_92 -> V_93 [ V_68 ] . V_12 ) ;
if ( F_39 ( V_24 ) ) {
F_38 ( V_4 , L_20 ,
V_68 , F_40 ( V_24 ) ) ;
continue;
}
V_58 -> V_24 [ V_68 ] = V_24 ;
++ V_133 ;
}
if ( ! V_133 )
return - V_123 ;
F_92 () ;
V_4 -> V_134 = ( void * ) V_58 ;
return 0 ;
}
static int F_93 ( struct V_135 * V_136 )
{
struct V_102 * V_92 = V_136 -> V_4 . V_126 ;
struct V_3 * V_4 ;
struct V_64 * V_58 ;
int V_16 ;
F_94 ( L_21 ,
V_137 ) ;
if ( V_136 -> V_4 . V_114 ) {
V_16 = F_81 ( & V_136 -> V_4 ) ;
if ( V_16 )
return V_16 ;
V_92 = V_136 -> V_4 . V_126 ;
}
if ( V_92 == NULL || ( V_92 -> V_94 == NULL && V_92 -> V_127 == NULL ) )
return - V_53 ;
if ( V_92 -> V_127 ) {
V_4 = V_92 -> V_127 ;
F_72 ( V_4 ) ;
} else {
V_4 = F_70 ( V_92 -> V_94 ) ;
}
if ( V_4 == NULL ) {
V_16 = - V_123 ;
goto V_71;
}
if ( V_4 -> V_134 != NULL ) {
F_95 ( V_4 ) ;
V_16 = - V_138 ;
goto V_71;
}
V_58 = F_34 ( & V_136 -> V_4 , sizeof( * V_58 ) , V_60 ) ;
if ( V_58 == NULL ) {
F_95 ( V_4 ) ;
V_16 = - V_61 ;
goto V_71;
}
F_96 ( V_136 , V_58 ) ;
V_16 = F_91 ( V_58 , V_4 , & V_136 -> V_4 , V_92 ) ;
if ( V_16 ) {
F_95 ( V_4 ) ;
goto V_71;
}
return 0 ;
V_71:
F_90 ( & V_136 -> V_4 ) ;
return V_16 ;
}
static void F_97 ( struct V_64 * V_58 )
{
int V_68 ;
V_58 -> V_59 -> V_134 = NULL ;
F_92 () ;
for ( V_68 = 0 ; V_68 < V_58 -> V_92 -> V_110 ; V_68 ++ ) {
struct V_23 * V_24 = V_58 -> V_24 [ V_68 ] ;
if ( V_24 )
F_54 ( V_24 ) ;
}
F_36 ( V_58 -> V_24 [ 0 ] ) ;
F_95 ( V_58 -> V_59 ) ;
}
static int F_98 ( struct V_135 * V_136 )
{
struct V_64 * V_58 = F_99 ( V_136 ) ;
F_97 ( V_58 ) ;
F_90 ( & V_136 -> V_4 ) ;
return 0 ;
}
static void F_100 ( struct V_135 * V_136 )
{
}
static int F_101 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_139 * V_140 , struct V_3 * V_141 )
{
struct V_64 * V_58 = V_4 -> V_134 ;
if ( F_102 ( V_58 == NULL ) ) {
F_103 ( V_2 ) ;
return 0 ;
}
return V_58 -> V_78 ( V_2 , V_4 , V_140 , V_141 ) ;
}
static int F_104 ( struct V_10 * V_99 )
{
struct V_135 * V_136 = F_105 ( V_99 ) ;
struct V_64 * V_58 = F_99 ( V_136 ) ;
int V_68 , V_16 = 0 ;
for ( V_68 = 0 ; V_68 < V_58 -> V_92 -> V_110 ; V_68 ++ ) {
struct V_23 * V_24 = V_58 -> V_24 [ V_68 ] ;
if ( V_24 != NULL )
V_16 = F_58 ( V_24 ) ;
}
return V_16 ;
}
static int F_106 ( struct V_10 * V_99 )
{
struct V_135 * V_136 = F_105 ( V_99 ) ;
struct V_64 * V_58 = F_99 ( V_136 ) ;
int V_68 , V_16 = 0 ;
for ( V_68 = 0 ; V_68 < V_58 -> V_92 -> V_110 ; V_68 ++ ) {
struct V_23 * V_24 = V_58 -> V_24 [ V_68 ] ;
if ( V_24 != NULL )
V_16 = F_61 ( V_24 ) ;
}
return V_16 ;
}
static int T_6 F_107 ( void )
{
int V_142 ;
F_108 ( & V_143 ) ;
V_142 = F_109 ( & V_144 ) ;
if ( V_142 )
return V_142 ;
F_110 ( & V_145 ) ;
return 0 ;
}
static void T_7 F_111 ( void )
{
F_112 ( & V_143 ) ;
F_113 ( & V_145 ) ;
F_114 ( & V_144 ) ;
}
