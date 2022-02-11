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
F_7 ( V_2 , V_70 & V_76 , & V_6 , L_43 ) ;
F_5 ( V_2 , '\n' ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_47 * V_42 , struct V_77 * V_78 ,
unsigned long V_30 )
{
bool V_79 = false ;
struct V_68 * V_69 ;
F_29 (peer_req, lh, w.list) {
if ( V_79 && ! ( V_69 -> V_63 & V_71 ) )
continue;
if ( V_42 )
F_2 ( V_2 , L_27 , V_42 -> V_43 , V_42 -> V_44 ) ;
F_2 ( V_2 , L_44 ,
( unsigned long long ) V_69 -> V_32 . V_33 , V_69 -> V_32 . V_34 >> 9 ,
( V_69 -> V_63 & V_80 ) ? 'W' : 'R' ,
F_3 ( V_30 - V_69 -> V_52 ) ) ;
F_27 ( V_2 , V_69 ) ;
if ( V_69 -> V_63 & V_71 )
break;
else
V_79 = true ;
}
}
static void F_30 ( struct V_1 * V_2 ,
struct V_47 * V_42 , unsigned long V_30 )
{
F_6 ( V_2 , L_45 ) ;
F_22 ( & V_42 -> V_46 -> V_57 ) ;
F_28 ( V_2 , V_42 , & V_42 -> V_81 , V_30 ) ;
F_28 ( V_2 , V_42 , & V_42 -> V_82 , V_30 ) ;
F_28 ( V_2 , V_42 , & V_42 -> V_83 , V_30 ) ;
F_24 ( & V_42 -> V_46 -> V_57 ) ;
if ( F_31 ( V_84 , & V_42 -> V_63 ) ) {
F_2 ( V_2 , L_46 ,
V_42 -> V_43 , V_42 -> V_44 ,
F_3 ( V_30 - V_42 -> V_85 ) ) ;
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
struct V_86 * V_87 ,
unsigned long V_30 )
{
struct V_9 * V_10 ;
unsigned int V_88 = 0 ;
unsigned int V_89 = 0 ;
F_6 ( V_2 , L_47 V_90 ) ;
F_22 ( & V_46 -> V_57 ) ;
F_29 (req, &connection->transfer_log, tl_requests) {
unsigned int V_49 = 0 ;
unsigned int V_11 ;
++ V_88 ;
if ( ! ( V_88 & 0x1ff ) ) {
struct V_9 * V_91 ;
F_34 ( & V_10 -> V_92 ) ;
F_24 ( & V_46 -> V_57 ) ;
F_35 () ;
F_22 ( & V_46 -> V_57 ) ;
V_91 = F_36 ( V_10 , V_93 ) ;
if ( F_37 ( & V_10 -> V_92 , V_94 ) )
V_10 = V_91 ;
if ( & V_10 -> V_93 == & V_87 -> V_95 )
break;
}
V_11 = V_10 -> V_12 ;
if ( V_10 -> V_13 == NULL )
V_49 |= 1 ;
if ( ( V_11 & V_96 ) && ( V_11 & V_17 ) )
V_49 |= 2 ;
if ( V_11 & V_97 ) {
if ( ! ( V_11 & V_23 ) )
V_49 |= 4 ;
if ( V_11 & V_21 )
V_49 |= 8 ;
if ( ! ( V_11 & V_24 ) )
V_49 |= 16 ;
}
if ( ( V_49 & V_89 ) == V_49 )
continue;
V_89 |= V_49 ;
F_2 ( V_2 , L_34 , V_88 ) ;
F_14 ( V_2 , V_10 , V_30 ) ;
if ( V_89 == 0x1f )
break;
}
F_24 ( & V_46 -> V_57 ) ;
}
static int F_38 ( struct V_1 * V_2 , void * V_98 )
{
struct V_45 * V_46 = V_2 -> V_99 ;
struct V_86 * V_87 ;
unsigned long V_54 = V_100 ;
V_87 = F_39 ( V_46 ) ;
if ( ! V_87 || ! F_40 ( & V_87 -> V_92 ) )
return - V_101 ;
F_2 ( V_2 , L_48 , 0 ) ;
F_6 ( V_2 , L_49 ) ;
F_26 ( V_2 , V_46 , V_54 ) ;
F_5 ( V_2 , '\n' ) ;
F_6 ( V_2 , L_50 ) ;
F_15 ( V_2 , V_46 , V_54 ) ;
F_5 ( V_2 , '\n' ) ;
F_6 ( V_2 , L_51 ) ;
F_16 () ;
if ( V_87 -> V_102 . V_103 ) {
struct V_104 * V_105 = F_41 ( V_87 -> V_102 . V_103 -> V_106 ) ;
int V_107 = V_105 -> V_108 - V_105 -> V_109 ;
F_2 ( V_2 , L_52 , V_107 ) ;
V_107 = V_105 -> V_110 - V_105 -> V_111 ;
F_2 ( V_2 , L_53 , V_107 ) ;
}
F_20 () ;
F_5 ( V_2 , '\n' ) ;
F_6 ( V_2 , L_54 ) ;
F_32 ( V_2 , V_46 , V_54 ) ;
F_5 ( V_2 , '\n' ) ;
F_6 ( V_2 , L_55 ) ;
F_21 ( V_2 , V_46 , V_54 ) ;
F_5 ( V_2 , '\n' ) ;
F_6 ( V_2 , L_56 ) ;
F_33 ( V_2 , V_46 , V_87 , V_54 ) ;
F_5 ( V_2 , '\n' ) ;
V_54 = V_100 - V_54 ;
if ( V_54 )
F_2 ( V_2 , L_57 , F_3 ( V_54 ) ) ;
F_37 ( & V_87 -> V_92 , V_112 ) ;
return 0 ;
}
static int F_42 ( struct V_113 * V_113 , int (* F_43)( struct V_1 * , void * ) ,
void * V_102 , struct V_92 * V_92 ,
void (* F_44)( struct V_92 * ) )
{
struct V_114 * V_115 ;
int V_116 = - V_101 ;
V_115 = V_113 -> V_117 . V_114 -> V_118 ;
F_45 ( F_46 ( V_115 ) ) ;
if ( F_47 ( V_113 -> V_117 . V_114 )
&& F_40 ( V_92 ) )
V_116 = 0 ;
F_48 ( F_46 ( V_115 ) ) ;
if ( ! V_116 ) {
V_116 = F_49 ( V_113 , F_43 , V_102 ) ;
if ( V_116 )
F_37 ( V_92 , F_44 ) ;
}
return V_116 ;
}
static int F_50 ( struct V_119 * V_119 , struct V_113 * V_113 )
{
struct V_45 * V_46 = V_119 -> V_120 ;
return F_42 ( V_113 , F_38 , V_46 ,
& V_46 -> V_92 , V_121 ) ;
}
static int F_51 ( struct V_119 * V_119 , struct V_113 * V_113 )
{
struct V_45 * V_46 = V_119 -> V_120 ;
F_37 ( & V_46 -> V_92 , V_121 ) ;
return F_52 ( V_119 , V_113 ) ;
}
void F_53 ( struct V_45 * V_46 )
{
struct V_114 * V_114 ;
if ( ! V_122 )
return;
V_114 = F_54 ( V_46 -> V_123 , V_122 ) ;
if ( F_55 ( V_114 ) )
goto V_124;
V_46 -> V_125 = V_114 ;
V_114 = F_54 ( L_58 , V_46 -> V_125 ) ;
if ( F_55 ( V_114 ) )
goto V_124;
V_46 -> V_126 = V_114 ;
V_114 = F_54 ( L_59 , V_46 -> V_125 ) ;
if ( F_55 ( V_114 ) )
goto V_124;
V_46 -> V_127 = V_114 ;
V_114 = F_56 ( L_60 , V_128 | V_129 ,
V_46 -> V_125 , V_46 ,
& V_130 ) ;
if ( F_55 ( V_114 ) )
goto V_124;
V_46 -> V_131 = V_114 ;
return;
V_124:
F_57 ( V_46 ) ;
F_58 ( V_46 , L_61 ) ;
}
static void F_59 ( struct V_114 * * V_132 )
{
F_60 ( * V_132 ) ;
* V_132 = NULL ;
}
void F_57 ( struct V_45 * V_46 )
{
F_59 ( & V_46 -> V_131 ) ;
F_59 ( & V_46 -> V_127 ) ;
F_59 ( & V_46 -> V_126 ) ;
F_59 ( & V_46 -> V_125 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
const struct V_133 * V_134 ,
unsigned long V_30 )
{
struct V_133 V_135 ;
do {
V_135 = * V_134 ;
} while ( V_135 . V_136 != V_134 -> V_136 );
if ( ! V_135 . V_137 )
return;
F_2 ( V_2 , L_62 ,
V_135 . V_136 ,
F_3 ( V_30 - V_135 . V_36 ) ,
V_135 . V_138 , V_135 . line ,
V_135 . V_137 ) ;
}
static void F_62 ( struct V_1 * V_2 ,
const char * V_139 ,
unsigned int V_136 , struct V_133 * V_134 , unsigned long V_30 )
{
unsigned int V_140 ;
unsigned int V_32 ;
F_2 ( V_2 , L_32 , V_139 ) ;
V_140 = V_136 % V_141 ;
for ( V_32 = V_140 ; V_32 < V_141 ; V_32 ++ )
F_61 ( V_2 , V_134 + V_32 , V_30 ) ;
for ( V_32 = 0 ; V_32 < V_140 ; V_32 ++ )
F_61 ( V_2 , V_134 + V_32 , V_30 ) ;
}
static int F_63 ( struct V_1 * V_2 , void * V_142 )
{
struct V_86 * V_87 = V_2 -> V_99 ;
unsigned long V_54 = V_100 ;
F_2 ( V_2 , L_48 , 0 ) ;
F_6 ( V_2 , L_63 ) ;
F_62 ( V_2 , L_64 , V_87 -> V_143 , V_87 -> V_144 , V_54 ) ;
F_62 ( V_2 , L_65 , V_87 -> V_145 , V_87 -> V_146 , V_54 ) ;
return 0 ;
}
static int F_64 ( struct V_119 * V_119 , struct V_113 * V_113 )
{
struct V_86 * V_87 = V_119 -> V_120 ;
return F_42 ( V_113 , F_63 , V_87 ,
& V_87 -> V_92 , V_112 ) ;
}
static int F_65 ( struct V_119 * V_119 , struct V_113 * V_113 )
{
struct V_86 * V_87 = V_119 -> V_120 ;
F_37 ( & V_87 -> V_92 , V_112 ) ;
return F_52 ( V_119 , V_113 ) ;
}
static int F_66 ( struct V_1 * V_2 , void * V_142 )
{
struct V_86 * V_87 = V_2 -> V_99 ;
unsigned long V_30 = V_100 ;
struct V_9 * V_147 , * V_148 ;
F_2 ( V_2 , L_48 , 0 ) ;
F_22 ( & V_87 -> V_46 -> V_57 ) ;
V_147 = V_87 -> V_91 ;
if ( V_147 )
F_14 ( V_2 , V_147 , V_30 ) ;
V_148 = V_87 -> V_149 ;
if ( V_148 && V_148 != V_147 ) {
V_147 = V_148 ;
F_14 ( V_2 , V_147 , V_30 ) ;
}
V_148 = V_87 -> V_150 ;
if ( V_148 && V_148 != V_147 )
F_14 ( V_2 , V_148 , V_30 ) ;
F_24 ( & V_87 -> V_46 -> V_57 ) ;
return 0 ;
}
static int F_67 ( struct V_119 * V_119 , struct V_113 * V_113 )
{
struct V_86 * V_87 = V_119 -> V_120 ;
return F_42 ( V_113 , F_66 , V_87 ,
& V_87 -> V_92 , V_112 ) ;
}
static int F_68 ( struct V_119 * V_119 , struct V_113 * V_113 )
{
struct V_86 * V_87 = V_119 -> V_120 ;
F_37 ( & V_87 -> V_92 , V_112 ) ;
return F_52 ( V_119 , V_113 ) ;
}
void F_69 ( struct V_86 * V_87 )
{
struct V_114 * V_151 = V_87 -> V_46 -> V_127 ;
struct V_114 * V_114 ;
if ( ! V_151 )
return;
V_114 = F_54 ( L_66 , V_151 ) ;
if ( F_55 ( V_114 ) )
goto V_124;
V_87 -> V_152 = V_114 ;
V_114 = F_56 ( L_67 , V_128 | V_129 ,
V_87 -> V_152 , V_87 ,
& V_153 ) ;
if ( F_55 ( V_114 ) )
goto V_124;
V_87 -> V_154 = V_114 ;
V_114 = F_56 ( L_68 , V_128 | V_129 ,
V_87 -> V_152 , V_87 ,
& V_155 ) ;
if ( F_55 ( V_114 ) )
goto V_124;
V_87 -> V_156 = V_114 ;
return;
V_124:
F_70 ( V_87 ) ;
F_58 ( V_87 , L_61 ) ;
}
void F_70 ( struct V_86 * V_87 )
{
F_59 ( & V_87 -> V_154 ) ;
F_59 ( & V_87 -> V_156 ) ;
F_59 ( & V_87 -> V_152 ) ;
}
static void F_71 ( struct V_1 * V_2 , struct V_157 * V_158 )
{
struct V_159 * V_160 = F_72 ( V_158 , struct V_159 , V_161 ) ;
F_2 ( V_2 , L_69 , V_160 -> V_162 ,
F_31 ( V_163 , & V_160 -> V_63 ) ? L_70 : L_71 ,
F_31 ( V_164 , & V_160 -> V_63 ) ? L_72 : L_73 ,
F_31 ( V_165 , & V_160 -> V_63 ) ? L_74 : L_75
) ;
}
static int F_73 ( struct V_1 * V_2 , void * V_142 )
{
struct V_47 * V_42 = V_2 -> V_99 ;
F_2 ( V_2 , L_48 , 0 ) ;
if ( F_74 ( V_42 , V_166 ) ) {
F_75 ( V_2 , V_42 -> V_167 ) ;
F_76 ( V_2 , V_42 -> V_167 , L_76 , F_71 ) ;
F_77 ( V_42 ) ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_2 , void * V_142 )
{
struct V_47 * V_42 = V_2 -> V_99 ;
F_2 ( V_2 , L_48 , 0 ) ;
if ( F_74 ( V_42 , V_166 ) ) {
F_75 ( V_2 , V_42 -> V_168 ) ;
F_76 ( V_2 , V_42 -> V_168 , L_77 , NULL ) ;
F_77 ( V_42 ) ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 , void * V_142 )
{
struct V_47 * V_42 = V_2 -> V_99 ;
struct V_45 * V_46 = V_42 -> V_46 ;
unsigned long V_30 = V_100 ;
struct V_9 * V_147 , * V_148 ;
int V_32 ;
F_2 ( V_2 , L_48 , 0 ) ;
F_6 ( V_2 , V_90 ) ;
F_22 ( & V_46 -> V_57 ) ;
for ( V_32 = 1 ; V_32 >= 0 ; -- V_32 ) {
V_147 = F_23 ( & V_42 -> V_58 [ V_32 ] ,
struct V_9 , V_59 ) ;
V_148 = F_23 ( & V_42 -> V_169 [ V_32 ] ,
struct V_9 , V_170 ) ;
if ( V_147 )
F_9 ( V_2 , V_147 , V_30 ) ;
if ( V_148 && V_148 != V_147 )
F_9 ( V_2 , V_148 , V_30 ) ;
}
F_24 ( & V_46 -> V_57 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , void * V_142 )
{
struct V_47 * V_42 = V_2 -> V_99 ;
struct V_171 * V_172 ;
enum V_173 V_174 ;
if ( ! F_74 ( V_42 , V_166 ) )
return - V_175 ;
V_172 = & V_42 -> V_176 -> V_172 ;
F_22 ( & V_172 -> V_177 ) ;
for ( V_174 = V_178 ; V_174 <= V_179 ; V_174 ++ ) {
F_2 ( V_2 , L_78 , V_172 -> V_180 [ V_174 ] ) ;
}
F_24 ( & V_172 -> V_177 ) ;
F_77 ( V_42 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , void * V_142 )
{
struct V_47 * V_42 = V_2 -> V_99 ;
F_2 ( V_2 , L_78 , ( unsigned long long ) V_42 -> V_181 ) ;
return 0 ;
}
void F_82 ( struct V_47 * V_42 )
{
struct V_114 * V_182 = V_42 -> V_46 -> V_126 ;
char V_183 [ 8 ] ;
char V_184 [ 8 ] ;
char * V_185 = NULL ;
struct V_114 * V_114 ;
if ( ! V_182 || ! V_186 )
return;
snprintf ( V_184 , sizeof( V_184 ) , L_79 , V_42 -> V_44 ) ;
V_114 = F_54 ( V_184 , V_182 ) ;
if ( F_55 ( V_114 ) )
goto V_124;
V_42 -> V_187 = V_114 ;
snprintf ( V_183 , sizeof( V_183 ) , L_79 , V_42 -> V_43 ) ;
V_185 = F_83 ( V_188 , L_80 ,
V_42 -> V_46 -> V_123 , V_42 -> V_44 ) ;
if ( ! V_185 )
goto V_124;
V_114 = F_84 ( V_183 , V_186 , V_185 ) ;
F_85 ( V_185 ) ;
V_185 = NULL ;
if ( F_55 ( V_114 ) )
goto V_124;
V_42 -> V_189 = V_114 ;
#define F_86 ( V_123 ) do { \
dentry = debugfs_create_file(#name, S_IRUSR|S_IRGRP, \
device->debugfs_vol, device, \
&device_ ## name ## _fops); \
if (IS_ERR_OR_NULL(dentry)) \
goto fail; \
device->debugfs_vol_ ## name = dentry; \
} while (0)
F_86 ( V_190 ) ;
F_86 ( V_191 ) ;
F_86 ( V_192 ) ;
F_86 ( V_193 ) ;
F_86 ( V_194 ) ;
#undef F_86
return;
V_124:
F_87 ( V_42 ) ;
F_58 ( V_42 , L_81 ) ;
}
void F_87 ( struct V_47 * V_42 )
{
F_59 ( & V_42 -> V_189 ) ;
F_59 ( & V_42 -> V_195 ) ;
F_59 ( & V_42 -> V_196 ) ;
F_59 ( & V_42 -> V_197 ) ;
F_59 ( & V_42 -> V_198 ) ;
F_59 ( & V_42 -> V_199 ) ;
F_59 ( & V_42 -> V_187 ) ;
}
void F_88 ( struct V_200 * V_201 )
{
struct V_114 * V_202 = V_201 -> V_87 -> V_152 ;
struct V_114 * V_114 ;
char V_184 [ 8 ] ;
if ( ! V_202 )
return;
snprintf ( V_184 , sizeof( V_184 ) , L_79 , V_201 -> V_42 -> V_44 ) ;
V_114 = F_54 ( V_184 , V_202 ) ;
if ( F_55 ( V_114 ) )
goto V_124;
V_201 -> V_203 = V_114 ;
return;
V_124:
F_89 ( V_201 ) ;
F_58 ( V_201 , L_81 ) ;
}
void F_89 ( struct V_200 * V_201 )
{
F_59 ( & V_201 -> V_203 ) ;
}
static int F_90 ( struct V_1 * V_2 , void * V_142 )
{
F_2 ( V_2 , L_82 , F_91 () ) ;
F_2 ( V_2 , L_83 , V_204 ) ;
F_2 ( V_2 , L_84 , V_205 ) ;
F_2 ( V_2 , L_85 , V_206 ) ;
F_2 ( V_2 , L_86 , V_207 ) ;
return 0 ;
}
static int F_92 ( struct V_119 * V_119 , struct V_113 * V_113 )
{
return F_49 ( V_113 , F_90 , NULL ) ;
}
void F_93 ( void )
{
F_59 ( & V_122 ) ;
F_59 ( & V_186 ) ;
F_59 ( & V_208 ) ;
F_59 ( & V_209 ) ;
}
int T_1 F_94 ( void )
{
struct V_114 * V_114 ;
V_114 = F_54 ( L_87 , NULL ) ;
if ( F_55 ( V_114 ) )
goto V_124;
V_209 = V_114 ;
V_114 = F_56 ( L_88 , 0444 , V_209 , NULL , & V_210 ) ;
if ( F_55 ( V_114 ) )
goto V_124;
V_208 = V_114 ;
V_114 = F_54 ( L_89 , V_209 ) ;
if ( F_55 ( V_114 ) )
goto V_124;
V_122 = V_114 ;
V_114 = F_54 ( L_90 , V_209 ) ;
if ( F_55 ( V_114 ) )
goto V_124;
V_186 = V_114 ;
return 0 ;
V_124:
F_93 () ;
if ( V_114 )
return F_95 ( V_114 ) ;
else
return - V_211 ;
}
