static void F_1 ( struct V_1 * V_2 , bool V_3 , unsigned long V_4 )
{
if ( V_3 )
F_2 ( V_2 , L_1 , F_3 ( V_4 ) ) ;
else
F_2 ( V_2 , L_2 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
bool V_5 , char * V_6 , const char * V_7 , const char * V_8 )
{
if ( V_5 && V_7 ) {
F_5 ( V_2 , * V_6 ) ;
F_6 ( V_2 , V_7 ) ;
* V_6 = '|' ;
} else if ( ! V_5 && V_8 ) {
F_5 ( V_2 , * V_6 ) ;
F_6 ( V_2 , V_8 ) ;
* V_6 = '|' ;
}
}
static void F_7 ( struct V_1 * V_2 ,
bool V_5 , char * V_6 , const char * V_7 )
{
F_4 ( V_2 , V_5 , V_6 , V_7 , NULL ) ;
}
static void F_8 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
unsigned int V_11 = V_10 -> V_12 ;
char V_6 = ' ' ;
F_2 ( V_2 , L_3 , V_11 ) ;
F_2 ( V_2 , L_4 , V_10 -> V_13 ? L_5 : L_6 ) ;
F_6 ( V_2 , L_7 ) ;
F_7 ( V_2 , V_11 & V_14 , & V_6 , L_8 ) ;
F_7 ( V_2 , V_11 & V_15 , & V_6 , L_9 ) ;
F_7 ( V_2 , V_11 & V_16 , & V_6 , L_10 ) ;
V_6 = ' ' ;
F_7 ( V_2 , V_11 & V_17 , & V_6 , L_5 ) ;
F_7 ( V_2 , V_11 & V_18 , & V_6 , L_6 ) ;
F_7 ( V_2 , V_11 & V_19 , & V_6 , L_11 ) ;
F_7 ( V_2 , V_11 & V_20 , & V_6 , L_12 ) ;
if ( V_6 == ' ' )
F_6 ( V_2 , L_13 ) ;
F_2 ( V_2 , L_14 ) ;
V_6 = ' ' ;
F_7 ( V_2 , V_11 & V_21 , & V_6 , L_5 ) ;
F_7 ( V_2 , V_11 & V_22 , & V_6 , L_15 ) ;
F_7 ( V_2 , V_11 & V_23 , & V_6 , L_16 ) ;
F_7 ( V_2 , V_11 & V_24 , & V_6 , L_17 ) ;
F_7 ( V_2 , V_11 & V_25 , & V_6 , L_18 ) ;
F_7 ( V_2 , V_11 & V_26 , & V_6 , L_12 ) ;
if ( V_6 == ' ' )
F_6 ( V_2 , L_13 ) ;
F_2 ( V_2 , L_19 ) ;
V_6 = ' ' ;
F_7 ( V_2 , V_11 & V_27 , & V_6 , L_20 ) ;
F_7 ( V_2 , V_11 & V_28 , & V_6 , L_21 ) ;
F_7 ( V_2 , V_11 & V_29 , & V_6 , L_22 ) ;
if ( V_6 == ' ' )
F_6 ( V_2 , L_13 ) ;
F_2 ( V_2 , L_23 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_9 * V_10 , unsigned long V_30 )
{
unsigned int V_11 = V_10 -> V_12 ;
#define F_10 "epoch\tsector\tsize\trw"
F_2 ( V_2 , L_24 ,
V_10 -> V_31 ,
( unsigned long long ) V_10 -> V_32 . V_33 , V_10 -> V_32 . V_34 >> 9 ,
( V_11 & V_35 ) ? L_25 : L_26 ) ;
#define F_11 "\tstart\tin AL\tsubmit"
F_2 ( V_2 , L_1 , F_3 ( V_30 - V_10 -> V_36 ) ) ;
F_1 ( V_2 , V_11 & V_14 , V_30 - V_10 -> V_37 ) ;
F_1 ( V_2 , V_11 & V_17 , V_30 - V_10 -> V_38 ) ;
#define F_12 "\tsent\tacked\tdone"
F_1 ( V_2 , V_11 & V_23 , V_30 - V_10 -> V_39 ) ;
F_1 ( V_2 , ( V_11 & V_23 ) && ! ( V_11 & V_21 ) , V_30 - V_10 -> V_40 ) ;
F_1 ( V_2 , V_11 & V_24 , V_30 - V_10 -> V_41 ) ;
#define F_13 "\tstate\n"
F_8 ( V_2 , V_10 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_9 * V_10 , unsigned long V_30 )
{
F_2 ( V_2 , L_27 , V_10 -> V_42 -> V_43 , V_10 -> V_42 -> V_44 ) ;
F_9 ( V_2 , V_10 , V_30 ) ;
}
static void F_15 ( struct V_1 * V_2 , struct V_45 * V_46 , unsigned long V_30 )
{
struct V_47 * V_42 ;
unsigned int V_32 ;
F_6 ( V_2 , L_28 ) ;
F_16 () ;
F_17 (&resource->devices, device, i) {
struct V_48 V_49 ;
V_49 = V_42 -> V_50 ;
if ( F_18 ( & V_49 . V_51 ) ) {
F_2 ( V_2 , L_29 ,
V_42 -> V_43 , V_42 -> V_44 ,
F_3 ( V_30 - V_49 . V_36 ) ) ;
if ( F_19 ( V_49 . V_52 , V_49 . V_36 ) )
F_6 ( V_2 , L_30 ) ;
else
F_2 ( V_2 , L_31 , F_3 ( V_30 - V_49 . V_52 ) ) ;
F_2 ( V_2 , L_32 , V_49 . V_53 ) ;
}
}
F_20 () ;
}
static void F_21 ( struct V_1 * V_2 , struct V_45 * V_46 , unsigned long V_30 )
{
struct V_47 * V_42 ;
unsigned int V_32 ;
F_6 ( V_2 , L_33 ) ;
F_16 () ;
F_17 (&resource->devices, device, i) {
unsigned long V_54 ;
struct V_9 * V_10 ;
int V_55 = F_18 ( & V_42 -> V_56 ) ;
if ( V_55 ) {
F_22 ( & V_42 -> V_46 -> V_57 ) ;
V_10 = F_23 ( & V_42 -> V_58 [ 1 ] ,
struct V_9 , V_59 ) ;
if ( V_10 && ! ( V_10 -> V_12 & V_14 ) )
V_54 = V_10 -> V_36 ;
else
V_10 = NULL ;
F_24 ( & V_42 -> V_46 -> V_57 ) ;
}
if ( V_55 ) {
F_2 ( V_2 , L_27 , V_42 -> V_43 , V_42 -> V_44 ) ;
if ( V_10 )
F_2 ( V_2 , L_34 , F_3 ( V_30 - V_54 ) ) ;
else
F_6 ( V_2 , L_30 ) ;
F_2 ( V_2 , L_35 , V_55 ) ;
}
}
F_20 () ;
}
static void F_25 ( struct V_1 * V_2 , struct V_47 * V_42 , unsigned long V_30 )
{
struct V_60 * V_61 ;
unsigned long V_36 ;
unsigned int V_62 ;
unsigned int V_63 ;
F_22 ( & V_42 -> V_46 -> V_57 ) ;
V_61 = F_23 ( & V_42 -> V_64 , struct V_60 , V_65 ) ;
if ( V_61 && V_61 -> V_66 )
V_61 = NULL ;
if ( V_61 ) {
V_36 = V_61 -> V_36 ;
V_62 = F_18 ( & V_61 -> V_62 ) ;
V_63 = V_61 -> V_63 ;
}
F_24 ( & V_42 -> V_46 -> V_57 ) ;
if ( V_61 ) {
F_2 ( V_2 , L_36 ,
V_42 -> V_43 , V_42 -> V_44 ,
( V_63 & V_67 ) ? 'R' : 'W' ,
F_3 ( V_30 - V_36 ) ,
V_62 ) ;
}
}
static void F_26 ( struct V_1 * V_2 , struct V_45 * V_46 , unsigned long V_30 )
{
struct V_47 * V_42 ;
unsigned int V_32 ;
F_6 ( V_2 , L_37 ) ;
F_16 () ;
F_17 (&resource->devices, device, i) {
F_25 ( V_2 , V_42 , V_30 ) ;
}
F_20 () ;
}
static void F_27 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
unsigned long V_70 = V_69 -> V_63 ;
char V_6 = ' ' ;
F_4 ( V_2 , V_70 & V_71 , & V_6 , L_38 , L_39 ) ;
F_4 ( V_2 , V_70 & V_72 , & V_6 , L_40 , L_41 ) ;
F_7 ( V_2 , V_70 & V_73 , & V_6 , L_8 ) ;
F_7 ( V_2 , V_70 & V_74 , & V_6 , L_21 ) ;
F_7 ( V_2 , V_70 & V_75 , & V_6 , L_42 ) ;
if ( V_70 & V_76 ) {
F_5 ( V_2 , V_6 ) ;
V_6 = '|' ;
if ( V_70 & V_77 )
F_6 ( V_2 , L_43 ) ;
else
F_6 ( V_2 , L_44 ) ;
}
F_5 ( V_2 , '\n' ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_47 * V_42 , struct V_78 * V_79 ,
unsigned long V_30 )
{
bool V_80 = false ;
struct V_68 * V_69 ;
F_29 (peer_req, lh, w.list) {
if ( V_80 && ! ( V_69 -> V_63 & V_71 ) )
continue;
if ( V_42 )
F_2 ( V_2 , L_27 , V_42 -> V_43 , V_42 -> V_44 ) ;
F_2 ( V_2 , L_45 ,
( unsigned long long ) V_69 -> V_32 . V_33 , V_69 -> V_32 . V_34 >> 9 ,
( V_69 -> V_63 & V_81 ) ? 'W' : 'R' ,
F_3 ( V_30 - V_69 -> V_52 ) ) ;
F_27 ( V_2 , V_69 ) ;
if ( V_69 -> V_63 & V_71 )
break;
else
V_80 = true ;
}
}
static void F_30 ( struct V_1 * V_2 ,
struct V_47 * V_42 , unsigned long V_30 )
{
F_6 ( V_2 , L_46 ) ;
F_22 ( & V_42 -> V_46 -> V_57 ) ;
F_28 ( V_2 , V_42 , & V_42 -> V_82 , V_30 ) ;
F_28 ( V_2 , V_42 , & V_42 -> V_83 , V_30 ) ;
F_28 ( V_2 , V_42 , & V_42 -> V_84 , V_30 ) ;
F_24 ( & V_42 -> V_46 -> V_57 ) ;
if ( F_31 ( V_85 , & V_42 -> V_63 ) ) {
F_2 ( V_2 , L_47 ,
V_42 -> V_43 , V_42 -> V_44 ,
F_3 ( V_30 - V_42 -> V_86 ) ) ;
}
}
static void F_32 ( struct V_1 * V_2 ,
struct V_45 * V_46 , unsigned long V_30 )
{
struct V_47 * V_42 ;
unsigned int V_32 ;
F_16 () ;
F_17 (&resource->devices, device, i) {
F_30 ( V_2 , V_42 , V_30 ) ;
}
F_20 () ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_45 * V_46 ,
struct V_87 * V_88 ,
unsigned long V_30 )
{
struct V_9 * V_10 ;
unsigned int V_89 = 0 ;
unsigned int V_90 = 0 ;
F_6 ( V_2 , L_48 V_91 ) ;
F_22 ( & V_46 -> V_57 ) ;
F_29 (req, &connection->transfer_log, tl_requests) {
unsigned int V_49 = 0 ;
unsigned int V_11 ;
++ V_89 ;
if ( ! ( V_89 & 0x1ff ) ) {
struct V_9 * V_92 ;
F_34 ( & V_10 -> V_93 ) ;
F_24 ( & V_46 -> V_57 ) ;
F_35 () ;
F_22 ( & V_46 -> V_57 ) ;
V_92 = F_36 ( V_10 , V_94 ) ;
if ( F_37 ( & V_10 -> V_93 , V_95 ) )
V_10 = V_92 ;
if ( & V_10 -> V_94 == & V_88 -> V_96 )
break;
}
V_11 = V_10 -> V_12 ;
if ( V_10 -> V_13 == NULL )
V_49 |= 1 ;
if ( ( V_11 & V_97 ) && ( V_11 & V_17 ) )
V_49 |= 2 ;
if ( V_11 & V_98 ) {
if ( ! ( V_11 & V_23 ) )
V_49 |= 4 ;
if ( V_11 & V_21 )
V_49 |= 8 ;
if ( ! ( V_11 & V_24 ) )
V_49 |= 16 ;
}
if ( ( V_49 & V_90 ) == V_49 )
continue;
V_90 |= V_49 ;
F_2 ( V_2 , L_34 , V_89 ) ;
F_14 ( V_2 , V_10 , V_30 ) ;
if ( V_90 == 0x1f )
break;
}
F_24 ( & V_46 -> V_57 ) ;
}
static int F_38 ( struct V_1 * V_2 , void * V_99 )
{
struct V_45 * V_46 = V_2 -> V_100 ;
struct V_87 * V_88 ;
unsigned long V_54 = V_101 ;
V_88 = F_39 ( V_46 ) ;
if ( ! V_88 || ! F_40 ( & V_88 -> V_93 ) )
return - V_102 ;
F_2 ( V_2 , L_49 , 0 ) ;
F_6 ( V_2 , L_50 ) ;
F_26 ( V_2 , V_46 , V_54 ) ;
F_5 ( V_2 , '\n' ) ;
F_6 ( V_2 , L_51 ) ;
F_15 ( V_2 , V_46 , V_54 ) ;
F_5 ( V_2 , '\n' ) ;
F_6 ( V_2 , L_52 ) ;
F_16 () ;
if ( V_88 -> V_103 . V_104 ) {
struct V_105 * V_106 = F_41 ( V_88 -> V_103 . V_104 -> V_107 ) ;
int V_108 = V_106 -> V_109 - V_106 -> V_110 ;
F_2 ( V_2 , L_53 , V_108 ) ;
V_108 = V_106 -> V_111 - V_106 -> V_112 ;
F_2 ( V_2 , L_54 , V_108 ) ;
}
F_20 () ;
F_5 ( V_2 , '\n' ) ;
F_6 ( V_2 , L_55 ) ;
F_32 ( V_2 , V_46 , V_54 ) ;
F_5 ( V_2 , '\n' ) ;
F_6 ( V_2 , L_56 ) ;
F_21 ( V_2 , V_46 , V_54 ) ;
F_5 ( V_2 , '\n' ) ;
F_6 ( V_2 , L_57 ) ;
F_33 ( V_2 , V_46 , V_88 , V_54 ) ;
F_5 ( V_2 , '\n' ) ;
V_54 = V_101 - V_54 ;
if ( V_54 )
F_2 ( V_2 , L_58 , F_3 ( V_54 ) ) ;
F_37 ( & V_88 -> V_93 , V_113 ) ;
return 0 ;
}
static int F_42 ( struct V_114 * V_114 , int (* F_43)( struct V_1 * , void * ) ,
void * V_103 , struct V_93 * V_93 ,
void (* F_44)( struct V_93 * ) )
{
struct V_115 * V_116 ;
int V_117 = - V_102 ;
V_116 = V_114 -> V_118 . V_115 -> V_119 ;
if ( ! V_116 || F_45 ( V_116 ) )
goto V_120;
F_46 ( F_47 ( V_116 ) ) ;
if ( F_48 ( V_114 -> V_118 . V_115 )
&& F_40 ( V_93 ) )
V_117 = 0 ;
F_49 ( F_47 ( V_116 ) ) ;
if ( ! V_117 ) {
V_117 = F_50 ( V_114 , F_43 , V_103 ) ;
if ( V_117 )
F_37 ( V_93 , F_44 ) ;
}
V_120:
return V_117 ;
}
static int F_51 ( struct V_121 * V_121 , struct V_114 * V_114 )
{
struct V_45 * V_46 = V_121 -> V_122 ;
return F_42 ( V_114 , F_38 , V_46 ,
& V_46 -> V_93 , V_123 ) ;
}
static int F_52 ( struct V_121 * V_121 , struct V_114 * V_114 )
{
struct V_45 * V_46 = V_121 -> V_122 ;
F_37 ( & V_46 -> V_93 , V_123 ) ;
return F_53 ( V_121 , V_114 ) ;
}
void F_54 ( struct V_45 * V_46 )
{
struct V_115 * V_115 ;
if ( ! V_124 )
return;
V_115 = F_55 ( V_46 -> V_125 , V_124 ) ;
if ( F_56 ( V_115 ) )
goto V_126;
V_46 -> V_127 = V_115 ;
V_115 = F_55 ( L_59 , V_46 -> V_127 ) ;
if ( F_56 ( V_115 ) )
goto V_126;
V_46 -> V_128 = V_115 ;
V_115 = F_55 ( L_60 , V_46 -> V_127 ) ;
if ( F_56 ( V_115 ) )
goto V_126;
V_46 -> V_129 = V_115 ;
V_115 = F_57 ( L_61 , V_130 | V_131 ,
V_46 -> V_127 , V_46 ,
& V_132 ) ;
if ( F_56 ( V_115 ) )
goto V_126;
V_46 -> V_133 = V_115 ;
return;
V_126:
F_58 ( V_46 ) ;
F_59 ( V_46 , L_62 ) ;
}
static void F_60 ( struct V_115 * * V_134 )
{
F_61 ( * V_134 ) ;
* V_134 = NULL ;
}
void F_58 ( struct V_45 * V_46 )
{
F_60 ( & V_46 -> V_133 ) ;
F_60 ( & V_46 -> V_129 ) ;
F_60 ( & V_46 -> V_128 ) ;
F_60 ( & V_46 -> V_127 ) ;
}
static void F_62 ( struct V_1 * V_2 ,
const struct V_135 * V_136 ,
unsigned long V_30 )
{
struct V_135 V_137 ;
do {
V_137 = * V_136 ;
} while ( V_137 . V_138 != V_136 -> V_138 );
if ( ! V_137 . V_139 )
return;
F_2 ( V_2 , L_63 ,
V_137 . V_138 ,
F_3 ( V_30 - V_137 . V_36 ) ,
V_137 . V_140 , V_137 . line ,
V_137 . V_139 ) ;
}
static void F_63 ( struct V_1 * V_2 ,
const char * V_141 ,
unsigned int V_138 , struct V_135 * V_136 , unsigned long V_30 )
{
unsigned int V_142 ;
unsigned int V_32 ;
F_2 ( V_2 , L_32 , V_141 ) ;
V_142 = V_138 % V_143 ;
for ( V_32 = V_142 ; V_32 < V_143 ; V_32 ++ )
F_62 ( V_2 , V_136 + V_32 , V_30 ) ;
for ( V_32 = 0 ; V_32 < V_142 ; V_32 ++ )
F_62 ( V_2 , V_136 + V_32 , V_30 ) ;
}
static int F_64 ( struct V_1 * V_2 , void * V_144 )
{
struct V_87 * V_88 = V_2 -> V_100 ;
unsigned long V_54 = V_101 ;
F_2 ( V_2 , L_49 , 0 ) ;
F_6 ( V_2 , L_64 ) ;
F_63 ( V_2 , L_65 , V_88 -> V_145 , V_88 -> V_146 , V_54 ) ;
F_63 ( V_2 , L_66 , V_88 -> V_147 , V_88 -> V_148 , V_54 ) ;
return 0 ;
}
static int F_65 ( struct V_121 * V_121 , struct V_114 * V_114 )
{
struct V_87 * V_88 = V_121 -> V_122 ;
return F_42 ( V_114 , F_64 , V_88 ,
& V_88 -> V_93 , V_113 ) ;
}
static int F_66 ( struct V_121 * V_121 , struct V_114 * V_114 )
{
struct V_87 * V_88 = V_121 -> V_122 ;
F_37 ( & V_88 -> V_93 , V_113 ) ;
return F_53 ( V_121 , V_114 ) ;
}
static int F_67 ( struct V_1 * V_2 , void * V_144 )
{
struct V_87 * V_88 = V_2 -> V_100 ;
unsigned long V_30 = V_101 ;
struct V_9 * V_149 , * V_150 ;
F_2 ( V_2 , L_49 , 0 ) ;
F_22 ( & V_88 -> V_46 -> V_57 ) ;
V_149 = V_88 -> V_92 ;
if ( V_149 )
F_14 ( V_2 , V_149 , V_30 ) ;
V_150 = V_88 -> V_151 ;
if ( V_150 && V_150 != V_149 ) {
V_149 = V_150 ;
F_14 ( V_2 , V_149 , V_30 ) ;
}
V_150 = V_88 -> V_152 ;
if ( V_150 && V_150 != V_149 )
F_14 ( V_2 , V_150 , V_30 ) ;
F_24 ( & V_88 -> V_46 -> V_57 ) ;
return 0 ;
}
static int F_68 ( struct V_121 * V_121 , struct V_114 * V_114 )
{
struct V_87 * V_88 = V_121 -> V_122 ;
return F_42 ( V_114 , F_67 , V_88 ,
& V_88 -> V_93 , V_113 ) ;
}
static int F_69 ( struct V_121 * V_121 , struct V_114 * V_114 )
{
struct V_87 * V_88 = V_121 -> V_122 ;
F_37 ( & V_88 -> V_93 , V_113 ) ;
return F_53 ( V_121 , V_114 ) ;
}
void F_70 ( struct V_87 * V_88 )
{
struct V_115 * V_153 = V_88 -> V_46 -> V_129 ;
struct V_115 * V_115 ;
if ( ! V_153 )
return;
V_115 = F_55 ( L_67 , V_153 ) ;
if ( F_56 ( V_115 ) )
goto V_126;
V_88 -> V_154 = V_115 ;
V_115 = F_57 ( L_68 , V_130 | V_131 ,
V_88 -> V_154 , V_88 ,
& V_155 ) ;
if ( F_56 ( V_115 ) )
goto V_126;
V_88 -> V_156 = V_115 ;
V_115 = F_57 ( L_69 , V_130 | V_131 ,
V_88 -> V_154 , V_88 ,
& V_157 ) ;
if ( F_56 ( V_115 ) )
goto V_126;
V_88 -> V_158 = V_115 ;
return;
V_126:
F_71 ( V_88 ) ;
F_59 ( V_88 , L_62 ) ;
}
void F_71 ( struct V_87 * V_88 )
{
F_60 ( & V_88 -> V_156 ) ;
F_60 ( & V_88 -> V_158 ) ;
F_60 ( & V_88 -> V_154 ) ;
}
static void F_72 ( struct V_1 * V_2 , struct V_159 * V_160 )
{
struct V_161 * V_162 = F_73 ( V_160 , struct V_161 , V_163 ) ;
F_2 ( V_2 , L_70 , V_162 -> V_164 ,
F_31 ( V_165 , & V_162 -> V_63 ) ? L_71 : L_72 ,
F_31 ( V_166 , & V_162 -> V_63 ) ? L_73 : L_74 ,
F_31 ( V_167 , & V_162 -> V_63 ) ? L_75 : L_76
) ;
}
static int F_74 ( struct V_1 * V_2 , void * V_144 )
{
struct V_47 * V_42 = V_2 -> V_100 ;
F_2 ( V_2 , L_49 , 0 ) ;
if ( F_75 ( V_42 , V_168 ) ) {
F_76 ( V_2 , V_42 -> V_169 ) ;
F_77 ( V_2 , V_42 -> V_169 , L_77 , F_72 ) ;
F_78 ( V_42 ) ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 , void * V_144 )
{
struct V_47 * V_42 = V_2 -> V_100 ;
F_2 ( V_2 , L_49 , 0 ) ;
if ( F_75 ( V_42 , V_168 ) ) {
F_76 ( V_2 , V_42 -> V_170 ) ;
F_77 ( V_2 , V_42 -> V_170 , L_78 , NULL ) ;
F_78 ( V_42 ) ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , void * V_144 )
{
struct V_47 * V_42 = V_2 -> V_100 ;
struct V_45 * V_46 = V_42 -> V_46 ;
unsigned long V_30 = V_101 ;
struct V_9 * V_149 , * V_150 ;
int V_32 ;
F_2 ( V_2 , L_49 , 0 ) ;
F_6 ( V_2 , V_91 ) ;
F_22 ( & V_46 -> V_57 ) ;
for ( V_32 = 1 ; V_32 >= 0 ; -- V_32 ) {
V_149 = F_23 ( & V_42 -> V_58 [ V_32 ] ,
struct V_9 , V_59 ) ;
V_150 = F_23 ( & V_42 -> V_171 [ V_32 ] ,
struct V_9 , V_172 ) ;
if ( V_149 )
F_9 ( V_2 , V_149 , V_30 ) ;
if ( V_150 && V_150 != V_149 )
F_9 ( V_2 , V_150 , V_30 ) ;
}
F_24 ( & V_46 -> V_57 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , void * V_144 )
{
struct V_47 * V_42 = V_2 -> V_100 ;
struct V_173 * V_174 ;
enum V_175 V_176 ;
if ( ! F_75 ( V_42 , V_168 ) )
return - V_177 ;
V_174 = & V_42 -> V_178 -> V_174 ;
F_22 ( & V_174 -> V_179 ) ;
for ( V_176 = V_180 ; V_176 <= V_181 ; V_176 ++ ) {
F_2 ( V_2 , L_79 , V_174 -> V_182 [ V_176 ] ) ;
}
F_24 ( & V_174 -> V_179 ) ;
F_78 ( V_42 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , void * V_144 )
{
struct V_47 * V_42 = V_2 -> V_100 ;
F_2 ( V_2 , L_79 , ( unsigned long long ) V_42 -> V_183 ) ;
return 0 ;
}
void F_83 ( struct V_47 * V_42 )
{
struct V_115 * V_184 = V_42 -> V_46 -> V_128 ;
char V_185 [ 8 ] ;
char V_186 [ 8 ] ;
char * V_187 = NULL ;
struct V_115 * V_115 ;
if ( ! V_184 || ! V_188 )
return;
snprintf ( V_186 , sizeof( V_186 ) , L_80 , V_42 -> V_44 ) ;
V_115 = F_55 ( V_186 , V_184 ) ;
if ( F_56 ( V_115 ) )
goto V_126;
V_42 -> V_189 = V_115 ;
snprintf ( V_185 , sizeof( V_185 ) , L_80 , V_42 -> V_43 ) ;
V_187 = F_84 ( V_190 , L_81 ,
V_42 -> V_46 -> V_125 , V_42 -> V_44 ) ;
if ( ! V_187 )
goto V_126;
V_115 = F_85 ( V_185 , V_188 , V_187 ) ;
F_86 ( V_187 ) ;
V_187 = NULL ;
if ( F_56 ( V_115 ) )
goto V_126;
V_42 -> V_191 = V_115 ;
#define F_87 ( V_125 ) do { \
dentry = debugfs_create_file(#name, S_IRUSR|S_IRGRP, \
device->debugfs_vol, device, \
&device_ ## name ## _fops); \
if (IS_ERR_OR_NULL(dentry)) \
goto fail; \
device->debugfs_vol_ ## name = dentry; \
} while (0)
F_87 ( V_192 ) ;
F_87 ( V_193 ) ;
F_87 ( V_194 ) ;
F_87 ( V_195 ) ;
F_87 ( V_196 ) ;
#undef F_87
return;
V_126:
F_88 ( V_42 ) ;
F_59 ( V_42 , L_82 ) ;
}
void F_88 ( struct V_47 * V_42 )
{
F_60 ( & V_42 -> V_191 ) ;
F_60 ( & V_42 -> V_197 ) ;
F_60 ( & V_42 -> V_198 ) ;
F_60 ( & V_42 -> V_199 ) ;
F_60 ( & V_42 -> V_200 ) ;
F_60 ( & V_42 -> V_201 ) ;
F_60 ( & V_42 -> V_189 ) ;
}
void F_89 ( struct V_202 * V_203 )
{
struct V_115 * V_204 = V_203 -> V_88 -> V_154 ;
struct V_115 * V_115 ;
char V_186 [ 8 ] ;
if ( ! V_204 )
return;
snprintf ( V_186 , sizeof( V_186 ) , L_80 , V_203 -> V_42 -> V_44 ) ;
V_115 = F_55 ( V_186 , V_204 ) ;
if ( F_56 ( V_115 ) )
goto V_126;
V_203 -> V_205 = V_115 ;
return;
V_126:
F_90 ( V_203 ) ;
F_59 ( V_203 , L_82 ) ;
}
void F_90 ( struct V_202 * V_203 )
{
F_60 ( & V_203 -> V_205 ) ;
}
static int F_91 ( struct V_1 * V_2 , void * V_144 )
{
F_2 ( V_2 , L_83 , F_92 () ) ;
F_2 ( V_2 , L_84 , V_206 ) ;
F_2 ( V_2 , L_85 , V_207 ) ;
F_2 ( V_2 , L_86 , V_208 ) ;
F_2 ( V_2 , L_87 , V_209 ) ;
return 0 ;
}
static int F_93 ( struct V_121 * V_121 , struct V_114 * V_114 )
{
return F_50 ( V_114 , F_91 , NULL ) ;
}
void F_94 ( void )
{
F_60 ( & V_124 ) ;
F_60 ( & V_188 ) ;
F_60 ( & V_210 ) ;
F_60 ( & V_211 ) ;
}
int T_1 F_95 ( void )
{
struct V_115 * V_115 ;
V_115 = F_55 ( L_88 , NULL ) ;
if ( F_56 ( V_115 ) )
goto V_126;
V_211 = V_115 ;
V_115 = F_57 ( L_89 , 0444 , V_211 , NULL , & V_212 ) ;
if ( F_56 ( V_115 ) )
goto V_126;
V_210 = V_115 ;
V_115 = F_55 ( L_90 , V_211 ) ;
if ( F_56 ( V_115 ) )
goto V_126;
V_124 = V_115 ;
V_115 = F_55 ( L_91 , V_211 ) ;
if ( F_56 ( V_115 ) )
goto V_126;
V_188 = V_115 ;
return 0 ;
V_126:
F_94 () ;
if ( V_115 )
return F_96 ( V_115 ) ;
else
return - V_213 ;
}
