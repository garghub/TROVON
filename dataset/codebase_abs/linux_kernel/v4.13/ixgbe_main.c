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
if ( ! ( V_2 -> V_368 & V_369 ) )
return;
V_2 -> V_368 &= ~ V_369 ;
switch ( V_14 -> V_21 ) {
case V_370 :
if ( ! ( V_365 & V_371 ) &&
! ( V_365 & V_372 ) )
return;
if ( ! ( V_365 & V_372 ) && V_14 -> V_118 . V_373 . V_374 ) {
T_1 V_20 ;
bool V_375 = false ;
V_14 -> V_118 . V_373 . V_374 ( V_14 , & V_20 , & V_375 , false ) ;
if ( V_375 )
return;
}
if ( V_14 -> V_46 . V_373 . V_376 ( V_14 ) != V_377 )
return;
break;
case V_378 :
case V_379 :
V_367 = V_14 -> V_46 . V_373 . V_376 ( V_14 ) ;
if ( V_367 != V_377 )
return;
break;
default:
if ( V_2 -> V_14 . V_118 . type >= V_122 )
return;
if ( ! ( V_365 & F_231 ( V_14 ) ) )
return;
break;
}
F_232 ( V_164 , L_69 , V_380 ) ;
V_2 -> V_366 = 0 ;
}
static void F_233 ( struct V_1 * V_2 , T_1 V_365 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ( V_2 -> V_148 & V_381 ) &&
( V_365 & F_234 ( V_14 ) ) ) {
F_232 ( V_190 , L_70 ) ;
F_74 ( V_14 , V_382 , F_234 ( V_14 ) ) ;
}
}
static void F_235 ( struct V_1 * V_2 , T_1 V_365 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! ( V_2 -> V_368 & V_383 ) )
return;
switch ( V_2 -> V_14 . V_118 . type ) {
case V_121 :
if ( ( ( V_365 & F_231 ( V_14 ) ) ||
( V_365 & V_372 ) ) &&
( ! F_14 ( V_34 , & V_2 -> V_35 ) ) ) {
V_2 -> V_366 = V_365 ;
V_2 -> V_368 |= V_369 ;
F_13 ( V_2 ) ;
return;
}
return;
case V_125 :
if ( V_365 & V_384 ) {
V_2 -> V_366 = V_365 ;
V_2 -> V_368 |= V_369 ;
F_13 ( V_2 ) ;
F_74 ( & V_2 -> V_14 , V_385 ,
V_384 ) ;
F_74 ( & V_2 -> V_14 , V_382 ,
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
F_232 ( V_164 , L_69 , V_380 ) ;
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
switch ( V_14 -> V_118 . V_373 . V_388 ( V_14 ) ) {
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
F_74 ( V_14 , V_382 , V_391 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_368 |= V_393 ;
V_2 -> V_394 = 0 ;
F_13 ( V_2 ) ;
}
}
if ( V_2 -> V_14 . V_118 . type == V_121 &&
( V_365 & F_234 ( V_14 ) ) ) {
F_74 ( V_14 , V_382 , F_234 ( V_14 ) ) ;
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
if ( V_2 -> V_368 & V_383 )
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
if ( V_2 -> V_148 & V_381 )
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
F_74 ( V_14 , V_382 , V_365 ) ;
if ( V_365 & V_372 )
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
F_74 ( V_14 , V_382 ,
V_392 ) ;
}
if ( V_365 & V_415 ) {
F_109 ( V_416 , L_71 ) ;
F_91 ( V_163 , & V_2 -> V_35 ) ;
F_13 ( V_2 ) ;
F_74 ( V_14 , V_382 , V_415 ) ;
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
unsigned int V_429 = 0 , V_430 = 0 ;
int V_431 , V_17 ;
for ( V_431 = 0 ; V_431 < V_2 -> V_210 ; V_431 ++ ) {
struct V_173 * V_174 = V_2 -> V_174 [ V_431 ] ;
struct V_432 * V_433 = & V_2 -> V_434 [ V_431 ] ;
if ( V_174 -> V_179 . V_64 && V_174 -> V_337 . V_64 ) {
snprintf ( V_174 -> V_59 , sizeof( V_174 -> V_59 ) ,
L_72 , V_77 -> V_59 , V_429 ++ ) ;
V_430 ++ ;
} else if ( V_174 -> V_337 . V_64 ) {
snprintf ( V_174 -> V_59 , sizeof( V_174 -> V_59 ) ,
L_73 , V_77 -> V_59 , V_429 ++ ) ;
} else if ( V_174 -> V_179 . V_64 ) {
snprintf ( V_174 -> V_59 , sizeof( V_174 -> V_59 ) ,
L_74 , V_77 -> V_59 , V_430 ++ ) ;
} else {
continue;
}
V_17 = F_262 ( V_433 -> V_431 , & F_253 , 0 ,
V_174 -> V_59 , V_174 ) ;
if ( V_17 ) {
F_107 ( V_190 , L_75
L_76 , V_17 ) ;
goto V_435;
}
if ( V_2 -> V_148 & V_409 ) {
F_263 ( V_433 -> V_431 ,
& V_174 -> V_436 ) ;
}
}
V_17 = F_262 ( V_2 -> V_434 [ V_431 ] . V_431 ,
F_249 , 0 , V_77 -> V_59 , V_2 ) ;
if ( V_17 ) {
F_107 ( V_190 , L_77 , V_17 ) ;
goto V_435;
}
return 0 ;
V_435:
while ( V_431 ) {
V_431 -- ;
F_263 ( V_2 -> V_434 [ V_431 ] . V_431 ,
NULL ) ;
F_264 ( V_2 -> V_434 [ V_431 ] . V_431 ,
V_2 -> V_174 [ V_431 ] ) ;
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
V_365 = F_40 ( V_14 , V_382 ) ;
if ( ! V_365 ) {
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_245 ( V_2 , true , true ) ;
return V_439 ;
}
if ( V_365 & V_372 )
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
F_74 ( V_14 , V_382 , V_415 ) ;
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
F_107 ( V_190 , L_78 , V_17 ) ;
return V_17 ;
}
static void F_269 ( struct V_1 * V_2 )
{
int V_431 ;
if ( ! ( V_2 -> V_148 & V_437 ) ) {
F_264 ( V_2 -> V_9 -> V_412 , V_2 ) ;
return;
}
if ( ! V_2 -> V_434 )
return;
for ( V_431 = 0 ; V_431 < V_2 -> V_210 ; V_431 ++ ) {
struct V_173 * V_174 = V_2 -> V_174 [ V_431 ] ;
struct V_432 * V_433 = & V_2 -> V_434 [ V_431 ] ;
if ( ! V_174 -> V_337 . V_64 && ! V_174 -> V_179 . V_64 )
continue;
F_263 ( V_433 -> V_431 , NULL ) ;
F_264 ( V_433 -> V_431 , V_174 ) ;
}
F_264 ( V_2 -> V_434 [ V_431 ] . V_431 , V_2 ) ;
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
int V_431 ;
for ( V_431 = 0 ; V_431 < V_2 -> V_210 ; V_431 ++ )
F_271 ( V_2 -> V_434 [ V_431 ] . V_431 ) ;
F_271 ( V_2 -> V_434 [ V_431 ++ ] . V_431 ) ;
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
F_109 ( V_14 , L_79 ) ;
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
F_277 ( V_14 , L_80 , V_158 ) ;
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
V_497 |= V_508 ;
} else {
if ( V_454 > 4 )
V_497 = V_509 ;
else if ( V_454 > 1 )
V_497 = V_510 ;
else
V_497 = V_503 ;
}
}
V_498 |= V_511 |
V_512 |
V_513 |
V_514 ;
if ( V_2 -> V_368 & V_515 )
V_498 |= V_516 ;
if ( V_2 -> V_368 & V_517 )
V_498 |= V_518 ;
if ( ( V_14 -> V_118 . type >= V_123 ) &&
( V_2 -> V_148 & V_457 ) ) {
unsigned int V_494 = V_2 -> V_339 ;
V_497 |= V_519 ;
F_74 ( V_14 , V_520 , V_497 ) ;
F_296 ( V_2 ) ;
V_499 = V_503 ;
V_499 |= V_498 ;
F_74 ( V_14 , F_299 ( V_494 ) , V_499 ) ;
} else {
F_295 ( V_2 ) ;
V_497 |= V_498 ;
F_74 ( V_14 , V_520 , V_497 ) ;
}
}
static void F_300 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_521 ;
T_4 V_158 = V_64 -> V_158 ;
if ( ! F_170 ( V_64 ) )
return;
V_521 = F_40 ( V_14 , F_301 ( V_158 ) ) ;
V_521 |= V_522 ;
V_521 |= V_523 ;
F_74 ( V_14 , F_301 ( V_158 ) , V_521 ) ;
}
static void F_302 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_443 = V_524 ;
T_1 V_525 ;
T_4 V_158 = V_64 -> V_158 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
if ( V_14 -> V_118 . type == V_119 &&
! ( F_40 ( V_14 , V_450 ) & V_451 ) )
return;
do {
F_276 ( 1000 , 2000 ) ;
V_525 = F_40 ( V_14 , F_45 ( V_158 ) ) ;
} while ( -- V_443 && ! ( V_525 & V_526 ) );
if ( ! V_443 ) {
F_107 ( V_164 , L_81
L_82 , V_158 ) ;
}
}
void F_303 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_443 = V_524 ;
T_1 V_525 ;
T_4 V_158 = V_64 -> V_158 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
V_525 = F_40 ( V_14 , F_45 ( V_158 ) ) ;
V_525 &= ~ V_526 ;
F_74 ( V_14 , F_45 ( V_158 ) , V_525 ) ;
if ( V_14 -> V_118 . type == V_119 &&
! ( F_40 ( V_14 , V_450 ) & V_451 ) )
return;
do {
F_26 ( 10 ) ;
V_525 = F_40 ( V_14 , F_45 ( V_158 ) ) ;
} while ( -- V_443 && ( V_525 & V_526 ) );
if ( ! V_443 ) {
F_107 ( V_164 , L_83
L_82 , V_158 ) ;
}
}
void F_304 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
union V_85 * V_86 ;
V_71 V_527 = V_64 -> V_72 ;
T_1 V_525 ;
T_4 V_158 = V_64 -> V_158 ;
V_525 = F_40 ( V_14 , F_45 ( V_158 ) ) ;
F_303 ( V_2 , V_64 ) ;
F_74 ( V_14 , F_46 ( V_158 ) , ( V_527 & F_274 ( 32 ) ) ) ;
F_74 ( V_14 , F_47 ( V_158 ) , ( V_527 >> 32 ) ) ;
F_74 ( V_14 , F_42 ( V_158 ) ,
V_64 -> V_98 * sizeof( union V_85 ) ) ;
F_240 ( V_14 ) ;
F_74 ( V_14 , F_43 ( V_158 ) , 0 ) ;
F_74 ( V_14 , F_44 ( V_158 ) , 0 ) ;
V_64 -> V_155 = V_2 -> V_446 + F_44 ( V_158 ) ;
F_283 ( V_2 , V_64 ) ;
F_300 ( V_2 , V_64 ) ;
if ( V_14 -> V_118 . type == V_119 ) {
V_525 &= ~ 0x3FFFFF ;
V_525 |= 0x080420 ;
#if ( V_302 < 8192 )
} else {
V_525 &= ~ ( V_528 |
V_529 ) ;
if ( F_142 ( V_64 ) &&
! F_14 ( V_479 , & V_64 -> V_35 ) )
V_525 |= V_530 |
V_529 ;
#endif
}
memset ( V_64 -> V_88 , 0 ,
sizeof( struct V_87 ) * V_64 -> V_98 ) ;
V_86 = F_70 ( V_64 , 0 ) ;
V_86 -> V_105 . V_106 . V_107 = 0 ;
V_525 |= V_526 ;
F_74 ( V_14 , F_45 ( V_158 ) , V_525 ) ;
F_302 ( V_2 , V_64 ) ;
F_150 ( V_64 , F_114 ( V_64 ) ) ;
}
static void F_305 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_495 = V_2 -> V_462 [ V_477 ] . V_496 ;
T_2 V_531 ;
T_1 V_532 = V_533 |
V_534 |
V_535 |
V_536 |
V_537 ;
if ( V_14 -> V_118 . type == V_119 )
return;
if ( V_495 > 3 )
V_532 |= 2u << 29 ;
else if ( V_495 > 1 )
V_532 |= 1u << 29 ;
F_306 (pool, &adapter->fwd_bitmask, 32 )
F_74 ( V_14 , F_307 ( F_308 ( V_531 ) ) , V_532 ) ;
}
static void F_309 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_195 , V_538 ;
T_1 V_539 , V_540 ;
int V_49 ;
if ( ! ( V_2 -> V_148 & V_457 ) )
return;
V_540 = F_40 ( V_14 , V_541 ) ;
V_540 |= V_542 ;
V_540 &= ~ V_543 ;
V_540 |= F_308 ( 0 ) << V_544 ;
V_540 |= V_545 ;
F_74 ( V_14 , V_541 , V_540 ) ;
V_538 = F_308 ( 0 ) % 32 ;
V_195 = ( F_308 ( 0 ) >= 32 ) ? 1 : 0 ;
F_74 ( V_14 , F_310 ( V_195 ) , F_311 ( 31 , V_538 ) ) ;
F_74 ( V_14 , F_310 ( V_195 ^ 1 ) , V_195 - 1 ) ;
F_74 ( V_14 , F_312 ( V_195 ) , F_311 ( 31 , V_538 ) ) ;
F_74 ( V_14 , F_312 ( V_195 ^ 1 ) , V_195 - 1 ) ;
if ( V_2 -> V_546 == V_547 )
F_74 ( V_14 , V_548 , V_549 ) ;
V_14 -> V_118 . V_373 . V_550 ( V_14 , 0 , F_308 ( 0 ) ) ;
V_2 -> V_368 &= ~ V_551 ;
switch ( V_2 -> V_462 [ V_463 ] . V_128 ) {
case V_552 :
V_539 = V_553 ;
break;
case V_464 :
V_539 = V_554 ;
break;
default:
V_539 = V_555 ;
break;
}
F_74 ( V_14 , V_556 , V_539 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_339 ; V_49 ++ ) {
F_313 ( V_2 -> V_77 , V_49 ,
V_2 -> V_557 [ V_49 ] . V_558 ) ;
F_314 ( V_2 -> V_77 , V_49 ,
V_2 -> V_557 [ V_49 ] . V_559 ) ;
}
}
static void F_315 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_76 * V_77 = V_2 -> V_77 ;
int V_560 = V_77 -> V_333 + V_561 + V_562 ;
struct V_63 * V_84 ;
int V_49 ;
T_1 V_563 , V_564 ;
#ifdef F_184
if ( ( V_2 -> V_148 & V_565 ) &&
( V_560 < V_566 ) )
V_560 = V_566 ;
#endif
if ( V_560 < ( V_567 + V_562 ) )
V_560 = ( V_567 + V_562 ) ;
V_563 = F_40 ( V_14 , V_568 ) ;
if ( V_560 != ( V_563 >> V_569 ) ) {
V_563 &= ~ V_570 ;
V_563 |= V_560 << V_569 ;
F_74 ( V_14 , V_568 , V_563 ) ;
}
V_564 = F_40 ( V_14 , V_571 ) ;
V_564 |= V_572 ;
F_74 ( V_14 , V_571 , V_564 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
V_84 = V_2 -> V_84 [ V_49 ] ;
F_316 ( V_84 ) ;
F_37 ( V_479 , & V_84 -> V_35 ) ;
F_37 ( V_573 , & V_84 -> V_35 ) ;
if ( V_2 -> V_368 & V_574 )
F_317 ( V_84 ) ;
if ( F_14 ( V_230 , & V_84 -> V_35 ) )
F_91 ( V_479 , & V_84 -> V_35 ) ;
F_37 ( V_573 , & V_84 -> V_35 ) ;
if ( V_2 -> V_368 & V_575 )
continue;
F_91 ( V_573 , & V_84 -> V_35 ) ;
#if ( V_302 < 8192 )
if ( V_2 -> V_368 & V_574 )
F_91 ( V_479 , & V_84 -> V_35 ) ;
if ( V_576 ||
( V_560 > ( V_567 + V_562 ) ) )
F_91 ( V_479 , & V_84 -> V_35 ) ;
#endif
}
}
static void F_318 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_577 = F_40 ( V_14 , V_578 ) ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_577 |= V_579 ;
break;
case V_123 :
case V_124 :
case V_125 :
if ( V_2 -> V_339 )
V_577 |= V_580 ;
case V_121 :
case V_122 :
F_74 ( V_14 , V_581 ,
( V_582 | F_40 ( V_14 , V_581 ) ) ) ;
V_577 &= ~ V_583 ;
V_577 |= ( V_584 | V_585 ) ;
V_577 |= V_586 ;
break;
default:
return;
}
F_74 ( V_14 , V_578 , V_577 ) ;
}
static void F_319 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
T_1 V_201 , V_587 ;
V_14 -> V_118 . V_373 . V_588 ( V_14 ) ;
F_305 ( V_2 ) ;
F_318 ( V_2 ) ;
V_587 = F_40 ( V_14 , V_589 ) ;
V_587 &= ~ V_590 ;
if ( ! ( V_2 -> V_368 & V_574 ) )
V_587 |= V_590 ;
V_587 |= ( V_591 | V_592 ) ;
F_74 ( V_14 , V_589 , V_587 ) ;
F_298 ( V_2 ) ;
F_315 ( V_2 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ )
F_304 ( V_2 , V_2 -> V_84 [ V_49 ] ) ;
V_201 = F_40 ( V_14 , V_593 ) ;
if ( V_14 -> V_118 . type == V_119 )
V_201 |= V_594 ;
V_201 |= V_595 ;
V_14 -> V_118 . V_373 . V_596 ( V_14 , V_201 ) ;
}
static int F_320 ( struct V_76 * V_77 ,
T_11 V_597 , T_2 V_273 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! V_273 || ! ( V_2 -> V_368 & V_551 ) )
V_14 -> V_118 . V_373 . V_598 ( & V_2 -> V_14 , V_273 , F_308 ( 0 ) , true , ! ! V_273 ) ;
F_91 ( V_273 , V_2 -> V_599 ) ;
return 0 ;
}
static int F_321 ( struct V_15 * V_14 , T_1 V_274 )
{
T_1 V_600 ;
int V_601 ;
if ( V_274 == 0 )
return 0 ;
for ( V_601 = V_602 ; -- V_601 ; ) {
V_600 = F_40 ( V_14 , F_322 ( V_601 ) ) ;
if ( ( V_600 & V_603 ) == V_274 )
break;
}
return V_601 ;
}
void F_323 ( struct V_1 * V_2 , T_1 V_273 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_604 , V_605 ;
int V_601 ;
V_601 = F_321 ( V_14 , V_273 ) ;
if ( ! V_601 )
return;
V_605 = V_601 * 2 + ( F_308 ( 0 ) / 32 ) ;
V_604 = ~ F_224 ( F_308 ( 0 ) % 32 ) ;
V_604 &= F_40 ( V_14 , F_324 ( V_605 ) ) ;
if ( ! V_604 && ! F_40 ( V_14 , F_324 ( V_605 ^ 1 ) ) ) {
if ( ! ( V_2 -> V_368 & V_551 ) )
F_74 ( V_14 , F_324 ( V_605 ) , 0 ) ;
F_74 ( V_14 , F_322 ( V_601 ) , 0 ) ;
}
}
static int F_325 ( struct V_76 * V_77 ,
T_11 V_597 , T_2 V_273 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_273 && ! ( V_2 -> V_368 & V_551 ) )
V_14 -> V_118 . V_373 . V_598 ( V_14 , V_273 , F_308 ( 0 ) , false , true ) ;
F_37 ( V_273 , V_2 -> V_599 ) ;
return 0 ;
}
static void F_326 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_606 ;
int V_49 , V_60 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_606 = F_40 ( V_14 , V_607 ) ;
V_606 &= ~ V_608 ;
F_74 ( V_14 , V_607 , V_606 ) ;
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
V_606 = F_40 ( V_14 , F_45 ( V_60 ) ) ;
V_606 &= ~ V_609 ;
F_74 ( V_14 , F_45 ( V_60 ) , V_606 ) ;
}
break;
default:
break;
}
}
static void F_327 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_606 ;
int V_49 , V_60 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_606 = F_40 ( V_14 , V_607 ) ;
V_606 |= V_608 ;
F_74 ( V_14 , V_607 , V_606 ) ;
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
V_606 = F_40 ( V_14 , F_45 ( V_60 ) ) ;
V_606 |= V_609 ;
F_74 ( V_14 , F_45 ( V_60 ) , V_606 ) ;
}
break;
default:
break;
}
}
static void F_328 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_606 , V_49 ;
V_606 = F_40 ( V_14 , V_607 ) ;
if ( V_2 -> V_148 & V_610 ) {
V_606 |= V_611 ;
F_74 ( V_14 , V_607 , V_606 ) ;
} else {
V_606 &= ~ V_611 ;
F_74 ( V_14 , V_607 , V_606 ) ;
return;
}
if ( V_14 -> V_118 . type == V_119 )
return;
if ( V_2 -> V_368 & V_551 )
return;
V_2 -> V_368 |= V_551 ;
for ( V_49 = V_602 ; -- V_49 ; ) {
T_1 V_195 = F_324 ( V_49 * 2 + F_308 ( 0 ) / 32 ) ;
T_1 V_612 = F_40 ( V_14 , V_195 ) ;
V_612 |= F_224 ( F_308 ( 0 ) % 32 ) ;
F_74 ( V_14 , V_195 , V_612 ) ;
}
for ( V_49 = V_14 -> V_118 . V_613 ; V_49 -- ; )
F_74 ( V_14 , F_329 ( V_49 ) , ~ 0U ) ;
}
static void F_330 ( struct V_1 * V_2 , T_1 V_614 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_615 [ V_616 ] = { 0 } ;
T_1 V_617 = V_614 * 32 ;
T_1 V_618 = V_617 + ( V_616 * 32 ) ;
T_1 V_49 , V_273 , V_605 , V_604 ;
for ( V_49 = V_602 ; -- V_49 ; ) {
T_1 V_600 = F_40 ( V_14 , F_322 ( V_49 ) ) ;
V_273 = V_600 & V_603 ;
if ( V_273 < V_617 || V_273 >= V_618 )
continue;
if ( V_600 ) {
V_615 [ ( V_273 - V_617 ) / 32 ] |= F_224 ( V_273 % 32 ) ;
if ( F_14 ( V_273 , V_2 -> V_599 ) )
continue;
}
V_605 = V_49 * 2 + F_308 ( 0 ) / 32 ;
V_604 = ~ F_224 ( F_308 ( 0 ) % 32 ) ;
V_604 &= F_40 ( V_14 , F_324 ( V_605 ) ) ;
F_74 ( V_14 , F_324 ( V_605 ) , V_604 ) ;
}
for ( V_49 = V_616 ; V_49 -- ; ) {
V_273 = ( V_614 + V_49 ) * 32 ;
V_605 = V_273 / V_619 ;
V_604 = V_273 % V_619 ;
V_615 [ V_49 ] |= V_2 -> V_599 [ V_605 ] >> V_604 ;
F_74 ( V_14 , F_329 ( V_614 + V_49 ) , V_615 [ V_49 ] ) ;
}
}
static void F_331 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_606 , V_49 ;
V_606 = F_40 ( V_14 , V_607 ) ;
V_606 |= V_611 ;
F_74 ( V_14 , V_607 , V_606 ) ;
if ( ! ( V_2 -> V_148 & V_610 ) ||
V_14 -> V_118 . type == V_119 )
return;
if ( ! ( V_2 -> V_368 & V_551 ) )
return;
V_2 -> V_368 &= ~ V_551 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_613 ; V_49 += V_616 )
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
if ( V_14 -> V_118 . V_373 . V_620 )
V_14 -> V_118 . V_373 . V_620 ( V_14 , V_77 ) ;
else
return - V_487 ;
#ifdef F_335
F_336 ( V_2 ) ;
#endif
return F_337 ( V_77 ) ;
}
void F_338 ( struct V_1 * V_2 )
{
struct V_621 * V_622 = & V_2 -> V_622 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_623 ; V_49 ++ , V_622 ++ ) {
V_622 -> V_35 &= ~ V_624 ;
if ( V_622 -> V_35 & V_625 )
V_14 -> V_118 . V_373 . V_626 ( V_14 , V_49 ,
V_622 -> V_627 ,
V_622 -> V_531 ,
V_628 ) ;
else
V_14 -> V_118 . V_373 . V_629 ( V_14 , V_49 ) ;
}
}
static void F_339 ( struct V_1 * V_2 )
{
struct V_621 * V_622 = & V_2 -> V_622 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_623 ; V_49 ++ , V_622 ++ ) {
if ( ! ( V_622 -> V_35 & V_624 ) )
continue;
V_622 -> V_35 &= ~ V_624 ;
if ( V_622 -> V_35 & V_625 )
V_14 -> V_118 . V_373 . V_626 ( V_14 , V_49 ,
V_622 -> V_627 ,
V_622 -> V_531 ,
V_628 ) ;
else
V_14 -> V_118 . V_373 . V_629 ( V_14 , V_49 ) ;
}
}
static void F_340 ( struct V_1 * V_2 )
{
struct V_621 * V_622 = & V_2 -> V_622 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_623 ; V_49 ++ , V_622 ++ ) {
V_622 -> V_35 |= V_624 ;
V_622 -> V_35 &= ~ V_625 ;
}
F_339 ( V_2 ) ;
}
static int F_341 ( struct V_1 * V_2 , T_2 V_531 )
{
struct V_621 * V_622 = & V_2 -> V_622 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 , V_98 = 0 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_623 ; V_49 ++ , V_622 ++ ) {
if ( V_622 -> V_35 & V_630 )
continue;
if ( V_622 -> V_35 & V_625 ) {
if ( V_622 -> V_531 != V_531 )
continue;
}
V_98 ++ ;
}
return V_98 ;
}
static void F_342 ( struct V_1 * V_2 )
{
struct V_621 * V_622 = & V_2 -> V_622 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
memcpy ( & V_622 -> V_627 , V_14 -> V_118 . V_627 , V_631 ) ;
V_622 -> V_531 = F_308 ( 0 ) ;
V_622 -> V_35 = V_630 | V_625 ;
V_14 -> V_118 . V_373 . V_626 ( V_14 , 0 , V_622 -> V_627 , V_622 -> V_531 ,
V_628 ) ;
}
int F_343 ( struct V_1 * V_2 ,
const T_4 * V_627 , T_2 V_531 )
{
struct V_621 * V_622 = & V_2 -> V_622 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( F_344 ( V_627 ) )
return - V_632 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_623 ; V_49 ++ , V_622 ++ ) {
if ( V_622 -> V_35 & V_625 )
continue;
F_345 ( V_622 -> V_627 , V_627 ) ;
V_622 -> V_531 = V_531 ;
V_622 -> V_35 |= V_624 |
V_625 ;
F_339 ( V_2 ) ;
return V_49 ;
}
return - V_487 ;
}
int F_346 ( struct V_1 * V_2 ,
const T_4 * V_627 , T_2 V_531 )
{
struct V_621 * V_622 = & V_2 -> V_622 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( F_344 ( V_627 ) )
return - V_632 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_623 ; V_49 ++ , V_622 ++ ) {
if ( ! ( V_622 -> V_35 & V_625 ) )
continue;
if ( V_622 -> V_531 != V_531 )
continue;
if ( ! F_347 ( V_627 , V_622 -> V_627 ) )
continue;
V_622 -> V_35 |= V_624 ;
V_622 -> V_35 &= ~ V_625 ;
F_339 ( V_2 ) ;
return 0 ;
}
return - V_487 ;
}
static int F_348 ( struct V_76 * V_77 , int V_633 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
int V_98 = 0 ;
if ( F_349 ( V_77 ) > F_341 ( V_2 , V_633 ) )
return - V_487 ;
if ( ! F_350 ( V_77 ) ) {
struct V_634 * V_635 ;
F_351 (ha, netdev) {
F_346 ( V_2 , V_635 -> V_627 , V_633 ) ;
F_343 ( V_2 , V_635 -> V_627 , V_633 ) ;
V_98 ++ ;
}
}
return V_98 ;
}
static int F_352 ( struct V_76 * V_77 , const unsigned char * V_627 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
int V_636 ;
V_636 = F_343 ( V_2 , V_627 , F_308 ( 0 ) ) ;
return F_353 ( int , V_636 , 0 ) ;
}
static int F_354 ( struct V_76 * V_77 , const unsigned char * V_627 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
F_346 ( V_2 , V_627 , F_308 ( 0 ) ) ;
return 0 ;
}
void F_355 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_637 , V_638 = V_639 | V_640 ;
T_12 V_218 = V_77 -> V_218 ;
int V_98 ;
V_637 = F_40 ( V_14 , V_641 ) ;
V_637 &= ~ V_642 ;
V_637 |= V_643 ;
V_637 |= V_644 ;
V_637 |= V_645 ;
V_637 &= ~ ( V_646 | V_647 ) ;
if ( V_77 -> V_148 & V_648 ) {
V_14 -> V_649 . V_650 = true ;
V_637 |= ( V_646 | V_647 ) ;
V_638 |= V_651 ;
V_218 &= ~ V_652 ;
} else {
if ( V_77 -> V_148 & V_653 ) {
V_637 |= V_647 ;
V_638 |= V_651 ;
}
V_14 -> V_649 . V_650 = false ;
}
if ( F_356 ( V_77 , F_352 , F_354 ) ) {
V_637 |= V_646 ;
V_638 |= V_654 ;
}
V_98 = F_334 ( V_77 ) ;
if ( V_98 < 0 ) {
V_637 |= V_647 ;
V_638 |= V_651 ;
} else if ( V_98 ) {
V_638 |= V_655 ;
}
if ( V_14 -> V_118 . type != V_119 ) {
V_638 |= F_40 ( V_14 , F_357 ( F_308 ( 0 ) ) ) &
~ ( V_651 | V_655 |
V_654 ) ;
F_74 ( V_14 , F_357 ( F_308 ( 0 ) ) , V_638 ) ;
}
if ( V_218 & V_297 ) {
V_637 |= ( V_642 |
V_643 |
V_645 ) ;
V_637 &= ~ ( V_644 ) ;
}
F_74 ( V_14 , V_641 , V_637 ) ;
if ( V_218 & V_271 )
F_327 ( V_2 ) ;
else
F_326 ( V_2 ) ;
if ( V_218 & V_652 )
F_331 ( V_2 ) ;
else
F_328 ( V_2 ) ;
}
static void F_358 ( struct V_1 * V_2 )
{
int V_656 ;
for ( V_656 = 0 ; V_656 < V_2 -> V_210 ; V_656 ++ )
F_359 ( & V_2 -> V_174 [ V_656 ] -> V_277 ) ;
}
static void F_360 ( struct V_1 * V_2 )
{
int V_656 ;
for ( V_656 = 0 ; V_656 < V_2 -> V_210 ; V_656 ++ )
F_361 ( & V_2 -> V_174 [ V_656 ] -> V_277 ) ;
}
static void F_362 ( struct V_1 * V_2 , T_1 V_128 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_657 ;
if ( ! ( V_2 -> V_148 & ( V_658 |
V_659 ) ) )
return;
V_657 = F_40 ( V_14 , V_660 ) && ~ V_128 ;
F_74 ( V_14 , V_660 , V_657 ) ;
if ( V_128 & V_661 )
V_2 -> V_662 = 0 ;
if ( V_128 & V_663 )
V_2 -> V_664 = 0 ;
}
static void F_363 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_560 = V_2 -> V_77 -> V_333 + V_561 + V_562 ;
if ( ! ( V_2 -> V_148 & V_149 ) ) {
if ( V_14 -> V_118 . type == V_119 )
F_364 ( V_2 -> V_77 , 65536 ) ;
return;
}
if ( V_14 -> V_118 . type == V_119 )
F_364 ( V_2 -> V_77 , 32768 ) ;
#ifdef F_184
if ( V_2 -> V_77 -> V_218 & V_665 )
V_560 = F_229 ( V_560 , V_566 ) ;
#endif
if ( V_2 -> V_666 & V_667 ) {
F_365 ( V_14 , & V_2 -> V_145 , V_560 ,
V_668 ) ;
F_365 ( V_14 , & V_2 -> V_145 , V_560 ,
V_669 ) ;
F_366 ( V_14 , & V_2 -> V_145 ) ;
} else if ( V_2 -> V_670 && V_2 -> V_147 ) {
F_367 ( & V_2 -> V_14 ,
V_2 -> V_670 ,
V_560 ) ;
F_368 ( & V_2 -> V_14 ,
V_2 -> V_147 -> V_144 ,
V_2 -> V_670 -> V_671 ) ;
}
if ( V_14 -> V_118 . type != V_119 ) {
T_1 V_672 = 0 ;
T_2 V_495 = V_2 -> V_462 [ V_477 ] . V_496 - 1 ;
while ( V_495 ) {
V_672 ++ ;
V_495 >>= 1 ;
}
F_74 ( V_14 , V_673 , V_672 * 0x11111111 ) ;
}
}
static int F_369 ( struct V_1 * V_2 , int V_674 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_76 * V_89 = V_2 -> V_77 ;
int V_416 , V_143 , V_675 , V_676 ;
T_1 V_677 , V_678 ;
V_143 = V_416 = V_89 -> V_333 + V_561 + V_562 + V_679 ;
#ifdef F_184
if ( ( V_89 -> V_218 & V_665 ) &&
( V_143 < V_566 ) &&
( V_674 == F_370 ( V_2 ) ) )
V_143 = V_566 ;
#endif
switch ( V_14 -> V_118 . type ) {
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_677 = F_371 ( V_416 , V_143 ) ;
break;
default:
V_677 = F_372 ( V_416 , V_143 ) ;
break;
}
if ( V_2 -> V_148 & V_457 )
V_677 += F_373 ( V_143 ) ;
V_675 = F_374 ( V_677 ) ;
V_678 = F_40 ( V_14 , F_375 ( V_674 ) ) >> 10 ;
V_676 = V_678 - V_675 ;
if ( V_676 < 0 ) {
F_27 ( V_164 , L_84
L_85
L_86 , V_674 ) ;
V_676 = V_143 + 1 ;
}
return V_676 ;
}
static int F_376 ( struct V_1 * V_2 , int V_674 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_76 * V_89 = V_2 -> V_77 ;
int V_143 ;
T_1 V_677 ;
V_143 = V_89 -> V_333 + V_561 + V_562 ;
#ifdef F_184
if ( ( V_89 -> V_218 & V_665 ) &&
( V_143 < V_566 ) &&
( V_674 == F_84 ( V_89 , V_2 -> V_680 . V_681 ) ) )
V_143 = V_566 ;
#endif
switch ( V_14 -> V_118 . type ) {
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_677 = F_377 ( V_143 ) ;
break;
default:
V_677 = F_378 ( V_143 ) ;
break;
}
return F_374 ( V_677 ) ;
}
static void F_379 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_682 = F_279 ( V_2 -> V_77 ) ;
int V_49 ;
if ( ! V_682 )
V_682 = 1 ;
for ( V_49 = 0 ; V_49 < V_682 ; V_49 ++ ) {
V_14 -> V_134 . V_683 [ V_49 ] = F_369 ( V_2 , V_49 ) ;
V_14 -> V_134 . V_684 [ V_49 ] = F_376 ( V_2 , V_49 ) ;
if ( V_14 -> V_134 . V_684 [ V_49 ] > V_14 -> V_134 . V_683 [ V_49 ] )
V_14 -> V_134 . V_684 [ V_49 ] = 0 ;
}
for (; V_49 < V_685 ; V_49 ++ )
V_14 -> V_134 . V_683 [ V_49 ] = 0 ;
}
static void F_380 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_686 ;
T_4 V_143 = F_279 ( V_2 -> V_77 ) ;
if ( V_2 -> V_148 & V_409 ||
V_2 -> V_148 & V_687 )
V_686 = 32 << V_2 -> V_688 ;
else
V_686 = 0 ;
V_14 -> V_118 . V_373 . V_689 ( V_14 , V_143 , V_686 , V_690 ) ;
F_379 ( V_2 ) ;
}
static void F_381 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_691 * V_692 ;
struct V_693 * V_694 ;
F_382 ( & V_2 -> V_695 ) ;
if ( ! F_383 ( & V_2 -> V_696 ) )
F_384 ( V_14 , & V_2 -> V_697 ) ;
F_385 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_386 ( V_14 ,
& V_694 -> V_694 ,
V_694 -> V_698 ,
( V_694 -> V_699 == V_700 ) ?
V_700 :
V_2 -> V_84 [ V_694 -> V_699 ] -> V_158 ) ;
}
F_387 ( & V_2 -> V_695 ) ;
}
static void F_388 ( struct V_76 * V_89 , unsigned int V_531 ,
struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_638 ;
V_638 = F_40 ( V_14 , F_357 ( V_531 ) ) ;
V_638 |= ( V_655 | V_639 | V_640 ) ;
V_638 &= ~ V_651 ;
if ( V_89 -> V_148 & V_653 ) {
V_638 |= V_651 ;
} else {
V_638 |= V_655 ;
V_14 -> V_118 . V_373 . V_620 ( V_14 , V_89 ) ;
}
F_348 ( V_2 -> V_77 , V_531 ) ;
F_74 ( V_14 , F_357 ( V_531 ) , V_638 ) ;
}
static void F_389 ( struct V_701 * V_702 )
{
struct V_1 * V_2 = V_702 -> V_157 ;
int V_495 = V_2 -> V_703 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_531 = V_702 -> V_531 ;
T_1 V_532 = V_533 |
V_534 |
V_535 |
V_536 |
V_537 ;
if ( V_14 -> V_118 . type == V_119 )
return;
if ( V_495 > 3 )
V_532 |= 2u << 29 ;
else if ( V_495 > 1 )
V_532 |= 1u << 29 ;
F_74 ( V_14 , F_307 ( F_308 ( V_531 ) ) , V_532 ) ;
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
static void F_392 ( struct V_701 * V_702 ,
struct V_63 * V_84 )
{
struct V_1 * V_2 = V_702 -> V_157 ;
int V_117 = V_84 -> V_96 + V_702 -> V_704 ;
F_303 ( V_2 , V_84 ) ;
F_276 ( 10000 , 20000 ) ;
F_243 ( V_2 , F_259 ( V_117 ) ) ;
F_390 ( V_84 ) ;
V_84 -> V_156 = NULL ;
}
static int F_393 ( struct V_76 * V_705 ,
struct V_701 * V_706 )
{
struct V_1 * V_2 = V_706 -> V_157 ;
unsigned int V_707 = V_706 -> V_704 ;
unsigned int V_708 = V_706 -> V_709 ;
int V_49 ;
F_394 ( V_705 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_703 ; V_49 ++ ) {
F_392 ( V_706 , V_2 -> V_84 [ V_707 + V_49 ] ) ;
V_2 -> V_84 [ V_707 + V_49 ] -> V_77 = V_2 -> V_77 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_703 ; V_49 ++ ) {
V_2 -> V_92 [ V_708 + V_49 ] -> V_156 = NULL ;
V_2 -> V_92 [ V_708 + V_49 ] -> V_77 = V_2 -> V_77 ;
}
return 0 ;
}
static int F_395 ( struct V_76 * V_705 ,
struct V_701 * V_706 )
{
struct V_1 * V_2 = V_706 -> V_157 ;
unsigned int V_707 , V_708 , V_401 ;
int V_49 , V_710 , V_17 = 0 ;
if ( ! F_14 ( V_706 -> V_531 , & V_2 -> V_711 ) )
return 0 ;
V_710 = V_706 -> V_531 * V_2 -> V_703 ;
F_396 ( V_705 , L_87 ,
V_706 -> V_531 , V_2 -> V_712 ,
V_710 , V_710 + V_2 -> V_703 ,
V_2 -> V_711 ) ;
V_706 -> V_77 = V_705 ;
V_706 -> V_704 = V_707 = V_710 ;
V_706 -> V_709 = V_708 = V_710 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_703 ; V_49 ++ )
F_392 ( V_706 , V_2 -> V_84 [ V_707 + V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_703 ; V_49 ++ ) {
V_2 -> V_84 [ V_707 + V_49 ] -> V_77 = V_705 ;
V_2 -> V_84 [ V_707 + V_49 ] -> V_156 = V_706 ;
F_304 ( V_2 , V_2 -> V_84 [ V_707 + V_49 ] ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_703 ; V_49 ++ ) {
V_2 -> V_92 [ V_708 + V_49 ] -> V_77 = V_705 ;
V_2 -> V_92 [ V_708 + V_49 ] -> V_156 = V_706 ;
}
V_401 = F_353 (unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues) ;
V_17 = F_397 ( V_705 , V_401 ) ;
if ( V_17 )
goto V_713;
V_17 = F_398 ( V_705 , V_401 ) ;
if ( V_17 )
goto V_713;
if ( F_399 ( V_705 -> V_714 ) )
F_343 ( V_2 , V_705 -> V_714 , V_706 -> V_531 ) ;
F_389 ( V_706 ) ;
F_388 ( V_705 , V_706 -> V_531 , V_2 ) ;
return V_17 ;
V_713:
F_393 ( V_705 , V_706 ) ;
return V_17 ;
}
static int F_400 ( struct V_76 * V_106 , void * V_103 )
{
if ( F_401 ( V_106 ) ) {
struct V_715 * V_716 = F_87 ( V_106 ) ;
struct V_701 * V_702 = V_716 -> V_717 ;
if ( V_716 -> V_717 )
F_395 ( V_106 , V_702 ) ;
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
V_14 -> V_118 . V_373 . V_718 ( V_14 ) ;
break;
default:
break;
}
if ( V_2 -> V_148 & V_409 ) {
F_406 ( & V_2 -> V_14 ,
V_2 -> V_688 ) ;
} else if ( V_2 -> V_148 & V_687 ) {
F_407 ( & V_2 -> V_14 ,
V_2 -> V_688 ) ;
F_381 ( V_2 ) ;
}
switch ( V_14 -> V_118 . type ) {
case V_121 :
case V_122 :
V_14 -> V_118 . V_373 . V_719 ( V_14 ) ;
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
V_2 -> V_368 |= V_720 ;
V_2 -> V_368 |= V_393 ;
V_2 -> V_394 = 0 ;
}
static int F_410 ( struct V_15 * V_14 )
{
T_1 V_20 ;
bool V_721 , V_375 = false ;
int V_636 = V_722 ;
if ( V_14 -> V_118 . V_373 . V_374 )
V_636 = V_14 -> V_118 . V_373 . V_374 ( V_14 , & V_20 , & V_375 , false ) ;
if ( V_636 )
return V_636 ;
V_20 = V_14 -> V_46 . V_723 ;
if ( ( ! V_20 ) && ( V_14 -> V_118 . V_373 . V_724 ) )
V_636 = V_14 -> V_118 . V_373 . V_724 ( V_14 , & V_20 ,
& V_721 ) ;
if ( V_636 )
return V_636 ;
if ( V_14 -> V_118 . V_373 . V_725 )
V_636 = V_14 -> V_118 . V_373 . V_725 ( V_14 , V_20 , V_375 ) ;
return V_636 ;
}
static void F_411 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_726 = 0 ;
if ( V_2 -> V_148 & V_437 ) {
V_726 = V_727 | V_728 |
V_729 ;
V_726 |= V_730 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
F_74 ( V_14 , V_731 , V_732 ) ;
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
F_74 ( V_14 , V_731 , V_732 ) ;
}
if ( V_2 -> V_148 & V_457 ) {
V_726 &= ~ V_733 ;
switch ( V_2 -> V_462 [ V_463 ] . V_128 ) {
case V_552 :
V_726 |= V_734 ;
break;
case V_464 :
V_726 |= V_735 ;
break;
default:
V_726 |= V_736 ;
break;
}
}
if ( V_2 -> V_368 & V_383 ) {
switch ( V_2 -> V_14 . V_118 . type ) {
case V_121 :
V_726 |= V_737 ;
break;
default:
break;
}
}
if ( V_2 -> V_148 & V_381 )
V_726 |= F_413 ( V_14 ) ;
switch ( V_14 -> V_118 . type ) {
case V_121 :
V_726 |= V_738 | V_739 ;
break;
case V_124 :
case V_125 :
V_726 |= V_740 ;
break;
default:
break;
}
F_74 ( V_14 , V_741 , V_726 ) ;
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
if ( V_14 -> V_118 . V_373 . V_742 )
V_14 -> V_118 . V_373 . V_742 ( V_14 ) ;
if ( V_14 -> V_46 . V_373 . V_743 )
V_14 -> V_46 . V_373 . V_743 ( V_14 , true ) ;
F_36 () ;
F_37 ( V_34 , & V_2 -> V_35 ) ;
F_358 ( V_2 ) ;
if ( F_236 ( V_14 ) ) {
F_409 ( V_2 ) ;
} else {
V_17 = F_410 ( V_14 ) ;
if ( V_17 )
F_107 ( V_190 , L_88 , V_17 ) ;
}
F_40 ( V_14 , V_382 ) ;
F_245 ( V_2 , true , true ) ;
if ( V_2 -> V_148 & V_381 ) {
T_1 V_744 = F_40 ( V_14 , V_745 ) ;
if ( V_744 & V_746 )
F_232 ( V_164 , L_70 ) ;
}
V_2 -> V_148 |= V_397 ;
V_2 -> V_398 = V_189 ;
F_415 ( & V_2 -> V_747 , V_189 ) ;
V_110 = F_40 ( V_14 , V_111 ) ;
V_110 |= V_748 ;
F_74 ( V_14 , V_111 , V_110 ) ;
}
void F_416 ( struct V_1 * V_2 )
{
F_417 ( F_418 () ) ;
F_419 ( V_2 -> V_77 ) ;
while ( F_15 ( V_749 , & V_2 -> V_35 ) )
F_276 ( 1000 , 2000 ) ;
if ( V_2 -> V_14 . V_46 . type == V_750 )
F_420 ( V_2 ) ;
F_421 ( V_2 ) ;
if ( V_2 -> V_148 & V_457 )
F_422 ( 2000 ) ;
F_423 ( V_2 ) ;
F_37 ( V_749 , & V_2 -> V_35 ) ;
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
while ( F_15 ( V_751 , & V_2 -> V_35 ) )
F_276 ( 1000 , 2000 ) ;
V_2 -> V_368 &= ~ ( V_720 |
V_393 ) ;
V_2 -> V_148 &= ~ V_395 ;
V_17 = V_14 -> V_118 . V_373 . V_752 ( V_14 ) ;
switch ( V_17 ) {
case 0 :
case V_753 :
case V_754 :
break;
case V_755 :
F_18 ( L_89 ) ;
break;
case V_756 :
F_11 ( L_90
L_91
L_92
L_93
L_94
L_95 ) ;
break;
default:
F_18 ( L_96 , V_17 ) ;
}
F_37 ( V_751 , & V_2 -> V_35 ) ;
F_340 ( V_2 ) ;
F_425 ( V_77 , NULL ) ;
F_342 ( V_2 ) ;
if ( V_14 -> V_118 . V_757 )
V_14 -> V_118 . V_373 . V_758 ( V_14 , F_308 ( 0 ) ) ;
if ( F_14 ( V_759 , & V_2 -> V_35 ) )
F_426 ( V_2 ) ;
if ( V_14 -> V_46 . V_373 . V_743 ) {
if ( ! F_63 ( V_2 -> V_77 ) && ! V_2 -> V_760 )
V_14 -> V_46 . V_373 . V_743 ( V_14 , false ) ;
else
V_14 -> V_46 . V_373 . V_743 ( V_14 , true ) ;
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
struct V_691 * V_692 ;
struct V_693 * V_694 ;
F_382 ( & V_2 -> V_695 ) ;
F_385 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_432 ( & V_694 -> V_761 ) ;
F_266 ( V_694 ) ;
}
V_2 -> V_762 = 0 ;
F_387 ( & V_2 -> V_695 ) ;
}
static int F_433 ( struct V_76 * V_106 , void * V_103 )
{
if ( F_401 ( V_106 ) ) {
struct V_715 * V_274 = F_87 ( V_106 ) ;
if ( V_274 -> V_717 ) {
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
V_14 -> V_118 . V_373 . V_588 ( V_14 ) ;
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
F_436 ( & V_2 -> V_747 ) ;
if ( V_2 -> V_339 ) {
F_74 ( & V_2 -> V_14 , V_341 , 0 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_339 ; V_49 ++ )
V_2 -> V_557 [ V_49 ] . V_763 = false ;
F_437 ( V_2 ) ;
F_438 ( V_2 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ ) {
T_4 V_158 = V_2 -> V_92 [ V_49 ] -> V_158 ;
F_74 ( V_14 , F_53 ( V_158 ) , V_764 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ ) {
T_4 V_158 = V_2 -> V_94 [ V_49 ] -> V_158 ;
F_74 ( V_14 , F_53 ( V_158 ) , V_764 ) ;
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
if ( V_14 -> V_118 . V_373 . V_765 )
V_14 -> V_118 . V_373 . V_765 ( V_14 ) ;
F_430 ( V_2 ) ;
F_429 ( V_2 ) ;
}
static void F_440 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_21 ) {
case V_378 :
case V_379 :
if ( ! V_14 -> V_46 . V_766 )
break;
V_2 -> V_368 |= V_767 ;
if ( ! V_14 -> V_46 . V_768 )
break;
V_2 -> V_368 |= V_769 ;
break;
default:
V_2 -> V_368 &= ~ V_767 ;
V_2 -> V_368 &= ~ V_769 ;
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
struct V_770 * V_143 ;
int V_60 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
case V_121 :
V_2 -> V_145 . V_771 . V_772 = V_685 ;
V_2 -> V_145 . V_771 . V_773 = V_685 ;
break;
case V_122 :
case V_123 :
V_2 -> V_145 . V_771 . V_772 = V_774 ;
V_2 -> V_145 . V_771 . V_773 = V_774 ;
break;
case V_124 :
case V_125 :
default:
V_2 -> V_145 . V_771 . V_772 = V_775 ;
V_2 -> V_145 . V_771 . V_773 = V_775 ;
break;
}
for ( V_60 = 0 ; V_60 < V_685 ; V_60 ++ ) {
V_143 = & V_2 -> V_145 . V_776 [ V_60 ] ;
V_143 -> V_777 [ V_668 ] . V_778 = 0 ;
V_143 -> V_777 [ V_668 ] . V_779 = 12 + ( V_60 & 1 ) ;
V_143 -> V_777 [ V_669 ] . V_778 = 0 ;
V_143 -> V_777 [ V_669 ] . V_779 = 12 + ( V_60 & 1 ) ;
V_143 -> V_780 = V_781 ;
}
V_143 = & V_2 -> V_145 . V_776 [ 0 ] ;
V_143 -> V_777 [ V_668 ] . V_782 = 0xFF ;
V_143 -> V_777 [ V_669 ] . V_782 = 0xFF ;
V_2 -> V_145 . V_783 [ V_668 ] [ 0 ] = 100 ;
V_2 -> V_145 . V_783 [ V_669 ] [ 0 ] = 100 ;
V_2 -> V_145 . V_146 = false ;
V_2 -> V_784 = 0x00 ;
if ( V_2 -> V_148 & V_785 )
V_2 -> V_666 = V_786 | V_667 ;
memcpy ( & V_2 -> V_787 , & V_2 -> V_145 ,
sizeof( V_2 -> V_787 ) ) ;
}
static int F_443 ( struct V_1 * V_2 ,
const struct V_788 * V_789 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_226 , V_790 ;
T_1 V_791 ;
int V_49 ;
V_14 -> V_792 = V_9 -> V_793 ;
V_14 -> V_21 = V_9 -> V_211 ;
V_14 -> V_794 = V_9 -> V_795 ;
V_14 -> V_796 = V_9 -> V_797 ;
V_14 -> V_798 = V_9 -> V_799 ;
V_789 -> V_800 ( V_14 ) ;
V_226 = F_353 ( int , F_444 ( V_2 ) , F_445 () ) ;
V_2 -> V_462 [ V_477 ] . V_801 = V_226 ;
V_2 -> V_368 |= V_802 ;
V_2 -> V_803 = V_804 ;
V_2 -> V_447 = 20 ;
V_790 = F_353 ( int , V_805 , F_445 () ) ;
V_2 -> V_462 [ V_806 ] . V_801 = V_790 ;
V_2 -> V_688 = V_807 ;
#ifdef F_257
V_2 -> V_148 |= V_213 ;
#endif
#ifdef F_405
V_2 -> V_148 |= V_785 ;
V_2 -> V_148 &= ~ V_149 ;
#endif
#ifdef F_184
V_2 -> V_148 |= V_808 ;
V_2 -> V_148 &= ~ V_565 ;
#ifdef F_405
V_2 -> V_680 . V_681 = V_809 ;
#endif
#endif
V_2 -> V_810 [ 0 ] = F_288 ( sizeof( * V_2 -> V_810 [ 0 ] ) ,
V_486 ) ;
if ( ! V_2 -> V_810 [ 0 ] )
return - V_487 ;
V_2 -> V_810 [ 0 ] -> V_811 = V_812 ;
for ( V_49 = 1 ; V_49 < V_813 ; V_49 ++ )
V_2 -> V_810 [ V_49 ] = NULL ;
V_2 -> V_622 = F_288 ( sizeof( struct V_621 ) *
V_14 -> V_118 . V_623 ,
V_814 ) ;
if ( ! V_2 -> V_622 )
return - V_487 ;
if ( F_287 ( V_2 ) )
return - V_487 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_2 -> V_368 &= ~ V_802 ;
if ( V_14 -> V_21 == V_815 )
V_2 -> V_148 |= V_381 ;
V_2 -> V_803 = V_816 ;
V_2 -> V_462 [ V_806 ] . V_801 = 0 ;
V_2 -> V_447 = 0 ;
V_2 -> V_688 = 0 ;
#ifdef F_184
V_2 -> V_148 &= ~ V_808 ;
V_2 -> V_148 &= ~ V_565 ;
#ifdef F_405
V_2 -> V_680 . V_681 = 0 ;
#endif
#endif
break;
case V_121 :
if ( V_14 -> V_21 == V_370 )
V_2 -> V_368 |= V_383 ;
break;
case V_122 :
V_791 = F_40 ( V_14 , F_446 ( V_14 ) ) ;
if ( V_791 & V_817 )
V_2 -> V_368 |= V_383 ;
break;
case V_125 :
V_2 -> V_148 |= V_659 ;
switch ( V_14 -> V_21 ) {
case V_378 :
case V_379 :
V_2 -> V_368 |= V_383 ;
break;
default:
break;
}
case V_124 :
#ifdef F_405
V_2 -> V_148 &= ~ V_785 ;
#endif
#ifdef F_184
V_2 -> V_148 &= ~ V_808 ;
#ifdef F_405
V_2 -> V_680 . V_681 = 0 ;
#endif
#endif
case V_123 :
if ( V_14 -> V_118 . type == V_123 )
V_2 -> V_368 |= V_383 ;
#ifdef F_257
V_2 -> V_148 &= ~ V_213 ;
#endif
V_2 -> V_148 |= V_658 ;
break;
default:
break;
}
#ifdef F_184
F_447 ( & V_2 -> V_680 . V_818 ) ;
#endif
F_447 ( & V_2 -> V_695 ) ;
#ifdef F_405
F_442 ( V_2 ) ;
#endif
V_14 -> V_134 . V_819 = V_136 ;
V_14 -> V_134 . V_135 = V_136 ;
F_379 ( V_2 ) ;
V_14 -> V_134 . V_820 = V_821 ;
V_14 -> V_134 . V_822 = true ;
V_14 -> V_134 . V_823 = F_448 ( V_14 ) ;
#ifdef F_335
if ( V_824 > 0 )
F_11 ( L_97 ) ;
if ( V_14 -> V_118 . type != V_119 ) {
if ( V_824 > V_825 ) {
V_824 = 0 ;
F_11 ( L_98 ) ;
}
}
#endif
V_2 -> V_428 = 1 ;
V_2 -> V_826 = 1 ;
V_2 -> V_827 = V_828 ;
V_2 -> V_829 = V_830 ;
V_2 -> V_831 = V_832 ;
if ( F_449 ( V_14 ) ) {
F_18 ( L_99 ) ;
return - V_833 ;
}
F_91 ( 0 , & V_2 -> V_711 ) ;
F_91 ( V_34 , & V_2 -> V_35 ) ;
return 0 ;
}
int F_450 ( struct V_63 * V_92 )
{
struct V_211 * V_89 = V_92 -> V_89 ;
int V_834 = F_451 ( V_89 ) ;
int V_835 = - 1 ;
int V_304 ;
V_304 = sizeof( struct V_66 ) * V_92 -> V_98 ;
if ( V_92 -> V_174 )
V_835 = V_92 -> V_174 -> V_836 ;
V_92 -> V_68 = F_452 ( V_304 , V_835 ) ;
if ( ! V_92 -> V_68 )
V_92 -> V_68 = F_453 ( V_304 ) ;
if ( ! V_92 -> V_68 )
goto V_17;
V_92 -> V_304 = V_92 -> V_98 * sizeof( union V_78 ) ;
V_92 -> V_304 = F_175 ( V_92 -> V_304 , 4096 ) ;
F_454 ( V_89 , V_835 ) ;
V_92 -> V_97 = F_455 ( V_89 ,
V_92 -> V_304 ,
& V_92 -> V_72 ,
V_486 ) ;
F_454 ( V_89 , V_834 ) ;
if ( ! V_92 -> V_97 )
V_92 -> V_97 = F_455 ( V_89 , V_92 -> V_304 ,
& V_92 -> V_72 , V_486 ) ;
if ( ! V_92 -> V_97 )
goto V_17;
V_92 -> V_70 = 0 ;
V_92 -> V_69 = 0 ;
return 0 ;
V_17:
F_456 ( V_92 -> V_68 ) ;
V_92 -> V_68 = NULL ;
F_457 ( V_89 , L_100 ) ;
return - V_487 ;
}
static int F_458 ( struct V_1 * V_2 )
{
int V_49 , V_60 = 0 , V_17 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ ) {
V_17 = F_450 ( V_2 -> V_92 [ V_49 ] ) ;
if ( ! V_17 )
continue;
F_107 ( V_190 , L_101 , V_49 ) ;
goto V_837;
}
for ( V_60 = 0 ; V_60 < V_2 -> V_93 ; V_60 ++ ) {
V_17 = F_450 ( V_2 -> V_94 [ V_60 ] ) ;
if ( ! V_17 )
continue;
F_107 ( V_190 , L_101 , V_60 ) ;
goto V_837;
}
return 0 ;
V_837:
while ( V_60 -- )
F_459 ( V_2 -> V_94 [ V_60 ] ) ;
while ( V_49 -- )
F_459 ( V_2 -> V_92 [ V_49 ] ) ;
return V_17 ;
}
int F_460 ( struct V_1 * V_2 ,
struct V_63 * V_84 )
{
struct V_211 * V_89 = V_84 -> V_89 ;
int V_834 = F_451 ( V_89 ) ;
int V_835 = - 1 ;
int V_304 ;
V_304 = sizeof( struct V_87 ) * V_84 -> V_98 ;
if ( V_84 -> V_174 )
V_835 = V_84 -> V_174 -> V_836 ;
V_84 -> V_88 = F_452 ( V_304 , V_835 ) ;
if ( ! V_84 -> V_88 )
V_84 -> V_88 = F_453 ( V_304 ) ;
if ( ! V_84 -> V_88 )
goto V_17;
V_84 -> V_304 = V_84 -> V_98 * sizeof( union V_85 ) ;
V_84 -> V_304 = F_175 ( V_84 -> V_304 , 4096 ) ;
F_454 ( V_89 , V_835 ) ;
V_84 -> V_97 = F_455 ( V_89 ,
V_84 -> V_304 ,
& V_84 -> V_72 ,
V_486 ) ;
F_454 ( V_89 , V_834 ) ;
if ( ! V_84 -> V_97 )
V_84 -> V_97 = F_455 ( V_89 , V_84 -> V_304 ,
& V_84 -> V_72 , V_486 ) ;
if ( ! V_84 -> V_97 )
goto V_17;
V_84 -> V_69 = 0 ;
V_84 -> V_70 = 0 ;
V_84 -> V_317 = V_2 -> V_317 ;
return 0 ;
V_17:
F_456 ( V_84 -> V_88 ) ;
V_84 -> V_88 = NULL ;
F_457 ( V_89 , L_102 ) ;
return - V_487 ;
}
static int F_461 ( struct V_1 * V_2 )
{
int V_49 , V_17 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
V_17 = F_460 ( V_2 , V_2 -> V_84 [ V_49 ] ) ;
if ( ! V_17 )
continue;
F_107 ( V_190 , L_103 , V_49 ) ;
goto V_838;
}
#ifdef F_184
V_17 = F_462 ( V_2 ) ;
if ( ! V_17 )
#endif
return 0 ;
V_838:
while ( V_49 -- )
F_463 ( V_2 -> V_84 [ V_49 ] ) ;
return V_17 ;
}
void F_459 ( struct V_63 * V_92 )
{
F_427 ( V_92 ) ;
F_456 ( V_92 -> V_68 ) ;
V_92 -> V_68 = NULL ;
if ( ! V_92 -> V_97 )
return;
F_464 ( V_92 -> V_89 , V_92 -> V_304 ,
V_92 -> V_97 , V_92 -> V_72 ) ;
V_92 -> V_97 = NULL ;
}
static void F_465 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ )
if ( V_2 -> V_92 [ V_49 ] -> V_97 )
F_459 ( V_2 -> V_92 [ V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ )
if ( V_2 -> V_94 [ V_49 ] -> V_97 )
F_459 ( V_2 -> V_94 [ V_49 ] ) ;
}
void F_463 ( struct V_63 * V_84 )
{
F_390 ( V_84 ) ;
V_84 -> V_317 = NULL ;
F_456 ( V_84 -> V_88 ) ;
V_84 -> V_88 = NULL ;
if ( ! V_84 -> V_97 )
return;
F_464 ( V_84 -> V_89 , V_84 -> V_304 ,
V_84 -> V_97 , V_84 -> V_72 ) ;
V_84 -> V_97 = NULL ;
}
static void F_466 ( struct V_1 * V_2 )
{
int V_49 ;
#ifdef F_184
F_467 ( V_2 ) ;
#endif
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ )
if ( V_2 -> V_84 [ V_49 ] -> V_97 )
F_463 ( V_2 -> V_84 [ V_49 ] ) ;
}
static int F_468 ( struct V_76 * V_77 , int V_839 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
if ( ( V_2 -> V_148 & V_457 ) &&
( V_2 -> V_14 . V_118 . type == V_121 ) &&
( V_839 > V_840 ) )
F_27 ( V_190 , L_104 ) ;
F_109 ( V_190 , L_105 , V_77 -> V_333 , V_839 ) ;
V_77 -> V_333 = V_839 ;
if ( F_63 ( V_77 ) )
F_416 ( V_2 ) ;
return 0 ;
}
int F_469 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 , V_401 ;
if ( F_14 ( V_841 , & V_2 -> V_35 ) )
return - V_842 ;
F_434 ( V_77 ) ;
V_17 = F_458 ( V_2 ) ;
if ( V_17 )
goto V_837;
V_17 = F_461 ( V_2 ) ;
if ( V_17 )
goto V_838;
F_404 ( V_2 ) ;
V_17 = F_268 ( V_2 ) ;
if ( V_17 )
goto V_843;
if ( V_2 -> V_712 > 1 )
V_401 = V_2 -> V_703 ;
else
V_401 = V_2 -> V_91 ;
V_17 = F_397 ( V_77 , V_401 ) ;
if ( V_17 )
goto V_844;
if ( V_2 -> V_712 > 1 &&
V_2 -> V_104 > V_845 )
V_401 = V_845 ;
else
V_401 = V_2 -> V_104 ;
V_17 = F_398 ( V_77 , V_401 ) ;
if ( V_17 )
goto V_844;
F_470 ( V_2 ) ;
F_414 ( V_2 ) ;
F_362 ( V_2 , V_846 ) ;
F_471 ( V_77 ) ;
return 0 ;
V_844:
F_269 ( V_2 ) ;
V_843:
F_466 ( V_2 ) ;
if ( V_14 -> V_46 . V_373 . V_743 && ! V_2 -> V_760 )
V_14 -> V_46 . V_373 . V_743 ( & V_2 -> V_14 , false ) ;
V_838:
F_465 ( V_2 ) ;
V_837:
F_424 ( V_2 ) ;
return V_17 ;
}
static void F_472 ( struct V_1 * V_2 )
{
F_473 ( V_2 ) ;
if ( V_2 -> V_14 . V_46 . V_373 . V_847 ) {
V_2 -> V_14 . V_46 . V_848 = true ;
F_421 ( V_2 ) ;
V_2 -> V_14 . V_46 . V_373 . V_847 ( & V_2 -> V_14 ) ;
V_2 -> V_14 . V_46 . V_848 = false ;
} else {
F_421 ( V_2 ) ;
}
F_269 ( V_2 ) ;
F_465 ( V_2 ) ;
F_466 ( V_2 ) ;
}
int F_474 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
F_475 ( V_2 ) ;
if ( F_476 ( V_77 ) )
F_472 ( V_2 ) ;
F_431 ( V_2 ) ;
F_73 ( V_2 ) ;
return 0 ;
}
static int F_477 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_478 ( V_9 ) ;
struct V_76 * V_77 = V_2 -> V_77 ;
T_1 V_17 ;
V_2 -> V_14 . V_41 = V_2 -> V_446 ;
F_479 ( V_9 , V_849 ) ;
F_480 ( V_9 ) ;
F_481 ( V_9 ) ;
V_17 = F_482 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_106 ) ;
return V_17 ;
}
F_36 () ;
F_37 ( V_850 , & V_2 -> V_35 ) ;
F_483 ( V_9 ) ;
F_484 ( V_9 , false ) ;
F_424 ( V_2 ) ;
F_74 ( & V_2 -> V_14 , V_851 , ~ 0 ) ;
F_485 () ;
V_17 = F_486 ( V_2 ) ;
if ( ! V_17 && F_63 ( V_77 ) )
V_17 = F_469 ( V_77 ) ;
if ( ! V_17 )
F_487 ( V_77 ) ;
F_488 () ;
return V_17 ;
}
static int F_489 ( struct V_5 * V_9 , bool * V_852 )
{
struct V_1 * V_2 = F_478 ( V_9 ) ;
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_853 , V_637 ;
T_1 V_854 = V_2 -> V_760 ;
#ifdef F_490
int V_855 = 0 ;
#endif
F_485 () ;
F_491 ( V_77 ) ;
if ( F_63 ( V_77 ) )
F_472 ( V_2 ) ;
F_492 ( V_2 ) ;
F_488 () ;
#ifdef F_490
V_855 = F_481 ( V_9 ) ;
if ( V_855 )
return V_855 ;
#endif
if ( V_14 -> V_118 . V_373 . V_856 )
V_14 -> V_118 . V_373 . V_856 ( V_14 ) ;
if ( V_854 ) {
F_355 ( V_77 ) ;
if ( V_14 -> V_118 . V_373 . V_742 )
V_14 -> V_118 . V_373 . V_742 ( V_14 ) ;
if ( V_854 & V_857 ) {
V_637 = F_40 ( V_14 , V_641 ) ;
V_637 |= V_647 ;
F_74 ( V_14 , V_641 , V_637 ) ;
}
V_853 = F_40 ( V_14 , V_858 ) ;
V_853 |= V_859 ;
F_74 ( V_14 , V_858 , V_853 ) ;
F_74 ( V_14 , V_860 , V_854 ) ;
} else {
F_74 ( V_14 , V_861 , 0 ) ;
F_74 ( V_14 , V_860 , 0 ) ;
}
switch ( V_14 -> V_118 . type ) {
case V_119 :
F_484 ( V_9 , false ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
F_484 ( V_9 , ! ! V_854 ) ;
break;
default:
break;
}
* V_852 = ! ! V_854 ;
if ( V_14 -> V_46 . V_373 . V_743 && ! * V_852 )
V_14 -> V_46 . V_373 . V_743 ( V_14 , false ) ;
F_73 ( V_2 ) ;
if ( ! F_15 ( V_850 , & V_2 -> V_35 ) )
F_493 ( V_9 ) ;
return 0 ;
}
static int F_494 ( struct V_5 * V_9 , T_13 V_35 )
{
int V_855 ;
bool V_862 ;
V_855 = F_489 ( V_9 , & V_862 ) ;
if ( V_855 )
return V_855 ;
if ( V_862 ) {
F_495 ( V_9 ) ;
} else {
F_484 ( V_9 , false ) ;
F_479 ( V_9 , V_863 ) ;
}
return 0 ;
}
static void F_496 ( struct V_5 * V_9 )
{
bool V_862 ;
F_489 ( V_9 , & V_862 ) ;
if ( V_864 == V_865 ) {
F_484 ( V_9 , V_862 ) ;
F_479 ( V_9 , V_863 ) ;
}
}
void F_497 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_131 * V_132 = & V_2 -> V_133 ;
V_71 V_866 = 0 ;
T_1 V_49 , V_867 = 0 , V_868 , V_869 , V_870 , V_871 , V_872 ;
V_71 V_287 = 0 , V_192 = 0 , V_873 = 0 ;
V_71 V_254 = 0 , V_332 = 0 ;
V_71 V_188 = 0 , V_153 = 0 , V_874 = 0 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_749 , & V_2 -> V_35 ) )
return;
if ( V_2 -> V_368 & V_574 ) {
V_71 V_268 = 0 ;
V_71 V_269 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
V_268 += V_2 -> V_84 [ V_49 ] -> V_240 . V_268 ;
V_269 += V_2 -> V_84 [ V_49 ] -> V_240 . V_269 ;
}
V_2 -> V_875 = V_268 ;
V_2 -> V_876 = V_269 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
struct V_63 * V_84 = V_2 -> V_84 [ V_49 ] ;
V_287 += V_84 -> V_240 . V_287 ;
V_254 += V_84 -> V_240 . V_254 ;
V_332 += V_84 -> V_240 . V_332 ;
V_874 += V_84 -> V_240 . V_241 ;
V_188 += V_84 -> V_133 . V_188 ;
V_153 += V_84 -> V_133 . V_153 ;
}
V_2 -> V_287 = V_287 ;
V_2 -> V_254 = V_254 ;
V_2 -> V_332 = V_332 ;
V_2 -> V_874 = V_874 ;
V_77 -> V_133 . V_877 = V_188 ;
V_77 -> V_133 . V_878 = V_153 ;
V_188 = 0 ;
V_153 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ ) {
struct V_63 * V_92 = V_2 -> V_92 [ V_49 ] ;
V_192 += V_92 -> V_161 . V_192 ;
V_873 += V_92 -> V_161 . V_873 ;
V_188 += V_92 -> V_133 . V_188 ;
V_153 += V_92 -> V_133 . V_153 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ ) {
struct V_63 * V_94 = V_2 -> V_94 [ V_49 ] ;
V_192 += V_94 -> V_161 . V_192 ;
V_873 += V_94 -> V_161 . V_873 ;
V_188 += V_94 -> V_133 . V_188 ;
V_153 += V_94 -> V_133 . V_153 ;
}
V_2 -> V_192 = V_192 ;
V_2 -> V_873 = V_873 ;
V_77 -> V_133 . V_879 = V_188 ;
V_77 -> V_133 . V_880 = V_153 ;
V_132 -> V_881 += F_40 ( V_14 , V_882 ) ;
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
V_868 = F_40 ( V_14 , F_498 ( V_49 ) ) ;
V_867 += V_868 ;
V_132 -> V_868 [ V_49 ] += V_868 ;
V_866 += V_132 -> V_868 [ V_49 ] ;
V_132 -> V_883 [ V_49 ] += F_40 ( V_14 , F_499 ( V_49 ) ) ;
V_132 -> V_884 [ V_49 ] += F_40 ( V_14 , F_500 ( V_49 ) ) ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_132 -> V_885 [ V_49 ] += F_40 ( V_14 , F_501 ( V_49 ) ) ;
V_132 -> V_886 [ V_49 ] += F_40 ( V_14 , F_502 ( V_49 ) ) ;
V_132 -> V_887 [ V_49 ] += F_40 ( V_14 , F_503 ( V_49 ) ) ;
V_132 -> V_888 [ V_49 ] +=
F_40 ( V_14 , F_504 ( V_49 ) ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_132 -> V_888 [ V_49 ] +=
F_40 ( V_14 , F_505 ( V_49 ) ) ;
break;
default:
break;
}
}
for ( V_49 = 0 ; V_49 < 16 ; V_49 ++ ) {
V_132 -> V_889 [ V_49 ] += F_40 ( V_14 , F_506 ( V_49 ) ) ;
V_132 -> V_890 [ V_49 ] += F_40 ( V_14 , F_507 ( V_49 ) ) ;
if ( ( V_14 -> V_118 . type == V_121 ) ||
( V_14 -> V_118 . type == V_122 ) ||
( V_14 -> V_118 . type == V_123 ) ||
( V_14 -> V_118 . type == V_124 ) ||
( V_14 -> V_118 . type == V_125 ) ) {
V_132 -> V_886 [ V_49 ] += F_40 ( V_14 , F_508 ( V_49 ) ) ;
F_40 ( V_14 , F_509 ( V_49 ) ) ;
V_132 -> V_887 [ V_49 ] += F_40 ( V_14 , F_510 ( V_49 ) ) ;
F_40 ( V_14 , F_511 ( V_49 ) ) ;
}
}
V_132 -> V_891 += F_40 ( V_14 , V_892 ) ;
V_132 -> V_891 -= V_867 ;
F_81 ( V_2 ) ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_132 -> V_893 += F_40 ( V_14 , V_894 ) ;
V_132 -> V_895 += F_40 ( V_14 , V_896 ) ;
V_132 -> V_897 += F_40 ( V_14 , V_898 ) ;
V_132 -> V_899 += F_40 ( V_14 , V_900 ) ;
break;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_132 -> V_901 += F_40 ( V_14 , V_902 ) ;
V_132 -> V_903 += F_40 ( V_14 , V_904 ) ;
V_132 -> V_905 += F_40 ( V_14 , V_906 ) ;
V_132 -> V_907 += F_40 ( V_14 , V_908 ) ;
case V_121 :
for ( V_49 = 0 ; V_49 < 16 ; V_49 ++ )
V_2 -> V_909 +=
F_40 ( V_14 , F_512 ( V_49 ) ) ;
V_132 -> V_895 += F_40 ( V_14 , V_910 ) ;
F_40 ( V_14 , V_896 ) ;
V_132 -> V_897 += F_40 ( V_14 , V_911 ) ;
F_40 ( V_14 , V_898 ) ;
V_132 -> V_899 += F_40 ( V_14 , V_912 ) ;
F_40 ( V_14 , V_900 ) ;
V_132 -> V_893 += F_40 ( V_14 , V_913 ) ;
V_132 -> V_914 += F_40 ( V_14 , V_915 ) ;
V_132 -> V_916 += F_40 ( V_14 , V_917 ) ;
#ifdef F_184
V_132 -> V_918 += F_40 ( V_14 , V_919 ) ;
V_132 -> V_920 += F_40 ( V_14 , V_921 ) ;
V_132 -> V_922 += F_40 ( V_14 , V_923 ) ;
V_132 -> V_924 += F_40 ( V_14 , V_925 ) ;
V_132 -> V_926 += F_40 ( V_14 , V_927 ) ;
V_132 -> V_928 += F_40 ( V_14 , V_929 ) ;
if ( V_2 -> V_680 . V_930 ) {
struct V_931 * V_680 = & V_2 -> V_680 ;
struct V_932 * V_930 ;
unsigned int V_193 ;
V_71 V_933 = 0 , V_934 = 0 ;
F_513 (cpu) {
V_930 = F_514 ( V_680 -> V_930 , V_193 ) ;
V_933 += V_930 -> V_933 ;
V_934 += V_930 -> V_934 ;
}
V_132 -> V_935 = V_933 ;
V_132 -> V_936 = V_934 ;
}
#endif
break;
default:
break;
}
V_869 = F_40 ( V_14 , V_937 ) ;
V_132 -> V_869 += V_869 ;
V_132 -> V_938 += F_40 ( V_14 , V_939 ) ;
if ( V_14 -> V_118 . type == V_119 )
V_132 -> V_938 -= V_869 ;
V_132 -> V_940 += F_40 ( V_14 , V_941 ) ;
V_132 -> V_942 += F_40 ( V_14 , V_943 ) ;
V_132 -> V_944 += F_40 ( V_14 , V_945 ) ;
V_132 -> V_946 += F_40 ( V_14 , V_947 ) ;
V_132 -> V_948 += F_40 ( V_14 , V_949 ) ;
V_132 -> V_950 += F_40 ( V_14 , V_951 ) ;
V_132 -> V_952 += F_40 ( V_14 , V_953 ) ;
V_132 -> V_954 += F_40 ( V_14 , V_955 ) ;
V_870 = F_40 ( V_14 , V_956 ) ;
V_132 -> V_957 += V_870 ;
V_871 = F_40 ( V_14 , V_958 ) ;
V_132 -> V_959 += V_871 ;
V_132 -> V_960 += F_40 ( V_14 , V_961 ) ;
V_132 -> V_962 += F_40 ( V_14 , V_963 ) ;
V_872 = V_870 + V_871 ;
V_132 -> V_960 -= V_872 ;
V_132 -> V_962 -= V_872 ;
V_132 -> V_897 -= ( V_872 * ( V_964 + V_562 ) ) ;
V_132 -> V_965 += F_40 ( V_14 , V_966 ) ;
V_132 -> V_967 += F_40 ( V_14 , V_968 ) ;
V_132 -> V_969 += F_40 ( V_14 , V_970 ) ;
V_132 -> V_971 += F_40 ( V_14 , V_972 ) ;
V_132 -> V_973 += F_40 ( V_14 , V_974 ) ;
V_132 -> V_973 -= V_872 ;
V_132 -> V_975 += F_40 ( V_14 , V_976 ) ;
V_132 -> V_977 += F_40 ( V_14 , V_978 ) ;
V_132 -> V_979 += F_40 ( V_14 , V_980 ) ;
V_132 -> V_981 += F_40 ( V_14 , V_982 ) ;
V_132 -> V_983 += F_40 ( V_14 , V_984 ) ;
V_132 -> V_985 += F_40 ( V_14 , V_986 ) ;
V_77 -> V_133 . V_987 = V_132 -> V_938 ;
V_77 -> V_133 . V_988 = V_132 -> V_881 + V_132 -> V_954 ;
V_77 -> V_133 . V_989 = 0 ;
V_77 -> V_133 . V_990 = V_132 -> V_954 ;
V_77 -> V_133 . V_991 = V_132 -> V_881 ;
V_77 -> V_133 . V_992 = V_866 ;
}
static void F_515 ( struct V_1 * V_2 )
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
V_2 -> V_993 ++ ;
if ( F_516 ( V_14 ) == 0 ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ )
F_91 ( V_419 ,
& ( V_2 -> V_92 [ V_49 ] -> V_35 ) ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ )
F_91 ( V_419 ,
& V_2 -> V_94 [ V_49 ] -> V_35 ) ;
F_74 ( V_14 , V_400 , V_411 ) ;
} else {
F_107 ( V_190 , L_107
L_108 ) ;
}
}
static void F_517 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_71 V_994 = 0 ;
int V_49 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_749 , & V_2 -> V_35 ) )
return;
if ( F_113 ( V_2 -> V_77 ) ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ )
F_518 ( V_2 -> V_92 [ V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ )
F_518 ( V_2 -> V_94 [ V_49 ] ) ;
}
if ( ! ( V_2 -> V_148 & V_437 ) ) {
F_74 ( V_14 , V_130 ,
( V_995 | V_996 ) ) ;
} else {
for ( V_49 = 0 ; V_49 < V_2 -> V_210 ; V_49 ++ ) {
struct V_173 * V_997 = V_2 -> V_174 [ V_49 ] ;
if ( V_997 -> V_337 . V_64 || V_997 -> V_179 . V_64 )
V_994 |= F_259 ( V_49 ) ;
}
}
F_78 ( V_2 , V_994 ) ;
}
static void F_519 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_998 = V_2 -> V_998 ;
bool V_375 = V_2 -> V_375 ;
bool V_144 = V_2 -> V_145 . V_146 ;
if ( ! ( V_2 -> V_148 & V_397 ) )
return;
if ( V_14 -> V_118 . V_373 . V_374 ) {
V_14 -> V_118 . V_373 . V_374 ( V_14 , & V_998 , & V_375 , false ) ;
} else {
V_998 = V_999 ;
V_375 = true ;
}
if ( V_2 -> V_147 )
V_144 |= ! ! ( V_2 -> V_147 -> V_144 ) ;
if ( V_375 && ! ( ( V_2 -> V_148 & V_149 ) && V_144 ) ) {
V_14 -> V_118 . V_373 . V_1000 ( V_14 ) ;
F_520 ( V_2 ) ;
}
if ( V_375 ||
F_521 ( V_189 , ( V_2 -> V_398 +
V_1001 ) ) ) {
V_2 -> V_148 &= ~ V_397 ;
F_74 ( V_14 , V_400 , V_399 ) ;
F_240 ( V_14 ) ;
}
V_2 -> V_375 = V_375 ;
V_2 -> V_998 = V_998 ;
}
static void F_522 ( struct V_1 * V_2 )
{
#ifdef F_405
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_1002 V_1003 = {
. V_1004 = V_1005 ,
. V_276 = 0 ,
} ;
T_4 V_681 = 0 ;
if ( V_2 -> V_666 & V_1006 )
V_681 = F_523 ( V_77 , & V_1003 ) ;
V_2 -> V_1007 = ( V_681 > 1 ) ? ( F_524 ( V_681 ) - 1 ) : 0 ;
#endif
}
static int F_525 ( struct V_76 * V_106 , void * V_103 )
{
if ( F_401 ( V_106 ) ) {
struct V_715 * V_274 = F_87 ( V_106 ) ;
if ( V_274 -> V_717 )
F_526 ( V_106 ) ;
}
return 0 ;
}
static void F_527 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_998 = V_2 -> V_998 ;
const char * V_1008 ;
bool V_1009 , V_1010 ;
if ( F_113 ( V_77 ) )
return;
V_2 -> V_368 &= ~ V_720 ;
switch ( V_14 -> V_118 . type ) {
case V_119 : {
T_1 V_1011 = F_40 ( V_14 , V_641 ) ;
T_1 V_1012 = F_40 ( V_14 , V_1013 ) ;
V_1009 = ! ! ( V_1011 & V_1014 ) ;
V_1010 = ! ! ( V_1012 & V_1015 ) ;
}
break;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_121 : {
T_1 V_1016 = F_40 ( V_14 , V_1017 ) ;
T_1 V_1018 = F_40 ( V_14 , V_1019 ) ;
V_1009 = ! ! ( V_1016 & V_1020 ) ;
V_1010 = ! ! ( V_1018 & V_1021 ) ;
}
break;
default:
V_1010 = false ;
V_1009 = false ;
break;
}
V_2 -> V_1022 = V_189 ;
if ( F_14 ( V_759 , & V_2 -> V_35 ) )
F_528 ( V_2 ) ;
switch ( V_998 ) {
case V_999 :
V_1008 = L_109 ;
break;
case V_1023 :
V_1008 = L_110 ;
break;
case V_1024 :
V_1008 = L_111 ;
break;
case V_1025 :
V_1008 = L_112 ;
break;
case V_1026 :
V_1008 = L_113 ;
break;
default:
V_1008 = L_114 ;
break;
}
F_109 ( V_164 , L_115 , V_1008 ,
( ( V_1009 && V_1010 ) ? L_116 :
( V_1009 ? L_117 :
( V_1010 ? L_118 : L_119 ) ) ) ) ;
F_529 ( V_77 ) ;
F_530 ( V_2 ) ;
F_526 ( V_2 -> V_77 ) ;
F_485 () ;
F_403 ( V_2 -> V_77 ,
F_525 , NULL ) ;
F_488 () ;
F_522 ( V_2 ) ;
F_437 ( V_2 ) ;
}
static void F_420 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_375 = false ;
V_2 -> V_998 = 0 ;
if ( ! F_113 ( V_77 ) )
return;
if ( F_236 ( V_14 ) && V_14 -> V_118 . type == V_119 )
V_2 -> V_368 |= V_720 ;
if ( F_14 ( V_759 , & V_2 -> V_35 ) )
F_528 ( V_2 ) ;
F_109 ( V_164 , L_120 ) ;
F_434 ( V_77 ) ;
F_437 ( V_2 ) ;
}
static bool F_531 ( struct V_1 * V_2 )
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
static bool F_532 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1027 * V_1028 = & V_2 -> V_462 [ V_463 ] ;
T_1 V_1029 = F_533 ( 1 , ~ V_1028 -> V_128 ) ;
int V_49 , V_60 ;
if ( ! V_2 -> V_339 )
return false ;
if ( V_14 -> V_118 . type >= V_123 )
return false ;
for ( V_49 = 0 ; V_49 < V_2 -> V_339 ; V_49 ++ ) {
for ( V_60 = 0 ; V_60 < V_1029 ; V_60 ++ ) {
T_1 V_1030 , V_1031 ;
V_1030 = F_40 ( V_14 , F_534 ( V_1029 , V_49 , V_60 ) ) ;
V_1031 = F_40 ( V_14 , F_535 ( V_1029 , V_49 , V_60 ) ) ;
if ( V_1030 != V_1031 )
return true ;
}
}
return false ;
}
static void F_536 ( struct V_1 * V_2 )
{
if ( ! F_113 ( V_2 -> V_77 ) ) {
if ( F_531 ( V_2 ) ||
F_532 ( V_2 ) ) {
F_27 ( V_164 , L_121 ) ;
F_91 ( V_163 , & V_2 -> V_35 ) ;
}
}
}
static void F_537 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_1032 ;
T_1 V_1033 ;
if ( ! ( F_113 ( V_2 -> V_77 ) ) )
return;
V_1033 = F_40 ( V_14 , V_1034 ) ;
if ( V_1033 )
return;
if ( ! V_9 )
return;
for ( V_1032 = 0 ; V_1032 < V_2 -> V_339 ; ++ V_1032 ) {
struct V_5 * V_1035 = V_2 -> V_557 [ V_1032 ] . V_1035 ;
T_2 V_1036 ;
if ( ! V_1035 )
continue;
F_28 ( V_1035 , V_1037 , & V_1036 ) ;
if ( V_1036 != V_13 &&
V_1036 & V_1038 )
F_538 ( V_1035 ) ;
}
}
static void F_539 ( struct V_1 * V_2 )
{
T_1 V_1039 ;
if ( V_2 -> V_14 . V_118 . type == V_119 ||
V_2 -> V_339 == 0 )
return;
V_1039 = F_40 ( & V_2 -> V_14 , V_1040 ) ;
if ( ! V_1039 )
return;
F_27 ( V_164 , L_122 , V_1039 ) ;
}
static void F_539 ( struct V_1 T_14 * V_2 )
{
}
static void
F_537 ( struct V_1 T_14 * V_2 )
{
}
static void F_540 ( struct V_1 * V_2 )
{
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_749 , & V_2 -> V_35 ) )
return;
F_519 ( V_2 ) ;
if ( V_2 -> V_375 )
F_527 ( V_2 ) ;
else
F_420 ( V_2 ) ;
F_537 ( V_2 ) ;
F_539 ( V_2 ) ;
F_497 ( V_2 ) ;
F_536 ( V_2 ) ;
}
static void F_541 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_3 V_17 ;
if ( ! ( V_2 -> V_368 & V_720 ) &&
! ( V_2 -> V_368 & V_393 ) )
return;
if ( V_2 -> V_394 &&
F_521 ( V_2 -> V_394 , V_189 ) )
return;
if ( F_15 ( V_751 , & V_2 -> V_35 ) )
return;
V_2 -> V_394 = V_189 + V_1041 - 1 ;
V_17 = V_14 -> V_46 . V_373 . V_1042 ( V_14 ) ;
if ( V_17 == V_754 )
goto V_1043;
if ( V_17 == V_753 ) {
V_2 -> V_368 |= V_393 ;
}
if ( V_17 )
goto V_1043;
if ( ! ( V_2 -> V_368 & V_393 ) )
goto V_1043;
V_2 -> V_368 &= ~ V_393 ;
if ( V_14 -> V_118 . type == V_119 )
V_17 = V_14 -> V_46 . V_373 . V_1044 ( V_14 ) ;
else
V_17 = V_14 -> V_118 . V_373 . V_1045 ( V_14 ) ;
if ( V_17 == V_754 )
goto V_1043;
V_2 -> V_148 |= V_395 ;
F_109 ( V_190 , L_123 , V_14 -> V_46 . V_1046 ) ;
V_1043:
F_37 ( V_751 , & V_2 -> V_35 ) ;
if ( ( V_17 == V_754 ) &&
( V_2 -> V_77 -> V_1047 == V_1048 ) ) {
F_18 ( L_124
L_125 ) ;
F_18 ( L_126
L_127 ) ;
F_542 ( V_2 -> V_77 ) ;
}
}
static void F_543 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_20 ;
bool V_721 = false ;
if ( ! ( V_2 -> V_148 & V_395 ) )
return;
if ( F_15 ( V_751 , & V_2 -> V_35 ) )
return;
V_2 -> V_148 &= ~ V_395 ;
V_20 = V_14 -> V_46 . V_723 ;
if ( ( ! V_20 ) && ( V_14 -> V_118 . V_373 . V_724 ) ) {
V_14 -> V_118 . V_373 . V_724 ( V_14 , & V_20 , & V_721 ) ;
if ( ! V_721 ) {
if ( V_20 & V_999 )
V_20 = V_999 ;
}
}
if ( V_14 -> V_118 . V_373 . V_725 )
V_14 -> V_118 . V_373 . V_725 ( V_14 , V_20 , true ) ;
V_2 -> V_148 |= V_397 ;
V_2 -> V_398 = V_189 ;
F_37 ( V_751 , & V_2 -> V_35 ) ;
}
static void F_544 ( unsigned long V_103 )
{
struct V_1 * V_2 = (struct V_1 * ) V_103 ;
unsigned long V_1049 ;
if ( V_2 -> V_148 & V_397 )
V_1049 = V_1050 / 10 ;
else
V_1049 = V_1050 * 2 ;
F_415 ( & V_2 -> V_747 , V_1049 + V_189 ) ;
F_13 ( V_2 ) ;
}
static void F_545 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_182 ;
if ( ! ( V_2 -> V_368 & V_414 ) )
return;
V_2 -> V_368 &= ~ V_414 ;
if ( ! V_14 -> V_46 . V_373 . V_1051 )
return;
V_182 = V_14 -> V_46 . V_373 . V_1051 ( & V_2 -> V_14 ) ;
if ( V_182 != V_377 )
return;
F_232 ( V_164 , L_69 , V_380 ) ;
}
static void F_546 ( struct V_1 * V_2 )
{
if ( ! F_251 ( V_163 , & V_2 -> V_35 ) )
return;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_749 , & V_2 -> V_35 ) )
return;
F_59 ( V_2 ) ;
F_547 ( V_2 -> V_77 , L_128 ) ;
V_2 -> V_191 ++ ;
F_485 () ;
F_416 ( V_2 ) ;
F_488 () ;
}
static void F_548 ( struct V_1052 * V_1053 )
{
struct V_1 * V_2 = F_256 ( V_1053 ,
struct V_1 ,
V_39 ) ;
if ( F_22 ( V_2 -> V_14 . V_41 ) ) {
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_485 () ;
F_421 ( V_2 ) ;
F_488 () ;
}
F_34 ( V_2 ) ;
return;
}
if ( V_2 -> V_368 & V_1054 ) {
F_485 () ;
V_2 -> V_368 &= ~ V_1054 ;
F_471 ( V_2 -> V_77 ) ;
F_488 () ;
}
F_546 ( V_2 ) ;
F_545 ( V_2 ) ;
F_541 ( V_2 ) ;
F_543 ( V_2 ) ;
F_230 ( V_2 ) ;
F_540 ( V_2 ) ;
F_515 ( V_2 ) ;
F_517 ( V_2 ) ;
if ( F_14 ( V_759 , & V_2 -> V_35 ) ) {
F_549 ( V_2 ) ;
F_550 ( V_2 ) ;
F_551 ( V_2 ) ;
}
F_34 ( V_2 ) ;
}
static int F_552 ( struct V_63 * V_92 ,
struct V_66 * V_1055 ,
T_4 * V_263 )
{
T_1 V_1056 , V_1057 , V_1058 ;
struct V_216 * V_100 = V_1055 -> V_100 ;
union {
struct V_1059 * V_1060 ;
struct V_1061 * V_1062 ;
unsigned char * V_1063 ;
} V_1064 ;
union {
struct V_1065 * V_1066 ;
unsigned char * V_1063 ;
} V_1067 ;
T_1 V_1068 , V_1069 ;
int V_17 ;
if ( V_100 -> V_246 != V_1070 )
return 0 ;
if ( ! F_553 ( V_100 ) )
return 0 ;
V_17 = F_554 ( V_100 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( F_555 ( V_1055 -> V_276 ) )
V_1064 . V_1063 = F_556 ( V_100 ) ;
else
V_1064 . V_1063 = F_557 ( V_100 ) ;
V_1067 . V_1063 = F_558 ( V_100 ) ;
V_1057 = V_1071 ;
if ( V_1064 . V_1060 -> V_1072 == 4 ) {
unsigned char * V_1073 = F_558 ( V_100 ) ;
unsigned char * V_1074 = V_1064 . V_1063 + ( V_1064 . V_1060 -> V_1075 * 4 ) ;
V_1064 . V_1060 -> V_1076 = F_559 ( F_560 ( V_1074 ,
V_1073 - V_1074 ,
0 ) ) ;
V_1057 |= V_1077 ;
V_1064 . V_1060 -> V_1078 = 0 ;
V_1055 -> V_1079 |= V_1080 |
V_1081 |
V_1082 ;
} else {
V_1064 . V_1062 -> V_1083 = 0 ;
V_1055 -> V_1079 |= V_1080 |
V_1081 ;
}
V_1069 = V_1067 . V_1063 - V_100 -> V_103 ;
* V_263 = ( V_1067 . V_1066 -> V_1084 * 4 ) + V_1069 ;
V_1068 = V_100 -> V_73 - V_1069 ;
F_561 ( & V_1067 . V_1066 -> V_1076 , F_562 ( V_1068 ) ) ;
V_1055 -> V_185 = F_157 ( V_100 ) -> V_185 ;
V_1055 -> V_184 += ( V_1055 -> V_185 - 1 ) * * V_263 ;
V_1058 = ( * V_263 - V_1069 ) << V_1085 ;
V_1058 |= F_157 ( V_100 ) -> V_264 << V_1086 ;
V_1056 = V_1067 . V_1063 - V_1064 . V_1063 ;
V_1056 |= ( V_1064 . V_1063 - V_100 -> V_103 ) << V_1087 ;
V_1056 |= V_1055 -> V_1079 & V_1088 ;
F_563 ( V_92 , V_1056 , 0 , V_1057 ,
V_1058 ) ;
return 1 ;
}
static inline bool F_564 ( struct V_216 * V_100 )
{
unsigned int V_1089 = 0 ;
F_565 ( V_100 , & V_1089 , V_1090 , NULL , NULL ) ;
return V_1089 == F_566 ( V_100 ) ;
}
static void F_567 ( struct V_63 * V_92 ,
struct V_66 * V_1055 )
{
struct V_216 * V_100 = V_1055 -> V_100 ;
T_1 V_1056 = 0 ;
T_1 V_1057 = 0 ;
if ( V_100 -> V_246 != V_1070 ) {
V_1091:
if ( ! ( V_1055 -> V_1079 & ( V_1092 |
V_1093 ) ) )
return;
goto V_1094;
}
switch ( V_100 -> V_1095 ) {
case F_568 ( struct V_1065 , V_1076 ) :
V_1057 = V_1071 ;
case F_568 ( struct V_1096 , V_1076 ) :
break;
case F_568 ( struct V_1097 , V_1098 ) :
if ( ( ( V_1055 -> V_276 == F_164 ( V_1099 ) ) &&
( F_569 ( V_100 ) -> V_276 == V_1090 ) ) ||
( ( V_1055 -> V_276 == F_164 ( V_1100 ) ) &&
F_564 ( V_100 ) ) ) {
V_1057 = V_1101 ;
break;
}
default:
F_570 ( V_100 ) ;
goto V_1091;
}
V_1055 -> V_1079 |= V_1081 ;
V_1056 = F_566 ( V_100 ) -
F_571 ( V_100 ) ;
V_1094:
V_1056 |= F_571 ( V_100 ) << V_1087 ;
V_1056 |= V_1055 -> V_1079 & V_1088 ;
F_563 ( V_92 , V_1056 , 0 , V_1057 , 0 ) ;
}
static T_1 F_572 ( struct V_216 * V_100 , T_1 V_1079 )
{
T_1 V_1102 = V_1103 |
V_1104 |
V_1105 ;
V_1102 |= F_573 ( V_1079 , V_1092 ,
V_1106 ) ;
V_1102 |= F_573 ( V_1079 , V_1080 ,
V_1107 ) ;
V_1102 |= F_573 ( V_1079 , V_1108 ,
V_1109 ) ;
V_1102 ^= F_573 ( V_100 -> V_1110 , 1 , V_1105 ) ;
return V_1102 ;
}
static void F_574 ( union V_78 * V_79 ,
T_1 V_1079 , unsigned int V_1068 )
{
T_1 V_1111 = V_1068 << V_1112 ;
V_1111 |= F_573 ( V_1079 ,
V_1081 ,
V_1113 ) ;
V_1111 |= F_573 ( V_1079 ,
V_1082 ,
V_1114 ) ;
V_1111 |= F_573 ( V_1079 ,
V_1093 ,
V_1115 ) ;
V_79 -> V_260 . V_1111 = F_96 ( V_1111 ) ;
}
static int F_575 ( struct V_63 * V_92 , T_2 V_304 )
{
F_108 ( V_92 -> V_77 , V_92 -> V_96 ) ;
F_115 () ;
if ( F_25 ( F_114 ( V_92 ) < V_304 ) )
return - V_842 ;
F_576 ( V_92 -> V_77 , V_92 -> V_96 ) ;
++ V_92 -> V_161 . V_192 ;
return 0 ;
}
static inline int F_577 ( struct V_63 * V_92 , T_2 V_304 )
{
if ( F_25 ( F_114 ( V_92 ) >= V_304 ) )
return 0 ;
return F_575 ( V_92 , V_304 ) ;
}
static int F_578 ( struct V_63 * V_92 ,
struct V_66 * V_1055 ,
const T_4 V_263 )
{
struct V_216 * V_100 = V_1055 -> V_100 ;
struct V_66 * V_67 ;
union V_78 * V_79 ;
struct V_288 * V_289 ;
T_8 V_72 ;
unsigned int V_294 , V_304 ;
T_1 V_1079 = V_1055 -> V_1079 ;
T_1 V_1102 = F_572 ( V_100 , V_1079 ) ;
T_2 V_49 = V_92 -> V_70 ;
V_79 = F_65 ( V_92 , V_49 ) ;
F_574 ( V_79 , V_1079 , V_100 -> V_73 - V_263 ) ;
V_304 = F_156 ( V_100 ) ;
V_294 = V_100 -> V_294 ;
#ifdef F_184
if ( V_1079 & V_1116 ) {
if ( V_294 < sizeof( struct V_336 ) ) {
V_304 -= sizeof( struct V_336 ) - V_294 ;
V_294 = 0 ;
} else {
V_294 -= sizeof( struct V_336 ) ;
}
}
#endif
V_72 = F_579 ( V_92 -> V_89 , V_100 -> V_103 , V_304 , V_186 ) ;
V_67 = V_1055 ;
for ( V_289 = & F_157 ( V_100 ) -> V_290 [ 0 ] ; ; V_289 ++ ) {
if ( F_148 ( V_92 -> V_89 , V_72 ) )
goto V_1117;
F_101 ( V_67 , V_73 , V_304 ) ;
F_580 ( V_67 , V_72 , V_72 ) ;
V_79 -> V_260 . V_1118 = F_152 ( V_72 ) ;
while ( F_23 ( V_304 > V_1119 ) ) {
V_79 -> V_260 . V_1120 =
F_96 ( V_1102 ^ V_1119 ) ;
V_49 ++ ;
V_79 ++ ;
if ( V_49 == V_92 -> V_98 ) {
V_79 = F_65 ( V_92 , 0 ) ;
V_49 = 0 ;
}
V_79 -> V_260 . V_1111 = 0 ;
V_72 += V_1119 ;
V_304 -= V_1119 ;
V_79 -> V_260 . V_1118 = F_152 ( V_72 ) ;
}
if ( F_25 ( ! V_294 ) )
break;
V_79 -> V_260 . V_1120 = F_96 ( V_1102 ^ V_304 ) ;
V_49 ++ ;
V_79 ++ ;
if ( V_49 == V_92 -> V_98 ) {
V_79 = F_65 ( V_92 , 0 ) ;
V_49 = 0 ;
}
V_79 -> V_260 . V_1111 = 0 ;
#ifdef F_184
V_304 = F_353 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_304 = F_180 ( V_289 ) ;
#endif
V_294 -= V_304 ;
V_72 = F_581 ( V_92 -> V_89 , V_289 , 0 , V_304 ,
V_186 ) ;
V_67 = & V_92 -> V_68 [ V_49 ] ;
}
V_1102 |= V_304 | V_1121 ;
V_79 -> V_260 . V_1120 = F_96 ( V_1102 ) ;
F_582 ( F_111 ( V_92 ) , V_1055 -> V_184 ) ;
V_1055 -> V_75 = V_189 ;
F_153 () ;
V_1055 -> V_74 = V_79 ;
V_49 ++ ;
if ( V_49 == V_92 -> V_98 )
V_49 = 0 ;
V_92 -> V_70 = V_49 ;
F_577 ( V_92 , V_1122 ) ;
if ( F_583 ( F_111 ( V_92 ) ) || ! V_100 -> V_1123 ) {
F_154 ( V_49 , V_92 -> V_155 ) ;
F_584 () ;
}
return 0 ;
V_1117:
F_457 ( V_92 -> V_89 , L_129 ) ;
V_67 = & V_92 -> V_68 [ V_49 ] ;
while ( V_67 != V_1055 ) {
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
F_183 ( V_1055 -> V_100 ) ;
V_1055 -> V_100 = NULL ;
V_92 -> V_70 = V_49 ;
return - 1 ;
}
static void F_585 ( struct V_63 * V_64 ,
struct V_66 * V_1055 )
{
struct V_173 * V_174 = V_64 -> V_174 ;
union V_1124 V_1125 = { . V_1126 = 0 } ;
union V_1124 V_1127 = { . V_1126 = 0 } ;
union {
unsigned char * V_1128 ;
struct V_1059 * V_1129 ;
struct V_1061 * V_1130 ;
} V_1063 ;
struct V_1065 * V_1131 ;
unsigned int V_1132 ;
struct V_216 * V_100 ;
T_11 V_1133 ;
int V_1134 ;
if ( ! V_174 )
return;
if ( ! V_64 -> V_447 )
return;
V_64 -> V_448 ++ ;
if ( ( V_1055 -> V_276 != F_164 ( V_1099 ) ) &&
( V_1055 -> V_276 != F_164 ( V_1100 ) ) )
return;
V_100 = V_1055 -> V_100 ;
V_1063 . V_1128 = F_557 ( V_100 ) ;
if ( F_23 ( V_1063 . V_1128 <= V_100 -> V_103 ) )
return;
if ( V_100 -> V_237 &&
V_1055 -> V_276 == F_164 ( V_1099 ) &&
V_1063 . V_1129 -> V_276 == V_1135 ) {
struct V_1 * V_2 = V_174 -> V_2 ;
if ( F_23 ( F_586 ( V_100 ) < V_1063 . V_1128 +
V_1136 ) )
return;
if ( V_2 -> V_662 &&
F_587 ( V_100 ) -> V_1137 == V_2 -> V_662 )
V_1063 . V_1128 = F_556 ( V_100 ) ;
if ( V_2 -> V_664 &&
F_587 ( V_100 ) -> V_1137 == V_2 -> V_664 )
V_1063 . V_1128 = F_556 ( V_100 ) ;
}
if ( F_23 ( F_586 ( V_100 ) < V_1063 . V_1128 + 40 ) )
return;
switch ( V_1063 . V_1129 -> V_1072 ) {
case V_1138 :
V_1132 = ( V_1063 . V_1128 [ 0 ] & 0x0F ) << 2 ;
V_1134 = V_1063 . V_1129 -> V_276 ;
break;
case 6 :
V_1132 = V_1063 . V_1128 - V_100 -> V_103 ;
V_1134 = F_565 ( V_100 , & V_1132 , V_1139 , NULL , NULL ) ;
V_1132 -= V_1063 . V_1128 - V_100 -> V_103 ;
break;
default:
return;
}
if ( V_1134 != V_1139 )
return;
if ( F_23 ( F_586 ( V_100 ) < V_1063 . V_1128 +
V_1132 + sizeof( struct V_1065 ) ) )
return;
V_1131 = (struct V_1065 * ) ( V_1063 . V_1128 + V_1132 ) ;
if ( V_1131 -> V_1140 )
return;
if ( ! V_1131 -> V_1141 && ( V_64 -> V_448 < V_64 -> V_447 ) )
return;
V_64 -> V_448 = 0 ;
V_1133 = F_164 ( V_1055 -> V_1079 >> V_1142 ) ;
V_1125 . V_1143 . V_1133 = V_1133 ;
if ( V_1055 -> V_1079 & ( V_1144 | V_1092 ) )
V_1127 . V_1145 . V_1146 ^= V_1131 -> V_1137 ^ F_164 ( V_275 ) ;
else
V_1127 . V_1145 . V_1146 ^= V_1131 -> V_1137 ^ V_1055 -> V_276 ;
V_1127 . V_1145 . V_1147 ^= V_1131 -> V_1148 ;
switch ( V_1063 . V_1129 -> V_1072 ) {
case V_1138 :
V_1125 . V_1143 . V_1149 = V_1150 ;
V_1127 . V_1064 ^= V_1063 . V_1129 -> V_1151 ^ V_1063 . V_1129 -> V_1152 ;
break;
case 6 :
V_1125 . V_1143 . V_1149 = V_1153 ;
V_1127 . V_1064 ^= V_1063 . V_1130 -> V_1151 . V_1154 [ 0 ] ^
V_1063 . V_1130 -> V_1151 . V_1154 [ 1 ] ^
V_1063 . V_1130 -> V_1151 . V_1154 [ 2 ] ^
V_1063 . V_1130 -> V_1151 . V_1154 [ 3 ] ^
V_1063 . V_1130 -> V_1152 . V_1154 [ 0 ] ^
V_1063 . V_1130 -> V_1152 . V_1154 [ 1 ] ^
V_1063 . V_1130 -> V_1152 . V_1154 [ 2 ] ^
V_1063 . V_1130 -> V_1152 . V_1154 [ 3 ] ;
break;
default:
break;
}
if ( V_1063 . V_1128 != F_557 ( V_100 ) )
V_1125 . V_1143 . V_1149 |= V_1155 ;
F_588 ( & V_174 -> V_2 -> V_14 ,
V_1125 , V_1127 , V_64 -> V_96 ) ;
}
static T_2 F_589 ( struct V_76 * V_89 , struct V_216 * V_100 ,
void * V_1156 , T_15 V_1157 )
{
struct V_701 * V_1158 = V_1156 ;
#ifdef F_184
struct V_1 * V_2 ;
struct V_1027 * V_1159 ;
int V_1160 ;
#endif
if ( V_1158 )
return V_100 -> V_1161 + V_1158 -> V_709 ;
#ifdef F_184
switch ( F_590 ( V_100 ) ) {
case F_164 ( V_1162 ) :
case F_164 ( V_1163 ) :
V_2 = F_87 ( V_89 ) ;
if ( V_2 -> V_148 & V_565 )
break;
default:
return V_1157 ( V_89 , V_100 ) ;
}
V_1159 = & V_2 -> V_462 [ V_1164 ] ;
V_1160 = F_591 ( V_100 ) ? F_592 ( V_100 ) :
F_222 () ;
while ( V_1160 >= V_1159 -> V_496 )
V_1160 -= V_1159 -> V_496 ;
return V_1160 + V_1159 -> V_1089 ;
#else
return V_1157 ( V_89 , V_100 ) ;
#endif
}
static int F_212 ( struct V_1 * V_2 ,
struct V_308 * V_309 )
{
struct V_63 * V_64 = V_2 -> V_94 [ F_222 () ] ;
struct V_66 * V_67 ;
union V_78 * V_79 ;
T_1 V_73 , V_1102 ;
T_8 V_72 ;
T_2 V_49 ;
V_73 = V_309 -> V_310 - V_309 -> V_103 ;
if ( F_23 ( ! F_114 ( V_64 ) ) )
return V_324 ;
V_72 = F_579 ( V_64 -> V_89 , V_309 -> V_103 , V_73 , V_186 ) ;
if ( F_148 ( V_64 -> V_89 , V_72 ) )
return V_324 ;
V_67 = & V_64 -> V_68 [ V_64 -> V_70 ] ;
V_67 -> V_184 = V_73 ;
V_67 -> V_185 = 1 ;
V_67 -> V_276 = 0 ;
V_49 = V_64 -> V_70 ;
V_79 = F_65 ( V_64 , V_49 ) ;
F_101 ( V_67 , V_73 , V_73 ) ;
F_580 ( V_67 , V_72 , V_72 ) ;
V_67 -> V_103 = V_309 -> V_103 ;
V_79 -> V_260 . V_1118 = F_152 ( V_72 ) ;
V_1102 = V_1103 |
V_1104 |
V_1105 ;
V_1102 |= V_73 | V_1121 ;
V_79 -> V_260 . V_1120 = F_96 ( V_1102 ) ;
V_79 -> V_260 . V_1111 =
F_96 ( V_73 << V_1112 ) ;
F_593 () ;
V_49 ++ ;
if ( V_49 == V_64 -> V_98 )
V_49 = 0 ;
V_67 -> V_74 = V_79 ;
V_64 -> V_70 = V_49 ;
return V_331 ;
}
T_16 F_594 ( struct V_216 * V_100 ,
struct V_1 * V_2 ,
struct V_63 * V_92 )
{
struct V_66 * V_1055 ;
int V_1165 ;
T_1 V_1079 = 0 ;
unsigned short V_1159 ;
T_2 V_98 = F_595 ( F_156 ( V_100 ) ) ;
T_11 V_276 = V_100 -> V_276 ;
T_4 V_263 = 0 ;
for ( V_1159 = 0 ; V_1159 < F_157 ( V_100 ) -> V_306 ; V_1159 ++ )
V_98 += F_595 ( F_157 ( V_100 ) -> V_290 [ V_1159 ] . V_304 ) ;
if ( F_577 ( V_92 , V_98 + 3 ) ) {
V_92 -> V_161 . V_873 ++ ;
return V_1166 ;
}
V_1055 = & V_92 -> V_68 [ V_92 -> V_70 ] ;
V_1055 -> V_100 = V_100 ;
V_1055 -> V_184 = V_100 -> V_73 ;
V_1055 -> V_185 = 1 ;
if ( F_596 ( V_100 ) ) {
V_1079 |= F_597 ( V_100 ) << V_1142 ;
V_1079 |= V_1092 ;
} else if ( V_276 == F_164 ( V_275 ) ) {
struct V_1167 * V_1168 , V_1169 ;
V_1168 = F_598 ( V_100 , V_561 , sizeof( V_1169 ) , & V_1169 ) ;
if ( ! V_1168 )
goto V_1170;
V_1079 |= F_599 ( V_1168 -> V_1171 ) <<
V_1142 ;
V_1079 |= V_1144 ;
}
V_276 = F_590 ( V_100 ) ;
if ( F_23 ( F_157 ( V_100 ) -> V_1079 & V_1172 ) &&
V_2 -> V_1173 ) {
if ( ! F_600 ( V_1174 ,
& V_2 -> V_35 ) ) {
F_157 ( V_100 ) -> V_1079 |= V_1175 ;
V_1079 |= V_1108 ;
V_2 -> V_1176 = F_601 ( V_100 ) ;
V_2 -> V_1177 = V_189 ;
F_602 ( & V_2 -> V_1178 ) ;
} else {
V_2 -> V_1179 ++ ;
}
}
F_603 ( V_100 ) ;
#ifdef F_335
if ( V_2 -> V_148 & V_457 )
V_1079 |= V_1093 ;
#endif
if ( ( V_2 -> V_148 & V_149 ) &&
( ( V_1079 & ( V_1092 | V_1144 ) ) ||
( V_100 -> V_1180 != V_1181 ) ) ) {
V_1079 &= ~ V_1182 ;
V_1079 |= ( V_100 -> V_1180 & 0x7 ) <<
V_1183 ;
if ( V_1079 & V_1144 ) {
struct V_1184 * V_1168 ;
if ( F_554 ( V_100 , 0 ) )
goto V_1170;
V_1168 = (struct V_1184 * ) V_100 -> V_103 ;
V_1168 -> V_1171 = F_164 ( V_1079 >>
V_1142 ) ;
} else {
V_1079 |= V_1092 ;
}
}
V_1055 -> V_1079 = V_1079 ;
V_1055 -> V_276 = V_276 ;
#ifdef F_184
if ( ( V_276 == F_164 ( V_1162 ) ) &&
( V_92 -> V_77 -> V_218 & ( V_1185 | V_1186 ) ) ) {
V_1165 = F_604 ( V_92 , V_1055 , & V_263 ) ;
if ( V_1165 < 0 )
goto V_1170;
goto V_1187;
}
#endif
V_1165 = F_552 ( V_92 , V_1055 , & V_263 ) ;
if ( V_1165 < 0 )
goto V_1170;
else if ( ! V_1165 )
F_567 ( V_92 , V_1055 ) ;
if ( F_14 ( V_419 , & V_92 -> V_35 ) )
F_585 ( V_92 , V_1055 ) ;
#ifdef F_184
V_1187:
#endif
if ( F_578 ( V_92 , V_1055 , V_263 ) )
goto V_1188;
return V_1189 ;
V_1170:
F_183 ( V_1055 -> V_100 ) ;
V_1055 -> V_100 = NULL ;
V_1188:
if ( F_23 ( V_1079 & V_1108 ) ) {
F_183 ( V_2 -> V_1176 ) ;
V_2 -> V_1176 = NULL ;
F_605 ( & V_2 -> V_1178 ) ;
F_606 ( V_1174 , & V_2 -> V_35 ) ;
}
return V_1189 ;
}
static T_16 F_607 ( struct V_216 * V_100 ,
struct V_76 * V_77 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_63 * V_92 ;
if ( F_608 ( V_100 , 17 ) )
return V_1189 ;
V_92 = V_64 ? V_64 : V_2 -> V_92 [ V_100 -> V_1161 ] ;
return F_594 ( V_100 , V_2 , V_92 ) ;
}
static T_16 F_609 ( struct V_216 * V_100 ,
struct V_76 * V_77 )
{
return F_607 ( V_100 , V_77 , NULL ) ;
}
static int F_610 ( struct V_76 * V_77 , void * V_62 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1190 * V_627 = V_62 ;
if ( ! F_399 ( V_627 -> V_1191 ) )
return - V_1192 ;
memcpy ( V_77 -> V_714 , V_627 -> V_1191 , V_77 -> V_1193 ) ;
memcpy ( V_14 -> V_118 . V_627 , V_627 -> V_1191 , V_77 -> V_1193 ) ;
F_342 ( V_2 ) ;
return 0 ;
}
static int
F_611 ( struct V_76 * V_77 , int V_1194 , int V_1195 , T_2 V_627 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_4 ;
int V_367 ;
if ( V_1194 != V_14 -> V_46 . V_1196 . V_1194 )
return - V_632 ;
V_367 = V_14 -> V_46 . V_373 . V_1197 ( V_14 , V_627 , V_1195 , & V_4 ) ;
if ( ! V_367 )
V_367 = V_4 ;
return V_367 ;
}
static int F_612 ( struct V_76 * V_77 , int V_1194 , int V_1195 ,
T_2 V_627 , T_2 V_4 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_1194 != V_14 -> V_46 . V_1196 . V_1194 )
return - V_632 ;
return V_14 -> V_46 . V_373 . V_1198 ( V_14 , V_627 , V_1195 , V_4 ) ;
}
static int F_613 ( struct V_76 * V_77 , struct V_1199 * V_1200 , int V_1201 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
switch ( V_1201 ) {
case V_1202 :
return F_614 ( V_2 , V_1200 ) ;
case V_1203 :
return F_615 ( V_2 , V_1200 ) ;
default:
return F_616 ( & V_2 -> V_14 . V_46 . V_1196 , F_617 ( V_1200 ) , V_1201 ) ;
}
}
static int F_618 ( struct V_76 * V_89 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_399 ( V_14 -> V_118 . V_1204 ) ) {
F_485 () ;
V_17 = F_619 ( V_89 , V_14 -> V_118 . V_1204 , V_1205 ) ;
F_488 () ;
V_14 -> V_118 . V_373 . V_758 ( V_14 , F_308 ( 0 ) ) ;
}
return V_17 ;
}
static int F_620 ( struct V_76 * V_89 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_1206 * V_118 = & V_2 -> V_14 . V_118 ;
if ( F_399 ( V_118 -> V_1204 ) ) {
F_485 () ;
V_17 = F_621 ( V_89 , V_118 -> V_1204 , V_1205 ) ;
F_488 () ;
}
return V_17 ;
}
static void F_622 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
int V_49 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
for ( V_49 = 0 ; V_49 < V_2 -> V_210 ; V_49 ++ )
F_253 ( 0 , V_2 -> V_174 [ V_49 ] ) ;
}
static void F_623 ( struct V_1207 * V_133 ,
struct V_63 * V_64 )
{
V_71 V_188 , V_153 ;
unsigned int V_1208 ;
if ( V_64 ) {
do {
V_1208 = F_624 ( & V_64 -> V_187 ) ;
V_153 = V_64 -> V_133 . V_153 ;
V_188 = V_64 -> V_133 . V_188 ;
} while ( F_625 ( & V_64 -> V_187 , V_1208 ) );
V_133 -> V_880 += V_153 ;
V_133 -> V_879 += V_188 ;
}
}
static void F_626 ( struct V_76 * V_77 ,
struct V_1207 * V_133 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
int V_49 ;
F_209 () ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
struct V_63 * V_64 = F_21 ( V_2 -> V_84 [ V_49 ] ) ;
V_71 V_188 , V_153 ;
unsigned int V_1208 ;
if ( V_64 ) {
do {
V_1208 = F_624 ( & V_64 -> V_187 ) ;
V_153 = V_64 -> V_133 . V_153 ;
V_188 = V_64 -> V_133 . V_188 ;
} while ( F_625 ( & V_64 -> V_187 , V_1208 ) );
V_133 -> V_878 += V_153 ;
V_133 -> V_877 += V_188 ;
}
}
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ ) {
struct V_63 * V_64 = F_21 ( V_2 -> V_92 [ V_49 ] ) ;
F_623 ( V_133 , V_64 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ ) {
struct V_63 * V_64 = F_21 ( V_2 -> V_94 [ V_49 ] ) ;
F_623 ( V_133 , V_64 ) ;
}
F_215 () ;
V_133 -> V_987 = V_77 -> V_133 . V_987 ;
V_133 -> V_988 = V_77 -> V_133 . V_988 ;
V_133 -> V_990 = V_77 -> V_133 . V_990 ;
V_133 -> V_991 = V_77 -> V_133 . V_991 ;
V_133 -> V_992 = V_77 -> V_133 . V_992 ;
}
static void F_627 ( struct V_1 * V_2 , T_4 V_143 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_3 , V_1209 ;
int V_49 ;
if ( V_14 -> V_118 . type == V_119 )
return;
V_3 = F_40 ( V_14 , V_1210 ) ;
V_1209 = V_3 ;
for ( V_49 = 0 ; V_49 < V_685 ; V_49 ++ ) {
T_4 V_1211 = V_3 >> ( V_49 * V_1212 ) ;
if ( V_1211 > V_143 )
V_3 &= ~ ( 0x7 << V_1212 ) ;
}
if ( V_3 != V_1209 )
F_74 ( V_14 , V_1210 , V_3 ) ;
return;
}
static void F_628 ( struct V_1 * V_2 )
{
struct V_76 * V_89 = V_2 -> V_77 ;
struct V_1213 * V_145 = & V_2 -> V_145 ;
struct V_1214 * V_1215 = V_2 -> V_670 ;
T_4 V_1216 ;
for ( V_1216 = 0 ; V_1216 < V_1217 ; V_1216 ++ ) {
T_4 V_143 = 0 ;
if ( V_2 -> V_666 & V_667 )
V_143 = F_629 ( V_145 , 0 , V_1216 ) ;
else if ( V_1215 )
V_143 = V_1215 -> V_671 [ V_1216 ] ;
F_630 ( V_89 , V_1216 , V_143 ) ;
}
}
int F_631 ( struct V_76 * V_89 , T_4 V_143 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
bool V_1218 ;
if ( V_143 > V_2 -> V_145 . V_771 . V_772 )
return - V_632 ;
if ( V_14 -> V_118 . type == V_119 && V_143 && V_143 < V_685 )
return - V_632 ;
V_1218 = ( F_632 ( & V_2 -> V_711 , 32 ) > 1 ) ;
if ( V_143 && V_1218 && V_2 -> V_712 > V_1219 )
return - V_842 ;
if ( F_63 ( V_89 ) )
F_474 ( V_89 ) ;
else
F_424 ( V_2 ) ;
F_492 ( V_2 ) ;
#ifdef F_405
if ( V_143 ) {
F_633 ( V_89 , V_143 ) ;
F_628 ( V_2 ) ;
V_2 -> V_148 |= V_149 ;
if ( V_2 -> V_14 . V_118 . type == V_119 ) {
V_2 -> V_1220 = V_2 -> V_14 . V_134 . V_819 ;
V_2 -> V_14 . V_134 . V_819 = V_1221 ;
}
} else {
F_634 ( V_89 ) ;
if ( V_2 -> V_14 . V_118 . type == V_119 )
V_2 -> V_14 . V_134 . V_819 = V_2 -> V_1220 ;
V_2 -> V_148 &= ~ V_149 ;
V_2 -> V_787 . V_146 = false ;
V_2 -> V_145 . V_146 = false ;
}
F_627 ( V_2 , V_143 ) ;
#endif
F_486 ( V_2 ) ;
if ( F_63 ( V_89 ) )
return F_469 ( V_89 ) ;
return 0 ;
}
static int F_635 ( struct V_1 * V_2 ,
struct V_1222 * V_1223 )
{
T_1 V_1224 = V_1223 -> V_1225 . V_1226 ;
T_1 V_1227 = F_636 ( V_1223 -> V_1225 . V_1226 ) ;
T_1 V_1228 = V_1223 -> V_1225 . V_1226 & 0xfffff ;
int V_17 = 0 , V_49 , V_60 ;
struct V_1229 * V_1230 = NULL ;
if ( V_1228 > V_1231 )
return - V_632 ;
if ( ( V_1227 != 0x800 ) && ( V_1227 >= V_813 ) )
return - V_632 ;
if ( V_1227 != 0x800 ) {
V_1230 = V_2 -> V_810 [ V_1227 ] ;
if ( ! V_1230 )
return - V_632 ;
if ( ! F_14 ( V_1228 - 1 , V_1230 -> V_1232 ) )
return - V_632 ;
F_37 ( V_1228 - 1 , V_1230 -> V_1232 ) ;
}
for ( V_49 = 1 ; V_49 < V_813 ; V_49 ++ ) {
V_1230 = V_2 -> V_810 [ V_49 ] ;
if ( V_1230 && V_1230 -> V_1233 == V_1224 ) {
for ( V_60 = 0 ; V_60 < V_1231 ; V_60 ++ ) {
if ( ! F_14 ( V_60 , V_1230 -> V_1232 ) )
continue;
F_382 ( & V_2 -> V_695 ) ;
V_17 = F_637 ( V_2 ,
NULL ,
V_60 + 1 ) ;
F_387 ( & V_2 -> V_695 ) ;
F_37 ( V_60 , V_1230 -> V_1232 ) ;
}
F_266 ( V_1230 -> V_1125 ) ;
F_266 ( V_1230 -> V_128 ) ;
F_266 ( V_1230 ) ;
V_2 -> V_810 [ V_49 ] = NULL ;
return V_17 ;
}
}
F_382 ( & V_2 -> V_695 ) ;
V_17 = F_637 ( V_2 , NULL , V_1228 ) ;
F_387 ( & V_2 -> V_695 ) ;
return V_17 ;
}
static int F_638 ( struct V_1 * V_2 ,
T_11 V_276 ,
struct V_1222 * V_1223 )
{
T_1 V_1227 = F_636 ( V_1223 -> V_1234 . V_1226 ) ;
if ( V_1227 >= V_813 )
return - V_632 ;
if ( V_1223 -> V_1234 . V_1235 > 0 )
return - V_632 ;
F_91 ( V_1227 - 1 , & V_2 -> V_1236 ) ;
return 0 ;
}
static int F_639 ( struct V_1 * V_2 ,
struct V_1222 * V_1223 )
{
T_1 V_1227 = F_636 ( V_1223 -> V_1234 . V_1226 ) ;
if ( V_1227 >= V_813 )
return - V_632 ;
F_37 ( V_1227 - 1 , & V_2 -> V_1236 ) ;
return 0 ;
}
static int F_640 ( struct V_76 * V_106 , void * V_1237 )
{
if ( F_401 ( V_106 ) ) {
struct V_715 * V_716 = F_87 ( V_106 ) ;
struct V_701 * V_702 = V_716 -> V_717 ;
struct V_1238 * V_103 = V_1237 ;
struct V_1 * V_2 = V_103 -> V_2 ;
int V_1239 = V_103 -> V_1239 ;
if ( V_702 && V_702 -> V_77 -> V_1239 == V_1239 ) {
V_103 -> V_114 = V_2 -> V_84 [ V_702 -> V_704 ] -> V_158 ;
V_103 -> V_699 = V_103 -> V_114 ;
return 1 ;
}
}
return 0 ;
}
static int F_641 ( struct V_1 * V_2 , int V_1239 ,
T_4 * V_114 , V_71 * V_699 )
{
unsigned int V_339 = V_2 -> V_339 , V_1032 ;
struct V_1238 V_103 ;
struct V_76 * V_106 ;
for ( V_1032 = 0 ; V_1032 < V_339 ; ++ V_1032 ) {
V_106 = F_478 ( V_2 -> V_557 [ V_1032 ] . V_1035 ) ;
if ( V_106 -> V_1239 == V_1239 ) {
if ( V_2 -> V_712 > 1 )
* V_114 = V_1032 * 2 ;
else
* V_114 = V_1032 * V_2 -> V_703 ;
* V_699 = V_1032 + 1 ;
* V_699 <<= V_1240 ;
return 0 ;
}
}
V_103 . V_2 = V_2 ;
V_103 . V_1239 = V_1239 ;
V_103 . V_699 = 0 ;
V_103 . V_114 = 0 ;
if ( F_403 ( V_2 -> V_77 ,
F_640 , & V_103 ) ) {
* V_699 = V_103 . V_699 ;
* V_114 = V_103 . V_114 ;
return 0 ;
}
return - V_632 ;
}
static int F_642 ( struct V_1 * V_2 ,
struct V_1241 * V_1242 , V_71 * V_699 , T_4 * V_114 )
{
const struct V_1243 * V_81 ;
F_643 ( V_1244 ) ;
int V_17 ;
if ( F_644 ( V_1242 ) )
return - V_632 ;
F_645 ( V_1242 , & V_1244 ) ;
F_646 (a, &actions, list) {
if ( F_647 ( V_81 ) ) {
* V_699 = V_700 ;
* V_114 = V_700 ;
return 0 ;
}
if ( F_648 ( V_81 ) ) {
int V_1239 = F_649 ( V_81 ) ;
V_17 = F_641 ( V_2 , V_1239 , V_114 ,
V_699 ) ;
if ( V_17 == 0 )
return V_17 ;
}
}
return - V_632 ;
}
static int F_642 ( struct V_1 * V_2 ,
struct V_1241 * V_1242 , V_71 * V_699 , T_4 * V_114 )
{
return - V_632 ;
}
static int F_650 ( struct V_693 * V_1125 ,
union V_1245 * V_128 ,
struct V_1222 * V_1223 ,
struct V_1246 * V_1247 ,
struct V_1248 * V_1249 )
{
int V_49 , V_60 , V_1250 ;
T_17 V_1251 , V_1252 ;
bool V_1253 = false , V_1254 = false ;
for ( V_49 = 0 ; V_49 < V_1223 -> V_1225 . V_1255 -> V_1256 ; V_49 ++ ) {
V_1250 = V_1223 -> V_1225 . V_1255 -> V_1257 [ V_49 ] . V_1250 ;
V_1251 = V_1223 -> V_1225 . V_1255 -> V_1257 [ V_49 ] . V_1251 ;
V_1252 = V_1223 -> V_1225 . V_1255 -> V_1257 [ V_49 ] . V_128 ;
for ( V_60 = 0 ; V_1247 [ V_60 ] . V_1251 ; V_60 ++ ) {
if ( V_1247 [ V_60 ] . V_1250 == V_1250 ) {
V_1247 [ V_60 ] . V_1251 ( V_1125 , V_128 , V_1251 , V_1252 ) ;
V_1125 -> V_694 . V_1143 . V_1149 |=
V_1247 [ V_60 ] . type ;
V_1253 = true ;
break;
}
}
if ( V_1249 ) {
if ( V_1249 -> V_1250 == V_1223 -> V_1225 . V_1255 -> V_1257 [ V_49 ] . V_1250 &&
V_1249 -> V_1251 == V_1223 -> V_1225 . V_1255 -> V_1257 [ V_49 ] . V_1251 &&
V_1249 -> V_128 == V_1223 -> V_1225 . V_1255 -> V_1257 [ V_49 ] . V_128 )
V_1254 = true ;
else
continue;
}
}
if ( V_1249 && ! V_1254 )
return - V_632 ;
if ( ! V_1253 )
return 0 ;
V_128 -> V_1143 . V_1149 = V_1258 |
V_1259 ;
if ( V_1125 -> V_694 . V_1143 . V_1149 == V_1260 )
V_128 -> V_1143 . V_1149 &= V_1258 ;
return 0 ;
}
static int F_651 ( struct V_1 * V_2 ,
T_11 V_276 ,
struct V_1222 * V_1223 )
{
T_1 V_1228 = V_1223 -> V_1225 . V_1226 & 0xfffff ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1246 * V_1247 ;
struct V_693 * V_1125 = NULL ;
union V_1245 * V_128 = NULL ;
struct V_1229 * V_1230 = NULL ;
int V_49 , V_17 = - V_632 ;
T_4 V_114 ;
T_1 V_1227 , V_1261 ;
V_1227 = F_636 ( V_1223 -> V_1225 . V_1226 ) ;
V_1261 = F_636 ( V_1223 -> V_1225 . V_1262 ) ;
if ( V_276 != F_164 ( V_1099 ) )
return V_17 ;
if ( V_1228 >= ( ( 1024 << V_2 -> V_688 ) - 2 ) ) {
F_107 ( V_164 , L_130 ) ;
return V_17 ;
}
if ( V_1227 == 0x800 ) {
V_1247 = ( V_2 -> V_810 [ 0 ] ) -> V_811 ;
} else {
if ( V_1227 >= V_813 )
return V_17 ;
if ( ! V_2 -> V_810 [ V_1227 ] )
return V_17 ;
V_1247 = ( V_2 -> V_810 [ V_1227 ] ) -> V_811 ;
}
if ( ! V_1247 )
return V_17 ;
if ( V_1261 ) {
struct V_1248 * V_1249 = V_1263 ;
if ( V_1261 >= V_813 )
return V_17 ;
if ( ! F_14 ( V_1261 - 1 , & V_2 -> V_1236 ) )
return V_17 ;
if ( V_2 -> V_810 [ V_1261 ] &&
( V_2 -> V_810 [ V_1261 ] ) -> V_1233 ) {
F_107 ( V_164 , L_131 ,
V_1261 ) ;
return V_17 ;
}
for ( V_49 = 0 ; V_1249 [ V_49 ] . V_1230 ; V_49 ++ ) {
if ( V_1249 [ V_49 ] . V_1264 != V_1223 -> V_1225 . V_1255 -> V_1265 ||
V_1249 [ V_49 ] . V_1266 != V_1223 -> V_1225 . V_1255 -> V_1267 ||
V_1249 [ V_49 ] . V_1252 != V_1223 -> V_1225 . V_1255 -> V_1268 )
return V_17 ;
V_1230 = F_288 ( sizeof( * V_1230 ) , V_486 ) ;
if ( ! V_1230 )
return - V_487 ;
V_1125 = F_288 ( sizeof( * V_1125 ) , V_486 ) ;
if ( ! V_1125 ) {
V_17 = - V_487 ;
goto V_1269;
}
V_128 = F_288 ( sizeof( * V_128 ) , V_486 ) ;
if ( ! V_128 ) {
V_17 = - V_487 ;
goto V_1270;
}
V_1230 -> V_1125 = V_1125 ;
V_1230 -> V_128 = V_128 ;
V_1230 -> V_1233 = V_1223 -> V_1225 . V_1226 ;
V_17 = F_650 ( V_1125 , V_128 , V_1223 ,
V_1247 , & V_1249 [ V_49 ] ) ;
if ( ! V_17 ) {
V_1230 -> V_811 = V_1249 [ V_49 ] . V_1230 ;
V_2 -> V_810 [ V_1261 ] = V_1230 ;
break;
}
}
return 0 ;
}
V_1125 = F_288 ( sizeof( * V_1125 ) , V_486 ) ;
if ( ! V_1125 )
return - V_487 ;
V_128 = F_288 ( sizeof( * V_128 ) , V_486 ) ;
if ( ! V_128 ) {
V_17 = - V_487 ;
goto V_1270;
}
if ( ( V_1227 != 0x800 ) && ( V_2 -> V_810 [ V_1227 ] ) ) {
if ( ( V_2 -> V_810 [ V_1227 ] ) -> V_1125 )
memcpy ( V_1125 , ( V_2 -> V_810 [ V_1227 ] ) -> V_1125 ,
sizeof( * V_1125 ) ) ;
if ( ( V_2 -> V_810 [ V_1227 ] ) -> V_128 )
memcpy ( V_128 , ( V_2 -> V_810 [ V_1227 ] ) -> V_128 ,
sizeof( * V_128 ) ) ;
for ( V_49 = 1 ; V_49 < V_813 ; V_49 ++ ) {
struct V_1229 * V_416 = V_2 -> V_810 [ V_49 ] ;
if ( V_416 && ( F_14 ( V_1228 - 1 , V_416 -> V_1232 ) ) ) {
F_107 ( V_164 , L_132 ,
V_1228 ) ;
V_17 = - V_632 ;
goto V_1271;
}
}
}
V_17 = F_650 ( V_1125 , V_128 , V_1223 , V_1247 , NULL ) ;
if ( V_17 )
goto V_1271;
V_17 = F_642 ( V_2 , V_1223 -> V_1225 . V_1242 , & V_1125 -> V_699 ,
& V_114 ) ;
if ( V_17 < 0 )
goto V_1271;
V_1125 -> V_698 = V_1228 ;
F_382 ( & V_2 -> V_695 ) ;
if ( F_383 ( & V_2 -> V_696 ) ) {
memcpy ( & V_2 -> V_697 , V_128 , sizeof( * V_128 ) ) ;
V_17 = F_384 ( V_14 , V_128 ) ;
if ( V_17 )
goto V_1272;
} else if ( memcmp ( & V_2 -> V_697 , V_128 , sizeof( * V_128 ) ) ) {
V_17 = - V_632 ;
goto V_1272;
}
F_652 ( & V_1125 -> V_694 , V_128 ) ;
V_17 = F_386 ( V_14 , & V_1125 -> V_694 ,
V_1125 -> V_698 , V_114 ) ;
if ( ! V_17 )
F_637 ( V_2 , V_1125 , V_1125 -> V_698 ) ;
F_387 ( & V_2 -> V_695 ) ;
if ( ( V_1227 != 0x800 ) && ( V_2 -> V_810 [ V_1227 ] ) )
F_91 ( V_1228 - 1 , ( V_2 -> V_810 [ V_1227 ] ) -> V_1232 ) ;
F_266 ( V_128 ) ;
return V_17 ;
V_1272:
F_387 ( & V_2 -> V_695 ) ;
V_1271:
F_266 ( V_128 ) ;
V_1270:
F_266 ( V_1125 ) ;
V_1269:
F_266 ( V_1230 ) ;
return V_17 ;
}
static int F_653 ( struct V_76 * V_89 , T_1 V_1226 , T_1 V_1273 ,
T_11 V_597 , struct V_1274 * V_143 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
if ( V_1273 )
return - V_1275 ;
if ( F_654 ( V_1226 ) == F_654 ( V_1276 ) &&
V_143 -> type == V_1277 ) {
switch ( V_143 -> V_1278 -> V_1279 ) {
case V_1280 :
case V_1281 :
return F_651 ( V_2 ,
V_597 , V_143 -> V_1278 ) ;
case V_1282 :
return F_635 ( V_2 , V_143 -> V_1278 ) ;
case V_1283 :
case V_1284 :
return F_638 ( V_2 , V_597 ,
V_143 -> V_1278 ) ;
case V_1285 :
return F_639 ( V_2 ,
V_143 -> V_1278 ) ;
default:
return - V_632 ;
}
}
if ( V_143 -> type != V_1286 )
return - V_632 ;
V_143 -> V_1287 -> V_14 = V_1288 ;
return F_631 ( V_89 , V_143 -> V_1287 -> V_682 ) ;
}
void F_655 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
F_485 () ;
F_631 ( V_77 , F_279 ( V_77 ) ) ;
F_488 () ;
}
void F_656 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
if ( F_63 ( V_77 ) )
F_416 ( V_2 ) ;
else
F_424 ( V_2 ) ;
}
static T_12 F_657 ( struct V_76 * V_77 ,
T_12 V_218 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
if ( ! ( V_218 & V_235 ) )
V_218 &= ~ V_1289 ;
if ( ! ( V_2 -> V_368 & V_802 ) )
V_218 &= ~ V_1289 ;
return V_218 ;
}
static int F_658 ( struct V_76 * V_77 ,
T_12 V_218 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
T_12 V_1290 = V_77 -> V_218 ^ V_218 ;
bool V_1291 = false ;
if ( ! ( V_218 & V_1289 ) ) {
if ( V_2 -> V_368 & V_574 )
V_1291 = true ;
V_2 -> V_368 &= ~ V_574 ;
} else if ( ( V_2 -> V_368 & V_802 ) &&
! ( V_2 -> V_368 & V_574 ) ) {
if ( V_2 -> V_428 == 1 ||
V_2 -> V_428 > V_1292 ) {
V_2 -> V_368 |= V_574 ;
V_1291 = true ;
} else if ( ( V_1290 ^ V_218 ) & V_1289 ) {
F_109 ( V_190 , L_133
L_134 ) ;
}
}
if ( ( V_218 & V_1293 ) || ( V_218 & V_1294 ) ) {
if ( ! ( V_2 -> V_148 & V_687 ) )
V_1291 = true ;
V_2 -> V_148 &= ~ V_409 ;
V_2 -> V_148 |= V_687 ;
} else {
if ( V_2 -> V_148 & V_687 )
V_1291 = true ;
V_2 -> V_148 &= ~ V_687 ;
if ( V_2 -> V_148 & V_457 ||
( F_279 ( V_77 ) > 1 ) ||
( V_2 -> V_462 [ V_477 ] . V_801 <= 1 ) ||
( ! V_2 -> V_447 ) )
;
else
V_2 -> V_148 |= V_409 ;
}
if ( V_1290 & V_297 )
V_1291 = true ;
V_77 -> V_218 = V_218 ;
if ( ( V_2 -> V_148 & V_658 ) ) {
if ( V_218 & V_235 ) {
V_2 -> V_368 |= V_1054 ;
} else {
T_1 V_1295 = V_661 ;
F_362 ( V_2 , V_1295 ) ;
}
}
if ( ( V_2 -> V_148 & V_659 ) ) {
if ( V_218 & V_235 ) {
V_2 -> V_368 |= V_1054 ;
} else {
T_1 V_1295 = V_663 ;
F_362 ( V_2 , V_1295 ) ;
}
}
if ( V_1291 )
F_656 ( V_77 ) ;
else if ( V_1290 & ( V_271 |
V_652 ) )
F_355 ( V_77 ) ;
return 0 ;
}
static void F_659 ( struct V_76 * V_89 ,
struct V_1296 * V_430 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_11 V_1145 = V_430 -> V_1145 ;
T_1 V_1297 = 0 ;
T_1 V_3 ;
if ( V_430 -> V_1298 != V_1299 )
return;
switch ( V_430 -> type ) {
case V_1300 :
if ( ! ( V_2 -> V_148 & V_658 ) )
return;
if ( V_2 -> V_662 == V_1145 )
return;
if ( V_2 -> V_662 ) {
F_660 ( V_89 ,
L_135 ,
F_599 ( V_2 -> V_662 ) ,
F_599 ( V_1145 ) ) ;
return;
}
V_2 -> V_662 = V_1145 ;
break;
case V_1301 :
if ( ! ( V_2 -> V_148 & V_659 ) )
return;
if ( V_2 -> V_664 == V_1145 )
return;
if ( V_2 -> V_664 ) {
F_660 ( V_89 ,
L_136 ,
F_599 ( V_2 -> V_664 ) ,
F_599 ( V_1145 ) ) ;
return;
}
V_1297 = V_1302 ;
V_2 -> V_664 = V_1145 ;
break;
default:
return;
}
V_3 = F_40 ( V_14 , V_660 ) | F_599 ( V_1145 ) << V_1297 ;
F_74 ( V_14 , V_660 , V_3 ) ;
}
static void F_661 ( struct V_76 * V_89 ,
struct V_1296 * V_430 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
T_1 V_1295 ;
if ( V_430 -> type != V_1300 &&
V_430 -> type != V_1301 )
return;
if ( V_430 -> V_1298 != V_1299 )
return;
switch ( V_430 -> type ) {
case V_1300 :
if ( ! ( V_2 -> V_148 & V_658 ) )
return;
if ( V_2 -> V_662 != V_430 -> V_1145 ) {
F_660 ( V_89 , L_137 ,
F_599 ( V_430 -> V_1145 ) ) ;
return;
}
V_1295 = V_661 ;
break;
case V_1301 :
if ( ! ( V_2 -> V_148 & V_659 ) )
return;
if ( V_2 -> V_664 != V_430 -> V_1145 ) {
F_660 ( V_89 , L_138 ,
F_599 ( V_430 -> V_1145 ) ) ;
return;
}
V_1295 = V_663 ;
break;
default:
return;
}
F_362 ( V_2 , V_1295 ) ;
V_2 -> V_368 |= V_1054 ;
}
static int F_662 ( struct V_1303 * V_1304 , struct V_1305 * V_1306 [] ,
struct V_76 * V_89 ,
const unsigned char * V_627 , T_2 V_273 ,
T_2 V_148 )
{
if ( F_663 ( V_627 ) || F_664 ( V_627 ) ) {
struct V_1 * V_2 = F_87 ( V_89 ) ;
T_2 V_531 = F_308 ( 0 ) ;
if ( F_349 ( V_89 ) >= F_341 ( V_2 , V_531 ) )
return - V_487 ;
}
return F_665 ( V_1304 , V_1306 , V_89 , V_627 , V_273 , V_148 ) ;
}
static int F_666 ( struct V_1 * V_2 ,
T_18 V_1307 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
unsigned int V_62 , V_1308 ;
T_1 V_540 ;
switch ( V_1307 ) {
case V_1309 :
F_74 ( & V_2 -> V_14 , V_548 , 0 ) ;
V_540 = F_40 ( V_14 , V_1310 ) ;
V_540 |= V_545 ;
F_74 ( V_14 , V_1310 , V_540 ) ;
V_1308 = V_2 -> V_339 + V_2 -> V_712 ;
for ( V_62 = 0 ; V_62 < V_1308 ; V_62 ++ ) {
if ( V_14 -> V_118 . V_373 . V_1311 )
V_14 -> V_118 . V_373 . V_1311 ( V_14 ,
true ,
V_62 ) ;
}
break;
case V_547 :
F_74 ( & V_2 -> V_14 , V_548 ,
V_549 ) ;
V_540 = F_40 ( V_14 , V_1310 ) ;
if ( ! V_2 -> V_339 )
V_540 &= ~ V_545 ;
F_74 ( V_14 , V_1310 , V_540 ) ;
V_1308 = V_2 -> V_339 + V_2 -> V_712 ;
for ( V_62 = 0 ; V_62 < V_1308 ; V_62 ++ ) {
if ( V_14 -> V_118 . V_373 . V_1311 )
V_14 -> V_118 . V_373 . V_1311 ( V_14 ,
false ,
V_62 ) ;
}
break;
default:
return - V_632 ;
}
V_2 -> V_546 = V_1307 ;
F_109 ( V_164 , L_139 ,
V_1307 == V_1309 ? L_140 : L_141 ) ;
return 0 ;
}
static int F_667 ( struct V_76 * V_89 ,
struct V_1312 * V_1313 , T_2 V_148 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_1305 * V_1314 , * V_1315 ;
int V_1316 ;
if ( ! ( V_2 -> V_148 & V_457 ) )
return - V_1275 ;
V_1315 = F_668 ( V_1313 , sizeof( struct V_1317 ) , V_1318 ) ;
if ( ! V_1315 )
return - V_632 ;
F_669 (attr, br_spec, rem) {
int V_182 ;
T_18 V_1307 ;
if ( F_670 ( V_1314 ) != V_1319 )
continue;
if ( F_671 ( V_1314 ) < sizeof( V_1307 ) )
return - V_632 ;
V_1307 = F_672 ( V_1314 ) ;
V_182 = F_666 ( V_2 , V_1307 ) ;
if ( V_182 )
return V_182 ;
break;
}
return 0 ;
}
static int F_673 ( struct V_216 * V_100 , T_1 V_1320 , T_1 V_1321 ,
struct V_76 * V_89 ,
T_1 V_1322 , int V_1323 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
if ( ! ( V_2 -> V_148 & V_457 ) )
return 0 ;
return F_674 ( V_100 , V_1320 , V_1321 , V_89 ,
V_2 -> V_546 , 0 , 0 , V_1323 ,
V_1322 , NULL ) ;
}
static void * F_675 ( struct V_76 * V_9 , struct V_76 * V_705 )
{
struct V_701 * V_1158 = NULL ;
struct V_1 * V_2 = F_87 ( V_9 ) ;
int V_1324 = V_2 -> V_339 + V_2 -> V_712 ;
unsigned int V_801 ;
int V_531 , V_17 ;
if ( V_1324 >= V_1325 )
return F_216 ( - V_632 ) ;
#ifdef F_676
if ( V_705 -> V_104 != V_705 -> V_91 ) {
F_660 ( V_9 , L_142 ,
V_705 -> V_59 ) ;
return F_216 ( - V_632 ) ;
}
#endif
if ( V_705 -> V_91 > V_845 ||
V_705 -> V_91 == V_1326 ) {
F_660 ( V_9 ,
L_143 ,
V_9 -> V_59 ) ;
return F_216 ( - V_632 ) ;
}
if ( ( ( V_2 -> V_148 & V_149 ) &&
V_2 -> V_712 > V_1219 - 1 ) ||
( V_2 -> V_712 > V_1327 ) )
return F_216 ( - V_842 ) ;
V_1158 = F_288 ( sizeof( * V_1158 ) , V_486 ) ;
if ( ! V_1158 )
return F_216 ( - V_487 ) ;
V_531 = F_632 ( & V_2 -> V_711 , 32 ) ;
V_2 -> V_712 ++ ;
F_91 ( V_531 , & V_2 -> V_711 ) ;
V_801 = F_677 ( & V_2 -> V_711 , 32 ) ;
V_2 -> V_148 |= V_610 | V_457 ;
V_2 -> V_462 [ V_463 ] . V_801 = V_801 + 1 ;
V_2 -> V_462 [ V_477 ] . V_801 = V_705 -> V_91 ;
V_17 = F_631 ( V_9 , F_279 ( V_9 ) ) ;
if ( V_17 )
goto V_1328;
V_1158 -> V_531 = V_531 ;
V_1158 -> V_157 = V_2 ;
if ( F_63 ( V_9 ) ) {
V_17 = F_395 ( V_705 , V_1158 ) ;
if ( V_17 )
goto V_1328;
F_678 ( V_705 ) ;
}
return V_1158 ;
V_1328:
F_660 ( V_9 ,
L_144 , V_705 -> V_59 ) ;
F_37 ( V_531 , & V_2 -> V_711 ) ;
V_2 -> V_712 -- ;
F_266 ( V_1158 ) ;
return F_216 ( V_17 ) ;
}
static void F_679 ( struct V_76 * V_9 , void * V_1329 )
{
struct V_701 * V_1158 = V_1329 ;
struct V_1 * V_2 = V_1158 -> V_157 ;
unsigned int V_801 ;
F_37 ( V_1158 -> V_531 , & V_2 -> V_711 ) ;
V_2 -> V_712 -- ;
V_801 = F_677 ( & V_2 -> V_711 , 32 ) ;
V_2 -> V_462 [ V_463 ] . V_801 = V_801 + 1 ;
F_393 ( V_1158 -> V_77 , V_1158 ) ;
F_631 ( V_9 , F_279 ( V_9 ) ) ;
F_396 ( V_9 , L_87 ,
V_1158 -> V_531 , V_2 -> V_712 ,
V_1158 -> V_704 ,
V_1158 -> V_704 + V_2 -> V_703 ,
V_2 -> V_711 ) ;
F_266 ( V_1158 ) ;
}
static T_12
F_680 ( struct V_216 * V_100 , struct V_76 * V_89 ,
T_12 V_218 )
{
unsigned int V_1330 , V_1331 ;
V_1331 = F_557 ( V_100 ) - V_100 -> V_103 ;
if ( F_23 ( V_1331 > V_1332 ) )
return V_218 & ~ ( V_1333 |
V_1334 |
V_1335 |
V_1336 |
V_1337 ) ;
V_1330 = F_558 ( V_100 ) - F_557 ( V_100 ) ;
if ( F_23 ( V_1330 > V_1338 ) )
return V_218 & ~ ( V_1333 |
V_1334 |
V_1336 |
V_1337 ) ;
if ( V_100 -> V_237 && ! ( V_218 & V_1339 ) )
V_218 &= ~ V_1336 ;
return V_218 ;
}
static int F_681 ( struct V_76 * V_89 , struct V_316 * V_1340 )
{
int V_49 , V_1341 = V_89 -> V_333 + V_561 + V_562 + V_1342 ;
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_316 * V_1343 ;
if ( V_2 -> V_148 & V_457 )
return - V_632 ;
if ( V_2 -> V_148 & V_149 )
return - V_632 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
struct V_63 * V_64 = V_2 -> V_84 [ V_49 ] ;
if ( F_170 ( V_64 ) )
return - V_632 ;
if ( V_1341 > F_72 ( V_64 ) )
return - V_632 ;
}
if ( V_1344 > V_1345 )
return - V_487 ;
V_1343 = F_682 ( & V_2 -> V_317 , V_1340 ) ;
if ( ! ! V_1340 != ! ! V_1343 ) {
int V_17 = F_631 ( V_89 , F_279 ( V_89 ) ) ;
if ( V_17 ) {
F_683 ( V_2 -> V_317 , V_1343 ) ;
return - V_632 ;
}
} else {
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ )
F_682 ( & V_2 -> V_84 [ V_49 ] -> V_317 , V_2 -> V_317 ) ;
}
if ( V_1343 )
F_684 ( V_1343 ) ;
return 0 ;
}
static int F_685 ( struct V_76 * V_89 , struct V_1346 * V_309 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
switch ( V_309 -> V_1279 ) {
case V_1347 :
return F_681 ( V_89 , V_309 -> V_1340 ) ;
case V_1348 :
V_309 -> V_1349 = ! ! ( V_2 -> V_317 ) ;
V_309 -> V_1350 = V_2 -> V_317 ?
V_2 -> V_317 -> V_1351 -> V_1352 : 0 ;
return 0 ;
default:
return - V_632 ;
}
}
static inline int F_686 ( struct V_1 * V_2 )
{
struct V_5 * V_433 , * V_9 = V_2 -> V_9 ;
int V_1353 = 0 ;
if ( F_8 ( & V_2 -> V_14 ) )
V_1353 = 4 ;
F_646 (entry, &adapter->pdev->bus->devices, bus_list) {
if ( V_433 -> V_1354 )
continue;
if ( ( V_433 -> V_793 != V_9 -> V_793 ) ||
( V_433 -> V_211 != V_9 -> V_211 ) )
return - 1 ;
V_1353 ++ ;
}
return V_1353 ;
}
bool F_687 ( struct V_1 * V_2 , T_2 V_21 ,
T_2 V_1355 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1356 = V_2 -> V_1357 & V_1358 ;
if ( V_14 -> V_118 . type == V_119 )
return false ;
if ( V_14 -> V_118 . type >= V_122 ) {
if ( ( V_1356 == V_1359 ) ||
( ( V_1356 == V_1360 ) &&
( V_14 -> V_10 . V_1361 == 0 ) ) )
return true ;
}
switch ( V_21 ) {
case V_1362 :
switch ( V_1355 ) {
case V_1363 :
case V_1364 :
case V_1365 :
case V_1366 :
if ( V_14 -> V_10 . V_1361 != 0 )
break;
case V_1367 :
case V_1368 :
case V_1369 :
case V_1370 :
case V_1371 :
case V_1372 :
case V_1373 :
return true ;
}
break;
case V_1374 :
switch ( V_1355 ) {
case V_1375 :
return true ;
}
break;
case V_1376 :
if ( V_1355 != V_1377 )
return true ;
break;
case V_1378 :
return true ;
default:
break;
}
return false ;
}
static int F_688 ( struct V_5 * V_9 , const struct V_1379 * V_1380 )
{
struct V_76 * V_77 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_14 ;
const struct V_788 * V_789 = V_1381 [ V_1380 -> V_1382 ] ;
int V_49 , V_17 , V_1383 , V_24 ;
unsigned int V_496 = V_1384 ;
T_4 V_1385 [ V_1386 ] ;
bool V_1387 = false ;
#ifdef F_184
T_2 V_1388 ;
#endif
T_1 V_1389 ;
if ( V_9 -> V_1354 ) {
F_689 ( 1 , V_1390 L_145 ,
F_690 ( V_9 ) , V_9 -> V_793 , V_9 -> V_211 ) ;
return - V_632 ;
}
V_17 = F_482 ( V_9 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_691 ( & V_9 -> V_89 , F_274 ( 64 ) ) ) {
V_1383 = 1 ;
} else {
V_17 = F_691 ( & V_9 -> V_89 , F_274 ( 32 ) ) ;
if ( V_17 ) {
F_457 ( & V_9 -> V_89 ,
L_146 ) ;
goto V_1391;
}
V_1383 = 0 ;
}
V_17 = F_692 ( V_9 , V_1392 ) ;
if ( V_17 ) {
F_457 ( & V_9 -> V_89 ,
L_147 , V_17 ) ;
goto V_1393;
}
F_693 ( V_9 ) ;
F_483 ( V_9 ) ;
F_481 ( V_9 ) ;
if ( V_789 -> V_118 == V_119 ) {
#ifdef F_405
V_496 = 4 * V_685 ;
#else
V_496 = V_1394 ;
#endif
}
V_77 = F_694 ( sizeof( struct V_1 ) , V_496 ) ;
if ( ! V_77 ) {
V_17 = - V_487 ;
goto V_1395;
}
F_695 ( V_77 , & V_9 -> V_89 ) ;
V_2 = F_87 ( V_77 ) ;
V_2 -> V_77 = V_77 ;
V_2 -> V_9 = V_9 ;
V_14 = & V_2 -> V_14 ;
V_14 -> V_40 = V_2 ;
V_2 -> V_1396 = F_696 ( V_1397 , V_1398 ) ;
V_14 -> V_41 = F_697 ( F_698 ( V_9 , 0 ) ,
F_699 ( V_9 , 0 ) ) ;
V_2 -> V_446 = V_14 -> V_41 ;
if ( ! V_14 -> V_41 ) {
V_17 = - V_833 ;
goto V_1399;
}
V_77 -> V_1400 = & V_1401 ;
F_700 ( V_77 ) ;
V_77 -> V_1402 = 5 * V_1050 ;
F_701 ( V_77 -> V_59 , F_690 ( V_9 ) , sizeof( V_77 -> V_59 ) ) ;
V_14 -> V_118 . V_373 = * V_789 -> V_1403 ;
V_14 -> V_118 . type = V_789 -> V_118 ;
V_14 -> V_1404 = V_789 -> V_1404 ;
if ( V_789 -> V_1405 )
V_14 -> V_416 . V_373 = * V_789 -> V_1405 ;
V_14 -> V_1406 . V_373 = * V_789 -> V_1407 ;
V_1389 = F_40 ( V_14 , F_702 ( V_14 ) ) ;
if ( F_22 ( V_14 -> V_41 ) ) {
V_17 = - V_833 ;
goto V_1399;
}
if ( ! ( V_1389 & F_224 ( 8 ) ) )
V_14 -> V_1406 . V_373 . V_260 = & V_1408 ;
V_14 -> V_46 . V_373 = * V_789 -> V_1409 ;
V_14 -> V_46 . V_1046 = V_1410 ;
V_14 -> V_46 . V_1196 . V_1194 = V_1411 ;
V_14 -> V_46 . V_1196 . V_1412 = 0 ;
V_14 -> V_46 . V_1196 . V_1413 = V_1414 | V_1415 ;
V_14 -> V_46 . V_1196 . V_89 = V_77 ;
V_14 -> V_46 . V_1196 . V_1416 = F_611 ;
V_14 -> V_46 . V_1196 . V_1417 = F_612 ;
V_17 = F_443 ( V_2 , V_789 ) ;
if ( V_17 )
goto V_1418;
if ( V_14 -> V_118 . V_373 . V_1419 )
V_14 -> V_118 . V_373 . V_1419 ( V_14 ) ;
switch ( V_2 -> V_14 . V_118 . type ) {
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
F_74 ( & V_2 -> V_14 , V_851 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_148 & V_381 ) {
T_1 V_744 = F_40 ( V_14 , V_745 ) ;
if ( V_744 & V_746 )
F_232 ( V_190 , L_70 ) ;
}
if ( V_1420 )
V_14 -> V_1420 = V_1420 ;
V_14 -> V_46 . V_1421 = true ;
V_17 = V_14 -> V_118 . V_373 . V_1422 ( V_14 ) ;
V_14 -> V_46 . V_1421 = false ;
F_440 ( V_2 ) ;
if ( V_17 == V_753 ) {
V_17 = 0 ;
} else if ( V_17 == V_754 ) {
F_18 ( L_148 ) ;
F_18 ( L_149 ) ;
goto V_1418;
} else if ( V_17 ) {
F_18 ( L_150 , V_17 ) ;
goto V_1418;
}
#ifdef F_335
if ( V_2 -> V_14 . V_118 . type == V_119 )
goto V_1423;
F_703 ( V_14 ) ;
V_14 -> V_1424 . V_373 = V_789 -> V_1425 ;
F_704 ( V_9 , V_825 ) ;
F_705 ( V_2 , V_824 ) ;
V_1423:
#endif
V_77 -> V_218 = V_1426 |
V_1336 |
V_1337 |
V_219 |
V_235 |
V_1333 ;
#define F_706 (NETIF_F_GSO_GRE | \
NETIF_F_GSO_GRE_CSUM | \
NETIF_F_GSO_IPXIP4 | \
NETIF_F_GSO_IPXIP6 | \
NETIF_F_GSO_UDP_TUNNEL | \
NETIF_F_GSO_UDP_TUNNEL_CSUM)
V_77 -> V_1427 = F_706 ;
V_77 -> V_218 |= V_1428 |
F_706 ;
if ( V_14 -> V_118 . type >= V_121 )
V_77 -> V_218 |= V_1334 ;
V_77 -> V_1429 |= V_77 -> V_218 |
V_652 |
V_271 |
V_1335 |
V_297 |
V_1430 ;
if ( V_14 -> V_118 . type >= V_121 )
V_77 -> V_1429 |= V_1293 |
V_1294 ;
if ( V_1383 )
V_77 -> V_218 |= V_1431 ;
V_77 -> V_1432 |= V_77 -> V_218 | V_1339 ;
V_77 -> V_1433 |= V_77 -> V_1432 ;
V_77 -> V_1434 |= V_1426 |
V_1336 |
V_1337 |
V_1333 ;
V_77 -> V_1434 |= F_706 ;
V_77 -> V_218 |= V_652 |
V_271 |
V_1335 ;
V_77 -> V_1435 |= V_1436 ;
V_77 -> V_1435 |= V_1437 ;
V_77 -> V_1438 = V_1439 ;
V_77 -> V_1440 = V_1441 - ( V_561 + V_562 ) ;
#ifdef F_405
if ( V_2 -> V_148 & V_785 )
V_77 -> V_1442 = & V_1443 ;
#endif
#ifdef F_184
if ( V_2 -> V_148 & V_808 ) {
unsigned int V_1444 ;
if ( V_14 -> V_118 . V_373 . V_1445 ) {
V_14 -> V_118 . V_373 . V_1445 ( V_14 , & V_1388 ) ;
if ( V_1388 & V_1446 )
V_2 -> V_148 &= ~ V_808 ;
}
V_1444 = F_353 ( int , V_1447 , F_445 () ) ;
V_2 -> V_462 [ V_1164 ] . V_801 = V_1444 ;
V_77 -> V_218 |= V_1185 |
V_1186 ;
V_77 -> V_1432 |= V_1185 |
V_1186 |
V_665 ;
}
#endif
if ( V_2 -> V_368 & V_802 )
V_77 -> V_1429 |= V_1289 ;
if ( V_2 -> V_368 & V_574 )
V_77 -> V_218 |= V_1289 ;
if ( V_14 -> V_1406 . V_373 . V_1448 ( V_14 , NULL ) < 0 ) {
F_18 ( L_151 ) ;
V_17 = - V_833 ;
goto V_1418;
}
F_707 ( & V_2 -> V_9 -> V_89 ,
V_2 -> V_14 . V_118 . V_1449 ) ;
memcpy ( V_77 -> V_714 , V_14 -> V_118 . V_1449 , V_77 -> V_1193 ) ;
if ( ! F_399 ( V_77 -> V_714 ) ) {
F_18 ( L_152 ) ;
V_17 = - V_833 ;
goto V_1418;
}
F_345 ( V_14 -> V_118 . V_627 , V_14 -> V_118 . V_1449 ) ;
F_342 ( V_2 ) ;
F_708 ( & V_2 -> V_747 , & F_544 ,
( unsigned long ) V_2 ) ;
if ( F_22 ( V_14 -> V_41 ) ) {
V_17 = - V_833 ;
goto V_1418;
}
F_709 ( & V_2 -> V_39 , F_548 ) ;
F_91 ( V_42 , & V_2 -> V_35 ) ;
F_37 ( V_37 , & V_2 -> V_35 ) ;
V_17 = F_486 ( V_2 ) ;
if ( V_17 )
goto V_1418;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ )
F_710 ( & V_2 -> V_84 [ V_49 ] -> V_187 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ )
F_710 ( & V_2 -> V_92 [ V_49 ] -> V_187 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ )
F_710 ( & V_2 -> V_94 [ V_49 ] -> V_187 ) ;
V_2 -> V_760 = 0 ;
V_14 -> V_1406 . V_373 . V_260 ( V_14 , 0x2c , & V_2 -> V_1357 ) ;
V_14 -> V_1450 = F_687 ( V_2 , V_9 -> V_211 ,
V_9 -> V_799 ) ;
if ( V_14 -> V_1450 )
V_2 -> V_760 = V_1451 ;
F_711 ( & V_2 -> V_9 -> V_89 , V_2 -> V_760 ) ;
V_14 -> V_1406 . V_373 . V_260 ( V_14 , 0x2e , & V_2 -> V_1452 ) ;
V_14 -> V_1406 . V_373 . V_260 ( V_14 , 0x2d , & V_2 -> V_1453 ) ;
if ( F_8 ( V_14 ) )
F_5 ( V_2 ) ;
else
V_14 -> V_118 . V_373 . V_1454 ( V_14 ) ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_24 = F_260 ( F_686 ( V_2 ) * 10 , 16 ) ;
break;
default:
V_24 = F_686 ( V_2 ) * 10 ;
break;
}
if ( V_24 > 0 )
F_9 ( V_2 , V_24 ) ;
V_17 = F_712 ( V_14 , V_1385 , sizeof( V_1385 ) ) ;
if ( V_17 )
F_701 ( V_1385 , L_7 , sizeof( V_1385 ) ) ;
if ( F_236 ( V_14 ) && V_14 -> V_46 . V_1046 != V_1455 )
F_12 ( L_153 ,
V_14 -> V_118 . type , V_14 -> V_46 . type , V_14 -> V_46 . V_1046 ,
V_1385 ) ;
else
F_12 ( L_154 ,
V_14 -> V_118 . type , V_14 -> V_46 . type , V_1385 ) ;
F_12 ( L_155 , V_77 -> V_714 ) ;
V_17 = V_14 -> V_118 . V_373 . V_1456 ( V_14 ) ;
if ( V_17 == V_756 ) {
F_11 ( L_90
L_156
L_157
L_158
L_94
L_95 ) ;
}
strcpy ( V_77 -> V_59 , L_159 ) ;
F_713 ( V_9 , V_2 ) ;
V_17 = F_714 ( V_77 ) ;
if ( V_17 )
goto V_1457;
if ( V_14 -> V_118 . V_373 . V_765 )
V_14 -> V_118 . V_373 . V_765 ( V_14 ) ;
F_434 ( V_77 ) ;
#ifdef F_257
if ( F_130 ( & V_9 -> V_89 ) == 0 ) {
V_2 -> V_148 |= V_196 ;
F_127 ( V_2 ) ;
}
#endif
if ( V_2 -> V_148 & V_457 ) {
F_109 ( V_190 , L_160 , V_2 -> V_339 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_339 ; V_49 ++ )
F_715 ( V_9 , ( V_49 | 0x10000000 ) ) ;
}
if ( V_14 -> V_118 . V_373 . V_1458 )
V_14 -> V_118 . V_373 . V_1458 ( V_14 , 0xFF , 0xFF , 0xFF , 0xFF ,
sizeof( V_1459 ) - 1 ,
V_1459 ) ;
F_618 ( V_77 ) ;
F_12 ( L_69 , V_1460 ) ;
#ifdef F_716
if ( F_717 ( V_2 ) )
F_107 ( V_190 , L_161 ) ;
#endif
F_718 ( V_2 ) ;
if ( F_719 ( V_14 ) && F_236 ( V_14 ) && V_14 -> V_118 . V_373 . V_725 )
V_14 -> V_118 . V_373 . V_725 ( V_14 ,
V_999 | V_1024 ,
true ) ;
return 0 ;
V_1457:
F_73 ( V_2 ) ;
F_492 ( V_2 ) ;
V_1418:
F_720 ( V_2 ) ;
V_2 -> V_368 &= ~ V_720 ;
F_721 ( V_2 -> V_446 ) ;
F_266 ( V_2 -> V_810 [ 0 ] ) ;
F_266 ( V_2 -> V_622 ) ;
F_266 ( V_2 -> V_484 ) ;
V_1399:
V_1387 = ! F_15 ( V_850 , & V_2 -> V_35 ) ;
F_722 ( V_77 ) ;
V_1395:
F_723 ( V_9 ) ;
V_1393:
V_1391:
if ( ! V_2 || V_1387 )
F_493 ( V_9 ) ;
return V_17 ;
}
static void F_724 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_478 ( V_9 ) ;
struct V_76 * V_77 ;
bool V_1387 ;
int V_49 ;
if ( ! V_2 )
return;
V_77 = V_2 -> V_77 ;
F_725 ( V_2 ) ;
F_91 ( V_36 , & V_2 -> V_35 ) ;
F_605 ( & V_2 -> V_39 ) ;
#ifdef F_257
if ( V_2 -> V_148 & V_196 ) {
V_2 -> V_148 &= ~ V_196 ;
F_131 ( & V_9 -> V_89 ) ;
F_74 ( & V_2 -> V_14 , V_207 ,
V_209 ) ;
}
#endif
#ifdef F_716
F_726 ( V_2 ) ;
#endif
F_620 ( V_77 ) ;
#ifdef F_335
F_720 ( V_2 ) ;
#endif
if ( V_77 -> V_1047 == V_1048 )
F_542 ( V_77 ) ;
F_492 ( V_2 ) ;
F_73 ( V_2 ) ;
#ifdef F_727
F_266 ( V_2 -> V_147 ) ;
F_266 ( V_2 -> V_670 ) ;
#endif
F_721 ( V_2 -> V_446 ) ;
F_723 ( V_9 ) ;
F_12 ( L_162 ) ;
for ( V_49 = 0 ; V_49 < V_813 ; V_49 ++ ) {
if ( V_2 -> V_810 [ V_49 ] ) {
F_266 ( V_2 -> V_810 [ V_49 ] -> V_1125 ) ;
F_266 ( V_2 -> V_810 [ V_49 ] -> V_128 ) ;
}
F_266 ( V_2 -> V_810 [ V_49 ] ) ;
}
F_266 ( V_2 -> V_622 ) ;
F_266 ( V_2 -> V_484 ) ;
V_1387 = ! F_15 ( V_850 , & V_2 -> V_35 ) ;
F_722 ( V_77 ) ;
F_728 ( V_9 ) ;
if ( V_1387 )
F_493 ( V_9 ) ;
}
static T_19 F_729 ( struct V_5 * V_9 ,
T_20 V_35 )
{
struct V_1 * V_2 = F_478 ( V_9 ) ;
struct V_76 * V_77 = V_2 -> V_77 ;
#ifdef F_335
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_1461 , * V_1035 ;
T_1 V_1462 , V_1463 , V_1464 , V_1465 ;
int V_1032 , V_1466 ;
T_2 V_1467 , V_1468 ;
if ( V_2 -> V_14 . V_118 . type == V_119 ||
V_2 -> V_339 == 0 )
goto V_1469;
V_1461 = V_9 -> V_10 -> V_12 ;
while ( V_1461 && ( F_730 ( V_1461 ) != V_1470 ) )
V_1461 = V_1461 -> V_10 -> V_12 ;
if ( ! V_1461 )
goto V_1469;
V_1466 = F_731 ( V_1461 , V_1471 ) ;
if ( ! V_1466 )
goto V_1469;
V_1462 = F_30 ( V_14 , V_1466 + V_1472 ) ;
V_1463 = F_30 ( V_14 , V_1466 + V_1472 + 4 ) ;
V_1464 = F_30 ( V_14 , V_1466 + V_1472 + 8 ) ;
V_1465 = F_30 ( V_14 , V_1466 + V_1472 + 12 ) ;
if ( F_22 ( V_14 -> V_41 ) )
goto V_1469;
V_1467 = V_1463 >> 16 ;
if ( ! ( V_1467 & 0x0080 ) )
goto V_1469;
V_1468 = V_1467 & 0x01 ;
if ( ( V_1468 & 1 ) == ( V_9 -> V_1473 & 1 ) ) {
unsigned int V_21 ;
V_1032 = ( V_1467 & 0x7F ) >> 1 ;
F_18 ( L_163 , V_1032 ) ;
F_18 ( L_164
L_165 ,
V_1462 , V_1463 , V_1464 , V_1465 ) ;
switch ( V_2 -> V_14 . V_118 . type ) {
case V_121 :
V_21 = V_1474 ;
break;
case V_122 :
V_21 = V_1475 ;
break;
case V_123 :
V_21 = V_1476 ;
break;
case V_124 :
V_21 = V_1477 ;
break;
case V_125 :
V_21 = V_1478 ;
break;
default:
V_21 = 0 ;
break;
}
V_1035 = F_732 ( V_1479 , V_21 , NULL ) ;
while ( V_1035 ) {
if ( V_1035 -> V_1473 == ( V_1467 & 0xFF ) )
break;
V_1035 = F_732 ( V_1479 ,
V_21 , V_1035 ) ;
}
if ( V_1035 ) {
F_538 ( V_1035 ) ;
F_733 ( V_1035 ) ;
}
F_734 ( V_9 ) ;
}
V_2 -> V_1480 ++ ;
return V_1481 ;
V_1469:
#endif
if ( ! F_14 ( V_42 , & V_2 -> V_35 ) )
return V_1482 ;
F_485 () ;
F_491 ( V_77 ) ;
if ( V_35 == V_1483 ) {
F_488 () ;
return V_1482 ;
}
if ( F_63 ( V_77 ) )
F_472 ( V_2 ) ;
if ( ! F_15 ( V_850 , & V_2 -> V_35 ) )
F_493 ( V_9 ) ;
F_488 () ;
return V_1484 ;
}
static T_19 F_735 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_478 ( V_9 ) ;
T_19 V_314 ;
int V_17 ;
if ( F_482 ( V_9 ) ) {
F_107 ( V_190 , L_166 ) ;
V_314 = V_1482 ;
} else {
F_36 () ;
F_37 ( V_850 , & V_2 -> V_35 ) ;
V_2 -> V_14 . V_41 = V_2 -> V_446 ;
F_483 ( V_9 ) ;
F_480 ( V_9 ) ;
F_481 ( V_9 ) ;
F_484 ( V_9 , false ) ;
F_424 ( V_2 ) ;
F_74 ( & V_2 -> V_14 , V_851 , ~ 0 ) ;
V_314 = V_1481 ;
}
V_17 = F_734 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_167
L_168 , V_17 ) ;
}
return V_314 ;
}
static void F_736 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_478 ( V_9 ) ;
struct V_76 * V_77 = V_2 -> V_77 ;
#ifdef F_335
if ( V_2 -> V_1480 ) {
F_109 ( V_164 , L_169 ) ;
V_2 -> V_1480 -- ;
return;
}
#endif
F_485 () ;
if ( F_63 ( V_77 ) )
F_469 ( V_77 ) ;
F_487 ( V_77 ) ;
F_488 () ;
}
static int T_21 F_737 ( void )
{
int V_636 ;
F_54 ( L_170 , V_1485 , V_1459 ) ;
F_54 ( L_69 , V_1486 ) ;
V_38 = F_738 ( V_1392 ) ;
if ( ! V_38 ) {
F_55 ( L_171 , V_1392 ) ;
return - V_487 ;
}
F_739 () ;
V_636 = F_740 ( & V_1487 ) ;
if ( V_636 ) {
F_741 ( V_38 ) ;
F_742 () ;
return V_636 ;
}
#ifdef F_257
F_743 ( & V_1488 ) ;
#endif
return 0 ;
}
static void T_22 F_744 ( void )
{
#ifdef F_257
F_745 ( & V_1488 ) ;
#endif
F_746 ( & V_1487 ) ;
F_742 () ;
if ( V_38 ) {
F_741 ( V_38 ) ;
V_38 = NULL ;
}
}
static int F_747 ( struct V_1489 * V_1490 , unsigned long V_212 ,
void * V_62 )
{
int V_1491 ;
V_1491 = F_748 ( & V_1487 . V_1492 , NULL , & V_212 ,
F_128 ) ;
return V_1491 ? V_1493 : V_1494 ;
}
