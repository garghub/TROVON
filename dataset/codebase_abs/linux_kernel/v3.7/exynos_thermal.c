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
if ( V_4 == V_8 )
V_5 -> V_6 -> V_9 = V_10 ;
else
V_5 -> V_6 -> V_9 = 0 ;
F_5 ( & V_5 -> V_6 -> V_7 ) ;
V_5 -> V_4 = V_4 ;
F_6 ( V_5 -> V_6 ) ;
F_7 ( L_2 ,
V_5 -> V_6 -> V_9 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , int V_11 ,
enum V_12 * type )
{
switch ( F_9 ( V_11 ) ) {
case V_13 :
case V_14 :
* type = V_15 ;
break;
case V_16 :
* type = V_17 ;
break;
default:
return - V_18 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , int V_11 ,
unsigned long * V_19 )
{
if ( V_11 < V_20 ( V_13 ) || V_11 > V_20 ( V_16 ) )
return - V_18 ;
* V_19 = V_5 -> V_21 -> V_22 . V_23 [ V_11 ] ;
* V_19 = * V_19 * V_24 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned long * V_19 )
{
int V_25 ;
V_25 = F_10 ( V_2 , V_20 ( V_16 ) , V_19 ) ;
return V_25 ;
}
static int F_12 ( unsigned int V_26 , unsigned int V_27 )
{
int V_28 = 0 , V_25 = - V_18 ;
struct V_29 * V_30 = NULL ;
#ifdef F_13
V_30 = F_14 ( V_26 ) ;
#endif
if ( ! V_30 )
return V_25 ;
while ( V_30 [ V_28 ] . V_31 != V_32 ) {
if ( V_30 [ V_28 ] . V_31 == V_33 )
continue;
if ( V_30 [ V_28 ] . V_31 == V_27 )
return V_28 ;
V_28 ++ ;
}
return V_25 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
int V_25 = 0 , V_28 , V_36 , V_37 ;
struct V_38 * V_39 , * V_40 ;
struct V_41 * V_42 = V_5 -> V_21 ;
V_39 = (struct V_38 * ) V_42 -> V_43 . V_44 ;
V_36 = V_42 -> V_43 . V_45 ;
if ( V_39 == NULL || V_36 == 0 )
return - V_18 ;
for ( V_28 = 0 ; V_28 < V_5 -> V_46 ; V_28 ++ )
if ( V_35 == V_5 -> V_47 [ V_28 ] )
break;
if ( V_28 == V_5 -> V_46 )
return 0 ;
for ( V_28 = 0 ; V_28 < V_36 ; V_28 ++ ) {
V_40 = (struct V_38 * ) & ( V_39 [ V_28 ] ) ;
V_37 = F_12 ( 0 , V_40 -> V_48 ) ;
if ( V_37 < 0 )
return 0 ;
switch ( F_9 ( V_28 ) ) {
case V_13 :
case V_14 :
if ( F_16 ( V_2 , V_28 , V_35 ,
V_37 , V_37 ) ) {
F_17 ( L_3 , V_28 ) ;
V_25 = - V_18 ;
}
V_5 -> V_49 = true ;
break;
default:
V_25 = - V_18 ;
}
}
return V_25 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
int V_25 = 0 , V_28 , V_36 ;
struct V_41 * V_42 = V_5 -> V_21 ;
if ( V_5 -> V_49 == false )
return 0 ;
V_36 = V_42 -> V_43 . V_45 ;
if ( V_36 == 0 )
return - V_18 ;
for ( V_28 = 0 ; V_28 < V_5 -> V_46 ; V_28 ++ )
if ( V_35 == V_5 -> V_47 [ V_28 ] )
break;
if ( V_28 == V_5 -> V_46 )
return 0 ;
for ( V_28 = 0 ; V_28 < V_36 ; V_28 ++ ) {
switch ( F_9 ( V_28 ) ) {
case V_13 :
case V_14 :
if ( F_19 ( V_2 , V_28 ,
V_35 ) ) {
F_17 ( L_4 , V_28 ) ;
V_25 = - V_18 ;
}
V_5 -> V_49 = false ;
break;
default:
V_25 = - V_18 ;
}
}
return V_25 ;
}
static int F_20 ( struct V_1 * V_2 ,
unsigned long * V_19 )
{
void * V_42 ;
if ( ! V_5 -> V_21 ) {
F_7 ( L_5 ) ;
return - V_18 ;
}
V_42 = V_5 -> V_21 -> V_50 ;
* V_19 = V_5 -> V_21 -> V_51 ( V_42 ) ;
* V_19 = * V_19 * V_24 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
int V_11 , enum V_52 * V_53 )
{
if ( V_2 -> V_54 >= V_11 )
* V_53 = V_55 ;
else
* V_53 = V_56 ;
return 0 ;
}
static void F_22 ( void )
{
unsigned int V_28 ;
char V_42 [ 10 ] ;
char * V_57 [] = { V_42 , NULL } ;
if ( ! V_5 || ! V_5 -> V_6 )
return;
if ( V_5 -> V_49 == false ) {
for ( V_28 = 0 ; V_28 < V_5 -> V_46 ; V_28 ++ ) {
if ( ! V_5 -> V_47 [ V_28 ] )
continue;
F_15 ( V_5 -> V_6 ,
V_5 -> V_47 [ V_28 ] ) ;
}
}
F_6 ( V_5 -> V_6 ) ;
F_4 ( & V_5 -> V_6 -> V_7 ) ;
for ( V_28 = 0 ; V_28 < V_5 -> V_21 -> V_22 . V_58 ; V_28 ++ ) {
if ( V_5 -> V_6 -> V_59 <
V_5 -> V_21 -> V_22 . V_23 [ V_28 ] * V_24 )
break;
}
if ( V_5 -> V_4 == V_8 ) {
if ( V_28 > 0 )
V_5 -> V_6 -> V_9 = V_60 ;
else
V_5 -> V_6 -> V_9 = V_10 ;
}
snprintf ( V_42 , sizeof( V_42 ) , L_6 , V_28 ) ;
F_23 ( & V_5 -> V_6 -> V_61 . V_62 , V_63 , V_57 ) ;
F_5 ( & V_5 -> V_6 -> V_7 ) ;
}
static int F_24 ( struct V_41 * V_21 )
{
int V_25 ;
struct V_64 V_65 ;
if ( ! V_21 || ! V_21 -> V_51 ) {
F_17 ( L_5 ) ;
return - V_18 ;
}
V_5 = F_25 ( sizeof( struct V_66 ) , V_67 ) ;
if ( ! V_5 )
return - V_68 ;
V_5 -> V_21 = V_21 ;
F_26 ( 0 , & V_65 ) ;
V_5 -> V_47 [ 0 ] = F_27 ( & V_65 ) ;
if ( F_28 ( V_5 -> V_47 [ 0 ] ) ) {
F_17 ( L_7 ) ;
V_25 = - V_18 ;
goto V_69;
}
V_5 -> V_46 ++ ;
V_5 -> V_6 = F_29 ( V_21 -> V_70 ,
V_71 , 0 , NULL , & V_72 , 0 ,
V_10 ) ;
if ( F_28 ( V_5 -> V_6 ) ) {
F_17 ( L_8 ) ;
V_25 = - V_18 ;
goto V_69;
}
V_5 -> V_4 = V_8 ;
F_7 ( L_9 ) ;
return 0 ;
V_69:
F_30 () ;
return V_25 ;
}
static void F_30 ( void )
{
int V_28 ;
if ( ! V_5 )
return;
if ( V_5 -> V_6 )
F_31 ( V_5 -> V_6 ) ;
for ( V_28 = 0 ; V_28 < V_5 -> V_46 ; V_28 ++ ) {
if ( V_5 -> V_47 [ V_28 ] )
F_32 ( V_5 -> V_47 [ V_28 ] ) ;
}
F_33 ( V_5 ) ;
F_7 ( L_10 ) ;
}
static int F_34 ( struct V_73 * V_42 , T_1 V_19 )
{
struct V_74 * V_75 = V_42 -> V_75 ;
int V_76 ;
if ( V_42 -> V_77 == V_78 )
if ( V_19 < 25 || V_19 > 125 ) {
V_76 = - V_18 ;
goto V_79;
}
switch ( V_75 -> V_80 ) {
case V_81 :
V_76 = ( V_19 - 25 ) *
( V_42 -> V_82 - V_42 -> V_83 ) /
( 85 - 25 ) + V_42 -> V_83 ;
break;
case V_84 :
V_76 = V_19 + V_42 -> V_83 - 25 ;
break;
default:
V_76 = V_19 + V_85 ;
break;
}
V_79:
return V_76 ;
}
static int F_35 ( struct V_73 * V_42 , T_1 V_76 )
{
struct V_74 * V_75 = V_42 -> V_75 ;
int V_19 ;
if ( V_42 -> V_77 == V_78 )
if ( V_76 < 75 || V_76 > 175 ) {
V_19 = - V_86 ;
goto V_79;
}
switch ( V_75 -> V_80 ) {
case V_81 :
V_19 = ( V_76 - V_42 -> V_83 ) * ( 85 - 25 ) /
( V_42 -> V_82 - V_42 -> V_83 ) + 25 ;
break;
case V_84 :
V_19 = V_76 - V_42 -> V_83 + 25 ;
break;
default:
V_19 = V_76 - V_85 ;
break;
}
V_79:
return V_19 ;
}
static int F_36 ( struct V_87 * V_88 )
{
struct V_73 * V_42 = F_37 ( V_88 ) ;
struct V_74 * V_75 = V_42 -> V_75 ;
unsigned int V_89 , V_90 , V_91 ;
int V_25 = 0 , V_92 ;
F_4 ( & V_42 -> V_7 ) ;
F_38 ( V_42 -> V_93 ) ;
V_89 = F_39 ( V_42 -> V_94 + V_95 ) ;
if ( ! V_89 ) {
V_25 = - V_96 ;
goto V_79;
}
if ( V_42 -> V_77 == V_97 ) {
F_40 ( V_98 ,
V_42 -> V_94 + V_99 ) ;
}
V_90 = F_41 ( V_42 -> V_94 + V_100 ) ;
V_42 -> V_83 = V_90 & V_101 ;
V_42 -> V_82 = ( ( V_90 >> 8 ) & V_101 ) ;
if ( ( V_102 > V_42 -> V_83 ) ||
( V_42 -> V_83 > V_103 ) ||
( V_42 -> V_82 != 0 ) )
V_42 -> V_83 = V_75 -> V_104 ;
if ( V_42 -> V_77 == V_78 ) {
V_92 = F_34 ( V_42 , V_75 -> V_105 ) ;
if ( V_92 < 0 ) {
V_25 = V_92 ;
goto V_79;
}
F_42 ( V_92 ,
V_42 -> V_94 + V_106 ) ;
F_42 ( V_75 -> V_107 [ 0 ] ,
V_42 -> V_94 + V_108 ) ;
F_42 ( V_75 -> V_107 [ 1 ] ,
V_42 -> V_94 + V_109 ) ;
F_42 ( V_75 -> V_107 [ 2 ] ,
V_42 -> V_94 + V_110 ) ;
F_42 ( V_75 -> V_107 [ 3 ] ,
V_42 -> V_94 + V_111 ) ;
F_43 ( V_112 ,
V_42 -> V_94 + V_113 ) ;
} else if ( V_42 -> V_77 == V_97 ) {
V_92 = F_34 ( V_42 , V_75 -> V_107 [ 0 ] ) ;
if ( V_92 < 0 ) {
V_25 = V_92 ;
goto V_79;
}
V_91 = V_92 ;
V_92 = F_34 ( V_42 , V_75 -> V_107 [ 1 ] ) ;
if ( V_92 < 0 ) {
V_25 = V_92 ;
goto V_79;
}
V_91 |= ( V_92 << 8 ) ;
V_92 = F_34 ( V_42 , V_75 -> V_107 [ 2 ] ) ;
if ( V_92 < 0 ) {
V_25 = V_92 ;
goto V_79;
}
V_91 |= ( V_92 << 16 ) ;
F_43 ( V_91 ,
V_42 -> V_94 + V_114 ) ;
F_43 ( 0 , V_42 -> V_94 + V_115 ) ;
F_43 ( V_116 | V_117 ,
V_42 -> V_94 + V_113 ) ;
}
V_79:
F_44 ( V_42 -> V_93 ) ;
F_5 ( & V_42 -> V_7 ) ;
return V_25 ;
}
static void F_45 ( struct V_87 * V_88 , bool V_118 )
{
struct V_73 * V_42 = F_37 ( V_88 ) ;
struct V_74 * V_75 = V_42 -> V_75 ;
unsigned int V_119 , V_120 ;
F_4 ( & V_42 -> V_7 ) ;
F_38 ( V_42 -> V_93 ) ;
V_119 = V_75 -> V_121 << V_122 |
V_75 -> V_123 << V_124 ;
if ( V_42 -> V_77 == V_97 ) {
V_119 |= V_75 -> V_125 << V_126 ;
V_119 |= ( V_127 << V_128 ) ;
}
if ( V_118 ) {
V_119 |= V_129 ;
V_120 = V_75 -> V_130 << 12 |
V_75 -> V_131 << 8 |
V_75 -> V_132 << 4 |
V_75 -> V_133 ;
} else {
V_119 |= V_134 ;
V_120 = 0 ;
}
F_43 ( V_120 , V_42 -> V_94 + V_135 ) ;
F_43 ( V_119 , V_42 -> V_94 + V_136 ) ;
F_44 ( V_42 -> V_93 ) ;
F_5 ( & V_42 -> V_7 ) ;
}
static int F_46 ( struct V_73 * V_42 )
{
T_1 V_76 ;
int V_19 ;
F_4 ( & V_42 -> V_7 ) ;
F_38 ( V_42 -> V_93 ) ;
V_76 = F_39 ( V_42 -> V_94 + V_137 ) ;
V_19 = F_35 ( V_42 , V_76 ) ;
F_44 ( V_42 -> V_93 ) ;
F_5 ( & V_42 -> V_7 ) ;
return V_19 ;
}
static void F_47 ( struct V_138 * V_139 )
{
struct V_73 * V_42 = F_48 ( V_139 ,
struct V_73 , V_140 ) ;
F_4 ( & V_42 -> V_7 ) ;
F_38 ( V_42 -> V_93 ) ;
if ( V_42 -> V_77 == V_97 )
F_43 ( V_116 ,
V_42 -> V_94 + V_113 ) ;
else
F_43 ( V_112 ,
V_42 -> V_94 + V_113 ) ;
F_44 ( V_42 -> V_93 ) ;
F_5 ( & V_42 -> V_7 ) ;
F_22 () ;
F_49 ( V_42 -> V_141 ) ;
}
static T_2 F_50 ( int V_141 , void * V_142 )
{
struct V_73 * V_42 = V_142 ;
F_51 ( V_141 ) ;
F_52 ( & V_42 -> V_140 ) ;
return V_143 ;
}
static inline struct V_74 * F_53 (
struct V_87 * V_88 )
{
#ifdef F_54
if ( V_88 -> V_144 . V_145 ) {
const struct V_146 * V_147 ;
V_147 = F_55 ( V_148 , V_88 -> V_144 . V_145 ) ;
if ( ! V_147 )
return NULL ;
return (struct V_74 * ) V_147 -> V_42 ;
}
#endif
return (struct V_74 * )
F_56 ( V_88 ) -> V_149 ;
}
static int T_3 F_57 ( struct V_87 * V_88 )
{
struct V_73 * V_42 ;
struct V_74 * V_75 = V_88 -> V_144 . V_150 ;
int V_25 , V_28 ;
if ( ! V_75 )
V_75 = F_53 ( V_88 ) ;
if ( ! V_75 ) {
F_58 ( & V_88 -> V_144 , L_11 ) ;
return - V_151 ;
}
V_42 = F_59 ( & V_88 -> V_144 , sizeof( struct V_73 ) ,
V_67 ) ;
if ( ! V_42 ) {
F_58 ( & V_88 -> V_144 , L_12 ) ;
return - V_68 ;
}
V_42 -> V_141 = F_60 ( V_88 , 0 ) ;
if ( V_42 -> V_141 < 0 ) {
F_58 ( & V_88 -> V_144 , L_13 ) ;
return V_42 -> V_141 ;
}
F_61 ( & V_42 -> V_140 , F_47 ) ;
V_42 -> V_152 = F_62 ( V_88 , V_153 , 0 ) ;
if ( ! V_42 -> V_152 ) {
F_58 ( & V_88 -> V_144 , L_14 ) ;
return - V_154 ;
}
V_42 -> V_94 = F_63 ( & V_88 -> V_144 , V_42 -> V_152 ) ;
if ( ! V_42 -> V_94 ) {
F_58 ( & V_88 -> V_144 , L_15 ) ;
return - V_151 ;
}
V_25 = F_64 ( & V_88 -> V_144 , V_42 -> V_141 , F_50 ,
V_155 , L_16 , V_42 ) ;
if ( V_25 ) {
F_58 ( & V_88 -> V_144 , L_17 , V_42 -> V_141 ) ;
return V_25 ;
}
V_42 -> V_93 = F_65 ( NULL , L_18 ) ;
if ( F_28 ( V_42 -> V_93 ) ) {
F_58 ( & V_88 -> V_144 , L_19 ) ;
return F_66 ( V_42 -> V_93 ) ;
}
if ( V_75 -> type == V_97 ||
V_75 -> type == V_78 )
V_42 -> V_77 = V_75 -> type ;
else {
V_25 = - V_18 ;
F_58 ( & V_88 -> V_144 , L_20 ) ;
goto V_156;
}
V_42 -> V_75 = V_75 ;
F_67 ( V_88 , V_42 ) ;
F_68 ( & V_42 -> V_7 ) ;
V_25 = F_36 ( V_88 ) ;
if ( V_25 ) {
F_58 ( & V_88 -> V_144 , L_21 ) ;
goto V_156;
}
F_45 ( V_88 , true ) ;
( & V_157 ) -> V_50 = V_42 ;
V_157 . V_22 . V_58 = V_75 -> V_133 +
V_75 -> V_132 + V_75 -> V_131 +
V_75 -> V_130 ;
for ( V_28 = 0 ; V_28 < V_157 . V_22 . V_58 ; V_28 ++ )
V_157 . V_22 . V_23 [ V_28 ] =
V_75 -> V_105 + V_75 -> V_107 [ V_28 ] ;
V_157 . V_43 . V_45 =
V_75 -> V_158 ;
for ( V_28 = 0 ; V_28 < V_75 -> V_158 ; V_28 ++ ) {
V_157 . V_43 . V_44 [ V_28 ] . V_48 =
V_75 -> V_159 [ V_28 ] . V_48 ;
V_157 . V_43 . V_44 [ V_28 ] . V_160 =
V_75 -> V_159 [ V_28 ] . V_160 ;
}
V_25 = F_24 ( & V_157 ) ;
if ( V_25 ) {
F_58 ( & V_88 -> V_144 , L_22 ) ;
goto V_156;
}
return 0 ;
V_156:
F_67 ( V_88 , NULL ) ;
F_69 ( V_42 -> V_93 ) ;
return V_25 ;
}
static int T_4 F_70 ( struct V_87 * V_88 )
{
struct V_73 * V_42 = F_37 ( V_88 ) ;
F_45 ( V_88 , false ) ;
F_30 () ;
F_69 ( V_42 -> V_93 ) ;
F_67 ( V_88 , NULL ) ;
return 0 ;
}
static int F_71 ( struct V_61 * V_144 )
{
F_45 ( F_72 ( V_144 ) , false ) ;
return 0 ;
}
static int F_73 ( struct V_61 * V_144 )
{
struct V_87 * V_88 = F_72 ( V_144 ) ;
F_36 ( V_88 ) ;
F_45 ( V_88 , true ) ;
return 0 ;
}
