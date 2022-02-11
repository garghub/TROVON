static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
F_2 (rp, &rapl_packages, plist) {
if ( V_3 -> V_2 == V_2 )
return V_3 ;
}
return NULL ;
}
static void F_3 ( void )
{
struct V_1 * V_4 , * V_5 ;
F_4 (p, tmp, &rapl_packages, plist) {
F_5 ( V_4 -> V_6 ) ;
F_6 ( & V_4 -> V_7 ) ;
F_5 ( V_4 ) ;
}
}
static int F_7 ( struct V_8 * V_9 , T_1 * V_10 )
{
struct V_11 * V_12 ;
T_1 V_13 ;
F_8 () ;
V_12 = F_9 ( V_9 ) ;
if ( ! F_10 ( V_12 , V_14 , true , & V_13 ) ) {
* V_10 = V_13 ;
F_11 () ;
return 0 ;
}
F_11 () ;
return - V_15 ;
}
static int F_12 ( struct V_8 * V_16 , T_1 * V_17 )
{
struct V_11 * V_12 = F_9 ( V_16 ) ;
* V_17 = F_13 ( V_12 , V_18 , V_19 , 0 ) ;
return 0 ;
}
static int F_14 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_9 ( V_9 ) ;
struct V_1 * V_3 = V_12 -> V_3 ;
if ( V_12 -> V_2 == V_20 ) {
F_5 ( V_12 ) ;
V_3 -> V_6 = NULL ;
}
return 0 ;
}
static int F_15 ( struct V_11 * V_12 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( V_12 -> V_23 [ V_21 ] . V_24 == NULL )
break;
}
return V_21 ;
}
static int F_16 ( struct V_8 * V_9 , bool V_25 )
{
struct V_11 * V_12 = F_9 ( V_9 ) ;
if ( V_12 -> V_26 & V_27 )
return - V_28 ;
F_8 () ;
F_17 ( V_12 , V_29 , V_25 ) ;
if ( V_30 -> V_31 )
V_30 -> V_31 ( V_12 , V_25 ) ;
F_11 () ;
return 0 ;
}
static int F_18 ( struct V_8 * V_9 , bool * V_25 )
{
struct V_11 * V_12 = F_9 ( V_9 ) ;
T_1 V_32 ;
if ( V_12 -> V_26 & V_27 ) {
* V_25 = false ;
return 0 ;
}
F_8 () ;
if ( F_10 ( V_12 , V_29 , true , & V_32 ) ) {
F_11 () ;
return - V_15 ;
}
* V_25 = V_32 ;
F_11 () ;
return 0 ;
}
static int F_19 ( struct V_8 * V_9 , int V_2 ,
T_1 V_33 )
{
struct V_11 * V_12 ;
struct V_1 * V_3 ;
int V_34 = 0 ;
F_8 () ;
V_12 = F_9 ( V_9 ) ;
V_3 = V_12 -> V_3 ;
if ( V_12 -> V_26 & V_27 ) {
F_20 ( & V_9 -> V_35 , L_1 ,
V_12 -> V_24 ) ;
V_34 = - V_28 ;
goto V_36;
}
switch ( V_12 -> V_23 [ V_2 ] . V_37 ) {
case V_29 :
F_17 ( V_12 , V_38 , V_33 ) ;
break;
case V_39 :
F_17 ( V_12 , V_40 , V_33 ) ;
break;
default:
V_34 = - V_41 ;
}
if ( ! V_34 )
F_21 ( V_3 ) ;
V_36:
F_11 () ;
return V_34 ;
}
static int F_22 ( struct V_8 * V_9 , int V_2 ,
T_1 * V_42 )
{
struct V_11 * V_12 ;
T_1 V_32 ;
int V_43 ;
int V_34 = 0 ;
F_8 () ;
V_12 = F_9 ( V_9 ) ;
switch ( V_12 -> V_23 [ V_2 ] . V_37 ) {
case V_29 :
V_43 = V_38 ;
break;
case V_39 :
V_43 = V_40 ;
break;
default:
F_11 () ;
return - V_41 ;
}
if ( F_10 ( V_12 , V_43 , true , & V_32 ) )
V_34 = - V_15 ;
else
* V_42 = V_32 ;
F_11 () ;
return V_34 ;
}
static int F_23 ( struct V_8 * V_9 , int V_2 ,
T_1 V_44 )
{
struct V_11 * V_12 ;
int V_34 = 0 ;
F_8 () ;
V_12 = F_9 ( V_9 ) ;
switch ( V_12 -> V_23 [ V_2 ] . V_37 ) {
case V_29 :
F_17 ( V_12 , V_45 , V_44 ) ;
break;
case V_39 :
F_17 ( V_12 , V_46 , V_44 ) ;
break;
default:
V_34 = - V_41 ;
}
F_11 () ;
return V_34 ;
}
static int F_24 ( struct V_8 * V_9 , int V_2 , T_1 * V_42 )
{
struct V_11 * V_12 ;
T_1 V_32 ;
int V_34 = 0 ;
F_8 () ;
V_12 = F_9 ( V_9 ) ;
switch ( V_12 -> V_23 [ V_2 ] . V_37 ) {
case V_29 :
V_34 = F_10 ( V_12 , V_45 , true , & V_32 ) ;
break;
case V_39 :
V_34 = F_10 ( V_12 , V_46 , true , & V_32 ) ;
break;
default:
F_11 () ;
return - V_41 ;
}
if ( ! V_34 )
* V_42 = V_32 ;
F_11 () ;
return V_34 ;
}
static const char * F_25 ( struct V_8 * V_9 , int V_2 )
{
struct V_47 * V_23 ;
struct V_11 * V_12 ;
V_12 = F_9 ( V_9 ) ;
V_23 = (struct V_47 * ) & V_12 -> V_23 [ V_2 ] ;
return V_23 -> V_24 ;
}
static int F_26 ( struct V_8 * V_9 , int V_2 ,
T_1 * V_42 )
{
struct V_11 * V_12 ;
T_1 V_32 ;
int V_43 ;
int V_34 = 0 ;
F_8 () ;
V_12 = F_9 ( V_9 ) ;
switch ( V_12 -> V_23 [ V_2 ] . V_37 ) {
case V_29 :
V_43 = V_48 ;
break;
case V_39 :
V_43 = V_49 ;
break;
default:
F_11 () ;
return - V_41 ;
}
if ( F_10 ( V_12 , V_43 , true , & V_32 ) )
V_34 = - V_15 ;
else
* V_42 = V_32 ;
F_11 () ;
return V_34 ;
}
static void F_27 ( struct V_1 * V_3 )
{
int V_21 ;
struct V_11 * V_12 = V_3 -> V_6 ;
for ( V_21 = 0 ; V_21 < V_50 ; V_21 ++ ) {
unsigned int V_51 = V_3 -> V_52 & ( 1 << V_21 ) ;
switch ( V_51 ) {
case F_28 ( V_20 ) :
V_12 -> V_24 = V_53 [ V_20 ] ;
V_12 -> V_2 = V_20 ;
V_12 -> V_54 [ 0 ] = V_55 ;
V_12 -> V_54 [ 1 ] = V_56 ;
V_12 -> V_54 [ 2 ] = V_57 ;
V_12 -> V_54 [ 3 ] = 0 ;
V_12 -> V_54 [ 4 ] = V_58 ;
V_12 -> V_23 [ 0 ] . V_37 = V_29 ;
V_12 -> V_23 [ 0 ] . V_24 = V_59 ;
V_12 -> V_23 [ 1 ] . V_37 = V_39 ;
V_12 -> V_23 [ 1 ] . V_24 = V_60 ;
break;
case F_28 ( V_61 ) :
V_12 -> V_24 = V_53 [ V_61 ] ;
V_12 -> V_2 = V_61 ;
V_12 -> V_54 [ 0 ] = V_62 ;
V_12 -> V_54 [ 1 ] = V_63 ;
V_12 -> V_54 [ 2 ] = 0 ;
V_12 -> V_54 [ 3 ] = V_64 ;
V_12 -> V_54 [ 4 ] = 0 ;
V_12 -> V_23 [ 0 ] . V_37 = V_29 ;
V_12 -> V_23 [ 0 ] . V_24 = V_59 ;
break;
case F_28 ( V_65 ) :
V_12 -> V_24 = V_53 [ V_65 ] ;
V_12 -> V_2 = V_65 ;
V_12 -> V_54 [ 0 ] = V_66 ;
V_12 -> V_54 [ 1 ] = V_67 ;
V_12 -> V_54 [ 2 ] = 0 ;
V_12 -> V_54 [ 3 ] = V_68 ;
V_12 -> V_54 [ 4 ] = 0 ;
V_12 -> V_23 [ 0 ] . V_37 = V_29 ;
V_12 -> V_23 [ 0 ] . V_24 = V_59 ;
break;
case F_28 ( V_69 ) :
V_12 -> V_24 = V_53 [ V_69 ] ;
V_12 -> V_2 = V_69 ;
V_12 -> V_54 [ 0 ] = V_70 ;
V_12 -> V_54 [ 1 ] = V_71 ;
V_12 -> V_54 [ 2 ] = V_72 ;
V_12 -> V_54 [ 3 ] = 0 ;
V_12 -> V_54 [ 4 ] = V_73 ;
V_12 -> V_23 [ 0 ] . V_37 = V_29 ;
V_12 -> V_23 [ 0 ] . V_24 = V_59 ;
V_12 -> V_74 =
V_30 -> V_75 ;
if ( V_12 -> V_74 )
F_29 ( L_2 ,
V_12 -> V_74 ) ;
break;
}
if ( V_51 ) {
V_12 -> V_3 = V_3 ;
V_12 ++ ;
}
}
}
static T_1 F_13 ( struct V_11 * V_12 , enum V_76 type ,
T_1 V_77 , int V_78 )
{
T_1 V_79 = 1 ;
struct V_1 * V_3 = V_12 -> V_3 ;
T_1 V_80 = 1 ;
switch ( type ) {
case V_81 :
V_79 = V_3 -> V_82 ;
break;
case V_18 :
V_80 = V_83 ;
if ( V_12 && V_12 -> V_74 )
V_79 = V_12 -> V_74 ;
else
V_79 = V_3 -> V_84 ;
break;
case V_85 :
return V_30 -> V_86 ( V_3 , V_77 , V_78 ) ;
case V_87 :
default:
return V_77 ;
} ;
if ( V_78 )
return F_30 ( V_77 , V_79 ) * V_80 ;
V_77 *= V_79 ;
return F_30 ( V_77 , V_80 ) ;
}
static int F_10 ( struct V_11 * V_12 ,
enum V_88 V_43 ,
bool V_89 , T_1 * V_42 )
{
T_1 V_77 , V_90 ;
T_2 V_91 ;
struct V_92 * V_3 = & V_93 [ V_43 ] ;
int V_94 ;
if ( ! V_3 -> V_24 || V_3 -> V_95 & V_96 )
return - V_41 ;
V_91 = V_12 -> V_54 [ V_3 -> V_2 ] ;
if ( ! V_91 )
return - V_41 ;
V_94 = V_12 -> V_3 -> V_97 ;
if ( V_43 == V_98 && V_12 -> V_2 == V_20 ) {
V_3 -> V_51 = V_99 ;
V_3 -> V_100 = 63 ;
}
if ( V_3 -> V_95 & V_101 ) {
* V_42 = V_12 -> V_102 . V_103 [ V_43 ] ;
return 0 ;
}
if ( F_31 ( V_94 , V_91 , & V_77 ) ) {
F_32 ( L_3 , V_91 , V_94 ) ;
return - V_15 ;
}
V_90 = V_77 & V_3 -> V_51 ;
V_90 = V_90 >> V_3 -> V_100 ;
if ( V_89 )
* V_42 = F_13 ( V_12 , V_3 -> V_104 , V_90 , 0 ) ;
else
* V_42 = V_90 ;
return 0 ;
}
static int F_33 ( T_2 V_105 , T_1 V_106 , T_1 V_107 )
{
int V_108 ;
T_1 V_32 ;
V_108 = F_34 ( V_105 , & V_32 ) ;
if ( V_108 )
goto V_109;
V_32 &= ~ V_106 ;
V_32 |= V_107 ;
V_108 = F_35 ( V_105 , V_32 ) ;
V_109:
return V_108 ;
}
static void F_36 ( void * V_110 )
{
struct V_111 * V_112 = V_110 ;
V_112 -> V_108 = F_33 ( V_112 -> V_105 , V_112 -> V_106 , V_112 -> V_107 ) ;
}
static int F_17 ( struct V_11 * V_12 ,
enum V_88 V_43 ,
unsigned long long V_77 )
{
struct V_92 * V_3 = & V_93 [ V_43 ] ;
int V_94 ;
T_1 V_113 ;
struct V_111 V_112 ;
int V_34 ;
V_94 = V_12 -> V_3 -> V_97 ;
V_113 = F_13 ( V_12 , V_3 -> V_104 , V_77 , 1 ) ;
V_113 |= V_113 << V_3 -> V_100 ;
memset ( & V_112 , 0 , sizeof( V_112 ) ) ;
V_112 . V_105 = V_12 -> V_54 [ V_3 -> V_2 ] ;
V_112 . V_106 = V_3 -> V_51 ;
V_112 . V_107 = V_113 ;
V_34 = F_37 ( V_94 , F_36 , & V_112 , 1 ) ;
if ( V_34 )
F_38 ( V_34 ) ;
else
V_34 = V_112 . V_108 ;
return V_34 ;
}
static int F_39 ( struct V_1 * V_3 , int V_94 )
{
T_1 V_114 ;
T_2 V_77 ;
if ( F_31 ( V_94 , V_115 , & V_114 ) ) {
F_40 ( L_4 ,
V_115 , V_94 ) ;
return - V_116 ;
}
V_77 = ( V_114 & V_117 ) >> V_118 ;
V_3 -> V_84 = V_83 * 1000000 / ( 1 << V_77 ) ;
V_77 = ( V_114 & V_119 ) >> V_120 ;
V_3 -> V_82 = 1000000 / ( 1 << V_77 ) ;
V_77 = ( V_114 & V_121 ) >> V_122 ;
V_3 -> V_123 = 1000000 / ( 1 << V_77 ) ;
F_32 ( L_5 ,
V_3 -> V_2 , V_3 -> V_84 , V_3 -> V_123 , V_3 -> V_82 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_3 , int V_94 )
{
T_1 V_114 ;
T_2 V_77 ;
if ( F_31 ( V_94 , V_115 , & V_114 ) ) {
F_40 ( L_4 ,
V_115 , V_94 ) ;
return - V_116 ;
}
V_77 = ( V_114 & V_117 ) >> V_118 ;
V_3 -> V_84 = V_83 * 1 << V_77 ;
V_77 = ( V_114 & V_119 ) >> V_120 ;
V_3 -> V_82 = ( 1 << V_77 ) * 1000 ;
V_77 = ( V_114 & V_121 ) >> V_122 ;
V_3 -> V_123 = 1000000 / ( 1 << V_77 ) ;
F_32 ( L_6 ,
V_3 -> V_2 , V_3 -> V_84 , V_3 -> V_123 , V_3 -> V_82 ) ;
return 0 ;
}
static void F_42 ( void * V_110 )
{
T_2 V_124 , V_125 = 0 ;
struct V_1 * V_3 = (struct V_1 * ) V_110 ;
F_43 ( V_126 , & V_124 , & V_125 ) ;
if ( ! ( V_3 -> V_127 & V_128 ) ) {
V_3 -> V_127 = V_124 & V_129 ;
V_3 -> V_127 |= V_128 ;
}
V_124 &= ~ V_129 ;
F_44 ( V_126 , V_124 , V_125 ) ;
}
static void F_21 ( struct V_1 * V_3 )
{
if ( ! F_45 ( V_130 ) || ! F_45 ( V_131 ) )
return;
F_37 ( V_3 -> V_97 , F_42 , V_3 , 1 ) ;
}
static void F_46 ( void * V_110 )
{
T_2 V_124 , V_125 = 0 ;
struct V_1 * V_3 = (struct V_1 * ) V_110 ;
F_43 ( V_126 , & V_124 , & V_125 ) ;
if ( V_3 -> V_127 & V_129 )
V_124 |= V_129 ;
else
V_124 &= ~ V_129 ;
F_44 ( V_126 , V_124 , V_125 ) ;
}
static void F_47 ( struct V_1 * V_3 )
{
if ( ! F_45 ( V_130 ) || ! F_45 ( V_131 ) )
return;
if ( ! ( V_3 -> V_127 & V_128 ) )
return;
F_37 ( V_3 -> V_97 , F_46 , V_3 , 1 ) ;
}
static void F_48 ( struct V_11 * V_12 , bool V_25 )
{
int V_132 = F_15 ( V_12 ) ;
F_17 ( V_12 , V_133 , V_25 ) ;
if ( V_132 > 1 ) {
F_17 ( V_12 , V_39 , V_25 ) ;
F_17 ( V_12 , V_134 , V_25 ) ;
}
}
static void F_49 ( struct V_11 * V_12 , bool V_135 )
{
static T_2 V_136 ;
T_2 V_137 ;
if ( ! V_30 -> V_138 ) {
F_40 ( L_7 ) ;
return;
}
if ( ! V_136 )
F_50 ( V_139 , V_140 ,
V_30 -> V_138 ,
& V_136 ) ;
V_137 = V_136 ;
if ( V_135 ) {
V_137 &= ~ ( 0x7f << 8 ) ;
V_137 |= 1 << 8 ;
}
F_51 ( V_139 , V_141 ,
V_30 -> V_138 , V_137 ) ;
}
static T_1 F_52 ( struct V_1 * V_3 , T_1 V_77 ,
bool V_78 )
{
T_1 V_142 , V_143 ;
if ( ! V_78 ) {
V_142 = ( V_77 & 0x60 ) >> 5 ;
V_143 = V_77 & 0x1f ;
V_77 = ( 1 << V_143 ) * ( 4 + V_142 ) * V_3 -> V_123 / 4 ;
} else {
F_53 ( V_77 , V_3 -> V_123 ) ;
V_143 = F_54 ( V_77 ) ;
V_142 = F_30 ( 4 * ( V_77 - ( 1 << V_143 ) ) , 1 << V_143 ) ;
V_77 = ( V_143 & 0x1f ) | ( ( V_142 & 0x3 ) << 5 ) ;
}
return V_77 ;
}
static T_1 F_55 ( struct V_1 * V_3 , T_1 V_77 ,
bool V_78 )
{
if ( ! V_78 )
return ( V_77 ) ? V_77 *= V_3 -> V_123 : V_3 -> V_123 ;
else
V_77 = F_30 ( V_77 , V_3 -> V_123 ) ;
return V_77 ;
}
static void F_56 ( void )
{
int V_144 , V_43 ;
T_1 V_32 ;
struct V_1 * V_3 ;
F_2 (rp, &rapl_packages, plist) {
for ( V_144 = 0 ; V_144 < V_3 -> V_145 ; V_144 ++ ) {
F_32 ( L_8 , V_3 -> V_2 ,
V_3 -> V_6 [ V_144 ] . V_24 ) ;
for ( V_43 = 0 ; V_43 < V_146 ; V_43 ++ )
if ( ! F_10 ( & V_3 -> V_6 [ V_144 ] , V_43 ,
V_93 [ V_43 ] . V_104 ,
& V_32 ) )
V_3 -> V_6 [ V_144 ] . V_102 . V_103 [ V_43 ] =
V_32 ;
}
}
}
static int F_57 ( void )
{
struct V_1 * V_3 ;
struct V_11 * V_12 , * V_147 = NULL ;
F_2 (rp, &rapl_packages, plist) {
F_47 ( V_3 ) ;
for ( V_12 = V_3 -> V_6 ; V_12 < V_3 -> V_6 + V_3 -> V_145 ;
V_12 ++ ) {
F_32 ( L_9 ,
V_3 -> V_2 , V_12 -> V_24 ) ;
F_17 ( V_12 , V_29 , 0 ) ;
F_17 ( V_12 , V_133 , 0 ) ;
if ( F_15 ( V_12 ) > 1 ) {
F_17 ( V_12 , V_39 , 0 ) ;
F_17 ( V_12 , V_134 , 0 ) ;
}
if ( V_12 -> V_2 == V_20 ) {
V_147 = V_12 ;
continue;
}
F_58 ( V_148 , & V_12 -> V_9 ) ;
}
if ( V_147 )
F_58 ( V_148 ,
& V_147 -> V_9 ) ;
}
if ( V_149 ) {
F_58 ( V_148 ,
& V_149 -> V_9 ) ;
F_5 ( V_149 ) ;
}
F_59 ( V_148 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_3 )
{
struct V_11 * V_12 ;
int V_34 = 0 ;
char V_150 [ 17 ] ;
struct V_8 * V_9 = NULL ;
int V_151 ;
for ( V_12 = V_3 -> V_6 ; V_12 < V_3 -> V_6 + V_3 -> V_145 ; V_12 ++ ) {
if ( V_12 -> V_2 == V_20 ) {
V_151 = F_15 ( V_12 ) ;
F_32 ( L_10 ,
V_3 -> V_2 , V_12 -> V_24 ) ;
memset ( V_150 , 0 , sizeof( V_150 ) ) ;
snprintf ( V_150 , sizeof( V_150 ) , L_11 ,
V_12 -> V_24 , V_3 -> V_2 ) ;
V_9 = F_61 ( & V_12 -> V_9 ,
V_148 ,
V_150 , NULL ,
& V_152 [ V_12 -> V_2 ] ,
V_151 ,
& V_153 ) ;
if ( F_62 ( V_9 ) ) {
F_32 ( L_12 ,
V_3 -> V_2 ) ;
V_34 = F_63 ( V_9 ) ;
goto V_154;
}
V_3 -> V_9 = V_9 ;
break;
}
}
if ( ! V_9 ) {
F_40 ( L_13 ) ;
V_34 = - V_116 ;
goto V_154;
}
for ( V_12 = V_3 -> V_6 ; V_12 < V_3 -> V_6 + V_3 -> V_145 ; V_12 ++ ) {
if ( V_12 -> V_2 == V_20 )
continue;
V_151 = F_15 ( V_12 ) ;
V_9 = F_61 ( & V_12 -> V_9 ,
V_148 , V_12 -> V_24 ,
V_3 -> V_9 ,
& V_152 [ V_12 -> V_2 ] , V_151 ,
& V_153 ) ;
if ( F_62 ( V_9 ) ) {
F_32 ( L_14 ,
V_3 -> V_2 , V_12 -> V_24 , V_150 ) ;
V_34 = F_63 ( V_9 ) ;
goto V_155;
}
}
V_154:
return V_34 ;
V_155:
while ( -- V_12 >= V_3 -> V_6 ) {
F_32 ( L_15 , V_3 -> V_2 , V_12 -> V_24 ) ;
F_58 ( V_148 , & V_12 -> V_9 ) ;
}
return V_34 ;
}
static int F_64 ( void )
{
struct V_11 * V_12 ;
struct V_8 * V_9 ;
T_1 V_32 ;
if ( F_31 ( 0 , V_156 , & V_32 ) || ! V_32 )
return - V_116 ;
if ( F_31 ( 0 , V_157 , & V_32 ) || ! V_32 )
return - V_116 ;
V_12 = F_65 ( sizeof( * V_12 ) , V_158 ) ;
if ( ! V_12 )
return - V_159 ;
V_12 -> V_24 = V_53 [ V_160 ] ;
V_12 -> V_2 = V_160 ;
V_12 -> V_54 [ 0 ] = V_157 ;
V_12 -> V_54 [ 1 ] = V_156 ;
V_12 -> V_23 [ 0 ] . V_37 = V_29 ;
V_12 -> V_23 [ 0 ] . V_24 = V_59 ;
V_12 -> V_23 [ 1 ] . V_37 = V_39 ;
V_12 -> V_23 [ 1 ] . V_24 = V_60 ;
V_12 -> V_3 = F_1 ( 0 ) ;
V_9 = F_61 ( & V_12 -> V_9 , V_148 ,
L_16 , NULL ,
& V_152 [ V_160 ] ,
2 , & V_153 ) ;
if ( F_62 ( V_9 ) ) {
F_5 ( V_12 ) ;
return F_63 ( V_9 ) ;
}
V_149 = V_12 ;
return 0 ;
}
static int F_66 ( void )
{
struct V_11 * V_12 ;
struct V_1 * V_3 ;
int V_34 = 0 ;
V_148 = F_67 ( NULL , L_17 , NULL ) ;
if ( F_62 ( V_148 ) ) {
F_32 ( L_18 ) ;
return F_63 ( V_148 ) ;
}
F_56 () ;
F_2 (rp, &rapl_packages, plist)
if ( F_60 ( V_3 ) )
goto V_161;
F_64 () ;
return V_34 ;
V_161:
F_68 (rp, &rapl_packages, plist) {
for ( V_12 = V_3 -> V_6 ; V_12 < V_3 -> V_6 + V_3 -> V_145 ;
V_12 ++ ) {
F_32 ( L_19 ,
V_3 -> V_2 , V_12 -> V_24 ) ;
F_58 ( V_148 , & V_12 -> V_9 ) ;
}
}
return V_34 ;
}
static int F_69 ( int V_94 , int V_162 )
{
unsigned V_91 ;
T_1 V_32 = 0 ;
switch ( V_162 ) {
case V_20 :
V_91 = V_56 ;
break;
case V_61 :
V_91 = V_63 ;
break;
case V_65 :
V_91 = V_67 ;
break;
case V_69 :
V_91 = V_71 ;
break;
case V_160 :
return - V_41 ;
default:
F_40 ( L_20 , V_162 ) ;
return - V_41 ;
}
if ( F_31 ( V_94 , V_91 , & V_32 ) || ! V_32 )
return - V_116 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_3 , int V_94 )
{
int V_21 ;
int V_34 = 0 ;
struct V_11 * V_12 ;
T_1 V_163 ;
for ( V_21 = 0 ; V_21 < V_50 ; V_21 ++ ) {
if ( ! F_69 ( V_94 , V_21 ) ) {
V_3 -> V_52 |= 1 << V_21 ;
F_29 ( L_21 , V_53 [ V_21 ] ) ;
}
}
V_3 -> V_145 = F_71 ( & V_3 -> V_52 , V_50 ) ;
if ( ! V_3 -> V_145 ) {
F_40 ( L_22 , V_3 -> V_2 ) ;
V_34 = - V_116 ;
goto V_164;
}
F_32 ( L_23 , V_3 -> V_145 , V_3 -> V_2 ) ;
V_3 -> V_6 = F_72 ( V_3 -> V_145 + 1 , sizeof( struct V_11 ) ,
V_158 ) ;
if ( ! V_3 -> V_6 ) {
V_34 = - V_159 ;
goto V_164;
}
F_27 ( V_3 ) ;
for ( V_12 = V_3 -> V_6 ; V_12 < V_3 -> V_6 + V_3 -> V_145 ; V_12 ++ ) {
V_34 = F_10 ( V_12 , V_98 , false , & V_163 ) ;
if ( V_34 )
return V_34 ;
if ( V_163 ) {
F_29 ( L_24 ,
V_3 -> V_2 , V_12 -> V_24 ) ;
V_12 -> V_26 |= V_27 ;
}
}
V_164:
return V_34 ;
}
static bool F_73 ( int V_165 )
{
struct V_1 * V_3 ;
F_2 (rp, &rapl_packages, plist)
if ( V_165 == V_3 -> V_2 )
return false ;
return true ;
}
static int F_74 ( void )
{
int V_21 ;
int V_166 ;
struct V_1 * V_167 , * V_3 ;
F_75 (i) {
V_166 = F_76 ( V_21 ) ;
if ( F_73 ( V_166 ) ) {
V_167 = F_65 ( sizeof( * V_3 ) , V_158 ) ;
if ( ! V_167 ) {
F_3 () ;
return - V_159 ;
}
V_167 -> V_2 = V_166 ;
V_167 -> V_168 = 1 ;
V_167 -> V_97 = V_21 ;
if ( F_70 ( V_167 , V_21 ) ||
V_30 -> V_169 ( V_167 , V_21 ) ) {
F_5 ( V_167 -> V_6 ) ;
F_5 ( V_167 ) ;
F_3 () ;
return - V_116 ;
}
F_77 ( & V_167 -> V_7 ) ;
F_78 ( & V_167 -> V_7 , & V_170 ) ;
} else {
V_3 = F_1 ( V_166 ) ;
if ( V_3 )
++ V_3 -> V_168 ;
}
}
return 0 ;
}
static void F_79 ( struct V_1 * V_3 )
{
struct V_11 * V_12 , * V_147 = NULL ;
for ( V_12 = V_3 -> V_6 ; V_12 < V_3 -> V_6 + V_3 -> V_145 ; V_12 ++ ) {
if ( V_12 -> V_2 == V_20 ) {
V_147 = V_12 ;
continue;
}
F_32 ( L_25 , V_3 -> V_2 , V_12 -> V_24 ) ;
F_58 ( V_148 , & V_12 -> V_9 ) ;
}
F_58 ( V_148 , & V_147 -> V_9 ) ;
F_6 ( & V_3 -> V_7 ) ;
F_5 ( V_3 ) ;
}
static int F_80 ( int V_94 )
{
int V_34 = 0 ;
int V_166 ;
struct V_1 * V_3 ;
V_166 = F_76 ( V_94 ) ;
V_3 = F_65 ( sizeof( struct V_1 ) , V_158 ) ;
if ( ! V_3 )
return - V_159 ;
V_3 -> V_2 = V_166 ;
V_3 -> V_168 = 1 ;
V_3 -> V_97 = V_94 ;
if ( F_70 ( V_3 , V_94 ) ||
V_30 -> V_169 ( V_3 , V_94 ) ) {
V_34 = - V_116 ;
goto V_171;
}
if ( ! F_60 ( V_3 ) ) {
F_77 ( & V_3 -> V_7 ) ;
F_78 ( & V_3 -> V_7 , & V_170 ) ;
return V_34 ;
}
V_171:
F_5 ( V_3 -> V_6 ) ;
F_5 ( V_3 ) ;
return V_34 ;
}
static int F_81 ( struct V_172 * V_173 ,
unsigned long V_174 , void * V_175 )
{
unsigned long V_94 = ( unsigned long ) V_175 ;
int V_166 ;
struct V_1 * V_3 ;
int V_97 ;
V_166 = F_76 ( V_94 ) ;
switch ( V_174 ) {
case V_176 :
case V_177 :
case V_178 :
case V_179 :
V_3 = F_1 ( V_166 ) ;
if ( V_3 )
++ V_3 -> V_168 ;
else
F_80 ( V_94 ) ;
break;
case V_180 :
case V_181 :
V_3 = F_1 ( V_166 ) ;
if ( ! V_3 )
break;
if ( -- V_3 -> V_168 == 0 )
F_79 ( V_3 ) ;
else if ( V_94 == V_3 -> V_97 ) {
V_97 = F_82 ( F_83 ( V_94 ) , V_94 ) ;
if ( V_97 < V_182 )
V_3 -> V_97 = V_97 ;
else
F_40 ( L_26 ,
V_166 ) ;
}
}
return V_183 ;
}
static int T_3 F_84 ( void )
{
int V_34 = 0 ;
const struct V_184 * V_2 ;
V_2 = F_85 ( V_185 ) ;
if ( ! V_2 ) {
F_40 ( L_27 ,
V_186 . V_187 , V_186 . V_188 ) ;
return - V_116 ;
}
V_30 = (struct V_30 * ) V_2 -> V_189 ;
F_86 () ;
F_8 () ;
V_34 = F_74 () ;
if ( V_34 )
goto V_164;
if ( F_66 () ) {
F_3 () ;
V_34 = - V_116 ;
goto V_164;
}
F_87 ( & V_190 ) ;
V_164:
F_11 () ;
F_88 () ;
return V_34 ;
}
static void T_4 F_89 ( void )
{
F_86 () ;
F_8 () ;
F_90 ( & V_190 ) ;
F_57 () ;
F_3 () ;
F_11 () ;
F_88 () ;
}
