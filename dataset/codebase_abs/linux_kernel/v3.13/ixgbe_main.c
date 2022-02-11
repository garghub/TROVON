static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_8 = V_2 -> V_9 -> V_10 -> V_11 ;
if ( ! V_8 )
return - 1 ;
V_6 = V_8 -> V_12 ;
if ( ! V_6 )
return - 1 ;
if ( ! F_2 ( V_6 ) )
return - 1 ;
F_3 ( V_6 , V_3 , V_4 ) ;
return 0 ;
}
static T_3 F_4 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_2 V_15 = 0 ;
int V_16 ;
V_14 -> V_10 . type = V_17 ;
V_16 = F_1 ( V_2 , 18 , & V_15 ) ;
if ( V_16 )
return V_16 ;
V_14 -> V_10 . V_18 = F_5 ( V_15 ) ;
V_14 -> V_10 . V_19 = F_6 ( V_15 ) ;
return 0 ;
}
static inline bool F_7 ( struct V_13 * V_14 )
{
switch ( V_14 -> V_20 ) {
case V_21 :
case V_22 :
return true ;
default:
return false ;
}
}
static void F_8 ( struct V_1 * V_2 ,
int V_23 )
{
int V_24 = 0 ;
enum V_25 V_19 = V_26 ;
enum V_27 V_18 = V_28 ;
struct V_5 * V_9 ;
if ( F_7 ( & V_2 -> V_14 ) )
V_9 = V_2 -> V_9 -> V_10 -> V_11 -> V_12 ;
else
V_9 = V_2 -> V_9 ;
if ( F_9 ( V_9 , & V_19 , & V_18 ) ||
V_19 == V_26 || V_18 == V_28 ) {
F_10 ( L_1 ) ;
return;
}
switch ( V_19 ) {
case V_29 :
V_24 = 2 * V_18 ;
break;
case V_30 :
V_24 = 4 * V_18 ;
break;
case V_31 :
V_24 = 8 * V_18 ;
break;
default:
F_10 ( L_1 ) ;
return;
}
F_11 ( L_2 ,
V_24 ) ;
F_11 ( L_3 ,
( V_19 == V_31 ? L_4 :
V_19 == V_30 ? L_5 :
V_19 == V_29 ? L_6 :
L_7 ) ,
V_18 ,
( V_19 == V_29 ? L_8 :
V_19 == V_30 ? L_8 :
V_19 == V_31 ? L_9 :
L_7 ) ) ;
if ( V_24 < V_23 ) {
F_10 ( L_10 ) ;
F_10 ( L_11 ,
V_23 ) ;
F_10 ( L_12 ) ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
if ( ! F_13 ( V_32 , & V_2 -> V_33 ) &&
! F_14 ( V_34 , & V_2 -> V_33 ) )
F_15 ( & V_2 -> V_35 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_17 ( ! F_13 ( V_34 , & V_2 -> V_33 ) ) ;
F_18 () ;
F_19 ( V_34 , & V_2 -> V_33 ) ;
}
static void F_20 ( struct V_13 * V_14 , struct V_36 * V_37 )
{
int V_38 = 0 , V_39 = 0 ;
char V_40 [ 16 ] ;
T_1 V_41 [ 64 ] ;
switch ( V_37 -> V_42 ) {
case F_21 ( 0 ) :
for ( V_38 = 0 ; V_38 < 64 ; V_38 ++ )
V_41 [ V_38 ] = F_22 ( V_14 , F_21 ( V_38 ) ) ;
break;
case F_23 ( 0 ) :
for ( V_38 = 0 ; V_38 < 64 ; V_38 ++ )
V_41 [ V_38 ] = F_22 ( V_14 , F_23 ( V_38 ) ) ;
break;
case F_24 ( 0 ) :
for ( V_38 = 0 ; V_38 < 64 ; V_38 ++ )
V_41 [ V_38 ] = F_22 ( V_14 , F_24 ( V_38 ) ) ;
break;
case F_25 ( 0 ) :
for ( V_38 = 0 ; V_38 < 64 ; V_38 ++ )
V_41 [ V_38 ] = F_22 ( V_14 , F_25 ( V_38 ) ) ;
break;
case F_26 ( 0 ) :
for ( V_38 = 0 ; V_38 < 64 ; V_38 ++ )
V_41 [ V_38 ] = F_22 ( V_14 , F_26 ( V_38 ) ) ;
break;
case F_27 ( 0 ) :
for ( V_38 = 0 ; V_38 < 64 ; V_38 ++ )
V_41 [ V_38 ] = F_22 ( V_14 , F_27 ( V_38 ) ) ;
break;
case F_28 ( 0 ) :
for ( V_38 = 0 ; V_38 < 64 ; V_38 ++ )
V_41 [ V_38 ] = F_22 ( V_14 , F_28 ( V_38 ) ) ;
break;
case F_29 ( 0 ) :
for ( V_38 = 0 ; V_38 < 64 ; V_38 ++ )
V_41 [ V_38 ] = F_22 ( V_14 , F_29 ( V_38 ) ) ;
break;
case F_30 ( 0 ) :
for ( V_38 = 0 ; V_38 < 64 ; V_38 ++ )
V_41 [ V_38 ] = F_22 ( V_14 , F_30 ( V_38 ) ) ;
break;
case F_31 ( 0 ) :
for ( V_38 = 0 ; V_38 < 64 ; V_38 ++ )
V_41 [ V_38 ] = F_22 ( V_14 , F_31 ( V_38 ) ) ;
break;
case F_32 ( 0 ) :
for ( V_38 = 0 ; V_38 < 64 ; V_38 ++ )
V_41 [ V_38 ] = F_22 ( V_14 , F_32 ( V_38 ) ) ;
break;
case F_33 ( 0 ) :
for ( V_38 = 0 ; V_38 < 64 ; V_38 ++ )
V_41 [ V_38 ] = F_22 ( V_14 , F_33 ( V_38 ) ) ;
break;
case F_34 ( 0 ) :
for ( V_38 = 0 ; V_38 < 64 ; V_38 ++ )
V_41 [ V_38 ] = F_22 ( V_14 , F_34 ( V_38 ) ) ;
break;
case F_35 ( 0 ) :
for ( V_38 = 0 ; V_38 < 64 ; V_38 ++ )
V_41 [ V_38 ] = F_22 ( V_14 , F_35 ( V_38 ) ) ;
break;
default:
F_36 ( L_13 , V_37 -> V_43 ,
F_22 ( V_14 , V_37 -> V_42 ) ) ;
return;
}
for ( V_38 = 0 ; V_38 < 8 ; V_38 ++ ) {
snprintf ( V_40 , 16 , L_14 , V_37 -> V_43 , V_38 * 8 , V_38 * 8 + 7 ) ;
F_37 ( L_15 , V_40 ) ;
for ( V_39 = 0 ; V_39 < 8 ; V_39 ++ )
F_38 ( L_16 , V_41 [ V_38 * 8 + V_39 ] ) ;
F_38 ( L_17 ) ;
}
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_36 * V_37 ;
int V_46 = 0 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
union V_51 * V_52 ;
struct V_53 { T_4 V_54 ; T_4 V_55 ; } * V_56 ;
struct V_47 * V_57 ;
union V_58 * V_59 ;
struct V_60 * V_61 ;
T_1 V_62 ;
int V_38 = 0 ;
if ( ! F_40 ( V_2 ) )
return;
if ( V_45 ) {
F_41 ( & V_2 -> V_9 -> V_63 , L_18 ) ;
F_36 ( L_19
L_20 ) ;
F_36 ( L_21 ,
V_45 -> V_43 ,
V_45 -> V_33 ,
V_45 -> V_64 ,
V_45 -> V_65 ) ;
}
F_41 ( & V_2 -> V_9 -> V_63 , L_22 ) ;
F_36 ( L_23 ) ;
for ( V_37 = (struct V_36 * ) V_66 ;
V_37 -> V_43 ; V_37 ++ ) {
F_20 ( V_14 , V_37 ) ;
}
if ( ! V_45 || ! F_42 ( V_45 ) )
goto exit;
F_41 ( & V_2 -> V_9 -> V_63 , L_24 ) ;
F_36 ( L_25 ,
L_26 ,
L_27 , L_28 , L_29 ) ;
for ( V_46 = 0 ; V_46 < V_2 -> V_67 ; V_46 ++ ) {
V_48 = V_2 -> V_48 [ V_46 ] ;
V_50 = & V_48 -> V_68 [ V_48 -> V_69 ] ;
F_36 ( L_30 ,
V_46 , V_48 -> V_70 , V_48 -> V_69 ,
( T_4 ) F_43 ( V_50 , V_71 ) ,
F_44 ( V_50 , V_72 ) ,
V_50 -> V_73 ,
( T_4 ) V_50 -> V_74 ) ;
}
if ( ! F_45 ( V_2 ) )
goto V_75;
F_41 ( & V_2 -> V_9 -> V_63 , L_31 ) ;
for ( V_46 = 0 ; V_46 < V_2 -> V_67 ; V_46 ++ ) {
V_48 = V_2 -> V_48 [ V_46 ] ;
F_36 ( L_32 ) ;
F_36 ( L_33 , V_48 -> V_76 ) ;
F_36 ( L_32 ) ;
F_36 ( L_34 ,
L_35 ,
L_36 ,
L_27 , L_28 , L_29 , L_37 ) ;
for ( V_38 = 0 ; V_48 -> V_77 && ( V_38 < V_48 -> V_78 ) ; V_38 ++ ) {
V_52 = F_46 ( V_48 , V_38 ) ;
V_50 = & V_48 -> V_68 [ V_38 ] ;
V_56 = (struct V_53 * ) V_52 ;
if ( F_44 ( V_50 , V_72 ) > 0 ) {
F_36 ( L_38 ,
V_38 ,
F_47 ( V_56 -> V_54 ) ,
F_47 ( V_56 -> V_55 ) ,
( T_4 ) F_43 ( V_50 , V_71 ) ,
F_44 ( V_50 , V_72 ) ,
V_50 -> V_73 ,
( T_4 ) V_50 -> V_74 ,
V_50 -> V_79 ) ;
if ( V_38 == V_48 -> V_70 &&
V_38 == V_48 -> V_69 )
F_38 ( L_39 ) ;
else if ( V_38 == V_48 -> V_70 )
F_38 ( L_40 ) ;
else if ( V_38 == V_48 -> V_69 )
F_38 ( L_41 ) ;
else
F_38 ( L_17 ) ;
if ( F_48 ( V_2 ) &&
V_50 -> V_79 )
F_49 ( V_80 , L_42 ,
V_81 , 16 , 1 ,
V_50 -> V_79 -> V_82 ,
F_44 ( V_50 , V_72 ) ,
true ) ;
}
}
}
V_75:
F_41 ( & V_2 -> V_9 -> V_63 , L_43 ) ;
F_36 ( L_44 ) ;
for ( V_46 = 0 ; V_46 < V_2 -> V_83 ; V_46 ++ ) {
V_57 = V_2 -> V_57 [ V_46 ] ;
F_36 ( L_45 ,
V_46 , V_57 -> V_70 , V_57 -> V_69 ) ;
}
if ( ! F_50 ( V_2 ) )
goto exit;
F_41 ( & V_2 -> V_9 -> V_63 , L_46 ) ;
for ( V_46 = 0 ; V_46 < V_2 -> V_83 ; V_46 ++ ) {
V_57 = V_2 -> V_57 [ V_46 ] ;
F_36 ( L_32 ) ;
F_36 ( L_47 , V_57 -> V_76 ) ;
F_36 ( L_32 ) ;
F_36 ( L_48 ,
L_49 ,
L_50 ,
L_51 ) ;
F_36 ( L_48 ,
L_52 ,
L_53 ,
L_54 ) ;
for ( V_38 = 0 ; V_38 < V_57 -> V_78 ; V_38 ++ ) {
V_61 = & V_57 -> V_61 [ V_38 ] ;
V_59 = F_51 ( V_57 , V_38 ) ;
V_56 = (struct V_53 * ) V_59 ;
V_62 = F_52 ( V_59 -> V_84 . V_85 . V_86 ) ;
if ( V_62 & V_87 ) {
F_36 ( L_55
L_56 , V_38 ,
F_47 ( V_56 -> V_54 ) ,
F_47 ( V_56 -> V_55 ) ,
V_61 -> V_79 ) ;
} else {
F_36 ( L_57
L_58 , V_38 ,
F_47 ( V_56 -> V_54 ) ,
F_47 ( V_56 -> V_55 ) ,
( T_4 ) V_61 -> V_71 ,
V_61 -> V_79 ) ;
if ( F_48 ( V_2 ) &&
V_61 -> V_71 ) {
F_49 ( V_80 , L_42 ,
V_81 , 16 , 1 ,
F_53 ( V_61 -> V_88 ) +
V_61 -> V_89 ,
F_54 ( V_57 ) , true ) ;
}
}
if ( V_38 == V_57 -> V_70 )
F_38 ( L_40 ) ;
else if ( V_38 == V_57 -> V_69 )
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
T_1 V_90 ;
V_90 = F_22 ( & V_2 -> V_14 , V_91 ) ;
F_56 ( & V_2 -> V_14 , V_91 ,
V_90 & ~ V_92 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
T_1 V_90 ;
V_90 = F_22 ( & V_2 -> V_14 , V_91 ) ;
F_56 ( & V_2 -> V_14 , V_91 ,
V_90 | V_92 ) ;
}
static void F_58 ( struct V_1 * V_2 , T_5 V_93 ,
T_6 V_94 , T_6 V_95 )
{
T_1 V_96 , V_97 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_98 . type ) {
case V_99 :
V_95 |= V_100 ;
if ( V_93 == - 1 )
V_93 = 0 ;
V_97 = ( ( ( V_93 * 64 ) + V_94 ) >> 2 ) & 0x1F ;
V_96 = F_22 ( V_14 , F_59 ( V_97 ) ) ;
V_96 &= ~ ( 0xFF << ( 8 * ( V_94 & 0x3 ) ) ) ;
V_96 |= ( V_95 << ( 8 * ( V_94 & 0x3 ) ) ) ;
F_56 ( V_14 , F_59 ( V_97 ) , V_96 ) ;
break;
case V_101 :
case V_102 :
if ( V_93 == - 1 ) {
V_95 |= V_100 ;
V_97 = ( ( V_94 & 1 ) * 8 ) ;
V_96 = F_22 ( & V_2 -> V_14 , V_103 ) ;
V_96 &= ~ ( 0xFF << V_97 ) ;
V_96 |= ( V_95 << V_97 ) ;
F_56 ( & V_2 -> V_14 , V_103 , V_96 ) ;
break;
} else {
V_95 |= V_100 ;
V_97 = ( ( 16 * ( V_94 & 1 ) ) + ( 8 * V_93 ) ) ;
V_96 = F_22 ( V_14 , F_59 ( V_94 >> 1 ) ) ;
V_96 &= ~ ( 0xFF << V_97 ) ;
V_96 |= ( V_95 << V_97 ) ;
F_56 ( V_14 , F_59 ( V_94 >> 1 ) , V_96 ) ;
break;
}
default:
break;
}
}
static inline void F_60 ( struct V_1 * V_2 ,
T_4 V_104 )
{
T_1 V_105 ;
switch ( V_2 -> V_14 . V_98 . type ) {
case V_99 :
V_105 = ( V_106 & V_104 ) ;
F_56 ( & V_2 -> V_14 , V_107 , V_105 ) ;
break;
case V_101 :
case V_102 :
V_105 = ( V_104 & 0xFFFFFFFF ) ;
F_56 ( & V_2 -> V_14 , F_61 ( 0 ) , V_105 ) ;
V_105 = ( V_104 >> 32 ) ;
F_56 ( & V_2 -> V_14 , F_61 ( 1 ) , V_105 ) ;
break;
default:
break;
}
}
void F_62 ( struct V_47 * V_108 ,
struct V_49 * V_50 )
{
if ( V_50 -> V_79 ) {
F_63 ( V_50 -> V_79 ) ;
if ( F_44 ( V_50 , V_72 ) )
F_64 ( V_108 -> V_63 ,
F_43 ( V_50 , V_71 ) ,
F_44 ( V_50 , V_72 ) ,
V_109 ) ;
} else if ( F_44 ( V_50 , V_72 ) ) {
F_65 ( V_108 -> V_63 ,
F_43 ( V_50 , V_71 ) ,
F_44 ( V_50 , V_72 ) ,
V_109 ) ;
}
V_50 -> V_73 = NULL ;
V_50 -> V_79 = NULL ;
F_66 ( V_50 , V_72 , 0 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_110 * V_111 = & V_2 -> V_112 ;
int V_38 ;
T_1 V_82 ;
if ( ( V_14 -> V_113 . V_114 != V_115 ) &&
( V_14 -> V_113 . V_114 != V_116 ) )
return;
switch ( V_14 -> V_98 . type ) {
case V_99 :
V_82 = F_22 ( V_14 , V_117 ) ;
break;
default:
V_82 = F_22 ( V_14 , V_118 ) ;
}
V_111 -> V_119 += V_82 ;
if ( ! V_82 )
return;
for ( V_38 = 0 ; V_38 < V_2 -> V_67 ; V_38 ++ )
F_19 ( V_120 ,
& V_2 -> V_48 [ V_38 ] -> V_33 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_110 * V_111 = & V_2 -> V_112 ;
T_1 V_121 [ 8 ] = { 0 } ;
T_6 V_122 ;
int V_38 ;
bool V_123 = V_2 -> V_124 . V_125 ;
if ( V_2 -> V_126 )
V_123 |= ! ! ( V_2 -> V_126 -> V_123 ) ;
if ( ! ( V_2 -> V_127 & V_128 ) || ! V_123 ) {
F_67 ( V_2 ) ;
return;
}
for ( V_38 = 0 ; V_38 < V_129 ; V_38 ++ ) {
T_1 V_130 ;
switch ( V_14 -> V_98 . type ) {
case V_99 :
V_130 = F_22 ( V_14 , F_69 ( V_38 ) ) ;
break;
default:
V_130 = F_22 ( V_14 , F_70 ( V_38 ) ) ;
}
V_111 -> V_130 [ V_38 ] += V_130 ;
V_122 = F_71 ( V_2 -> V_45 , V_38 ) ;
V_121 [ V_122 ] += V_130 ;
}
for ( V_38 = 0 ; V_38 < V_2 -> V_67 ; V_38 ++ ) {
struct V_47 * V_48 = V_2 -> V_48 [ V_38 ] ;
V_122 = V_48 -> V_131 ;
if ( V_121 [ V_122 ] )
F_19 ( V_120 , & V_48 -> V_33 ) ;
}
}
static T_4 F_72 ( struct V_47 * V_108 )
{
return V_108 -> V_112 . V_132 ;
}
static T_4 F_73 ( struct V_47 * V_108 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 ;
T_1 V_133 , V_134 ;
if ( V_108 -> V_135 )
V_2 = V_108 -> V_135 -> V_136 ;
else
V_2 = F_74 ( V_108 -> V_45 ) ;
V_14 = & V_2 -> V_14 ;
V_133 = F_22 ( V_14 , F_33 ( V_108 -> V_137 ) ) ;
V_134 = F_22 ( V_14 , F_34 ( V_108 -> V_137 ) ) ;
if ( V_133 != V_134 )
return ( V_133 < V_134 ) ?
V_134 - V_133 : ( V_134 + V_108 -> V_78 - V_133 ) ;
return 0 ;
}
static inline bool F_75 ( struct V_47 * V_48 )
{
T_1 V_138 = F_72 ( V_48 ) ;
T_1 V_139 = V_48 -> V_140 . V_139 ;
T_1 V_141 = F_73 ( V_48 ) ;
bool V_142 = false ;
F_76 ( V_48 ) ;
if ( ( V_139 == V_138 ) && V_141 ) {
V_142 = F_14 ( V_120 ,
& V_48 -> V_33 ) ;
} else {
V_48 -> V_140 . V_139 = V_138 ;
F_19 ( V_120 , & V_48 -> V_33 ) ;
}
return V_142 ;
}
static void F_77 ( struct V_1 * V_2 )
{
if ( ! F_13 ( V_32 , & V_2 -> V_33 ) ) {
V_2 -> V_143 |= V_144 ;
F_78 ( V_145 , L_59 ) ;
F_12 ( V_2 ) ;
}
}
static bool F_79 ( struct V_146 * V_147 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = V_147 -> V_2 ;
struct V_49 * V_50 ;
union V_51 * V_52 ;
unsigned int V_148 = 0 , V_149 = 0 ;
unsigned int V_150 = V_147 -> V_151 . V_152 ;
unsigned int V_38 = V_48 -> V_69 ;
if ( F_13 ( V_32 , & V_2 -> V_33 ) )
return true ;
V_50 = & V_48 -> V_68 [ V_38 ] ;
V_52 = F_46 ( V_48 , V_38 ) ;
V_38 -= V_48 -> V_78 ;
do {
union V_51 * V_153 = V_50 -> V_73 ;
if ( ! V_153 )
break;
F_80 () ;
if ( ! ( V_153 -> V_84 . V_154 & F_81 ( V_155 ) ) )
break;
V_50 -> V_73 = NULL ;
V_148 += V_50 -> V_156 ;
V_149 += V_50 -> V_157 ;
F_63 ( V_50 -> V_79 ) ;
F_64 ( V_48 -> V_63 ,
F_43 ( V_50 , V_71 ) ,
F_44 ( V_50 , V_72 ) ,
V_109 ) ;
V_50 -> V_79 = NULL ;
F_66 ( V_50 , V_72 , 0 ) ;
while ( V_52 != V_153 ) {
V_50 ++ ;
V_52 ++ ;
V_38 ++ ;
if ( F_82 ( ! V_38 ) ) {
V_38 -= V_48 -> V_78 ;
V_50 = V_48 -> V_68 ;
V_52 = F_46 ( V_48 , 0 ) ;
}
if ( F_44 ( V_50 , V_72 ) ) {
F_65 ( V_48 -> V_63 ,
F_43 ( V_50 , V_71 ) ,
F_44 ( V_50 , V_72 ) ,
V_109 ) ;
F_66 ( V_50 , V_72 , 0 ) ;
}
}
V_50 ++ ;
V_52 ++ ;
V_38 ++ ;
if ( F_82 ( ! V_38 ) ) {
V_38 -= V_48 -> V_78 ;
V_50 = V_48 -> V_68 ;
V_52 = F_46 ( V_48 , 0 ) ;
}
F_83 ( V_52 ) ;
V_150 -- ;
} while ( F_84 ( V_150 ) );
V_38 += V_48 -> V_78 ;
V_48 -> V_69 = V_38 ;
F_85 ( & V_48 -> V_158 ) ;
V_48 -> V_112 . V_159 += V_148 ;
V_48 -> V_112 . V_132 += V_149 ;
F_86 ( & V_48 -> V_158 ) ;
V_147 -> V_151 . V_148 += V_148 ;
V_147 -> V_151 . V_149 += V_149 ;
if ( F_87 ( V_48 ) && F_75 ( V_48 ) ) {
struct V_13 * V_14 = & V_2 -> V_14 ;
F_88 ( V_145 , L_60
L_61
L_62
L_63
L_64
L_65
L_66
L_67 ,
V_48 -> V_76 ,
F_22 ( V_14 , F_33 ( V_48 -> V_137 ) ) ,
F_22 ( V_14 , F_34 ( V_48 -> V_137 ) ) ,
V_48 -> V_70 , V_38 ,
V_48 -> V_68 [ V_38 ] . V_74 , V_160 ) ;
F_89 ( V_48 -> V_45 , V_48 -> V_76 ) ;
F_90 ( V_161 ,
L_68 ,
V_2 -> V_162 + 1 , V_48 -> V_76 ) ;
F_77 ( V_2 ) ;
return true ;
}
F_91 ( F_92 ( V_48 ) ,
V_149 , V_148 ) ;
#define F_93 (DESC_NEEDED * 2)
if ( F_82 ( V_149 && F_94 ( V_48 -> V_45 ) &&
( F_95 ( V_48 ) >= F_93 ) ) ) {
F_96 () ;
if ( F_97 ( V_48 -> V_45 ,
V_48 -> V_76 )
&& ! F_13 ( V_32 , & V_2 -> V_33 ) ) {
F_98 ( V_48 -> V_45 ,
V_48 -> V_76 ) ;
++ V_48 -> V_140 . V_163 ;
}
}
return ! ! V_150 ;
}
static void F_99 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
int V_164 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_165 = F_100 ( V_48 -> V_63 , V_164 ) ;
T_2 V_166 ;
switch ( V_14 -> V_98 . type ) {
case V_99 :
V_166 = F_101 ( V_48 -> V_137 ) ;
break;
case V_101 :
case V_102 :
V_166 = F_102 ( V_48 -> V_137 ) ;
V_165 <<= V_167 ;
break;
default:
return;
}
V_165 |= V_168 |
V_169 |
V_170 ;
F_56 ( V_14 , V_166 , V_165 ) ;
}
static void F_103 ( struct V_1 * V_2 ,
struct V_47 * V_57 ,
int V_164 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_171 = F_100 ( V_57 -> V_63 , V_164 ) ;
T_6 V_137 = V_57 -> V_137 ;
switch ( V_14 -> V_98 . type ) {
case V_101 :
case V_102 :
V_171 <<= V_172 ;
break;
default:
break;
}
V_171 |= V_173 |
V_174 ;
F_56 ( V_14 , F_23 ( V_137 ) , V_171 ) ;
}
static void F_104 ( struct V_146 * V_147 )
{
struct V_1 * V_2 = V_147 -> V_2 ;
struct V_47 * V_108 ;
int V_164 = F_105 () ;
if ( V_147 -> V_164 == V_164 )
goto V_175;
F_106 (ring, q_vector->tx)
F_99 ( V_2 , V_108 , V_164 ) ;
F_106 (ring, q_vector->rx)
F_103 ( V_2 , V_108 , V_164 ) ;
V_147 -> V_164 = V_164 ;
V_175:
F_107 () ;
}
static void F_108 ( struct V_1 * V_2 )
{
int V_38 ;
if ( ! ( V_2 -> V_127 & V_176 ) )
return;
F_56 ( & V_2 -> V_14 , V_177 , 2 ) ;
for ( V_38 = 0 ; V_38 < V_2 -> V_178 ; V_38 ++ ) {
V_2 -> V_147 [ V_38 ] -> V_164 = - 1 ;
F_104 ( V_2 -> V_147 [ V_38 ] ) ;
}
}
static int F_109 ( struct V_179 * V_63 , void * V_82 )
{
struct V_1 * V_2 = F_110 ( V_63 ) ;
unsigned long V_180 = * ( unsigned long * ) V_82 ;
if ( ! ( V_2 -> V_127 & V_181 ) )
return 0 ;
switch ( V_180 ) {
case V_182 :
if ( V_2 -> V_127 & V_176 )
break;
if ( F_111 ( V_63 ) == 0 ) {
V_2 -> V_127 |= V_176 ;
F_108 ( V_2 ) ;
break;
}
case V_183 :
if ( V_2 -> V_127 & V_176 ) {
F_112 ( V_63 ) ;
V_2 -> V_127 &= ~ V_176 ;
F_56 ( & V_2 -> V_14 , V_177 , 1 ) ;
}
break;
}
return 0 ;
}
static inline void F_113 ( struct V_47 * V_108 ,
union V_58 * V_59 ,
struct V_184 * V_79 )
{
if ( V_108 -> V_45 -> V_185 & V_186 )
V_79 -> V_187 = F_52 ( V_59 -> V_84 . V_188 . V_189 . V_190 ) ;
}
static inline bool F_114 ( struct V_47 * V_108 ,
union V_58 * V_59 )
{
T_7 V_191 = V_59 -> V_84 . V_188 . V_192 . V_193 . V_191 ;
return F_13 ( V_194 , & V_108 -> V_33 ) &&
( ( V_191 & F_115 ( V_195 ) ) ==
( F_115 ( V_196 <<
V_197 ) ) ) ;
}
static inline void F_116 ( struct V_47 * V_108 ,
union V_58 * V_59 ,
struct V_184 * V_79 )
{
F_117 ( V_79 ) ;
if ( ! ( V_108 -> V_45 -> V_185 & V_198 ) )
return;
if ( F_118 ( V_59 , V_199 ) &&
F_118 ( V_59 , V_200 ) ) {
V_108 -> V_201 . V_202 ++ ;
return;
}
if ( ! F_118 ( V_59 , V_203 ) )
return;
if ( F_118 ( V_59 , V_204 ) ) {
T_7 V_191 = V_59 -> V_84 . V_188 . V_192 . V_193 . V_191 ;
if ( ( V_191 & F_115 ( V_205 ) ) &&
F_13 ( V_206 , & V_108 -> V_33 ) )
return;
V_108 -> V_201 . V_202 ++ ;
return;
}
V_79 -> V_207 = V_208 ;
}
static inline void F_119 ( struct V_47 * V_57 , T_1 V_209 )
{
V_57 -> V_70 = V_209 ;
V_57 -> V_210 = V_209 ;
F_120 () ;
F_121 ( V_209 , V_57 -> V_134 ) ;
}
static bool F_122 ( struct V_47 * V_57 ,
struct V_60 * V_211 )
{
struct V_88 * V_88 = V_211 -> V_88 ;
T_8 V_71 = V_211 -> V_71 ;
if ( F_84 ( V_71 ) )
return true ;
if ( F_84 ( ! V_88 ) ) {
V_88 = F_123 ( V_212 | V_213 | V_214 ,
V_211 -> V_79 , F_124 ( V_57 ) ) ;
if ( F_82 ( ! V_88 ) ) {
V_57 -> V_201 . V_215 ++ ;
return false ;
}
V_211 -> V_88 = V_88 ;
}
V_71 = F_125 ( V_57 -> V_63 , V_88 , 0 ,
F_126 ( V_57 ) , V_216 ) ;
if ( F_127 ( V_57 -> V_63 , V_71 ) ) {
F_128 ( V_88 , F_124 ( V_57 ) ) ;
V_211 -> V_88 = NULL ;
V_57 -> V_201 . V_215 ++ ;
return false ;
}
V_211 -> V_71 = V_71 ;
V_211 -> V_89 = 0 ;
return true ;
}
void F_129 ( struct V_47 * V_57 , T_2 V_217 )
{
union V_58 * V_59 ;
struct V_60 * V_211 ;
T_2 V_38 = V_57 -> V_70 ;
if ( ! V_217 )
return;
V_59 = F_51 ( V_57 , V_38 ) ;
V_211 = & V_57 -> V_61 [ V_38 ] ;
V_38 -= V_57 -> V_78 ;
do {
if ( ! F_122 ( V_57 , V_211 ) )
break;
V_59 -> V_218 . V_219 = F_130 ( V_211 -> V_71 + V_211 -> V_89 ) ;
V_59 ++ ;
V_211 ++ ;
V_38 ++ ;
if ( F_82 ( ! V_38 ) ) {
V_59 = F_51 ( V_57 , 0 ) ;
V_211 = V_57 -> V_61 ;
V_38 -= V_57 -> V_78 ;
}
V_59 -> V_218 . V_220 = 0 ;
V_217 -- ;
} while ( V_217 );
V_38 += V_57 -> V_78 ;
if ( V_57 -> V_70 != V_38 )
F_119 ( V_57 , V_38 ) ;
}
static unsigned int F_131 ( unsigned char * V_82 ,
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
V_231 . V_222 = V_82 ;
V_232 = V_231 . V_224 -> V_236 ;
V_231 . V_222 += V_235 ;
if ( V_232 == F_132 ( V_237 ) ) {
if ( ( V_231 . V_222 - V_82 ) > ( V_221 - V_238 ) )
return V_221 ;
V_232 = V_231 . V_226 -> V_239 ;
V_231 . V_222 += V_238 ;
}
if ( V_232 == F_132 ( V_240 ) ) {
if ( ( V_231 . V_222 - V_82 ) > ( V_221 - sizeof( struct V_227 ) ) )
return V_221 ;
V_234 = ( V_231 . V_222 [ 0 ] & 0x0F ) << 2 ;
if ( V_234 < sizeof( struct V_227 ) )
return V_231 . V_222 - V_82 ;
if ( ! ( V_231 . V_228 -> V_241 & F_133 ( V_242 ) ) )
V_233 = V_231 . V_228 -> V_232 ;
} else if ( V_232 == F_132 ( V_243 ) ) {
if ( ( V_231 . V_222 - V_82 ) > ( V_221 - sizeof( struct V_229 ) ) )
return V_221 ;
V_233 = V_231 . V_230 -> V_233 ;
V_234 = sizeof( struct V_229 ) ;
#ifdef F_134
} else if ( V_232 == F_132 ( V_244 ) ) {
if ( ( V_231 . V_222 - V_82 ) > ( V_221 - V_245 ) )
return V_221 ;
V_234 = V_245 ;
#endif
} else {
return V_231 . V_222 - V_82 ;
}
V_231 . V_222 += V_234 ;
if ( V_233 == V_246 ) {
if ( ( V_231 . V_222 - V_82 ) > ( V_221 - sizeof( struct V_247 ) ) )
return V_221 ;
V_234 = ( V_231 . V_222 [ 12 ] & 0xF0 ) >> 2 ;
if ( V_234 < sizeof( struct V_247 ) )
return V_231 . V_222 - V_82 ;
V_231 . V_222 += V_234 ;
} else if ( V_233 == V_248 ) {
if ( ( V_231 . V_222 - V_82 ) > ( V_221 - sizeof( struct V_249 ) ) )
return V_221 ;
V_231 . V_222 += sizeof( struct V_249 ) ;
}
if ( ( V_231 . V_222 - V_82 ) < V_221 )
return V_231 . V_222 - V_82 ;
else
return V_221 ;
}
static void F_135 ( struct V_47 * V_108 ,
struct V_184 * V_79 )
{
T_2 V_250 = F_136 ( V_79 ) ;
F_137 ( V_79 ) -> V_251 = F_138 ( ( V_79 -> V_72 - V_250 ) ,
F_139 ( V_79 ) -> V_252 ) ;
F_137 ( V_79 ) -> V_253 = V_254 ;
}
static void F_140 ( struct V_47 * V_57 ,
struct V_184 * V_79 )
{
if ( ! F_139 ( V_79 ) -> V_252 )
return;
V_57 -> V_201 . V_255 += F_139 ( V_79 ) -> V_252 ;
V_57 -> V_201 . V_256 ++ ;
F_135 ( V_57 , V_79 ) ;
F_139 ( V_79 ) -> V_252 = 0 ;
}
static void F_141 ( struct V_47 * V_57 ,
union V_58 * V_59 ,
struct V_184 * V_79 )
{
struct V_44 * V_63 = V_57 -> V_45 ;
F_140 ( V_57 , V_79 ) ;
F_113 ( V_57 , V_59 , V_79 ) ;
F_116 ( V_57 , V_59 , V_79 ) ;
F_142 ( V_57 , V_59 , V_79 ) ;
if ( ( V_63 -> V_185 & V_257 ) &&
F_118 ( V_59 , V_258 ) ) {
T_2 V_259 = F_143 ( V_59 -> V_84 . V_85 . V_226 ) ;
F_144 ( V_79 , F_133 ( V_237 ) , V_259 ) ;
}
F_145 ( V_79 , V_57 -> V_76 ) ;
V_79 -> V_232 = F_146 ( V_79 , V_63 ) ;
}
static void F_147 ( struct V_146 * V_147 ,
struct V_184 * V_79 )
{
struct V_1 * V_2 = V_147 -> V_2 ;
if ( F_148 ( V_147 ) )
F_149 ( V_79 ) ;
else if ( ! ( V_2 -> V_127 & V_260 ) )
F_150 ( & V_147 -> V_261 , V_79 ) ;
else
F_151 ( V_79 ) ;
}
static bool F_152 ( struct V_47 * V_57 ,
union V_58 * V_59 ,
struct V_184 * V_79 )
{
T_1 V_262 = V_57 -> V_69 + 1 ;
V_262 = ( V_262 < V_57 -> V_78 ) ? V_262 : 0 ;
V_57 -> V_69 = V_262 ;
F_83 ( F_51 ( V_57 , V_262 ) ) ;
if ( F_153 ( V_57 ) ) {
T_10 V_263 = V_59 -> V_84 . V_188 . V_192 . V_82 &
F_81 ( V_264 ) ;
if ( F_82 ( V_263 ) ) {
T_1 V_265 = F_52 ( V_263 ) ;
V_265 >>= V_266 ;
F_139 ( V_79 ) -> V_252 += V_265 - 1 ;
V_262 = F_52 ( V_59 -> V_84 . V_85 . V_86 ) ;
V_262 &= V_267 ;
V_262 >>= V_268 ;
}
}
if ( F_84 ( F_118 ( V_59 , V_269 ) ) )
return false ;
V_57 -> V_61 [ V_262 ] . V_79 = V_79 ;
V_57 -> V_201 . V_270 ++ ;
return true ;
}
static void F_154 ( struct V_47 * V_57 ,
struct V_184 * V_79 )
{
struct V_271 * V_272 = & F_137 ( V_79 ) -> V_273 [ 0 ] ;
unsigned char * V_274 ;
unsigned int V_275 ;
V_274 = F_155 ( V_272 ) ;
V_275 = F_131 ( V_274 , V_276 ) ;
F_156 ( V_79 , V_274 , F_157 ( V_275 , sizeof( long ) ) ) ;
F_158 ( V_272 , V_275 ) ;
V_272 -> V_89 += V_275 ;
V_79 -> V_277 -= V_275 ;
V_79 -> V_134 += V_275 ;
}
static void F_159 ( struct V_47 * V_57 ,
struct V_184 * V_79 )
{
if ( F_82 ( F_139 ( V_79 ) -> V_278 ) ) {
F_65 ( V_57 -> V_63 , F_139 ( V_79 ) -> V_71 ,
F_126 ( V_57 ) , V_216 ) ;
F_139 ( V_79 ) -> V_278 = false ;
} else {
struct V_271 * V_272 = & F_137 ( V_79 ) -> V_273 [ 0 ] ;
F_160 ( V_57 -> V_63 ,
F_139 ( V_79 ) -> V_71 ,
V_272 -> V_89 ,
F_54 ( V_57 ) ,
V_216 ) ;
}
F_139 ( V_79 ) -> V_71 = 0 ;
}
static bool F_161 ( struct V_47 * V_57 ,
union V_58 * V_59 ,
struct V_184 * V_79 )
{
struct V_44 * V_45 = V_57 -> V_45 ;
if ( F_82 ( F_118 ( V_59 ,
V_279 ) &&
! ( V_45 -> V_185 & V_280 ) ) ) {
F_63 ( V_79 ) ;
return true ;
}
if ( F_162 ( V_79 ) )
F_154 ( V_57 , V_79 ) ;
#ifdef F_134
if ( F_114 ( V_57 , V_59 ) )
return false ;
#endif
if ( F_82 ( V_79 -> V_72 < 60 ) ) {
int V_281 = 60 - V_79 -> V_72 ;
if ( F_163 ( V_79 , V_281 ) )
return true ;
F_164 ( V_79 , V_281 ) ;
}
return false ;
}
static void F_165 ( struct V_47 * V_57 ,
struct V_60 * V_282 )
{
struct V_60 * V_283 ;
T_2 V_284 = V_57 -> V_210 ;
V_283 = & V_57 -> V_61 [ V_284 ] ;
V_284 ++ ;
V_57 -> V_210 = ( V_284 < V_57 -> V_78 ) ? V_284 : 0 ;
V_283 -> V_88 = V_282 -> V_88 ;
V_283 -> V_71 = V_282 -> V_71 ;
V_283 -> V_89 = V_282 -> V_89 ;
F_166 ( V_57 -> V_63 , V_283 -> V_71 ,
V_283 -> V_89 ,
F_54 ( V_57 ) ,
V_216 ) ;
}
static bool F_167 ( struct V_47 * V_57 ,
struct V_60 * V_285 ,
union V_58 * V_59 ,
struct V_184 * V_79 )
{
struct V_88 * V_88 = V_285 -> V_88 ;
unsigned int V_286 = F_143 ( V_59 -> V_84 . V_85 . V_287 ) ;
#if ( V_288 < 8192 )
unsigned int V_289 = F_54 ( V_57 ) ;
#else
unsigned int V_289 = F_157 ( V_286 , V_290 ) ;
unsigned int V_291 = F_126 ( V_57 ) -
F_54 ( V_57 ) ;
#endif
if ( ( V_286 <= V_276 ) && ! F_162 ( V_79 ) ) {
unsigned char * V_274 = F_53 ( V_88 ) + V_285 -> V_89 ;
memcpy ( F_164 ( V_79 , V_286 ) , V_274 , F_157 ( V_286 , sizeof( long ) ) ) ;
if ( F_84 ( F_168 ( V_88 ) == F_169 () ) )
return true ;
F_170 ( V_88 ) ;
return false ;
}
F_171 ( V_79 , F_137 ( V_79 ) -> V_292 , V_88 ,
V_285 -> V_89 , V_286 , V_289 ) ;
if ( F_82 ( F_168 ( V_88 ) != F_169 () ) )
return false ;
#if ( V_288 < 8192 )
if ( F_82 ( F_172 ( V_88 ) != 1 ) )
return false ;
V_285 -> V_89 ^= V_289 ;
F_173 ( & V_88 -> V_293 , 2 ) ;
#else
V_285 -> V_89 += V_289 ;
if ( V_285 -> V_89 > V_291 )
return false ;
F_174 ( V_88 ) ;
#endif
return true ;
}
static struct V_184 * F_175 ( struct V_47 * V_57 ,
union V_58 * V_59 )
{
struct V_60 * V_285 ;
struct V_184 * V_79 ;
struct V_88 * V_88 ;
V_285 = & V_57 -> V_61 [ V_57 -> V_69 ] ;
V_88 = V_285 -> V_88 ;
F_176 ( V_88 ) ;
V_79 = V_285 -> V_79 ;
if ( F_84 ( ! V_79 ) ) {
void * V_294 = F_53 ( V_88 ) +
V_285 -> V_89 ;
F_83 ( V_294 ) ;
#if V_290 < 128
F_83 ( V_294 + V_290 ) ;
#endif
V_79 = F_177 ( V_57 -> V_45 ,
V_276 ) ;
if ( F_82 ( ! V_79 ) ) {
V_57 -> V_201 . V_295 ++ ;
return NULL ;
}
F_176 ( V_79 -> V_82 ) ;
if ( F_84 ( F_118 ( V_59 , V_269 ) ) )
goto V_296;
F_139 ( V_79 ) -> V_71 = V_285 -> V_71 ;
} else {
if ( F_118 ( V_59 , V_269 ) )
F_159 ( V_57 , V_79 ) ;
V_296:
F_160 ( V_57 -> V_63 ,
V_285 -> V_71 ,
V_285 -> V_89 ,
F_54 ( V_57 ) ,
V_216 ) ;
}
if ( F_167 ( V_57 , V_285 , V_59 , V_79 ) ) {
F_165 ( V_57 , V_285 ) ;
} else if ( F_139 ( V_79 ) -> V_71 == V_285 -> V_71 ) {
F_139 ( V_79 ) -> V_278 = true ;
} else {
F_65 ( V_57 -> V_63 , V_285 -> V_71 ,
F_126 ( V_57 ) ,
V_216 ) ;
}
V_285 -> V_79 = NULL ;
V_285 -> V_71 = 0 ;
V_285 -> V_88 = NULL ;
return V_79 ;
}
static int F_178 ( struct V_146 * V_147 ,
struct V_47 * V_57 ,
const int V_150 )
{
unsigned int V_297 = 0 , V_298 = 0 ;
#ifdef F_134
struct V_1 * V_2 = V_147 -> V_2 ;
int V_299 ;
unsigned int V_300 = 0 ;
#endif
T_2 V_217 = F_95 ( V_57 ) ;
do {
union V_58 * V_59 ;
struct V_184 * V_79 ;
if ( V_217 >= V_301 ) {
F_129 ( V_57 , V_217 ) ;
V_217 = 0 ;
}
V_59 = F_51 ( V_57 , V_57 -> V_69 ) ;
if ( ! F_118 ( V_59 , V_87 ) )
break;
F_179 () ;
V_79 = F_175 ( V_57 , V_59 ) ;
if ( ! V_79 )
break;
V_217 ++ ;
if ( F_152 ( V_57 , V_59 , V_79 ) )
continue;
if ( F_161 ( V_57 , V_59 , V_79 ) )
continue;
V_297 += V_79 -> V_72 ;
F_141 ( V_57 , V_59 , V_79 ) ;
#ifdef F_134
if ( F_114 ( V_57 , V_59 ) ) {
V_299 = F_180 ( V_2 , V_59 , V_79 ) ;
if ( V_299 > 0 ) {
if ( ! V_300 ) {
V_300 = V_57 -> V_45 -> V_302 -
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
F_63 ( V_79 ) ;
continue;
}
}
#endif
F_181 ( V_79 , & V_147 -> V_261 ) ;
F_147 ( V_147 , V_79 ) ;
V_298 ++ ;
} while ( F_84 ( V_298 < V_150 ) );
F_85 ( & V_57 -> V_158 ) ;
V_57 -> V_112 . V_132 += V_298 ;
V_57 -> V_112 . V_159 += V_297 ;
F_86 ( & V_57 -> V_158 ) ;
V_147 -> V_306 . V_149 += V_298 ;
V_147 -> V_306 . V_148 += V_297 ;
if ( V_217 )
F_129 ( V_57 , V_217 ) ;
return V_298 ;
}
static int F_182 ( struct V_307 * V_261 )
{
struct V_146 * V_147 =
F_183 ( V_261 , struct V_146 , V_261 ) ;
struct V_1 * V_2 = V_147 -> V_2 ;
struct V_47 * V_108 ;
int V_308 = 0 ;
if ( F_13 ( V_32 , & V_2 -> V_33 ) )
return V_309 ;
if ( ! F_184 ( V_147 ) )
return V_310 ;
F_106 (ring, q_vector->rx) {
V_308 = F_178 ( V_147 , V_108 , 4 ) ;
#ifdef F_185
if ( V_308 )
V_108 -> V_112 . V_311 += V_308 ;
else
V_108 -> V_112 . V_312 ++ ;
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
T_1 V_105 ;
if ( V_2 -> V_314 > 32 ) {
T_1 V_315 = ( 1 << ( V_2 -> V_314 - 32 ) ) - 1 ;
F_56 ( & V_2 -> V_14 , V_316 , V_315 ) ;
}
for ( V_313 = 0 ; V_313 < V_2 -> V_178 ; V_313 ++ ) {
struct V_47 * V_108 ;
V_147 = V_2 -> V_147 [ V_313 ] ;
F_106 (ring, q_vector->rx)
F_58 ( V_2 , 0 , V_108 -> V_137 , V_313 ) ;
F_106 (ring, q_vector->tx)
F_58 ( V_2 , 1 , V_108 -> V_137 , V_313 ) ;
F_188 ( V_147 ) ;
}
switch ( V_2 -> V_14 . V_98 . type ) {
case V_99 :
F_58 ( V_2 , - 1 , V_317 ,
V_313 ) ;
break;
case V_101 :
case V_102 :
F_58 ( V_2 , - 1 , 1 , V_313 ) ;
break;
default:
break;
}
F_56 ( & V_2 -> V_14 , F_189 ( V_313 ) , 1950 ) ;
V_105 = V_318 ;
V_105 &= ~ ( V_319 |
V_320 |
V_321 ) ;
F_56 ( & V_2 -> V_14 , V_322 , V_105 ) ;
}
static void F_190 ( struct V_146 * V_147 ,
struct V_323 * V_324 )
{
int V_159 = V_324 -> V_148 ;
int V_132 = V_324 -> V_149 ;
T_1 V_325 ;
T_4 V_326 ;
T_6 V_327 = V_324 -> V_328 ;
if ( V_132 == 0 )
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
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_313 = V_147 -> V_313 ;
T_1 V_332 = V_147 -> V_328 & V_333 ;
switch ( V_2 -> V_14 . V_98 . type ) {
case V_99 :
V_332 |= ( V_332 << 16 ) ;
break;
case V_101 :
case V_102 :
V_332 |= V_334 ;
break;
default:
break;
}
F_56 ( V_14 , F_189 ( V_313 ) , V_332 ) ;
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
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_340 = V_2 -> V_341 ;
if ( F_13 ( V_32 , & V_2 -> V_33 ) )
return;
if ( ! ( V_2 -> V_143 & V_342 ) &&
! ( V_2 -> V_143 & V_343 ) )
return;
V_2 -> V_143 &= ~ V_343 ;
switch ( V_14 -> V_20 ) {
case V_344 :
if ( ! ( V_340 & V_345 ) &&
! ( V_340 & V_346 ) )
return;
if ( ! ( V_340 & V_346 ) && V_14 -> V_98 . V_347 . V_348 ) {
T_1 V_19 ;
bool V_349 = false ;
V_14 -> V_98 . V_347 . V_348 ( V_14 , & V_19 , & V_349 , false ) ;
if ( V_349 )
return;
}
if ( V_14 -> V_350 . V_347 . V_351 ( V_14 ) != V_352 )
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
struct V_13 * V_14 = & V_2 -> V_14 ;
if ( ( V_2 -> V_127 & V_353 ) &&
( V_340 & V_354 ) ) {
F_194 ( V_161 , L_72 ) ;
F_56 ( V_14 , V_355 , V_354 ) ;
}
}
static void F_196 ( struct V_1 * V_2 , T_1 V_340 )
{
if ( ! ( V_2 -> V_143 & V_342 ) )
return;
switch ( V_2 -> V_14 . V_98 . type ) {
case V_101 :
if ( ( ( V_340 & V_345 ) || ( V_340 & V_346 ) ) &&
( ! F_13 ( V_32 , & V_2 -> V_33 ) ) ) {
V_2 -> V_341 = V_340 ;
V_2 -> V_143 |= V_343 ;
F_12 ( V_2 ) ;
return;
}
return;
case V_102 :
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
struct V_13 * V_14 = & V_2 -> V_14 ;
if ( V_340 & V_357 ) {
F_56 ( V_14 , V_355 , V_357 ) ;
if ( ! F_13 ( V_32 , & V_2 -> V_33 ) ) {
V_2 -> V_143 |= V_358 ;
F_12 ( V_2 ) ;
}
}
if ( V_340 & V_354 ) {
F_56 ( V_14 , V_355 , V_354 ) ;
if ( ! F_13 ( V_32 , & V_2 -> V_33 ) ) {
V_2 -> V_127 |= V_359 ;
F_12 ( V_2 ) ;
}
}
}
static void F_198 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
V_2 -> V_360 ++ ;
V_2 -> V_127 |= V_361 ;
V_2 -> V_362 = V_160 ;
if ( ! F_13 ( V_32 , & V_2 -> V_33 ) ) {
F_56 ( V_14 , V_363 , V_364 ) ;
F_199 ( V_14 ) ;
F_12 ( V_2 ) ;
}
}
static inline void F_200 ( struct V_1 * V_2 ,
T_4 V_104 )
{
T_1 V_105 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_98 . type ) {
case V_99 :
V_105 = ( V_106 & V_104 ) ;
F_56 ( V_14 , V_365 , V_105 ) ;
break;
case V_101 :
case V_102 :
V_105 = ( V_104 & 0xFFFFFFFF ) ;
if ( V_105 )
F_56 ( V_14 , F_201 ( 0 ) , V_105 ) ;
V_105 = ( V_104 >> 32 ) ;
if ( V_105 )
F_56 ( V_14 , F_201 ( 1 ) , V_105 ) ;
break;
default:
break;
}
}
static inline void F_202 ( struct V_1 * V_2 ,
T_4 V_104 )
{
T_1 V_105 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_98 . type ) {
case V_99 :
V_105 = ( V_106 & V_104 ) ;
F_56 ( V_14 , V_363 , V_105 ) ;
break;
case V_101 :
case V_102 :
V_105 = ( V_104 & 0xFFFFFFFF ) ;
if ( V_105 )
F_56 ( V_14 , F_203 ( 0 ) , V_105 ) ;
V_105 = ( V_104 >> 32 ) ;
if ( V_105 )
F_56 ( V_14 , F_203 ( 1 ) , V_105 ) ;
break;
default:
break;
}
}
static inline void F_204 ( struct V_1 * V_2 , bool V_366 ,
bool V_367 )
{
T_1 V_105 = ( V_318 & ~ V_106 ) ;
if ( V_2 -> V_127 & V_361 )
V_105 &= ~ V_321 ;
if ( V_2 -> V_143 & V_342 )
switch ( V_2 -> V_14 . V_98 . type ) {
case V_101 :
V_105 |= V_368 ;
break;
case V_102 :
V_105 |= V_369 ;
break;
default:
break;
}
if ( V_2 -> V_127 & V_353 )
V_105 |= V_370 ;
switch ( V_2 -> V_14 . V_98 . type ) {
case V_101 :
V_105 |= V_370 ;
V_105 |= V_371 ;
case V_102 :
V_105 |= V_372 ;
V_105 |= V_320 ;
break;
default:
break;
}
if ( V_2 -> V_14 . V_98 . type == V_102 )
V_105 |= V_373 ;
if ( ( V_2 -> V_127 & V_374 ) &&
! ( V_2 -> V_143 & V_375 ) )
V_105 |= V_376 ;
F_56 ( & V_2 -> V_14 , V_365 , V_105 ) ;
if ( V_366 )
F_200 ( V_2 , ~ 0 ) ;
if ( V_367 )
F_199 ( & V_2 -> V_14 ) ;
}
static T_11 F_205 ( int V_377 , void * V_82 )
{
struct V_1 * V_2 = V_82 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_340 ;
V_340 = F_22 ( V_14 , V_107 ) ;
V_340 &= 0xFFFF0000 ;
F_56 ( V_14 , V_355 , V_340 ) ;
if ( V_340 & V_346 )
F_198 ( V_2 ) ;
if ( V_340 & V_378 )
F_206 ( V_2 ) ;
switch ( V_14 -> V_98 . type ) {
case V_101 :
case V_102 :
if ( V_340 & V_379 )
F_90 ( V_380 , L_73
L_74 ) ;
if ( V_340 & V_381 ) {
int V_382 = 0 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_67 ; V_38 ++ ) {
struct V_47 * V_108 = V_2 -> V_48 [ V_38 ] ;
if ( F_207 ( V_383 ,
& V_108 -> V_33 ) )
V_382 ++ ;
}
if ( V_382 ) {
F_56 ( V_14 , V_363 , V_384 ) ;
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
if ( ! F_13 ( V_32 , & V_2 -> V_33 ) )
F_204 ( V_2 , false , false ) ;
return V_386 ;
}
static T_11 F_209 ( int V_377 , void * V_82 )
{
struct V_146 * V_147 = V_82 ;
if ( V_147 -> V_306 . V_108 || V_147 -> V_151 . V_108 )
F_210 ( & V_147 -> V_261 ) ;
return V_386 ;
}
int F_211 ( struct V_307 * V_261 , int V_150 )
{
struct V_146 * V_147 =
F_183 ( V_261 , struct V_146 , V_261 ) ;
struct V_1 * V_2 = V_147 -> V_2 ;
struct V_47 * V_108 ;
int V_387 ;
bool V_388 = true ;
#ifdef F_212
if ( V_2 -> V_127 & V_176 )
F_104 ( V_147 ) ;
#endif
F_106 (ring, q_vector->tx)
V_388 &= ! ! F_79 ( V_147 , V_108 ) ;
if ( ! F_213 ( V_147 ) )
return V_150 ;
if ( V_147 -> V_306 . V_78 > 1 )
V_387 = F_192 ( V_150 / V_147 -> V_306 . V_78 , 1 ) ;
else
V_387 = V_150 ;
F_106 (ring, q_vector->rx)
V_388 &= ( F_178 ( V_147 , V_108 ,
V_387 ) < V_387 ) ;
F_214 ( V_147 ) ;
if ( ! V_388 )
return V_150 ;
F_215 ( V_261 ) ;
if ( V_2 -> V_389 & 1 )
F_191 ( V_147 ) ;
if ( ! F_13 ( V_32 , & V_2 -> V_33 ) )
F_200 ( V_2 , ( ( T_4 ) 1 << V_147 -> V_313 ) ) ;
return 0 ;
}
static int F_216 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
int V_390 , V_16 ;
int V_391 = 0 , V_392 = 0 ;
for ( V_390 = 0 ; V_390 < V_2 -> V_178 ; V_390 ++ ) {
struct V_146 * V_147 = V_2 -> V_147 [ V_390 ] ;
struct V_393 * V_394 = & V_2 -> V_395 [ V_390 ] ;
if ( V_147 -> V_151 . V_108 && V_147 -> V_306 . V_108 ) {
snprintf ( V_147 -> V_43 , sizeof( V_147 -> V_43 ) - 1 ,
L_75 , V_45 -> V_43 , L_76 , V_391 ++ ) ;
V_392 ++ ;
} else if ( V_147 -> V_306 . V_108 ) {
snprintf ( V_147 -> V_43 , sizeof( V_147 -> V_43 ) - 1 ,
L_75 , V_45 -> V_43 , L_77 , V_391 ++ ) ;
} else if ( V_147 -> V_151 . V_108 ) {
snprintf ( V_147 -> V_43 , sizeof( V_147 -> V_43 ) - 1 ,
L_75 , V_45 -> V_43 , L_78 , V_392 ++ ) ;
} else {
continue;
}
V_16 = F_217 ( V_394 -> V_390 , & F_209 , 0 ,
V_147 -> V_43 , V_147 ) ;
if ( V_16 ) {
F_88 ( V_161 , L_79
L_80 , V_16 ) ;
goto V_396;
}
if ( V_2 -> V_127 & V_374 ) {
F_218 ( V_394 -> V_390 ,
& V_147 -> V_397 ) ;
}
}
V_16 = F_217 ( V_2 -> V_395 [ V_390 ] . V_390 ,
F_205 , 0 , V_45 -> V_43 , V_2 ) ;
if ( V_16 ) {
F_88 ( V_161 , L_81 , V_16 ) ;
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
V_2 -> V_127 &= ~ V_398 ;
F_220 ( V_2 -> V_9 ) ;
F_221 ( V_2 -> V_395 ) ;
V_2 -> V_395 = NULL ;
return V_16 ;
}
static T_11 F_222 ( int V_377 , void * V_82 )
{
struct V_1 * V_2 = V_82 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_146 * V_147 = V_2 -> V_147 [ 0 ] ;
T_1 V_340 ;
F_56 ( V_14 , V_363 , V_399 ) ;
V_340 = F_22 ( V_14 , V_355 ) ;
if ( ! V_340 ) {
if ( ! F_13 ( V_32 , & V_2 -> V_33 ) )
F_204 ( V_2 , true , true ) ;
return V_400 ;
}
if ( V_340 & V_346 )
F_198 ( V_2 ) ;
switch ( V_14 -> V_98 . type ) {
case V_101 :
F_197 ( V_2 , V_340 ) ;
case V_102 :
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
if ( ! F_13 ( V_32 , & V_2 -> V_33 ) )
F_204 ( V_2 , false , false ) ;
return V_386 ;
}
static int F_223 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
int V_16 ;
if ( V_2 -> V_127 & V_398 )
V_16 = F_216 ( V_2 ) ;
else if ( V_2 -> V_127 & V_401 )
V_16 = F_217 ( V_2 -> V_9 -> V_377 , F_222 , 0 ,
V_45 -> V_43 , V_2 ) ;
else
V_16 = F_217 ( V_2 -> V_9 -> V_377 , F_222 , V_402 ,
V_45 -> V_43 , V_2 ) ;
if ( V_16 )
F_88 ( V_161 , L_83 , V_16 ) ;
return V_16 ;
}
static void F_224 ( struct V_1 * V_2 )
{
int V_390 ;
if ( ! ( V_2 -> V_127 & V_398 ) ) {
F_219 ( V_2 -> V_9 -> V_377 , V_2 ) ;
return;
}
for ( V_390 = 0 ; V_390 < V_2 -> V_178 ; V_390 ++ ) {
struct V_146 * V_147 = V_2 -> V_147 [ V_390 ] ;
struct V_393 * V_394 = & V_2 -> V_395 [ V_390 ] ;
if ( ! V_147 -> V_306 . V_108 && ! V_147 -> V_151 . V_108 )
continue;
F_218 ( V_394 -> V_390 , NULL ) ;
F_219 ( V_394 -> V_390 , V_147 ) ;
}
F_219 ( V_2 -> V_395 [ V_390 ++ ] . V_390 , V_2 ) ;
}
static inline void F_225 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_98 . type ) {
case V_99 :
F_56 ( & V_2 -> V_14 , V_363 , ~ 0 ) ;
break;
case V_101 :
case V_102 :
F_56 ( & V_2 -> V_14 , V_363 , 0xFFFF0000 ) ;
F_56 ( & V_2 -> V_14 , F_203 ( 0 ) , ~ 0 ) ;
F_56 ( & V_2 -> V_14 , F_203 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_199 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_127 & V_398 ) {
int V_390 ;
for ( V_390 = 0 ; V_390 < V_2 -> V_178 ; V_390 ++ )
F_226 ( V_2 -> V_395 [ V_390 ] . V_390 ) ;
F_226 ( V_2 -> V_395 [ V_390 ++ ] . V_390 ) ;
} else {
F_226 ( V_2 -> V_9 -> V_377 ) ;
}
}
static void F_227 ( struct V_1 * V_2 )
{
struct V_146 * V_147 = V_2 -> V_147 [ 0 ] ;
F_188 ( V_147 ) ;
F_58 ( V_2 , 0 , 0 , 0 ) ;
F_58 ( V_2 , 1 , 0 , 0 ) ;
F_90 ( V_14 , L_84 ) ;
}
void F_228 ( struct V_1 * V_2 ,
struct V_47 * V_108 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_4 V_403 = V_108 -> V_71 ;
int V_404 = 10 ;
T_1 V_405 = V_406 ;
T_6 V_137 = V_108 -> V_137 ;
F_56 ( V_14 , F_35 ( V_137 ) , 0 ) ;
F_199 ( V_14 ) ;
F_56 ( V_14 , F_30 ( V_137 ) ,
( V_403 & F_229 ( 32 ) ) ) ;
F_56 ( V_14 , F_31 ( V_137 ) , ( V_403 >> 32 ) ) ;
F_56 ( V_14 , F_32 ( V_137 ) ,
V_108 -> V_78 * sizeof( union V_51 ) ) ;
F_56 ( V_14 , F_33 ( V_137 ) , 0 ) ;
F_56 ( V_14 , F_34 ( V_137 ) , 0 ) ;
V_108 -> V_134 = V_14 -> V_407 + F_34 ( V_137 ) ;
#if F_230 ( V_408 )
if ( ! V_108 -> V_147 || ( V_108 -> V_147 -> V_328 < V_337 ) )
#else
if ( ! V_108 -> V_147 || ( V_108 -> V_147 -> V_328 < 8 ) )
#endif
V_405 |= ( 1 << 16 ) ;
else
V_405 |= ( 8 << 16 ) ;
V_405 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_127 & V_374 ) {
V_108 -> V_409 = V_2 -> V_409 ;
V_108 -> V_410 = 0 ;
F_231 ( V_383 , & V_108 -> V_33 ) ;
} else {
V_108 -> V_409 = 0 ;
}
if ( ! F_14 ( V_411 , & V_108 -> V_33 ) ) {
struct V_146 * V_147 = V_108 -> V_147 ;
if ( V_147 )
F_232 ( V_108 -> V_45 ,
& V_147 -> V_397 ,
V_108 -> V_76 ) ;
}
F_19 ( V_120 , & V_108 -> V_33 ) ;
F_56 ( V_14 , F_35 ( V_137 ) , V_405 ) ;
if ( V_14 -> V_98 . type == V_99 &&
! ( F_22 ( V_14 , V_412 ) & V_413 ) )
return;
do {
F_233 ( 1000 , 2000 ) ;
V_405 = F_22 ( V_14 , F_35 ( V_137 ) ) ;
} while ( -- V_404 && ! ( V_405 & V_406 ) );
if ( ! V_404 )
F_88 ( V_145 , L_85 , V_137 ) ;
}
static void F_234 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_414 , V_415 ;
T_6 V_416 = F_235 ( V_2 -> V_45 ) ;
if ( V_14 -> V_98 . type == V_99 )
return;
V_414 = F_22 ( V_14 , V_417 ) ;
V_414 |= V_418 ;
F_56 ( V_14 , V_417 , V_414 ) ;
if ( V_2 -> V_127 & V_419 ) {
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
F_56 ( V_14 , V_430 , V_415 ) ;
if ( V_416 ) {
T_1 V_431 = F_22 ( V_14 , V_432 ) ;
V_431 |= V_433 ;
F_56 ( V_14 , V_432 , V_431 ) ;
}
V_414 &= ~ V_418 ;
F_56 ( V_14 , V_417 , V_414 ) ;
}
static void F_236 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_434 ;
T_1 V_38 ;
F_234 ( V_2 ) ;
if ( V_14 -> V_98 . type != V_99 ) {
V_434 = F_22 ( V_14 , V_435 ) ;
V_434 |= V_436 ;
F_56 ( V_14 , V_435 , V_434 ) ;
}
for ( V_38 = 0 ; V_38 < V_2 -> V_67 ; V_38 ++ )
F_228 ( V_2 , V_2 -> V_48 [ V_38 ] ) ;
}
static void F_237 ( struct V_1 * V_2 ,
struct V_47 * V_108 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_6 V_137 = V_108 -> V_137 ;
T_1 V_437 = F_22 ( V_14 , F_21 ( V_137 ) ) ;
V_437 |= V_438 ;
F_56 ( V_14 , F_21 ( V_137 ) , V_437 ) ;
}
static void F_238 ( struct V_1 * V_2 ,
struct V_47 * V_108 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_6 V_137 = V_108 -> V_137 ;
T_1 V_437 = F_22 ( V_14 , F_21 ( V_137 ) ) ;
V_437 &= ~ V_438 ;
F_56 ( V_14 , F_21 ( V_137 ) , V_437 ) ;
}
static void F_239 ( struct V_1 * V_2 ,
struct V_47 * V_57 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_437 ;
T_6 V_137 = V_57 -> V_137 ;
if ( V_14 -> V_98 . type == V_99 ) {
T_2 V_105 = V_2 -> V_424 [ V_425 ] . V_105 ;
V_137 &= V_105 ;
}
V_437 = V_276 << V_439 ;
V_437 |= F_54 ( V_57 ) >> V_440 ;
V_437 |= V_441 ;
F_56 ( V_14 , F_21 ( V_137 ) , V_437 ) ;
}
static void F_240 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
static const T_1 V_442 [ 10 ] = { 0xE291D73D , 0x1805EC6C , 0x2A94B30D ,
0xA54F2BEC , 0xEA49AF7C , 0xE214AD3D , 0xB855AABE ,
0x6A3E67EA , 0x14364D17 , 0x3BED200D } ;
T_1 V_443 = 0 , V_444 = 0 ;
T_1 V_445 ;
int V_38 , V_39 ;
T_2 V_446 = V_2 -> V_424 [ V_425 ] . V_426 ;
if ( ( V_2 -> V_127 & V_419 ) && ( V_446 < 2 ) )
V_446 = 2 ;
for ( V_38 = 0 ; V_38 < 10 ; V_38 ++ )
F_56 ( V_14 , F_241 ( V_38 ) , V_442 [ V_38 ] ) ;
for ( V_38 = 0 , V_39 = 0 ; V_38 < 128 ; V_38 ++ , V_39 ++ ) {
if ( V_39 == V_446 )
V_39 = 0 ;
V_444 = ( V_444 << 8 ) | ( V_39 * 0x11 ) ;
if ( ( V_38 & 3 ) == 3 )
F_56 ( V_14 , F_242 ( V_38 >> 2 ) , V_444 ) ;
}
V_445 = F_22 ( V_14 , V_447 ) ;
V_445 |= V_448 ;
F_56 ( V_14 , V_447 , V_445 ) ;
if ( V_2 -> V_14 . V_98 . type == V_99 ) {
if ( V_2 -> V_424 [ V_425 ] . V_105 )
V_443 = V_449 ;
} else {
T_6 V_416 = F_235 ( V_2 -> V_45 ) ;
if ( V_2 -> V_127 & V_419 ) {
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
F_56 ( V_14 , V_464 , V_443 ) ;
}
static void F_243 ( struct V_1 * V_2 ,
struct V_47 * V_108 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_465 ;
T_6 V_137 = V_108 -> V_137 ;
if ( ! F_153 ( V_108 ) )
return;
V_465 = F_22 ( V_14 , F_244 ( V_137 ) ) ;
V_465 |= V_466 ;
V_465 |= V_467 ;
F_56 ( V_14 , F_244 ( V_137 ) , V_465 ) ;
}
static void F_245 ( struct V_1 * V_2 ,
struct V_47 * V_108 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_404 = V_468 ;
T_1 V_469 ;
T_6 V_137 = V_108 -> V_137 ;
if ( V_14 -> V_98 . type == V_99 &&
! ( F_22 ( V_14 , V_412 ) & V_413 ) )
return;
do {
F_233 ( 1000 , 2000 ) ;
V_469 = F_22 ( V_14 , F_27 ( V_137 ) ) ;
} while ( -- V_404 && ! ( V_469 & V_470 ) );
if ( ! V_404 ) {
F_88 ( V_145 , L_86
L_87 , V_137 ) ;
}
}
void F_246 ( struct V_1 * V_2 ,
struct V_47 * V_108 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_404 = V_468 ;
T_1 V_469 ;
T_6 V_137 = V_108 -> V_137 ;
V_469 = F_22 ( V_14 , F_27 ( V_137 ) ) ;
V_469 &= ~ V_470 ;
F_56 ( V_14 , F_27 ( V_137 ) , V_469 ) ;
if ( V_14 -> V_98 . type == V_99 &&
! ( F_22 ( V_14 , V_412 ) & V_413 ) )
return;
do {
F_247 ( 10 ) ;
V_469 = F_22 ( V_14 , F_27 ( V_137 ) ) ;
} while ( -- V_404 && ( V_469 & V_470 ) );
if ( ! V_404 ) {
F_88 ( V_145 , L_88
L_87 , V_137 ) ;
}
}
void F_248 ( struct V_1 * V_2 ,
struct V_47 * V_108 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_4 V_471 = V_108 -> V_71 ;
T_1 V_469 ;
T_6 V_137 = V_108 -> V_137 ;
V_469 = F_22 ( V_14 , F_27 ( V_137 ) ) ;
F_246 ( V_2 , V_108 ) ;
F_56 ( V_14 , F_28 ( V_137 ) , ( V_471 & F_229 ( 32 ) ) ) ;
F_56 ( V_14 , F_29 ( V_137 ) , ( V_471 >> 32 ) ) ;
F_56 ( V_14 , F_24 ( V_137 ) ,
V_108 -> V_78 * sizeof( union V_58 ) ) ;
F_56 ( V_14 , F_25 ( V_137 ) , 0 ) ;
F_56 ( V_14 , F_26 ( V_137 ) , 0 ) ;
V_108 -> V_134 = V_14 -> V_407 + F_26 ( V_137 ) ;
F_239 ( V_2 , V_108 ) ;
F_243 ( V_2 , V_108 ) ;
if ( V_14 -> V_98 . type == V_99 ) {
V_469 &= ~ 0x3FFFFF ;
V_469 |= 0x080420 ;
}
V_469 |= V_470 ;
F_56 ( V_14 , F_27 ( V_137 ) , V_469 ) ;
F_245 ( V_2 , V_108 ) ;
F_129 ( V_108 , F_95 ( V_108 ) ) ;
}
static void F_249 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_446 = V_2 -> V_424 [ V_425 ] . V_426 ;
T_2 V_472 ;
T_1 V_473 = V_474 |
V_475 |
V_476 |
V_477 |
V_478 ;
if ( V_14 -> V_98 . type == V_99 )
return;
if ( V_446 > 3 )
V_473 |= 2 << 29 ;
else if ( V_446 > 1 )
V_473 |= 1 << 29 ;
F_250 (pool, &adapter->fwd_bitmask, 32 )
F_56 ( V_14 , F_251 ( F_252 ( V_472 ) ) , V_473 ) ;
}
static void F_253 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_166 , V_479 ;
T_1 V_480 , V_481 ;
int V_38 ;
if ( ! ( V_2 -> V_127 & V_419 ) )
return;
V_481 = F_22 ( V_14 , V_482 ) ;
V_481 |= V_483 ;
V_481 &= ~ V_484 ;
V_481 |= F_252 ( 0 ) << V_485 ;
V_481 |= V_486 ;
F_56 ( V_14 , V_482 , V_481 ) ;
V_479 = F_252 ( 0 ) % 32 ;
V_166 = ( F_252 ( 0 ) >= 32 ) ? 1 : 0 ;
F_56 ( V_14 , F_254 ( V_166 ) , ( ~ 0 ) << V_479 ) ;
F_56 ( V_14 , F_254 ( V_166 ^ 1 ) , V_166 - 1 ) ;
F_56 ( V_14 , F_255 ( V_166 ) , ( ~ 0 ) << V_479 ) ;
F_56 ( V_14 , F_255 ( V_166 ^ 1 ) , V_166 - 1 ) ;
if ( V_2 -> V_143 & V_487 )
F_56 ( V_14 , V_488 , V_489 ) ;
V_14 -> V_98 . V_347 . V_490 ( V_14 , 0 , F_252 ( 0 ) ) ;
switch ( V_2 -> V_424 [ V_491 ] . V_105 ) {
case V_492 :
V_480 = V_493 ;
break;
case V_494 :
V_480 = V_495 ;
break;
default:
V_480 = V_496 ;
break;
}
F_56 ( V_14 , V_497 , V_480 ) ;
V_14 -> V_98 . V_347 . V_498 ( V_14 , ( V_2 -> V_314 != 0 ) ,
V_2 -> V_314 ) ;
for ( V_38 = 0 ; V_38 < V_2 -> V_314 ; V_38 ++ ) {
if ( ! V_2 -> V_499 [ V_38 ] . V_500 )
F_256 ( V_2 -> V_45 , V_38 , false ) ;
}
}
static void F_257 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_44 * V_45 = V_2 -> V_45 ;
int V_501 = V_45 -> V_302 + V_235 + V_502 ;
struct V_47 * V_57 ;
int V_38 ;
T_1 V_503 , V_504 ;
#ifdef F_134
if ( ( V_2 -> V_127 & V_505 ) &&
( V_501 < V_506 ) )
V_501 = V_506 ;
#endif
if ( V_501 < ( V_507 + V_502 ) )
V_501 = ( V_507 + V_502 ) ;
V_503 = F_22 ( V_14 , V_508 ) ;
if ( V_501 != ( V_503 >> V_509 ) ) {
V_503 &= ~ V_510 ;
V_503 |= V_501 << V_509 ;
F_56 ( V_14 , V_508 , V_503 ) ;
}
V_504 = F_22 ( V_14 , V_511 ) ;
V_504 |= V_512 ;
F_56 ( V_14 , V_511 , V_504 ) ;
for ( V_38 = 0 ; V_38 < V_2 -> V_83 ; V_38 ++ ) {
V_57 = V_2 -> V_57 [ V_38 ] ;
if ( V_2 -> V_143 & V_513 )
F_258 ( V_57 ) ;
else
F_259 ( V_57 ) ;
}
}
static void F_260 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_514 = F_22 ( V_14 , V_515 ) ;
switch ( V_14 -> V_98 . type ) {
case V_99 :
V_514 |= V_516 ;
break;
case V_101 :
case V_102 :
F_56 ( V_14 , V_517 ,
( V_518 | F_22 ( V_14 , V_517 ) ) ) ;
V_514 &= ~ V_519 ;
V_514 |= ( V_520 | V_521 ) ;
V_514 |= V_522 ;
break;
default:
return;
}
F_56 ( V_14 , V_515 , V_514 ) ;
}
static void F_261 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_38 ;
T_1 V_171 , V_523 ;
V_171 = F_22 ( V_14 , V_524 ) ;
F_56 ( V_14 , V_524 , V_171 & ~ V_525 ) ;
F_249 ( V_2 ) ;
F_260 ( V_2 ) ;
V_523 = F_22 ( V_14 , V_526 ) ;
V_523 &= ~ V_527 ;
if ( ! ( V_2 -> V_143 & V_513 ) )
V_523 |= V_527 ;
F_56 ( V_14 , V_526 , V_523 ) ;
F_240 ( V_2 ) ;
F_257 ( V_2 ) ;
for ( V_38 = 0 ; V_38 < V_2 -> V_83 ; V_38 ++ )
F_248 ( V_2 , V_2 -> V_57 [ V_38 ] ) ;
if ( V_14 -> V_98 . type == V_99 )
V_171 |= V_528 ;
V_171 |= V_525 ;
V_14 -> V_98 . V_347 . V_529 ( V_14 , V_171 ) ;
}
static int F_262 ( struct V_44 * V_45 ,
T_9 V_530 , T_2 V_259 )
{
struct V_1 * V_2 = F_74 ( V_45 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
V_14 -> V_98 . V_347 . V_531 ( & V_2 -> V_14 , V_259 , F_252 ( 0 ) , true ) ;
F_231 ( V_259 , V_2 -> V_532 ) ;
return 0 ;
}
static int F_263 ( struct V_44 * V_45 ,
T_9 V_530 , T_2 V_259 )
{
struct V_1 * V_2 = F_74 ( V_45 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
V_14 -> V_98 . V_347 . V_531 ( & V_2 -> V_14 , V_259 , F_252 ( 0 ) , false ) ;
F_19 ( V_259 , V_2 -> V_532 ) ;
return 0 ;
}
static void F_264 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_533 ;
V_533 = F_22 ( V_14 , V_534 ) ;
V_533 &= ~ ( V_535 | V_536 ) ;
F_56 ( V_14 , V_534 , V_533 ) ;
}
static void F_265 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_533 ;
V_533 = F_22 ( V_14 , V_534 ) ;
V_533 |= V_535 ;
V_533 &= ~ V_536 ;
F_56 ( V_14 , V_534 , V_533 ) ;
}
static void F_266 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_533 ;
int V_38 , V_39 ;
switch ( V_14 -> V_98 . type ) {
case V_99 :
V_533 = F_22 ( V_14 , V_534 ) ;
V_533 &= ~ V_537 ;
F_56 ( V_14 , V_534 , V_533 ) ;
break;
case V_101 :
case V_102 :
for ( V_38 = 0 ; V_38 < V_2 -> V_83 ; V_38 ++ ) {
struct V_47 * V_108 = V_2 -> V_57 [ V_38 ] ;
if ( V_108 -> V_135 )
continue;
V_39 = V_108 -> V_137 ;
V_533 = F_22 ( V_14 , F_27 ( V_39 ) ) ;
V_533 &= ~ V_538 ;
F_56 ( V_14 , F_27 ( V_39 ) , V_533 ) ;
}
break;
default:
break;
}
}
static void F_267 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_533 ;
int V_38 , V_39 ;
switch ( V_14 -> V_98 . type ) {
case V_99 :
V_533 = F_22 ( V_14 , V_534 ) ;
V_533 |= V_537 ;
F_56 ( V_14 , V_534 , V_533 ) ;
break;
case V_101 :
case V_102 :
for ( V_38 = 0 ; V_38 < V_2 -> V_83 ; V_38 ++ ) {
struct V_47 * V_108 = V_2 -> V_57 [ V_38 ] ;
if ( V_108 -> V_135 )
continue;
V_39 = V_108 -> V_137 ;
V_533 = F_22 ( V_14 , F_27 ( V_39 ) ) ;
V_533 |= V_538 ;
F_56 ( V_14 , F_27 ( V_39 ) , V_533 ) ;
}
break;
default:
break;
}
}
static void F_268 ( struct V_1 * V_2 )
{
T_2 V_259 ;
F_262 ( V_2 -> V_45 , F_133 ( V_237 ) , 0 ) ;
F_250 (vid, adapter->active_vlans, VLAN_N_VID)
F_262 ( V_2 -> V_45 , F_133 ( V_237 ) , V_259 ) ;
}
static int F_269 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_74 ( V_45 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
unsigned int V_539 = V_14 -> V_98 . V_540 - 1 ;
int V_78 = 0 ;
if ( V_2 -> V_127 & V_419 )
V_539 = V_541 - 1 ;
if ( F_270 ( V_45 ) > V_539 )
return - V_542 ;
if ( ! F_271 ( V_45 ) ) {
struct V_543 * V_544 ;
if ( ! V_14 -> V_98 . V_347 . V_545 )
return - V_542 ;
F_272 (ha, netdev) {
if ( ! V_539 )
break;
V_14 -> V_98 . V_347 . V_545 ( V_14 , V_539 -- , V_544 -> V_546 ,
F_252 ( 0 ) , V_547 ) ;
V_78 ++ ;
}
}
for (; V_539 > 0 ; V_539 -- )
V_14 -> V_98 . V_347 . V_548 ( V_14 , V_539 ) ;
return V_78 ;
}
void F_273 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_74 ( V_45 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_549 , V_550 = V_551 | V_552 ;
int V_78 ;
V_549 = F_22 ( V_14 , V_553 ) ;
V_549 &= ~ V_554 ;
V_549 |= V_555 ;
V_549 |= V_556 ;
V_549 |= V_557 ;
V_549 &= ~ ( V_558 | V_559 ) ;
if ( V_45 -> V_127 & V_560 ) {
V_14 -> V_561 . V_562 = true ;
V_549 |= ( V_558 | V_559 ) ;
V_550 |= ( V_563 | V_564 ) ;
if ( ! ( V_2 -> V_127 & ( V_565 |
V_419 ) ) )
F_264 ( V_2 ) ;
else
F_265 ( V_2 ) ;
} else {
if ( V_45 -> V_127 & V_566 ) {
V_549 |= V_559 ;
V_550 |= V_564 ;
}
F_265 ( V_2 ) ;
V_14 -> V_561 . V_562 = false ;
}
V_78 = F_269 ( V_45 ) ;
if ( V_78 < 0 ) {
V_549 |= V_558 ;
V_550 |= V_563 ;
}
V_14 -> V_98 . V_347 . V_567 ( V_14 , V_45 ) ;
V_550 |= V_568 ;
if ( V_2 -> V_314 )
F_274 ( V_2 ) ;
if ( V_14 -> V_98 . type != V_99 ) {
V_550 |= F_22 ( V_14 , F_275 ( F_252 ( 0 ) ) ) &
~ ( V_564 | V_568 |
V_563 ) ;
F_56 ( V_14 , F_275 ( F_252 ( 0 ) ) , V_550 ) ;
}
if ( V_2 -> V_45 -> V_185 & V_280 ) {
V_549 |= ( V_554 |
V_555 |
V_557 ) ;
V_549 &= ~ ( V_556 ) ;
}
F_56 ( V_14 , V_553 , V_549 ) ;
if ( V_45 -> V_185 & V_257 )
F_267 ( V_2 ) ;
else
F_266 ( V_2 ) ;
}
static void F_276 ( struct V_1 * V_2 )
{
int V_569 ;
for ( V_569 = 0 ; V_569 < V_2 -> V_178 ; V_569 ++ ) {
F_277 ( V_2 -> V_147 [ V_569 ] ) ;
F_278 ( & V_2 -> V_147 [ V_569 ] -> V_261 ) ;
}
}
static void F_279 ( struct V_1 * V_2 )
{
int V_569 ;
for ( V_569 = 0 ; V_569 < V_2 -> V_178 ; V_569 ++ ) {
F_280 ( & V_2 -> V_147 [ V_569 ] -> V_261 ) ;
while ( ! F_281 ( V_2 -> V_147 [ V_569 ] ) ) {
F_36 ( L_89 , V_569 ) ;
F_233 ( 1000 , 20000 ) ;
}
}
}
static void F_282 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_501 = V_2 -> V_45 -> V_302 + V_235 + V_502 ;
if ( ! ( V_2 -> V_127 & V_128 ) ) {
if ( V_14 -> V_98 . type == V_99 )
F_283 ( V_2 -> V_45 , 65536 ) ;
return;
}
if ( V_14 -> V_98 . type == V_99 )
F_283 ( V_2 -> V_45 , 32768 ) ;
#ifdef F_134
if ( V_2 -> V_45 -> V_185 & V_570 )
V_501 = F_192 ( V_501 , V_506 ) ;
#endif
if ( V_2 -> V_571 & V_572 ) {
F_284 ( V_14 , & V_2 -> V_124 , V_501 ,
V_573 ) ;
F_284 ( V_14 , & V_2 -> V_124 , V_501 ,
V_574 ) ;
F_285 ( V_14 , & V_2 -> V_124 ) ;
} else if ( V_2 -> V_575 && V_2 -> V_126 ) {
F_286 ( & V_2 -> V_14 ,
V_2 -> V_575 ,
V_501 ) ;
F_287 ( & V_2 -> V_14 ,
V_2 -> V_126 -> V_123 ,
V_2 -> V_575 -> V_576 ) ;
}
if ( V_14 -> V_98 . type != V_99 ) {
T_1 V_577 = 0 ;
T_2 V_446 = V_2 -> V_424 [ V_425 ] . V_426 - 1 ;
while ( V_446 ) {
V_577 ++ ;
V_446 >>= 1 ;
}
F_56 ( V_14 , V_578 , V_577 * 0x11111111 ) ;
}
}
static int F_288 ( struct V_1 * V_2 , int V_579 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_44 * V_63 = V_2 -> V_45 ;
int V_380 , V_122 , V_580 , V_581 ;
T_1 V_582 , V_583 ;
V_122 = V_380 = V_63 -> V_302 + V_235 + V_502 + V_584 ;
#ifdef F_134
if ( ( V_63 -> V_185 & V_570 ) &&
( V_122 < V_506 ) &&
( V_579 == F_289 ( V_2 ) ) )
V_122 = V_506 ;
#endif
switch ( V_14 -> V_98 . type ) {
case V_102 :
V_582 = F_290 ( V_380 , V_122 ) ;
break;
default:
V_582 = F_291 ( V_380 , V_122 ) ;
break;
}
if ( V_2 -> V_127 & V_419 )
V_582 += F_292 ( V_122 ) ;
V_580 = F_293 ( V_582 ) ;
V_583 = F_22 ( V_14 , F_294 ( V_579 ) ) >> 10 ;
V_581 = V_583 - V_580 ;
if ( V_581 < 0 ) {
F_78 ( V_145 , L_90
L_91
L_92 , V_579 ) ;
V_581 = V_122 + 1 ;
}
return V_581 ;
}
static int F_295 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_44 * V_63 = V_2 -> V_45 ;
int V_122 ;
T_1 V_582 ;
V_122 = V_63 -> V_302 + V_235 + V_502 ;
switch ( V_14 -> V_98 . type ) {
case V_102 :
V_582 = F_296 ( V_122 ) ;
break;
default:
V_582 = F_297 ( V_122 ) ;
break;
}
return F_293 ( V_582 ) ;
}
static void F_298 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_585 = F_235 ( V_2 -> V_45 ) ;
int V_38 ;
if ( ! V_585 )
V_585 = 1 ;
V_14 -> V_113 . V_586 = F_295 ( V_2 ) ;
for ( V_38 = 0 ; V_38 < V_585 ; V_38 ++ ) {
V_14 -> V_113 . V_587 [ V_38 ] = F_288 ( V_2 , V_38 ) ;
if ( V_14 -> V_113 . V_586 > V_14 -> V_113 . V_587 [ V_38 ] )
V_14 -> V_113 . V_586 = 0 ;
}
}
static void F_299 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_588 ;
T_6 V_122 = F_235 ( V_2 -> V_45 ) ;
if ( V_2 -> V_127 & V_374 ||
V_2 -> V_127 & V_589 )
V_588 = 32 << V_2 -> V_590 ;
else
V_588 = 0 ;
V_14 -> V_98 . V_347 . V_591 ( V_14 , V_122 , V_588 , V_592 ) ;
F_298 ( V_2 ) ;
}
static void F_300 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_593 * V_594 ;
struct V_595 * V_596 ;
F_301 ( & V_2 -> V_597 ) ;
if ( ! F_302 ( & V_2 -> V_598 ) )
F_303 ( V_14 , & V_2 -> V_599 ) ;
F_304 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_305 ( V_14 ,
& V_596 -> V_596 ,
V_596 -> V_600 ,
( V_596 -> V_601 == V_602 ) ?
V_602 :
V_2 -> V_57 [ V_596 -> V_601 ] -> V_137 ) ;
}
F_306 ( & V_2 -> V_597 ) ;
}
static void F_307 ( struct V_44 * V_63 , unsigned int V_472 ,
struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_550 ;
V_550 = F_22 ( V_14 , F_275 ( V_472 ) ) ;
V_550 |= ( V_568 | V_551 | V_552 ) ;
V_550 &= ~ V_564 ;
if ( V_63 -> V_127 & V_566 ) {
V_550 |= V_564 ;
} else {
V_550 |= V_568 ;
V_14 -> V_98 . V_347 . V_567 ( V_14 , V_63 ) ;
}
F_269 ( V_2 -> V_45 ) ;
F_56 ( V_14 , F_275 ( V_472 ) , V_550 ) ;
}
static void F_308 ( struct V_1 * V_2 ,
T_6 * V_546 , T_2 V_472 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
unsigned int V_394 ;
V_394 = V_14 -> V_98 . V_540 - V_472 ;
V_14 -> V_98 . V_347 . V_545 ( V_14 , V_394 , V_546 , F_252 ( V_472 ) , V_547 ) ;
}
static void F_309 ( struct V_603 * V_604 )
{
struct V_1 * V_2 = V_604 -> V_136 ;
int V_446 = V_2 -> V_605 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
T_2 V_472 = V_604 -> V_472 ;
T_1 V_473 = V_474 |
V_475 |
V_476 |
V_477 |
V_478 ;
if ( V_14 -> V_98 . type == V_99 )
return;
if ( V_446 > 3 )
V_473 |= 2 << 29 ;
else if ( V_446 > 1 )
V_473 |= 1 << 29 ;
F_56 ( V_14 , F_251 ( F_252 ( V_472 ) ) , V_473 ) ;
}
static void F_310 ( struct V_47 * V_57 )
{
struct V_179 * V_63 = V_57 -> V_63 ;
unsigned long V_286 ;
T_2 V_38 ;
if ( ! V_57 -> V_61 )
return;
for ( V_38 = 0 ; V_38 < V_57 -> V_78 ; V_38 ++ ) {
struct V_60 * V_285 ;
V_285 = & V_57 -> V_61 [ V_38 ] ;
if ( V_285 -> V_79 ) {
struct V_184 * V_79 = V_285 -> V_79 ;
if ( F_139 ( V_79 ) -> V_278 ) {
F_65 ( V_63 ,
F_139 ( V_79 ) -> V_71 ,
F_54 ( V_57 ) ,
V_216 ) ;
F_139 ( V_79 ) -> V_278 = false ;
}
F_311 ( V_79 ) ;
}
V_285 -> V_79 = NULL ;
if ( V_285 -> V_71 )
F_65 ( V_63 , V_285 -> V_71 ,
F_126 ( V_57 ) ,
V_216 ) ;
V_285 -> V_71 = 0 ;
if ( V_285 -> V_88 )
F_128 ( V_285 -> V_88 ,
F_124 ( V_57 ) ) ;
V_285 -> V_88 = NULL ;
}
V_286 = sizeof( struct V_60 ) * V_57 -> V_78 ;
memset ( V_57 -> V_61 , 0 , V_286 ) ;
memset ( V_57 -> V_77 , 0 , V_57 -> V_286 ) ;
V_57 -> V_210 = 0 ;
V_57 -> V_69 = 0 ;
V_57 -> V_70 = 0 ;
}
static void F_312 ( struct V_603 * V_604 ,
struct V_47 * V_57 )
{
struct V_1 * V_2 = V_604 -> V_136 ;
int V_97 = V_57 -> V_76 + V_604 -> V_606 ;
F_246 ( V_2 , V_57 ) ;
F_233 ( 10000 , 20000 ) ;
F_202 ( V_2 , ( ( T_4 ) 1 << V_97 ) ) ;
F_310 ( V_57 ) ;
V_57 -> V_135 = NULL ;
}
static int F_313 ( struct V_44 * V_607 ,
struct V_603 * V_608 )
{
struct V_1 * V_2 = V_608 -> V_136 ;
unsigned int V_609 = V_608 -> V_606 ;
unsigned int V_610 = V_608 -> V_611 ;
int V_38 ;
F_314 ( V_607 ) ;
for ( V_38 = 0 ; V_38 < V_2 -> V_605 ; V_38 ++ ) {
F_312 ( V_608 , V_2 -> V_57 [ V_609 + V_38 ] ) ;
V_2 -> V_57 [ V_609 + V_38 ] -> V_45 = V_2 -> V_45 ;
}
for ( V_38 = 0 ; V_38 < V_2 -> V_605 ; V_38 ++ ) {
V_2 -> V_48 [ V_610 + V_38 ] -> V_135 = NULL ;
V_2 -> V_48 [ V_610 + V_38 ] -> V_45 = V_2 -> V_45 ;
}
return 0 ;
}
static int F_315 ( struct V_44 * V_607 ,
struct V_603 * V_608 )
{
struct V_1 * V_2 = V_608 -> V_136 ;
unsigned int V_609 , V_610 , V_366 ;
int V_38 , V_612 , V_16 = 0 ;
if ( ! F_13 ( V_608 -> V_472 , & V_2 -> V_613 ) )
return 0 ;
V_612 = V_608 -> V_472 * V_2 -> V_605 ;
F_316 ( V_607 , L_93 ,
V_608 -> V_472 , V_2 -> V_614 ,
V_612 , V_612 + V_2 -> V_605 ,
V_2 -> V_613 ) ;
V_608 -> V_45 = V_607 ;
V_608 -> V_606 = V_609 = V_612 ;
V_608 -> V_611 = V_610 = V_612 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_605 ; V_38 ++ )
F_312 ( V_608 , V_2 -> V_57 [ V_609 + V_38 ] ) ;
for ( V_38 = 0 ; V_38 < V_2 -> V_605 ; V_38 ++ ) {
V_2 -> V_57 [ V_609 + V_38 ] -> V_45 = V_607 ;
V_2 -> V_57 [ V_609 + V_38 ] -> V_135 = V_608 ;
F_248 ( V_2 , V_2 -> V_57 [ V_609 + V_38 ] ) ;
}
for ( V_38 = 0 ; V_38 < V_2 -> V_605 ; V_38 ++ ) {
V_2 -> V_48 [ V_610 + V_38 ] -> V_45 = V_607 ;
V_2 -> V_48 [ V_610 + V_38 ] -> V_135 = V_608 ;
}
V_366 = F_317 (unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues) ;
V_16 = F_318 ( V_607 , V_366 ) ;
if ( V_16 )
goto V_615;
V_16 = F_319 ( V_607 , V_366 ) ;
if ( V_16 )
goto V_615;
if ( F_320 ( V_607 -> V_616 ) )
F_308 ( V_2 , V_607 -> V_616 , V_608 -> V_472 ) ;
F_309 ( V_608 ) ;
F_307 ( V_607 , V_608 -> V_472 , V_2 ) ;
return V_16 ;
V_615:
F_313 ( V_607 , V_608 ) ;
return V_16 ;
}
static void F_321 ( struct V_1 * V_2 )
{
struct V_44 * V_85 ;
struct V_617 * V_618 ;
int V_16 ;
F_322 (adapter->netdev, upper, iter) {
if ( F_323 ( V_85 ) ) {
struct V_619 * V_620 = F_74 ( V_85 ) ;
struct V_603 * V_604 = V_620 -> V_621 ;
if ( V_620 -> V_621 ) {
V_16 = F_315 ( V_85 , V_604 ) ;
if ( V_16 )
continue;
}
}
}
}
static void F_324 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
F_299 ( V_2 ) ;
#ifdef F_325
F_282 ( V_2 ) ;
#endif
F_253 ( V_2 ) ;
F_273 ( V_2 -> V_45 ) ;
F_268 ( V_2 ) ;
switch ( V_14 -> V_98 . type ) {
case V_101 :
case V_102 :
V_14 -> V_98 . V_347 . V_622 ( V_14 ) ;
break;
default:
break;
}
if ( V_2 -> V_127 & V_374 ) {
F_326 ( & V_2 -> V_14 ,
V_2 -> V_590 ) ;
} else if ( V_2 -> V_127 & V_589 ) {
F_327 ( & V_2 -> V_14 ,
V_2 -> V_590 ) ;
F_300 ( V_2 ) ;
}
switch ( V_14 -> V_98 . type ) {
case V_101 :
case V_102 :
V_14 -> V_98 . V_347 . V_623 ( V_14 ) ;
break;
default:
break;
}
#ifdef F_134
F_328 ( V_2 ) ;
#endif
F_236 ( V_2 ) ;
F_261 ( V_2 ) ;
F_321 ( V_2 ) ;
}
static inline bool F_329 ( struct V_13 * V_14 )
{
switch ( V_14 -> V_350 . type ) {
case V_624 :
case V_625 :
case V_626 :
case V_627 :
case V_628 :
case V_629 :
case V_630 :
case V_631 :
case V_632 :
case V_633 :
case V_634 :
case V_635 :
return true ;
case V_636 :
if ( V_14 -> V_98 . type == V_99 )
return true ;
default:
return false ;
}
}
static void F_330 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_98 . type == V_99 )
V_2 -> V_143 |= V_637 ;
V_2 -> V_143 |= V_358 ;
}
static int F_331 ( struct V_13 * V_14 )
{
T_1 V_19 ;
bool V_638 , V_349 = false ;
T_1 V_142 = V_639 ;
if ( V_14 -> V_98 . V_347 . V_348 )
V_142 = V_14 -> V_98 . V_347 . V_348 ( V_14 , & V_19 , & V_349 , false ) ;
if ( V_142 )
goto V_640;
V_19 = V_14 -> V_350 . V_641 ;
if ( ( ! V_19 ) && ( V_14 -> V_98 . V_347 . V_642 ) )
V_142 = V_14 -> V_98 . V_347 . V_642 ( V_14 , & V_19 ,
& V_638 ) ;
if ( V_142 )
goto V_640;
if ( V_14 -> V_98 . V_347 . V_643 )
V_142 = V_14 -> V_98 . V_347 . V_643 ( V_14 , V_19 , V_349 ) ;
V_640:
return V_142 ;
}
static void F_332 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_644 = 0 ;
if ( V_2 -> V_127 & V_398 ) {
V_644 = V_645 | V_646 |
V_647 ;
V_644 |= V_648 ;
switch ( V_14 -> V_98 . type ) {
case V_99 :
F_56 ( V_14 , V_649 , V_650 ) ;
break;
case V_101 :
case V_102 :
default:
F_56 ( V_14 , F_333 ( 0 ) , 0xFFFFFFFF ) ;
F_56 ( V_14 , F_333 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_56 ( V_14 , V_649 , V_650 ) ;
}
if ( V_2 -> V_127 & V_419 ) {
V_644 &= ~ V_651 ;
switch ( V_2 -> V_424 [ V_491 ] . V_105 ) {
case V_492 :
V_644 |= V_652 ;
break;
case V_494 :
V_644 |= V_653 ;
break;
default:
V_644 |= V_654 ;
break;
}
}
if ( V_2 -> V_143 & V_342 ) {
switch ( V_2 -> V_14 . V_98 . type ) {
case V_101 :
V_644 |= V_655 ;
break;
case V_102 :
V_644 |= V_369 ;
break;
default:
break;
}
}
if ( V_2 -> V_127 & V_353 )
V_644 |= V_656 ;
if ( V_14 -> V_98 . type == V_101 ) {
V_644 |= V_656 ;
V_644 |= V_657 ;
}
F_56 ( V_14 , V_658 , V_644 ) ;
}
static void F_334 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_44 * V_85 ;
struct V_617 * V_618 ;
int V_16 ;
T_1 V_90 ;
F_57 ( V_2 ) ;
F_332 ( V_2 ) ;
if ( V_2 -> V_127 & V_398 )
F_187 ( V_2 ) ;
else
F_227 ( V_2 ) ;
if ( V_14 -> V_98 . V_347 . V_659 )
V_14 -> V_98 . V_347 . V_659 ( V_14 ) ;
F_19 ( V_32 , & V_2 -> V_33 ) ;
F_276 ( V_2 ) ;
if ( F_329 ( V_14 ) ) {
F_330 ( V_2 ) ;
} else {
V_16 = F_331 ( V_14 ) ;
if ( V_16 )
F_88 ( V_161 , L_94 , V_16 ) ;
}
F_22 ( V_14 , V_355 ) ;
F_204 ( V_2 , true , true ) ;
if ( V_2 -> V_127 & V_353 ) {
T_1 V_660 = F_22 ( V_14 , V_661 ) ;
if ( V_660 & V_662 )
F_194 ( V_145 , L_72 ) ;
}
F_335 ( V_2 -> V_45 ) ;
F_322 (adapter->netdev, upper, iter) {
if ( F_323 ( V_85 ) ) {
struct V_619 * V_226 = F_74 ( V_85 ) ;
if ( V_226 -> V_621 )
F_335 ( V_85 ) ;
}
}
V_2 -> V_127 |= V_361 ;
V_2 -> V_362 = V_160 ;
F_336 ( & V_2 -> V_663 , V_160 ) ;
V_90 = F_22 ( V_14 , V_91 ) ;
V_90 |= V_664 ;
F_56 ( V_14 , V_91 , V_90 ) ;
}
void F_337 ( struct V_1 * V_2 )
{
F_338 ( F_339 () ) ;
V_2 -> V_45 -> V_64 = V_160 ;
while ( F_14 ( V_665 , & V_2 -> V_33 ) )
F_233 ( 1000 , 2000 ) ;
F_340 ( V_2 ) ;
if ( V_2 -> V_127 & V_419 )
F_341 ( 2000 ) ;
F_342 ( V_2 ) ;
F_19 ( V_665 , & V_2 -> V_33 ) ;
}
void F_342 ( struct V_1 * V_2 )
{
F_324 ( V_2 ) ;
F_334 ( V_2 ) ;
}
void F_343 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_16 ;
while ( F_14 ( V_666 , & V_2 -> V_33 ) )
F_233 ( 1000 , 2000 ) ;
V_2 -> V_143 &= ~ ( V_637 |
V_358 ) ;
V_2 -> V_127 &= ~ V_359 ;
V_16 = V_14 -> V_98 . V_347 . V_667 ( V_14 ) ;
switch ( V_16 ) {
case 0 :
case V_668 :
case V_669 :
break;
case V_670 :
F_344 ( L_95 ) ;
break;
case V_671 :
F_10 ( L_96
L_97
L_98
L_99
L_100
L_101 ) ;
break;
default:
F_344 ( L_102 , V_16 ) ;
}
F_19 ( V_666 , & V_2 -> V_33 ) ;
V_14 -> V_98 . V_347 . V_545 ( V_14 , 0 , V_14 -> V_98 . V_546 , F_252 ( 0 ) , V_547 ) ;
if ( V_14 -> V_98 . V_672 )
V_14 -> V_98 . V_347 . V_673 ( V_14 , F_252 ( 0 ) ) ;
if ( F_13 ( V_674 , & V_2 -> V_33 ) )
F_345 ( V_2 ) ;
}
static void F_346 ( struct V_47 * V_48 )
{
struct V_49 * V_68 ;
unsigned long V_286 ;
T_2 V_38 ;
if ( ! V_48 -> V_68 )
return;
for ( V_38 = 0 ; V_38 < V_48 -> V_78 ; V_38 ++ ) {
V_68 = & V_48 -> V_68 [ V_38 ] ;
F_62 ( V_48 , V_68 ) ;
}
F_347 ( F_92 ( V_48 ) ) ;
V_286 = sizeof( struct V_49 ) * V_48 -> V_78 ;
memset ( V_48 -> V_68 , 0 , V_286 ) ;
memset ( V_48 -> V_77 , 0 , V_48 -> V_286 ) ;
V_48 -> V_70 = 0 ;
V_48 -> V_69 = 0 ;
}
static void F_348 ( struct V_1 * V_2 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_83 ; V_38 ++ )
F_310 ( V_2 -> V_57 [ V_38 ] ) ;
}
static void F_349 ( struct V_1 * V_2 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_67 ; V_38 ++ )
F_346 ( V_2 -> V_48 [ V_38 ] ) ;
}
static void F_350 ( struct V_1 * V_2 )
{
struct V_593 * V_594 ;
struct V_595 * V_596 ;
F_301 ( & V_2 -> V_597 ) ;
F_304 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_351 ( & V_596 -> V_675 ) ;
F_221 ( V_596 ) ;
}
V_2 -> V_676 = 0 ;
F_306 ( & V_2 -> V_597 ) ;
}
void F_340 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_44 * V_85 ;
struct V_617 * V_618 ;
T_1 V_171 ;
int V_38 ;
F_231 ( V_32 , & V_2 -> V_33 ) ;
V_171 = F_22 ( V_14 , V_524 ) ;
F_56 ( V_14 , V_524 , V_171 & ~ V_525 ) ;
for ( V_38 = 0 ; V_38 < V_2 -> V_83 ; V_38 ++ )
F_246 ( V_2 , V_2 -> V_57 [ V_38 ] ) ;
F_233 ( 10000 , 20000 ) ;
F_314 ( V_45 ) ;
F_352 ( V_45 ) ;
F_353 ( V_45 ) ;
F_322 (adapter->netdev, upper, iter) {
if ( F_323 ( V_85 ) ) {
struct V_619 * V_226 = F_74 ( V_85 ) ;
if ( V_226 -> V_621 ) {
F_314 ( V_85 ) ;
F_352 ( V_85 ) ;
F_353 ( V_85 ) ;
}
}
}
F_225 ( V_2 ) ;
F_279 ( V_2 ) ;
V_2 -> V_143 &= ~ ( V_375 |
V_144 ) ;
V_2 -> V_127 &= ~ V_361 ;
F_354 ( & V_2 -> V_663 ) ;
if ( V_2 -> V_314 ) {
F_56 ( & V_2 -> V_14 , V_316 , 0 ) ;
for ( V_38 = 0 ; V_38 < V_2 -> V_314 ; V_38 ++ )
V_2 -> V_499 [ V_38 ] . V_677 = false ;
F_355 ( V_2 ) ;
F_356 ( V_2 ) ;
}
for ( V_38 = 0 ; V_38 < V_2 -> V_67 ; V_38 ++ ) {
T_6 V_137 = V_2 -> V_48 [ V_38 ] -> V_137 ;
F_56 ( V_14 , F_35 ( V_137 ) , V_678 ) ;
}
switch ( V_14 -> V_98 . type ) {
case V_101 :
case V_102 :
F_56 ( V_14 , V_435 ,
( F_22 ( V_14 , V_435 ) &
~ V_436 ) ) ;
break;
default:
break;
}
if ( ! F_357 ( V_2 -> V_9 ) )
F_343 ( V_2 ) ;
if ( V_14 -> V_98 . V_347 . V_679 )
V_14 -> V_98 . V_347 . V_679 ( V_14 ) ;
F_349 ( V_2 ) ;
F_348 ( V_2 ) ;
#ifdef F_212
F_108 ( V_2 ) ;
#endif
}
static void F_358 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_74 ( V_45 ) ;
F_77 ( V_2 ) ;
}
static int F_359 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_190 , V_680 ;
T_1 V_681 ;
#ifdef F_325
int V_39 ;
struct V_682 * V_122 ;
#endif
V_14 -> V_683 = V_9 -> V_684 ;
V_14 -> V_20 = V_9 -> V_179 ;
V_14 -> V_685 = V_9 -> V_686 ;
V_14 -> V_687 = V_9 -> V_688 ;
V_14 -> V_689 = V_9 -> V_690 ;
V_190 = F_317 ( int , V_691 , F_360 () ) ;
V_2 -> V_424 [ V_425 ] . V_692 = V_190 ;
V_2 -> V_143 |= V_693 ;
V_2 -> V_143 |= V_513 ;
V_2 -> V_694 = V_695 ;
V_2 -> V_409 = 20 ;
V_680 = F_317 ( int , V_696 , F_360 () ) ;
V_2 -> V_424 [ V_697 ] . V_692 = V_680 ;
V_2 -> V_590 = V_698 ;
#ifdef F_212
V_2 -> V_127 |= V_181 ;
#endif
#ifdef F_134
V_2 -> V_127 |= V_699 ;
V_2 -> V_127 &= ~ V_505 ;
#ifdef F_325
V_2 -> V_700 . V_701 = V_702 ;
#endif
#endif
switch ( V_14 -> V_98 . type ) {
case V_99 :
V_2 -> V_143 &= ~ V_693 ;
V_2 -> V_143 &= ~ V_513 ;
if ( V_14 -> V_20 == V_703 )
V_2 -> V_127 |= V_353 ;
V_2 -> V_694 = V_704 ;
V_2 -> V_424 [ V_697 ] . V_692 = 0 ;
V_2 -> V_409 = 0 ;
V_2 -> V_590 = 0 ;
#ifdef F_134
V_2 -> V_127 &= ~ V_699 ;
V_2 -> V_127 &= ~ V_505 ;
#ifdef F_325
V_2 -> V_700 . V_701 = 0 ;
#endif
#endif
break;
case V_101 :
if ( V_14 -> V_20 == V_344 )
V_2 -> V_143 |= V_342 ;
break;
case V_102 :
V_681 = F_22 ( V_14 , V_705 ) ;
if ( V_681 & V_706 )
V_2 -> V_143 |= V_342 ;
break;
default:
break;
}
#ifdef F_134
F_361 ( & V_2 -> V_700 . V_707 ) ;
#endif
F_361 ( & V_2 -> V_597 ) ;
#ifdef F_325
switch ( V_14 -> V_98 . type ) {
case V_102 :
V_2 -> V_124 . V_708 . V_709 = V_710 ;
V_2 -> V_124 . V_708 . V_711 = V_710 ;
break;
default:
V_2 -> V_124 . V_708 . V_709 = V_712 ;
V_2 -> V_124 . V_708 . V_711 = V_712 ;
break;
}
for ( V_39 = 0 ; V_39 < V_712 ; V_39 ++ ) {
V_122 = & V_2 -> V_124 . V_713 [ V_39 ] ;
V_122 -> V_714 [ V_573 ] . V_715 = 0 ;
V_122 -> V_714 [ V_573 ] . V_716 = 12 + ( V_39 & 1 ) ;
V_122 -> V_714 [ V_574 ] . V_715 = 0 ;
V_122 -> V_714 [ V_574 ] . V_716 = 12 + ( V_39 & 1 ) ;
V_122 -> V_717 = V_718 ;
}
V_122 = & V_2 -> V_124 . V_713 [ 0 ] ;
V_122 -> V_714 [ V_573 ] . V_719 = 0xFF ;
V_122 -> V_714 [ V_574 ] . V_719 = 0xFF ;
V_2 -> V_124 . V_720 [ V_573 ] [ 0 ] = 100 ;
V_2 -> V_124 . V_720 [ V_574 ] [ 0 ] = 100 ;
V_2 -> V_124 . V_125 = false ;
V_2 -> V_721 = 0x00 ;
V_2 -> V_571 = V_722 | V_572 ;
memcpy ( & V_2 -> V_723 , & V_2 -> V_124 ,
sizeof( V_2 -> V_723 ) ) ;
#endif
V_14 -> V_113 . V_724 = V_115 ;
V_14 -> V_113 . V_114 = V_115 ;
F_298 ( V_2 ) ;
V_14 -> V_113 . V_725 = V_726 ;
V_14 -> V_113 . V_727 = true ;
V_14 -> V_113 . V_728 = F_362 ( V_14 ) ;
#ifdef F_363
if ( V_729 > 0 )
F_10 ( L_103 ) ;
if ( V_14 -> V_98 . type != V_99 ) {
if ( V_729 > 63 ) {
V_2 -> V_314 = 0 ;
F_10 ( L_104 ) ;
} else {
V_2 -> V_314 = V_729 ;
}
}
#endif
V_2 -> V_389 = 1 ;
V_2 -> V_730 = 1 ;
V_2 -> V_731 = V_732 ;
V_2 -> V_733 = V_734 ;
V_2 -> V_735 = V_736 ;
if ( F_364 ( V_14 ) ) {
F_344 ( L_105 ) ;
return - V_737 ;
}
F_231 ( 0 , & V_2 -> V_613 ) ;
F_231 ( V_32 , & V_2 -> V_33 ) ;
return 0 ;
}
int F_365 ( struct V_47 * V_48 )
{
struct V_179 * V_63 = V_48 -> V_63 ;
int V_738 = F_366 ( V_63 ) ;
int V_739 = - 1 ;
int V_286 ;
V_286 = sizeof( struct V_49 ) * V_48 -> V_78 ;
if ( V_48 -> V_147 )
V_739 = V_48 -> V_147 -> V_739 ;
V_48 -> V_68 = F_367 ( V_286 , V_739 ) ;
if ( ! V_48 -> V_68 )
V_48 -> V_68 = F_368 ( V_286 ) ;
if ( ! V_48 -> V_68 )
goto V_16;
F_369 ( & V_48 -> V_158 ) ;
V_48 -> V_286 = V_48 -> V_78 * sizeof( union V_51 ) ;
V_48 -> V_286 = F_157 ( V_48 -> V_286 , 4096 ) ;
F_370 ( V_63 , V_739 ) ;
V_48 -> V_77 = F_371 ( V_63 ,
V_48 -> V_286 ,
& V_48 -> V_71 ,
V_740 ) ;
F_370 ( V_63 , V_738 ) ;
if ( ! V_48 -> V_77 )
V_48 -> V_77 = F_371 ( V_63 , V_48 -> V_286 ,
& V_48 -> V_71 , V_740 ) ;
if ( ! V_48 -> V_77 )
goto V_16;
V_48 -> V_70 = 0 ;
V_48 -> V_69 = 0 ;
return 0 ;
V_16:
F_372 ( V_48 -> V_68 ) ;
V_48 -> V_68 = NULL ;
F_373 ( V_63 , L_106 ) ;
return - V_542 ;
}
static int F_374 ( struct V_1 * V_2 )
{
int V_38 , V_16 = 0 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_67 ; V_38 ++ ) {
V_16 = F_365 ( V_2 -> V_48 [ V_38 ] ) ;
if ( ! V_16 )
continue;
F_88 ( V_161 , L_107 , V_38 ) ;
goto V_741;
}
return 0 ;
V_741:
while ( V_38 -- )
F_375 ( V_2 -> V_48 [ V_38 ] ) ;
return V_16 ;
}
int F_376 ( struct V_47 * V_57 )
{
struct V_179 * V_63 = V_57 -> V_63 ;
int V_738 = F_366 ( V_63 ) ;
int V_739 = - 1 ;
int V_286 ;
V_286 = sizeof( struct V_60 ) * V_57 -> V_78 ;
if ( V_57 -> V_147 )
V_739 = V_57 -> V_147 -> V_739 ;
V_57 -> V_61 = F_367 ( V_286 , V_739 ) ;
if ( ! V_57 -> V_61 )
V_57 -> V_61 = F_368 ( V_286 ) ;
if ( ! V_57 -> V_61 )
goto V_16;
F_369 ( & V_57 -> V_158 ) ;
V_57 -> V_286 = V_57 -> V_78 * sizeof( union V_58 ) ;
V_57 -> V_286 = F_157 ( V_57 -> V_286 , 4096 ) ;
F_370 ( V_63 , V_739 ) ;
V_57 -> V_77 = F_371 ( V_63 ,
V_57 -> V_286 ,
& V_57 -> V_71 ,
V_740 ) ;
F_370 ( V_63 , V_738 ) ;
if ( ! V_57 -> V_77 )
V_57 -> V_77 = F_371 ( V_63 , V_57 -> V_286 ,
& V_57 -> V_71 , V_740 ) ;
if ( ! V_57 -> V_77 )
goto V_16;
V_57 -> V_69 = 0 ;
V_57 -> V_70 = 0 ;
return 0 ;
V_16:
F_372 ( V_57 -> V_61 ) ;
V_57 -> V_61 = NULL ;
F_373 ( V_63 , L_108 ) ;
return - V_542 ;
}
static int F_377 ( struct V_1 * V_2 )
{
int V_38 , V_16 = 0 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_83 ; V_38 ++ ) {
V_16 = F_376 ( V_2 -> V_57 [ V_38 ] ) ;
if ( ! V_16 )
continue;
F_88 ( V_161 , L_109 , V_38 ) ;
goto V_742;
}
#ifdef F_134
V_16 = F_378 ( V_2 ) ;
if ( ! V_16 )
#endif
return 0 ;
V_742:
while ( V_38 -- )
F_379 ( V_2 -> V_57 [ V_38 ] ) ;
return V_16 ;
}
void F_375 ( struct V_47 * V_48 )
{
F_346 ( V_48 ) ;
F_372 ( V_48 -> V_68 ) ;
V_48 -> V_68 = NULL ;
if ( ! V_48 -> V_77 )
return;
F_380 ( V_48 -> V_63 , V_48 -> V_286 ,
V_48 -> V_77 , V_48 -> V_71 ) ;
V_48 -> V_77 = NULL ;
}
static void F_381 ( struct V_1 * V_2 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_67 ; V_38 ++ )
if ( V_2 -> V_48 [ V_38 ] -> V_77 )
F_375 ( V_2 -> V_48 [ V_38 ] ) ;
}
void F_379 ( struct V_47 * V_57 )
{
F_310 ( V_57 ) ;
F_372 ( V_57 -> V_61 ) ;
V_57 -> V_61 = NULL ;
if ( ! V_57 -> V_77 )
return;
F_380 ( V_57 -> V_63 , V_57 -> V_286 ,
V_57 -> V_77 , V_57 -> V_71 ) ;
V_57 -> V_77 = NULL ;
}
static void F_382 ( struct V_1 * V_2 )
{
int V_38 ;
#ifdef F_134
F_383 ( V_2 ) ;
#endif
for ( V_38 = 0 ; V_38 < V_2 -> V_83 ; V_38 ++ )
if ( V_2 -> V_57 [ V_38 ] -> V_77 )
F_379 ( V_2 -> V_57 [ V_38 ] ) ;
}
static int F_384 ( struct V_44 * V_45 , int V_743 )
{
struct V_1 * V_2 = F_74 ( V_45 ) ;
int V_501 = V_743 + V_235 + V_502 ;
if ( ( V_743 < 68 ) || ( V_501 > V_744 ) )
return - V_745 ;
if ( ( V_2 -> V_127 & V_419 ) &&
( V_2 -> V_14 . V_98 . type == V_101 ) &&
( V_501 > ( V_507 + V_502 ) ) )
F_78 ( V_161 , L_110 ) ;
F_90 ( V_161 , L_111 , V_45 -> V_302 , V_743 ) ;
V_45 -> V_302 = V_743 ;
if ( F_42 ( V_45 ) )
F_337 ( V_2 ) ;
return 0 ;
}
static int F_385 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_74 ( V_45 ) ;
int V_16 , V_366 ;
if ( F_13 ( V_746 , & V_2 -> V_33 ) )
return - V_747 ;
F_352 ( V_45 ) ;
V_16 = F_374 ( V_2 ) ;
if ( V_16 )
goto V_741;
V_16 = F_377 ( V_2 ) ;
if ( V_16 )
goto V_742;
F_324 ( V_2 ) ;
V_16 = F_223 ( V_2 ) ;
if ( V_16 )
goto V_748;
if ( V_2 -> V_614 > 1 )
V_366 = V_2 -> V_605 ;
else
V_366 = V_2 -> V_67 ;
V_16 = F_318 ( V_45 , V_366 ) ;
if ( V_16 )
goto V_749;
if ( V_2 -> V_614 > 1 &&
V_2 -> V_83 > V_750 )
V_366 = V_750 ;
else
V_366 = V_2 -> V_83 ;
V_16 = F_319 ( V_45 , V_366 ) ;
if ( V_16 )
goto V_749;
F_386 ( V_2 ) ;
F_334 ( V_2 ) ;
return 0 ;
V_749:
F_224 ( V_2 ) ;
V_748:
F_382 ( V_2 ) ;
V_742:
F_381 ( V_2 ) ;
V_741:
F_343 ( V_2 ) ;
return V_16 ;
}
static int F_387 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_74 ( V_45 ) ;
F_388 ( V_2 ) ;
F_340 ( V_2 ) ;
F_224 ( V_2 ) ;
F_350 ( V_2 ) ;
F_381 ( V_2 ) ;
F_382 ( V_2 ) ;
F_55 ( V_2 ) ;
return 0 ;
}
static int F_389 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_390 ( V_9 ) ;
struct V_44 * V_45 = V_2 -> V_45 ;
T_1 V_16 ;
F_391 ( V_9 , V_751 ) ;
F_392 ( V_9 ) ;
F_393 ( V_9 ) ;
V_16 = F_394 ( V_9 ) ;
if ( V_16 ) {
F_344 ( L_112 ) ;
return V_16 ;
}
F_395 ( V_9 ) ;
F_396 ( V_9 , false ) ;
F_343 ( V_2 ) ;
F_56 ( & V_2 -> V_14 , V_752 , ~ 0 ) ;
F_397 () ;
V_16 = F_398 ( V_2 ) ;
if ( ! V_16 && F_42 ( V_45 ) )
V_16 = F_385 ( V_45 ) ;
F_399 () ;
if ( V_16 )
return V_16 ;
F_400 ( V_45 ) ;
return 0 ;
}
static int F_401 ( struct V_5 * V_9 , bool * V_753 )
{
struct V_1 * V_2 = F_390 ( V_9 ) ;
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_754 , V_549 ;
T_1 V_755 = V_2 -> V_756 ;
#ifdef F_402
int V_757 = 0 ;
#endif
F_403 ( V_45 ) ;
F_397 () ;
if ( F_42 ( V_45 ) ) {
F_340 ( V_2 ) ;
F_224 ( V_2 ) ;
F_381 ( V_2 ) ;
F_382 ( V_2 ) ;
}
F_399 () ;
F_404 ( V_2 ) ;
#ifdef F_402
V_757 = F_393 ( V_9 ) ;
if ( V_757 )
return V_757 ;
#endif
if ( V_14 -> V_98 . V_347 . V_758 )
V_14 -> V_98 . V_347 . V_758 ( V_14 ) ;
if ( V_755 ) {
F_273 ( V_45 ) ;
if ( V_14 -> V_98 . V_347 . V_659 )
V_14 -> V_98 . V_347 . V_659 ( V_14 ) ;
if ( V_755 & V_759 ) {
V_549 = F_22 ( V_14 , V_553 ) ;
V_549 |= V_559 ;
F_56 ( V_14 , V_553 , V_549 ) ;
}
V_754 = F_22 ( V_14 , V_760 ) ;
V_754 |= V_761 ;
F_56 ( V_14 , V_760 , V_754 ) ;
F_56 ( V_14 , V_762 , V_755 ) ;
} else {
F_56 ( V_14 , V_763 , 0 ) ;
F_56 ( V_14 , V_762 , 0 ) ;
}
switch ( V_14 -> V_98 . type ) {
case V_99 :
F_396 ( V_9 , false ) ;
break;
case V_101 :
case V_102 :
F_396 ( V_9 , ! ! V_755 ) ;
break;
default:
break;
}
* V_753 = ! ! V_755 ;
F_55 ( V_2 ) ;
F_405 ( V_9 ) ;
return 0 ;
}
static int F_406 ( struct V_5 * V_9 , T_12 V_33 )
{
int V_757 ;
bool V_764 ;
V_757 = F_401 ( V_9 , & V_764 ) ;
if ( V_757 )
return V_757 ;
if ( V_764 ) {
F_407 ( V_9 ) ;
} else {
F_396 ( V_9 , false ) ;
F_391 ( V_9 , V_765 ) ;
}
return 0 ;
}
static void F_408 ( struct V_5 * V_9 )
{
bool V_764 ;
F_401 ( V_9 , & V_764 ) ;
if ( V_766 == V_767 ) {
F_396 ( V_9 , V_764 ) ;
F_391 ( V_9 , V_765 ) ;
}
}
void F_409 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_110 * V_111 = & V_2 -> V_112 ;
T_4 V_768 = 0 ;
T_1 V_38 , V_769 = 0 , V_770 , V_771 , V_772 , V_773 , V_774 ;
T_4 V_270 = 0 , V_163 = 0 , V_775 = 0 ;
T_4 V_215 = 0 , V_295 = 0 ;
T_4 V_159 = 0 , V_132 = 0 , V_776 = 0 ;
if ( F_13 ( V_32 , & V_2 -> V_33 ) ||
F_13 ( V_665 , & V_2 -> V_33 ) )
return;
if ( V_2 -> V_143 & V_513 ) {
T_4 V_255 = 0 ;
T_4 V_256 = 0 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_83 ; V_38 ++ ) {
V_255 += V_2 -> V_57 [ V_38 ] -> V_201 . V_255 ;
V_256 += V_2 -> V_57 [ V_38 ] -> V_201 . V_256 ;
}
V_2 -> V_777 = V_255 ;
V_2 -> V_778 = V_256 ;
}
for ( V_38 = 0 ; V_38 < V_2 -> V_83 ; V_38 ++ ) {
struct V_47 * V_57 = V_2 -> V_57 [ V_38 ] ;
V_270 += V_57 -> V_201 . V_270 ;
V_215 += V_57 -> V_201 . V_215 ;
V_295 += V_57 -> V_201 . V_295 ;
V_776 += V_57 -> V_201 . V_202 ;
V_159 += V_57 -> V_112 . V_159 ;
V_132 += V_57 -> V_112 . V_132 ;
}
V_2 -> V_270 = V_270 ;
V_2 -> V_215 = V_215 ;
V_2 -> V_295 = V_295 ;
V_2 -> V_776 = V_776 ;
V_45 -> V_112 . V_779 = V_159 ;
V_45 -> V_112 . V_780 = V_132 ;
V_159 = 0 ;
V_132 = 0 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_67 ; V_38 ++ ) {
struct V_47 * V_48 = V_2 -> V_48 [ V_38 ] ;
V_163 += V_48 -> V_140 . V_163 ;
V_775 += V_48 -> V_140 . V_775 ;
V_159 += V_48 -> V_112 . V_159 ;
V_132 += V_48 -> V_112 . V_132 ;
}
V_2 -> V_163 = V_163 ;
V_2 -> V_775 = V_775 ;
V_45 -> V_112 . V_781 = V_159 ;
V_45 -> V_112 . V_782 = V_132 ;
V_111 -> V_783 += F_22 ( V_14 , V_784 ) ;
for ( V_38 = 0 ; V_38 < 8 ; V_38 ++ ) {
V_770 = F_22 ( V_14 , F_410 ( V_38 ) ) ;
V_769 += V_770 ;
V_111 -> V_770 [ V_38 ] += V_770 ;
V_768 += V_111 -> V_770 [ V_38 ] ;
V_111 -> V_785 [ V_38 ] += F_22 ( V_14 , F_411 ( V_38 ) ) ;
V_111 -> V_786 [ V_38 ] += F_22 ( V_14 , F_412 ( V_38 ) ) ;
switch ( V_14 -> V_98 . type ) {
case V_99 :
V_111 -> V_787 [ V_38 ] += F_22 ( V_14 , F_413 ( V_38 ) ) ;
V_111 -> V_788 [ V_38 ] += F_22 ( V_14 , F_414 ( V_38 ) ) ;
V_111 -> V_789 [ V_38 ] += F_22 ( V_14 , F_415 ( V_38 ) ) ;
V_111 -> V_790 [ V_38 ] +=
F_22 ( V_14 , F_416 ( V_38 ) ) ;
break;
case V_101 :
case V_102 :
V_111 -> V_790 [ V_38 ] +=
F_22 ( V_14 , F_417 ( V_38 ) ) ;
break;
default:
break;
}
}
for ( V_38 = 0 ; V_38 < 16 ; V_38 ++ ) {
V_111 -> V_791 [ V_38 ] += F_22 ( V_14 , F_418 ( V_38 ) ) ;
V_111 -> V_792 [ V_38 ] += F_22 ( V_14 , F_419 ( V_38 ) ) ;
if ( ( V_14 -> V_98 . type == V_101 ) ||
( V_14 -> V_98 . type == V_102 ) ) {
V_111 -> V_788 [ V_38 ] += F_22 ( V_14 , F_420 ( V_38 ) ) ;
F_22 ( V_14 , F_421 ( V_38 ) ) ;
V_111 -> V_789 [ V_38 ] += F_22 ( V_14 , F_422 ( V_38 ) ) ;
F_22 ( V_14 , F_423 ( V_38 ) ) ;
}
}
V_111 -> V_793 += F_22 ( V_14 , V_794 ) ;
V_111 -> V_793 -= V_769 ;
F_68 ( V_2 ) ;
switch ( V_14 -> V_98 . type ) {
case V_99 :
V_111 -> V_795 += F_22 ( V_14 , V_796 ) ;
V_111 -> V_797 += F_22 ( V_14 , V_798 ) ;
V_111 -> V_799 += F_22 ( V_14 , V_800 ) ;
V_111 -> V_801 += F_22 ( V_14 , V_802 ) ;
break;
case V_102 :
V_111 -> V_803 += F_22 ( V_14 , V_804 ) ;
V_111 -> V_805 += F_22 ( V_14 , V_806 ) ;
V_111 -> V_807 += F_22 ( V_14 , V_808 ) ;
V_111 -> V_809 += F_22 ( V_14 , V_810 ) ;
case V_101 :
for ( V_38 = 0 ; V_38 < 16 ; V_38 ++ )
V_2 -> V_811 +=
F_22 ( V_14 , F_424 ( V_38 ) ) ;
V_111 -> V_797 += F_22 ( V_14 , V_812 ) ;
F_22 ( V_14 , V_798 ) ;
V_111 -> V_799 += F_22 ( V_14 , V_813 ) ;
F_22 ( V_14 , V_800 ) ;
V_111 -> V_801 += F_22 ( V_14 , V_814 ) ;
F_22 ( V_14 , V_802 ) ;
V_111 -> V_795 += F_22 ( V_14 , V_815 ) ;
V_111 -> V_816 += F_22 ( V_14 , V_817 ) ;
V_111 -> V_818 += F_22 ( V_14 , V_819 ) ;
#ifdef F_134
V_111 -> V_820 += F_22 ( V_14 , V_821 ) ;
V_111 -> V_822 += F_22 ( V_14 , V_823 ) ;
V_111 -> V_824 += F_22 ( V_14 , V_825 ) ;
V_111 -> V_826 += F_22 ( V_14 , V_827 ) ;
V_111 -> V_828 += F_22 ( V_14 , V_829 ) ;
V_111 -> V_830 += F_22 ( V_14 , V_831 ) ;
if ( V_2 -> V_700 . V_832 ) {
struct V_833 * V_700 = & V_2 -> V_700 ;
struct V_834 * V_832 ;
unsigned int V_164 ;
T_4 V_835 = 0 , V_836 = 0 ;
F_425 (cpu) {
V_832 = F_426 ( V_700 -> V_832 , V_164 ) ;
V_835 += V_832 -> V_835 ;
V_836 += V_832 -> V_836 ;
}
V_111 -> V_837 = V_835 ;
V_111 -> V_838 = V_836 ;
}
#endif
break;
default:
break;
}
V_771 = F_22 ( V_14 , V_839 ) ;
V_111 -> V_771 += V_771 ;
V_111 -> V_840 += F_22 ( V_14 , V_841 ) ;
if ( V_14 -> V_98 . type == V_99 )
V_111 -> V_840 -= V_771 ;
V_111 -> V_842 += F_22 ( V_14 , V_843 ) ;
V_111 -> V_844 += F_22 ( V_14 , V_845 ) ;
V_111 -> V_846 += F_22 ( V_14 , V_847 ) ;
V_111 -> V_848 += F_22 ( V_14 , V_849 ) ;
V_111 -> V_850 += F_22 ( V_14 , V_851 ) ;
V_111 -> V_852 += F_22 ( V_14 , V_853 ) ;
V_111 -> V_854 += F_22 ( V_14 , V_855 ) ;
V_111 -> V_856 += F_22 ( V_14 , V_857 ) ;
V_772 = F_22 ( V_14 , V_858 ) ;
V_111 -> V_859 += V_772 ;
V_773 = F_22 ( V_14 , V_860 ) ;
V_111 -> V_861 += V_773 ;
V_111 -> V_862 += F_22 ( V_14 , V_863 ) ;
V_111 -> V_864 += F_22 ( V_14 , V_865 ) ;
V_774 = V_772 + V_773 ;
V_111 -> V_862 -= V_774 ;
V_111 -> V_864 -= V_774 ;
V_111 -> V_799 -= ( V_774 * ( V_866 + V_502 ) ) ;
V_111 -> V_867 += F_22 ( V_14 , V_868 ) ;
V_111 -> V_869 += F_22 ( V_14 , V_870 ) ;
V_111 -> V_871 += F_22 ( V_14 , V_872 ) ;
V_111 -> V_873 += F_22 ( V_14 , V_874 ) ;
V_111 -> V_875 += F_22 ( V_14 , V_876 ) ;
V_111 -> V_875 -= V_774 ;
V_111 -> V_877 += F_22 ( V_14 , V_878 ) ;
V_111 -> V_879 += F_22 ( V_14 , V_880 ) ;
V_111 -> V_881 += F_22 ( V_14 , V_882 ) ;
V_111 -> V_883 += F_22 ( V_14 , V_884 ) ;
V_111 -> V_885 += F_22 ( V_14 , V_886 ) ;
V_111 -> V_887 += F_22 ( V_14 , V_888 ) ;
V_45 -> V_112 . V_889 = V_111 -> V_840 ;
V_45 -> V_112 . V_890 = V_111 -> V_783 + V_111 -> V_856 ;
V_45 -> V_112 . V_891 = 0 ;
V_45 -> V_112 . V_892 = V_111 -> V_856 ;
V_45 -> V_112 . V_893 = V_111 -> V_783 ;
V_45 -> V_112 . V_894 = V_768 ;
}
static void F_427 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_38 ;
if ( ! ( V_2 -> V_143 & V_375 ) )
return;
V_2 -> V_143 &= ~ V_375 ;
if ( F_13 ( V_32 , & V_2 -> V_33 ) )
return;
if ( ! ( V_2 -> V_127 & V_374 ) )
return;
V_2 -> V_895 ++ ;
if ( F_428 ( V_14 ) == 0 ) {
for ( V_38 = 0 ; V_38 < V_2 -> V_67 ; V_38 ++ )
F_231 ( V_383 ,
& ( V_2 -> V_48 [ V_38 ] -> V_33 ) ) ;
F_56 ( V_14 , V_365 , V_376 ) ;
} else {
F_88 ( V_161 , L_113
L_114 ) ;
}
}
static void F_429 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_4 V_896 = 0 ;
int V_38 ;
if ( F_13 ( V_32 , & V_2 -> V_33 ) ||
F_13 ( V_665 , & V_2 -> V_33 ) )
return;
if ( F_94 ( V_2 -> V_45 ) ) {
for ( V_38 = 0 ; V_38 < V_2 -> V_67 ; V_38 ++ )
F_430 ( V_2 -> V_48 [ V_38 ] ) ;
}
if ( ! ( V_2 -> V_127 & V_398 ) ) {
F_56 ( V_14 , V_107 ,
( V_897 | V_898 ) ) ;
} else {
for ( V_38 = 0 ; V_38 < V_2 -> V_178 ; V_38 ++ ) {
struct V_146 * V_899 = V_2 -> V_147 [ V_38 ] ;
if ( V_899 -> V_306 . V_108 || V_899 -> V_151 . V_108 )
V_896 |= ( ( T_4 ) 1 << V_38 ) ;
}
}
F_60 ( V_2 , V_896 ) ;
}
static void F_431 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_900 = V_2 -> V_900 ;
bool V_349 = V_2 -> V_349 ;
bool V_123 = V_2 -> V_124 . V_125 ;
if ( ! ( V_2 -> V_127 & V_361 ) )
return;
if ( V_14 -> V_98 . V_347 . V_348 ) {
V_14 -> V_98 . V_347 . V_348 ( V_14 , & V_900 , & V_349 , false ) ;
} else {
V_900 = V_901 ;
V_349 = true ;
}
if ( V_2 -> V_126 )
V_123 |= ! ! ( V_2 -> V_126 -> V_123 ) ;
if ( V_349 && ! ( ( V_2 -> V_127 & V_128 ) && V_123 ) ) {
V_14 -> V_98 . V_347 . V_902 ( V_14 ) ;
F_432 ( V_2 ) ;
}
if ( V_349 ||
F_433 ( V_160 , ( V_2 -> V_362 +
V_903 ) ) ) {
V_2 -> V_127 &= ~ V_361 ;
F_56 ( V_14 , V_365 , V_364 ) ;
F_199 ( V_14 ) ;
}
V_2 -> V_349 = V_349 ;
V_2 -> V_900 = V_900 ;
}
static void F_434 ( struct V_1 * V_2 )
{
#ifdef F_325
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_904 V_905 = {
. V_906 = V_907 ,
. V_232 = 0 ,
} ;
T_6 V_701 = 0 ;
if ( V_2 -> V_571 & V_908 )
V_701 = F_435 ( V_45 , & V_905 ) ;
V_2 -> V_909 = ( V_701 > 1 ) ? ( F_436 ( V_701 ) - 1 ) : 0 ;
#endif
}
static void F_437 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_900 = V_2 -> V_900 ;
bool V_910 , V_911 ;
if ( F_94 ( V_45 ) )
return;
V_2 -> V_143 &= ~ V_637 ;
switch ( V_14 -> V_98 . type ) {
case V_99 : {
T_1 V_912 = F_22 ( V_14 , V_553 ) ;
T_1 V_913 = F_22 ( V_14 , V_914 ) ;
V_910 = ! ! ( V_912 & V_915 ) ;
V_911 = ! ! ( V_913 & V_916 ) ;
}
break;
case V_102 :
case V_101 : {
T_1 V_917 = F_22 ( V_14 , V_918 ) ;
T_1 V_919 = F_22 ( V_14 , V_920 ) ;
V_910 = ! ! ( V_917 & V_921 ) ;
V_911 = ! ! ( V_919 & V_922 ) ;
}
break;
default:
V_911 = false ;
V_910 = false ;
break;
}
V_2 -> V_923 = V_160 ;
if ( F_13 ( V_674 , & V_2 -> V_33 ) )
F_438 ( V_2 ) ;
F_90 ( V_145 , L_115 ,
( V_900 == V_901 ?
L_116 :
( V_900 == V_924 ?
L_117 :
( V_900 == V_925 ?
L_118 :
L_119 ) ) ) ,
( ( V_910 && V_911 ) ? L_120 :
( V_910 ? L_121 :
( V_911 ? L_122 : L_123 ) ) ) ) ;
F_439 ( V_45 ) ;
F_440 ( V_2 ) ;
F_434 ( V_2 ) ;
F_355 ( V_2 ) ;
}
static void F_441 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
V_2 -> V_349 = false ;
V_2 -> V_900 = 0 ;
if ( ! F_94 ( V_45 ) )
return;
if ( F_329 ( V_14 ) && V_14 -> V_98 . type == V_99 )
V_2 -> V_143 |= V_637 ;
if ( F_13 ( V_674 , & V_2 -> V_33 ) )
F_438 ( V_2 ) ;
F_90 ( V_145 , L_124 ) ;
F_352 ( V_45 ) ;
F_355 ( V_2 ) ;
}
static void F_442 ( struct V_1 * V_2 )
{
int V_38 ;
int V_926 = 0 ;
if ( ! F_94 ( V_2 -> V_45 ) ) {
for ( V_38 = 0 ; V_38 < V_2 -> V_67 ; V_38 ++ ) {
struct V_47 * V_48 = V_2 -> V_48 [ V_38 ] ;
if ( V_48 -> V_70 != V_48 -> V_69 ) {
V_926 = 1 ;
break;
}
}
if ( V_926 ) {
F_78 ( V_145 , L_125 ) ;
V_2 -> V_143 |= V_144 ;
}
}
}
static void F_443 ( struct V_1 * V_2 )
{
T_1 V_927 ;
if ( V_2 -> V_14 . V_98 . type == V_99 ||
V_2 -> V_314 == 0 )
return;
V_927 = F_22 ( & V_2 -> V_14 , V_928 ) ;
if ( ! V_927 )
return;
F_78 ( V_145 , L_126 , V_927 ) ;
}
static void F_444 ( struct V_1 * V_2 )
{
if ( F_13 ( V_32 , & V_2 -> V_33 ) ||
F_13 ( V_665 , & V_2 -> V_33 ) )
return;
F_431 ( V_2 ) ;
if ( V_2 -> V_349 )
F_437 ( V_2 ) ;
else
F_441 ( V_2 ) ;
F_443 ( V_2 ) ;
F_409 ( V_2 ) ;
F_442 ( V_2 ) ;
}
static void F_445 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_3 V_16 ;
if ( ! ( V_2 -> V_143 & V_637 ) &&
! ( V_2 -> V_143 & V_358 ) )
return;
if ( F_14 ( V_666 , & V_2 -> V_33 ) )
return;
V_16 = V_14 -> V_350 . V_347 . V_929 ( V_14 ) ;
if ( V_16 == V_669 )
goto V_930;
if ( V_16 == V_668 ) {
V_2 -> V_143 |= V_358 ;
}
if ( V_16 )
goto V_930;
if ( ! ( V_2 -> V_143 & V_358 ) )
goto V_930;
V_2 -> V_143 &= ~ V_358 ;
if ( V_14 -> V_98 . type == V_99 )
V_16 = V_14 -> V_350 . V_347 . V_931 ( V_14 ) ;
else
V_16 = V_14 -> V_98 . V_347 . V_932 ( V_14 ) ;
if ( V_16 == V_669 )
goto V_930;
V_2 -> V_127 |= V_359 ;
F_90 ( V_161 , L_127 , V_14 -> V_350 . V_933 ) ;
V_930:
F_19 ( V_666 , & V_2 -> V_33 ) ;
if ( ( V_16 == V_669 ) &&
( V_2 -> V_45 -> V_934 == V_935 ) ) {
F_344 ( L_128
L_129 ) ;
F_344 ( L_130
L_131 ) ;
F_446 ( V_2 -> V_45 ) ;
}
}
static void F_447 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_19 ;
bool V_638 = false ;
if ( ! ( V_2 -> V_127 & V_359 ) )
return;
if ( F_14 ( V_666 , & V_2 -> V_33 ) )
return;
V_2 -> V_127 &= ~ V_359 ;
V_19 = V_14 -> V_350 . V_641 ;
if ( ( ! V_19 ) && ( V_14 -> V_98 . V_347 . V_642 ) ) {
V_14 -> V_98 . V_347 . V_642 ( V_14 , & V_19 , & V_638 ) ;
if ( ! V_638 ) {
if ( V_19 & V_901 )
V_19 = V_901 ;
}
}
if ( V_14 -> V_98 . V_347 . V_643 )
V_14 -> V_98 . V_347 . V_643 ( V_14 , V_19 , true ) ;
V_2 -> V_127 |= V_361 ;
V_2 -> V_362 = V_160 ;
F_19 ( V_666 , & V_2 -> V_33 ) ;
}
static void F_448 ( struct V_1 * V_2 )
{
int V_936 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_44 * V_45 = V_2 -> V_45 ;
T_1 V_937 ;
T_1 V_938 , V_939 ;
V_937 = F_22 ( V_14 , V_940 ) ;
if ( V_937 )
return;
for ( V_936 = 0 ; V_936 < V_2 -> V_314 ; V_936 ++ ) {
V_938 = ( V_936 << 16 ) | 0x80000000 ;
V_938 |= V_941 ;
F_56 ( V_14 , V_942 , V_938 ) ;
V_939 = F_22 ( V_14 , V_943 ) ;
V_938 &= 0x7FFFFFFF ;
F_56 ( V_14 , V_942 , V_938 ) ;
V_939 >>= 16 ;
if ( V_939 & V_944 ) {
F_449 ( V_45 , L_132 , V_936 ) ;
V_938 = ( V_936 << 16 ) | 0x80000000 ;
V_938 |= 0xA8 ;
F_56 ( V_14 , V_942 , V_938 ) ;
V_939 = 0x00008000 ;
F_56 ( V_14 , V_943 , V_939 ) ;
V_938 &= 0x7FFFFFFF ;
F_56 ( V_14 , V_942 , V_938 ) ;
}
}
}
static void F_450 ( unsigned long V_82 )
{
struct V_1 * V_2 = (struct V_1 * ) V_82 ;
unsigned long V_945 ;
bool V_946 = true ;
if ( V_2 -> V_127 & V_361 )
V_945 = V_947 / 10 ;
else
V_945 = V_947 * 2 ;
#ifdef F_363
if ( ! V_2 -> V_314 ||
( V_2 -> V_127 & V_361 ) )
goto V_948;
F_448 ( V_2 ) ;
V_945 = V_947 / 50 ;
V_2 -> V_949 ++ ;
if ( V_2 -> V_949 >= 100 )
V_2 -> V_949 = 0 ;
else
V_946 = false ;
V_948:
#endif
F_336 ( & V_2 -> V_663 , V_945 + V_160 ) ;
if ( V_946 )
F_12 ( V_2 ) ;
}
static void F_451 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_143 & V_144 ) )
return;
V_2 -> V_143 &= ~ V_144 ;
if ( F_13 ( V_32 , & V_2 -> V_33 ) ||
F_13 ( V_665 , & V_2 -> V_33 ) )
return;
F_39 ( V_2 ) ;
F_449 ( V_2 -> V_45 , L_133 ) ;
V_2 -> V_162 ++ ;
F_337 ( V_2 ) ;
}
static void F_452 ( struct V_950 * V_951 )
{
struct V_1 * V_2 = F_183 ( V_951 ,
struct V_1 ,
V_35 ) ;
F_451 ( V_2 ) ;
F_445 ( V_2 ) ;
F_447 ( V_2 ) ;
F_193 ( V_2 ) ;
F_444 ( V_2 ) ;
F_427 ( V_2 ) ;
F_429 ( V_2 ) ;
if ( F_13 ( V_674 , & V_2 -> V_33 ) ) {
F_453 ( V_2 ) ;
F_454 ( V_2 ) ;
}
F_16 ( V_2 ) ;
}
static int F_455 ( struct V_47 * V_48 ,
struct V_49 * V_952 ,
T_6 * V_250 )
{
struct V_184 * V_79 = V_952 -> V_79 ;
T_1 V_953 , V_954 ;
T_1 V_955 , V_956 ;
if ( V_79 -> V_207 != V_957 )
return 0 ;
if ( ! F_456 ( V_79 ) )
return 0 ;
if ( F_457 ( V_79 ) ) {
int V_16 = F_458 ( V_79 , 0 , 0 , V_212 ) ;
if ( V_16 )
return V_16 ;
}
V_954 = V_958 ;
if ( V_952 -> V_232 == F_132 ( V_240 ) ) {
struct V_227 * V_959 = F_459 ( V_79 ) ;
V_959 -> V_960 = 0 ;
V_959 -> V_961 = 0 ;
F_460 ( V_79 ) -> V_961 = ~ F_461 ( V_959 -> V_962 ,
V_959 -> V_963 , 0 ,
V_246 ,
0 ) ;
V_954 |= V_964 ;
V_952 -> V_965 |= V_966 |
V_967 |
V_968 ;
} else if ( F_462 ( V_79 ) ) {
F_463 ( V_79 ) -> V_969 = 0 ;
F_460 ( V_79 ) -> V_961 =
~ F_464 ( & F_463 ( V_79 ) -> V_962 ,
& F_463 ( V_79 ) -> V_963 ,
0 , V_246 , 0 ) ;
V_952 -> V_965 |= V_966 |
V_967 ;
}
V_956 = F_465 ( V_79 ) ;
* V_250 = F_466 ( V_79 ) + V_956 ;
V_952 -> V_157 = F_137 ( V_79 ) -> V_157 ;
V_952 -> V_156 += ( V_952 -> V_157 - 1 ) * * V_250 ;
V_955 = V_956 << V_970 ;
V_955 |= F_137 ( V_79 ) -> V_251 << V_971 ;
V_953 = F_467 ( V_79 ) ;
V_953 |= F_468 ( V_79 ) << V_972 ;
V_953 |= V_952 -> V_965 & V_973 ;
F_469 ( V_48 , V_953 , 0 , V_954 ,
V_955 ) ;
return 1 ;
}
static void F_470 ( struct V_47 * V_48 ,
struct V_49 * V_952 )
{
struct V_184 * V_79 = V_952 -> V_79 ;
T_1 V_953 = 0 ;
T_1 V_955 = 0 ;
T_1 V_954 = 0 ;
if ( V_79 -> V_207 != V_957 ) {
if ( ! ( V_952 -> V_965 & V_974 ) &&
! ( V_952 -> V_965 & V_975 ) )
return;
} else {
T_6 V_976 = 0 ;
switch ( V_952 -> V_232 ) {
case F_132 ( V_240 ) :
V_953 |= F_467 ( V_79 ) ;
V_954 |= V_964 ;
V_976 = F_459 ( V_79 ) -> V_232 ;
break;
case F_132 ( V_243 ) :
V_953 |= F_467 ( V_79 ) ;
V_976 = F_463 ( V_79 ) -> V_233 ;
break;
default:
if ( F_82 ( F_471 () ) ) {
F_472 ( V_48 -> V_63 ,
L_134 ,
V_952 -> V_232 ) ;
}
break;
}
switch ( V_976 ) {
case V_246 :
V_954 |= V_958 ;
V_955 = F_465 ( V_79 ) <<
V_970 ;
break;
case V_977 :
V_954 |= V_978 ;
V_955 = sizeof( struct V_979 ) <<
V_970 ;
break;
case V_248 :
V_955 = sizeof( struct V_249 ) <<
V_970 ;
break;
default:
if ( F_82 ( F_471 () ) ) {
F_472 ( V_48 -> V_63 ,
L_135 ,
V_976 ) ;
}
break;
}
V_952 -> V_965 |= V_967 ;
}
V_953 |= F_468 ( V_79 ) << V_972 ;
V_953 |= V_952 -> V_965 & V_973 ;
F_469 ( V_48 , V_953 , 0 ,
V_954 , V_955 ) ;
}
static T_1 F_473 ( struct V_184 * V_79 , T_1 V_965 )
{
T_1 V_980 = V_981 |
V_982 |
V_983 ;
V_980 |= F_474 ( V_965 , V_974 ,
V_984 ) ;
V_980 |= F_474 ( V_965 , V_966 ,
V_985 ) ;
V_980 |= F_474 ( V_965 , V_986 ,
V_987 ) ;
V_980 ^= F_474 ( V_79 -> V_988 , 1 , V_983 ) ;
return V_980 ;
}
static void F_475 ( union V_51 * V_52 ,
T_1 V_965 , unsigned int V_989 )
{
T_1 V_990 = V_989 << V_991 ;
V_990 |= F_474 ( V_965 ,
V_967 ,
V_992 ) ;
V_990 |= F_474 ( V_965 ,
V_968 ,
V_993 ) ;
V_990 |= F_474 ( V_965 ,
V_975 ,
V_994 ) ;
V_52 -> V_218 . V_990 = F_81 ( V_990 ) ;
}
static void F_476 ( struct V_47 * V_48 ,
struct V_49 * V_952 ,
const T_6 V_250 )
{
struct V_184 * V_79 = V_952 -> V_79 ;
struct V_49 * V_50 ;
union V_51 * V_52 ;
struct V_271 * V_272 ;
T_8 V_71 ;
unsigned int V_277 , V_286 ;
T_1 V_965 = V_952 -> V_965 ;
T_1 V_980 = F_473 ( V_79 , V_965 ) ;
T_2 V_38 = V_48 -> V_70 ;
V_52 = F_46 ( V_48 , V_38 ) ;
F_475 ( V_52 , V_965 , V_79 -> V_72 - V_250 ) ;
V_286 = F_136 ( V_79 ) ;
V_277 = V_79 -> V_277 ;
#ifdef F_134
if ( V_965 & V_995 ) {
if ( V_277 < sizeof( struct V_305 ) ) {
V_286 -= sizeof( struct V_305 ) - V_277 ;
V_277 = 0 ;
} else {
V_277 -= sizeof( struct V_305 ) ;
}
}
#endif
V_71 = F_477 ( V_48 -> V_63 , V_79 -> V_82 , V_286 , V_109 ) ;
V_50 = V_952 ;
for ( V_272 = & F_137 ( V_79 ) -> V_273 [ 0 ] ; ; V_272 ++ ) {
if ( F_127 ( V_48 -> V_63 , V_71 ) )
goto V_996;
F_66 ( V_50 , V_72 , V_286 ) ;
F_478 ( V_50 , V_71 , V_71 ) ;
V_52 -> V_218 . V_997 = F_130 ( V_71 ) ;
while ( F_82 ( V_286 > V_998 ) ) {
V_52 -> V_218 . V_999 =
F_81 ( V_980 ^ V_998 ) ;
V_38 ++ ;
V_52 ++ ;
if ( V_38 == V_48 -> V_78 ) {
V_52 = F_46 ( V_48 , 0 ) ;
V_38 = 0 ;
}
V_52 -> V_218 . V_990 = 0 ;
V_71 += V_998 ;
V_286 -= V_998 ;
V_52 -> V_218 . V_997 = F_130 ( V_71 ) ;
}
if ( F_84 ( ! V_277 ) )
break;
V_52 -> V_218 . V_999 = F_81 ( V_980 ^ V_286 ) ;
V_38 ++ ;
V_52 ++ ;
if ( V_38 == V_48 -> V_78 ) {
V_52 = F_46 ( V_48 , 0 ) ;
V_38 = 0 ;
}
V_52 -> V_218 . V_990 = 0 ;
#ifdef F_134
V_286 = F_317 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_286 = F_479 ( V_272 ) ;
#endif
V_277 -= V_286 ;
V_71 = F_480 ( V_48 -> V_63 , V_272 , 0 , V_286 ,
V_109 ) ;
V_50 = & V_48 -> V_68 [ V_38 ] ;
}
V_980 |= V_286 | V_1000 ;
V_52 -> V_218 . V_999 = F_81 ( V_980 ) ;
F_481 ( F_92 ( V_48 ) , V_952 -> V_156 ) ;
V_952 -> V_74 = V_160 ;
F_120 () ;
V_952 -> V_73 = V_52 ;
V_38 ++ ;
if ( V_38 == V_48 -> V_78 )
V_38 = 0 ;
V_48 -> V_70 = V_38 ;
F_121 ( V_38 , V_48 -> V_134 ) ;
return;
V_996:
F_373 ( V_48 -> V_63 , L_136 ) ;
for (; ; ) {
V_50 = & V_48 -> V_68 [ V_38 ] ;
F_62 ( V_48 , V_50 ) ;
if ( V_50 == V_952 )
break;
if ( V_38 == 0 )
V_38 = V_48 -> V_78 ;
V_38 -- ;
}
V_48 -> V_70 = V_38 ;
}
static void F_482 ( struct V_47 * V_108 ,
struct V_49 * V_952 )
{
struct V_146 * V_147 = V_108 -> V_147 ;
union V_1001 V_1002 = { . V_1003 = 0 } ;
union V_1001 V_1004 = { . V_1003 = 0 } ;
union {
unsigned char * V_222 ;
struct V_227 * V_228 ;
struct V_229 * V_230 ;
} V_231 ;
struct V_247 * V_1005 ;
T_9 V_1006 ;
if ( ! V_147 )
return;
if ( ! V_108 -> V_409 )
return;
V_108 -> V_410 ++ ;
V_231 . V_222 = F_483 ( V_952 -> V_79 ) ;
if ( ( V_952 -> V_232 != F_132 ( V_243 ) ||
V_231 . V_230 -> V_233 != V_246 ) &&
( V_952 -> V_232 != F_132 ( V_240 ) ||
V_231 . V_228 -> V_232 != V_246 ) )
return;
V_1005 = F_460 ( V_952 -> V_79 ) ;
if ( ! V_1005 || V_1005 -> V_1007 )
return;
if ( ! V_1005 -> V_1008 && ( V_108 -> V_410 < V_108 -> V_409 ) )
return;
V_108 -> V_410 = 0 ;
V_1006 = F_133 ( V_952 -> V_965 >> V_1009 ) ;
V_1002 . V_1010 . V_1006 = V_1006 ;
if ( V_952 -> V_965 & ( V_1011 | V_974 ) )
V_1004 . V_1012 . V_1013 ^= V_1005 -> V_1014 ^ F_132 ( V_237 ) ;
else
V_1004 . V_1012 . V_1013 ^= V_1005 -> V_1014 ^ V_952 -> V_232 ;
V_1004 . V_1012 . V_1015 ^= V_1005 -> V_1016 ;
if ( V_952 -> V_232 == F_132 ( V_240 ) ) {
V_1002 . V_1010 . V_1017 = V_1018 ;
V_1004 . V_1019 ^= V_231 . V_228 -> V_962 ^ V_231 . V_228 -> V_963 ;
} else {
V_1002 . V_1010 . V_1017 = V_1020 ;
V_1004 . V_1019 ^= V_231 . V_230 -> V_962 . V_1021 [ 0 ] ^
V_231 . V_230 -> V_962 . V_1021 [ 1 ] ^
V_231 . V_230 -> V_962 . V_1021 [ 2 ] ^
V_231 . V_230 -> V_962 . V_1021 [ 3 ] ^
V_231 . V_230 -> V_963 . V_1021 [ 0 ] ^
V_231 . V_230 -> V_963 . V_1021 [ 1 ] ^
V_231 . V_230 -> V_963 . V_1021 [ 2 ] ^
V_231 . V_230 -> V_963 . V_1021 [ 3 ] ;
}
F_484 ( & V_147 -> V_2 -> V_14 ,
V_1002 , V_1004 , V_108 -> V_76 ) ;
}
static int F_485 ( struct V_47 * V_48 , T_2 V_286 )
{
F_89 ( V_48 -> V_45 , V_48 -> V_76 ) ;
F_96 () ;
if ( F_84 ( F_95 ( V_48 ) < V_286 ) )
return - V_747 ;
F_486 ( V_48 -> V_45 , V_48 -> V_76 ) ;
++ V_48 -> V_140 . V_163 ;
return 0 ;
}
static inline int F_487 ( struct V_47 * V_48 , T_2 V_286 )
{
if ( F_84 ( F_95 ( V_48 ) >= V_286 ) )
return 0 ;
return F_485 ( V_48 , V_286 ) ;
}
static T_2 F_488 ( struct V_44 * V_63 , struct V_184 * V_79 ,
void * V_1022 )
{
struct V_603 * V_1023 = V_1022 ;
#ifdef F_134
struct V_1 * V_2 ;
struct V_1024 * V_1025 ;
int V_1026 ;
#endif
if ( V_1023 )
return V_79 -> V_1027 + V_1023 -> V_611 ;
#ifdef F_134
switch ( F_489 ( V_79 ) ) {
case F_132 ( V_244 ) :
case F_132 ( V_1028 ) :
V_2 = F_74 ( V_63 ) ;
if ( V_2 -> V_127 & V_505 )
break;
default:
return F_490 ( V_63 , V_79 ) ;
}
V_1025 = & V_2 -> V_424 [ V_1029 ] ;
V_1026 = F_491 ( V_79 ) ? F_492 ( V_79 ) :
F_493 () ;
while ( V_1026 >= V_1025 -> V_426 )
V_1026 -= V_1025 -> V_426 ;
return V_1026 + V_1025 -> V_1030 ;
#else
return F_490 ( V_63 , V_79 ) ;
#endif
}
T_13 F_494 ( struct V_184 * V_79 ,
struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_49 * V_952 ;
int V_1031 ;
T_1 V_965 = 0 ;
unsigned short V_1025 ;
T_2 V_78 = F_495 ( F_136 ( V_79 ) ) ;
T_9 V_232 = V_79 -> V_232 ;
T_6 V_250 = 0 ;
for ( V_1025 = 0 ; V_1025 < F_137 ( V_79 ) -> V_292 ; V_1025 ++ )
V_78 += F_495 ( F_137 ( V_79 ) -> V_273 [ V_1025 ] . V_286 ) ;
if ( F_487 ( V_48 , V_78 + 3 ) ) {
V_48 -> V_140 . V_775 ++ ;
return V_1032 ;
}
V_952 = & V_48 -> V_68 [ V_48 -> V_70 ] ;
V_952 -> V_79 = V_79 ;
V_952 -> V_156 = V_79 -> V_72 ;
V_952 -> V_157 = 1 ;
if ( F_496 ( V_79 ) ) {
V_965 |= F_497 ( V_79 ) << V_1009 ;
V_965 |= V_974 ;
} else if ( V_232 == F_132 ( V_237 ) ) {
struct V_225 * V_1033 , V_1034 ;
V_1033 = F_498 ( V_79 , V_235 , sizeof( V_1034 ) , & V_1034 ) ;
if ( ! V_1033 )
goto V_1035;
V_232 = V_1033 -> V_239 ;
V_965 |= F_499 ( V_1033 -> V_1036 ) <<
V_1009 ;
V_965 |= V_1011 ;
}
F_500 ( V_79 ) ;
if ( F_82 ( F_137 ( V_79 ) -> V_965 & V_1037 ) ) {
F_137 ( V_79 ) -> V_965 |= V_1038 ;
V_965 |= V_986 ;
V_2 -> V_1039 = F_501 ( V_79 ) ;
V_2 -> V_1040 = V_160 ;
F_15 ( & V_2 -> V_1041 ) ;
}
#ifdef F_363
if ( V_2 -> V_127 & V_419 )
V_965 |= V_975 ;
#endif
if ( ( V_2 -> V_127 & V_128 ) &&
( ( V_965 & ( V_974 | V_1011 ) ) ||
( V_79 -> V_1042 != V_1043 ) ) ) {
V_965 &= ~ V_1044 ;
V_965 |= ( V_79 -> V_1042 & 0x7 ) <<
V_1045 ;
if ( V_965 & V_1011 ) {
struct V_1046 * V_1033 ;
if ( F_457 ( V_79 ) &&
F_458 ( V_79 , 0 , 0 , V_212 ) )
goto V_1035;
V_1033 = (struct V_1046 * ) V_79 -> V_82 ;
V_1033 -> V_1036 = F_133 ( V_965 >>
V_1009 ) ;
} else {
V_965 |= V_974 ;
}
}
V_952 -> V_965 = V_965 ;
V_952 -> V_232 = V_232 ;
#ifdef F_134
if ( ( V_232 == F_132 ( V_244 ) ) &&
( V_48 -> V_45 -> V_185 & ( V_1047 | V_1048 ) ) ) {
V_1031 = F_502 ( V_48 , V_952 , & V_250 ) ;
if ( V_1031 < 0 )
goto V_1035;
goto V_1049;
}
#endif
V_1031 = F_455 ( V_48 , V_952 , & V_250 ) ;
if ( V_1031 < 0 )
goto V_1035;
else if ( ! V_1031 )
F_470 ( V_48 , V_952 ) ;
if ( F_13 ( V_383 , & V_48 -> V_33 ) )
F_482 ( V_48 , V_952 ) ;
#ifdef F_134
V_1049:
#endif
F_476 ( V_48 , V_952 , V_250 ) ;
F_487 ( V_48 , V_1050 ) ;
return V_1051 ;
V_1035:
F_63 ( V_952 -> V_79 ) ;
V_952 -> V_79 = NULL ;
return V_1051 ;
}
static T_13 F_503 ( struct V_184 * V_79 ,
struct V_44 * V_45 ,
struct V_47 * V_108 )
{
struct V_1 * V_2 = F_74 ( V_45 ) ;
struct V_47 * V_48 ;
if ( F_82 ( V_79 -> V_72 < 17 ) ) {
if ( F_163 ( V_79 , 17 - V_79 -> V_72 ) )
return V_1051 ;
V_79 -> V_72 = 17 ;
F_504 ( V_79 , 17 ) ;
}
V_48 = V_108 ? V_108 : V_2 -> V_48 [ V_79 -> V_1027 ] ;
return F_494 ( V_79 , V_2 , V_48 ) ;
}
static T_13 F_505 ( struct V_184 * V_79 ,
struct V_44 * V_45 )
{
return F_503 ( V_79 , V_45 , NULL ) ;
}
static int F_506 ( struct V_44 * V_45 , void * V_1052 )
{
struct V_1 * V_2 = F_74 ( V_45 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_1053 * V_546 = V_1052 ;
if ( ! F_320 ( V_546 -> V_1054 ) )
return - V_1055 ;
memcpy ( V_45 -> V_616 , V_546 -> V_1054 , V_45 -> V_1056 ) ;
memcpy ( V_14 -> V_98 . V_546 , V_546 -> V_1054 , V_45 -> V_1056 ) ;
V_14 -> V_98 . V_347 . V_545 ( V_14 , 0 , V_14 -> V_98 . V_546 , F_252 ( 0 ) , V_547 ) ;
return 0 ;
}
static int
F_507 ( struct V_44 * V_45 , int V_1057 , int V_1058 , T_2 V_546 )
{
struct V_1 * V_2 = F_74 ( V_45 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
T_2 V_4 ;
int V_1059 ;
if ( V_1057 != V_14 -> V_350 . V_1060 . V_1057 )
return - V_745 ;
V_1059 = V_14 -> V_350 . V_347 . V_1061 ( V_14 , V_546 , V_1058 , & V_4 ) ;
if ( ! V_1059 )
V_1059 = V_4 ;
return V_1059 ;
}
static int F_508 ( struct V_44 * V_45 , int V_1057 , int V_1058 ,
T_2 V_546 , T_2 V_4 )
{
struct V_1 * V_2 = F_74 ( V_45 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
if ( V_1057 != V_14 -> V_350 . V_1060 . V_1057 )
return - V_745 ;
return V_14 -> V_350 . V_347 . V_1062 ( V_14 , V_546 , V_1058 , V_4 ) ;
}
static int F_509 ( struct V_44 * V_45 , struct V_1063 * V_1064 , int V_1065 )
{
struct V_1 * V_2 = F_74 ( V_45 ) ;
switch ( V_1065 ) {
case V_1066 :
return F_510 ( V_2 , V_1064 , V_1065 ) ;
default:
return F_511 ( & V_2 -> V_14 . V_350 . V_1060 , F_512 ( V_1064 ) , V_1065 ) ;
}
}
static int F_513 ( struct V_44 * V_63 )
{
int V_16 = 0 ;
struct V_1 * V_2 = F_74 ( V_63 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
if ( F_320 ( V_14 -> V_98 . V_1067 ) ) {
F_397 () ;
V_16 = F_514 ( V_63 , V_14 -> V_98 . V_1067 , V_1068 ) ;
F_399 () ;
V_14 -> V_98 . V_347 . V_673 ( V_14 , F_252 ( 0 ) ) ;
}
return V_16 ;
}
static int F_515 ( struct V_44 * V_63 )
{
int V_16 = 0 ;
struct V_1 * V_2 = F_74 ( V_63 ) ;
struct V_1069 * V_98 = & V_2 -> V_14 . V_98 ;
if ( F_320 ( V_98 -> V_1067 ) ) {
F_397 () ;
V_16 = F_516 ( V_63 , V_98 -> V_1067 , V_1068 ) ;
F_399 () ;
}
return V_16 ;
}
static void F_517 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_74 ( V_45 ) ;
int V_38 ;
if ( F_13 ( V_32 , & V_2 -> V_33 ) )
return;
V_2 -> V_127 |= V_260 ;
if ( V_2 -> V_127 & V_398 ) {
for ( V_38 = 0 ; V_38 < V_2 -> V_178 ; V_38 ++ )
F_209 ( 0 , V_2 -> V_147 [ V_38 ] ) ;
} else {
F_222 ( V_2 -> V_9 -> V_377 , V_45 ) ;
}
V_2 -> V_127 &= ~ V_260 ;
}
static struct V_1070 * F_518 ( struct V_44 * V_45 ,
struct V_1070 * V_112 )
{
struct V_1 * V_2 = F_74 ( V_45 ) ;
int V_38 ;
F_519 () ;
for ( V_38 = 0 ; V_38 < V_2 -> V_83 ; V_38 ++ ) {
struct V_47 * V_108 = F_520 ( V_2 -> V_57 [ V_38 ] ) ;
T_4 V_159 , V_132 ;
unsigned int V_1071 ;
if ( V_108 ) {
do {
V_1071 = F_521 ( & V_108 -> V_158 ) ;
V_132 = V_108 -> V_112 . V_132 ;
V_159 = V_108 -> V_112 . V_159 ;
} while ( F_522 ( & V_108 -> V_158 , V_1071 ) );
V_112 -> V_780 += V_132 ;
V_112 -> V_779 += V_159 ;
}
}
for ( V_38 = 0 ; V_38 < V_2 -> V_67 ; V_38 ++ ) {
struct V_47 * V_108 = F_520 ( V_2 -> V_48 [ V_38 ] ) ;
T_4 V_159 , V_132 ;
unsigned int V_1071 ;
if ( V_108 ) {
do {
V_1071 = F_521 ( & V_108 -> V_158 ) ;
V_132 = V_108 -> V_112 . V_132 ;
V_159 = V_108 -> V_112 . V_159 ;
} while ( F_522 ( & V_108 -> V_158 , V_1071 ) );
V_112 -> V_782 += V_132 ;
V_112 -> V_781 += V_159 ;
}
}
F_523 () ;
V_112 -> V_889 = V_45 -> V_112 . V_889 ;
V_112 -> V_890 = V_45 -> V_112 . V_890 ;
V_112 -> V_892 = V_45 -> V_112 . V_892 ;
V_112 -> V_893 = V_45 -> V_112 . V_893 ;
V_112 -> V_894 = V_45 -> V_112 . V_894 ;
return V_112 ;
}
static void F_524 ( struct V_1 * V_2 , T_6 V_122 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_3 , V_1072 ;
int V_38 ;
if ( V_14 -> V_98 . type == V_99 )
return;
V_3 = F_22 ( V_14 , V_1073 ) ;
V_1072 = V_3 ;
for ( V_38 = 0 ; V_38 < V_712 ; V_38 ++ ) {
T_6 V_1074 = V_3 >> ( V_38 * V_1075 ) ;
if ( V_1074 > V_122 )
V_3 &= ~ ( 0x7 << V_1075 ) ;
}
if ( V_3 != V_1072 )
F_56 ( V_14 , V_1073 , V_3 ) ;
return;
}
static void F_525 ( struct V_1 * V_2 )
{
struct V_44 * V_63 = V_2 -> V_45 ;
struct V_1076 * V_124 = & V_2 -> V_124 ;
struct V_1077 * V_1078 = V_2 -> V_575 ;
T_6 V_1079 ;
for ( V_1079 = 0 ; V_1079 < V_1080 ; V_1079 ++ ) {
T_6 V_122 = 0 ;
if ( V_2 -> V_571 & V_572 )
V_122 = F_526 ( V_124 , 0 , V_1079 ) ;
else if ( V_1078 )
V_122 = V_1078 -> V_576 [ V_1079 ] ;
F_527 ( V_63 , V_1079 , V_122 ) ;
}
}
int F_528 ( struct V_44 * V_63 , T_6 V_122 )
{
struct V_1 * V_2 = F_74 ( V_63 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
bool V_1081 ;
if ( V_122 > V_2 -> V_124 . V_708 . V_709 ||
( V_14 -> V_98 . type == V_99 &&
V_122 < V_712 ) )
return - V_745 ;
V_1081 = ( F_529 ( & V_2 -> V_613 , 32 ) > 1 ) ;
if ( V_122 && V_1081 && V_2 -> V_614 > V_1082 )
return - V_747 ;
if ( F_42 ( V_63 ) )
F_387 ( V_63 ) ;
F_404 ( V_2 ) ;
#ifdef F_325
if ( V_122 ) {
F_530 ( V_63 , V_122 ) ;
F_525 ( V_2 ) ;
V_2 -> V_127 |= V_128 ;
if ( V_2 -> V_14 . V_98 . type == V_99 ) {
V_2 -> V_1083 = V_2 -> V_14 . V_113 . V_724 ;
V_2 -> V_14 . V_113 . V_724 = V_1084 ;
}
} else {
F_531 ( V_63 ) ;
if ( V_2 -> V_14 . V_98 . type == V_99 )
V_2 -> V_14 . V_113 . V_724 = V_2 -> V_1083 ;
V_2 -> V_127 &= ~ V_128 ;
V_2 -> V_723 . V_125 = false ;
V_2 -> V_124 . V_125 = false ;
}
F_524 ( V_2 , V_122 ) ;
#endif
F_398 ( V_2 ) ;
if ( F_42 ( V_63 ) )
return F_385 ( V_63 ) ;
return 0 ;
}
void F_532 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
F_397 () ;
F_528 ( V_45 , F_235 ( V_45 ) ) ;
F_399 () ;
}
void F_533 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_74 ( V_45 ) ;
if ( F_42 ( V_45 ) )
F_337 ( V_2 ) ;
else
F_343 ( V_2 ) ;
}
static T_14 F_534 ( struct V_44 * V_45 ,
T_14 V_185 )
{
struct V_1 * V_2 = F_74 ( V_45 ) ;
if ( ! ( V_185 & V_198 ) )
V_185 &= ~ V_1085 ;
if ( ! ( V_2 -> V_143 & V_693 ) )
V_185 &= ~ V_1085 ;
return V_185 ;
}
static int F_535 ( struct V_44 * V_45 ,
T_14 V_185 )
{
struct V_1 * V_2 = F_74 ( V_45 ) ;
T_14 V_1086 = V_45 -> V_185 ^ V_185 ;
bool V_1087 = false ;
if ( ! ( V_185 & V_1085 ) ) {
if ( V_2 -> V_143 & V_513 )
V_1087 = true ;
V_2 -> V_143 &= ~ V_513 ;
} else if ( ( V_2 -> V_143 & V_693 ) &&
! ( V_2 -> V_143 & V_513 ) ) {
if ( V_2 -> V_389 == 1 ||
V_2 -> V_389 > V_1088 ) {
V_2 -> V_143 |= V_513 ;
V_1087 = true ;
} else if ( ( V_1086 ^ V_185 ) & V_1085 ) {
F_90 ( V_161 , L_137
L_138 ) ;
}
}
switch ( V_185 & V_1089 ) {
case V_1089 :
if ( ! ( V_2 -> V_127 & V_589 ) )
V_1087 = true ;
V_2 -> V_127 &= ~ V_374 ;
V_2 -> V_127 |= V_589 ;
break;
default:
if ( V_2 -> V_127 & V_589 )
V_1087 = true ;
V_2 -> V_127 &= ~ V_589 ;
if ( V_2 -> V_127 & V_419 )
break;
if ( F_235 ( V_45 ) > 1 )
break;
if ( V_2 -> V_424 [ V_425 ] . V_692 <= 1 )
break;
if ( ! V_2 -> V_409 )
break;
V_2 -> V_127 |= V_374 ;
break;
}
if ( V_185 & V_257 )
F_267 ( V_2 ) ;
else
F_266 ( V_2 ) ;
if ( V_1086 & V_280 )
V_1087 = true ;
V_45 -> V_185 = V_185 ;
if ( V_1087 )
F_533 ( V_45 ) ;
return 0 ;
}
static int F_536 ( struct V_1090 * V_1091 , struct V_1092 * V_1093 [] ,
struct V_44 * V_63 ,
const unsigned char * V_546 ,
T_2 V_127 )
{
struct V_1 * V_2 = F_74 ( V_63 ) ;
int V_16 ;
if ( ! ( V_2 -> V_127 & V_419 ) )
return F_537 ( V_1091 , V_1093 , V_63 , V_546 , V_127 ) ;
if ( V_1091 -> V_1094 && ! ( V_1091 -> V_1094 & V_1095 ) ) {
F_36 ( L_139 ,
V_1096 ) ;
return - V_745 ;
}
if ( F_538 ( V_546 ) || F_539 ( V_546 ) ) {
T_1 V_1097 = V_541 ;
if ( F_270 ( V_63 ) < V_1097 )
V_16 = F_540 ( V_63 , V_546 ) ;
else
V_16 = - V_542 ;
} else if ( F_541 ( V_546 ) ) {
V_16 = F_542 ( V_63 , V_546 ) ;
} else {
V_16 = - V_745 ;
}
if ( V_16 == - V_1098 && ! ( V_127 & V_1099 ) )
V_16 = 0 ;
return V_16 ;
}
static int F_543 ( struct V_44 * V_63 ,
struct V_1100 * V_1101 )
{
struct V_1 * V_2 = F_74 ( V_63 ) ;
struct V_1092 * V_1102 , * V_1103 ;
int V_1104 ;
if ( ! ( V_2 -> V_127 & V_419 ) )
return - V_1105 ;
V_1103 = F_544 ( V_1101 , sizeof( struct V_1106 ) , V_1107 ) ;
F_545 (attr, br_spec, rem) {
T_15 V_1108 ;
T_1 V_3 = 0 ;
if ( F_546 ( V_1102 ) != V_1109 )
continue;
V_1108 = F_547 ( V_1102 ) ;
if ( V_1108 == V_1110 ) {
V_3 = 0 ;
V_2 -> V_143 &= ~ V_487 ;
} else if ( V_1108 == V_1111 ) {
V_3 = V_489 ;
V_2 -> V_143 |= V_487 ;
} else
return - V_745 ;
F_56 ( & V_2 -> V_14 , V_488 , V_3 ) ;
F_90 ( V_145 , L_140 ,
V_1108 == V_1110 ? L_141 : L_142 ) ;
}
return 0 ;
}
static int F_548 ( struct V_184 * V_79 , T_1 V_1112 , T_1 V_1113 ,
struct V_44 * V_63 ,
T_1 V_1114 )
{
struct V_1 * V_2 = F_74 ( V_63 ) ;
T_2 V_1108 ;
if ( ! ( V_2 -> V_127 & V_419 ) )
return 0 ;
if ( V_2 -> V_143 & V_487 )
V_1108 = V_1111 ;
else
V_1108 = V_1110 ;
return F_549 ( V_79 , V_1112 , V_1113 , V_63 , V_1108 ) ;
}
static void * F_550 ( struct V_44 * V_9 , struct V_44 * V_607 )
{
struct V_603 * V_1023 = NULL ;
struct V_1 * V_2 = F_74 ( V_9 ) ;
unsigned int V_692 ;
int V_472 , V_16 ;
#ifdef F_551
if ( V_607 -> V_83 != V_607 -> V_67 ) {
F_552 ( V_9 , L_143 ,
V_607 -> V_43 ) ;
return F_553 ( - V_745 ) ;
}
#endif
if ( V_607 -> V_67 > V_750 ||
V_607 -> V_67 == V_1115 ) {
F_552 ( V_9 ,
L_144 ,
V_9 -> V_43 ) ;
return F_553 ( - V_745 ) ;
}
if ( ( ( V_2 -> V_127 & V_128 ) &&
V_2 -> V_614 > V_1082 - 1 ) ||
( V_2 -> V_614 > V_1116 ) )
return F_553 ( - V_747 ) ;
V_1023 = F_554 ( 1 , sizeof( struct V_603 ) , V_740 ) ;
if ( ! V_1023 )
return F_553 ( - V_542 ) ;
V_472 = F_529 ( & V_2 -> V_613 , 32 ) ;
V_2 -> V_614 ++ ;
F_231 ( V_472 , & V_2 -> V_613 ) ;
V_692 = F_555 ( & V_2 -> V_613 , 32 ) ;
V_2 -> V_127 |= V_565 | V_419 ;
V_2 -> V_424 [ V_491 ] . V_692 = V_692 + 1 ;
V_2 -> V_424 [ V_425 ] . V_692 = V_607 -> V_67 ;
V_16 = F_528 ( V_9 , F_235 ( V_9 ) ) ;
if ( V_16 )
goto V_1117;
V_1023 -> V_472 = V_472 ;
V_1023 -> V_136 = V_2 ;
V_16 = F_315 ( V_607 , V_1023 ) ;
if ( V_16 )
goto V_1117;
F_335 ( V_607 ) ;
return V_1023 ;
V_1117:
F_552 ( V_9 ,
L_145 , V_607 -> V_43 ) ;
F_19 ( V_472 , & V_2 -> V_613 ) ;
V_2 -> V_614 -- ;
F_221 ( V_1023 ) ;
return F_553 ( V_16 ) ;
}
static void F_556 ( struct V_44 * V_9 , void * V_1118 )
{
struct V_603 * V_1023 = V_1118 ;
struct V_1 * V_2 = V_1023 -> V_136 ;
unsigned int V_692 ;
F_19 ( V_1023 -> V_472 , & V_2 -> V_613 ) ;
V_2 -> V_614 -- ;
V_692 = F_555 ( & V_2 -> V_613 , 32 ) ;
V_2 -> V_424 [ V_491 ] . V_692 = V_692 + 1 ;
F_313 ( V_1023 -> V_45 , V_1023 ) ;
F_528 ( V_9 , F_235 ( V_9 ) ) ;
F_316 ( V_9 , L_93 ,
V_1023 -> V_472 , V_2 -> V_614 ,
V_1023 -> V_606 ,
V_1023 -> V_606 + V_2 -> V_605 ,
V_2 -> V_613 ) ;
F_221 ( V_1023 ) ;
}
static inline int F_557 ( struct V_1 * V_2 )
{
struct V_617 * V_394 ;
int V_1119 = 0 ;
if ( F_7 ( & V_2 -> V_14 ) ) {
V_1119 = 4 ;
} else {
F_558 (entry, &adapter->pdev->bus_list) {
struct V_5 * V_9 =
F_559 ( V_394 , struct V_5 , V_1120 ) ;
if ( ! V_9 -> V_1121 )
V_1119 ++ ;
}
}
return V_1119 ;
}
int F_560 ( struct V_1 * V_2 , T_2 V_20 ,
T_2 V_1122 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_2 V_1123 = V_2 -> V_1124 & V_1125 ;
int V_1126 = 0 ;
switch ( V_20 ) {
case V_1127 :
switch ( V_1122 ) {
case V_1128 :
if ( V_14 -> V_10 . V_1129 != 0 )
break;
case V_1130 :
case V_1131 :
case V_1132 :
case V_1133 :
case V_1134 :
V_1126 = 1 ;
break;
}
break;
case V_1135 :
switch ( V_1122 ) {
case V_1136 :
V_1126 = 1 ;
break;
}
break;
case V_1137 :
if ( V_1122 != V_1138 )
V_1126 = 1 ;
break;
case V_1139 :
V_1126 = 1 ;
break;
case V_1140 :
case V_1141 :
if ( ( V_1123 == V_1142 ) ||
( ( V_1123 == V_1143 ) &&
( V_14 -> V_10 . V_1129 == 0 ) ) ) {
V_1126 = 1 ;
}
break;
}
return V_1126 ;
}
static int F_561 ( struct V_5 * V_9 , const struct V_1144 * V_1145 )
{
struct V_44 * V_45 ;
struct V_1 * V_2 = NULL ;
struct V_13 * V_14 ;
const struct V_1146 * V_1147 = V_1148 [ V_1145 -> V_1149 ] ;
static int V_1150 ;
int V_38 , V_16 , V_1151 , V_23 ;
unsigned int V_426 = V_1152 ;
T_6 V_1153 [ V_1154 ] ;
#ifdef F_134
T_2 V_1155 ;
#endif
T_1 V_1156 ;
if ( V_9 -> V_1121 ) {
F_562 ( 1 , V_1157 L_146 ,
F_563 ( V_9 ) , V_9 -> V_684 , V_9 -> V_179 ) ;
return - V_745 ;
}
V_16 = F_394 ( V_9 ) ;
if ( V_16 )
return V_16 ;
if ( ! F_564 ( & V_9 -> V_63 , F_229 ( 64 ) ) ) {
V_1151 = 1 ;
} else {
V_16 = F_564 ( & V_9 -> V_63 , F_229 ( 32 ) ) ;
if ( V_16 ) {
F_373 ( & V_9 -> V_63 ,
L_147 ) ;
goto V_1158;
}
V_1151 = 0 ;
}
V_16 = F_565 ( V_9 , F_566 ( V_9 ,
V_1159 ) , V_1096 ) ;
if ( V_16 ) {
F_373 ( & V_9 -> V_63 ,
L_148 , V_16 ) ;
goto V_1160;
}
F_567 ( V_9 ) ;
F_395 ( V_9 ) ;
F_393 ( V_9 ) ;
if ( V_1147 -> V_98 == V_99 ) {
#ifdef F_325
V_426 = 4 * V_712 ;
#else
V_426 = V_691 ;
#endif
}
V_45 = F_568 ( sizeof( struct V_1 ) , V_426 ) ;
if ( ! V_45 ) {
V_16 = - V_542 ;
goto V_1161;
}
F_569 ( V_45 , & V_9 -> V_63 ) ;
V_2 = F_74 ( V_45 ) ;
F_570 ( V_9 , V_2 ) ;
V_2 -> V_45 = V_45 ;
V_2 -> V_9 = V_9 ;
V_14 = & V_2 -> V_14 ;
V_14 -> V_1162 = V_2 ;
V_2 -> V_1163 = F_571 ( V_1164 , V_1165 ) ;
V_14 -> V_407 = F_572 ( F_573 ( V_9 , 0 ) ,
F_574 ( V_9 , 0 ) ) ;
if ( ! V_14 -> V_407 ) {
V_16 = - V_737 ;
goto V_1166;
}
V_45 -> V_1167 = & V_1168 ;
F_575 ( V_45 ) ;
V_45 -> V_1169 = 5 * V_947 ;
strncpy ( V_45 -> V_43 , F_563 ( V_9 ) , sizeof( V_45 -> V_43 ) - 1 ) ;
V_2 -> V_1170 = V_1150 ;
memcpy ( & V_14 -> V_98 . V_347 , V_1147 -> V_1171 , sizeof( V_14 -> V_98 . V_347 ) ) ;
V_14 -> V_98 . type = V_1147 -> V_98 ;
memcpy ( & V_14 -> V_1172 . V_347 , V_1147 -> V_1173 , sizeof( V_14 -> V_1172 . V_347 ) ) ;
V_1156 = F_22 ( V_14 , V_1174 ) ;
if ( ! ( V_1156 & ( 1 << 8 ) ) )
V_14 -> V_1172 . V_347 . V_218 = & V_1175 ;
memcpy ( & V_14 -> V_350 . V_347 , V_1147 -> V_1176 , sizeof( V_14 -> V_350 . V_347 ) ) ;
V_14 -> V_350 . V_933 = V_1177 ;
V_14 -> V_350 . V_1060 . V_1057 = V_1178 ;
V_14 -> V_350 . V_1060 . V_1179 = 0 ;
V_14 -> V_350 . V_1060 . V_1180 = V_1181 | V_1182 ;
V_14 -> V_350 . V_1060 . V_63 = V_45 ;
V_14 -> V_350 . V_1060 . V_1183 = F_507 ;
V_14 -> V_350 . V_1060 . V_1184 = F_508 ;
V_1147 -> V_1185 ( V_14 ) ;
V_16 = F_359 ( V_2 ) ;
if ( V_16 )
goto V_1186;
if ( V_14 -> V_98 . V_347 . V_1187 )
V_14 -> V_1187 = V_14 -> V_98 . V_347 . V_1187 ( V_14 ) ;
switch ( V_2 -> V_14 . V_98 . type ) {
case V_101 :
case V_102 :
F_56 ( & V_2 -> V_14 , V_752 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_127 & V_353 ) {
T_1 V_660 = F_22 ( V_14 , V_661 ) ;
if ( V_660 & V_662 )
F_194 ( V_161 , L_72 ) ;
}
if ( V_1188 )
V_14 -> V_1188 = V_1188 ;
V_14 -> V_350 . V_1189 = true ;
V_16 = V_14 -> V_98 . V_347 . V_1190 ( V_14 ) ;
V_14 -> V_350 . V_1189 = false ;
if ( V_16 == V_668 &&
V_14 -> V_98 . type == V_99 ) {
V_16 = 0 ;
} else if ( V_16 == V_669 ) {
F_344 ( L_149 ) ;
F_344 ( L_150 ) ;
goto V_1186;
} else if ( V_16 ) {
F_344 ( L_151 , V_16 ) ;
goto V_1186;
}
#ifdef F_363
if ( V_2 -> V_14 . V_98 . type == V_99 )
goto V_1191;
F_576 ( V_14 ) ;
memcpy ( & V_14 -> V_1192 . V_347 , V_1147 -> V_1193 , sizeof( V_14 -> V_1192 . V_347 ) ) ;
F_577 ( V_2 ) ;
F_578 ( V_9 , 63 ) ;
V_1191:
#endif
V_45 -> V_185 = V_1194 |
V_1195 |
V_1196 |
V_1197 |
V_257 |
V_1198 |
V_1199 |
V_1200 |
V_186 |
V_198 ;
V_45 -> V_1201 = V_45 -> V_185 | V_1202 ;
switch ( V_2 -> V_14 . V_98 . type ) {
case V_101 :
case V_102 :
V_45 -> V_185 |= V_1203 ;
V_45 -> V_1201 |= V_1203 |
V_1089 ;
break;
default:
break;
}
V_45 -> V_1201 |= V_280 ;
V_45 -> V_1204 |= V_1199 ;
V_45 -> V_1204 |= V_1200 ;
V_45 -> V_1204 |= V_1195 ;
V_45 -> V_1204 |= V_1196 ;
V_45 -> V_1204 |= V_1194 ;
V_45 -> V_1205 |= V_1206 ;
V_45 -> V_1205 |= V_1207 ;
#ifdef F_325
V_45 -> V_1208 = & V_1208 ;
#endif
#ifdef F_134
if ( V_2 -> V_127 & V_699 ) {
unsigned int V_1209 ;
if ( V_14 -> V_98 . V_347 . V_1210 ) {
V_14 -> V_98 . V_347 . V_1210 ( V_14 , & V_1155 ) ;
if ( V_1155 & V_1211 )
V_2 -> V_127 &= ~ V_699 ;
}
V_1209 = F_317 ( int , V_1212 , F_360 () ) ;
V_2 -> V_424 [ V_1029 ] . V_692 = V_1209 ;
V_45 -> V_185 |= V_1047 |
V_1048 ;
V_45 -> V_1204 |= V_1047 |
V_1048 |
V_570 ;
}
#endif
if ( V_1151 ) {
V_45 -> V_185 |= V_1213 ;
V_45 -> V_1204 |= V_1213 ;
}
if ( V_2 -> V_143 & V_693 )
V_45 -> V_1201 |= V_1085 ;
if ( V_2 -> V_143 & V_513 )
V_45 -> V_185 |= V_1085 ;
if ( V_14 -> V_1172 . V_347 . V_1214 ( V_14 , NULL ) < 0 ) {
F_344 ( L_152 ) ;
V_16 = - V_737 ;
goto V_1186;
}
memcpy ( V_45 -> V_616 , V_14 -> V_98 . V_1215 , V_45 -> V_1056 ) ;
if ( ! F_320 ( V_45 -> V_616 ) ) {
F_344 ( L_153 ) ;
V_16 = - V_737 ;
goto V_1186;
}
F_579 ( & V_2 -> V_663 , & F_450 ,
( unsigned long ) V_2 ) ;
F_580 ( & V_2 -> V_35 , F_452 ) ;
F_19 ( V_34 , & V_2 -> V_33 ) ;
V_16 = F_398 ( V_2 ) ;
if ( V_16 )
goto V_1186;
V_2 -> V_756 = 0 ;
V_14 -> V_1172 . V_347 . V_218 ( V_14 , 0x2c , & V_2 -> V_1124 ) ;
V_14 -> V_1216 = F_560 ( V_2 , V_9 -> V_179 ,
V_9 -> V_690 ) ;
if ( V_14 -> V_1216 )
V_2 -> V_756 = V_1217 ;
F_581 ( & V_2 -> V_9 -> V_63 , V_2 -> V_756 ) ;
V_14 -> V_1172 . V_347 . V_218 ( V_14 , 0x2e , & V_2 -> V_1218 ) ;
V_14 -> V_1172 . V_347 . V_218 ( V_14 , 0x2d , & V_2 -> V_1219 ) ;
V_14 -> V_98 . V_347 . V_1220 ( V_14 ) ;
if ( F_7 ( V_14 ) )
F_4 ( V_2 ) ;
switch ( V_14 -> V_98 . type ) {
case V_99 :
V_23 = F_582 ( F_557 ( V_2 ) * 10 , 16 ) ;
break;
default:
V_23 = F_557 ( V_2 ) * 10 ;
break;
}
F_8 ( V_2 , V_23 ) ;
V_16 = F_583 ( V_14 , V_1153 , V_1154 ) ;
if ( V_16 )
strncpy ( V_1153 , L_7 , V_1154 ) ;
if ( F_329 ( V_14 ) && V_14 -> V_350 . V_933 != V_1221 )
F_11 ( L_154 ,
V_14 -> V_98 . type , V_14 -> V_350 . type , V_14 -> V_350 . V_933 ,
V_1153 ) ;
else
F_11 ( L_155 ,
V_14 -> V_98 . type , V_14 -> V_350 . type , V_1153 ) ;
F_11 ( L_156 , V_45 -> V_616 ) ;
V_16 = V_14 -> V_98 . V_347 . V_1222 ( V_14 ) ;
if ( V_16 == V_671 ) {
F_10 ( L_96
L_157
L_158
L_159
L_100
L_101 ) ;
}
strcpy ( V_45 -> V_43 , L_160 ) ;
V_16 = F_584 ( V_45 ) ;
if ( V_16 )
goto V_1223;
if ( V_14 -> V_98 . V_347 . V_679 )
V_14 -> V_98 . V_347 . V_679 ( V_14 ) ;
F_352 ( V_45 ) ;
#ifdef F_212
if ( F_111 ( & V_9 -> V_63 ) == 0 ) {
V_2 -> V_127 |= V_176 ;
F_108 ( V_2 ) ;
}
#endif
if ( V_2 -> V_127 & V_419 ) {
F_90 ( V_161 , L_161 , V_2 -> V_314 ) ;
for ( V_38 = 0 ; V_38 < V_2 -> V_314 ; V_38 ++ )
F_585 ( V_9 , ( V_38 | 0x10000000 ) ) ;
}
if ( V_14 -> V_98 . V_347 . V_1224 )
V_14 -> V_98 . V_347 . V_1224 ( V_14 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_513 ( V_45 ) ;
F_11 ( L_162 , V_1225 ) ;
V_1150 ++ ;
#ifdef F_586
if ( F_587 ( V_2 ) )
F_88 ( V_161 , L_163 ) ;
#endif
F_588 ( V_2 ) ;
if ( V_14 -> V_1187 && V_14 -> V_98 . V_347 . V_643 )
V_14 -> V_98 . V_347 . V_643 ( V_14 ,
V_901 | V_924 ,
true ) ;
return 0 ;
V_1223:
F_55 ( V_2 ) ;
F_404 ( V_2 ) ;
V_1186:
F_589 ( V_2 ) ;
V_2 -> V_143 &= ~ V_637 ;
F_590 ( V_14 -> V_407 ) ;
V_1166:
F_591 ( V_45 ) ;
V_1161:
F_592 ( V_9 ,
F_566 ( V_9 , V_1159 ) ) ;
V_1160:
V_1158:
F_405 ( V_9 ) ;
return V_16 ;
}
static void F_593 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_390 ( V_9 ) ;
struct V_44 * V_45 = V_2 -> V_45 ;
F_594 ( V_2 ) ;
F_231 ( V_32 , & V_2 -> V_33 ) ;
F_595 ( & V_2 -> V_35 ) ;
#ifdef F_212
if ( V_2 -> V_127 & V_176 ) {
V_2 -> V_127 &= ~ V_176 ;
F_112 ( & V_9 -> V_63 ) ;
F_56 ( & V_2 -> V_14 , V_177 , 1 ) ;
}
#endif
#ifdef F_586
F_596 ( V_2 ) ;
#endif
F_515 ( V_45 ) ;
if ( V_45 -> V_934 == V_935 )
F_446 ( V_45 ) ;
#ifdef F_363
if ( V_729 )
F_589 ( V_2 ) ;
#endif
F_404 ( V_2 ) ;
F_55 ( V_2 ) ;
#ifdef F_597
F_221 ( V_2 -> V_126 ) ;
F_221 ( V_2 -> V_575 ) ;
#endif
F_590 ( V_2 -> V_14 . V_407 ) ;
F_592 ( V_9 , F_566 ( V_9 ,
V_1159 ) ) ;
F_11 ( L_164 ) ;
F_591 ( V_45 ) ;
F_598 ( V_9 ) ;
F_405 ( V_9 ) ;
}
static T_16 F_599 ( struct V_5 * V_9 ,
T_17 V_33 )
{
struct V_1 * V_2 = F_390 ( V_9 ) ;
struct V_44 * V_45 = V_2 -> V_45 ;
#ifdef F_363
struct V_5 * V_1226 , * V_1227 ;
T_1 V_1228 , V_1229 , V_1230 , V_1231 ;
int V_936 , V_1232 ;
T_2 V_1233 , V_1234 ;
if ( V_2 -> V_14 . V_98 . type == V_99 ||
V_2 -> V_314 == 0 )
goto V_1235;
V_1226 = V_9 -> V_10 -> V_12 ;
while ( V_1226 && ( F_600 ( V_1226 ) != V_1236 ) )
V_1226 = V_1226 -> V_10 -> V_12 ;
if ( ! V_1226 )
goto V_1235;
V_1232 = F_601 ( V_1226 , V_1237 ) ;
if ( ! V_1232 )
goto V_1235;
F_602 ( V_1226 , V_1232 + V_1238 , & V_1228 ) ;
F_602 ( V_1226 , V_1232 + V_1238 + 4 , & V_1229 ) ;
F_602 ( V_1226 , V_1232 + V_1238 + 8 , & V_1230 ) ;
F_602 ( V_1226 , V_1232 + V_1238 + 12 , & V_1231 ) ;
V_1233 = V_1229 >> 16 ;
if ( ! ( V_1233 & 0x0080 ) )
goto V_1235;
V_1234 = V_1233 & 0x01 ;
if ( ( V_1234 & 1 ) == ( V_9 -> V_1239 & 1 ) ) {
unsigned int V_20 ;
V_936 = ( V_1233 & 0x7F ) >> 1 ;
F_344 ( L_165 , V_936 ) ;
F_344 ( L_166
L_167 ,
V_1228 , V_1229 , V_1230 , V_1231 ) ;
switch ( V_2 -> V_14 . V_98 . type ) {
case V_101 :
V_20 = V_1240 ;
break;
case V_102 :
V_20 = V_1241 ;
break;
default:
V_20 = 0 ;
break;
}
V_1227 = F_603 ( V_1242 , V_20 , NULL ) ;
while ( V_1227 ) {
if ( V_1227 -> V_1239 == ( V_1233 & 0xFF ) )
break;
V_1227 = F_603 ( V_1242 ,
V_20 , V_1227 ) ;
}
if ( V_1227 ) {
F_344 ( L_168 , V_936 ) ;
F_604 ( V_1227 , 0xA8 , 0x00008000 ) ;
F_605 ( V_1227 ) ;
}
F_606 ( V_9 ) ;
}
V_2 -> V_1243 ++ ;
return V_1244 ;
V_1235:
#endif
F_403 ( V_45 ) ;
if ( V_33 == V_1245 )
return V_1246 ;
if ( F_42 ( V_45 ) )
F_340 ( V_2 ) ;
F_405 ( V_9 ) ;
return V_1247 ;
}
static T_16 F_607 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_390 ( V_9 ) ;
T_16 V_1248 ;
int V_16 ;
if ( F_394 ( V_9 ) ) {
F_88 ( V_161 , L_169 ) ;
V_1248 = V_1246 ;
} else {
F_395 ( V_9 ) ;
F_392 ( V_9 ) ;
F_393 ( V_9 ) ;
F_396 ( V_9 , false ) ;
F_343 ( V_2 ) ;
F_56 ( & V_2 -> V_14 , V_752 , ~ 0 ) ;
V_1248 = V_1244 ;
}
V_16 = F_606 ( V_9 ) ;
if ( V_16 ) {
F_344 ( L_170
L_171 , V_16 ) ;
}
return V_1248 ;
}
static void F_608 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_390 ( V_9 ) ;
struct V_44 * V_45 = V_2 -> V_45 ;
#ifdef F_363
if ( V_2 -> V_1243 ) {
F_90 ( V_145 , L_172 ) ;
V_2 -> V_1243 -- ;
return;
}
#endif
if ( F_42 ( V_45 ) )
F_342 ( V_2 ) ;
F_400 ( V_45 ) ;
}
static int T_18 F_609 ( void )
{
int V_142 ;
F_36 ( L_173 , V_1249 , V_1250 ) ;
F_36 ( L_162 , V_1251 ) ;
F_610 () ;
V_142 = F_611 ( & V_1252 ) ;
if ( V_142 ) {
F_612 () ;
return V_142 ;
}
#ifdef F_212
F_613 ( & V_1253 ) ;
#endif
return 0 ;
}
static void T_19 F_614 ( void )
{
#ifdef F_212
F_615 ( & V_1253 ) ;
#endif
F_616 ( & V_1252 ) ;
F_612 () ;
F_617 () ;
}
static int F_618 ( struct V_1254 * V_1255 , unsigned long V_180 ,
void * V_1052 )
{
int V_1256 ;
V_1256 = F_619 ( & V_1252 . V_1257 , NULL , & V_180 ,
F_109 ) ;
return V_1256 ? V_1258 : V_1259 ;
}
