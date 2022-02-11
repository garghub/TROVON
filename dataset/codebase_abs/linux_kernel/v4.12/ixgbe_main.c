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
int V_49 ;
char V_56 [ 16 ] ;
T_1 V_57 [ 64 ] ;
switch ( V_55 -> V_58 ) {
case F_39 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_57 [ V_49 ] = F_40 ( V_14 , F_39 ( V_49 ) ) ;
break;
case F_41 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_57 [ V_49 ] = F_40 ( V_14 , F_41 ( V_49 ) ) ;
break;
case F_42 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_57 [ V_49 ] = F_40 ( V_14 , F_42 ( V_49 ) ) ;
break;
case F_43 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_57 [ V_49 ] = F_40 ( V_14 , F_43 ( V_49 ) ) ;
break;
case F_44 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_57 [ V_49 ] = F_40 ( V_14 , F_44 ( V_49 ) ) ;
break;
case F_45 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_57 [ V_49 ] = F_40 ( V_14 , F_45 ( V_49 ) ) ;
break;
case F_46 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_57 [ V_49 ] = F_40 ( V_14 , F_46 ( V_49 ) ) ;
break;
case F_47 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_57 [ V_49 ] = F_40 ( V_14 , F_47 ( V_49 ) ) ;
break;
case F_48 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_57 [ V_49 ] = F_40 ( V_14 , F_48 ( V_49 ) ) ;
break;
case F_49 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_57 [ V_49 ] = F_40 ( V_14 , F_49 ( V_49 ) ) ;
break;
case F_50 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_57 [ V_49 ] = F_40 ( V_14 , F_50 ( V_49 ) ) ;
break;
case F_51 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_57 [ V_49 ] = F_40 ( V_14 , F_51 ( V_49 ) ) ;
break;
case F_52 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_57 [ V_49 ] = F_40 ( V_14 , F_52 ( V_49 ) ) ;
break;
case F_53 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_57 [ V_49 ] = F_40 ( V_14 , F_53 ( V_49 ) ) ;
break;
default:
F_54 ( L_15 ,
V_55 -> V_59 , F_40 ( V_14 , V_55 -> V_58 ) ) ;
return;
}
V_49 = 0 ;
while ( V_49 < 64 ) {
int V_60 ;
char V_61 [ 9 * 8 + 1 ] ;
char * V_62 = V_61 ;
snprintf ( V_56 , 16 , L_16 , V_55 -> V_59 , V_49 , V_49 + 7 ) ;
for ( V_60 = 0 ; V_60 < 8 ; V_60 ++ )
V_62 += sprintf ( V_62 , L_17 , V_57 [ V_49 ++ ] ) ;
F_55 ( L_18 , V_56 , V_61 ) ;
}
}
static void F_56 ( struct V_63 * V_64 , int V_65 )
{
struct V_66 * V_67 ;
V_67 = & V_64 -> V_68 [ V_64 -> V_69 ] ;
F_54 ( L_19 ,
V_65 , V_64 -> V_70 , V_64 -> V_69 ,
( V_71 ) F_57 ( V_67 , V_72 ) ,
F_58 ( V_67 , V_73 ) ,
V_67 -> V_74 ,
( V_71 ) V_67 -> V_75 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_55 ;
int V_65 = 0 ;
struct V_63 * V_64 ;
struct V_66 * V_67 ;
union V_78 * V_79 ;
struct V_80 { V_71 V_81 ; V_71 V_82 ; } * V_83 ;
struct V_63 * V_84 ;
union V_85 * V_86 ;
struct V_87 * V_88 ;
int V_49 = 0 ;
if ( ! F_60 ( V_2 ) )
return;
if ( V_77 ) {
F_61 ( & V_2 -> V_9 -> V_89 , L_20 ) ;
F_54 ( L_21
L_22 ) ;
F_54 ( L_23 ,
V_77 -> V_59 ,
V_77 -> V_35 ,
F_62 ( V_77 ) ) ;
}
F_61 ( & V_2 -> V_9 -> V_89 , L_24 ) ;
F_54 ( L_25 ) ;
for ( V_55 = (struct V_54 * ) V_90 ;
V_55 -> V_59 ; V_55 ++ ) {
F_38 ( V_14 , V_55 ) ;
}
if ( ! V_77 || ! F_63 ( V_77 ) )
return;
F_61 ( & V_2 -> V_9 -> V_89 , L_26 ) ;
F_54 ( L_27 ,
L_28 ,
L_29 , L_30 , L_31 ) ;
for ( V_65 = 0 ; V_65 < V_2 -> V_91 ; V_65 ++ ) {
V_64 = V_2 -> V_92 [ V_65 ] ;
F_56 ( V_64 , V_65 ) ;
}
for ( V_65 = 0 ; V_65 < V_2 -> V_93 ; V_65 ++ ) {
V_64 = V_2 -> V_94 [ V_65 ] ;
F_56 ( V_64 , V_65 ) ;
}
if ( ! F_64 ( V_2 ) )
goto V_95;
F_61 ( & V_2 -> V_9 -> V_89 , L_32 ) ;
for ( V_65 = 0 ; V_65 < V_2 -> V_91 ; V_65 ++ ) {
V_64 = V_2 -> V_92 [ V_65 ] ;
F_54 ( L_33 ) ;
F_54 ( L_34 , V_64 -> V_96 ) ;
F_54 ( L_33 ) ;
F_54 ( L_35 ,
L_36 ,
L_37 ,
L_29 , L_30 , L_31 , L_38 ) ;
for ( V_49 = 0 ; V_64 -> V_97 && ( V_49 < V_64 -> V_98 ) ; V_49 ++ ) {
V_79 = F_65 ( V_64 , V_49 ) ;
V_67 = & V_64 -> V_68 [ V_49 ] ;
V_83 = (struct V_80 * ) V_79 ;
if ( F_58 ( V_67 , V_73 ) > 0 ) {
const char * V_99 ;
if ( V_49 == V_64 -> V_70 &&
V_49 == V_64 -> V_69 )
V_99 = L_39 ;
else if ( V_49 == V_64 -> V_70 )
V_99 = L_40 ;
else if ( V_49 == V_64 -> V_69 )
V_99 = L_41 ;
else
V_99 = L_42 ;
F_54 ( L_43 ,
V_49 ,
F_66 ( V_83 -> V_81 ) ,
F_66 ( V_83 -> V_82 ) ,
( V_71 ) F_57 ( V_67 , V_72 ) ,
F_58 ( V_67 , V_73 ) ,
V_67 -> V_74 ,
( V_71 ) V_67 -> V_75 ,
V_67 -> V_100 ,
V_99 ) ;
if ( F_67 ( V_2 ) &&
V_67 -> V_100 )
F_68 ( V_101 , L_42 ,
V_102 , 16 , 1 ,
V_67 -> V_100 -> V_103 ,
F_58 ( V_67 , V_73 ) ,
true ) ;
}
}
}
V_95:
F_61 ( & V_2 -> V_9 -> V_89 , L_44 ) ;
F_54 ( L_45 ) ;
for ( V_65 = 0 ; V_65 < V_2 -> V_104 ; V_65 ++ ) {
V_84 = V_2 -> V_84 [ V_65 ] ;
F_54 ( L_46 ,
V_65 , V_84 -> V_70 , V_84 -> V_69 ) ;
}
if ( ! F_69 ( V_2 ) )
return;
F_61 ( & V_2 -> V_9 -> V_89 , L_47 ) ;
for ( V_65 = 0 ; V_65 < V_2 -> V_104 ; V_65 ++ ) {
V_84 = V_2 -> V_84 [ V_65 ] ;
F_54 ( L_33 ) ;
F_54 ( L_48 , V_84 -> V_96 ) ;
F_54 ( L_33 ) ;
F_54 ( L_49 ,
L_50 ,
L_51 ,
L_52 ) ;
F_54 ( L_49 ,
L_53 ,
L_54 ,
L_55 ) ;
for ( V_49 = 0 ; V_49 < V_84 -> V_98 ; V_49 ++ ) {
const char * V_99 ;
if ( V_49 == V_84 -> V_70 )
V_99 = L_40 ;
else if ( V_49 == V_84 -> V_69 )
V_99 = L_41 ;
else
V_99 = L_42 ;
V_88 = & V_84 -> V_88 [ V_49 ] ;
V_86 = F_70 ( V_84 , V_49 ) ;
V_83 = (struct V_80 * ) V_86 ;
if ( V_86 -> V_105 . V_106 . V_107 ) {
F_54 ( L_56 ,
V_49 ,
F_66 ( V_83 -> V_81 ) ,
F_66 ( V_83 -> V_82 ) ,
V_88 -> V_100 ,
V_99 ) ;
} else {
F_54 ( L_57 ,
V_49 ,
F_66 ( V_83 -> V_81 ) ,
F_66 ( V_83 -> V_82 ) ,
( V_71 ) V_88 -> V_72 ,
V_88 -> V_100 ,
V_99 ) ;
if ( F_67 ( V_2 ) &&
V_88 -> V_72 ) {
F_68 ( V_101 , L_42 ,
V_102 , 16 , 1 ,
F_71 ( V_88 -> V_108 ) +
V_88 -> V_109 ,
F_72 ( V_84 ) , true ) ;
}
}
}
}
}
static void F_73 ( struct V_1 * V_2 )
{
T_1 V_110 ;
V_110 = F_40 ( & V_2 -> V_14 , V_111 ) ;
F_74 ( & V_2 -> V_14 , V_111 ,
V_110 & ~ V_112 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
T_1 V_110 ;
V_110 = F_40 ( & V_2 -> V_14 , V_111 ) ;
F_74 ( & V_2 -> V_14 , V_111 ,
V_110 | V_112 ) ;
}
static void F_76 ( struct V_1 * V_2 , T_6 V_113 ,
T_4 V_114 , T_4 V_115 )
{
T_1 V_116 , V_117 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_115 |= V_120 ;
if ( V_113 == - 1 )
V_113 = 0 ;
V_117 = ( ( ( V_113 * 64 ) + V_114 ) >> 2 ) & 0x1F ;
V_116 = F_40 ( V_14 , F_77 ( V_117 ) ) ;
V_116 &= ~ ( 0xFF << ( 8 * ( V_114 & 0x3 ) ) ) ;
V_116 |= ( V_115 << ( 8 * ( V_114 & 0x3 ) ) ) ;
F_74 ( V_14 , F_77 ( V_117 ) , V_116 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
if ( V_113 == - 1 ) {
V_115 |= V_120 ;
V_117 = ( ( V_114 & 1 ) * 8 ) ;
V_116 = F_40 ( & V_2 -> V_14 , V_126 ) ;
V_116 &= ~ ( 0xFF << V_117 ) ;
V_116 |= ( V_115 << V_117 ) ;
F_74 ( & V_2 -> V_14 , V_126 , V_116 ) ;
break;
} else {
V_115 |= V_120 ;
V_117 = ( ( 16 * ( V_114 & 1 ) ) + ( 8 * V_113 ) ) ;
V_116 = F_40 ( V_14 , F_77 ( V_114 >> 1 ) ) ;
V_116 &= ~ ( 0xFF << V_117 ) ;
V_116 |= ( V_115 << V_117 ) ;
F_74 ( V_14 , F_77 ( V_114 >> 1 ) , V_116 ) ;
break;
}
default:
break;
}
}
static inline void F_78 ( struct V_1 * V_2 ,
V_71 V_127 )
{
T_1 V_128 ;
switch ( V_2 -> V_14 . V_118 . type ) {
case V_119 :
V_128 = ( V_129 & V_127 ) ;
F_74 ( & V_2 -> V_14 , V_130 , V_128 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_128 = ( V_127 & 0xFFFFFFFF ) ;
F_74 ( & V_2 -> V_14 , F_79 ( 0 ) , V_128 ) ;
V_128 = ( V_127 >> 32 ) ;
F_74 ( & V_2 -> V_14 , F_79 ( 1 ) , V_128 ) ;
break;
default:
break;
}
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_131 * V_132 = & V_2 -> V_133 ;
int V_49 ;
T_1 V_103 ;
if ( ( V_14 -> V_134 . V_135 != V_136 ) &&
( V_14 -> V_134 . V_135 != V_137 ) )
return;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_103 = F_40 ( V_14 , V_138 ) ;
break;
default:
V_103 = F_40 ( V_14 , V_139 ) ;
}
V_132 -> V_140 += V_103 ;
if ( ! V_103 )
return;
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ )
F_37 ( V_141 ,
& V_2 -> V_92 [ V_49 ] -> V_35 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ )
F_37 ( V_141 ,
& V_2 -> V_94 [ V_49 ] -> V_35 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_131 * V_132 = & V_2 -> V_133 ;
T_1 V_142 [ 8 ] = { 0 } ;
T_4 V_143 ;
int V_49 ;
bool V_144 = V_2 -> V_145 . V_146 ;
if ( V_2 -> V_147 )
V_144 |= ! ! ( V_2 -> V_147 -> V_144 ) ;
if ( ! ( V_2 -> V_148 & V_149 ) || ! V_144 ) {
F_80 ( V_2 ) ;
return;
}
for ( V_49 = 0 ; V_49 < V_150 ; V_49 ++ ) {
T_1 V_151 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_151 = F_40 ( V_14 , F_82 ( V_49 ) ) ;
break;
default:
V_151 = F_40 ( V_14 , F_83 ( V_49 ) ) ;
}
V_132 -> V_151 [ V_49 ] += V_151 ;
V_143 = F_84 ( V_2 -> V_77 , V_49 ) ;
V_142 [ V_143 ] += V_151 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ ) {
struct V_63 * V_92 = V_2 -> V_92 [ V_49 ] ;
V_143 = V_92 -> V_152 ;
if ( V_142 [ V_143 ] )
F_37 ( V_141 , & V_92 -> V_35 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ ) {
struct V_63 * V_94 = V_2 -> V_94 [ V_49 ] ;
V_143 = V_94 -> V_152 ;
if ( V_142 [ V_143 ] )
F_37 ( V_141 , & V_94 -> V_35 ) ;
}
}
static V_71 F_85 ( struct V_63 * V_64 )
{
return V_64 -> V_133 . V_153 ;
}
static V_71 F_86 ( struct V_63 * V_64 )
{
struct V_1 * V_2 ;
struct V_15 * V_14 ;
T_1 V_154 , V_155 ;
if ( V_64 -> V_156 )
V_2 = V_64 -> V_156 -> V_157 ;
else
V_2 = F_87 ( V_64 -> V_77 ) ;
V_14 = & V_2 -> V_14 ;
V_154 = F_40 ( V_14 , F_51 ( V_64 -> V_158 ) ) ;
V_155 = F_40 ( V_14 , F_52 ( V_64 -> V_158 ) ) ;
if ( V_154 != V_155 )
return ( V_154 < V_155 ) ?
V_155 - V_154 : ( V_155 + V_64 -> V_98 - V_154 ) ;
return 0 ;
}
static inline bool F_88 ( struct V_63 * V_92 )
{
T_1 V_159 = F_85 ( V_92 ) ;
T_1 V_160 = V_92 -> V_161 . V_160 ;
T_1 V_162 = F_86 ( V_92 ) ;
F_89 ( V_92 ) ;
if ( V_160 == V_159 && V_162 )
return F_15 ( V_141 ,
& V_92 -> V_35 ) ;
V_92 -> V_161 . V_160 = V_159 ;
F_37 ( V_141 , & V_92 -> V_35 ) ;
return false ;
}
static void F_90 ( struct V_1 * V_2 )
{
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_91 ( V_163 , & V_2 -> V_35 ) ;
F_27 ( V_164 , L_58 ) ;
F_13 ( V_2 ) ;
}
}
static int F_92 ( struct V_76 * V_77 ,
int V_96 , T_1 V_165 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_166 = F_93 ( V_2 ) ;
if ( ! V_165 )
return 0 ;
V_166 <<= V_167 ;
V_166 /= V_165 ;
V_166 &= V_168 |
V_169 ;
V_166 |= V_170 ;
F_74 ( V_14 , V_171 , V_96 ) ;
F_74 ( V_14 , V_172 , V_166 ) ;
return 0 ;
}
static bool F_94 ( struct V_173 * V_174 ,
struct V_63 * V_92 , int V_175 )
{
struct V_1 * V_2 = V_174 -> V_2 ;
struct V_66 * V_67 ;
union V_78 * V_79 ;
unsigned int V_176 = 0 , V_177 = 0 ;
unsigned int V_178 = V_174 -> V_179 . V_180 ;
unsigned int V_49 = V_92 -> V_69 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return true ;
V_67 = & V_92 -> V_68 [ V_49 ] ;
V_79 = F_65 ( V_92 , V_49 ) ;
V_49 -= V_92 -> V_98 ;
do {
union V_78 * V_181 = V_67 -> V_74 ;
if ( ! V_181 )
break;
F_95 () ;
if ( ! ( V_181 -> V_105 . V_182 & F_96 ( V_183 ) ) )
break;
V_67 -> V_74 = NULL ;
V_176 += V_67 -> V_184 ;
V_177 += V_67 -> V_185 ;
if ( F_97 ( V_92 ) )
F_98 ( V_67 -> V_103 ) ;
else
F_99 ( V_67 -> V_100 , V_175 ) ;
F_100 ( V_92 -> V_89 ,
F_57 ( V_67 , V_72 ) ,
F_58 ( V_67 , V_73 ) ,
V_186 ) ;
F_101 ( V_67 , V_73 , 0 ) ;
while ( V_79 != V_181 ) {
V_67 ++ ;
V_79 ++ ;
V_49 ++ ;
if ( F_23 ( ! V_49 ) ) {
V_49 -= V_92 -> V_98 ;
V_67 = V_92 -> V_68 ;
V_79 = F_65 ( V_92 , 0 ) ;
}
if ( F_58 ( V_67 , V_73 ) ) {
F_102 ( V_92 -> V_89 ,
F_57 ( V_67 , V_72 ) ,
F_58 ( V_67 , V_73 ) ,
V_186 ) ;
F_101 ( V_67 , V_73 , 0 ) ;
}
}
V_67 ++ ;
V_79 ++ ;
V_49 ++ ;
if ( F_23 ( ! V_49 ) ) {
V_49 -= V_92 -> V_98 ;
V_67 = V_92 -> V_68 ;
V_79 = F_65 ( V_92 , 0 ) ;
}
F_103 ( V_79 ) ;
V_178 -- ;
} while ( F_25 ( V_178 ) );
V_49 += V_92 -> V_98 ;
V_92 -> V_69 = V_49 ;
F_104 ( & V_92 -> V_187 ) ;
V_92 -> V_133 . V_188 += V_176 ;
V_92 -> V_133 . V_153 += V_177 ;
F_105 ( & V_92 -> V_187 ) ;
V_174 -> V_179 . V_176 += V_176 ;
V_174 -> V_179 . V_177 += V_177 ;
if ( F_106 ( V_92 ) && F_88 ( V_92 ) ) {
struct V_15 * V_14 = & V_2 -> V_14 ;
F_107 ( V_164 , L_59
L_60
L_61
L_62
L_63
L_64
L_65
L_66 ,
F_97 ( V_92 ) ? L_67 : L_42 ,
V_92 -> V_96 ,
F_40 ( V_14 , F_51 ( V_92 -> V_158 ) ) ,
F_40 ( V_14 , F_52 ( V_92 -> V_158 ) ) ,
V_92 -> V_70 , V_49 ,
V_92 -> V_68 [ V_49 ] . V_75 , V_189 ) ;
if ( ! F_97 ( V_92 ) )
F_108 ( V_92 -> V_77 ,
V_92 -> V_96 ) ;
F_109 ( V_190 ,
L_68 ,
V_2 -> V_191 + 1 , V_92 -> V_96 ) ;
F_90 ( V_2 ) ;
return true ;
}
if ( F_97 ( V_92 ) )
return ! ! V_178 ;
F_110 ( F_111 ( V_92 ) ,
V_177 , V_176 ) ;
#define F_112 (DESC_NEEDED * 2)
if ( F_23 ( V_177 && F_113 ( V_92 -> V_77 ) &&
( F_114 ( V_92 ) >= F_112 ) ) ) {
F_115 () ;
if ( F_116 ( V_92 -> V_77 ,
V_92 -> V_96 )
&& ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_117 ( V_92 -> V_77 ,
V_92 -> V_96 ) ;
++ V_92 -> V_161 . V_192 ;
}
}
return ! ! V_178 ;
}
static void F_118 ( struct V_1 * V_2 ,
struct V_63 * V_92 ,
int V_193 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_194 = 0 ;
T_2 V_195 ;
if ( V_2 -> V_148 & V_196 )
V_194 = F_119 ( V_92 -> V_89 , V_193 ) ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_195 = F_120 ( V_92 -> V_158 ) ;
break;
case V_121 :
case V_122 :
V_195 = F_121 ( V_92 -> V_158 ) ;
V_194 <<= V_197 ;
break;
default:
return;
}
V_194 |= V_198 |
V_199 |
V_200 ;
F_74 ( V_14 , V_195 , V_194 ) ;
}
static void F_122 ( struct V_1 * V_2 ,
struct V_63 * V_84 ,
int V_193 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_201 = 0 ;
T_4 V_158 = V_84 -> V_158 ;
if ( V_2 -> V_148 & V_196 )
V_201 = F_119 ( V_84 -> V_89 , V_193 ) ;
switch ( V_14 -> V_118 . type ) {
case V_121 :
case V_122 :
V_201 <<= V_202 ;
break;
default:
break;
}
V_201 |= V_203 |
V_204 |
V_205 ;
F_74 ( V_14 , F_41 ( V_158 ) , V_201 ) ;
}
static void F_123 ( struct V_173 * V_174 )
{
struct V_1 * V_2 = V_174 -> V_2 ;
struct V_63 * V_64 ;
int V_193 = F_124 () ;
if ( V_174 -> V_193 == V_193 )
goto V_206;
F_125 (ring, q_vector->tx)
F_118 ( V_2 , V_64 , V_193 ) ;
F_125 (ring, q_vector->rx)
F_122 ( V_2 , V_64 , V_193 ) ;
V_174 -> V_193 = V_193 ;
V_206:
F_126 () ;
}
static void F_127 ( struct V_1 * V_2 )
{
int V_49 ;
if ( V_2 -> V_148 & V_196 )
F_74 ( & V_2 -> V_14 , V_207 ,
V_208 ) ;
else
F_74 ( & V_2 -> V_14 , V_207 ,
V_209 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_210 ; V_49 ++ ) {
V_2 -> V_174 [ V_49 ] -> V_193 = - 1 ;
F_123 ( V_2 -> V_174 [ V_49 ] ) ;
}
}
static int F_128 ( struct V_211 * V_89 , void * V_103 )
{
struct V_1 * V_2 = F_129 ( V_89 ) ;
unsigned long V_212 = * ( unsigned long * ) V_103 ;
if ( ! ( V_2 -> V_148 & V_213 ) )
return 0 ;
switch ( V_212 ) {
case V_214 :
if ( V_2 -> V_148 & V_196 )
break;
if ( F_130 ( V_89 ) == 0 ) {
V_2 -> V_148 |= V_196 ;
F_74 ( & V_2 -> V_14 , V_207 ,
V_208 ) ;
break;
}
case V_215 :
if ( V_2 -> V_148 & V_196 ) {
F_131 ( V_89 ) ;
V_2 -> V_148 &= ~ V_196 ;
F_74 ( & V_2 -> V_14 , V_207 ,
V_209 ) ;
}
break;
}
return 0 ;
}
static inline void F_132 ( struct V_63 * V_64 ,
union V_85 * V_86 ,
struct V_216 * V_100 )
{
T_2 V_217 ;
if ( ! ( V_64 -> V_77 -> V_218 & V_219 ) )
return;
V_217 = F_133 ( V_86 -> V_105 . V_220 . V_221 . V_222 . V_223 ) &
V_224 ;
if ( ! V_217 )
return;
F_134 ( V_100 , F_135 ( V_86 -> V_105 . V_220 . V_225 . V_226 ) ,
( V_227 & ( 1ul << V_217 ) ) ?
V_228 : V_229 ) ;
}
static inline bool F_136 ( struct V_63 * V_64 ,
union V_85 * V_86 )
{
T_7 V_223 = V_86 -> V_105 . V_220 . V_221 . V_222 . V_223 ;
return F_14 ( V_230 , & V_64 -> V_35 ) &&
( ( V_223 & F_137 ( V_231 ) ) ==
( F_137 ( V_232 <<
V_233 ) ) ) ;
}
static inline void F_138 ( struct V_63 * V_64 ,
union V_85 * V_86 ,
struct V_216 * V_100 )
{
T_7 V_223 = V_86 -> V_105 . V_220 . V_221 . V_222 . V_223 ;
bool V_234 = false ;
F_139 ( V_100 ) ;
if ( ! ( V_64 -> V_77 -> V_218 & V_235 ) )
return;
if ( V_223 & F_137 ( V_236 ) ) {
V_234 = true ;
V_100 -> V_237 = 1 ;
}
if ( F_140 ( V_86 , V_238 ) &&
F_140 ( V_86 , V_239 ) ) {
V_64 -> V_240 . V_241 ++ ;
return;
}
if ( ! F_140 ( V_86 , V_242 ) )
return;
if ( F_140 ( V_86 , V_243 ) ) {
if ( ( V_223 & F_137 ( V_244 ) ) &&
F_14 ( V_245 , & V_64 -> V_35 ) )
return;
V_64 -> V_240 . V_241 ++ ;
return;
}
V_100 -> V_246 = V_247 ;
if ( V_234 ) {
if ( ! F_140 ( V_86 , V_248 ) )
return;
if ( F_140 ( V_86 , V_249 ) ) {
V_100 -> V_246 = V_250 ;
return;
}
V_100 -> V_251 = 1 ;
}
}
static inline unsigned int F_141 ( struct V_63 * V_84 )
{
return F_142 ( V_84 ) ? V_252 : 0 ;
}
static bool F_143 ( struct V_63 * V_84 ,
struct V_87 * V_253 )
{
struct V_108 * V_108 = V_253 -> V_108 ;
T_8 V_72 ;
if ( F_25 ( V_108 ) )
return true ;
V_108 = F_144 ( F_145 ( V_84 ) ) ;
if ( F_23 ( ! V_108 ) ) {
V_84 -> V_240 . V_254 ++ ;
return false ;
}
V_72 = F_146 ( V_84 -> V_89 , V_108 , 0 ,
F_147 ( V_84 ) ,
V_255 ,
V_256 ) ;
if ( F_148 ( V_84 -> V_89 , V_72 ) ) {
F_149 ( V_108 , F_145 ( V_84 ) ) ;
V_84 -> V_240 . V_254 ++ ;
return false ;
}
V_253 -> V_72 = V_72 ;
V_253 -> V_108 = V_108 ;
V_253 -> V_109 = F_141 ( V_84 ) ;
V_253 -> V_257 = 1 ;
return true ;
}
void F_150 ( struct V_63 * V_84 , T_2 V_258 )
{
union V_85 * V_86 ;
struct V_87 * V_253 ;
T_2 V_49 = V_84 -> V_70 ;
T_2 V_259 ;
if ( ! V_258 )
return;
V_86 = F_70 ( V_84 , V_49 ) ;
V_253 = & V_84 -> V_88 [ V_49 ] ;
V_49 -= V_84 -> V_98 ;
V_259 = F_72 ( V_84 ) ;
do {
if ( ! F_143 ( V_84 , V_253 ) )
break;
F_151 ( V_84 -> V_89 , V_253 -> V_72 ,
V_253 -> V_109 , V_259 ,
V_255 ) ;
V_86 -> V_260 . V_261 = F_152 ( V_253 -> V_72 + V_253 -> V_109 ) ;
V_86 ++ ;
V_253 ++ ;
V_49 ++ ;
if ( F_23 ( ! V_49 ) ) {
V_86 = F_70 ( V_84 , 0 ) ;
V_253 = V_84 -> V_88 ;
V_49 -= V_84 -> V_98 ;
}
V_86 -> V_105 . V_106 . V_107 = 0 ;
V_258 -- ;
} while ( V_258 );
V_49 += V_84 -> V_98 ;
if ( V_84 -> V_70 != V_49 ) {
V_84 -> V_70 = V_49 ;
V_84 -> V_262 = V_49 ;
F_153 () ;
F_154 ( V_49 , V_84 -> V_155 ) ;
}
}
static void F_155 ( struct V_63 * V_64 ,
struct V_216 * V_100 )
{
T_2 V_263 = F_156 ( V_100 ) ;
F_157 ( V_100 ) -> V_264 = F_158 ( ( V_100 -> V_73 - V_263 ) ,
F_159 ( V_100 ) -> V_265 ) ;
F_157 ( V_100 ) -> V_266 = V_267 ;
}
static void F_160 ( struct V_63 * V_84 ,
struct V_216 * V_100 )
{
if ( ! F_159 ( V_100 ) -> V_265 )
return;
V_84 -> V_240 . V_268 += F_159 ( V_100 ) -> V_265 ;
V_84 -> V_240 . V_269 ++ ;
F_155 ( V_84 , V_100 ) ;
F_159 ( V_100 ) -> V_265 = 0 ;
}
static void F_161 ( struct V_63 * V_84 ,
union V_85 * V_86 ,
struct V_216 * V_100 )
{
struct V_76 * V_89 = V_84 -> V_77 ;
T_1 V_148 = V_84 -> V_174 -> V_2 -> V_148 ;
F_160 ( V_84 , V_100 ) ;
F_132 ( V_84 , V_86 , V_100 ) ;
F_138 ( V_84 , V_86 , V_100 ) ;
if ( F_23 ( V_148 & V_270 ) )
F_162 ( V_84 , V_86 , V_100 ) ;
if ( ( V_89 -> V_218 & V_271 ) &&
F_140 ( V_86 , V_272 ) ) {
T_2 V_273 = F_133 ( V_86 -> V_105 . V_106 . V_274 ) ;
F_163 ( V_100 , F_164 ( V_275 ) , V_273 ) ;
}
F_165 ( V_100 , V_84 -> V_96 ) ;
V_100 -> V_276 = F_166 ( V_100 , V_89 ) ;
}
static void F_167 ( struct V_173 * V_174 ,
struct V_216 * V_100 )
{
F_168 ( & V_174 -> V_277 , V_100 ) ;
}
static bool F_169 ( struct V_63 * V_84 ,
union V_85 * V_86 ,
struct V_216 * V_100 )
{
T_1 V_278 = V_84 -> V_69 + 1 ;
V_278 = ( V_278 < V_84 -> V_98 ) ? V_278 : 0 ;
V_84 -> V_69 = V_278 ;
F_103 ( F_70 ( V_84 , V_278 ) ) ;
if ( F_170 ( V_84 ) ) {
T_9 V_279 = V_86 -> V_105 . V_220 . V_221 . V_103 &
F_96 ( V_280 ) ;
if ( F_23 ( V_279 ) ) {
T_1 V_281 = F_135 ( V_279 ) ;
V_281 >>= V_282 ;
F_159 ( V_100 ) -> V_265 += V_281 - 1 ;
V_278 = F_135 ( V_86 -> V_105 . V_106 . V_283 ) ;
V_278 &= V_284 ;
V_278 >>= V_285 ;
}
}
if ( F_25 ( F_140 ( V_86 , V_286 ) ) )
return false ;
V_84 -> V_88 [ V_278 ] . V_100 = V_100 ;
V_84 -> V_240 . V_287 ++ ;
return true ;
}
static void F_171 ( struct V_63 * V_84 ,
struct V_216 * V_100 )
{
struct V_288 * V_289 = & F_157 ( V_100 ) -> V_290 [ 0 ] ;
unsigned char * V_291 ;
unsigned int V_292 ;
V_291 = F_172 ( V_289 ) ;
V_292 = F_173 ( V_291 , V_293 ) ;
F_174 ( V_100 , V_291 , F_175 ( V_292 , sizeof( long ) ) ) ;
F_176 ( V_289 , V_292 ) ;
V_289 -> V_109 += V_292 ;
V_100 -> V_294 -= V_292 ;
V_100 -> V_155 += V_292 ;
}
static void F_177 ( struct V_63 * V_84 ,
struct V_216 * V_100 )
{
if ( F_23 ( F_159 ( V_100 ) -> V_295 ) ) {
F_178 ( V_84 -> V_89 , F_159 ( V_100 ) -> V_72 ,
F_147 ( V_84 ) ,
V_255 ,
V_256 ) ;
} else {
struct V_288 * V_289 = & F_157 ( V_100 ) -> V_290 [ 0 ] ;
F_179 ( V_84 -> V_89 ,
F_159 ( V_100 ) -> V_72 ,
V_289 -> V_109 ,
F_180 ( V_289 ) ,
V_255 ) ;
}
}
static bool F_181 ( struct V_63 * V_84 ,
union V_85 * V_86 ,
struct V_216 * V_100 )
{
struct V_76 * V_77 = V_84 -> V_77 ;
if ( F_182 ( V_100 ) )
return true ;
if ( F_23 ( F_140 ( V_86 ,
V_296 ) &&
! ( V_77 -> V_218 & V_297 ) ) ) {
F_183 ( V_100 ) ;
return true ;
}
if ( ! F_156 ( V_100 ) )
F_171 ( V_84 , V_100 ) ;
#ifdef F_184
if ( F_136 ( V_84 , V_86 ) )
return false ;
#endif
if ( F_185 ( V_100 ) )
return true ;
return false ;
}
static void F_186 ( struct V_63 * V_84 ,
struct V_87 * V_298 )
{
struct V_87 * V_299 ;
T_2 V_300 = V_84 -> V_262 ;
V_299 = & V_84 -> V_88 [ V_300 ] ;
V_300 ++ ;
V_84 -> V_262 = ( V_300 < V_84 -> V_98 ) ? V_300 : 0 ;
V_299 -> V_72 = V_298 -> V_72 ;
V_299 -> V_108 = V_298 -> V_108 ;
V_299 -> V_109 = V_298 -> V_109 ;
V_299 -> V_257 = V_298 -> V_257 ;
}
static inline bool F_187 ( struct V_108 * V_108 )
{
return ( F_188 ( V_108 ) != F_189 () ) || F_190 ( V_108 ) ;
}
static bool F_191 ( struct V_87 * V_301 )
{
unsigned int V_257 = V_301 -> V_257 ;
struct V_108 * V_108 = V_301 -> V_108 ;
if ( F_23 ( F_187 ( V_108 ) ) )
return false ;
#if ( V_302 < 8192 )
if ( F_23 ( ( F_192 ( V_108 ) - V_257 ) > 1 ) )
return false ;
#else
#define F_193 \
(SKB_WITH_OVERHEAD(PAGE_SIZE) - IXGBE_RXBUFFER_3K)
if ( V_301 -> V_109 > F_193 )
return false ;
#endif
if ( F_23 ( ! V_257 ) ) {
F_194 ( V_108 , V_303 ) ;
V_301 -> V_257 = V_303 ;
}
return true ;
}
static void F_195 ( struct V_63 * V_84 ,
struct V_87 * V_301 ,
struct V_216 * V_100 ,
unsigned int V_304 )
{
#if ( V_302 < 8192 )
unsigned int V_305 = F_147 ( V_84 ) / 2 ;
#else
unsigned int V_305 = F_142 ( V_84 ) ?
F_196 ( V_252 + V_304 ) :
F_196 ( V_304 ) ;
#endif
F_197 ( V_100 , F_157 ( V_100 ) -> V_306 , V_301 -> V_108 ,
V_301 -> V_109 , V_304 , V_305 ) ;
#if ( V_302 < 8192 )
V_301 -> V_109 ^= V_305 ;
#else
V_301 -> V_109 += V_305 ;
#endif
}
static struct V_87 * F_198 ( struct V_63 * V_84 ,
union V_85 * V_86 ,
struct V_216 * * V_100 ,
const unsigned int V_304 )
{
struct V_87 * V_301 ;
V_301 = & V_84 -> V_88 [ V_84 -> V_69 ] ;
F_199 ( V_301 -> V_108 ) ;
* V_100 = V_301 -> V_100 ;
if ( ! F_140 ( V_86 , V_286 ) ) {
if ( ! * V_100 )
goto V_307;
} else {
if ( * V_100 )
F_177 ( V_84 , * V_100 ) ;
}
F_179 ( V_84 -> V_89 ,
V_301 -> V_72 ,
V_301 -> V_109 ,
V_304 ,
V_255 ) ;
V_307:
V_301 -> V_257 -- ;
return V_301 ;
}
static void F_200 ( struct V_63 * V_84 ,
struct V_87 * V_301 ,
struct V_216 * V_100 )
{
if ( F_191 ( V_301 ) ) {
F_186 ( V_84 , V_301 ) ;
} else {
if ( ! F_182 ( V_100 ) && F_159 ( V_100 ) -> V_72 == V_301 -> V_72 ) {
F_159 ( V_100 ) -> V_295 = true ;
} else {
F_178 ( V_84 -> V_89 , V_301 -> V_72 ,
F_147 ( V_84 ) ,
V_255 ,
V_256 ) ;
}
F_201 ( V_301 -> V_108 ,
V_301 -> V_257 ) ;
}
V_301 -> V_108 = NULL ;
V_301 -> V_100 = NULL ;
}
static struct V_216 * F_202 ( struct V_63 * V_84 ,
struct V_87 * V_301 ,
struct V_308 * V_309 ,
union V_85 * V_86 )
{
unsigned int V_304 = V_309 -> V_310 - V_309 -> V_103 ;
#if ( V_302 < 8192 )
unsigned int V_305 = F_147 ( V_84 ) / 2 ;
#else
unsigned int V_305 = F_196 ( V_309 -> V_310 -
V_309 -> V_311 ) ;
#endif
struct V_216 * V_100 ;
F_103 ( V_309 -> V_103 ) ;
#if V_312 < 128
F_103 ( V_309 -> V_103 + V_312 ) ;
#endif
V_100 = F_203 ( & V_84 -> V_174 -> V_277 , V_293 ) ;
if ( F_23 ( ! V_100 ) )
return NULL ;
if ( V_304 > V_293 ) {
if ( ! F_140 ( V_86 , V_286 ) )
F_159 ( V_100 ) -> V_72 = V_301 -> V_72 ;
F_197 ( V_100 , 0 , V_301 -> V_108 ,
V_309 -> V_103 - F_71 ( V_301 -> V_108 ) ,
V_304 , V_305 ) ;
#if ( V_302 < 8192 )
V_301 -> V_109 ^= V_305 ;
#else
V_301 -> V_109 += V_305 ;
#endif
} else {
memcpy ( F_204 ( V_100 , V_304 ) ,
V_309 -> V_103 , F_175 ( V_304 , sizeof( long ) ) ) ;
V_301 -> V_257 ++ ;
}
return V_100 ;
}
static struct V_216 * F_205 ( struct V_63 * V_84 ,
struct V_87 * V_301 ,
struct V_308 * V_309 ,
union V_85 * V_86 )
{
#if ( V_302 < 8192 )
unsigned int V_305 = F_147 ( V_84 ) / 2 ;
#else
unsigned int V_305 = F_196 ( sizeof( struct V_313 ) ) +
F_196 ( V_309 -> V_310 -
V_309 -> V_311 ) ;
#endif
struct V_216 * V_100 ;
F_103 ( V_309 -> V_103 ) ;
#if V_312 < 128
F_103 ( V_309 -> V_103 + V_312 ) ;
#endif
V_100 = F_206 ( V_309 -> V_311 , V_305 ) ;
if ( F_23 ( ! V_100 ) )
return NULL ;
F_207 ( V_100 , V_309 -> V_103 - V_309 -> V_311 ) ;
F_204 ( V_100 , V_309 -> V_310 - V_309 -> V_103 ) ;
if ( ! F_140 ( V_86 , V_286 ) )
F_159 ( V_100 ) -> V_72 = V_301 -> V_72 ;
#if ( V_302 < 8192 )
V_301 -> V_109 ^= V_305 ;
#else
V_301 -> V_109 += V_305 ;
#endif
return V_100 ;
}
static struct V_216 * F_208 ( struct V_1 * V_2 ,
struct V_63 * V_84 ,
struct V_308 * V_309 )
{
int V_314 = V_315 ;
struct V_316 * V_317 ;
T_1 V_318 ;
F_209 () ;
V_317 = F_210 ( V_84 -> V_317 ) ;
if ( ! V_317 )
goto V_319;
V_318 = F_211 ( V_317 , V_309 ) ;
switch ( V_318 ) {
case V_320 :
break;
case V_321 :
V_314 = F_212 ( V_2 , V_309 ) ;
break;
default:
F_213 ( V_318 ) ;
case V_322 :
F_214 ( V_84 -> V_77 , V_317 , V_318 ) ;
case V_323 :
V_314 = V_324 ;
break;
}
V_319:
F_215 () ;
return F_216 ( - V_314 ) ;
}
static void F_217 ( struct V_63 * V_84 ,
struct V_87 * V_301 ,
unsigned int V_304 )
{
#if ( V_302 < 8192 )
unsigned int V_305 = F_147 ( V_84 ) / 2 ;
V_301 -> V_109 ^= V_305 ;
#else
unsigned int V_305 = F_142 ( V_84 ) ?
F_196 ( V_252 + V_304 ) :
F_196 ( V_304 ) ;
V_301 -> V_109 += V_305 ;
#endif
}
static int F_218 ( struct V_173 * V_174 ,
struct V_63 * V_84 ,
const int V_178 )
{
unsigned int V_325 = 0 , V_326 = 0 ;
struct V_1 * V_2 = V_174 -> V_2 ;
#ifdef F_184
int V_327 ;
unsigned int V_328 = 0 ;
#endif
T_2 V_258 = F_114 ( V_84 ) ;
bool V_329 = false ;
while ( F_25 ( V_326 < V_178 ) ) {
union V_85 * V_86 ;
struct V_87 * V_301 ;
struct V_216 * V_100 ;
struct V_308 V_309 ;
unsigned int V_304 ;
if ( V_258 >= V_330 ) {
F_150 ( V_84 , V_258 ) ;
V_258 = 0 ;
}
V_86 = F_70 ( V_84 , V_84 -> V_69 ) ;
V_304 = F_133 ( V_86 -> V_105 . V_106 . V_107 ) ;
if ( ! V_304 )
break;
F_219 () ;
V_301 = F_198 ( V_84 , V_86 , & V_100 , V_304 ) ;
if ( ! V_100 ) {
V_309 . V_103 = F_71 ( V_301 -> V_108 ) +
V_301 -> V_109 ;
V_309 . V_311 = V_309 . V_103 -
F_141 ( V_84 ) ;
V_309 . V_310 = V_309 . V_103 + V_304 ;
V_100 = F_208 ( V_2 , V_84 , & V_309 ) ;
}
if ( F_182 ( V_100 ) ) {
if ( F_220 ( V_100 ) == - V_331 ) {
V_329 = true ;
F_217 ( V_84 , V_301 , V_304 ) ;
} else {
V_301 -> V_257 ++ ;
}
V_326 ++ ;
V_325 += V_304 ;
} else if ( V_100 ) {
F_195 ( V_84 , V_301 , V_100 , V_304 ) ;
} else if ( F_142 ( V_84 ) ) {
V_100 = F_205 ( V_84 , V_301 ,
& V_309 , V_86 ) ;
} else {
V_100 = F_202 ( V_84 , V_301 ,
& V_309 , V_86 ) ;
}
if ( ! V_100 ) {
V_84 -> V_240 . V_332 ++ ;
V_301 -> V_257 ++ ;
break;
}
F_200 ( V_84 , V_301 , V_100 ) ;
V_258 ++ ;
if ( F_169 ( V_84 , V_86 , V_100 ) )
continue;
if ( F_181 ( V_84 , V_86 , V_100 ) )
continue;
V_325 += V_100 -> V_73 ;
F_161 ( V_84 , V_86 , V_100 ) ;
#ifdef F_184
if ( F_136 ( V_84 , V_86 ) ) {
V_327 = F_221 ( V_2 , V_86 , V_100 ) ;
if ( V_327 > 0 ) {
if ( ! V_328 ) {
V_328 = V_84 -> V_77 -> V_333 -
sizeof( struct V_334 ) -
sizeof( struct V_335 ) -
sizeof( struct V_336 ) ;
if ( V_328 > 512 )
V_328 &= ~ 511 ;
}
V_325 += V_327 ;
V_326 += F_158 ( V_327 ,
V_328 ) ;
}
if ( ! V_327 ) {
F_183 ( V_100 ) ;
continue;
}
}
#endif
F_167 ( V_174 , V_100 ) ;
V_326 ++ ;
}
if ( V_329 ) {
struct V_63 * V_64 = V_2 -> V_94 [ F_222 () ] ;
F_153 () ;
F_154 ( V_64 -> V_70 , V_64 -> V_155 ) ;
}
F_104 ( & V_84 -> V_187 ) ;
V_84 -> V_133 . V_153 += V_326 ;
V_84 -> V_133 . V_188 += V_325 ;
F_105 ( & V_84 -> V_187 ) ;
V_174 -> V_337 . V_177 += V_326 ;
V_174 -> V_337 . V_176 += V_325 ;
return V_326 ;
}
static void F_223 ( struct V_1 * V_2 )
{
struct V_173 * V_174 ;
int V_338 ;
T_1 V_128 ;
if ( V_2 -> V_339 > 32 ) {
T_1 V_340 = F_224 ( V_2 -> V_339 - 32 ) - 1 ;
F_74 ( & V_2 -> V_14 , V_341 , V_340 ) ;
}
for ( V_338 = 0 ; V_338 < V_2 -> V_210 ; V_338 ++ ) {
struct V_63 * V_64 ;
V_174 = V_2 -> V_174 [ V_338 ] ;
F_125 (ring, q_vector->rx)
F_76 ( V_2 , 0 , V_64 -> V_158 , V_338 ) ;
F_125 (ring, q_vector->tx)
F_76 ( V_2 , 1 , V_64 -> V_158 , V_338 ) ;
F_225 ( V_174 ) ;
}
switch ( V_2 -> V_14 . V_118 . type ) {
case V_119 :
F_76 ( V_2 , - 1 , V_342 ,
V_338 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
F_76 ( V_2 , - 1 , 1 , V_338 ) ;
break;
default:
break;
}
F_74 ( & V_2 -> V_14 , F_226 ( V_338 ) , 1950 ) ;
V_128 = V_343 ;
V_128 &= ~ ( V_344 |
V_345 |
V_346 ) ;
F_74 ( & V_2 -> V_14 , V_347 , V_128 ) ;
}
static void F_227 ( struct V_173 * V_174 ,
struct V_348 * V_349 )
{
int V_188 = V_349 -> V_176 ;
int V_153 = V_349 -> V_177 ;
T_1 V_350 ;
V_71 V_351 ;
T_4 V_352 = V_349 -> V_353 ;
if ( V_153 == 0 )
return;
V_350 = V_174 -> V_353 >> 2 ;
if ( V_350 == 0 )
return;
V_351 = V_188 / V_350 ;
switch ( V_352 ) {
case V_354 :
if ( V_351 > 10 )
V_352 = V_355 ;
break;
case V_355 :
if ( V_351 > 20 )
V_352 = V_356 ;
else if ( V_351 <= 10 )
V_352 = V_354 ;
break;
case V_356 :
if ( V_351 <= 20 )
V_352 = V_355 ;
break;
}
V_349 -> V_176 = 0 ;
V_349 -> V_177 = 0 ;
V_349 -> V_353 = V_352 ;
}
void F_225 ( struct V_173 * V_174 )
{
struct V_1 * V_2 = V_174 -> V_2 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_338 = V_174 -> V_338 ;
T_1 V_357 = V_174 -> V_353 & V_358 ;
switch ( V_2 -> V_14 . V_118 . type ) {
case V_119 :
V_357 |= ( V_357 << 16 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_357 |= V_359 ;
break;
default:
break;
}
F_74 ( V_14 , F_226 ( V_338 ) , V_357 ) ;
}
static void F_228 ( struct V_173 * V_174 )
{
T_1 V_360 = V_174 -> V_353 ;
T_4 V_361 ;
F_227 ( V_174 , & V_174 -> V_179 ) ;
F_227 ( V_174 , & V_174 -> V_337 ) ;
V_361 = F_229 ( V_174 -> V_337 . V_353 , V_174 -> V_179 . V_353 ) ;
switch ( V_361 ) {
case V_354 :
V_360 = V_362 ;
break;
case V_355 :
V_360 = V_363 ;
break;
case V_356 :
V_360 = V_364 ;
break;
default:
break;
}
if ( V_360 != V_174 -> V_353 ) {
V_360 = ( 10 * V_360 * V_174 -> V_353 ) /
( ( 9 * V_360 ) + V_174 -> V_353 ) ;
V_174 -> V_353 = V_360 ;
F_225 ( V_174 ) ;
}
}
static void F_230 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_365 = V_2 -> V_366 ;
T_3 V_367 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
if ( ! ( V_2 -> V_368 & V_369 ) &&
! ( V_2 -> V_368 & V_370 ) )
return;
V_2 -> V_368 &= ~ V_370 ;
switch ( V_14 -> V_21 ) {
case V_371 :
if ( ! ( V_365 & V_372 ) &&
! ( V_365 & V_373 ) )
return;
if ( ! ( V_365 & V_373 ) && V_14 -> V_118 . V_374 . V_375 ) {
T_1 V_20 ;
bool V_376 = false ;
V_14 -> V_118 . V_374 . V_375 ( V_14 , & V_20 , & V_376 , false ) ;
if ( V_376 )
return;
}
if ( V_14 -> V_46 . V_374 . V_377 ( V_14 ) != V_378 )
return;
break;
case V_379 :
case V_380 :
V_367 = V_14 -> V_46 . V_374 . V_377 ( V_14 ) ;
if ( V_367 != V_378 )
return;
break;
default:
if ( V_2 -> V_14 . V_118 . type >= V_122 )
return;
if ( ! ( V_365 & F_231 ( V_14 ) ) )
return;
break;
}
F_232 ( V_164 , L_69 , V_381 ) ;
V_2 -> V_366 = 0 ;
}
static void F_233 ( struct V_1 * V_2 , T_1 V_365 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ( V_2 -> V_148 & V_382 ) &&
( V_365 & F_234 ( V_14 ) ) ) {
F_232 ( V_190 , L_70 ) ;
F_74 ( V_14 , V_383 , F_234 ( V_14 ) ) ;
}
}
static void F_235 ( struct V_1 * V_2 , T_1 V_365 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! ( V_2 -> V_368 & V_369 ) )
return;
switch ( V_2 -> V_14 . V_118 . type ) {
case V_121 :
if ( ( ( V_365 & F_231 ( V_14 ) ) ||
( V_365 & V_373 ) ) &&
( ! F_14 ( V_34 , & V_2 -> V_35 ) ) ) {
V_2 -> V_366 = V_365 ;
V_2 -> V_368 |= V_370 ;
F_13 ( V_2 ) ;
return;
}
return;
case V_125 :
if ( V_365 & V_384 ) {
V_2 -> V_366 = V_365 ;
V_2 -> V_368 |= V_370 ;
F_13 ( V_2 ) ;
F_74 ( & V_2 -> V_14 , V_385 ,
V_384 ) ;
F_74 ( & V_2 -> V_14 , V_383 ,
V_384 ) ;
}
return;
case V_123 :
case V_122 :
if ( ! ( V_365 & V_386 ) )
return;
break;
default:
return;
}
F_232 ( V_164 , L_69 , V_381 ) ;
}
static inline bool F_236 ( struct V_15 * V_14 )
{
switch ( V_14 -> V_118 . type ) {
case V_119 :
if ( V_14 -> V_46 . type == V_387 )
return true ;
return false ;
case V_121 :
case V_124 :
case V_125 :
switch ( V_14 -> V_118 . V_374 . V_388 ( V_14 ) ) {
case V_389 :
case V_390 :
return true ;
default:
return false ;
}
default:
return false ;
}
}
static void F_237 ( struct V_1 * V_2 , T_1 V_365 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_391 = F_238 ( V_14 ) ;
if ( ! F_236 ( V_14 ) )
return;
if ( V_14 -> V_118 . type >= V_122 )
V_391 = V_392 ;
if ( V_365 & V_391 ) {
F_74 ( V_14 , V_383 , V_391 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_368 |= V_393 ;
V_2 -> V_394 = 0 ;
F_13 ( V_2 ) ;
}
}
if ( V_2 -> V_14 . V_118 . type == V_121 &&
( V_365 & F_234 ( V_14 ) ) ) {
F_74 ( V_14 , V_383 , F_234 ( V_14 ) ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_148 |= V_395 ;
F_13 ( V_2 ) ;
}
}
}
static void F_239 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_396 ++ ;
V_2 -> V_148 |= V_397 ;
V_2 -> V_398 = V_189 ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_74 ( V_14 , V_385 , V_399 ) ;
F_240 ( V_14 ) ;
F_13 ( V_2 ) ;
}
}
static inline void F_241 ( struct V_1 * V_2 ,
V_71 V_127 )
{
T_1 V_128 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_128 = ( V_129 & V_127 ) ;
F_74 ( V_14 , V_400 , V_128 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_128 = ( V_127 & 0xFFFFFFFF ) ;
if ( V_128 )
F_74 ( V_14 , F_242 ( 0 ) , V_128 ) ;
V_128 = ( V_127 >> 32 ) ;
if ( V_128 )
F_74 ( V_14 , F_242 ( 1 ) , V_128 ) ;
break;
default:
break;
}
}
static inline void F_243 ( struct V_1 * V_2 ,
V_71 V_127 )
{
T_1 V_128 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_128 = ( V_129 & V_127 ) ;
F_74 ( V_14 , V_385 , V_128 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_128 = ( V_127 & 0xFFFFFFFF ) ;
if ( V_128 )
F_74 ( V_14 , F_244 ( 0 ) , V_128 ) ;
V_128 = ( V_127 >> 32 ) ;
if ( V_128 )
F_74 ( V_14 , F_244 ( 1 ) , V_128 ) ;
break;
default:
break;
}
}
static inline void F_245 ( struct V_1 * V_2 , bool V_401 ,
bool V_402 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_128 = ( V_343 & ~ V_129 ) ;
if ( V_2 -> V_148 & V_397 )
V_128 &= ~ V_346 ;
if ( V_2 -> V_368 & V_369 )
switch ( V_2 -> V_14 . V_118 . type ) {
case V_121 :
V_128 |= F_246 ( V_14 ) ;
break;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_128 |= V_403 ;
break;
default:
break;
}
if ( V_2 -> V_148 & V_382 )
V_128 |= F_247 ( V_14 ) ;
switch ( V_2 -> V_14 . V_118 . type ) {
case V_121 :
V_128 |= F_247 ( V_14 ) ;
V_128 |= F_248 ( V_14 ) ;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
if ( V_2 -> V_14 . V_21 == V_404 ||
V_2 -> V_14 . V_21 == V_405 ||
V_2 -> V_14 . V_21 == V_406 )
V_128 |= F_246 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_14 . V_46 . type == V_407 )
V_128 |= V_392 ;
V_128 |= V_408 ;
V_128 |= V_345 ;
break;
default:
break;
}
if ( ( V_2 -> V_148 & V_409 ) &&
! ( V_2 -> V_368 & V_410 ) )
V_128 |= V_411 ;
F_74 ( & V_2 -> V_14 , V_400 , V_128 ) ;
if ( V_401 )
F_241 ( V_2 , ~ 0 ) ;
if ( V_402 )
F_240 ( & V_2 -> V_14 ) ;
}
static T_10 F_249 ( int V_412 , void * V_103 )
{
struct V_1 * V_2 = V_103 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_365 ;
V_365 = F_40 ( V_14 , V_130 ) ;
V_365 &= 0xFFFF0000 ;
F_74 ( V_14 , V_383 , V_365 ) ;
if ( V_365 & V_373 )
F_239 ( V_2 ) ;
if ( V_365 & V_413 )
F_250 ( V_2 ) ;
switch ( V_14 -> V_118 . type ) {
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
if ( V_14 -> V_46 . type == V_407 &&
( V_365 & V_392 ) ) {
V_2 -> V_368 |= V_414 ;
F_13 ( V_2 ) ;
F_74 ( V_14 , V_383 ,
V_392 ) ;
}
if ( V_365 & V_415 ) {
F_109 ( V_416 , L_71 ) ;
F_91 ( V_163 , & V_2 -> V_35 ) ;
F_13 ( V_2 ) ;
F_74 ( V_14 , V_383 , V_415 ) ;
}
if ( V_365 & V_417 ) {
int V_418 = 0 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ ) {
struct V_63 * V_64 = V_2 -> V_92 [ V_49 ] ;
if ( F_251 ( V_419 ,
& V_64 -> V_35 ) )
V_418 ++ ;
}
if ( V_418 ) {
F_74 ( V_14 , V_385 , V_420 ) ;
V_2 -> V_368 |= V_410 ;
F_13 ( V_2 ) ;
}
}
F_237 ( V_2 , V_365 ) ;
F_235 ( V_2 , V_365 ) ;
break;
default:
break;
}
F_233 ( V_2 , V_365 ) ;
if ( F_23 ( V_365 & V_421 ) )
F_252 ( V_2 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_245 ( V_2 , false , false ) ;
return V_422 ;
}
static T_10 F_253 ( int V_412 , void * V_103 )
{
struct V_173 * V_174 = V_103 ;
if ( V_174 -> V_337 . V_64 || V_174 -> V_179 . V_64 )
F_254 ( & V_174 -> V_277 ) ;
return V_422 ;
}
int F_255 ( struct V_423 * V_277 , int V_178 )
{
struct V_173 * V_174 =
F_256 ( V_277 , struct V_173 , V_277 ) ;
struct V_1 * V_2 = V_174 -> V_2 ;
struct V_63 * V_64 ;
int V_424 , V_425 = 0 ;
bool V_426 = true ;
#ifdef F_257
if ( V_2 -> V_148 & V_196 )
F_123 ( V_174 ) ;
#endif
F_125 (ring, q_vector->tx) {
if ( ! F_94 ( V_174 , V_64 , V_178 ) )
V_426 = false ;
}
if ( V_178 <= 0 )
return V_178 ;
if ( V_174 -> V_337 . V_98 > 1 )
V_424 = F_229 ( V_178 / V_174 -> V_337 . V_98 , 1 ) ;
else
V_424 = V_178 ;
F_125 (ring, q_vector->rx) {
int V_427 = F_218 ( V_174 , V_64 ,
V_424 ) ;
V_425 += V_427 ;
if ( V_427 >= V_424 )
V_426 = false ;
}
if ( ! V_426 )
return V_178 ;
F_258 ( V_277 , V_425 ) ;
if ( V_2 -> V_428 & 1 )
F_228 ( V_174 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_241 ( V_2 , F_259 ( V_174 -> V_338 ) ) ;
return F_260 ( V_425 , V_178 - 1 ) ;
}
static int F_261 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
int V_429 , V_17 ;
int V_430 = 0 , V_431 = 0 ;
for ( V_429 = 0 ; V_429 < V_2 -> V_210 ; V_429 ++ ) {
struct V_173 * V_174 = V_2 -> V_174 [ V_429 ] ;
struct V_432 * V_433 = & V_2 -> V_434 [ V_429 ] ;
if ( V_174 -> V_179 . V_64 && V_174 -> V_337 . V_64 ) {
snprintf ( V_174 -> V_59 , sizeof( V_174 -> V_59 ) - 1 ,
L_72 , V_77 -> V_59 , L_73 , V_430 ++ ) ;
V_431 ++ ;
} else if ( V_174 -> V_337 . V_64 ) {
snprintf ( V_174 -> V_59 , sizeof( V_174 -> V_59 ) - 1 ,
L_72 , V_77 -> V_59 , L_74 , V_430 ++ ) ;
} else if ( V_174 -> V_179 . V_64 ) {
snprintf ( V_174 -> V_59 , sizeof( V_174 -> V_59 ) - 1 ,
L_72 , V_77 -> V_59 , L_75 , V_431 ++ ) ;
} else {
continue;
}
V_17 = F_262 ( V_433 -> V_429 , & F_253 , 0 ,
V_174 -> V_59 , V_174 ) ;
if ( V_17 ) {
F_107 ( V_190 , L_76
L_77 , V_17 ) ;
goto V_435;
}
if ( V_2 -> V_148 & V_409 ) {
F_263 ( V_433 -> V_429 ,
& V_174 -> V_436 ) ;
}
}
V_17 = F_262 ( V_2 -> V_434 [ V_429 ] . V_429 ,
F_249 , 0 , V_77 -> V_59 , V_2 ) ;
if ( V_17 ) {
F_107 ( V_190 , L_78 , V_17 ) ;
goto V_435;
}
return 0 ;
V_435:
while ( V_429 ) {
V_429 -- ;
F_263 ( V_2 -> V_434 [ V_429 ] . V_429 ,
NULL ) ;
F_264 ( V_2 -> V_434 [ V_429 ] . V_429 ,
V_2 -> V_174 [ V_429 ] ) ;
}
V_2 -> V_148 &= ~ V_437 ;
F_265 ( V_2 -> V_9 ) ;
F_266 ( V_2 -> V_434 ) ;
V_2 -> V_434 = NULL ;
return V_17 ;
}
static T_10 F_267 ( int V_412 , void * V_103 )
{
struct V_1 * V_2 = V_103 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_173 * V_174 = V_2 -> V_174 [ 0 ] ;
T_1 V_365 ;
F_74 ( V_14 , V_385 , V_438 ) ;
V_365 = F_40 ( V_14 , V_383 ) ;
if ( ! V_365 ) {
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_245 ( V_2 , true , true ) ;
return V_439 ;
}
if ( V_365 & V_373 )
F_239 ( V_2 ) ;
switch ( V_14 -> V_118 . type ) {
case V_121 :
F_237 ( V_2 , V_365 ) ;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
if ( V_365 & V_415 ) {
F_109 ( V_416 , L_71 ) ;
F_91 ( V_163 , & V_2 -> V_35 ) ;
F_13 ( V_2 ) ;
F_74 ( V_14 , V_383 , V_415 ) ;
}
F_235 ( V_2 , V_365 ) ;
break;
default:
break;
}
F_233 ( V_2 , V_365 ) ;
if ( F_23 ( V_365 & V_421 ) )
F_252 ( V_2 ) ;
F_254 ( & V_174 -> V_277 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_245 ( V_2 , false , false ) ;
return V_422 ;
}
static int F_268 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
int V_17 ;
if ( V_2 -> V_148 & V_437 )
V_17 = F_261 ( V_2 ) ;
else if ( V_2 -> V_148 & V_440 )
V_17 = F_262 ( V_2 -> V_9 -> V_412 , F_267 , 0 ,
V_77 -> V_59 , V_2 ) ;
else
V_17 = F_262 ( V_2 -> V_9 -> V_412 , F_267 , V_441 ,
V_77 -> V_59 , V_2 ) ;
if ( V_17 )
F_107 ( V_190 , L_79 , V_17 ) ;
return V_17 ;
}
static void F_269 ( struct V_1 * V_2 )
{
int V_429 ;
if ( ! ( V_2 -> V_148 & V_437 ) ) {
F_264 ( V_2 -> V_9 -> V_412 , V_2 ) ;
return;
}
if ( ! V_2 -> V_434 )
return;
for ( V_429 = 0 ; V_429 < V_2 -> V_210 ; V_429 ++ ) {
struct V_173 * V_174 = V_2 -> V_174 [ V_429 ] ;
struct V_432 * V_433 = & V_2 -> V_434 [ V_429 ] ;
if ( ! V_174 -> V_337 . V_64 && ! V_174 -> V_179 . V_64 )
continue;
F_263 ( V_433 -> V_429 , NULL ) ;
F_264 ( V_433 -> V_429 , V_174 ) ;
}
F_264 ( V_2 -> V_434 [ V_429 ] . V_429 , V_2 ) ;
}
static inline void F_270 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_118 . type ) {
case V_119 :
F_74 ( & V_2 -> V_14 , V_385 , ~ 0 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
F_74 ( & V_2 -> V_14 , V_385 , 0xFFFF0000 ) ;
F_74 ( & V_2 -> V_14 , F_244 ( 0 ) , ~ 0 ) ;
F_74 ( & V_2 -> V_14 , F_244 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_240 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_148 & V_437 ) {
int V_429 ;
for ( V_429 = 0 ; V_429 < V_2 -> V_210 ; V_429 ++ )
F_271 ( V_2 -> V_434 [ V_429 ] . V_429 ) ;
F_271 ( V_2 -> V_434 [ V_429 ++ ] . V_429 ) ;
} else {
F_271 ( V_2 -> V_9 -> V_412 ) ;
}
}
static void F_272 ( struct V_1 * V_2 )
{
struct V_173 * V_174 = V_2 -> V_174 [ 0 ] ;
F_225 ( V_174 ) ;
F_76 ( V_2 , 0 , 0 , 0 ) ;
F_76 ( V_2 , 1 , 0 , 0 ) ;
F_109 ( V_14 , L_80 ) ;
}
void F_273 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_71 V_442 = V_64 -> V_72 ;
int V_443 = 10 ;
T_1 V_444 = V_445 ;
T_4 V_158 = V_64 -> V_158 ;
F_74 ( V_14 , F_53 ( V_158 ) , 0 ) ;
F_240 ( V_14 ) ;
F_74 ( V_14 , F_48 ( V_158 ) ,
( V_442 & F_274 ( 32 ) ) ) ;
F_74 ( V_14 , F_49 ( V_158 ) , ( V_442 >> 32 ) ) ;
F_74 ( V_14 , F_50 ( V_158 ) ,
V_64 -> V_98 * sizeof( union V_78 ) ) ;
F_74 ( V_14 , F_51 ( V_158 ) , 0 ) ;
F_74 ( V_14 , F_52 ( V_158 ) , 0 ) ;
V_64 -> V_155 = V_2 -> V_446 + F_52 ( V_158 ) ;
if ( ! V_64 -> V_174 || ( V_64 -> V_174 -> V_353 < V_362 ) )
V_444 |= 1u << 16 ;
else
V_444 |= 8u << 16 ;
V_444 |= ( 1u << 8 ) |
32 ;
if ( V_2 -> V_148 & V_409 ) {
V_64 -> V_447 = V_2 -> V_447 ;
V_64 -> V_448 = 0 ;
F_91 ( V_419 , & V_64 -> V_35 ) ;
} else {
V_64 -> V_447 = 0 ;
}
if ( ! F_15 ( V_449 , & V_64 -> V_35 ) ) {
struct V_173 * V_174 = V_64 -> V_174 ;
if ( V_174 )
F_275 ( V_64 -> V_77 ,
& V_174 -> V_436 ,
V_64 -> V_96 ) ;
}
F_37 ( V_141 , & V_64 -> V_35 ) ;
memset ( V_64 -> V_68 , 0 ,
sizeof( struct V_66 ) * V_64 -> V_98 ) ;
F_74 ( V_14 , F_53 ( V_158 ) , V_444 ) ;
if ( V_14 -> V_118 . type == V_119 &&
! ( F_40 ( V_14 , V_450 ) & V_451 ) )
return;
do {
F_276 ( 1000 , 2000 ) ;
V_444 = F_40 ( V_14 , F_53 ( V_158 ) ) ;
} while ( -- V_443 && ! ( V_444 & V_445 ) );
if ( ! V_443 )
F_277 ( V_14 , L_81 , V_158 ) ;
}
static void F_278 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_452 , V_453 ;
T_4 V_454 = F_279 ( V_2 -> V_77 ) ;
if ( V_14 -> V_118 . type == V_119 )
return;
V_452 = F_40 ( V_14 , V_455 ) ;
V_452 |= V_456 ;
F_74 ( V_14 , V_455 , V_452 ) ;
if ( V_2 -> V_148 & V_457 ) {
V_453 = V_458 ;
if ( V_454 > 4 )
V_453 |= V_459 | V_460 ;
else if ( V_454 > 1 )
V_453 |= V_459 | V_461 ;
else if ( V_2 -> V_462 [ V_463 ] . V_128 ==
V_464 )
V_453 |= V_465 ;
else
V_453 |= V_466 ;
} else {
if ( V_454 > 4 )
V_453 = V_459 | V_460 ;
else if ( V_454 > 1 )
V_453 = V_459 | V_461 ;
else
V_453 = V_467 ;
}
F_74 ( V_14 , V_468 , V_453 ) ;
if ( V_454 ) {
T_1 V_469 = F_40 ( V_14 , V_470 ) ;
V_469 |= V_471 ;
F_74 ( V_14 , V_470 , V_469 ) ;
}
V_452 &= ~ V_456 ;
F_74 ( V_14 , V_455 , V_452 ) ;
}
static void F_280 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_472 ;
T_1 V_49 ;
F_278 ( V_2 ) ;
if ( V_14 -> V_118 . type != V_119 ) {
V_472 = F_40 ( V_14 , V_473 ) ;
V_472 |= V_474 ;
F_74 ( V_14 , V_473 , V_472 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ )
F_273 ( V_2 , V_2 -> V_92 [ V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ )
F_273 ( V_2 , V_2 -> V_94 [ V_49 ] ) ;
}
static void F_281 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_158 = V_64 -> V_158 ;
T_1 V_475 = F_40 ( V_14 , F_39 ( V_158 ) ) ;
V_475 |= V_476 ;
F_74 ( V_14 , F_39 ( V_158 ) , V_475 ) ;
}
static void F_282 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_158 = V_64 -> V_158 ;
T_1 V_475 = F_40 ( V_14 , F_39 ( V_158 ) ) ;
V_475 &= ~ V_476 ;
F_74 ( V_14 , F_39 ( V_158 ) , V_475 ) ;
}
static void F_283 ( struct V_1 * V_2 ,
struct V_63 * V_84 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_475 ;
T_4 V_158 = V_84 -> V_158 ;
if ( V_14 -> V_118 . type == V_119 ) {
T_2 V_128 = V_2 -> V_462 [ V_477 ] . V_128 ;
V_158 &= V_128 ;
}
V_475 = V_293 << V_478 ;
if ( F_14 ( V_479 , & V_84 -> V_35 ) )
V_475 |= V_480 >> V_481 ;
else
V_475 |= V_482 >> V_481 ;
V_475 |= V_483 ;
F_74 ( V_14 , F_39 ( V_158 ) , V_475 ) ;
}
T_1 F_284 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_118 . type < V_123 )
return 128 ;
else if ( V_2 -> V_148 & V_457 )
return 64 ;
else
return 512 ;
}
void F_285 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < 10 ; V_49 ++ )
F_74 ( V_14 , F_286 ( V_49 ) , V_2 -> V_484 [ V_49 ] ) ;
}
static inline int F_287 ( struct V_1 * V_2 )
{
T_1 * V_484 ;
if ( ! V_2 -> V_484 ) {
V_484 = F_288 ( V_485 , V_486 ) ;
if ( F_23 ( ! V_484 ) )
return - V_487 ;
F_289 ( V_484 , V_485 ) ;
V_2 -> V_484 = V_484 ;
}
return 0 ;
}
void F_290 ( struct V_1 * V_2 )
{
T_1 V_49 , V_488 = F_284 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_489 = 0 ;
T_1 V_490 ;
T_4 * V_491 = V_2 -> V_492 ;
if ( V_2 -> V_14 . V_118 . type == V_119 )
V_490 = 0x11 ;
else
V_490 = 0x1 ;
for ( V_49 = 0 ; V_49 < V_488 ; V_49 ++ ) {
V_489 |= V_490 * V_491 [ V_49 ] << ( V_49 & 0x3 ) * 8 ;
if ( ( V_49 & 3 ) == 3 ) {
if ( V_49 < 128 )
F_74 ( V_14 , F_291 ( V_49 >> 2 ) , V_489 ) ;
else
F_74 ( V_14 , F_292 ( ( V_49 >> 2 ) - 32 ) ,
V_489 ) ;
V_489 = 0 ;
}
}
}
static void F_293 ( struct V_1 * V_2 )
{
T_1 V_49 , V_488 = F_284 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_493 = 0 ;
unsigned int V_494 = V_2 -> V_339 ;
for ( V_49 = 0 ; V_49 < V_488 ; V_49 ++ ) {
V_493 |= ( T_1 ) V_2 -> V_492 [ V_49 ] << ( V_49 & 0x3 ) * 8 ;
if ( ( V_49 & 3 ) == 3 ) {
F_74 ( V_14 , F_294 ( V_49 >> 2 , V_494 ) ,
V_493 ) ;
V_493 = 0 ;
}
}
}
static void F_295 ( struct V_1 * V_2 )
{
T_1 V_49 , V_60 ;
T_1 V_488 = F_284 ( V_2 ) ;
T_2 V_495 = V_2 -> V_462 [ V_477 ] . V_496 ;
if ( ( V_2 -> V_148 & V_457 ) && ( V_495 < 4 ) )
V_495 = 4 ;
F_285 ( V_2 ) ;
memset ( V_2 -> V_492 , 0 , sizeof( V_2 -> V_492 ) ) ;
for ( V_49 = 0 , V_60 = 0 ; V_49 < V_488 ; V_49 ++ , V_60 ++ ) {
if ( V_60 == V_495 )
V_60 = 0 ;
V_2 -> V_492 [ V_49 ] = V_60 ;
}
F_290 ( V_2 ) ;
}
static void F_296 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_495 = V_2 -> V_462 [ V_477 ] . V_496 ;
unsigned int V_494 = V_2 -> V_339 ;
int V_49 , V_60 ;
for ( V_49 = 0 ; V_49 < 10 ; V_49 ++ )
F_74 ( V_14 , F_297 ( V_49 , V_494 ) ,
* ( V_2 -> V_484 + V_49 ) ) ;
for ( V_49 = 0 , V_60 = 0 ; V_49 < 64 ; V_49 ++ , V_60 ++ ) {
if ( V_60 == V_495 )
V_60 = 0 ;
V_2 -> V_492 [ V_49 ] = V_60 ;
}
F_293 ( V_2 ) ;
}
static void F_298 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_497 = 0 , V_498 = 0 , V_499 = 0 ;
T_1 V_500 ;
V_500 = F_40 ( V_14 , V_501 ) ;
V_500 |= V_502 ;
F_74 ( V_14 , V_501 , V_500 ) ;
if ( V_2 -> V_14 . V_118 . type == V_119 ) {
if ( V_2 -> V_462 [ V_477 ] . V_128 )
V_497 = V_503 ;
} else {
T_4 V_454 = F_279 ( V_2 -> V_77 ) ;
if ( V_2 -> V_148 & V_457 ) {
if ( V_454 > 4 )
V_497 = V_504 ;
else if ( V_454 > 1 )
V_497 = V_505 ;
else if ( V_2 -> V_462 [ V_463 ] . V_128 ==
V_464 )
V_497 = V_506 ;
else
V_497 = V_507 ;
} else {
if ( V_454 > 4 )
V_497 = V_508 ;
else if ( V_454 > 1 )
V_497 = V_509 ;
else
V_497 = V_503 ;
}
}
V_498 |= V_510 |
V_511 |
V_512 |
V_513 ;
if ( V_2 -> V_368 & V_514 )
V_498 |= V_515 ;
if ( V_2 -> V_368 & V_516 )
V_498 |= V_517 ;
if ( ( V_14 -> V_118 . type >= V_123 ) &&
( V_2 -> V_148 & V_457 ) ) {
unsigned int V_494 = V_2 -> V_339 ;
V_497 |= V_518 ;
F_74 ( V_14 , V_519 , V_497 ) ;
F_296 ( V_2 ) ;
V_499 = V_503 ;
V_499 |= V_498 ;
F_74 ( V_14 , F_299 ( V_494 ) , V_499 ) ;
} else {
F_295 ( V_2 ) ;
V_497 |= V_498 ;
F_74 ( V_14 , V_519 , V_497 ) ;
}
}
static void F_300 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_520 ;
T_4 V_158 = V_64 -> V_158 ;
if ( ! F_170 ( V_64 ) )
return;
V_520 = F_40 ( V_14 , F_301 ( V_158 ) ) ;
V_520 |= V_521 ;
V_520 |= V_522 ;
F_74 ( V_14 , F_301 ( V_158 ) , V_520 ) ;
}
static void F_302 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_443 = V_523 ;
T_1 V_524 ;
T_4 V_158 = V_64 -> V_158 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
if ( V_14 -> V_118 . type == V_119 &&
! ( F_40 ( V_14 , V_450 ) & V_451 ) )
return;
do {
F_276 ( 1000 , 2000 ) ;
V_524 = F_40 ( V_14 , F_45 ( V_158 ) ) ;
} while ( -- V_443 && ! ( V_524 & V_525 ) );
if ( ! V_443 ) {
F_107 ( V_164 , L_82
L_83 , V_158 ) ;
}
}
void F_303 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_443 = V_523 ;
T_1 V_524 ;
T_4 V_158 = V_64 -> V_158 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
V_524 = F_40 ( V_14 , F_45 ( V_158 ) ) ;
V_524 &= ~ V_525 ;
F_74 ( V_14 , F_45 ( V_158 ) , V_524 ) ;
if ( V_14 -> V_118 . type == V_119 &&
! ( F_40 ( V_14 , V_450 ) & V_451 ) )
return;
do {
F_26 ( 10 ) ;
V_524 = F_40 ( V_14 , F_45 ( V_158 ) ) ;
} while ( -- V_443 && ( V_524 & V_525 ) );
if ( ! V_443 ) {
F_107 ( V_164 , L_84
L_83 , V_158 ) ;
}
}
void F_304 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
union V_85 * V_86 ;
V_71 V_526 = V_64 -> V_72 ;
T_1 V_524 ;
T_4 V_158 = V_64 -> V_158 ;
V_524 = F_40 ( V_14 , F_45 ( V_158 ) ) ;
F_303 ( V_2 , V_64 ) ;
F_74 ( V_14 , F_46 ( V_158 ) , ( V_526 & F_274 ( 32 ) ) ) ;
F_74 ( V_14 , F_47 ( V_158 ) , ( V_526 >> 32 ) ) ;
F_74 ( V_14 , F_42 ( V_158 ) ,
V_64 -> V_98 * sizeof( union V_85 ) ) ;
F_240 ( V_14 ) ;
F_74 ( V_14 , F_43 ( V_158 ) , 0 ) ;
F_74 ( V_14 , F_44 ( V_158 ) , 0 ) ;
V_64 -> V_155 = V_2 -> V_446 + F_44 ( V_158 ) ;
F_283 ( V_2 , V_64 ) ;
F_300 ( V_2 , V_64 ) ;
if ( V_14 -> V_118 . type == V_119 ) {
V_524 &= ~ 0x3FFFFF ;
V_524 |= 0x080420 ;
#if ( V_302 < 8192 )
} else {
V_524 &= ~ ( V_527 |
V_528 ) ;
if ( F_142 ( V_64 ) &&
! F_14 ( V_479 , & V_64 -> V_35 ) )
V_524 |= V_529 |
V_528 ;
#endif
}
memset ( V_64 -> V_88 , 0 ,
sizeof( struct V_87 ) * V_64 -> V_98 ) ;
V_86 = F_70 ( V_64 , 0 ) ;
V_86 -> V_105 . V_106 . V_107 = 0 ;
V_524 |= V_525 ;
F_74 ( V_14 , F_45 ( V_158 ) , V_524 ) ;
F_302 ( V_2 , V_64 ) ;
F_150 ( V_64 , F_114 ( V_64 ) ) ;
}
static void F_305 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_495 = V_2 -> V_462 [ V_477 ] . V_496 ;
T_2 V_530 ;
T_1 V_531 = V_532 |
V_533 |
V_534 |
V_535 |
V_536 ;
if ( V_14 -> V_118 . type == V_119 )
return;
if ( V_495 > 3 )
V_531 |= 2u << 29 ;
else if ( V_495 > 1 )
V_531 |= 1u << 29 ;
F_306 (pool, &adapter->fwd_bitmask, 32 )
F_74 ( V_14 , F_307 ( F_308 ( V_530 ) ) , V_531 ) ;
}
static void F_309 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_195 , V_537 ;
T_1 V_538 , V_539 ;
int V_49 ;
if ( ! ( V_2 -> V_148 & V_457 ) )
return;
V_539 = F_40 ( V_14 , V_540 ) ;
V_539 |= V_541 ;
V_539 &= ~ V_542 ;
V_539 |= F_308 ( 0 ) << V_543 ;
V_539 |= V_544 ;
F_74 ( V_14 , V_540 , V_539 ) ;
V_537 = F_308 ( 0 ) % 32 ;
V_195 = ( F_308 ( 0 ) >= 32 ) ? 1 : 0 ;
F_74 ( V_14 , F_310 ( V_195 ) , F_311 ( 31 , V_537 ) ) ;
F_74 ( V_14 , F_310 ( V_195 ^ 1 ) , V_195 - 1 ) ;
F_74 ( V_14 , F_312 ( V_195 ) , F_311 ( 31 , V_537 ) ) ;
F_74 ( V_14 , F_312 ( V_195 ^ 1 ) , V_195 - 1 ) ;
if ( V_2 -> V_545 == V_546 )
F_74 ( V_14 , V_547 , V_548 ) ;
V_14 -> V_118 . V_374 . V_549 ( V_14 , 0 , F_308 ( 0 ) ) ;
V_2 -> V_368 &= ~ V_550 ;
switch ( V_2 -> V_462 [ V_463 ] . V_128 ) {
case V_551 :
V_538 = V_552 ;
break;
case V_464 :
V_538 = V_553 ;
break;
default:
V_538 = V_554 ;
break;
}
F_74 ( V_14 , V_555 , V_538 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_339 ; V_49 ++ ) {
F_313 ( V_2 -> V_77 , V_49 ,
V_2 -> V_556 [ V_49 ] . V_557 ) ;
F_314 ( V_2 -> V_77 , V_49 ,
V_2 -> V_556 [ V_49 ] . V_558 ) ;
}
}
static void F_315 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_76 * V_77 = V_2 -> V_77 ;
int V_559 = V_77 -> V_333 + V_560 + V_561 ;
struct V_63 * V_84 ;
int V_49 ;
T_1 V_562 , V_563 ;
#ifdef F_184
if ( ( V_2 -> V_148 & V_564 ) &&
( V_559 < V_565 ) )
V_559 = V_565 ;
#endif
if ( V_559 < ( V_566 + V_561 ) )
V_559 = ( V_566 + V_561 ) ;
V_562 = F_40 ( V_14 , V_567 ) ;
if ( V_559 != ( V_562 >> V_568 ) ) {
V_562 &= ~ V_569 ;
V_562 |= V_559 << V_568 ;
F_74 ( V_14 , V_567 , V_562 ) ;
}
V_563 = F_40 ( V_14 , V_570 ) ;
V_563 |= V_571 ;
F_74 ( V_14 , V_570 , V_563 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
V_84 = V_2 -> V_84 [ V_49 ] ;
F_316 ( V_84 ) ;
F_37 ( V_479 , & V_84 -> V_35 ) ;
F_37 ( V_572 , & V_84 -> V_35 ) ;
if ( V_2 -> V_368 & V_573 )
F_317 ( V_84 ) ;
if ( F_14 ( V_230 , & V_84 -> V_35 ) )
F_91 ( V_479 , & V_84 -> V_35 ) ;
F_37 ( V_572 , & V_84 -> V_35 ) ;
if ( V_2 -> V_368 & V_574 )
continue;
F_91 ( V_572 , & V_84 -> V_35 ) ;
#if ( V_302 < 8192 )
if ( V_2 -> V_368 & V_573 )
F_91 ( V_479 , & V_84 -> V_35 ) ;
if ( V_575 ||
( V_559 > ( V_566 + V_561 ) ) )
F_91 ( V_479 , & V_84 -> V_35 ) ;
#endif
}
}
static void F_318 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_576 = F_40 ( V_14 , V_577 ) ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_576 |= V_578 ;
break;
case V_123 :
case V_124 :
case V_125 :
if ( V_2 -> V_339 )
V_576 |= V_579 ;
case V_121 :
case V_122 :
F_74 ( V_14 , V_580 ,
( V_581 | F_40 ( V_14 , V_580 ) ) ) ;
V_576 &= ~ V_582 ;
V_576 |= ( V_583 | V_584 ) ;
V_576 |= V_585 ;
break;
default:
return;
}
F_74 ( V_14 , V_577 , V_576 ) ;
}
static void F_319 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
T_1 V_201 , V_586 ;
V_14 -> V_118 . V_374 . V_587 ( V_14 ) ;
F_305 ( V_2 ) ;
F_318 ( V_2 ) ;
V_586 = F_40 ( V_14 , V_588 ) ;
V_586 &= ~ V_589 ;
if ( ! ( V_2 -> V_368 & V_573 ) )
V_586 |= V_589 ;
V_586 |= ( V_590 | V_591 ) ;
F_74 ( V_14 , V_588 , V_586 ) ;
F_298 ( V_2 ) ;
F_315 ( V_2 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ )
F_304 ( V_2 , V_2 -> V_84 [ V_49 ] ) ;
V_201 = F_40 ( V_14 , V_592 ) ;
if ( V_14 -> V_118 . type == V_119 )
V_201 |= V_593 ;
V_201 |= V_594 ;
V_14 -> V_118 . V_374 . V_595 ( V_14 , V_201 ) ;
}
static int F_320 ( struct V_76 * V_77 ,
T_11 V_596 , T_2 V_273 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! V_273 || ! ( V_2 -> V_368 & V_550 ) )
V_14 -> V_118 . V_374 . V_597 ( & V_2 -> V_14 , V_273 , F_308 ( 0 ) , true , ! ! V_273 ) ;
F_91 ( V_273 , V_2 -> V_598 ) ;
return 0 ;
}
static int F_321 ( struct V_15 * V_14 , T_1 V_274 )
{
T_1 V_599 ;
int V_600 ;
if ( V_274 == 0 )
return 0 ;
for ( V_600 = V_601 ; -- V_600 ; ) {
V_599 = F_40 ( V_14 , F_322 ( V_600 ) ) ;
if ( ( V_599 & V_602 ) == V_274 )
break;
}
return V_600 ;
}
void F_323 ( struct V_1 * V_2 , T_1 V_273 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_603 , V_604 ;
int V_600 ;
V_600 = F_321 ( V_14 , V_273 ) ;
if ( ! V_600 )
return;
V_604 = V_600 * 2 + ( F_308 ( 0 ) / 32 ) ;
V_603 = ~ F_224 ( F_308 ( 0 ) % 32 ) ;
V_603 &= F_40 ( V_14 , F_324 ( V_604 ) ) ;
if ( ! V_603 && ! F_40 ( V_14 , F_324 ( V_604 ^ 1 ) ) ) {
if ( ! ( V_2 -> V_368 & V_550 ) )
F_74 ( V_14 , F_324 ( V_604 ) , 0 ) ;
F_74 ( V_14 , F_322 ( V_600 ) , 0 ) ;
}
}
static int F_325 ( struct V_76 * V_77 ,
T_11 V_596 , T_2 V_273 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_273 && ! ( V_2 -> V_368 & V_550 ) )
V_14 -> V_118 . V_374 . V_597 ( V_14 , V_273 , F_308 ( 0 ) , false , true ) ;
F_37 ( V_273 , V_2 -> V_598 ) ;
return 0 ;
}
static void F_326 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_605 ;
int V_49 , V_60 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_605 = F_40 ( V_14 , V_606 ) ;
V_605 &= ~ V_607 ;
F_74 ( V_14 , V_606 , V_605 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
struct V_63 * V_64 = V_2 -> V_84 [ V_49 ] ;
if ( V_64 -> V_156 )
continue;
V_60 = V_64 -> V_158 ;
V_605 = F_40 ( V_14 , F_45 ( V_60 ) ) ;
V_605 &= ~ V_608 ;
F_74 ( V_14 , F_45 ( V_60 ) , V_605 ) ;
}
break;
default:
break;
}
}
static void F_327 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_605 ;
int V_49 , V_60 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_605 = F_40 ( V_14 , V_606 ) ;
V_605 |= V_607 ;
F_74 ( V_14 , V_606 , V_605 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
struct V_63 * V_64 = V_2 -> V_84 [ V_49 ] ;
if ( V_64 -> V_156 )
continue;
V_60 = V_64 -> V_158 ;
V_605 = F_40 ( V_14 , F_45 ( V_60 ) ) ;
V_605 |= V_608 ;
F_74 ( V_14 , F_45 ( V_60 ) , V_605 ) ;
}
break;
default:
break;
}
}
static void F_328 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_605 , V_49 ;
V_605 = F_40 ( V_14 , V_606 ) ;
if ( V_2 -> V_148 & V_609 ) {
V_605 |= V_610 ;
F_74 ( V_14 , V_606 , V_605 ) ;
} else {
V_605 &= ~ V_610 ;
F_74 ( V_14 , V_606 , V_605 ) ;
return;
}
if ( V_14 -> V_118 . type == V_119 )
return;
if ( V_2 -> V_368 & V_550 )
return;
V_2 -> V_368 |= V_550 ;
for ( V_49 = V_601 ; -- V_49 ; ) {
T_1 V_195 = F_324 ( V_49 * 2 + F_308 ( 0 ) / 32 ) ;
T_1 V_611 = F_40 ( V_14 , V_195 ) ;
V_611 |= F_224 ( F_308 ( 0 ) % 32 ) ;
F_74 ( V_14 , V_195 , V_611 ) ;
}
for ( V_49 = V_14 -> V_118 . V_612 ; V_49 -- ; )
F_74 ( V_14 , F_329 ( V_49 ) , ~ 0U ) ;
}
static void F_330 ( struct V_1 * V_2 , T_1 V_613 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_614 [ V_615 ] = { 0 } ;
T_1 V_616 = V_613 * 32 ;
T_1 V_617 = V_616 + ( V_615 * 32 ) ;
T_1 V_49 , V_273 , V_604 , V_603 ;
for ( V_49 = V_601 ; -- V_49 ; ) {
T_1 V_599 = F_40 ( V_14 , F_322 ( V_49 ) ) ;
V_273 = V_599 & V_602 ;
if ( V_273 < V_616 || V_273 >= V_617 )
continue;
if ( V_599 ) {
V_614 [ ( V_273 - V_616 ) / 32 ] |= F_224 ( V_273 % 32 ) ;
if ( F_14 ( V_273 , V_2 -> V_598 ) )
continue;
}
V_604 = V_49 * 2 + F_308 ( 0 ) / 32 ;
V_603 = ~ F_224 ( F_308 ( 0 ) % 32 ) ;
V_603 &= F_40 ( V_14 , F_324 ( V_604 ) ) ;
F_74 ( V_14 , F_324 ( V_604 ) , V_603 ) ;
}
for ( V_49 = V_615 ; V_49 -- ; ) {
V_273 = ( V_613 + V_49 ) * 32 ;
V_604 = V_273 / V_618 ;
V_603 = V_273 % V_618 ;
V_614 [ V_49 ] |= V_2 -> V_598 [ V_604 ] >> V_603 ;
F_74 ( V_14 , F_329 ( V_613 + V_49 ) , V_614 [ V_49 ] ) ;
}
}
static void F_331 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_605 , V_49 ;
V_605 = F_40 ( V_14 , V_606 ) ;
V_605 |= V_610 ;
F_74 ( V_14 , V_606 , V_605 ) ;
if ( ! ( V_2 -> V_148 & V_609 ) ||
V_14 -> V_118 . type == V_119 )
return;
if ( ! ( V_2 -> V_368 & V_550 ) )
return;
V_2 -> V_368 &= ~ V_550 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_612 ; V_49 += V_615 )
F_330 ( V_2 , V_49 ) ;
}
static void F_332 ( struct V_1 * V_2 )
{
T_2 V_273 = 1 ;
F_320 ( V_2 -> V_77 , F_164 ( V_275 ) , 0 ) ;
F_333 (vid, adapter->active_vlans, VLAN_N_VID)
F_320 ( V_2 -> V_77 , F_164 ( V_275 ) , V_273 ) ;
}
static int F_334 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! F_63 ( V_77 ) )
return 0 ;
if ( V_14 -> V_118 . V_374 . V_619 )
V_14 -> V_118 . V_374 . V_619 ( V_14 , V_77 ) ;
else
return - V_487 ;
#ifdef F_335
F_336 ( V_2 ) ;
#endif
return F_337 ( V_77 ) ;
}
void F_338 ( struct V_1 * V_2 )
{
struct V_620 * V_621 = & V_2 -> V_621 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_622 ; V_49 ++ , V_621 ++ ) {
V_621 -> V_35 &= ~ V_623 ;
if ( V_621 -> V_35 & V_624 )
V_14 -> V_118 . V_374 . V_625 ( V_14 , V_49 ,
V_621 -> V_626 ,
V_621 -> V_530 ,
V_627 ) ;
else
V_14 -> V_118 . V_374 . V_628 ( V_14 , V_49 ) ;
}
}
static void F_339 ( struct V_1 * V_2 )
{
struct V_620 * V_621 = & V_2 -> V_621 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_622 ; V_49 ++ , V_621 ++ ) {
if ( ! ( V_621 -> V_35 & V_623 ) )
continue;
V_621 -> V_35 &= ~ V_623 ;
if ( V_621 -> V_35 & V_624 )
V_14 -> V_118 . V_374 . V_625 ( V_14 , V_49 ,
V_621 -> V_626 ,
V_621 -> V_530 ,
V_627 ) ;
else
V_14 -> V_118 . V_374 . V_628 ( V_14 , V_49 ) ;
}
}
static void F_340 ( struct V_1 * V_2 )
{
struct V_620 * V_621 = & V_2 -> V_621 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_622 ; V_49 ++ , V_621 ++ ) {
V_621 -> V_35 |= V_623 ;
V_621 -> V_35 &= ~ V_624 ;
}
F_339 ( V_2 ) ;
}
static int F_341 ( struct V_1 * V_2 , T_2 V_530 )
{
struct V_620 * V_621 = & V_2 -> V_621 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 , V_98 = 0 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_622 ; V_49 ++ , V_621 ++ ) {
if ( V_621 -> V_35 & V_629 )
continue;
if ( V_621 -> V_35 & V_624 ) {
if ( V_621 -> V_530 != V_530 )
continue;
}
V_98 ++ ;
}
return V_98 ;
}
static void F_342 ( struct V_1 * V_2 )
{
struct V_620 * V_621 = & V_2 -> V_621 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
memcpy ( & V_621 -> V_626 , V_14 -> V_118 . V_626 , V_630 ) ;
V_621 -> V_530 = F_308 ( 0 ) ;
V_621 -> V_35 = V_629 | V_624 ;
V_14 -> V_118 . V_374 . V_625 ( V_14 , 0 , V_621 -> V_626 , V_621 -> V_530 ,
V_627 ) ;
}
int F_343 ( struct V_1 * V_2 ,
const T_4 * V_626 , T_2 V_530 )
{
struct V_620 * V_621 = & V_2 -> V_621 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( F_344 ( V_626 ) )
return - V_631 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_622 ; V_49 ++ , V_621 ++ ) {
if ( V_621 -> V_35 & V_624 )
continue;
F_345 ( V_621 -> V_626 , V_626 ) ;
V_621 -> V_530 = V_530 ;
V_621 -> V_35 |= V_623 |
V_624 ;
F_339 ( V_2 ) ;
return V_49 ;
}
return - V_487 ;
}
int F_346 ( struct V_1 * V_2 ,
const T_4 * V_626 , T_2 V_530 )
{
struct V_620 * V_621 = & V_2 -> V_621 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( F_344 ( V_626 ) )
return - V_631 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_622 ; V_49 ++ , V_621 ++ ) {
if ( ! ( V_621 -> V_35 & V_624 ) )
continue;
if ( V_621 -> V_530 != V_530 )
continue;
if ( ! F_347 ( V_626 , V_621 -> V_626 ) )
continue;
V_621 -> V_35 |= V_623 ;
V_621 -> V_35 &= ~ V_624 ;
F_339 ( V_2 ) ;
return 0 ;
}
return - V_487 ;
}
static int F_348 ( struct V_76 * V_77 , int V_632 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
int V_98 = 0 ;
if ( F_349 ( V_77 ) > F_341 ( V_2 , V_632 ) )
return - V_487 ;
if ( ! F_350 ( V_77 ) ) {
struct V_633 * V_634 ;
F_351 (ha, netdev) {
F_346 ( V_2 , V_634 -> V_626 , V_632 ) ;
F_343 ( V_2 , V_634 -> V_626 , V_632 ) ;
V_98 ++ ;
}
}
return V_98 ;
}
static int F_352 ( struct V_76 * V_77 , const unsigned char * V_626 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
int V_635 ;
V_635 = F_343 ( V_2 , V_626 , F_308 ( 0 ) ) ;
return F_353 ( int , V_635 , 0 ) ;
}
static int F_354 ( struct V_76 * V_77 , const unsigned char * V_626 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
F_346 ( V_2 , V_626 , F_308 ( 0 ) ) ;
return 0 ;
}
void F_355 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_636 , V_637 = V_638 | V_639 ;
T_12 V_218 = V_77 -> V_218 ;
int V_98 ;
V_636 = F_40 ( V_14 , V_640 ) ;
V_636 &= ~ V_641 ;
V_636 |= V_642 ;
V_636 |= V_643 ;
V_636 |= V_644 ;
V_636 &= ~ ( V_645 | V_646 ) ;
if ( V_77 -> V_148 & V_647 ) {
V_14 -> V_648 . V_649 = true ;
V_636 |= ( V_645 | V_646 ) ;
V_637 |= V_650 ;
V_218 &= ~ V_651 ;
} else {
if ( V_77 -> V_148 & V_652 ) {
V_636 |= V_646 ;
V_637 |= V_650 ;
}
V_14 -> V_648 . V_649 = false ;
}
if ( F_356 ( V_77 , F_352 , F_354 ) ) {
V_636 |= V_645 ;
V_637 |= V_653 ;
}
V_98 = F_334 ( V_77 ) ;
if ( V_98 < 0 ) {
V_636 |= V_646 ;
V_637 |= V_650 ;
} else if ( V_98 ) {
V_637 |= V_654 ;
}
if ( V_14 -> V_118 . type != V_119 ) {
V_637 |= F_40 ( V_14 , F_357 ( F_308 ( 0 ) ) ) &
~ ( V_650 | V_654 |
V_653 ) ;
F_74 ( V_14 , F_357 ( F_308 ( 0 ) ) , V_637 ) ;
}
if ( V_218 & V_297 ) {
V_636 |= ( V_641 |
V_642 |
V_644 ) ;
V_636 &= ~ ( V_643 ) ;
}
F_74 ( V_14 , V_640 , V_636 ) ;
if ( V_218 & V_271 )
F_327 ( V_2 ) ;
else
F_326 ( V_2 ) ;
if ( V_218 & V_651 )
F_331 ( V_2 ) ;
else
F_328 ( V_2 ) ;
}
static void F_358 ( struct V_1 * V_2 )
{
int V_655 ;
for ( V_655 = 0 ; V_655 < V_2 -> V_210 ; V_655 ++ )
F_359 ( & V_2 -> V_174 [ V_655 ] -> V_277 ) ;
}
static void F_360 ( struct V_1 * V_2 )
{
int V_655 ;
for ( V_655 = 0 ; V_655 < V_2 -> V_210 ; V_655 ++ )
F_361 ( & V_2 -> V_174 [ V_655 ] -> V_277 ) ;
}
static void F_362 ( struct V_1 * V_2 , T_1 V_128 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_656 ;
if ( ! ( V_2 -> V_148 & ( V_657 |
V_658 ) ) )
return;
V_656 = F_40 ( V_14 , V_659 ) && ~ V_128 ;
F_74 ( V_14 , V_659 , V_656 ) ;
if ( V_128 & V_660 )
V_2 -> V_661 = 0 ;
if ( V_128 & V_662 )
V_2 -> V_663 = 0 ;
}
static void F_363 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_559 = V_2 -> V_77 -> V_333 + V_560 + V_561 ;
if ( ! ( V_2 -> V_148 & V_149 ) ) {
if ( V_14 -> V_118 . type == V_119 )
F_364 ( V_2 -> V_77 , 65536 ) ;
return;
}
if ( V_14 -> V_118 . type == V_119 )
F_364 ( V_2 -> V_77 , 32768 ) ;
#ifdef F_184
if ( V_2 -> V_77 -> V_218 & V_664 )
V_559 = F_229 ( V_559 , V_565 ) ;
#endif
if ( V_2 -> V_665 & V_666 ) {
F_365 ( V_14 , & V_2 -> V_145 , V_559 ,
V_667 ) ;
F_365 ( V_14 , & V_2 -> V_145 , V_559 ,
V_668 ) ;
F_366 ( V_14 , & V_2 -> V_145 ) ;
} else if ( V_2 -> V_669 && V_2 -> V_147 ) {
F_367 ( & V_2 -> V_14 ,
V_2 -> V_669 ,
V_559 ) ;
F_368 ( & V_2 -> V_14 ,
V_2 -> V_147 -> V_144 ,
V_2 -> V_669 -> V_670 ) ;
}
if ( V_14 -> V_118 . type != V_119 ) {
T_1 V_671 = 0 ;
T_2 V_495 = V_2 -> V_462 [ V_477 ] . V_496 - 1 ;
while ( V_495 ) {
V_671 ++ ;
V_495 >>= 1 ;
}
F_74 ( V_14 , V_672 , V_671 * 0x11111111 ) ;
}
}
static int F_369 ( struct V_1 * V_2 , int V_673 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_76 * V_89 = V_2 -> V_77 ;
int V_416 , V_143 , V_674 , V_675 ;
T_1 V_676 , V_677 ;
V_143 = V_416 = V_89 -> V_333 + V_560 + V_561 + V_678 ;
#ifdef F_184
if ( ( V_89 -> V_218 & V_664 ) &&
( V_143 < V_565 ) &&
( V_673 == F_370 ( V_2 ) ) )
V_143 = V_565 ;
#endif
switch ( V_14 -> V_118 . type ) {
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_676 = F_371 ( V_416 , V_143 ) ;
break;
default:
V_676 = F_372 ( V_416 , V_143 ) ;
break;
}
if ( V_2 -> V_148 & V_457 )
V_676 += F_373 ( V_143 ) ;
V_674 = F_374 ( V_676 ) ;
V_677 = F_40 ( V_14 , F_375 ( V_673 ) ) >> 10 ;
V_675 = V_677 - V_674 ;
if ( V_675 < 0 ) {
F_27 ( V_164 , L_85
L_86
L_87 , V_673 ) ;
V_675 = V_143 + 1 ;
}
return V_675 ;
}
static int F_376 ( struct V_1 * V_2 , int V_673 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_76 * V_89 = V_2 -> V_77 ;
int V_143 ;
T_1 V_676 ;
V_143 = V_89 -> V_333 + V_560 + V_561 ;
#ifdef F_184
if ( ( V_89 -> V_218 & V_664 ) &&
( V_143 < V_565 ) &&
( V_673 == F_84 ( V_89 , V_2 -> V_679 . V_680 ) ) )
V_143 = V_565 ;
#endif
switch ( V_14 -> V_118 . type ) {
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_676 = F_377 ( V_143 ) ;
break;
default:
V_676 = F_378 ( V_143 ) ;
break;
}
return F_374 ( V_676 ) ;
}
static void F_379 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_681 = F_279 ( V_2 -> V_77 ) ;
int V_49 ;
if ( ! V_681 )
V_681 = 1 ;
for ( V_49 = 0 ; V_49 < V_681 ; V_49 ++ ) {
V_14 -> V_134 . V_682 [ V_49 ] = F_369 ( V_2 , V_49 ) ;
V_14 -> V_134 . V_683 [ V_49 ] = F_376 ( V_2 , V_49 ) ;
if ( V_14 -> V_134 . V_683 [ V_49 ] > V_14 -> V_134 . V_682 [ V_49 ] )
V_14 -> V_134 . V_683 [ V_49 ] = 0 ;
}
for (; V_49 < V_684 ; V_49 ++ )
V_14 -> V_134 . V_682 [ V_49 ] = 0 ;
}
static void F_380 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_685 ;
T_4 V_143 = F_279 ( V_2 -> V_77 ) ;
if ( V_2 -> V_148 & V_409 ||
V_2 -> V_148 & V_686 )
V_685 = 32 << V_2 -> V_687 ;
else
V_685 = 0 ;
V_14 -> V_118 . V_374 . V_688 ( V_14 , V_143 , V_685 , V_689 ) ;
F_379 ( V_2 ) ;
}
static void F_381 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_690 * V_691 ;
struct V_692 * V_693 ;
F_382 ( & V_2 -> V_694 ) ;
if ( ! F_383 ( & V_2 -> V_695 ) )
F_384 ( V_14 , & V_2 -> V_696 ) ;
F_385 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_386 ( V_14 ,
& V_693 -> V_693 ,
V_693 -> V_697 ,
( V_693 -> V_698 == V_699 ) ?
V_699 :
V_2 -> V_84 [ V_693 -> V_698 ] -> V_158 ) ;
}
F_387 ( & V_2 -> V_694 ) ;
}
static void F_388 ( struct V_76 * V_89 , unsigned int V_530 ,
struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_637 ;
V_637 = F_40 ( V_14 , F_357 ( V_530 ) ) ;
V_637 |= ( V_654 | V_638 | V_639 ) ;
V_637 &= ~ V_650 ;
if ( V_89 -> V_148 & V_652 ) {
V_637 |= V_650 ;
} else {
V_637 |= V_654 ;
V_14 -> V_118 . V_374 . V_619 ( V_14 , V_89 ) ;
}
F_348 ( V_2 -> V_77 , V_530 ) ;
F_74 ( V_14 , F_357 ( V_530 ) , V_637 ) ;
}
static void F_389 ( struct V_700 * V_701 )
{
struct V_1 * V_2 = V_701 -> V_157 ;
int V_495 = V_2 -> V_702 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_530 = V_701 -> V_530 ;
T_1 V_531 = V_532 |
V_533 |
V_534 |
V_535 |
V_536 ;
if ( V_14 -> V_118 . type == V_119 )
return;
if ( V_495 > 3 )
V_531 |= 2u << 29 ;
else if ( V_495 > 1 )
V_531 |= 1u << 29 ;
F_74 ( V_14 , F_307 ( F_308 ( V_530 ) ) , V_531 ) ;
}
static void F_390 ( struct V_63 * V_84 )
{
T_2 V_49 = V_84 -> V_69 ;
struct V_87 * V_301 = & V_84 -> V_88 [ V_49 ] ;
while ( V_49 != V_84 -> V_262 ) {
if ( V_301 -> V_100 ) {
struct V_216 * V_100 = V_301 -> V_100 ;
if ( F_159 ( V_100 ) -> V_295 )
F_178 ( V_84 -> V_89 ,
F_159 ( V_100 ) -> V_72 ,
F_147 ( V_84 ) ,
V_255 ,
V_256 ) ;
F_391 ( V_100 ) ;
}
F_179 ( V_84 -> V_89 ,
V_301 -> V_72 ,
V_301 -> V_109 ,
F_72 ( V_84 ) ,
V_255 ) ;
F_178 ( V_84 -> V_89 , V_301 -> V_72 ,
F_147 ( V_84 ) ,
V_255 ,
V_256 ) ;
F_201 ( V_301 -> V_108 ,
V_301 -> V_257 ) ;
V_49 ++ ;
V_301 ++ ;
if ( V_49 == V_84 -> V_98 ) {
V_49 = 0 ;
V_301 = V_84 -> V_88 ;
}
}
V_84 -> V_262 = 0 ;
V_84 -> V_69 = 0 ;
V_84 -> V_70 = 0 ;
}
static void F_392 ( struct V_700 * V_701 ,
struct V_63 * V_84 )
{
struct V_1 * V_2 = V_701 -> V_157 ;
int V_117 = V_84 -> V_96 + V_701 -> V_703 ;
F_303 ( V_2 , V_84 ) ;
F_276 ( 10000 , 20000 ) ;
F_243 ( V_2 , F_259 ( V_117 ) ) ;
F_390 ( V_84 ) ;
V_84 -> V_156 = NULL ;
}
static int F_393 ( struct V_76 * V_704 ,
struct V_700 * V_705 )
{
struct V_1 * V_2 = V_705 -> V_157 ;
unsigned int V_706 = V_705 -> V_703 ;
unsigned int V_707 = V_705 -> V_708 ;
int V_49 ;
F_394 ( V_704 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_702 ; V_49 ++ ) {
F_392 ( V_705 , V_2 -> V_84 [ V_706 + V_49 ] ) ;
V_2 -> V_84 [ V_706 + V_49 ] -> V_77 = V_2 -> V_77 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_702 ; V_49 ++ ) {
V_2 -> V_92 [ V_707 + V_49 ] -> V_156 = NULL ;
V_2 -> V_92 [ V_707 + V_49 ] -> V_77 = V_2 -> V_77 ;
}
return 0 ;
}
static int F_395 ( struct V_76 * V_704 ,
struct V_700 * V_705 )
{
struct V_1 * V_2 = V_705 -> V_157 ;
unsigned int V_706 , V_707 , V_401 ;
int V_49 , V_709 , V_17 = 0 ;
if ( ! F_14 ( V_705 -> V_530 , & V_2 -> V_710 ) )
return 0 ;
V_709 = V_705 -> V_530 * V_2 -> V_702 ;
F_396 ( V_704 , L_88 ,
V_705 -> V_530 , V_2 -> V_711 ,
V_709 , V_709 + V_2 -> V_702 ,
V_2 -> V_710 ) ;
V_705 -> V_77 = V_704 ;
V_705 -> V_703 = V_706 = V_709 ;
V_705 -> V_708 = V_707 = V_709 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_702 ; V_49 ++ )
F_392 ( V_705 , V_2 -> V_84 [ V_706 + V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_702 ; V_49 ++ ) {
V_2 -> V_84 [ V_706 + V_49 ] -> V_77 = V_704 ;
V_2 -> V_84 [ V_706 + V_49 ] -> V_156 = V_705 ;
F_304 ( V_2 , V_2 -> V_84 [ V_706 + V_49 ] ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_702 ; V_49 ++ ) {
V_2 -> V_92 [ V_707 + V_49 ] -> V_77 = V_704 ;
V_2 -> V_92 [ V_707 + V_49 ] -> V_156 = V_705 ;
}
V_401 = F_353 (unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues) ;
V_17 = F_397 ( V_704 , V_401 ) ;
if ( V_17 )
goto V_712;
V_17 = F_398 ( V_704 , V_401 ) ;
if ( V_17 )
goto V_712;
if ( F_399 ( V_704 -> V_713 ) )
F_343 ( V_2 , V_704 -> V_713 , V_705 -> V_530 ) ;
F_389 ( V_705 ) ;
F_388 ( V_704 , V_705 -> V_530 , V_2 ) ;
return V_17 ;
V_712:
F_393 ( V_704 , V_705 ) ;
return V_17 ;
}
static int F_400 ( struct V_76 * V_106 , void * V_103 )
{
if ( F_401 ( V_106 ) ) {
struct V_714 * V_715 = F_87 ( V_106 ) ;
struct V_700 * V_701 = V_715 -> V_716 ;
if ( V_715 -> V_716 )
F_395 ( V_106 , V_701 ) ;
}
return 0 ;
}
static void F_402 ( struct V_1 * V_2 )
{
F_403 ( V_2 -> V_77 ,
F_400 , NULL ) ;
}
static void F_404 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
F_380 ( V_2 ) ;
#ifdef F_405
F_363 ( V_2 ) ;
#endif
F_309 ( V_2 ) ;
F_355 ( V_2 -> V_77 ) ;
F_332 ( V_2 ) ;
switch ( V_14 -> V_118 . type ) {
case V_121 :
case V_122 :
V_14 -> V_118 . V_374 . V_717 ( V_14 ) ;
break;
default:
break;
}
if ( V_2 -> V_148 & V_409 ) {
F_406 ( & V_2 -> V_14 ,
V_2 -> V_687 ) ;
} else if ( V_2 -> V_148 & V_686 ) {
F_407 ( & V_2 -> V_14 ,
V_2 -> V_687 ) ;
F_381 ( V_2 ) ;
}
switch ( V_14 -> V_118 . type ) {
case V_121 :
case V_122 :
V_14 -> V_118 . V_374 . V_718 ( V_14 ) ;
break;
default:
break;
}
#ifdef F_257
if ( V_2 -> V_148 & V_213 )
F_127 ( V_2 ) ;
#endif
#ifdef F_184
F_408 ( V_2 ) ;
#endif
F_280 ( V_2 ) ;
F_319 ( V_2 ) ;
F_402 ( V_2 ) ;
}
static void F_409 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_118 . type == V_119 )
V_2 -> V_368 |= V_719 ;
V_2 -> V_368 |= V_393 ;
V_2 -> V_394 = 0 ;
}
static int F_410 ( struct V_15 * V_14 )
{
T_1 V_20 ;
bool V_720 , V_376 = false ;
int V_635 = V_721 ;
if ( V_14 -> V_118 . V_374 . V_375 )
V_635 = V_14 -> V_118 . V_374 . V_375 ( V_14 , & V_20 , & V_376 , false ) ;
if ( V_635 )
return V_635 ;
V_20 = V_14 -> V_46 . V_722 ;
if ( ( ! V_20 ) && ( V_14 -> V_118 . V_374 . V_723 ) )
V_635 = V_14 -> V_118 . V_374 . V_723 ( V_14 , & V_20 ,
& V_720 ) ;
if ( V_635 )
return V_635 ;
if ( V_14 -> V_118 . V_374 . V_724 )
V_635 = V_14 -> V_118 . V_374 . V_724 ( V_14 , V_20 , V_376 ) ;
return V_635 ;
}
static void F_411 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_725 = 0 ;
if ( V_2 -> V_148 & V_437 ) {
V_725 = V_726 | V_727 |
V_728 ;
V_725 |= V_729 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
F_74 ( V_14 , V_730 , V_731 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
default:
F_74 ( V_14 , F_412 ( 0 ) , 0xFFFFFFFF ) ;
F_74 ( V_14 , F_412 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_74 ( V_14 , V_730 , V_731 ) ;
}
if ( V_2 -> V_148 & V_457 ) {
V_725 &= ~ V_732 ;
switch ( V_2 -> V_462 [ V_463 ] . V_128 ) {
case V_551 :
V_725 |= V_733 ;
break;
case V_464 :
V_725 |= V_734 ;
break;
default:
V_725 |= V_735 ;
break;
}
}
if ( V_2 -> V_368 & V_369 ) {
switch ( V_2 -> V_14 . V_118 . type ) {
case V_121 :
V_725 |= V_736 ;
break;
default:
break;
}
}
if ( V_2 -> V_148 & V_382 )
V_725 |= F_413 ( V_14 ) ;
switch ( V_14 -> V_118 . type ) {
case V_121 :
V_725 |= V_737 | V_738 ;
break;
case V_124 :
case V_125 :
V_725 |= V_739 ;
break;
default:
break;
}
F_74 ( V_14 , V_740 , V_725 ) ;
}
static void F_414 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 ;
T_1 V_110 ;
F_75 ( V_2 ) ;
F_411 ( V_2 ) ;
if ( V_2 -> V_148 & V_437 )
F_223 ( V_2 ) ;
else
F_272 ( V_2 ) ;
if ( V_14 -> V_118 . V_374 . V_741 )
V_14 -> V_118 . V_374 . V_741 ( V_14 ) ;
if ( V_14 -> V_46 . V_374 . V_742 )
V_14 -> V_46 . V_374 . V_742 ( V_14 , true ) ;
F_36 () ;
F_37 ( V_34 , & V_2 -> V_35 ) ;
F_358 ( V_2 ) ;
if ( F_236 ( V_14 ) ) {
F_409 ( V_2 ) ;
} else {
V_17 = F_410 ( V_14 ) ;
if ( V_17 )
F_107 ( V_190 , L_89 , V_17 ) ;
}
F_40 ( V_14 , V_383 ) ;
F_245 ( V_2 , true , true ) ;
if ( V_2 -> V_148 & V_382 ) {
T_1 V_743 = F_40 ( V_14 , V_744 ) ;
if ( V_743 & V_745 )
F_232 ( V_164 , L_70 ) ;
}
V_2 -> V_148 |= V_397 ;
V_2 -> V_398 = V_189 ;
F_415 ( & V_2 -> V_746 , V_189 ) ;
V_110 = F_40 ( V_14 , V_111 ) ;
V_110 |= V_747 ;
F_74 ( V_14 , V_111 , V_110 ) ;
}
void F_416 ( struct V_1 * V_2 )
{
F_417 ( F_418 () ) ;
F_419 ( V_2 -> V_77 ) ;
while ( F_15 ( V_748 , & V_2 -> V_35 ) )
F_276 ( 1000 , 2000 ) ;
if ( V_2 -> V_14 . V_46 . type == V_749 )
F_420 ( V_2 ) ;
F_421 ( V_2 ) ;
if ( V_2 -> V_148 & V_457 )
F_422 ( 2000 ) ;
F_423 ( V_2 ) ;
F_37 ( V_748 , & V_2 -> V_35 ) ;
}
void F_423 ( struct V_1 * V_2 )
{
F_404 ( V_2 ) ;
F_414 ( V_2 ) ;
}
void F_424 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_76 * V_77 = V_2 -> V_77 ;
int V_17 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
while ( F_15 ( V_750 , & V_2 -> V_35 ) )
F_276 ( 1000 , 2000 ) ;
V_2 -> V_368 &= ~ ( V_719 |
V_393 ) ;
V_2 -> V_148 &= ~ V_395 ;
V_17 = V_14 -> V_118 . V_374 . V_751 ( V_14 ) ;
switch ( V_17 ) {
case 0 :
case V_752 :
case V_753 :
break;
case V_754 :
F_18 ( L_90 ) ;
break;
case V_755 :
F_11 ( L_91
L_92
L_93
L_94
L_95
L_96 ) ;
break;
default:
F_18 ( L_97 , V_17 ) ;
}
F_37 ( V_750 , & V_2 -> V_35 ) ;
F_340 ( V_2 ) ;
F_425 ( V_77 , NULL ) ;
F_342 ( V_2 ) ;
if ( V_14 -> V_118 . V_756 )
V_14 -> V_118 . V_374 . V_757 ( V_14 , F_308 ( 0 ) ) ;
if ( F_14 ( V_758 , & V_2 -> V_35 ) )
F_426 ( V_2 ) ;
if ( V_14 -> V_46 . V_374 . V_742 ) {
if ( ! F_63 ( V_2 -> V_77 ) && ! V_2 -> V_759 )
V_14 -> V_46 . V_374 . V_742 ( V_14 , false ) ;
else
V_14 -> V_46 . V_374 . V_742 ( V_14 , true ) ;
}
}
static void F_427 ( struct V_63 * V_92 )
{
T_2 V_49 = V_92 -> V_69 ;
struct V_66 * V_67 = & V_92 -> V_68 [ V_49 ] ;
while ( V_49 != V_92 -> V_70 ) {
union V_78 * V_181 , * V_79 ;
if ( F_97 ( V_92 ) )
F_98 ( V_67 -> V_103 ) ;
else
F_183 ( V_67 -> V_100 ) ;
F_100 ( V_92 -> V_89 ,
F_57 ( V_67 , V_72 ) ,
F_58 ( V_67 , V_73 ) ,
V_186 ) ;
V_181 = V_67 -> V_74 ;
V_79 = F_65 ( V_92 , V_49 ) ;
while ( V_79 != V_181 ) {
V_67 ++ ;
V_79 ++ ;
V_49 ++ ;
if ( F_23 ( V_49 == V_92 -> V_98 ) ) {
V_49 = 0 ;
V_67 = V_92 -> V_68 ;
V_79 = F_65 ( V_92 , 0 ) ;
}
if ( F_58 ( V_67 , V_73 ) )
F_102 ( V_92 -> V_89 ,
F_57 ( V_67 , V_72 ) ,
F_58 ( V_67 , V_73 ) ,
V_186 ) ;
}
V_67 ++ ;
V_49 ++ ;
if ( F_23 ( V_49 == V_92 -> V_98 ) ) {
V_49 = 0 ;
V_67 = V_92 -> V_68 ;
}
}
if ( ! F_97 ( V_92 ) )
F_428 ( F_111 ( V_92 ) ) ;
V_92 -> V_70 = 0 ;
V_92 -> V_69 = 0 ;
}
static void F_429 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ )
F_390 ( V_2 -> V_84 [ V_49 ] ) ;
}
static void F_430 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ )
F_427 ( V_2 -> V_92 [ V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ )
F_427 ( V_2 -> V_94 [ V_49 ] ) ;
}
static void F_431 ( struct V_1 * V_2 )
{
struct V_690 * V_691 ;
struct V_692 * V_693 ;
F_382 ( & V_2 -> V_694 ) ;
F_385 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_432 ( & V_693 -> V_760 ) ;
F_266 ( V_693 ) ;
}
V_2 -> V_761 = 0 ;
F_387 ( & V_2 -> V_694 ) ;
}
static int F_433 ( struct V_76 * V_106 , void * V_103 )
{
if ( F_401 ( V_106 ) ) {
struct V_714 * V_274 = F_87 ( V_106 ) ;
if ( V_274 -> V_716 ) {
F_394 ( V_106 ) ;
F_434 ( V_106 ) ;
F_435 ( V_106 ) ;
}
}
return 0 ;
}
void F_421 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( F_15 ( V_34 , & V_2 -> V_35 ) )
return;
V_14 -> V_118 . V_374 . V_587 ( V_14 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ )
F_303 ( V_2 , V_2 -> V_84 [ V_49 ] ) ;
F_276 ( 10000 , 20000 ) ;
F_394 ( V_77 ) ;
F_434 ( V_77 ) ;
F_435 ( V_77 ) ;
F_403 ( V_2 -> V_77 ,
F_433 , NULL ) ;
F_270 ( V_2 ) ;
F_360 ( V_2 ) ;
F_37 ( V_163 , & V_2 -> V_35 ) ;
V_2 -> V_368 &= ~ V_410 ;
V_2 -> V_148 &= ~ V_397 ;
F_436 ( & V_2 -> V_746 ) ;
if ( V_2 -> V_339 ) {
F_74 ( & V_2 -> V_14 , V_341 , 0 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_339 ; V_49 ++ )
V_2 -> V_556 [ V_49 ] . V_762 = false ;
F_437 ( V_2 ) ;
F_438 ( V_2 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ ) {
T_4 V_158 = V_2 -> V_92 [ V_49 ] -> V_158 ;
F_74 ( V_14 , F_53 ( V_158 ) , V_763 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ ) {
T_4 V_158 = V_2 -> V_94 [ V_49 ] -> V_158 ;
F_74 ( V_14 , F_53 ( V_158 ) , V_763 ) ;
}
switch ( V_14 -> V_118 . type ) {
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
F_74 ( V_14 , V_473 ,
( F_40 ( V_14 , V_473 ) &
~ V_474 ) ) ;
break;
default:
break;
}
if ( ! F_439 ( V_2 -> V_9 ) )
F_424 ( V_2 ) ;
if ( V_14 -> V_118 . V_374 . V_764 )
V_14 -> V_118 . V_374 . V_764 ( V_14 ) ;
F_430 ( V_2 ) ;
F_429 ( V_2 ) ;
}
static void F_440 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_21 ) {
case V_379 :
case V_380 :
if ( ! V_14 -> V_46 . V_765 )
break;
V_2 -> V_368 |= V_766 ;
if ( ! V_14 -> V_46 . V_767 )
break;
V_2 -> V_368 |= V_768 ;
break;
default:
V_2 -> V_368 &= ~ V_766 ;
V_2 -> V_368 &= ~ V_768 ;
break;
}
}
static void F_441 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
F_90 ( V_2 ) ;
}
static void F_442 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_769 * V_143 ;
int V_60 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
case V_121 :
V_2 -> V_145 . V_770 . V_771 = V_684 ;
V_2 -> V_145 . V_770 . V_772 = V_684 ;
break;
case V_122 :
case V_123 :
V_2 -> V_145 . V_770 . V_771 = V_773 ;
V_2 -> V_145 . V_770 . V_772 = V_773 ;
break;
case V_124 :
case V_125 :
default:
V_2 -> V_145 . V_770 . V_771 = V_774 ;
V_2 -> V_145 . V_770 . V_772 = V_774 ;
break;
}
for ( V_60 = 0 ; V_60 < V_684 ; V_60 ++ ) {
V_143 = & V_2 -> V_145 . V_775 [ V_60 ] ;
V_143 -> V_776 [ V_667 ] . V_777 = 0 ;
V_143 -> V_776 [ V_667 ] . V_778 = 12 + ( V_60 & 1 ) ;
V_143 -> V_776 [ V_668 ] . V_777 = 0 ;
V_143 -> V_776 [ V_668 ] . V_778 = 12 + ( V_60 & 1 ) ;
V_143 -> V_779 = V_780 ;
}
V_143 = & V_2 -> V_145 . V_775 [ 0 ] ;
V_143 -> V_776 [ V_667 ] . V_781 = 0xFF ;
V_143 -> V_776 [ V_668 ] . V_781 = 0xFF ;
V_2 -> V_145 . V_782 [ V_667 ] [ 0 ] = 100 ;
V_2 -> V_145 . V_782 [ V_668 ] [ 0 ] = 100 ;
V_2 -> V_145 . V_146 = false ;
V_2 -> V_783 = 0x00 ;
if ( V_2 -> V_148 & V_784 )
V_2 -> V_665 = V_785 | V_666 ;
memcpy ( & V_2 -> V_786 , & V_2 -> V_145 ,
sizeof( V_2 -> V_786 ) ) ;
}
static int F_443 ( struct V_1 * V_2 ,
const struct V_787 * V_788 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_226 , V_789 ;
T_1 V_790 ;
int V_49 ;
V_14 -> V_791 = V_9 -> V_792 ;
V_14 -> V_21 = V_9 -> V_211 ;
V_14 -> V_793 = V_9 -> V_794 ;
V_14 -> V_795 = V_9 -> V_796 ;
V_14 -> V_797 = V_9 -> V_798 ;
V_788 -> V_799 ( V_14 ) ;
V_226 = F_353 ( int , F_444 ( V_2 ) , F_445 () ) ;
V_2 -> V_462 [ V_477 ] . V_800 = V_226 ;
V_2 -> V_368 |= V_801 ;
V_2 -> V_802 = V_803 ;
V_2 -> V_447 = 20 ;
V_789 = F_353 ( int , V_804 , F_445 () ) ;
V_2 -> V_462 [ V_805 ] . V_800 = V_789 ;
V_2 -> V_687 = V_806 ;
#ifdef F_257
V_2 -> V_148 |= V_213 ;
#endif
#ifdef F_405
V_2 -> V_148 |= V_784 ;
V_2 -> V_148 &= ~ V_149 ;
#endif
#ifdef F_184
V_2 -> V_148 |= V_807 ;
V_2 -> V_148 &= ~ V_564 ;
#ifdef F_405
V_2 -> V_679 . V_680 = V_808 ;
#endif
#endif
V_2 -> V_809 [ 0 ] = F_288 ( sizeof( * V_2 -> V_809 [ 0 ] ) ,
V_486 ) ;
if ( ! V_2 -> V_809 [ 0 ] )
return - V_487 ;
V_2 -> V_809 [ 0 ] -> V_810 = V_811 ;
for ( V_49 = 1 ; V_49 < V_812 ; V_49 ++ )
V_2 -> V_809 [ V_49 ] = NULL ;
V_2 -> V_621 = F_288 ( sizeof( struct V_620 ) *
V_14 -> V_118 . V_622 ,
V_813 ) ;
if ( ! V_2 -> V_621 )
return - V_487 ;
if ( F_287 ( V_2 ) )
return - V_487 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_2 -> V_368 &= ~ V_801 ;
if ( V_14 -> V_21 == V_814 )
V_2 -> V_148 |= V_382 ;
V_2 -> V_802 = V_815 ;
V_2 -> V_462 [ V_805 ] . V_800 = 0 ;
V_2 -> V_447 = 0 ;
V_2 -> V_687 = 0 ;
#ifdef F_184
V_2 -> V_148 &= ~ V_807 ;
V_2 -> V_148 &= ~ V_564 ;
#ifdef F_405
V_2 -> V_679 . V_680 = 0 ;
#endif
#endif
break;
case V_121 :
if ( V_14 -> V_21 == V_371 )
V_2 -> V_368 |= V_369 ;
break;
case V_122 :
V_790 = F_40 ( V_14 , F_446 ( V_14 ) ) ;
if ( V_790 & V_816 )
V_2 -> V_368 |= V_369 ;
break;
case V_125 :
V_2 -> V_148 |= V_658 ;
switch ( V_14 -> V_21 ) {
case V_379 :
case V_380 :
V_2 -> V_368 |= V_369 ;
break;
default:
break;
}
case V_124 :
#ifdef F_405
V_2 -> V_148 &= ~ V_784 ;
#endif
#ifdef F_184
V_2 -> V_148 &= ~ V_807 ;
#ifdef F_405
V_2 -> V_679 . V_680 = 0 ;
#endif
#endif
case V_123 :
if ( V_14 -> V_118 . type == V_123 )
V_2 -> V_368 |= V_369 ;
#ifdef F_257
V_2 -> V_148 &= ~ V_213 ;
#endif
V_2 -> V_148 |= V_657 ;
break;
default:
break;
}
#ifdef F_184
F_447 ( & V_2 -> V_679 . V_817 ) ;
#endif
F_447 ( & V_2 -> V_694 ) ;
#ifdef F_405
F_442 ( V_2 ) ;
#endif
V_14 -> V_134 . V_818 = V_136 ;
V_14 -> V_134 . V_135 = V_136 ;
F_379 ( V_2 ) ;
V_14 -> V_134 . V_819 = V_820 ;
V_14 -> V_134 . V_821 = true ;
V_14 -> V_134 . V_822 = F_448 ( V_14 ) ;
#ifdef F_335
if ( V_823 > 0 )
F_11 ( L_98 ) ;
if ( V_14 -> V_118 . type != V_119 ) {
if ( V_823 > V_824 ) {
V_823 = 0 ;
F_11 ( L_99 ) ;
}
}
#endif
V_2 -> V_428 = 1 ;
V_2 -> V_825 = 1 ;
V_2 -> V_826 = V_827 ;
V_2 -> V_828 = V_829 ;
V_2 -> V_830 = V_831 ;
if ( F_449 ( V_14 ) ) {
F_18 ( L_100 ) ;
return - V_832 ;
}
F_91 ( 0 , & V_2 -> V_710 ) ;
F_91 ( V_34 , & V_2 -> V_35 ) ;
return 0 ;
}
int F_450 ( struct V_63 * V_92 )
{
struct V_211 * V_89 = V_92 -> V_89 ;
int V_833 = F_451 ( V_89 ) ;
int V_834 = - 1 ;
int V_304 ;
V_304 = sizeof( struct V_66 ) * V_92 -> V_98 ;
if ( V_92 -> V_174 )
V_834 = V_92 -> V_174 -> V_835 ;
V_92 -> V_68 = F_452 ( V_304 , V_834 ) ;
if ( ! V_92 -> V_68 )
V_92 -> V_68 = F_453 ( V_304 ) ;
if ( ! V_92 -> V_68 )
goto V_17;
F_454 ( & V_92 -> V_187 ) ;
V_92 -> V_304 = V_92 -> V_98 * sizeof( union V_78 ) ;
V_92 -> V_304 = F_175 ( V_92 -> V_304 , 4096 ) ;
F_455 ( V_89 , V_834 ) ;
V_92 -> V_97 = F_456 ( V_89 ,
V_92 -> V_304 ,
& V_92 -> V_72 ,
V_486 ) ;
F_455 ( V_89 , V_833 ) ;
if ( ! V_92 -> V_97 )
V_92 -> V_97 = F_456 ( V_89 , V_92 -> V_304 ,
& V_92 -> V_72 , V_486 ) ;
if ( ! V_92 -> V_97 )
goto V_17;
V_92 -> V_70 = 0 ;
V_92 -> V_69 = 0 ;
return 0 ;
V_17:
F_457 ( V_92 -> V_68 ) ;
V_92 -> V_68 = NULL ;
F_458 ( V_89 , L_101 ) ;
return - V_487 ;
}
static int F_459 ( struct V_1 * V_2 )
{
int V_49 , V_60 = 0 , V_17 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ ) {
V_17 = F_450 ( V_2 -> V_92 [ V_49 ] ) ;
if ( ! V_17 )
continue;
F_107 ( V_190 , L_102 , V_49 ) ;
goto V_836;
}
for ( V_60 = 0 ; V_60 < V_2 -> V_93 ; V_60 ++ ) {
V_17 = F_450 ( V_2 -> V_94 [ V_60 ] ) ;
if ( ! V_17 )
continue;
F_107 ( V_190 , L_102 , V_60 ) ;
goto V_836;
}
return 0 ;
V_836:
while ( V_60 -- )
F_460 ( V_2 -> V_94 [ V_60 ] ) ;
while ( V_49 -- )
F_460 ( V_2 -> V_92 [ V_49 ] ) ;
return V_17 ;
}
int F_461 ( struct V_1 * V_2 ,
struct V_63 * V_84 )
{
struct V_211 * V_89 = V_84 -> V_89 ;
int V_833 = F_451 ( V_89 ) ;
int V_834 = - 1 ;
int V_304 ;
V_304 = sizeof( struct V_87 ) * V_84 -> V_98 ;
if ( V_84 -> V_174 )
V_834 = V_84 -> V_174 -> V_835 ;
V_84 -> V_88 = F_452 ( V_304 , V_834 ) ;
if ( ! V_84 -> V_88 )
V_84 -> V_88 = F_453 ( V_304 ) ;
if ( ! V_84 -> V_88 )
goto V_17;
F_454 ( & V_84 -> V_187 ) ;
V_84 -> V_304 = V_84 -> V_98 * sizeof( union V_85 ) ;
V_84 -> V_304 = F_175 ( V_84 -> V_304 , 4096 ) ;
F_455 ( V_89 , V_834 ) ;
V_84 -> V_97 = F_456 ( V_89 ,
V_84 -> V_304 ,
& V_84 -> V_72 ,
V_486 ) ;
F_455 ( V_89 , V_833 ) ;
if ( ! V_84 -> V_97 )
V_84 -> V_97 = F_456 ( V_89 , V_84 -> V_304 ,
& V_84 -> V_72 , V_486 ) ;
if ( ! V_84 -> V_97 )
goto V_17;
V_84 -> V_69 = 0 ;
V_84 -> V_70 = 0 ;
V_84 -> V_317 = V_2 -> V_317 ;
return 0 ;
V_17:
F_457 ( V_84 -> V_88 ) ;
V_84 -> V_88 = NULL ;
F_458 ( V_89 , L_103 ) ;
return - V_487 ;
}
static int F_462 ( struct V_1 * V_2 )
{
int V_49 , V_17 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
V_17 = F_461 ( V_2 , V_2 -> V_84 [ V_49 ] ) ;
if ( ! V_17 )
continue;
F_107 ( V_190 , L_104 , V_49 ) ;
goto V_837;
}
#ifdef F_184
V_17 = F_463 ( V_2 ) ;
if ( ! V_17 )
#endif
return 0 ;
V_837:
while ( V_49 -- )
F_464 ( V_2 -> V_84 [ V_49 ] ) ;
return V_17 ;
}
void F_460 ( struct V_63 * V_92 )
{
F_427 ( V_92 ) ;
F_457 ( V_92 -> V_68 ) ;
V_92 -> V_68 = NULL ;
if ( ! V_92 -> V_97 )
return;
F_465 ( V_92 -> V_89 , V_92 -> V_304 ,
V_92 -> V_97 , V_92 -> V_72 ) ;
V_92 -> V_97 = NULL ;
}
static void F_466 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ )
if ( V_2 -> V_92 [ V_49 ] -> V_97 )
F_460 ( V_2 -> V_92 [ V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ )
if ( V_2 -> V_94 [ V_49 ] -> V_97 )
F_460 ( V_2 -> V_94 [ V_49 ] ) ;
}
void F_464 ( struct V_63 * V_84 )
{
F_390 ( V_84 ) ;
V_84 -> V_317 = NULL ;
F_457 ( V_84 -> V_88 ) ;
V_84 -> V_88 = NULL ;
if ( ! V_84 -> V_97 )
return;
F_465 ( V_84 -> V_89 , V_84 -> V_304 ,
V_84 -> V_97 , V_84 -> V_72 ) ;
V_84 -> V_97 = NULL ;
}
static void F_467 ( struct V_1 * V_2 )
{
int V_49 ;
#ifdef F_184
F_468 ( V_2 ) ;
#endif
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ )
if ( V_2 -> V_84 [ V_49 ] -> V_97 )
F_464 ( V_2 -> V_84 [ V_49 ] ) ;
}
static int F_469 ( struct V_76 * V_77 , int V_838 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
if ( ( V_2 -> V_148 & V_457 ) &&
( V_2 -> V_14 . V_118 . type == V_121 ) &&
( V_838 > V_839 ) )
F_27 ( V_190 , L_105 ) ;
F_109 ( V_190 , L_106 , V_77 -> V_333 , V_838 ) ;
V_77 -> V_333 = V_838 ;
if ( F_63 ( V_77 ) )
F_416 ( V_2 ) ;
return 0 ;
}
int F_470 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 , V_401 ;
if ( F_14 ( V_840 , & V_2 -> V_35 ) )
return - V_841 ;
F_434 ( V_77 ) ;
V_17 = F_459 ( V_2 ) ;
if ( V_17 )
goto V_836;
V_17 = F_462 ( V_2 ) ;
if ( V_17 )
goto V_837;
F_404 ( V_2 ) ;
V_17 = F_268 ( V_2 ) ;
if ( V_17 )
goto V_842;
if ( V_2 -> V_711 > 1 )
V_401 = V_2 -> V_702 ;
else
V_401 = V_2 -> V_91 ;
V_17 = F_397 ( V_77 , V_401 ) ;
if ( V_17 )
goto V_843;
if ( V_2 -> V_711 > 1 &&
V_2 -> V_104 > V_844 )
V_401 = V_844 ;
else
V_401 = V_2 -> V_104 ;
V_17 = F_398 ( V_77 , V_401 ) ;
if ( V_17 )
goto V_843;
F_471 ( V_2 ) ;
F_414 ( V_2 ) ;
F_362 ( V_2 , V_845 ) ;
F_472 ( V_77 ) ;
return 0 ;
V_843:
F_269 ( V_2 ) ;
V_842:
F_467 ( V_2 ) ;
if ( V_14 -> V_46 . V_374 . V_742 && ! V_2 -> V_759 )
V_14 -> V_46 . V_374 . V_742 ( & V_2 -> V_14 , false ) ;
V_837:
F_466 ( V_2 ) ;
V_836:
F_424 ( V_2 ) ;
return V_17 ;
}
static void F_473 ( struct V_1 * V_2 )
{
F_474 ( V_2 ) ;
if ( V_2 -> V_14 . V_46 . V_374 . V_846 ) {
V_2 -> V_14 . V_46 . V_847 = true ;
F_421 ( V_2 ) ;
V_2 -> V_14 . V_46 . V_374 . V_846 ( & V_2 -> V_14 ) ;
V_2 -> V_14 . V_46 . V_847 = false ;
} else {
F_421 ( V_2 ) ;
}
F_269 ( V_2 ) ;
F_466 ( V_2 ) ;
F_467 ( V_2 ) ;
}
int F_475 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
F_476 ( V_2 ) ;
if ( F_477 ( V_77 ) )
F_473 ( V_2 ) ;
F_431 ( V_2 ) ;
F_73 ( V_2 ) ;
return 0 ;
}
static int F_478 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_479 ( V_9 ) ;
struct V_76 * V_77 = V_2 -> V_77 ;
T_1 V_17 ;
V_2 -> V_14 . V_41 = V_2 -> V_446 ;
F_480 ( V_9 , V_848 ) ;
F_481 ( V_9 ) ;
F_482 ( V_9 ) ;
V_17 = F_483 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_107 ) ;
return V_17 ;
}
F_36 () ;
F_37 ( V_849 , & V_2 -> V_35 ) ;
F_484 ( V_9 ) ;
F_485 ( V_9 , false ) ;
F_424 ( V_2 ) ;
F_74 ( & V_2 -> V_14 , V_850 , ~ 0 ) ;
F_486 () ;
V_17 = F_487 ( V_2 ) ;
if ( ! V_17 && F_63 ( V_77 ) )
V_17 = F_470 ( V_77 ) ;
if ( ! V_17 )
F_488 ( V_77 ) ;
F_489 () ;
return V_17 ;
}
static int F_490 ( struct V_5 * V_9 , bool * V_851 )
{
struct V_1 * V_2 = F_479 ( V_9 ) ;
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_852 , V_636 ;
T_1 V_853 = V_2 -> V_759 ;
#ifdef F_491
int V_854 = 0 ;
#endif
F_486 () ;
F_492 ( V_77 ) ;
if ( F_63 ( V_77 ) )
F_473 ( V_2 ) ;
F_493 ( V_2 ) ;
F_489 () ;
#ifdef F_491
V_854 = F_482 ( V_9 ) ;
if ( V_854 )
return V_854 ;
#endif
if ( V_14 -> V_118 . V_374 . V_855 )
V_14 -> V_118 . V_374 . V_855 ( V_14 ) ;
if ( V_853 ) {
F_355 ( V_77 ) ;
if ( V_14 -> V_118 . V_374 . V_741 )
V_14 -> V_118 . V_374 . V_741 ( V_14 ) ;
if ( V_853 & V_856 ) {
V_636 = F_40 ( V_14 , V_640 ) ;
V_636 |= V_646 ;
F_74 ( V_14 , V_640 , V_636 ) ;
}
V_852 = F_40 ( V_14 , V_857 ) ;
V_852 |= V_858 ;
F_74 ( V_14 , V_857 , V_852 ) ;
F_74 ( V_14 , V_859 , V_853 ) ;
} else {
F_74 ( V_14 , V_860 , 0 ) ;
F_74 ( V_14 , V_859 , 0 ) ;
}
switch ( V_14 -> V_118 . type ) {
case V_119 :
F_485 ( V_9 , false ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
F_485 ( V_9 , ! ! V_853 ) ;
break;
default:
break;
}
* V_851 = ! ! V_853 ;
if ( V_14 -> V_46 . V_374 . V_742 && ! * V_851 )
V_14 -> V_46 . V_374 . V_742 ( V_14 , false ) ;
F_73 ( V_2 ) ;
if ( ! F_15 ( V_849 , & V_2 -> V_35 ) )
F_494 ( V_9 ) ;
return 0 ;
}
static int F_495 ( struct V_5 * V_9 , T_13 V_35 )
{
int V_854 ;
bool V_861 ;
V_854 = F_490 ( V_9 , & V_861 ) ;
if ( V_854 )
return V_854 ;
if ( V_861 ) {
F_496 ( V_9 ) ;
} else {
F_485 ( V_9 , false ) ;
F_480 ( V_9 , V_862 ) ;
}
return 0 ;
}
static void F_497 ( struct V_5 * V_9 )
{
bool V_861 ;
F_490 ( V_9 , & V_861 ) ;
if ( V_863 == V_864 ) {
F_485 ( V_9 , V_861 ) ;
F_480 ( V_9 , V_862 ) ;
}
}
void F_498 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_131 * V_132 = & V_2 -> V_133 ;
V_71 V_865 = 0 ;
T_1 V_49 , V_866 = 0 , V_867 , V_868 , V_869 , V_870 , V_871 ;
V_71 V_287 = 0 , V_192 = 0 , V_872 = 0 ;
V_71 V_254 = 0 , V_332 = 0 ;
V_71 V_188 = 0 , V_153 = 0 , V_873 = 0 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_748 , & V_2 -> V_35 ) )
return;
if ( V_2 -> V_368 & V_573 ) {
V_71 V_268 = 0 ;
V_71 V_269 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
V_268 += V_2 -> V_84 [ V_49 ] -> V_240 . V_268 ;
V_269 += V_2 -> V_84 [ V_49 ] -> V_240 . V_269 ;
}
V_2 -> V_874 = V_268 ;
V_2 -> V_875 = V_269 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
struct V_63 * V_84 = V_2 -> V_84 [ V_49 ] ;
V_287 += V_84 -> V_240 . V_287 ;
V_254 += V_84 -> V_240 . V_254 ;
V_332 += V_84 -> V_240 . V_332 ;
V_873 += V_84 -> V_240 . V_241 ;
V_188 += V_84 -> V_133 . V_188 ;
V_153 += V_84 -> V_133 . V_153 ;
}
V_2 -> V_287 = V_287 ;
V_2 -> V_254 = V_254 ;
V_2 -> V_332 = V_332 ;
V_2 -> V_873 = V_873 ;
V_77 -> V_133 . V_876 = V_188 ;
V_77 -> V_133 . V_877 = V_153 ;
V_188 = 0 ;
V_153 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ ) {
struct V_63 * V_92 = V_2 -> V_92 [ V_49 ] ;
V_192 += V_92 -> V_161 . V_192 ;
V_872 += V_92 -> V_161 . V_872 ;
V_188 += V_92 -> V_133 . V_188 ;
V_153 += V_92 -> V_133 . V_153 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ ) {
struct V_63 * V_94 = V_2 -> V_94 [ V_49 ] ;
V_192 += V_94 -> V_161 . V_192 ;
V_872 += V_94 -> V_161 . V_872 ;
V_188 += V_94 -> V_133 . V_188 ;
V_153 += V_94 -> V_133 . V_153 ;
}
V_2 -> V_192 = V_192 ;
V_2 -> V_872 = V_872 ;
V_77 -> V_133 . V_878 = V_188 ;
V_77 -> V_133 . V_879 = V_153 ;
V_132 -> V_880 += F_40 ( V_14 , V_881 ) ;
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
V_867 = F_40 ( V_14 , F_499 ( V_49 ) ) ;
V_866 += V_867 ;
V_132 -> V_867 [ V_49 ] += V_867 ;
V_865 += V_132 -> V_867 [ V_49 ] ;
V_132 -> V_882 [ V_49 ] += F_40 ( V_14 , F_500 ( V_49 ) ) ;
V_132 -> V_883 [ V_49 ] += F_40 ( V_14 , F_501 ( V_49 ) ) ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_132 -> V_884 [ V_49 ] += F_40 ( V_14 , F_502 ( V_49 ) ) ;
V_132 -> V_885 [ V_49 ] += F_40 ( V_14 , F_503 ( V_49 ) ) ;
V_132 -> V_886 [ V_49 ] += F_40 ( V_14 , F_504 ( V_49 ) ) ;
V_132 -> V_887 [ V_49 ] +=
F_40 ( V_14 , F_505 ( V_49 ) ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_132 -> V_887 [ V_49 ] +=
F_40 ( V_14 , F_506 ( V_49 ) ) ;
break;
default:
break;
}
}
for ( V_49 = 0 ; V_49 < 16 ; V_49 ++ ) {
V_132 -> V_888 [ V_49 ] += F_40 ( V_14 , F_507 ( V_49 ) ) ;
V_132 -> V_889 [ V_49 ] += F_40 ( V_14 , F_508 ( V_49 ) ) ;
if ( ( V_14 -> V_118 . type == V_121 ) ||
( V_14 -> V_118 . type == V_122 ) ||
( V_14 -> V_118 . type == V_123 ) ||
( V_14 -> V_118 . type == V_124 ) ||
( V_14 -> V_118 . type == V_125 ) ) {
V_132 -> V_885 [ V_49 ] += F_40 ( V_14 , F_509 ( V_49 ) ) ;
F_40 ( V_14 , F_510 ( V_49 ) ) ;
V_132 -> V_886 [ V_49 ] += F_40 ( V_14 , F_511 ( V_49 ) ) ;
F_40 ( V_14 , F_512 ( V_49 ) ) ;
}
}
V_132 -> V_890 += F_40 ( V_14 , V_891 ) ;
V_132 -> V_890 -= V_866 ;
F_81 ( V_2 ) ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_132 -> V_892 += F_40 ( V_14 , V_893 ) ;
V_132 -> V_894 += F_40 ( V_14 , V_895 ) ;
V_132 -> V_896 += F_40 ( V_14 , V_897 ) ;
V_132 -> V_898 += F_40 ( V_14 , V_899 ) ;
break;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_132 -> V_900 += F_40 ( V_14 , V_901 ) ;
V_132 -> V_902 += F_40 ( V_14 , V_903 ) ;
V_132 -> V_904 += F_40 ( V_14 , V_905 ) ;
V_132 -> V_906 += F_40 ( V_14 , V_907 ) ;
case V_121 :
for ( V_49 = 0 ; V_49 < 16 ; V_49 ++ )
V_2 -> V_908 +=
F_40 ( V_14 , F_513 ( V_49 ) ) ;
V_132 -> V_894 += F_40 ( V_14 , V_909 ) ;
F_40 ( V_14 , V_895 ) ;
V_132 -> V_896 += F_40 ( V_14 , V_910 ) ;
F_40 ( V_14 , V_897 ) ;
V_132 -> V_898 += F_40 ( V_14 , V_911 ) ;
F_40 ( V_14 , V_899 ) ;
V_132 -> V_892 += F_40 ( V_14 , V_912 ) ;
V_132 -> V_913 += F_40 ( V_14 , V_914 ) ;
V_132 -> V_915 += F_40 ( V_14 , V_916 ) ;
#ifdef F_184
V_132 -> V_917 += F_40 ( V_14 , V_918 ) ;
V_132 -> V_919 += F_40 ( V_14 , V_920 ) ;
V_132 -> V_921 += F_40 ( V_14 , V_922 ) ;
V_132 -> V_923 += F_40 ( V_14 , V_924 ) ;
V_132 -> V_925 += F_40 ( V_14 , V_926 ) ;
V_132 -> V_927 += F_40 ( V_14 , V_928 ) ;
if ( V_2 -> V_679 . V_929 ) {
struct V_930 * V_679 = & V_2 -> V_679 ;
struct V_931 * V_929 ;
unsigned int V_193 ;
V_71 V_932 = 0 , V_933 = 0 ;
F_514 (cpu) {
V_929 = F_515 ( V_679 -> V_929 , V_193 ) ;
V_932 += V_929 -> V_932 ;
V_933 += V_929 -> V_933 ;
}
V_132 -> V_934 = V_932 ;
V_132 -> V_935 = V_933 ;
}
#endif
break;
default:
break;
}
V_868 = F_40 ( V_14 , V_936 ) ;
V_132 -> V_868 += V_868 ;
V_132 -> V_937 += F_40 ( V_14 , V_938 ) ;
if ( V_14 -> V_118 . type == V_119 )
V_132 -> V_937 -= V_868 ;
V_132 -> V_939 += F_40 ( V_14 , V_940 ) ;
V_132 -> V_941 += F_40 ( V_14 , V_942 ) ;
V_132 -> V_943 += F_40 ( V_14 , V_944 ) ;
V_132 -> V_945 += F_40 ( V_14 , V_946 ) ;
V_132 -> V_947 += F_40 ( V_14 , V_948 ) ;
V_132 -> V_949 += F_40 ( V_14 , V_950 ) ;
V_132 -> V_951 += F_40 ( V_14 , V_952 ) ;
V_132 -> V_953 += F_40 ( V_14 , V_954 ) ;
V_869 = F_40 ( V_14 , V_955 ) ;
V_132 -> V_956 += V_869 ;
V_870 = F_40 ( V_14 , V_957 ) ;
V_132 -> V_958 += V_870 ;
V_132 -> V_959 += F_40 ( V_14 , V_960 ) ;
V_132 -> V_961 += F_40 ( V_14 , V_962 ) ;
V_871 = V_869 + V_870 ;
V_132 -> V_959 -= V_871 ;
V_132 -> V_961 -= V_871 ;
V_132 -> V_896 -= ( V_871 * ( V_963 + V_561 ) ) ;
V_132 -> V_964 += F_40 ( V_14 , V_965 ) ;
V_132 -> V_966 += F_40 ( V_14 , V_967 ) ;
V_132 -> V_968 += F_40 ( V_14 , V_969 ) ;
V_132 -> V_970 += F_40 ( V_14 , V_971 ) ;
V_132 -> V_972 += F_40 ( V_14 , V_973 ) ;
V_132 -> V_972 -= V_871 ;
V_132 -> V_974 += F_40 ( V_14 , V_975 ) ;
V_132 -> V_976 += F_40 ( V_14 , V_977 ) ;
V_132 -> V_978 += F_40 ( V_14 , V_979 ) ;
V_132 -> V_980 += F_40 ( V_14 , V_981 ) ;
V_132 -> V_982 += F_40 ( V_14 , V_983 ) ;
V_132 -> V_984 += F_40 ( V_14 , V_985 ) ;
V_77 -> V_133 . V_986 = V_132 -> V_937 ;
V_77 -> V_133 . V_987 = V_132 -> V_880 + V_132 -> V_953 ;
V_77 -> V_133 . V_988 = 0 ;
V_77 -> V_133 . V_989 = V_132 -> V_953 ;
V_77 -> V_133 . V_990 = V_132 -> V_880 ;
V_77 -> V_133 . V_991 = V_865 ;
}
static void F_516 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( ! ( V_2 -> V_368 & V_410 ) )
return;
V_2 -> V_368 &= ~ V_410 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
if ( ! ( V_2 -> V_148 & V_409 ) )
return;
V_2 -> V_992 ++ ;
if ( F_517 ( V_14 ) == 0 ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ )
F_91 ( V_419 ,
& ( V_2 -> V_92 [ V_49 ] -> V_35 ) ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ )
F_91 ( V_419 ,
& V_2 -> V_94 [ V_49 ] -> V_35 ) ;
F_74 ( V_14 , V_400 , V_411 ) ;
} else {
F_107 ( V_190 , L_108
L_109 ) ;
}
}
static void F_518 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_71 V_993 = 0 ;
int V_49 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_748 , & V_2 -> V_35 ) )
return;
if ( F_113 ( V_2 -> V_77 ) ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ )
F_519 ( V_2 -> V_92 [ V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ )
F_519 ( V_2 -> V_94 [ V_49 ] ) ;
}
if ( ! ( V_2 -> V_148 & V_437 ) ) {
F_74 ( V_14 , V_130 ,
( V_994 | V_995 ) ) ;
} else {
for ( V_49 = 0 ; V_49 < V_2 -> V_210 ; V_49 ++ ) {
struct V_173 * V_996 = V_2 -> V_174 [ V_49 ] ;
if ( V_996 -> V_337 . V_64 || V_996 -> V_179 . V_64 )
V_993 |= F_259 ( V_49 ) ;
}
}
F_78 ( V_2 , V_993 ) ;
}
static void F_520 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_997 = V_2 -> V_997 ;
bool V_376 = V_2 -> V_376 ;
bool V_144 = V_2 -> V_145 . V_146 ;
if ( ! ( V_2 -> V_148 & V_397 ) )
return;
if ( V_14 -> V_118 . V_374 . V_375 ) {
V_14 -> V_118 . V_374 . V_375 ( V_14 , & V_997 , & V_376 , false ) ;
} else {
V_997 = V_998 ;
V_376 = true ;
}
if ( V_2 -> V_147 )
V_144 |= ! ! ( V_2 -> V_147 -> V_144 ) ;
if ( V_376 && ! ( ( V_2 -> V_148 & V_149 ) && V_144 ) ) {
V_14 -> V_118 . V_374 . V_999 ( V_14 ) ;
F_521 ( V_2 ) ;
}
if ( V_376 ||
F_522 ( V_189 , ( V_2 -> V_398 +
V_1000 ) ) ) {
V_2 -> V_148 &= ~ V_397 ;
F_74 ( V_14 , V_400 , V_399 ) ;
F_240 ( V_14 ) ;
}
V_2 -> V_376 = V_376 ;
V_2 -> V_997 = V_997 ;
}
static void F_523 ( struct V_1 * V_2 )
{
#ifdef F_405
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_1001 V_1002 = {
. V_1003 = V_1004 ,
. V_276 = 0 ,
} ;
T_4 V_680 = 0 ;
if ( V_2 -> V_665 & V_1005 )
V_680 = F_524 ( V_77 , & V_1002 ) ;
V_2 -> V_1006 = ( V_680 > 1 ) ? ( F_525 ( V_680 ) - 1 ) : 0 ;
#endif
}
static int F_526 ( struct V_76 * V_106 , void * V_103 )
{
if ( F_401 ( V_106 ) ) {
struct V_714 * V_274 = F_87 ( V_106 ) ;
if ( V_274 -> V_716 )
F_527 ( V_106 ) ;
}
return 0 ;
}
static void F_528 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_997 = V_2 -> V_997 ;
const char * V_1007 ;
bool V_1008 , V_1009 ;
if ( F_113 ( V_77 ) )
return;
V_2 -> V_368 &= ~ V_719 ;
switch ( V_14 -> V_118 . type ) {
case V_119 : {
T_1 V_1010 = F_40 ( V_14 , V_640 ) ;
T_1 V_1011 = F_40 ( V_14 , V_1012 ) ;
V_1008 = ! ! ( V_1010 & V_1013 ) ;
V_1009 = ! ! ( V_1011 & V_1014 ) ;
}
break;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_121 : {
T_1 V_1015 = F_40 ( V_14 , V_1016 ) ;
T_1 V_1017 = F_40 ( V_14 , V_1018 ) ;
V_1008 = ! ! ( V_1015 & V_1019 ) ;
V_1009 = ! ! ( V_1017 & V_1020 ) ;
}
break;
default:
V_1009 = false ;
V_1008 = false ;
break;
}
V_2 -> V_1021 = V_189 ;
if ( F_14 ( V_758 , & V_2 -> V_35 ) )
F_529 ( V_2 ) ;
switch ( V_997 ) {
case V_998 :
V_1007 = L_110 ;
break;
case V_1022 :
V_1007 = L_111 ;
break;
case V_1023 :
V_1007 = L_112 ;
break;
case V_1024 :
V_1007 = L_113 ;
break;
case V_1025 :
V_1007 = L_114 ;
break;
default:
V_1007 = L_115 ;
break;
}
F_109 ( V_164 , L_116 , V_1007 ,
( ( V_1008 && V_1009 ) ? L_117 :
( V_1008 ? L_118 :
( V_1009 ? L_119 : L_120 ) ) ) ) ;
F_530 ( V_77 ) ;
F_531 ( V_2 ) ;
F_527 ( V_2 -> V_77 ) ;
F_486 () ;
F_403 ( V_2 -> V_77 ,
F_526 , NULL ) ;
F_489 () ;
F_523 ( V_2 ) ;
F_437 ( V_2 ) ;
}
static void F_420 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_376 = false ;
V_2 -> V_997 = 0 ;
if ( ! F_113 ( V_77 ) )
return;
if ( F_236 ( V_14 ) && V_14 -> V_118 . type == V_119 )
V_2 -> V_368 |= V_719 ;
if ( F_14 ( V_758 , & V_2 -> V_35 ) )
F_529 ( V_2 ) ;
F_109 ( V_164 , L_121 ) ;
F_434 ( V_77 ) ;
F_437 ( V_2 ) ;
}
static bool F_532 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ ) {
struct V_63 * V_92 = V_2 -> V_92 [ V_49 ] ;
if ( V_92 -> V_70 != V_92 -> V_69 )
return true ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ ) {
struct V_63 * V_64 = V_2 -> V_94 [ V_49 ] ;
if ( V_64 -> V_70 != V_64 -> V_69 )
return true ;
}
return false ;
}
static bool F_533 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1026 * V_1027 = & V_2 -> V_462 [ V_463 ] ;
T_1 V_1028 = F_534 ( 1 , ~ V_1027 -> V_128 ) ;
int V_49 , V_60 ;
if ( ! V_2 -> V_339 )
return false ;
if ( V_14 -> V_118 . type >= V_123 )
return false ;
for ( V_49 = 0 ; V_49 < V_2 -> V_339 ; V_49 ++ ) {
for ( V_60 = 0 ; V_60 < V_1028 ; V_60 ++ ) {
T_1 V_1029 , V_1030 ;
V_1029 = F_40 ( V_14 , F_535 ( V_1028 , V_49 , V_60 ) ) ;
V_1030 = F_40 ( V_14 , F_536 ( V_1028 , V_49 , V_60 ) ) ;
if ( V_1029 != V_1030 )
return true ;
}
}
return false ;
}
static void F_537 ( struct V_1 * V_2 )
{
if ( ! F_113 ( V_2 -> V_77 ) ) {
if ( F_532 ( V_2 ) ||
F_533 ( V_2 ) ) {
F_27 ( V_164 , L_122 ) ;
F_91 ( V_163 , & V_2 -> V_35 ) ;
}
}
}
static void F_538 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_1031 ;
T_1 V_1032 ;
if ( ! ( F_113 ( V_2 -> V_77 ) ) )
return;
V_1032 = F_40 ( V_14 , V_1033 ) ;
if ( V_1032 )
return;
if ( ! V_9 )
return;
for ( V_1031 = 0 ; V_1031 < V_2 -> V_339 ; ++ V_1031 ) {
struct V_5 * V_1034 = V_2 -> V_556 [ V_1031 ] . V_1034 ;
T_2 V_1035 ;
if ( ! V_1034 )
continue;
F_28 ( V_1034 , V_1036 , & V_1035 ) ;
if ( V_1035 != V_13 &&
V_1035 & V_1037 )
F_539 ( V_1034 ) ;
}
}
static void F_540 ( struct V_1 * V_2 )
{
T_1 V_1038 ;
if ( V_2 -> V_14 . V_118 . type == V_119 ||
V_2 -> V_339 == 0 )
return;
V_1038 = F_40 ( & V_2 -> V_14 , V_1039 ) ;
if ( ! V_1038 )
return;
F_27 ( V_164 , L_123 , V_1038 ) ;
}
static void F_540 ( struct V_1 T_14 * V_2 )
{
}
static void
F_538 ( struct V_1 T_14 * V_2 )
{
}
static void F_541 ( struct V_1 * V_2 )
{
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_748 , & V_2 -> V_35 ) )
return;
F_520 ( V_2 ) ;
if ( V_2 -> V_376 )
F_528 ( V_2 ) ;
else
F_420 ( V_2 ) ;
F_538 ( V_2 ) ;
F_540 ( V_2 ) ;
F_498 ( V_2 ) ;
F_537 ( V_2 ) ;
}
static void F_542 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_3 V_17 ;
if ( ! ( V_2 -> V_368 & V_719 ) &&
! ( V_2 -> V_368 & V_393 ) )
return;
if ( V_2 -> V_394 &&
F_522 ( V_2 -> V_394 , V_189 ) )
return;
if ( F_15 ( V_750 , & V_2 -> V_35 ) )
return;
V_2 -> V_394 = V_189 + V_1040 - 1 ;
V_17 = V_14 -> V_46 . V_374 . V_1041 ( V_14 ) ;
if ( V_17 == V_753 )
goto V_1042;
if ( V_17 == V_752 ) {
V_2 -> V_368 |= V_393 ;
}
if ( V_17 )
goto V_1042;
if ( ! ( V_2 -> V_368 & V_393 ) )
goto V_1042;
V_2 -> V_368 &= ~ V_393 ;
if ( V_14 -> V_118 . type == V_119 )
V_17 = V_14 -> V_46 . V_374 . V_1043 ( V_14 ) ;
else
V_17 = V_14 -> V_118 . V_374 . V_1044 ( V_14 ) ;
if ( V_17 == V_753 )
goto V_1042;
V_2 -> V_148 |= V_395 ;
F_109 ( V_190 , L_124 , V_14 -> V_46 . V_1045 ) ;
V_1042:
F_37 ( V_750 , & V_2 -> V_35 ) ;
if ( ( V_17 == V_753 ) &&
( V_2 -> V_77 -> V_1046 == V_1047 ) ) {
F_18 ( L_125
L_126 ) ;
F_18 ( L_127
L_128 ) ;
F_543 ( V_2 -> V_77 ) ;
}
}
static void F_544 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_20 ;
bool V_720 = false ;
if ( ! ( V_2 -> V_148 & V_395 ) )
return;
if ( F_15 ( V_750 , & V_2 -> V_35 ) )
return;
V_2 -> V_148 &= ~ V_395 ;
V_20 = V_14 -> V_46 . V_722 ;
if ( ( ! V_20 ) && ( V_14 -> V_118 . V_374 . V_723 ) ) {
V_14 -> V_118 . V_374 . V_723 ( V_14 , & V_20 , & V_720 ) ;
if ( ! V_720 ) {
if ( V_20 & V_998 )
V_20 = V_998 ;
}
}
if ( V_14 -> V_118 . V_374 . V_724 )
V_14 -> V_118 . V_374 . V_724 ( V_14 , V_20 , true ) ;
V_2 -> V_148 |= V_397 ;
V_2 -> V_398 = V_189 ;
F_37 ( V_750 , & V_2 -> V_35 ) ;
}
static void F_545 ( unsigned long V_103 )
{
struct V_1 * V_2 = (struct V_1 * ) V_103 ;
unsigned long V_1048 ;
if ( V_2 -> V_148 & V_397 )
V_1048 = V_1049 / 10 ;
else
V_1048 = V_1049 * 2 ;
F_415 ( & V_2 -> V_746 , V_1048 + V_189 ) ;
F_13 ( V_2 ) ;
}
static void F_546 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_182 ;
if ( ! ( V_2 -> V_368 & V_414 ) )
return;
V_2 -> V_368 &= ~ V_414 ;
if ( ! V_14 -> V_46 . V_374 . V_1050 )
return;
V_182 = V_14 -> V_46 . V_374 . V_1050 ( & V_2 -> V_14 ) ;
if ( V_182 != V_378 )
return;
F_232 ( V_164 , L_69 , V_381 ) ;
}
static void F_547 ( struct V_1 * V_2 )
{
if ( ! F_251 ( V_163 , & V_2 -> V_35 ) )
return;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_748 , & V_2 -> V_35 ) )
return;
F_59 ( V_2 ) ;
F_548 ( V_2 -> V_77 , L_129 ) ;
V_2 -> V_191 ++ ;
F_486 () ;
F_416 ( V_2 ) ;
F_489 () ;
}
static void F_549 ( struct V_1051 * V_1052 )
{
struct V_1 * V_2 = F_256 ( V_1052 ,
struct V_1 ,
V_39 ) ;
if ( F_22 ( V_2 -> V_14 . V_41 ) ) {
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_486 () ;
F_421 ( V_2 ) ;
F_489 () ;
}
F_34 ( V_2 ) ;
return;
}
if ( V_2 -> V_368 & V_1053 ) {
F_486 () ;
V_2 -> V_368 &= ~ V_1053 ;
F_472 ( V_2 -> V_77 ) ;
F_489 () ;
}
F_547 ( V_2 ) ;
F_546 ( V_2 ) ;
F_542 ( V_2 ) ;
F_544 ( V_2 ) ;
F_230 ( V_2 ) ;
F_541 ( V_2 ) ;
F_516 ( V_2 ) ;
F_518 ( V_2 ) ;
if ( F_14 ( V_758 , & V_2 -> V_35 ) ) {
F_550 ( V_2 ) ;
F_551 ( V_2 ) ;
}
F_34 ( V_2 ) ;
}
static int F_552 ( struct V_63 * V_92 ,
struct V_66 * V_1054 ,
T_4 * V_263 )
{
T_1 V_1055 , V_1056 , V_1057 ;
struct V_216 * V_100 = V_1054 -> V_100 ;
union {
struct V_1058 * V_1059 ;
struct V_1060 * V_1061 ;
unsigned char * V_1062 ;
} V_1063 ;
union {
struct V_1064 * V_1065 ;
unsigned char * V_1062 ;
} V_1066 ;
T_1 V_1067 , V_1068 ;
int V_17 ;
if ( V_100 -> V_246 != V_1069 )
return 0 ;
if ( ! F_553 ( V_100 ) )
return 0 ;
V_17 = F_554 ( V_100 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_1063 . V_1062 = F_555 ( V_100 ) ;
V_1066 . V_1062 = F_556 ( V_100 ) ;
V_1056 = V_1070 ;
if ( V_1063 . V_1059 -> V_1071 == 4 ) {
unsigned char * V_1072 = F_556 ( V_100 ) ;
unsigned char * V_1073 = V_1063 . V_1062 + ( V_1063 . V_1059 -> V_1074 * 4 ) ;
V_1063 . V_1059 -> V_1075 = F_557 ( F_558 ( V_1073 ,
V_1072 - V_1073 ,
0 ) ) ;
V_1056 |= V_1076 ;
V_1063 . V_1059 -> V_1077 = 0 ;
V_1054 -> V_1078 |= V_1079 |
V_1080 |
V_1081 ;
} else {
V_1063 . V_1061 -> V_1082 = 0 ;
V_1054 -> V_1078 |= V_1079 |
V_1080 ;
}
V_1068 = V_1066 . V_1062 - V_100 -> V_103 ;
* V_263 = ( V_1066 . V_1065 -> V_1083 * 4 ) + V_1068 ;
V_1067 = V_100 -> V_73 - V_1068 ;
F_559 ( & V_1066 . V_1065 -> V_1075 , F_560 ( V_1067 ) ) ;
V_1054 -> V_185 = F_157 ( V_100 ) -> V_185 ;
V_1054 -> V_184 += ( V_1054 -> V_185 - 1 ) * * V_263 ;
V_1057 = ( * V_263 - V_1068 ) << V_1084 ;
V_1057 |= F_157 ( V_100 ) -> V_264 << V_1085 ;
V_1055 = V_1066 . V_1062 - V_1063 . V_1062 ;
V_1055 |= ( V_1063 . V_1062 - V_100 -> V_103 ) << V_1086 ;
V_1055 |= V_1054 -> V_1078 & V_1087 ;
F_561 ( V_92 , V_1055 , 0 , V_1056 ,
V_1057 ) ;
return 1 ;
}
static inline bool F_562 ( struct V_216 * V_100 )
{
unsigned int V_1088 = 0 ;
F_563 ( V_100 , & V_1088 , V_1089 , NULL , NULL ) ;
return V_1088 == F_564 ( V_100 ) ;
}
static void F_565 ( struct V_63 * V_92 ,
struct V_66 * V_1054 )
{
struct V_216 * V_100 = V_1054 -> V_100 ;
T_1 V_1055 = 0 ;
T_1 V_1056 = 0 ;
if ( V_100 -> V_246 != V_1069 ) {
V_1090:
if ( ! ( V_1054 -> V_1078 & ( V_1091 |
V_1092 ) ) )
return;
goto V_1093;
}
switch ( V_100 -> V_1094 ) {
case F_566 ( struct V_1064 , V_1075 ) :
V_1056 = V_1070 ;
case F_566 ( struct V_1095 , V_1075 ) :
break;
case F_566 ( struct V_1096 , V_1097 ) :
if ( ( ( V_1054 -> V_276 == F_164 ( V_1098 ) ) &&
( F_567 ( V_100 ) -> V_276 == V_1089 ) ) ||
( ( V_1054 -> V_276 == F_164 ( V_1099 ) ) &&
F_562 ( V_100 ) ) ) {
V_1056 = V_1100 ;
break;
}
default:
F_568 ( V_100 ) ;
goto V_1090;
}
V_1054 -> V_1078 |= V_1080 ;
V_1055 = F_564 ( V_100 ) -
F_569 ( V_100 ) ;
V_1093:
V_1055 |= F_569 ( V_100 ) << V_1086 ;
V_1055 |= V_1054 -> V_1078 & V_1087 ;
F_561 ( V_92 , V_1055 , 0 , V_1056 , 0 ) ;
}
static T_1 F_570 ( struct V_216 * V_100 , T_1 V_1078 )
{
T_1 V_1101 = V_1102 |
V_1103 |
V_1104 ;
V_1101 |= F_571 ( V_1078 , V_1091 ,
V_1105 ) ;
V_1101 |= F_571 ( V_1078 , V_1079 ,
V_1106 ) ;
V_1101 |= F_571 ( V_1078 , V_1107 ,
V_1108 ) ;
V_1101 ^= F_571 ( V_100 -> V_1109 , 1 , V_1104 ) ;
return V_1101 ;
}
static void F_572 ( union V_78 * V_79 ,
T_1 V_1078 , unsigned int V_1067 )
{
T_1 V_1110 = V_1067 << V_1111 ;
V_1110 |= F_571 ( V_1078 ,
V_1080 ,
V_1112 ) ;
V_1110 |= F_571 ( V_1078 ,
V_1081 ,
V_1113 ) ;
V_1110 |= F_571 ( V_1078 ,
V_1092 ,
V_1114 ) ;
V_79 -> V_260 . V_1110 = F_96 ( V_1110 ) ;
}
static int F_573 ( struct V_63 * V_92 , T_2 V_304 )
{
F_108 ( V_92 -> V_77 , V_92 -> V_96 ) ;
F_115 () ;
if ( F_25 ( F_114 ( V_92 ) < V_304 ) )
return - V_841 ;
F_574 ( V_92 -> V_77 , V_92 -> V_96 ) ;
++ V_92 -> V_161 . V_192 ;
return 0 ;
}
static inline int F_575 ( struct V_63 * V_92 , T_2 V_304 )
{
if ( F_25 ( F_114 ( V_92 ) >= V_304 ) )
return 0 ;
return F_573 ( V_92 , V_304 ) ;
}
static void F_576 ( struct V_63 * V_92 ,
struct V_66 * V_1054 ,
const T_4 V_263 )
{
struct V_216 * V_100 = V_1054 -> V_100 ;
struct V_66 * V_67 ;
union V_78 * V_79 ;
struct V_288 * V_289 ;
T_8 V_72 ;
unsigned int V_294 , V_304 ;
T_1 V_1078 = V_1054 -> V_1078 ;
T_1 V_1101 = F_570 ( V_100 , V_1078 ) ;
T_2 V_49 = V_92 -> V_70 ;
V_79 = F_65 ( V_92 , V_49 ) ;
F_572 ( V_79 , V_1078 , V_100 -> V_73 - V_263 ) ;
V_304 = F_156 ( V_100 ) ;
V_294 = V_100 -> V_294 ;
#ifdef F_184
if ( V_1078 & V_1115 ) {
if ( V_294 < sizeof( struct V_336 ) ) {
V_304 -= sizeof( struct V_336 ) - V_294 ;
V_294 = 0 ;
} else {
V_294 -= sizeof( struct V_336 ) ;
}
}
#endif
V_72 = F_577 ( V_92 -> V_89 , V_100 -> V_103 , V_304 , V_186 ) ;
V_67 = V_1054 ;
for ( V_289 = & F_157 ( V_100 ) -> V_290 [ 0 ] ; ; V_289 ++ ) {
if ( F_148 ( V_92 -> V_89 , V_72 ) )
goto V_1116;
F_101 ( V_67 , V_73 , V_304 ) ;
F_578 ( V_67 , V_72 , V_72 ) ;
V_79 -> V_260 . V_1117 = F_152 ( V_72 ) ;
while ( F_23 ( V_304 > V_1118 ) ) {
V_79 -> V_260 . V_1119 =
F_96 ( V_1101 ^ V_1118 ) ;
V_49 ++ ;
V_79 ++ ;
if ( V_49 == V_92 -> V_98 ) {
V_79 = F_65 ( V_92 , 0 ) ;
V_49 = 0 ;
}
V_79 -> V_260 . V_1110 = 0 ;
V_72 += V_1118 ;
V_304 -= V_1118 ;
V_79 -> V_260 . V_1117 = F_152 ( V_72 ) ;
}
if ( F_25 ( ! V_294 ) )
break;
V_79 -> V_260 . V_1119 = F_96 ( V_1101 ^ V_304 ) ;
V_49 ++ ;
V_79 ++ ;
if ( V_49 == V_92 -> V_98 ) {
V_79 = F_65 ( V_92 , 0 ) ;
V_49 = 0 ;
}
V_79 -> V_260 . V_1110 = 0 ;
#ifdef F_184
V_304 = F_353 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_304 = F_180 ( V_289 ) ;
#endif
V_294 -= V_304 ;
V_72 = F_579 ( V_92 -> V_89 , V_289 , 0 , V_304 ,
V_186 ) ;
V_67 = & V_92 -> V_68 [ V_49 ] ;
}
V_1101 |= V_304 | V_1120 ;
V_79 -> V_260 . V_1119 = F_96 ( V_1101 ) ;
F_580 ( F_111 ( V_92 ) , V_1054 -> V_184 ) ;
V_1054 -> V_75 = V_189 ;
F_153 () ;
V_1054 -> V_74 = V_79 ;
V_49 ++ ;
if ( V_49 == V_92 -> V_98 )
V_49 = 0 ;
V_92 -> V_70 = V_49 ;
F_575 ( V_92 , V_1121 ) ;
if ( F_581 ( F_111 ( V_92 ) ) || ! V_100 -> V_1122 ) {
F_154 ( V_49 , V_92 -> V_155 ) ;
F_582 () ;
}
return;
V_1116:
F_458 ( V_92 -> V_89 , L_130 ) ;
V_67 = & V_92 -> V_68 [ V_49 ] ;
while ( V_67 != V_1054 ) {
if ( F_58 ( V_67 , V_73 ) )
F_102 ( V_92 -> V_89 ,
F_57 ( V_67 , V_72 ) ,
F_58 ( V_67 , V_73 ) ,
V_186 ) ;
F_101 ( V_67 , V_73 , 0 ) ;
if ( V_49 -- )
V_49 += V_92 -> V_98 ;
V_67 = & V_92 -> V_68 [ V_49 ] ;
}
if ( F_58 ( V_67 , V_73 ) )
F_100 ( V_92 -> V_89 ,
F_57 ( V_67 , V_72 ) ,
F_58 ( V_67 , V_73 ) ,
V_186 ) ;
F_101 ( V_67 , V_73 , 0 ) ;
F_183 ( V_1054 -> V_100 ) ;
V_1054 -> V_100 = NULL ;
V_92 -> V_70 = V_49 ;
}
static void F_583 ( struct V_63 * V_64 ,
struct V_66 * V_1054 )
{
struct V_173 * V_174 = V_64 -> V_174 ;
union V_1123 V_1124 = { . V_1125 = 0 } ;
union V_1123 V_1126 = { . V_1125 = 0 } ;
union {
unsigned char * V_1127 ;
struct V_1058 * V_1128 ;
struct V_1060 * V_1129 ;
} V_1062 ;
struct V_1064 * V_1130 ;
unsigned int V_1131 ;
struct V_216 * V_100 ;
T_11 V_1132 ;
int V_1133 ;
if ( ! V_174 )
return;
if ( ! V_64 -> V_447 )
return;
V_64 -> V_448 ++ ;
if ( ( V_1054 -> V_276 != F_164 ( V_1098 ) ) &&
( V_1054 -> V_276 != F_164 ( V_1099 ) ) )
return;
V_100 = V_1054 -> V_100 ;
V_1062 . V_1127 = F_555 ( V_100 ) ;
if ( F_23 ( V_1062 . V_1127 <= V_100 -> V_103 ) )
return;
if ( V_100 -> V_237 &&
V_1054 -> V_276 == F_164 ( V_1098 ) &&
V_1062 . V_1128 -> V_276 == V_1134 ) {
struct V_1 * V_2 = V_174 -> V_2 ;
if ( F_23 ( F_584 ( V_100 ) < V_1062 . V_1127 +
V_1135 ) )
return;
if ( V_2 -> V_661 &&
F_585 ( V_100 ) -> V_1136 == V_2 -> V_661 )
V_1062 . V_1127 = F_586 ( V_100 ) ;
if ( V_2 -> V_663 &&
F_585 ( V_100 ) -> V_1136 == V_2 -> V_663 )
V_1062 . V_1127 = F_586 ( V_100 ) ;
}
if ( F_23 ( F_584 ( V_100 ) < V_1062 . V_1127 + 40 ) )
return;
switch ( V_1062 . V_1128 -> V_1071 ) {
case V_1137 :
V_1131 = ( V_1062 . V_1127 [ 0 ] & 0x0F ) << 2 ;
V_1133 = V_1062 . V_1128 -> V_276 ;
break;
case 6 :
V_1131 = V_1062 . V_1127 - V_100 -> V_103 ;
V_1133 = F_563 ( V_100 , & V_1131 , V_1138 , NULL , NULL ) ;
V_1131 -= V_1062 . V_1127 - V_100 -> V_103 ;
break;
default:
return;
}
if ( V_1133 != V_1138 )
return;
if ( F_23 ( F_584 ( V_100 ) < V_1062 . V_1127 +
V_1131 + sizeof( struct V_1064 ) ) )
return;
V_1130 = (struct V_1064 * ) ( V_1062 . V_1127 + V_1131 ) ;
if ( V_1130 -> V_1139 )
return;
if ( ! V_1130 -> V_1140 && ( V_64 -> V_448 < V_64 -> V_447 ) )
return;
V_64 -> V_448 = 0 ;
V_1132 = F_164 ( V_1054 -> V_1078 >> V_1141 ) ;
V_1124 . V_1142 . V_1132 = V_1132 ;
if ( V_1054 -> V_1078 & ( V_1143 | V_1091 ) )
V_1126 . V_1144 . V_1145 ^= V_1130 -> V_1136 ^ F_164 ( V_275 ) ;
else
V_1126 . V_1144 . V_1145 ^= V_1130 -> V_1136 ^ V_1054 -> V_276 ;
V_1126 . V_1144 . V_1146 ^= V_1130 -> V_1147 ;
switch ( V_1062 . V_1128 -> V_1071 ) {
case V_1137 :
V_1124 . V_1142 . V_1148 = V_1149 ;
V_1126 . V_1063 ^= V_1062 . V_1128 -> V_1150 ^ V_1062 . V_1128 -> V_1151 ;
break;
case 6 :
V_1124 . V_1142 . V_1148 = V_1152 ;
V_1126 . V_1063 ^= V_1062 . V_1129 -> V_1150 . V_1153 [ 0 ] ^
V_1062 . V_1129 -> V_1150 . V_1153 [ 1 ] ^
V_1062 . V_1129 -> V_1150 . V_1153 [ 2 ] ^
V_1062 . V_1129 -> V_1150 . V_1153 [ 3 ] ^
V_1062 . V_1129 -> V_1151 . V_1153 [ 0 ] ^
V_1062 . V_1129 -> V_1151 . V_1153 [ 1 ] ^
V_1062 . V_1129 -> V_1151 . V_1153 [ 2 ] ^
V_1062 . V_1129 -> V_1151 . V_1153 [ 3 ] ;
break;
default:
break;
}
if ( V_1062 . V_1127 != F_555 ( V_100 ) )
V_1124 . V_1142 . V_1148 |= V_1154 ;
F_587 ( & V_174 -> V_2 -> V_14 ,
V_1124 , V_1126 , V_64 -> V_96 ) ;
}
static T_2 F_588 ( struct V_76 * V_89 , struct V_216 * V_100 ,
void * V_1155 , T_15 V_1156 )
{
struct V_700 * V_1157 = V_1155 ;
#ifdef F_184
struct V_1 * V_2 ;
struct V_1026 * V_1158 ;
int V_1159 ;
#endif
if ( V_1157 )
return V_100 -> V_1160 + V_1157 -> V_708 ;
#ifdef F_184
switch ( F_589 ( V_100 ) ) {
case F_164 ( V_1161 ) :
case F_164 ( V_1162 ) :
V_2 = F_87 ( V_89 ) ;
if ( V_2 -> V_148 & V_564 )
break;
default:
return V_1156 ( V_89 , V_100 ) ;
}
V_1158 = & V_2 -> V_462 [ V_1163 ] ;
V_1159 = F_590 ( V_100 ) ? F_591 ( V_100 ) :
F_222 () ;
while ( V_1159 >= V_1158 -> V_496 )
V_1159 -= V_1158 -> V_496 ;
return V_1159 + V_1158 -> V_1088 ;
#else
return V_1156 ( V_89 , V_100 ) ;
#endif
}
static int F_212 ( struct V_1 * V_2 ,
struct V_308 * V_309 )
{
struct V_63 * V_64 = V_2 -> V_94 [ F_222 () ] ;
struct V_66 * V_67 ;
union V_78 * V_79 ;
T_1 V_73 , V_1101 ;
T_8 V_72 ;
T_2 V_49 ;
V_73 = V_309 -> V_310 - V_309 -> V_103 ;
if ( F_23 ( ! F_114 ( V_64 ) ) )
return V_324 ;
V_72 = F_577 ( V_64 -> V_89 , V_309 -> V_103 , V_73 , V_186 ) ;
if ( F_148 ( V_64 -> V_89 , V_72 ) )
return V_324 ;
V_67 = & V_64 -> V_68 [ V_64 -> V_70 ] ;
V_67 -> V_184 = V_73 ;
V_67 -> V_185 = 1 ;
V_67 -> V_276 = 0 ;
V_49 = V_64 -> V_70 ;
V_79 = F_65 ( V_64 , V_49 ) ;
F_101 ( V_67 , V_73 , V_73 ) ;
F_578 ( V_67 , V_72 , V_72 ) ;
V_67 -> V_103 = V_309 -> V_103 ;
V_79 -> V_260 . V_1117 = F_152 ( V_72 ) ;
V_1101 = V_1102 |
V_1103 |
V_1104 ;
V_1101 |= V_73 | V_1120 ;
V_79 -> V_260 . V_1119 = F_96 ( V_1101 ) ;
V_79 -> V_260 . V_1110 =
F_96 ( V_73 << V_1111 ) ;
F_592 () ;
V_49 ++ ;
if ( V_49 == V_64 -> V_98 )
V_49 = 0 ;
V_67 -> V_74 = V_79 ;
V_64 -> V_70 = V_49 ;
return V_331 ;
}
T_16 F_593 ( struct V_216 * V_100 ,
struct V_1 * V_2 ,
struct V_63 * V_92 )
{
struct V_66 * V_1054 ;
int V_1164 ;
T_1 V_1078 = 0 ;
unsigned short V_1158 ;
T_2 V_98 = F_594 ( F_156 ( V_100 ) ) ;
T_11 V_276 = V_100 -> V_276 ;
T_4 V_263 = 0 ;
for ( V_1158 = 0 ; V_1158 < F_157 ( V_100 ) -> V_306 ; V_1158 ++ )
V_98 += F_594 ( F_157 ( V_100 ) -> V_290 [ V_1158 ] . V_304 ) ;
if ( F_575 ( V_92 , V_98 + 3 ) ) {
V_92 -> V_161 . V_872 ++ ;
return V_1165 ;
}
V_1054 = & V_92 -> V_68 [ V_92 -> V_70 ] ;
V_1054 -> V_100 = V_100 ;
V_1054 -> V_184 = V_100 -> V_73 ;
V_1054 -> V_185 = 1 ;
if ( F_595 ( V_100 ) ) {
V_1078 |= F_596 ( V_100 ) << V_1141 ;
V_1078 |= V_1091 ;
} else if ( V_276 == F_164 ( V_275 ) ) {
struct V_1166 * V_1167 , V_1168 ;
V_1167 = F_597 ( V_100 , V_560 , sizeof( V_1168 ) , & V_1168 ) ;
if ( ! V_1167 )
goto V_1169;
V_1078 |= F_598 ( V_1167 -> V_1170 ) <<
V_1141 ;
V_1078 |= V_1143 ;
}
V_276 = F_589 ( V_100 ) ;
if ( F_23 ( F_157 ( V_100 ) -> V_1078 & V_1171 ) &&
V_2 -> V_1172 &&
! F_599 ( V_1173 ,
& V_2 -> V_35 ) ) {
F_157 ( V_100 ) -> V_1078 |= V_1174 ;
V_1078 |= V_1107 ;
V_2 -> V_1175 = F_600 ( V_100 ) ;
V_2 -> V_1176 = V_189 ;
F_601 ( & V_2 -> V_1177 ) ;
}
F_602 ( V_100 ) ;
#ifdef F_335
if ( V_2 -> V_148 & V_457 )
V_1078 |= V_1092 ;
#endif
if ( ( V_2 -> V_148 & V_149 ) &&
( ( V_1078 & ( V_1091 | V_1143 ) ) ||
( V_100 -> V_1178 != V_1179 ) ) ) {
V_1078 &= ~ V_1180 ;
V_1078 |= ( V_100 -> V_1178 & 0x7 ) <<
V_1181 ;
if ( V_1078 & V_1143 ) {
struct V_1182 * V_1167 ;
if ( F_554 ( V_100 , 0 ) )
goto V_1169;
V_1167 = (struct V_1182 * ) V_100 -> V_103 ;
V_1167 -> V_1170 = F_164 ( V_1078 >>
V_1141 ) ;
} else {
V_1078 |= V_1091 ;
}
}
V_1054 -> V_1078 = V_1078 ;
V_1054 -> V_276 = V_276 ;
#ifdef F_184
if ( ( V_276 == F_164 ( V_1161 ) ) &&
( V_92 -> V_77 -> V_218 & ( V_1183 | V_1184 ) ) ) {
V_1164 = F_603 ( V_92 , V_1054 , & V_263 ) ;
if ( V_1164 < 0 )
goto V_1169;
goto V_1185;
}
#endif
V_1164 = F_552 ( V_92 , V_1054 , & V_263 ) ;
if ( V_1164 < 0 )
goto V_1169;
else if ( ! V_1164 )
F_565 ( V_92 , V_1054 ) ;
if ( F_14 ( V_419 , & V_92 -> V_35 ) )
F_583 ( V_92 , V_1054 ) ;
#ifdef F_184
V_1185:
#endif
F_576 ( V_92 , V_1054 , V_263 ) ;
return V_1186 ;
V_1169:
F_183 ( V_1054 -> V_100 ) ;
V_1054 -> V_100 = NULL ;
return V_1186 ;
}
static T_16 F_604 ( struct V_216 * V_100 ,
struct V_76 * V_77 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_63 * V_92 ;
if ( F_605 ( V_100 , 17 ) )
return V_1186 ;
V_92 = V_64 ? V_64 : V_2 -> V_92 [ V_100 -> V_1160 ] ;
return F_593 ( V_100 , V_2 , V_92 ) ;
}
static T_16 F_606 ( struct V_216 * V_100 ,
struct V_76 * V_77 )
{
return F_604 ( V_100 , V_77 , NULL ) ;
}
static int F_607 ( struct V_76 * V_77 , void * V_62 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1187 * V_626 = V_62 ;
if ( ! F_399 ( V_626 -> V_1188 ) )
return - V_1189 ;
memcpy ( V_77 -> V_713 , V_626 -> V_1188 , V_77 -> V_1190 ) ;
memcpy ( V_14 -> V_118 . V_626 , V_626 -> V_1188 , V_77 -> V_1190 ) ;
F_342 ( V_2 ) ;
return 0 ;
}
static int
F_608 ( struct V_76 * V_77 , int V_1191 , int V_1192 , T_2 V_626 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_4 ;
int V_367 ;
if ( V_1191 != V_14 -> V_46 . V_1193 . V_1191 )
return - V_631 ;
V_367 = V_14 -> V_46 . V_374 . V_1194 ( V_14 , V_626 , V_1192 , & V_4 ) ;
if ( ! V_367 )
V_367 = V_4 ;
return V_367 ;
}
static int F_609 ( struct V_76 * V_77 , int V_1191 , int V_1192 ,
T_2 V_626 , T_2 V_4 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_1191 != V_14 -> V_46 . V_1193 . V_1191 )
return - V_631 ;
return V_14 -> V_46 . V_374 . V_1195 ( V_14 , V_626 , V_1192 , V_4 ) ;
}
static int F_610 ( struct V_76 * V_77 , struct V_1196 * V_1197 , int V_1198 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
switch ( V_1198 ) {
case V_1199 :
return F_611 ( V_2 , V_1197 ) ;
case V_1200 :
return F_612 ( V_2 , V_1197 ) ;
default:
return F_613 ( & V_2 -> V_14 . V_46 . V_1193 , F_614 ( V_1197 ) , V_1198 ) ;
}
}
static int F_615 ( struct V_76 * V_89 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_399 ( V_14 -> V_118 . V_1201 ) ) {
F_486 () ;
V_17 = F_616 ( V_89 , V_14 -> V_118 . V_1201 , V_1202 ) ;
F_489 () ;
V_14 -> V_118 . V_374 . V_757 ( V_14 , F_308 ( 0 ) ) ;
}
return V_17 ;
}
static int F_617 ( struct V_76 * V_89 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_1203 * V_118 = & V_2 -> V_14 . V_118 ;
if ( F_399 ( V_118 -> V_1201 ) ) {
F_486 () ;
V_17 = F_618 ( V_89 , V_118 -> V_1201 , V_1202 ) ;
F_489 () ;
}
return V_17 ;
}
static void F_619 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
int V_49 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
for ( V_49 = 0 ; V_49 < V_2 -> V_210 ; V_49 ++ )
F_253 ( 0 , V_2 -> V_174 [ V_49 ] ) ;
}
static void F_620 ( struct V_1204 * V_133 ,
struct V_63 * V_64 )
{
V_71 V_188 , V_153 ;
unsigned int V_1205 ;
if ( V_64 ) {
do {
V_1205 = F_621 ( & V_64 -> V_187 ) ;
V_153 = V_64 -> V_133 . V_153 ;
V_188 = V_64 -> V_133 . V_188 ;
} while ( F_622 ( & V_64 -> V_187 , V_1205 ) );
V_133 -> V_879 += V_153 ;
V_133 -> V_878 += V_188 ;
}
}
static void F_623 ( struct V_76 * V_77 ,
struct V_1204 * V_133 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
int V_49 ;
F_209 () ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
struct V_63 * V_64 = F_21 ( V_2 -> V_84 [ V_49 ] ) ;
V_71 V_188 , V_153 ;
unsigned int V_1205 ;
if ( V_64 ) {
do {
V_1205 = F_621 ( & V_64 -> V_187 ) ;
V_153 = V_64 -> V_133 . V_153 ;
V_188 = V_64 -> V_133 . V_188 ;
} while ( F_622 ( & V_64 -> V_187 , V_1205 ) );
V_133 -> V_877 += V_153 ;
V_133 -> V_876 += V_188 ;
}
}
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ ) {
struct V_63 * V_64 = F_21 ( V_2 -> V_92 [ V_49 ] ) ;
F_620 ( V_133 , V_64 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ ) {
struct V_63 * V_64 = F_21 ( V_2 -> V_94 [ V_49 ] ) ;
F_620 ( V_133 , V_64 ) ;
}
F_215 () ;
V_133 -> V_986 = V_77 -> V_133 . V_986 ;
V_133 -> V_987 = V_77 -> V_133 . V_987 ;
V_133 -> V_989 = V_77 -> V_133 . V_989 ;
V_133 -> V_990 = V_77 -> V_133 . V_990 ;
V_133 -> V_991 = V_77 -> V_133 . V_991 ;
}
static void F_624 ( struct V_1 * V_2 , T_4 V_143 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_3 , V_1206 ;
int V_49 ;
if ( V_14 -> V_118 . type == V_119 )
return;
V_3 = F_40 ( V_14 , V_1207 ) ;
V_1206 = V_3 ;
for ( V_49 = 0 ; V_49 < V_684 ; V_49 ++ ) {
T_4 V_1208 = V_3 >> ( V_49 * V_1209 ) ;
if ( V_1208 > V_143 )
V_3 &= ~ ( 0x7 << V_1209 ) ;
}
if ( V_3 != V_1206 )
F_74 ( V_14 , V_1207 , V_3 ) ;
return;
}
static void F_625 ( struct V_1 * V_2 )
{
struct V_76 * V_89 = V_2 -> V_77 ;
struct V_1210 * V_145 = & V_2 -> V_145 ;
struct V_1211 * V_1212 = V_2 -> V_669 ;
T_4 V_1213 ;
for ( V_1213 = 0 ; V_1213 < V_1214 ; V_1213 ++ ) {
T_4 V_143 = 0 ;
if ( V_2 -> V_665 & V_666 )
V_143 = F_626 ( V_145 , 0 , V_1213 ) ;
else if ( V_1212 )
V_143 = V_1212 -> V_670 [ V_1213 ] ;
F_627 ( V_89 , V_1213 , V_143 ) ;
}
}
int F_628 ( struct V_76 * V_89 , T_4 V_143 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
bool V_1215 ;
if ( V_143 > V_2 -> V_145 . V_770 . V_771 )
return - V_631 ;
if ( V_14 -> V_118 . type == V_119 && V_143 && V_143 < V_684 )
return - V_631 ;
V_1215 = ( F_629 ( & V_2 -> V_710 , 32 ) > 1 ) ;
if ( V_143 && V_1215 && V_2 -> V_711 > V_1216 )
return - V_841 ;
if ( F_63 ( V_89 ) )
F_475 ( V_89 ) ;
else
F_424 ( V_2 ) ;
F_493 ( V_2 ) ;
#ifdef F_405
if ( V_143 ) {
F_630 ( V_89 , V_143 ) ;
F_625 ( V_2 ) ;
V_2 -> V_148 |= V_149 ;
if ( V_2 -> V_14 . V_118 . type == V_119 ) {
V_2 -> V_1217 = V_2 -> V_14 . V_134 . V_818 ;
V_2 -> V_14 . V_134 . V_818 = V_1218 ;
}
} else {
F_631 ( V_89 ) ;
if ( V_2 -> V_14 . V_118 . type == V_119 )
V_2 -> V_14 . V_134 . V_818 = V_2 -> V_1217 ;
V_2 -> V_148 &= ~ V_149 ;
V_2 -> V_786 . V_146 = false ;
V_2 -> V_145 . V_146 = false ;
}
F_624 ( V_2 , V_143 ) ;
#endif
F_487 ( V_2 ) ;
if ( F_63 ( V_89 ) )
return F_470 ( V_89 ) ;
return 0 ;
}
static int F_632 ( struct V_1 * V_2 ,
struct V_1219 * V_1220 )
{
T_1 V_1221 = V_1220 -> V_1222 . V_1223 ;
T_1 V_1224 = F_633 ( V_1220 -> V_1222 . V_1223 ) ;
T_1 V_1225 = V_1220 -> V_1222 . V_1223 & 0xfffff ;
int V_17 = 0 , V_49 , V_60 ;
struct V_1226 * V_1227 = NULL ;
if ( V_1225 > V_1228 )
return - V_631 ;
if ( ( V_1224 != 0x800 ) && ( V_1224 >= V_812 ) )
return - V_631 ;
if ( V_1224 != 0x800 ) {
V_1227 = V_2 -> V_809 [ V_1224 ] ;
if ( ! V_1227 )
return - V_631 ;
if ( ! F_14 ( V_1225 - 1 , V_1227 -> V_1229 ) )
return - V_631 ;
F_37 ( V_1225 - 1 , V_1227 -> V_1229 ) ;
}
for ( V_49 = 1 ; V_49 < V_812 ; V_49 ++ ) {
V_1227 = V_2 -> V_809 [ V_49 ] ;
if ( V_1227 && V_1227 -> V_1230 == V_1221 ) {
for ( V_60 = 0 ; V_60 < V_1228 ; V_60 ++ ) {
if ( ! F_14 ( V_60 , V_1227 -> V_1229 ) )
continue;
F_382 ( & V_2 -> V_694 ) ;
V_17 = F_634 ( V_2 ,
NULL ,
V_60 + 1 ) ;
F_387 ( & V_2 -> V_694 ) ;
F_37 ( V_60 , V_1227 -> V_1229 ) ;
}
F_266 ( V_1227 -> V_1124 ) ;
F_266 ( V_1227 -> V_128 ) ;
F_266 ( V_1227 ) ;
V_2 -> V_809 [ V_49 ] = NULL ;
return V_17 ;
}
}
F_382 ( & V_2 -> V_694 ) ;
V_17 = F_634 ( V_2 , NULL , V_1225 ) ;
F_387 ( & V_2 -> V_694 ) ;
return V_17 ;
}
static int F_635 ( struct V_1 * V_2 ,
T_11 V_276 ,
struct V_1219 * V_1220 )
{
T_1 V_1224 = F_633 ( V_1220 -> V_1231 . V_1223 ) ;
if ( V_1224 >= V_812 )
return - V_631 ;
if ( V_1220 -> V_1231 . V_1232 > 0 )
return - V_631 ;
F_91 ( V_1224 - 1 , & V_2 -> V_1233 ) ;
return 0 ;
}
static int F_636 ( struct V_1 * V_2 ,
struct V_1219 * V_1220 )
{
T_1 V_1224 = F_633 ( V_1220 -> V_1231 . V_1223 ) ;
if ( V_1224 >= V_812 )
return - V_631 ;
F_37 ( V_1224 - 1 , & V_2 -> V_1233 ) ;
return 0 ;
}
static int F_637 ( struct V_76 * V_106 , void * V_1234 )
{
if ( F_401 ( V_106 ) ) {
struct V_714 * V_715 = F_87 ( V_106 ) ;
struct V_700 * V_701 = V_715 -> V_716 ;
struct V_1235 * V_103 = V_1234 ;
struct V_1 * V_2 = V_103 -> V_2 ;
int V_1236 = V_103 -> V_1236 ;
if ( V_701 && V_701 -> V_77 -> V_1236 == V_1236 ) {
V_103 -> V_114 = V_2 -> V_84 [ V_701 -> V_703 ] -> V_158 ;
V_103 -> V_698 = V_103 -> V_114 ;
return 1 ;
}
}
return 0 ;
}
static int F_638 ( struct V_1 * V_2 , int V_1236 ,
T_4 * V_114 , V_71 * V_698 )
{
unsigned int V_339 = V_2 -> V_339 , V_1031 ;
struct V_1235 V_103 ;
struct V_76 * V_106 ;
for ( V_1031 = 0 ; V_1031 < V_339 ; ++ V_1031 ) {
V_106 = F_479 ( V_2 -> V_556 [ V_1031 ] . V_1034 ) ;
if ( V_106 -> V_1236 == V_1236 ) {
if ( V_2 -> V_711 > 1 )
* V_114 = V_1031 * 2 ;
else
* V_114 = V_1031 * V_2 -> V_702 ;
* V_698 = V_1031 + 1 ;
* V_698 <<= V_1237 ;
return 0 ;
}
}
V_103 . V_2 = V_2 ;
V_103 . V_1236 = V_1236 ;
V_103 . V_698 = 0 ;
V_103 . V_114 = 0 ;
if ( F_403 ( V_2 -> V_77 ,
F_637 , & V_103 ) ) {
* V_698 = V_103 . V_698 ;
* V_114 = V_103 . V_114 ;
return 0 ;
}
return - V_631 ;
}
static int F_639 ( struct V_1 * V_2 ,
struct V_1238 * V_1239 , V_71 * V_698 , T_4 * V_114 )
{
const struct V_1240 * V_81 ;
F_640 ( V_1241 ) ;
int V_17 ;
if ( F_641 ( V_1239 ) )
return - V_631 ;
F_642 ( V_1239 , & V_1241 ) ;
F_643 (a, &actions, list) {
if ( F_644 ( V_81 ) ) {
* V_698 = V_699 ;
* V_114 = V_699 ;
return 0 ;
}
if ( F_645 ( V_81 ) ) {
int V_1236 = F_646 ( V_81 ) ;
V_17 = F_638 ( V_2 , V_1236 , V_114 ,
V_698 ) ;
if ( V_17 == 0 )
return V_17 ;
}
}
return - V_631 ;
}
static int F_639 ( struct V_1 * V_2 ,
struct V_1238 * V_1239 , V_71 * V_698 , T_4 * V_114 )
{
return - V_631 ;
}
static int F_647 ( struct V_692 * V_1124 ,
union V_1242 * V_128 ,
struct V_1219 * V_1220 ,
struct V_1243 * V_1244 ,
struct V_1245 * V_1246 )
{
int V_49 , V_60 , V_1247 ;
T_17 V_1248 , V_1249 ;
bool V_1250 = false , V_1251 = false ;
for ( V_49 = 0 ; V_49 < V_1220 -> V_1222 . V_1252 -> V_1253 ; V_49 ++ ) {
V_1247 = V_1220 -> V_1222 . V_1252 -> V_1254 [ V_49 ] . V_1247 ;
V_1248 = V_1220 -> V_1222 . V_1252 -> V_1254 [ V_49 ] . V_1248 ;
V_1249 = V_1220 -> V_1222 . V_1252 -> V_1254 [ V_49 ] . V_128 ;
for ( V_60 = 0 ; V_1244 [ V_60 ] . V_1248 ; V_60 ++ ) {
if ( V_1244 [ V_60 ] . V_1247 == V_1247 ) {
V_1244 [ V_60 ] . V_1248 ( V_1124 , V_128 , V_1248 , V_1249 ) ;
V_1124 -> V_693 . V_1142 . V_1148 |=
V_1244 [ V_60 ] . type ;
V_1250 = true ;
break;
}
}
if ( V_1246 ) {
if ( V_1246 -> V_1247 == V_1220 -> V_1222 . V_1252 -> V_1254 [ V_49 ] . V_1247 &&
V_1246 -> V_1248 == V_1220 -> V_1222 . V_1252 -> V_1254 [ V_49 ] . V_1248 &&
V_1246 -> V_128 == V_1220 -> V_1222 . V_1252 -> V_1254 [ V_49 ] . V_128 )
V_1251 = true ;
else
continue;
}
}
if ( V_1246 && ! V_1251 )
return - V_631 ;
if ( ! V_1250 )
return 0 ;
V_128 -> V_1142 . V_1148 = V_1255 |
V_1256 ;
if ( V_1124 -> V_693 . V_1142 . V_1148 == V_1257 )
V_128 -> V_1142 . V_1148 &= V_1255 ;
return 0 ;
}
static int F_648 ( struct V_1 * V_2 ,
T_11 V_276 ,
struct V_1219 * V_1220 )
{
T_1 V_1225 = V_1220 -> V_1222 . V_1223 & 0xfffff ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1243 * V_1244 ;
struct V_692 * V_1124 = NULL ;
union V_1242 * V_128 = NULL ;
struct V_1226 * V_1227 = NULL ;
int V_49 , V_17 = - V_631 ;
T_4 V_114 ;
T_1 V_1224 , V_1258 ;
V_1224 = F_633 ( V_1220 -> V_1222 . V_1223 ) ;
V_1258 = F_633 ( V_1220 -> V_1222 . V_1259 ) ;
if ( V_276 != F_164 ( V_1098 ) )
return V_17 ;
if ( V_1225 >= ( ( 1024 << V_2 -> V_687 ) - 2 ) ) {
F_107 ( V_164 , L_131 ) ;
return V_17 ;
}
if ( V_1224 == 0x800 ) {
V_1244 = ( V_2 -> V_809 [ 0 ] ) -> V_810 ;
} else {
if ( V_1224 >= V_812 )
return V_17 ;
if ( ! V_2 -> V_809 [ V_1224 ] )
return V_17 ;
V_1244 = ( V_2 -> V_809 [ V_1224 ] ) -> V_810 ;
}
if ( ! V_1244 )
return V_17 ;
if ( V_1258 ) {
struct V_1245 * V_1246 = V_1260 ;
if ( V_1258 >= V_812 )
return V_17 ;
if ( ! F_14 ( V_1258 - 1 , & V_2 -> V_1233 ) )
return V_17 ;
if ( V_2 -> V_809 [ V_1258 ] &&
( V_2 -> V_809 [ V_1258 ] ) -> V_1230 ) {
F_107 ( V_164 , L_132 ,
V_1258 ) ;
return V_17 ;
}
for ( V_49 = 0 ; V_1246 [ V_49 ] . V_1227 ; V_49 ++ ) {
if ( V_1246 [ V_49 ] . V_1261 != V_1220 -> V_1222 . V_1252 -> V_1262 ||
V_1246 [ V_49 ] . V_1263 != V_1220 -> V_1222 . V_1252 -> V_1264 ||
V_1246 [ V_49 ] . V_1249 != V_1220 -> V_1222 . V_1252 -> V_1265 )
return V_17 ;
V_1227 = F_288 ( sizeof( * V_1227 ) , V_486 ) ;
if ( ! V_1227 )
return - V_487 ;
V_1124 = F_288 ( sizeof( * V_1124 ) , V_486 ) ;
if ( ! V_1124 ) {
V_17 = - V_487 ;
goto V_1266;
}
V_128 = F_288 ( sizeof( * V_128 ) , V_486 ) ;
if ( ! V_128 ) {
V_17 = - V_487 ;
goto V_1267;
}
V_1227 -> V_1124 = V_1124 ;
V_1227 -> V_128 = V_128 ;
V_1227 -> V_1230 = V_1220 -> V_1222 . V_1223 ;
V_17 = F_647 ( V_1124 , V_128 , V_1220 ,
V_1244 , & V_1246 [ V_49 ] ) ;
if ( ! V_17 ) {
V_1227 -> V_810 = V_1246 [ V_49 ] . V_1227 ;
V_2 -> V_809 [ V_1258 ] = V_1227 ;
break;
}
}
return 0 ;
}
V_1124 = F_288 ( sizeof( * V_1124 ) , V_486 ) ;
if ( ! V_1124 )
return - V_487 ;
V_128 = F_288 ( sizeof( * V_128 ) , V_486 ) ;
if ( ! V_128 ) {
V_17 = - V_487 ;
goto V_1267;
}
if ( ( V_1224 != 0x800 ) && ( V_2 -> V_809 [ V_1224 ] ) ) {
if ( ( V_2 -> V_809 [ V_1224 ] ) -> V_1124 )
memcpy ( V_1124 , ( V_2 -> V_809 [ V_1224 ] ) -> V_1124 ,
sizeof( * V_1124 ) ) ;
if ( ( V_2 -> V_809 [ V_1224 ] ) -> V_128 )
memcpy ( V_128 , ( V_2 -> V_809 [ V_1224 ] ) -> V_128 ,
sizeof( * V_128 ) ) ;
for ( V_49 = 1 ; V_49 < V_812 ; V_49 ++ ) {
struct V_1226 * V_416 = V_2 -> V_809 [ V_49 ] ;
if ( V_416 && ( F_14 ( V_1225 - 1 , V_416 -> V_1229 ) ) ) {
F_107 ( V_164 , L_133 ,
V_1225 ) ;
V_17 = - V_631 ;
goto V_1268;
}
}
}
V_17 = F_647 ( V_1124 , V_128 , V_1220 , V_1244 , NULL ) ;
if ( V_17 )
goto V_1268;
V_17 = F_639 ( V_2 , V_1220 -> V_1222 . V_1239 , & V_1124 -> V_698 ,
& V_114 ) ;
if ( V_17 < 0 )
goto V_1268;
V_1124 -> V_697 = V_1225 ;
F_382 ( & V_2 -> V_694 ) ;
if ( F_383 ( & V_2 -> V_695 ) ) {
memcpy ( & V_2 -> V_696 , V_128 , sizeof( * V_128 ) ) ;
V_17 = F_384 ( V_14 , V_128 ) ;
if ( V_17 )
goto V_1269;
} else if ( memcmp ( & V_2 -> V_696 , V_128 , sizeof( * V_128 ) ) ) {
V_17 = - V_631 ;
goto V_1269;
}
F_649 ( & V_1124 -> V_693 , V_128 ) ;
V_17 = F_386 ( V_14 , & V_1124 -> V_693 ,
V_1124 -> V_697 , V_114 ) ;
if ( ! V_17 )
F_634 ( V_2 , V_1124 , V_1124 -> V_697 ) ;
F_387 ( & V_2 -> V_694 ) ;
if ( ( V_1224 != 0x800 ) && ( V_2 -> V_809 [ V_1224 ] ) )
F_91 ( V_1225 - 1 , ( V_2 -> V_809 [ V_1224 ] ) -> V_1229 ) ;
F_266 ( V_128 ) ;
return V_17 ;
V_1269:
F_387 ( & V_2 -> V_694 ) ;
V_1268:
F_266 ( V_128 ) ;
V_1267:
F_266 ( V_1124 ) ;
V_1266:
F_266 ( V_1227 ) ;
return V_17 ;
}
static int F_650 ( struct V_76 * V_89 , T_1 V_1223 , T_11 V_596 ,
struct V_1270 * V_143 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
if ( F_651 ( V_1223 ) == F_651 ( V_1271 ) &&
V_143 -> type == V_1272 ) {
switch ( V_143 -> V_1273 -> V_1274 ) {
case V_1275 :
case V_1276 :
return F_648 ( V_2 ,
V_596 , V_143 -> V_1273 ) ;
case V_1277 :
return F_632 ( V_2 , V_143 -> V_1273 ) ;
case V_1278 :
case V_1279 :
return F_635 ( V_2 , V_596 ,
V_143 -> V_1273 ) ;
case V_1280 :
return F_636 ( V_2 ,
V_143 -> V_1273 ) ;
default:
return - V_631 ;
}
}
if ( V_143 -> type != V_1281 )
return - V_631 ;
V_143 -> V_1282 -> V_14 = V_1283 ;
return F_628 ( V_89 , V_143 -> V_1282 -> V_681 ) ;
}
void F_652 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
F_486 () ;
F_628 ( V_77 , F_279 ( V_77 ) ) ;
F_489 () ;
}
void F_653 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
if ( F_63 ( V_77 ) )
F_416 ( V_2 ) ;
else
F_424 ( V_2 ) ;
}
static T_12 F_654 ( struct V_76 * V_77 ,
T_12 V_218 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
if ( ! ( V_218 & V_235 ) )
V_218 &= ~ V_1284 ;
if ( ! ( V_2 -> V_368 & V_801 ) )
V_218 &= ~ V_1284 ;
return V_218 ;
}
static int F_655 ( struct V_76 * V_77 ,
T_12 V_218 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
T_12 V_1285 = V_77 -> V_218 ^ V_218 ;
bool V_1286 = false ;
if ( ! ( V_218 & V_1284 ) ) {
if ( V_2 -> V_368 & V_573 )
V_1286 = true ;
V_2 -> V_368 &= ~ V_573 ;
} else if ( ( V_2 -> V_368 & V_801 ) &&
! ( V_2 -> V_368 & V_573 ) ) {
if ( V_2 -> V_428 == 1 ||
V_2 -> V_428 > V_1287 ) {
V_2 -> V_368 |= V_573 ;
V_1286 = true ;
} else if ( ( V_1285 ^ V_218 ) & V_1284 ) {
F_109 ( V_190 , L_134
L_135 ) ;
}
}
if ( ( V_218 & V_1288 ) || ( V_218 & V_1289 ) ) {
if ( ! ( V_2 -> V_148 & V_686 ) )
V_1286 = true ;
V_2 -> V_148 &= ~ V_409 ;
V_2 -> V_148 |= V_686 ;
} else {
if ( V_2 -> V_148 & V_686 )
V_1286 = true ;
V_2 -> V_148 &= ~ V_686 ;
if ( V_2 -> V_148 & V_457 ||
( F_279 ( V_77 ) > 1 ) ||
( V_2 -> V_462 [ V_477 ] . V_800 <= 1 ) ||
( ! V_2 -> V_447 ) )
;
else
V_2 -> V_148 |= V_409 ;
}
if ( V_1285 & V_297 )
V_1286 = true ;
V_77 -> V_218 = V_218 ;
if ( ( V_2 -> V_148 & V_657 ) ) {
if ( V_218 & V_235 ) {
V_2 -> V_368 |= V_1053 ;
} else {
T_1 V_1290 = V_660 ;
F_362 ( V_2 , V_1290 ) ;
}
}
if ( ( V_2 -> V_148 & V_658 ) ) {
if ( V_218 & V_235 ) {
V_2 -> V_368 |= V_1053 ;
} else {
T_1 V_1290 = V_662 ;
F_362 ( V_2 , V_1290 ) ;
}
}
if ( V_1286 )
F_653 ( V_77 ) ;
else if ( V_1285 & ( V_271 |
V_651 ) )
F_355 ( V_77 ) ;
return 0 ;
}
static void F_656 ( struct V_76 * V_89 ,
struct V_1291 * V_431 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_11 V_1144 = V_431 -> V_1144 ;
T_1 V_1292 = 0 ;
T_1 V_3 ;
if ( V_431 -> V_1293 != V_1294 )
return;
switch ( V_431 -> type ) {
case V_1295 :
if ( ! ( V_2 -> V_148 & V_657 ) )
return;
if ( V_2 -> V_661 == V_1144 )
return;
if ( V_2 -> V_661 ) {
F_657 ( V_89 ,
L_136 ,
F_598 ( V_2 -> V_661 ) ,
F_598 ( V_1144 ) ) ;
return;
}
V_2 -> V_661 = V_1144 ;
break;
case V_1296 :
if ( ! ( V_2 -> V_148 & V_658 ) )
return;
if ( V_2 -> V_663 == V_1144 )
return;
if ( V_2 -> V_663 ) {
F_657 ( V_89 ,
L_137 ,
F_598 ( V_2 -> V_663 ) ,
F_598 ( V_1144 ) ) ;
return;
}
V_1292 = V_1297 ;
V_2 -> V_663 = V_1144 ;
break;
default:
return;
}
V_3 = F_40 ( V_14 , V_659 ) | F_598 ( V_1144 ) << V_1292 ;
F_74 ( V_14 , V_659 , V_3 ) ;
}
static void F_658 ( struct V_76 * V_89 ,
struct V_1291 * V_431 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
T_1 V_1290 ;
if ( V_431 -> type != V_1295 &&
V_431 -> type != V_1296 )
return;
if ( V_431 -> V_1293 != V_1294 )
return;
switch ( V_431 -> type ) {
case V_1295 :
if ( ! ( V_2 -> V_148 & V_657 ) )
return;
if ( V_2 -> V_661 != V_431 -> V_1144 ) {
F_657 ( V_89 , L_138 ,
F_598 ( V_431 -> V_1144 ) ) ;
return;
}
V_1290 = V_660 ;
break;
case V_1296 :
if ( ! ( V_2 -> V_148 & V_658 ) )
return;
if ( V_2 -> V_663 != V_431 -> V_1144 ) {
F_657 ( V_89 , L_139 ,
F_598 ( V_431 -> V_1144 ) ) ;
return;
}
V_1290 = V_662 ;
break;
default:
return;
}
F_362 ( V_2 , V_1290 ) ;
V_2 -> V_368 |= V_1053 ;
}
static int F_659 ( struct V_1298 * V_1299 , struct V_1300 * V_1301 [] ,
struct V_76 * V_89 ,
const unsigned char * V_626 , T_2 V_273 ,
T_2 V_148 )
{
if ( F_660 ( V_626 ) || F_661 ( V_626 ) ) {
struct V_1 * V_2 = F_87 ( V_89 ) ;
T_2 V_530 = F_308 ( 0 ) ;
if ( F_349 ( V_89 ) >= F_341 ( V_2 , V_530 ) )
return - V_487 ;
}
return F_662 ( V_1299 , V_1301 , V_89 , V_626 , V_273 , V_148 ) ;
}
static int F_663 ( struct V_1 * V_2 ,
T_18 V_1302 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
unsigned int V_62 , V_1303 ;
T_1 V_539 ;
switch ( V_1302 ) {
case V_1304 :
F_74 ( & V_2 -> V_14 , V_547 , 0 ) ;
V_539 = F_40 ( V_14 , V_1305 ) ;
V_539 |= V_544 ;
F_74 ( V_14 , V_1305 , V_539 ) ;
V_1303 = V_2 -> V_339 + V_2 -> V_711 ;
for ( V_62 = 0 ; V_62 < V_1303 ; V_62 ++ ) {
if ( V_14 -> V_118 . V_374 . V_1306 )
V_14 -> V_118 . V_374 . V_1306 ( V_14 ,
true ,
V_62 ) ;
}
break;
case V_546 :
F_74 ( & V_2 -> V_14 , V_547 ,
V_548 ) ;
V_539 = F_40 ( V_14 , V_1305 ) ;
if ( ! V_2 -> V_339 )
V_539 &= ~ V_544 ;
F_74 ( V_14 , V_1305 , V_539 ) ;
V_1303 = V_2 -> V_339 + V_2 -> V_711 ;
for ( V_62 = 0 ; V_62 < V_1303 ; V_62 ++ ) {
if ( V_14 -> V_118 . V_374 . V_1306 )
V_14 -> V_118 . V_374 . V_1306 ( V_14 ,
false ,
V_62 ) ;
}
break;
default:
return - V_631 ;
}
V_2 -> V_545 = V_1302 ;
F_109 ( V_164 , L_140 ,
V_1302 == V_1304 ? L_141 : L_142 ) ;
return 0 ;
}
static int F_664 ( struct V_76 * V_89 ,
struct V_1307 * V_1308 , T_2 V_148 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_1300 * V_1309 , * V_1310 ;
int V_1311 ;
if ( ! ( V_2 -> V_148 & V_457 ) )
return - V_1312 ;
V_1310 = F_665 ( V_1308 , sizeof( struct V_1313 ) , V_1314 ) ;
if ( ! V_1310 )
return - V_631 ;
F_666 (attr, br_spec, rem) {
int V_182 ;
T_18 V_1302 ;
if ( F_667 ( V_1309 ) != V_1315 )
continue;
if ( F_668 ( V_1309 ) < sizeof( V_1302 ) )
return - V_631 ;
V_1302 = F_669 ( V_1309 ) ;
V_182 = F_663 ( V_2 , V_1302 ) ;
if ( V_182 )
return V_182 ;
break;
}
return 0 ;
}
static int F_670 ( struct V_216 * V_100 , T_1 V_1316 , T_1 V_1317 ,
struct V_76 * V_89 ,
T_1 V_1318 , int V_1319 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
if ( ! ( V_2 -> V_148 & V_457 ) )
return 0 ;
return F_671 ( V_100 , V_1316 , V_1317 , V_89 ,
V_2 -> V_545 , 0 , 0 , V_1319 ,
V_1318 , NULL ) ;
}
static void * F_672 ( struct V_76 * V_9 , struct V_76 * V_704 )
{
struct V_700 * V_1157 = NULL ;
struct V_1 * V_2 = F_87 ( V_9 ) ;
int V_1320 = V_2 -> V_339 + V_2 -> V_711 ;
unsigned int V_800 ;
int V_530 , V_17 ;
if ( V_1320 >= V_1321 )
return F_216 ( - V_631 ) ;
#ifdef F_673
if ( V_704 -> V_104 != V_704 -> V_91 ) {
F_657 ( V_9 , L_143 ,
V_704 -> V_59 ) ;
return F_216 ( - V_631 ) ;
}
#endif
if ( V_704 -> V_91 > V_844 ||
V_704 -> V_91 == V_1322 ) {
F_657 ( V_9 ,
L_144 ,
V_9 -> V_59 ) ;
return F_216 ( - V_631 ) ;
}
if ( ( ( V_2 -> V_148 & V_149 ) &&
V_2 -> V_711 > V_1216 - 1 ) ||
( V_2 -> V_711 > V_1323 ) )
return F_216 ( - V_841 ) ;
V_1157 = F_288 ( sizeof( * V_1157 ) , V_486 ) ;
if ( ! V_1157 )
return F_216 ( - V_487 ) ;
V_530 = F_629 ( & V_2 -> V_710 , 32 ) ;
V_2 -> V_711 ++ ;
F_91 ( V_530 , & V_2 -> V_710 ) ;
V_800 = F_674 ( & V_2 -> V_710 , 32 ) ;
V_2 -> V_148 |= V_609 | V_457 ;
V_2 -> V_462 [ V_463 ] . V_800 = V_800 + 1 ;
V_2 -> V_462 [ V_477 ] . V_800 = V_704 -> V_91 ;
V_17 = F_628 ( V_9 , F_279 ( V_9 ) ) ;
if ( V_17 )
goto V_1324;
V_1157 -> V_530 = V_530 ;
V_1157 -> V_157 = V_2 ;
if ( F_63 ( V_9 ) ) {
V_17 = F_395 ( V_704 , V_1157 ) ;
if ( V_17 )
goto V_1324;
F_675 ( V_704 ) ;
}
return V_1157 ;
V_1324:
F_657 ( V_9 ,
L_145 , V_704 -> V_59 ) ;
F_37 ( V_530 , & V_2 -> V_710 ) ;
V_2 -> V_711 -- ;
F_266 ( V_1157 ) ;
return F_216 ( V_17 ) ;
}
static void F_676 ( struct V_76 * V_9 , void * V_1325 )
{
struct V_700 * V_1157 = V_1325 ;
struct V_1 * V_2 = V_1157 -> V_157 ;
unsigned int V_800 ;
F_37 ( V_1157 -> V_530 , & V_2 -> V_710 ) ;
V_2 -> V_711 -- ;
V_800 = F_674 ( & V_2 -> V_710 , 32 ) ;
V_2 -> V_462 [ V_463 ] . V_800 = V_800 + 1 ;
F_393 ( V_1157 -> V_77 , V_1157 ) ;
F_628 ( V_9 , F_279 ( V_9 ) ) ;
F_396 ( V_9 , L_88 ,
V_1157 -> V_530 , V_2 -> V_711 ,
V_1157 -> V_703 ,
V_1157 -> V_703 + V_2 -> V_702 ,
V_2 -> V_710 ) ;
F_266 ( V_1157 ) ;
}
static T_12
F_677 ( struct V_216 * V_100 , struct V_76 * V_89 ,
T_12 V_218 )
{
unsigned int V_1326 , V_1327 ;
V_1327 = F_555 ( V_100 ) - V_100 -> V_103 ;
if ( F_23 ( V_1327 > V_1328 ) )
return V_218 & ~ ( V_1329 |
V_1330 |
V_1331 |
V_1332 |
V_1333 ) ;
V_1326 = F_556 ( V_100 ) - F_555 ( V_100 ) ;
if ( F_23 ( V_1326 > V_1334 ) )
return V_218 & ~ ( V_1329 |
V_1330 |
V_1332 |
V_1333 ) ;
if ( V_100 -> V_237 && ! ( V_218 & V_1335 ) )
V_218 &= ~ V_1332 ;
return V_218 ;
}
static int F_678 ( struct V_76 * V_89 , struct V_316 * V_1336 )
{
int V_49 , V_1337 = V_89 -> V_333 + V_560 + V_561 + V_1338 ;
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_316 * V_1339 ;
if ( V_2 -> V_148 & V_457 )
return - V_631 ;
if ( V_2 -> V_148 & V_149 )
return - V_631 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
struct V_63 * V_64 = V_2 -> V_84 [ V_49 ] ;
if ( F_170 ( V_64 ) )
return - V_631 ;
if ( V_1337 > F_72 ( V_64 ) )
return - V_631 ;
}
if ( V_1340 > V_1341 )
return - V_487 ;
V_1339 = F_679 ( & V_2 -> V_317 , V_1336 ) ;
if ( ! ! V_1336 != ! ! V_1339 ) {
int V_17 = F_628 ( V_89 , F_279 ( V_89 ) ) ;
if ( V_17 ) {
F_680 ( V_2 -> V_317 , V_1339 ) ;
return - V_631 ;
}
} else {
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ )
F_679 ( & V_2 -> V_84 [ V_49 ] -> V_317 , V_2 -> V_317 ) ;
}
if ( V_1339 )
F_681 ( V_1339 ) ;
return 0 ;
}
static int F_682 ( struct V_76 * V_89 , struct V_1342 * V_309 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
switch ( V_309 -> V_1274 ) {
case V_1343 :
return F_678 ( V_89 , V_309 -> V_1336 ) ;
case V_1344 :
V_309 -> V_1345 = ! ! ( V_2 -> V_317 ) ;
return 0 ;
default:
return - V_631 ;
}
}
static inline int F_683 ( struct V_1 * V_2 )
{
struct V_5 * V_433 , * V_9 = V_2 -> V_9 ;
int V_1346 = 0 ;
if ( F_8 ( & V_2 -> V_14 ) )
V_1346 = 4 ;
F_643 (entry, &adapter->pdev->bus->devices, bus_list) {
if ( V_433 -> V_1347 )
continue;
if ( ( V_433 -> V_792 != V_9 -> V_792 ) ||
( V_433 -> V_211 != V_9 -> V_211 ) )
return - 1 ;
V_1346 ++ ;
}
return V_1346 ;
}
bool F_684 ( struct V_1 * V_2 , T_2 V_21 ,
T_2 V_1348 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1349 = V_2 -> V_1350 & V_1351 ;
if ( V_14 -> V_118 . type == V_119 )
return false ;
if ( V_14 -> V_118 . type >= V_122 ) {
if ( ( V_1349 == V_1352 ) ||
( ( V_1349 == V_1353 ) &&
( V_14 -> V_10 . V_1354 == 0 ) ) )
return true ;
}
switch ( V_21 ) {
case V_1355 :
switch ( V_1348 ) {
case V_1356 :
case V_1357 :
case V_1358 :
case V_1359 :
if ( V_14 -> V_10 . V_1354 != 0 )
break;
case V_1360 :
case V_1361 :
case V_1362 :
case V_1363 :
case V_1364 :
case V_1365 :
case V_1366 :
return true ;
}
break;
case V_1367 :
switch ( V_1348 ) {
case V_1368 :
return true ;
}
break;
case V_1369 :
if ( V_1348 != V_1370 )
return true ;
break;
case V_1371 :
return true ;
default:
break;
}
return false ;
}
static int F_685 ( struct V_5 * V_9 , const struct V_1372 * V_1373 )
{
struct V_76 * V_77 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_14 ;
const struct V_787 * V_788 = V_1374 [ V_1373 -> V_1375 ] ;
int V_49 , V_17 , V_1376 , V_24 ;
unsigned int V_496 = V_1377 ;
T_4 V_1378 [ V_1379 ] ;
bool V_1380 = false ;
#ifdef F_184
T_2 V_1381 ;
#endif
T_1 V_1382 ;
if ( V_9 -> V_1347 ) {
F_686 ( 1 , V_1383 L_146 ,
F_687 ( V_9 ) , V_9 -> V_792 , V_9 -> V_211 ) ;
return - V_631 ;
}
V_17 = F_483 ( V_9 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_688 ( & V_9 -> V_89 , F_274 ( 64 ) ) ) {
V_1376 = 1 ;
} else {
V_17 = F_688 ( & V_9 -> V_89 , F_274 ( 32 ) ) ;
if ( V_17 ) {
F_458 ( & V_9 -> V_89 ,
L_147 ) ;
goto V_1384;
}
V_1376 = 0 ;
}
V_17 = F_689 ( V_9 , V_1385 ) ;
if ( V_17 ) {
F_458 ( & V_9 -> V_89 ,
L_148 , V_17 ) ;
goto V_1386;
}
F_690 ( V_9 ) ;
F_484 ( V_9 ) ;
F_482 ( V_9 ) ;
if ( V_788 -> V_118 == V_119 ) {
#ifdef F_405
V_496 = 4 * V_684 ;
#else
V_496 = V_1387 ;
#endif
}
V_77 = F_691 ( sizeof( struct V_1 ) , V_496 ) ;
if ( ! V_77 ) {
V_17 = - V_487 ;
goto V_1388;
}
F_692 ( V_77 , & V_9 -> V_89 ) ;
V_2 = F_87 ( V_77 ) ;
V_2 -> V_77 = V_77 ;
V_2 -> V_9 = V_9 ;
V_14 = & V_2 -> V_14 ;
V_14 -> V_40 = V_2 ;
V_2 -> V_1389 = F_693 ( V_1390 , V_1391 ) ;
V_14 -> V_41 = F_694 ( F_695 ( V_9 , 0 ) ,
F_696 ( V_9 , 0 ) ) ;
V_2 -> V_446 = V_14 -> V_41 ;
if ( ! V_14 -> V_41 ) {
V_17 = - V_832 ;
goto V_1392;
}
V_77 -> V_1393 = & V_1394 ;
F_697 ( V_77 ) ;
V_77 -> V_1395 = 5 * V_1049 ;
F_698 ( V_77 -> V_59 , F_687 ( V_9 ) , sizeof( V_77 -> V_59 ) ) ;
V_14 -> V_118 . V_374 = * V_788 -> V_1396 ;
V_14 -> V_118 . type = V_788 -> V_118 ;
V_14 -> V_1397 = V_788 -> V_1397 ;
if ( V_788 -> V_1398 )
V_14 -> V_416 . V_374 = * V_788 -> V_1398 ;
V_14 -> V_1399 . V_374 = * V_788 -> V_1400 ;
V_1382 = F_40 ( V_14 , F_699 ( V_14 ) ) ;
if ( F_22 ( V_14 -> V_41 ) ) {
V_17 = - V_832 ;
goto V_1392;
}
if ( ! ( V_1382 & F_224 ( 8 ) ) )
V_14 -> V_1399 . V_374 . V_260 = & V_1401 ;
V_14 -> V_46 . V_374 = * V_788 -> V_1402 ;
V_14 -> V_46 . V_1045 = V_1403 ;
V_14 -> V_46 . V_1193 . V_1191 = V_1404 ;
V_14 -> V_46 . V_1193 . V_1405 = 0 ;
V_14 -> V_46 . V_1193 . V_1406 = V_1407 | V_1408 ;
V_14 -> V_46 . V_1193 . V_89 = V_77 ;
V_14 -> V_46 . V_1193 . V_1409 = F_608 ;
V_14 -> V_46 . V_1193 . V_1410 = F_609 ;
V_17 = F_443 ( V_2 , V_788 ) ;
if ( V_17 )
goto V_1411;
if ( V_14 -> V_118 . V_374 . V_1412 )
V_14 -> V_118 . V_374 . V_1412 ( V_14 ) ;
switch ( V_2 -> V_14 . V_118 . type ) {
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
F_74 ( & V_2 -> V_14 , V_850 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_148 & V_382 ) {
T_1 V_743 = F_40 ( V_14 , V_744 ) ;
if ( V_743 & V_745 )
F_232 ( V_190 , L_70 ) ;
}
if ( V_1413 )
V_14 -> V_1413 = V_1413 ;
V_14 -> V_46 . V_1414 = true ;
V_17 = V_14 -> V_118 . V_374 . V_1415 ( V_14 ) ;
V_14 -> V_46 . V_1414 = false ;
F_440 ( V_2 ) ;
if ( V_17 == V_752 ) {
V_17 = 0 ;
} else if ( V_17 == V_753 ) {
F_18 ( L_149 ) ;
F_18 ( L_150 ) ;
goto V_1411;
} else if ( V_17 ) {
F_18 ( L_151 , V_17 ) ;
goto V_1411;
}
#ifdef F_335
if ( V_2 -> V_14 . V_118 . type == V_119 )
goto V_1416;
F_700 ( V_14 ) ;
V_14 -> V_1417 . V_374 = V_788 -> V_1418 ;
F_701 ( V_9 , V_824 ) ;
F_702 ( V_2 , V_823 ) ;
V_1416:
#endif
V_77 -> V_218 = V_1419 |
V_1332 |
V_1333 |
V_219 |
V_235 |
V_1329 ;
#define F_703 (NETIF_F_GSO_GRE | \
NETIF_F_GSO_GRE_CSUM | \
NETIF_F_GSO_IPXIP4 | \
NETIF_F_GSO_IPXIP6 | \
NETIF_F_GSO_UDP_TUNNEL | \
NETIF_F_GSO_UDP_TUNNEL_CSUM)
V_77 -> V_1420 = F_703 ;
V_77 -> V_218 |= V_1421 |
F_703 ;
if ( V_14 -> V_118 . type >= V_121 )
V_77 -> V_218 |= V_1330 ;
V_77 -> V_1422 |= V_77 -> V_218 |
V_651 |
V_271 |
V_1331 |
V_297 |
V_1423 ;
if ( V_14 -> V_118 . type >= V_121 )
V_77 -> V_1422 |= V_1288 |
V_1289 ;
if ( V_1376 )
V_77 -> V_218 |= V_1424 ;
V_77 -> V_1425 |= V_77 -> V_218 | V_1335 ;
V_77 -> V_1426 |= V_77 -> V_1425 ;
V_77 -> V_1427 |= V_1329 ;
V_77 -> V_218 |= V_651 |
V_271 |
V_1331 ;
V_77 -> V_1428 |= V_1429 ;
V_77 -> V_1428 |= V_1430 ;
V_77 -> V_1431 = V_1432 ;
V_77 -> V_1433 = V_1434 - ( V_560 + V_561 ) ;
#ifdef F_405
if ( V_2 -> V_148 & V_784 )
V_77 -> V_1435 = & V_1436 ;
#endif
#ifdef F_184
if ( V_2 -> V_148 & V_807 ) {
unsigned int V_1437 ;
if ( V_14 -> V_118 . V_374 . V_1438 ) {
V_14 -> V_118 . V_374 . V_1438 ( V_14 , & V_1381 ) ;
if ( V_1381 & V_1439 )
V_2 -> V_148 &= ~ V_807 ;
}
V_1437 = F_353 ( int , V_1440 , F_445 () ) ;
V_2 -> V_462 [ V_1163 ] . V_800 = V_1437 ;
V_77 -> V_218 |= V_1183 |
V_1184 ;
V_77 -> V_1425 |= V_1183 |
V_1184 |
V_664 ;
}
#endif
if ( V_2 -> V_368 & V_801 )
V_77 -> V_1422 |= V_1284 ;
if ( V_2 -> V_368 & V_573 )
V_77 -> V_218 |= V_1284 ;
if ( V_14 -> V_1399 . V_374 . V_1441 ( V_14 , NULL ) < 0 ) {
F_18 ( L_152 ) ;
V_17 = - V_832 ;
goto V_1411;
}
F_704 ( & V_2 -> V_9 -> V_89 ,
V_2 -> V_14 . V_118 . V_1442 ) ;
memcpy ( V_77 -> V_713 , V_14 -> V_118 . V_1442 , V_77 -> V_1190 ) ;
if ( ! F_399 ( V_77 -> V_713 ) ) {
F_18 ( L_153 ) ;
V_17 = - V_832 ;
goto V_1411;
}
F_345 ( V_14 -> V_118 . V_626 , V_14 -> V_118 . V_1442 ) ;
F_342 ( V_2 ) ;
F_705 ( & V_2 -> V_746 , & F_545 ,
( unsigned long ) V_2 ) ;
if ( F_22 ( V_14 -> V_41 ) ) {
V_17 = - V_832 ;
goto V_1411;
}
F_706 ( & V_2 -> V_39 , F_549 ) ;
F_91 ( V_42 , & V_2 -> V_35 ) ;
F_37 ( V_37 , & V_2 -> V_35 ) ;
V_17 = F_487 ( V_2 ) ;
if ( V_17 )
goto V_1411;
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ )
F_454 ( & V_2 -> V_94 [ V_49 ] -> V_187 ) ;
V_2 -> V_759 = 0 ;
V_14 -> V_1399 . V_374 . V_260 ( V_14 , 0x2c , & V_2 -> V_1350 ) ;
V_14 -> V_1443 = F_684 ( V_2 , V_9 -> V_211 ,
V_9 -> V_798 ) ;
if ( V_14 -> V_1443 )
V_2 -> V_759 = V_1444 ;
F_707 ( & V_2 -> V_9 -> V_89 , V_2 -> V_759 ) ;
V_14 -> V_1399 . V_374 . V_260 ( V_14 , 0x2e , & V_2 -> V_1445 ) ;
V_14 -> V_1399 . V_374 . V_260 ( V_14 , 0x2d , & V_2 -> V_1446 ) ;
if ( F_8 ( V_14 ) )
F_5 ( V_2 ) ;
else
V_14 -> V_118 . V_374 . V_1447 ( V_14 ) ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_24 = F_260 ( F_683 ( V_2 ) * 10 , 16 ) ;
break;
default:
V_24 = F_683 ( V_2 ) * 10 ;
break;
}
if ( V_24 > 0 )
F_9 ( V_2 , V_24 ) ;
V_17 = F_708 ( V_14 , V_1378 , sizeof( V_1378 ) ) ;
if ( V_17 )
F_698 ( V_1378 , L_7 , sizeof( V_1378 ) ) ;
if ( F_236 ( V_14 ) && V_14 -> V_46 . V_1045 != V_1448 )
F_12 ( L_154 ,
V_14 -> V_118 . type , V_14 -> V_46 . type , V_14 -> V_46 . V_1045 ,
V_1378 ) ;
else
F_12 ( L_155 ,
V_14 -> V_118 . type , V_14 -> V_46 . type , V_1378 ) ;
F_12 ( L_156 , V_77 -> V_713 ) ;
V_17 = V_14 -> V_118 . V_374 . V_1449 ( V_14 ) ;
if ( V_17 == V_755 ) {
F_11 ( L_91
L_157
L_158
L_159
L_95
L_96 ) ;
}
strcpy ( V_77 -> V_59 , L_160 ) ;
V_17 = F_709 ( V_77 ) ;
if ( V_17 )
goto V_1450;
F_710 ( V_9 , V_2 ) ;
if ( V_14 -> V_118 . V_374 . V_764 )
V_14 -> V_118 . V_374 . V_764 ( V_14 ) ;
F_434 ( V_77 ) ;
#ifdef F_257
if ( F_130 ( & V_9 -> V_89 ) == 0 ) {
V_2 -> V_148 |= V_196 ;
F_127 ( V_2 ) ;
}
#endif
if ( V_2 -> V_148 & V_457 ) {
F_109 ( V_190 , L_161 , V_2 -> V_339 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_339 ; V_49 ++ )
F_711 ( V_9 , ( V_49 | 0x10000000 ) ) ;
}
if ( V_14 -> V_118 . V_374 . V_1451 )
V_14 -> V_118 . V_374 . V_1451 ( V_14 , 0xFF , 0xFF , 0xFF , 0xFF ,
sizeof( V_1452 ) - 1 ,
V_1452 ) ;
F_615 ( V_77 ) ;
F_12 ( L_69 , V_1453 ) ;
#ifdef F_712
if ( F_713 ( V_2 ) )
F_107 ( V_190 , L_162 ) ;
#endif
F_714 ( V_2 ) ;
if ( F_715 ( V_14 ) && F_236 ( V_14 ) && V_14 -> V_118 . V_374 . V_724 )
V_14 -> V_118 . V_374 . V_724 ( V_14 ,
V_998 | V_1023 ,
true ) ;
return 0 ;
V_1450:
F_73 ( V_2 ) ;
F_493 ( V_2 ) ;
V_1411:
F_716 ( V_2 ) ;
V_2 -> V_368 &= ~ V_719 ;
F_717 ( V_2 -> V_446 ) ;
F_266 ( V_2 -> V_809 [ 0 ] ) ;
F_266 ( V_2 -> V_621 ) ;
F_266 ( V_2 -> V_484 ) ;
V_1392:
V_1380 = ! F_15 ( V_849 , & V_2 -> V_35 ) ;
F_718 ( V_77 ) ;
V_1388:
F_719 ( V_9 ) ;
V_1386:
V_1384:
if ( ! V_2 || V_1380 )
F_494 ( V_9 ) ;
return V_17 ;
}
static void F_720 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_479 ( V_9 ) ;
struct V_76 * V_77 ;
bool V_1380 ;
int V_49 ;
if ( ! V_2 )
return;
V_77 = V_2 -> V_77 ;
F_721 ( V_2 ) ;
F_91 ( V_36 , & V_2 -> V_35 ) ;
F_722 ( & V_2 -> V_39 ) ;
#ifdef F_257
if ( V_2 -> V_148 & V_196 ) {
V_2 -> V_148 &= ~ V_196 ;
F_131 ( & V_9 -> V_89 ) ;
F_74 ( & V_2 -> V_14 , V_207 ,
V_209 ) ;
}
#endif
#ifdef F_712
F_723 ( V_2 ) ;
#endif
F_617 ( V_77 ) ;
#ifdef F_335
F_716 ( V_2 ) ;
#endif
if ( V_77 -> V_1046 == V_1047 )
F_543 ( V_77 ) ;
F_493 ( V_2 ) ;
F_73 ( V_2 ) ;
#ifdef F_724
F_266 ( V_2 -> V_147 ) ;
F_266 ( V_2 -> V_669 ) ;
#endif
F_717 ( V_2 -> V_446 ) ;
F_719 ( V_9 ) ;
F_12 ( L_163 ) ;
for ( V_49 = 0 ; V_49 < V_812 ; V_49 ++ ) {
if ( V_2 -> V_809 [ V_49 ] ) {
F_266 ( V_2 -> V_809 [ V_49 ] -> V_1124 ) ;
F_266 ( V_2 -> V_809 [ V_49 ] -> V_128 ) ;
}
F_266 ( V_2 -> V_809 [ V_49 ] ) ;
}
F_266 ( V_2 -> V_621 ) ;
F_266 ( V_2 -> V_484 ) ;
V_1380 = ! F_15 ( V_849 , & V_2 -> V_35 ) ;
F_718 ( V_77 ) ;
F_725 ( V_9 ) ;
if ( V_1380 )
F_494 ( V_9 ) ;
}
static T_19 F_726 ( struct V_5 * V_9 ,
T_20 V_35 )
{
struct V_1 * V_2 = F_479 ( V_9 ) ;
struct V_76 * V_77 = V_2 -> V_77 ;
#ifdef F_335
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_1454 , * V_1034 ;
T_1 V_1455 , V_1456 , V_1457 , V_1458 ;
int V_1031 , V_1459 ;
T_2 V_1460 , V_1461 ;
if ( V_2 -> V_14 . V_118 . type == V_119 ||
V_2 -> V_339 == 0 )
goto V_1462;
V_1454 = V_9 -> V_10 -> V_12 ;
while ( V_1454 && ( F_727 ( V_1454 ) != V_1463 ) )
V_1454 = V_1454 -> V_10 -> V_12 ;
if ( ! V_1454 )
goto V_1462;
V_1459 = F_728 ( V_1454 , V_1464 ) ;
if ( ! V_1459 )
goto V_1462;
V_1455 = F_30 ( V_14 , V_1459 + V_1465 ) ;
V_1456 = F_30 ( V_14 , V_1459 + V_1465 + 4 ) ;
V_1457 = F_30 ( V_14 , V_1459 + V_1465 + 8 ) ;
V_1458 = F_30 ( V_14 , V_1459 + V_1465 + 12 ) ;
if ( F_22 ( V_14 -> V_41 ) )
goto V_1462;
V_1460 = V_1456 >> 16 ;
if ( ! ( V_1460 & 0x0080 ) )
goto V_1462;
V_1461 = V_1460 & 0x01 ;
if ( ( V_1461 & 1 ) == ( V_9 -> V_1466 & 1 ) ) {
unsigned int V_21 ;
V_1031 = ( V_1460 & 0x7F ) >> 1 ;
F_18 ( L_164 , V_1031 ) ;
F_18 ( L_165
L_166 ,
V_1455 , V_1456 , V_1457 , V_1458 ) ;
switch ( V_2 -> V_14 . V_118 . type ) {
case V_121 :
V_21 = V_1467 ;
break;
case V_122 :
V_21 = V_1468 ;
break;
case V_123 :
V_21 = V_1469 ;
break;
case V_124 :
V_21 = V_1470 ;
break;
case V_125 :
V_21 = V_1471 ;
break;
default:
V_21 = 0 ;
break;
}
V_1034 = F_729 ( V_1472 , V_21 , NULL ) ;
while ( V_1034 ) {
if ( V_1034 -> V_1466 == ( V_1460 & 0xFF ) )
break;
V_1034 = F_729 ( V_1472 ,
V_21 , V_1034 ) ;
}
if ( V_1034 ) {
F_539 ( V_1034 ) ;
F_730 ( V_1034 ) ;
}
F_731 ( V_9 ) ;
}
V_2 -> V_1473 ++ ;
return V_1474 ;
V_1462:
#endif
if ( ! F_14 ( V_42 , & V_2 -> V_35 ) )
return V_1475 ;
F_486 () ;
F_492 ( V_77 ) ;
if ( V_35 == V_1476 ) {
F_489 () ;
return V_1475 ;
}
if ( F_63 ( V_77 ) )
F_473 ( V_2 ) ;
if ( ! F_15 ( V_849 , & V_2 -> V_35 ) )
F_494 ( V_9 ) ;
F_489 () ;
return V_1477 ;
}
static T_19 F_732 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_479 ( V_9 ) ;
T_19 V_314 ;
int V_17 ;
if ( F_483 ( V_9 ) ) {
F_107 ( V_190 , L_167 ) ;
V_314 = V_1475 ;
} else {
F_36 () ;
F_37 ( V_849 , & V_2 -> V_35 ) ;
V_2 -> V_14 . V_41 = V_2 -> V_446 ;
F_484 ( V_9 ) ;
F_481 ( V_9 ) ;
F_482 ( V_9 ) ;
F_485 ( V_9 , false ) ;
F_424 ( V_2 ) ;
F_74 ( & V_2 -> V_14 , V_850 , ~ 0 ) ;
V_314 = V_1474 ;
}
V_17 = F_731 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_168
L_169 , V_17 ) ;
}
return V_314 ;
}
static void F_733 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_479 ( V_9 ) ;
struct V_76 * V_77 = V_2 -> V_77 ;
#ifdef F_335
if ( V_2 -> V_1473 ) {
F_109 ( V_164 , L_170 ) ;
V_2 -> V_1473 -- ;
return;
}
#endif
F_486 () ;
if ( F_63 ( V_77 ) )
F_470 ( V_77 ) ;
F_488 ( V_77 ) ;
F_489 () ;
}
static int T_21 F_734 ( void )
{
int V_635 ;
F_54 ( L_171 , V_1478 , V_1452 ) ;
F_54 ( L_69 , V_1479 ) ;
V_38 = F_735 ( V_1385 ) ;
if ( ! V_38 ) {
F_55 ( L_172 , V_1385 ) ;
return - V_487 ;
}
F_736 () ;
V_635 = F_737 ( & V_1480 ) ;
if ( V_635 ) {
F_738 ( V_38 ) ;
F_739 () ;
return V_635 ;
}
#ifdef F_257
F_740 ( & V_1481 ) ;
#endif
return 0 ;
}
static void T_22 F_741 ( void )
{
#ifdef F_257
F_742 ( & V_1481 ) ;
#endif
F_743 ( & V_1480 ) ;
F_739 () ;
if ( V_38 ) {
F_738 ( V_38 ) ;
V_38 = NULL ;
}
}
static int F_744 ( struct V_1482 * V_1483 , unsigned long V_212 ,
void * V_62 )
{
int V_1484 ;
V_1484 = F_745 ( & V_1480 . V_1485 , NULL , & V_212 ,
F_128 ) ;
return V_1484 ? V_1486 : V_1487 ;
}
