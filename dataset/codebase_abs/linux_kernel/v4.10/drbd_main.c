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
void F_101 ( struct V_4 * V_5 , struct V_181 * V_83 , struct V_182 * V_183 )
{
if ( V_183 ) {
V_83 -> V_184 -> V_185 = F_64 ( F_102 ( V_183 ) ) ;
V_83 -> V_184 -> V_186 = F_64 ( F_103 ( V_183 ) ) ;
V_83 -> V_184 -> V_187 = F_64 ( F_104 ( V_183 ) ) ;
V_83 -> V_184 -> V_188 = F_64 ( F_105 ( V_183 ) ) ;
V_83 -> V_184 -> V_189 = F_64 ( F_106 ( V_183 ) ) ;
V_83 -> V_184 -> V_190 = F_107 ( V_183 ) ;
V_83 -> V_184 -> V_191 = F_108 ( V_183 ) ;
V_83 -> V_184 -> V_192 = ! ! V_183 -> V_193 . V_194 ;
} else {
V_183 = V_5 -> V_195 ;
V_83 -> V_184 -> V_185 = F_64 ( F_102 ( V_183 ) ) ;
V_83 -> V_184 -> V_186 = F_64 ( F_103 ( V_183 ) ) ;
V_83 -> V_184 -> V_187 = 0 ;
V_83 -> V_184 -> V_188 = F_64 ( F_105 ( V_183 ) ) ;
V_83 -> V_184 -> V_189 = F_64 ( F_106 ( V_183 ) ) ;
V_83 -> V_184 -> V_190 = 0 ;
V_83 -> V_184 -> V_191 = 0 ;
V_83 -> V_184 -> V_192 = 0 ;
}
}
int F_109 ( struct V_71 * V_72 , int V_196 , enum V_197 V_44 )
{
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_102 * V_103 ;
struct V_181 * V_83 ;
T_4 V_198 , V_199 ;
int V_200 ;
unsigned int V_201 ;
unsigned int V_202 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_202 = sizeof( * V_83 ) ;
if ( V_72 -> V_14 -> V_203 & V_204 )
V_202 += sizeof( V_83 -> V_184 [ 0 ] ) ;
memset ( V_83 , 0 , V_202 ) ;
if ( F_89 ( V_5 , V_159 ) ) {
struct V_182 * V_183 = F_110 ( V_5 -> V_128 -> V_205 ) ;
V_198 = F_111 ( V_5 -> V_128 ) ;
F_46 () ;
V_199 = F_83 ( V_5 -> V_128 -> V_120 ) -> V_206 ;
F_49 () ;
V_200 = F_112 ( V_5 ) ;
V_201 = F_113 ( V_183 ) << 9 ;
V_201 = V_82 ( V_201 , V_207 ) ;
F_101 ( V_5 , V_83 , V_183 ) ;
F_85 ( V_5 ) ;
} else {
V_198 = 0 ;
V_199 = 0 ;
V_200 = V_208 ;
V_201 = V_207 ;
F_101 ( V_5 , V_83 , NULL ) ;
}
if ( V_72 -> V_14 -> V_84 <= 94 )
V_201 = V_82 ( V_201 , V_101 ) ;
else if ( V_72 -> V_14 -> V_84 < 100 )
V_201 = V_82 ( V_201 , V_209 ) ;
V_83 -> V_198 = F_90 ( V_198 ) ;
V_83 -> V_199 = F_90 ( V_199 ) ;
V_83 -> V_210 = F_90 ( V_196 ? 0 : F_114 ( V_5 -> V_211 ) ) ;
V_83 -> V_201 = F_64 ( V_201 ) ;
V_83 -> V_212 = F_65 ( V_200 ) ;
V_83 -> V_197 = F_65 ( V_44 ) ;
return F_79 ( V_72 , V_103 , V_213 , V_202 , NULL , 0 ) ;
}
int F_115 ( struct V_71 * V_72 )
{
struct V_102 * V_103 ;
struct V_214 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_10 = F_64 ( V_72 -> V_5 -> V_10 . V_158 ) ;
return F_79 ( V_72 , V_103 , V_215 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_116 ( struct V_71 * V_72 , union V_216 V_10 )
{
struct V_102 * V_103 ;
struct V_214 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_10 = F_64 ( V_10 . V_158 ) ;
return F_79 ( V_72 , V_103 , V_215 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_117 ( struct V_71 * V_72 , union V_216 V_217 , union V_216 V_218 )
{
struct V_102 * V_103 ;
struct V_219 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_217 = F_64 ( V_217 . V_158 ) ;
V_83 -> V_218 = F_64 ( V_218 . V_158 ) ;
return F_79 ( V_72 , V_103 , V_220 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_118 ( struct V_13 * V_14 , union V_216 V_217 , union V_216 V_218 )
{
enum V_89 V_90 ;
struct V_102 * V_103 ;
struct V_219 * V_83 ;
V_90 = V_14 -> V_84 < 100 ? V_220 : V_221 ;
V_103 = & V_14 -> V_108 ;
V_83 = F_70 ( V_14 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_217 = F_64 ( V_217 . V_158 ) ;
V_83 -> V_218 = F_64 ( V_218 . V_158 ) ;
return F_78 ( V_14 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
void F_119 ( struct V_71 * V_72 , enum V_222 V_223 )
{
struct V_102 * V_103 ;
struct V_224 * V_83 ;
V_103 = & V_72 -> V_14 -> V_114 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( V_83 ) {
V_83 -> V_223 = F_64 ( V_223 ) ;
F_79 ( V_72 , V_103 , V_225 , sizeof( * V_83 ) , NULL , 0 ) ;
}
}
void F_120 ( struct V_13 * V_14 , enum V_222 V_223 )
{
struct V_102 * V_103 ;
struct V_224 * V_83 ;
enum V_89 V_90 = V_14 -> V_84 < 100 ? V_225 : V_226 ;
V_103 = & V_14 -> V_114 ;
V_83 = F_70 ( V_14 , V_103 ) ;
if ( V_83 ) {
V_83 -> V_223 = F_64 ( V_223 ) ;
F_78 ( V_14 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
}
static void F_121 ( struct V_227 * V_83 , enum V_228 V_229 )
{
F_122 ( V_229 & ~ 0xf ) ;
V_83 -> V_230 = ( V_83 -> V_230 & ~ 0xf ) | V_229 ;
}
static void F_123 ( struct V_227 * V_83 , int V_231 )
{
V_83 -> V_230 = ( V_83 -> V_230 & ~ 0x80 ) | ( V_231 ? 0x80 : 0 ) ;
}
static void F_124 ( struct V_227 * V_83 , int V_232 )
{
F_122 ( V_232 & ~ 0x7 ) ;
V_83 -> V_230 = ( V_83 -> V_230 & ( ~ 0x7 << 4 ) ) | ( V_232 << 4 ) ;
}
static int F_125 ( struct V_4 * V_5 ,
struct V_227 * V_83 ,
unsigned int V_91 ,
struct V_233 * V_234 )
{
struct V_235 V_236 ;
unsigned long V_237 ;
unsigned long V_238 ;
unsigned long V_239 ;
unsigned V_240 ;
unsigned V_241 ;
int V_242 , V_243 ;
F_46 () ;
V_243 = F_83 ( F_22 ( V_5 ) -> V_14 -> V_118 ) -> V_243 ;
F_49 () ;
if ( ! V_243 || F_22 ( V_5 ) -> V_14 -> V_84 < 90 )
return 0 ;
if ( V_234 -> V_244 >= V_234 -> V_245 )
return 0 ;
F_126 ( & V_236 , V_83 -> V_229 , V_91 , 0 ) ;
memset ( V_83 -> V_229 , 0 , V_91 ) ;
V_237 = 0 ;
V_241 = 2 ;
do {
V_238 = ( V_241 == 0 ) ? F_127 ( V_5 , V_234 -> V_244 )
: F_128 ( V_5 , V_234 -> V_244 ) ;
if ( V_238 == - 1UL )
V_238 = V_234 -> V_245 ;
V_239 = V_238 - V_234 -> V_244 ;
if ( V_241 == 2 ) {
if ( V_239 == 0 ) {
F_123 ( V_83 , 1 ) ;
V_241 = ! V_241 ;
continue;
}
F_123 ( V_83 , 0 ) ;
}
if ( V_239 == 0 ) {
F_11 ( V_5 , L_15
L_16 , V_241 , V_234 -> V_244 ) ;
return - 1 ;
}
V_242 = F_129 ( & V_236 , V_239 ) ;
if ( V_242 == - V_246 )
break;
if ( V_242 <= 0 ) {
F_11 ( V_5 , L_17 , V_242 ) ;
return 0 ;
}
V_241 = ! V_241 ;
V_237 += V_239 ;
V_234 -> V_244 = V_238 ;
} while ( V_234 -> V_244 < V_234 -> V_245 );
V_240 = V_236 . V_247 . V_248 - V_83 -> V_229 + ! ! V_236 . V_247 . V_249 ;
if ( V_237 < ( V_240 << 3 ) ) {
V_234 -> V_244 -= V_237 ;
F_130 ( V_234 ) ;
V_234 -> V_244 = V_234 -> V_250 * V_251 ;
return 0 ;
}
F_130 ( V_234 ) ;
F_124 ( V_83 , ( 8 - V_236 . V_247 . V_249 ) & 0x7 ) ;
return V_240 ;
}
static int
F_131 ( struct V_4 * V_5 , struct V_233 * V_234 )
{
struct V_102 * V_103 = & F_22 ( V_5 ) -> V_14 -> V_108 ;
unsigned int V_107 = F_60 ( F_22 ( V_5 ) -> V_14 ) ;
struct V_227 * V_83 = V_103 -> V_105 + V_107 ;
int V_240 , V_110 ;
V_240 = F_125 ( V_5 , V_83 ,
V_252 - V_107 - sizeof( * V_83 ) , V_234 ) ;
if ( V_240 < 0 )
return - V_115 ;
if ( V_240 ) {
F_121 ( V_83 , V_253 ) ;
V_110 = F_74 ( F_22 ( V_5 ) -> V_14 , V_5 -> V_73 , V_103 ,
V_254 , sizeof( * V_83 ) + V_240 ,
NULL , 0 ) ;
V_234 -> V_255 [ 0 ] ++ ;
V_234 -> V_256 [ 0 ] += V_107 + sizeof( * V_83 ) + V_240 ;
if ( V_234 -> V_244 >= V_234 -> V_245 )
V_240 = 0 ;
} else {
unsigned int V_257 ;
unsigned long V_258 ;
unsigned long * V_83 = V_103 -> V_105 + V_107 ;
V_257 = V_252 - V_107 ;
V_258 = F_132 ( V_259 , V_257 / sizeof( * V_83 ) ,
V_234 -> V_260 - V_234 -> V_250 ) ;
V_240 = V_258 * sizeof( * V_83 ) ;
if ( V_240 )
F_133 ( V_5 , V_234 -> V_250 , V_258 , V_83 ) ;
V_110 = F_74 ( F_22 ( V_5 ) -> V_14 , V_5 -> V_73 , V_103 , V_261 , V_240 , NULL , 0 ) ;
V_234 -> V_250 += V_258 ;
V_234 -> V_244 = V_234 -> V_250 * V_251 ;
V_234 -> V_255 [ 1 ] ++ ;
V_234 -> V_256 [ 1 ] += V_107 + V_240 ;
if ( V_234 -> V_244 > V_234 -> V_245 )
V_234 -> V_244 = V_234 -> V_245 ;
}
if ( ! V_110 ) {
if ( V_240 == 0 ) {
F_134 ( V_5 , L_18 , V_234 ) ;
return 0 ;
} else
return 1 ;
}
return - V_115 ;
}
static int F_135 ( struct V_4 * V_5 )
{
struct V_233 V_234 ;
int V_110 ;
if ( ! F_136 ( V_5 -> V_262 ) )
return false ;
if ( F_84 ( V_5 ) ) {
if ( F_137 ( V_5 -> V_128 , V_263 ) ) {
F_25 ( V_5 , L_19 ) ;
F_138 ( V_5 ) ;
if ( F_139 ( V_5 ) ) {
F_11 ( V_5 , L_20 ) ;
} else {
F_140 ( V_5 , V_263 ) ;
F_100 ( V_5 ) ;
}
}
F_85 ( V_5 ) ;
}
V_234 = (struct V_233 ) {
. V_245 = F_141 ( V_5 ) ,
. V_260 = F_142 ( V_5 ) ,
} ;
do {
V_110 = F_131 ( V_5 , & V_234 ) ;
} while ( V_110 > 0 );
return V_110 == 0 ;
}
int F_143 ( struct V_4 * V_5 )
{
struct V_102 * V_103 = & F_22 ( V_5 ) -> V_14 -> V_108 ;
int V_110 = - 1 ;
F_71 ( & V_103 -> V_106 ) ;
if ( V_103 -> V_104 )
V_110 = ! F_135 ( V_5 ) ;
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
void F_144 ( struct V_13 * V_14 , T_5 V_15 , T_5 V_16 )
{
struct V_102 * V_103 ;
struct V_264 * V_83 ;
if ( V_14 -> V_265 < V_266 )
return;
V_103 = & V_14 -> V_114 ;
V_83 = F_70 ( V_14 , V_103 ) ;
if ( ! V_83 )
return;
V_83 -> V_267 = V_15 ;
V_83 -> V_16 = F_64 ( V_16 ) ;
F_78 ( V_14 , V_103 , V_268 , sizeof( * V_83 ) , NULL , 0 ) ;
}
static int F_145 ( struct V_71 * V_72 , enum V_89 V_90 ,
T_3 V_269 , T_5 V_270 , T_3 V_271 )
{
struct V_102 * V_103 ;
struct V_272 * V_83 ;
if ( V_72 -> V_5 -> V_10 . V_32 < V_273 )
return - V_115 ;
V_103 = & V_72 -> V_14 -> V_114 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_269 = V_269 ;
V_83 -> V_271 = V_271 ;
V_83 -> V_270 = V_270 ;
V_83 -> V_274 = F_64 ( F_146 ( & V_72 -> V_5 -> V_275 ) ) ;
return F_79 ( V_72 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
void F_147 ( struct V_71 * V_72 , enum V_89 V_90 ,
struct V_276 * V_277 , int V_257 )
{
if ( V_72 -> V_14 -> V_278 )
V_257 -= F_148 ( V_72 -> V_14 -> V_278 ) ;
F_145 ( V_72 , V_90 , V_277 -> V_269 , F_64 ( V_257 ) ,
V_277 -> V_271 ) ;
}
void F_149 ( struct V_71 * V_72 , enum V_89 V_90 ,
struct V_279 * V_280 )
{
F_145 ( V_72 , V_90 , V_280 -> V_269 , V_280 -> V_270 , V_280 -> V_271 ) ;
}
int F_150 ( struct V_71 * V_72 , enum V_89 V_90 ,
struct V_281 * V_282 )
{
return F_145 ( V_72 , V_90 ,
F_90 ( V_282 -> V_158 . V_269 ) ,
F_64 ( V_282 -> V_158 . V_91 ) ,
V_282 -> V_271 ) ;
}
int F_151 ( struct V_71 * V_72 , enum V_89 V_90 ,
T_4 V_269 , int V_270 , T_3 V_271 )
{
return F_145 ( V_72 , V_90 ,
F_90 ( V_269 ) ,
F_64 ( V_270 ) ,
F_90 ( V_271 ) ) ;
}
int F_152 ( struct V_71 * V_72 ,
struct V_281 * V_282 )
{
struct V_102 * V_103 ;
struct V_283 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_269 = F_90 ( V_282 -> V_158 . V_269 ) ;
V_83 -> V_270 = F_64 ( V_282 -> V_158 . V_91 ) ;
V_83 -> V_99 = 0 ;
return F_79 ( V_72 , V_103 , V_284 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_153 ( struct V_71 * V_72 , int V_90 ,
T_4 V_269 , int V_91 , T_3 V_271 )
{
struct V_102 * V_103 ;
struct V_279 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_269 = F_90 ( V_269 ) ;
V_83 -> V_271 = V_271 ;
V_83 -> V_270 = F_64 ( V_91 ) ;
return F_79 ( V_72 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_154 ( struct V_71 * V_72 , T_4 V_269 , int V_91 ,
void * V_285 , int V_286 , enum V_89 V_90 )
{
struct V_102 * V_103 ;
struct V_279 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_269 = F_90 ( V_269 ) ;
V_83 -> V_271 = V_287 ;
V_83 -> V_270 = F_64 ( V_91 ) ;
return F_79 ( V_72 , V_103 , V_90 , sizeof( * V_83 ) , V_285 , V_286 ) ;
}
int F_155 ( struct V_71 * V_72 , T_4 V_269 , int V_91 )
{
struct V_102 * V_103 ;
struct V_279 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_269 = F_90 ( V_269 ) ;
V_83 -> V_271 = V_287 ;
V_83 -> V_270 = F_64 ( V_91 ) ;
return F_79 ( V_72 , V_103 , V_288 , sizeof( * V_83 ) , NULL , 0 ) ;
}
static int F_156 ( struct V_13 * V_14 , struct V_104 * V_103 )
{
int V_289 ;
V_289 = V_14 -> V_114 . V_104 == V_103
|| ! V_14 -> V_290 . V_55
|| F_157 ( & V_14 -> V_290 ) != V_54
|| V_14 -> V_265 < V_266 ;
if ( V_289 )
return true ;
V_289 = ! -- V_14 -> V_291 ;
if ( ! V_289 ) {
F_11 ( V_14 , L_21 ,
V_46 -> V_47 , V_46 -> V_64 , V_14 -> V_291 ) ;
F_158 ( V_14 ) ;
}
return V_289 ; ;
}
static void F_159 ( struct V_13 * V_14 )
{
struct V_103 * V_292 = V_14 -> V_108 . V_104 -> V_292 ;
if ( V_292 -> V_293 > V_292 -> V_294 * 4 / 5 )
F_160 ( V_295 , & V_14 -> V_44 ) ;
}
static int F_161 ( struct V_71 * V_72 , struct V_296 * V_296 ,
int V_297 , V_259 V_91 , unsigned V_109 )
{
struct V_104 * V_104 ;
void * V_298 ;
int V_110 ;
V_104 = V_72 -> V_14 -> V_108 . V_104 ;
V_298 = F_162 ( V_296 ) + V_297 ;
V_110 = F_75 ( V_72 -> V_14 , V_104 , V_298 , V_91 , V_109 ) ;
F_163 ( V_296 ) ;
if ( ! V_110 )
V_72 -> V_5 -> V_299 += V_91 >> 9 ;
return V_110 ;
}
static int F_164 ( struct V_71 * V_72 , struct V_296 * V_296 ,
int V_297 , V_259 V_91 , unsigned V_109 )
{
struct V_104 * V_104 = V_72 -> V_14 -> V_108 . V_104 ;
T_6 V_300 = F_165 () ;
int V_240 = V_91 ;
int V_110 = - V_115 ;
if ( V_301 || ( F_166 ( V_296 ) < 1 ) || F_167 ( V_296 ) )
return F_161 ( V_72 , V_296 , V_297 , V_91 , V_109 ) ;
V_109 |= V_302 ;
F_159 ( V_72 -> V_14 ) ;
F_168 ( V_303 ) ;
do {
int V_304 ;
V_304 = V_104 -> V_305 -> V_306 ( V_104 , V_296 , V_297 , V_240 , V_109 ) ;
if ( V_304 <= 0 ) {
if ( V_304 == - V_307 ) {
if ( F_156 ( V_72 -> V_14 , V_104 ) )
break;
continue;
}
F_169 ( V_72 -> V_5 , L_22 ,
V_308 , ( int ) V_91 , V_240 , V_304 ) ;
if ( V_304 < 0 )
V_110 = V_304 ;
break;
}
V_240 -= V_304 ;
V_297 += V_304 ;
} while ( V_240 > 0 );
F_168 ( V_300 ) ;
F_170 ( V_295 , & V_72 -> V_14 -> V_44 ) ;
if ( V_240 == 0 ) {
V_110 = 0 ;
V_72 -> V_5 -> V_299 += V_91 >> 9 ;
}
return V_110 ;
}
static int F_171 ( struct V_71 * V_72 , struct V_1 * V_1 )
{
struct V_309 V_310 ;
struct V_311 V_312 ;
F_172 (bvec, bio, iter) {
int V_110 ;
V_110 = F_161 ( V_72 , V_310 . V_313 ,
V_310 . V_314 , V_310 . V_315 ,
F_173 ( V_310 , V_312 )
? 0 : V_111 ) ;
if ( V_110 )
return V_110 ;
if ( F_174 ( V_1 ) == V_316 )
break;
}
return 0 ;
}
static int F_175 ( struct V_71 * V_72 , struct V_1 * V_1 )
{
struct V_309 V_310 ;
struct V_311 V_312 ;
F_172 (bvec, bio, iter) {
int V_110 ;
V_110 = F_164 ( V_72 , V_310 . V_313 ,
V_310 . V_314 , V_310 . V_315 ,
F_173 ( V_310 , V_312 ) ? 0 : V_111 ) ;
if ( V_110 )
return V_110 ;
if ( F_174 ( V_1 ) == V_316 )
break;
}
return 0 ;
}
static int F_176 ( struct V_71 * V_72 ,
struct V_281 * V_282 )
{
struct V_296 * V_296 = V_282 -> V_317 ;
unsigned V_240 = V_282 -> V_158 . V_91 ;
int V_110 ;
F_177 (page) {
unsigned V_318 = F_132 ( unsigned , V_240 , V_319 ) ;
V_110 = F_164 ( V_72 , V_296 , 0 , V_318 ,
F_178 ( V_296 ) ? V_111 : 0 ) ;
if ( V_110 )
return V_110 ;
V_240 -= V_318 ;
}
return 0 ;
}
static T_5 F_179 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
if ( V_14 -> V_84 >= 95 )
return ( V_1 -> V_320 & V_321 ? V_322 : 0 ) |
( V_1 -> V_320 & V_323 ? V_324 : 0 ) |
( V_1 -> V_320 & V_325 ? V_326 : 0 ) |
( F_174 ( V_1 ) == V_316 ? V_327 : 0 ) |
( F_174 ( V_1 ) == V_328 ? V_329 : 0 ) ;
else
return V_1 -> V_320 & V_321 ? V_322 : 0 ;
}
int F_180 ( struct V_71 * V_72 , struct V_17 * V_19 )
{
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_102 * V_103 ;
struct V_276 * V_83 ;
struct V_330 * V_331 = NULL ;
void * V_332 ;
unsigned int V_333 = 0 ;
int V_286 ;
int V_110 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
V_286 = V_72 -> V_14 -> V_334 ?
F_148 ( V_72 -> V_14 -> V_334 ) : 0 ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_269 = F_90 ( V_19 -> V_158 . V_269 ) ;
V_83 -> V_271 = ( unsigned long ) V_19 ;
V_83 -> V_274 = F_64 ( F_146 ( & V_5 -> V_275 ) ) ;
V_333 = F_179 ( V_72 -> V_14 , V_19 -> V_335 ) ;
if ( V_5 -> V_10 . V_32 >= V_336 &&
V_5 -> V_10 . V_32 <= V_337 )
V_333 |= V_338 ;
if ( V_72 -> V_14 -> V_84 >= 100 ) {
if ( V_19 -> V_25 & V_339 )
V_333 |= V_340 ;
if ( V_19 -> V_25 & V_341
|| ( V_333 & V_338 ) )
V_333 |= V_342 ;
}
V_83 -> V_333 = F_64 ( V_333 ) ;
if ( V_333 & V_329 ) {
struct V_343 * V_344 = (struct V_343 * ) V_83 ;
V_344 -> V_91 = F_64 ( V_19 -> V_158 . V_91 ) ;
V_110 = F_74 ( V_72 -> V_14 , V_5 -> V_73 , V_103 , V_345 , sizeof( * V_344 ) , NULL , 0 ) ;
goto V_346;
}
if ( V_333 & V_327 ) {
V_331 = (struct V_330 * ) V_83 ;
V_332 = V_331 + 1 ;
V_331 -> V_91 = F_64 ( V_19 -> V_158 . V_91 ) ;
} else
V_332 = V_83 + 1 ;
if ( V_286 )
F_181 ( V_72 -> V_14 -> V_334 , V_19 -> V_335 , V_332 ) ;
if ( V_331 ) {
V_110 =
F_74 ( V_72 -> V_14 , V_5 -> V_73 , V_103 , V_347 ,
sizeof( * V_331 ) + V_286 , NULL ,
F_182 ( V_19 -> V_335 ) . V_315 ) ;
} else
V_110 =
F_74 ( V_72 -> V_14 , V_5 -> V_73 , V_103 , V_348 ,
sizeof( * V_83 ) + V_286 , NULL , V_19 -> V_158 . V_91 ) ;
if ( ! V_110 ) {
if ( ! ( V_19 -> V_25 & ( V_339 | V_341 ) ) || V_286 )
V_110 = F_171 ( V_72 , V_19 -> V_335 ) ;
else
V_110 = F_175 ( V_72 , V_19 -> V_335 ) ;
if ( V_286 > 0 && V_286 <= 64 ) {
unsigned char V_285 [ 64 ] ;
F_181 ( V_72 -> V_14 -> V_334 , V_19 -> V_335 , V_285 ) ;
if ( memcmp ( V_83 + 1 , V_285 , V_286 ) ) {
F_169 ( V_5 ,
L_23 ,
( unsigned long long ) V_19 -> V_158 . V_269 , V_19 -> V_158 . V_91 ) ;
}
}
}
V_346:
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
int F_183 ( struct V_71 * V_72 , enum V_89 V_90 ,
struct V_281 * V_282 )
{
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_102 * V_103 ;
struct V_276 * V_83 ;
int V_110 ;
int V_286 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
V_286 = V_72 -> V_14 -> V_334 ?
F_148 ( V_72 -> V_14 -> V_334 ) : 0 ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_269 = F_90 ( V_282 -> V_158 . V_269 ) ;
V_83 -> V_271 = V_282 -> V_271 ;
V_83 -> V_274 = 0 ;
V_83 -> V_333 = 0 ;
if ( V_286 )
F_184 ( V_72 -> V_14 -> V_334 , V_282 , V_83 + 1 ) ;
V_110 = F_74 ( V_72 -> V_14 , V_5 -> V_73 , V_103 , V_90 , sizeof( * V_83 ) + V_286 , NULL , V_282 -> V_158 . V_91 ) ;
if ( ! V_110 )
V_110 = F_176 ( V_72 , V_282 ) ;
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
int F_185 ( struct V_71 * V_72 , struct V_17 * V_19 )
{
struct V_102 * V_103 ;
struct V_283 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_269 = F_90 ( V_19 -> V_158 . V_269 ) ;
V_83 -> V_270 = F_64 ( V_19 -> V_158 . V_91 ) ;
return F_79 ( V_72 , V_103 , V_349 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_186 ( struct V_13 * V_14 , struct V_104 * V_103 ,
void * V_350 , V_259 V_91 , unsigned V_109 )
{
struct V_351 V_352 ;
struct V_353 V_354 ;
int V_355 , V_304 = 0 ;
if ( ! V_103 )
return - V_356 ;
V_352 . V_357 = V_350 ;
V_352 . V_358 = V_91 ;
V_354 . V_359 = NULL ;
V_354 . V_360 = 0 ;
V_354 . V_361 = NULL ;
V_354 . V_362 = 0 ;
V_354 . V_109 = V_109 | V_302 ;
if ( V_103 == V_14 -> V_108 . V_104 ) {
F_46 () ;
V_14 -> V_291 = F_83 ( V_14 -> V_118 ) -> V_291 ;
F_49 () ;
F_159 ( V_14 ) ;
}
do {
V_355 = F_187 ( V_103 , & V_354 , & V_352 , 1 , V_352 . V_358 ) ;
if ( V_355 == - V_307 ) {
if ( F_156 ( V_14 , V_103 ) )
break;
else
continue;
}
if ( V_355 == - V_363 ) {
F_38 ( V_46 ) ;
V_355 = 0 ;
}
if ( V_355 < 0 )
break;
V_304 += V_355 ;
V_352 . V_357 += V_355 ;
V_352 . V_358 -= V_355 ;
} while ( V_304 < V_91 );
if ( V_103 == V_14 -> V_108 . V_104 )
F_170 ( V_295 , & V_14 -> V_44 ) ;
if ( V_355 <= 0 ) {
if ( V_355 != - V_307 ) {
F_11 ( V_14 , L_24 ,
V_103 == V_14 -> V_114 . V_104 ? L_25 : L_26 ,
V_355 ) ;
F_15 ( V_14 , F_16 ( V_32 , V_364 ) , V_34 ) ;
} else
F_15 ( V_14 , F_16 ( V_32 , V_365 ) , V_34 ) ;
}
return V_304 ;
}
int F_75 ( struct V_13 * V_14 , struct V_104 * V_103 , void * V_100 ,
V_259 V_91 , unsigned V_109 )
{
int V_110 ;
V_110 = F_186 ( V_14 , V_103 , V_100 , V_91 , V_109 ) ;
if ( V_110 < 0 )
return V_110 ;
if ( V_110 != V_91 )
return - V_115 ;
return 0 ;
}
static int F_188 ( struct V_366 * V_367 , T_7 V_368 )
{
struct V_4 * V_5 = V_367 -> V_369 -> V_370 ;
unsigned long V_44 ;
int V_355 = 0 ;
F_71 ( & V_371 ) ;
F_24 ( & V_5 -> V_22 -> V_23 , V_44 ) ;
if ( V_5 -> V_10 . V_372 != V_373 ) {
if ( V_368 & V_374 )
V_355 = - V_375 ;
else if ( ! V_376 )
V_355 = - V_377 ;
}
if ( ! V_355 )
V_5 -> V_378 ++ ;
F_26 ( & V_5 -> V_22 -> V_23 , V_44 ) ;
F_72 ( & V_371 ) ;
return V_355 ;
}
static void F_189 ( struct V_379 * V_380 , T_7 V_368 )
{
struct V_4 * V_5 = V_380 -> V_370 ;
F_71 ( & V_371 ) ;
V_5 -> V_378 -- ;
F_72 ( & V_371 ) ;
}
static void F_190 ( struct V_4 * V_5 )
{
V_5 -> V_10 = (union V_381 ) {
{ . V_372 = V_382 ,
. V_383 = V_384 ,
. V_32 = V_385 ,
. V_11 = V_386 ,
. V_387 = V_388 ,
} } ;
}
void F_191 ( struct V_4 * V_5 )
{
F_190 ( V_5 ) ;
F_192 ( & V_5 -> V_389 , 0 ) ;
F_192 ( & V_5 -> V_390 , 0 ) ;
F_192 ( & V_5 -> V_391 , 0 ) ;
F_192 ( & V_5 -> V_392 , 0 ) ;
F_192 ( & V_5 -> V_393 , 0 ) ;
F_192 ( & V_5 -> V_9 , 0 ) ;
F_192 ( & V_5 -> V_394 , 0 ) ;
F_192 ( & V_5 -> V_395 , 0 ) ;
F_192 ( & V_5 -> V_396 , 0 ) ;
F_192 ( & V_5 -> V_397 , 0 ) ;
F_192 ( & V_5 -> V_398 . V_399 , 0 ) ;
F_193 ( & V_5 -> V_400 ) ;
V_5 -> V_401 = & V_5 -> V_400 ;
F_33 ( & V_5 -> V_402 ) ;
F_33 ( & V_5 -> V_403 ) ;
F_194 ( & V_5 -> V_404 ) ;
F_194 ( & V_5 -> V_405 ) ;
F_194 ( & V_5 -> V_406 ) ;
F_194 ( & V_5 -> V_407 ) ;
F_194 ( & V_5 -> V_408 ) ;
F_194 ( & V_5 -> V_409 ) ;
F_194 ( & V_5 -> V_410 . V_411 ) ;
F_194 ( & V_5 -> V_412 . V_411 ) ;
F_194 ( & V_5 -> V_413 . V_414 . V_411 ) ;
F_194 ( & V_5 -> V_415 [ 0 ] ) ;
F_194 ( & V_5 -> V_415 [ 1 ] ) ;
F_194 ( & V_5 -> V_416 [ 0 ] ) ;
F_194 ( & V_5 -> V_416 [ 1 ] ) ;
V_5 -> V_410 . V_417 = V_418 ;
V_5 -> V_412 . V_417 = V_419 ;
V_5 -> V_413 . V_414 . V_417 = V_420 ;
F_195 ( & V_5 -> V_421 ) ;
F_195 ( & V_5 -> V_422 ) ;
F_195 ( & V_5 -> V_423 ) ;
F_195 ( & V_5 -> V_424 ) ;
V_5 -> V_421 . V_50 = V_425 ;
V_5 -> V_421 . V_108 = ( unsigned long ) V_5 ;
V_5 -> V_422 . V_50 = V_426 ;
V_5 -> V_422 . V_108 = ( unsigned long ) V_5 ;
V_5 -> V_423 . V_50 = V_427 ;
V_5 -> V_423 . V_108 = ( unsigned long ) V_5 ;
V_5 -> V_424 . V_50 = V_428 ;
V_5 -> V_424 . V_108 = ( unsigned long ) V_5 ;
F_196 ( & V_5 -> V_12 ) ;
F_196 ( & V_5 -> V_429 ) ;
F_196 ( & V_5 -> V_430 ) ;
F_196 ( & V_5 -> V_431 ) ;
F_196 ( & V_5 -> V_432 ) ;
V_5 -> V_433 = V_434 ;
V_5 -> V_435 = V_436 ;
V_5 -> V_437 = V_436 ;
}
void F_197 ( struct V_4 * V_5 )
{
int V_158 ;
if ( F_22 ( V_5 ) -> V_14 -> V_438 . V_52 != V_56 )
F_11 ( V_5 , L_27 ,
F_22 ( V_5 ) -> V_14 -> V_438 . V_52 ) ;
V_5 -> V_439 =
V_5 -> V_440 =
V_5 -> V_441 =
V_5 -> V_442 =
V_5 -> V_299 =
V_5 -> V_443 =
V_5 -> V_444 =
V_5 -> V_445 =
V_5 -> V_446 =
V_5 -> V_447 = 0 ;
V_5 -> V_448 = 0 ;
V_5 -> V_449 = 0 ;
for ( V_158 = 0 ; V_158 < V_450 ; V_158 ++ ) {
V_5 -> V_451 [ V_158 ] = 0 ;
V_5 -> V_452 [ V_158 ] = 0 ;
}
F_97 ( V_5 , F_22 ( V_5 ) -> V_14 -> V_118 == NULL ) ;
F_198 ( V_5 , 0 ) ;
if ( V_5 -> V_262 ) {
F_199 ( V_5 , 0 , 1 ) ;
F_200 ( V_5 ) ;
}
F_201 ( V_5 , V_5 -> V_128 ) ;
V_5 -> V_128 = NULL ;
F_170 ( V_453 , & V_5 -> V_44 ) ;
F_97 ( V_5 , F_202 ( & V_5 -> V_404 ) ) ;
F_97 ( V_5 , F_202 ( & V_5 -> V_405 ) ) ;
F_97 ( V_5 , F_202 ( & V_5 -> V_406 ) ) ;
F_97 ( V_5 , F_202 ( & V_5 -> V_407 ) ) ;
F_97 ( V_5 , F_202 ( & V_5 -> V_408 ) ) ;
F_97 ( V_5 , F_202 ( & V_5 -> V_409 ) ) ;
F_97 ( V_5 , F_202 ( & F_22 ( V_5 ) -> V_14 -> V_454 . V_183 ) ) ;
F_97 ( V_5 , F_202 ( & V_5 -> V_410 . V_411 ) ) ;
F_97 ( V_5 , F_202 ( & V_5 -> V_412 . V_411 ) ) ;
F_190 ( V_5 ) ;
}
static void F_203 ( void )
{
struct V_296 * V_296 ;
while ( V_455 ) {
V_296 = V_455 ;
V_455 = (struct V_296 * ) F_204 ( V_296 ) ;
F_205 ( V_296 ) ;
V_456 -- ;
}
if ( V_3 )
F_206 ( V_3 ) ;
if ( V_457 )
F_207 ( V_457 ) ;
if ( V_458 )
F_207 ( V_458 ) ;
if ( V_459 )
F_207 ( V_459 ) ;
if ( V_460 )
F_208 ( V_460 ) ;
if ( V_461 )
F_208 ( V_461 ) ;
if ( V_462 )
F_208 ( V_462 ) ;
if ( V_463 )
F_208 ( V_463 ) ;
V_3 = NULL ;
V_457 = NULL ;
V_458 = NULL ;
V_459 = NULL ;
V_460 = NULL ;
V_461 = NULL ;
V_462 = NULL ;
V_463 = NULL ;
return;
}
static int F_209 ( void )
{
struct V_296 * V_296 ;
const int V_464 = ( V_207 / V_319 ) * V_465 ;
int V_158 ;
V_459 = NULL ;
V_460 = NULL ;
V_461 = NULL ;
V_462 = NULL ;
V_463 = NULL ;
V_455 = NULL ;
V_457 = NULL ;
V_3 = NULL ;
V_461 = F_210 (
L_28 , sizeof( struct V_17 ) , 0 , 0 , NULL ) ;
if ( V_461 == NULL )
goto V_466;
V_460 = F_210 (
L_29 , sizeof( struct V_281 ) , 0 , 0 , NULL ) ;
if ( V_460 == NULL )
goto V_466;
V_462 = F_210 (
L_30 , sizeof( struct V_467 ) , 0 , 0 , NULL ) ;
if ( V_462 == NULL )
goto V_466;
V_463 = F_210 (
L_31 , sizeof( struct V_468 ) , 0 , 0 , NULL ) ;
if ( V_463 == NULL )
goto V_466;
V_3 = F_211 ( V_469 , 0 ) ;
if ( V_3 == NULL )
goto V_466;
V_457 = F_212 ( V_469 , 0 ) ;
if ( V_457 == NULL )
goto V_466;
V_459 = F_213 ( V_464 ,
V_461 ) ;
if ( V_459 == NULL )
goto V_466;
V_458 = F_213 ( V_464 , V_460 ) ;
if ( V_458 == NULL )
goto V_466;
F_33 ( & V_470 ) ;
for ( V_158 = 0 ; V_158 < V_464 ; V_158 ++ ) {
V_296 = F_214 ( V_471 ) ;
if ( ! V_296 )
goto V_466;
F_215 ( V_296 , ( unsigned long ) V_455 ) ;
V_455 = V_296 ;
}
V_456 = V_464 ;
return 0 ;
V_466:
F_203 () ;
return - V_472 ;
}
static void F_216 ( struct V_4 * V_5 )
{
int V_473 ;
V_473 = F_217 ( V_5 , & V_5 -> V_404 ) ;
if ( V_473 )
F_11 ( V_5 , L_32 , V_473 ) ;
V_473 = F_217 ( V_5 , & V_5 -> V_405 ) ;
if ( V_473 )
F_11 ( V_5 , L_33 , V_473 ) ;
V_473 = F_217 ( V_5 , & V_5 -> V_407 ) ;
if ( V_473 )
F_11 ( V_5 , L_34 , V_473 ) ;
V_473 = F_217 ( V_5 , & V_5 -> V_406 ) ;
if ( V_473 )
F_11 ( V_5 , L_35 , V_473 ) ;
V_473 = F_217 ( V_5 , & V_5 -> V_408 ) ;
if ( V_473 )
F_11 ( V_5 , L_36 , V_473 ) ;
}
void F_218 ( struct V_58 * V_58 )
{
struct V_4 * V_5 = F_219 ( V_58 , struct V_4 , V_58 ) ;
struct V_43 * V_22 = V_5 -> V_22 ;
struct V_71 * V_72 , * V_474 ;
F_220 ( & V_5 -> V_424 ) ;
F_97 ( V_5 , V_5 -> V_378 == 0 ) ;
if ( V_5 -> V_211 )
F_221 ( V_5 -> V_211 ) ;
F_201 ( V_5 , V_5 -> V_128 ) ;
V_5 -> V_128 = NULL ;
F_216 ( V_5 ) ;
F_222 ( V_5 -> V_475 ) ;
F_222 ( V_5 -> V_476 ) ;
F_55 ( V_5 -> V_477 ) ;
if ( V_5 -> V_262 )
F_200 ( V_5 ) ;
F_205 ( V_5 -> V_398 . V_296 ) ;
F_223 ( V_5 -> V_478 ) ;
F_224 ( V_5 -> V_195 ) ;
F_55 ( V_5 -> V_479 ) ;
F_225 (peer_device, tmp_peer_device, device) {
F_29 ( & V_72 -> V_14 -> V_58 , V_59 ) ;
F_55 ( V_72 ) ;
}
memset ( V_5 , 0xfd , sizeof( * V_5 ) ) ;
F_55 ( V_5 ) ;
F_29 ( & V_22 -> V_58 , V_60 ) ;
}
static void F_226 ( struct V_480 * V_481 )
{
struct V_482 * V_483 = F_219 ( V_481 , struct V_482 , V_484 ) ;
F_227 ( V_485 ) ;
struct V_17 * V_19 , * V_238 ;
F_9 ( & V_483 -> V_486 ) ;
F_228 ( & V_483 -> V_485 , & V_485 ) ;
F_14 ( & V_483 -> V_486 ) ;
F_18 (req, tmp, &writes, tl_requests) {
struct V_4 * V_5 = V_19 -> V_5 ;
struct V_1 * V_1 = V_19 -> V_335 ;
unsigned long V_487 = V_19 -> V_487 ;
bool V_488 ;
V_488 =
F_136 ( F_229 ( & V_19 -> V_489 ) == 0 ) &&
F_136 ( V_19 -> V_25 & V_490 ) &&
F_136 ( ( V_19 -> V_25 & V_38 ) == 0 ||
( V_19 -> V_25 & V_491 ) != 0 ) ;
if ( ! V_488 )
F_11 ( V_5 , L_37 ,
V_19 , F_229 ( & V_19 -> V_489 ) ,
V_19 -> V_25 ) ;
F_29 ( & V_19 -> V_58 , V_492 ) ;
F_230 ( V_5 ) ;
F_231 ( V_5 , V_1 , V_487 ) ;
}
}
void F_232 ( struct V_17 * V_19 )
{
unsigned long V_44 ;
F_24 ( & V_483 . V_486 , V_44 ) ;
F_233 ( & V_19 -> V_493 , & V_483 . V_485 ) ;
F_26 ( & V_483 . V_486 , V_44 ) ;
F_234 ( V_19 -> V_5 ) ;
F_235 ( V_483 . V_494 , & V_483 . V_484 ) ;
}
void V_60 ( struct V_58 * V_58 )
{
struct V_43 * V_22 =
F_219 ( V_58 , struct V_43 , V_58 ) ;
F_236 ( & V_22 -> V_495 ) ;
F_237 ( V_22 -> V_76 ) ;
F_55 ( V_22 -> V_48 ) ;
memset ( V_22 , 0xf2 , sizeof( * V_22 ) ) ;
F_55 ( V_22 ) ;
}
void F_238 ( struct V_43 * V_22 )
{
struct V_13 * V_14 , * V_238 ;
F_239 (connection, tmp, resource) {
F_240 ( & V_14 -> V_496 ) ;
F_241 ( V_14 ) ;
F_29 ( & V_14 -> V_58 , V_59 ) ;
}
F_242 ( V_22 ) ;
F_29 ( & V_22 -> V_58 , V_60 ) ;
}
static void F_243 ( void )
{
unsigned int V_158 ;
struct V_4 * V_5 ;
struct V_43 * V_22 , * V_238 ;
if ( V_497 )
F_244 ( L_38 , NULL ) ;
if ( V_483 . V_494 )
F_245 ( V_483 . V_494 ) ;
F_246 () ;
F_247 () ;
F_248 (&drbd_devices, device, i)
F_249 ( V_5 ) ;
F_250 (resource, tmp, &drbd_resources) {
F_240 ( & V_22 -> V_498 ) ;
F_238 ( V_22 ) ;
}
F_203 () ;
F_251 ( V_499 , L_38 ) ;
F_236 ( & V_500 ) ;
F_252 ( L_39 ) ;
}
static int F_253 ( void * V_501 , int V_502 )
{
struct V_4 * V_5 = V_501 ;
struct V_182 * V_183 ;
char V_503 = '-' ;
int V_18 = 0 ;
if ( ! F_254 ( V_5 ) ) {
V_18 = V_502 ;
V_503 = 'd' ;
goto V_346;
}
if ( F_92 ( V_504 , & F_22 ( V_5 ) -> V_14 -> V_44 ) ) {
V_18 |= ( 1 << V_505 ) ;
if ( ! F_89 ( V_5 , V_177 ) )
V_18 |= ( 1 << V_506 ) ;
else
F_85 ( V_5 ) ;
V_18 &= V_502 ;
V_503 = 'c' ;
goto V_346;
}
if ( F_84 ( V_5 ) ) {
V_183 = F_110 ( V_5 -> V_128 -> V_205 ) ;
V_18 = F_255 ( & V_183 -> V_507 , V_502 ) ;
F_85 ( V_5 ) ;
if ( V_18 )
V_503 = 'b' ;
}
if ( V_502 & ( 1 << V_505 ) &&
F_92 ( V_295 , & F_22 ( V_5 ) -> V_14 -> V_44 ) ) {
V_18 |= ( 1 << V_505 ) ;
V_503 = V_503 == 'b' ? 'a' : 'n' ;
}
V_346:
V_5 -> V_508 = V_503 ;
return V_18 ;
}
static void F_256 ( struct V_509 * V_494 )
{
F_33 ( & V_494 -> V_510 ) ;
F_194 ( & V_494 -> V_183 ) ;
F_196 ( & V_494 -> V_511 ) ;
}
static int F_257 ( struct V_512 * V_414 , int V_513 )
{
struct V_514 * V_514 =
F_219 ( V_414 , struct V_514 , V_414 ) ;
F_258 ( & V_514 -> V_515 ) ;
return 0 ;
}
void F_259 ( struct V_509 * V_516 )
{
struct V_514 V_514 ;
V_514 . V_414 . V_417 = F_257 ;
F_37 ( & V_514 . V_515 ) ;
F_260 ( V_516 , & V_514 . V_414 ) ;
F_44 ( & V_514 . V_515 ) ;
}
struct V_43 * F_261 ( const char * V_48 )
{
struct V_43 * V_22 ;
if ( ! V_48 || ! V_48 [ 0 ] )
return NULL ;
F_46 () ;
F_52 (resource, &drbd_resources) {
if ( ! strcmp ( V_22 -> V_48 , V_48 ) ) {
F_36 ( & V_22 -> V_58 ) ;
goto V_517;
}
}
V_22 = NULL ;
V_517:
F_49 () ;
return V_22 ;
}
struct V_13 * F_262 ( void * V_518 , int V_519 ,
void * V_520 , int V_521 )
{
struct V_43 * V_22 ;
struct V_13 * V_14 ;
F_46 () ;
F_52 (resource, &drbd_resources) {
F_263 (connection, resource) {
if ( V_14 -> V_519 == V_519 &&
V_14 -> V_521 == V_521 &&
! memcmp ( & V_14 -> V_518 , V_518 , V_519 ) &&
! memcmp ( & V_14 -> V_520 , V_520 , V_521 ) ) {
F_36 ( & V_14 -> V_58 ) ;
goto V_517;
}
}
}
V_14 = NULL ;
V_517:
F_49 () ;
return V_14 ;
}
static int F_264 ( struct V_102 * V_104 )
{
V_104 -> V_522 = ( void * ) F_265 ( V_80 ) ;
if ( ! V_104 -> V_522 )
return - V_472 ;
V_104 -> V_105 = ( void * ) F_265 ( V_80 ) ;
if ( ! V_104 -> V_105 )
return - V_472 ;
return 0 ;
}
static void F_266 ( struct V_102 * V_104 )
{
F_267 ( ( unsigned long ) V_104 -> V_105 ) ;
F_267 ( ( unsigned long ) V_104 -> V_522 ) ;
}
void F_268 ( struct V_13 * V_14 )
{
F_269 ( V_14 ) ;
F_270 ( V_14 -> V_523 ) ;
F_270 ( V_14 -> V_524 ) ;
F_271 ( V_14 -> V_525 ) ;
F_270 ( V_14 -> V_334 ) ;
F_270 ( V_14 -> V_278 ) ;
F_55 ( V_14 -> V_526 ) ;
F_55 ( V_14 -> V_527 ) ;
V_14 -> V_523 = NULL ;
V_14 -> V_524 = NULL ;
V_14 -> V_525 = NULL ;
V_14 -> V_334 = NULL ;
V_14 -> V_278 = NULL ;
V_14 -> V_526 = NULL ;
V_14 -> V_527 = NULL ;
}
int F_272 ( struct V_43 * V_22 , struct V_528 * V_528 )
{
struct V_13 * V_14 ;
T_2 V_529 ;
int V_110 ;
if ( ! F_273 ( & V_529 , V_80 ) )
return - V_472 ;
if ( V_79 > 1 && V_528 -> V_76 [ 0 ] != 0 ) {
V_110 = F_274 ( V_528 -> V_76 , V_530 ,
F_275 ( V_529 ) , V_79 ) ;
if ( V_110 == - V_531 ) {
T_2 V_532 ;
if ( F_273 ( & V_532 , V_80 ) ) {
F_56 ( V_532 ) ;
F_276 ( V_529 , V_529 , V_532 ) ;
F_169 ( V_22 , L_40 ,
V_528 -> V_76 ,
strlen ( V_528 -> V_76 ) > 12 ? L_41 : L_42 ,
V_79 ) ;
F_237 ( V_532 ) ;
V_110 = 0 ;
}
}
if ( V_110 ) {
F_169 ( V_22 , L_43 , V_110 ) ;
goto V_533;
}
}
V_22 -> V_528 = * V_528 ;
if ( F_277 ( V_529 ) )
F_50 ( & V_529 ) ;
if ( ! F_278 ( V_22 -> V_76 , V_529 ) ) {
F_279 ( V_22 -> V_76 , V_529 ) ;
F_263 (connection, resource) {
V_14 -> V_438 . V_65 = 1 ;
V_14 -> V_290 . V_65 = 1 ;
V_14 -> V_484 . V_65 = 1 ;
}
}
V_110 = 0 ;
V_533:
F_237 ( V_529 ) ;
return V_110 ;
}
struct V_43 * F_280 ( const char * V_48 )
{
struct V_43 * V_22 ;
V_22 = F_51 ( sizeof( struct V_43 ) , V_80 ) ;
if ( ! V_22 )
goto V_533;
V_22 -> V_48 = F_281 ( V_48 , V_80 ) ;
if ( ! V_22 -> V_48 )
goto V_534;
if ( ! F_273 ( & V_22 -> V_76 , V_80 ) )
goto V_535;
F_282 ( & V_22 -> V_58 ) ;
F_283 ( & V_22 -> V_495 ) ;
F_194 ( & V_22 -> V_496 ) ;
V_22 -> V_536 = V_537 ;
F_284 ( & V_22 -> V_498 , & V_538 ) ;
F_193 ( & V_22 -> V_539 ) ;
F_193 ( & V_22 -> V_540 ) ;
F_33 ( & V_22 -> V_23 ) ;
F_285 ( V_22 ) ;
return V_22 ;
V_535:
F_55 ( V_22 -> V_48 ) ;
V_534:
F_55 ( V_22 ) ;
V_533:
return NULL ;
}
struct V_13 * F_286 ( const char * V_48 , struct V_528 * V_528 )
{
struct V_43 * V_22 ;
struct V_13 * V_14 ;
V_14 = F_51 ( sizeof( struct V_13 ) , V_80 ) ;
if ( ! V_14 )
return NULL ;
if ( F_264 ( & V_14 -> V_108 ) )
goto V_533;
if ( F_264 ( & V_14 -> V_114 ) )
goto V_533;
V_14 -> V_541 = F_51 ( sizeof( struct V_542 ) , V_80 ) ;
if ( ! V_14 -> V_541 )
goto V_533;
F_194 ( & V_14 -> V_543 ) ;
F_194 ( & V_14 -> V_541 -> V_411 ) ;
V_14 -> V_544 = 1 ;
F_33 ( & V_14 -> V_545 ) ;
V_14 -> V_546 . V_547 = false ;
V_14 -> V_546 . V_548 = 0 ;
V_14 -> V_546 . V_549 = 0 ;
V_22 = F_280 ( V_48 ) ;
if ( ! V_22 )
goto V_533;
V_14 -> V_265 = V_385 ;
F_193 ( & V_14 -> V_550 ) ;
F_196 ( & V_14 -> V_551 ) ;
F_283 ( & V_14 -> V_75 ) ;
F_256 ( & V_14 -> V_454 ) ;
F_193 ( & V_14 -> V_108 . V_106 ) ;
F_193 ( & V_14 -> V_114 . V_106 ) ;
F_31 ( V_22 , & V_14 -> V_438 , V_552 , L_44 ) ;
V_14 -> V_438 . V_14 = V_14 ;
F_31 ( V_22 , & V_14 -> V_484 , V_553 , L_45 ) ;
V_14 -> V_484 . V_14 = V_14 ;
F_31 ( V_22 , & V_14 -> V_290 , V_554 , L_46 ) ;
V_14 -> V_290 . V_14 = V_14 ;
F_282 ( & V_14 -> V_58 ) ;
V_14 -> V_22 = V_22 ;
if ( F_272 ( V_22 , V_528 ) )
goto V_555;
F_36 ( & V_22 -> V_58 ) ;
F_284 ( & V_14 -> V_496 , & V_22 -> V_496 ) ;
F_287 ( V_14 ) ;
return V_14 ;
V_555:
F_240 ( & V_22 -> V_498 ) ;
F_238 ( V_22 ) ;
V_533:
F_55 ( V_14 -> V_541 ) ;
F_266 ( & V_14 -> V_114 ) ;
F_266 ( & V_14 -> V_108 ) ;
F_55 ( V_14 ) ;
return NULL ;
}
void V_59 ( struct V_58 * V_58 )
{
struct V_13 * V_14 = F_219 ( V_58 , struct V_13 , V_58 ) ;
struct V_43 * V_22 = V_14 -> V_22 ;
if ( F_229 ( & V_14 -> V_541 -> V_556 ) != 0 )
F_11 ( V_14 , L_47 , F_229 ( & V_14 -> V_541 -> V_556 ) ) ;
F_55 ( V_14 -> V_541 ) ;
F_236 ( & V_14 -> V_75 ) ;
F_266 ( & V_14 -> V_114 ) ;
F_266 ( & V_14 -> V_108 ) ;
F_55 ( V_14 -> V_526 ) ;
F_55 ( V_14 -> V_527 ) ;
memset ( V_14 , 0xfc , sizeof( * V_14 ) ) ;
F_55 ( V_14 ) ;
F_29 ( & V_22 -> V_58 , V_60 ) ;
}
static int F_288 ( struct V_4 * V_5 )
{
V_5 -> V_557 . V_494 =
F_289 ( L_48 , V_558 , V_5 -> V_74 ) ;
if ( ! V_5 -> V_557 . V_494 )
return - V_472 ;
F_290 ( & V_5 -> V_557 . V_484 , V_559 ) ;
F_194 ( & V_5 -> V_557 . V_485 ) ;
return 0 ;
}
enum V_560 F_291 ( struct V_561 * V_562 , unsigned int V_74 )
{
struct V_43 * V_22 = V_562 -> V_22 ;
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_71 * V_72 , * V_474 ;
struct V_379 * V_11 ;
struct V_182 * V_183 ;
int V_563 ;
int V_73 = V_562 -> V_98 ;
enum V_560 V_110 = V_564 ;
V_5 = F_292 ( V_74 ) ;
if ( V_5 )
return V_565 ;
V_5 = F_51 ( sizeof( struct V_4 ) , V_80 ) ;
if ( ! V_5 )
return V_564 ;
F_282 ( & V_5 -> V_58 ) ;
F_36 ( & V_22 -> V_58 ) ;
V_5 -> V_22 = V_22 ;
V_5 -> V_74 = V_74 ;
V_5 -> V_73 = V_73 ;
F_191 ( V_5 ) ;
V_183 = F_293 ( V_80 ) ;
if ( ! V_183 )
goto V_566;
V_5 -> V_195 = V_183 ;
V_183 -> V_567 = V_5 ;
V_11 = F_294 ( 1 ) ;
if ( ! V_11 )
goto V_568;
V_5 -> V_478 = V_11 ;
F_295 ( V_11 , true ) ;
V_11 -> V_569 = V_183 ;
V_11 -> V_570 = V_499 ;
V_11 -> V_571 = V_74 ;
V_11 -> V_572 = & V_573 ;
sprintf ( V_11 -> V_574 , L_49 , V_74 ) ;
V_11 -> V_370 = V_5 ;
V_5 -> V_211 = F_296 ( F_297 ( V_499 , V_74 ) ) ;
V_5 -> V_211 -> V_575 = V_5 -> V_211 ;
V_183 -> V_507 . V_576 = F_253 ;
V_183 -> V_507 . V_501 = V_5 ;
F_298 ( V_183 , V_577 ) ;
F_299 ( V_183 , true , true ) ;
F_300 ( V_183 , V_436 >> 8 ) ;
F_301 ( V_183 , V_578 ) ;
V_183 -> V_579 = & V_22 -> V_23 ;
V_5 -> V_398 . V_296 = F_214 ( V_80 ) ;
if ( ! V_5 -> V_398 . V_296 )
goto V_580;
if ( F_302 ( V_5 ) )
goto V_581;
V_5 -> V_582 = V_583 ;
V_5 -> V_584 = V_583 ;
V_563 = F_303 ( & V_500 , V_5 , V_74 , V_74 + 1 , V_80 ) ;
if ( V_563 < 0 ) {
if ( V_563 == - V_585 )
V_110 = V_565 ;
goto V_586;
}
F_36 ( & V_5 -> V_58 ) ;
V_563 = F_303 ( & V_22 -> V_495 , V_5 , V_73 , V_73 + 1 , V_80 ) ;
if ( V_563 < 0 ) {
if ( V_563 == - V_585 )
V_110 = V_565 ;
goto V_587;
}
F_36 ( & V_5 -> V_58 ) ;
F_194 ( & V_5 -> V_75 ) ;
F_194 ( & V_5 -> V_588 ) ;
F_304 (connection, resource) {
V_72 = F_51 ( sizeof( struct V_71 ) , V_80 ) ;
if ( ! V_72 )
goto V_589;
V_72 -> V_14 = V_14 ;
V_72 -> V_5 = V_5 ;
F_305 ( & V_72 -> V_75 , & V_5 -> V_75 ) ;
F_36 ( & V_5 -> V_58 ) ;
V_563 = F_303 ( & V_14 -> V_75 , V_72 , V_73 , V_73 + 1 , V_80 ) ;
if ( V_563 < 0 ) {
if ( V_563 == - V_585 )
V_110 = V_590 ;
goto V_589;
}
F_36 ( & V_14 -> V_58 ) ;
F_290 ( & V_72 -> V_591 , V_592 ) ;
}
if ( F_288 ( V_5 ) ) {
V_110 = V_564 ;
goto V_593;
}
F_306 ( V_11 ) ;
V_5 -> V_10 . V_32 = F_307 ( V_22 ) -> V_265 ;
if ( V_5 -> V_10 . V_32 == V_266 ) {
F_308 (peer_device, device)
F_309 ( V_72 ) ;
}
F_308 (peer_device, device)
F_310 ( V_72 ) ;
F_311 ( V_5 ) ;
return V_594 ;
V_593:
F_312 ( & V_14 -> V_75 , V_73 ) ;
V_589:
F_304 (connection, resource) {
V_72 = F_313 ( & V_14 -> V_75 , V_73 ) ;
if ( V_72 ) {
F_312 ( & V_14 -> V_75 , V_73 ) ;
F_29 ( & V_14 -> V_58 , V_59 ) ;
}
}
F_225 (peer_device, tmp_peer_device, device) {
F_240 ( & V_72 -> V_75 ) ;
F_55 ( V_72 ) ;
}
F_312 ( & V_22 -> V_495 , V_73 ) ;
V_587:
F_312 ( & V_500 , V_74 ) ;
F_314 () ;
V_586:
F_200 ( V_5 ) ;
V_581:
F_205 ( V_5 -> V_398 . V_296 ) ;
V_580:
F_223 ( V_11 ) ;
V_568:
F_224 ( V_183 ) ;
V_566:
F_29 ( & V_22 -> V_58 , V_60 ) ;
F_55 ( V_5 ) ;
return V_110 ;
}
void F_249 ( struct V_4 * V_5 )
{
struct V_43 * V_22 = V_5 -> V_22 ;
struct V_13 * V_14 ;
struct V_71 * V_72 ;
int V_595 = 3 ;
F_308 (peer_device, device)
F_315 ( V_72 ) ;
F_316 ( V_5 ) ;
F_304 (connection, resource) {
F_312 ( & V_14 -> V_75 , V_5 -> V_73 ) ;
V_595 ++ ;
}
F_312 ( & V_22 -> V_495 , V_5 -> V_73 ) ;
F_312 ( & V_500 , F_48 ( V_5 ) ) ;
F_317 ( V_5 -> V_478 ) ;
F_314 () ;
F_318 ( & V_5 -> V_58 , V_595 , F_218 ) ;
}
static int T_8 F_319 ( void )
{
int V_110 ;
if ( V_465 < V_596 || V_465 > V_597 ) {
F_320 ( L_50 , V_465 ) ;
#ifdef F_321
return - V_598 ;
#else
V_465 = V_599 ;
#endif
}
V_110 = F_322 ( V_499 , L_38 ) ;
if ( V_110 ) {
F_320 ( L_51 ,
V_499 ) ;
return V_110 ;
}
F_196 ( & V_600 ) ;
V_497 = NULL ;
F_283 ( & V_500 ) ;
F_193 ( & V_601 ) ;
F_194 ( & V_538 ) ;
V_110 = F_323 () ;
if ( V_110 ) {
F_320 ( L_52 ) ;
goto V_533;
}
V_110 = F_209 () ;
if ( V_110 )
goto V_533;
V_110 = - V_472 ;
V_497 = F_324 ( L_38 , V_602 | V_603 , NULL , & V_604 , NULL ) ;
if ( ! V_497 ) {
F_320 ( L_53 ) ;
goto V_533;
}
V_483 . V_494 = F_325 ( L_54 ) ;
if ( ! V_483 . V_494 ) {
F_320 ( L_55 ) ;
goto V_533;
}
F_290 ( & V_483 . V_484 , F_226 ) ;
F_33 ( & V_483 . V_486 ) ;
F_194 ( & V_483 . V_485 ) ;
if ( F_326 () )
F_327 ( L_56 ) ;
F_252 ( L_57
L_58 V_605 L_59 ,
V_606 , V_607 , V_608 ) ;
F_252 ( L_60 , F_328 () ) ;
F_252 ( L_61 , V_499 ) ;
return 0 ;
V_533:
F_243 () ;
if ( V_110 == - V_472 )
F_320 ( L_62 ) ;
else
F_320 ( L_63 ) ;
return V_110 ;
}
static void F_329 ( struct V_102 * V_609 )
{
struct V_104 * V_24 ;
F_71 ( & V_609 -> V_106 ) ;
V_24 = V_609 -> V_104 ;
V_609 -> V_104 = NULL ;
F_72 ( & V_609 -> V_106 ) ;
if ( V_24 ) {
F_314 () ;
F_330 ( V_24 , V_610 ) ;
F_331 ( V_24 ) ;
}
}
void F_269 ( struct V_13 * V_14 )
{
if ( V_14 -> V_108 . V_104 )
F_329 ( & V_14 -> V_108 ) ;
if ( V_14 -> V_114 . V_104 )
F_329 ( & V_14 -> V_114 ) ;
}
void F_332 ( struct V_13 * V_14 )
{
struct V_71 * V_72 ;
int V_73 ;
F_46 () ;
F_248 (&connection->peer_devices, peer_device, vnr) {
struct V_4 * V_5 = V_72 -> V_5 ;
F_36 ( & V_5 -> V_58 ) ;
F_49 () ;
F_100 ( V_5 ) ;
F_29 ( & V_5 -> V_58 , F_218 ) ;
F_46 () ;
}
F_49 () ;
}
void F_333 ( struct V_4 * V_5 , void * V_248 )
{
struct V_611 * V_100 = V_248 ;
T_4 V_269 ;
int V_158 ;
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
V_100 -> V_612 = F_90 ( F_114 ( V_5 -> V_211 ) ) ;
for ( V_158 = V_162 ; V_158 < V_163 ; V_158 ++ )
V_100 -> V_164 [ V_158 ] = F_90 ( V_5 -> V_128 -> V_160 . V_164 [ V_158 ] ) ;
V_100 -> V_44 = F_64 ( V_5 -> V_128 -> V_160 . V_44 ) ;
V_100 -> V_92 = F_64 ( V_613 ) ;
V_100 -> V_614 = F_64 ( V_5 -> V_128 -> V_160 . V_614 ) ;
V_100 -> V_615 = F_64 ( V_5 -> V_128 -> V_160 . V_615 ) ;
V_100 -> V_616 = F_64 ( V_5 -> V_475 -> V_617 ) ;
V_100 -> V_618 = F_64 ( V_619 ) ;
V_100 -> V_620 = F_90 ( V_5 -> V_128 -> V_160 . V_620 ) ;
V_100 -> V_621 = F_64 ( V_5 -> V_128 -> V_160 . V_621 ) ;
V_100 -> V_622 = F_64 ( V_5 -> V_435 ) ;
V_100 -> V_623 = F_64 ( V_5 -> V_128 -> V_160 . V_623 ) ;
V_100 -> V_624 = F_64 ( V_5 -> V_128 -> V_160 . V_624 ) ;
F_97 ( V_5 , F_334 ( V_5 -> V_128 ) == V_5 -> V_128 -> V_160 . V_625 ) ;
V_269 = V_5 -> V_128 -> V_160 . V_625 ;
if ( F_335 ( V_5 , V_5 -> V_128 , V_269 , V_626 ) ) {
F_11 ( V_5 , L_64 ) ;
F_336 ( V_5 , 1 , V_627 ) ;
}
}
void F_100 ( struct V_4 * V_5 )
{
struct V_611 * V_100 ;
F_61 ( V_163 != 4 ) ;
F_61 ( sizeof( struct V_611 ) != 4096 ) ;
F_337 ( & V_5 -> V_422 ) ;
if ( ! F_338 ( V_628 , & V_5 -> V_44 ) )
return;
if ( ! F_89 ( V_5 , V_629 ) )
return;
V_100 = F_339 ( V_5 , V_308 ) ;
if ( ! V_100 )
goto V_346;
F_333 ( V_5 , V_100 ) ;
V_5 -> V_128 -> V_160 . V_612 = F_114 ( V_5 -> V_211 ) ;
F_340 ( V_5 ) ;
V_346:
F_85 ( V_5 ) ;
}
static int F_341 ( struct V_4 * V_5 ,
struct V_611 * V_630 ,
struct V_631 * V_632 )
{
T_5 V_623 = F_342 ( V_630 -> V_623 ) ;
T_5 V_624 = F_342 ( V_630 -> V_624 ) ;
T_3 V_633 ;
if ( V_623 == 0 && V_624 == 0 ) {
V_623 = 1 ;
V_624 = V_634 / 8 ;
}
if ( V_623 == 0 || V_624 == 0 )
goto V_110;
V_633 = ( T_3 ) V_623 * V_624 ;
if ( V_633 > ( 16 * 1024 * 1024 / 4 ) )
goto V_110;
if ( V_633 < V_634 / 8 )
goto V_110;
V_632 -> V_624 = V_624 ;
V_632 -> V_623 = V_623 ;
V_632 -> V_633 = V_633 ;
return 0 ;
V_110:
F_11 ( V_5 , L_65 ,
V_623 , V_624 ) ;
return - V_598 ;
}
static int F_343 ( struct V_4 * V_5 , struct V_635 * V_367 )
{
T_4 V_636 = F_114 ( V_367 -> V_637 ) ;
struct V_631 * V_632 = & V_367 -> V_160 ;
T_9 V_638 ;
T_9 V_639 ;
if ( V_632 -> V_615 < 0 ) {
if ( V_632 -> V_621 > V_632 -> V_615 )
goto V_110;
V_638 = - V_632 -> V_615 ;
V_639 = V_632 -> V_615 - V_632 -> V_621 ;
} else {
if ( V_632 -> V_615 != V_640 )
goto V_110;
if ( V_632 -> V_621 < V_632 -> V_615 + V_632 -> V_633 * V_640 )
goto V_110;
V_638 = V_632 -> V_621 - V_640 ;
V_639 = V_632 -> V_614 - V_632 -> V_621 ;
}
if ( V_632 -> V_641 >= 0 ) {
if ( V_632 -> V_614 != V_642
|| V_632 -> V_615 != V_640
|| V_632 -> V_621 != V_640 + V_634
|| V_632 -> V_623 != 1
|| V_632 -> V_624 != V_634 / 8 )
goto V_110;
}
if ( V_636 < V_632 -> V_614 )
goto V_110;
if ( V_636 - V_632 -> V_614 < F_344 ( V_367 ) )
goto V_110;
if ( ( V_638 & 7 ) || ( V_638 < V_634 ) )
goto V_110;
if ( V_638 != V_632 -> V_633 * V_640 )
goto V_110;
if ( V_632 -> V_621 & 7 )
goto V_110;
if ( V_639 < ( V_632 -> V_612 + 7 ) / V_640 / 8 / 512 )
goto V_110;
return 0 ;
V_110:
F_11 ( V_5 , L_66
L_67
L_68 ,
V_632 -> V_641 ,
V_632 -> V_623 , V_632 -> V_624 ,
V_632 -> V_615 , V_632 -> V_621 , V_632 -> V_614 ,
( unsigned long long ) V_632 -> V_612 ,
( unsigned long long ) V_636 ) ;
return - V_598 ;
}
int F_345 ( struct V_4 * V_5 , struct V_635 * V_367 )
{
struct V_611 * V_100 ;
T_5 V_92 , V_44 ;
int V_158 , V_355 = V_594 ;
if ( V_5 -> V_10 . V_11 != V_386 )
return V_643 ;
V_100 = F_339 ( V_5 , V_308 ) ;
if ( ! V_100 )
return V_564 ;
V_367 -> V_160 . V_641 = V_367 -> V_120 -> V_641 ;
V_367 -> V_160 . V_625 = F_334 ( V_367 ) ;
V_367 -> V_160 . V_614 = 8 ;
if ( F_335 ( V_5 , V_367 , V_367 -> V_160 . V_625 ,
V_644 ) ) {
F_11 ( V_5 , L_69 ) ;
V_355 = V_645 ;
goto V_110;
}
V_92 = F_342 ( V_100 -> V_92 ) ;
V_44 = F_342 ( V_100 -> V_44 ) ;
if ( V_92 == V_613 ||
( V_92 == V_646 && ! ( V_44 & V_647 ) ) ) {
F_11 ( V_5 , L_70 ) ;
V_355 = V_648 ;
goto V_110;
}
V_355 = V_649 ;
if ( V_92 != V_646 ) {
if ( V_92 == V_650 )
F_11 ( V_5 , L_71 ) ;
else
F_11 ( V_5 , L_72 ) ;
goto V_110;
}
if ( F_342 ( V_100 -> V_618 ) != V_619 ) {
F_11 ( V_5 , L_73 ,
F_342 ( V_100 -> V_618 ) , V_619 ) ;
goto V_110;
}
V_367 -> V_160 . V_612 = F_346 ( V_100 -> V_612 ) ;
for ( V_158 = V_162 ; V_158 < V_163 ; V_158 ++ )
V_367 -> V_160 . V_164 [ V_158 ] = F_346 ( V_100 -> V_164 [ V_158 ] ) ;
V_367 -> V_160 . V_44 = F_342 ( V_100 -> V_44 ) ;
V_367 -> V_160 . V_620 = F_346 ( V_100 -> V_620 ) ;
V_367 -> V_160 . V_614 = F_342 ( V_100 -> V_614 ) ;
V_367 -> V_160 . V_615 = F_342 ( V_100 -> V_615 ) ;
V_367 -> V_160 . V_621 = F_342 ( V_100 -> V_621 ) ;
if ( F_341 ( V_5 , V_100 , & V_367 -> V_160 ) )
goto V_110;
if ( F_343 ( V_5 , V_367 ) )
goto V_110;
if ( F_342 ( V_100 -> V_621 ) != V_367 -> V_160 . V_621 ) {
F_11 ( V_5 , L_74 ,
F_342 ( V_100 -> V_621 ) , V_367 -> V_160 . V_621 ) ;
goto V_110;
}
if ( F_342 ( V_100 -> V_614 ) != V_367 -> V_160 . V_614 ) {
F_11 ( V_5 , L_75 ,
F_342 ( V_100 -> V_614 ) , V_367 -> V_160 . V_614 ) ;
goto V_110;
}
V_355 = V_594 ;
F_9 ( & V_5 -> V_22 -> V_23 ) ;
if ( V_5 -> V_10 . V_32 < V_273 ) {
unsigned int V_383 ;
V_383 = F_342 ( V_100 -> V_622 ) ;
V_383 = F_347 ( V_383 , V_436 ) ;
V_5 -> V_435 = V_383 ;
}
F_14 ( & V_5 -> V_22 -> V_23 ) ;
V_110:
F_340 ( V_5 ) ;
return V_355 ;
}
void F_348 ( struct V_4 * V_5 , unsigned int line , const char * F_32 )
{
if ( ! F_349 ( V_628 , & V_5 -> V_44 ) ) {
F_350 ( & V_5 -> V_422 , V_651 + V_652 ) ;
V_5 -> V_653 . line = line ;
V_5 -> V_653 . F_32 = F_32 ;
}
}
void F_351 ( struct V_4 * V_5 )
{
if ( ! F_349 ( V_628 , & V_5 -> V_44 ) )
F_350 ( & V_5 -> V_422 , V_651 + 5 * V_652 ) ;
}
void F_352 ( struct V_4 * V_5 ) __must_hold( T_10 )
{
int V_158 ;
for ( V_158 = V_173 ; V_158 < V_174 ; V_158 ++ )
V_5 -> V_128 -> V_160 . V_164 [ V_158 + 1 ] = V_5 -> V_128 -> V_160 . V_164 [ V_158 ] ;
}
void F_353 ( struct V_4 * V_5 , int V_654 , T_3 V_218 ) __must_hold( T_10 )
{
if ( V_654 == V_162 ) {
if ( V_5 -> V_10 . V_372 == V_373 )
V_218 |= 1 ;
else
V_218 &= ~ ( ( T_3 ) 1 ) ;
F_354 ( V_5 , V_218 ) ;
}
V_5 -> V_128 -> V_160 . V_164 [ V_654 ] = V_218 ;
F_351 ( V_5 ) ;
}
void F_355 ( struct V_4 * V_5 , int V_654 , T_3 V_218 ) __must_hold( T_10 )
{
unsigned long V_44 ;
F_24 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
F_353 ( V_5 , V_654 , V_218 ) ;
F_26 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
}
void F_99 ( struct V_4 * V_5 , int V_654 , T_3 V_218 ) __must_hold( T_10 )
{
unsigned long V_44 ;
F_24 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
if ( V_5 -> V_128 -> V_160 . V_164 [ V_654 ] ) {
F_352 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_173 ] = V_5 -> V_128 -> V_160 . V_164 [ V_654 ] ;
}
F_353 ( V_5 , V_654 , V_218 ) ;
F_26 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
}
void F_356 ( struct V_4 * V_5 ) __must_hold( T_10 )
{
T_3 V_218 ;
unsigned long long V_655 ;
F_98 ( & V_218 , sizeof( T_3 ) ) ;
F_9 ( & V_5 -> V_128 -> V_160 . V_161 ) ;
V_655 = V_5 -> V_128 -> V_160 . V_164 [ V_172 ] ;
if ( V_655 )
F_169 ( V_5 , L_76 , V_655 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_172 ] = V_5 -> V_128 -> V_160 . V_164 [ V_162 ] ;
F_353 ( V_5 , V_162 , V_218 ) ;
F_14 ( & V_5 -> V_128 -> V_160 . V_161 ) ;
F_95 ( V_5 , L_77 ) ;
F_100 ( V_5 ) ;
}
void F_357 ( struct V_4 * V_5 , T_3 V_218 ) __must_hold( T_10 )
{
unsigned long V_44 ;
if ( V_5 -> V_128 -> V_160 . V_164 [ V_172 ] == 0 && V_218 == 0 )
return;
F_24 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
if ( V_218 == 0 ) {
F_352 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_173 ] = V_5 -> V_128 -> V_160 . V_164 [ V_172 ] ;
V_5 -> V_128 -> V_160 . V_164 [ V_172 ] = 0 ;
} else {
unsigned long long V_655 = V_5 -> V_128 -> V_160 . V_164 [ V_172 ] ;
if ( V_655 )
F_169 ( V_5 , L_76 , V_655 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_172 ] = V_218 & ~ ( ( T_3 ) 1 ) ;
}
F_26 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
F_351 ( V_5 ) ;
}
int F_358 ( struct V_4 * V_5 ) __must_hold( T_10 )
{
int V_355 = - V_115 ;
F_359 ( V_5 , V_263 ) ;
F_100 ( V_5 ) ;
F_138 ( V_5 ) ;
V_355 = F_139 ( V_5 ) ;
if ( ! V_355 ) {
F_140 ( V_5 , V_263 ) ;
F_100 ( V_5 ) ;
}
return V_355 ;
}
int F_360 ( struct V_4 * V_5 ) __must_hold( T_10 )
{
F_361 ( V_5 ) ;
F_362 ( V_5 ) ;
return F_139 ( V_5 ) ;
}
static int V_420 ( struct V_512 * V_414 , int V_656 )
{
struct V_4 * V_5 =
F_219 ( V_414 , struct V_4 , V_413 . V_414 ) ;
struct V_413 * V_657 = & V_5 -> V_413 ;
int V_355 = - V_115 ;
if ( V_657 -> V_44 != V_658 ) {
int V_659 = F_229 ( & V_5 -> V_389 ) ;
if ( V_659 )
F_11 ( V_5 , L_78 ,
V_659 , V_657 -> V_660 ) ;
}
if ( F_84 ( V_5 ) ) {
F_363 ( V_5 , V_657 -> V_660 , V_657 -> V_44 ) ;
V_355 = V_657 -> V_661 ( V_5 ) ;
F_364 ( V_5 ) ;
F_85 ( V_5 ) ;
}
F_365 ( V_662 , & V_5 -> V_44 ) ;
F_7 ( & V_5 -> V_12 ) ;
if ( V_657 -> V_515 )
V_657 -> V_515 ( V_5 , V_355 ) ;
F_170 ( V_663 , & V_5 -> V_44 ) ;
V_657 -> V_660 = NULL ;
V_657 -> V_44 = 0 ;
return 0 ;
}
void F_366 ( struct V_4 * V_5 ,
int (* V_661)( struct V_4 * ) ,
void (* V_515)( struct V_4 * , int ) ,
char * V_660 , enum V_664 V_44 )
{
F_97 ( V_5 , V_46 == F_22 ( V_5 ) -> V_14 -> V_484 . V_55 ) ;
F_97 ( V_5 , ! F_92 ( V_663 , & V_5 -> V_44 ) ) ;
F_97 ( V_5 , ! F_92 ( V_662 , & V_5 -> V_44 ) ) ;
F_97 ( V_5 , F_202 ( & V_5 -> V_413 . V_414 . V_411 ) ) ;
if ( V_5 -> V_413 . V_660 )
F_11 ( V_5 , L_79 ,
V_660 , V_5 -> V_413 . V_660 ) ;
V_5 -> V_413 . V_661 = V_661 ;
V_5 -> V_413 . V_515 = V_515 ;
V_5 -> V_413 . V_660 = V_660 ;
V_5 -> V_413 . V_44 = V_44 ;
F_9 ( & V_5 -> V_22 -> V_23 ) ;
F_160 ( V_662 , & V_5 -> V_44 ) ;
if ( V_44 == V_658 || F_229 ( & V_5 -> V_389 ) == 0 ) {
if ( ! F_349 ( V_663 , & V_5 -> V_44 ) )
F_260 ( & F_22 ( V_5 ) -> V_14 -> V_454 ,
& V_5 -> V_413 . V_414 ) ;
}
F_14 ( & V_5 -> V_22 -> V_23 ) ;
}
int F_367 ( struct V_4 * V_5 , int (* V_661)( struct V_4 * ) ,
char * V_660 , enum V_664 V_44 )
{
const bool V_665 = V_44 & ( V_666 | V_667 | V_668 ) ;
int V_355 ;
F_97 ( V_5 , V_46 != F_22 ( V_5 ) -> V_14 -> V_484 . V_55 ) ;
if ( V_665 )
F_368 ( V_5 ) ;
F_363 ( V_5 , V_660 , V_44 ) ;
V_355 = V_661 ( V_5 ) ;
F_364 ( V_5 ) ;
if ( V_665 )
F_369 ( V_5 ) ;
return V_355 ;
}
void F_359 ( struct V_4 * V_5 , int V_669 ) __must_hold( T_10 )
{
if ( ( V_5 -> V_128 -> V_160 . V_44 & V_669 ) != V_669 ) {
F_351 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_44 |= V_669 ;
}
}
void F_140 ( struct V_4 * V_5 , int V_669 ) __must_hold( T_10 )
{
if ( ( V_5 -> V_128 -> V_160 . V_44 & V_669 ) != 0 ) {
F_351 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_44 &= ~ V_669 ;
}
}
int F_137 ( struct V_635 * V_367 , int V_669 )
{
return ( V_367 -> V_160 . V_44 & V_669 ) != 0 ;
}
static void V_426 ( unsigned long V_108 )
{
struct V_4 * V_5 = (struct V_4 * ) V_108 ;
F_370 ( V_5 , V_670 ) ;
}
const char * F_371 ( enum V_89 V_90 )
{
static const char * V_671 [] = {
[ V_348 ] = L_80 ,
[ V_347 ] = L_81 ,
[ V_345 ] = L_82 ,
[ V_672 ] = L_83 ,
[ V_673 ] = L_84 ,
[ V_674 ] = L_85 ,
[ V_261 ] = L_86 ,
[ V_675 ] = L_87 ,
[ V_676 ] = L_88 ,
[ V_677 ] = L_89 ,
[ V_678 ] = L_90 ,
[ V_679 ] = L_91 ,
[ V_126 ] = L_92 ,
[ V_125 ] = L_93 ,
[ V_155 ] = L_94 ,
[ V_170 ] = L_95 ,
[ V_213 ] = L_96 ,
[ V_215 ] = L_97 ,
[ V_180 ] = L_98 ,
[ V_680 ] = L_99 ,
[ V_681 ] = L_100 ,
[ V_112 ] = L_101 ,
[ V_113 ] = L_102 ,
[ V_682 ] = L_103 ,
[ V_683 ] = L_104 ,
[ V_684 ] = L_105 ,
[ V_685 ] = L_106 ,
[ V_686 ] = L_107 ,
[ V_687 ] = L_108 ,
[ V_688 ] = L_109 ,
[ V_268 ] = L_110 ,
[ V_220 ] = L_111 ,
[ V_225 ] = L_112 ,
[ V_288 ] = L_113 ,
[ V_689 ] = L_114 ,
[ V_690 ] = L_115 ,
[ V_691 ] = L_116 ,
[ V_692 ] = L_117 ,
[ V_254 ] = L_118 ,
[ V_693 ] = L_119 ,
[ V_349 ] = L_120 ,
[ V_694 ] = L_121 ,
[ V_695 ] = L_122 ,
[ V_221 ] = L_123 ,
[ V_226 ] = L_124 ,
[ V_694 ] = L_125 ,
[ V_696 ] = L_126 ,
[ V_697 ] = L_127 ,
[ V_284 ] = L_128 ,
} ;
if ( V_90 == V_698 )
return L_129 ;
if ( V_90 == V_699 )
return L_130 ;
if ( V_90 == V_700 )
return L_131 ;
if ( V_90 >= F_372 ( V_671 ) )
return L_132 ;
return V_671 [ V_90 ] ;
}
int F_373 ( struct V_4 * V_5 , struct V_701 * V_158 )
{
struct V_118 * V_119 ;
F_374 ( V_67 ) ;
long V_702 ;
F_46 () ;
V_119 = F_83 ( F_22 ( V_5 ) -> V_14 -> V_118 ) ;
if ( ! V_119 ) {
F_49 () ;
return - V_703 ;
}
V_702 = V_119 -> V_291 ? V_119 -> V_702 * V_652 / 10 * V_119 -> V_291 : V_704 ;
F_49 () ;
V_158 -> V_705 = true ;
F_375 ( & V_5 -> V_12 , & V_67 , V_706 ) ;
F_14 ( & V_5 -> V_22 -> V_23 ) ;
V_702 = F_376 ( V_702 ) ;
F_377 ( & V_5 -> V_12 , & V_67 ) ;
F_9 ( & V_5 -> V_22 -> V_23 ) ;
if ( ! V_702 || V_5 -> V_10 . V_32 < V_273 )
return - V_703 ;
if ( F_378 ( V_46 ) )
return - V_707 ;
return 0 ;
}
void F_379 ( void )
{
struct V_43 * V_22 ;
int T_11 V_158 = 0 ;
F_71 ( & V_601 ) ;
F_380 () ;
F_381 (resource, &drbd_resources)
F_382 ( & V_22 -> V_23 , V_158 ++ ) ;
}
void F_383 ( void )
{
struct V_43 * V_22 ;
F_381 (resource, &drbd_resources)
F_384 ( & V_22 -> V_23 ) ;
F_385 () ;
F_72 ( & V_601 ) ;
}
static unsigned long
F_386 ( struct V_708 * V_709 )
{
long V_710 ;
if ( ! V_709 -> V_711 -- ) {
F_98 ( & V_710 , sizeof( V_710 ) ) ;
V_709 -> V_10 += V_710 ;
V_709 -> V_711 = V_712 ;
}
V_709 -> V_10 = V_709 -> V_10 * V_713 + V_714 ;
return F_387 ( V_709 -> V_10 ) ;
}
static char *
F_388 ( unsigned int type ) {
static char * V_715 [] = {
[ V_716 ] = L_133 ,
[ V_717 ] = L_134 ,
[ V_718 ] = L_135 ,
[ V_719 ] = L_136 ,
[ V_720 ] = L_137 ,
[ V_721 ] = L_138 ,
[ V_722 ] = L_139 ,
[ V_723 ] = L_140 ,
[ V_724 ] = L_141 ,
[ V_725 ] = L_142 ,
} ;
return ( type < V_726 ) ? V_715 [ type ] : L_143 ;
}
unsigned int
F_389 ( struct V_4 * V_5 , unsigned int type )
{
static struct V_708 V_727 = { 0 , 0 } ;
unsigned int V_728 = (
( V_729 == 0 ||
( ( 1 << F_48 ( V_5 ) ) & V_729 ) != 0 ) &&
( ( ( F_386 ( & V_727 ) % 100 ) + 1 ) <= V_730 ) ) ;
if ( V_728 ) {
V_731 ++ ;
if ( F_390 ( & V_732 ) )
F_169 ( V_5 , L_144 ,
F_388 ( type ) ) ;
}
return V_728 ;
}
const char * F_328 ( void )
{
static char V_733 [ 38 ] = L_145 ;
if ( V_733 [ 0 ] == 0 ) {
#ifdef F_321
sprintf ( V_733 , L_146 , V_61 -> V_734 ) ;
#else
V_733 [ 0 ] = 'b' ;
#endif
}
return V_733 ;
}
