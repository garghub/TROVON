static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 * V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_9 = V_2 -> V_10 -> V_11 -> V_12 ;
if ( ! V_9 )
return - 1 ;
V_7 = V_9 -> V_13 ;
if ( ! V_7 )
return - 1 ;
V_5 = F_2 ( V_7 , V_14 ) ;
if ( ! V_5 )
return - 1 ;
F_3 ( V_7 , V_5 + V_3 , V_4 ) ;
return 0 ;
}
static T_3 F_4 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_2 V_17 = 0 ;
int V_18 ;
V_16 -> V_11 . type = V_19 ;
V_18 = F_1 ( V_2 , 18 , & V_17 ) ;
if ( V_18 )
return V_18 ;
V_16 -> V_11 . V_20 = F_5 ( V_17 ) ;
V_16 -> V_11 . V_21 = F_6 ( V_17 ) ;
return 0 ;
}
static inline bool F_7 ( struct V_15 * V_16 )
{
switch ( V_16 -> V_22 ) {
case V_23 :
case V_24 :
return true ;
default:
return false ;
}
}
static void F_8 ( struct V_1 * V_2 ,
int V_25 )
{
int V_26 = 0 ;
enum V_27 V_21 = V_28 ;
enum V_29 V_20 = V_30 ;
struct V_6 * V_10 ;
if ( F_7 ( & V_2 -> V_16 ) )
V_10 = V_2 -> V_10 -> V_11 -> V_12 -> V_13 ;
else
V_10 = V_2 -> V_10 ;
if ( F_9 ( V_10 , & V_21 , & V_20 ) ||
V_21 == V_28 || V_20 == V_30 ) {
F_10 ( L_1 ) ;
return;
}
switch ( V_21 ) {
case V_31 :
V_26 = 2 * V_20 ;
break;
case V_32 :
V_26 = 4 * V_20 ;
break;
case V_33 :
V_26 = 8 * V_20 ;
break;
default:
F_10 ( L_1 ) ;
return;
}
F_11 ( L_2 ,
V_26 ) ;
F_11 ( L_3 ,
( V_21 == V_33 ? L_4 :
V_21 == V_32 ? L_5 :
V_21 == V_31 ? L_6 :
L_7 ) ,
V_20 ,
( V_21 == V_31 ? L_8 :
V_21 == V_32 ? L_8 :
V_21 == V_33 ? L_9 :
L_7 ) ) ;
if ( V_26 < V_25 ) {
F_10 ( L_10 ) ;
F_10 ( L_11 ,
V_25 ) ;
F_10 ( L_12 ) ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
if ( ! F_13 ( V_34 , & V_2 -> V_35 ) &&
! F_14 ( V_36 , & V_2 -> V_35 ) )
F_15 ( & V_2 -> V_37 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_17 ( ! F_13 ( V_36 , & V_2 -> V_35 ) ) ;
F_18 () ;
F_19 ( V_36 , & V_2 -> V_35 ) ;
}
static void F_20 ( struct V_15 * V_16 , struct V_38 * V_39 )
{
int V_40 = 0 , V_41 = 0 ;
char V_42 [ 16 ] ;
T_1 V_43 [ 64 ] ;
switch ( V_39 -> V_44 ) {
case F_21 ( 0 ) :
for ( V_40 = 0 ; V_40 < 64 ; V_40 ++ )
V_43 [ V_40 ] = F_22 ( V_16 , F_21 ( V_40 ) ) ;
break;
case F_23 ( 0 ) :
for ( V_40 = 0 ; V_40 < 64 ; V_40 ++ )
V_43 [ V_40 ] = F_22 ( V_16 , F_23 ( V_40 ) ) ;
break;
case F_24 ( 0 ) :
for ( V_40 = 0 ; V_40 < 64 ; V_40 ++ )
V_43 [ V_40 ] = F_22 ( V_16 , F_24 ( V_40 ) ) ;
break;
case F_25 ( 0 ) :
for ( V_40 = 0 ; V_40 < 64 ; V_40 ++ )
V_43 [ V_40 ] = F_22 ( V_16 , F_25 ( V_40 ) ) ;
break;
case F_26 ( 0 ) :
for ( V_40 = 0 ; V_40 < 64 ; V_40 ++ )
V_43 [ V_40 ] = F_22 ( V_16 , F_26 ( V_40 ) ) ;
break;
case F_27 ( 0 ) :
for ( V_40 = 0 ; V_40 < 64 ; V_40 ++ )
V_43 [ V_40 ] = F_22 ( V_16 , F_27 ( V_40 ) ) ;
break;
case F_28 ( 0 ) :
for ( V_40 = 0 ; V_40 < 64 ; V_40 ++ )
V_43 [ V_40 ] = F_22 ( V_16 , F_28 ( V_40 ) ) ;
break;
case F_29 ( 0 ) :
for ( V_40 = 0 ; V_40 < 64 ; V_40 ++ )
V_43 [ V_40 ] = F_22 ( V_16 , F_29 ( V_40 ) ) ;
break;
case F_30 ( 0 ) :
for ( V_40 = 0 ; V_40 < 64 ; V_40 ++ )
V_43 [ V_40 ] = F_22 ( V_16 , F_30 ( V_40 ) ) ;
break;
case F_31 ( 0 ) :
for ( V_40 = 0 ; V_40 < 64 ; V_40 ++ )
V_43 [ V_40 ] = F_22 ( V_16 , F_31 ( V_40 ) ) ;
break;
case F_32 ( 0 ) :
for ( V_40 = 0 ; V_40 < 64 ; V_40 ++ )
V_43 [ V_40 ] = F_22 ( V_16 , F_32 ( V_40 ) ) ;
break;
case F_33 ( 0 ) :
for ( V_40 = 0 ; V_40 < 64 ; V_40 ++ )
V_43 [ V_40 ] = F_22 ( V_16 , F_33 ( V_40 ) ) ;
break;
case F_34 ( 0 ) :
for ( V_40 = 0 ; V_40 < 64 ; V_40 ++ )
V_43 [ V_40 ] = F_22 ( V_16 , F_34 ( V_40 ) ) ;
break;
case F_35 ( 0 ) :
for ( V_40 = 0 ; V_40 < 64 ; V_40 ++ )
V_43 [ V_40 ] = F_22 ( V_16 , F_35 ( V_40 ) ) ;
break;
default:
F_36 ( L_13 , V_39 -> V_45 ,
F_22 ( V_16 , V_39 -> V_44 ) ) ;
return;
}
for ( V_40 = 0 ; V_40 < 8 ; V_40 ++ ) {
snprintf ( V_42 , 16 , L_14 , V_39 -> V_45 , V_40 * 8 , V_40 * 8 + 7 ) ;
F_37 ( L_15 , V_42 ) ;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ )
F_38 ( L_16 , V_43 [ V_40 * 8 + V_41 ] ) ;
F_38 ( L_17 ) ;
}
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_38 * V_39 ;
int V_48 = 0 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
union V_53 * V_54 ;
struct V_55 { T_4 V_56 ; T_4 V_57 ; } * V_58 ;
struct V_49 * V_59 ;
union V_60 * V_61 ;
struct V_62 * V_63 ;
T_1 V_64 ;
int V_40 = 0 ;
if ( ! F_40 ( V_2 ) )
return;
if ( V_47 ) {
F_41 ( & V_2 -> V_10 -> V_65 , L_18 ) ;
F_36 ( L_19
L_20 ) ;
F_36 ( L_21 ,
V_47 -> V_45 ,
V_47 -> V_35 ,
V_47 -> V_66 ,
V_47 -> V_67 ) ;
}
F_41 ( & V_2 -> V_10 -> V_65 , L_22 ) ;
F_36 ( L_23 ) ;
for ( V_39 = (struct V_38 * ) V_68 ;
V_39 -> V_45 ; V_39 ++ ) {
F_20 ( V_16 , V_39 ) ;
}
if ( ! V_47 || ! F_42 ( V_47 ) )
goto exit;
F_41 ( & V_2 -> V_10 -> V_65 , L_24 ) ;
F_36 ( L_25 ,
L_26 ,
L_27 , L_28 , L_29 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_69 ; V_48 ++ ) {
V_50 = V_2 -> V_50 [ V_48 ] ;
V_52 = & V_50 -> V_70 [ V_50 -> V_71 ] ;
F_36 ( L_30 ,
V_48 , V_50 -> V_72 , V_50 -> V_71 ,
( T_4 ) F_43 ( V_52 , V_73 ) ,
F_44 ( V_52 , V_74 ) ,
V_52 -> V_75 ,
( T_4 ) V_52 -> V_76 ) ;
}
if ( ! F_45 ( V_2 ) )
goto V_77;
F_41 ( & V_2 -> V_10 -> V_65 , L_31 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_69 ; V_48 ++ ) {
V_50 = V_2 -> V_50 [ V_48 ] ;
F_36 ( L_32 ) ;
F_36 ( L_33 , V_50 -> V_78 ) ;
F_36 ( L_32 ) ;
F_36 ( L_34 ,
L_35 ,
L_36 ,
L_27 , L_28 , L_29 , L_37 ) ;
for ( V_40 = 0 ; V_50 -> V_79 && ( V_40 < V_50 -> V_80 ) ; V_40 ++ ) {
V_54 = F_46 ( V_50 , V_40 ) ;
V_52 = & V_50 -> V_70 [ V_40 ] ;
V_58 = (struct V_55 * ) V_54 ;
if ( F_44 ( V_52 , V_74 ) > 0 ) {
F_36 ( L_38 ,
V_40 ,
F_47 ( V_58 -> V_56 ) ,
F_47 ( V_58 -> V_57 ) ,
( T_4 ) F_43 ( V_52 , V_73 ) ,
F_44 ( V_52 , V_74 ) ,
V_52 -> V_75 ,
( T_4 ) V_52 -> V_76 ,
V_52 -> V_81 ) ;
if ( V_40 == V_50 -> V_72 &&
V_40 == V_50 -> V_71 )
F_38 ( L_39 ) ;
else if ( V_40 == V_50 -> V_72 )
F_38 ( L_40 ) ;
else if ( V_40 == V_50 -> V_71 )
F_38 ( L_41 ) ;
else
F_38 ( L_17 ) ;
if ( F_48 ( V_2 ) &&
V_52 -> V_81 )
F_49 ( V_82 , L_42 ,
V_83 , 16 , 1 ,
V_52 -> V_81 -> V_84 ,
F_44 ( V_52 , V_74 ) ,
true ) ;
}
}
}
V_77:
F_41 ( & V_2 -> V_10 -> V_65 , L_43 ) ;
F_36 ( L_44 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_85 ; V_48 ++ ) {
V_59 = V_2 -> V_59 [ V_48 ] ;
F_36 ( L_45 ,
V_48 , V_59 -> V_72 , V_59 -> V_71 ) ;
}
if ( ! F_50 ( V_2 ) )
goto exit;
F_41 ( & V_2 -> V_10 -> V_65 , L_46 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_85 ; V_48 ++ ) {
V_59 = V_2 -> V_59 [ V_48 ] ;
F_36 ( L_32 ) ;
F_36 ( L_47 , V_59 -> V_78 ) ;
F_36 ( L_32 ) ;
F_36 ( L_48 ,
L_49 ,
L_50 ,
L_51 ) ;
F_36 ( L_48 ,
L_52 ,
L_53 ,
L_54 ) ;
for ( V_40 = 0 ; V_40 < V_59 -> V_80 ; V_40 ++ ) {
V_63 = & V_59 -> V_63 [ V_40 ] ;
V_61 = F_51 ( V_59 , V_40 ) ;
V_58 = (struct V_55 * ) V_61 ;
V_64 = F_52 ( V_61 -> V_86 . V_87 . V_88 ) ;
if ( V_64 & V_89 ) {
F_36 ( L_55
L_56 , V_40 ,
F_47 ( V_58 -> V_56 ) ,
F_47 ( V_58 -> V_57 ) ,
V_63 -> V_81 ) ;
} else {
F_36 ( L_57
L_58 , V_40 ,
F_47 ( V_58 -> V_56 ) ,
F_47 ( V_58 -> V_57 ) ,
( T_4 ) V_63 -> V_73 ,
V_63 -> V_81 ) ;
if ( F_48 ( V_2 ) &&
V_63 -> V_73 ) {
F_49 ( V_82 , L_42 ,
V_83 , 16 , 1 ,
F_53 ( V_63 -> V_90 ) +
V_63 -> V_91 ,
F_54 ( V_59 ) , true ) ;
}
}
if ( V_40 == V_59 -> V_72 )
F_38 ( L_40 ) ;
else if ( V_40 == V_59 -> V_71 )
F_38 ( L_41 ) ;
else
F_38 ( L_17 ) ;
}
}
exit:
return;
}
static void F_55 ( struct V_1 * V_2 )
{
T_1 V_92 ;
V_92 = F_22 ( & V_2 -> V_16 , V_93 ) ;
F_56 ( & V_2 -> V_16 , V_93 ,
V_92 & ~ V_94 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
T_1 V_92 ;
V_92 = F_22 ( & V_2 -> V_16 , V_93 ) ;
F_56 ( & V_2 -> V_16 , V_93 ,
V_92 | V_94 ) ;
}
static void F_58 ( struct V_1 * V_2 , T_5 V_95 ,
T_6 V_96 , T_6 V_97 )
{
T_1 V_98 , V_99 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
switch ( V_16 -> V_100 . type ) {
case V_101 :
V_97 |= V_102 ;
if ( V_95 == - 1 )
V_95 = 0 ;
V_99 = ( ( ( V_95 * 64 ) + V_96 ) >> 2 ) & 0x1F ;
V_98 = F_22 ( V_16 , F_59 ( V_99 ) ) ;
V_98 &= ~ ( 0xFF << ( 8 * ( V_96 & 0x3 ) ) ) ;
V_98 |= ( V_97 << ( 8 * ( V_96 & 0x3 ) ) ) ;
F_56 ( V_16 , F_59 ( V_99 ) , V_98 ) ;
break;
case V_103 :
case V_104 :
if ( V_95 == - 1 ) {
V_97 |= V_102 ;
V_99 = ( ( V_96 & 1 ) * 8 ) ;
V_98 = F_22 ( & V_2 -> V_16 , V_105 ) ;
V_98 &= ~ ( 0xFF << V_99 ) ;
V_98 |= ( V_97 << V_99 ) ;
F_56 ( & V_2 -> V_16 , V_105 , V_98 ) ;
break;
} else {
V_97 |= V_102 ;
V_99 = ( ( 16 * ( V_96 & 1 ) ) + ( 8 * V_95 ) ) ;
V_98 = F_22 ( V_16 , F_59 ( V_96 >> 1 ) ) ;
V_98 &= ~ ( 0xFF << V_99 ) ;
V_98 |= ( V_97 << V_99 ) ;
F_56 ( V_16 , F_59 ( V_96 >> 1 ) , V_98 ) ;
break;
}
default:
break;
}
}
static inline void F_60 ( struct V_1 * V_2 ,
T_4 V_106 )
{
T_1 V_107 ;
switch ( V_2 -> V_16 . V_100 . type ) {
case V_101 :
V_107 = ( V_108 & V_106 ) ;
F_56 ( & V_2 -> V_16 , V_109 , V_107 ) ;
break;
case V_103 :
case V_104 :
V_107 = ( V_106 & 0xFFFFFFFF ) ;
F_56 ( & V_2 -> V_16 , F_61 ( 0 ) , V_107 ) ;
V_107 = ( V_106 >> 32 ) ;
F_56 ( & V_2 -> V_16 , F_61 ( 1 ) , V_107 ) ;
break;
default:
break;
}
}
void F_62 ( struct V_49 * V_110 ,
struct V_51 * V_52 )
{
if ( V_52 -> V_81 ) {
F_63 ( V_52 -> V_81 ) ;
if ( F_44 ( V_52 , V_74 ) )
F_64 ( V_110 -> V_65 ,
F_43 ( V_52 , V_73 ) ,
F_44 ( V_52 , V_74 ) ,
V_111 ) ;
} else if ( F_44 ( V_52 , V_74 ) ) {
F_65 ( V_110 -> V_65 ,
F_43 ( V_52 , V_73 ) ,
F_44 ( V_52 , V_74 ) ,
V_111 ) ;
}
V_52 -> V_75 = NULL ;
V_52 -> V_81 = NULL ;
F_66 ( V_52 , V_74 , 0 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_112 * V_113 = & V_2 -> V_114 ;
int V_40 ;
T_1 V_84 ;
if ( ( V_16 -> V_115 . V_116 != V_117 ) &&
( V_16 -> V_115 . V_116 != V_118 ) )
return;
switch ( V_16 -> V_100 . type ) {
case V_101 :
V_84 = F_22 ( V_16 , V_119 ) ;
break;
default:
V_84 = F_22 ( V_16 , V_120 ) ;
}
V_113 -> V_121 += V_84 ;
if ( ! V_84 )
return;
for ( V_40 = 0 ; V_40 < V_2 -> V_69 ; V_40 ++ )
F_19 ( V_122 ,
& V_2 -> V_50 [ V_40 ] -> V_35 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_112 * V_113 = & V_2 -> V_114 ;
T_1 V_123 [ 8 ] = { 0 } ;
T_6 V_124 ;
int V_40 ;
bool V_125 = V_2 -> V_126 . V_127 ;
if ( V_2 -> V_128 )
V_125 |= ! ! ( V_2 -> V_128 -> V_125 ) ;
if ( ! ( V_2 -> V_129 & V_130 ) || ! V_125 ) {
F_67 ( V_2 ) ;
return;
}
for ( V_40 = 0 ; V_40 < V_131 ; V_40 ++ ) {
T_1 V_132 ;
switch ( V_16 -> V_100 . type ) {
case V_101 :
V_132 = F_22 ( V_16 , F_69 ( V_40 ) ) ;
break;
default:
V_132 = F_22 ( V_16 , F_70 ( V_40 ) ) ;
}
V_113 -> V_132 [ V_40 ] += V_132 ;
V_124 = F_71 ( V_2 -> V_47 , V_40 ) ;
V_123 [ V_124 ] += V_132 ;
}
for ( V_40 = 0 ; V_40 < V_2 -> V_69 ; V_40 ++ ) {
struct V_49 * V_50 = V_2 -> V_50 [ V_40 ] ;
V_124 = V_50 -> V_133 ;
if ( V_123 [ V_124 ] )
F_19 ( V_122 , & V_50 -> V_35 ) ;
}
}
static T_4 F_72 ( struct V_49 * V_110 )
{
return V_110 -> V_114 . V_134 ;
}
static T_4 F_73 ( struct V_49 * V_110 )
{
struct V_1 * V_2 = F_74 ( V_110 -> V_47 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_135 = F_22 ( V_16 , F_33 ( V_110 -> V_136 ) ) ;
T_1 V_137 = F_22 ( V_16 , F_34 ( V_110 -> V_136 ) ) ;
if ( V_135 != V_137 )
return ( V_135 < V_137 ) ?
V_137 - V_135 : ( V_137 + V_110 -> V_80 - V_135 ) ;
return 0 ;
}
static inline bool F_75 ( struct V_49 * V_50 )
{
T_1 V_138 = F_72 ( V_50 ) ;
T_1 V_139 = V_50 -> V_140 . V_139 ;
T_1 V_141 = F_73 ( V_50 ) ;
bool V_142 = false ;
F_76 ( V_50 ) ;
if ( ( V_139 == V_138 ) && V_141 ) {
V_142 = F_14 ( V_122 ,
& V_50 -> V_35 ) ;
} else {
V_50 -> V_140 . V_139 = V_138 ;
F_19 ( V_122 , & V_50 -> V_35 ) ;
}
return V_142 ;
}
static void F_77 ( struct V_1 * V_2 )
{
if ( ! F_13 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_143 |= V_144 ;
F_78 ( V_145 , L_59 ) ;
F_12 ( V_2 ) ;
}
}
static bool F_79 ( struct V_146 * V_147 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = V_147 -> V_2 ;
struct V_51 * V_52 ;
union V_53 * V_54 ;
unsigned int V_148 = 0 , V_149 = 0 ;
unsigned int V_150 = V_147 -> V_151 . V_152 ;
unsigned int V_40 = V_50 -> V_71 ;
if ( F_13 ( V_34 , & V_2 -> V_35 ) )
return true ;
V_52 = & V_50 -> V_70 [ V_40 ] ;
V_54 = F_46 ( V_50 , V_40 ) ;
V_40 -= V_50 -> V_80 ;
do {
union V_53 * V_153 = V_52 -> V_75 ;
if ( ! V_153 )
break;
F_80 () ;
if ( ! ( V_153 -> V_86 . V_154 & F_81 ( V_155 ) ) )
break;
V_52 -> V_75 = NULL ;
V_148 += V_52 -> V_156 ;
V_149 += V_52 -> V_157 ;
F_63 ( V_52 -> V_81 ) ;
F_64 ( V_50 -> V_65 ,
F_43 ( V_52 , V_73 ) ,
F_44 ( V_52 , V_74 ) ,
V_111 ) ;
V_52 -> V_81 = NULL ;
F_66 ( V_52 , V_74 , 0 ) ;
while ( V_54 != V_153 ) {
V_52 ++ ;
V_54 ++ ;
V_40 ++ ;
if ( F_82 ( ! V_40 ) ) {
V_40 -= V_50 -> V_80 ;
V_52 = V_50 -> V_70 ;
V_54 = F_46 ( V_50 , 0 ) ;
}
if ( F_44 ( V_52 , V_74 ) ) {
F_65 ( V_50 -> V_65 ,
F_43 ( V_52 , V_73 ) ,
F_44 ( V_52 , V_74 ) ,
V_111 ) ;
F_66 ( V_52 , V_74 , 0 ) ;
}
}
V_52 ++ ;
V_54 ++ ;
V_40 ++ ;
if ( F_82 ( ! V_40 ) ) {
V_40 -= V_50 -> V_80 ;
V_52 = V_50 -> V_70 ;
V_54 = F_46 ( V_50 , 0 ) ;
}
F_83 ( V_54 ) ;
V_150 -- ;
} while ( F_84 ( V_150 ) );
V_40 += V_50 -> V_80 ;
V_50 -> V_71 = V_40 ;
F_85 ( & V_50 -> V_158 ) ;
V_50 -> V_114 . V_159 += V_148 ;
V_50 -> V_114 . V_134 += V_149 ;
F_86 ( & V_50 -> V_158 ) ;
V_147 -> V_151 . V_148 += V_148 ;
V_147 -> V_151 . V_149 += V_149 ;
if ( F_87 ( V_50 ) && F_75 ( V_50 ) ) {
struct V_15 * V_16 = & V_2 -> V_16 ;
F_88 ( V_145 , L_60
L_61
L_62
L_63
L_64
L_65
L_66
L_67 ,
V_50 -> V_78 ,
F_22 ( V_16 , F_33 ( V_50 -> V_136 ) ) ,
F_22 ( V_16 , F_34 ( V_50 -> V_136 ) ) ,
V_50 -> V_72 , V_40 ,
V_50 -> V_70 [ V_40 ] . V_76 , V_160 ) ;
F_89 ( V_50 -> V_47 , V_50 -> V_78 ) ;
F_90 ( V_161 ,
L_68 ,
V_2 -> V_162 + 1 , V_50 -> V_78 ) ;
F_77 ( V_2 ) ;
return true ;
}
F_91 ( F_92 ( V_50 ) ,
V_149 , V_148 ) ;
#define F_93 (DESC_NEEDED * 2)
if ( F_82 ( V_149 && F_94 ( V_50 -> V_47 ) &&
( F_95 ( V_50 ) >= F_93 ) ) ) {
F_96 () ;
if ( F_97 ( V_50 -> V_47 ,
V_50 -> V_78 )
&& ! F_13 ( V_34 , & V_2 -> V_35 ) ) {
F_98 ( V_50 -> V_47 ,
V_50 -> V_78 ) ;
++ V_50 -> V_140 . V_163 ;
}
}
return ! ! V_150 ;
}
static void F_99 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
int V_164 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_165 = F_100 ( V_50 -> V_65 , V_164 ) ;
T_2 V_166 ;
switch ( V_16 -> V_100 . type ) {
case V_101 :
V_166 = F_101 ( V_50 -> V_136 ) ;
break;
case V_103 :
case V_104 :
V_166 = F_102 ( V_50 -> V_136 ) ;
V_165 <<= V_167 ;
break;
default:
return;
}
V_165 |= V_168 |
V_169 |
V_170 ;
F_56 ( V_16 , V_166 , V_165 ) ;
}
static void F_103 ( struct V_1 * V_2 ,
struct V_49 * V_59 ,
int V_164 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_171 = F_100 ( V_59 -> V_65 , V_164 ) ;
T_6 V_136 = V_59 -> V_136 ;
switch ( V_16 -> V_100 . type ) {
case V_103 :
case V_104 :
V_171 <<= V_172 ;
break;
default:
break;
}
V_171 |= V_173 |
V_174 ;
F_56 ( V_16 , F_23 ( V_136 ) , V_171 ) ;
}
static void F_104 ( struct V_146 * V_147 )
{
struct V_1 * V_2 = V_147 -> V_2 ;
struct V_49 * V_110 ;
int V_164 = F_105 () ;
if ( V_147 -> V_164 == V_164 )
goto V_175;
F_106 (ring, q_vector->tx)
F_99 ( V_2 , V_110 , V_164 ) ;
F_106 (ring, q_vector->rx)
F_103 ( V_2 , V_110 , V_164 ) ;
V_147 -> V_164 = V_164 ;
V_175:
F_107 () ;
}
static void F_108 ( struct V_1 * V_2 )
{
int V_40 ;
if ( ! ( V_2 -> V_129 & V_176 ) )
return;
F_56 ( & V_2 -> V_16 , V_177 , 2 ) ;
for ( V_40 = 0 ; V_40 < V_2 -> V_178 ; V_40 ++ ) {
V_2 -> V_147 [ V_40 ] -> V_164 = - 1 ;
F_104 ( V_2 -> V_147 [ V_40 ] ) ;
}
}
static int F_109 ( struct V_179 * V_65 , void * V_84 )
{
struct V_1 * V_2 = F_110 ( V_65 ) ;
unsigned long V_180 = * ( unsigned long * ) V_84 ;
if ( ! ( V_2 -> V_129 & V_181 ) )
return 0 ;
switch ( V_180 ) {
case V_182 :
if ( V_2 -> V_129 & V_176 )
break;
if ( F_111 ( V_65 ) == 0 ) {
V_2 -> V_129 |= V_176 ;
F_108 ( V_2 ) ;
break;
}
case V_183 :
if ( V_2 -> V_129 & V_176 ) {
F_112 ( V_65 ) ;
V_2 -> V_129 &= ~ V_176 ;
F_56 ( & V_2 -> V_16 , V_177 , 1 ) ;
}
break;
}
return 0 ;
}
static inline void F_113 ( struct V_49 * V_110 ,
union V_60 * V_61 ,
struct V_184 * V_81 )
{
if ( V_110 -> V_47 -> V_185 & V_186 )
V_81 -> V_187 = F_52 ( V_61 -> V_86 . V_188 . V_189 . V_190 ) ;
}
static inline bool F_114 ( struct V_49 * V_110 ,
union V_60 * V_61 )
{
T_7 V_191 = V_61 -> V_86 . V_188 . V_192 . V_193 . V_191 ;
return F_13 ( V_194 , & V_110 -> V_35 ) &&
( ( V_191 & F_115 ( V_195 ) ) ==
( F_115 ( V_196 <<
V_197 ) ) ) ;
}
static inline void F_116 ( struct V_49 * V_110 ,
union V_60 * V_61 ,
struct V_184 * V_81 )
{
F_117 ( V_81 ) ;
if ( ! ( V_110 -> V_47 -> V_185 & V_198 ) )
return;
if ( F_118 ( V_61 , V_199 ) &&
F_118 ( V_61 , V_200 ) ) {
V_110 -> V_201 . V_202 ++ ;
return;
}
if ( ! F_118 ( V_61 , V_203 ) )
return;
if ( F_118 ( V_61 , V_204 ) ) {
T_7 V_191 = V_61 -> V_86 . V_188 . V_192 . V_193 . V_191 ;
if ( ( V_191 & F_115 ( V_205 ) ) &&
F_13 ( V_206 , & V_110 -> V_35 ) )
return;
V_110 -> V_201 . V_202 ++ ;
return;
}
V_81 -> V_207 = V_208 ;
}
static inline void F_119 ( struct V_49 * V_59 , T_1 V_209 )
{
V_59 -> V_72 = V_209 ;
V_59 -> V_210 = V_209 ;
F_120 () ;
F_121 ( V_209 , V_59 -> V_137 ) ;
}
static bool F_122 ( struct V_49 * V_59 ,
struct V_62 * V_211 )
{
struct V_90 * V_90 = V_211 -> V_90 ;
T_8 V_73 = V_211 -> V_73 ;
if ( F_84 ( V_73 ) )
return true ;
if ( F_84 ( ! V_90 ) ) {
V_90 = F_123 ( V_212 | V_213 | V_214 ,
V_211 -> V_81 , F_124 ( V_59 ) ) ;
if ( F_82 ( ! V_90 ) ) {
V_59 -> V_201 . V_215 ++ ;
return false ;
}
V_211 -> V_90 = V_90 ;
}
V_73 = F_125 ( V_59 -> V_65 , V_90 , 0 ,
F_126 ( V_59 ) , V_216 ) ;
if ( F_127 ( V_59 -> V_65 , V_73 ) ) {
F_128 ( V_90 , F_124 ( V_59 ) ) ;
V_211 -> V_90 = NULL ;
V_59 -> V_201 . V_215 ++ ;
return false ;
}
V_211 -> V_73 = V_73 ;
V_211 -> V_91 = 0 ;
return true ;
}
void F_129 ( struct V_49 * V_59 , T_2 V_217 )
{
union V_60 * V_61 ;
struct V_62 * V_211 ;
T_2 V_40 = V_59 -> V_72 ;
if ( ! V_217 )
return;
V_61 = F_51 ( V_59 , V_40 ) ;
V_211 = & V_59 -> V_63 [ V_40 ] ;
V_40 -= V_59 -> V_80 ;
do {
if ( ! F_122 ( V_59 , V_211 ) )
break;
V_61 -> V_218 . V_219 = F_130 ( V_211 -> V_73 + V_211 -> V_91 ) ;
V_61 ++ ;
V_211 ++ ;
V_40 ++ ;
if ( F_82 ( ! V_40 ) ) {
V_61 = F_51 ( V_59 , 0 ) ;
V_211 = V_59 -> V_63 ;
V_40 -= V_59 -> V_80 ;
}
V_61 -> V_218 . V_220 = 0 ;
V_217 -- ;
} while ( V_217 );
V_40 += V_59 -> V_80 ;
if ( V_59 -> V_72 != V_40 )
F_119 ( V_59 , V_40 ) ;
}
static unsigned int F_131 ( unsigned char * V_84 ,
unsigned int V_221 )
{
union {
unsigned char * V_222 ;
struct V_223 * V_224 ;
struct V_225 * V_226 ;
struct V_227 * V_228 ;
struct V_229 * V_230 ;
} V_231 ;
T_9 V_232 ;
T_6 V_233 = 0 ;
T_6 V_234 ;
if ( V_221 < V_235 )
return V_221 ;
V_231 . V_222 = V_84 ;
V_232 = V_231 . V_224 -> V_236 ;
V_231 . V_222 += V_235 ;
if ( V_232 == F_132 ( V_237 ) ) {
if ( ( V_231 . V_222 - V_84 ) > ( V_221 - V_238 ) )
return V_221 ;
V_232 = V_231 . V_226 -> V_239 ;
V_231 . V_222 += V_238 ;
}
if ( V_232 == F_132 ( V_240 ) ) {
if ( ( V_231 . V_222 - V_84 ) > ( V_221 - sizeof( struct V_227 ) ) )
return V_221 ;
V_234 = ( V_231 . V_222 [ 0 ] & 0x0F ) << 2 ;
if ( V_234 < sizeof( struct V_227 ) )
return V_231 . V_222 - V_84 ;
if ( ! ( V_231 . V_228 -> V_241 & F_133 ( V_242 ) ) )
V_233 = V_231 . V_228 -> V_232 ;
} else if ( V_232 == F_132 ( V_243 ) ) {
if ( ( V_231 . V_222 - V_84 ) > ( V_221 - sizeof( struct V_229 ) ) )
return V_221 ;
V_233 = V_231 . V_230 -> V_233 ;
V_234 = sizeof( struct V_229 ) ;
#ifdef F_134
} else if ( V_232 == F_132 ( V_244 ) ) {
if ( ( V_231 . V_222 - V_84 ) > ( V_221 - V_245 ) )
return V_221 ;
V_234 = V_245 ;
#endif
} else {
return V_231 . V_222 - V_84 ;
}
V_231 . V_222 += V_234 ;
if ( V_233 == V_246 ) {
if ( ( V_231 . V_222 - V_84 ) > ( V_221 - sizeof( struct V_247 ) ) )
return V_221 ;
V_234 = ( V_231 . V_222 [ 12 ] & 0xF0 ) >> 2 ;
if ( V_234 < sizeof( struct V_247 ) )
return V_231 . V_222 - V_84 ;
V_231 . V_222 += V_234 ;
} else if ( V_233 == V_248 ) {
if ( ( V_231 . V_222 - V_84 ) > ( V_221 - sizeof( struct V_249 ) ) )
return V_221 ;
V_231 . V_222 += sizeof( struct V_249 ) ;
}
if ( ( V_231 . V_222 - V_84 ) < V_221 )
return V_231 . V_222 - V_84 ;
else
return V_221 ;
}
static void F_135 ( struct V_49 * V_110 ,
struct V_184 * V_81 )
{
T_2 V_250 = F_136 ( V_81 ) ;
F_137 ( V_81 ) -> V_251 = F_138 ( ( V_81 -> V_74 - V_250 ) ,
F_139 ( V_81 ) -> V_252 ) ;
F_137 ( V_81 ) -> V_253 = V_254 ;
}
static void F_140 ( struct V_49 * V_59 ,
struct V_184 * V_81 )
{
if ( ! F_139 ( V_81 ) -> V_252 )
return;
V_59 -> V_201 . V_255 += F_139 ( V_81 ) -> V_252 ;
V_59 -> V_201 . V_256 ++ ;
F_135 ( V_59 , V_81 ) ;
F_139 ( V_81 ) -> V_252 = 0 ;
}
static void F_141 ( struct V_49 * V_59 ,
union V_60 * V_61 ,
struct V_184 * V_81 )
{
struct V_46 * V_65 = V_59 -> V_47 ;
F_140 ( V_59 , V_81 ) ;
F_113 ( V_59 , V_61 , V_81 ) ;
F_116 ( V_59 , V_61 , V_81 ) ;
F_142 ( V_59 , V_61 , V_81 ) ;
if ( ( V_65 -> V_185 & V_257 ) &&
F_118 ( V_61 , V_258 ) ) {
T_2 V_259 = F_143 ( V_61 -> V_86 . V_87 . V_226 ) ;
F_144 ( V_81 , F_133 ( V_237 ) , V_259 ) ;
}
F_145 ( V_81 , V_59 -> V_78 ) ;
V_81 -> V_232 = F_146 ( V_81 , V_65 ) ;
}
static void F_147 ( struct V_146 * V_147 ,
struct V_184 * V_81 )
{
struct V_1 * V_2 = V_147 -> V_2 ;
if ( F_148 ( V_147 ) )
F_149 ( V_81 ) ;
else if ( ! ( V_2 -> V_129 & V_260 ) )
F_150 ( & V_147 -> V_261 , V_81 ) ;
else
F_151 ( V_81 ) ;
}
static bool F_152 ( struct V_49 * V_59 ,
union V_60 * V_61 ,
struct V_184 * V_81 )
{
T_1 V_262 = V_59 -> V_71 + 1 ;
V_262 = ( V_262 < V_59 -> V_80 ) ? V_262 : 0 ;
V_59 -> V_71 = V_262 ;
F_83 ( F_51 ( V_59 , V_262 ) ) ;
if ( F_153 ( V_59 ) ) {
T_10 V_263 = V_61 -> V_86 . V_188 . V_192 . V_84 &
F_81 ( V_264 ) ;
if ( F_82 ( V_263 ) ) {
T_1 V_265 = F_52 ( V_263 ) ;
V_265 >>= V_266 ;
F_139 ( V_81 ) -> V_252 += V_265 - 1 ;
V_262 = F_52 ( V_61 -> V_86 . V_87 . V_88 ) ;
V_262 &= V_267 ;
V_262 >>= V_268 ;
}
}
if ( F_84 ( F_118 ( V_61 , V_269 ) ) )
return false ;
V_59 -> V_63 [ V_262 ] . V_81 = V_81 ;
V_59 -> V_201 . V_270 ++ ;
return true ;
}
static void F_154 ( struct V_49 * V_59 ,
struct V_184 * V_81 )
{
struct V_271 * V_272 = & F_137 ( V_81 ) -> V_273 [ 0 ] ;
unsigned char * V_274 ;
unsigned int V_275 ;
V_274 = F_155 ( V_272 ) ;
V_275 = F_131 ( V_274 , V_276 ) ;
F_156 ( V_81 , V_274 , F_157 ( V_275 , sizeof( long ) ) ) ;
F_158 ( V_272 , V_275 ) ;
V_272 -> V_91 += V_275 ;
V_81 -> V_277 -= V_275 ;
V_81 -> V_137 += V_275 ;
}
static void F_159 ( struct V_49 * V_59 ,
struct V_184 * V_81 )
{
if ( F_82 ( F_139 ( V_81 ) -> V_278 ) ) {
F_65 ( V_59 -> V_65 , F_139 ( V_81 ) -> V_73 ,
F_126 ( V_59 ) , V_216 ) ;
F_139 ( V_81 ) -> V_278 = false ;
} else {
struct V_271 * V_272 = & F_137 ( V_81 ) -> V_273 [ 0 ] ;
F_160 ( V_59 -> V_65 ,
F_139 ( V_81 ) -> V_73 ,
V_272 -> V_91 ,
F_54 ( V_59 ) ,
V_216 ) ;
}
F_139 ( V_81 ) -> V_73 = 0 ;
}
static bool F_161 ( struct V_49 * V_59 ,
union V_60 * V_61 ,
struct V_184 * V_81 )
{
struct V_46 * V_47 = V_59 -> V_47 ;
if ( F_82 ( F_118 ( V_61 ,
V_279 ) &&
! ( V_47 -> V_185 & V_280 ) ) ) {
F_63 ( V_81 ) ;
return true ;
}
if ( F_162 ( V_81 ) )
F_154 ( V_59 , V_81 ) ;
#ifdef F_134
if ( F_114 ( V_59 , V_61 ) )
return false ;
#endif
if ( F_82 ( V_81 -> V_74 < 60 ) ) {
int V_281 = 60 - V_81 -> V_74 ;
if ( F_163 ( V_81 , V_281 ) )
return true ;
F_164 ( V_81 , V_281 ) ;
}
return false ;
}
static void F_165 ( struct V_49 * V_59 ,
struct V_62 * V_282 )
{
struct V_62 * V_283 ;
T_2 V_284 = V_59 -> V_210 ;
V_283 = & V_59 -> V_63 [ V_284 ] ;
V_284 ++ ;
V_59 -> V_210 = ( V_284 < V_59 -> V_80 ) ? V_284 : 0 ;
V_283 -> V_90 = V_282 -> V_90 ;
V_283 -> V_73 = V_282 -> V_73 ;
V_283 -> V_91 = V_282 -> V_91 ;
F_166 ( V_59 -> V_65 , V_283 -> V_73 ,
V_283 -> V_91 ,
F_54 ( V_59 ) ,
V_216 ) ;
}
static bool F_167 ( struct V_49 * V_59 ,
struct V_62 * V_285 ,
union V_60 * V_61 ,
struct V_184 * V_81 )
{
struct V_90 * V_90 = V_285 -> V_90 ;
unsigned int V_286 = F_143 ( V_61 -> V_86 . V_87 . V_287 ) ;
#if ( V_288 < 8192 )
unsigned int V_289 = F_54 ( V_59 ) ;
#else
unsigned int V_289 = F_157 ( V_286 , V_290 ) ;
unsigned int V_291 = F_126 ( V_59 ) -
F_54 ( V_59 ) ;
#endif
if ( ( V_286 <= V_276 ) && ! F_162 ( V_81 ) ) {
unsigned char * V_274 = F_53 ( V_90 ) + V_285 -> V_91 ;
memcpy ( F_164 ( V_81 , V_286 ) , V_274 , F_157 ( V_286 , sizeof( long ) ) ) ;
if ( F_84 ( F_168 ( V_90 ) == F_169 () ) )
return true ;
F_170 ( V_90 ) ;
return false ;
}
F_171 ( V_81 , F_137 ( V_81 ) -> V_292 , V_90 ,
V_285 -> V_91 , V_286 , V_289 ) ;
if ( F_82 ( F_168 ( V_90 ) != F_169 () ) )
return false ;
#if ( V_288 < 8192 )
if ( F_82 ( F_172 ( V_90 ) != 1 ) )
return false ;
V_285 -> V_91 ^= V_289 ;
F_173 ( & V_90 -> V_293 , 2 ) ;
#else
V_285 -> V_91 += V_289 ;
if ( V_285 -> V_91 > V_291 )
return false ;
F_174 ( V_90 ) ;
#endif
return true ;
}
static struct V_184 * F_175 ( struct V_49 * V_59 ,
union V_60 * V_61 )
{
struct V_62 * V_285 ;
struct V_184 * V_81 ;
struct V_90 * V_90 ;
V_285 = & V_59 -> V_63 [ V_59 -> V_71 ] ;
V_90 = V_285 -> V_90 ;
F_176 ( V_90 ) ;
V_81 = V_285 -> V_81 ;
if ( F_84 ( ! V_81 ) ) {
void * V_294 = F_53 ( V_90 ) +
V_285 -> V_91 ;
F_83 ( V_294 ) ;
#if V_290 < 128
F_83 ( V_294 + V_290 ) ;
#endif
V_81 = F_177 ( V_59 -> V_47 ,
V_276 ) ;
if ( F_82 ( ! V_81 ) ) {
V_59 -> V_201 . V_295 ++ ;
return NULL ;
}
F_176 ( V_81 -> V_84 ) ;
if ( F_84 ( F_118 ( V_61 , V_269 ) ) )
goto V_296;
F_139 ( V_81 ) -> V_73 = V_285 -> V_73 ;
} else {
if ( F_118 ( V_61 , V_269 ) )
F_159 ( V_59 , V_81 ) ;
V_296:
F_160 ( V_59 -> V_65 ,
V_285 -> V_73 ,
V_285 -> V_91 ,
F_54 ( V_59 ) ,
V_216 ) ;
}
if ( F_167 ( V_59 , V_285 , V_61 , V_81 ) ) {
F_165 ( V_59 , V_285 ) ;
} else if ( F_139 ( V_81 ) -> V_73 == V_285 -> V_73 ) {
F_139 ( V_81 ) -> V_278 = true ;
} else {
F_65 ( V_59 -> V_65 , V_285 -> V_73 ,
F_126 ( V_59 ) ,
V_216 ) ;
}
V_285 -> V_81 = NULL ;
V_285 -> V_73 = 0 ;
V_285 -> V_90 = NULL ;
return V_81 ;
}
static int F_178 ( struct V_146 * V_147 ,
struct V_49 * V_59 ,
const int V_150 )
{
unsigned int V_297 = 0 , V_298 = 0 ;
#ifdef F_134
struct V_1 * V_2 = V_147 -> V_2 ;
int V_299 ;
unsigned int V_300 = 0 ;
#endif
T_2 V_217 = F_95 ( V_59 ) ;
do {
union V_60 * V_61 ;
struct V_184 * V_81 ;
if ( V_217 >= V_301 ) {
F_129 ( V_59 , V_217 ) ;
V_217 = 0 ;
}
V_61 = F_51 ( V_59 , V_59 -> V_71 ) ;
if ( ! F_118 ( V_61 , V_89 ) )
break;
F_179 () ;
V_81 = F_175 ( V_59 , V_61 ) ;
if ( ! V_81 )
break;
V_217 ++ ;
if ( F_152 ( V_59 , V_61 , V_81 ) )
continue;
if ( F_161 ( V_59 , V_61 , V_81 ) )
continue;
V_297 += V_81 -> V_74 ;
F_141 ( V_59 , V_61 , V_81 ) ;
#ifdef F_134
if ( F_114 ( V_59 , V_61 ) ) {
V_299 = F_180 ( V_2 , V_61 , V_81 ) ;
if ( V_299 > 0 ) {
if ( ! V_300 ) {
V_300 = V_59 -> V_47 -> V_302 -
sizeof( struct V_303 ) -
sizeof( struct V_304 ) -
sizeof( struct V_305 ) ;
if ( V_300 > 512 )
V_300 &= ~ 511 ;
}
V_297 += V_299 ;
V_298 += F_138 ( V_299 ,
V_300 ) ;
}
if ( ! V_299 ) {
F_63 ( V_81 ) ;
continue;
}
}
#endif
F_181 ( V_81 , & V_147 -> V_261 ) ;
F_147 ( V_147 , V_81 ) ;
V_298 ++ ;
} while ( F_84 ( V_298 < V_150 ) );
F_85 ( & V_59 -> V_158 ) ;
V_59 -> V_114 . V_134 += V_298 ;
V_59 -> V_114 . V_159 += V_297 ;
F_86 ( & V_59 -> V_158 ) ;
V_147 -> V_306 . V_149 += V_298 ;
V_147 -> V_306 . V_148 += V_297 ;
if ( V_217 )
F_129 ( V_59 , V_217 ) ;
return V_298 ;
}
static int F_182 ( struct V_307 * V_261 )
{
struct V_146 * V_147 =
F_183 ( V_261 , struct V_146 , V_261 ) ;
struct V_1 * V_2 = V_147 -> V_2 ;
struct V_49 * V_110 ;
int V_308 = 0 ;
if ( F_13 ( V_34 , & V_2 -> V_35 ) )
return V_309 ;
if ( ! F_184 ( V_147 ) )
return V_310 ;
F_106 (ring, q_vector->rx) {
V_308 = F_178 ( V_147 , V_110 , 4 ) ;
#ifdef F_185
if ( V_308 )
V_110 -> V_114 . V_311 += V_308 ;
else
V_110 -> V_114 . V_312 ++ ;
#endif
if ( V_308 )
break;
}
F_186 ( V_147 ) ;
return V_308 ;
}
static void F_187 ( struct V_1 * V_2 )
{
struct V_146 * V_147 ;
int V_313 ;
T_1 V_107 ;
if ( V_2 -> V_314 > 32 ) {
T_1 V_315 = ( 1 << ( V_2 -> V_314 - 32 ) ) - 1 ;
F_56 ( & V_2 -> V_16 , V_316 , V_315 ) ;
}
for ( V_313 = 0 ; V_313 < V_2 -> V_178 ; V_313 ++ ) {
struct V_49 * V_110 ;
V_147 = V_2 -> V_147 [ V_313 ] ;
F_106 (ring, q_vector->rx)
F_58 ( V_2 , 0 , V_110 -> V_136 , V_313 ) ;
F_106 (ring, q_vector->tx)
F_58 ( V_2 , 1 , V_110 -> V_136 , V_313 ) ;
F_188 ( V_147 ) ;
}
switch ( V_2 -> V_16 . V_100 . type ) {
case V_101 :
F_58 ( V_2 , - 1 , V_317 ,
V_313 ) ;
break;
case V_103 :
case V_104 :
F_58 ( V_2 , - 1 , 1 , V_313 ) ;
break;
default:
break;
}
F_56 ( & V_2 -> V_16 , F_189 ( V_313 ) , 1950 ) ;
V_107 = V_318 ;
V_107 &= ~ ( V_319 |
V_320 |
V_321 ) ;
F_56 ( & V_2 -> V_16 , V_322 , V_107 ) ;
}
static void F_190 ( struct V_146 * V_147 ,
struct V_323 * V_324 )
{
int V_159 = V_324 -> V_148 ;
int V_134 = V_324 -> V_149 ;
T_1 V_325 ;
T_4 V_326 ;
T_6 V_327 = V_324 -> V_328 ;
if ( V_134 == 0 )
return;
V_325 = V_147 -> V_328 >> 2 ;
if ( V_325 == 0 )
return;
V_326 = V_159 / V_325 ;
switch ( V_327 ) {
case V_329 :
if ( V_326 > 10 )
V_327 = V_330 ;
break;
case V_330 :
if ( V_326 > 20 )
V_327 = V_331 ;
else if ( V_326 <= 10 )
V_327 = V_329 ;
break;
case V_331 :
if ( V_326 <= 20 )
V_327 = V_330 ;
break;
}
V_324 -> V_148 = 0 ;
V_324 -> V_149 = 0 ;
V_324 -> V_328 = V_327 ;
}
void F_188 ( struct V_146 * V_147 )
{
struct V_1 * V_2 = V_147 -> V_2 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_313 = V_147 -> V_313 ;
T_1 V_332 = V_147 -> V_328 & V_333 ;
switch ( V_2 -> V_16 . V_100 . type ) {
case V_101 :
V_332 |= ( V_332 << 16 ) ;
break;
case V_103 :
case V_104 :
V_332 |= V_334 ;
break;
default:
break;
}
F_56 ( V_16 , F_189 ( V_313 ) , V_332 ) ;
}
static void F_191 ( struct V_146 * V_147 )
{
T_1 V_335 = V_147 -> V_328 ;
T_6 V_336 ;
F_190 ( V_147 , & V_147 -> V_151 ) ;
F_190 ( V_147 , & V_147 -> V_306 ) ;
V_336 = F_192 ( V_147 -> V_306 . V_328 , V_147 -> V_151 . V_328 ) ;
switch ( V_336 ) {
case V_329 :
V_335 = V_337 ;
break;
case V_330 :
V_335 = V_338 ;
break;
case V_331 :
V_335 = V_339 ;
break;
default:
break;
}
if ( V_335 != V_147 -> V_328 ) {
V_335 = ( 10 * V_335 * V_147 -> V_328 ) /
( ( 9 * V_335 ) + V_147 -> V_328 ) ;
V_147 -> V_328 = V_335 ;
F_188 ( V_147 ) ;
}
}
static void F_193 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_340 = V_2 -> V_341 ;
if ( F_13 ( V_34 , & V_2 -> V_35 ) )
return;
if ( ! ( V_2 -> V_143 & V_342 ) &&
! ( V_2 -> V_143 & V_343 ) )
return;
V_2 -> V_143 &= ~ V_343 ;
switch ( V_16 -> V_22 ) {
case V_344 :
if ( ! ( V_340 & V_345 ) &&
! ( V_340 & V_346 ) )
return;
if ( ! ( V_340 & V_346 ) && V_16 -> V_100 . V_347 . V_348 ) {
T_1 V_21 ;
bool V_349 = false ;
V_16 -> V_100 . V_347 . V_348 ( V_16 , & V_21 , & V_349 , false ) ;
if ( V_349 )
return;
}
if ( V_16 -> V_350 . V_347 . V_351 ( V_16 ) != V_352 )
return;
break;
default:
if ( ! ( V_340 & V_345 ) )
return;
break;
}
F_194 ( V_145 ,
L_69
L_70
L_71 ) ;
V_2 -> V_341 = 0 ;
}
static void F_195 ( struct V_1 * V_2 , T_1 V_340 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
if ( ( V_2 -> V_129 & V_353 ) &&
( V_340 & V_354 ) ) {
F_194 ( V_161 , L_72 ) ;
F_56 ( V_16 , V_355 , V_354 ) ;
}
}
static void F_196 ( struct V_1 * V_2 , T_1 V_340 )
{
if ( ! ( V_2 -> V_143 & V_342 ) )
return;
switch ( V_2 -> V_16 . V_100 . type ) {
case V_103 :
if ( ( ( V_340 & V_345 ) || ( V_340 & V_346 ) ) &&
( ! F_13 ( V_34 , & V_2 -> V_35 ) ) ) {
V_2 -> V_341 = V_340 ;
V_2 -> V_143 |= V_343 ;
F_12 ( V_2 ) ;
return;
}
return;
case V_104 :
if ( ! ( V_340 & V_356 ) )
return;
break;
default:
return;
}
F_194 ( V_145 ,
L_69
L_70
L_71 ) ;
}
static void F_197 ( struct V_1 * V_2 , T_1 V_340 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
if ( V_340 & V_357 ) {
F_56 ( V_16 , V_355 , V_357 ) ;
if ( ! F_13 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_143 |= V_358 ;
F_12 ( V_2 ) ;
}
}
if ( V_340 & V_354 ) {
F_56 ( V_16 , V_355 , V_354 ) ;
if ( ! F_13 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_129 |= V_359 ;
F_12 ( V_2 ) ;
}
}
}
static void F_198 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
V_2 -> V_360 ++ ;
V_2 -> V_129 |= V_361 ;
V_2 -> V_362 = V_160 ;
if ( ! F_13 ( V_34 , & V_2 -> V_35 ) ) {
F_56 ( V_16 , V_363 , V_364 ) ;
F_199 ( V_16 ) ;
F_12 ( V_2 ) ;
}
}
static inline void F_200 ( struct V_1 * V_2 ,
T_4 V_106 )
{
T_1 V_107 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
switch ( V_16 -> V_100 . type ) {
case V_101 :
V_107 = ( V_108 & V_106 ) ;
F_56 ( V_16 , V_365 , V_107 ) ;
break;
case V_103 :
case V_104 :
V_107 = ( V_106 & 0xFFFFFFFF ) ;
if ( V_107 )
F_56 ( V_16 , F_201 ( 0 ) , V_107 ) ;
V_107 = ( V_106 >> 32 ) ;
if ( V_107 )
F_56 ( V_16 , F_201 ( 1 ) , V_107 ) ;
break;
default:
break;
}
}
static inline void F_202 ( struct V_1 * V_2 ,
T_4 V_106 )
{
T_1 V_107 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
switch ( V_16 -> V_100 . type ) {
case V_101 :
V_107 = ( V_108 & V_106 ) ;
F_56 ( V_16 , V_363 , V_107 ) ;
break;
case V_103 :
case V_104 :
V_107 = ( V_106 & 0xFFFFFFFF ) ;
if ( V_107 )
F_56 ( V_16 , F_203 ( 0 ) , V_107 ) ;
V_107 = ( V_106 >> 32 ) ;
if ( V_107 )
F_56 ( V_16 , F_203 ( 1 ) , V_107 ) ;
break;
default:
break;
}
}
static inline void F_204 ( struct V_1 * V_2 , bool V_366 ,
bool V_367 )
{
T_1 V_107 = ( V_318 & ~ V_108 ) ;
if ( V_2 -> V_129 & V_361 )
V_107 &= ~ V_321 ;
if ( V_2 -> V_143 & V_342 )
switch ( V_2 -> V_16 . V_100 . type ) {
case V_103 :
V_107 |= V_368 ;
break;
case V_104 :
V_107 |= V_369 ;
break;
default:
break;
}
if ( V_2 -> V_129 & V_353 )
V_107 |= V_370 ;
switch ( V_2 -> V_16 . V_100 . type ) {
case V_103 :
V_107 |= V_370 ;
V_107 |= V_371 ;
case V_104 :
V_107 |= V_372 ;
V_107 |= V_320 ;
break;
default:
break;
}
if ( V_2 -> V_16 . V_100 . type == V_104 )
V_107 |= V_373 ;
if ( ( V_2 -> V_129 & V_374 ) &&
! ( V_2 -> V_143 & V_375 ) )
V_107 |= V_376 ;
F_56 ( & V_2 -> V_16 , V_365 , V_107 ) ;
if ( V_366 )
F_200 ( V_2 , ~ 0 ) ;
if ( V_367 )
F_199 ( & V_2 -> V_16 ) ;
}
static T_11 F_205 ( int V_377 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_340 ;
V_340 = F_22 ( V_16 , V_109 ) ;
V_340 &= 0xFFFF0000 ;
F_56 ( V_16 , V_355 , V_340 ) ;
if ( V_340 & V_346 )
F_198 ( V_2 ) ;
if ( V_340 & V_378 )
F_206 ( V_2 ) ;
switch ( V_16 -> V_100 . type ) {
case V_103 :
case V_104 :
if ( V_340 & V_379 )
F_90 ( V_380 , L_73
L_74 ) ;
if ( V_340 & V_381 ) {
int V_382 = 0 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_2 -> V_69 ; V_40 ++ ) {
struct V_49 * V_110 = V_2 -> V_50 [ V_40 ] ;
if ( F_207 ( V_383 ,
& V_110 -> V_35 ) )
V_382 ++ ;
}
if ( V_382 ) {
F_56 ( V_16 , V_363 , V_384 ) ;
V_2 -> V_143 |= V_375 ;
F_12 ( V_2 ) ;
}
}
F_197 ( V_2 , V_340 ) ;
F_196 ( V_2 , V_340 ) ;
break;
default:
break;
}
F_195 ( V_2 , V_340 ) ;
if ( F_82 ( V_340 & V_385 ) )
F_208 ( V_2 , V_340 ) ;
if ( ! F_13 ( V_34 , & V_2 -> V_35 ) )
F_204 ( V_2 , false , false ) ;
return V_386 ;
}
static T_11 F_209 ( int V_377 , void * V_84 )
{
struct V_146 * V_147 = V_84 ;
if ( V_147 -> V_306 . V_110 || V_147 -> V_151 . V_110 )
F_210 ( & V_147 -> V_261 ) ;
return V_386 ;
}
int F_211 ( struct V_307 * V_261 , int V_150 )
{
struct V_146 * V_147 =
F_183 ( V_261 , struct V_146 , V_261 ) ;
struct V_1 * V_2 = V_147 -> V_2 ;
struct V_49 * V_110 ;
int V_387 ;
bool V_388 = true ;
#ifdef F_212
if ( V_2 -> V_129 & V_176 )
F_104 ( V_147 ) ;
#endif
F_106 (ring, q_vector->tx)
V_388 &= ! ! F_79 ( V_147 , V_110 ) ;
if ( ! F_213 ( V_147 ) )
return V_150 ;
if ( V_147 -> V_306 . V_80 > 1 )
V_387 = F_192 ( V_150 / V_147 -> V_306 . V_80 , 1 ) ;
else
V_387 = V_150 ;
F_106 (ring, q_vector->rx)
V_388 &= ( F_178 ( V_147 , V_110 ,
V_387 ) < V_387 ) ;
F_214 ( V_147 ) ;
if ( ! V_388 )
return V_150 ;
F_215 ( V_261 ) ;
if ( V_2 -> V_389 & 1 )
F_191 ( V_147 ) ;
if ( ! F_13 ( V_34 , & V_2 -> V_35 ) )
F_200 ( V_2 , ( ( T_4 ) 1 << V_147 -> V_313 ) ) ;
return 0 ;
}
static int F_216 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
int V_390 , V_18 ;
int V_391 = 0 , V_392 = 0 ;
for ( V_390 = 0 ; V_390 < V_2 -> V_178 ; V_390 ++ ) {
struct V_146 * V_147 = V_2 -> V_147 [ V_390 ] ;
struct V_393 * V_394 = & V_2 -> V_395 [ V_390 ] ;
if ( V_147 -> V_151 . V_110 && V_147 -> V_306 . V_110 ) {
snprintf ( V_147 -> V_45 , sizeof( V_147 -> V_45 ) - 1 ,
L_75 , V_47 -> V_45 , L_76 , V_391 ++ ) ;
V_392 ++ ;
} else if ( V_147 -> V_306 . V_110 ) {
snprintf ( V_147 -> V_45 , sizeof( V_147 -> V_45 ) - 1 ,
L_75 , V_47 -> V_45 , L_77 , V_391 ++ ) ;
} else if ( V_147 -> V_151 . V_110 ) {
snprintf ( V_147 -> V_45 , sizeof( V_147 -> V_45 ) - 1 ,
L_75 , V_47 -> V_45 , L_78 , V_392 ++ ) ;
} else {
continue;
}
V_18 = F_217 ( V_394 -> V_390 , & F_209 , 0 ,
V_147 -> V_45 , V_147 ) ;
if ( V_18 ) {
F_88 ( V_161 , L_79
L_80 , V_18 ) ;
goto V_396;
}
if ( V_2 -> V_129 & V_374 ) {
F_218 ( V_394 -> V_390 ,
& V_147 -> V_397 ) ;
}
}
V_18 = F_217 ( V_2 -> V_395 [ V_390 ] . V_390 ,
F_205 , 0 , V_47 -> V_45 , V_2 ) ;
if ( V_18 ) {
F_88 ( V_161 , L_81 , V_18 ) ;
goto V_396;
}
return 0 ;
V_396:
while ( V_390 ) {
V_390 -- ;
F_218 ( V_2 -> V_395 [ V_390 ] . V_390 ,
NULL ) ;
F_219 ( V_2 -> V_395 [ V_390 ] . V_390 ,
V_2 -> V_147 [ V_390 ] ) ;
}
V_2 -> V_129 &= ~ V_398 ;
F_220 ( V_2 -> V_10 ) ;
F_221 ( V_2 -> V_395 ) ;
V_2 -> V_395 = NULL ;
return V_18 ;
}
static T_11 F_222 ( int V_377 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_146 * V_147 = V_2 -> V_147 [ 0 ] ;
T_1 V_340 ;
F_56 ( V_16 , V_363 , V_399 ) ;
V_340 = F_22 ( V_16 , V_355 ) ;
if ( ! V_340 ) {
if ( ! F_13 ( V_34 , & V_2 -> V_35 ) )
F_204 ( V_2 , true , true ) ;
return V_400 ;
}
if ( V_340 & V_346 )
F_198 ( V_2 ) ;
switch ( V_16 -> V_100 . type ) {
case V_103 :
F_197 ( V_2 , V_340 ) ;
case V_104 :
if ( V_340 & V_379 )
F_90 ( V_380 , L_82
L_74 ) ;
F_196 ( V_2 , V_340 ) ;
break;
default:
break;
}
F_195 ( V_2 , V_340 ) ;
if ( F_82 ( V_340 & V_385 ) )
F_208 ( V_2 , V_340 ) ;
F_210 ( & V_147 -> V_261 ) ;
if ( ! F_13 ( V_34 , & V_2 -> V_35 ) )
F_204 ( V_2 , false , false ) ;
return V_386 ;
}
static int F_223 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
int V_18 ;
if ( V_2 -> V_129 & V_398 )
V_18 = F_216 ( V_2 ) ;
else if ( V_2 -> V_129 & V_401 )
V_18 = F_217 ( V_2 -> V_10 -> V_377 , F_222 , 0 ,
V_47 -> V_45 , V_2 ) ;
else
V_18 = F_217 ( V_2 -> V_10 -> V_377 , F_222 , V_402 ,
V_47 -> V_45 , V_2 ) ;
if ( V_18 )
F_88 ( V_161 , L_83 , V_18 ) ;
return V_18 ;
}
static void F_224 ( struct V_1 * V_2 )
{
int V_390 ;
if ( ! ( V_2 -> V_129 & V_398 ) ) {
F_219 ( V_2 -> V_10 -> V_377 , V_2 ) ;
return;
}
for ( V_390 = 0 ; V_390 < V_2 -> V_178 ; V_390 ++ ) {
struct V_146 * V_147 = V_2 -> V_147 [ V_390 ] ;
struct V_393 * V_394 = & V_2 -> V_395 [ V_390 ] ;
if ( ! V_147 -> V_306 . V_110 && ! V_147 -> V_151 . V_110 )
continue;
F_218 ( V_394 -> V_390 , NULL ) ;
F_219 ( V_394 -> V_390 , V_147 ) ;
}
F_219 ( V_2 -> V_395 [ V_390 ++ ] . V_390 , V_2 ) ;
}
static inline void F_225 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_16 . V_100 . type ) {
case V_101 :
F_56 ( & V_2 -> V_16 , V_363 , ~ 0 ) ;
break;
case V_103 :
case V_104 :
F_56 ( & V_2 -> V_16 , V_363 , 0xFFFF0000 ) ;
F_56 ( & V_2 -> V_16 , F_203 ( 0 ) , ~ 0 ) ;
F_56 ( & V_2 -> V_16 , F_203 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_199 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_129 & V_398 ) {
int V_390 ;
for ( V_390 = 0 ; V_390 < V_2 -> V_178 ; V_390 ++ )
F_226 ( V_2 -> V_395 [ V_390 ] . V_390 ) ;
F_226 ( V_2 -> V_395 [ V_390 ++ ] . V_390 ) ;
} else {
F_226 ( V_2 -> V_10 -> V_377 ) ;
}
}
static void F_227 ( struct V_1 * V_2 )
{
struct V_146 * V_147 = V_2 -> V_147 [ 0 ] ;
F_188 ( V_147 ) ;
F_58 ( V_2 , 0 , 0 , 0 ) ;
F_58 ( V_2 , 1 , 0 , 0 ) ;
F_90 ( V_16 , L_84 ) ;
}
void F_228 ( struct V_1 * V_2 ,
struct V_49 * V_110 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_4 V_403 = V_110 -> V_73 ;
int V_404 = 10 ;
T_1 V_405 = V_406 ;
T_6 V_136 = V_110 -> V_136 ;
F_56 ( V_16 , F_35 ( V_136 ) , 0 ) ;
F_199 ( V_16 ) ;
F_56 ( V_16 , F_30 ( V_136 ) ,
( V_403 & F_229 ( 32 ) ) ) ;
F_56 ( V_16 , F_31 ( V_136 ) , ( V_403 >> 32 ) ) ;
F_56 ( V_16 , F_32 ( V_136 ) ,
V_110 -> V_80 * sizeof( union V_53 ) ) ;
F_56 ( V_16 , F_33 ( V_136 ) , 0 ) ;
F_56 ( V_16 , F_34 ( V_136 ) , 0 ) ;
V_110 -> V_137 = V_16 -> V_407 + F_34 ( V_136 ) ;
#if F_230 ( V_408 )
if ( ! V_110 -> V_147 || ( V_110 -> V_147 -> V_328 < V_337 ) )
#else
if ( ! V_110 -> V_147 || ( V_110 -> V_147 -> V_328 < 8 ) )
#endif
V_405 |= ( 1 << 16 ) ;
else
V_405 |= ( 8 << 16 ) ;
V_405 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_129 & V_374 ) {
V_110 -> V_409 = V_2 -> V_409 ;
V_110 -> V_410 = 0 ;
F_231 ( V_383 , & V_110 -> V_35 ) ;
} else {
V_110 -> V_409 = 0 ;
}
if ( ! F_14 ( V_411 , & V_110 -> V_35 ) ) {
struct V_146 * V_147 = V_110 -> V_147 ;
if ( V_147 )
F_232 ( V_2 -> V_47 ,
& V_147 -> V_397 ,
V_110 -> V_78 ) ;
}
F_19 ( V_122 , & V_110 -> V_35 ) ;
F_56 ( V_16 , F_35 ( V_136 ) , V_405 ) ;
if ( V_16 -> V_100 . type == V_101 &&
! ( F_22 ( V_16 , V_412 ) & V_413 ) )
return;
do {
F_233 ( 1000 , 2000 ) ;
V_405 = F_22 ( V_16 , F_35 ( V_136 ) ) ;
} while ( -- V_404 && ! ( V_405 & V_406 ) );
if ( ! V_404 )
F_88 ( V_145 , L_85 , V_136 ) ;
}
static void F_234 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_414 , V_415 ;
T_6 V_416 = F_235 ( V_2 -> V_47 ) ;
if ( V_16 -> V_100 . type == V_101 )
return;
V_414 = F_22 ( V_16 , V_417 ) ;
V_414 |= V_418 ;
F_56 ( V_16 , V_417 , V_414 ) ;
if ( V_2 -> V_129 & V_419 ) {
V_415 = V_420 ;
if ( V_416 > 4 )
V_415 |= V_421 | V_422 ;
else if ( V_416 > 1 )
V_415 |= V_421 | V_423 ;
else if ( V_2 -> V_424 [ V_425 ] . V_426 == 4 )
V_415 |= V_427 ;
else
V_415 |= V_428 ;
} else {
if ( V_416 > 4 )
V_415 = V_421 | V_422 ;
else if ( V_416 > 1 )
V_415 = V_421 | V_423 ;
else
V_415 = V_429 ;
}
F_56 ( V_16 , V_430 , V_415 ) ;
if ( V_416 ) {
T_1 V_431 = F_22 ( V_16 , V_432 ) ;
V_431 |= V_433 ;
F_56 ( V_16 , V_432 , V_431 ) ;
}
V_414 &= ~ V_418 ;
F_56 ( V_16 , V_417 , V_414 ) ;
}
static void F_236 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_434 ;
T_1 V_40 ;
F_234 ( V_2 ) ;
if ( V_16 -> V_100 . type != V_101 ) {
V_434 = F_22 ( V_16 , V_435 ) ;
V_434 |= V_436 ;
F_56 ( V_16 , V_435 , V_434 ) ;
}
for ( V_40 = 0 ; V_40 < V_2 -> V_69 ; V_40 ++ )
F_228 ( V_2 , V_2 -> V_50 [ V_40 ] ) ;
}
static void F_237 ( struct V_1 * V_2 ,
struct V_49 * V_110 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_6 V_136 = V_110 -> V_136 ;
T_1 V_437 = F_22 ( V_16 , F_21 ( V_136 ) ) ;
V_437 |= V_438 ;
F_56 ( V_16 , F_21 ( V_136 ) , V_437 ) ;
}
static void F_238 ( struct V_1 * V_2 ,
struct V_49 * V_110 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_6 V_136 = V_110 -> V_136 ;
T_1 V_437 = F_22 ( V_16 , F_21 ( V_136 ) ) ;
V_437 &= ~ V_438 ;
F_56 ( V_16 , F_21 ( V_136 ) , V_437 ) ;
}
static void F_239 ( struct V_1 * V_2 ,
struct V_49 * V_59 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_437 ;
T_6 V_136 = V_59 -> V_136 ;
if ( V_16 -> V_100 . type == V_101 ) {
T_2 V_107 = V_2 -> V_424 [ V_425 ] . V_107 ;
V_136 &= V_107 ;
}
V_437 = V_276 << V_439 ;
V_437 |= F_54 ( V_59 ) >> V_440 ;
V_437 |= V_441 ;
F_56 ( V_16 , F_21 ( V_136 ) , V_437 ) ;
}
static void F_240 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
static const T_1 V_442 [ 10 ] = { 0xE291D73D , 0x1805EC6C , 0x2A94B30D ,
0xA54F2BEC , 0xEA49AF7C , 0xE214AD3D , 0xB855AABE ,
0x6A3E67EA , 0x14364D17 , 0x3BED200D } ;
T_1 V_443 = 0 , V_444 = 0 ;
T_1 V_445 ;
int V_40 , V_41 ;
T_2 V_446 = V_2 -> V_424 [ V_425 ] . V_426 ;
if ( ( V_2 -> V_129 & V_419 ) && ( V_446 < 2 ) )
V_446 = 2 ;
for ( V_40 = 0 ; V_40 < 10 ; V_40 ++ )
F_56 ( V_16 , F_241 ( V_40 ) , V_442 [ V_40 ] ) ;
for ( V_40 = 0 , V_41 = 0 ; V_40 < 128 ; V_40 ++ , V_41 ++ ) {
if ( V_41 == V_446 )
V_41 = 0 ;
V_444 = ( V_444 << 8 ) | ( V_41 * 0x11 ) ;
if ( ( V_40 & 3 ) == 3 )
F_56 ( V_16 , F_242 ( V_40 >> 2 ) , V_444 ) ;
}
V_445 = F_22 ( V_16 , V_447 ) ;
V_445 |= V_448 ;
F_56 ( V_16 , V_447 , V_445 ) ;
if ( V_2 -> V_16 . V_100 . type == V_101 ) {
if ( V_2 -> V_424 [ V_425 ] . V_107 )
V_443 = V_449 ;
} else {
T_6 V_416 = F_235 ( V_2 -> V_47 ) ;
if ( V_2 -> V_129 & V_419 ) {
if ( V_416 > 4 )
V_443 = V_450 ;
else if ( V_416 > 1 )
V_443 = V_451 ;
else if ( V_2 -> V_424 [ V_425 ] . V_426 == 4 )
V_443 = V_452 ;
else
V_443 = V_453 ;
} else {
if ( V_416 > 4 )
V_443 = V_454 ;
else if ( V_416 > 1 )
V_443 = V_455 ;
else
V_443 = V_449 ;
}
}
V_443 |= V_456 |
V_457 |
V_458 |
V_459 ;
if ( V_2 -> V_143 & V_460 )
V_443 |= V_461 ;
if ( V_2 -> V_143 & V_462 )
V_443 |= V_463 ;
F_56 ( V_16 , V_464 , V_443 ) ;
}
static void F_243 ( struct V_1 * V_2 ,
struct V_49 * V_110 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_465 ;
T_6 V_136 = V_110 -> V_136 ;
if ( ! F_153 ( V_110 ) )
return;
V_465 = F_22 ( V_16 , F_244 ( V_136 ) ) ;
V_465 |= V_466 ;
V_465 |= V_467 ;
F_56 ( V_16 , F_244 ( V_136 ) , V_465 ) ;
}
static void F_245 ( struct V_1 * V_2 ,
struct V_49 * V_110 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_404 = V_468 ;
T_1 V_469 ;
T_6 V_136 = V_110 -> V_136 ;
if ( V_16 -> V_100 . type == V_101 &&
! ( F_22 ( V_16 , V_412 ) & V_413 ) )
return;
do {
F_233 ( 1000 , 2000 ) ;
V_469 = F_22 ( V_16 , F_27 ( V_136 ) ) ;
} while ( -- V_404 && ! ( V_469 & V_470 ) );
if ( ! V_404 ) {
F_88 ( V_145 , L_86
L_87 , V_136 ) ;
}
}
void F_246 ( struct V_1 * V_2 ,
struct V_49 * V_110 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_404 = V_468 ;
T_1 V_469 ;
T_6 V_136 = V_110 -> V_136 ;
V_469 = F_22 ( V_16 , F_27 ( V_136 ) ) ;
V_469 &= ~ V_470 ;
F_56 ( V_16 , F_27 ( V_136 ) , V_469 ) ;
if ( V_16 -> V_100 . type == V_101 &&
! ( F_22 ( V_16 , V_412 ) & V_413 ) )
return;
do {
F_247 ( 10 ) ;
V_469 = F_22 ( V_16 , F_27 ( V_136 ) ) ;
} while ( -- V_404 && ( V_469 & V_470 ) );
if ( ! V_404 ) {
F_88 ( V_145 , L_88
L_87 , V_136 ) ;
}
}
void F_248 ( struct V_1 * V_2 ,
struct V_49 * V_110 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_4 V_471 = V_110 -> V_73 ;
T_1 V_469 ;
T_6 V_136 = V_110 -> V_136 ;
V_469 = F_22 ( V_16 , F_27 ( V_136 ) ) ;
F_246 ( V_2 , V_110 ) ;
F_56 ( V_16 , F_28 ( V_136 ) , ( V_471 & F_229 ( 32 ) ) ) ;
F_56 ( V_16 , F_29 ( V_136 ) , ( V_471 >> 32 ) ) ;
F_56 ( V_16 , F_24 ( V_136 ) ,
V_110 -> V_80 * sizeof( union V_60 ) ) ;
F_56 ( V_16 , F_25 ( V_136 ) , 0 ) ;
F_56 ( V_16 , F_26 ( V_136 ) , 0 ) ;
V_110 -> V_137 = V_16 -> V_407 + F_26 ( V_136 ) ;
F_239 ( V_2 , V_110 ) ;
F_243 ( V_2 , V_110 ) ;
if ( V_16 -> V_100 . type == V_101 ) {
V_469 &= ~ 0x3FFFFF ;
V_469 |= 0x080420 ;
}
V_469 |= V_470 ;
F_56 ( V_16 , F_27 ( V_136 ) , V_469 ) ;
F_245 ( V_2 , V_110 ) ;
F_129 ( V_110 , F_95 ( V_110 ) ) ;
}
static void F_249 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_446 = V_2 -> V_424 [ V_425 ] . V_426 ;
int V_472 ;
T_1 V_473 = V_474 |
V_475 |
V_476 |
V_477 |
V_478 ;
if ( V_16 -> V_100 . type == V_101 )
return;
if ( V_446 > 3 )
V_473 |= 2 << 29 ;
else if ( V_446 > 1 )
V_473 |= 1 << 29 ;
for ( V_472 = 0 ; V_472 < V_2 -> V_479 ; V_472 ++ )
F_56 ( V_16 , F_250 ( F_251 ( V_472 ) ) ,
V_473 ) ;
}
static void F_252 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_166 , V_480 ;
T_1 V_481 , V_482 ;
int V_40 ;
if ( ! ( V_2 -> V_129 & V_419 ) )
return;
V_482 = F_22 ( V_16 , V_483 ) ;
V_482 |= V_484 ;
V_482 &= ~ V_485 ;
V_482 |= F_251 ( 0 ) << V_486 ;
V_482 |= V_487 ;
F_56 ( V_16 , V_483 , V_482 ) ;
V_480 = F_251 ( 0 ) % 32 ;
V_166 = ( F_251 ( 0 ) >= 32 ) ? 1 : 0 ;
F_56 ( V_16 , F_253 ( V_166 ) , ( ~ 0 ) << V_480 ) ;
F_56 ( V_16 , F_253 ( V_166 ^ 1 ) , V_166 - 1 ) ;
F_56 ( V_16 , F_254 ( V_166 ) , ( ~ 0 ) << V_480 ) ;
F_56 ( V_16 , F_254 ( V_166 ^ 1 ) , V_166 - 1 ) ;
if ( V_2 -> V_143 & V_488 )
F_56 ( V_16 , V_489 , V_490 ) ;
V_16 -> V_100 . V_347 . V_491 ( V_16 , 0 , F_251 ( 0 ) ) ;
switch ( V_2 -> V_424 [ V_492 ] . V_107 ) {
case V_493 :
V_481 = V_494 ;
break;
case V_495 :
V_481 = V_496 ;
break;
default:
V_481 = V_497 ;
break;
}
F_56 ( V_16 , V_498 , V_481 ) ;
V_16 -> V_100 . V_347 . V_499 ( V_16 , ( V_2 -> V_314 != 0 ) ,
V_2 -> V_314 ) ;
for ( V_40 = 0 ; V_40 < V_2 -> V_314 ; V_40 ++ ) {
if ( ! V_2 -> V_500 [ V_40 ] . V_501 )
F_255 ( V_2 -> V_47 , V_40 , false ) ;
}
}
static void F_256 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_46 * V_47 = V_2 -> V_47 ;
int V_502 = V_47 -> V_302 + V_235 + V_503 ;
struct V_49 * V_59 ;
int V_40 ;
T_1 V_504 , V_505 ;
#ifdef F_134
if ( ( V_2 -> V_129 & V_506 ) &&
( V_502 < V_507 ) )
V_502 = V_507 ;
#endif
if ( V_502 < ( V_508 + V_503 ) )
V_502 = ( V_508 + V_503 ) ;
V_504 = F_22 ( V_16 , V_509 ) ;
if ( V_502 != ( V_504 >> V_510 ) ) {
V_504 &= ~ V_511 ;
V_504 |= V_502 << V_510 ;
F_56 ( V_16 , V_509 , V_504 ) ;
}
V_505 = F_22 ( V_16 , V_512 ) ;
V_505 |= V_513 ;
F_56 ( V_16 , V_512 , V_505 ) ;
for ( V_40 = 0 ; V_40 < V_2 -> V_85 ; V_40 ++ ) {
V_59 = V_2 -> V_59 [ V_40 ] ;
if ( V_2 -> V_143 & V_514 )
F_257 ( V_59 ) ;
else
F_258 ( V_59 ) ;
}
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_515 = F_22 ( V_16 , V_516 ) ;
switch ( V_16 -> V_100 . type ) {
case V_101 :
V_515 |= V_517 ;
break;
case V_103 :
case V_104 :
F_56 ( V_16 , V_518 ,
( V_519 | F_22 ( V_16 , V_518 ) ) ) ;
V_515 &= ~ V_520 ;
V_515 |= ( V_521 | V_522 ) ;
V_515 |= V_523 ;
break;
default:
return;
}
F_56 ( V_16 , V_516 , V_515 ) ;
}
static void F_260 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_40 ;
T_1 V_171 , V_524 ;
V_171 = F_22 ( V_16 , V_525 ) ;
F_56 ( V_16 , V_525 , V_171 & ~ V_526 ) ;
F_249 ( V_2 ) ;
F_259 ( V_2 ) ;
V_524 = F_22 ( V_16 , V_527 ) ;
V_524 &= ~ V_528 ;
if ( ! ( V_2 -> V_143 & V_514 ) )
V_524 |= V_528 ;
F_56 ( V_16 , V_527 , V_524 ) ;
F_240 ( V_2 ) ;
F_256 ( V_2 ) ;
for ( V_40 = 0 ; V_40 < V_2 -> V_85 ; V_40 ++ )
F_248 ( V_2 , V_2 -> V_59 [ V_40 ] ) ;
if ( V_16 -> V_100 . type == V_101 )
V_171 |= V_529 ;
V_171 |= V_526 ;
V_16 -> V_100 . V_347 . V_530 ( V_16 , V_171 ) ;
}
static int F_261 ( struct V_46 * V_47 ,
T_9 V_531 , T_2 V_259 )
{
struct V_1 * V_2 = F_74 ( V_47 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
V_16 -> V_100 . V_347 . V_532 ( & V_2 -> V_16 , V_259 , F_251 ( 0 ) , true ) ;
F_231 ( V_259 , V_2 -> V_533 ) ;
return 0 ;
}
static int F_262 ( struct V_46 * V_47 ,
T_9 V_531 , T_2 V_259 )
{
struct V_1 * V_2 = F_74 ( V_47 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
V_16 -> V_100 . V_347 . V_532 ( & V_2 -> V_16 , V_259 , F_251 ( 0 ) , false ) ;
F_19 ( V_259 , V_2 -> V_533 ) ;
return 0 ;
}
static void F_263 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_534 ;
V_534 = F_22 ( V_16 , V_535 ) ;
V_534 &= ~ ( V_536 | V_537 ) ;
F_56 ( V_16 , V_535 , V_534 ) ;
}
static void F_264 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_534 ;
V_534 = F_22 ( V_16 , V_535 ) ;
V_534 |= V_536 ;
V_534 &= ~ V_537 ;
F_56 ( V_16 , V_535 , V_534 ) ;
}
static void F_265 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_534 ;
int V_40 , V_41 ;
switch ( V_16 -> V_100 . type ) {
case V_101 :
V_534 = F_22 ( V_16 , V_535 ) ;
V_534 &= ~ V_538 ;
F_56 ( V_16 , V_535 , V_534 ) ;
break;
case V_103 :
case V_104 :
for ( V_40 = 0 ; V_40 < V_2 -> V_85 ; V_40 ++ ) {
V_41 = V_2 -> V_59 [ V_40 ] -> V_136 ;
V_534 = F_22 ( V_16 , F_27 ( V_41 ) ) ;
V_534 &= ~ V_539 ;
F_56 ( V_16 , F_27 ( V_41 ) , V_534 ) ;
}
break;
default:
break;
}
}
static void F_266 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_534 ;
int V_40 , V_41 ;
switch ( V_16 -> V_100 . type ) {
case V_101 :
V_534 = F_22 ( V_16 , V_535 ) ;
V_534 |= V_538 ;
F_56 ( V_16 , V_535 , V_534 ) ;
break;
case V_103 :
case V_104 :
for ( V_40 = 0 ; V_40 < V_2 -> V_85 ; V_40 ++ ) {
V_41 = V_2 -> V_59 [ V_40 ] -> V_136 ;
V_534 = F_22 ( V_16 , F_27 ( V_41 ) ) ;
V_534 |= V_539 ;
F_56 ( V_16 , F_27 ( V_41 ) , V_534 ) ;
}
break;
default:
break;
}
}
static void F_267 ( struct V_1 * V_2 )
{
T_2 V_259 ;
F_261 ( V_2 -> V_47 , F_133 ( V_237 ) , 0 ) ;
F_268 (vid, adapter->active_vlans, VLAN_N_VID)
F_261 ( V_2 -> V_47 , F_133 ( V_237 ) , V_259 ) ;
}
static int F_269 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_74 ( V_47 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
unsigned int V_540 = V_16 -> V_100 . V_541 - 1 ;
int V_80 = 0 ;
if ( V_2 -> V_129 & V_419 )
V_540 = V_542 - 1 ;
if ( F_270 ( V_47 ) > V_540 )
return - V_543 ;
if ( ! F_271 ( V_47 ) ) {
struct V_544 * V_545 ;
if ( ! V_16 -> V_100 . V_347 . V_546 )
return - V_543 ;
F_272 (ha, netdev) {
if ( ! V_540 )
break;
V_16 -> V_100 . V_347 . V_546 ( V_16 , V_540 -- , V_545 -> V_547 ,
F_251 ( 0 ) , V_548 ) ;
V_80 ++ ;
}
}
for (; V_540 > 0 ; V_540 -- )
V_16 -> V_100 . V_347 . V_549 ( V_16 , V_540 ) ;
return V_80 ;
}
void F_273 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_74 ( V_47 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_550 , V_551 = V_552 | V_553 ;
int V_80 ;
V_550 = F_22 ( V_16 , V_554 ) ;
V_550 &= ~ V_555 ;
V_550 |= V_556 ;
V_550 |= V_557 ;
V_550 |= V_558 ;
V_550 &= ~ ( V_559 | V_560 ) ;
if ( V_47 -> V_129 & V_561 ) {
V_16 -> V_562 . V_563 = true ;
V_550 |= ( V_559 | V_560 ) ;
V_551 |= ( V_564 | V_565 ) ;
if ( ! ( V_2 -> V_129 & ( V_566 |
V_419 ) ) )
F_263 ( V_2 ) ;
else
F_264 ( V_2 ) ;
} else {
if ( V_47 -> V_129 & V_567 ) {
V_550 |= V_560 ;
V_551 |= V_565 ;
} else {
V_16 -> V_100 . V_347 . V_568 ( V_16 , V_47 ) ;
V_551 |= V_569 ;
}
F_264 ( V_2 ) ;
V_16 -> V_562 . V_563 = false ;
}
V_80 = F_269 ( V_47 ) ;
if ( V_80 < 0 ) {
V_550 |= V_559 ;
V_551 |= V_564 ;
}
if ( V_2 -> V_314 )
F_274 ( V_2 ) ;
if ( V_16 -> V_100 . type != V_101 ) {
V_551 |= F_22 ( V_16 , F_275 ( F_251 ( 0 ) ) ) &
~ ( V_565 | V_569 |
V_564 ) ;
F_56 ( V_16 , F_275 ( F_251 ( 0 ) ) , V_551 ) ;
}
if ( V_2 -> V_47 -> V_185 & V_280 ) {
V_550 |= ( V_555 |
V_556 |
V_558 ) ;
V_550 &= ~ ( V_557 ) ;
}
F_56 ( V_16 , V_554 , V_550 ) ;
if ( V_47 -> V_185 & V_257 )
F_266 ( V_2 ) ;
else
F_265 ( V_2 ) ;
}
static void F_276 ( struct V_1 * V_2 )
{
int V_570 ;
for ( V_570 = 0 ; V_570 < V_2 -> V_178 ; V_570 ++ ) {
F_277 ( V_2 -> V_147 [ V_570 ] ) ;
F_278 ( & V_2 -> V_147 [ V_570 ] -> V_261 ) ;
}
}
static void F_279 ( struct V_1 * V_2 )
{
int V_570 ;
F_280 () ;
for ( V_570 = 0 ; V_570 < V_2 -> V_178 ; V_570 ++ ) {
F_281 ( & V_2 -> V_147 [ V_570 ] -> V_261 ) ;
while ( ! F_213 ( V_2 -> V_147 [ V_570 ] ) ) {
F_36 ( L_89 , V_570 ) ;
F_282 ( 1 ) ;
}
}
F_283 () ;
}
static void F_284 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_502 = V_2 -> V_47 -> V_302 + V_235 + V_503 ;
if ( ! ( V_2 -> V_129 & V_130 ) ) {
if ( V_16 -> V_100 . type == V_101 )
F_285 ( V_2 -> V_47 , 65536 ) ;
return;
}
if ( V_16 -> V_100 . type == V_101 )
F_285 ( V_2 -> V_47 , 32768 ) ;
#ifdef F_134
if ( V_2 -> V_47 -> V_185 & V_571 )
V_502 = F_192 ( V_502 , V_507 ) ;
#endif
if ( V_2 -> V_572 & V_573 ) {
F_286 ( V_16 , & V_2 -> V_126 , V_502 ,
V_574 ) ;
F_286 ( V_16 , & V_2 -> V_126 , V_502 ,
V_575 ) ;
F_287 ( V_16 , & V_2 -> V_126 ) ;
} else if ( V_2 -> V_576 && V_2 -> V_128 ) {
F_288 ( & V_2 -> V_16 ,
V_2 -> V_576 ,
V_502 ) ;
F_289 ( & V_2 -> V_16 ,
V_2 -> V_128 -> V_125 ,
V_2 -> V_576 -> V_577 ) ;
}
if ( V_16 -> V_100 . type != V_101 ) {
T_1 V_578 = 0 ;
T_2 V_446 = V_2 -> V_424 [ V_425 ] . V_426 - 1 ;
while ( V_446 ) {
V_578 ++ ;
V_446 >>= 1 ;
}
F_56 ( V_16 , V_579 , V_578 * 0x11111111 ) ;
}
}
static int F_290 ( struct V_1 * V_2 , int V_580 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_46 * V_65 = V_2 -> V_47 ;
int V_380 , V_124 , V_581 , V_582 ;
T_1 V_583 , V_584 ;
V_124 = V_380 = V_65 -> V_302 + V_235 + V_503 + V_585 ;
#ifdef F_134
if ( ( V_65 -> V_185 & V_571 ) &&
( V_124 < V_507 ) &&
( V_580 == F_291 ( V_2 ) ) )
V_124 = V_507 ;
#endif
switch ( V_16 -> V_100 . type ) {
case V_104 :
V_583 = F_292 ( V_380 , V_124 ) ;
break;
default:
V_583 = F_293 ( V_380 , V_124 ) ;
break;
}
if ( V_2 -> V_129 & V_419 )
V_583 += F_294 ( V_124 ) ;
V_581 = F_295 ( V_583 ) ;
V_584 = F_22 ( V_16 , F_296 ( V_580 ) ) >> 10 ;
V_582 = V_584 - V_581 ;
if ( V_582 < 0 ) {
F_78 ( V_145 , L_90
L_91
L_92 , V_580 ) ;
V_582 = V_124 + 1 ;
}
return V_582 ;
}
static int F_297 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_46 * V_65 = V_2 -> V_47 ;
int V_124 ;
T_1 V_583 ;
V_124 = V_65 -> V_302 + V_235 + V_503 ;
switch ( V_16 -> V_100 . type ) {
case V_104 :
V_583 = F_298 ( V_124 ) ;
break;
default:
V_583 = F_299 ( V_124 ) ;
break;
}
return F_295 ( V_583 ) ;
}
static void F_300 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_586 = F_235 ( V_2 -> V_47 ) ;
int V_40 ;
if ( ! V_586 )
V_586 = 1 ;
V_16 -> V_115 . V_587 = F_297 ( V_2 ) ;
for ( V_40 = 0 ; V_40 < V_586 ; V_40 ++ ) {
V_16 -> V_115 . V_588 [ V_40 ] = F_290 ( V_2 , V_40 ) ;
if ( V_16 -> V_115 . V_587 > V_16 -> V_115 . V_588 [ V_40 ] )
V_16 -> V_115 . V_587 = 0 ;
}
}
static void F_301 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_589 ;
T_6 V_124 = F_235 ( V_2 -> V_47 ) ;
if ( V_2 -> V_129 & V_374 ||
V_2 -> V_129 & V_590 )
V_589 = 32 << V_2 -> V_591 ;
else
V_589 = 0 ;
V_16 -> V_100 . V_347 . V_592 ( V_16 , V_124 , V_589 , V_593 ) ;
F_300 ( V_2 ) ;
}
static void F_302 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_594 * V_595 ;
struct V_596 * V_597 ;
F_303 ( & V_2 -> V_598 ) ;
if ( ! F_304 ( & V_2 -> V_599 ) )
F_305 ( V_16 , & V_2 -> V_600 ) ;
F_306 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_307 ( V_16 ,
& V_597 -> V_597 ,
V_597 -> V_601 ,
( V_597 -> V_602 == V_603 ) ?
V_603 :
V_2 -> V_59 [ V_597 -> V_602 ] -> V_136 ) ;
}
F_308 ( & V_2 -> V_598 ) ;
}
static void F_309 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
F_301 ( V_2 ) ;
#ifdef F_310
F_284 ( V_2 ) ;
#endif
F_252 ( V_2 ) ;
F_273 ( V_2 -> V_47 ) ;
F_267 ( V_2 ) ;
switch ( V_16 -> V_100 . type ) {
case V_103 :
case V_104 :
V_16 -> V_100 . V_347 . V_604 ( V_16 ) ;
break;
default:
break;
}
if ( V_2 -> V_129 & V_374 ) {
F_311 ( & V_2 -> V_16 ,
V_2 -> V_591 ) ;
} else if ( V_2 -> V_129 & V_590 ) {
F_312 ( & V_2 -> V_16 ,
V_2 -> V_591 ) ;
F_302 ( V_2 ) ;
}
switch ( V_16 -> V_100 . type ) {
case V_103 :
case V_104 :
V_16 -> V_100 . V_347 . V_605 ( V_16 ) ;
break;
default:
break;
}
#ifdef F_134
F_313 ( V_2 ) ;
#endif
F_236 ( V_2 ) ;
F_260 ( V_2 ) ;
}
static inline bool F_314 ( struct V_15 * V_16 )
{
switch ( V_16 -> V_350 . type ) {
case V_606 :
case V_607 :
case V_608 :
case V_609 :
case V_610 :
case V_611 :
case V_612 :
case V_613 :
case V_614 :
case V_615 :
case V_616 :
case V_617 :
return true ;
case V_618 :
if ( V_16 -> V_100 . type == V_101 )
return true ;
default:
return false ;
}
}
static void F_315 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 . V_100 . type == V_101 )
V_2 -> V_143 |= V_619 ;
V_2 -> V_143 |= V_358 ;
}
static int F_316 ( struct V_15 * V_16 )
{
T_1 V_21 ;
bool V_620 , V_349 = false ;
T_1 V_142 = V_621 ;
if ( V_16 -> V_100 . V_347 . V_348 )
V_142 = V_16 -> V_100 . V_347 . V_348 ( V_16 , & V_21 , & V_349 , false ) ;
if ( V_142 )
goto V_622;
V_21 = V_16 -> V_350 . V_623 ;
if ( ( ! V_21 ) && ( V_16 -> V_100 . V_347 . V_624 ) )
V_142 = V_16 -> V_100 . V_347 . V_624 ( V_16 , & V_21 ,
& V_620 ) ;
if ( V_142 )
goto V_622;
if ( V_16 -> V_100 . V_347 . V_625 )
V_142 = V_16 -> V_100 . V_347 . V_625 ( V_16 , V_21 , V_349 ) ;
V_622:
return V_142 ;
}
static void F_317 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_626 = 0 ;
if ( V_2 -> V_129 & V_398 ) {
V_626 = V_627 | V_628 |
V_629 ;
V_626 |= V_630 ;
switch ( V_16 -> V_100 . type ) {
case V_101 :
F_56 ( V_16 , V_631 , V_632 ) ;
break;
case V_103 :
case V_104 :
default:
F_56 ( V_16 , F_318 ( 0 ) , 0xFFFFFFFF ) ;
F_56 ( V_16 , F_318 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_56 ( V_16 , V_631 , V_632 ) ;
}
if ( V_2 -> V_129 & V_419 ) {
V_626 &= ~ V_633 ;
switch ( V_2 -> V_424 [ V_492 ] . V_107 ) {
case V_493 :
V_626 |= V_634 ;
break;
case V_495 :
V_626 |= V_635 ;
break;
default:
V_626 |= V_636 ;
break;
}
}
if ( V_2 -> V_143 & V_342 ) {
switch ( V_2 -> V_16 . V_100 . type ) {
case V_103 :
V_626 |= V_637 ;
break;
case V_104 :
V_626 |= V_369 ;
break;
default:
break;
}
}
if ( V_2 -> V_129 & V_353 )
V_626 |= V_638 ;
if ( V_16 -> V_100 . type == V_103 ) {
V_626 |= V_638 ;
V_626 |= V_639 ;
}
F_56 ( V_16 , V_640 , V_626 ) ;
}
static void F_319 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_18 ;
T_1 V_92 ;
F_57 ( V_2 ) ;
F_317 ( V_2 ) ;
if ( V_2 -> V_129 & V_398 )
F_187 ( V_2 ) ;
else
F_227 ( V_2 ) ;
if ( V_16 -> V_100 . V_347 . V_641 )
V_16 -> V_100 . V_347 . V_641 ( V_16 ) ;
F_19 ( V_34 , & V_2 -> V_35 ) ;
F_276 ( V_2 ) ;
if ( F_314 ( V_16 ) ) {
F_315 ( V_2 ) ;
} else {
V_18 = F_316 ( V_16 ) ;
if ( V_18 )
F_88 ( V_161 , L_93 , V_18 ) ;
}
F_22 ( V_16 , V_355 ) ;
F_204 ( V_2 , true , true ) ;
if ( V_2 -> V_129 & V_353 ) {
T_1 V_642 = F_22 ( V_16 , V_643 ) ;
if ( V_642 & V_644 )
F_194 ( V_145 , L_72 ) ;
}
F_320 ( V_2 -> V_47 ) ;
V_2 -> V_129 |= V_361 ;
V_2 -> V_362 = V_160 ;
F_321 ( & V_2 -> V_645 , V_160 ) ;
V_92 = F_22 ( V_16 , V_93 ) ;
V_92 |= V_646 ;
F_56 ( V_16 , V_93 , V_92 ) ;
}
void F_322 ( struct V_1 * V_2 )
{
F_323 ( F_324 () ) ;
V_2 -> V_47 -> V_66 = V_160 ;
while ( F_14 ( V_647 , & V_2 -> V_35 ) )
F_233 ( 1000 , 2000 ) ;
F_325 ( V_2 ) ;
if ( V_2 -> V_129 & V_419 )
F_326 ( 2000 ) ;
F_327 ( V_2 ) ;
F_19 ( V_647 , & V_2 -> V_35 ) ;
}
void F_327 ( struct V_1 * V_2 )
{
F_309 ( V_2 ) ;
F_319 ( V_2 ) ;
}
void F_328 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_18 ;
while ( F_14 ( V_648 , & V_2 -> V_35 ) )
F_233 ( 1000 , 2000 ) ;
V_2 -> V_143 &= ~ ( V_619 |
V_358 ) ;
V_2 -> V_129 &= ~ V_359 ;
V_18 = V_16 -> V_100 . V_347 . V_649 ( V_16 ) ;
switch ( V_18 ) {
case 0 :
case V_650 :
case V_651 :
break;
case V_652 :
F_329 ( L_94 ) ;
break;
case V_653 :
F_10 ( L_95
L_96
L_97
L_98
L_99
L_100 ) ;
break;
default:
F_329 ( L_101 , V_18 ) ;
}
F_19 ( V_648 , & V_2 -> V_35 ) ;
V_16 -> V_100 . V_347 . V_546 ( V_16 , 0 , V_16 -> V_100 . V_547 , F_251 ( 0 ) , V_548 ) ;
if ( V_16 -> V_100 . V_654 )
V_16 -> V_100 . V_347 . V_655 ( V_16 , F_251 ( 0 ) ) ;
if ( F_13 ( V_656 , & V_2 -> V_35 ) )
F_330 ( V_2 ) ;
}
static void F_331 ( struct V_49 * V_59 )
{
struct V_179 * V_65 = V_59 -> V_65 ;
unsigned long V_286 ;
T_2 V_40 ;
if ( ! V_59 -> V_63 )
return;
for ( V_40 = 0 ; V_40 < V_59 -> V_80 ; V_40 ++ ) {
struct V_62 * V_285 ;
V_285 = & V_59 -> V_63 [ V_40 ] ;
if ( V_285 -> V_81 ) {
struct V_184 * V_81 = V_285 -> V_81 ;
if ( F_139 ( V_81 ) -> V_278 ) {
F_65 ( V_65 ,
F_139 ( V_81 ) -> V_73 ,
F_54 ( V_59 ) ,
V_216 ) ;
F_139 ( V_81 ) -> V_278 = false ;
}
F_332 ( V_81 ) ;
}
V_285 -> V_81 = NULL ;
if ( V_285 -> V_73 )
F_65 ( V_65 , V_285 -> V_73 ,
F_126 ( V_59 ) ,
V_216 ) ;
V_285 -> V_73 = 0 ;
if ( V_285 -> V_90 )
F_128 ( V_285 -> V_90 ,
F_124 ( V_59 ) ) ;
V_285 -> V_90 = NULL ;
}
V_286 = sizeof( struct V_62 ) * V_59 -> V_80 ;
memset ( V_59 -> V_63 , 0 , V_286 ) ;
memset ( V_59 -> V_79 , 0 , V_59 -> V_286 ) ;
V_59 -> V_210 = 0 ;
V_59 -> V_71 = 0 ;
V_59 -> V_72 = 0 ;
}
static void F_333 ( struct V_49 * V_50 )
{
struct V_51 * V_70 ;
unsigned long V_286 ;
T_2 V_40 ;
if ( ! V_50 -> V_70 )
return;
for ( V_40 = 0 ; V_40 < V_50 -> V_80 ; V_40 ++ ) {
V_70 = & V_50 -> V_70 [ V_40 ] ;
F_62 ( V_50 , V_70 ) ;
}
F_334 ( F_92 ( V_50 ) ) ;
V_286 = sizeof( struct V_51 ) * V_50 -> V_80 ;
memset ( V_50 -> V_70 , 0 , V_286 ) ;
memset ( V_50 -> V_79 , 0 , V_50 -> V_286 ) ;
V_50 -> V_72 = 0 ;
V_50 -> V_71 = 0 ;
}
static void F_335 ( struct V_1 * V_2 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_2 -> V_85 ; V_40 ++ )
F_331 ( V_2 -> V_59 [ V_40 ] ) ;
}
static void F_336 ( struct V_1 * V_2 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_2 -> V_69 ; V_40 ++ )
F_333 ( V_2 -> V_50 [ V_40 ] ) ;
}
static void F_337 ( struct V_1 * V_2 )
{
struct V_594 * V_595 ;
struct V_596 * V_597 ;
F_303 ( & V_2 -> V_598 ) ;
F_306 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_338 ( & V_597 -> V_657 ) ;
F_221 ( V_597 ) ;
}
V_2 -> V_658 = 0 ;
F_308 ( & V_2 -> V_598 ) ;
}
void F_325 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_171 ;
int V_40 ;
F_231 ( V_34 , & V_2 -> V_35 ) ;
V_171 = F_22 ( V_16 , V_525 ) ;
F_56 ( V_16 , V_525 , V_171 & ~ V_526 ) ;
for ( V_40 = 0 ; V_40 < V_2 -> V_85 ; V_40 ++ )
F_246 ( V_2 , V_2 -> V_59 [ V_40 ] ) ;
F_233 ( 10000 , 20000 ) ;
F_339 ( V_47 ) ;
F_340 ( V_47 ) ;
F_341 ( V_47 ) ;
F_225 ( V_2 ) ;
F_279 ( V_2 ) ;
V_2 -> V_143 &= ~ ( V_375 |
V_144 ) ;
V_2 -> V_129 &= ~ V_361 ;
F_342 ( & V_2 -> V_645 ) ;
if ( V_2 -> V_314 ) {
F_56 ( & V_2 -> V_16 , V_316 , 0 ) ;
for ( V_40 = 0 ; V_40 < V_2 -> V_314 ; V_40 ++ )
V_2 -> V_500 [ V_40 ] . V_659 = false ;
F_343 ( V_2 ) ;
F_344 ( V_2 ) ;
}
for ( V_40 = 0 ; V_40 < V_2 -> V_69 ; V_40 ++ ) {
T_6 V_136 = V_2 -> V_50 [ V_40 ] -> V_136 ;
F_56 ( V_16 , F_35 ( V_136 ) , V_660 ) ;
}
switch ( V_16 -> V_100 . type ) {
case V_103 :
case V_104 :
F_56 ( V_16 , V_435 ,
( F_22 ( V_16 , V_435 ) &
~ V_436 ) ) ;
break;
default:
break;
}
if ( ! F_345 ( V_2 -> V_10 ) )
F_328 ( V_2 ) ;
if ( V_16 -> V_100 . V_347 . V_661 )
V_16 -> V_100 . V_347 . V_661 ( V_16 ) ;
F_336 ( V_2 ) ;
F_335 ( V_2 ) ;
#ifdef F_212
F_108 ( V_2 ) ;
#endif
}
static void F_346 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_74 ( V_47 ) ;
F_77 ( V_2 ) ;
}
static int F_347 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_6 * V_10 = V_2 -> V_10 ;
unsigned int V_190 , V_662 ;
T_1 V_663 ;
#ifdef F_310
int V_41 ;
struct V_664 * V_124 ;
#endif
V_16 -> V_665 = V_10 -> V_666 ;
V_16 -> V_22 = V_10 -> V_179 ;
V_16 -> V_667 = V_10 -> V_668 ;
V_16 -> V_669 = V_10 -> V_670 ;
V_16 -> V_671 = V_10 -> V_672 ;
V_190 = F_348 ( int , V_673 , F_349 () ) ;
V_2 -> V_424 [ V_425 ] . V_674 = V_190 ;
V_2 -> V_143 |= V_675 ;
V_2 -> V_143 |= V_514 ;
V_2 -> V_676 = V_677 ;
V_2 -> V_409 = 20 ;
V_662 = F_348 ( int , V_678 , F_349 () ) ;
V_2 -> V_424 [ V_679 ] . V_674 = V_662 ;
V_2 -> V_591 = V_680 ;
#ifdef F_212
V_2 -> V_129 |= V_181 ;
#endif
#ifdef F_134
V_2 -> V_129 |= V_681 ;
V_2 -> V_129 &= ~ V_506 ;
#ifdef F_310
V_2 -> V_682 . V_683 = V_684 ;
#endif
#endif
switch ( V_16 -> V_100 . type ) {
case V_101 :
V_2 -> V_143 &= ~ V_675 ;
V_2 -> V_143 &= ~ V_514 ;
if ( V_16 -> V_22 == V_685 )
V_2 -> V_129 |= V_353 ;
V_2 -> V_676 = V_686 ;
V_2 -> V_424 [ V_679 ] . V_674 = 0 ;
V_2 -> V_409 = 0 ;
V_2 -> V_591 = 0 ;
#ifdef F_134
V_2 -> V_129 &= ~ V_681 ;
V_2 -> V_129 &= ~ V_506 ;
#ifdef F_310
V_2 -> V_682 . V_683 = 0 ;
#endif
#endif
break;
case V_103 :
if ( V_16 -> V_22 == V_344 )
V_2 -> V_143 |= V_342 ;
break;
case V_104 :
V_663 = F_22 ( V_16 , V_687 ) ;
if ( V_663 & V_688 )
V_2 -> V_143 |= V_342 ;
break;
default:
break;
}
#ifdef F_134
F_350 ( & V_2 -> V_682 . V_689 ) ;
#endif
F_350 ( & V_2 -> V_598 ) ;
#ifdef F_310
switch ( V_16 -> V_100 . type ) {
case V_104 :
V_2 -> V_126 . V_690 . V_691 = V_692 ;
V_2 -> V_126 . V_690 . V_693 = V_692 ;
break;
default:
V_2 -> V_126 . V_690 . V_691 = V_694 ;
V_2 -> V_126 . V_690 . V_693 = V_694 ;
break;
}
for ( V_41 = 0 ; V_41 < V_694 ; V_41 ++ ) {
V_124 = & V_2 -> V_126 . V_695 [ V_41 ] ;
V_124 -> V_696 [ V_574 ] . V_697 = 0 ;
V_124 -> V_696 [ V_574 ] . V_698 = 12 + ( V_41 & 1 ) ;
V_124 -> V_696 [ V_575 ] . V_697 = 0 ;
V_124 -> V_696 [ V_575 ] . V_698 = 12 + ( V_41 & 1 ) ;
V_124 -> V_699 = V_700 ;
}
V_124 = & V_2 -> V_126 . V_695 [ 0 ] ;
V_124 -> V_696 [ V_574 ] . V_701 = 0xFF ;
V_124 -> V_696 [ V_575 ] . V_701 = 0xFF ;
V_2 -> V_126 . V_702 [ V_574 ] [ 0 ] = 100 ;
V_2 -> V_126 . V_702 [ V_575 ] [ 0 ] = 100 ;
V_2 -> V_126 . V_127 = false ;
V_2 -> V_703 = 0x00 ;
V_2 -> V_572 = V_704 | V_573 ;
memcpy ( & V_2 -> V_705 , & V_2 -> V_126 ,
sizeof( V_2 -> V_705 ) ) ;
#endif
V_16 -> V_115 . V_706 = V_117 ;
V_16 -> V_115 . V_116 = V_117 ;
F_300 ( V_2 ) ;
V_16 -> V_115 . V_707 = V_708 ;
V_16 -> V_115 . V_709 = true ;
V_16 -> V_115 . V_710 = F_351 ( V_16 ) ;
#ifdef F_352
if ( V_16 -> V_100 . type != V_101 )
V_2 -> V_314 = ( V_711 > 63 ) ? 0 : V_711 ;
#endif
V_2 -> V_389 = 1 ;
V_2 -> V_712 = 1 ;
V_2 -> V_713 = V_714 ;
V_2 -> V_715 = V_716 ;
V_2 -> V_717 = V_718 ;
if ( F_353 ( V_16 ) ) {
F_329 ( L_102 ) ;
return - V_719 ;
}
F_231 ( V_34 , & V_2 -> V_35 ) ;
return 0 ;
}
int F_354 ( struct V_49 * V_50 )
{
struct V_179 * V_65 = V_50 -> V_65 ;
int V_720 = F_355 ( V_65 ) ;
int V_721 = - 1 ;
int V_286 ;
V_286 = sizeof( struct V_51 ) * V_50 -> V_80 ;
if ( V_50 -> V_147 )
V_721 = V_50 -> V_147 -> V_721 ;
V_50 -> V_70 = F_356 ( V_286 , V_721 ) ;
if ( ! V_50 -> V_70 )
V_50 -> V_70 = F_357 ( V_286 ) ;
if ( ! V_50 -> V_70 )
goto V_18;
V_50 -> V_286 = V_50 -> V_80 * sizeof( union V_53 ) ;
V_50 -> V_286 = F_157 ( V_50 -> V_286 , 4096 ) ;
F_358 ( V_65 , V_721 ) ;
V_50 -> V_79 = F_359 ( V_65 ,
V_50 -> V_286 ,
& V_50 -> V_73 ,
V_722 ) ;
F_358 ( V_65 , V_720 ) ;
if ( ! V_50 -> V_79 )
V_50 -> V_79 = F_359 ( V_65 , V_50 -> V_286 ,
& V_50 -> V_73 , V_722 ) ;
if ( ! V_50 -> V_79 )
goto V_18;
V_50 -> V_72 = 0 ;
V_50 -> V_71 = 0 ;
return 0 ;
V_18:
F_360 ( V_50 -> V_70 ) ;
V_50 -> V_70 = NULL ;
F_361 ( V_65 , L_103 ) ;
return - V_543 ;
}
static int F_362 ( struct V_1 * V_2 )
{
int V_40 , V_18 = 0 ;
for ( V_40 = 0 ; V_40 < V_2 -> V_69 ; V_40 ++ ) {
V_18 = F_354 ( V_2 -> V_50 [ V_40 ] ) ;
if ( ! V_18 )
continue;
F_88 ( V_161 , L_104 , V_40 ) ;
goto V_723;
}
return 0 ;
V_723:
while ( V_40 -- )
F_363 ( V_2 -> V_50 [ V_40 ] ) ;
return V_18 ;
}
int F_364 ( struct V_49 * V_59 )
{
struct V_179 * V_65 = V_59 -> V_65 ;
int V_720 = F_355 ( V_65 ) ;
int V_721 = - 1 ;
int V_286 ;
V_286 = sizeof( struct V_62 ) * V_59 -> V_80 ;
if ( V_59 -> V_147 )
V_721 = V_59 -> V_147 -> V_721 ;
V_59 -> V_63 = F_356 ( V_286 , V_721 ) ;
if ( ! V_59 -> V_63 )
V_59 -> V_63 = F_357 ( V_286 ) ;
if ( ! V_59 -> V_63 )
goto V_18;
V_59 -> V_286 = V_59 -> V_80 * sizeof( union V_60 ) ;
V_59 -> V_286 = F_157 ( V_59 -> V_286 , 4096 ) ;
F_358 ( V_65 , V_721 ) ;
V_59 -> V_79 = F_359 ( V_65 ,
V_59 -> V_286 ,
& V_59 -> V_73 ,
V_722 ) ;
F_358 ( V_65 , V_720 ) ;
if ( ! V_59 -> V_79 )
V_59 -> V_79 = F_359 ( V_65 , V_59 -> V_286 ,
& V_59 -> V_73 , V_722 ) ;
if ( ! V_59 -> V_79 )
goto V_18;
V_59 -> V_71 = 0 ;
V_59 -> V_72 = 0 ;
return 0 ;
V_18:
F_360 ( V_59 -> V_63 ) ;
V_59 -> V_63 = NULL ;
F_361 ( V_65 , L_105 ) ;
return - V_543 ;
}
static int F_365 ( struct V_1 * V_2 )
{
int V_40 , V_18 = 0 ;
for ( V_40 = 0 ; V_40 < V_2 -> V_85 ; V_40 ++ ) {
V_18 = F_364 ( V_2 -> V_59 [ V_40 ] ) ;
if ( ! V_18 )
continue;
F_88 ( V_161 , L_106 , V_40 ) ;
goto V_724;
}
#ifdef F_134
V_18 = F_366 ( V_2 ) ;
if ( ! V_18 )
#endif
return 0 ;
V_724:
while ( V_40 -- )
F_367 ( V_2 -> V_59 [ V_40 ] ) ;
return V_18 ;
}
void F_363 ( struct V_49 * V_50 )
{
F_333 ( V_50 ) ;
F_360 ( V_50 -> V_70 ) ;
V_50 -> V_70 = NULL ;
if ( ! V_50 -> V_79 )
return;
F_368 ( V_50 -> V_65 , V_50 -> V_286 ,
V_50 -> V_79 , V_50 -> V_73 ) ;
V_50 -> V_79 = NULL ;
}
static void F_369 ( struct V_1 * V_2 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_2 -> V_69 ; V_40 ++ )
if ( V_2 -> V_50 [ V_40 ] -> V_79 )
F_363 ( V_2 -> V_50 [ V_40 ] ) ;
}
void F_367 ( struct V_49 * V_59 )
{
F_331 ( V_59 ) ;
F_360 ( V_59 -> V_63 ) ;
V_59 -> V_63 = NULL ;
if ( ! V_59 -> V_79 )
return;
F_368 ( V_59 -> V_65 , V_59 -> V_286 ,
V_59 -> V_79 , V_59 -> V_73 ) ;
V_59 -> V_79 = NULL ;
}
static void F_370 ( struct V_1 * V_2 )
{
int V_40 ;
#ifdef F_134
F_371 ( V_2 ) ;
#endif
for ( V_40 = 0 ; V_40 < V_2 -> V_85 ; V_40 ++ )
if ( V_2 -> V_59 [ V_40 ] -> V_79 )
F_367 ( V_2 -> V_59 [ V_40 ] ) ;
}
static int F_372 ( struct V_46 * V_47 , int V_725 )
{
struct V_1 * V_2 = F_74 ( V_47 ) ;
int V_502 = V_725 + V_235 + V_503 ;
if ( ( V_725 < 68 ) || ( V_502 > V_726 ) )
return - V_727 ;
if ( ( V_2 -> V_129 & V_419 ) &&
( V_2 -> V_16 . V_100 . type == V_103 ) &&
( V_502 > ( V_508 + V_503 ) ) )
F_78 ( V_161 , L_107 ) ;
F_90 ( V_161 , L_108 , V_47 -> V_302 , V_725 ) ;
V_47 -> V_302 = V_725 ;
if ( F_42 ( V_47 ) )
F_322 ( V_2 ) ;
return 0 ;
}
static int F_373 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_74 ( V_47 ) ;
int V_18 ;
if ( F_13 ( V_728 , & V_2 -> V_35 ) )
return - V_729 ;
F_340 ( V_47 ) ;
V_18 = F_362 ( V_2 ) ;
if ( V_18 )
goto V_723;
V_18 = F_365 ( V_2 ) ;
if ( V_18 )
goto V_724;
F_309 ( V_2 ) ;
V_18 = F_223 ( V_2 ) ;
if ( V_18 )
goto V_730;
V_18 = F_374 ( V_47 ,
V_2 -> V_479 > 1 ? 1 :
V_2 -> V_69 ) ;
if ( V_18 )
goto V_731;
V_18 = F_375 ( V_47 ,
V_2 -> V_479 > 1 ? 1 :
V_2 -> V_85 ) ;
if ( V_18 )
goto V_731;
F_376 ( V_2 ) ;
F_319 ( V_2 ) ;
return 0 ;
V_731:
F_224 ( V_2 ) ;
V_730:
F_370 ( V_2 ) ;
V_724:
F_369 ( V_2 ) ;
V_723:
F_328 ( V_2 ) ;
return V_18 ;
}
static int F_377 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_74 ( V_47 ) ;
F_378 ( V_2 ) ;
F_325 ( V_2 ) ;
F_224 ( V_2 ) ;
F_337 ( V_2 ) ;
F_369 ( V_2 ) ;
F_370 ( V_2 ) ;
F_55 ( V_2 ) ;
return 0 ;
}
static int F_379 ( struct V_6 * V_10 )
{
struct V_1 * V_2 = F_380 ( V_10 ) ;
struct V_46 * V_47 = V_2 -> V_47 ;
T_1 V_18 ;
F_381 ( V_10 , V_732 ) ;
F_382 ( V_10 ) ;
F_383 ( V_10 ) ;
V_18 = F_384 ( V_10 ) ;
if ( V_18 ) {
F_329 ( L_109 ) ;
return V_18 ;
}
F_385 ( V_10 ) ;
F_386 ( V_10 , false ) ;
F_328 ( V_2 ) ;
F_56 ( & V_2 -> V_16 , V_733 , ~ 0 ) ;
F_387 () ;
V_18 = F_388 ( V_2 ) ;
if ( ! V_18 && F_42 ( V_47 ) )
V_18 = F_373 ( V_47 ) ;
F_389 () ;
if ( V_18 )
return V_18 ;
F_390 ( V_47 ) ;
return 0 ;
}
static int F_391 ( struct V_6 * V_10 , bool * V_734 )
{
struct V_1 * V_2 = F_380 ( V_10 ) ;
struct V_46 * V_47 = V_2 -> V_47 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_735 , V_550 ;
T_1 V_736 = V_2 -> V_737 ;
#ifdef F_392
int V_738 = 0 ;
#endif
F_393 ( V_47 ) ;
F_387 () ;
if ( F_42 ( V_47 ) ) {
F_325 ( V_2 ) ;
F_224 ( V_2 ) ;
F_369 ( V_2 ) ;
F_370 ( V_2 ) ;
}
F_389 () ;
F_394 ( V_2 ) ;
#ifdef F_392
V_738 = F_383 ( V_10 ) ;
if ( V_738 )
return V_738 ;
#endif
if ( V_16 -> V_100 . V_347 . V_739 )
V_16 -> V_100 . V_347 . V_739 ( V_16 ) ;
if ( V_736 ) {
F_273 ( V_47 ) ;
if ( V_16 -> V_100 . V_347 . V_641 )
V_16 -> V_100 . V_347 . V_641 ( V_16 ) ;
if ( V_736 & V_740 ) {
V_550 = F_22 ( V_16 , V_554 ) ;
V_550 |= V_560 ;
F_56 ( V_16 , V_554 , V_550 ) ;
}
V_735 = F_22 ( V_16 , V_741 ) ;
V_735 |= V_742 ;
F_56 ( V_16 , V_741 , V_735 ) ;
F_56 ( V_16 , V_743 , V_736 ) ;
} else {
F_56 ( V_16 , V_744 , 0 ) ;
F_56 ( V_16 , V_743 , 0 ) ;
}
switch ( V_16 -> V_100 . type ) {
case V_101 :
F_386 ( V_10 , false ) ;
break;
case V_103 :
case V_104 :
F_386 ( V_10 , ! ! V_736 ) ;
break;
default:
break;
}
* V_734 = ! ! V_736 ;
F_55 ( V_2 ) ;
F_395 ( V_10 ) ;
return 0 ;
}
static int F_396 ( struct V_6 * V_10 , T_12 V_35 )
{
int V_738 ;
bool V_745 ;
V_738 = F_391 ( V_10 , & V_745 ) ;
if ( V_738 )
return V_738 ;
if ( V_745 ) {
F_397 ( V_10 ) ;
} else {
F_386 ( V_10 , false ) ;
F_381 ( V_10 , V_746 ) ;
}
return 0 ;
}
static void F_398 ( struct V_6 * V_10 )
{
bool V_745 ;
F_391 ( V_10 , & V_745 ) ;
if ( V_747 == V_748 ) {
F_386 ( V_10 , V_745 ) ;
F_381 ( V_10 , V_746 ) ;
}
}
void F_399 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_112 * V_113 = & V_2 -> V_114 ;
T_4 V_749 = 0 ;
T_1 V_40 , V_750 = 0 , V_751 , V_752 , V_753 , V_754 , V_755 ;
T_4 V_270 = 0 , V_163 = 0 , V_756 = 0 ;
T_4 V_215 = 0 , V_295 = 0 ;
T_4 V_159 = 0 , V_134 = 0 , V_757 = 0 ;
if ( F_13 ( V_34 , & V_2 -> V_35 ) ||
F_13 ( V_647 , & V_2 -> V_35 ) )
return;
if ( V_2 -> V_143 & V_514 ) {
T_4 V_255 = 0 ;
T_4 V_256 = 0 ;
for ( V_40 = 0 ; V_40 < V_2 -> V_85 ; V_40 ++ ) {
V_255 += V_2 -> V_59 [ V_40 ] -> V_201 . V_255 ;
V_256 += V_2 -> V_59 [ V_40 ] -> V_201 . V_256 ;
}
V_2 -> V_758 = V_255 ;
V_2 -> V_759 = V_256 ;
}
for ( V_40 = 0 ; V_40 < V_2 -> V_85 ; V_40 ++ ) {
struct V_49 * V_59 = V_2 -> V_59 [ V_40 ] ;
V_270 += V_59 -> V_201 . V_270 ;
V_215 += V_59 -> V_201 . V_215 ;
V_295 += V_59 -> V_201 . V_295 ;
V_757 += V_59 -> V_201 . V_202 ;
V_159 += V_59 -> V_114 . V_159 ;
V_134 += V_59 -> V_114 . V_134 ;
}
V_2 -> V_270 = V_270 ;
V_2 -> V_215 = V_215 ;
V_2 -> V_295 = V_295 ;
V_2 -> V_757 = V_757 ;
V_47 -> V_114 . V_760 = V_159 ;
V_47 -> V_114 . V_761 = V_134 ;
V_159 = 0 ;
V_134 = 0 ;
for ( V_40 = 0 ; V_40 < V_2 -> V_69 ; V_40 ++ ) {
struct V_49 * V_50 = V_2 -> V_50 [ V_40 ] ;
V_163 += V_50 -> V_140 . V_163 ;
V_756 += V_50 -> V_140 . V_756 ;
V_159 += V_50 -> V_114 . V_159 ;
V_134 += V_50 -> V_114 . V_134 ;
}
V_2 -> V_163 = V_163 ;
V_2 -> V_756 = V_756 ;
V_47 -> V_114 . V_762 = V_159 ;
V_47 -> V_114 . V_763 = V_134 ;
V_113 -> V_764 += F_22 ( V_16 , V_765 ) ;
for ( V_40 = 0 ; V_40 < 8 ; V_40 ++ ) {
V_751 = F_22 ( V_16 , F_400 ( V_40 ) ) ;
V_750 += V_751 ;
V_113 -> V_751 [ V_40 ] += V_751 ;
V_749 += V_113 -> V_751 [ V_40 ] ;
V_113 -> V_766 [ V_40 ] += F_22 ( V_16 , F_401 ( V_40 ) ) ;
V_113 -> V_767 [ V_40 ] += F_22 ( V_16 , F_402 ( V_40 ) ) ;
switch ( V_16 -> V_100 . type ) {
case V_101 :
V_113 -> V_768 [ V_40 ] += F_22 ( V_16 , F_403 ( V_40 ) ) ;
V_113 -> V_769 [ V_40 ] += F_22 ( V_16 , F_404 ( V_40 ) ) ;
V_113 -> V_770 [ V_40 ] += F_22 ( V_16 , F_405 ( V_40 ) ) ;
V_113 -> V_771 [ V_40 ] +=
F_22 ( V_16 , F_406 ( V_40 ) ) ;
break;
case V_103 :
case V_104 :
V_113 -> V_771 [ V_40 ] +=
F_22 ( V_16 , F_407 ( V_40 ) ) ;
break;
default:
break;
}
}
for ( V_40 = 0 ; V_40 < 16 ; V_40 ++ ) {
V_113 -> V_772 [ V_40 ] += F_22 ( V_16 , F_408 ( V_40 ) ) ;
V_113 -> V_773 [ V_40 ] += F_22 ( V_16 , F_409 ( V_40 ) ) ;
if ( ( V_16 -> V_100 . type == V_103 ) ||
( V_16 -> V_100 . type == V_104 ) ) {
V_113 -> V_769 [ V_40 ] += F_22 ( V_16 , F_410 ( V_40 ) ) ;
F_22 ( V_16 , F_411 ( V_40 ) ) ;
V_113 -> V_770 [ V_40 ] += F_22 ( V_16 , F_412 ( V_40 ) ) ;
F_22 ( V_16 , F_413 ( V_40 ) ) ;
}
}
V_113 -> V_774 += F_22 ( V_16 , V_775 ) ;
V_113 -> V_774 -= V_750 ;
F_68 ( V_2 ) ;
switch ( V_16 -> V_100 . type ) {
case V_101 :
V_113 -> V_776 += F_22 ( V_16 , V_777 ) ;
V_113 -> V_778 += F_22 ( V_16 , V_779 ) ;
V_113 -> V_780 += F_22 ( V_16 , V_781 ) ;
V_113 -> V_782 += F_22 ( V_16 , V_783 ) ;
break;
case V_104 :
V_113 -> V_784 += F_22 ( V_16 , V_785 ) ;
V_113 -> V_786 += F_22 ( V_16 , V_787 ) ;
V_113 -> V_788 += F_22 ( V_16 , V_789 ) ;
V_113 -> V_790 += F_22 ( V_16 , V_791 ) ;
case V_103 :
for ( V_40 = 0 ; V_40 < 16 ; V_40 ++ )
V_2 -> V_792 +=
F_22 ( V_16 , F_414 ( V_40 ) ) ;
V_113 -> V_778 += F_22 ( V_16 , V_793 ) ;
F_22 ( V_16 , V_779 ) ;
V_113 -> V_780 += F_22 ( V_16 , V_794 ) ;
F_22 ( V_16 , V_781 ) ;
V_113 -> V_782 += F_22 ( V_16 , V_795 ) ;
F_22 ( V_16 , V_783 ) ;
V_113 -> V_776 += F_22 ( V_16 , V_796 ) ;
V_113 -> V_797 += F_22 ( V_16 , V_798 ) ;
V_113 -> V_799 += F_22 ( V_16 , V_800 ) ;
#ifdef F_134
V_113 -> V_801 += F_22 ( V_16 , V_802 ) ;
V_113 -> V_803 += F_22 ( V_16 , V_804 ) ;
V_113 -> V_805 += F_22 ( V_16 , V_806 ) ;
V_113 -> V_807 += F_22 ( V_16 , V_808 ) ;
V_113 -> V_809 += F_22 ( V_16 , V_810 ) ;
V_113 -> V_811 += F_22 ( V_16 , V_812 ) ;
if ( V_2 -> V_682 . V_813 ) {
struct V_814 * V_682 = & V_2 -> V_682 ;
struct V_815 * V_813 ;
unsigned int V_164 ;
T_4 V_816 = 0 , V_817 = 0 ;
F_415 (cpu) {
V_813 = F_416 ( V_682 -> V_813 , V_164 ) ;
V_816 += V_813 -> V_816 ;
V_817 += V_813 -> V_817 ;
}
V_113 -> V_818 = V_816 ;
V_113 -> V_819 = V_817 ;
}
#endif
break;
default:
break;
}
V_752 = F_22 ( V_16 , V_820 ) ;
V_113 -> V_752 += V_752 ;
V_113 -> V_821 += F_22 ( V_16 , V_822 ) ;
if ( V_16 -> V_100 . type == V_101 )
V_113 -> V_821 -= V_752 ;
V_113 -> V_823 += F_22 ( V_16 , V_824 ) ;
V_113 -> V_825 += F_22 ( V_16 , V_826 ) ;
V_113 -> V_827 += F_22 ( V_16 , V_828 ) ;
V_113 -> V_829 += F_22 ( V_16 , V_830 ) ;
V_113 -> V_831 += F_22 ( V_16 , V_832 ) ;
V_113 -> V_833 += F_22 ( V_16 , V_834 ) ;
V_113 -> V_835 += F_22 ( V_16 , V_836 ) ;
V_113 -> V_837 += F_22 ( V_16 , V_838 ) ;
V_753 = F_22 ( V_16 , V_839 ) ;
V_113 -> V_840 += V_753 ;
V_754 = F_22 ( V_16 , V_841 ) ;
V_113 -> V_842 += V_754 ;
V_113 -> V_843 += F_22 ( V_16 , V_844 ) ;
V_113 -> V_845 += F_22 ( V_16 , V_846 ) ;
V_755 = V_753 + V_754 ;
V_113 -> V_843 -= V_755 ;
V_113 -> V_845 -= V_755 ;
V_113 -> V_780 -= ( V_755 * ( V_847 + V_503 ) ) ;
V_113 -> V_848 += F_22 ( V_16 , V_849 ) ;
V_113 -> V_850 += F_22 ( V_16 , V_851 ) ;
V_113 -> V_852 += F_22 ( V_16 , V_853 ) ;
V_113 -> V_854 += F_22 ( V_16 , V_855 ) ;
V_113 -> V_856 += F_22 ( V_16 , V_857 ) ;
V_113 -> V_856 -= V_755 ;
V_113 -> V_858 += F_22 ( V_16 , V_859 ) ;
V_113 -> V_860 += F_22 ( V_16 , V_861 ) ;
V_113 -> V_862 += F_22 ( V_16 , V_863 ) ;
V_113 -> V_864 += F_22 ( V_16 , V_865 ) ;
V_113 -> V_866 += F_22 ( V_16 , V_867 ) ;
V_113 -> V_868 += F_22 ( V_16 , V_869 ) ;
V_47 -> V_114 . V_870 = V_113 -> V_821 ;
V_47 -> V_114 . V_871 = V_113 -> V_764 + V_113 -> V_837 ;
V_47 -> V_114 . V_872 = 0 ;
V_47 -> V_114 . V_873 = V_113 -> V_837 ;
V_47 -> V_114 . V_874 = V_113 -> V_764 ;
V_47 -> V_114 . V_875 = V_749 ;
}
static void F_417 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_40 ;
if ( ! ( V_2 -> V_143 & V_375 ) )
return;
V_2 -> V_143 &= ~ V_375 ;
if ( F_13 ( V_34 , & V_2 -> V_35 ) )
return;
if ( ! ( V_2 -> V_129 & V_374 ) )
return;
V_2 -> V_876 ++ ;
if ( F_418 ( V_16 ) == 0 ) {
for ( V_40 = 0 ; V_40 < V_2 -> V_69 ; V_40 ++ )
F_231 ( V_383 ,
& ( V_2 -> V_50 [ V_40 ] -> V_35 ) ) ;
F_56 ( V_16 , V_365 , V_376 ) ;
} else {
F_88 ( V_161 , L_110
L_111 ) ;
}
}
static void F_419 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_4 V_877 = 0 ;
int V_40 ;
if ( F_13 ( V_34 , & V_2 -> V_35 ) ||
F_13 ( V_647 , & V_2 -> V_35 ) )
return;
if ( F_94 ( V_2 -> V_47 ) ) {
for ( V_40 = 0 ; V_40 < V_2 -> V_69 ; V_40 ++ )
F_420 ( V_2 -> V_50 [ V_40 ] ) ;
}
if ( ! ( V_2 -> V_129 & V_398 ) ) {
F_56 ( V_16 , V_109 ,
( V_878 | V_879 ) ) ;
} else {
for ( V_40 = 0 ; V_40 < V_2 -> V_178 ; V_40 ++ ) {
struct V_146 * V_880 = V_2 -> V_147 [ V_40 ] ;
if ( V_880 -> V_306 . V_110 || V_880 -> V_151 . V_110 )
V_877 |= ( ( T_4 ) 1 << V_40 ) ;
}
}
F_60 ( V_2 , V_877 ) ;
}
static void F_421 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_881 = V_2 -> V_881 ;
bool V_349 = V_2 -> V_349 ;
bool V_125 = V_2 -> V_126 . V_127 ;
if ( ! ( V_2 -> V_129 & V_361 ) )
return;
if ( V_16 -> V_100 . V_347 . V_348 ) {
V_16 -> V_100 . V_347 . V_348 ( V_16 , & V_881 , & V_349 , false ) ;
} else {
V_881 = V_882 ;
V_349 = true ;
}
if ( V_2 -> V_128 )
V_125 |= ! ! ( V_2 -> V_128 -> V_125 ) ;
if ( V_349 && ! ( ( V_2 -> V_129 & V_130 ) && V_125 ) ) {
V_16 -> V_100 . V_347 . V_883 ( V_16 ) ;
F_422 ( V_2 ) ;
}
if ( V_349 ||
F_423 ( V_160 , ( V_2 -> V_362 +
V_884 ) ) ) {
V_2 -> V_129 &= ~ V_361 ;
F_56 ( V_16 , V_365 , V_364 ) ;
F_199 ( V_16 ) ;
}
V_2 -> V_349 = V_349 ;
V_2 -> V_881 = V_881 ;
}
static void F_424 ( struct V_1 * V_2 )
{
#ifdef F_310
struct V_46 * V_47 = V_2 -> V_47 ;
struct V_885 V_886 = {
. V_887 = V_888 ,
. V_232 = 0 ,
} ;
T_6 V_683 = 0 ;
if ( V_2 -> V_572 & V_889 )
V_683 = F_425 ( V_47 , & V_886 ) ;
V_2 -> V_890 = ( V_683 > 1 ) ? ( F_426 ( V_683 ) - 1 ) : 0 ;
#endif
}
static void F_427 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_881 = V_2 -> V_881 ;
bool V_891 , V_892 ;
if ( F_94 ( V_47 ) )
return;
V_2 -> V_143 &= ~ V_619 ;
switch ( V_16 -> V_100 . type ) {
case V_101 : {
T_1 V_893 = F_22 ( V_16 , V_554 ) ;
T_1 V_894 = F_22 ( V_16 , V_895 ) ;
V_891 = ! ! ( V_893 & V_896 ) ;
V_892 = ! ! ( V_894 & V_897 ) ;
}
break;
case V_104 :
case V_103 : {
T_1 V_898 = F_22 ( V_16 , V_899 ) ;
T_1 V_900 = F_22 ( V_16 , V_901 ) ;
V_891 = ! ! ( V_898 & V_902 ) ;
V_892 = ! ! ( V_900 & V_903 ) ;
}
break;
default:
V_892 = false ;
V_891 = false ;
break;
}
V_2 -> V_904 = V_160 ;
if ( F_13 ( V_656 , & V_2 -> V_35 ) )
F_428 ( V_2 ) ;
F_90 ( V_145 , L_112 ,
( V_881 == V_882 ?
L_113 :
( V_881 == V_905 ?
L_114 :
( V_881 == V_906 ?
L_115 :
L_116 ) ) ) ,
( ( V_891 && V_892 ) ? L_117 :
( V_891 ? L_118 :
( V_892 ? L_119 : L_120 ) ) ) ) ;
F_429 ( V_47 ) ;
F_430 ( V_2 ) ;
F_424 ( V_2 ) ;
F_343 ( V_2 ) ;
}
static void F_431 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
V_2 -> V_349 = false ;
V_2 -> V_881 = 0 ;
if ( ! F_94 ( V_47 ) )
return;
if ( F_314 ( V_16 ) && V_16 -> V_100 . type == V_101 )
V_2 -> V_143 |= V_619 ;
if ( F_13 ( V_656 , & V_2 -> V_35 ) )
F_428 ( V_2 ) ;
F_90 ( V_145 , L_121 ) ;
F_340 ( V_47 ) ;
F_343 ( V_2 ) ;
}
static void F_432 ( struct V_1 * V_2 )
{
int V_40 ;
int V_907 = 0 ;
if ( ! F_94 ( V_2 -> V_47 ) ) {
for ( V_40 = 0 ; V_40 < V_2 -> V_69 ; V_40 ++ ) {
struct V_49 * V_50 = V_2 -> V_50 [ V_40 ] ;
if ( V_50 -> V_72 != V_50 -> V_71 ) {
V_907 = 1 ;
break;
}
}
if ( V_907 ) {
F_78 ( V_145 , L_122 ) ;
V_2 -> V_143 |= V_144 ;
}
}
}
static void F_433 ( struct V_1 * V_2 )
{
T_1 V_908 ;
if ( V_2 -> V_16 . V_100 . type == V_101 ||
V_2 -> V_314 == 0 )
return;
V_908 = F_22 ( & V_2 -> V_16 , V_909 ) ;
if ( ! V_908 )
return;
F_78 ( V_145 , L_123 , V_908 ) ;
}
static void F_434 ( struct V_1 * V_2 )
{
if ( F_13 ( V_34 , & V_2 -> V_35 ) ||
F_13 ( V_647 , & V_2 -> V_35 ) )
return;
F_421 ( V_2 ) ;
if ( V_2 -> V_349 )
F_427 ( V_2 ) ;
else
F_431 ( V_2 ) ;
F_433 ( V_2 ) ;
F_399 ( V_2 ) ;
F_432 ( V_2 ) ;
}
static void F_435 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_3 V_18 ;
if ( ! ( V_2 -> V_143 & V_619 ) &&
! ( V_2 -> V_143 & V_358 ) )
return;
if ( F_14 ( V_648 , & V_2 -> V_35 ) )
return;
V_18 = V_16 -> V_350 . V_347 . V_910 ( V_16 ) ;
if ( V_18 == V_651 )
goto V_911;
if ( V_18 == V_650 ) {
V_2 -> V_143 |= V_358 ;
}
if ( V_18 )
goto V_911;
if ( ! ( V_2 -> V_143 & V_358 ) )
goto V_911;
V_2 -> V_143 &= ~ V_358 ;
if ( V_16 -> V_100 . type == V_101 )
V_18 = V_16 -> V_350 . V_347 . V_912 ( V_16 ) ;
else
V_18 = V_16 -> V_100 . V_347 . V_913 ( V_16 ) ;
if ( V_18 == V_651 )
goto V_911;
V_2 -> V_129 |= V_359 ;
F_90 ( V_161 , L_124 , V_16 -> V_350 . V_914 ) ;
V_911:
F_19 ( V_648 , & V_2 -> V_35 ) ;
if ( ( V_18 == V_651 ) &&
( V_2 -> V_47 -> V_915 == V_916 ) ) {
F_329 ( L_125
L_126 ) ;
F_329 ( L_127
L_128 ) ;
F_436 ( V_2 -> V_47 ) ;
}
}
static void F_437 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_21 ;
bool V_620 = false ;
if ( ! ( V_2 -> V_129 & V_359 ) )
return;
if ( F_14 ( V_648 , & V_2 -> V_35 ) )
return;
V_2 -> V_129 &= ~ V_359 ;
V_21 = V_16 -> V_350 . V_623 ;
if ( ( ! V_21 ) && ( V_16 -> V_100 . V_347 . V_624 ) ) {
V_16 -> V_100 . V_347 . V_624 ( V_16 , & V_21 , & V_620 ) ;
if ( ! V_620 ) {
if ( V_21 & V_882 )
V_21 = V_882 ;
}
}
if ( V_16 -> V_100 . V_347 . V_625 )
V_16 -> V_100 . V_347 . V_625 ( V_16 , V_21 , true ) ;
V_2 -> V_129 |= V_361 ;
V_2 -> V_362 = V_160 ;
F_19 ( V_648 , & V_2 -> V_35 ) ;
}
static void F_438 ( struct V_1 * V_2 )
{
int V_917 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_46 * V_47 = V_2 -> V_47 ;
T_1 V_918 ;
T_1 V_919 , V_920 ;
V_918 = F_22 ( V_16 , V_921 ) ;
if ( V_918 )
return;
for ( V_917 = 0 ; V_917 < V_2 -> V_314 ; V_917 ++ ) {
V_919 = ( V_917 << 16 ) | 0x80000000 ;
V_919 |= V_922 ;
F_56 ( V_16 , V_923 , V_919 ) ;
V_920 = F_22 ( V_16 , V_924 ) ;
V_919 &= 0x7FFFFFFF ;
F_56 ( V_16 , V_923 , V_919 ) ;
V_920 >>= 16 ;
if ( V_920 & V_925 ) {
F_439 ( V_47 , L_129 , V_917 ) ;
V_919 = ( V_917 << 16 ) | 0x80000000 ;
V_919 |= 0xA8 ;
F_56 ( V_16 , V_923 , V_919 ) ;
V_920 = 0x00008000 ;
F_56 ( V_16 , V_924 , V_920 ) ;
V_919 &= 0x7FFFFFFF ;
F_56 ( V_16 , V_923 , V_919 ) ;
}
}
}
static void F_440 ( unsigned long V_84 )
{
struct V_1 * V_2 = (struct V_1 * ) V_84 ;
unsigned long V_926 ;
bool V_927 = true ;
if ( V_2 -> V_129 & V_361 )
V_926 = V_928 / 10 ;
else
V_926 = V_928 * 2 ;
#ifdef F_352
if ( ! V_2 -> V_314 ||
( V_2 -> V_129 & V_361 ) )
goto V_929;
F_438 ( V_2 ) ;
V_926 = V_928 / 50 ;
V_2 -> V_930 ++ ;
if ( V_2 -> V_930 >= 100 )
V_2 -> V_930 = 0 ;
else
V_927 = false ;
V_929:
#endif
F_321 ( & V_2 -> V_645 , V_926 + V_160 ) ;
if ( V_927 )
F_12 ( V_2 ) ;
}
static void F_441 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_143 & V_144 ) )
return;
V_2 -> V_143 &= ~ V_144 ;
if ( F_13 ( V_34 , & V_2 -> V_35 ) ||
F_13 ( V_647 , & V_2 -> V_35 ) )
return;
F_39 ( V_2 ) ;
F_439 ( V_2 -> V_47 , L_130 ) ;
V_2 -> V_162 ++ ;
F_322 ( V_2 ) ;
}
static void F_442 ( struct V_931 * V_932 )
{
struct V_1 * V_2 = F_183 ( V_932 ,
struct V_1 ,
V_37 ) ;
F_441 ( V_2 ) ;
F_435 ( V_2 ) ;
F_437 ( V_2 ) ;
F_193 ( V_2 ) ;
F_434 ( V_2 ) ;
F_417 ( V_2 ) ;
F_419 ( V_2 ) ;
if ( F_13 ( V_656 , & V_2 -> V_35 ) ) {
F_443 ( V_2 ) ;
F_444 ( V_2 ) ;
}
F_16 ( V_2 ) ;
}
static int F_445 ( struct V_49 * V_50 ,
struct V_51 * V_933 ,
T_6 * V_250 )
{
struct V_184 * V_81 = V_933 -> V_81 ;
T_1 V_934 , V_935 ;
T_1 V_936 , V_937 ;
if ( V_81 -> V_207 != V_938 )
return 0 ;
if ( ! F_446 ( V_81 ) )
return 0 ;
if ( F_447 ( V_81 ) ) {
int V_18 = F_448 ( V_81 , 0 , 0 , V_212 ) ;
if ( V_18 )
return V_18 ;
}
V_935 = V_939 ;
if ( V_933 -> V_232 == F_132 ( V_240 ) ) {
struct V_227 * V_940 = F_449 ( V_81 ) ;
V_940 -> V_941 = 0 ;
V_940 -> V_942 = 0 ;
F_450 ( V_81 ) -> V_942 = ~ F_451 ( V_940 -> V_943 ,
V_940 -> V_944 , 0 ,
V_246 ,
0 ) ;
V_935 |= V_945 ;
V_933 -> V_946 |= V_947 |
V_948 |
V_949 ;
} else if ( F_452 ( V_81 ) ) {
F_453 ( V_81 ) -> V_950 = 0 ;
F_450 ( V_81 ) -> V_942 =
~ F_454 ( & F_453 ( V_81 ) -> V_943 ,
& F_453 ( V_81 ) -> V_944 ,
0 , V_246 , 0 ) ;
V_933 -> V_946 |= V_947 |
V_948 ;
}
V_937 = F_455 ( V_81 ) ;
* V_250 = F_456 ( V_81 ) + V_937 ;
V_933 -> V_157 = F_137 ( V_81 ) -> V_157 ;
V_933 -> V_156 += ( V_933 -> V_157 - 1 ) * * V_250 ;
V_936 = V_937 << V_951 ;
V_936 |= F_137 ( V_81 ) -> V_251 << V_952 ;
V_934 = F_457 ( V_81 ) ;
V_934 |= F_458 ( V_81 ) << V_953 ;
V_934 |= V_933 -> V_946 & V_954 ;
F_459 ( V_50 , V_934 , 0 , V_935 ,
V_936 ) ;
return 1 ;
}
static void F_460 ( struct V_49 * V_50 ,
struct V_51 * V_933 )
{
struct V_184 * V_81 = V_933 -> V_81 ;
T_1 V_934 = 0 ;
T_1 V_936 = 0 ;
T_1 V_935 = 0 ;
if ( V_81 -> V_207 != V_938 ) {
if ( ! ( V_933 -> V_946 & V_955 ) &&
! ( V_933 -> V_946 & V_956 ) )
return;
} else {
T_6 V_957 = 0 ;
switch ( V_933 -> V_232 ) {
case F_132 ( V_240 ) :
V_934 |= F_457 ( V_81 ) ;
V_935 |= V_945 ;
V_957 = F_449 ( V_81 ) -> V_232 ;
break;
case F_132 ( V_243 ) :
V_934 |= F_457 ( V_81 ) ;
V_957 = F_453 ( V_81 ) -> V_233 ;
break;
default:
if ( F_82 ( F_461 () ) ) {
F_462 ( V_50 -> V_65 ,
L_131 ,
V_933 -> V_232 ) ;
}
break;
}
switch ( V_957 ) {
case V_246 :
V_935 |= V_939 ;
V_936 = F_455 ( V_81 ) <<
V_951 ;
break;
case V_958 :
V_935 |= V_959 ;
V_936 = sizeof( struct V_960 ) <<
V_951 ;
break;
case V_248 :
V_936 = sizeof( struct V_249 ) <<
V_951 ;
break;
default:
if ( F_82 ( F_461 () ) ) {
F_462 ( V_50 -> V_65 ,
L_132 ,
V_957 ) ;
}
break;
}
V_933 -> V_946 |= V_948 ;
}
V_934 |= F_458 ( V_81 ) << V_953 ;
V_934 |= V_933 -> V_946 & V_954 ;
F_459 ( V_50 , V_934 , 0 ,
V_935 , V_936 ) ;
}
static T_1 F_463 ( struct V_184 * V_81 , T_1 V_946 )
{
T_1 V_961 = V_962 |
V_963 |
V_964 ;
V_961 |= F_464 ( V_946 , V_955 ,
V_965 ) ;
V_961 |= F_464 ( V_946 , V_947 ,
V_966 ) ;
V_961 |= F_464 ( V_946 , V_967 ,
V_968 ) ;
V_961 ^= F_464 ( V_81 -> V_969 , 1 , V_964 ) ;
return V_961 ;
}
static void F_465 ( union V_53 * V_54 ,
T_1 V_946 , unsigned int V_970 )
{
T_1 V_971 = V_970 << V_972 ;
V_971 |= F_464 ( V_946 ,
V_948 ,
V_973 ) ;
V_971 |= F_464 ( V_946 ,
V_949 ,
V_974 ) ;
V_971 |= F_464 ( V_946 ,
V_956 ,
V_975 ) ;
V_54 -> V_218 . V_971 = F_81 ( V_971 ) ;
}
static void F_466 ( struct V_49 * V_50 ,
struct V_51 * V_933 ,
const T_6 V_250 )
{
struct V_184 * V_81 = V_933 -> V_81 ;
struct V_51 * V_52 ;
union V_53 * V_54 ;
struct V_271 * V_272 ;
T_8 V_73 ;
unsigned int V_277 , V_286 ;
T_1 V_946 = V_933 -> V_946 ;
T_1 V_961 = F_463 ( V_81 , V_946 ) ;
T_2 V_40 = V_50 -> V_72 ;
V_54 = F_46 ( V_50 , V_40 ) ;
F_465 ( V_54 , V_946 , V_81 -> V_74 - V_250 ) ;
V_286 = F_136 ( V_81 ) ;
V_277 = V_81 -> V_277 ;
#ifdef F_134
if ( V_946 & V_976 ) {
if ( V_277 < sizeof( struct V_305 ) ) {
V_286 -= sizeof( struct V_305 ) - V_277 ;
V_277 = 0 ;
} else {
V_277 -= sizeof( struct V_305 ) ;
}
}
#endif
V_73 = F_467 ( V_50 -> V_65 , V_81 -> V_84 , V_286 , V_111 ) ;
V_52 = V_933 ;
for ( V_272 = & F_137 ( V_81 ) -> V_273 [ 0 ] ; ; V_272 ++ ) {
if ( F_127 ( V_50 -> V_65 , V_73 ) )
goto V_977;
F_66 ( V_52 , V_74 , V_286 ) ;
F_468 ( V_52 , V_73 , V_73 ) ;
V_54 -> V_218 . V_978 = F_130 ( V_73 ) ;
while ( F_82 ( V_286 > V_979 ) ) {
V_54 -> V_218 . V_980 =
F_81 ( V_961 ^ V_979 ) ;
V_40 ++ ;
V_54 ++ ;
if ( V_40 == V_50 -> V_80 ) {
V_54 = F_46 ( V_50 , 0 ) ;
V_40 = 0 ;
}
V_54 -> V_218 . V_971 = 0 ;
V_73 += V_979 ;
V_286 -= V_979 ;
V_54 -> V_218 . V_978 = F_130 ( V_73 ) ;
}
if ( F_84 ( ! V_277 ) )
break;
V_54 -> V_218 . V_980 = F_81 ( V_961 ^ V_286 ) ;
V_40 ++ ;
V_54 ++ ;
if ( V_40 == V_50 -> V_80 ) {
V_54 = F_46 ( V_50 , 0 ) ;
V_40 = 0 ;
}
V_54 -> V_218 . V_971 = 0 ;
#ifdef F_134
V_286 = F_348 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_286 = F_469 ( V_272 ) ;
#endif
V_277 -= V_286 ;
V_73 = F_470 ( V_50 -> V_65 , V_272 , 0 , V_286 ,
V_111 ) ;
V_52 = & V_50 -> V_70 [ V_40 ] ;
}
V_961 |= V_286 | V_981 ;
V_54 -> V_218 . V_980 = F_81 ( V_961 ) ;
F_471 ( F_92 ( V_50 ) , V_933 -> V_156 ) ;
V_933 -> V_76 = V_160 ;
F_120 () ;
V_933 -> V_75 = V_54 ;
V_40 ++ ;
if ( V_40 == V_50 -> V_80 )
V_40 = 0 ;
V_50 -> V_72 = V_40 ;
F_121 ( V_40 , V_50 -> V_137 ) ;
return;
V_977:
F_361 ( V_50 -> V_65 , L_133 ) ;
for (; ; ) {
V_52 = & V_50 -> V_70 [ V_40 ] ;
F_62 ( V_50 , V_52 ) ;
if ( V_52 == V_933 )
break;
if ( V_40 == 0 )
V_40 = V_50 -> V_80 ;
V_40 -- ;
}
V_50 -> V_72 = V_40 ;
}
static void F_472 ( struct V_49 * V_110 ,
struct V_51 * V_933 )
{
struct V_146 * V_147 = V_110 -> V_147 ;
union V_982 V_983 = { . V_984 = 0 } ;
union V_982 V_985 = { . V_984 = 0 } ;
union {
unsigned char * V_222 ;
struct V_227 * V_228 ;
struct V_229 * V_230 ;
} V_231 ;
struct V_247 * V_986 ;
T_9 V_987 ;
if ( ! V_147 )
return;
if ( ! V_110 -> V_409 )
return;
V_110 -> V_410 ++ ;
V_231 . V_222 = F_473 ( V_933 -> V_81 ) ;
if ( ( V_933 -> V_232 != F_132 ( V_243 ) ||
V_231 . V_230 -> V_233 != V_246 ) &&
( V_933 -> V_232 != F_132 ( V_240 ) ||
V_231 . V_228 -> V_232 != V_246 ) )
return;
V_986 = F_450 ( V_933 -> V_81 ) ;
if ( ! V_986 || V_986 -> V_988 )
return;
if ( ! V_986 -> V_989 && ( V_110 -> V_410 < V_110 -> V_409 ) )
return;
V_110 -> V_410 = 0 ;
V_987 = F_133 ( V_933 -> V_946 >> V_990 ) ;
V_983 . V_991 . V_987 = V_987 ;
if ( V_933 -> V_946 & ( V_992 | V_955 ) )
V_985 . V_993 . V_994 ^= V_986 -> V_995 ^ F_132 ( V_237 ) ;
else
V_985 . V_993 . V_994 ^= V_986 -> V_995 ^ V_933 -> V_232 ;
V_985 . V_993 . V_996 ^= V_986 -> V_997 ;
if ( V_933 -> V_232 == F_132 ( V_240 ) ) {
V_983 . V_991 . V_998 = V_999 ;
V_985 . V_1000 ^= V_231 . V_228 -> V_943 ^ V_231 . V_228 -> V_944 ;
} else {
V_983 . V_991 . V_998 = V_1001 ;
V_985 . V_1000 ^= V_231 . V_230 -> V_943 . V_1002 [ 0 ] ^
V_231 . V_230 -> V_943 . V_1002 [ 1 ] ^
V_231 . V_230 -> V_943 . V_1002 [ 2 ] ^
V_231 . V_230 -> V_943 . V_1002 [ 3 ] ^
V_231 . V_230 -> V_944 . V_1002 [ 0 ] ^
V_231 . V_230 -> V_944 . V_1002 [ 1 ] ^
V_231 . V_230 -> V_944 . V_1002 [ 2 ] ^
V_231 . V_230 -> V_944 . V_1002 [ 3 ] ;
}
F_474 ( & V_147 -> V_2 -> V_16 ,
V_983 , V_985 , V_110 -> V_78 ) ;
}
static int F_475 ( struct V_49 * V_50 , T_2 V_286 )
{
F_89 ( V_50 -> V_47 , V_50 -> V_78 ) ;
F_96 () ;
if ( F_84 ( F_95 ( V_50 ) < V_286 ) )
return - V_729 ;
F_476 ( V_50 -> V_47 , V_50 -> V_78 ) ;
++ V_50 -> V_140 . V_163 ;
return 0 ;
}
static inline int F_477 ( struct V_49 * V_50 , T_2 V_286 )
{
if ( F_84 ( F_95 ( V_50 ) >= V_286 ) )
return 0 ;
return F_475 ( V_50 , V_286 ) ;
}
static T_2 F_478 ( struct V_46 * V_65 , struct V_184 * V_81 )
{
struct V_1 * V_2 ;
struct V_1003 * V_1004 ;
int V_1005 ;
switch ( F_479 ( V_81 ) ) {
case F_132 ( V_244 ) :
case F_132 ( V_1006 ) :
V_2 = F_74 ( V_65 ) ;
if ( V_2 -> V_129 & V_506 )
break;
default:
return F_480 ( V_65 , V_81 ) ;
}
V_1004 = & V_2 -> V_424 [ V_1007 ] ;
V_1005 = F_481 ( V_81 ) ? F_482 ( V_81 ) :
F_483 () ;
while ( V_1005 >= V_1004 -> V_426 )
V_1005 -= V_1004 -> V_426 ;
return V_1005 + V_1004 -> V_1008 ;
}
T_13 F_484 ( struct V_184 * V_81 ,
struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_51 * V_933 ;
int V_1009 ;
T_1 V_946 = 0 ;
unsigned short V_1004 ;
T_2 V_80 = F_485 ( F_136 ( V_81 ) ) ;
T_9 V_232 = V_81 -> V_232 ;
T_6 V_250 = 0 ;
for ( V_1004 = 0 ; V_1004 < F_137 ( V_81 ) -> V_292 ; V_1004 ++ )
V_80 += F_485 ( F_137 ( V_81 ) -> V_273 [ V_1004 ] . V_286 ) ;
if ( F_477 ( V_50 , V_80 + 3 ) ) {
V_50 -> V_140 . V_756 ++ ;
return V_1010 ;
}
V_933 = & V_50 -> V_70 [ V_50 -> V_72 ] ;
V_933 -> V_81 = V_81 ;
V_933 -> V_156 = V_81 -> V_74 ;
V_933 -> V_157 = 1 ;
if ( F_486 ( V_81 ) ) {
V_946 |= F_487 ( V_81 ) << V_990 ;
V_946 |= V_955 ;
} else if ( V_232 == F_132 ( V_237 ) ) {
struct V_225 * V_1011 , V_1012 ;
V_1011 = F_488 ( V_81 , V_235 , sizeof( V_1012 ) , & V_1012 ) ;
if ( ! V_1011 )
goto V_1013;
V_232 = V_1011 -> V_239 ;
V_946 |= F_489 ( V_1011 -> V_1014 ) <<
V_990 ;
V_946 |= V_992 ;
}
F_490 ( V_81 ) ;
if ( F_82 ( F_137 ( V_81 ) -> V_946 & V_1015 ) ) {
F_137 ( V_81 ) -> V_946 |= V_1016 ;
V_946 |= V_967 ;
V_2 -> V_1017 = F_491 ( V_81 ) ;
V_2 -> V_1018 = V_160 ;
F_15 ( & V_2 -> V_1019 ) ;
}
#ifdef F_352
if ( V_2 -> V_129 & V_419 )
V_946 |= V_956 ;
#endif
if ( ( V_2 -> V_129 & V_130 ) &&
( ( V_946 & ( V_955 | V_992 ) ) ||
( V_81 -> V_1020 != V_1021 ) ) ) {
V_946 &= ~ V_1022 ;
V_946 |= ( V_81 -> V_1020 & 0x7 ) <<
V_1023 ;
if ( V_946 & V_992 ) {
struct V_1024 * V_1011 ;
if ( F_447 ( V_81 ) &&
F_448 ( V_81 , 0 , 0 , V_212 ) )
goto V_1013;
V_1011 = (struct V_1024 * ) V_81 -> V_84 ;
V_1011 -> V_1014 = F_133 ( V_946 >>
V_990 ) ;
} else {
V_946 |= V_955 ;
}
}
V_933 -> V_946 = V_946 ;
V_933 -> V_232 = V_232 ;
#ifdef F_134
if ( ( V_232 == F_132 ( V_244 ) ) &&
( V_50 -> V_47 -> V_185 & ( V_1025 | V_1026 ) ) ) {
V_1009 = F_492 ( V_50 , V_933 , & V_250 ) ;
if ( V_1009 < 0 )
goto V_1013;
goto V_1027;
}
#endif
V_1009 = F_445 ( V_50 , V_933 , & V_250 ) ;
if ( V_1009 < 0 )
goto V_1013;
else if ( ! V_1009 )
F_460 ( V_50 , V_933 ) ;
if ( F_13 ( V_383 , & V_50 -> V_35 ) )
F_472 ( V_50 , V_933 ) ;
#ifdef F_134
V_1027:
#endif
F_466 ( V_50 , V_933 , V_250 ) ;
F_477 ( V_50 , V_1028 ) ;
return V_1029 ;
V_1013:
F_63 ( V_933 -> V_81 ) ;
V_933 -> V_81 = NULL ;
return V_1029 ;
}
static T_13 F_493 ( struct V_184 * V_81 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_74 ( V_47 ) ;
struct V_49 * V_50 ;
if ( F_82 ( V_81 -> V_74 < 17 ) ) {
if ( F_163 ( V_81 , 17 - V_81 -> V_74 ) )
return V_1029 ;
V_81 -> V_74 = 17 ;
F_494 ( V_81 , 17 ) ;
}
V_50 = V_2 -> V_50 [ V_81 -> V_1030 ] ;
return F_484 ( V_81 , V_2 , V_50 ) ;
}
static int F_495 ( struct V_46 * V_47 , void * V_472 )
{
struct V_1 * V_2 = F_74 ( V_47 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_1031 * V_547 = V_472 ;
if ( ! F_496 ( V_547 -> V_1032 ) )
return - V_1033 ;
memcpy ( V_47 -> V_1034 , V_547 -> V_1032 , V_47 -> V_1035 ) ;
memcpy ( V_16 -> V_100 . V_547 , V_547 -> V_1032 , V_47 -> V_1035 ) ;
V_16 -> V_100 . V_347 . V_546 ( V_16 , 0 , V_16 -> V_100 . V_547 , F_251 ( 0 ) , V_548 ) ;
return 0 ;
}
static int
F_497 ( struct V_46 * V_47 , int V_1036 , int V_1037 , T_2 V_547 )
{
struct V_1 * V_2 = F_74 ( V_47 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_2 V_4 ;
int V_1038 ;
if ( V_1036 != V_16 -> V_350 . V_1039 . V_1036 )
return - V_727 ;
V_1038 = V_16 -> V_350 . V_347 . V_1040 ( V_16 , V_547 , V_1037 , & V_4 ) ;
if ( ! V_1038 )
V_1038 = V_4 ;
return V_1038 ;
}
static int F_498 ( struct V_46 * V_47 , int V_1036 , int V_1037 ,
T_2 V_547 , T_2 V_4 )
{
struct V_1 * V_2 = F_74 ( V_47 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
if ( V_1036 != V_16 -> V_350 . V_1039 . V_1036 )
return - V_727 ;
return V_16 -> V_350 . V_347 . V_1041 ( V_16 , V_547 , V_1037 , V_4 ) ;
}
static int F_499 ( struct V_46 * V_47 , struct V_1042 * V_1043 , int V_1044 )
{
struct V_1 * V_2 = F_74 ( V_47 ) ;
switch ( V_1044 ) {
case V_1045 :
return F_500 ( V_2 , V_1043 , V_1044 ) ;
default:
return F_501 ( & V_2 -> V_16 . V_350 . V_1039 , F_502 ( V_1043 ) , V_1044 ) ;
}
}
static int F_503 ( struct V_46 * V_65 )
{
int V_18 = 0 ;
struct V_1 * V_2 = F_74 ( V_65 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
if ( F_496 ( V_16 -> V_100 . V_1046 ) ) {
F_387 () ;
V_18 = F_504 ( V_65 , V_16 -> V_100 . V_1046 , V_1047 ) ;
F_389 () ;
V_16 -> V_100 . V_347 . V_655 ( V_16 , F_251 ( 0 ) ) ;
}
return V_18 ;
}
static int F_505 ( struct V_46 * V_65 )
{
int V_18 = 0 ;
struct V_1 * V_2 = F_74 ( V_65 ) ;
struct V_1048 * V_100 = & V_2 -> V_16 . V_100 ;
if ( F_496 ( V_100 -> V_1046 ) ) {
F_387 () ;
V_18 = F_506 ( V_65 , V_100 -> V_1046 , V_1047 ) ;
F_389 () ;
}
return V_18 ;
}
static void F_507 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_74 ( V_47 ) ;
int V_40 ;
if ( F_13 ( V_34 , & V_2 -> V_35 ) )
return;
V_2 -> V_129 |= V_260 ;
if ( V_2 -> V_129 & V_398 ) {
for ( V_40 = 0 ; V_40 < V_2 -> V_178 ; V_40 ++ )
F_209 ( 0 , V_2 -> V_147 [ V_40 ] ) ;
} else {
F_222 ( V_2 -> V_10 -> V_377 , V_47 ) ;
}
V_2 -> V_129 &= ~ V_260 ;
}
static struct V_1049 * F_508 ( struct V_46 * V_47 ,
struct V_1049 * V_114 )
{
struct V_1 * V_2 = F_74 ( V_47 ) ;
int V_40 ;
F_509 () ;
for ( V_40 = 0 ; V_40 < V_2 -> V_85 ; V_40 ++ ) {
struct V_49 * V_110 = F_510 ( V_2 -> V_59 [ V_40 ] ) ;
T_4 V_159 , V_134 ;
unsigned int V_1050 ;
if ( V_110 ) {
do {
V_1050 = F_511 ( & V_110 -> V_158 ) ;
V_134 = V_110 -> V_114 . V_134 ;
V_159 = V_110 -> V_114 . V_159 ;
} while ( F_512 ( & V_110 -> V_158 , V_1050 ) );
V_114 -> V_761 += V_134 ;
V_114 -> V_760 += V_159 ;
}
}
for ( V_40 = 0 ; V_40 < V_2 -> V_69 ; V_40 ++ ) {
struct V_49 * V_110 = F_510 ( V_2 -> V_50 [ V_40 ] ) ;
T_4 V_159 , V_134 ;
unsigned int V_1050 ;
if ( V_110 ) {
do {
V_1050 = F_511 ( & V_110 -> V_158 ) ;
V_134 = V_110 -> V_114 . V_134 ;
V_159 = V_110 -> V_114 . V_159 ;
} while ( F_512 ( & V_110 -> V_158 , V_1050 ) );
V_114 -> V_763 += V_134 ;
V_114 -> V_762 += V_159 ;
}
}
F_513 () ;
V_114 -> V_870 = V_47 -> V_114 . V_870 ;
V_114 -> V_871 = V_47 -> V_114 . V_871 ;
V_114 -> V_873 = V_47 -> V_114 . V_873 ;
V_114 -> V_874 = V_47 -> V_114 . V_874 ;
V_114 -> V_875 = V_47 -> V_114 . V_875 ;
return V_114 ;
}
static void F_514 ( struct V_1 * V_2 , T_6 V_124 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_3 , V_1051 ;
int V_40 ;
if ( V_16 -> V_100 . type == V_101 )
return;
V_3 = F_22 ( V_16 , V_1052 ) ;
V_1051 = V_3 ;
for ( V_40 = 0 ; V_40 < V_694 ; V_40 ++ ) {
T_6 V_1053 = V_3 >> ( V_40 * V_1054 ) ;
if ( V_1053 > V_124 )
V_3 &= ~ ( 0x7 << V_1054 ) ;
}
if ( V_3 != V_1051 )
F_56 ( V_16 , V_1052 , V_3 ) ;
return;
}
static void F_515 ( struct V_1 * V_2 )
{
struct V_46 * V_65 = V_2 -> V_47 ;
struct V_1055 * V_126 = & V_2 -> V_126 ;
struct V_1056 * V_1057 = V_2 -> V_576 ;
T_6 V_1058 ;
for ( V_1058 = 0 ; V_1058 < V_1059 ; V_1058 ++ ) {
T_6 V_124 = 0 ;
if ( V_2 -> V_572 & V_573 )
V_124 = F_516 ( V_126 , 0 , V_1058 ) ;
else if ( V_1057 )
V_124 = V_1057 -> V_577 [ V_1058 ] ;
F_517 ( V_65 , V_1058 , V_124 ) ;
}
}
int F_518 ( struct V_46 * V_65 , T_6 V_124 )
{
struct V_1 * V_2 = F_74 ( V_65 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
if ( V_124 > V_2 -> V_126 . V_690 . V_691 ||
( V_16 -> V_100 . type == V_101 &&
V_124 < V_694 ) )
return - V_727 ;
if ( F_42 ( V_65 ) )
F_377 ( V_65 ) ;
F_394 ( V_2 ) ;
#ifdef F_310
if ( V_124 ) {
F_519 ( V_65 , V_124 ) ;
F_515 ( V_2 ) ;
V_2 -> V_129 |= V_130 ;
if ( V_2 -> V_16 . V_100 . type == V_101 ) {
V_2 -> V_1060 = V_2 -> V_16 . V_115 . V_706 ;
V_2 -> V_16 . V_115 . V_706 = V_1061 ;
}
} else {
F_520 ( V_65 ) ;
if ( V_2 -> V_16 . V_100 . type == V_101 )
V_2 -> V_16 . V_115 . V_706 = V_2 -> V_1060 ;
V_2 -> V_129 &= ~ V_130 ;
V_2 -> V_705 . V_127 = false ;
V_2 -> V_126 . V_127 = false ;
}
F_514 ( V_2 , V_124 ) ;
#endif
F_388 ( V_2 ) ;
if ( F_42 ( V_65 ) )
return F_373 ( V_65 ) ;
return 0 ;
}
void F_521 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
F_387 () ;
F_518 ( V_47 , F_235 ( V_47 ) ) ;
F_389 () ;
}
void F_522 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_74 ( V_47 ) ;
if ( F_42 ( V_47 ) )
F_322 ( V_2 ) ;
else
F_328 ( V_2 ) ;
}
static T_14 F_523 ( struct V_46 * V_47 ,
T_14 V_185 )
{
struct V_1 * V_2 = F_74 ( V_47 ) ;
if ( ! ( V_185 & V_198 ) )
V_185 &= ~ V_1062 ;
if ( ! ( V_2 -> V_143 & V_675 ) )
V_185 &= ~ V_1062 ;
return V_185 ;
}
static int F_524 ( struct V_46 * V_47 ,
T_14 V_185 )
{
struct V_1 * V_2 = F_74 ( V_47 ) ;
T_14 V_1063 = V_47 -> V_185 ^ V_185 ;
bool V_1064 = false ;
if ( ! ( V_185 & V_1062 ) ) {
if ( V_2 -> V_143 & V_514 )
V_1064 = true ;
V_2 -> V_143 &= ~ V_514 ;
} else if ( ( V_2 -> V_143 & V_675 ) &&
! ( V_2 -> V_143 & V_514 ) ) {
if ( V_2 -> V_389 == 1 ||
V_2 -> V_389 > V_1065 ) {
V_2 -> V_143 |= V_514 ;
V_1064 = true ;
} else if ( ( V_1063 ^ V_185 ) & V_1062 ) {
F_90 ( V_161 , L_134
L_135 ) ;
}
}
switch ( V_185 & V_1066 ) {
case V_1066 :
if ( ! ( V_2 -> V_129 & V_590 ) )
V_1064 = true ;
V_2 -> V_129 &= ~ V_374 ;
V_2 -> V_129 |= V_590 ;
break;
default:
if ( V_2 -> V_129 & V_590 )
V_1064 = true ;
V_2 -> V_129 &= ~ V_590 ;
if ( V_2 -> V_129 & V_419 )
break;
if ( F_235 ( V_47 ) > 1 )
break;
if ( V_2 -> V_424 [ V_425 ] . V_674 <= 1 )
break;
if ( ! V_2 -> V_409 )
break;
V_2 -> V_129 |= V_374 ;
break;
}
if ( V_185 & V_257 )
F_266 ( V_2 ) ;
else
F_265 ( V_2 ) ;
if ( V_1063 & V_280 )
V_1064 = true ;
V_47 -> V_185 = V_185 ;
if ( V_1064 )
F_522 ( V_47 ) ;
return 0 ;
}
static int F_525 ( struct V_1067 * V_1068 , struct V_1069 * V_1070 [] ,
struct V_46 * V_65 ,
const unsigned char * V_547 ,
T_2 V_129 )
{
struct V_1 * V_2 = F_74 ( V_65 ) ;
int V_18 ;
if ( ! ( V_2 -> V_129 & V_419 ) )
return F_526 ( V_1068 , V_1070 , V_65 , V_547 , V_129 ) ;
if ( V_1068 -> V_1071 && ! ( V_1068 -> V_1071 & V_1072 ) ) {
F_36 ( L_136 ,
V_1073 ) ;
return - V_727 ;
}
if ( F_527 ( V_547 ) || F_528 ( V_547 ) ) {
T_1 V_1074 = V_542 ;
if ( F_270 ( V_65 ) < V_1074 )
V_18 = F_529 ( V_65 , V_547 ) ;
else
V_18 = - V_543 ;
} else if ( F_530 ( V_547 ) ) {
V_18 = F_531 ( V_65 , V_547 ) ;
} else {
V_18 = - V_727 ;
}
if ( V_18 == - V_1075 && ! ( V_129 & V_1076 ) )
V_18 = 0 ;
return V_18 ;
}
static int F_532 ( struct V_46 * V_65 ,
struct V_1077 * V_1078 )
{
struct V_1 * V_2 = F_74 ( V_65 ) ;
struct V_1069 * V_1079 , * V_1080 ;
int V_1081 ;
if ( ! ( V_2 -> V_129 & V_419 ) )
return - V_1082 ;
V_1080 = F_533 ( V_1078 , sizeof( struct V_1083 ) , V_1084 ) ;
F_534 (attr, br_spec, rem) {
T_15 V_1085 ;
T_1 V_3 = 0 ;
if ( F_535 ( V_1079 ) != V_1086 )
continue;
V_1085 = F_536 ( V_1079 ) ;
if ( V_1085 == V_1087 ) {
V_3 = 0 ;
V_2 -> V_143 &= ~ V_488 ;
} else if ( V_1085 == V_1088 ) {
V_3 = V_490 ;
V_2 -> V_143 |= V_488 ;
} else
return - V_727 ;
F_56 ( & V_2 -> V_16 , V_489 , V_3 ) ;
F_90 ( V_145 , L_137 ,
V_1085 == V_1087 ? L_138 : L_139 ) ;
}
return 0 ;
}
static int F_537 ( struct V_184 * V_81 , T_1 V_1089 , T_1 V_1090 ,
struct V_46 * V_65 ,
T_1 V_1091 )
{
struct V_1 * V_2 = F_74 ( V_65 ) ;
T_2 V_1085 ;
if ( ! ( V_2 -> V_129 & V_419 ) )
return 0 ;
if ( V_2 -> V_143 & V_488 )
V_1085 = V_1088 ;
else
V_1085 = V_1087 ;
return F_538 ( V_81 , V_1089 , V_1090 , V_65 , V_1085 ) ;
}
static inline int F_539 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_1092 * V_394 ;
int V_1093 = 0 ;
switch ( V_16 -> V_22 ) {
case V_23 :
case V_24 :
V_1093 = 4 ;
break;
default:
F_540 (entry, &adapter->pdev->bus_list) {
struct V_6 * V_10 =
F_541 ( V_394 , struct V_6 , V_1094 ) ;
if ( ! V_10 -> V_1095 )
V_1093 ++ ;
}
}
return V_1093 ;
}
int F_542 ( struct V_1 * V_2 , T_2 V_22 ,
T_2 V_1096 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_2 V_1097 = V_2 -> V_1098 & V_1099 ;
int V_1100 = 0 ;
switch ( V_22 ) {
case V_1101 :
switch ( V_1096 ) {
case V_1102 :
if ( V_16 -> V_11 . V_1103 != 0 )
break;
case V_1104 :
case V_1105 :
case V_1106 :
case V_1107 :
case V_1108 :
V_1100 = 1 ;
break;
}
break;
case V_1109 :
switch ( V_1096 ) {
case V_1110 :
V_1100 = 1 ;
break;
}
break;
case V_1111 :
if ( V_1096 != V_1112 )
V_1100 = 1 ;
break;
case V_1113 :
V_1100 = 1 ;
break;
case V_1114 :
case V_1115 :
if ( ( V_1097 == V_1116 ) ||
( ( V_1097 == V_1117 ) &&
( V_16 -> V_11 . V_1103 == 0 ) ) ) {
V_1100 = 1 ;
}
break;
}
return V_1100 ;
}
static int F_543 ( struct V_6 * V_10 , const struct V_1118 * V_1119 )
{
struct V_46 * V_47 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_16 ;
const struct V_1120 * V_1121 = V_1122 [ V_1119 -> V_1123 ] ;
static int V_1124 ;
int V_40 , V_18 , V_1125 , V_25 ;
unsigned int V_426 = V_1126 ;
T_6 V_1127 [ V_1128 ] ;
#ifdef F_134
T_2 V_1129 ;
#endif
T_1 V_1130 ;
if ( V_10 -> V_1095 ) {
F_544 ( 1 , V_1131 L_140 ,
F_545 ( V_10 ) , V_10 -> V_666 , V_10 -> V_179 ) ;
return - V_727 ;
}
V_18 = F_384 ( V_10 ) ;
if ( V_18 )
return V_18 ;
if ( ! F_546 ( & V_10 -> V_65 , F_229 ( 64 ) ) &&
! F_547 ( & V_10 -> V_65 , F_229 ( 64 ) ) ) {
V_1125 = 1 ;
} else {
V_18 = F_546 ( & V_10 -> V_65 , F_229 ( 32 ) ) ;
if ( V_18 ) {
V_18 = F_547 ( & V_10 -> V_65 ,
F_229 ( 32 ) ) ;
if ( V_18 ) {
F_361 ( & V_10 -> V_65 ,
L_141 ) ;
goto V_1132;
}
}
V_1125 = 0 ;
}
V_18 = F_548 ( V_10 , F_549 ( V_10 ,
V_1133 ) , V_1073 ) ;
if ( V_18 ) {
F_361 ( & V_10 -> V_65 ,
L_142 , V_18 ) ;
goto V_1134;
}
F_550 ( V_10 ) ;
F_385 ( V_10 ) ;
F_383 ( V_10 ) ;
if ( V_1121 -> V_100 == V_101 ) {
#ifdef F_310
V_426 = 4 * V_694 ;
#else
V_426 = V_673 ;
#endif
}
V_47 = F_551 ( sizeof( struct V_1 ) , V_426 ) ;
if ( ! V_47 ) {
V_18 = - V_543 ;
goto V_1135;
}
F_552 ( V_47 , & V_10 -> V_65 ) ;
V_2 = F_74 ( V_47 ) ;
F_553 ( V_10 , V_2 ) ;
V_2 -> V_47 = V_47 ;
V_2 -> V_10 = V_10 ;
V_16 = & V_2 -> V_16 ;
V_16 -> V_1136 = V_2 ;
V_2 -> V_1137 = F_554 ( V_1138 , V_1139 ) ;
V_16 -> V_407 = F_555 ( F_556 ( V_10 , 0 ) ,
F_557 ( V_10 , 0 ) ) ;
if ( ! V_16 -> V_407 ) {
V_18 = - V_719 ;
goto V_1140;
}
V_47 -> V_1141 = & V_1142 ;
F_558 ( V_47 ) ;
V_47 -> V_1143 = 5 * V_928 ;
strncpy ( V_47 -> V_45 , F_545 ( V_10 ) , sizeof( V_47 -> V_45 ) - 1 ) ;
V_2 -> V_1144 = V_1124 ;
memcpy ( & V_16 -> V_100 . V_347 , V_1121 -> V_1145 , sizeof( V_16 -> V_100 . V_347 ) ) ;
V_16 -> V_100 . type = V_1121 -> V_100 ;
memcpy ( & V_16 -> V_1146 . V_347 , V_1121 -> V_1147 , sizeof( V_16 -> V_1146 . V_347 ) ) ;
V_1130 = F_22 ( V_16 , V_1148 ) ;
if ( ! ( V_1130 & ( 1 << 8 ) ) )
V_16 -> V_1146 . V_347 . V_218 = & V_1149 ;
memcpy ( & V_16 -> V_350 . V_347 , V_1121 -> V_1150 , sizeof( V_16 -> V_350 . V_347 ) ) ;
V_16 -> V_350 . V_914 = V_1151 ;
V_16 -> V_350 . V_1039 . V_1036 = V_1152 ;
V_16 -> V_350 . V_1039 . V_1153 = 0 ;
V_16 -> V_350 . V_1039 . V_1154 = V_1155 | V_1156 ;
V_16 -> V_350 . V_1039 . V_65 = V_47 ;
V_16 -> V_350 . V_1039 . V_1157 = F_497 ;
V_16 -> V_350 . V_1039 . V_1158 = F_498 ;
V_1121 -> V_1159 ( V_16 ) ;
V_18 = F_347 ( V_2 ) ;
if ( V_18 )
goto V_1160;
if ( V_16 -> V_100 . V_347 . V_1161 )
V_16 -> V_1161 = V_16 -> V_100 . V_347 . V_1161 ( V_16 ) ;
switch ( V_2 -> V_16 . V_100 . type ) {
case V_103 :
case V_104 :
F_56 ( & V_2 -> V_16 , V_733 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_129 & V_353 ) {
T_1 V_642 = F_22 ( V_16 , V_643 ) ;
if ( V_642 & V_644 )
F_194 ( V_161 , L_72 ) ;
}
if ( V_1162 )
V_16 -> V_1162 = V_1162 ;
V_16 -> V_350 . V_1163 = true ;
V_18 = V_16 -> V_100 . V_347 . V_1164 ( V_16 ) ;
V_16 -> V_350 . V_1163 = false ;
if ( V_18 == V_650 &&
V_16 -> V_100 . type == V_101 ) {
V_18 = 0 ;
} else if ( V_18 == V_651 ) {
F_329 ( L_143 ) ;
F_329 ( L_144 ) ;
goto V_1160;
} else if ( V_18 ) {
F_329 ( L_145 , V_18 ) ;
goto V_1160;
}
#ifdef F_352
if ( V_2 -> V_16 . V_100 . type == V_101 )
goto V_1165;
F_559 ( V_16 ) ;
memcpy ( & V_16 -> V_1166 . V_347 , V_1121 -> V_1167 , sizeof( V_16 -> V_1166 . V_347 ) ) ;
F_560 ( V_2 ) ;
F_561 ( V_10 , 63 ) ;
V_1165:
#endif
V_47 -> V_185 = V_1168 |
V_1169 |
V_1170 |
V_1171 |
V_257 |
V_1172 |
V_1173 |
V_1174 |
V_186 |
V_198 ;
V_47 -> V_1175 = V_47 -> V_185 ;
switch ( V_2 -> V_16 . V_100 . type ) {
case V_103 :
case V_104 :
V_47 -> V_185 |= V_1176 ;
V_47 -> V_1175 |= V_1176 |
V_1066 ;
break;
default:
break;
}
V_47 -> V_1175 |= V_280 ;
V_47 -> V_1177 |= V_1173 ;
V_47 -> V_1177 |= V_1174 ;
V_47 -> V_1177 |= V_1169 ;
V_47 -> V_1177 |= V_1170 ;
V_47 -> V_1177 |= V_1168 ;
V_47 -> V_1178 |= V_1179 ;
V_47 -> V_1178 |= V_1180 ;
#ifdef F_310
V_47 -> V_1181 = & V_1181 ;
#endif
#ifdef F_134
if ( V_2 -> V_129 & V_681 ) {
unsigned int V_1182 ;
if ( V_16 -> V_100 . V_347 . V_1183 ) {
V_16 -> V_100 . V_347 . V_1183 ( V_16 , & V_1129 ) ;
if ( V_1129 & V_1184 )
V_2 -> V_129 &= ~ V_681 ;
}
V_1182 = F_348 ( int , V_1185 , F_349 () ) ;
V_2 -> V_424 [ V_1007 ] . V_674 = V_1182 ;
V_47 -> V_185 |= V_1025 |
V_1026 ;
V_47 -> V_1177 |= V_1025 |
V_1026 |
V_571 ;
}
#endif
if ( V_1125 ) {
V_47 -> V_185 |= V_1186 ;
V_47 -> V_1177 |= V_1186 ;
}
if ( V_2 -> V_143 & V_675 )
V_47 -> V_1175 |= V_1062 ;
if ( V_2 -> V_143 & V_514 )
V_47 -> V_185 |= V_1062 ;
if ( V_16 -> V_1146 . V_347 . V_1187 ( V_16 , NULL ) < 0 ) {
F_329 ( L_146 ) ;
V_18 = - V_719 ;
goto V_1160;
}
memcpy ( V_47 -> V_1034 , V_16 -> V_100 . V_1188 , V_47 -> V_1035 ) ;
if ( ! F_496 ( V_47 -> V_1034 ) ) {
F_329 ( L_147 ) ;
V_18 = - V_719 ;
goto V_1160;
}
F_562 ( & V_2 -> V_645 , & F_440 ,
( unsigned long ) V_2 ) ;
F_563 ( & V_2 -> V_37 , F_442 ) ;
F_19 ( V_36 , & V_2 -> V_35 ) ;
V_18 = F_388 ( V_2 ) ;
if ( V_18 )
goto V_1160;
V_2 -> V_737 = 0 ;
V_16 -> V_1146 . V_347 . V_218 ( V_16 , 0x2c , & V_2 -> V_1098 ) ;
V_16 -> V_1189 = F_542 ( V_2 , V_10 -> V_179 ,
V_10 -> V_672 ) ;
if ( V_16 -> V_1189 )
V_2 -> V_737 = V_1190 ;
F_564 ( & V_2 -> V_10 -> V_65 , V_2 -> V_737 ) ;
V_16 -> V_1146 . V_347 . V_218 ( V_16 , 0x2e , & V_2 -> V_1191 ) ;
V_16 -> V_1146 . V_347 . V_218 ( V_16 , 0x2d , & V_2 -> V_1192 ) ;
V_16 -> V_100 . V_347 . V_1193 ( V_16 ) ;
if ( F_7 ( V_16 ) )
F_4 ( V_2 ) ;
F_11 ( L_148 ,
( V_16 -> V_11 . V_21 == V_1194 ? L_4 :
V_16 -> V_11 . V_21 == V_1195 ? L_5 :
V_16 -> V_11 . V_21 == V_1196 ? L_6 :
L_7 ) ,
( V_16 -> V_11 . V_20 == V_1197 ? L_149 :
V_16 -> V_11 . V_20 == V_1198 ? L_150 :
V_16 -> V_11 . V_20 == V_1199 ? L_151 :
L_7 ) ,
V_47 -> V_1034 ) ;
V_18 = F_565 ( V_16 , V_1127 , V_1128 ) ;
if ( V_18 )
strncpy ( V_1127 , L_7 , V_1128 ) ;
if ( F_314 ( V_16 ) && V_16 -> V_350 . V_914 != V_1200 )
F_11 ( L_152 ,
V_16 -> V_100 . type , V_16 -> V_350 . type , V_16 -> V_350 . V_914 ,
V_1127 ) ;
else
F_11 ( L_153 ,
V_16 -> V_100 . type , V_16 -> V_350 . type , V_1127 ) ;
switch ( V_16 -> V_100 . type ) {
case V_101 :
V_25 = F_566 ( F_539 ( V_2 ) * 10 , 16 ) ;
break;
default:
V_25 = F_539 ( V_2 ) * 10 ;
break;
}
F_8 ( V_2 , V_25 ) ;
V_18 = V_16 -> V_100 . V_347 . V_1201 ( V_16 ) ;
if ( V_18 == V_653 ) {
F_10 ( L_95
L_154
L_155
L_156
L_99
L_100 ) ;
}
strcpy ( V_47 -> V_45 , L_157 ) ;
V_18 = F_567 ( V_47 ) ;
if ( V_18 )
goto V_1202;
if ( V_16 -> V_100 . V_347 . V_661 )
V_16 -> V_100 . V_347 . V_661 ( V_16 ) ;
F_340 ( V_47 ) ;
#ifdef F_212
if ( F_111 ( & V_10 -> V_65 ) == 0 ) {
V_2 -> V_129 |= V_176 ;
F_108 ( V_2 ) ;
}
#endif
if ( V_2 -> V_129 & V_419 ) {
F_90 ( V_161 , L_158 , V_2 -> V_314 ) ;
for ( V_40 = 0 ; V_40 < V_2 -> V_314 ; V_40 ++ )
F_568 ( V_10 , ( V_40 | 0x10000000 ) ) ;
}
if ( V_16 -> V_100 . V_347 . V_1203 )
V_16 -> V_100 . V_347 . V_1203 ( V_16 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_503 ( V_47 ) ;
F_11 ( L_159 , V_1204 ) ;
V_1124 ++ ;
#ifdef F_569
if ( F_570 ( V_2 ) )
F_88 ( V_161 , L_160 ) ;
#endif
F_571 ( V_2 ) ;
if ( V_16 -> V_1161 && V_16 -> V_100 . V_347 . V_625 )
V_16 -> V_100 . V_347 . V_625 ( V_16 ,
V_882 | V_905 ,
true ) ;
return 0 ;
V_1202:
F_55 ( V_2 ) ;
F_394 ( V_2 ) ;
V_1160:
F_572 ( V_2 ) ;
V_2 -> V_143 &= ~ V_619 ;
F_573 ( V_16 -> V_407 ) ;
V_1140:
F_574 ( V_47 ) ;
V_1135:
F_575 ( V_10 ,
F_549 ( V_10 , V_1133 ) ) ;
V_1134:
V_1132:
F_395 ( V_10 ) ;
return V_18 ;
}
static void F_576 ( struct V_6 * V_10 )
{
struct V_1 * V_2 = F_380 ( V_10 ) ;
struct V_46 * V_47 = V_2 -> V_47 ;
F_577 ( V_2 ) ;
F_231 ( V_34 , & V_2 -> V_35 ) ;
F_578 ( & V_2 -> V_37 ) ;
#ifdef F_212
if ( V_2 -> V_129 & V_176 ) {
V_2 -> V_129 &= ~ V_176 ;
F_112 ( & V_10 -> V_65 ) ;
F_56 ( & V_2 -> V_16 , V_177 , 1 ) ;
}
#endif
#ifdef F_569
F_579 ( V_2 ) ;
#endif
F_505 ( V_47 ) ;
if ( V_47 -> V_915 == V_916 )
F_436 ( V_47 ) ;
#ifdef F_352
if ( V_711 )
F_572 ( V_2 ) ;
#endif
F_394 ( V_2 ) ;
F_55 ( V_2 ) ;
#ifdef F_580
F_221 ( V_2 -> V_128 ) ;
F_221 ( V_2 -> V_576 ) ;
#endif
F_573 ( V_2 -> V_16 . V_407 ) ;
F_575 ( V_10 , F_549 ( V_10 ,
V_1133 ) ) ;
F_11 ( L_161 ) ;
F_574 ( V_47 ) ;
F_581 ( V_10 ) ;
F_395 ( V_10 ) ;
}
static T_16 F_582 ( struct V_6 * V_10 ,
T_17 V_35 )
{
struct V_1 * V_2 = F_380 ( V_10 ) ;
struct V_46 * V_47 = V_2 -> V_47 ;
#ifdef F_352
struct V_6 * V_1205 , * V_1206 ;
T_1 V_1207 , V_1208 , V_1209 , V_1210 ;
int V_917 , V_5 ;
T_2 V_1211 , V_1212 ;
if ( V_2 -> V_16 . V_100 . type == V_101 ||
V_2 -> V_314 == 0 )
goto V_1213;
V_1205 = V_10 -> V_11 -> V_13 ;
while ( V_1205 && ( F_583 ( V_1205 ) != V_1214 ) )
V_1205 = V_1205 -> V_11 -> V_13 ;
if ( ! V_1205 )
goto V_1213;
V_5 = F_584 ( V_1205 , V_1215 ) ;
if ( ! V_5 )
goto V_1213;
F_585 ( V_1205 , V_5 + V_1216 , & V_1207 ) ;
F_585 ( V_1205 , V_5 + V_1216 + 4 , & V_1208 ) ;
F_585 ( V_1205 , V_5 + V_1216 + 8 , & V_1209 ) ;
F_585 ( V_1205 , V_5 + V_1216 + 12 , & V_1210 ) ;
V_1211 = V_1208 >> 16 ;
if ( ! ( V_1211 & 0x0080 ) )
goto V_1213;
V_1212 = V_1211 & 0x01 ;
if ( ( V_1212 & 1 ) == ( V_10 -> V_1217 & 1 ) ) {
unsigned int V_22 ;
V_917 = ( V_1211 & 0x7F ) >> 1 ;
F_329 ( L_162 , V_917 ) ;
F_329 ( L_163
L_164 ,
V_1207 , V_1208 , V_1209 , V_1210 ) ;
switch ( V_2 -> V_16 . V_100 . type ) {
case V_103 :
V_22 = V_1218 ;
break;
case V_104 :
V_22 = V_1219 ;
break;
default:
V_22 = 0 ;
break;
}
V_1206 = F_586 ( V_1220 , V_22 , NULL ) ;
while ( V_1206 ) {
if ( V_1206 -> V_1217 == ( V_1211 & 0xFF ) )
break;
V_1206 = F_586 ( V_1220 ,
V_22 , V_1206 ) ;
}
if ( V_1206 ) {
F_329 ( L_165 , V_917 ) ;
F_587 ( V_1206 , 0xA8 , 0x00008000 ) ;
F_588 ( V_1206 ) ;
}
F_589 ( V_10 ) ;
}
V_2 -> V_1221 ++ ;
return V_1222 ;
V_1213:
#endif
F_393 ( V_47 ) ;
if ( V_35 == V_1223 )
return V_1224 ;
if ( F_42 ( V_47 ) )
F_325 ( V_2 ) ;
F_395 ( V_10 ) ;
return V_1225 ;
}
static T_16 F_590 ( struct V_6 * V_10 )
{
struct V_1 * V_2 = F_380 ( V_10 ) ;
T_16 V_1226 ;
int V_18 ;
if ( F_384 ( V_10 ) ) {
F_88 ( V_161 , L_166 ) ;
V_1226 = V_1224 ;
} else {
F_385 ( V_10 ) ;
F_382 ( V_10 ) ;
F_383 ( V_10 ) ;
F_386 ( V_10 , false ) ;
F_328 ( V_2 ) ;
F_56 ( & V_2 -> V_16 , V_733 , ~ 0 ) ;
V_1226 = V_1222 ;
}
V_18 = F_589 ( V_10 ) ;
if ( V_18 ) {
F_329 ( L_167
L_168 , V_18 ) ;
}
return V_1226 ;
}
static void F_591 ( struct V_6 * V_10 )
{
struct V_1 * V_2 = F_380 ( V_10 ) ;
struct V_46 * V_47 = V_2 -> V_47 ;
#ifdef F_352
if ( V_2 -> V_1221 ) {
F_90 ( V_145 , L_169 ) ;
V_2 -> V_1221 -- ;
return;
}
#endif
if ( F_42 ( V_47 ) )
F_327 ( V_2 ) ;
F_390 ( V_47 ) ;
}
static int T_18 F_592 ( void )
{
int V_142 ;
F_36 ( L_170 , V_1227 , V_1228 ) ;
F_36 ( L_159 , V_1229 ) ;
F_593 () ;
V_142 = F_594 ( & V_1230 ) ;
if ( V_142 ) {
F_595 () ;
return V_142 ;
}
#ifdef F_212
F_596 ( & V_1231 ) ;
#endif
return 0 ;
}
static void T_19 F_597 ( void )
{
#ifdef F_212
F_598 ( & V_1231 ) ;
#endif
F_599 ( & V_1230 ) ;
F_595 () ;
F_600 () ;
}
static int F_601 ( struct V_1232 * V_1233 , unsigned long V_180 ,
void * V_472 )
{
int V_1234 ;
V_1234 = F_602 ( & V_1230 . V_1235 , NULL , & V_180 ,
F_109 ) ;
return V_1234 ? V_1236 : V_1237 ;
}
