static inline int F_1 ( void )
{
return V_1 ;
}
void * F_2 ( void )
{
if ( F_1 () )
return V_2 . V_3 ;
return NULL ;
}
static int F_3 ( void )
{
return F_4 ( 65 ) ;
}
static int F_5 ( void )
{
return F_4 ( 12 ) ;
}
static inline struct V_4
F_6 ( T_1 V_5 , unsigned long * V_6 )
{
if ( F_4 ( 15 ) )
V_5 |= 1UL << 23 ;
return F_7 ( V_5 , V_6 ) ;
}
static inline int F_8 ( void )
{
if ( ! V_7 )
return - V_8 ;
return F_9 ( V_7 ) ;
}
static void F_10 ( void )
{
if ( ! F_5 () )
return;
V_7 = F_11 ( sizeof( * V_7 ) , V_9 ) ;
if ( ! V_7 )
return;
if ( F_8 () != 0 ) {
F_12 ( V_7 ) ;
V_7 = NULL ;
return;
}
}
static inline int F_13 ( unsigned int * V_10 , unsigned int V_11 )
{
return F_14 ( ( V_10 + ( V_11 >> 5 ) ) , ( V_11 & 0x1f ) ) ;
}
static inline int F_15 ( unsigned int V_12 )
{
if ( ! V_7 )
return 1 ;
return F_13 ( V_7 -> V_13 , V_12 ) ;
}
static inline int F_16 ( unsigned int V_14 )
{
if ( ! V_7 )
return V_14 < 16 ;
return F_13 ( V_7 -> V_15 , V_14 ) ;
}
static int F_17 ( T_1 V_5 , int * V_16 , int * V_17 ,
unsigned int * V_18 )
{
struct V_4 V_19 ;
unsigned long V_6 ;
int V_20 ;
if ( ! F_15 ( F_18 ( V_5 ) ) )
return - V_21 ;
V_19 = F_6 ( V_5 , & V_6 ) ;
switch ( V_19 . V_22 ) {
case V_23 :
* V_16 = ( int ) ( V_6 & 0xff ) ;
* V_17 = ( int ) ( ( V_6 >> 24 ) & 0xff ) ;
* V_18 = ( unsigned int ) ( V_6 >> 32 ) ;
V_20 = ( V_6 >> 16 ) & 0xff ;
if ( ( V_6 & ( 1UL << 57 ) ) && V_20 > 0 )
V_24 = V_20 ;
else
V_24 = 15 ;
switch ( * V_17 ) {
case V_25 :
case V_26 :
* V_18 |= 0x08000000 ;
break;
case V_27 :
case V_28 :
* V_18 |= 0x10000000 ;
break;
default:
break;
}
return 0 ;
case V_29 :
case V_30 :
case V_31 :
case V_32 :
return - V_21 ;
case V_33 :
case V_34 :
case V_35 :
return - V_36 ;
default:
F_19 () ;
}
}
void F_20 ( enum F_20 V_37 )
{
T_2 V_38 ;
switch ( V_37 ) {
case V_39 :
case V_40 :
if ( F_1 () )
break;
if ( V_41 ) {
F_21 ( & V_42 ) ;
break;
}
case V_43 :
F_22 ( & V_44 ) ;
if ( ! F_23 ( & V_45 ) ) {
V_38 = V_46 ;
F_24 ( & V_45 , V_38 ) ;
F_25 ( & V_45 ) ;
}
F_26 ( & V_44 ) ;
break;
case V_47 :
default:
break;
}
}
void F_27 ( unsigned long V_48 )
{
struct V_49 * V_50 = (struct V_49 * ) V_48 ;
if ( V_51 )
return;
F_22 ( & V_50 -> V_52 ) ;
F_20 ( F_28 ( V_50 , V_53 ) ) ;
F_26 ( & V_50 -> V_52 ) ;
}
static enum F_25 F_29 ( struct V_54 * V_55 )
{
if ( ! V_51 )
F_30 ( & V_56 ) ;
return V_57 ;
}
static void F_31 ( struct V_58 * V_59 )
{
F_32 ( V_60 ) ;
if ( ! V_51 )
F_30 ( & V_56 ) ;
}
static void F_33 ( unsigned long V_61 )
{
struct V_62 * V_63 ;
struct V_49 * V_50 ;
enum F_20 V_37 = V_47 ;
if ( F_1 () )
F_34 ( V_2 . V_3 , 0 ) ;
F_22 ( & V_64 ) ;
F_35 (ac) {
F_36 (aq, ac) {
F_22 ( & V_50 -> V_52 ) ;
V_37 = F_37 ( V_37 , F_38 ( V_50 , V_65 ) ) ;
F_26 ( & V_50 -> V_52 ) ;
}
}
F_26 ( & V_64 ) ;
F_20 ( V_37 ) ;
}
static int F_39 ( void )
{
struct V_62 * V_63 ;
struct V_49 * V_50 ;
F_22 ( & V_64 ) ;
F_35 (ac) {
F_36 (aq, ac) {
if ( V_50 -> V_66 == 0 )
continue;
F_26 ( & V_64 ) ;
return 1 ;
}
}
F_26 ( & V_64 ) ;
return 0 ;
}
static int F_40 ( void * V_48 )
{
F_41 ( V_37 , V_67 ) ;
F_42 ( V_67 , V_68 ) ;
F_43 () ;
while ( ! F_44 () ) {
F_45 ( & V_42 , & V_37 ) ;
F_46 ( V_69 ) ;
if ( V_51 || ! F_39 () ) {
F_47 () ;
F_48 () ;
}
F_46 ( V_70 ) ;
F_49 ( & V_42 , & V_37 ) ;
if ( F_50 () ) {
F_47 () ;
F_48 () ;
continue;
}
F_33 ( 0 ) ;
}
return 0 ;
}
static int F_51 ( void )
{
int V_71 ;
if ( F_1 () || V_41 )
return 0 ;
F_52 ( & V_72 ) ;
V_41 = F_53 ( F_40 , NULL , L_1 ) ;
V_71 = F_54 ( V_41 ) ;
if ( V_71 )
V_41 = NULL ;
F_55 ( & V_72 ) ;
return V_71 ;
}
static void F_56 ( void )
{
if ( ! V_41 )
return;
F_52 ( & V_72 ) ;
F_57 ( V_41 ) ;
V_41 = NULL ;
F_55 ( & V_72 ) ;
}
static int F_58 ( struct V_73 * V_74 , struct V_75 * V_76 )
{
struct V_77 * V_78 = F_59 ( V_76 ) ;
struct V_79 * V_12 ;
for ( V_12 = V_78 -> V_80 ; V_12 -> V_81 ; V_12 ++ ) {
if ( F_60 ( V_74 ) &&
V_12 -> V_81 & V_82 &&
V_12 -> V_83 == F_61 ( V_74 ) -> V_17 )
return 1 ;
if ( F_62 ( V_74 ) &&
V_12 -> V_81 & V_84 &&
V_12 -> V_83 == F_61 ( V_74 ) -> V_17 )
return 1 ;
}
return 0 ;
}
static int F_63 ( struct V_73 * V_74 , struct V_85 * V_86 )
{
struct V_87 * V_88 = F_61 ( V_74 ) ;
int V_89 = 0 ;
if ( ! V_88 )
return - V_21 ;
V_89 = F_64 ( V_86 , L_2 , V_88 -> V_17 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_64 ( V_86 , L_3 , V_88 -> V_17 ) ;
return V_89 ;
}
static int F_65 ( struct V_73 * V_74 )
{
struct V_87 * V_88 = F_61 ( V_74 ) ;
if ( V_88 -> V_76 && V_88 -> V_76 -> V_90 )
V_88 -> V_76 -> V_90 ( V_88 ) ;
return 0 ;
}
static int F_66 ( struct V_73 * V_74 )
{
struct V_87 * V_88 = F_61 ( V_74 ) ;
if ( V_88 -> V_76 && V_88 -> V_76 -> V_91 )
V_88 -> V_76 -> V_91 ( V_88 ) ;
return 0 ;
}
static void F_67 ( void )
{
F_68 ( V_92 , L_4 ) ;
V_51 = 1 ;
F_69 ( & V_93 ) ;
F_70 ( & V_56 ) ;
}
static int F_71 ( struct V_73 * V_74 , void * V_61 )
{
if ( F_60 ( V_74 ) )
F_72 ( V_74 ) ;
return 0 ;
}
static int F_73 ( struct V_73 * V_74 , void * V_61 )
{
if ( F_62 ( V_74 ) )
F_72 ( V_74 ) ;
return 0 ;
}
static int F_74 ( struct V_73 * V_74 , void * V_48 )
{
if ( F_62 ( V_74 ) &&
F_18 ( F_75 ( V_74 ) -> V_5 ) == ( int ) ( long ) V_48 )
F_72 ( V_74 ) ;
return 0 ;
}
static void F_76 ( void )
{
int V_71 ;
F_68 ( V_92 , L_5 ) ;
F_77 ( & V_94 , NULL , NULL ,
F_73 ) ;
F_77 ( & V_94 , NULL , NULL ,
F_71 ) ;
if ( F_3 () && ! F_1 () ) {
V_71 = F_78 ( & V_2 ) ;
V_1 = ( V_71 == 0 ) ;
}
if ( ! F_3 () && F_1 () ) {
F_79 ( & V_2 ) ;
V_1 = 0 ;
}
if ( ! V_95 )
V_96 = - 1 ;
V_51 = 0 ;
if ( V_1 )
F_34 ( V_2 . V_3 , 0 ) ;
F_80 ( & V_56 ) ;
F_81 ( V_97 , & V_93 ) ;
}
static int F_82 ( struct V_98 * V_99 , unsigned long V_100 ,
void * V_101 )
{
switch ( V_100 ) {
case V_102 :
case V_103 :
F_67 () ;
break;
case V_104 :
case V_105 :
F_76 () ;
break;
default:
break;
}
return V_106 ;
}
static int F_83 ( struct V_73 * V_74 )
{
struct V_87 * V_88 = F_61 ( V_74 ) ;
struct V_77 * V_78 = F_59 ( V_74 -> V_107 ) ;
int V_71 ;
F_22 ( & V_64 ) ;
if ( F_60 ( V_74 ) )
F_84 ( & F_85 ( V_74 ) -> V_108 , & V_109 ) ;
else
F_84 ( & F_75 ( V_74 ) -> V_108 ,
& F_75 ( V_74 ) -> V_110 -> V_111 ) ;
F_26 ( & V_64 ) ;
V_88 -> V_76 = V_78 ;
V_71 = V_78 -> V_112 ? V_78 -> V_112 ( V_88 ) : - V_21 ;
if ( V_71 ) {
F_22 ( & V_64 ) ;
if ( F_60 ( V_74 ) )
F_86 ( & F_85 ( V_74 ) -> V_108 ) ;
else
F_86 ( & F_75 ( V_74 ) -> V_108 ) ;
F_26 ( & V_64 ) ;
V_88 -> V_76 = NULL ;
}
return V_71 ;
}
static int F_87 ( struct V_73 * V_74 )
{
struct V_87 * V_88 = F_61 ( V_74 ) ;
struct V_77 * V_78 = V_88 -> V_76 ;
if ( V_78 -> remove )
V_78 -> remove ( V_88 ) ;
F_22 ( & V_64 ) ;
if ( F_60 ( V_74 ) )
F_86 ( & F_85 ( V_74 ) -> V_108 ) ;
else
F_86 ( & F_75 ( V_74 ) -> V_108 ) ;
F_26 ( & V_64 ) ;
return 0 ;
}
int F_88 ( struct V_77 * V_78 , struct V_113 * V_114 ,
char * V_115 )
{
struct V_75 * V_76 = & V_78 -> V_107 ;
if ( ! V_116 )
return - V_21 ;
V_76 -> V_117 = & V_94 ;
V_76 -> V_112 = F_83 ;
V_76 -> remove = F_87 ;
V_76 -> V_114 = V_114 ;
V_76 -> V_115 = V_115 ;
return F_89 ( V_76 ) ;
}
void F_90 ( struct V_77 * V_78 )
{
F_91 ( & V_78 -> V_107 ) ;
}
void F_92 ( void )
{
if ( V_51 )
return;
F_93 ( & V_118 ) ;
F_81 ( V_97 , & V_93 ) ;
F_69 ( & V_93 ) ;
}
static T_3 F_94 ( struct V_119 * V_117 , char * V_120 )
{
return snprintf ( V_120 , V_121 , L_6 , V_96 ) ;
}
static T_3 F_95 ( struct V_119 * V_117 ,
const char * V_120 , T_4 V_122 )
{
int V_14 ;
if ( sscanf ( V_120 , L_7 , & V_14 ) != 1 ||
V_14 < 0 || V_14 > V_24 )
return - V_123 ;
F_22 ( & V_124 ) ;
V_96 = V_14 ;
F_26 ( & V_124 ) ;
F_68 ( V_92 , L_8 , V_14 ) ;
return V_122 ;
}
static T_3 F_96 ( struct V_119 * V_117 , char * V_120 )
{
if ( ! V_7 )
return snprintf ( V_120 , V_121 , L_9 ) ;
return snprintf ( V_120 , V_121 ,
L_10 ,
V_7 -> V_125 [ 0 ] , V_7 -> V_125 [ 1 ] ,
V_7 -> V_125 [ 2 ] , V_7 -> V_125 [ 3 ] ,
V_7 -> V_125 [ 4 ] , V_7 -> V_125 [ 5 ] ,
V_7 -> V_125 [ 6 ] , V_7 -> V_125 [ 7 ] ) ;
}
static T_3 F_97 ( struct V_119 * V_117 , char * V_120 )
{
if ( ! V_7 )
return snprintf ( V_120 , V_121 , L_9 ) ;
return snprintf ( V_120 , V_121 ,
L_10 ,
V_7 -> V_15 [ 0 ] , V_7 -> V_15 [ 1 ] ,
V_7 -> V_15 [ 2 ] , V_7 -> V_15 [ 3 ] ,
V_7 -> V_15 [ 4 ] , V_7 -> V_15 [ 5 ] ,
V_7 -> V_15 [ 6 ] , V_7 -> V_15 [ 7 ] ) ;
}
static T_3 F_98 ( struct V_119 * V_117 , char * V_120 )
{
return snprintf ( V_120 , V_121 , L_6 , V_126 ) ;
}
static T_3 F_99 ( struct V_119 * V_117 , char * V_120 )
{
return snprintf ( V_120 , V_121 , L_6 ,
F_1 () ? 1 : 0 ) ;
}
static T_3 F_100 ( struct V_119 * V_117 ,
const char * V_120 , T_4 V_122 )
{
int time ;
if ( sscanf ( V_120 , L_6 , & time ) != 1 || time < 5 || time > 120 )
return - V_123 ;
V_126 = time ;
F_101 ( & V_118 , V_127 + V_126 * V_128 ) ;
return V_122 ;
}
static T_3 F_102 ( struct V_119 * V_117 , char * V_120 )
{
return snprintf ( V_120 , V_121 , L_6 , V_41 ? 1 : 0 ) ;
}
static T_3 F_103 ( struct V_119 * V_117 ,
const char * V_120 , T_4 V_122 )
{
int V_129 , V_71 ;
if ( sscanf ( V_120 , L_6 , & V_129 ) != 1 )
return - V_123 ;
if ( V_129 ) {
V_71 = F_51 () ;
if ( V_71 )
V_122 = V_71 ;
} else
F_56 () ;
return V_122 ;
}
static T_3 F_104 ( struct V_119 * V_117 , char * V_120 )
{
return snprintf ( V_120 , V_121 , L_11 , V_46 ) ;
}
static T_3 F_105 ( struct V_119 * V_117 , const char * V_120 ,
T_4 V_122 )
{
unsigned long long time ;
T_2 V_38 ;
if ( sscanf ( V_120 , L_11 , & time ) != 1 || time < 1 ||
time > 120000000000ULL )
return - V_123 ;
V_46 = time ;
V_38 = V_46 ;
F_22 ( & V_44 ) ;
F_106 ( & V_45 ) ;
F_107 ( & V_45 , V_38 ) ;
F_108 ( & V_45 , V_130 ) ;
F_26 ( & V_44 ) ;
return V_122 ;
}
static T_3 F_109 ( struct V_119 * V_117 , char * V_120 )
{
int V_131 ;
if ( V_7 )
V_131 = V_24 ? : - 1 ;
else
V_131 = 15 ;
return snprintf ( V_120 , V_121 , L_6 , V_131 ) ;
}
static int F_110 ( void )
{
int V_122 , V_132 , V_133 ;
struct V_4 V_19 ;
int V_134 , V_135 ;
F_22 ( & V_124 ) ;
if ( V_96 >= 0 ) {
F_26 ( & V_124 ) ;
return 0 ;
}
V_133 = - 1 ;
V_132 = 0 ;
for ( V_134 = 0 ; V_134 < V_136 ; V_134 ++ ) {
if ( ! F_16 ( V_134 ) )
continue;
V_122 = 0 ;
for ( V_135 = 0 ; V_135 < V_137 ; V_135 ++ ) {
if ( ! F_15 ( V_135 ) )
continue;
V_19 = F_6 ( F_111 ( V_135 , V_134 ) , NULL ) ;
if ( V_19 . V_22 != V_23 )
continue;
V_122 ++ ;
}
if ( V_122 > V_132 ) {
V_132 = V_122 ;
V_133 = V_134 ;
}
}
if ( V_133 >= 0 ) {
V_96 = V_133 ;
F_68 ( V_92 , L_12 , V_96 ) ;
F_26 ( & V_124 ) ;
return 0 ;
}
F_26 ( & V_124 ) ;
return - V_21 ;
}
static int F_112 ( struct V_73 * V_74 , void * V_48 )
{
return F_60 ( V_74 ) && F_85 ( V_74 ) -> V_12 == ( int ) ( long ) V_48 ;
}
static int F_113 ( struct V_73 * V_74 , void * V_48 )
{
return F_62 ( V_74 ) && F_75 ( V_74 ) -> V_5 == ( int ) ( long ) V_48 ;
}
static void F_114 ( struct V_138 * V_55 )
{
struct V_49 * V_50 ;
struct V_62 * V_63 ;
struct V_73 * V_74 ;
T_1 V_5 ;
int V_139 = 0 , type = 0 ;
unsigned int V_140 = 0 ;
int V_71 , V_12 , V_141 , V_142 , V_143 , V_144 = 0 ;
F_68 ( V_92 , L_13 ) ;
F_8 () ;
if ( F_110 () != 0 )
goto V_145;
for ( V_12 = 0 ; V_12 < V_137 ; V_12 ++ ) {
V_74 = F_115 ( & V_94 , NULL ,
( void * ) ( long ) V_12 ,
F_112 ) ;
V_63 = V_74 ? F_85 ( V_74 ) : NULL ;
if ( ! F_15 ( V_12 ) ) {
if ( V_74 ) {
F_77 ( & V_94 , NULL ,
( void * ) ( long ) V_12 ,
F_74 ) ;
F_72 ( V_74 ) ;
F_116 ( V_74 ) ;
}
continue;
}
V_143 = 0 ;
for ( V_141 = 0 ; V_141 < V_136 ; V_141 ++ ) {
V_5 = F_111 ( V_12 , V_141 ) ;
V_74 = F_115 ( & V_94 , NULL ,
( void * ) ( long ) V_5 ,
F_113 ) ;
V_50 = V_74 ? F_75 ( V_74 ) : NULL ;
if ( ! F_16 ( V_141 ) ) {
if ( V_74 ) {
F_72 ( V_74 ) ;
F_116 ( V_74 ) ;
}
continue;
}
V_71 = F_17 ( V_5 , & V_139 , & type , & V_140 ) ;
if ( V_74 ) {
F_22 ( & V_50 -> V_52 ) ;
if ( V_71 == - V_21 ||
( V_63 && V_63 -> V_140 != V_140 ) )
V_50 -> V_146 = V_147 ;
V_142 = V_50 -> V_146 == V_147 ;
F_26 ( & V_50 -> V_52 ) ;
if ( V_142 )
F_72 ( V_74 ) ;
F_116 ( V_74 ) ;
if ( ! V_142 ) {
V_143 ++ ;
if ( V_141 == V_96 )
V_144 ++ ;
continue;
}
}
if ( V_71 )
continue;
if ( ! V_63 ) {
V_63 = F_117 ( V_12 , V_139 ,
type , V_140 ) ;
if ( ! V_63 )
continue;
V_63 -> V_88 . V_73 . V_117 = & V_94 ;
V_63 -> V_88 . V_73 . V_148 = V_149 ;
F_118 ( & V_63 -> V_88 . V_73 ,
L_14 , V_12 ) ;
V_71 = F_119 ( & V_63 -> V_88 . V_73 ) ;
if ( V_71 ) {
F_116 ( & V_63 -> V_88 . V_73 ) ;
V_63 = NULL ;
break;
}
F_120 ( & V_63 -> V_88 . V_73 ) ;
}
V_50 = F_121 ( V_5 , type ) ;
if ( ! V_50 )
continue;
V_50 -> V_110 = V_63 ;
V_50 -> V_88 . V_73 . V_117 = & V_94 ;
V_50 -> V_88 . V_73 . V_148 = & V_63 -> V_88 . V_73 ;
F_118 ( & V_50 -> V_88 . V_73 ,
L_15 , V_12 , V_141 ) ;
F_22 ( & V_50 -> V_52 ) ;
F_20 ( F_28 ( V_50 , V_65 ) ) ;
F_26 ( & V_50 -> V_52 ) ;
V_71 = F_119 ( & V_50 -> V_88 . V_73 ) ;
if ( V_71 ) {
F_116 ( & V_50 -> V_88 . V_73 ) ;
continue;
}
V_143 ++ ;
if ( V_141 == V_96 )
V_144 ++ ;
}
if ( V_63 ) {
if ( ! V_143 )
F_72 ( & V_63 -> V_88 . V_73 ) ;
F_116 ( & V_63 -> V_88 . V_73 ) ;
}
}
if ( V_144 < 1 )
F_68 ( V_150 , L_16 ,
V_96 ) ;
V_145:
F_101 ( & V_118 , V_127 + V_126 * V_128 ) ;
}
static void F_122 ( unsigned long V_101 )
{
if ( V_51 )
return;
F_81 ( V_97 , & V_93 ) ;
}
static void F_123 ( void )
{
int V_134 , V_135 ;
for ( V_134 = 0 ; V_134 < V_136 ; V_134 ++ ) {
if ( ! F_16 ( V_134 ) )
continue;
for ( V_135 = 0 ; V_135 < V_137 ; V_135 ++ ) {
if ( ! F_15 ( V_135 ) )
continue;
F_124 ( F_111 ( V_135 , V_134 ) ) ;
}
}
}
int T_5 F_125 ( void )
{
V_151 = F_126 ( L_17 , 1 , 1 ,
V_152 * sizeof( long ) ) ;
F_127 ( V_151 , & V_153 ) ;
F_128 ( V_151 , V_154 ) ;
return 0 ;
}
void F_129 ( void )
{
F_130 ( V_151 ) ;
}
int T_5 F_131 ( void )
{
int V_131 ;
int V_71 , V_134 ;
V_71 = F_125 () ;
if ( V_71 )
return V_71 ;
if ( F_132 () != 0 ) {
F_133 ( L_18 ) ;
return - V_21 ;
}
F_10 () ;
if ( V_7 )
V_131 =
V_24 ? V_24 : V_136 - 1 ;
else
V_131 = 15 ;
if ( V_96 < - 1 || V_96 > V_131 ) {
F_133 ( L_19 ,
V_96 ) ;
V_96 = - 1 ;
}
if ( V_96 >= 0 )
V_95 = 1 ;
if ( F_3 () ) {
V_71 = F_78 ( & V_2 ) ;
V_1 = ( V_71 == 0 ) ;
}
F_134 ( & V_155 ) ;
V_71 = F_135 ( & V_94 ) ;
if ( V_71 )
goto V_145;
for ( V_134 = 0 ; V_156 [ V_134 ] ; V_134 ++ ) {
V_71 = F_136 ( & V_94 , V_156 [ V_134 ] ) ;
if ( V_71 )
goto V_157;
}
V_149 = F_137 ( L_17 ) ;
V_71 = F_54 ( V_149 ) ;
if ( V_71 )
goto V_157;
F_138 ( & V_118 , F_122 , 0 ) ;
if ( V_158 )
V_46 = 1500000 ;
F_139 ( & V_44 ) ;
F_140 ( & V_45 , V_159 , V_130 ) ;
V_45 . V_160 = F_29 ;
if ( V_161 ) {
V_71 = F_51 () ;
if ( V_71 )
goto V_162;
}
V_71 = F_141 ( & V_163 ) ;
if ( V_71 )
goto V_164;
F_81 ( V_97 , & V_93 ) ;
V_116 = true ;
return 0 ;
V_164:
F_56 () ;
V_162:
F_106 ( & V_45 ) ;
F_142 ( V_149 ) ;
V_157:
while ( V_134 -- )
F_143 ( & V_94 , V_156 [ V_134 ] ) ;
F_144 ( & V_94 ) ;
V_145:
F_145 ( & V_155 ) ;
if ( F_1 () )
F_79 ( & V_2 ) ;
F_12 ( V_7 ) ;
return V_71 ;
}
