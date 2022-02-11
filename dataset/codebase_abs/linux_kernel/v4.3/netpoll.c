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
static int F_23 ( struct V_19 * V_20 , int V_21 )
{
int V_13 = 0 ;
if ( ! F_24 ( V_22 , & V_20 -> V_23 ) )
return V_21 ;
if ( F_25 ( V_24 , & V_20 -> V_23 ) )
goto V_11;
V_13 = V_20 -> V_25 ( V_20 , V_21 ) ;
F_26 ( V_13 > V_21 , L_1 , V_20 -> V_25 ) ;
F_27 ( V_20 ) ;
F_28 ( V_24 , & V_20 -> V_23 ) ;
V_11:
return V_21 - V_13 ;
}
static void F_29 ( struct V_3 * V_4 , int V_21 )
{
struct V_19 * V_20 ;
F_30 (napi, &dev->napi_list, dev_list) {
if ( V_20 -> V_26 != F_17 () &&
F_31 ( & V_20 -> V_27 ) ) {
V_21 = F_23 ( V_20 , V_21 ) ;
F_32 ( & V_20 -> V_27 ) ;
}
}
}
static void F_33 ( struct V_3 * V_4 )
{
const struct V_28 * V_29 ;
struct V_14 * V_30 = F_34 ( V_4 -> V_15 ) ;
int V_21 = 0 ;
if ( F_35 ( & V_30 -> V_31 ) )
return;
if ( ! F_12 ( V_4 ) ) {
F_36 ( & V_30 -> V_31 ) ;
return;
}
V_29 = V_4 -> V_32 ;
if ( ! V_29 -> V_33 ) {
F_36 ( & V_30 -> V_31 ) ;
return;
}
V_29 -> V_33 ( V_4 ) ;
F_29 ( V_4 , V_21 ) ;
F_36 ( & V_30 -> V_31 ) ;
F_37 () ;
}
void F_38 ( struct V_3 * V_4 )
{
struct V_14 * V_30 ;
int V_34 ;
F_39 () ;
V_34 = F_40 ( & V_35 ) ;
V_30 = F_41 ( V_4 -> V_15 , & V_35 ) ;
if ( V_30 )
F_42 ( & V_30 -> V_31 ) ;
F_43 ( & V_35 , V_34 ) ;
}
void F_44 ( struct V_3 * V_4 )
{
struct V_14 * V_30 ;
F_45 () ;
V_30 = F_46 ( V_4 -> V_15 ) ;
if ( V_30 )
F_36 ( & V_30 -> V_31 ) ;
F_47 () ;
}
static void F_48 ( void )
{
struct V_1 * V_2 ;
unsigned long V_17 ;
F_49 ( & V_36 . V_37 , V_17 ) ;
while ( V_36 . V_38 < V_39 ) {
V_2 = F_50 ( V_40 , V_41 ) ;
if ( ! V_2 )
break;
F_51 ( & V_36 , V_2 ) ;
}
F_52 ( & V_36 . V_37 , V_17 ) ;
}
static void F_37 ( void )
{
unsigned long V_17 ;
struct V_42 * V_43 = & F_53 ( V_42 ) ;
if ( V_43 -> V_44 ) {
struct V_1 * V_45 ;
F_15 ( V_17 ) ;
V_45 = V_43 -> V_44 ;
V_43 -> V_44 = NULL ;
F_21 ( V_17 ) ;
while ( V_45 != NULL ) {
struct V_1 * V_2 = V_45 ;
V_45 = V_45 -> V_46 ;
if ( ! F_54 ( V_2 ) ) {
F_55 ( & V_2 -> V_47 ) ;
F_56 ( V_2 ) ;
} else {
F_57 ( V_2 ) ;
}
}
}
F_58 ( V_42 ) ;
}
static struct V_1 * F_59 ( struct V_48 * V_49 , int V_50 , int V_51 )
{
int V_52 = 0 ;
struct V_1 * V_2 ;
F_37 () ;
F_48 () ;
V_53:
V_2 = F_50 ( V_50 , V_41 ) ;
if ( ! V_2 )
V_2 = F_10 ( & V_36 ) ;
if ( ! V_2 ) {
if ( ++ V_52 < 10 ) {
F_33 ( V_49 -> V_4 ) ;
goto V_53;
}
return NULL ;
}
F_60 ( & V_2 -> V_47 , 1 ) ;
F_61 ( V_2 , V_51 ) ;
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
void F_63 ( struct V_48 * V_49 , struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_7 = V_54 ;
unsigned long V_55 ;
struct V_14 * V_15 ;
F_64 ( ! F_65 () ) ;
V_15 = F_34 ( V_49 -> V_4 -> V_15 ) ;
if ( ! V_15 || ! F_12 ( V_4 ) || ! F_11 ( V_4 ) ) {
F_66 ( V_2 ) ;
return;
}
if ( F_67 ( & V_15 -> V_6 ) == 0 && ! F_62 ( V_4 ) ) {
struct V_5 * V_6 ;
V_6 = F_68 ( V_4 , V_2 , NULL ) ;
for ( V_55 = F_69 ( 1 ) / V_56 ;
V_55 > 0 ; -- V_55 ) {
if ( F_70 ( V_4 , V_6 ) ) {
if ( ! F_71 ( V_6 ) )
V_7 = F_1 ( V_2 , V_4 , V_6 ) ;
F_20 ( V_4 , V_6 ) ;
if ( V_7 == V_8 )
break;
}
F_33 ( V_49 -> V_4 ) ;
F_72 ( V_56 ) ;
}
F_26 ( ! F_65 () ,
L_2 ,
V_4 -> V_57 , V_4 -> V_32 -> V_58 ) ;
}
if ( V_7 != V_8 ) {
F_73 ( & V_15 -> V_6 , V_2 ) ;
F_22 ( & V_15 -> V_16 , 0 ) ;
}
}
void F_74 ( struct V_48 * V_49 , const char * V_59 , int V_50 )
{
int V_60 , V_61 , V_62 ;
struct V_1 * V_2 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
static T_2 V_69 ;
struct V_70 * V_71 ;
F_64 ( ! F_65 () ) ;
V_62 = V_50 + sizeof( * V_64 ) ;
if ( V_49 -> V_72 )
V_61 = V_62 + sizeof( * V_71 ) ;
else
V_61 = V_62 + sizeof( * V_66 ) ;
V_60 = V_61 + F_75 ( V_49 -> V_4 ) ;
V_2 = F_59 ( V_49 , V_60 + V_49 -> V_4 -> V_73 ,
V_60 - V_50 ) ;
if ( ! V_2 )
return;
F_76 ( V_2 , V_59 , V_50 ) ;
F_77 ( V_2 , V_50 ) ;
F_78 ( V_2 , sizeof( * V_64 ) ) ;
F_79 ( V_2 ) ;
V_64 = F_80 ( V_2 ) ;
V_64 -> V_74 = F_81 ( V_49 -> V_75 ) ;
V_64 -> V_76 = F_81 ( V_49 -> V_77 ) ;
V_64 -> V_50 = F_81 ( V_62 ) ;
if ( V_49 -> V_72 ) {
V_64 -> V_78 = 0 ;
V_64 -> V_78 = F_82 ( & V_49 -> V_79 . V_80 ,
& V_49 -> V_81 . V_80 ,
V_62 , V_82 ,
F_83 ( V_64 , V_62 , 0 ) ) ;
if ( V_64 -> V_78 == 0 )
V_64 -> V_78 = V_83 ;
F_78 ( V_2 , sizeof( * V_71 ) ) ;
F_84 ( V_2 ) ;
V_71 = F_85 ( V_2 ) ;
F_86 ( 0x60 , ( unsigned char * ) V_71 ) ;
V_71 -> V_84 [ 0 ] = 0 ;
V_71 -> V_84 [ 1 ] = 0 ;
V_71 -> V_84 [ 2 ] = 0 ;
V_71 -> V_85 = F_81 ( sizeof( struct V_63 ) + V_50 ) ;
V_71 -> V_86 = V_82 ;
V_71 -> V_87 = 32 ;
V_71 -> V_88 = V_49 -> V_79 . V_80 ;
V_71 -> V_89 = V_49 -> V_81 . V_80 ;
V_68 = (struct V_67 * ) F_78 ( V_2 , V_90 ) ;
F_87 ( V_2 ) ;
V_2 -> V_91 = V_68 -> V_92 = F_81 ( V_93 ) ;
} else {
V_64 -> V_78 = 0 ;
V_64 -> V_78 = F_88 ( V_49 -> V_79 . V_94 ,
V_49 -> V_81 . V_94 ,
V_62 , V_82 ,
F_83 ( V_64 , V_62 , 0 ) ) ;
if ( V_64 -> V_78 == 0 )
V_64 -> V_78 = V_83 ;
F_78 ( V_2 , sizeof( * V_66 ) ) ;
F_84 ( V_2 ) ;
V_66 = F_89 ( V_2 ) ;
F_86 ( 0x45 , ( unsigned char * ) V_66 ) ;
V_66 -> V_95 = 0 ;
F_86 ( F_81 ( V_61 ) , & ( V_66 -> V_96 ) ) ;
V_66 -> V_97 = F_81 ( F_90 ( & V_69 ) ) ;
V_66 -> V_98 = 0 ;
V_66 -> V_99 = 64 ;
V_66 -> V_91 = V_82 ;
V_66 -> V_78 = 0 ;
F_86 ( V_49 -> V_79 . V_94 , & ( V_66 -> V_88 ) ) ;
F_86 ( V_49 -> V_81 . V_94 , & ( V_66 -> V_89 ) ) ;
V_66 -> V_78 = F_91 ( ( unsigned char * ) V_66 , V_66 -> V_100 ) ;
V_68 = (struct V_67 * ) F_78 ( V_2 , V_90 ) ;
F_87 ( V_2 ) ;
V_2 -> V_91 = V_68 -> V_92 = F_81 ( V_101 ) ;
}
F_92 ( V_68 -> V_102 , V_49 -> V_4 -> V_103 ) ;
F_92 ( V_68 -> V_104 , V_49 -> V_105 ) ;
V_2 -> V_4 = V_49 -> V_4 ;
F_93 ( V_49 , V_2 ) ;
}
void F_94 ( struct V_48 * V_49 )
{
F_95 ( V_49 , L_3 , V_49 -> V_75 ) ;
if ( V_49 -> V_72 )
F_95 ( V_49 , L_4 , & V_49 -> V_79 . V_80 ) ;
else
F_95 ( V_49 , L_5 , & V_49 -> V_79 . V_94 ) ;
F_95 ( V_49 , L_6 , V_49 -> V_106 ) ;
F_95 ( V_49 , L_7 , V_49 -> V_77 ) ;
if ( V_49 -> V_72 )
F_95 ( V_49 , L_8 , & V_49 -> V_81 . V_80 ) ;
else
F_95 ( V_49 , L_9 , & V_49 -> V_81 . V_94 ) ;
F_95 ( V_49 , L_10 , V_49 -> V_105 ) ;
}
static int F_96 ( const char * V_107 , union V_108 * V_109 )
{
const char * V_110 ;
if ( ! strchr ( V_107 , ':' ) &&
F_97 ( V_107 , - 1 , ( void * ) V_109 , - 1 , & V_110 ) > 0 ) {
if ( ! * V_110 )
return 0 ;
}
if ( F_98 ( V_107 , - 1 , V_109 -> V_80 . V_111 , - 1 , & V_110 ) > 0 ) {
#if F_99 ( V_112 )
if ( ! * V_110 )
return 1 ;
#else
return - 1 ;
#endif
}
return - 1 ;
}
int F_100 ( struct V_48 * V_49 , char * V_113 )
{
char * V_114 = V_113 , * V_115 ;
int V_72 ;
bool V_116 = false ;
if ( * V_114 != '@' ) {
if ( ( V_115 = strchr ( V_114 , '@' ) ) == NULL )
goto V_117;
* V_115 = 0 ;
if ( F_101 ( V_114 , 10 , & V_49 -> V_75 ) )
goto V_117;
V_114 = V_115 ;
}
V_114 ++ ;
if ( * V_114 != '/' ) {
V_116 = true ;
if ( ( V_115 = strchr ( V_114 , '/' ) ) == NULL )
goto V_117;
* V_115 = 0 ;
V_72 = F_96 ( V_114 , & V_49 -> V_79 ) ;
if ( V_72 < 0 )
goto V_117;
else
V_49 -> V_72 = ( bool ) V_72 ;
V_114 = V_115 ;
}
V_114 ++ ;
if ( * V_114 != ',' ) {
if ( ( V_115 = strchr ( V_114 , ',' ) ) == NULL )
goto V_117;
* V_115 = 0 ;
F_102 ( V_49 -> V_106 , V_114 , sizeof( V_49 -> V_106 ) ) ;
V_114 = V_115 ;
}
V_114 ++ ;
if ( * V_114 != '@' ) {
if ( ( V_115 = strchr ( V_114 , '@' ) ) == NULL )
goto V_117;
* V_115 = 0 ;
if ( * V_114 == ' ' || * V_114 == '\t' )
F_95 ( V_49 , L_11 ) ;
if ( F_101 ( V_114 , 10 , & V_49 -> V_77 ) )
goto V_117;
V_114 = V_115 ;
}
V_114 ++ ;
if ( ( V_115 = strchr ( V_114 , '/' ) ) == NULL )
goto V_117;
* V_115 = 0 ;
V_72 = F_96 ( V_114 , & V_49 -> V_81 ) ;
if ( V_72 < 0 )
goto V_117;
else if ( V_116 && V_49 -> V_72 != ( bool ) V_72 )
goto V_117;
else
V_49 -> V_72 = ( bool ) V_72 ;
V_114 = V_115 + 1 ;
if ( * V_114 != 0 ) {
if ( ! F_103 ( V_114 , V_49 -> V_105 ) )
goto V_117;
}
F_94 ( V_49 ) ;
return 0 ;
V_117:
F_95 ( V_49 , L_12 , V_114 ) ;
return - 1 ;
}
int F_104 ( struct V_48 * V_49 , struct V_3 * V_118 )
{
struct V_14 * V_15 ;
const struct V_28 * V_29 ;
int V_119 ;
V_49 -> V_4 = V_118 ;
F_102 ( V_49 -> V_106 , V_118 -> V_57 , V_120 ) ;
F_105 ( & V_49 -> V_121 , V_122 ) ;
if ( ( V_118 -> V_123 & V_124 ) ||
! V_118 -> V_32 -> V_33 ) {
F_106 ( V_49 , L_13 ,
V_49 -> V_106 ) ;
V_119 = - V_125 ;
goto V_11;
}
if ( ! V_118 -> V_15 ) {
V_15 = F_107 ( sizeof( * V_15 ) , V_126 ) ;
if ( ! V_15 ) {
V_119 = - V_127 ;
goto V_11;
}
F_108 ( & V_15 -> V_31 , 1 ) ;
F_109 ( & V_15 -> V_6 ) ;
F_110 ( & V_15 -> V_16 , F_8 ) ;
F_60 ( & V_15 -> V_128 , 1 ) ;
V_29 = V_49 -> V_4 -> V_32 ;
if ( V_29 -> V_129 ) {
V_119 = V_29 -> V_129 ( V_118 , V_15 ) ;
if ( V_119 )
goto V_130;
}
} else {
V_15 = F_111 ( V_118 -> V_15 ) ;
F_55 ( & V_15 -> V_128 ) ;
}
V_15 -> V_48 = V_49 ;
F_112 ( V_118 -> V_15 , V_15 ) ;
return 0 ;
V_130:
F_113 ( V_15 ) ;
V_11:
return V_119 ;
}
int F_114 ( struct V_48 * V_49 )
{
struct V_3 * V_118 = NULL ;
struct V_131 * V_132 ;
int V_119 ;
F_115 () ;
if ( V_49 -> V_106 ) {
struct V_133 * V_133 = V_134 -> V_135 -> V_136 ;
V_118 = F_116 ( V_133 , V_49 -> V_106 ) ;
}
if ( ! V_118 ) {
F_106 ( V_49 , L_14 , V_49 -> V_106 ) ;
V_119 = - V_137 ;
goto V_138;
}
F_117 ( V_118 ) ;
if ( F_118 ( V_118 ) ) {
F_106 ( V_49 , L_15 , V_49 -> V_106 ) ;
V_119 = - V_139 ;
goto V_140;
}
if ( ! F_12 ( V_118 ) ) {
unsigned long V_141 , V_142 ;
F_95 ( V_49 , L_16 , V_49 -> V_106 ) ;
V_119 = F_119 ( V_118 ) ;
if ( V_119 ) {
F_106 ( V_49 , L_17 , V_118 -> V_57 ) ;
goto V_140;
}
F_120 () ;
V_142 = V_143 + V_18 / 10 ;
V_141 = V_143 + V_144 * V_18 ;
while ( ! F_121 ( V_118 ) ) {
if ( F_122 ( V_143 , V_141 ) ) {
F_123 ( V_49 , L_18 ) ;
break;
}
F_124 ( 1 ) ;
}
if ( F_125 ( V_143 , V_142 ) ) {
F_123 ( V_49 , L_19 ) ;
F_124 ( 4000 ) ;
}
F_115 () ;
}
if ( ! V_49 -> V_79 . V_94 ) {
if ( ! V_49 -> V_72 ) {
V_132 = F_126 ( V_118 ) ;
if ( ! V_132 || ! V_132 -> V_145 ) {
F_106 ( V_49 , L_20 ,
V_49 -> V_106 ) ;
V_119 = - V_146 ;
goto V_140;
}
V_49 -> V_79 . V_94 = V_132 -> V_145 -> V_147 ;
F_95 ( V_49 , L_21 , & V_49 -> V_79 . V_94 ) ;
} else {
#if F_99 ( V_112 )
struct V_148 * V_149 ;
V_119 = - V_146 ;
V_149 = F_127 ( V_118 ) ;
if ( V_149 ) {
struct V_150 * V_151 ;
F_128 ( & V_149 -> V_37 ) ;
F_30 (ifp, &idev->addr_list, if_list) {
if ( F_129 ( & V_151 -> V_109 ) & V_152 )
continue;
V_49 -> V_79 . V_80 = V_151 -> V_109 ;
V_119 = 0 ;
break;
}
F_130 ( & V_149 -> V_37 ) ;
}
if ( V_119 ) {
F_106 ( V_49 , L_22 ,
V_49 -> V_106 ) ;
goto V_140;
} else
F_95 ( V_49 , L_23 , & V_49 -> V_79 . V_80 ) ;
#else
F_106 ( V_49 , L_24 ,
V_49 -> V_106 ) ;
V_119 = - V_153 ;
goto V_140;
#endif
}
}
F_48 () ;
V_119 = F_104 ( V_49 , V_118 ) ;
if ( V_119 )
goto V_140;
F_120 () ;
return 0 ;
V_140:
F_131 ( V_118 ) ;
V_138:
F_120 () ;
return V_119 ;
}
static int T_3 F_132 ( void )
{
F_109 ( & V_36 ) ;
return 0 ;
}
static void F_133 ( struct V_154 * V_154 )
{
struct V_14 * V_15 =
F_9 ( V_154 , struct V_14 , V_155 ) ;
F_134 ( & V_15 -> V_6 ) ;
F_135 ( & V_15 -> V_16 ) ;
F_136 ( & V_15 -> V_6 ) ;
F_135 ( & V_15 -> V_16 ) ;
F_113 ( V_15 ) ;
}
void F_137 ( struct V_48 * V_49 )
{
struct V_14 * V_15 ;
V_15 = F_111 ( V_49 -> V_4 -> V_15 ) ;
if ( ! V_15 )
return;
F_138 ( & V_35 ) ;
if ( F_139 ( & V_15 -> V_128 ) ) {
const struct V_28 * V_29 ;
V_29 = V_49 -> V_4 -> V_32 ;
if ( V_29 -> V_156 )
V_29 -> V_156 ( V_49 -> V_4 ) ;
F_140 ( V_49 -> V_4 -> V_15 , NULL ) ;
F_141 ( & V_15 -> V_155 , F_133 ) ;
} else
F_140 ( V_49 -> V_4 -> V_15 , NULL ) ;
}
static void V_122 ( struct V_12 * V_13 )
{
struct V_48 * V_49 = F_9 ( V_13 , struct V_48 , V_121 ) ;
F_115 () ;
F_137 ( V_49 ) ;
F_120 () ;
F_113 ( V_49 ) ;
}
void F_142 ( struct V_48 * V_49 )
{
F_143 ( & V_49 -> V_121 ) ;
}
void F_144 ( struct V_48 * V_49 )
{
F_115 () ;
if ( ! V_49 -> V_4 )
goto V_11;
F_137 ( V_49 ) ;
F_131 ( V_49 -> V_4 ) ;
V_49 -> V_4 = NULL ;
V_11:
F_120 () ;
}
