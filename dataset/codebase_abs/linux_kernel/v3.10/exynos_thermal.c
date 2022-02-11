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
static int F_12 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
int V_26 = 0 , V_29 , V_30 , V_31 ;
struct V_32 * V_33 , * V_34 ;
struct V_35 * V_36 = V_5 -> V_9 ;
V_33 = (struct V_32 * ) V_36 -> V_37 . V_38 ;
V_30 = V_36 -> V_37 . V_39 ;
if ( V_33 == NULL || V_30 == 0 )
return - V_21 ;
for ( V_29 = 0 ; V_29 < V_5 -> V_40 ; V_29 ++ )
if ( V_28 == V_5 -> V_41 [ V_29 ] )
break;
if ( V_29 == V_5 -> V_40 )
return 0 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
V_34 = (struct V_32 * ) & ( V_33 [ V_29 ] ) ;
V_31 = F_13 ( 0 , V_34 -> V_42 ) ;
if ( V_31 == V_43 )
return 0 ;
switch ( F_9 ( V_29 ) ) {
case V_16 :
case V_17 :
if ( F_14 ( V_2 , V_29 , V_28 ,
V_31 , 0 ) ) {
F_15 ( L_3 , V_29 ) ;
V_26 = - V_21 ;
}
V_5 -> V_44 = true ;
break;
default:
V_26 = - V_21 ;
}
}
return V_26 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
int V_26 = 0 , V_29 , V_30 ;
struct V_35 * V_36 = V_5 -> V_9 ;
if ( V_5 -> V_44 == false )
return 0 ;
V_30 = V_36 -> V_37 . V_39 ;
if ( V_30 == 0 )
return - V_21 ;
for ( V_29 = 0 ; V_29 < V_5 -> V_40 ; V_29 ++ )
if ( V_28 == V_5 -> V_41 [ V_29 ] )
break;
if ( V_29 == V_5 -> V_40 )
return 0 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
switch ( F_9 ( V_29 ) ) {
case V_16 :
case V_17 :
if ( F_17 ( V_2 , V_29 ,
V_28 ) ) {
F_15 ( L_4 , V_29 ) ;
V_26 = - V_21 ;
}
V_5 -> V_44 = false ;
break;
default:
V_26 = - V_21 ;
}
}
return V_26 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned long * V_22 )
{
void * V_36 ;
if ( ! V_5 -> V_9 ) {
F_7 ( L_5 ) ;
return - V_21 ;
}
V_36 = V_5 -> V_9 -> V_45 ;
* V_22 = V_5 -> V_9 -> V_46 ( V_36 ) ;
* V_22 = * V_22 * V_25 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned long V_22 )
{
void * V_36 ;
int V_26 = - V_21 ;
if ( ! V_5 -> V_9 ) {
F_7 ( L_5 ) ;
return - V_21 ;
}
V_36 = V_5 -> V_9 -> V_45 ;
if ( V_5 -> V_9 -> V_47 )
V_26 = V_5 -> V_9 -> V_47 ( V_36 , V_22 ) ;
return V_26 ;
}
static int F_20 ( struct V_1 * V_2 ,
int V_14 , enum V_48 * V_49 )
{
int V_26 ;
unsigned long V_50 ;
V_26 = F_10 ( V_2 , V_14 , & V_50 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_2 -> V_51 >= V_50 )
* V_49 = V_52 ;
else
* V_49 = V_53 ;
return 0 ;
}
static void F_21 ( void )
{
unsigned int V_29 ;
char V_36 [ 10 ] ;
char * V_54 [] = { V_36 , NULL } ;
if ( ! V_5 || ! V_5 -> V_6 )
return;
if ( V_5 -> V_44 == false ) {
for ( V_29 = 0 ; V_29 < V_5 -> V_40 ; V_29 ++ ) {
if ( ! V_5 -> V_41 [ V_29 ] )
continue;
F_12 ( V_5 -> V_6 ,
V_5 -> V_41 [ V_29 ] ) ;
}
}
F_6 ( V_5 -> V_6 ) ;
F_4 ( & V_5 -> V_6 -> V_7 ) ;
for ( V_29 = 0 ; V_29 < V_5 -> V_9 -> V_10 . V_55 ; V_29 ++ ) {
if ( V_5 -> V_6 -> V_56 <
V_5 -> V_9 -> V_10 . V_24 [ V_29 ] * V_25 )
break;
}
if ( V_5 -> V_4 == V_8 &&
! V_5 -> V_9 -> V_10 . V_11 ) {
if ( V_29 > 0 )
V_5 -> V_6 -> V_12 = V_57 ;
else
V_5 -> V_6 -> V_12 = V_13 ;
}
snprintf ( V_36 , sizeof( V_36 ) , L_6 , V_29 ) ;
F_22 ( & V_5 -> V_6 -> V_58 . V_59 , V_60 , V_54 ) ;
F_5 ( & V_5 -> V_6 -> V_7 ) ;
}
static int F_23 ( struct V_35 * V_9 )
{
int V_26 ;
struct V_61 V_62 ;
if ( ! V_9 || ! V_9 -> V_46 ) {
F_15 ( L_5 ) ;
return - V_21 ;
}
V_5 = F_24 ( sizeof( struct V_63 ) , V_64 ) ;
if ( ! V_5 )
return - V_65 ;
V_5 -> V_9 = V_9 ;
F_25 ( 0 , & V_62 ) ;
V_5 -> V_41 [ 0 ] = F_26 ( & V_62 ) ;
if ( F_27 ( V_5 -> V_41 [ 0 ] ) ) {
F_15 ( L_7 ) ;
V_26 = - V_21 ;
goto V_66;
}
V_5 -> V_40 ++ ;
V_5 -> V_6 = F_28 ( V_9 -> V_67 ,
V_68 , 0 , NULL , & V_69 , NULL , 0 ,
V_9 -> V_10 . V_11 ?
0 : V_13 ) ;
if ( F_27 ( V_5 -> V_6 ) ) {
F_15 ( L_8 ) ;
V_26 = F_29 ( V_5 -> V_6 ) ;
goto V_66;
}
V_5 -> V_4 = V_8 ;
F_7 ( L_9 ) ;
return 0 ;
V_66:
F_30 () ;
return V_26 ;
}
static void F_30 ( void )
{
int V_29 ;
if ( ! V_5 )
return;
if ( V_5 -> V_6 )
F_31 ( V_5 -> V_6 ) ;
for ( V_29 = 0 ; V_29 < V_5 -> V_40 ; V_29 ++ ) {
if ( V_5 -> V_41 [ V_29 ] )
F_32 ( V_5 -> V_41 [ V_29 ] ) ;
}
F_33 ( V_5 ) ;
F_7 ( L_10 ) ;
}
static int F_34 ( struct V_70 * V_36 , T_1 V_22 )
{
struct V_71 * V_72 = V_36 -> V_72 ;
int V_73 ;
if ( V_36 -> V_74 == V_75 )
if ( V_22 < 25 || V_22 > 125 ) {
V_73 = - V_21 ;
goto V_76;
}
switch ( V_72 -> V_77 ) {
case V_78 :
V_73 = ( V_22 - 25 ) *
( V_36 -> V_79 - V_36 -> V_80 ) /
( 85 - 25 ) + V_36 -> V_80 ;
break;
case V_81 :
V_73 = V_22 + V_36 -> V_80 - 25 ;
break;
default:
V_73 = V_22 + V_82 ;
break;
}
V_76:
return V_73 ;
}
static int F_35 ( struct V_70 * V_36 , T_1 V_73 )
{
struct V_71 * V_72 = V_36 -> V_72 ;
int V_22 ;
if ( V_36 -> V_74 == V_75 )
if ( V_73 < 75 || V_73 > 175 ) {
V_22 = - V_83 ;
goto V_76;
}
switch ( V_72 -> V_77 ) {
case V_78 :
V_22 = ( V_73 - V_36 -> V_80 ) * ( 85 - 25 ) /
( V_36 -> V_79 - V_36 -> V_80 ) + 25 ;
break;
case V_81 :
V_22 = V_73 - V_36 -> V_80 + 25 ;
break;
default:
V_22 = V_73 - V_82 ;
break;
}
V_76:
return V_22 ;
}
static int F_36 ( struct V_84 * V_85 )
{
struct V_70 * V_36 = F_37 ( V_85 ) ;
struct V_71 * V_72 = V_36 -> V_72 ;
unsigned int V_86 , V_87 ;
unsigned int V_88 = 0 , V_89 = 0 ;
int V_26 = 0 , V_90 , V_29 , V_91 = 0 ;
F_4 ( & V_36 -> V_7 ) ;
F_38 ( V_36 -> V_92 ) ;
V_86 = F_39 ( V_36 -> V_93 + V_94 ) ;
if ( ! V_86 ) {
V_26 = - V_95 ;
goto V_76;
}
if ( V_36 -> V_74 == V_96 ) {
F_40 ( V_97 ,
V_36 -> V_93 + V_98 ) ;
}
V_87 = F_41 ( V_36 -> V_93 + V_99 ) ;
V_36 -> V_80 = V_87 & V_100 ;
V_36 -> V_79 = ( ( V_87 >> 8 ) & V_100 ) ;
if ( ( V_101 > V_36 -> V_80 ) ||
( V_36 -> V_80 > V_102 ) ||
( V_36 -> V_79 != 0 ) )
V_36 -> V_80 = V_72 -> V_103 ;
for ( V_29 = 0 ; V_29 < V_104 ; V_29 ++ )
if ( V_72 -> V_105 [ V_29 ] )
V_91 ++ ;
if ( V_36 -> V_74 == V_75 ) {
V_90 = F_34 ( V_36 , V_72 -> V_106 ) ;
if ( V_90 < 0 ) {
V_26 = V_90 ;
goto V_76;
}
F_42 ( V_90 ,
V_36 -> V_93 + V_107 ) ;
for ( V_29 = 0 ; V_29 < V_91 ; V_29 ++ )
F_42 ( V_72 -> V_105 [ V_29 ] ,
V_36 -> V_93 + V_108 + V_29 * 4 ) ;
F_43 ( V_109 ,
V_36 -> V_93 + V_110 ) ;
} else if ( V_36 -> V_74 == V_96 ) {
for ( V_29 = 0 ; V_29 < V_91 ; V_29 ++ ) {
V_90 = F_34 ( V_36 ,
V_72 -> V_105 [ V_29 ] ) ;
if ( V_90 < 0 ) {
V_26 = V_90 ;
goto V_76;
}
V_88 |= V_90 << 8 * V_29 ;
if ( V_72 -> V_111 ) {
V_90 = F_34 ( V_36 ,
V_72 -> V_105 [ V_29 ] -
V_72 -> V_111 ) ;
if ( V_90 > 0 )
V_89 |=
V_90 << 8 * V_29 ;
}
}
F_43 ( V_88 ,
V_36 -> V_93 + V_112 ) ;
F_43 ( V_89 ,
V_36 -> V_93 + V_113 ) ;
F_43 ( V_114 | V_115 ,
V_36 -> V_93 + V_110 ) ;
}
V_76:
F_44 ( V_36 -> V_92 ) ;
F_5 ( & V_36 -> V_7 ) ;
return V_26 ;
}
static void F_45 ( struct V_84 * V_85 , bool V_116 )
{
struct V_70 * V_36 = F_37 ( V_85 ) ;
struct V_71 * V_72 = V_36 -> V_72 ;
unsigned int V_117 , V_118 ;
F_4 ( & V_36 -> V_7 ) ;
F_38 ( V_36 -> V_92 ) ;
V_117 = V_72 -> V_119 << V_120 |
V_72 -> V_121 << V_122 ;
if ( V_36 -> V_74 == V_96 ) {
V_117 |= V_72 -> V_123 << V_124 ;
V_117 |= ( V_125 << V_126 ) ;
}
if ( V_116 ) {
V_117 |= V_127 ;
V_118 = V_72 -> V_128 << 12 |
V_72 -> V_129 << 8 |
V_72 -> V_130 << 4 |
V_72 -> V_131 ;
if ( V_72 -> V_111 )
V_118 |= V_118 << 16 ;
} else {
V_117 |= V_132 ;
V_118 = 0 ;
}
F_43 ( V_118 , V_36 -> V_93 + V_133 ) ;
F_43 ( V_117 , V_36 -> V_93 + V_134 ) ;
F_44 ( V_36 -> V_92 ) ;
F_5 ( & V_36 -> V_7 ) ;
}
static int F_46 ( struct V_70 * V_36 )
{
T_1 V_73 ;
int V_22 ;
F_4 ( & V_36 -> V_7 ) ;
F_38 ( V_36 -> V_92 ) ;
V_73 = F_39 ( V_36 -> V_93 + V_135 ) ;
V_22 = F_35 ( V_36 , V_73 ) ;
F_44 ( V_36 -> V_92 ) ;
F_5 ( & V_36 -> V_7 ) ;
return V_22 ;
}
static int F_47 ( void * V_136 , unsigned long V_22 )
{
struct V_70 * V_36 = V_136 ;
unsigned int V_137 ;
int V_26 = - V_21 ;
if ( V_36 -> V_74 == V_75 )
goto V_76;
if ( V_22 && V_22 < V_25 )
goto V_76;
F_4 ( & V_36 -> V_7 ) ;
F_38 ( V_36 -> V_92 ) ;
V_137 = F_41 ( V_36 -> V_93 + V_138 ) ;
if ( V_22 ) {
V_22 /= V_25 ;
V_137 = ( V_139 << V_140 ) |
( F_34 ( V_36 , V_22 )
<< V_141 ) | V_142 ;
} else {
V_137 &= ~ V_142 ;
}
F_43 ( V_137 , V_36 -> V_93 + V_138 ) ;
F_44 ( V_36 -> V_92 ) ;
F_5 ( & V_36 -> V_7 ) ;
return 0 ;
V_76:
return V_26 ;
}
static int F_47 ( void * V_136 , unsigned long V_22 )
{ return - V_21 ; }
static void F_48 ( struct V_143 * V_144 )
{
struct V_70 * V_36 = F_49 ( V_144 ,
struct V_70 , V_145 ) ;
F_21 () ;
F_4 ( & V_36 -> V_7 ) ;
F_38 ( V_36 -> V_92 ) ;
if ( V_36 -> V_74 == V_96 )
F_43 ( V_114 |
V_115 ,
V_36 -> V_93 + V_110 ) ;
else
F_43 ( V_109 ,
V_36 -> V_93 + V_110 ) ;
F_44 ( V_36 -> V_92 ) ;
F_5 ( & V_36 -> V_7 ) ;
F_50 ( V_36 -> V_146 ) ;
}
static T_2 F_51 ( int V_146 , void * V_147 )
{
struct V_70 * V_36 = V_147 ;
F_52 ( V_146 ) ;
F_53 ( & V_36 -> V_145 ) ;
return V_148 ;
}
static inline struct V_71 * F_54 (
struct V_84 * V_85 )
{
#ifdef F_55
if ( V_85 -> V_149 . V_150 ) {
const struct V_151 * V_152 ;
V_152 = F_56 ( V_153 , V_85 -> V_149 . V_150 ) ;
if ( ! V_152 )
return NULL ;
return (struct V_71 * ) V_152 -> V_36 ;
}
#endif
return (struct V_71 * )
F_57 ( V_85 ) -> V_154 ;
}
static int F_58 ( struct V_84 * V_85 )
{
struct V_70 * V_36 ;
struct V_71 * V_72 = V_85 -> V_149 . V_155 ;
int V_26 , V_29 ;
if ( ! V_72 )
V_72 = F_54 ( V_85 ) ;
if ( ! V_72 ) {
F_59 ( & V_85 -> V_149 , L_11 ) ;
return - V_156 ;
}
V_36 = F_60 ( & V_85 -> V_149 , sizeof( struct V_70 ) ,
V_64 ) ;
if ( ! V_36 ) {
F_59 ( & V_85 -> V_149 , L_12 ) ;
return - V_65 ;
}
V_36 -> V_146 = F_61 ( V_85 , 0 ) ;
if ( V_36 -> V_146 < 0 ) {
F_59 ( & V_85 -> V_149 , L_13 ) ;
return V_36 -> V_146 ;
}
F_62 ( & V_36 -> V_145 , F_48 ) ;
V_36 -> V_157 = F_63 ( V_85 , V_158 , 0 ) ;
V_36 -> V_93 = F_64 ( & V_85 -> V_149 , V_36 -> V_157 ) ;
if ( F_27 ( V_36 -> V_93 ) )
return F_29 ( V_36 -> V_93 ) ;
V_26 = F_65 ( & V_85 -> V_149 , V_36 -> V_146 , F_51 ,
V_159 , L_14 , V_36 ) ;
if ( V_26 ) {
F_59 ( & V_85 -> V_149 , L_15 , V_36 -> V_146 ) ;
return V_26 ;
}
V_36 -> V_92 = F_66 ( & V_85 -> V_149 , L_16 ) ;
if ( F_27 ( V_36 -> V_92 ) ) {
F_59 ( & V_85 -> V_149 , L_17 ) ;
return F_29 ( V_36 -> V_92 ) ;
}
V_26 = F_67 ( V_36 -> V_92 ) ;
if ( V_26 )
return V_26 ;
if ( V_72 -> type == V_96 ||
V_72 -> type == V_75 )
V_36 -> V_74 = V_72 -> type ;
else {
V_26 = - V_21 ;
F_59 ( & V_85 -> V_149 , L_18 ) ;
goto V_160;
}
V_36 -> V_72 = V_72 ;
F_68 ( V_85 , V_36 ) ;
F_69 ( & V_36 -> V_7 ) ;
V_26 = F_36 ( V_85 ) ;
if ( V_26 ) {
F_59 ( & V_85 -> V_149 , L_19 ) ;
goto V_160;
}
F_45 ( V_85 , true ) ;
( & V_161 ) -> V_45 = V_36 ;
V_161 . V_10 . V_55 = V_72 -> V_131 +
V_72 -> V_130 + V_72 -> V_129 +
V_72 -> V_128 ;
for ( V_29 = 0 ; V_29 < V_161 . V_10 . V_55 ; V_29 ++ )
V_161 . V_10 . V_24 [ V_29 ] =
V_72 -> V_106 + V_72 -> V_105 [ V_29 ] ;
V_161 . V_10 . V_11 = V_72 -> V_111 ;
V_161 . V_37 . V_39 =
V_72 -> V_162 ;
for ( V_29 = 0 ; V_29 < V_72 -> V_162 ; V_29 ++ ) {
V_161 . V_37 . V_38 [ V_29 ] . V_42 =
V_72 -> V_163 [ V_29 ] . V_42 ;
V_161 . V_37 . V_38 [ V_29 ] . V_164 =
V_72 -> V_163 [ V_29 ] . V_164 ;
}
V_26 = F_23 ( & V_161 ) ;
if ( V_26 ) {
F_59 ( & V_85 -> V_149 , L_20 ) ;
goto V_160;
}
return 0 ;
V_160:
F_68 ( V_85 , NULL ) ;
F_70 ( V_36 -> V_92 ) ;
return V_26 ;
}
static int F_71 ( struct V_84 * V_85 )
{
struct V_70 * V_36 = F_37 ( V_85 ) ;
F_45 ( V_85 , false ) ;
F_30 () ;
F_70 ( V_36 -> V_92 ) ;
F_68 ( V_85 , NULL ) ;
return 0 ;
}
static int F_72 ( struct V_58 * V_149 )
{
F_45 ( F_73 ( V_149 ) , false ) ;
return 0 ;
}
static int F_74 ( struct V_58 * V_149 )
{
struct V_84 * V_85 = F_73 ( V_149 ) ;
F_36 ( V_85 ) ;
F_45 ( V_85 , true ) ;
return 0 ;
}
