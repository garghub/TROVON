static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
F_2 (rp, &rapl_packages, plist) {
if ( V_3 -> V_2 == V_2 )
return V_3 ;
}
return NULL ;
}
static int F_3 ( struct V_4 * V_5 , T_1 * V_6 )
{
struct V_7 * V_8 ;
T_1 V_9 ;
F_4 () ;
V_8 = F_5 ( V_5 ) ;
if ( ! F_6 ( V_8 , V_10 , true , & V_9 ) ) {
* V_6 = V_9 ;
F_7 () ;
return 0 ;
}
F_7 () ;
return - V_11 ;
}
static int F_8 ( struct V_4 * V_12 , T_1 * V_13 )
{
struct V_7 * V_8 = F_5 ( V_12 ) ;
* V_13 = F_9 ( V_8 , V_14 , V_15 , 0 ) ;
return 0 ;
}
static int F_10 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_5 ( V_5 ) ;
struct V_1 * V_3 = V_8 -> V_3 ;
if ( V_8 -> V_2 == V_16 ) {
F_11 ( V_8 ) ;
V_3 -> V_17 = NULL ;
}
return 0 ;
}
static int F_12 ( struct V_7 * V_8 )
{
int V_18 , V_19 = 0 ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
if ( V_8 -> V_21 [ V_18 ] . V_22 )
V_19 ++ ;
}
return V_19 ;
}
static int F_13 ( struct V_4 * V_5 , bool V_23 )
{
struct V_7 * V_8 = F_5 ( V_5 ) ;
if ( V_8 -> V_24 & V_25 )
return - V_26 ;
F_4 () ;
F_14 ( V_8 , V_27 , V_23 ) ;
if ( V_28 -> V_29 )
V_28 -> V_29 ( V_8 , V_23 ) ;
F_7 () ;
return 0 ;
}
static int F_15 ( struct V_4 * V_5 , bool * V_23 )
{
struct V_7 * V_8 = F_5 ( V_5 ) ;
T_1 V_30 ;
if ( V_8 -> V_24 & V_25 ) {
* V_23 = false ;
return 0 ;
}
F_4 () ;
if ( F_6 ( V_8 , V_27 , true , & V_30 ) ) {
F_7 () ;
return - V_11 ;
}
* V_23 = V_30 ;
F_7 () ;
return 0 ;
}
static int F_16 ( struct V_7 * V_8 , int V_31 )
{
int V_18 , V_32 ;
for ( V_18 = 0 , V_32 = 0 ; V_18 < V_20 ; V_18 ++ ) {
if ( ( V_8 -> V_21 [ V_18 ] . V_22 ) && V_32 ++ == V_31 ) {
F_17 ( L_1 , V_33 , V_18 ) ;
return V_18 ;
}
}
F_18 ( L_2 , V_31 ) ;
return - V_34 ;
}
static int F_19 ( struct V_4 * V_5 , int V_31 ,
T_1 V_35 )
{
struct V_7 * V_8 ;
struct V_1 * V_3 ;
int V_36 = 0 ;
int V_2 ;
F_4 () ;
V_8 = F_5 ( V_5 ) ;
V_2 = F_16 ( V_8 , V_31 ) ;
if ( V_2 < 0 ) {
V_36 = V_2 ;
goto V_37;
}
V_3 = V_8 -> V_3 ;
if ( V_8 -> V_24 & V_25 ) {
F_20 ( & V_5 -> V_38 , L_3 ,
V_8 -> V_22 ) ;
V_36 = - V_26 ;
goto V_37;
}
switch ( V_8 -> V_21 [ V_2 ] . V_39 ) {
case V_27 :
F_14 ( V_8 , V_40 , V_35 ) ;
break;
case V_41 :
F_14 ( V_8 , V_42 , V_35 ) ;
break;
default:
V_36 = - V_34 ;
}
if ( ! V_36 )
F_21 ( V_3 ) ;
V_37:
F_7 () ;
return V_36 ;
}
static int F_22 ( struct V_4 * V_5 , int V_31 ,
T_1 * V_43 )
{
struct V_7 * V_8 ;
T_1 V_30 ;
int V_44 ;
int V_36 = 0 ;
int V_2 ;
F_4 () ;
V_8 = F_5 ( V_5 ) ;
V_2 = F_16 ( V_8 , V_31 ) ;
if ( V_2 < 0 ) {
V_36 = V_2 ;
goto V_45;
}
switch ( V_8 -> V_21 [ V_2 ] . V_39 ) {
case V_27 :
V_44 = V_40 ;
break;
case V_41 :
V_44 = V_42 ;
break;
default:
F_7 () ;
return - V_34 ;
}
if ( F_6 ( V_8 , V_44 , true , & V_30 ) )
V_36 = - V_11 ;
else
* V_43 = V_30 ;
V_45:
F_7 () ;
return V_36 ;
}
static int F_23 ( struct V_4 * V_5 , int V_31 ,
T_1 V_46 )
{
struct V_7 * V_8 ;
int V_36 = 0 ;
int V_2 ;
F_4 () ;
V_8 = F_5 ( V_5 ) ;
V_2 = F_16 ( V_8 , V_31 ) ;
if ( V_2 < 0 ) {
V_36 = V_2 ;
goto V_47;
}
switch ( V_8 -> V_21 [ V_2 ] . V_39 ) {
case V_27 :
F_14 ( V_8 , V_48 , V_46 ) ;
break;
case V_41 :
F_14 ( V_8 , V_49 , V_46 ) ;
break;
default:
V_36 = - V_34 ;
}
V_47:
F_7 () ;
return V_36 ;
}
static int F_24 ( struct V_4 * V_5 , int V_31 , T_1 * V_43 )
{
struct V_7 * V_8 ;
T_1 V_30 ;
int V_36 = 0 ;
int V_2 ;
F_4 () ;
V_8 = F_5 ( V_5 ) ;
V_2 = F_16 ( V_8 , V_31 ) ;
if ( V_2 < 0 ) {
V_36 = V_2 ;
goto V_50;
}
switch ( V_8 -> V_21 [ V_2 ] . V_39 ) {
case V_27 :
V_36 = F_6 ( V_8 , V_48 , true , & V_30 ) ;
break;
case V_41 :
V_36 = F_6 ( V_8 , V_49 , true , & V_30 ) ;
break;
default:
F_7 () ;
return - V_34 ;
}
if ( ! V_36 )
* V_43 = V_30 ;
V_50:
F_7 () ;
return V_36 ;
}
static const char * F_25 ( struct V_4 * V_5 , int V_31 )
{
struct V_7 * V_8 ;
int V_2 ;
V_8 = F_5 ( V_5 ) ;
V_2 = F_16 ( V_8 , V_31 ) ;
if ( V_2 >= 0 )
return V_8 -> V_21 [ V_2 ] . V_22 ;
return NULL ;
}
static int F_26 ( struct V_4 * V_5 , int V_2 ,
T_1 * V_43 )
{
struct V_7 * V_8 ;
T_1 V_30 ;
int V_44 ;
int V_36 = 0 ;
F_4 () ;
V_8 = F_5 ( V_5 ) ;
switch ( V_8 -> V_21 [ V_2 ] . V_39 ) {
case V_27 :
V_44 = V_51 ;
break;
case V_41 :
V_44 = V_52 ;
break;
default:
F_7 () ;
return - V_34 ;
}
if ( F_6 ( V_8 , V_44 , true , & V_30 ) )
V_36 = - V_11 ;
else
* V_43 = V_30 ;
F_7 () ;
return V_36 ;
}
static void F_27 ( struct V_1 * V_3 )
{
int V_18 ;
struct V_7 * V_8 = V_3 -> V_17 ;
for ( V_18 = 0 ; V_18 < V_53 ; V_18 ++ ) {
unsigned int V_54 = V_3 -> V_55 & ( 1 << V_18 ) ;
switch ( V_54 ) {
case F_28 ( V_16 ) :
V_8 -> V_22 = V_56 [ V_16 ] ;
V_8 -> V_2 = V_16 ;
V_8 -> V_57 [ 0 ] = V_58 ;
V_8 -> V_57 [ 1 ] = V_59 ;
V_8 -> V_57 [ 2 ] = V_60 ;
V_8 -> V_57 [ 3 ] = 0 ;
V_8 -> V_57 [ 4 ] = V_61 ;
V_8 -> V_21 [ 0 ] . V_39 = V_27 ;
V_8 -> V_21 [ 0 ] . V_22 = V_62 ;
V_8 -> V_21 [ 1 ] . V_39 = V_41 ;
V_8 -> V_21 [ 1 ] . V_22 = V_63 ;
break;
case F_28 ( V_64 ) :
V_8 -> V_22 = V_56 [ V_64 ] ;
V_8 -> V_2 = V_64 ;
V_8 -> V_57 [ 0 ] = V_65 ;
V_8 -> V_57 [ 1 ] = V_66 ;
V_8 -> V_57 [ 2 ] = 0 ;
V_8 -> V_57 [ 3 ] = V_67 ;
V_8 -> V_57 [ 4 ] = 0 ;
V_8 -> V_21 [ 0 ] . V_39 = V_27 ;
V_8 -> V_21 [ 0 ] . V_22 = V_62 ;
break;
case F_28 ( V_68 ) :
V_8 -> V_22 = V_56 [ V_68 ] ;
V_8 -> V_2 = V_68 ;
V_8 -> V_57 [ 0 ] = V_69 ;
V_8 -> V_57 [ 1 ] = V_70 ;
V_8 -> V_57 [ 2 ] = 0 ;
V_8 -> V_57 [ 3 ] = V_71 ;
V_8 -> V_57 [ 4 ] = 0 ;
V_8 -> V_21 [ 0 ] . V_39 = V_27 ;
V_8 -> V_21 [ 0 ] . V_22 = V_62 ;
break;
case F_28 ( V_72 ) :
V_8 -> V_22 = V_56 [ V_72 ] ;
V_8 -> V_2 = V_72 ;
V_8 -> V_57 [ 0 ] = V_73 ;
V_8 -> V_57 [ 1 ] = V_74 ;
V_8 -> V_57 [ 2 ] = V_75 ;
V_8 -> V_57 [ 3 ] = 0 ;
V_8 -> V_57 [ 4 ] = V_76 ;
V_8 -> V_21 [ 0 ] . V_39 = V_27 ;
V_8 -> V_21 [ 0 ] . V_22 = V_62 ;
V_8 -> V_77 =
V_28 -> V_78 ;
if ( V_8 -> V_77 )
F_29 ( L_4 ,
V_8 -> V_77 ) ;
break;
}
if ( V_54 ) {
V_8 -> V_3 = V_3 ;
V_8 ++ ;
}
}
}
static T_1 F_9 ( struct V_7 * V_8 , enum V_79 type ,
T_1 V_80 , int V_81 )
{
T_1 V_82 = 1 ;
struct V_1 * V_3 = V_8 -> V_3 ;
T_1 V_83 = 1 ;
switch ( type ) {
case V_84 :
V_82 = V_3 -> V_85 ;
break;
case V_14 :
V_83 = V_86 ;
if ( V_8 -> V_77 )
V_82 = V_8 -> V_77 ;
else
V_82 = V_3 -> V_87 ;
break;
case V_88 :
return V_28 -> V_89 ( V_3 , V_80 , V_81 ) ;
case V_90 :
default:
return V_80 ;
} ;
if ( V_81 )
return F_30 ( V_80 , V_82 ) * V_83 ;
V_80 *= V_82 ;
return F_30 ( V_80 , V_83 ) ;
}
static int F_6 ( struct V_7 * V_8 ,
enum V_91 V_44 ,
bool V_92 , T_1 * V_43 )
{
T_1 V_80 , V_93 ;
T_2 V_94 ;
struct V_95 * V_3 = & V_96 [ V_44 ] ;
int V_97 ;
if ( ! V_3 -> V_22 || V_3 -> V_98 & V_99 )
return - V_34 ;
V_94 = V_8 -> V_57 [ V_3 -> V_2 ] ;
if ( ! V_94 )
return - V_34 ;
V_97 = V_8 -> V_3 -> V_100 ;
if ( V_44 == V_101 && V_8 -> V_2 == V_16 ) {
V_3 -> V_54 = V_102 ;
V_3 -> V_103 = 63 ;
}
if ( V_3 -> V_98 & V_104 ) {
* V_43 = V_8 -> V_105 . V_106 [ V_44 ] ;
return 0 ;
}
if ( F_31 ( V_97 , V_94 , & V_80 ) ) {
F_17 ( L_5 , V_94 , V_97 ) ;
return - V_11 ;
}
V_93 = V_80 & V_3 -> V_54 ;
V_93 = V_93 >> V_3 -> V_103 ;
if ( V_92 )
* V_43 = F_9 ( V_8 , V_3 -> V_107 , V_93 , 0 ) ;
else
* V_43 = V_93 ;
return 0 ;
}
static int F_32 ( T_2 V_108 , T_1 V_109 , T_1 V_110 )
{
int V_111 ;
T_1 V_30 ;
V_111 = F_33 ( V_108 , & V_30 ) ;
if ( V_111 )
goto V_112;
V_30 &= ~ V_109 ;
V_30 |= V_110 ;
V_111 = F_34 ( V_108 , V_30 ) ;
V_112:
return V_111 ;
}
static void F_35 ( void * V_113 )
{
struct V_114 * V_115 = V_113 ;
V_115 -> V_111 = F_32 ( V_115 -> V_108 , V_115 -> V_109 , V_115 -> V_110 ) ;
}
static int F_14 ( struct V_7 * V_8 ,
enum V_91 V_44 ,
unsigned long long V_80 )
{
struct V_95 * V_3 = & V_96 [ V_44 ] ;
int V_97 ;
T_1 V_116 ;
struct V_114 V_115 ;
int V_36 ;
V_97 = V_8 -> V_3 -> V_100 ;
V_116 = F_9 ( V_8 , V_3 -> V_107 , V_80 , 1 ) ;
V_116 |= V_116 << V_3 -> V_103 ;
memset ( & V_115 , 0 , sizeof( V_115 ) ) ;
V_115 . V_108 = V_8 -> V_57 [ V_3 -> V_2 ] ;
V_115 . V_109 = V_3 -> V_54 ;
V_115 . V_110 = V_116 ;
V_36 = F_36 ( V_97 , F_35 , & V_115 , 1 ) ;
if ( V_36 )
F_37 ( V_36 ) ;
else
V_36 = V_115 . V_111 ;
return V_36 ;
}
static int F_38 ( struct V_1 * V_3 , int V_97 )
{
T_1 V_117 ;
T_2 V_80 ;
if ( F_31 ( V_97 , V_118 , & V_117 ) ) {
F_18 ( L_6 ,
V_118 , V_97 ) ;
return - V_119 ;
}
V_80 = ( V_117 & V_120 ) >> V_121 ;
V_3 -> V_87 = V_86 * 1000000 / ( 1 << V_80 ) ;
V_80 = ( V_117 & V_122 ) >> V_123 ;
V_3 -> V_85 = 1000000 / ( 1 << V_80 ) ;
V_80 = ( V_117 & V_124 ) >> V_125 ;
V_3 -> V_126 = 1000000 / ( 1 << V_80 ) ;
F_17 ( L_7 ,
V_3 -> V_2 , V_3 -> V_87 , V_3 -> V_126 , V_3 -> V_85 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_3 , int V_97 )
{
T_1 V_117 ;
T_2 V_80 ;
if ( F_31 ( V_97 , V_118 , & V_117 ) ) {
F_18 ( L_6 ,
V_118 , V_97 ) ;
return - V_119 ;
}
V_80 = ( V_117 & V_120 ) >> V_121 ;
V_3 -> V_87 = V_86 * 1 << V_80 ;
V_80 = ( V_117 & V_122 ) >> V_123 ;
V_3 -> V_85 = ( 1 << V_80 ) * 1000 ;
V_80 = ( V_117 & V_124 ) >> V_125 ;
V_3 -> V_126 = 1000000 / ( 1 << V_80 ) ;
F_17 ( L_8 ,
V_3 -> V_2 , V_3 -> V_87 , V_3 -> V_126 , V_3 -> V_85 ) ;
return 0 ;
}
static void F_40 ( void * V_113 )
{
T_2 V_127 , V_128 = 0 ;
struct V_1 * V_3 = (struct V_1 * ) V_113 ;
F_41 ( V_129 , & V_127 , & V_128 ) ;
if ( ! ( V_3 -> V_130 & V_131 ) ) {
V_3 -> V_130 = V_127 & V_132 ;
V_3 -> V_130 |= V_131 ;
}
V_127 &= ~ V_132 ;
F_42 ( V_129 , V_127 , V_128 ) ;
}
static void F_21 ( struct V_1 * V_3 )
{
if ( ! F_43 ( V_133 ) || ! F_43 ( V_134 ) )
return;
F_36 ( V_3 -> V_100 , F_40 , V_3 , 1 ) ;
}
static void F_44 ( struct V_1 * V_3 )
{
T_2 V_127 , V_128 ;
if ( ! F_43 ( V_133 ) || ! F_43 ( V_134 ) )
return;
if ( ! ( V_3 -> V_130 & V_131 ) )
return;
F_41 ( V_129 , & V_127 , & V_128 ) ;
if ( V_3 -> V_130 & V_132 )
V_127 |= V_132 ;
else
V_127 &= ~ V_132 ;
F_42 ( V_129 , V_127 , V_128 ) ;
}
static void F_45 ( struct V_7 * V_8 , bool V_23 )
{
int V_135 = F_12 ( V_8 ) ;
F_14 ( V_8 , V_136 , V_23 ) ;
if ( V_135 > 1 ) {
F_14 ( V_8 , V_41 , V_23 ) ;
F_14 ( V_8 , V_137 , V_23 ) ;
}
}
static void F_46 ( struct V_7 * V_8 , bool V_138 )
{
static T_2 V_139 ;
T_2 V_140 ;
if ( ! V_28 -> V_141 ) {
F_18 ( L_9 ) ;
return;
}
if ( ! V_139 )
F_47 ( V_142 , V_143 ,
V_28 -> V_141 ,
& V_139 ) ;
V_140 = V_139 ;
if ( V_138 ) {
V_140 &= ~ ( 0x7f << 8 ) ;
V_140 |= 1 << 8 ;
}
F_48 ( V_142 , V_144 ,
V_28 -> V_141 , V_140 ) ;
}
static T_1 F_49 ( struct V_1 * V_3 , T_1 V_80 ,
bool V_81 )
{
T_1 V_145 , V_146 ;
if ( ! V_81 ) {
V_145 = ( V_80 & 0x60 ) >> 5 ;
V_146 = V_80 & 0x1f ;
V_80 = ( 1 << V_146 ) * ( 4 + V_145 ) * V_3 -> V_126 / 4 ;
} else {
F_50 ( V_80 , V_3 -> V_126 ) ;
V_146 = F_51 ( V_80 ) ;
V_145 = F_30 ( 4 * ( V_80 - ( 1 << V_146 ) ) , 1 << V_146 ) ;
V_80 = ( V_146 & 0x1f ) | ( ( V_145 & 0x3 ) << 5 ) ;
}
return V_80 ;
}
static T_1 F_52 ( struct V_1 * V_3 , T_1 V_80 ,
bool V_81 )
{
if ( ! V_81 )
return ( V_80 ) ? V_80 *= V_3 -> V_126 : V_3 -> V_126 ;
else
V_80 = F_30 ( V_80 , V_3 -> V_126 ) ;
return V_80 ;
}
static void F_53 ( struct V_1 * V_3 )
{
int V_147 , V_44 ;
T_1 V_30 ;
for ( V_147 = 0 ; V_147 < V_3 -> V_148 ; V_147 ++ ) {
F_17 ( L_10 , V_3 -> V_2 ,
V_3 -> V_17 [ V_147 ] . V_22 ) ;
for ( V_44 = 0 ; V_44 < V_149 ; V_44 ++ ) {
if ( ! F_6 ( & V_3 -> V_17 [ V_147 ] , V_44 ,
V_96 [ V_44 ] . V_107 , & V_30 ) )
V_3 -> V_17 [ V_147 ] . V_105 . V_106 [ V_44 ] = V_30 ;
}
}
}
static void F_54 ( void )
{
if ( V_150 ) {
F_55 ( V_151 ,
& V_150 -> V_5 ) ;
F_11 ( V_150 ) ;
}
F_56 ( V_151 ) ;
}
static int F_57 ( struct V_1 * V_3 )
{
struct V_7 * V_8 ;
char V_152 [ 17 ] ;
struct V_4 * V_5 = NULL ;
int V_19 , V_36 ; ;
F_53 ( V_3 ) ;
for ( V_8 = V_3 -> V_17 ; V_8 < V_3 -> V_17 + V_3 -> V_148 ; V_8 ++ ) {
if ( V_8 -> V_2 == V_16 ) {
V_19 = F_12 ( V_8 ) ;
F_17 ( L_11 ,
V_3 -> V_2 , V_8 -> V_22 ) ;
memset ( V_152 , 0 , sizeof( V_152 ) ) ;
snprintf ( V_152 , sizeof( V_152 ) , L_12 ,
V_8 -> V_22 , V_3 -> V_2 ) ;
V_5 = F_58 ( & V_8 -> V_5 ,
V_151 ,
V_152 , NULL ,
& V_153 [ V_8 -> V_2 ] ,
V_19 ,
& V_154 ) ;
if ( F_59 ( V_5 ) ) {
F_17 ( L_13 ,
V_3 -> V_2 ) ;
return F_60 ( V_5 ) ;
}
V_3 -> V_5 = V_5 ;
break;
}
}
if ( ! V_5 ) {
F_18 ( L_14 ) ;
return - V_119 ;
}
for ( V_8 = V_3 -> V_17 ; V_8 < V_3 -> V_17 + V_3 -> V_148 ; V_8 ++ ) {
if ( V_8 -> V_2 == V_16 )
continue;
V_19 = F_12 ( V_8 ) ;
V_5 = F_58 ( & V_8 -> V_5 ,
V_151 , V_8 -> V_22 ,
V_3 -> V_5 ,
& V_153 [ V_8 -> V_2 ] , V_19 ,
& V_154 ) ;
if ( F_59 ( V_5 ) ) {
F_17 ( L_15 ,
V_3 -> V_2 , V_8 -> V_22 , V_152 ) ;
V_36 = F_60 ( V_5 ) ;
goto V_155;
}
}
return 0 ;
V_155:
while ( -- V_8 >= V_3 -> V_17 ) {
F_17 ( L_16 , V_3 -> V_2 , V_8 -> V_22 ) ;
F_55 ( V_151 , & V_8 -> V_5 ) ;
}
return V_36 ;
}
static int T_3 F_61 ( void )
{
struct V_7 * V_8 ;
struct V_4 * V_5 ;
T_1 V_30 ;
if ( F_31 ( 0 , V_156 , & V_30 ) || ! V_30 )
return - V_119 ;
if ( F_31 ( 0 , V_157 , & V_30 ) || ! V_30 )
return - V_119 ;
V_8 = F_62 ( sizeof( * V_8 ) , V_158 ) ;
if ( ! V_8 )
return - V_159 ;
V_8 -> V_22 = V_56 [ V_160 ] ;
V_8 -> V_2 = V_160 ;
V_8 -> V_57 [ 0 ] = V_157 ;
V_8 -> V_57 [ 1 ] = V_156 ;
V_8 -> V_21 [ 0 ] . V_39 = V_27 ;
V_8 -> V_21 [ 0 ] . V_22 = V_62 ;
V_8 -> V_21 [ 1 ] . V_39 = V_41 ;
V_8 -> V_21 [ 1 ] . V_22 = V_63 ;
V_8 -> V_3 = F_1 ( 0 ) ;
V_5 = F_58 ( & V_8 -> V_5 , V_151 ,
L_17 , NULL ,
& V_153 [ V_160 ] ,
2 , & V_154 ) ;
if ( F_59 ( V_5 ) ) {
F_11 ( V_8 ) ;
return F_60 ( V_5 ) ;
}
V_150 = V_8 ;
return 0 ;
}
static int T_3 F_63 ( void )
{
V_151 = F_64 ( NULL , L_18 , NULL ) ;
if ( F_59 ( V_151 ) ) {
F_17 ( L_19 ) ;
return F_60 ( V_151 ) ;
}
return 0 ;
}
static int F_65 ( int V_97 , int V_161 )
{
unsigned V_94 ;
T_1 V_30 = 0 ;
switch ( V_161 ) {
case V_16 :
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
case V_160 :
return - V_34 ;
default:
F_18 ( L_20 , V_161 ) ;
return - V_34 ;
}
if ( F_31 ( V_97 , V_94 , & V_30 ) || ! V_30 )
return - V_119 ;
return 0 ;
}
static void F_66 ( struct V_7 * V_8 )
{
T_1 V_162 ;
int V_18 ;
if ( ! F_6 ( V_8 , V_101 , false , & V_162 ) ) {
if ( V_162 ) {
F_29 ( L_21 ,
V_8 -> V_3 -> V_2 , V_8 -> V_22 ) ;
V_8 -> V_24 |= V_25 ;
}
}
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
int V_44 = V_8 -> V_21 [ V_18 ] . V_39 ;
if ( F_6 ( V_8 , V_44 , false , & V_162 ) )
V_8 -> V_21 [ V_18 ] . V_22 = NULL ;
}
}
static int F_67 ( struct V_1 * V_3 , int V_97 )
{
struct V_7 * V_8 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_53 ; V_18 ++ ) {
if ( ! F_65 ( V_97 , V_18 ) ) {
V_3 -> V_55 |= 1 << V_18 ;
F_29 ( L_22 , V_56 [ V_18 ] ) ;
}
}
V_3 -> V_148 = F_68 ( & V_3 -> V_55 , V_53 ) ;
if ( ! V_3 -> V_148 ) {
F_17 ( L_23 , V_3 -> V_2 ) ;
return - V_119 ;
}
F_17 ( L_24 , V_3 -> V_148 , V_3 -> V_2 ) ;
V_3 -> V_17 = F_69 ( V_3 -> V_148 + 1 , sizeof( struct V_7 ) ,
V_158 ) ;
if ( ! V_3 -> V_17 )
return - V_159 ;
F_27 ( V_3 ) ;
for ( V_8 = V_3 -> V_17 ; V_8 < V_3 -> V_17 + V_3 -> V_148 ; V_8 ++ )
F_66 ( V_8 ) ;
return 0 ;
}
static void F_70 ( struct V_1 * V_3 )
{
struct V_7 * V_8 , * V_163 = NULL ;
F_44 ( V_3 ) ;
for ( V_8 = V_3 -> V_17 ; V_8 < V_3 -> V_17 + V_3 -> V_148 ; V_8 ++ ) {
F_14 ( V_8 , V_27 , 0 ) ;
F_14 ( V_8 , V_136 , 0 ) ;
if ( F_12 ( V_8 ) > 1 ) {
F_14 ( V_8 , V_41 , 0 ) ;
F_14 ( V_8 , V_137 , 0 ) ;
}
if ( V_8 -> V_2 == V_16 ) {
V_163 = V_8 ;
continue;
}
F_17 ( L_25 ,
V_3 -> V_2 , V_8 -> V_22 ) ;
F_55 ( V_151 , & V_8 -> V_5 ) ;
}
F_55 ( V_151 , & V_163 -> V_5 ) ;
F_71 ( & V_3 -> V_164 ) ;
F_11 ( V_3 ) ;
}
static struct V_1 * F_72 ( int V_97 , int V_165 )
{
struct V_1 * V_3 ;
int V_36 ;
V_3 = F_62 ( sizeof( struct V_1 ) , V_158 ) ;
if ( ! V_3 )
return F_73 ( - V_159 ) ;
V_3 -> V_2 = V_165 ;
V_3 -> V_100 = V_97 ;
if ( F_67 ( V_3 , V_97 ) ||
V_28 -> V_166 ( V_3 , V_97 ) ) {
V_36 = - V_119 ;
goto V_167;
}
V_36 = F_57 ( V_3 ) ;
if ( ! V_36 ) {
F_74 ( & V_3 -> V_164 ) ;
F_75 ( & V_3 -> V_164 , & V_168 ) ;
return V_3 ;
}
V_167:
F_11 ( V_3 -> V_17 ) ;
F_11 ( V_3 ) ;
return F_73 ( V_36 ) ;
}
static int F_76 ( unsigned int V_97 )
{
int V_165 = F_77 ( V_97 ) ;
struct V_1 * V_3 ;
V_3 = F_1 ( V_165 ) ;
if ( ! V_3 ) {
V_3 = F_72 ( V_97 , V_165 ) ;
if ( F_59 ( V_3 ) )
return F_60 ( V_3 ) ;
}
F_78 ( V_97 , & V_3 -> V_169 ) ;
return 0 ;
}
static int F_79 ( unsigned int V_97 )
{
int V_165 = F_77 ( V_97 ) ;
struct V_1 * V_3 ;
int V_100 ;
V_3 = F_1 ( V_165 ) ;
if ( ! V_3 )
return 0 ;
F_80 ( V_97 , & V_3 -> V_169 ) ;
V_100 = F_81 ( & V_3 -> V_169 ) ;
if ( V_100 >= V_170 )
F_70 ( V_3 ) ;
else if ( V_3 -> V_100 == V_97 )
V_3 -> V_100 = V_100 ;
return 0 ;
}
static int T_3 F_82 ( void )
{
const struct V_171 * V_2 ;
int V_36 ;
V_2 = F_83 ( V_172 ) ;
if ( ! V_2 ) {
F_18 ( L_26 ,
V_173 . V_174 , V_173 . V_175 ) ;
return - V_119 ;
}
V_28 = (struct V_28 * ) V_2 -> V_176 ;
V_36 = F_63 () ;
if ( V_36 )
return V_36 ;
V_36 = F_84 ( V_177 , L_27 ,
F_76 , F_79 ) ;
if ( V_36 < 0 )
goto V_178;
V_179 = V_36 ;
F_61 () ;
return 0 ;
V_178:
F_54 () ;
return V_36 ;
}
static void T_4 F_85 ( void )
{
F_86 ( V_179 ) ;
F_54 () ;
}
