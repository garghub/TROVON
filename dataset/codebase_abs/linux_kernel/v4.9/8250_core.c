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
V_28 , L_4 , V_4 ) ;
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
static void F_29 ( unsigned long V_38 )
{
struct V_13 * V_14 = (struct V_13 * ) V_38 ;
V_14 -> V_16 . V_18 ( & V_14 -> V_16 ) ;
F_30 ( & V_14 -> V_39 , V_40 + F_31 ( & V_14 -> V_16 ) ) ;
}
static void F_32 ( unsigned long V_38 )
{
struct V_13 * V_14 = (struct V_13 * ) V_38 ;
unsigned int V_41 , V_42 = 0 , V_43 ;
unsigned long V_29 ;
F_33 ( & V_14 -> V_16 . V_11 , V_29 ) ;
if ( V_14 -> V_16 . V_1 ) {
V_42 = F_34 ( V_14 , V_44 ) ;
F_35 ( V_14 , V_44 , 0 ) ;
}
V_41 = F_34 ( V_14 , V_45 ) ;
V_43 = F_34 ( V_14 , V_46 ) ;
V_14 -> V_47 |= V_43 & V_48 ;
if ( ( V_41 & V_49 ) && ( V_14 -> V_42 & V_50 ) &&
( ! F_36 ( & V_14 -> V_16 . V_51 -> V_52 ) || V_14 -> V_16 . V_53 ) &&
( V_43 & V_54 ) ) {
V_41 &= ~ ( V_55 | V_49 ) ;
V_41 |= V_56 ;
}
if ( ! ( V_41 & V_49 ) )
F_37 ( V_14 ) ;
if ( V_14 -> V_16 . V_1 )
F_35 ( V_14 , V_44 , V_42 ) ;
F_38 ( & V_14 -> V_16 . V_11 , V_29 ) ;
F_30 ( & V_14 -> V_39 ,
V_40 + F_31 ( & V_14 -> V_16 ) + V_57 / 5 ) ;
}
static int F_39 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
int V_58 = 0 ;
if ( V_14 -> V_59 & V_60 ) {
F_2 ( L_5 , F_40 ( V_16 ) ) ;
V_14 -> V_39 . V_61 = F_32 ;
V_14 -> V_39 . V_38 = ( unsigned long ) V_14 ;
F_30 ( & V_14 -> V_39 , V_40 +
F_31 ( V_16 ) + V_57 / 5 ) ;
}
if ( ! V_16 -> V_1 ) {
V_14 -> V_39 . V_38 = ( unsigned long ) V_14 ;
F_30 ( & V_14 -> V_39 , V_40 + F_31 ( V_16 ) ) ;
} else
V_58 = F_16 ( V_14 ) ;
return V_58 ;
}
static void F_41 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
F_42 ( & V_14 -> V_39 ) ;
V_14 -> V_39 . V_61 = F_29 ;
if ( V_16 -> V_1 )
F_27 ( V_14 ) ;
}
static int F_43 ( struct V_13 * V_14 )
{
unsigned long V_62 = V_63 << V_14 -> V_16 . V_64 ;
unsigned int V_65 = 8 << V_14 -> V_16 . V_64 ;
struct V_15 * V_16 = & V_14 -> V_16 ;
int V_27 = - V_66 ;
switch ( V_16 -> V_67 ) {
case V_68 :
case V_69 :
V_62 += V_16 -> V_70 ;
if ( F_44 ( V_62 , V_65 , L_6 ) )
V_27 = 0 ;
else
V_27 = - V_71 ;
break;
}
return V_27 ;
}
static void F_45 ( struct V_13 * V_14 )
{
unsigned long V_72 = V_63 << V_14 -> V_16 . V_64 ;
unsigned int V_65 = 8 << V_14 -> V_16 . V_64 ;
struct V_15 * V_16 = & V_14 -> V_16 ;
switch ( V_16 -> V_67 ) {
case V_68 :
case V_69 :
F_46 ( V_16 -> V_70 + V_72 , V_65 ) ;
break;
}
}
struct V_13 * F_47 ( int line )
{
return & V_73 [ line ] ;
}
void F_48 (
void (* F_49)( int V_16 , struct V_15 * V_14 , unsigned short * V_74 ) )
{
V_75 = F_49 ;
}
static void F_50 ( struct V_15 * V_16 , int V_29 )
{
struct V_13 * V_14 = F_51 ( V_16 ) ;
V_14 -> V_76 &= ~ V_77 ;
if ( V_16 -> type == V_78 ) {
if ( F_43 ( V_14 ) == 0 )
V_14 -> V_76 |= V_77 ;
} else if ( V_29 & V_79 ) {
int V_4 ;
for ( V_4 = 0 ; V_4 < V_80 ; V_4 ++ ) {
if ( V_81 [ V_4 ] == V_14 -> V_16 . V_70 ) {
if ( F_43 ( V_14 ) == 0 )
V_14 -> V_76 |= V_77 ;
break;
}
}
}
V_82 -> V_83 ( V_16 , V_29 ) ;
if ( V_16 -> type != V_78 && V_14 -> V_76 & V_77 )
F_45 ( V_14 ) ;
}
static int F_52 ( struct V_15 * V_16 )
{
struct V_13 * V_14 = F_51 ( V_16 ) ;
int V_27 ;
V_27 = V_82 -> V_84 ( V_16 ) ;
if ( V_27 == 0 && V_16 -> type == V_78 ) {
V_27 = F_43 ( V_14 ) ;
if ( V_27 < 0 )
V_82 -> V_85 ( V_16 ) ;
}
return V_27 ;
}
static void F_53 ( struct V_15 * V_16 )
{
struct V_13 * V_14 = F_51 ( V_16 ) ;
if ( V_16 -> type == V_78 )
F_45 ( V_14 ) ;
V_82 -> V_85 ( V_16 ) ;
}
static void F_54 ( struct V_86 * V_87 )
{
V_87 -> V_83 = F_50 ;
V_87 -> V_84 = F_52 ;
V_87 -> V_85 = F_53 ;
}
static void T_2 F_55 ( void )
{
struct V_13 * V_14 ;
static int V_88 = 1 ;
int V_4 , V_89 = 0 ;
if ( ! V_88 )
return;
V_88 = 0 ;
if ( V_90 > V_91 )
V_90 = V_91 ;
for ( V_4 = 0 ; V_4 < V_90 ; V_4 ++ ) {
struct V_13 * V_14 = & V_73 [ V_4 ] ;
struct V_15 * V_16 = & V_14 -> V_16 ;
V_16 -> line = V_4 ;
F_56 ( V_14 ) ;
if ( ! V_82 )
V_82 = V_16 -> V_87 ;
V_16 -> V_87 = & V_92 ;
F_57 ( & V_14 -> V_39 ) ;
V_14 -> V_39 . V_61 = F_29 ;
V_14 -> V_87 = & V_93 ;
V_14 -> V_94 = ~ V_95 ;
V_14 -> V_96 = V_95 ;
}
V_92 = * V_82 ;
F_54 ( & V_92 ) ;
if ( V_97 )
V_89 = V_31 ;
for ( V_4 = 0 , V_14 = V_73 ;
V_4 < F_58 ( V_98 ) && V_4 < V_90 ;
V_4 ++ , V_14 ++ ) {
struct V_15 * V_16 = & V_14 -> V_16 ;
V_16 -> V_70 = V_98 [ V_4 ] . V_16 ;
V_16 -> V_1 = F_59 ( V_98 [ V_4 ] . V_1 ) ;
V_16 -> V_37 = 0 ;
V_16 -> V_99 = V_98 [ V_4 ] . V_100 * 16 ;
V_16 -> V_29 = V_98 [ V_4 ] . V_29 ;
V_16 -> V_101 = 0 ;
V_16 -> V_102 = V_98 [ V_4 ] . V_103 ;
V_16 -> V_67 = V_98 [ V_4 ] . V_104 ;
V_16 -> V_64 = V_98 [ V_4 ] . V_105 ;
F_60 ( V_14 ) ;
V_16 -> V_37 |= V_89 ;
if ( V_75 != NULL )
V_75 ( V_4 , & V_14 -> V_16 , & V_14 -> V_74 ) ;
}
}
static void T_2
F_61 ( struct V_106 * V_107 , struct V_108 * V_109 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_90 ; V_4 ++ ) {
struct V_13 * V_14 = & V_73 [ V_4 ] ;
if ( V_14 -> V_16 . type == V_110 )
continue;
if ( V_14 -> V_16 . V_109 )
continue;
V_14 -> V_16 . V_109 = V_109 ;
if ( V_111 )
V_14 -> V_16 . V_29 |= V_112 ;
F_62 ( V_107 , & V_14 -> V_16 ) ;
}
}
static void F_63 ( struct V_113 * V_114 , const char * V_115 ,
unsigned int V_116 )
{
struct V_13 * V_14 = & V_73 [ V_114 -> V_117 ] ;
F_64 ( V_14 , V_115 , V_116 ) ;
}
static int F_65 ( struct V_113 * V_114 , char * V_118 )
{
struct V_15 * V_16 ;
int V_58 ;
if ( V_114 -> V_117 >= V_90 )
V_114 -> V_117 = 0 ;
V_16 = & V_73 [ V_114 -> V_117 ] . V_16 ;
V_16 -> V_119 = V_114 ;
V_58 = F_66 ( V_16 , V_118 , false ) ;
if ( V_58 != 0 )
V_16 -> V_119 = NULL ;
return V_58 ;
}
static int F_67 ( struct V_113 * V_114 , char * V_120 , int V_121 ,
char * V_118 )
{
char V_122 [] = L_7 ;
unsigned char V_67 ;
T_3 V_123 ;
int V_4 ;
if ( strncmp ( V_120 , V_122 , 4 ) != 0 )
return - V_124 ;
if ( F_68 ( V_118 , & V_67 , & V_123 , & V_118 ) )
return - V_124 ;
for ( V_4 = 0 ; V_4 < V_90 ; V_4 ++ ) {
struct V_15 * V_16 = & V_73 [ V_4 ] . V_16 ;
if ( V_16 -> V_67 != V_67 )
continue;
if ( ( V_67 == V_125 || V_67 == V_126 ||
V_67 == V_127 || V_67 == V_128 )
&& ( V_16 -> V_129 != V_123 ) )
continue;
if ( V_67 == V_69 && V_16 -> V_70 != V_123 )
continue;
V_114 -> V_117 = V_4 ;
V_16 -> V_119 = V_114 ;
return F_66 ( V_16 , V_118 , true ) ;
}
return - V_124 ;
}
static int T_2 F_69 ( void )
{
if ( V_90 == 0 )
return - V_124 ;
F_55 () ;
F_70 ( & V_130 ) ;
return 0 ;
}
int T_2 F_71 ( struct V_15 * V_16 )
{
struct V_15 * V_131 ;
if ( V_16 -> line >= F_58 ( V_73 ) || V_90 == 0 )
return - V_124 ;
F_55 () ;
V_131 = & V_73 [ V_16 -> line ] . V_16 ;
V_131 -> V_70 = V_16 -> V_70 ;
V_131 -> V_102 = V_16 -> V_102 ;
V_131 -> V_1 = V_16 -> V_1 ;
V_131 -> V_37 = V_16 -> V_37 ;
V_131 -> V_99 = V_16 -> V_99 ;
V_131 -> V_132 = V_16 -> V_132 ;
V_131 -> V_64 = V_16 -> V_64 ;
V_131 -> V_67 = V_16 -> V_67 ;
V_131 -> V_29 = V_16 -> V_29 ;
V_131 -> V_129 = V_16 -> V_129 ;
V_131 -> V_133 = V_16 -> V_133 ;
V_131 -> V_134 = V_16 -> V_134 ;
V_131 -> type = V_16 -> type ;
V_131 -> line = V_16 -> line ;
F_60 ( F_51 ( V_131 ) ) ;
if ( V_16 -> F_34 )
V_131 -> F_34 = V_16 -> F_34 ;
if ( V_16 -> F_35 )
V_131 -> F_35 = V_16 -> F_35 ;
if ( V_16 -> V_18 )
V_131 -> V_18 = V_16 -> V_18 ;
return 0 ;
}
void F_72 ( int line )
{
struct V_13 * V_14 = & V_73 [ line ] ;
struct V_15 * V_16 = & V_14 -> V_16 ;
if ( ! V_135 && F_73 ( V_16 ) &&
V_16 -> type != V_136 ) {
unsigned char V_137 = 0xa5 ;
F_35 ( V_14 , V_138 , V_137 ) ;
if ( F_34 ( V_14 , V_138 ) == V_137 )
V_14 -> V_137 = V_137 ;
}
F_74 ( & V_139 , V_16 ) ;
}
void F_75 ( int line )
{
struct V_13 * V_14 = & V_73 [ line ] ;
struct V_15 * V_16 = & V_14 -> V_16 ;
V_14 -> V_137 = 0 ;
if ( V_14 -> V_74 & V_140 ) {
F_76 ( V_16 , V_141 , 0xE0 ) ;
F_77 ( V_14 ) ;
F_76 ( V_16 , V_141 , 0 ) ;
V_16 -> V_99 = 921600 * 16 ;
}
F_78 ( & V_139 , V_16 ) ;
}
static int F_79 ( struct V_142 * V_109 )
{
struct V_143 * V_131 = F_80 ( & V_109 -> V_109 ) ;
struct V_13 V_144 ;
int V_27 , V_4 , V_89 = 0 ;
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
if ( V_97 )
V_89 = V_31 ;
for ( V_4 = 0 ; V_131 && V_131 -> V_29 != 0 ; V_131 ++ , V_4 ++ ) {
V_144 . V_16 . V_70 = V_131 -> V_70 ;
V_144 . V_16 . V_102 = V_131 -> V_102 ;
V_144 . V_16 . V_1 = V_131 -> V_1 ;
V_144 . V_16 . V_37 = V_131 -> V_37 ;
V_144 . V_16 . V_99 = V_131 -> V_99 ;
V_144 . V_16 . V_64 = V_131 -> V_64 ;
V_144 . V_16 . V_67 = V_131 -> V_67 ;
V_144 . V_16 . V_29 = V_131 -> V_29 ;
V_144 . V_16 . V_129 = V_131 -> V_129 ;
V_144 . V_16 . V_101 = V_131 -> V_101 ;
V_144 . V_16 . V_134 = V_131 -> V_134 ;
V_144 . V_16 . type = V_131 -> type ;
V_144 . V_16 . F_34 = V_131 -> F_34 ;
V_144 . V_16 . F_35 = V_131 -> F_35 ;
V_144 . V_16 . V_18 = V_131 -> V_18 ;
V_144 . V_16 . V_145 = V_131 -> V_145 ;
V_144 . V_16 . V_146 = V_131 -> V_146 ;
V_144 . V_16 . V_147 = V_131 -> V_147 ;
V_144 . V_16 . V_148 = V_131 -> V_148 ;
V_144 . V_16 . V_109 = & V_109 -> V_109 ;
V_144 . V_16 . V_37 |= V_89 ;
V_27 = F_81 ( & V_144 ) ;
if ( V_27 < 0 ) {
F_82 ( & V_109 -> V_109 , L_8
L_9 , V_4 ,
V_131 -> V_70 , ( unsigned long long ) V_131 -> V_129 ,
V_131 -> V_1 , V_27 ) ;
}
}
return 0 ;
}
static int F_83 ( struct V_142 * V_109 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_90 ; V_4 ++ ) {
struct V_13 * V_14 = & V_73 [ V_4 ] ;
if ( V_14 -> V_16 . V_109 == & V_109 -> V_109 )
F_84 ( V_4 ) ;
}
return 0 ;
}
static int F_85 ( struct V_142 * V_109 , T_4 V_51 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_91 ; V_4 ++ ) {
struct V_13 * V_14 = & V_73 [ V_4 ] ;
if ( V_14 -> V_16 . type != V_149 && V_14 -> V_16 . V_109 == & V_109 -> V_109 )
F_74 ( & V_139 , & V_14 -> V_16 ) ;
}
return 0 ;
}
static int F_86 ( struct V_142 * V_109 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_91 ; V_4 ++ ) {
struct V_13 * V_14 = & V_73 [ V_4 ] ;
if ( V_14 -> V_16 . type != V_149 && V_14 -> V_16 . V_109 == & V_109 -> V_109 )
F_75 ( V_4 ) ;
}
return 0 ;
}
static struct V_13 * F_87 ( struct V_15 * V_16 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_90 ; V_4 ++ )
if ( F_88 ( & V_73 [ V_4 ] . V_16 , V_16 ) )
return & V_73 [ V_4 ] ;
V_4 = V_16 -> line ;
if ( V_4 < V_90 && V_73 [ V_4 ] . V_16 . type == V_149 &&
V_73 [ V_4 ] . V_16 . V_70 == 0 )
return & V_73 [ V_4 ] ;
for ( V_4 = 0 ; V_4 < V_90 ; V_4 ++ )
if ( V_73 [ V_4 ] . V_16 . type == V_149 &&
V_73 [ V_4 ] . V_16 . V_70 == 0 )
return & V_73 [ V_4 ] ;
for ( V_4 = 0 ; V_4 < V_90 ; V_4 ++ )
if ( V_73 [ V_4 ] . V_16 . type == V_149 )
return & V_73 [ V_4 ] ;
return NULL ;
}
int F_81 ( struct V_13 * V_14 )
{
struct V_13 * V_144 ;
int V_27 = - V_150 ;
if ( V_14 -> V_16 . V_99 == 0 )
return - V_66 ;
F_17 ( & V_151 ) ;
V_144 = F_87 ( & V_14 -> V_16 ) ;
if ( V_144 && V_144 -> V_16 . type != V_110 ) {
if ( V_144 -> V_16 . V_109 )
F_89 ( & V_139 , & V_144 -> V_16 ) ;
V_144 -> V_16 . V_70 = V_14 -> V_16 . V_70 ;
V_144 -> V_16 . V_102 = V_14 -> V_16 . V_102 ;
V_144 -> V_16 . V_1 = V_14 -> V_16 . V_1 ;
V_144 -> V_16 . V_37 = V_14 -> V_16 . V_37 ;
V_144 -> V_16 . V_99 = V_14 -> V_16 . V_99 ;
V_144 -> V_16 . V_132 = V_14 -> V_16 . V_132 ;
V_144 -> V_16 . V_64 = V_14 -> V_16 . V_64 ;
V_144 -> V_16 . V_67 = V_14 -> V_16 . V_67 ;
V_144 -> V_16 . V_29 = V_14 -> V_16 . V_29 | V_152 ;
V_144 -> V_59 = V_14 -> V_59 ;
V_144 -> V_16 . V_129 = V_14 -> V_16 . V_129 ;
V_144 -> V_16 . V_133 = V_14 -> V_16 . V_133 ;
V_144 -> V_16 . V_134 = V_14 -> V_16 . V_134 ;
V_144 -> V_153 = V_14 -> V_153 ;
V_144 -> V_74 = V_14 -> V_74 ;
V_144 -> V_16 . V_154 = V_14 -> V_16 . V_154 ;
V_144 -> V_16 . V_155 = V_14 -> V_16 . V_155 ;
V_144 -> V_16 . V_156 = V_14 -> V_16 . V_156 ;
V_144 -> V_16 . V_157 = V_14 -> V_16 . V_157 ;
V_144 -> V_158 = V_14 -> V_158 ;
if ( V_144 -> V_16 . V_132 && ! V_144 -> V_153 )
V_144 -> V_153 = V_144 -> V_16 . V_132 ;
if ( V_14 -> V_16 . V_109 )
V_144 -> V_16 . V_109 = V_14 -> V_16 . V_109 ;
if ( V_111 )
V_144 -> V_16 . V_29 |= V_112 ;
if ( V_14 -> V_16 . V_29 & V_159 )
V_144 -> V_16 . type = V_14 -> V_16 . type ;
F_60 ( V_144 ) ;
if ( V_14 -> V_16 . F_34 )
V_144 -> V_16 . F_34 = V_14 -> V_16 . F_34 ;
if ( V_14 -> V_16 . F_35 )
V_144 -> V_16 . F_35 = V_14 -> V_16 . F_35 ;
if ( V_14 -> V_16 . V_18 )
V_144 -> V_16 . V_18 = V_14 -> V_16 . V_18 ;
if ( V_14 -> V_16 . V_146 )
V_144 -> V_16 . V_146 = V_14 -> V_16 . V_146 ;
if ( V_14 -> V_16 . V_147 )
V_144 -> V_16 . V_147 = V_14 -> V_16 . V_147 ;
if ( V_14 -> V_16 . V_160 )
V_144 -> V_16 . V_160 = V_14 -> V_16 . V_160 ;
if ( V_14 -> V_16 . V_161 )
V_144 -> V_16 . V_161 = V_14 -> V_16 . V_161 ;
if ( V_14 -> V_16 . V_162 )
V_144 -> V_16 . V_162 = V_14 -> V_16 . V_162 ;
if ( V_14 -> V_16 . V_148 )
V_144 -> V_16 . V_148 = V_14 -> V_16 . V_148 ;
if ( V_14 -> V_16 . V_145 )
V_144 -> V_16 . V_145 = V_14 -> V_16 . V_145 ;
if ( V_14 -> V_163 )
V_144 -> V_163 = V_14 -> V_163 ;
if ( V_14 -> V_164 )
V_144 -> V_164 = V_14 -> V_164 ;
if ( V_144 -> V_16 . type != V_110 ) {
if ( V_75 != NULL )
V_75 ( 0 , & V_144 -> V_16 ,
& V_144 -> V_74 ) ;
V_27 = F_62 ( & V_139 ,
& V_144 -> V_16 ) ;
if ( V_27 == 0 )
V_27 = V_144 -> V_16 . line ;
} else {
F_90 ( V_144 -> V_16 . V_109 ,
L_10 ,
V_144 -> V_16 . V_70 ,
( unsigned long long ) V_144 -> V_16 . V_129 ,
V_144 -> V_16 . V_1 ) ;
V_27 = 0 ;
}
}
F_21 ( & V_151 ) ;
return V_27 ;
}
void F_84 ( int line )
{
struct V_13 * V_144 = & V_73 [ line ] ;
F_17 ( & V_151 ) ;
if ( V_144 -> V_165 ) {
unsigned long V_29 ;
F_33 ( & V_144 -> V_16 . V_11 , V_29 ) ;
F_91 ( V_144 ) ;
F_38 ( & V_144 -> V_16 . V_11 , V_29 ) ;
}
F_89 ( & V_139 , & V_144 -> V_16 ) ;
if ( V_166 ) {
V_144 -> V_16 . V_29 &= ~ V_152 ;
if ( V_111 )
V_144 -> V_16 . V_29 |= V_112 ;
V_144 -> V_16 . type = V_149 ;
V_144 -> V_16 . V_109 = & V_166 -> V_109 ;
V_144 -> V_74 = 0 ;
F_62 ( & V_139 , & V_144 -> V_16 ) ;
} else {
V_144 -> V_16 . V_109 = NULL ;
}
F_21 ( & V_151 ) ;
}
static int T_2 F_92 ( void )
{
int V_27 ;
if ( V_90 == 0 )
return - V_124 ;
F_55 () ;
F_93 ( L_11 ,
V_90 , V_97 ? L_12 : L_13 ) ;
#ifdef F_94
V_27 = F_95 ( & V_139 , V_91 ) ;
#else
V_139 . V_167 = V_91 ;
V_27 = F_96 ( & V_139 ) ;
#endif
if ( V_27 )
goto V_168;
V_27 = F_97 () ;
if ( V_27 )
goto V_169;
V_166 = F_98 ( L_14 ,
V_170 ) ;
if ( ! V_166 ) {
V_27 = - V_36 ;
goto V_171;
}
V_27 = F_99 ( V_166 ) ;
if ( V_27 )
goto V_172;
F_61 ( & V_139 , & V_166 -> V_109 ) ;
V_27 = F_100 ( & V_173 ) ;
if ( V_27 == 0 )
goto V_168;
F_101 ( V_166 ) ;
V_172:
F_102 ( V_166 ) ;
V_171:
F_103 () ;
V_169:
#ifdef F_94
F_104 ( & V_139 , V_91 ) ;
#else
F_105 ( & V_139 ) ;
#endif
V_168:
return V_27 ;
}
static void T_5 F_106 ( void )
{
struct V_142 * V_174 = V_166 ;
V_166 = NULL ;
F_107 ( & V_173 ) ;
F_108 ( V_174 ) ;
F_103 () ;
#ifdef F_94
F_104 ( & V_139 , V_91 ) ;
#else
F_105 ( & V_139 ) ;
#endif
}
static void T_6 F_109 ( void )
{
#undef V_175
#define V_175 "8250_core."
F_110 ( V_97 , & V_176 , & V_97 , 0644 ) ;
F_110 ( V_90 , & V_176 , & V_90 , 0644 ) ;
F_110 ( V_111 , & V_176 , & V_111 , 0644 ) ;
#ifdef F_111
F_112 ( V_175 , V_81 ,
& V_177 , . V_178 = & V_179 ,
0444 , - 1 , 0 ) ;
#endif
}
