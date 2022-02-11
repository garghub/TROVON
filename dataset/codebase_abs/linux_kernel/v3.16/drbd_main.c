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
return V_110 ;
}
static int F_76 ( struct V_13 * V_14 , struct V_102 * V_103 ,
enum V_89 V_90 , unsigned int V_107 ,
void * V_108 , unsigned int V_91 )
{
return F_74 ( V_14 , 0 , V_103 , V_90 , V_107 , V_108 , V_91 ) ;
}
int F_77 ( struct V_13 * V_14 , struct V_102 * V_103 ,
enum V_89 V_90 , unsigned int V_107 ,
void * V_108 , unsigned int V_91 )
{
int V_110 ;
V_110 = F_76 ( V_14 , V_103 , V_90 , V_107 , V_108 , V_91 ) ;
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
int F_78 ( struct V_71 * V_72 , struct V_102 * V_103 ,
enum V_89 V_90 , unsigned int V_107 ,
void * V_108 , unsigned int V_91 )
{
int V_110 ;
V_110 = F_74 ( V_72 -> V_14 , V_72 -> V_5 -> V_73 ,
V_103 , V_90 , V_107 , V_108 , V_91 ) ;
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
int F_79 ( struct V_13 * V_14 )
{
struct V_102 * V_103 ;
V_103 = & V_14 -> V_112 ;
if ( ! F_70 ( V_14 , V_103 ) )
return - V_113 ;
return F_77 ( V_14 , V_103 , V_114 , 0 , NULL , 0 ) ;
}
int F_80 ( struct V_13 * V_14 )
{
struct V_102 * V_103 ;
V_103 = & V_14 -> V_112 ;
if ( ! F_70 ( V_14 , V_103 ) )
return - V_113 ;
return F_77 ( V_14 , V_103 , V_115 , 0 , NULL , 0 ) ;
}
int F_81 ( struct V_71 * V_72 )
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
return - V_113 ;
F_46 () ;
V_119 = F_82 ( V_72 -> V_14 -> V_118 ) ;
V_91 = V_117 <= 87 ? sizeof( struct V_122 )
: V_117 == 88 ? sizeof( struct V_122 )
+ strlen ( V_119 -> V_123 ) + 1
: V_117 <= 94 ? sizeof( struct V_124 )
: sizeof( struct V_116 ) ;
V_90 = V_117 >= 89 ? V_125 : V_126 ;
memset ( V_83 -> V_123 , 0 , 2 * V_127 ) ;
if ( F_83 ( V_72 -> V_5 ) ) {
V_121 = F_82 ( V_72 -> V_5 -> V_128 -> V_120 ) ;
V_83 -> V_129 = F_64 ( V_121 -> V_129 ) ;
V_83 -> V_130 = F_64 ( V_121 -> V_130 ) ;
V_83 -> V_131 = F_64 ( V_121 -> V_131 ) ;
V_83 -> V_132 = F_64 ( V_121 -> V_132 ) ;
V_83 -> V_133 = F_64 ( V_121 -> V_133 ) ;
F_84 ( V_72 -> V_5 ) ;
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
return F_78 ( V_72 , V_103 , V_90 , V_91 , NULL , 0 ) ;
}
int F_85 ( struct V_13 * V_14 , enum V_89 V_90 )
{
struct V_102 * V_103 ;
struct V_140 * V_83 ;
struct V_118 * V_119 ;
int V_91 , V_141 ;
V_103 = & V_14 -> V_108 ;
V_83 = F_69 ( V_14 , V_103 ) ;
if ( ! V_83 )
return - V_113 ;
F_46 () ;
V_119 = F_82 ( V_14 -> V_118 ) ;
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
return F_76 ( V_14 , V_103 , V_90 , V_91 , NULL , 0 ) ;
}
int F_86 ( struct V_13 * V_14 )
{
int V_110 ;
F_71 ( & V_14 -> V_108 . V_106 ) ;
V_110 = F_85 ( V_14 , V_155 ) ;
F_72 ( & V_14 -> V_108 . V_106 ) ;
return V_110 ;
}
static int F_87 ( struct V_71 * V_72 , T_3 V_156 )
{
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_102 * V_103 ;
struct V_157 * V_83 ;
int V_158 ;
if ( ! F_88 ( V_5 , V_159 ) )
return 0 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 ) {
F_84 ( V_5 ) ;
return - V_113 ;
}
F_9 ( & V_5 -> V_128 -> V_160 . V_161 ) ;
for ( V_158 = V_162 ; V_158 < V_163 ; V_158 ++ )
V_83 -> V_164 [ V_158 ] = F_89 ( V_5 -> V_128 -> V_160 . V_164 [ V_158 ] ) ;
F_14 ( & V_5 -> V_128 -> V_160 . V_161 ) ;
V_5 -> V_165 = F_90 ( V_5 ) ;
V_83 -> V_164 [ V_163 ] = F_89 ( V_5 -> V_165 ) ;
F_46 () ;
V_156 |= F_82 ( V_72 -> V_14 -> V_118 ) -> V_151 ? 1 : 0 ;
F_49 () ;
V_156 |= F_91 ( V_166 , & V_5 -> V_44 ) ? 2 : 0 ;
V_156 |= V_5 -> V_167 . V_11 == V_168 ? 4 : 0 ;
V_83 -> V_164 [ V_169 ] = F_89 ( V_156 ) ;
F_84 ( V_5 ) ;
return F_78 ( V_72 , V_103 , V_170 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_92 ( struct V_71 * V_72 )
{
return F_87 ( V_72 , 0 ) ;
}
int F_93 ( struct V_71 * V_72 )
{
return F_87 ( V_72 , 8 ) ;
}
void F_94 ( struct V_4 * V_5 , const char * V_171 )
{
if ( F_88 ( V_5 , V_159 ) ) {
T_3 * V_164 = V_5 -> V_128 -> V_160 . V_164 ;
F_25 ( V_5 , L_12 ,
V_171 ,
( unsigned long long ) V_164 [ V_162 ] ,
( unsigned long long ) V_164 [ V_172 ] ,
( unsigned long long ) V_164 [ V_173 ] ,
( unsigned long long ) V_164 [ V_174 ] ) ;
F_84 ( V_5 ) ;
} else {
F_25 ( V_5 , L_13 ,
V_171 ,
( unsigned long long ) V_5 -> V_175 ) ;
}
}
void F_95 ( struct V_71 * V_72 )
{
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_102 * V_103 ;
struct V_176 * V_83 ;
T_3 V_164 ;
F_96 ( V_5 , V_5 -> V_10 . V_11 == V_177 ) ;
V_164 = V_5 -> V_128 -> V_160 . V_164 [ V_172 ] ;
if ( V_164 && V_164 != V_178 )
V_164 = V_164 + V_179 ;
else
F_97 ( & V_164 , sizeof( T_3 ) ) ;
F_98 ( V_5 , V_172 , V_164 ) ;
F_94 ( V_5 , L_14 ) ;
F_99 ( V_5 ) ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( V_83 ) {
V_83 -> V_164 = F_89 ( V_164 ) ;
F_78 ( V_72 , V_103 , V_180 , sizeof( * V_83 ) , NULL , 0 ) ;
}
}
int F_100 ( struct V_71 * V_72 , int V_181 , enum V_182 V_44 )
{
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_102 * V_103 ;
struct V_183 * V_83 ;
T_4 V_184 , V_185 ;
int V_186 ;
unsigned int V_187 ;
if ( F_88 ( V_5 , V_159 ) ) {
F_96 ( V_5 , V_5 -> V_128 -> V_188 ) ;
V_184 = F_101 ( V_5 -> V_128 ) ;
F_46 () ;
V_185 = F_82 ( V_5 -> V_128 -> V_120 ) -> V_189 ;
F_49 () ;
V_186 = F_102 ( V_5 ) ;
V_187 = F_103 ( V_5 -> V_128 -> V_188 -> V_190 -> V_191 ) << 9 ;
V_187 = V_82 ( V_187 , V_192 ) ;
F_84 ( V_5 ) ;
} else {
V_184 = 0 ;
V_185 = 0 ;
V_186 = V_193 ;
V_187 = V_192 ;
}
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_113 ;
if ( V_72 -> V_14 -> V_84 <= 94 )
V_187 = V_82 ( V_187 , V_101 ) ;
else if ( V_72 -> V_14 -> V_84 < 100 )
V_187 = V_82 ( V_187 , V_194 ) ;
V_83 -> V_184 = F_89 ( V_184 ) ;
V_83 -> V_185 = F_89 ( V_185 ) ;
V_83 -> V_195 = F_89 ( V_181 ? 0 : F_104 ( V_5 -> V_196 ) ) ;
V_83 -> V_187 = F_64 ( V_187 ) ;
V_83 -> V_197 = F_65 ( V_186 ) ;
V_83 -> V_182 = F_65 ( V_44 ) ;
return F_78 ( V_72 , V_103 , V_198 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_105 ( struct V_71 * V_72 )
{
struct V_102 * V_103 ;
struct V_199 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_113 ;
V_83 -> V_10 = F_64 ( V_72 -> V_5 -> V_10 . V_158 ) ;
return F_78 ( V_72 , V_103 , V_200 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_106 ( struct V_71 * V_72 , union V_201 V_10 )
{
struct V_102 * V_103 ;
struct V_199 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_113 ;
V_83 -> V_10 = F_64 ( V_10 . V_158 ) ;
return F_78 ( V_72 , V_103 , V_200 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_107 ( struct V_71 * V_72 , union V_201 V_202 , union V_201 V_203 )
{
struct V_102 * V_103 ;
struct V_204 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_113 ;
V_83 -> V_202 = F_64 ( V_202 . V_158 ) ;
V_83 -> V_203 = F_64 ( V_203 . V_158 ) ;
return F_78 ( V_72 , V_103 , V_205 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_108 ( struct V_13 * V_14 , union V_201 V_202 , union V_201 V_203 )
{
enum V_89 V_90 ;
struct V_102 * V_103 ;
struct V_204 * V_83 ;
V_90 = V_14 -> V_84 < 100 ? V_205 : V_206 ;
V_103 = & V_14 -> V_108 ;
V_83 = F_70 ( V_14 , V_103 ) ;
if ( ! V_83 )
return - V_113 ;
V_83 -> V_202 = F_64 ( V_202 . V_158 ) ;
V_83 -> V_203 = F_64 ( V_203 . V_158 ) ;
return F_77 ( V_14 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
void F_109 ( struct V_71 * V_72 , enum V_207 V_208 )
{
struct V_102 * V_103 ;
struct V_209 * V_83 ;
V_103 = & V_72 -> V_14 -> V_112 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( V_83 ) {
V_83 -> V_208 = F_64 ( V_208 ) ;
F_78 ( V_72 , V_103 , V_210 , sizeof( * V_83 ) , NULL , 0 ) ;
}
}
void F_110 ( struct V_13 * V_14 , enum V_207 V_208 )
{
struct V_102 * V_103 ;
struct V_209 * V_83 ;
enum V_89 V_90 = V_14 -> V_84 < 100 ? V_210 : V_211 ;
V_103 = & V_14 -> V_112 ;
V_83 = F_70 ( V_14 , V_103 ) ;
if ( V_83 ) {
V_83 -> V_208 = F_64 ( V_208 ) ;
F_77 ( V_14 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
}
static void F_111 ( struct V_212 * V_83 , enum V_213 V_214 )
{
F_112 ( V_214 & ~ 0xf ) ;
V_83 -> V_215 = ( V_83 -> V_215 & ~ 0xf ) | V_214 ;
}
static void F_113 ( struct V_212 * V_83 , int V_216 )
{
V_83 -> V_215 = ( V_83 -> V_215 & ~ 0x80 ) | ( V_216 ? 0x80 : 0 ) ;
}
static void F_114 ( struct V_212 * V_83 , int V_217 )
{
F_112 ( V_217 & ~ 0x7 ) ;
V_83 -> V_215 = ( V_83 -> V_215 & ( ~ 0x7 << 4 ) ) | ( V_217 << 4 ) ;
}
static int F_115 ( struct V_4 * V_5 ,
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
V_228 = F_82 ( F_22 ( V_5 ) -> V_14 -> V_118 ) -> V_228 ;
F_49 () ;
if ( ! V_228 || F_22 ( V_5 ) -> V_14 -> V_84 < 90 )
return 0 ;
if ( V_219 -> V_229 >= V_219 -> V_230 )
return 0 ;
F_116 ( & V_221 , V_83 -> V_214 , V_91 , 0 ) ;
memset ( V_83 -> V_214 , 0 , V_91 ) ;
V_222 = 0 ;
V_226 = 2 ;
do {
V_223 = ( V_226 == 0 ) ? F_117 ( V_5 , V_219 -> V_229 )
: F_118 ( V_5 , V_219 -> V_229 ) ;
if ( V_223 == - 1UL )
V_223 = V_219 -> V_230 ;
V_224 = V_223 - V_219 -> V_229 ;
if ( V_226 == 2 ) {
if ( V_224 == 0 ) {
F_113 ( V_83 , 1 ) ;
V_226 = ! V_226 ;
continue;
}
F_113 ( V_83 , 0 ) ;
}
if ( V_224 == 0 ) {
F_11 ( V_5 , L_15
L_16 , V_226 , V_219 -> V_229 ) ;
return - 1 ;
}
V_227 = F_119 ( & V_221 , V_224 ) ;
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
F_120 ( V_219 ) ;
V_219 -> V_229 = V_219 -> V_235 * V_236 ;
return 0 ;
}
F_120 ( V_219 ) ;
F_114 ( V_83 , ( 8 - V_221 . V_232 . V_234 ) & 0x7 ) ;
return V_225 ;
}
static int
F_121 ( struct V_4 * V_5 , struct V_218 * V_219 )
{
struct V_102 * V_103 = & F_22 ( V_5 ) -> V_14 -> V_108 ;
unsigned int V_107 = F_60 ( F_22 ( V_5 ) -> V_14 ) ;
struct V_212 * V_83 = V_103 -> V_105 + V_107 ;
int V_225 , V_110 ;
V_225 = F_115 ( V_5 , V_83 ,
V_237 - V_107 - sizeof( * V_83 ) , V_219 ) ;
if ( V_225 < 0 )
return - V_113 ;
if ( V_225 ) {
F_111 ( V_83 , V_238 ) ;
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
V_243 = F_122 ( V_244 , V_242 / sizeof( * V_83 ) ,
V_219 -> V_245 - V_219 -> V_235 ) ;
V_225 = V_243 * sizeof( * V_83 ) ;
if ( V_225 )
F_123 ( V_5 , V_219 -> V_235 , V_243 , V_83 ) ;
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
F_124 ( V_5 , L_18 , V_219 ) ;
return 0 ;
} else
return 1 ;
}
return - V_113 ;
}
static int F_125 ( struct V_4 * V_5 )
{
struct V_218 V_219 ;
int V_110 ;
if ( ! F_126 ( V_5 -> V_247 ) )
return false ;
if ( F_83 ( V_5 ) ) {
if ( F_127 ( V_5 -> V_128 , V_248 ) ) {
F_25 ( V_5 , L_19 ) ;
F_128 ( V_5 ) ;
if ( F_129 ( V_5 ) ) {
F_11 ( V_5 , L_20 ) ;
} else {
F_130 ( V_5 , V_248 ) ;
F_99 ( V_5 ) ;
}
}
F_84 ( V_5 ) ;
}
V_219 = (struct V_218 ) {
. V_230 = F_131 ( V_5 ) ,
. V_245 = F_132 ( V_5 ) ,
} ;
do {
V_110 = F_121 ( V_5 , & V_219 ) ;
} while ( V_110 > 0 );
return V_110 == 0 ;
}
int F_133 ( struct V_4 * V_5 )
{
struct V_102 * V_103 = & F_22 ( V_5 ) -> V_14 -> V_108 ;
int V_110 = - 1 ;
F_71 ( & V_103 -> V_106 ) ;
if ( V_103 -> V_104 )
V_110 = ! F_125 ( V_5 ) ;
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
void F_134 ( struct V_13 * V_14 , T_5 V_15 , T_5 V_16 )
{
struct V_102 * V_103 ;
struct V_249 * V_83 ;
if ( V_14 -> V_250 < V_251 )
return;
V_103 = & V_14 -> V_112 ;
V_83 = F_70 ( V_14 , V_103 ) ;
if ( ! V_83 )
return;
V_83 -> V_252 = V_15 ;
V_83 -> V_16 = F_64 ( V_16 ) ;
F_77 ( V_14 , V_103 , V_253 , sizeof( * V_83 ) , NULL , 0 ) ;
}
static int F_135 ( struct V_71 * V_72 , enum V_89 V_90 ,
T_3 V_254 , T_5 V_255 , T_3 V_256 )
{
struct V_102 * V_103 ;
struct V_257 * V_83 ;
if ( V_72 -> V_5 -> V_10 . V_32 < V_258 )
return - V_113 ;
V_103 = & V_72 -> V_14 -> V_112 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_113 ;
V_83 -> V_254 = V_254 ;
V_83 -> V_256 = V_256 ;
V_83 -> V_255 = V_255 ;
V_83 -> V_259 = F_64 ( F_136 ( & V_72 -> V_5 -> V_260 ) ) ;
return F_78 ( V_72 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
void F_137 ( struct V_71 * V_72 , enum V_89 V_90 ,
struct V_261 * V_262 , int V_242 )
{
if ( V_72 -> V_14 -> V_263 )
V_242 -= F_138 ( V_72 -> V_14 -> V_263 ) ;
F_135 ( V_72 , V_90 , V_262 -> V_254 , F_64 ( V_242 ) ,
V_262 -> V_256 ) ;
}
void F_139 ( struct V_71 * V_72 , enum V_89 V_90 ,
struct V_264 * V_265 )
{
F_135 ( V_72 , V_90 , V_265 -> V_254 , V_265 -> V_255 , V_265 -> V_256 ) ;
}
int F_140 ( struct V_71 * V_72 , enum V_89 V_90 ,
struct V_266 * V_267 )
{
return F_135 ( V_72 , V_90 ,
F_89 ( V_267 -> V_158 . V_254 ) ,
F_64 ( V_267 -> V_158 . V_91 ) ,
V_267 -> V_256 ) ;
}
int F_141 ( struct V_71 * V_72 , enum V_89 V_90 ,
T_4 V_254 , int V_255 , T_3 V_256 )
{
return F_135 ( V_72 , V_90 ,
F_89 ( V_254 ) ,
F_64 ( V_255 ) ,
F_89 ( V_256 ) ) ;
}
int F_142 ( struct V_71 * V_72 , int V_90 ,
T_4 V_254 , int V_91 , T_3 V_256 )
{
struct V_102 * V_103 ;
struct V_264 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_113 ;
V_83 -> V_254 = F_89 ( V_254 ) ;
V_83 -> V_256 = V_256 ;
V_83 -> V_255 = F_64 ( V_91 ) ;
return F_78 ( V_72 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_143 ( struct V_71 * V_72 , T_4 V_254 , int V_91 ,
void * V_268 , int V_269 , enum V_89 V_90 )
{
struct V_102 * V_103 ;
struct V_264 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_113 ;
V_83 -> V_254 = F_89 ( V_254 ) ;
V_83 -> V_256 = V_270 ;
V_83 -> V_255 = F_64 ( V_91 ) ;
return F_78 ( V_72 , V_103 , V_90 , sizeof( * V_83 ) , V_268 , V_269 ) ;
}
int F_144 ( struct V_71 * V_72 , T_4 V_254 , int V_91 )
{
struct V_102 * V_103 ;
struct V_264 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_113 ;
V_83 -> V_254 = F_89 ( V_254 ) ;
V_83 -> V_256 = V_270 ;
V_83 -> V_255 = F_64 ( V_91 ) ;
return F_78 ( V_72 , V_103 , V_271 , sizeof( * V_83 ) , NULL , 0 ) ;
}
static int F_145 ( struct V_13 * V_14 , struct V_104 * V_103 )
{
int V_272 ;
V_272 = V_14 -> V_112 . V_104 == V_103
|| ! V_14 -> V_273 . V_55
|| F_146 ( & V_14 -> V_273 ) != V_54
|| V_14 -> V_250 < V_251 ;
if ( V_272 )
return true ;
V_272 = ! -- V_14 -> V_274 ;
if ( ! V_272 ) {
F_11 ( V_14 , L_21 ,
V_46 -> V_47 , V_46 -> V_64 , V_14 -> V_274 ) ;
F_147 ( V_14 ) ;
}
return V_272 ; ;
}
static void F_148 ( struct V_13 * V_14 )
{
struct V_103 * V_275 = V_14 -> V_108 . V_104 -> V_275 ;
if ( V_275 -> V_276 > V_275 -> V_277 * 4 / 5 )
F_149 ( V_278 , & V_14 -> V_44 ) ;
}
static int F_150 ( struct V_71 * V_72 , struct V_279 * V_279 ,
int V_280 , V_244 V_91 , unsigned V_109 )
{
struct V_104 * V_104 ;
void * V_281 ;
int V_110 ;
V_104 = V_72 -> V_14 -> V_108 . V_104 ;
V_281 = F_151 ( V_279 ) + V_280 ;
V_110 = F_75 ( V_72 -> V_14 , V_104 , V_281 , V_91 , V_109 ) ;
F_152 ( V_279 ) ;
if ( ! V_110 )
V_72 -> V_5 -> V_282 += V_91 >> 9 ;
return V_110 ;
}
static int F_153 ( struct V_71 * V_72 , struct V_279 * V_279 ,
int V_280 , V_244 V_91 , unsigned V_109 )
{
struct V_104 * V_104 = V_72 -> V_14 -> V_108 . V_104 ;
T_6 V_283 = F_154 () ;
int V_225 = V_91 ;
int V_110 = - V_113 ;
if ( V_284 || ( F_155 ( V_279 ) < 1 ) || F_156 ( V_279 ) )
return F_150 ( V_72 , V_279 , V_280 , V_91 , V_109 ) ;
V_109 |= V_285 ;
F_148 ( V_72 -> V_14 ) ;
F_157 ( V_286 ) ;
do {
int V_287 ;
V_287 = V_104 -> V_288 -> V_289 ( V_104 , V_279 , V_280 , V_225 , V_109 ) ;
if ( V_287 <= 0 ) {
if ( V_287 == - V_290 ) {
if ( F_145 ( V_72 -> V_14 , V_104 ) )
break;
continue;
}
F_158 ( V_72 -> V_5 , L_22 ,
V_291 , ( int ) V_91 , V_225 , V_287 ) ;
if ( V_287 < 0 )
V_110 = V_287 ;
break;
}
V_225 -= V_287 ;
V_280 += V_287 ;
} while ( V_225 > 0 );
F_157 ( V_283 ) ;
F_159 ( V_278 , & V_72 -> V_14 -> V_44 ) ;
if ( V_225 == 0 ) {
V_110 = 0 ;
V_72 -> V_5 -> V_282 += V_91 >> 9 ;
}
return V_110 ;
}
static int F_160 ( struct V_71 * V_72 , struct V_1 * V_1 )
{
struct V_292 V_293 ;
struct V_294 V_295 ;
F_161 (bvec, bio, iter) {
int V_110 ;
V_110 = F_150 ( V_72 , V_293 . V_296 ,
V_293 . V_297 , V_293 . V_298 ,
F_162 ( V_293 , V_295 )
? 0 : V_111 ) ;
if ( V_110 )
return V_110 ;
}
return 0 ;
}
static int F_163 ( struct V_71 * V_72 , struct V_1 * V_1 )
{
struct V_292 V_293 ;
struct V_294 V_295 ;
F_161 (bvec, bio, iter) {
int V_110 ;
V_110 = F_153 ( V_72 , V_293 . V_296 ,
V_293 . V_297 , V_293 . V_298 ,
F_162 ( V_293 , V_295 ) ? 0 : V_111 ) ;
if ( V_110 )
return V_110 ;
}
return 0 ;
}
static int F_164 ( struct V_71 * V_72 ,
struct V_266 * V_267 )
{
struct V_279 * V_279 = V_267 -> V_299 ;
unsigned V_225 = V_267 -> V_158 . V_91 ;
int V_110 ;
F_165 (page) {
unsigned V_300 = F_122 ( unsigned , V_225 , V_301 ) ;
V_110 = F_153 ( V_72 , V_279 , 0 , V_300 ,
F_166 ( V_279 ) ? V_111 : 0 ) ;
if ( V_110 )
return V_110 ;
V_225 -= V_300 ;
}
return 0 ;
}
static T_5 F_167 ( struct V_13 * V_14 , unsigned long V_302 )
{
if ( V_14 -> V_84 >= 95 )
return ( V_302 & V_303 ? V_304 : 0 ) |
( V_302 & V_305 ? V_306 : 0 ) |
( V_302 & V_307 ? V_308 : 0 ) |
( V_302 & V_309 ? V_310 : 0 ) ;
else
return V_302 & V_303 ? V_304 : 0 ;
}
int F_168 ( struct V_71 * V_72 , struct V_17 * V_19 )
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
F_138 ( V_72 -> V_14 -> V_313 ) : 0 ;
if ( ! V_83 )
return - V_113 ;
V_83 -> V_254 = F_89 ( V_19 -> V_158 . V_254 ) ;
V_83 -> V_256 = ( unsigned long ) V_19 ;
V_83 -> V_259 = F_64 ( F_136 ( & V_5 -> V_260 ) ) ;
V_311 = F_167 ( V_72 -> V_14 , V_19 -> V_314 -> V_302 ) ;
if ( V_5 -> V_10 . V_32 >= V_315 &&
V_5 -> V_10 . V_32 <= V_316 )
V_311 |= V_317 ;
if ( V_72 -> V_14 -> V_84 >= 100 ) {
if ( V_19 -> V_25 & V_318 )
V_311 |= V_319 ;
if ( V_19 -> V_25 & V_320 )
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
F_169 ( V_72 -> V_14 -> V_313 , V_19 -> V_314 , V_83 + 1 ) ;
V_110 = F_74 ( V_72 -> V_14 , V_5 -> V_73 , V_103 , V_326 , sizeof( * V_83 ) + V_312 , NULL , V_19 -> V_158 . V_91 ) ;
if ( ! V_110 ) {
if ( ! ( V_19 -> V_25 & ( V_318 | V_320 ) ) || V_312 )
V_110 = F_160 ( V_72 , V_19 -> V_314 ) ;
else
V_110 = F_163 ( V_72 , V_19 -> V_314 ) ;
if ( V_312 > 0 && V_312 <= 64 ) {
unsigned char V_268 [ 64 ] ;
F_169 ( V_72 -> V_14 -> V_313 , V_19 -> V_314 , V_268 ) ;
if ( memcmp ( V_83 + 1 , V_268 , V_312 ) ) {
F_158 ( V_5 ,
L_23 ,
( unsigned long long ) V_19 -> V_158 . V_254 , V_19 -> V_158 . V_91 ) ;
}
}
}
V_325:
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
int F_170 ( struct V_71 * V_72 , enum V_89 V_90 ,
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
F_138 ( V_72 -> V_14 -> V_313 ) : 0 ;
if ( ! V_83 )
return - V_113 ;
V_83 -> V_254 = F_89 ( V_267 -> V_158 . V_254 ) ;
V_83 -> V_256 = V_267 -> V_256 ;
V_83 -> V_259 = 0 ;
V_83 -> V_311 = 0 ;
if ( V_312 )
F_171 ( V_72 -> V_14 -> V_313 , V_267 , V_83 + 1 ) ;
V_110 = F_74 ( V_72 -> V_14 , V_5 -> V_73 , V_103 , V_90 , sizeof( * V_83 ) + V_312 , NULL , V_267 -> V_158 . V_91 ) ;
if ( ! V_110 )
V_110 = F_164 ( V_72 , V_267 ) ;
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
int F_172 ( struct V_71 * V_72 , struct V_17 * V_19 )
{
struct V_102 * V_103 ;
struct V_327 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_113 ;
V_83 -> V_254 = F_89 ( V_19 -> V_158 . V_254 ) ;
V_83 -> V_255 = F_64 ( V_19 -> V_158 . V_91 ) ;
return F_78 ( V_72 , V_103 , V_328 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_173 ( struct V_13 * V_14 , struct V_104 * V_103 ,
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
V_14 -> V_274 = F_82 ( V_14 -> V_118 ) -> V_274 ;
F_49 () ;
F_148 ( V_14 ) ;
}
do {
V_334 = F_174 ( V_103 , & V_333 , & V_331 , 1 , V_91 ) ;
if ( V_334 == - V_290 ) {
if ( F_145 ( V_14 , V_103 ) )
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
F_159 ( V_278 , & V_14 -> V_44 ) ;
if ( V_334 <= 0 ) {
if ( V_334 != - V_290 ) {
F_11 ( V_14 , L_24 ,
V_103 == V_14 -> V_112 . V_104 ? L_25 : L_26 ,
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
V_110 = F_173 ( V_14 , V_103 , V_100 , V_91 , V_109 ) ;
if ( V_110 < 0 )
return V_110 ;
if ( V_110 != V_91 )
return - V_113 ;
return 0 ;
}
static int F_175 ( struct V_345 * V_346 , T_7 V_347 )
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
static void F_176 ( struct V_357 * V_358 , T_7 V_347 )
{
struct V_4 * V_5 = V_358 -> V_348 ;
F_71 ( & V_349 ) ;
V_5 -> V_356 -- ;
F_72 ( & V_349 ) ;
}
static void F_177 ( struct V_4 * V_5 )
{
V_5 -> V_10 = (union V_359 ) {
{ . V_350 = V_360 ,
. V_361 = V_362 ,
. V_32 = V_363 ,
. V_11 = V_364 ,
. V_365 = V_366 ,
} } ;
}
void F_178 ( struct V_4 * V_5 )
{
F_177 ( V_5 ) ;
F_179 ( & V_5 -> V_367 , 0 ) ;
F_179 ( & V_5 -> V_368 , 0 ) ;
F_179 ( & V_5 -> V_369 , 0 ) ;
F_179 ( & V_5 -> V_370 , 0 ) ;
F_179 ( & V_5 -> V_9 , 0 ) ;
F_179 ( & V_5 -> V_371 , 0 ) ;
F_179 ( & V_5 -> V_372 , 0 ) ;
F_179 ( & V_5 -> V_373 , 0 ) ;
F_179 ( & V_5 -> V_374 , 0 ) ;
F_179 ( & V_5 -> V_375 , 0 ) ;
F_180 ( & V_5 -> V_376 ) ;
V_5 -> V_377 = & V_5 -> V_376 ;
F_33 ( & V_5 -> V_378 ) ;
F_33 ( & V_5 -> V_379 ) ;
F_181 ( & V_5 -> V_380 ) ;
F_181 ( & V_5 -> V_381 ) ;
F_181 ( & V_5 -> V_382 ) ;
F_181 ( & V_5 -> V_383 ) ;
F_181 ( & V_5 -> V_384 ) ;
F_181 ( & V_5 -> V_385 ) ;
F_181 ( & V_5 -> V_386 . V_387 ) ;
F_181 ( & V_5 -> V_388 . V_387 ) ;
F_181 ( & V_5 -> V_389 . V_387 ) ;
F_181 ( & V_5 -> V_390 . V_387 ) ;
F_181 ( & V_5 -> V_391 . V_387 ) ;
F_181 ( & V_5 -> V_392 . V_393 . V_387 ) ;
V_5 -> V_386 . V_394 = V_395 ;
V_5 -> V_388 . V_394 = V_396 ;
V_5 -> V_389 . V_394 = V_397 ;
V_5 -> V_390 . V_394 = V_398 ;
V_5 -> V_392 . V_393 . V_394 = V_399 ;
V_5 -> V_391 . V_394 = V_400 ;
F_182 ( & V_5 -> V_401 ) ;
F_182 ( & V_5 -> V_402 ) ;
F_182 ( & V_5 -> V_403 ) ;
F_182 ( & V_5 -> V_404 ) ;
V_5 -> V_401 . V_50 = V_405 ;
V_5 -> V_401 . V_108 = ( unsigned long ) V_5 ;
V_5 -> V_402 . V_50 = V_406 ;
V_5 -> V_402 . V_108 = ( unsigned long ) V_5 ;
V_5 -> V_403 . V_50 = V_407 ;
V_5 -> V_403 . V_108 = ( unsigned long ) V_5 ;
V_5 -> V_404 . V_50 = V_408 ;
V_5 -> V_404 . V_108 = ( unsigned long ) V_5 ;
F_183 ( & V_5 -> V_12 ) ;
F_183 ( & V_5 -> V_409 ) ;
F_183 ( & V_5 -> V_410 ) ;
F_183 ( & V_5 -> V_411 ) ;
F_183 ( & V_5 -> V_412 ) ;
V_5 -> V_413 = V_414 ;
V_5 -> V_415 = V_416 ;
V_5 -> V_417 = V_416 ;
}
void F_184 ( struct V_4 * V_5 )
{
int V_158 ;
if ( F_22 ( V_5 ) -> V_14 -> V_418 . V_52 != V_56 )
F_11 ( V_5 , L_27 ,
F_22 ( V_5 ) -> V_14 -> V_418 . V_52 ) ;
V_5 -> V_419 =
V_5 -> V_420 =
V_5 -> V_421 =
V_5 -> V_422 =
V_5 -> V_282 =
V_5 -> V_423 =
V_5 -> V_424 =
V_5 -> V_425 =
V_5 -> V_426 =
V_5 -> V_427 = 0 ;
V_5 -> V_428 = 0 ;
V_5 -> V_429 = 0 ;
for ( V_158 = 0 ; V_158 < V_430 ; V_158 ++ ) {
V_5 -> V_431 [ V_158 ] = 0 ;
V_5 -> V_432 [ V_158 ] = 0 ;
}
F_96 ( V_5 , F_22 ( V_5 ) -> V_14 -> V_118 == NULL ) ;
F_185 ( V_5 , 0 ) ;
if ( V_5 -> V_247 ) {
F_186 ( V_5 , 0 , 1 ) ;
F_187 ( V_5 ) ;
}
F_188 ( V_5 -> V_128 ) ;
V_5 -> V_128 = NULL ;
F_159 ( V_433 , & V_5 -> V_44 ) ;
F_96 ( V_5 , F_189 ( & V_5 -> V_380 ) ) ;
F_96 ( V_5 , F_189 ( & V_5 -> V_381 ) ) ;
F_96 ( V_5 , F_189 ( & V_5 -> V_382 ) ) ;
F_96 ( V_5 , F_189 ( & V_5 -> V_383 ) ) ;
F_96 ( V_5 , F_189 ( & V_5 -> V_384 ) ) ;
F_96 ( V_5 , F_189 ( & V_5 -> V_385 ) ) ;
F_96 ( V_5 , F_189 ( & F_22 ( V_5 ) -> V_14 -> V_434 . V_435 ) ) ;
F_96 ( V_5 , F_189 ( & V_5 -> V_386 . V_387 ) ) ;
F_96 ( V_5 , F_189 ( & V_5 -> V_388 . V_387 ) ) ;
F_96 ( V_5 , F_189 ( & V_5 -> V_389 . V_387 ) ) ;
F_177 ( V_5 ) ;
}
static void F_190 ( void )
{
struct V_279 * V_279 ;
while ( V_436 ) {
V_279 = V_436 ;
V_436 = (struct V_279 * ) F_191 ( V_279 ) ;
F_192 ( V_279 ) ;
V_437 -- ;
}
if ( V_3 )
F_193 ( V_3 ) ;
if ( V_438 )
F_194 ( V_438 ) ;
if ( V_439 )
F_194 ( V_439 ) ;
if ( V_440 )
F_194 ( V_440 ) ;
if ( V_441 )
F_195 ( V_441 ) ;
if ( V_442 )
F_195 ( V_442 ) ;
if ( V_443 )
F_195 ( V_443 ) ;
if ( V_444 )
F_195 ( V_444 ) ;
V_3 = NULL ;
V_438 = NULL ;
V_439 = NULL ;
V_440 = NULL ;
V_441 = NULL ;
V_442 = NULL ;
V_443 = NULL ;
V_444 = NULL ;
return;
}
static int F_196 ( void )
{
struct V_279 * V_279 ;
const int V_445 = ( V_192 / V_301 ) * V_446 ;
int V_158 ;
V_440 = NULL ;
V_441 = NULL ;
V_442 = NULL ;
V_443 = NULL ;
V_444 = NULL ;
V_436 = NULL ;
V_438 = NULL ;
V_3 = NULL ;
V_442 = F_197 (
L_28 , sizeof( struct V_17 ) , 0 , 0 , NULL ) ;
if ( V_442 == NULL )
goto V_447;
V_441 = F_197 (
L_29 , sizeof( struct V_266 ) , 0 , 0 , NULL ) ;
if ( V_441 == NULL )
goto V_447;
V_443 = F_197 (
L_30 , sizeof( struct V_448 ) , 0 , 0 , NULL ) ;
if ( V_443 == NULL )
goto V_447;
V_444 = F_197 (
L_31 , sizeof( struct V_449 ) , 0 , 0 , NULL ) ;
if ( V_444 == NULL )
goto V_447;
V_3 = F_198 ( V_450 , 0 ) ;
if ( V_3 == NULL )
goto V_447;
V_438 = F_199 ( V_450 , 0 ) ;
if ( V_438 == NULL )
goto V_447;
V_440 = F_200 ( V_445 ,
V_451 , V_452 , V_442 ) ;
if ( V_440 == NULL )
goto V_447;
V_439 = F_200 ( V_445 ,
V_451 , V_452 , V_441 ) ;
if ( V_439 == NULL )
goto V_447;
F_33 ( & V_453 ) ;
for ( V_158 = 0 ; V_158 < V_445 ; V_158 ++ ) {
V_279 = F_201 ( V_454 ) ;
if ( ! V_279 )
goto V_447;
F_202 ( V_279 , ( unsigned long ) V_436 ) ;
V_436 = V_279 ;
}
V_437 = V_445 ;
return 0 ;
V_447:
F_190 () ;
return - V_455 ;
}
static int F_203 ( struct V_456 * V_457 , unsigned long V_214 ,
void * V_458 )
{
return V_459 ;
}
static void F_204 ( struct V_4 * V_5 )
{
int V_460 ;
V_460 = F_205 ( V_5 , & V_5 -> V_380 ) ;
if ( V_460 )
F_11 ( V_5 , L_32 , V_460 ) ;
V_460 = F_205 ( V_5 , & V_5 -> V_381 ) ;
if ( V_460 )
F_11 ( V_5 , L_33 , V_460 ) ;
V_460 = F_205 ( V_5 , & V_5 -> V_383 ) ;
if ( V_460 )
F_11 ( V_5 , L_34 , V_460 ) ;
V_460 = F_205 ( V_5 , & V_5 -> V_382 ) ;
if ( V_460 )
F_11 ( V_5 , L_35 , V_460 ) ;
V_460 = F_205 ( V_5 , & V_5 -> V_384 ) ;
if ( V_460 )
F_11 ( V_5 , L_36 , V_460 ) ;
}
void F_206 ( struct V_58 * V_58 )
{
struct V_4 * V_5 = F_207 ( V_58 , struct V_4 , V_58 ) ;
struct V_43 * V_22 = V_5 -> V_22 ;
struct V_13 * V_14 ;
F_208 ( & V_5 -> V_404 ) ;
F_96 ( V_5 , V_5 -> V_356 == 0 ) ;
if ( V_5 -> V_196 )
F_209 ( V_5 -> V_196 ) ;
F_188 ( V_5 -> V_128 ) ;
V_5 -> V_128 = NULL ;
F_204 ( V_5 ) ;
F_210 ( V_5 -> V_461 ) ;
F_210 ( V_5 -> V_462 ) ;
F_55 ( V_5 -> V_463 ) ;
if ( V_5 -> V_247 )
F_187 ( V_5 ) ;
F_192 ( V_5 -> V_464 ) ;
F_211 ( V_5 -> V_465 ) ;
F_212 ( V_5 -> V_466 ) ;
F_55 ( V_5 -> V_467 ) ;
F_55 ( F_22 ( V_5 ) ) ;
F_55 ( V_5 ) ;
F_213 (connection, resource)
F_29 ( & V_14 -> V_58 , V_59 ) ;
F_29 ( & V_22 -> V_58 , V_60 ) ;
}
static void F_214 ( struct V_468 * V_469 )
{
struct V_470 * V_471 = F_207 ( V_469 , struct V_470 , V_472 ) ;
F_215 ( V_473 ) ;
struct V_17 * V_19 , * V_223 ;
F_9 ( & V_471 -> V_474 ) ;
F_216 ( & V_471 -> V_473 , & V_473 ) ;
F_14 ( & V_471 -> V_474 ) ;
F_18 (req, tmp, &writes, tl_requests) {
struct V_4 * V_5 = V_19 -> V_5 ;
struct V_1 * V_1 = V_19 -> V_314 ;
unsigned long V_475 = V_19 -> V_475 ;
bool V_476 ;
V_476 =
F_126 ( F_217 ( & V_19 -> V_477 ) == 0 ) &&
F_126 ( V_19 -> V_25 & V_478 ) &&
F_126 ( ( V_19 -> V_25 & V_38 ) == 0 ||
( V_19 -> V_25 & V_479 ) != 0 ) ;
if ( ! V_476 )
F_11 ( V_5 , L_37 ,
V_19 , F_217 ( & V_19 -> V_477 ) ,
V_19 -> V_25 ) ;
F_29 ( & V_19 -> V_58 , V_480 ) ;
F_218 ( V_5 ) ;
F_219 ( V_5 , V_1 , V_475 ) ;
}
}
void F_220 ( struct V_17 * V_19 )
{
unsigned long V_44 ;
F_24 ( & V_471 . V_474 , V_44 ) ;
F_221 ( & V_19 -> V_481 , & V_471 . V_473 ) ;
F_26 ( & V_471 . V_474 , V_44 ) ;
F_222 ( V_19 -> V_5 ) ;
F_223 ( V_471 . V_482 , & V_471 . V_472 ) ;
}
void V_60 ( struct V_58 * V_58 )
{
struct V_43 * V_22 =
F_207 ( V_58 , struct V_43 , V_58 ) ;
F_224 ( & V_22 -> V_483 ) ;
F_225 ( V_22 -> V_76 ) ;
F_55 ( V_22 -> V_48 ) ;
F_55 ( V_22 ) ;
}
void F_226 ( struct V_43 * V_22 )
{
struct V_13 * V_14 , * V_223 ;
F_227 (connection, tmp, resource) {
F_228 ( & V_14 -> V_484 ) ;
F_29 ( & V_14 -> V_58 , V_59 ) ;
}
F_29 ( & V_22 -> V_58 , V_60 ) ;
}
static void F_229 ( void )
{
unsigned int V_158 ;
struct V_4 * V_5 ;
struct V_43 * V_22 , * V_223 ;
F_230 ( & V_485 ) ;
if ( V_486 )
F_231 ( L_38 , NULL ) ;
if ( V_471 . V_482 )
F_232 ( V_471 . V_482 ) ;
F_233 () ;
F_234 (&drbd_devices, device, i)
F_235 ( V_5 ) ;
F_236 (resource, tmp, &drbd_resources) {
F_228 ( & V_22 -> V_487 ) ;
F_226 ( V_22 ) ;
}
F_190 () ;
F_237 ( V_488 , L_38 ) ;
F_224 ( & V_489 ) ;
F_238 ( V_490 L_39 ) ;
}
static int F_239 ( void * V_491 , int V_492 )
{
struct V_4 * V_5 = V_491 ;
struct V_493 * V_435 ;
char V_494 = '-' ;
int V_18 = 0 ;
if ( ! F_240 ( V_5 ) ) {
V_18 = V_492 ;
V_494 = 'd' ;
goto V_325;
}
if ( F_91 ( V_495 , & F_22 ( V_5 ) -> V_14 -> V_44 ) ) {
V_18 |= ( 1 << V_496 ) ;
if ( ! F_88 ( V_5 , V_177 ) )
V_18 |= ( 1 << V_497 ) ;
else
F_84 ( V_5 ) ;
V_18 &= V_492 ;
V_494 = 'c' ;
goto V_325;
}
if ( F_83 ( V_5 ) ) {
V_435 = F_241 ( V_5 -> V_128 -> V_188 ) ;
V_18 = F_242 ( & V_435 -> V_498 , V_492 ) ;
F_84 ( V_5 ) ;
if ( V_18 )
V_494 = 'b' ;
}
if ( V_492 & ( 1 << V_496 ) &&
F_91 ( V_278 , & F_22 ( V_5 ) -> V_14 -> V_44 ) ) {
V_18 |= ( 1 << V_496 ) ;
V_494 = V_494 == 'b' ? 'a' : 'n' ;
}
V_325:
V_5 -> V_499 = V_494 ;
return V_18 ;
}
static void F_243 ( struct V_500 * V_482 )
{
F_33 ( & V_482 -> V_501 ) ;
F_181 ( & V_482 -> V_435 ) ;
F_183 ( & V_482 -> V_502 ) ;
}
static int F_244 ( struct V_503 * V_393 , int V_504 )
{
struct V_505 * V_505 =
F_207 ( V_393 , struct V_505 , V_393 ) ;
F_245 ( & V_505 -> V_506 ) ;
return 0 ;
}
void F_246 ( struct V_500 * V_507 )
{
struct V_505 V_505 ;
V_505 . V_393 . V_394 = F_244 ;
F_37 ( & V_505 . V_506 ) ;
F_247 ( V_507 , & V_505 . V_393 ) ;
F_44 ( & V_505 . V_506 ) ;
}
struct V_43 * F_248 ( const char * V_48 )
{
struct V_43 * V_22 ;
if ( ! V_48 || ! V_48 [ 0 ] )
return NULL ;
F_46 () ;
F_52 (resource, &drbd_resources) {
if ( ! strcmp ( V_22 -> V_48 , V_48 ) ) {
F_36 ( & V_22 -> V_58 ) ;
goto V_508;
}
}
V_22 = NULL ;
V_508:
F_49 () ;
return V_22 ;
}
struct V_13 * F_249 ( void * V_509 , int V_510 ,
void * V_511 , int V_512 )
{
struct V_43 * V_22 ;
struct V_13 * V_14 ;
F_46 () ;
F_52 (resource, &drbd_resources) {
F_250 (connection, resource) {
if ( V_14 -> V_510 == V_510 &&
V_14 -> V_512 == V_512 &&
! memcmp ( & V_14 -> V_509 , V_509 , V_510 ) &&
! memcmp ( & V_14 -> V_511 , V_511 , V_512 ) ) {
F_36 ( & V_14 -> V_58 ) ;
goto V_508;
}
}
}
V_14 = NULL ;
V_508:
F_49 () ;
return V_14 ;
}
static int F_251 ( struct V_102 * V_104 )
{
V_104 -> V_513 = ( void * ) F_252 ( V_80 ) ;
if ( ! V_104 -> V_513 )
return - V_455 ;
V_104 -> V_105 = ( void * ) F_252 ( V_80 ) ;
if ( ! V_104 -> V_105 )
return - V_455 ;
return 0 ;
}
static void F_253 ( struct V_102 * V_104 )
{
F_254 ( ( unsigned long ) V_104 -> V_105 ) ;
F_254 ( ( unsigned long ) V_104 -> V_513 ) ;
}
void F_255 ( struct V_13 * V_14 )
{
F_256 ( V_14 ) ;
F_257 ( V_14 -> V_514 ) ;
F_257 ( V_14 -> V_515 ) ;
F_257 ( V_14 -> V_516 ) ;
F_257 ( V_14 -> V_313 ) ;
F_257 ( V_14 -> V_263 ) ;
F_55 ( V_14 -> V_517 ) ;
F_55 ( V_14 -> V_518 ) ;
V_14 -> V_514 = NULL ;
V_14 -> V_515 = NULL ;
V_14 -> V_516 = NULL ;
V_14 -> V_313 = NULL ;
V_14 -> V_263 = NULL ;
V_14 -> V_517 = NULL ;
V_14 -> V_518 = NULL ;
}
int F_258 ( struct V_43 * V_22 , struct V_519 * V_519 )
{
struct V_13 * V_14 ;
T_2 V_520 ;
int V_110 ;
if ( ! F_259 ( & V_520 , V_80 ) )
return - V_455 ;
if ( V_79 > 1 && V_519 -> V_76 [ 0 ] != 0 ) {
V_110 = F_260 ( V_519 -> V_76 , V_521 ,
F_261 ( V_520 ) , V_79 ) ;
if ( V_110 ) {
F_158 ( V_22 , L_40 , V_110 ) ;
goto V_522;
}
}
V_22 -> V_519 = * V_519 ;
if ( F_262 ( V_520 ) )
F_50 ( & V_520 ) ;
if ( ! F_263 ( V_22 -> V_76 , V_520 ) ) {
F_264 ( V_22 -> V_76 , V_520 ) ;
F_250 (connection, resource) {
V_14 -> V_418 . V_65 = 1 ;
V_14 -> V_273 . V_65 = 1 ;
V_14 -> V_472 . V_65 = 1 ;
}
}
V_110 = 0 ;
V_522:
F_225 ( V_520 ) ;
return V_110 ;
}
struct V_43 * F_265 ( const char * V_48 )
{
struct V_43 * V_22 ;
V_22 = F_51 ( sizeof( struct V_43 ) , V_80 ) ;
if ( ! V_22 )
goto V_522;
V_22 -> V_48 = F_266 ( V_48 , V_80 ) ;
if ( ! V_22 -> V_48 )
goto V_523;
if ( ! F_259 ( & V_22 -> V_76 , V_80 ) )
goto V_524;
F_267 ( & V_22 -> V_58 ) ;
F_268 ( & V_22 -> V_483 ) ;
F_181 ( & V_22 -> V_484 ) ;
F_269 ( & V_22 -> V_487 , & V_525 ) ;
F_180 ( & V_22 -> V_526 ) ;
F_180 ( & V_22 -> V_527 ) ;
F_33 ( & V_22 -> V_23 ) ;
return V_22 ;
V_524:
F_55 ( V_22 -> V_48 ) ;
V_523:
F_55 ( V_22 ) ;
V_522:
return NULL ;
}
struct V_13 * F_270 ( const char * V_48 , struct V_519 * V_519 )
{
struct V_43 * V_22 ;
struct V_13 * V_14 ;
V_14 = F_51 ( sizeof( struct V_13 ) , V_80 ) ;
if ( ! V_14 )
return NULL ;
if ( F_251 ( & V_14 -> V_108 ) )
goto V_522;
if ( F_251 ( & V_14 -> V_112 ) )
goto V_522;
V_14 -> V_528 = F_51 ( sizeof( struct V_529 ) , V_80 ) ;
if ( ! V_14 -> V_528 )
goto V_522;
F_181 ( & V_14 -> V_530 ) ;
F_181 ( & V_14 -> V_528 -> V_387 ) ;
V_14 -> V_531 = 1 ;
F_33 ( & V_14 -> V_532 ) ;
V_14 -> V_533 = V_534 ;
V_14 -> V_535 . V_536 = false ;
V_14 -> V_535 . V_537 = 0 ;
V_14 -> V_535 . V_538 = 0 ;
V_22 = F_265 ( V_48 ) ;
if ( ! V_22 )
goto V_522;
V_14 -> V_250 = V_363 ;
F_180 ( & V_14 -> V_539 ) ;
F_183 ( & V_14 -> V_540 ) ;
F_268 ( & V_14 -> V_75 ) ;
F_243 ( & V_14 -> V_434 ) ;
F_180 ( & V_14 -> V_108 . V_106 ) ;
F_180 ( & V_14 -> V_112 . V_106 ) ;
F_31 ( V_22 , & V_14 -> V_418 , V_541 , L_41 ) ;
V_14 -> V_418 . V_14 = V_14 ;
F_31 ( V_22 , & V_14 -> V_472 , V_542 , L_42 ) ;
V_14 -> V_472 . V_14 = V_14 ;
F_31 ( V_22 , & V_14 -> V_273 , V_543 , L_43 ) ;
V_14 -> V_273 . V_14 = V_14 ;
F_267 ( & V_14 -> V_58 ) ;
V_14 -> V_22 = V_22 ;
if ( F_258 ( V_22 , V_519 ) )
goto V_544;
F_36 ( & V_22 -> V_58 ) ;
F_269 ( & V_14 -> V_484 , & V_22 -> V_484 ) ;
return V_14 ;
V_544:
F_228 ( & V_22 -> V_487 ) ;
F_226 ( V_22 ) ;
V_522:
F_55 ( V_14 -> V_528 ) ;
F_253 ( & V_14 -> V_112 ) ;
F_253 ( & V_14 -> V_108 ) ;
F_55 ( V_14 ) ;
return NULL ;
}
void V_59 ( struct V_58 * V_58 )
{
struct V_13 * V_14 = F_207 ( V_58 , struct V_13 , V_58 ) ;
struct V_43 * V_22 = V_14 -> V_22 ;
if ( F_217 ( & V_14 -> V_528 -> V_545 ) != 0 )
F_11 ( V_14 , L_44 , F_217 ( & V_14 -> V_528 -> V_545 ) ) ;
F_55 ( V_14 -> V_528 ) ;
F_224 ( & V_14 -> V_75 ) ;
F_253 ( & V_14 -> V_112 ) ;
F_253 ( & V_14 -> V_108 ) ;
F_55 ( V_14 -> V_517 ) ;
F_55 ( V_14 -> V_518 ) ;
F_55 ( V_14 ) ;
F_29 ( & V_22 -> V_58 , V_60 ) ;
}
static int F_271 ( struct V_4 * V_5 )
{
V_5 -> V_546 . V_482 = F_272 ( L_45 ,
V_547 | V_548 , 1 , V_5 -> V_74 ) ;
if ( ! V_5 -> V_546 . V_482 )
return - V_455 ;
F_273 ( & V_5 -> V_546 . V_472 , V_549 ) ;
F_33 ( & V_5 -> V_546 . V_474 ) ;
F_181 ( & V_5 -> V_546 . V_473 ) ;
return 0 ;
}
enum V_550 F_274 ( struct V_551 * V_552 , unsigned int V_74 )
{
struct V_43 * V_22 = V_552 -> V_22 ;
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_71 * V_72 , * V_553 ;
struct V_357 * V_11 ;
struct V_493 * V_435 ;
int V_554 ;
int V_73 = V_552 -> V_98 ;
enum V_550 V_110 = V_555 ;
V_5 = F_275 ( V_74 ) ;
if ( V_5 )
return V_556 ;
V_5 = F_51 ( sizeof( struct V_4 ) , V_80 ) ;
if ( ! V_5 )
return V_555 ;
F_267 ( & V_5 -> V_58 ) ;
F_36 ( & V_22 -> V_58 ) ;
V_5 -> V_22 = V_22 ;
V_5 -> V_74 = V_74 ;
V_5 -> V_73 = V_73 ;
F_178 ( V_5 ) ;
V_435 = F_276 ( V_80 ) ;
if ( ! V_435 )
goto V_557;
V_5 -> V_466 = V_435 ;
V_435 -> V_558 = V_5 ;
V_11 = F_277 ( 1 ) ;
if ( ! V_11 )
goto V_559;
V_5 -> V_465 = V_11 ;
F_278 ( V_11 , true ) ;
V_11 -> V_191 = V_435 ;
V_11 -> V_560 = V_488 ;
V_11 -> V_561 = V_74 ;
V_11 -> V_562 = & V_563 ;
sprintf ( V_11 -> V_564 , L_46 , V_74 ) ;
V_11 -> V_348 = V_5 ;
V_5 -> V_196 = F_279 ( F_280 ( V_488 , V_74 ) ) ;
V_5 -> V_196 -> V_565 = V_5 -> V_196 ;
V_435 -> V_498 . V_566 = F_239 ;
V_435 -> V_498 . V_491 = V_5 ;
F_281 ( V_435 , V_567 ) ;
F_282 ( V_435 , V_307 | V_305 ) ;
F_283 ( V_435 , V_416 >> 8 ) ;
F_284 ( V_435 , V_568 ) ;
F_285 ( V_435 , V_569 ) ;
V_435 -> V_570 = & V_22 -> V_23 ;
V_5 -> V_464 = F_201 ( V_80 ) ;
if ( ! V_5 -> V_464 )
goto V_571;
if ( F_286 ( V_5 ) )
goto V_572;
V_5 -> V_573 = V_574 ;
V_5 -> V_575 = V_574 ;
V_554 = F_287 ( & V_489 , V_5 , V_74 , V_74 + 1 , V_80 ) ;
if ( V_554 < 0 ) {
if ( V_554 == - V_576 ) {
V_110 = V_556 ;
F_288 ( V_552 -> V_577 , L_47 ) ;
}
goto V_578;
}
F_36 ( & V_5 -> V_58 ) ;
V_554 = F_287 ( & V_22 -> V_483 , V_5 , V_73 , V_73 + 1 , V_80 ) ;
if ( V_554 < 0 ) {
if ( V_554 == - V_576 ) {
V_110 = V_556 ;
F_288 ( V_552 -> V_577 , L_47 ) ;
}
goto V_579;
}
F_36 ( & V_5 -> V_58 ) ;
F_181 ( & V_5 -> V_75 ) ;
F_213 (connection, resource) {
V_72 = F_51 ( sizeof( struct V_71 ) , V_80 ) ;
if ( ! V_72 )
goto V_580;
V_72 -> V_14 = V_14 ;
V_72 -> V_5 = V_5 ;
F_289 ( & V_72 -> V_75 , & V_5 -> V_75 ) ;
F_36 ( & V_5 -> V_58 ) ;
V_554 = F_287 ( & V_14 -> V_75 , V_72 , V_73 , V_73 + 1 , V_80 ) ;
if ( V_554 < 0 ) {
if ( V_554 == - V_576 ) {
V_110 = V_581 ;
F_288 ( V_552 -> V_577 , L_48 ) ;
}
goto V_580;
}
F_36 ( & V_14 -> V_58 ) ;
}
if ( F_271 ( V_5 ) ) {
V_110 = V_555 ;
F_288 ( V_552 -> V_577 , L_49 ) ;
goto V_582;
}
F_290 ( V_11 ) ;
V_5 -> V_10 . V_32 = F_291 ( V_22 ) -> V_250 ;
if ( V_5 -> V_10 . V_32 == V_251 ) {
F_292 (peer_device, device)
F_293 ( V_72 ) ;
}
return V_583 ;
V_582:
F_294 ( & V_14 -> V_75 , V_73 ) ;
V_580:
F_213 (connection, resource) {
V_72 = F_295 ( & V_14 -> V_75 , V_73 ) ;
if ( V_72 ) {
F_294 ( & V_14 -> V_75 , V_73 ) ;
F_29 ( & V_14 -> V_58 , V_59 ) ;
}
}
F_296 (peer_device, tmp_peer_device, device) {
F_228 ( & V_72 -> V_75 ) ;
F_55 ( V_72 ) ;
}
F_294 ( & V_22 -> V_483 , V_73 ) ;
V_579:
F_294 ( & V_489 , V_74 ) ;
F_297 () ;
V_578:
F_187 ( V_5 ) ;
V_572:
F_192 ( V_5 -> V_464 ) ;
V_571:
F_211 ( V_11 ) ;
V_559:
F_212 ( V_435 ) ;
V_557:
F_29 ( & V_22 -> V_58 , V_60 ) ;
F_55 ( V_5 ) ;
return V_110 ;
}
void F_235 ( struct V_4 * V_5 )
{
struct V_43 * V_22 = V_5 -> V_22 ;
struct V_13 * V_14 ;
int V_584 = 3 ;
F_213 (connection, resource) {
F_294 ( & V_14 -> V_75 , V_5 -> V_73 ) ;
V_584 ++ ;
}
F_294 ( & V_22 -> V_483 , V_5 -> V_73 ) ;
F_294 ( & V_489 , F_48 ( V_5 ) ) ;
F_298 ( V_5 -> V_465 ) ;
F_297 () ;
F_299 ( & V_5 -> V_58 , V_584 , F_206 ) ;
}
int T_8 F_300 ( void )
{
int V_110 ;
if ( V_446 < V_585 || V_446 > V_586 ) {
F_238 ( V_587
L_50 , V_446 ) ;
#ifdef F_301
return - V_588 ;
#else
V_446 = V_589 ;
#endif
}
V_110 = F_302 ( V_488 , L_38 ) ;
if ( V_110 ) {
F_238 ( V_587
L_51 ,
V_488 ) ;
return V_110 ;
}
F_303 ( & V_485 ) ;
F_183 ( & V_590 ) ;
V_486 = NULL ;
F_268 ( & V_489 ) ;
F_304 ( & V_591 ) ;
F_181 ( & V_525 ) ;
V_110 = F_305 () ;
if ( V_110 ) {
F_238 ( V_587 L_52 ) ;
goto V_522;
}
V_110 = F_196 () ;
if ( V_110 )
goto V_522;
V_110 = - V_455 ;
V_486 = F_306 ( L_38 , V_592 | V_593 , NULL , & V_594 , NULL ) ;
if ( ! V_486 ) {
F_238 ( V_587 L_53 ) ;
goto V_522;
}
V_471 . V_482 = F_307 ( L_54 ) ;
if ( ! V_471 . V_482 ) {
F_238 ( V_587 L_55 ) ;
goto V_522;
}
F_273 ( & V_471 . V_472 , F_214 ) ;
F_33 ( & V_471 . V_474 ) ;
F_181 ( & V_471 . V_473 ) ;
F_238 ( V_490 L_56
L_57 V_595 L_58 ,
V_596 , V_597 , V_598 ) ;
F_238 ( V_490 L_59 , F_308 () ) ;
F_238 ( V_490 L_60 ,
V_488 ) ;
return 0 ;
V_522:
F_229 () ;
if ( V_110 == - V_455 )
F_238 ( V_587 L_61 ) ;
else
F_238 ( V_587 L_62 ) ;
return V_110 ;
}
void F_188 ( struct V_599 * V_128 )
{
if ( V_128 == NULL )
return;
F_309 ( V_128 -> V_188 , V_600 | V_352 | V_601 ) ;
F_309 ( V_128 -> V_602 , V_600 | V_352 | V_601 ) ;
F_55 ( V_128 -> V_120 ) ;
F_55 ( V_128 ) ;
}
void F_256 ( struct V_13 * V_14 )
{
if ( V_14 -> V_108 . V_104 ) {
F_71 ( & V_14 -> V_108 . V_106 ) ;
F_310 ( V_14 -> V_108 . V_104 , V_603 ) ;
F_311 ( V_14 -> V_108 . V_104 ) ;
V_14 -> V_108 . V_104 = NULL ;
F_72 ( & V_14 -> V_108 . V_106 ) ;
}
if ( V_14 -> V_112 . V_104 ) {
F_71 ( & V_14 -> V_112 . V_106 ) ;
F_310 ( V_14 -> V_112 . V_104 , V_603 ) ;
F_311 ( V_14 -> V_112 . V_104 ) ;
V_14 -> V_112 . V_104 = NULL ;
F_72 ( & V_14 -> V_112 . V_106 ) ;
}
}
void F_312 ( struct V_13 * V_14 )
{
struct V_71 * V_72 ;
int V_73 ;
F_46 () ;
F_234 (&connection->peer_devices, peer_device, vnr) {
struct V_4 * V_5 = V_72 -> V_5 ;
F_36 ( & V_5 -> V_58 ) ;
F_49 () ;
F_99 ( V_5 ) ;
F_29 ( & V_5 -> V_58 , F_206 ) ;
F_46 () ;
}
F_49 () ;
}
void F_313 ( struct V_4 * V_5 , void * V_233 )
{
struct V_604 * V_100 = V_233 ;
T_4 V_254 ;
int V_158 ;
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
V_100 -> V_605 = F_89 ( F_104 ( V_5 -> V_196 ) ) ;
for ( V_158 = V_162 ; V_158 < V_163 ; V_158 ++ )
V_100 -> V_164 [ V_158 ] = F_89 ( V_5 -> V_128 -> V_160 . V_164 [ V_158 ] ) ;
V_100 -> V_44 = F_64 ( V_5 -> V_128 -> V_160 . V_44 ) ;
V_100 -> V_92 = F_64 ( V_606 ) ;
V_100 -> V_607 = F_64 ( V_5 -> V_128 -> V_160 . V_607 ) ;
V_100 -> V_608 = F_64 ( V_5 -> V_128 -> V_160 . V_608 ) ;
V_100 -> V_609 = F_64 ( V_5 -> V_461 -> V_610 ) ;
V_100 -> V_611 = F_64 ( V_612 ) ;
V_100 -> V_613 = F_89 ( V_5 -> V_128 -> V_160 . V_613 ) ;
V_100 -> V_614 = F_64 ( V_5 -> V_128 -> V_160 . V_614 ) ;
V_100 -> V_615 = F_64 ( V_5 -> V_415 ) ;
V_100 -> V_616 = F_64 ( V_5 -> V_128 -> V_160 . V_616 ) ;
V_100 -> V_617 = F_64 ( V_5 -> V_128 -> V_160 . V_617 ) ;
F_96 ( V_5 , F_314 ( V_5 -> V_128 ) == V_5 -> V_128 -> V_160 . V_618 ) ;
V_254 = V_5 -> V_128 -> V_160 . V_618 ;
if ( F_315 ( V_5 , V_5 -> V_128 , V_254 , V_619 ) ) {
F_11 ( V_5 , L_63 ) ;
F_316 ( V_5 , 1 , V_620 ) ;
}
}
void F_99 ( struct V_4 * V_5 )
{
struct V_604 * V_100 ;
F_61 ( V_163 != 4 ) ;
F_61 ( sizeof( struct V_604 ) != 4096 ) ;
F_317 ( & V_5 -> V_402 ) ;
if ( ! F_318 ( V_621 , & V_5 -> V_44 ) )
return;
if ( ! F_88 ( V_5 , V_622 ) )
return;
V_100 = F_319 ( V_5 ) ;
if ( ! V_100 )
goto V_325;
F_313 ( V_5 , V_100 ) ;
V_5 -> V_128 -> V_160 . V_605 = F_104 ( V_5 -> V_196 ) ;
F_320 ( V_5 ) ;
V_325:
F_84 ( V_5 ) ;
}
static int F_321 ( struct V_4 * V_5 ,
struct V_604 * V_623 ,
struct V_624 * V_625 )
{
T_5 V_616 = F_322 ( V_623 -> V_616 ) ;
T_5 V_617 = F_322 ( V_623 -> V_617 ) ;
T_3 V_626 ;
if ( V_616 == 0 && V_617 == 0 ) {
V_616 = 1 ;
V_617 = V_627 / 8 ;
}
if ( V_616 == 0 || V_617 == 0 )
goto V_110;
V_626 = ( T_3 ) V_616 * V_617 ;
if ( V_626 > ( 16 * 1024 * 1024 / 4 ) )
goto V_110;
if ( V_626 < V_627 / 8 )
goto V_110;
V_625 -> V_617 = V_617 ;
V_625 -> V_616 = V_616 ;
V_625 -> V_626 = V_626 ;
return 0 ;
V_110:
F_11 ( V_5 , L_64 ,
V_616 , V_617 ) ;
return - V_588 ;
}
static int F_323 ( struct V_4 * V_5 , struct V_599 * V_346 )
{
T_4 V_628 = F_104 ( V_346 -> V_602 ) ;
struct V_624 * V_625 = & V_346 -> V_160 ;
T_9 V_629 ;
T_9 V_630 ;
if ( V_625 -> V_608 < 0 ) {
if ( V_625 -> V_614 > V_625 -> V_608 )
goto V_110;
V_629 = - V_625 -> V_608 ;
V_630 = V_625 -> V_608 - V_625 -> V_614 ;
} else {
if ( V_625 -> V_608 != V_631 )
goto V_110;
if ( V_625 -> V_614 < V_625 -> V_608 + V_625 -> V_626 * V_631 )
goto V_110;
V_629 = V_625 -> V_614 - V_631 ;
V_630 = V_625 -> V_607 - V_625 -> V_614 ;
}
if ( V_625 -> V_632 >= 0 ) {
if ( V_625 -> V_607 != V_633
|| V_625 -> V_608 != V_631
|| V_625 -> V_614 != V_631 + V_627
|| V_625 -> V_616 != 1
|| V_625 -> V_617 != V_627 / 8 )
goto V_110;
}
if ( V_628 < V_625 -> V_607 )
goto V_110;
if ( V_628 - V_625 -> V_607 < F_324 ( V_346 ) )
goto V_110;
if ( ( V_629 & 7 ) || ( V_629 < V_627 ) )
goto V_110;
if ( V_629 != V_625 -> V_626 * V_631 )
goto V_110;
if ( V_625 -> V_614 & 7 )
goto V_110;
if ( V_630 < ( V_625 -> V_605 + 7 ) / V_631 / 8 / 512 )
goto V_110;
return 0 ;
V_110:
F_11 ( V_5 , L_65
L_66
L_67 ,
V_625 -> V_632 ,
V_625 -> V_616 , V_625 -> V_617 ,
V_625 -> V_608 , V_625 -> V_614 , V_625 -> V_607 ,
( unsigned long long ) V_625 -> V_605 ,
( unsigned long long ) V_628 ) ;
return - V_588 ;
}
int F_325 ( struct V_4 * V_5 , struct V_599 * V_346 )
{
struct V_604 * V_100 ;
T_5 V_92 , V_44 ;
int V_158 , V_334 = V_583 ;
if ( V_5 -> V_10 . V_11 != V_364 )
return V_634 ;
V_100 = F_319 ( V_5 ) ;
if ( ! V_100 )
return V_555 ;
V_346 -> V_160 . V_632 = V_346 -> V_120 -> V_632 ;
V_346 -> V_160 . V_618 = F_314 ( V_346 ) ;
if ( F_315 ( V_5 , V_346 , V_346 -> V_160 . V_618 , V_635 ) ) {
F_11 ( V_5 , L_68 ) ;
V_334 = V_636 ;
goto V_110;
}
V_92 = F_322 ( V_100 -> V_92 ) ;
V_44 = F_322 ( V_100 -> V_44 ) ;
if ( V_92 == V_606 ||
( V_92 == V_637 && ! ( V_44 & V_638 ) ) ) {
F_11 ( V_5 , L_69 ) ;
V_334 = V_639 ;
goto V_110;
}
V_334 = V_640 ;
if ( V_92 != V_637 ) {
if ( V_92 == V_641 )
F_11 ( V_5 , L_70 ) ;
else
F_11 ( V_5 , L_71 ) ;
goto V_110;
}
if ( F_322 ( V_100 -> V_611 ) != V_612 ) {
F_11 ( V_5 , L_72 ,
F_322 ( V_100 -> V_611 ) , V_612 ) ;
goto V_110;
}
V_346 -> V_160 . V_605 = F_326 ( V_100 -> V_605 ) ;
for ( V_158 = V_162 ; V_158 < V_163 ; V_158 ++ )
V_346 -> V_160 . V_164 [ V_158 ] = F_326 ( V_100 -> V_164 [ V_158 ] ) ;
V_346 -> V_160 . V_44 = F_322 ( V_100 -> V_44 ) ;
V_346 -> V_160 . V_613 = F_326 ( V_100 -> V_613 ) ;
V_346 -> V_160 . V_607 = F_322 ( V_100 -> V_607 ) ;
V_346 -> V_160 . V_608 = F_322 ( V_100 -> V_608 ) ;
V_346 -> V_160 . V_614 = F_322 ( V_100 -> V_614 ) ;
if ( F_321 ( V_5 , V_100 , & V_346 -> V_160 ) )
goto V_110;
if ( F_323 ( V_5 , V_346 ) )
goto V_110;
if ( F_322 ( V_100 -> V_614 ) != V_346 -> V_160 . V_614 ) {
F_11 ( V_5 , L_73 ,
F_322 ( V_100 -> V_614 ) , V_346 -> V_160 . V_614 ) ;
goto V_110;
}
if ( F_322 ( V_100 -> V_607 ) != V_346 -> V_160 . V_607 ) {
F_11 ( V_5 , L_74 ,
F_322 ( V_100 -> V_607 ) , V_346 -> V_160 . V_607 ) ;
goto V_110;
}
V_334 = V_583 ;
F_9 ( & V_5 -> V_22 -> V_23 ) ;
if ( V_5 -> V_10 . V_32 < V_258 ) {
unsigned int V_361 ;
V_361 = F_322 ( V_100 -> V_615 ) ;
V_361 = F_327 ( V_361 , V_416 ) ;
V_5 -> V_415 = V_361 ;
}
F_14 ( & V_5 -> V_22 -> V_23 ) ;
V_110:
F_320 ( V_5 ) ;
return V_334 ;
}
void F_328 ( struct V_4 * V_5 , unsigned int line , const char * F_32 )
{
if ( ! F_329 ( V_621 , & V_5 -> V_44 ) ) {
F_330 ( & V_5 -> V_402 , V_642 + V_643 ) ;
V_5 -> V_644 . line = line ;
V_5 -> V_644 . F_32 = F_32 ;
}
}
void F_331 ( struct V_4 * V_5 )
{
if ( ! F_329 ( V_621 , & V_5 -> V_44 ) )
F_330 ( & V_5 -> V_402 , V_642 + 5 * V_643 ) ;
}
void F_332 ( struct V_4 * V_5 ) __must_hold( T_10 )
{
int V_158 ;
for ( V_158 = V_173 ; V_158 < V_174 ; V_158 ++ )
V_5 -> V_128 -> V_160 . V_164 [ V_158 + 1 ] = V_5 -> V_128 -> V_160 . V_164 [ V_158 ] ;
}
void F_333 ( struct V_4 * V_5 , int V_645 , T_3 V_203 ) __must_hold( T_10 )
{
if ( V_645 == V_162 ) {
if ( V_5 -> V_10 . V_350 == V_351 )
V_203 |= 1 ;
else
V_203 &= ~ ( ( T_3 ) 1 ) ;
F_334 ( V_5 , V_203 ) ;
}
V_5 -> V_128 -> V_160 . V_164 [ V_645 ] = V_203 ;
F_331 ( V_5 ) ;
}
void F_335 ( struct V_4 * V_5 , int V_645 , T_3 V_203 ) __must_hold( T_10 )
{
unsigned long V_44 ;
F_24 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
F_333 ( V_5 , V_645 , V_203 ) ;
F_26 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
}
void F_98 ( struct V_4 * V_5 , int V_645 , T_3 V_203 ) __must_hold( T_10 )
{
unsigned long V_44 ;
F_24 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
if ( V_5 -> V_128 -> V_160 . V_164 [ V_645 ] ) {
F_332 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_173 ] = V_5 -> V_128 -> V_160 . V_164 [ V_645 ] ;
}
F_333 ( V_5 , V_645 , V_203 ) ;
F_26 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
}
void F_336 ( struct V_4 * V_5 ) __must_hold( T_10 )
{
T_3 V_203 ;
unsigned long long V_646 ;
F_97 ( & V_203 , sizeof( T_3 ) ) ;
F_9 ( & V_5 -> V_128 -> V_160 . V_161 ) ;
V_646 = V_5 -> V_128 -> V_160 . V_164 [ V_172 ] ;
if ( V_646 )
F_158 ( V_5 , L_75 , V_646 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_172 ] = V_5 -> V_128 -> V_160 . V_164 [ V_162 ] ;
F_333 ( V_5 , V_162 , V_203 ) ;
F_14 ( & V_5 -> V_128 -> V_160 . V_161 ) ;
F_94 ( V_5 , L_76 ) ;
F_99 ( V_5 ) ;
}
void F_337 ( struct V_4 * V_5 , T_3 V_203 ) __must_hold( T_10 )
{
unsigned long V_44 ;
if ( V_5 -> V_128 -> V_160 . V_164 [ V_172 ] == 0 && V_203 == 0 )
return;
F_24 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
if ( V_203 == 0 ) {
F_332 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_173 ] = V_5 -> V_128 -> V_160 . V_164 [ V_172 ] ;
V_5 -> V_128 -> V_160 . V_164 [ V_172 ] = 0 ;
} else {
unsigned long long V_646 = V_5 -> V_128 -> V_160 . V_164 [ V_172 ] ;
if ( V_646 )
F_158 ( V_5 , L_75 , V_646 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_172 ] = V_203 & ~ ( ( T_3 ) 1 ) ;
}
F_26 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
F_331 ( V_5 ) ;
}
int F_338 ( struct V_4 * V_5 )
{
int V_334 = - V_113 ;
if ( F_88 ( V_5 , V_647 ) ) {
F_339 ( V_5 , V_248 ) ;
F_99 ( V_5 ) ;
F_128 ( V_5 ) ;
V_334 = F_129 ( V_5 ) ;
if ( ! V_334 ) {
F_130 ( V_5 , V_248 ) ;
F_99 ( V_5 ) ;
}
F_84 ( V_5 ) ;
}
return V_334 ;
}
int F_340 ( struct V_4 * V_5 )
{
int V_334 = - V_113 ;
F_341 ( V_5 ) ;
if ( F_88 ( V_5 , V_647 ) ) {
F_342 ( V_5 ) ;
V_334 = F_129 ( V_5 ) ;
F_84 ( V_5 ) ;
}
return V_334 ;
}
static int V_399 ( struct V_503 * V_393 , int V_458 )
{
struct V_4 * V_5 =
F_207 ( V_393 , struct V_4 , V_392 . V_393 ) ;
struct V_392 * V_648 = & V_5 -> V_392 ;
int V_334 = - V_113 ;
F_96 ( V_5 , F_217 ( & V_5 -> V_367 ) == 0 ) ;
if ( F_83 ( V_5 ) ) {
F_343 ( V_5 , V_648 -> V_649 , V_648 -> V_44 ) ;
V_334 = V_648 -> V_650 ( V_5 ) ;
F_344 ( V_5 ) ;
F_84 ( V_5 ) ;
}
F_345 ( V_651 , & V_5 -> V_44 ) ;
F_7 ( & V_5 -> V_12 ) ;
if ( V_648 -> V_506 )
V_648 -> V_506 ( V_5 , V_334 ) ;
F_159 ( V_652 , & V_5 -> V_44 ) ;
V_648 -> V_649 = NULL ;
V_648 -> V_44 = 0 ;
return 0 ;
}
void F_346 ( struct V_4 * V_5 )
{
F_210 ( V_5 -> V_462 ) ;
V_5 -> V_462 = NULL ;
F_210 ( V_5 -> V_461 ) ;
V_5 -> V_461 = NULL ;
F_347 (local,
drbd_free_bc(device->ldev);
device->ldev = NULL;) ;
F_159 ( V_653 , & V_5 -> V_44 ) ;
}
static int V_397 ( struct V_503 * V_393 , int V_458 )
{
struct V_4 * V_5 =
F_207 ( V_393 , struct V_4 , V_389 ) ;
F_96 ( V_5 , V_5 -> V_10 . V_11 == V_622 ) ;
if ( V_5 -> V_247 && V_5 -> V_128 ) {
if ( F_348 ( V_5 , F_129 ,
L_77 , V_654 ) ) {
if ( F_91 ( V_655 , & V_5 -> V_44 ) ) {
F_339 ( V_5 , V_248 ) ;
F_99 ( V_5 ) ;
}
}
}
F_349 ( V_5 , F_16 ( V_11 , V_364 ) ) ;
return 0 ;
}
void F_350 ( struct V_4 * V_5 ,
int (* V_650)( struct V_4 * ) ,
void (* V_506)( struct V_4 * , int ) ,
char * V_649 , enum V_656 V_44 )
{
F_96 ( V_5 , V_46 == F_22 ( V_5 ) -> V_14 -> V_472 . V_55 ) ;
F_96 ( V_5 , ! F_91 ( V_652 , & V_5 -> V_44 ) ) ;
F_96 ( V_5 , ! F_91 ( V_651 , & V_5 -> V_44 ) ) ;
F_96 ( V_5 , F_189 ( & V_5 -> V_392 . V_393 . V_387 ) ) ;
if ( V_5 -> V_392 . V_649 )
F_11 ( V_5 , L_78 ,
V_649 , V_5 -> V_392 . V_649 ) ;
V_5 -> V_392 . V_650 = V_650 ;
V_5 -> V_392 . V_506 = V_506 ;
V_5 -> V_392 . V_649 = V_649 ;
V_5 -> V_392 . V_44 = V_44 ;
F_9 ( & V_5 -> V_22 -> V_23 ) ;
F_149 ( V_651 , & V_5 -> V_44 ) ;
if ( F_217 ( & V_5 -> V_367 ) == 0 ) {
if ( ! F_329 ( V_652 , & V_5 -> V_44 ) )
F_247 ( & F_22 ( V_5 ) -> V_14 -> V_434 ,
& V_5 -> V_392 . V_393 ) ;
}
F_14 ( & V_5 -> V_22 -> V_23 ) ;
}
int F_351 ( struct V_4 * V_5 , int (* V_650)( struct V_4 * ) ,
char * V_649 , enum V_656 V_44 )
{
int V_334 ;
F_96 ( V_5 , V_46 != F_22 ( V_5 ) -> V_14 -> V_472 . V_55 ) ;
if ( ( V_44 & V_657 ) == 0 )
F_352 ( V_5 ) ;
F_343 ( V_5 , V_649 , V_44 ) ;
V_334 = V_650 ( V_5 ) ;
F_344 ( V_5 ) ;
if ( ( V_44 & V_657 ) == 0 )
F_353 ( V_5 ) ;
return V_334 ;
}
void F_339 ( struct V_4 * V_5 , int V_658 ) __must_hold( T_10 )
{
if ( ( V_5 -> V_128 -> V_160 . V_44 & V_658 ) != V_658 ) {
F_331 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_44 |= V_658 ;
}
}
void F_130 ( struct V_4 * V_5 , int V_658 ) __must_hold( T_10 )
{
if ( ( V_5 -> V_128 -> V_160 . V_44 & V_658 ) != 0 ) {
F_331 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_44 &= ~ V_658 ;
}
}
int F_127 ( struct V_599 * V_346 , int V_658 )
{
return ( V_346 -> V_160 . V_44 & V_658 ) != 0 ;
}
static void V_406 ( unsigned long V_108 )
{
struct V_4 * V_5 = (struct V_4 * ) V_108 ;
if ( F_189 ( & V_5 -> V_390 . V_387 ) )
F_354 ( & F_22 ( V_5 ) -> V_14 -> V_434 ,
& V_5 -> V_390 ) ;
}
static int V_398 ( struct V_503 * V_393 , int V_458 )
{
struct V_4 * V_5 =
F_207 ( V_393 , struct V_4 , V_390 ) ;
F_158 ( V_5 , L_79 ) ;
#ifdef F_355
F_158 ( V_5 , L_80 ,
V_5 -> V_644 . F_32 , V_5 -> V_644 . line ) ;
#endif
F_99 ( V_5 ) ;
return 0 ;
}
const char * F_356 ( enum V_89 V_90 )
{
static const char * V_659 [] = {
[ V_326 ] = L_81 ,
[ V_660 ] = L_82 ,
[ V_661 ] = L_83 ,
[ V_662 ] = L_84 ,
[ V_246 ] = L_85 ,
[ V_663 ] = L_86 ,
[ V_664 ] = L_87 ,
[ V_665 ] = L_88 ,
[ V_666 ] = L_89 ,
[ V_667 ] = L_90 ,
[ V_126 ] = L_91 ,
[ V_125 ] = L_92 ,
[ V_155 ] = L_93 ,
[ V_170 ] = L_94 ,
[ V_198 ] = L_95 ,
[ V_200 ] = L_96 ,
[ V_180 ] = L_97 ,
[ V_668 ] = L_98 ,
[ V_669 ] = L_99 ,
[ V_114 ] = L_100 ,
[ V_115 ] = L_101 ,
[ V_670 ] = L_102 ,
[ V_671 ] = L_103 ,
[ V_672 ] = L_104 ,
[ V_673 ] = L_105 ,
[ V_674 ] = L_106 ,
[ V_675 ] = L_107 ,
[ V_676 ] = L_108 ,
[ V_253 ] = L_109 ,
[ V_205 ] = L_110 ,
[ V_210 ] = L_111 ,
[ V_271 ] = L_112 ,
[ V_677 ] = L_113 ,
[ V_678 ] = L_114 ,
[ V_679 ] = L_115 ,
[ V_680 ] = L_116 ,
[ V_239 ] = L_117 ,
[ V_681 ] = L_118 ,
[ V_328 ] = L_119 ,
[ V_682 ] = L_120 ,
[ V_683 ] = L_121 ,
[ V_206 ] = L_122 ,
[ V_211 ] = L_123 ,
[ V_682 ] = L_124 ,
[ V_684 ] = L_125 ,
} ;
if ( V_90 == V_685 )
return L_126 ;
if ( V_90 == V_686 )
return L_127 ;
if ( V_90 == V_687 )
return L_128 ;
if ( V_90 >= F_357 ( V_659 ) )
return L_129 ;
return V_659 [ V_90 ] ;
}
int F_358 ( struct V_4 * V_5 , struct V_688 * V_158 )
{
struct V_118 * V_119 ;
F_359 ( V_67 ) ;
long V_689 ;
F_46 () ;
V_119 = F_82 ( F_22 ( V_5 ) -> V_14 -> V_118 ) ;
if ( ! V_119 ) {
F_49 () ;
return - V_690 ;
}
V_689 = V_119 -> V_274 ? V_119 -> V_689 * V_643 / 10 * V_119 -> V_274 : V_691 ;
F_49 () ;
V_158 -> V_692 = true ;
F_360 ( & V_5 -> V_12 , & V_67 , V_693 ) ;
F_14 ( & V_5 -> V_22 -> V_23 ) ;
V_689 = F_361 ( V_689 ) ;
F_362 ( & V_5 -> V_12 , & V_67 ) ;
F_9 ( & V_5 -> V_22 -> V_23 ) ;
if ( ! V_689 || V_5 -> V_10 . V_32 < V_258 )
return - V_690 ;
if ( F_363 ( V_46 ) )
return - V_694 ;
return 0 ;
}
static unsigned long
F_364 ( struct V_695 * V_696 )
{
long V_697 ;
if ( ! V_696 -> V_698 -- ) {
F_97 ( & V_697 , sizeof( V_697 ) ) ;
V_696 -> V_10 += V_697 ;
V_696 -> V_698 = V_699 ;
}
V_696 -> V_10 = V_696 -> V_10 * V_700 + V_701 ;
return F_365 ( V_696 -> V_10 ) ;
}
static char *
F_366 ( unsigned int type ) {
static char * V_702 [] = {
[ V_703 ] = L_130 ,
[ V_704 ] = L_131 ,
[ V_705 ] = L_132 ,
[ V_706 ] = L_133 ,
[ V_707 ] = L_134 ,
[ V_708 ] = L_135 ,
[ V_709 ] = L_136 ,
[ V_710 ] = L_137 ,
[ V_711 ] = L_138 ,
[ V_712 ] = L_139 ,
} ;
return ( type < V_713 ) ? V_702 [ type ] : L_140 ;
}
unsigned int
F_367 ( struct V_4 * V_5 , unsigned int type )
{
static struct V_695 V_714 = { 0 , 0 } ;
unsigned int V_715 = (
( V_716 == 0 ||
( ( 1 << F_48 ( V_5 ) ) & V_716 ) != 0 ) &&
( ( ( F_364 ( & V_714 ) % 100 ) + 1 ) <= V_717 ) ) ;
if ( V_715 ) {
V_718 ++ ;
if ( F_368 ( & V_719 ) )
F_158 ( V_5 , L_141 ,
F_366 ( type ) ) ;
}
return V_715 ;
}
const char * F_308 ( void )
{
static char V_720 [ 38 ] = L_142 ;
if ( V_720 [ 0 ] == 0 ) {
#ifdef F_301
sprintf ( V_720 , L_143 , V_61 -> V_721 ) ;
#else
V_720 [ 0 ] = 'b' ;
#endif
}
return V_720 ;
}
