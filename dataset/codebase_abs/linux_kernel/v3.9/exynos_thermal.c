static int F_1 ( struct V_1 * V_2 ,
enum V_3 * V_4 )
{
if ( V_5 )
* V_4 = V_5 -> V_4 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( ! V_5 -> V_6 ) {
F_3 ( L_1 ) ;
return 0 ;
}
F_4 ( & V_5 -> V_6 -> V_7 ) ;
if ( V_4 == V_8 &&
! V_5 -> V_9 -> V_10 . V_11 )
V_5 -> V_6 -> V_12 = V_13 ;
else
V_5 -> V_6 -> V_12 = 0 ;
F_5 ( & V_5 -> V_6 -> V_7 ) ;
V_5 -> V_4 = V_4 ;
F_6 ( V_5 -> V_6 ) ;
F_7 ( L_2 ,
V_5 -> V_6 -> V_12 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , int V_14 ,
enum V_15 * type )
{
switch ( F_9 ( V_14 ) ) {
case V_16 :
case V_17 :
* type = V_18 ;
break;
case V_19 :
* type = V_20 ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , int V_14 ,
unsigned long * V_22 )
{
if ( V_14 < V_23 ( V_16 ) || V_14 > V_23 ( V_19 ) )
return - V_21 ;
* V_22 = V_5 -> V_9 -> V_10 . V_24 [ V_14 ] ;
* V_22 = * V_22 * V_25 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned long * V_22 )
{
int V_26 ;
V_26 = F_10 ( V_2 , V_23 ( V_19 ) , V_22 ) ;
return V_26 ;
}
static int F_12 ( unsigned int V_27 , unsigned int V_28 )
{
int V_29 = 0 , V_26 = - V_21 ;
struct V_30 * V_31 = NULL ;
#ifdef F_13
V_31 = F_14 ( V_27 ) ;
#endif
if ( ! V_31 )
return V_26 ;
while ( V_31 [ V_29 ] . V_32 != V_33 ) {
if ( V_31 [ V_29 ] . V_32 == V_34 )
continue;
if ( V_31 [ V_29 ] . V_32 == V_28 )
return V_29 ;
V_29 ++ ;
}
return V_26 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
int V_26 = 0 , V_29 , V_37 , V_38 ;
struct V_39 * V_40 , * V_41 ;
struct V_42 * V_43 = V_5 -> V_9 ;
V_40 = (struct V_39 * ) V_43 -> V_44 . V_45 ;
V_37 = V_43 -> V_44 . V_46 ;
if ( V_40 == NULL || V_37 == 0 )
return - V_21 ;
for ( V_29 = 0 ; V_29 < V_5 -> V_47 ; V_29 ++ )
if ( V_36 == V_5 -> V_48 [ V_29 ] )
break;
if ( V_29 == V_5 -> V_47 )
return 0 ;
for ( V_29 = 0 ; V_29 < V_37 ; V_29 ++ ) {
V_41 = (struct V_39 * ) & ( V_40 [ V_29 ] ) ;
V_38 = F_12 ( 0 , V_41 -> V_49 ) ;
if ( V_38 < 0 )
return 0 ;
switch ( F_9 ( V_29 ) ) {
case V_16 :
case V_17 :
if ( F_16 ( V_2 , V_29 , V_36 ,
V_38 , 0 ) ) {
F_17 ( L_3 , V_29 ) ;
V_26 = - V_21 ;
}
V_5 -> V_50 = true ;
break;
default:
V_26 = - V_21 ;
}
}
return V_26 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
int V_26 = 0 , V_29 , V_37 ;
struct V_42 * V_43 = V_5 -> V_9 ;
if ( V_5 -> V_50 == false )
return 0 ;
V_37 = V_43 -> V_44 . V_46 ;
if ( V_37 == 0 )
return - V_21 ;
for ( V_29 = 0 ; V_29 < V_5 -> V_47 ; V_29 ++ )
if ( V_36 == V_5 -> V_48 [ V_29 ] )
break;
if ( V_29 == V_5 -> V_47 )
return 0 ;
for ( V_29 = 0 ; V_29 < V_37 ; V_29 ++ ) {
switch ( F_9 ( V_29 ) ) {
case V_16 :
case V_17 :
if ( F_19 ( V_2 , V_29 ,
V_36 ) ) {
F_17 ( L_4 , V_29 ) ;
V_26 = - V_21 ;
}
V_5 -> V_50 = false ;
break;
default:
V_26 = - V_21 ;
}
}
return V_26 ;
}
static int F_20 ( struct V_1 * V_2 ,
unsigned long * V_22 )
{
void * V_43 ;
if ( ! V_5 -> V_9 ) {
F_7 ( L_5 ) ;
return - V_21 ;
}
V_43 = V_5 -> V_9 -> V_51 ;
* V_22 = V_5 -> V_9 -> V_52 ( V_43 ) ;
* V_22 = * V_22 * V_25 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
int V_14 , enum V_53 * V_54 )
{
int V_26 ;
unsigned long V_55 ;
V_26 = F_10 ( V_2 , V_14 , & V_55 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_2 -> V_56 >= V_55 )
* V_54 = V_57 ;
else
* V_54 = V_58 ;
return 0 ;
}
static void F_22 ( void )
{
unsigned int V_29 ;
char V_43 [ 10 ] ;
char * V_59 [] = { V_43 , NULL } ;
if ( ! V_5 || ! V_5 -> V_6 )
return;
if ( V_5 -> V_50 == false ) {
for ( V_29 = 0 ; V_29 < V_5 -> V_47 ; V_29 ++ ) {
if ( ! V_5 -> V_48 [ V_29 ] )
continue;
F_15 ( V_5 -> V_6 ,
V_5 -> V_48 [ V_29 ] ) ;
}
}
F_6 ( V_5 -> V_6 ) ;
F_4 ( & V_5 -> V_6 -> V_7 ) ;
for ( V_29 = 0 ; V_29 < V_5 -> V_9 -> V_10 . V_60 ; V_29 ++ ) {
if ( V_5 -> V_6 -> V_61 <
V_5 -> V_9 -> V_10 . V_24 [ V_29 ] * V_25 )
break;
}
if ( V_5 -> V_4 == V_8 &&
! V_5 -> V_9 -> V_10 . V_11 ) {
if ( V_29 > 0 )
V_5 -> V_6 -> V_12 = V_62 ;
else
V_5 -> V_6 -> V_12 = V_13 ;
}
snprintf ( V_43 , sizeof( V_43 ) , L_6 , V_29 ) ;
F_23 ( & V_5 -> V_6 -> V_63 . V_64 , V_65 , V_59 ) ;
F_5 ( & V_5 -> V_6 -> V_7 ) ;
}
static int F_24 ( struct V_42 * V_9 )
{
int V_26 ;
struct V_66 V_67 ;
if ( ! V_9 || ! V_9 -> V_52 ) {
F_17 ( L_5 ) ;
return - V_21 ;
}
V_5 = F_25 ( sizeof( struct V_68 ) , V_69 ) ;
if ( ! V_5 )
return - V_70 ;
V_5 -> V_9 = V_9 ;
F_26 ( 0 , & V_67 ) ;
V_5 -> V_48 [ 0 ] = F_27 ( & V_67 ) ;
if ( F_28 ( V_5 -> V_48 [ 0 ] ) ) {
F_17 ( L_7 ) ;
V_26 = - V_21 ;
goto V_71;
}
V_5 -> V_47 ++ ;
V_5 -> V_6 = F_29 ( V_9 -> V_72 ,
V_73 , 0 , NULL , & V_74 , NULL , 0 ,
V_9 -> V_10 . V_11 ?
0 : V_13 ) ;
if ( F_28 ( V_5 -> V_6 ) ) {
F_17 ( L_8 ) ;
V_26 = F_30 ( V_5 -> V_6 ) ;
goto V_71;
}
V_5 -> V_4 = V_8 ;
F_7 ( L_9 ) ;
return 0 ;
V_71:
F_31 () ;
return V_26 ;
}
static void F_31 ( void )
{
int V_29 ;
if ( ! V_5 )
return;
if ( V_5 -> V_6 )
F_32 ( V_5 -> V_6 ) ;
for ( V_29 = 0 ; V_29 < V_5 -> V_47 ; V_29 ++ ) {
if ( V_5 -> V_48 [ V_29 ] )
F_33 ( V_5 -> V_48 [ V_29 ] ) ;
}
F_34 ( V_5 ) ;
F_7 ( L_10 ) ;
}
static int F_35 ( struct V_75 * V_43 , T_1 V_22 )
{
struct V_76 * V_77 = V_43 -> V_77 ;
int V_78 ;
if ( V_43 -> V_79 == V_80 )
if ( V_22 < 25 || V_22 > 125 ) {
V_78 = - V_21 ;
goto V_81;
}
switch ( V_77 -> V_82 ) {
case V_83 :
V_78 = ( V_22 - 25 ) *
( V_43 -> V_84 - V_43 -> V_85 ) /
( 85 - 25 ) + V_43 -> V_85 ;
break;
case V_86 :
V_78 = V_22 + V_43 -> V_85 - 25 ;
break;
default:
V_78 = V_22 + V_87 ;
break;
}
V_81:
return V_78 ;
}
static int F_36 ( struct V_75 * V_43 , T_1 V_78 )
{
struct V_76 * V_77 = V_43 -> V_77 ;
int V_22 ;
if ( V_43 -> V_79 == V_80 )
if ( V_78 < 75 || V_78 > 175 ) {
V_22 = - V_88 ;
goto V_81;
}
switch ( V_77 -> V_82 ) {
case V_83 :
V_22 = ( V_78 - V_43 -> V_85 ) * ( 85 - 25 ) /
( V_43 -> V_84 - V_43 -> V_85 ) + 25 ;
break;
case V_86 :
V_22 = V_78 - V_43 -> V_85 + 25 ;
break;
default:
V_22 = V_78 - V_87 ;
break;
}
V_81:
return V_22 ;
}
static int F_37 ( struct V_89 * V_90 )
{
struct V_75 * V_43 = F_38 ( V_90 ) ;
struct V_76 * V_77 = V_43 -> V_77 ;
unsigned int V_91 , V_92 ;
unsigned int V_93 = 0 , V_94 = 0 ;
int V_26 = 0 , V_95 , V_29 , V_96 = 0 ;
F_4 ( & V_43 -> V_7 ) ;
F_39 ( V_43 -> V_97 ) ;
V_91 = F_40 ( V_43 -> V_98 + V_99 ) ;
if ( ! V_91 ) {
V_26 = - V_100 ;
goto V_81;
}
if ( V_43 -> V_79 == V_101 ) {
F_41 ( V_102 ,
V_43 -> V_98 + V_103 ) ;
}
V_92 = F_42 ( V_43 -> V_98 + V_104 ) ;
V_43 -> V_85 = V_92 & V_105 ;
V_43 -> V_84 = ( ( V_92 >> 8 ) & V_105 ) ;
if ( ( V_106 > V_43 -> V_85 ) ||
( V_43 -> V_85 > V_107 ) ||
( V_43 -> V_84 != 0 ) )
V_43 -> V_85 = V_77 -> V_108 ;
for ( V_29 = 0 ; V_29 < V_109 ; V_29 ++ )
if ( V_77 -> V_110 [ V_29 ] )
V_96 ++ ;
if ( V_43 -> V_79 == V_80 ) {
V_95 = F_35 ( V_43 , V_77 -> V_111 ) ;
if ( V_95 < 0 ) {
V_26 = V_95 ;
goto V_81;
}
F_43 ( V_95 ,
V_43 -> V_98 + V_112 ) ;
for ( V_29 = 0 ; V_29 < V_96 ; V_29 ++ )
F_43 ( V_77 -> V_110 [ V_29 ] ,
V_43 -> V_98 + V_113 + V_29 * 4 ) ;
F_44 ( V_114 ,
V_43 -> V_98 + V_115 ) ;
} else if ( V_43 -> V_79 == V_101 ) {
for ( V_29 = 0 ; V_29 < V_96 ; V_29 ++ ) {
V_95 = F_35 ( V_43 ,
V_77 -> V_110 [ V_29 ] ) ;
if ( V_95 < 0 ) {
V_26 = V_95 ;
goto V_81;
}
V_93 |= V_95 << 8 * V_29 ;
if ( V_77 -> V_116 ) {
V_95 = F_35 ( V_43 ,
V_77 -> V_110 [ V_29 ] -
V_77 -> V_116 ) ;
if ( V_95 > 0 )
V_94 |=
V_95 << 8 * V_29 ;
}
}
F_44 ( V_93 ,
V_43 -> V_98 + V_117 ) ;
F_44 ( V_94 ,
V_43 -> V_98 + V_118 ) ;
F_44 ( V_119 | V_120 ,
V_43 -> V_98 + V_115 ) ;
}
V_81:
F_45 ( V_43 -> V_97 ) ;
F_5 ( & V_43 -> V_7 ) ;
return V_26 ;
}
static void F_46 ( struct V_89 * V_90 , bool V_121 )
{
struct V_75 * V_43 = F_38 ( V_90 ) ;
struct V_76 * V_77 = V_43 -> V_77 ;
unsigned int V_122 , V_123 ;
F_4 ( & V_43 -> V_7 ) ;
F_39 ( V_43 -> V_97 ) ;
V_122 = V_77 -> V_124 << V_125 |
V_77 -> V_126 << V_127 ;
if ( V_43 -> V_79 == V_101 ) {
V_122 |= V_77 -> V_128 << V_129 ;
V_122 |= ( V_130 << V_131 ) ;
}
if ( V_121 ) {
V_122 |= V_132 ;
V_123 = V_77 -> V_133 << 12 |
V_77 -> V_134 << 8 |
V_77 -> V_135 << 4 |
V_77 -> V_136 ;
if ( V_77 -> V_116 )
V_123 |= V_123 << 16 ;
} else {
V_122 |= V_137 ;
V_123 = 0 ;
}
F_44 ( V_123 , V_43 -> V_98 + V_138 ) ;
F_44 ( V_122 , V_43 -> V_98 + V_139 ) ;
F_45 ( V_43 -> V_97 ) ;
F_5 ( & V_43 -> V_7 ) ;
}
static int F_47 ( struct V_75 * V_43 )
{
T_1 V_78 ;
int V_22 ;
F_4 ( & V_43 -> V_7 ) ;
F_39 ( V_43 -> V_97 ) ;
V_78 = F_40 ( V_43 -> V_98 + V_140 ) ;
V_22 = F_36 ( V_43 , V_78 ) ;
F_45 ( V_43 -> V_97 ) ;
F_5 ( & V_43 -> V_7 ) ;
return V_22 ;
}
static void F_48 ( struct V_141 * V_142 )
{
struct V_75 * V_43 = F_49 ( V_142 ,
struct V_75 , V_143 ) ;
F_22 () ;
F_4 ( & V_43 -> V_7 ) ;
F_39 ( V_43 -> V_97 ) ;
if ( V_43 -> V_79 == V_101 )
F_44 ( V_119 |
V_120 ,
V_43 -> V_98 + V_115 ) ;
else
F_44 ( V_114 ,
V_43 -> V_98 + V_115 ) ;
F_45 ( V_43 -> V_97 ) ;
F_5 ( & V_43 -> V_7 ) ;
F_50 ( V_43 -> V_144 ) ;
}
static T_2 F_51 ( int V_144 , void * V_145 )
{
struct V_75 * V_43 = V_145 ;
F_52 ( V_144 ) ;
F_53 ( & V_43 -> V_143 ) ;
return V_146 ;
}
static inline struct V_76 * F_54 (
struct V_89 * V_90 )
{
#ifdef F_55
if ( V_90 -> V_147 . V_148 ) {
const struct V_149 * V_150 ;
V_150 = F_56 ( V_151 , V_90 -> V_147 . V_148 ) ;
if ( ! V_150 )
return NULL ;
return (struct V_76 * ) V_150 -> V_43 ;
}
#endif
return (struct V_76 * )
F_57 ( V_90 ) -> V_152 ;
}
static T_3 F_58 ( struct V_63 * V_147 ,
struct V_153 * V_154 ,
char * V_155 )
{
struct V_89 * V_90 = F_49 ( V_147 ,
struct V_89 , V_147 ) ;
struct V_75 * V_43 = F_38 ( V_90 ) ;
unsigned int V_156 ;
T_1 V_78 ;
int V_22 = 0 ;
if ( V_43 -> V_79 == V_80 )
goto V_81;
F_4 ( & V_43 -> V_7 ) ;
F_39 ( V_43 -> V_97 ) ;
V_156 = F_42 ( V_43 -> V_98 + V_157 ) ;
F_45 ( V_43 -> V_97 ) ;
F_5 ( & V_43 -> V_7 ) ;
if ( V_156 & V_158 ) {
V_156 >>= V_159 ;
V_78 = V_156 & V_160 ;
V_22 = F_36 ( V_43 , V_78 ) ;
}
V_81:
return sprintf ( V_155 , L_11 , V_22 * V_25 ) ;
}
static T_3 F_59 ( struct V_63 * V_147 ,
struct V_153 * V_154 ,
const char * V_155 , T_4 V_161 )
{
struct V_89 * V_90 = F_49 ( V_147 ,
struct V_89 , V_147 ) ;
struct V_75 * V_43 = F_38 ( V_90 ) ;
unsigned int V_156 ;
int V_22 ;
if ( V_43 -> V_79 == V_80 )
goto V_81;
if ( ! sscanf ( V_155 , L_11 , & V_22 ) || V_22 < 0 )
return - V_21 ;
F_4 ( & V_43 -> V_7 ) ;
F_39 ( V_43 -> V_97 ) ;
V_156 = F_42 ( V_43 -> V_98 + V_157 ) ;
if ( V_22 ) {
if ( V_22 > V_25 )
V_22 /= V_25 ;
V_156 = ( V_162 << V_163 ) |
( F_35 ( V_43 , ( V_22 / V_25 ) )
<< V_159 ) | V_158 ;
} else {
V_156 &= ~ V_158 ;
}
F_44 ( V_156 , V_43 -> V_98 + V_157 ) ;
F_45 ( V_43 -> V_97 ) ;
F_5 ( & V_43 -> V_7 ) ;
V_81:
return V_161 ;
}
static int F_60 ( struct V_63 * V_147 )
{
return F_61 ( V_147 , & V_164 ) ;
}
static void F_62 ( struct V_63 * V_147 )
{
F_63 ( V_147 , & V_164 ) ;
}
static inline int F_60 ( struct V_63 * V_147 ) { return 0 ; }
static inline void F_62 ( struct V_63 * V_147 ) {}
static int F_64 ( struct V_89 * V_90 )
{
struct V_75 * V_43 ;
struct V_76 * V_77 = V_90 -> V_147 . V_165 ;
int V_26 , V_29 ;
if ( ! V_77 )
V_77 = F_54 ( V_90 ) ;
if ( ! V_77 ) {
F_65 ( & V_90 -> V_147 , L_12 ) ;
return - V_166 ;
}
V_43 = F_66 ( & V_90 -> V_147 , sizeof( struct V_75 ) ,
V_69 ) ;
if ( ! V_43 ) {
F_65 ( & V_90 -> V_147 , L_13 ) ;
return - V_70 ;
}
V_43 -> V_144 = F_67 ( V_90 , 0 ) ;
if ( V_43 -> V_144 < 0 ) {
F_65 ( & V_90 -> V_147 , L_14 ) ;
return V_43 -> V_144 ;
}
F_68 ( & V_43 -> V_143 , F_48 ) ;
V_43 -> V_167 = F_69 ( V_90 , V_168 , 0 ) ;
if ( ! V_43 -> V_167 ) {
F_65 ( & V_90 -> V_147 , L_15 ) ;
return - V_169 ;
}
V_43 -> V_98 = F_70 ( & V_90 -> V_147 , V_43 -> V_167 ) ;
if ( F_28 ( V_43 -> V_98 ) )
return F_30 ( V_43 -> V_98 ) ;
V_26 = F_71 ( & V_90 -> V_147 , V_43 -> V_144 , F_51 ,
V_170 , L_16 , V_43 ) ;
if ( V_26 ) {
F_65 ( & V_90 -> V_147 , L_17 , V_43 -> V_144 ) ;
return V_26 ;
}
V_43 -> V_97 = F_72 ( NULL , L_18 ) ;
if ( F_28 ( V_43 -> V_97 ) ) {
F_65 ( & V_90 -> V_147 , L_19 ) ;
return F_30 ( V_43 -> V_97 ) ;
}
if ( V_77 -> type == V_101 ||
V_77 -> type == V_80 )
V_43 -> V_79 = V_77 -> type ;
else {
V_26 = - V_21 ;
F_65 ( & V_90 -> V_147 , L_20 ) ;
goto V_171;
}
V_43 -> V_77 = V_77 ;
F_73 ( V_90 , V_43 ) ;
F_74 ( & V_43 -> V_7 ) ;
V_26 = F_37 ( V_90 ) ;
if ( V_26 ) {
F_65 ( & V_90 -> V_147 , L_21 ) ;
goto V_171;
}
F_46 ( V_90 , true ) ;
( & V_172 ) -> V_51 = V_43 ;
V_172 . V_10 . V_60 = V_77 -> V_136 +
V_77 -> V_135 + V_77 -> V_134 +
V_77 -> V_133 ;
for ( V_29 = 0 ; V_29 < V_172 . V_10 . V_60 ; V_29 ++ )
V_172 . V_10 . V_24 [ V_29 ] =
V_77 -> V_111 + V_77 -> V_110 [ V_29 ] ;
V_172 . V_10 . V_11 = V_77 -> V_116 ;
V_172 . V_44 . V_46 =
V_77 -> V_173 ;
for ( V_29 = 0 ; V_29 < V_77 -> V_173 ; V_29 ++ ) {
V_172 . V_44 . V_45 [ V_29 ] . V_49 =
V_77 -> V_174 [ V_29 ] . V_49 ;
V_172 . V_44 . V_45 [ V_29 ] . V_175 =
V_77 -> V_174 [ V_29 ] . V_175 ;
}
V_26 = F_24 ( & V_172 ) ;
if ( V_26 ) {
F_65 ( & V_90 -> V_147 , L_22 ) ;
goto V_171;
}
V_26 = F_60 ( & V_90 -> V_147 ) ;
if ( V_26 )
F_65 ( & V_90 -> V_147 , L_23 ) ;
return 0 ;
V_171:
F_73 ( V_90 , NULL ) ;
F_75 ( V_43 -> V_97 ) ;
return V_26 ;
}
static int F_76 ( struct V_89 * V_90 )
{
struct V_75 * V_43 = F_38 ( V_90 ) ;
F_62 ( & V_90 -> V_147 ) ;
F_46 ( V_90 , false ) ;
F_31 () ;
F_75 ( V_43 -> V_97 ) ;
F_73 ( V_90 , NULL ) ;
return 0 ;
}
static int F_77 ( struct V_63 * V_147 )
{
F_46 ( F_78 ( V_147 ) , false ) ;
return 0 ;
}
static int F_79 ( struct V_63 * V_147 )
{
struct V_89 * V_90 = F_78 ( V_147 ) ;
F_37 ( V_90 ) ;
F_46 ( V_90 , true ) ;
return 0 ;
}
