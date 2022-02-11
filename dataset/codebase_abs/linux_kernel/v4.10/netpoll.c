static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 = V_8 ;
T_1 V_9 ;
V_9 = F_2 ( V_2 ) ;
if ( F_3 ( V_2 ) &&
! F_4 ( V_9 , V_2 -> V_10 ) ) {
V_2 = F_5 ( V_2 ) ;
if ( F_6 ( ! V_2 ) ) {
goto V_11;
}
}
V_7 = F_7 ( V_2 , V_4 , V_6 , false ) ;
V_11:
return V_7 ;
}
static void F_8 ( struct V_12 * V_13 )
{
struct V_14 * V_15 =
F_9 ( V_13 , struct V_14 , V_16 . V_13 ) ;
struct V_1 * V_2 ;
unsigned long V_17 ;
while ( ( V_2 = F_10 ( & V_15 -> V_6 ) ) ) {
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
if ( ! F_11 ( V_4 ) || ! F_12 ( V_4 ) ) {
F_13 ( V_2 ) ;
continue;
}
V_6 = F_14 ( V_4 , V_2 ) ;
F_15 ( V_17 ) ;
F_16 ( V_4 , V_6 , F_17 () ) ;
if ( F_18 ( V_6 ) ||
F_1 ( V_2 , V_4 , V_6 ) != V_8 ) {
F_19 ( & V_15 -> V_6 , V_2 ) ;
F_20 ( V_4 , V_6 ) ;
F_21 ( V_17 ) ;
F_22 ( & V_15 -> V_16 , V_18 / 10 ) ;
return;
}
F_20 ( V_4 , V_6 ) ;
F_21 ( V_17 ) ;
}
}
static void F_23 ( struct V_19 * V_20 )
{
int V_13 = 0 ;
if ( ! F_24 ( V_21 , & V_20 -> V_22 ) )
return;
if ( F_25 ( V_23 , & V_20 -> V_22 ) )
return;
V_13 = V_20 -> V_24 ( V_20 , 0 ) ;
F_26 ( V_13 , L_1 , V_20 -> V_24 ) ;
F_27 ( V_20 , V_13 , 0 ) ;
F_28 ( V_23 , & V_20 -> V_22 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
struct V_19 * V_20 ;
int V_25 = F_17 () ;
F_30 (napi, &dev->napi_list, dev_list) {
if ( F_31 ( & V_20 -> V_26 , - 1 , V_25 ) == - 1 ) {
F_23 ( V_20 ) ;
F_32 ( & V_20 -> V_26 , - 1 ) ;
}
}
}
static void F_33 ( struct V_3 * V_4 )
{
const struct V_27 * V_28 ;
struct V_14 * V_29 = F_34 ( V_4 -> V_15 ) ;
if ( F_35 ( & V_29 -> V_30 ) )
return;
if ( ! F_12 ( V_4 ) ) {
F_36 ( & V_29 -> V_30 ) ;
return;
}
V_28 = V_4 -> V_31 ;
if ( ! V_28 -> V_32 ) {
F_36 ( & V_29 -> V_30 ) ;
return;
}
V_28 -> V_32 ( V_4 ) ;
F_29 ( V_4 ) ;
F_36 ( & V_29 -> V_30 ) ;
F_37 () ;
}
void F_38 ( struct V_3 * V_4 )
{
struct V_14 * V_29 ;
int V_33 ;
F_39 () ;
V_33 = F_40 ( & V_34 ) ;
V_29 = F_41 ( V_4 -> V_15 , & V_34 ) ;
if ( V_29 )
F_42 ( & V_29 -> V_30 ) ;
F_43 ( & V_34 , V_33 ) ;
}
void F_44 ( struct V_3 * V_4 )
{
struct V_14 * V_29 ;
F_45 () ;
V_29 = F_46 ( V_4 -> V_15 ) ;
if ( V_29 )
F_36 ( & V_29 -> V_30 ) ;
F_47 () ;
}
static void F_48 ( void )
{
struct V_1 * V_2 ;
unsigned long V_17 ;
F_49 ( & V_35 . V_36 , V_17 ) ;
while ( V_35 . V_37 < V_38 ) {
V_2 = F_50 ( V_39 , V_40 ) ;
if ( ! V_2 )
break;
F_51 ( & V_35 , V_2 ) ;
}
F_52 ( & V_35 . V_36 , V_17 ) ;
}
static void F_37 ( void )
{
unsigned long V_17 ;
struct V_41 * V_42 = & F_53 ( V_41 ) ;
if ( V_42 -> V_43 ) {
struct V_1 * V_44 ;
F_15 ( V_17 ) ;
V_44 = V_42 -> V_43 ;
V_42 -> V_43 = NULL ;
F_21 ( V_17 ) ;
while ( V_44 != NULL ) {
struct V_1 * V_2 = V_44 ;
V_44 = V_44 -> V_45 ;
if ( ! F_54 ( V_2 ) ) {
F_55 ( & V_2 -> V_46 ) ;
F_56 ( V_2 ) ;
} else {
F_57 ( V_2 ) ;
}
}
}
F_58 ( V_41 ) ;
}
static struct V_1 * F_59 ( struct V_47 * V_48 , int V_49 , int V_50 )
{
int V_51 = 0 ;
struct V_1 * V_2 ;
F_37 () ;
F_48 () ;
V_52:
V_2 = F_50 ( V_49 , V_40 ) ;
if ( ! V_2 )
V_2 = F_10 ( & V_35 ) ;
if ( ! V_2 ) {
if ( ++ V_51 < 10 ) {
F_33 ( V_48 -> V_4 ) ;
goto V_52;
}
return NULL ;
}
F_60 ( & V_2 -> V_46 , 1 ) ;
F_61 ( V_2 , V_50 ) ;
return V_2 ;
}
static int F_62 ( struct V_3 * V_4 )
{
struct V_19 * V_20 ;
F_30 (napi, &dev->napi_list, dev_list) {
if ( V_20 -> V_26 == F_17 () )
return 1 ;
}
return 0 ;
}
void F_63 ( struct V_47 * V_48 , struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_7 = V_53 ;
unsigned long V_54 ;
struct V_14 * V_15 ;
F_64 ( ! F_65 () ) ;
V_15 = F_34 ( V_48 -> V_4 -> V_15 ) ;
if ( ! V_15 || ! F_12 ( V_4 ) || ! F_11 ( V_4 ) ) {
F_66 ( V_2 ) ;
return;
}
if ( F_67 ( & V_15 -> V_6 ) == 0 && ! F_62 ( V_4 ) ) {
struct V_5 * V_6 ;
V_6 = F_68 ( V_4 , V_2 , NULL ) ;
for ( V_54 = F_69 ( 1 ) / V_55 ;
V_54 > 0 ; -- V_54 ) {
if ( F_70 ( V_4 , V_6 ) ) {
if ( ! F_71 ( V_6 ) )
V_7 = F_1 ( V_2 , V_4 , V_6 ) ;
F_20 ( V_4 , V_6 ) ;
if ( V_7 == V_8 )
break;
}
F_33 ( V_48 -> V_4 ) ;
F_72 ( V_55 ) ;
}
F_26 ( ! F_65 () ,
L_2 ,
V_4 -> V_56 , V_4 -> V_31 -> V_57 ) ;
}
if ( V_7 != V_8 ) {
F_73 ( & V_15 -> V_6 , V_2 ) ;
F_22 ( & V_15 -> V_16 , 0 ) ;
}
}
void F_74 ( struct V_47 * V_48 , const char * V_58 , int V_49 )
{
int V_59 , V_60 , V_61 ;
struct V_1 * V_2 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
static T_2 V_68 ;
struct V_69 * V_70 ;
F_64 ( ! F_65 () ) ;
V_61 = V_49 + sizeof( * V_63 ) ;
if ( V_48 -> V_71 )
V_60 = V_61 + sizeof( * V_70 ) ;
else
V_60 = V_61 + sizeof( * V_65 ) ;
V_59 = V_60 + F_75 ( V_48 -> V_4 ) ;
V_2 = F_59 ( V_48 , V_59 + V_48 -> V_4 -> V_72 ,
V_59 - V_49 ) ;
if ( ! V_2 )
return;
F_76 ( V_2 , V_58 , V_49 ) ;
F_77 ( V_2 , V_49 ) ;
F_78 ( V_2 , sizeof( * V_63 ) ) ;
F_79 ( V_2 ) ;
V_63 = F_80 ( V_2 ) ;
V_63 -> V_73 = F_81 ( V_48 -> V_74 ) ;
V_63 -> V_75 = F_81 ( V_48 -> V_76 ) ;
V_63 -> V_49 = F_81 ( V_61 ) ;
if ( V_48 -> V_71 ) {
V_63 -> V_77 = 0 ;
V_63 -> V_77 = F_82 ( & V_48 -> V_78 . V_79 ,
& V_48 -> V_80 . V_79 ,
V_61 , V_81 ,
F_83 ( V_63 , V_61 , 0 ) ) ;
if ( V_63 -> V_77 == 0 )
V_63 -> V_77 = V_82 ;
F_78 ( V_2 , sizeof( * V_70 ) ) ;
F_84 ( V_2 ) ;
V_70 = F_85 ( V_2 ) ;
F_86 ( 0x60 , ( unsigned char * ) V_70 ) ;
V_70 -> V_83 [ 0 ] = 0 ;
V_70 -> V_83 [ 1 ] = 0 ;
V_70 -> V_83 [ 2 ] = 0 ;
V_70 -> V_84 = F_81 ( sizeof( struct V_62 ) + V_49 ) ;
V_70 -> V_85 = V_81 ;
V_70 -> V_86 = 32 ;
V_70 -> V_87 = V_48 -> V_78 . V_79 ;
V_70 -> V_88 = V_48 -> V_80 . V_79 ;
V_67 = (struct V_66 * ) F_78 ( V_2 , V_89 ) ;
F_87 ( V_2 ) ;
V_2 -> V_90 = V_67 -> V_91 = F_81 ( V_92 ) ;
} else {
V_63 -> V_77 = 0 ;
V_63 -> V_77 = F_88 ( V_48 -> V_78 . V_93 ,
V_48 -> V_80 . V_93 ,
V_61 , V_81 ,
F_83 ( V_63 , V_61 , 0 ) ) ;
if ( V_63 -> V_77 == 0 )
V_63 -> V_77 = V_82 ;
F_78 ( V_2 , sizeof( * V_65 ) ) ;
F_84 ( V_2 ) ;
V_65 = F_89 ( V_2 ) ;
F_86 ( 0x45 , ( unsigned char * ) V_65 ) ;
V_65 -> V_94 = 0 ;
F_86 ( F_81 ( V_60 ) , & ( V_65 -> V_95 ) ) ;
V_65 -> V_96 = F_81 ( F_90 ( & V_68 ) ) ;
V_65 -> V_97 = 0 ;
V_65 -> V_98 = 64 ;
V_65 -> V_90 = V_81 ;
V_65 -> V_77 = 0 ;
F_86 ( V_48 -> V_78 . V_93 , & ( V_65 -> V_87 ) ) ;
F_86 ( V_48 -> V_80 . V_93 , & ( V_65 -> V_88 ) ) ;
V_65 -> V_77 = F_91 ( ( unsigned char * ) V_65 , V_65 -> V_99 ) ;
V_67 = (struct V_66 * ) F_78 ( V_2 , V_89 ) ;
F_87 ( V_2 ) ;
V_2 -> V_90 = V_67 -> V_91 = F_81 ( V_100 ) ;
}
F_92 ( V_67 -> V_101 , V_48 -> V_4 -> V_102 ) ;
F_92 ( V_67 -> V_103 , V_48 -> V_104 ) ;
V_2 -> V_4 = V_48 -> V_4 ;
F_93 ( V_48 , V_2 ) ;
}
void F_94 ( struct V_47 * V_48 )
{
F_95 ( V_48 , L_3 , V_48 -> V_74 ) ;
if ( V_48 -> V_71 )
F_95 ( V_48 , L_4 , & V_48 -> V_78 . V_79 ) ;
else
F_95 ( V_48 , L_5 , & V_48 -> V_78 . V_93 ) ;
F_95 ( V_48 , L_6 , V_48 -> V_105 ) ;
F_95 ( V_48 , L_7 , V_48 -> V_76 ) ;
if ( V_48 -> V_71 )
F_95 ( V_48 , L_8 , & V_48 -> V_80 . V_79 ) ;
else
F_95 ( V_48 , L_9 , & V_48 -> V_80 . V_93 ) ;
F_95 ( V_48 , L_10 , V_48 -> V_104 ) ;
}
static int F_96 ( const char * V_106 , union V_107 * V_108 )
{
const char * V_109 ;
if ( ! strchr ( V_106 , ':' ) &&
F_97 ( V_106 , - 1 , ( void * ) V_108 , - 1 , & V_109 ) > 0 ) {
if ( ! * V_109 )
return 0 ;
}
if ( F_98 ( V_106 , - 1 , V_108 -> V_79 . V_110 , - 1 , & V_109 ) > 0 ) {
#if F_99 ( V_111 )
if ( ! * V_109 )
return 1 ;
#else
return - 1 ;
#endif
}
return - 1 ;
}
int F_100 ( struct V_47 * V_48 , char * V_112 )
{
char * V_113 = V_112 , * V_114 ;
int V_71 ;
bool V_115 = false ;
if ( * V_113 != '@' ) {
if ( ( V_114 = strchr ( V_113 , '@' ) ) == NULL )
goto V_116;
* V_114 = 0 ;
if ( F_101 ( V_113 , 10 , & V_48 -> V_74 ) )
goto V_116;
V_113 = V_114 ;
}
V_113 ++ ;
if ( * V_113 != '/' ) {
V_115 = true ;
if ( ( V_114 = strchr ( V_113 , '/' ) ) == NULL )
goto V_116;
* V_114 = 0 ;
V_71 = F_96 ( V_113 , & V_48 -> V_78 ) ;
if ( V_71 < 0 )
goto V_116;
else
V_48 -> V_71 = ( bool ) V_71 ;
V_113 = V_114 ;
}
V_113 ++ ;
if ( * V_113 != ',' ) {
if ( ( V_114 = strchr ( V_113 , ',' ) ) == NULL )
goto V_116;
* V_114 = 0 ;
F_102 ( V_48 -> V_105 , V_113 , sizeof( V_48 -> V_105 ) ) ;
V_113 = V_114 ;
}
V_113 ++ ;
if ( * V_113 != '@' ) {
if ( ( V_114 = strchr ( V_113 , '@' ) ) == NULL )
goto V_116;
* V_114 = 0 ;
if ( * V_113 == ' ' || * V_113 == '\t' )
F_95 ( V_48 , L_11 ) ;
if ( F_101 ( V_113 , 10 , & V_48 -> V_76 ) )
goto V_116;
V_113 = V_114 ;
}
V_113 ++ ;
if ( ( V_114 = strchr ( V_113 , '/' ) ) == NULL )
goto V_116;
* V_114 = 0 ;
V_71 = F_96 ( V_113 , & V_48 -> V_80 ) ;
if ( V_71 < 0 )
goto V_116;
else if ( V_115 && V_48 -> V_71 != ( bool ) V_71 )
goto V_116;
else
V_48 -> V_71 = ( bool ) V_71 ;
V_113 = V_114 + 1 ;
if ( * V_113 != 0 ) {
if ( ! F_103 ( V_113 , V_48 -> V_104 ) )
goto V_116;
}
F_94 ( V_48 ) ;
return 0 ;
V_116:
F_95 ( V_48 , L_12 , V_113 ) ;
return - 1 ;
}
int F_104 ( struct V_47 * V_48 , struct V_3 * V_117 )
{
struct V_14 * V_15 ;
const struct V_27 * V_28 ;
int V_118 ;
V_48 -> V_4 = V_117 ;
F_102 ( V_48 -> V_105 , V_117 -> V_56 , V_119 ) ;
F_105 ( & V_48 -> V_120 , V_121 ) ;
if ( ( V_117 -> V_122 & V_123 ) ||
! V_117 -> V_31 -> V_32 ) {
F_106 ( V_48 , L_13 ,
V_48 -> V_105 ) ;
V_118 = - V_124 ;
goto V_11;
}
if ( ! V_117 -> V_15 ) {
V_15 = F_107 ( sizeof( * V_15 ) , V_125 ) ;
if ( ! V_15 ) {
V_118 = - V_126 ;
goto V_11;
}
F_108 ( & V_15 -> V_30 , 1 ) ;
F_109 ( & V_15 -> V_6 ) ;
F_110 ( & V_15 -> V_16 , F_8 ) ;
F_60 ( & V_15 -> V_127 , 1 ) ;
V_28 = V_48 -> V_4 -> V_31 ;
if ( V_28 -> V_128 ) {
V_118 = V_28 -> V_128 ( V_117 , V_15 ) ;
if ( V_118 )
goto V_129;
}
} else {
V_15 = F_111 ( V_117 -> V_15 ) ;
F_55 ( & V_15 -> V_127 ) ;
}
V_15 -> V_47 = V_48 ;
F_112 ( V_117 -> V_15 , V_15 ) ;
return 0 ;
V_129:
F_113 ( V_15 ) ;
V_11:
return V_118 ;
}
int F_114 ( struct V_47 * V_48 )
{
struct V_3 * V_117 = NULL ;
struct V_130 * V_131 ;
int V_118 ;
F_115 () ;
if ( V_48 -> V_105 ) {
struct V_132 * V_132 = V_133 -> V_134 -> V_135 ;
V_117 = F_116 ( V_132 , V_48 -> V_105 ) ;
}
if ( ! V_117 ) {
F_106 ( V_48 , L_14 , V_48 -> V_105 ) ;
V_118 = - V_136 ;
goto V_137;
}
F_117 ( V_117 ) ;
if ( F_118 ( V_117 ) ) {
F_106 ( V_48 , L_15 , V_48 -> V_105 ) ;
V_118 = - V_138 ;
goto V_139;
}
if ( ! F_12 ( V_117 ) ) {
unsigned long V_140 , V_141 ;
F_95 ( V_48 , L_16 , V_48 -> V_105 ) ;
V_118 = F_119 ( V_117 ) ;
if ( V_118 ) {
F_106 ( V_48 , L_17 , V_117 -> V_56 ) ;
goto V_139;
}
F_120 () ;
V_141 = V_142 + V_18 / 10 ;
V_140 = V_142 + V_143 * V_18 ;
while ( ! F_121 ( V_117 ) ) {
if ( F_122 ( V_142 , V_140 ) ) {
F_123 ( V_48 , L_18 ) ;
break;
}
F_124 ( 1 ) ;
}
if ( F_125 ( V_142 , V_141 ) ) {
F_123 ( V_48 , L_19 ) ;
F_124 ( 4000 ) ;
}
F_115 () ;
}
if ( ! V_48 -> V_78 . V_93 ) {
if ( ! V_48 -> V_71 ) {
V_131 = F_126 ( V_117 ) ;
if ( ! V_131 || ! V_131 -> V_144 ) {
F_106 ( V_48 , L_20 ,
V_48 -> V_105 ) ;
V_118 = - V_145 ;
goto V_139;
}
V_48 -> V_78 . V_93 = V_131 -> V_144 -> V_146 ;
F_95 ( V_48 , L_21 , & V_48 -> V_78 . V_93 ) ;
} else {
#if F_99 ( V_111 )
struct V_147 * V_148 ;
V_118 = - V_145 ;
V_148 = F_127 ( V_117 ) ;
if ( V_148 ) {
struct V_149 * V_150 ;
F_128 ( & V_148 -> V_36 ) ;
F_30 (ifp, &idev->addr_list, if_list) {
if ( F_129 ( & V_150 -> V_108 ) & V_151 )
continue;
V_48 -> V_78 . V_79 = V_150 -> V_108 ;
V_118 = 0 ;
break;
}
F_130 ( & V_148 -> V_36 ) ;
}
if ( V_118 ) {
F_106 ( V_48 , L_22 ,
V_48 -> V_105 ) ;
goto V_139;
} else
F_95 ( V_48 , L_23 , & V_48 -> V_78 . V_79 ) ;
#else
F_106 ( V_48 , L_24 ,
V_48 -> V_105 ) ;
V_118 = - V_152 ;
goto V_139;
#endif
}
}
F_48 () ;
V_118 = F_104 ( V_48 , V_117 ) ;
if ( V_118 )
goto V_139;
F_120 () ;
return 0 ;
V_139:
F_131 ( V_117 ) ;
V_137:
F_120 () ;
return V_118 ;
}
static int T_3 F_132 ( void )
{
F_109 ( & V_35 ) ;
return 0 ;
}
static void F_133 ( struct V_153 * V_153 )
{
struct V_14 * V_15 =
F_9 ( V_153 , struct V_14 , V_154 ) ;
F_134 ( & V_15 -> V_6 ) ;
F_135 ( & V_15 -> V_16 ) ;
F_136 ( & V_15 -> V_6 ) ;
F_135 ( & V_15 -> V_16 ) ;
F_113 ( V_15 ) ;
}
void F_137 ( struct V_47 * V_48 )
{
struct V_14 * V_15 ;
V_15 = F_111 ( V_48 -> V_4 -> V_15 ) ;
if ( ! V_15 )
return;
F_138 ( & V_34 ) ;
if ( F_139 ( & V_15 -> V_127 ) ) {
const struct V_27 * V_28 ;
V_28 = V_48 -> V_4 -> V_31 ;
if ( V_28 -> V_155 )
V_28 -> V_155 ( V_48 -> V_4 ) ;
F_140 ( V_48 -> V_4 -> V_15 , NULL ) ;
F_141 ( & V_15 -> V_154 , F_133 ) ;
} else
F_140 ( V_48 -> V_4 -> V_15 , NULL ) ;
}
static void V_121 ( struct V_12 * V_13 )
{
struct V_47 * V_48 = F_9 ( V_13 , struct V_47 , V_120 ) ;
F_115 () ;
F_137 ( V_48 ) ;
F_120 () ;
F_113 ( V_48 ) ;
}
void F_142 ( struct V_47 * V_48 )
{
F_143 ( & V_48 -> V_120 ) ;
}
void F_144 ( struct V_47 * V_48 )
{
F_115 () ;
if ( ! V_48 -> V_4 )
goto V_11;
F_137 ( V_48 ) ;
F_131 ( V_48 -> V_4 ) ;
V_48 -> V_4 = NULL ;
V_11:
F_120 () ;
}
