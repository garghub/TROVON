static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 = V_8 ;
T_1 V_9 ;
V_9 = F_2 ( V_2 ) ;
if ( F_3 ( V_2 ) &&
! F_4 ( V_9 , V_2 -> V_10 ) ) {
V_2 = F_5 ( V_2 , V_2 -> V_10 ,
F_6 ( V_2 ) ) ;
if ( F_7 ( ! V_2 ) ) {
goto V_11;
}
V_2 -> V_12 = 0 ;
}
V_7 = F_8 ( V_2 , V_4 , V_6 , false ) ;
V_11:
return V_7 ;
}
static void F_9 ( struct V_13 * V_14 )
{
struct V_15 * V_16 =
F_10 ( V_14 , struct V_15 , V_17 . V_14 ) ;
struct V_1 * V_2 ;
unsigned long V_18 ;
while ( ( V_2 = F_11 ( & V_16 -> V_6 ) ) ) {
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
if ( ! F_12 ( V_4 ) || ! F_13 ( V_4 ) ) {
F_14 ( V_2 ) ;
continue;
}
V_6 = F_15 ( V_4 , V_2 ) ;
F_16 ( V_18 ) ;
F_17 ( V_4 , V_6 , F_18 () ) ;
if ( F_19 ( V_6 ) ||
F_1 ( V_2 , V_4 , V_6 ) != V_8 ) {
F_20 ( & V_16 -> V_6 , V_2 ) ;
F_21 ( V_4 , V_6 ) ;
F_22 ( V_18 ) ;
F_23 ( & V_16 -> V_17 , V_19 / 10 ) ;
return;
}
F_21 ( V_4 , V_6 ) ;
F_22 ( V_18 ) ;
}
}
static int F_24 ( struct V_20 * V_21 , int V_22 )
{
int V_14 ;
if ( ! F_25 ( V_23 , & V_21 -> V_24 ) )
return V_22 ;
F_26 ( V_25 , & V_21 -> V_24 ) ;
V_14 = V_21 -> V_26 ( V_21 , V_22 ) ;
F_27 ( V_14 > V_22 , L_1 , V_21 -> V_26 ) ;
F_28 ( V_21 ) ;
F_29 ( V_25 , & V_21 -> V_24 ) ;
return V_22 - V_14 ;
}
static void F_30 ( struct V_3 * V_4 , int V_22 )
{
struct V_20 * V_21 ;
F_31 (napi, &dev->napi_list, dev_list) {
if ( V_21 -> V_27 != F_18 () &&
F_32 ( & V_21 -> V_28 ) ) {
V_22 = F_24 ( V_21 , V_22 ) ;
F_33 ( & V_21 -> V_28 ) ;
}
}
}
static void F_34 ( struct V_3 * V_4 )
{
const struct V_29 * V_30 ;
struct V_15 * V_31 = F_35 ( V_4 -> V_16 ) ;
int V_22 = 0 ;
if ( F_36 ( & V_31 -> V_32 ) )
return;
if ( ! F_13 ( V_4 ) ) {
F_37 ( & V_31 -> V_32 ) ;
return;
}
V_30 = V_4 -> V_33 ;
if ( ! V_30 -> V_34 ) {
F_37 ( & V_31 -> V_32 ) ;
return;
}
V_30 -> V_34 ( V_4 ) ;
F_30 ( V_4 , V_22 ) ;
F_37 ( & V_31 -> V_32 ) ;
F_38 () ;
}
void F_39 ( struct V_3 * V_4 )
{
struct V_15 * V_31 ;
int V_35 ;
F_40 () ;
V_35 = F_41 ( & V_36 ) ;
V_31 = F_42 ( V_4 -> V_16 , & V_36 ) ;
if ( V_31 )
F_43 ( & V_31 -> V_32 ) ;
F_44 ( & V_36 , V_35 ) ;
}
void F_45 ( struct V_3 * V_4 )
{
struct V_15 * V_31 ;
F_46 () ;
V_31 = F_47 ( V_4 -> V_16 ) ;
if ( V_31 )
F_37 ( & V_31 -> V_32 ) ;
F_48 () ;
}
static void F_49 ( void )
{
struct V_1 * V_2 ;
unsigned long V_18 ;
F_50 ( & V_37 . V_38 , V_18 ) ;
while ( V_37 . V_39 < V_40 ) {
V_2 = F_51 ( V_41 , V_42 ) ;
if ( ! V_2 )
break;
F_52 ( & V_37 , V_2 ) ;
}
F_53 ( & V_37 . V_38 , V_18 ) ;
}
static void F_38 ( void )
{
unsigned long V_18 ;
struct V_43 * V_44 = & F_54 ( V_43 ) ;
if ( V_44 -> V_45 ) {
struct V_1 * V_46 ;
F_16 ( V_18 ) ;
V_46 = V_44 -> V_45 ;
V_44 -> V_45 = NULL ;
F_22 ( V_18 ) ;
while ( V_46 != NULL ) {
struct V_1 * V_2 = V_46 ;
V_46 = V_46 -> V_47 ;
if ( ! F_55 ( V_2 ) ) {
F_56 ( & V_2 -> V_48 ) ;
F_57 ( V_2 ) ;
} else {
F_58 ( V_2 ) ;
}
}
}
F_59 ( V_43 ) ;
}
static struct V_1 * F_60 ( struct V_49 * V_50 , int V_51 , int V_52 )
{
int V_53 = 0 ;
struct V_1 * V_2 ;
F_38 () ;
F_49 () ;
V_54:
V_2 = F_51 ( V_51 , V_42 ) ;
if ( ! V_2 )
V_2 = F_11 ( & V_37 ) ;
if ( ! V_2 ) {
if ( ++ V_53 < 10 ) {
F_34 ( V_50 -> V_4 ) ;
goto V_54;
}
return NULL ;
}
F_61 ( & V_2 -> V_48 , 1 ) ;
F_62 ( V_2 , V_52 ) ;
return V_2 ;
}
static int F_63 ( struct V_3 * V_4 )
{
struct V_20 * V_21 ;
F_31 (napi, &dev->napi_list, dev_list) {
if ( V_21 -> V_27 == F_18 () )
return 1 ;
}
return 0 ;
}
void F_64 ( struct V_49 * V_50 , struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_7 = V_55 ;
unsigned long V_56 ;
struct V_15 * V_16 ;
F_65 ( ! F_66 () ) ;
V_16 = F_35 ( V_50 -> V_4 -> V_16 ) ;
if ( ! V_16 || ! F_13 ( V_4 ) || ! F_12 ( V_4 ) ) {
F_67 ( V_2 ) ;
return;
}
if ( F_68 ( & V_16 -> V_6 ) == 0 && ! F_63 ( V_4 ) ) {
struct V_5 * V_6 ;
V_6 = F_69 ( V_4 , V_2 , NULL ) ;
for ( V_56 = F_70 ( 1 ) / V_57 ;
V_56 > 0 ; -- V_56 ) {
if ( F_71 ( V_4 , V_6 ) ) {
if ( ! F_72 ( V_6 ) )
V_7 = F_1 ( V_2 , V_4 , V_6 ) ;
F_21 ( V_4 , V_6 ) ;
if ( V_7 == V_8 )
break;
}
F_34 ( V_50 -> V_4 ) ;
F_73 ( V_57 ) ;
}
F_27 ( ! F_66 () ,
L_2 ,
V_4 -> V_58 , V_4 -> V_33 -> V_59 ) ;
}
if ( V_7 != V_8 ) {
F_74 ( & V_16 -> V_6 , V_2 ) ;
F_23 ( & V_16 -> V_17 , 0 ) ;
}
}
void F_75 ( struct V_49 * V_50 , const char * V_60 , int V_51 )
{
int V_61 , V_62 , V_63 ;
struct V_1 * V_2 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
static T_2 V_70 ;
struct V_71 * V_72 ;
V_63 = V_51 + sizeof( * V_65 ) ;
if ( V_50 -> V_73 )
V_62 = V_63 + sizeof( * V_72 ) ;
else
V_62 = V_63 + sizeof( * V_67 ) ;
V_61 = V_62 + F_76 ( V_50 -> V_4 ) ;
V_2 = F_60 ( V_50 , V_61 + V_50 -> V_4 -> V_74 ,
V_61 - V_51 ) ;
if ( ! V_2 )
return;
F_77 ( V_2 , V_60 , V_51 ) ;
F_78 ( V_2 , V_51 ) ;
F_79 ( V_2 , sizeof( * V_65 ) ) ;
F_80 ( V_2 ) ;
V_65 = F_81 ( V_2 ) ;
V_65 -> V_75 = F_82 ( V_50 -> V_76 ) ;
V_65 -> V_77 = F_82 ( V_50 -> V_78 ) ;
V_65 -> V_51 = F_82 ( V_63 ) ;
if ( V_50 -> V_73 ) {
V_65 -> V_79 = 0 ;
V_65 -> V_79 = F_83 ( & V_50 -> V_80 . V_81 ,
& V_50 -> V_82 . V_81 ,
V_63 , V_83 ,
F_84 ( V_65 , V_63 , 0 ) ) ;
if ( V_65 -> V_79 == 0 )
V_65 -> V_79 = V_84 ;
F_79 ( V_2 , sizeof( * V_72 ) ) ;
F_85 ( V_2 ) ;
V_72 = F_86 ( V_2 ) ;
F_87 ( 0x60 , ( unsigned char * ) V_72 ) ;
V_72 -> V_85 [ 0 ] = 0 ;
V_72 -> V_85 [ 1 ] = 0 ;
V_72 -> V_85 [ 2 ] = 0 ;
V_72 -> V_86 = F_82 ( sizeof( struct V_64 ) + V_51 ) ;
V_72 -> V_87 = V_83 ;
V_72 -> V_88 = 32 ;
V_72 -> V_89 = V_50 -> V_80 . V_81 ;
V_72 -> V_90 = V_50 -> V_82 . V_81 ;
V_69 = (struct V_68 * ) F_79 ( V_2 , V_91 ) ;
F_88 ( V_2 ) ;
V_2 -> V_92 = V_69 -> V_93 = F_82 ( V_94 ) ;
} else {
V_65 -> V_79 = 0 ;
V_65 -> V_79 = F_89 ( V_50 -> V_80 . V_95 ,
V_50 -> V_82 . V_95 ,
V_63 , V_83 ,
F_84 ( V_65 , V_63 , 0 ) ) ;
if ( V_65 -> V_79 == 0 )
V_65 -> V_79 = V_84 ;
F_79 ( V_2 , sizeof( * V_67 ) ) ;
F_85 ( V_2 ) ;
V_67 = F_90 ( V_2 ) ;
F_87 ( 0x45 , ( unsigned char * ) V_67 ) ;
V_67 -> V_96 = 0 ;
F_87 ( F_82 ( V_62 ) , & ( V_67 -> V_97 ) ) ;
V_67 -> V_98 = F_82 ( F_91 ( & V_70 ) ) ;
V_67 -> V_99 = 0 ;
V_67 -> V_100 = 64 ;
V_67 -> V_92 = V_83 ;
V_67 -> V_79 = 0 ;
F_87 ( V_50 -> V_80 . V_95 , & ( V_67 -> V_89 ) ) ;
F_87 ( V_50 -> V_82 . V_95 , & ( V_67 -> V_90 ) ) ;
V_67 -> V_79 = F_92 ( ( unsigned char * ) V_67 , V_67 -> V_101 ) ;
V_69 = (struct V_68 * ) F_79 ( V_2 , V_91 ) ;
F_88 ( V_2 ) ;
V_2 -> V_92 = V_69 -> V_93 = F_82 ( V_102 ) ;
}
F_93 ( V_69 -> V_103 , V_50 -> V_4 -> V_104 ) ;
F_93 ( V_69 -> V_105 , V_50 -> V_106 ) ;
V_2 -> V_4 = V_50 -> V_4 ;
F_94 ( V_50 , V_2 ) ;
}
void F_95 ( struct V_49 * V_50 )
{
F_96 ( V_50 , L_3 , V_50 -> V_76 ) ;
if ( V_50 -> V_73 )
F_96 ( V_50 , L_4 , & V_50 -> V_80 . V_81 ) ;
else
F_96 ( V_50 , L_5 , & V_50 -> V_80 . V_95 ) ;
F_96 ( V_50 , L_6 , V_50 -> V_107 ) ;
F_96 ( V_50 , L_7 , V_50 -> V_78 ) ;
if ( V_50 -> V_73 )
F_96 ( V_50 , L_8 , & V_50 -> V_82 . V_81 ) ;
else
F_96 ( V_50 , L_9 , & V_50 -> V_82 . V_95 ) ;
F_96 ( V_50 , L_10 , V_50 -> V_106 ) ;
}
static int F_97 ( const char * V_108 , union V_109 * V_110 )
{
const char * V_111 ;
if ( ! strchr ( V_108 , ':' ) &&
F_98 ( V_108 , - 1 , ( void * ) V_110 , - 1 , & V_111 ) > 0 ) {
if ( ! * V_111 )
return 0 ;
}
if ( F_99 ( V_108 , - 1 , V_110 -> V_81 . V_112 , - 1 , & V_111 ) > 0 ) {
#if F_100 ( V_113 )
if ( ! * V_111 )
return 1 ;
#else
return - 1 ;
#endif
}
return - 1 ;
}
int F_101 ( struct V_49 * V_50 , char * V_114 )
{
char * V_115 = V_114 , * V_116 ;
int V_73 ;
bool V_117 = false ;
if ( * V_115 != '@' ) {
if ( ( V_116 = strchr ( V_115 , '@' ) ) == NULL )
goto V_118;
* V_116 = 0 ;
if ( F_102 ( V_115 , 10 , & V_50 -> V_76 ) )
goto V_118;
V_115 = V_116 ;
}
V_115 ++ ;
if ( * V_115 != '/' ) {
V_117 = true ;
if ( ( V_116 = strchr ( V_115 , '/' ) ) == NULL )
goto V_118;
* V_116 = 0 ;
V_73 = F_97 ( V_115 , & V_50 -> V_80 ) ;
if ( V_73 < 0 )
goto V_118;
else
V_50 -> V_73 = ( bool ) V_73 ;
V_115 = V_116 ;
}
V_115 ++ ;
if ( * V_115 != ',' ) {
if ( ( V_116 = strchr ( V_115 , ',' ) ) == NULL )
goto V_118;
* V_116 = 0 ;
F_103 ( V_50 -> V_107 , V_115 , sizeof( V_50 -> V_107 ) ) ;
V_115 = V_116 ;
}
V_115 ++ ;
if ( * V_115 != '@' ) {
if ( ( V_116 = strchr ( V_115 , '@' ) ) == NULL )
goto V_118;
* V_116 = 0 ;
if ( * V_115 == ' ' || * V_115 == '\t' )
F_96 ( V_50 , L_11 ) ;
if ( F_102 ( V_115 , 10 , & V_50 -> V_78 ) )
goto V_118;
V_115 = V_116 ;
}
V_115 ++ ;
if ( ( V_116 = strchr ( V_115 , '/' ) ) == NULL )
goto V_118;
* V_116 = 0 ;
V_73 = F_97 ( V_115 , & V_50 -> V_82 ) ;
if ( V_73 < 0 )
goto V_118;
else if ( V_117 && V_50 -> V_73 != ( bool ) V_73 )
goto V_118;
else
V_50 -> V_73 = ( bool ) V_73 ;
V_115 = V_116 + 1 ;
if ( * V_115 != 0 ) {
if ( ! F_104 ( V_115 , V_50 -> V_106 ) )
goto V_118;
}
F_95 ( V_50 ) ;
return 0 ;
V_118:
F_96 ( V_50 , L_12 , V_115 ) ;
return - 1 ;
}
int F_105 ( struct V_49 * V_50 , struct V_3 * V_119 )
{
struct V_15 * V_16 ;
const struct V_29 * V_30 ;
int V_120 ;
V_50 -> V_4 = V_119 ;
F_103 ( V_50 -> V_107 , V_119 -> V_58 , V_121 ) ;
F_106 ( & V_50 -> V_122 , V_123 ) ;
if ( ( V_119 -> V_124 & V_125 ) ||
! V_119 -> V_33 -> V_34 ) {
F_107 ( V_50 , L_13 ,
V_50 -> V_107 ) ;
V_120 = - V_126 ;
goto V_11;
}
if ( ! V_119 -> V_16 ) {
V_16 = F_108 ( sizeof( * V_16 ) , V_127 ) ;
if ( ! V_16 ) {
V_120 = - V_128 ;
goto V_11;
}
F_109 ( & V_16 -> V_32 , 1 ) ;
F_110 ( & V_16 -> V_6 ) ;
F_111 ( & V_16 -> V_17 , F_9 ) ;
F_61 ( & V_16 -> V_129 , 1 ) ;
V_30 = V_50 -> V_4 -> V_33 ;
if ( V_30 -> V_130 ) {
V_120 = V_30 -> V_130 ( V_119 , V_16 ) ;
if ( V_120 )
goto V_131;
}
} else {
V_16 = F_112 ( V_119 -> V_16 ) ;
F_56 ( & V_16 -> V_129 ) ;
}
V_16 -> V_49 = V_50 ;
F_113 ( V_119 -> V_16 , V_16 ) ;
return 0 ;
V_131:
F_114 ( V_16 ) ;
V_11:
return V_120 ;
}
int F_115 ( struct V_49 * V_50 )
{
struct V_3 * V_119 = NULL ;
struct V_132 * V_133 ;
int V_120 ;
F_116 () ;
if ( V_50 -> V_107 ) {
struct V_134 * V_134 = V_135 -> V_136 -> V_137 ;
V_119 = F_117 ( V_134 , V_50 -> V_107 ) ;
}
if ( ! V_119 ) {
F_107 ( V_50 , L_14 , V_50 -> V_107 ) ;
V_120 = - V_138 ;
goto V_139;
}
F_118 ( V_119 ) ;
if ( F_119 ( V_119 ) ) {
F_107 ( V_50 , L_15 , V_50 -> V_107 ) ;
V_120 = - V_140 ;
goto V_141;
}
if ( ! F_13 ( V_119 ) ) {
unsigned long V_142 , V_143 ;
F_96 ( V_50 , L_16 , V_50 -> V_107 ) ;
V_120 = F_120 ( V_119 ) ;
if ( V_120 ) {
F_107 ( V_50 , L_17 , V_119 -> V_58 ) ;
goto V_141;
}
F_121 () ;
V_143 = V_144 + V_19 / 10 ;
V_142 = V_144 + V_145 * V_19 ;
while ( ! F_122 ( V_119 ) ) {
if ( F_123 ( V_144 , V_142 ) ) {
F_124 ( V_50 , L_18 ) ;
break;
}
F_125 ( 1 ) ;
}
if ( F_126 ( V_144 , V_143 ) ) {
F_124 ( V_50 , L_19 ) ;
F_125 ( 4000 ) ;
}
F_116 () ;
}
if ( ! V_50 -> V_80 . V_95 ) {
if ( ! V_50 -> V_73 ) {
V_133 = F_127 ( V_119 ) ;
if ( ! V_133 || ! V_133 -> V_146 ) {
F_107 ( V_50 , L_20 ,
V_50 -> V_107 ) ;
V_120 = - V_147 ;
goto V_141;
}
V_50 -> V_80 . V_95 = V_133 -> V_146 -> V_148 ;
F_96 ( V_50 , L_21 , & V_50 -> V_80 . V_95 ) ;
} else {
#if F_100 ( V_113 )
struct V_149 * V_150 ;
V_120 = - V_147 ;
V_150 = F_128 ( V_119 ) ;
if ( V_150 ) {
struct V_151 * V_152 ;
F_129 ( & V_150 -> V_38 ) ;
F_31 (ifp, &idev->addr_list, if_list) {
if ( F_130 ( & V_152 -> V_110 ) & V_153 )
continue;
V_50 -> V_80 . V_81 = V_152 -> V_110 ;
V_120 = 0 ;
break;
}
F_131 ( & V_150 -> V_38 ) ;
}
if ( V_120 ) {
F_107 ( V_50 , L_22 ,
V_50 -> V_107 ) ;
goto V_141;
} else
F_96 ( V_50 , L_23 , & V_50 -> V_80 . V_81 ) ;
#else
F_107 ( V_50 , L_24 ,
V_50 -> V_107 ) ;
V_120 = - V_154 ;
goto V_141;
#endif
}
}
F_49 () ;
V_120 = F_105 ( V_50 , V_119 ) ;
if ( V_120 )
goto V_141;
F_121 () ;
return 0 ;
V_141:
F_132 ( V_119 ) ;
V_139:
F_121 () ;
return V_120 ;
}
static int T_3 F_133 ( void )
{
F_110 ( & V_37 ) ;
return 0 ;
}
static void F_134 ( struct V_155 * V_155 )
{
struct V_15 * V_16 =
F_10 ( V_155 , struct V_15 , V_156 ) ;
F_135 ( & V_16 -> V_6 ) ;
F_136 ( & V_16 -> V_17 ) ;
F_137 ( & V_16 -> V_6 ) ;
F_136 ( & V_16 -> V_17 ) ;
F_114 ( V_16 ) ;
}
void F_138 ( struct V_49 * V_50 )
{
struct V_15 * V_16 ;
V_16 = F_112 ( V_50 -> V_4 -> V_16 ) ;
if ( ! V_16 )
return;
F_139 ( & V_36 ) ;
if ( F_140 ( & V_16 -> V_129 ) ) {
const struct V_29 * V_30 ;
V_30 = V_50 -> V_4 -> V_33 ;
if ( V_30 -> V_157 )
V_30 -> V_157 ( V_50 -> V_4 ) ;
F_141 ( V_50 -> V_4 -> V_16 , NULL ) ;
F_142 ( & V_16 -> V_156 , F_134 ) ;
} else
F_141 ( V_50 -> V_4 -> V_16 , NULL ) ;
}
static void V_123 ( struct V_13 * V_14 )
{
struct V_49 * V_50 = F_10 ( V_14 , struct V_49 , V_122 ) ;
F_116 () ;
F_138 ( V_50 ) ;
F_121 () ;
F_114 ( V_50 ) ;
}
void F_143 ( struct V_49 * V_50 )
{
F_144 ( & V_50 -> V_122 ) ;
}
void F_145 ( struct V_49 * V_50 )
{
F_116 () ;
if ( ! V_50 -> V_4 )
goto V_11;
F_138 ( V_50 ) ;
F_132 ( V_50 -> V_4 ) ;
V_50 -> V_4 = NULL ;
V_11:
F_121 () ;
}
