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
int V_21 , V_22 = 0 ;
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ ) {
if ( V_12 -> V_24 [ V_21 ] . V_25 )
V_22 ++ ;
}
return V_22 ;
}
static int F_16 ( struct V_8 * V_9 , bool V_26 )
{
struct V_11 * V_12 = F_9 ( V_9 ) ;
if ( V_12 -> V_27 & V_28 )
return - V_29 ;
F_8 () ;
F_17 ( V_12 , V_30 , V_26 ) ;
if ( V_31 -> V_32 )
V_31 -> V_32 ( V_12 , V_26 ) ;
F_11 () ;
return 0 ;
}
static int F_18 ( struct V_8 * V_9 , bool * V_26 )
{
struct V_11 * V_12 = F_9 ( V_9 ) ;
T_1 V_33 ;
if ( V_12 -> V_27 & V_28 ) {
* V_26 = false ;
return 0 ;
}
F_8 () ;
if ( F_10 ( V_12 , V_30 , true , & V_33 ) ) {
F_11 () ;
return - V_15 ;
}
* V_26 = V_33 ;
F_11 () ;
return 0 ;
}
static int F_19 ( struct V_11 * V_12 , int V_34 )
{
int V_21 , V_35 ;
for ( V_21 = 0 , V_35 = 0 ; V_21 < V_23 ; V_21 ++ ) {
if ( ( V_12 -> V_24 [ V_21 ] . V_25 ) && V_35 ++ == V_34 ) {
F_20 ( L_1 , V_36 , V_21 ) ;
return V_21 ;
}
}
return - V_37 ;
}
static int F_21 ( struct V_8 * V_9 , int V_34 ,
T_1 V_38 )
{
struct V_11 * V_12 ;
struct V_1 * V_3 ;
int V_39 = 0 ;
int V_2 ;
F_8 () ;
V_12 = F_9 ( V_9 ) ;
V_2 = F_19 ( V_12 , V_34 ) ;
V_3 = V_12 -> V_3 ;
if ( V_12 -> V_27 & V_28 ) {
F_22 ( & V_9 -> V_40 , L_2 ,
V_12 -> V_25 ) ;
V_39 = - V_29 ;
goto V_41;
}
switch ( V_12 -> V_24 [ V_2 ] . V_42 ) {
case V_30 :
F_17 ( V_12 , V_43 , V_38 ) ;
break;
case V_44 :
F_17 ( V_12 , V_45 , V_38 ) ;
break;
default:
V_39 = - V_37 ;
}
if ( ! V_39 )
F_23 ( V_3 ) ;
V_41:
F_11 () ;
return V_39 ;
}
static int F_24 ( struct V_8 * V_9 , int V_34 ,
T_1 * V_46 )
{
struct V_11 * V_12 ;
T_1 V_33 ;
int V_47 ;
int V_39 = 0 ;
int V_2 ;
F_8 () ;
V_12 = F_9 ( V_9 ) ;
V_2 = F_19 ( V_12 , V_34 ) ;
switch ( V_12 -> V_24 [ V_2 ] . V_42 ) {
case V_30 :
V_47 = V_43 ;
break;
case V_44 :
V_47 = V_45 ;
break;
default:
F_11 () ;
return - V_37 ;
}
if ( F_10 ( V_12 , V_47 , true , & V_33 ) )
V_39 = - V_15 ;
else
* V_46 = V_33 ;
F_11 () ;
return V_39 ;
}
static int F_25 ( struct V_8 * V_9 , int V_34 ,
T_1 V_48 )
{
struct V_11 * V_12 ;
int V_39 = 0 ;
int V_2 ;
F_8 () ;
V_12 = F_9 ( V_9 ) ;
V_2 = F_19 ( V_12 , V_34 ) ;
switch ( V_12 -> V_24 [ V_2 ] . V_42 ) {
case V_30 :
F_17 ( V_12 , V_49 , V_48 ) ;
break;
case V_44 :
F_17 ( V_12 , V_50 , V_48 ) ;
break;
default:
V_39 = - V_37 ;
}
F_11 () ;
return V_39 ;
}
static int F_26 ( struct V_8 * V_9 , int V_34 , T_1 * V_46 )
{
struct V_11 * V_12 ;
T_1 V_33 ;
int V_39 = 0 ;
int V_2 ;
F_8 () ;
V_12 = F_9 ( V_9 ) ;
V_2 = F_19 ( V_12 , V_34 ) ;
switch ( V_12 -> V_24 [ V_2 ] . V_42 ) {
case V_30 :
V_39 = F_10 ( V_12 , V_49 , true , & V_33 ) ;
break;
case V_44 :
V_39 = F_10 ( V_12 , V_50 , true , & V_33 ) ;
break;
default:
F_11 () ;
return - V_37 ;
}
if ( ! V_39 )
* V_46 = V_33 ;
F_11 () ;
return V_39 ;
}
static const char * F_27 ( struct V_8 * V_9 , int V_34 )
{
struct V_11 * V_12 ;
int V_2 ;
V_12 = F_9 ( V_9 ) ;
V_2 = F_19 ( V_12 , V_34 ) ;
if ( V_2 >= 0 )
return V_12 -> V_24 [ V_2 ] . V_25 ;
return NULL ;
}
static int F_28 ( struct V_8 * V_9 , int V_2 ,
T_1 * V_46 )
{
struct V_11 * V_12 ;
T_1 V_33 ;
int V_47 ;
int V_39 = 0 ;
F_8 () ;
V_12 = F_9 ( V_9 ) ;
switch ( V_12 -> V_24 [ V_2 ] . V_42 ) {
case V_30 :
V_47 = V_51 ;
break;
case V_44 :
V_47 = V_52 ;
break;
default:
F_11 () ;
return - V_37 ;
}
if ( F_10 ( V_12 , V_47 , true , & V_33 ) )
V_39 = - V_15 ;
else
* V_46 = V_33 ;
F_11 () ;
return V_39 ;
}
static void F_29 ( struct V_1 * V_3 )
{
int V_21 ;
struct V_11 * V_12 = V_3 -> V_6 ;
for ( V_21 = 0 ; V_21 < V_53 ; V_21 ++ ) {
unsigned int V_54 = V_3 -> V_55 & ( 1 << V_21 ) ;
switch ( V_54 ) {
case F_30 ( V_20 ) :
V_12 -> V_25 = V_56 [ V_20 ] ;
V_12 -> V_2 = V_20 ;
V_12 -> V_57 [ 0 ] = V_58 ;
V_12 -> V_57 [ 1 ] = V_59 ;
V_12 -> V_57 [ 2 ] = V_60 ;
V_12 -> V_57 [ 3 ] = 0 ;
V_12 -> V_57 [ 4 ] = V_61 ;
V_12 -> V_24 [ 0 ] . V_42 = V_30 ;
V_12 -> V_24 [ 0 ] . V_25 = V_62 ;
V_12 -> V_24 [ 1 ] . V_42 = V_44 ;
V_12 -> V_24 [ 1 ] . V_25 = V_63 ;
break;
case F_30 ( V_64 ) :
V_12 -> V_25 = V_56 [ V_64 ] ;
V_12 -> V_2 = V_64 ;
V_12 -> V_57 [ 0 ] = V_65 ;
V_12 -> V_57 [ 1 ] = V_66 ;
V_12 -> V_57 [ 2 ] = 0 ;
V_12 -> V_57 [ 3 ] = V_67 ;
V_12 -> V_57 [ 4 ] = 0 ;
V_12 -> V_24 [ 0 ] . V_42 = V_30 ;
V_12 -> V_24 [ 0 ] . V_25 = V_62 ;
break;
case F_30 ( V_68 ) :
V_12 -> V_25 = V_56 [ V_68 ] ;
V_12 -> V_2 = V_68 ;
V_12 -> V_57 [ 0 ] = V_69 ;
V_12 -> V_57 [ 1 ] = V_70 ;
V_12 -> V_57 [ 2 ] = 0 ;
V_12 -> V_57 [ 3 ] = V_71 ;
V_12 -> V_57 [ 4 ] = 0 ;
V_12 -> V_24 [ 0 ] . V_42 = V_30 ;
V_12 -> V_24 [ 0 ] . V_25 = V_62 ;
break;
case F_30 ( V_72 ) :
V_12 -> V_25 = V_56 [ V_72 ] ;
V_12 -> V_2 = V_72 ;
V_12 -> V_57 [ 0 ] = V_73 ;
V_12 -> V_57 [ 1 ] = V_74 ;
V_12 -> V_57 [ 2 ] = V_75 ;
V_12 -> V_57 [ 3 ] = 0 ;
V_12 -> V_57 [ 4 ] = V_76 ;
V_12 -> V_24 [ 0 ] . V_42 = V_30 ;
V_12 -> V_24 [ 0 ] . V_25 = V_62 ;
V_12 -> V_77 =
V_31 -> V_78 ;
if ( V_12 -> V_77 )
F_31 ( L_3 ,
V_12 -> V_77 ) ;
break;
}
if ( V_54 ) {
V_12 -> V_3 = V_3 ;
V_12 ++ ;
}
}
}
static T_1 F_13 ( struct V_11 * V_12 , enum V_79 type ,
T_1 V_80 , int V_81 )
{
T_1 V_82 = 1 ;
struct V_1 * V_3 = V_12 -> V_3 ;
T_1 V_83 = 1 ;
switch ( type ) {
case V_84 :
V_82 = V_3 -> V_85 ;
break;
case V_18 :
V_83 = V_86 ;
if ( V_12 && V_12 -> V_77 )
V_82 = V_12 -> V_77 ;
else
V_82 = V_3 -> V_87 ;
break;
case V_88 :
return V_31 -> V_89 ( V_3 , V_80 , V_81 ) ;
case V_90 :
default:
return V_80 ;
} ;
if ( V_81 )
return F_32 ( V_80 , V_82 ) * V_83 ;
V_80 *= V_82 ;
return F_32 ( V_80 , V_83 ) ;
}
static int F_10 ( struct V_11 * V_12 ,
enum V_91 V_47 ,
bool V_92 , T_1 * V_46 )
{
T_1 V_80 , V_93 ;
T_2 V_94 ;
struct V_95 * V_3 = & V_96 [ V_47 ] ;
int V_97 ;
if ( ! V_3 -> V_25 || V_3 -> V_98 & V_99 )
return - V_37 ;
V_94 = V_12 -> V_57 [ V_3 -> V_2 ] ;
if ( ! V_94 )
return - V_37 ;
V_97 = V_12 -> V_3 -> V_100 ;
if ( V_47 == V_101 && V_12 -> V_2 == V_20 ) {
V_3 -> V_54 = V_102 ;
V_3 -> V_103 = 63 ;
}
if ( V_3 -> V_98 & V_104 ) {
* V_46 = V_12 -> V_105 . V_106 [ V_47 ] ;
return 0 ;
}
if ( F_33 ( V_97 , V_94 , & V_80 ) ) {
F_20 ( L_4 , V_94 , V_97 ) ;
return - V_15 ;
}
V_93 = V_80 & V_3 -> V_54 ;
V_93 = V_93 >> V_3 -> V_103 ;
if ( V_92 )
* V_46 = F_13 ( V_12 , V_3 -> V_107 , V_93 , 0 ) ;
else
* V_46 = V_93 ;
return 0 ;
}
static int F_34 ( T_2 V_108 , T_1 V_109 , T_1 V_110 )
{
int V_111 ;
T_1 V_33 ;
V_111 = F_35 ( V_108 , & V_33 ) ;
if ( V_111 )
goto V_112;
V_33 &= ~ V_109 ;
V_33 |= V_110 ;
V_111 = F_36 ( V_108 , V_33 ) ;
V_112:
return V_111 ;
}
static void F_37 ( void * V_113 )
{
struct V_114 * V_115 = V_113 ;
V_115 -> V_111 = F_34 ( V_115 -> V_108 , V_115 -> V_109 , V_115 -> V_110 ) ;
}
static int F_17 ( struct V_11 * V_12 ,
enum V_91 V_47 ,
unsigned long long V_80 )
{
struct V_95 * V_3 = & V_96 [ V_47 ] ;
int V_97 ;
T_1 V_116 ;
struct V_114 V_115 ;
int V_39 ;
V_97 = V_12 -> V_3 -> V_100 ;
V_116 = F_13 ( V_12 , V_3 -> V_107 , V_80 , 1 ) ;
V_116 |= V_116 << V_3 -> V_103 ;
memset ( & V_115 , 0 , sizeof( V_115 ) ) ;
V_115 . V_108 = V_12 -> V_57 [ V_3 -> V_2 ] ;
V_115 . V_109 = V_3 -> V_54 ;
V_115 . V_110 = V_116 ;
V_39 = F_38 ( V_97 , F_37 , & V_115 , 1 ) ;
if ( V_39 )
F_39 ( V_39 ) ;
else
V_39 = V_115 . V_111 ;
return V_39 ;
}
static int F_40 ( struct V_1 * V_3 , int V_97 )
{
T_1 V_117 ;
T_2 V_80 ;
if ( F_33 ( V_97 , V_118 , & V_117 ) ) {
F_41 ( L_5 ,
V_118 , V_97 ) ;
return - V_119 ;
}
V_80 = ( V_117 & V_120 ) >> V_121 ;
V_3 -> V_87 = V_86 * 1000000 / ( 1 << V_80 ) ;
V_80 = ( V_117 & V_122 ) >> V_123 ;
V_3 -> V_85 = 1000000 / ( 1 << V_80 ) ;
V_80 = ( V_117 & V_124 ) >> V_125 ;
V_3 -> V_126 = 1000000 / ( 1 << V_80 ) ;
F_20 ( L_6 ,
V_3 -> V_2 , V_3 -> V_87 , V_3 -> V_126 , V_3 -> V_85 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_3 , int V_97 )
{
T_1 V_117 ;
T_2 V_80 ;
if ( F_33 ( V_97 , V_118 , & V_117 ) ) {
F_41 ( L_5 ,
V_118 , V_97 ) ;
return - V_119 ;
}
V_80 = ( V_117 & V_120 ) >> V_121 ;
V_3 -> V_87 = V_86 * 1 << V_80 ;
V_80 = ( V_117 & V_122 ) >> V_123 ;
V_3 -> V_85 = ( 1 << V_80 ) * 1000 ;
V_80 = ( V_117 & V_124 ) >> V_125 ;
V_3 -> V_126 = 1000000 / ( 1 << V_80 ) ;
F_20 ( L_7 ,
V_3 -> V_2 , V_3 -> V_87 , V_3 -> V_126 , V_3 -> V_85 ) ;
return 0 ;
}
static void F_43 ( void * V_113 )
{
T_2 V_127 , V_128 = 0 ;
struct V_1 * V_3 = (struct V_1 * ) V_113 ;
F_44 ( V_129 , & V_127 , & V_128 ) ;
if ( ! ( V_3 -> V_130 & V_131 ) ) {
V_3 -> V_130 = V_127 & V_132 ;
V_3 -> V_130 |= V_131 ;
}
V_127 &= ~ V_132 ;
F_45 ( V_129 , V_127 , V_128 ) ;
}
static void F_23 ( struct V_1 * V_3 )
{
if ( ! F_46 ( V_133 ) || ! F_46 ( V_134 ) )
return;
F_38 ( V_3 -> V_100 , F_43 , V_3 , 1 ) ;
}
static void F_47 ( void * V_113 )
{
T_2 V_127 , V_128 = 0 ;
struct V_1 * V_3 = (struct V_1 * ) V_113 ;
F_44 ( V_129 , & V_127 , & V_128 ) ;
if ( V_3 -> V_130 & V_132 )
V_127 |= V_132 ;
else
V_127 &= ~ V_132 ;
F_45 ( V_129 , V_127 , V_128 ) ;
}
static void F_48 ( struct V_1 * V_3 )
{
if ( ! F_46 ( V_133 ) || ! F_46 ( V_134 ) )
return;
if ( ! ( V_3 -> V_130 & V_131 ) )
return;
F_38 ( V_3 -> V_100 , F_47 , V_3 , 1 ) ;
}
static void F_49 ( struct V_11 * V_12 , bool V_26 )
{
int V_135 = F_15 ( V_12 ) ;
F_17 ( V_12 , V_136 , V_26 ) ;
if ( V_135 > 1 ) {
F_17 ( V_12 , V_44 , V_26 ) ;
F_17 ( V_12 , V_137 , V_26 ) ;
}
}
static void F_50 ( struct V_11 * V_12 , bool V_138 )
{
static T_2 V_139 ;
T_2 V_140 ;
if ( ! V_31 -> V_141 ) {
F_41 ( L_8 ) ;
return;
}
if ( ! V_139 )
F_51 ( V_142 , V_143 ,
V_31 -> V_141 ,
& V_139 ) ;
V_140 = V_139 ;
if ( V_138 ) {
V_140 &= ~ ( 0x7f << 8 ) ;
V_140 |= 1 << 8 ;
}
F_52 ( V_142 , V_144 ,
V_31 -> V_141 , V_140 ) ;
}
static T_1 F_53 ( struct V_1 * V_3 , T_1 V_80 ,
bool V_81 )
{
T_1 V_145 , V_146 ;
if ( ! V_81 ) {
V_145 = ( V_80 & 0x60 ) >> 5 ;
V_146 = V_80 & 0x1f ;
V_80 = ( 1 << V_146 ) * ( 4 + V_145 ) * V_3 -> V_126 / 4 ;
} else {
F_54 ( V_80 , V_3 -> V_126 ) ;
V_146 = F_55 ( V_80 ) ;
V_145 = F_32 ( 4 * ( V_80 - ( 1 << V_146 ) ) , 1 << V_146 ) ;
V_80 = ( V_146 & 0x1f ) | ( ( V_145 & 0x3 ) << 5 ) ;
}
return V_80 ;
}
static T_1 F_56 ( struct V_1 * V_3 , T_1 V_80 ,
bool V_81 )
{
if ( ! V_81 )
return ( V_80 ) ? V_80 *= V_3 -> V_126 : V_3 -> V_126 ;
else
V_80 = F_32 ( V_80 , V_3 -> V_126 ) ;
return V_80 ;
}
static void F_57 ( void )
{
int V_147 , V_47 ;
T_1 V_33 ;
struct V_1 * V_3 ;
F_2 (rp, &rapl_packages, plist) {
for ( V_147 = 0 ; V_147 < V_3 -> V_148 ; V_147 ++ ) {
F_20 ( L_9 , V_3 -> V_2 ,
V_3 -> V_6 [ V_147 ] . V_25 ) ;
for ( V_47 = 0 ; V_47 < V_149 ; V_47 ++ )
if ( ! F_10 ( & V_3 -> V_6 [ V_147 ] , V_47 ,
V_96 [ V_47 ] . V_107 ,
& V_33 ) )
V_3 -> V_6 [ V_147 ] . V_105 . V_106 [ V_47 ] =
V_33 ;
}
}
}
static int F_58 ( void )
{
struct V_1 * V_3 ;
struct V_11 * V_12 , * V_150 = NULL ;
F_2 (rp, &rapl_packages, plist) {
F_48 ( V_3 ) ;
for ( V_12 = V_3 -> V_6 ; V_12 < V_3 -> V_6 + V_3 -> V_148 ;
V_12 ++ ) {
F_20 ( L_10 ,
V_3 -> V_2 , V_12 -> V_25 ) ;
F_17 ( V_12 , V_30 , 0 ) ;
F_17 ( V_12 , V_136 , 0 ) ;
if ( F_15 ( V_12 ) > 1 ) {
F_17 ( V_12 , V_44 , 0 ) ;
F_17 ( V_12 , V_137 , 0 ) ;
}
if ( V_12 -> V_2 == V_20 ) {
V_150 = V_12 ;
continue;
}
F_59 ( V_151 , & V_12 -> V_9 ) ;
}
if ( V_150 )
F_59 ( V_151 ,
& V_150 -> V_9 ) ;
}
if ( V_152 ) {
F_59 ( V_151 ,
& V_152 -> V_9 ) ;
F_5 ( V_152 ) ;
}
F_60 ( V_151 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_3 )
{
struct V_11 * V_12 ;
int V_39 = 0 ;
char V_153 [ 17 ] ;
struct V_8 * V_9 = NULL ;
int V_22 ;
for ( V_12 = V_3 -> V_6 ; V_12 < V_3 -> V_6 + V_3 -> V_148 ; V_12 ++ ) {
if ( V_12 -> V_2 == V_20 ) {
V_22 = F_15 ( V_12 ) ;
F_20 ( L_11 ,
V_3 -> V_2 , V_12 -> V_25 ) ;
memset ( V_153 , 0 , sizeof( V_153 ) ) ;
snprintf ( V_153 , sizeof( V_153 ) , L_12 ,
V_12 -> V_25 , V_3 -> V_2 ) ;
V_9 = F_62 ( & V_12 -> V_9 ,
V_151 ,
V_153 , NULL ,
& V_154 [ V_12 -> V_2 ] ,
V_22 ,
& V_155 ) ;
if ( F_63 ( V_9 ) ) {
F_20 ( L_13 ,
V_3 -> V_2 ) ;
V_39 = F_64 ( V_9 ) ;
goto V_156;
}
V_3 -> V_9 = V_9 ;
break;
}
}
if ( ! V_9 ) {
F_41 ( L_14 ) ;
V_39 = - V_119 ;
goto V_156;
}
for ( V_12 = V_3 -> V_6 ; V_12 < V_3 -> V_6 + V_3 -> V_148 ; V_12 ++ ) {
if ( V_12 -> V_2 == V_20 )
continue;
V_22 = F_15 ( V_12 ) ;
V_9 = F_62 ( & V_12 -> V_9 ,
V_151 , V_12 -> V_25 ,
V_3 -> V_9 ,
& V_154 [ V_12 -> V_2 ] , V_22 ,
& V_155 ) ;
if ( F_63 ( V_9 ) ) {
F_20 ( L_15 ,
V_3 -> V_2 , V_12 -> V_25 , V_153 ) ;
V_39 = F_64 ( V_9 ) ;
goto V_157;
}
}
V_156:
return V_39 ;
V_157:
while ( -- V_12 >= V_3 -> V_6 ) {
F_20 ( L_16 , V_3 -> V_2 , V_12 -> V_25 ) ;
F_59 ( V_151 , & V_12 -> V_9 ) ;
}
return V_39 ;
}
static int F_65 ( void )
{
struct V_11 * V_12 ;
struct V_8 * V_9 ;
T_1 V_33 ;
if ( F_33 ( 0 , V_158 , & V_33 ) || ! V_33 )
return - V_119 ;
if ( F_33 ( 0 , V_159 , & V_33 ) || ! V_33 )
return - V_119 ;
V_12 = F_66 ( sizeof( * V_12 ) , V_160 ) ;
if ( ! V_12 )
return - V_161 ;
V_12 -> V_25 = V_56 [ V_162 ] ;
V_12 -> V_2 = V_162 ;
V_12 -> V_57 [ 0 ] = V_159 ;
V_12 -> V_57 [ 1 ] = V_158 ;
V_12 -> V_24 [ 0 ] . V_42 = V_30 ;
V_12 -> V_24 [ 0 ] . V_25 = V_62 ;
V_12 -> V_24 [ 1 ] . V_42 = V_44 ;
V_12 -> V_24 [ 1 ] . V_25 = V_63 ;
V_12 -> V_3 = F_1 ( 0 ) ;
V_9 = F_62 ( & V_12 -> V_9 , V_151 ,
L_17 , NULL ,
& V_154 [ V_162 ] ,
2 , & V_155 ) ;
if ( F_63 ( V_9 ) ) {
F_5 ( V_12 ) ;
return F_64 ( V_9 ) ;
}
V_152 = V_12 ;
return 0 ;
}
static int F_67 ( void )
{
struct V_11 * V_12 ;
struct V_1 * V_3 ;
int V_39 = 0 ;
V_151 = F_68 ( NULL , L_18 , NULL ) ;
if ( F_63 ( V_151 ) ) {
F_20 ( L_19 ) ;
return F_64 ( V_151 ) ;
}
F_57 () ;
F_2 (rp, &rapl_packages, plist)
if ( F_61 ( V_3 ) )
goto V_163;
F_65 () ;
return V_39 ;
V_163:
F_69 (rp, &rapl_packages, plist) {
for ( V_12 = V_3 -> V_6 ; V_12 < V_3 -> V_6 + V_3 -> V_148 ;
V_12 ++ ) {
F_20 ( L_20 ,
V_3 -> V_2 , V_12 -> V_25 ) ;
F_59 ( V_151 , & V_12 -> V_9 ) ;
}
}
return V_39 ;
}
static int F_70 ( int V_97 , int V_164 )
{
unsigned V_94 ;
T_1 V_33 = 0 ;
switch ( V_164 ) {
case V_20 :
V_94 = V_59 ;
break;
case V_64 :
V_94 = V_66 ;
break;
case V_68 :
V_94 = V_70 ;
break;
case V_72 :
V_94 = V_74 ;
break;
case V_162 :
return - V_37 ;
default:
F_41 ( L_21 , V_164 ) ;
return - V_37 ;
}
if ( F_33 ( V_97 , V_94 , & V_33 ) || ! V_33 )
return - V_119 ;
return 0 ;
}
static void F_71 ( struct V_11 * V_12 )
{
T_1 V_165 ;
int V_21 ;
if ( ! F_10 ( V_12 , V_101 , false , & V_165 ) ) {
if ( V_165 ) {
F_31 ( L_22 ,
V_12 -> V_3 -> V_2 , V_12 -> V_25 ) ;
V_12 -> V_27 |= V_28 ;
}
}
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ ) {
int V_47 = V_12 -> V_24 [ V_21 ] . V_42 ;
if ( F_10 ( V_12 , V_47 , false , & V_165 ) )
V_12 -> V_24 [ V_21 ] . V_25 = NULL ;
}
}
static int F_72 ( struct V_1 * V_3 , int V_97 )
{
int V_21 ;
int V_39 = 0 ;
struct V_11 * V_12 ;
for ( V_21 = 0 ; V_21 < V_53 ; V_21 ++ ) {
if ( ! F_70 ( V_97 , V_21 ) ) {
V_3 -> V_55 |= 1 << V_21 ;
F_31 ( L_23 , V_56 [ V_21 ] ) ;
}
}
V_3 -> V_148 = F_73 ( & V_3 -> V_55 , V_53 ) ;
if ( ! V_3 -> V_148 ) {
F_20 ( L_24 , V_3 -> V_2 ) ;
V_39 = - V_119 ;
goto V_166;
}
F_20 ( L_25 , V_3 -> V_148 , V_3 -> V_2 ) ;
V_3 -> V_6 = F_74 ( V_3 -> V_148 + 1 , sizeof( struct V_11 ) ,
V_160 ) ;
if ( ! V_3 -> V_6 ) {
V_39 = - V_161 ;
goto V_166;
}
F_29 ( V_3 ) ;
for ( V_12 = V_3 -> V_6 ; V_12 < V_3 -> V_6 + V_3 -> V_148 ; V_12 ++ )
F_71 ( V_12 ) ;
V_166:
return V_39 ;
}
static bool F_75 ( int V_167 )
{
struct V_1 * V_3 ;
F_2 (rp, &rapl_packages, plist)
if ( V_167 == V_3 -> V_2 )
return false ;
return true ;
}
static int F_76 ( void )
{
int V_21 ;
int V_168 ;
struct V_1 * V_169 , * V_3 ;
F_77 (i) {
V_168 = F_78 ( V_21 ) ;
if ( F_75 ( V_168 ) ) {
V_169 = F_66 ( sizeof( * V_3 ) , V_160 ) ;
if ( ! V_169 ) {
F_3 () ;
return - V_161 ;
}
V_169 -> V_2 = V_168 ;
V_169 -> V_170 = 1 ;
V_169 -> V_100 = V_21 ;
if ( F_72 ( V_169 , V_21 ) ||
V_31 -> V_171 ( V_169 , V_21 ) ) {
F_5 ( V_169 -> V_6 ) ;
F_5 ( V_169 ) ;
F_3 () ;
return - V_119 ;
}
F_79 ( & V_169 -> V_7 ) ;
F_80 ( & V_169 -> V_7 , & V_172 ) ;
} else {
V_3 = F_1 ( V_168 ) ;
if ( V_3 )
++ V_3 -> V_170 ;
}
}
return 0 ;
}
static void F_81 ( struct V_1 * V_3 )
{
struct V_11 * V_12 , * V_150 = NULL ;
for ( V_12 = V_3 -> V_6 ; V_12 < V_3 -> V_6 + V_3 -> V_148 ; V_12 ++ ) {
if ( V_12 -> V_2 == V_20 ) {
V_150 = V_12 ;
continue;
}
F_20 ( L_26 , V_3 -> V_2 , V_12 -> V_25 ) ;
F_59 ( V_151 , & V_12 -> V_9 ) ;
}
F_59 ( V_151 , & V_150 -> V_9 ) ;
F_6 ( & V_3 -> V_7 ) ;
F_5 ( V_3 ) ;
}
static int F_82 ( int V_97 )
{
int V_39 = 0 ;
int V_168 ;
struct V_1 * V_3 ;
V_168 = F_78 ( V_97 ) ;
V_3 = F_66 ( sizeof( struct V_1 ) , V_160 ) ;
if ( ! V_3 )
return - V_161 ;
V_3 -> V_2 = V_168 ;
V_3 -> V_170 = 1 ;
V_3 -> V_100 = V_97 ;
if ( F_72 ( V_3 , V_97 ) ||
V_31 -> V_171 ( V_3 , V_97 ) ) {
V_39 = - V_119 ;
goto V_173;
}
if ( ! F_61 ( V_3 ) ) {
F_79 ( & V_3 -> V_7 ) ;
F_80 ( & V_3 -> V_7 , & V_172 ) ;
return V_39 ;
}
V_173:
F_5 ( V_3 -> V_6 ) ;
F_5 ( V_3 ) ;
return V_39 ;
}
static int F_83 ( struct V_174 * V_175 ,
unsigned long V_176 , void * V_177 )
{
unsigned long V_97 = ( unsigned long ) V_177 ;
int V_168 ;
struct V_1 * V_3 ;
int V_100 ;
V_168 = F_78 ( V_97 ) ;
switch ( V_176 ) {
case V_178 :
case V_179 :
case V_180 :
case V_181 :
V_3 = F_1 ( V_168 ) ;
if ( V_3 )
++ V_3 -> V_170 ;
else
F_82 ( V_97 ) ;
break;
case V_182 :
case V_183 :
V_3 = F_1 ( V_168 ) ;
if ( ! V_3 )
break;
if ( -- V_3 -> V_170 == 0 )
F_81 ( V_3 ) ;
else if ( V_97 == V_3 -> V_100 ) {
V_100 = F_84 ( F_85 ( V_97 ) , V_97 ) ;
if ( V_100 < V_184 )
V_3 -> V_100 = V_100 ;
else
F_41 ( L_27 ,
V_168 ) ;
}
}
return V_185 ;
}
static int T_3 F_86 ( void )
{
int V_39 = 0 ;
const struct V_186 * V_2 ;
V_2 = F_87 ( V_187 ) ;
if ( ! V_2 ) {
F_41 ( L_28 ,
V_188 . V_189 , V_188 . V_190 ) ;
return - V_119 ;
}
V_31 = (struct V_31 * ) V_2 -> V_191 ;
F_88 () ;
F_8 () ;
V_39 = F_76 () ;
if ( V_39 )
goto V_166;
if ( F_67 () ) {
F_3 () ;
V_39 = - V_119 ;
goto V_166;
}
F_89 ( & V_192 ) ;
V_166:
F_11 () ;
F_90 () ;
return V_39 ;
}
static void T_4 F_91 ( void )
{
F_88 () ;
F_8 () ;
F_92 ( & V_192 ) ;
F_58 () ;
F_3 () ;
F_11 () ;
F_90 () ;
}
