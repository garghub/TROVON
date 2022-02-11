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
* V_20 = F_16 ( 0 , V_21 , V_22 , 0 ) ;
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
break;
}
if ( V_53 ) {
V_15 -> V_4 = V_3 -> V_2 ;
V_15 ++ ;
}
}
}
static T_1 F_16 ( int V_76 , enum V_77 type , T_1 V_78 ,
int V_79 )
{
T_1 V_80 = 1 ;
struct V_1 * V_3 ;
V_3 = F_1 ( V_76 ) ;
if ( ! V_3 )
return V_78 ;
switch ( type ) {
case V_81 :
V_80 = V_3 -> V_82 ;
break;
case V_21 :
V_80 = V_3 -> V_83 ;
break;
case V_84 :
return V_33 -> V_85 ( V_3 , V_78 , V_79 ) ;
case V_86 :
default:
return V_78 ;
} ;
if ( V_79 )
return F_32 ( V_78 , V_80 ) ;
V_78 *= V_80 ;
return V_78 ;
}
static int F_13 ( struct V_14 * V_15 ,
enum V_87 V_45 ,
bool V_88 , T_1 * V_44 )
{
T_1 V_78 , V_89 ;
T_2 V_90 ;
struct V_91 * V_3 = & V_92 [ V_45 ] ;
int V_93 ;
if ( ! V_3 -> V_25 || V_3 -> V_94 & V_95 )
return - V_43 ;
V_90 = V_15 -> V_56 [ V_3 -> V_2 ] ;
if ( ! V_90 )
return - V_43 ;
V_93 = F_3 ( V_15 -> V_4 ) ;
if ( V_93 < 0 )
return V_93 ;
if ( V_45 == V_96 && V_15 -> V_2 == V_23 ) {
V_3 -> V_53 = V_97 ;
V_3 -> V_98 = 63 ;
}
if ( V_3 -> V_94 & V_99 ) {
* V_44 = V_15 -> V_100 . V_101 [ V_45 ] ;
return 0 ;
}
if ( F_33 ( V_93 , V_90 , & V_78 ) ) {
F_34 ( L_3 , V_90 , V_93 ) ;
return - V_18 ;
}
V_89 = V_78 & V_3 -> V_53 ;
V_89 = V_89 >> V_3 -> V_98 ;
if ( V_88 )
* V_44 = F_16 ( V_15 -> V_4 , V_3 -> V_102 , V_89 , 0 ) ;
else
* V_44 = V_89 ;
return 0 ;
}
static int F_21 ( struct V_14 * V_15 ,
enum V_87 V_45 ,
unsigned long long V_78 )
{
T_1 V_103 ;
T_2 V_90 ;
struct V_91 * V_3 = & V_92 [ V_45 ] ;
int V_93 ;
V_93 = F_3 ( V_15 -> V_4 ) ;
if ( V_93 < 0 )
return V_93 ;
V_90 = V_15 -> V_56 [ V_3 -> V_2 ] ;
if ( F_33 ( V_93 , V_90 , & V_103 ) ) {
F_35 ( & V_15 -> V_12 . V_24 ,
L_3 , V_90 , V_93 ) ;
return - V_18 ;
}
V_78 = F_16 ( V_15 -> V_4 , V_3 -> V_102 , V_78 , 1 ) ;
V_103 &= ~ V_3 -> V_53 ;
V_103 |= V_78 << V_3 -> V_98 ;
if ( F_36 ( V_93 , V_90 , V_103 ) ) {
F_35 ( & V_15 -> V_12 . V_24 ,
L_4 , V_90 , V_93 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_3 , int V_93 )
{
T_1 V_103 ;
T_2 V_78 ;
if ( F_33 ( V_93 , V_104 , & V_103 ) ) {
F_38 ( L_5 ,
V_104 , V_93 ) ;
return - V_6 ;
}
V_78 = ( V_103 & V_105 ) >> V_106 ;
V_3 -> V_83 = 1000000 / ( 1 << V_78 ) ;
V_78 = ( V_103 & V_107 ) >> V_108 ;
V_3 -> V_82 = 1000000 / ( 1 << V_78 ) ;
V_78 = ( V_103 & V_109 ) >> V_110 ;
V_3 -> V_111 = 1000000 / ( 1 << V_78 ) ;
F_34 ( L_6 ,
V_3 -> V_2 , V_3 -> V_83 , V_3 -> V_111 , V_3 -> V_82 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_3 , int V_93 )
{
T_1 V_103 ;
T_2 V_78 ;
if ( F_33 ( V_93 , V_104 , & V_103 ) ) {
F_38 ( L_5 ,
V_104 , V_93 ) ;
return - V_6 ;
}
V_78 = ( V_103 & V_105 ) >> V_106 ;
V_3 -> V_83 = 1 << V_78 ;
V_78 = ( V_103 & V_107 ) >> V_108 ;
V_3 -> V_82 = ( 1 << V_78 ) * 1000 ;
V_78 = ( V_103 & V_109 ) >> V_110 ;
V_3 -> V_111 = 1000000 / ( 1 << V_78 ) ;
F_34 ( L_7 ,
V_3 -> V_2 , V_3 -> V_83 , V_3 -> V_111 , V_3 -> V_82 ) ;
return 0 ;
}
static void F_24 ( int V_4 )
{
T_2 V_112 , V_113 = 0 ;
int V_93 ;
struct V_1 * V_3 ;
V_3 = F_1 ( V_4 ) ;
if ( ! V_3 )
return;
if ( ! F_40 ( V_114 ) || ! F_40 ( V_115 ) )
return;
V_93 = F_3 ( V_4 ) ;
if ( V_93 < 0 )
return;
F_41 ( V_93 , V_116 , & V_112 , & V_113 ) ;
if ( ! ( V_3 -> V_117 & V_118 ) ) {
V_3 -> V_117 = V_112 & V_119 ;
V_3 -> V_117 |= V_118 ;
}
V_112 &= ~ V_119 ;
F_42 ( V_93 , V_116 , V_112 , V_113 ) ;
}
static void F_43 ( int V_4 )
{
T_2 V_112 , V_113 ;
int V_93 ;
struct V_1 * V_3 ;
V_3 = F_1 ( V_4 ) ;
if ( ! V_3 )
return;
if ( ! F_40 ( V_114 ) || ! F_40 ( V_115 ) )
return;
V_93 = F_3 ( V_4 ) ;
if ( V_93 < 0 )
return;
if ( ! ( V_3 -> V_117 & V_118 ) )
return;
F_41 ( V_93 , V_116 , & V_112 , & V_113 ) ;
if ( V_3 -> V_117 & V_119 )
V_112 |= V_119 ;
else
V_112 &= ~ V_119 ;
F_42 ( V_93 , V_116 , V_112 , V_113 ) ;
}
static void F_44 ( struct V_14 * V_15 , bool V_28 )
{
int V_120 = F_19 ( V_15 ) ;
F_21 ( V_15 , V_121 , V_28 ) ;
if ( V_120 > 1 ) {
F_21 ( V_15 , V_41 , V_28 ) ;
F_21 ( V_15 , V_122 , V_28 ) ;
}
}
static void F_45 ( struct V_14 * V_15 , bool V_123 )
{
static T_2 V_124 ;
T_2 V_125 ;
if ( ! V_124 )
F_46 ( V_126 , V_127 ,
V_128 , & V_124 ) ;
V_125 = V_124 ;
if ( V_123 ) {
V_125 &= ~ ( 0x7f << 8 ) ;
V_125 |= 1 << 8 ;
}
F_47 ( V_126 , V_129 ,
V_128 , V_125 ) ;
}
static T_1 F_48 ( struct V_1 * V_3 , T_1 V_78 ,
bool V_79 )
{
T_1 V_130 , V_131 ;
if ( ! V_79 ) {
V_130 = ( V_78 & 0x60 ) >> 5 ;
V_131 = V_78 & 0x1f ;
V_78 = ( 1 << V_131 ) * ( 4 + V_130 ) * V_3 -> V_111 / 4 ;
} else {
F_49 ( V_78 , V_3 -> V_111 ) ;
V_131 = F_50 ( V_78 ) ;
V_130 = F_32 ( 4 * ( V_78 - ( 1 << V_131 ) ) , 1 << V_131 ) ;
V_78 = ( V_131 & 0x1f ) | ( ( V_130 & 0x3 ) << 5 ) ;
}
return V_78 ;
}
static T_1 F_51 ( struct V_1 * V_3 , T_1 V_78 ,
bool V_79 )
{
if ( ! V_79 )
return ( V_78 ) ? V_78 *= V_3 -> V_111 : V_3 -> V_111 ;
else
V_78 = F_32 ( V_78 , V_3 -> V_111 ) ;
return V_78 ;
}
static void F_52 ( void )
{
int V_132 , V_45 ;
T_1 V_35 ;
struct V_1 * V_3 ;
F_2 (rp, &rapl_packages, plist) {
for ( V_132 = 0 ; V_132 < V_3 -> V_133 ; V_132 ++ ) {
F_34 ( L_8 , V_3 -> V_2 ,
V_3 -> V_9 [ V_132 ] . V_25 ) ;
for ( V_45 = 0 ; V_45 < V_134 ; V_45 ++ )
if ( ! F_13 ( & V_3 -> V_9 [ V_132 ] , V_45 ,
V_92 [ V_45 ] . V_102 ,
& V_35 ) )
V_3 -> V_9 [ V_132 ] . V_100 . V_101 [ V_45 ] =
V_35 ;
}
}
}
static int F_53 ( void )
{
struct V_1 * V_3 ;
struct V_14 * V_15 , * V_135 = NULL ;
F_2 (rp, &rapl_packages, plist) {
F_43 ( V_3 -> V_2 ) ;
for ( V_15 = V_3 -> V_9 ; V_15 < V_3 -> V_9 + V_3 -> V_133 ;
V_15 ++ ) {
F_34 ( L_9 ,
V_3 -> V_2 , V_15 -> V_25 ) ;
F_21 ( V_15 , V_32 , 0 ) ;
F_21 ( V_15 , V_41 , 0 ) ;
F_21 ( V_15 , V_121 , 0 ) ;
F_21 ( V_15 , V_122 , 0 ) ;
if ( V_15 -> V_2 == V_23 ) {
V_135 = V_15 ;
continue;
}
F_54 ( V_136 , & V_15 -> V_12 ) ;
}
if ( V_135 )
F_54 ( V_136 ,
& V_135 -> V_12 ) ;
}
F_55 ( V_136 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_3 )
{
struct V_14 * V_15 ;
int V_37 = 0 ;
char V_137 [ 17 ] ;
struct V_11 * V_12 = NULL ;
int V_138 ;
for ( V_15 = V_3 -> V_9 ; V_15 < V_3 -> V_9 + V_3 -> V_133 ; V_15 ++ ) {
if ( V_15 -> V_2 == V_23 ) {
V_138 = F_19 ( V_15 ) ;
F_34 ( L_10 ,
V_3 -> V_2 , V_15 -> V_25 ) ;
memset ( V_137 , 0 , sizeof( V_137 ) ) ;
snprintf ( V_137 , sizeof( V_137 ) , L_11 ,
V_15 -> V_25 , V_3 -> V_2 ) ;
V_12 = F_57 ( & V_15 -> V_12 ,
V_136 ,
V_137 , NULL ,
& V_139 [ V_15 -> V_2 ] ,
V_138 ,
& V_140 ) ;
if ( F_58 ( V_12 ) ) {
F_34 ( L_12 ,
V_3 -> V_2 ) ;
V_37 = F_59 ( V_12 ) ;
goto V_141;
}
V_3 -> V_12 = V_12 ;
break;
}
}
if ( ! V_12 ) {
F_38 ( L_13 ) ;
V_37 = - V_6 ;
goto V_141;
}
for ( V_15 = V_3 -> V_9 ; V_15 < V_3 -> V_9 + V_3 -> V_133 ; V_15 ++ ) {
if ( V_15 -> V_2 == V_23 )
continue;
V_138 = F_19 ( V_15 ) ;
V_12 = F_57 ( & V_15 -> V_12 ,
V_136 , V_15 -> V_25 ,
V_3 -> V_12 ,
& V_139 [ V_15 -> V_2 ] , V_138 ,
& V_140 ) ;
if ( F_58 ( V_12 ) ) {
F_34 ( L_14 ,
V_3 -> V_2 , V_15 -> V_25 , V_137 ) ;
V_37 = F_59 ( V_12 ) ;
goto V_142;
}
}
V_141:
return V_37 ;
V_142:
while ( -- V_15 >= V_3 -> V_9 ) {
F_34 ( L_15 , V_3 -> V_2 , V_15 -> V_25 ) ;
F_54 ( V_136 , & V_15 -> V_12 ) ;
}
return V_37 ;
}
static int F_60 ( void )
{
struct V_14 * V_15 ;
struct V_1 * V_3 ;
int V_37 = 0 ;
V_136 = F_61 ( NULL , L_16 , NULL ) ;
if ( F_58 ( V_136 ) ) {
F_34 ( L_17 ) ;
return F_59 ( V_136 ) ;
}
F_52 () ;
F_2 (rp, &rapl_packages, plist)
if ( F_56 ( V_3 ) )
goto V_143;
return V_37 ;
V_143:
F_62 (rp, &rapl_packages, plist) {
for ( V_15 = V_3 -> V_9 ; V_15 < V_3 -> V_9 + V_3 -> V_133 ;
V_15 ++ ) {
F_34 ( L_18 ,
V_3 -> V_2 , V_15 -> V_25 ) ;
F_54 ( V_136 , & V_15 -> V_12 ) ;
}
}
return V_37 ;
}
static int F_63 ( int V_93 , int V_144 )
{
unsigned V_90 ;
T_1 V_35 = 0 ;
switch ( V_144 ) {
case V_23 :
V_90 = V_58 ;
break;
case V_63 :
V_90 = V_65 ;
break;
case V_67 :
V_90 = V_69 ;
break;
case V_71 :
V_90 = V_73 ;
break;
default:
F_38 ( L_19 , V_144 ) ;
return - V_43 ;
}
if ( F_33 ( V_93 , V_90 , & V_35 ) || ! V_35 )
return - V_6 ;
return 0 ;
}
static int F_64 ( struct V_1 * V_3 , int V_93 )
{
int V_5 ;
int V_37 = 0 ;
struct V_14 * V_15 ;
T_1 V_145 ;
for ( V_5 = 0 ; V_5 < V_52 ; V_5 ++ ) {
if ( ! F_63 ( V_93 , V_5 ) ) {
V_3 -> V_54 |= 1 << V_5 ;
F_65 ( L_20 , V_55 [ V_5 ] ) ;
}
}
V_3 -> V_133 = F_66 ( & V_3 -> V_54 , V_52 ) ;
if ( ! V_3 -> V_133 ) {
F_38 ( L_21 , V_3 -> V_2 ) ;
V_37 = - V_6 ;
goto V_146;
}
F_34 ( L_22 , V_3 -> V_133 , V_3 -> V_2 ) ;
V_3 -> V_9 = F_67 ( V_3 -> V_133 + 1 , sizeof( struct V_14 ) ,
V_147 ) ;
if ( ! V_3 -> V_9 ) {
V_37 = - V_148 ;
goto V_146;
}
F_30 ( V_3 ) ;
for ( V_15 = V_3 -> V_9 ; V_15 < V_3 -> V_9 + V_3 -> V_133 ; V_15 ++ ) {
if ( F_13 ( V_15 , V_96 , false , & V_145 ) ) {
F_65 ( L_23 ,
V_3 -> V_2 , V_15 -> V_25 ) ;
V_15 -> V_29 |= V_30 ;
}
}
V_146:
return V_37 ;
}
static bool F_68 ( int V_76 )
{
struct V_1 * V_3 ;
F_2 (rp, &rapl_packages, plist)
if ( V_76 == V_3 -> V_2 )
return false ;
return true ;
}
static int F_69 ( void )
{
int V_5 ;
int V_149 ;
struct V_1 * V_150 , * V_3 ;
F_4 (i) {
V_149 = F_5 ( V_5 ) ;
if ( F_68 ( V_149 ) ) {
V_150 = F_70 ( sizeof( * V_3 ) , V_147 ) ;
if ( ! V_150 ) {
F_6 () ;
return - V_148 ;
}
V_150 -> V_2 = V_149 ;
V_150 -> V_151 = 1 ;
if ( F_64 ( V_150 , V_5 ) ||
V_33 -> V_152 ( V_150 , V_5 ) ) {
F_8 ( V_150 -> V_9 ) ;
F_8 ( V_150 ) ;
F_6 () ;
return - V_6 ;
}
F_71 ( & V_150 -> V_10 ) ;
F_72 ( & V_150 -> V_10 , & V_153 ) ;
} else {
V_3 = F_1 ( V_149 ) ;
if ( V_3 )
++ V_3 -> V_151 ;
}
}
return 0 ;
}
static void F_73 ( struct V_1 * V_3 )
{
struct V_14 * V_15 , * V_135 = NULL ;
for ( V_15 = V_3 -> V_9 ; V_15 < V_3 -> V_9 + V_3 -> V_133 ; V_15 ++ ) {
if ( V_15 -> V_2 == V_23 ) {
V_135 = V_15 ;
continue;
}
F_34 ( L_24 , V_3 -> V_2 , V_15 -> V_25 ) ;
F_54 ( V_136 , & V_15 -> V_12 ) ;
}
F_54 ( V_136 , & V_135 -> V_12 ) ;
F_9 ( & V_3 -> V_10 ) ;
F_8 ( V_3 ) ;
}
static int F_74 ( int V_93 )
{
int V_37 = 0 ;
int V_149 ;
struct V_1 * V_3 ;
V_149 = F_5 ( V_93 ) ;
V_3 = F_70 ( sizeof( struct V_1 ) , V_147 ) ;
if ( ! V_3 )
return - V_148 ;
V_3 -> V_2 = V_149 ;
V_3 -> V_151 = 1 ;
if ( F_64 ( V_3 , V_93 ) ||
V_33 -> V_152 ( V_3 , V_93 ) ) {
V_37 = - V_6 ;
goto V_154;
}
if ( ! F_56 ( V_3 ) ) {
F_71 ( & V_3 -> V_10 ) ;
F_72 ( & V_3 -> V_10 , & V_153 ) ;
return V_37 ;
}
V_154:
F_8 ( V_3 -> V_9 ) ;
F_8 ( V_3 ) ;
return V_37 ;
}
static int F_75 ( struct V_155 * V_156 ,
unsigned long V_157 , void * V_158 )
{
unsigned long V_93 = ( unsigned long ) V_158 ;
int V_149 ;
struct V_1 * V_3 ;
V_149 = F_5 ( V_93 ) ;
switch ( V_157 ) {
case V_159 :
case V_160 :
case V_161 :
case V_162 :
V_3 = F_1 ( V_149 ) ;
if ( V_3 )
++ V_3 -> V_151 ;
else
F_74 ( V_93 ) ;
break;
case V_163 :
case V_164 :
V_3 = F_1 ( V_149 ) ;
if ( ! V_3 )
break;
if ( -- V_3 -> V_151 == 0 )
F_73 ( V_3 ) ;
}
return V_165 ;
}
static int T_3 F_76 ( void )
{
int V_37 = 0 ;
const struct V_166 * V_2 ;
V_2 = F_77 ( V_167 ) ;
if ( ! V_2 ) {
F_38 ( L_25 ,
V_168 . V_169 , V_168 . V_170 ) ;
return - V_6 ;
}
V_33 = (struct V_33 * ) V_2 -> V_171 ;
F_78 () ;
F_11 () ;
V_37 = F_69 () ;
if ( V_37 )
goto V_146;
if ( F_60 () ) {
F_6 () ;
V_37 = - V_6 ;
goto V_146;
}
F_79 ( & V_172 ) ;
V_146:
F_14 () ;
F_80 () ;
return V_37 ;
}
static void T_4 F_81 ( void )
{
F_78 () ;
F_11 () ;
F_82 ( & V_172 ) ;
F_53 () ;
F_6 () ;
F_14 () ;
F_80 () ;
}
