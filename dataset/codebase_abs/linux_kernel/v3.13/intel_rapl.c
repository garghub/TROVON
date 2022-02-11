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
int V_29 ;
if ( V_15 -> V_30 & V_31 )
return - V_32 ;
F_11 () ;
V_29 = F_19 ( V_15 ) ;
F_21 ( V_15 , V_33 , V_28 ) ;
F_21 ( V_15 , V_34 , V_28 ) ;
if ( V_29 > 1 ) {
F_21 ( V_15 , V_35 , V_28 ) ;
F_21 ( V_15 , V_36 , V_28 ) ;
}
F_14 () ;
return 0 ;
}
static int F_22 ( struct V_11 * V_12 , bool * V_28 )
{
struct V_14 * V_15 = F_12 ( V_12 ) ;
T_1 V_37 ;
if ( V_15 -> V_30 & V_31 ) {
* V_28 = false ;
return 0 ;
}
F_11 () ;
if ( F_13 ( V_15 , V_33 , true , & V_37 ) ) {
F_14 () ;
return - V_18 ;
}
* V_28 = V_37 ;
F_14 () ;
return 0 ;
}
static int F_23 ( struct V_11 * V_12 , int V_2 ,
T_1 V_38 )
{
struct V_14 * V_15 ;
struct V_1 * V_3 ;
int V_39 = 0 ;
F_11 () ;
V_15 = F_12 ( V_12 ) ;
V_3 = F_1 ( V_15 -> V_4 ) ;
if ( ! V_3 ) {
V_39 = - V_6 ;
goto V_40;
}
if ( V_15 -> V_30 & V_31 ) {
F_18 ( & V_12 -> V_24 , L_2 ,
V_15 -> V_25 ) ;
V_39 = - V_32 ;
goto V_40;
}
switch ( V_15 -> V_27 [ V_2 ] . V_41 ) {
case V_33 :
F_21 ( V_15 , V_42 , V_38 ) ;
break;
case V_35 :
F_21 ( V_15 , V_43 , V_38 ) ;
break;
default:
V_39 = - V_44 ;
}
if ( ! V_39 )
F_24 ( V_15 -> V_4 ) ;
V_40:
F_14 () ;
return V_39 ;
}
static int F_25 ( struct V_11 * V_12 , int V_2 ,
T_1 * V_45 )
{
struct V_14 * V_15 ;
T_1 V_37 ;
int V_46 ;
int V_39 = 0 ;
F_11 () ;
V_15 = F_12 ( V_12 ) ;
switch ( V_15 -> V_27 [ V_2 ] . V_41 ) {
case V_33 :
V_46 = V_42 ;
break;
case V_35 :
V_46 = V_43 ;
break;
default:
F_14 () ;
return - V_44 ;
}
if ( F_13 ( V_15 , V_46 , true , & V_37 ) )
V_39 = - V_18 ;
else
* V_45 = V_37 ;
F_14 () ;
return V_39 ;
}
static int F_26 ( struct V_11 * V_12 , int V_2 ,
T_1 V_47 )
{
struct V_14 * V_15 ;
int V_39 = 0 ;
F_11 () ;
V_15 = F_12 ( V_12 ) ;
switch ( V_15 -> V_27 [ V_2 ] . V_41 ) {
case V_33 :
F_21 ( V_15 , V_48 , V_47 ) ;
break;
case V_35 :
F_21 ( V_15 , V_49 , V_47 ) ;
break;
default:
V_39 = - V_44 ;
}
F_14 () ;
return V_39 ;
}
static int F_27 ( struct V_11 * V_12 , int V_2 , T_1 * V_45 )
{
struct V_14 * V_15 ;
T_1 V_37 ;
int V_39 = 0 ;
F_11 () ;
V_15 = F_12 ( V_12 ) ;
switch ( V_15 -> V_27 [ V_2 ] . V_41 ) {
case V_33 :
V_39 = F_13 ( V_15 , V_48 , true , & V_37 ) ;
break;
case V_35 :
V_39 = F_13 ( V_15 , V_49 , true , & V_37 ) ;
break;
default:
F_14 () ;
return - V_44 ;
}
if ( ! V_39 )
* V_45 = V_37 ;
F_14 () ;
return V_39 ;
}
static const char * F_28 ( struct V_11 * V_12 , int V_2 )
{
struct V_50 * V_27 ;
struct V_14 * V_15 ;
V_15 = F_12 ( V_12 ) ;
V_27 = (struct V_50 * ) & V_15 -> V_27 [ V_2 ] ;
return V_27 -> V_25 ;
}
static int F_29 ( struct V_11 * V_12 , int V_2 ,
T_1 * V_45 )
{
struct V_14 * V_15 ;
T_1 V_37 ;
int V_46 ;
int V_39 = 0 ;
F_11 () ;
V_15 = F_12 ( V_12 ) ;
switch ( V_15 -> V_27 [ V_2 ] . V_41 ) {
case V_33 :
V_46 = V_51 ;
break;
case V_35 :
V_46 = V_52 ;
break;
default:
F_14 () ;
return - V_44 ;
}
if ( F_13 ( V_15 , V_46 , true , & V_37 ) )
V_39 = - V_18 ;
else
* V_45 = V_37 ;
F_14 () ;
return V_39 ;
}
static void F_30 ( struct V_1 * V_3 )
{
int V_5 ;
struct V_14 * V_15 = V_3 -> V_9 ;
for ( V_5 = 0 ; V_5 < V_53 ; V_5 ++ ) {
unsigned int V_54 = V_3 -> V_55 & ( 1 << V_5 ) ;
switch ( V_54 ) {
case F_31 ( V_23 ) :
V_15 -> V_25 = V_56 [ V_23 ] ;
V_15 -> V_2 = V_23 ;
V_15 -> V_57 [ 0 ] = V_58 ;
V_15 -> V_57 [ 1 ] = V_59 ;
V_15 -> V_57 [ 2 ] = V_60 ;
V_15 -> V_57 [ 3 ] = 0 ;
V_15 -> V_57 [ 4 ] = V_61 ;
V_15 -> V_27 [ 0 ] . V_41 = V_33 ;
V_15 -> V_27 [ 0 ] . V_25 = V_62 ;
V_15 -> V_27 [ 1 ] . V_41 = V_35 ;
V_15 -> V_27 [ 1 ] . V_25 = V_63 ;
break;
case F_31 ( V_64 ) :
V_15 -> V_25 = V_56 [ V_64 ] ;
V_15 -> V_2 = V_64 ;
V_15 -> V_57 [ 0 ] = V_65 ;
V_15 -> V_57 [ 1 ] = V_66 ;
V_15 -> V_57 [ 2 ] = 0 ;
V_15 -> V_57 [ 3 ] = V_67 ;
V_15 -> V_57 [ 4 ] = 0 ;
V_15 -> V_27 [ 0 ] . V_41 = V_33 ;
V_15 -> V_27 [ 0 ] . V_25 = V_62 ;
break;
case F_31 ( V_68 ) :
V_15 -> V_25 = V_56 [ V_68 ] ;
V_15 -> V_2 = V_68 ;
V_15 -> V_57 [ 0 ] = V_69 ;
V_15 -> V_57 [ 1 ] = V_70 ;
V_15 -> V_57 [ 2 ] = 0 ;
V_15 -> V_57 [ 3 ] = V_71 ;
V_15 -> V_57 [ 4 ] = 0 ;
V_15 -> V_27 [ 0 ] . V_41 = V_33 ;
V_15 -> V_27 [ 0 ] . V_25 = V_62 ;
break;
case F_31 ( V_72 ) :
V_15 -> V_25 = V_56 [ V_72 ] ;
V_15 -> V_2 = V_72 ;
V_15 -> V_57 [ 0 ] = V_73 ;
V_15 -> V_57 [ 1 ] = V_74 ;
V_15 -> V_57 [ 2 ] = V_75 ;
V_15 -> V_57 [ 3 ] = 0 ;
V_15 -> V_57 [ 4 ] = V_76 ;
V_15 -> V_27 [ 0 ] . V_41 = V_33 ;
V_15 -> V_27 [ 0 ] . V_25 = V_62 ;
break;
}
if ( V_54 ) {
V_15 -> V_4 = V_3 -> V_2 ;
V_15 ++ ;
}
}
}
static T_1 F_16 ( int V_77 , enum V_78 type , T_1 V_79 ,
int V_80 )
{
T_1 V_81 = 1 ;
int V_82 = 1 ;
T_1 V_83 , V_84 ;
struct V_1 * V_3 ;
V_3 = F_1 ( V_77 ) ;
if ( ! V_3 )
return V_79 ;
switch ( type ) {
case V_85 :
V_81 = V_3 -> V_86 ;
V_82 = V_87 ;
break;
case V_21 :
V_82 = V_88 ;
V_81 = V_3 -> V_89 ;
break;
case V_90 :
V_81 = V_3 -> V_91 ;
V_82 = V_92 ;
if ( ! V_80 ) {
V_83 = ( V_79 & 0x60 ) >> 5 ;
V_84 = V_79 & 0x1f ;
V_79 = ( 1 << V_84 ) * ( 4 + V_83 ) * V_82 / 4 ;
return F_32 ( V_79 , V_81 ) ;
} else {
F_33 ( V_79 , V_82 ) ;
V_79 *= V_81 ;
V_84 = F_34 ( V_79 ) ;
V_83 = F_32 ( 4 * ( V_79 - ( 1 << V_84 ) ) , 1 << V_84 ) ;
V_79 = ( V_84 & 0x1f ) | ( ( V_83 & 0x3 ) << 5 ) ;
return V_79 ;
}
break;
case V_93 :
default:
return V_79 ;
} ;
if ( V_80 )
return F_32 ( V_79 * V_81 , V_82 ) ;
else
return F_32 ( V_79 * V_82 , V_81 ) ;
}
static int F_13 ( struct V_14 * V_15 ,
enum V_94 V_46 ,
bool V_95 , T_1 * V_45 )
{
T_1 V_79 , V_96 ;
T_2 V_97 ;
struct V_98 * V_3 = & V_99 [ V_46 ] ;
int V_100 ;
if ( ! V_3 -> V_25 || V_3 -> V_101 & V_102 )
return - V_44 ;
V_97 = V_15 -> V_57 [ V_3 -> V_2 ] ;
if ( ! V_97 )
return - V_44 ;
V_100 = F_3 ( V_15 -> V_4 ) ;
if ( V_100 < 0 )
return V_100 ;
if ( V_46 == V_103 && V_15 -> V_2 == V_23 ) {
V_3 -> V_54 = V_104 ;
V_3 -> V_105 = 63 ;
}
if ( V_3 -> V_101 & V_106 ) {
* V_45 = V_15 -> V_107 . V_108 [ V_46 ] ;
return 0 ;
}
if ( F_35 ( V_100 , V_97 , & V_79 ) ) {
F_36 ( L_3 , V_97 , V_100 ) ;
return - V_18 ;
}
V_96 = V_79 & V_3 -> V_54 ;
V_96 = V_96 >> V_3 -> V_105 ;
if ( V_95 )
* V_45 = F_16 ( V_15 -> V_4 , V_3 -> V_109 , V_96 , 0 ) ;
else
* V_45 = V_96 ;
return 0 ;
}
static int F_21 ( struct V_14 * V_15 ,
enum V_94 V_46 ,
unsigned long long V_79 )
{
T_1 V_110 ;
T_2 V_97 ;
struct V_98 * V_3 = & V_99 [ V_46 ] ;
int V_100 ;
V_100 = F_3 ( V_15 -> V_4 ) ;
if ( V_100 < 0 )
return V_100 ;
V_97 = V_15 -> V_57 [ V_3 -> V_2 ] ;
if ( F_35 ( V_100 , V_97 , & V_110 ) ) {
F_37 ( & V_15 -> V_12 . V_24 ,
L_3 , V_97 , V_100 ) ;
return - V_18 ;
}
V_79 = F_16 ( V_15 -> V_4 , V_3 -> V_109 , V_79 , 1 ) ;
V_110 &= ~ V_3 -> V_54 ;
V_110 |= V_79 << V_3 -> V_105 ;
if ( F_38 ( V_100 , V_97 , V_110 ) ) {
F_37 ( & V_15 -> V_12 . V_24 ,
L_4 , V_97 , V_100 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_3 , int V_100 )
{
T_1 V_110 ;
T_2 V_79 ;
if ( F_35 ( V_100 , V_111 , & V_110 ) ) {
F_40 ( L_5 ,
V_111 , V_100 ) ;
return - V_6 ;
}
V_79 = ( V_110 & V_112 ) >> V_113 ;
if ( F_41 ( V_114 ) )
V_3 -> V_89 = 1000000 / ( 1 << V_79 ) ;
else
V_3 -> V_89 = 1 << V_79 ;
V_79 = ( V_110 & V_115 ) >> V_116 ;
V_3 -> V_86 = 1 << V_79 ;
V_79 = ( V_110 & V_117 ) >> V_118 ;
V_3 -> V_91 = 1 << V_79 ;
F_36 ( L_6 ,
V_3 -> V_2 ,
V_3 -> V_89 ,
V_3 -> V_91 ,
V_3 -> V_86 ) ;
return 0 ;
}
static void F_24 ( int V_4 )
{
T_2 V_119 , V_120 = 0 ;
int V_100 ;
struct V_1 * V_3 ;
V_3 = F_1 ( V_4 ) ;
if ( ! V_3 )
return;
if ( ! F_42 ( V_121 ) || ! F_42 ( V_122 ) )
return;
V_100 = F_3 ( V_4 ) ;
if ( V_100 < 0 )
return;
F_43 ( V_100 , V_123 , & V_119 , & V_120 ) ;
if ( ! ( V_3 -> V_124 & V_125 ) ) {
V_3 -> V_124 = V_119 & V_126 ;
V_3 -> V_124 |= V_125 ;
}
V_119 &= ~ V_126 ;
F_44 ( V_100 , V_123 , V_119 , V_120 ) ;
}
static void F_45 ( int V_4 )
{
T_2 V_119 , V_120 ;
int V_100 ;
struct V_1 * V_3 ;
V_3 = F_1 ( V_4 ) ;
if ( ! V_3 )
return;
if ( ! F_42 ( V_121 ) || ! F_42 ( V_122 ) )
return;
V_100 = F_3 ( V_4 ) ;
if ( V_100 < 0 )
return;
if ( ! ( V_3 -> V_124 & V_125 ) )
return;
F_43 ( V_100 , V_123 , & V_119 , & V_120 ) ;
if ( V_3 -> V_124 & V_126 )
V_119 |= V_126 ;
else
V_119 &= ~ V_126 ;
F_44 ( V_100 , V_123 , V_119 , V_120 ) ;
}
static void F_46 ( void )
{
int V_127 , V_46 ;
T_1 V_37 ;
struct V_1 * V_3 ;
F_2 (rp, &rapl_packages, plist) {
for ( V_127 = 0 ; V_127 < V_3 -> V_128 ; V_127 ++ ) {
F_36 ( L_7 , V_3 -> V_2 ,
V_3 -> V_9 [ V_127 ] . V_25 ) ;
for ( V_46 = 0 ; V_46 < V_129 ; V_46 ++ )
if ( ! F_13 ( & V_3 -> V_9 [ V_127 ] , V_46 ,
V_99 [ V_46 ] . V_109 ,
& V_37 ) )
V_3 -> V_9 [ V_127 ] . V_107 . V_108 [ V_46 ] =
V_37 ;
}
}
}
static int F_47 ( void )
{
struct V_1 * V_3 ;
struct V_14 * V_15 , * V_130 = NULL ;
F_2 (rp, &rapl_packages, plist) {
F_45 ( V_3 -> V_2 ) ;
for ( V_15 = V_3 -> V_9 ; V_15 < V_3 -> V_9 + V_3 -> V_128 ;
V_15 ++ ) {
F_36 ( L_8 ,
V_3 -> V_2 , V_15 -> V_25 ) ;
F_21 ( V_15 , V_33 , 0 ) ;
F_21 ( V_15 , V_35 , 0 ) ;
F_21 ( V_15 , V_34 , 0 ) ;
F_21 ( V_15 , V_36 , 0 ) ;
if ( V_15 -> V_2 == V_23 ) {
V_130 = V_15 ;
continue;
}
F_48 ( V_131 , & V_15 -> V_12 ) ;
}
if ( V_130 )
F_48 ( V_131 ,
& V_130 -> V_12 ) ;
}
F_49 ( V_131 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_3 )
{
struct V_14 * V_15 ;
int V_39 = 0 ;
char V_132 [ 17 ] ;
struct V_11 * V_12 = NULL ;
int V_133 ;
for ( V_15 = V_3 -> V_9 ; V_15 < V_3 -> V_9 + V_3 -> V_128 ; V_15 ++ ) {
if ( V_15 -> V_2 == V_23 ) {
V_133 = F_19 ( V_15 ) ;
F_36 ( L_9 ,
V_3 -> V_2 , V_15 -> V_25 ) ;
memset ( V_132 , 0 , sizeof( V_132 ) ) ;
snprintf ( V_132 , sizeof( V_132 ) , L_10 ,
V_15 -> V_25 , V_3 -> V_2 ) ;
V_12 = F_51 ( & V_15 -> V_12 ,
V_131 ,
V_132 , NULL ,
& V_134 [ V_15 -> V_2 ] ,
V_133 ,
& V_135 ) ;
if ( F_52 ( V_12 ) ) {
F_36 ( L_11 ,
V_3 -> V_2 ) ;
V_39 = F_53 ( V_12 ) ;
goto V_136;
}
V_3 -> V_12 = V_12 ;
break;
}
}
if ( ! V_12 ) {
F_40 ( L_12 ) ;
V_39 = - V_6 ;
goto V_136;
}
for ( V_15 = V_3 -> V_9 ; V_15 < V_3 -> V_9 + V_3 -> V_128 ; V_15 ++ ) {
if ( V_15 -> V_2 == V_23 )
continue;
V_133 = F_19 ( V_15 ) ;
V_12 = F_51 ( & V_15 -> V_12 ,
V_131 , V_15 -> V_25 ,
V_3 -> V_12 ,
& V_134 [ V_15 -> V_2 ] , V_133 ,
& V_135 ) ;
if ( F_52 ( V_12 ) ) {
F_36 ( L_13 ,
V_3 -> V_2 , V_15 -> V_25 , V_132 ) ;
V_39 = F_53 ( V_12 ) ;
goto V_137;
}
}
V_136:
return V_39 ;
V_137:
while ( -- V_15 >= V_3 -> V_9 ) {
F_36 ( L_14 , V_3 -> V_2 , V_15 -> V_25 ) ;
F_48 ( V_131 , & V_15 -> V_12 ) ;
}
return V_39 ;
}
static int F_54 ( void )
{
struct V_14 * V_15 ;
struct V_1 * V_3 ;
int V_39 = 0 ;
V_131 = F_55 ( NULL , L_15 , NULL ) ;
if ( F_52 ( V_131 ) ) {
F_36 ( L_16 ) ;
return F_53 ( V_131 ) ;
}
F_46 () ;
F_2 (rp, &rapl_packages, plist)
if ( F_50 ( V_3 ) )
goto V_138;
return V_39 ;
V_138:
F_56 (rp, &rapl_packages, plist) {
for ( V_15 = V_3 -> V_9 ; V_15 < V_3 -> V_9 + V_3 -> V_128 ;
V_15 ++ ) {
F_36 ( L_17 ,
V_3 -> V_2 , V_15 -> V_25 ) ;
F_48 ( V_131 , & V_15 -> V_12 ) ;
}
}
return V_39 ;
}
static int F_57 ( int V_100 , int V_139 )
{
unsigned V_97 ;
T_1 V_140 , V_141 = 0 ;
int V_142 = 0 ;
switch ( V_139 ) {
case V_23 :
V_97 = V_59 ;
break;
case V_64 :
V_97 = V_66 ;
break;
case V_68 :
V_97 = V_70 ;
break;
case V_72 :
V_97 = V_74 ;
break;
default:
F_40 ( L_18 , V_139 ) ;
return - V_44 ;
}
if ( F_35 ( V_100 , V_97 , & V_140 ) )
return - V_6 ;
while ( ++ V_142 < 10 ) {
F_58 ( 10000 , 15000 ) ;
F_35 ( V_100 , V_97 , & V_141 ) ;
if ( ( V_140 & V_22 ) != ( V_141 & V_22 ) )
return 0 ;
}
F_59 ( L_19 ,
V_56 [ V_139 ] , V_140 , V_141 ) ;
return - V_6 ;
}
static int F_60 ( struct V_1 * V_3 , int V_100 )
{
int V_5 ;
int V_39 = 0 ;
struct V_14 * V_15 ;
T_1 V_143 ;
for ( V_5 = 0 ; V_5 < V_53 ; V_5 ++ ) {
if ( ! F_57 ( V_100 , V_5 ) )
V_3 -> V_55 |= 1 << V_5 ;
}
V_3 -> V_128 = F_61 ( & V_3 -> V_55 , V_53 ) ;
if ( ! V_3 -> V_128 ) {
F_40 ( L_20 , V_3 -> V_2 ) ;
V_39 = - V_6 ;
goto V_144;
}
F_36 ( L_21 , V_3 -> V_128 , V_3 -> V_2 ) ;
V_3 -> V_9 = F_62 ( V_3 -> V_128 + 1 , sizeof( struct V_14 ) ,
V_145 ) ;
if ( ! V_3 -> V_9 ) {
V_39 = - V_146 ;
goto V_144;
}
F_30 ( V_3 ) ;
for ( V_15 = V_3 -> V_9 ; V_15 < V_3 -> V_9 + V_3 -> V_128 ; V_15 ++ ) {
if ( F_13 ( V_15 , V_103 , false , & V_143 ) ) {
F_59 ( L_22 ,
V_3 -> V_2 , V_15 -> V_25 ) ;
V_15 -> V_30 |= V_31 ;
}
}
V_144:
return V_39 ;
}
static bool F_63 ( int V_77 )
{
struct V_1 * V_3 ;
F_2 (rp, &rapl_packages, plist)
if ( V_77 == V_3 -> V_2 )
return false ;
return true ;
}
static int F_64 ( void )
{
int V_5 ;
int V_147 ;
struct V_1 * V_148 , * V_3 ;
F_4 (i) {
V_147 = F_5 ( V_5 ) ;
if ( F_63 ( V_147 ) ) {
V_148 = F_65 ( sizeof( * V_3 ) , V_145 ) ;
if ( ! V_148 ) {
F_6 () ;
return - V_146 ;
}
V_148 -> V_2 = V_147 ;
V_148 -> V_149 = 1 ;
if ( F_60 ( V_148 , V_5 ) ||
F_39 ( V_148 , V_5 ) ) {
F_8 ( V_148 -> V_9 ) ;
F_8 ( V_148 ) ;
F_6 () ;
return - V_6 ;
}
F_66 ( & V_148 -> V_10 ) ;
F_67 ( & V_148 -> V_10 , & V_150 ) ;
} else {
V_3 = F_1 ( V_147 ) ;
if ( V_3 )
++ V_3 -> V_149 ;
}
}
return 0 ;
}
static void F_68 ( struct V_1 * V_3 )
{
struct V_14 * V_15 , * V_130 = NULL ;
for ( V_15 = V_3 -> V_9 ; V_15 < V_3 -> V_9 + V_3 -> V_128 ; V_15 ++ ) {
if ( V_15 -> V_2 == V_23 ) {
V_130 = V_15 ;
continue;
}
F_36 ( L_23 , V_3 -> V_2 , V_15 -> V_25 ) ;
F_48 ( V_131 , & V_15 -> V_12 ) ;
}
F_48 ( V_131 , & V_130 -> V_12 ) ;
F_9 ( & V_3 -> V_10 ) ;
F_8 ( V_3 ) ;
}
static int F_69 ( int V_100 )
{
int V_39 = 0 ;
int V_147 ;
struct V_1 * V_3 ;
V_147 = F_5 ( V_100 ) ;
V_3 = F_65 ( sizeof( struct V_1 ) , V_145 ) ;
if ( ! V_3 )
return - V_146 ;
V_3 -> V_2 = V_147 ;
V_3 -> V_149 = 1 ;
if ( F_60 ( V_3 , V_100 ) ||
F_39 ( V_3 , V_100 ) ) {
V_39 = - V_6 ;
goto V_151;
}
if ( ! F_50 ( V_3 ) ) {
F_66 ( & V_3 -> V_10 ) ;
F_67 ( & V_3 -> V_10 , & V_150 ) ;
return V_39 ;
}
V_151:
F_8 ( V_3 -> V_9 ) ;
F_8 ( V_3 ) ;
return V_39 ;
}
static int F_70 ( struct V_152 * V_153 ,
unsigned long V_154 , void * V_155 )
{
unsigned long V_100 = ( unsigned long ) V_155 ;
int V_147 ;
struct V_1 * V_3 ;
V_147 = F_5 ( V_100 ) ;
switch ( V_154 ) {
case V_156 :
case V_157 :
case V_158 :
case V_159 :
V_3 = F_1 ( V_147 ) ;
if ( V_3 )
++ V_3 -> V_149 ;
else
F_69 ( V_100 ) ;
break;
case V_160 :
case V_161 :
V_3 = F_1 ( V_147 ) ;
if ( ! V_3 )
break;
if ( -- V_3 -> V_149 == 0 )
F_68 ( V_3 ) ;
}
return V_162 ;
}
static int T_3 F_71 ( void )
{
int V_39 = 0 ;
if ( ! F_41 ( V_163 ) ) {
F_40 ( L_24 ,
V_164 . V_165 , V_164 . V_166 ) ;
return - V_6 ;
}
F_11 () ;
V_39 = F_64 () ;
if ( V_39 )
goto V_144;
if ( F_54 () ) {
F_6 () ;
V_39 = - V_6 ;
goto V_144;
}
F_72 ( & V_167 ) ;
V_144:
F_14 () ;
return V_39 ;
}
static void T_4 F_73 ( void )
{
F_11 () ;
F_74 ( & V_167 ) ;
F_47 () ;
F_6 () ;
F_14 () ;
}
