static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 , * V_7 = NULL ;
int V_8 = 0 , V_9 = 0 ;
F_2 ( L_1 , V_10 , V_1 ) ;
F_3 ( & V_4 -> V_11 ) ;
V_6 = V_4 -> V_12 ;
do {
struct V_13 * V_14 ;
struct V_15 * V_16 ;
V_14 = F_4 ( V_6 , struct V_13 , V_17 ) ;
V_16 = & V_14 -> V_16 ;
if ( V_16 -> V_18 ( V_16 ) ) {
V_9 = 1 ;
V_7 = NULL ;
} else if ( V_7 == NULL )
V_7 = V_6 ;
V_6 = V_6 -> V_19 ;
if ( V_6 == V_4 -> V_12 && V_8 ++ > V_20 ) {
F_5 ( V_21
L_2 , V_1 ) ;
break;
}
} while ( V_6 != V_7 );
F_6 ( & V_4 -> V_11 ) ;
F_2 ( L_3 , V_10 , V_1 ) ;
return F_7 ( V_9 ) ;
}
static void F_8 ( struct V_3 * V_4 , struct V_13 * V_14 )
{
F_9 ( & V_4 -> V_11 ) ;
if ( ! F_10 ( V_4 -> V_12 ) ) {
if ( V_4 -> V_12 == & V_14 -> V_17 )
V_4 -> V_12 = V_4 -> V_12 -> V_19 ;
F_11 ( & V_14 -> V_17 ) ;
} else {
F_12 ( V_4 -> V_12 != & V_14 -> V_17 ) ;
V_4 -> V_12 = NULL ;
}
F_13 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 == NULL ) {
F_14 ( & V_4 -> V_22 ) ;
F_15 ( V_4 ) ;
}
}
static int F_16 ( struct V_13 * V_14 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_3 * V_4 ;
int V_27 , V_28 = V_14 -> V_16 . V_29 & V_30 ? V_31 : 0 ;
F_17 ( & V_32 ) ;
V_24 = & V_33 [ V_14 -> V_16 . V_1 % V_34 ] ;
F_18 (n, h) {
V_4 = F_19 ( V_26 , struct V_3 , V_22 ) ;
if ( V_4 -> V_1 == V_14 -> V_16 . V_1 )
break;
}
if ( V_26 == NULL ) {
V_4 = F_20 ( sizeof( struct V_3 ) , V_35 ) ;
if ( V_4 == NULL ) {
F_21 ( & V_32 ) ;
return - V_36 ;
}
F_22 ( & V_4 -> V_11 ) ;
V_4 -> V_1 = V_14 -> V_16 . V_1 ;
F_23 ( & V_4 -> V_22 , V_24 ) ;
}
F_21 ( & V_32 ) ;
F_9 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 ) {
F_24 ( & V_14 -> V_17 , V_4 -> V_12 ) ;
F_13 ( & V_4 -> V_11 ) ;
V_27 = 0 ;
} else {
F_25 ( & V_14 -> V_17 ) ;
V_4 -> V_12 = & V_14 -> V_17 ;
F_13 ( & V_4 -> V_11 ) ;
V_28 |= V_14 -> V_16 . V_37 ;
V_27 = F_26 ( V_14 -> V_16 . V_1 , F_1 ,
V_28 , V_14 -> V_16 . V_38 , V_4 ) ;
if ( V_27 < 0 )
F_8 ( V_4 , V_14 ) ;
}
return V_27 ;
}
static void F_27 ( struct V_13 * V_14 )
{
struct V_3 * V_4 ;
struct V_25 * V_26 ;
struct V_23 * V_24 ;
F_17 ( & V_32 ) ;
V_24 = & V_33 [ V_14 -> V_16 . V_1 % V_34 ] ;
F_18 (n, h) {
V_4 = F_19 ( V_26 , struct V_3 , V_22 ) ;
if ( V_4 -> V_1 == V_14 -> V_16 . V_1 )
break;
}
F_12 ( V_26 == NULL ) ;
F_12 ( V_4 -> V_12 == NULL ) ;
if ( F_10 ( V_4 -> V_12 ) )
F_28 ( V_14 -> V_16 . V_1 , V_4 ) ;
F_8 ( V_4 , V_14 ) ;
F_21 ( & V_32 ) ;
}
static void F_29 ( unsigned long V_39 )
{
struct V_13 * V_14 = (struct V_13 * ) V_39 ;
V_14 -> V_16 . V_18 ( & V_14 -> V_16 ) ;
F_30 ( & V_14 -> V_40 , V_41 + F_31 ( & V_14 -> V_16 ) ) ;
}
static void F_32 ( unsigned long V_39 )
{
struct V_13 * V_14 = (struct V_13 * ) V_39 ;
unsigned int V_42 , V_43 = 0 , V_44 ;
unsigned long V_29 ;
F_33 ( & V_14 -> V_16 . V_11 , V_29 ) ;
if ( V_14 -> V_16 . V_1 ) {
V_43 = F_34 ( V_14 , V_45 ) ;
F_35 ( V_14 , V_45 , 0 ) ;
}
V_42 = F_34 ( V_14 , V_46 ) ;
V_44 = F_34 ( V_14 , V_47 ) ;
V_14 -> V_48 |= V_44 & V_49 ;
if ( ( V_42 & V_50 ) && ( V_14 -> V_43 & V_51 ) &&
( ! F_36 ( & V_14 -> V_16 . V_52 -> V_53 ) || V_14 -> V_16 . V_54 ) &&
( V_44 & V_55 ) ) {
V_42 &= ~ ( V_56 | V_50 ) ;
V_42 |= V_57 ;
}
if ( ! ( V_42 & V_50 ) )
F_37 ( V_14 ) ;
if ( V_14 -> V_16 . V_1 )
F_35 ( V_14 , V_45 , V_43 ) ;
F_38 ( & V_14 -> V_16 . V_11 , V_29 ) ;
F_30 ( & V_14 -> V_40 ,
V_41 + F_31 ( & V_14 -> V_16 ) + V_58 / 5 ) ;
}
static int F_39 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
int V_59 = 0 ;
if ( V_14 -> V_60 & V_61 ) {
F_2 ( L_4 , F_40 ( V_16 ) ) ;
V_14 -> V_40 . V_62 = F_32 ;
V_14 -> V_40 . V_39 = ( unsigned long ) V_14 ;
F_30 ( & V_14 -> V_40 , V_41 +
F_31 ( V_16 ) + V_58 / 5 ) ;
}
if ( ! V_16 -> V_1 ) {
V_14 -> V_40 . V_39 = ( unsigned long ) V_14 ;
F_30 ( & V_14 -> V_40 , V_41 + F_31 ( V_16 ) ) ;
} else
V_59 = F_16 ( V_14 ) ;
return V_59 ;
}
static void F_41 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
F_42 ( & V_14 -> V_40 ) ;
V_14 -> V_40 . V_62 = F_29 ;
if ( V_16 -> V_1 )
F_27 ( V_14 ) ;
}
static int F_43 ( struct V_13 * V_14 )
{
unsigned long V_63 = V_64 << V_14 -> V_16 . V_65 ;
unsigned int V_66 = 8 << V_14 -> V_16 . V_65 ;
struct V_15 * V_16 = & V_14 -> V_16 ;
int V_27 = - V_67 ;
switch ( V_16 -> V_68 ) {
case V_69 :
case V_70 :
V_63 += V_16 -> V_71 ;
if ( F_44 ( V_63 , V_66 , L_5 ) )
V_27 = 0 ;
else
V_27 = - V_72 ;
break;
}
return V_27 ;
}
static void F_45 ( struct V_13 * V_14 )
{
unsigned long V_73 = V_64 << V_14 -> V_16 . V_65 ;
unsigned int V_66 = 8 << V_14 -> V_16 . V_65 ;
struct V_15 * V_16 = & V_14 -> V_16 ;
switch ( V_16 -> V_68 ) {
case V_69 :
case V_70 :
F_46 ( V_16 -> V_71 + V_73 , V_66 ) ;
break;
}
}
struct V_13 * F_47 ( int line )
{
return & V_74 [ line ] ;
}
void F_48 (
void (* F_49)( int V_16 , struct V_15 * V_14 , T_2 * V_75 ) )
{
V_76 = F_49 ;
}
static void F_50 ( struct V_15 * V_16 , int V_29 )
{
struct V_13 * V_14 = F_51 ( V_16 ) ;
V_14 -> V_77 &= ~ V_78 ;
if ( V_16 -> type == V_79 ) {
if ( F_43 ( V_14 ) == 0 )
V_14 -> V_77 |= V_78 ;
} else if ( V_29 & V_80 ) {
int V_4 ;
for ( V_4 = 0 ; V_4 < V_81 ; V_4 ++ ) {
if ( V_82 [ V_4 ] == V_14 -> V_16 . V_71 ) {
if ( F_43 ( V_14 ) == 0 )
V_14 -> V_77 |= V_78 ;
break;
}
}
}
V_83 -> V_84 ( V_16 , V_29 ) ;
if ( V_16 -> type != V_79 && V_14 -> V_77 & V_78 )
F_45 ( V_14 ) ;
}
static int F_52 ( struct V_15 * V_16 )
{
struct V_13 * V_14 = F_51 ( V_16 ) ;
int V_27 ;
V_27 = V_83 -> V_85 ( V_16 ) ;
if ( V_27 == 0 && V_16 -> type == V_79 ) {
V_27 = F_43 ( V_14 ) ;
if ( V_27 < 0 )
V_83 -> V_86 ( V_16 ) ;
}
return V_27 ;
}
static void F_53 ( struct V_15 * V_16 )
{
struct V_13 * V_14 = F_51 ( V_16 ) ;
if ( V_16 -> type == V_79 )
F_45 ( V_14 ) ;
V_83 -> V_86 ( V_16 ) ;
}
static void F_54 ( struct V_87 * V_88 )
{
V_88 -> V_84 = F_50 ;
V_88 -> V_85 = F_52 ;
V_88 -> V_86 = F_53 ;
}
static inline void F_55 ( struct V_13 * V_14 )
{
V_14 -> V_16 . V_89 |= V_90 ? V_91 : 0 ;
}
static void T_3 F_56 ( void )
{
struct V_13 * V_14 ;
static int V_92 = 1 ;
int V_4 , V_93 = 0 ;
if ( ! V_92 )
return;
V_92 = 0 ;
if ( V_94 > V_95 )
V_94 = V_95 ;
for ( V_4 = 0 ; V_4 < V_94 ; V_4 ++ ) {
struct V_13 * V_14 = & V_74 [ V_4 ] ;
struct V_15 * V_16 = & V_14 -> V_16 ;
V_16 -> line = V_4 ;
F_57 ( V_14 ) ;
if ( ! V_83 )
V_83 = V_16 -> V_88 ;
V_16 -> V_88 = & V_96 ;
F_58 ( & V_14 -> V_40 ) ;
V_14 -> V_40 . V_62 = F_29 ;
V_14 -> V_88 = & V_97 ;
V_14 -> V_98 = ~ V_99 ;
V_14 -> V_100 = V_99 ;
}
V_96 = * V_83 ;
F_54 ( & V_96 ) ;
if ( V_101 )
V_93 = V_31 ;
for ( V_4 = 0 , V_14 = V_74 ;
V_4 < F_59 ( V_102 ) && V_4 < V_94 ;
V_4 ++ , V_14 ++ ) {
struct V_15 * V_16 = & V_14 -> V_16 ;
V_16 -> V_71 = V_102 [ V_4 ] . V_16 ;
V_16 -> V_1 = F_60 ( V_102 [ V_4 ] . V_1 ) ;
V_16 -> V_37 = 0 ;
V_16 -> V_103 = V_102 [ V_4 ] . V_104 * 16 ;
V_16 -> V_29 = V_102 [ V_4 ] . V_29 ;
V_16 -> V_105 = 0 ;
V_16 -> V_106 = V_102 [ V_4 ] . V_107 ;
V_16 -> V_68 = V_102 [ V_4 ] . V_108 ;
V_16 -> V_65 = V_102 [ V_4 ] . V_109 ;
F_61 ( V_14 ) ;
V_16 -> V_37 |= V_93 ;
if ( V_76 != NULL )
V_76 ( V_4 , & V_14 -> V_16 , & V_14 -> V_75 ) ;
}
}
static void T_3
F_62 ( struct V_110 * V_111 , struct V_112 * V_113 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_94 ; V_4 ++ ) {
struct V_13 * V_14 = & V_74 [ V_4 ] ;
if ( V_14 -> V_16 . type == V_114 )
continue;
if ( V_14 -> V_16 . V_113 )
continue;
V_14 -> V_16 . V_113 = V_113 ;
F_55 ( V_14 ) ;
F_63 ( V_111 , & V_14 -> V_16 ) ;
}
}
static void F_64 ( struct V_115 * V_116 , const char * V_117 ,
unsigned int V_118 )
{
struct V_13 * V_14 = & V_74 [ V_116 -> V_119 ] ;
F_65 ( V_14 , V_117 , V_118 ) ;
}
static int F_66 ( struct V_115 * V_116 , char * V_120 )
{
struct V_15 * V_16 ;
int V_59 ;
if ( V_116 -> V_119 >= V_94 )
V_116 -> V_119 = 0 ;
V_16 = & V_74 [ V_116 -> V_119 ] . V_16 ;
V_16 -> V_121 = V_116 ;
V_59 = F_67 ( V_16 , V_120 , false ) ;
if ( V_59 != 0 )
V_16 -> V_121 = NULL ;
return V_59 ;
}
static int F_68 ( struct V_115 * V_116 , char * V_38 , int V_122 ,
char * V_120 )
{
char V_123 [] = L_6 ;
unsigned char V_68 ;
T_4 V_124 ;
int V_4 ;
if ( strncmp ( V_38 , V_123 , 4 ) != 0 )
return - V_125 ;
if ( F_69 ( V_120 , & V_68 , & V_124 , & V_120 ) )
return - V_125 ;
for ( V_4 = 0 ; V_4 < V_94 ; V_4 ++ ) {
struct V_15 * V_16 = & V_74 [ V_4 ] . V_16 ;
if ( V_16 -> V_68 != V_68 )
continue;
if ( ( V_68 == V_126 || V_68 == V_127 ||
V_68 == V_128 || V_68 == V_129 )
&& ( V_16 -> V_130 != V_124 ) )
continue;
if ( V_68 == V_70 && V_16 -> V_71 != V_124 )
continue;
V_116 -> V_119 = V_4 ;
V_16 -> V_121 = V_116 ;
return F_67 ( V_16 , V_120 , true ) ;
}
return - V_125 ;
}
static int T_3 F_70 ( void )
{
if ( V_94 == 0 )
return - V_125 ;
F_56 () ;
F_71 ( & V_131 ) ;
return 0 ;
}
int T_3 F_72 ( struct V_15 * V_16 )
{
struct V_15 * V_132 ;
if ( V_16 -> line >= F_59 ( V_74 ) || V_94 == 0 )
return - V_125 ;
F_56 () ;
V_132 = & V_74 [ V_16 -> line ] . V_16 ;
V_132 -> V_71 = V_16 -> V_71 ;
V_132 -> V_106 = V_16 -> V_106 ;
V_132 -> V_1 = V_16 -> V_1 ;
V_132 -> V_37 = V_16 -> V_37 ;
V_132 -> V_103 = V_16 -> V_103 ;
V_132 -> V_133 = V_16 -> V_133 ;
V_132 -> V_65 = V_16 -> V_65 ;
V_132 -> V_68 = V_16 -> V_68 ;
V_132 -> V_29 = V_16 -> V_29 ;
V_132 -> V_130 = V_16 -> V_130 ;
V_132 -> V_134 = V_16 -> V_134 ;
V_132 -> V_135 = V_16 -> V_135 ;
V_132 -> type = V_16 -> type ;
V_132 -> line = V_16 -> line ;
F_61 ( F_51 ( V_132 ) ) ;
if ( V_16 -> F_34 )
V_132 -> F_34 = V_16 -> F_34 ;
if ( V_16 -> F_35 )
V_132 -> F_35 = V_16 -> F_35 ;
if ( V_16 -> V_18 )
V_132 -> V_18 = V_16 -> V_18 ;
return 0 ;
}
void F_73 ( int line )
{
struct V_13 * V_14 = & V_74 [ line ] ;
struct V_15 * V_16 = & V_14 -> V_16 ;
if ( ! V_136 && F_74 ( V_16 ) &&
V_16 -> type != V_137 ) {
unsigned char V_138 = 0xa5 ;
F_35 ( V_14 , V_139 , V_138 ) ;
if ( F_34 ( V_14 , V_139 ) == V_138 )
V_14 -> V_138 = V_138 ;
}
F_75 ( & V_140 , V_16 ) ;
}
void F_76 ( int line )
{
struct V_13 * V_14 = & V_74 [ line ] ;
struct V_15 * V_16 = & V_14 -> V_16 ;
V_14 -> V_138 = 0 ;
if ( V_14 -> V_75 & V_141 ) {
F_77 ( V_16 , V_142 , 0xE0 ) ;
F_78 ( V_14 ) ;
F_77 ( V_16 , V_142 , 0 ) ;
V_16 -> V_103 = 921600 * 16 ;
}
F_79 ( & V_140 , V_16 ) ;
}
static int F_80 ( struct V_143 * V_113 )
{
struct V_144 * V_132 = F_81 ( & V_113 -> V_113 ) ;
struct V_13 V_145 ;
int V_27 , V_4 , V_93 = 0 ;
memset ( & V_145 , 0 , sizeof( V_145 ) ) ;
if ( V_101 )
V_93 = V_31 ;
for ( V_4 = 0 ; V_132 && V_132 -> V_29 != 0 ; V_132 ++ , V_4 ++ ) {
V_145 . V_16 . V_71 = V_132 -> V_71 ;
V_145 . V_16 . V_106 = V_132 -> V_106 ;
V_145 . V_16 . V_1 = V_132 -> V_1 ;
V_145 . V_16 . V_37 = V_132 -> V_37 ;
V_145 . V_16 . V_103 = V_132 -> V_103 ;
V_145 . V_16 . V_65 = V_132 -> V_65 ;
V_145 . V_16 . V_68 = V_132 -> V_68 ;
V_145 . V_16 . V_29 = V_132 -> V_29 ;
V_145 . V_16 . V_130 = V_132 -> V_130 ;
V_145 . V_16 . V_105 = V_132 -> V_105 ;
V_145 . V_16 . V_135 = V_132 -> V_135 ;
V_145 . V_16 . type = V_132 -> type ;
V_145 . V_16 . F_34 = V_132 -> F_34 ;
V_145 . V_16 . F_35 = V_132 -> F_35 ;
V_145 . V_16 . V_18 = V_132 -> V_18 ;
V_145 . V_16 . V_146 = V_132 -> V_146 ;
V_145 . V_16 . V_147 = V_132 -> V_147 ;
V_145 . V_16 . V_148 = V_132 -> V_148 ;
V_145 . V_16 . V_149 = V_132 -> V_149 ;
V_145 . V_16 . V_150 = V_132 -> V_150 ;
V_145 . V_16 . V_113 = & V_113 -> V_113 ;
V_145 . V_16 . V_37 |= V_93 ;
V_27 = F_82 ( & V_145 ) ;
if ( V_27 < 0 ) {
F_83 ( & V_113 -> V_113 , L_7
L_8 , V_4 ,
V_132 -> V_71 , ( unsigned long long ) V_132 -> V_130 ,
V_132 -> V_1 , V_27 ) ;
}
}
return 0 ;
}
static int F_84 ( struct V_143 * V_113 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_94 ; V_4 ++ ) {
struct V_13 * V_14 = & V_74 [ V_4 ] ;
if ( V_14 -> V_16 . V_113 == & V_113 -> V_113 )
F_85 ( V_4 ) ;
}
return 0 ;
}
static int F_86 ( struct V_143 * V_113 , T_5 V_52 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_95 ; V_4 ++ ) {
struct V_13 * V_14 = & V_74 [ V_4 ] ;
if ( V_14 -> V_16 . type != V_151 && V_14 -> V_16 . V_113 == & V_113 -> V_113 )
F_75 ( & V_140 , & V_14 -> V_16 ) ;
}
return 0 ;
}
static int F_87 ( struct V_143 * V_113 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_95 ; V_4 ++ ) {
struct V_13 * V_14 = & V_74 [ V_4 ] ;
if ( V_14 -> V_16 . type != V_151 && V_14 -> V_16 . V_113 == & V_113 -> V_113 )
F_76 ( V_4 ) ;
}
return 0 ;
}
static struct V_13 * F_88 ( struct V_15 * V_16 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_94 ; V_4 ++ )
if ( F_89 ( & V_74 [ V_4 ] . V_16 , V_16 ) )
return & V_74 [ V_4 ] ;
V_4 = V_16 -> line ;
if ( V_4 < V_94 && V_74 [ V_4 ] . V_16 . type == V_151 &&
V_74 [ V_4 ] . V_16 . V_71 == 0 )
return & V_74 [ V_4 ] ;
for ( V_4 = 0 ; V_4 < V_94 ; V_4 ++ )
if ( V_74 [ V_4 ] . V_16 . type == V_151 &&
V_74 [ V_4 ] . V_16 . V_71 == 0 )
return & V_74 [ V_4 ] ;
for ( V_4 = 0 ; V_4 < V_94 ; V_4 ++ )
if ( V_74 [ V_4 ] . V_16 . type == V_151 )
return & V_74 [ V_4 ] ;
return NULL ;
}
int F_82 ( struct V_13 * V_14 )
{
struct V_13 * V_145 ;
int V_27 = - V_152 ;
if ( V_14 -> V_16 . V_103 == 0 )
return - V_67 ;
F_17 ( & V_153 ) ;
V_145 = F_88 ( & V_14 -> V_16 ) ;
if ( V_145 && V_145 -> V_16 . type != V_114 ) {
if ( V_145 -> V_16 . V_113 )
F_90 ( & V_140 , & V_145 -> V_16 ) ;
V_145 -> V_16 . V_71 = V_14 -> V_16 . V_71 ;
V_145 -> V_16 . V_106 = V_14 -> V_16 . V_106 ;
V_145 -> V_16 . V_1 = V_14 -> V_16 . V_1 ;
V_145 -> V_16 . V_37 = V_14 -> V_16 . V_37 ;
V_145 -> V_16 . V_103 = V_14 -> V_16 . V_103 ;
V_145 -> V_16 . V_133 = V_14 -> V_16 . V_133 ;
V_145 -> V_16 . V_65 = V_14 -> V_16 . V_65 ;
V_145 -> V_16 . V_68 = V_14 -> V_16 . V_68 ;
V_145 -> V_16 . V_29 = V_14 -> V_16 . V_29 | V_154 ;
V_145 -> V_60 = V_14 -> V_60 ;
V_145 -> V_16 . V_130 = V_14 -> V_16 . V_130 ;
V_145 -> V_16 . V_134 = V_14 -> V_16 . V_134 ;
V_145 -> V_16 . V_135 = V_14 -> V_16 . V_135 ;
V_145 -> V_155 = V_14 -> V_155 ;
V_145 -> V_75 = V_14 -> V_75 ;
V_145 -> V_16 . V_156 = V_14 -> V_16 . V_156 ;
V_145 -> V_16 . V_157 = V_14 -> V_16 . V_157 ;
V_145 -> V_16 . V_158 = V_14 -> V_16 . V_158 ;
V_145 -> V_16 . V_159 = V_14 -> V_16 . V_159 ;
V_145 -> V_160 = V_14 -> V_160 ;
if ( V_145 -> V_16 . V_133 && ! V_145 -> V_155 )
V_145 -> V_155 = V_145 -> V_16 . V_133 ;
if ( V_14 -> V_16 . V_113 )
V_145 -> V_16 . V_113 = V_14 -> V_16 . V_113 ;
if ( V_14 -> V_16 . V_29 & V_161 )
V_145 -> V_16 . type = V_14 -> V_16 . type ;
F_61 ( V_145 ) ;
if ( V_14 -> V_16 . F_34 )
V_145 -> V_16 . F_34 = V_14 -> V_16 . F_34 ;
if ( V_14 -> V_16 . F_35 )
V_145 -> V_16 . F_35 = V_14 -> V_16 . F_35 ;
if ( V_14 -> V_16 . V_18 )
V_145 -> V_16 . V_18 = V_14 -> V_16 . V_18 ;
if ( V_14 -> V_16 . V_147 )
V_145 -> V_16 . V_147 = V_14 -> V_16 . V_147 ;
if ( V_14 -> V_16 . V_148 )
V_145 -> V_16 . V_148 = V_14 -> V_16 . V_148 ;
if ( V_14 -> V_16 . V_149 )
V_145 -> V_16 . V_149 = V_14 -> V_16 . V_149 ;
if ( V_14 -> V_16 . V_162 )
V_145 -> V_16 . V_162 = V_14 -> V_16 . V_162 ;
if ( V_14 -> V_16 . V_163 )
V_145 -> V_16 . V_163 = V_14 -> V_16 . V_163 ;
if ( V_14 -> V_16 . V_164 )
V_145 -> V_16 . V_164 = V_14 -> V_16 . V_164 ;
if ( V_14 -> V_16 . V_150 )
V_145 -> V_16 . V_150 = V_14 -> V_16 . V_150 ;
if ( V_14 -> V_16 . V_146 )
V_145 -> V_16 . V_146 = V_14 -> V_16 . V_146 ;
if ( V_14 -> V_165 )
V_145 -> V_165 = V_14 -> V_165 ;
if ( V_14 -> V_166 )
V_145 -> V_166 = V_14 -> V_166 ;
if ( V_145 -> V_16 . type != V_114 ) {
if ( V_76 != NULL )
V_76 ( 0 , & V_145 -> V_16 ,
& V_145 -> V_75 ) ;
F_55 ( V_145 ) ;
V_27 = F_63 ( & V_140 ,
& V_145 -> V_16 ) ;
if ( V_27 == 0 )
V_27 = V_145 -> V_16 . line ;
} else {
F_91 ( V_145 -> V_16 . V_113 ,
L_9 ,
V_145 -> V_16 . V_71 ,
( unsigned long long ) V_145 -> V_16 . V_130 ,
V_145 -> V_16 . V_1 ) ;
V_27 = 0 ;
}
}
F_21 ( & V_153 ) ;
return V_27 ;
}
void F_85 ( int line )
{
struct V_13 * V_145 = & V_74 [ line ] ;
F_17 ( & V_153 ) ;
if ( V_145 -> V_167 ) {
unsigned long V_29 ;
F_33 ( & V_145 -> V_16 . V_11 , V_29 ) ;
F_92 ( V_145 ) ;
F_38 ( & V_145 -> V_16 . V_11 , V_29 ) ;
}
F_90 ( & V_140 , & V_145 -> V_16 ) ;
if ( V_168 ) {
V_145 -> V_16 . V_29 &= ~ V_154 ;
V_145 -> V_16 . type = V_151 ;
V_145 -> V_16 . V_113 = & V_168 -> V_113 ;
V_145 -> V_75 = 0 ;
F_55 ( V_145 ) ;
F_63 ( & V_140 , & V_145 -> V_16 ) ;
} else {
V_145 -> V_16 . V_113 = NULL ;
}
F_21 ( & V_153 ) ;
}
static int T_3 F_93 ( void )
{
int V_27 ;
if ( V_94 == 0 )
return - V_125 ;
F_56 () ;
F_94 ( L_10 ,
V_94 , V_101 ? L_11 : L_12 ) ;
#ifdef F_95
V_27 = F_96 ( & V_140 , V_95 ) ;
#else
V_140 . V_169 = V_95 ;
V_27 = F_97 ( & V_140 ) ;
#endif
if ( V_27 )
goto V_170;
V_27 = F_98 () ;
if ( V_27 )
goto V_171;
V_168 = F_99 ( L_13 ,
V_172 ) ;
if ( ! V_168 ) {
V_27 = - V_36 ;
goto V_173;
}
V_27 = F_100 ( V_168 ) ;
if ( V_27 )
goto V_174;
F_62 ( & V_140 , & V_168 -> V_113 ) ;
V_27 = F_101 ( & V_175 ) ;
if ( V_27 == 0 )
goto V_170;
F_102 ( V_168 ) ;
V_174:
F_103 ( V_168 ) ;
V_173:
F_104 () ;
V_171:
#ifdef F_95
F_105 ( & V_140 , V_95 ) ;
#else
F_106 ( & V_140 ) ;
#endif
V_170:
return V_27 ;
}
static void T_6 F_107 ( void )
{
struct V_143 * V_176 = V_168 ;
V_168 = NULL ;
F_108 ( & V_175 ) ;
F_109 ( V_176 ) ;
F_104 () ;
#ifdef F_95
F_105 ( & V_140 , V_95 ) ;
#else
F_106 ( & V_140 ) ;
#endif
}
static void T_7 F_110 ( void )
{
#undef V_177
#define V_177 "8250_core."
F_111 ( V_101 , & V_178 , & V_101 , 0644 ) ;
F_111 ( V_94 , & V_178 , & V_94 , 0644 ) ;
F_111 ( V_90 , & V_178 , & V_90 , 0644 ) ;
#ifdef F_112
F_113 ( V_177 , V_82 ,
& V_179 , . V_180 = & V_181 ,
0444 , - 1 , 0 ) ;
#endif
}
