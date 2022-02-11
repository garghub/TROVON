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
V_83 -> V_184 -> V_191 = ! ! V_183 -> V_192 . V_193 ;
} else {
V_183 = V_5 -> V_194 ;
V_83 -> V_184 -> V_185 = F_64 ( F_102 ( V_183 ) ) ;
V_83 -> V_184 -> V_186 = F_64 ( F_103 ( V_183 ) ) ;
V_83 -> V_184 -> V_187 = 0 ;
V_83 -> V_184 -> V_188 = F_64 ( F_105 ( V_183 ) ) ;
V_83 -> V_184 -> V_189 = F_64 ( F_106 ( V_183 ) ) ;
V_83 -> V_184 -> V_190 = 0 ;
V_83 -> V_184 -> V_191 = 0 ;
}
}
int F_108 ( struct V_71 * V_72 , int V_195 , enum V_196 V_44 )
{
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_102 * V_103 ;
struct V_181 * V_83 ;
T_4 V_197 , V_198 ;
int V_199 ;
unsigned int V_200 ;
unsigned int V_201 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_201 = sizeof( * V_83 ) ;
if ( V_72 -> V_14 -> V_202 & V_203 )
V_201 += sizeof( V_83 -> V_184 [ 0 ] ) ;
memset ( V_83 , 0 , V_201 ) ;
if ( F_89 ( V_5 , V_159 ) ) {
struct V_182 * V_183 = F_109 ( V_5 -> V_128 -> V_204 ) ;
V_197 = F_110 ( V_5 -> V_128 ) ;
F_46 () ;
V_198 = F_83 ( V_5 -> V_128 -> V_120 ) -> V_205 ;
F_49 () ;
V_199 = F_111 ( V_5 ) ;
V_200 = F_112 ( V_183 ) << 9 ;
V_200 = V_82 ( V_200 , V_206 ) ;
F_101 ( V_5 , V_83 , V_183 ) ;
F_85 ( V_5 ) ;
} else {
V_197 = 0 ;
V_198 = 0 ;
V_199 = V_207 ;
V_200 = V_206 ;
F_101 ( V_5 , V_83 , NULL ) ;
}
if ( V_72 -> V_14 -> V_84 <= 94 )
V_200 = V_82 ( V_200 , V_101 ) ;
else if ( V_72 -> V_14 -> V_84 < 100 )
V_200 = V_82 ( V_200 , V_208 ) ;
V_83 -> V_197 = F_90 ( V_197 ) ;
V_83 -> V_198 = F_90 ( V_198 ) ;
V_83 -> V_209 = F_90 ( V_195 ? 0 : F_113 ( V_5 -> V_210 ) ) ;
V_83 -> V_200 = F_64 ( V_200 ) ;
V_83 -> V_211 = F_65 ( V_199 ) ;
V_83 -> V_196 = F_65 ( V_44 ) ;
return F_79 ( V_72 , V_103 , V_212 , V_201 , NULL , 0 ) ;
}
int F_114 ( struct V_71 * V_72 )
{
struct V_102 * V_103 ;
struct V_213 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_10 = F_64 ( V_72 -> V_5 -> V_10 . V_158 ) ;
return F_79 ( V_72 , V_103 , V_214 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_115 ( struct V_71 * V_72 , union V_215 V_10 )
{
struct V_102 * V_103 ;
struct V_213 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_10 = F_64 ( V_10 . V_158 ) ;
return F_79 ( V_72 , V_103 , V_214 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_116 ( struct V_71 * V_72 , union V_215 V_216 , union V_215 V_217 )
{
struct V_102 * V_103 ;
struct V_218 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_216 = F_64 ( V_216 . V_158 ) ;
V_83 -> V_217 = F_64 ( V_217 . V_158 ) ;
return F_79 ( V_72 , V_103 , V_219 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_117 ( struct V_13 * V_14 , union V_215 V_216 , union V_215 V_217 )
{
enum V_89 V_90 ;
struct V_102 * V_103 ;
struct V_218 * V_83 ;
V_90 = V_14 -> V_84 < 100 ? V_219 : V_220 ;
V_103 = & V_14 -> V_108 ;
V_83 = F_70 ( V_14 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_216 = F_64 ( V_216 . V_158 ) ;
V_83 -> V_217 = F_64 ( V_217 . V_158 ) ;
return F_78 ( V_14 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
void F_118 ( struct V_71 * V_72 , enum V_221 V_222 )
{
struct V_102 * V_103 ;
struct V_223 * V_83 ;
V_103 = & V_72 -> V_14 -> V_114 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( V_83 ) {
V_83 -> V_222 = F_64 ( V_222 ) ;
F_79 ( V_72 , V_103 , V_224 , sizeof( * V_83 ) , NULL , 0 ) ;
}
}
void F_119 ( struct V_13 * V_14 , enum V_221 V_222 )
{
struct V_102 * V_103 ;
struct V_223 * V_83 ;
enum V_89 V_90 = V_14 -> V_84 < 100 ? V_224 : V_225 ;
V_103 = & V_14 -> V_114 ;
V_83 = F_70 ( V_14 , V_103 ) ;
if ( V_83 ) {
V_83 -> V_222 = F_64 ( V_222 ) ;
F_78 ( V_14 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
}
static void F_120 ( struct V_226 * V_83 , enum V_227 V_228 )
{
F_121 ( V_228 & ~ 0xf ) ;
V_83 -> V_229 = ( V_83 -> V_229 & ~ 0xf ) | V_228 ;
}
static void F_122 ( struct V_226 * V_83 , int V_230 )
{
V_83 -> V_229 = ( V_83 -> V_229 & ~ 0x80 ) | ( V_230 ? 0x80 : 0 ) ;
}
static void F_123 ( struct V_226 * V_83 , int V_231 )
{
F_121 ( V_231 & ~ 0x7 ) ;
V_83 -> V_229 = ( V_83 -> V_229 & ( ~ 0x7 << 4 ) ) | ( V_231 << 4 ) ;
}
static int F_124 ( struct V_4 * V_5 ,
struct V_226 * V_83 ,
unsigned int V_91 ,
struct V_232 * V_233 )
{
struct V_234 V_235 ;
unsigned long V_236 ;
unsigned long V_237 ;
unsigned long V_238 ;
unsigned V_239 ;
unsigned V_240 ;
int V_241 , V_242 ;
F_46 () ;
V_242 = F_83 ( F_22 ( V_5 ) -> V_14 -> V_118 ) -> V_242 ;
F_49 () ;
if ( ! V_242 || F_22 ( V_5 ) -> V_14 -> V_84 < 90 )
return 0 ;
if ( V_233 -> V_243 >= V_233 -> V_244 )
return 0 ;
F_125 ( & V_235 , V_83 -> V_228 , V_91 , 0 ) ;
memset ( V_83 -> V_228 , 0 , V_91 ) ;
V_236 = 0 ;
V_240 = 2 ;
do {
V_237 = ( V_240 == 0 ) ? F_126 ( V_5 , V_233 -> V_243 )
: F_127 ( V_5 , V_233 -> V_243 ) ;
if ( V_237 == - 1UL )
V_237 = V_233 -> V_244 ;
V_238 = V_237 - V_233 -> V_243 ;
if ( V_240 == 2 ) {
if ( V_238 == 0 ) {
F_122 ( V_83 , 1 ) ;
V_240 = ! V_240 ;
continue;
}
F_122 ( V_83 , 0 ) ;
}
if ( V_238 == 0 ) {
F_11 ( V_5 , L_15
L_16 , V_240 , V_233 -> V_243 ) ;
return - 1 ;
}
V_241 = F_128 ( & V_235 , V_238 ) ;
if ( V_241 == - V_245 )
break;
if ( V_241 <= 0 ) {
F_11 ( V_5 , L_17 , V_241 ) ;
return 0 ;
}
V_240 = ! V_240 ;
V_236 += V_238 ;
V_233 -> V_243 = V_237 ;
} while ( V_233 -> V_243 < V_233 -> V_244 );
V_239 = V_235 . V_246 . V_247 - V_83 -> V_228 + ! ! V_235 . V_246 . V_248 ;
if ( V_236 < ( V_239 << 3 ) ) {
V_233 -> V_243 -= V_236 ;
F_129 ( V_233 ) ;
V_233 -> V_243 = V_233 -> V_249 * V_250 ;
return 0 ;
}
F_129 ( V_233 ) ;
F_123 ( V_83 , ( 8 - V_235 . V_246 . V_248 ) & 0x7 ) ;
return V_239 ;
}
static int
F_130 ( struct V_4 * V_5 , struct V_232 * V_233 )
{
struct V_102 * V_103 = & F_22 ( V_5 ) -> V_14 -> V_108 ;
unsigned int V_107 = F_60 ( F_22 ( V_5 ) -> V_14 ) ;
struct V_226 * V_83 = V_103 -> V_105 + V_107 ;
int V_239 , V_110 ;
V_239 = F_124 ( V_5 , V_83 ,
V_251 - V_107 - sizeof( * V_83 ) , V_233 ) ;
if ( V_239 < 0 )
return - V_115 ;
if ( V_239 ) {
F_120 ( V_83 , V_252 ) ;
V_110 = F_74 ( F_22 ( V_5 ) -> V_14 , V_5 -> V_73 , V_103 ,
V_253 , sizeof( * V_83 ) + V_239 ,
NULL , 0 ) ;
V_233 -> V_254 [ 0 ] ++ ;
V_233 -> V_255 [ 0 ] += V_107 + sizeof( * V_83 ) + V_239 ;
if ( V_233 -> V_243 >= V_233 -> V_244 )
V_239 = 0 ;
} else {
unsigned int V_256 ;
unsigned long V_257 ;
unsigned long * V_83 = V_103 -> V_105 + V_107 ;
V_256 = V_251 - V_107 ;
V_257 = F_131 ( V_258 , V_256 / sizeof( * V_83 ) ,
V_233 -> V_259 - V_233 -> V_249 ) ;
V_239 = V_257 * sizeof( * V_83 ) ;
if ( V_239 )
F_132 ( V_5 , V_233 -> V_249 , V_257 , V_83 ) ;
V_110 = F_74 ( F_22 ( V_5 ) -> V_14 , V_5 -> V_73 , V_103 , V_260 , V_239 , NULL , 0 ) ;
V_233 -> V_249 += V_257 ;
V_233 -> V_243 = V_233 -> V_249 * V_250 ;
V_233 -> V_254 [ 1 ] ++ ;
V_233 -> V_255 [ 1 ] += V_107 + V_239 ;
if ( V_233 -> V_243 > V_233 -> V_244 )
V_233 -> V_243 = V_233 -> V_244 ;
}
if ( ! V_110 ) {
if ( V_239 == 0 ) {
F_133 ( V_5 , L_18 , V_233 ) ;
return 0 ;
} else
return 1 ;
}
return - V_115 ;
}
static int F_134 ( struct V_4 * V_5 )
{
struct V_232 V_233 ;
int V_110 ;
if ( ! F_135 ( V_5 -> V_261 ) )
return false ;
if ( F_84 ( V_5 ) ) {
if ( F_136 ( V_5 -> V_128 , V_262 ) ) {
F_25 ( V_5 , L_19 ) ;
F_137 ( V_5 ) ;
if ( F_138 ( V_5 ) ) {
F_11 ( V_5 , L_20 ) ;
} else {
F_139 ( V_5 , V_262 ) ;
F_100 ( V_5 ) ;
}
}
F_85 ( V_5 ) ;
}
V_233 = (struct V_232 ) {
. V_244 = F_140 ( V_5 ) ,
. V_259 = F_141 ( V_5 ) ,
} ;
do {
V_110 = F_130 ( V_5 , & V_233 ) ;
} while ( V_110 > 0 );
return V_110 == 0 ;
}
int F_142 ( struct V_4 * V_5 )
{
struct V_102 * V_103 = & F_22 ( V_5 ) -> V_14 -> V_108 ;
int V_110 = - 1 ;
F_71 ( & V_103 -> V_106 ) ;
if ( V_103 -> V_104 )
V_110 = ! F_134 ( V_5 ) ;
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
void F_143 ( struct V_13 * V_14 , T_5 V_15 , T_5 V_16 )
{
struct V_102 * V_103 ;
struct V_263 * V_83 ;
if ( V_14 -> V_264 < V_265 )
return;
V_103 = & V_14 -> V_114 ;
V_83 = F_70 ( V_14 , V_103 ) ;
if ( ! V_83 )
return;
V_83 -> V_266 = V_15 ;
V_83 -> V_16 = F_64 ( V_16 ) ;
F_78 ( V_14 , V_103 , V_267 , sizeof( * V_83 ) , NULL , 0 ) ;
}
static int F_144 ( struct V_71 * V_72 , enum V_89 V_90 ,
T_3 V_268 , T_5 V_269 , T_3 V_270 )
{
struct V_102 * V_103 ;
struct V_271 * V_83 ;
if ( V_72 -> V_5 -> V_10 . V_32 < V_272 )
return - V_115 ;
V_103 = & V_72 -> V_14 -> V_114 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_268 = V_268 ;
V_83 -> V_270 = V_270 ;
V_83 -> V_269 = V_269 ;
V_83 -> V_273 = F_64 ( F_145 ( & V_72 -> V_5 -> V_274 ) ) ;
return F_79 ( V_72 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
void F_146 ( struct V_71 * V_72 , enum V_89 V_90 ,
struct V_275 * V_276 , int V_256 )
{
if ( V_72 -> V_14 -> V_277 )
V_256 -= F_147 ( V_72 -> V_14 -> V_277 ) ;
F_144 ( V_72 , V_90 , V_276 -> V_268 , F_64 ( V_256 ) ,
V_276 -> V_270 ) ;
}
void F_148 ( struct V_71 * V_72 , enum V_89 V_90 ,
struct V_278 * V_279 )
{
F_144 ( V_72 , V_90 , V_279 -> V_268 , V_279 -> V_269 , V_279 -> V_270 ) ;
}
int F_149 ( struct V_71 * V_72 , enum V_89 V_90 ,
struct V_280 * V_281 )
{
return F_144 ( V_72 , V_90 ,
F_90 ( V_281 -> V_158 . V_268 ) ,
F_64 ( V_281 -> V_158 . V_91 ) ,
V_281 -> V_270 ) ;
}
int F_150 ( struct V_71 * V_72 , enum V_89 V_90 ,
T_4 V_268 , int V_269 , T_3 V_270 )
{
return F_144 ( V_72 , V_90 ,
F_90 ( V_268 ) ,
F_64 ( V_269 ) ,
F_90 ( V_270 ) ) ;
}
int F_151 ( struct V_71 * V_72 ,
struct V_280 * V_281 )
{
struct V_102 * V_103 ;
struct V_282 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_268 = F_90 ( V_281 -> V_158 . V_268 ) ;
V_83 -> V_269 = F_64 ( V_281 -> V_158 . V_91 ) ;
V_83 -> V_99 = 0 ;
return F_79 ( V_72 , V_103 , V_283 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_152 ( struct V_71 * V_72 , int V_90 ,
T_4 V_268 , int V_91 , T_3 V_270 )
{
struct V_102 * V_103 ;
struct V_278 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_268 = F_90 ( V_268 ) ;
V_83 -> V_270 = V_270 ;
V_83 -> V_269 = F_64 ( V_91 ) ;
return F_79 ( V_72 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_153 ( struct V_71 * V_72 , T_4 V_268 , int V_91 ,
void * V_284 , int V_285 , enum V_89 V_90 )
{
struct V_102 * V_103 ;
struct V_278 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_268 = F_90 ( V_268 ) ;
V_83 -> V_270 = V_286 ;
V_83 -> V_269 = F_64 ( V_91 ) ;
return F_79 ( V_72 , V_103 , V_90 , sizeof( * V_83 ) , V_284 , V_285 ) ;
}
int F_154 ( struct V_71 * V_72 , T_4 V_268 , int V_91 )
{
struct V_102 * V_103 ;
struct V_278 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_268 = F_90 ( V_268 ) ;
V_83 -> V_270 = V_286 ;
V_83 -> V_269 = F_64 ( V_91 ) ;
return F_79 ( V_72 , V_103 , V_287 , sizeof( * V_83 ) , NULL , 0 ) ;
}
static int F_155 ( struct V_13 * V_14 , struct V_104 * V_103 )
{
int V_288 ;
V_288 = V_14 -> V_114 . V_104 == V_103
|| ! V_14 -> V_289 . V_55
|| F_156 ( & V_14 -> V_289 ) != V_54
|| V_14 -> V_264 < V_265 ;
if ( V_288 )
return true ;
V_288 = ! -- V_14 -> V_290 ;
if ( ! V_288 ) {
F_11 ( V_14 , L_21 ,
V_46 -> V_47 , V_46 -> V_64 , V_14 -> V_290 ) ;
F_157 ( V_14 ) ;
}
return V_288 ; ;
}
static void F_158 ( struct V_13 * V_14 )
{
struct V_103 * V_291 = V_14 -> V_108 . V_104 -> V_291 ;
if ( V_291 -> V_292 > V_291 -> V_293 * 4 / 5 )
F_159 ( V_294 , & V_14 -> V_44 ) ;
}
static int F_160 ( struct V_71 * V_72 , struct V_295 * V_295 ,
int V_296 , V_258 V_91 , unsigned V_109 )
{
struct V_104 * V_104 ;
void * V_297 ;
int V_110 ;
V_104 = V_72 -> V_14 -> V_108 . V_104 ;
V_297 = F_161 ( V_295 ) + V_296 ;
V_110 = F_75 ( V_72 -> V_14 , V_104 , V_297 , V_91 , V_109 ) ;
F_162 ( V_295 ) ;
if ( ! V_110 )
V_72 -> V_5 -> V_298 += V_91 >> 9 ;
return V_110 ;
}
static int F_163 ( struct V_71 * V_72 , struct V_295 * V_295 ,
int V_296 , V_258 V_91 , unsigned V_109 )
{
struct V_104 * V_104 = V_72 -> V_14 -> V_108 . V_104 ;
T_6 V_299 = F_164 () ;
int V_239 = V_91 ;
int V_110 = - V_115 ;
if ( V_300 || ( F_165 ( V_295 ) < 1 ) || F_166 ( V_295 ) )
return F_160 ( V_72 , V_295 , V_296 , V_91 , V_109 ) ;
V_109 |= V_301 ;
F_158 ( V_72 -> V_14 ) ;
F_167 ( V_302 ) ;
do {
int V_303 ;
V_303 = V_104 -> V_304 -> V_305 ( V_104 , V_295 , V_296 , V_239 , V_109 ) ;
if ( V_303 <= 0 ) {
if ( V_303 == - V_306 ) {
if ( F_155 ( V_72 -> V_14 , V_104 ) )
break;
continue;
}
F_168 ( V_72 -> V_5 , L_22 ,
V_307 , ( int ) V_91 , V_239 , V_303 ) ;
if ( V_303 < 0 )
V_110 = V_303 ;
break;
}
V_239 -= V_303 ;
V_296 += V_303 ;
} while ( V_239 > 0 );
F_167 ( V_299 ) ;
F_169 ( V_294 , & V_72 -> V_14 -> V_44 ) ;
if ( V_239 == 0 ) {
V_110 = 0 ;
V_72 -> V_5 -> V_298 += V_91 >> 9 ;
}
return V_110 ;
}
static int F_170 ( struct V_71 * V_72 , struct V_1 * V_1 )
{
struct V_308 V_309 ;
struct V_310 V_311 ;
F_171 (bvec, bio, iter) {
int V_110 ;
V_110 = F_160 ( V_72 , V_309 . V_312 ,
V_309 . V_313 , V_309 . V_314 ,
F_172 ( V_309 , V_311 )
? 0 : V_111 ) ;
if ( V_110 )
return V_110 ;
if ( F_173 ( V_1 ) == V_315 )
break;
}
return 0 ;
}
static int F_174 ( struct V_71 * V_72 , struct V_1 * V_1 )
{
struct V_308 V_309 ;
struct V_310 V_311 ;
F_171 (bvec, bio, iter) {
int V_110 ;
V_110 = F_163 ( V_72 , V_309 . V_312 ,
V_309 . V_313 , V_309 . V_314 ,
F_172 ( V_309 , V_311 ) ? 0 : V_111 ) ;
if ( V_110 )
return V_110 ;
if ( F_173 ( V_1 ) == V_315 )
break;
}
return 0 ;
}
static int F_175 ( struct V_71 * V_72 ,
struct V_280 * V_281 )
{
struct V_295 * V_295 = V_281 -> V_316 ;
unsigned V_239 = V_281 -> V_158 . V_91 ;
int V_110 ;
F_176 (page) {
unsigned V_317 = F_131 ( unsigned , V_239 , V_318 ) ;
V_110 = F_163 ( V_72 , V_295 , 0 , V_317 ,
F_177 ( V_295 ) ? V_111 : 0 ) ;
if ( V_110 )
return V_110 ;
V_239 -= V_317 ;
}
return 0 ;
}
static T_5 F_178 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
if ( V_14 -> V_84 >= 95 )
return ( V_1 -> V_319 & V_320 ? V_321 : 0 ) |
( V_1 -> V_319 & V_322 ? V_323 : 0 ) |
( V_1 -> V_319 & V_324 ? V_325 : 0 ) |
( F_173 ( V_1 ) == V_315 ? V_326 : 0 ) |
( F_173 ( V_1 ) == V_327 ? V_328 : 0 ) |
( F_173 ( V_1 ) == V_329 ? V_328 : 0 ) ;
else
return V_1 -> V_319 & V_320 ? V_321 : 0 ;
}
int F_179 ( struct V_71 * V_72 , struct V_17 * V_19 )
{
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_102 * V_103 ;
struct V_275 * V_83 ;
struct V_330 * V_331 = NULL ;
void * V_332 ;
unsigned int V_333 = 0 ;
int V_285 ;
int V_110 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
V_285 = V_72 -> V_14 -> V_334 ?
F_147 ( V_72 -> V_14 -> V_334 ) : 0 ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_268 = F_90 ( V_19 -> V_158 . V_268 ) ;
V_83 -> V_270 = ( unsigned long ) V_19 ;
V_83 -> V_273 = F_64 ( F_145 ( & V_5 -> V_274 ) ) ;
V_333 = F_178 ( V_72 -> V_14 , V_19 -> V_335 ) ;
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
if ( V_333 & V_328 ) {
struct V_343 * V_344 = (struct V_343 * ) V_83 ;
V_344 -> V_91 = F_64 ( V_19 -> V_158 . V_91 ) ;
V_110 = F_74 ( V_72 -> V_14 , V_5 -> V_73 , V_103 , V_345 , sizeof( * V_344 ) , NULL , 0 ) ;
goto V_346;
}
if ( V_333 & V_326 ) {
V_331 = (struct V_330 * ) V_83 ;
V_332 = V_331 + 1 ;
V_331 -> V_91 = F_64 ( V_19 -> V_158 . V_91 ) ;
} else
V_332 = V_83 + 1 ;
if ( V_285 )
F_180 ( V_72 -> V_14 -> V_334 , V_19 -> V_335 , V_332 ) ;
if ( V_331 ) {
V_110 =
F_74 ( V_72 -> V_14 , V_5 -> V_73 , V_103 , V_347 ,
sizeof( * V_331 ) + V_285 , NULL ,
F_181 ( V_19 -> V_335 ) . V_314 ) ;
} else
V_110 =
F_74 ( V_72 -> V_14 , V_5 -> V_73 , V_103 , V_348 ,
sizeof( * V_83 ) + V_285 , NULL , V_19 -> V_158 . V_91 ) ;
if ( ! V_110 ) {
if ( ! ( V_19 -> V_25 & ( V_339 | V_341 ) ) || V_285 )
V_110 = F_170 ( V_72 , V_19 -> V_335 ) ;
else
V_110 = F_174 ( V_72 , V_19 -> V_335 ) ;
if ( V_285 > 0 && V_285 <= 64 ) {
unsigned char V_284 [ 64 ] ;
F_180 ( V_72 -> V_14 -> V_334 , V_19 -> V_335 , V_284 ) ;
if ( memcmp ( V_83 + 1 , V_284 , V_285 ) ) {
F_168 ( V_5 ,
L_23 ,
( unsigned long long ) V_19 -> V_158 . V_268 , V_19 -> V_158 . V_91 ) ;
}
}
}
V_346:
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
int F_182 ( struct V_71 * V_72 , enum V_89 V_90 ,
struct V_280 * V_281 )
{
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_102 * V_103 ;
struct V_275 * V_83 ;
int V_110 ;
int V_285 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
V_285 = V_72 -> V_14 -> V_334 ?
F_147 ( V_72 -> V_14 -> V_334 ) : 0 ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_268 = F_90 ( V_281 -> V_158 . V_268 ) ;
V_83 -> V_270 = V_281 -> V_270 ;
V_83 -> V_273 = 0 ;
V_83 -> V_333 = 0 ;
if ( V_285 )
F_183 ( V_72 -> V_14 -> V_334 , V_281 , V_83 + 1 ) ;
V_110 = F_74 ( V_72 -> V_14 , V_5 -> V_73 , V_103 , V_90 , sizeof( * V_83 ) + V_285 , NULL , V_281 -> V_158 . V_91 ) ;
if ( ! V_110 )
V_110 = F_175 ( V_72 , V_281 ) ;
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
int F_184 ( struct V_71 * V_72 , struct V_17 * V_19 )
{
struct V_102 * V_103 ;
struct V_282 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_268 = F_90 ( V_19 -> V_158 . V_268 ) ;
V_83 -> V_269 = F_64 ( V_19 -> V_158 . V_91 ) ;
return F_79 ( V_72 , V_103 , V_349 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_185 ( struct V_13 * V_14 , struct V_104 * V_103 ,
void * V_350 , V_258 V_91 , unsigned V_109 )
{
struct V_351 V_352 = { . V_353 = V_350 , . V_354 = V_91 } ;
struct V_355 V_356 ;
int V_357 , V_303 = 0 ;
if ( ! V_103 )
return - V_358 ;
V_356 . V_359 = NULL ;
V_356 . V_360 = 0 ;
V_356 . V_361 = NULL ;
V_356 . V_362 = 0 ;
V_356 . V_109 = V_109 | V_301 ;
F_186 ( & V_356 . V_363 , V_364 | V_365 , & V_352 , 1 , V_91 ) ;
if ( V_103 == V_14 -> V_108 . V_104 ) {
F_46 () ;
V_14 -> V_290 = F_83 ( V_14 -> V_118 ) -> V_290 ;
F_49 () ;
F_158 ( V_14 ) ;
}
do {
V_357 = F_187 ( V_103 , & V_356 ) ;
if ( V_357 == - V_306 ) {
if ( F_155 ( V_14 , V_103 ) )
break;
else
continue;
}
if ( V_357 == - V_366 ) {
F_38 ( V_46 ) ;
V_357 = 0 ;
}
if ( V_357 < 0 )
break;
V_303 += V_357 ;
} while ( V_303 < V_91 );
if ( V_103 == V_14 -> V_108 . V_104 )
F_169 ( V_294 , & V_14 -> V_44 ) ;
if ( V_357 <= 0 ) {
if ( V_357 != - V_306 ) {
F_11 ( V_14 , L_24 ,
V_103 == V_14 -> V_114 . V_104 ? L_25 : L_26 ,
V_357 ) ;
F_15 ( V_14 , F_16 ( V_32 , V_367 ) , V_34 ) ;
} else
F_15 ( V_14 , F_16 ( V_32 , V_368 ) , V_34 ) ;
}
return V_303 ;
}
int F_75 ( struct V_13 * V_14 , struct V_104 * V_103 , void * V_100 ,
V_258 V_91 , unsigned V_109 )
{
int V_110 ;
V_110 = F_185 ( V_14 , V_103 , V_100 , V_91 , V_109 ) ;
if ( V_110 < 0 )
return V_110 ;
if ( V_110 != V_91 )
return - V_115 ;
return 0 ;
}
static int F_188 ( struct V_369 * V_370 , T_7 V_371 )
{
struct V_4 * V_5 = V_370 -> V_372 -> V_373 ;
unsigned long V_44 ;
int V_357 = 0 ;
F_71 ( & V_374 ) ;
F_24 ( & V_5 -> V_22 -> V_23 , V_44 ) ;
if ( V_5 -> V_10 . V_375 != V_376 ) {
if ( V_371 & V_377 )
V_357 = - V_378 ;
else if ( ! V_379 )
V_357 = - V_380 ;
}
if ( ! V_357 )
V_5 -> V_381 ++ ;
F_26 ( & V_5 -> V_22 -> V_23 , V_44 ) ;
F_72 ( & V_374 ) ;
return V_357 ;
}
static void F_189 ( struct V_382 * V_383 , T_7 V_371 )
{
struct V_4 * V_5 = V_383 -> V_373 ;
F_71 ( & V_374 ) ;
V_5 -> V_381 -- ;
F_72 ( & V_374 ) ;
}
static void F_190 ( struct V_4 * V_5 )
{
V_5 -> V_10 = (union V_384 ) {
{ . V_375 = V_385 ,
. V_386 = V_387 ,
. V_32 = V_388 ,
. V_11 = V_389 ,
. V_390 = V_391 ,
} } ;
}
void F_191 ( struct V_4 * V_5 )
{
F_190 ( V_5 ) ;
F_192 ( & V_5 -> V_392 , 0 ) ;
F_192 ( & V_5 -> V_393 , 0 ) ;
F_192 ( & V_5 -> V_394 , 0 ) ;
F_192 ( & V_5 -> V_395 , 0 ) ;
F_192 ( & V_5 -> V_396 , 0 ) ;
F_192 ( & V_5 -> V_9 , 0 ) ;
F_192 ( & V_5 -> V_397 , 0 ) ;
F_192 ( & V_5 -> V_398 , 0 ) ;
F_192 ( & V_5 -> V_399 , 0 ) ;
F_192 ( & V_5 -> V_400 , 0 ) ;
F_192 ( & V_5 -> V_401 . V_402 , 0 ) ;
F_193 ( & V_5 -> V_403 ) ;
V_5 -> V_404 = & V_5 -> V_403 ;
F_33 ( & V_5 -> V_405 ) ;
F_33 ( & V_5 -> V_406 ) ;
F_194 ( & V_5 -> V_407 ) ;
F_194 ( & V_5 -> V_408 ) ;
F_194 ( & V_5 -> V_409 ) ;
F_194 ( & V_5 -> V_410 ) ;
F_194 ( & V_5 -> V_411 ) ;
F_194 ( & V_5 -> V_412 ) ;
F_194 ( & V_5 -> V_413 . V_414 ) ;
F_194 ( & V_5 -> V_415 . V_414 ) ;
F_194 ( & V_5 -> V_416 . V_417 . V_414 ) ;
F_194 ( & V_5 -> V_418 [ 0 ] ) ;
F_194 ( & V_5 -> V_418 [ 1 ] ) ;
F_194 ( & V_5 -> V_419 [ 0 ] ) ;
F_194 ( & V_5 -> V_419 [ 1 ] ) ;
V_5 -> V_413 . V_420 = V_421 ;
V_5 -> V_415 . V_420 = V_422 ;
V_5 -> V_416 . V_417 . V_420 = V_423 ;
F_195 ( & V_5 -> V_424 ) ;
F_195 ( & V_5 -> V_425 ) ;
F_195 ( & V_5 -> V_426 ) ;
F_195 ( & V_5 -> V_427 ) ;
V_5 -> V_424 . V_50 = V_428 ;
V_5 -> V_424 . V_108 = ( unsigned long ) V_5 ;
V_5 -> V_425 . V_50 = V_429 ;
V_5 -> V_425 . V_108 = ( unsigned long ) V_5 ;
V_5 -> V_426 . V_50 = V_430 ;
V_5 -> V_426 . V_108 = ( unsigned long ) V_5 ;
V_5 -> V_427 . V_50 = V_431 ;
V_5 -> V_427 . V_108 = ( unsigned long ) V_5 ;
F_196 ( & V_5 -> V_12 ) ;
F_196 ( & V_5 -> V_432 ) ;
F_196 ( & V_5 -> V_433 ) ;
F_196 ( & V_5 -> V_434 ) ;
F_196 ( & V_5 -> V_435 ) ;
V_5 -> V_436 = V_437 ;
V_5 -> V_438 = V_439 ;
V_5 -> V_440 = V_439 ;
}
void F_197 ( struct V_4 * V_5 )
{
int V_158 ;
if ( F_22 ( V_5 ) -> V_14 -> V_441 . V_52 != V_56 )
F_11 ( V_5 , L_27 ,
F_22 ( V_5 ) -> V_14 -> V_441 . V_52 ) ;
V_5 -> V_442 =
V_5 -> V_443 =
V_5 -> V_444 =
V_5 -> V_445 =
V_5 -> V_298 =
V_5 -> V_446 =
V_5 -> V_447 =
V_5 -> V_448 =
V_5 -> V_449 =
V_5 -> V_450 = 0 ;
V_5 -> V_451 = 0 ;
V_5 -> V_452 = 0 ;
for ( V_158 = 0 ; V_158 < V_453 ; V_158 ++ ) {
V_5 -> V_454 [ V_158 ] = 0 ;
V_5 -> V_455 [ V_158 ] = 0 ;
}
F_97 ( V_5 , F_22 ( V_5 ) -> V_14 -> V_118 == NULL ) ;
F_198 ( V_5 , 0 ) ;
if ( V_5 -> V_261 ) {
F_199 ( V_5 , 0 , 1 ) ;
F_200 ( V_5 ) ;
}
F_201 ( V_5 , V_5 -> V_128 ) ;
V_5 -> V_128 = NULL ;
F_169 ( V_456 , & V_5 -> V_44 ) ;
F_97 ( V_5 , F_202 ( & V_5 -> V_407 ) ) ;
F_97 ( V_5 , F_202 ( & V_5 -> V_408 ) ) ;
F_97 ( V_5 , F_202 ( & V_5 -> V_409 ) ) ;
F_97 ( V_5 , F_202 ( & V_5 -> V_410 ) ) ;
F_97 ( V_5 , F_202 ( & V_5 -> V_411 ) ) ;
F_97 ( V_5 , F_202 ( & V_5 -> V_412 ) ) ;
F_97 ( V_5 , F_202 ( & F_22 ( V_5 ) -> V_14 -> V_457 . V_183 ) ) ;
F_97 ( V_5 , F_202 ( & V_5 -> V_413 . V_414 ) ) ;
F_97 ( V_5 , F_202 ( & V_5 -> V_415 . V_414 ) ) ;
F_190 ( V_5 ) ;
}
static void F_203 ( void )
{
struct V_295 * V_295 ;
while ( V_458 ) {
V_295 = V_458 ;
V_458 = (struct V_295 * ) F_204 ( V_295 ) ;
F_205 ( V_295 ) ;
V_459 -- ;
}
if ( V_3 )
F_206 ( V_3 ) ;
if ( V_460 )
F_207 ( V_460 ) ;
if ( V_461 )
F_207 ( V_461 ) ;
if ( V_462 )
F_207 ( V_462 ) ;
if ( V_463 )
F_208 ( V_463 ) ;
if ( V_464 )
F_208 ( V_464 ) ;
if ( V_465 )
F_208 ( V_465 ) ;
if ( V_466 )
F_208 ( V_466 ) ;
V_3 = NULL ;
V_460 = NULL ;
V_461 = NULL ;
V_462 = NULL ;
V_463 = NULL ;
V_464 = NULL ;
V_465 = NULL ;
V_466 = NULL ;
return;
}
static int F_209 ( void )
{
struct V_295 * V_295 ;
const int V_467 = ( V_206 / V_318 ) * V_468 ;
int V_158 ;
V_462 = NULL ;
V_463 = NULL ;
V_464 = NULL ;
V_465 = NULL ;
V_466 = NULL ;
V_458 = NULL ;
V_460 = NULL ;
V_3 = NULL ;
V_464 = F_210 (
L_28 , sizeof( struct V_17 ) , 0 , 0 , NULL ) ;
if ( V_464 == NULL )
goto V_469;
V_463 = F_210 (
L_29 , sizeof( struct V_280 ) , 0 , 0 , NULL ) ;
if ( V_463 == NULL )
goto V_469;
V_465 = F_210 (
L_30 , sizeof( struct V_470 ) , 0 , 0 , NULL ) ;
if ( V_465 == NULL )
goto V_469;
V_466 = F_210 (
L_31 , sizeof( struct V_471 ) , 0 , 0 , NULL ) ;
if ( V_466 == NULL )
goto V_469;
V_3 = F_211 ( V_472 , 0 ) ;
if ( V_3 == NULL )
goto V_469;
V_460 = F_212 ( V_472 , 0 ) ;
if ( V_460 == NULL )
goto V_469;
V_462 = F_213 ( V_467 ,
V_464 ) ;
if ( V_462 == NULL )
goto V_469;
V_461 = F_213 ( V_467 , V_463 ) ;
if ( V_461 == NULL )
goto V_469;
F_33 ( & V_473 ) ;
for ( V_158 = 0 ; V_158 < V_467 ; V_158 ++ ) {
V_295 = F_214 ( V_474 ) ;
if ( ! V_295 )
goto V_469;
F_215 ( V_295 , ( unsigned long ) V_458 ) ;
V_458 = V_295 ;
}
V_459 = V_467 ;
return 0 ;
V_469:
F_203 () ;
return - V_475 ;
}
static void F_216 ( struct V_4 * V_5 )
{
int V_476 ;
V_476 = F_217 ( V_5 , & V_5 -> V_407 ) ;
if ( V_476 )
F_11 ( V_5 , L_32 , V_476 ) ;
V_476 = F_217 ( V_5 , & V_5 -> V_408 ) ;
if ( V_476 )
F_11 ( V_5 , L_33 , V_476 ) ;
V_476 = F_217 ( V_5 , & V_5 -> V_410 ) ;
if ( V_476 )
F_11 ( V_5 , L_34 , V_476 ) ;
V_476 = F_217 ( V_5 , & V_5 -> V_409 ) ;
if ( V_476 )
F_11 ( V_5 , L_35 , V_476 ) ;
V_476 = F_217 ( V_5 , & V_5 -> V_411 ) ;
if ( V_476 )
F_11 ( V_5 , L_36 , V_476 ) ;
}
void F_218 ( struct V_58 * V_58 )
{
struct V_4 * V_5 = F_219 ( V_58 , struct V_4 , V_58 ) ;
struct V_43 * V_22 = V_5 -> V_22 ;
struct V_71 * V_72 , * V_477 ;
F_220 ( & V_5 -> V_427 ) ;
F_97 ( V_5 , V_5 -> V_381 == 0 ) ;
if ( V_5 -> V_210 )
F_221 ( V_5 -> V_210 ) ;
F_201 ( V_5 , V_5 -> V_128 ) ;
V_5 -> V_128 = NULL ;
F_216 ( V_5 ) ;
F_222 ( V_5 -> V_478 ) ;
F_222 ( V_5 -> V_479 ) ;
F_55 ( V_5 -> V_480 ) ;
if ( V_5 -> V_261 )
F_200 ( V_5 ) ;
F_205 ( V_5 -> V_401 . V_295 ) ;
F_223 ( V_5 -> V_481 ) ;
F_224 ( V_5 -> V_194 ) ;
F_55 ( V_5 -> V_482 ) ;
F_225 (peer_device, tmp_peer_device, device) {
F_29 ( & V_72 -> V_14 -> V_58 , V_59 ) ;
F_55 ( V_72 ) ;
}
memset ( V_5 , 0xfd , sizeof( * V_5 ) ) ;
F_55 ( V_5 ) ;
F_29 ( & V_22 -> V_58 , V_60 ) ;
}
static void F_226 ( struct V_483 * V_484 )
{
struct V_485 * V_486 = F_219 ( V_484 , struct V_485 , V_487 ) ;
F_227 ( V_488 ) ;
struct V_17 * V_19 , * V_237 ;
F_9 ( & V_486 -> V_489 ) ;
F_228 ( & V_486 -> V_488 , & V_488 ) ;
F_14 ( & V_486 -> V_489 ) ;
F_18 (req, tmp, &writes, tl_requests) {
struct V_4 * V_5 = V_19 -> V_5 ;
struct V_1 * V_1 = V_19 -> V_335 ;
unsigned long V_490 = V_19 -> V_490 ;
bool V_491 ;
V_491 =
F_135 ( F_229 ( & V_19 -> V_492 ) == 0 ) &&
F_135 ( V_19 -> V_25 & V_493 ) &&
F_135 ( ( V_19 -> V_25 & V_38 ) == 0 ||
( V_19 -> V_25 & V_494 ) != 0 ) ;
if ( ! V_491 )
F_11 ( V_5 , L_37 ,
V_19 , F_229 ( & V_19 -> V_492 ) ,
V_19 -> V_25 ) ;
F_29 ( & V_19 -> V_58 , V_495 ) ;
F_230 ( V_5 ) ;
F_231 ( V_5 , V_1 , V_490 ) ;
}
}
void F_232 ( struct V_17 * V_19 )
{
unsigned long V_44 ;
F_24 ( & V_486 . V_489 , V_44 ) ;
F_233 ( & V_19 -> V_496 , & V_486 . V_488 ) ;
F_26 ( & V_486 . V_489 , V_44 ) ;
F_234 ( V_19 -> V_5 ) ;
F_235 ( V_486 . V_497 , & V_486 . V_487 ) ;
}
void V_60 ( struct V_58 * V_58 )
{
struct V_43 * V_22 =
F_219 ( V_58 , struct V_43 , V_58 ) ;
F_236 ( & V_22 -> V_498 ) ;
F_237 ( V_22 -> V_76 ) ;
F_55 ( V_22 -> V_48 ) ;
memset ( V_22 , 0xf2 , sizeof( * V_22 ) ) ;
F_55 ( V_22 ) ;
}
void F_238 ( struct V_43 * V_22 )
{
struct V_13 * V_14 , * V_237 ;
F_239 (connection, tmp, resource) {
F_240 ( & V_14 -> V_499 ) ;
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
struct V_43 * V_22 , * V_237 ;
if ( V_500 )
F_244 ( L_38 , NULL ) ;
if ( V_486 . V_497 )
F_245 ( V_486 . V_497 ) ;
F_246 () ;
F_247 () ;
F_248 (&drbd_devices, device, i)
F_249 ( V_5 ) ;
F_250 (resource, tmp, &drbd_resources) {
F_240 ( & V_22 -> V_501 ) ;
F_238 ( V_22 ) ;
}
F_203 () ;
F_251 ( V_502 , L_38 ) ;
F_236 ( & V_503 ) ;
F_252 ( L_39 ) ;
}
static int F_253 ( void * V_504 , int V_505 )
{
struct V_4 * V_5 = V_504 ;
struct V_182 * V_183 ;
char V_506 = '-' ;
int V_18 = 0 ;
if ( ! F_254 ( V_5 ) ) {
V_18 = V_505 ;
V_506 = 'd' ;
goto V_346;
}
if ( F_92 ( V_507 , & F_22 ( V_5 ) -> V_14 -> V_44 ) ) {
V_18 |= ( 1 << V_508 ) ;
if ( ! F_89 ( V_5 , V_177 ) )
V_18 |= ( 1 << V_509 ) ;
else
F_85 ( V_5 ) ;
V_18 &= V_505 ;
V_506 = 'c' ;
goto V_346;
}
if ( F_84 ( V_5 ) ) {
V_183 = F_109 ( V_5 -> V_128 -> V_204 ) ;
V_18 = F_255 ( V_183 -> V_510 , V_505 ) ;
F_85 ( V_5 ) ;
if ( V_18 )
V_506 = 'b' ;
}
if ( V_505 & ( 1 << V_508 ) &&
F_92 ( V_294 , & F_22 ( V_5 ) -> V_14 -> V_44 ) ) {
V_18 |= ( 1 << V_508 ) ;
V_506 = V_506 == 'b' ? 'a' : 'n' ;
}
V_346:
V_5 -> V_511 = V_506 ;
return V_18 ;
}
static void F_256 ( struct V_512 * V_497 )
{
F_33 ( & V_497 -> V_513 ) ;
F_194 ( & V_497 -> V_183 ) ;
F_196 ( & V_497 -> V_514 ) ;
}
static int F_257 ( struct V_515 * V_417 , int V_516 )
{
struct V_517 * V_517 =
F_219 ( V_417 , struct V_517 , V_417 ) ;
F_258 ( & V_517 -> V_518 ) ;
return 0 ;
}
void F_259 ( struct V_512 * V_519 )
{
struct V_517 V_517 ;
V_517 . V_417 . V_420 = F_257 ;
F_37 ( & V_517 . V_518 ) ;
F_260 ( V_519 , & V_517 . V_417 ) ;
F_44 ( & V_517 . V_518 ) ;
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
goto V_520;
}
}
V_22 = NULL ;
V_520:
F_49 () ;
return V_22 ;
}
struct V_13 * F_262 ( void * V_521 , int V_522 ,
void * V_523 , int V_524 )
{
struct V_43 * V_22 ;
struct V_13 * V_14 ;
F_46 () ;
F_52 (resource, &drbd_resources) {
F_263 (connection, resource) {
if ( V_14 -> V_522 == V_522 &&
V_14 -> V_524 == V_524 &&
! memcmp ( & V_14 -> V_521 , V_521 , V_522 ) &&
! memcmp ( & V_14 -> V_523 , V_523 , V_524 ) ) {
F_36 ( & V_14 -> V_58 ) ;
goto V_520;
}
}
}
V_14 = NULL ;
V_520:
F_49 () ;
return V_14 ;
}
static int F_264 ( struct V_102 * V_104 )
{
V_104 -> V_525 = ( void * ) F_265 ( V_80 ) ;
if ( ! V_104 -> V_525 )
return - V_475 ;
V_104 -> V_105 = ( void * ) F_265 ( V_80 ) ;
if ( ! V_104 -> V_105 )
return - V_475 ;
return 0 ;
}
static void F_266 ( struct V_102 * V_104 )
{
F_267 ( ( unsigned long ) V_104 -> V_105 ) ;
F_267 ( ( unsigned long ) V_104 -> V_525 ) ;
}
void F_268 ( struct V_13 * V_14 )
{
F_269 ( V_14 ) ;
F_270 ( V_14 -> V_526 ) ;
F_270 ( V_14 -> V_527 ) ;
F_271 ( V_14 -> V_528 ) ;
F_270 ( V_14 -> V_334 ) ;
F_270 ( V_14 -> V_277 ) ;
F_55 ( V_14 -> V_529 ) ;
F_55 ( V_14 -> V_530 ) ;
V_14 -> V_526 = NULL ;
V_14 -> V_527 = NULL ;
V_14 -> V_528 = NULL ;
V_14 -> V_334 = NULL ;
V_14 -> V_277 = NULL ;
V_14 -> V_529 = NULL ;
V_14 -> V_530 = NULL ;
}
int F_272 ( struct V_43 * V_22 , struct V_531 * V_531 )
{
struct V_13 * V_14 ;
T_2 V_532 ;
int V_110 ;
if ( ! F_273 ( & V_532 , V_80 ) )
return - V_475 ;
if ( V_79 > 1 && V_531 -> V_76 [ 0 ] != 0 ) {
V_110 = F_274 ( V_531 -> V_76 , V_533 ,
F_275 ( V_532 ) , V_79 ) ;
if ( V_110 == - V_534 ) {
T_2 V_535 ;
if ( F_273 ( & V_535 , V_80 ) ) {
F_56 ( V_535 ) ;
F_276 ( V_532 , V_532 , V_535 ) ;
F_168 ( V_22 , L_40 ,
V_531 -> V_76 ,
strlen ( V_531 -> V_76 ) > 12 ? L_41 : L_42 ,
V_79 ) ;
F_237 ( V_535 ) ;
V_110 = 0 ;
}
}
if ( V_110 ) {
F_168 ( V_22 , L_43 , V_110 ) ;
goto V_536;
}
}
V_22 -> V_531 = * V_531 ;
if ( F_277 ( V_532 ) )
F_50 ( & V_532 ) ;
if ( ! F_278 ( V_22 -> V_76 , V_532 ) ) {
F_279 ( V_22 -> V_76 , V_532 ) ;
F_263 (connection, resource) {
V_14 -> V_441 . V_65 = 1 ;
V_14 -> V_289 . V_65 = 1 ;
V_14 -> V_487 . V_65 = 1 ;
}
}
V_110 = 0 ;
V_536:
F_237 ( V_532 ) ;
return V_110 ;
}
struct V_43 * F_280 ( const char * V_48 )
{
struct V_43 * V_22 ;
V_22 = F_51 ( sizeof( struct V_43 ) , V_80 ) ;
if ( ! V_22 )
goto V_536;
V_22 -> V_48 = F_281 ( V_48 , V_80 ) ;
if ( ! V_22 -> V_48 )
goto V_537;
if ( ! F_273 ( & V_22 -> V_76 , V_80 ) )
goto V_538;
F_282 ( & V_22 -> V_58 ) ;
F_283 ( & V_22 -> V_498 ) ;
F_194 ( & V_22 -> V_499 ) ;
V_22 -> V_539 = V_540 ;
F_284 ( & V_22 -> V_501 , & V_541 ) ;
F_193 ( & V_22 -> V_542 ) ;
F_193 ( & V_22 -> V_543 ) ;
F_33 ( & V_22 -> V_23 ) ;
F_285 ( V_22 ) ;
return V_22 ;
V_538:
F_55 ( V_22 -> V_48 ) ;
V_537:
F_55 ( V_22 ) ;
V_536:
return NULL ;
}
struct V_13 * F_286 ( const char * V_48 , struct V_531 * V_531 )
{
struct V_43 * V_22 ;
struct V_13 * V_14 ;
V_14 = F_51 ( sizeof( struct V_13 ) , V_80 ) ;
if ( ! V_14 )
return NULL ;
if ( F_264 ( & V_14 -> V_108 ) )
goto V_536;
if ( F_264 ( & V_14 -> V_114 ) )
goto V_536;
V_14 -> V_544 = F_51 ( sizeof( struct V_545 ) , V_80 ) ;
if ( ! V_14 -> V_544 )
goto V_536;
F_194 ( & V_14 -> V_546 ) ;
F_194 ( & V_14 -> V_544 -> V_414 ) ;
V_14 -> V_547 = 1 ;
F_33 ( & V_14 -> V_548 ) ;
V_14 -> V_549 . V_550 = false ;
V_14 -> V_549 . V_551 = 0 ;
V_14 -> V_549 . V_552 = 0 ;
V_22 = F_280 ( V_48 ) ;
if ( ! V_22 )
goto V_536;
V_14 -> V_264 = V_388 ;
F_193 ( & V_14 -> V_553 ) ;
F_196 ( & V_14 -> V_554 ) ;
F_283 ( & V_14 -> V_75 ) ;
F_256 ( & V_14 -> V_457 ) ;
F_193 ( & V_14 -> V_108 . V_106 ) ;
F_193 ( & V_14 -> V_114 . V_106 ) ;
F_31 ( V_22 , & V_14 -> V_441 , V_555 , L_44 ) ;
V_14 -> V_441 . V_14 = V_14 ;
F_31 ( V_22 , & V_14 -> V_487 , V_556 , L_45 ) ;
V_14 -> V_487 . V_14 = V_14 ;
F_31 ( V_22 , & V_14 -> V_289 , V_557 , L_46 ) ;
V_14 -> V_289 . V_14 = V_14 ;
F_282 ( & V_14 -> V_58 ) ;
V_14 -> V_22 = V_22 ;
if ( F_272 ( V_22 , V_531 ) )
goto V_558;
F_36 ( & V_22 -> V_58 ) ;
F_284 ( & V_14 -> V_499 , & V_22 -> V_499 ) ;
F_287 ( V_14 ) ;
return V_14 ;
V_558:
F_240 ( & V_22 -> V_501 ) ;
F_238 ( V_22 ) ;
V_536:
F_55 ( V_14 -> V_544 ) ;
F_266 ( & V_14 -> V_114 ) ;
F_266 ( & V_14 -> V_108 ) ;
F_55 ( V_14 ) ;
return NULL ;
}
void V_59 ( struct V_58 * V_58 )
{
struct V_13 * V_14 = F_219 ( V_58 , struct V_13 , V_58 ) ;
struct V_43 * V_22 = V_14 -> V_22 ;
if ( F_229 ( & V_14 -> V_544 -> V_559 ) != 0 )
F_11 ( V_14 , L_47 , F_229 ( & V_14 -> V_544 -> V_559 ) ) ;
F_55 ( V_14 -> V_544 ) ;
F_236 ( & V_14 -> V_75 ) ;
F_266 ( & V_14 -> V_114 ) ;
F_266 ( & V_14 -> V_108 ) ;
F_55 ( V_14 -> V_529 ) ;
F_55 ( V_14 -> V_530 ) ;
memset ( V_14 , 0xfc , sizeof( * V_14 ) ) ;
F_55 ( V_14 ) ;
F_29 ( & V_22 -> V_58 , V_60 ) ;
}
static int F_288 ( struct V_4 * V_5 )
{
V_5 -> V_560 . V_497 =
F_289 ( L_48 , V_561 , V_5 -> V_74 ) ;
if ( ! V_5 -> V_560 . V_497 )
return - V_475 ;
F_290 ( & V_5 -> V_560 . V_487 , V_562 ) ;
F_194 ( & V_5 -> V_560 . V_488 ) ;
return 0 ;
}
enum V_563 F_291 ( struct V_564 * V_565 , unsigned int V_74 )
{
struct V_43 * V_22 = V_565 -> V_22 ;
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_71 * V_72 , * V_477 ;
struct V_382 * V_11 ;
struct V_182 * V_183 ;
int V_566 ;
int V_73 = V_565 -> V_98 ;
enum V_563 V_110 = V_567 ;
V_5 = F_292 ( V_74 ) ;
if ( V_5 )
return V_568 ;
V_5 = F_51 ( sizeof( struct V_4 ) , V_80 ) ;
if ( ! V_5 )
return V_567 ;
F_282 ( & V_5 -> V_58 ) ;
F_36 ( & V_22 -> V_58 ) ;
V_5 -> V_22 = V_22 ;
V_5 -> V_74 = V_74 ;
V_5 -> V_73 = V_73 ;
F_191 ( V_5 ) ;
V_183 = F_293 ( V_80 ) ;
if ( ! V_183 )
goto V_569;
V_5 -> V_194 = V_183 ;
V_183 -> V_570 = V_5 ;
V_11 = F_294 ( 1 ) ;
if ( ! V_11 )
goto V_571;
V_5 -> V_481 = V_11 ;
F_295 ( V_11 , true ) ;
V_11 -> V_572 = V_183 ;
V_11 -> V_573 = V_502 ;
V_11 -> V_574 = V_74 ;
V_11 -> V_575 = & V_576 ;
sprintf ( V_11 -> V_577 , L_49 , V_74 ) ;
V_11 -> V_373 = V_5 ;
V_5 -> V_210 = F_296 ( F_297 ( V_502 , V_74 ) ) ;
V_5 -> V_210 -> V_578 = V_5 -> V_210 ;
V_183 -> V_510 -> V_579 = F_253 ;
V_183 -> V_510 -> V_504 = V_5 ;
F_298 ( V_183 , V_580 ) ;
F_299 ( V_183 , true , true ) ;
F_300 ( V_183 , V_439 >> 8 ) ;
F_301 ( V_183 , V_581 ) ;
V_183 -> V_582 = & V_22 -> V_23 ;
V_5 -> V_401 . V_295 = F_214 ( V_80 ) ;
if ( ! V_5 -> V_401 . V_295 )
goto V_583;
if ( F_302 ( V_5 ) )
goto V_584;
V_5 -> V_585 = V_586 ;
V_5 -> V_587 = V_586 ;
V_566 = F_303 ( & V_503 , V_5 , V_74 , V_74 + 1 , V_80 ) ;
if ( V_566 < 0 ) {
if ( V_566 == - V_588 )
V_110 = V_568 ;
goto V_589;
}
F_36 ( & V_5 -> V_58 ) ;
V_566 = F_303 ( & V_22 -> V_498 , V_5 , V_73 , V_73 + 1 , V_80 ) ;
if ( V_566 < 0 ) {
if ( V_566 == - V_588 )
V_110 = V_568 ;
goto V_590;
}
F_36 ( & V_5 -> V_58 ) ;
F_194 ( & V_5 -> V_75 ) ;
F_194 ( & V_5 -> V_591 ) ;
F_304 (connection, resource) {
V_72 = F_51 ( sizeof( struct V_71 ) , V_80 ) ;
if ( ! V_72 )
goto V_592;
V_72 -> V_14 = V_14 ;
V_72 -> V_5 = V_5 ;
F_305 ( & V_72 -> V_75 , & V_5 -> V_75 ) ;
F_36 ( & V_5 -> V_58 ) ;
V_566 = F_303 ( & V_14 -> V_75 , V_72 , V_73 , V_73 + 1 , V_80 ) ;
if ( V_566 < 0 ) {
if ( V_566 == - V_588 )
V_110 = V_593 ;
goto V_592;
}
F_36 ( & V_14 -> V_58 ) ;
F_290 ( & V_72 -> V_594 , V_595 ) ;
}
if ( F_288 ( V_5 ) ) {
V_110 = V_567 ;
goto V_596;
}
F_306 ( V_11 ) ;
V_5 -> V_10 . V_32 = F_307 ( V_22 ) -> V_264 ;
if ( V_5 -> V_10 . V_32 == V_265 ) {
F_308 (peer_device, device)
F_309 ( V_72 ) ;
}
F_308 (peer_device, device)
F_310 ( V_72 ) ;
F_311 ( V_5 ) ;
return V_597 ;
V_596:
F_312 ( & V_14 -> V_75 , V_73 ) ;
V_592:
F_304 (connection, resource) {
V_72 = F_312 ( & V_14 -> V_75 , V_73 ) ;
if ( V_72 )
F_29 ( & V_14 -> V_58 , V_59 ) ;
}
F_225 (peer_device, tmp_peer_device, device) {
F_240 ( & V_72 -> V_75 ) ;
F_55 ( V_72 ) ;
}
F_312 ( & V_22 -> V_498 , V_73 ) ;
V_590:
F_312 ( & V_503 , V_74 ) ;
F_313 () ;
V_589:
F_200 ( V_5 ) ;
V_584:
F_205 ( V_5 -> V_401 . V_295 ) ;
V_583:
F_223 ( V_11 ) ;
V_571:
F_224 ( V_183 ) ;
V_569:
F_29 ( & V_22 -> V_58 , V_60 ) ;
F_55 ( V_5 ) ;
return V_110 ;
}
void F_249 ( struct V_4 * V_5 )
{
struct V_43 * V_22 = V_5 -> V_22 ;
struct V_13 * V_14 ;
struct V_71 * V_72 ;
F_308 (peer_device, device)
F_314 ( V_72 ) ;
F_315 ( V_5 ) ;
F_304 (connection, resource) {
F_312 ( & V_14 -> V_75 , V_5 -> V_73 ) ;
F_29 ( & V_5 -> V_58 , F_218 ) ;
}
F_312 ( & V_22 -> V_498 , V_5 -> V_73 ) ;
F_29 ( & V_5 -> V_58 , F_218 ) ;
F_312 ( & V_503 , F_48 ( V_5 ) ) ;
F_29 ( & V_5 -> V_58 , F_218 ) ;
F_316 ( V_5 -> V_481 ) ;
F_313 () ;
F_29 ( & V_5 -> V_58 , F_218 ) ;
}
static int T_8 F_317 ( void )
{
int V_110 ;
if ( V_468 < V_598 || V_468 > V_599 ) {
F_318 ( L_50 , V_468 ) ;
#ifdef F_319
return - V_600 ;
#else
V_468 = V_601 ;
#endif
}
V_110 = F_320 ( V_502 , L_38 ) ;
if ( V_110 ) {
F_318 ( L_51 ,
V_502 ) ;
return V_110 ;
}
F_196 ( & V_602 ) ;
V_500 = NULL ;
F_283 ( & V_503 ) ;
F_193 ( & V_603 ) ;
F_194 ( & V_541 ) ;
V_110 = F_321 () ;
if ( V_110 ) {
F_318 ( L_52 ) ;
goto V_536;
}
V_110 = F_209 () ;
if ( V_110 )
goto V_536;
V_110 = - V_475 ;
V_500 = F_322 ( L_38 , V_604 | V_605 , NULL , & V_606 , NULL ) ;
if ( ! V_500 ) {
F_318 ( L_53 ) ;
goto V_536;
}
V_486 . V_497 = F_323 ( L_54 ) ;
if ( ! V_486 . V_497 ) {
F_318 ( L_55 ) ;
goto V_536;
}
F_290 ( & V_486 . V_487 , F_226 ) ;
F_33 ( & V_486 . V_489 ) ;
F_194 ( & V_486 . V_488 ) ;
if ( F_324 () )
F_325 ( L_56 ) ;
F_252 ( L_57
L_58 V_607 L_59 ,
V_608 , V_609 , V_610 ) ;
F_252 ( L_60 , F_326 () ) ;
F_252 ( L_61 , V_502 ) ;
return 0 ;
V_536:
F_243 () ;
if ( V_110 == - V_475 )
F_318 ( L_62 ) ;
else
F_318 ( L_63 ) ;
return V_110 ;
}
static void F_327 ( struct V_102 * V_611 )
{
struct V_104 * V_24 ;
F_71 ( & V_611 -> V_106 ) ;
V_24 = V_611 -> V_104 ;
V_611 -> V_104 = NULL ;
F_72 ( & V_611 -> V_106 ) ;
if ( V_24 ) {
F_313 () ;
F_328 ( V_24 , V_612 ) ;
F_329 ( V_24 ) ;
}
}
void F_269 ( struct V_13 * V_14 )
{
if ( V_14 -> V_108 . V_104 )
F_327 ( & V_14 -> V_108 ) ;
if ( V_14 -> V_114 . V_104 )
F_327 ( & V_14 -> V_114 ) ;
}
void F_330 ( struct V_13 * V_14 )
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
void F_331 ( struct V_4 * V_5 , void * V_247 )
{
struct V_613 * V_100 = V_247 ;
T_4 V_268 ;
int V_158 ;
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
V_100 -> V_614 = F_90 ( F_113 ( V_5 -> V_210 ) ) ;
for ( V_158 = V_162 ; V_158 < V_163 ; V_158 ++ )
V_100 -> V_164 [ V_158 ] = F_90 ( V_5 -> V_128 -> V_160 . V_164 [ V_158 ] ) ;
V_100 -> V_44 = F_64 ( V_5 -> V_128 -> V_160 . V_44 ) ;
V_100 -> V_92 = F_64 ( V_615 ) ;
V_100 -> V_616 = F_64 ( V_5 -> V_128 -> V_160 . V_616 ) ;
V_100 -> V_617 = F_64 ( V_5 -> V_128 -> V_160 . V_617 ) ;
V_100 -> V_618 = F_64 ( V_5 -> V_478 -> V_619 ) ;
V_100 -> V_620 = F_64 ( V_621 ) ;
V_100 -> V_622 = F_90 ( V_5 -> V_128 -> V_160 . V_622 ) ;
V_100 -> V_623 = F_64 ( V_5 -> V_128 -> V_160 . V_623 ) ;
V_100 -> V_624 = F_64 ( V_5 -> V_438 ) ;
V_100 -> V_625 = F_64 ( V_5 -> V_128 -> V_160 . V_625 ) ;
V_100 -> V_626 = F_64 ( V_5 -> V_128 -> V_160 . V_626 ) ;
F_97 ( V_5 , F_332 ( V_5 -> V_128 ) == V_5 -> V_128 -> V_160 . V_627 ) ;
V_268 = V_5 -> V_128 -> V_160 . V_627 ;
if ( F_333 ( V_5 , V_5 -> V_128 , V_268 , V_628 ) ) {
F_11 ( V_5 , L_64 ) ;
F_334 ( V_5 , 1 , V_629 ) ;
}
}
void F_100 ( struct V_4 * V_5 )
{
struct V_613 * V_100 ;
F_61 ( V_163 != 4 ) ;
F_61 ( sizeof( struct V_613 ) != 4096 ) ;
F_335 ( & V_5 -> V_425 ) ;
if ( ! F_336 ( V_630 , & V_5 -> V_44 ) )
return;
if ( ! F_89 ( V_5 , V_631 ) )
return;
V_100 = F_337 ( V_5 , V_307 ) ;
if ( ! V_100 )
goto V_346;
F_331 ( V_5 , V_100 ) ;
V_5 -> V_128 -> V_160 . V_614 = F_113 ( V_5 -> V_210 ) ;
F_338 ( V_5 ) ;
V_346:
F_85 ( V_5 ) ;
}
static int F_339 ( struct V_4 * V_5 ,
struct V_613 * V_632 ,
struct V_633 * V_634 )
{
T_5 V_625 = F_340 ( V_632 -> V_625 ) ;
T_5 V_626 = F_340 ( V_632 -> V_626 ) ;
T_3 V_635 ;
if ( V_625 == 0 && V_626 == 0 ) {
V_625 = 1 ;
V_626 = V_636 / 8 ;
}
if ( V_625 == 0 || V_626 == 0 )
goto V_110;
V_635 = ( T_3 ) V_625 * V_626 ;
if ( V_635 > ( 16 * 1024 * 1024 / 4 ) )
goto V_110;
if ( V_635 < V_636 / 8 )
goto V_110;
V_634 -> V_626 = V_626 ;
V_634 -> V_625 = V_625 ;
V_634 -> V_635 = V_635 ;
return 0 ;
V_110:
F_11 ( V_5 , L_65 ,
V_625 , V_626 ) ;
return - V_600 ;
}
static int F_341 ( struct V_4 * V_5 , struct V_637 * V_370 )
{
T_4 V_638 = F_113 ( V_370 -> V_639 ) ;
struct V_633 * V_634 = & V_370 -> V_160 ;
T_9 V_640 ;
T_9 V_641 ;
if ( V_634 -> V_617 < 0 ) {
if ( V_634 -> V_623 > V_634 -> V_617 )
goto V_110;
V_640 = - V_634 -> V_617 ;
V_641 = V_634 -> V_617 - V_634 -> V_623 ;
} else {
if ( V_634 -> V_617 != V_642 )
goto V_110;
if ( V_634 -> V_623 < V_634 -> V_617 + V_634 -> V_635 * V_642 )
goto V_110;
V_640 = V_634 -> V_623 - V_642 ;
V_641 = V_634 -> V_616 - V_634 -> V_623 ;
}
if ( V_634 -> V_643 >= 0 ) {
if ( V_634 -> V_616 != V_644
|| V_634 -> V_617 != V_642
|| V_634 -> V_623 != V_642 + V_636
|| V_634 -> V_625 != 1
|| V_634 -> V_626 != V_636 / 8 )
goto V_110;
}
if ( V_638 < V_634 -> V_616 )
goto V_110;
if ( V_638 - V_634 -> V_616 < F_342 ( V_370 ) )
goto V_110;
if ( ( V_640 & 7 ) || ( V_640 < V_636 ) )
goto V_110;
if ( V_640 != V_634 -> V_635 * V_642 )
goto V_110;
if ( V_634 -> V_623 & 7 )
goto V_110;
if ( V_641 < ( V_634 -> V_614 + 7 ) / V_642 / 8 / 512 )
goto V_110;
return 0 ;
V_110:
F_11 ( V_5 , L_66
L_67
L_68 ,
V_634 -> V_643 ,
V_634 -> V_625 , V_634 -> V_626 ,
V_634 -> V_617 , V_634 -> V_623 , V_634 -> V_616 ,
( unsigned long long ) V_634 -> V_614 ,
( unsigned long long ) V_638 ) ;
return - V_600 ;
}
int F_343 ( struct V_4 * V_5 , struct V_637 * V_370 )
{
struct V_613 * V_100 ;
T_5 V_92 , V_44 ;
int V_158 , V_357 = V_597 ;
if ( V_5 -> V_10 . V_11 != V_389 )
return V_645 ;
V_100 = F_337 ( V_5 , V_307 ) ;
if ( ! V_100 )
return V_567 ;
V_370 -> V_160 . V_643 = V_370 -> V_120 -> V_643 ;
V_370 -> V_160 . V_627 = F_332 ( V_370 ) ;
V_370 -> V_160 . V_616 = 8 ;
if ( F_333 ( V_5 , V_370 , V_370 -> V_160 . V_627 ,
V_646 ) ) {
F_11 ( V_5 , L_69 ) ;
V_357 = V_647 ;
goto V_110;
}
V_92 = F_340 ( V_100 -> V_92 ) ;
V_44 = F_340 ( V_100 -> V_44 ) ;
if ( V_92 == V_615 ||
( V_92 == V_648 && ! ( V_44 & V_649 ) ) ) {
F_11 ( V_5 , L_70 ) ;
V_357 = V_650 ;
goto V_110;
}
V_357 = V_651 ;
if ( V_92 != V_648 ) {
if ( V_92 == V_652 )
F_11 ( V_5 , L_71 ) ;
else
F_11 ( V_5 , L_72 ) ;
goto V_110;
}
if ( F_340 ( V_100 -> V_620 ) != V_621 ) {
F_11 ( V_5 , L_73 ,
F_340 ( V_100 -> V_620 ) , V_621 ) ;
goto V_110;
}
V_370 -> V_160 . V_614 = F_344 ( V_100 -> V_614 ) ;
for ( V_158 = V_162 ; V_158 < V_163 ; V_158 ++ )
V_370 -> V_160 . V_164 [ V_158 ] = F_344 ( V_100 -> V_164 [ V_158 ] ) ;
V_370 -> V_160 . V_44 = F_340 ( V_100 -> V_44 ) ;
V_370 -> V_160 . V_622 = F_344 ( V_100 -> V_622 ) ;
V_370 -> V_160 . V_616 = F_340 ( V_100 -> V_616 ) ;
V_370 -> V_160 . V_617 = F_340 ( V_100 -> V_617 ) ;
V_370 -> V_160 . V_623 = F_340 ( V_100 -> V_623 ) ;
if ( F_339 ( V_5 , V_100 , & V_370 -> V_160 ) )
goto V_110;
if ( F_341 ( V_5 , V_370 ) )
goto V_110;
if ( F_340 ( V_100 -> V_623 ) != V_370 -> V_160 . V_623 ) {
F_11 ( V_5 , L_74 ,
F_340 ( V_100 -> V_623 ) , V_370 -> V_160 . V_623 ) ;
goto V_110;
}
if ( F_340 ( V_100 -> V_616 ) != V_370 -> V_160 . V_616 ) {
F_11 ( V_5 , L_75 ,
F_340 ( V_100 -> V_616 ) , V_370 -> V_160 . V_616 ) ;
goto V_110;
}
V_357 = V_597 ;
F_9 ( & V_5 -> V_22 -> V_23 ) ;
if ( V_5 -> V_10 . V_32 < V_272 ) {
unsigned int V_386 ;
V_386 = F_340 ( V_100 -> V_624 ) ;
V_386 = F_345 ( V_386 , V_439 ) ;
V_5 -> V_438 = V_386 ;
}
F_14 ( & V_5 -> V_22 -> V_23 ) ;
V_110:
F_338 ( V_5 ) ;
return V_357 ;
}
void F_346 ( struct V_4 * V_5 , unsigned int line , const char * F_32 )
{
if ( ! F_347 ( V_630 , & V_5 -> V_44 ) ) {
F_348 ( & V_5 -> V_425 , V_653 + V_654 ) ;
V_5 -> V_655 . line = line ;
V_5 -> V_655 . F_32 = F_32 ;
}
}
void F_349 ( struct V_4 * V_5 )
{
if ( ! F_347 ( V_630 , & V_5 -> V_44 ) )
F_348 ( & V_5 -> V_425 , V_653 + 5 * V_654 ) ;
}
void F_350 ( struct V_4 * V_5 ) __must_hold( T_10 )
{
int V_158 ;
for ( V_158 = V_173 ; V_158 < V_174 ; V_158 ++ )
V_5 -> V_128 -> V_160 . V_164 [ V_158 + 1 ] = V_5 -> V_128 -> V_160 . V_164 [ V_158 ] ;
}
void F_351 ( struct V_4 * V_5 , int V_656 , T_3 V_217 ) __must_hold( T_10 )
{
if ( V_656 == V_162 ) {
if ( V_5 -> V_10 . V_375 == V_376 )
V_217 |= 1 ;
else
V_217 &= ~ ( ( T_3 ) 1 ) ;
F_352 ( V_5 , V_217 ) ;
}
V_5 -> V_128 -> V_160 . V_164 [ V_656 ] = V_217 ;
F_349 ( V_5 ) ;
}
void F_353 ( struct V_4 * V_5 , int V_656 , T_3 V_217 ) __must_hold( T_10 )
{
unsigned long V_44 ;
F_24 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
F_351 ( V_5 , V_656 , V_217 ) ;
F_26 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
}
void F_99 ( struct V_4 * V_5 , int V_656 , T_3 V_217 ) __must_hold( T_10 )
{
unsigned long V_44 ;
F_24 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
if ( V_5 -> V_128 -> V_160 . V_164 [ V_656 ] ) {
F_350 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_173 ] = V_5 -> V_128 -> V_160 . V_164 [ V_656 ] ;
}
F_351 ( V_5 , V_656 , V_217 ) ;
F_26 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
}
void F_354 ( struct V_4 * V_5 ) __must_hold( T_10 )
{
T_3 V_217 ;
unsigned long long V_657 ;
F_98 ( & V_217 , sizeof( T_3 ) ) ;
F_9 ( & V_5 -> V_128 -> V_160 . V_161 ) ;
V_657 = V_5 -> V_128 -> V_160 . V_164 [ V_172 ] ;
if ( V_657 )
F_168 ( V_5 , L_76 , V_657 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_172 ] = V_5 -> V_128 -> V_160 . V_164 [ V_162 ] ;
F_351 ( V_5 , V_162 , V_217 ) ;
F_14 ( & V_5 -> V_128 -> V_160 . V_161 ) ;
F_95 ( V_5 , L_77 ) ;
F_100 ( V_5 ) ;
}
void F_355 ( struct V_4 * V_5 , T_3 V_217 ) __must_hold( T_10 )
{
unsigned long V_44 ;
if ( V_5 -> V_128 -> V_160 . V_164 [ V_172 ] == 0 && V_217 == 0 )
return;
F_24 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
if ( V_217 == 0 ) {
F_350 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_173 ] = V_5 -> V_128 -> V_160 . V_164 [ V_172 ] ;
V_5 -> V_128 -> V_160 . V_164 [ V_172 ] = 0 ;
} else {
unsigned long long V_657 = V_5 -> V_128 -> V_160 . V_164 [ V_172 ] ;
if ( V_657 )
F_168 ( V_5 , L_76 , V_657 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_172 ] = V_217 & ~ ( ( T_3 ) 1 ) ;
}
F_26 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
F_349 ( V_5 ) ;
}
int F_356 ( struct V_4 * V_5 ) __must_hold( T_10 )
{
int V_357 = - V_115 ;
F_357 ( V_5 , V_262 ) ;
F_100 ( V_5 ) ;
F_137 ( V_5 ) ;
V_357 = F_138 ( V_5 ) ;
if ( ! V_357 ) {
F_139 ( V_5 , V_262 ) ;
F_100 ( V_5 ) ;
}
return V_357 ;
}
int F_358 ( struct V_4 * V_5 ) __must_hold( T_10 )
{
F_359 ( V_5 ) ;
F_360 ( V_5 ) ;
return F_138 ( V_5 ) ;
}
static int V_423 ( struct V_515 * V_417 , int V_658 )
{
struct V_4 * V_5 =
F_219 ( V_417 , struct V_4 , V_416 . V_417 ) ;
struct V_416 * V_659 = & V_5 -> V_416 ;
int V_357 = - V_115 ;
if ( V_659 -> V_44 != V_660 ) {
int V_661 = F_229 ( & V_5 -> V_392 ) ;
if ( V_661 )
F_11 ( V_5 , L_78 ,
V_661 , V_659 -> V_662 ) ;
}
if ( F_84 ( V_5 ) ) {
F_361 ( V_5 , V_659 -> V_662 , V_659 -> V_44 ) ;
V_357 = V_659 -> V_663 ( V_5 ) ;
F_362 ( V_5 ) ;
F_85 ( V_5 ) ;
}
F_363 ( V_664 , & V_5 -> V_44 ) ;
F_7 ( & V_5 -> V_12 ) ;
if ( V_659 -> V_518 )
V_659 -> V_518 ( V_5 , V_357 ) ;
F_169 ( V_665 , & V_5 -> V_44 ) ;
V_659 -> V_662 = NULL ;
V_659 -> V_44 = 0 ;
return 0 ;
}
void F_364 ( struct V_4 * V_5 ,
int (* V_663)( struct V_4 * ) ,
void (* V_518)( struct V_4 * , int ) ,
char * V_662 , enum V_666 V_44 )
{
F_97 ( V_5 , V_46 == F_22 ( V_5 ) -> V_14 -> V_487 . V_55 ) ;
F_97 ( V_5 , ! F_92 ( V_665 , & V_5 -> V_44 ) ) ;
F_97 ( V_5 , ! F_92 ( V_664 , & V_5 -> V_44 ) ) ;
F_97 ( V_5 , F_202 ( & V_5 -> V_416 . V_417 . V_414 ) ) ;
if ( V_5 -> V_416 . V_662 )
F_11 ( V_5 , L_79 ,
V_662 , V_5 -> V_416 . V_662 ) ;
V_5 -> V_416 . V_663 = V_663 ;
V_5 -> V_416 . V_518 = V_518 ;
V_5 -> V_416 . V_662 = V_662 ;
V_5 -> V_416 . V_44 = V_44 ;
F_9 ( & V_5 -> V_22 -> V_23 ) ;
F_159 ( V_664 , & V_5 -> V_44 ) ;
if ( V_44 == V_660 || F_229 ( & V_5 -> V_392 ) == 0 ) {
if ( ! F_347 ( V_665 , & V_5 -> V_44 ) )
F_260 ( & F_22 ( V_5 ) -> V_14 -> V_457 ,
& V_5 -> V_416 . V_417 ) ;
}
F_14 ( & V_5 -> V_22 -> V_23 ) ;
}
int F_365 ( struct V_4 * V_5 , int (* V_663)( struct V_4 * ) ,
char * V_662 , enum V_666 V_44 )
{
const bool V_667 = V_44 & ( V_668 | V_669 | V_670 ) ;
int V_357 ;
F_97 ( V_5 , V_46 != F_22 ( V_5 ) -> V_14 -> V_487 . V_55 ) ;
if ( V_667 )
F_366 ( V_5 ) ;
F_361 ( V_5 , V_662 , V_44 ) ;
V_357 = V_663 ( V_5 ) ;
F_362 ( V_5 ) ;
if ( V_667 )
F_367 ( V_5 ) ;
return V_357 ;
}
void F_357 ( struct V_4 * V_5 , int V_671 ) __must_hold( T_10 )
{
if ( ( V_5 -> V_128 -> V_160 . V_44 & V_671 ) != V_671 ) {
F_349 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_44 |= V_671 ;
}
}
void F_139 ( struct V_4 * V_5 , int V_671 ) __must_hold( T_10 )
{
if ( ( V_5 -> V_128 -> V_160 . V_44 & V_671 ) != 0 ) {
F_349 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_44 &= ~ V_671 ;
}
}
int F_136 ( struct V_637 * V_370 , int V_671 )
{
return ( V_370 -> V_160 . V_44 & V_671 ) != 0 ;
}
static void V_429 ( unsigned long V_108 )
{
struct V_4 * V_5 = (struct V_4 * ) V_108 ;
F_368 ( V_5 , V_672 ) ;
}
const char * F_369 ( enum V_89 V_90 )
{
static const char * V_673 [] = {
[ V_348 ] = L_80 ,
[ V_347 ] = L_81 ,
[ V_345 ] = L_82 ,
[ V_674 ] = L_83 ,
[ V_675 ] = L_84 ,
[ V_676 ] = L_85 ,
[ V_260 ] = L_86 ,
[ V_677 ] = L_87 ,
[ V_678 ] = L_88 ,
[ V_679 ] = L_89 ,
[ V_680 ] = L_90 ,
[ V_681 ] = L_91 ,
[ V_126 ] = L_92 ,
[ V_125 ] = L_93 ,
[ V_155 ] = L_94 ,
[ V_170 ] = L_95 ,
[ V_212 ] = L_96 ,
[ V_214 ] = L_97 ,
[ V_180 ] = L_98 ,
[ V_682 ] = L_99 ,
[ V_683 ] = L_100 ,
[ V_112 ] = L_101 ,
[ V_113 ] = L_102 ,
[ V_684 ] = L_103 ,
[ V_685 ] = L_104 ,
[ V_686 ] = L_105 ,
[ V_687 ] = L_106 ,
[ V_688 ] = L_107 ,
[ V_689 ] = L_108 ,
[ V_690 ] = L_109 ,
[ V_267 ] = L_110 ,
[ V_219 ] = L_111 ,
[ V_224 ] = L_112 ,
[ V_287 ] = L_113 ,
[ V_691 ] = L_114 ,
[ V_692 ] = L_115 ,
[ V_693 ] = L_116 ,
[ V_694 ] = L_117 ,
[ V_253 ] = L_118 ,
[ V_695 ] = L_119 ,
[ V_349 ] = L_120 ,
[ V_696 ] = L_121 ,
[ V_697 ] = L_122 ,
[ V_220 ] = L_123 ,
[ V_225 ] = L_124 ,
[ V_696 ] = L_125 ,
[ V_698 ] = L_126 ,
[ V_699 ] = L_127 ,
[ V_283 ] = L_128 ,
} ;
if ( V_90 == V_700 )
return L_129 ;
if ( V_90 == V_701 )
return L_130 ;
if ( V_90 == V_702 )
return L_131 ;
if ( V_90 >= F_370 ( V_673 ) )
return L_132 ;
return V_673 [ V_90 ] ;
}
int F_371 ( struct V_4 * V_5 , struct V_703 * V_158 )
{
struct V_118 * V_119 ;
F_372 ( V_67 ) ;
long V_704 ;
F_46 () ;
V_119 = F_83 ( F_22 ( V_5 ) -> V_14 -> V_118 ) ;
if ( ! V_119 ) {
F_49 () ;
return - V_705 ;
}
V_704 = V_119 -> V_290 ? V_119 -> V_704 * V_654 / 10 * V_119 -> V_290 : V_706 ;
F_49 () ;
V_158 -> V_707 = true ;
F_373 ( & V_5 -> V_12 , & V_67 , V_708 ) ;
F_14 ( & V_5 -> V_22 -> V_23 ) ;
V_704 = F_374 ( V_704 ) ;
F_375 ( & V_5 -> V_12 , & V_67 ) ;
F_9 ( & V_5 -> V_22 -> V_23 ) ;
if ( ! V_704 || V_5 -> V_10 . V_32 < V_272 )
return - V_705 ;
if ( F_376 ( V_46 ) )
return - V_709 ;
return 0 ;
}
void F_377 ( void )
{
struct V_43 * V_22 ;
int T_11 V_158 = 0 ;
F_71 ( & V_603 ) ;
F_378 () ;
F_379 (resource, &drbd_resources)
F_380 ( & V_22 -> V_23 , V_158 ++ ) ;
}
void F_381 ( void )
{
struct V_43 * V_22 ;
F_379 (resource, &drbd_resources)
F_382 ( & V_22 -> V_23 ) ;
F_383 () ;
F_72 ( & V_603 ) ;
}
static unsigned long
F_384 ( struct V_710 * V_711 )
{
long V_712 ;
if ( ! V_711 -> V_713 -- ) {
F_98 ( & V_712 , sizeof( V_712 ) ) ;
V_711 -> V_10 += V_712 ;
V_711 -> V_713 = V_714 ;
}
V_711 -> V_10 = V_711 -> V_10 * V_715 + V_716 ;
return F_385 ( V_711 -> V_10 ) ;
}
static char *
F_386 ( unsigned int type ) {
static char * V_717 [] = {
[ V_718 ] = L_133 ,
[ V_719 ] = L_134 ,
[ V_720 ] = L_135 ,
[ V_721 ] = L_136 ,
[ V_722 ] = L_137 ,
[ V_723 ] = L_138 ,
[ V_724 ] = L_139 ,
[ V_725 ] = L_140 ,
[ V_726 ] = L_141 ,
[ V_727 ] = L_142 ,
} ;
return ( type < V_728 ) ? V_717 [ type ] : L_143 ;
}
unsigned int
F_387 ( struct V_4 * V_5 , unsigned int type )
{
static struct V_710 V_729 = { 0 , 0 } ;
unsigned int V_730 = (
( V_731 == 0 ||
( ( 1 << F_48 ( V_5 ) ) & V_731 ) != 0 ) &&
( ( ( F_384 ( & V_729 ) % 100 ) + 1 ) <= V_732 ) ) ;
if ( V_730 ) {
V_733 ++ ;
if ( F_388 ( & V_734 ) )
F_168 ( V_5 , L_144 ,
F_386 ( type ) ) ;
}
return V_730 ;
}
const char * F_326 ( void )
{
static char V_735 [ 38 ] = L_145 ;
if ( V_735 [ 0 ] == 0 ) {
#ifdef F_319
sprintf ( V_735 , L_146 , V_61 -> V_736 ) ;
#else
V_735 [ 0 ] = 'b' ;
#endif
}
return V_735 ;
}
