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
! F_13 ( V_34 , & V_2 -> V_33 ) &&
! F_14 ( V_35 , & V_2 -> V_33 ) )
F_15 ( & V_2 -> V_36 ) ;
}
static void F_16 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_37 ;
if ( ! V_14 -> V_38 )
return;
V_14 -> V_38 = NULL ;
F_17 ( L_13 ) ;
F_12 ( V_2 ) ;
}
void F_18 ( struct V_13 * V_14 , T_1 V_3 )
{
T_1 V_4 ;
if ( V_3 == V_39 ) {
F_16 ( V_14 ) ;
return;
}
V_4 = F_19 ( V_14 , V_39 ) ;
if ( V_4 == V_40 )
F_16 ( V_14 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_21 ( ! F_13 ( V_35 , & V_2 -> V_33 ) ) ;
F_22 () ;
F_23 ( V_35 , & V_2 -> V_33 ) ;
}
static void F_24 ( struct V_13 * V_14 , struct V_41 * V_42 )
{
int V_43 = 0 , V_44 = 0 ;
char V_45 [ 16 ] ;
T_1 V_46 [ 64 ] ;
switch ( V_42 -> V_47 ) {
case F_25 ( 0 ) :
for ( V_43 = 0 ; V_43 < 64 ; V_43 ++ )
V_46 [ V_43 ] = F_26 ( V_14 , F_25 ( V_43 ) ) ;
break;
case F_27 ( 0 ) :
for ( V_43 = 0 ; V_43 < 64 ; V_43 ++ )
V_46 [ V_43 ] = F_26 ( V_14 , F_27 ( V_43 ) ) ;
break;
case F_28 ( 0 ) :
for ( V_43 = 0 ; V_43 < 64 ; V_43 ++ )
V_46 [ V_43 ] = F_26 ( V_14 , F_28 ( V_43 ) ) ;
break;
case F_29 ( 0 ) :
for ( V_43 = 0 ; V_43 < 64 ; V_43 ++ )
V_46 [ V_43 ] = F_26 ( V_14 , F_29 ( V_43 ) ) ;
break;
case F_30 ( 0 ) :
for ( V_43 = 0 ; V_43 < 64 ; V_43 ++ )
V_46 [ V_43 ] = F_26 ( V_14 , F_30 ( V_43 ) ) ;
break;
case F_31 ( 0 ) :
for ( V_43 = 0 ; V_43 < 64 ; V_43 ++ )
V_46 [ V_43 ] = F_26 ( V_14 , F_31 ( V_43 ) ) ;
break;
case F_32 ( 0 ) :
for ( V_43 = 0 ; V_43 < 64 ; V_43 ++ )
V_46 [ V_43 ] = F_26 ( V_14 , F_32 ( V_43 ) ) ;
break;
case F_33 ( 0 ) :
for ( V_43 = 0 ; V_43 < 64 ; V_43 ++ )
V_46 [ V_43 ] = F_26 ( V_14 , F_33 ( V_43 ) ) ;
break;
case F_34 ( 0 ) :
for ( V_43 = 0 ; V_43 < 64 ; V_43 ++ )
V_46 [ V_43 ] = F_26 ( V_14 , F_34 ( V_43 ) ) ;
break;
case F_35 ( 0 ) :
for ( V_43 = 0 ; V_43 < 64 ; V_43 ++ )
V_46 [ V_43 ] = F_26 ( V_14 , F_35 ( V_43 ) ) ;
break;
case F_36 ( 0 ) :
for ( V_43 = 0 ; V_43 < 64 ; V_43 ++ )
V_46 [ V_43 ] = F_26 ( V_14 , F_36 ( V_43 ) ) ;
break;
case F_37 ( 0 ) :
for ( V_43 = 0 ; V_43 < 64 ; V_43 ++ )
V_46 [ V_43 ] = F_26 ( V_14 , F_37 ( V_43 ) ) ;
break;
case F_38 ( 0 ) :
for ( V_43 = 0 ; V_43 < 64 ; V_43 ++ )
V_46 [ V_43 ] = F_26 ( V_14 , F_38 ( V_43 ) ) ;
break;
case F_39 ( 0 ) :
for ( V_43 = 0 ; V_43 < 64 ; V_43 ++ )
V_46 [ V_43 ] = F_26 ( V_14 , F_39 ( V_43 ) ) ;
break;
default:
F_40 ( L_14 , V_42 -> V_48 ,
F_26 ( V_14 , V_42 -> V_47 ) ) ;
return;
}
for ( V_43 = 0 ; V_43 < 8 ; V_43 ++ ) {
snprintf ( V_45 , 16 , L_15 , V_42 -> V_48 , V_43 * 8 , V_43 * 8 + 7 ) ;
F_41 ( L_16 , V_45 ) ;
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ )
F_42 ( L_17 , V_46 [ V_43 * 8 + V_44 ] ) ;
F_42 ( L_18 ) ;
}
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = V_2 -> V_50 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_41 * V_42 ;
int V_51 = 0 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
union V_56 * V_57 ;
struct V_58 { T_4 V_59 ; T_4 V_60 ; } * V_61 ;
struct V_52 * V_62 ;
union V_63 * V_64 ;
struct V_65 * V_66 ;
T_1 V_67 ;
int V_43 = 0 ;
if ( ! F_44 ( V_2 ) )
return;
if ( V_50 ) {
F_45 ( & V_2 -> V_9 -> V_68 , L_19 ) ;
F_40 ( L_20
L_21 ) ;
F_40 ( L_22 ,
V_50 -> V_48 ,
V_50 -> V_33 ,
V_50 -> V_69 ,
V_50 -> V_70 ) ;
}
F_45 ( & V_2 -> V_9 -> V_68 , L_23 ) ;
F_40 ( L_24 ) ;
for ( V_42 = (struct V_41 * ) V_71 ;
V_42 -> V_48 ; V_42 ++ ) {
F_24 ( V_14 , V_42 ) ;
}
if ( ! V_50 || ! F_46 ( V_50 ) )
goto exit;
F_45 ( & V_2 -> V_9 -> V_68 , L_25 ) ;
F_40 ( L_26 ,
L_27 ,
L_28 , L_29 , L_30 ) ;
for ( V_51 = 0 ; V_51 < V_2 -> V_72 ; V_51 ++ ) {
V_53 = V_2 -> V_53 [ V_51 ] ;
V_55 = & V_53 -> V_73 [ V_53 -> V_74 ] ;
F_40 ( L_31 ,
V_51 , V_53 -> V_75 , V_53 -> V_74 ,
( T_4 ) F_47 ( V_55 , V_76 ) ,
F_48 ( V_55 , V_77 ) ,
V_55 -> V_78 ,
( T_4 ) V_55 -> V_79 ) ;
}
if ( ! F_49 ( V_2 ) )
goto V_80;
F_45 ( & V_2 -> V_9 -> V_68 , L_32 ) ;
for ( V_51 = 0 ; V_51 < V_2 -> V_72 ; V_51 ++ ) {
V_53 = V_2 -> V_53 [ V_51 ] ;
F_40 ( L_33 ) ;
F_40 ( L_34 , V_53 -> V_81 ) ;
F_40 ( L_33 ) ;
F_40 ( L_35 ,
L_36 ,
L_37 ,
L_28 , L_29 , L_30 , L_38 ) ;
for ( V_43 = 0 ; V_53 -> V_82 && ( V_43 < V_53 -> V_83 ) ; V_43 ++ ) {
V_57 = F_50 ( V_53 , V_43 ) ;
V_55 = & V_53 -> V_73 [ V_43 ] ;
V_61 = (struct V_58 * ) V_57 ;
if ( F_48 ( V_55 , V_77 ) > 0 ) {
F_40 ( L_39 ,
V_43 ,
F_51 ( V_61 -> V_59 ) ,
F_51 ( V_61 -> V_60 ) ,
( T_4 ) F_47 ( V_55 , V_76 ) ,
F_48 ( V_55 , V_77 ) ,
V_55 -> V_78 ,
( T_4 ) V_55 -> V_79 ,
V_55 -> V_84 ) ;
if ( V_43 == V_53 -> V_75 &&
V_43 == V_53 -> V_74 )
F_42 ( L_40 ) ;
else if ( V_43 == V_53 -> V_75 )
F_42 ( L_41 ) ;
else if ( V_43 == V_53 -> V_74 )
F_42 ( L_42 ) ;
else
F_42 ( L_18 ) ;
if ( F_52 ( V_2 ) &&
V_55 -> V_84 )
F_53 ( V_85 , L_43 ,
V_86 , 16 , 1 ,
V_55 -> V_84 -> V_87 ,
F_48 ( V_55 , V_77 ) ,
true ) ;
}
}
}
V_80:
F_45 ( & V_2 -> V_9 -> V_68 , L_44 ) ;
F_40 ( L_45 ) ;
for ( V_51 = 0 ; V_51 < V_2 -> V_88 ; V_51 ++ ) {
V_62 = V_2 -> V_62 [ V_51 ] ;
F_40 ( L_46 ,
V_51 , V_62 -> V_75 , V_62 -> V_74 ) ;
}
if ( ! F_54 ( V_2 ) )
goto exit;
F_45 ( & V_2 -> V_9 -> V_68 , L_47 ) ;
for ( V_51 = 0 ; V_51 < V_2 -> V_88 ; V_51 ++ ) {
V_62 = V_2 -> V_62 [ V_51 ] ;
F_40 ( L_33 ) ;
F_40 ( L_48 , V_62 -> V_81 ) ;
F_40 ( L_33 ) ;
F_40 ( L_49 ,
L_50 ,
L_51 ,
L_52 ) ;
F_40 ( L_49 ,
L_53 ,
L_54 ,
L_55 ) ;
for ( V_43 = 0 ; V_43 < V_62 -> V_83 ; V_43 ++ ) {
V_66 = & V_62 -> V_66 [ V_43 ] ;
V_64 = F_55 ( V_62 , V_43 ) ;
V_61 = (struct V_58 * ) V_64 ;
V_67 = F_56 ( V_64 -> V_89 . V_90 . V_91 ) ;
if ( V_67 & V_92 ) {
F_40 ( L_56
L_57 , V_43 ,
F_51 ( V_61 -> V_59 ) ,
F_51 ( V_61 -> V_60 ) ,
V_66 -> V_84 ) ;
} else {
F_40 ( L_58
L_59 , V_43 ,
F_51 ( V_61 -> V_59 ) ,
F_51 ( V_61 -> V_60 ) ,
( T_4 ) V_66 -> V_76 ,
V_66 -> V_84 ) ;
if ( F_52 ( V_2 ) &&
V_66 -> V_76 ) {
F_53 ( V_85 , L_43 ,
V_86 , 16 , 1 ,
F_57 ( V_66 -> V_93 ) +
V_66 -> V_94 ,
F_58 ( V_62 ) , true ) ;
}
}
if ( V_43 == V_62 -> V_75 )
F_42 ( L_41 ) ;
else if ( V_43 == V_62 -> V_74 )
F_42 ( L_42 ) ;
else
F_42 ( L_18 ) ;
}
}
exit:
return;
}
static void F_59 ( struct V_1 * V_2 )
{
T_1 V_95 ;
V_95 = F_26 ( & V_2 -> V_14 , V_96 ) ;
F_60 ( & V_2 -> V_14 , V_96 ,
V_95 & ~ V_97 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
T_1 V_95 ;
V_95 = F_26 ( & V_2 -> V_14 , V_96 ) ;
F_60 ( & V_2 -> V_14 , V_96 ,
V_95 | V_97 ) ;
}
static void F_62 ( struct V_1 * V_2 , T_5 V_98 ,
T_6 V_99 , T_6 V_100 )
{
T_1 V_101 , V_102 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_103 . type ) {
case V_104 :
V_100 |= V_105 ;
if ( V_98 == - 1 )
V_98 = 0 ;
V_102 = ( ( ( V_98 * 64 ) + V_99 ) >> 2 ) & 0x1F ;
V_101 = F_26 ( V_14 , F_63 ( V_102 ) ) ;
V_101 &= ~ ( 0xFF << ( 8 * ( V_99 & 0x3 ) ) ) ;
V_101 |= ( V_100 << ( 8 * ( V_99 & 0x3 ) ) ) ;
F_60 ( V_14 , F_63 ( V_102 ) , V_101 ) ;
break;
case V_106 :
case V_107 :
if ( V_98 == - 1 ) {
V_100 |= V_105 ;
V_102 = ( ( V_99 & 1 ) * 8 ) ;
V_101 = F_26 ( & V_2 -> V_14 , V_108 ) ;
V_101 &= ~ ( 0xFF << V_102 ) ;
V_101 |= ( V_100 << V_102 ) ;
F_60 ( & V_2 -> V_14 , V_108 , V_101 ) ;
break;
} else {
V_100 |= V_105 ;
V_102 = ( ( 16 * ( V_99 & 1 ) ) + ( 8 * V_98 ) ) ;
V_101 = F_26 ( V_14 , F_63 ( V_99 >> 1 ) ) ;
V_101 &= ~ ( 0xFF << V_102 ) ;
V_101 |= ( V_100 << V_102 ) ;
F_60 ( V_14 , F_63 ( V_99 >> 1 ) , V_101 ) ;
break;
}
default:
break;
}
}
static inline void F_64 ( struct V_1 * V_2 ,
T_4 V_109 )
{
T_1 V_110 ;
switch ( V_2 -> V_14 . V_103 . type ) {
case V_104 :
V_110 = ( V_111 & V_109 ) ;
F_60 ( & V_2 -> V_14 , V_112 , V_110 ) ;
break;
case V_106 :
case V_107 :
V_110 = ( V_109 & 0xFFFFFFFF ) ;
F_60 ( & V_2 -> V_14 , F_65 ( 0 ) , V_110 ) ;
V_110 = ( V_109 >> 32 ) ;
F_60 ( & V_2 -> V_14 , F_65 ( 1 ) , V_110 ) ;
break;
default:
break;
}
}
void F_66 ( struct V_52 * V_113 ,
struct V_54 * V_55 )
{
if ( V_55 -> V_84 ) {
F_67 ( V_55 -> V_84 ) ;
if ( F_48 ( V_55 , V_77 ) )
F_68 ( V_113 -> V_68 ,
F_47 ( V_55 , V_76 ) ,
F_48 ( V_55 , V_77 ) ,
V_114 ) ;
} else if ( F_48 ( V_55 , V_77 ) ) {
F_69 ( V_113 -> V_68 ,
F_47 ( V_55 , V_76 ) ,
F_48 ( V_55 , V_77 ) ,
V_114 ) ;
}
V_55 -> V_78 = NULL ;
V_55 -> V_84 = NULL ;
F_70 ( V_55 , V_77 , 0 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_115 * V_116 = & V_2 -> V_117 ;
int V_43 ;
T_1 V_87 ;
if ( ( V_14 -> V_118 . V_119 != V_120 ) &&
( V_14 -> V_118 . V_119 != V_121 ) )
return;
switch ( V_14 -> V_103 . type ) {
case V_104 :
V_87 = F_26 ( V_14 , V_122 ) ;
break;
default:
V_87 = F_26 ( V_14 , V_123 ) ;
}
V_116 -> V_124 += V_87 ;
if ( ! V_87 )
return;
for ( V_43 = 0 ; V_43 < V_2 -> V_72 ; V_43 ++ )
F_23 ( V_125 ,
& V_2 -> V_53 [ V_43 ] -> V_33 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_115 * V_116 = & V_2 -> V_117 ;
T_1 V_126 [ 8 ] = { 0 } ;
T_6 V_127 ;
int V_43 ;
bool V_128 = V_2 -> V_129 . V_130 ;
if ( V_2 -> V_131 )
V_128 |= ! ! ( V_2 -> V_131 -> V_128 ) ;
if ( ! ( V_2 -> V_132 & V_133 ) || ! V_128 ) {
F_71 ( V_2 ) ;
return;
}
for ( V_43 = 0 ; V_43 < V_134 ; V_43 ++ ) {
T_1 V_135 ;
switch ( V_14 -> V_103 . type ) {
case V_104 :
V_135 = F_26 ( V_14 , F_73 ( V_43 ) ) ;
break;
default:
V_135 = F_26 ( V_14 , F_74 ( V_43 ) ) ;
}
V_116 -> V_135 [ V_43 ] += V_135 ;
V_127 = F_75 ( V_2 -> V_50 , V_43 ) ;
V_126 [ V_127 ] += V_135 ;
}
for ( V_43 = 0 ; V_43 < V_2 -> V_72 ; V_43 ++ ) {
struct V_52 * V_53 = V_2 -> V_53 [ V_43 ] ;
V_127 = V_53 -> V_136 ;
if ( V_126 [ V_127 ] )
F_23 ( V_125 , & V_53 -> V_33 ) ;
}
}
static T_4 F_76 ( struct V_52 * V_113 )
{
return V_113 -> V_117 . V_137 ;
}
static T_4 F_77 ( struct V_52 * V_113 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 ;
T_1 V_138 , V_139 ;
if ( V_113 -> V_140 )
V_2 = V_113 -> V_140 -> V_141 ;
else
V_2 = F_78 ( V_113 -> V_50 ) ;
V_14 = & V_2 -> V_14 ;
V_138 = F_26 ( V_14 , F_37 ( V_113 -> V_142 ) ) ;
V_139 = F_26 ( V_14 , F_38 ( V_113 -> V_142 ) ) ;
if ( V_138 != V_139 )
return ( V_138 < V_139 ) ?
V_139 - V_138 : ( V_139 + V_113 -> V_83 - V_138 ) ;
return 0 ;
}
static inline bool F_79 ( struct V_52 * V_53 )
{
T_1 V_143 = F_76 ( V_53 ) ;
T_1 V_144 = V_53 -> V_145 . V_144 ;
T_1 V_146 = F_77 ( V_53 ) ;
bool V_147 = false ;
F_80 ( V_53 ) ;
if ( ( V_144 == V_143 ) && V_146 ) {
V_147 = F_14 ( V_125 ,
& V_53 -> V_33 ) ;
} else {
V_53 -> V_145 . V_144 = V_143 ;
F_23 ( V_125 , & V_53 -> V_33 ) ;
}
return V_147 ;
}
static void F_81 ( struct V_1 * V_2 )
{
if ( ! F_13 ( V_32 , & V_2 -> V_33 ) ) {
V_2 -> V_148 |= V_149 ;
F_82 ( V_150 , L_60 ) ;
F_12 ( V_2 ) ;
}
}
static bool F_83 ( struct V_151 * V_152 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 = V_152 -> V_2 ;
struct V_54 * V_55 ;
union V_56 * V_57 ;
unsigned int V_153 = 0 , V_154 = 0 ;
unsigned int V_155 = V_152 -> V_156 . V_157 ;
unsigned int V_43 = V_53 -> V_74 ;
if ( F_13 ( V_32 , & V_2 -> V_33 ) )
return true ;
V_55 = & V_53 -> V_73 [ V_43 ] ;
V_57 = F_50 ( V_53 , V_43 ) ;
V_43 -= V_53 -> V_83 ;
do {
union V_56 * V_158 = V_55 -> V_78 ;
if ( ! V_158 )
break;
F_84 () ;
if ( ! ( V_158 -> V_89 . V_159 & F_85 ( V_160 ) ) )
break;
V_55 -> V_78 = NULL ;
V_153 += V_55 -> V_161 ;
V_154 += V_55 -> V_162 ;
F_67 ( V_55 -> V_84 ) ;
F_68 ( V_53 -> V_68 ,
F_47 ( V_55 , V_76 ) ,
F_48 ( V_55 , V_77 ) ,
V_114 ) ;
V_55 -> V_84 = NULL ;
F_70 ( V_55 , V_77 , 0 ) ;
while ( V_57 != V_158 ) {
V_55 ++ ;
V_57 ++ ;
V_43 ++ ;
if ( F_86 ( ! V_43 ) ) {
V_43 -= V_53 -> V_83 ;
V_55 = V_53 -> V_73 ;
V_57 = F_50 ( V_53 , 0 ) ;
}
if ( F_48 ( V_55 , V_77 ) ) {
F_69 ( V_53 -> V_68 ,
F_47 ( V_55 , V_76 ) ,
F_48 ( V_55 , V_77 ) ,
V_114 ) ;
F_70 ( V_55 , V_77 , 0 ) ;
}
}
V_55 ++ ;
V_57 ++ ;
V_43 ++ ;
if ( F_86 ( ! V_43 ) ) {
V_43 -= V_53 -> V_83 ;
V_55 = V_53 -> V_73 ;
V_57 = F_50 ( V_53 , 0 ) ;
}
F_87 ( V_57 ) ;
V_155 -- ;
} while ( F_88 ( V_155 ) );
V_43 += V_53 -> V_83 ;
V_53 -> V_74 = V_43 ;
F_89 ( & V_53 -> V_163 ) ;
V_53 -> V_117 . V_164 += V_153 ;
V_53 -> V_117 . V_137 += V_154 ;
F_90 ( & V_53 -> V_163 ) ;
V_152 -> V_156 . V_153 += V_153 ;
V_152 -> V_156 . V_154 += V_154 ;
if ( F_91 ( V_53 ) && F_79 ( V_53 ) ) {
struct V_13 * V_14 = & V_2 -> V_14 ;
F_92 ( V_150 , L_61
L_62
L_63
L_64
L_65
L_66
L_67
L_68 ,
V_53 -> V_81 ,
F_26 ( V_14 , F_37 ( V_53 -> V_142 ) ) ,
F_26 ( V_14 , F_38 ( V_53 -> V_142 ) ) ,
V_53 -> V_75 , V_43 ,
V_53 -> V_73 [ V_43 ] . V_79 , V_165 ) ;
F_93 ( V_53 -> V_50 , V_53 -> V_81 ) ;
F_94 ( V_166 ,
L_69 ,
V_2 -> V_167 + 1 , V_53 -> V_81 ) ;
F_81 ( V_2 ) ;
return true ;
}
F_95 ( F_96 ( V_53 ) ,
V_154 , V_153 ) ;
#define F_97 (DESC_NEEDED * 2)
if ( F_86 ( V_154 && F_98 ( V_53 -> V_50 ) &&
( F_99 ( V_53 ) >= F_97 ) ) ) {
F_100 () ;
if ( F_101 ( V_53 -> V_50 ,
V_53 -> V_81 )
&& ! F_13 ( V_32 , & V_2 -> V_33 ) ) {
F_102 ( V_53 -> V_50 ,
V_53 -> V_81 ) ;
++ V_53 -> V_145 . V_168 ;
}
}
return ! ! V_155 ;
}
static void F_103 ( struct V_1 * V_2 ,
struct V_52 * V_53 ,
int V_169 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_170 = F_104 ( V_53 -> V_68 , V_169 ) ;
T_2 V_171 ;
switch ( V_14 -> V_103 . type ) {
case V_104 :
V_171 = F_105 ( V_53 -> V_142 ) ;
break;
case V_106 :
case V_107 :
V_171 = F_106 ( V_53 -> V_142 ) ;
V_170 <<= V_172 ;
break;
default:
return;
}
V_170 |= V_173 |
V_174 |
V_175 ;
F_60 ( V_14 , V_171 , V_170 ) ;
}
static void F_107 ( struct V_1 * V_2 ,
struct V_52 * V_62 ,
int V_169 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_176 = F_104 ( V_62 -> V_68 , V_169 ) ;
T_6 V_142 = V_62 -> V_142 ;
switch ( V_14 -> V_103 . type ) {
case V_106 :
case V_107 :
V_176 <<= V_177 ;
break;
default:
break;
}
V_176 |= V_178 |
V_179 ;
F_60 ( V_14 , F_27 ( V_142 ) , V_176 ) ;
}
static void F_108 ( struct V_151 * V_152 )
{
struct V_1 * V_2 = V_152 -> V_2 ;
struct V_52 * V_113 ;
int V_169 = F_109 () ;
if ( V_152 -> V_169 == V_169 )
goto V_180;
F_110 (ring, q_vector->tx)
F_103 ( V_2 , V_113 , V_169 ) ;
F_110 (ring, q_vector->rx)
F_107 ( V_2 , V_113 , V_169 ) ;
V_152 -> V_169 = V_169 ;
V_180:
F_111 () ;
}
static void F_112 ( struct V_1 * V_2 )
{
int V_43 ;
if ( ! ( V_2 -> V_132 & V_181 ) )
return;
F_60 ( & V_2 -> V_14 , V_182 , 2 ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_183 ; V_43 ++ ) {
V_2 -> V_152 [ V_43 ] -> V_169 = - 1 ;
F_108 ( V_2 -> V_152 [ V_43 ] ) ;
}
}
static int F_113 ( struct V_184 * V_68 , void * V_87 )
{
struct V_1 * V_2 = F_114 ( V_68 ) ;
unsigned long V_185 = * ( unsigned long * ) V_87 ;
if ( ! ( V_2 -> V_132 & V_186 ) )
return 0 ;
switch ( V_185 ) {
case V_187 :
if ( V_2 -> V_132 & V_181 )
break;
if ( F_115 ( V_68 ) == 0 ) {
V_2 -> V_132 |= V_181 ;
F_112 ( V_2 ) ;
break;
}
case V_188 :
if ( V_2 -> V_132 & V_181 ) {
F_116 ( V_68 ) ;
V_2 -> V_132 &= ~ V_181 ;
F_60 ( & V_2 -> V_14 , V_182 , 1 ) ;
}
break;
}
return 0 ;
}
static inline void F_117 ( struct V_52 * V_113 ,
union V_63 * V_64 ,
struct V_189 * V_84 )
{
if ( V_113 -> V_50 -> V_190 & V_191 )
V_84 -> V_192 = F_56 ( V_64 -> V_89 . V_193 . V_194 . V_195 ) ;
}
static inline bool F_118 ( struct V_52 * V_113 ,
union V_63 * V_64 )
{
T_7 V_196 = V_64 -> V_89 . V_193 . V_197 . V_198 . V_196 ;
return F_13 ( V_199 , & V_113 -> V_33 ) &&
( ( V_196 & F_119 ( V_200 ) ) ==
( F_119 ( V_201 <<
V_202 ) ) ) ;
}
static inline void F_120 ( struct V_52 * V_113 ,
union V_63 * V_64 ,
struct V_189 * V_84 )
{
F_121 ( V_84 ) ;
if ( ! ( V_113 -> V_50 -> V_190 & V_203 ) )
return;
if ( F_122 ( V_64 , V_204 ) &&
F_122 ( V_64 , V_205 ) ) {
V_113 -> V_206 . V_207 ++ ;
return;
}
if ( ! F_122 ( V_64 , V_208 ) )
return;
if ( F_122 ( V_64 , V_209 ) ) {
T_7 V_196 = V_64 -> V_89 . V_193 . V_197 . V_198 . V_196 ;
if ( ( V_196 & F_119 ( V_210 ) ) &&
F_13 ( V_211 , & V_113 -> V_33 ) )
return;
V_113 -> V_206 . V_207 ++ ;
return;
}
V_84 -> V_212 = V_213 ;
}
static inline void F_123 ( struct V_52 * V_62 , T_1 V_214 )
{
V_62 -> V_75 = V_214 ;
V_62 -> V_215 = V_214 ;
F_124 () ;
F_125 ( V_62 , V_214 ) ;
}
static bool F_126 ( struct V_52 * V_62 ,
struct V_65 * V_216 )
{
struct V_93 * V_93 = V_216 -> V_93 ;
T_8 V_76 = V_216 -> V_76 ;
if ( F_88 ( V_76 ) )
return true ;
if ( F_88 ( ! V_93 ) ) {
V_93 = F_127 ( V_217 | V_218 | V_219 ,
V_216 -> V_84 , F_128 ( V_62 ) ) ;
if ( F_86 ( ! V_93 ) ) {
V_62 -> V_206 . V_220 ++ ;
return false ;
}
V_216 -> V_93 = V_93 ;
}
V_76 = F_129 ( V_62 -> V_68 , V_93 , 0 ,
F_130 ( V_62 ) , V_221 ) ;
if ( F_131 ( V_62 -> V_68 , V_76 ) ) {
F_132 ( V_93 , F_128 ( V_62 ) ) ;
V_216 -> V_93 = NULL ;
V_62 -> V_206 . V_220 ++ ;
return false ;
}
V_216 -> V_76 = V_76 ;
V_216 -> V_94 = 0 ;
return true ;
}
void F_133 ( struct V_52 * V_62 , T_2 V_222 )
{
union V_63 * V_64 ;
struct V_65 * V_216 ;
T_2 V_43 = V_62 -> V_75 ;
if ( ! V_222 )
return;
V_64 = F_55 ( V_62 , V_43 ) ;
V_216 = & V_62 -> V_66 [ V_43 ] ;
V_43 -= V_62 -> V_83 ;
do {
if ( ! F_126 ( V_62 , V_216 ) )
break;
V_64 -> V_223 . V_224 = F_134 ( V_216 -> V_76 + V_216 -> V_94 ) ;
V_64 ++ ;
V_216 ++ ;
V_43 ++ ;
if ( F_86 ( ! V_43 ) ) {
V_64 = F_55 ( V_62 , 0 ) ;
V_216 = V_62 -> V_66 ;
V_43 -= V_62 -> V_83 ;
}
V_64 -> V_223 . V_225 = 0 ;
V_222 -- ;
} while ( V_222 );
V_43 += V_62 -> V_83 ;
if ( V_62 -> V_75 != V_43 )
F_123 ( V_62 , V_43 ) ;
}
static unsigned int F_135 ( unsigned char * V_87 ,
unsigned int V_226 )
{
union {
unsigned char * V_227 ;
struct V_228 * V_229 ;
struct V_230 * V_231 ;
struct V_232 * V_233 ;
struct V_234 * V_235 ;
} V_236 ;
T_9 V_237 ;
T_6 V_238 = 0 ;
T_6 V_239 ;
if ( V_226 < V_240 )
return V_226 ;
V_236 . V_227 = V_87 ;
V_237 = V_236 . V_229 -> V_241 ;
V_236 . V_227 += V_240 ;
if ( V_237 == F_136 ( V_242 ) ) {
if ( ( V_236 . V_227 - V_87 ) > ( V_226 - V_243 ) )
return V_226 ;
V_237 = V_236 . V_231 -> V_244 ;
V_236 . V_227 += V_243 ;
}
if ( V_237 == F_136 ( V_245 ) ) {
if ( ( V_236 . V_227 - V_87 ) > ( V_226 - sizeof( struct V_232 ) ) )
return V_226 ;
V_239 = ( V_236 . V_227 [ 0 ] & 0x0F ) << 2 ;
if ( V_239 < sizeof( struct V_232 ) )
return V_236 . V_227 - V_87 ;
if ( ! ( V_236 . V_233 -> V_246 & F_137 ( V_247 ) ) )
V_238 = V_236 . V_233 -> V_237 ;
} else if ( V_237 == F_136 ( V_248 ) ) {
if ( ( V_236 . V_227 - V_87 ) > ( V_226 - sizeof( struct V_234 ) ) )
return V_226 ;
V_238 = V_236 . V_235 -> V_238 ;
V_239 = sizeof( struct V_234 ) ;
#ifdef F_138
} else if ( V_237 == F_136 ( V_249 ) ) {
if ( ( V_236 . V_227 - V_87 ) > ( V_226 - V_250 ) )
return V_226 ;
V_239 = V_250 ;
#endif
} else {
return V_236 . V_227 - V_87 ;
}
V_236 . V_227 += V_239 ;
if ( V_238 == V_251 ) {
if ( ( V_236 . V_227 - V_87 ) > ( V_226 - sizeof( struct V_252 ) ) )
return V_226 ;
V_239 = ( V_236 . V_227 [ 12 ] & 0xF0 ) >> 2 ;
if ( V_239 < sizeof( struct V_252 ) )
return V_236 . V_227 - V_87 ;
V_236 . V_227 += V_239 ;
} else if ( V_238 == V_253 ) {
if ( ( V_236 . V_227 - V_87 ) > ( V_226 - sizeof( struct V_254 ) ) )
return V_226 ;
V_236 . V_227 += sizeof( struct V_254 ) ;
}
if ( ( V_236 . V_227 - V_87 ) < V_226 )
return V_236 . V_227 - V_87 ;
else
return V_226 ;
}
static void F_139 ( struct V_52 * V_113 ,
struct V_189 * V_84 )
{
T_2 V_255 = F_140 ( V_84 ) ;
F_141 ( V_84 ) -> V_256 = F_142 ( ( V_84 -> V_77 - V_255 ) ,
F_143 ( V_84 ) -> V_257 ) ;
F_141 ( V_84 ) -> V_258 = V_259 ;
}
static void F_144 ( struct V_52 * V_62 ,
struct V_189 * V_84 )
{
if ( ! F_143 ( V_84 ) -> V_257 )
return;
V_62 -> V_206 . V_260 += F_143 ( V_84 ) -> V_257 ;
V_62 -> V_206 . V_261 ++ ;
F_139 ( V_62 , V_84 ) ;
F_143 ( V_84 ) -> V_257 = 0 ;
}
static void F_145 ( struct V_52 * V_62 ,
union V_63 * V_64 ,
struct V_189 * V_84 )
{
struct V_49 * V_68 = V_62 -> V_50 ;
F_144 ( V_62 , V_84 ) ;
F_117 ( V_62 , V_64 , V_84 ) ;
F_120 ( V_62 , V_64 , V_84 ) ;
F_146 ( V_62 , V_64 , V_84 ) ;
if ( ( V_68 -> V_190 & V_262 ) &&
F_122 ( V_64 , V_263 ) ) {
T_2 V_264 = F_147 ( V_64 -> V_89 . V_90 . V_231 ) ;
F_148 ( V_84 , F_137 ( V_242 ) , V_264 ) ;
}
F_149 ( V_84 , V_62 -> V_81 ) ;
V_84 -> V_237 = F_150 ( V_84 , V_68 ) ;
}
static void F_151 ( struct V_151 * V_152 ,
struct V_189 * V_84 )
{
struct V_1 * V_2 = V_152 -> V_2 ;
if ( F_152 ( V_152 ) )
F_153 ( V_84 ) ;
else if ( ! ( V_2 -> V_132 & V_265 ) )
F_154 ( & V_152 -> V_266 , V_84 ) ;
else
F_155 ( V_84 ) ;
}
static bool F_156 ( struct V_52 * V_62 ,
union V_63 * V_64 ,
struct V_189 * V_84 )
{
T_1 V_267 = V_62 -> V_74 + 1 ;
V_267 = ( V_267 < V_62 -> V_83 ) ? V_267 : 0 ;
V_62 -> V_74 = V_267 ;
F_87 ( F_55 ( V_62 , V_267 ) ) ;
if ( F_157 ( V_62 ) ) {
T_10 V_268 = V_64 -> V_89 . V_193 . V_197 . V_87 &
F_85 ( V_269 ) ;
if ( F_86 ( V_268 ) ) {
T_1 V_270 = F_56 ( V_268 ) ;
V_270 >>= V_271 ;
F_143 ( V_84 ) -> V_257 += V_270 - 1 ;
V_267 = F_56 ( V_64 -> V_89 . V_90 . V_91 ) ;
V_267 &= V_272 ;
V_267 >>= V_273 ;
}
}
if ( F_88 ( F_122 ( V_64 , V_274 ) ) )
return false ;
V_62 -> V_66 [ V_267 ] . V_84 = V_84 ;
V_62 -> V_206 . V_275 ++ ;
return true ;
}
static void F_158 ( struct V_52 * V_62 ,
struct V_189 * V_84 )
{
struct V_276 * V_277 = & F_141 ( V_84 ) -> V_278 [ 0 ] ;
unsigned char * V_279 ;
unsigned int V_280 ;
V_279 = F_159 ( V_277 ) ;
V_280 = F_135 ( V_279 , V_281 ) ;
F_160 ( V_84 , V_279 , F_161 ( V_280 , sizeof( long ) ) ) ;
F_162 ( V_277 , V_280 ) ;
V_277 -> V_94 += V_280 ;
V_84 -> V_282 -= V_280 ;
V_84 -> V_139 += V_280 ;
}
static void F_163 ( struct V_52 * V_62 ,
struct V_189 * V_84 )
{
if ( F_86 ( F_143 ( V_84 ) -> V_283 ) ) {
F_69 ( V_62 -> V_68 , F_143 ( V_84 ) -> V_76 ,
F_130 ( V_62 ) , V_221 ) ;
F_143 ( V_84 ) -> V_283 = false ;
} else {
struct V_276 * V_277 = & F_141 ( V_84 ) -> V_278 [ 0 ] ;
F_164 ( V_62 -> V_68 ,
F_143 ( V_84 ) -> V_76 ,
V_277 -> V_94 ,
F_58 ( V_62 ) ,
V_221 ) ;
}
F_143 ( V_84 ) -> V_76 = 0 ;
}
static bool F_165 ( struct V_52 * V_62 ,
union V_63 * V_64 ,
struct V_189 * V_84 )
{
struct V_49 * V_50 = V_62 -> V_50 ;
if ( F_86 ( F_122 ( V_64 ,
V_284 ) &&
! ( V_50 -> V_190 & V_285 ) ) ) {
F_67 ( V_84 ) ;
return true ;
}
if ( F_166 ( V_84 ) )
F_158 ( V_62 , V_84 ) ;
#ifdef F_138
if ( F_118 ( V_62 , V_64 ) )
return false ;
#endif
if ( F_86 ( V_84 -> V_77 < 60 ) ) {
int V_286 = 60 - V_84 -> V_77 ;
if ( F_167 ( V_84 , V_286 ) )
return true ;
F_168 ( V_84 , V_286 ) ;
}
return false ;
}
static void F_169 ( struct V_52 * V_62 ,
struct V_65 * V_287 )
{
struct V_65 * V_288 ;
T_2 V_289 = V_62 -> V_215 ;
V_288 = & V_62 -> V_66 [ V_289 ] ;
V_289 ++ ;
V_62 -> V_215 = ( V_289 < V_62 -> V_83 ) ? V_289 : 0 ;
V_288 -> V_93 = V_287 -> V_93 ;
V_288 -> V_76 = V_287 -> V_76 ;
V_288 -> V_94 = V_287 -> V_94 ;
F_170 ( V_62 -> V_68 , V_288 -> V_76 ,
V_288 -> V_94 ,
F_58 ( V_62 ) ,
V_221 ) ;
}
static bool F_171 ( struct V_52 * V_62 ,
struct V_65 * V_290 ,
union V_63 * V_64 ,
struct V_189 * V_84 )
{
struct V_93 * V_93 = V_290 -> V_93 ;
unsigned int V_291 = F_147 ( V_64 -> V_89 . V_90 . V_292 ) ;
#if ( V_293 < 8192 )
unsigned int V_294 = F_58 ( V_62 ) ;
#else
unsigned int V_294 = F_161 ( V_291 , V_295 ) ;
unsigned int V_296 = F_130 ( V_62 ) -
F_58 ( V_62 ) ;
#endif
if ( ( V_291 <= V_281 ) && ! F_166 ( V_84 ) ) {
unsigned char * V_279 = F_57 ( V_93 ) + V_290 -> V_94 ;
memcpy ( F_168 ( V_84 , V_291 ) , V_279 , F_161 ( V_291 , sizeof( long ) ) ) ;
if ( F_88 ( F_172 ( V_93 ) == F_173 () ) )
return true ;
F_174 ( V_93 ) ;
return false ;
}
F_175 ( V_84 , F_141 ( V_84 ) -> V_297 , V_93 ,
V_290 -> V_94 , V_291 , V_294 ) ;
if ( F_86 ( F_172 ( V_93 ) != F_173 () ) )
return false ;
#if ( V_293 < 8192 )
if ( F_86 ( F_176 ( V_93 ) != 1 ) )
return false ;
V_290 -> V_94 ^= V_294 ;
F_177 ( & V_93 -> V_298 , 2 ) ;
#else
V_290 -> V_94 += V_294 ;
if ( V_290 -> V_94 > V_296 )
return false ;
F_178 ( V_93 ) ;
#endif
return true ;
}
static struct V_189 * F_179 ( struct V_52 * V_62 ,
union V_63 * V_64 )
{
struct V_65 * V_290 ;
struct V_189 * V_84 ;
struct V_93 * V_93 ;
V_290 = & V_62 -> V_66 [ V_62 -> V_74 ] ;
V_93 = V_290 -> V_93 ;
F_180 ( V_93 ) ;
V_84 = V_290 -> V_84 ;
if ( F_88 ( ! V_84 ) ) {
void * V_299 = F_57 ( V_93 ) +
V_290 -> V_94 ;
F_87 ( V_299 ) ;
#if V_295 < 128
F_87 ( V_299 + V_295 ) ;
#endif
V_84 = F_181 ( V_62 -> V_50 ,
V_281 ) ;
if ( F_86 ( ! V_84 ) ) {
V_62 -> V_206 . V_300 ++ ;
return NULL ;
}
F_180 ( V_84 -> V_87 ) ;
if ( F_88 ( F_122 ( V_64 , V_274 ) ) )
goto V_301;
F_143 ( V_84 ) -> V_76 = V_290 -> V_76 ;
} else {
if ( F_122 ( V_64 , V_274 ) )
F_163 ( V_62 , V_84 ) ;
V_301:
F_164 ( V_62 -> V_68 ,
V_290 -> V_76 ,
V_290 -> V_94 ,
F_58 ( V_62 ) ,
V_221 ) ;
}
if ( F_171 ( V_62 , V_290 , V_64 , V_84 ) ) {
F_169 ( V_62 , V_290 ) ;
} else if ( F_143 ( V_84 ) -> V_76 == V_290 -> V_76 ) {
F_143 ( V_84 ) -> V_283 = true ;
} else {
F_69 ( V_62 -> V_68 , V_290 -> V_76 ,
F_130 ( V_62 ) ,
V_221 ) ;
}
V_290 -> V_84 = NULL ;
V_290 -> V_76 = 0 ;
V_290 -> V_93 = NULL ;
return V_84 ;
}
static int F_182 ( struct V_151 * V_152 ,
struct V_52 * V_62 ,
const int V_155 )
{
unsigned int V_302 = 0 , V_303 = 0 ;
#ifdef F_138
struct V_1 * V_2 = V_152 -> V_2 ;
int V_304 ;
unsigned int V_305 = 0 ;
#endif
T_2 V_222 = F_99 ( V_62 ) ;
do {
union V_63 * V_64 ;
struct V_189 * V_84 ;
if ( V_222 >= V_306 ) {
F_133 ( V_62 , V_222 ) ;
V_222 = 0 ;
}
V_64 = F_55 ( V_62 , V_62 -> V_74 ) ;
if ( ! F_122 ( V_64 , V_92 ) )
break;
F_183 () ;
V_84 = F_179 ( V_62 , V_64 ) ;
if ( ! V_84 )
break;
V_222 ++ ;
if ( F_156 ( V_62 , V_64 , V_84 ) )
continue;
if ( F_165 ( V_62 , V_64 , V_84 ) )
continue;
V_302 += V_84 -> V_77 ;
F_145 ( V_62 , V_64 , V_84 ) ;
#ifdef F_138
if ( F_118 ( V_62 , V_64 ) ) {
V_304 = F_184 ( V_2 , V_64 , V_84 ) ;
if ( V_304 > 0 ) {
if ( ! V_305 ) {
V_305 = V_62 -> V_50 -> V_307 -
sizeof( struct V_308 ) -
sizeof( struct V_309 ) -
sizeof( struct V_310 ) ;
if ( V_305 > 512 )
V_305 &= ~ 511 ;
}
V_302 += V_304 ;
V_303 += F_142 ( V_304 ,
V_305 ) ;
}
if ( ! V_304 ) {
F_67 ( V_84 ) ;
continue;
}
}
#endif
F_185 ( V_84 , & V_152 -> V_266 ) ;
F_151 ( V_152 , V_84 ) ;
V_303 ++ ;
} while ( F_88 ( V_303 < V_155 ) );
F_89 ( & V_62 -> V_163 ) ;
V_62 -> V_117 . V_137 += V_303 ;
V_62 -> V_117 . V_164 += V_302 ;
F_90 ( & V_62 -> V_163 ) ;
V_152 -> V_311 . V_154 += V_303 ;
V_152 -> V_311 . V_153 += V_302 ;
if ( V_222 )
F_133 ( V_62 , V_222 ) ;
return V_303 ;
}
static int F_186 ( struct V_312 * V_266 )
{
struct V_151 * V_152 =
F_187 ( V_266 , struct V_151 , V_266 ) ;
struct V_1 * V_2 = V_152 -> V_2 ;
struct V_52 * V_113 ;
int V_313 = 0 ;
if ( F_13 ( V_32 , & V_2 -> V_33 ) )
return V_314 ;
if ( ! F_188 ( V_152 ) )
return V_315 ;
F_110 (ring, q_vector->rx) {
V_313 = F_182 ( V_152 , V_113 , 4 ) ;
#ifdef F_189
if ( V_313 )
V_113 -> V_117 . V_316 += V_313 ;
else
V_113 -> V_117 . V_317 ++ ;
#endif
if ( V_313 )
break;
}
F_190 ( V_152 ) ;
return V_313 ;
}
static void F_191 ( struct V_1 * V_2 )
{
struct V_151 * V_152 ;
int V_318 ;
T_1 V_110 ;
if ( V_2 -> V_319 > 32 ) {
T_1 V_320 = ( 1 << ( V_2 -> V_319 - 32 ) ) - 1 ;
F_60 ( & V_2 -> V_14 , V_321 , V_320 ) ;
}
for ( V_318 = 0 ; V_318 < V_2 -> V_183 ; V_318 ++ ) {
struct V_52 * V_113 ;
V_152 = V_2 -> V_152 [ V_318 ] ;
F_110 (ring, q_vector->rx)
F_62 ( V_2 , 0 , V_113 -> V_142 , V_318 ) ;
F_110 (ring, q_vector->tx)
F_62 ( V_2 , 1 , V_113 -> V_142 , V_318 ) ;
F_192 ( V_152 ) ;
}
switch ( V_2 -> V_14 . V_103 . type ) {
case V_104 :
F_62 ( V_2 , - 1 , V_322 ,
V_318 ) ;
break;
case V_106 :
case V_107 :
F_62 ( V_2 , - 1 , 1 , V_318 ) ;
break;
default:
break;
}
F_60 ( & V_2 -> V_14 , F_193 ( V_318 ) , 1950 ) ;
V_110 = V_323 ;
V_110 &= ~ ( V_324 |
V_325 |
V_326 ) ;
F_60 ( & V_2 -> V_14 , V_327 , V_110 ) ;
}
static void F_194 ( struct V_151 * V_152 ,
struct V_328 * V_329 )
{
int V_164 = V_329 -> V_153 ;
int V_137 = V_329 -> V_154 ;
T_1 V_330 ;
T_4 V_331 ;
T_6 V_332 = V_329 -> V_333 ;
if ( V_137 == 0 )
return;
V_330 = V_152 -> V_333 >> 2 ;
if ( V_330 == 0 )
return;
V_331 = V_164 / V_330 ;
switch ( V_332 ) {
case V_334 :
if ( V_331 > 10 )
V_332 = V_335 ;
break;
case V_335 :
if ( V_331 > 20 )
V_332 = V_336 ;
else if ( V_331 <= 10 )
V_332 = V_334 ;
break;
case V_336 :
if ( V_331 <= 20 )
V_332 = V_335 ;
break;
}
V_329 -> V_153 = 0 ;
V_329 -> V_154 = 0 ;
V_329 -> V_333 = V_332 ;
}
void F_192 ( struct V_151 * V_152 )
{
struct V_1 * V_2 = V_152 -> V_2 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_318 = V_152 -> V_318 ;
T_1 V_337 = V_152 -> V_333 & V_338 ;
switch ( V_2 -> V_14 . V_103 . type ) {
case V_104 :
V_337 |= ( V_337 << 16 ) ;
break;
case V_106 :
case V_107 :
V_337 |= V_339 ;
break;
default:
break;
}
F_60 ( V_14 , F_193 ( V_318 ) , V_337 ) ;
}
static void F_195 ( struct V_151 * V_152 )
{
T_1 V_340 = V_152 -> V_333 ;
T_6 V_341 ;
F_194 ( V_152 , & V_152 -> V_156 ) ;
F_194 ( V_152 , & V_152 -> V_311 ) ;
V_341 = F_196 ( V_152 -> V_311 . V_333 , V_152 -> V_156 . V_333 ) ;
switch ( V_341 ) {
case V_334 :
V_340 = V_342 ;
break;
case V_335 :
V_340 = V_343 ;
break;
case V_336 :
V_340 = V_344 ;
break;
default:
break;
}
if ( V_340 != V_152 -> V_333 ) {
V_340 = ( 10 * V_340 * V_152 -> V_333 ) /
( ( 9 * V_340 ) + V_152 -> V_333 ) ;
V_152 -> V_333 = V_340 ;
F_192 ( V_152 ) ;
}
}
static void F_197 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_345 = V_2 -> V_346 ;
if ( F_13 ( V_32 , & V_2 -> V_33 ) )
return;
if ( ! ( V_2 -> V_148 & V_347 ) &&
! ( V_2 -> V_148 & V_348 ) )
return;
V_2 -> V_148 &= ~ V_348 ;
switch ( V_14 -> V_20 ) {
case V_349 :
if ( ! ( V_345 & V_350 ) &&
! ( V_345 & V_351 ) )
return;
if ( ! ( V_345 & V_351 ) && V_14 -> V_103 . V_352 . V_353 ) {
T_1 V_19 ;
bool V_354 = false ;
V_14 -> V_103 . V_352 . V_353 ( V_14 , & V_19 , & V_354 , false ) ;
if ( V_354 )
return;
}
if ( V_14 -> V_355 . V_352 . V_356 ( V_14 ) != V_357 )
return;
break;
default:
if ( ! ( V_345 & V_350 ) )
return;
break;
}
F_198 ( V_150 ,
L_70
L_71
L_72 ) ;
V_2 -> V_346 = 0 ;
}
static void F_199 ( struct V_1 * V_2 , T_1 V_345 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
if ( ( V_2 -> V_132 & V_358 ) &&
( V_345 & V_359 ) ) {
F_198 ( V_166 , L_73 ) ;
F_60 ( V_14 , V_360 , V_359 ) ;
}
}
static void F_200 ( struct V_1 * V_2 , T_1 V_345 )
{
if ( ! ( V_2 -> V_148 & V_347 ) )
return;
switch ( V_2 -> V_14 . V_103 . type ) {
case V_106 :
if ( ( ( V_345 & V_350 ) || ( V_345 & V_351 ) ) &&
( ! F_13 ( V_32 , & V_2 -> V_33 ) ) ) {
V_2 -> V_346 = V_345 ;
V_2 -> V_148 |= V_348 ;
F_12 ( V_2 ) ;
return;
}
return;
case V_107 :
if ( ! ( V_345 & V_361 ) )
return;
break;
default:
return;
}
F_198 ( V_150 ,
L_70
L_71
L_72 ) ;
}
static void F_201 ( struct V_1 * V_2 , T_1 V_345 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
if ( V_345 & V_362 ) {
F_60 ( V_14 , V_360 , V_362 ) ;
if ( ! F_13 ( V_32 , & V_2 -> V_33 ) ) {
V_2 -> V_148 |= V_363 ;
F_12 ( V_2 ) ;
}
}
if ( V_345 & V_359 ) {
F_60 ( V_14 , V_360 , V_359 ) ;
if ( ! F_13 ( V_32 , & V_2 -> V_33 ) ) {
V_2 -> V_132 |= V_364 ;
F_12 ( V_2 ) ;
}
}
}
static void F_202 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
V_2 -> V_365 ++ ;
V_2 -> V_132 |= V_366 ;
V_2 -> V_367 = V_165 ;
if ( ! F_13 ( V_32 , & V_2 -> V_33 ) ) {
F_60 ( V_14 , V_368 , V_369 ) ;
F_203 ( V_14 ) ;
F_12 ( V_2 ) ;
}
}
static inline void F_204 ( struct V_1 * V_2 ,
T_4 V_109 )
{
T_1 V_110 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_103 . type ) {
case V_104 :
V_110 = ( V_111 & V_109 ) ;
F_60 ( V_14 , V_370 , V_110 ) ;
break;
case V_106 :
case V_107 :
V_110 = ( V_109 & 0xFFFFFFFF ) ;
if ( V_110 )
F_60 ( V_14 , F_205 ( 0 ) , V_110 ) ;
V_110 = ( V_109 >> 32 ) ;
if ( V_110 )
F_60 ( V_14 , F_205 ( 1 ) , V_110 ) ;
break;
default:
break;
}
}
static inline void F_206 ( struct V_1 * V_2 ,
T_4 V_109 )
{
T_1 V_110 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_103 . type ) {
case V_104 :
V_110 = ( V_111 & V_109 ) ;
F_60 ( V_14 , V_368 , V_110 ) ;
break;
case V_106 :
case V_107 :
V_110 = ( V_109 & 0xFFFFFFFF ) ;
if ( V_110 )
F_60 ( V_14 , F_207 ( 0 ) , V_110 ) ;
V_110 = ( V_109 >> 32 ) ;
if ( V_110 )
F_60 ( V_14 , F_207 ( 1 ) , V_110 ) ;
break;
default:
break;
}
}
static inline void F_208 ( struct V_1 * V_2 , bool V_371 ,
bool V_372 )
{
T_1 V_110 = ( V_323 & ~ V_111 ) ;
if ( V_2 -> V_132 & V_366 )
V_110 &= ~ V_326 ;
if ( V_2 -> V_148 & V_347 )
switch ( V_2 -> V_14 . V_103 . type ) {
case V_106 :
V_110 |= V_373 ;
break;
case V_107 :
V_110 |= V_374 ;
break;
default:
break;
}
if ( V_2 -> V_132 & V_358 )
V_110 |= V_375 ;
switch ( V_2 -> V_14 . V_103 . type ) {
case V_106 :
V_110 |= V_375 ;
V_110 |= V_376 ;
case V_107 :
V_110 |= V_377 ;
V_110 |= V_325 ;
break;
default:
break;
}
if ( V_2 -> V_14 . V_103 . type == V_107 )
V_110 |= V_378 ;
if ( ( V_2 -> V_132 & V_379 ) &&
! ( V_2 -> V_148 & V_380 ) )
V_110 |= V_381 ;
F_60 ( & V_2 -> V_14 , V_370 , V_110 ) ;
if ( V_371 )
F_204 ( V_2 , ~ 0 ) ;
if ( V_372 )
F_203 ( & V_2 -> V_14 ) ;
}
static T_11 F_209 ( int V_382 , void * V_87 )
{
struct V_1 * V_2 = V_87 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_345 ;
V_345 = F_26 ( V_14 , V_112 ) ;
V_345 &= 0xFFFF0000 ;
F_60 ( V_14 , V_360 , V_345 ) ;
if ( V_345 & V_351 )
F_202 ( V_2 ) ;
if ( V_345 & V_383 )
F_210 ( V_2 ) ;
switch ( V_14 -> V_103 . type ) {
case V_106 :
case V_107 :
if ( V_345 & V_384 )
F_94 ( V_385 , L_74
L_75 ) ;
if ( V_345 & V_386 ) {
int V_387 = 0 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_72 ; V_43 ++ ) {
struct V_52 * V_113 = V_2 -> V_53 [ V_43 ] ;
if ( F_211 ( V_388 ,
& V_113 -> V_33 ) )
V_387 ++ ;
}
if ( V_387 ) {
F_60 ( V_14 , V_368 , V_389 ) ;
V_2 -> V_148 |= V_380 ;
F_12 ( V_2 ) ;
}
}
F_201 ( V_2 , V_345 ) ;
F_200 ( V_2 , V_345 ) ;
break;
default:
break;
}
F_199 ( V_2 , V_345 ) ;
if ( F_86 ( V_345 & V_390 ) )
F_212 ( V_2 , V_345 ) ;
if ( ! F_13 ( V_32 , & V_2 -> V_33 ) )
F_208 ( V_2 , false , false ) ;
return V_391 ;
}
static T_11 F_213 ( int V_382 , void * V_87 )
{
struct V_151 * V_152 = V_87 ;
if ( V_152 -> V_311 . V_113 || V_152 -> V_156 . V_113 )
F_214 ( & V_152 -> V_266 ) ;
return V_391 ;
}
int F_215 ( struct V_312 * V_266 , int V_155 )
{
struct V_151 * V_152 =
F_187 ( V_266 , struct V_151 , V_266 ) ;
struct V_1 * V_2 = V_152 -> V_2 ;
struct V_52 * V_113 ;
int V_392 ;
bool V_393 = true ;
#ifdef F_216
if ( V_2 -> V_132 & V_181 )
F_108 ( V_152 ) ;
#endif
F_110 (ring, q_vector->tx)
V_393 &= ! ! F_83 ( V_152 , V_113 ) ;
if ( ! F_217 ( V_152 ) )
return V_155 ;
if ( V_152 -> V_311 . V_83 > 1 )
V_392 = F_196 ( V_155 / V_152 -> V_311 . V_83 , 1 ) ;
else
V_392 = V_155 ;
F_110 (ring, q_vector->rx)
V_393 &= ( F_182 ( V_152 , V_113 ,
V_392 ) < V_392 ) ;
F_218 ( V_152 ) ;
if ( ! V_393 )
return V_155 ;
F_219 ( V_266 ) ;
if ( V_2 -> V_394 & 1 )
F_195 ( V_152 ) ;
if ( ! F_13 ( V_32 , & V_2 -> V_33 ) )
F_204 ( V_2 , ( ( T_4 ) 1 << V_152 -> V_318 ) ) ;
return 0 ;
}
static int F_220 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = V_2 -> V_50 ;
int V_395 , V_16 ;
int V_396 = 0 , V_397 = 0 ;
for ( V_395 = 0 ; V_395 < V_2 -> V_183 ; V_395 ++ ) {
struct V_151 * V_152 = V_2 -> V_152 [ V_395 ] ;
struct V_398 * V_399 = & V_2 -> V_400 [ V_395 ] ;
if ( V_152 -> V_156 . V_113 && V_152 -> V_311 . V_113 ) {
snprintf ( V_152 -> V_48 , sizeof( V_152 -> V_48 ) - 1 ,
L_76 , V_50 -> V_48 , L_77 , V_396 ++ ) ;
V_397 ++ ;
} else if ( V_152 -> V_311 . V_113 ) {
snprintf ( V_152 -> V_48 , sizeof( V_152 -> V_48 ) - 1 ,
L_76 , V_50 -> V_48 , L_78 , V_396 ++ ) ;
} else if ( V_152 -> V_156 . V_113 ) {
snprintf ( V_152 -> V_48 , sizeof( V_152 -> V_48 ) - 1 ,
L_76 , V_50 -> V_48 , L_79 , V_397 ++ ) ;
} else {
continue;
}
V_16 = F_221 ( V_399 -> V_395 , & F_213 , 0 ,
V_152 -> V_48 , V_152 ) ;
if ( V_16 ) {
F_92 ( V_166 , L_80
L_81 , V_16 ) ;
goto V_401;
}
if ( V_2 -> V_132 & V_379 ) {
F_222 ( V_399 -> V_395 ,
& V_152 -> V_402 ) ;
}
}
V_16 = F_221 ( V_2 -> V_400 [ V_395 ] . V_395 ,
F_209 , 0 , V_50 -> V_48 , V_2 ) ;
if ( V_16 ) {
F_92 ( V_166 , L_82 , V_16 ) ;
goto V_401;
}
return 0 ;
V_401:
while ( V_395 ) {
V_395 -- ;
F_222 ( V_2 -> V_400 [ V_395 ] . V_395 ,
NULL ) ;
F_223 ( V_2 -> V_400 [ V_395 ] . V_395 ,
V_2 -> V_152 [ V_395 ] ) ;
}
V_2 -> V_132 &= ~ V_403 ;
F_224 ( V_2 -> V_9 ) ;
F_225 ( V_2 -> V_400 ) ;
V_2 -> V_400 = NULL ;
return V_16 ;
}
static T_11 F_226 ( int V_382 , void * V_87 )
{
struct V_1 * V_2 = V_87 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_151 * V_152 = V_2 -> V_152 [ 0 ] ;
T_1 V_345 ;
F_60 ( V_14 , V_368 , V_404 ) ;
V_345 = F_26 ( V_14 , V_360 ) ;
if ( ! V_345 ) {
if ( ! F_13 ( V_32 , & V_2 -> V_33 ) )
F_208 ( V_2 , true , true ) ;
return V_405 ;
}
if ( V_345 & V_351 )
F_202 ( V_2 ) ;
switch ( V_14 -> V_103 . type ) {
case V_106 :
F_201 ( V_2 , V_345 ) ;
case V_107 :
if ( V_345 & V_384 )
F_94 ( V_385 , L_83
L_75 ) ;
F_200 ( V_2 , V_345 ) ;
break;
default:
break;
}
F_199 ( V_2 , V_345 ) ;
if ( F_86 ( V_345 & V_390 ) )
F_212 ( V_2 , V_345 ) ;
F_214 ( & V_152 -> V_266 ) ;
if ( ! F_13 ( V_32 , & V_2 -> V_33 ) )
F_208 ( V_2 , false , false ) ;
return V_391 ;
}
static int F_227 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = V_2 -> V_50 ;
int V_16 ;
if ( V_2 -> V_132 & V_403 )
V_16 = F_220 ( V_2 ) ;
else if ( V_2 -> V_132 & V_406 )
V_16 = F_221 ( V_2 -> V_9 -> V_382 , F_226 , 0 ,
V_50 -> V_48 , V_2 ) ;
else
V_16 = F_221 ( V_2 -> V_9 -> V_382 , F_226 , V_407 ,
V_50 -> V_48 , V_2 ) ;
if ( V_16 )
F_92 ( V_166 , L_84 , V_16 ) ;
return V_16 ;
}
static void F_228 ( struct V_1 * V_2 )
{
int V_395 ;
if ( ! ( V_2 -> V_132 & V_403 ) ) {
F_223 ( V_2 -> V_9 -> V_382 , V_2 ) ;
return;
}
for ( V_395 = 0 ; V_395 < V_2 -> V_183 ; V_395 ++ ) {
struct V_151 * V_152 = V_2 -> V_152 [ V_395 ] ;
struct V_398 * V_399 = & V_2 -> V_400 [ V_395 ] ;
if ( ! V_152 -> V_311 . V_113 && ! V_152 -> V_156 . V_113 )
continue;
F_222 ( V_399 -> V_395 , NULL ) ;
F_223 ( V_399 -> V_395 , V_152 ) ;
}
F_223 ( V_2 -> V_400 [ V_395 ++ ] . V_395 , V_2 ) ;
}
static inline void F_229 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_103 . type ) {
case V_104 :
F_60 ( & V_2 -> V_14 , V_368 , ~ 0 ) ;
break;
case V_106 :
case V_107 :
F_60 ( & V_2 -> V_14 , V_368 , 0xFFFF0000 ) ;
F_60 ( & V_2 -> V_14 , F_207 ( 0 ) , ~ 0 ) ;
F_60 ( & V_2 -> V_14 , F_207 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_203 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_132 & V_403 ) {
int V_395 ;
for ( V_395 = 0 ; V_395 < V_2 -> V_183 ; V_395 ++ )
F_230 ( V_2 -> V_400 [ V_395 ] . V_395 ) ;
F_230 ( V_2 -> V_400 [ V_395 ++ ] . V_395 ) ;
} else {
F_230 ( V_2 -> V_9 -> V_382 ) ;
}
}
static void F_231 ( struct V_1 * V_2 )
{
struct V_151 * V_152 = V_2 -> V_152 [ 0 ] ;
F_192 ( V_152 ) ;
F_62 ( V_2 , 0 , 0 , 0 ) ;
F_62 ( V_2 , 1 , 0 , 0 ) ;
F_94 ( V_14 , L_85 ) ;
}
void F_232 ( struct V_1 * V_2 ,
struct V_52 * V_113 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_4 V_408 = V_113 -> V_76 ;
int V_409 = 10 ;
T_1 V_410 = V_411 ;
T_6 V_142 = V_113 -> V_142 ;
F_60 ( V_14 , F_39 ( V_142 ) , 0 ) ;
F_203 ( V_14 ) ;
F_60 ( V_14 , F_34 ( V_142 ) ,
( V_408 & F_233 ( 32 ) ) ) ;
F_60 ( V_14 , F_35 ( V_142 ) , ( V_408 >> 32 ) ) ;
F_60 ( V_14 , F_36 ( V_142 ) ,
V_113 -> V_83 * sizeof( union V_56 ) ) ;
F_60 ( V_14 , F_37 ( V_142 ) , 0 ) ;
F_60 ( V_14 , F_38 ( V_142 ) , 0 ) ;
V_113 -> V_139 = V_2 -> V_412 + F_38 ( V_142 ) ;
#if F_234 ( V_413 )
if ( ! V_113 -> V_152 || ( V_113 -> V_152 -> V_333 < V_342 ) )
#else
if ( ! V_113 -> V_152 || ( V_113 -> V_152 -> V_333 < 8 ) )
#endif
V_410 |= ( 1 << 16 ) ;
else
V_410 |= ( 8 << 16 ) ;
V_410 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_132 & V_379 ) {
V_113 -> V_414 = V_2 -> V_414 ;
V_113 -> V_415 = 0 ;
F_235 ( V_388 , & V_113 -> V_33 ) ;
} else {
V_113 -> V_414 = 0 ;
}
if ( ! F_14 ( V_416 , & V_113 -> V_33 ) ) {
struct V_151 * V_152 = V_113 -> V_152 ;
if ( V_152 )
F_236 ( V_113 -> V_50 ,
& V_152 -> V_402 ,
V_113 -> V_81 ) ;
}
F_23 ( V_125 , & V_113 -> V_33 ) ;
F_60 ( V_14 , F_39 ( V_142 ) , V_410 ) ;
if ( V_14 -> V_103 . type == V_104 &&
! ( F_26 ( V_14 , V_417 ) & V_418 ) )
return;
do {
F_237 ( 1000 , 2000 ) ;
V_410 = F_26 ( V_14 , F_39 ( V_142 ) ) ;
} while ( -- V_409 && ! ( V_410 & V_411 ) );
if ( ! V_409 )
F_92 ( V_150 , L_86 , V_142 ) ;
}
static void F_238 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_419 , V_420 ;
T_6 V_421 = F_239 ( V_2 -> V_50 ) ;
if ( V_14 -> V_103 . type == V_104 )
return;
V_419 = F_26 ( V_14 , V_422 ) ;
V_419 |= V_423 ;
F_60 ( V_14 , V_422 , V_419 ) ;
if ( V_2 -> V_132 & V_424 ) {
V_420 = V_425 ;
if ( V_421 > 4 )
V_420 |= V_426 | V_427 ;
else if ( V_421 > 1 )
V_420 |= V_426 | V_428 ;
else if ( V_2 -> V_429 [ V_430 ] . V_431 == 4 )
V_420 |= V_432 ;
else
V_420 |= V_433 ;
} else {
if ( V_421 > 4 )
V_420 = V_426 | V_427 ;
else if ( V_421 > 1 )
V_420 = V_426 | V_428 ;
else
V_420 = V_434 ;
}
F_60 ( V_14 , V_435 , V_420 ) ;
if ( V_421 ) {
T_1 V_436 = F_26 ( V_14 , V_437 ) ;
V_436 |= V_438 ;
F_60 ( V_14 , V_437 , V_436 ) ;
}
V_419 &= ~ V_423 ;
F_60 ( V_14 , V_422 , V_419 ) ;
}
static void F_240 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_439 ;
T_1 V_43 ;
F_238 ( V_2 ) ;
if ( V_14 -> V_103 . type != V_104 ) {
V_439 = F_26 ( V_14 , V_440 ) ;
V_439 |= V_441 ;
F_60 ( V_14 , V_440 , V_439 ) ;
}
for ( V_43 = 0 ; V_43 < V_2 -> V_72 ; V_43 ++ )
F_232 ( V_2 , V_2 -> V_53 [ V_43 ] ) ;
}
static void F_241 ( struct V_1 * V_2 ,
struct V_52 * V_113 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_6 V_142 = V_113 -> V_142 ;
T_1 V_442 = F_26 ( V_14 , F_25 ( V_142 ) ) ;
V_442 |= V_443 ;
F_60 ( V_14 , F_25 ( V_142 ) , V_442 ) ;
}
static void F_242 ( struct V_1 * V_2 ,
struct V_52 * V_113 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_6 V_142 = V_113 -> V_142 ;
T_1 V_442 = F_26 ( V_14 , F_25 ( V_142 ) ) ;
V_442 &= ~ V_443 ;
F_60 ( V_14 , F_25 ( V_142 ) , V_442 ) ;
}
static void F_243 ( struct V_1 * V_2 ,
struct V_52 * V_62 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_442 ;
T_6 V_142 = V_62 -> V_142 ;
if ( V_14 -> V_103 . type == V_104 ) {
T_2 V_110 = V_2 -> V_429 [ V_430 ] . V_110 ;
V_142 &= V_110 ;
}
V_442 = V_281 << V_444 ;
V_442 |= F_58 ( V_62 ) >> V_445 ;
V_442 |= V_446 ;
F_60 ( V_14 , F_25 ( V_142 ) , V_442 ) ;
}
static void F_244 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
static const T_1 V_447 [ 10 ] = { 0xE291D73D , 0x1805EC6C , 0x2A94B30D ,
0xA54F2BEC , 0xEA49AF7C , 0xE214AD3D , 0xB855AABE ,
0x6A3E67EA , 0x14364D17 , 0x3BED200D } ;
T_1 V_448 = 0 , V_449 = 0 ;
T_1 V_450 ;
int V_43 , V_44 ;
T_2 V_451 = V_2 -> V_429 [ V_430 ] . V_431 ;
if ( ( V_2 -> V_132 & V_424 ) && ( V_451 < 2 ) )
V_451 = 2 ;
for ( V_43 = 0 ; V_43 < 10 ; V_43 ++ )
F_60 ( V_14 , F_245 ( V_43 ) , V_447 [ V_43 ] ) ;
for ( V_43 = 0 , V_44 = 0 ; V_43 < 128 ; V_43 ++ , V_44 ++ ) {
if ( V_44 == V_451 )
V_44 = 0 ;
V_449 = ( V_449 << 8 ) | ( V_44 * 0x11 ) ;
if ( ( V_43 & 3 ) == 3 )
F_60 ( V_14 , F_246 ( V_43 >> 2 ) , V_449 ) ;
}
V_450 = F_26 ( V_14 , V_452 ) ;
V_450 |= V_453 ;
F_60 ( V_14 , V_452 , V_450 ) ;
if ( V_2 -> V_14 . V_103 . type == V_104 ) {
if ( V_2 -> V_429 [ V_430 ] . V_110 )
V_448 = V_454 ;
} else {
T_6 V_421 = F_239 ( V_2 -> V_50 ) ;
if ( V_2 -> V_132 & V_424 ) {
if ( V_421 > 4 )
V_448 = V_455 ;
else if ( V_421 > 1 )
V_448 = V_456 ;
else if ( V_2 -> V_429 [ V_430 ] . V_431 == 4 )
V_448 = V_457 ;
else
V_448 = V_458 ;
} else {
if ( V_421 > 4 )
V_448 = V_459 ;
else if ( V_421 > 1 )
V_448 = V_460 ;
else
V_448 = V_454 ;
}
}
V_448 |= V_461 |
V_462 |
V_463 |
V_464 ;
if ( V_2 -> V_148 & V_465 )
V_448 |= V_466 ;
if ( V_2 -> V_148 & V_467 )
V_448 |= V_468 ;
F_60 ( V_14 , V_469 , V_448 ) ;
}
static void F_247 ( struct V_1 * V_2 ,
struct V_52 * V_113 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_470 ;
T_6 V_142 = V_113 -> V_142 ;
if ( ! F_157 ( V_113 ) )
return;
V_470 = F_26 ( V_14 , F_248 ( V_142 ) ) ;
V_470 |= V_471 ;
V_470 |= V_472 ;
F_60 ( V_14 , F_248 ( V_142 ) , V_470 ) ;
}
static void F_249 ( struct V_1 * V_2 ,
struct V_52 * V_113 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_409 = V_473 ;
T_1 V_474 ;
T_6 V_142 = V_113 -> V_142 ;
if ( F_250 ( V_14 -> V_38 ) )
return;
if ( V_14 -> V_103 . type == V_104 &&
! ( F_26 ( V_14 , V_417 ) & V_418 ) )
return;
do {
F_237 ( 1000 , 2000 ) ;
V_474 = F_26 ( V_14 , F_31 ( V_142 ) ) ;
} while ( -- V_409 && ! ( V_474 & V_475 ) );
if ( ! V_409 ) {
F_92 ( V_150 , L_87
L_88 , V_142 ) ;
}
}
void F_251 ( struct V_1 * V_2 ,
struct V_52 * V_113 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_409 = V_473 ;
T_1 V_474 ;
T_6 V_142 = V_113 -> V_142 ;
if ( F_250 ( V_14 -> V_38 ) )
return;
V_474 = F_26 ( V_14 , F_31 ( V_142 ) ) ;
V_474 &= ~ V_475 ;
F_60 ( V_14 , F_31 ( V_142 ) , V_474 ) ;
if ( V_14 -> V_103 . type == V_104 &&
! ( F_26 ( V_14 , V_417 ) & V_418 ) )
return;
do {
F_252 ( 10 ) ;
V_474 = F_26 ( V_14 , F_31 ( V_142 ) ) ;
} while ( -- V_409 && ( V_474 & V_475 ) );
if ( ! V_409 ) {
F_92 ( V_150 , L_89
L_88 , V_142 ) ;
}
}
void F_253 ( struct V_1 * V_2 ,
struct V_52 * V_113 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_4 V_476 = V_113 -> V_76 ;
T_1 V_474 ;
T_6 V_142 = V_113 -> V_142 ;
V_474 = F_26 ( V_14 , F_31 ( V_142 ) ) ;
F_251 ( V_2 , V_113 ) ;
F_60 ( V_14 , F_32 ( V_142 ) , ( V_476 & F_233 ( 32 ) ) ) ;
F_60 ( V_14 , F_33 ( V_142 ) , ( V_476 >> 32 ) ) ;
F_60 ( V_14 , F_28 ( V_142 ) ,
V_113 -> V_83 * sizeof( union V_63 ) ) ;
F_60 ( V_14 , F_29 ( V_142 ) , 0 ) ;
F_60 ( V_14 , F_30 ( V_142 ) , 0 ) ;
V_113 -> V_139 = V_2 -> V_412 + F_30 ( V_142 ) ;
F_243 ( V_2 , V_113 ) ;
F_247 ( V_2 , V_113 ) ;
if ( V_14 -> V_103 . type == V_104 ) {
V_474 &= ~ 0x3FFFFF ;
V_474 |= 0x080420 ;
}
V_474 |= V_475 ;
F_60 ( V_14 , F_31 ( V_142 ) , V_474 ) ;
F_249 ( V_2 , V_113 ) ;
F_133 ( V_113 , F_99 ( V_113 ) ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_451 = V_2 -> V_429 [ V_430 ] . V_431 ;
T_2 V_477 ;
T_1 V_478 = V_479 |
V_480 |
V_481 |
V_482 |
V_483 ;
if ( V_14 -> V_103 . type == V_104 )
return;
if ( V_451 > 3 )
V_478 |= 2 << 29 ;
else if ( V_451 > 1 )
V_478 |= 1 << 29 ;
F_255 (pool, &adapter->fwd_bitmask, 32 )
F_60 ( V_14 , F_256 ( F_257 ( V_477 ) ) , V_478 ) ;
}
static void F_258 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_171 , V_484 ;
T_1 V_485 , V_486 ;
int V_43 ;
if ( ! ( V_2 -> V_132 & V_424 ) )
return;
V_486 = F_26 ( V_14 , V_487 ) ;
V_486 |= V_488 ;
V_486 &= ~ V_489 ;
V_486 |= F_257 ( 0 ) << V_490 ;
V_486 |= V_491 ;
F_60 ( V_14 , V_487 , V_486 ) ;
V_484 = F_257 ( 0 ) % 32 ;
V_171 = ( F_257 ( 0 ) >= 32 ) ? 1 : 0 ;
F_60 ( V_14 , F_259 ( V_171 ) , ( ~ 0 ) << V_484 ) ;
F_60 ( V_14 , F_259 ( V_171 ^ 1 ) , V_171 - 1 ) ;
F_60 ( V_14 , F_260 ( V_171 ) , ( ~ 0 ) << V_484 ) ;
F_60 ( V_14 , F_260 ( V_171 ^ 1 ) , V_171 - 1 ) ;
if ( V_2 -> V_148 & V_492 )
F_60 ( V_14 , V_493 , V_494 ) ;
V_14 -> V_103 . V_352 . V_495 ( V_14 , 0 , F_257 ( 0 ) ) ;
switch ( V_2 -> V_429 [ V_496 ] . V_110 ) {
case V_497 :
V_485 = V_498 ;
break;
case V_499 :
V_485 = V_500 ;
break;
default:
V_485 = V_501 ;
break;
}
F_60 ( V_14 , V_502 , V_485 ) ;
V_14 -> V_103 . V_352 . V_503 ( V_14 , ( V_2 -> V_319 != 0 ) ,
V_2 -> V_319 ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_319 ; V_43 ++ ) {
if ( ! V_2 -> V_504 [ V_43 ] . V_505 )
F_261 ( V_2 -> V_50 , V_43 , false ) ;
}
}
static void F_262 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_49 * V_50 = V_2 -> V_50 ;
int V_506 = V_50 -> V_307 + V_240 + V_507 ;
struct V_52 * V_62 ;
int V_43 ;
T_1 V_508 , V_509 ;
#ifdef F_138
if ( ( V_2 -> V_132 & V_510 ) &&
( V_506 < V_511 ) )
V_506 = V_511 ;
#endif
if ( V_506 < ( V_512 + V_507 ) )
V_506 = ( V_512 + V_507 ) ;
V_508 = F_26 ( V_14 , V_513 ) ;
if ( V_506 != ( V_508 >> V_514 ) ) {
V_508 &= ~ V_515 ;
V_508 |= V_506 << V_514 ;
F_60 ( V_14 , V_513 , V_508 ) ;
}
V_509 = F_26 ( V_14 , V_516 ) ;
V_509 |= V_517 ;
F_60 ( V_14 , V_516 , V_509 ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_88 ; V_43 ++ ) {
V_62 = V_2 -> V_62 [ V_43 ] ;
if ( V_2 -> V_148 & V_518 )
F_263 ( V_62 ) ;
else
F_264 ( V_62 ) ;
}
}
static void F_265 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_519 = F_26 ( V_14 , V_520 ) ;
switch ( V_14 -> V_103 . type ) {
case V_104 :
V_519 |= V_521 ;
break;
case V_106 :
case V_107 :
F_60 ( V_14 , V_522 ,
( V_523 | F_26 ( V_14 , V_522 ) ) ) ;
V_519 &= ~ V_524 ;
V_519 |= ( V_525 | V_526 ) ;
V_519 |= V_527 ;
break;
default:
return;
}
F_60 ( V_14 , V_520 , V_519 ) ;
}
static void F_266 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_43 ;
T_1 V_176 , V_528 ;
V_176 = F_26 ( V_14 , V_529 ) ;
F_60 ( V_14 , V_529 , V_176 & ~ V_530 ) ;
F_254 ( V_2 ) ;
F_265 ( V_2 ) ;
V_528 = F_26 ( V_14 , V_531 ) ;
V_528 &= ~ V_532 ;
if ( ! ( V_2 -> V_148 & V_518 ) )
V_528 |= V_532 ;
F_60 ( V_14 , V_531 , V_528 ) ;
F_244 ( V_2 ) ;
F_262 ( V_2 ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_88 ; V_43 ++ )
F_253 ( V_2 , V_2 -> V_62 [ V_43 ] ) ;
if ( V_14 -> V_103 . type == V_104 )
V_176 |= V_533 ;
V_176 |= V_530 ;
V_14 -> V_103 . V_352 . V_534 ( V_14 , V_176 ) ;
}
static int F_267 ( struct V_49 * V_50 ,
T_9 V_535 , T_2 V_264 )
{
struct V_1 * V_2 = F_78 ( V_50 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
V_14 -> V_103 . V_352 . V_536 ( & V_2 -> V_14 , V_264 , F_257 ( 0 ) , true ) ;
F_235 ( V_264 , V_2 -> V_537 ) ;
return 0 ;
}
static int F_268 ( struct V_49 * V_50 ,
T_9 V_535 , T_2 V_264 )
{
struct V_1 * V_2 = F_78 ( V_50 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
V_14 -> V_103 . V_352 . V_536 ( & V_2 -> V_14 , V_264 , F_257 ( 0 ) , false ) ;
F_23 ( V_264 , V_2 -> V_537 ) ;
return 0 ;
}
static void F_269 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_538 ;
V_538 = F_26 ( V_14 , V_539 ) ;
V_538 &= ~ ( V_540 | V_541 ) ;
F_60 ( V_14 , V_539 , V_538 ) ;
}
static void F_270 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_538 ;
V_538 = F_26 ( V_14 , V_539 ) ;
V_538 |= V_540 ;
V_538 &= ~ V_541 ;
F_60 ( V_14 , V_539 , V_538 ) ;
}
static void F_271 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_538 ;
int V_43 , V_44 ;
switch ( V_14 -> V_103 . type ) {
case V_104 :
V_538 = F_26 ( V_14 , V_539 ) ;
V_538 &= ~ V_542 ;
F_60 ( V_14 , V_539 , V_538 ) ;
break;
case V_106 :
case V_107 :
for ( V_43 = 0 ; V_43 < V_2 -> V_88 ; V_43 ++ ) {
struct V_52 * V_113 = V_2 -> V_62 [ V_43 ] ;
if ( V_113 -> V_140 )
continue;
V_44 = V_113 -> V_142 ;
V_538 = F_26 ( V_14 , F_31 ( V_44 ) ) ;
V_538 &= ~ V_543 ;
F_60 ( V_14 , F_31 ( V_44 ) , V_538 ) ;
}
break;
default:
break;
}
}
static void F_272 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_538 ;
int V_43 , V_44 ;
switch ( V_14 -> V_103 . type ) {
case V_104 :
V_538 = F_26 ( V_14 , V_539 ) ;
V_538 |= V_542 ;
F_60 ( V_14 , V_539 , V_538 ) ;
break;
case V_106 :
case V_107 :
for ( V_43 = 0 ; V_43 < V_2 -> V_88 ; V_43 ++ ) {
struct V_52 * V_113 = V_2 -> V_62 [ V_43 ] ;
if ( V_113 -> V_140 )
continue;
V_44 = V_113 -> V_142 ;
V_538 = F_26 ( V_14 , F_31 ( V_44 ) ) ;
V_538 |= V_543 ;
F_60 ( V_14 , F_31 ( V_44 ) , V_538 ) ;
}
break;
default:
break;
}
}
static void F_273 ( struct V_1 * V_2 )
{
T_2 V_264 ;
F_267 ( V_2 -> V_50 , F_137 ( V_242 ) , 0 ) ;
F_255 (vid, adapter->active_vlans, VLAN_N_VID)
F_267 ( V_2 -> V_50 , F_137 ( V_242 ) , V_264 ) ;
}
static int F_274 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_78 ( V_50 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
unsigned int V_544 = V_14 -> V_103 . V_545 - 1 ;
int V_83 = 0 ;
if ( V_2 -> V_132 & V_424 )
V_544 = V_546 - 1 ;
if ( F_275 ( V_50 ) > V_544 )
return - V_547 ;
if ( ! F_276 ( V_50 ) ) {
struct V_548 * V_549 ;
if ( ! V_14 -> V_103 . V_352 . V_550 )
return - V_547 ;
F_277 (ha, netdev) {
if ( ! V_544 )
break;
V_14 -> V_103 . V_352 . V_550 ( V_14 , V_544 -- , V_549 -> V_551 ,
F_257 ( 0 ) , V_552 ) ;
V_83 ++ ;
}
}
for (; V_544 > 0 ; V_544 -- )
V_14 -> V_103 . V_352 . V_553 ( V_14 , V_544 ) ;
return V_83 ;
}
void F_278 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_78 ( V_50 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_554 , V_555 = V_556 | V_557 ;
int V_83 ;
V_554 = F_26 ( V_14 , V_558 ) ;
V_554 &= ~ V_559 ;
V_554 |= V_560 ;
V_554 |= V_561 ;
V_554 |= V_562 ;
V_554 &= ~ ( V_563 | V_564 ) ;
if ( V_50 -> V_132 & V_565 ) {
V_14 -> V_566 . V_567 = true ;
V_554 |= ( V_563 | V_564 ) ;
V_555 |= ( V_568 | V_569 ) ;
if ( ! ( V_2 -> V_132 & ( V_570 |
V_424 ) ) )
F_269 ( V_2 ) ;
else
F_270 ( V_2 ) ;
} else {
if ( V_50 -> V_132 & V_571 ) {
V_554 |= V_564 ;
V_555 |= V_569 ;
}
F_270 ( V_2 ) ;
V_14 -> V_566 . V_567 = false ;
}
V_83 = F_274 ( V_50 ) ;
if ( V_83 < 0 ) {
V_554 |= V_563 ;
V_555 |= V_568 ;
}
V_14 -> V_103 . V_352 . V_572 ( V_14 , V_50 ) ;
V_555 |= V_573 ;
if ( V_2 -> V_319 )
F_279 ( V_2 ) ;
if ( V_14 -> V_103 . type != V_104 ) {
V_555 |= F_26 ( V_14 , F_280 ( F_257 ( 0 ) ) ) &
~ ( V_569 | V_573 |
V_568 ) ;
F_60 ( V_14 , F_280 ( F_257 ( 0 ) ) , V_555 ) ;
}
if ( V_2 -> V_50 -> V_190 & V_285 ) {
V_554 |= ( V_559 |
V_560 |
V_562 ) ;
V_554 &= ~ ( V_561 ) ;
}
F_60 ( V_14 , V_558 , V_554 ) ;
if ( V_50 -> V_190 & V_262 )
F_272 ( V_2 ) ;
else
F_271 ( V_2 ) ;
}
static void F_281 ( struct V_1 * V_2 )
{
int V_574 ;
for ( V_574 = 0 ; V_574 < V_2 -> V_183 ; V_574 ++ ) {
F_282 ( V_2 -> V_152 [ V_574 ] ) ;
F_283 ( & V_2 -> V_152 [ V_574 ] -> V_266 ) ;
}
}
static void F_284 ( struct V_1 * V_2 )
{
int V_574 ;
for ( V_574 = 0 ; V_574 < V_2 -> V_183 ; V_574 ++ ) {
F_285 ( & V_2 -> V_152 [ V_574 ] -> V_266 ) ;
while ( ! F_286 ( V_2 -> V_152 [ V_574 ] ) ) {
F_40 ( L_90 , V_574 ) ;
F_237 ( 1000 , 20000 ) ;
}
}
}
static void F_287 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_506 = V_2 -> V_50 -> V_307 + V_240 + V_507 ;
if ( ! ( V_2 -> V_132 & V_133 ) ) {
if ( V_14 -> V_103 . type == V_104 )
F_288 ( V_2 -> V_50 , 65536 ) ;
return;
}
if ( V_14 -> V_103 . type == V_104 )
F_288 ( V_2 -> V_50 , 32768 ) ;
#ifdef F_138
if ( V_2 -> V_50 -> V_190 & V_575 )
V_506 = F_196 ( V_506 , V_511 ) ;
#endif
if ( V_2 -> V_576 & V_577 ) {
F_289 ( V_14 , & V_2 -> V_129 , V_506 ,
V_578 ) ;
F_289 ( V_14 , & V_2 -> V_129 , V_506 ,
V_579 ) ;
F_290 ( V_14 , & V_2 -> V_129 ) ;
} else if ( V_2 -> V_580 && V_2 -> V_131 ) {
F_291 ( & V_2 -> V_14 ,
V_2 -> V_580 ,
V_506 ) ;
F_292 ( & V_2 -> V_14 ,
V_2 -> V_131 -> V_128 ,
V_2 -> V_580 -> V_581 ) ;
}
if ( V_14 -> V_103 . type != V_104 ) {
T_1 V_582 = 0 ;
T_2 V_451 = V_2 -> V_429 [ V_430 ] . V_431 - 1 ;
while ( V_451 ) {
V_582 ++ ;
V_451 >>= 1 ;
}
F_60 ( V_14 , V_583 , V_582 * 0x11111111 ) ;
}
}
static int F_293 ( struct V_1 * V_2 , int V_584 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_49 * V_68 = V_2 -> V_50 ;
int V_385 , V_127 , V_585 , V_586 ;
T_1 V_587 , V_588 ;
V_127 = V_385 = V_68 -> V_307 + V_240 + V_507 + V_589 ;
#ifdef F_138
if ( ( V_68 -> V_190 & V_575 ) &&
( V_127 < V_511 ) &&
( V_584 == F_294 ( V_2 ) ) )
V_127 = V_511 ;
#endif
switch ( V_14 -> V_103 . type ) {
case V_107 :
V_587 = F_295 ( V_385 , V_127 ) ;
break;
default:
V_587 = F_296 ( V_385 , V_127 ) ;
break;
}
if ( V_2 -> V_132 & V_424 )
V_587 += F_297 ( V_127 ) ;
V_585 = F_298 ( V_587 ) ;
V_588 = F_26 ( V_14 , F_299 ( V_584 ) ) >> 10 ;
V_586 = V_588 - V_585 ;
if ( V_586 < 0 ) {
F_82 ( V_150 , L_91
L_92
L_93 , V_584 ) ;
V_586 = V_127 + 1 ;
}
return V_586 ;
}
static int F_300 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_49 * V_68 = V_2 -> V_50 ;
int V_127 ;
T_1 V_587 ;
V_127 = V_68 -> V_307 + V_240 + V_507 ;
switch ( V_14 -> V_103 . type ) {
case V_107 :
V_587 = F_301 ( V_127 ) ;
break;
default:
V_587 = F_302 ( V_127 ) ;
break;
}
return F_298 ( V_587 ) ;
}
static void F_303 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_590 = F_239 ( V_2 -> V_50 ) ;
int V_43 ;
if ( ! V_590 )
V_590 = 1 ;
V_14 -> V_118 . V_591 = F_300 ( V_2 ) ;
for ( V_43 = 0 ; V_43 < V_590 ; V_43 ++ ) {
V_14 -> V_118 . V_592 [ V_43 ] = F_293 ( V_2 , V_43 ) ;
if ( V_14 -> V_118 . V_591 > V_14 -> V_118 . V_592 [ V_43 ] )
V_14 -> V_118 . V_591 = 0 ;
}
}
static void F_304 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_593 ;
T_6 V_127 = F_239 ( V_2 -> V_50 ) ;
if ( V_2 -> V_132 & V_379 ||
V_2 -> V_132 & V_594 )
V_593 = 32 << V_2 -> V_595 ;
else
V_593 = 0 ;
V_14 -> V_103 . V_352 . V_596 ( V_14 , V_127 , V_593 , V_597 ) ;
F_303 ( V_2 ) ;
}
static void F_305 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_598 * V_599 ;
struct V_600 * V_601 ;
F_306 ( & V_2 -> V_602 ) ;
if ( ! F_307 ( & V_2 -> V_603 ) )
F_308 ( V_14 , & V_2 -> V_604 ) ;
F_309 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_310 ( V_14 ,
& V_601 -> V_601 ,
V_601 -> V_605 ,
( V_601 -> V_606 == V_607 ) ?
V_607 :
V_2 -> V_62 [ V_601 -> V_606 ] -> V_142 ) ;
}
F_311 ( & V_2 -> V_602 ) ;
}
static void F_312 ( struct V_49 * V_68 , unsigned int V_477 ,
struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_555 ;
V_555 = F_26 ( V_14 , F_280 ( V_477 ) ) ;
V_555 |= ( V_573 | V_556 | V_557 ) ;
V_555 &= ~ V_569 ;
if ( V_68 -> V_132 & V_571 ) {
V_555 |= V_569 ;
} else {
V_555 |= V_573 ;
V_14 -> V_103 . V_352 . V_572 ( V_14 , V_68 ) ;
}
F_274 ( V_2 -> V_50 ) ;
F_60 ( V_14 , F_280 ( V_477 ) , V_555 ) ;
}
static void F_313 ( struct V_1 * V_2 ,
T_6 * V_551 , T_2 V_477 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
unsigned int V_399 ;
V_399 = V_14 -> V_103 . V_545 - V_477 ;
V_14 -> V_103 . V_352 . V_550 ( V_14 , V_399 , V_551 , F_257 ( V_477 ) , V_552 ) ;
}
static void F_314 ( struct V_608 * V_609 )
{
struct V_1 * V_2 = V_609 -> V_141 ;
int V_451 = V_2 -> V_610 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
T_2 V_477 = V_609 -> V_477 ;
T_1 V_478 = V_479 |
V_480 |
V_481 |
V_482 |
V_483 ;
if ( V_14 -> V_103 . type == V_104 )
return;
if ( V_451 > 3 )
V_478 |= 2 << 29 ;
else if ( V_451 > 1 )
V_478 |= 1 << 29 ;
F_60 ( V_14 , F_256 ( F_257 ( V_477 ) ) , V_478 ) ;
}
static void F_315 ( struct V_52 * V_62 )
{
struct V_184 * V_68 = V_62 -> V_68 ;
unsigned long V_291 ;
T_2 V_43 ;
if ( ! V_62 -> V_66 )
return;
for ( V_43 = 0 ; V_43 < V_62 -> V_83 ; V_43 ++ ) {
struct V_65 * V_290 ;
V_290 = & V_62 -> V_66 [ V_43 ] ;
if ( V_290 -> V_84 ) {
struct V_189 * V_84 = V_290 -> V_84 ;
if ( F_143 ( V_84 ) -> V_283 ) {
F_69 ( V_68 ,
F_143 ( V_84 ) -> V_76 ,
F_58 ( V_62 ) ,
V_221 ) ;
F_143 ( V_84 ) -> V_283 = false ;
}
F_316 ( V_84 ) ;
}
V_290 -> V_84 = NULL ;
if ( V_290 -> V_76 )
F_69 ( V_68 , V_290 -> V_76 ,
F_130 ( V_62 ) ,
V_221 ) ;
V_290 -> V_76 = 0 ;
if ( V_290 -> V_93 )
F_132 ( V_290 -> V_93 ,
F_128 ( V_62 ) ) ;
V_290 -> V_93 = NULL ;
}
V_291 = sizeof( struct V_65 ) * V_62 -> V_83 ;
memset ( V_62 -> V_66 , 0 , V_291 ) ;
memset ( V_62 -> V_82 , 0 , V_62 -> V_291 ) ;
V_62 -> V_215 = 0 ;
V_62 -> V_74 = 0 ;
V_62 -> V_75 = 0 ;
}
static void F_317 ( struct V_608 * V_609 ,
struct V_52 * V_62 )
{
struct V_1 * V_2 = V_609 -> V_141 ;
int V_102 = V_62 -> V_81 + V_609 -> V_611 ;
F_251 ( V_2 , V_62 ) ;
F_237 ( 10000 , 20000 ) ;
F_206 ( V_2 , ( ( T_4 ) 1 << V_102 ) ) ;
F_315 ( V_62 ) ;
V_62 -> V_140 = NULL ;
}
static int F_318 ( struct V_49 * V_612 ,
struct V_608 * V_613 )
{
struct V_1 * V_2 = V_613 -> V_141 ;
unsigned int V_614 = V_613 -> V_611 ;
unsigned int V_615 = V_613 -> V_616 ;
int V_43 ;
F_319 ( V_612 ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_610 ; V_43 ++ ) {
F_317 ( V_613 , V_2 -> V_62 [ V_614 + V_43 ] ) ;
V_2 -> V_62 [ V_614 + V_43 ] -> V_50 = V_2 -> V_50 ;
}
for ( V_43 = 0 ; V_43 < V_2 -> V_610 ; V_43 ++ ) {
V_2 -> V_53 [ V_615 + V_43 ] -> V_140 = NULL ;
V_2 -> V_53 [ V_615 + V_43 ] -> V_50 = V_2 -> V_50 ;
}
return 0 ;
}
static int F_320 ( struct V_49 * V_612 ,
struct V_608 * V_613 )
{
struct V_1 * V_2 = V_613 -> V_141 ;
unsigned int V_614 , V_615 , V_371 ;
int V_43 , V_617 , V_16 = 0 ;
if ( ! F_13 ( V_613 -> V_477 , & V_2 -> V_618 ) )
return 0 ;
V_617 = V_613 -> V_477 * V_2 -> V_610 ;
F_321 ( V_612 , L_94 ,
V_613 -> V_477 , V_2 -> V_619 ,
V_617 , V_617 + V_2 -> V_610 ,
V_2 -> V_618 ) ;
V_613 -> V_50 = V_612 ;
V_613 -> V_611 = V_614 = V_617 ;
V_613 -> V_616 = V_615 = V_617 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_610 ; V_43 ++ )
F_317 ( V_613 , V_2 -> V_62 [ V_614 + V_43 ] ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_610 ; V_43 ++ ) {
V_2 -> V_62 [ V_614 + V_43 ] -> V_50 = V_612 ;
V_2 -> V_62 [ V_614 + V_43 ] -> V_140 = V_613 ;
F_253 ( V_2 , V_2 -> V_62 [ V_614 + V_43 ] ) ;
}
for ( V_43 = 0 ; V_43 < V_2 -> V_610 ; V_43 ++ ) {
V_2 -> V_53 [ V_615 + V_43 ] -> V_50 = V_612 ;
V_2 -> V_53 [ V_615 + V_43 ] -> V_140 = V_613 ;
}
V_371 = F_322 (unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues) ;
V_16 = F_323 ( V_612 , V_371 ) ;
if ( V_16 )
goto V_620;
V_16 = F_324 ( V_612 , V_371 ) ;
if ( V_16 )
goto V_620;
if ( F_325 ( V_612 -> V_621 ) )
F_313 ( V_2 , V_612 -> V_621 , V_613 -> V_477 ) ;
F_314 ( V_613 ) ;
F_312 ( V_612 , V_613 -> V_477 , V_2 ) ;
return V_16 ;
V_620:
F_318 ( V_612 , V_613 ) ;
return V_16 ;
}
static void F_326 ( struct V_1 * V_2 )
{
struct V_49 * V_90 ;
struct V_622 * V_623 ;
int V_16 ;
F_327 (adapter->netdev, upper, iter) {
if ( F_328 ( V_90 ) ) {
struct V_624 * V_625 = F_78 ( V_90 ) ;
struct V_608 * V_609 = V_625 -> V_626 ;
if ( V_625 -> V_626 ) {
V_16 = F_320 ( V_90 , V_609 ) ;
if ( V_16 )
continue;
}
}
}
}
static void F_329 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
F_304 ( V_2 ) ;
#ifdef F_330
F_287 ( V_2 ) ;
#endif
F_258 ( V_2 ) ;
F_278 ( V_2 -> V_50 ) ;
F_273 ( V_2 ) ;
switch ( V_14 -> V_103 . type ) {
case V_106 :
case V_107 :
V_14 -> V_103 . V_352 . V_627 ( V_14 ) ;
break;
default:
break;
}
if ( V_2 -> V_132 & V_379 ) {
F_331 ( & V_2 -> V_14 ,
V_2 -> V_595 ) ;
} else if ( V_2 -> V_132 & V_594 ) {
F_332 ( & V_2 -> V_14 ,
V_2 -> V_595 ) ;
F_305 ( V_2 ) ;
}
switch ( V_14 -> V_103 . type ) {
case V_106 :
case V_107 :
V_14 -> V_103 . V_352 . V_628 ( V_14 ) ;
break;
default:
break;
}
#ifdef F_138
F_333 ( V_2 ) ;
#endif
F_240 ( V_2 ) ;
F_266 ( V_2 ) ;
F_326 ( V_2 ) ;
}
static inline bool F_334 ( struct V_13 * V_14 )
{
switch ( V_14 -> V_355 . type ) {
case V_629 :
case V_630 :
case V_631 :
case V_632 :
case V_633 :
case V_634 :
case V_635 :
case V_636 :
case V_637 :
case V_638 :
case V_639 :
case V_640 :
return true ;
case V_641 :
if ( V_14 -> V_103 . type == V_104 )
return true ;
default:
return false ;
}
}
static void F_335 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_103 . type == V_104 )
V_2 -> V_148 |= V_642 ;
V_2 -> V_148 |= V_363 ;
}
static int F_336 ( struct V_13 * V_14 )
{
T_1 V_19 ;
bool V_643 , V_354 = false ;
T_1 V_147 = V_644 ;
if ( V_14 -> V_103 . V_352 . V_353 )
V_147 = V_14 -> V_103 . V_352 . V_353 ( V_14 , & V_19 , & V_354 , false ) ;
if ( V_147 )
goto V_645;
V_19 = V_14 -> V_355 . V_646 ;
if ( ( ! V_19 ) && ( V_14 -> V_103 . V_352 . V_647 ) )
V_147 = V_14 -> V_103 . V_352 . V_647 ( V_14 , & V_19 ,
& V_643 ) ;
if ( V_147 )
goto V_645;
if ( V_14 -> V_103 . V_352 . V_648 )
V_147 = V_14 -> V_103 . V_352 . V_648 ( V_14 , V_19 , V_354 ) ;
V_645:
return V_147 ;
}
static void F_337 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_649 = 0 ;
if ( V_2 -> V_132 & V_403 ) {
V_649 = V_650 | V_651 |
V_652 ;
V_649 |= V_653 ;
switch ( V_14 -> V_103 . type ) {
case V_104 :
F_60 ( V_14 , V_654 , V_655 ) ;
break;
case V_106 :
case V_107 :
default:
F_60 ( V_14 , F_338 ( 0 ) , 0xFFFFFFFF ) ;
F_60 ( V_14 , F_338 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_60 ( V_14 , V_654 , V_655 ) ;
}
if ( V_2 -> V_132 & V_424 ) {
V_649 &= ~ V_656 ;
switch ( V_2 -> V_429 [ V_496 ] . V_110 ) {
case V_497 :
V_649 |= V_657 ;
break;
case V_499 :
V_649 |= V_658 ;
break;
default:
V_649 |= V_659 ;
break;
}
}
if ( V_2 -> V_148 & V_347 ) {
switch ( V_2 -> V_14 . V_103 . type ) {
case V_106 :
V_649 |= V_660 ;
break;
case V_107 :
V_649 |= V_374 ;
break;
default:
break;
}
}
if ( V_2 -> V_132 & V_358 )
V_649 |= V_661 ;
if ( V_14 -> V_103 . type == V_106 ) {
V_649 |= V_661 ;
V_649 |= V_662 ;
}
F_60 ( V_14 , V_663 , V_649 ) ;
}
static void F_339 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_49 * V_90 ;
struct V_622 * V_623 ;
int V_16 ;
T_1 V_95 ;
F_61 ( V_2 ) ;
F_337 ( V_2 ) ;
if ( V_2 -> V_132 & V_403 )
F_191 ( V_2 ) ;
else
F_231 ( V_2 ) ;
if ( V_14 -> V_103 . V_352 . V_664 )
V_14 -> V_103 . V_352 . V_664 ( V_14 ) ;
F_22 () ;
F_23 ( V_32 , & V_2 -> V_33 ) ;
F_281 ( V_2 ) ;
if ( F_334 ( V_14 ) ) {
F_335 ( V_2 ) ;
} else {
V_16 = F_336 ( V_14 ) ;
if ( V_16 )
F_92 ( V_166 , L_95 , V_16 ) ;
}
F_26 ( V_14 , V_360 ) ;
F_208 ( V_2 , true , true ) ;
if ( V_2 -> V_132 & V_358 ) {
T_1 V_665 = F_26 ( V_14 , V_666 ) ;
if ( V_665 & V_667 )
F_198 ( V_150 , L_73 ) ;
}
F_340 ( V_2 -> V_50 ) ;
F_327 (adapter->netdev, upper, iter) {
if ( F_328 ( V_90 ) ) {
struct V_624 * V_231 = F_78 ( V_90 ) ;
if ( V_231 -> V_626 )
F_340 ( V_90 ) ;
}
}
V_2 -> V_132 |= V_366 ;
V_2 -> V_367 = V_165 ;
F_341 ( & V_2 -> V_668 , V_165 ) ;
V_95 = F_26 ( V_14 , V_96 ) ;
V_95 |= V_669 ;
F_60 ( V_14 , V_96 , V_95 ) ;
}
void F_342 ( struct V_1 * V_2 )
{
F_343 ( F_344 () ) ;
V_2 -> V_50 -> V_69 = V_165 ;
while ( F_14 ( V_670 , & V_2 -> V_33 ) )
F_237 ( 1000 , 2000 ) ;
F_345 ( V_2 ) ;
if ( V_2 -> V_132 & V_424 )
F_346 ( 2000 ) ;
F_347 ( V_2 ) ;
F_23 ( V_670 , & V_2 -> V_33 ) ;
}
void F_347 ( struct V_1 * V_2 )
{
F_329 ( V_2 ) ;
F_339 ( V_2 ) ;
}
void F_348 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_16 ;
if ( F_250 ( V_14 -> V_38 ) )
return;
while ( F_14 ( V_671 , & V_2 -> V_33 ) )
F_237 ( 1000 , 2000 ) ;
V_2 -> V_148 &= ~ ( V_642 |
V_363 ) ;
V_2 -> V_132 &= ~ V_364 ;
V_16 = V_14 -> V_103 . V_352 . V_672 ( V_14 ) ;
switch ( V_16 ) {
case 0 :
case V_673 :
case V_674 :
break;
case V_675 :
F_17 ( L_96 ) ;
break;
case V_676 :
F_10 ( L_97
L_98
L_99
L_100
L_101
L_102 ) ;
break;
default:
F_17 ( L_103 , V_16 ) ;
}
F_23 ( V_671 , & V_2 -> V_33 ) ;
V_14 -> V_103 . V_352 . V_550 ( V_14 , 0 , V_14 -> V_103 . V_551 , F_257 ( 0 ) , V_552 ) ;
if ( V_14 -> V_103 . V_677 )
V_14 -> V_103 . V_352 . V_678 ( V_14 , F_257 ( 0 ) ) ;
if ( F_13 ( V_679 , & V_2 -> V_33 ) )
F_349 ( V_2 ) ;
}
static void F_350 ( struct V_52 * V_53 )
{
struct V_54 * V_73 ;
unsigned long V_291 ;
T_2 V_43 ;
if ( ! V_53 -> V_73 )
return;
for ( V_43 = 0 ; V_43 < V_53 -> V_83 ; V_43 ++ ) {
V_73 = & V_53 -> V_73 [ V_43 ] ;
F_66 ( V_53 , V_73 ) ;
}
F_351 ( F_96 ( V_53 ) ) ;
V_291 = sizeof( struct V_54 ) * V_53 -> V_83 ;
memset ( V_53 -> V_73 , 0 , V_291 ) ;
memset ( V_53 -> V_82 , 0 , V_53 -> V_291 ) ;
V_53 -> V_75 = 0 ;
V_53 -> V_74 = 0 ;
}
static void F_352 ( struct V_1 * V_2 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_88 ; V_43 ++ )
F_315 ( V_2 -> V_62 [ V_43 ] ) ;
}
static void F_353 ( struct V_1 * V_2 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_72 ; V_43 ++ )
F_350 ( V_2 -> V_53 [ V_43 ] ) ;
}
static void F_354 ( struct V_1 * V_2 )
{
struct V_598 * V_599 ;
struct V_600 * V_601 ;
F_306 ( & V_2 -> V_602 ) ;
F_309 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_355 ( & V_601 -> V_680 ) ;
F_225 ( V_601 ) ;
}
V_2 -> V_681 = 0 ;
F_311 ( & V_2 -> V_602 ) ;
}
void F_345 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = V_2 -> V_50 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_49 * V_90 ;
struct V_622 * V_623 ;
T_1 V_176 ;
int V_43 ;
if ( F_14 ( V_32 , & V_2 -> V_33 ) )
return;
V_176 = F_26 ( V_14 , V_529 ) ;
F_60 ( V_14 , V_529 , V_176 & ~ V_530 ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_88 ; V_43 ++ )
F_251 ( V_2 , V_2 -> V_62 [ V_43 ] ) ;
F_237 ( 10000 , 20000 ) ;
F_319 ( V_50 ) ;
F_356 ( V_50 ) ;
F_357 ( V_50 ) ;
F_327 (adapter->netdev, upper, iter) {
if ( F_328 ( V_90 ) ) {
struct V_624 * V_231 = F_78 ( V_90 ) ;
if ( V_231 -> V_626 ) {
F_319 ( V_90 ) ;
F_356 ( V_90 ) ;
F_357 ( V_90 ) ;
}
}
}
F_229 ( V_2 ) ;
F_284 ( V_2 ) ;
V_2 -> V_148 &= ~ ( V_380 |
V_149 ) ;
V_2 -> V_132 &= ~ V_366 ;
F_358 ( & V_2 -> V_668 ) ;
if ( V_2 -> V_319 ) {
F_60 ( & V_2 -> V_14 , V_321 , 0 ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_319 ; V_43 ++ )
V_2 -> V_504 [ V_43 ] . V_682 = false ;
F_359 ( V_2 ) ;
F_360 ( V_2 ) ;
}
for ( V_43 = 0 ; V_43 < V_2 -> V_72 ; V_43 ++ ) {
T_6 V_142 = V_2 -> V_53 [ V_43 ] -> V_142 ;
F_60 ( V_14 , F_39 ( V_142 ) , V_683 ) ;
}
switch ( V_14 -> V_103 . type ) {
case V_106 :
case V_107 :
F_60 ( V_14 , V_440 ,
( F_26 ( V_14 , V_440 ) &
~ V_441 ) ) ;
break;
default:
break;
}
if ( ! F_361 ( V_2 -> V_9 ) )
F_348 ( V_2 ) ;
if ( V_14 -> V_103 . V_352 . V_684 )
V_14 -> V_103 . V_352 . V_684 ( V_14 ) ;
F_353 ( V_2 ) ;
F_352 ( V_2 ) ;
#ifdef F_216
F_112 ( V_2 ) ;
#endif
}
static void F_362 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_78 ( V_50 ) ;
F_81 ( V_2 ) ;
}
static int F_363 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_195 , V_685 ;
T_1 V_686 ;
#ifdef F_330
int V_44 ;
struct V_687 * V_127 ;
#endif
V_14 -> V_688 = V_9 -> V_689 ;
V_14 -> V_20 = V_9 -> V_184 ;
V_14 -> V_690 = V_9 -> V_691 ;
V_14 -> V_692 = V_9 -> V_693 ;
V_14 -> V_694 = V_9 -> V_695 ;
V_195 = F_322 ( int , V_696 , F_364 () ) ;
V_2 -> V_429 [ V_430 ] . V_697 = V_195 ;
V_2 -> V_148 |= V_698 ;
V_2 -> V_148 |= V_518 ;
V_2 -> V_699 = V_700 ;
V_2 -> V_414 = 20 ;
V_685 = F_322 ( int , V_701 , F_364 () ) ;
V_2 -> V_429 [ V_702 ] . V_697 = V_685 ;
V_2 -> V_595 = V_703 ;
#ifdef F_216
V_2 -> V_132 |= V_186 ;
#endif
#ifdef F_138
V_2 -> V_132 |= V_704 ;
V_2 -> V_132 &= ~ V_510 ;
#ifdef F_330
V_2 -> V_705 . V_706 = V_707 ;
#endif
#endif
switch ( V_14 -> V_103 . type ) {
case V_104 :
V_2 -> V_148 &= ~ V_698 ;
V_2 -> V_148 &= ~ V_518 ;
if ( V_14 -> V_20 == V_708 )
V_2 -> V_132 |= V_358 ;
V_2 -> V_699 = V_709 ;
V_2 -> V_429 [ V_702 ] . V_697 = 0 ;
V_2 -> V_414 = 0 ;
V_2 -> V_595 = 0 ;
#ifdef F_138
V_2 -> V_132 &= ~ V_704 ;
V_2 -> V_132 &= ~ V_510 ;
#ifdef F_330
V_2 -> V_705 . V_706 = 0 ;
#endif
#endif
break;
case V_106 :
if ( V_14 -> V_20 == V_349 )
V_2 -> V_148 |= V_347 ;
break;
case V_107 :
V_686 = F_26 ( V_14 , V_710 ) ;
if ( V_686 & V_711 )
V_2 -> V_148 |= V_347 ;
break;
default:
break;
}
#ifdef F_138
F_365 ( & V_2 -> V_705 . V_712 ) ;
#endif
F_365 ( & V_2 -> V_602 ) ;
#ifdef F_330
switch ( V_14 -> V_103 . type ) {
case V_107 :
V_2 -> V_129 . V_713 . V_714 = V_715 ;
V_2 -> V_129 . V_713 . V_716 = V_715 ;
break;
default:
V_2 -> V_129 . V_713 . V_714 = V_717 ;
V_2 -> V_129 . V_713 . V_716 = V_717 ;
break;
}
for ( V_44 = 0 ; V_44 < V_717 ; V_44 ++ ) {
V_127 = & V_2 -> V_129 . V_718 [ V_44 ] ;
V_127 -> V_719 [ V_578 ] . V_720 = 0 ;
V_127 -> V_719 [ V_578 ] . V_721 = 12 + ( V_44 & 1 ) ;
V_127 -> V_719 [ V_579 ] . V_720 = 0 ;
V_127 -> V_719 [ V_579 ] . V_721 = 12 + ( V_44 & 1 ) ;
V_127 -> V_722 = V_723 ;
}
V_127 = & V_2 -> V_129 . V_718 [ 0 ] ;
V_127 -> V_719 [ V_578 ] . V_724 = 0xFF ;
V_127 -> V_719 [ V_579 ] . V_724 = 0xFF ;
V_2 -> V_129 . V_725 [ V_578 ] [ 0 ] = 100 ;
V_2 -> V_129 . V_725 [ V_579 ] [ 0 ] = 100 ;
V_2 -> V_129 . V_130 = false ;
V_2 -> V_726 = 0x00 ;
V_2 -> V_576 = V_727 | V_577 ;
memcpy ( & V_2 -> V_728 , & V_2 -> V_129 ,
sizeof( V_2 -> V_728 ) ) ;
#endif
V_14 -> V_118 . V_729 = V_120 ;
V_14 -> V_118 . V_119 = V_120 ;
F_303 ( V_2 ) ;
V_14 -> V_118 . V_730 = V_731 ;
V_14 -> V_118 . V_732 = true ;
V_14 -> V_118 . V_733 = F_366 ( V_14 ) ;
#ifdef F_367
if ( V_734 > 0 )
F_10 ( L_104 ) ;
if ( V_14 -> V_103 . type != V_104 ) {
if ( V_734 > V_735 ) {
V_2 -> V_319 = 0 ;
F_10 ( L_105 ) ;
} else {
V_2 -> V_319 = V_734 ;
}
}
#endif
V_2 -> V_394 = 1 ;
V_2 -> V_736 = 1 ;
V_2 -> V_737 = V_738 ;
V_2 -> V_739 = V_740 ;
V_2 -> V_741 = V_742 ;
if ( F_368 ( V_14 ) ) {
F_17 ( L_106 ) ;
return - V_743 ;
}
F_235 ( 0 , & V_2 -> V_618 ) ;
F_235 ( V_32 , & V_2 -> V_33 ) ;
return 0 ;
}
int F_369 ( struct V_52 * V_53 )
{
struct V_184 * V_68 = V_53 -> V_68 ;
int V_744 = F_370 ( V_68 ) ;
int V_745 = - 1 ;
int V_291 ;
V_291 = sizeof( struct V_54 ) * V_53 -> V_83 ;
if ( V_53 -> V_152 )
V_745 = V_53 -> V_152 -> V_745 ;
V_53 -> V_73 = F_371 ( V_291 , V_745 ) ;
if ( ! V_53 -> V_73 )
V_53 -> V_73 = F_372 ( V_291 ) ;
if ( ! V_53 -> V_73 )
goto V_16;
F_373 ( & V_53 -> V_163 ) ;
V_53 -> V_291 = V_53 -> V_83 * sizeof( union V_56 ) ;
V_53 -> V_291 = F_161 ( V_53 -> V_291 , 4096 ) ;
F_374 ( V_68 , V_745 ) ;
V_53 -> V_82 = F_375 ( V_68 ,
V_53 -> V_291 ,
& V_53 -> V_76 ,
V_746 ) ;
F_374 ( V_68 , V_744 ) ;
if ( ! V_53 -> V_82 )
V_53 -> V_82 = F_375 ( V_68 , V_53 -> V_291 ,
& V_53 -> V_76 , V_746 ) ;
if ( ! V_53 -> V_82 )
goto V_16;
V_53 -> V_75 = 0 ;
V_53 -> V_74 = 0 ;
return 0 ;
V_16:
F_376 ( V_53 -> V_73 ) ;
V_53 -> V_73 = NULL ;
F_377 ( V_68 , L_107 ) ;
return - V_547 ;
}
static int F_378 ( struct V_1 * V_2 )
{
int V_43 , V_16 = 0 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_72 ; V_43 ++ ) {
V_16 = F_369 ( V_2 -> V_53 [ V_43 ] ) ;
if ( ! V_16 )
continue;
F_92 ( V_166 , L_108 , V_43 ) ;
goto V_747;
}
return 0 ;
V_747:
while ( V_43 -- )
F_379 ( V_2 -> V_53 [ V_43 ] ) ;
return V_16 ;
}
int F_380 ( struct V_52 * V_62 )
{
struct V_184 * V_68 = V_62 -> V_68 ;
int V_744 = F_370 ( V_68 ) ;
int V_745 = - 1 ;
int V_291 ;
V_291 = sizeof( struct V_65 ) * V_62 -> V_83 ;
if ( V_62 -> V_152 )
V_745 = V_62 -> V_152 -> V_745 ;
V_62 -> V_66 = F_371 ( V_291 , V_745 ) ;
if ( ! V_62 -> V_66 )
V_62 -> V_66 = F_372 ( V_291 ) ;
if ( ! V_62 -> V_66 )
goto V_16;
F_373 ( & V_62 -> V_163 ) ;
V_62 -> V_291 = V_62 -> V_83 * sizeof( union V_63 ) ;
V_62 -> V_291 = F_161 ( V_62 -> V_291 , 4096 ) ;
F_374 ( V_68 , V_745 ) ;
V_62 -> V_82 = F_375 ( V_68 ,
V_62 -> V_291 ,
& V_62 -> V_76 ,
V_746 ) ;
F_374 ( V_68 , V_744 ) ;
if ( ! V_62 -> V_82 )
V_62 -> V_82 = F_375 ( V_68 , V_62 -> V_291 ,
& V_62 -> V_76 , V_746 ) ;
if ( ! V_62 -> V_82 )
goto V_16;
V_62 -> V_74 = 0 ;
V_62 -> V_75 = 0 ;
return 0 ;
V_16:
F_376 ( V_62 -> V_66 ) ;
V_62 -> V_66 = NULL ;
F_377 ( V_68 , L_109 ) ;
return - V_547 ;
}
static int F_381 ( struct V_1 * V_2 )
{
int V_43 , V_16 = 0 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_88 ; V_43 ++ ) {
V_16 = F_380 ( V_2 -> V_62 [ V_43 ] ) ;
if ( ! V_16 )
continue;
F_92 ( V_166 , L_110 , V_43 ) ;
goto V_748;
}
#ifdef F_138
V_16 = F_382 ( V_2 ) ;
if ( ! V_16 )
#endif
return 0 ;
V_748:
while ( V_43 -- )
F_383 ( V_2 -> V_62 [ V_43 ] ) ;
return V_16 ;
}
void F_379 ( struct V_52 * V_53 )
{
F_350 ( V_53 ) ;
F_376 ( V_53 -> V_73 ) ;
V_53 -> V_73 = NULL ;
if ( ! V_53 -> V_82 )
return;
F_384 ( V_53 -> V_68 , V_53 -> V_291 ,
V_53 -> V_82 , V_53 -> V_76 ) ;
V_53 -> V_82 = NULL ;
}
static void F_385 ( struct V_1 * V_2 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_72 ; V_43 ++ )
if ( V_2 -> V_53 [ V_43 ] -> V_82 )
F_379 ( V_2 -> V_53 [ V_43 ] ) ;
}
void F_383 ( struct V_52 * V_62 )
{
F_315 ( V_62 ) ;
F_376 ( V_62 -> V_66 ) ;
V_62 -> V_66 = NULL ;
if ( ! V_62 -> V_82 )
return;
F_384 ( V_62 -> V_68 , V_62 -> V_291 ,
V_62 -> V_82 , V_62 -> V_76 ) ;
V_62 -> V_82 = NULL ;
}
static void F_386 ( struct V_1 * V_2 )
{
int V_43 ;
#ifdef F_138
F_387 ( V_2 ) ;
#endif
for ( V_43 = 0 ; V_43 < V_2 -> V_88 ; V_43 ++ )
if ( V_2 -> V_62 [ V_43 ] -> V_82 )
F_383 ( V_2 -> V_62 [ V_43 ] ) ;
}
static int F_388 ( struct V_49 * V_50 , int V_749 )
{
struct V_1 * V_2 = F_78 ( V_50 ) ;
int V_506 = V_749 + V_240 + V_507 ;
if ( ( V_749 < 68 ) || ( V_506 > V_750 ) )
return - V_751 ;
if ( ( V_2 -> V_132 & V_424 ) &&
( V_2 -> V_14 . V_103 . type == V_106 ) &&
( V_506 > ( V_512 + V_507 ) ) )
F_82 ( V_166 , L_111 ) ;
F_94 ( V_166 , L_112 , V_50 -> V_307 , V_749 ) ;
V_50 -> V_307 = V_749 ;
if ( F_46 ( V_50 ) )
F_342 ( V_2 ) ;
return 0 ;
}
static int F_389 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_78 ( V_50 ) ;
int V_16 , V_371 ;
if ( F_13 ( V_752 , & V_2 -> V_33 ) )
return - V_753 ;
F_356 ( V_50 ) ;
V_16 = F_378 ( V_2 ) ;
if ( V_16 )
goto V_747;
V_16 = F_381 ( V_2 ) ;
if ( V_16 )
goto V_748;
F_329 ( V_2 ) ;
V_16 = F_227 ( V_2 ) ;
if ( V_16 )
goto V_754;
if ( V_2 -> V_619 > 1 )
V_371 = V_2 -> V_610 ;
else
V_371 = V_2 -> V_72 ;
V_16 = F_323 ( V_50 , V_371 ) ;
if ( V_16 )
goto V_755;
if ( V_2 -> V_619 > 1 &&
V_2 -> V_88 > V_756 )
V_371 = V_756 ;
else
V_371 = V_2 -> V_88 ;
V_16 = F_324 ( V_50 , V_371 ) ;
if ( V_16 )
goto V_755;
F_390 ( V_2 ) ;
F_339 ( V_2 ) ;
return 0 ;
V_755:
F_228 ( V_2 ) ;
V_754:
F_386 ( V_2 ) ;
V_748:
F_385 ( V_2 ) ;
V_747:
F_348 ( V_2 ) ;
return V_16 ;
}
static int F_391 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_78 ( V_50 ) ;
F_392 ( V_2 ) ;
F_345 ( V_2 ) ;
F_228 ( V_2 ) ;
F_354 ( V_2 ) ;
F_385 ( V_2 ) ;
F_386 ( V_2 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
static int F_393 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_394 ( V_9 ) ;
struct V_49 * V_50 = V_2 -> V_50 ;
T_1 V_16 ;
F_395 ( V_9 , V_757 ) ;
F_396 ( V_9 ) ;
F_397 ( V_9 ) ;
V_16 = F_398 ( V_9 ) ;
if ( V_16 ) {
F_17 ( L_113 ) ;
return V_16 ;
}
F_399 ( V_9 ) ;
F_400 ( V_9 , false ) ;
F_348 ( V_2 ) ;
F_60 ( & V_2 -> V_14 , V_758 , ~ 0 ) ;
F_401 () ;
V_16 = F_402 ( V_2 ) ;
if ( ! V_16 && F_46 ( V_50 ) )
V_16 = F_389 ( V_50 ) ;
F_403 () ;
if ( V_16 )
return V_16 ;
F_404 ( V_50 ) ;
return 0 ;
}
static int F_405 ( struct V_5 * V_9 , bool * V_759 )
{
struct V_1 * V_2 = F_394 ( V_9 ) ;
struct V_49 * V_50 = V_2 -> V_50 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_760 , V_554 ;
T_1 V_761 = V_2 -> V_762 ;
#ifdef F_406
int V_763 = 0 ;
#endif
F_407 ( V_50 ) ;
F_401 () ;
if ( F_46 ( V_50 ) ) {
F_345 ( V_2 ) ;
F_228 ( V_2 ) ;
F_385 ( V_2 ) ;
F_386 ( V_2 ) ;
}
F_403 () ;
F_408 ( V_2 ) ;
#ifdef F_406
V_763 = F_397 ( V_9 ) ;
if ( V_763 )
return V_763 ;
#endif
if ( V_14 -> V_103 . V_352 . V_764 )
V_14 -> V_103 . V_352 . V_764 ( V_14 ) ;
if ( V_761 ) {
F_278 ( V_50 ) ;
if ( V_14 -> V_103 . V_352 . V_664 )
V_14 -> V_103 . V_352 . V_664 ( V_14 ) ;
if ( V_761 & V_765 ) {
V_554 = F_26 ( V_14 , V_558 ) ;
V_554 |= V_564 ;
F_60 ( V_14 , V_558 , V_554 ) ;
}
V_760 = F_26 ( V_14 , V_766 ) ;
V_760 |= V_767 ;
F_60 ( V_14 , V_766 , V_760 ) ;
F_60 ( V_14 , V_768 , V_761 ) ;
} else {
F_60 ( V_14 , V_769 , 0 ) ;
F_60 ( V_14 , V_768 , 0 ) ;
}
switch ( V_14 -> V_103 . type ) {
case V_104 :
F_400 ( V_9 , false ) ;
break;
case V_106 :
case V_107 :
F_400 ( V_9 , ! ! V_761 ) ;
break;
default:
break;
}
* V_759 = ! ! V_761 ;
F_59 ( V_2 ) ;
F_409 ( V_9 ) ;
return 0 ;
}
static int F_410 ( struct V_5 * V_9 , T_12 V_33 )
{
int V_763 ;
bool V_770 ;
V_763 = F_405 ( V_9 , & V_770 ) ;
if ( V_763 )
return V_763 ;
if ( V_770 ) {
F_411 ( V_9 ) ;
} else {
F_400 ( V_9 , false ) ;
F_395 ( V_9 , V_771 ) ;
}
return 0 ;
}
static void F_412 ( struct V_5 * V_9 )
{
bool V_770 ;
F_405 ( V_9 , & V_770 ) ;
if ( V_772 == V_773 ) {
F_400 ( V_9 , V_770 ) ;
F_395 ( V_9 , V_771 ) ;
}
}
void F_413 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = V_2 -> V_50 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_115 * V_116 = & V_2 -> V_117 ;
T_4 V_774 = 0 ;
T_1 V_43 , V_775 = 0 , V_776 , V_777 , V_778 , V_779 , V_780 ;
T_4 V_275 = 0 , V_168 = 0 , V_781 = 0 ;
T_4 V_220 = 0 , V_300 = 0 ;
T_4 V_164 = 0 , V_137 = 0 , V_782 = 0 ;
if ( F_13 ( V_32 , & V_2 -> V_33 ) ||
F_13 ( V_670 , & V_2 -> V_33 ) )
return;
if ( V_2 -> V_148 & V_518 ) {
T_4 V_260 = 0 ;
T_4 V_261 = 0 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_88 ; V_43 ++ ) {
V_260 += V_2 -> V_62 [ V_43 ] -> V_206 . V_260 ;
V_261 += V_2 -> V_62 [ V_43 ] -> V_206 . V_261 ;
}
V_2 -> V_783 = V_260 ;
V_2 -> V_784 = V_261 ;
}
for ( V_43 = 0 ; V_43 < V_2 -> V_88 ; V_43 ++ ) {
struct V_52 * V_62 = V_2 -> V_62 [ V_43 ] ;
V_275 += V_62 -> V_206 . V_275 ;
V_220 += V_62 -> V_206 . V_220 ;
V_300 += V_62 -> V_206 . V_300 ;
V_782 += V_62 -> V_206 . V_207 ;
V_164 += V_62 -> V_117 . V_164 ;
V_137 += V_62 -> V_117 . V_137 ;
}
V_2 -> V_275 = V_275 ;
V_2 -> V_220 = V_220 ;
V_2 -> V_300 = V_300 ;
V_2 -> V_782 = V_782 ;
V_50 -> V_117 . V_785 = V_164 ;
V_50 -> V_117 . V_786 = V_137 ;
V_164 = 0 ;
V_137 = 0 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_72 ; V_43 ++ ) {
struct V_52 * V_53 = V_2 -> V_53 [ V_43 ] ;
V_168 += V_53 -> V_145 . V_168 ;
V_781 += V_53 -> V_145 . V_781 ;
V_164 += V_53 -> V_117 . V_164 ;
V_137 += V_53 -> V_117 . V_137 ;
}
V_2 -> V_168 = V_168 ;
V_2 -> V_781 = V_781 ;
V_50 -> V_117 . V_787 = V_164 ;
V_50 -> V_117 . V_788 = V_137 ;
V_116 -> V_789 += F_26 ( V_14 , V_790 ) ;
for ( V_43 = 0 ; V_43 < 8 ; V_43 ++ ) {
V_776 = F_26 ( V_14 , F_414 ( V_43 ) ) ;
V_775 += V_776 ;
V_116 -> V_776 [ V_43 ] += V_776 ;
V_774 += V_116 -> V_776 [ V_43 ] ;
V_116 -> V_791 [ V_43 ] += F_26 ( V_14 , F_415 ( V_43 ) ) ;
V_116 -> V_792 [ V_43 ] += F_26 ( V_14 , F_416 ( V_43 ) ) ;
switch ( V_14 -> V_103 . type ) {
case V_104 :
V_116 -> V_793 [ V_43 ] += F_26 ( V_14 , F_417 ( V_43 ) ) ;
V_116 -> V_794 [ V_43 ] += F_26 ( V_14 , F_418 ( V_43 ) ) ;
V_116 -> V_795 [ V_43 ] += F_26 ( V_14 , F_419 ( V_43 ) ) ;
V_116 -> V_796 [ V_43 ] +=
F_26 ( V_14 , F_420 ( V_43 ) ) ;
break;
case V_106 :
case V_107 :
V_116 -> V_796 [ V_43 ] +=
F_26 ( V_14 , F_421 ( V_43 ) ) ;
break;
default:
break;
}
}
for ( V_43 = 0 ; V_43 < 16 ; V_43 ++ ) {
V_116 -> V_797 [ V_43 ] += F_26 ( V_14 , F_422 ( V_43 ) ) ;
V_116 -> V_798 [ V_43 ] += F_26 ( V_14 , F_423 ( V_43 ) ) ;
if ( ( V_14 -> V_103 . type == V_106 ) ||
( V_14 -> V_103 . type == V_107 ) ) {
V_116 -> V_794 [ V_43 ] += F_26 ( V_14 , F_424 ( V_43 ) ) ;
F_26 ( V_14 , F_425 ( V_43 ) ) ;
V_116 -> V_795 [ V_43 ] += F_26 ( V_14 , F_426 ( V_43 ) ) ;
F_26 ( V_14 , F_427 ( V_43 ) ) ;
}
}
V_116 -> V_799 += F_26 ( V_14 , V_800 ) ;
V_116 -> V_799 -= V_775 ;
F_72 ( V_2 ) ;
switch ( V_14 -> V_103 . type ) {
case V_104 :
V_116 -> V_801 += F_26 ( V_14 , V_802 ) ;
V_116 -> V_803 += F_26 ( V_14 , V_804 ) ;
V_116 -> V_805 += F_26 ( V_14 , V_806 ) ;
V_116 -> V_807 += F_26 ( V_14 , V_808 ) ;
break;
case V_107 :
V_116 -> V_809 += F_26 ( V_14 , V_810 ) ;
V_116 -> V_811 += F_26 ( V_14 , V_812 ) ;
V_116 -> V_813 += F_26 ( V_14 , V_814 ) ;
V_116 -> V_815 += F_26 ( V_14 , V_816 ) ;
case V_106 :
for ( V_43 = 0 ; V_43 < 16 ; V_43 ++ )
V_2 -> V_817 +=
F_26 ( V_14 , F_428 ( V_43 ) ) ;
V_116 -> V_803 += F_26 ( V_14 , V_818 ) ;
F_26 ( V_14 , V_804 ) ;
V_116 -> V_805 += F_26 ( V_14 , V_819 ) ;
F_26 ( V_14 , V_806 ) ;
V_116 -> V_807 += F_26 ( V_14 , V_820 ) ;
F_26 ( V_14 , V_808 ) ;
V_116 -> V_801 += F_26 ( V_14 , V_821 ) ;
V_116 -> V_822 += F_26 ( V_14 , V_823 ) ;
V_116 -> V_824 += F_26 ( V_14 , V_825 ) ;
#ifdef F_138
V_116 -> V_826 += F_26 ( V_14 , V_827 ) ;
V_116 -> V_828 += F_26 ( V_14 , V_829 ) ;
V_116 -> V_830 += F_26 ( V_14 , V_831 ) ;
V_116 -> V_832 += F_26 ( V_14 , V_833 ) ;
V_116 -> V_834 += F_26 ( V_14 , V_835 ) ;
V_116 -> V_836 += F_26 ( V_14 , V_837 ) ;
if ( V_2 -> V_705 . V_838 ) {
struct V_839 * V_705 = & V_2 -> V_705 ;
struct V_840 * V_838 ;
unsigned int V_169 ;
T_4 V_841 = 0 , V_842 = 0 ;
F_429 (cpu) {
V_838 = F_430 ( V_705 -> V_838 , V_169 ) ;
V_841 += V_838 -> V_841 ;
V_842 += V_838 -> V_842 ;
}
V_116 -> V_843 = V_841 ;
V_116 -> V_844 = V_842 ;
}
#endif
break;
default:
break;
}
V_777 = F_26 ( V_14 , V_845 ) ;
V_116 -> V_777 += V_777 ;
V_116 -> V_846 += F_26 ( V_14 , V_847 ) ;
if ( V_14 -> V_103 . type == V_104 )
V_116 -> V_846 -= V_777 ;
V_116 -> V_848 += F_26 ( V_14 , V_849 ) ;
V_116 -> V_850 += F_26 ( V_14 , V_851 ) ;
V_116 -> V_852 += F_26 ( V_14 , V_853 ) ;
V_116 -> V_854 += F_26 ( V_14 , V_855 ) ;
V_116 -> V_856 += F_26 ( V_14 , V_857 ) ;
V_116 -> V_858 += F_26 ( V_14 , V_859 ) ;
V_116 -> V_860 += F_26 ( V_14 , V_861 ) ;
V_116 -> V_862 += F_26 ( V_14 , V_863 ) ;
V_778 = F_26 ( V_14 , V_864 ) ;
V_116 -> V_865 += V_778 ;
V_779 = F_26 ( V_14 , V_866 ) ;
V_116 -> V_867 += V_779 ;
V_116 -> V_868 += F_26 ( V_14 , V_869 ) ;
V_116 -> V_870 += F_26 ( V_14 , V_871 ) ;
V_780 = V_778 + V_779 ;
V_116 -> V_868 -= V_780 ;
V_116 -> V_870 -= V_780 ;
V_116 -> V_805 -= ( V_780 * ( V_872 + V_507 ) ) ;
V_116 -> V_873 += F_26 ( V_14 , V_874 ) ;
V_116 -> V_875 += F_26 ( V_14 , V_876 ) ;
V_116 -> V_877 += F_26 ( V_14 , V_878 ) ;
V_116 -> V_879 += F_26 ( V_14 , V_880 ) ;
V_116 -> V_881 += F_26 ( V_14 , V_882 ) ;
V_116 -> V_881 -= V_780 ;
V_116 -> V_883 += F_26 ( V_14 , V_884 ) ;
V_116 -> V_885 += F_26 ( V_14 , V_886 ) ;
V_116 -> V_887 += F_26 ( V_14 , V_888 ) ;
V_116 -> V_889 += F_26 ( V_14 , V_890 ) ;
V_116 -> V_891 += F_26 ( V_14 , V_892 ) ;
V_116 -> V_893 += F_26 ( V_14 , V_894 ) ;
V_50 -> V_117 . V_895 = V_116 -> V_846 ;
V_50 -> V_117 . V_896 = V_116 -> V_789 + V_116 -> V_862 ;
V_50 -> V_117 . V_897 = 0 ;
V_50 -> V_117 . V_898 = V_116 -> V_862 ;
V_50 -> V_117 . V_899 = V_116 -> V_789 ;
V_50 -> V_117 . V_900 = V_774 ;
}
static void F_431 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_43 ;
if ( ! ( V_2 -> V_148 & V_380 ) )
return;
V_2 -> V_148 &= ~ V_380 ;
if ( F_13 ( V_32 , & V_2 -> V_33 ) )
return;
if ( ! ( V_2 -> V_132 & V_379 ) )
return;
V_2 -> V_901 ++ ;
if ( F_432 ( V_14 ) == 0 ) {
for ( V_43 = 0 ; V_43 < V_2 -> V_72 ; V_43 ++ )
F_235 ( V_388 ,
& ( V_2 -> V_53 [ V_43 ] -> V_33 ) ) ;
F_60 ( V_14 , V_370 , V_381 ) ;
} else {
F_92 ( V_166 , L_114
L_115 ) ;
}
}
static void F_433 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_4 V_902 = 0 ;
int V_43 ;
if ( F_13 ( V_32 , & V_2 -> V_33 ) ||
F_13 ( V_34 , & V_2 -> V_33 ) ||
F_13 ( V_670 , & V_2 -> V_33 ) )
return;
if ( F_98 ( V_2 -> V_50 ) ) {
for ( V_43 = 0 ; V_43 < V_2 -> V_72 ; V_43 ++ )
F_434 ( V_2 -> V_53 [ V_43 ] ) ;
}
if ( ! ( V_2 -> V_132 & V_403 ) ) {
F_60 ( V_14 , V_112 ,
( V_903 | V_904 ) ) ;
} else {
for ( V_43 = 0 ; V_43 < V_2 -> V_183 ; V_43 ++ ) {
struct V_151 * V_905 = V_2 -> V_152 [ V_43 ] ;
if ( V_905 -> V_311 . V_113 || V_905 -> V_156 . V_113 )
V_902 |= ( ( T_4 ) 1 << V_43 ) ;
}
}
F_64 ( V_2 , V_902 ) ;
}
static void F_435 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_906 = V_2 -> V_906 ;
bool V_354 = V_2 -> V_354 ;
bool V_128 = V_2 -> V_129 . V_130 ;
if ( ! ( V_2 -> V_132 & V_366 ) )
return;
if ( V_14 -> V_103 . V_352 . V_353 ) {
V_14 -> V_103 . V_352 . V_353 ( V_14 , & V_906 , & V_354 , false ) ;
} else {
V_906 = V_907 ;
V_354 = true ;
}
if ( V_2 -> V_131 )
V_128 |= ! ! ( V_2 -> V_131 -> V_128 ) ;
if ( V_354 && ! ( ( V_2 -> V_132 & V_133 ) && V_128 ) ) {
V_14 -> V_103 . V_352 . V_908 ( V_14 ) ;
F_436 ( V_2 ) ;
}
if ( V_354 ||
F_437 ( V_165 , ( V_2 -> V_367 +
V_909 ) ) ) {
V_2 -> V_132 &= ~ V_366 ;
F_60 ( V_14 , V_370 , V_369 ) ;
F_203 ( V_14 ) ;
}
V_2 -> V_354 = V_354 ;
V_2 -> V_906 = V_906 ;
}
static void F_438 ( struct V_1 * V_2 )
{
#ifdef F_330
struct V_49 * V_50 = V_2 -> V_50 ;
struct V_910 V_911 = {
. V_912 = V_913 ,
. V_237 = 0 ,
} ;
T_6 V_706 = 0 ;
if ( V_2 -> V_576 & V_914 )
V_706 = F_439 ( V_50 , & V_911 ) ;
V_2 -> V_915 = ( V_706 > 1 ) ? ( F_440 ( V_706 ) - 1 ) : 0 ;
#endif
}
static void F_441 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = V_2 -> V_50 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_906 = V_2 -> V_906 ;
bool V_916 , V_917 ;
if ( F_98 ( V_50 ) )
return;
V_2 -> V_148 &= ~ V_642 ;
switch ( V_14 -> V_103 . type ) {
case V_104 : {
T_1 V_918 = F_26 ( V_14 , V_558 ) ;
T_1 V_919 = F_26 ( V_14 , V_920 ) ;
V_916 = ! ! ( V_918 & V_921 ) ;
V_917 = ! ! ( V_919 & V_922 ) ;
}
break;
case V_107 :
case V_106 : {
T_1 V_923 = F_26 ( V_14 , V_924 ) ;
T_1 V_925 = F_26 ( V_14 , V_926 ) ;
V_916 = ! ! ( V_923 & V_927 ) ;
V_917 = ! ! ( V_925 & V_928 ) ;
}
break;
default:
V_917 = false ;
V_916 = false ;
break;
}
V_2 -> V_929 = V_165 ;
if ( F_13 ( V_679 , & V_2 -> V_33 ) )
F_442 ( V_2 ) ;
F_94 ( V_150 , L_116 ,
( V_906 == V_907 ?
L_117 :
( V_906 == V_930 ?
L_118 :
( V_906 == V_931 ?
L_119 :
L_120 ) ) ) ,
( ( V_916 && V_917 ) ? L_121 :
( V_916 ? L_122 :
( V_917 ? L_123 : L_124 ) ) ) ) ;
F_443 ( V_50 ) ;
F_444 ( V_2 ) ;
F_438 ( V_2 ) ;
F_359 ( V_2 ) ;
}
static void F_445 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = V_2 -> V_50 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
V_2 -> V_354 = false ;
V_2 -> V_906 = 0 ;
if ( ! F_98 ( V_50 ) )
return;
if ( F_334 ( V_14 ) && V_14 -> V_103 . type == V_104 )
V_2 -> V_148 |= V_642 ;
if ( F_13 ( V_679 , & V_2 -> V_33 ) )
F_442 ( V_2 ) ;
F_94 ( V_150 , L_125 ) ;
F_356 ( V_50 ) ;
F_359 ( V_2 ) ;
}
static void F_446 ( struct V_1 * V_2 )
{
int V_43 ;
int V_932 = 0 ;
if ( ! F_98 ( V_2 -> V_50 ) ) {
for ( V_43 = 0 ; V_43 < V_2 -> V_72 ; V_43 ++ ) {
struct V_52 * V_53 = V_2 -> V_53 [ V_43 ] ;
if ( V_53 -> V_75 != V_53 -> V_74 ) {
V_932 = 1 ;
break;
}
}
if ( V_932 ) {
F_82 ( V_150 , L_126 ) ;
V_2 -> V_148 |= V_149 ;
}
}
}
static void F_447 ( struct V_1 * V_2 )
{
T_1 V_933 ;
if ( V_2 -> V_14 . V_103 . type == V_104 ||
V_2 -> V_319 == 0 )
return;
V_933 = F_26 ( & V_2 -> V_14 , V_934 ) ;
if ( ! V_933 )
return;
F_82 ( V_150 , L_127 , V_933 ) ;
}
static void F_448 ( struct V_1 * V_2 )
{
if ( F_13 ( V_32 , & V_2 -> V_33 ) ||
F_13 ( V_34 , & V_2 -> V_33 ) ||
F_13 ( V_670 , & V_2 -> V_33 ) )
return;
F_435 ( V_2 ) ;
if ( V_2 -> V_354 )
F_441 ( V_2 ) ;
else
F_445 ( V_2 ) ;
F_447 ( V_2 ) ;
F_413 ( V_2 ) ;
F_446 ( V_2 ) ;
}
static void F_449 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_3 V_16 ;
if ( ! ( V_2 -> V_148 & V_642 ) &&
! ( V_2 -> V_148 & V_363 ) )
return;
if ( F_14 ( V_671 , & V_2 -> V_33 ) )
return;
V_16 = V_14 -> V_355 . V_352 . V_935 ( V_14 ) ;
if ( V_16 == V_674 )
goto V_936;
if ( V_16 == V_673 ) {
V_2 -> V_148 |= V_363 ;
}
if ( V_16 )
goto V_936;
if ( ! ( V_2 -> V_148 & V_363 ) )
goto V_936;
V_2 -> V_148 &= ~ V_363 ;
if ( V_14 -> V_103 . type == V_104 )
V_16 = V_14 -> V_355 . V_352 . V_937 ( V_14 ) ;
else
V_16 = V_14 -> V_103 . V_352 . V_938 ( V_14 ) ;
if ( V_16 == V_674 )
goto V_936;
V_2 -> V_132 |= V_364 ;
F_94 ( V_166 , L_128 , V_14 -> V_355 . V_939 ) ;
V_936:
F_23 ( V_671 , & V_2 -> V_33 ) ;
if ( ( V_16 == V_674 ) &&
( V_2 -> V_50 -> V_940 == V_941 ) ) {
F_17 ( L_129
L_130 ) ;
F_17 ( L_131
L_132 ) ;
F_450 ( V_2 -> V_50 ) ;
}
}
static void F_451 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_19 ;
bool V_643 = false ;
if ( ! ( V_2 -> V_132 & V_364 ) )
return;
if ( F_14 ( V_671 , & V_2 -> V_33 ) )
return;
V_2 -> V_132 &= ~ V_364 ;
V_19 = V_14 -> V_355 . V_646 ;
if ( ( ! V_19 ) && ( V_14 -> V_103 . V_352 . V_647 ) ) {
V_14 -> V_103 . V_352 . V_647 ( V_14 , & V_19 , & V_643 ) ;
if ( ! V_643 ) {
if ( V_19 & V_907 )
V_19 = V_907 ;
}
}
if ( V_14 -> V_103 . V_352 . V_648 )
V_14 -> V_103 . V_352 . V_648 ( V_14 , V_19 , true ) ;
V_2 -> V_132 |= V_366 ;
V_2 -> V_367 = V_165 ;
F_23 ( V_671 , & V_2 -> V_33 ) ;
}
static void F_452 ( struct V_1 * V_2 )
{
int V_942 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_49 * V_50 = V_2 -> V_50 ;
T_1 V_943 ;
T_1 V_944 , V_945 ;
V_943 = F_26 ( V_14 , V_946 ) ;
if ( V_943 )
return;
for ( V_942 = 0 ; V_942 < V_2 -> V_319 ; V_942 ++ ) {
V_944 = ( V_942 << 16 ) | 0x80000000 ;
V_944 |= V_947 ;
F_60 ( V_14 , V_948 , V_944 ) ;
V_945 = F_26 ( V_14 , V_949 ) ;
V_944 &= 0x7FFFFFFF ;
F_60 ( V_14 , V_948 , V_944 ) ;
V_945 >>= 16 ;
if ( V_945 & V_950 ) {
F_453 ( V_50 , L_133 , V_942 ) ;
V_944 = ( V_942 << 16 ) | 0x80000000 ;
V_944 |= 0xA8 ;
F_60 ( V_14 , V_948 , V_944 ) ;
V_945 = 0x00008000 ;
F_60 ( V_14 , V_949 , V_945 ) ;
V_944 &= 0x7FFFFFFF ;
F_60 ( V_14 , V_948 , V_944 ) ;
}
}
}
static void F_454 ( unsigned long V_87 )
{
struct V_1 * V_2 = (struct V_1 * ) V_87 ;
unsigned long V_951 ;
bool V_952 = true ;
if ( V_2 -> V_132 & V_366 )
V_951 = V_953 / 10 ;
else
V_951 = V_953 * 2 ;
#ifdef F_367
if ( ! V_2 -> V_319 ||
( V_2 -> V_132 & V_366 ) )
goto V_954;
F_452 ( V_2 ) ;
V_951 = V_953 / 50 ;
V_2 -> V_955 ++ ;
if ( V_2 -> V_955 >= 100 )
V_2 -> V_955 = 0 ;
else
V_952 = false ;
V_954:
#endif
F_341 ( & V_2 -> V_668 , V_951 + V_165 ) ;
if ( V_952 )
F_12 ( V_2 ) ;
}
static void F_455 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_148 & V_149 ) )
return;
V_2 -> V_148 &= ~ V_149 ;
if ( F_13 ( V_32 , & V_2 -> V_33 ) ||
F_13 ( V_34 , & V_2 -> V_33 ) ||
F_13 ( V_670 , & V_2 -> V_33 ) )
return;
F_43 ( V_2 ) ;
F_453 ( V_2 -> V_50 , L_134 ) ;
V_2 -> V_167 ++ ;
F_401 () ;
F_342 ( V_2 ) ;
F_403 () ;
}
static void F_456 ( struct V_956 * V_957 )
{
struct V_1 * V_2 = F_187 ( V_957 ,
struct V_1 ,
V_36 ) ;
if ( F_250 ( V_2 -> V_14 . V_38 ) ) {
if ( ! F_13 ( V_32 , & V_2 -> V_33 ) ) {
F_401 () ;
F_345 ( V_2 ) ;
F_403 () ;
}
F_20 ( V_2 ) ;
return;
}
F_455 ( V_2 ) ;
F_449 ( V_2 ) ;
F_451 ( V_2 ) ;
F_197 ( V_2 ) ;
F_448 ( V_2 ) ;
F_431 ( V_2 ) ;
F_433 ( V_2 ) ;
if ( F_13 ( V_679 , & V_2 -> V_33 ) ) {
F_457 ( V_2 ) ;
F_458 ( V_2 ) ;
}
F_20 ( V_2 ) ;
}
static int F_459 ( struct V_52 * V_53 ,
struct V_54 * V_958 ,
T_6 * V_255 )
{
struct V_189 * V_84 = V_958 -> V_84 ;
T_1 V_959 , V_960 ;
T_1 V_961 , V_962 ;
if ( V_84 -> V_212 != V_963 )
return 0 ;
if ( ! F_460 ( V_84 ) )
return 0 ;
if ( F_461 ( V_84 ) ) {
int V_16 = F_462 ( V_84 , 0 , 0 , V_217 ) ;
if ( V_16 )
return V_16 ;
}
V_960 = V_964 ;
if ( V_958 -> V_237 == F_136 ( V_245 ) ) {
struct V_232 * V_965 = F_463 ( V_84 ) ;
V_965 -> V_966 = 0 ;
V_965 -> V_967 = 0 ;
F_464 ( V_84 ) -> V_967 = ~ F_465 ( V_965 -> V_968 ,
V_965 -> V_969 , 0 ,
V_251 ,
0 ) ;
V_960 |= V_970 ;
V_958 -> V_971 |= V_972 |
V_973 |
V_974 ;
} else if ( F_466 ( V_84 ) ) {
F_467 ( V_84 ) -> V_975 = 0 ;
F_464 ( V_84 ) -> V_967 =
~ F_468 ( & F_467 ( V_84 ) -> V_968 ,
& F_467 ( V_84 ) -> V_969 ,
0 , V_251 , 0 ) ;
V_958 -> V_971 |= V_972 |
V_973 ;
}
V_962 = F_469 ( V_84 ) ;
* V_255 = F_470 ( V_84 ) + V_962 ;
V_958 -> V_162 = F_141 ( V_84 ) -> V_162 ;
V_958 -> V_161 += ( V_958 -> V_162 - 1 ) * * V_255 ;
V_961 = V_962 << V_976 ;
V_961 |= F_141 ( V_84 ) -> V_256 << V_977 ;
V_959 = F_471 ( V_84 ) ;
V_959 |= F_472 ( V_84 ) << V_978 ;
V_959 |= V_958 -> V_971 & V_979 ;
F_473 ( V_53 , V_959 , 0 , V_960 ,
V_961 ) ;
return 1 ;
}
static void F_474 ( struct V_52 * V_53 ,
struct V_54 * V_958 )
{
struct V_189 * V_84 = V_958 -> V_84 ;
T_1 V_959 = 0 ;
T_1 V_961 = 0 ;
T_1 V_960 = 0 ;
if ( V_84 -> V_212 != V_963 ) {
if ( ! ( V_958 -> V_971 & V_980 ) &&
! ( V_958 -> V_971 & V_981 ) )
return;
} else {
T_6 V_982 = 0 ;
switch ( V_958 -> V_237 ) {
case F_136 ( V_245 ) :
V_959 |= F_471 ( V_84 ) ;
V_960 |= V_970 ;
V_982 = F_463 ( V_84 ) -> V_237 ;
break;
case F_136 ( V_248 ) :
V_959 |= F_471 ( V_84 ) ;
V_982 = F_467 ( V_84 ) -> V_238 ;
break;
default:
if ( F_86 ( F_475 () ) ) {
F_476 ( V_53 -> V_68 ,
L_135 ,
V_958 -> V_237 ) ;
}
break;
}
switch ( V_982 ) {
case V_251 :
V_960 |= V_964 ;
V_961 = F_469 ( V_84 ) <<
V_976 ;
break;
case V_983 :
V_960 |= V_984 ;
V_961 = sizeof( struct V_985 ) <<
V_976 ;
break;
case V_253 :
V_961 = sizeof( struct V_254 ) <<
V_976 ;
break;
default:
if ( F_86 ( F_475 () ) ) {
F_476 ( V_53 -> V_68 ,
L_136 ,
V_982 ) ;
}
break;
}
V_958 -> V_971 |= V_973 ;
}
V_959 |= F_472 ( V_84 ) << V_978 ;
V_959 |= V_958 -> V_971 & V_979 ;
F_473 ( V_53 , V_959 , 0 ,
V_960 , V_961 ) ;
}
static T_1 F_477 ( struct V_189 * V_84 , T_1 V_971 )
{
T_1 V_986 = V_987 |
V_988 |
V_989 ;
V_986 |= F_478 ( V_971 , V_980 ,
V_990 ) ;
V_986 |= F_478 ( V_971 , V_972 ,
V_991 ) ;
V_986 |= F_478 ( V_971 , V_992 ,
V_993 ) ;
V_986 ^= F_478 ( V_84 -> V_994 , 1 , V_989 ) ;
return V_986 ;
}
static void F_479 ( union V_56 * V_57 ,
T_1 V_971 , unsigned int V_995 )
{
T_1 V_996 = V_995 << V_997 ;
V_996 |= F_478 ( V_971 ,
V_973 ,
V_998 ) ;
V_996 |= F_478 ( V_971 ,
V_974 ,
V_999 ) ;
V_996 |= F_478 ( V_971 ,
V_981 ,
V_1000 ) ;
V_57 -> V_223 . V_996 = F_85 ( V_996 ) ;
}
static void F_480 ( struct V_52 * V_53 ,
struct V_54 * V_958 ,
const T_6 V_255 )
{
struct V_189 * V_84 = V_958 -> V_84 ;
struct V_54 * V_55 ;
union V_56 * V_57 ;
struct V_276 * V_277 ;
T_8 V_76 ;
unsigned int V_282 , V_291 ;
T_1 V_971 = V_958 -> V_971 ;
T_1 V_986 = F_477 ( V_84 , V_971 ) ;
T_2 V_43 = V_53 -> V_75 ;
V_57 = F_50 ( V_53 , V_43 ) ;
F_479 ( V_57 , V_971 , V_84 -> V_77 - V_255 ) ;
V_291 = F_140 ( V_84 ) ;
V_282 = V_84 -> V_282 ;
#ifdef F_138
if ( V_971 & V_1001 ) {
if ( V_282 < sizeof( struct V_310 ) ) {
V_291 -= sizeof( struct V_310 ) - V_282 ;
V_282 = 0 ;
} else {
V_282 -= sizeof( struct V_310 ) ;
}
}
#endif
V_76 = F_481 ( V_53 -> V_68 , V_84 -> V_87 , V_291 , V_114 ) ;
V_55 = V_958 ;
for ( V_277 = & F_141 ( V_84 ) -> V_278 [ 0 ] ; ; V_277 ++ ) {
if ( F_131 ( V_53 -> V_68 , V_76 ) )
goto V_1002;
F_70 ( V_55 , V_77 , V_291 ) ;
F_482 ( V_55 , V_76 , V_76 ) ;
V_57 -> V_223 . V_1003 = F_134 ( V_76 ) ;
while ( F_86 ( V_291 > V_1004 ) ) {
V_57 -> V_223 . V_1005 =
F_85 ( V_986 ^ V_1004 ) ;
V_43 ++ ;
V_57 ++ ;
if ( V_43 == V_53 -> V_83 ) {
V_57 = F_50 ( V_53 , 0 ) ;
V_43 = 0 ;
}
V_57 -> V_223 . V_996 = 0 ;
V_76 += V_1004 ;
V_291 -= V_1004 ;
V_57 -> V_223 . V_1003 = F_134 ( V_76 ) ;
}
if ( F_88 ( ! V_282 ) )
break;
V_57 -> V_223 . V_1005 = F_85 ( V_986 ^ V_291 ) ;
V_43 ++ ;
V_57 ++ ;
if ( V_43 == V_53 -> V_83 ) {
V_57 = F_50 ( V_53 , 0 ) ;
V_43 = 0 ;
}
V_57 -> V_223 . V_996 = 0 ;
#ifdef F_138
V_291 = F_322 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_291 = F_483 ( V_277 ) ;
#endif
V_282 -= V_291 ;
V_76 = F_484 ( V_53 -> V_68 , V_277 , 0 , V_291 ,
V_114 ) ;
V_55 = & V_53 -> V_73 [ V_43 ] ;
}
V_986 |= V_291 | V_1006 ;
V_57 -> V_223 . V_1005 = F_85 ( V_986 ) ;
F_485 ( F_96 ( V_53 ) , V_958 -> V_161 ) ;
V_958 -> V_79 = V_165 ;
F_124 () ;
V_958 -> V_78 = V_57 ;
V_43 ++ ;
if ( V_43 == V_53 -> V_83 )
V_43 = 0 ;
V_53 -> V_75 = V_43 ;
F_125 ( V_53 , V_43 ) ;
return;
V_1002:
F_377 ( V_53 -> V_68 , L_137 ) ;
for (; ; ) {
V_55 = & V_53 -> V_73 [ V_43 ] ;
F_66 ( V_53 , V_55 ) ;
if ( V_55 == V_958 )
break;
if ( V_43 == 0 )
V_43 = V_53 -> V_83 ;
V_43 -- ;
}
V_53 -> V_75 = V_43 ;
}
static void F_486 ( struct V_52 * V_113 ,
struct V_54 * V_958 )
{
struct V_151 * V_152 = V_113 -> V_152 ;
union V_1007 V_1008 = { . V_1009 = 0 } ;
union V_1007 V_1010 = { . V_1009 = 0 } ;
union {
unsigned char * V_227 ;
struct V_232 * V_233 ;
struct V_234 * V_235 ;
} V_236 ;
struct V_252 * V_1011 ;
T_9 V_1012 ;
if ( ! V_152 )
return;
if ( ! V_113 -> V_414 )
return;
V_113 -> V_415 ++ ;
V_236 . V_227 = F_487 ( V_958 -> V_84 ) ;
if ( ( V_958 -> V_237 != F_136 ( V_248 ) ||
V_236 . V_235 -> V_238 != V_251 ) &&
( V_958 -> V_237 != F_136 ( V_245 ) ||
V_236 . V_233 -> V_237 != V_251 ) )
return;
V_1011 = F_464 ( V_958 -> V_84 ) ;
if ( ! V_1011 || V_1011 -> V_1013 )
return;
if ( ! V_1011 -> V_1014 && ( V_113 -> V_415 < V_113 -> V_414 ) )
return;
V_113 -> V_415 = 0 ;
V_1012 = F_137 ( V_958 -> V_971 >> V_1015 ) ;
V_1008 . V_1016 . V_1012 = V_1012 ;
if ( V_958 -> V_971 & ( V_1017 | V_980 ) )
V_1010 . V_1018 . V_1019 ^= V_1011 -> V_1020 ^ F_136 ( V_242 ) ;
else
V_1010 . V_1018 . V_1019 ^= V_1011 -> V_1020 ^ V_958 -> V_237 ;
V_1010 . V_1018 . V_1021 ^= V_1011 -> V_1022 ;
if ( V_958 -> V_237 == F_136 ( V_245 ) ) {
V_1008 . V_1016 . V_1023 = V_1024 ;
V_1010 . V_1025 ^= V_236 . V_233 -> V_968 ^ V_236 . V_233 -> V_969 ;
} else {
V_1008 . V_1016 . V_1023 = V_1026 ;
V_1010 . V_1025 ^= V_236 . V_235 -> V_968 . V_1027 [ 0 ] ^
V_236 . V_235 -> V_968 . V_1027 [ 1 ] ^
V_236 . V_235 -> V_968 . V_1027 [ 2 ] ^
V_236 . V_235 -> V_968 . V_1027 [ 3 ] ^
V_236 . V_235 -> V_969 . V_1027 [ 0 ] ^
V_236 . V_235 -> V_969 . V_1027 [ 1 ] ^
V_236 . V_235 -> V_969 . V_1027 [ 2 ] ^
V_236 . V_235 -> V_969 . V_1027 [ 3 ] ;
}
F_488 ( & V_152 -> V_2 -> V_14 ,
V_1008 , V_1010 , V_113 -> V_81 ) ;
}
static int F_489 ( struct V_52 * V_53 , T_2 V_291 )
{
F_93 ( V_53 -> V_50 , V_53 -> V_81 ) ;
F_100 () ;
if ( F_88 ( F_99 ( V_53 ) < V_291 ) )
return - V_753 ;
F_490 ( V_53 -> V_50 , V_53 -> V_81 ) ;
++ V_53 -> V_145 . V_168 ;
return 0 ;
}
static inline int F_491 ( struct V_52 * V_53 , T_2 V_291 )
{
if ( F_88 ( F_99 ( V_53 ) >= V_291 ) )
return 0 ;
return F_489 ( V_53 , V_291 ) ;
}
static T_2 F_492 ( struct V_49 * V_68 , struct V_189 * V_84 ,
void * V_1028 , T_13 V_1029 )
{
struct V_608 * V_1030 = V_1028 ;
#ifdef F_138
struct V_1 * V_2 ;
struct V_1031 * V_1032 ;
int V_1033 ;
#endif
if ( V_1030 )
return V_84 -> V_1034 + V_1030 -> V_616 ;
#ifdef F_138
switch ( F_493 ( V_84 ) ) {
case F_136 ( V_249 ) :
case F_136 ( V_1035 ) :
V_2 = F_78 ( V_68 ) ;
if ( V_2 -> V_132 & V_510 )
break;
default:
return V_1029 ( V_68 , V_84 ) ;
}
V_1032 = & V_2 -> V_429 [ V_1036 ] ;
V_1033 = F_494 ( V_84 ) ? F_495 ( V_84 ) :
F_496 () ;
while ( V_1033 >= V_1032 -> V_431 )
V_1033 -= V_1032 -> V_431 ;
return V_1033 + V_1032 -> V_1037 ;
#else
return V_1029 ( V_68 , V_84 ) ;
#endif
}
T_14 F_497 ( struct V_189 * V_84 ,
struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_54 * V_958 ;
int V_1038 ;
T_1 V_971 = 0 ;
unsigned short V_1032 ;
T_2 V_83 = F_498 ( F_140 ( V_84 ) ) ;
T_9 V_237 = V_84 -> V_237 ;
T_6 V_255 = 0 ;
for ( V_1032 = 0 ; V_1032 < F_141 ( V_84 ) -> V_297 ; V_1032 ++ )
V_83 += F_498 ( F_141 ( V_84 ) -> V_278 [ V_1032 ] . V_291 ) ;
if ( F_491 ( V_53 , V_83 + 3 ) ) {
V_53 -> V_145 . V_781 ++ ;
return V_1039 ;
}
V_958 = & V_53 -> V_73 [ V_53 -> V_75 ] ;
V_958 -> V_84 = V_84 ;
V_958 -> V_161 = V_84 -> V_77 ;
V_958 -> V_162 = 1 ;
if ( F_499 ( V_84 ) ) {
V_971 |= F_500 ( V_84 ) << V_1015 ;
V_971 |= V_980 ;
} else if ( V_237 == F_136 ( V_242 ) ) {
struct V_230 * V_1040 , V_1041 ;
V_1040 = F_501 ( V_84 , V_240 , sizeof( V_1041 ) , & V_1041 ) ;
if ( ! V_1040 )
goto V_1042;
V_237 = V_1040 -> V_244 ;
V_971 |= F_502 ( V_1040 -> V_1043 ) <<
V_1015 ;
V_971 |= V_1017 ;
}
F_503 ( V_84 ) ;
if ( F_86 ( F_141 ( V_84 ) -> V_971 & V_1044 ) ) {
F_141 ( V_84 ) -> V_971 |= V_1045 ;
V_971 |= V_992 ;
V_2 -> V_1046 = F_504 ( V_84 ) ;
V_2 -> V_1047 = V_165 ;
F_15 ( & V_2 -> V_1048 ) ;
}
#ifdef F_367
if ( V_2 -> V_132 & V_424 )
V_971 |= V_981 ;
#endif
if ( ( V_2 -> V_132 & V_133 ) &&
( ( V_971 & ( V_980 | V_1017 ) ) ||
( V_84 -> V_1049 != V_1050 ) ) ) {
V_971 &= ~ V_1051 ;
V_971 |= ( V_84 -> V_1049 & 0x7 ) <<
V_1052 ;
if ( V_971 & V_1017 ) {
struct V_1053 * V_1040 ;
if ( F_461 ( V_84 ) &&
F_462 ( V_84 , 0 , 0 , V_217 ) )
goto V_1042;
V_1040 = (struct V_1053 * ) V_84 -> V_87 ;
V_1040 -> V_1043 = F_137 ( V_971 >>
V_1015 ) ;
} else {
V_971 |= V_980 ;
}
}
V_958 -> V_971 = V_971 ;
V_958 -> V_237 = V_237 ;
#ifdef F_138
if ( ( V_237 == F_136 ( V_249 ) ) &&
( V_53 -> V_50 -> V_190 & ( V_1054 | V_1055 ) ) ) {
V_1038 = F_505 ( V_53 , V_958 , & V_255 ) ;
if ( V_1038 < 0 )
goto V_1042;
goto V_1056;
}
#endif
V_1038 = F_459 ( V_53 , V_958 , & V_255 ) ;
if ( V_1038 < 0 )
goto V_1042;
else if ( ! V_1038 )
F_474 ( V_53 , V_958 ) ;
if ( F_13 ( V_388 , & V_53 -> V_33 ) )
F_486 ( V_53 , V_958 ) ;
#ifdef F_138
V_1056:
#endif
F_480 ( V_53 , V_958 , V_255 ) ;
F_491 ( V_53 , V_1057 ) ;
return V_1058 ;
V_1042:
F_67 ( V_958 -> V_84 ) ;
V_958 -> V_84 = NULL ;
return V_1058 ;
}
static T_14 F_506 ( struct V_189 * V_84 ,
struct V_49 * V_50 ,
struct V_52 * V_113 )
{
struct V_1 * V_2 = F_78 ( V_50 ) ;
struct V_52 * V_53 ;
if ( F_86 ( V_84 -> V_77 < 17 ) ) {
if ( F_167 ( V_84 , 17 - V_84 -> V_77 ) )
return V_1058 ;
V_84 -> V_77 = 17 ;
F_507 ( V_84 , 17 ) ;
}
V_53 = V_113 ? V_113 : V_2 -> V_53 [ V_84 -> V_1034 ] ;
return F_497 ( V_84 , V_2 , V_53 ) ;
}
static T_14 F_508 ( struct V_189 * V_84 ,
struct V_49 * V_50 )
{
return F_506 ( V_84 , V_50 , NULL ) ;
}
static int F_509 ( struct V_49 * V_50 , void * V_1059 )
{
struct V_1 * V_2 = F_78 ( V_50 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_1060 * V_551 = V_1059 ;
if ( ! F_325 ( V_551 -> V_1061 ) )
return - V_1062 ;
memcpy ( V_50 -> V_621 , V_551 -> V_1061 , V_50 -> V_1063 ) ;
memcpy ( V_14 -> V_103 . V_551 , V_551 -> V_1061 , V_50 -> V_1063 ) ;
V_14 -> V_103 . V_352 . V_550 ( V_14 , 0 , V_14 -> V_103 . V_551 , F_257 ( 0 ) , V_552 ) ;
return 0 ;
}
static int
F_510 ( struct V_49 * V_50 , int V_1064 , int V_1065 , T_2 V_551 )
{
struct V_1 * V_2 = F_78 ( V_50 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
T_2 V_4 ;
int V_1066 ;
if ( V_1064 != V_14 -> V_355 . V_1067 . V_1064 )
return - V_751 ;
V_1066 = V_14 -> V_355 . V_352 . V_1068 ( V_14 , V_551 , V_1065 , & V_4 ) ;
if ( ! V_1066 )
V_1066 = V_4 ;
return V_1066 ;
}
static int F_511 ( struct V_49 * V_50 , int V_1064 , int V_1065 ,
T_2 V_551 , T_2 V_4 )
{
struct V_1 * V_2 = F_78 ( V_50 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
if ( V_1064 != V_14 -> V_355 . V_1067 . V_1064 )
return - V_751 ;
return V_14 -> V_355 . V_352 . V_1069 ( V_14 , V_551 , V_1065 , V_4 ) ;
}
static int F_512 ( struct V_49 * V_50 , struct V_1070 * V_1071 , int V_1072 )
{
struct V_1 * V_2 = F_78 ( V_50 ) ;
switch ( V_1072 ) {
case V_1073 :
return F_513 ( V_2 , V_1071 , V_1072 ) ;
default:
return F_514 ( & V_2 -> V_14 . V_355 . V_1067 , F_515 ( V_1071 ) , V_1072 ) ;
}
}
static int F_516 ( struct V_49 * V_68 )
{
int V_16 = 0 ;
struct V_1 * V_2 = F_78 ( V_68 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
if ( F_325 ( V_14 -> V_103 . V_1074 ) ) {
F_401 () ;
V_16 = F_517 ( V_68 , V_14 -> V_103 . V_1074 , V_1075 ) ;
F_403 () ;
V_14 -> V_103 . V_352 . V_678 ( V_14 , F_257 ( 0 ) ) ;
}
return V_16 ;
}
static int F_518 ( struct V_49 * V_68 )
{
int V_16 = 0 ;
struct V_1 * V_2 = F_78 ( V_68 ) ;
struct V_1076 * V_103 = & V_2 -> V_14 . V_103 ;
if ( F_325 ( V_103 -> V_1074 ) ) {
F_401 () ;
V_16 = F_519 ( V_68 , V_103 -> V_1074 , V_1075 ) ;
F_403 () ;
}
return V_16 ;
}
static void F_520 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_78 ( V_50 ) ;
int V_43 ;
if ( F_13 ( V_32 , & V_2 -> V_33 ) )
return;
V_2 -> V_132 |= V_265 ;
if ( V_2 -> V_132 & V_403 ) {
for ( V_43 = 0 ; V_43 < V_2 -> V_183 ; V_43 ++ )
F_213 ( 0 , V_2 -> V_152 [ V_43 ] ) ;
} else {
F_226 ( V_2 -> V_9 -> V_382 , V_50 ) ;
}
V_2 -> V_132 &= ~ V_265 ;
}
static struct V_1077 * F_521 ( struct V_49 * V_50 ,
struct V_1077 * V_117 )
{
struct V_1 * V_2 = F_78 ( V_50 ) ;
int V_43 ;
F_522 () ;
for ( V_43 = 0 ; V_43 < V_2 -> V_88 ; V_43 ++ ) {
struct V_52 * V_113 = F_523 ( V_2 -> V_62 [ V_43 ] ) ;
T_4 V_164 , V_137 ;
unsigned int V_1078 ;
if ( V_113 ) {
do {
V_1078 = F_524 ( & V_113 -> V_163 ) ;
V_137 = V_113 -> V_117 . V_137 ;
V_164 = V_113 -> V_117 . V_164 ;
} while ( F_525 ( & V_113 -> V_163 , V_1078 ) );
V_117 -> V_786 += V_137 ;
V_117 -> V_785 += V_164 ;
}
}
for ( V_43 = 0 ; V_43 < V_2 -> V_72 ; V_43 ++ ) {
struct V_52 * V_113 = F_523 ( V_2 -> V_53 [ V_43 ] ) ;
T_4 V_164 , V_137 ;
unsigned int V_1078 ;
if ( V_113 ) {
do {
V_1078 = F_524 ( & V_113 -> V_163 ) ;
V_137 = V_113 -> V_117 . V_137 ;
V_164 = V_113 -> V_117 . V_164 ;
} while ( F_525 ( & V_113 -> V_163 , V_1078 ) );
V_117 -> V_788 += V_137 ;
V_117 -> V_787 += V_164 ;
}
}
F_526 () ;
V_117 -> V_895 = V_50 -> V_117 . V_895 ;
V_117 -> V_896 = V_50 -> V_117 . V_896 ;
V_117 -> V_898 = V_50 -> V_117 . V_898 ;
V_117 -> V_899 = V_50 -> V_117 . V_899 ;
V_117 -> V_900 = V_50 -> V_117 . V_900 ;
return V_117 ;
}
static void F_527 ( struct V_1 * V_2 , T_6 V_127 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 V_3 , V_1079 ;
int V_43 ;
if ( V_14 -> V_103 . type == V_104 )
return;
V_3 = F_26 ( V_14 , V_1080 ) ;
V_1079 = V_3 ;
for ( V_43 = 0 ; V_43 < V_717 ; V_43 ++ ) {
T_6 V_1081 = V_3 >> ( V_43 * V_1082 ) ;
if ( V_1081 > V_127 )
V_3 &= ~ ( 0x7 << V_1082 ) ;
}
if ( V_3 != V_1079 )
F_60 ( V_14 , V_1080 , V_3 ) ;
return;
}
static void F_528 ( struct V_1 * V_2 )
{
struct V_49 * V_68 = V_2 -> V_50 ;
struct V_1083 * V_129 = & V_2 -> V_129 ;
struct V_1084 * V_1085 = V_2 -> V_580 ;
T_6 V_1086 ;
for ( V_1086 = 0 ; V_1086 < V_1087 ; V_1086 ++ ) {
T_6 V_127 = 0 ;
if ( V_2 -> V_576 & V_577 )
V_127 = F_529 ( V_129 , 0 , V_1086 ) ;
else if ( V_1085 )
V_127 = V_1085 -> V_581 [ V_1086 ] ;
F_530 ( V_68 , V_1086 , V_127 ) ;
}
}
int F_531 ( struct V_49 * V_68 , T_6 V_127 )
{
struct V_1 * V_2 = F_78 ( V_68 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
bool V_1088 ;
if ( V_127 > V_2 -> V_129 . V_713 . V_714 ||
( V_14 -> V_103 . type == V_104 &&
V_127 < V_717 ) )
return - V_751 ;
V_1088 = ( F_532 ( & V_2 -> V_618 , 32 ) > 1 ) ;
if ( V_127 && V_1088 && V_2 -> V_619 > V_1089 )
return - V_753 ;
if ( F_46 ( V_68 ) )
F_391 ( V_68 ) ;
F_408 ( V_2 ) ;
#ifdef F_330
if ( V_127 ) {
F_533 ( V_68 , V_127 ) ;
F_528 ( V_2 ) ;
V_2 -> V_132 |= V_133 ;
if ( V_2 -> V_14 . V_103 . type == V_104 ) {
V_2 -> V_1090 = V_2 -> V_14 . V_118 . V_729 ;
V_2 -> V_14 . V_118 . V_729 = V_1091 ;
}
} else {
F_534 ( V_68 ) ;
if ( V_2 -> V_14 . V_103 . type == V_104 )
V_2 -> V_14 . V_118 . V_729 = V_2 -> V_1090 ;
V_2 -> V_132 &= ~ V_133 ;
V_2 -> V_728 . V_130 = false ;
V_2 -> V_129 . V_130 = false ;
}
F_527 ( V_2 , V_127 ) ;
#endif
F_402 ( V_2 ) ;
if ( F_46 ( V_68 ) )
return F_389 ( V_68 ) ;
return 0 ;
}
void F_535 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = V_2 -> V_50 ;
F_401 () ;
F_531 ( V_50 , F_239 ( V_50 ) ) ;
F_403 () ;
}
void F_536 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_78 ( V_50 ) ;
if ( F_46 ( V_50 ) )
F_342 ( V_2 ) ;
else
F_348 ( V_2 ) ;
}
static T_15 F_537 ( struct V_49 * V_50 ,
T_15 V_190 )
{
struct V_1 * V_2 = F_78 ( V_50 ) ;
if ( ! ( V_190 & V_203 ) )
V_190 &= ~ V_1092 ;
if ( ! ( V_2 -> V_148 & V_698 ) )
V_190 &= ~ V_1092 ;
return V_190 ;
}
static int F_538 ( struct V_49 * V_50 ,
T_15 V_190 )
{
struct V_1 * V_2 = F_78 ( V_50 ) ;
T_15 V_1093 = V_50 -> V_190 ^ V_190 ;
bool V_1094 = false ;
if ( ! ( V_190 & V_1092 ) ) {
if ( V_2 -> V_148 & V_518 )
V_1094 = true ;
V_2 -> V_148 &= ~ V_518 ;
} else if ( ( V_2 -> V_148 & V_698 ) &&
! ( V_2 -> V_148 & V_518 ) ) {
if ( V_2 -> V_394 == 1 ||
V_2 -> V_394 > V_1095 ) {
V_2 -> V_148 |= V_518 ;
V_1094 = true ;
} else if ( ( V_1093 ^ V_190 ) & V_1092 ) {
F_94 ( V_166 , L_138
L_139 ) ;
}
}
switch ( V_190 & V_1096 ) {
case V_1096 :
if ( ! ( V_2 -> V_132 & V_594 ) )
V_1094 = true ;
V_2 -> V_132 &= ~ V_379 ;
V_2 -> V_132 |= V_594 ;
break;
default:
if ( V_2 -> V_132 & V_594 )
V_1094 = true ;
V_2 -> V_132 &= ~ V_594 ;
if ( V_2 -> V_132 & V_424 )
break;
if ( F_239 ( V_50 ) > 1 )
break;
if ( V_2 -> V_429 [ V_430 ] . V_697 <= 1 )
break;
if ( ! V_2 -> V_414 )
break;
V_2 -> V_132 |= V_379 ;
break;
}
if ( V_190 & V_262 )
F_272 ( V_2 ) ;
else
F_271 ( V_2 ) ;
if ( V_1093 & V_285 )
V_1094 = true ;
V_50 -> V_190 = V_190 ;
if ( V_1094 )
F_536 ( V_50 ) ;
return 0 ;
}
static int F_539 ( struct V_1097 * V_1098 , struct V_1099 * V_1100 [] ,
struct V_49 * V_68 ,
const unsigned char * V_551 ,
T_2 V_132 )
{
struct V_1 * V_2 = F_78 ( V_68 ) ;
int V_16 ;
if ( ! ( V_2 -> V_132 & V_424 ) )
return F_540 ( V_1098 , V_1100 , V_68 , V_551 , V_132 ) ;
if ( V_1098 -> V_1101 && ! ( V_1098 -> V_1101 & V_1102 ) ) {
F_40 ( L_140 ,
V_1103 ) ;
return - V_751 ;
}
if ( F_541 ( V_551 ) || F_542 ( V_551 ) ) {
T_1 V_1104 = V_546 ;
if ( F_275 ( V_68 ) < V_1104 )
V_16 = F_543 ( V_68 , V_551 ) ;
else
V_16 = - V_547 ;
} else if ( F_544 ( V_551 ) ) {
V_16 = F_545 ( V_68 , V_551 ) ;
} else {
V_16 = - V_751 ;
}
if ( V_16 == - V_1105 && ! ( V_132 & V_1106 ) )
V_16 = 0 ;
return V_16 ;
}
static int F_546 ( struct V_49 * V_68 ,
struct V_1107 * V_1108 )
{
struct V_1 * V_2 = F_78 ( V_68 ) ;
struct V_1099 * V_1109 , * V_1110 ;
int V_1111 ;
if ( ! ( V_2 -> V_132 & V_424 ) )
return - V_1112 ;
V_1110 = F_547 ( V_1108 , sizeof( struct V_1113 ) , V_1114 ) ;
F_548 (attr, br_spec, rem) {
T_16 V_1115 ;
T_1 V_3 = 0 ;
if ( F_549 ( V_1109 ) != V_1116 )
continue;
V_1115 = F_550 ( V_1109 ) ;
if ( V_1115 == V_1117 ) {
V_3 = 0 ;
V_2 -> V_148 &= ~ V_492 ;
} else if ( V_1115 == V_1118 ) {
V_3 = V_494 ;
V_2 -> V_148 |= V_492 ;
} else
return - V_751 ;
F_60 ( & V_2 -> V_14 , V_493 , V_3 ) ;
F_94 ( V_150 , L_141 ,
V_1115 == V_1117 ? L_142 : L_143 ) ;
}
return 0 ;
}
static int F_551 ( struct V_189 * V_84 , T_1 V_1119 , T_1 V_1120 ,
struct V_49 * V_68 ,
T_1 V_1121 )
{
struct V_1 * V_2 = F_78 ( V_68 ) ;
T_2 V_1115 ;
if ( ! ( V_2 -> V_132 & V_424 ) )
return 0 ;
if ( V_2 -> V_148 & V_492 )
V_1115 = V_1118 ;
else
V_1115 = V_1117 ;
return F_552 ( V_84 , V_1119 , V_1120 , V_68 , V_1115 ) ;
}
static void * F_553 ( struct V_49 * V_9 , struct V_49 * V_612 )
{
struct V_608 * V_1030 = NULL ;
struct V_1 * V_2 = F_78 ( V_9 ) ;
unsigned int V_697 ;
int V_477 , V_16 ;
#ifdef F_554
if ( V_612 -> V_88 != V_612 -> V_72 ) {
F_555 ( V_9 , L_144 ,
V_612 -> V_48 ) ;
return F_556 ( - V_751 ) ;
}
#endif
if ( V_612 -> V_72 > V_756 ||
V_612 -> V_72 == V_1122 ) {
F_555 ( V_9 ,
L_145 ,
V_9 -> V_48 ) ;
return F_556 ( - V_751 ) ;
}
if ( ( ( V_2 -> V_132 & V_133 ) &&
V_2 -> V_619 > V_1089 - 1 ) ||
( V_2 -> V_619 > V_1123 ) )
return F_556 ( - V_753 ) ;
V_1030 = F_557 ( 1 , sizeof( struct V_608 ) , V_746 ) ;
if ( ! V_1030 )
return F_556 ( - V_547 ) ;
V_477 = F_532 ( & V_2 -> V_618 , 32 ) ;
V_2 -> V_619 ++ ;
F_235 ( V_477 , & V_2 -> V_618 ) ;
V_697 = F_558 ( & V_2 -> V_618 , 32 ) ;
V_2 -> V_132 |= V_570 | V_424 ;
V_2 -> V_429 [ V_496 ] . V_697 = V_697 + 1 ;
V_2 -> V_429 [ V_430 ] . V_697 = V_612 -> V_72 ;
V_16 = F_531 ( V_9 , F_239 ( V_9 ) ) ;
if ( V_16 )
goto V_1124;
V_1030 -> V_477 = V_477 ;
V_1030 -> V_141 = V_2 ;
V_16 = F_320 ( V_612 , V_1030 ) ;
if ( V_16 )
goto V_1124;
F_340 ( V_612 ) ;
return V_1030 ;
V_1124:
F_555 ( V_9 ,
L_146 , V_612 -> V_48 ) ;
F_23 ( V_477 , & V_2 -> V_618 ) ;
V_2 -> V_619 -- ;
F_225 ( V_1030 ) ;
return F_556 ( V_16 ) ;
}
static void F_559 ( struct V_49 * V_9 , void * V_1125 )
{
struct V_608 * V_1030 = V_1125 ;
struct V_1 * V_2 = V_1030 -> V_141 ;
unsigned int V_697 ;
F_23 ( V_1030 -> V_477 , & V_2 -> V_618 ) ;
V_2 -> V_619 -- ;
V_697 = F_558 ( & V_2 -> V_618 , 32 ) ;
V_2 -> V_429 [ V_496 ] . V_697 = V_697 + 1 ;
F_318 ( V_1030 -> V_50 , V_1030 ) ;
F_531 ( V_9 , F_239 ( V_9 ) ) ;
F_321 ( V_9 , L_94 ,
V_1030 -> V_477 , V_2 -> V_619 ,
V_1030 -> V_611 ,
V_1030 -> V_611 + V_2 -> V_610 ,
V_2 -> V_618 ) ;
F_225 ( V_1030 ) ;
}
static inline int F_560 ( struct V_1 * V_2 )
{
struct V_622 * V_399 ;
int V_1126 = 0 ;
if ( F_7 ( & V_2 -> V_14 ) ) {
V_1126 = 4 ;
} else {
F_561 (entry, &adapter->pdev->bus_list) {
struct V_5 * V_9 =
F_562 ( V_399 , struct V_5 , V_1127 ) ;
if ( ! V_9 -> V_1128 )
V_1126 ++ ;
}
}
return V_1126 ;
}
int F_563 ( struct V_1 * V_2 , T_2 V_20 ,
T_2 V_1129 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_2 V_1130 = V_2 -> V_1131 & V_1132 ;
int V_1133 = 0 ;
switch ( V_20 ) {
case V_1134 :
switch ( V_1129 ) {
case V_1135 :
if ( V_14 -> V_10 . V_1136 != 0 )
break;
case V_1137 :
case V_1138 :
case V_1139 :
case V_1140 :
case V_1141 :
V_1133 = 1 ;
break;
}
break;
case V_1142 :
switch ( V_1129 ) {
case V_1143 :
V_1133 = 1 ;
break;
}
break;
case V_1144 :
if ( V_1129 != V_1145 )
V_1133 = 1 ;
break;
case V_1146 :
V_1133 = 1 ;
break;
case V_1147 :
case V_1148 :
if ( ( V_1130 == V_1149 ) ||
( ( V_1130 == V_1150 ) &&
( V_14 -> V_10 . V_1136 == 0 ) ) ) {
V_1133 = 1 ;
}
break;
}
return V_1133 ;
}
static int F_564 ( struct V_5 * V_9 , const struct V_1151 * V_1152 )
{
struct V_49 * V_50 ;
struct V_1 * V_2 = NULL ;
struct V_13 * V_14 ;
const struct V_1153 * V_1154 = V_1155 [ V_1152 -> V_1156 ] ;
static int V_1157 ;
int V_43 , V_16 , V_1158 , V_23 ;
unsigned int V_431 = V_1159 ;
T_6 V_1160 [ V_1161 ] ;
#ifdef F_138
T_2 V_1162 ;
#endif
T_1 V_1163 ;
if ( V_9 -> V_1128 ) {
F_565 ( 1 , V_1164 L_147 ,
F_566 ( V_9 ) , V_9 -> V_689 , V_9 -> V_184 ) ;
return - V_751 ;
}
V_16 = F_398 ( V_9 ) ;
if ( V_16 )
return V_16 ;
if ( ! F_567 ( & V_9 -> V_68 , F_233 ( 64 ) ) ) {
V_1158 = 1 ;
} else {
V_16 = F_567 ( & V_9 -> V_68 , F_233 ( 32 ) ) ;
if ( V_16 ) {
F_377 ( & V_9 -> V_68 ,
L_148 ) ;
goto V_1165;
}
V_1158 = 0 ;
}
V_16 = F_568 ( V_9 , F_569 ( V_9 ,
V_1166 ) , V_1103 ) ;
if ( V_16 ) {
F_377 ( & V_9 -> V_68 ,
L_149 , V_16 ) ;
goto V_1167;
}
F_570 ( V_9 ) ;
F_399 ( V_9 ) ;
F_397 ( V_9 ) ;
if ( V_1154 -> V_103 == V_104 ) {
#ifdef F_330
V_431 = 4 * V_717 ;
#else
V_431 = V_696 ;
#endif
}
V_50 = F_571 ( sizeof( struct V_1 ) , V_431 ) ;
if ( ! V_50 ) {
V_16 = - V_547 ;
goto V_1168;
}
F_572 ( V_50 , & V_9 -> V_68 ) ;
V_2 = F_78 ( V_50 ) ;
F_573 ( V_9 , V_2 ) ;
V_2 -> V_50 = V_50 ;
V_2 -> V_9 = V_9 ;
V_14 = & V_2 -> V_14 ;
V_14 -> V_37 = V_2 ;
V_2 -> V_1169 = F_574 ( V_1170 , V_1171 ) ;
V_14 -> V_38 = F_575 ( F_576 ( V_9 , 0 ) ,
F_577 ( V_9 , 0 ) ) ;
V_2 -> V_412 = V_14 -> V_38 ;
if ( ! V_14 -> V_38 ) {
V_16 = - V_743 ;
goto V_1172;
}
V_50 -> V_1173 = & V_1174 ;
F_578 ( V_50 ) ;
V_50 -> V_1175 = 5 * V_953 ;
strncpy ( V_50 -> V_48 , F_566 ( V_9 ) , sizeof( V_50 -> V_48 ) - 1 ) ;
V_2 -> V_1176 = V_1157 ;
memcpy ( & V_14 -> V_103 . V_352 , V_1154 -> V_1177 , sizeof( V_14 -> V_103 . V_352 ) ) ;
V_14 -> V_103 . type = V_1154 -> V_103 ;
memcpy ( & V_14 -> V_1178 . V_352 , V_1154 -> V_1179 , sizeof( V_14 -> V_1178 . V_352 ) ) ;
V_1163 = F_26 ( V_14 , V_1180 ) ;
if ( ! ( V_1163 & ( 1 << 8 ) ) )
V_14 -> V_1178 . V_352 . V_223 = & V_1181 ;
memcpy ( & V_14 -> V_355 . V_352 , V_1154 -> V_1182 , sizeof( V_14 -> V_355 . V_352 ) ) ;
V_14 -> V_355 . V_939 = V_1183 ;
V_14 -> V_355 . V_1067 . V_1064 = V_1184 ;
V_14 -> V_355 . V_1067 . V_1185 = 0 ;
V_14 -> V_355 . V_1067 . V_1186 = V_1187 | V_1188 ;
V_14 -> V_355 . V_1067 . V_68 = V_50 ;
V_14 -> V_355 . V_1067 . V_1189 = F_510 ;
V_14 -> V_355 . V_1067 . V_1190 = F_511 ;
V_1154 -> V_1191 ( V_14 ) ;
V_16 = F_363 ( V_2 ) ;
if ( V_16 )
goto V_1192;
if ( V_14 -> V_103 . V_352 . V_1193 )
V_14 -> V_1193 = V_14 -> V_103 . V_352 . V_1193 ( V_14 ) ;
switch ( V_2 -> V_14 . V_103 . type ) {
case V_106 :
case V_107 :
F_60 ( & V_2 -> V_14 , V_758 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_132 & V_358 ) {
T_1 V_665 = F_26 ( V_14 , V_666 ) ;
if ( V_665 & V_667 )
F_198 ( V_166 , L_73 ) ;
}
if ( V_1194 )
V_14 -> V_1194 = V_1194 ;
V_14 -> V_355 . V_1195 = true ;
V_16 = V_14 -> V_103 . V_352 . V_1196 ( V_14 ) ;
V_14 -> V_355 . V_1195 = false ;
if ( V_16 == V_673 &&
V_14 -> V_103 . type == V_104 ) {
V_16 = 0 ;
} else if ( V_16 == V_674 ) {
F_17 ( L_150 ) ;
F_17 ( L_151 ) ;
goto V_1192;
} else if ( V_16 ) {
F_17 ( L_152 , V_16 ) ;
goto V_1192;
}
#ifdef F_367
if ( V_2 -> V_14 . V_103 . type == V_104 )
goto V_1197;
F_579 ( V_14 ) ;
memcpy ( & V_14 -> V_1198 . V_352 , V_1154 -> V_1199 , sizeof( V_14 -> V_1198 . V_352 ) ) ;
F_580 ( V_9 , V_735 ) ;
F_581 ( V_2 ) ;
V_1197:
#endif
V_50 -> V_190 = V_1200 |
V_1201 |
V_1202 |
V_1203 |
V_262 |
V_1204 |
V_1205 |
V_1206 |
V_191 |
V_203 ;
V_50 -> V_1207 = V_50 -> V_190 | V_1208 ;
switch ( V_2 -> V_14 . V_103 . type ) {
case V_106 :
case V_107 :
V_50 -> V_190 |= V_1209 ;
V_50 -> V_1207 |= V_1209 |
V_1096 ;
break;
default:
break;
}
V_50 -> V_1207 |= V_285 ;
V_50 -> V_1210 |= V_1205 ;
V_50 -> V_1210 |= V_1206 ;
V_50 -> V_1210 |= V_1201 ;
V_50 -> V_1210 |= V_1202 ;
V_50 -> V_1210 |= V_1200 ;
V_50 -> V_1211 |= V_1212 ;
V_50 -> V_1211 |= V_1213 ;
#ifdef F_330
V_50 -> V_1214 = & V_1214 ;
#endif
#ifdef F_138
if ( V_2 -> V_132 & V_704 ) {
unsigned int V_1215 ;
if ( V_14 -> V_103 . V_352 . V_1216 ) {
V_14 -> V_103 . V_352 . V_1216 ( V_14 , & V_1162 ) ;
if ( V_1162 & V_1217 )
V_2 -> V_132 &= ~ V_704 ;
}
V_1215 = F_322 ( int , V_1218 , F_364 () ) ;
V_2 -> V_429 [ V_1036 ] . V_697 = V_1215 ;
V_50 -> V_190 |= V_1054 |
V_1055 ;
V_50 -> V_1210 |= V_1054 |
V_1055 |
V_575 ;
}
#endif
if ( V_1158 ) {
V_50 -> V_190 |= V_1219 ;
V_50 -> V_1210 |= V_1219 ;
}
if ( V_2 -> V_148 & V_698 )
V_50 -> V_1207 |= V_1092 ;
if ( V_2 -> V_148 & V_518 )
V_50 -> V_190 |= V_1092 ;
if ( V_14 -> V_1178 . V_352 . V_1220 ( V_14 , NULL ) < 0 ) {
F_17 ( L_153 ) ;
V_16 = - V_743 ;
goto V_1192;
}
memcpy ( V_50 -> V_621 , V_14 -> V_103 . V_1221 , V_50 -> V_1063 ) ;
if ( ! F_325 ( V_50 -> V_621 ) ) {
F_17 ( L_154 ) ;
V_16 = - V_743 ;
goto V_1192;
}
F_582 ( & V_2 -> V_668 , & F_454 ,
( unsigned long ) V_2 ) ;
F_583 ( & V_2 -> V_36 , F_456 ) ;
F_23 ( V_35 , & V_2 -> V_33 ) ;
V_16 = F_402 ( V_2 ) ;
if ( V_16 )
goto V_1192;
V_2 -> V_762 = 0 ;
V_14 -> V_1178 . V_352 . V_223 ( V_14 , 0x2c , & V_2 -> V_1131 ) ;
V_14 -> V_1222 = F_563 ( V_2 , V_9 -> V_184 ,
V_9 -> V_695 ) ;
if ( V_14 -> V_1222 )
V_2 -> V_762 = V_1223 ;
F_584 ( & V_2 -> V_9 -> V_68 , V_2 -> V_762 ) ;
V_14 -> V_1178 . V_352 . V_223 ( V_14 , 0x2e , & V_2 -> V_1224 ) ;
V_14 -> V_1178 . V_352 . V_223 ( V_14 , 0x2d , & V_2 -> V_1225 ) ;
V_14 -> V_103 . V_352 . V_1226 ( V_14 ) ;
if ( F_7 ( V_14 ) )
F_4 ( V_2 ) ;
switch ( V_14 -> V_103 . type ) {
case V_104 :
V_23 = F_585 ( F_560 ( V_2 ) * 10 , 16 ) ;
break;
default:
V_23 = F_560 ( V_2 ) * 10 ;
break;
}
F_8 ( V_2 , V_23 ) ;
V_16 = F_586 ( V_14 , V_1160 , V_1161 ) ;
if ( V_16 )
strncpy ( V_1160 , L_7 , V_1161 ) ;
if ( F_334 ( V_14 ) && V_14 -> V_355 . V_939 != V_1227 )
F_11 ( L_155 ,
V_14 -> V_103 . type , V_14 -> V_355 . type , V_14 -> V_355 . V_939 ,
V_1160 ) ;
else
F_11 ( L_156 ,
V_14 -> V_103 . type , V_14 -> V_355 . type , V_1160 ) ;
F_11 ( L_157 , V_50 -> V_621 ) ;
V_16 = V_14 -> V_103 . V_352 . V_1228 ( V_14 ) ;
if ( V_16 == V_676 ) {
F_10 ( L_97
L_158
L_159
L_160
L_101
L_102 ) ;
}
strcpy ( V_50 -> V_48 , L_161 ) ;
V_16 = F_587 ( V_50 ) ;
if ( V_16 )
goto V_1229;
if ( V_14 -> V_103 . V_352 . V_684 )
V_14 -> V_103 . V_352 . V_684 ( V_14 ) ;
F_356 ( V_50 ) ;
#ifdef F_216
if ( F_115 ( & V_9 -> V_68 ) == 0 ) {
V_2 -> V_132 |= V_181 ;
F_112 ( V_2 ) ;
}
#endif
if ( V_2 -> V_132 & V_424 ) {
F_94 ( V_166 , L_162 , V_2 -> V_319 ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_319 ; V_43 ++ )
F_588 ( V_9 , ( V_43 | 0x10000000 ) ) ;
}
if ( V_14 -> V_103 . V_352 . V_1230 )
V_14 -> V_103 . V_352 . V_1230 ( V_14 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_516 ( V_50 ) ;
F_11 ( L_163 , V_1231 ) ;
V_1157 ++ ;
#ifdef F_589
if ( F_590 ( V_2 ) )
F_92 ( V_166 , L_164 ) ;
#endif
F_591 ( V_2 ) ;
if ( V_14 -> V_1193 && V_14 -> V_103 . V_352 . V_648 )
V_14 -> V_103 . V_352 . V_648 ( V_14 ,
V_907 | V_930 ,
true ) ;
return 0 ;
V_1229:
F_59 ( V_2 ) ;
F_408 ( V_2 ) ;
V_1192:
F_592 ( V_2 ) ;
V_2 -> V_148 &= ~ V_642 ;
F_593 ( V_2 -> V_412 ) ;
V_1172:
F_594 ( V_50 ) ;
V_1168:
F_595 ( V_9 ,
F_569 ( V_9 , V_1166 ) ) ;
V_1167:
V_1165:
F_409 ( V_9 ) ;
return V_16 ;
}
static void F_596 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_394 ( V_9 ) ;
struct V_49 * V_50 = V_2 -> V_50 ;
F_597 ( V_2 ) ;
F_235 ( V_34 , & V_2 -> V_33 ) ;
F_598 ( & V_2 -> V_36 ) ;
#ifdef F_216
if ( V_2 -> V_132 & V_181 ) {
V_2 -> V_132 &= ~ V_181 ;
F_116 ( & V_9 -> V_68 ) ;
F_60 ( & V_2 -> V_14 , V_182 , 1 ) ;
}
#endif
#ifdef F_589
F_599 ( V_2 ) ;
#endif
F_518 ( V_50 ) ;
if ( V_50 -> V_940 == V_941 )
F_450 ( V_50 ) ;
#ifdef F_367
if ( V_734 )
F_592 ( V_2 ) ;
#endif
F_408 ( V_2 ) ;
F_59 ( V_2 ) ;
#ifdef F_600
F_225 ( V_2 -> V_131 ) ;
F_225 ( V_2 -> V_580 ) ;
#endif
F_593 ( V_2 -> V_412 ) ;
F_595 ( V_9 , F_569 ( V_9 ,
V_1166 ) ) ;
F_11 ( L_165 ) ;
F_594 ( V_50 ) ;
F_601 ( V_9 ) ;
F_409 ( V_9 ) ;
}
static T_17 F_602 ( struct V_5 * V_9 ,
T_18 V_33 )
{
struct V_1 * V_2 = F_394 ( V_9 ) ;
struct V_49 * V_50 = V_2 -> V_50 ;
#ifdef F_367
struct V_5 * V_1232 , * V_1233 ;
T_1 V_1234 , V_1235 , V_1236 , V_1237 ;
int V_942 , V_1238 ;
T_2 V_1239 , V_1240 ;
if ( V_2 -> V_14 . V_103 . type == V_104 ||
V_2 -> V_319 == 0 )
goto V_1241;
V_1232 = V_9 -> V_10 -> V_12 ;
while ( V_1232 && ( F_603 ( V_1232 ) != V_1242 ) )
V_1232 = V_1232 -> V_10 -> V_12 ;
if ( ! V_1232 )
goto V_1241;
V_1238 = F_604 ( V_1232 , V_1243 ) ;
if ( ! V_1238 )
goto V_1241;
F_605 ( V_1232 , V_1238 + V_1244 , & V_1234 ) ;
F_605 ( V_1232 , V_1238 + V_1244 + 4 , & V_1235 ) ;
F_605 ( V_1232 , V_1238 + V_1244 + 8 , & V_1236 ) ;
F_605 ( V_1232 , V_1238 + V_1244 + 12 , & V_1237 ) ;
V_1239 = V_1235 >> 16 ;
if ( ! ( V_1239 & 0x0080 ) )
goto V_1241;
V_1240 = V_1239 & 0x01 ;
if ( ( V_1240 & 1 ) == ( V_9 -> V_1245 & 1 ) ) {
unsigned int V_20 ;
V_942 = ( V_1239 & 0x7F ) >> 1 ;
F_17 ( L_166 , V_942 ) ;
F_17 ( L_167
L_168 ,
V_1234 , V_1235 , V_1236 , V_1237 ) ;
switch ( V_2 -> V_14 . V_103 . type ) {
case V_106 :
V_20 = V_1246 ;
break;
case V_107 :
V_20 = V_1247 ;
break;
default:
V_20 = 0 ;
break;
}
V_1233 = F_606 ( V_1248 , V_20 , NULL ) ;
while ( V_1233 ) {
if ( V_1233 -> V_1245 == ( V_1239 & 0xFF ) )
break;
V_1233 = F_606 ( V_1248 ,
V_20 , V_1233 ) ;
}
if ( V_1233 ) {
F_17 ( L_169 , V_942 ) ;
F_607 ( V_1233 , 0xA8 , 0x00008000 ) ;
F_608 ( V_1233 ) ;
}
F_609 ( V_9 ) ;
}
V_2 -> V_1249 ++ ;
return V_1250 ;
V_1241:
#endif
F_407 ( V_50 ) ;
if ( V_33 == V_1251 )
return V_1252 ;
if ( F_46 ( V_50 ) )
F_345 ( V_2 ) ;
F_409 ( V_9 ) ;
return V_1253 ;
}
static T_17 F_610 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_394 ( V_9 ) ;
T_17 V_1254 ;
int V_16 ;
if ( F_398 ( V_9 ) ) {
F_92 ( V_166 , L_170 ) ;
V_1254 = V_1252 ;
} else {
F_399 ( V_9 ) ;
F_396 ( V_9 ) ;
F_397 ( V_9 ) ;
F_400 ( V_9 , false ) ;
F_348 ( V_2 ) ;
F_60 ( & V_2 -> V_14 , V_758 , ~ 0 ) ;
V_1254 = V_1250 ;
}
V_16 = F_609 ( V_9 ) ;
if ( V_16 ) {
F_17 ( L_171
L_172 , V_16 ) ;
}
return V_1254 ;
}
static void F_611 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_394 ( V_9 ) ;
struct V_49 * V_50 = V_2 -> V_50 ;
#ifdef F_367
if ( V_2 -> V_1249 ) {
F_94 ( V_150 , L_173 ) ;
V_2 -> V_1249 -- ;
return;
}
#endif
if ( F_46 ( V_50 ) )
F_347 ( V_2 ) ;
F_404 ( V_50 ) ;
}
static int T_19 F_612 ( void )
{
int V_147 ;
F_40 ( L_174 , V_1255 , V_1256 ) ;
F_40 ( L_163 , V_1257 ) ;
F_613 () ;
V_147 = F_614 ( & V_1258 ) ;
if ( V_147 ) {
F_615 () ;
return V_147 ;
}
#ifdef F_216
F_616 ( & V_1259 ) ;
#endif
return 0 ;
}
static void T_20 F_617 ( void )
{
#ifdef F_216
F_618 ( & V_1259 ) ;
#endif
F_619 ( & V_1258 ) ;
F_615 () ;
F_620 () ;
}
static int F_621 ( struct V_1260 * V_1261 , unsigned long V_185 ,
void * V_1059 )
{
int V_1262 ;
V_1262 = F_622 ( & V_1258 . V_1263 , NULL , & V_185 ,
F_113 ) ;
return V_1262 ? V_1264 : V_1265 ;
}
