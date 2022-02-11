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
int V_17 , V_314 = V_315 ;
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
case V_322 :
V_17 = F_213 ( V_2 -> V_77 , V_309 , V_317 ) ;
if ( ! V_17 )
V_314 = V_323 ;
else
V_314 = V_324 ;
break;
default:
F_214 ( V_318 ) ;
case V_325 :
F_215 ( V_84 -> V_77 , V_317 , V_318 ) ;
case V_326 :
V_314 = V_324 ;
break;
}
V_319:
F_216 () ;
return F_217 ( - V_314 ) ;
}
static void F_218 ( struct V_63 * V_84 ,
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
static int F_219 ( struct V_173 * V_174 ,
struct V_63 * V_84 ,
const int V_178 )
{
unsigned int V_327 = 0 , V_328 = 0 ;
struct V_1 * V_2 = V_174 -> V_2 ;
#ifdef F_184
int V_329 ;
unsigned int V_330 = 0 ;
#endif
T_2 V_258 = F_114 ( V_84 ) ;
bool V_331 = false ;
while ( F_25 ( V_328 < V_178 ) ) {
union V_85 * V_86 ;
struct V_87 * V_301 ;
struct V_216 * V_100 ;
struct V_308 V_309 ;
unsigned int V_304 ;
if ( V_258 >= V_332 ) {
F_150 ( V_84 , V_258 ) ;
V_258 = 0 ;
}
V_86 = F_70 ( V_84 , V_84 -> V_69 ) ;
V_304 = F_133 ( V_86 -> V_105 . V_106 . V_107 ) ;
if ( ! V_304 )
break;
F_220 () ;
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
if ( F_221 ( V_100 ) == - V_323 ) {
V_331 = true ;
F_218 ( V_84 , V_301 , V_304 ) ;
} else {
V_301 -> V_257 ++ ;
}
V_328 ++ ;
V_327 += V_304 ;
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
V_84 -> V_240 . V_333 ++ ;
V_301 -> V_257 ++ ;
break;
}
F_200 ( V_84 , V_301 , V_100 ) ;
V_258 ++ ;
if ( F_169 ( V_84 , V_86 , V_100 ) )
continue;
if ( F_181 ( V_84 , V_86 , V_100 ) )
continue;
V_327 += V_100 -> V_73 ;
F_161 ( V_84 , V_86 , V_100 ) ;
#ifdef F_184
if ( F_136 ( V_84 , V_86 ) ) {
V_329 = F_222 ( V_2 , V_86 , V_100 ) ;
if ( V_329 > 0 ) {
if ( ! V_330 ) {
V_330 = V_84 -> V_77 -> V_334 -
sizeof( struct V_335 ) -
sizeof( struct V_336 ) -
sizeof( struct V_337 ) ;
if ( V_330 > 512 )
V_330 &= ~ 511 ;
}
V_327 += V_329 ;
V_328 += F_158 ( V_329 ,
V_330 ) ;
}
if ( ! V_329 ) {
F_183 ( V_100 ) ;
continue;
}
}
#endif
F_167 ( V_174 , V_100 ) ;
V_328 ++ ;
}
if ( V_331 ) {
struct V_63 * V_64 = V_2 -> V_94 [ F_223 () ] ;
F_153 () ;
F_154 ( V_64 -> V_70 , V_64 -> V_155 ) ;
F_224 () ;
}
F_104 ( & V_84 -> V_187 ) ;
V_84 -> V_133 . V_153 += V_328 ;
V_84 -> V_133 . V_188 += V_327 ;
F_105 ( & V_84 -> V_187 ) ;
V_174 -> V_338 . V_177 += V_328 ;
V_174 -> V_338 . V_176 += V_327 ;
return V_328 ;
}
static void F_225 ( struct V_1 * V_2 )
{
struct V_173 * V_174 ;
int V_339 ;
T_1 V_128 ;
if ( V_2 -> V_340 > 32 ) {
T_1 V_341 = F_226 ( V_2 -> V_340 - 32 ) - 1 ;
F_74 ( & V_2 -> V_14 , V_342 , V_341 ) ;
}
for ( V_339 = 0 ; V_339 < V_2 -> V_210 ; V_339 ++ ) {
struct V_63 * V_64 ;
V_174 = V_2 -> V_174 [ V_339 ] ;
F_125 (ring, q_vector->rx)
F_76 ( V_2 , 0 , V_64 -> V_158 , V_339 ) ;
F_125 (ring, q_vector->tx)
F_76 ( V_2 , 1 , V_64 -> V_158 , V_339 ) ;
F_227 ( V_174 ) ;
}
switch ( V_2 -> V_14 . V_118 . type ) {
case V_119 :
F_76 ( V_2 , - 1 , V_343 ,
V_339 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
F_76 ( V_2 , - 1 , 1 , V_339 ) ;
break;
default:
break;
}
F_74 ( & V_2 -> V_14 , F_228 ( V_339 ) , 1950 ) ;
V_128 = V_344 ;
V_128 &= ~ ( V_345 |
V_346 |
V_347 ) ;
F_74 ( & V_2 -> V_14 , V_348 , V_128 ) ;
}
static void F_229 ( struct V_173 * V_174 ,
struct V_349 * V_350 )
{
int V_188 = V_350 -> V_176 ;
int V_153 = V_350 -> V_177 ;
T_1 V_351 ;
V_71 V_352 ;
T_4 V_353 = V_350 -> V_354 ;
if ( V_153 == 0 )
return;
V_351 = V_174 -> V_354 >> 2 ;
if ( V_351 == 0 )
return;
V_352 = V_188 / V_351 ;
switch ( V_353 ) {
case V_355 :
if ( V_352 > 10 )
V_353 = V_356 ;
break;
case V_356 :
if ( V_352 > 20 )
V_353 = V_357 ;
else if ( V_352 <= 10 )
V_353 = V_355 ;
break;
case V_357 :
if ( V_352 <= 20 )
V_353 = V_356 ;
break;
}
V_350 -> V_176 = 0 ;
V_350 -> V_177 = 0 ;
V_350 -> V_354 = V_353 ;
}
void F_227 ( struct V_173 * V_174 )
{
struct V_1 * V_2 = V_174 -> V_2 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_339 = V_174 -> V_339 ;
T_1 V_358 = V_174 -> V_354 & V_359 ;
switch ( V_2 -> V_14 . V_118 . type ) {
case V_119 :
V_358 |= ( V_358 << 16 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_358 |= V_360 ;
break;
default:
break;
}
F_74 ( V_14 , F_228 ( V_339 ) , V_358 ) ;
}
static void F_230 ( struct V_173 * V_174 )
{
T_1 V_361 = V_174 -> V_354 ;
T_4 V_362 ;
F_229 ( V_174 , & V_174 -> V_179 ) ;
F_229 ( V_174 , & V_174 -> V_338 ) ;
V_362 = F_231 ( V_174 -> V_338 . V_354 , V_174 -> V_179 . V_354 ) ;
switch ( V_362 ) {
case V_355 :
V_361 = V_363 ;
break;
case V_356 :
V_361 = V_364 ;
break;
case V_357 :
V_361 = V_365 ;
break;
default:
break;
}
if ( V_361 != V_174 -> V_354 ) {
V_361 = ( 10 * V_361 * V_174 -> V_354 ) /
( ( 9 * V_361 ) + V_174 -> V_354 ) ;
V_174 -> V_354 = V_361 ;
F_227 ( V_174 ) ;
}
}
static void F_232 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_366 = V_2 -> V_367 ;
T_3 V_368 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
if ( ! ( V_2 -> V_369 & V_370 ) )
return;
V_2 -> V_369 &= ~ V_370 ;
switch ( V_14 -> V_21 ) {
case V_371 :
if ( ! ( V_366 & V_372 ) &&
! ( V_366 & V_373 ) )
return;
if ( ! ( V_366 & V_373 ) && V_14 -> V_118 . V_374 . V_375 ) {
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
V_368 = V_14 -> V_46 . V_374 . V_377 ( V_14 ) ;
if ( V_368 != V_378 )
return;
break;
default:
if ( V_2 -> V_14 . V_118 . type >= V_122 )
return;
if ( ! ( V_366 & F_233 ( V_14 ) ) )
return;
break;
}
F_234 ( V_164 , L_69 , V_381 ) ;
V_2 -> V_367 = 0 ;
}
static void F_235 ( struct V_1 * V_2 , T_1 V_366 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ( V_2 -> V_148 & V_382 ) &&
( V_366 & F_236 ( V_14 ) ) ) {
F_234 ( V_190 , L_70 ) ;
F_74 ( V_14 , V_383 , F_236 ( V_14 ) ) ;
}
}
static void F_237 ( struct V_1 * V_2 , T_1 V_366 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! ( V_2 -> V_369 & V_384 ) )
return;
switch ( V_2 -> V_14 . V_118 . type ) {
case V_121 :
if ( ( ( V_366 & F_233 ( V_14 ) ) ||
( V_366 & V_373 ) ) &&
( ! F_14 ( V_34 , & V_2 -> V_35 ) ) ) {
V_2 -> V_367 = V_366 ;
V_2 -> V_369 |= V_370 ;
F_13 ( V_2 ) ;
return;
}
return;
case V_125 :
if ( V_366 & V_385 ) {
V_2 -> V_367 = V_366 ;
V_2 -> V_369 |= V_370 ;
F_13 ( V_2 ) ;
F_74 ( & V_2 -> V_14 , V_386 ,
V_385 ) ;
F_74 ( & V_2 -> V_14 , V_383 ,
V_385 ) ;
}
return;
case V_123 :
case V_122 :
if ( ! ( V_366 & V_387 ) )
return;
break;
default:
return;
}
F_234 ( V_164 , L_69 , V_381 ) ;
}
static inline bool F_238 ( struct V_15 * V_14 )
{
switch ( V_14 -> V_118 . type ) {
case V_119 :
if ( V_14 -> V_46 . type == V_388 )
return true ;
return false ;
case V_121 :
case V_124 :
case V_125 :
switch ( V_14 -> V_118 . V_374 . V_389 ( V_14 ) ) {
case V_390 :
case V_391 :
return true ;
default:
return false ;
}
default:
return false ;
}
}
static void F_239 ( struct V_1 * V_2 , T_1 V_366 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_392 = F_240 ( V_14 ) ;
if ( ! F_238 ( V_14 ) )
return;
if ( V_14 -> V_118 . type >= V_122 )
V_392 = V_393 ;
if ( V_366 & V_392 ) {
F_74 ( V_14 , V_383 , V_392 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_369 |= V_394 ;
V_2 -> V_395 = 0 ;
F_13 ( V_2 ) ;
}
}
if ( V_2 -> V_14 . V_118 . type == V_121 &&
( V_366 & F_236 ( V_14 ) ) ) {
F_74 ( V_14 , V_383 , F_236 ( V_14 ) ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_148 |= V_396 ;
F_13 ( V_2 ) ;
}
}
}
static void F_241 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_397 ++ ;
V_2 -> V_148 |= V_398 ;
V_2 -> V_399 = V_189 ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_74 ( V_14 , V_386 , V_400 ) ;
F_242 ( V_14 ) ;
F_13 ( V_2 ) ;
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
F_74 ( V_14 , V_401 , V_128 ) ;
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
static inline void F_245 ( struct V_1 * V_2 ,
V_71 V_127 )
{
T_1 V_128 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_128 = ( V_129 & V_127 ) ;
F_74 ( V_14 , V_386 , V_128 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_128 = ( V_127 & 0xFFFFFFFF ) ;
if ( V_128 )
F_74 ( V_14 , F_246 ( 0 ) , V_128 ) ;
V_128 = ( V_127 >> 32 ) ;
if ( V_128 )
F_74 ( V_14 , F_246 ( 1 ) , V_128 ) ;
break;
default:
break;
}
}
static inline void F_247 ( struct V_1 * V_2 , bool V_402 ,
bool V_403 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_128 = ( V_344 & ~ V_129 ) ;
if ( V_2 -> V_148 & V_398 )
V_128 &= ~ V_347 ;
if ( V_2 -> V_369 & V_384 )
switch ( V_2 -> V_14 . V_118 . type ) {
case V_121 :
V_128 |= F_248 ( V_14 ) ;
break;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_128 |= V_404 ;
break;
default:
break;
}
if ( V_2 -> V_148 & V_382 )
V_128 |= F_249 ( V_14 ) ;
switch ( V_2 -> V_14 . V_118 . type ) {
case V_121 :
V_128 |= F_249 ( V_14 ) ;
V_128 |= F_250 ( V_14 ) ;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
if ( V_2 -> V_14 . V_21 == V_405 ||
V_2 -> V_14 . V_21 == V_406 ||
V_2 -> V_14 . V_21 == V_407 )
V_128 |= F_248 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_14 . V_46 . type == V_408 )
V_128 |= V_393 ;
V_128 |= V_409 ;
V_128 |= V_346 ;
break;
default:
break;
}
if ( ( V_2 -> V_148 & V_410 ) &&
! ( V_2 -> V_369 & V_411 ) )
V_128 |= V_412 ;
F_74 ( & V_2 -> V_14 , V_401 , V_128 ) ;
if ( V_402 )
F_243 ( V_2 , ~ 0 ) ;
if ( V_403 )
F_242 ( & V_2 -> V_14 ) ;
}
static T_10 F_251 ( int V_413 , void * V_103 )
{
struct V_1 * V_2 = V_103 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_366 ;
V_366 = F_40 ( V_14 , V_130 ) ;
V_366 &= 0xFFFF0000 ;
F_74 ( V_14 , V_383 , V_366 ) ;
if ( V_366 & V_373 )
F_241 ( V_2 ) ;
if ( V_366 & V_414 )
F_252 ( V_2 ) ;
switch ( V_14 -> V_118 . type ) {
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
if ( V_14 -> V_46 . type == V_408 &&
( V_366 & V_393 ) ) {
V_2 -> V_369 |= V_415 ;
F_13 ( V_2 ) ;
F_74 ( V_14 , V_383 ,
V_393 ) ;
}
if ( V_366 & V_416 ) {
F_109 ( V_417 , L_71 ) ;
F_91 ( V_163 , & V_2 -> V_35 ) ;
F_13 ( V_2 ) ;
F_74 ( V_14 , V_383 , V_416 ) ;
}
if ( V_366 & V_418 ) {
int V_419 = 0 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ ) {
struct V_63 * V_64 = V_2 -> V_92 [ V_49 ] ;
if ( F_253 ( V_420 ,
& V_64 -> V_35 ) )
V_419 ++ ;
}
if ( V_419 ) {
F_74 ( V_14 , V_386 , V_421 ) ;
V_2 -> V_369 |= V_411 ;
F_13 ( V_2 ) ;
}
}
F_239 ( V_2 , V_366 ) ;
F_237 ( V_2 , V_366 ) ;
break;
default:
break;
}
F_235 ( V_2 , V_366 ) ;
if ( F_23 ( V_366 & V_422 ) )
F_254 ( V_2 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_247 ( V_2 , false , false ) ;
return V_423 ;
}
static T_10 F_255 ( int V_413 , void * V_103 )
{
struct V_173 * V_174 = V_103 ;
if ( V_174 -> V_338 . V_64 || V_174 -> V_179 . V_64 )
F_256 ( & V_174 -> V_277 ) ;
return V_423 ;
}
int F_257 ( struct V_424 * V_277 , int V_178 )
{
struct V_173 * V_174 =
F_258 ( V_277 , struct V_173 , V_277 ) ;
struct V_1 * V_2 = V_174 -> V_2 ;
struct V_63 * V_64 ;
int V_425 , V_426 = 0 ;
bool V_427 = true ;
#ifdef F_259
if ( V_2 -> V_148 & V_196 )
F_123 ( V_174 ) ;
#endif
F_125 (ring, q_vector->tx) {
if ( ! F_94 ( V_174 , V_64 , V_178 ) )
V_427 = false ;
}
if ( V_178 <= 0 )
return V_178 ;
if ( V_174 -> V_338 . V_98 > 1 )
V_425 = F_231 ( V_178 / V_174 -> V_338 . V_98 , 1 ) ;
else
V_425 = V_178 ;
F_125 (ring, q_vector->rx) {
int V_428 = F_219 ( V_174 , V_64 ,
V_425 ) ;
V_426 += V_428 ;
if ( V_428 >= V_425 )
V_427 = false ;
}
if ( ! V_427 )
return V_178 ;
F_260 ( V_277 , V_426 ) ;
if ( V_2 -> V_429 & 1 )
F_230 ( V_174 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_243 ( V_2 , F_261 ( V_174 -> V_339 ) ) ;
return F_262 ( V_426 , V_178 - 1 ) ;
}
static int F_263 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
unsigned int V_430 = 0 , V_431 = 0 ;
int V_432 , V_17 ;
for ( V_432 = 0 ; V_432 < V_2 -> V_210 ; V_432 ++ ) {
struct V_173 * V_174 = V_2 -> V_174 [ V_432 ] ;
struct V_433 * V_434 = & V_2 -> V_435 [ V_432 ] ;
if ( V_174 -> V_179 . V_64 && V_174 -> V_338 . V_64 ) {
snprintf ( V_174 -> V_59 , sizeof( V_174 -> V_59 ) ,
L_72 , V_77 -> V_59 , V_430 ++ ) ;
V_431 ++ ;
} else if ( V_174 -> V_338 . V_64 ) {
snprintf ( V_174 -> V_59 , sizeof( V_174 -> V_59 ) ,
L_73 , V_77 -> V_59 , V_430 ++ ) ;
} else if ( V_174 -> V_179 . V_64 ) {
snprintf ( V_174 -> V_59 , sizeof( V_174 -> V_59 ) ,
L_74 , V_77 -> V_59 , V_431 ++ ) ;
} else {
continue;
}
V_17 = F_264 ( V_434 -> V_432 , & F_255 , 0 ,
V_174 -> V_59 , V_174 ) ;
if ( V_17 ) {
F_107 ( V_190 , L_75
L_76 , V_17 ) ;
goto V_436;
}
if ( V_2 -> V_148 & V_410 ) {
F_265 ( V_434 -> V_432 ,
& V_174 -> V_437 ) ;
}
}
V_17 = F_264 ( V_2 -> V_435 [ V_432 ] . V_432 ,
F_251 , 0 , V_77 -> V_59 , V_2 ) ;
if ( V_17 ) {
F_107 ( V_190 , L_77 , V_17 ) ;
goto V_436;
}
return 0 ;
V_436:
while ( V_432 ) {
V_432 -- ;
F_265 ( V_2 -> V_435 [ V_432 ] . V_432 ,
NULL ) ;
F_266 ( V_2 -> V_435 [ V_432 ] . V_432 ,
V_2 -> V_174 [ V_432 ] ) ;
}
V_2 -> V_148 &= ~ V_438 ;
F_267 ( V_2 -> V_9 ) ;
F_268 ( V_2 -> V_435 ) ;
V_2 -> V_435 = NULL ;
return V_17 ;
}
static T_10 F_269 ( int V_413 , void * V_103 )
{
struct V_1 * V_2 = V_103 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_173 * V_174 = V_2 -> V_174 [ 0 ] ;
T_1 V_366 ;
F_74 ( V_14 , V_386 , V_439 ) ;
V_366 = F_40 ( V_14 , V_383 ) ;
if ( ! V_366 ) {
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_247 ( V_2 , true , true ) ;
return V_440 ;
}
if ( V_366 & V_373 )
F_241 ( V_2 ) ;
switch ( V_14 -> V_118 . type ) {
case V_121 :
F_239 ( V_2 , V_366 ) ;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
if ( V_366 & V_416 ) {
F_109 ( V_417 , L_71 ) ;
F_91 ( V_163 , & V_2 -> V_35 ) ;
F_13 ( V_2 ) ;
F_74 ( V_14 , V_383 , V_416 ) ;
}
F_237 ( V_2 , V_366 ) ;
break;
default:
break;
}
F_235 ( V_2 , V_366 ) ;
if ( F_23 ( V_366 & V_422 ) )
F_254 ( V_2 ) ;
F_256 ( & V_174 -> V_277 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_247 ( V_2 , false , false ) ;
return V_423 ;
}
static int F_270 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
int V_17 ;
if ( V_2 -> V_148 & V_438 )
V_17 = F_263 ( V_2 ) ;
else if ( V_2 -> V_148 & V_441 )
V_17 = F_264 ( V_2 -> V_9 -> V_413 , F_269 , 0 ,
V_77 -> V_59 , V_2 ) ;
else
V_17 = F_264 ( V_2 -> V_9 -> V_413 , F_269 , V_442 ,
V_77 -> V_59 , V_2 ) ;
if ( V_17 )
F_107 ( V_190 , L_78 , V_17 ) ;
return V_17 ;
}
static void F_271 ( struct V_1 * V_2 )
{
int V_432 ;
if ( ! ( V_2 -> V_148 & V_438 ) ) {
F_266 ( V_2 -> V_9 -> V_413 , V_2 ) ;
return;
}
if ( ! V_2 -> V_435 )
return;
for ( V_432 = 0 ; V_432 < V_2 -> V_210 ; V_432 ++ ) {
struct V_173 * V_174 = V_2 -> V_174 [ V_432 ] ;
struct V_433 * V_434 = & V_2 -> V_435 [ V_432 ] ;
if ( ! V_174 -> V_338 . V_64 && ! V_174 -> V_179 . V_64 )
continue;
F_265 ( V_434 -> V_432 , NULL ) ;
F_266 ( V_434 -> V_432 , V_174 ) ;
}
F_266 ( V_2 -> V_435 [ V_432 ] . V_432 , V_2 ) ;
}
static inline void F_272 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_118 . type ) {
case V_119 :
F_74 ( & V_2 -> V_14 , V_386 , ~ 0 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
F_74 ( & V_2 -> V_14 , V_386 , 0xFFFF0000 ) ;
F_74 ( & V_2 -> V_14 , F_246 ( 0 ) , ~ 0 ) ;
F_74 ( & V_2 -> V_14 , F_246 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_242 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_148 & V_438 ) {
int V_432 ;
for ( V_432 = 0 ; V_432 < V_2 -> V_210 ; V_432 ++ )
F_273 ( V_2 -> V_435 [ V_432 ] . V_432 ) ;
F_273 ( V_2 -> V_435 [ V_432 ++ ] . V_432 ) ;
} else {
F_273 ( V_2 -> V_9 -> V_413 ) ;
}
}
static void F_274 ( struct V_1 * V_2 )
{
struct V_173 * V_174 = V_2 -> V_174 [ 0 ] ;
F_227 ( V_174 ) ;
F_76 ( V_2 , 0 , 0 , 0 ) ;
F_76 ( V_2 , 1 , 0 , 0 ) ;
F_109 ( V_14 , L_79 ) ;
}
void F_275 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_71 V_443 = V_64 -> V_72 ;
int V_444 = 10 ;
T_1 V_445 = V_446 ;
T_4 V_158 = V_64 -> V_158 ;
F_74 ( V_14 , F_53 ( V_158 ) , 0 ) ;
F_242 ( V_14 ) ;
F_74 ( V_14 , F_48 ( V_158 ) ,
( V_443 & F_276 ( 32 ) ) ) ;
F_74 ( V_14 , F_49 ( V_158 ) , ( V_443 >> 32 ) ) ;
F_74 ( V_14 , F_50 ( V_158 ) ,
V_64 -> V_98 * sizeof( union V_78 ) ) ;
F_74 ( V_14 , F_51 ( V_158 ) , 0 ) ;
F_74 ( V_14 , F_52 ( V_158 ) , 0 ) ;
V_64 -> V_155 = V_2 -> V_447 + F_52 ( V_158 ) ;
if ( ! V_64 -> V_174 || ( V_64 -> V_174 -> V_354 < V_363 ) )
V_445 |= 1u << 16 ;
else
V_445 |= 8u << 16 ;
V_445 |= ( 1u << 8 ) |
32 ;
if ( V_2 -> V_148 & V_410 ) {
V_64 -> V_448 = V_2 -> V_448 ;
V_64 -> V_449 = 0 ;
F_91 ( V_420 , & V_64 -> V_35 ) ;
} else {
V_64 -> V_448 = 0 ;
}
if ( ! F_15 ( V_450 , & V_64 -> V_35 ) ) {
struct V_173 * V_174 = V_64 -> V_174 ;
if ( V_174 )
F_277 ( V_64 -> V_77 ,
& V_174 -> V_437 ,
V_64 -> V_96 ) ;
}
F_37 ( V_141 , & V_64 -> V_35 ) ;
memset ( V_64 -> V_68 , 0 ,
sizeof( struct V_66 ) * V_64 -> V_98 ) ;
F_74 ( V_14 , F_53 ( V_158 ) , V_445 ) ;
if ( V_14 -> V_118 . type == V_119 &&
! ( F_40 ( V_14 , V_451 ) & V_452 ) )
return;
do {
F_278 ( 1000 , 2000 ) ;
V_445 = F_40 ( V_14 , F_53 ( V_158 ) ) ;
} while ( -- V_444 && ! ( V_445 & V_446 ) );
if ( ! V_444 )
F_279 ( V_14 , L_80 , V_158 ) ;
}
static void F_280 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_453 , V_454 ;
T_4 V_455 = F_281 ( V_2 -> V_77 ) ;
if ( V_14 -> V_118 . type == V_119 )
return;
V_453 = F_40 ( V_14 , V_456 ) ;
V_453 |= V_457 ;
F_74 ( V_14 , V_456 , V_453 ) ;
if ( V_2 -> V_148 & V_458 ) {
V_454 = V_459 ;
if ( V_455 > 4 )
V_454 |= V_460 | V_461 ;
else if ( V_455 > 1 )
V_454 |= V_460 | V_462 ;
else if ( V_2 -> V_463 [ V_464 ] . V_128 ==
V_465 )
V_454 |= V_466 ;
else
V_454 |= V_467 ;
} else {
if ( V_455 > 4 )
V_454 = V_460 | V_461 ;
else if ( V_455 > 1 )
V_454 = V_460 | V_462 ;
else
V_454 = V_468 ;
}
F_74 ( V_14 , V_469 , V_454 ) ;
if ( V_455 ) {
T_1 V_470 = F_40 ( V_14 , V_471 ) ;
V_470 |= V_472 ;
F_74 ( V_14 , V_471 , V_470 ) ;
}
V_453 &= ~ V_457 ;
F_74 ( V_14 , V_456 , V_453 ) ;
}
static void F_282 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_473 ;
T_1 V_49 ;
F_280 ( V_2 ) ;
if ( V_14 -> V_118 . type != V_119 ) {
V_473 = F_40 ( V_14 , V_474 ) ;
V_473 |= V_475 ;
F_74 ( V_14 , V_474 , V_473 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ )
F_275 ( V_2 , V_2 -> V_92 [ V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ )
F_275 ( V_2 , V_2 -> V_94 [ V_49 ] ) ;
}
static void F_283 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_158 = V_64 -> V_158 ;
T_1 V_476 = F_40 ( V_14 , F_39 ( V_158 ) ) ;
V_476 |= V_477 ;
F_74 ( V_14 , F_39 ( V_158 ) , V_476 ) ;
}
static void F_284 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_158 = V_64 -> V_158 ;
T_1 V_476 = F_40 ( V_14 , F_39 ( V_158 ) ) ;
V_476 &= ~ V_477 ;
F_74 ( V_14 , F_39 ( V_158 ) , V_476 ) ;
}
static void F_285 ( struct V_1 * V_2 ,
struct V_63 * V_84 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_476 ;
T_4 V_158 = V_84 -> V_158 ;
if ( V_14 -> V_118 . type == V_119 ) {
T_2 V_128 = V_2 -> V_463 [ V_478 ] . V_128 ;
V_158 &= V_128 ;
}
V_476 = V_293 << V_479 ;
if ( F_14 ( V_480 , & V_84 -> V_35 ) )
V_476 |= V_481 >> V_482 ;
else
V_476 |= V_483 >> V_482 ;
V_476 |= V_484 ;
F_74 ( V_14 , F_39 ( V_158 ) , V_476 ) ;
}
T_1 F_286 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_118 . type < V_123 )
return 128 ;
else if ( V_2 -> V_148 & V_458 )
return 64 ;
else
return 512 ;
}
void F_287 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < 10 ; V_49 ++ )
F_74 ( V_14 , F_288 ( V_49 ) , V_2 -> V_485 [ V_49 ] ) ;
}
static inline int F_289 ( struct V_1 * V_2 )
{
T_1 * V_485 ;
if ( ! V_2 -> V_485 ) {
V_485 = F_290 ( V_486 , V_487 ) ;
if ( F_23 ( ! V_485 ) )
return - V_488 ;
F_291 ( V_485 , V_486 ) ;
V_2 -> V_485 = V_485 ;
}
return 0 ;
}
void F_292 ( struct V_1 * V_2 )
{
T_1 V_49 , V_489 = F_286 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_490 = 0 ;
T_1 V_491 ;
T_4 * V_492 = V_2 -> V_493 ;
if ( V_2 -> V_14 . V_118 . type == V_119 )
V_491 = 0x11 ;
else
V_491 = 0x1 ;
for ( V_49 = 0 ; V_49 < V_489 ; V_49 ++ ) {
V_490 |= V_491 * V_492 [ V_49 ] << ( V_49 & 0x3 ) * 8 ;
if ( ( V_49 & 3 ) == 3 ) {
if ( V_49 < 128 )
F_74 ( V_14 , F_293 ( V_49 >> 2 ) , V_490 ) ;
else
F_74 ( V_14 , F_294 ( ( V_49 >> 2 ) - 32 ) ,
V_490 ) ;
V_490 = 0 ;
}
}
}
static void F_295 ( struct V_1 * V_2 )
{
T_1 V_49 , V_489 = F_286 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_494 = 0 ;
unsigned int V_495 = V_2 -> V_340 ;
for ( V_49 = 0 ; V_49 < V_489 ; V_49 ++ ) {
V_494 |= ( T_1 ) V_2 -> V_493 [ V_49 ] << ( V_49 & 0x3 ) * 8 ;
if ( ( V_49 & 3 ) == 3 ) {
F_74 ( V_14 , F_296 ( V_49 >> 2 , V_495 ) ,
V_494 ) ;
V_494 = 0 ;
}
}
}
static void F_297 ( struct V_1 * V_2 )
{
T_1 V_49 , V_60 ;
T_1 V_489 = F_286 ( V_2 ) ;
T_2 V_496 = V_2 -> V_463 [ V_478 ] . V_497 ;
if ( ( V_2 -> V_148 & V_458 ) && ( V_496 < 4 ) )
V_496 = 4 ;
F_287 ( V_2 ) ;
memset ( V_2 -> V_493 , 0 , sizeof( V_2 -> V_493 ) ) ;
for ( V_49 = 0 , V_60 = 0 ; V_49 < V_489 ; V_49 ++ , V_60 ++ ) {
if ( V_60 == V_496 )
V_60 = 0 ;
V_2 -> V_493 [ V_49 ] = V_60 ;
}
F_292 ( V_2 ) ;
}
static void F_298 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_496 = V_2 -> V_463 [ V_478 ] . V_497 ;
unsigned int V_495 = V_2 -> V_340 ;
int V_49 , V_60 ;
for ( V_49 = 0 ; V_49 < 10 ; V_49 ++ )
F_74 ( V_14 , F_299 ( V_49 , V_495 ) ,
* ( V_2 -> V_485 + V_49 ) ) ;
for ( V_49 = 0 , V_60 = 0 ; V_49 < 64 ; V_49 ++ , V_60 ++ ) {
if ( V_60 == V_496 )
V_60 = 0 ;
V_2 -> V_493 [ V_49 ] = V_60 ;
}
F_295 ( V_2 ) ;
}
static void F_300 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_498 = 0 , V_499 = 0 , V_500 = 0 ;
T_1 V_501 ;
V_501 = F_40 ( V_14 , V_502 ) ;
V_501 |= V_503 ;
F_74 ( V_14 , V_502 , V_501 ) ;
if ( V_2 -> V_14 . V_118 . type == V_119 ) {
if ( V_2 -> V_463 [ V_478 ] . V_128 )
V_498 = V_504 ;
} else {
T_4 V_455 = F_281 ( V_2 -> V_77 ) ;
if ( V_2 -> V_148 & V_458 ) {
if ( V_455 > 4 )
V_498 = V_505 ;
else if ( V_455 > 1 )
V_498 = V_506 ;
else if ( V_2 -> V_463 [ V_464 ] . V_128 ==
V_465 )
V_498 = V_507 ;
else
V_498 = V_508 ;
V_498 |= V_509 ;
} else {
if ( V_455 > 4 )
V_498 = V_510 ;
else if ( V_455 > 1 )
V_498 = V_511 ;
else
V_498 = V_504 ;
}
}
V_499 |= V_512 |
V_513 |
V_514 |
V_515 ;
if ( V_2 -> V_369 & V_516 )
V_499 |= V_517 ;
if ( V_2 -> V_369 & V_518 )
V_499 |= V_519 ;
if ( ( V_14 -> V_118 . type >= V_123 ) &&
( V_2 -> V_148 & V_458 ) ) {
unsigned int V_495 = V_2 -> V_340 ;
V_498 |= V_520 ;
F_74 ( V_14 , V_521 , V_498 ) ;
F_298 ( V_2 ) ;
V_500 = V_504 ;
V_500 |= V_499 ;
F_74 ( V_14 , F_301 ( V_495 ) , V_500 ) ;
} else {
F_297 ( V_2 ) ;
V_498 |= V_499 ;
F_74 ( V_14 , V_521 , V_498 ) ;
}
}
static void F_302 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_522 ;
T_4 V_158 = V_64 -> V_158 ;
if ( ! F_170 ( V_64 ) )
return;
V_522 = F_40 ( V_14 , F_303 ( V_158 ) ) ;
V_522 |= V_523 ;
V_522 |= V_524 ;
F_74 ( V_14 , F_303 ( V_158 ) , V_522 ) ;
}
static void F_304 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_444 = V_525 ;
T_1 V_526 ;
T_4 V_158 = V_64 -> V_158 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
if ( V_14 -> V_118 . type == V_119 &&
! ( F_40 ( V_14 , V_451 ) & V_452 ) )
return;
do {
F_278 ( 1000 , 2000 ) ;
V_526 = F_40 ( V_14 , F_45 ( V_158 ) ) ;
} while ( -- V_444 && ! ( V_526 & V_527 ) );
if ( ! V_444 ) {
F_107 ( V_164 , L_81
L_82 , V_158 ) ;
}
}
void F_305 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_444 = V_525 ;
T_1 V_526 ;
T_4 V_158 = V_64 -> V_158 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
V_526 = F_40 ( V_14 , F_45 ( V_158 ) ) ;
V_526 &= ~ V_527 ;
F_74 ( V_14 , F_45 ( V_158 ) , V_526 ) ;
if ( V_14 -> V_118 . type == V_119 &&
! ( F_40 ( V_14 , V_451 ) & V_452 ) )
return;
do {
F_26 ( 10 ) ;
V_526 = F_40 ( V_14 , F_45 ( V_158 ) ) ;
} while ( -- V_444 && ( V_526 & V_527 ) );
if ( ! V_444 ) {
F_107 ( V_164 , L_83
L_82 , V_158 ) ;
}
}
void F_306 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
union V_85 * V_86 ;
V_71 V_528 = V_64 -> V_72 ;
T_1 V_526 ;
T_4 V_158 = V_64 -> V_158 ;
V_526 = F_40 ( V_14 , F_45 ( V_158 ) ) ;
F_305 ( V_2 , V_64 ) ;
F_74 ( V_14 , F_46 ( V_158 ) , ( V_528 & F_276 ( 32 ) ) ) ;
F_74 ( V_14 , F_47 ( V_158 ) , ( V_528 >> 32 ) ) ;
F_74 ( V_14 , F_42 ( V_158 ) ,
V_64 -> V_98 * sizeof( union V_85 ) ) ;
F_242 ( V_14 ) ;
F_74 ( V_14 , F_43 ( V_158 ) , 0 ) ;
F_74 ( V_14 , F_44 ( V_158 ) , 0 ) ;
V_64 -> V_155 = V_2 -> V_447 + F_44 ( V_158 ) ;
F_285 ( V_2 , V_64 ) ;
F_302 ( V_2 , V_64 ) ;
if ( V_14 -> V_118 . type == V_119 ) {
V_526 &= ~ 0x3FFFFF ;
V_526 |= 0x080420 ;
#if ( V_302 < 8192 )
} else {
V_526 &= ~ ( V_529 |
V_530 ) ;
if ( F_142 ( V_64 ) &&
! F_14 ( V_480 , & V_64 -> V_35 ) )
V_526 |= V_531 |
V_530 ;
#endif
}
memset ( V_64 -> V_88 , 0 ,
sizeof( struct V_87 ) * V_64 -> V_98 ) ;
V_86 = F_70 ( V_64 , 0 ) ;
V_86 -> V_105 . V_106 . V_107 = 0 ;
V_526 |= V_527 ;
F_74 ( V_14 , F_45 ( V_158 ) , V_526 ) ;
F_304 ( V_2 , V_64 ) ;
F_150 ( V_64 , F_114 ( V_64 ) ) ;
}
static void F_307 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_496 = V_2 -> V_463 [ V_478 ] . V_497 ;
T_2 V_532 ;
T_1 V_533 = V_534 |
V_535 |
V_536 |
V_537 |
V_538 ;
if ( V_14 -> V_118 . type == V_119 )
return;
if ( V_496 > 3 )
V_533 |= 2u << 29 ;
else if ( V_496 > 1 )
V_533 |= 1u << 29 ;
F_308 (pool, &adapter->fwd_bitmask, 32 )
F_74 ( V_14 , F_309 ( F_310 ( V_532 ) ) , V_533 ) ;
}
static void F_311 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_195 , V_539 ;
T_1 V_540 , V_541 ;
int V_49 ;
if ( ! ( V_2 -> V_148 & V_458 ) )
return;
V_541 = F_40 ( V_14 , V_542 ) ;
V_541 |= V_543 ;
V_541 &= ~ V_544 ;
V_541 |= F_310 ( 0 ) << V_545 ;
V_541 |= V_546 ;
F_74 ( V_14 , V_542 , V_541 ) ;
V_539 = F_310 ( 0 ) % 32 ;
V_195 = ( F_310 ( 0 ) >= 32 ) ? 1 : 0 ;
F_74 ( V_14 , F_312 ( V_195 ) , F_313 ( 31 , V_539 ) ) ;
F_74 ( V_14 , F_312 ( V_195 ^ 1 ) , V_195 - 1 ) ;
F_74 ( V_14 , F_314 ( V_195 ) , F_313 ( 31 , V_539 ) ) ;
F_74 ( V_14 , F_314 ( V_195 ^ 1 ) , V_195 - 1 ) ;
if ( V_2 -> V_547 == V_548 )
F_74 ( V_14 , V_549 , V_550 ) ;
V_14 -> V_118 . V_374 . V_551 ( V_14 , 0 , F_310 ( 0 ) ) ;
V_2 -> V_369 &= ~ V_552 ;
switch ( V_2 -> V_463 [ V_464 ] . V_128 ) {
case V_553 :
V_540 = V_554 ;
break;
case V_465 :
V_540 = V_555 ;
break;
default:
V_540 = V_556 ;
break;
}
F_74 ( V_14 , V_557 , V_540 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_340 ; V_49 ++ ) {
F_315 ( V_2 -> V_77 , V_49 ,
V_2 -> V_558 [ V_49 ] . V_559 ) ;
F_316 ( V_2 -> V_77 , V_49 ,
V_2 -> V_558 [ V_49 ] . V_560 ) ;
}
}
static void F_317 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_76 * V_77 = V_2 -> V_77 ;
int V_561 = V_77 -> V_334 + V_562 + V_563 ;
struct V_63 * V_84 ;
int V_49 ;
T_1 V_564 , V_565 ;
#ifdef F_184
if ( ( V_2 -> V_148 & V_566 ) &&
( V_561 < V_567 ) )
V_561 = V_567 ;
#endif
if ( V_561 < ( V_568 + V_563 ) )
V_561 = ( V_568 + V_563 ) ;
V_564 = F_40 ( V_14 , V_569 ) ;
if ( V_561 != ( V_564 >> V_570 ) ) {
V_564 &= ~ V_571 ;
V_564 |= V_561 << V_570 ;
F_74 ( V_14 , V_569 , V_564 ) ;
}
V_565 = F_40 ( V_14 , V_572 ) ;
V_565 |= V_573 ;
F_74 ( V_14 , V_572 , V_565 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
V_84 = V_2 -> V_84 [ V_49 ] ;
F_318 ( V_84 ) ;
F_37 ( V_480 , & V_84 -> V_35 ) ;
F_37 ( V_574 , & V_84 -> V_35 ) ;
if ( V_2 -> V_369 & V_575 )
F_319 ( V_84 ) ;
if ( F_14 ( V_230 , & V_84 -> V_35 ) )
F_91 ( V_480 , & V_84 -> V_35 ) ;
F_37 ( V_574 , & V_84 -> V_35 ) ;
if ( V_2 -> V_369 & V_576 )
continue;
F_91 ( V_574 , & V_84 -> V_35 ) ;
#if ( V_302 < 8192 )
if ( V_2 -> V_369 & V_575 )
F_91 ( V_480 , & V_84 -> V_35 ) ;
if ( V_577 ||
( V_561 > ( V_568 + V_563 ) ) )
F_91 ( V_480 , & V_84 -> V_35 ) ;
#endif
}
}
static void F_320 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_578 = F_40 ( V_14 , V_579 ) ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_578 |= V_580 ;
break;
case V_123 :
case V_124 :
case V_125 :
if ( V_2 -> V_340 )
V_578 |= V_581 ;
case V_121 :
case V_122 :
F_74 ( V_14 , V_582 ,
( V_583 | F_40 ( V_14 , V_582 ) ) ) ;
V_578 &= ~ V_584 ;
V_578 |= ( V_585 | V_586 ) ;
V_578 |= V_587 ;
break;
default:
return;
}
F_74 ( V_14 , V_579 , V_578 ) ;
}
static void F_321 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
T_1 V_201 , V_588 ;
V_14 -> V_118 . V_374 . V_589 ( V_14 ) ;
F_307 ( V_2 ) ;
F_320 ( V_2 ) ;
V_588 = F_40 ( V_14 , V_590 ) ;
V_588 &= ~ V_591 ;
if ( ! ( V_2 -> V_369 & V_575 ) )
V_588 |= V_591 ;
V_588 |= ( V_592 | V_593 ) ;
F_74 ( V_14 , V_590 , V_588 ) ;
F_300 ( V_2 ) ;
F_317 ( V_2 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ )
F_306 ( V_2 , V_2 -> V_84 [ V_49 ] ) ;
V_201 = F_40 ( V_14 , V_594 ) ;
if ( V_14 -> V_118 . type == V_119 )
V_201 |= V_595 ;
V_201 |= V_596 ;
V_14 -> V_118 . V_374 . V_597 ( V_14 , V_201 ) ;
}
static int F_322 ( struct V_76 * V_77 ,
T_11 V_598 , T_2 V_273 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! V_273 || ! ( V_2 -> V_369 & V_552 ) )
V_14 -> V_118 . V_374 . V_599 ( & V_2 -> V_14 , V_273 , F_310 ( 0 ) , true , ! ! V_273 ) ;
F_91 ( V_273 , V_2 -> V_600 ) ;
return 0 ;
}
static int F_323 ( struct V_15 * V_14 , T_1 V_274 )
{
T_1 V_601 ;
int V_602 ;
if ( V_274 == 0 )
return 0 ;
for ( V_602 = V_603 ; -- V_602 ; ) {
V_601 = F_40 ( V_14 , F_324 ( V_602 ) ) ;
if ( ( V_601 & V_604 ) == V_274 )
break;
}
return V_602 ;
}
void F_325 ( struct V_1 * V_2 , T_1 V_273 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_605 , V_606 ;
int V_602 ;
V_602 = F_323 ( V_14 , V_273 ) ;
if ( ! V_602 )
return;
V_606 = V_602 * 2 + ( F_310 ( 0 ) / 32 ) ;
V_605 = ~ F_226 ( F_310 ( 0 ) % 32 ) ;
V_605 &= F_40 ( V_14 , F_326 ( V_606 ) ) ;
if ( ! V_605 && ! F_40 ( V_14 , F_326 ( V_606 ^ 1 ) ) ) {
if ( ! ( V_2 -> V_369 & V_552 ) )
F_74 ( V_14 , F_326 ( V_606 ) , 0 ) ;
F_74 ( V_14 , F_324 ( V_602 ) , 0 ) ;
}
}
static int F_327 ( struct V_76 * V_77 ,
T_11 V_598 , T_2 V_273 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_273 && ! ( V_2 -> V_369 & V_552 ) )
V_14 -> V_118 . V_374 . V_599 ( V_14 , V_273 , F_310 ( 0 ) , false , true ) ;
F_37 ( V_273 , V_2 -> V_600 ) ;
return 0 ;
}
static void F_328 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_607 ;
int V_49 , V_60 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_607 = F_40 ( V_14 , V_608 ) ;
V_607 &= ~ V_609 ;
F_74 ( V_14 , V_608 , V_607 ) ;
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
V_607 = F_40 ( V_14 , F_45 ( V_60 ) ) ;
V_607 &= ~ V_610 ;
F_74 ( V_14 , F_45 ( V_60 ) , V_607 ) ;
}
break;
default:
break;
}
}
static void F_329 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_607 ;
int V_49 , V_60 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_607 = F_40 ( V_14 , V_608 ) ;
V_607 |= V_609 ;
F_74 ( V_14 , V_608 , V_607 ) ;
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
V_607 = F_40 ( V_14 , F_45 ( V_60 ) ) ;
V_607 |= V_610 ;
F_74 ( V_14 , F_45 ( V_60 ) , V_607 ) ;
}
break;
default:
break;
}
}
static void F_330 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_607 , V_49 ;
V_607 = F_40 ( V_14 , V_608 ) ;
if ( V_2 -> V_148 & V_611 ) {
V_607 |= V_612 ;
F_74 ( V_14 , V_608 , V_607 ) ;
} else {
V_607 &= ~ V_612 ;
F_74 ( V_14 , V_608 , V_607 ) ;
return;
}
if ( V_14 -> V_118 . type == V_119 )
return;
if ( V_2 -> V_369 & V_552 )
return;
V_2 -> V_369 |= V_552 ;
for ( V_49 = V_603 ; -- V_49 ; ) {
T_1 V_195 = F_326 ( V_49 * 2 + F_310 ( 0 ) / 32 ) ;
T_1 V_613 = F_40 ( V_14 , V_195 ) ;
V_613 |= F_226 ( F_310 ( 0 ) % 32 ) ;
F_74 ( V_14 , V_195 , V_613 ) ;
}
for ( V_49 = V_14 -> V_118 . V_614 ; V_49 -- ; )
F_74 ( V_14 , F_331 ( V_49 ) , ~ 0U ) ;
}
static void F_332 ( struct V_1 * V_2 , T_1 V_615 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_616 [ V_617 ] = { 0 } ;
T_1 V_618 = V_615 * 32 ;
T_1 V_619 = V_618 + ( V_617 * 32 ) ;
T_1 V_49 , V_273 , V_606 , V_605 ;
for ( V_49 = V_603 ; -- V_49 ; ) {
T_1 V_601 = F_40 ( V_14 , F_324 ( V_49 ) ) ;
V_273 = V_601 & V_604 ;
if ( V_273 < V_618 || V_273 >= V_619 )
continue;
if ( V_601 ) {
V_616 [ ( V_273 - V_618 ) / 32 ] |= F_226 ( V_273 % 32 ) ;
if ( F_14 ( V_273 , V_2 -> V_600 ) )
continue;
}
V_606 = V_49 * 2 + F_310 ( 0 ) / 32 ;
V_605 = ~ F_226 ( F_310 ( 0 ) % 32 ) ;
V_605 &= F_40 ( V_14 , F_326 ( V_606 ) ) ;
F_74 ( V_14 , F_326 ( V_606 ) , V_605 ) ;
}
for ( V_49 = V_617 ; V_49 -- ; ) {
V_273 = ( V_615 + V_49 ) * 32 ;
V_606 = V_273 / V_620 ;
V_605 = V_273 % V_620 ;
V_616 [ V_49 ] |= V_2 -> V_600 [ V_606 ] >> V_605 ;
F_74 ( V_14 , F_331 ( V_615 + V_49 ) , V_616 [ V_49 ] ) ;
}
}
static void F_333 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_607 , V_49 ;
V_607 = F_40 ( V_14 , V_608 ) ;
V_607 |= V_612 ;
F_74 ( V_14 , V_608 , V_607 ) ;
if ( ! ( V_2 -> V_148 & V_611 ) ||
V_14 -> V_118 . type == V_119 )
return;
if ( ! ( V_2 -> V_369 & V_552 ) )
return;
V_2 -> V_369 &= ~ V_552 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_614 ; V_49 += V_617 )
F_332 ( V_2 , V_49 ) ;
}
static void F_334 ( struct V_1 * V_2 )
{
T_2 V_273 = 1 ;
F_322 ( V_2 -> V_77 , F_164 ( V_275 ) , 0 ) ;
F_335 (vid, adapter->active_vlans, VLAN_N_VID)
F_322 ( V_2 -> V_77 , F_164 ( V_275 ) , V_273 ) ;
}
static int F_336 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! F_63 ( V_77 ) )
return 0 ;
if ( V_14 -> V_118 . V_374 . V_621 )
V_14 -> V_118 . V_374 . V_621 ( V_14 , V_77 ) ;
else
return - V_488 ;
#ifdef F_337
F_338 ( V_2 ) ;
#endif
return F_339 ( V_77 ) ;
}
void F_340 ( struct V_1 * V_2 )
{
struct V_622 * V_623 = & V_2 -> V_623 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_624 ; V_49 ++ , V_623 ++ ) {
V_623 -> V_35 &= ~ V_625 ;
if ( V_623 -> V_35 & V_626 )
V_14 -> V_118 . V_374 . V_627 ( V_14 , V_49 ,
V_623 -> V_628 ,
V_623 -> V_532 ,
V_629 ) ;
else
V_14 -> V_118 . V_374 . V_630 ( V_14 , V_49 ) ;
}
}
static void F_341 ( struct V_1 * V_2 )
{
struct V_622 * V_623 = & V_2 -> V_623 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_624 ; V_49 ++ , V_623 ++ ) {
if ( ! ( V_623 -> V_35 & V_625 ) )
continue;
V_623 -> V_35 &= ~ V_625 ;
if ( V_623 -> V_35 & V_626 )
V_14 -> V_118 . V_374 . V_627 ( V_14 , V_49 ,
V_623 -> V_628 ,
V_623 -> V_532 ,
V_629 ) ;
else
V_14 -> V_118 . V_374 . V_630 ( V_14 , V_49 ) ;
}
}
static void F_342 ( struct V_1 * V_2 )
{
struct V_622 * V_623 = & V_2 -> V_623 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_624 ; V_49 ++ , V_623 ++ ) {
V_623 -> V_35 |= V_625 ;
V_623 -> V_35 &= ~ V_626 ;
}
F_341 ( V_2 ) ;
}
static int F_343 ( struct V_1 * V_2 , T_2 V_532 )
{
struct V_622 * V_623 = & V_2 -> V_623 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 , V_98 = 0 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_624 ; V_49 ++ , V_623 ++ ) {
if ( V_623 -> V_35 & V_631 )
continue;
if ( V_623 -> V_35 & V_626 ) {
if ( V_623 -> V_532 != V_532 )
continue;
}
V_98 ++ ;
}
return V_98 ;
}
static void F_344 ( struct V_1 * V_2 )
{
struct V_622 * V_623 = & V_2 -> V_623 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
memcpy ( & V_623 -> V_628 , V_14 -> V_118 . V_628 , V_632 ) ;
V_623 -> V_532 = F_310 ( 0 ) ;
V_623 -> V_35 = V_631 | V_626 ;
V_14 -> V_118 . V_374 . V_627 ( V_14 , 0 , V_623 -> V_628 , V_623 -> V_532 ,
V_629 ) ;
}
int F_345 ( struct V_1 * V_2 ,
const T_4 * V_628 , T_2 V_532 )
{
struct V_622 * V_623 = & V_2 -> V_623 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( F_346 ( V_628 ) )
return - V_633 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_624 ; V_49 ++ , V_623 ++ ) {
if ( V_623 -> V_35 & V_626 )
continue;
F_347 ( V_623 -> V_628 , V_628 ) ;
V_623 -> V_532 = V_532 ;
V_623 -> V_35 |= V_625 |
V_626 ;
F_341 ( V_2 ) ;
return V_49 ;
}
return - V_488 ;
}
int F_348 ( struct V_1 * V_2 ,
const T_4 * V_628 , T_2 V_532 )
{
struct V_622 * V_623 = & V_2 -> V_623 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( F_346 ( V_628 ) )
return - V_633 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_118 . V_624 ; V_49 ++ , V_623 ++ ) {
if ( ! ( V_623 -> V_35 & V_626 ) )
continue;
if ( V_623 -> V_532 != V_532 )
continue;
if ( ! F_349 ( V_628 , V_623 -> V_628 ) )
continue;
V_623 -> V_35 |= V_625 ;
V_623 -> V_35 &= ~ V_626 ;
F_341 ( V_2 ) ;
return 0 ;
}
return - V_488 ;
}
static int F_350 ( struct V_76 * V_77 , int V_634 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
int V_98 = 0 ;
if ( F_351 ( V_77 ) > F_343 ( V_2 , V_634 ) )
return - V_488 ;
if ( ! F_352 ( V_77 ) ) {
struct V_635 * V_636 ;
F_353 (ha, netdev) {
F_348 ( V_2 , V_636 -> V_628 , V_634 ) ;
F_345 ( V_2 , V_636 -> V_628 , V_634 ) ;
V_98 ++ ;
}
}
return V_98 ;
}
static int F_354 ( struct V_76 * V_77 , const unsigned char * V_628 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
int V_637 ;
V_637 = F_345 ( V_2 , V_628 , F_310 ( 0 ) ) ;
return F_355 ( int , V_637 , 0 ) ;
}
static int F_356 ( struct V_76 * V_77 , const unsigned char * V_628 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
F_348 ( V_2 , V_628 , F_310 ( 0 ) ) ;
return 0 ;
}
void F_357 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_638 , V_639 = V_640 | V_641 ;
T_12 V_218 = V_77 -> V_218 ;
int V_98 ;
V_638 = F_40 ( V_14 , V_642 ) ;
V_638 &= ~ V_643 ;
V_638 |= V_644 ;
V_638 |= V_645 ;
V_638 |= V_646 ;
V_638 &= ~ ( V_647 | V_648 ) ;
if ( V_77 -> V_148 & V_649 ) {
V_14 -> V_650 . V_651 = true ;
V_638 |= ( V_647 | V_648 ) ;
V_639 |= V_652 ;
V_218 &= ~ V_653 ;
} else {
if ( V_77 -> V_148 & V_654 ) {
V_638 |= V_648 ;
V_639 |= V_652 ;
}
V_14 -> V_650 . V_651 = false ;
}
if ( F_358 ( V_77 , F_354 , F_356 ) ) {
V_638 |= V_647 ;
V_639 |= V_655 ;
}
V_98 = F_336 ( V_77 ) ;
if ( V_98 < 0 ) {
V_638 |= V_648 ;
V_639 |= V_652 ;
} else if ( V_98 ) {
V_639 |= V_656 ;
}
if ( V_14 -> V_118 . type != V_119 ) {
V_639 |= F_40 ( V_14 , F_359 ( F_310 ( 0 ) ) ) &
~ ( V_652 | V_656 |
V_655 ) ;
F_74 ( V_14 , F_359 ( F_310 ( 0 ) ) , V_639 ) ;
}
if ( V_218 & V_297 ) {
V_638 |= ( V_643 |
V_644 |
V_646 ) ;
V_638 &= ~ ( V_645 ) ;
}
F_74 ( V_14 , V_642 , V_638 ) ;
if ( V_218 & V_271 )
F_329 ( V_2 ) ;
else
F_328 ( V_2 ) ;
if ( V_218 & V_653 )
F_333 ( V_2 ) ;
else
F_330 ( V_2 ) ;
}
static void F_360 ( struct V_1 * V_2 )
{
int V_657 ;
for ( V_657 = 0 ; V_657 < V_2 -> V_210 ; V_657 ++ )
F_361 ( & V_2 -> V_174 [ V_657 ] -> V_277 ) ;
}
static void F_362 ( struct V_1 * V_2 )
{
int V_657 ;
for ( V_657 = 0 ; V_657 < V_2 -> V_210 ; V_657 ++ )
F_363 ( & V_2 -> V_174 [ V_657 ] -> V_277 ) ;
}
static void F_364 ( struct V_1 * V_2 , T_1 V_128 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_658 ;
if ( ! ( V_2 -> V_148 & ( V_659 |
V_660 ) ) )
return;
V_658 = F_40 ( V_14 , V_661 ) & ~ V_128 ;
F_74 ( V_14 , V_661 , V_658 ) ;
if ( V_128 & V_662 )
V_2 -> V_663 = 0 ;
if ( V_128 & V_664 )
V_2 -> V_665 = 0 ;
}
static void F_365 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_561 = V_2 -> V_77 -> V_334 + V_562 + V_563 ;
if ( ! ( V_2 -> V_148 & V_149 ) ) {
if ( V_14 -> V_118 . type == V_119 )
F_366 ( V_2 -> V_77 , 65536 ) ;
return;
}
if ( V_14 -> V_118 . type == V_119 )
F_366 ( V_2 -> V_77 , 32768 ) ;
#ifdef F_184
if ( V_2 -> V_77 -> V_218 & V_666 )
V_561 = F_231 ( V_561 , V_567 ) ;
#endif
if ( V_2 -> V_667 & V_668 ) {
F_367 ( V_14 , & V_2 -> V_145 , V_561 ,
V_669 ) ;
F_367 ( V_14 , & V_2 -> V_145 , V_561 ,
V_670 ) ;
F_368 ( V_14 , & V_2 -> V_145 ) ;
} else if ( V_2 -> V_671 && V_2 -> V_147 ) {
F_369 ( & V_2 -> V_14 ,
V_2 -> V_671 ,
V_561 ) ;
F_370 ( & V_2 -> V_14 ,
V_2 -> V_147 -> V_144 ,
V_2 -> V_671 -> V_672 ) ;
}
if ( V_14 -> V_118 . type != V_119 ) {
T_1 V_673 = 0 ;
T_2 V_496 = V_2 -> V_463 [ V_478 ] . V_497 - 1 ;
while ( V_496 ) {
V_673 ++ ;
V_496 >>= 1 ;
}
F_74 ( V_14 , V_674 , V_673 * 0x11111111 ) ;
}
}
static int F_371 ( struct V_1 * V_2 , int V_675 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_76 * V_89 = V_2 -> V_77 ;
int V_417 , V_143 , V_676 , V_677 ;
T_1 V_678 , V_679 ;
V_143 = V_417 = V_89 -> V_334 + V_562 + V_563 + V_680 ;
#ifdef F_184
if ( ( V_89 -> V_218 & V_666 ) &&
( V_143 < V_567 ) &&
( V_675 == F_372 ( V_2 ) ) )
V_143 = V_567 ;
#endif
switch ( V_14 -> V_118 . type ) {
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_678 = F_373 ( V_417 , V_143 ) ;
break;
default:
V_678 = F_374 ( V_417 , V_143 ) ;
break;
}
if ( V_2 -> V_148 & V_458 )
V_678 += F_375 ( V_143 ) ;
V_676 = F_376 ( V_678 ) ;
V_679 = F_40 ( V_14 , F_377 ( V_675 ) ) >> 10 ;
V_677 = V_679 - V_676 ;
if ( V_677 < 0 ) {
F_27 ( V_164 , L_84
L_85
L_86 , V_675 ) ;
V_677 = V_143 + 1 ;
}
return V_677 ;
}
static int F_378 ( struct V_1 * V_2 , int V_675 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_76 * V_89 = V_2 -> V_77 ;
int V_143 ;
T_1 V_678 ;
V_143 = V_89 -> V_334 + V_562 + V_563 ;
#ifdef F_184
if ( ( V_89 -> V_218 & V_666 ) &&
( V_143 < V_567 ) &&
( V_675 == F_84 ( V_89 , V_2 -> V_681 . V_682 ) ) )
V_143 = V_567 ;
#endif
switch ( V_14 -> V_118 . type ) {
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_678 = F_379 ( V_143 ) ;
break;
default:
V_678 = F_380 ( V_143 ) ;
break;
}
return F_376 ( V_678 ) ;
}
static void F_381 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_683 = F_281 ( V_2 -> V_77 ) ;
int V_49 ;
if ( ! V_683 )
V_683 = 1 ;
for ( V_49 = 0 ; V_49 < V_683 ; V_49 ++ ) {
V_14 -> V_134 . V_684 [ V_49 ] = F_371 ( V_2 , V_49 ) ;
V_14 -> V_134 . V_685 [ V_49 ] = F_378 ( V_2 , V_49 ) ;
if ( V_14 -> V_134 . V_685 [ V_49 ] > V_14 -> V_134 . V_684 [ V_49 ] )
V_14 -> V_134 . V_685 [ V_49 ] = 0 ;
}
for (; V_49 < V_686 ; V_49 ++ )
V_14 -> V_134 . V_684 [ V_49 ] = 0 ;
}
static void F_382 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_687 ;
T_4 V_143 = F_281 ( V_2 -> V_77 ) ;
if ( V_2 -> V_148 & V_410 ||
V_2 -> V_148 & V_688 )
V_687 = 32 << V_2 -> V_689 ;
else
V_687 = 0 ;
V_14 -> V_118 . V_374 . V_690 ( V_14 , V_143 , V_687 , V_691 ) ;
F_381 ( V_2 ) ;
}
static void F_383 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_692 * V_693 ;
struct V_694 * V_695 ;
F_384 ( & V_2 -> V_696 ) ;
if ( ! F_385 ( & V_2 -> V_697 ) )
F_386 ( V_14 , & V_2 -> V_698 ) ;
F_387 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_388 ( V_14 ,
& V_695 -> V_695 ,
V_695 -> V_699 ,
( V_695 -> V_700 == V_701 ) ?
V_701 :
V_2 -> V_84 [ V_695 -> V_700 ] -> V_158 ) ;
}
F_389 ( & V_2 -> V_696 ) ;
}
static void F_390 ( struct V_76 * V_89 , unsigned int V_532 ,
struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_639 ;
V_639 = F_40 ( V_14 , F_359 ( V_532 ) ) ;
V_639 |= ( V_656 | V_640 | V_641 ) ;
V_639 &= ~ V_652 ;
if ( V_89 -> V_148 & V_654 ) {
V_639 |= V_652 ;
} else {
V_639 |= V_656 ;
V_14 -> V_118 . V_374 . V_621 ( V_14 , V_89 ) ;
}
F_350 ( V_2 -> V_77 , V_532 ) ;
F_74 ( V_14 , F_359 ( V_532 ) , V_639 ) ;
}
static void F_391 ( struct V_702 * V_703 )
{
struct V_1 * V_2 = V_703 -> V_157 ;
int V_496 = V_2 -> V_704 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_532 = V_703 -> V_532 ;
T_1 V_533 = V_534 |
V_535 |
V_536 |
V_537 |
V_538 ;
if ( V_14 -> V_118 . type == V_119 )
return;
if ( V_496 > 3 )
V_533 |= 2u << 29 ;
else if ( V_496 > 1 )
V_533 |= 1u << 29 ;
F_74 ( V_14 , F_309 ( F_310 ( V_532 ) ) , V_533 ) ;
}
static void F_392 ( struct V_63 * V_84 )
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
F_393 ( V_100 ) ;
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
static void F_394 ( struct V_702 * V_703 ,
struct V_63 * V_84 )
{
struct V_1 * V_2 = V_703 -> V_157 ;
int V_117 = V_84 -> V_96 + V_703 -> V_705 ;
F_305 ( V_2 , V_84 ) ;
F_278 ( 10000 , 20000 ) ;
F_245 ( V_2 , F_261 ( V_117 ) ) ;
F_392 ( V_84 ) ;
V_84 -> V_156 = NULL ;
}
static int F_395 ( struct V_76 * V_706 ,
struct V_702 * V_707 )
{
struct V_1 * V_2 = V_707 -> V_157 ;
unsigned int V_708 = V_707 -> V_705 ;
unsigned int V_709 = V_707 -> V_710 ;
int V_49 ;
F_396 ( V_706 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_704 ; V_49 ++ ) {
F_394 ( V_707 , V_2 -> V_84 [ V_708 + V_49 ] ) ;
V_2 -> V_84 [ V_708 + V_49 ] -> V_77 = V_2 -> V_77 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_704 ; V_49 ++ ) {
V_2 -> V_92 [ V_709 + V_49 ] -> V_156 = NULL ;
V_2 -> V_92 [ V_709 + V_49 ] -> V_77 = V_2 -> V_77 ;
}
return 0 ;
}
static int F_397 ( struct V_76 * V_706 ,
struct V_702 * V_707 )
{
struct V_1 * V_2 = V_707 -> V_157 ;
unsigned int V_708 , V_709 , V_402 ;
int V_49 , V_711 , V_17 = 0 ;
if ( ! F_14 ( V_707 -> V_532 , & V_2 -> V_712 ) )
return 0 ;
V_711 = V_707 -> V_532 * V_2 -> V_704 ;
F_398 ( V_706 , L_87 ,
V_707 -> V_532 , V_2 -> V_713 ,
V_711 , V_711 + V_2 -> V_704 ,
V_2 -> V_712 ) ;
V_707 -> V_77 = V_706 ;
V_707 -> V_705 = V_708 = V_711 ;
V_707 -> V_710 = V_709 = V_711 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_704 ; V_49 ++ )
F_394 ( V_707 , V_2 -> V_84 [ V_708 + V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_704 ; V_49 ++ ) {
V_2 -> V_84 [ V_708 + V_49 ] -> V_77 = V_706 ;
V_2 -> V_84 [ V_708 + V_49 ] -> V_156 = V_707 ;
F_306 ( V_2 , V_2 -> V_84 [ V_708 + V_49 ] ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_704 ; V_49 ++ ) {
V_2 -> V_92 [ V_709 + V_49 ] -> V_77 = V_706 ;
V_2 -> V_92 [ V_709 + V_49 ] -> V_156 = V_707 ;
}
V_402 = F_355 (unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues) ;
V_17 = F_399 ( V_706 , V_402 ) ;
if ( V_17 )
goto V_714;
V_17 = F_400 ( V_706 , V_402 ) ;
if ( V_17 )
goto V_714;
if ( F_401 ( V_706 -> V_715 ) )
F_345 ( V_2 , V_706 -> V_715 , V_707 -> V_532 ) ;
F_391 ( V_707 ) ;
F_390 ( V_706 , V_707 -> V_532 , V_2 ) ;
return V_17 ;
V_714:
F_395 ( V_706 , V_707 ) ;
return V_17 ;
}
static int F_402 ( struct V_76 * V_106 , void * V_103 )
{
if ( F_403 ( V_106 ) ) {
struct V_716 * V_717 = F_87 ( V_106 ) ;
struct V_702 * V_703 = V_717 -> V_718 ;
if ( V_717 -> V_718 )
F_397 ( V_106 , V_703 ) ;
}
return 0 ;
}
static void F_404 ( struct V_1 * V_2 )
{
F_405 ( V_2 -> V_77 ,
F_402 , NULL ) ;
}
static void F_406 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
F_382 ( V_2 ) ;
#ifdef F_407
F_365 ( V_2 ) ;
#endif
F_311 ( V_2 ) ;
F_357 ( V_2 -> V_77 ) ;
F_334 ( V_2 ) ;
switch ( V_14 -> V_118 . type ) {
case V_121 :
case V_122 :
V_14 -> V_118 . V_374 . V_719 ( V_14 ) ;
break;
default:
break;
}
if ( V_2 -> V_148 & V_410 ) {
F_408 ( & V_2 -> V_14 ,
V_2 -> V_689 ) ;
} else if ( V_2 -> V_148 & V_688 ) {
F_409 ( & V_2 -> V_14 ,
V_2 -> V_689 ) ;
F_383 ( V_2 ) ;
}
switch ( V_14 -> V_118 . type ) {
case V_121 :
case V_122 :
V_14 -> V_118 . V_374 . V_720 ( V_14 ) ;
break;
default:
break;
}
#ifdef F_259
if ( V_2 -> V_148 & V_213 )
F_127 ( V_2 ) ;
#endif
#ifdef F_184
F_410 ( V_2 ) ;
#endif
F_282 ( V_2 ) ;
F_321 ( V_2 ) ;
F_404 ( V_2 ) ;
}
static void F_411 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_118 . type == V_119 )
V_2 -> V_369 |= V_721 ;
V_2 -> V_369 |= V_394 ;
V_2 -> V_395 = 0 ;
}
static int F_412 ( struct V_15 * V_14 )
{
T_1 V_20 ;
bool V_722 , V_376 = false ;
int V_637 = V_723 ;
if ( V_14 -> V_118 . V_374 . V_375 )
V_637 = V_14 -> V_118 . V_374 . V_375 ( V_14 , & V_20 , & V_376 , false ) ;
if ( V_637 )
return V_637 ;
V_20 = V_14 -> V_46 . V_724 ;
if ( ( ! V_20 ) && ( V_14 -> V_118 . V_374 . V_725 ) )
V_637 = V_14 -> V_118 . V_374 . V_725 ( V_14 , & V_20 ,
& V_722 ) ;
if ( V_637 )
return V_637 ;
if ( V_14 -> V_118 . V_374 . V_726 )
V_637 = V_14 -> V_118 . V_374 . V_726 ( V_14 , V_20 , V_376 ) ;
return V_637 ;
}
static void F_413 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_727 = 0 ;
if ( V_2 -> V_148 & V_438 ) {
V_727 = V_728 | V_729 |
V_730 ;
V_727 |= V_731 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
F_74 ( V_14 , V_732 , V_733 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
default:
F_74 ( V_14 , F_414 ( 0 ) , 0xFFFFFFFF ) ;
F_74 ( V_14 , F_414 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_74 ( V_14 , V_732 , V_733 ) ;
}
if ( V_2 -> V_148 & V_458 ) {
V_727 &= ~ V_734 ;
switch ( V_2 -> V_463 [ V_464 ] . V_128 ) {
case V_553 :
V_727 |= V_735 ;
break;
case V_465 :
V_727 |= V_736 ;
break;
default:
V_727 |= V_737 ;
break;
}
}
if ( V_2 -> V_369 & V_384 ) {
switch ( V_2 -> V_14 . V_118 . type ) {
case V_121 :
V_727 |= V_738 ;
break;
default:
break;
}
}
if ( V_2 -> V_148 & V_382 )
V_727 |= F_415 ( V_14 ) ;
switch ( V_14 -> V_118 . type ) {
case V_121 :
V_727 |= V_739 | V_740 ;
break;
case V_124 :
case V_125 :
V_727 |= V_741 ;
break;
default:
break;
}
F_74 ( V_14 , V_742 , V_727 ) ;
}
static void F_416 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 ;
T_1 V_110 ;
F_75 ( V_2 ) ;
F_413 ( V_2 ) ;
if ( V_2 -> V_148 & V_438 )
F_225 ( V_2 ) ;
else
F_274 ( V_2 ) ;
if ( V_14 -> V_118 . V_374 . V_743 )
V_14 -> V_118 . V_374 . V_743 ( V_14 ) ;
if ( V_14 -> V_46 . V_374 . V_744 )
V_14 -> V_46 . V_374 . V_744 ( V_14 , true ) ;
F_36 () ;
F_37 ( V_34 , & V_2 -> V_35 ) ;
F_360 ( V_2 ) ;
if ( F_238 ( V_14 ) ) {
F_411 ( V_2 ) ;
} else {
V_17 = F_412 ( V_14 ) ;
if ( V_17 )
F_107 ( V_190 , L_88 , V_17 ) ;
}
F_40 ( V_14 , V_383 ) ;
F_247 ( V_2 , true , true ) ;
if ( V_2 -> V_148 & V_382 ) {
T_1 V_745 = F_40 ( V_14 , V_746 ) ;
if ( V_745 & V_747 )
F_234 ( V_164 , L_70 ) ;
}
V_2 -> V_148 |= V_398 ;
V_2 -> V_399 = V_189 ;
F_417 ( & V_2 -> V_748 , V_189 ) ;
V_110 = F_40 ( V_14 , V_111 ) ;
V_110 |= V_749 ;
F_74 ( V_14 , V_111 , V_110 ) ;
}
void F_418 ( struct V_1 * V_2 )
{
F_419 ( F_420 () ) ;
F_421 ( V_2 -> V_77 ) ;
while ( F_15 ( V_750 , & V_2 -> V_35 ) )
F_278 ( 1000 , 2000 ) ;
if ( V_2 -> V_14 . V_46 . type == V_751 )
F_422 ( V_2 ) ;
F_423 ( V_2 ) ;
if ( V_2 -> V_148 & V_458 )
F_424 ( 2000 ) ;
F_425 ( V_2 ) ;
F_37 ( V_750 , & V_2 -> V_35 ) ;
}
void F_425 ( struct V_1 * V_2 )
{
F_406 ( V_2 ) ;
F_416 ( V_2 ) ;
}
void F_426 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_76 * V_77 = V_2 -> V_77 ;
int V_17 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
while ( F_15 ( V_752 , & V_2 -> V_35 ) )
F_278 ( 1000 , 2000 ) ;
V_2 -> V_369 &= ~ ( V_721 |
V_394 ) ;
V_2 -> V_148 &= ~ V_396 ;
V_17 = V_14 -> V_118 . V_374 . V_753 ( V_14 ) ;
switch ( V_17 ) {
case 0 :
case V_754 :
case V_755 :
break;
case V_756 :
F_18 ( L_89 ) ;
break;
case V_757 :
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
F_37 ( V_752 , & V_2 -> V_35 ) ;
F_342 ( V_2 ) ;
F_427 ( V_77 , NULL ) ;
F_344 ( V_2 ) ;
if ( V_14 -> V_118 . V_758 )
V_14 -> V_118 . V_374 . V_759 ( V_14 , F_310 ( 0 ) ) ;
if ( F_14 ( V_760 , & V_2 -> V_35 ) )
F_428 ( V_2 ) ;
if ( V_14 -> V_46 . V_374 . V_744 ) {
if ( ! F_63 ( V_2 -> V_77 ) && ! V_2 -> V_761 )
V_14 -> V_46 . V_374 . V_744 ( V_14 , false ) ;
else
V_14 -> V_46 . V_374 . V_744 ( V_14 , true ) ;
}
}
static void F_429 ( struct V_63 * V_92 )
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
F_430 ( F_111 ( V_92 ) ) ;
V_92 -> V_70 = 0 ;
V_92 -> V_69 = 0 ;
}
static void F_431 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ )
F_392 ( V_2 -> V_84 [ V_49 ] ) ;
}
static void F_432 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ )
F_429 ( V_2 -> V_92 [ V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ )
F_429 ( V_2 -> V_94 [ V_49 ] ) ;
}
static void F_433 ( struct V_1 * V_2 )
{
struct V_692 * V_693 ;
struct V_694 * V_695 ;
F_384 ( & V_2 -> V_696 ) ;
F_387 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_434 ( & V_695 -> V_762 ) ;
F_268 ( V_695 ) ;
}
V_2 -> V_763 = 0 ;
F_389 ( & V_2 -> V_696 ) ;
}
static int F_435 ( struct V_76 * V_106 , void * V_103 )
{
if ( F_403 ( V_106 ) ) {
struct V_716 * V_274 = F_87 ( V_106 ) ;
if ( V_274 -> V_718 ) {
F_396 ( V_106 ) ;
F_436 ( V_106 ) ;
F_437 ( V_106 ) ;
}
}
return 0 ;
}
void F_423 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( F_15 ( V_34 , & V_2 -> V_35 ) )
return;
V_14 -> V_118 . V_374 . V_589 ( V_14 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ )
F_305 ( V_2 , V_2 -> V_84 [ V_49 ] ) ;
F_278 ( 10000 , 20000 ) ;
if ( V_2 -> V_94 [ 0 ] )
F_438 () ;
F_396 ( V_77 ) ;
F_436 ( V_77 ) ;
F_437 ( V_77 ) ;
F_405 ( V_2 -> V_77 ,
F_435 , NULL ) ;
F_272 ( V_2 ) ;
F_362 ( V_2 ) ;
F_37 ( V_163 , & V_2 -> V_35 ) ;
V_2 -> V_369 &= ~ V_411 ;
V_2 -> V_148 &= ~ V_398 ;
F_439 ( & V_2 -> V_748 ) ;
if ( V_2 -> V_340 ) {
F_74 ( & V_2 -> V_14 , V_342 , 0 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_340 ; V_49 ++ )
V_2 -> V_558 [ V_49 ] . V_764 = false ;
F_440 ( V_2 ) ;
F_441 ( V_2 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ ) {
T_4 V_158 = V_2 -> V_92 [ V_49 ] -> V_158 ;
F_74 ( V_14 , F_53 ( V_158 ) , V_765 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ ) {
T_4 V_158 = V_2 -> V_94 [ V_49 ] -> V_158 ;
F_74 ( V_14 , F_53 ( V_158 ) , V_765 ) ;
}
switch ( V_14 -> V_118 . type ) {
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
F_74 ( V_14 , V_474 ,
( F_40 ( V_14 , V_474 ) &
~ V_475 ) ) ;
break;
default:
break;
}
if ( ! F_442 ( V_2 -> V_9 ) )
F_426 ( V_2 ) ;
if ( V_14 -> V_118 . V_374 . V_766 )
V_14 -> V_118 . V_374 . V_766 ( V_14 ) ;
F_432 ( V_2 ) ;
F_431 ( V_2 ) ;
}
static void F_443 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_21 ) {
case V_379 :
case V_380 :
if ( ! V_14 -> V_46 . V_767 )
break;
V_2 -> V_369 |= V_768 ;
if ( ! V_14 -> V_46 . V_769 )
break;
V_2 -> V_369 |= V_770 ;
break;
default:
V_2 -> V_369 &= ~ V_768 ;
V_2 -> V_369 &= ~ V_770 ;
break;
}
}
static void F_444 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
F_90 ( V_2 ) ;
}
static void F_445 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_771 * V_143 ;
int V_60 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
case V_121 :
V_2 -> V_145 . V_772 . V_773 = V_686 ;
V_2 -> V_145 . V_772 . V_774 = V_686 ;
break;
case V_122 :
case V_123 :
V_2 -> V_145 . V_772 . V_773 = V_775 ;
V_2 -> V_145 . V_772 . V_774 = V_775 ;
break;
case V_124 :
case V_125 :
default:
V_2 -> V_145 . V_772 . V_773 = V_776 ;
V_2 -> V_145 . V_772 . V_774 = V_776 ;
break;
}
for ( V_60 = 0 ; V_60 < V_686 ; V_60 ++ ) {
V_143 = & V_2 -> V_145 . V_777 [ V_60 ] ;
V_143 -> V_778 [ V_669 ] . V_779 = 0 ;
V_143 -> V_778 [ V_669 ] . V_780 = 12 + ( V_60 & 1 ) ;
V_143 -> V_778 [ V_670 ] . V_779 = 0 ;
V_143 -> V_778 [ V_670 ] . V_780 = 12 + ( V_60 & 1 ) ;
V_143 -> V_781 = V_782 ;
}
V_143 = & V_2 -> V_145 . V_777 [ 0 ] ;
V_143 -> V_778 [ V_669 ] . V_783 = 0xFF ;
V_143 -> V_778 [ V_670 ] . V_783 = 0xFF ;
V_2 -> V_145 . V_784 [ V_669 ] [ 0 ] = 100 ;
V_2 -> V_145 . V_784 [ V_670 ] [ 0 ] = 100 ;
V_2 -> V_145 . V_146 = false ;
V_2 -> V_785 = 0x00 ;
if ( V_2 -> V_148 & V_786 )
V_2 -> V_667 = V_787 | V_668 ;
memcpy ( & V_2 -> V_788 , & V_2 -> V_145 ,
sizeof( V_2 -> V_788 ) ) ;
}
static int F_446 ( struct V_1 * V_2 ,
const struct V_789 * V_790 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_226 , V_791 ;
T_1 V_792 ;
int V_49 ;
V_14 -> V_793 = V_9 -> V_794 ;
V_14 -> V_21 = V_9 -> V_211 ;
V_14 -> V_795 = V_9 -> V_796 ;
V_14 -> V_797 = V_9 -> V_798 ;
V_14 -> V_799 = V_9 -> V_800 ;
V_790 -> V_801 ( V_14 ) ;
V_226 = F_355 ( int , F_447 ( V_2 ) , F_448 () ) ;
V_2 -> V_463 [ V_478 ] . V_802 = V_226 ;
V_2 -> V_369 |= V_803 ;
V_2 -> V_804 = V_805 ;
V_2 -> V_448 = 20 ;
V_791 = F_355 ( int , V_806 , F_448 () ) ;
V_2 -> V_463 [ V_807 ] . V_802 = V_791 ;
V_2 -> V_689 = V_808 ;
#ifdef F_259
V_2 -> V_148 |= V_213 ;
#endif
#ifdef F_407
V_2 -> V_148 |= V_786 ;
V_2 -> V_148 &= ~ V_149 ;
#endif
#ifdef F_184
V_2 -> V_148 |= V_809 ;
V_2 -> V_148 &= ~ V_566 ;
#ifdef F_407
V_2 -> V_681 . V_682 = V_810 ;
#endif
#endif
V_2 -> V_811 [ 0 ] = F_290 ( sizeof( * V_2 -> V_811 [ 0 ] ) ,
V_487 ) ;
if ( ! V_2 -> V_811 [ 0 ] )
return - V_488 ;
V_2 -> V_811 [ 0 ] -> V_812 = V_813 ;
for ( V_49 = 1 ; V_49 < V_814 ; V_49 ++ )
V_2 -> V_811 [ V_49 ] = NULL ;
V_2 -> V_623 = F_290 ( sizeof( struct V_622 ) *
V_14 -> V_118 . V_624 ,
V_815 ) ;
if ( ! V_2 -> V_623 )
return - V_488 ;
if ( F_289 ( V_2 ) )
return - V_488 ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_2 -> V_369 &= ~ V_803 ;
if ( V_14 -> V_21 == V_816 )
V_2 -> V_148 |= V_382 ;
V_2 -> V_804 = V_817 ;
V_2 -> V_463 [ V_807 ] . V_802 = 0 ;
V_2 -> V_448 = 0 ;
V_2 -> V_689 = 0 ;
#ifdef F_184
V_2 -> V_148 &= ~ V_809 ;
V_2 -> V_148 &= ~ V_566 ;
#ifdef F_407
V_2 -> V_681 . V_682 = 0 ;
#endif
#endif
break;
case V_121 :
if ( V_14 -> V_21 == V_371 )
V_2 -> V_369 |= V_384 ;
break;
case V_122 :
V_792 = F_40 ( V_14 , F_449 ( V_14 ) ) ;
if ( V_792 & V_818 )
V_2 -> V_369 |= V_384 ;
break;
case V_125 :
V_2 -> V_148 |= V_660 ;
switch ( V_14 -> V_21 ) {
case V_379 :
case V_380 :
V_2 -> V_369 |= V_384 ;
break;
default:
break;
}
case V_124 :
#ifdef F_407
V_2 -> V_148 &= ~ V_786 ;
#endif
#ifdef F_184
V_2 -> V_148 &= ~ V_809 ;
#ifdef F_407
V_2 -> V_681 . V_682 = 0 ;
#endif
#endif
case V_123 :
if ( V_14 -> V_118 . type == V_123 )
V_2 -> V_369 |= V_384 ;
#ifdef F_259
V_2 -> V_148 &= ~ V_213 ;
#endif
V_2 -> V_148 |= V_659 ;
break;
default:
break;
}
#ifdef F_184
F_450 ( & V_2 -> V_681 . V_819 ) ;
#endif
F_450 ( & V_2 -> V_696 ) ;
#ifdef F_407
F_445 ( V_2 ) ;
#endif
V_14 -> V_134 . V_820 = V_136 ;
V_14 -> V_134 . V_135 = V_136 ;
F_381 ( V_2 ) ;
V_14 -> V_134 . V_821 = V_822 ;
V_14 -> V_134 . V_823 = true ;
V_14 -> V_134 . V_824 = F_451 ( V_14 ) ;
#ifdef F_337
if ( V_825 > 0 )
F_11 ( L_97 ) ;
if ( V_14 -> V_118 . type != V_119 ) {
if ( V_825 > V_826 ) {
V_825 = 0 ;
F_11 ( L_98 ) ;
}
}
#endif
V_2 -> V_429 = 1 ;
V_2 -> V_827 = 1 ;
V_2 -> V_828 = V_829 ;
V_2 -> V_830 = V_831 ;
V_2 -> V_832 = V_833 ;
if ( F_452 ( V_14 ) ) {
F_18 ( L_99 ) ;
return - V_834 ;
}
F_91 ( 0 , & V_2 -> V_712 ) ;
F_91 ( V_34 , & V_2 -> V_35 ) ;
return 0 ;
}
int F_453 ( struct V_63 * V_92 )
{
struct V_211 * V_89 = V_92 -> V_89 ;
int V_835 = F_454 ( V_89 ) ;
int V_836 = - 1 ;
int V_304 ;
V_304 = sizeof( struct V_66 ) * V_92 -> V_98 ;
if ( V_92 -> V_174 )
V_836 = V_92 -> V_174 -> V_837 ;
V_92 -> V_68 = F_455 ( V_304 , V_836 ) ;
if ( ! V_92 -> V_68 )
V_92 -> V_68 = F_456 ( V_304 ) ;
if ( ! V_92 -> V_68 )
goto V_17;
V_92 -> V_304 = V_92 -> V_98 * sizeof( union V_78 ) ;
V_92 -> V_304 = F_175 ( V_92 -> V_304 , 4096 ) ;
F_457 ( V_89 , V_836 ) ;
V_92 -> V_97 = F_458 ( V_89 ,
V_92 -> V_304 ,
& V_92 -> V_72 ,
V_487 ) ;
F_457 ( V_89 , V_835 ) ;
if ( ! V_92 -> V_97 )
V_92 -> V_97 = F_458 ( V_89 , V_92 -> V_304 ,
& V_92 -> V_72 , V_487 ) ;
if ( ! V_92 -> V_97 )
goto V_17;
V_92 -> V_70 = 0 ;
V_92 -> V_69 = 0 ;
return 0 ;
V_17:
F_459 ( V_92 -> V_68 ) ;
V_92 -> V_68 = NULL ;
F_460 ( V_89 , L_100 ) ;
return - V_488 ;
}
static int F_461 ( struct V_1 * V_2 )
{
int V_49 , V_60 = 0 , V_17 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ ) {
V_17 = F_453 ( V_2 -> V_92 [ V_49 ] ) ;
if ( ! V_17 )
continue;
F_107 ( V_190 , L_101 , V_49 ) ;
goto V_838;
}
for ( V_60 = 0 ; V_60 < V_2 -> V_93 ; V_60 ++ ) {
V_17 = F_453 ( V_2 -> V_94 [ V_60 ] ) ;
if ( ! V_17 )
continue;
F_107 ( V_190 , L_101 , V_60 ) ;
goto V_838;
}
return 0 ;
V_838:
while ( V_60 -- )
F_462 ( V_2 -> V_94 [ V_60 ] ) ;
while ( V_49 -- )
F_462 ( V_2 -> V_92 [ V_49 ] ) ;
return V_17 ;
}
int F_463 ( struct V_1 * V_2 ,
struct V_63 * V_84 )
{
struct V_211 * V_89 = V_84 -> V_89 ;
int V_835 = F_454 ( V_89 ) ;
int V_836 = - 1 ;
int V_304 ;
V_304 = sizeof( struct V_87 ) * V_84 -> V_98 ;
if ( V_84 -> V_174 )
V_836 = V_84 -> V_174 -> V_837 ;
V_84 -> V_88 = F_455 ( V_304 , V_836 ) ;
if ( ! V_84 -> V_88 )
V_84 -> V_88 = F_456 ( V_304 ) ;
if ( ! V_84 -> V_88 )
goto V_17;
V_84 -> V_304 = V_84 -> V_98 * sizeof( union V_85 ) ;
V_84 -> V_304 = F_175 ( V_84 -> V_304 , 4096 ) ;
F_457 ( V_89 , V_836 ) ;
V_84 -> V_97 = F_458 ( V_89 ,
V_84 -> V_304 ,
& V_84 -> V_72 ,
V_487 ) ;
F_457 ( V_89 , V_835 ) ;
if ( ! V_84 -> V_97 )
V_84 -> V_97 = F_458 ( V_89 , V_84 -> V_304 ,
& V_84 -> V_72 , V_487 ) ;
if ( ! V_84 -> V_97 )
goto V_17;
V_84 -> V_69 = 0 ;
V_84 -> V_70 = 0 ;
V_84 -> V_317 = V_2 -> V_317 ;
return 0 ;
V_17:
F_459 ( V_84 -> V_88 ) ;
V_84 -> V_88 = NULL ;
F_460 ( V_89 , L_102 ) ;
return - V_488 ;
}
static int F_464 ( struct V_1 * V_2 )
{
int V_49 , V_17 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
V_17 = F_463 ( V_2 , V_2 -> V_84 [ V_49 ] ) ;
if ( ! V_17 )
continue;
F_107 ( V_190 , L_103 , V_49 ) ;
goto V_839;
}
#ifdef F_184
V_17 = F_465 ( V_2 ) ;
if ( ! V_17 )
#endif
return 0 ;
V_839:
while ( V_49 -- )
F_466 ( V_2 -> V_84 [ V_49 ] ) ;
return V_17 ;
}
void F_462 ( struct V_63 * V_92 )
{
F_429 ( V_92 ) ;
F_459 ( V_92 -> V_68 ) ;
V_92 -> V_68 = NULL ;
if ( ! V_92 -> V_97 )
return;
F_467 ( V_92 -> V_89 , V_92 -> V_304 ,
V_92 -> V_97 , V_92 -> V_72 ) ;
V_92 -> V_97 = NULL ;
}
static void F_468 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ )
if ( V_2 -> V_92 [ V_49 ] -> V_97 )
F_462 ( V_2 -> V_92 [ V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ )
if ( V_2 -> V_94 [ V_49 ] -> V_97 )
F_462 ( V_2 -> V_94 [ V_49 ] ) ;
}
void F_466 ( struct V_63 * V_84 )
{
F_392 ( V_84 ) ;
V_84 -> V_317 = NULL ;
F_459 ( V_84 -> V_88 ) ;
V_84 -> V_88 = NULL ;
if ( ! V_84 -> V_97 )
return;
F_467 ( V_84 -> V_89 , V_84 -> V_304 ,
V_84 -> V_97 , V_84 -> V_72 ) ;
V_84 -> V_97 = NULL ;
}
static void F_469 ( struct V_1 * V_2 )
{
int V_49 ;
#ifdef F_184
F_470 ( V_2 ) ;
#endif
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ )
if ( V_2 -> V_84 [ V_49 ] -> V_97 )
F_466 ( V_2 -> V_84 [ V_49 ] ) ;
}
static int F_471 ( struct V_76 * V_77 , int V_840 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
if ( ( V_2 -> V_148 & V_458 ) &&
( V_2 -> V_14 . V_118 . type == V_121 ) &&
( V_840 > V_841 ) )
F_27 ( V_190 , L_104 ) ;
F_109 ( V_190 , L_105 , V_77 -> V_334 , V_840 ) ;
V_77 -> V_334 = V_840 ;
if ( F_63 ( V_77 ) )
F_418 ( V_2 ) ;
return 0 ;
}
int F_472 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 , V_402 ;
if ( F_14 ( V_842 , & V_2 -> V_35 ) )
return - V_843 ;
F_436 ( V_77 ) ;
V_17 = F_461 ( V_2 ) ;
if ( V_17 )
goto V_838;
V_17 = F_464 ( V_2 ) ;
if ( V_17 )
goto V_839;
F_406 ( V_2 ) ;
V_17 = F_270 ( V_2 ) ;
if ( V_17 )
goto V_844;
if ( V_2 -> V_713 > 1 )
V_402 = V_2 -> V_704 ;
else
V_402 = V_2 -> V_91 ;
V_17 = F_399 ( V_77 , V_402 ) ;
if ( V_17 )
goto V_845;
if ( V_2 -> V_713 > 1 &&
V_2 -> V_104 > V_846 )
V_402 = V_846 ;
else
V_402 = V_2 -> V_104 ;
V_17 = F_400 ( V_77 , V_402 ) ;
if ( V_17 )
goto V_845;
F_473 ( V_2 ) ;
F_416 ( V_2 ) ;
F_364 ( V_2 , V_847 ) ;
F_474 ( V_77 ) ;
return 0 ;
V_845:
F_271 ( V_2 ) ;
V_844:
F_469 ( V_2 ) ;
if ( V_14 -> V_46 . V_374 . V_744 && ! V_2 -> V_761 )
V_14 -> V_46 . V_374 . V_744 ( & V_2 -> V_14 , false ) ;
V_839:
F_468 ( V_2 ) ;
V_838:
F_426 ( V_2 ) ;
return V_17 ;
}
static void F_475 ( struct V_1 * V_2 )
{
F_476 ( V_2 ) ;
if ( V_2 -> V_14 . V_46 . V_374 . V_848 ) {
V_2 -> V_14 . V_46 . V_849 = true ;
F_423 ( V_2 ) ;
V_2 -> V_14 . V_46 . V_374 . V_848 ( & V_2 -> V_14 ) ;
V_2 -> V_14 . V_46 . V_849 = false ;
} else {
F_423 ( V_2 ) ;
}
F_271 ( V_2 ) ;
F_468 ( V_2 ) ;
F_469 ( V_2 ) ;
}
int F_477 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
F_478 ( V_2 ) ;
if ( F_479 ( V_77 ) )
F_475 ( V_2 ) ;
F_433 ( V_2 ) ;
F_73 ( V_2 ) ;
return 0 ;
}
static int F_480 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_481 ( V_9 ) ;
struct V_76 * V_77 = V_2 -> V_77 ;
T_1 V_17 ;
V_2 -> V_14 . V_41 = V_2 -> V_447 ;
F_482 ( V_9 , V_850 ) ;
F_483 ( V_9 ) ;
F_484 ( V_9 ) ;
V_17 = F_485 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_106 ) ;
return V_17 ;
}
F_36 () ;
F_37 ( V_851 , & V_2 -> V_35 ) ;
F_486 ( V_9 ) ;
F_487 ( V_9 , false ) ;
F_426 ( V_2 ) ;
F_74 ( & V_2 -> V_14 , V_852 , ~ 0 ) ;
F_488 () ;
V_17 = F_489 ( V_2 ) ;
if ( ! V_17 && F_63 ( V_77 ) )
V_17 = F_472 ( V_77 ) ;
if ( ! V_17 )
F_490 ( V_77 ) ;
F_491 () ;
return V_17 ;
}
static int F_492 ( struct V_5 * V_9 , bool * V_853 )
{
struct V_1 * V_2 = F_481 ( V_9 ) ;
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_854 , V_638 ;
T_1 V_855 = V_2 -> V_761 ;
#ifdef F_493
int V_856 = 0 ;
#endif
F_488 () ;
F_494 ( V_77 ) ;
if ( F_63 ( V_77 ) )
F_475 ( V_2 ) ;
F_495 ( V_2 ) ;
F_491 () ;
#ifdef F_493
V_856 = F_484 ( V_9 ) ;
if ( V_856 )
return V_856 ;
#endif
if ( V_14 -> V_118 . V_374 . V_857 )
V_14 -> V_118 . V_374 . V_857 ( V_14 ) ;
if ( V_855 ) {
F_357 ( V_77 ) ;
if ( V_14 -> V_118 . V_374 . V_743 )
V_14 -> V_118 . V_374 . V_743 ( V_14 ) ;
if ( V_855 & V_858 ) {
V_638 = F_40 ( V_14 , V_642 ) ;
V_638 |= V_648 ;
F_74 ( V_14 , V_642 , V_638 ) ;
}
V_854 = F_40 ( V_14 , V_859 ) ;
V_854 |= V_860 ;
F_74 ( V_14 , V_859 , V_854 ) ;
F_74 ( V_14 , V_861 , V_855 ) ;
} else {
F_74 ( V_14 , V_862 , 0 ) ;
F_74 ( V_14 , V_861 , 0 ) ;
}
switch ( V_14 -> V_118 . type ) {
case V_119 :
F_487 ( V_9 , false ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
F_487 ( V_9 , ! ! V_855 ) ;
break;
default:
break;
}
* V_853 = ! ! V_855 ;
if ( V_14 -> V_46 . V_374 . V_744 && ! * V_853 )
V_14 -> V_46 . V_374 . V_744 ( V_14 , false ) ;
F_73 ( V_2 ) ;
if ( ! F_15 ( V_851 , & V_2 -> V_35 ) )
F_496 ( V_9 ) ;
return 0 ;
}
static int F_497 ( struct V_5 * V_9 , T_13 V_35 )
{
int V_856 ;
bool V_863 ;
V_856 = F_492 ( V_9 , & V_863 ) ;
if ( V_856 )
return V_856 ;
if ( V_863 ) {
F_498 ( V_9 ) ;
} else {
F_487 ( V_9 , false ) ;
F_482 ( V_9 , V_864 ) ;
}
return 0 ;
}
static void F_499 ( struct V_5 * V_9 )
{
bool V_863 ;
F_492 ( V_9 , & V_863 ) ;
if ( V_865 == V_866 ) {
F_487 ( V_9 , V_863 ) ;
F_482 ( V_9 , V_864 ) ;
}
}
void F_500 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_131 * V_132 = & V_2 -> V_133 ;
V_71 V_867 = 0 ;
T_1 V_49 , V_868 = 0 , V_869 , V_870 , V_871 , V_872 , V_873 ;
V_71 V_287 = 0 , V_192 = 0 , V_874 = 0 ;
V_71 V_254 = 0 , V_333 = 0 ;
V_71 V_188 = 0 , V_153 = 0 , V_875 = 0 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_750 , & V_2 -> V_35 ) )
return;
if ( V_2 -> V_369 & V_575 ) {
V_71 V_268 = 0 ;
V_71 V_269 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
V_268 += V_2 -> V_84 [ V_49 ] -> V_240 . V_268 ;
V_269 += V_2 -> V_84 [ V_49 ] -> V_240 . V_269 ;
}
V_2 -> V_876 = V_268 ;
V_2 -> V_877 = V_269 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
struct V_63 * V_84 = V_2 -> V_84 [ V_49 ] ;
V_287 += V_84 -> V_240 . V_287 ;
V_254 += V_84 -> V_240 . V_254 ;
V_333 += V_84 -> V_240 . V_333 ;
V_875 += V_84 -> V_240 . V_241 ;
V_188 += V_84 -> V_133 . V_188 ;
V_153 += V_84 -> V_133 . V_153 ;
}
V_2 -> V_287 = V_287 ;
V_2 -> V_254 = V_254 ;
V_2 -> V_333 = V_333 ;
V_2 -> V_875 = V_875 ;
V_77 -> V_133 . V_878 = V_188 ;
V_77 -> V_133 . V_879 = V_153 ;
V_188 = 0 ;
V_153 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ ) {
struct V_63 * V_92 = V_2 -> V_92 [ V_49 ] ;
V_192 += V_92 -> V_161 . V_192 ;
V_874 += V_92 -> V_161 . V_874 ;
V_188 += V_92 -> V_133 . V_188 ;
V_153 += V_92 -> V_133 . V_153 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ ) {
struct V_63 * V_94 = V_2 -> V_94 [ V_49 ] ;
V_192 += V_94 -> V_161 . V_192 ;
V_874 += V_94 -> V_161 . V_874 ;
V_188 += V_94 -> V_133 . V_188 ;
V_153 += V_94 -> V_133 . V_153 ;
}
V_2 -> V_192 = V_192 ;
V_2 -> V_874 = V_874 ;
V_77 -> V_133 . V_880 = V_188 ;
V_77 -> V_133 . V_881 = V_153 ;
V_132 -> V_882 += F_40 ( V_14 , V_883 ) ;
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
V_869 = F_40 ( V_14 , F_501 ( V_49 ) ) ;
V_868 += V_869 ;
V_132 -> V_869 [ V_49 ] += V_869 ;
V_867 += V_132 -> V_869 [ V_49 ] ;
V_132 -> V_884 [ V_49 ] += F_40 ( V_14 , F_502 ( V_49 ) ) ;
V_132 -> V_885 [ V_49 ] += F_40 ( V_14 , F_503 ( V_49 ) ) ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_132 -> V_886 [ V_49 ] += F_40 ( V_14 , F_504 ( V_49 ) ) ;
V_132 -> V_887 [ V_49 ] += F_40 ( V_14 , F_505 ( V_49 ) ) ;
V_132 -> V_888 [ V_49 ] += F_40 ( V_14 , F_506 ( V_49 ) ) ;
V_132 -> V_889 [ V_49 ] +=
F_40 ( V_14 , F_507 ( V_49 ) ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_132 -> V_889 [ V_49 ] +=
F_40 ( V_14 , F_508 ( V_49 ) ) ;
break;
default:
break;
}
}
for ( V_49 = 0 ; V_49 < 16 ; V_49 ++ ) {
V_132 -> V_890 [ V_49 ] += F_40 ( V_14 , F_509 ( V_49 ) ) ;
V_132 -> V_891 [ V_49 ] += F_40 ( V_14 , F_510 ( V_49 ) ) ;
if ( ( V_14 -> V_118 . type == V_121 ) ||
( V_14 -> V_118 . type == V_122 ) ||
( V_14 -> V_118 . type == V_123 ) ||
( V_14 -> V_118 . type == V_124 ) ||
( V_14 -> V_118 . type == V_125 ) ) {
V_132 -> V_887 [ V_49 ] += F_40 ( V_14 , F_511 ( V_49 ) ) ;
F_40 ( V_14 , F_512 ( V_49 ) ) ;
V_132 -> V_888 [ V_49 ] += F_40 ( V_14 , F_513 ( V_49 ) ) ;
F_40 ( V_14 , F_514 ( V_49 ) ) ;
}
}
V_132 -> V_892 += F_40 ( V_14 , V_893 ) ;
V_132 -> V_892 -= V_868 ;
F_81 ( V_2 ) ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_132 -> V_894 += F_40 ( V_14 , V_895 ) ;
V_132 -> V_896 += F_40 ( V_14 , V_897 ) ;
V_132 -> V_898 += F_40 ( V_14 , V_899 ) ;
V_132 -> V_900 += F_40 ( V_14 , V_901 ) ;
break;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_132 -> V_902 += F_40 ( V_14 , V_903 ) ;
V_132 -> V_904 += F_40 ( V_14 , V_905 ) ;
V_132 -> V_906 += F_40 ( V_14 , V_907 ) ;
V_132 -> V_908 += F_40 ( V_14 , V_909 ) ;
case V_121 :
for ( V_49 = 0 ; V_49 < 16 ; V_49 ++ )
V_2 -> V_910 +=
F_40 ( V_14 , F_515 ( V_49 ) ) ;
V_132 -> V_896 += F_40 ( V_14 , V_911 ) ;
F_40 ( V_14 , V_897 ) ;
V_132 -> V_898 += F_40 ( V_14 , V_912 ) ;
F_40 ( V_14 , V_899 ) ;
V_132 -> V_900 += F_40 ( V_14 , V_913 ) ;
F_40 ( V_14 , V_901 ) ;
V_132 -> V_894 += F_40 ( V_14 , V_914 ) ;
V_132 -> V_915 += F_40 ( V_14 , V_916 ) ;
V_132 -> V_917 += F_40 ( V_14 , V_918 ) ;
#ifdef F_184
V_132 -> V_919 += F_40 ( V_14 , V_920 ) ;
V_132 -> V_921 += F_40 ( V_14 , V_922 ) ;
V_132 -> V_923 += F_40 ( V_14 , V_924 ) ;
V_132 -> V_925 += F_40 ( V_14 , V_926 ) ;
V_132 -> V_927 += F_40 ( V_14 , V_928 ) ;
V_132 -> V_929 += F_40 ( V_14 , V_930 ) ;
if ( V_2 -> V_681 . V_931 ) {
struct V_932 * V_681 = & V_2 -> V_681 ;
struct V_933 * V_931 ;
unsigned int V_193 ;
V_71 V_934 = 0 , V_935 = 0 ;
F_516 (cpu) {
V_931 = F_517 ( V_681 -> V_931 , V_193 ) ;
V_934 += V_931 -> V_934 ;
V_935 += V_931 -> V_935 ;
}
V_132 -> V_936 = V_934 ;
V_132 -> V_937 = V_935 ;
}
#endif
break;
default:
break;
}
V_870 = F_40 ( V_14 , V_938 ) ;
V_132 -> V_870 += V_870 ;
V_132 -> V_939 += F_40 ( V_14 , V_940 ) ;
if ( V_14 -> V_118 . type == V_119 )
V_132 -> V_939 -= V_870 ;
V_132 -> V_941 += F_40 ( V_14 , V_942 ) ;
V_132 -> V_943 += F_40 ( V_14 , V_944 ) ;
V_132 -> V_945 += F_40 ( V_14 , V_946 ) ;
V_132 -> V_947 += F_40 ( V_14 , V_948 ) ;
V_132 -> V_949 += F_40 ( V_14 , V_950 ) ;
V_132 -> V_951 += F_40 ( V_14 , V_952 ) ;
V_132 -> V_953 += F_40 ( V_14 , V_954 ) ;
V_132 -> V_955 += F_40 ( V_14 , V_956 ) ;
V_871 = F_40 ( V_14 , V_957 ) ;
V_132 -> V_958 += V_871 ;
V_872 = F_40 ( V_14 , V_959 ) ;
V_132 -> V_960 += V_872 ;
V_132 -> V_961 += F_40 ( V_14 , V_962 ) ;
V_132 -> V_963 += F_40 ( V_14 , V_964 ) ;
V_873 = V_871 + V_872 ;
V_132 -> V_961 -= V_873 ;
V_132 -> V_963 -= V_873 ;
V_132 -> V_898 -= ( V_873 * ( V_965 + V_563 ) ) ;
V_132 -> V_966 += F_40 ( V_14 , V_967 ) ;
V_132 -> V_968 += F_40 ( V_14 , V_969 ) ;
V_132 -> V_970 += F_40 ( V_14 , V_971 ) ;
V_132 -> V_972 += F_40 ( V_14 , V_973 ) ;
V_132 -> V_974 += F_40 ( V_14 , V_975 ) ;
V_132 -> V_974 -= V_873 ;
V_132 -> V_976 += F_40 ( V_14 , V_977 ) ;
V_132 -> V_978 += F_40 ( V_14 , V_979 ) ;
V_132 -> V_980 += F_40 ( V_14 , V_981 ) ;
V_132 -> V_982 += F_40 ( V_14 , V_983 ) ;
V_132 -> V_984 += F_40 ( V_14 , V_985 ) ;
V_132 -> V_986 += F_40 ( V_14 , V_987 ) ;
V_77 -> V_133 . V_988 = V_132 -> V_939 ;
V_77 -> V_133 . V_989 = V_132 -> V_882 + V_132 -> V_955 ;
V_77 -> V_133 . V_990 = 0 ;
V_77 -> V_133 . V_991 = V_132 -> V_955 ;
V_77 -> V_133 . V_992 = V_132 -> V_882 ;
V_77 -> V_133 . V_993 = V_867 ;
}
static void F_518 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( ! ( V_2 -> V_369 & V_411 ) )
return;
V_2 -> V_369 &= ~ V_411 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
if ( ! ( V_2 -> V_148 & V_410 ) )
return;
V_2 -> V_994 ++ ;
if ( F_519 ( V_14 ) == 0 ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ )
F_91 ( V_420 ,
& ( V_2 -> V_92 [ V_49 ] -> V_35 ) ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ )
F_91 ( V_420 ,
& V_2 -> V_94 [ V_49 ] -> V_35 ) ;
F_74 ( V_14 , V_401 , V_412 ) ;
} else {
F_107 ( V_190 , L_107
L_108 ) ;
}
}
static void F_520 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_71 V_995 = 0 ;
int V_49 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_750 , & V_2 -> V_35 ) )
return;
if ( F_113 ( V_2 -> V_77 ) ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ )
F_521 ( V_2 -> V_92 [ V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ )
F_521 ( V_2 -> V_94 [ V_49 ] ) ;
}
if ( ! ( V_2 -> V_148 & V_438 ) ) {
F_74 ( V_14 , V_130 ,
( V_996 | V_997 ) ) ;
} else {
for ( V_49 = 0 ; V_49 < V_2 -> V_210 ; V_49 ++ ) {
struct V_173 * V_998 = V_2 -> V_174 [ V_49 ] ;
if ( V_998 -> V_338 . V_64 || V_998 -> V_179 . V_64 )
V_995 |= F_261 ( V_49 ) ;
}
}
F_78 ( V_2 , V_995 ) ;
}
static void F_522 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_999 = V_2 -> V_999 ;
bool V_376 = V_2 -> V_376 ;
bool V_144 = V_2 -> V_145 . V_146 ;
if ( ! ( V_2 -> V_148 & V_398 ) )
return;
if ( V_14 -> V_118 . V_374 . V_375 ) {
V_14 -> V_118 . V_374 . V_375 ( V_14 , & V_999 , & V_376 , false ) ;
} else {
V_999 = V_1000 ;
V_376 = true ;
}
if ( V_2 -> V_147 )
V_144 |= ! ! ( V_2 -> V_147 -> V_144 ) ;
if ( V_376 && ! ( ( V_2 -> V_148 & V_149 ) && V_144 ) ) {
V_14 -> V_118 . V_374 . V_1001 ( V_14 ) ;
F_523 ( V_2 ) ;
}
if ( V_376 ||
F_524 ( V_189 , ( V_2 -> V_399 +
V_1002 ) ) ) {
V_2 -> V_148 &= ~ V_398 ;
F_74 ( V_14 , V_401 , V_400 ) ;
F_242 ( V_14 ) ;
}
V_2 -> V_376 = V_376 ;
V_2 -> V_999 = V_999 ;
}
static void F_525 ( struct V_1 * V_2 )
{
#ifdef F_407
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_1003 V_1004 = {
. V_1005 = V_1006 ,
. V_276 = 0 ,
} ;
T_4 V_682 = 0 ;
if ( V_2 -> V_667 & V_1007 )
V_682 = F_526 ( V_77 , & V_1004 ) ;
V_2 -> V_1008 = ( V_682 > 1 ) ? ( F_527 ( V_682 ) - 1 ) : 0 ;
#endif
}
static int F_528 ( struct V_76 * V_106 , void * V_103 )
{
if ( F_403 ( V_106 ) ) {
struct V_716 * V_274 = F_87 ( V_106 ) ;
if ( V_274 -> V_718 )
F_529 ( V_106 ) ;
}
return 0 ;
}
static void F_530 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_999 = V_2 -> V_999 ;
const char * V_1009 ;
bool V_1010 , V_1011 ;
if ( F_113 ( V_77 ) )
return;
V_2 -> V_369 &= ~ V_721 ;
switch ( V_14 -> V_118 . type ) {
case V_119 : {
T_1 V_1012 = F_40 ( V_14 , V_642 ) ;
T_1 V_1013 = F_40 ( V_14 , V_1014 ) ;
V_1010 = ! ! ( V_1012 & V_1015 ) ;
V_1011 = ! ! ( V_1013 & V_1016 ) ;
}
break;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_121 : {
T_1 V_1017 = F_40 ( V_14 , V_1018 ) ;
T_1 V_1019 = F_40 ( V_14 , V_1020 ) ;
V_1010 = ! ! ( V_1017 & V_1021 ) ;
V_1011 = ! ! ( V_1019 & V_1022 ) ;
}
break;
default:
V_1011 = false ;
V_1010 = false ;
break;
}
V_2 -> V_1023 = V_189 ;
if ( F_14 ( V_760 , & V_2 -> V_35 ) )
F_531 ( V_2 ) ;
switch ( V_999 ) {
case V_1000 :
V_1009 = L_109 ;
break;
case V_1024 :
V_1009 = L_110 ;
break;
case V_1025 :
V_1009 = L_111 ;
break;
case V_1026 :
V_1009 = L_112 ;
break;
case V_1027 :
V_1009 = L_113 ;
break;
default:
V_1009 = L_114 ;
break;
}
F_109 ( V_164 , L_115 , V_1009 ,
( ( V_1010 && V_1011 ) ? L_116 :
( V_1010 ? L_117 :
( V_1011 ? L_118 : L_119 ) ) ) ) ;
F_532 ( V_77 ) ;
F_533 ( V_2 ) ;
F_529 ( V_2 -> V_77 ) ;
F_488 () ;
F_405 ( V_2 -> V_77 ,
F_528 , NULL ) ;
F_491 () ;
F_525 ( V_2 ) ;
F_440 ( V_2 ) ;
}
static void F_422 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_376 = false ;
V_2 -> V_999 = 0 ;
if ( ! F_113 ( V_77 ) )
return;
if ( F_238 ( V_14 ) && V_14 -> V_118 . type == V_119 )
V_2 -> V_369 |= V_721 ;
if ( F_14 ( V_760 , & V_2 -> V_35 ) )
F_531 ( V_2 ) ;
F_109 ( V_164 , L_120 ) ;
F_436 ( V_77 ) ;
F_440 ( V_2 ) ;
}
static bool F_534 ( struct V_1 * V_2 )
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
static bool F_535 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1028 * V_1029 = & V_2 -> V_463 [ V_464 ] ;
T_1 V_1030 = F_536 ( 1 , ~ V_1029 -> V_128 ) ;
int V_49 , V_60 ;
if ( ! V_2 -> V_340 )
return false ;
if ( V_14 -> V_118 . type >= V_123 )
return false ;
for ( V_49 = 0 ; V_49 < V_2 -> V_340 ; V_49 ++ ) {
for ( V_60 = 0 ; V_60 < V_1030 ; V_60 ++ ) {
T_1 V_1031 , V_1032 ;
V_1031 = F_40 ( V_14 , F_537 ( V_1030 , V_49 , V_60 ) ) ;
V_1032 = F_40 ( V_14 , F_538 ( V_1030 , V_49 , V_60 ) ) ;
if ( V_1031 != V_1032 )
return true ;
}
}
return false ;
}
static void F_539 ( struct V_1 * V_2 )
{
if ( ! F_113 ( V_2 -> V_77 ) ) {
if ( F_534 ( V_2 ) ||
F_535 ( V_2 ) ) {
F_27 ( V_164 , L_121 ) ;
F_91 ( V_163 , & V_2 -> V_35 ) ;
}
}
}
static void F_540 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_1033 ;
T_1 V_1034 ;
if ( ! ( F_113 ( V_2 -> V_77 ) ) )
return;
V_1034 = F_40 ( V_14 , V_1035 ) ;
if ( V_1034 )
return;
if ( ! V_9 )
return;
for ( V_1033 = 0 ; V_1033 < V_2 -> V_340 ; ++ V_1033 ) {
struct V_5 * V_1036 = V_2 -> V_558 [ V_1033 ] . V_1036 ;
T_2 V_1037 ;
if ( ! V_1036 )
continue;
F_28 ( V_1036 , V_1038 , & V_1037 ) ;
if ( V_1037 != V_13 &&
V_1037 & V_1039 )
F_541 ( V_1036 ) ;
}
}
static void F_542 ( struct V_1 * V_2 )
{
T_1 V_1040 ;
if ( V_2 -> V_14 . V_118 . type == V_119 ||
V_2 -> V_340 == 0 )
return;
V_1040 = F_40 ( & V_2 -> V_14 , V_1041 ) ;
if ( ! V_1040 )
return;
F_27 ( V_164 , L_122 , V_1040 ) ;
}
static void F_542 ( struct V_1 T_14 * V_2 )
{
}
static void
F_540 ( struct V_1 T_14 * V_2 )
{
}
static void F_543 ( struct V_1 * V_2 )
{
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_750 , & V_2 -> V_35 ) )
return;
F_522 ( V_2 ) ;
if ( V_2 -> V_376 )
F_530 ( V_2 ) ;
else
F_422 ( V_2 ) ;
F_540 ( V_2 ) ;
F_542 ( V_2 ) ;
F_500 ( V_2 ) ;
F_539 ( V_2 ) ;
}
static void F_544 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_3 V_17 ;
if ( ! ( V_2 -> V_369 & V_721 ) &&
! ( V_2 -> V_369 & V_394 ) )
return;
if ( V_2 -> V_395 &&
F_524 ( V_2 -> V_395 , V_189 ) )
return;
if ( F_15 ( V_752 , & V_2 -> V_35 ) )
return;
V_2 -> V_395 = V_189 + V_1042 - 1 ;
V_17 = V_14 -> V_46 . V_374 . V_1043 ( V_14 ) ;
if ( V_17 == V_755 )
goto V_1044;
if ( V_17 == V_754 ) {
V_2 -> V_369 |= V_394 ;
}
if ( V_17 )
goto V_1044;
if ( ! ( V_2 -> V_369 & V_394 ) )
goto V_1044;
V_2 -> V_369 &= ~ V_394 ;
if ( V_14 -> V_118 . type == V_119 )
V_17 = V_14 -> V_46 . V_374 . V_1045 ( V_14 ) ;
else
V_17 = V_14 -> V_118 . V_374 . V_1046 ( V_14 ) ;
if ( V_17 == V_755 )
goto V_1044;
V_2 -> V_148 |= V_396 ;
F_109 ( V_190 , L_123 , V_14 -> V_46 . V_1047 ) ;
V_1044:
F_37 ( V_752 , & V_2 -> V_35 ) ;
if ( ( V_17 == V_755 ) &&
( V_2 -> V_77 -> V_1048 == V_1049 ) ) {
F_18 ( L_124
L_125 ) ;
F_18 ( L_126
L_127 ) ;
F_545 ( V_2 -> V_77 ) ;
}
}
static void F_546 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_20 ;
bool V_722 = false ;
if ( ! ( V_2 -> V_148 & V_396 ) )
return;
if ( F_15 ( V_752 , & V_2 -> V_35 ) )
return;
V_2 -> V_148 &= ~ V_396 ;
V_20 = V_14 -> V_46 . V_724 ;
if ( ( ! V_20 ) && ( V_14 -> V_118 . V_374 . V_725 ) ) {
V_14 -> V_118 . V_374 . V_725 ( V_14 , & V_20 , & V_722 ) ;
if ( ! V_722 ) {
if ( V_20 & V_1000 )
V_20 = V_1000 ;
}
}
if ( V_14 -> V_118 . V_374 . V_726 )
V_14 -> V_118 . V_374 . V_726 ( V_14 , V_20 , true ) ;
V_2 -> V_148 |= V_398 ;
V_2 -> V_399 = V_189 ;
F_37 ( V_752 , & V_2 -> V_35 ) ;
}
static void F_547 ( unsigned long V_103 )
{
struct V_1 * V_2 = (struct V_1 * ) V_103 ;
unsigned long V_1050 ;
if ( V_2 -> V_148 & V_398 )
V_1050 = V_1051 / 10 ;
else
V_1050 = V_1051 * 2 ;
F_417 ( & V_2 -> V_748 , V_1050 + V_189 ) ;
F_13 ( V_2 ) ;
}
static void F_548 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_182 ;
if ( ! ( V_2 -> V_369 & V_415 ) )
return;
V_2 -> V_369 &= ~ V_415 ;
if ( ! V_14 -> V_46 . V_374 . V_1052 )
return;
V_182 = V_14 -> V_46 . V_374 . V_1052 ( & V_2 -> V_14 ) ;
if ( V_182 != V_378 )
return;
F_234 ( V_164 , L_69 , V_381 ) ;
}
static void F_549 ( struct V_1 * V_2 )
{
if ( ! F_253 ( V_163 , & V_2 -> V_35 ) )
return;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_750 , & V_2 -> V_35 ) )
return;
F_59 ( V_2 ) ;
F_550 ( V_2 -> V_77 , L_128 ) ;
V_2 -> V_191 ++ ;
F_488 () ;
F_418 ( V_2 ) ;
F_491 () ;
}
static void F_551 ( struct V_1053 * V_1054 )
{
struct V_1 * V_2 = F_258 ( V_1054 ,
struct V_1 ,
V_39 ) ;
if ( F_22 ( V_2 -> V_14 . V_41 ) ) {
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_488 () ;
F_423 ( V_2 ) ;
F_491 () ;
}
F_34 ( V_2 ) ;
return;
}
if ( V_2 -> V_369 & V_1055 ) {
F_488 () ;
V_2 -> V_369 &= ~ V_1055 ;
F_474 ( V_2 -> V_77 ) ;
F_491 () ;
}
F_549 ( V_2 ) ;
F_548 ( V_2 ) ;
F_544 ( V_2 ) ;
F_546 ( V_2 ) ;
F_232 ( V_2 ) ;
F_543 ( V_2 ) ;
F_518 ( V_2 ) ;
F_520 ( V_2 ) ;
if ( F_14 ( V_760 , & V_2 -> V_35 ) ) {
F_552 ( V_2 ) ;
F_553 ( V_2 ) ;
F_554 ( V_2 ) ;
}
F_34 ( V_2 ) ;
}
static int F_555 ( struct V_63 * V_92 ,
struct V_66 * V_1056 ,
T_4 * V_263 )
{
T_1 V_1057 , V_1058 , V_1059 ;
struct V_216 * V_100 = V_1056 -> V_100 ;
union {
struct V_1060 * V_1061 ;
struct V_1062 * V_1063 ;
unsigned char * V_1064 ;
} V_1065 ;
union {
struct V_1066 * V_1067 ;
unsigned char * V_1064 ;
} V_1068 ;
T_1 V_1069 , V_1070 ;
int V_17 ;
if ( V_100 -> V_246 != V_1071 )
return 0 ;
if ( ! F_556 ( V_100 ) )
return 0 ;
V_17 = F_557 ( V_100 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( F_558 ( V_1056 -> V_276 ) )
V_1065 . V_1064 = F_559 ( V_100 ) ;
else
V_1065 . V_1064 = F_560 ( V_100 ) ;
V_1068 . V_1064 = F_561 ( V_100 ) ;
V_1058 = V_1072 ;
if ( V_1065 . V_1061 -> V_1073 == 4 ) {
unsigned char * V_1074 = F_561 ( V_100 ) ;
unsigned char * V_1075 = V_1065 . V_1064 + ( V_1065 . V_1061 -> V_1076 * 4 ) ;
V_1065 . V_1061 -> V_1077 = F_562 ( F_563 ( V_1075 ,
V_1074 - V_1075 ,
0 ) ) ;
V_1058 |= V_1078 ;
V_1065 . V_1061 -> V_1079 = 0 ;
V_1056 -> V_1080 |= V_1081 |
V_1082 |
V_1083 ;
} else {
V_1065 . V_1063 -> V_1084 = 0 ;
V_1056 -> V_1080 |= V_1081 |
V_1082 ;
}
V_1070 = V_1068 . V_1064 - V_100 -> V_103 ;
* V_263 = ( V_1068 . V_1067 -> V_1085 * 4 ) + V_1070 ;
V_1069 = V_100 -> V_73 - V_1070 ;
F_564 ( & V_1068 . V_1067 -> V_1077 , F_565 ( V_1069 ) ) ;
V_1056 -> V_185 = F_157 ( V_100 ) -> V_185 ;
V_1056 -> V_184 += ( V_1056 -> V_185 - 1 ) * * V_263 ;
V_1059 = ( * V_263 - V_1070 ) << V_1086 ;
V_1059 |= F_157 ( V_100 ) -> V_264 << V_1087 ;
V_1057 = V_1068 . V_1064 - V_1065 . V_1064 ;
V_1057 |= ( V_1065 . V_1064 - V_100 -> V_103 ) << V_1088 ;
V_1057 |= V_1056 -> V_1080 & V_1089 ;
F_566 ( V_92 , V_1057 , 0 , V_1058 ,
V_1059 ) ;
return 1 ;
}
static inline bool F_567 ( struct V_216 * V_100 )
{
unsigned int V_1090 = 0 ;
F_568 ( V_100 , & V_1090 , V_1091 , NULL , NULL ) ;
return V_1090 == F_569 ( V_100 ) ;
}
static void F_570 ( struct V_63 * V_92 ,
struct V_66 * V_1056 )
{
struct V_216 * V_100 = V_1056 -> V_100 ;
T_1 V_1057 = 0 ;
T_1 V_1058 = 0 ;
if ( V_100 -> V_246 != V_1071 ) {
V_1092:
if ( ! ( V_1056 -> V_1080 & ( V_1093 |
V_1094 ) ) )
return;
goto V_1095;
}
switch ( V_100 -> V_1096 ) {
case F_571 ( struct V_1066 , V_1077 ) :
V_1058 = V_1072 ;
case F_571 ( struct V_1097 , V_1077 ) :
break;
case F_571 ( struct V_1098 , V_1099 ) :
if ( ( ( V_1056 -> V_276 == F_164 ( V_1100 ) ) &&
( F_572 ( V_100 ) -> V_276 == V_1091 ) ) ||
( ( V_1056 -> V_276 == F_164 ( V_1101 ) ) &&
F_567 ( V_100 ) ) ) {
V_1058 = V_1102 ;
break;
}
default:
F_573 ( V_100 ) ;
goto V_1092;
}
V_1056 -> V_1080 |= V_1082 ;
V_1057 = F_569 ( V_100 ) -
F_574 ( V_100 ) ;
V_1095:
V_1057 |= F_574 ( V_100 ) << V_1088 ;
V_1057 |= V_1056 -> V_1080 & V_1089 ;
F_566 ( V_92 , V_1057 , 0 , V_1058 , 0 ) ;
}
static T_1 F_575 ( struct V_216 * V_100 , T_1 V_1080 )
{
T_1 V_1103 = V_1104 |
V_1105 |
V_1106 ;
V_1103 |= F_576 ( V_1080 , V_1093 ,
V_1107 ) ;
V_1103 |= F_576 ( V_1080 , V_1081 ,
V_1108 ) ;
V_1103 |= F_576 ( V_1080 , V_1109 ,
V_1110 ) ;
V_1103 ^= F_576 ( V_100 -> V_1111 , 1 , V_1106 ) ;
return V_1103 ;
}
static void F_577 ( union V_78 * V_79 ,
T_1 V_1080 , unsigned int V_1069 )
{
T_1 V_1112 = V_1069 << V_1113 ;
V_1112 |= F_576 ( V_1080 ,
V_1082 ,
V_1114 ) ;
V_1112 |= F_576 ( V_1080 ,
V_1083 ,
V_1115 ) ;
V_1112 |= F_576 ( V_1080 ,
V_1094 ,
V_1116 ) ;
V_79 -> V_260 . V_1112 = F_96 ( V_1112 ) ;
}
static int F_578 ( struct V_63 * V_92 , T_2 V_304 )
{
F_108 ( V_92 -> V_77 , V_92 -> V_96 ) ;
F_115 () ;
if ( F_25 ( F_114 ( V_92 ) < V_304 ) )
return - V_843 ;
F_579 ( V_92 -> V_77 , V_92 -> V_96 ) ;
++ V_92 -> V_161 . V_192 ;
return 0 ;
}
static inline int F_580 ( struct V_63 * V_92 , T_2 V_304 )
{
if ( F_25 ( F_114 ( V_92 ) >= V_304 ) )
return 0 ;
return F_578 ( V_92 , V_304 ) ;
}
static int F_581 ( struct V_63 * V_92 ,
struct V_66 * V_1056 ,
const T_4 V_263 )
{
struct V_216 * V_100 = V_1056 -> V_100 ;
struct V_66 * V_67 ;
union V_78 * V_79 ;
struct V_288 * V_289 ;
T_8 V_72 ;
unsigned int V_294 , V_304 ;
T_1 V_1080 = V_1056 -> V_1080 ;
T_1 V_1103 = F_575 ( V_100 , V_1080 ) ;
T_2 V_49 = V_92 -> V_70 ;
V_79 = F_65 ( V_92 , V_49 ) ;
F_577 ( V_79 , V_1080 , V_100 -> V_73 - V_263 ) ;
V_304 = F_156 ( V_100 ) ;
V_294 = V_100 -> V_294 ;
#ifdef F_184
if ( V_1080 & V_1117 ) {
if ( V_294 < sizeof( struct V_337 ) ) {
V_304 -= sizeof( struct V_337 ) - V_294 ;
V_294 = 0 ;
} else {
V_294 -= sizeof( struct V_337 ) ;
}
}
#endif
V_72 = F_582 ( V_92 -> V_89 , V_100 -> V_103 , V_304 , V_186 ) ;
V_67 = V_1056 ;
for ( V_289 = & F_157 ( V_100 ) -> V_290 [ 0 ] ; ; V_289 ++ ) {
if ( F_148 ( V_92 -> V_89 , V_72 ) )
goto V_1118;
F_101 ( V_67 , V_73 , V_304 ) ;
F_583 ( V_67 , V_72 , V_72 ) ;
V_79 -> V_260 . V_1119 = F_152 ( V_72 ) ;
while ( F_23 ( V_304 > V_1120 ) ) {
V_79 -> V_260 . V_1121 =
F_96 ( V_1103 ^ V_1120 ) ;
V_49 ++ ;
V_79 ++ ;
if ( V_49 == V_92 -> V_98 ) {
V_79 = F_65 ( V_92 , 0 ) ;
V_49 = 0 ;
}
V_79 -> V_260 . V_1112 = 0 ;
V_72 += V_1120 ;
V_304 -= V_1120 ;
V_79 -> V_260 . V_1119 = F_152 ( V_72 ) ;
}
if ( F_25 ( ! V_294 ) )
break;
V_79 -> V_260 . V_1121 = F_96 ( V_1103 ^ V_304 ) ;
V_49 ++ ;
V_79 ++ ;
if ( V_49 == V_92 -> V_98 ) {
V_79 = F_65 ( V_92 , 0 ) ;
V_49 = 0 ;
}
V_79 -> V_260 . V_1112 = 0 ;
#ifdef F_184
V_304 = F_355 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_304 = F_180 ( V_289 ) ;
#endif
V_294 -= V_304 ;
V_72 = F_584 ( V_92 -> V_89 , V_289 , 0 , V_304 ,
V_186 ) ;
V_67 = & V_92 -> V_68 [ V_49 ] ;
}
V_1103 |= V_304 | V_1122 ;
V_79 -> V_260 . V_1121 = F_96 ( V_1103 ) ;
F_585 ( F_111 ( V_92 ) , V_1056 -> V_184 ) ;
V_1056 -> V_75 = V_189 ;
F_153 () ;
V_1056 -> V_74 = V_79 ;
V_49 ++ ;
if ( V_49 == V_92 -> V_98 )
V_49 = 0 ;
V_92 -> V_70 = V_49 ;
F_580 ( V_92 , V_1123 ) ;
if ( F_586 ( F_111 ( V_92 ) ) || ! V_100 -> V_1124 ) {
F_154 ( V_49 , V_92 -> V_155 ) ;
F_587 () ;
}
return 0 ;
V_1118:
F_460 ( V_92 -> V_89 , L_129 ) ;
for (; ; ) {
V_67 = & V_92 -> V_68 [ V_49 ] ;
if ( F_58 ( V_67 , V_73 ) )
F_102 ( V_92 -> V_89 ,
F_57 ( V_67 , V_72 ) ,
F_58 ( V_67 , V_73 ) ,
V_186 ) ;
F_101 ( V_67 , V_73 , 0 ) ;
if ( V_67 == V_1056 )
break;
if ( V_49 == 0 )
V_49 += V_92 -> V_98 ;
V_49 -- ;
}
F_183 ( V_1056 -> V_100 ) ;
V_1056 -> V_100 = NULL ;
V_92 -> V_70 = V_49 ;
return - 1 ;
}
static void F_588 ( struct V_63 * V_64 ,
struct V_66 * V_1056 )
{
struct V_173 * V_174 = V_64 -> V_174 ;
union V_1125 V_1126 = { . V_1127 = 0 } ;
union V_1125 V_1128 = { . V_1127 = 0 } ;
union {
unsigned char * V_1129 ;
struct V_1060 * V_1130 ;
struct V_1062 * V_1131 ;
} V_1064 ;
struct V_1066 * V_1132 ;
unsigned int V_1133 ;
struct V_216 * V_100 ;
T_11 V_1134 ;
int V_1135 ;
if ( ! V_174 )
return;
if ( ! V_64 -> V_448 )
return;
V_64 -> V_449 ++ ;
if ( ( V_1056 -> V_276 != F_164 ( V_1100 ) ) &&
( V_1056 -> V_276 != F_164 ( V_1101 ) ) )
return;
V_100 = V_1056 -> V_100 ;
V_1064 . V_1129 = F_560 ( V_100 ) ;
if ( F_23 ( V_1064 . V_1129 <= V_100 -> V_103 ) )
return;
if ( V_100 -> V_237 &&
V_1056 -> V_276 == F_164 ( V_1100 ) &&
V_1064 . V_1130 -> V_276 == V_1136 ) {
struct V_1 * V_2 = V_174 -> V_2 ;
if ( F_23 ( F_589 ( V_100 ) < V_1064 . V_1129 +
V_1137 ) )
return;
if ( V_2 -> V_663 &&
F_590 ( V_100 ) -> V_1138 == V_2 -> V_663 )
V_1064 . V_1129 = F_559 ( V_100 ) ;
if ( V_2 -> V_665 &&
F_590 ( V_100 ) -> V_1138 == V_2 -> V_665 )
V_1064 . V_1129 = F_559 ( V_100 ) ;
}
if ( F_23 ( F_589 ( V_100 ) < V_1064 . V_1129 + 40 ) )
return;
switch ( V_1064 . V_1130 -> V_1073 ) {
case V_1139 :
V_1133 = ( V_1064 . V_1129 [ 0 ] & 0x0F ) << 2 ;
V_1135 = V_1064 . V_1130 -> V_276 ;
break;
case 6 :
V_1133 = V_1064 . V_1129 - V_100 -> V_103 ;
V_1135 = F_568 ( V_100 , & V_1133 , V_1140 , NULL , NULL ) ;
V_1133 -= V_1064 . V_1129 - V_100 -> V_103 ;
break;
default:
return;
}
if ( V_1135 != V_1140 )
return;
if ( F_23 ( F_589 ( V_100 ) < V_1064 . V_1129 +
V_1133 + sizeof( struct V_1066 ) ) )
return;
V_1132 = (struct V_1066 * ) ( V_1064 . V_1129 + V_1133 ) ;
if ( V_1132 -> V_1141 )
return;
if ( ! V_1132 -> V_1142 && ( V_64 -> V_449 < V_64 -> V_448 ) )
return;
V_64 -> V_449 = 0 ;
V_1134 = F_164 ( V_1056 -> V_1080 >> V_1143 ) ;
V_1126 . V_1144 . V_1134 = V_1134 ;
if ( V_1056 -> V_1080 & ( V_1145 | V_1093 ) )
V_1128 . V_1146 . V_1147 ^= V_1132 -> V_1138 ^ F_164 ( V_275 ) ;
else
V_1128 . V_1146 . V_1147 ^= V_1132 -> V_1138 ^ V_1056 -> V_276 ;
V_1128 . V_1146 . V_1148 ^= V_1132 -> V_1149 ;
switch ( V_1064 . V_1130 -> V_1073 ) {
case V_1139 :
V_1126 . V_1144 . V_1150 = V_1151 ;
V_1128 . V_1065 ^= V_1064 . V_1130 -> V_1152 ^ V_1064 . V_1130 -> V_1153 ;
break;
case 6 :
V_1126 . V_1144 . V_1150 = V_1154 ;
V_1128 . V_1065 ^= V_1064 . V_1131 -> V_1152 . V_1155 [ 0 ] ^
V_1064 . V_1131 -> V_1152 . V_1155 [ 1 ] ^
V_1064 . V_1131 -> V_1152 . V_1155 [ 2 ] ^
V_1064 . V_1131 -> V_1152 . V_1155 [ 3 ] ^
V_1064 . V_1131 -> V_1153 . V_1155 [ 0 ] ^
V_1064 . V_1131 -> V_1153 . V_1155 [ 1 ] ^
V_1064 . V_1131 -> V_1153 . V_1155 [ 2 ] ^
V_1064 . V_1131 -> V_1153 . V_1155 [ 3 ] ;
break;
default:
break;
}
if ( V_1064 . V_1129 != F_560 ( V_100 ) )
V_1126 . V_1144 . V_1150 |= V_1156 ;
F_591 ( & V_174 -> V_2 -> V_14 ,
V_1126 , V_1128 , V_64 -> V_96 ) ;
}
static T_2 F_592 ( struct V_76 * V_89 , struct V_216 * V_100 ,
void * V_1157 , T_15 V_1158 )
{
struct V_702 * V_1159 = V_1157 ;
#ifdef F_184
struct V_1 * V_2 ;
struct V_1028 * V_1160 ;
int V_1161 ;
#endif
if ( V_1159 )
return V_100 -> V_1162 + V_1159 -> V_710 ;
#ifdef F_184
switch ( F_593 ( V_100 ) ) {
case F_164 ( V_1163 ) :
case F_164 ( V_1164 ) :
V_2 = F_87 ( V_89 ) ;
if ( V_2 -> V_148 & V_566 )
break;
default:
return V_1158 ( V_89 , V_100 ) ;
}
V_1160 = & V_2 -> V_463 [ V_1165 ] ;
V_1161 = F_594 ( V_100 ) ? F_595 ( V_100 ) :
F_223 () ;
while ( V_1161 >= V_1160 -> V_497 )
V_1161 -= V_1160 -> V_497 ;
return V_1161 + V_1160 -> V_1090 ;
#else
return V_1158 ( V_89 , V_100 ) ;
#endif
}
static int F_212 ( struct V_1 * V_2 ,
struct V_308 * V_309 )
{
struct V_63 * V_64 = V_2 -> V_94 [ F_223 () ] ;
struct V_66 * V_67 ;
union V_78 * V_79 ;
T_1 V_73 , V_1103 ;
T_8 V_72 ;
T_2 V_49 ;
V_73 = V_309 -> V_310 - V_309 -> V_103 ;
if ( F_23 ( ! F_114 ( V_64 ) ) )
return V_324 ;
V_72 = F_582 ( V_64 -> V_89 , V_309 -> V_103 , V_73 , V_186 ) ;
if ( F_148 ( V_64 -> V_89 , V_72 ) )
return V_324 ;
V_67 = & V_64 -> V_68 [ V_64 -> V_70 ] ;
V_67 -> V_184 = V_73 ;
V_67 -> V_185 = 1 ;
V_67 -> V_276 = 0 ;
V_49 = V_64 -> V_70 ;
V_79 = F_65 ( V_64 , V_49 ) ;
F_101 ( V_67 , V_73 , V_73 ) ;
F_583 ( V_67 , V_72 , V_72 ) ;
V_67 -> V_103 = V_309 -> V_103 ;
V_79 -> V_260 . V_1119 = F_152 ( V_72 ) ;
V_1103 = V_1104 |
V_1105 |
V_1106 ;
V_1103 |= V_73 | V_1122 ;
V_79 -> V_260 . V_1121 = F_96 ( V_1103 ) ;
V_79 -> V_260 . V_1112 =
F_96 ( V_73 << V_1113 ) ;
F_596 () ;
V_49 ++ ;
if ( V_49 == V_64 -> V_98 )
V_49 = 0 ;
V_67 -> V_74 = V_79 ;
V_64 -> V_70 = V_49 ;
return V_323 ;
}
T_16 F_597 ( struct V_216 * V_100 ,
struct V_1 * V_2 ,
struct V_63 * V_92 )
{
struct V_66 * V_1056 ;
int V_1166 ;
T_1 V_1080 = 0 ;
unsigned short V_1160 ;
T_2 V_98 = F_598 ( F_156 ( V_100 ) ) ;
T_11 V_276 = V_100 -> V_276 ;
T_4 V_263 = 0 ;
for ( V_1160 = 0 ; V_1160 < F_157 ( V_100 ) -> V_306 ; V_1160 ++ )
V_98 += F_598 ( F_157 ( V_100 ) -> V_290 [ V_1160 ] . V_304 ) ;
if ( F_580 ( V_92 , V_98 + 3 ) ) {
V_92 -> V_161 . V_874 ++ ;
return V_1167 ;
}
V_1056 = & V_92 -> V_68 [ V_92 -> V_70 ] ;
V_1056 -> V_100 = V_100 ;
V_1056 -> V_184 = V_100 -> V_73 ;
V_1056 -> V_185 = 1 ;
if ( F_599 ( V_100 ) ) {
V_1080 |= F_600 ( V_100 ) << V_1143 ;
V_1080 |= V_1093 ;
} else if ( V_276 == F_164 ( V_275 ) ) {
struct V_1168 * V_1169 , V_1170 ;
V_1169 = F_601 ( V_100 , V_562 , sizeof( V_1170 ) , & V_1170 ) ;
if ( ! V_1169 )
goto V_1171;
V_1080 |= F_602 ( V_1169 -> V_1172 ) <<
V_1143 ;
V_1080 |= V_1145 ;
}
V_276 = F_593 ( V_100 ) ;
if ( F_23 ( F_157 ( V_100 ) -> V_1080 & V_1173 ) &&
V_2 -> V_1174 ) {
if ( ! F_603 ( V_1175 ,
& V_2 -> V_35 ) ) {
F_157 ( V_100 ) -> V_1080 |= V_1176 ;
V_1080 |= V_1109 ;
V_2 -> V_1177 = F_604 ( V_100 ) ;
V_2 -> V_1178 = V_189 ;
F_605 ( & V_2 -> V_1179 ) ;
} else {
V_2 -> V_1180 ++ ;
}
}
F_606 ( V_100 ) ;
#ifdef F_337
if ( V_2 -> V_148 & V_458 )
V_1080 |= V_1094 ;
#endif
if ( ( V_2 -> V_148 & V_149 ) &&
( ( V_1080 & ( V_1093 | V_1145 ) ) ||
( V_100 -> V_1181 != V_1182 ) ) ) {
V_1080 &= ~ V_1183 ;
V_1080 |= ( V_100 -> V_1181 & 0x7 ) <<
V_1184 ;
if ( V_1080 & V_1145 ) {
struct V_1185 * V_1169 ;
if ( F_557 ( V_100 , 0 ) )
goto V_1171;
V_1169 = (struct V_1185 * ) V_100 -> V_103 ;
V_1169 -> V_1172 = F_164 ( V_1080 >>
V_1143 ) ;
} else {
V_1080 |= V_1093 ;
}
}
V_1056 -> V_1080 = V_1080 ;
V_1056 -> V_276 = V_276 ;
#ifdef F_184
if ( ( V_276 == F_164 ( V_1163 ) ) &&
( V_92 -> V_77 -> V_218 & ( V_1186 | V_1187 ) ) ) {
V_1166 = F_607 ( V_92 , V_1056 , & V_263 ) ;
if ( V_1166 < 0 )
goto V_1171;
goto V_1188;
}
#endif
V_1166 = F_555 ( V_92 , V_1056 , & V_263 ) ;
if ( V_1166 < 0 )
goto V_1171;
else if ( ! V_1166 )
F_570 ( V_92 , V_1056 ) ;
if ( F_14 ( V_420 , & V_92 -> V_35 ) )
F_588 ( V_92 , V_1056 ) ;
#ifdef F_184
V_1188:
#endif
if ( F_581 ( V_92 , V_1056 , V_263 ) )
goto V_1189;
return V_1190 ;
V_1171:
F_183 ( V_1056 -> V_100 ) ;
V_1056 -> V_100 = NULL ;
V_1189:
if ( F_23 ( V_1080 & V_1109 ) ) {
F_183 ( V_2 -> V_1177 ) ;
V_2 -> V_1177 = NULL ;
F_608 ( & V_2 -> V_1179 ) ;
F_609 ( V_1175 , & V_2 -> V_35 ) ;
}
return V_1190 ;
}
static T_16 F_610 ( struct V_216 * V_100 ,
struct V_76 * V_77 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_63 * V_92 ;
if ( F_611 ( V_100 , 17 ) )
return V_1190 ;
V_92 = V_64 ? V_64 : V_2 -> V_92 [ V_100 -> V_1162 ] ;
return F_597 ( V_100 , V_2 , V_92 ) ;
}
static T_16 F_612 ( struct V_216 * V_100 ,
struct V_76 * V_77 )
{
return F_610 ( V_100 , V_77 , NULL ) ;
}
static int F_613 ( struct V_76 * V_77 , void * V_62 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1191 * V_628 = V_62 ;
if ( ! F_401 ( V_628 -> V_1192 ) )
return - V_1193 ;
memcpy ( V_77 -> V_715 , V_628 -> V_1192 , V_77 -> V_1194 ) ;
memcpy ( V_14 -> V_118 . V_628 , V_628 -> V_1192 , V_77 -> V_1194 ) ;
F_344 ( V_2 ) ;
return 0 ;
}
static int
F_614 ( struct V_76 * V_77 , int V_1195 , int V_1196 , T_2 V_628 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_4 ;
int V_368 ;
if ( V_1195 != V_14 -> V_46 . V_1197 . V_1195 )
return - V_633 ;
V_368 = V_14 -> V_46 . V_374 . V_1198 ( V_14 , V_628 , V_1196 , & V_4 ) ;
if ( ! V_368 )
V_368 = V_4 ;
return V_368 ;
}
static int F_615 ( struct V_76 * V_77 , int V_1195 , int V_1196 ,
T_2 V_628 , T_2 V_4 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_1195 != V_14 -> V_46 . V_1197 . V_1195 )
return - V_633 ;
return V_14 -> V_46 . V_374 . V_1199 ( V_14 , V_628 , V_1196 , V_4 ) ;
}
static int F_616 ( struct V_76 * V_77 , struct V_1200 * V_1201 , int V_1202 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
switch ( V_1202 ) {
case V_1203 :
return F_617 ( V_2 , V_1201 ) ;
case V_1204 :
return F_618 ( V_2 , V_1201 ) ;
case V_1205 :
if ( ! V_2 -> V_14 . V_46 . V_374 . V_1198 )
return - V_1206 ;
default:
return F_619 ( & V_2 -> V_14 . V_46 . V_1197 , F_620 ( V_1201 ) , V_1202 ) ;
}
}
static int F_621 ( struct V_76 * V_89 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_401 ( V_14 -> V_118 . V_1207 ) ) {
F_488 () ;
V_17 = F_622 ( V_89 , V_14 -> V_118 . V_1207 , V_1208 ) ;
F_491 () ;
V_14 -> V_118 . V_374 . V_759 ( V_14 , F_310 ( 0 ) ) ;
}
return V_17 ;
}
static int F_623 ( struct V_76 * V_89 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_1209 * V_118 = & V_2 -> V_14 . V_118 ;
if ( F_401 ( V_118 -> V_1207 ) ) {
F_488 () ;
V_17 = F_624 ( V_89 , V_118 -> V_1207 , V_1208 ) ;
F_491 () ;
}
return V_17 ;
}
static void F_625 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
int V_49 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
for ( V_49 = 0 ; V_49 < V_2 -> V_210 ; V_49 ++ )
F_255 ( 0 , V_2 -> V_174 [ V_49 ] ) ;
}
static void F_626 ( struct V_1210 * V_133 ,
struct V_63 * V_64 )
{
V_71 V_188 , V_153 ;
unsigned int V_1211 ;
if ( V_64 ) {
do {
V_1211 = F_627 ( & V_64 -> V_187 ) ;
V_153 = V_64 -> V_133 . V_153 ;
V_188 = V_64 -> V_133 . V_188 ;
} while ( F_628 ( & V_64 -> V_187 , V_1211 ) );
V_133 -> V_881 += V_153 ;
V_133 -> V_880 += V_188 ;
}
}
static void F_629 ( struct V_76 * V_77 ,
struct V_1210 * V_133 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
int V_49 ;
F_209 () ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
struct V_63 * V_64 = F_21 ( V_2 -> V_84 [ V_49 ] ) ;
V_71 V_188 , V_153 ;
unsigned int V_1211 ;
if ( V_64 ) {
do {
V_1211 = F_627 ( & V_64 -> V_187 ) ;
V_153 = V_64 -> V_133 . V_153 ;
V_188 = V_64 -> V_133 . V_188 ;
} while ( F_628 ( & V_64 -> V_187 , V_1211 ) );
V_133 -> V_879 += V_153 ;
V_133 -> V_878 += V_188 ;
}
}
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ ) {
struct V_63 * V_64 = F_21 ( V_2 -> V_92 [ V_49 ] ) ;
F_626 ( V_133 , V_64 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ ) {
struct V_63 * V_64 = F_21 ( V_2 -> V_94 [ V_49 ] ) ;
F_626 ( V_133 , V_64 ) ;
}
F_216 () ;
V_133 -> V_988 = V_77 -> V_133 . V_988 ;
V_133 -> V_989 = V_77 -> V_133 . V_989 ;
V_133 -> V_991 = V_77 -> V_133 . V_991 ;
V_133 -> V_992 = V_77 -> V_133 . V_992 ;
V_133 -> V_993 = V_77 -> V_133 . V_993 ;
}
static void F_630 ( struct V_1 * V_2 , T_4 V_143 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_3 , V_1212 ;
int V_49 ;
if ( V_14 -> V_118 . type == V_119 )
return;
V_3 = F_40 ( V_14 , V_1213 ) ;
V_1212 = V_3 ;
for ( V_49 = 0 ; V_49 < V_686 ; V_49 ++ ) {
T_4 V_1214 = V_3 >> ( V_49 * V_1215 ) ;
if ( V_1214 > V_143 )
V_3 &= ~ ( 0x7 << V_1215 ) ;
}
if ( V_3 != V_1212 )
F_74 ( V_14 , V_1213 , V_3 ) ;
return;
}
static void F_631 ( struct V_1 * V_2 )
{
struct V_76 * V_89 = V_2 -> V_77 ;
struct V_1216 * V_145 = & V_2 -> V_145 ;
struct V_1217 * V_1218 = V_2 -> V_671 ;
T_4 V_1219 ;
for ( V_1219 = 0 ; V_1219 < V_1220 ; V_1219 ++ ) {
T_4 V_143 = 0 ;
if ( V_2 -> V_667 & V_668 )
V_143 = F_632 ( V_145 , 0 , V_1219 ) ;
else if ( V_1218 )
V_143 = V_1218 -> V_672 [ V_1219 ] ;
F_633 ( V_89 , V_1219 , V_143 ) ;
}
}
int F_634 ( struct V_76 * V_89 , T_4 V_143 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
bool V_1221 ;
if ( V_143 > V_2 -> V_145 . V_772 . V_773 )
return - V_633 ;
if ( V_14 -> V_118 . type == V_119 && V_143 && V_143 < V_686 )
return - V_633 ;
V_1221 = ( F_635 ( & V_2 -> V_712 , 32 ) > 1 ) ;
if ( V_143 && V_1221 && V_2 -> V_713 > V_1222 )
return - V_843 ;
if ( F_63 ( V_89 ) )
F_477 ( V_89 ) ;
else
F_426 ( V_2 ) ;
F_495 ( V_2 ) ;
#ifdef F_407
if ( V_143 ) {
F_636 ( V_89 , V_143 ) ;
F_631 ( V_2 ) ;
V_2 -> V_148 |= V_149 ;
if ( V_2 -> V_14 . V_118 . type == V_119 ) {
V_2 -> V_1223 = V_2 -> V_14 . V_134 . V_820 ;
V_2 -> V_14 . V_134 . V_820 = V_1224 ;
}
} else {
F_637 ( V_89 ) ;
if ( V_2 -> V_14 . V_118 . type == V_119 )
V_2 -> V_14 . V_134 . V_820 = V_2 -> V_1223 ;
V_2 -> V_148 &= ~ V_149 ;
V_2 -> V_788 . V_146 = false ;
V_2 -> V_145 . V_146 = false ;
}
F_630 ( V_2 , V_143 ) ;
#endif
F_489 ( V_2 ) ;
if ( F_63 ( V_89 ) )
return F_472 ( V_89 ) ;
return 0 ;
}
static int F_638 ( struct V_1 * V_2 ,
struct V_1225 * V_1226 )
{
T_1 V_1227 = V_1226 -> V_1228 . V_1229 ;
T_1 V_1230 = F_639 ( V_1226 -> V_1228 . V_1229 ) ;
T_1 V_1231 = V_1226 -> V_1228 . V_1229 & 0xfffff ;
int V_17 = 0 , V_49 , V_60 ;
struct V_1232 * V_1233 = NULL ;
if ( V_1231 > V_1234 )
return - V_633 ;
if ( ( V_1230 != 0x800 ) && ( V_1230 >= V_814 ) )
return - V_633 ;
if ( V_1230 != 0x800 ) {
V_1233 = V_2 -> V_811 [ V_1230 ] ;
if ( ! V_1233 )
return - V_633 ;
if ( ! F_14 ( V_1231 - 1 , V_1233 -> V_1235 ) )
return - V_633 ;
F_37 ( V_1231 - 1 , V_1233 -> V_1235 ) ;
}
for ( V_49 = 1 ; V_49 < V_814 ; V_49 ++ ) {
V_1233 = V_2 -> V_811 [ V_49 ] ;
if ( V_1233 && V_1233 -> V_1236 == V_1227 ) {
for ( V_60 = 0 ; V_60 < V_1234 ; V_60 ++ ) {
if ( ! F_14 ( V_60 , V_1233 -> V_1235 ) )
continue;
F_384 ( & V_2 -> V_696 ) ;
V_17 = F_640 ( V_2 ,
NULL ,
V_60 + 1 ) ;
F_389 ( & V_2 -> V_696 ) ;
F_37 ( V_60 , V_1233 -> V_1235 ) ;
}
F_268 ( V_1233 -> V_1126 ) ;
F_268 ( V_1233 -> V_128 ) ;
F_268 ( V_1233 ) ;
V_2 -> V_811 [ V_49 ] = NULL ;
return V_17 ;
}
}
F_384 ( & V_2 -> V_696 ) ;
V_17 = F_640 ( V_2 , NULL , V_1231 ) ;
F_389 ( & V_2 -> V_696 ) ;
return V_17 ;
}
static int F_641 ( struct V_1 * V_2 ,
struct V_1225 * V_1226 )
{
T_1 V_1230 = F_639 ( V_1226 -> V_1237 . V_1229 ) ;
if ( V_1230 >= V_814 )
return - V_633 ;
if ( V_1226 -> V_1237 . V_1238 > 0 )
return - V_633 ;
F_91 ( V_1230 - 1 , & V_2 -> V_1239 ) ;
return 0 ;
}
static int F_642 ( struct V_1 * V_2 ,
struct V_1225 * V_1226 )
{
T_1 V_1230 = F_639 ( V_1226 -> V_1237 . V_1229 ) ;
if ( V_1230 >= V_814 )
return - V_633 ;
F_37 ( V_1230 - 1 , & V_2 -> V_1239 ) ;
return 0 ;
}
static int F_643 ( struct V_76 * V_106 , void * V_1240 )
{
if ( F_403 ( V_106 ) ) {
struct V_716 * V_717 = F_87 ( V_106 ) ;
struct V_702 * V_703 = V_717 -> V_718 ;
struct V_1241 * V_103 = V_1240 ;
struct V_1 * V_2 = V_103 -> V_2 ;
int V_1242 = V_103 -> V_1242 ;
if ( V_703 && V_703 -> V_77 -> V_1242 == V_1242 ) {
V_103 -> V_114 = V_2 -> V_84 [ V_703 -> V_705 ] -> V_158 ;
V_103 -> V_700 = V_103 -> V_114 ;
return 1 ;
}
}
return 0 ;
}
static int F_644 ( struct V_1 * V_2 , int V_1242 ,
T_4 * V_114 , V_71 * V_700 )
{
unsigned int V_340 = V_2 -> V_340 , V_1033 ;
struct V_1241 V_103 ;
struct V_76 * V_106 ;
for ( V_1033 = 0 ; V_1033 < V_340 ; ++ V_1033 ) {
V_106 = F_481 ( V_2 -> V_558 [ V_1033 ] . V_1036 ) ;
if ( V_106 -> V_1242 == V_1242 ) {
if ( V_2 -> V_713 > 1 )
* V_114 = V_1033 * 2 ;
else
* V_114 = V_1033 * V_2 -> V_704 ;
* V_700 = V_1033 + 1 ;
* V_700 <<= V_1243 ;
return 0 ;
}
}
V_103 . V_2 = V_2 ;
V_103 . V_1242 = V_1242 ;
V_103 . V_700 = 0 ;
V_103 . V_114 = 0 ;
if ( F_405 ( V_2 -> V_77 ,
F_643 , & V_103 ) ) {
* V_700 = V_103 . V_700 ;
* V_114 = V_103 . V_114 ;
return 0 ;
}
return - V_633 ;
}
static int F_645 ( struct V_1 * V_2 ,
struct V_1244 * V_1245 , V_71 * V_700 , T_4 * V_114 )
{
const struct V_1246 * V_81 ;
F_646 ( V_1247 ) ;
int V_17 ;
if ( ! F_647 ( V_1245 ) )
return - V_633 ;
F_648 ( V_1245 , & V_1247 ) ;
F_649 (a, &actions, list) {
if ( F_650 ( V_81 ) ) {
* V_700 = V_701 ;
* V_114 = V_701 ;
return 0 ;
}
if ( F_651 ( V_81 ) ) {
int V_1242 = F_652 ( V_81 ) ;
V_17 = F_644 ( V_2 , V_1242 , V_114 ,
V_700 ) ;
if ( V_17 == 0 )
return V_17 ;
}
}
return - V_633 ;
}
static int F_645 ( struct V_1 * V_2 ,
struct V_1244 * V_1245 , V_71 * V_700 , T_4 * V_114 )
{
return - V_633 ;
}
static int F_653 ( struct V_694 * V_1126 ,
union V_1248 * V_128 ,
struct V_1225 * V_1226 ,
struct V_1249 * V_1250 ,
struct V_1251 * V_1252 )
{
int V_49 , V_60 , V_1253 ;
T_17 V_1254 , V_1255 ;
bool V_1256 = false , V_1257 = false ;
for ( V_49 = 0 ; V_49 < V_1226 -> V_1228 . V_1258 -> V_1259 ; V_49 ++ ) {
V_1253 = V_1226 -> V_1228 . V_1258 -> V_1260 [ V_49 ] . V_1253 ;
V_1254 = V_1226 -> V_1228 . V_1258 -> V_1260 [ V_49 ] . V_1254 ;
V_1255 = V_1226 -> V_1228 . V_1258 -> V_1260 [ V_49 ] . V_128 ;
for ( V_60 = 0 ; V_1250 [ V_60 ] . V_1254 ; V_60 ++ ) {
if ( V_1250 [ V_60 ] . V_1253 == V_1253 ) {
V_1250 [ V_60 ] . V_1254 ( V_1126 , V_128 , V_1254 , V_1255 ) ;
V_1126 -> V_695 . V_1144 . V_1150 |=
V_1250 [ V_60 ] . type ;
V_1256 = true ;
break;
}
}
if ( V_1252 ) {
if ( V_1252 -> V_1253 == V_1226 -> V_1228 . V_1258 -> V_1260 [ V_49 ] . V_1253 &&
V_1252 -> V_1254 == V_1226 -> V_1228 . V_1258 -> V_1260 [ V_49 ] . V_1254 &&
V_1252 -> V_128 == V_1226 -> V_1228 . V_1258 -> V_1260 [ V_49 ] . V_128 )
V_1257 = true ;
else
continue;
}
}
if ( V_1252 && ! V_1257 )
return - V_633 ;
if ( ! V_1256 )
return 0 ;
V_128 -> V_1144 . V_1150 = V_1261 |
V_1262 ;
if ( V_1126 -> V_695 . V_1144 . V_1150 == V_1263 )
V_128 -> V_1144 . V_1150 &= V_1261 ;
return 0 ;
}
static int F_654 ( struct V_1 * V_2 ,
struct V_1225 * V_1226 )
{
T_11 V_276 = V_1226 -> V_1128 . V_276 ;
T_1 V_1231 = V_1226 -> V_1228 . V_1229 & 0xfffff ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1249 * V_1250 ;
struct V_694 * V_1126 = NULL ;
union V_1248 * V_128 = NULL ;
struct V_1232 * V_1233 = NULL ;
int V_49 , V_17 = - V_633 ;
T_4 V_114 ;
T_1 V_1230 , V_1264 ;
V_1230 = F_639 ( V_1226 -> V_1228 . V_1229 ) ;
V_1264 = F_639 ( V_1226 -> V_1228 . V_1265 ) ;
if ( V_276 != F_164 ( V_1100 ) )
return V_17 ;
if ( V_1231 >= ( ( 1024 << V_2 -> V_689 ) - 2 ) ) {
F_107 ( V_164 , L_130 ) ;
return V_17 ;
}
if ( V_1230 == 0x800 ) {
V_1250 = ( V_2 -> V_811 [ 0 ] ) -> V_812 ;
} else {
if ( V_1230 >= V_814 )
return V_17 ;
if ( ! V_2 -> V_811 [ V_1230 ] )
return V_17 ;
V_1250 = ( V_2 -> V_811 [ V_1230 ] ) -> V_812 ;
}
if ( ! V_1250 )
return V_17 ;
if ( V_1264 ) {
struct V_1251 * V_1252 = V_1266 ;
if ( V_1264 >= V_814 )
return V_17 ;
if ( ! F_14 ( V_1264 - 1 , & V_2 -> V_1239 ) )
return V_17 ;
if ( V_2 -> V_811 [ V_1264 ] &&
( V_2 -> V_811 [ V_1264 ] ) -> V_1236 ) {
F_107 ( V_164 , L_131 ,
V_1264 ) ;
return V_17 ;
}
for ( V_49 = 0 ; V_1252 [ V_49 ] . V_1233 ; V_49 ++ ) {
if ( V_1252 [ V_49 ] . V_1267 != V_1226 -> V_1228 . V_1258 -> V_1268 ||
V_1252 [ V_49 ] . V_1269 != V_1226 -> V_1228 . V_1258 -> V_1270 ||
V_1252 [ V_49 ] . V_1255 != V_1226 -> V_1228 . V_1258 -> V_1271 )
return V_17 ;
V_1233 = F_290 ( sizeof( * V_1233 ) , V_487 ) ;
if ( ! V_1233 )
return - V_488 ;
V_1126 = F_290 ( sizeof( * V_1126 ) , V_487 ) ;
if ( ! V_1126 ) {
V_17 = - V_488 ;
goto V_1272;
}
V_128 = F_290 ( sizeof( * V_128 ) , V_487 ) ;
if ( ! V_128 ) {
V_17 = - V_488 ;
goto V_1273;
}
V_1233 -> V_1126 = V_1126 ;
V_1233 -> V_128 = V_128 ;
V_1233 -> V_1236 = V_1226 -> V_1228 . V_1229 ;
V_17 = F_653 ( V_1126 , V_128 , V_1226 ,
V_1250 , & V_1252 [ V_49 ] ) ;
if ( ! V_17 ) {
V_1233 -> V_812 = V_1252 [ V_49 ] . V_1233 ;
V_2 -> V_811 [ V_1264 ] = V_1233 ;
break;
}
}
return 0 ;
}
V_1126 = F_290 ( sizeof( * V_1126 ) , V_487 ) ;
if ( ! V_1126 )
return - V_488 ;
V_128 = F_290 ( sizeof( * V_128 ) , V_487 ) ;
if ( ! V_128 ) {
V_17 = - V_488 ;
goto V_1273;
}
if ( ( V_1230 != 0x800 ) && ( V_2 -> V_811 [ V_1230 ] ) ) {
if ( ( V_2 -> V_811 [ V_1230 ] ) -> V_1126 )
memcpy ( V_1126 , ( V_2 -> V_811 [ V_1230 ] ) -> V_1126 ,
sizeof( * V_1126 ) ) ;
if ( ( V_2 -> V_811 [ V_1230 ] ) -> V_128 )
memcpy ( V_128 , ( V_2 -> V_811 [ V_1230 ] ) -> V_128 ,
sizeof( * V_128 ) ) ;
for ( V_49 = 1 ; V_49 < V_814 ; V_49 ++ ) {
struct V_1232 * V_417 = V_2 -> V_811 [ V_49 ] ;
if ( V_417 && ( F_14 ( V_1231 - 1 , V_417 -> V_1235 ) ) ) {
F_107 ( V_164 , L_132 ,
V_1231 ) ;
V_17 = - V_633 ;
goto V_1274;
}
}
}
V_17 = F_653 ( V_1126 , V_128 , V_1226 , V_1250 , NULL ) ;
if ( V_17 )
goto V_1274;
V_17 = F_645 ( V_2 , V_1226 -> V_1228 . V_1245 , & V_1126 -> V_700 ,
& V_114 ) ;
if ( V_17 < 0 )
goto V_1274;
V_1126 -> V_699 = V_1231 ;
F_384 ( & V_2 -> V_696 ) ;
if ( F_385 ( & V_2 -> V_697 ) ) {
memcpy ( & V_2 -> V_698 , V_128 , sizeof( * V_128 ) ) ;
V_17 = F_386 ( V_14 , V_128 ) ;
if ( V_17 )
goto V_1275;
} else if ( memcmp ( & V_2 -> V_698 , V_128 , sizeof( * V_128 ) ) ) {
V_17 = - V_633 ;
goto V_1275;
}
F_655 ( & V_1126 -> V_695 , V_128 ) ;
V_17 = F_388 ( V_14 , & V_1126 -> V_695 ,
V_1126 -> V_699 , V_114 ) ;
if ( ! V_17 )
F_640 ( V_2 , V_1126 , V_1126 -> V_699 ) ;
F_389 ( & V_2 -> V_696 ) ;
if ( ( V_1230 != 0x800 ) && ( V_2 -> V_811 [ V_1230 ] ) )
F_91 ( V_1231 - 1 , ( V_2 -> V_811 [ V_1230 ] ) -> V_1235 ) ;
F_268 ( V_128 ) ;
return V_17 ;
V_1275:
F_389 ( & V_2 -> V_696 ) ;
V_1274:
F_268 ( V_128 ) ;
V_1273:
F_268 ( V_1126 ) ;
V_1272:
F_268 ( V_1233 ) ;
return V_17 ;
}
static int F_656 ( struct V_76 * V_89 ,
struct V_1225 * V_1276 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
if ( ! F_657 ( V_1276 -> V_1128 . V_1277 ) ||
V_1276 -> V_1128 . V_1278 )
return - V_1206 ;
switch ( V_1276 -> V_1279 ) {
case V_1280 :
case V_1281 :
return F_654 ( V_2 , V_1276 ) ;
case V_1282 :
return F_638 ( V_2 , V_1276 ) ;
case V_1283 :
case V_1284 :
return F_641 ( V_2 , V_1276 ) ;
case V_1285 :
return F_642 ( V_2 , V_1276 ) ;
default:
return - V_1206 ;
}
}
static int F_658 ( struct V_76 * V_89 ,
struct V_1286 * V_1287 )
{
V_1287 -> V_14 = V_1288 ;
return F_634 ( V_89 , V_1287 -> V_683 ) ;
}
static int F_659 ( struct V_76 * V_89 , enum V_1289 type ,
void * V_1290 )
{
switch ( type ) {
case V_1291 :
return F_656 ( V_89 , V_1290 ) ;
case V_1292 :
return F_658 ( V_89 , V_1290 ) ;
default:
return - V_1206 ;
}
}
void F_660 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
F_488 () ;
F_634 ( V_77 , F_281 ( V_77 ) ) ;
F_491 () ;
}
void F_661 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
if ( F_63 ( V_77 ) )
F_418 ( V_2 ) ;
else
F_426 ( V_2 ) ;
}
static T_12 F_662 ( struct V_76 * V_77 ,
T_12 V_218 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
if ( ! ( V_218 & V_235 ) )
V_218 &= ~ V_1293 ;
if ( ! ( V_2 -> V_369 & V_803 ) )
V_218 &= ~ V_1293 ;
return V_218 ;
}
static int F_663 ( struct V_76 * V_77 ,
T_12 V_218 )
{
struct V_1 * V_2 = F_87 ( V_77 ) ;
T_12 V_1294 = V_77 -> V_218 ^ V_218 ;
bool V_1295 = false ;
if ( ! ( V_218 & V_1293 ) ) {
if ( V_2 -> V_369 & V_575 )
V_1295 = true ;
V_2 -> V_369 &= ~ V_575 ;
} else if ( ( V_2 -> V_369 & V_803 ) &&
! ( V_2 -> V_369 & V_575 ) ) {
if ( V_2 -> V_429 == 1 ||
V_2 -> V_429 > V_1296 ) {
V_2 -> V_369 |= V_575 ;
V_1295 = true ;
} else if ( ( V_1294 ^ V_218 ) & V_1293 ) {
F_109 ( V_190 , L_133
L_134 ) ;
}
}
if ( ( V_218 & V_1297 ) || ( V_218 & V_1298 ) ) {
if ( ! ( V_2 -> V_148 & V_688 ) )
V_1295 = true ;
V_2 -> V_148 &= ~ V_410 ;
V_2 -> V_148 |= V_688 ;
} else {
if ( V_2 -> V_148 & V_688 )
V_1295 = true ;
V_2 -> V_148 &= ~ V_688 ;
if ( V_2 -> V_148 & V_458 ||
( F_281 ( V_77 ) > 1 ) ||
( V_2 -> V_463 [ V_478 ] . V_802 <= 1 ) ||
( ! V_2 -> V_448 ) )
;
else
V_2 -> V_148 |= V_410 ;
}
if ( V_1294 & V_297 )
V_1295 = true ;
V_77 -> V_218 = V_218 ;
if ( ( V_2 -> V_148 & V_659 ) ) {
if ( V_218 & V_235 ) {
V_2 -> V_369 |= V_1055 ;
} else {
T_1 V_1299 = V_662 ;
F_364 ( V_2 , V_1299 ) ;
}
}
if ( ( V_2 -> V_148 & V_660 ) ) {
if ( V_218 & V_235 ) {
V_2 -> V_369 |= V_1055 ;
} else {
T_1 V_1299 = V_664 ;
F_364 ( V_2 , V_1299 ) ;
}
}
if ( V_1295 )
F_661 ( V_77 ) ;
else if ( V_1294 & ( V_271 |
V_653 ) )
F_357 ( V_77 ) ;
return 0 ;
}
static void F_664 ( struct V_76 * V_89 ,
struct V_1300 * V_431 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_11 V_1146 = V_431 -> V_1146 ;
T_1 V_1301 = 0 ;
T_1 V_3 ;
if ( V_431 -> V_1302 != V_1303 )
return;
switch ( V_431 -> type ) {
case V_1304 :
if ( ! ( V_2 -> V_148 & V_659 ) )
return;
if ( V_2 -> V_663 == V_1146 )
return;
if ( V_2 -> V_663 ) {
F_665 ( V_89 ,
L_135 ,
F_602 ( V_2 -> V_663 ) ,
F_602 ( V_1146 ) ) ;
return;
}
V_2 -> V_663 = V_1146 ;
break;
case V_1305 :
if ( ! ( V_2 -> V_148 & V_660 ) )
return;
if ( V_2 -> V_665 == V_1146 )
return;
if ( V_2 -> V_665 ) {
F_665 ( V_89 ,
L_136 ,
F_602 ( V_2 -> V_665 ) ,
F_602 ( V_1146 ) ) ;
return;
}
V_1301 = V_1306 ;
V_2 -> V_665 = V_1146 ;
break;
default:
return;
}
V_3 = F_40 ( V_14 , V_661 ) | F_602 ( V_1146 ) << V_1301 ;
F_74 ( V_14 , V_661 , V_3 ) ;
}
static void F_666 ( struct V_76 * V_89 ,
struct V_1300 * V_431 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
T_1 V_1299 ;
if ( V_431 -> type != V_1304 &&
V_431 -> type != V_1305 )
return;
if ( V_431 -> V_1302 != V_1303 )
return;
switch ( V_431 -> type ) {
case V_1304 :
if ( ! ( V_2 -> V_148 & V_659 ) )
return;
if ( V_2 -> V_663 != V_431 -> V_1146 ) {
F_665 ( V_89 , L_137 ,
F_602 ( V_431 -> V_1146 ) ) ;
return;
}
V_1299 = V_662 ;
break;
case V_1305 :
if ( ! ( V_2 -> V_148 & V_660 ) )
return;
if ( V_2 -> V_665 != V_431 -> V_1146 ) {
F_665 ( V_89 , L_138 ,
F_602 ( V_431 -> V_1146 ) ) ;
return;
}
V_1299 = V_664 ;
break;
default:
return;
}
F_364 ( V_2 , V_1299 ) ;
V_2 -> V_369 |= V_1055 ;
}
static int F_667 ( struct V_1307 * V_1308 , struct V_1309 * V_1310 [] ,
struct V_76 * V_89 ,
const unsigned char * V_628 , T_2 V_273 ,
T_2 V_148 )
{
if ( F_668 ( V_628 ) || F_669 ( V_628 ) ) {
struct V_1 * V_2 = F_87 ( V_89 ) ;
T_2 V_532 = F_310 ( 0 ) ;
if ( F_351 ( V_89 ) >= F_343 ( V_2 , V_532 ) )
return - V_488 ;
}
return F_670 ( V_1308 , V_1310 , V_89 , V_628 , V_273 , V_148 ) ;
}
static int F_671 ( struct V_1 * V_2 ,
T_18 V_1311 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
unsigned int V_62 , V_1312 ;
T_1 V_541 ;
switch ( V_1311 ) {
case V_1313 :
F_74 ( & V_2 -> V_14 , V_549 , 0 ) ;
V_541 = F_40 ( V_14 , V_1314 ) ;
V_541 |= V_546 ;
F_74 ( V_14 , V_1314 , V_541 ) ;
V_1312 = V_2 -> V_340 + V_2 -> V_713 ;
for ( V_62 = 0 ; V_62 < V_1312 ; V_62 ++ ) {
if ( V_14 -> V_118 . V_374 . V_1315 )
V_14 -> V_118 . V_374 . V_1315 ( V_14 ,
true ,
V_62 ) ;
}
break;
case V_548 :
F_74 ( & V_2 -> V_14 , V_549 ,
V_550 ) ;
V_541 = F_40 ( V_14 , V_1314 ) ;
if ( ! V_2 -> V_340 )
V_541 &= ~ V_546 ;
F_74 ( V_14 , V_1314 , V_541 ) ;
V_1312 = V_2 -> V_340 + V_2 -> V_713 ;
for ( V_62 = 0 ; V_62 < V_1312 ; V_62 ++ ) {
if ( V_14 -> V_118 . V_374 . V_1315 )
V_14 -> V_118 . V_374 . V_1315 ( V_14 ,
false ,
V_62 ) ;
}
break;
default:
return - V_633 ;
}
V_2 -> V_547 = V_1311 ;
F_109 ( V_164 , L_139 ,
V_1311 == V_1313 ? L_140 : L_141 ) ;
return 0 ;
}
static int F_672 ( struct V_76 * V_89 ,
struct V_1316 * V_1317 , T_2 V_148 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_1309 * V_1318 , * V_1319 ;
int V_1320 ;
if ( ! ( V_2 -> V_148 & V_458 ) )
return - V_1206 ;
V_1319 = F_673 ( V_1317 , sizeof( struct V_1321 ) , V_1322 ) ;
if ( ! V_1319 )
return - V_633 ;
F_674 (attr, br_spec, rem) {
int V_182 ;
T_18 V_1311 ;
if ( F_675 ( V_1318 ) != V_1323 )
continue;
if ( F_676 ( V_1318 ) < sizeof( V_1311 ) )
return - V_633 ;
V_1311 = F_677 ( V_1318 ) ;
V_182 = F_671 ( V_2 , V_1311 ) ;
if ( V_182 )
return V_182 ;
break;
}
return 0 ;
}
static int F_678 ( struct V_216 * V_100 , T_1 V_1324 , T_1 V_1325 ,
struct V_76 * V_89 ,
T_1 V_1326 , int V_1327 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
if ( ! ( V_2 -> V_148 & V_458 ) )
return 0 ;
return F_679 ( V_100 , V_1324 , V_1325 , V_89 ,
V_2 -> V_547 , 0 , 0 , V_1327 ,
V_1326 , NULL ) ;
}
static void * F_680 ( struct V_76 * V_9 , struct V_76 * V_706 )
{
struct V_702 * V_1159 = NULL ;
struct V_1 * V_2 = F_87 ( V_9 ) ;
int V_1328 = V_2 -> V_340 + V_2 -> V_713 ;
unsigned int V_802 ;
int V_532 , V_17 ;
if ( V_1328 >= V_1329 )
return F_217 ( - V_633 ) ;
#ifdef F_681
if ( V_706 -> V_104 != V_706 -> V_91 ) {
F_665 ( V_9 , L_142 ,
V_706 -> V_59 ) ;
return F_217 ( - V_633 ) ;
}
#endif
if ( V_706 -> V_91 > V_846 ||
V_706 -> V_91 == V_1330 ) {
F_665 ( V_9 ,
L_143 ,
V_9 -> V_59 ) ;
return F_217 ( - V_633 ) ;
}
if ( ( ( V_2 -> V_148 & V_149 ) &&
V_2 -> V_713 > V_1222 - 1 ) ||
( V_2 -> V_713 > V_1331 ) )
return F_217 ( - V_843 ) ;
V_1159 = F_290 ( sizeof( * V_1159 ) , V_487 ) ;
if ( ! V_1159 )
return F_217 ( - V_488 ) ;
V_532 = F_635 ( & V_2 -> V_712 , 32 ) ;
V_2 -> V_713 ++ ;
F_91 ( V_532 , & V_2 -> V_712 ) ;
V_802 = F_682 ( & V_2 -> V_712 , 32 ) ;
V_2 -> V_148 |= V_611 | V_458 ;
V_2 -> V_463 [ V_464 ] . V_802 = V_802 + 1 ;
V_2 -> V_463 [ V_478 ] . V_802 = V_706 -> V_91 ;
V_17 = F_634 ( V_9 , F_281 ( V_9 ) ) ;
if ( V_17 )
goto V_1332;
V_1159 -> V_532 = V_532 ;
V_1159 -> V_157 = V_2 ;
if ( F_63 ( V_9 ) ) {
V_17 = F_397 ( V_706 , V_1159 ) ;
if ( V_17 )
goto V_1332;
F_683 ( V_706 ) ;
}
return V_1159 ;
V_1332:
F_665 ( V_9 ,
L_144 , V_706 -> V_59 ) ;
F_37 ( V_532 , & V_2 -> V_712 ) ;
V_2 -> V_713 -- ;
F_268 ( V_1159 ) ;
return F_217 ( V_17 ) ;
}
static void F_684 ( struct V_76 * V_9 , void * V_1333 )
{
struct V_702 * V_1159 = V_1333 ;
struct V_1 * V_2 = V_1159 -> V_157 ;
unsigned int V_802 ;
F_37 ( V_1159 -> V_532 , & V_2 -> V_712 ) ;
V_2 -> V_713 -- ;
V_802 = F_682 ( & V_2 -> V_712 , 32 ) ;
V_2 -> V_463 [ V_464 ] . V_802 = V_802 + 1 ;
F_395 ( V_1159 -> V_77 , V_1159 ) ;
F_634 ( V_9 , F_281 ( V_9 ) ) ;
F_398 ( V_9 , L_87 ,
V_1159 -> V_532 , V_2 -> V_713 ,
V_1159 -> V_705 ,
V_1159 -> V_705 + V_2 -> V_704 ,
V_2 -> V_712 ) ;
F_268 ( V_1159 ) ;
}
static T_12
F_685 ( struct V_216 * V_100 , struct V_76 * V_89 ,
T_12 V_218 )
{
unsigned int V_1334 , V_1335 ;
V_1335 = F_560 ( V_100 ) - V_100 -> V_103 ;
if ( F_23 ( V_1335 > V_1336 ) )
return V_218 & ~ ( V_1337 |
V_1338 |
V_1339 |
V_1340 |
V_1341 ) ;
V_1334 = F_561 ( V_100 ) - F_560 ( V_100 ) ;
if ( F_23 ( V_1334 > V_1342 ) )
return V_218 & ~ ( V_1337 |
V_1338 |
V_1340 |
V_1341 ) ;
if ( V_100 -> V_237 && ! ( V_218 & V_1343 ) )
V_218 &= ~ V_1340 ;
return V_218 ;
}
static int F_686 ( struct V_76 * V_89 , struct V_316 * V_1344 )
{
int V_49 , V_1345 = V_89 -> V_334 + V_562 + V_563 + V_1346 ;
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_316 * V_1347 ;
if ( V_2 -> V_148 & V_458 )
return - V_633 ;
if ( V_2 -> V_148 & V_149 )
return - V_633 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ ) {
struct V_63 * V_64 = V_2 -> V_84 [ V_49 ] ;
if ( F_170 ( V_64 ) )
return - V_633 ;
if ( V_1345 > F_72 ( V_64 ) )
return - V_633 ;
}
if ( V_1348 > V_1349 )
return - V_488 ;
V_1347 = F_687 ( & V_2 -> V_317 , V_1344 ) ;
if ( ! ! V_1344 != ! ! V_1347 ) {
int V_17 = F_634 ( V_89 , F_281 ( V_89 ) ) ;
if ( V_17 ) {
F_688 ( V_2 -> V_317 , V_1347 ) ;
return - V_633 ;
}
} else {
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ )
F_687 ( & V_2 -> V_84 [ V_49 ] -> V_317 , V_2 -> V_317 ) ;
}
if ( V_1347 )
F_689 ( V_1347 ) ;
return 0 ;
}
static int F_690 ( struct V_76 * V_89 , struct V_1350 * V_309 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
switch ( V_309 -> V_1279 ) {
case V_1351 :
return F_686 ( V_89 , V_309 -> V_1344 ) ;
case V_1352 :
V_309 -> V_1353 = ! ! ( V_2 -> V_317 ) ;
V_309 -> V_1354 = V_2 -> V_317 ?
V_2 -> V_317 -> V_1355 -> V_1356 : 0 ;
return 0 ;
default:
return - V_633 ;
}
}
static int F_691 ( struct V_76 * V_89 , struct V_308 * V_309 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_63 * V_64 ;
int V_17 ;
if ( F_23 ( F_14 ( V_34 , & V_2 -> V_35 ) ) )
return - V_1357 ;
V_64 = V_2 -> V_317 ? V_2 -> V_94 [ F_223 () ] : NULL ;
if ( F_23 ( ! V_64 ) )
return - V_1358 ;
V_17 = F_212 ( V_2 , V_309 ) ;
if ( V_17 != V_323 )
return - V_1359 ;
return 0 ;
}
static void F_692 ( struct V_76 * V_89 )
{
struct V_1 * V_2 = F_87 ( V_89 ) ;
struct V_63 * V_64 ;
if ( F_23 ( F_14 ( V_34 , & V_2 -> V_35 ) ) )
return;
V_64 = V_2 -> V_317 ? V_2 -> V_94 [ F_223 () ] : NULL ;
if ( F_23 ( ! V_64 ) )
return;
F_153 () ;
F_154 ( V_64 -> V_70 , V_64 -> V_155 ) ;
return;
}
static inline int F_693 ( struct V_1 * V_2 )
{
struct V_5 * V_434 , * V_9 = V_2 -> V_9 ;
int V_1360 = 0 ;
if ( F_8 ( & V_2 -> V_14 ) )
V_1360 = 4 ;
F_649 (entry, &adapter->pdev->bus->devices, bus_list) {
if ( V_434 -> V_1361 )
continue;
if ( ( V_434 -> V_794 != V_9 -> V_794 ) ||
( V_434 -> V_211 != V_9 -> V_211 ) )
return - 1 ;
V_1360 ++ ;
}
return V_1360 ;
}
bool F_694 ( struct V_1 * V_2 , T_2 V_21 ,
T_2 V_1362 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1363 = V_2 -> V_1364 & V_1365 ;
if ( V_14 -> V_118 . type == V_119 )
return false ;
if ( V_14 -> V_118 . type >= V_122 ) {
if ( ( V_1363 == V_1366 ) ||
( ( V_1363 == V_1367 ) &&
( V_14 -> V_10 . V_1368 == 0 ) ) )
return true ;
}
switch ( V_21 ) {
case V_1369 :
switch ( V_1362 ) {
case V_1370 :
case V_1371 :
case V_1372 :
case V_1373 :
if ( V_14 -> V_10 . V_1368 != 0 )
break;
case V_1374 :
case V_1375 :
case V_1376 :
case V_1377 :
case V_1378 :
case V_1379 :
case V_1380 :
return true ;
}
break;
case V_1381 :
switch ( V_1362 ) {
case V_1382 :
return true ;
}
break;
case V_1383 :
if ( V_1362 != V_1384 )
return true ;
break;
case V_1385 :
return true ;
default:
break;
}
return false ;
}
static int F_695 ( struct V_5 * V_9 , const struct V_1386 * V_1387 )
{
struct V_76 * V_77 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_14 ;
const struct V_789 * V_790 = V_1388 [ V_1387 -> V_1389 ] ;
int V_49 , V_17 , V_1390 , V_24 ;
unsigned int V_497 = V_1391 ;
T_4 V_1392 [ V_1393 ] ;
bool V_1394 = false ;
#ifdef F_184
T_2 V_1395 ;
#endif
T_1 V_1396 ;
if ( V_9 -> V_1361 ) {
F_696 ( 1 , V_1397 L_145 ,
F_697 ( V_9 ) , V_9 -> V_794 , V_9 -> V_211 ) ;
return - V_633 ;
}
V_17 = F_485 ( V_9 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_698 ( & V_9 -> V_89 , F_276 ( 64 ) ) ) {
V_1390 = 1 ;
} else {
V_17 = F_698 ( & V_9 -> V_89 , F_276 ( 32 ) ) ;
if ( V_17 ) {
F_460 ( & V_9 -> V_89 ,
L_146 ) ;
goto V_1398;
}
V_1390 = 0 ;
}
V_17 = F_699 ( V_9 , V_1399 ) ;
if ( V_17 ) {
F_460 ( & V_9 -> V_89 ,
L_147 , V_17 ) ;
goto V_1400;
}
F_700 ( V_9 ) ;
F_486 ( V_9 ) ;
F_484 ( V_9 ) ;
if ( V_790 -> V_118 == V_119 ) {
#ifdef F_407
V_497 = 4 * V_686 ;
#else
V_497 = V_1401 ;
#endif
}
V_77 = F_701 ( sizeof( struct V_1 ) , V_497 ) ;
if ( ! V_77 ) {
V_17 = - V_488 ;
goto V_1402;
}
F_702 ( V_77 , & V_9 -> V_89 ) ;
V_2 = F_87 ( V_77 ) ;
V_2 -> V_77 = V_77 ;
V_2 -> V_9 = V_9 ;
V_14 = & V_2 -> V_14 ;
V_14 -> V_40 = V_2 ;
V_2 -> V_1403 = F_703 ( V_1404 , V_1405 ) ;
V_14 -> V_41 = F_704 ( F_705 ( V_9 , 0 ) ,
F_706 ( V_9 , 0 ) ) ;
V_2 -> V_447 = V_14 -> V_41 ;
if ( ! V_14 -> V_41 ) {
V_17 = - V_834 ;
goto V_1406;
}
V_77 -> V_1407 = & V_1408 ;
F_707 ( V_77 ) ;
V_77 -> V_1409 = 5 * V_1051 ;
F_708 ( V_77 -> V_59 , F_697 ( V_9 ) , sizeof( V_77 -> V_59 ) ) ;
V_14 -> V_118 . V_374 = * V_790 -> V_1410 ;
V_14 -> V_118 . type = V_790 -> V_118 ;
V_14 -> V_1411 = V_790 -> V_1411 ;
if ( V_790 -> V_1412 )
V_14 -> V_417 . V_374 = * V_790 -> V_1412 ;
V_14 -> V_1413 . V_374 = * V_790 -> V_1414 ;
V_1396 = F_40 ( V_14 , F_709 ( V_14 ) ) ;
if ( F_22 ( V_14 -> V_41 ) ) {
V_17 = - V_834 ;
goto V_1406;
}
if ( ! ( V_1396 & F_226 ( 8 ) ) )
V_14 -> V_1413 . V_374 . V_260 = & V_1415 ;
V_14 -> V_46 . V_374 = * V_790 -> V_1416 ;
V_14 -> V_46 . V_1047 = V_1417 ;
V_14 -> V_46 . V_1197 . V_1195 = V_1418 ;
V_14 -> V_46 . V_1197 . V_1419 = 0 ;
V_14 -> V_46 . V_1197 . V_1420 = V_1421 | V_1422 ;
V_14 -> V_46 . V_1197 . V_89 = V_77 ;
V_14 -> V_46 . V_1197 . V_1423 = F_614 ;
V_14 -> V_46 . V_1197 . V_1424 = F_615 ;
V_17 = F_446 ( V_2 , V_790 ) ;
if ( V_17 )
goto V_1425;
if ( V_14 -> V_118 . V_374 . V_1426 )
V_14 -> V_118 . V_374 . V_1426 ( V_14 ) ;
switch ( V_2 -> V_14 . V_118 . type ) {
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
F_74 ( & V_2 -> V_14 , V_852 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_148 & V_382 ) {
T_1 V_745 = F_40 ( V_14 , V_746 ) ;
if ( V_745 & V_747 )
F_234 ( V_190 , L_70 ) ;
}
if ( V_1427 )
V_14 -> V_1427 = V_1427 ;
V_14 -> V_46 . V_1428 = true ;
V_17 = V_14 -> V_118 . V_374 . V_1429 ( V_14 ) ;
V_14 -> V_46 . V_1428 = false ;
F_443 ( V_2 ) ;
if ( V_17 == V_754 ) {
V_17 = 0 ;
} else if ( V_17 == V_755 ) {
F_18 ( L_148 ) ;
F_18 ( L_149 ) ;
goto V_1425;
} else if ( V_17 ) {
F_18 ( L_150 , V_17 ) ;
goto V_1425;
}
#ifdef F_337
if ( V_2 -> V_14 . V_118 . type == V_119 )
goto V_1430;
F_710 ( V_14 ) ;
V_14 -> V_1431 . V_374 = V_790 -> V_1432 ;
F_711 ( V_9 , V_826 ) ;
F_712 ( V_2 , V_825 ) ;
V_1430:
#endif
V_77 -> V_218 = V_1433 |
V_1340 |
V_1341 |
V_219 |
V_235 |
V_1337 ;
#define F_713 (NETIF_F_GSO_GRE | \
NETIF_F_GSO_GRE_CSUM | \
NETIF_F_GSO_IPXIP4 | \
NETIF_F_GSO_IPXIP6 | \
NETIF_F_GSO_UDP_TUNNEL | \
NETIF_F_GSO_UDP_TUNNEL_CSUM)
V_77 -> V_1434 = F_713 ;
V_77 -> V_218 |= V_1435 |
F_713 ;
if ( V_14 -> V_118 . type >= V_121 )
V_77 -> V_218 |= V_1338 ;
V_77 -> V_1436 |= V_77 -> V_218 |
V_653 |
V_271 |
V_1339 |
V_297 |
V_1437 ;
if ( V_14 -> V_118 . type >= V_121 )
V_77 -> V_1436 |= V_1297 |
V_1298 ;
if ( V_1390 )
V_77 -> V_218 |= V_1438 ;
V_77 -> V_1439 |= V_77 -> V_218 | V_1343 ;
V_77 -> V_1440 |= V_77 -> V_1439 ;
V_77 -> V_1441 |= V_1433 |
V_1340 |
V_1341 |
V_1337 ;
V_77 -> V_1441 |= F_713 ;
V_77 -> V_218 |= V_653 |
V_271 |
V_1339 ;
V_77 -> V_1442 |= V_1443 ;
V_77 -> V_1442 |= V_1444 ;
V_77 -> V_1445 = V_1446 ;
V_77 -> V_1447 = V_1448 - ( V_562 + V_563 ) ;
#ifdef F_407
if ( V_2 -> V_148 & V_786 )
V_77 -> V_1449 = & V_1450 ;
#endif
#ifdef F_184
if ( V_2 -> V_148 & V_809 ) {
unsigned int V_1451 ;
if ( V_14 -> V_118 . V_374 . V_1452 ) {
V_14 -> V_118 . V_374 . V_1452 ( V_14 , & V_1395 ) ;
if ( V_1395 & V_1453 )
V_2 -> V_148 &= ~ V_809 ;
}
V_1451 = F_355 ( int , V_1454 , F_448 () ) ;
V_2 -> V_463 [ V_1165 ] . V_802 = V_1451 ;
V_77 -> V_218 |= V_1186 |
V_1187 ;
V_77 -> V_1439 |= V_1186 |
V_1187 |
V_666 ;
}
#endif
if ( V_2 -> V_369 & V_803 )
V_77 -> V_1436 |= V_1293 ;
if ( V_2 -> V_369 & V_575 )
V_77 -> V_218 |= V_1293 ;
if ( V_14 -> V_1413 . V_374 . V_1455 ( V_14 , NULL ) < 0 ) {
F_18 ( L_151 ) ;
V_17 = - V_834 ;
goto V_1425;
}
F_714 ( & V_2 -> V_9 -> V_89 ,
V_2 -> V_14 . V_118 . V_1456 ) ;
memcpy ( V_77 -> V_715 , V_14 -> V_118 . V_1456 , V_77 -> V_1194 ) ;
if ( ! F_401 ( V_77 -> V_715 ) ) {
F_18 ( L_152 ) ;
V_17 = - V_834 ;
goto V_1425;
}
F_347 ( V_14 -> V_118 . V_628 , V_14 -> V_118 . V_1456 ) ;
F_344 ( V_2 ) ;
F_715 ( & V_2 -> V_748 , & F_547 ,
( unsigned long ) V_2 ) ;
if ( F_22 ( V_14 -> V_41 ) ) {
V_17 = - V_834 ;
goto V_1425;
}
F_716 ( & V_2 -> V_39 , F_551 ) ;
F_91 ( V_42 , & V_2 -> V_35 ) ;
F_37 ( V_37 , & V_2 -> V_35 ) ;
V_17 = F_489 ( V_2 ) ;
if ( V_17 )
goto V_1425;
for ( V_49 = 0 ; V_49 < V_2 -> V_104 ; V_49 ++ )
F_717 ( & V_2 -> V_84 [ V_49 ] -> V_187 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_91 ; V_49 ++ )
F_717 ( & V_2 -> V_92 [ V_49 ] -> V_187 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_93 ; V_49 ++ )
F_717 ( & V_2 -> V_94 [ V_49 ] -> V_187 ) ;
V_2 -> V_761 = 0 ;
V_14 -> V_1413 . V_374 . V_260 ( V_14 , 0x2c , & V_2 -> V_1364 ) ;
V_14 -> V_1457 = F_694 ( V_2 , V_9 -> V_211 ,
V_9 -> V_800 ) ;
if ( V_14 -> V_1457 )
V_2 -> V_761 = V_1458 ;
F_718 ( & V_2 -> V_9 -> V_89 , V_2 -> V_761 ) ;
V_14 -> V_1413 . V_374 . V_260 ( V_14 , 0x2e , & V_2 -> V_1459 ) ;
V_14 -> V_1413 . V_374 . V_260 ( V_14 , 0x2d , & V_2 -> V_1460 ) ;
if ( F_8 ( V_14 ) )
F_5 ( V_2 ) ;
else
V_14 -> V_118 . V_374 . V_1461 ( V_14 ) ;
switch ( V_14 -> V_118 . type ) {
case V_119 :
V_24 = F_262 ( F_693 ( V_2 ) * 10 , 16 ) ;
break;
default:
V_24 = F_693 ( V_2 ) * 10 ;
break;
}
if ( V_24 > 0 )
F_9 ( V_2 , V_24 ) ;
V_17 = F_719 ( V_14 , V_1392 , sizeof( V_1392 ) ) ;
if ( V_17 )
F_708 ( V_1392 , L_7 , sizeof( V_1392 ) ) ;
if ( F_238 ( V_14 ) && V_14 -> V_46 . V_1047 != V_1462 )
F_12 ( L_153 ,
V_14 -> V_118 . type , V_14 -> V_46 . type , V_14 -> V_46 . V_1047 ,
V_1392 ) ;
else
F_12 ( L_154 ,
V_14 -> V_118 . type , V_14 -> V_46 . type , V_1392 ) ;
F_12 ( L_155 , V_77 -> V_715 ) ;
V_17 = V_14 -> V_118 . V_374 . V_1463 ( V_14 ) ;
if ( V_17 == V_757 ) {
F_11 ( L_90
L_156
L_157
L_158
L_94
L_95 ) ;
}
strcpy ( V_77 -> V_59 , L_159 ) ;
F_720 ( V_9 , V_2 ) ;
V_17 = F_721 ( V_77 ) ;
if ( V_17 )
goto V_1464;
if ( V_14 -> V_118 . V_374 . V_766 )
V_14 -> V_118 . V_374 . V_766 ( V_14 ) ;
F_436 ( V_77 ) ;
#ifdef F_259
if ( F_130 ( & V_9 -> V_89 ) == 0 ) {
V_2 -> V_148 |= V_196 ;
F_127 ( V_2 ) ;
}
#endif
if ( V_2 -> V_148 & V_458 ) {
F_109 ( V_190 , L_160 , V_2 -> V_340 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_340 ; V_49 ++ )
F_722 ( V_9 , ( V_49 | 0x10000000 ) ) ;
}
if ( V_14 -> V_118 . V_374 . V_1465 )
V_14 -> V_118 . V_374 . V_1465 ( V_14 , 0xFF , 0xFF , 0xFF , 0xFF ,
sizeof( V_1466 ) - 1 ,
V_1466 ) ;
F_621 ( V_77 ) ;
F_12 ( L_69 , V_1467 ) ;
#ifdef F_723
if ( F_724 ( V_2 ) )
F_107 ( V_190 , L_161 ) ;
#endif
F_725 ( V_2 ) ;
if ( F_726 ( V_14 ) && F_238 ( V_14 ) && V_14 -> V_118 . V_374 . V_726 )
V_14 -> V_118 . V_374 . V_726 ( V_14 ,
V_1000 | V_1025 ,
true ) ;
return 0 ;
V_1464:
F_73 ( V_2 ) ;
F_495 ( V_2 ) ;
V_1425:
F_727 ( V_2 ) ;
V_2 -> V_369 &= ~ V_721 ;
F_728 ( V_2 -> V_447 ) ;
F_268 ( V_2 -> V_811 [ 0 ] ) ;
F_268 ( V_2 -> V_623 ) ;
F_268 ( V_2 -> V_485 ) ;
V_1406:
V_1394 = ! F_15 ( V_851 , & V_2 -> V_35 ) ;
F_729 ( V_77 ) ;
V_1402:
F_730 ( V_9 ) ;
V_1400:
V_1398:
if ( ! V_2 || V_1394 )
F_496 ( V_9 ) ;
return V_17 ;
}
static void F_731 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_481 ( V_9 ) ;
struct V_76 * V_77 ;
bool V_1394 ;
int V_49 ;
if ( ! V_2 )
return;
V_77 = V_2 -> V_77 ;
F_732 ( V_2 ) ;
F_91 ( V_36 , & V_2 -> V_35 ) ;
F_608 ( & V_2 -> V_39 ) ;
#ifdef F_259
if ( V_2 -> V_148 & V_196 ) {
V_2 -> V_148 &= ~ V_196 ;
F_131 ( & V_9 -> V_89 ) ;
F_74 ( & V_2 -> V_14 , V_207 ,
V_209 ) ;
}
#endif
#ifdef F_723
F_733 ( V_2 ) ;
#endif
F_623 ( V_77 ) ;
#ifdef F_337
F_727 ( V_2 ) ;
#endif
if ( V_77 -> V_1048 == V_1049 )
F_545 ( V_77 ) ;
F_495 ( V_2 ) ;
F_73 ( V_2 ) ;
#ifdef F_734
F_268 ( V_2 -> V_147 ) ;
F_268 ( V_2 -> V_671 ) ;
#endif
F_728 ( V_2 -> V_447 ) ;
F_730 ( V_9 ) ;
F_12 ( L_162 ) ;
for ( V_49 = 0 ; V_49 < V_814 ; V_49 ++ ) {
if ( V_2 -> V_811 [ V_49 ] ) {
F_268 ( V_2 -> V_811 [ V_49 ] -> V_1126 ) ;
F_268 ( V_2 -> V_811 [ V_49 ] -> V_128 ) ;
}
F_268 ( V_2 -> V_811 [ V_49 ] ) ;
}
F_268 ( V_2 -> V_623 ) ;
F_268 ( V_2 -> V_485 ) ;
V_1394 = ! F_15 ( V_851 , & V_2 -> V_35 ) ;
F_729 ( V_77 ) ;
F_735 ( V_9 ) ;
if ( V_1394 )
F_496 ( V_9 ) ;
}
static T_19 F_736 ( struct V_5 * V_9 ,
T_20 V_35 )
{
struct V_1 * V_2 = F_481 ( V_9 ) ;
struct V_76 * V_77 = V_2 -> V_77 ;
#ifdef F_337
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_1468 , * V_1036 ;
T_1 V_1469 , V_1470 , V_1471 , V_1472 ;
int V_1033 , V_1473 ;
T_2 V_1474 , V_1475 ;
if ( V_2 -> V_14 . V_118 . type == V_119 ||
V_2 -> V_340 == 0 )
goto V_1476;
V_1468 = V_9 -> V_10 -> V_12 ;
while ( V_1468 && ( F_737 ( V_1468 ) != V_1477 ) )
V_1468 = V_1468 -> V_10 -> V_12 ;
if ( ! V_1468 )
goto V_1476;
V_1473 = F_738 ( V_1468 , V_1478 ) ;
if ( ! V_1473 )
goto V_1476;
V_1469 = F_30 ( V_14 , V_1473 + V_1479 ) ;
V_1470 = F_30 ( V_14 , V_1473 + V_1479 + 4 ) ;
V_1471 = F_30 ( V_14 , V_1473 + V_1479 + 8 ) ;
V_1472 = F_30 ( V_14 , V_1473 + V_1479 + 12 ) ;
if ( F_22 ( V_14 -> V_41 ) )
goto V_1476;
V_1474 = V_1470 >> 16 ;
if ( ! ( V_1474 & 0x0080 ) )
goto V_1476;
V_1475 = V_1474 & 0x01 ;
if ( ( V_1475 & 1 ) == ( V_9 -> V_1480 & 1 ) ) {
unsigned int V_21 ;
V_1033 = ( V_1474 & 0x7F ) >> 1 ;
F_18 ( L_163 , V_1033 ) ;
F_18 ( L_164
L_165 ,
V_1469 , V_1470 , V_1471 , V_1472 ) ;
switch ( V_2 -> V_14 . V_118 . type ) {
case V_121 :
V_21 = V_1481 ;
break;
case V_122 :
V_21 = V_1482 ;
break;
case V_123 :
V_21 = V_1483 ;
break;
case V_124 :
V_21 = V_1484 ;
break;
case V_125 :
V_21 = V_1485 ;
break;
default:
V_21 = 0 ;
break;
}
V_1036 = F_739 ( V_1486 , V_21 , NULL ) ;
while ( V_1036 ) {
if ( V_1036 -> V_1480 == ( V_1474 & 0xFF ) )
break;
V_1036 = F_739 ( V_1486 ,
V_21 , V_1036 ) ;
}
if ( V_1036 ) {
F_541 ( V_1036 ) ;
F_740 ( V_1036 ) ;
}
F_741 ( V_9 ) ;
}
V_2 -> V_1487 ++ ;
return V_1488 ;
V_1476:
#endif
if ( ! F_14 ( V_42 , & V_2 -> V_35 ) )
return V_1489 ;
F_488 () ;
F_494 ( V_77 ) ;
if ( V_35 == V_1490 ) {
F_491 () ;
return V_1489 ;
}
if ( F_63 ( V_77 ) )
F_475 ( V_2 ) ;
if ( ! F_15 ( V_851 , & V_2 -> V_35 ) )
F_496 ( V_9 ) ;
F_491 () ;
return V_1491 ;
}
static T_19 F_742 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_481 ( V_9 ) ;
T_19 V_314 ;
int V_17 ;
if ( F_485 ( V_9 ) ) {
F_107 ( V_190 , L_166 ) ;
V_314 = V_1489 ;
} else {
F_36 () ;
F_37 ( V_851 , & V_2 -> V_35 ) ;
V_2 -> V_14 . V_41 = V_2 -> V_447 ;
F_486 ( V_9 ) ;
F_483 ( V_9 ) ;
F_484 ( V_9 ) ;
F_487 ( V_9 , false ) ;
F_426 ( V_2 ) ;
F_74 ( & V_2 -> V_14 , V_852 , ~ 0 ) ;
V_314 = V_1488 ;
}
V_17 = F_741 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_167
L_168 , V_17 ) ;
}
return V_314 ;
}
static void F_743 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_481 ( V_9 ) ;
struct V_76 * V_77 = V_2 -> V_77 ;
#ifdef F_337
if ( V_2 -> V_1487 ) {
F_109 ( V_164 , L_169 ) ;
V_2 -> V_1487 -- ;
return;
}
#endif
F_488 () ;
if ( F_63 ( V_77 ) )
F_472 ( V_77 ) ;
F_490 ( V_77 ) ;
F_491 () ;
}
static int T_21 F_744 ( void )
{
int V_637 ;
F_54 ( L_170 , V_1492 , V_1466 ) ;
F_54 ( L_69 , V_1493 ) ;
V_38 = F_745 ( V_1399 ) ;
if ( ! V_38 ) {
F_55 ( L_171 , V_1399 ) ;
return - V_488 ;
}
F_746 () ;
V_637 = F_747 ( & V_1494 ) ;
if ( V_637 ) {
F_748 ( V_38 ) ;
F_749 () ;
return V_637 ;
}
#ifdef F_259
F_750 ( & V_1495 ) ;
#endif
return 0 ;
}
static void T_22 F_751 ( void )
{
#ifdef F_259
F_752 ( & V_1495 ) ;
#endif
F_753 ( & V_1494 ) ;
F_749 () ;
if ( V_38 ) {
F_748 ( V_38 ) ;
V_38 = NULL ;
}
}
static int F_754 ( struct V_1496 * V_1497 , unsigned long V_212 ,
void * V_62 )
{
int V_1498 ;
V_1498 = F_755 ( & V_1494 . V_1499 , NULL , & V_212 ,
F_128 ) ;
return V_1498 ? V_1500 : V_1501 ;
}
