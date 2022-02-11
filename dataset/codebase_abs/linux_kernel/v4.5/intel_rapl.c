static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
F_2 (rp, &rapl_packages, plist) {
if ( V_3 -> V_2 == V_2 )
return V_3 ;
}
return NULL ;
}
static int F_3 ( int V_4 )
{
int V_5 ;
F_4 (i) {
if ( F_5 ( V_5 ) == V_4 )
return V_5 ;
}
return - V_6 ;
}
static void F_6 ( void )
{
struct V_1 * V_7 , * V_8 ;
F_7 (p, tmp, &rapl_packages, plist) {
F_8 ( V_7 -> V_9 ) ;
F_9 ( & V_7 -> V_10 ) ;
F_8 ( V_7 ) ;
}
}
static int F_10 ( struct V_11 * V_12 , T_1 * V_13 )
{
struct V_14 * V_15 ;
T_1 V_16 ;
F_11 () ;
V_15 = F_12 ( V_12 ) ;
if ( ! F_13 ( V_15 , V_17 , true , & V_16 ) ) {
* V_13 = V_16 ;
F_14 () ;
return 0 ;
}
F_14 () ;
return - V_18 ;
}
static int F_15 ( struct V_11 * V_19 , T_1 * V_20 )
{
struct V_14 * V_15 = F_12 ( V_19 ) ;
* V_20 = F_16 ( V_15 , 0 , V_21 , V_22 , 0 ) ;
return 0 ;
}
static int F_17 ( struct V_11 * V_12 )
{
struct V_14 * V_15 = F_12 ( V_12 ) ;
struct V_1 * V_3 ;
if ( V_15 -> V_2 == V_23 ) {
V_3 = F_1 ( V_15 -> V_4 ) ;
if ( ! V_3 ) {
F_18 ( & V_12 -> V_24 , L_1 ,
V_15 -> V_25 ) ;
return - V_6 ;
}
F_8 ( V_15 ) ;
V_3 -> V_9 = NULL ;
}
return 0 ;
}
static int F_19 ( struct V_14 * V_15 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_26 ; V_5 ++ ) {
if ( V_15 -> V_27 [ V_5 ] . V_25 == NULL )
break;
}
return V_5 ;
}
static int F_20 ( struct V_11 * V_12 , bool V_28 )
{
struct V_14 * V_15 = F_12 ( V_12 ) ;
if ( V_15 -> V_29 & V_30 )
return - V_31 ;
F_11 () ;
F_21 ( V_15 , V_32 , V_28 ) ;
if ( V_33 -> V_34 )
V_33 -> V_34 ( V_15 , V_28 ) ;
F_14 () ;
return 0 ;
}
static int F_22 ( struct V_11 * V_12 , bool * V_28 )
{
struct V_14 * V_15 = F_12 ( V_12 ) ;
T_1 V_35 ;
if ( V_15 -> V_29 & V_30 ) {
* V_28 = false ;
return 0 ;
}
F_11 () ;
if ( F_13 ( V_15 , V_32 , true , & V_35 ) ) {
F_14 () ;
return - V_18 ;
}
* V_28 = V_35 ;
F_14 () ;
return 0 ;
}
static int F_23 ( struct V_11 * V_12 , int V_2 ,
T_1 V_36 )
{
struct V_14 * V_15 ;
struct V_1 * V_3 ;
int V_37 = 0 ;
F_11 () ;
V_15 = F_12 ( V_12 ) ;
V_3 = F_1 ( V_15 -> V_4 ) ;
if ( ! V_3 ) {
V_37 = - V_6 ;
goto V_38;
}
if ( V_15 -> V_29 & V_30 ) {
F_18 ( & V_12 -> V_24 , L_2 ,
V_15 -> V_25 ) ;
V_37 = - V_31 ;
goto V_38;
}
switch ( V_15 -> V_27 [ V_2 ] . V_39 ) {
case V_32 :
F_21 ( V_15 , V_40 , V_36 ) ;
break;
case V_41 :
F_21 ( V_15 , V_42 , V_36 ) ;
break;
default:
V_37 = - V_43 ;
}
if ( ! V_37 )
F_24 ( V_15 -> V_4 ) ;
V_38:
F_14 () ;
return V_37 ;
}
static int F_25 ( struct V_11 * V_12 , int V_2 ,
T_1 * V_44 )
{
struct V_14 * V_15 ;
T_1 V_35 ;
int V_45 ;
int V_37 = 0 ;
F_11 () ;
V_15 = F_12 ( V_12 ) ;
switch ( V_15 -> V_27 [ V_2 ] . V_39 ) {
case V_32 :
V_45 = V_40 ;
break;
case V_41 :
V_45 = V_42 ;
break;
default:
F_14 () ;
return - V_43 ;
}
if ( F_13 ( V_15 , V_45 , true , & V_35 ) )
V_37 = - V_18 ;
else
* V_44 = V_35 ;
F_14 () ;
return V_37 ;
}
static int F_26 ( struct V_11 * V_12 , int V_2 ,
T_1 V_46 )
{
struct V_14 * V_15 ;
int V_37 = 0 ;
F_11 () ;
V_15 = F_12 ( V_12 ) ;
switch ( V_15 -> V_27 [ V_2 ] . V_39 ) {
case V_32 :
F_21 ( V_15 , V_47 , V_46 ) ;
break;
case V_41 :
F_21 ( V_15 , V_48 , V_46 ) ;
break;
default:
V_37 = - V_43 ;
}
F_14 () ;
return V_37 ;
}
static int F_27 ( struct V_11 * V_12 , int V_2 , T_1 * V_44 )
{
struct V_14 * V_15 ;
T_1 V_35 ;
int V_37 = 0 ;
F_11 () ;
V_15 = F_12 ( V_12 ) ;
switch ( V_15 -> V_27 [ V_2 ] . V_39 ) {
case V_32 :
V_37 = F_13 ( V_15 , V_47 , true , & V_35 ) ;
break;
case V_41 :
V_37 = F_13 ( V_15 , V_48 , true , & V_35 ) ;
break;
default:
F_14 () ;
return - V_43 ;
}
if ( ! V_37 )
* V_44 = V_35 ;
F_14 () ;
return V_37 ;
}
static const char * F_28 ( struct V_11 * V_12 , int V_2 )
{
struct V_49 * V_27 ;
struct V_14 * V_15 ;
V_15 = F_12 ( V_12 ) ;
V_27 = (struct V_49 * ) & V_15 -> V_27 [ V_2 ] ;
return V_27 -> V_25 ;
}
static int F_29 ( struct V_11 * V_12 , int V_2 ,
T_1 * V_44 )
{
struct V_14 * V_15 ;
T_1 V_35 ;
int V_45 ;
int V_37 = 0 ;
F_11 () ;
V_15 = F_12 ( V_12 ) ;
switch ( V_15 -> V_27 [ V_2 ] . V_39 ) {
case V_32 :
V_45 = V_50 ;
break;
case V_41 :
V_45 = V_51 ;
break;
default:
F_14 () ;
return - V_43 ;
}
if ( F_13 ( V_15 , V_45 , true , & V_35 ) )
V_37 = - V_18 ;
else
* V_44 = V_35 ;
F_14 () ;
return V_37 ;
}
static void F_30 ( struct V_1 * V_3 )
{
int V_5 ;
struct V_14 * V_15 = V_3 -> V_9 ;
for ( V_5 = 0 ; V_5 < V_52 ; V_5 ++ ) {
unsigned int V_53 = V_3 -> V_54 & ( 1 << V_5 ) ;
switch ( V_53 ) {
case F_31 ( V_23 ) :
V_15 -> V_25 = V_55 [ V_23 ] ;
V_15 -> V_2 = V_23 ;
V_15 -> V_56 [ 0 ] = V_57 ;
V_15 -> V_56 [ 1 ] = V_58 ;
V_15 -> V_56 [ 2 ] = V_59 ;
V_15 -> V_56 [ 3 ] = 0 ;
V_15 -> V_56 [ 4 ] = V_60 ;
V_15 -> V_27 [ 0 ] . V_39 = V_32 ;
V_15 -> V_27 [ 0 ] . V_25 = V_61 ;
V_15 -> V_27 [ 1 ] . V_39 = V_41 ;
V_15 -> V_27 [ 1 ] . V_25 = V_62 ;
break;
case F_31 ( V_63 ) :
V_15 -> V_25 = V_55 [ V_63 ] ;
V_15 -> V_2 = V_63 ;
V_15 -> V_56 [ 0 ] = V_64 ;
V_15 -> V_56 [ 1 ] = V_65 ;
V_15 -> V_56 [ 2 ] = 0 ;
V_15 -> V_56 [ 3 ] = V_66 ;
V_15 -> V_56 [ 4 ] = 0 ;
V_15 -> V_27 [ 0 ] . V_39 = V_32 ;
V_15 -> V_27 [ 0 ] . V_25 = V_61 ;
break;
case F_31 ( V_67 ) :
V_15 -> V_25 = V_55 [ V_67 ] ;
V_15 -> V_2 = V_67 ;
V_15 -> V_56 [ 0 ] = V_68 ;
V_15 -> V_56 [ 1 ] = V_69 ;
V_15 -> V_56 [ 2 ] = 0 ;
V_15 -> V_56 [ 3 ] = V_70 ;
V_15 -> V_56 [ 4 ] = 0 ;
V_15 -> V_27 [ 0 ] . V_39 = V_32 ;
V_15 -> V_27 [ 0 ] . V_25 = V_61 ;
break;
case F_31 ( V_71 ) :
V_15 -> V_25 = V_55 [ V_71 ] ;
V_15 -> V_2 = V_71 ;
V_15 -> V_56 [ 0 ] = V_72 ;
V_15 -> V_56 [ 1 ] = V_73 ;
V_15 -> V_56 [ 2 ] = V_74 ;
V_15 -> V_56 [ 3 ] = 0 ;
V_15 -> V_56 [ 4 ] = V_75 ;
V_15 -> V_27 [ 0 ] . V_39 = V_32 ;
V_15 -> V_27 [ 0 ] . V_25 = V_61 ;
V_15 -> V_76 =
V_33 -> V_77 ;
if ( V_15 -> V_76 )
F_32 ( L_3 ,
V_15 -> V_76 ) ;
break;
}
if ( V_53 ) {
V_15 -> V_4 = V_3 -> V_2 ;
V_15 ++ ;
}
}
}
static T_1 F_16 ( struct V_14 * V_15 , int V_78 ,
enum V_79 type , T_1 V_80 ,
int V_81 )
{
T_1 V_82 = 1 ;
struct V_1 * V_3 ;
T_1 V_83 = 1 ;
V_3 = F_1 ( V_78 ) ;
if ( ! V_3 )
return V_80 ;
switch ( type ) {
case V_84 :
V_82 = V_3 -> V_85 ;
break;
case V_21 :
V_83 = V_86 ;
if ( V_15 && V_15 -> V_76 )
V_82 = V_15 -> V_76 ;
else
V_82 = V_3 -> V_87 ;
break;
case V_88 :
return V_33 -> V_89 ( V_3 , V_80 , V_81 ) ;
case V_90 :
default:
return V_80 ;
} ;
if ( V_81 )
return F_33 ( V_80 , V_82 ) * V_83 ;
V_80 *= V_82 ;
return F_33 ( V_80 , V_83 ) ;
}
static int F_13 ( struct V_14 * V_15 ,
enum V_91 V_45 ,
bool V_92 , T_1 * V_44 )
{
T_1 V_80 , V_93 ;
T_2 V_94 ;
struct V_95 * V_3 = & V_96 [ V_45 ] ;
int V_97 ;
if ( ! V_3 -> V_25 || V_3 -> V_98 & V_99 )
return - V_43 ;
V_94 = V_15 -> V_56 [ V_3 -> V_2 ] ;
if ( ! V_94 )
return - V_43 ;
V_97 = F_3 ( V_15 -> V_4 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( V_45 == V_100 && V_15 -> V_2 == V_23 ) {
V_3 -> V_53 = V_101 ;
V_3 -> V_102 = 63 ;
}
if ( V_3 -> V_98 & V_103 ) {
* V_44 = V_15 -> V_104 . V_105 [ V_45 ] ;
return 0 ;
}
if ( F_34 ( V_97 , V_94 , & V_80 ) ) {
F_35 ( L_4 , V_94 , V_97 ) ;
return - V_18 ;
}
V_93 = V_80 & V_3 -> V_53 ;
V_93 = V_93 >> V_3 -> V_102 ;
if ( V_92 )
* V_44 = F_16 ( V_15 , V_15 -> V_4 , V_3 -> V_106 , V_93 , 0 ) ;
else
* V_44 = V_93 ;
return 0 ;
}
static int F_21 ( struct V_14 * V_15 ,
enum V_91 V_45 ,
unsigned long long V_80 )
{
T_1 V_107 ;
T_2 V_94 ;
struct V_95 * V_3 = & V_96 [ V_45 ] ;
int V_97 ;
V_97 = F_3 ( V_15 -> V_4 ) ;
if ( V_97 < 0 )
return V_97 ;
V_94 = V_15 -> V_56 [ V_3 -> V_2 ] ;
if ( F_34 ( V_97 , V_94 , & V_107 ) ) {
F_36 ( & V_15 -> V_12 . V_24 ,
L_4 , V_94 , V_97 ) ;
return - V_18 ;
}
V_80 = F_16 ( V_15 , V_15 -> V_4 , V_3 -> V_106 , V_80 , 1 ) ;
V_107 &= ~ V_3 -> V_53 ;
V_107 |= V_80 << V_3 -> V_102 ;
if ( F_37 ( V_97 , V_94 , V_107 ) ) {
F_36 ( & V_15 -> V_12 . V_24 ,
L_5 , V_94 , V_97 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_3 , int V_97 )
{
T_1 V_107 ;
T_2 V_80 ;
if ( F_34 ( V_97 , V_108 , & V_107 ) ) {
F_39 ( L_6 ,
V_108 , V_97 ) ;
return - V_6 ;
}
V_80 = ( V_107 & V_109 ) >> V_110 ;
V_3 -> V_87 = V_86 * 1000000 / ( 1 << V_80 ) ;
V_80 = ( V_107 & V_111 ) >> V_112 ;
V_3 -> V_85 = 1000000 / ( 1 << V_80 ) ;
V_80 = ( V_107 & V_113 ) >> V_114 ;
V_3 -> V_115 = 1000000 / ( 1 << V_80 ) ;
F_35 ( L_7 ,
V_3 -> V_2 , V_3 -> V_87 , V_3 -> V_115 , V_3 -> V_85 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_3 , int V_97 )
{
T_1 V_107 ;
T_2 V_80 ;
if ( F_34 ( V_97 , V_108 , & V_107 ) ) {
F_39 ( L_6 ,
V_108 , V_97 ) ;
return - V_6 ;
}
V_80 = ( V_107 & V_109 ) >> V_110 ;
V_3 -> V_87 = V_86 * 1 << V_80 ;
V_80 = ( V_107 & V_111 ) >> V_112 ;
V_3 -> V_85 = ( 1 << V_80 ) * 1000 ;
V_80 = ( V_107 & V_113 ) >> V_114 ;
V_3 -> V_115 = 1000000 / ( 1 << V_80 ) ;
F_35 ( L_8 ,
V_3 -> V_2 , V_3 -> V_87 , V_3 -> V_115 , V_3 -> V_85 ) ;
return 0 ;
}
static void F_24 ( int V_4 )
{
T_2 V_116 , V_117 = 0 ;
int V_97 ;
struct V_1 * V_3 ;
V_3 = F_1 ( V_4 ) ;
if ( ! V_3 )
return;
if ( ! F_41 ( V_118 ) || ! F_41 ( V_119 ) )
return;
V_97 = F_3 ( V_4 ) ;
if ( V_97 < 0 )
return;
F_42 ( V_97 , V_120 , & V_116 , & V_117 ) ;
if ( ! ( V_3 -> V_121 & V_122 ) ) {
V_3 -> V_121 = V_116 & V_123 ;
V_3 -> V_121 |= V_122 ;
}
V_116 &= ~ V_123 ;
F_43 ( V_97 , V_120 , V_116 , V_117 ) ;
}
static void F_44 ( int V_4 )
{
T_2 V_116 , V_117 ;
int V_97 ;
struct V_1 * V_3 ;
V_3 = F_1 ( V_4 ) ;
if ( ! V_3 )
return;
if ( ! F_41 ( V_118 ) || ! F_41 ( V_119 ) )
return;
V_97 = F_3 ( V_4 ) ;
if ( V_97 < 0 )
return;
if ( ! ( V_3 -> V_121 & V_122 ) )
return;
F_42 ( V_97 , V_120 , & V_116 , & V_117 ) ;
if ( V_3 -> V_121 & V_123 )
V_116 |= V_123 ;
else
V_116 &= ~ V_123 ;
F_43 ( V_97 , V_120 , V_116 , V_117 ) ;
}
static void F_45 ( struct V_14 * V_15 , bool V_28 )
{
int V_124 = F_19 ( V_15 ) ;
F_21 ( V_15 , V_125 , V_28 ) ;
if ( V_124 > 1 ) {
F_21 ( V_15 , V_41 , V_28 ) ;
F_21 ( V_15 , V_126 , V_28 ) ;
}
}
static void F_46 ( struct V_14 * V_15 , bool V_127 )
{
static T_2 V_128 ;
T_2 V_129 ;
if ( ! V_33 -> V_130 ) {
F_39 ( L_9 ) ;
return;
}
if ( ! V_128 )
F_47 ( V_131 , V_132 ,
V_33 -> V_130 ,
& V_128 ) ;
V_129 = V_128 ;
if ( V_127 ) {
V_129 &= ~ ( 0x7f << 8 ) ;
V_129 |= 1 << 8 ;
}
F_48 ( V_131 , V_133 ,
V_33 -> V_130 , V_129 ) ;
}
static T_1 F_49 ( struct V_1 * V_3 , T_1 V_80 ,
bool V_81 )
{
T_1 V_134 , V_135 ;
if ( ! V_81 ) {
V_134 = ( V_80 & 0x60 ) >> 5 ;
V_135 = V_80 & 0x1f ;
V_80 = ( 1 << V_135 ) * ( 4 + V_134 ) * V_3 -> V_115 / 4 ;
} else {
F_50 ( V_80 , V_3 -> V_115 ) ;
V_135 = F_51 ( V_80 ) ;
V_134 = F_33 ( 4 * ( V_80 - ( 1 << V_135 ) ) , 1 << V_135 ) ;
V_80 = ( V_135 & 0x1f ) | ( ( V_134 & 0x3 ) << 5 ) ;
}
return V_80 ;
}
static T_1 F_52 ( struct V_1 * V_3 , T_1 V_80 ,
bool V_81 )
{
if ( ! V_81 )
return ( V_80 ) ? V_80 *= V_3 -> V_115 : V_3 -> V_115 ;
else
V_80 = F_33 ( V_80 , V_3 -> V_115 ) ;
return V_80 ;
}
static void F_53 ( void )
{
int V_136 , V_45 ;
T_1 V_35 ;
struct V_1 * V_3 ;
F_2 (rp, &rapl_packages, plist) {
for ( V_136 = 0 ; V_136 < V_3 -> V_137 ; V_136 ++ ) {
F_35 ( L_10 , V_3 -> V_2 ,
V_3 -> V_9 [ V_136 ] . V_25 ) ;
for ( V_45 = 0 ; V_45 < V_138 ; V_45 ++ )
if ( ! F_13 ( & V_3 -> V_9 [ V_136 ] , V_45 ,
V_96 [ V_45 ] . V_106 ,
& V_35 ) )
V_3 -> V_9 [ V_136 ] . V_104 . V_105 [ V_45 ] =
V_35 ;
}
}
}
static int F_54 ( void )
{
struct V_1 * V_3 ;
struct V_14 * V_15 , * V_139 = NULL ;
F_2 (rp, &rapl_packages, plist) {
F_44 ( V_3 -> V_2 ) ;
for ( V_15 = V_3 -> V_9 ; V_15 < V_3 -> V_9 + V_3 -> V_137 ;
V_15 ++ ) {
F_35 ( L_11 ,
V_3 -> V_2 , V_15 -> V_25 ) ;
F_21 ( V_15 , V_32 , 0 ) ;
F_21 ( V_15 , V_125 , 0 ) ;
if ( F_19 ( V_15 ) > 1 ) {
F_21 ( V_15 , V_41 , 0 ) ;
F_21 ( V_15 , V_126 , 0 ) ;
}
if ( V_15 -> V_2 == V_23 ) {
V_139 = V_15 ;
continue;
}
F_55 ( V_140 , & V_15 -> V_12 ) ;
}
if ( V_139 )
F_55 ( V_140 ,
& V_139 -> V_12 ) ;
}
F_56 ( V_140 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_3 )
{
struct V_14 * V_15 ;
int V_37 = 0 ;
char V_141 [ 17 ] ;
struct V_11 * V_12 = NULL ;
int V_142 ;
for ( V_15 = V_3 -> V_9 ; V_15 < V_3 -> V_9 + V_3 -> V_137 ; V_15 ++ ) {
if ( V_15 -> V_2 == V_23 ) {
V_142 = F_19 ( V_15 ) ;
F_35 ( L_12 ,
V_3 -> V_2 , V_15 -> V_25 ) ;
memset ( V_141 , 0 , sizeof( V_141 ) ) ;
snprintf ( V_141 , sizeof( V_141 ) , L_13 ,
V_15 -> V_25 , V_3 -> V_2 ) ;
V_12 = F_58 ( & V_15 -> V_12 ,
V_140 ,
V_141 , NULL ,
& V_143 [ V_15 -> V_2 ] ,
V_142 ,
& V_144 ) ;
if ( F_59 ( V_12 ) ) {
F_35 ( L_14 ,
V_3 -> V_2 ) ;
V_37 = F_60 ( V_12 ) ;
goto V_145;
}
V_3 -> V_12 = V_12 ;
break;
}
}
if ( ! V_12 ) {
F_39 ( L_15 ) ;
V_37 = - V_6 ;
goto V_145;
}
for ( V_15 = V_3 -> V_9 ; V_15 < V_3 -> V_9 + V_3 -> V_137 ; V_15 ++ ) {
if ( V_15 -> V_2 == V_23 )
continue;
V_142 = F_19 ( V_15 ) ;
V_12 = F_58 ( & V_15 -> V_12 ,
V_140 , V_15 -> V_25 ,
V_3 -> V_12 ,
& V_143 [ V_15 -> V_2 ] , V_142 ,
& V_144 ) ;
if ( F_59 ( V_12 ) ) {
F_35 ( L_16 ,
V_3 -> V_2 , V_15 -> V_25 , V_141 ) ;
V_37 = F_60 ( V_12 ) ;
goto V_146;
}
}
V_145:
return V_37 ;
V_146:
while ( -- V_15 >= V_3 -> V_9 ) {
F_35 ( L_17 , V_3 -> V_2 , V_15 -> V_25 ) ;
F_55 ( V_140 , & V_15 -> V_12 ) ;
}
return V_37 ;
}
static int F_61 ( void )
{
struct V_14 * V_15 ;
struct V_1 * V_3 ;
int V_37 = 0 ;
V_140 = F_62 ( NULL , L_18 , NULL ) ;
if ( F_59 ( V_140 ) ) {
F_35 ( L_19 ) ;
return F_60 ( V_140 ) ;
}
F_53 () ;
F_2 (rp, &rapl_packages, plist)
if ( F_57 ( V_3 ) )
goto V_147;
return V_37 ;
V_147:
F_63 (rp, &rapl_packages, plist) {
for ( V_15 = V_3 -> V_9 ; V_15 < V_3 -> V_9 + V_3 -> V_137 ;
V_15 ++ ) {
F_35 ( L_20 ,
V_3 -> V_2 , V_15 -> V_25 ) ;
F_55 ( V_140 , & V_15 -> V_12 ) ;
}
}
return V_37 ;
}
static int F_64 ( int V_97 , int V_148 )
{
unsigned V_94 ;
T_1 V_35 = 0 ;
switch ( V_148 ) {
case V_23 :
V_94 = V_58 ;
break;
case V_63 :
V_94 = V_65 ;
break;
case V_67 :
V_94 = V_69 ;
break;
case V_71 :
V_94 = V_73 ;
break;
default:
F_39 ( L_21 , V_148 ) ;
return - V_43 ;
}
if ( F_34 ( V_97 , V_94 , & V_35 ) || ! V_35 )
return - V_6 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_3 , int V_97 )
{
int V_5 ;
int V_37 = 0 ;
struct V_14 * V_15 ;
T_1 V_149 ;
for ( V_5 = 0 ; V_5 < V_52 ; V_5 ++ ) {
if ( ! F_64 ( V_97 , V_5 ) ) {
V_3 -> V_54 |= 1 << V_5 ;
F_32 ( L_22 , V_55 [ V_5 ] ) ;
}
}
V_3 -> V_137 = F_66 ( & V_3 -> V_54 , V_52 ) ;
if ( ! V_3 -> V_137 ) {
F_39 ( L_23 , V_3 -> V_2 ) ;
V_37 = - V_6 ;
goto V_150;
}
F_35 ( L_24 , V_3 -> V_137 , V_3 -> V_2 ) ;
V_3 -> V_9 = F_67 ( V_3 -> V_137 + 1 , sizeof( struct V_14 ) ,
V_151 ) ;
if ( ! V_3 -> V_9 ) {
V_37 = - V_152 ;
goto V_150;
}
F_30 ( V_3 ) ;
for ( V_15 = V_3 -> V_9 ; V_15 < V_3 -> V_9 + V_3 -> V_137 ; V_15 ++ ) {
V_37 = F_13 ( V_15 , V_100 , false , & V_149 ) ;
if ( V_37 )
return V_37 ;
if ( V_149 ) {
F_32 ( L_25 ,
V_3 -> V_2 , V_15 -> V_25 ) ;
V_15 -> V_29 |= V_30 ;
}
}
V_150:
return V_37 ;
}
static bool F_68 ( int V_78 )
{
struct V_1 * V_3 ;
F_2 (rp, &rapl_packages, plist)
if ( V_78 == V_3 -> V_2 )
return false ;
return true ;
}
static int F_69 ( void )
{
int V_5 ;
int V_153 ;
struct V_1 * V_154 , * V_3 ;
F_4 (i) {
V_153 = F_5 ( V_5 ) ;
if ( F_68 ( V_153 ) ) {
V_154 = F_70 ( sizeof( * V_3 ) , V_151 ) ;
if ( ! V_154 ) {
F_6 () ;
return - V_152 ;
}
V_154 -> V_2 = V_153 ;
V_154 -> V_155 = 1 ;
if ( F_65 ( V_154 , V_5 ) ||
V_33 -> V_156 ( V_154 , V_5 ) ) {
F_8 ( V_154 -> V_9 ) ;
F_8 ( V_154 ) ;
F_6 () ;
return - V_6 ;
}
F_71 ( & V_154 -> V_10 ) ;
F_72 ( & V_154 -> V_10 , & V_157 ) ;
} else {
V_3 = F_1 ( V_153 ) ;
if ( V_3 )
++ V_3 -> V_155 ;
}
}
return 0 ;
}
static void F_73 ( struct V_1 * V_3 )
{
struct V_14 * V_15 , * V_139 = NULL ;
for ( V_15 = V_3 -> V_9 ; V_15 < V_3 -> V_9 + V_3 -> V_137 ; V_15 ++ ) {
if ( V_15 -> V_2 == V_23 ) {
V_139 = V_15 ;
continue;
}
F_35 ( L_26 , V_3 -> V_2 , V_15 -> V_25 ) ;
F_55 ( V_140 , & V_15 -> V_12 ) ;
}
F_55 ( V_140 , & V_139 -> V_12 ) ;
F_9 ( & V_3 -> V_10 ) ;
F_8 ( V_3 ) ;
}
static int F_74 ( int V_97 )
{
int V_37 = 0 ;
int V_153 ;
struct V_1 * V_3 ;
V_153 = F_5 ( V_97 ) ;
V_3 = F_70 ( sizeof( struct V_1 ) , V_151 ) ;
if ( ! V_3 )
return - V_152 ;
V_3 -> V_2 = V_153 ;
V_3 -> V_155 = 1 ;
if ( F_65 ( V_3 , V_97 ) ||
V_33 -> V_156 ( V_3 , V_97 ) ) {
V_37 = - V_6 ;
goto V_158;
}
if ( ! F_57 ( V_3 ) ) {
F_71 ( & V_3 -> V_10 ) ;
F_72 ( & V_3 -> V_10 , & V_157 ) ;
return V_37 ;
}
V_158:
F_8 ( V_3 -> V_9 ) ;
F_8 ( V_3 ) ;
return V_37 ;
}
static int F_75 ( struct V_159 * V_160 ,
unsigned long V_161 , void * V_162 )
{
unsigned long V_97 = ( unsigned long ) V_162 ;
int V_153 ;
struct V_1 * V_3 ;
V_153 = F_5 ( V_97 ) ;
switch ( V_161 ) {
case V_163 :
case V_164 :
case V_165 :
case V_166 :
V_3 = F_1 ( V_153 ) ;
if ( V_3 )
++ V_3 -> V_155 ;
else
F_74 ( V_97 ) ;
break;
case V_167 :
case V_168 :
V_3 = F_1 ( V_153 ) ;
if ( ! V_3 )
break;
if ( -- V_3 -> V_155 == 0 )
F_73 ( V_3 ) ;
}
return V_169 ;
}
static int T_3 F_76 ( void )
{
int V_37 = 0 ;
const struct V_170 * V_2 ;
V_2 = F_77 ( V_171 ) ;
if ( ! V_2 ) {
F_39 ( L_27 ,
V_172 . V_173 , V_172 . V_174 ) ;
return - V_6 ;
}
V_33 = (struct V_33 * ) V_2 -> V_175 ;
F_78 () ;
F_11 () ;
V_37 = F_69 () ;
if ( V_37 )
goto V_150;
if ( F_61 () ) {
F_6 () ;
V_37 = - V_6 ;
goto V_150;
}
F_79 ( & V_176 ) ;
V_150:
F_14 () ;
F_80 () ;
return V_37 ;
}
static void T_4 F_81 ( void )
{
F_78 () ;
F_11 () ;
F_82 ( & V_176 ) ;
F_54 () ;
F_6 () ;
F_14 () ;
F_80 () ;
}
