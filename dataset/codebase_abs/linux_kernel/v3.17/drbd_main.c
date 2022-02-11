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
F_9 ( & V_14 -> V_22 -> V_23 ) ;
F_10 (r, &connection->transfer_log, tl_requests) {
const unsigned V_24 = V_18 -> V_25 ;
if ( ! V_19 ) {
if ( ! ( V_24 & V_26 ) )
continue;
if ( ! ( V_24 & V_27 ) )
continue;
if ( V_24 & V_28 )
continue;
V_19 = V_18 ;
V_20 = V_19 -> V_29 ;
V_21 ++ ;
} else {
if ( V_18 -> V_29 != V_20 )
break;
if ( ! ( V_24 & V_26 ) )
continue;
V_21 ++ ;
}
}
if ( V_19 == NULL ) {
F_11 ( V_14 , L_1 ,
V_15 ) ;
goto V_30;
}
if ( V_20 != V_15 ) {
F_11 ( V_14 , L_2 ,
V_15 , V_20 ) ;
goto V_30;
}
if ( V_21 != V_16 ) {
F_11 ( V_14 , L_3 ,
V_15 , V_16 , V_21 ) ;
goto V_30;
}
F_10 (req, &connection->transfer_log, tl_requests)
if ( V_19 -> V_29 == V_20 )
break;
F_12 (req, r, &connection->transfer_log, tl_requests) {
if ( V_19 -> V_29 != V_20 )
break;
F_13 ( V_19 , V_31 ) ;
}
F_14 ( & V_14 -> V_22 -> V_23 ) ;
return;
V_30:
F_14 ( & V_14 -> V_22 -> V_23 ) ;
F_15 ( V_14 , F_16 ( V_32 , V_33 ) , V_34 ) ;
}
void F_17 ( struct V_13 * V_14 , enum V_35 V_36 )
{
struct V_17 * V_19 , * V_18 ;
F_18 (req, r, &connection->transfer_log, tl_requests)
F_13 ( V_19 , V_36 ) ;
}
void F_19 ( struct V_13 * V_14 , enum V_35 V_36 )
{
F_9 ( & V_14 -> V_22 -> V_23 ) ;
F_17 ( V_14 , V_36 ) ;
F_14 ( & V_14 -> V_22 -> V_23 ) ;
}
void F_20 ( struct V_13 * V_14 )
{
F_19 ( V_14 , V_37 ) ;
}
void F_21 ( struct V_4 * V_5 )
{
struct V_13 * V_14 = F_22 ( V_5 ) -> V_14 ;
struct V_17 * V_19 , * V_18 ;
F_9 ( & V_14 -> V_22 -> V_23 ) ;
F_18 (req, r, &connection->transfer_log, tl_requests) {
if ( ! ( V_19 -> V_25 & V_38 ) )
continue;
if ( V_19 -> V_5 != V_5 )
continue;
F_13 ( V_19 , V_39 ) ;
}
F_14 ( & V_14 -> V_22 -> V_23 ) ;
}
static int F_23 ( void * V_40 )
{
struct V_41 * V_42 = (struct V_41 * ) V_40 ;
struct V_43 * V_22 = V_42 -> V_22 ;
unsigned long V_44 ;
int V_45 ;
snprintf ( V_46 -> V_47 , sizeof( V_46 -> V_47 ) , L_4 ,
V_42 -> V_48 [ 0 ] ,
V_22 -> V_48 ) ;
V_49:
V_45 = V_42 -> V_50 ( V_42 ) ;
F_24 ( & V_42 -> V_51 , V_44 ) ;
if ( V_42 -> V_52 == V_53 ) {
F_25 ( V_22 , L_5 , V_42 -> V_48 ) ;
V_42 -> V_52 = V_54 ;
F_26 ( & V_42 -> V_51 , V_44 ) ;
goto V_49;
}
V_42 -> V_55 = NULL ;
V_42 -> V_52 = V_56 ;
F_27 () ;
F_28 ( & V_42 -> V_57 ) ;
F_26 ( & V_42 -> V_51 , V_44 ) ;
F_25 ( V_22 , L_6 , V_46 -> V_47 ) ;
if ( V_42 -> V_14 )
F_29 ( & V_42 -> V_14 -> V_58 , V_59 ) ;
F_29 ( & V_22 -> V_58 , V_60 ) ;
F_30 ( V_61 ) ;
return V_45 ;
}
static void F_31 ( struct V_43 * V_22 , struct V_41 * V_42 ,
int (* F_32) ( struct V_41 * ) , const char * V_48 )
{
F_33 ( & V_42 -> V_51 ) ;
V_42 -> V_55 = NULL ;
V_42 -> V_52 = V_56 ;
V_42 -> V_50 = F_32 ;
V_42 -> V_22 = V_22 ;
V_42 -> V_14 = NULL ;
V_42 -> V_48 = V_48 ;
}
int F_34 ( struct V_41 * V_42 )
{
struct V_43 * V_22 = V_42 -> V_22 ;
struct V_62 * V_63 ;
unsigned long V_44 ;
F_24 ( & V_42 -> V_51 , V_44 ) ;
switch ( V_42 -> V_52 ) {
case V_56 :
F_25 ( V_22 , L_7 ,
V_42 -> V_48 , V_46 -> V_47 , V_46 -> V_64 ) ;
if ( ! F_35 ( V_61 ) ) {
F_11 ( V_22 , L_8 ) ;
F_26 ( & V_42 -> V_51 , V_44 ) ;
return false ;
}
F_36 ( & V_22 -> V_58 ) ;
if ( V_42 -> V_14 )
F_36 ( & V_42 -> V_14 -> V_58 ) ;
F_37 ( & V_42 -> V_57 ) ;
V_42 -> V_65 = 1 ;
V_42 -> V_52 = V_54 ;
F_26 ( & V_42 -> V_51 , V_44 ) ;
F_38 ( V_46 ) ;
V_63 = F_39 ( F_23 , ( void * ) V_42 ,
L_4 , V_42 -> V_48 [ 0 ] , V_42 -> V_22 -> V_48 ) ;
if ( F_40 ( V_63 ) ) {
F_11 ( V_22 , L_9 ) ;
if ( V_42 -> V_14 )
F_29 ( & V_42 -> V_14 -> V_58 , V_59 ) ;
F_29 ( & V_22 -> V_58 , V_60 ) ;
F_30 ( V_61 ) ;
return false ;
}
F_24 ( & V_42 -> V_51 , V_44 ) ;
V_42 -> V_55 = V_63 ;
V_42 -> V_52 = V_54 ;
F_26 ( & V_42 -> V_51 , V_44 ) ;
F_41 ( V_63 ) ;
break;
case V_66 :
V_42 -> V_52 = V_53 ;
F_25 ( V_22 , L_10 ,
V_42 -> V_48 , V_46 -> V_47 , V_46 -> V_64 ) ;
case V_54 :
case V_53 :
default:
F_26 ( & V_42 -> V_51 , V_44 ) ;
break;
}
return true ;
}
void F_42 ( struct V_41 * V_42 , int V_49 , int V_67 )
{
unsigned long V_44 ;
enum V_68 V_69 = V_49 ? V_53 : V_66 ;
F_24 ( & V_42 -> V_51 , V_44 ) ;
if ( V_42 -> V_52 == V_56 ) {
F_26 ( & V_42 -> V_51 , V_44 ) ;
if ( V_49 )
F_34 ( V_42 ) ;
return;
}
if ( V_42 -> V_52 != V_69 ) {
if ( V_42 -> V_55 == NULL ) {
F_26 ( & V_42 -> V_51 , V_44 ) ;
return;
}
V_42 -> V_52 = V_69 ;
F_27 () ;
F_37 ( & V_42 -> V_57 ) ;
if ( V_42 -> V_55 != V_46 )
F_43 ( V_70 , V_42 -> V_55 ) ;
}
F_26 ( & V_42 -> V_51 , V_44 ) ;
if ( V_67 )
F_44 ( & V_42 -> V_57 ) ;
}
int F_45 ( struct V_13 * V_14 )
{
struct V_71 * V_72 ;
int V_73 = 0 , V_74 = - 1 ;
F_46 () ;
V_72 = F_47 ( & V_14 -> V_75 , & V_73 ) ;
if ( V_72 )
V_74 = F_48 ( V_72 -> V_5 ) ;
F_49 () ;
return V_74 ;
}
static void F_50 ( T_2 * V_76 )
{
unsigned int * V_77 , V_78 = ~ 0 ;
V_77 = F_51 ( V_79 * sizeof( * V_77 ) , V_80 ) ;
if ( V_77 ) {
struct V_43 * V_22 ;
unsigned int V_81 , V_82 = ~ 0 ;
F_46 () ;
F_52 (resource, &drbd_resources) {
F_53 (cpu, resource->cpu_mask)
V_77 [ V_81 ] ++ ;
}
F_49 () ;
F_54 (cpu) {
if ( V_77 [ V_81 ] < V_82 ) {
V_82 = V_77 [ V_81 ] ;
V_78 = V_81 ;
}
}
F_55 ( V_77 ) ;
}
if ( V_78 == ~ 0 ) {
F_56 ( * V_76 ) ;
return;
}
F_57 ( V_78 , * V_76 ) ;
}
void F_58 ( struct V_41 * V_42 )
{
struct V_43 * V_22 = V_42 -> V_22 ;
struct V_62 * V_83 = V_46 ;
if ( ! V_42 -> V_65 )
return;
V_42 -> V_65 = 0 ;
F_59 ( V_83 , V_22 -> V_76 ) ;
}
unsigned int F_60 ( struct V_13 * V_14 )
{
if ( V_14 -> V_84 >= 100 ) {
F_61 ( ! F_62 ( sizeof( struct V_85 ) , 8 ) ) ;
return sizeof( struct V_85 ) ;
} else {
F_61 ( sizeof( struct V_86 ) !=
sizeof( struct V_87 ) ) ;
F_61 ( ! F_62 ( sizeof( struct V_86 ) , 8 ) ) ;
return sizeof( struct V_86 ) ;
}
}
static unsigned int F_63 ( struct V_86 * V_88 , enum V_89 V_90 , int V_91 )
{
V_88 -> V_92 = F_64 ( V_93 ) ;
V_88 -> V_94 = F_65 ( V_90 ) ;
V_88 -> V_95 = F_65 ( V_91 ) ;
return sizeof( struct V_86 ) ;
}
static unsigned int F_66 ( struct V_87 * V_88 , enum V_89 V_90 , int V_91 )
{
V_88 -> V_92 = F_65 ( V_96 ) ;
V_88 -> V_94 = F_65 ( V_90 ) ;
V_88 -> V_95 = F_64 ( V_91 ) ;
return sizeof( struct V_87 ) ;
}
static unsigned int F_67 ( struct V_85 * V_88 , enum V_89 V_90 ,
int V_91 , int V_73 )
{
V_88 -> V_92 = F_64 ( V_97 ) ;
V_88 -> V_98 = F_65 ( V_73 ) ;
V_88 -> V_94 = F_65 ( V_90 ) ;
V_88 -> V_95 = F_64 ( V_91 ) ;
V_88 -> V_99 = 0 ;
return sizeof( struct V_85 ) ;
}
static unsigned int F_68 ( struct V_13 * V_14 , int V_73 ,
void * V_100 , enum V_89 V_90 , int V_91 )
{
if ( V_14 -> V_84 >= 100 )
return F_67 ( V_100 , V_90 , V_91 , V_73 ) ;
else if ( V_14 -> V_84 >= 95 &&
V_91 > V_101 )
return F_66 ( V_100 , V_90 , V_91 ) ;
else
return F_63 ( V_100 , V_90 , V_91 ) ;
}
static void * F_69 ( struct V_13 * V_14 ,
struct V_102 * V_103 )
{
if ( ! V_103 -> V_104 )
return NULL ;
return V_103 -> V_105 + F_60 ( V_14 ) ;
}
void * F_70 ( struct V_13 * V_14 , struct V_102 * V_103 )
{
void * V_83 ;
F_71 ( & V_103 -> V_106 ) ;
V_83 = F_69 ( V_14 , V_103 ) ;
if ( ! V_83 )
F_72 ( & V_103 -> V_106 ) ;
return V_83 ;
}
void * F_73 ( struct V_71 * V_72 , struct V_102 * V_103 )
{
return F_70 ( V_72 -> V_14 , V_103 ) ;
}
static int F_74 ( struct V_13 * V_14 , int V_73 ,
struct V_102 * V_103 , enum V_89 V_90 ,
unsigned int V_107 , void * V_108 ,
unsigned int V_91 )
{
int V_109 ;
int V_110 ;
V_109 = V_108 ? V_111 : 0 ;
V_107 += F_68 ( V_14 , V_73 , V_103 -> V_105 , V_90 ,
V_107 + V_91 ) ;
V_110 = F_75 ( V_14 , V_103 -> V_104 , V_103 -> V_105 , V_107 ,
V_109 ) ;
if ( V_108 && ! V_110 )
V_110 = F_75 ( V_14 , V_103 -> V_104 , V_108 , V_91 , 0 ) ;
if ( ! V_110 && ( V_90 == V_112 || V_90 == V_113 ) )
F_76 ( V_103 -> V_104 ) ;
return V_110 ;
}
static int F_77 ( struct V_13 * V_14 , struct V_102 * V_103 ,
enum V_89 V_90 , unsigned int V_107 ,
void * V_108 , unsigned int V_91 )
{
return F_74 ( V_14 , 0 , V_103 , V_90 , V_107 , V_108 , V_91 ) ;
}
int F_78 ( struct V_13 * V_14 , struct V_102 * V_103 ,
enum V_89 V_90 , unsigned int V_107 ,
void * V_108 , unsigned int V_91 )
{
int V_110 ;
V_110 = F_77 ( V_14 , V_103 , V_90 , V_107 , V_108 , V_91 ) ;
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
int F_79 ( struct V_71 * V_72 , struct V_102 * V_103 ,
enum V_89 V_90 , unsigned int V_107 ,
void * V_108 , unsigned int V_91 )
{
int V_110 ;
V_110 = F_74 ( V_72 -> V_14 , V_72 -> V_5 -> V_73 ,
V_103 , V_90 , V_107 , V_108 , V_91 ) ;
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
int F_80 ( struct V_13 * V_14 )
{
struct V_102 * V_103 ;
V_103 = & V_14 -> V_114 ;
if ( ! F_70 ( V_14 , V_103 ) )
return - V_115 ;
return F_78 ( V_14 , V_103 , V_112 , 0 , NULL , 0 ) ;
}
int F_81 ( struct V_13 * V_14 )
{
struct V_102 * V_103 ;
V_103 = & V_14 -> V_114 ;
if ( ! F_70 ( V_14 , V_103 ) )
return - V_115 ;
return F_78 ( V_14 , V_103 , V_113 , 0 , NULL , 0 ) ;
}
int F_82 ( struct V_71 * V_72 )
{
struct V_102 * V_103 ;
struct V_116 * V_83 ;
int V_91 ;
const int V_117 = V_72 -> V_14 -> V_84 ;
enum V_89 V_90 ;
struct V_118 * V_119 ;
struct V_120 * V_121 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
F_46 () ;
V_119 = F_83 ( V_72 -> V_14 -> V_118 ) ;
V_91 = V_117 <= 87 ? sizeof( struct V_122 )
: V_117 == 88 ? sizeof( struct V_122 )
+ strlen ( V_119 -> V_123 ) + 1
: V_117 <= 94 ? sizeof( struct V_124 )
: sizeof( struct V_116 ) ;
V_90 = V_117 >= 89 ? V_125 : V_126 ;
memset ( V_83 -> V_123 , 0 , 2 * V_127 ) ;
if ( F_84 ( V_72 -> V_5 ) ) {
V_121 = F_83 ( V_72 -> V_5 -> V_128 -> V_120 ) ;
V_83 -> V_129 = F_64 ( V_121 -> V_129 ) ;
V_83 -> V_130 = F_64 ( V_121 -> V_130 ) ;
V_83 -> V_131 = F_64 ( V_121 -> V_131 ) ;
V_83 -> V_132 = F_64 ( V_121 -> V_132 ) ;
V_83 -> V_133 = F_64 ( V_121 -> V_133 ) ;
F_85 ( V_72 -> V_5 ) ;
} else {
V_83 -> V_129 = F_64 ( V_134 ) ;
V_83 -> V_130 = F_64 ( V_135 ) ;
V_83 -> V_131 = F_64 ( V_136 ) ;
V_83 -> V_132 = F_64 ( V_137 ) ;
V_83 -> V_133 = F_64 ( V_138 ) ;
}
if ( V_117 >= 88 )
strcpy ( V_83 -> V_123 , V_119 -> V_123 ) ;
if ( V_117 >= 89 )
strcpy ( V_83 -> V_139 , V_119 -> V_139 ) ;
F_49 () ;
return F_79 ( V_72 , V_103 , V_90 , V_91 , NULL , 0 ) ;
}
int F_86 ( struct V_13 * V_14 , enum V_89 V_90 )
{
struct V_102 * V_103 ;
struct V_140 * V_83 ;
struct V_118 * V_119 ;
int V_91 , V_141 ;
V_103 = & V_14 -> V_108 ;
V_83 = F_69 ( V_14 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
F_46 () ;
V_119 = F_83 ( V_14 -> V_118 ) ;
if ( V_119 -> V_142 && V_14 -> V_84 < 92 ) {
F_49 () ;
F_72 ( & V_103 -> V_106 ) ;
F_11 ( V_14 , L_11 ) ;
return - V_143 ;
}
V_91 = sizeof( * V_83 ) ;
if ( V_14 -> V_84 >= 87 )
V_91 += strlen ( V_119 -> V_144 ) + 1 ;
V_83 -> V_145 = F_64 ( V_119 -> V_146 ) ;
V_83 -> V_147 = F_64 ( V_119 -> V_147 ) ;
V_83 -> V_148 = F_64 ( V_119 -> V_148 ) ;
V_83 -> V_149 = F_64 ( V_119 -> V_149 ) ;
V_83 -> V_150 = F_64 ( V_119 -> V_150 ) ;
V_141 = 0 ;
if ( V_119 -> V_151 )
V_141 |= V_152 ;
if ( V_119 -> V_142 )
V_141 |= V_153 ;
V_83 -> V_154 = F_64 ( V_141 ) ;
if ( V_14 -> V_84 >= 87 )
strcpy ( V_83 -> V_144 , V_119 -> V_144 ) ;
F_49 () ;
return F_77 ( V_14 , V_103 , V_90 , V_91 , NULL , 0 ) ;
}
int F_87 ( struct V_13 * V_14 )
{
int V_110 ;
F_71 ( & V_14 -> V_108 . V_106 ) ;
V_110 = F_86 ( V_14 , V_155 ) ;
F_72 ( & V_14 -> V_108 . V_106 ) ;
return V_110 ;
}
static int F_88 ( struct V_71 * V_72 , T_3 V_156 )
{
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_102 * V_103 ;
struct V_157 * V_83 ;
int V_158 ;
if ( ! F_89 ( V_5 , V_159 ) )
return 0 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 ) {
F_85 ( V_5 ) ;
return - V_115 ;
}
F_9 ( & V_5 -> V_128 -> V_160 . V_161 ) ;
for ( V_158 = V_162 ; V_158 < V_163 ; V_158 ++ )
V_83 -> V_164 [ V_158 ] = F_90 ( V_5 -> V_128 -> V_160 . V_164 [ V_158 ] ) ;
F_14 ( & V_5 -> V_128 -> V_160 . V_161 ) ;
V_5 -> V_165 = F_91 ( V_5 ) ;
V_83 -> V_164 [ V_163 ] = F_90 ( V_5 -> V_165 ) ;
F_46 () ;
V_156 |= F_83 ( V_72 -> V_14 -> V_118 ) -> V_151 ? 1 : 0 ;
F_49 () ;
V_156 |= F_92 ( V_166 , & V_5 -> V_44 ) ? 2 : 0 ;
V_156 |= V_5 -> V_167 . V_11 == V_168 ? 4 : 0 ;
V_83 -> V_164 [ V_169 ] = F_90 ( V_156 ) ;
F_85 ( V_5 ) ;
return F_79 ( V_72 , V_103 , V_170 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_93 ( struct V_71 * V_72 )
{
return F_88 ( V_72 , 0 ) ;
}
int F_94 ( struct V_71 * V_72 )
{
return F_88 ( V_72 , 8 ) ;
}
void F_95 ( struct V_4 * V_5 , const char * V_171 )
{
if ( F_89 ( V_5 , V_159 ) ) {
T_3 * V_164 = V_5 -> V_128 -> V_160 . V_164 ;
F_25 ( V_5 , L_12 ,
V_171 ,
( unsigned long long ) V_164 [ V_162 ] ,
( unsigned long long ) V_164 [ V_172 ] ,
( unsigned long long ) V_164 [ V_173 ] ,
( unsigned long long ) V_164 [ V_174 ] ) ;
F_85 ( V_5 ) ;
} else {
F_25 ( V_5 , L_13 ,
V_171 ,
( unsigned long long ) V_5 -> V_175 ) ;
}
}
void F_96 ( struct V_71 * V_72 )
{
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_102 * V_103 ;
struct V_176 * V_83 ;
T_3 V_164 ;
F_97 ( V_5 , V_5 -> V_10 . V_11 == V_177 ) ;
V_164 = V_5 -> V_128 -> V_160 . V_164 [ V_172 ] ;
if ( V_164 && V_164 != V_178 )
V_164 = V_164 + V_179 ;
else
F_98 ( & V_164 , sizeof( T_3 ) ) ;
F_99 ( V_5 , V_172 , V_164 ) ;
F_95 ( V_5 , L_14 ) ;
F_100 ( V_5 ) ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( V_83 ) {
V_83 -> V_164 = F_90 ( V_164 ) ;
F_79 ( V_72 , V_103 , V_180 , sizeof( * V_83 ) , NULL , 0 ) ;
}
}
int F_101 ( struct V_71 * V_72 , int V_181 , enum V_182 V_44 )
{
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_102 * V_103 ;
struct V_183 * V_83 ;
T_4 V_184 , V_185 ;
int V_186 ;
unsigned int V_187 ;
if ( F_89 ( V_5 , V_159 ) ) {
F_97 ( V_5 , V_5 -> V_128 -> V_188 ) ;
V_184 = F_102 ( V_5 -> V_128 ) ;
F_46 () ;
V_185 = F_83 ( V_5 -> V_128 -> V_120 ) -> V_189 ;
F_49 () ;
V_186 = F_103 ( V_5 ) ;
V_187 = F_104 ( V_5 -> V_128 -> V_188 -> V_190 -> V_191 ) << 9 ;
V_187 = V_82 ( V_187 , V_192 ) ;
F_85 ( V_5 ) ;
} else {
V_184 = 0 ;
V_185 = 0 ;
V_186 = V_193 ;
V_187 = V_192 ;
}
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
if ( V_72 -> V_14 -> V_84 <= 94 )
V_187 = V_82 ( V_187 , V_101 ) ;
else if ( V_72 -> V_14 -> V_84 < 100 )
V_187 = V_82 ( V_187 , V_194 ) ;
V_83 -> V_184 = F_90 ( V_184 ) ;
V_83 -> V_185 = F_90 ( V_185 ) ;
V_83 -> V_195 = F_90 ( V_181 ? 0 : F_105 ( V_5 -> V_196 ) ) ;
V_83 -> V_187 = F_64 ( V_187 ) ;
V_83 -> V_197 = F_65 ( V_186 ) ;
V_83 -> V_182 = F_65 ( V_44 ) ;
return F_79 ( V_72 , V_103 , V_198 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_106 ( struct V_71 * V_72 )
{
struct V_102 * V_103 ;
struct V_199 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_10 = F_64 ( V_72 -> V_5 -> V_10 . V_158 ) ;
return F_79 ( V_72 , V_103 , V_200 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_107 ( struct V_71 * V_72 , union V_201 V_10 )
{
struct V_102 * V_103 ;
struct V_199 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_10 = F_64 ( V_10 . V_158 ) ;
return F_79 ( V_72 , V_103 , V_200 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_108 ( struct V_71 * V_72 , union V_201 V_202 , union V_201 V_203 )
{
struct V_102 * V_103 ;
struct V_204 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_202 = F_64 ( V_202 . V_158 ) ;
V_83 -> V_203 = F_64 ( V_203 . V_158 ) ;
return F_79 ( V_72 , V_103 , V_205 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_109 ( struct V_13 * V_14 , union V_201 V_202 , union V_201 V_203 )
{
enum V_89 V_90 ;
struct V_102 * V_103 ;
struct V_204 * V_83 ;
V_90 = V_14 -> V_84 < 100 ? V_205 : V_206 ;
V_103 = & V_14 -> V_108 ;
V_83 = F_70 ( V_14 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_202 = F_64 ( V_202 . V_158 ) ;
V_83 -> V_203 = F_64 ( V_203 . V_158 ) ;
return F_78 ( V_14 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
void F_110 ( struct V_71 * V_72 , enum V_207 V_208 )
{
struct V_102 * V_103 ;
struct V_209 * V_83 ;
V_103 = & V_72 -> V_14 -> V_114 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( V_83 ) {
V_83 -> V_208 = F_64 ( V_208 ) ;
F_79 ( V_72 , V_103 , V_210 , sizeof( * V_83 ) , NULL , 0 ) ;
}
}
void F_111 ( struct V_13 * V_14 , enum V_207 V_208 )
{
struct V_102 * V_103 ;
struct V_209 * V_83 ;
enum V_89 V_90 = V_14 -> V_84 < 100 ? V_210 : V_211 ;
V_103 = & V_14 -> V_114 ;
V_83 = F_70 ( V_14 , V_103 ) ;
if ( V_83 ) {
V_83 -> V_208 = F_64 ( V_208 ) ;
F_78 ( V_14 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
}
static void F_112 ( struct V_212 * V_83 , enum V_213 V_214 )
{
F_113 ( V_214 & ~ 0xf ) ;
V_83 -> V_215 = ( V_83 -> V_215 & ~ 0xf ) | V_214 ;
}
static void F_114 ( struct V_212 * V_83 , int V_216 )
{
V_83 -> V_215 = ( V_83 -> V_215 & ~ 0x80 ) | ( V_216 ? 0x80 : 0 ) ;
}
static void F_115 ( struct V_212 * V_83 , int V_217 )
{
F_113 ( V_217 & ~ 0x7 ) ;
V_83 -> V_215 = ( V_83 -> V_215 & ( ~ 0x7 << 4 ) ) | ( V_217 << 4 ) ;
}
static int F_116 ( struct V_4 * V_5 ,
struct V_212 * V_83 ,
unsigned int V_91 ,
struct V_218 * V_219 )
{
struct V_220 V_221 ;
unsigned long V_222 ;
unsigned long V_223 ;
unsigned long V_224 ;
unsigned V_225 ;
unsigned V_226 ;
int V_227 , V_228 ;
F_46 () ;
V_228 = F_83 ( F_22 ( V_5 ) -> V_14 -> V_118 ) -> V_228 ;
F_49 () ;
if ( ! V_228 || F_22 ( V_5 ) -> V_14 -> V_84 < 90 )
return 0 ;
if ( V_219 -> V_229 >= V_219 -> V_230 )
return 0 ;
F_117 ( & V_221 , V_83 -> V_214 , V_91 , 0 ) ;
memset ( V_83 -> V_214 , 0 , V_91 ) ;
V_222 = 0 ;
V_226 = 2 ;
do {
V_223 = ( V_226 == 0 ) ? F_118 ( V_5 , V_219 -> V_229 )
: F_119 ( V_5 , V_219 -> V_229 ) ;
if ( V_223 == - 1UL )
V_223 = V_219 -> V_230 ;
V_224 = V_223 - V_219 -> V_229 ;
if ( V_226 == 2 ) {
if ( V_224 == 0 ) {
F_114 ( V_83 , 1 ) ;
V_226 = ! V_226 ;
continue;
}
F_114 ( V_83 , 0 ) ;
}
if ( V_224 == 0 ) {
F_11 ( V_5 , L_15
L_16 , V_226 , V_219 -> V_229 ) ;
return - 1 ;
}
V_227 = F_120 ( & V_221 , V_224 ) ;
if ( V_227 == - V_231 )
break;
if ( V_227 <= 0 ) {
F_11 ( V_5 , L_17 , V_227 ) ;
return 0 ;
}
V_226 = ! V_226 ;
V_222 += V_224 ;
V_219 -> V_229 = V_223 ;
} while ( V_219 -> V_229 < V_219 -> V_230 );
V_225 = V_221 . V_232 . V_233 - V_83 -> V_214 + ! ! V_221 . V_232 . V_234 ;
if ( V_222 < ( V_225 << 3 ) ) {
V_219 -> V_229 -= V_222 ;
F_121 ( V_219 ) ;
V_219 -> V_229 = V_219 -> V_235 * V_236 ;
return 0 ;
}
F_121 ( V_219 ) ;
F_115 ( V_83 , ( 8 - V_221 . V_232 . V_234 ) & 0x7 ) ;
return V_225 ;
}
static int
F_122 ( struct V_4 * V_5 , struct V_218 * V_219 )
{
struct V_102 * V_103 = & F_22 ( V_5 ) -> V_14 -> V_108 ;
unsigned int V_107 = F_60 ( F_22 ( V_5 ) -> V_14 ) ;
struct V_212 * V_83 = V_103 -> V_105 + V_107 ;
int V_225 , V_110 ;
V_225 = F_116 ( V_5 , V_83 ,
V_237 - V_107 - sizeof( * V_83 ) , V_219 ) ;
if ( V_225 < 0 )
return - V_115 ;
if ( V_225 ) {
F_112 ( V_83 , V_238 ) ;
V_110 = F_74 ( F_22 ( V_5 ) -> V_14 , V_5 -> V_73 , V_103 ,
V_239 , sizeof( * V_83 ) + V_225 ,
NULL , 0 ) ;
V_219 -> V_240 [ 0 ] ++ ;
V_219 -> V_241 [ 0 ] += V_107 + sizeof( * V_83 ) + V_225 ;
if ( V_219 -> V_229 >= V_219 -> V_230 )
V_225 = 0 ;
} else {
unsigned int V_242 ;
unsigned long V_243 ;
unsigned long * V_83 = V_103 -> V_105 + V_107 ;
V_242 = V_237 - V_107 ;
V_243 = F_123 ( V_244 , V_242 / sizeof( * V_83 ) ,
V_219 -> V_245 - V_219 -> V_235 ) ;
V_225 = V_243 * sizeof( * V_83 ) ;
if ( V_225 )
F_124 ( V_5 , V_219 -> V_235 , V_243 , V_83 ) ;
V_110 = F_74 ( F_22 ( V_5 ) -> V_14 , V_5 -> V_73 , V_103 , V_246 , V_225 , NULL , 0 ) ;
V_219 -> V_235 += V_243 ;
V_219 -> V_229 = V_219 -> V_235 * V_236 ;
V_219 -> V_240 [ 1 ] ++ ;
V_219 -> V_241 [ 1 ] += V_107 + V_225 ;
if ( V_219 -> V_229 > V_219 -> V_230 )
V_219 -> V_229 = V_219 -> V_230 ;
}
if ( ! V_110 ) {
if ( V_225 == 0 ) {
F_125 ( V_5 , L_18 , V_219 ) ;
return 0 ;
} else
return 1 ;
}
return - V_115 ;
}
static int F_126 ( struct V_4 * V_5 )
{
struct V_218 V_219 ;
int V_110 ;
if ( ! F_127 ( V_5 -> V_247 ) )
return false ;
if ( F_84 ( V_5 ) ) {
if ( F_128 ( V_5 -> V_128 , V_248 ) ) {
F_25 ( V_5 , L_19 ) ;
F_129 ( V_5 ) ;
if ( F_130 ( V_5 ) ) {
F_11 ( V_5 , L_20 ) ;
} else {
F_131 ( V_5 , V_248 ) ;
F_100 ( V_5 ) ;
}
}
F_85 ( V_5 ) ;
}
V_219 = (struct V_218 ) {
. V_230 = F_132 ( V_5 ) ,
. V_245 = F_133 ( V_5 ) ,
} ;
do {
V_110 = F_122 ( V_5 , & V_219 ) ;
} while ( V_110 > 0 );
return V_110 == 0 ;
}
int F_134 ( struct V_4 * V_5 )
{
struct V_102 * V_103 = & F_22 ( V_5 ) -> V_14 -> V_108 ;
int V_110 = - 1 ;
F_71 ( & V_103 -> V_106 ) ;
if ( V_103 -> V_104 )
V_110 = ! F_126 ( V_5 ) ;
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
void F_135 ( struct V_13 * V_14 , T_5 V_15 , T_5 V_16 )
{
struct V_102 * V_103 ;
struct V_249 * V_83 ;
if ( V_14 -> V_250 < V_251 )
return;
V_103 = & V_14 -> V_114 ;
V_83 = F_70 ( V_14 , V_103 ) ;
if ( ! V_83 )
return;
V_83 -> V_252 = V_15 ;
V_83 -> V_16 = F_64 ( V_16 ) ;
F_78 ( V_14 , V_103 , V_253 , sizeof( * V_83 ) , NULL , 0 ) ;
}
static int F_136 ( struct V_71 * V_72 , enum V_89 V_90 ,
T_3 V_254 , T_5 V_255 , T_3 V_256 )
{
struct V_102 * V_103 ;
struct V_257 * V_83 ;
if ( V_72 -> V_5 -> V_10 . V_32 < V_258 )
return - V_115 ;
V_103 = & V_72 -> V_14 -> V_114 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_254 = V_254 ;
V_83 -> V_256 = V_256 ;
V_83 -> V_255 = V_255 ;
V_83 -> V_259 = F_64 ( F_137 ( & V_72 -> V_5 -> V_260 ) ) ;
return F_79 ( V_72 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
void F_138 ( struct V_71 * V_72 , enum V_89 V_90 ,
struct V_261 * V_262 , int V_242 )
{
if ( V_72 -> V_14 -> V_263 )
V_242 -= F_139 ( V_72 -> V_14 -> V_263 ) ;
F_136 ( V_72 , V_90 , V_262 -> V_254 , F_64 ( V_242 ) ,
V_262 -> V_256 ) ;
}
void F_140 ( struct V_71 * V_72 , enum V_89 V_90 ,
struct V_264 * V_265 )
{
F_136 ( V_72 , V_90 , V_265 -> V_254 , V_265 -> V_255 , V_265 -> V_256 ) ;
}
int F_141 ( struct V_71 * V_72 , enum V_89 V_90 ,
struct V_266 * V_267 )
{
return F_136 ( V_72 , V_90 ,
F_90 ( V_267 -> V_158 . V_254 ) ,
F_64 ( V_267 -> V_158 . V_91 ) ,
V_267 -> V_256 ) ;
}
int F_142 ( struct V_71 * V_72 , enum V_89 V_90 ,
T_4 V_254 , int V_255 , T_3 V_256 )
{
return F_136 ( V_72 , V_90 ,
F_90 ( V_254 ) ,
F_64 ( V_255 ) ,
F_90 ( V_256 ) ) ;
}
int F_143 ( struct V_71 * V_72 , int V_90 ,
T_4 V_254 , int V_91 , T_3 V_256 )
{
struct V_102 * V_103 ;
struct V_264 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_254 = F_90 ( V_254 ) ;
V_83 -> V_256 = V_256 ;
V_83 -> V_255 = F_64 ( V_91 ) ;
return F_79 ( V_72 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_144 ( struct V_71 * V_72 , T_4 V_254 , int V_91 ,
void * V_268 , int V_269 , enum V_89 V_90 )
{
struct V_102 * V_103 ;
struct V_264 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_254 = F_90 ( V_254 ) ;
V_83 -> V_256 = V_270 ;
V_83 -> V_255 = F_64 ( V_91 ) ;
return F_79 ( V_72 , V_103 , V_90 , sizeof( * V_83 ) , V_268 , V_269 ) ;
}
int F_145 ( struct V_71 * V_72 , T_4 V_254 , int V_91 )
{
struct V_102 * V_103 ;
struct V_264 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_254 = F_90 ( V_254 ) ;
V_83 -> V_256 = V_270 ;
V_83 -> V_255 = F_64 ( V_91 ) ;
return F_79 ( V_72 , V_103 , V_271 , sizeof( * V_83 ) , NULL , 0 ) ;
}
static int F_146 ( struct V_13 * V_14 , struct V_104 * V_103 )
{
int V_272 ;
V_272 = V_14 -> V_114 . V_104 == V_103
|| ! V_14 -> V_273 . V_55
|| F_147 ( & V_14 -> V_273 ) != V_54
|| V_14 -> V_250 < V_251 ;
if ( V_272 )
return true ;
V_272 = ! -- V_14 -> V_274 ;
if ( ! V_272 ) {
F_11 ( V_14 , L_21 ,
V_46 -> V_47 , V_46 -> V_64 , V_14 -> V_274 ) ;
F_148 ( V_14 ) ;
}
return V_272 ; ;
}
static void F_149 ( struct V_13 * V_14 )
{
struct V_103 * V_275 = V_14 -> V_108 . V_104 -> V_275 ;
if ( V_275 -> V_276 > V_275 -> V_277 * 4 / 5 )
F_150 ( V_278 , & V_14 -> V_44 ) ;
}
static int F_151 ( struct V_71 * V_72 , struct V_279 * V_279 ,
int V_280 , V_244 V_91 , unsigned V_109 )
{
struct V_104 * V_104 ;
void * V_281 ;
int V_110 ;
V_104 = V_72 -> V_14 -> V_108 . V_104 ;
V_281 = F_152 ( V_279 ) + V_280 ;
V_110 = F_75 ( V_72 -> V_14 , V_104 , V_281 , V_91 , V_109 ) ;
F_153 ( V_279 ) ;
if ( ! V_110 )
V_72 -> V_5 -> V_282 += V_91 >> 9 ;
return V_110 ;
}
static int F_154 ( struct V_71 * V_72 , struct V_279 * V_279 ,
int V_280 , V_244 V_91 , unsigned V_109 )
{
struct V_104 * V_104 = V_72 -> V_14 -> V_108 . V_104 ;
T_6 V_283 = F_155 () ;
int V_225 = V_91 ;
int V_110 = - V_115 ;
if ( V_284 || ( F_156 ( V_279 ) < 1 ) || F_157 ( V_279 ) )
return F_151 ( V_72 , V_279 , V_280 , V_91 , V_109 ) ;
V_109 |= V_285 ;
F_149 ( V_72 -> V_14 ) ;
F_158 ( V_286 ) ;
do {
int V_287 ;
V_287 = V_104 -> V_288 -> V_289 ( V_104 , V_279 , V_280 , V_225 , V_109 ) ;
if ( V_287 <= 0 ) {
if ( V_287 == - V_290 ) {
if ( F_146 ( V_72 -> V_14 , V_104 ) )
break;
continue;
}
F_159 ( V_72 -> V_5 , L_22 ,
V_291 , ( int ) V_91 , V_225 , V_287 ) ;
if ( V_287 < 0 )
V_110 = V_287 ;
break;
}
V_225 -= V_287 ;
V_280 += V_287 ;
} while ( V_225 > 0 );
F_158 ( V_283 ) ;
F_160 ( V_278 , & V_72 -> V_14 -> V_44 ) ;
if ( V_225 == 0 ) {
V_110 = 0 ;
V_72 -> V_5 -> V_282 += V_91 >> 9 ;
}
return V_110 ;
}
static int F_161 ( struct V_71 * V_72 , struct V_1 * V_1 )
{
struct V_292 V_293 ;
struct V_294 V_295 ;
F_162 (bvec, bio, iter) {
int V_110 ;
V_110 = F_151 ( V_72 , V_293 . V_296 ,
V_293 . V_297 , V_293 . V_298 ,
F_163 ( V_293 , V_295 )
? 0 : V_111 ) ;
if ( V_110 )
return V_110 ;
}
return 0 ;
}
static int F_164 ( struct V_71 * V_72 , struct V_1 * V_1 )
{
struct V_292 V_293 ;
struct V_294 V_295 ;
F_162 (bvec, bio, iter) {
int V_110 ;
V_110 = F_154 ( V_72 , V_293 . V_296 ,
V_293 . V_297 , V_293 . V_298 ,
F_163 ( V_293 , V_295 ) ? 0 : V_111 ) ;
if ( V_110 )
return V_110 ;
}
return 0 ;
}
static int F_165 ( struct V_71 * V_72 ,
struct V_266 * V_267 )
{
struct V_279 * V_279 = V_267 -> V_299 ;
unsigned V_225 = V_267 -> V_158 . V_91 ;
int V_110 ;
F_166 (page) {
unsigned V_300 = F_123 ( unsigned , V_225 , V_301 ) ;
V_110 = F_154 ( V_72 , V_279 , 0 , V_300 ,
F_167 ( V_279 ) ? V_111 : 0 ) ;
if ( V_110 )
return V_110 ;
V_225 -= V_300 ;
}
return 0 ;
}
static T_5 F_168 ( struct V_13 * V_14 , unsigned long V_302 )
{
if ( V_14 -> V_84 >= 95 )
return ( V_302 & V_303 ? V_304 : 0 ) |
( V_302 & V_305 ? V_306 : 0 ) |
( V_302 & V_307 ? V_308 : 0 ) |
( V_302 & V_309 ? V_310 : 0 ) ;
else
return V_302 & V_303 ? V_304 : 0 ;
}
int F_169 ( struct V_71 * V_72 , struct V_17 * V_19 )
{
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_102 * V_103 ;
struct V_261 * V_83 ;
unsigned int V_311 = 0 ;
int V_312 ;
int V_110 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
V_312 = V_72 -> V_14 -> V_313 ?
F_139 ( V_72 -> V_14 -> V_313 ) : 0 ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_254 = F_90 ( V_19 -> V_158 . V_254 ) ;
V_83 -> V_256 = ( unsigned long ) V_19 ;
V_83 -> V_259 = F_64 ( F_137 ( & V_5 -> V_260 ) ) ;
V_311 = F_168 ( V_72 -> V_14 , V_19 -> V_314 -> V_302 ) ;
if ( V_5 -> V_10 . V_32 >= V_315 &&
V_5 -> V_10 . V_32 <= V_316 )
V_311 |= V_317 ;
if ( V_72 -> V_14 -> V_84 >= 100 ) {
if ( V_19 -> V_25 & V_318 )
V_311 |= V_319 ;
if ( V_19 -> V_25 & V_320
|| ( V_311 & V_317 ) )
V_311 |= V_321 ;
}
V_83 -> V_311 = F_64 ( V_311 ) ;
if ( V_311 & V_310 ) {
struct V_322 * V_323 = (struct V_322 * ) V_83 ;
V_323 -> V_91 = F_64 ( V_19 -> V_158 . V_91 ) ;
V_110 = F_74 ( V_72 -> V_14 , V_5 -> V_73 , V_103 , V_324 , sizeof( * V_323 ) , NULL , 0 ) ;
goto V_325;
}
if ( V_312 )
F_170 ( V_72 -> V_14 -> V_313 , V_19 -> V_314 , V_83 + 1 ) ;
V_110 = F_74 ( V_72 -> V_14 , V_5 -> V_73 , V_103 , V_326 , sizeof( * V_83 ) + V_312 , NULL , V_19 -> V_158 . V_91 ) ;
if ( ! V_110 ) {
if ( ! ( V_19 -> V_25 & ( V_318 | V_320 ) ) || V_312 )
V_110 = F_161 ( V_72 , V_19 -> V_314 ) ;
else
V_110 = F_164 ( V_72 , V_19 -> V_314 ) ;
if ( V_312 > 0 && V_312 <= 64 ) {
unsigned char V_268 [ 64 ] ;
F_170 ( V_72 -> V_14 -> V_313 , V_19 -> V_314 , V_268 ) ;
if ( memcmp ( V_83 + 1 , V_268 , V_312 ) ) {
F_159 ( V_5 ,
L_23 ,
( unsigned long long ) V_19 -> V_158 . V_254 , V_19 -> V_158 . V_91 ) ;
}
}
}
V_325:
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
int F_171 ( struct V_71 * V_72 , enum V_89 V_90 ,
struct V_266 * V_267 )
{
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_102 * V_103 ;
struct V_261 * V_83 ;
int V_110 ;
int V_312 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
V_312 = V_72 -> V_14 -> V_313 ?
F_139 ( V_72 -> V_14 -> V_313 ) : 0 ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_254 = F_90 ( V_267 -> V_158 . V_254 ) ;
V_83 -> V_256 = V_267 -> V_256 ;
V_83 -> V_259 = 0 ;
V_83 -> V_311 = 0 ;
if ( V_312 )
F_172 ( V_72 -> V_14 -> V_313 , V_267 , V_83 + 1 ) ;
V_110 = F_74 ( V_72 -> V_14 , V_5 -> V_73 , V_103 , V_90 , sizeof( * V_83 ) + V_312 , NULL , V_267 -> V_158 . V_91 ) ;
if ( ! V_110 )
V_110 = F_165 ( V_72 , V_267 ) ;
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
int F_173 ( struct V_71 * V_72 , struct V_17 * V_19 )
{
struct V_102 * V_103 ;
struct V_327 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_254 = F_90 ( V_19 -> V_158 . V_254 ) ;
V_83 -> V_255 = F_64 ( V_19 -> V_158 . V_91 ) ;
return F_79 ( V_72 , V_103 , V_328 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_174 ( struct V_13 * V_14 , struct V_104 * V_103 ,
void * V_329 , V_244 V_91 , unsigned V_109 )
{
struct V_330 V_331 ;
struct V_332 V_333 ;
int V_334 , V_287 = 0 ;
if ( ! V_103 )
return - V_335 ;
V_331 . V_336 = V_329 ;
V_331 . V_337 = V_91 ;
V_333 . V_338 = NULL ;
V_333 . V_339 = 0 ;
V_333 . V_340 = NULL ;
V_333 . V_341 = 0 ;
V_333 . V_109 = V_109 | V_285 ;
if ( V_103 == V_14 -> V_108 . V_104 ) {
F_46 () ;
V_14 -> V_274 = F_83 ( V_14 -> V_118 ) -> V_274 ;
F_49 () ;
F_149 ( V_14 ) ;
}
do {
V_334 = F_175 ( V_103 , & V_333 , & V_331 , 1 , V_91 ) ;
if ( V_334 == - V_290 ) {
if ( F_146 ( V_14 , V_103 ) )
break;
else
continue;
}
if ( V_334 == - V_342 ) {
F_38 ( V_46 ) ;
V_334 = 0 ;
}
if ( V_334 < 0 )
break;
V_287 += V_334 ;
V_331 . V_336 += V_334 ;
V_331 . V_337 -= V_334 ;
} while ( V_287 < V_91 );
if ( V_103 == V_14 -> V_108 . V_104 )
F_160 ( V_278 , & V_14 -> V_44 ) ;
if ( V_334 <= 0 ) {
if ( V_334 != - V_290 ) {
F_11 ( V_14 , L_24 ,
V_103 == V_14 -> V_114 . V_104 ? L_25 : L_26 ,
V_334 ) ;
F_15 ( V_14 , F_16 ( V_32 , V_343 ) , V_34 ) ;
} else
F_15 ( V_14 , F_16 ( V_32 , V_344 ) , V_34 ) ;
}
return V_287 ;
}
int F_75 ( struct V_13 * V_14 , struct V_104 * V_103 , void * V_100 ,
V_244 V_91 , unsigned V_109 )
{
int V_110 ;
V_110 = F_174 ( V_14 , V_103 , V_100 , V_91 , V_109 ) ;
if ( V_110 < 0 )
return V_110 ;
if ( V_110 != V_91 )
return - V_115 ;
return 0 ;
}
static int F_176 ( struct V_345 * V_346 , T_7 V_347 )
{
struct V_4 * V_5 = V_346 -> V_190 -> V_348 ;
unsigned long V_44 ;
int V_334 = 0 ;
F_71 ( & V_349 ) ;
F_24 ( & V_5 -> V_22 -> V_23 , V_44 ) ;
if ( V_5 -> V_10 . V_350 != V_351 ) {
if ( V_347 & V_352 )
V_334 = - V_353 ;
else if ( ! V_354 )
V_334 = - V_355 ;
}
if ( ! V_334 )
V_5 -> V_356 ++ ;
F_26 ( & V_5 -> V_22 -> V_23 , V_44 ) ;
F_72 ( & V_349 ) ;
return V_334 ;
}
static void F_177 ( struct V_357 * V_358 , T_7 V_347 )
{
struct V_4 * V_5 = V_358 -> V_348 ;
F_71 ( & V_349 ) ;
V_5 -> V_356 -- ;
F_72 ( & V_349 ) ;
}
static void F_178 ( struct V_4 * V_5 )
{
V_5 -> V_10 = (union V_359 ) {
{ . V_350 = V_360 ,
. V_361 = V_362 ,
. V_32 = V_363 ,
. V_11 = V_364 ,
. V_365 = V_366 ,
} } ;
}
void F_179 ( struct V_4 * V_5 )
{
F_178 ( V_5 ) ;
F_180 ( & V_5 -> V_367 , 0 ) ;
F_180 ( & V_5 -> V_368 , 0 ) ;
F_180 ( & V_5 -> V_369 , 0 ) ;
F_180 ( & V_5 -> V_370 , 0 ) ;
F_180 ( & V_5 -> V_371 , 0 ) ;
F_180 ( & V_5 -> V_9 , 0 ) ;
F_180 ( & V_5 -> V_372 , 0 ) ;
F_180 ( & V_5 -> V_373 , 0 ) ;
F_180 ( & V_5 -> V_374 , 0 ) ;
F_180 ( & V_5 -> V_375 , 0 ) ;
F_180 ( & V_5 -> V_376 . V_377 , 0 ) ;
F_181 ( & V_5 -> V_378 ) ;
V_5 -> V_379 = & V_5 -> V_378 ;
F_33 ( & V_5 -> V_380 ) ;
F_33 ( & V_5 -> V_381 ) ;
F_182 ( & V_5 -> V_382 ) ;
F_182 ( & V_5 -> V_383 ) ;
F_182 ( & V_5 -> V_384 ) ;
F_182 ( & V_5 -> V_385 ) ;
F_182 ( & V_5 -> V_386 ) ;
F_182 ( & V_5 -> V_387 ) ;
F_182 ( & V_5 -> V_388 . V_389 ) ;
F_182 ( & V_5 -> V_390 . V_389 ) ;
F_182 ( & V_5 -> V_391 . V_392 . V_389 ) ;
F_182 ( & V_5 -> V_393 [ 0 ] ) ;
F_182 ( & V_5 -> V_393 [ 1 ] ) ;
F_182 ( & V_5 -> V_394 [ 0 ] ) ;
F_182 ( & V_5 -> V_394 [ 1 ] ) ;
V_5 -> V_388 . V_395 = V_396 ;
V_5 -> V_390 . V_395 = V_397 ;
V_5 -> V_391 . V_392 . V_395 = V_398 ;
F_183 ( & V_5 -> V_399 ) ;
F_183 ( & V_5 -> V_400 ) ;
F_183 ( & V_5 -> V_401 ) ;
F_183 ( & V_5 -> V_402 ) ;
V_5 -> V_399 . V_50 = V_403 ;
V_5 -> V_399 . V_108 = ( unsigned long ) V_5 ;
V_5 -> V_400 . V_50 = V_404 ;
V_5 -> V_400 . V_108 = ( unsigned long ) V_5 ;
V_5 -> V_401 . V_50 = V_405 ;
V_5 -> V_401 . V_108 = ( unsigned long ) V_5 ;
V_5 -> V_402 . V_50 = V_406 ;
V_5 -> V_402 . V_108 = ( unsigned long ) V_5 ;
F_184 ( & V_5 -> V_12 ) ;
F_184 ( & V_5 -> V_407 ) ;
F_184 ( & V_5 -> V_408 ) ;
F_184 ( & V_5 -> V_409 ) ;
F_184 ( & V_5 -> V_410 ) ;
V_5 -> V_411 = V_412 ;
V_5 -> V_413 = V_414 ;
V_5 -> V_415 = V_414 ;
}
void F_185 ( struct V_4 * V_5 )
{
int V_158 ;
if ( F_22 ( V_5 ) -> V_14 -> V_416 . V_52 != V_56 )
F_11 ( V_5 , L_27 ,
F_22 ( V_5 ) -> V_14 -> V_416 . V_52 ) ;
V_5 -> V_417 =
V_5 -> V_418 =
V_5 -> V_419 =
V_5 -> V_420 =
V_5 -> V_282 =
V_5 -> V_421 =
V_5 -> V_422 =
V_5 -> V_423 =
V_5 -> V_424 =
V_5 -> V_425 = 0 ;
V_5 -> V_426 = 0 ;
V_5 -> V_427 = 0 ;
for ( V_158 = 0 ; V_158 < V_428 ; V_158 ++ ) {
V_5 -> V_429 [ V_158 ] = 0 ;
V_5 -> V_430 [ V_158 ] = 0 ;
}
F_97 ( V_5 , F_22 ( V_5 ) -> V_14 -> V_118 == NULL ) ;
F_186 ( V_5 , 0 ) ;
if ( V_5 -> V_247 ) {
F_187 ( V_5 , 0 , 1 ) ;
F_188 ( V_5 ) ;
}
F_189 ( V_5 -> V_128 ) ;
V_5 -> V_128 = NULL ;
F_160 ( V_431 , & V_5 -> V_44 ) ;
F_97 ( V_5 , F_190 ( & V_5 -> V_382 ) ) ;
F_97 ( V_5 , F_190 ( & V_5 -> V_383 ) ) ;
F_97 ( V_5 , F_190 ( & V_5 -> V_384 ) ) ;
F_97 ( V_5 , F_190 ( & V_5 -> V_385 ) ) ;
F_97 ( V_5 , F_190 ( & V_5 -> V_386 ) ) ;
F_97 ( V_5 , F_190 ( & V_5 -> V_387 ) ) ;
F_97 ( V_5 , F_190 ( & F_22 ( V_5 ) -> V_14 -> V_432 . V_433 ) ) ;
F_97 ( V_5 , F_190 ( & V_5 -> V_388 . V_389 ) ) ;
F_97 ( V_5 , F_190 ( & V_5 -> V_390 . V_389 ) ) ;
F_178 ( V_5 ) ;
}
static void F_191 ( void )
{
struct V_279 * V_279 ;
while ( V_434 ) {
V_279 = V_434 ;
V_434 = (struct V_279 * ) F_192 ( V_279 ) ;
F_193 ( V_279 ) ;
V_435 -- ;
}
if ( V_3 )
F_194 ( V_3 ) ;
if ( V_436 )
F_195 ( V_436 ) ;
if ( V_437 )
F_195 ( V_437 ) ;
if ( V_438 )
F_195 ( V_438 ) ;
if ( V_439 )
F_196 ( V_439 ) ;
if ( V_440 )
F_196 ( V_440 ) ;
if ( V_441 )
F_196 ( V_441 ) ;
if ( V_442 )
F_196 ( V_442 ) ;
V_3 = NULL ;
V_436 = NULL ;
V_437 = NULL ;
V_438 = NULL ;
V_439 = NULL ;
V_440 = NULL ;
V_441 = NULL ;
V_442 = NULL ;
return;
}
static int F_197 ( void )
{
struct V_279 * V_279 ;
const int V_443 = ( V_192 / V_301 ) * V_444 ;
int V_158 ;
V_438 = NULL ;
V_439 = NULL ;
V_440 = NULL ;
V_441 = NULL ;
V_442 = NULL ;
V_434 = NULL ;
V_436 = NULL ;
V_3 = NULL ;
V_440 = F_198 (
L_28 , sizeof( struct V_17 ) , 0 , 0 , NULL ) ;
if ( V_440 == NULL )
goto V_445;
V_439 = F_198 (
L_29 , sizeof( struct V_266 ) , 0 , 0 , NULL ) ;
if ( V_439 == NULL )
goto V_445;
V_441 = F_198 (
L_30 , sizeof( struct V_446 ) , 0 , 0 , NULL ) ;
if ( V_441 == NULL )
goto V_445;
V_442 = F_198 (
L_31 , sizeof( struct V_447 ) , 0 , 0 , NULL ) ;
if ( V_442 == NULL )
goto V_445;
V_3 = F_199 ( V_448 , 0 ) ;
if ( V_3 == NULL )
goto V_445;
V_436 = F_200 ( V_448 , 0 ) ;
if ( V_436 == NULL )
goto V_445;
V_438 = F_201 ( V_443 ,
V_449 , V_450 , V_440 ) ;
if ( V_438 == NULL )
goto V_445;
V_437 = F_201 ( V_443 ,
V_449 , V_450 , V_439 ) ;
if ( V_437 == NULL )
goto V_445;
F_33 ( & V_451 ) ;
for ( V_158 = 0 ; V_158 < V_443 ; V_158 ++ ) {
V_279 = F_202 ( V_452 ) ;
if ( ! V_279 )
goto V_445;
F_203 ( V_279 , ( unsigned long ) V_434 ) ;
V_434 = V_279 ;
}
V_435 = V_443 ;
return 0 ;
V_445:
F_191 () ;
return - V_453 ;
}
static void F_204 ( struct V_4 * V_5 )
{
int V_454 ;
V_454 = F_205 ( V_5 , & V_5 -> V_382 ) ;
if ( V_454 )
F_11 ( V_5 , L_32 , V_454 ) ;
V_454 = F_205 ( V_5 , & V_5 -> V_383 ) ;
if ( V_454 )
F_11 ( V_5 , L_33 , V_454 ) ;
V_454 = F_205 ( V_5 , & V_5 -> V_385 ) ;
if ( V_454 )
F_11 ( V_5 , L_34 , V_454 ) ;
V_454 = F_205 ( V_5 , & V_5 -> V_384 ) ;
if ( V_454 )
F_11 ( V_5 , L_35 , V_454 ) ;
V_454 = F_205 ( V_5 , & V_5 -> V_386 ) ;
if ( V_454 )
F_11 ( V_5 , L_36 , V_454 ) ;
}
void F_206 ( struct V_58 * V_58 )
{
struct V_4 * V_5 = F_207 ( V_58 , struct V_4 , V_58 ) ;
struct V_43 * V_22 = V_5 -> V_22 ;
struct V_71 * V_72 , * V_455 ;
F_208 ( & V_5 -> V_402 ) ;
F_97 ( V_5 , V_5 -> V_356 == 0 ) ;
if ( V_5 -> V_196 )
F_209 ( V_5 -> V_196 ) ;
F_189 ( V_5 -> V_128 ) ;
V_5 -> V_128 = NULL ;
F_204 ( V_5 ) ;
F_210 ( V_5 -> V_456 ) ;
F_210 ( V_5 -> V_457 ) ;
F_55 ( V_5 -> V_458 ) ;
if ( V_5 -> V_247 )
F_188 ( V_5 ) ;
F_193 ( V_5 -> V_376 . V_279 ) ;
F_211 ( V_5 -> V_459 ) ;
F_212 ( V_5 -> V_460 ) ;
F_55 ( V_5 -> V_461 ) ;
F_213 (peer_device, tmp_peer_device, device) {
F_29 ( & V_72 -> V_14 -> V_58 , V_59 ) ;
F_55 ( V_72 ) ;
}
memset ( V_5 , 0xfd , sizeof( * V_5 ) ) ;
F_55 ( V_5 ) ;
F_29 ( & V_22 -> V_58 , V_60 ) ;
}
static void F_214 ( struct V_462 * V_463 )
{
struct V_464 * V_465 = F_207 ( V_463 , struct V_464 , V_466 ) ;
F_215 ( V_467 ) ;
struct V_17 * V_19 , * V_223 ;
F_9 ( & V_465 -> V_468 ) ;
F_216 ( & V_465 -> V_467 , & V_467 ) ;
F_14 ( & V_465 -> V_468 ) ;
F_18 (req, tmp, &writes, tl_requests) {
struct V_4 * V_5 = V_19 -> V_5 ;
struct V_1 * V_1 = V_19 -> V_314 ;
unsigned long V_469 = V_19 -> V_469 ;
bool V_470 ;
V_470 =
F_127 ( F_217 ( & V_19 -> V_471 ) == 0 ) &&
F_127 ( V_19 -> V_25 & V_472 ) &&
F_127 ( ( V_19 -> V_25 & V_38 ) == 0 ||
( V_19 -> V_25 & V_473 ) != 0 ) ;
if ( ! V_470 )
F_11 ( V_5 , L_37 ,
V_19 , F_217 ( & V_19 -> V_471 ) ,
V_19 -> V_25 ) ;
F_29 ( & V_19 -> V_58 , V_474 ) ;
F_218 ( V_5 ) ;
F_219 ( V_5 , V_1 , V_469 ) ;
}
}
void F_220 ( struct V_17 * V_19 )
{
unsigned long V_44 ;
F_24 ( & V_465 . V_468 , V_44 ) ;
F_221 ( & V_19 -> V_475 , & V_465 . V_467 ) ;
F_26 ( & V_465 . V_468 , V_44 ) ;
F_222 ( V_19 -> V_5 ) ;
F_223 ( V_465 . V_476 , & V_465 . V_466 ) ;
}
void V_60 ( struct V_58 * V_58 )
{
struct V_43 * V_22 =
F_207 ( V_58 , struct V_43 , V_58 ) ;
F_224 ( & V_22 -> V_477 ) ;
F_225 ( V_22 -> V_76 ) ;
F_55 ( V_22 -> V_48 ) ;
memset ( V_22 , 0xf2 , sizeof( * V_22 ) ) ;
F_55 ( V_22 ) ;
}
void F_226 ( struct V_43 * V_22 )
{
struct V_13 * V_14 , * V_223 ;
F_227 (connection, tmp, resource) {
F_228 ( & V_14 -> V_478 ) ;
F_229 ( V_14 ) ;
F_29 ( & V_14 -> V_58 , V_59 ) ;
}
F_230 ( V_22 ) ;
F_29 ( & V_22 -> V_58 , V_60 ) ;
}
static void F_231 ( void )
{
unsigned int V_158 ;
struct V_4 * V_5 ;
struct V_43 * V_22 , * V_223 ;
if ( V_479 )
F_232 ( L_38 , NULL ) ;
if ( V_465 . V_476 )
F_233 ( V_465 . V_476 ) ;
F_234 () ;
F_235 () ;
F_236 (&drbd_devices, device, i)
F_237 ( V_5 ) ;
F_238 (resource, tmp, &drbd_resources) {
F_228 ( & V_22 -> V_480 ) ;
F_226 ( V_22 ) ;
}
F_191 () ;
F_239 ( V_481 , L_38 ) ;
F_224 ( & V_482 ) ;
F_240 ( L_39 ) ;
}
static int F_241 ( void * V_483 , int V_484 )
{
struct V_4 * V_5 = V_483 ;
struct V_485 * V_433 ;
char V_486 = '-' ;
int V_18 = 0 ;
if ( ! F_242 ( V_5 ) ) {
V_18 = V_484 ;
V_486 = 'd' ;
goto V_325;
}
if ( F_92 ( V_487 , & F_22 ( V_5 ) -> V_14 -> V_44 ) ) {
V_18 |= ( 1 << V_488 ) ;
if ( ! F_89 ( V_5 , V_177 ) )
V_18 |= ( 1 << V_489 ) ;
else
F_85 ( V_5 ) ;
V_18 &= V_484 ;
V_486 = 'c' ;
goto V_325;
}
if ( F_84 ( V_5 ) ) {
V_433 = F_243 ( V_5 -> V_128 -> V_188 ) ;
V_18 = F_244 ( & V_433 -> V_490 , V_484 ) ;
F_85 ( V_5 ) ;
if ( V_18 )
V_486 = 'b' ;
}
if ( V_484 & ( 1 << V_488 ) &&
F_92 ( V_278 , & F_22 ( V_5 ) -> V_14 -> V_44 ) ) {
V_18 |= ( 1 << V_488 ) ;
V_486 = V_486 == 'b' ? 'a' : 'n' ;
}
V_325:
V_5 -> V_491 = V_486 ;
return V_18 ;
}
static void F_245 ( struct V_492 * V_476 )
{
F_33 ( & V_476 -> V_493 ) ;
F_182 ( & V_476 -> V_433 ) ;
F_184 ( & V_476 -> V_494 ) ;
}
static int F_246 ( struct V_495 * V_392 , int V_496 )
{
struct V_497 * V_497 =
F_207 ( V_392 , struct V_497 , V_392 ) ;
F_247 ( & V_497 -> V_498 ) ;
return 0 ;
}
void F_248 ( struct V_492 * V_499 )
{
struct V_497 V_497 ;
V_497 . V_392 . V_395 = F_246 ;
F_37 ( & V_497 . V_498 ) ;
F_249 ( V_499 , & V_497 . V_392 ) ;
F_44 ( & V_497 . V_498 ) ;
}
struct V_43 * F_250 ( const char * V_48 )
{
struct V_43 * V_22 ;
if ( ! V_48 || ! V_48 [ 0 ] )
return NULL ;
F_46 () ;
F_52 (resource, &drbd_resources) {
if ( ! strcmp ( V_22 -> V_48 , V_48 ) ) {
F_36 ( & V_22 -> V_58 ) ;
goto V_500;
}
}
V_22 = NULL ;
V_500:
F_49 () ;
return V_22 ;
}
struct V_13 * F_251 ( void * V_501 , int V_502 ,
void * V_503 , int V_504 )
{
struct V_43 * V_22 ;
struct V_13 * V_14 ;
F_46 () ;
F_52 (resource, &drbd_resources) {
F_252 (connection, resource) {
if ( V_14 -> V_502 == V_502 &&
V_14 -> V_504 == V_504 &&
! memcmp ( & V_14 -> V_501 , V_501 , V_502 ) &&
! memcmp ( & V_14 -> V_503 , V_503 , V_504 ) ) {
F_36 ( & V_14 -> V_58 ) ;
goto V_500;
}
}
}
V_14 = NULL ;
V_500:
F_49 () ;
return V_14 ;
}
static int F_253 ( struct V_102 * V_104 )
{
V_104 -> V_505 = ( void * ) F_254 ( V_80 ) ;
if ( ! V_104 -> V_505 )
return - V_453 ;
V_104 -> V_105 = ( void * ) F_254 ( V_80 ) ;
if ( ! V_104 -> V_105 )
return - V_453 ;
return 0 ;
}
static void F_255 ( struct V_102 * V_104 )
{
F_256 ( ( unsigned long ) V_104 -> V_105 ) ;
F_256 ( ( unsigned long ) V_104 -> V_505 ) ;
}
void F_257 ( struct V_13 * V_14 )
{
F_258 ( V_14 ) ;
F_259 ( V_14 -> V_506 ) ;
F_259 ( V_14 -> V_507 ) ;
F_259 ( V_14 -> V_508 ) ;
F_259 ( V_14 -> V_313 ) ;
F_259 ( V_14 -> V_263 ) ;
F_55 ( V_14 -> V_509 ) ;
F_55 ( V_14 -> V_510 ) ;
V_14 -> V_506 = NULL ;
V_14 -> V_507 = NULL ;
V_14 -> V_508 = NULL ;
V_14 -> V_313 = NULL ;
V_14 -> V_263 = NULL ;
V_14 -> V_509 = NULL ;
V_14 -> V_510 = NULL ;
}
int F_260 ( struct V_43 * V_22 , struct V_511 * V_511 )
{
struct V_13 * V_14 ;
T_2 V_512 ;
int V_110 ;
if ( ! F_261 ( & V_512 , V_80 ) )
return - V_453 ;
if ( V_79 > 1 && V_511 -> V_76 [ 0 ] != 0 ) {
V_110 = F_262 ( V_511 -> V_76 , V_513 ,
F_263 ( V_512 ) , V_79 ) ;
if ( V_110 == - V_514 ) {
T_2 V_515 ;
if ( F_261 ( & V_515 , V_80 ) ) {
F_56 ( V_515 ) ;
F_264 ( V_512 , V_512 , V_515 ) ;
F_159 ( V_22 , L_40 ,
V_511 -> V_76 ,
strlen ( V_511 -> V_76 ) > 12 ? L_41 : L_42 ,
V_79 ) ;
F_225 ( V_515 ) ;
V_110 = 0 ;
}
}
if ( V_110 ) {
F_159 ( V_22 , L_43 , V_110 ) ;
goto V_516;
}
}
V_22 -> V_511 = * V_511 ;
if ( F_265 ( V_512 ) )
F_50 ( & V_512 ) ;
if ( ! F_266 ( V_22 -> V_76 , V_512 ) ) {
F_267 ( V_22 -> V_76 , V_512 ) ;
F_252 (connection, resource) {
V_14 -> V_416 . V_65 = 1 ;
V_14 -> V_273 . V_65 = 1 ;
V_14 -> V_466 . V_65 = 1 ;
}
}
V_110 = 0 ;
V_516:
F_225 ( V_512 ) ;
return V_110 ;
}
struct V_43 * F_268 ( const char * V_48 )
{
struct V_43 * V_22 ;
V_22 = F_51 ( sizeof( struct V_43 ) , V_80 ) ;
if ( ! V_22 )
goto V_516;
V_22 -> V_48 = F_269 ( V_48 , V_80 ) ;
if ( ! V_22 -> V_48 )
goto V_517;
if ( ! F_261 ( & V_22 -> V_76 , V_80 ) )
goto V_518;
F_270 ( & V_22 -> V_58 ) ;
F_271 ( & V_22 -> V_477 ) ;
F_182 ( & V_22 -> V_478 ) ;
V_22 -> V_519 = V_520 ;
F_272 ( & V_22 -> V_480 , & V_521 ) ;
F_181 ( & V_22 -> V_522 ) ;
F_181 ( & V_22 -> V_523 ) ;
F_33 ( & V_22 -> V_23 ) ;
F_273 ( V_22 ) ;
return V_22 ;
V_518:
F_55 ( V_22 -> V_48 ) ;
V_517:
F_55 ( V_22 ) ;
V_516:
return NULL ;
}
struct V_13 * F_274 ( const char * V_48 , struct V_511 * V_511 )
{
struct V_43 * V_22 ;
struct V_13 * V_14 ;
V_14 = F_51 ( sizeof( struct V_13 ) , V_80 ) ;
if ( ! V_14 )
return NULL ;
if ( F_253 ( & V_14 -> V_108 ) )
goto V_516;
if ( F_253 ( & V_14 -> V_114 ) )
goto V_516;
V_14 -> V_524 = F_51 ( sizeof( struct V_525 ) , V_80 ) ;
if ( ! V_14 -> V_524 )
goto V_516;
F_182 ( & V_14 -> V_526 ) ;
F_182 ( & V_14 -> V_524 -> V_389 ) ;
V_14 -> V_527 = 1 ;
F_33 ( & V_14 -> V_528 ) ;
V_14 -> V_529 . V_530 = false ;
V_14 -> V_529 . V_531 = 0 ;
V_14 -> V_529 . V_532 = 0 ;
V_22 = F_268 ( V_48 ) ;
if ( ! V_22 )
goto V_516;
V_14 -> V_250 = V_363 ;
F_181 ( & V_14 -> V_533 ) ;
F_184 ( & V_14 -> V_534 ) ;
F_271 ( & V_14 -> V_75 ) ;
F_245 ( & V_14 -> V_432 ) ;
F_181 ( & V_14 -> V_108 . V_106 ) ;
F_181 ( & V_14 -> V_114 . V_106 ) ;
F_31 ( V_22 , & V_14 -> V_416 , V_535 , L_44 ) ;
V_14 -> V_416 . V_14 = V_14 ;
F_31 ( V_22 , & V_14 -> V_466 , V_536 , L_45 ) ;
V_14 -> V_466 . V_14 = V_14 ;
F_31 ( V_22 , & V_14 -> V_273 , V_537 , L_46 ) ;
V_14 -> V_273 . V_14 = V_14 ;
F_270 ( & V_14 -> V_58 ) ;
V_14 -> V_22 = V_22 ;
if ( F_260 ( V_22 , V_511 ) )
goto V_538;
F_36 ( & V_22 -> V_58 ) ;
F_272 ( & V_14 -> V_478 , & V_22 -> V_478 ) ;
F_275 ( V_14 ) ;
return V_14 ;
V_538:
F_228 ( & V_22 -> V_480 ) ;
F_226 ( V_22 ) ;
V_516:
F_55 ( V_14 -> V_524 ) ;
F_255 ( & V_14 -> V_114 ) ;
F_255 ( & V_14 -> V_108 ) ;
F_55 ( V_14 ) ;
return NULL ;
}
void V_59 ( struct V_58 * V_58 )
{
struct V_13 * V_14 = F_207 ( V_58 , struct V_13 , V_58 ) ;
struct V_43 * V_22 = V_14 -> V_22 ;
if ( F_217 ( & V_14 -> V_524 -> V_539 ) != 0 )
F_11 ( V_14 , L_47 , F_217 ( & V_14 -> V_524 -> V_539 ) ) ;
F_55 ( V_14 -> V_524 ) ;
F_224 ( & V_14 -> V_75 ) ;
F_255 ( & V_14 -> V_114 ) ;
F_255 ( & V_14 -> V_108 ) ;
F_55 ( V_14 -> V_509 ) ;
F_55 ( V_14 -> V_510 ) ;
memset ( V_14 , 0xfc , sizeof( * V_14 ) ) ;
F_55 ( V_14 ) ;
F_29 ( & V_22 -> V_58 , V_60 ) ;
}
static int F_276 ( struct V_4 * V_5 )
{
V_5 -> V_540 . V_476 = F_277 ( L_48 ,
V_541 | V_542 , 1 , V_5 -> V_74 ) ;
if ( ! V_5 -> V_540 . V_476 )
return - V_453 ;
F_278 ( & V_5 -> V_540 . V_466 , V_543 ) ;
F_182 ( & V_5 -> V_540 . V_467 ) ;
return 0 ;
}
enum V_544 F_279 ( struct V_545 * V_546 , unsigned int V_74 )
{
struct V_43 * V_22 = V_546 -> V_22 ;
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_71 * V_72 , * V_455 ;
struct V_357 * V_11 ;
struct V_485 * V_433 ;
int V_547 ;
int V_73 = V_546 -> V_98 ;
enum V_544 V_110 = V_548 ;
V_5 = F_280 ( V_74 ) ;
if ( V_5 )
return V_549 ;
V_5 = F_51 ( sizeof( struct V_4 ) , V_80 ) ;
if ( ! V_5 )
return V_548 ;
F_270 ( & V_5 -> V_58 ) ;
F_36 ( & V_22 -> V_58 ) ;
V_5 -> V_22 = V_22 ;
V_5 -> V_74 = V_74 ;
V_5 -> V_73 = V_73 ;
F_179 ( V_5 ) ;
V_433 = F_281 ( V_80 ) ;
if ( ! V_433 )
goto V_550;
V_5 -> V_460 = V_433 ;
V_433 -> V_551 = V_5 ;
V_11 = F_282 ( 1 ) ;
if ( ! V_11 )
goto V_552;
V_5 -> V_459 = V_11 ;
F_283 ( V_11 , true ) ;
V_11 -> V_191 = V_433 ;
V_11 -> V_553 = V_481 ;
V_11 -> V_554 = V_74 ;
V_11 -> V_555 = & V_556 ;
sprintf ( V_11 -> V_557 , L_49 , V_74 ) ;
V_11 -> V_348 = V_5 ;
V_5 -> V_196 = F_284 ( F_285 ( V_481 , V_74 ) ) ;
V_5 -> V_196 -> V_558 = V_5 -> V_196 ;
V_433 -> V_490 . V_559 = F_241 ;
V_433 -> V_490 . V_483 = V_5 ;
F_286 ( V_433 , V_560 ) ;
F_287 ( V_433 , V_307 | V_305 ) ;
F_288 ( V_433 , V_414 >> 8 ) ;
F_289 ( V_433 , V_561 ) ;
F_290 ( V_433 , V_562 ) ;
V_433 -> V_563 = & V_22 -> V_23 ;
V_5 -> V_376 . V_279 = F_202 ( V_80 ) ;
if ( ! V_5 -> V_376 . V_279 )
goto V_564;
if ( F_291 ( V_5 ) )
goto V_565;
V_5 -> V_566 = V_567 ;
V_5 -> V_568 = V_567 ;
V_547 = F_292 ( & V_482 , V_5 , V_74 , V_74 + 1 , V_80 ) ;
if ( V_547 < 0 ) {
if ( V_547 == - V_569 ) {
V_110 = V_549 ;
F_293 ( V_546 -> V_570 , L_50 ) ;
}
goto V_571;
}
F_36 ( & V_5 -> V_58 ) ;
V_547 = F_292 ( & V_22 -> V_477 , V_5 , V_73 , V_73 + 1 , V_80 ) ;
if ( V_547 < 0 ) {
if ( V_547 == - V_569 ) {
V_110 = V_549 ;
F_293 ( V_546 -> V_570 , L_50 ) ;
}
goto V_572;
}
F_36 ( & V_5 -> V_58 ) ;
F_182 ( & V_5 -> V_75 ) ;
F_182 ( & V_5 -> V_573 ) ;
F_294 (connection, resource) {
V_72 = F_51 ( sizeof( struct V_71 ) , V_80 ) ;
if ( ! V_72 )
goto V_574;
V_72 -> V_14 = V_14 ;
V_72 -> V_5 = V_5 ;
F_295 ( & V_72 -> V_75 , & V_5 -> V_75 ) ;
F_36 ( & V_5 -> V_58 ) ;
V_547 = F_292 ( & V_14 -> V_75 , V_72 , V_73 , V_73 + 1 , V_80 ) ;
if ( V_547 < 0 ) {
if ( V_547 == - V_569 ) {
V_110 = V_575 ;
F_293 ( V_546 -> V_570 , L_51 ) ;
}
goto V_574;
}
F_36 ( & V_14 -> V_58 ) ;
}
if ( F_276 ( V_5 ) ) {
V_110 = V_548 ;
F_293 ( V_546 -> V_570 , L_52 ) ;
goto V_576;
}
F_296 ( V_11 ) ;
V_5 -> V_10 . V_32 = F_297 ( V_22 ) -> V_250 ;
if ( V_5 -> V_10 . V_32 == V_251 ) {
F_298 (peer_device, device)
F_299 ( V_72 ) ;
}
F_298 (peer_device, device)
F_300 ( V_72 ) ;
F_301 ( V_5 ) ;
return V_577 ;
V_576:
F_302 ( & V_14 -> V_75 , V_73 ) ;
V_574:
F_294 (connection, resource) {
V_72 = F_303 ( & V_14 -> V_75 , V_73 ) ;
if ( V_72 ) {
F_302 ( & V_14 -> V_75 , V_73 ) ;
F_29 ( & V_14 -> V_58 , V_59 ) ;
}
}
F_213 (peer_device, tmp_peer_device, device) {
F_228 ( & V_72 -> V_75 ) ;
F_55 ( V_72 ) ;
}
F_302 ( & V_22 -> V_477 , V_73 ) ;
V_572:
F_302 ( & V_482 , V_74 ) ;
F_304 () ;
V_571:
F_188 ( V_5 ) ;
V_565:
F_193 ( V_5 -> V_376 . V_279 ) ;
V_564:
F_211 ( V_11 ) ;
V_552:
F_212 ( V_433 ) ;
V_550:
F_29 ( & V_22 -> V_58 , V_60 ) ;
F_55 ( V_5 ) ;
return V_110 ;
}
void F_237 ( struct V_4 * V_5 )
{
struct V_43 * V_22 = V_5 -> V_22 ;
struct V_13 * V_14 ;
struct V_71 * V_72 ;
int V_578 = 3 ;
F_298 (peer_device, device)
F_305 ( V_72 ) ;
F_306 ( V_5 ) ;
F_294 (connection, resource) {
F_302 ( & V_14 -> V_75 , V_5 -> V_73 ) ;
V_578 ++ ;
}
F_302 ( & V_22 -> V_477 , V_5 -> V_73 ) ;
F_302 ( & V_482 , F_48 ( V_5 ) ) ;
F_307 ( V_5 -> V_459 ) ;
F_304 () ;
F_308 ( & V_5 -> V_58 , V_578 , F_206 ) ;
}
static int T_8 F_309 ( void )
{
int V_110 ;
if ( V_444 < V_579 || V_444 > V_580 ) {
F_310 ( L_53 , V_444 ) ;
#ifdef F_311
return - V_581 ;
#else
V_444 = V_582 ;
#endif
}
V_110 = F_312 ( V_481 , L_38 ) ;
if ( V_110 ) {
F_310 ( L_54 ,
V_481 ) ;
return V_110 ;
}
F_184 ( & V_583 ) ;
V_479 = NULL ;
F_271 ( & V_482 ) ;
F_313 ( & V_584 ) ;
F_182 ( & V_521 ) ;
V_110 = F_314 () ;
if ( V_110 ) {
F_310 ( L_55 ) ;
goto V_516;
}
V_110 = F_197 () ;
if ( V_110 )
goto V_516;
V_110 = - V_453 ;
V_479 = F_315 ( L_38 , V_585 | V_586 , NULL , & V_587 , NULL ) ;
if ( ! V_479 ) {
F_310 ( L_56 ) ;
goto V_516;
}
V_465 . V_476 = F_316 ( L_57 ) ;
if ( ! V_465 . V_476 ) {
F_310 ( L_58 ) ;
goto V_516;
}
F_278 ( & V_465 . V_466 , F_214 ) ;
F_33 ( & V_465 . V_468 ) ;
F_182 ( & V_465 . V_467 ) ;
if ( F_317 () )
F_318 ( L_59 ) ;
F_240 ( L_60
L_61 V_588 L_62 ,
V_589 , V_590 , V_591 ) ;
F_240 ( L_63 , F_319 () ) ;
F_240 ( L_64 , V_481 ) ;
return 0 ;
V_516:
F_231 () ;
if ( V_110 == - V_453 )
F_310 ( L_65 ) ;
else
F_310 ( L_66 ) ;
return V_110 ;
}
void F_189 ( struct V_592 * V_128 )
{
if ( V_128 == NULL )
return;
F_320 ( V_128 -> V_188 , V_593 | V_352 | V_594 ) ;
F_320 ( V_128 -> V_595 , V_593 | V_352 | V_594 ) ;
F_55 ( V_128 -> V_120 ) ;
F_55 ( V_128 ) ;
}
static void F_321 ( struct V_102 * V_596 )
{
struct V_104 * V_24 ;
F_71 ( & V_596 -> V_106 ) ;
V_24 = V_596 -> V_104 ;
V_596 -> V_104 = NULL ;
F_72 ( & V_596 -> V_106 ) ;
if ( V_24 ) {
F_304 () ;
F_322 ( V_24 , V_597 ) ;
F_323 ( V_24 ) ;
}
}
void F_258 ( struct V_13 * V_14 )
{
if ( V_14 -> V_108 . V_104 )
F_321 ( & V_14 -> V_108 ) ;
if ( V_14 -> V_114 . V_104 )
F_321 ( & V_14 -> V_114 ) ;
}
void F_324 ( struct V_13 * V_14 )
{
struct V_71 * V_72 ;
int V_73 ;
F_46 () ;
F_236 (&connection->peer_devices, peer_device, vnr) {
struct V_4 * V_5 = V_72 -> V_5 ;
F_36 ( & V_5 -> V_58 ) ;
F_49 () ;
F_100 ( V_5 ) ;
F_29 ( & V_5 -> V_58 , F_206 ) ;
F_46 () ;
}
F_49 () ;
}
void F_325 ( struct V_4 * V_5 , void * V_233 )
{
struct V_598 * V_100 = V_233 ;
T_4 V_254 ;
int V_158 ;
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
V_100 -> V_599 = F_90 ( F_105 ( V_5 -> V_196 ) ) ;
for ( V_158 = V_162 ; V_158 < V_163 ; V_158 ++ )
V_100 -> V_164 [ V_158 ] = F_90 ( V_5 -> V_128 -> V_160 . V_164 [ V_158 ] ) ;
V_100 -> V_44 = F_64 ( V_5 -> V_128 -> V_160 . V_44 ) ;
V_100 -> V_92 = F_64 ( V_600 ) ;
V_100 -> V_601 = F_64 ( V_5 -> V_128 -> V_160 . V_601 ) ;
V_100 -> V_602 = F_64 ( V_5 -> V_128 -> V_160 . V_602 ) ;
V_100 -> V_603 = F_64 ( V_5 -> V_456 -> V_604 ) ;
V_100 -> V_605 = F_64 ( V_606 ) ;
V_100 -> V_607 = F_90 ( V_5 -> V_128 -> V_160 . V_607 ) ;
V_100 -> V_608 = F_64 ( V_5 -> V_128 -> V_160 . V_608 ) ;
V_100 -> V_609 = F_64 ( V_5 -> V_413 ) ;
V_100 -> V_610 = F_64 ( V_5 -> V_128 -> V_160 . V_610 ) ;
V_100 -> V_611 = F_64 ( V_5 -> V_128 -> V_160 . V_611 ) ;
F_97 ( V_5 , F_326 ( V_5 -> V_128 ) == V_5 -> V_128 -> V_160 . V_612 ) ;
V_254 = V_5 -> V_128 -> V_160 . V_612 ;
if ( F_327 ( V_5 , V_5 -> V_128 , V_254 , V_613 ) ) {
F_11 ( V_5 , L_67 ) ;
F_328 ( V_5 , 1 , V_614 ) ;
}
}
void F_100 ( struct V_4 * V_5 )
{
struct V_598 * V_100 ;
F_61 ( V_163 != 4 ) ;
F_61 ( sizeof( struct V_598 ) != 4096 ) ;
F_329 ( & V_5 -> V_400 ) ;
if ( ! F_330 ( V_615 , & V_5 -> V_44 ) )
return;
if ( ! F_89 ( V_5 , V_616 ) )
return;
V_100 = F_331 ( V_5 , V_291 ) ;
if ( ! V_100 )
goto V_325;
F_325 ( V_5 , V_100 ) ;
V_5 -> V_128 -> V_160 . V_599 = F_105 ( V_5 -> V_196 ) ;
F_332 ( V_5 ) ;
V_325:
F_85 ( V_5 ) ;
}
static int F_333 ( struct V_4 * V_5 ,
struct V_598 * V_617 ,
struct V_618 * V_619 )
{
T_5 V_610 = F_334 ( V_617 -> V_610 ) ;
T_5 V_611 = F_334 ( V_617 -> V_611 ) ;
T_3 V_620 ;
if ( V_610 == 0 && V_611 == 0 ) {
V_610 = 1 ;
V_611 = V_621 / 8 ;
}
if ( V_610 == 0 || V_611 == 0 )
goto V_110;
V_620 = ( T_3 ) V_610 * V_611 ;
if ( V_620 > ( 16 * 1024 * 1024 / 4 ) )
goto V_110;
if ( V_620 < V_621 / 8 )
goto V_110;
V_619 -> V_611 = V_611 ;
V_619 -> V_610 = V_610 ;
V_619 -> V_620 = V_620 ;
return 0 ;
V_110:
F_11 ( V_5 , L_68 ,
V_610 , V_611 ) ;
return - V_581 ;
}
static int F_335 ( struct V_4 * V_5 , struct V_592 * V_346 )
{
T_4 V_622 = F_105 ( V_346 -> V_595 ) ;
struct V_618 * V_619 = & V_346 -> V_160 ;
T_9 V_623 ;
T_9 V_624 ;
if ( V_619 -> V_602 < 0 ) {
if ( V_619 -> V_608 > V_619 -> V_602 )
goto V_110;
V_623 = - V_619 -> V_602 ;
V_624 = V_619 -> V_602 - V_619 -> V_608 ;
} else {
if ( V_619 -> V_602 != V_625 )
goto V_110;
if ( V_619 -> V_608 < V_619 -> V_602 + V_619 -> V_620 * V_625 )
goto V_110;
V_623 = V_619 -> V_608 - V_625 ;
V_624 = V_619 -> V_601 - V_619 -> V_608 ;
}
if ( V_619 -> V_626 >= 0 ) {
if ( V_619 -> V_601 != V_627
|| V_619 -> V_602 != V_625
|| V_619 -> V_608 != V_625 + V_621
|| V_619 -> V_610 != 1
|| V_619 -> V_611 != V_621 / 8 )
goto V_110;
}
if ( V_622 < V_619 -> V_601 )
goto V_110;
if ( V_622 - V_619 -> V_601 < F_336 ( V_346 ) )
goto V_110;
if ( ( V_623 & 7 ) || ( V_623 < V_621 ) )
goto V_110;
if ( V_623 != V_619 -> V_620 * V_625 )
goto V_110;
if ( V_619 -> V_608 & 7 )
goto V_110;
if ( V_624 < ( V_619 -> V_599 + 7 ) / V_625 / 8 / 512 )
goto V_110;
return 0 ;
V_110:
F_11 ( V_5 , L_69
L_70
L_71 ,
V_619 -> V_626 ,
V_619 -> V_610 , V_619 -> V_611 ,
V_619 -> V_602 , V_619 -> V_608 , V_619 -> V_601 ,
( unsigned long long ) V_619 -> V_599 ,
( unsigned long long ) V_622 ) ;
return - V_581 ;
}
int F_337 ( struct V_4 * V_5 , struct V_592 * V_346 )
{
struct V_598 * V_100 ;
T_5 V_92 , V_44 ;
int V_158 , V_334 = V_577 ;
if ( V_5 -> V_10 . V_11 != V_364 )
return V_628 ;
V_100 = F_331 ( V_5 , V_291 ) ;
if ( ! V_100 )
return V_548 ;
V_346 -> V_160 . V_626 = V_346 -> V_120 -> V_626 ;
V_346 -> V_160 . V_612 = F_326 ( V_346 ) ;
if ( F_327 ( V_5 , V_346 , V_346 -> V_160 . V_612 , V_629 ) ) {
F_11 ( V_5 , L_72 ) ;
V_334 = V_630 ;
goto V_110;
}
V_92 = F_334 ( V_100 -> V_92 ) ;
V_44 = F_334 ( V_100 -> V_44 ) ;
if ( V_92 == V_600 ||
( V_92 == V_631 && ! ( V_44 & V_632 ) ) ) {
F_11 ( V_5 , L_73 ) ;
V_334 = V_633 ;
goto V_110;
}
V_334 = V_634 ;
if ( V_92 != V_631 ) {
if ( V_92 == V_635 )
F_11 ( V_5 , L_74 ) ;
else
F_11 ( V_5 , L_75 ) ;
goto V_110;
}
if ( F_334 ( V_100 -> V_605 ) != V_606 ) {
F_11 ( V_5 , L_76 ,
F_334 ( V_100 -> V_605 ) , V_606 ) ;
goto V_110;
}
V_346 -> V_160 . V_599 = F_338 ( V_100 -> V_599 ) ;
for ( V_158 = V_162 ; V_158 < V_163 ; V_158 ++ )
V_346 -> V_160 . V_164 [ V_158 ] = F_338 ( V_100 -> V_164 [ V_158 ] ) ;
V_346 -> V_160 . V_44 = F_334 ( V_100 -> V_44 ) ;
V_346 -> V_160 . V_607 = F_338 ( V_100 -> V_607 ) ;
V_346 -> V_160 . V_601 = F_334 ( V_100 -> V_601 ) ;
V_346 -> V_160 . V_602 = F_334 ( V_100 -> V_602 ) ;
V_346 -> V_160 . V_608 = F_334 ( V_100 -> V_608 ) ;
if ( F_333 ( V_5 , V_100 , & V_346 -> V_160 ) )
goto V_110;
if ( F_335 ( V_5 , V_346 ) )
goto V_110;
if ( F_334 ( V_100 -> V_608 ) != V_346 -> V_160 . V_608 ) {
F_11 ( V_5 , L_77 ,
F_334 ( V_100 -> V_608 ) , V_346 -> V_160 . V_608 ) ;
goto V_110;
}
if ( F_334 ( V_100 -> V_601 ) != V_346 -> V_160 . V_601 ) {
F_11 ( V_5 , L_78 ,
F_334 ( V_100 -> V_601 ) , V_346 -> V_160 . V_601 ) ;
goto V_110;
}
V_334 = V_577 ;
F_9 ( & V_5 -> V_22 -> V_23 ) ;
if ( V_5 -> V_10 . V_32 < V_258 ) {
unsigned int V_361 ;
V_361 = F_334 ( V_100 -> V_609 ) ;
V_361 = F_339 ( V_361 , V_414 ) ;
V_5 -> V_413 = V_361 ;
}
F_14 ( & V_5 -> V_22 -> V_23 ) ;
V_110:
F_332 ( V_5 ) ;
return V_334 ;
}
void F_340 ( struct V_4 * V_5 , unsigned int line , const char * F_32 )
{
if ( ! F_341 ( V_615 , & V_5 -> V_44 ) ) {
F_342 ( & V_5 -> V_400 , V_636 + V_637 ) ;
V_5 -> V_638 . line = line ;
V_5 -> V_638 . F_32 = F_32 ;
}
}
void F_343 ( struct V_4 * V_5 )
{
if ( ! F_341 ( V_615 , & V_5 -> V_44 ) )
F_342 ( & V_5 -> V_400 , V_636 + 5 * V_637 ) ;
}
void F_344 ( struct V_4 * V_5 ) __must_hold( T_10 )
{
int V_158 ;
for ( V_158 = V_173 ; V_158 < V_174 ; V_158 ++ )
V_5 -> V_128 -> V_160 . V_164 [ V_158 + 1 ] = V_5 -> V_128 -> V_160 . V_164 [ V_158 ] ;
}
void F_345 ( struct V_4 * V_5 , int V_639 , T_3 V_203 ) __must_hold( T_10 )
{
if ( V_639 == V_162 ) {
if ( V_5 -> V_10 . V_350 == V_351 )
V_203 |= 1 ;
else
V_203 &= ~ ( ( T_3 ) 1 ) ;
F_346 ( V_5 , V_203 ) ;
}
V_5 -> V_128 -> V_160 . V_164 [ V_639 ] = V_203 ;
F_343 ( V_5 ) ;
}
void F_347 ( struct V_4 * V_5 , int V_639 , T_3 V_203 ) __must_hold( T_10 )
{
unsigned long V_44 ;
F_24 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
F_345 ( V_5 , V_639 , V_203 ) ;
F_26 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
}
void F_99 ( struct V_4 * V_5 , int V_639 , T_3 V_203 ) __must_hold( T_10 )
{
unsigned long V_44 ;
F_24 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
if ( V_5 -> V_128 -> V_160 . V_164 [ V_639 ] ) {
F_344 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_173 ] = V_5 -> V_128 -> V_160 . V_164 [ V_639 ] ;
}
F_345 ( V_5 , V_639 , V_203 ) ;
F_26 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
}
void F_348 ( struct V_4 * V_5 ) __must_hold( T_10 )
{
T_3 V_203 ;
unsigned long long V_640 ;
F_98 ( & V_203 , sizeof( T_3 ) ) ;
F_9 ( & V_5 -> V_128 -> V_160 . V_161 ) ;
V_640 = V_5 -> V_128 -> V_160 . V_164 [ V_172 ] ;
if ( V_640 )
F_159 ( V_5 , L_79 , V_640 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_172 ] = V_5 -> V_128 -> V_160 . V_164 [ V_162 ] ;
F_345 ( V_5 , V_162 , V_203 ) ;
F_14 ( & V_5 -> V_128 -> V_160 . V_161 ) ;
F_95 ( V_5 , L_80 ) ;
F_100 ( V_5 ) ;
}
void F_349 ( struct V_4 * V_5 , T_3 V_203 ) __must_hold( T_10 )
{
unsigned long V_44 ;
if ( V_5 -> V_128 -> V_160 . V_164 [ V_172 ] == 0 && V_203 == 0 )
return;
F_24 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
if ( V_203 == 0 ) {
F_344 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_173 ] = V_5 -> V_128 -> V_160 . V_164 [ V_172 ] ;
V_5 -> V_128 -> V_160 . V_164 [ V_172 ] = 0 ;
} else {
unsigned long long V_640 = V_5 -> V_128 -> V_160 . V_164 [ V_172 ] ;
if ( V_640 )
F_159 ( V_5 , L_79 , V_640 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_172 ] = V_203 & ~ ( ( T_3 ) 1 ) ;
}
F_26 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
F_343 ( V_5 ) ;
}
int F_350 ( struct V_4 * V_5 ) __must_hold( T_10 )
{
int V_334 = - V_115 ;
F_351 ( V_5 , V_248 ) ;
F_100 ( V_5 ) ;
F_129 ( V_5 ) ;
V_334 = F_130 ( V_5 ) ;
if ( ! V_334 ) {
F_131 ( V_5 , V_248 ) ;
F_100 ( V_5 ) ;
}
return V_334 ;
}
int F_352 ( struct V_4 * V_5 ) __must_hold( T_10 )
{
F_353 ( V_5 ) ;
F_354 ( V_5 ) ;
return F_130 ( V_5 ) ;
}
static int V_398 ( struct V_495 * V_392 , int V_641 )
{
struct V_4 * V_5 =
F_207 ( V_392 , struct V_4 , V_391 . V_392 ) ;
struct V_391 * V_642 = & V_5 -> V_391 ;
int V_334 = - V_115 ;
F_97 ( V_5 , F_217 ( & V_5 -> V_367 ) == 0 ) ;
if ( F_84 ( V_5 ) ) {
F_355 ( V_5 , V_642 -> V_643 , V_642 -> V_44 ) ;
V_334 = V_642 -> V_644 ( V_5 ) ;
F_356 ( V_5 ) ;
F_85 ( V_5 ) ;
}
F_357 ( V_645 , & V_5 -> V_44 ) ;
F_7 ( & V_5 -> V_12 ) ;
if ( V_642 -> V_498 )
V_642 -> V_498 ( V_5 , V_334 ) ;
F_160 ( V_646 , & V_5 -> V_44 ) ;
V_642 -> V_643 = NULL ;
V_642 -> V_44 = 0 ;
return 0 ;
}
void F_358 ( struct V_4 * V_5 ,
int (* V_644)( struct V_4 * ) ,
void (* V_498)( struct V_4 * , int ) ,
char * V_643 , enum V_647 V_44 )
{
F_97 ( V_5 , V_46 == F_22 ( V_5 ) -> V_14 -> V_466 . V_55 ) ;
F_97 ( V_5 , ! F_92 ( V_646 , & V_5 -> V_44 ) ) ;
F_97 ( V_5 , ! F_92 ( V_645 , & V_5 -> V_44 ) ) ;
F_97 ( V_5 , F_190 ( & V_5 -> V_391 . V_392 . V_389 ) ) ;
if ( V_5 -> V_391 . V_643 )
F_11 ( V_5 , L_81 ,
V_643 , V_5 -> V_391 . V_643 ) ;
V_5 -> V_391 . V_644 = V_644 ;
V_5 -> V_391 . V_498 = V_498 ;
V_5 -> V_391 . V_643 = V_643 ;
V_5 -> V_391 . V_44 = V_44 ;
F_9 ( & V_5 -> V_22 -> V_23 ) ;
F_150 ( V_645 , & V_5 -> V_44 ) ;
if ( F_217 ( & V_5 -> V_367 ) == 0 ) {
if ( ! F_341 ( V_646 , & V_5 -> V_44 ) )
F_249 ( & F_22 ( V_5 ) -> V_14 -> V_432 ,
& V_5 -> V_391 . V_392 ) ;
}
F_14 ( & V_5 -> V_22 -> V_23 ) ;
}
int F_359 ( struct V_4 * V_5 , int (* V_644)( struct V_4 * ) ,
char * V_643 , enum V_647 V_44 )
{
int V_334 ;
F_97 ( V_5 , V_46 != F_22 ( V_5 ) -> V_14 -> V_466 . V_55 ) ;
if ( ( V_44 & V_648 ) == 0 )
F_360 ( V_5 ) ;
F_355 ( V_5 , V_643 , V_44 ) ;
V_334 = V_644 ( V_5 ) ;
F_356 ( V_5 ) ;
if ( ( V_44 & V_648 ) == 0 )
F_361 ( V_5 ) ;
return V_334 ;
}
void F_351 ( struct V_4 * V_5 , int V_649 ) __must_hold( T_10 )
{
if ( ( V_5 -> V_128 -> V_160 . V_44 & V_649 ) != V_649 ) {
F_343 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_44 |= V_649 ;
}
}
void F_131 ( struct V_4 * V_5 , int V_649 ) __must_hold( T_10 )
{
if ( ( V_5 -> V_128 -> V_160 . V_44 & V_649 ) != 0 ) {
F_343 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_44 &= ~ V_649 ;
}
}
int F_128 ( struct V_592 * V_346 , int V_649 )
{
return ( V_346 -> V_160 . V_44 & V_649 ) != 0 ;
}
static void V_404 ( unsigned long V_108 )
{
struct V_4 * V_5 = (struct V_4 * ) V_108 ;
F_362 ( V_5 , V_650 ) ;
}
const char * F_363 ( enum V_89 V_90 )
{
static const char * V_651 [] = {
[ V_326 ] = L_82 ,
[ V_652 ] = L_83 ,
[ V_653 ] = L_84 ,
[ V_654 ] = L_85 ,
[ V_246 ] = L_86 ,
[ V_655 ] = L_87 ,
[ V_656 ] = L_88 ,
[ V_657 ] = L_89 ,
[ V_658 ] = L_90 ,
[ V_659 ] = L_91 ,
[ V_126 ] = L_92 ,
[ V_125 ] = L_93 ,
[ V_155 ] = L_94 ,
[ V_170 ] = L_95 ,
[ V_198 ] = L_96 ,
[ V_200 ] = L_97 ,
[ V_180 ] = L_98 ,
[ V_660 ] = L_99 ,
[ V_661 ] = L_100 ,
[ V_112 ] = L_101 ,
[ V_113 ] = L_102 ,
[ V_662 ] = L_103 ,
[ V_663 ] = L_104 ,
[ V_664 ] = L_105 ,
[ V_665 ] = L_106 ,
[ V_666 ] = L_107 ,
[ V_667 ] = L_108 ,
[ V_668 ] = L_109 ,
[ V_253 ] = L_110 ,
[ V_205 ] = L_111 ,
[ V_210 ] = L_112 ,
[ V_271 ] = L_113 ,
[ V_669 ] = L_114 ,
[ V_670 ] = L_115 ,
[ V_671 ] = L_116 ,
[ V_672 ] = L_117 ,
[ V_239 ] = L_118 ,
[ V_673 ] = L_119 ,
[ V_328 ] = L_120 ,
[ V_674 ] = L_121 ,
[ V_675 ] = L_122 ,
[ V_206 ] = L_123 ,
[ V_211 ] = L_124 ,
[ V_674 ] = L_125 ,
[ V_676 ] = L_126 ,
} ;
if ( V_90 == V_677 )
return L_127 ;
if ( V_90 == V_678 )
return L_128 ;
if ( V_90 == V_679 )
return L_129 ;
if ( V_90 >= F_364 ( V_651 ) )
return L_130 ;
return V_651 [ V_90 ] ;
}
int F_365 ( struct V_4 * V_5 , struct V_680 * V_158 )
{
struct V_118 * V_119 ;
F_366 ( V_67 ) ;
long V_681 ;
F_46 () ;
V_119 = F_83 ( F_22 ( V_5 ) -> V_14 -> V_118 ) ;
if ( ! V_119 ) {
F_49 () ;
return - V_682 ;
}
V_681 = V_119 -> V_274 ? V_119 -> V_681 * V_637 / 10 * V_119 -> V_274 : V_683 ;
F_49 () ;
V_158 -> V_684 = true ;
F_367 ( & V_5 -> V_12 , & V_67 , V_685 ) ;
F_14 ( & V_5 -> V_22 -> V_23 ) ;
V_681 = F_368 ( V_681 ) ;
F_369 ( & V_5 -> V_12 , & V_67 ) ;
F_9 ( & V_5 -> V_22 -> V_23 ) ;
if ( ! V_681 || V_5 -> V_10 . V_32 < V_258 )
return - V_682 ;
if ( F_370 ( V_46 ) )
return - V_686 ;
return 0 ;
}
static unsigned long
F_371 ( struct V_687 * V_688 )
{
long V_689 ;
if ( ! V_688 -> V_690 -- ) {
F_98 ( & V_689 , sizeof( V_689 ) ) ;
V_688 -> V_10 += V_689 ;
V_688 -> V_690 = V_691 ;
}
V_688 -> V_10 = V_688 -> V_10 * V_692 + V_693 ;
return F_372 ( V_688 -> V_10 ) ;
}
static char *
F_373 ( unsigned int type ) {
static char * V_694 [] = {
[ V_695 ] = L_131 ,
[ V_696 ] = L_132 ,
[ V_697 ] = L_133 ,
[ V_698 ] = L_134 ,
[ V_699 ] = L_135 ,
[ V_700 ] = L_136 ,
[ V_701 ] = L_137 ,
[ V_702 ] = L_138 ,
[ V_703 ] = L_139 ,
[ V_704 ] = L_140 ,
} ;
return ( type < V_705 ) ? V_694 [ type ] : L_141 ;
}
unsigned int
F_374 ( struct V_4 * V_5 , unsigned int type )
{
static struct V_687 V_706 = { 0 , 0 } ;
unsigned int V_707 = (
( V_708 == 0 ||
( ( 1 << F_48 ( V_5 ) ) & V_708 ) != 0 ) &&
( ( ( F_371 ( & V_706 ) % 100 ) + 1 ) <= V_709 ) ) ;
if ( V_707 ) {
V_710 ++ ;
if ( F_375 ( & V_711 ) )
F_159 ( V_5 , L_142 ,
F_373 ( type ) ) ;
}
return V_707 ;
}
const char * F_319 ( void )
{
static char V_712 [ 38 ] = L_143 ;
if ( V_712 [ 0 ] == 0 ) {
#ifdef F_311
sprintf ( V_712 , L_144 , V_61 -> V_713 ) ;
#else
V_712 [ 0 ] = 'b' ;
#endif
}
return V_712 ;
}
