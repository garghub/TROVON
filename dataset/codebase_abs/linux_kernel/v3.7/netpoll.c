static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 . V_2 ) ;
struct V_6 * V_7 ;
unsigned long V_8 ;
while ( ( V_7 = F_3 ( & V_4 -> V_9 ) ) ) {
struct V_10 * V_11 = V_7 -> V_11 ;
const struct V_12 * V_13 = V_11 -> V_14 ;
struct V_15 * V_9 ;
if ( ! F_4 ( V_11 ) || ! F_5 ( V_11 ) ) {
F_6 ( V_7 ) ;
continue;
}
V_9 = F_7 ( V_11 , F_8 ( V_7 ) ) ;
F_9 ( V_8 ) ;
F_10 ( V_9 , F_11 () ) ;
if ( F_12 ( V_9 ) ||
V_13 -> V_16 ( V_7 , V_11 ) != V_17 ) {
F_13 ( & V_4 -> V_9 , V_7 ) ;
F_14 ( V_9 ) ;
F_15 ( V_8 ) ;
F_16 ( & V_4 -> V_5 , V_18 / 10 ) ;
return;
}
F_14 ( V_9 ) ;
F_15 ( V_8 ) ;
}
}
static T_1 F_17 ( struct V_6 * V_7 , struct V_19 * V_20 ,
unsigned short V_21 , T_2 V_22 , T_2 V_23 )
{
T_3 V_24 ;
if ( V_20 -> V_25 == 0 || F_18 ( V_7 ) )
return 0 ;
V_24 = F_19 ( V_22 , V_23 , V_21 , V_26 , 0 ) ;
if ( V_7 -> V_27 == V_28 &&
! F_20 ( F_21 ( V_24 , V_7 -> V_29 ) ) )
return 0 ;
V_7 -> V_29 = V_24 ;
return F_22 ( V_7 ) ;
}
static int F_23 ( struct V_3 * V_4 ,
struct V_30 * V_31 , int V_32 )
{
int V_2 ;
if ( ! F_24 ( V_33 , & V_31 -> V_34 ) )
return V_32 ;
V_4 -> V_35 |= V_36 ;
F_25 ( & V_37 ) ;
F_26 ( V_38 , & V_31 -> V_34 ) ;
V_2 = V_31 -> V_39 ( V_31 , V_32 ) ;
F_27 ( V_31 ) ;
F_28 ( V_38 , & V_31 -> V_34 ) ;
F_29 ( & V_37 ) ;
V_4 -> V_35 &= ~ V_36 ;
return V_32 - V_2 ;
}
static void F_30 ( struct V_10 * V_11 )
{
struct V_30 * V_31 ;
int V_32 = 16 ;
F_31 (napi, &dev->napi_list, dev_list) {
if ( V_31 -> V_40 != F_11 () &&
F_32 ( & V_31 -> V_41 ) ) {
V_32 = F_23 ( F_33 ( V_11 -> V_4 ) ,
V_31 , V_32 ) ;
F_34 ( & V_31 -> V_41 ) ;
if ( ! V_32 )
break;
}
}
}
static void F_35 ( struct V_3 * V_42 )
{
if ( V_42 ) {
struct V_6 * V_7 ;
while ( ( V_7 = F_3 ( & V_42 -> V_43 ) ) )
F_36 ( V_7 , V_42 ) ;
}
}
static void F_37 ( struct V_10 * V_11 )
{
const struct V_12 * V_13 ;
struct V_3 * V_44 = F_33 ( V_11 -> V_4 ) ;
if ( ! V_11 || ! F_5 ( V_11 ) )
return;
V_13 = V_11 -> V_14 ;
if ( ! V_13 -> V_45 )
return;
V_13 -> V_45 ( V_11 ) ;
F_30 ( V_11 ) ;
if ( V_11 -> V_8 & V_46 ) {
if ( V_44 ) {
struct V_10 * V_47 = V_11 -> V_48 ;
struct V_6 * V_7 ;
struct V_3 * V_49 = F_33 ( V_47 -> V_4 ) ;
while ( ( V_7 = F_3 ( & V_44 -> V_43 ) ) ) {
V_7 -> V_11 = V_47 ;
F_38 ( & V_49 -> V_43 , V_7 ) ;
}
}
}
F_35 ( V_44 ) ;
F_39 () ;
}
static void F_40 ( void )
{
struct V_6 * V_7 ;
unsigned long V_8 ;
F_41 ( & V_50 . V_51 , V_8 ) ;
while ( V_50 . V_52 < V_53 ) {
V_7 = F_42 ( V_54 , V_55 ) ;
if ( ! V_7 )
break;
F_43 ( & V_50 , V_7 ) ;
}
F_44 ( & V_50 . V_51 , V_8 ) ;
}
static void F_39 ( void )
{
unsigned long V_8 ;
struct V_56 * V_57 = & F_45 ( V_56 ) ;
if ( V_57 -> V_58 ) {
struct V_6 * V_59 ;
F_9 ( V_8 ) ;
V_59 = V_57 -> V_58 ;
V_57 -> V_58 = NULL ;
F_15 ( V_8 ) ;
while ( V_59 != NULL ) {
struct V_6 * V_7 = V_59 ;
V_59 = V_59 -> V_60 ;
if ( V_7 -> V_61 ) {
F_25 ( & V_7 -> V_62 ) ;
F_46 ( V_7 ) ;
} else {
F_6 ( V_7 ) ;
}
}
}
F_47 ( V_56 ) ;
}
static struct V_6 * F_48 ( struct V_63 * V_64 , int V_65 , int V_66 )
{
int V_67 = 0 ;
struct V_6 * V_7 ;
F_39 () ;
F_40 () ;
V_68:
V_7 = F_42 ( V_65 , V_55 ) ;
if ( ! V_7 )
V_7 = F_3 ( & V_50 ) ;
if ( ! V_7 ) {
if ( ++ V_67 < 10 ) {
F_37 ( V_64 -> V_11 ) ;
goto V_68;
}
return NULL ;
}
F_49 ( & V_7 -> V_62 , 1 ) ;
F_50 ( V_7 , V_66 ) ;
return V_7 ;
}
static int F_51 ( struct V_10 * V_11 )
{
struct V_30 * V_31 ;
F_31 (napi, &dev->napi_list, dev_list) {
if ( V_31 -> V_40 == F_11 () )
return 1 ;
}
return 0 ;
}
void F_52 ( struct V_63 * V_64 , struct V_6 * V_7 ,
struct V_10 * V_11 )
{
int V_69 = V_70 ;
unsigned long V_71 ;
const struct V_12 * V_13 = V_11 -> V_14 ;
struct V_3 * V_4 ;
F_53 ( ! F_54 () ) ;
V_4 = F_33 ( V_64 -> V_11 -> V_4 ) ;
if ( ! V_4 || ! F_5 ( V_11 ) || ! F_4 ( V_11 ) ) {
F_6 ( V_7 ) ;
return;
}
if ( F_55 ( & V_4 -> V_9 ) == 0 && ! F_51 ( V_11 ) ) {
struct V_15 * V_9 ;
V_9 = F_56 ( V_11 , V_7 ) ;
for ( V_71 = F_57 ( 1 ) / V_72 ;
V_71 > 0 ; -- V_71 ) {
if ( F_58 ( V_9 ) ) {
if ( ! F_59 ( V_9 ) ) {
if ( F_60 ( V_7 ) &&
! ( F_61 ( V_7 ) & V_73 ) ) {
V_7 = F_62 ( V_7 , F_63 ( V_7 ) ) ;
if ( F_64 ( ! V_7 ) )
break;
V_7 -> V_74 = 0 ;
}
V_69 = V_13 -> V_16 ( V_7 , V_11 ) ;
if ( V_69 == V_17 )
F_65 ( V_9 ) ;
}
F_14 ( V_9 ) ;
if ( V_69 == V_17 )
break;
}
F_37 ( V_64 -> V_11 ) ;
F_66 ( V_72 ) ;
}
F_67 ( ! F_54 () ,
L_1 ,
V_11 -> V_75 , V_13 -> V_16 ) ;
}
if ( V_69 != V_17 ) {
F_38 ( & V_4 -> V_9 , V_7 ) ;
F_16 ( & V_4 -> V_5 , 0 ) ;
}
}
void F_68 ( struct V_63 * V_64 , const char * V_76 , int V_65 )
{
int V_77 , V_78 , V_79 ;
struct V_6 * V_7 ;
struct V_19 * V_80 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
static T_4 V_85 ;
V_79 = V_65 + sizeof( * V_80 ) ;
V_78 = V_79 + sizeof( * V_82 ) ;
V_77 = V_78 + F_69 ( V_64 -> V_11 ) ;
V_7 = F_48 ( V_64 , V_77 + V_64 -> V_11 -> V_86 ,
V_77 - V_65 ) ;
if ( ! V_7 )
return;
F_70 ( V_7 , V_76 , V_65 ) ;
F_71 ( V_7 , V_65 ) ;
F_72 ( V_7 , sizeof( * V_80 ) ) ;
F_73 ( V_7 ) ;
V_80 = F_74 ( V_7 ) ;
V_80 -> V_87 = F_75 ( V_64 -> V_88 ) ;
V_80 -> V_89 = F_75 ( V_64 -> V_90 ) ;
V_80 -> V_65 = F_75 ( V_79 ) ;
V_80 -> V_25 = 0 ;
V_80 -> V_25 = F_76 ( V_64 -> V_91 ,
V_64 -> V_92 ,
V_79 , V_26 ,
F_77 ( V_80 , V_79 , 0 ) ) ;
if ( V_80 -> V_25 == 0 )
V_80 -> V_25 = V_93 ;
F_72 ( V_7 , sizeof( * V_82 ) ) ;
F_78 ( V_7 ) ;
V_82 = F_79 ( V_7 ) ;
F_80 ( 0x45 , ( unsigned char * ) V_82 ) ;
V_82 -> V_94 = 0 ;
F_80 ( F_75 ( V_78 ) , & ( V_82 -> V_95 ) ) ;
V_82 -> V_96 = F_75 ( F_81 ( & V_85 ) ) ;
V_82 -> V_97 = 0 ;
V_82 -> V_98 = 64 ;
V_82 -> V_99 = V_26 ;
V_82 -> V_25 = 0 ;
F_80 ( V_64 -> V_91 , & ( V_82 -> V_22 ) ) ;
F_80 ( V_64 -> V_92 , & ( V_82 -> V_23 ) ) ;
V_82 -> V_25 = F_82 ( ( unsigned char * ) V_82 , V_82 -> V_100 ) ;
V_84 = (struct V_83 * ) F_72 ( V_7 , V_101 ) ;
F_83 ( V_7 ) ;
V_7 -> V_99 = V_84 -> V_102 = F_75 ( V_103 ) ;
memcpy ( V_84 -> V_104 , V_64 -> V_11 -> V_105 , V_106 ) ;
memcpy ( V_84 -> V_107 , V_64 -> V_108 , V_106 ) ;
V_7 -> V_11 = V_64 -> V_11 ;
F_84 ( V_64 , V_7 ) ;
}
static void F_36 ( struct V_6 * V_7 , struct V_3 * V_4 )
{
struct V_109 * V_110 ;
unsigned char * V_111 ;
int V_112 , type = V_113 , V_114 = V_115 ;
T_2 V_116 , V_117 ;
unsigned char * V_118 ;
struct V_6 * V_119 ;
struct V_63 * V_64 , * V_120 ;
unsigned long V_8 ;
int V_121 , V_122 ;
int V_123 = 0 ;
if ( F_85 ( & V_4 -> V_124 ) )
return;
F_41 ( & V_4 -> V_125 , V_8 ) ;
F_86 (np, tmp, &npinfo->rx_np, rx) {
if ( V_64 -> V_11 == V_7 -> V_11 )
V_123 ++ ;
}
F_44 ( & V_4 -> V_125 , V_8 ) ;
if ( ! V_123 )
return;
if ( V_7 -> V_11 -> V_8 & V_126 )
return;
if ( ! F_87 ( V_7 , F_88 ( V_7 -> V_11 ) ) )
return;
F_78 ( V_7 ) ;
F_73 ( V_7 ) ;
V_110 = F_89 ( V_7 ) ;
if ( ( V_110 -> V_127 != F_75 ( V_128 ) &&
V_110 -> V_127 != F_75 ( V_129 ) ) ||
V_110 -> V_130 != F_75 ( V_103 ) ||
V_110 -> V_131 != F_75 ( V_132 ) )
return;
V_111 = ( unsigned char * ) ( V_110 + 1 ) ;
V_118 = V_111 ;
V_111 += V_7 -> V_11 -> V_133 ;
memcpy ( & V_116 , V_111 , 4 ) ;
V_111 += 4 ;
V_111 += V_7 -> V_11 -> V_133 ;
memcpy ( & V_117 , V_111 , 4 ) ;
if ( F_90 ( V_117 ) || F_91 ( V_117 ) )
return;
V_112 = F_88 ( V_7 -> V_11 ) ;
F_41 ( & V_4 -> V_125 , V_8 ) ;
F_86 (np, tmp, &npinfo->rx_np, rx) {
if ( V_117 != V_64 -> V_91 )
continue;
V_121 = F_69 ( V_64 -> V_11 ) ;
V_122 = V_64 -> V_11 -> V_86 ;
V_119 = F_48 ( V_64 , V_112 + V_121 + V_122 , V_121 ) ;
if ( ! V_119 )
continue;
F_78 ( V_119 ) ;
V_110 = (struct V_109 * ) F_71 ( V_119 , V_112 ) ;
V_119 -> V_11 = V_7 -> V_11 ;
V_119 -> V_99 = F_75 ( V_115 ) ;
if ( F_92 ( V_119 , V_7 -> V_11 , V_114 ,
V_118 , V_64 -> V_11 -> V_105 ,
V_119 -> V_65 ) < 0 ) {
F_93 ( V_119 ) ;
continue;
}
V_110 -> V_127 = F_75 ( V_64 -> V_11 -> type ) ;
V_110 -> V_130 = F_75 ( V_103 ) ;
V_110 -> V_134 = V_64 -> V_11 -> V_133 ;
V_110 -> V_135 = 4 ;
V_110 -> V_131 = F_75 ( type ) ;
V_111 = ( unsigned char * ) ( V_110 + 1 ) ;
memcpy ( V_111 , V_64 -> V_11 -> V_105 , V_64 -> V_11 -> V_133 ) ;
V_111 += V_64 -> V_11 -> V_133 ;
memcpy ( V_111 , & V_117 , 4 ) ;
V_111 += 4 ;
memcpy ( V_111 , V_118 , V_64 -> V_11 -> V_133 ) ;
V_111 += V_64 -> V_11 -> V_133 ;
memcpy ( V_111 , & V_116 , 4 ) ;
F_84 ( V_64 , V_119 ) ;
break;
}
F_44 ( & V_4 -> V_125 , V_8 ) ;
}
int F_94 ( struct V_6 * V_7 , struct V_3 * V_4 )
{
int V_136 , V_65 , V_21 ;
int V_123 = 0 ;
const struct V_81 * V_82 ;
struct V_19 * V_20 ;
struct V_63 * V_64 , * V_120 ;
if ( F_85 ( & V_4 -> V_124 ) )
goto V_137;
if ( V_7 -> V_11 -> type != V_128 )
goto V_137;
if ( V_7 -> V_99 == F_75 ( V_115 ) &&
F_95 ( & V_37 ) ) {
F_38 ( & V_4 -> V_43 , V_7 ) ;
return 1 ;
}
if ( V_7 -> V_99 == F_96 ( V_138 ) ) {
V_7 = F_97 ( V_7 ) ;
if ( F_64 ( ! V_7 ) )
goto V_137;
}
V_136 = F_98 ( F_99 ( V_7 ) -> V_102 ) ;
if ( V_136 != V_103 )
goto V_137;
if ( V_7 -> V_139 == V_140 )
goto V_137;
if ( F_100 ( V_7 ) )
goto V_137;
if ( ! F_87 ( V_7 , sizeof( struct V_81 ) ) )
goto V_137;
V_82 = (struct V_81 * ) V_7 -> V_141 ;
if ( V_82 -> V_100 < 5 || V_82 -> V_142 != 4 )
goto V_137;
if ( ! F_87 ( V_7 , V_82 -> V_100 * 4 ) )
goto V_137;
V_82 = (struct V_81 * ) V_7 -> V_141 ;
if ( F_82 ( ( V_143 * ) V_82 , V_82 -> V_100 ) != 0 )
goto V_137;
V_65 = F_98 ( V_82 -> V_95 ) ;
if ( V_7 -> V_65 < V_65 || V_65 < V_82 -> V_100 * 4 )
goto V_137;
if ( F_101 ( V_7 , V_65 ) )
goto V_137;
V_82 = (struct V_81 * ) V_7 -> V_141 ;
if ( V_82 -> V_99 != V_26 )
goto V_137;
V_65 -= V_82 -> V_100 * 4 ;
V_20 = (struct V_19 * ) ( ( ( char * ) V_82 ) + V_82 -> V_100 * 4 ) ;
V_21 = F_98 ( V_20 -> V_65 ) ;
if ( V_21 != V_65 )
goto V_137;
if ( F_17 ( V_7 , V_20 , V_21 , V_82 -> V_22 , V_82 -> V_23 ) )
goto V_137;
F_86 (np, tmp, &npinfo->rx_np, rx) {
if ( V_64 -> V_91 && V_64 -> V_91 != V_82 -> V_23 )
continue;
if ( V_64 -> V_92 && V_64 -> V_92 != V_82 -> V_22 )
continue;
if ( V_64 -> V_88 && V_64 -> V_88 != F_98 ( V_20 -> V_89 ) )
continue;
V_64 -> V_144 ( V_64 , F_98 ( V_20 -> V_87 ) ,
( char * ) ( V_20 + 1 ) ,
V_21 - sizeof( struct V_19 ) ) ;
V_123 ++ ;
}
if ( ! V_123 )
goto V_137;
F_93 ( V_7 ) ;
return 1 ;
V_137:
if ( F_95 ( & V_37 ) ) {
F_93 ( V_7 ) ;
return 1 ;
}
return 0 ;
}
void F_102 ( struct V_63 * V_64 )
{
F_103 ( V_64 , L_2 , V_64 -> V_88 ) ;
F_103 ( V_64 , L_3 , & V_64 -> V_91 ) ;
F_103 ( V_64 , L_4 , V_64 -> V_145 ) ;
F_103 ( V_64 , L_5 , V_64 -> V_90 ) ;
F_103 ( V_64 , L_6 , & V_64 -> V_92 ) ;
F_103 ( V_64 , L_7 , V_64 -> V_108 ) ;
}
int F_104 ( struct V_63 * V_64 , char * V_146 )
{
char * V_147 = V_146 , * V_148 ;
if ( * V_147 != '@' ) {
if ( ( V_148 = strchr ( V_147 , '@' ) ) == NULL )
goto V_149;
* V_148 = 0 ;
V_64 -> V_88 = F_105 ( V_147 , NULL , 10 ) ;
V_147 = V_148 ;
}
V_147 ++ ;
if ( * V_147 != '/' ) {
if ( ( V_148 = strchr ( V_147 , '/' ) ) == NULL )
goto V_149;
* V_148 = 0 ;
V_64 -> V_91 = F_106 ( V_147 ) ;
V_147 = V_148 ;
}
V_147 ++ ;
if ( * V_147 != ',' ) {
if ( ( V_148 = strchr ( V_147 , ',' ) ) == NULL )
goto V_149;
* V_148 = 0 ;
F_107 ( V_64 -> V_145 , V_147 , sizeof( V_64 -> V_145 ) ) ;
V_147 = V_148 ;
}
V_147 ++ ;
if ( * V_147 != '@' ) {
if ( ( V_148 = strchr ( V_147 , '@' ) ) == NULL )
goto V_149;
* V_148 = 0 ;
if ( * V_147 == ' ' || * V_147 == '\t' )
F_103 ( V_64 , L_8 ) ;
V_64 -> V_90 = F_105 ( V_147 , NULL , 10 ) ;
V_147 = V_148 ;
}
V_147 ++ ;
if ( ( V_148 = strchr ( V_147 , '/' ) ) == NULL )
goto V_149;
* V_148 = 0 ;
V_64 -> V_92 = F_106 ( V_147 ) ;
V_147 = V_148 + 1 ;
if ( * V_147 != 0 ) {
if ( ! F_108 ( V_147 , V_64 -> V_108 ) )
goto V_149;
}
F_102 ( V_64 ) ;
return 0 ;
V_149:
F_103 ( V_64 , L_9 , V_147 ) ;
return - 1 ;
}
int F_109 ( struct V_63 * V_64 , struct V_10 * V_150 , T_5 V_151 )
{
struct V_3 * V_4 ;
const struct V_12 * V_13 ;
unsigned long V_8 ;
int V_152 ;
V_64 -> V_11 = V_150 ;
F_107 ( V_64 -> V_145 , V_150 -> V_75 , V_153 ) ;
if ( ( V_150 -> V_154 & V_155 ) ||
! V_150 -> V_14 -> V_45 ) {
F_110 ( V_64 , L_10 ,
V_64 -> V_145 ) ;
V_152 = - V_156 ;
goto V_137;
}
if ( ! V_150 -> V_4 ) {
V_4 = F_111 ( sizeof( * V_4 ) , V_151 ) ;
if ( ! V_4 ) {
V_152 = - V_157 ;
goto V_137;
}
V_4 -> V_35 = 0 ;
F_112 ( & V_4 -> V_124 ) ;
F_113 ( & V_4 -> V_125 ) ;
F_114 ( & V_4 -> V_43 ) ;
F_114 ( & V_4 -> V_9 ) ;
F_115 ( & V_4 -> V_5 , F_1 ) ;
F_49 ( & V_4 -> V_158 , 1 ) ;
V_13 = V_64 -> V_11 -> V_14 ;
if ( V_13 -> V_159 ) {
V_152 = V_13 -> V_159 ( V_150 , V_4 , V_151 ) ;
if ( V_152 )
goto V_160;
}
} else {
V_4 = V_150 -> V_4 ;
F_25 ( & V_4 -> V_158 ) ;
}
V_4 -> V_63 = V_64 ;
if ( V_64 -> V_144 ) {
F_41 ( & V_4 -> V_125 , V_8 ) ;
V_4 -> V_35 |= V_161 ;
F_116 ( & V_64 -> V_162 , & V_4 -> V_124 ) ;
F_44 ( & V_4 -> V_125 , V_8 ) ;
}
F_117 ( V_150 -> V_4 , V_4 ) ;
return 0 ;
V_160:
F_118 ( V_4 ) ;
V_137:
return V_152 ;
}
int F_119 ( struct V_63 * V_64 )
{
struct V_10 * V_150 = NULL ;
struct V_163 * V_164 ;
int V_152 ;
if ( V_64 -> V_145 )
V_150 = F_120 ( & V_165 , V_64 -> V_145 ) ;
if ( ! V_150 ) {
F_110 ( V_64 , L_11 , V_64 -> V_145 ) ;
return - V_166 ;
}
if ( V_150 -> V_48 ) {
F_110 ( V_64 , L_12 , V_64 -> V_145 ) ;
V_152 = - V_167 ;
goto V_168;
}
if ( ! F_5 ( V_150 ) ) {
unsigned long V_169 , V_170 ;
F_103 ( V_64 , L_13 , V_64 -> V_145 ) ;
F_121 () ;
V_152 = F_122 ( V_150 ) ;
F_123 () ;
if ( V_152 ) {
F_110 ( V_64 , L_14 , V_150 -> V_75 ) ;
goto V_168;
}
V_170 = V_171 + V_18 / 10 ;
V_169 = V_171 + V_172 * V_18 ;
while ( ! F_124 ( V_150 ) ) {
if ( F_125 ( V_171 , V_169 ) ) {
F_126 ( V_64 , L_15 ) ;
break;
}
F_127 ( 1 ) ;
}
if ( F_128 ( V_171 , V_170 ) ) {
F_126 ( V_64 , L_16 ) ;
F_127 ( 4000 ) ;
}
}
if ( ! V_64 -> V_91 ) {
F_129 () ;
V_164 = F_130 ( V_150 ) ;
if ( ! V_164 || ! V_164 -> V_173 ) {
F_131 () ;
F_110 ( V_64 , L_17 ,
V_64 -> V_145 ) ;
V_152 = - V_174 ;
goto V_168;
}
V_64 -> V_91 = V_164 -> V_173 -> V_175 ;
F_131 () ;
F_103 ( V_64 , L_3 , & V_64 -> V_91 ) ;
}
F_40 () ;
F_121 () ;
V_152 = F_109 ( V_64 , V_150 , V_176 ) ;
F_123 () ;
if ( V_152 )
goto V_168;
return 0 ;
V_168:
F_132 ( V_150 ) ;
return V_152 ;
}
static int T_6 F_133 ( void )
{
F_114 ( & V_50 ) ;
return 0 ;
}
static void F_134 ( struct V_177 * V_177 )
{
struct V_3 * V_4 =
F_2 ( V_177 , struct V_3 , V_178 ) ;
F_135 ( & V_4 -> V_43 ) ;
F_135 ( & V_4 -> V_9 ) ;
F_136 ( & V_4 -> V_5 ) ;
F_137 ( & V_4 -> V_9 ) ;
F_136 ( & V_4 -> V_5 ) ;
F_118 ( V_4 ) ;
}
void F_138 ( struct V_63 * V_64 )
{
struct V_3 * V_4 ;
unsigned long V_8 ;
V_4 = V_64 -> V_11 -> V_4 ;
if ( ! V_4 )
return;
if ( ! F_85 ( & V_4 -> V_124 ) ) {
F_41 ( & V_4 -> V_125 , V_8 ) ;
F_139 ( & V_64 -> V_162 ) ;
if ( F_85 ( & V_4 -> V_124 ) )
V_4 -> V_35 &= ~ V_161 ;
F_44 ( & V_4 -> V_125 , V_8 ) ;
}
if ( F_140 ( & V_4 -> V_158 ) ) {
const struct V_12 * V_13 ;
V_13 = V_64 -> V_11 -> V_14 ;
if ( V_13 -> V_179 )
V_13 -> V_179 ( V_64 -> V_11 ) ;
F_141 ( V_64 -> V_11 -> V_4 , NULL ) ;
F_142 ( & V_4 -> V_178 , F_134 ) ;
}
}
static void F_143 ( struct V_177 * V_177 )
{
struct V_63 * V_64 = F_2 ( V_177 , struct V_63 , V_178 ) ;
F_138 ( V_64 ) ;
F_118 ( V_64 ) ;
}
void F_144 ( struct V_63 * V_64 )
{
F_142 ( & V_64 -> V_178 , F_143 ) ;
}
void F_145 ( struct V_63 * V_64 )
{
if ( ! V_64 -> V_11 )
return;
F_121 () ;
F_138 ( V_64 ) ;
F_123 () ;
F_132 ( V_64 -> V_11 ) ;
V_64 -> V_11 = NULL ;
}
int F_146 ( void )
{
return F_95 ( & V_37 ) ;
}
void F_147 ( int V_180 )
{
if ( V_180 )
F_25 ( & V_37 ) ;
else
F_29 ( & V_37 ) ;
}
