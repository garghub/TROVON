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
if ( * V_4 == V_13 &&
F_4 ( & V_2 -> V_14 , V_6 ) )
return - 1 ;
return 0 ;
}
static T_3 F_5 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_16 = 0 ;
int V_17 ;
V_14 -> V_10 . type = V_18 ;
V_17 = F_1 ( V_2 , 18 , & V_16 ) ;
if ( V_17 )
return V_17 ;
V_14 -> V_10 . V_19 = F_6 ( V_16 ) ;
V_14 -> V_10 . V_20 = F_7 ( V_16 ) ;
return 0 ;
}
static inline bool F_8 ( struct V_15 * V_14 )
{
switch ( V_14 -> V_21 ) {
case V_22 :
case V_23 :
return true ;
default:
return false ;
}
}
static void F_9 ( struct V_1 * V_2 ,
int V_24 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_25 = 0 ;
enum V_26 V_20 = V_27 ;
enum V_28 V_19 = V_29 ;
struct V_5 * V_9 ;
if ( V_14 -> V_10 . type == V_30 )
return;
if ( F_8 ( & V_2 -> V_14 ) )
V_9 = V_2 -> V_9 -> V_10 -> V_11 -> V_12 ;
else
V_9 = V_2 -> V_9 ;
if ( F_10 ( V_9 , & V_20 , & V_19 ) ||
V_20 == V_27 || V_19 == V_29 ) {
F_11 ( L_1 ) ;
return;
}
switch ( V_20 ) {
case V_31 :
V_25 = 2 * V_19 ;
break;
case V_32 :
V_25 = 4 * V_19 ;
break;
case V_33 :
V_25 = 8 * V_19 ;
break;
default:
F_11 ( L_1 ) ;
return;
}
F_12 ( L_2 ,
V_25 ) ;
F_12 ( L_3 ,
( V_20 == V_33 ? L_4 :
V_20 == V_32 ? L_5 :
V_20 == V_31 ? L_6 :
L_7 ) ,
V_19 ,
( V_20 == V_31 ? L_8 :
V_20 == V_32 ? L_8 :
V_20 == V_33 ? L_9 :
L_7 ) ) ;
if ( V_25 < V_24 ) {
F_11 ( L_10 ) ;
F_11 ( L_11 ,
V_24 ) ;
F_11 ( L_12 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) &&
! F_14 ( V_36 , & V_2 -> V_35 ) &&
! F_15 ( V_37 , & V_2 -> V_35 ) )
F_16 ( V_38 , & V_2 -> V_39 ) ;
}
static void F_17 ( struct V_15 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_40 ;
if ( ! V_14 -> V_41 )
return;
V_14 -> V_41 = NULL ;
F_18 ( L_13 ) ;
if ( F_14 ( V_42 , & V_2 -> V_35 ) )
F_13 ( V_2 ) ;
}
static void F_19 ( struct V_15 * V_14 , T_1 V_3 )
{
T_1 V_4 ;
if ( V_3 == V_43 ) {
F_17 ( V_14 ) ;
return;
}
V_4 = F_20 ( V_14 , V_43 ) ;
if ( V_4 == V_44 )
F_17 ( V_14 ) ;
}
T_1 F_20 ( struct V_15 * V_14 , T_1 V_3 )
{
T_4 T_5 * V_45 = F_21 ( V_14 -> V_41 ) ;
T_1 V_4 ;
if ( F_22 ( V_45 ) )
return V_44 ;
if ( F_23 ( V_14 -> V_46 . V_47 &
V_48 ) ) {
struct V_1 * V_2 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < 200 ; ++ V_49 ) {
V_4 = F_24 ( V_45 + V_50 ) ;
if ( F_25 ( ! V_4 ) )
goto V_51;
if ( V_4 == V_44 ) {
F_17 ( V_14 ) ;
return V_44 ;
}
F_26 ( 5 ) ;
}
V_2 = V_14 -> V_40 ;
F_27 ( V_14 , L_14 , V_4 ) ;
}
V_51:
V_4 = F_24 ( V_45 + V_3 ) ;
if ( F_23 ( V_4 == V_44 ) )
F_19 ( V_14 , V_3 ) ;
return V_4 ;
}
static bool F_4 ( struct V_15 * V_14 , struct V_5 * V_9 )
{
T_2 V_4 ;
F_28 ( V_9 , V_52 , & V_4 ) ;
if ( V_4 == V_13 ) {
F_17 ( V_14 ) ;
return true ;
}
return false ;
}
T_2 F_29 ( struct V_15 * V_14 , T_1 V_3 )
{
struct V_1 * V_2 = V_14 -> V_40 ;
T_2 V_4 ;
if ( F_22 ( V_14 -> V_41 ) )
return V_13 ;
F_28 ( V_2 -> V_9 , V_3 , & V_4 ) ;
if ( V_4 == V_13 &&
F_4 ( V_14 , V_2 -> V_9 ) )
return V_13 ;
return V_4 ;
}
static T_1 F_30 ( struct V_15 * V_14 , T_1 V_3 )
{
struct V_1 * V_2 = V_14 -> V_40 ;
T_1 V_4 ;
if ( F_22 ( V_14 -> V_41 ) )
return V_53 ;
F_31 ( V_2 -> V_9 , V_3 , & V_4 ) ;
if ( V_4 == V_53 &&
F_4 ( V_14 , V_2 -> V_9 ) )
return V_53 ;
return V_4 ;
}
void F_32 ( struct V_15 * V_14 , T_1 V_3 , T_2 V_4 )
{
struct V_1 * V_2 = V_14 -> V_40 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
F_33 ( V_2 -> V_9 , V_3 , V_4 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_35 ( ! F_14 ( V_37 , & V_2 -> V_35 ) ) ;
F_36 () ;
F_37 ( V_37 , & V_2 -> V_35 ) ;
}
static void F_38 ( struct V_15 * V_14 , struct V_54 * V_55 )
{
int V_49 = 0 , V_56 = 0 ;
char V_57 [ 16 ] ;
T_1 V_58 [ 64 ] ;
switch ( V_55 -> V_59 ) {
case F_39 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_58 [ V_49 ] = F_40 ( V_14 , F_39 ( V_49 ) ) ;
break;
case F_41 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_58 [ V_49 ] = F_40 ( V_14 , F_41 ( V_49 ) ) ;
break;
case F_42 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_58 [ V_49 ] = F_40 ( V_14 , F_42 ( V_49 ) ) ;
break;
case F_43 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_58 [ V_49 ] = F_40 ( V_14 , F_43 ( V_49 ) ) ;
break;
case F_44 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_58 [ V_49 ] = F_40 ( V_14 , F_44 ( V_49 ) ) ;
break;
case F_45 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_58 [ V_49 ] = F_40 ( V_14 , F_45 ( V_49 ) ) ;
break;
case F_46 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_58 [ V_49 ] = F_40 ( V_14 , F_46 ( V_49 ) ) ;
break;
case F_47 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_58 [ V_49 ] = F_40 ( V_14 , F_47 ( V_49 ) ) ;
break;
case F_48 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_58 [ V_49 ] = F_40 ( V_14 , F_48 ( V_49 ) ) ;
break;
case F_49 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_58 [ V_49 ] = F_40 ( V_14 , F_49 ( V_49 ) ) ;
break;
case F_50 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_58 [ V_49 ] = F_40 ( V_14 , F_50 ( V_49 ) ) ;
break;
case F_51 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_58 [ V_49 ] = F_40 ( V_14 , F_51 ( V_49 ) ) ;
break;
case F_52 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_58 [ V_49 ] = F_40 ( V_14 , F_52 ( V_49 ) ) ;
break;
case F_53 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_58 [ V_49 ] = F_40 ( V_14 , F_53 ( V_49 ) ) ;
break;
default:
F_54 ( L_15 , V_55 -> V_60 ,
F_40 ( V_14 , V_55 -> V_59 ) ) ;
return;
}
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
snprintf ( V_57 , 16 , L_16 , V_55 -> V_60 , V_49 * 8 , V_49 * 8 + 7 ) ;
F_55 ( L_17 , V_57 ) ;
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ )
F_56 ( L_18 , V_58 [ V_49 * 8 + V_56 ] ) ;
F_56 ( L_19 ) ;
}
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_55 ;
int V_63 = 0 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
union V_68 * V_69 ;
struct V_70 { T_6 V_71 ; T_6 V_72 ; } * V_73 ;
struct V_64 * V_74 ;
union V_75 * V_76 ;
struct V_77 * V_78 ;
T_1 V_79 ;
int V_49 = 0 ;
if ( ! F_58 ( V_2 ) )
return;
if ( V_62 ) {
F_59 ( & V_2 -> V_9 -> V_80 , L_20 ) ;
F_54 ( L_21
L_22 ) ;
F_54 ( L_23 ,
V_62 -> V_60 ,
V_62 -> V_35 ,
F_60 ( V_62 ) ) ;
}
F_59 ( & V_2 -> V_9 -> V_80 , L_24 ) ;
F_54 ( L_25 ) ;
for ( V_55 = (struct V_54 * ) V_81 ;
V_55 -> V_60 ; V_55 ++ ) {
F_38 ( V_14 , V_55 ) ;
}
if ( ! V_62 || ! F_61 ( V_62 ) )
return;
F_59 ( & V_2 -> V_9 -> V_80 , L_26 ) ;
F_54 ( L_27 ,
L_28 ,
L_29 , L_30 , L_31 ) ;
for ( V_63 = 0 ; V_63 < V_2 -> V_82 ; V_63 ++ ) {
V_65 = V_2 -> V_65 [ V_63 ] ;
V_67 = & V_65 -> V_83 [ V_65 -> V_84 ] ;
F_54 ( L_32 ,
V_63 , V_65 -> V_85 , V_65 -> V_84 ,
( T_6 ) F_62 ( V_67 , V_86 ) ,
F_63 ( V_67 , V_87 ) ,
V_67 -> V_88 ,
( T_6 ) V_67 -> V_89 ) ;
}
if ( ! F_64 ( V_2 ) )
goto V_90;
F_59 ( & V_2 -> V_9 -> V_80 , L_33 ) ;
for ( V_63 = 0 ; V_63 < V_2 -> V_82 ; V_63 ++ ) {
V_65 = V_2 -> V_65 [ V_63 ] ;
F_54 ( L_34 ) ;
F_54 ( L_35 , V_65 -> V_91 ) ;
F_54 ( L_34 ) ;
F_54 ( L_36 ,
L_37 ,
L_38 ,
L_29 , L_30 , L_31 , L_39 ) ;
for ( V_49 = 0 ; V_65 -> V_92 && ( V_49 < V_65 -> V_93 ) ; V_49 ++ ) {
V_69 = F_65 ( V_65 , V_49 ) ;
V_67 = & V_65 -> V_83 [ V_49 ] ;
V_73 = (struct V_70 * ) V_69 ;
if ( F_63 ( V_67 , V_87 ) > 0 ) {
F_54 ( L_40 ,
V_49 ,
F_66 ( V_73 -> V_71 ) ,
F_66 ( V_73 -> V_72 ) ,
( T_6 ) F_62 ( V_67 , V_86 ) ,
F_63 ( V_67 , V_87 ) ,
V_67 -> V_88 ,
( T_6 ) V_67 -> V_89 ,
V_67 -> V_94 ) ;
if ( V_49 == V_65 -> V_85 &&
V_49 == V_65 -> V_84 )
F_56 ( L_41 ) ;
else if ( V_49 == V_65 -> V_85 )
F_56 ( L_42 ) ;
else if ( V_49 == V_65 -> V_84 )
F_56 ( L_43 ) ;
else
F_56 ( L_19 ) ;
if ( F_67 ( V_2 ) &&
V_67 -> V_94 )
F_68 ( V_95 , L_44 ,
V_96 , 16 , 1 ,
V_67 -> V_94 -> V_97 ,
F_63 ( V_67 , V_87 ) ,
true ) ;
}
}
}
V_90:
F_59 ( & V_2 -> V_9 -> V_80 , L_45 ) ;
F_54 ( L_46 ) ;
for ( V_63 = 0 ; V_63 < V_2 -> V_98 ; V_63 ++ ) {
V_74 = V_2 -> V_74 [ V_63 ] ;
F_54 ( L_47 ,
V_63 , V_74 -> V_85 , V_74 -> V_84 ) ;
}
if ( ! F_69 ( V_2 ) )
return;
F_59 ( & V_2 -> V_9 -> V_80 , L_48 ) ;
for ( V_63 = 0 ; V_63 < V_2 -> V_98 ; V_63 ++ ) {
V_74 = V_2 -> V_74 [ V_63 ] ;
F_54 ( L_34 ) ;
F_54 ( L_49 , V_74 -> V_91 ) ;
F_54 ( L_34 ) ;
F_54 ( L_50 ,
L_51 ,
L_52 ,
L_53 ) ;
F_54 ( L_50 ,
L_54 ,
L_55 ,
L_56 ) ;
for ( V_49 = 0 ; V_49 < V_74 -> V_93 ; V_49 ++ ) {
V_78 = & V_74 -> V_78 [ V_49 ] ;
V_76 = F_70 ( V_74 , V_49 ) ;
V_73 = (struct V_70 * ) V_76 ;
V_79 = F_71 ( V_76 -> V_99 . V_100 . V_101 ) ;
if ( V_79 & V_102 ) {
F_54 ( L_57
L_58 , V_49 ,
F_66 ( V_73 -> V_71 ) ,
F_66 ( V_73 -> V_72 ) ,
V_78 -> V_94 ) ;
} else {
F_54 ( L_59
L_60 , V_49 ,
F_66 ( V_73 -> V_71 ) ,
F_66 ( V_73 -> V_72 ) ,
( T_6 ) V_78 -> V_86 ,
V_78 -> V_94 ) ;
if ( F_67 ( V_2 ) &&
V_78 -> V_86 ) {
F_68 ( V_95 , L_44 ,
V_96 , 16 , 1 ,
F_72 ( V_78 -> V_103 ) +
V_78 -> V_104 ,
F_73 ( V_74 ) , true ) ;
}
}
if ( V_49 == V_74 -> V_85 )
F_56 ( L_42 ) ;
else if ( V_49 == V_74 -> V_84 )
F_56 ( L_43 ) ;
else
F_56 ( L_19 ) ;
}
}
}
static void F_74 ( struct V_1 * V_2 )
{
T_1 V_105 ;
V_105 = F_40 ( & V_2 -> V_14 , V_106 ) ;
F_75 ( & V_2 -> V_14 , V_106 ,
V_105 & ~ V_107 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
T_1 V_105 ;
V_105 = F_40 ( & V_2 -> V_14 , V_106 ) ;
F_75 ( & V_2 -> V_14 , V_106 ,
V_105 | V_107 ) ;
}
static void F_77 ( struct V_1 * V_2 , T_7 V_108 ,
T_4 V_109 , T_4 V_110 )
{
T_1 V_111 , V_112 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_113 . type ) {
case V_114 :
V_110 |= V_115 ;
if ( V_108 == - 1 )
V_108 = 0 ;
V_112 = ( ( ( V_108 * 64 ) + V_109 ) >> 2 ) & 0x1F ;
V_111 = F_40 ( V_14 , F_78 ( V_112 ) ) ;
V_111 &= ~ ( 0xFF << ( 8 * ( V_109 & 0x3 ) ) ) ;
V_111 |= ( V_110 << ( 8 * ( V_109 & 0x3 ) ) ) ;
F_75 ( V_14 , F_78 ( V_112 ) , V_111 ) ;
break;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
if ( V_108 == - 1 ) {
V_110 |= V_115 ;
V_112 = ( ( V_109 & 1 ) * 8 ) ;
V_111 = F_40 ( & V_2 -> V_14 , V_121 ) ;
V_111 &= ~ ( 0xFF << V_112 ) ;
V_111 |= ( V_110 << V_112 ) ;
F_75 ( & V_2 -> V_14 , V_121 , V_111 ) ;
break;
} else {
V_110 |= V_115 ;
V_112 = ( ( 16 * ( V_109 & 1 ) ) + ( 8 * V_108 ) ) ;
V_111 = F_40 ( V_14 , F_78 ( V_109 >> 1 ) ) ;
V_111 &= ~ ( 0xFF << V_112 ) ;
V_111 |= ( V_110 << V_112 ) ;
F_75 ( V_14 , F_78 ( V_109 >> 1 ) , V_111 ) ;
break;
}
default:
break;
}
}
static inline void F_79 ( struct V_1 * V_2 ,
T_6 V_122 )
{
T_1 V_123 ;
switch ( V_2 -> V_14 . V_113 . type ) {
case V_114 :
V_123 = ( V_124 & V_122 ) ;
F_75 ( & V_2 -> V_14 , V_125 , V_123 ) ;
break;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_123 = ( V_122 & 0xFFFFFFFF ) ;
F_75 ( & V_2 -> V_14 , F_80 ( 0 ) , V_123 ) ;
V_123 = ( V_122 >> 32 ) ;
F_75 ( & V_2 -> V_14 , F_80 ( 1 ) , V_123 ) ;
break;
default:
break;
}
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_126 * V_127 = & V_2 -> V_128 ;
int V_49 ;
T_1 V_97 ;
if ( ( V_14 -> V_129 . V_130 != V_131 ) &&
( V_14 -> V_129 . V_130 != V_132 ) )
return;
switch ( V_14 -> V_113 . type ) {
case V_114 :
V_97 = F_40 ( V_14 , V_133 ) ;
break;
default:
V_97 = F_40 ( V_14 , V_134 ) ;
}
V_127 -> V_135 += V_97 ;
if ( ! V_97 )
return;
for ( V_49 = 0 ; V_49 < V_2 -> V_82 ; V_49 ++ )
F_37 ( V_136 ,
& V_2 -> V_65 [ V_49 ] -> V_35 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_126 * V_127 = & V_2 -> V_128 ;
T_1 V_137 [ 8 ] = { 0 } ;
T_4 V_138 ;
int V_49 ;
bool V_139 = V_2 -> V_140 . V_141 ;
if ( V_2 -> V_142 )
V_139 |= ! ! ( V_2 -> V_142 -> V_139 ) ;
if ( ! ( V_2 -> V_143 & V_144 ) || ! V_139 ) {
F_81 ( V_2 ) ;
return;
}
for ( V_49 = 0 ; V_49 < V_145 ; V_49 ++ ) {
T_1 V_146 ;
switch ( V_14 -> V_113 . type ) {
case V_114 :
V_146 = F_40 ( V_14 , F_83 ( V_49 ) ) ;
break;
default:
V_146 = F_40 ( V_14 , F_84 ( V_49 ) ) ;
}
V_127 -> V_146 [ V_49 ] += V_146 ;
V_138 = F_85 ( V_2 -> V_62 , V_49 ) ;
V_137 [ V_138 ] += V_146 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_82 ; V_49 ++ ) {
struct V_64 * V_65 = V_2 -> V_65 [ V_49 ] ;
V_138 = V_65 -> V_147 ;
if ( V_137 [ V_138 ] )
F_37 ( V_136 , & V_65 -> V_35 ) ;
}
}
static T_6 F_86 ( struct V_64 * V_148 )
{
return V_148 -> V_128 . V_149 ;
}
static T_6 F_87 ( struct V_64 * V_148 )
{
struct V_1 * V_2 ;
struct V_15 * V_14 ;
T_1 V_150 , V_151 ;
if ( V_148 -> V_152 )
V_2 = V_148 -> V_152 -> V_153 ;
else
V_2 = F_88 ( V_148 -> V_62 ) ;
V_14 = & V_2 -> V_14 ;
V_150 = F_40 ( V_14 , F_51 ( V_148 -> V_154 ) ) ;
V_151 = F_40 ( V_14 , F_52 ( V_148 -> V_154 ) ) ;
if ( V_150 != V_151 )
return ( V_150 < V_151 ) ?
V_151 - V_150 : ( V_151 + V_148 -> V_93 - V_150 ) ;
return 0 ;
}
static inline bool F_89 ( struct V_64 * V_65 )
{
T_1 V_155 = F_86 ( V_65 ) ;
T_1 V_156 = V_65 -> V_157 . V_156 ;
T_1 V_158 = F_87 ( V_65 ) ;
F_90 ( V_65 ) ;
if ( V_156 == V_155 && V_158 )
return F_15 ( V_136 ,
& V_65 -> V_35 ) ;
V_65 -> V_157 . V_156 = V_155 ;
F_37 ( V_136 , & V_65 -> V_35 ) ;
return false ;
}
static void F_91 ( struct V_1 * V_2 )
{
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_92 ( V_159 , & V_2 -> V_35 ) ;
F_27 ( V_160 , L_61 ) ;
F_13 ( V_2 ) ;
}
}
static int F_93 ( struct V_61 * V_62 ,
int V_91 , T_1 V_161 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_162 = F_94 ( V_2 ) ;
if ( ! V_161 )
return 0 ;
V_162 <<= V_163 ;
V_162 /= V_161 ;
V_162 &= V_164 |
V_165 ;
V_162 |= V_166 ;
F_75 ( V_14 , V_167 , V_91 ) ;
F_75 ( V_14 , V_168 , V_162 ) ;
return 0 ;
}
static bool F_95 ( struct V_169 * V_170 ,
struct V_64 * V_65 , int V_171 )
{
struct V_1 * V_2 = V_170 -> V_2 ;
struct V_66 * V_67 ;
union V_68 * V_69 ;
unsigned int V_172 = 0 , V_173 = 0 ;
unsigned int V_174 = V_170 -> V_175 . V_176 ;
unsigned int V_49 = V_65 -> V_84 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return true ;
V_67 = & V_65 -> V_83 [ V_49 ] ;
V_69 = F_65 ( V_65 , V_49 ) ;
V_49 -= V_65 -> V_93 ;
do {
union V_68 * V_177 = V_67 -> V_88 ;
if ( ! V_177 )
break;
F_96 () ;
if ( ! ( V_177 -> V_99 . V_178 & F_97 ( V_179 ) ) )
break;
V_67 -> V_88 = NULL ;
V_172 += V_67 -> V_180 ;
V_173 += V_67 -> V_181 ;
F_98 ( V_67 -> V_94 , V_171 ) ;
F_99 ( V_65 -> V_80 ,
F_62 ( V_67 , V_86 ) ,
F_63 ( V_67 , V_87 ) ,
V_182 ) ;
F_100 ( V_67 , V_87 , 0 ) ;
while ( V_69 != V_177 ) {
V_67 ++ ;
V_69 ++ ;
V_49 ++ ;
if ( F_23 ( ! V_49 ) ) {
V_49 -= V_65 -> V_93 ;
V_67 = V_65 -> V_83 ;
V_69 = F_65 ( V_65 , 0 ) ;
}
if ( F_63 ( V_67 , V_87 ) ) {
F_101 ( V_65 -> V_80 ,
F_62 ( V_67 , V_86 ) ,
F_63 ( V_67 , V_87 ) ,
V_182 ) ;
F_100 ( V_67 , V_87 , 0 ) ;
}
}
V_67 ++ ;
V_69 ++ ;
V_49 ++ ;
if ( F_23 ( ! V_49 ) ) {
V_49 -= V_65 -> V_93 ;
V_67 = V_65 -> V_83 ;
V_69 = F_65 ( V_65 , 0 ) ;
}
F_102 ( V_69 ) ;
V_174 -- ;
} while ( F_25 ( V_174 ) );
V_49 += V_65 -> V_93 ;
V_65 -> V_84 = V_49 ;
F_103 ( & V_65 -> V_183 ) ;
V_65 -> V_128 . V_184 += V_172 ;
V_65 -> V_128 . V_149 += V_173 ;
F_104 ( & V_65 -> V_183 ) ;
V_170 -> V_175 . V_172 += V_172 ;
V_170 -> V_175 . V_173 += V_173 ;
if ( F_105 ( V_65 ) && F_89 ( V_65 ) ) {
struct V_15 * V_14 = & V_2 -> V_14 ;
F_106 ( V_160 , L_62
L_63
L_64
L_65
L_66
L_67
L_68
L_69 ,
V_65 -> V_91 ,
F_40 ( V_14 , F_51 ( V_65 -> V_154 ) ) ,
F_40 ( V_14 , F_52 ( V_65 -> V_154 ) ) ,
V_65 -> V_85 , V_49 ,
V_65 -> V_83 [ V_49 ] . V_89 , V_185 ) ;
F_107 ( V_65 -> V_62 , V_65 -> V_91 ) ;
F_108 ( V_186 ,
L_70 ,
V_2 -> V_187 + 1 , V_65 -> V_91 ) ;
F_91 ( V_2 ) ;
return true ;
}
F_109 ( F_110 ( V_65 ) ,
V_173 , V_172 ) ;
#define F_111 (DESC_NEEDED * 2)
if ( F_23 ( V_173 && F_112 ( V_65 -> V_62 ) &&
( F_113 ( V_65 ) >= F_111 ) ) ) {
F_114 () ;
if ( F_115 ( V_65 -> V_62 ,
V_65 -> V_91 )
&& ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_116 ( V_65 -> V_62 ,
V_65 -> V_91 ) ;
++ V_65 -> V_157 . V_188 ;
}
}
return ! ! V_174 ;
}
static void F_117 ( struct V_1 * V_2 ,
struct V_64 * V_65 ,
int V_189 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_190 = 0 ;
T_2 V_191 ;
if ( V_2 -> V_143 & V_192 )
V_190 = F_118 ( V_65 -> V_80 , V_189 ) ;
switch ( V_14 -> V_113 . type ) {
case V_114 :
V_191 = F_119 ( V_65 -> V_154 ) ;
break;
case V_116 :
case V_117 :
V_191 = F_120 ( V_65 -> V_154 ) ;
V_190 <<= V_193 ;
break;
default:
return;
}
V_190 |= V_194 |
V_195 |
V_196 ;
F_75 ( V_14 , V_191 , V_190 ) ;
}
static void F_121 ( struct V_1 * V_2 ,
struct V_64 * V_74 ,
int V_189 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_197 = 0 ;
T_4 V_154 = V_74 -> V_154 ;
if ( V_2 -> V_143 & V_192 )
V_197 = F_118 ( V_74 -> V_80 , V_189 ) ;
switch ( V_14 -> V_113 . type ) {
case V_116 :
case V_117 :
V_197 <<= V_198 ;
break;
default:
break;
}
V_197 |= V_199 |
V_200 |
V_201 ;
F_75 ( V_14 , F_41 ( V_154 ) , V_197 ) ;
}
static void F_122 ( struct V_169 * V_170 )
{
struct V_1 * V_2 = V_170 -> V_2 ;
struct V_64 * V_148 ;
int V_189 = F_123 () ;
if ( V_170 -> V_189 == V_189 )
goto V_202;
F_124 (ring, q_vector->tx)
F_117 ( V_2 , V_148 , V_189 ) ;
F_124 (ring, q_vector->rx)
F_121 ( V_2 , V_148 , V_189 ) ;
V_170 -> V_189 = V_189 ;
V_202:
F_125 () ;
}
static void F_126 ( struct V_1 * V_2 )
{
int V_49 ;
if ( V_2 -> V_143 & V_192 )
F_75 ( & V_2 -> V_14 , V_203 ,
V_204 ) ;
else
F_75 ( & V_2 -> V_14 , V_203 ,
V_205 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_206 ; V_49 ++ ) {
V_2 -> V_170 [ V_49 ] -> V_189 = - 1 ;
F_122 ( V_2 -> V_170 [ V_49 ] ) ;
}
}
static int F_127 ( struct V_207 * V_80 , void * V_97 )
{
struct V_1 * V_2 = F_128 ( V_80 ) ;
unsigned long V_208 = * ( unsigned long * ) V_97 ;
if ( ! ( V_2 -> V_143 & V_209 ) )
return 0 ;
switch ( V_208 ) {
case V_210 :
if ( V_2 -> V_143 & V_192 )
break;
if ( F_129 ( V_80 ) == 0 ) {
V_2 -> V_143 |= V_192 ;
F_75 ( & V_2 -> V_14 , V_203 ,
V_204 ) ;
break;
}
case V_211 :
if ( V_2 -> V_143 & V_192 ) {
F_130 ( V_80 ) ;
V_2 -> V_143 &= ~ V_192 ;
F_75 ( & V_2 -> V_14 , V_203 ,
V_205 ) ;
}
break;
}
return 0 ;
}
static inline void F_131 ( struct V_64 * V_148 ,
union V_75 * V_76 ,
struct V_212 * V_94 )
{
T_2 V_213 ;
if ( ! ( V_148 -> V_62 -> V_214 & V_215 ) )
return;
V_213 = F_132 ( V_76 -> V_99 . V_216 . V_217 . V_218 . V_219 ) &
V_220 ;
if ( ! V_213 )
return;
F_133 ( V_94 , F_71 ( V_76 -> V_99 . V_216 . V_221 . V_222 ) ,
( V_223 & ( 1ul << V_213 ) ) ?
V_224 : V_225 ) ;
}
static inline bool F_134 ( struct V_64 * V_148 ,
union V_75 * V_76 )
{
T_8 V_219 = V_76 -> V_99 . V_216 . V_217 . V_218 . V_219 ;
return F_14 ( V_226 , & V_148 -> V_35 ) &&
( ( V_219 & F_135 ( V_227 ) ) ==
( F_135 ( V_228 <<
V_229 ) ) ) ;
}
static inline void F_136 ( struct V_64 * V_148 ,
union V_75 * V_76 ,
struct V_212 * V_94 )
{
T_8 V_219 = V_76 -> V_99 . V_216 . V_217 . V_218 . V_219 ;
bool V_230 = false ;
F_137 ( V_94 ) ;
if ( ! ( V_148 -> V_62 -> V_214 & V_231 ) )
return;
if ( V_219 & F_135 ( V_232 ) ) {
V_230 = true ;
V_94 -> V_233 = 1 ;
}
if ( F_138 ( V_76 , V_234 ) &&
F_138 ( V_76 , V_235 ) ) {
V_148 -> V_236 . V_237 ++ ;
return;
}
if ( ! F_138 ( V_76 , V_238 ) )
return;
if ( F_138 ( V_76 , V_239 ) ) {
if ( ( V_219 & F_135 ( V_240 ) ) &&
F_14 ( V_241 , & V_148 -> V_35 ) )
return;
V_148 -> V_236 . V_237 ++ ;
return;
}
V_94 -> V_242 = V_243 ;
if ( V_230 ) {
if ( ! F_138 ( V_76 , V_244 ) )
return;
if ( F_138 ( V_76 , V_245 ) ) {
V_94 -> V_242 = V_246 ;
return;
}
V_94 -> V_247 = 1 ;
}
}
static inline unsigned int F_139 ( struct V_64 * V_74 )
{
return F_140 ( V_74 ) ? V_248 : 0 ;
}
static bool F_141 ( struct V_64 * V_74 ,
struct V_77 * V_249 )
{
struct V_103 * V_103 = V_249 -> V_103 ;
T_9 V_86 ;
if ( F_25 ( V_103 ) )
return true ;
V_103 = F_142 ( F_143 ( V_74 ) ) ;
if ( F_23 ( ! V_103 ) ) {
V_74 -> V_236 . V_250 ++ ;
return false ;
}
V_86 = F_144 ( V_74 -> V_80 , V_103 , 0 ,
F_145 ( V_74 ) ,
V_251 ,
V_252 ) ;
if ( F_146 ( V_74 -> V_80 , V_86 ) ) {
F_147 ( V_103 , F_143 ( V_74 ) ) ;
V_74 -> V_236 . V_250 ++ ;
return false ;
}
V_249 -> V_86 = V_86 ;
V_249 -> V_103 = V_103 ;
V_249 -> V_104 = F_139 ( V_74 ) ;
V_249 -> V_253 = 1 ;
return true ;
}
void F_148 ( struct V_64 * V_74 , T_2 V_254 )
{
union V_75 * V_76 ;
struct V_77 * V_249 ;
T_2 V_49 = V_74 -> V_85 ;
T_2 V_255 ;
if ( ! V_254 )
return;
V_76 = F_70 ( V_74 , V_49 ) ;
V_249 = & V_74 -> V_78 [ V_49 ] ;
V_49 -= V_74 -> V_93 ;
V_255 = F_73 ( V_74 ) ;
do {
if ( ! F_141 ( V_74 , V_249 ) )
break;
F_149 ( V_74 -> V_80 , V_249 -> V_86 ,
V_249 -> V_104 , V_255 ,
V_251 ) ;
V_76 -> V_256 . V_257 = F_150 ( V_249 -> V_86 + V_249 -> V_104 ) ;
V_76 ++ ;
V_249 ++ ;
V_49 ++ ;
if ( F_23 ( ! V_49 ) ) {
V_76 = F_70 ( V_74 , 0 ) ;
V_249 = V_74 -> V_78 ;
V_49 -= V_74 -> V_93 ;
}
V_76 -> V_99 . V_100 . V_258 = 0 ;
V_254 -- ;
} while ( V_254 );
V_49 += V_74 -> V_93 ;
if ( V_74 -> V_85 != V_49 ) {
V_74 -> V_85 = V_49 ;
V_74 -> V_259 = V_49 ;
F_151 () ;
F_152 ( V_49 , V_74 -> V_151 ) ;
}
}
static void F_153 ( struct V_64 * V_148 ,
struct V_212 * V_94 )
{
T_2 V_260 = F_154 ( V_94 ) ;
F_155 ( V_94 ) -> V_261 = F_156 ( ( V_94 -> V_87 - V_260 ) ,
F_157 ( V_94 ) -> V_262 ) ;
F_155 ( V_94 ) -> V_263 = V_264 ;
}
static void F_158 ( struct V_64 * V_74 ,
struct V_212 * V_94 )
{
if ( ! F_157 ( V_94 ) -> V_262 )
return;
V_74 -> V_236 . V_265 += F_157 ( V_94 ) -> V_262 ;
V_74 -> V_236 . V_266 ++ ;
F_153 ( V_74 , V_94 ) ;
F_157 ( V_94 ) -> V_262 = 0 ;
}
static void F_159 ( struct V_64 * V_74 ,
union V_75 * V_76 ,
struct V_212 * V_94 )
{
struct V_61 * V_80 = V_74 -> V_62 ;
T_1 V_143 = V_74 -> V_170 -> V_2 -> V_143 ;
F_158 ( V_74 , V_94 ) ;
F_131 ( V_74 , V_76 , V_94 ) ;
F_136 ( V_74 , V_76 , V_94 ) ;
if ( F_23 ( V_143 & V_267 ) )
F_160 ( V_74 , V_76 , V_94 ) ;
if ( ( V_80 -> V_214 & V_268 ) &&
F_138 ( V_76 , V_269 ) ) {
T_2 V_270 = F_132 ( V_76 -> V_99 . V_100 . V_271 ) ;
F_161 ( V_94 , F_162 ( V_272 ) , V_270 ) ;
}
F_163 ( V_94 , V_74 -> V_91 ) ;
V_94 -> V_273 = F_164 ( V_94 , V_80 ) ;
}
static void F_165 ( struct V_169 * V_170 ,
struct V_212 * V_94 )
{
F_166 ( & V_170 -> V_274 , V_94 ) ;
}
static bool F_167 ( struct V_64 * V_74 ,
union V_75 * V_76 ,
struct V_212 * V_94 )
{
T_1 V_275 = V_74 -> V_84 + 1 ;
V_275 = ( V_275 < V_74 -> V_93 ) ? V_275 : 0 ;
V_74 -> V_84 = V_275 ;
F_102 ( F_70 ( V_74 , V_275 ) ) ;
if ( F_168 ( V_74 ) ) {
T_10 V_276 = V_76 -> V_99 . V_216 . V_217 . V_97 &
F_97 ( V_277 ) ;
if ( F_23 ( V_276 ) ) {
T_1 V_278 = F_71 ( V_276 ) ;
V_278 >>= V_279 ;
F_157 ( V_94 ) -> V_262 += V_278 - 1 ;
V_275 = F_71 ( V_76 -> V_99 . V_100 . V_101 ) ;
V_275 &= V_280 ;
V_275 >>= V_281 ;
}
}
if ( F_25 ( F_138 ( V_76 , V_282 ) ) )
return false ;
V_74 -> V_78 [ V_275 ] . V_94 = V_94 ;
V_74 -> V_236 . V_283 ++ ;
return true ;
}
static void F_169 ( struct V_64 * V_74 ,
struct V_212 * V_94 )
{
struct V_284 * V_285 = & F_155 ( V_94 ) -> V_286 [ 0 ] ;
unsigned char * V_287 ;
unsigned int V_288 ;
V_287 = F_170 ( V_285 ) ;
V_288 = F_171 ( V_287 , V_289 ) ;
F_172 ( V_94 , V_287 , F_173 ( V_288 , sizeof( long ) ) ) ;
F_174 ( V_285 , V_288 ) ;
V_285 -> V_104 += V_288 ;
V_94 -> V_290 -= V_288 ;
V_94 -> V_151 += V_288 ;
}
static void F_175 ( struct V_64 * V_74 ,
struct V_212 * V_94 )
{
if ( F_23 ( F_157 ( V_94 ) -> V_291 ) ) {
F_176 ( V_74 -> V_80 , F_157 ( V_94 ) -> V_86 ,
F_145 ( V_74 ) ,
V_251 ,
V_252 ) ;
} else {
struct V_284 * V_285 = & F_155 ( V_94 ) -> V_286 [ 0 ] ;
F_177 ( V_74 -> V_80 ,
F_157 ( V_94 ) -> V_86 ,
V_285 -> V_104 ,
F_178 ( V_285 ) ,
V_251 ) ;
}
}
static bool F_179 ( struct V_64 * V_74 ,
union V_75 * V_76 ,
struct V_212 * V_94 )
{
struct V_61 * V_62 = V_74 -> V_62 ;
if ( F_23 ( F_138 ( V_76 ,
V_292 ) &&
! ( V_62 -> V_214 & V_293 ) ) ) {
F_180 ( V_94 ) ;
return true ;
}
if ( ! F_154 ( V_94 ) )
F_169 ( V_74 , V_94 ) ;
#ifdef F_181
if ( F_134 ( V_74 , V_76 ) )
return false ;
#endif
if ( F_182 ( V_94 ) )
return true ;
return false ;
}
static void F_183 ( struct V_64 * V_74 ,
struct V_77 * V_294 )
{
struct V_77 * V_295 ;
T_2 V_296 = V_74 -> V_259 ;
V_295 = & V_74 -> V_78 [ V_296 ] ;
V_296 ++ ;
V_74 -> V_259 = ( V_296 < V_74 -> V_93 ) ? V_296 : 0 ;
V_295 -> V_86 = V_294 -> V_86 ;
V_295 -> V_103 = V_294 -> V_103 ;
V_295 -> V_104 = V_294 -> V_104 ;
V_295 -> V_253 = V_294 -> V_253 ;
}
static inline bool F_184 ( struct V_103 * V_103 )
{
return ( F_185 ( V_103 ) != F_186 () ) || F_187 ( V_103 ) ;
}
static bool F_188 ( struct V_77 * V_297 )
{
unsigned int V_253 = V_297 -> V_253 ;
struct V_103 * V_103 = V_297 -> V_103 ;
if ( F_23 ( F_184 ( V_103 ) ) )
return false ;
#if ( V_298 < 8192 )
if ( F_23 ( ( F_189 ( V_103 ) - V_253 ) > 1 ) )
return false ;
#else
#define F_190 \
(SKB_WITH_OVERHEAD(PAGE_SIZE) - IXGBE_RXBUFFER_3K)
if ( V_297 -> V_104 > F_190 )
return false ;
#endif
if ( F_23 ( ! V_253 ) ) {
F_191 ( V_103 , V_299 ) ;
V_297 -> V_253 = V_299 ;
}
return true ;
}
static void F_192 ( struct V_64 * V_74 ,
struct V_77 * V_297 ,
struct V_212 * V_94 ,
unsigned int V_300 )
{
#if ( V_298 < 8192 )
unsigned int V_301 = F_145 ( V_74 ) / 2 ;
#else
unsigned int V_301 = F_140 ( V_74 ) ?
F_193 ( V_248 + V_300 ) :
F_193 ( V_300 ) ;
#endif
F_194 ( V_94 , F_155 ( V_94 ) -> V_302 , V_297 -> V_103 ,
V_297 -> V_104 , V_300 , V_301 ) ;
#if ( V_298 < 8192 )
V_297 -> V_104 ^= V_301 ;
#else
V_297 -> V_104 += V_301 ;
#endif
}
static struct V_77 * F_195 ( struct V_64 * V_74 ,
union V_75 * V_76 ,
struct V_212 * * V_94 ,
const unsigned int V_300 )
{
struct V_77 * V_297 ;
V_297 = & V_74 -> V_78 [ V_74 -> V_84 ] ;
F_196 ( V_297 -> V_103 ) ;
* V_94 = V_297 -> V_94 ;
if ( ! F_138 ( V_76 , V_282 ) ) {
if ( ! * V_94 )
goto V_303;
} else {
if ( * V_94 )
F_175 ( V_74 , * V_94 ) ;
}
F_177 ( V_74 -> V_80 ,
V_297 -> V_86 ,
V_297 -> V_104 ,
V_300 ,
V_251 ) ;
V_303:
V_297 -> V_253 -- ;
return V_297 ;
}
static void F_197 ( struct V_64 * V_74 ,
struct V_77 * V_297 ,
struct V_212 * V_94 )
{
if ( F_188 ( V_297 ) ) {
F_183 ( V_74 , V_297 ) ;
} else {
if ( F_157 ( V_94 ) -> V_86 == V_297 -> V_86 ) {
F_157 ( V_94 ) -> V_291 = true ;
} else {
F_176 ( V_74 -> V_80 , V_297 -> V_86 ,
F_145 ( V_74 ) ,
V_251 ,
V_252 ) ;
}
F_198 ( V_297 -> V_103 ,
V_297 -> V_253 ) ;
}
V_297 -> V_103 = NULL ;
V_297 -> V_94 = NULL ;
}
static struct V_212 * F_199 ( struct V_64 * V_74 ,
struct V_77 * V_297 ,
union V_75 * V_76 ,
unsigned int V_300 )
{
void * V_287 = F_72 ( V_297 -> V_103 ) + V_297 -> V_104 ;
#if ( V_298 < 8192 )
unsigned int V_301 = F_145 ( V_74 ) / 2 ;
#else
unsigned int V_301 = F_193 ( V_300 ) ;
#endif
struct V_212 * V_94 ;
F_102 ( V_287 ) ;
#if V_304 < 128
F_102 ( V_287 + V_304 ) ;
#endif
V_94 = F_200 ( & V_74 -> V_170 -> V_274 , V_289 ) ;
if ( F_23 ( ! V_94 ) )
return NULL ;
if ( V_300 > V_289 ) {
if ( ! F_138 ( V_76 , V_282 ) )
F_157 ( V_94 ) -> V_86 = V_297 -> V_86 ;
F_194 ( V_94 , 0 , V_297 -> V_103 ,
V_297 -> V_104 ,
V_300 , V_301 ) ;
#if ( V_298 < 8192 )
V_297 -> V_104 ^= V_301 ;
#else
V_297 -> V_104 += V_301 ;
#endif
} else {
memcpy ( F_201 ( V_94 , V_300 ) , V_287 , F_173 ( V_300 , sizeof( long ) ) ) ;
V_297 -> V_253 ++ ;
}
return V_94 ;
}
static struct V_212 * F_202 ( struct V_64 * V_74 ,
struct V_77 * V_297 ,
union V_75 * V_76 ,
unsigned int V_300 )
{
void * V_287 = F_72 ( V_297 -> V_103 ) + V_297 -> V_104 ;
#if ( V_298 < 8192 )
unsigned int V_301 = F_145 ( V_74 ) / 2 ;
#else
unsigned int V_301 = F_193 ( sizeof( struct V_305 ) ) +
F_193 ( V_248 + V_300 ) ;
#endif
struct V_212 * V_94 ;
F_102 ( V_287 ) ;
#if V_304 < 128
F_102 ( V_287 + V_304 ) ;
#endif
V_94 = F_203 ( V_287 - V_248 , V_301 ) ;
if ( F_23 ( ! V_94 ) )
return NULL ;
F_204 ( V_94 , V_248 ) ;
F_201 ( V_94 , V_300 ) ;
if ( ! F_138 ( V_76 , V_282 ) )
F_157 ( V_94 ) -> V_86 = V_297 -> V_86 ;
#if ( V_298 < 8192 )
V_297 -> V_104 ^= V_301 ;
#else
V_297 -> V_104 += V_301 ;
#endif
return V_94 ;
}
static int F_205 ( struct V_169 * V_170 ,
struct V_64 * V_74 ,
const int V_174 )
{
unsigned int V_306 = 0 , V_307 = 0 ;
#ifdef F_181
struct V_1 * V_2 = V_170 -> V_2 ;
int V_308 ;
unsigned int V_309 = 0 ;
#endif
T_2 V_254 = F_113 ( V_74 ) ;
while ( F_25 ( V_307 < V_174 ) ) {
union V_75 * V_76 ;
struct V_77 * V_297 ;
struct V_212 * V_94 ;
unsigned int V_300 ;
if ( V_254 >= V_310 ) {
F_148 ( V_74 , V_254 ) ;
V_254 = 0 ;
}
V_76 = F_70 ( V_74 , V_74 -> V_84 ) ;
V_300 = F_132 ( V_76 -> V_99 . V_100 . V_258 ) ;
if ( ! V_300 )
break;
F_206 () ;
V_297 = F_195 ( V_74 , V_76 , & V_94 , V_300 ) ;
if ( V_94 )
F_192 ( V_74 , V_297 , V_94 , V_300 ) ;
else if ( F_140 ( V_74 ) )
V_94 = F_202 ( V_74 , V_297 ,
V_76 , V_300 ) ;
else
V_94 = F_199 ( V_74 , V_297 ,
V_76 , V_300 ) ;
if ( ! V_94 ) {
V_74 -> V_236 . V_311 ++ ;
V_297 -> V_253 ++ ;
break;
}
F_197 ( V_74 , V_297 , V_94 ) ;
V_254 ++ ;
if ( F_167 ( V_74 , V_76 , V_94 ) )
continue;
if ( F_179 ( V_74 , V_76 , V_94 ) )
continue;
V_306 += V_94 -> V_87 ;
F_159 ( V_74 , V_76 , V_94 ) ;
#ifdef F_181
if ( F_134 ( V_74 , V_76 ) ) {
V_308 = F_207 ( V_2 , V_76 , V_94 ) ;
if ( V_308 > 0 ) {
if ( ! V_309 ) {
V_309 = V_74 -> V_62 -> V_312 -
sizeof( struct V_313 ) -
sizeof( struct V_314 ) -
sizeof( struct V_315 ) ;
if ( V_309 > 512 )
V_309 &= ~ 511 ;
}
V_306 += V_308 ;
V_307 += F_156 ( V_308 ,
V_309 ) ;
}
if ( ! V_308 ) {
F_180 ( V_94 ) ;
continue;
}
}
#endif
F_165 ( V_170 , V_94 ) ;
V_307 ++ ;
}
F_103 ( & V_74 -> V_183 ) ;
V_74 -> V_128 . V_149 += V_307 ;
V_74 -> V_128 . V_184 += V_306 ;
F_104 ( & V_74 -> V_183 ) ;
V_170 -> V_316 . V_173 += V_307 ;
V_170 -> V_316 . V_172 += V_306 ;
return V_307 ;
}
static void F_208 ( struct V_1 * V_2 )
{
struct V_169 * V_170 ;
int V_317 ;
T_1 V_123 ;
if ( V_2 -> V_318 > 32 ) {
T_1 V_319 = F_209 ( V_2 -> V_318 - 32 ) - 1 ;
F_75 ( & V_2 -> V_14 , V_320 , V_319 ) ;
}
for ( V_317 = 0 ; V_317 < V_2 -> V_206 ; V_317 ++ ) {
struct V_64 * V_148 ;
V_170 = V_2 -> V_170 [ V_317 ] ;
F_124 (ring, q_vector->rx)
F_77 ( V_2 , 0 , V_148 -> V_154 , V_317 ) ;
F_124 (ring, q_vector->tx)
F_77 ( V_2 , 1 , V_148 -> V_154 , V_317 ) ;
F_210 ( V_170 ) ;
}
switch ( V_2 -> V_14 . V_113 . type ) {
case V_114 :
F_77 ( V_2 , - 1 , V_321 ,
V_317 ) ;
break;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
F_77 ( V_2 , - 1 , 1 , V_317 ) ;
break;
default:
break;
}
F_75 ( & V_2 -> V_14 , F_211 ( V_317 ) , 1950 ) ;
V_123 = V_322 ;
V_123 &= ~ ( V_323 |
V_324 |
V_325 ) ;
F_75 ( & V_2 -> V_14 , V_326 , V_123 ) ;
}
static void F_212 ( struct V_169 * V_170 ,
struct V_327 * V_328 )
{
int V_184 = V_328 -> V_172 ;
int V_149 = V_328 -> V_173 ;
T_1 V_329 ;
T_6 V_330 ;
T_4 V_331 = V_328 -> V_332 ;
if ( V_149 == 0 )
return;
V_329 = V_170 -> V_332 >> 2 ;
if ( V_329 == 0 )
return;
V_330 = V_184 / V_329 ;
switch ( V_331 ) {
case V_333 :
if ( V_330 > 10 )
V_331 = V_334 ;
break;
case V_334 :
if ( V_330 > 20 )
V_331 = V_335 ;
else if ( V_330 <= 10 )
V_331 = V_333 ;
break;
case V_335 :
if ( V_330 <= 20 )
V_331 = V_334 ;
break;
}
V_328 -> V_172 = 0 ;
V_328 -> V_173 = 0 ;
V_328 -> V_332 = V_331 ;
}
void F_210 ( struct V_169 * V_170 )
{
struct V_1 * V_2 = V_170 -> V_2 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_317 = V_170 -> V_317 ;
T_1 V_336 = V_170 -> V_332 & V_337 ;
switch ( V_2 -> V_14 . V_113 . type ) {
case V_114 :
V_336 |= ( V_336 << 16 ) ;
break;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_336 |= V_338 ;
break;
default:
break;
}
F_75 ( V_14 , F_211 ( V_317 ) , V_336 ) ;
}
static void F_213 ( struct V_169 * V_170 )
{
T_1 V_339 = V_170 -> V_332 ;
T_4 V_340 ;
F_212 ( V_170 , & V_170 -> V_175 ) ;
F_212 ( V_170 , & V_170 -> V_316 ) ;
V_340 = F_214 ( V_170 -> V_316 . V_332 , V_170 -> V_175 . V_332 ) ;
switch ( V_340 ) {
case V_333 :
V_339 = V_341 ;
break;
case V_334 :
V_339 = V_342 ;
break;
case V_335 :
V_339 = V_343 ;
break;
default:
break;
}
if ( V_339 != V_170 -> V_332 ) {
V_339 = ( 10 * V_339 * V_170 -> V_332 ) /
( ( 9 * V_339 ) + V_170 -> V_332 ) ;
V_170 -> V_332 = V_339 ;
F_210 ( V_170 ) ;
}
}
static void F_215 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_344 = V_2 -> V_345 ;
T_3 V_346 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
if ( ! ( V_2 -> V_347 & V_348 ) &&
! ( V_2 -> V_347 & V_349 ) )
return;
V_2 -> V_347 &= ~ V_349 ;
switch ( V_14 -> V_21 ) {
case V_350 :
if ( ! ( V_344 & V_351 ) &&
! ( V_344 & V_352 ) )
return;
if ( ! ( V_344 & V_352 ) && V_14 -> V_113 . V_353 . V_354 ) {
T_1 V_20 ;
bool V_355 = false ;
V_14 -> V_113 . V_353 . V_354 ( V_14 , & V_20 , & V_355 , false ) ;
if ( V_355 )
return;
}
if ( V_14 -> V_46 . V_353 . V_356 ( V_14 ) != V_357 )
return;
break;
case V_358 :
case V_359 :
V_346 = V_14 -> V_46 . V_353 . V_356 ( V_14 ) ;
if ( V_346 != V_357 )
return;
break;
default:
if ( V_2 -> V_14 . V_113 . type >= V_117 )
return;
if ( ! ( V_344 & F_216 ( V_14 ) ) )
return;
break;
}
F_217 ( V_160 , L_71 , V_360 ) ;
V_2 -> V_345 = 0 ;
}
static void F_218 ( struct V_1 * V_2 , T_1 V_344 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ( V_2 -> V_143 & V_361 ) &&
( V_344 & F_219 ( V_14 ) ) ) {
F_217 ( V_186 , L_72 ) ;
F_75 ( V_14 , V_362 , F_219 ( V_14 ) ) ;
}
}
static void F_220 ( struct V_1 * V_2 , T_1 V_344 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! ( V_2 -> V_347 & V_348 ) )
return;
switch ( V_2 -> V_14 . V_113 . type ) {
case V_116 :
if ( ( ( V_344 & F_216 ( V_14 ) ) ||
( V_344 & V_352 ) ) &&
( ! F_14 ( V_34 , & V_2 -> V_35 ) ) ) {
V_2 -> V_345 = V_344 ;
V_2 -> V_347 |= V_349 ;
F_13 ( V_2 ) ;
return;
}
return;
case V_120 :
if ( V_344 & V_363 ) {
V_2 -> V_345 = V_344 ;
V_2 -> V_347 |= V_349 ;
F_13 ( V_2 ) ;
F_75 ( & V_2 -> V_14 , V_364 ,
V_363 ) ;
F_75 ( & V_2 -> V_14 , V_362 ,
V_363 ) ;
}
return;
case V_118 :
case V_117 :
if ( ! ( V_344 & V_365 ) )
return;
break;
default:
return;
}
F_217 ( V_160 , L_71 , V_360 ) ;
}
static inline bool F_221 ( struct V_15 * V_14 )
{
switch ( V_14 -> V_113 . type ) {
case V_114 :
if ( V_14 -> V_46 . type == V_366 )
return true ;
return false ;
case V_116 :
case V_119 :
case V_120 :
switch ( V_14 -> V_113 . V_353 . V_367 ( V_14 ) ) {
case V_368 :
case V_369 :
return true ;
default:
return false ;
}
default:
return false ;
}
}
static void F_222 ( struct V_1 * V_2 , T_1 V_344 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_370 = F_223 ( V_14 ) ;
if ( ! F_221 ( V_14 ) )
return;
if ( V_14 -> V_113 . type >= V_117 )
V_370 = V_371 ;
if ( V_344 & V_370 ) {
F_75 ( V_14 , V_362 , V_370 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_347 |= V_372 ;
V_2 -> V_373 = 0 ;
F_13 ( V_2 ) ;
}
}
if ( V_2 -> V_14 . V_113 . type == V_116 &&
( V_344 & F_219 ( V_14 ) ) ) {
F_75 ( V_14 , V_362 , F_219 ( V_14 ) ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_143 |= V_374 ;
F_13 ( V_2 ) ;
}
}
}
static void F_224 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_375 ++ ;
V_2 -> V_143 |= V_376 ;
V_2 -> V_377 = V_185 ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_75 ( V_14 , V_364 , V_378 ) ;
F_225 ( V_14 ) ;
F_13 ( V_2 ) ;
}
}
static inline void F_226 ( struct V_1 * V_2 ,
T_6 V_122 )
{
T_1 V_123 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_113 . type ) {
case V_114 :
V_123 = ( V_124 & V_122 ) ;
F_75 ( V_14 , V_379 , V_123 ) ;
break;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_123 = ( V_122 & 0xFFFFFFFF ) ;
if ( V_123 )
F_75 ( V_14 , F_227 ( 0 ) , V_123 ) ;
V_123 = ( V_122 >> 32 ) ;
if ( V_123 )
F_75 ( V_14 , F_227 ( 1 ) , V_123 ) ;
break;
default:
break;
}
}
static inline void F_228 ( struct V_1 * V_2 ,
T_6 V_122 )
{
T_1 V_123 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_113 . type ) {
case V_114 :
V_123 = ( V_124 & V_122 ) ;
F_75 ( V_14 , V_364 , V_123 ) ;
break;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_123 = ( V_122 & 0xFFFFFFFF ) ;
if ( V_123 )
F_75 ( V_14 , F_229 ( 0 ) , V_123 ) ;
V_123 = ( V_122 >> 32 ) ;
if ( V_123 )
F_75 ( V_14 , F_229 ( 1 ) , V_123 ) ;
break;
default:
break;
}
}
static inline void F_230 ( struct V_1 * V_2 , bool V_380 ,
bool V_381 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_123 = ( V_322 & ~ V_124 ) ;
if ( V_2 -> V_143 & V_376 )
V_123 &= ~ V_325 ;
if ( V_2 -> V_347 & V_348 )
switch ( V_2 -> V_14 . V_113 . type ) {
case V_116 :
V_123 |= F_231 ( V_14 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_123 |= V_382 ;
break;
default:
break;
}
if ( V_2 -> V_143 & V_361 )
V_123 |= F_232 ( V_14 ) ;
switch ( V_2 -> V_14 . V_113 . type ) {
case V_116 :
V_123 |= F_232 ( V_14 ) ;
V_123 |= F_233 ( V_14 ) ;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
if ( V_2 -> V_14 . V_21 == V_383 ||
V_2 -> V_14 . V_21 == V_384 ||
V_2 -> V_14 . V_21 == V_385 )
V_123 |= F_231 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_14 . V_46 . type == V_386 )
V_123 |= V_371 ;
V_123 |= V_387 ;
V_123 |= V_324 ;
break;
default:
break;
}
if ( ( V_2 -> V_143 & V_388 ) &&
! ( V_2 -> V_347 & V_389 ) )
V_123 |= V_390 ;
F_75 ( & V_2 -> V_14 , V_379 , V_123 ) ;
if ( V_380 )
F_226 ( V_2 , ~ 0 ) ;
if ( V_381 )
F_225 ( & V_2 -> V_14 ) ;
}
static T_11 F_234 ( int V_391 , void * V_97 )
{
struct V_1 * V_2 = V_97 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_344 ;
V_344 = F_40 ( V_14 , V_125 ) ;
V_344 &= 0xFFFF0000 ;
F_75 ( V_14 , V_362 , V_344 ) ;
if ( V_344 & V_352 )
F_224 ( V_2 ) ;
if ( V_344 & V_392 )
F_235 ( V_2 ) ;
switch ( V_14 -> V_113 . type ) {
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
if ( V_14 -> V_46 . type == V_386 &&
( V_344 & V_371 ) ) {
V_2 -> V_347 |= V_393 ;
F_13 ( V_2 ) ;
F_75 ( V_14 , V_362 ,
V_371 ) ;
}
if ( V_344 & V_394 ) {
F_108 ( V_395 , L_73 ) ;
F_92 ( V_159 , & V_2 -> V_35 ) ;
F_13 ( V_2 ) ;
F_75 ( V_14 , V_362 , V_394 ) ;
}
if ( V_344 & V_396 ) {
int V_397 = 0 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_82 ; V_49 ++ ) {
struct V_64 * V_148 = V_2 -> V_65 [ V_49 ] ;
if ( F_236 ( V_398 ,
& V_148 -> V_35 ) )
V_397 ++ ;
}
if ( V_397 ) {
F_75 ( V_14 , V_364 , V_399 ) ;
V_2 -> V_347 |= V_389 ;
F_13 ( V_2 ) ;
}
}
F_222 ( V_2 , V_344 ) ;
F_220 ( V_2 , V_344 ) ;
break;
default:
break;
}
F_218 ( V_2 , V_344 ) ;
if ( F_23 ( V_344 & V_400 ) )
F_237 ( V_2 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_230 ( V_2 , false , false ) ;
return V_401 ;
}
static T_11 F_238 ( int V_391 , void * V_97 )
{
struct V_169 * V_170 = V_97 ;
if ( V_170 -> V_316 . V_148 || V_170 -> V_175 . V_148 )
F_239 ( & V_170 -> V_274 ) ;
return V_401 ;
}
int F_240 ( struct V_402 * V_274 , int V_174 )
{
struct V_169 * V_170 =
F_241 ( V_274 , struct V_169 , V_274 ) ;
struct V_1 * V_2 = V_170 -> V_2 ;
struct V_64 * V_148 ;
int V_403 , V_404 = 0 ;
bool V_405 = true ;
#ifdef F_242
if ( V_2 -> V_143 & V_192 )
F_122 ( V_170 ) ;
#endif
F_124 (ring, q_vector->tx) {
if ( ! F_95 ( V_170 , V_148 , V_174 ) )
V_405 = false ;
}
if ( V_174 <= 0 )
return V_174 ;
if ( V_170 -> V_316 . V_93 > 1 )
V_403 = F_214 ( V_174 / V_170 -> V_316 . V_93 , 1 ) ;
else
V_403 = V_174 ;
F_124 (ring, q_vector->rx) {
int V_406 = F_205 ( V_170 , V_148 ,
V_403 ) ;
V_404 += V_406 ;
if ( V_406 >= V_403 )
V_405 = false ;
}
if ( ! V_405 )
return V_174 ;
F_243 ( V_274 , V_404 ) ;
if ( V_2 -> V_407 & 1 )
F_213 ( V_170 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_226 ( V_2 , F_244 ( V_170 -> V_317 ) ) ;
return F_245 ( V_404 , V_174 - 1 ) ;
}
static int F_246 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
int V_408 , V_17 ;
int V_409 = 0 , V_410 = 0 ;
for ( V_408 = 0 ; V_408 < V_2 -> V_206 ; V_408 ++ ) {
struct V_169 * V_170 = V_2 -> V_170 [ V_408 ] ;
struct V_411 * V_412 = & V_2 -> V_413 [ V_408 ] ;
if ( V_170 -> V_175 . V_148 && V_170 -> V_316 . V_148 ) {
snprintf ( V_170 -> V_60 , sizeof( V_170 -> V_60 ) - 1 ,
L_74 , V_62 -> V_60 , L_75 , V_409 ++ ) ;
V_410 ++ ;
} else if ( V_170 -> V_316 . V_148 ) {
snprintf ( V_170 -> V_60 , sizeof( V_170 -> V_60 ) - 1 ,
L_74 , V_62 -> V_60 , L_76 , V_409 ++ ) ;
} else if ( V_170 -> V_175 . V_148 ) {
snprintf ( V_170 -> V_60 , sizeof( V_170 -> V_60 ) - 1 ,
L_74 , V_62 -> V_60 , L_77 , V_410 ++ ) ;
} else {
continue;
}
V_17 = F_247 ( V_412 -> V_408 , & F_238 , 0 ,
V_170 -> V_60 , V_170 ) ;
if ( V_17 ) {
F_106 ( V_186 , L_78
L_79 , V_17 ) ;
goto V_414;
}
if ( V_2 -> V_143 & V_388 ) {
F_248 ( V_412 -> V_408 ,
& V_170 -> V_415 ) ;
}
}
V_17 = F_247 ( V_2 -> V_413 [ V_408 ] . V_408 ,
F_234 , 0 , V_62 -> V_60 , V_2 ) ;
if ( V_17 ) {
F_106 ( V_186 , L_80 , V_17 ) ;
goto V_414;
}
return 0 ;
V_414:
while ( V_408 ) {
V_408 -- ;
F_248 ( V_2 -> V_413 [ V_408 ] . V_408 ,
NULL ) ;
F_249 ( V_2 -> V_413 [ V_408 ] . V_408 ,
V_2 -> V_170 [ V_408 ] ) ;
}
V_2 -> V_143 &= ~ V_416 ;
F_250 ( V_2 -> V_9 ) ;
F_251 ( V_2 -> V_413 ) ;
V_2 -> V_413 = NULL ;
return V_17 ;
}
static T_11 F_252 ( int V_391 , void * V_97 )
{
struct V_1 * V_2 = V_97 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_169 * V_170 = V_2 -> V_170 [ 0 ] ;
T_1 V_344 ;
F_75 ( V_14 , V_364 , V_417 ) ;
V_344 = F_40 ( V_14 , V_362 ) ;
if ( ! V_344 ) {
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_230 ( V_2 , true , true ) ;
return V_418 ;
}
if ( V_344 & V_352 )
F_224 ( V_2 ) ;
switch ( V_14 -> V_113 . type ) {
case V_116 :
F_222 ( V_2 , V_344 ) ;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
if ( V_344 & V_394 ) {
F_108 ( V_395 , L_73 ) ;
F_92 ( V_159 , & V_2 -> V_35 ) ;
F_13 ( V_2 ) ;
F_75 ( V_14 , V_362 , V_394 ) ;
}
F_220 ( V_2 , V_344 ) ;
break;
default:
break;
}
F_218 ( V_2 , V_344 ) ;
if ( F_23 ( V_344 & V_400 ) )
F_237 ( V_2 ) ;
F_239 ( & V_170 -> V_274 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_230 ( V_2 , false , false ) ;
return V_401 ;
}
static int F_253 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
int V_17 ;
if ( V_2 -> V_143 & V_416 )
V_17 = F_246 ( V_2 ) ;
else if ( V_2 -> V_143 & V_419 )
V_17 = F_247 ( V_2 -> V_9 -> V_391 , F_252 , 0 ,
V_62 -> V_60 , V_2 ) ;
else
V_17 = F_247 ( V_2 -> V_9 -> V_391 , F_252 , V_420 ,
V_62 -> V_60 , V_2 ) ;
if ( V_17 )
F_106 ( V_186 , L_81 , V_17 ) ;
return V_17 ;
}
static void F_254 ( struct V_1 * V_2 )
{
int V_408 ;
if ( ! ( V_2 -> V_143 & V_416 ) ) {
F_249 ( V_2 -> V_9 -> V_391 , V_2 ) ;
return;
}
if ( ! V_2 -> V_413 )
return;
for ( V_408 = 0 ; V_408 < V_2 -> V_206 ; V_408 ++ ) {
struct V_169 * V_170 = V_2 -> V_170 [ V_408 ] ;
struct V_411 * V_412 = & V_2 -> V_413 [ V_408 ] ;
if ( ! V_170 -> V_316 . V_148 && ! V_170 -> V_175 . V_148 )
continue;
F_248 ( V_412 -> V_408 , NULL ) ;
F_249 ( V_412 -> V_408 , V_170 ) ;
}
F_249 ( V_2 -> V_413 [ V_408 ] . V_408 , V_2 ) ;
}
static inline void F_255 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_113 . type ) {
case V_114 :
F_75 ( & V_2 -> V_14 , V_364 , ~ 0 ) ;
break;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
F_75 ( & V_2 -> V_14 , V_364 , 0xFFFF0000 ) ;
F_75 ( & V_2 -> V_14 , F_229 ( 0 ) , ~ 0 ) ;
F_75 ( & V_2 -> V_14 , F_229 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_225 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_143 & V_416 ) {
int V_408 ;
for ( V_408 = 0 ; V_408 < V_2 -> V_206 ; V_408 ++ )
F_256 ( V_2 -> V_413 [ V_408 ] . V_408 ) ;
F_256 ( V_2 -> V_413 [ V_408 ++ ] . V_408 ) ;
} else {
F_256 ( V_2 -> V_9 -> V_391 ) ;
}
}
static void F_257 ( struct V_1 * V_2 )
{
struct V_169 * V_170 = V_2 -> V_170 [ 0 ] ;
F_210 ( V_170 ) ;
F_77 ( V_2 , 0 , 0 , 0 ) ;
F_77 ( V_2 , 1 , 0 , 0 ) ;
F_108 ( V_14 , L_82 ) ;
}
void F_258 ( struct V_1 * V_2 ,
struct V_64 * V_148 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_421 = V_148 -> V_86 ;
int V_422 = 10 ;
T_1 V_423 = V_424 ;
T_4 V_154 = V_148 -> V_154 ;
F_75 ( V_14 , F_53 ( V_154 ) , 0 ) ;
F_225 ( V_14 ) ;
F_75 ( V_14 , F_48 ( V_154 ) ,
( V_421 & F_259 ( 32 ) ) ) ;
F_75 ( V_14 , F_49 ( V_154 ) , ( V_421 >> 32 ) ) ;
F_75 ( V_14 , F_50 ( V_154 ) ,
V_148 -> V_93 * sizeof( union V_68 ) ) ;
F_75 ( V_14 , F_51 ( V_154 ) , 0 ) ;
F_75 ( V_14 , F_52 ( V_154 ) , 0 ) ;
V_148 -> V_151 = V_2 -> V_425 + F_52 ( V_154 ) ;
if ( ! V_148 -> V_170 || ( V_148 -> V_170 -> V_332 < V_341 ) )
V_423 |= 1u << 16 ;
else
V_423 |= 8u << 16 ;
V_423 |= ( 1u << 8 ) |
32 ;
if ( V_2 -> V_143 & V_388 ) {
V_148 -> V_426 = V_2 -> V_426 ;
V_148 -> V_427 = 0 ;
F_92 ( V_398 , & V_148 -> V_35 ) ;
} else {
V_148 -> V_426 = 0 ;
}
if ( ! F_15 ( V_428 , & V_148 -> V_35 ) ) {
struct V_169 * V_170 = V_148 -> V_170 ;
if ( V_170 )
F_260 ( V_148 -> V_62 ,
& V_170 -> V_415 ,
V_148 -> V_91 ) ;
}
F_37 ( V_136 , & V_148 -> V_35 ) ;
memset ( V_148 -> V_83 , 0 ,
sizeof( struct V_66 ) * V_148 -> V_93 ) ;
F_75 ( V_14 , F_53 ( V_154 ) , V_423 ) ;
if ( V_14 -> V_113 . type == V_114 &&
! ( F_40 ( V_14 , V_429 ) & V_430 ) )
return;
do {
F_261 ( 1000 , 2000 ) ;
V_423 = F_40 ( V_14 , F_53 ( V_154 ) ) ;
} while ( -- V_422 && ! ( V_423 & V_424 ) );
if ( ! V_422 )
F_262 ( V_14 , L_83 , V_154 ) ;
}
static void F_263 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_431 , V_432 ;
T_4 V_433 = F_264 ( V_2 -> V_62 ) ;
if ( V_14 -> V_113 . type == V_114 )
return;
V_431 = F_40 ( V_14 , V_434 ) ;
V_431 |= V_435 ;
F_75 ( V_14 , V_434 , V_431 ) ;
if ( V_2 -> V_143 & V_436 ) {
V_432 = V_437 ;
if ( V_433 > 4 )
V_432 |= V_438 | V_439 ;
else if ( V_433 > 1 )
V_432 |= V_438 | V_440 ;
else if ( V_2 -> V_441 [ V_442 ] . V_123 ==
V_443 )
V_432 |= V_444 ;
else
V_432 |= V_445 ;
} else {
if ( V_433 > 4 )
V_432 = V_438 | V_439 ;
else if ( V_433 > 1 )
V_432 = V_438 | V_440 ;
else
V_432 = V_446 ;
}
F_75 ( V_14 , V_447 , V_432 ) ;
if ( V_433 ) {
T_1 V_448 = F_40 ( V_14 , V_449 ) ;
V_448 |= V_450 ;
F_75 ( V_14 , V_449 , V_448 ) ;
}
V_431 &= ~ V_435 ;
F_75 ( V_14 , V_434 , V_431 ) ;
}
static void F_265 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_451 ;
T_1 V_49 ;
F_263 ( V_2 ) ;
if ( V_14 -> V_113 . type != V_114 ) {
V_451 = F_40 ( V_14 , V_452 ) ;
V_451 |= V_453 ;
F_75 ( V_14 , V_452 , V_451 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_82 ; V_49 ++ )
F_258 ( V_2 , V_2 -> V_65 [ V_49 ] ) ;
}
static void F_266 ( struct V_1 * V_2 ,
struct V_64 * V_148 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_154 = V_148 -> V_154 ;
T_1 V_454 = F_40 ( V_14 , F_39 ( V_154 ) ) ;
V_454 |= V_455 ;
F_75 ( V_14 , F_39 ( V_154 ) , V_454 ) ;
}
static void F_267 ( struct V_1 * V_2 ,
struct V_64 * V_148 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_154 = V_148 -> V_154 ;
T_1 V_454 = F_40 ( V_14 , F_39 ( V_154 ) ) ;
V_454 &= ~ V_455 ;
F_75 ( V_14 , F_39 ( V_154 ) , V_454 ) ;
}
static void F_268 ( struct V_1 * V_2 ,
struct V_64 * V_74 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_454 ;
T_4 V_154 = V_74 -> V_154 ;
if ( V_14 -> V_113 . type == V_114 ) {
T_2 V_123 = V_2 -> V_441 [ V_456 ] . V_123 ;
V_154 &= V_123 ;
}
V_454 = V_289 << V_457 ;
if ( F_14 ( V_458 , & V_74 -> V_35 ) )
V_454 |= V_459 >> V_460 ;
else
V_454 |= V_461 >> V_460 ;
V_454 |= V_462 ;
F_75 ( V_14 , F_39 ( V_154 ) , V_454 ) ;
}
T_1 F_269 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_113 . type < V_118 )
return 128 ;
else if ( V_2 -> V_143 & V_436 )
return 64 ;
else
return 512 ;
}
void F_270 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < 10 ; V_49 ++ )
F_75 ( V_14 , F_271 ( V_49 ) , V_2 -> V_463 [ V_49 ] ) ;
}
void F_272 ( struct V_1 * V_2 )
{
T_1 V_49 , V_464 = F_269 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_465 = 0 ;
T_1 V_466 ;
T_4 * V_467 = V_2 -> V_468 ;
if ( V_2 -> V_14 . V_113 . type == V_114 )
V_466 = 0x11 ;
else
V_466 = 0x1 ;
for ( V_49 = 0 ; V_49 < V_464 ; V_49 ++ ) {
V_465 |= V_466 * V_467 [ V_49 ] << ( V_49 & 0x3 ) * 8 ;
if ( ( V_49 & 3 ) == 3 ) {
if ( V_49 < 128 )
F_75 ( V_14 , F_273 ( V_49 >> 2 ) , V_465 ) ;
else
F_75 ( V_14 , F_274 ( ( V_49 >> 2 ) - 32 ) ,
V_465 ) ;
V_465 = 0 ;
}
}
}
static void F_275 ( struct V_1 * V_2 )
{
T_1 V_49 , V_464 = F_269 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_469 = 0 ;
unsigned int V_470 = V_2 -> V_318 ;
for ( V_49 = 0 ; V_49 < V_464 ; V_49 ++ ) {
V_469 |= ( T_1 ) V_2 -> V_468 [ V_49 ] << ( V_49 & 0x3 ) * 8 ;
if ( ( V_49 & 3 ) == 3 ) {
F_75 ( V_14 , F_276 ( V_49 >> 2 , V_470 ) ,
V_469 ) ;
V_469 = 0 ;
}
}
}
static void F_277 ( struct V_1 * V_2 )
{
T_1 V_49 , V_56 ;
T_1 V_464 = F_269 ( V_2 ) ;
T_2 V_471 = V_2 -> V_441 [ V_456 ] . V_472 ;
if ( ( V_2 -> V_143 & V_436 ) && ( V_471 < 4 ) )
V_471 = 4 ;
F_270 ( V_2 ) ;
memset ( V_2 -> V_468 , 0 , sizeof( V_2 -> V_468 ) ) ;
for ( V_49 = 0 , V_56 = 0 ; V_49 < V_464 ; V_49 ++ , V_56 ++ ) {
if ( V_56 == V_471 )
V_56 = 0 ;
V_2 -> V_468 [ V_49 ] = V_56 ;
}
F_272 ( V_2 ) ;
}
static void F_278 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_471 = V_2 -> V_441 [ V_456 ] . V_472 ;
unsigned int V_470 = V_2 -> V_318 ;
int V_49 , V_56 ;
for ( V_49 = 0 ; V_49 < 10 ; V_49 ++ )
F_75 ( V_14 , F_279 ( V_49 , V_470 ) ,
V_2 -> V_463 [ V_49 ] ) ;
for ( V_49 = 0 , V_56 = 0 ; V_49 < 64 ; V_49 ++ , V_56 ++ ) {
if ( V_56 == V_471 )
V_56 = 0 ;
V_2 -> V_468 [ V_49 ] = V_56 ;
}
F_275 ( V_2 ) ;
}
static void F_280 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_473 = 0 , V_474 = 0 , V_475 = 0 ;
T_1 V_476 ;
V_476 = F_40 ( V_14 , V_477 ) ;
V_476 |= V_478 ;
F_75 ( V_14 , V_477 , V_476 ) ;
if ( V_2 -> V_14 . V_113 . type == V_114 ) {
if ( V_2 -> V_441 [ V_456 ] . V_123 )
V_473 = V_479 ;
} else {
T_4 V_433 = F_264 ( V_2 -> V_62 ) ;
if ( V_2 -> V_143 & V_436 ) {
if ( V_433 > 4 )
V_473 = V_480 ;
else if ( V_433 > 1 )
V_473 = V_481 ;
else if ( V_2 -> V_441 [ V_442 ] . V_123 ==
V_443 )
V_473 = V_482 ;
else
V_473 = V_483 ;
} else {
if ( V_433 > 4 )
V_473 = V_484 ;
else if ( V_433 > 1 )
V_473 = V_485 ;
else
V_473 = V_479 ;
}
}
V_474 |= V_486 |
V_487 |
V_488 |
V_489 ;
if ( V_2 -> V_347 & V_490 )
V_474 |= V_491 ;
if ( V_2 -> V_347 & V_492 )
V_474 |= V_493 ;
F_281 ( V_2 -> V_463 , sizeof( V_2 -> V_463 ) ) ;
if ( ( V_14 -> V_113 . type >= V_118 ) &&
( V_2 -> V_143 & V_436 ) ) {
unsigned int V_470 = V_2 -> V_318 ;
V_473 |= V_494 ;
F_75 ( V_14 , V_495 , V_473 ) ;
F_278 ( V_2 ) ;
V_475 = V_479 ;
V_475 |= V_474 ;
F_75 ( V_14 , F_282 ( V_470 ) , V_475 ) ;
} else {
F_277 ( V_2 ) ;
V_473 |= V_474 ;
F_75 ( V_14 , V_495 , V_473 ) ;
}
}
static void F_283 ( struct V_1 * V_2 ,
struct V_64 * V_148 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_496 ;
T_4 V_154 = V_148 -> V_154 ;
if ( ! F_168 ( V_148 ) )
return;
V_496 = F_40 ( V_14 , F_284 ( V_154 ) ) ;
V_496 |= V_497 ;
V_496 |= V_498 ;
F_75 ( V_14 , F_284 ( V_154 ) , V_496 ) ;
}
static void F_285 ( struct V_1 * V_2 ,
struct V_64 * V_148 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_422 = V_499 ;
T_1 V_500 ;
T_4 V_154 = V_148 -> V_154 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
if ( V_14 -> V_113 . type == V_114 &&
! ( F_40 ( V_14 , V_429 ) & V_430 ) )
return;
do {
F_261 ( 1000 , 2000 ) ;
V_500 = F_40 ( V_14 , F_45 ( V_154 ) ) ;
} while ( -- V_422 && ! ( V_500 & V_501 ) );
if ( ! V_422 ) {
F_106 ( V_160 , L_84
L_85 , V_154 ) ;
}
}
void F_286 ( struct V_1 * V_2 ,
struct V_64 * V_148 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_422 = V_499 ;
T_1 V_500 ;
T_4 V_154 = V_148 -> V_154 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
V_500 = F_40 ( V_14 , F_45 ( V_154 ) ) ;
V_500 &= ~ V_501 ;
F_75 ( V_14 , F_45 ( V_154 ) , V_500 ) ;
if ( V_14 -> V_113 . type == V_114 &&
! ( F_40 ( V_14 , V_429 ) & V_430 ) )
return;
do {
F_26 ( 10 ) ;
V_500 = F_40 ( V_14 , F_45 ( V_154 ) ) ;
} while ( -- V_422 && ( V_500 & V_501 ) );
if ( ! V_422 ) {
F_106 ( V_160 , L_86
L_85 , V_154 ) ;
}
}
void F_287 ( struct V_1 * V_2 ,
struct V_64 * V_148 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
union V_75 * V_76 ;
T_6 V_502 = V_148 -> V_86 ;
T_1 V_500 ;
T_4 V_154 = V_148 -> V_154 ;
V_500 = F_40 ( V_14 , F_45 ( V_154 ) ) ;
F_286 ( V_2 , V_148 ) ;
F_75 ( V_14 , F_46 ( V_154 ) , ( V_502 & F_259 ( 32 ) ) ) ;
F_75 ( V_14 , F_47 ( V_154 ) , ( V_502 >> 32 ) ) ;
F_75 ( V_14 , F_42 ( V_154 ) ,
V_148 -> V_93 * sizeof( union V_75 ) ) ;
F_225 ( V_14 ) ;
F_75 ( V_14 , F_43 ( V_154 ) , 0 ) ;
F_75 ( V_14 , F_44 ( V_154 ) , 0 ) ;
V_148 -> V_151 = V_2 -> V_425 + F_44 ( V_154 ) ;
F_268 ( V_2 , V_148 ) ;
F_283 ( V_2 , V_148 ) ;
if ( V_14 -> V_113 . type == V_114 ) {
V_500 &= ~ 0x3FFFFF ;
V_500 |= 0x080420 ;
#if ( V_298 < 8192 )
} else {
V_500 &= ~ ( V_503 |
V_504 ) ;
if ( F_140 ( V_148 ) &&
! F_14 ( V_458 , & V_148 -> V_35 ) )
V_500 |= V_505 |
V_504 ;
#endif
}
memset ( V_148 -> V_78 , 0 ,
sizeof( struct V_77 ) * V_148 -> V_93 ) ;
V_76 = F_70 ( V_148 , 0 ) ;
V_76 -> V_99 . V_100 . V_258 = 0 ;
V_500 |= V_501 ;
F_75 ( V_14 , F_45 ( V_154 ) , V_500 ) ;
F_285 ( V_2 , V_148 ) ;
F_148 ( V_148 , F_113 ( V_148 ) ) ;
}
static void F_288 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_471 = V_2 -> V_441 [ V_456 ] . V_472 ;
T_2 V_506 ;
T_1 V_507 = V_508 |
V_509 |
V_510 |
V_511 |
V_512 ;
if ( V_14 -> V_113 . type == V_114 )
return;
if ( V_471 > 3 )
V_507 |= 2u << 29 ;
else if ( V_471 > 1 )
V_507 |= 1u << 29 ;
F_289 (pool, &adapter->fwd_bitmask, 32 )
F_75 ( V_14 , F_290 ( F_291 ( V_506 ) ) , V_507 ) ;
}
static void F_292 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_191 , V_513 ;
T_1 V_514 , V_515 ;
int V_49 ;
if ( ! ( V_2 -> V_143 & V_436 ) )
return;
V_515 = F_40 ( V_14 , V_516 ) ;
V_515 |= V_517 ;
V_515 &= ~ V_518 ;
V_515 |= F_291 ( 0 ) << V_519 ;
V_515 |= V_520 ;
F_75 ( V_14 , V_516 , V_515 ) ;
V_513 = F_291 ( 0 ) % 32 ;
V_191 = ( F_291 ( 0 ) >= 32 ) ? 1 : 0 ;
F_75 ( V_14 , F_293 ( V_191 ) , F_294 ( 31 , V_513 ) ) ;
F_75 ( V_14 , F_293 ( V_191 ^ 1 ) , V_191 - 1 ) ;
F_75 ( V_14 , F_295 ( V_191 ) , F_294 ( 31 , V_513 ) ) ;
F_75 ( V_14 , F_295 ( V_191 ^ 1 ) , V_191 - 1 ) ;
if ( V_2 -> V_521 == V_522 )
F_75 ( V_14 , V_523 , V_524 ) ;
V_14 -> V_113 . V_353 . V_525 ( V_14 , 0 , F_291 ( 0 ) ) ;
V_2 -> V_347 &= ~ V_526 ;
switch ( V_2 -> V_441 [ V_442 ] . V_123 ) {
case V_527 :
V_514 = V_528 ;
break;
case V_443 :
V_514 = V_529 ;
break;
default:
V_514 = V_530 ;
break;
}
F_75 ( V_14 , V_531 , V_514 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_318 ; V_49 ++ ) {
F_296 ( V_2 -> V_62 , V_49 ,
V_2 -> V_532 [ V_49 ] . V_533 ) ;
F_297 ( V_2 -> V_62 , V_49 ,
V_2 -> V_532 [ V_49 ] . V_534 ) ;
}
}
static void F_298 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_61 * V_62 = V_2 -> V_62 ;
int V_535 = V_62 -> V_312 + V_536 + V_537 ;
struct V_64 * V_74 ;
int V_49 ;
T_1 V_538 , V_539 ;
#ifdef F_181
if ( ( V_2 -> V_143 & V_540 ) &&
( V_535 < V_541 ) )
V_535 = V_541 ;
#endif
if ( V_535 < ( V_542 + V_537 ) )
V_535 = ( V_542 + V_537 ) ;
V_538 = F_40 ( V_14 , V_543 ) ;
if ( V_535 != ( V_538 >> V_544 ) ) {
V_538 &= ~ V_545 ;
V_538 |= V_535 << V_544 ;
F_75 ( V_14 , V_543 , V_538 ) ;
}
V_539 = F_40 ( V_14 , V_546 ) ;
V_539 |= V_547 ;
F_75 ( V_14 , V_546 , V_539 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_98 ; V_49 ++ ) {
V_74 = V_2 -> V_74 [ V_49 ] ;
F_299 ( V_74 ) ;
F_37 ( V_458 , & V_74 -> V_35 ) ;
F_37 ( V_548 , & V_74 -> V_35 ) ;
if ( V_2 -> V_347 & V_549 )
F_300 ( V_74 ) ;
if ( F_14 ( V_226 , & V_74 -> V_35 ) )
F_92 ( V_458 , & V_74 -> V_35 ) ;
F_37 ( V_548 , & V_74 -> V_35 ) ;
if ( V_2 -> V_347 & V_550 )
continue;
F_92 ( V_548 , & V_74 -> V_35 ) ;
#if ( V_298 < 8192 )
if ( V_2 -> V_347 & V_549 )
F_92 ( V_458 , & V_74 -> V_35 ) ;
if ( ( V_535 > ( V_542 + V_537 ) ) ||
( V_535 > V_505 ) )
F_92 ( V_458 , & V_74 -> V_35 ) ;
#endif
}
}
static void F_301 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_551 = F_40 ( V_14 , V_552 ) ;
switch ( V_14 -> V_113 . type ) {
case V_114 :
V_551 |= V_553 ;
break;
case V_118 :
case V_119 :
case V_120 :
if ( V_2 -> V_318 )
V_551 |= V_554 ;
case V_116 :
case V_117 :
F_75 ( V_14 , V_555 ,
( V_556 | F_40 ( V_14 , V_555 ) ) ) ;
V_551 &= ~ V_557 ;
V_551 |= ( V_558 | V_559 ) ;
V_551 |= V_560 ;
break;
default:
return;
}
F_75 ( V_14 , V_552 , V_551 ) ;
}
static void F_302 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
T_1 V_197 , V_561 ;
V_14 -> V_113 . V_353 . V_562 ( V_14 ) ;
F_288 ( V_2 ) ;
F_301 ( V_2 ) ;
V_561 = F_40 ( V_14 , V_563 ) ;
V_561 &= ~ V_564 ;
if ( ! ( V_2 -> V_347 & V_549 ) )
V_561 |= V_564 ;
V_561 |= ( V_565 | V_566 ) ;
F_75 ( V_14 , V_563 , V_561 ) ;
F_280 ( V_2 ) ;
F_298 ( V_2 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_98 ; V_49 ++ )
F_287 ( V_2 , V_2 -> V_74 [ V_49 ] ) ;
V_197 = F_40 ( V_14 , V_567 ) ;
if ( V_14 -> V_113 . type == V_114 )
V_197 |= V_568 ;
V_197 |= V_569 ;
V_14 -> V_113 . V_353 . V_570 ( V_14 , V_197 ) ;
}
static int F_303 ( struct V_61 * V_62 ,
T_12 V_571 , T_2 V_270 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! V_270 || ! ( V_2 -> V_347 & V_526 ) )
V_14 -> V_113 . V_353 . V_572 ( & V_2 -> V_14 , V_270 , F_291 ( 0 ) , true , ! ! V_270 ) ;
F_92 ( V_270 , V_2 -> V_573 ) ;
return 0 ;
}
static int F_304 ( struct V_15 * V_14 , T_1 V_271 )
{
T_1 V_574 ;
int V_575 ;
if ( V_271 == 0 )
return 0 ;
for ( V_575 = V_576 ; -- V_575 ; ) {
V_574 = F_40 ( V_14 , F_305 ( V_575 ) ) ;
if ( ( V_574 & V_577 ) == V_271 )
break;
}
return V_575 ;
}
void F_306 ( struct V_1 * V_2 , T_1 V_270 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_578 , V_579 ;
int V_575 ;
V_575 = F_304 ( V_14 , V_270 ) ;
if ( ! V_575 )
return;
V_579 = V_575 * 2 + ( F_291 ( 0 ) / 32 ) ;
V_578 = ~ F_209 ( F_291 ( 0 ) % 32 ) ;
V_578 &= F_40 ( V_14 , F_307 ( V_579 ) ) ;
if ( ! V_578 && ! F_40 ( V_14 , F_307 ( V_579 ^ 1 ) ) ) {
if ( ! ( V_2 -> V_347 & V_526 ) )
F_75 ( V_14 , F_307 ( V_579 ) , 0 ) ;
F_75 ( V_14 , F_305 ( V_575 ) , 0 ) ;
}
}
static int F_308 ( struct V_61 * V_62 ,
T_12 V_571 , T_2 V_270 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_270 && ! ( V_2 -> V_347 & V_526 ) )
V_14 -> V_113 . V_353 . V_572 ( V_14 , V_270 , F_291 ( 0 ) , false , true ) ;
F_37 ( V_270 , V_2 -> V_573 ) ;
return 0 ;
}
static void F_309 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_580 ;
int V_49 , V_56 ;
switch ( V_14 -> V_113 . type ) {
case V_114 :
V_580 = F_40 ( V_14 , V_581 ) ;
V_580 &= ~ V_582 ;
F_75 ( V_14 , V_581 , V_580 ) ;
break;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
for ( V_49 = 0 ; V_49 < V_2 -> V_98 ; V_49 ++ ) {
struct V_64 * V_148 = V_2 -> V_74 [ V_49 ] ;
if ( V_148 -> V_152 )
continue;
V_56 = V_148 -> V_154 ;
V_580 = F_40 ( V_14 , F_45 ( V_56 ) ) ;
V_580 &= ~ V_583 ;
F_75 ( V_14 , F_45 ( V_56 ) , V_580 ) ;
}
break;
default:
break;
}
}
static void F_310 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_580 ;
int V_49 , V_56 ;
switch ( V_14 -> V_113 . type ) {
case V_114 :
V_580 = F_40 ( V_14 , V_581 ) ;
V_580 |= V_582 ;
F_75 ( V_14 , V_581 , V_580 ) ;
break;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
for ( V_49 = 0 ; V_49 < V_2 -> V_98 ; V_49 ++ ) {
struct V_64 * V_148 = V_2 -> V_74 [ V_49 ] ;
if ( V_148 -> V_152 )
continue;
V_56 = V_148 -> V_154 ;
V_580 = F_40 ( V_14 , F_45 ( V_56 ) ) ;
V_580 |= V_583 ;
F_75 ( V_14 , F_45 ( V_56 ) , V_580 ) ;
}
break;
default:
break;
}
}
static void F_311 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_580 , V_49 ;
V_580 = F_40 ( V_14 , V_581 ) ;
if ( V_2 -> V_143 & V_584 ) {
V_580 |= V_585 ;
F_75 ( V_14 , V_581 , V_580 ) ;
} else {
V_580 &= ~ V_585 ;
F_75 ( V_14 , V_581 , V_580 ) ;
return;
}
if ( V_14 -> V_113 . type == V_114 )
return;
if ( V_2 -> V_347 & V_526 )
return;
V_2 -> V_347 |= V_526 ;
for ( V_49 = V_576 ; -- V_49 ; ) {
T_1 V_191 = F_307 ( V_49 * 2 + F_291 ( 0 ) / 32 ) ;
T_1 V_586 = F_40 ( V_14 , V_191 ) ;
V_586 |= F_209 ( F_291 ( 0 ) % 32 ) ;
F_75 ( V_14 , V_191 , V_586 ) ;
}
for ( V_49 = V_14 -> V_113 . V_587 ; V_49 -- ; )
F_75 ( V_14 , F_312 ( V_49 ) , ~ 0U ) ;
}
static void F_313 ( struct V_1 * V_2 , T_1 V_588 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_589 [ V_590 ] = { 0 } ;
T_1 V_591 = V_588 * 32 ;
T_1 V_592 = V_591 + ( V_590 * 32 ) ;
T_1 V_49 , V_270 , V_579 , V_578 ;
for ( V_49 = V_576 ; -- V_49 ; ) {
T_1 V_574 = F_40 ( V_14 , F_305 ( V_49 ) ) ;
V_270 = V_574 & V_577 ;
if ( V_270 < V_591 || V_270 >= V_592 )
continue;
if ( V_574 ) {
V_589 [ ( V_270 - V_591 ) / 32 ] |= F_209 ( V_270 % 32 ) ;
if ( F_14 ( V_270 , V_2 -> V_573 ) )
continue;
}
V_579 = V_49 * 2 + F_291 ( 0 ) / 32 ;
V_578 = ~ F_209 ( F_291 ( 0 ) % 32 ) ;
V_578 &= F_40 ( V_14 , F_307 ( V_579 ) ) ;
F_75 ( V_14 , F_307 ( V_579 ) , V_578 ) ;
}
for ( V_49 = V_590 ; V_49 -- ; ) {
V_270 = ( V_588 + V_49 ) * 32 ;
V_579 = V_270 / V_593 ;
V_578 = V_270 % V_593 ;
V_589 [ V_49 ] |= V_2 -> V_573 [ V_579 ] >> V_578 ;
F_75 ( V_14 , F_312 ( V_588 + V_49 ) , V_589 [ V_49 ] ) ;
}
}
static void F_314 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_580 , V_49 ;
V_580 = F_40 ( V_14 , V_581 ) ;
V_580 |= V_585 ;
F_75 ( V_14 , V_581 , V_580 ) ;
if ( ! ( V_2 -> V_143 & V_584 ) ||
V_14 -> V_113 . type == V_114 )
return;
if ( ! ( V_2 -> V_347 & V_526 ) )
return;
V_2 -> V_347 &= ~ V_526 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_113 . V_587 ; V_49 += V_590 )
F_313 ( V_2 , V_49 ) ;
}
static void F_315 ( struct V_1 * V_2 )
{
T_2 V_270 = 1 ;
F_303 ( V_2 -> V_62 , F_162 ( V_272 ) , 0 ) ;
F_316 (vid, adapter->active_vlans, VLAN_N_VID)
F_303 ( V_2 -> V_62 , F_162 ( V_272 ) , V_270 ) ;
}
static int F_317 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! F_61 ( V_62 ) )
return 0 ;
if ( V_14 -> V_113 . V_353 . V_594 )
V_14 -> V_113 . V_353 . V_594 ( V_14 , V_62 ) ;
else
return - V_595 ;
#ifdef F_318
F_319 ( V_2 ) ;
#endif
return F_320 ( V_62 ) ;
}
void F_321 ( struct V_1 * V_2 )
{
struct V_596 * V_597 = & V_2 -> V_597 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_113 . V_598 ; V_49 ++ , V_597 ++ ) {
V_597 -> V_35 &= ~ V_599 ;
if ( V_597 -> V_35 & V_600 )
V_14 -> V_113 . V_353 . V_601 ( V_14 , V_49 ,
V_597 -> V_602 ,
V_597 -> V_506 ,
V_603 ) ;
else
V_14 -> V_113 . V_353 . V_604 ( V_14 , V_49 ) ;
}
}
static void F_322 ( struct V_1 * V_2 )
{
struct V_596 * V_597 = & V_2 -> V_597 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_113 . V_598 ; V_49 ++ , V_597 ++ ) {
if ( ! ( V_597 -> V_35 & V_599 ) )
continue;
V_597 -> V_35 &= ~ V_599 ;
if ( V_597 -> V_35 & V_600 )
V_14 -> V_113 . V_353 . V_601 ( V_14 , V_49 ,
V_597 -> V_602 ,
V_597 -> V_506 ,
V_603 ) ;
else
V_14 -> V_113 . V_353 . V_604 ( V_14 , V_49 ) ;
}
}
static void F_323 ( struct V_1 * V_2 )
{
struct V_596 * V_597 = & V_2 -> V_597 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_113 . V_598 ; V_49 ++ , V_597 ++ ) {
V_597 -> V_35 |= V_599 ;
V_597 -> V_35 &= ~ V_600 ;
}
F_322 ( V_2 ) ;
}
static int F_324 ( struct V_1 * V_2 , T_2 V_506 )
{
struct V_596 * V_597 = & V_2 -> V_597 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 , V_93 = 0 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_113 . V_598 ; V_49 ++ , V_597 ++ ) {
if ( V_597 -> V_35 & V_605 )
continue;
if ( V_597 -> V_35 & V_600 ) {
if ( V_597 -> V_506 != V_506 )
continue;
}
V_93 ++ ;
}
return V_93 ;
}
static void F_325 ( struct V_1 * V_2 )
{
struct V_596 * V_597 = & V_2 -> V_597 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
memcpy ( & V_597 -> V_602 , V_14 -> V_113 . V_602 , V_606 ) ;
V_597 -> V_506 = F_291 ( 0 ) ;
V_597 -> V_35 = V_605 | V_600 ;
V_14 -> V_113 . V_353 . V_601 ( V_14 , 0 , V_597 -> V_602 , V_597 -> V_506 ,
V_603 ) ;
}
int F_326 ( struct V_1 * V_2 ,
const T_4 * V_602 , T_2 V_506 )
{
struct V_596 * V_597 = & V_2 -> V_597 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( F_327 ( V_602 ) )
return - V_607 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_113 . V_598 ; V_49 ++ , V_597 ++ ) {
if ( V_597 -> V_35 & V_600 )
continue;
F_328 ( V_597 -> V_602 , V_602 ) ;
V_597 -> V_506 = V_506 ;
V_597 -> V_35 |= V_599 |
V_600 ;
F_322 ( V_2 ) ;
return V_49 ;
}
return - V_595 ;
}
int F_329 ( struct V_1 * V_2 ,
const T_4 * V_602 , T_2 V_506 )
{
struct V_596 * V_597 = & V_2 -> V_597 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( F_327 ( V_602 ) )
return - V_607 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_113 . V_598 ; V_49 ++ , V_597 ++ ) {
if ( ! ( V_597 -> V_35 & V_600 ) )
continue;
if ( V_597 -> V_506 != V_506 )
continue;
if ( ! F_330 ( V_602 , V_597 -> V_602 ) )
continue;
V_597 -> V_35 |= V_599 ;
V_597 -> V_35 &= ~ V_600 ;
F_322 ( V_2 ) ;
return 0 ;
}
return - V_595 ;
}
static int F_331 ( struct V_61 * V_62 , int V_608 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
int V_93 = 0 ;
if ( F_332 ( V_62 ) > F_324 ( V_2 , V_608 ) )
return - V_595 ;
if ( ! F_333 ( V_62 ) ) {
struct V_609 * V_610 ;
F_334 (ha, netdev) {
F_329 ( V_2 , V_610 -> V_602 , V_608 ) ;
F_326 ( V_2 , V_610 -> V_602 , V_608 ) ;
V_93 ++ ;
}
}
return V_93 ;
}
static int F_335 ( struct V_61 * V_62 , const unsigned char * V_602 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
int V_611 ;
V_611 = F_326 ( V_2 , V_602 , F_291 ( 0 ) ) ;
return F_336 ( int , V_611 , 0 ) ;
}
static int F_337 ( struct V_61 * V_62 , const unsigned char * V_602 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
F_329 ( V_2 , V_602 , F_291 ( 0 ) ) ;
return 0 ;
}
void F_338 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_612 , V_613 = V_614 | V_615 ;
T_13 V_214 = V_62 -> V_214 ;
int V_93 ;
V_612 = F_40 ( V_14 , V_616 ) ;
V_612 &= ~ V_617 ;
V_612 |= V_618 ;
V_612 |= V_619 ;
V_612 |= V_620 ;
V_612 &= ~ ( V_621 | V_622 ) ;
if ( V_62 -> V_143 & V_623 ) {
V_14 -> V_624 . V_625 = true ;
V_612 |= ( V_621 | V_622 ) ;
V_613 |= V_626 ;
V_214 &= ~ V_627 ;
} else {
if ( V_62 -> V_143 & V_628 ) {
V_612 |= V_622 ;
V_613 |= V_626 ;
}
V_14 -> V_624 . V_625 = false ;
}
if ( F_339 ( V_62 , F_335 , F_337 ) ) {
V_612 |= V_621 ;
V_613 |= V_629 ;
}
V_93 = F_317 ( V_62 ) ;
if ( V_93 < 0 ) {
V_612 |= V_622 ;
V_613 |= V_626 ;
} else if ( V_93 ) {
V_613 |= V_630 ;
}
if ( V_14 -> V_113 . type != V_114 ) {
V_613 |= F_40 ( V_14 , F_340 ( F_291 ( 0 ) ) ) &
~ ( V_626 | V_630 |
V_629 ) ;
F_75 ( V_14 , F_340 ( F_291 ( 0 ) ) , V_613 ) ;
}
if ( V_214 & V_293 ) {
V_612 |= ( V_617 |
V_618 |
V_620 ) ;
V_612 &= ~ ( V_619 ) ;
}
F_75 ( V_14 , V_616 , V_612 ) ;
if ( V_214 & V_268 )
F_310 ( V_2 ) ;
else
F_309 ( V_2 ) ;
if ( V_214 & V_627 )
F_314 ( V_2 ) ;
else
F_311 ( V_2 ) ;
}
static void F_341 ( struct V_1 * V_2 )
{
int V_631 ;
for ( V_631 = 0 ; V_631 < V_2 -> V_206 ; V_631 ++ )
F_342 ( & V_2 -> V_170 [ V_631 ] -> V_274 ) ;
}
static void F_343 ( struct V_1 * V_2 )
{
int V_631 ;
for ( V_631 = 0 ; V_631 < V_2 -> V_206 ; V_631 ++ )
F_344 ( & V_2 -> V_170 [ V_631 ] -> V_274 ) ;
}
static void F_345 ( struct V_1 * V_2 , T_1 V_123 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_632 ;
if ( ! ( V_2 -> V_143 & ( V_633 |
V_634 ) ) )
return;
V_632 = F_40 ( V_14 , V_635 ) && ~ V_123 ;
F_75 ( V_14 , V_635 , V_632 ) ;
if ( V_123 & V_636 )
V_2 -> V_637 = 0 ;
if ( V_123 & V_638 )
V_2 -> V_639 = 0 ;
}
static void F_346 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_535 = V_2 -> V_62 -> V_312 + V_536 + V_537 ;
if ( ! ( V_2 -> V_143 & V_144 ) ) {
if ( V_14 -> V_113 . type == V_114 )
F_347 ( V_2 -> V_62 , 65536 ) ;
return;
}
if ( V_14 -> V_113 . type == V_114 )
F_347 ( V_2 -> V_62 , 32768 ) ;
#ifdef F_181
if ( V_2 -> V_62 -> V_214 & V_640 )
V_535 = F_214 ( V_535 , V_541 ) ;
#endif
if ( V_2 -> V_641 & V_642 ) {
F_348 ( V_14 , & V_2 -> V_140 , V_535 ,
V_643 ) ;
F_348 ( V_14 , & V_2 -> V_140 , V_535 ,
V_644 ) ;
F_349 ( V_14 , & V_2 -> V_140 ) ;
} else if ( V_2 -> V_645 && V_2 -> V_142 ) {
F_350 ( & V_2 -> V_14 ,
V_2 -> V_645 ,
V_535 ) ;
F_351 ( & V_2 -> V_14 ,
V_2 -> V_142 -> V_139 ,
V_2 -> V_645 -> V_646 ) ;
}
if ( V_14 -> V_113 . type != V_114 ) {
T_1 V_647 = 0 ;
T_2 V_471 = V_2 -> V_441 [ V_456 ] . V_472 - 1 ;
while ( V_471 ) {
V_647 ++ ;
V_471 >>= 1 ;
}
F_75 ( V_14 , V_648 , V_647 * 0x11111111 ) ;
}
}
static int F_352 ( struct V_1 * V_2 , int V_649 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_61 * V_80 = V_2 -> V_62 ;
int V_395 , V_138 , V_650 , V_651 ;
T_1 V_652 , V_653 ;
V_138 = V_395 = V_80 -> V_312 + V_536 + V_537 + V_654 ;
#ifdef F_181
if ( ( V_80 -> V_214 & V_640 ) &&
( V_138 < V_541 ) &&
( V_649 == F_353 ( V_2 ) ) )
V_138 = V_541 ;
#endif
switch ( V_14 -> V_113 . type ) {
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_652 = F_354 ( V_395 , V_138 ) ;
break;
default:
V_652 = F_355 ( V_395 , V_138 ) ;
break;
}
if ( V_2 -> V_143 & V_436 )
V_652 += F_356 ( V_138 ) ;
V_650 = F_357 ( V_652 ) ;
V_653 = F_40 ( V_14 , F_358 ( V_649 ) ) >> 10 ;
V_651 = V_653 - V_650 ;
if ( V_651 < 0 ) {
F_27 ( V_160 , L_87
L_88
L_89 , V_649 ) ;
V_651 = V_138 + 1 ;
}
return V_651 ;
}
static int F_359 ( struct V_1 * V_2 , int V_649 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_61 * V_80 = V_2 -> V_62 ;
int V_138 ;
T_1 V_652 ;
V_138 = V_80 -> V_312 + V_536 + V_537 ;
#ifdef F_181
if ( ( V_80 -> V_214 & V_640 ) &&
( V_138 < V_541 ) &&
( V_649 == F_85 ( V_80 , V_2 -> V_655 . V_656 ) ) )
V_138 = V_541 ;
#endif
switch ( V_14 -> V_113 . type ) {
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_652 = F_360 ( V_138 ) ;
break;
default:
V_652 = F_361 ( V_138 ) ;
break;
}
return F_357 ( V_652 ) ;
}
static void F_362 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_657 = F_264 ( V_2 -> V_62 ) ;
int V_49 ;
if ( ! V_657 )
V_657 = 1 ;
for ( V_49 = 0 ; V_49 < V_657 ; V_49 ++ ) {
V_14 -> V_129 . V_658 [ V_49 ] = F_352 ( V_2 , V_49 ) ;
V_14 -> V_129 . V_659 [ V_49 ] = F_359 ( V_2 , V_49 ) ;
if ( V_14 -> V_129 . V_659 [ V_49 ] > V_14 -> V_129 . V_658 [ V_49 ] )
V_14 -> V_129 . V_659 [ V_49 ] = 0 ;
}
for (; V_49 < V_660 ; V_49 ++ )
V_14 -> V_129 . V_658 [ V_49 ] = 0 ;
}
static void F_363 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_661 ;
T_4 V_138 = F_264 ( V_2 -> V_62 ) ;
if ( V_2 -> V_143 & V_388 ||
V_2 -> V_143 & V_662 )
V_661 = 32 << V_2 -> V_663 ;
else
V_661 = 0 ;
V_14 -> V_113 . V_353 . V_664 ( V_14 , V_138 , V_661 , V_665 ) ;
F_362 ( V_2 ) ;
}
static void F_364 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_666 * V_667 ;
struct V_668 * V_669 ;
F_365 ( & V_2 -> V_670 ) ;
if ( ! F_366 ( & V_2 -> V_671 ) )
F_367 ( V_14 , & V_2 -> V_672 ) ;
F_368 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_369 ( V_14 ,
& V_669 -> V_669 ,
V_669 -> V_673 ,
( V_669 -> V_674 == V_675 ) ?
V_675 :
V_2 -> V_74 [ V_669 -> V_674 ] -> V_154 ) ;
}
F_370 ( & V_2 -> V_670 ) ;
}
static void F_371 ( struct V_61 * V_80 , unsigned int V_506 ,
struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_613 ;
V_613 = F_40 ( V_14 , F_340 ( V_506 ) ) ;
V_613 |= ( V_630 | V_614 | V_615 ) ;
V_613 &= ~ V_626 ;
if ( V_80 -> V_143 & V_628 ) {
V_613 |= V_626 ;
} else {
V_613 |= V_630 ;
V_14 -> V_113 . V_353 . V_594 ( V_14 , V_80 ) ;
}
F_331 ( V_2 -> V_62 , V_506 ) ;
F_75 ( V_14 , F_340 ( V_506 ) , V_613 ) ;
}
static void F_372 ( struct V_676 * V_677 )
{
struct V_1 * V_2 = V_677 -> V_153 ;
int V_471 = V_2 -> V_678 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_506 = V_677 -> V_506 ;
T_1 V_507 = V_508 |
V_509 |
V_510 |
V_511 |
V_512 ;
if ( V_14 -> V_113 . type == V_114 )
return;
if ( V_471 > 3 )
V_507 |= 2u << 29 ;
else if ( V_471 > 1 )
V_507 |= 1u << 29 ;
F_75 ( V_14 , F_290 ( F_291 ( V_506 ) ) , V_507 ) ;
}
static void F_373 ( struct V_64 * V_74 )
{
T_2 V_49 = V_74 -> V_84 ;
struct V_77 * V_297 = & V_74 -> V_78 [ V_49 ] ;
while ( V_49 != V_74 -> V_259 ) {
if ( V_297 -> V_94 ) {
struct V_212 * V_94 = V_297 -> V_94 ;
if ( F_157 ( V_94 ) -> V_291 )
F_176 ( V_74 -> V_80 ,
F_157 ( V_94 ) -> V_86 ,
F_145 ( V_74 ) ,
V_251 ,
V_252 ) ;
F_374 ( V_94 ) ;
}
F_177 ( V_74 -> V_80 ,
V_297 -> V_86 ,
V_297 -> V_104 ,
F_73 ( V_74 ) ,
V_251 ) ;
F_176 ( V_74 -> V_80 , V_297 -> V_86 ,
F_145 ( V_74 ) ,
V_251 ,
V_252 ) ;
F_198 ( V_297 -> V_103 ,
V_297 -> V_253 ) ;
V_49 ++ ;
V_297 ++ ;
if ( V_49 == V_74 -> V_93 ) {
V_49 = 0 ;
V_297 = V_74 -> V_78 ;
}
}
V_74 -> V_259 = 0 ;
V_74 -> V_84 = 0 ;
V_74 -> V_85 = 0 ;
}
static void F_375 ( struct V_676 * V_677 ,
struct V_64 * V_74 )
{
struct V_1 * V_2 = V_677 -> V_153 ;
int V_112 = V_74 -> V_91 + V_677 -> V_679 ;
F_286 ( V_2 , V_74 ) ;
F_261 ( 10000 , 20000 ) ;
F_228 ( V_2 , F_244 ( V_112 ) ) ;
F_373 ( V_74 ) ;
V_74 -> V_152 = NULL ;
}
static int F_376 ( struct V_61 * V_680 ,
struct V_676 * V_681 )
{
struct V_1 * V_2 = V_681 -> V_153 ;
unsigned int V_682 = V_681 -> V_679 ;
unsigned int V_683 = V_681 -> V_684 ;
int V_49 ;
F_377 ( V_680 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_678 ; V_49 ++ ) {
F_375 ( V_681 , V_2 -> V_74 [ V_682 + V_49 ] ) ;
V_2 -> V_74 [ V_682 + V_49 ] -> V_62 = V_2 -> V_62 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_678 ; V_49 ++ ) {
V_2 -> V_65 [ V_683 + V_49 ] -> V_152 = NULL ;
V_2 -> V_65 [ V_683 + V_49 ] -> V_62 = V_2 -> V_62 ;
}
return 0 ;
}
static int F_378 ( struct V_61 * V_680 ,
struct V_676 * V_681 )
{
struct V_1 * V_2 = V_681 -> V_153 ;
unsigned int V_682 , V_683 , V_380 ;
int V_49 , V_685 , V_17 = 0 ;
if ( ! F_14 ( V_681 -> V_506 , & V_2 -> V_686 ) )
return 0 ;
V_685 = V_681 -> V_506 * V_2 -> V_678 ;
F_379 ( V_680 , L_90 ,
V_681 -> V_506 , V_2 -> V_687 ,
V_685 , V_685 + V_2 -> V_678 ,
V_2 -> V_686 ) ;
V_681 -> V_62 = V_680 ;
V_681 -> V_679 = V_682 = V_685 ;
V_681 -> V_684 = V_683 = V_685 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_678 ; V_49 ++ )
F_375 ( V_681 , V_2 -> V_74 [ V_682 + V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_678 ; V_49 ++ ) {
V_2 -> V_74 [ V_682 + V_49 ] -> V_62 = V_680 ;
V_2 -> V_74 [ V_682 + V_49 ] -> V_152 = V_681 ;
F_287 ( V_2 , V_2 -> V_74 [ V_682 + V_49 ] ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_678 ; V_49 ++ ) {
V_2 -> V_65 [ V_683 + V_49 ] -> V_62 = V_680 ;
V_2 -> V_65 [ V_683 + V_49 ] -> V_152 = V_681 ;
}
V_380 = F_336 (unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues) ;
V_17 = F_380 ( V_680 , V_380 ) ;
if ( V_17 )
goto V_688;
V_17 = F_381 ( V_680 , V_380 ) ;
if ( V_17 )
goto V_688;
if ( F_382 ( V_680 -> V_689 ) )
F_326 ( V_2 , V_680 -> V_689 , V_681 -> V_506 ) ;
F_372 ( V_681 ) ;
F_371 ( V_680 , V_681 -> V_506 , V_2 ) ;
return V_17 ;
V_688:
F_376 ( V_680 , V_681 ) ;
return V_17 ;
}
static int F_383 ( struct V_61 * V_100 , void * V_97 )
{
if ( F_384 ( V_100 ) ) {
struct V_690 * V_691 = F_88 ( V_100 ) ;
struct V_676 * V_677 = V_691 -> V_692 ;
if ( V_691 -> V_692 )
F_378 ( V_100 , V_677 ) ;
}
return 0 ;
}
static void F_385 ( struct V_1 * V_2 )
{
F_386 ( V_2 -> V_62 ,
F_383 , NULL ) ;
}
static void F_387 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
F_363 ( V_2 ) ;
#ifdef F_388
F_346 ( V_2 ) ;
#endif
F_292 ( V_2 ) ;
F_338 ( V_2 -> V_62 ) ;
F_315 ( V_2 ) ;
switch ( V_14 -> V_113 . type ) {
case V_116 :
case V_117 :
V_14 -> V_113 . V_353 . V_693 ( V_14 ) ;
break;
default:
break;
}
if ( V_2 -> V_143 & V_388 ) {
F_389 ( & V_2 -> V_14 ,
V_2 -> V_663 ) ;
} else if ( V_2 -> V_143 & V_662 ) {
F_390 ( & V_2 -> V_14 ,
V_2 -> V_663 ) ;
F_364 ( V_2 ) ;
}
switch ( V_14 -> V_113 . type ) {
case V_116 :
case V_117 :
V_14 -> V_113 . V_353 . V_694 ( V_14 ) ;
break;
default:
break;
}
#ifdef F_242
if ( V_2 -> V_143 & V_209 )
F_126 ( V_2 ) ;
#endif
#ifdef F_181
F_391 ( V_2 ) ;
#endif
F_265 ( V_2 ) ;
F_302 ( V_2 ) ;
F_385 ( V_2 ) ;
}
static void F_392 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_113 . type == V_114 )
V_2 -> V_347 |= V_695 ;
V_2 -> V_347 |= V_372 ;
V_2 -> V_373 = 0 ;
}
static int F_393 ( struct V_15 * V_14 )
{
T_1 V_20 ;
bool V_696 , V_355 = false ;
int V_611 = V_697 ;
if ( V_14 -> V_113 . V_353 . V_354 )
V_611 = V_14 -> V_113 . V_353 . V_354 ( V_14 , & V_20 , & V_355 , false ) ;
if ( V_611 )
return V_611 ;
V_20 = V_14 -> V_46 . V_698 ;
if ( ( ! V_20 ) && ( V_14 -> V_113 . V_353 . V_699 ) )
V_611 = V_14 -> V_113 . V_353 . V_699 ( V_14 , & V_20 ,
& V_696 ) ;
if ( V_611 )
return V_611 ;
if ( V_14 -> V_113 . V_353 . V_700 )
V_611 = V_14 -> V_113 . V_353 . V_700 ( V_14 , V_20 , V_355 ) ;
return V_611 ;
}
static void F_394 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_701 = 0 ;
if ( V_2 -> V_143 & V_416 ) {
V_701 = V_702 | V_703 |
V_704 ;
V_701 |= V_705 ;
switch ( V_14 -> V_113 . type ) {
case V_114 :
F_75 ( V_14 , V_706 , V_707 ) ;
break;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
default:
F_75 ( V_14 , F_395 ( 0 ) , 0xFFFFFFFF ) ;
F_75 ( V_14 , F_395 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_75 ( V_14 , V_706 , V_707 ) ;
}
if ( V_2 -> V_143 & V_436 ) {
V_701 &= ~ V_708 ;
switch ( V_2 -> V_441 [ V_442 ] . V_123 ) {
case V_527 :
V_701 |= V_709 ;
break;
case V_443 :
V_701 |= V_710 ;
break;
default:
V_701 |= V_711 ;
break;
}
}
if ( V_2 -> V_347 & V_348 ) {
switch ( V_2 -> V_14 . V_113 . type ) {
case V_116 :
V_701 |= V_712 ;
break;
default:
break;
}
}
if ( V_2 -> V_143 & V_361 )
V_701 |= F_396 ( V_14 ) ;
switch ( V_14 -> V_113 . type ) {
case V_116 :
V_701 |= V_713 | V_714 ;
break;
case V_119 :
case V_120 :
V_701 |= V_715 ;
break;
default:
break;
}
F_75 ( V_14 , V_716 , V_701 ) ;
}
static void F_397 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 ;
T_1 V_105 ;
F_76 ( V_2 ) ;
F_394 ( V_2 ) ;
if ( V_2 -> V_143 & V_416 )
F_208 ( V_2 ) ;
else
F_257 ( V_2 ) ;
if ( V_14 -> V_113 . V_353 . V_717 )
V_14 -> V_113 . V_353 . V_717 ( V_14 ) ;
if ( V_14 -> V_46 . V_353 . V_718 )
V_14 -> V_46 . V_353 . V_718 ( V_14 , true ) ;
F_36 () ;
F_37 ( V_34 , & V_2 -> V_35 ) ;
F_341 ( V_2 ) ;
if ( F_221 ( V_14 ) ) {
F_392 ( V_2 ) ;
} else {
V_17 = F_393 ( V_14 ) ;
if ( V_17 )
F_106 ( V_186 , L_91 , V_17 ) ;
}
F_40 ( V_14 , V_362 ) ;
F_230 ( V_2 , true , true ) ;
if ( V_2 -> V_143 & V_361 ) {
T_1 V_719 = F_40 ( V_14 , V_720 ) ;
if ( V_719 & V_721 )
F_217 ( V_160 , L_72 ) ;
}
V_2 -> V_143 |= V_376 ;
V_2 -> V_377 = V_185 ;
F_398 ( & V_2 -> V_722 , V_185 ) ;
V_105 = F_40 ( V_14 , V_106 ) ;
V_105 |= V_723 ;
F_75 ( V_14 , V_106 , V_105 ) ;
}
void F_399 ( struct V_1 * V_2 )
{
F_400 ( F_401 () ) ;
F_402 ( V_2 -> V_62 ) ;
while ( F_15 ( V_724 , & V_2 -> V_35 ) )
F_261 ( 1000 , 2000 ) ;
if ( V_2 -> V_14 . V_46 . type == V_725 )
F_403 ( V_2 ) ;
F_404 ( V_2 ) ;
if ( V_2 -> V_143 & V_436 )
F_405 ( 2000 ) ;
F_406 ( V_2 ) ;
F_37 ( V_724 , & V_2 -> V_35 ) ;
}
void F_406 ( struct V_1 * V_2 )
{
F_387 ( V_2 ) ;
F_397 ( V_2 ) ;
}
void F_407 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_61 * V_62 = V_2 -> V_62 ;
int V_17 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
while ( F_15 ( V_726 , & V_2 -> V_35 ) )
F_261 ( 1000 , 2000 ) ;
V_2 -> V_347 &= ~ ( V_695 |
V_372 ) ;
V_2 -> V_143 &= ~ V_374 ;
V_17 = V_14 -> V_113 . V_353 . V_727 ( V_14 ) ;
switch ( V_17 ) {
case 0 :
case V_728 :
case V_729 :
break;
case V_730 :
F_18 ( L_92 ) ;
break;
case V_731 :
F_11 ( L_93
L_94
L_95
L_96
L_97
L_98 ) ;
break;
default:
F_18 ( L_99 , V_17 ) ;
}
F_37 ( V_726 , & V_2 -> V_35 ) ;
F_323 ( V_2 ) ;
F_408 ( V_62 , NULL ) ;
F_325 ( V_2 ) ;
if ( V_14 -> V_113 . V_732 )
V_14 -> V_113 . V_353 . V_733 ( V_14 , F_291 ( 0 ) ) ;
if ( F_14 ( V_734 , & V_2 -> V_35 ) )
F_409 ( V_2 ) ;
if ( V_14 -> V_46 . V_353 . V_718 ) {
if ( ! F_61 ( V_2 -> V_62 ) && ! V_2 -> V_735 )
V_14 -> V_46 . V_353 . V_718 ( V_14 , false ) ;
else
V_14 -> V_46 . V_353 . V_718 ( V_14 , true ) ;
}
}
static void F_410 ( struct V_64 * V_65 )
{
T_2 V_49 = V_65 -> V_84 ;
struct V_66 * V_67 = & V_65 -> V_83 [ V_49 ] ;
while ( V_49 != V_65 -> V_85 ) {
union V_68 * V_177 , * V_69 ;
F_180 ( V_67 -> V_94 ) ;
F_99 ( V_65 -> V_80 ,
F_62 ( V_67 , V_86 ) ,
F_63 ( V_67 , V_87 ) ,
V_182 ) ;
V_177 = V_67 -> V_88 ;
V_69 = F_65 ( V_65 , V_49 ) ;
while ( V_69 != V_177 ) {
V_67 ++ ;
V_69 ++ ;
V_49 ++ ;
if ( F_23 ( V_49 == V_65 -> V_93 ) ) {
V_49 = 0 ;
V_67 = V_65 -> V_83 ;
V_69 = F_65 ( V_65 , 0 ) ;
}
if ( F_63 ( V_67 , V_87 ) )
F_101 ( V_65 -> V_80 ,
F_62 ( V_67 , V_86 ) ,
F_63 ( V_67 , V_87 ) ,
V_182 ) ;
}
V_67 ++ ;
V_49 ++ ;
if ( F_23 ( V_49 == V_65 -> V_93 ) ) {
V_49 = 0 ;
V_67 = V_65 -> V_83 ;
}
}
F_411 ( F_110 ( V_65 ) ) ;
V_65 -> V_85 = 0 ;
V_65 -> V_84 = 0 ;
}
static void F_412 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_98 ; V_49 ++ )
F_373 ( V_2 -> V_74 [ V_49 ] ) ;
}
static void F_413 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_82 ; V_49 ++ )
F_410 ( V_2 -> V_65 [ V_49 ] ) ;
}
static void F_414 ( struct V_1 * V_2 )
{
struct V_666 * V_667 ;
struct V_668 * V_669 ;
F_365 ( & V_2 -> V_670 ) ;
F_368 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_415 ( & V_669 -> V_736 ) ;
F_251 ( V_669 ) ;
}
V_2 -> V_737 = 0 ;
F_370 ( & V_2 -> V_670 ) ;
}
static int F_416 ( struct V_61 * V_100 , void * V_97 )
{
if ( F_384 ( V_100 ) ) {
struct V_690 * V_271 = F_88 ( V_100 ) ;
if ( V_271 -> V_692 ) {
F_377 ( V_100 ) ;
F_417 ( V_100 ) ;
F_418 ( V_100 ) ;
}
}
return 0 ;
}
void F_404 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( F_15 ( V_34 , & V_2 -> V_35 ) )
return;
V_14 -> V_113 . V_353 . V_562 ( V_14 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_98 ; V_49 ++ )
F_286 ( V_2 , V_2 -> V_74 [ V_49 ] ) ;
F_261 ( 10000 , 20000 ) ;
F_377 ( V_62 ) ;
F_417 ( V_62 ) ;
F_418 ( V_62 ) ;
F_386 ( V_2 -> V_62 ,
F_416 , NULL ) ;
F_255 ( V_2 ) ;
F_343 ( V_2 ) ;
F_37 ( V_159 , & V_2 -> V_35 ) ;
V_2 -> V_347 &= ~ V_389 ;
V_2 -> V_143 &= ~ V_376 ;
F_419 ( & V_2 -> V_722 ) ;
if ( V_2 -> V_318 ) {
F_75 ( & V_2 -> V_14 , V_320 , 0 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_318 ; V_49 ++ )
V_2 -> V_532 [ V_49 ] . V_738 = false ;
F_420 ( V_2 ) ;
F_421 ( V_2 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_82 ; V_49 ++ ) {
T_4 V_154 = V_2 -> V_65 [ V_49 ] -> V_154 ;
F_75 ( V_14 , F_53 ( V_154 ) , V_739 ) ;
}
switch ( V_14 -> V_113 . type ) {
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
F_75 ( V_14 , V_452 ,
( F_40 ( V_14 , V_452 ) &
~ V_453 ) ) ;
break;
default:
break;
}
if ( ! F_422 ( V_2 -> V_9 ) )
F_407 ( V_2 ) ;
if ( V_14 -> V_113 . V_353 . V_740 )
V_14 -> V_113 . V_353 . V_740 ( V_14 ) ;
F_413 ( V_2 ) ;
F_412 ( V_2 ) ;
}
static void F_423 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_21 ) {
case V_358 :
case V_359 :
if ( ! V_14 -> V_46 . V_741 )
break;
V_2 -> V_347 |= V_742 ;
if ( ! V_14 -> V_46 . V_743 )
break;
V_2 -> V_347 |= V_744 ;
break;
default:
V_2 -> V_347 &= ~ V_742 ;
V_2 -> V_347 &= ~ V_744 ;
break;
}
}
static void F_424 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
F_91 ( V_2 ) ;
}
static void F_425 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_745 * V_138 ;
int V_56 ;
switch ( V_14 -> V_113 . type ) {
case V_114 :
case V_116 :
V_2 -> V_140 . V_746 . V_747 = V_660 ;
V_2 -> V_140 . V_746 . V_748 = V_660 ;
break;
case V_117 :
case V_118 :
V_2 -> V_140 . V_746 . V_747 = V_749 ;
V_2 -> V_140 . V_746 . V_748 = V_749 ;
break;
case V_119 :
case V_120 :
default:
V_2 -> V_140 . V_746 . V_747 = V_750 ;
V_2 -> V_140 . V_746 . V_748 = V_750 ;
break;
}
for ( V_56 = 0 ; V_56 < V_660 ; V_56 ++ ) {
V_138 = & V_2 -> V_140 . V_751 [ V_56 ] ;
V_138 -> V_752 [ V_643 ] . V_753 = 0 ;
V_138 -> V_752 [ V_643 ] . V_754 = 12 + ( V_56 & 1 ) ;
V_138 -> V_752 [ V_644 ] . V_753 = 0 ;
V_138 -> V_752 [ V_644 ] . V_754 = 12 + ( V_56 & 1 ) ;
V_138 -> V_755 = V_756 ;
}
V_138 = & V_2 -> V_140 . V_751 [ 0 ] ;
V_138 -> V_752 [ V_643 ] . V_757 = 0xFF ;
V_138 -> V_752 [ V_644 ] . V_757 = 0xFF ;
V_2 -> V_140 . V_758 [ V_643 ] [ 0 ] = 100 ;
V_2 -> V_140 . V_758 [ V_644 ] [ 0 ] = 100 ;
V_2 -> V_140 . V_141 = false ;
V_2 -> V_759 = 0x00 ;
if ( V_2 -> V_143 & V_760 )
V_2 -> V_641 = V_761 | V_642 ;
memcpy ( & V_2 -> V_762 , & V_2 -> V_140 ,
sizeof( V_2 -> V_762 ) ) ;
}
static int F_426 ( struct V_1 * V_2 ,
const struct V_763 * V_764 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_222 , V_765 ;
T_1 V_766 ;
int V_49 ;
V_14 -> V_767 = V_9 -> V_768 ;
V_14 -> V_21 = V_9 -> V_207 ;
V_14 -> V_769 = V_9 -> V_770 ;
V_14 -> V_771 = V_9 -> V_772 ;
V_14 -> V_773 = V_9 -> V_774 ;
V_764 -> V_775 ( V_14 ) ;
V_222 = F_336 ( int , F_427 ( V_2 ) , F_428 () ) ;
V_2 -> V_441 [ V_456 ] . V_776 = V_222 ;
V_2 -> V_347 |= V_777 ;
V_2 -> V_778 = V_779 ;
V_2 -> V_426 = 20 ;
V_765 = F_336 ( int , V_780 , F_428 () ) ;
V_2 -> V_441 [ V_781 ] . V_776 = V_765 ;
V_2 -> V_663 = V_782 ;
#ifdef F_242
V_2 -> V_143 |= V_209 ;
#endif
#ifdef F_388
V_2 -> V_143 |= V_760 ;
V_2 -> V_143 &= ~ V_144 ;
#endif
#ifdef F_181
V_2 -> V_143 |= V_783 ;
V_2 -> V_143 &= ~ V_540 ;
#ifdef F_388
V_2 -> V_655 . V_656 = V_784 ;
#endif
#endif
V_2 -> V_785 [ 0 ] = F_429 ( sizeof( * V_2 -> V_785 [ 0 ] ) ,
V_786 ) ;
if ( ! V_2 -> V_785 [ 0 ] )
return - V_595 ;
V_2 -> V_785 [ 0 ] -> V_787 = V_788 ;
for ( V_49 = 1 ; V_49 < V_789 ; V_49 ++ )
V_2 -> V_785 [ V_49 ] = NULL ;
V_2 -> V_597 = F_429 ( sizeof( struct V_596 ) *
V_14 -> V_113 . V_598 ,
V_790 ) ;
if ( ! V_2 -> V_597 )
return - V_595 ;
switch ( V_14 -> V_113 . type ) {
case V_114 :
V_2 -> V_347 &= ~ V_777 ;
if ( V_14 -> V_21 == V_791 )
V_2 -> V_143 |= V_361 ;
V_2 -> V_778 = V_792 ;
V_2 -> V_441 [ V_781 ] . V_776 = 0 ;
V_2 -> V_426 = 0 ;
V_2 -> V_663 = 0 ;
#ifdef F_181
V_2 -> V_143 &= ~ V_783 ;
V_2 -> V_143 &= ~ V_540 ;
#ifdef F_388
V_2 -> V_655 . V_656 = 0 ;
#endif
#endif
break;
case V_116 :
if ( V_14 -> V_21 == V_350 )
V_2 -> V_347 |= V_348 ;
break;
case V_117 :
V_766 = F_40 ( V_14 , F_430 ( V_14 ) ) ;
if ( V_766 & V_793 )
V_2 -> V_347 |= V_348 ;
break;
case V_120 :
V_2 -> V_143 |= V_634 ;
switch ( V_14 -> V_21 ) {
case V_358 :
case V_359 :
V_2 -> V_347 |= V_348 ;
break;
default:
break;
}
case V_119 :
#ifdef F_388
V_2 -> V_143 &= ~ V_760 ;
#endif
#ifdef F_181
V_2 -> V_143 &= ~ V_783 ;
#ifdef F_388
V_2 -> V_655 . V_656 = 0 ;
#endif
#endif
case V_118 :
if ( V_14 -> V_113 . type == V_118 )
V_2 -> V_347 |= V_348 ;
#ifdef F_242
V_2 -> V_143 &= ~ V_209 ;
#endif
V_2 -> V_143 |= V_633 ;
break;
default:
break;
}
#ifdef F_181
F_431 ( & V_2 -> V_655 . V_794 ) ;
#endif
F_431 ( & V_2 -> V_670 ) ;
#ifdef F_388
F_425 ( V_2 ) ;
#endif
V_14 -> V_129 . V_795 = V_131 ;
V_14 -> V_129 . V_130 = V_131 ;
F_362 ( V_2 ) ;
V_14 -> V_129 . V_796 = V_797 ;
V_14 -> V_129 . V_798 = true ;
V_14 -> V_129 . V_799 = F_432 ( V_14 ) ;
#ifdef F_318
if ( V_800 > 0 )
F_11 ( L_100 ) ;
if ( V_14 -> V_113 . type != V_114 ) {
if ( V_800 > V_801 ) {
V_2 -> V_318 = 0 ;
F_11 ( L_101 ) ;
} else {
V_2 -> V_318 = V_800 ;
}
}
#endif
V_2 -> V_407 = 1 ;
V_2 -> V_802 = 1 ;
V_2 -> V_803 = V_804 ;
V_2 -> V_805 = V_806 ;
V_2 -> V_807 = V_808 ;
if ( F_433 ( V_14 ) ) {
F_18 ( L_102 ) ;
return - V_809 ;
}
F_92 ( 0 , & V_2 -> V_686 ) ;
F_92 ( V_34 , & V_2 -> V_35 ) ;
return 0 ;
}
int F_434 ( struct V_64 * V_65 )
{
struct V_207 * V_80 = V_65 -> V_80 ;
int V_810 = F_435 ( V_80 ) ;
int V_811 = - 1 ;
int V_300 ;
V_300 = sizeof( struct V_66 ) * V_65 -> V_93 ;
if ( V_65 -> V_170 )
V_811 = V_65 -> V_170 -> V_812 ;
V_65 -> V_83 = F_436 ( V_300 , V_811 ) ;
if ( ! V_65 -> V_83 )
V_65 -> V_83 = F_437 ( V_300 ) ;
if ( ! V_65 -> V_83 )
goto V_17;
F_438 ( & V_65 -> V_183 ) ;
V_65 -> V_300 = V_65 -> V_93 * sizeof( union V_68 ) ;
V_65 -> V_300 = F_173 ( V_65 -> V_300 , 4096 ) ;
F_439 ( V_80 , V_811 ) ;
V_65 -> V_92 = F_440 ( V_80 ,
V_65 -> V_300 ,
& V_65 -> V_86 ,
V_786 ) ;
F_439 ( V_80 , V_810 ) ;
if ( ! V_65 -> V_92 )
V_65 -> V_92 = F_440 ( V_80 , V_65 -> V_300 ,
& V_65 -> V_86 , V_786 ) ;
if ( ! V_65 -> V_92 )
goto V_17;
V_65 -> V_85 = 0 ;
V_65 -> V_84 = 0 ;
return 0 ;
V_17:
F_441 ( V_65 -> V_83 ) ;
V_65 -> V_83 = NULL ;
F_442 ( V_80 , L_103 ) ;
return - V_595 ;
}
static int F_443 ( struct V_1 * V_2 )
{
int V_49 , V_17 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_82 ; V_49 ++ ) {
V_17 = F_434 ( V_2 -> V_65 [ V_49 ] ) ;
if ( ! V_17 )
continue;
F_106 ( V_186 , L_104 , V_49 ) ;
goto V_813;
}
return 0 ;
V_813:
while ( V_49 -- )
F_444 ( V_2 -> V_65 [ V_49 ] ) ;
return V_17 ;
}
int F_445 ( struct V_64 * V_74 )
{
struct V_207 * V_80 = V_74 -> V_80 ;
int V_810 = F_435 ( V_80 ) ;
int V_811 = - 1 ;
int V_300 ;
V_300 = sizeof( struct V_77 ) * V_74 -> V_93 ;
if ( V_74 -> V_170 )
V_811 = V_74 -> V_170 -> V_812 ;
V_74 -> V_78 = F_436 ( V_300 , V_811 ) ;
if ( ! V_74 -> V_78 )
V_74 -> V_78 = F_437 ( V_300 ) ;
if ( ! V_74 -> V_78 )
goto V_17;
F_438 ( & V_74 -> V_183 ) ;
V_74 -> V_300 = V_74 -> V_93 * sizeof( union V_75 ) ;
V_74 -> V_300 = F_173 ( V_74 -> V_300 , 4096 ) ;
F_439 ( V_80 , V_811 ) ;
V_74 -> V_92 = F_440 ( V_80 ,
V_74 -> V_300 ,
& V_74 -> V_86 ,
V_786 ) ;
F_439 ( V_80 , V_810 ) ;
if ( ! V_74 -> V_92 )
V_74 -> V_92 = F_440 ( V_80 , V_74 -> V_300 ,
& V_74 -> V_86 , V_786 ) ;
if ( ! V_74 -> V_92 )
goto V_17;
V_74 -> V_84 = 0 ;
V_74 -> V_85 = 0 ;
return 0 ;
V_17:
F_441 ( V_74 -> V_78 ) ;
V_74 -> V_78 = NULL ;
F_442 ( V_80 , L_105 ) ;
return - V_595 ;
}
static int F_446 ( struct V_1 * V_2 )
{
int V_49 , V_17 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_98 ; V_49 ++ ) {
V_17 = F_445 ( V_2 -> V_74 [ V_49 ] ) ;
if ( ! V_17 )
continue;
F_106 ( V_186 , L_106 , V_49 ) ;
goto V_814;
}
#ifdef F_181
V_17 = F_447 ( V_2 ) ;
if ( ! V_17 )
#endif
return 0 ;
V_814:
while ( V_49 -- )
F_448 ( V_2 -> V_74 [ V_49 ] ) ;
return V_17 ;
}
void F_444 ( struct V_64 * V_65 )
{
F_410 ( V_65 ) ;
F_441 ( V_65 -> V_83 ) ;
V_65 -> V_83 = NULL ;
if ( ! V_65 -> V_92 )
return;
F_449 ( V_65 -> V_80 , V_65 -> V_300 ,
V_65 -> V_92 , V_65 -> V_86 ) ;
V_65 -> V_92 = NULL ;
}
static void F_450 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_82 ; V_49 ++ )
if ( V_2 -> V_65 [ V_49 ] -> V_92 )
F_444 ( V_2 -> V_65 [ V_49 ] ) ;
}
void F_448 ( struct V_64 * V_74 )
{
F_373 ( V_74 ) ;
F_441 ( V_74 -> V_78 ) ;
V_74 -> V_78 = NULL ;
if ( ! V_74 -> V_92 )
return;
F_449 ( V_74 -> V_80 , V_74 -> V_300 ,
V_74 -> V_92 , V_74 -> V_86 ) ;
V_74 -> V_92 = NULL ;
}
static void F_451 ( struct V_1 * V_2 )
{
int V_49 ;
#ifdef F_181
F_452 ( V_2 ) ;
#endif
for ( V_49 = 0 ; V_49 < V_2 -> V_98 ; V_49 ++ )
if ( V_2 -> V_74 [ V_49 ] -> V_92 )
F_448 ( V_2 -> V_74 [ V_49 ] ) ;
}
static int F_453 ( struct V_61 * V_62 , int V_815 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
if ( ( V_2 -> V_143 & V_436 ) &&
( V_2 -> V_14 . V_113 . type == V_116 ) &&
( V_815 > V_816 ) )
F_27 ( V_186 , L_107 ) ;
F_108 ( V_186 , L_108 , V_62 -> V_312 , V_815 ) ;
V_62 -> V_312 = V_815 ;
if ( F_61 ( V_62 ) )
F_399 ( V_2 ) ;
return 0 ;
}
int F_454 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 , V_380 ;
if ( F_14 ( V_817 , & V_2 -> V_35 ) )
return - V_818 ;
F_417 ( V_62 ) ;
V_17 = F_443 ( V_2 ) ;
if ( V_17 )
goto V_813;
V_17 = F_446 ( V_2 ) ;
if ( V_17 )
goto V_814;
F_387 ( V_2 ) ;
V_17 = F_253 ( V_2 ) ;
if ( V_17 )
goto V_819;
if ( V_2 -> V_687 > 1 )
V_380 = V_2 -> V_678 ;
else
V_380 = V_2 -> V_82 ;
V_17 = F_380 ( V_62 , V_380 ) ;
if ( V_17 )
goto V_820;
if ( V_2 -> V_687 > 1 &&
V_2 -> V_98 > V_821 )
V_380 = V_821 ;
else
V_380 = V_2 -> V_98 ;
V_17 = F_381 ( V_62 , V_380 ) ;
if ( V_17 )
goto V_820;
F_455 ( V_2 ) ;
F_397 ( V_2 ) ;
F_345 ( V_2 , V_822 ) ;
F_456 ( V_62 ) ;
return 0 ;
V_820:
F_254 ( V_2 ) ;
V_819:
F_451 ( V_2 ) ;
if ( V_14 -> V_46 . V_353 . V_718 && ! V_2 -> V_735 )
V_14 -> V_46 . V_353 . V_718 ( & V_2 -> V_14 , false ) ;
V_814:
F_450 ( V_2 ) ;
V_813:
F_407 ( V_2 ) ;
return V_17 ;
}
static void F_457 ( struct V_1 * V_2 )
{
F_458 ( V_2 ) ;
if ( V_2 -> V_14 . V_46 . V_353 . V_823 ) {
V_2 -> V_14 . V_46 . V_824 = true ;
F_404 ( V_2 ) ;
V_2 -> V_14 . V_46 . V_353 . V_823 ( & V_2 -> V_14 ) ;
V_2 -> V_14 . V_46 . V_824 = false ;
} else {
F_404 ( V_2 ) ;
}
F_254 ( V_2 ) ;
F_450 ( V_2 ) ;
F_451 ( V_2 ) ;
}
int F_459 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
F_460 ( V_2 ) ;
if ( F_461 ( V_62 ) )
F_457 ( V_2 ) ;
F_414 ( V_2 ) ;
F_74 ( V_2 ) ;
return 0 ;
}
static int F_462 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_463 ( V_9 ) ;
struct V_61 * V_62 = V_2 -> V_62 ;
T_1 V_17 ;
V_2 -> V_14 . V_41 = V_2 -> V_425 ;
F_464 ( V_9 , V_825 ) ;
F_465 ( V_9 ) ;
F_466 ( V_9 ) ;
V_17 = F_467 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_109 ) ;
return V_17 ;
}
F_36 () ;
F_37 ( V_826 , & V_2 -> V_35 ) ;
F_468 ( V_9 ) ;
F_469 ( V_9 , false ) ;
F_407 ( V_2 ) ;
F_75 ( & V_2 -> V_14 , V_827 , ~ 0 ) ;
F_470 () ;
V_17 = F_471 ( V_2 ) ;
if ( ! V_17 && F_61 ( V_62 ) )
V_17 = F_454 ( V_62 ) ;
if ( ! V_17 )
F_472 ( V_62 ) ;
F_473 () ;
return V_17 ;
}
static int F_474 ( struct V_5 * V_9 , bool * V_828 )
{
struct V_1 * V_2 = F_463 ( V_9 ) ;
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_829 , V_612 ;
T_1 V_830 = V_2 -> V_735 ;
#ifdef F_475
int V_831 = 0 ;
#endif
F_470 () ;
F_476 ( V_62 ) ;
if ( F_61 ( V_62 ) )
F_457 ( V_2 ) ;
F_477 ( V_2 ) ;
F_473 () ;
#ifdef F_475
V_831 = F_466 ( V_9 ) ;
if ( V_831 )
return V_831 ;
#endif
if ( V_14 -> V_113 . V_353 . V_832 )
V_14 -> V_113 . V_353 . V_832 ( V_14 ) ;
if ( V_830 ) {
F_338 ( V_62 ) ;
if ( V_14 -> V_113 . V_353 . V_717 )
V_14 -> V_113 . V_353 . V_717 ( V_14 ) ;
if ( V_830 & V_833 ) {
V_612 = F_40 ( V_14 , V_616 ) ;
V_612 |= V_622 ;
F_75 ( V_14 , V_616 , V_612 ) ;
}
V_829 = F_40 ( V_14 , V_834 ) ;
V_829 |= V_835 ;
F_75 ( V_14 , V_834 , V_829 ) ;
F_75 ( V_14 , V_836 , V_830 ) ;
} else {
F_75 ( V_14 , V_837 , 0 ) ;
F_75 ( V_14 , V_836 , 0 ) ;
}
switch ( V_14 -> V_113 . type ) {
case V_114 :
F_469 ( V_9 , false ) ;
break;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
F_469 ( V_9 , ! ! V_830 ) ;
break;
default:
break;
}
* V_828 = ! ! V_830 ;
if ( V_14 -> V_46 . V_353 . V_718 && ! * V_828 )
V_14 -> V_46 . V_353 . V_718 ( V_14 , false ) ;
F_74 ( V_2 ) ;
if ( ! F_15 ( V_826 , & V_2 -> V_35 ) )
F_478 ( V_9 ) ;
return 0 ;
}
static int F_479 ( struct V_5 * V_9 , T_14 V_35 )
{
int V_831 ;
bool V_838 ;
V_831 = F_474 ( V_9 , & V_838 ) ;
if ( V_831 )
return V_831 ;
if ( V_838 ) {
F_480 ( V_9 ) ;
} else {
F_469 ( V_9 , false ) ;
F_464 ( V_9 , V_839 ) ;
}
return 0 ;
}
static void F_481 ( struct V_5 * V_9 )
{
bool V_838 ;
F_474 ( V_9 , & V_838 ) ;
if ( V_840 == V_841 ) {
F_469 ( V_9 , V_838 ) ;
F_464 ( V_9 , V_839 ) ;
}
}
void F_482 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_126 * V_127 = & V_2 -> V_128 ;
T_6 V_842 = 0 ;
T_1 V_49 , V_843 = 0 , V_844 , V_845 , V_846 , V_847 , V_848 ;
T_6 V_283 = 0 , V_188 = 0 , V_849 = 0 ;
T_6 V_250 = 0 , V_311 = 0 ;
T_6 V_184 = 0 , V_149 = 0 , V_850 = 0 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_724 , & V_2 -> V_35 ) )
return;
if ( V_2 -> V_347 & V_549 ) {
T_6 V_265 = 0 ;
T_6 V_266 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_98 ; V_49 ++ ) {
V_265 += V_2 -> V_74 [ V_49 ] -> V_236 . V_265 ;
V_266 += V_2 -> V_74 [ V_49 ] -> V_236 . V_266 ;
}
V_2 -> V_851 = V_265 ;
V_2 -> V_852 = V_266 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_98 ; V_49 ++ ) {
struct V_64 * V_74 = V_2 -> V_74 [ V_49 ] ;
V_283 += V_74 -> V_236 . V_283 ;
V_250 += V_74 -> V_236 . V_250 ;
V_311 += V_74 -> V_236 . V_311 ;
V_850 += V_74 -> V_236 . V_237 ;
V_184 += V_74 -> V_128 . V_184 ;
V_149 += V_74 -> V_128 . V_149 ;
}
V_2 -> V_283 = V_283 ;
V_2 -> V_250 = V_250 ;
V_2 -> V_311 = V_311 ;
V_2 -> V_850 = V_850 ;
V_62 -> V_128 . V_853 = V_184 ;
V_62 -> V_128 . V_854 = V_149 ;
V_184 = 0 ;
V_149 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_82 ; V_49 ++ ) {
struct V_64 * V_65 = V_2 -> V_65 [ V_49 ] ;
V_188 += V_65 -> V_157 . V_188 ;
V_849 += V_65 -> V_157 . V_849 ;
V_184 += V_65 -> V_128 . V_184 ;
V_149 += V_65 -> V_128 . V_149 ;
}
V_2 -> V_188 = V_188 ;
V_2 -> V_849 = V_849 ;
V_62 -> V_128 . V_855 = V_184 ;
V_62 -> V_128 . V_856 = V_149 ;
V_127 -> V_857 += F_40 ( V_14 , V_858 ) ;
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
V_844 = F_40 ( V_14 , F_483 ( V_49 ) ) ;
V_843 += V_844 ;
V_127 -> V_844 [ V_49 ] += V_844 ;
V_842 += V_127 -> V_844 [ V_49 ] ;
V_127 -> V_859 [ V_49 ] += F_40 ( V_14 , F_484 ( V_49 ) ) ;
V_127 -> V_860 [ V_49 ] += F_40 ( V_14 , F_485 ( V_49 ) ) ;
switch ( V_14 -> V_113 . type ) {
case V_114 :
V_127 -> V_861 [ V_49 ] += F_40 ( V_14 , F_486 ( V_49 ) ) ;
V_127 -> V_862 [ V_49 ] += F_40 ( V_14 , F_487 ( V_49 ) ) ;
V_127 -> V_863 [ V_49 ] += F_40 ( V_14 , F_488 ( V_49 ) ) ;
V_127 -> V_864 [ V_49 ] +=
F_40 ( V_14 , F_489 ( V_49 ) ) ;
break;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_127 -> V_864 [ V_49 ] +=
F_40 ( V_14 , F_490 ( V_49 ) ) ;
break;
default:
break;
}
}
for ( V_49 = 0 ; V_49 < 16 ; V_49 ++ ) {
V_127 -> V_865 [ V_49 ] += F_40 ( V_14 , F_491 ( V_49 ) ) ;
V_127 -> V_866 [ V_49 ] += F_40 ( V_14 , F_492 ( V_49 ) ) ;
if ( ( V_14 -> V_113 . type == V_116 ) ||
( V_14 -> V_113 . type == V_117 ) ||
( V_14 -> V_113 . type == V_118 ) ||
( V_14 -> V_113 . type == V_119 ) ||
( V_14 -> V_113 . type == V_120 ) ) {
V_127 -> V_862 [ V_49 ] += F_40 ( V_14 , F_493 ( V_49 ) ) ;
F_40 ( V_14 , F_494 ( V_49 ) ) ;
V_127 -> V_863 [ V_49 ] += F_40 ( V_14 , F_495 ( V_49 ) ) ;
F_40 ( V_14 , F_496 ( V_49 ) ) ;
}
}
V_127 -> V_867 += F_40 ( V_14 , V_868 ) ;
V_127 -> V_867 -= V_843 ;
F_82 ( V_2 ) ;
switch ( V_14 -> V_113 . type ) {
case V_114 :
V_127 -> V_869 += F_40 ( V_14 , V_870 ) ;
V_127 -> V_871 += F_40 ( V_14 , V_872 ) ;
V_127 -> V_873 += F_40 ( V_14 , V_874 ) ;
V_127 -> V_875 += F_40 ( V_14 , V_876 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_127 -> V_877 += F_40 ( V_14 , V_878 ) ;
V_127 -> V_879 += F_40 ( V_14 , V_880 ) ;
V_127 -> V_881 += F_40 ( V_14 , V_882 ) ;
V_127 -> V_883 += F_40 ( V_14 , V_884 ) ;
case V_116 :
for ( V_49 = 0 ; V_49 < 16 ; V_49 ++ )
V_2 -> V_885 +=
F_40 ( V_14 , F_497 ( V_49 ) ) ;
V_127 -> V_871 += F_40 ( V_14 , V_886 ) ;
F_40 ( V_14 , V_872 ) ;
V_127 -> V_873 += F_40 ( V_14 , V_887 ) ;
F_40 ( V_14 , V_874 ) ;
V_127 -> V_875 += F_40 ( V_14 , V_888 ) ;
F_40 ( V_14 , V_876 ) ;
V_127 -> V_869 += F_40 ( V_14 , V_889 ) ;
V_127 -> V_890 += F_40 ( V_14 , V_891 ) ;
V_127 -> V_892 += F_40 ( V_14 , V_893 ) ;
#ifdef F_181
V_127 -> V_894 += F_40 ( V_14 , V_895 ) ;
V_127 -> V_896 += F_40 ( V_14 , V_897 ) ;
V_127 -> V_898 += F_40 ( V_14 , V_899 ) ;
V_127 -> V_900 += F_40 ( V_14 , V_901 ) ;
V_127 -> V_902 += F_40 ( V_14 , V_903 ) ;
V_127 -> V_904 += F_40 ( V_14 , V_905 ) ;
if ( V_2 -> V_655 . V_906 ) {
struct V_907 * V_655 = & V_2 -> V_655 ;
struct V_908 * V_906 ;
unsigned int V_189 ;
T_6 V_909 = 0 , V_910 = 0 ;
F_498 (cpu) {
V_906 = F_499 ( V_655 -> V_906 , V_189 ) ;
V_909 += V_906 -> V_909 ;
V_910 += V_906 -> V_910 ;
}
V_127 -> V_911 = V_909 ;
V_127 -> V_912 = V_910 ;
}
#endif
break;
default:
break;
}
V_845 = F_40 ( V_14 , V_913 ) ;
V_127 -> V_845 += V_845 ;
V_127 -> V_914 += F_40 ( V_14 , V_915 ) ;
if ( V_14 -> V_113 . type == V_114 )
V_127 -> V_914 -= V_845 ;
V_127 -> V_916 += F_40 ( V_14 , V_917 ) ;
V_127 -> V_918 += F_40 ( V_14 , V_919 ) ;
V_127 -> V_920 += F_40 ( V_14 , V_921 ) ;
V_127 -> V_922 += F_40 ( V_14 , V_923 ) ;
V_127 -> V_924 += F_40 ( V_14 , V_925 ) ;
V_127 -> V_926 += F_40 ( V_14 , V_927 ) ;
V_127 -> V_928 += F_40 ( V_14 , V_929 ) ;
V_127 -> V_930 += F_40 ( V_14 , V_931 ) ;
V_846 = F_40 ( V_14 , V_932 ) ;
V_127 -> V_933 += V_846 ;
V_847 = F_40 ( V_14 , V_934 ) ;
V_127 -> V_935 += V_847 ;
V_127 -> V_936 += F_40 ( V_14 , V_937 ) ;
V_127 -> V_938 += F_40 ( V_14 , V_939 ) ;
V_848 = V_846 + V_847 ;
V_127 -> V_936 -= V_848 ;
V_127 -> V_938 -= V_848 ;
V_127 -> V_873 -= ( V_848 * ( V_940 + V_537 ) ) ;
V_127 -> V_941 += F_40 ( V_14 , V_942 ) ;
V_127 -> V_943 += F_40 ( V_14 , V_944 ) ;
V_127 -> V_945 += F_40 ( V_14 , V_946 ) ;
V_127 -> V_947 += F_40 ( V_14 , V_948 ) ;
V_127 -> V_949 += F_40 ( V_14 , V_950 ) ;
V_127 -> V_949 -= V_848 ;
V_127 -> V_951 += F_40 ( V_14 , V_952 ) ;
V_127 -> V_953 += F_40 ( V_14 , V_954 ) ;
V_127 -> V_955 += F_40 ( V_14 , V_956 ) ;
V_127 -> V_957 += F_40 ( V_14 , V_958 ) ;
V_127 -> V_959 += F_40 ( V_14 , V_960 ) ;
V_127 -> V_961 += F_40 ( V_14 , V_962 ) ;
V_62 -> V_128 . V_963 = V_127 -> V_914 ;
V_62 -> V_128 . V_964 = V_127 -> V_857 + V_127 -> V_930 ;
V_62 -> V_128 . V_965 = 0 ;
V_62 -> V_128 . V_966 = V_127 -> V_930 ;
V_62 -> V_128 . V_967 = V_127 -> V_857 ;
V_62 -> V_128 . V_968 = V_842 ;
}
static void F_500 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( ! ( V_2 -> V_347 & V_389 ) )
return;
V_2 -> V_347 &= ~ V_389 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
if ( ! ( V_2 -> V_143 & V_388 ) )
return;
V_2 -> V_969 ++ ;
if ( F_501 ( V_14 ) == 0 ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_82 ; V_49 ++ )
F_92 ( V_398 ,
& ( V_2 -> V_65 [ V_49 ] -> V_35 ) ) ;
F_75 ( V_14 , V_379 , V_390 ) ;
} else {
F_106 ( V_186 , L_110
L_111 ) ;
}
}
static void F_502 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_970 = 0 ;
int V_49 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_724 , & V_2 -> V_35 ) )
return;
if ( F_112 ( V_2 -> V_62 ) ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_82 ; V_49 ++ )
F_503 ( V_2 -> V_65 [ V_49 ] ) ;
}
if ( ! ( V_2 -> V_143 & V_416 ) ) {
F_75 ( V_14 , V_125 ,
( V_971 | V_972 ) ) ;
} else {
for ( V_49 = 0 ; V_49 < V_2 -> V_206 ; V_49 ++ ) {
struct V_169 * V_973 = V_2 -> V_170 [ V_49 ] ;
if ( V_973 -> V_316 . V_148 || V_973 -> V_175 . V_148 )
V_970 |= F_244 ( V_49 ) ;
}
}
F_79 ( V_2 , V_970 ) ;
}
static void F_504 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_974 = V_2 -> V_974 ;
bool V_355 = V_2 -> V_355 ;
bool V_139 = V_2 -> V_140 . V_141 ;
if ( ! ( V_2 -> V_143 & V_376 ) )
return;
if ( V_14 -> V_113 . V_353 . V_354 ) {
V_14 -> V_113 . V_353 . V_354 ( V_14 , & V_974 , & V_355 , false ) ;
} else {
V_974 = V_975 ;
V_355 = true ;
}
if ( V_2 -> V_142 )
V_139 |= ! ! ( V_2 -> V_142 -> V_139 ) ;
if ( V_355 && ! ( ( V_2 -> V_143 & V_144 ) && V_139 ) ) {
V_14 -> V_113 . V_353 . V_976 ( V_14 ) ;
F_505 ( V_2 ) ;
}
if ( V_355 ||
F_506 ( V_185 , ( V_2 -> V_377 +
V_977 ) ) ) {
V_2 -> V_143 &= ~ V_376 ;
F_75 ( V_14 , V_379 , V_378 ) ;
F_225 ( V_14 ) ;
}
V_2 -> V_355 = V_355 ;
V_2 -> V_974 = V_974 ;
}
static void F_507 ( struct V_1 * V_2 )
{
#ifdef F_388
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_978 V_979 = {
. V_980 = V_981 ,
. V_273 = 0 ,
} ;
T_4 V_656 = 0 ;
if ( V_2 -> V_641 & V_982 )
V_656 = F_508 ( V_62 , & V_979 ) ;
V_2 -> V_983 = ( V_656 > 1 ) ? ( F_509 ( V_656 ) - 1 ) : 0 ;
#endif
}
static int F_510 ( struct V_61 * V_100 , void * V_97 )
{
if ( F_384 ( V_100 ) ) {
struct V_690 * V_271 = F_88 ( V_100 ) ;
if ( V_271 -> V_692 )
F_511 ( V_100 ) ;
}
return 0 ;
}
static void F_512 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_974 = V_2 -> V_974 ;
const char * V_984 ;
bool V_985 , V_986 ;
if ( F_112 ( V_62 ) )
return;
V_2 -> V_347 &= ~ V_695 ;
switch ( V_14 -> V_113 . type ) {
case V_114 : {
T_1 V_987 = F_40 ( V_14 , V_616 ) ;
T_1 V_988 = F_40 ( V_14 , V_989 ) ;
V_985 = ! ! ( V_987 & V_990 ) ;
V_986 = ! ! ( V_988 & V_991 ) ;
}
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_116 : {
T_1 V_992 = F_40 ( V_14 , V_993 ) ;
T_1 V_994 = F_40 ( V_14 , V_995 ) ;
V_985 = ! ! ( V_992 & V_996 ) ;
V_986 = ! ! ( V_994 & V_997 ) ;
}
break;
default:
V_986 = false ;
V_985 = false ;
break;
}
V_2 -> V_998 = V_185 ;
if ( F_14 ( V_734 , & V_2 -> V_35 ) )
F_513 ( V_2 ) ;
switch ( V_974 ) {
case V_975 :
V_984 = L_112 ;
break;
case V_999 :
V_984 = L_113 ;
break;
case V_1000 :
V_984 = L_114 ;
break;
case V_1001 :
V_984 = L_115 ;
break;
case V_1002 :
V_984 = L_116 ;
break;
default:
V_984 = L_117 ;
break;
}
F_108 ( V_160 , L_118 , V_984 ,
( ( V_985 && V_986 ) ? L_119 :
( V_985 ? L_120 :
( V_986 ? L_121 : L_122 ) ) ) ) ;
F_514 ( V_62 ) ;
F_515 ( V_2 ) ;
F_511 ( V_2 -> V_62 ) ;
F_470 () ;
F_386 ( V_2 -> V_62 ,
F_510 , NULL ) ;
F_473 () ;
F_507 ( V_2 ) ;
F_420 ( V_2 ) ;
}
static void F_403 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_355 = false ;
V_2 -> V_974 = 0 ;
if ( ! F_112 ( V_62 ) )
return;
if ( F_221 ( V_14 ) && V_14 -> V_113 . type == V_114 )
V_2 -> V_347 |= V_695 ;
if ( F_14 ( V_734 , & V_2 -> V_35 ) )
F_513 ( V_2 ) ;
F_108 ( V_160 , L_123 ) ;
F_417 ( V_62 ) ;
F_420 ( V_2 ) ;
}
static bool F_516 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_82 ; V_49 ++ ) {
struct V_64 * V_65 = V_2 -> V_65 [ V_49 ] ;
if ( V_65 -> V_85 != V_65 -> V_84 )
return true ;
}
return false ;
}
static bool F_517 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1003 * V_1004 = & V_2 -> V_441 [ V_442 ] ;
T_1 V_1005 = F_518 ( 1 , ~ V_1004 -> V_123 ) ;
int V_49 , V_56 ;
if ( ! V_2 -> V_318 )
return false ;
if ( V_14 -> V_113 . type >= V_118 )
return false ;
for ( V_49 = 0 ; V_49 < V_2 -> V_318 ; V_49 ++ ) {
for ( V_56 = 0 ; V_56 < V_1005 ; V_56 ++ ) {
T_1 V_1006 , V_1007 ;
V_1006 = F_40 ( V_14 , F_519 ( V_1005 , V_49 , V_56 ) ) ;
V_1007 = F_40 ( V_14 , F_520 ( V_1005 , V_49 , V_56 ) ) ;
if ( V_1006 != V_1007 )
return true ;
}
}
return false ;
}
static void F_521 ( struct V_1 * V_2 )
{
if ( ! F_112 ( V_2 -> V_62 ) ) {
if ( F_516 ( V_2 ) ||
F_517 ( V_2 ) ) {
F_27 ( V_160 , L_124 ) ;
F_92 ( V_159 , & V_2 -> V_35 ) ;
}
}
}
static inline void F_522 ( struct V_1 * V_2 ,
struct V_5 * V_1008 )
{
if ( ! F_523 ( V_1008 ) )
F_11 ( L_125 ) ;
F_18 ( L_126 , F_524 ( V_1008 ) ) ;
F_525 ( V_1008 , V_1009 , V_1010 ) ;
F_405 ( 100 ) ;
}
static void F_526 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_1011 ;
T_1 V_1012 ;
if ( ! ( F_112 ( V_2 -> V_62 ) ) )
return;
V_1012 = F_40 ( V_14 , V_1013 ) ;
if ( V_1012 )
return;
if ( ! V_9 )
return;
for ( V_1011 = 0 ; V_1011 < V_2 -> V_318 ; ++ V_1011 ) {
struct V_5 * V_1008 = V_2 -> V_532 [ V_1011 ] . V_1008 ;
T_2 V_1014 ;
if ( ! V_1008 )
continue;
F_28 ( V_1008 , V_1015 , & V_1014 ) ;
if ( V_1014 != V_13 &&
V_1014 & V_1016 )
F_522 ( V_2 , V_1008 ) ;
}
}
static void F_527 ( struct V_1 * V_2 )
{
T_1 V_1017 ;
if ( V_2 -> V_14 . V_113 . type == V_114 ||
V_2 -> V_318 == 0 )
return;
V_1017 = F_40 ( & V_2 -> V_14 , V_1018 ) ;
if ( ! V_1017 )
return;
F_27 ( V_160 , L_127 , V_1017 ) ;
}
static void F_527 ( struct V_1 T_15 * V_2 )
{
}
static void
F_526 ( struct V_1 T_15 * V_2 )
{
}
static void F_528 ( struct V_1 * V_2 )
{
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_724 , & V_2 -> V_35 ) )
return;
F_504 ( V_2 ) ;
if ( V_2 -> V_355 )
F_512 ( V_2 ) ;
else
F_403 ( V_2 ) ;
F_526 ( V_2 ) ;
F_527 ( V_2 ) ;
F_482 ( V_2 ) ;
F_521 ( V_2 ) ;
}
static void F_529 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_3 V_17 ;
if ( ! ( V_2 -> V_347 & V_695 ) &&
! ( V_2 -> V_347 & V_372 ) )
return;
if ( V_2 -> V_373 &&
F_506 ( V_2 -> V_373 , V_185 ) )
return;
if ( F_15 ( V_726 , & V_2 -> V_35 ) )
return;
V_2 -> V_373 = V_185 + V_1019 - 1 ;
V_17 = V_14 -> V_46 . V_353 . V_1020 ( V_14 ) ;
if ( V_17 == V_729 )
goto V_1021;
if ( V_17 == V_728 ) {
V_2 -> V_347 |= V_372 ;
}
if ( V_17 )
goto V_1021;
if ( ! ( V_2 -> V_347 & V_372 ) )
goto V_1021;
V_2 -> V_347 &= ~ V_372 ;
if ( V_14 -> V_113 . type == V_114 )
V_17 = V_14 -> V_46 . V_353 . V_1022 ( V_14 ) ;
else
V_17 = V_14 -> V_113 . V_353 . V_1023 ( V_14 ) ;
if ( V_17 == V_729 )
goto V_1021;
V_2 -> V_143 |= V_374 ;
F_108 ( V_186 , L_128 , V_14 -> V_46 . V_1024 ) ;
V_1021:
F_37 ( V_726 , & V_2 -> V_35 ) ;
if ( ( V_17 == V_729 ) &&
( V_2 -> V_62 -> V_1025 == V_1026 ) ) {
F_18 ( L_129
L_130 ) ;
F_18 ( L_131
L_132 ) ;
F_530 ( V_2 -> V_62 ) ;
}
}
static void F_531 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_20 ;
bool V_696 = false ;
if ( ! ( V_2 -> V_143 & V_374 ) )
return;
if ( F_15 ( V_726 , & V_2 -> V_35 ) )
return;
V_2 -> V_143 &= ~ V_374 ;
V_20 = V_14 -> V_46 . V_698 ;
if ( ( ! V_20 ) && ( V_14 -> V_113 . V_353 . V_699 ) ) {
V_14 -> V_113 . V_353 . V_699 ( V_14 , & V_20 , & V_696 ) ;
if ( ! V_696 ) {
if ( V_20 & V_975 )
V_20 = V_975 ;
}
}
if ( V_14 -> V_113 . V_353 . V_700 )
V_14 -> V_113 . V_353 . V_700 ( V_14 , V_20 , true ) ;
V_2 -> V_143 |= V_376 ;
V_2 -> V_377 = V_185 ;
F_37 ( V_726 , & V_2 -> V_35 ) ;
}
static void F_532 ( unsigned long V_97 )
{
struct V_1 * V_2 = (struct V_1 * ) V_97 ;
unsigned long V_1027 ;
if ( V_2 -> V_143 & V_376 )
V_1027 = V_1028 / 10 ;
else
V_1027 = V_1028 * 2 ;
F_398 ( & V_2 -> V_722 , V_1027 + V_185 ) ;
F_13 ( V_2 ) ;
}
static void F_533 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_178 ;
if ( ! ( V_2 -> V_347 & V_393 ) )
return;
V_2 -> V_347 &= ~ V_393 ;
if ( ! V_14 -> V_46 . V_353 . V_1029 )
return;
V_178 = V_14 -> V_46 . V_353 . V_1029 ( & V_2 -> V_14 ) ;
if ( V_178 != V_357 )
return;
F_217 ( V_160 , L_71 , V_360 ) ;
}
static void F_534 ( struct V_1 * V_2 )
{
if ( ! F_236 ( V_159 , & V_2 -> V_35 ) )
return;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_724 , & V_2 -> V_35 ) )
return;
F_57 ( V_2 ) ;
F_535 ( V_2 -> V_62 , L_133 ) ;
V_2 -> V_187 ++ ;
F_470 () ;
F_399 ( V_2 ) ;
F_473 () ;
}
static void F_536 ( struct V_1030 * V_1031 )
{
struct V_1 * V_2 = F_241 ( V_1031 ,
struct V_1 ,
V_39 ) ;
if ( F_22 ( V_2 -> V_14 . V_41 ) ) {
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_470 () ;
F_404 ( V_2 ) ;
F_473 () ;
}
F_34 ( V_2 ) ;
return;
}
if ( V_2 -> V_347 & V_1032 ) {
F_470 () ;
V_2 -> V_347 &= ~ V_1032 ;
F_456 ( V_2 -> V_62 ) ;
F_473 () ;
}
F_534 ( V_2 ) ;
F_533 ( V_2 ) ;
F_529 ( V_2 ) ;
F_531 ( V_2 ) ;
F_215 ( V_2 ) ;
F_528 ( V_2 ) ;
F_500 ( V_2 ) ;
F_502 ( V_2 ) ;
if ( F_14 ( V_734 , & V_2 -> V_35 ) ) {
F_537 ( V_2 ) ;
F_538 ( V_2 ) ;
}
F_34 ( V_2 ) ;
}
static int F_539 ( struct V_64 * V_65 ,
struct V_66 * V_1033 ,
T_4 * V_260 )
{
T_1 V_1034 , V_1035 , V_1036 ;
struct V_212 * V_94 = V_1033 -> V_94 ;
union {
struct V_1037 * V_1038 ;
struct V_1039 * V_1040 ;
unsigned char * V_1041 ;
} V_1042 ;
union {
struct V_1043 * V_1044 ;
unsigned char * V_1041 ;
} V_1045 ;
T_1 V_1046 , V_1047 ;
int V_17 ;
if ( V_94 -> V_242 != V_1048 )
return 0 ;
if ( ! F_540 ( V_94 ) )
return 0 ;
V_17 = F_541 ( V_94 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_1042 . V_1041 = F_542 ( V_94 ) ;
V_1045 . V_1041 = F_543 ( V_94 ) ;
V_1035 = V_1049 ;
if ( V_1042 . V_1038 -> V_1050 == 4 ) {
unsigned char * V_1051 = F_543 ( V_94 ) ;
unsigned char * V_1052 = V_1042 . V_1041 + ( V_1042 . V_1038 -> V_1053 * 4 ) ;
V_1042 . V_1038 -> V_1054 = F_544 ( F_545 ( V_1052 ,
V_1051 - V_1052 ,
0 ) ) ;
V_1035 |= V_1055 ;
V_1042 . V_1038 -> V_1056 = 0 ;
V_1033 -> V_1057 |= V_1058 |
V_1059 |
V_1060 ;
} else {
V_1042 . V_1040 -> V_1061 = 0 ;
V_1033 -> V_1057 |= V_1058 |
V_1059 ;
}
V_1047 = V_1045 . V_1041 - V_94 -> V_97 ;
* V_260 = ( V_1045 . V_1044 -> V_1062 * 4 ) + V_1047 ;
V_1046 = V_94 -> V_87 - V_1047 ;
F_546 ( & V_1045 . V_1044 -> V_1054 , F_547 ( V_1046 ) ) ;
V_1033 -> V_181 = F_155 ( V_94 ) -> V_181 ;
V_1033 -> V_180 += ( V_1033 -> V_181 - 1 ) * * V_260 ;
V_1036 = ( * V_260 - V_1047 ) << V_1063 ;
V_1036 |= F_155 ( V_94 ) -> V_261 << V_1064 ;
V_1034 = V_1045 . V_1041 - V_1042 . V_1041 ;
V_1034 |= ( V_1042 . V_1041 - V_94 -> V_97 ) << V_1065 ;
V_1034 |= V_1033 -> V_1057 & V_1066 ;
F_548 ( V_65 , V_1034 , 0 , V_1035 ,
V_1036 ) ;
return 1 ;
}
static inline bool F_549 ( struct V_212 * V_94 )
{
unsigned int V_1067 = 0 ;
F_550 ( V_94 , & V_1067 , V_1068 , NULL , NULL ) ;
return V_1067 == F_551 ( V_94 ) ;
}
static void F_552 ( struct V_64 * V_65 ,
struct V_66 * V_1033 )
{
struct V_212 * V_94 = V_1033 -> V_94 ;
T_1 V_1034 = 0 ;
T_1 V_1035 = 0 ;
if ( V_94 -> V_242 != V_1048 ) {
V_1069:
if ( ! ( V_1033 -> V_1057 & ( V_1070 |
V_1071 ) ) )
return;
goto V_1072;
}
switch ( V_94 -> V_1073 ) {
case F_553 ( struct V_1043 , V_1054 ) :
V_1035 = V_1049 ;
case F_553 ( struct V_1074 , V_1054 ) :
break;
case F_553 ( struct V_1075 , V_1076 ) :
if ( ( ( V_1033 -> V_273 == F_162 ( V_1077 ) ) &&
( F_554 ( V_94 ) -> V_273 == V_1068 ) ) ||
( ( V_1033 -> V_273 == F_162 ( V_1078 ) ) &&
F_549 ( V_94 ) ) ) {
V_1035 = V_1079 ;
break;
}
default:
F_555 ( V_94 ) ;
goto V_1069;
}
V_1033 -> V_1057 |= V_1059 ;
V_1034 = F_551 ( V_94 ) -
F_556 ( V_94 ) ;
V_1072:
V_1034 |= F_556 ( V_94 ) << V_1065 ;
V_1034 |= V_1033 -> V_1057 & V_1066 ;
F_548 ( V_65 , V_1034 , 0 , V_1035 , 0 ) ;
}
static T_1 F_557 ( struct V_212 * V_94 , T_1 V_1057 )
{
T_1 V_1080 = V_1081 |
V_1082 |
V_1083 ;
V_1080 |= F_558 ( V_1057 , V_1070 ,
V_1084 ) ;
V_1080 |= F_558 ( V_1057 , V_1058 ,
V_1085 ) ;
V_1080 |= F_558 ( V_1057 , V_1086 ,
V_1087 ) ;
V_1080 ^= F_558 ( V_94 -> V_1088 , 1 , V_1083 ) ;
return V_1080 ;
}
static void F_559 ( union V_68 * V_69 ,
T_1 V_1057 , unsigned int V_1046 )
{
T_1 V_1089 = V_1046 << V_1090 ;
V_1089 |= F_558 ( V_1057 ,
V_1059 ,
V_1091 ) ;
V_1089 |= F_558 ( V_1057 ,
V_1060 ,
V_1092 ) ;
V_1089 |= F_558 ( V_1057 ,
V_1071 ,
V_1093 ) ;
V_69 -> V_256 . V_1089 = F_97 ( V_1089 ) ;
}
static int F_560 ( struct V_64 * V_65 , T_2 V_300 )
{
F_107 ( V_65 -> V_62 , V_65 -> V_91 ) ;
F_114 () ;
if ( F_25 ( F_113 ( V_65 ) < V_300 ) )
return - V_818 ;
F_561 ( V_65 -> V_62 , V_65 -> V_91 ) ;
++ V_65 -> V_157 . V_188 ;
return 0 ;
}
static inline int F_562 ( struct V_64 * V_65 , T_2 V_300 )
{
if ( F_25 ( F_113 ( V_65 ) >= V_300 ) )
return 0 ;
return F_560 ( V_65 , V_300 ) ;
}
static void F_563 ( struct V_64 * V_65 ,
struct V_66 * V_1033 ,
const T_4 V_260 )
{
struct V_212 * V_94 = V_1033 -> V_94 ;
struct V_66 * V_67 ;
union V_68 * V_69 ;
struct V_284 * V_285 ;
T_9 V_86 ;
unsigned int V_290 , V_300 ;
T_1 V_1057 = V_1033 -> V_1057 ;
T_1 V_1080 = F_557 ( V_94 , V_1057 ) ;
T_2 V_49 = V_65 -> V_85 ;
V_69 = F_65 ( V_65 , V_49 ) ;
F_559 ( V_69 , V_1057 , V_94 -> V_87 - V_260 ) ;
V_300 = F_154 ( V_94 ) ;
V_290 = V_94 -> V_290 ;
#ifdef F_181
if ( V_1057 & V_1094 ) {
if ( V_290 < sizeof( struct V_315 ) ) {
V_300 -= sizeof( struct V_315 ) - V_290 ;
V_290 = 0 ;
} else {
V_290 -= sizeof( struct V_315 ) ;
}
}
#endif
V_86 = F_564 ( V_65 -> V_80 , V_94 -> V_97 , V_300 , V_182 ) ;
V_67 = V_1033 ;
for ( V_285 = & F_155 ( V_94 ) -> V_286 [ 0 ] ; ; V_285 ++ ) {
if ( F_146 ( V_65 -> V_80 , V_86 ) )
goto V_1095;
F_100 ( V_67 , V_87 , V_300 ) ;
F_565 ( V_67 , V_86 , V_86 ) ;
V_69 -> V_256 . V_1096 = F_150 ( V_86 ) ;
while ( F_23 ( V_300 > V_1097 ) ) {
V_69 -> V_256 . V_1098 =
F_97 ( V_1080 ^ V_1097 ) ;
V_49 ++ ;
V_69 ++ ;
if ( V_49 == V_65 -> V_93 ) {
V_69 = F_65 ( V_65 , 0 ) ;
V_49 = 0 ;
}
V_69 -> V_256 . V_1089 = 0 ;
V_86 += V_1097 ;
V_300 -= V_1097 ;
V_69 -> V_256 . V_1096 = F_150 ( V_86 ) ;
}
if ( F_25 ( ! V_290 ) )
break;
V_69 -> V_256 . V_1098 = F_97 ( V_1080 ^ V_300 ) ;
V_49 ++ ;
V_69 ++ ;
if ( V_49 == V_65 -> V_93 ) {
V_69 = F_65 ( V_65 , 0 ) ;
V_49 = 0 ;
}
V_69 -> V_256 . V_1089 = 0 ;
#ifdef F_181
V_300 = F_336 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_300 = F_178 ( V_285 ) ;
#endif
V_290 -= V_300 ;
V_86 = F_566 ( V_65 -> V_80 , V_285 , 0 , V_300 ,
V_182 ) ;
V_67 = & V_65 -> V_83 [ V_49 ] ;
}
V_1080 |= V_300 | V_1099 ;
V_69 -> V_256 . V_1098 = F_97 ( V_1080 ) ;
F_567 ( F_110 ( V_65 ) , V_1033 -> V_180 ) ;
V_1033 -> V_89 = V_185 ;
F_151 () ;
V_1033 -> V_88 = V_69 ;
V_49 ++ ;
if ( V_49 == V_65 -> V_93 )
V_49 = 0 ;
V_65 -> V_85 = V_49 ;
F_562 ( V_65 , V_1100 ) ;
if ( F_568 ( F_110 ( V_65 ) ) || ! V_94 -> V_1101 ) {
F_152 ( V_49 , V_65 -> V_151 ) ;
F_569 () ;
}
return;
V_1095:
F_442 ( V_65 -> V_80 , L_134 ) ;
V_67 = & V_65 -> V_83 [ V_49 ] ;
while ( V_67 != V_1033 ) {
if ( F_63 ( V_67 , V_87 ) )
F_101 ( V_65 -> V_80 ,
F_62 ( V_67 , V_86 ) ,
F_63 ( V_67 , V_87 ) ,
V_182 ) ;
F_100 ( V_67 , V_87 , 0 ) ;
if ( V_49 -- )
V_49 += V_65 -> V_93 ;
V_67 = & V_65 -> V_83 [ V_49 ] ;
}
if ( F_63 ( V_67 , V_87 ) )
F_99 ( V_65 -> V_80 ,
F_62 ( V_67 , V_86 ) ,
F_63 ( V_67 , V_87 ) ,
V_182 ) ;
F_100 ( V_67 , V_87 , 0 ) ;
F_180 ( V_1033 -> V_94 ) ;
V_1033 -> V_94 = NULL ;
V_65 -> V_85 = V_49 ;
}
static void F_570 ( struct V_64 * V_148 ,
struct V_66 * V_1033 )
{
struct V_169 * V_170 = V_148 -> V_170 ;
union V_1102 V_1103 = { . V_1104 = 0 } ;
union V_1102 V_1105 = { . V_1104 = 0 } ;
union {
unsigned char * V_1106 ;
struct V_1037 * V_1107 ;
struct V_1039 * V_1108 ;
} V_1041 ;
struct V_1043 * V_1109 ;
unsigned int V_1110 ;
struct V_212 * V_94 ;
T_12 V_1111 ;
int V_1112 ;
if ( ! V_170 )
return;
if ( ! V_148 -> V_426 )
return;
V_148 -> V_427 ++ ;
if ( ( V_1033 -> V_273 != F_162 ( V_1077 ) ) &&
( V_1033 -> V_273 != F_162 ( V_1078 ) ) )
return;
V_94 = V_1033 -> V_94 ;
V_1041 . V_1106 = F_542 ( V_94 ) ;
if ( F_23 ( V_1041 . V_1106 <= V_94 -> V_97 ) )
return;
if ( V_94 -> V_233 &&
V_1033 -> V_273 == F_162 ( V_1077 ) &&
V_1041 . V_1107 -> V_273 == V_1113 ) {
struct V_1 * V_2 = V_170 -> V_2 ;
if ( F_23 ( F_571 ( V_94 ) < V_1041 . V_1106 +
V_1114 ) )
return;
if ( V_2 -> V_637 &&
F_572 ( V_94 ) -> V_1115 == V_2 -> V_637 )
V_1041 . V_1106 = F_573 ( V_94 ) ;
if ( V_2 -> V_639 &&
F_572 ( V_94 ) -> V_1115 == V_2 -> V_639 )
V_1041 . V_1106 = F_573 ( V_94 ) ;
}
if ( F_23 ( F_571 ( V_94 ) < V_1041 . V_1106 + 40 ) )
return;
switch ( V_1041 . V_1107 -> V_1050 ) {
case V_1116 :
V_1110 = ( V_1041 . V_1106 [ 0 ] & 0x0F ) << 2 ;
V_1112 = V_1041 . V_1107 -> V_273 ;
break;
case 6 :
V_1110 = V_1041 . V_1106 - V_94 -> V_97 ;
V_1112 = F_550 ( V_94 , & V_1110 , V_1117 , NULL , NULL ) ;
V_1110 -= V_1041 . V_1106 - V_94 -> V_97 ;
break;
default:
return;
}
if ( V_1112 != V_1117 )
return;
if ( F_23 ( F_571 ( V_94 ) < V_1041 . V_1106 +
V_1110 + sizeof( struct V_1043 ) ) )
return;
V_1109 = (struct V_1043 * ) ( V_1041 . V_1106 + V_1110 ) ;
if ( V_1109 -> V_1118 )
return;
if ( ! V_1109 -> V_1119 && ( V_148 -> V_427 < V_148 -> V_426 ) )
return;
V_148 -> V_427 = 0 ;
V_1111 = F_162 ( V_1033 -> V_1057 >> V_1120 ) ;
V_1103 . V_1121 . V_1111 = V_1111 ;
if ( V_1033 -> V_1057 & ( V_1122 | V_1070 ) )
V_1105 . V_1123 . V_1124 ^= V_1109 -> V_1115 ^ F_162 ( V_272 ) ;
else
V_1105 . V_1123 . V_1124 ^= V_1109 -> V_1115 ^ V_1033 -> V_273 ;
V_1105 . V_1123 . V_1125 ^= V_1109 -> V_1126 ;
switch ( V_1041 . V_1107 -> V_1050 ) {
case V_1116 :
V_1103 . V_1121 . V_1127 = V_1128 ;
V_1105 . V_1042 ^= V_1041 . V_1107 -> V_1129 ^ V_1041 . V_1107 -> V_1130 ;
break;
case 6 :
V_1103 . V_1121 . V_1127 = V_1131 ;
V_1105 . V_1042 ^= V_1041 . V_1108 -> V_1129 . V_1132 [ 0 ] ^
V_1041 . V_1108 -> V_1129 . V_1132 [ 1 ] ^
V_1041 . V_1108 -> V_1129 . V_1132 [ 2 ] ^
V_1041 . V_1108 -> V_1129 . V_1132 [ 3 ] ^
V_1041 . V_1108 -> V_1130 . V_1132 [ 0 ] ^
V_1041 . V_1108 -> V_1130 . V_1132 [ 1 ] ^
V_1041 . V_1108 -> V_1130 . V_1132 [ 2 ] ^
V_1041 . V_1108 -> V_1130 . V_1132 [ 3 ] ;
break;
default:
break;
}
if ( V_1041 . V_1106 != F_542 ( V_94 ) )
V_1103 . V_1121 . V_1127 |= V_1133 ;
F_574 ( & V_170 -> V_2 -> V_14 ,
V_1103 , V_1105 , V_148 -> V_91 ) ;
}
static T_2 F_575 ( struct V_61 * V_80 , struct V_212 * V_94 ,
void * V_1134 , T_16 V_1135 )
{
struct V_676 * V_1136 = V_1134 ;
#ifdef F_181
struct V_1 * V_2 ;
struct V_1003 * V_1137 ;
int V_1138 ;
#endif
if ( V_1136 )
return V_94 -> V_1139 + V_1136 -> V_684 ;
#ifdef F_181
switch ( F_576 ( V_94 ) ) {
case F_162 ( V_1140 ) :
case F_162 ( V_1141 ) :
V_2 = F_88 ( V_80 ) ;
if ( V_2 -> V_143 & V_540 )
break;
default:
return V_1135 ( V_80 , V_94 ) ;
}
V_1137 = & V_2 -> V_441 [ V_1142 ] ;
V_1138 = F_577 ( V_94 ) ? F_578 ( V_94 ) :
F_579 () ;
while ( V_1138 >= V_1137 -> V_472 )
V_1138 -= V_1137 -> V_472 ;
return V_1138 + V_1137 -> V_1067 ;
#else
return V_1135 ( V_80 , V_94 ) ;
#endif
}
T_17 F_580 ( struct V_212 * V_94 ,
struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_66 * V_1033 ;
int V_1143 ;
T_1 V_1057 = 0 ;
unsigned short V_1137 ;
T_2 V_93 = F_581 ( F_154 ( V_94 ) ) ;
T_12 V_273 = V_94 -> V_273 ;
T_4 V_260 = 0 ;
for ( V_1137 = 0 ; V_1137 < F_155 ( V_94 ) -> V_302 ; V_1137 ++ )
V_93 += F_581 ( F_155 ( V_94 ) -> V_286 [ V_1137 ] . V_300 ) ;
if ( F_562 ( V_65 , V_93 + 3 ) ) {
V_65 -> V_157 . V_849 ++ ;
return V_1144 ;
}
V_1033 = & V_65 -> V_83 [ V_65 -> V_85 ] ;
V_1033 -> V_94 = V_94 ;
V_1033 -> V_180 = V_94 -> V_87 ;
V_1033 -> V_181 = 1 ;
if ( F_582 ( V_94 ) ) {
V_1057 |= F_583 ( V_94 ) << V_1120 ;
V_1057 |= V_1070 ;
} else if ( V_273 == F_162 ( V_272 ) ) {
struct V_1145 * V_1146 , V_1147 ;
V_1146 = F_584 ( V_94 , V_536 , sizeof( V_1147 ) , & V_1147 ) ;
if ( ! V_1146 )
goto V_1148;
V_1057 |= F_585 ( V_1146 -> V_1149 ) <<
V_1120 ;
V_1057 |= V_1122 ;
}
V_273 = F_576 ( V_94 ) ;
if ( F_23 ( F_155 ( V_94 ) -> V_1057 & V_1150 ) &&
V_2 -> V_1151 &&
! F_586 ( V_1152 ,
& V_2 -> V_35 ) ) {
F_155 ( V_94 ) -> V_1057 |= V_1153 ;
V_1057 |= V_1086 ;
V_2 -> V_1154 = F_587 ( V_94 ) ;
V_2 -> V_1155 = V_185 ;
F_588 ( & V_2 -> V_1156 ) ;
}
F_589 ( V_94 ) ;
#ifdef F_318
if ( V_2 -> V_143 & V_436 )
V_1057 |= V_1071 ;
#endif
if ( ( V_2 -> V_143 & V_144 ) &&
( ( V_1057 & ( V_1070 | V_1122 ) ) ||
( V_94 -> V_1157 != V_1158 ) ) ) {
V_1057 &= ~ V_1159 ;
V_1057 |= ( V_94 -> V_1157 & 0x7 ) <<
V_1160 ;
if ( V_1057 & V_1122 ) {
struct V_1161 * V_1146 ;
if ( F_541 ( V_94 , 0 ) )
goto V_1148;
V_1146 = (struct V_1161 * ) V_94 -> V_97 ;
V_1146 -> V_1149 = F_162 ( V_1057 >>
V_1120 ) ;
} else {
V_1057 |= V_1070 ;
}
}
V_1033 -> V_1057 = V_1057 ;
V_1033 -> V_273 = V_273 ;
#ifdef F_181
if ( ( V_273 == F_162 ( V_1140 ) ) &&
( V_65 -> V_62 -> V_214 & ( V_1162 | V_1163 ) ) ) {
V_1143 = F_590 ( V_65 , V_1033 , & V_260 ) ;
if ( V_1143 < 0 )
goto V_1148;
goto V_1164;
}
#endif
V_1143 = F_539 ( V_65 , V_1033 , & V_260 ) ;
if ( V_1143 < 0 )
goto V_1148;
else if ( ! V_1143 )
F_552 ( V_65 , V_1033 ) ;
if ( F_14 ( V_398 , & V_65 -> V_35 ) )
F_570 ( V_65 , V_1033 ) ;
#ifdef F_181
V_1164:
#endif
F_563 ( V_65 , V_1033 , V_260 ) ;
return V_1165 ;
V_1148:
F_180 ( V_1033 -> V_94 ) ;
V_1033 -> V_94 = NULL ;
return V_1165 ;
}
static T_17 F_591 ( struct V_212 * V_94 ,
struct V_61 * V_62 ,
struct V_64 * V_148 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
struct V_64 * V_65 ;
if ( F_592 ( V_94 , 17 ) )
return V_1165 ;
V_65 = V_148 ? V_148 : V_2 -> V_65 [ V_94 -> V_1139 ] ;
return F_580 ( V_94 , V_2 , V_65 ) ;
}
static T_17 F_593 ( struct V_212 * V_94 ,
struct V_61 * V_62 )
{
return F_591 ( V_94 , V_62 , NULL ) ;
}
static int F_594 ( struct V_61 * V_62 , void * V_1166 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1167 * V_602 = V_1166 ;
if ( ! F_382 ( V_602 -> V_1168 ) )
return - V_1169 ;
memcpy ( V_62 -> V_689 , V_602 -> V_1168 , V_62 -> V_1170 ) ;
memcpy ( V_14 -> V_113 . V_602 , V_602 -> V_1168 , V_62 -> V_1170 ) ;
F_325 ( V_2 ) ;
return 0 ;
}
static int
F_595 ( struct V_61 * V_62 , int V_1171 , int V_1172 , T_2 V_602 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_4 ;
int V_346 ;
if ( V_1171 != V_14 -> V_46 . V_1173 . V_1171 )
return - V_607 ;
V_346 = V_14 -> V_46 . V_353 . V_1174 ( V_14 , V_602 , V_1172 , & V_4 ) ;
if ( ! V_346 )
V_346 = V_4 ;
return V_346 ;
}
static int F_596 ( struct V_61 * V_62 , int V_1171 , int V_1172 ,
T_2 V_602 , T_2 V_4 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_1171 != V_14 -> V_46 . V_1173 . V_1171 )
return - V_607 ;
return V_14 -> V_46 . V_353 . V_1175 ( V_14 , V_602 , V_1172 , V_4 ) ;
}
static int F_597 ( struct V_61 * V_62 , struct V_1176 * V_1177 , int V_1178 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
switch ( V_1178 ) {
case V_1179 :
return F_598 ( V_2 , V_1177 ) ;
case V_1180 :
return F_599 ( V_2 , V_1177 ) ;
default:
return F_600 ( & V_2 -> V_14 . V_46 . V_1173 , F_601 ( V_1177 ) , V_1178 ) ;
}
}
static int F_602 ( struct V_61 * V_80 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_88 ( V_80 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_382 ( V_14 -> V_113 . V_1181 ) ) {
F_470 () ;
V_17 = F_603 ( V_80 , V_14 -> V_113 . V_1181 , V_1182 ) ;
F_473 () ;
V_14 -> V_113 . V_353 . V_733 ( V_14 , F_291 ( 0 ) ) ;
}
return V_17 ;
}
static int F_604 ( struct V_61 * V_80 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_88 ( V_80 ) ;
struct V_1183 * V_113 = & V_2 -> V_14 . V_113 ;
if ( F_382 ( V_113 -> V_1181 ) ) {
F_470 () ;
V_17 = F_605 ( V_80 , V_113 -> V_1181 , V_1182 ) ;
F_473 () ;
}
return V_17 ;
}
static void F_606 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
int V_49 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
for ( V_49 = 0 ; V_49 < V_2 -> V_206 ; V_49 ++ )
F_238 ( 0 , V_2 -> V_170 [ V_49 ] ) ;
}
static void F_607 ( struct V_61 * V_62 ,
struct V_1184 * V_128 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
int V_49 ;
F_608 () ;
for ( V_49 = 0 ; V_49 < V_2 -> V_98 ; V_49 ++ ) {
struct V_64 * V_148 = F_21 ( V_2 -> V_74 [ V_49 ] ) ;
T_6 V_184 , V_149 ;
unsigned int V_1185 ;
if ( V_148 ) {
do {
V_1185 = F_609 ( & V_148 -> V_183 ) ;
V_149 = V_148 -> V_128 . V_149 ;
V_184 = V_148 -> V_128 . V_184 ;
} while ( F_610 ( & V_148 -> V_183 , V_1185 ) );
V_128 -> V_854 += V_149 ;
V_128 -> V_853 += V_184 ;
}
}
for ( V_49 = 0 ; V_49 < V_2 -> V_82 ; V_49 ++ ) {
struct V_64 * V_148 = F_21 ( V_2 -> V_65 [ V_49 ] ) ;
T_6 V_184 , V_149 ;
unsigned int V_1185 ;
if ( V_148 ) {
do {
V_1185 = F_609 ( & V_148 -> V_183 ) ;
V_149 = V_148 -> V_128 . V_149 ;
V_184 = V_148 -> V_128 . V_184 ;
} while ( F_610 ( & V_148 -> V_183 , V_1185 ) );
V_128 -> V_856 += V_149 ;
V_128 -> V_855 += V_184 ;
}
}
F_611 () ;
V_128 -> V_963 = V_62 -> V_128 . V_963 ;
V_128 -> V_964 = V_62 -> V_128 . V_964 ;
V_128 -> V_966 = V_62 -> V_128 . V_966 ;
V_128 -> V_967 = V_62 -> V_128 . V_967 ;
V_128 -> V_968 = V_62 -> V_128 . V_968 ;
}
static void F_612 ( struct V_1 * V_2 , T_4 V_138 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_3 , V_1186 ;
int V_49 ;
if ( V_14 -> V_113 . type == V_114 )
return;
V_3 = F_40 ( V_14 , V_1187 ) ;
V_1186 = V_3 ;
for ( V_49 = 0 ; V_49 < V_660 ; V_49 ++ ) {
T_4 V_1188 = V_3 >> ( V_49 * V_1189 ) ;
if ( V_1188 > V_138 )
V_3 &= ~ ( 0x7 << V_1189 ) ;
}
if ( V_3 != V_1186 )
F_75 ( V_14 , V_1187 , V_3 ) ;
return;
}
static void F_613 ( struct V_1 * V_2 )
{
struct V_61 * V_80 = V_2 -> V_62 ;
struct V_1190 * V_140 = & V_2 -> V_140 ;
struct V_1191 * V_1192 = V_2 -> V_645 ;
T_4 V_1193 ;
for ( V_1193 = 0 ; V_1193 < V_1194 ; V_1193 ++ ) {
T_4 V_138 = 0 ;
if ( V_2 -> V_641 & V_642 )
V_138 = F_614 ( V_140 , 0 , V_1193 ) ;
else if ( V_1192 )
V_138 = V_1192 -> V_646 [ V_1193 ] ;
F_615 ( V_80 , V_1193 , V_138 ) ;
}
}
int F_616 ( struct V_61 * V_80 , T_4 V_138 )
{
struct V_1 * V_2 = F_88 ( V_80 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
bool V_1195 ;
if ( V_138 > V_2 -> V_140 . V_746 . V_747 )
return - V_607 ;
if ( V_14 -> V_113 . type == V_114 && V_138 && V_138 < V_660 )
return - V_607 ;
V_1195 = ( F_617 ( & V_2 -> V_686 , 32 ) > 1 ) ;
if ( V_138 && V_1195 && V_2 -> V_687 > V_1196 )
return - V_818 ;
if ( F_61 ( V_80 ) )
F_459 ( V_80 ) ;
else
F_407 ( V_2 ) ;
F_477 ( V_2 ) ;
#ifdef F_388
if ( V_138 ) {
F_618 ( V_80 , V_138 ) ;
F_613 ( V_2 ) ;
V_2 -> V_143 |= V_144 ;
if ( V_2 -> V_14 . V_113 . type == V_114 ) {
V_2 -> V_1197 = V_2 -> V_14 . V_129 . V_795 ;
V_2 -> V_14 . V_129 . V_795 = V_1198 ;
}
} else {
F_619 ( V_80 ) ;
if ( V_2 -> V_14 . V_113 . type == V_114 )
V_2 -> V_14 . V_129 . V_795 = V_2 -> V_1197 ;
V_2 -> V_143 &= ~ V_144 ;
V_2 -> V_762 . V_141 = false ;
V_2 -> V_140 . V_141 = false ;
}
F_612 ( V_2 , V_138 ) ;
#endif
F_471 ( V_2 ) ;
if ( F_61 ( V_80 ) )
return F_454 ( V_80 ) ;
return 0 ;
}
static int F_620 ( struct V_1 * V_2 ,
struct V_1199 * V_1200 )
{
T_1 V_1201 = V_1200 -> V_1202 . V_1203 ;
T_1 V_1204 = F_621 ( V_1200 -> V_1202 . V_1203 ) ;
T_1 V_1205 = V_1200 -> V_1202 . V_1203 & 0xfffff ;
int V_17 = 0 , V_49 , V_56 ;
struct V_1206 * V_1207 = NULL ;
if ( V_1205 > V_1208 )
return - V_607 ;
if ( ( V_1204 != 0x800 ) && ( V_1204 >= V_789 ) )
return - V_607 ;
if ( V_1204 != 0x800 ) {
V_1207 = V_2 -> V_785 [ V_1204 ] ;
if ( ! V_1207 )
return - V_607 ;
if ( ! F_14 ( V_1205 - 1 , V_1207 -> V_1209 ) )
return - V_607 ;
F_37 ( V_1205 - 1 , V_1207 -> V_1209 ) ;
}
for ( V_49 = 1 ; V_49 < V_789 ; V_49 ++ ) {
V_1207 = V_2 -> V_785 [ V_49 ] ;
if ( V_1207 && V_1207 -> V_1210 == V_1201 ) {
for ( V_56 = 0 ; V_56 < V_1208 ; V_56 ++ ) {
if ( ! F_14 ( V_56 , V_1207 -> V_1209 ) )
continue;
F_365 ( & V_2 -> V_670 ) ;
V_17 = F_622 ( V_2 ,
NULL ,
V_56 + 1 ) ;
F_370 ( & V_2 -> V_670 ) ;
F_37 ( V_56 , V_1207 -> V_1209 ) ;
}
F_251 ( V_1207 -> V_1103 ) ;
F_251 ( V_1207 -> V_123 ) ;
F_251 ( V_1207 ) ;
V_2 -> V_785 [ V_49 ] = NULL ;
return V_17 ;
}
}
F_365 ( & V_2 -> V_670 ) ;
V_17 = F_622 ( V_2 , NULL , V_1205 ) ;
F_370 ( & V_2 -> V_670 ) ;
return V_17 ;
}
static int F_623 ( struct V_1 * V_2 ,
T_12 V_273 ,
struct V_1199 * V_1200 )
{
T_1 V_1204 = F_621 ( V_1200 -> V_1211 . V_1203 ) ;
if ( V_1204 >= V_789 )
return - V_607 ;
if ( V_1200 -> V_1211 . V_1212 > 0 )
return - V_607 ;
F_92 ( V_1204 - 1 , & V_2 -> V_1213 ) ;
return 0 ;
}
static int F_624 ( struct V_1 * V_2 ,
struct V_1199 * V_1200 )
{
T_1 V_1204 = F_621 ( V_1200 -> V_1211 . V_1203 ) ;
if ( V_1204 >= V_789 )
return - V_607 ;
F_37 ( V_1204 - 1 , & V_2 -> V_1213 ) ;
return 0 ;
}
static int F_625 ( struct V_61 * V_100 , void * V_1214 )
{
if ( F_384 ( V_100 ) ) {
struct V_690 * V_691 = F_88 ( V_100 ) ;
struct V_676 * V_677 = V_691 -> V_692 ;
struct V_1215 * V_97 = V_1214 ;
struct V_1 * V_2 = V_97 -> V_2 ;
int V_1216 = V_97 -> V_1216 ;
if ( V_677 && V_677 -> V_62 -> V_1216 == V_1216 ) {
V_97 -> V_109 = V_2 -> V_74 [ V_677 -> V_679 ] -> V_154 ;
V_97 -> V_674 = V_97 -> V_109 ;
return 1 ;
}
}
return 0 ;
}
static int F_626 ( struct V_1 * V_2 , int V_1216 ,
T_4 * V_109 , T_6 * V_674 )
{
unsigned int V_318 = V_2 -> V_318 , V_1011 ;
struct V_1215 V_97 ;
struct V_61 * V_100 ;
for ( V_1011 = 0 ; V_1011 < V_318 ; ++ V_1011 ) {
V_100 = F_463 ( V_2 -> V_532 [ V_1011 ] . V_1008 ) ;
if ( V_100 -> V_1216 == V_1216 ) {
if ( V_2 -> V_687 > 1 )
* V_109 = V_1011 * 2 ;
else
* V_109 = V_1011 * V_2 -> V_678 ;
* V_674 = V_1011 + 1 ;
* V_674 <<= V_1217 ;
return 0 ;
}
}
V_97 . V_2 = V_2 ;
V_97 . V_1216 = V_1216 ;
V_97 . V_674 = 0 ;
V_97 . V_109 = 0 ;
if ( F_386 ( V_2 -> V_62 ,
F_625 , & V_97 ) ) {
* V_674 = V_97 . V_674 ;
* V_109 = V_97 . V_109 ;
return 0 ;
}
return - V_607 ;
}
static int F_627 ( struct V_1 * V_2 ,
struct V_1218 * V_1219 , T_6 * V_674 , T_4 * V_109 )
{
const struct V_1220 * V_71 ;
F_628 ( V_1221 ) ;
int V_17 ;
if ( F_629 ( V_1219 ) )
return - V_607 ;
F_630 ( V_1219 , & V_1221 ) ;
F_631 (a, &actions, list) {
if ( F_632 ( V_71 ) ) {
* V_674 = V_675 ;
* V_109 = V_675 ;
return 0 ;
}
if ( F_633 ( V_71 ) ) {
int V_1216 = F_634 ( V_71 ) ;
V_17 = F_626 ( V_2 , V_1216 , V_109 ,
V_674 ) ;
if ( V_17 == 0 )
return V_17 ;
}
}
return - V_607 ;
}
static int F_627 ( struct V_1 * V_2 ,
struct V_1218 * V_1219 , T_6 * V_674 , T_4 * V_109 )
{
return - V_607 ;
}
static int F_635 ( struct V_668 * V_1103 ,
union V_1222 * V_123 ,
struct V_1199 * V_1200 ,
struct V_1223 * V_1224 ,
struct V_1225 * V_1226 )
{
int V_49 , V_56 , V_1227 ;
T_18 V_1228 , V_1229 ;
bool V_1230 = false , V_1231 = false ;
for ( V_49 = 0 ; V_49 < V_1200 -> V_1202 . V_1232 -> V_1233 ; V_49 ++ ) {
V_1227 = V_1200 -> V_1202 . V_1232 -> V_1234 [ V_49 ] . V_1227 ;
V_1228 = V_1200 -> V_1202 . V_1232 -> V_1234 [ V_49 ] . V_1228 ;
V_1229 = V_1200 -> V_1202 . V_1232 -> V_1234 [ V_49 ] . V_123 ;
for ( V_56 = 0 ; V_1224 [ V_56 ] . V_1228 ; V_56 ++ ) {
if ( V_1224 [ V_56 ] . V_1227 == V_1227 ) {
V_1224 [ V_56 ] . V_1228 ( V_1103 , V_123 , V_1228 , V_1229 ) ;
V_1103 -> V_669 . V_1121 . V_1127 |=
V_1224 [ V_56 ] . type ;
V_1230 = true ;
break;
}
}
if ( V_1226 ) {
if ( V_1226 -> V_1227 == V_1200 -> V_1202 . V_1232 -> V_1234 [ V_49 ] . V_1227 &&
V_1226 -> V_1228 == V_1200 -> V_1202 . V_1232 -> V_1234 [ V_49 ] . V_1228 &&
V_1226 -> V_123 == V_1200 -> V_1202 . V_1232 -> V_1234 [ V_49 ] . V_123 )
V_1231 = true ;
else
continue;
}
}
if ( V_1226 && ! V_1231 )
return - V_607 ;
if ( ! V_1230 )
return 0 ;
V_123 -> V_1121 . V_1127 = V_1235 |
V_1236 ;
if ( V_1103 -> V_669 . V_1121 . V_1127 == V_1237 )
V_123 -> V_1121 . V_1127 &= V_1235 ;
return 0 ;
}
static int F_636 ( struct V_1 * V_2 ,
T_12 V_273 ,
struct V_1199 * V_1200 )
{
T_1 V_1205 = V_1200 -> V_1202 . V_1203 & 0xfffff ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1223 * V_1224 ;
struct V_668 * V_1103 = NULL ;
union V_1222 * V_123 = NULL ;
struct V_1206 * V_1207 = NULL ;
int V_49 , V_17 = - V_607 ;
T_4 V_109 ;
T_1 V_1204 , V_1238 ;
V_1204 = F_621 ( V_1200 -> V_1202 . V_1203 ) ;
V_1238 = F_621 ( V_1200 -> V_1202 . V_1239 ) ;
if ( V_273 != F_162 ( V_1077 ) )
return V_17 ;
if ( V_1205 >= ( ( 1024 << V_2 -> V_663 ) - 2 ) ) {
F_106 ( V_160 , L_135 ) ;
return V_17 ;
}
if ( V_1204 == 0x800 ) {
V_1224 = ( V_2 -> V_785 [ 0 ] ) -> V_787 ;
} else {
if ( V_1204 >= V_789 )
return V_17 ;
if ( ! V_2 -> V_785 [ V_1204 ] )
return V_17 ;
V_1224 = ( V_2 -> V_785 [ V_1204 ] ) -> V_787 ;
}
if ( ! V_1224 )
return V_17 ;
if ( V_1238 ) {
struct V_1225 * V_1226 = V_1240 ;
if ( V_1238 >= V_789 )
return V_17 ;
if ( ! F_14 ( V_1238 - 1 , & V_2 -> V_1213 ) )
return V_17 ;
if ( V_2 -> V_785 [ V_1238 ] &&
( V_2 -> V_785 [ V_1238 ] ) -> V_1210 ) {
F_106 ( V_160 , L_136 ,
V_1238 ) ;
return V_17 ;
}
for ( V_49 = 0 ; V_1226 [ V_49 ] . V_1207 ; V_49 ++ ) {
if ( V_1226 [ V_49 ] . V_1241 != V_1200 -> V_1202 . V_1232 -> V_1242 ||
V_1226 [ V_49 ] . V_1243 != V_1200 -> V_1202 . V_1232 -> V_1244 ||
V_1226 [ V_49 ] . V_1229 != V_1200 -> V_1202 . V_1232 -> V_1245 )
return V_17 ;
V_1207 = F_429 ( sizeof( * V_1207 ) , V_786 ) ;
if ( ! V_1207 )
return - V_595 ;
V_1103 = F_429 ( sizeof( * V_1103 ) , V_786 ) ;
if ( ! V_1103 ) {
V_17 = - V_595 ;
goto V_1246;
}
V_123 = F_429 ( sizeof( * V_123 ) , V_786 ) ;
if ( ! V_123 ) {
V_17 = - V_595 ;
goto V_1247;
}
V_1207 -> V_1103 = V_1103 ;
V_1207 -> V_123 = V_123 ;
V_1207 -> V_1210 = V_1200 -> V_1202 . V_1203 ;
V_17 = F_635 ( V_1103 , V_123 , V_1200 ,
V_1224 , & V_1226 [ V_49 ] ) ;
if ( ! V_17 ) {
V_1207 -> V_787 = V_1226 [ V_49 ] . V_1207 ;
V_2 -> V_785 [ V_1238 ] = V_1207 ;
break;
}
}
return 0 ;
}
V_1103 = F_429 ( sizeof( * V_1103 ) , V_786 ) ;
if ( ! V_1103 )
return - V_595 ;
V_123 = F_429 ( sizeof( * V_123 ) , V_786 ) ;
if ( ! V_123 ) {
V_17 = - V_595 ;
goto V_1247;
}
if ( ( V_1204 != 0x800 ) && ( V_2 -> V_785 [ V_1204 ] ) ) {
if ( ( V_2 -> V_785 [ V_1204 ] ) -> V_1103 )
memcpy ( V_1103 , ( V_2 -> V_785 [ V_1204 ] ) -> V_1103 ,
sizeof( * V_1103 ) ) ;
if ( ( V_2 -> V_785 [ V_1204 ] ) -> V_123 )
memcpy ( V_123 , ( V_2 -> V_785 [ V_1204 ] ) -> V_123 ,
sizeof( * V_123 ) ) ;
for ( V_49 = 1 ; V_49 < V_789 ; V_49 ++ ) {
struct V_1206 * V_395 = V_2 -> V_785 [ V_49 ] ;
if ( V_395 && ( F_14 ( V_1205 - 1 , V_395 -> V_1209 ) ) ) {
F_106 ( V_160 , L_137 ,
V_1205 ) ;
V_17 = - V_607 ;
goto V_1248;
}
}
}
V_17 = F_635 ( V_1103 , V_123 , V_1200 , V_1224 , NULL ) ;
if ( V_17 )
goto V_1248;
V_17 = F_627 ( V_2 , V_1200 -> V_1202 . V_1219 , & V_1103 -> V_674 ,
& V_109 ) ;
if ( V_17 < 0 )
goto V_1248;
V_1103 -> V_673 = V_1205 ;
F_365 ( & V_2 -> V_670 ) ;
if ( F_366 ( & V_2 -> V_671 ) ) {
memcpy ( & V_2 -> V_672 , V_123 , sizeof( * V_123 ) ) ;
V_17 = F_367 ( V_14 , V_123 ) ;
if ( V_17 )
goto V_1249;
} else if ( memcmp ( & V_2 -> V_672 , V_123 , sizeof( * V_123 ) ) ) {
V_17 = - V_607 ;
goto V_1249;
}
F_637 ( & V_1103 -> V_669 , V_123 ) ;
V_17 = F_369 ( V_14 , & V_1103 -> V_669 ,
V_1103 -> V_673 , V_109 ) ;
if ( ! V_17 )
F_622 ( V_2 , V_1103 , V_1103 -> V_673 ) ;
F_370 ( & V_2 -> V_670 ) ;
if ( ( V_1204 != 0x800 ) && ( V_2 -> V_785 [ V_1204 ] ) )
F_92 ( V_1205 - 1 , ( V_2 -> V_785 [ V_1204 ] ) -> V_1209 ) ;
F_251 ( V_123 ) ;
return V_17 ;
V_1249:
F_370 ( & V_2 -> V_670 ) ;
V_1248:
F_251 ( V_123 ) ;
V_1247:
F_251 ( V_1103 ) ;
V_1246:
F_251 ( V_1207 ) ;
return V_17 ;
}
static int F_638 ( struct V_61 * V_80 , T_1 V_1203 , T_12 V_571 ,
struct V_1250 * V_138 )
{
struct V_1 * V_2 = F_88 ( V_80 ) ;
if ( F_639 ( V_1203 ) == F_639 ( V_1251 ) &&
V_138 -> type == V_1252 ) {
switch ( V_138 -> V_1253 -> V_1254 ) {
case V_1255 :
case V_1256 :
return F_636 ( V_2 ,
V_571 , V_138 -> V_1253 ) ;
case V_1257 :
return F_620 ( V_2 , V_138 -> V_1253 ) ;
case V_1258 :
case V_1259 :
return F_623 ( V_2 , V_571 ,
V_138 -> V_1253 ) ;
case V_1260 :
return F_624 ( V_2 ,
V_138 -> V_1253 ) ;
default:
return - V_607 ;
}
}
if ( V_138 -> type != V_1261 )
return - V_607 ;
return F_616 ( V_80 , V_138 -> V_138 ) ;
}
void F_640 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
F_470 () ;
F_616 ( V_62 , F_264 ( V_62 ) ) ;
F_473 () ;
}
void F_641 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
if ( F_61 ( V_62 ) )
F_399 ( V_2 ) ;
else
F_407 ( V_2 ) ;
}
static T_13 F_642 ( struct V_61 * V_62 ,
T_13 V_214 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
if ( ! ( V_214 & V_231 ) )
V_214 &= ~ V_1262 ;
if ( ! ( V_2 -> V_347 & V_777 ) )
V_214 &= ~ V_1262 ;
return V_214 ;
}
static int F_643 ( struct V_61 * V_62 ,
T_13 V_214 )
{
struct V_1 * V_2 = F_88 ( V_62 ) ;
T_13 V_1263 = V_62 -> V_214 ^ V_214 ;
bool V_1264 = false ;
if ( ! ( V_214 & V_1262 ) ) {
if ( V_2 -> V_347 & V_549 )
V_1264 = true ;
V_2 -> V_347 &= ~ V_549 ;
} else if ( ( V_2 -> V_347 & V_777 ) &&
! ( V_2 -> V_347 & V_549 ) ) {
if ( V_2 -> V_407 == 1 ||
V_2 -> V_407 > V_1265 ) {
V_2 -> V_347 |= V_549 ;
V_1264 = true ;
} else if ( ( V_1263 ^ V_214 ) & V_1262 ) {
F_108 ( V_186 , L_138
L_139 ) ;
}
}
if ( ( V_214 & V_1266 ) || ( V_214 & V_1267 ) ) {
if ( ! ( V_2 -> V_143 & V_662 ) )
V_1264 = true ;
V_2 -> V_143 &= ~ V_388 ;
V_2 -> V_143 |= V_662 ;
} else {
if ( V_2 -> V_143 & V_662 )
V_1264 = true ;
V_2 -> V_143 &= ~ V_662 ;
if ( V_2 -> V_143 & V_436 ||
( F_264 ( V_62 ) > 1 ) ||
( V_2 -> V_441 [ V_456 ] . V_776 <= 1 ) ||
( ! V_2 -> V_426 ) )
;
else
V_2 -> V_143 |= V_388 ;
}
if ( V_1263 & V_293 )
V_1264 = true ;
V_62 -> V_214 = V_214 ;
if ( ( V_2 -> V_143 & V_633 ) ) {
if ( V_214 & V_231 ) {
V_2 -> V_347 |= V_1032 ;
} else {
T_1 V_1268 = V_636 ;
F_345 ( V_2 , V_1268 ) ;
}
}
if ( ( V_2 -> V_143 & V_634 ) ) {
if ( V_214 & V_231 ) {
V_2 -> V_347 |= V_1032 ;
} else {
T_1 V_1268 = V_638 ;
F_345 ( V_2 , V_1268 ) ;
}
}
if ( V_1264 )
F_641 ( V_62 ) ;
else if ( V_1263 & ( V_268 |
V_627 ) )
F_338 ( V_62 ) ;
return 0 ;
}
static void F_644 ( struct V_61 * V_80 ,
struct V_1269 * V_410 )
{
struct V_1 * V_2 = F_88 ( V_80 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_12 V_1123 = V_410 -> V_1123 ;
T_1 V_1270 = 0 ;
T_1 V_3 ;
if ( V_410 -> V_1271 != V_1272 )
return;
switch ( V_410 -> type ) {
case V_1273 :
if ( ! ( V_2 -> V_143 & V_633 ) )
return;
if ( V_2 -> V_637 == V_1123 )
return;
if ( V_2 -> V_637 ) {
F_645 ( V_80 ,
L_140 ,
F_585 ( V_2 -> V_637 ) ,
F_585 ( V_1123 ) ) ;
return;
}
V_2 -> V_637 = V_1123 ;
break;
case V_1274 :
if ( ! ( V_2 -> V_143 & V_634 ) )
return;
if ( V_2 -> V_639 == V_1123 )
return;
if ( V_2 -> V_639 ) {
F_645 ( V_80 ,
L_141 ,
F_585 ( V_2 -> V_639 ) ,
F_585 ( V_1123 ) ) ;
return;
}
V_1270 = V_1275 ;
V_2 -> V_639 = V_1123 ;
break;
default:
return;
}
V_3 = F_40 ( V_14 , V_635 ) | F_585 ( V_1123 ) << V_1270 ;
F_75 ( V_14 , V_635 , V_3 ) ;
}
static void F_646 ( struct V_61 * V_80 ,
struct V_1269 * V_410 )
{
struct V_1 * V_2 = F_88 ( V_80 ) ;
T_1 V_1268 ;
if ( V_410 -> type != V_1273 &&
V_410 -> type != V_1274 )
return;
if ( V_410 -> V_1271 != V_1272 )
return;
switch ( V_410 -> type ) {
case V_1273 :
if ( ! ( V_2 -> V_143 & V_633 ) )
return;
if ( V_2 -> V_637 != V_410 -> V_1123 ) {
F_645 ( V_80 , L_142 ,
F_585 ( V_410 -> V_1123 ) ) ;
return;
}
V_1268 = V_636 ;
break;
case V_1274 :
if ( ! ( V_2 -> V_143 & V_634 ) )
return;
if ( V_2 -> V_639 != V_410 -> V_1123 ) {
F_645 ( V_80 , L_143 ,
F_585 ( V_410 -> V_1123 ) ) ;
return;
}
V_1268 = V_638 ;
break;
default:
return;
}
F_345 ( V_2 , V_1268 ) ;
V_2 -> V_347 |= V_1032 ;
}
static int F_647 ( struct V_1276 * V_1277 , struct V_1278 * V_1279 [] ,
struct V_61 * V_80 ,
const unsigned char * V_602 , T_2 V_270 ,
T_2 V_143 )
{
if ( F_648 ( V_602 ) || F_649 ( V_602 ) ) {
struct V_1 * V_2 = F_88 ( V_80 ) ;
T_2 V_506 = F_291 ( 0 ) ;
if ( F_332 ( V_80 ) >= F_324 ( V_2 , V_506 ) )
return - V_595 ;
}
return F_650 ( V_1277 , V_1279 , V_80 , V_602 , V_270 , V_143 ) ;
}
static int F_651 ( struct V_1 * V_2 ,
T_19 V_1280 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
unsigned int V_1166 , V_1281 ;
T_1 V_515 ;
switch ( V_1280 ) {
case V_1282 :
F_75 ( & V_2 -> V_14 , V_523 , 0 ) ;
V_515 = F_40 ( V_14 , V_1283 ) ;
V_515 |= V_520 ;
F_75 ( V_14 , V_1283 , V_515 ) ;
V_1281 = V_2 -> V_318 + V_2 -> V_687 ;
for ( V_1166 = 0 ; V_1166 < V_1281 ; V_1166 ++ ) {
if ( V_14 -> V_113 . V_353 . V_1284 )
V_14 -> V_113 . V_353 . V_1284 ( V_14 ,
true ,
V_1166 ) ;
}
break;
case V_522 :
F_75 ( & V_2 -> V_14 , V_523 ,
V_524 ) ;
V_515 = F_40 ( V_14 , V_1283 ) ;
if ( ! V_2 -> V_318 )
V_515 &= ~ V_520 ;
F_75 ( V_14 , V_1283 , V_515 ) ;
V_1281 = V_2 -> V_318 + V_2 -> V_687 ;
for ( V_1166 = 0 ; V_1166 < V_1281 ; V_1166 ++ ) {
if ( V_14 -> V_113 . V_353 . V_1284 )
V_14 -> V_113 . V_353 . V_1284 ( V_14 ,
false ,
V_1166 ) ;
}
break;
default:
return - V_607 ;
}
V_2 -> V_521 = V_1280 ;
F_108 ( V_160 , L_144 ,
V_1280 == V_1282 ? L_145 : L_146 ) ;
return 0 ;
}
static int F_652 ( struct V_61 * V_80 ,
struct V_1285 * V_1286 , T_2 V_143 )
{
struct V_1 * V_2 = F_88 ( V_80 ) ;
struct V_1278 * V_1287 , * V_1288 ;
int V_1289 ;
if ( ! ( V_2 -> V_143 & V_436 ) )
return - V_1290 ;
V_1288 = F_653 ( V_1286 , sizeof( struct V_1291 ) , V_1292 ) ;
if ( ! V_1288 )
return - V_607 ;
F_654 (attr, br_spec, rem) {
int V_178 ;
T_19 V_1280 ;
if ( F_655 ( V_1287 ) != V_1293 )
continue;
if ( F_656 ( V_1287 ) < sizeof( V_1280 ) )
return - V_607 ;
V_1280 = F_657 ( V_1287 ) ;
V_178 = F_651 ( V_2 , V_1280 ) ;
if ( V_178 )
return V_178 ;
break;
}
return 0 ;
}
static int F_658 ( struct V_212 * V_94 , T_1 V_1294 , T_1 V_1295 ,
struct V_61 * V_80 ,
T_1 V_1296 , int V_1297 )
{
struct V_1 * V_2 = F_88 ( V_80 ) ;
if ( ! ( V_2 -> V_143 & V_436 ) )
return 0 ;
return F_659 ( V_94 , V_1294 , V_1295 , V_80 ,
V_2 -> V_521 , 0 , 0 , V_1297 ,
V_1296 , NULL ) ;
}
static void * F_660 ( struct V_61 * V_9 , struct V_61 * V_680 )
{
struct V_676 * V_1136 = NULL ;
struct V_1 * V_2 = F_88 ( V_9 ) ;
int V_1298 = V_2 -> V_318 + V_2 -> V_687 ;
unsigned int V_776 ;
int V_506 , V_17 ;
if ( V_1298 >= V_1299 )
return F_661 ( - V_607 ) ;
#ifdef F_662
if ( V_680 -> V_98 != V_680 -> V_82 ) {
F_645 ( V_9 , L_147 ,
V_680 -> V_60 ) ;
return F_661 ( - V_607 ) ;
}
#endif
if ( V_680 -> V_82 > V_821 ||
V_680 -> V_82 == V_1300 ) {
F_645 ( V_9 ,
L_148 ,
V_9 -> V_60 ) ;
return F_661 ( - V_607 ) ;
}
if ( ( ( V_2 -> V_143 & V_144 ) &&
V_2 -> V_687 > V_1196 - 1 ) ||
( V_2 -> V_687 > V_1301 ) )
return F_661 ( - V_818 ) ;
V_1136 = F_429 ( sizeof( * V_1136 ) , V_786 ) ;
if ( ! V_1136 )
return F_661 ( - V_595 ) ;
V_506 = F_617 ( & V_2 -> V_686 , 32 ) ;
V_2 -> V_687 ++ ;
F_92 ( V_506 , & V_2 -> V_686 ) ;
V_776 = F_663 ( & V_2 -> V_686 , 32 ) ;
V_2 -> V_143 |= V_584 | V_436 ;
V_2 -> V_441 [ V_442 ] . V_776 = V_776 + 1 ;
V_2 -> V_441 [ V_456 ] . V_776 = V_680 -> V_82 ;
V_17 = F_616 ( V_9 , F_264 ( V_9 ) ) ;
if ( V_17 )
goto V_1302;
V_1136 -> V_506 = V_506 ;
V_1136 -> V_153 = V_2 ;
if ( F_61 ( V_9 ) ) {
V_17 = F_378 ( V_680 , V_1136 ) ;
if ( V_17 )
goto V_1302;
F_664 ( V_680 ) ;
}
return V_1136 ;
V_1302:
F_645 ( V_9 ,
L_149 , V_680 -> V_60 ) ;
F_37 ( V_506 , & V_2 -> V_686 ) ;
V_2 -> V_687 -- ;
F_251 ( V_1136 ) ;
return F_661 ( V_17 ) ;
}
static void F_665 ( struct V_61 * V_9 , void * V_1303 )
{
struct V_676 * V_1136 = V_1303 ;
struct V_1 * V_2 = V_1136 -> V_153 ;
unsigned int V_776 ;
F_37 ( V_1136 -> V_506 , & V_2 -> V_686 ) ;
V_2 -> V_687 -- ;
V_776 = F_663 ( & V_2 -> V_686 , 32 ) ;
V_2 -> V_441 [ V_442 ] . V_776 = V_776 + 1 ;
F_376 ( V_1136 -> V_62 , V_1136 ) ;
F_616 ( V_9 , F_264 ( V_9 ) ) ;
F_379 ( V_9 , L_90 ,
V_1136 -> V_506 , V_2 -> V_687 ,
V_1136 -> V_679 ,
V_1136 -> V_679 + V_2 -> V_678 ,
V_2 -> V_686 ) ;
F_251 ( V_1136 ) ;
}
static T_13
F_666 ( struct V_212 * V_94 , struct V_61 * V_80 ,
T_13 V_214 )
{
unsigned int V_1304 , V_1305 ;
V_1305 = F_542 ( V_94 ) - V_94 -> V_97 ;
if ( F_23 ( V_1305 > V_1306 ) )
return V_214 & ~ ( V_1307 |
V_1308 |
V_1309 |
V_1310 |
V_1311 ) ;
V_1304 = F_543 ( V_94 ) - F_542 ( V_94 ) ;
if ( F_23 ( V_1304 > V_1312 ) )
return V_214 & ~ ( V_1307 |
V_1308 |
V_1310 |
V_1311 ) ;
if ( V_94 -> V_233 && ! ( V_214 & V_1313 ) )
V_214 &= ~ V_1310 ;
return V_214 ;
}
static inline int F_667 ( struct V_1 * V_2 )
{
struct V_5 * V_412 , * V_9 = V_2 -> V_9 ;
int V_1314 = 0 ;
if ( F_8 ( & V_2 -> V_14 ) )
V_1314 = 4 ;
F_631 (entry, &adapter->pdev->bus->devices, bus_list) {
if ( V_412 -> V_1315 )
continue;
if ( ( V_412 -> V_768 != V_9 -> V_768 ) ||
( V_412 -> V_207 != V_9 -> V_207 ) )
return - 1 ;
V_1314 ++ ;
}
return V_1314 ;
}
bool F_668 ( struct V_1 * V_2 , T_2 V_21 ,
T_2 V_1316 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1317 = V_2 -> V_1318 & V_1319 ;
if ( V_14 -> V_113 . type == V_114 )
return false ;
if ( V_14 -> V_113 . type >= V_117 ) {
if ( ( V_1317 == V_1320 ) ||
( ( V_1317 == V_1321 ) &&
( V_14 -> V_10 . V_1322 == 0 ) ) )
return true ;
}
switch ( V_21 ) {
case V_1323 :
switch ( V_1316 ) {
case V_1324 :
case V_1325 :
case V_1326 :
case V_1327 :
if ( V_14 -> V_10 . V_1322 != 0 )
break;
case V_1328 :
case V_1329 :
case V_1330 :
case V_1331 :
case V_1332 :
case V_1333 :
case V_1334 :
return true ;
}
break;
case V_1335 :
switch ( V_1316 ) {
case V_1336 :
return true ;
}
break;
case V_1337 :
if ( V_1316 != V_1338 )
return true ;
break;
case V_1339 :
return true ;
default:
break;
}
return false ;
}
static int F_669 ( struct V_5 * V_9 , const struct V_1340 * V_1341 )
{
struct V_61 * V_62 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_14 ;
const struct V_763 * V_764 = V_1342 [ V_1341 -> V_1343 ] ;
int V_49 , V_17 , V_1344 , V_24 ;
unsigned int V_472 = V_1345 ;
T_4 V_1346 [ V_1347 ] ;
bool V_1348 = false ;
#ifdef F_181
T_2 V_1349 ;
#endif
T_1 V_1350 ;
if ( V_9 -> V_1315 ) {
F_670 ( 1 , V_1351 L_150 ,
F_524 ( V_9 ) , V_9 -> V_768 , V_9 -> V_207 ) ;
return - V_607 ;
}
V_17 = F_467 ( V_9 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_671 ( & V_9 -> V_80 , F_259 ( 64 ) ) ) {
V_1344 = 1 ;
} else {
V_17 = F_671 ( & V_9 -> V_80 , F_259 ( 32 ) ) ;
if ( V_17 ) {
F_442 ( & V_9 -> V_80 ,
L_151 ) ;
goto V_1352;
}
V_1344 = 0 ;
}
V_17 = F_672 ( V_9 , V_1353 ) ;
if ( V_17 ) {
F_442 ( & V_9 -> V_80 ,
L_152 , V_17 ) ;
goto V_1354;
}
F_673 ( V_9 ) ;
F_468 ( V_9 ) ;
F_466 ( V_9 ) ;
if ( V_764 -> V_113 == V_114 ) {
#ifdef F_388
V_472 = 4 * V_660 ;
#else
V_472 = V_1355 ;
#endif
}
V_62 = F_674 ( sizeof( struct V_1 ) , V_472 ) ;
if ( ! V_62 ) {
V_17 = - V_595 ;
goto V_1356;
}
F_675 ( V_62 , & V_9 -> V_80 ) ;
V_2 = F_88 ( V_62 ) ;
V_2 -> V_62 = V_62 ;
V_2 -> V_9 = V_9 ;
V_14 = & V_2 -> V_14 ;
V_14 -> V_40 = V_2 ;
V_2 -> V_1357 = F_676 ( V_1358 , V_1359 ) ;
V_14 -> V_41 = F_677 ( F_678 ( V_9 , 0 ) ,
F_679 ( V_9 , 0 ) ) ;
V_2 -> V_425 = V_14 -> V_41 ;
if ( ! V_14 -> V_41 ) {
V_17 = - V_809 ;
goto V_1360;
}
V_62 -> V_1361 = & V_1362 ;
F_680 ( V_62 ) ;
V_62 -> V_1363 = 5 * V_1028 ;
F_681 ( V_62 -> V_60 , F_524 ( V_9 ) , sizeof( V_62 -> V_60 ) ) ;
V_14 -> V_113 . V_353 = * V_764 -> V_1364 ;
V_14 -> V_113 . type = V_764 -> V_113 ;
V_14 -> V_1365 = V_764 -> V_1365 ;
if ( V_764 -> V_1366 )
V_14 -> V_395 . V_353 = * V_764 -> V_1366 ;
V_14 -> V_1367 . V_353 = * V_764 -> V_1368 ;
V_1350 = F_40 ( V_14 , F_682 ( V_14 ) ) ;
if ( F_22 ( V_14 -> V_41 ) ) {
V_17 = - V_809 ;
goto V_1360;
}
if ( ! ( V_1350 & F_209 ( 8 ) ) )
V_14 -> V_1367 . V_353 . V_256 = & V_1369 ;
V_14 -> V_46 . V_353 = * V_764 -> V_1370 ;
V_14 -> V_46 . V_1024 = V_1371 ;
V_14 -> V_46 . V_1173 . V_1171 = V_1372 ;
V_14 -> V_46 . V_1173 . V_1373 = 0 ;
V_14 -> V_46 . V_1173 . V_1374 = V_1375 | V_1376 ;
V_14 -> V_46 . V_1173 . V_80 = V_62 ;
V_14 -> V_46 . V_1173 . V_1377 = F_595 ;
V_14 -> V_46 . V_1173 . V_1378 = F_596 ;
V_17 = F_426 ( V_2 , V_764 ) ;
if ( V_17 )
goto V_1379;
if ( V_14 -> V_113 . V_353 . V_1380 )
V_14 -> V_113 . V_353 . V_1380 ( V_14 ) ;
switch ( V_2 -> V_14 . V_113 . type ) {
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
F_75 ( & V_2 -> V_14 , V_827 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_143 & V_361 ) {
T_1 V_719 = F_40 ( V_14 , V_720 ) ;
if ( V_719 & V_721 )
F_217 ( V_186 , L_72 ) ;
}
if ( V_1381 )
V_14 -> V_1381 = V_1381 ;
V_14 -> V_46 . V_1382 = true ;
V_17 = V_14 -> V_113 . V_353 . V_1383 ( V_14 ) ;
V_14 -> V_46 . V_1382 = false ;
F_423 ( V_2 ) ;
if ( V_17 == V_728 ) {
V_17 = 0 ;
} else if ( V_17 == V_729 ) {
F_18 ( L_153 ) ;
F_18 ( L_154 ) ;
goto V_1379;
} else if ( V_17 ) {
F_18 ( L_155 , V_17 ) ;
goto V_1379;
}
#ifdef F_318
if ( V_2 -> V_14 . V_113 . type == V_114 )
goto V_1384;
F_683 ( V_14 ) ;
V_14 -> V_1385 . V_353 = V_764 -> V_1386 ;
F_684 ( V_9 , V_801 ) ;
F_685 ( V_2 ) ;
V_1384:
#endif
V_62 -> V_214 = V_1387 |
V_1310 |
V_1311 |
V_215 |
V_231 |
V_1307 ;
#define F_686 (NETIF_F_GSO_GRE | \
NETIF_F_GSO_GRE_CSUM | \
NETIF_F_GSO_IPXIP4 | \
NETIF_F_GSO_IPXIP6 | \
NETIF_F_GSO_UDP_TUNNEL | \
NETIF_F_GSO_UDP_TUNNEL_CSUM)
V_62 -> V_1388 = F_686 ;
V_62 -> V_214 |= V_1389 |
F_686 ;
if ( V_14 -> V_113 . type >= V_116 )
V_62 -> V_214 |= V_1308 ;
V_62 -> V_1390 |= V_62 -> V_214 |
V_627 |
V_268 |
V_1309 |
V_293 |
V_1391 ;
if ( V_14 -> V_113 . type >= V_116 )
V_62 -> V_1390 |= V_1266 |
V_1267 ;
if ( V_1344 )
V_62 -> V_214 |= V_1392 ;
V_62 -> V_1393 |= V_62 -> V_214 | V_1313 ;
V_62 -> V_1394 |= V_62 -> V_1393 ;
V_62 -> V_1395 |= V_1307 ;
V_62 -> V_214 |= V_627 |
V_268 |
V_1309 ;
V_62 -> V_1396 |= V_1397 ;
V_62 -> V_1396 |= V_1398 ;
V_62 -> V_1399 = V_1400 ;
V_62 -> V_1401 = V_1402 - ( V_536 + V_537 ) ;
#ifdef F_388
if ( V_2 -> V_143 & V_760 )
V_62 -> V_1403 = & V_1404 ;
#endif
#ifdef F_181
if ( V_2 -> V_143 & V_783 ) {
unsigned int V_1405 ;
if ( V_14 -> V_113 . V_353 . V_1406 ) {
V_14 -> V_113 . V_353 . V_1406 ( V_14 , & V_1349 ) ;
if ( V_1349 & V_1407 )
V_2 -> V_143 &= ~ V_783 ;
}
V_1405 = F_336 ( int , V_1408 , F_428 () ) ;
V_2 -> V_441 [ V_1142 ] . V_776 = V_1405 ;
V_62 -> V_214 |= V_1162 |
V_1163 ;
V_62 -> V_1393 |= V_1162 |
V_1163 |
V_640 ;
}
#endif
if ( V_2 -> V_347 & V_777 )
V_62 -> V_1390 |= V_1262 ;
if ( V_2 -> V_347 & V_549 )
V_62 -> V_214 |= V_1262 ;
if ( V_14 -> V_1367 . V_353 . V_1409 ( V_14 , NULL ) < 0 ) {
F_18 ( L_156 ) ;
V_17 = - V_809 ;
goto V_1379;
}
F_687 ( & V_2 -> V_9 -> V_80 ,
V_2 -> V_14 . V_113 . V_1410 ) ;
memcpy ( V_62 -> V_689 , V_14 -> V_113 . V_1410 , V_62 -> V_1170 ) ;
if ( ! F_382 ( V_62 -> V_689 ) ) {
F_18 ( L_157 ) ;
V_17 = - V_809 ;
goto V_1379;
}
F_328 ( V_14 -> V_113 . V_602 , V_14 -> V_113 . V_1410 ) ;
F_325 ( V_2 ) ;
F_688 ( & V_2 -> V_722 , & F_532 ,
( unsigned long ) V_2 ) ;
if ( F_22 ( V_14 -> V_41 ) ) {
V_17 = - V_809 ;
goto V_1379;
}
F_689 ( & V_2 -> V_39 , F_536 ) ;
F_92 ( V_42 , & V_2 -> V_35 ) ;
F_37 ( V_37 , & V_2 -> V_35 ) ;
V_17 = F_471 ( V_2 ) ;
if ( V_17 )
goto V_1379;
V_2 -> V_735 = 0 ;
V_14 -> V_1367 . V_353 . V_256 ( V_14 , 0x2c , & V_2 -> V_1318 ) ;
V_14 -> V_1411 = F_668 ( V_2 , V_9 -> V_207 ,
V_9 -> V_774 ) ;
if ( V_14 -> V_1411 )
V_2 -> V_735 = V_1412 ;
F_690 ( & V_2 -> V_9 -> V_80 , V_2 -> V_735 ) ;
V_14 -> V_1367 . V_353 . V_256 ( V_14 , 0x2e , & V_2 -> V_1413 ) ;
V_14 -> V_1367 . V_353 . V_256 ( V_14 , 0x2d , & V_2 -> V_1414 ) ;
if ( F_8 ( V_14 ) )
F_5 ( V_2 ) ;
else
V_14 -> V_113 . V_353 . V_1415 ( V_14 ) ;
switch ( V_14 -> V_113 . type ) {
case V_114 :
V_24 = F_245 ( F_667 ( V_2 ) * 10 , 16 ) ;
break;
default:
V_24 = F_667 ( V_2 ) * 10 ;
break;
}
if ( V_24 > 0 )
F_9 ( V_2 , V_24 ) ;
V_17 = F_691 ( V_14 , V_1346 , sizeof( V_1346 ) ) ;
if ( V_17 )
F_681 ( V_1346 , L_7 , sizeof( V_1346 ) ) ;
if ( F_221 ( V_14 ) && V_14 -> V_46 . V_1024 != V_1416 )
F_12 ( L_158 ,
V_14 -> V_113 . type , V_14 -> V_46 . type , V_14 -> V_46 . V_1024 ,
V_1346 ) ;
else
F_12 ( L_159 ,
V_14 -> V_113 . type , V_14 -> V_46 . type , V_1346 ) ;
F_12 ( L_160 , V_62 -> V_689 ) ;
V_17 = V_14 -> V_113 . V_353 . V_1417 ( V_14 ) ;
if ( V_17 == V_731 ) {
F_11 ( L_93
L_161
L_162
L_163
L_97
L_98 ) ;
}
strcpy ( V_62 -> V_60 , L_164 ) ;
V_17 = F_692 ( V_62 ) ;
if ( V_17 )
goto V_1418;
F_693 ( V_9 , V_2 ) ;
if ( V_14 -> V_113 . V_353 . V_740 )
V_14 -> V_113 . V_353 . V_740 ( V_14 ) ;
F_417 ( V_62 ) ;
#ifdef F_242
if ( F_129 ( & V_9 -> V_80 ) == 0 ) {
V_2 -> V_143 |= V_192 ;
F_126 ( V_2 ) ;
}
#endif
if ( V_2 -> V_143 & V_436 ) {
F_108 ( V_186 , L_165 , V_2 -> V_318 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_318 ; V_49 ++ )
F_694 ( V_9 , ( V_49 | 0x10000000 ) ) ;
}
if ( V_14 -> V_113 . V_353 . V_1419 )
V_14 -> V_113 . V_353 . V_1419 ( V_14 , 0xFF , 0xFF , 0xFF , 0xFF ,
sizeof( V_1420 ) - 1 ,
V_1420 ) ;
F_602 ( V_62 ) ;
F_12 ( L_71 , V_1421 ) ;
#ifdef F_695
if ( F_696 ( V_2 ) )
F_106 ( V_186 , L_166 ) ;
#endif
F_697 ( V_2 ) ;
if ( F_698 ( V_14 ) && F_221 ( V_14 ) && V_14 -> V_113 . V_353 . V_700 )
V_14 -> V_113 . V_353 . V_700 ( V_14 ,
V_975 | V_1000 ,
true ) ;
return 0 ;
V_1418:
F_74 ( V_2 ) ;
F_477 ( V_2 ) ;
V_1379:
F_699 ( V_2 ) ;
V_2 -> V_347 &= ~ V_695 ;
F_700 ( V_2 -> V_425 ) ;
F_251 ( V_2 -> V_785 [ 0 ] ) ;
F_251 ( V_2 -> V_597 ) ;
V_1360:
V_1348 = ! F_15 ( V_826 , & V_2 -> V_35 ) ;
F_701 ( V_62 ) ;
V_1356:
F_702 ( V_9 ) ;
V_1354:
V_1352:
if ( ! V_2 || V_1348 )
F_478 ( V_9 ) ;
return V_17 ;
}
static void F_703 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_463 ( V_9 ) ;
struct V_61 * V_62 ;
bool V_1348 ;
int V_49 ;
if ( ! V_2 )
return;
V_62 = V_2 -> V_62 ;
F_704 ( V_2 ) ;
F_92 ( V_36 , & V_2 -> V_35 ) ;
F_705 ( & V_2 -> V_39 ) ;
#ifdef F_242
if ( V_2 -> V_143 & V_192 ) {
V_2 -> V_143 &= ~ V_192 ;
F_130 ( & V_9 -> V_80 ) ;
F_75 ( & V_2 -> V_14 , V_203 ,
V_205 ) ;
}
#endif
#ifdef F_695
F_706 ( V_2 ) ;
#endif
F_604 ( V_62 ) ;
#ifdef F_318
F_699 ( V_2 ) ;
#endif
if ( V_62 -> V_1025 == V_1026 )
F_530 ( V_62 ) ;
F_477 ( V_2 ) ;
F_74 ( V_2 ) ;
#ifdef F_707
F_251 ( V_2 -> V_142 ) ;
F_251 ( V_2 -> V_645 ) ;
#endif
F_700 ( V_2 -> V_425 ) ;
F_702 ( V_9 ) ;
F_12 ( L_167 ) ;
for ( V_49 = 0 ; V_49 < V_789 ; V_49 ++ ) {
if ( V_2 -> V_785 [ V_49 ] ) {
F_251 ( V_2 -> V_785 [ V_49 ] -> V_1103 ) ;
F_251 ( V_2 -> V_785 [ V_49 ] -> V_123 ) ;
}
F_251 ( V_2 -> V_785 [ V_49 ] ) ;
}
F_251 ( V_2 -> V_597 ) ;
V_1348 = ! F_15 ( V_826 , & V_2 -> V_35 ) ;
F_701 ( V_62 ) ;
F_708 ( V_9 ) ;
if ( V_1348 )
F_478 ( V_9 ) ;
}
static T_20 F_709 ( struct V_5 * V_9 ,
T_21 V_35 )
{
struct V_1 * V_2 = F_463 ( V_9 ) ;
struct V_61 * V_62 = V_2 -> V_62 ;
#ifdef F_318
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_1422 , * V_1008 ;
T_1 V_1423 , V_1424 , V_1425 , V_1426 ;
int V_1011 , V_1427 ;
T_2 V_1428 , V_1429 ;
if ( V_2 -> V_14 . V_113 . type == V_114 ||
V_2 -> V_318 == 0 )
goto V_1430;
V_1422 = V_9 -> V_10 -> V_12 ;
while ( V_1422 && ( F_710 ( V_1422 ) != V_1431 ) )
V_1422 = V_1422 -> V_10 -> V_12 ;
if ( ! V_1422 )
goto V_1430;
V_1427 = F_711 ( V_1422 , V_1432 ) ;
if ( ! V_1427 )
goto V_1430;
V_1423 = F_30 ( V_14 , V_1427 + V_1433 ) ;
V_1424 = F_30 ( V_14 , V_1427 + V_1433 + 4 ) ;
V_1425 = F_30 ( V_14 , V_1427 + V_1433 + 8 ) ;
V_1426 = F_30 ( V_14 , V_1427 + V_1433 + 12 ) ;
if ( F_22 ( V_14 -> V_41 ) )
goto V_1430;
V_1428 = V_1424 >> 16 ;
if ( ! ( V_1428 & 0x0080 ) )
goto V_1430;
V_1429 = V_1428 & 0x01 ;
if ( ( V_1429 & 1 ) == ( V_9 -> V_1434 & 1 ) ) {
unsigned int V_21 ;
V_1011 = ( V_1428 & 0x7F ) >> 1 ;
F_18 ( L_168 , V_1011 ) ;
F_18 ( L_169
L_170 ,
V_1423 , V_1424 , V_1425 , V_1426 ) ;
switch ( V_2 -> V_14 . V_113 . type ) {
case V_116 :
V_21 = V_1435 ;
break;
case V_117 :
V_21 = V_1436 ;
break;
case V_118 :
V_21 = V_1437 ;
break;
case V_119 :
V_21 = V_1438 ;
break;
case V_120 :
V_21 = V_1439 ;
break;
default:
V_21 = 0 ;
break;
}
V_1008 = F_712 ( V_1440 , V_21 , NULL ) ;
while ( V_1008 ) {
if ( V_1008 -> V_1434 == ( V_1428 & 0xFF ) )
break;
V_1008 = F_712 ( V_1440 ,
V_21 , V_1008 ) ;
}
if ( V_1008 ) {
F_522 ( V_2 , V_1008 ) ;
F_713 ( V_1008 ) ;
}
F_714 ( V_9 ) ;
}
V_2 -> V_1441 ++ ;
return V_1442 ;
V_1430:
#endif
if ( ! F_14 ( V_42 , & V_2 -> V_35 ) )
return V_1443 ;
F_470 () ;
F_476 ( V_62 ) ;
if ( V_35 == V_1444 ) {
F_473 () ;
return V_1443 ;
}
if ( F_61 ( V_62 ) )
F_457 ( V_2 ) ;
if ( ! F_15 ( V_826 , & V_2 -> V_35 ) )
F_478 ( V_9 ) ;
F_473 () ;
return V_1445 ;
}
static T_20 F_715 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_463 ( V_9 ) ;
T_20 V_1446 ;
int V_17 ;
if ( F_467 ( V_9 ) ) {
F_106 ( V_186 , L_171 ) ;
V_1446 = V_1443 ;
} else {
F_36 () ;
F_37 ( V_826 , & V_2 -> V_35 ) ;
V_2 -> V_14 . V_41 = V_2 -> V_425 ;
F_468 ( V_9 ) ;
F_465 ( V_9 ) ;
F_466 ( V_9 ) ;
F_469 ( V_9 , false ) ;
F_407 ( V_2 ) ;
F_75 ( & V_2 -> V_14 , V_827 , ~ 0 ) ;
V_1446 = V_1442 ;
}
V_17 = F_714 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_172
L_173 , V_17 ) ;
}
return V_1446 ;
}
static void F_716 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_463 ( V_9 ) ;
struct V_61 * V_62 = V_2 -> V_62 ;
#ifdef F_318
if ( V_2 -> V_1441 ) {
F_108 ( V_160 , L_174 ) ;
V_2 -> V_1441 -- ;
return;
}
#endif
F_470 () ;
if ( F_61 ( V_62 ) )
F_454 ( V_62 ) ;
F_472 ( V_62 ) ;
F_473 () ;
}
static int T_22 F_717 ( void )
{
int V_611 ;
F_54 ( L_175 , V_1447 , V_1420 ) ;
F_54 ( L_71 , V_1448 ) ;
V_38 = F_718 ( V_1353 ) ;
if ( ! V_38 ) {
F_55 ( L_176 , V_1353 ) ;
return - V_595 ;
}
F_719 () ;
V_611 = F_720 ( & V_1449 ) ;
if ( V_611 ) {
F_721 ( V_38 ) ;
F_722 () ;
return V_611 ;
}
#ifdef F_242
F_723 ( & V_1450 ) ;
#endif
return 0 ;
}
static void T_23 F_724 ( void )
{
#ifdef F_242
F_725 ( & V_1450 ) ;
#endif
F_726 ( & V_1449 ) ;
F_722 () ;
if ( V_38 ) {
F_721 ( V_38 ) ;
V_38 = NULL ;
}
}
static int F_727 ( struct V_1451 * V_1452 , unsigned long V_208 ,
void * V_1166 )
{
int V_1453 ;
V_1453 = F_728 ( & V_1449 . V_1454 , NULL , & V_208 ,
F_127 ) ;
return V_1453 ? V_1455 : V_1456 ;
}
