struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_1 ;
if ( ! V_3 )
return F_2 ( V_2 , 1 ) ;
V_1 = F_3 ( V_2 , 1 , V_3 ) ;
if ( ! V_1 )
return NULL ;
return V_1 ;
}
int F_4 ( struct V_4 * V_5 , enum V_6 V_7 )
{
int V_8 ;
F_5 ( & V_5 -> V_9 ) ;
V_8 = ( V_5 -> V_10 . V_11 >= V_7 ) ;
if ( ! V_8 ) {
if ( F_6 ( & V_5 -> V_9 ) )
F_7 ( & V_5 -> V_12 ) ;
}
return V_8 ;
}
void F_8 ( struct V_13 * V_14 , unsigned int V_15 ,
unsigned int V_16 )
{
struct V_17 * V_18 ;
struct V_17 * V_19 = NULL ;
int V_20 = 0 ;
int V_21 = 0 ;
F_9 ( & V_14 -> V_22 ) ;
F_10 (r, &tconn->transfer_log, tl_requests) {
const unsigned V_23 = V_18 -> V_24 ;
if ( ! V_19 ) {
if ( ! ( V_23 & V_25 ) )
continue;
if ( ! ( V_23 & V_26 ) )
continue;
if ( V_23 & V_27 )
continue;
V_19 = V_18 ;
V_20 = V_19 -> V_28 ;
V_21 ++ ;
} else {
if ( V_18 -> V_28 != V_20 )
break;
if ( ! ( V_23 & V_25 ) )
continue;
V_21 ++ ;
}
}
if ( V_19 == NULL ) {
F_11 ( V_14 , L_1 ,
V_15 ) ;
goto V_29;
}
if ( V_20 != V_15 ) {
F_11 ( V_14 , L_2 ,
V_15 , V_20 ) ;
goto V_29;
}
if ( V_21 != V_16 ) {
F_11 ( V_14 , L_3 ,
V_15 , V_16 , V_21 ) ;
goto V_29;
}
F_10 (req, &tconn->transfer_log, tl_requests)
if ( V_19 -> V_28 == V_20 )
break;
F_12 (req, r, &tconn->transfer_log, tl_requests) {
if ( V_19 -> V_28 != V_20 )
break;
F_13 ( V_19 , V_30 ) ;
}
F_14 ( & V_14 -> V_22 ) ;
return;
V_29:
F_14 ( & V_14 -> V_22 ) ;
F_15 ( V_14 , F_16 ( V_31 , V_32 ) , V_33 ) ;
}
void F_17 ( struct V_13 * V_14 , enum V_34 V_35 )
{
struct V_17 * V_19 , * V_18 ;
F_18 (req, r, &tconn->transfer_log, tl_requests)
F_13 ( V_19 , V_35 ) ;
}
void F_19 ( struct V_13 * V_14 , enum V_34 V_35 )
{
F_9 ( & V_14 -> V_22 ) ;
F_17 ( V_14 , V_35 ) ;
F_14 ( & V_14 -> V_22 ) ;
}
void F_20 ( struct V_13 * V_14 )
{
F_19 ( V_14 , V_36 ) ;
}
void F_21 ( struct V_4 * V_5 )
{
struct V_13 * V_14 = V_5 -> V_14 ;
struct V_17 * V_19 , * V_18 ;
F_9 ( & V_14 -> V_22 ) ;
F_18 (req, r, &tconn->transfer_log, tl_requests) {
if ( ! ( V_19 -> V_24 & V_37 ) )
continue;
if ( V_19 -> V_38 . V_5 != V_5 )
continue;
F_13 ( V_19 , V_39 ) ;
}
F_14 ( & V_14 -> V_22 ) ;
}
static int F_22 ( void * V_40 )
{
struct V_41 * V_42 = (struct V_41 * ) V_40 ;
struct V_13 * V_14 = V_42 -> V_14 ;
unsigned long V_43 ;
int V_44 ;
snprintf ( V_45 -> V_46 , sizeof( V_45 -> V_46 ) , L_4 ,
V_42 -> V_47 [ 0 ] , V_42 -> V_14 -> V_47 ) ;
V_48:
V_44 = V_42 -> V_49 ( V_42 ) ;
F_23 ( & V_42 -> V_50 , V_43 ) ;
if ( V_42 -> V_51 == V_52 ) {
F_24 ( V_14 , L_5 , V_42 -> V_47 ) ;
V_42 -> V_51 = V_53 ;
F_25 ( & V_42 -> V_50 , V_43 ) ;
goto V_48;
}
V_42 -> V_54 = NULL ;
V_42 -> V_51 = V_55 ;
F_26 () ;
F_27 ( & V_42 -> V_56 ) ;
F_25 ( & V_42 -> V_50 , V_43 ) ;
F_24 ( V_14 , L_6 , V_45 -> V_46 ) ;
F_28 ( & V_14 -> V_57 , & V_58 ) ;
F_29 ( V_59 ) ;
return V_44 ;
}
static void F_30 ( struct V_13 * V_14 , struct V_41 * V_42 ,
int (* F_31) ( struct V_41 * ) , char * V_47 )
{
F_32 ( & V_42 -> V_50 ) ;
V_42 -> V_54 = NULL ;
V_42 -> V_51 = V_55 ;
V_42 -> V_49 = F_31 ;
V_42 -> V_14 = V_14 ;
strncpy ( V_42 -> V_47 , V_47 , F_33 ( V_42 -> V_47 ) ) ;
}
int F_34 ( struct V_41 * V_42 )
{
struct V_13 * V_14 = V_42 -> V_14 ;
struct V_60 * V_61 ;
unsigned long V_43 ;
F_23 ( & V_42 -> V_50 , V_43 ) ;
switch ( V_42 -> V_51 ) {
case V_55 :
F_24 ( V_14 , L_7 ,
V_42 -> V_47 , V_45 -> V_46 , V_45 -> V_62 ) ;
if ( ! F_35 ( V_59 ) ) {
F_11 ( V_14 , L_8 ) ;
F_25 ( & V_42 -> V_50 , V_43 ) ;
return false ;
}
F_36 ( & V_42 -> V_14 -> V_57 ) ;
F_37 ( & V_42 -> V_56 ) ;
V_42 -> V_63 = 1 ;
V_42 -> V_51 = V_53 ;
F_25 ( & V_42 -> V_50 , V_43 ) ;
F_38 ( V_45 ) ;
V_61 = F_39 ( F_22 , ( void * ) V_42 ,
L_4 , V_42 -> V_47 [ 0 ] , V_42 -> V_14 -> V_47 ) ;
if ( F_40 ( V_61 ) ) {
F_11 ( V_14 , L_9 ) ;
F_28 ( & V_14 -> V_57 , & V_58 ) ;
F_29 ( V_59 ) ;
return false ;
}
F_23 ( & V_42 -> V_50 , V_43 ) ;
V_42 -> V_54 = V_61 ;
V_42 -> V_51 = V_53 ;
F_25 ( & V_42 -> V_50 , V_43 ) ;
F_41 ( V_61 ) ;
break;
case V_64 :
V_42 -> V_51 = V_52 ;
F_24 ( V_14 , L_10 ,
V_42 -> V_47 , V_45 -> V_46 , V_45 -> V_62 ) ;
case V_53 :
case V_52 :
default:
F_25 ( & V_42 -> V_50 , V_43 ) ;
break;
}
return true ;
}
void F_42 ( struct V_41 * V_42 , int V_48 , int V_65 )
{
unsigned long V_43 ;
enum V_66 V_67 = V_48 ? V_52 : V_64 ;
F_23 ( & V_42 -> V_50 , V_43 ) ;
if ( V_42 -> V_51 == V_55 ) {
F_25 ( & V_42 -> V_50 , V_43 ) ;
if ( V_48 )
F_34 ( V_42 ) ;
return;
}
if ( V_42 -> V_51 != V_67 ) {
if ( V_42 -> V_54 == NULL ) {
F_25 ( & V_42 -> V_50 , V_43 ) ;
return;
}
V_42 -> V_51 = V_67 ;
F_26 () ;
F_37 ( & V_42 -> V_56 ) ;
if ( V_42 -> V_54 != V_45 )
F_43 ( V_68 , V_42 -> V_54 ) ;
}
F_25 ( & V_42 -> V_50 , V_43 ) ;
if ( V_65 )
F_44 ( & V_42 -> V_56 ) ;
}
static struct V_41 * F_45 ( struct V_13 * V_14 , struct V_60 * V_54 )
{
struct V_41 * V_42 =
V_54 == V_14 -> V_69 . V_54 ? & V_14 -> V_69 :
V_54 == V_14 -> V_70 . V_54 ? & V_14 -> V_70 :
V_54 == V_14 -> V_71 . V_54 ? & V_14 -> V_71 : NULL ;
return V_42 ;
}
char * F_46 ( struct V_13 * V_14 , struct V_60 * V_54 )
{
struct V_41 * V_42 = F_45 ( V_14 , V_54 ) ;
return V_42 ? V_42 -> V_47 : V_54 -> V_46 ;
}
int F_47 ( struct V_13 * V_14 )
{
struct V_4 * V_5 ;
int V_72 = 0 , V_73 ;
F_48 () ;
V_5 = F_49 ( & V_14 -> V_74 , & V_72 ) ;
V_73 = V_5 ? F_50 ( V_5 ) : - 1 ;
F_51 () ;
return V_73 ;
}
void F_52 ( struct V_13 * V_14 )
{
int V_75 , V_76 ;
if ( F_53 ( V_14 -> V_77 ) )
return;
V_75 = F_47 ( V_14 ) % F_53 ( V_78 ) ;
F_54 (cpu) {
if ( V_75 -- == 0 ) {
F_55 ( V_76 , V_14 -> V_77 ) ;
return;
}
}
F_56 ( V_14 -> V_77 ) ;
}
void F_57 ( struct V_41 * V_42 )
{
struct V_60 * V_79 = V_45 ;
if ( ! V_42 -> V_63 )
return;
V_42 -> V_63 = 0 ;
F_58 ( V_79 , V_42 -> V_14 -> V_77 ) ;
}
unsigned int F_59 ( struct V_13 * V_14 )
{
if ( V_14 -> V_80 >= 100 ) {
F_60 ( ! F_61 ( sizeof( struct V_81 ) , 8 ) ) ;
return sizeof( struct V_81 ) ;
} else {
F_60 ( sizeof( struct V_82 ) !=
sizeof( struct V_83 ) ) ;
F_60 ( ! F_61 ( sizeof( struct V_82 ) , 8 ) ) ;
return sizeof( struct V_82 ) ;
}
}
static unsigned int F_62 ( struct V_82 * V_84 , enum V_85 V_86 , int V_87 )
{
V_84 -> V_88 = F_63 ( V_89 ) ;
V_84 -> V_90 = F_64 ( V_86 ) ;
V_84 -> V_91 = F_64 ( V_87 ) ;
return sizeof( struct V_82 ) ;
}
static unsigned int F_65 ( struct V_83 * V_84 , enum V_85 V_86 , int V_87 )
{
V_84 -> V_88 = F_64 ( V_92 ) ;
V_84 -> V_90 = F_64 ( V_86 ) ;
V_84 -> V_91 = F_63 ( V_87 ) ;
return sizeof( struct V_83 ) ;
}
static unsigned int F_66 ( struct V_81 * V_84 , enum V_85 V_86 ,
int V_87 , int V_72 )
{
V_84 -> V_88 = F_63 ( V_93 ) ;
V_84 -> V_94 = F_64 ( V_72 ) ;
V_84 -> V_90 = F_64 ( V_86 ) ;
V_84 -> V_91 = F_63 ( V_87 ) ;
V_84 -> V_95 = 0 ;
return sizeof( struct V_81 ) ;
}
static unsigned int F_67 ( struct V_13 * V_14 , int V_72 ,
void * V_96 , enum V_85 V_86 , int V_87 )
{
if ( V_14 -> V_80 >= 100 )
return F_66 ( V_96 , V_86 , V_87 , V_72 ) ;
else if ( V_14 -> V_80 >= 95 &&
V_87 > V_97 )
return F_65 ( V_96 , V_86 , V_87 ) ;
else
return F_62 ( V_96 , V_86 , V_87 ) ;
}
static void * F_68 ( struct V_13 * V_14 ,
struct V_98 * V_99 )
{
if ( ! V_99 -> V_100 )
return NULL ;
return V_99 -> V_101 + F_59 ( V_14 ) ;
}
void * F_69 ( struct V_13 * V_14 , struct V_98 * V_99 )
{
void * V_79 ;
F_70 ( & V_99 -> V_102 ) ;
V_79 = F_68 ( V_14 , V_99 ) ;
if ( ! V_79 )
F_71 ( & V_99 -> V_102 ) ;
return V_79 ;
}
void * F_72 ( struct V_4 * V_5 , struct V_98 * V_99 )
{
return F_69 ( V_5 -> V_14 , V_99 ) ;
}
static int F_73 ( struct V_13 * V_14 , int V_72 ,
struct V_98 * V_99 , enum V_85 V_86 ,
unsigned int V_103 , void * V_104 ,
unsigned int V_87 )
{
int V_105 ;
int V_106 ;
V_105 = V_104 ? V_107 : 0 ;
V_103 += F_67 ( V_14 , V_72 , V_99 -> V_101 , V_86 ,
V_103 + V_87 ) ;
V_106 = F_74 ( V_14 , V_99 -> V_100 , V_99 -> V_101 , V_103 ,
V_105 ) ;
if ( V_104 && ! V_106 )
V_106 = F_74 ( V_14 , V_99 -> V_100 , V_104 , V_87 , 0 ) ;
return V_106 ;
}
static int F_75 ( struct V_13 * V_14 , struct V_98 * V_99 ,
enum V_85 V_86 , unsigned int V_103 ,
void * V_104 , unsigned int V_87 )
{
return F_73 ( V_14 , 0 , V_99 , V_86 , V_103 , V_104 , V_87 ) ;
}
int F_76 ( struct V_13 * V_14 , struct V_98 * V_99 ,
enum V_85 V_86 , unsigned int V_103 ,
void * V_104 , unsigned int V_87 )
{
int V_106 ;
V_106 = F_75 ( V_14 , V_99 , V_86 , V_103 , V_104 , V_87 ) ;
F_71 ( & V_99 -> V_102 ) ;
return V_106 ;
}
int F_77 ( struct V_4 * V_5 , struct V_98 * V_99 ,
enum V_85 V_86 , unsigned int V_103 ,
void * V_104 , unsigned int V_87 )
{
int V_106 ;
V_106 = F_73 ( V_5 -> V_14 , V_5 -> V_72 , V_99 , V_86 , V_103 ,
V_104 , V_87 ) ;
F_71 ( & V_99 -> V_102 ) ;
return V_106 ;
}
int F_78 ( struct V_13 * V_14 )
{
struct V_98 * V_99 ;
V_99 = & V_14 -> V_108 ;
if ( ! F_69 ( V_14 , V_99 ) )
return - V_109 ;
return F_76 ( V_14 , V_99 , V_110 , 0 , NULL , 0 ) ;
}
int F_79 ( struct V_13 * V_14 )
{
struct V_98 * V_99 ;
V_99 = & V_14 -> V_108 ;
if ( ! F_69 ( V_14 , V_99 ) )
return - V_109 ;
return F_76 ( V_14 , V_99 , V_111 , 0 , NULL , 0 ) ;
}
int F_80 ( struct V_4 * V_5 )
{
struct V_98 * V_99 ;
struct V_112 * V_79 ;
int V_87 ;
const int V_113 = V_5 -> V_14 -> V_80 ;
enum V_85 V_86 ;
struct V_114 * V_115 ;
struct V_116 * V_117 ;
V_99 = & V_5 -> V_14 -> V_104 ;
V_79 = F_72 ( V_5 , V_99 ) ;
if ( ! V_79 )
return - V_109 ;
F_48 () ;
V_115 = F_81 ( V_5 -> V_14 -> V_114 ) ;
V_87 = V_113 <= 87 ? sizeof( struct V_118 )
: V_113 == 88 ? sizeof( struct V_118 )
+ strlen ( V_115 -> V_119 ) + 1
: V_113 <= 94 ? sizeof( struct V_120 )
: sizeof( struct V_112 ) ;
V_86 = V_113 >= 89 ? V_121 : V_122 ;
memset ( V_79 -> V_119 , 0 , 2 * V_123 ) ;
if ( F_82 ( V_5 ) ) {
V_117 = F_81 ( V_5 -> V_124 -> V_116 ) ;
V_79 -> V_125 = F_63 ( V_117 -> V_125 ) ;
V_79 -> V_126 = F_63 ( V_117 -> V_126 ) ;
V_79 -> V_127 = F_63 ( V_117 -> V_127 ) ;
V_79 -> V_128 = F_63 ( V_117 -> V_128 ) ;
V_79 -> V_129 = F_63 ( V_117 -> V_129 ) ;
F_83 ( V_5 ) ;
} else {
V_79 -> V_125 = F_63 ( V_130 ) ;
V_79 -> V_126 = F_63 ( V_131 ) ;
V_79 -> V_127 = F_63 ( V_132 ) ;
V_79 -> V_128 = F_63 ( V_133 ) ;
V_79 -> V_129 = F_63 ( V_134 ) ;
}
if ( V_113 >= 88 )
strcpy ( V_79 -> V_119 , V_115 -> V_119 ) ;
if ( V_113 >= 89 )
strcpy ( V_79 -> V_135 , V_115 -> V_135 ) ;
F_51 () ;
return F_77 ( V_5 , V_99 , V_86 , V_87 , NULL , 0 ) ;
}
int F_84 ( struct V_13 * V_14 , enum V_85 V_86 )
{
struct V_98 * V_99 ;
struct V_136 * V_79 ;
struct V_114 * V_115 ;
int V_87 , V_137 ;
V_99 = & V_14 -> V_104 ;
V_79 = F_68 ( V_14 , V_99 ) ;
if ( ! V_79 )
return - V_109 ;
F_48 () ;
V_115 = F_81 ( V_14 -> V_114 ) ;
if ( V_115 -> V_138 && V_14 -> V_80 < 92 ) {
F_51 () ;
F_71 ( & V_99 -> V_102 ) ;
F_11 ( V_14 , L_11 ) ;
return - V_139 ;
}
V_87 = sizeof( * V_79 ) ;
if ( V_14 -> V_80 >= 87 )
V_87 += strlen ( V_115 -> V_140 ) + 1 ;
V_79 -> V_141 = F_63 ( V_115 -> V_142 ) ;
V_79 -> V_143 = F_63 ( V_115 -> V_143 ) ;
V_79 -> V_144 = F_63 ( V_115 -> V_144 ) ;
V_79 -> V_145 = F_63 ( V_115 -> V_145 ) ;
V_79 -> V_146 = F_63 ( V_115 -> V_146 ) ;
V_137 = 0 ;
if ( V_115 -> V_147 )
V_137 |= V_148 ;
if ( V_115 -> V_138 )
V_137 |= V_149 ;
V_79 -> V_150 = F_63 ( V_137 ) ;
if ( V_14 -> V_80 >= 87 )
strcpy ( V_79 -> V_140 , V_115 -> V_140 ) ;
F_51 () ;
return F_75 ( V_14 , V_99 , V_86 , V_87 , NULL , 0 ) ;
}
int F_85 ( struct V_13 * V_14 )
{
int V_106 ;
F_70 ( & V_14 -> V_104 . V_102 ) ;
V_106 = F_84 ( V_14 , V_151 ) ;
F_71 ( & V_14 -> V_104 . V_102 ) ;
return V_106 ;
}
int F_86 ( struct V_4 * V_5 , T_2 V_152 )
{
struct V_98 * V_99 ;
struct V_153 * V_79 ;
int V_154 ;
if ( ! F_87 ( V_5 , V_155 ) )
return 0 ;
V_99 = & V_5 -> V_14 -> V_104 ;
V_79 = F_72 ( V_5 , V_99 ) ;
if ( ! V_79 ) {
F_83 ( V_5 ) ;
return - V_109 ;
}
F_9 ( & V_5 -> V_124 -> V_156 . V_157 ) ;
for ( V_154 = V_158 ; V_154 < V_159 ; V_154 ++ )
V_79 -> V_160 [ V_154 ] = F_88 ( V_5 -> V_124 -> V_156 . V_160 [ V_154 ] ) ;
F_14 ( & V_5 -> V_124 -> V_156 . V_157 ) ;
V_5 -> V_161 = F_89 ( V_5 ) ;
V_79 -> V_160 [ V_159 ] = F_88 ( V_5 -> V_161 ) ;
F_48 () ;
V_152 |= F_81 ( V_5 -> V_14 -> V_114 ) -> V_147 ? 1 : 0 ;
F_51 () ;
V_152 |= F_90 ( V_162 , & V_5 -> V_43 ) ? 2 : 0 ;
V_152 |= V_5 -> V_163 . V_11 == V_164 ? 4 : 0 ;
V_79 -> V_160 [ V_165 ] = F_88 ( V_152 ) ;
F_83 ( V_5 ) ;
return F_77 ( V_5 , V_99 , V_166 , sizeof( * V_79 ) , NULL , 0 ) ;
}
int F_91 ( struct V_4 * V_5 )
{
return F_86 ( V_5 , 0 ) ;
}
int F_92 ( struct V_4 * V_5 )
{
return F_86 ( V_5 , 8 ) ;
}
void F_93 ( struct V_4 * V_5 , const char * V_167 )
{
if ( F_87 ( V_5 , V_155 ) ) {
T_2 * V_160 = V_5 -> V_124 -> V_156 . V_160 ;
F_94 ( V_168 , L_12 ,
V_167 ,
( unsigned long long ) V_160 [ V_158 ] ,
( unsigned long long ) V_160 [ V_169 ] ,
( unsigned long long ) V_160 [ V_170 ] ,
( unsigned long long ) V_160 [ V_171 ] ) ;
F_83 ( V_5 ) ;
} else {
F_94 ( V_168 , L_13 ,
V_167 ,
( unsigned long long ) V_5 -> V_172 ) ;
}
}
void F_95 ( struct V_4 * V_5 )
{
struct V_98 * V_99 ;
struct V_173 * V_79 ;
T_2 V_160 ;
F_96 ( V_5 -> V_10 . V_11 == V_174 ) ;
V_160 = V_5 -> V_124 -> V_156 . V_160 [ V_169 ] ;
if ( V_160 && V_160 != V_175 )
V_160 = V_160 + V_176 ;
else
F_97 ( & V_160 , sizeof( T_2 ) ) ;
F_98 ( V_5 , V_169 , V_160 ) ;
F_93 ( V_5 , L_14 ) ;
F_99 ( V_5 ) ;
V_99 = & V_5 -> V_14 -> V_104 ;
V_79 = F_72 ( V_5 , V_99 ) ;
if ( V_79 ) {
V_79 -> V_160 = F_88 ( V_160 ) ;
F_77 ( V_5 , V_99 , V_177 , sizeof( * V_79 ) , NULL , 0 ) ;
}
}
int F_100 ( struct V_4 * V_5 , int V_178 , enum V_179 V_43 )
{
struct V_98 * V_99 ;
struct V_180 * V_79 ;
T_3 V_181 , V_182 ;
int V_183 ;
unsigned int V_184 ;
if ( F_87 ( V_5 , V_155 ) ) {
F_96 ( V_5 -> V_124 -> V_185 ) ;
V_181 = F_101 ( V_5 -> V_124 ) ;
F_48 () ;
V_182 = F_81 ( V_5 -> V_124 -> V_116 ) -> V_186 ;
F_51 () ;
V_183 = F_102 ( V_5 ) ;
V_184 = F_103 ( V_5 -> V_124 -> V_185 -> V_187 -> V_188 ) << 9 ;
V_184 = F_104 ( V_184 , V_189 ) ;
F_83 ( V_5 ) ;
} else {
V_181 = 0 ;
V_182 = 0 ;
V_183 = V_190 ;
V_184 = V_189 ;
}
V_99 = & V_5 -> V_14 -> V_104 ;
V_79 = F_72 ( V_5 , V_99 ) ;
if ( ! V_79 )
return - V_109 ;
if ( V_5 -> V_14 -> V_80 <= 94 )
V_184 = F_104 ( V_184 , V_97 ) ;
else if ( V_5 -> V_14 -> V_80 < 100 )
V_184 = F_104 ( V_184 , V_191 ) ;
V_79 -> V_181 = F_88 ( V_181 ) ;
V_79 -> V_182 = F_88 ( V_182 ) ;
V_79 -> V_192 = F_88 ( V_178 ? 0 : F_105 ( V_5 -> V_193 ) ) ;
V_79 -> V_184 = F_63 ( V_184 ) ;
V_79 -> V_194 = F_64 ( V_183 ) ;
V_79 -> V_179 = F_64 ( V_43 ) ;
return F_77 ( V_5 , V_99 , V_195 , sizeof( * V_79 ) , NULL , 0 ) ;
}
int F_106 ( struct V_4 * V_5 )
{
struct V_98 * V_99 ;
struct V_196 * V_79 ;
V_99 = & V_5 -> V_14 -> V_104 ;
V_79 = F_72 ( V_5 , V_99 ) ;
if ( ! V_79 )
return - V_109 ;
V_79 -> V_10 = F_63 ( V_5 -> V_10 . V_154 ) ;
return F_77 ( V_5 , V_99 , V_197 , sizeof( * V_79 ) , NULL , 0 ) ;
}
int F_107 ( struct V_4 * V_5 , union V_198 V_10 )
{
struct V_98 * V_99 ;
struct V_196 * V_79 ;
V_99 = & V_5 -> V_14 -> V_104 ;
V_79 = F_72 ( V_5 , V_99 ) ;
if ( ! V_79 )
return - V_109 ;
V_79 -> V_10 = F_63 ( V_10 . V_154 ) ;
return F_77 ( V_5 , V_99 , V_197 , sizeof( * V_79 ) , NULL , 0 ) ;
}
int F_108 ( struct V_4 * V_5 , union V_198 V_199 , union V_198 V_200 )
{
struct V_98 * V_99 ;
struct V_201 * V_79 ;
V_99 = & V_5 -> V_14 -> V_104 ;
V_79 = F_72 ( V_5 , V_99 ) ;
if ( ! V_79 )
return - V_109 ;
V_79 -> V_199 = F_63 ( V_199 . V_154 ) ;
V_79 -> V_200 = F_63 ( V_200 . V_154 ) ;
return F_77 ( V_5 , V_99 , V_202 , sizeof( * V_79 ) , NULL , 0 ) ;
}
int F_109 ( struct V_13 * V_14 , union V_198 V_199 , union V_198 V_200 )
{
enum V_85 V_86 ;
struct V_98 * V_99 ;
struct V_201 * V_79 ;
V_86 = V_14 -> V_80 < 100 ? V_202 : V_203 ;
V_99 = & V_14 -> V_104 ;
V_79 = F_69 ( V_14 , V_99 ) ;
if ( ! V_79 )
return - V_109 ;
V_79 -> V_199 = F_63 ( V_199 . V_154 ) ;
V_79 -> V_200 = F_63 ( V_200 . V_154 ) ;
return F_76 ( V_14 , V_99 , V_86 , sizeof( * V_79 ) , NULL , 0 ) ;
}
void F_110 ( struct V_4 * V_5 , enum V_204 V_205 )
{
struct V_98 * V_99 ;
struct V_206 * V_79 ;
V_99 = & V_5 -> V_14 -> V_108 ;
V_79 = F_72 ( V_5 , V_99 ) ;
if ( V_79 ) {
V_79 -> V_205 = F_63 ( V_205 ) ;
F_77 ( V_5 , V_99 , V_207 , sizeof( * V_79 ) , NULL , 0 ) ;
}
}
void F_111 ( struct V_13 * V_14 , enum V_204 V_205 )
{
struct V_98 * V_99 ;
struct V_206 * V_79 ;
enum V_85 V_86 = V_14 -> V_80 < 100 ? V_207 : V_208 ;
V_99 = & V_14 -> V_108 ;
V_79 = F_69 ( V_14 , V_99 ) ;
if ( V_79 ) {
V_79 -> V_205 = F_63 ( V_205 ) ;
F_76 ( V_14 , V_99 , V_86 , sizeof( * V_79 ) , NULL , 0 ) ;
}
}
static void F_112 ( struct V_209 * V_79 , enum V_210 V_211 )
{
F_113 ( V_211 & ~ 0xf ) ;
V_79 -> V_212 = ( V_79 -> V_212 & ~ 0xf ) | V_211 ;
}
static void F_114 ( struct V_209 * V_79 , int V_213 )
{
V_79 -> V_212 = ( V_79 -> V_212 & ~ 0x80 ) | ( V_213 ? 0x80 : 0 ) ;
}
static void F_115 ( struct V_209 * V_79 , int V_214 )
{
F_113 ( V_214 & ~ 0x7 ) ;
V_79 -> V_212 = ( V_79 -> V_212 & ( ~ 0x7 << 4 ) ) | ( V_214 << 4 ) ;
}
int F_116 ( struct V_4 * V_5 ,
struct V_209 * V_79 ,
unsigned int V_87 ,
struct V_215 * V_216 )
{
struct V_217 V_218 ;
unsigned long V_219 ;
unsigned long V_220 ;
unsigned long V_221 ;
unsigned V_222 ;
unsigned V_223 ;
int V_224 , V_225 ;
F_48 () ;
V_225 = F_81 ( V_5 -> V_14 -> V_114 ) -> V_225 ;
F_51 () ;
if ( ! V_225 || V_5 -> V_14 -> V_80 < 90 )
return 0 ;
if ( V_216 -> V_226 >= V_216 -> V_227 )
return 0 ;
F_117 ( & V_218 , V_79 -> V_211 , V_87 , 0 ) ;
memset ( V_79 -> V_211 , 0 , V_87 ) ;
V_219 = 0 ;
V_223 = 2 ;
do {
V_220 = ( V_223 == 0 ) ? F_118 ( V_5 , V_216 -> V_226 )
: F_119 ( V_5 , V_216 -> V_226 ) ;
if ( V_220 == - 1UL )
V_220 = V_216 -> V_227 ;
V_221 = V_220 - V_216 -> V_226 ;
if ( V_223 == 2 ) {
if ( V_221 == 0 ) {
F_114 ( V_79 , 1 ) ;
V_223 = ! V_223 ;
continue;
}
F_114 ( V_79 , 0 ) ;
}
if ( V_221 == 0 ) {
F_120 ( V_168 , L_15
L_16 , V_223 , V_216 -> V_226 ) ;
return - 1 ;
}
V_224 = F_121 ( & V_218 , V_221 ) ;
if ( V_224 == - V_228 )
break;
if ( V_224 <= 0 ) {
F_120 ( V_168 , L_17 , V_224 ) ;
return 0 ;
}
V_223 = ! V_223 ;
V_219 += V_221 ;
V_216 -> V_226 = V_220 ;
} while ( V_216 -> V_226 < V_216 -> V_227 );
V_222 = V_218 . V_229 . V_230 - V_79 -> V_211 + ! ! V_218 . V_229 . V_231 ;
if ( V_219 < ( V_222 << 3 ) ) {
V_216 -> V_226 -= V_219 ;
F_122 ( V_216 ) ;
V_216 -> V_226 = V_216 -> V_232 * V_233 ;
return 0 ;
}
F_122 ( V_216 ) ;
F_115 ( V_79 , ( 8 - V_218 . V_229 . V_231 ) & 0x7 ) ;
return V_222 ;
}
static int
F_123 ( struct V_4 * V_5 , struct V_215 * V_216 )
{
struct V_98 * V_99 = & V_5 -> V_14 -> V_104 ;
unsigned int V_103 = F_59 ( V_5 -> V_14 ) ;
struct V_209 * V_79 = V_99 -> V_101 + V_103 ;
int V_222 , V_106 ;
V_222 = F_116 ( V_5 , V_79 ,
V_234 - V_103 - sizeof( * V_79 ) , V_216 ) ;
if ( V_222 < 0 )
return - V_109 ;
if ( V_222 ) {
F_112 ( V_79 , V_235 ) ;
V_106 = F_73 ( V_5 -> V_14 , V_5 -> V_72 , V_99 ,
V_236 , sizeof( * V_79 ) + V_222 ,
NULL , 0 ) ;
V_216 -> V_237 [ 0 ] ++ ;
V_216 -> V_238 [ 0 ] += V_103 + sizeof( * V_79 ) + V_222 ;
if ( V_216 -> V_226 >= V_216 -> V_227 )
V_222 = 0 ;
} else {
unsigned int V_239 ;
unsigned long V_240 ;
unsigned long * V_79 = V_99 -> V_101 + V_103 ;
V_239 = V_234 - V_103 ;
V_240 = F_124 ( V_241 , V_239 / sizeof( * V_79 ) ,
V_216 -> V_242 - V_216 -> V_232 ) ;
V_222 = V_240 * sizeof( * V_79 ) ;
if ( V_222 )
F_125 ( V_5 , V_216 -> V_232 , V_240 , V_79 ) ;
V_106 = F_73 ( V_5 -> V_14 , V_5 -> V_72 , V_99 , V_243 , V_222 , NULL , 0 ) ;
V_216 -> V_232 += V_240 ;
V_216 -> V_226 = V_216 -> V_232 * V_233 ;
V_216 -> V_237 [ 1 ] ++ ;
V_216 -> V_238 [ 1 ] += V_103 + V_222 ;
if ( V_216 -> V_226 > V_216 -> V_227 )
V_216 -> V_226 = V_216 -> V_227 ;
}
if ( ! V_106 ) {
if ( V_222 == 0 ) {
F_126 ( V_5 , L_18 , V_216 ) ;
return 0 ;
} else
return 1 ;
}
return - V_109 ;
}
static int F_127 ( struct V_4 * V_5 )
{
struct V_215 V_216 ;
int V_106 ;
if ( ! F_128 ( V_5 -> V_244 ) )
return false ;
if ( F_82 ( V_5 ) ) {
if ( F_129 ( V_5 -> V_124 , V_245 ) ) {
F_94 ( V_168 , L_19 ) ;
F_130 ( V_5 ) ;
if ( F_131 ( V_5 ) ) {
F_120 ( V_168 , L_20 ) ;
} else {
F_132 ( V_5 , V_245 ) ;
F_99 ( V_5 ) ;
}
}
F_83 ( V_5 ) ;
}
V_216 = (struct V_215 ) {
. V_227 = F_133 ( V_5 ) ,
. V_242 = F_134 ( V_5 ) ,
} ;
do {
V_106 = F_123 ( V_5 , & V_216 ) ;
} while ( V_106 > 0 );
return V_106 == 0 ;
}
int F_135 ( struct V_4 * V_5 )
{
struct V_98 * V_99 = & V_5 -> V_14 -> V_104 ;
int V_106 = - 1 ;
F_70 ( & V_99 -> V_102 ) ;
if ( V_99 -> V_100 )
V_106 = ! F_127 ( V_5 ) ;
F_71 ( & V_99 -> V_102 ) ;
return V_106 ;
}
void F_136 ( struct V_13 * V_14 , T_4 V_15 , T_4 V_16 )
{
struct V_98 * V_99 ;
struct V_246 * V_79 ;
if ( V_14 -> V_247 < V_248 )
return;
V_99 = & V_14 -> V_108 ;
V_79 = F_69 ( V_14 , V_99 ) ;
if ( ! V_79 )
return;
V_79 -> V_249 = V_15 ;
V_79 -> V_16 = F_63 ( V_16 ) ;
F_76 ( V_14 , V_99 , V_250 , sizeof( * V_79 ) , NULL , 0 ) ;
}
static int F_137 ( struct V_4 * V_5 , enum V_85 V_86 ,
T_2 V_251 , T_4 V_252 , T_2 V_253 )
{
struct V_98 * V_99 ;
struct V_254 * V_79 ;
if ( V_5 -> V_10 . V_31 < V_255 )
return - V_109 ;
V_99 = & V_5 -> V_14 -> V_108 ;
V_79 = F_72 ( V_5 , V_99 ) ;
if ( ! V_79 )
return - V_109 ;
V_79 -> V_251 = V_251 ;
V_79 -> V_253 = V_253 ;
V_79 -> V_252 = V_252 ;
V_79 -> V_256 = F_63 ( F_138 ( & V_5 -> V_257 ) ) ;
return F_77 ( V_5 , V_99 , V_86 , sizeof( * V_79 ) , NULL , 0 ) ;
}
void F_139 ( struct V_4 * V_5 , enum V_85 V_86 ,
struct V_258 * V_259 , int V_239 )
{
if ( V_5 -> V_14 -> V_260 )
V_239 -= F_140 ( V_5 -> V_14 -> V_260 ) ;
F_137 ( V_5 , V_86 , V_259 -> V_251 , F_63 ( V_239 ) ,
V_259 -> V_253 ) ;
}
void F_141 ( struct V_4 * V_5 , enum V_85 V_86 ,
struct V_261 * V_262 )
{
F_137 ( V_5 , V_86 , V_262 -> V_251 , V_262 -> V_252 , V_262 -> V_253 ) ;
}
int F_142 ( struct V_4 * V_5 , enum V_85 V_86 ,
struct V_263 * V_264 )
{
return F_137 ( V_5 , V_86 ,
F_88 ( V_264 -> V_154 . V_251 ) ,
F_63 ( V_264 -> V_154 . V_87 ) ,
V_264 -> V_253 ) ;
}
int F_143 ( struct V_4 * V_5 , enum V_85 V_86 ,
T_3 V_251 , int V_252 , T_2 V_253 )
{
return F_137 ( V_5 , V_86 ,
F_88 ( V_251 ) ,
F_63 ( V_252 ) ,
F_88 ( V_253 ) ) ;
}
int F_144 ( struct V_4 * V_5 , int V_86 ,
T_3 V_251 , int V_87 , T_2 V_253 )
{
struct V_98 * V_99 ;
struct V_261 * V_79 ;
V_99 = & V_5 -> V_14 -> V_104 ;
V_79 = F_72 ( V_5 , V_99 ) ;
if ( ! V_79 )
return - V_109 ;
V_79 -> V_251 = F_88 ( V_251 ) ;
V_79 -> V_253 = V_253 ;
V_79 -> V_252 = F_63 ( V_87 ) ;
return F_77 ( V_5 , V_99 , V_86 , sizeof( * V_79 ) , NULL , 0 ) ;
}
int F_145 ( struct V_4 * V_5 , T_3 V_251 , int V_87 ,
void * V_265 , int V_266 , enum V_85 V_86 )
{
struct V_98 * V_99 ;
struct V_261 * V_79 ;
V_99 = & V_5 -> V_14 -> V_104 ;
V_79 = F_72 ( V_5 , V_99 ) ;
if ( ! V_79 )
return - V_109 ;
V_79 -> V_251 = F_88 ( V_251 ) ;
V_79 -> V_253 = V_267 ;
V_79 -> V_252 = F_63 ( V_87 ) ;
return F_77 ( V_5 , V_99 , V_86 , sizeof( * V_79 ) ,
V_265 , V_266 ) ;
}
int F_146 ( struct V_4 * V_5 , T_3 V_251 , int V_87 )
{
struct V_98 * V_99 ;
struct V_261 * V_79 ;
V_99 = & V_5 -> V_14 -> V_104 ;
V_79 = F_72 ( V_5 , V_99 ) ;
if ( ! V_79 )
return - V_109 ;
V_79 -> V_251 = F_88 ( V_251 ) ;
V_79 -> V_253 = V_267 ;
V_79 -> V_252 = F_63 ( V_87 ) ;
return F_77 ( V_5 , V_99 , V_268 , sizeof( * V_79 ) , NULL , 0 ) ;
}
static int F_147 ( struct V_13 * V_14 , struct V_100 * V_99 )
{
int V_269 ;
V_269 = V_14 -> V_108 . V_100 == V_99
|| ! V_14 -> V_70 . V_54
|| F_148 ( & V_14 -> V_70 ) != V_53
|| V_14 -> V_247 < V_248 ;
if ( V_269 )
return true ;
V_269 = ! -- V_14 -> V_270 ;
if ( ! V_269 ) {
F_11 ( V_14 , L_21 ,
V_45 -> V_46 , V_45 -> V_62 , V_14 -> V_270 ) ;
F_149 ( V_14 ) ;
}
return V_269 ; ;
}
static void F_150 ( struct V_13 * V_14 )
{
struct V_99 * V_271 = V_14 -> V_104 . V_100 -> V_271 ;
if ( V_271 -> V_272 > V_271 -> V_273 * 4 / 5 )
F_151 ( V_274 , & V_14 -> V_43 ) ;
}
static int F_152 ( struct V_4 * V_5 , struct V_275 * V_275 ,
int V_276 , V_241 V_87 , unsigned V_105 )
{
struct V_100 * V_100 ;
void * V_277 ;
int V_106 ;
V_100 = V_5 -> V_14 -> V_104 . V_100 ;
V_277 = F_153 ( V_275 ) + V_276 ;
V_106 = F_74 ( V_5 -> V_14 , V_100 , V_277 , V_87 , V_105 ) ;
F_154 ( V_275 ) ;
if ( ! V_106 )
V_5 -> V_278 += V_87 >> 9 ;
return V_106 ;
}
static int F_155 ( struct V_4 * V_5 , struct V_275 * V_275 ,
int V_276 , V_241 V_87 , unsigned V_105 )
{
struct V_100 * V_100 = V_5 -> V_14 -> V_104 . V_100 ;
T_5 V_279 = F_156 () ;
int V_222 = V_87 ;
int V_106 = - V_109 ;
if ( V_280 || ( F_157 ( V_275 ) < 1 ) || F_158 ( V_275 ) )
return F_152 ( V_5 , V_275 , V_276 , V_87 , V_105 ) ;
V_105 |= V_281 ;
F_150 ( V_5 -> V_14 ) ;
F_159 ( V_282 ) ;
do {
int V_283 ;
V_283 = V_100 -> V_284 -> V_285 ( V_100 , V_275 , V_276 , V_222 , V_105 ) ;
if ( V_283 <= 0 ) {
if ( V_283 == - V_286 ) {
if ( F_147 ( V_5 -> V_14 , V_100 ) )
break;
continue;
}
F_160 ( V_168 , L_22 ,
V_287 , ( int ) V_87 , V_222 , V_283 ) ;
if ( V_283 < 0 )
V_106 = V_283 ;
break;
}
V_222 -= V_283 ;
V_276 += V_283 ;
} while ( V_222 > 0 );
F_159 ( V_279 ) ;
F_161 ( V_274 , & V_5 -> V_14 -> V_43 ) ;
if ( V_222 == 0 ) {
V_106 = 0 ;
V_5 -> V_278 += V_87 >> 9 ;
}
return V_106 ;
}
static int F_162 ( struct V_4 * V_5 , struct V_1 * V_1 )
{
struct V_288 * V_289 ;
int V_154 ;
F_163 (bvec, bio, i) {
int V_106 ;
V_106 = F_152 ( V_5 , V_289 -> V_290 ,
V_289 -> V_291 , V_289 -> V_292 ,
V_154 == V_1 -> V_293 - 1 ? 0 : V_107 ) ;
if ( V_106 )
return V_106 ;
}
return 0 ;
}
static int F_164 ( struct V_4 * V_5 , struct V_1 * V_1 )
{
struct V_288 * V_289 ;
int V_154 ;
F_163 (bvec, bio, i) {
int V_106 ;
V_106 = F_155 ( V_5 , V_289 -> V_290 ,
V_289 -> V_291 , V_289 -> V_292 ,
V_154 == V_1 -> V_293 - 1 ? 0 : V_107 ) ;
if ( V_106 )
return V_106 ;
}
return 0 ;
}
static int F_165 ( struct V_4 * V_5 ,
struct V_263 * V_264 )
{
struct V_275 * V_275 = V_264 -> V_294 ;
unsigned V_222 = V_264 -> V_154 . V_87 ;
int V_106 ;
F_166 (page) {
unsigned V_295 = F_124 ( unsigned , V_222 , V_296 ) ;
V_106 = F_155 ( V_5 , V_275 , 0 , V_295 ,
F_167 ( V_275 ) ? V_107 : 0 ) ;
if ( V_106 )
return V_106 ;
V_222 -= V_295 ;
}
return 0 ;
}
static T_4 F_168 ( struct V_4 * V_5 , unsigned long V_297 )
{
if ( V_5 -> V_14 -> V_80 >= 95 )
return ( V_297 & V_298 ? V_299 : 0 ) |
( V_297 & V_300 ? V_301 : 0 ) |
( V_297 & V_302 ? V_303 : 0 ) |
( V_297 & V_304 ? V_305 : 0 ) ;
else
return V_297 & V_298 ? V_299 : 0 ;
}
int F_169 ( struct V_4 * V_5 , struct V_17 * V_19 )
{
struct V_98 * V_99 ;
struct V_258 * V_79 ;
unsigned int V_306 = 0 ;
int V_307 ;
int V_106 ;
V_99 = & V_5 -> V_14 -> V_104 ;
V_79 = F_72 ( V_5 , V_99 ) ;
V_307 = V_5 -> V_14 -> V_308 ? F_140 ( V_5 -> V_14 -> V_308 ) : 0 ;
if ( ! V_79 )
return - V_109 ;
V_79 -> V_251 = F_88 ( V_19 -> V_154 . V_251 ) ;
V_79 -> V_253 = ( unsigned long ) V_19 ;
V_79 -> V_256 = F_63 ( F_138 ( & V_5 -> V_257 ) ) ;
V_306 = F_168 ( V_5 , V_19 -> V_309 -> V_297 ) ;
if ( V_5 -> V_10 . V_31 >= V_310 &&
V_5 -> V_10 . V_31 <= V_311 )
V_306 |= V_312 ;
if ( V_5 -> V_14 -> V_80 >= 100 ) {
if ( V_19 -> V_24 & V_313 )
V_306 |= V_314 ;
if ( V_19 -> V_24 & V_315 )
V_306 |= V_316 ;
}
V_79 -> V_306 = F_63 ( V_306 ) ;
if ( V_307 )
F_170 ( V_5 , V_5 -> V_14 -> V_308 , V_19 -> V_309 , V_79 + 1 ) ;
V_106 = F_73 ( V_5 -> V_14 , V_5 -> V_72 , V_99 , V_317 , sizeof( * V_79 ) + V_307 , NULL , V_19 -> V_154 . V_87 ) ;
if ( ! V_106 ) {
if ( ! ( V_19 -> V_24 & ( V_313 | V_315 ) ) || V_307 )
V_106 = F_162 ( V_5 , V_19 -> V_309 ) ;
else
V_106 = F_164 ( V_5 , V_19 -> V_309 ) ;
if ( V_307 > 0 && V_307 <= 64 ) {
unsigned char V_265 [ 64 ] ;
F_170 ( V_5 , V_5 -> V_14 -> V_308 , V_19 -> V_309 , V_265 ) ;
if ( memcmp ( V_79 + 1 , V_265 , V_307 ) ) {
F_160 ( V_168 ,
L_23 ,
( unsigned long long ) V_19 -> V_154 . V_251 , V_19 -> V_154 . V_87 ) ;
}
}
}
F_71 ( & V_99 -> V_102 ) ;
return V_106 ;
}
int F_171 ( struct V_4 * V_5 , enum V_85 V_86 ,
struct V_263 * V_264 )
{
struct V_98 * V_99 ;
struct V_258 * V_79 ;
int V_106 ;
int V_307 ;
V_99 = & V_5 -> V_14 -> V_104 ;
V_79 = F_72 ( V_5 , V_99 ) ;
V_307 = V_5 -> V_14 -> V_308 ? F_140 ( V_5 -> V_14 -> V_308 ) : 0 ;
if ( ! V_79 )
return - V_109 ;
V_79 -> V_251 = F_88 ( V_264 -> V_154 . V_251 ) ;
V_79 -> V_253 = V_264 -> V_253 ;
V_79 -> V_256 = 0 ;
V_79 -> V_306 = 0 ;
if ( V_307 )
F_172 ( V_5 , V_5 -> V_14 -> V_308 , V_264 , V_79 + 1 ) ;
V_106 = F_73 ( V_5 -> V_14 , V_5 -> V_72 , V_99 , V_86 , sizeof( * V_79 ) + V_307 , NULL , V_264 -> V_154 . V_87 ) ;
if ( ! V_106 )
V_106 = F_165 ( V_5 , V_264 ) ;
F_71 ( & V_99 -> V_102 ) ;
return V_106 ;
}
int F_173 ( struct V_4 * V_5 , struct V_17 * V_19 )
{
struct V_98 * V_99 ;
struct V_318 * V_79 ;
V_99 = & V_5 -> V_14 -> V_104 ;
V_79 = F_72 ( V_5 , V_99 ) ;
if ( ! V_79 )
return - V_109 ;
V_79 -> V_251 = F_88 ( V_19 -> V_154 . V_251 ) ;
V_79 -> V_252 = F_63 ( V_19 -> V_154 . V_87 ) ;
return F_77 ( V_5 , V_99 , V_319 , sizeof( * V_79 ) , NULL , 0 ) ;
}
int F_174 ( struct V_13 * V_14 , struct V_100 * V_99 ,
void * V_320 , V_241 V_87 , unsigned V_105 )
{
struct V_321 V_322 ;
struct V_323 V_324 ;
int V_325 , V_283 = 0 ;
if ( ! V_99 )
return - V_326 ;
V_322 . V_327 = V_320 ;
V_322 . V_328 = V_87 ;
V_324 . V_329 = NULL ;
V_324 . V_330 = 0 ;
V_324 . V_331 = NULL ;
V_324 . V_332 = 0 ;
V_324 . V_105 = V_105 | V_281 ;
if ( V_99 == V_14 -> V_104 . V_100 ) {
F_48 () ;
V_14 -> V_270 = F_81 ( V_14 -> V_114 ) -> V_270 ;
F_51 () ;
F_150 ( V_14 ) ;
}
do {
V_325 = F_175 ( V_99 , & V_324 , & V_322 , 1 , V_87 ) ;
if ( V_325 == - V_286 ) {
if ( F_147 ( V_14 , V_99 ) )
break;
else
continue;
}
if ( V_325 == - V_333 ) {
F_38 ( V_45 ) ;
V_325 = 0 ;
}
if ( V_325 < 0 )
break;
V_283 += V_325 ;
V_322 . V_327 += V_325 ;
V_322 . V_328 -= V_325 ;
} while ( V_283 < V_87 );
if ( V_99 == V_14 -> V_104 . V_100 )
F_161 ( V_274 , & V_14 -> V_43 ) ;
if ( V_325 <= 0 ) {
if ( V_325 != - V_286 ) {
F_11 ( V_14 , L_24 ,
V_99 == V_14 -> V_108 . V_100 ? L_25 : L_26 ,
V_325 ) ;
F_15 ( V_14 , F_16 ( V_31 , V_334 ) , V_33 ) ;
} else
F_15 ( V_14 , F_16 ( V_31 , V_335 ) , V_33 ) ;
}
return V_283 ;
}
int F_74 ( struct V_13 * V_14 , struct V_100 * V_99 , void * V_96 ,
V_241 V_87 , unsigned V_105 )
{
int V_106 ;
V_106 = F_174 ( V_14 , V_99 , V_96 , V_87 , V_105 ) ;
if ( V_106 < 0 )
return V_106 ;
if ( V_106 != V_87 )
return - V_109 ;
return 0 ;
}
static int F_176 ( struct V_336 * V_337 , T_6 V_338 )
{
struct V_4 * V_5 = V_337 -> V_187 -> V_339 ;
unsigned long V_43 ;
int V_325 = 0 ;
F_70 ( & V_340 ) ;
F_23 ( & V_5 -> V_14 -> V_22 , V_43 ) ;
if ( V_5 -> V_10 . V_341 != V_342 ) {
if ( V_338 & V_343 )
V_325 = - V_344 ;
else if ( ! V_345 )
V_325 = - V_346 ;
}
if ( ! V_325 )
V_5 -> V_347 ++ ;
F_25 ( & V_5 -> V_14 -> V_22 , V_43 ) ;
F_71 ( & V_340 ) ;
return V_325 ;
}
static int F_177 ( struct V_348 * V_349 , T_6 V_338 )
{
struct V_4 * V_5 = V_349 -> V_339 ;
F_70 ( & V_340 ) ;
V_5 -> V_347 -- ;
F_71 ( & V_340 ) ;
return 0 ;
}
static void F_178 ( struct V_4 * V_5 )
{
V_5 -> V_10 = (union V_350 ) {
{ . V_341 = V_351 ,
. V_352 = V_353 ,
. V_31 = V_354 ,
. V_11 = V_355 ,
. V_356 = V_357 ,
} } ;
}
void F_179 ( struct V_4 * V_5 )
{
F_178 ( V_5 ) ;
F_180 ( & V_5 -> V_358 , 0 ) ;
F_180 ( & V_5 -> V_359 , 0 ) ;
F_180 ( & V_5 -> V_360 , 0 ) ;
F_180 ( & V_5 -> V_361 , 0 ) ;
F_180 ( & V_5 -> V_9 , 0 ) ;
F_180 ( & V_5 -> V_362 , 0 ) ;
F_180 ( & V_5 -> V_363 , 0 ) ;
F_180 ( & V_5 -> V_364 , 0 ) ;
F_180 ( & V_5 -> V_365 , 0 ) ;
F_180 ( & V_5 -> V_366 , 0 ) ;
F_181 ( & V_5 -> V_367 ) ;
V_5 -> V_368 = & V_5 -> V_367 ;
F_32 ( & V_5 -> V_369 ) ;
F_32 ( & V_5 -> V_370 ) ;
F_182 ( & V_5 -> V_371 ) ;
F_182 ( & V_5 -> V_372 ) ;
F_182 ( & V_5 -> V_373 ) ;
F_182 ( & V_5 -> V_374 ) ;
F_182 ( & V_5 -> V_375 ) ;
F_182 ( & V_5 -> V_376 ) ;
F_182 ( & V_5 -> V_377 . V_378 ) ;
F_182 ( & V_5 -> V_379 . V_378 ) ;
F_182 ( & V_5 -> V_380 . V_378 ) ;
F_182 ( & V_5 -> V_381 . V_378 ) ;
F_182 ( & V_5 -> V_382 . V_378 ) ;
F_182 ( & V_5 -> V_383 . V_38 . V_378 ) ;
V_5 -> V_377 . V_384 = V_385 ;
V_5 -> V_379 . V_384 = V_386 ;
V_5 -> V_380 . V_384 = V_387 ;
V_5 -> V_381 . V_384 = V_388 ;
V_5 -> V_383 . V_38 . V_384 = V_389 ;
V_5 -> V_382 . V_384 = V_390 ;
V_5 -> V_377 . V_5 = V_5 ;
V_5 -> V_379 . V_5 = V_5 ;
V_5 -> V_380 . V_5 = V_5 ;
V_5 -> V_381 . V_5 = V_5 ;
V_5 -> V_383 . V_38 . V_5 = V_5 ;
V_5 -> V_382 . V_5 = V_5 ;
F_183 ( & V_5 -> V_391 ) ;
F_183 ( & V_5 -> V_392 ) ;
F_183 ( & V_5 -> V_393 ) ;
F_183 ( & V_5 -> V_394 ) ;
V_5 -> V_391 . V_49 = V_395 ;
V_5 -> V_391 . V_104 = ( unsigned long ) V_5 ;
V_5 -> V_392 . V_49 = V_396 ;
V_5 -> V_392 . V_104 = ( unsigned long ) V_5 ;
V_5 -> V_393 . V_49 = V_397 ;
V_5 -> V_393 . V_104 = ( unsigned long ) V_5 ;
V_5 -> V_394 . V_49 = V_398 ;
V_5 -> V_394 . V_104 = ( unsigned long ) V_5 ;
F_184 ( & V_5 -> V_12 ) ;
F_184 ( & V_5 -> V_399 ) ;
F_184 ( & V_5 -> V_400 ) ;
F_184 ( & V_5 -> V_401 ) ;
F_184 ( & V_5 -> V_402 ) ;
V_5 -> V_403 = V_404 ;
V_5 -> V_405 = V_406 ;
V_5 -> V_407 = V_406 ;
}
void F_185 ( struct V_4 * V_5 )
{
int V_154 ;
if ( V_5 -> V_14 -> V_69 . V_51 != V_55 )
F_120 ( V_168 , L_27 ,
V_5 -> V_14 -> V_69 . V_51 ) ;
V_5 -> V_408 =
V_5 -> V_409 =
V_5 -> V_410 =
V_5 -> V_411 =
V_5 -> V_278 =
V_5 -> V_412 =
V_5 -> V_413 =
V_5 -> V_414 =
V_5 -> V_415 =
V_5 -> V_416 = 0 ;
V_5 -> V_417 = 0 ;
V_5 -> V_418 = 0 ;
for ( V_154 = 0 ; V_154 < V_419 ; V_154 ++ ) {
V_5 -> V_420 [ V_154 ] = 0 ;
V_5 -> V_421 [ V_154 ] = 0 ;
}
F_96 ( V_5 -> V_14 -> V_114 == NULL ) ;
F_186 ( V_5 , 0 ) ;
if ( V_5 -> V_244 ) {
F_187 ( V_5 , 0 , 1 ) ;
F_188 ( V_5 ) ;
}
F_189 ( V_5 -> V_124 ) ;
V_5 -> V_124 = NULL ;
F_161 ( V_422 , & V_5 -> V_43 ) ;
F_96 ( F_190 ( & V_5 -> V_371 ) ) ;
F_96 ( F_190 ( & V_5 -> V_372 ) ) ;
F_96 ( F_190 ( & V_5 -> V_373 ) ) ;
F_96 ( F_190 ( & V_5 -> V_374 ) ) ;
F_96 ( F_190 ( & V_5 -> V_375 ) ) ;
F_96 ( F_190 ( & V_5 -> V_376 ) ) ;
F_96 ( F_190 ( & V_5 -> V_14 -> V_423 . V_424 ) ) ;
F_96 ( F_190 ( & V_5 -> V_377 . V_378 ) ) ;
F_96 ( F_190 ( & V_5 -> V_379 . V_378 ) ) ;
F_96 ( F_190 ( & V_5 -> V_380 . V_378 ) ) ;
F_178 ( V_5 ) ;
}
static void F_191 ( void )
{
struct V_275 * V_275 ;
while ( V_425 ) {
V_275 = V_425 ;
V_425 = (struct V_275 * ) F_192 ( V_275 ) ;
F_193 ( V_275 ) ;
V_426 -- ;
}
if ( V_3 )
F_194 ( V_3 ) ;
if ( V_427 )
F_195 ( V_427 ) ;
if ( V_428 )
F_195 ( V_428 ) ;
if ( V_429 )
F_195 ( V_429 ) ;
if ( V_430 )
F_196 ( V_430 ) ;
if ( V_431 )
F_196 ( V_431 ) ;
if ( V_432 )
F_196 ( V_432 ) ;
if ( V_433 )
F_196 ( V_433 ) ;
V_3 = NULL ;
V_427 = NULL ;
V_428 = NULL ;
V_429 = NULL ;
V_430 = NULL ;
V_431 = NULL ;
V_432 = NULL ;
V_433 = NULL ;
return;
}
static int F_197 ( void )
{
struct V_275 * V_275 ;
const int V_434 = ( V_189 / V_296 ) * V_435 ;
int V_154 ;
V_429 = NULL ;
V_430 = NULL ;
V_431 = NULL ;
V_432 = NULL ;
V_433 = NULL ;
V_425 = NULL ;
V_427 = NULL ;
V_3 = NULL ;
V_431 = F_198 (
L_28 , sizeof( struct V_17 ) , 0 , 0 , NULL ) ;
if ( V_431 == NULL )
goto V_436;
V_430 = F_198 (
L_29 , sizeof( struct V_263 ) , 0 , 0 , NULL ) ;
if ( V_430 == NULL )
goto V_436;
V_432 = F_198 (
L_30 , sizeof( struct V_437 ) , 0 , 0 , NULL ) ;
if ( V_432 == NULL )
goto V_436;
V_433 = F_198 (
L_31 , sizeof( struct V_438 ) , 0 , 0 , NULL ) ;
if ( V_433 == NULL )
goto V_436;
V_3 = F_199 ( V_439 , 0 ) ;
if ( V_3 == NULL )
goto V_436;
V_427 = F_200 ( V_439 , 0 ) ;
if ( V_427 == NULL )
goto V_436;
V_429 = F_201 ( V_434 ,
V_440 , V_441 , V_431 ) ;
if ( V_429 == NULL )
goto V_436;
V_428 = F_201 ( V_434 ,
V_440 , V_441 , V_430 ) ;
if ( V_428 == NULL )
goto V_436;
F_32 ( & V_442 ) ;
for ( V_154 = 0 ; V_154 < V_434 ; V_154 ++ ) {
V_275 = F_202 ( V_443 ) ;
if ( ! V_275 )
goto V_436;
F_203 ( V_275 , ( unsigned long ) V_425 ) ;
V_425 = V_275 ;
}
V_426 = V_434 ;
return 0 ;
V_436:
F_191 () ;
return - V_444 ;
}
static int F_204 ( struct V_445 * V_446 , unsigned long V_211 ,
void * V_447 )
{
return V_448 ;
}
static void F_205 ( struct V_4 * V_5 )
{
int V_449 ;
V_449 = F_206 ( V_5 , & V_5 -> V_371 ) ;
if ( V_449 )
F_120 ( V_168 , L_32 , V_449 ) ;
V_449 = F_206 ( V_5 , & V_5 -> V_372 ) ;
if ( V_449 )
F_120 ( V_168 , L_33 , V_449 ) ;
V_449 = F_206 ( V_5 , & V_5 -> V_374 ) ;
if ( V_449 )
F_120 ( V_168 , L_34 , V_449 ) ;
V_449 = F_206 ( V_5 , & V_5 -> V_373 ) ;
if ( V_449 )
F_120 ( V_168 , L_35 , V_449 ) ;
V_449 = F_206 ( V_5 , & V_5 -> V_375 ) ;
if ( V_449 )
F_120 ( V_168 , L_36 , V_449 ) ;
}
void F_207 ( struct V_57 * V_57 )
{
struct V_4 * V_5 = F_208 ( V_57 , struct V_4 , V_57 ) ;
struct V_13 * V_14 = V_5 -> V_14 ;
F_209 ( & V_5 -> V_394 ) ;
F_96 ( V_5 -> V_347 == 0 ) ;
if ( V_5 -> V_193 )
F_210 ( V_5 -> V_193 ) ;
F_189 ( V_5 -> V_124 ) ;
V_5 -> V_124 = NULL ;
F_205 ( V_5 ) ;
F_211 ( V_5 -> V_450 ) ;
F_211 ( V_5 -> V_451 ) ;
F_212 ( V_5 -> V_452 ) ;
if ( V_5 -> V_244 )
F_188 ( V_5 ) ;
F_193 ( V_5 -> V_453 ) ;
F_213 ( V_5 -> V_454 ) ;
F_214 ( V_5 -> V_455 ) ;
F_212 ( V_5 -> V_456 ) ;
F_212 ( V_5 ) ;
F_28 ( & V_14 -> V_57 , & V_58 ) ;
}
static void F_215 ( struct V_457 * V_458 )
{
struct V_459 * V_460 = F_208 ( V_458 , struct V_459 , V_71 ) ;
F_216 ( V_461 ) ;
struct V_17 * V_19 , * V_220 ;
F_9 ( & V_460 -> V_462 ) ;
F_217 ( & V_460 -> V_461 , & V_461 ) ;
F_14 ( & V_460 -> V_462 ) ;
F_18 (req, tmp, &writes, tl_requests) {
struct V_4 * V_5 = V_19 -> V_38 . V_5 ;
struct V_1 * V_1 = V_19 -> V_309 ;
unsigned long V_463 = V_19 -> V_463 ;
bool V_464 ;
V_464 =
F_128 ( F_218 ( & V_19 -> V_465 ) == 0 ) &&
F_128 ( V_19 -> V_24 & V_466 ) &&
F_128 ( ( V_19 -> V_24 & V_37 ) == 0 ||
( V_19 -> V_24 & V_467 ) != 0 ) ;
if ( ! V_464 )
F_120 ( V_168 , L_37 ,
V_19 , F_218 ( & V_19 -> V_465 ) ,
V_19 -> V_24 ) ;
F_28 ( & V_19 -> V_57 , V_468 ) ;
F_219 ( V_5 ) ;
F_220 ( V_5 , V_1 , V_463 ) ;
}
}
void F_221 ( struct V_17 * V_19 )
{
unsigned long V_43 ;
F_23 ( & V_460 . V_462 , V_43 ) ;
F_222 ( & V_19 -> V_469 , & V_460 . V_461 ) ;
F_25 ( & V_460 . V_462 , V_43 ) ;
F_223 ( V_19 -> V_38 . V_5 ) ;
F_224 ( V_460 . V_470 , & V_460 . V_71 ) ;
}
static void F_225 ( void )
{
unsigned int V_154 ;
struct V_4 * V_5 ;
struct V_13 * V_14 , * V_220 ;
F_226 ( & V_471 ) ;
if ( V_472 )
F_227 ( L_38 , NULL ) ;
if ( V_460 . V_470 )
F_228 ( V_460 . V_470 ) ;
F_229 () ;
F_230 (&minors, mdev, i) {
F_231 ( & V_473 , F_50 ( V_5 ) ) ;
F_231 ( & V_5 -> V_14 -> V_74 , V_5 -> V_72 ) ;
F_232 ( V_5 -> V_454 ) ;
F_28 ( & V_5 -> V_57 , & F_207 ) ;
}
F_18 (tconn, tmp, &drbd_tconns, all_tconn) {
F_233 ( & V_14 -> V_474 ) ;
F_28 ( & V_14 -> V_57 , & V_58 ) ;
}
F_191 () ;
F_234 ( V_475 , L_38 ) ;
F_235 ( & V_473 ) ;
F_236 ( V_476 L_39 ) ;
}
static int F_237 ( void * V_477 , int V_478 )
{
struct V_4 * V_5 = V_477 ;
struct V_479 * V_424 ;
char V_480 = '-' ;
int V_18 = 0 ;
if ( ! F_238 ( V_5 ) ) {
V_18 = V_478 ;
V_480 = 'd' ;
goto V_481;
}
if ( F_90 ( V_482 , & V_5 -> V_14 -> V_43 ) ) {
V_18 |= ( 1 << V_483 ) ;
if ( ! F_87 ( V_5 , V_174 ) )
V_18 |= ( 1 << V_484 ) ;
else
F_83 ( V_5 ) ;
V_18 &= V_478 ;
V_480 = 'c' ;
goto V_481;
}
if ( F_82 ( V_5 ) ) {
V_424 = F_239 ( V_5 -> V_124 -> V_185 ) ;
V_18 = F_240 ( & V_424 -> V_485 , V_478 ) ;
F_83 ( V_5 ) ;
if ( V_18 )
V_480 = 'b' ;
}
if ( V_478 & ( 1 << V_483 ) && F_90 ( V_274 , & V_5 -> V_14 -> V_43 ) ) {
V_18 |= ( 1 << V_483 ) ;
V_480 = V_480 == 'b' ? 'a' : 'n' ;
}
V_481:
V_5 -> V_486 = V_480 ;
return V_18 ;
}
static void F_241 ( struct V_487 * V_470 )
{
F_32 ( & V_470 -> V_488 ) ;
F_182 ( & V_470 -> V_424 ) ;
F_184 ( & V_470 -> V_489 ) ;
}
struct V_13 * F_242 ( const char * V_47 )
{
struct V_13 * V_14 ;
if ( ! V_47 || ! V_47 [ 0 ] )
return NULL ;
F_48 () ;
F_243 (tconn, &drbd_tconns, all_tconn) {
if ( ! strcmp ( V_14 -> V_47 , V_47 ) ) {
F_36 ( & V_14 -> V_57 ) ;
goto V_490;
}
}
V_14 = NULL ;
V_490:
F_51 () ;
return V_14 ;
}
struct V_13 * F_244 ( void * V_491 , int V_492 ,
void * V_493 , int V_494 )
{
struct V_13 * V_14 ;
F_48 () ;
F_243 (tconn, &drbd_tconns, all_tconn) {
if ( V_14 -> V_492 == V_492 &&
V_14 -> V_494 == V_494 &&
! memcmp ( & V_14 -> V_491 , V_491 , V_492 ) &&
! memcmp ( & V_14 -> V_493 , V_493 , V_494 ) ) {
F_36 ( & V_14 -> V_57 ) ;
goto V_490;
}
}
V_14 = NULL ;
V_490:
F_51 () ;
return V_14 ;
}
static int F_245 ( struct V_98 * V_100 )
{
V_100 -> V_495 = ( void * ) F_246 ( V_496 ) ;
if ( ! V_100 -> V_495 )
return - V_444 ;
V_100 -> V_101 = ( void * ) F_246 ( V_496 ) ;
if ( ! V_100 -> V_101 )
return - V_444 ;
return 0 ;
}
static void F_247 ( struct V_98 * V_100 )
{
F_248 ( ( unsigned long ) V_100 -> V_101 ) ;
F_248 ( ( unsigned long ) V_100 -> V_495 ) ;
}
void F_249 ( struct V_13 * V_14 )
{
F_250 ( V_14 ) ;
F_251 ( V_14 -> V_497 ) ;
F_251 ( V_14 -> V_498 ) ;
F_251 ( V_14 -> V_499 ) ;
F_251 ( V_14 -> V_308 ) ;
F_251 ( V_14 -> V_260 ) ;
F_212 ( V_14 -> V_500 ) ;
F_212 ( V_14 -> V_501 ) ;
V_14 -> V_497 = NULL ;
V_14 -> V_498 = NULL ;
V_14 -> V_499 = NULL ;
V_14 -> V_308 = NULL ;
V_14 -> V_260 = NULL ;
V_14 -> V_500 = NULL ;
V_14 -> V_501 = NULL ;
}
int F_252 ( struct V_13 * V_14 , struct V_502 * V_502 )
{
T_7 V_503 ;
int V_106 ;
if ( ! F_253 ( & V_503 , V_496 ) )
return - V_444 ;
if ( V_504 > 1 && V_502 -> V_77 [ 0 ] != 0 ) {
V_106 = F_254 ( V_502 -> V_77 , 32 ,
F_255 ( V_503 ) , V_504 ) ;
if ( V_106 ) {
F_256 ( V_14 , L_40 , V_106 ) ;
goto V_505;
}
}
V_14 -> V_502 = * V_502 ;
if ( ! F_257 ( V_14 -> V_77 , V_503 ) ) {
F_258 ( V_14 -> V_77 , V_503 ) ;
F_52 ( V_14 ) ;
V_14 -> V_69 . V_63 = 1 ;
V_14 -> V_70 . V_63 = 1 ;
V_14 -> V_71 . V_63 = 1 ;
}
V_106 = 0 ;
V_505:
F_259 ( V_503 ) ;
return V_106 ;
}
struct V_13 * F_260 ( const char * V_47 , struct V_502 * V_502 )
{
struct V_13 * V_14 ;
V_14 = F_261 ( sizeof( struct V_13 ) , V_496 ) ;
if ( ! V_14 )
return NULL ;
V_14 -> V_47 = F_262 ( V_47 , V_496 ) ;
if ( ! V_14 -> V_47 )
goto V_505;
if ( F_245 ( & V_14 -> V_104 ) )
goto V_505;
if ( F_245 ( & V_14 -> V_108 ) )
goto V_505;
if ( ! F_253 ( & V_14 -> V_77 , V_496 ) )
goto V_505;
if ( F_252 ( V_14 , V_502 ) )
goto V_505;
V_14 -> V_506 = F_261 ( sizeof( struct V_507 ) , V_496 ) ;
if ( ! V_14 -> V_506 )
goto V_505;
F_182 ( & V_14 -> V_508 ) ;
F_182 ( & V_14 -> V_506 -> V_378 ) ;
V_14 -> V_509 = 1 ;
F_32 ( & V_14 -> V_510 ) ;
V_14 -> V_511 = V_512 ;
V_14 -> V_513 . V_514 = false ;
V_14 -> V_513 . V_515 = 0 ;
V_14 -> V_513 . V_516 = 0 ;
V_14 -> V_247 = V_354 ;
F_181 ( & V_14 -> V_517 ) ;
F_32 ( & V_14 -> V_22 ) ;
F_181 ( & V_14 -> V_518 ) ;
F_184 ( & V_14 -> V_519 ) ;
F_263 ( & V_14 -> V_74 ) ;
F_241 ( & V_14 -> V_423 ) ;
F_181 ( & V_14 -> V_104 . V_102 ) ;
F_181 ( & V_14 -> V_108 . V_102 ) ;
F_30 ( V_14 , & V_14 -> V_69 , V_520 , L_41 ) ;
F_30 ( V_14 , & V_14 -> V_71 , V_521 , L_42 ) ;
F_30 ( V_14 , & V_14 -> V_70 , V_522 , L_43 ) ;
F_264 ( & V_14 -> V_57 ) ;
F_265 ( & V_14 -> V_474 , & V_523 ) ;
return V_14 ;
V_505:
F_212 ( V_14 -> V_506 ) ;
F_259 ( V_14 -> V_77 ) ;
F_247 ( & V_14 -> V_108 ) ;
F_247 ( & V_14 -> V_104 ) ;
F_212 ( V_14 -> V_47 ) ;
F_212 ( V_14 ) ;
return NULL ;
}
void V_58 ( struct V_57 * V_57 )
{
struct V_13 * V_14 = F_208 ( V_57 , struct V_13 , V_57 ) ;
if ( F_218 ( & V_14 -> V_506 -> V_524 ) != 0 )
F_11 ( V_14 , L_44 , F_218 ( & V_14 -> V_506 -> V_524 ) ) ;
F_212 ( V_14 -> V_506 ) ;
F_235 ( & V_14 -> V_74 ) ;
F_259 ( V_14 -> V_77 ) ;
F_247 ( & V_14 -> V_108 ) ;
F_247 ( & V_14 -> V_104 ) ;
F_212 ( V_14 -> V_47 ) ;
F_212 ( V_14 -> V_500 ) ;
F_212 ( V_14 -> V_501 ) ;
F_212 ( V_14 ) ;
}
enum V_525 F_266 ( struct V_13 * V_14 , unsigned int V_526 , int V_72 )
{
struct V_4 * V_5 ;
struct V_348 * V_11 ;
struct V_479 * V_424 ;
int V_527 = V_72 ;
int V_528 = V_526 ;
enum V_525 V_106 = V_529 ;
V_5 = F_267 ( V_526 ) ;
if ( V_5 )
return V_530 ;
V_5 = F_261 ( sizeof( struct V_4 ) , V_496 ) ;
if ( ! V_5 )
return V_529 ;
F_36 ( & V_14 -> V_57 ) ;
V_5 -> V_14 = V_14 ;
V_5 -> V_526 = V_526 ;
V_5 -> V_72 = V_72 ;
F_179 ( V_5 ) ;
V_424 = F_268 ( V_496 ) ;
if ( ! V_424 )
goto V_531;
V_5 -> V_455 = V_424 ;
V_424 -> V_532 = V_5 ;
V_11 = F_269 ( 1 ) ;
if ( ! V_11 )
goto V_533;
V_5 -> V_454 = V_11 ;
F_270 ( V_11 , true ) ;
V_11 -> V_188 = V_424 ;
V_11 -> V_534 = V_475 ;
V_11 -> V_535 = V_526 ;
V_11 -> V_536 = & V_537 ;
sprintf ( V_11 -> V_538 , L_45 , V_526 ) ;
V_11 -> V_339 = V_5 ;
V_5 -> V_193 = F_271 ( F_272 ( V_475 , V_526 ) ) ;
V_5 -> V_193 -> V_539 = V_5 -> V_193 ;
V_424 -> V_485 . V_540 = F_237 ;
V_424 -> V_485 . V_477 = V_5 ;
F_273 ( V_424 , V_541 ) ;
F_274 ( V_424 , V_302 | V_300 ) ;
F_275 ( V_424 , V_406 >> 8 ) ;
F_276 ( V_424 , V_542 ) ;
F_277 ( V_424 , V_543 ) ;
V_424 -> V_544 = & V_5 -> V_14 -> V_22 ;
V_5 -> V_453 = F_202 ( V_496 ) ;
if ( ! V_5 -> V_453 )
goto V_545;
if ( F_278 ( V_5 ) )
goto V_546;
V_5 -> V_547 = V_548 ;
V_5 -> V_549 = V_548 ;
if ( ! F_279 ( & V_473 , V_496 ) )
goto V_550;
if ( F_280 ( & V_473 , V_5 , V_526 , & V_528 ) )
goto V_550;
if ( V_528 != V_526 ) {
V_106 = V_530 ;
F_281 ( L_46 ) ;
goto V_551;
}
if ( ! F_279 ( & V_14 -> V_74 , V_496 ) )
goto V_551;
if ( F_280 ( & V_14 -> V_74 , V_5 , V_72 , & V_527 ) )
goto V_551;
if ( V_527 != V_72 ) {
V_106 = V_552 ;
F_281 ( L_47 ) ;
goto V_553;
}
F_282 ( V_11 ) ;
F_264 ( & V_5 -> V_57 ) ;
V_5 -> V_10 . V_31 = V_14 -> V_247 ;
if ( V_5 -> V_10 . V_31 == V_248 )
F_283 ( V_5 ) ;
return V_554 ;
V_553:
F_231 ( & V_14 -> V_74 , V_527 ) ;
V_551:
F_231 ( & V_473 , V_528 ) ;
F_284 () ;
V_550:
F_188 ( V_5 ) ;
V_546:
F_193 ( V_5 -> V_453 ) ;
V_545:
F_213 ( V_11 ) ;
V_533:
F_214 ( V_424 ) ;
V_531:
F_212 ( V_5 ) ;
F_28 ( & V_14 -> V_57 , & V_58 ) ;
return V_106 ;
}
int T_8 F_285 ( void )
{
int V_106 ;
if ( V_435 < V_555 || V_435 > V_556 ) {
F_236 ( V_557
L_48 , V_435 ) ;
#ifdef F_286
return - V_558 ;
#else
V_435 = V_559 ;
#endif
}
V_106 = F_287 ( V_475 , L_38 ) ;
if ( V_106 ) {
F_236 ( V_557
L_49 ,
V_475 ) ;
return V_106 ;
}
V_106 = F_288 () ;
if ( V_106 ) {
F_236 ( V_557 L_50 ) ;
goto V_505;
}
F_289 ( & V_471 ) ;
V_106 = - V_444 ;
F_184 ( & V_560 ) ;
V_472 = NULL ;
F_263 ( & V_473 ) ;
V_106 = F_197 () ;
if ( V_106 )
goto V_505;
V_472 = F_290 ( L_38 , V_561 | V_562 , NULL , & V_563 , NULL ) ;
if ( ! V_472 ) {
F_236 ( V_557 L_51 ) ;
goto V_505;
}
F_291 ( & V_564 ) ;
F_182 ( & V_523 ) ;
V_460 . V_470 = F_292 ( L_52 ) ;
if ( ! V_460 . V_470 ) {
F_236 ( V_557 L_53 ) ;
goto V_505;
}
F_293 ( & V_460 . V_71 , F_215 ) ;
F_32 ( & V_460 . V_462 ) ;
F_182 ( & V_460 . V_461 ) ;
F_236 ( V_476 L_54
L_55 V_565 L_56 ,
V_566 , V_567 , V_568 ) ;
F_236 ( V_476 L_57 , F_294 () ) ;
F_236 ( V_476 L_58 ,
V_475 ) ;
return 0 ;
V_505:
F_225 () ;
if ( V_106 == - V_444 )
F_236 ( V_557 L_59 ) ;
else
F_236 ( V_557 L_60 ) ;
return V_106 ;
}
void F_189 ( struct V_569 * V_124 )
{
if ( V_124 == NULL )
return;
F_295 ( V_124 -> V_185 , V_570 | V_343 | V_571 ) ;
F_295 ( V_124 -> V_572 , V_570 | V_343 | V_571 ) ;
F_212 ( V_124 ) ;
}
void F_250 ( struct V_13 * V_14 )
{
if ( V_14 -> V_104 . V_100 ) {
F_70 ( & V_14 -> V_104 . V_102 ) ;
F_296 ( V_14 -> V_104 . V_100 , V_573 ) ;
F_297 ( V_14 -> V_104 . V_100 ) ;
V_14 -> V_104 . V_100 = NULL ;
F_71 ( & V_14 -> V_104 . V_102 ) ;
}
if ( V_14 -> V_108 . V_100 ) {
F_70 ( & V_14 -> V_108 . V_102 ) ;
F_296 ( V_14 -> V_108 . V_100 , V_573 ) ;
F_297 ( V_14 -> V_108 . V_100 ) ;
V_14 -> V_108 . V_100 = NULL ;
F_71 ( & V_14 -> V_108 . V_102 ) ;
}
}
void F_298 ( struct V_13 * V_14 )
{
struct V_4 * V_5 ;
int V_72 ;
F_48 () ;
F_230 (&tconn->volumes, mdev, vnr) {
F_36 ( & V_5 -> V_57 ) ;
F_51 () ;
F_99 ( V_5 ) ;
F_28 ( & V_5 -> V_57 , & F_207 ) ;
F_48 () ;
}
F_51 () ;
}
void F_99 ( struct V_4 * V_5 )
{
struct V_574 * V_96 ;
T_3 V_251 ;
int V_154 ;
F_299 ( & V_5 -> V_392 ) ;
if ( ! F_300 ( V_575 , & V_5 -> V_43 ) )
return;
if ( ! F_87 ( V_5 , V_576 ) )
return;
V_96 = F_301 ( V_5 ) ;
if ( ! V_96 )
goto V_481;
memset ( V_96 , 0 , 512 ) ;
V_96 -> V_577 = F_88 ( F_105 ( V_5 -> V_193 ) ) ;
for ( V_154 = V_158 ; V_154 < V_159 ; V_154 ++ )
V_96 -> V_160 [ V_154 ] = F_88 ( V_5 -> V_124 -> V_156 . V_160 [ V_154 ] ) ;
V_96 -> V_43 = F_63 ( V_5 -> V_124 -> V_156 . V_43 ) ;
V_96 -> V_88 = F_63 ( V_578 ) ;
V_96 -> V_579 = F_63 ( V_5 -> V_124 -> V_156 . V_579 ) ;
V_96 -> V_580 = F_63 ( V_5 -> V_124 -> V_156 . V_580 ) ;
V_96 -> V_581 = F_63 ( V_5 -> V_450 -> V_582 ) ;
V_96 -> V_583 = F_63 ( V_584 ) ;
V_96 -> V_585 = F_88 ( V_5 -> V_124 -> V_156 . V_585 ) ;
V_96 -> V_586 = F_63 ( V_5 -> V_124 -> V_156 . V_586 ) ;
V_96 -> V_587 = F_63 ( V_5 -> V_405 ) ;
F_96 ( F_302 ( V_5 , V_5 -> V_124 ) == V_5 -> V_124 -> V_156 . V_588 ) ;
V_251 = V_5 -> V_124 -> V_156 . V_588 ;
if ( F_303 ( V_5 , V_5 -> V_124 , V_251 , V_589 ) ) {
F_120 ( V_168 , L_61 ) ;
F_304 ( V_5 , 1 , V_590 ) ;
}
V_5 -> V_124 -> V_156 . V_591 = F_105 ( V_5 -> V_193 ) ;
F_305 ( V_5 ) ;
V_481:
F_83 ( V_5 ) ;
}
int F_306 ( struct V_4 * V_5 , struct V_569 * V_337 )
{
struct V_574 * V_96 ;
T_4 V_88 , V_43 ;
int V_154 , V_325 = V_554 ;
if ( ! F_87 ( V_5 , V_592 ) )
return V_593 ;
V_96 = F_301 ( V_5 ) ;
if ( ! V_96 )
goto V_481;
if ( F_303 ( V_5 , V_337 , V_337 -> V_156 . V_588 , V_594 ) ) {
F_120 ( V_168 , L_62 ) ;
V_325 = V_593 ;
goto V_106;
}
V_88 = F_307 ( V_96 -> V_88 ) ;
V_43 = F_307 ( V_96 -> V_43 ) ;
if ( V_88 == V_578 ||
( V_88 == V_595 && ! ( V_43 & V_596 ) ) ) {
F_120 ( V_168 , L_63 ) ;
V_325 = V_597 ;
goto V_106;
}
if ( V_88 != V_595 ) {
if ( V_88 == V_598 )
F_120 ( V_168 , L_64 ) ;
else
F_120 ( V_168 , L_65 ) ;
V_325 = V_599 ;
goto V_106;
}
if ( F_307 ( V_96 -> V_580 ) != V_337 -> V_156 . V_580 ) {
F_120 ( V_168 , L_66 ,
F_307 ( V_96 -> V_580 ) , V_337 -> V_156 . V_580 ) ;
V_325 = V_599 ;
goto V_106;
}
if ( F_307 ( V_96 -> V_586 ) != V_337 -> V_156 . V_586 ) {
F_120 ( V_168 , L_67 ,
F_307 ( V_96 -> V_586 ) , V_337 -> V_156 . V_586 ) ;
V_325 = V_599 ;
goto V_106;
}
if ( F_307 ( V_96 -> V_579 ) != V_337 -> V_156 . V_579 ) {
F_120 ( V_168 , L_68 ,
F_307 ( V_96 -> V_579 ) , V_337 -> V_156 . V_579 ) ;
V_325 = V_599 ;
goto V_106;
}
if ( F_307 ( V_96 -> V_583 ) != V_584 ) {
F_120 ( V_168 , L_69 ,
F_307 ( V_96 -> V_583 ) , V_584 ) ;
V_325 = V_599 ;
goto V_106;
}
V_337 -> V_156 . V_591 = F_308 ( V_96 -> V_577 ) ;
for ( V_154 = V_158 ; V_154 < V_159 ; V_154 ++ )
V_337 -> V_156 . V_160 [ V_154 ] = F_308 ( V_96 -> V_160 [ V_154 ] ) ;
V_337 -> V_156 . V_43 = F_307 ( V_96 -> V_43 ) ;
V_337 -> V_156 . V_585 = F_308 ( V_96 -> V_585 ) ;
F_9 ( & V_5 -> V_14 -> V_22 ) ;
if ( V_5 -> V_10 . V_31 < V_255 ) {
unsigned int V_352 ;
V_352 = F_307 ( V_96 -> V_587 ) ;
V_352 = F_309 ( V_352 , V_406 ) ;
V_5 -> V_405 = V_352 ;
}
F_14 ( & V_5 -> V_14 -> V_22 ) ;
V_106:
F_305 ( V_5 ) ;
V_481:
F_83 ( V_5 ) ;
return V_325 ;
}
void F_310 ( struct V_4 * V_5 , unsigned int line , const char * F_31 )
{
if ( ! F_311 ( V_575 , & V_5 -> V_43 ) ) {
F_312 ( & V_5 -> V_392 , V_600 + V_601 ) ;
V_5 -> V_602 . line = line ;
V_5 -> V_602 . F_31 = F_31 ;
}
}
void F_313 ( struct V_4 * V_5 )
{
if ( ! F_311 ( V_575 , & V_5 -> V_43 ) )
F_312 ( & V_5 -> V_392 , V_600 + 5 * V_601 ) ;
}
void F_314 ( struct V_4 * V_5 ) __must_hold( T_9 )
{
int V_154 ;
for ( V_154 = V_170 ; V_154 < V_171 ; V_154 ++ )
V_5 -> V_124 -> V_156 . V_160 [ V_154 + 1 ] = V_5 -> V_124 -> V_156 . V_160 [ V_154 ] ;
}
void F_315 ( struct V_4 * V_5 , int V_603 , T_2 V_200 ) __must_hold( T_9 )
{
if ( V_603 == V_158 ) {
if ( V_5 -> V_10 . V_341 == V_342 )
V_200 |= 1 ;
else
V_200 &= ~ ( ( T_2 ) 1 ) ;
F_316 ( V_5 , V_200 ) ;
}
V_5 -> V_124 -> V_156 . V_160 [ V_603 ] = V_200 ;
F_313 ( V_5 ) ;
}
void F_317 ( struct V_4 * V_5 , int V_603 , T_2 V_200 ) __must_hold( T_9 )
{
unsigned long V_43 ;
F_23 ( & V_5 -> V_124 -> V_156 . V_157 , V_43 ) ;
F_315 ( V_5 , V_603 , V_200 ) ;
F_25 ( & V_5 -> V_124 -> V_156 . V_157 , V_43 ) ;
}
void F_98 ( struct V_4 * V_5 , int V_603 , T_2 V_200 ) __must_hold( T_9 )
{
unsigned long V_43 ;
F_23 ( & V_5 -> V_124 -> V_156 . V_157 , V_43 ) ;
if ( V_5 -> V_124 -> V_156 . V_160 [ V_603 ] ) {
F_314 ( V_5 ) ;
V_5 -> V_124 -> V_156 . V_160 [ V_170 ] = V_5 -> V_124 -> V_156 . V_160 [ V_603 ] ;
}
F_315 ( V_5 , V_603 , V_200 ) ;
F_25 ( & V_5 -> V_124 -> V_156 . V_157 , V_43 ) ;
}
void F_318 ( struct V_4 * V_5 ) __must_hold( T_9 )
{
T_2 V_200 ;
unsigned long long V_604 ;
F_97 ( & V_200 , sizeof( T_2 ) ) ;
F_9 ( & V_5 -> V_124 -> V_156 . V_157 ) ;
V_604 = V_5 -> V_124 -> V_156 . V_160 [ V_169 ] ;
if ( V_604 )
F_160 ( V_168 , L_70 , V_604 ) ;
V_5 -> V_124 -> V_156 . V_160 [ V_169 ] = V_5 -> V_124 -> V_156 . V_160 [ V_158 ] ;
F_315 ( V_5 , V_158 , V_200 ) ;
F_14 ( & V_5 -> V_124 -> V_156 . V_157 ) ;
F_93 ( V_5 , L_71 ) ;
F_99 ( V_5 ) ;
}
void F_319 ( struct V_4 * V_5 , T_2 V_200 ) __must_hold( T_9 )
{
unsigned long V_43 ;
if ( V_5 -> V_124 -> V_156 . V_160 [ V_169 ] == 0 && V_200 == 0 )
return;
F_23 ( & V_5 -> V_124 -> V_156 . V_157 , V_43 ) ;
if ( V_200 == 0 ) {
F_314 ( V_5 ) ;
V_5 -> V_124 -> V_156 . V_160 [ V_170 ] = V_5 -> V_124 -> V_156 . V_160 [ V_169 ] ;
V_5 -> V_124 -> V_156 . V_160 [ V_169 ] = 0 ;
} else {
unsigned long long V_604 = V_5 -> V_124 -> V_156 . V_160 [ V_169 ] ;
if ( V_604 )
F_160 ( V_168 , L_70 , V_604 ) ;
V_5 -> V_124 -> V_156 . V_160 [ V_169 ] = V_200 & ~ ( ( T_2 ) 1 ) ;
}
F_25 ( & V_5 -> V_124 -> V_156 . V_157 , V_43 ) ;
F_313 ( V_5 ) ;
}
int F_320 ( struct V_4 * V_5 )
{
int V_325 = - V_109 ;
if ( F_87 ( V_5 , V_592 ) ) {
F_321 ( V_5 , V_245 ) ;
F_99 ( V_5 ) ;
F_130 ( V_5 ) ;
V_325 = F_131 ( V_5 ) ;
if ( ! V_325 ) {
F_132 ( V_5 , V_245 ) ;
F_99 ( V_5 ) ;
}
F_83 ( V_5 ) ;
}
return V_325 ;
}
int F_322 ( struct V_4 * V_5 )
{
int V_325 = - V_109 ;
F_323 ( V_5 ) ;
if ( F_87 ( V_5 , V_592 ) ) {
F_324 ( V_5 ) ;
V_325 = F_131 ( V_5 ) ;
F_83 ( V_5 ) ;
}
return V_325 ;
}
static int V_389 ( struct V_605 * V_38 , int V_447 )
{
struct V_383 * V_606 = F_208 ( V_38 , struct V_383 , V_38 ) ;
struct V_4 * V_5 = V_38 -> V_5 ;
int V_325 = - V_109 ;
F_96 ( F_218 ( & V_5 -> V_358 ) == 0 ) ;
if ( F_82 ( V_5 ) ) {
F_325 ( V_5 , V_606 -> V_607 , V_606 -> V_43 ) ;
V_325 = V_606 -> V_608 ( V_5 ) ;
F_326 ( V_5 ) ;
F_83 ( V_5 ) ;
}
F_327 ( V_609 , & V_5 -> V_43 ) ;
F_7 ( & V_5 -> V_12 ) ;
if ( V_606 -> V_610 )
V_606 -> V_610 ( V_5 , V_325 ) ;
F_161 ( V_611 , & V_5 -> V_43 ) ;
V_606 -> V_607 = NULL ;
V_606 -> V_43 = 0 ;
return 0 ;
}
void F_328 ( struct V_4 * V_5 )
{
F_211 ( V_5 -> V_451 ) ;
V_5 -> V_451 = NULL ;
F_211 ( V_5 -> V_450 ) ;
V_5 -> V_450 = NULL ;
F_329 (local,
drbd_free_bc(mdev->ldev);
mdev->ldev = NULL;) ;
F_161 ( V_612 , & V_5 -> V_43 ) ;
}
static int V_387 ( struct V_605 * V_38 , int V_447 )
{
struct V_4 * V_5 = V_38 -> V_5 ;
F_96 ( V_5 -> V_10 . V_11 == V_576 ) ;
if ( V_5 -> V_244 && V_5 -> V_124 ) {
if ( F_330 ( V_5 , F_131 ,
L_72 , V_613 ) ) {
if ( F_90 ( V_614 , & V_5 -> V_43 ) ) {
F_321 ( V_5 , V_245 ) ;
F_99 ( V_5 ) ;
}
}
}
F_331 ( V_5 , F_16 ( V_11 , V_355 ) ) ;
return 0 ;
}
void F_332 ( struct V_4 * V_5 )
{
F_96 ( V_5 -> V_10 . V_11 == V_576 ) ;
if ( ! F_311 ( V_612 , & V_5 -> V_43 ) )
F_333 ( & V_5 -> V_14 -> V_423 , & V_5 -> V_380 ) ;
}
void F_334 ( struct V_4 * V_5 ,
int (* V_608)( struct V_4 * ) ,
void (* V_610)( struct V_4 * , int ) ,
char * V_607 , enum V_615 V_43 )
{
F_96 ( V_45 == V_5 -> V_14 -> V_71 . V_54 ) ;
F_96 ( ! F_90 ( V_611 , & V_5 -> V_43 ) ) ;
F_96 ( ! F_90 ( V_609 , & V_5 -> V_43 ) ) ;
F_96 ( F_190 ( & V_5 -> V_383 . V_38 . V_378 ) ) ;
if ( V_5 -> V_383 . V_607 )
F_120 ( V_168 , L_73 ,
V_607 , V_5 -> V_383 . V_607 ) ;
V_5 -> V_383 . V_608 = V_608 ;
V_5 -> V_383 . V_610 = V_610 ;
V_5 -> V_383 . V_607 = V_607 ;
V_5 -> V_383 . V_43 = V_43 ;
F_9 ( & V_5 -> V_14 -> V_22 ) ;
F_151 ( V_609 , & V_5 -> V_43 ) ;
if ( F_218 ( & V_5 -> V_358 ) == 0 ) {
if ( ! F_311 ( V_611 , & V_5 -> V_43 ) )
F_333 ( & V_5 -> V_14 -> V_423 , & V_5 -> V_383 . V_38 ) ;
}
F_14 ( & V_5 -> V_14 -> V_22 ) ;
}
int F_335 ( struct V_4 * V_5 , int (* V_608)( struct V_4 * ) ,
char * V_607 , enum V_615 V_43 )
{
int V_325 ;
F_96 ( V_45 != V_5 -> V_14 -> V_71 . V_54 ) ;
if ( ( V_43 & V_616 ) == 0 )
F_336 ( V_5 ) ;
F_325 ( V_5 , V_607 , V_43 ) ;
V_325 = V_608 ( V_5 ) ;
F_326 ( V_5 ) ;
if ( ( V_43 & V_616 ) == 0 )
F_337 ( V_5 ) ;
return V_325 ;
}
void F_321 ( struct V_4 * V_5 , int V_617 ) __must_hold( T_9 )
{
if ( ( V_5 -> V_124 -> V_156 . V_43 & V_617 ) != V_617 ) {
F_313 ( V_5 ) ;
V_5 -> V_124 -> V_156 . V_43 |= V_617 ;
}
}
void F_132 ( struct V_4 * V_5 , int V_617 ) __must_hold( T_9 )
{
if ( ( V_5 -> V_124 -> V_156 . V_43 & V_617 ) != 0 ) {
F_313 ( V_5 ) ;
V_5 -> V_124 -> V_156 . V_43 &= ~ V_617 ;
}
}
int F_129 ( struct V_569 * V_337 , int V_617 )
{
return ( V_337 -> V_156 . V_43 & V_617 ) != 0 ;
}
static void V_396 ( unsigned long V_104 )
{
struct V_4 * V_5 = (struct V_4 * ) V_104 ;
if ( F_190 ( & V_5 -> V_381 . V_378 ) )
F_338 ( & V_5 -> V_14 -> V_423 , & V_5 -> V_381 ) ;
}
static int V_388 ( struct V_605 * V_38 , int V_447 )
{
struct V_4 * V_5 = V_38 -> V_5 ;
F_160 ( V_168 , L_74 ) ;
#ifdef F_339
F_160 ( V_168 , L_75 ,
V_5 -> V_602 . F_31 , V_5 -> V_602 . line ) ;
#endif
F_99 ( V_5 ) ;
return 0 ;
}
const char * F_340 ( enum V_85 V_86 )
{
static const char * V_618 [] = {
[ V_317 ] = L_76 ,
[ V_619 ] = L_77 ,
[ V_620 ] = L_78 ,
[ V_621 ] = L_79 ,
[ V_243 ] = L_80 ,
[ V_622 ] = L_81 ,
[ V_623 ] = L_82 ,
[ V_624 ] = L_83 ,
[ V_625 ] = L_84 ,
[ V_626 ] = L_85 ,
[ V_122 ] = L_86 ,
[ V_121 ] = L_87 ,
[ V_151 ] = L_88 ,
[ V_166 ] = L_89 ,
[ V_195 ] = L_90 ,
[ V_197 ] = L_91 ,
[ V_177 ] = L_92 ,
[ V_627 ] = L_93 ,
[ V_628 ] = L_94 ,
[ V_110 ] = L_95 ,
[ V_111 ] = L_96 ,
[ V_629 ] = L_97 ,
[ V_630 ] = L_98 ,
[ V_631 ] = L_99 ,
[ V_632 ] = L_100 ,
[ V_633 ] = L_101 ,
[ V_634 ] = L_102 ,
[ V_635 ] = L_103 ,
[ V_250 ] = L_104 ,
[ V_202 ] = L_105 ,
[ V_207 ] = L_106 ,
[ V_268 ] = L_107 ,
[ V_636 ] = L_108 ,
[ V_637 ] = L_109 ,
[ V_638 ] = L_110 ,
[ V_639 ] = L_111 ,
[ V_236 ] = L_112 ,
[ V_640 ] = L_113 ,
[ V_319 ] = L_114 ,
[ V_641 ] = L_115 ,
[ V_642 ] = L_116 ,
[ V_203 ] = L_117 ,
[ V_208 ] = L_118 ,
[ V_641 ] = L_119 ,
[ V_643 ] = L_120 ,
} ;
if ( V_86 == V_644 )
return L_121 ;
if ( V_86 == V_645 )
return L_122 ;
if ( V_86 == V_646 )
return L_123 ;
if ( V_86 >= F_33 ( V_618 ) )
return L_124 ;
return V_618 [ V_86 ] ;
}
int F_341 ( struct V_4 * V_5 , struct V_647 * V_154 )
{
struct V_114 * V_115 ;
F_342 ( V_65 ) ;
long V_648 ;
F_48 () ;
V_115 = F_81 ( V_5 -> V_14 -> V_114 ) ;
if ( ! V_115 ) {
F_51 () ;
return - V_649 ;
}
V_648 = V_115 -> V_270 ? V_115 -> V_648 * V_601 / 10 * V_115 -> V_270 : V_650 ;
F_51 () ;
V_154 -> V_651 = true ;
F_343 ( & V_5 -> V_12 , & V_65 , V_652 ) ;
F_14 ( & V_5 -> V_14 -> V_22 ) ;
V_648 = F_344 ( V_648 ) ;
F_345 ( & V_5 -> V_12 , & V_65 ) ;
F_9 ( & V_5 -> V_14 -> V_22 ) ;
if ( ! V_648 || V_5 -> V_10 . V_31 < V_255 )
return - V_649 ;
if ( F_346 ( V_45 ) )
return - V_653 ;
return 0 ;
}
static unsigned long
F_347 ( struct V_654 * V_655 )
{
long V_656 ;
if ( ! V_655 -> V_657 -- ) {
F_97 ( & V_656 , sizeof( V_656 ) ) ;
V_655 -> V_10 += V_656 ;
V_655 -> V_657 = V_658 ;
}
V_655 -> V_10 = V_655 -> V_10 * V_659 + V_660 ;
return F_348 ( V_655 -> V_10 ) ;
}
static char *
F_349 ( unsigned int type ) {
static char * V_661 [] = {
[ V_662 ] = L_125 ,
[ V_663 ] = L_126 ,
[ V_664 ] = L_127 ,
[ V_665 ] = L_128 ,
[ V_666 ] = L_129 ,
[ V_667 ] = L_130 ,
[ V_668 ] = L_131 ,
[ V_669 ] = L_132 ,
[ V_670 ] = L_133 ,
[ V_671 ] = L_134 ,
} ;
return ( type < V_672 ) ? V_661 [ type ] : L_135 ;
}
unsigned int
F_350 ( struct V_4 * V_5 , unsigned int type )
{
static struct V_654 V_673 = { 0 , 0 } ;
unsigned int V_674 = (
( V_675 == 0 ||
( ( 1 << F_50 ( V_5 ) ) & V_675 ) != 0 ) &&
( ( ( F_347 ( & V_673 ) % 100 ) + 1 ) <= V_676 ) ) ;
if ( V_674 ) {
V_677 ++ ;
if ( F_351 ( & V_678 ) )
F_160 ( V_168 , L_136 ,
F_349 ( type ) ) ;
}
return V_674 ;
}
const char * F_294 ( void )
{
static char V_679 [ 38 ] = L_137 ;
if ( V_679 [ 0 ] == 0 ) {
#ifdef F_286
sprintf ( V_679 , L_138 , V_59 -> V_680 ) ;
#else
V_679 [ 0 ] = 'b' ;
#endif
}
return V_679 ;
}
