static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 , * V_7 = NULL ;
int V_8 = 0 , V_9 = 0 ;
F_2 ( L_1 , V_1 ) ;
F_3 ( & V_4 -> V_10 ) ;
V_6 = V_4 -> V_11 ;
do {
struct V_12 * V_13 ;
struct V_14 * V_15 ;
V_13 = F_4 ( V_6 , struct V_12 , V_16 ) ;
V_15 = & V_13 -> V_15 ;
if ( V_15 -> V_17 ( V_15 ) ) {
V_9 = 1 ;
V_7 = NULL ;
} else if ( V_7 == NULL )
V_7 = V_6 ;
V_6 = V_6 -> V_18 ;
if ( V_6 == V_4 -> V_11 && V_8 ++ > V_19 ) {
F_5 ( V_20
L_2 , V_1 ) ;
break;
}
} while ( V_6 != V_7 );
F_6 ( & V_4 -> V_10 ) ;
F_2 ( L_3 ) ;
return F_7 ( V_9 ) ;
}
static void F_8 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
F_9 ( & V_4 -> V_10 ) ;
if ( ! F_10 ( V_4 -> V_11 ) ) {
if ( V_4 -> V_11 == & V_13 -> V_16 )
V_4 -> V_11 = V_4 -> V_11 -> V_18 ;
F_11 ( & V_13 -> V_16 ) ;
} else {
F_12 ( V_4 -> V_11 != & V_13 -> V_16 ) ;
V_4 -> V_11 = NULL ;
}
F_13 ( & V_4 -> V_10 ) ;
if ( V_4 -> V_11 == NULL ) {
F_14 ( & V_4 -> V_21 ) ;
F_15 ( V_4 ) ;
}
}
static int F_16 ( struct V_12 * V_13 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_3 * V_4 ;
int V_26 , V_27 = V_13 -> V_15 . V_28 & V_29 ? V_30 : 0 ;
F_17 ( & V_31 ) ;
V_23 = & V_32 [ V_13 -> V_15 . V_1 % V_33 ] ;
F_18 (n, h) {
V_4 = F_19 ( V_25 , struct V_3 , V_21 ) ;
if ( V_4 -> V_1 == V_13 -> V_15 . V_1 )
break;
}
if ( V_25 == NULL ) {
V_4 = F_20 ( sizeof( struct V_3 ) , V_34 ) ;
if ( V_4 == NULL ) {
F_21 ( & V_31 ) ;
return - V_35 ;
}
F_22 ( & V_4 -> V_10 ) ;
V_4 -> V_1 = V_13 -> V_15 . V_1 ;
F_23 ( & V_4 -> V_21 , V_23 ) ;
}
F_21 ( & V_31 ) ;
F_9 ( & V_4 -> V_10 ) ;
if ( V_4 -> V_11 ) {
F_24 ( & V_13 -> V_16 , V_4 -> V_11 ) ;
F_13 ( & V_4 -> V_10 ) ;
V_26 = 0 ;
} else {
F_25 ( & V_13 -> V_16 ) ;
V_4 -> V_11 = & V_13 -> V_16 ;
F_13 ( & V_4 -> V_10 ) ;
V_27 |= V_13 -> V_15 . V_36 ;
V_26 = F_26 ( V_13 -> V_15 . V_1 , F_1 ,
V_27 , L_4 , V_4 ) ;
if ( V_26 < 0 )
F_8 ( V_4 , V_13 ) ;
}
return V_26 ;
}
static void F_27 ( struct V_12 * V_13 )
{
struct V_3 * V_4 ;
struct V_24 * V_25 ;
struct V_22 * V_23 ;
F_17 ( & V_31 ) ;
V_23 = & V_32 [ V_13 -> V_15 . V_1 % V_33 ] ;
F_18 (n, h) {
V_4 = F_19 ( V_25 , struct V_3 , V_21 ) ;
if ( V_4 -> V_1 == V_13 -> V_15 . V_1 )
break;
}
F_12 ( V_25 == NULL ) ;
F_12 ( V_4 -> V_11 == NULL ) ;
if ( F_10 ( V_4 -> V_11 ) )
F_28 ( V_13 -> V_15 . V_1 , V_4 ) ;
F_8 ( V_4 , V_13 ) ;
F_21 ( & V_31 ) ;
}
static void F_29 ( unsigned long V_37 )
{
struct V_12 * V_13 = (struct V_12 * ) V_37 ;
V_13 -> V_15 . V_17 ( & V_13 -> V_15 ) ;
F_30 ( & V_13 -> V_38 , V_39 + F_31 ( & V_13 -> V_15 ) ) ;
}
static void F_32 ( unsigned long V_37 )
{
struct V_12 * V_13 = (struct V_12 * ) V_37 ;
unsigned int V_40 , V_41 = 0 , V_42 ;
unsigned long V_28 ;
F_33 ( & V_13 -> V_15 . V_10 , V_28 ) ;
if ( V_13 -> V_15 . V_1 ) {
V_41 = F_34 ( V_13 , V_43 ) ;
F_35 ( V_13 , V_43 , 0 ) ;
}
V_40 = F_34 ( V_13 , V_44 ) ;
V_42 = F_34 ( V_13 , V_45 ) ;
V_13 -> V_46 |= V_42 & V_47 ;
if ( ( V_40 & V_48 ) && ( V_13 -> V_41 & V_49 ) &&
( ! F_36 ( & V_13 -> V_15 . V_50 -> V_51 ) || V_13 -> V_15 . V_52 ) &&
( V_42 & V_53 ) ) {
V_40 &= ~ ( V_54 | V_48 ) ;
V_40 |= V_55 ;
}
if ( ! ( V_40 & V_48 ) )
F_37 ( V_13 ) ;
if ( V_13 -> V_15 . V_1 )
F_35 ( V_13 , V_43 , V_41 ) ;
F_38 ( & V_13 -> V_15 . V_10 , V_28 ) ;
F_30 ( & V_13 -> V_38 ,
V_39 + F_31 ( & V_13 -> V_15 ) + V_56 / 5 ) ;
}
static int F_39 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_13 -> V_15 ;
int V_57 = 0 ;
if ( V_13 -> V_58 & V_59 ) {
F_40 ( L_5 , F_41 ( V_15 ) ) ;
V_13 -> V_38 . V_60 = F_32 ;
V_13 -> V_38 . V_37 = ( unsigned long ) V_13 ;
F_30 ( & V_13 -> V_38 , V_39 +
F_31 ( V_15 ) + V_56 / 5 ) ;
}
if ( ! V_15 -> V_1 ) {
V_13 -> V_38 . V_37 = ( unsigned long ) V_13 ;
F_30 ( & V_13 -> V_38 , V_39 + F_31 ( V_15 ) ) ;
} else
V_57 = F_16 ( V_13 ) ;
return V_57 ;
}
static void F_42 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_13 -> V_15 ;
F_43 ( & V_13 -> V_38 ) ;
V_13 -> V_38 . V_60 = F_29 ;
if ( V_15 -> V_1 )
F_27 ( V_13 ) ;
}
static int F_44 ( struct V_12 * V_13 )
{
unsigned long V_61 = V_62 << V_13 -> V_15 . V_63 ;
unsigned int V_64 = 8 << V_13 -> V_15 . V_63 ;
struct V_14 * V_15 = & V_13 -> V_15 ;
int V_26 = - V_65 ;
switch ( V_15 -> V_66 ) {
case V_67 :
case V_68 :
V_61 += V_15 -> V_69 ;
if ( F_45 ( V_61 , V_64 , L_6 ) )
V_26 = 0 ;
else
V_26 = - V_70 ;
break;
}
return V_26 ;
}
static void F_46 ( struct V_12 * V_13 )
{
unsigned long V_71 = V_62 << V_13 -> V_15 . V_63 ;
unsigned int V_64 = 8 << V_13 -> V_15 . V_63 ;
struct V_14 * V_15 = & V_13 -> V_15 ;
switch ( V_15 -> V_66 ) {
case V_67 :
case V_68 :
F_47 ( V_15 -> V_69 + V_71 , V_64 ) ;
break;
}
}
struct V_12 * F_48 ( int line )
{
return & V_72 [ line ] ;
}
void F_49 (
void (* F_50)( int V_15 , struct V_14 * V_13 , unsigned short * V_73 ) )
{
V_74 = F_50 ;
}
static void F_51 ( struct V_14 * V_15 , int V_28 )
{
struct V_12 * V_13 = F_52 ( V_15 ) ;
V_13 -> V_75 &= ~ V_76 ;
if ( V_15 -> type == V_77 ) {
if ( F_44 ( V_13 ) == 0 )
V_13 -> V_75 |= V_76 ;
} else if ( V_28 & V_78 ) {
int V_4 ;
for ( V_4 = 0 ; V_4 < V_79 ; V_4 ++ ) {
if ( V_80 [ V_4 ] == V_13 -> V_15 . V_69 ) {
if ( F_44 ( V_13 ) == 0 )
V_13 -> V_75 |= V_76 ;
break;
}
}
}
V_81 -> V_82 ( V_15 , V_28 ) ;
if ( V_15 -> type != V_77 && V_13 -> V_75 & V_76 )
F_46 ( V_13 ) ;
}
static int F_53 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_52 ( V_15 ) ;
int V_26 ;
V_26 = V_81 -> V_83 ( V_15 ) ;
if ( V_26 == 0 && V_15 -> type == V_77 ) {
V_26 = F_44 ( V_13 ) ;
if ( V_26 < 0 )
V_81 -> V_84 ( V_15 ) ;
}
return V_26 ;
}
static void F_54 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_52 ( V_15 ) ;
if ( V_15 -> type == V_77 )
F_46 ( V_13 ) ;
V_81 -> V_84 ( V_15 ) ;
}
static void F_55 ( struct V_85 * V_86 )
{
V_86 -> V_82 = F_51 ;
V_86 -> V_83 = F_53 ;
V_86 -> V_84 = F_54 ;
}
static void T_2 F_56 ( void )
{
struct V_12 * V_13 ;
static int V_87 = 1 ;
int V_4 , V_88 = 0 ;
if ( ! V_87 )
return;
V_87 = 0 ;
if ( V_89 > V_90 )
V_89 = V_90 ;
for ( V_4 = 0 ; V_4 < V_89 ; V_4 ++ ) {
struct V_12 * V_13 = & V_72 [ V_4 ] ;
struct V_14 * V_15 = & V_13 -> V_15 ;
V_15 -> line = V_4 ;
F_57 ( V_13 ) ;
if ( ! V_81 )
V_81 = V_15 -> V_86 ;
V_15 -> V_86 = & V_91 ;
F_58 ( & V_13 -> V_38 ) ;
V_13 -> V_38 . V_60 = F_29 ;
V_13 -> V_86 = & V_92 ;
V_13 -> V_93 = ~ V_94 ;
V_13 -> V_95 = V_94 ;
}
V_91 = * V_81 ;
F_55 ( & V_91 ) ;
if ( V_96 )
V_88 = V_30 ;
for ( V_4 = 0 , V_13 = V_72 ;
V_4 < F_59 ( V_97 ) && V_4 < V_89 ;
V_4 ++ , V_13 ++ ) {
struct V_14 * V_15 = & V_13 -> V_15 ;
V_15 -> V_69 = V_97 [ V_4 ] . V_15 ;
V_15 -> V_1 = F_60 ( V_97 [ V_4 ] . V_1 ) ;
V_15 -> V_36 = V_97 [ V_4 ] . V_36 ;
V_15 -> V_98 = V_97 [ V_4 ] . V_99 * 16 ;
V_15 -> V_28 = V_97 [ V_4 ] . V_28 ;
V_15 -> V_100 = V_97 [ V_4 ] . V_100 ;
V_15 -> V_101 = V_97 [ V_4 ] . V_102 ;
V_15 -> V_66 = V_97 [ V_4 ] . V_103 ;
V_15 -> V_63 = V_97 [ V_4 ] . V_104 ;
F_61 ( V_13 ) ;
V_15 -> V_36 |= V_88 ;
if ( V_74 != NULL )
V_74 ( V_4 , & V_13 -> V_15 , & V_13 -> V_73 ) ;
}
}
static void T_2
F_62 ( struct V_105 * V_106 , struct V_107 * V_108 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_89 ; V_4 ++ ) {
struct V_12 * V_13 = & V_72 [ V_4 ] ;
if ( V_13 -> V_15 . type == V_109 )
continue;
if ( V_13 -> V_15 . V_108 )
continue;
V_13 -> V_15 . V_108 = V_108 ;
if ( V_110 )
V_13 -> V_15 . V_28 |= V_111 ;
F_63 ( V_106 , & V_13 -> V_15 ) ;
}
}
static void F_64 ( struct V_112 * V_113 , const char * V_114 ,
unsigned int V_115 )
{
struct V_12 * V_13 = & V_72 [ V_113 -> V_116 ] ;
F_65 ( V_13 , V_114 , V_115 ) ;
}
static int F_66 ( struct V_112 * V_113 , char * V_117 )
{
struct V_14 * V_15 ;
int V_57 ;
if ( V_113 -> V_116 >= V_89 )
V_113 -> V_116 = 0 ;
V_15 = & V_72 [ V_113 -> V_116 ] . V_15 ;
V_15 -> V_118 = V_113 ;
V_57 = F_67 ( V_15 , V_117 , false ) ;
if ( V_57 != 0 )
V_15 -> V_118 = NULL ;
return V_57 ;
}
static int F_68 ( struct V_112 * V_113 , char * V_119 , int V_120 ,
char * V_117 )
{
char V_121 [] = L_7 ;
unsigned char V_66 ;
unsigned long V_122 ;
int V_4 ;
if ( strncmp ( V_119 , V_121 , 4 ) != 0 )
return - V_123 ;
if ( F_69 ( V_117 , & V_66 , & V_122 , & V_117 ) )
return - V_123 ;
for ( V_4 = 0 ; V_4 < V_89 ; V_4 ++ ) {
struct V_14 * V_15 = & V_72 [ V_4 ] . V_15 ;
if ( V_15 -> V_66 != V_66 )
continue;
if ( ( V_66 == V_124 || V_66 == V_125 ||
V_66 == V_126 || V_66 == V_127 )
&& ( V_15 -> V_128 != V_122 ) )
continue;
if ( V_66 == V_68 && V_15 -> V_69 != V_122 )
continue;
V_113 -> V_116 = V_4 ;
V_15 -> V_118 = V_113 ;
return F_67 ( V_15 , V_117 , true ) ;
}
return - V_123 ;
}
static int T_2 F_70 ( void )
{
if ( V_89 == 0 )
return - V_123 ;
F_56 () ;
F_71 ( & V_129 ) ;
return 0 ;
}
int T_2 F_72 ( struct V_14 * V_15 )
{
struct V_14 * V_130 ;
if ( V_15 -> line >= F_59 ( V_72 ) || V_89 == 0 )
return - V_123 ;
F_56 () ;
V_130 = & V_72 [ V_15 -> line ] . V_15 ;
V_130 -> V_69 = V_15 -> V_69 ;
V_130 -> V_101 = V_15 -> V_101 ;
V_130 -> V_1 = V_15 -> V_1 ;
V_130 -> V_36 = V_15 -> V_36 ;
V_130 -> V_98 = V_15 -> V_98 ;
V_130 -> V_131 = V_15 -> V_131 ;
V_130 -> V_63 = V_15 -> V_63 ;
V_130 -> V_66 = V_15 -> V_66 ;
V_130 -> V_28 = V_15 -> V_28 ;
V_130 -> V_128 = V_15 -> V_128 ;
V_130 -> V_132 = V_15 -> V_132 ;
V_130 -> V_133 = V_15 -> V_133 ;
V_130 -> type = V_15 -> type ;
V_130 -> line = V_15 -> line ;
F_61 ( F_52 ( V_130 ) ) ;
if ( V_15 -> F_34 )
V_130 -> F_34 = V_15 -> F_34 ;
if ( V_15 -> F_35 )
V_130 -> F_35 = V_15 -> F_35 ;
if ( V_15 -> V_17 )
V_130 -> V_17 = V_15 -> V_17 ;
return 0 ;
}
void F_73 ( int line )
{
struct V_12 * V_13 = & V_72 [ line ] ;
struct V_14 * V_15 = & V_13 -> V_15 ;
if ( ! V_134 && F_74 ( V_15 ) &&
V_15 -> type != V_135 ) {
unsigned char V_136 = 0xa5 ;
F_35 ( V_13 , V_137 , V_136 ) ;
if ( F_34 ( V_13 , V_137 ) == V_136 )
V_13 -> V_136 = V_136 ;
}
F_75 ( & V_138 , V_15 ) ;
}
void F_76 ( int line )
{
struct V_12 * V_13 = & V_72 [ line ] ;
struct V_14 * V_15 = & V_13 -> V_15 ;
V_13 -> V_136 = 0 ;
if ( V_13 -> V_73 & V_139 ) {
F_77 ( V_15 , V_140 , 0xE0 ) ;
F_78 ( V_13 ) ;
F_77 ( V_15 , V_140 , 0 ) ;
V_15 -> V_98 = 921600 * 16 ;
}
F_79 ( & V_138 , V_15 ) ;
}
static int F_80 ( struct V_141 * V_108 )
{
struct V_142 * V_130 = F_81 ( & V_108 -> V_108 ) ;
struct V_12 V_143 ;
int V_26 , V_4 , V_88 = 0 ;
memset ( & V_143 , 0 , sizeof( V_143 ) ) ;
if ( V_96 )
V_88 = V_30 ;
for ( V_4 = 0 ; V_130 && V_130 -> V_28 != 0 ; V_130 ++ , V_4 ++ ) {
V_143 . V_15 . V_69 = V_130 -> V_69 ;
V_143 . V_15 . V_101 = V_130 -> V_101 ;
V_143 . V_15 . V_1 = V_130 -> V_1 ;
V_143 . V_15 . V_36 = V_130 -> V_36 ;
V_143 . V_15 . V_98 = V_130 -> V_98 ;
V_143 . V_15 . V_63 = V_130 -> V_63 ;
V_143 . V_15 . V_66 = V_130 -> V_66 ;
V_143 . V_15 . V_28 = V_130 -> V_28 ;
V_143 . V_15 . V_128 = V_130 -> V_128 ;
V_143 . V_15 . V_100 = V_130 -> V_100 ;
V_143 . V_15 . V_133 = V_130 -> V_133 ;
V_143 . V_15 . type = V_130 -> type ;
V_143 . V_15 . F_34 = V_130 -> F_34 ;
V_143 . V_15 . F_35 = V_130 -> F_35 ;
V_143 . V_15 . V_17 = V_130 -> V_17 ;
V_143 . V_15 . V_144 = V_130 -> V_144 ;
V_143 . V_15 . V_145 = V_130 -> V_145 ;
V_143 . V_15 . V_146 = V_130 -> V_146 ;
V_143 . V_15 . V_108 = & V_108 -> V_108 ;
V_143 . V_15 . V_36 |= V_88 ;
V_26 = F_82 ( & V_143 ) ;
if ( V_26 < 0 ) {
F_83 ( & V_108 -> V_108 , L_8
L_9 , V_4 ,
V_130 -> V_69 , ( unsigned long long ) V_130 -> V_128 ,
V_130 -> V_1 , V_26 ) ;
}
}
return 0 ;
}
static int F_84 ( struct V_141 * V_108 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_89 ; V_4 ++ ) {
struct V_12 * V_13 = & V_72 [ V_4 ] ;
if ( V_13 -> V_15 . V_108 == & V_108 -> V_108 )
F_85 ( V_4 ) ;
}
return 0 ;
}
static int F_86 ( struct V_141 * V_108 , T_3 V_50 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_90 ; V_4 ++ ) {
struct V_12 * V_13 = & V_72 [ V_4 ] ;
if ( V_13 -> V_15 . type != V_147 && V_13 -> V_15 . V_108 == & V_108 -> V_108 )
F_75 ( & V_138 , & V_13 -> V_15 ) ;
}
return 0 ;
}
static int F_87 ( struct V_141 * V_108 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_90 ; V_4 ++ ) {
struct V_12 * V_13 = & V_72 [ V_4 ] ;
if ( V_13 -> V_15 . type != V_147 && V_13 -> V_15 . V_108 == & V_108 -> V_108 )
F_76 ( V_4 ) ;
}
return 0 ;
}
static struct V_12 * F_88 ( struct V_14 * V_15 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_89 ; V_4 ++ )
if ( F_89 ( & V_72 [ V_4 ] . V_15 , V_15 ) )
return & V_72 [ V_4 ] ;
V_4 = V_15 -> line ;
if ( V_4 < V_89 && V_72 [ V_4 ] . V_15 . type == V_147 &&
V_72 [ V_4 ] . V_15 . V_69 == 0 )
return & V_72 [ V_4 ] ;
for ( V_4 = 0 ; V_4 < V_89 ; V_4 ++ )
if ( V_72 [ V_4 ] . V_15 . type == V_147 &&
V_72 [ V_4 ] . V_15 . V_69 == 0 )
return & V_72 [ V_4 ] ;
for ( V_4 = 0 ; V_4 < V_89 ; V_4 ++ )
if ( V_72 [ V_4 ] . V_15 . type == V_147 )
return & V_72 [ V_4 ] ;
return NULL ;
}
int F_82 ( struct V_12 * V_13 )
{
struct V_12 * V_143 ;
int V_26 = - V_148 ;
if ( V_13 -> V_15 . V_98 == 0 )
return - V_65 ;
F_17 ( & V_149 ) ;
V_143 = F_88 ( & V_13 -> V_15 ) ;
if ( V_143 && V_143 -> V_15 . type != V_109 ) {
if ( V_143 -> V_15 . V_108 )
F_90 ( & V_138 , & V_143 -> V_15 ) ;
V_143 -> V_15 . V_69 = V_13 -> V_15 . V_69 ;
V_143 -> V_15 . V_101 = V_13 -> V_15 . V_101 ;
V_143 -> V_15 . V_1 = V_13 -> V_15 . V_1 ;
V_143 -> V_15 . V_36 = V_13 -> V_15 . V_36 ;
V_143 -> V_15 . V_98 = V_13 -> V_15 . V_98 ;
V_143 -> V_15 . V_131 = V_13 -> V_15 . V_131 ;
V_143 -> V_15 . V_63 = V_13 -> V_15 . V_63 ;
V_143 -> V_15 . V_66 = V_13 -> V_15 . V_66 ;
V_143 -> V_15 . V_28 = V_13 -> V_15 . V_28 | V_150 ;
V_143 -> V_58 = V_13 -> V_58 ;
V_143 -> V_15 . V_128 = V_13 -> V_15 . V_128 ;
V_143 -> V_15 . V_132 = V_13 -> V_15 . V_132 ;
V_143 -> V_15 . V_133 = V_13 -> V_15 . V_133 ;
V_143 -> V_151 = V_13 -> V_151 ;
V_143 -> V_73 = V_13 -> V_73 ;
V_143 -> V_15 . V_152 = V_13 -> V_15 . V_152 ;
V_143 -> V_15 . V_153 = V_13 -> V_15 . V_153 ;
V_143 -> V_15 . V_154 = V_13 -> V_15 . V_154 ;
V_143 -> V_15 . V_155 = V_13 -> V_15 . V_155 ;
V_143 -> V_156 = V_13 -> V_156 ;
if ( V_143 -> V_15 . V_131 && ! V_143 -> V_151 )
V_143 -> V_151 = V_143 -> V_15 . V_131 ;
if ( V_13 -> V_15 . V_108 )
V_143 -> V_15 . V_108 = V_13 -> V_15 . V_108 ;
if ( V_110 )
V_143 -> V_15 . V_28 |= V_111 ;
if ( V_13 -> V_15 . V_28 & V_157 )
V_143 -> V_15 . type = V_13 -> V_15 . type ;
F_61 ( V_143 ) ;
if ( V_13 -> V_15 . F_34 )
V_143 -> V_15 . F_34 = V_13 -> V_15 . F_34 ;
if ( V_13 -> V_15 . F_35 )
V_143 -> V_15 . F_35 = V_13 -> V_15 . F_35 ;
if ( V_13 -> V_15 . V_17 )
V_143 -> V_15 . V_17 = V_13 -> V_15 . V_17 ;
if ( V_13 -> V_15 . V_145 )
V_143 -> V_15 . V_145 = V_13 -> V_15 . V_145 ;
if ( V_13 -> V_15 . V_158 )
V_143 -> V_15 . V_158 = V_13 -> V_15 . V_158 ;
if ( V_13 -> V_15 . V_159 )
V_143 -> V_15 . V_159 = V_13 -> V_15 . V_159 ;
if ( V_13 -> V_15 . V_160 )
V_143 -> V_15 . V_160 = V_13 -> V_15 . V_160 ;
if ( V_13 -> V_15 . V_146 )
V_143 -> V_15 . V_146 = V_13 -> V_15 . V_146 ;
if ( V_13 -> V_15 . V_144 )
V_143 -> V_15 . V_144 = V_13 -> V_15 . V_144 ;
if ( V_13 -> V_161 )
V_143 -> V_161 = V_13 -> V_161 ;
if ( V_13 -> V_162 )
V_143 -> V_162 = V_13 -> V_162 ;
if ( V_143 -> V_15 . type != V_109 ) {
if ( V_74 != NULL )
V_74 ( 0 , & V_143 -> V_15 ,
& V_143 -> V_73 ) ;
V_26 = F_63 ( & V_138 ,
& V_143 -> V_15 ) ;
if ( V_26 == 0 )
V_26 = V_143 -> V_15 . line ;
} else {
F_91 ( V_143 -> V_15 . V_108 ,
L_10 ,
V_143 -> V_15 . V_69 ,
( unsigned long long ) V_143 -> V_15 . V_128 ,
V_143 -> V_15 . V_1 ) ;
V_26 = 0 ;
}
}
F_21 ( & V_149 ) ;
return V_26 ;
}
void F_85 ( int line )
{
struct V_12 * V_143 = & V_72 [ line ] ;
F_17 ( & V_149 ) ;
if ( V_143 -> V_163 ) {
unsigned long V_28 ;
F_33 ( & V_143 -> V_15 . V_10 , V_28 ) ;
F_92 ( V_143 ) ;
F_38 ( & V_143 -> V_15 . V_10 , V_28 ) ;
}
F_90 ( & V_138 , & V_143 -> V_15 ) ;
if ( V_164 ) {
V_143 -> V_15 . V_28 &= ~ V_150 ;
if ( V_110 )
V_143 -> V_15 . V_28 |= V_111 ;
V_143 -> V_15 . type = V_147 ;
V_143 -> V_15 . V_108 = & V_164 -> V_108 ;
V_143 -> V_73 = 0 ;
F_63 ( & V_138 , & V_143 -> V_15 ) ;
} else {
V_143 -> V_15 . V_108 = NULL ;
}
F_21 ( & V_149 ) ;
}
static int T_2 F_93 ( void )
{
int V_26 ;
if ( V_89 == 0 )
return - V_123 ;
F_56 () ;
F_94 ( L_11 ,
V_89 , V_96 ? L_12 : L_13 ) ;
#ifdef F_95
V_26 = F_96 ( & V_138 , V_90 ) ;
#else
V_138 . V_165 = V_90 ;
V_26 = F_97 ( & V_138 ) ;
#endif
if ( V_26 )
goto V_166;
V_26 = F_98 () ;
if ( V_26 )
goto V_167;
V_164 = F_99 ( L_14 ,
V_168 ) ;
if ( ! V_164 ) {
V_26 = - V_35 ;
goto V_169;
}
V_26 = F_100 ( V_164 ) ;
if ( V_26 )
goto V_170;
F_62 ( & V_138 , & V_164 -> V_108 ) ;
V_26 = F_101 ( & V_171 ) ;
if ( V_26 == 0 )
goto V_166;
F_102 ( V_164 ) ;
V_170:
F_103 ( V_164 ) ;
V_169:
F_104 () ;
V_167:
#ifdef F_95
F_105 ( & V_138 , V_90 ) ;
#else
F_106 ( & V_138 ) ;
#endif
V_166:
return V_26 ;
}
static void T_4 F_107 ( void )
{
struct V_141 * V_172 = V_164 ;
V_164 = NULL ;
F_108 ( & V_171 ) ;
F_109 ( V_172 ) ;
F_104 () ;
#ifdef F_95
F_105 ( & V_138 , V_90 ) ;
#else
F_106 ( & V_138 ) ;
#endif
}
static void T_5 F_110 ( void )
{
#undef V_173
#define V_173 "8250_core."
F_111 ( V_96 , & V_174 , & V_96 , 0644 ) ;
F_111 ( V_89 , & V_174 , & V_89 , 0644 ) ;
F_111 ( V_110 , & V_174 , & V_110 , 0644 ) ;
#ifdef F_112
F_113 ( V_173 , V_80 ,
& V_175 , . V_176 = & V_177 ,
0444 , - 1 , 0 ) ;
#endif
}
