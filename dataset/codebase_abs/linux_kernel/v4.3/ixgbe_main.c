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
F_16 ( & V_2 -> V_38 ) ;
}
static void F_17 ( struct V_15 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_39 ;
if ( ! V_14 -> V_40 )
return;
V_14 -> V_40 = NULL ;
F_18 ( L_13 ) ;
if ( F_14 ( V_41 , & V_2 -> V_35 ) )
F_13 ( V_2 ) ;
}
static void F_19 ( struct V_15 * V_14 , T_1 V_3 )
{
T_1 V_4 ;
if ( V_3 == V_42 ) {
F_17 ( V_14 ) ;
return;
}
V_4 = F_20 ( V_14 , V_42 ) ;
if ( V_4 == V_43 )
F_17 ( V_14 ) ;
}
T_1 F_20 ( struct V_15 * V_14 , T_1 V_3 )
{
T_4 T_5 * V_44 = F_21 ( V_14 -> V_40 ) ;
T_1 V_4 ;
if ( F_22 ( V_44 ) )
return V_43 ;
V_4 = F_23 ( V_44 + V_3 ) ;
if ( F_24 ( V_4 == V_43 ) )
F_19 ( V_14 , V_3 ) ;
return V_4 ;
}
static bool F_4 ( struct V_15 * V_14 , struct V_5 * V_9 )
{
T_2 V_4 ;
F_25 ( V_9 , V_45 , & V_4 ) ;
if ( V_4 == V_13 ) {
F_17 ( V_14 ) ;
return true ;
}
return false ;
}
T_2 F_26 ( struct V_15 * V_14 , T_1 V_3 )
{
struct V_1 * V_2 = V_14 -> V_39 ;
T_2 V_4 ;
if ( F_22 ( V_14 -> V_40 ) )
return V_13 ;
F_25 ( V_2 -> V_9 , V_3 , & V_4 ) ;
if ( V_4 == V_13 &&
F_4 ( V_14 , V_2 -> V_9 ) )
return V_13 ;
return V_4 ;
}
static T_1 F_27 ( struct V_15 * V_14 , T_1 V_3 )
{
struct V_1 * V_2 = V_14 -> V_39 ;
T_1 V_4 ;
if ( F_22 ( V_14 -> V_40 ) )
return V_46 ;
F_28 ( V_2 -> V_9 , V_3 , & V_4 ) ;
if ( V_4 == V_46 &&
F_4 ( V_14 , V_2 -> V_9 ) )
return V_46 ;
return V_4 ;
}
void F_29 ( struct V_15 * V_14 , T_1 V_3 , T_2 V_4 )
{
struct V_1 * V_2 = V_14 -> V_39 ;
if ( F_22 ( V_14 -> V_40 ) )
return;
F_30 ( V_2 -> V_9 , V_3 , V_4 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_32 ( ! F_14 ( V_37 , & V_2 -> V_35 ) ) ;
F_33 () ;
F_34 ( V_37 , & V_2 -> V_35 ) ;
}
static void F_35 ( struct V_15 * V_14 , struct V_47 * V_48 )
{
int V_49 = 0 , V_50 = 0 ;
char V_51 [ 16 ] ;
T_1 V_52 [ 64 ] ;
switch ( V_48 -> V_53 ) {
case F_36 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_52 [ V_49 ] = F_37 ( V_14 , F_36 ( V_49 ) ) ;
break;
case F_38 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_52 [ V_49 ] = F_37 ( V_14 , F_38 ( V_49 ) ) ;
break;
case F_39 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_52 [ V_49 ] = F_37 ( V_14 , F_39 ( V_49 ) ) ;
break;
case F_40 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_52 [ V_49 ] = F_37 ( V_14 , F_40 ( V_49 ) ) ;
break;
case F_41 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_52 [ V_49 ] = F_37 ( V_14 , F_41 ( V_49 ) ) ;
break;
case F_42 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_52 [ V_49 ] = F_37 ( V_14 , F_42 ( V_49 ) ) ;
break;
case F_43 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_52 [ V_49 ] = F_37 ( V_14 , F_43 ( V_49 ) ) ;
break;
case F_44 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_52 [ V_49 ] = F_37 ( V_14 , F_44 ( V_49 ) ) ;
break;
case F_45 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_52 [ V_49 ] = F_37 ( V_14 , F_45 ( V_49 ) ) ;
break;
case F_46 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_52 [ V_49 ] = F_37 ( V_14 , F_46 ( V_49 ) ) ;
break;
case F_47 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_52 [ V_49 ] = F_37 ( V_14 , F_47 ( V_49 ) ) ;
break;
case F_48 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_52 [ V_49 ] = F_37 ( V_14 , F_48 ( V_49 ) ) ;
break;
case F_49 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_52 [ V_49 ] = F_37 ( V_14 , F_49 ( V_49 ) ) ;
break;
case F_50 ( 0 ) :
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ )
V_52 [ V_49 ] = F_37 ( V_14 , F_50 ( V_49 ) ) ;
break;
default:
F_51 ( L_14 , V_48 -> V_54 ,
F_37 ( V_14 , V_48 -> V_53 ) ) ;
return;
}
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
snprintf ( V_51 , 16 , L_15 , V_48 -> V_54 , V_49 * 8 , V_49 * 8 + 7 ) ;
F_52 ( L_16 , V_51 ) ;
for ( V_50 = 0 ; V_50 < 8 ; V_50 ++ )
F_53 ( L_17 , V_52 [ V_49 * 8 + V_50 ] ) ;
F_53 ( L_18 ) ;
}
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_56 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_47 * V_48 ;
int V_57 = 0 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
union V_62 * V_63 ;
struct V_64 { T_6 V_65 ; T_6 V_66 ; } * V_67 ;
struct V_58 * V_68 ;
union V_69 * V_70 ;
struct V_71 * V_72 ;
T_1 V_73 ;
int V_49 = 0 ;
if ( ! F_55 ( V_2 ) )
return;
if ( V_56 ) {
F_56 ( & V_2 -> V_9 -> V_74 , L_19 ) ;
F_51 ( L_20
L_21 ) ;
F_51 ( L_22 ,
V_56 -> V_54 ,
V_56 -> V_35 ,
V_56 -> V_75 ,
V_56 -> V_76 ) ;
}
F_56 ( & V_2 -> V_9 -> V_74 , L_23 ) ;
F_51 ( L_24 ) ;
for ( V_48 = (struct V_47 * ) V_77 ;
V_48 -> V_54 ; V_48 ++ ) {
F_35 ( V_14 , V_48 ) ;
}
if ( ! V_56 || ! F_57 ( V_56 ) )
return;
F_56 ( & V_2 -> V_9 -> V_74 , L_25 ) ;
F_51 ( L_26 ,
L_27 ,
L_28 , L_29 , L_30 ) ;
for ( V_57 = 0 ; V_57 < V_2 -> V_78 ; V_57 ++ ) {
V_59 = V_2 -> V_59 [ V_57 ] ;
V_61 = & V_59 -> V_79 [ V_59 -> V_80 ] ;
F_51 ( L_31 ,
V_57 , V_59 -> V_81 , V_59 -> V_80 ,
( T_6 ) F_58 ( V_61 , V_82 ) ,
F_59 ( V_61 , V_83 ) ,
V_61 -> V_84 ,
( T_6 ) V_61 -> V_85 ) ;
}
if ( ! F_60 ( V_2 ) )
goto V_86;
F_56 ( & V_2 -> V_9 -> V_74 , L_32 ) ;
for ( V_57 = 0 ; V_57 < V_2 -> V_78 ; V_57 ++ ) {
V_59 = V_2 -> V_59 [ V_57 ] ;
F_51 ( L_33 ) ;
F_51 ( L_34 , V_59 -> V_87 ) ;
F_51 ( L_33 ) ;
F_51 ( L_35 ,
L_36 ,
L_37 ,
L_28 , L_29 , L_30 , L_38 ) ;
for ( V_49 = 0 ; V_59 -> V_88 && ( V_49 < V_59 -> V_89 ) ; V_49 ++ ) {
V_63 = F_61 ( V_59 , V_49 ) ;
V_61 = & V_59 -> V_79 [ V_49 ] ;
V_67 = (struct V_64 * ) V_63 ;
if ( F_59 ( V_61 , V_83 ) > 0 ) {
F_51 ( L_39 ,
V_49 ,
F_62 ( V_67 -> V_65 ) ,
F_62 ( V_67 -> V_66 ) ,
( T_6 ) F_58 ( V_61 , V_82 ) ,
F_59 ( V_61 , V_83 ) ,
V_61 -> V_84 ,
( T_6 ) V_61 -> V_85 ,
V_61 -> V_90 ) ;
if ( V_49 == V_59 -> V_81 &&
V_49 == V_59 -> V_80 )
F_53 ( L_40 ) ;
else if ( V_49 == V_59 -> V_81 )
F_53 ( L_41 ) ;
else if ( V_49 == V_59 -> V_80 )
F_53 ( L_42 ) ;
else
F_53 ( L_18 ) ;
if ( F_63 ( V_2 ) &&
V_61 -> V_90 )
F_64 ( V_91 , L_43 ,
V_92 , 16 , 1 ,
V_61 -> V_90 -> V_93 ,
F_59 ( V_61 , V_83 ) ,
true ) ;
}
}
}
V_86:
F_56 ( & V_2 -> V_9 -> V_74 , L_44 ) ;
F_51 ( L_45 ) ;
for ( V_57 = 0 ; V_57 < V_2 -> V_94 ; V_57 ++ ) {
V_68 = V_2 -> V_68 [ V_57 ] ;
F_51 ( L_46 ,
V_57 , V_68 -> V_81 , V_68 -> V_80 ) ;
}
if ( ! F_65 ( V_2 ) )
return;
F_56 ( & V_2 -> V_9 -> V_74 , L_47 ) ;
for ( V_57 = 0 ; V_57 < V_2 -> V_94 ; V_57 ++ ) {
V_68 = V_2 -> V_68 [ V_57 ] ;
F_51 ( L_33 ) ;
F_51 ( L_48 , V_68 -> V_87 ) ;
F_51 ( L_33 ) ;
F_51 ( L_49 ,
L_50 ,
L_51 ,
L_52 ) ;
F_51 ( L_49 ,
L_53 ,
L_54 ,
L_55 ) ;
for ( V_49 = 0 ; V_49 < V_68 -> V_89 ; V_49 ++ ) {
V_72 = & V_68 -> V_72 [ V_49 ] ;
V_70 = F_66 ( V_68 , V_49 ) ;
V_67 = (struct V_64 * ) V_70 ;
V_73 = F_67 ( V_70 -> V_95 . V_96 . V_97 ) ;
if ( V_73 & V_98 ) {
F_51 ( L_56
L_57 , V_49 ,
F_62 ( V_67 -> V_65 ) ,
F_62 ( V_67 -> V_66 ) ,
V_72 -> V_90 ) ;
} else {
F_51 ( L_58
L_59 , V_49 ,
F_62 ( V_67 -> V_65 ) ,
F_62 ( V_67 -> V_66 ) ,
( T_6 ) V_72 -> V_82 ,
V_72 -> V_90 ) ;
if ( F_63 ( V_2 ) &&
V_72 -> V_82 ) {
F_64 ( V_91 , L_43 ,
V_92 , 16 , 1 ,
F_68 ( V_72 -> V_99 ) +
V_72 -> V_100 ,
F_69 ( V_68 ) , true ) ;
}
}
if ( V_49 == V_68 -> V_81 )
F_53 ( L_41 ) ;
else if ( V_49 == V_68 -> V_80 )
F_53 ( L_42 ) ;
else
F_53 ( L_18 ) ;
}
}
}
static void F_70 ( struct V_1 * V_2 )
{
T_1 V_101 ;
V_101 = F_37 ( & V_2 -> V_14 , V_102 ) ;
F_71 ( & V_2 -> V_14 , V_102 ,
V_101 & ~ V_103 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
T_1 V_101 ;
V_101 = F_37 ( & V_2 -> V_14 , V_102 ) ;
F_71 ( & V_2 -> V_14 , V_102 ,
V_101 | V_103 ) ;
}
static void F_73 ( struct V_1 * V_2 , T_7 V_104 ,
T_4 V_105 , T_4 V_106 )
{
T_1 V_107 , V_108 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
V_106 |= V_111 ;
if ( V_104 == - 1 )
V_104 = 0 ;
V_108 = ( ( ( V_104 * 64 ) + V_105 ) >> 2 ) & 0x1F ;
V_107 = F_37 ( V_14 , F_74 ( V_108 ) ) ;
V_107 &= ~ ( 0xFF << ( 8 * ( V_105 & 0x3 ) ) ) ;
V_107 |= ( V_106 << ( 8 * ( V_105 & 0x3 ) ) ) ;
F_71 ( V_14 , F_74 ( V_108 ) , V_107 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
if ( V_104 == - 1 ) {
V_106 |= V_111 ;
V_108 = ( ( V_105 & 1 ) * 8 ) ;
V_107 = F_37 ( & V_2 -> V_14 , V_116 ) ;
V_107 &= ~ ( 0xFF << V_108 ) ;
V_107 |= ( V_106 << V_108 ) ;
F_71 ( & V_2 -> V_14 , V_116 , V_107 ) ;
break;
} else {
V_106 |= V_111 ;
V_108 = ( ( 16 * ( V_105 & 1 ) ) + ( 8 * V_104 ) ) ;
V_107 = F_37 ( V_14 , F_74 ( V_105 >> 1 ) ) ;
V_107 &= ~ ( 0xFF << V_108 ) ;
V_107 |= ( V_106 << V_108 ) ;
F_71 ( V_14 , F_74 ( V_105 >> 1 ) , V_107 ) ;
break;
}
default:
break;
}
}
static inline void F_75 ( struct V_1 * V_2 ,
T_6 V_117 )
{
T_1 V_118 ;
switch ( V_2 -> V_14 . V_109 . type ) {
case V_110 :
V_118 = ( V_119 & V_117 ) ;
F_71 ( & V_2 -> V_14 , V_120 , V_118 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_118 = ( V_117 & 0xFFFFFFFF ) ;
F_71 ( & V_2 -> V_14 , F_76 ( 0 ) , V_118 ) ;
V_118 = ( V_117 >> 32 ) ;
F_71 ( & V_2 -> V_14 , F_76 ( 1 ) , V_118 ) ;
break;
default:
break;
}
}
void F_77 ( struct V_58 * V_121 ,
struct V_60 * V_61 )
{
if ( V_61 -> V_90 ) {
F_78 ( V_61 -> V_90 ) ;
if ( F_59 ( V_61 , V_83 ) )
F_79 ( V_121 -> V_74 ,
F_58 ( V_61 , V_82 ) ,
F_59 ( V_61 , V_83 ) ,
V_122 ) ;
} else if ( F_59 ( V_61 , V_83 ) ) {
F_80 ( V_121 -> V_74 ,
F_58 ( V_61 , V_82 ) ,
F_59 ( V_61 , V_83 ) ,
V_122 ) ;
}
V_61 -> V_84 = NULL ;
V_61 -> V_90 = NULL ;
F_81 ( V_61 , V_83 , 0 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_123 * V_124 = & V_2 -> V_125 ;
int V_49 ;
T_1 V_93 ;
if ( ( V_14 -> V_126 . V_127 != V_128 ) &&
( V_14 -> V_126 . V_127 != V_129 ) )
return;
switch ( V_14 -> V_109 . type ) {
case V_110 :
V_93 = F_37 ( V_14 , V_130 ) ;
break;
default:
V_93 = F_37 ( V_14 , V_131 ) ;
}
V_124 -> V_132 += V_93 ;
if ( ! V_93 )
return;
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ )
F_34 ( V_133 ,
& V_2 -> V_59 [ V_49 ] -> V_35 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_123 * V_124 = & V_2 -> V_125 ;
T_1 V_134 [ 8 ] = { 0 } ;
T_4 V_135 ;
int V_49 ;
bool V_136 = V_2 -> V_137 . V_138 ;
if ( V_2 -> V_139 )
V_136 |= ! ! ( V_2 -> V_139 -> V_136 ) ;
if ( ! ( V_2 -> V_140 & V_141 ) || ! V_136 ) {
F_82 ( V_2 ) ;
return;
}
for ( V_49 = 0 ; V_49 < V_142 ; V_49 ++ ) {
T_1 V_143 ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
V_143 = F_37 ( V_14 , F_84 ( V_49 ) ) ;
break;
default:
V_143 = F_37 ( V_14 , F_85 ( V_49 ) ) ;
}
V_124 -> V_143 [ V_49 ] += V_143 ;
V_135 = F_86 ( V_2 -> V_56 , V_49 ) ;
V_134 [ V_135 ] += V_143 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ ) {
struct V_58 * V_59 = V_2 -> V_59 [ V_49 ] ;
V_135 = V_59 -> V_144 ;
if ( V_134 [ V_135 ] )
F_34 ( V_133 , & V_59 -> V_35 ) ;
}
}
static T_6 F_87 ( struct V_58 * V_121 )
{
return V_121 -> V_125 . V_145 ;
}
static T_6 F_88 ( struct V_58 * V_121 )
{
struct V_1 * V_2 ;
struct V_15 * V_14 ;
T_1 V_146 , V_147 ;
if ( V_121 -> V_148 )
V_2 = V_121 -> V_148 -> V_149 ;
else
V_2 = F_89 ( V_121 -> V_56 ) ;
V_14 = & V_2 -> V_14 ;
V_146 = F_37 ( V_14 , F_48 ( V_121 -> V_150 ) ) ;
V_147 = F_37 ( V_14 , F_49 ( V_121 -> V_150 ) ) ;
if ( V_146 != V_147 )
return ( V_146 < V_147 ) ?
V_147 - V_146 : ( V_147 + V_121 -> V_89 - V_146 ) ;
return 0 ;
}
static inline bool F_90 ( struct V_58 * V_59 )
{
T_1 V_151 = F_87 ( V_59 ) ;
T_1 V_152 = V_59 -> V_153 . V_152 ;
T_1 V_154 = F_88 ( V_59 ) ;
F_91 ( V_59 ) ;
if ( V_152 == V_151 && V_154 )
return F_15 ( V_133 ,
& V_59 -> V_35 ) ;
V_59 -> V_153 . V_152 = V_151 ;
F_34 ( V_133 , & V_59 -> V_35 ) ;
return false ;
}
static void F_92 ( struct V_1 * V_2 )
{
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_155 |= V_156 ;
F_93 ( V_157 , L_60 ) ;
F_13 ( V_2 ) ;
}
}
static bool F_94 ( struct V_158 * V_159 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = V_159 -> V_2 ;
struct V_60 * V_61 ;
union V_62 * V_63 ;
unsigned int V_160 = 0 , V_161 = 0 ;
unsigned int V_162 = V_159 -> V_163 . V_164 ;
unsigned int V_49 = V_59 -> V_80 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return true ;
V_61 = & V_59 -> V_79 [ V_49 ] ;
V_63 = F_61 ( V_59 , V_49 ) ;
V_49 -= V_59 -> V_89 ;
do {
union V_62 * V_165 = V_61 -> V_84 ;
if ( ! V_165 )
break;
F_95 () ;
if ( ! ( V_165 -> V_95 . V_166 & F_96 ( V_167 ) ) )
break;
V_61 -> V_84 = NULL ;
V_160 += V_61 -> V_168 ;
V_161 += V_61 -> V_169 ;
F_97 ( V_61 -> V_90 ) ;
F_79 ( V_59 -> V_74 ,
F_58 ( V_61 , V_82 ) ,
F_59 ( V_61 , V_83 ) ,
V_122 ) ;
V_61 -> V_90 = NULL ;
F_81 ( V_61 , V_83 , 0 ) ;
while ( V_63 != V_165 ) {
V_61 ++ ;
V_63 ++ ;
V_49 ++ ;
if ( F_24 ( ! V_49 ) ) {
V_49 -= V_59 -> V_89 ;
V_61 = V_59 -> V_79 ;
V_63 = F_61 ( V_59 , 0 ) ;
}
if ( F_59 ( V_61 , V_83 ) ) {
F_80 ( V_59 -> V_74 ,
F_58 ( V_61 , V_82 ) ,
F_59 ( V_61 , V_83 ) ,
V_122 ) ;
F_81 ( V_61 , V_83 , 0 ) ;
}
}
V_61 ++ ;
V_63 ++ ;
V_49 ++ ;
if ( F_24 ( ! V_49 ) ) {
V_49 -= V_59 -> V_89 ;
V_61 = V_59 -> V_79 ;
V_63 = F_61 ( V_59 , 0 ) ;
}
F_98 ( V_63 ) ;
V_162 -- ;
} while ( F_99 ( V_162 ) );
V_49 += V_59 -> V_89 ;
V_59 -> V_80 = V_49 ;
F_100 ( & V_59 -> V_170 ) ;
V_59 -> V_125 . V_171 += V_160 ;
V_59 -> V_125 . V_145 += V_161 ;
F_101 ( & V_59 -> V_170 ) ;
V_159 -> V_163 . V_160 += V_160 ;
V_159 -> V_163 . V_161 += V_161 ;
if ( F_102 ( V_59 ) && F_90 ( V_59 ) ) {
struct V_15 * V_14 = & V_2 -> V_14 ;
F_103 ( V_157 , L_61
L_62
L_63
L_64
L_65
L_66
L_67
L_68 ,
V_59 -> V_87 ,
F_37 ( V_14 , F_48 ( V_59 -> V_150 ) ) ,
F_37 ( V_14 , F_49 ( V_59 -> V_150 ) ) ,
V_59 -> V_81 , V_49 ,
V_59 -> V_79 [ V_49 ] . V_85 , V_172 ) ;
F_104 ( V_59 -> V_56 , V_59 -> V_87 ) ;
F_105 ( V_173 ,
L_69 ,
V_2 -> V_174 + 1 , V_59 -> V_87 ) ;
F_92 ( V_2 ) ;
return true ;
}
F_106 ( F_107 ( V_59 ) ,
V_161 , V_160 ) ;
#define F_108 (DESC_NEEDED * 2)
if ( F_24 ( V_161 && F_109 ( V_59 -> V_56 ) &&
( F_110 ( V_59 ) >= F_108 ) ) ) {
F_111 () ;
if ( F_112 ( V_59 -> V_56 ,
V_59 -> V_87 )
&& ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_113 ( V_59 -> V_56 ,
V_59 -> V_87 ) ;
++ V_59 -> V_153 . V_175 ;
}
}
return ! ! V_162 ;
}
static void F_114 ( struct V_1 * V_2 ,
struct V_58 * V_59 ,
int V_176 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_177 = F_115 ( V_59 -> V_74 , V_176 ) ;
T_2 V_178 ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
V_178 = F_116 ( V_59 -> V_150 ) ;
break;
case V_112 :
case V_113 :
V_178 = F_117 ( V_59 -> V_150 ) ;
V_177 <<= V_179 ;
break;
default:
return;
}
V_177 |= V_180 |
V_181 |
V_182 ;
F_71 ( V_14 , V_178 , V_177 ) ;
}
static void F_118 ( struct V_1 * V_2 ,
struct V_58 * V_68 ,
int V_176 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_183 = F_115 ( V_68 -> V_74 , V_176 ) ;
T_4 V_150 = V_68 -> V_150 ;
switch ( V_14 -> V_109 . type ) {
case V_112 :
case V_113 :
V_183 <<= V_184 ;
break;
default:
break;
}
V_183 |= V_185 |
V_186 ;
F_71 ( V_14 , F_38 ( V_150 ) , V_183 ) ;
}
static void F_119 ( struct V_158 * V_159 )
{
struct V_1 * V_2 = V_159 -> V_2 ;
struct V_58 * V_121 ;
int V_176 = F_120 () ;
if ( V_159 -> V_176 == V_176 )
goto V_187;
F_121 (ring, q_vector->tx)
F_114 ( V_2 , V_121 , V_176 ) ;
F_121 (ring, q_vector->rx)
F_118 ( V_2 , V_121 , V_176 ) ;
V_159 -> V_176 = V_176 ;
V_187:
F_122 () ;
}
static void F_123 ( struct V_1 * V_2 )
{
int V_49 ;
if ( ! ( V_2 -> V_140 & V_188 ) )
return;
F_71 ( & V_2 -> V_14 , V_189 , 2 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_190 ; V_49 ++ ) {
V_2 -> V_159 [ V_49 ] -> V_176 = - 1 ;
F_119 ( V_2 -> V_159 [ V_49 ] ) ;
}
}
static int F_124 ( struct V_191 * V_74 , void * V_93 )
{
struct V_1 * V_2 = F_125 ( V_74 ) ;
unsigned long V_192 = * ( unsigned long * ) V_93 ;
if ( ! ( V_2 -> V_140 & V_193 ) )
return 0 ;
switch ( V_192 ) {
case V_194 :
if ( V_2 -> V_140 & V_188 )
break;
if ( F_126 ( V_74 ) == 0 ) {
V_2 -> V_140 |= V_188 ;
F_123 ( V_2 ) ;
break;
}
case V_195 :
if ( V_2 -> V_140 & V_188 ) {
F_127 ( V_74 ) ;
V_2 -> V_140 &= ~ V_188 ;
F_71 ( & V_2 -> V_14 , V_189 , 1 ) ;
}
break;
}
return 0 ;
}
static inline void F_128 ( struct V_58 * V_121 ,
union V_69 * V_70 ,
struct V_196 * V_90 )
{
T_2 V_197 ;
if ( ! ( V_121 -> V_56 -> V_198 & V_199 ) )
return;
V_197 = F_129 ( V_70 -> V_95 . V_200 . V_201 . V_202 . V_203 ) &
V_204 ;
if ( ! V_197 )
return;
F_130 ( V_90 , F_67 ( V_70 -> V_95 . V_200 . V_205 . V_206 ) ,
( V_207 & ( 1ul << V_197 ) ) ?
V_208 : V_209 ) ;
}
static inline bool F_131 ( struct V_58 * V_121 ,
union V_69 * V_70 )
{
T_8 V_203 = V_70 -> V_95 . V_200 . V_201 . V_202 . V_203 ;
return F_14 ( V_210 , & V_121 -> V_35 ) &&
( ( V_203 & F_132 ( V_211 ) ) ==
( F_132 ( V_212 <<
V_213 ) ) ) ;
}
static inline void F_133 ( struct V_58 * V_121 ,
union V_69 * V_70 ,
struct V_196 * V_90 )
{
T_8 V_203 = V_70 -> V_95 . V_200 . V_201 . V_202 . V_203 ;
T_8 V_214 = V_70 -> V_95 . V_200 . V_201 . V_202 . V_214 ;
bool V_215 = false ;
F_134 ( V_90 ) ;
if ( ! ( V_121 -> V_56 -> V_198 & V_216 ) )
return;
if ( ( V_203 & F_132 ( V_217 ) ) &&
( V_214 & F_132 ( V_218 >> 16 ) ) ) {
V_215 = true ;
V_90 -> V_219 = 1 ;
}
if ( F_135 ( V_70 , V_220 ) &&
F_135 ( V_70 , V_221 ) ) {
V_121 -> V_222 . V_223 ++ ;
return;
}
if ( ! F_135 ( V_70 , V_224 ) )
return;
if ( F_135 ( V_70 , V_225 ) ) {
if ( ( V_203 & F_132 ( V_226 ) ) &&
F_14 ( V_227 , & V_121 -> V_35 ) )
return;
V_121 -> V_222 . V_223 ++ ;
return;
}
V_90 -> V_228 = V_229 ;
if ( V_215 ) {
if ( ! F_135 ( V_70 , V_230 ) )
return;
if ( F_135 ( V_70 , V_231 ) ) {
V_121 -> V_222 . V_223 ++ ;
return;
}
V_90 -> V_232 = 1 ;
}
}
static bool F_136 ( struct V_58 * V_68 ,
struct V_71 * V_233 )
{
struct V_99 * V_99 = V_233 -> V_99 ;
T_9 V_82 ;
if ( F_99 ( V_99 ) )
return true ;
V_99 = F_137 ( F_138 ( V_68 ) ) ;
if ( F_24 ( ! V_99 ) ) {
V_68 -> V_222 . V_234 ++ ;
return false ;
}
V_82 = F_139 ( V_68 -> V_74 , V_99 , 0 ,
F_140 ( V_68 ) , V_235 ) ;
if ( F_141 ( V_68 -> V_74 , V_82 ) ) {
F_142 ( V_99 , F_138 ( V_68 ) ) ;
V_68 -> V_222 . V_234 ++ ;
return false ;
}
V_233 -> V_82 = V_82 ;
V_233 -> V_99 = V_99 ;
V_233 -> V_100 = 0 ;
return true ;
}
void F_143 ( struct V_58 * V_68 , T_2 V_236 )
{
union V_69 * V_70 ;
struct V_71 * V_233 ;
T_2 V_49 = V_68 -> V_81 ;
if ( ! V_236 )
return;
V_70 = F_66 ( V_68 , V_49 ) ;
V_233 = & V_68 -> V_72 [ V_49 ] ;
V_49 -= V_68 -> V_89 ;
do {
if ( ! F_136 ( V_68 , V_233 ) )
break;
V_70 -> V_237 . V_238 = F_144 ( V_233 -> V_82 + V_233 -> V_100 ) ;
V_70 ++ ;
V_233 ++ ;
V_49 ++ ;
if ( F_24 ( ! V_49 ) ) {
V_70 = F_66 ( V_68 , 0 ) ;
V_233 = V_68 -> V_72 ;
V_49 -= V_68 -> V_89 ;
}
V_70 -> V_95 . V_96 . V_97 = 0 ;
V_236 -- ;
} while ( V_236 );
V_49 += V_68 -> V_89 ;
if ( V_68 -> V_81 != V_49 ) {
V_68 -> V_81 = V_49 ;
V_68 -> V_239 = V_49 ;
F_145 () ;
F_146 ( V_49 , V_68 -> V_147 ) ;
}
}
static void F_147 ( struct V_58 * V_121 ,
struct V_196 * V_90 )
{
T_2 V_240 = F_148 ( V_90 ) ;
F_149 ( V_90 ) -> V_241 = F_150 ( ( V_90 -> V_83 - V_240 ) ,
F_151 ( V_90 ) -> V_242 ) ;
F_149 ( V_90 ) -> V_243 = V_244 ;
}
static void F_152 ( struct V_58 * V_68 ,
struct V_196 * V_90 )
{
if ( ! F_151 ( V_90 ) -> V_242 )
return;
V_68 -> V_222 . V_245 += F_151 ( V_90 ) -> V_242 ;
V_68 -> V_222 . V_246 ++ ;
F_147 ( V_68 , V_90 ) ;
F_151 ( V_90 ) -> V_242 = 0 ;
}
static void F_153 ( struct V_58 * V_68 ,
union V_69 * V_70 ,
struct V_196 * V_90 )
{
struct V_55 * V_74 = V_68 -> V_56 ;
F_152 ( V_68 , V_90 ) ;
F_128 ( V_68 , V_70 , V_90 ) ;
F_133 ( V_68 , V_70 , V_90 ) ;
if ( F_24 ( F_135 ( V_70 , V_247 ) ) )
F_154 ( V_68 -> V_159 -> V_2 , V_90 ) ;
if ( ( V_74 -> V_198 & V_248 ) &&
F_135 ( V_70 , V_249 ) ) {
T_2 V_250 = F_129 ( V_70 -> V_95 . V_96 . V_251 ) ;
F_155 ( V_90 , F_156 ( V_252 ) , V_250 ) ;
}
F_157 ( V_90 , V_68 -> V_87 ) ;
V_90 -> V_253 = F_158 ( V_90 , V_74 ) ;
}
static void F_159 ( struct V_158 * V_159 ,
struct V_196 * V_90 )
{
if ( F_160 ( V_159 ) )
F_161 ( V_90 ) ;
else
F_162 ( & V_159 -> V_254 , V_90 ) ;
}
static bool F_163 ( struct V_58 * V_68 ,
union V_69 * V_70 ,
struct V_196 * V_90 )
{
T_1 V_255 = V_68 -> V_80 + 1 ;
V_255 = ( V_255 < V_68 -> V_89 ) ? V_255 : 0 ;
V_68 -> V_80 = V_255 ;
F_98 ( F_66 ( V_68 , V_255 ) ) ;
if ( F_164 ( V_68 ) ) {
T_10 V_256 = V_70 -> V_95 . V_200 . V_201 . V_93 &
F_96 ( V_257 ) ;
if ( F_24 ( V_256 ) ) {
T_1 V_258 = F_67 ( V_256 ) ;
V_258 >>= V_259 ;
F_151 ( V_90 ) -> V_242 += V_258 - 1 ;
V_255 = F_67 ( V_70 -> V_95 . V_96 . V_97 ) ;
V_255 &= V_260 ;
V_255 >>= V_261 ;
}
}
if ( F_99 ( F_135 ( V_70 , V_262 ) ) )
return false ;
V_68 -> V_72 [ V_255 ] . V_90 = V_90 ;
V_68 -> V_222 . V_263 ++ ;
return true ;
}
static void F_165 ( struct V_58 * V_68 ,
struct V_196 * V_90 )
{
struct V_264 * V_265 = & F_149 ( V_90 ) -> V_266 [ 0 ] ;
unsigned char * V_267 ;
unsigned int V_268 ;
V_267 = F_166 ( V_265 ) ;
V_268 = F_167 ( V_267 , V_269 ) ;
F_168 ( V_90 , V_267 , F_169 ( V_268 , sizeof( long ) ) ) ;
F_170 ( V_265 , V_268 ) ;
V_265 -> V_100 += V_268 ;
V_90 -> V_270 -= V_268 ;
V_90 -> V_147 += V_268 ;
}
static void F_171 ( struct V_58 * V_68 ,
struct V_196 * V_90 )
{
if ( F_24 ( F_151 ( V_90 ) -> V_271 ) ) {
F_80 ( V_68 -> V_74 , F_151 ( V_90 ) -> V_82 ,
F_140 ( V_68 ) , V_235 ) ;
F_151 ( V_90 ) -> V_271 = false ;
} else {
struct V_264 * V_265 = & F_149 ( V_90 ) -> V_266 [ 0 ] ;
F_172 ( V_68 -> V_74 ,
F_151 ( V_90 ) -> V_82 ,
V_265 -> V_100 ,
F_69 ( V_68 ) ,
V_235 ) ;
}
F_151 ( V_90 ) -> V_82 = 0 ;
}
static bool F_173 ( struct V_58 * V_68 ,
union V_69 * V_70 ,
struct V_196 * V_90 )
{
struct V_55 * V_56 = V_68 -> V_56 ;
if ( F_24 ( F_135 ( V_70 ,
V_272 ) &&
! ( V_56 -> V_198 & V_273 ) ) ) {
F_78 ( V_90 ) ;
return true ;
}
if ( F_174 ( V_90 ) )
F_165 ( V_68 , V_90 ) ;
#ifdef F_175
if ( F_131 ( V_68 , V_70 ) )
return false ;
#endif
if ( F_176 ( V_90 ) )
return true ;
return false ;
}
static void F_177 ( struct V_58 * V_68 ,
struct V_71 * V_274 )
{
struct V_71 * V_275 ;
T_2 V_276 = V_68 -> V_239 ;
V_275 = & V_68 -> V_72 [ V_276 ] ;
V_276 ++ ;
V_68 -> V_239 = ( V_276 < V_68 -> V_89 ) ? V_276 : 0 ;
* V_275 = * V_274 ;
F_178 ( V_68 -> V_74 , V_275 -> V_82 ,
V_275 -> V_100 ,
F_69 ( V_68 ) ,
V_235 ) ;
}
static inline bool F_179 ( struct V_99 * V_99 )
{
return ( F_180 ( V_99 ) != F_181 () ) || F_182 ( V_99 ) ;
}
static bool F_183 ( struct V_58 * V_68 ,
struct V_71 * V_277 ,
union V_69 * V_70 ,
struct V_196 * V_90 )
{
struct V_99 * V_99 = V_277 -> V_99 ;
unsigned int V_278 = F_129 ( V_70 -> V_95 . V_96 . V_279 ) ;
#if ( V_280 < 8192 )
unsigned int V_281 = F_69 ( V_68 ) ;
#else
unsigned int V_281 = F_169 ( V_278 , V_282 ) ;
unsigned int V_283 = F_140 ( V_68 ) -
F_69 ( V_68 ) ;
#endif
if ( ( V_278 <= V_269 ) && ! F_174 ( V_90 ) ) {
unsigned char * V_267 = F_68 ( V_99 ) + V_277 -> V_100 ;
memcpy ( F_184 ( V_90 , V_278 ) , V_267 , F_169 ( V_278 , sizeof( long ) ) ) ;
if ( F_99 ( ! F_179 ( V_99 ) ) )
return true ;
F_142 ( V_99 , F_138 ( V_68 ) ) ;
return false ;
}
F_185 ( V_90 , F_149 ( V_90 ) -> V_284 , V_99 ,
V_277 -> V_100 , V_278 , V_281 ) ;
if ( F_24 ( F_179 ( V_99 ) ) )
return false ;
#if ( V_280 < 8192 )
if ( F_24 ( F_186 ( V_99 ) != 1 ) )
return false ;
V_277 -> V_100 ^= V_281 ;
#else
V_277 -> V_100 += V_281 ;
if ( V_277 -> V_100 > V_283 )
return false ;
#endif
F_187 ( & V_99 -> V_285 ) ;
return true ;
}
static struct V_196 * F_188 ( struct V_58 * V_68 ,
union V_69 * V_70 )
{
struct V_71 * V_277 ;
struct V_196 * V_90 ;
struct V_99 * V_99 ;
V_277 = & V_68 -> V_72 [ V_68 -> V_80 ] ;
V_99 = V_277 -> V_99 ;
F_189 ( V_99 ) ;
V_90 = V_277 -> V_90 ;
if ( F_99 ( ! V_90 ) ) {
void * V_286 = F_68 ( V_99 ) +
V_277 -> V_100 ;
F_98 ( V_286 ) ;
#if V_282 < 128
F_98 ( V_286 + V_282 ) ;
#endif
V_90 = F_190 ( & V_68 -> V_159 -> V_254 ,
V_269 ) ;
if ( F_24 ( ! V_90 ) ) {
V_68 -> V_222 . V_287 ++ ;
return NULL ;
}
F_189 ( V_90 -> V_93 ) ;
if ( F_99 ( F_135 ( V_70 , V_262 ) ) )
goto V_288;
F_151 ( V_90 ) -> V_82 = V_277 -> V_82 ;
} else {
if ( F_135 ( V_70 , V_262 ) )
F_171 ( V_68 , V_90 ) ;
V_288:
F_172 ( V_68 -> V_74 ,
V_277 -> V_82 ,
V_277 -> V_100 ,
F_69 ( V_68 ) ,
V_235 ) ;
V_277 -> V_90 = NULL ;
}
if ( F_183 ( V_68 , V_277 , V_70 , V_90 ) ) {
F_177 ( V_68 , V_277 ) ;
} else if ( F_151 ( V_90 ) -> V_82 == V_277 -> V_82 ) {
F_151 ( V_90 ) -> V_271 = true ;
} else {
F_80 ( V_68 -> V_74 , V_277 -> V_82 ,
F_140 ( V_68 ) ,
V_235 ) ;
}
V_277 -> V_99 = NULL ;
return V_90 ;
}
static int F_191 ( struct V_158 * V_159 ,
struct V_58 * V_68 ,
const int V_162 )
{
unsigned int V_289 = 0 , V_290 = 0 ;
#ifdef F_175
struct V_1 * V_2 = V_159 -> V_2 ;
int V_291 ;
unsigned int V_292 = 0 ;
#endif
T_2 V_236 = F_110 ( V_68 ) ;
while ( F_99 ( V_290 < V_162 ) ) {
union V_69 * V_70 ;
struct V_196 * V_90 ;
if ( V_236 >= V_293 ) {
F_143 ( V_68 , V_236 ) ;
V_236 = 0 ;
}
V_70 = F_66 ( V_68 , V_68 -> V_80 ) ;
if ( ! V_70 -> V_95 . V_96 . V_97 )
break;
F_192 () ;
V_90 = F_188 ( V_68 , V_70 ) ;
if ( ! V_90 )
break;
V_236 ++ ;
if ( F_163 ( V_68 , V_70 , V_90 ) )
continue;
if ( F_173 ( V_68 , V_70 , V_90 ) )
continue;
V_289 += V_90 -> V_83 ;
F_153 ( V_68 , V_70 , V_90 ) ;
#ifdef F_175
if ( F_131 ( V_68 , V_70 ) ) {
V_291 = F_193 ( V_2 , V_70 , V_90 ) ;
if ( V_291 > 0 ) {
if ( ! V_292 ) {
V_292 = V_68 -> V_56 -> V_294 -
sizeof( struct V_295 ) -
sizeof( struct V_296 ) -
sizeof( struct V_297 ) ;
if ( V_292 > 512 )
V_292 &= ~ 511 ;
}
V_289 += V_291 ;
V_290 += F_150 ( V_291 ,
V_292 ) ;
}
if ( ! V_291 ) {
F_78 ( V_90 ) ;
continue;
}
}
#endif
F_194 ( V_90 , & V_159 -> V_254 ) ;
F_159 ( V_159 , V_90 ) ;
V_290 ++ ;
}
F_100 ( & V_68 -> V_170 ) ;
V_68 -> V_125 . V_145 += V_290 ;
V_68 -> V_125 . V_171 += V_289 ;
F_101 ( & V_68 -> V_170 ) ;
V_159 -> V_298 . V_161 += V_290 ;
V_159 -> V_298 . V_160 += V_289 ;
return V_290 ;
}
static int F_195 ( struct V_299 * V_254 )
{
struct V_158 * V_159 =
F_196 ( V_254 , struct V_158 , V_254 ) ;
struct V_1 * V_2 = V_159 -> V_2 ;
struct V_58 * V_121 ;
int V_300 = 0 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return V_301 ;
if ( ! F_197 ( V_159 ) )
return V_302 ;
F_121 (ring, q_vector->rx) {
V_300 = F_191 ( V_159 , V_121 , 4 ) ;
#ifdef F_198
if ( V_300 )
V_121 -> V_125 . V_303 += V_300 ;
else
V_121 -> V_125 . V_304 ++ ;
#endif
if ( V_300 )
break;
}
F_199 ( V_159 ) ;
return V_300 ;
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_158 * V_159 ;
int V_305 ;
T_1 V_118 ;
if ( V_2 -> V_306 > 32 ) {
T_1 V_307 = ( 1 << ( V_2 -> V_306 - 32 ) ) - 1 ;
F_71 ( & V_2 -> V_14 , V_308 , V_307 ) ;
}
for ( V_305 = 0 ; V_305 < V_2 -> V_190 ; V_305 ++ ) {
struct V_58 * V_121 ;
V_159 = V_2 -> V_159 [ V_305 ] ;
F_121 (ring, q_vector->rx)
F_73 ( V_2 , 0 , V_121 -> V_150 , V_305 ) ;
F_121 (ring, q_vector->tx)
F_73 ( V_2 , 1 , V_121 -> V_150 , V_305 ) ;
F_201 ( V_159 ) ;
}
switch ( V_2 -> V_14 . V_109 . type ) {
case V_110 :
F_73 ( V_2 , - 1 , V_309 ,
V_305 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
F_73 ( V_2 , - 1 , 1 , V_305 ) ;
break;
default:
break;
}
F_71 ( & V_2 -> V_14 , F_202 ( V_305 ) , 1950 ) ;
V_118 = V_310 ;
V_118 &= ~ ( V_311 |
V_312 |
V_313 ) ;
F_71 ( & V_2 -> V_14 , V_314 , V_118 ) ;
}
static void F_203 ( struct V_158 * V_159 ,
struct V_315 * V_316 )
{
int V_171 = V_316 -> V_160 ;
int V_145 = V_316 -> V_161 ;
T_1 V_317 ;
T_6 V_318 ;
T_4 V_319 = V_316 -> V_320 ;
if ( V_145 == 0 )
return;
V_317 = V_159 -> V_320 >> 2 ;
if ( V_317 == 0 )
return;
V_318 = V_171 / V_317 ;
switch ( V_319 ) {
case V_321 :
if ( V_318 > 10 )
V_319 = V_322 ;
break;
case V_322 :
if ( V_318 > 20 )
V_319 = V_323 ;
else if ( V_318 <= 10 )
V_319 = V_321 ;
break;
case V_323 :
if ( V_318 <= 20 )
V_319 = V_322 ;
break;
}
V_316 -> V_160 = 0 ;
V_316 -> V_161 = 0 ;
V_316 -> V_320 = V_319 ;
}
void F_201 ( struct V_158 * V_159 )
{
struct V_1 * V_2 = V_159 -> V_2 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_305 = V_159 -> V_305 ;
T_1 V_324 = V_159 -> V_320 & V_325 ;
switch ( V_2 -> V_14 . V_109 . type ) {
case V_110 :
V_324 |= ( V_324 << 16 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_324 |= V_326 ;
break;
default:
break;
}
F_71 ( V_14 , F_202 ( V_305 ) , V_324 ) ;
}
static void F_204 ( struct V_158 * V_159 )
{
T_1 V_327 = V_159 -> V_320 ;
T_4 V_328 ;
F_203 ( V_159 , & V_159 -> V_163 ) ;
F_203 ( V_159 , & V_159 -> V_298 ) ;
V_328 = F_205 ( V_159 -> V_298 . V_320 , V_159 -> V_163 . V_320 ) ;
switch ( V_328 ) {
case V_321 :
V_327 = V_329 ;
break;
case V_322 :
V_327 = V_330 ;
break;
case V_323 :
V_327 = V_331 ;
break;
default:
break;
}
if ( V_327 != V_159 -> V_320 ) {
V_327 = ( 10 * V_327 * V_159 -> V_320 ) /
( ( 9 * V_327 ) + V_159 -> V_320 ) ;
V_159 -> V_320 = V_327 ;
F_201 ( V_159 ) ;
}
}
static void F_206 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_332 = V_2 -> V_333 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
if ( ! ( V_2 -> V_155 & V_334 ) &&
! ( V_2 -> V_155 & V_335 ) )
return;
V_2 -> V_155 &= ~ V_335 ;
switch ( V_14 -> V_21 ) {
case V_336 :
if ( ! ( V_332 & V_337 ) &&
! ( V_332 & V_338 ) )
return;
if ( ! ( V_332 & V_338 ) && V_14 -> V_109 . V_339 . V_340 ) {
T_1 V_20 ;
bool V_341 = false ;
V_14 -> V_109 . V_339 . V_340 ( V_14 , & V_20 , & V_341 , false ) ;
if ( V_341 )
return;
}
if ( V_14 -> V_342 . V_339 . V_343 ( V_14 ) != V_344 )
return;
break;
default:
if ( V_2 -> V_14 . V_109 . type >= V_113 )
return;
if ( ! ( V_332 & F_207 ( V_14 ) ) )
return;
break;
}
F_208 ( V_157 , L_70 , V_345 ) ;
V_2 -> V_333 = 0 ;
}
static void F_209 ( struct V_1 * V_2 , T_1 V_332 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ( V_2 -> V_140 & V_346 ) &&
( V_332 & F_210 ( V_14 ) ) ) {
F_208 ( V_173 , L_71 ) ;
F_71 ( V_14 , V_347 , F_210 ( V_14 ) ) ;
}
}
static void F_211 ( struct V_1 * V_2 , T_1 V_332 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! ( V_2 -> V_155 & V_334 ) )
return;
switch ( V_2 -> V_14 . V_109 . type ) {
case V_112 :
if ( ( ( V_332 & F_207 ( V_14 ) ) ||
( V_332 & V_338 ) ) &&
( ! F_14 ( V_34 , & V_2 -> V_35 ) ) ) {
V_2 -> V_333 = V_332 ;
V_2 -> V_155 |= V_335 ;
F_13 ( V_2 ) ;
return;
}
return;
case V_113 :
if ( ! ( V_332 & V_348 ) )
return;
break;
default:
return;
}
F_208 ( V_157 , L_70 , V_345 ) ;
}
static inline bool F_212 ( struct V_15 * V_14 )
{
switch ( V_14 -> V_109 . type ) {
case V_110 :
if ( V_14 -> V_342 . type == V_349 )
return true ;
return false ;
case V_112 :
case V_115 :
switch ( V_14 -> V_109 . V_339 . V_350 ( V_14 ) ) {
case V_351 :
case V_352 :
return true ;
default:
return false ;
}
default:
return false ;
}
}
static void F_213 ( struct V_1 * V_2 , T_1 V_332 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_332 & F_214 ( V_14 ) ) {
F_71 ( V_14 , V_347 , F_214 ( V_14 ) ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_155 |= V_353 ;
F_13 ( V_2 ) ;
}
}
if ( V_332 & F_210 ( V_14 ) ) {
F_71 ( V_14 , V_347 , F_210 ( V_14 ) ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_140 |= V_354 ;
F_13 ( V_2 ) ;
}
}
}
static void F_215 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_355 ++ ;
V_2 -> V_140 |= V_356 ;
V_2 -> V_357 = V_172 ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_71 ( V_14 , V_358 , V_359 ) ;
F_216 ( V_14 ) ;
F_13 ( V_2 ) ;
}
}
static inline void F_217 ( struct V_1 * V_2 ,
T_6 V_117 )
{
T_1 V_118 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
V_118 = ( V_119 & V_117 ) ;
F_71 ( V_14 , V_360 , V_118 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_118 = ( V_117 & 0xFFFFFFFF ) ;
if ( V_118 )
F_71 ( V_14 , F_218 ( 0 ) , V_118 ) ;
V_118 = ( V_117 >> 32 ) ;
if ( V_118 )
F_71 ( V_14 , F_218 ( 1 ) , V_118 ) ;
break;
default:
break;
}
}
static inline void F_219 ( struct V_1 * V_2 ,
T_6 V_117 )
{
T_1 V_118 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
V_118 = ( V_119 & V_117 ) ;
F_71 ( V_14 , V_358 , V_118 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_118 = ( V_117 & 0xFFFFFFFF ) ;
if ( V_118 )
F_71 ( V_14 , F_220 ( 0 ) , V_118 ) ;
V_118 = ( V_117 >> 32 ) ;
if ( V_118 )
F_71 ( V_14 , F_220 ( 1 ) , V_118 ) ;
break;
default:
break;
}
}
static inline void F_221 ( struct V_1 * V_2 , bool V_361 ,
bool V_362 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_118 = ( V_310 & ~ V_119 ) ;
if ( V_2 -> V_140 & V_356 )
V_118 &= ~ V_313 ;
if ( V_2 -> V_155 & V_334 )
switch ( V_2 -> V_14 . V_109 . type ) {
case V_112 :
V_118 |= F_222 ( V_14 ) ;
break;
case V_113 :
case V_114 :
case V_115 :
V_118 |= V_363 ;
break;
default:
break;
}
if ( V_2 -> V_140 & V_346 )
V_118 |= F_223 ( V_14 ) ;
switch ( V_2 -> V_14 . V_109 . type ) {
case V_112 :
V_118 |= F_223 ( V_14 ) ;
V_118 |= F_224 ( V_14 ) ;
case V_113 :
case V_114 :
case V_115 :
if ( V_2 -> V_14 . V_342 . type == V_364 )
V_118 |= V_365 ;
V_118 |= V_366 ;
V_118 |= V_312 ;
break;
default:
break;
}
if ( ( V_2 -> V_140 & V_367 ) &&
! ( V_2 -> V_155 & V_368 ) )
V_118 |= V_369 ;
F_71 ( & V_2 -> V_14 , V_360 , V_118 ) ;
if ( V_361 )
F_217 ( V_2 , ~ 0 ) ;
if ( V_362 )
F_216 ( & V_2 -> V_14 ) ;
}
static T_11 F_225 ( int V_370 , void * V_93 )
{
struct V_1 * V_2 = V_93 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_332 ;
V_332 = F_37 ( V_14 , V_120 ) ;
V_332 &= 0xFFFF0000 ;
F_71 ( V_14 , V_347 , V_332 ) ;
if ( V_332 & V_338 )
F_215 ( V_2 ) ;
if ( V_332 & V_371 )
F_226 ( V_2 ) ;
switch ( V_14 -> V_109 . type ) {
case V_112 :
case V_113 :
case V_114 :
case V_115 :
if ( V_14 -> V_342 . type == V_364 &&
( V_332 & V_365 ) ) {
V_2 -> V_155 |= V_372 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_347 ,
V_365 ) ;
}
if ( V_332 & V_373 ) {
F_105 ( V_374 , L_72 ) ;
V_2 -> V_155 |= V_156 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_347 , V_373 ) ;
}
if ( V_332 & V_375 ) {
int V_376 = 0 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ ) {
struct V_58 * V_121 = V_2 -> V_59 [ V_49 ] ;
if ( F_227 ( V_377 ,
& V_121 -> V_35 ) )
V_376 ++ ;
}
if ( V_376 ) {
F_71 ( V_14 , V_358 , V_378 ) ;
V_2 -> V_155 |= V_368 ;
F_13 ( V_2 ) ;
}
}
F_213 ( V_2 , V_332 ) ;
F_211 ( V_2 , V_332 ) ;
break;
default:
break;
}
F_209 ( V_2 , V_332 ) ;
if ( F_24 ( V_332 & V_379 ) )
F_228 ( V_2 , V_332 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_221 ( V_2 , false , false ) ;
return V_380 ;
}
static T_11 F_229 ( int V_370 , void * V_93 )
{
struct V_158 * V_159 = V_93 ;
if ( V_159 -> V_298 . V_121 || V_159 -> V_163 . V_121 )
F_230 ( & V_159 -> V_254 ) ;
return V_380 ;
}
int F_231 ( struct V_299 * V_254 , int V_162 )
{
struct V_158 * V_159 =
F_196 ( V_254 , struct V_158 , V_254 ) ;
struct V_1 * V_2 = V_159 -> V_2 ;
struct V_58 * V_121 ;
int V_381 ;
bool V_382 = true ;
#ifdef F_232
if ( V_2 -> V_140 & V_188 )
F_119 ( V_159 ) ;
#endif
F_121 (ring, q_vector->tx)
V_382 &= ! ! F_94 ( V_159 , V_121 ) ;
if ( ! F_233 ( V_159 ) )
return V_162 ;
if ( V_159 -> V_298 . V_89 > 1 )
V_381 = F_205 ( V_162 / V_159 -> V_298 . V_89 , 1 ) ;
else
V_381 = V_162 ;
F_121 (ring, q_vector->rx)
V_382 &= ( F_191 ( V_159 , V_121 ,
V_381 ) < V_381 ) ;
F_234 ( V_159 ) ;
if ( ! V_382 )
return V_162 ;
F_235 ( V_254 ) ;
if ( V_2 -> V_383 & 1 )
F_204 ( V_159 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_217 ( V_2 , ( ( T_6 ) 1 << V_159 -> V_305 ) ) ;
return 0 ;
}
static int F_236 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_56 ;
int V_384 , V_17 ;
int V_385 = 0 , V_386 = 0 ;
for ( V_384 = 0 ; V_384 < V_2 -> V_190 ; V_384 ++ ) {
struct V_158 * V_159 = V_2 -> V_159 [ V_384 ] ;
struct V_387 * V_388 = & V_2 -> V_389 [ V_384 ] ;
if ( V_159 -> V_163 . V_121 && V_159 -> V_298 . V_121 ) {
snprintf ( V_159 -> V_54 , sizeof( V_159 -> V_54 ) - 1 ,
L_73 , V_56 -> V_54 , L_74 , V_385 ++ ) ;
V_386 ++ ;
} else if ( V_159 -> V_298 . V_121 ) {
snprintf ( V_159 -> V_54 , sizeof( V_159 -> V_54 ) - 1 ,
L_73 , V_56 -> V_54 , L_75 , V_385 ++ ) ;
} else if ( V_159 -> V_163 . V_121 ) {
snprintf ( V_159 -> V_54 , sizeof( V_159 -> V_54 ) - 1 ,
L_73 , V_56 -> V_54 , L_76 , V_386 ++ ) ;
} else {
continue;
}
V_17 = F_237 ( V_388 -> V_384 , & F_229 , 0 ,
V_159 -> V_54 , V_159 ) ;
if ( V_17 ) {
F_103 ( V_173 , L_77
L_78 , V_17 ) ;
goto V_390;
}
if ( V_2 -> V_140 & V_367 ) {
F_238 ( V_388 -> V_384 ,
& V_159 -> V_391 ) ;
}
}
V_17 = F_237 ( V_2 -> V_389 [ V_384 ] . V_384 ,
F_225 , 0 , V_56 -> V_54 , V_2 ) ;
if ( V_17 ) {
F_103 ( V_173 , L_79 , V_17 ) ;
goto V_390;
}
return 0 ;
V_390:
while ( V_384 ) {
V_384 -- ;
F_238 ( V_2 -> V_389 [ V_384 ] . V_384 ,
NULL ) ;
F_239 ( V_2 -> V_389 [ V_384 ] . V_384 ,
V_2 -> V_159 [ V_384 ] ) ;
}
V_2 -> V_140 &= ~ V_392 ;
F_240 ( V_2 -> V_9 ) ;
F_241 ( V_2 -> V_389 ) ;
V_2 -> V_389 = NULL ;
return V_17 ;
}
static T_11 F_242 ( int V_370 , void * V_93 )
{
struct V_1 * V_2 = V_93 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_158 * V_159 = V_2 -> V_159 [ 0 ] ;
T_1 V_332 ;
F_71 ( V_14 , V_358 , V_393 ) ;
V_332 = F_37 ( V_14 , V_347 ) ;
if ( ! V_332 ) {
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_221 ( V_2 , true , true ) ;
return V_394 ;
}
if ( V_332 & V_338 )
F_215 ( V_2 ) ;
switch ( V_14 -> V_109 . type ) {
case V_112 :
F_213 ( V_2 , V_332 ) ;
case V_113 :
case V_114 :
case V_115 :
if ( V_332 & V_373 ) {
F_105 ( V_374 , L_72 ) ;
V_2 -> V_155 |= V_156 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_347 , V_373 ) ;
}
F_211 ( V_2 , V_332 ) ;
break;
default:
break;
}
F_209 ( V_2 , V_332 ) ;
if ( F_24 ( V_332 & V_379 ) )
F_228 ( V_2 , V_332 ) ;
F_230 ( & V_159 -> V_254 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_221 ( V_2 , false , false ) ;
return V_380 ;
}
static int F_243 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_56 ;
int V_17 ;
if ( V_2 -> V_140 & V_392 )
V_17 = F_236 ( V_2 ) ;
else if ( V_2 -> V_140 & V_395 )
V_17 = F_237 ( V_2 -> V_9 -> V_370 , F_242 , 0 ,
V_56 -> V_54 , V_2 ) ;
else
V_17 = F_237 ( V_2 -> V_9 -> V_370 , F_242 , V_396 ,
V_56 -> V_54 , V_2 ) ;
if ( V_17 )
F_103 ( V_173 , L_80 , V_17 ) ;
return V_17 ;
}
static void F_244 ( struct V_1 * V_2 )
{
int V_384 ;
if ( ! ( V_2 -> V_140 & V_392 ) ) {
F_239 ( V_2 -> V_9 -> V_370 , V_2 ) ;
return;
}
for ( V_384 = 0 ; V_384 < V_2 -> V_190 ; V_384 ++ ) {
struct V_158 * V_159 = V_2 -> V_159 [ V_384 ] ;
struct V_387 * V_388 = & V_2 -> V_389 [ V_384 ] ;
if ( ! V_159 -> V_298 . V_121 && ! V_159 -> V_163 . V_121 )
continue;
F_238 ( V_388 -> V_384 , NULL ) ;
F_239 ( V_388 -> V_384 , V_159 ) ;
}
F_239 ( V_2 -> V_389 [ V_384 ++ ] . V_384 , V_2 ) ;
}
static inline void F_245 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_109 . type ) {
case V_110 :
F_71 ( & V_2 -> V_14 , V_358 , ~ 0 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
F_71 ( & V_2 -> V_14 , V_358 , 0xFFFF0000 ) ;
F_71 ( & V_2 -> V_14 , F_220 ( 0 ) , ~ 0 ) ;
F_71 ( & V_2 -> V_14 , F_220 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_216 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_140 & V_392 ) {
int V_384 ;
for ( V_384 = 0 ; V_384 < V_2 -> V_190 ; V_384 ++ )
F_246 ( V_2 -> V_389 [ V_384 ] . V_384 ) ;
F_246 ( V_2 -> V_389 [ V_384 ++ ] . V_384 ) ;
} else {
F_246 ( V_2 -> V_9 -> V_370 ) ;
}
}
static void F_247 ( struct V_1 * V_2 )
{
struct V_158 * V_159 = V_2 -> V_159 [ 0 ] ;
F_201 ( V_159 ) ;
F_73 ( V_2 , 0 , 0 , 0 ) ;
F_73 ( V_2 , 1 , 0 , 0 ) ;
F_105 ( V_14 , L_81 ) ;
}
void F_248 ( struct V_1 * V_2 ,
struct V_58 * V_121 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_397 = V_121 -> V_82 ;
int V_398 = 10 ;
T_1 V_399 = V_400 ;
T_4 V_150 = V_121 -> V_150 ;
F_71 ( V_14 , F_50 ( V_150 ) , 0 ) ;
F_216 ( V_14 ) ;
F_71 ( V_14 , F_45 ( V_150 ) ,
( V_397 & F_249 ( 32 ) ) ) ;
F_71 ( V_14 , F_46 ( V_150 ) , ( V_397 >> 32 ) ) ;
F_71 ( V_14 , F_47 ( V_150 ) ,
V_121 -> V_89 * sizeof( union V_62 ) ) ;
F_71 ( V_14 , F_48 ( V_150 ) , 0 ) ;
F_71 ( V_14 , F_49 ( V_150 ) , 0 ) ;
V_121 -> V_147 = V_2 -> V_401 + F_49 ( V_150 ) ;
if ( ! V_121 -> V_159 || ( V_121 -> V_159 -> V_320 < V_329 ) )
V_399 |= ( 1 << 16 ) ;
else
V_399 |= ( 8 << 16 ) ;
V_399 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_140 & V_367 ) {
V_121 -> V_402 = V_2 -> V_402 ;
V_121 -> V_403 = 0 ;
F_250 ( V_377 , & V_121 -> V_35 ) ;
} else {
V_121 -> V_402 = 0 ;
}
if ( ! F_15 ( V_404 , & V_121 -> V_35 ) ) {
struct V_158 * V_159 = V_121 -> V_159 ;
if ( V_159 )
F_251 ( V_121 -> V_56 ,
& V_159 -> V_391 ,
V_121 -> V_87 ) ;
}
F_34 ( V_133 , & V_121 -> V_35 ) ;
F_71 ( V_14 , F_50 ( V_150 ) , V_399 ) ;
if ( V_14 -> V_109 . type == V_110 &&
! ( F_37 ( V_14 , V_405 ) & V_406 ) )
return;
do {
F_252 ( 1000 , 2000 ) ;
V_399 = F_37 ( V_14 , F_50 ( V_150 ) ) ;
} while ( -- V_398 && ! ( V_399 & V_400 ) );
if ( ! V_398 )
F_103 ( V_157 , L_82 , V_150 ) ;
}
static void F_253 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_407 , V_408 ;
T_4 V_409 = F_254 ( V_2 -> V_56 ) ;
if ( V_14 -> V_109 . type == V_110 )
return;
V_407 = F_37 ( V_14 , V_410 ) ;
V_407 |= V_411 ;
F_71 ( V_14 , V_410 , V_407 ) ;
if ( V_2 -> V_140 & V_412 ) {
V_408 = V_413 ;
if ( V_409 > 4 )
V_408 |= V_414 | V_415 ;
else if ( V_409 > 1 )
V_408 |= V_414 | V_416 ;
else if ( V_2 -> V_417 [ V_418 ] . V_419 == 4 )
V_408 |= V_420 ;
else
V_408 |= V_421 ;
} else {
if ( V_409 > 4 )
V_408 = V_414 | V_415 ;
else if ( V_409 > 1 )
V_408 = V_414 | V_416 ;
else
V_408 = V_422 ;
}
F_71 ( V_14 , V_423 , V_408 ) ;
if ( V_409 ) {
T_1 V_424 = F_37 ( V_14 , V_425 ) ;
V_424 |= V_426 ;
F_71 ( V_14 , V_425 , V_424 ) ;
}
V_407 &= ~ V_411 ;
F_71 ( V_14 , V_410 , V_407 ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_427 ;
T_1 V_49 ;
F_253 ( V_2 ) ;
if ( V_14 -> V_109 . type != V_110 ) {
V_427 = F_37 ( V_14 , V_428 ) ;
V_427 |= V_429 ;
F_71 ( V_14 , V_428 , V_427 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ )
F_248 ( V_2 , V_2 -> V_59 [ V_49 ] ) ;
}
static void F_256 ( struct V_1 * V_2 ,
struct V_58 * V_121 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_150 = V_121 -> V_150 ;
T_1 V_430 = F_37 ( V_14 , F_36 ( V_150 ) ) ;
V_430 |= V_431 ;
F_71 ( V_14 , F_36 ( V_150 ) , V_430 ) ;
}
static void F_257 ( struct V_1 * V_2 ,
struct V_58 * V_121 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_150 = V_121 -> V_150 ;
T_1 V_430 = F_37 ( V_14 , F_36 ( V_150 ) ) ;
V_430 &= ~ V_431 ;
F_71 ( V_14 , F_36 ( V_150 ) , V_430 ) ;
}
static void F_258 ( struct V_1 * V_2 ,
struct V_58 * V_68 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_430 ;
T_4 V_150 = V_68 -> V_150 ;
if ( V_14 -> V_109 . type == V_110 ) {
T_2 V_118 = V_2 -> V_417 [ V_418 ] . V_118 ;
V_150 &= V_118 ;
}
V_430 = V_269 << V_432 ;
V_430 |= F_69 ( V_68 ) >> V_433 ;
V_430 |= V_434 ;
F_71 ( V_14 , F_36 ( V_150 ) , V_430 ) ;
}
T_1 F_259 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_109 . type < V_114 )
return 128 ;
else if ( V_2 -> V_140 & V_412 )
return 64 ;
else
return 512 ;
}
void F_260 ( struct V_1 * V_2 )
{
T_1 V_49 , V_435 = F_259 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_436 = 0 ;
T_1 V_437 ;
T_4 * V_438 = V_2 -> V_439 ;
if ( V_2 -> V_14 . V_109 . type == V_110 )
V_437 = 0x11 ;
else
V_437 = 0x1 ;
for ( V_49 = 0 ; V_49 < V_435 ; V_49 ++ ) {
V_436 |= V_437 * V_438 [ V_49 ] << ( V_49 & 0x3 ) * 8 ;
if ( ( V_49 & 3 ) == 3 ) {
if ( V_49 < 128 )
F_71 ( V_14 , F_261 ( V_49 >> 2 ) , V_436 ) ;
else
F_71 ( V_14 , F_262 ( ( V_49 >> 2 ) - 32 ) ,
V_436 ) ;
V_436 = 0 ;
}
}
}
static void F_263 ( struct V_1 * V_2 )
{
T_1 V_49 , V_435 = F_259 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_440 = 0 ;
unsigned int V_441 = V_2 -> V_306 ;
for ( V_49 = 0 ; V_49 < V_435 ; V_49 ++ ) {
V_440 |= ( T_1 ) V_2 -> V_439 [ V_49 ] << ( V_49 & 0x3 ) * 8 ;
if ( ( V_49 & 3 ) == 3 ) {
F_71 ( V_14 , F_264 ( V_49 >> 2 , V_441 ) ,
V_440 ) ;
V_440 = 0 ;
}
}
}
static void F_265 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_49 , V_50 ;
T_1 V_435 = F_259 ( V_2 ) ;
T_2 V_442 = V_2 -> V_417 [ V_418 ] . V_419 ;
if ( ( V_2 -> V_140 & V_412 ) && ( V_442 < 2 ) )
V_442 = 2 ;
for ( V_49 = 0 ; V_49 < 10 ; V_49 ++ )
F_71 ( V_14 , F_266 ( V_49 ) , V_2 -> V_443 [ V_49 ] ) ;
memset ( V_2 -> V_439 , 0 , sizeof( V_2 -> V_439 ) ) ;
for ( V_49 = 0 , V_50 = 0 ; V_49 < V_435 ; V_49 ++ , V_50 ++ ) {
if ( V_50 == V_442 )
V_50 = 0 ;
V_2 -> V_439 [ V_49 ] = V_50 ;
}
F_260 ( V_2 ) ;
}
static void F_267 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_442 = V_2 -> V_417 [ V_418 ] . V_419 ;
unsigned int V_441 = V_2 -> V_306 ;
int V_49 , V_50 ;
for ( V_49 = 0 ; V_49 < 10 ; V_49 ++ )
F_71 ( V_14 , F_268 ( V_49 , V_441 ) ,
V_2 -> V_443 [ V_49 ] ) ;
for ( V_49 = 0 , V_50 = 0 ; V_49 < 64 ; V_49 ++ , V_50 ++ ) {
if ( V_50 == V_442 )
V_50 = 0 ;
V_2 -> V_439 [ V_49 ] = V_50 ;
}
F_263 ( V_2 ) ;
}
static void F_269 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_444 = 0 , V_445 = 0 , V_446 = 0 ;
T_1 V_447 ;
V_447 = F_37 ( V_14 , V_448 ) ;
V_447 |= V_449 ;
F_71 ( V_14 , V_448 , V_447 ) ;
if ( V_2 -> V_14 . V_109 . type == V_110 ) {
if ( V_2 -> V_417 [ V_418 ] . V_118 )
V_444 = V_450 ;
} else {
T_4 V_409 = F_254 ( V_2 -> V_56 ) ;
if ( V_2 -> V_140 & V_412 ) {
if ( V_409 > 4 )
V_444 = V_451 ;
else if ( V_409 > 1 )
V_444 = V_452 ;
else if ( V_2 -> V_417 [ V_418 ] . V_419 == 4 )
V_444 = V_453 ;
else
V_444 = V_454 ;
} else {
if ( V_409 > 4 )
V_444 = V_455 ;
else if ( V_409 > 1 )
V_444 = V_456 ;
else
V_444 = V_450 ;
}
}
V_445 |= V_457 |
V_458 |
V_459 |
V_460 ;
if ( V_2 -> V_155 & V_461 )
V_445 |= V_462 ;
if ( V_2 -> V_155 & V_463 )
V_445 |= V_464 ;
F_270 ( V_2 -> V_443 , sizeof( V_2 -> V_443 ) ) ;
if ( ( V_14 -> V_109 . type >= V_114 ) &&
( V_2 -> V_140 & V_412 ) ) {
unsigned int V_441 = V_2 -> V_306 ;
V_444 |= V_465 ;
F_71 ( V_14 , V_466 , V_444 ) ;
F_267 ( V_2 ) ;
V_446 = V_450 ;
V_446 |= V_445 ;
F_71 ( V_14 , F_271 ( V_441 ) , V_446 ) ;
} else {
F_265 ( V_2 ) ;
V_444 |= V_445 ;
F_71 ( V_14 , V_466 , V_444 ) ;
}
}
static void F_272 ( struct V_1 * V_2 ,
struct V_58 * V_121 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_467 ;
T_4 V_150 = V_121 -> V_150 ;
if ( ! F_164 ( V_121 ) )
return;
V_467 = F_37 ( V_14 , F_273 ( V_150 ) ) ;
V_467 |= V_468 ;
V_467 |= V_469 ;
F_71 ( V_14 , F_273 ( V_150 ) , V_467 ) ;
}
static void F_274 ( struct V_1 * V_2 ,
struct V_58 * V_121 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_398 = V_470 ;
T_1 V_471 ;
T_4 V_150 = V_121 -> V_150 ;
if ( F_22 ( V_14 -> V_40 ) )
return;
if ( V_14 -> V_109 . type == V_110 &&
! ( F_37 ( V_14 , V_405 ) & V_406 ) )
return;
do {
F_252 ( 1000 , 2000 ) ;
V_471 = F_37 ( V_14 , F_42 ( V_150 ) ) ;
} while ( -- V_398 && ! ( V_471 & V_472 ) );
if ( ! V_398 ) {
F_103 ( V_157 , L_83
L_84 , V_150 ) ;
}
}
void F_275 ( struct V_1 * V_2 ,
struct V_58 * V_121 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_398 = V_470 ;
T_1 V_471 ;
T_4 V_150 = V_121 -> V_150 ;
if ( F_22 ( V_14 -> V_40 ) )
return;
V_471 = F_37 ( V_14 , F_42 ( V_150 ) ) ;
V_471 &= ~ V_472 ;
F_71 ( V_14 , F_42 ( V_150 ) , V_471 ) ;
if ( V_14 -> V_109 . type == V_110 &&
! ( F_37 ( V_14 , V_405 ) & V_406 ) )
return;
do {
F_276 ( 10 ) ;
V_471 = F_37 ( V_14 , F_42 ( V_150 ) ) ;
} while ( -- V_398 && ( V_471 & V_472 ) );
if ( ! V_398 ) {
F_103 ( V_157 , L_85
L_84 , V_150 ) ;
}
}
void F_277 ( struct V_1 * V_2 ,
struct V_58 * V_121 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_473 = V_121 -> V_82 ;
T_1 V_471 ;
T_4 V_150 = V_121 -> V_150 ;
V_471 = F_37 ( V_14 , F_42 ( V_150 ) ) ;
F_275 ( V_2 , V_121 ) ;
F_71 ( V_14 , F_43 ( V_150 ) , ( V_473 & F_249 ( 32 ) ) ) ;
F_71 ( V_14 , F_44 ( V_150 ) , ( V_473 >> 32 ) ) ;
F_71 ( V_14 , F_39 ( V_150 ) ,
V_121 -> V_89 * sizeof( union V_69 ) ) ;
F_71 ( V_14 , F_40 ( V_150 ) , 0 ) ;
F_71 ( V_14 , F_41 ( V_150 ) , 0 ) ;
V_121 -> V_147 = V_2 -> V_401 + F_41 ( V_150 ) ;
F_258 ( V_2 , V_121 ) ;
F_272 ( V_2 , V_121 ) ;
if ( V_14 -> V_109 . type == V_110 ) {
V_471 &= ~ 0x3FFFFF ;
V_471 |= 0x080420 ;
}
V_471 |= V_472 ;
F_71 ( V_14 , F_42 ( V_150 ) , V_471 ) ;
F_274 ( V_2 , V_121 ) ;
F_143 ( V_121 , F_110 ( V_121 ) ) ;
}
static void F_278 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_442 = V_2 -> V_417 [ V_418 ] . V_419 ;
T_2 V_474 ;
T_1 V_475 = V_476 |
V_477 |
V_478 |
V_479 |
V_480 ;
if ( V_14 -> V_109 . type == V_110 )
return;
if ( V_442 > 3 )
V_475 |= 2 << 29 ;
else if ( V_442 > 1 )
V_475 |= 1 << 29 ;
F_279 (pool, &adapter->fwd_bitmask, 32 )
F_71 ( V_14 , F_280 ( F_281 ( V_474 ) ) , V_475 ) ;
}
static void F_282 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_178 , V_481 ;
T_1 V_482 , V_483 ;
int V_49 ;
if ( ! ( V_2 -> V_140 & V_412 ) )
return;
V_483 = F_37 ( V_14 , V_484 ) ;
V_483 |= V_485 ;
V_483 &= ~ V_486 ;
V_483 |= F_281 ( 0 ) << V_487 ;
V_483 |= V_488 ;
F_71 ( V_14 , V_484 , V_483 ) ;
V_481 = F_281 ( 0 ) % 32 ;
V_178 = ( F_281 ( 0 ) >= 32 ) ? 1 : 0 ;
F_71 ( V_14 , F_283 ( V_178 ) , ( ~ 0 ) << V_481 ) ;
F_71 ( V_14 , F_283 ( V_178 ^ 1 ) , V_178 - 1 ) ;
F_71 ( V_14 , F_284 ( V_178 ) , ( ~ 0 ) << V_481 ) ;
F_71 ( V_14 , F_284 ( V_178 ^ 1 ) , V_178 - 1 ) ;
if ( V_2 -> V_489 == V_490 )
F_71 ( V_14 , V_491 , V_492 ) ;
V_14 -> V_109 . V_339 . V_493 ( V_14 , 0 , F_281 ( 0 ) ) ;
switch ( V_2 -> V_417 [ V_494 ] . V_118 ) {
case V_495 :
V_482 = V_496 ;
break;
case V_497 :
V_482 = V_498 ;
break;
default:
V_482 = V_499 ;
break;
}
F_71 ( V_14 , V_500 , V_482 ) ;
V_14 -> V_109 . V_339 . V_501 ( V_14 , ( V_2 -> V_306 != 0 ) ,
V_2 -> V_306 ) ;
if ( V_14 -> V_109 . V_339 . V_502 )
F_71 ( V_14 , F_285 ( V_503 ) ,
( V_504 |
V_505 |
V_506 ) ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_306 ; V_49 ++ ) {
if ( ! V_2 -> V_507 [ V_49 ] . V_508 )
F_286 ( V_2 -> V_56 , V_49 , false ) ;
if ( V_14 -> V_109 . V_339 . V_502 )
V_14 -> V_109 . V_339 . V_502 ( V_14 , true , V_49 ) ;
F_287 ( V_2 -> V_56 , V_49 ,
V_2 -> V_507 [ V_49 ] . V_509 ) ;
}
}
static void F_288 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_55 * V_56 = V_2 -> V_56 ;
int V_510 = V_56 -> V_294 + V_511 + V_512 ;
struct V_58 * V_68 ;
int V_49 ;
T_1 V_513 , V_514 ;
#ifdef F_175
if ( ( V_2 -> V_140 & V_515 ) &&
( V_510 < V_516 ) )
V_510 = V_516 ;
#endif
if ( V_510 < ( V_517 + V_512 ) )
V_510 = ( V_517 + V_512 ) ;
V_513 = F_37 ( V_14 , V_518 ) ;
if ( V_510 != ( V_513 >> V_519 ) ) {
V_513 &= ~ V_520 ;
V_513 |= V_510 << V_519 ;
F_71 ( V_14 , V_518 , V_513 ) ;
}
V_514 = F_37 ( V_14 , V_521 ) ;
V_514 |= V_522 ;
F_71 ( V_14 , V_521 , V_514 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_94 ; V_49 ++ ) {
V_68 = V_2 -> V_68 [ V_49 ] ;
if ( V_2 -> V_155 & V_523 )
F_289 ( V_68 ) ;
else
F_290 ( V_68 ) ;
}
}
static void F_291 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_524 = F_37 ( V_14 , V_525 ) ;
switch ( V_14 -> V_109 . type ) {
case V_114 :
case V_115 :
case V_110 :
V_524 |= V_526 ;
break;
case V_112 :
case V_113 :
F_71 ( V_14 , V_527 ,
( V_528 | F_37 ( V_14 , V_527 ) ) ) ;
V_524 &= ~ V_529 ;
V_524 |= ( V_530 | V_531 ) ;
V_524 |= V_532 ;
break;
default:
return;
}
F_71 ( V_14 , V_525 , V_524 ) ;
}
static void F_292 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
T_1 V_183 , V_533 ;
V_14 -> V_109 . V_339 . V_534 ( V_14 ) ;
F_278 ( V_2 ) ;
F_291 ( V_2 ) ;
V_533 = F_37 ( V_14 , V_535 ) ;
V_533 &= ~ V_536 ;
if ( ! ( V_2 -> V_155 & V_523 ) )
V_533 |= V_536 ;
F_71 ( V_14 , V_535 , V_533 ) ;
F_269 ( V_2 ) ;
F_288 ( V_2 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_94 ; V_49 ++ )
F_277 ( V_2 , V_2 -> V_68 [ V_49 ] ) ;
V_183 = F_37 ( V_14 , V_537 ) ;
if ( V_14 -> V_109 . type == V_110 )
V_183 |= V_538 ;
V_183 |= V_539 ;
V_14 -> V_109 . V_339 . V_540 ( V_14 , V_183 ) ;
}
static int F_293 ( struct V_55 * V_56 ,
T_12 V_541 , T_2 V_250 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_109 . V_339 . V_542 ( & V_2 -> V_14 , V_250 , F_281 ( 0 ) , true ) ;
F_250 ( V_250 , V_2 -> V_543 ) ;
return 0 ;
}
static int F_294 ( struct V_55 * V_56 ,
T_12 V_541 , T_2 V_250 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_109 . V_339 . V_542 ( & V_2 -> V_14 , V_250 , F_281 ( 0 ) , false ) ;
F_34 ( V_250 , V_2 -> V_543 ) ;
return 0 ;
}
static void F_295 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_544 ;
int V_49 , V_50 ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
V_544 = F_37 ( V_14 , V_545 ) ;
V_544 &= ~ V_546 ;
F_71 ( V_14 , V_545 , V_544 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
for ( V_49 = 0 ; V_49 < V_2 -> V_94 ; V_49 ++ ) {
struct V_58 * V_121 = V_2 -> V_68 [ V_49 ] ;
if ( V_121 -> V_148 )
continue;
V_50 = V_121 -> V_150 ;
V_544 = F_37 ( V_14 , F_42 ( V_50 ) ) ;
V_544 &= ~ V_547 ;
F_71 ( V_14 , F_42 ( V_50 ) , V_544 ) ;
}
break;
default:
break;
}
}
static void F_296 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_544 ;
int V_49 , V_50 ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
V_544 = F_37 ( V_14 , V_545 ) ;
V_544 |= V_546 ;
F_71 ( V_14 , V_545 , V_544 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
for ( V_49 = 0 ; V_49 < V_2 -> V_94 ; V_49 ++ ) {
struct V_58 * V_121 = V_2 -> V_68 [ V_49 ] ;
if ( V_121 -> V_148 )
continue;
V_50 = V_121 -> V_150 ;
V_544 = F_37 ( V_14 , F_42 ( V_50 ) ) ;
V_544 |= V_547 ;
F_71 ( V_14 , F_42 ( V_50 ) , V_544 ) ;
}
break;
default:
break;
}
}
static void F_297 ( struct V_1 * V_2 )
{
T_2 V_250 ;
F_293 ( V_2 -> V_56 , F_156 ( V_252 ) , 0 ) ;
F_279 (vid, adapter->active_vlans, VLAN_N_VID)
F_293 ( V_2 -> V_56 , F_156 ( V_252 ) , V_250 ) ;
}
static int F_298 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! F_57 ( V_56 ) )
return 0 ;
if ( V_14 -> V_109 . V_339 . V_548 )
V_14 -> V_109 . V_339 . V_548 ( V_14 , V_56 ) ;
else
return - V_549 ;
#ifdef F_299
F_300 ( V_2 ) ;
#endif
return F_301 ( V_56 ) ;
}
void F_302 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_109 . V_550 ; V_49 ++ ) {
if ( V_2 -> V_551 [ V_49 ] . V_35 & V_552 )
V_14 -> V_109 . V_339 . V_553 ( V_14 , V_49 , V_2 -> V_551 [ V_49 ] . V_554 ,
V_2 -> V_551 [ V_49 ] . V_105 ,
V_555 ) ;
else
V_14 -> V_109 . V_339 . V_556 ( V_14 , V_49 ) ;
V_2 -> V_551 [ V_49 ] . V_35 &= ~ ( V_557 ) ;
}
}
static void F_303 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_109 . V_550 ; V_49 ++ ) {
if ( V_2 -> V_551 [ V_49 ] . V_35 & V_557 ) {
if ( V_2 -> V_551 [ V_49 ] . V_35 &
V_552 )
V_14 -> V_109 . V_339 . V_553 ( V_14 , V_49 ,
V_2 -> V_551 [ V_49 ] . V_554 ,
V_2 -> V_551 [ V_49 ] . V_105 ,
V_555 ) ;
else
V_14 -> V_109 . V_339 . V_556 ( V_14 , V_49 ) ;
V_2 -> V_551 [ V_49 ] . V_35 &=
~ ( V_557 ) ;
}
}
}
static void F_304 ( struct V_1 * V_2 )
{
int V_49 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_109 . V_550 ; V_49 ++ ) {
V_2 -> V_551 [ V_49 ] . V_35 |= V_557 ;
V_2 -> V_551 [ V_49 ] . V_35 &= ~ V_552 ;
F_305 ( V_2 -> V_551 [ V_49 ] . V_554 ) ;
V_2 -> V_551 [ V_49 ] . V_105 = 0 ;
}
F_303 ( V_2 ) ;
}
static int F_306 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 , V_89 = 0 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_109 . V_550 ; V_49 ++ ) {
if ( V_2 -> V_551 [ V_49 ] . V_35 == 0 )
V_89 ++ ;
}
return V_89 ;
}
static void F_307 ( struct V_1 * V_2 ,
T_4 * V_554 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
memcpy ( & V_2 -> V_551 [ 0 ] . V_554 , V_554 , V_558 ) ;
V_2 -> V_551 [ 0 ] . V_105 = F_281 ( 0 ) ;
V_2 -> V_551 [ 0 ] . V_35 = ( V_559 |
V_552 ) ;
V_14 -> V_109 . V_339 . V_553 ( V_14 , 0 , V_2 -> V_551 [ 0 ] . V_554 ,
V_2 -> V_551 [ 0 ] . V_105 ,
V_555 ) ;
}
int F_308 ( struct V_1 * V_2 , T_4 * V_554 , T_2 V_105 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( F_309 ( V_554 ) )
return - V_560 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_109 . V_550 ; V_49 ++ ) {
if ( V_2 -> V_551 [ V_49 ] . V_35 & V_552 )
continue;
V_2 -> V_551 [ V_49 ] . V_35 |= ( V_557 |
V_552 ) ;
F_310 ( V_2 -> V_551 [ V_49 ] . V_554 , V_554 ) ;
V_2 -> V_551 [ V_49 ] . V_105 = V_105 ;
F_303 ( V_2 ) ;
return V_49 ;
}
return - V_549 ;
}
int F_311 ( struct V_1 * V_2 , T_4 * V_554 , T_2 V_105 )
{
int V_49 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_309 ( V_554 ) )
return - V_560 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_109 . V_550 ; V_49 ++ ) {
if ( F_312 ( V_554 , V_2 -> V_551 [ V_49 ] . V_554 ) &&
V_2 -> V_551 [ V_49 ] . V_105 == V_105 ) {
V_2 -> V_551 [ V_49 ] . V_35 |= V_557 ;
V_2 -> V_551 [ V_49 ] . V_35 &= ~ V_552 ;
F_305 ( V_2 -> V_551 [ V_49 ] . V_554 ) ;
V_2 -> V_551 [ V_49 ] . V_105 = 0 ;
F_303 ( V_2 ) ;
return 0 ;
}
}
return - V_549 ;
}
static int F_313 ( struct V_55 * V_56 , int V_561 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
int V_89 = 0 ;
if ( F_314 ( V_56 ) > F_306 ( V_2 ) )
return - V_549 ;
if ( ! F_315 ( V_56 ) ) {
struct V_562 * V_563 ;
F_316 (ha, netdev) {
F_311 ( V_2 , V_563 -> V_554 , V_561 ) ;
F_308 ( V_2 , V_563 -> V_554 , V_561 ) ;
V_89 ++ ;
}
}
return V_89 ;
}
void F_317 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_564 , V_565 = V_566 | V_567 ;
T_1 V_544 ;
int V_89 ;
V_564 = F_37 ( V_14 , V_568 ) ;
V_544 = F_37 ( V_14 , V_545 ) ;
V_564 &= ~ V_569 ;
V_564 |= V_570 ;
V_564 |= V_571 ;
V_564 |= V_572 ;
V_564 &= ~ ( V_573 | V_574 ) ;
V_544 &= ~ ( V_575 | V_576 ) ;
if ( V_56 -> V_140 & V_577 ) {
V_14 -> V_578 . V_579 = true ;
V_564 |= ( V_573 | V_574 ) ;
V_565 |= V_580 ;
if ( V_2 -> V_140 & ( V_581 |
V_412 ) )
V_544 |= ( V_575 | V_576 ) ;
} else {
if ( V_56 -> V_140 & V_582 ) {
V_564 |= V_574 ;
V_565 |= V_580 ;
}
V_544 |= V_575 ;
V_14 -> V_578 . V_579 = false ;
}
V_89 = F_313 ( V_56 , F_281 ( 0 ) ) ;
if ( V_89 < 0 ) {
V_564 |= V_573 ;
V_565 |= V_583 ;
}
V_89 = F_298 ( V_56 ) ;
if ( V_89 < 0 ) {
V_564 |= V_574 ;
V_565 |= V_580 ;
} else if ( V_89 ) {
V_565 |= V_584 ;
}
if ( V_14 -> V_109 . type != V_110 ) {
V_565 |= F_37 ( V_14 , F_318 ( F_281 ( 0 ) ) ) &
~ ( V_580 | V_584 |
V_583 ) ;
F_71 ( V_14 , F_318 ( F_281 ( 0 ) ) , V_565 ) ;
}
if ( V_2 -> V_56 -> V_198 & V_273 ) {
V_564 |= ( V_569 |
V_570 |
V_572 ) ;
V_564 &= ~ ( V_571 ) ;
}
F_71 ( V_14 , V_545 , V_544 ) ;
F_71 ( V_14 , V_568 , V_564 ) ;
if ( V_56 -> V_198 & V_248 )
F_296 ( V_2 ) ;
else
F_295 ( V_2 ) ;
}
static void F_319 ( struct V_1 * V_2 )
{
int V_585 ;
for ( V_585 = 0 ; V_585 < V_2 -> V_190 ; V_585 ++ ) {
F_320 ( V_2 -> V_159 [ V_585 ] ) ;
F_321 ( & V_2 -> V_159 [ V_585 ] -> V_254 ) ;
}
}
static void F_322 ( struct V_1 * V_2 )
{
int V_585 ;
for ( V_585 = 0 ; V_585 < V_2 -> V_190 ; V_585 ++ ) {
F_323 ( & V_2 -> V_159 [ V_585 ] -> V_254 ) ;
while ( ! F_324 ( V_2 -> V_159 [ V_585 ] ) ) {
F_51 ( L_86 , V_585 ) ;
F_252 ( 1000 , 20000 ) ;
}
}
}
static void F_325 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_109 . type ) {
case V_114 :
case V_115 :
F_71 ( & V_2 -> V_14 , V_586 , 0 ) ;
#ifdef F_326
V_2 -> V_587 = 0 ;
#endif
break;
default:
break;
}
}
static void F_327 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_510 = V_2 -> V_56 -> V_294 + V_511 + V_512 ;
if ( ! ( V_2 -> V_140 & V_141 ) ) {
if ( V_14 -> V_109 . type == V_110 )
F_328 ( V_2 -> V_56 , 65536 ) ;
return;
}
if ( V_14 -> V_109 . type == V_110 )
F_328 ( V_2 -> V_56 , 32768 ) ;
#ifdef F_175
if ( V_2 -> V_56 -> V_198 & V_588 )
V_510 = F_205 ( V_510 , V_516 ) ;
#endif
if ( V_2 -> V_589 & V_590 ) {
F_329 ( V_14 , & V_2 -> V_137 , V_510 ,
V_591 ) ;
F_329 ( V_14 , & V_2 -> V_137 , V_510 ,
V_592 ) ;
F_330 ( V_14 , & V_2 -> V_137 ) ;
} else if ( V_2 -> V_593 && V_2 -> V_139 ) {
F_331 ( & V_2 -> V_14 ,
V_2 -> V_593 ,
V_510 ) ;
F_332 ( & V_2 -> V_14 ,
V_2 -> V_139 -> V_136 ,
V_2 -> V_593 -> V_594 ) ;
}
if ( V_14 -> V_109 . type != V_110 ) {
T_1 V_595 = 0 ;
T_2 V_442 = V_2 -> V_417 [ V_418 ] . V_419 - 1 ;
while ( V_442 ) {
V_595 ++ ;
V_442 >>= 1 ;
}
F_71 ( V_14 , V_596 , V_595 * 0x11111111 ) ;
}
}
static int F_333 ( struct V_1 * V_2 , int V_597 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_55 * V_74 = V_2 -> V_56 ;
int V_374 , V_135 , V_598 , V_599 ;
T_1 V_600 , V_601 ;
V_135 = V_374 = V_74 -> V_294 + V_511 + V_512 + V_602 ;
#ifdef F_175
if ( ( V_74 -> V_198 & V_588 ) &&
( V_135 < V_516 ) &&
( V_597 == F_334 ( V_2 ) ) )
V_135 = V_516 ;
#endif
switch ( V_14 -> V_109 . type ) {
case V_113 :
case V_114 :
case V_115 :
V_600 = F_335 ( V_374 , V_135 ) ;
break;
default:
V_600 = F_336 ( V_374 , V_135 ) ;
break;
}
if ( V_2 -> V_140 & V_412 )
V_600 += F_337 ( V_135 ) ;
V_598 = F_338 ( V_600 ) ;
V_601 = F_37 ( V_14 , F_339 ( V_597 ) ) >> 10 ;
V_599 = V_601 - V_598 ;
if ( V_599 < 0 ) {
F_93 ( V_157 , L_87
L_88
L_89 , V_597 ) ;
V_599 = V_135 + 1 ;
}
return V_599 ;
}
static int F_340 ( struct V_1 * V_2 , int V_597 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_55 * V_74 = V_2 -> V_56 ;
int V_135 ;
T_1 V_600 ;
V_135 = V_74 -> V_294 + V_511 + V_512 ;
#ifdef F_175
if ( ( V_74 -> V_198 & V_588 ) &&
( V_135 < V_516 ) &&
( V_597 == F_86 ( V_74 , V_2 -> V_603 . V_604 ) ) )
V_135 = V_516 ;
#endif
switch ( V_14 -> V_109 . type ) {
case V_113 :
case V_114 :
case V_115 :
V_600 = F_341 ( V_135 ) ;
break;
default:
V_600 = F_342 ( V_135 ) ;
break;
}
return F_338 ( V_600 ) ;
}
static void F_343 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_605 = F_254 ( V_2 -> V_56 ) ;
int V_49 ;
if ( ! V_605 )
V_605 = 1 ;
for ( V_49 = 0 ; V_49 < V_605 ; V_49 ++ ) {
V_14 -> V_126 . V_606 [ V_49 ] = F_333 ( V_2 , V_49 ) ;
V_14 -> V_126 . V_607 [ V_49 ] = F_340 ( V_2 , V_49 ) ;
if ( V_14 -> V_126 . V_607 [ V_49 ] > V_14 -> V_126 . V_606 [ V_49 ] )
V_14 -> V_126 . V_607 [ V_49 ] = 0 ;
}
for (; V_49 < V_608 ; V_49 ++ )
V_14 -> V_126 . V_606 [ V_49 ] = 0 ;
}
static void F_344 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_609 ;
T_4 V_135 = F_254 ( V_2 -> V_56 ) ;
if ( V_2 -> V_140 & V_367 ||
V_2 -> V_140 & V_610 )
V_609 = 32 << V_2 -> V_611 ;
else
V_609 = 0 ;
V_14 -> V_109 . V_339 . V_612 ( V_14 , V_135 , V_609 , V_613 ) ;
F_343 ( V_2 ) ;
}
static void F_345 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_614 * V_615 ;
struct V_616 * V_617 ;
F_346 ( & V_2 -> V_618 ) ;
if ( ! F_347 ( & V_2 -> V_619 ) )
F_348 ( V_14 , & V_2 -> V_620 ) ;
F_349 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_350 ( V_14 ,
& V_617 -> V_617 ,
V_617 -> V_621 ,
( V_617 -> V_622 == V_623 ) ?
V_623 :
V_2 -> V_68 [ V_617 -> V_622 ] -> V_150 ) ;
}
F_351 ( & V_2 -> V_618 ) ;
}
static void F_352 ( struct V_55 * V_74 , unsigned int V_474 ,
struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_565 ;
V_565 = F_37 ( V_14 , F_318 ( V_474 ) ) ;
V_565 |= ( V_584 | V_566 | V_567 ) ;
V_565 &= ~ V_580 ;
if ( V_74 -> V_140 & V_582 ) {
V_565 |= V_580 ;
} else {
V_565 |= V_584 ;
V_14 -> V_109 . V_339 . V_548 ( V_14 , V_74 ) ;
}
F_313 ( V_2 -> V_56 , V_474 ) ;
F_71 ( V_14 , F_318 ( V_474 ) , V_565 ) ;
}
static void F_353 ( struct V_624 * V_625 )
{
struct V_1 * V_2 = V_625 -> V_149 ;
int V_442 = V_2 -> V_626 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_474 = V_625 -> V_474 ;
T_1 V_475 = V_476 |
V_477 |
V_478 |
V_479 |
V_480 ;
if ( V_14 -> V_109 . type == V_110 )
return;
if ( V_442 > 3 )
V_475 |= 2 << 29 ;
else if ( V_442 > 1 )
V_475 |= 1 << 29 ;
F_71 ( V_14 , F_280 ( F_281 ( V_474 ) ) , V_475 ) ;
}
static void F_354 ( struct V_58 * V_68 )
{
struct V_191 * V_74 = V_68 -> V_74 ;
unsigned long V_278 ;
T_2 V_49 ;
if ( ! V_68 -> V_72 )
return;
for ( V_49 = 0 ; V_49 < V_68 -> V_89 ; V_49 ++ ) {
struct V_71 * V_277 = & V_68 -> V_72 [ V_49 ] ;
if ( V_277 -> V_90 ) {
struct V_196 * V_90 = V_277 -> V_90 ;
if ( F_151 ( V_90 ) -> V_271 )
F_80 ( V_74 ,
F_151 ( V_90 ) -> V_82 ,
F_69 ( V_68 ) ,
V_235 ) ;
F_355 ( V_90 ) ;
V_277 -> V_90 = NULL ;
}
if ( ! V_277 -> V_99 )
continue;
F_80 ( V_74 , V_277 -> V_82 ,
F_140 ( V_68 ) , V_235 ) ;
F_142 ( V_277 -> V_99 , F_138 ( V_68 ) ) ;
V_277 -> V_99 = NULL ;
}
V_278 = sizeof( struct V_71 ) * V_68 -> V_89 ;
memset ( V_68 -> V_72 , 0 , V_278 ) ;
memset ( V_68 -> V_88 , 0 , V_68 -> V_278 ) ;
V_68 -> V_239 = 0 ;
V_68 -> V_80 = 0 ;
V_68 -> V_81 = 0 ;
}
static void F_356 ( struct V_624 * V_625 ,
struct V_58 * V_68 )
{
struct V_1 * V_2 = V_625 -> V_149 ;
int V_108 = V_68 -> V_87 + V_625 -> V_627 ;
F_275 ( V_2 , V_68 ) ;
F_252 ( 10000 , 20000 ) ;
F_219 ( V_2 , ( ( T_6 ) 1 << V_108 ) ) ;
F_354 ( V_68 ) ;
V_68 -> V_148 = NULL ;
}
static int F_357 ( struct V_55 * V_628 ,
struct V_624 * V_629 )
{
struct V_1 * V_2 = V_629 -> V_149 ;
unsigned int V_630 = V_629 -> V_627 ;
unsigned int V_631 = V_629 -> V_632 ;
int V_49 ;
F_358 ( V_628 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_626 ; V_49 ++ ) {
F_356 ( V_629 , V_2 -> V_68 [ V_630 + V_49 ] ) ;
V_2 -> V_68 [ V_630 + V_49 ] -> V_56 = V_2 -> V_56 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_626 ; V_49 ++ ) {
V_2 -> V_59 [ V_631 + V_49 ] -> V_148 = NULL ;
V_2 -> V_59 [ V_631 + V_49 ] -> V_56 = V_2 -> V_56 ;
}
return 0 ;
}
static int F_359 ( struct V_55 * V_628 ,
struct V_624 * V_629 )
{
struct V_1 * V_2 = V_629 -> V_149 ;
unsigned int V_630 , V_631 , V_361 ;
int V_49 , V_633 , V_17 = 0 ;
if ( ! F_14 ( V_629 -> V_474 , & V_2 -> V_634 ) )
return 0 ;
V_633 = V_629 -> V_474 * V_2 -> V_626 ;
F_360 ( V_628 , L_90 ,
V_629 -> V_474 , V_2 -> V_635 ,
V_633 , V_633 + V_2 -> V_626 ,
V_2 -> V_634 ) ;
V_629 -> V_56 = V_628 ;
V_629 -> V_627 = V_630 = V_633 ;
V_629 -> V_632 = V_631 = V_633 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_626 ; V_49 ++ )
F_356 ( V_629 , V_2 -> V_68 [ V_630 + V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_626 ; V_49 ++ ) {
V_2 -> V_68 [ V_630 + V_49 ] -> V_56 = V_628 ;
V_2 -> V_68 [ V_630 + V_49 ] -> V_148 = V_629 ;
F_277 ( V_2 , V_2 -> V_68 [ V_630 + V_49 ] ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_626 ; V_49 ++ ) {
V_2 -> V_59 [ V_631 + V_49 ] -> V_56 = V_628 ;
V_2 -> V_59 [ V_631 + V_49 ] -> V_148 = V_629 ;
}
V_361 = F_361 (unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues) ;
V_17 = F_362 ( V_628 , V_361 ) ;
if ( V_17 )
goto V_636;
V_17 = F_363 ( V_628 , V_361 ) ;
if ( V_17 )
goto V_636;
if ( F_364 ( V_628 -> V_637 ) )
F_308 ( V_2 , V_628 -> V_637 , V_629 -> V_474 ) ;
F_353 ( V_629 ) ;
F_352 ( V_628 , V_629 -> V_474 , V_2 ) ;
return V_17 ;
V_636:
F_357 ( V_628 , V_629 ) ;
return V_17 ;
}
static void F_365 ( struct V_1 * V_2 )
{
struct V_55 * V_96 ;
struct V_638 * V_639 ;
int V_17 ;
F_366 (adapter->netdev, upper, iter) {
if ( F_367 ( V_96 ) ) {
struct V_640 * V_641 = F_89 ( V_96 ) ;
struct V_624 * V_625 = V_641 -> V_642 ;
if ( V_641 -> V_642 ) {
V_17 = F_359 ( V_96 , V_625 ) ;
if ( V_17 )
continue;
}
}
}
}
static void F_368 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
F_344 ( V_2 ) ;
#ifdef F_369
F_327 ( V_2 ) ;
#endif
F_282 ( V_2 ) ;
F_317 ( V_2 -> V_56 ) ;
F_297 ( V_2 ) ;
switch ( V_14 -> V_109 . type ) {
case V_112 :
case V_113 :
V_14 -> V_109 . V_339 . V_643 ( V_14 ) ;
break;
default:
break;
}
if ( V_2 -> V_140 & V_367 ) {
F_370 ( & V_2 -> V_14 ,
V_2 -> V_611 ) ;
} else if ( V_2 -> V_140 & V_610 ) {
F_371 ( & V_2 -> V_14 ,
V_2 -> V_611 ) ;
F_345 ( V_2 ) ;
}
switch ( V_14 -> V_109 . type ) {
case V_112 :
case V_113 :
V_14 -> V_109 . V_339 . V_644 ( V_14 ) ;
break;
default:
break;
}
#ifdef F_175
F_372 ( V_2 ) ;
#endif
F_255 ( V_2 ) ;
F_292 ( V_2 ) ;
F_365 ( V_2 ) ;
}
static void F_373 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_109 . type == V_110 )
V_2 -> V_155 |= V_645 ;
V_2 -> V_155 |= V_353 ;
}
static int F_374 ( struct V_15 * V_14 )
{
T_1 V_20 ;
bool V_646 , V_341 = false ;
int V_647 = V_648 ;
if ( V_14 -> V_109 . V_339 . V_340 )
V_647 = V_14 -> V_109 . V_339 . V_340 ( V_14 , & V_20 , & V_341 , false ) ;
if ( V_647 )
return V_647 ;
V_20 = V_14 -> V_342 . V_649 ;
if ( ( ! V_20 ) && ( V_14 -> V_109 . V_339 . V_650 ) )
V_647 = V_14 -> V_109 . V_339 . V_650 ( V_14 , & V_20 ,
& V_646 ) ;
if ( V_647 )
return V_647 ;
if ( V_14 -> V_109 . V_339 . V_651 )
V_647 = V_14 -> V_109 . V_339 . V_651 ( V_14 , V_20 , V_341 ) ;
return V_647 ;
}
static void F_375 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_652 = 0 ;
if ( V_2 -> V_140 & V_392 ) {
V_652 = V_653 | V_654 |
V_655 ;
V_652 |= V_656 ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
F_71 ( V_14 , V_657 , V_658 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
default:
F_71 ( V_14 , F_376 ( 0 ) , 0xFFFFFFFF ) ;
F_71 ( V_14 , F_376 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_71 ( V_14 , V_657 , V_658 ) ;
}
if ( V_2 -> V_140 & V_412 ) {
V_652 &= ~ V_659 ;
switch ( V_2 -> V_417 [ V_494 ] . V_118 ) {
case V_495 :
V_652 |= V_660 ;
break;
case V_497 :
V_652 |= V_661 ;
break;
default:
V_652 |= V_662 ;
break;
}
}
if ( V_2 -> V_155 & V_334 ) {
switch ( V_2 -> V_14 . V_109 . type ) {
case V_112 :
V_652 |= V_663 ;
break;
case V_113 :
V_652 |= V_363 ;
break;
default:
break;
}
}
if ( V_2 -> V_140 & V_346 )
V_652 |= F_377 ( V_14 ) ;
if ( V_14 -> V_109 . type == V_112 ) {
V_652 |= V_664 ;
V_652 |= V_665 ;
}
F_71 ( V_14 , V_666 , V_652 ) ;
}
static void F_378 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 ;
T_1 V_101 ;
F_72 ( V_2 ) ;
F_375 ( V_2 ) ;
if ( V_2 -> V_140 & V_392 )
F_200 ( V_2 ) ;
else
F_247 ( V_2 ) ;
if ( V_14 -> V_109 . V_339 . V_667 )
V_14 -> V_109 . V_339 . V_667 ( V_14 ) ;
if ( V_14 -> V_342 . V_339 . V_668 )
V_14 -> V_342 . V_339 . V_668 ( V_14 , true ) ;
F_33 () ;
F_34 ( V_34 , & V_2 -> V_35 ) ;
F_319 ( V_2 ) ;
if ( F_212 ( V_14 ) ) {
F_373 ( V_2 ) ;
} else {
V_17 = F_374 ( V_14 ) ;
if ( V_17 )
F_103 ( V_173 , L_91 , V_17 ) ;
}
F_37 ( V_14 , V_347 ) ;
F_221 ( V_2 , true , true ) ;
if ( V_2 -> V_140 & V_346 ) {
T_1 V_669 = F_37 ( V_14 , V_670 ) ;
if ( V_669 & V_671 )
F_208 ( V_157 , L_71 ) ;
}
V_2 -> V_140 |= V_356 ;
V_2 -> V_357 = V_172 ;
F_379 ( & V_2 -> V_672 , V_172 ) ;
V_101 = F_37 ( V_14 , V_102 ) ;
V_101 |= V_673 ;
F_71 ( V_14 , V_102 , V_101 ) ;
}
void F_380 ( struct V_1 * V_2 )
{
F_381 ( F_382 () ) ;
V_2 -> V_56 -> V_75 = V_172 ;
while ( F_15 ( V_674 , & V_2 -> V_35 ) )
F_252 ( 1000 , 2000 ) ;
F_383 ( V_2 ) ;
if ( V_2 -> V_140 & V_412 )
F_384 ( 2000 ) ;
F_385 ( V_2 ) ;
F_34 ( V_674 , & V_2 -> V_35 ) ;
}
void F_385 ( struct V_1 * V_2 )
{
F_368 ( V_2 ) ;
F_378 ( V_2 ) ;
}
void F_386 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_55 * V_56 = V_2 -> V_56 ;
int V_17 ;
T_4 V_675 [ V_558 ] ;
if ( F_22 ( V_14 -> V_40 ) )
return;
while ( F_15 ( V_676 , & V_2 -> V_35 ) )
F_252 ( 1000 , 2000 ) ;
V_2 -> V_155 &= ~ ( V_645 |
V_353 ) ;
V_2 -> V_140 &= ~ V_354 ;
V_17 = V_14 -> V_109 . V_339 . V_677 ( V_14 ) ;
switch ( V_17 ) {
case 0 :
case V_678 :
case V_679 :
break;
case V_680 :
F_18 ( L_92 ) ;
break;
case V_681 :
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
F_34 ( V_676 , & V_2 -> V_35 ) ;
memcpy ( V_675 , & V_2 -> V_551 [ 0 ] . V_554 , V_56 -> V_682 ) ;
F_304 ( V_2 ) ;
F_307 ( V_2 , V_675 ) ;
if ( V_14 -> V_109 . V_683 )
V_14 -> V_109 . V_339 . V_684 ( V_14 , F_281 ( 0 ) ) ;
if ( F_14 ( V_685 , & V_2 -> V_35 ) )
F_387 ( V_2 ) ;
if ( V_14 -> V_342 . V_339 . V_668 ) {
if ( ! F_57 ( V_2 -> V_56 ) && ! V_2 -> V_686 )
V_14 -> V_342 . V_339 . V_668 ( V_14 , false ) ;
else
V_14 -> V_342 . V_339 . V_668 ( V_14 , true ) ;
}
}
static void F_388 ( struct V_58 * V_59 )
{
struct V_60 * V_79 ;
unsigned long V_278 ;
T_2 V_49 ;
if ( ! V_59 -> V_79 )
return;
for ( V_49 = 0 ; V_49 < V_59 -> V_89 ; V_49 ++ ) {
V_79 = & V_59 -> V_79 [ V_49 ] ;
F_77 ( V_59 , V_79 ) ;
}
F_389 ( F_107 ( V_59 ) ) ;
V_278 = sizeof( struct V_60 ) * V_59 -> V_89 ;
memset ( V_59 -> V_79 , 0 , V_278 ) ;
memset ( V_59 -> V_88 , 0 , V_59 -> V_278 ) ;
V_59 -> V_81 = 0 ;
V_59 -> V_80 = 0 ;
}
static void F_390 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_94 ; V_49 ++ )
F_354 ( V_2 -> V_68 [ V_49 ] ) ;
}
static void F_391 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ )
F_388 ( V_2 -> V_59 [ V_49 ] ) ;
}
static void F_392 ( struct V_1 * V_2 )
{
struct V_614 * V_615 ;
struct V_616 * V_617 ;
F_346 ( & V_2 -> V_618 ) ;
F_349 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_393 ( & V_617 -> V_687 ) ;
F_241 ( V_617 ) ;
}
V_2 -> V_688 = 0 ;
F_351 ( & V_2 -> V_618 ) ;
}
void F_383 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_56 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_55 * V_96 ;
struct V_638 * V_639 ;
int V_49 ;
if ( F_15 ( V_34 , & V_2 -> V_35 ) )
return;
V_14 -> V_109 . V_339 . V_534 ( V_14 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_94 ; V_49 ++ )
F_275 ( V_2 , V_2 -> V_68 [ V_49 ] ) ;
F_252 ( 10000 , 20000 ) ;
F_358 ( V_56 ) ;
F_394 ( V_56 ) ;
F_395 ( V_56 ) ;
F_366 (adapter->netdev, upper, iter) {
if ( F_367 ( V_96 ) ) {
struct V_640 * V_251 = F_89 ( V_96 ) ;
if ( V_251 -> V_642 ) {
F_358 ( V_96 ) ;
F_394 ( V_96 ) ;
F_395 ( V_96 ) ;
}
}
}
F_245 ( V_2 ) ;
F_322 ( V_2 ) ;
V_2 -> V_155 &= ~ ( V_368 |
V_156 ) ;
V_2 -> V_140 &= ~ V_356 ;
F_396 ( & V_2 -> V_672 ) ;
if ( V_2 -> V_306 ) {
F_71 ( & V_2 -> V_14 , V_308 , 0 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_306 ; V_49 ++ )
V_2 -> V_507 [ V_49 ] . V_689 = false ;
F_397 ( V_2 ) ;
F_398 ( V_2 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ ) {
T_4 V_150 = V_2 -> V_59 [ V_49 ] -> V_150 ;
F_71 ( V_14 , F_50 ( V_150 ) , V_690 ) ;
}
switch ( V_14 -> V_109 . type ) {
case V_112 :
case V_113 :
case V_114 :
case V_115 :
F_71 ( V_14 , V_428 ,
( F_37 ( V_14 , V_428 ) &
~ V_429 ) ) ;
break;
default:
break;
}
if ( ! F_399 ( V_2 -> V_9 ) )
F_386 ( V_2 ) ;
if ( V_14 -> V_109 . V_339 . V_691 )
V_14 -> V_109 . V_339 . V_691 ( V_14 ) ;
F_391 ( V_2 ) ;
F_390 ( V_2 ) ;
#ifdef F_232
F_123 ( V_2 ) ;
#endif
}
static void F_400 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
F_92 ( V_2 ) ;
}
static int F_401 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_206 , V_692 ;
T_1 V_693 ;
#ifdef F_369
int V_50 ;
struct V_694 * V_135 ;
#endif
V_14 -> V_695 = V_9 -> V_696 ;
V_14 -> V_21 = V_9 -> V_191 ;
V_14 -> V_697 = V_9 -> V_698 ;
V_14 -> V_699 = V_9 -> V_700 ;
V_14 -> V_701 = V_9 -> V_702 ;
V_206 = F_361 ( int , F_402 ( V_2 ) , F_403 () ) ;
V_2 -> V_417 [ V_418 ] . V_703 = V_206 ;
V_2 -> V_155 |= V_704 ;
V_2 -> V_155 |= V_523 ;
V_2 -> V_705 = V_706 ;
V_2 -> V_402 = 20 ;
V_692 = F_361 ( int , V_707 , F_403 () ) ;
V_2 -> V_417 [ V_708 ] . V_703 = V_692 ;
V_2 -> V_611 = V_709 ;
#ifdef F_232
V_2 -> V_140 |= V_193 ;
#endif
#ifdef F_175
V_2 -> V_140 |= V_710 ;
V_2 -> V_140 &= ~ V_515 ;
#ifdef F_369
V_2 -> V_603 . V_604 = V_711 ;
#endif
#endif
V_2 -> V_551 = F_404 ( sizeof( struct V_712 ) *
V_14 -> V_109 . V_550 ,
V_713 ) ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
V_2 -> V_155 &= ~ V_704 ;
V_2 -> V_155 &= ~ V_523 ;
if ( V_14 -> V_21 == V_714 )
V_2 -> V_140 |= V_346 ;
V_2 -> V_705 = V_715 ;
V_2 -> V_417 [ V_708 ] . V_703 = 0 ;
V_2 -> V_402 = 0 ;
V_2 -> V_611 = 0 ;
#ifdef F_175
V_2 -> V_140 &= ~ V_710 ;
V_2 -> V_140 &= ~ V_515 ;
#ifdef F_369
V_2 -> V_603 . V_604 = 0 ;
#endif
#endif
break;
case V_112 :
if ( V_14 -> V_21 == V_336 )
V_2 -> V_155 |= V_334 ;
break;
case V_113 :
V_693 = F_37 ( V_14 , F_405 ( V_14 ) ) ;
if ( V_693 & V_716 )
V_2 -> V_155 |= V_334 ;
break;
case V_115 :
case V_114 :
#ifdef F_232
V_2 -> V_140 &= ~ V_193 ;
#endif
#ifdef F_326
V_2 -> V_140 |= V_717 ;
#endif
break;
default:
break;
}
#ifdef F_175
F_406 ( & V_2 -> V_603 . V_718 ) ;
#endif
F_406 ( & V_2 -> V_618 ) ;
#ifdef F_369
switch ( V_14 -> V_109 . type ) {
case V_113 :
case V_114 :
case V_115 :
V_2 -> V_137 . V_719 . V_720 = V_721 ;
V_2 -> V_137 . V_719 . V_722 = V_721 ;
break;
default:
V_2 -> V_137 . V_719 . V_720 = V_608 ;
V_2 -> V_137 . V_719 . V_722 = V_608 ;
break;
}
for ( V_50 = 0 ; V_50 < V_608 ; V_50 ++ ) {
V_135 = & V_2 -> V_137 . V_723 [ V_50 ] ;
V_135 -> V_724 [ V_591 ] . V_725 = 0 ;
V_135 -> V_724 [ V_591 ] . V_726 = 12 + ( V_50 & 1 ) ;
V_135 -> V_724 [ V_592 ] . V_725 = 0 ;
V_135 -> V_724 [ V_592 ] . V_726 = 12 + ( V_50 & 1 ) ;
V_135 -> V_727 = V_728 ;
}
V_135 = & V_2 -> V_137 . V_723 [ 0 ] ;
V_135 -> V_724 [ V_591 ] . V_729 = 0xFF ;
V_135 -> V_724 [ V_592 ] . V_729 = 0xFF ;
V_2 -> V_137 . V_730 [ V_591 ] [ 0 ] = 100 ;
V_2 -> V_137 . V_730 [ V_592 ] [ 0 ] = 100 ;
V_2 -> V_137 . V_138 = false ;
V_2 -> V_731 = 0x00 ;
V_2 -> V_589 = V_732 | V_590 ;
memcpy ( & V_2 -> V_733 , & V_2 -> V_137 ,
sizeof( V_2 -> V_733 ) ) ;
#endif
V_14 -> V_126 . V_734 = V_128 ;
V_14 -> V_126 . V_127 = V_128 ;
F_343 ( V_2 ) ;
V_14 -> V_126 . V_735 = V_736 ;
V_14 -> V_126 . V_737 = true ;
V_14 -> V_126 . V_738 = F_407 ( V_14 ) ;
#ifdef F_299
if ( V_739 > 0 )
F_11 ( L_100 ) ;
if ( V_14 -> V_109 . type != V_110 ) {
if ( V_739 > V_740 ) {
V_2 -> V_306 = 0 ;
F_11 ( L_101 ) ;
} else {
V_2 -> V_306 = V_739 ;
}
}
#endif
V_2 -> V_383 = 1 ;
V_2 -> V_741 = 1 ;
V_2 -> V_742 = V_743 ;
V_2 -> V_744 = V_745 ;
V_2 -> V_746 = V_747 ;
if ( F_408 ( V_14 ) ) {
F_18 ( L_102 ) ;
return - V_748 ;
}
F_250 ( 0 , & V_2 -> V_634 ) ;
F_250 ( V_34 , & V_2 -> V_35 ) ;
return 0 ;
}
int F_409 ( struct V_58 * V_59 )
{
struct V_191 * V_74 = V_59 -> V_74 ;
int V_749 = F_410 ( V_74 ) ;
int V_750 = - 1 ;
int V_278 ;
V_278 = sizeof( struct V_60 ) * V_59 -> V_89 ;
if ( V_59 -> V_159 )
V_750 = V_59 -> V_159 -> V_751 ;
V_59 -> V_79 = F_411 ( V_278 , V_750 ) ;
if ( ! V_59 -> V_79 )
V_59 -> V_79 = F_412 ( V_278 ) ;
if ( ! V_59 -> V_79 )
goto V_17;
F_413 ( & V_59 -> V_170 ) ;
V_59 -> V_278 = V_59 -> V_89 * sizeof( union V_62 ) ;
V_59 -> V_278 = F_169 ( V_59 -> V_278 , 4096 ) ;
F_414 ( V_74 , V_750 ) ;
V_59 -> V_88 = F_415 ( V_74 ,
V_59 -> V_278 ,
& V_59 -> V_82 ,
V_752 ) ;
F_414 ( V_74 , V_749 ) ;
if ( ! V_59 -> V_88 )
V_59 -> V_88 = F_415 ( V_74 , V_59 -> V_278 ,
& V_59 -> V_82 , V_752 ) ;
if ( ! V_59 -> V_88 )
goto V_17;
V_59 -> V_81 = 0 ;
V_59 -> V_80 = 0 ;
return 0 ;
V_17:
F_416 ( V_59 -> V_79 ) ;
V_59 -> V_79 = NULL ;
F_417 ( V_74 , L_103 ) ;
return - V_549 ;
}
static int F_418 ( struct V_1 * V_2 )
{
int V_49 , V_17 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ ) {
V_17 = F_409 ( V_2 -> V_59 [ V_49 ] ) ;
if ( ! V_17 )
continue;
F_103 ( V_173 , L_104 , V_49 ) ;
goto V_753;
}
return 0 ;
V_753:
while ( V_49 -- )
F_419 ( V_2 -> V_59 [ V_49 ] ) ;
return V_17 ;
}
int F_420 ( struct V_58 * V_68 )
{
struct V_191 * V_74 = V_68 -> V_74 ;
int V_749 = F_410 ( V_74 ) ;
int V_750 = - 1 ;
int V_278 ;
V_278 = sizeof( struct V_71 ) * V_68 -> V_89 ;
if ( V_68 -> V_159 )
V_750 = V_68 -> V_159 -> V_751 ;
V_68 -> V_72 = F_411 ( V_278 , V_750 ) ;
if ( ! V_68 -> V_72 )
V_68 -> V_72 = F_412 ( V_278 ) ;
if ( ! V_68 -> V_72 )
goto V_17;
F_413 ( & V_68 -> V_170 ) ;
V_68 -> V_278 = V_68 -> V_89 * sizeof( union V_69 ) ;
V_68 -> V_278 = F_169 ( V_68 -> V_278 , 4096 ) ;
F_414 ( V_74 , V_750 ) ;
V_68 -> V_88 = F_415 ( V_74 ,
V_68 -> V_278 ,
& V_68 -> V_82 ,
V_752 ) ;
F_414 ( V_74 , V_749 ) ;
if ( ! V_68 -> V_88 )
V_68 -> V_88 = F_415 ( V_74 , V_68 -> V_278 ,
& V_68 -> V_82 , V_752 ) ;
if ( ! V_68 -> V_88 )
goto V_17;
V_68 -> V_80 = 0 ;
V_68 -> V_81 = 0 ;
return 0 ;
V_17:
F_416 ( V_68 -> V_72 ) ;
V_68 -> V_72 = NULL ;
F_417 ( V_74 , L_105 ) ;
return - V_549 ;
}
static int F_421 ( struct V_1 * V_2 )
{
int V_49 , V_17 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_94 ; V_49 ++ ) {
V_17 = F_420 ( V_2 -> V_68 [ V_49 ] ) ;
if ( ! V_17 )
continue;
F_103 ( V_173 , L_106 , V_49 ) ;
goto V_754;
}
#ifdef F_175
V_17 = F_422 ( V_2 ) ;
if ( ! V_17 )
#endif
return 0 ;
V_754:
while ( V_49 -- )
F_423 ( V_2 -> V_68 [ V_49 ] ) ;
return V_17 ;
}
void F_419 ( struct V_58 * V_59 )
{
F_388 ( V_59 ) ;
F_416 ( V_59 -> V_79 ) ;
V_59 -> V_79 = NULL ;
if ( ! V_59 -> V_88 )
return;
F_424 ( V_59 -> V_74 , V_59 -> V_278 ,
V_59 -> V_88 , V_59 -> V_82 ) ;
V_59 -> V_88 = NULL ;
}
static void F_425 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ )
if ( V_2 -> V_59 [ V_49 ] -> V_88 )
F_419 ( V_2 -> V_59 [ V_49 ] ) ;
}
void F_423 ( struct V_58 * V_68 )
{
F_354 ( V_68 ) ;
F_416 ( V_68 -> V_72 ) ;
V_68 -> V_72 = NULL ;
if ( ! V_68 -> V_88 )
return;
F_424 ( V_68 -> V_74 , V_68 -> V_278 ,
V_68 -> V_88 , V_68 -> V_82 ) ;
V_68 -> V_88 = NULL ;
}
static void F_426 ( struct V_1 * V_2 )
{
int V_49 ;
#ifdef F_175
F_427 ( V_2 ) ;
#endif
for ( V_49 = 0 ; V_49 < V_2 -> V_94 ; V_49 ++ )
if ( V_2 -> V_68 [ V_49 ] -> V_88 )
F_423 ( V_2 -> V_68 [ V_49 ] ) ;
}
static int F_428 ( struct V_55 * V_56 , int V_755 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
int V_510 = V_755 + V_511 + V_512 ;
if ( ( V_755 < 68 ) || ( V_510 > V_756 ) )
return - V_560 ;
if ( ( V_2 -> V_140 & V_412 ) &&
( V_2 -> V_14 . V_109 . type == V_112 ) &&
( V_510 > ( V_517 + V_512 ) ) )
F_93 ( V_173 , L_107 ) ;
F_105 ( V_173 , L_108 , V_56 -> V_294 , V_755 ) ;
V_56 -> V_294 = V_755 ;
if ( F_57 ( V_56 ) )
F_380 ( V_2 ) ;
return 0 ;
}
static int F_429 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 , V_361 ;
if ( F_14 ( V_757 , & V_2 -> V_35 ) )
return - V_758 ;
F_394 ( V_56 ) ;
V_17 = F_418 ( V_2 ) ;
if ( V_17 )
goto V_753;
V_17 = F_421 ( V_2 ) ;
if ( V_17 )
goto V_754;
F_368 ( V_2 ) ;
V_17 = F_243 ( V_2 ) ;
if ( V_17 )
goto V_759;
if ( V_2 -> V_635 > 1 )
V_361 = V_2 -> V_626 ;
else
V_361 = V_2 -> V_78 ;
V_17 = F_362 ( V_56 , V_361 ) ;
if ( V_17 )
goto V_760;
if ( V_2 -> V_635 > 1 &&
V_2 -> V_94 > V_761 )
V_361 = V_761 ;
else
V_361 = V_2 -> V_94 ;
V_17 = F_363 ( V_56 , V_361 ) ;
if ( V_17 )
goto V_760;
F_430 ( V_2 ) ;
F_378 ( V_2 ) ;
F_325 ( V_2 ) ;
#ifdef F_326
F_431 ( V_56 ) ;
#endif
return 0 ;
V_760:
F_244 ( V_2 ) ;
V_759:
F_426 ( V_2 ) ;
if ( V_14 -> V_342 . V_339 . V_668 && ! V_2 -> V_686 )
V_14 -> V_342 . V_339 . V_668 ( & V_2 -> V_14 , false ) ;
V_754:
F_425 ( V_2 ) ;
V_753:
F_386 ( V_2 ) ;
return V_17 ;
}
static void F_432 ( struct V_1 * V_2 )
{
F_433 ( V_2 ) ;
if ( V_2 -> V_14 . V_342 . V_339 . V_762 ) {
V_2 -> V_14 . V_342 . V_763 = true ;
F_383 ( V_2 ) ;
V_2 -> V_14 . V_342 . V_339 . V_762 ( & V_2 -> V_14 ) ;
V_2 -> V_14 . V_342 . V_763 = false ;
} else {
F_383 ( V_2 ) ;
}
F_244 ( V_2 ) ;
F_425 ( V_2 ) ;
F_426 ( V_2 ) ;
}
static int F_434 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
F_435 ( V_2 ) ;
F_432 ( V_2 ) ;
F_392 ( V_2 ) ;
F_70 ( V_2 ) ;
return 0 ;
}
static int F_436 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_437 ( V_9 ) ;
struct V_55 * V_56 = V_2 -> V_56 ;
T_1 V_17 ;
V_2 -> V_14 . V_40 = V_2 -> V_401 ;
F_438 ( V_9 , V_764 ) ;
F_439 ( V_9 ) ;
F_440 ( V_9 ) ;
V_17 = F_441 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_109 ) ;
return V_17 ;
}
F_33 () ;
F_34 ( V_765 , & V_2 -> V_35 ) ;
F_442 ( V_9 ) ;
F_443 ( V_9 , false ) ;
F_386 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_766 , ~ 0 ) ;
F_444 () ;
V_17 = F_445 ( V_2 ) ;
if ( ! V_17 && F_57 ( V_56 ) )
V_17 = F_429 ( V_56 ) ;
F_446 () ;
if ( V_17 )
return V_17 ;
F_447 ( V_56 ) ;
return 0 ;
}
static int F_448 ( struct V_5 * V_9 , bool * V_767 )
{
struct V_1 * V_2 = F_437 ( V_9 ) ;
struct V_55 * V_56 = V_2 -> V_56 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_768 , V_564 ;
T_1 V_769 = V_2 -> V_686 ;
#ifdef F_449
int V_770 = 0 ;
#endif
F_450 ( V_56 ) ;
F_444 () ;
if ( F_57 ( V_56 ) )
F_432 ( V_2 ) ;
F_446 () ;
F_451 ( V_2 ) ;
#ifdef F_449
V_770 = F_440 ( V_9 ) ;
if ( V_770 )
return V_770 ;
#endif
if ( V_14 -> V_109 . V_339 . V_771 )
V_14 -> V_109 . V_339 . V_771 ( V_14 ) ;
if ( V_769 ) {
F_317 ( V_56 ) ;
if ( V_14 -> V_109 . V_339 . V_667 )
V_14 -> V_109 . V_339 . V_667 ( V_14 ) ;
if ( V_769 & V_772 ) {
V_564 = F_37 ( V_14 , V_568 ) ;
V_564 |= V_574 ;
F_71 ( V_14 , V_568 , V_564 ) ;
}
V_768 = F_37 ( V_14 , V_773 ) ;
V_768 |= V_774 ;
F_71 ( V_14 , V_773 , V_768 ) ;
F_71 ( V_14 , V_775 , V_769 ) ;
} else {
F_71 ( V_14 , V_776 , 0 ) ;
F_71 ( V_14 , V_775 , 0 ) ;
}
switch ( V_14 -> V_109 . type ) {
case V_110 :
F_443 ( V_9 , false ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
F_443 ( V_9 , ! ! V_769 ) ;
break;
default:
break;
}
* V_767 = ! ! V_769 ;
if ( V_14 -> V_342 . V_339 . V_668 && ! * V_767 )
V_14 -> V_342 . V_339 . V_668 ( V_14 , false ) ;
F_70 ( V_2 ) ;
if ( ! F_15 ( V_765 , & V_2 -> V_35 ) )
F_452 ( V_9 ) ;
return 0 ;
}
static int F_453 ( struct V_5 * V_9 , T_13 V_35 )
{
int V_770 ;
bool V_777 ;
V_770 = F_448 ( V_9 , & V_777 ) ;
if ( V_770 )
return V_770 ;
if ( V_777 ) {
F_454 ( V_9 ) ;
} else {
F_443 ( V_9 , false ) ;
F_438 ( V_9 , V_778 ) ;
}
return 0 ;
}
static void F_455 ( struct V_5 * V_9 )
{
bool V_777 ;
F_448 ( V_9 , & V_777 ) ;
if ( V_779 == V_780 ) {
F_443 ( V_9 , V_777 ) ;
F_438 ( V_9 , V_778 ) ;
}
}
void F_456 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_56 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_123 * V_124 = & V_2 -> V_125 ;
T_6 V_781 = 0 ;
T_1 V_49 , V_782 = 0 , V_783 , V_784 , V_785 , V_786 , V_787 ;
T_6 V_263 = 0 , V_175 = 0 , V_788 = 0 ;
T_6 V_234 = 0 , V_287 = 0 ;
T_6 V_171 = 0 , V_145 = 0 , V_789 = 0 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_674 , & V_2 -> V_35 ) )
return;
if ( V_2 -> V_155 & V_523 ) {
T_6 V_245 = 0 ;
T_6 V_246 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_94 ; V_49 ++ ) {
V_245 += V_2 -> V_68 [ V_49 ] -> V_222 . V_245 ;
V_246 += V_2 -> V_68 [ V_49 ] -> V_222 . V_246 ;
}
V_2 -> V_790 = V_245 ;
V_2 -> V_791 = V_246 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_94 ; V_49 ++ ) {
struct V_58 * V_68 = V_2 -> V_68 [ V_49 ] ;
V_263 += V_68 -> V_222 . V_263 ;
V_234 += V_68 -> V_222 . V_234 ;
V_287 += V_68 -> V_222 . V_287 ;
V_789 += V_68 -> V_222 . V_223 ;
V_171 += V_68 -> V_125 . V_171 ;
V_145 += V_68 -> V_125 . V_145 ;
}
V_2 -> V_263 = V_263 ;
V_2 -> V_234 = V_234 ;
V_2 -> V_287 = V_287 ;
V_2 -> V_789 = V_789 ;
V_56 -> V_125 . V_792 = V_171 ;
V_56 -> V_125 . V_793 = V_145 ;
V_171 = 0 ;
V_145 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ ) {
struct V_58 * V_59 = V_2 -> V_59 [ V_49 ] ;
V_175 += V_59 -> V_153 . V_175 ;
V_788 += V_59 -> V_153 . V_788 ;
V_171 += V_59 -> V_125 . V_171 ;
V_145 += V_59 -> V_125 . V_145 ;
}
V_2 -> V_175 = V_175 ;
V_2 -> V_788 = V_788 ;
V_56 -> V_125 . V_794 = V_171 ;
V_56 -> V_125 . V_795 = V_145 ;
V_124 -> V_796 += F_37 ( V_14 , V_797 ) ;
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
V_783 = F_37 ( V_14 , F_457 ( V_49 ) ) ;
V_782 += V_783 ;
V_124 -> V_783 [ V_49 ] += V_783 ;
V_781 += V_124 -> V_783 [ V_49 ] ;
V_124 -> V_798 [ V_49 ] += F_37 ( V_14 , F_458 ( V_49 ) ) ;
V_124 -> V_799 [ V_49 ] += F_37 ( V_14 , F_459 ( V_49 ) ) ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
V_124 -> V_800 [ V_49 ] += F_37 ( V_14 , F_460 ( V_49 ) ) ;
V_124 -> V_801 [ V_49 ] += F_37 ( V_14 , F_461 ( V_49 ) ) ;
V_124 -> V_802 [ V_49 ] += F_37 ( V_14 , F_462 ( V_49 ) ) ;
V_124 -> V_803 [ V_49 ] +=
F_37 ( V_14 , F_463 ( V_49 ) ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_124 -> V_803 [ V_49 ] +=
F_37 ( V_14 , F_464 ( V_49 ) ) ;
break;
default:
break;
}
}
for ( V_49 = 0 ; V_49 < 16 ; V_49 ++ ) {
V_124 -> V_804 [ V_49 ] += F_37 ( V_14 , F_465 ( V_49 ) ) ;
V_124 -> V_805 [ V_49 ] += F_37 ( V_14 , F_466 ( V_49 ) ) ;
if ( ( V_14 -> V_109 . type == V_112 ) ||
( V_14 -> V_109 . type == V_113 ) ||
( V_14 -> V_109 . type == V_114 ) ||
( V_14 -> V_109 . type == V_115 ) ) {
V_124 -> V_801 [ V_49 ] += F_37 ( V_14 , F_467 ( V_49 ) ) ;
F_37 ( V_14 , F_468 ( V_49 ) ) ;
V_124 -> V_802 [ V_49 ] += F_37 ( V_14 , F_469 ( V_49 ) ) ;
F_37 ( V_14 , F_470 ( V_49 ) ) ;
}
}
V_124 -> V_806 += F_37 ( V_14 , V_807 ) ;
V_124 -> V_806 -= V_782 ;
F_83 ( V_2 ) ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
V_124 -> V_808 += F_37 ( V_14 , V_809 ) ;
V_124 -> V_810 += F_37 ( V_14 , V_811 ) ;
V_124 -> V_812 += F_37 ( V_14 , V_813 ) ;
V_124 -> V_814 += F_37 ( V_14 , V_815 ) ;
break;
case V_113 :
case V_114 :
case V_115 :
V_124 -> V_816 += F_37 ( V_14 , V_817 ) ;
V_124 -> V_818 += F_37 ( V_14 , V_819 ) ;
V_124 -> V_820 += F_37 ( V_14 , V_821 ) ;
V_124 -> V_822 += F_37 ( V_14 , V_823 ) ;
case V_112 :
for ( V_49 = 0 ; V_49 < 16 ; V_49 ++ )
V_2 -> V_824 +=
F_37 ( V_14 , F_471 ( V_49 ) ) ;
V_124 -> V_810 += F_37 ( V_14 , V_825 ) ;
F_37 ( V_14 , V_811 ) ;
V_124 -> V_812 += F_37 ( V_14 , V_826 ) ;
F_37 ( V_14 , V_813 ) ;
V_124 -> V_814 += F_37 ( V_14 , V_827 ) ;
F_37 ( V_14 , V_815 ) ;
V_124 -> V_808 += F_37 ( V_14 , V_828 ) ;
V_124 -> V_829 += F_37 ( V_14 , V_830 ) ;
V_124 -> V_831 += F_37 ( V_14 , V_832 ) ;
#ifdef F_175
V_124 -> V_833 += F_37 ( V_14 , V_834 ) ;
V_124 -> V_835 += F_37 ( V_14 , V_836 ) ;
V_124 -> V_837 += F_37 ( V_14 , V_838 ) ;
V_124 -> V_839 += F_37 ( V_14 , V_840 ) ;
V_124 -> V_841 += F_37 ( V_14 , V_842 ) ;
V_124 -> V_843 += F_37 ( V_14 , V_844 ) ;
if ( V_2 -> V_603 . V_845 ) {
struct V_846 * V_603 = & V_2 -> V_603 ;
struct V_847 * V_845 ;
unsigned int V_176 ;
T_6 V_848 = 0 , V_849 = 0 ;
F_472 (cpu) {
V_845 = F_473 ( V_603 -> V_845 , V_176 ) ;
V_848 += V_845 -> V_848 ;
V_849 += V_845 -> V_849 ;
}
V_124 -> V_850 = V_848 ;
V_124 -> V_851 = V_849 ;
}
#endif
break;
default:
break;
}
V_784 = F_37 ( V_14 , V_852 ) ;
V_124 -> V_784 += V_784 ;
V_124 -> V_853 += F_37 ( V_14 , V_854 ) ;
if ( V_14 -> V_109 . type == V_110 )
V_124 -> V_853 -= V_784 ;
V_124 -> V_855 += F_37 ( V_14 , V_856 ) ;
V_124 -> V_857 += F_37 ( V_14 , V_858 ) ;
V_124 -> V_859 += F_37 ( V_14 , V_860 ) ;
V_124 -> V_861 += F_37 ( V_14 , V_862 ) ;
V_124 -> V_863 += F_37 ( V_14 , V_864 ) ;
V_124 -> V_865 += F_37 ( V_14 , V_866 ) ;
V_124 -> V_867 += F_37 ( V_14 , V_868 ) ;
V_124 -> V_869 += F_37 ( V_14 , V_870 ) ;
V_785 = F_37 ( V_14 , V_871 ) ;
V_124 -> V_872 += V_785 ;
V_786 = F_37 ( V_14 , V_873 ) ;
V_124 -> V_874 += V_786 ;
V_124 -> V_875 += F_37 ( V_14 , V_876 ) ;
V_124 -> V_877 += F_37 ( V_14 , V_878 ) ;
V_787 = V_785 + V_786 ;
V_124 -> V_875 -= V_787 ;
V_124 -> V_877 -= V_787 ;
V_124 -> V_812 -= ( V_787 * ( V_879 + V_512 ) ) ;
V_124 -> V_880 += F_37 ( V_14 , V_881 ) ;
V_124 -> V_882 += F_37 ( V_14 , V_883 ) ;
V_124 -> V_884 += F_37 ( V_14 , V_885 ) ;
V_124 -> V_886 += F_37 ( V_14 , V_887 ) ;
V_124 -> V_888 += F_37 ( V_14 , V_889 ) ;
V_124 -> V_888 -= V_787 ;
V_124 -> V_890 += F_37 ( V_14 , V_891 ) ;
V_124 -> V_892 += F_37 ( V_14 , V_893 ) ;
V_124 -> V_894 += F_37 ( V_14 , V_895 ) ;
V_124 -> V_896 += F_37 ( V_14 , V_897 ) ;
V_124 -> V_898 += F_37 ( V_14 , V_899 ) ;
V_124 -> V_900 += F_37 ( V_14 , V_901 ) ;
V_56 -> V_125 . V_902 = V_124 -> V_853 ;
V_56 -> V_125 . V_903 = V_124 -> V_796 + V_124 -> V_869 ;
V_56 -> V_125 . V_904 = 0 ;
V_56 -> V_125 . V_905 = V_124 -> V_869 ;
V_56 -> V_125 . V_906 = V_124 -> V_796 ;
V_56 -> V_125 . V_907 = V_781 ;
}
static void F_474 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( ! ( V_2 -> V_155 & V_368 ) )
return;
V_2 -> V_155 &= ~ V_368 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
if ( ! ( V_2 -> V_140 & V_367 ) )
return;
V_2 -> V_908 ++ ;
if ( F_475 ( V_14 ) == 0 ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ )
F_250 ( V_377 ,
& ( V_2 -> V_59 [ V_49 ] -> V_35 ) ) ;
F_71 ( V_14 , V_360 , V_369 ) ;
} else {
F_103 ( V_173 , L_110
L_111 ) ;
}
}
static void F_476 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_909 = 0 ;
int V_49 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_674 , & V_2 -> V_35 ) )
return;
if ( F_109 ( V_2 -> V_56 ) ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ )
F_477 ( V_2 -> V_59 [ V_49 ] ) ;
}
if ( ! ( V_2 -> V_140 & V_392 ) ) {
F_71 ( V_14 , V_120 ,
( V_910 | V_911 ) ) ;
} else {
for ( V_49 = 0 ; V_49 < V_2 -> V_190 ; V_49 ++ ) {
struct V_158 * V_912 = V_2 -> V_159 [ V_49 ] ;
if ( V_912 -> V_298 . V_121 || V_912 -> V_163 . V_121 )
V_909 |= ( ( T_6 ) 1 << V_49 ) ;
}
}
F_75 ( V_2 , V_909 ) ;
}
static void F_478 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_913 = V_2 -> V_913 ;
bool V_341 = V_2 -> V_341 ;
bool V_136 = V_2 -> V_137 . V_138 ;
if ( ! ( V_2 -> V_140 & V_356 ) )
return;
if ( V_14 -> V_109 . V_339 . V_340 ) {
V_14 -> V_109 . V_339 . V_340 ( V_14 , & V_913 , & V_341 , false ) ;
} else {
V_913 = V_914 ;
V_341 = true ;
}
if ( V_2 -> V_139 )
V_136 |= ! ! ( V_2 -> V_139 -> V_136 ) ;
if ( V_341 && ! ( ( V_2 -> V_140 & V_141 ) && V_136 ) ) {
V_14 -> V_109 . V_339 . V_915 ( V_14 ) ;
F_479 ( V_2 ) ;
}
if ( V_341 ||
F_480 ( V_172 , ( V_2 -> V_357 +
V_916 ) ) ) {
V_2 -> V_140 &= ~ V_356 ;
F_71 ( V_14 , V_360 , V_359 ) ;
F_216 ( V_14 ) ;
}
V_2 -> V_341 = V_341 ;
V_2 -> V_913 = V_913 ;
}
static void F_481 ( struct V_1 * V_2 )
{
#ifdef F_369
struct V_55 * V_56 = V_2 -> V_56 ;
struct V_917 V_918 = {
. V_919 = V_920 ,
. V_253 = 0 ,
} ;
T_4 V_604 = 0 ;
if ( V_2 -> V_589 & V_921 )
V_604 = F_482 ( V_56 , & V_918 ) ;
V_2 -> V_922 = ( V_604 > 1 ) ? ( F_483 ( V_604 ) - 1 ) : 0 ;
#endif
}
static void F_484 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_56 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_55 * V_96 ;
struct V_638 * V_639 ;
T_1 V_913 = V_2 -> V_913 ;
const char * V_923 ;
bool V_924 , V_925 ;
if ( F_109 ( V_56 ) )
return;
V_2 -> V_155 &= ~ V_645 ;
switch ( V_14 -> V_109 . type ) {
case V_110 : {
T_1 V_926 = F_37 ( V_14 , V_568 ) ;
T_1 V_927 = F_37 ( V_14 , V_928 ) ;
V_924 = ! ! ( V_926 & V_929 ) ;
V_925 = ! ! ( V_927 & V_930 ) ;
}
break;
case V_113 :
case V_114 :
case V_115 :
case V_112 : {
T_1 V_931 = F_37 ( V_14 , V_932 ) ;
T_1 V_933 = F_37 ( V_14 , V_934 ) ;
V_924 = ! ! ( V_931 & V_935 ) ;
V_925 = ! ! ( V_933 & V_936 ) ;
}
break;
default:
V_925 = false ;
V_924 = false ;
break;
}
V_2 -> V_937 = V_172 ;
if ( F_14 ( V_685 , & V_2 -> V_35 ) )
F_485 ( V_2 ) ;
switch ( V_913 ) {
case V_914 :
V_923 = L_112 ;
break;
case V_938 :
V_923 = L_113 ;
break;
case V_939 :
V_923 = L_114 ;
break;
case V_940 :
V_923 = L_115 ;
break;
default:
V_923 = L_116 ;
break;
}
F_105 ( V_157 , L_117 , V_923 ,
( ( V_924 && V_925 ) ? L_118 :
( V_924 ? L_119 :
( V_925 ? L_120 : L_121 ) ) ) ) ;
F_486 ( V_56 ) ;
F_487 ( V_2 ) ;
F_488 ( V_2 -> V_56 ) ;
F_444 () ;
F_366 (adapter->netdev, upper, iter) {
if ( F_367 ( V_96 ) ) {
struct V_640 * V_251 = F_89 ( V_96 ) ;
if ( V_251 -> V_642 )
F_488 ( V_96 ) ;
}
}
F_446 () ;
F_481 ( V_2 ) ;
F_397 ( V_2 ) ;
}
static void F_489 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_56 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_341 = false ;
V_2 -> V_913 = 0 ;
if ( ! F_109 ( V_56 ) )
return;
if ( F_212 ( V_14 ) && V_14 -> V_109 . type == V_110 )
V_2 -> V_155 |= V_645 ;
if ( F_14 ( V_685 , & V_2 -> V_35 ) )
F_485 ( V_2 ) ;
F_105 ( V_157 , L_122 ) ;
F_394 ( V_56 ) ;
F_397 ( V_2 ) ;
}
static bool F_490 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ ) {
struct V_58 * V_59 = V_2 -> V_59 [ V_49 ] ;
if ( V_59 -> V_81 != V_59 -> V_80 )
return true ;
}
return false ;
}
static bool F_491 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_941 * V_942 = & V_2 -> V_417 [ V_494 ] ;
T_1 V_943 = F_492 ( 1 , ~ V_942 -> V_118 ) ;
int V_49 , V_50 ;
if ( ! V_2 -> V_306 )
return false ;
if ( V_14 -> V_109 . type >= V_114 )
return false ;
for ( V_49 = 0 ; V_49 < V_2 -> V_306 ; V_49 ++ ) {
for ( V_50 = 0 ; V_50 < V_943 ; V_50 ++ ) {
T_1 V_944 , V_945 ;
V_944 = F_37 ( V_14 , F_493 ( V_943 , V_49 , V_50 ) ) ;
V_945 = F_37 ( V_14 , F_494 ( V_943 , V_49 , V_50 ) ) ;
if ( V_944 != V_945 )
return true ;
}
}
return false ;
}
static void F_495 ( struct V_1 * V_2 )
{
if ( ! F_109 ( V_2 -> V_56 ) ) {
if ( F_490 ( V_2 ) ||
F_491 ( V_2 ) ) {
F_93 ( V_157 , L_123 ) ;
V_2 -> V_155 |= V_156 ;
}
}
}
static inline void F_496 ( struct V_1 * V_2 ,
struct V_5 * V_946 )
{
if ( ! F_497 ( V_946 ) )
F_11 ( L_124 ) ;
F_18 ( L_125 , F_498 ( V_946 ) ) ;
F_499 ( V_946 , V_947 , V_948 ) ;
F_384 ( 100 ) ;
}
static void F_500 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
struct V_5 * V_946 ;
T_1 V_949 ;
int V_950 ;
unsigned short V_951 ;
if ( ! ( F_109 ( V_2 -> V_56 ) ) )
return;
V_949 = F_37 ( V_14 , V_952 ) ;
if ( V_949 )
return;
if ( ! V_9 )
return;
V_950 = F_501 ( V_9 , V_953 ) ;
if ( ! V_950 )
return;
F_25 ( V_9 , V_950 + V_954 , & V_951 ) ;
V_946 = F_502 ( V_9 -> V_696 , V_951 , NULL ) ;
while ( V_946 ) {
if ( V_946 -> V_955 && ( V_946 -> V_956 == V_9 ) ) {
T_2 V_957 ;
F_25 ( V_946 , V_958 , & V_957 ) ;
if ( V_957 & V_959 )
F_496 ( V_2 , V_946 ) ;
}
V_946 = F_502 ( V_9 -> V_696 , V_951 , V_946 ) ;
}
}
static void F_503 ( struct V_1 * V_2 )
{
T_1 V_960 ;
if ( V_2 -> V_14 . V_109 . type == V_110 ||
V_2 -> V_306 == 0 )
return;
V_960 = F_37 ( & V_2 -> V_14 , V_961 ) ;
if ( ! V_960 )
return;
F_93 ( V_157 , L_126 , V_960 ) ;
}
static void F_503 ( struct V_1 T_14 * V_2 )
{
}
static void
F_500 ( struct V_1 T_14 * V_2 )
{
}
static void F_504 ( struct V_1 * V_2 )
{
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_674 , & V_2 -> V_35 ) )
return;
F_478 ( V_2 ) ;
if ( V_2 -> V_341 )
F_484 ( V_2 ) ;
else
F_489 ( V_2 ) ;
F_500 ( V_2 ) ;
F_503 ( V_2 ) ;
F_456 ( V_2 ) ;
F_495 ( V_2 ) ;
}
static void F_505 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_3 V_17 ;
if ( ! ( V_2 -> V_155 & V_645 ) &&
! ( V_2 -> V_155 & V_353 ) )
return;
if ( F_15 ( V_676 , & V_2 -> V_35 ) )
return;
V_17 = V_14 -> V_342 . V_339 . V_962 ( V_14 ) ;
if ( V_17 == V_679 )
goto V_963;
if ( V_17 == V_678 ) {
V_2 -> V_155 |= V_353 ;
}
if ( V_17 )
goto V_963;
if ( ! ( V_2 -> V_155 & V_353 ) )
goto V_963;
V_2 -> V_155 &= ~ V_353 ;
if ( V_14 -> V_109 . type == V_110 )
V_17 = V_14 -> V_342 . V_339 . V_964 ( V_14 ) ;
else
V_17 = V_14 -> V_109 . V_339 . V_965 ( V_14 ) ;
if ( V_17 == V_679 )
goto V_963;
V_2 -> V_140 |= V_354 ;
F_105 ( V_173 , L_127 , V_14 -> V_342 . V_966 ) ;
V_963:
F_34 ( V_676 , & V_2 -> V_35 ) ;
if ( ( V_17 == V_679 ) &&
( V_2 -> V_56 -> V_967 == V_968 ) ) {
F_18 ( L_128
L_129 ) ;
F_18 ( L_130
L_131 ) ;
F_506 ( V_2 -> V_56 ) ;
}
}
static void F_507 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_20 ;
bool V_646 = false ;
if ( ! ( V_2 -> V_140 & V_354 ) )
return;
if ( F_15 ( V_676 , & V_2 -> V_35 ) )
return;
V_2 -> V_140 &= ~ V_354 ;
V_20 = V_14 -> V_342 . V_649 ;
if ( ( ! V_20 ) && ( V_14 -> V_109 . V_339 . V_650 ) ) {
V_14 -> V_109 . V_339 . V_650 ( V_14 , & V_20 , & V_646 ) ;
if ( ! V_646 ) {
if ( V_20 & V_914 )
V_20 = V_914 ;
}
}
if ( V_14 -> V_109 . V_339 . V_651 )
V_14 -> V_109 . V_339 . V_651 ( V_14 , V_20 , true ) ;
V_2 -> V_140 |= V_356 ;
V_2 -> V_357 = V_172 ;
F_34 ( V_676 , & V_2 -> V_35 ) ;
}
static void F_508 ( unsigned long V_93 )
{
struct V_1 * V_2 = (struct V_1 * ) V_93 ;
unsigned long V_969 ;
if ( V_2 -> V_140 & V_356 )
V_969 = V_970 / 10 ;
else
V_969 = V_970 * 2 ;
F_379 ( & V_2 -> V_672 , V_969 + V_172 ) ;
F_13 ( V_2 ) ;
}
static void F_509 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_166 ;
if ( ! ( V_2 -> V_155 & V_372 ) )
return;
V_2 -> V_155 &= ~ V_372 ;
if ( ! V_14 -> V_342 . V_339 . V_971 )
return;
V_166 = V_14 -> V_342 . V_339 . V_971 ( & V_2 -> V_14 ) ;
if ( V_166 != V_344 )
return;
F_208 ( V_157 , L_70 , V_345 ) ;
}
static void F_510 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_155 & V_156 ) )
return;
V_2 -> V_155 &= ~ V_156 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_674 , & V_2 -> V_35 ) )
return;
F_54 ( V_2 ) ;
F_511 ( V_2 -> V_56 , L_132 ) ;
V_2 -> V_174 ++ ;
F_444 () ;
F_380 ( V_2 ) ;
F_446 () ;
}
static void F_512 ( struct V_972 * V_973 )
{
struct V_1 * V_2 = F_196 ( V_973 ,
struct V_1 ,
V_38 ) ;
if ( F_22 ( V_2 -> V_14 . V_40 ) ) {
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_444 () ;
F_383 ( V_2 ) ;
F_446 () ;
}
F_31 ( V_2 ) ;
return;
}
#ifdef F_326
if ( V_2 -> V_155 & V_974 ) {
V_2 -> V_155 &= ~ V_974 ;
F_431 ( V_2 -> V_56 ) ;
}
#endif
F_510 ( V_2 ) ;
F_509 ( V_2 ) ;
F_505 ( V_2 ) ;
F_507 ( V_2 ) ;
F_206 ( V_2 ) ;
F_504 ( V_2 ) ;
F_474 ( V_2 ) ;
F_476 ( V_2 ) ;
if ( F_14 ( V_685 , & V_2 -> V_35 ) ) {
F_513 ( V_2 ) ;
F_514 ( V_2 ) ;
}
F_31 ( V_2 ) ;
}
static int F_515 ( struct V_58 * V_59 ,
struct V_60 * V_975 ,
T_4 * V_240 )
{
struct V_196 * V_90 = V_975 -> V_90 ;
T_1 V_976 , V_977 ;
T_1 V_978 , V_979 ;
int V_17 ;
if ( V_90 -> V_228 != V_980 )
return 0 ;
if ( ! F_516 ( V_90 ) )
return 0 ;
V_17 = F_517 ( V_90 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_977 = V_981 ;
if ( V_975 -> V_253 == F_156 ( V_982 ) ) {
struct V_983 * V_984 = F_518 ( V_90 ) ;
V_984 -> V_985 = 0 ;
V_984 -> V_986 = 0 ;
F_519 ( V_90 ) -> V_986 = ~ F_520 ( V_984 -> V_987 ,
V_984 -> V_988 , 0 ,
V_989 ,
0 ) ;
V_977 |= V_990 ;
V_975 -> V_991 |= V_992 |
V_993 |
V_994 ;
} else if ( F_521 ( V_90 ) ) {
F_522 ( V_90 ) -> V_995 = 0 ;
F_519 ( V_90 ) -> V_986 =
~ F_523 ( & F_522 ( V_90 ) -> V_987 ,
& F_522 ( V_90 ) -> V_988 ,
0 , V_989 , 0 ) ;
V_975 -> V_991 |= V_992 |
V_993 ;
}
V_979 = F_524 ( V_90 ) ;
* V_240 = F_525 ( V_90 ) + V_979 ;
V_975 -> V_169 = F_149 ( V_90 ) -> V_169 ;
V_975 -> V_168 += ( V_975 -> V_169 - 1 ) * * V_240 ;
V_978 = V_979 << V_996 ;
V_978 |= F_149 ( V_90 ) -> V_241 << V_997 ;
V_976 = F_526 ( V_90 ) ;
V_976 |= F_527 ( V_90 ) << V_998 ;
V_976 |= V_975 -> V_991 & V_999 ;
F_528 ( V_59 , V_976 , 0 , V_977 ,
V_978 ) ;
return 1 ;
}
static void F_529 ( struct V_58 * V_59 ,
struct V_60 * V_975 )
{
struct V_196 * V_90 = V_975 -> V_90 ;
T_1 V_976 = 0 ;
T_1 V_978 = 0 ;
T_1 V_977 = 0 ;
if ( V_90 -> V_228 != V_980 ) {
if ( ! ( V_975 -> V_991 & V_1000 ) &&
! ( V_975 -> V_991 & V_1001 ) )
return;
V_976 = F_527 ( V_90 ) <<
V_998 ;
} else {
T_4 V_1002 = 0 ;
union {
struct V_983 * V_1003 ;
struct V_1004 * V_1005 ;
T_4 * V_1006 ;
} V_1007 ;
union {
struct V_1008 * V_1008 ;
T_4 * V_1006 ;
} V_1009 ;
if ( V_90 -> V_219 ) {
V_1007 . V_1006 = F_530 ( V_90 ) ;
V_1009 . V_1006 = F_531 ( V_90 ) ;
V_976 = F_532 ( V_90 ) <<
V_998 ;
} else {
V_1007 . V_1006 = F_533 ( V_90 ) ;
V_1009 . V_1006 = F_534 ( V_90 ) ;
V_976 = F_527 ( V_90 ) <<
V_998 ;
}
switch ( V_1007 . V_1003 -> V_1010 ) {
case V_1011 :
V_976 |= V_1009 . V_1006 - V_1007 . V_1006 ;
V_977 |= V_990 ;
V_1002 = V_1007 . V_1003 -> V_253 ;
break;
case 6 :
V_976 |= V_1009 . V_1006 - V_1007 . V_1006 ;
V_1002 = V_1007 . V_1005 -> V_1012 ;
break;
default:
if ( F_24 ( F_535 () ) ) {
F_536 ( V_59 -> V_74 ,
L_133 ,
V_1007 . V_1003 -> V_1010 ) ;
}
}
switch ( V_1002 ) {
case V_989 :
V_977 |= V_981 ;
V_978 = ( V_1009 . V_1008 -> V_1013 * 4 ) <<
V_996 ;
break;
case V_1014 :
V_977 |= V_1015 ;
V_978 = sizeof( struct V_1016 ) <<
V_996 ;
break;
case V_1017 :
V_978 = sizeof( struct V_1018 ) <<
V_996 ;
break;
default:
if ( F_24 ( F_535 () ) ) {
F_536 ( V_59 -> V_74 ,
L_134 ,
V_1002 ) ;
}
break;
}
V_975 -> V_991 |= V_993 ;
}
V_976 |= V_975 -> V_991 & V_999 ;
F_528 ( V_59 , V_976 , 0 ,
V_977 , V_978 ) ;
}
static T_1 F_537 ( struct V_196 * V_90 , T_1 V_991 )
{
T_1 V_1019 = V_1020 |
V_1021 |
V_1022 ;
V_1019 |= F_538 ( V_991 , V_1000 ,
V_1023 ) ;
V_1019 |= F_538 ( V_991 , V_992 ,
V_1024 ) ;
V_1019 |= F_538 ( V_991 , V_1025 ,
V_1026 ) ;
V_1019 ^= F_538 ( V_90 -> V_1027 , 1 , V_1022 ) ;
return V_1019 ;
}
static void F_539 ( union V_62 * V_63 ,
T_1 V_991 , unsigned int V_1028 )
{
T_1 V_1029 = V_1028 << V_1030 ;
V_1029 |= F_538 ( V_991 ,
V_993 ,
V_1031 ) ;
V_1029 |= F_538 ( V_991 ,
V_994 ,
V_1032 ) ;
V_1029 |= F_538 ( V_991 ,
V_1001 ,
V_1033 ) ;
V_63 -> V_237 . V_1029 = F_96 ( V_1029 ) ;
}
static int F_540 ( struct V_58 * V_59 , T_2 V_278 )
{
F_104 ( V_59 -> V_56 , V_59 -> V_87 ) ;
F_111 () ;
if ( F_99 ( F_110 ( V_59 ) < V_278 ) )
return - V_758 ;
F_541 ( V_59 -> V_56 , V_59 -> V_87 ) ;
++ V_59 -> V_153 . V_175 ;
return 0 ;
}
static inline int F_542 ( struct V_58 * V_59 , T_2 V_278 )
{
if ( F_99 ( F_110 ( V_59 ) >= V_278 ) )
return 0 ;
return F_540 ( V_59 , V_278 ) ;
}
static void F_543 ( struct V_58 * V_59 ,
struct V_60 * V_975 ,
const T_4 V_240 )
{
struct V_196 * V_90 = V_975 -> V_90 ;
struct V_60 * V_61 ;
union V_62 * V_63 ;
struct V_264 * V_265 ;
T_9 V_82 ;
unsigned int V_270 , V_278 ;
T_1 V_991 = V_975 -> V_991 ;
T_1 V_1019 = F_537 ( V_90 , V_991 ) ;
T_2 V_49 = V_59 -> V_81 ;
V_63 = F_61 ( V_59 , V_49 ) ;
F_539 ( V_63 , V_991 , V_90 -> V_83 - V_240 ) ;
V_278 = F_148 ( V_90 ) ;
V_270 = V_90 -> V_270 ;
#ifdef F_175
if ( V_991 & V_1034 ) {
if ( V_270 < sizeof( struct V_297 ) ) {
V_278 -= sizeof( struct V_297 ) - V_270 ;
V_270 = 0 ;
} else {
V_270 -= sizeof( struct V_297 ) ;
}
}
#endif
V_82 = F_544 ( V_59 -> V_74 , V_90 -> V_93 , V_278 , V_122 ) ;
V_61 = V_975 ;
for ( V_265 = & F_149 ( V_90 ) -> V_266 [ 0 ] ; ; V_265 ++ ) {
if ( F_141 ( V_59 -> V_74 , V_82 ) )
goto V_1035;
F_81 ( V_61 , V_83 , V_278 ) ;
F_545 ( V_61 , V_82 , V_82 ) ;
V_63 -> V_237 . V_1036 = F_144 ( V_82 ) ;
while ( F_24 ( V_278 > V_1037 ) ) {
V_63 -> V_237 . V_1038 =
F_96 ( V_1019 ^ V_1037 ) ;
V_49 ++ ;
V_63 ++ ;
if ( V_49 == V_59 -> V_89 ) {
V_63 = F_61 ( V_59 , 0 ) ;
V_49 = 0 ;
}
V_63 -> V_237 . V_1029 = 0 ;
V_82 += V_1037 ;
V_278 -= V_1037 ;
V_63 -> V_237 . V_1036 = F_144 ( V_82 ) ;
}
if ( F_99 ( ! V_270 ) )
break;
V_63 -> V_237 . V_1038 = F_96 ( V_1019 ^ V_278 ) ;
V_49 ++ ;
V_63 ++ ;
if ( V_49 == V_59 -> V_89 ) {
V_63 = F_61 ( V_59 , 0 ) ;
V_49 = 0 ;
}
V_63 -> V_237 . V_1029 = 0 ;
#ifdef F_175
V_278 = F_361 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_278 = F_546 ( V_265 ) ;
#endif
V_270 -= V_278 ;
V_82 = F_547 ( V_59 -> V_74 , V_265 , 0 , V_278 ,
V_122 ) ;
V_61 = & V_59 -> V_79 [ V_49 ] ;
}
V_1019 |= V_278 | V_1039 ;
V_63 -> V_237 . V_1038 = F_96 ( V_1019 ) ;
F_548 ( F_107 ( V_59 ) , V_975 -> V_168 ) ;
V_975 -> V_85 = V_172 ;
F_145 () ;
V_975 -> V_84 = V_63 ;
V_49 ++ ;
if ( V_49 == V_59 -> V_89 )
V_49 = 0 ;
V_59 -> V_81 = V_49 ;
F_542 ( V_59 , V_1040 ) ;
if ( F_549 ( F_107 ( V_59 ) ) || ! V_90 -> V_1041 ) {
F_146 ( V_49 , V_59 -> V_147 ) ;
F_550 () ;
}
return;
V_1035:
F_417 ( V_59 -> V_74 , L_135 ) ;
for (; ; ) {
V_61 = & V_59 -> V_79 [ V_49 ] ;
F_77 ( V_59 , V_61 ) ;
if ( V_61 == V_975 )
break;
if ( V_49 == 0 )
V_49 = V_59 -> V_89 ;
V_49 -- ;
}
V_59 -> V_81 = V_49 ;
}
static void F_551 ( struct V_58 * V_121 ,
struct V_60 * V_975 )
{
struct V_158 * V_159 = V_121 -> V_159 ;
union V_1042 V_1043 = { . V_1044 = 0 } ;
union V_1042 V_1045 = { . V_1044 = 0 } ;
union {
unsigned char * V_1046 ;
struct V_983 * V_1003 ;
struct V_1004 * V_1005 ;
} V_1047 ;
struct V_1008 * V_1048 ;
struct V_196 * V_90 ;
#ifdef F_326
T_4 V_1049 = false ;
#endif
T_12 V_1050 ;
if ( ! V_159 )
return;
if ( ! V_121 -> V_402 )
return;
V_121 -> V_403 ++ ;
V_90 = V_975 -> V_90 ;
V_1047 . V_1046 = F_533 ( V_90 ) ;
if ( V_90 -> V_219 ) {
#ifdef F_326
struct V_1 * V_2 = V_159 -> V_2 ;
if ( ! V_2 -> V_587 )
return;
if ( V_975 -> V_253 != F_156 ( V_982 ) ||
V_1047 . V_1003 -> V_1010 != V_1011 ||
V_1047 . V_1003 -> V_253 != V_1017 ) {
return;
}
if ( F_552 ( F_553 ( V_90 ) -> V_1051 ) != V_2 -> V_587 )
return;
V_1049 = true ;
V_1047 . V_1046 = F_530 ( V_90 ) ;
V_1048 = F_554 ( V_90 ) ;
#else
return;
#endif
} else {
if ( ( V_975 -> V_253 != F_156 ( V_1052 ) ||
V_1047 . V_1005 -> V_1012 != V_989 ) &&
( V_975 -> V_253 != F_156 ( V_982 ) ||
V_1047 . V_1003 -> V_253 != V_989 ) )
return;
V_1048 = F_519 ( V_90 ) ;
}
if ( ! V_1048 || V_1048 -> V_1053 )
return;
if ( ! V_1048 -> V_1054 && ( V_121 -> V_403 < V_121 -> V_402 ) )
return;
V_121 -> V_403 = 0 ;
V_1050 = F_156 ( V_975 -> V_991 >> V_1055 ) ;
V_1043 . V_1056 . V_1050 = V_1050 ;
if ( V_975 -> V_991 & ( V_1057 | V_1000 ) )
V_1045 . V_1058 . V_1059 ^= V_1048 -> V_1051 ^ F_156 ( V_252 ) ;
else
V_1045 . V_1058 . V_1059 ^= V_1048 -> V_1051 ^ V_975 -> V_253 ;
V_1045 . V_1058 . V_1060 ^= V_1048 -> V_1061 ;
if ( V_975 -> V_253 == F_156 ( V_982 ) ) {
V_1043 . V_1056 . V_1062 = V_1063 ;
V_1045 . V_1064 ^= V_1047 . V_1003 -> V_987 ^ V_1047 . V_1003 -> V_988 ;
} else {
V_1043 . V_1056 . V_1062 = V_1065 ;
V_1045 . V_1064 ^= V_1047 . V_1005 -> V_987 . V_1066 [ 0 ] ^
V_1047 . V_1005 -> V_987 . V_1066 [ 1 ] ^
V_1047 . V_1005 -> V_987 . V_1066 [ 2 ] ^
V_1047 . V_1005 -> V_987 . V_1066 [ 3 ] ^
V_1047 . V_1005 -> V_988 . V_1066 [ 0 ] ^
V_1047 . V_1005 -> V_988 . V_1066 [ 1 ] ^
V_1047 . V_1005 -> V_988 . V_1066 [ 2 ] ^
V_1047 . V_1005 -> V_988 . V_1066 [ 3 ] ;
}
#ifdef F_326
if ( V_1049 )
V_1043 . V_1056 . V_1062 |= V_1067 ;
#endif
F_555 ( & V_159 -> V_2 -> V_14 ,
V_1043 , V_1045 , V_121 -> V_87 ) ;
}
static T_2 F_556 ( struct V_55 * V_74 , struct V_196 * V_90 ,
void * V_1068 , T_15 V_1069 )
{
struct V_624 * V_1070 = V_1068 ;
#ifdef F_175
struct V_1 * V_2 ;
struct V_941 * V_1071 ;
int V_1072 ;
#endif
if ( V_1070 )
return V_90 -> V_1073 + V_1070 -> V_632 ;
#ifdef F_175
switch ( F_557 ( V_90 ) ) {
case F_156 ( V_1074 ) :
case F_156 ( V_1075 ) :
V_2 = F_89 ( V_74 ) ;
if ( V_2 -> V_140 & V_515 )
break;
default:
return V_1069 ( V_74 , V_90 ) ;
}
V_1071 = & V_2 -> V_417 [ V_1076 ] ;
V_1072 = F_558 ( V_90 ) ? F_559 ( V_90 ) :
F_560 () ;
while ( V_1072 >= V_1071 -> V_419 )
V_1072 -= V_1071 -> V_419 ;
return V_1072 + V_1071 -> V_1077 ;
#else
return V_1069 ( V_74 , V_90 ) ;
#endif
}
T_16 F_561 ( struct V_196 * V_90 ,
struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_60 * V_975 ;
int V_1078 ;
T_1 V_991 = 0 ;
unsigned short V_1071 ;
T_2 V_89 = F_562 ( F_148 ( V_90 ) ) ;
T_12 V_253 = V_90 -> V_253 ;
T_4 V_240 = 0 ;
for ( V_1071 = 0 ; V_1071 < F_149 ( V_90 ) -> V_284 ; V_1071 ++ )
V_89 += F_562 ( F_149 ( V_90 ) -> V_266 [ V_1071 ] . V_278 ) ;
if ( F_542 ( V_59 , V_89 + 3 ) ) {
V_59 -> V_153 . V_788 ++ ;
return V_1079 ;
}
V_975 = & V_59 -> V_79 [ V_59 -> V_81 ] ;
V_975 -> V_90 = V_90 ;
V_975 -> V_168 = V_90 -> V_83 ;
V_975 -> V_169 = 1 ;
if ( F_563 ( V_90 ) ) {
V_991 |= F_564 ( V_90 ) << V_1055 ;
V_991 |= V_1000 ;
} else if ( V_253 == F_156 ( V_252 ) ) {
struct V_1080 * V_1081 , V_1082 ;
V_1081 = F_565 ( V_90 , V_511 , sizeof( V_1082 ) , & V_1082 ) ;
if ( ! V_1081 )
goto V_1083;
V_991 |= F_552 ( V_1081 -> V_1084 ) <<
V_1055 ;
V_991 |= V_1057 ;
}
V_253 = F_557 ( V_90 ) ;
if ( F_24 ( F_149 ( V_90 ) -> V_991 & V_1085 ) &&
V_2 -> V_1086 &&
! F_566 ( V_1087 ,
& V_2 -> V_35 ) ) {
F_149 ( V_90 ) -> V_991 |= V_1088 ;
V_991 |= V_1025 ;
V_2 -> V_1089 = F_567 ( V_90 ) ;
V_2 -> V_1090 = V_172 ;
F_16 ( & V_2 -> V_1091 ) ;
}
F_568 ( V_90 ) ;
#ifdef F_299
if ( V_2 -> V_140 & V_412 )
V_991 |= V_1001 ;
#endif
if ( ( V_2 -> V_140 & V_141 ) &&
( ( V_991 & ( V_1000 | V_1057 ) ) ||
( V_90 -> V_1092 != V_1093 ) ) ) {
V_991 &= ~ V_1094 ;
V_991 |= ( V_90 -> V_1092 & 0x7 ) <<
V_1095 ;
if ( V_991 & V_1057 ) {
struct V_1096 * V_1081 ;
if ( F_517 ( V_90 , 0 ) )
goto V_1083;
V_1081 = (struct V_1096 * ) V_90 -> V_93 ;
V_1081 -> V_1084 = F_156 ( V_991 >>
V_1055 ) ;
} else {
V_991 |= V_1000 ;
}
}
V_975 -> V_991 = V_991 ;
V_975 -> V_253 = V_253 ;
#ifdef F_175
if ( ( V_253 == F_156 ( V_1074 ) ) &&
( V_59 -> V_56 -> V_198 & ( V_1097 | V_1098 ) ) ) {
V_1078 = F_569 ( V_59 , V_975 , & V_240 ) ;
if ( V_1078 < 0 )
goto V_1083;
goto V_1099;
}
#endif
V_1078 = F_515 ( V_59 , V_975 , & V_240 ) ;
if ( V_1078 < 0 )
goto V_1083;
else if ( ! V_1078 )
F_529 ( V_59 , V_975 ) ;
if ( F_14 ( V_377 , & V_59 -> V_35 ) )
F_551 ( V_59 , V_975 ) ;
#ifdef F_175
V_1099:
#endif
F_543 ( V_59 , V_975 , V_240 ) ;
return V_1100 ;
V_1083:
F_78 ( V_975 -> V_90 ) ;
V_975 -> V_90 = NULL ;
return V_1100 ;
}
static T_16 F_570 ( struct V_196 * V_90 ,
struct V_55 * V_56 ,
struct V_58 * V_121 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
struct V_58 * V_59 ;
if ( F_571 ( V_90 , 17 ) )
return V_1100 ;
V_59 = V_121 ? V_121 : V_2 -> V_59 [ V_90 -> V_1073 ] ;
return F_561 ( V_90 , V_2 , V_59 ) ;
}
static T_16 F_572 ( struct V_196 * V_90 ,
struct V_55 * V_56 )
{
return F_570 ( V_90 , V_56 , NULL ) ;
}
static int F_573 ( struct V_55 * V_56 , void * V_1101 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1102 * V_554 = V_1101 ;
int V_647 ;
if ( ! F_364 ( V_554 -> V_1103 ) )
return - V_1104 ;
F_311 ( V_2 , V_14 -> V_109 . V_554 , F_281 ( 0 ) ) ;
memcpy ( V_56 -> V_637 , V_554 -> V_1103 , V_56 -> V_682 ) ;
memcpy ( V_14 -> V_109 . V_554 , V_554 -> V_1103 , V_56 -> V_682 ) ;
V_647 = F_308 ( V_2 , V_14 -> V_109 . V_554 , F_281 ( 0 ) ) ;
return V_647 > 0 ? 0 : V_647 ;
}
static int
F_574 ( struct V_55 * V_56 , int V_1105 , int V_1106 , T_2 V_554 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_4 ;
int V_1107 ;
if ( V_1105 != V_14 -> V_342 . V_1108 . V_1105 )
return - V_560 ;
V_1107 = V_14 -> V_342 . V_339 . V_1109 ( V_14 , V_554 , V_1106 , & V_4 ) ;
if ( ! V_1107 )
V_1107 = V_4 ;
return V_1107 ;
}
static int F_575 ( struct V_55 * V_56 , int V_1105 , int V_1106 ,
T_2 V_554 , T_2 V_4 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_1105 != V_14 -> V_342 . V_1108 . V_1105 )
return - V_560 ;
return V_14 -> V_342 . V_339 . V_1110 ( V_14 , V_554 , V_1106 , V_4 ) ;
}
static int F_576 ( struct V_55 * V_56 , struct V_1111 * V_1112 , int V_1113 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
switch ( V_1113 ) {
case V_1114 :
return F_577 ( V_2 , V_1112 ) ;
case V_1115 :
return F_578 ( V_2 , V_1112 ) ;
default:
return F_579 ( & V_2 -> V_14 . V_342 . V_1108 , F_580 ( V_1112 ) , V_1113 ) ;
}
}
static int F_581 ( struct V_55 * V_74 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_74 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_364 ( V_14 -> V_109 . V_1116 ) ) {
F_444 () ;
V_17 = F_582 ( V_74 , V_14 -> V_109 . V_1116 , V_1117 ) ;
F_446 () ;
V_14 -> V_109 . V_339 . V_684 ( V_14 , F_281 ( 0 ) ) ;
}
return V_17 ;
}
static int F_583 ( struct V_55 * V_74 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_74 ) ;
struct V_1118 * V_109 = & V_2 -> V_14 . V_109 ;
if ( F_364 ( V_109 -> V_1116 ) ) {
F_444 () ;
V_17 = F_584 ( V_74 , V_109 -> V_1116 , V_1117 ) ;
F_446 () ;
}
return V_17 ;
}
static void F_585 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
int V_49 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
for ( V_49 = 0 ; V_49 < V_2 -> V_190 ; V_49 ++ )
F_229 ( 0 , V_2 -> V_159 [ V_49 ] ) ;
}
static struct V_1119 * F_586 ( struct V_55 * V_56 ,
struct V_1119 * V_125 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
int V_49 ;
F_587 () ;
for ( V_49 = 0 ; V_49 < V_2 -> V_94 ; V_49 ++ ) {
struct V_58 * V_121 = F_21 ( V_2 -> V_68 [ V_49 ] ) ;
T_6 V_171 , V_145 ;
unsigned int V_1120 ;
if ( V_121 ) {
do {
V_1120 = F_588 ( & V_121 -> V_170 ) ;
V_145 = V_121 -> V_125 . V_145 ;
V_171 = V_121 -> V_125 . V_171 ;
} while ( F_589 ( & V_121 -> V_170 , V_1120 ) );
V_125 -> V_793 += V_145 ;
V_125 -> V_792 += V_171 ;
}
}
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ ) {
struct V_58 * V_121 = F_21 ( V_2 -> V_59 [ V_49 ] ) ;
T_6 V_171 , V_145 ;
unsigned int V_1120 ;
if ( V_121 ) {
do {
V_1120 = F_588 ( & V_121 -> V_170 ) ;
V_145 = V_121 -> V_125 . V_145 ;
V_171 = V_121 -> V_125 . V_171 ;
} while ( F_589 ( & V_121 -> V_170 , V_1120 ) );
V_125 -> V_795 += V_145 ;
V_125 -> V_794 += V_171 ;
}
}
F_590 () ;
V_125 -> V_902 = V_56 -> V_125 . V_902 ;
V_125 -> V_903 = V_56 -> V_125 . V_903 ;
V_125 -> V_905 = V_56 -> V_125 . V_905 ;
V_125 -> V_906 = V_56 -> V_125 . V_906 ;
V_125 -> V_907 = V_56 -> V_125 . V_907 ;
return V_125 ;
}
static void F_591 ( struct V_1 * V_2 , T_4 V_135 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_3 , V_1121 ;
int V_49 ;
if ( V_14 -> V_109 . type == V_110 )
return;
V_3 = F_37 ( V_14 , V_1122 ) ;
V_1121 = V_3 ;
for ( V_49 = 0 ; V_49 < V_608 ; V_49 ++ ) {
T_4 V_1123 = V_3 >> ( V_49 * V_1124 ) ;
if ( V_1123 > V_135 )
V_3 &= ~ ( 0x7 << V_1124 ) ;
}
if ( V_3 != V_1121 )
F_71 ( V_14 , V_1122 , V_3 ) ;
return;
}
static void F_592 ( struct V_1 * V_2 )
{
struct V_55 * V_74 = V_2 -> V_56 ;
struct V_1125 * V_137 = & V_2 -> V_137 ;
struct V_1126 * V_1127 = V_2 -> V_593 ;
T_4 V_1128 ;
for ( V_1128 = 0 ; V_1128 < V_1129 ; V_1128 ++ ) {
T_4 V_135 = 0 ;
if ( V_2 -> V_589 & V_590 )
V_135 = F_593 ( V_137 , 0 , V_1128 ) ;
else if ( V_1127 )
V_135 = V_1127 -> V_594 [ V_1128 ] ;
F_594 ( V_74 , V_1128 , V_135 ) ;
}
}
int F_595 ( struct V_55 * V_74 , T_4 V_135 )
{
struct V_1 * V_2 = F_89 ( V_74 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
bool V_1130 ;
if ( V_135 > V_2 -> V_137 . V_719 . V_720 )
return - V_560 ;
if ( V_14 -> V_109 . type == V_110 && V_135 && V_135 < V_608 )
return - V_560 ;
V_1130 = ( F_596 ( & V_2 -> V_634 , 32 ) > 1 ) ;
if ( V_135 && V_1130 && V_2 -> V_635 > V_1131 )
return - V_758 ;
if ( F_57 ( V_74 ) )
F_434 ( V_74 ) ;
F_451 ( V_2 ) ;
#ifdef F_369
if ( V_135 ) {
F_597 ( V_74 , V_135 ) ;
F_592 ( V_2 ) ;
V_2 -> V_140 |= V_141 ;
if ( V_2 -> V_14 . V_109 . type == V_110 ) {
V_2 -> V_1132 = V_2 -> V_14 . V_126 . V_734 ;
V_2 -> V_14 . V_126 . V_734 = V_1133 ;
}
} else {
F_598 ( V_74 ) ;
if ( V_2 -> V_14 . V_109 . type == V_110 )
V_2 -> V_14 . V_126 . V_734 = V_2 -> V_1132 ;
V_2 -> V_140 &= ~ V_141 ;
V_2 -> V_733 . V_138 = false ;
V_2 -> V_137 . V_138 = false ;
}
F_591 ( V_2 , V_135 ) ;
#endif
F_445 ( V_2 ) ;
if ( F_57 ( V_74 ) )
return F_429 ( V_74 ) ;
return 0 ;
}
void F_599 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_56 ;
F_444 () ;
F_595 ( V_56 , F_254 ( V_56 ) ) ;
F_446 () ;
}
void F_600 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
if ( F_57 ( V_56 ) )
F_380 ( V_2 ) ;
else
F_386 ( V_2 ) ;
}
static T_17 F_601 ( struct V_55 * V_56 ,
T_17 V_198 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
if ( ! ( V_198 & V_216 ) )
V_198 &= ~ V_1134 ;
if ( ! ( V_2 -> V_155 & V_704 ) )
V_198 &= ~ V_1134 ;
return V_198 ;
}
static int F_602 ( struct V_55 * V_56 ,
T_17 V_198 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
T_17 V_1135 = V_56 -> V_198 ^ V_198 ;
bool V_1136 = false ;
if ( ! ( V_198 & V_1134 ) ) {
if ( V_2 -> V_155 & V_523 )
V_1136 = true ;
V_2 -> V_155 &= ~ V_523 ;
} else if ( ( V_2 -> V_155 & V_704 ) &&
! ( V_2 -> V_155 & V_523 ) ) {
if ( V_2 -> V_383 == 1 ||
V_2 -> V_383 > V_1137 ) {
V_2 -> V_155 |= V_523 ;
V_1136 = true ;
} else if ( ( V_1135 ^ V_198 ) & V_1134 ) {
F_105 ( V_173 , L_136
L_137 ) ;
}
}
switch ( V_198 & V_1138 ) {
case V_1138 :
if ( ! ( V_2 -> V_140 & V_610 ) )
V_1136 = true ;
V_2 -> V_140 &= ~ V_367 ;
V_2 -> V_140 |= V_610 ;
break;
default:
if ( V_2 -> V_140 & V_610 )
V_1136 = true ;
V_2 -> V_140 &= ~ V_610 ;
if ( V_2 -> V_140 & V_412 )
break;
if ( F_254 ( V_56 ) > 1 )
break;
if ( V_2 -> V_417 [ V_418 ] . V_703 <= 1 )
break;
if ( ! V_2 -> V_402 )
break;
V_2 -> V_140 |= V_367 ;
break;
}
if ( V_198 & V_248 )
F_296 ( V_2 ) ;
else
F_295 ( V_2 ) ;
if ( V_1135 & V_273 )
V_1136 = true ;
V_56 -> V_198 = V_198 ;
#ifdef F_326
if ( ( V_2 -> V_140 & V_717 ) ) {
if ( V_198 & V_216 )
V_2 -> V_155 |= V_974 ;
else
F_325 ( V_2 ) ;
}
#endif
if ( V_1136 )
F_600 ( V_56 ) ;
return 0 ;
}
static void F_603 ( struct V_55 * V_74 , T_18 V_1139 ,
T_12 V_1058 )
{
struct V_1 * V_2 = F_89 ( V_74 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1140 = F_552 ( V_1058 ) ;
if ( ! ( V_2 -> V_140 & V_717 ) )
return;
if ( V_1139 == V_1141 )
return;
if ( V_2 -> V_587 == V_1140 )
return;
if ( V_2 -> V_587 ) {
F_604 ( V_74 ,
L_138 ,
V_1140 ) ;
return;
}
V_2 -> V_587 = V_1140 ;
F_71 ( V_14 , V_586 , V_1140 ) ;
}
static void F_605 ( struct V_55 * V_74 , T_18 V_1139 ,
T_12 V_1058 )
{
struct V_1 * V_2 = F_89 ( V_74 ) ;
T_2 V_1140 = F_552 ( V_1058 ) ;
if ( ! ( V_2 -> V_140 & V_717 ) )
return;
if ( V_1139 == V_1141 )
return;
if ( V_2 -> V_587 != V_1140 ) {
F_604 ( V_74 , L_139 ,
V_1140 ) ;
return;
}
F_325 ( V_2 ) ;
V_2 -> V_155 |= V_974 ;
}
static int F_606 ( struct V_1142 * V_1143 , struct V_1144 * V_1145 [] ,
struct V_55 * V_74 ,
const unsigned char * V_554 , T_2 V_250 ,
T_2 V_140 )
{
if ( F_607 ( V_554 ) || F_608 ( V_554 ) ) {
if ( V_1146 <= F_314 ( V_74 ) )
return - V_549 ;
}
return F_609 ( V_1143 , V_1145 , V_74 , V_554 , V_250 , V_140 ) ;
}
static int F_610 ( struct V_1 * V_2 ,
T_19 V_1147 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
unsigned int V_1101 , V_1148 ;
T_1 V_483 ;
switch ( V_1147 ) {
case V_1149 :
F_71 ( & V_2 -> V_14 , V_491 , 0 ) ;
V_483 = F_37 ( V_14 , V_1150 ) ;
V_483 |= V_488 ;
F_71 ( V_14 , V_1150 , V_483 ) ;
V_1148 = V_2 -> V_306 + V_2 -> V_635 ;
for ( V_1101 = 0 ; V_1101 < V_1148 ; V_1101 ++ ) {
if ( V_14 -> V_109 . V_339 . V_1151 )
V_14 -> V_109 . V_339 . V_1151 ( V_14 ,
true ,
V_1101 ) ;
}
break;
case V_490 :
F_71 ( & V_2 -> V_14 , V_491 ,
V_492 ) ;
V_483 = F_37 ( V_14 , V_1150 ) ;
if ( ! V_2 -> V_306 )
V_483 &= ~ V_488 ;
F_71 ( V_14 , V_1150 , V_483 ) ;
V_1148 = V_2 -> V_306 + V_2 -> V_635 ;
for ( V_1101 = 0 ; V_1101 < V_1148 ; V_1101 ++ ) {
if ( V_14 -> V_109 . V_339 . V_1151 )
V_14 -> V_109 . V_339 . V_1151 ( V_14 ,
false ,
V_1101 ) ;
}
break;
default:
return - V_560 ;
}
V_2 -> V_489 = V_1147 ;
F_105 ( V_157 , L_140 ,
V_1147 == V_1149 ? L_141 : L_142 ) ;
return 0 ;
}
static int F_611 ( struct V_55 * V_74 ,
struct V_1152 * V_1153 , T_2 V_140 )
{
struct V_1 * V_2 = F_89 ( V_74 ) ;
struct V_1144 * V_1154 , * V_1155 ;
int V_1156 ;
if ( ! ( V_2 -> V_140 & V_412 ) )
return - V_1157 ;
V_1155 = F_612 ( V_1153 , sizeof( struct V_1158 ) , V_1159 ) ;
if ( ! V_1155 )
return - V_560 ;
F_613 (attr, br_spec, rem) {
int V_166 ;
T_19 V_1147 ;
if ( F_614 ( V_1154 ) != V_1160 )
continue;
if ( F_615 ( V_1154 ) < sizeof( V_1147 ) )
return - V_560 ;
V_1147 = F_616 ( V_1154 ) ;
V_166 = F_610 ( V_2 , V_1147 ) ;
if ( V_166 )
return V_166 ;
break;
}
return 0 ;
}
static int F_617 ( struct V_196 * V_90 , T_1 V_1161 , T_1 V_1162 ,
struct V_55 * V_74 ,
T_1 V_1163 , int V_1164 )
{
struct V_1 * V_2 = F_89 ( V_74 ) ;
if ( ! ( V_2 -> V_140 & V_412 ) )
return 0 ;
return F_618 ( V_90 , V_1161 , V_1162 , V_74 ,
V_2 -> V_489 , 0 , 0 , V_1164 ,
V_1163 , NULL ) ;
}
static void * F_619 ( struct V_55 * V_9 , struct V_55 * V_628 )
{
struct V_624 * V_1070 = NULL ;
struct V_1 * V_2 = F_89 ( V_9 ) ;
int V_1165 = V_2 -> V_306 + V_2 -> V_635 ;
unsigned int V_703 ;
int V_474 , V_17 ;
if ( V_1165 >= V_1166 )
return F_620 ( - V_560 ) ;
#ifdef F_621
if ( V_628 -> V_94 != V_628 -> V_78 ) {
F_604 ( V_9 , L_143 ,
V_628 -> V_54 ) ;
return F_620 ( - V_560 ) ;
}
#endif
if ( V_628 -> V_78 > V_761 ||
V_628 -> V_78 == V_1167 ) {
F_604 ( V_9 ,
L_144 ,
V_9 -> V_54 ) ;
return F_620 ( - V_560 ) ;
}
if ( ( ( V_2 -> V_140 & V_141 ) &&
V_2 -> V_635 > V_1131 - 1 ) ||
( V_2 -> V_635 > V_1168 ) )
return F_620 ( - V_758 ) ;
V_1070 = F_404 ( sizeof( * V_1070 ) , V_752 ) ;
if ( ! V_1070 )
return F_620 ( - V_549 ) ;
V_474 = F_596 ( & V_2 -> V_634 , 32 ) ;
V_2 -> V_635 ++ ;
F_250 ( V_474 , & V_2 -> V_634 ) ;
V_703 = F_622 ( & V_2 -> V_634 , 32 ) ;
V_2 -> V_140 |= V_581 | V_412 ;
V_2 -> V_417 [ V_494 ] . V_703 = V_703 + 1 ;
V_2 -> V_417 [ V_418 ] . V_703 = V_628 -> V_78 ;
V_17 = F_595 ( V_9 , F_254 ( V_9 ) ) ;
if ( V_17 )
goto V_1169;
V_1070 -> V_474 = V_474 ;
V_1070 -> V_149 = V_2 ;
V_17 = F_359 ( V_628 , V_1070 ) ;
if ( V_17 )
goto V_1169;
F_623 ( V_628 ) ;
return V_1070 ;
V_1169:
F_604 ( V_9 ,
L_145 , V_628 -> V_54 ) ;
F_34 ( V_474 , & V_2 -> V_634 ) ;
V_2 -> V_635 -- ;
F_241 ( V_1070 ) ;
return F_620 ( V_17 ) ;
}
static void F_624 ( struct V_55 * V_9 , void * V_1170 )
{
struct V_624 * V_1070 = V_1170 ;
struct V_1 * V_2 = V_1070 -> V_149 ;
unsigned int V_703 ;
F_34 ( V_1070 -> V_474 , & V_2 -> V_634 ) ;
V_2 -> V_635 -- ;
V_703 = F_622 ( & V_2 -> V_634 , 32 ) ;
V_2 -> V_417 [ V_494 ] . V_703 = V_703 + 1 ;
F_357 ( V_1070 -> V_56 , V_1070 ) ;
F_595 ( V_9 , F_254 ( V_9 ) ) ;
F_360 ( V_9 , L_90 ,
V_1070 -> V_474 , V_2 -> V_635 ,
V_1070 -> V_627 ,
V_1070 -> V_627 + V_2 -> V_626 ,
V_2 -> V_634 ) ;
F_241 ( V_1070 ) ;
}
static T_17
F_625 ( struct V_196 * V_90 , struct V_55 * V_74 ,
T_17 V_198 )
{
if ( ! V_90 -> V_219 )
return V_198 ;
if ( F_24 ( F_626 ( V_90 ) - F_534 ( V_90 ) >
V_1171 ) )
return V_198 & ~ V_1172 ;
return V_198 ;
}
static inline int F_627 ( struct V_1 * V_2 )
{
struct V_5 * V_388 , * V_9 = V_2 -> V_9 ;
int V_1173 = 0 ;
if ( F_8 ( & V_2 -> V_14 ) )
V_1173 = 4 ;
F_628 (entry, &adapter->pdev->bus->devices, bus_list) {
if ( V_388 -> V_955 )
continue;
if ( ( V_388 -> V_696 != V_9 -> V_696 ) ||
( V_388 -> V_191 != V_9 -> V_191 ) )
return - 1 ;
V_1173 ++ ;
}
return V_1173 ;
}
int F_629 ( struct V_1 * V_2 , T_2 V_21 ,
T_2 V_1174 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1175 = V_2 -> V_1176 & V_1177 ;
int V_1178 = 0 ;
switch ( V_21 ) {
case V_1179 :
switch ( V_1174 ) {
case V_1180 :
case V_1181 :
if ( V_14 -> V_10 . V_1182 != 0 )
break;
case V_1183 :
case V_1184 :
case V_1185 :
case V_1186 :
case V_1187 :
V_1178 = 1 ;
break;
}
break;
case V_1188 :
switch ( V_1174 ) {
case V_1189 :
V_1178 = 1 ;
break;
}
break;
case V_1190 :
if ( V_1174 != V_1191 )
V_1178 = 1 ;
break;
case V_1192 :
V_1178 = 1 ;
break;
case V_1193 :
case V_1194 :
case V_1195 :
case V_1196 :
case V_1197 :
case V_1198 :
if ( ( V_1175 == V_1199 ) ||
( ( V_1175 == V_1200 ) &&
( V_14 -> V_10 . V_1182 == 0 ) ) ) {
V_1178 = 1 ;
}
break;
}
return V_1178 ;
}
static void F_630 ( struct V_1 * V_2 )
{
#ifdef F_631
struct V_1201 * V_1202 = F_632 ( V_2 -> V_9 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
const unsigned char * V_554 ;
V_554 = F_633 ( V_1202 ) ;
if ( V_554 ) {
F_310 ( V_14 -> V_109 . V_1203 , V_554 ) ;
return;
}
#endif
#ifdef F_634
F_310 ( V_14 -> V_109 . V_1203 , V_1204 -> V_1205 ) ;
#endif
}
static int F_635 ( struct V_5 * V_9 , const struct V_1206 * V_1207 )
{
struct V_55 * V_56 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_14 ;
const struct V_1208 * V_1209 = V_1210 [ V_1207 -> V_1211 ] ;
int V_49 , V_17 , V_1212 , V_24 ;
unsigned int V_419 = V_1213 ;
T_4 V_1214 [ V_1215 ] ;
bool V_1216 = false ;
#ifdef F_175
T_2 V_1217 ;
#endif
T_1 V_1218 ;
if ( V_9 -> V_955 ) {
F_636 ( 1 , V_1219 L_146 ,
F_498 ( V_9 ) , V_9 -> V_696 , V_9 -> V_191 ) ;
return - V_560 ;
}
V_17 = F_441 ( V_9 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_637 ( & V_9 -> V_74 , F_249 ( 64 ) ) ) {
V_1212 = 1 ;
} else {
V_17 = F_637 ( & V_9 -> V_74 , F_249 ( 32 ) ) ;
if ( V_17 ) {
F_417 ( & V_9 -> V_74 ,
L_147 ) ;
goto V_1220;
}
V_1212 = 0 ;
}
V_17 = F_638 ( V_9 , F_639 ( V_9 ,
V_1221 ) , V_1222 ) ;
if ( V_17 ) {
F_417 ( & V_9 -> V_74 ,
L_148 , V_17 ) ;
goto V_1223;
}
F_640 ( V_9 ) ;
F_442 ( V_9 ) ;
F_440 ( V_9 ) ;
if ( V_1209 -> V_109 == V_110 ) {
#ifdef F_369
V_419 = 4 * V_608 ;
#else
V_419 = V_1224 ;
#endif
}
V_56 = F_641 ( sizeof( struct V_1 ) , V_419 ) ;
if ( ! V_56 ) {
V_17 = - V_549 ;
goto V_1225;
}
F_642 ( V_56 , & V_9 -> V_74 ) ;
V_2 = F_89 ( V_56 ) ;
V_2 -> V_56 = V_56 ;
V_2 -> V_9 = V_9 ;
V_14 = & V_2 -> V_14 ;
V_14 -> V_39 = V_2 ;
V_2 -> V_1226 = F_643 ( V_1227 , V_1228 ) ;
V_14 -> V_40 = F_644 ( F_645 ( V_9 , 0 ) ,
F_646 ( V_9 , 0 ) ) ;
V_2 -> V_401 = V_14 -> V_40 ;
if ( ! V_14 -> V_40 ) {
V_17 = - V_748 ;
goto V_1229;
}
V_56 -> V_1230 = & V_1231 ;
F_647 ( V_56 ) ;
V_56 -> V_1232 = 5 * V_970 ;
F_648 ( V_56 -> V_54 , F_498 ( V_9 ) , sizeof( V_56 -> V_54 ) ) ;
memcpy ( & V_14 -> V_109 . V_339 , V_1209 -> V_1233 , sizeof( V_14 -> V_109 . V_339 ) ) ;
V_14 -> V_109 . type = V_1209 -> V_109 ;
V_14 -> V_1234 = V_1209 -> V_1234 ;
memcpy ( & V_14 -> V_1235 . V_339 , V_1209 -> V_1236 , sizeof( V_14 -> V_1235 . V_339 ) ) ;
V_1218 = F_37 ( V_14 , F_649 ( V_14 ) ) ;
if ( F_22 ( V_14 -> V_40 ) ) {
V_17 = - V_748 ;
goto V_1229;
}
if ( ! ( V_1218 & ( 1 << 8 ) ) )
V_14 -> V_1235 . V_339 . V_237 = & V_1237 ;
memcpy ( & V_14 -> V_342 . V_339 , V_1209 -> V_1238 , sizeof( V_14 -> V_342 . V_339 ) ) ;
V_14 -> V_342 . V_966 = V_1239 ;
V_14 -> V_342 . V_1108 . V_1105 = V_1240 ;
V_14 -> V_342 . V_1108 . V_1241 = 0 ;
V_14 -> V_342 . V_1108 . V_1242 = V_1243 | V_1244 ;
V_14 -> V_342 . V_1108 . V_74 = V_56 ;
V_14 -> V_342 . V_1108 . V_1245 = F_574 ;
V_14 -> V_342 . V_1108 . V_1246 = F_575 ;
V_1209 -> V_1247 ( V_14 ) ;
V_17 = F_401 ( V_2 ) ;
if ( V_17 )
goto V_1248;
switch ( V_2 -> V_14 . V_109 . type ) {
case V_112 :
case V_113 :
case V_114 :
case V_115 :
F_71 ( & V_2 -> V_14 , V_766 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_140 & V_346 ) {
T_1 V_669 = F_37 ( V_14 , V_670 ) ;
if ( V_669 & V_671 )
F_208 ( V_173 , L_71 ) ;
}
if ( V_1249 )
V_14 -> V_1249 = V_1249 ;
V_14 -> V_342 . V_1250 = true ;
V_17 = V_14 -> V_109 . V_339 . V_1251 ( V_14 ) ;
V_14 -> V_342 . V_1250 = false ;
if ( V_17 == V_678 &&
V_14 -> V_109 . type == V_110 ) {
V_17 = 0 ;
} else if ( V_17 == V_679 ) {
F_18 ( L_149 ) ;
F_18 ( L_150 ) ;
goto V_1248;
} else if ( V_17 ) {
F_18 ( L_151 , V_17 ) ;
goto V_1248;
}
#ifdef F_299
if ( V_2 -> V_14 . V_109 . type == V_110 )
goto V_1252;
F_650 ( V_14 ) ;
memcpy ( & V_14 -> V_1253 . V_339 , V_1209 -> V_1254 , sizeof( V_14 -> V_1253 . V_339 ) ) ;
F_651 ( V_9 , V_740 ) ;
F_652 ( V_2 ) ;
V_1252:
#endif
V_56 -> V_198 = V_1255 |
V_1256 |
V_1257 |
V_1258 |
V_248 |
V_1259 |
V_1260 |
V_199 |
V_216 ;
V_56 -> V_1261 = V_56 -> V_198 | V_1262 ;
switch ( V_2 -> V_14 . V_109 . type ) {
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_56 -> V_198 |= V_1263 ;
V_56 -> V_1261 |= V_1263 |
V_1138 ;
break;
default:
break;
}
V_56 -> V_1261 |= V_273 ;
V_56 -> V_198 |= V_1264 ;
V_56 -> V_1265 |= V_1259 ;
V_56 -> V_1265 |= V_1260 ;
V_56 -> V_1265 |= V_1256 ;
V_56 -> V_1265 |= V_1257 ;
V_56 -> V_1265 |= V_1255 ;
V_56 -> V_1266 |= V_1255 | V_1256 |
V_1257 ;
V_56 -> V_1267 |= V_1268 ;
V_56 -> V_1267 |= V_1269 ;
#ifdef F_326
switch ( V_2 -> V_14 . V_109 . type ) {
case V_114 :
case V_115 :
V_56 -> V_1266 |= V_216 |
V_1256 |
V_1257 ;
break;
default:
break;
}
#endif
#ifdef F_369
V_56 -> V_1270 = & V_1270 ;
#endif
#ifdef F_175
if ( V_2 -> V_140 & V_710 ) {
unsigned int V_1271 ;
if ( V_14 -> V_109 . V_339 . V_1272 ) {
V_14 -> V_109 . V_339 . V_1272 ( V_14 , & V_1217 ) ;
if ( V_1217 & V_1273 )
V_2 -> V_140 &= ~ V_710 ;
}
V_1271 = F_361 ( int , V_1274 , F_403 () ) ;
V_2 -> V_417 [ V_1076 ] . V_703 = V_1271 ;
V_56 -> V_198 |= V_1097 |
V_1098 ;
V_56 -> V_1265 |= V_1097 |
V_1098 |
V_588 ;
}
#endif
if ( V_1212 ) {
V_56 -> V_198 |= V_1275 ;
V_56 -> V_1265 |= V_1275 ;
}
if ( V_2 -> V_155 & V_704 )
V_56 -> V_1261 |= V_1134 ;
if ( V_2 -> V_155 & V_523 )
V_56 -> V_198 |= V_1134 ;
if ( V_14 -> V_1235 . V_339 . V_1276 ( V_14 , NULL ) < 0 ) {
F_18 ( L_152 ) ;
V_17 = - V_748 ;
goto V_1248;
}
F_630 ( V_2 ) ;
memcpy ( V_56 -> V_637 , V_14 -> V_109 . V_1203 , V_56 -> V_682 ) ;
if ( ! F_364 ( V_56 -> V_637 ) ) {
F_18 ( L_153 ) ;
V_17 = - V_748 ;
goto V_1248;
}
F_307 ( V_2 , V_14 -> V_109 . V_1203 ) ;
F_653 ( & V_2 -> V_672 , & F_508 ,
( unsigned long ) V_2 ) ;
if ( F_22 ( V_14 -> V_40 ) ) {
V_17 = - V_748 ;
goto V_1248;
}
F_654 ( & V_2 -> V_38 , F_512 ) ;
F_250 ( V_41 , & V_2 -> V_35 ) ;
F_34 ( V_37 , & V_2 -> V_35 ) ;
V_17 = F_445 ( V_2 ) ;
if ( V_17 )
goto V_1248;
V_2 -> V_686 = 0 ;
V_14 -> V_1235 . V_339 . V_237 ( V_14 , 0x2c , & V_2 -> V_1176 ) ;
V_14 -> V_1277 = F_629 ( V_2 , V_9 -> V_191 ,
V_9 -> V_702 ) ;
if ( V_14 -> V_1277 )
V_2 -> V_686 = V_1278 ;
F_655 ( & V_2 -> V_9 -> V_74 , V_2 -> V_686 ) ;
V_14 -> V_1235 . V_339 . V_237 ( V_14 , 0x2e , & V_2 -> V_1279 ) ;
V_14 -> V_1235 . V_339 . V_237 ( V_14 , 0x2d , & V_2 -> V_1280 ) ;
if ( F_8 ( V_14 ) )
F_5 ( V_2 ) ;
else
V_14 -> V_109 . V_339 . V_1281 ( V_14 ) ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
V_24 = F_656 ( F_627 ( V_2 ) * 10 , 16 ) ;
break;
default:
V_24 = F_627 ( V_2 ) * 10 ;
break;
}
if ( V_24 > 0 )
F_9 ( V_2 , V_24 ) ;
V_17 = F_657 ( V_14 , V_1214 , sizeof( V_1214 ) ) ;
if ( V_17 )
F_648 ( V_1214 , L_7 , sizeof( V_1214 ) ) ;
if ( F_212 ( V_14 ) && V_14 -> V_342 . V_966 != V_1282 )
F_12 ( L_154 ,
V_14 -> V_109 . type , V_14 -> V_342 . type , V_14 -> V_342 . V_966 ,
V_1214 ) ;
else
F_12 ( L_155 ,
V_14 -> V_109 . type , V_14 -> V_342 . type , V_1214 ) ;
F_12 ( L_156 , V_56 -> V_637 ) ;
V_17 = V_14 -> V_109 . V_339 . V_1283 ( V_14 ) ;
if ( V_17 == V_681 ) {
F_11 ( L_93
L_157
L_158
L_159
L_97
L_98 ) ;
}
strcpy ( V_56 -> V_54 , L_160 ) ;
V_17 = F_658 ( V_56 ) ;
if ( V_17 )
goto V_1284;
F_659 ( V_9 , V_2 ) ;
if ( V_14 -> V_109 . V_339 . V_691 )
V_14 -> V_109 . V_339 . V_691 ( V_14 ) ;
F_394 ( V_56 ) ;
#ifdef F_232
if ( F_126 ( & V_9 -> V_74 ) == 0 ) {
V_2 -> V_140 |= V_188 ;
F_123 ( V_2 ) ;
}
#endif
if ( V_2 -> V_140 & V_412 ) {
F_105 ( V_173 , L_161 , V_2 -> V_306 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_306 ; V_49 ++ )
F_660 ( V_9 , ( V_49 | 0x10000000 ) ) ;
}
if ( V_14 -> V_109 . V_339 . V_1285 )
V_14 -> V_109 . V_339 . V_1285 ( V_14 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_581 ( V_56 ) ;
F_12 ( L_70 , V_1286 ) ;
#ifdef F_661
if ( F_662 ( V_2 ) )
F_103 ( V_173 , L_162 ) ;
#endif
F_663 ( V_2 ) ;
if ( F_664 ( V_14 ) && F_212 ( V_14 ) && V_14 -> V_109 . V_339 . V_651 )
V_14 -> V_109 . V_339 . V_651 ( V_14 ,
V_914 | V_939 ,
true ) ;
return 0 ;
V_1284:
F_70 ( V_2 ) ;
F_451 ( V_2 ) ;
V_1248:
F_665 ( V_2 ) ;
V_2 -> V_155 &= ~ V_645 ;
F_666 ( V_2 -> V_401 ) ;
F_241 ( V_2 -> V_551 ) ;
V_1229:
V_1216 = ! F_15 ( V_765 , & V_2 -> V_35 ) ;
F_667 ( V_56 ) ;
V_1225:
F_668 ( V_9 ,
F_639 ( V_9 , V_1221 ) ) ;
V_1223:
V_1220:
if ( ! V_2 || V_1216 )
F_452 ( V_9 ) ;
return V_17 ;
}
static void F_669 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_437 ( V_9 ) ;
struct V_55 * V_56 ;
bool V_1216 ;
if ( ! V_2 )
return;
V_56 = V_2 -> V_56 ;
F_670 ( V_2 ) ;
F_250 ( V_36 , & V_2 -> V_35 ) ;
F_671 ( & V_2 -> V_38 ) ;
#ifdef F_232
if ( V_2 -> V_140 & V_188 ) {
V_2 -> V_140 &= ~ V_188 ;
F_127 ( & V_9 -> V_74 ) ;
F_71 ( & V_2 -> V_14 , V_189 , 1 ) ;
}
#endif
#ifdef F_661
F_672 ( V_2 ) ;
#endif
F_583 ( V_56 ) ;
if ( V_56 -> V_967 == V_968 )
F_506 ( V_56 ) ;
#ifdef F_299
F_665 ( V_2 ) ;
#endif
F_451 ( V_2 ) ;
F_70 ( V_2 ) ;
#ifdef F_673
F_241 ( V_2 -> V_139 ) ;
F_241 ( V_2 -> V_593 ) ;
#endif
F_666 ( V_2 -> V_401 ) ;
F_668 ( V_9 , F_639 ( V_9 ,
V_1221 ) ) ;
F_12 ( L_163 ) ;
F_241 ( V_2 -> V_551 ) ;
V_1216 = ! F_15 ( V_765 , & V_2 -> V_35 ) ;
F_667 ( V_56 ) ;
F_674 ( V_9 ) ;
if ( V_1216 )
F_452 ( V_9 ) ;
}
static T_20 F_675 ( struct V_5 * V_9 ,
T_21 V_35 )
{
struct V_1 * V_2 = F_437 ( V_9 ) ;
struct V_55 * V_56 = V_2 -> V_56 ;
#ifdef F_299
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_1287 , * V_946 ;
T_1 V_1288 , V_1289 , V_1290 , V_1291 ;
int V_1292 , V_950 ;
T_2 V_1293 , V_1294 ;
if ( V_2 -> V_14 . V_109 . type == V_110 ||
V_2 -> V_306 == 0 )
goto V_1295;
V_1287 = V_9 -> V_10 -> V_12 ;
while ( V_1287 && ( F_676 ( V_1287 ) != V_1296 ) )
V_1287 = V_1287 -> V_10 -> V_12 ;
if ( ! V_1287 )
goto V_1295;
V_950 = F_501 ( V_1287 , V_1297 ) ;
if ( ! V_950 )
goto V_1295;
V_1288 = F_27 ( V_14 , V_950 + V_1298 ) ;
V_1289 = F_27 ( V_14 , V_950 + V_1298 + 4 ) ;
V_1290 = F_27 ( V_14 , V_950 + V_1298 + 8 ) ;
V_1291 = F_27 ( V_14 , V_950 + V_1298 + 12 ) ;
if ( F_22 ( V_14 -> V_40 ) )
goto V_1295;
V_1293 = V_1289 >> 16 ;
if ( ! ( V_1293 & 0x0080 ) )
goto V_1295;
V_1294 = V_1293 & 0x01 ;
if ( ( V_1294 & 1 ) == ( V_9 -> V_1299 & 1 ) ) {
unsigned int V_21 ;
V_1292 = ( V_1293 & 0x7F ) >> 1 ;
F_18 ( L_164 , V_1292 ) ;
F_18 ( L_165
L_166 ,
V_1288 , V_1289 , V_1290 , V_1291 ) ;
switch ( V_2 -> V_14 . V_109 . type ) {
case V_112 :
V_21 = V_1300 ;
break;
case V_113 :
V_21 = V_1301 ;
break;
case V_114 :
V_21 = V_1302 ;
break;
case V_115 :
V_21 = V_1303 ;
break;
default:
V_21 = 0 ;
break;
}
V_946 = F_502 ( V_1304 , V_21 , NULL ) ;
while ( V_946 ) {
if ( V_946 -> V_1299 == ( V_1293 & 0xFF ) )
break;
V_946 = F_502 ( V_1304 ,
V_21 , V_946 ) ;
}
if ( V_946 ) {
F_496 ( V_2 , V_946 ) ;
F_677 ( V_946 ) ;
}
F_678 ( V_9 ) ;
}
V_2 -> V_1305 ++ ;
return V_1306 ;
V_1295:
#endif
if ( ! F_14 ( V_41 , & V_2 -> V_35 ) )
return V_1307 ;
F_444 () ;
F_450 ( V_56 ) ;
if ( V_35 == V_1308 ) {
F_446 () ;
return V_1307 ;
}
if ( F_57 ( V_56 ) )
F_383 ( V_2 ) ;
if ( ! F_15 ( V_765 , & V_2 -> V_35 ) )
F_452 ( V_9 ) ;
F_446 () ;
return V_1309 ;
}
static T_20 F_679 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_437 ( V_9 ) ;
T_20 V_1310 ;
int V_17 ;
if ( F_441 ( V_9 ) ) {
F_103 ( V_173 , L_167 ) ;
V_1310 = V_1307 ;
} else {
F_33 () ;
F_34 ( V_765 , & V_2 -> V_35 ) ;
V_2 -> V_14 . V_40 = V_2 -> V_401 ;
F_442 ( V_9 ) ;
F_439 ( V_9 ) ;
F_440 ( V_9 ) ;
F_443 ( V_9 , false ) ;
F_386 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_766 , ~ 0 ) ;
V_1310 = V_1306 ;
}
V_17 = F_678 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_168
L_169 , V_17 ) ;
}
return V_1310 ;
}
static void F_680 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_437 ( V_9 ) ;
struct V_55 * V_56 = V_2 -> V_56 ;
#ifdef F_299
if ( V_2 -> V_1305 ) {
F_105 ( V_157 , L_170 ) ;
V_2 -> V_1305 -- ;
return;
}
#endif
if ( F_57 ( V_56 ) )
F_385 ( V_2 ) ;
F_447 ( V_56 ) ;
}
static int T_22 F_681 ( void )
{
int V_647 ;
F_51 ( L_171 , V_1311 , V_1312 ) ;
F_51 ( L_70 , V_1313 ) ;
F_682 () ;
V_647 = F_683 ( & V_1314 ) ;
if ( V_647 ) {
F_684 () ;
return V_647 ;
}
#ifdef F_232
F_685 ( & V_1315 ) ;
#endif
return 0 ;
}
static void T_23 F_686 ( void )
{
#ifdef F_232
F_687 ( & V_1315 ) ;
#endif
F_688 ( & V_1314 ) ;
F_684 () ;
}
static int F_689 ( struct V_1316 * V_1317 , unsigned long V_192 ,
void * V_1101 )
{
int V_1318 ;
V_1318 = F_690 ( & V_1314 . V_1319 , NULL , & V_192 ,
F_124 ) ;
return V_1318 ? V_1320 : V_1321 ;
}
