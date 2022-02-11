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
T_1 V_177 = 0 ;
T_2 V_178 ;
if ( V_2 -> V_140 & V_179 )
V_177 = F_115 ( V_59 -> V_74 , V_176 ) ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
V_178 = F_116 ( V_59 -> V_150 ) ;
break;
case V_112 :
case V_113 :
V_178 = F_117 ( V_59 -> V_150 ) ;
V_177 <<= V_180 ;
break;
default:
return;
}
V_177 |= V_181 |
V_182 |
V_183 ;
F_71 ( V_14 , V_178 , V_177 ) ;
}
static void F_118 ( struct V_1 * V_2 ,
struct V_58 * V_68 ,
int V_176 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_184 = 0 ;
T_4 V_150 = V_68 -> V_150 ;
if ( V_2 -> V_140 & V_179 )
V_184 = F_115 ( V_68 -> V_74 , V_176 ) ;
switch ( V_14 -> V_109 . type ) {
case V_112 :
case V_113 :
V_184 <<= V_185 ;
break;
default:
break;
}
V_184 |= V_186 |
V_187 |
V_188 ;
F_71 ( V_14 , F_38 ( V_150 ) , V_184 ) ;
}
static void F_119 ( struct V_158 * V_159 )
{
struct V_1 * V_2 = V_159 -> V_2 ;
struct V_58 * V_121 ;
int V_176 = F_120 () ;
if ( V_159 -> V_176 == V_176 )
goto V_189;
F_121 (ring, q_vector->tx)
F_114 ( V_2 , V_121 , V_176 ) ;
F_121 (ring, q_vector->rx)
F_118 ( V_2 , V_121 , V_176 ) ;
V_159 -> V_176 = V_176 ;
V_189:
F_122 () ;
}
static void F_123 ( struct V_1 * V_2 )
{
int V_49 ;
if ( V_2 -> V_140 & V_179 )
F_71 ( & V_2 -> V_14 , V_190 ,
V_191 ) ;
else
F_71 ( & V_2 -> V_14 , V_190 ,
V_192 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_193 ; V_49 ++ ) {
V_2 -> V_159 [ V_49 ] -> V_176 = - 1 ;
F_119 ( V_2 -> V_159 [ V_49 ] ) ;
}
}
static int F_124 ( struct V_194 * V_74 , void * V_93 )
{
struct V_1 * V_2 = F_125 ( V_74 ) ;
unsigned long V_195 = * ( unsigned long * ) V_93 ;
if ( ! ( V_2 -> V_140 & V_196 ) )
return 0 ;
switch ( V_195 ) {
case V_197 :
if ( V_2 -> V_140 & V_179 )
break;
if ( F_126 ( V_74 ) == 0 ) {
V_2 -> V_140 |= V_179 ;
F_71 ( & V_2 -> V_14 , V_190 ,
V_191 ) ;
break;
}
case V_198 :
if ( V_2 -> V_140 & V_179 ) {
F_127 ( V_74 ) ;
V_2 -> V_140 &= ~ V_179 ;
F_71 ( & V_2 -> V_14 , V_190 ,
V_192 ) ;
}
break;
}
return 0 ;
}
static inline void F_128 ( struct V_58 * V_121 ,
union V_69 * V_70 ,
struct V_199 * V_90 )
{
T_2 V_200 ;
if ( ! ( V_121 -> V_56 -> V_201 & V_202 ) )
return;
V_200 = F_129 ( V_70 -> V_95 . V_203 . V_204 . V_205 . V_206 ) &
V_207 ;
if ( ! V_200 )
return;
F_130 ( V_90 , F_67 ( V_70 -> V_95 . V_203 . V_208 . V_209 ) ,
( V_210 & ( 1ul << V_200 ) ) ?
V_211 : V_212 ) ;
}
static inline bool F_131 ( struct V_58 * V_121 ,
union V_69 * V_70 )
{
T_8 V_206 = V_70 -> V_95 . V_203 . V_204 . V_205 . V_206 ;
return F_14 ( V_213 , & V_121 -> V_35 ) &&
( ( V_206 & F_132 ( V_214 ) ) ==
( F_132 ( V_215 <<
V_216 ) ) ) ;
}
static inline void F_133 ( struct V_58 * V_121 ,
union V_69 * V_70 ,
struct V_199 * V_90 )
{
T_8 V_206 = V_70 -> V_95 . V_203 . V_204 . V_205 . V_206 ;
T_8 V_217 = V_70 -> V_95 . V_203 . V_204 . V_205 . V_217 ;
bool V_218 = false ;
F_134 ( V_90 ) ;
if ( ! ( V_121 -> V_56 -> V_201 & V_219 ) )
return;
if ( ( V_206 & F_132 ( V_220 ) ) &&
( V_217 & F_132 ( V_221 >> 16 ) ) ) {
V_218 = true ;
V_90 -> V_222 = 1 ;
}
if ( F_135 ( V_70 , V_223 ) &&
F_135 ( V_70 , V_224 ) ) {
V_121 -> V_225 . V_226 ++ ;
return;
}
if ( ! F_135 ( V_70 , V_227 ) )
return;
if ( F_135 ( V_70 , V_228 ) ) {
if ( ( V_206 & F_132 ( V_229 ) ) &&
F_14 ( V_230 , & V_121 -> V_35 ) )
return;
V_121 -> V_225 . V_226 ++ ;
return;
}
V_90 -> V_231 = V_232 ;
if ( V_218 ) {
if ( ! F_135 ( V_70 , V_233 ) )
return;
if ( F_135 ( V_70 , V_234 ) ) {
V_121 -> V_225 . V_226 ++ ;
return;
}
V_90 -> V_235 = 1 ;
}
}
static bool F_136 ( struct V_58 * V_68 ,
struct V_71 * V_236 )
{
struct V_99 * V_99 = V_236 -> V_99 ;
T_9 V_82 ;
if ( F_99 ( V_99 ) )
return true ;
V_99 = F_137 ( F_138 ( V_68 ) ) ;
if ( F_24 ( ! V_99 ) ) {
V_68 -> V_225 . V_237 ++ ;
return false ;
}
V_82 = F_139 ( V_68 -> V_74 , V_99 , 0 ,
F_140 ( V_68 ) , V_238 ) ;
if ( F_141 ( V_68 -> V_74 , V_82 ) ) {
F_142 ( V_99 , F_138 ( V_68 ) ) ;
V_68 -> V_225 . V_237 ++ ;
return false ;
}
V_236 -> V_82 = V_82 ;
V_236 -> V_99 = V_99 ;
V_236 -> V_100 = 0 ;
return true ;
}
void F_143 ( struct V_58 * V_68 , T_2 V_239 )
{
union V_69 * V_70 ;
struct V_71 * V_236 ;
T_2 V_49 = V_68 -> V_81 ;
if ( ! V_239 )
return;
V_70 = F_66 ( V_68 , V_49 ) ;
V_236 = & V_68 -> V_72 [ V_49 ] ;
V_49 -= V_68 -> V_89 ;
do {
if ( ! F_136 ( V_68 , V_236 ) )
break;
V_70 -> V_240 . V_241 = F_144 ( V_236 -> V_82 + V_236 -> V_100 ) ;
V_70 ++ ;
V_236 ++ ;
V_49 ++ ;
if ( F_24 ( ! V_49 ) ) {
V_70 = F_66 ( V_68 , 0 ) ;
V_236 = V_68 -> V_72 ;
V_49 -= V_68 -> V_89 ;
}
V_70 -> V_95 . V_96 . V_97 = 0 ;
V_239 -- ;
} while ( V_239 );
V_49 += V_68 -> V_89 ;
if ( V_68 -> V_81 != V_49 ) {
V_68 -> V_81 = V_49 ;
V_68 -> V_242 = V_49 ;
F_145 () ;
F_146 ( V_49 , V_68 -> V_147 ) ;
}
}
static void F_147 ( struct V_58 * V_121 ,
struct V_199 * V_90 )
{
T_2 V_243 = F_148 ( V_90 ) ;
F_149 ( V_90 ) -> V_244 = F_150 ( ( V_90 -> V_83 - V_243 ) ,
F_151 ( V_90 ) -> V_245 ) ;
F_149 ( V_90 ) -> V_246 = V_247 ;
}
static void F_152 ( struct V_58 * V_68 ,
struct V_199 * V_90 )
{
if ( ! F_151 ( V_90 ) -> V_245 )
return;
V_68 -> V_225 . V_248 += F_151 ( V_90 ) -> V_245 ;
V_68 -> V_225 . V_249 ++ ;
F_147 ( V_68 , V_90 ) ;
F_151 ( V_90 ) -> V_245 = 0 ;
}
static void F_153 ( struct V_58 * V_68 ,
union V_69 * V_70 ,
struct V_199 * V_90 )
{
struct V_55 * V_74 = V_68 -> V_56 ;
F_152 ( V_68 , V_90 ) ;
F_128 ( V_68 , V_70 , V_90 ) ;
F_133 ( V_68 , V_70 , V_90 ) ;
if ( F_24 ( F_135 ( V_70 , V_250 ) ) )
F_154 ( V_68 -> V_159 -> V_2 , V_90 ) ;
if ( ( V_74 -> V_201 & V_251 ) &&
F_135 ( V_70 , V_252 ) ) {
T_2 V_253 = F_129 ( V_70 -> V_95 . V_96 . V_254 ) ;
F_155 ( V_90 , F_156 ( V_255 ) , V_253 ) ;
}
F_157 ( V_90 , V_68 -> V_87 ) ;
V_90 -> V_256 = F_158 ( V_90 , V_74 ) ;
}
static void F_159 ( struct V_158 * V_159 ,
struct V_199 * V_90 )
{
if ( F_160 ( V_159 ) )
F_161 ( V_90 ) ;
else
F_162 ( & V_159 -> V_257 , V_90 ) ;
}
static bool F_163 ( struct V_58 * V_68 ,
union V_69 * V_70 ,
struct V_199 * V_90 )
{
T_1 V_258 = V_68 -> V_80 + 1 ;
V_258 = ( V_258 < V_68 -> V_89 ) ? V_258 : 0 ;
V_68 -> V_80 = V_258 ;
F_98 ( F_66 ( V_68 , V_258 ) ) ;
if ( F_164 ( V_68 ) ) {
T_10 V_259 = V_70 -> V_95 . V_203 . V_204 . V_93 &
F_96 ( V_260 ) ;
if ( F_24 ( V_259 ) ) {
T_1 V_261 = F_67 ( V_259 ) ;
V_261 >>= V_262 ;
F_151 ( V_90 ) -> V_245 += V_261 - 1 ;
V_258 = F_67 ( V_70 -> V_95 . V_96 . V_97 ) ;
V_258 &= V_263 ;
V_258 >>= V_264 ;
}
}
if ( F_99 ( F_135 ( V_70 , V_265 ) ) )
return false ;
V_68 -> V_72 [ V_258 ] . V_90 = V_90 ;
V_68 -> V_225 . V_266 ++ ;
return true ;
}
static void F_165 ( struct V_58 * V_68 ,
struct V_199 * V_90 )
{
struct V_267 * V_268 = & F_149 ( V_90 ) -> V_269 [ 0 ] ;
unsigned char * V_270 ;
unsigned int V_271 ;
V_270 = F_166 ( V_268 ) ;
V_271 = F_167 ( V_270 , V_272 ) ;
F_168 ( V_90 , V_270 , F_169 ( V_271 , sizeof( long ) ) ) ;
F_170 ( V_268 , V_271 ) ;
V_268 -> V_100 += V_271 ;
V_90 -> V_273 -= V_271 ;
V_90 -> V_147 += V_271 ;
}
static void F_171 ( struct V_58 * V_68 ,
struct V_199 * V_90 )
{
if ( F_24 ( F_151 ( V_90 ) -> V_274 ) ) {
F_80 ( V_68 -> V_74 , F_151 ( V_90 ) -> V_82 ,
F_140 ( V_68 ) , V_238 ) ;
F_151 ( V_90 ) -> V_274 = false ;
} else {
struct V_267 * V_268 = & F_149 ( V_90 ) -> V_269 [ 0 ] ;
F_172 ( V_68 -> V_74 ,
F_151 ( V_90 ) -> V_82 ,
V_268 -> V_100 ,
F_69 ( V_68 ) ,
V_238 ) ;
}
F_151 ( V_90 ) -> V_82 = 0 ;
}
static bool F_173 ( struct V_58 * V_68 ,
union V_69 * V_70 ,
struct V_199 * V_90 )
{
struct V_55 * V_56 = V_68 -> V_56 ;
if ( F_24 ( F_135 ( V_70 ,
V_275 ) &&
! ( V_56 -> V_201 & V_276 ) ) ) {
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
struct V_71 * V_277 )
{
struct V_71 * V_278 ;
T_2 V_279 = V_68 -> V_242 ;
V_278 = & V_68 -> V_72 [ V_279 ] ;
V_279 ++ ;
V_68 -> V_242 = ( V_279 < V_68 -> V_89 ) ? V_279 : 0 ;
* V_278 = * V_277 ;
F_178 ( V_68 -> V_74 , V_278 -> V_82 ,
V_278 -> V_100 ,
F_69 ( V_68 ) ,
V_238 ) ;
}
static inline bool F_179 ( struct V_99 * V_99 )
{
return ( F_180 ( V_99 ) != F_181 () ) || F_182 ( V_99 ) ;
}
static bool F_183 ( struct V_58 * V_68 ,
struct V_71 * V_280 ,
union V_69 * V_70 ,
struct V_199 * V_90 )
{
struct V_99 * V_99 = V_280 -> V_99 ;
unsigned int V_281 = F_129 ( V_70 -> V_95 . V_96 . V_282 ) ;
#if ( V_283 < 8192 )
unsigned int V_284 = F_69 ( V_68 ) ;
#else
unsigned int V_284 = F_169 ( V_281 , V_285 ) ;
unsigned int V_286 = F_140 ( V_68 ) -
F_69 ( V_68 ) ;
#endif
if ( ( V_281 <= V_272 ) && ! F_174 ( V_90 ) ) {
unsigned char * V_270 = F_68 ( V_99 ) + V_280 -> V_100 ;
memcpy ( F_184 ( V_90 , V_281 ) , V_270 , F_169 ( V_281 , sizeof( long ) ) ) ;
if ( F_99 ( ! F_179 ( V_99 ) ) )
return true ;
F_142 ( V_99 , F_138 ( V_68 ) ) ;
return false ;
}
F_185 ( V_90 , F_149 ( V_90 ) -> V_287 , V_99 ,
V_280 -> V_100 , V_281 , V_284 ) ;
if ( F_24 ( F_179 ( V_99 ) ) )
return false ;
#if ( V_283 < 8192 )
if ( F_24 ( F_186 ( V_99 ) != 1 ) )
return false ;
V_280 -> V_100 ^= V_284 ;
#else
V_280 -> V_100 += V_284 ;
if ( V_280 -> V_100 > V_286 )
return false ;
#endif
F_187 ( & V_99 -> V_288 ) ;
return true ;
}
static struct V_199 * F_188 ( struct V_58 * V_68 ,
union V_69 * V_70 )
{
struct V_71 * V_280 ;
struct V_199 * V_90 ;
struct V_99 * V_99 ;
V_280 = & V_68 -> V_72 [ V_68 -> V_80 ] ;
V_99 = V_280 -> V_99 ;
F_189 ( V_99 ) ;
V_90 = V_280 -> V_90 ;
if ( F_99 ( ! V_90 ) ) {
void * V_289 = F_68 ( V_99 ) +
V_280 -> V_100 ;
F_98 ( V_289 ) ;
#if V_285 < 128
F_98 ( V_289 + V_285 ) ;
#endif
V_90 = F_190 ( & V_68 -> V_159 -> V_257 ,
V_272 ) ;
if ( F_24 ( ! V_90 ) ) {
V_68 -> V_225 . V_290 ++ ;
return NULL ;
}
F_189 ( V_90 -> V_93 ) ;
if ( F_99 ( F_135 ( V_70 , V_265 ) ) )
goto V_291;
F_151 ( V_90 ) -> V_82 = V_280 -> V_82 ;
} else {
if ( F_135 ( V_70 , V_265 ) )
F_171 ( V_68 , V_90 ) ;
V_291:
F_172 ( V_68 -> V_74 ,
V_280 -> V_82 ,
V_280 -> V_100 ,
F_69 ( V_68 ) ,
V_238 ) ;
V_280 -> V_90 = NULL ;
}
if ( F_183 ( V_68 , V_280 , V_70 , V_90 ) ) {
F_177 ( V_68 , V_280 ) ;
} else if ( F_151 ( V_90 ) -> V_82 == V_280 -> V_82 ) {
F_151 ( V_90 ) -> V_274 = true ;
} else {
F_80 ( V_68 -> V_74 , V_280 -> V_82 ,
F_140 ( V_68 ) ,
V_238 ) ;
}
V_280 -> V_99 = NULL ;
return V_90 ;
}
static int F_191 ( struct V_158 * V_159 ,
struct V_58 * V_68 ,
const int V_162 )
{
unsigned int V_292 = 0 , V_293 = 0 ;
#ifdef F_175
struct V_1 * V_2 = V_159 -> V_2 ;
int V_294 ;
unsigned int V_295 = 0 ;
#endif
T_2 V_239 = F_110 ( V_68 ) ;
while ( F_99 ( V_293 < V_162 ) ) {
union V_69 * V_70 ;
struct V_199 * V_90 ;
if ( V_239 >= V_296 ) {
F_143 ( V_68 , V_239 ) ;
V_239 = 0 ;
}
V_70 = F_66 ( V_68 , V_68 -> V_80 ) ;
if ( ! V_70 -> V_95 . V_96 . V_97 )
break;
F_192 () ;
V_90 = F_188 ( V_68 , V_70 ) ;
if ( ! V_90 )
break;
V_239 ++ ;
if ( F_163 ( V_68 , V_70 , V_90 ) )
continue;
if ( F_173 ( V_68 , V_70 , V_90 ) )
continue;
V_292 += V_90 -> V_83 ;
F_153 ( V_68 , V_70 , V_90 ) ;
#ifdef F_175
if ( F_131 ( V_68 , V_70 ) ) {
V_294 = F_193 ( V_2 , V_70 , V_90 ) ;
if ( V_294 > 0 ) {
if ( ! V_295 ) {
V_295 = V_68 -> V_56 -> V_297 -
sizeof( struct V_298 ) -
sizeof( struct V_299 ) -
sizeof( struct V_300 ) ;
if ( V_295 > 512 )
V_295 &= ~ 511 ;
}
V_292 += V_294 ;
V_293 += F_150 ( V_294 ,
V_295 ) ;
}
if ( ! V_294 ) {
F_78 ( V_90 ) ;
continue;
}
}
#endif
F_194 ( V_90 , & V_159 -> V_257 ) ;
F_159 ( V_159 , V_90 ) ;
V_293 ++ ;
}
F_100 ( & V_68 -> V_170 ) ;
V_68 -> V_125 . V_145 += V_293 ;
V_68 -> V_125 . V_171 += V_292 ;
F_101 ( & V_68 -> V_170 ) ;
V_159 -> V_301 . V_161 += V_293 ;
V_159 -> V_301 . V_160 += V_292 ;
return V_293 ;
}
static int F_195 ( struct V_302 * V_257 )
{
struct V_158 * V_159 =
F_196 ( V_257 , struct V_158 , V_257 ) ;
struct V_1 * V_2 = V_159 -> V_2 ;
struct V_58 * V_121 ;
int V_303 = 0 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return V_304 ;
if ( ! F_197 ( V_159 ) )
return V_305 ;
F_121 (ring, q_vector->rx) {
V_303 = F_191 ( V_159 , V_121 , 4 ) ;
#ifdef F_198
if ( V_303 )
V_121 -> V_125 . V_306 += V_303 ;
else
V_121 -> V_125 . V_307 ++ ;
#endif
if ( V_303 )
break;
}
F_199 ( V_159 ) ;
return V_303 ;
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_158 * V_159 ;
int V_308 ;
T_1 V_118 ;
if ( V_2 -> V_309 > 32 ) {
T_1 V_310 = ( 1 << ( V_2 -> V_309 - 32 ) ) - 1 ;
F_71 ( & V_2 -> V_14 , V_311 , V_310 ) ;
}
for ( V_308 = 0 ; V_308 < V_2 -> V_193 ; V_308 ++ ) {
struct V_58 * V_121 ;
V_159 = V_2 -> V_159 [ V_308 ] ;
F_121 (ring, q_vector->rx)
F_73 ( V_2 , 0 , V_121 -> V_150 , V_308 ) ;
F_121 (ring, q_vector->tx)
F_73 ( V_2 , 1 , V_121 -> V_150 , V_308 ) ;
F_201 ( V_159 ) ;
}
switch ( V_2 -> V_14 . V_109 . type ) {
case V_110 :
F_73 ( V_2 , - 1 , V_312 ,
V_308 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
F_73 ( V_2 , - 1 , 1 , V_308 ) ;
break;
default:
break;
}
F_71 ( & V_2 -> V_14 , F_202 ( V_308 ) , 1950 ) ;
V_118 = V_313 ;
V_118 &= ~ ( V_314 |
V_315 |
V_316 ) ;
F_71 ( & V_2 -> V_14 , V_317 , V_118 ) ;
}
static void F_203 ( struct V_158 * V_159 ,
struct V_318 * V_319 )
{
int V_171 = V_319 -> V_160 ;
int V_145 = V_319 -> V_161 ;
T_1 V_320 ;
T_6 V_321 ;
T_4 V_322 = V_319 -> V_323 ;
if ( V_145 == 0 )
return;
V_320 = V_159 -> V_323 >> 2 ;
if ( V_320 == 0 )
return;
V_321 = V_171 / V_320 ;
switch ( V_322 ) {
case V_324 :
if ( V_321 > 10 )
V_322 = V_325 ;
break;
case V_325 :
if ( V_321 > 20 )
V_322 = V_326 ;
else if ( V_321 <= 10 )
V_322 = V_324 ;
break;
case V_326 :
if ( V_321 <= 20 )
V_322 = V_325 ;
break;
}
V_319 -> V_160 = 0 ;
V_319 -> V_161 = 0 ;
V_319 -> V_323 = V_322 ;
}
void F_201 ( struct V_158 * V_159 )
{
struct V_1 * V_2 = V_159 -> V_2 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_308 = V_159 -> V_308 ;
T_1 V_327 = V_159 -> V_323 & V_328 ;
switch ( V_2 -> V_14 . V_109 . type ) {
case V_110 :
V_327 |= ( V_327 << 16 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_327 |= V_329 ;
break;
default:
break;
}
F_71 ( V_14 , F_202 ( V_308 ) , V_327 ) ;
}
static void F_204 ( struct V_158 * V_159 )
{
T_1 V_330 = V_159 -> V_323 ;
T_4 V_331 ;
F_203 ( V_159 , & V_159 -> V_163 ) ;
F_203 ( V_159 , & V_159 -> V_301 ) ;
V_331 = F_205 ( V_159 -> V_301 . V_323 , V_159 -> V_163 . V_323 ) ;
switch ( V_331 ) {
case V_324 :
V_330 = V_332 ;
break;
case V_325 :
V_330 = V_333 ;
break;
case V_326 :
V_330 = V_334 ;
break;
default:
break;
}
if ( V_330 != V_159 -> V_323 ) {
V_330 = ( 10 * V_330 * V_159 -> V_323 ) /
( ( 9 * V_330 ) + V_159 -> V_323 ) ;
V_159 -> V_323 = V_330 ;
F_201 ( V_159 ) ;
}
}
static void F_206 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_335 = V_2 -> V_336 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
if ( ! ( V_2 -> V_155 & V_337 ) &&
! ( V_2 -> V_155 & V_338 ) )
return;
V_2 -> V_155 &= ~ V_338 ;
switch ( V_14 -> V_21 ) {
case V_339 :
if ( ! ( V_335 & V_340 ) &&
! ( V_335 & V_341 ) )
return;
if ( ! ( V_335 & V_341 ) && V_14 -> V_109 . V_342 . V_343 ) {
T_1 V_20 ;
bool V_344 = false ;
V_14 -> V_109 . V_342 . V_343 ( V_14 , & V_20 , & V_344 , false ) ;
if ( V_344 )
return;
}
if ( V_14 -> V_345 . V_342 . V_346 ( V_14 ) != V_347 )
return;
break;
default:
if ( V_2 -> V_14 . V_109 . type >= V_113 )
return;
if ( ! ( V_335 & F_207 ( V_14 ) ) )
return;
break;
}
F_208 ( V_157 , L_70 , V_348 ) ;
V_2 -> V_336 = 0 ;
}
static void F_209 ( struct V_1 * V_2 , T_1 V_335 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ( V_2 -> V_140 & V_349 ) &&
( V_335 & F_210 ( V_14 ) ) ) {
F_208 ( V_173 , L_71 ) ;
F_71 ( V_14 , V_350 , F_210 ( V_14 ) ) ;
}
}
static void F_211 ( struct V_1 * V_2 , T_1 V_335 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! ( V_2 -> V_155 & V_337 ) )
return;
switch ( V_2 -> V_14 . V_109 . type ) {
case V_112 :
if ( ( ( V_335 & F_207 ( V_14 ) ) ||
( V_335 & V_341 ) ) &&
( ! F_14 ( V_34 , & V_2 -> V_35 ) ) ) {
V_2 -> V_336 = V_335 ;
V_2 -> V_155 |= V_338 ;
F_13 ( V_2 ) ;
return;
}
return;
case V_113 :
if ( ! ( V_335 & V_351 ) )
return;
break;
default:
return;
}
F_208 ( V_157 , L_70 , V_348 ) ;
}
static inline bool F_212 ( struct V_15 * V_14 )
{
switch ( V_14 -> V_109 . type ) {
case V_110 :
if ( V_14 -> V_345 . type == V_352 )
return true ;
return false ;
case V_112 :
case V_115 :
switch ( V_14 -> V_109 . V_342 . V_353 ( V_14 ) ) {
case V_354 :
case V_355 :
return true ;
default:
return false ;
}
default:
return false ;
}
}
static void F_213 ( struct V_1 * V_2 , T_1 V_335 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_356 = F_214 ( V_14 ) ;
if ( ! F_212 ( V_14 ) )
return;
if ( V_14 -> V_109 . type >= V_113 )
V_356 = V_357 ;
if ( V_335 & V_356 ) {
F_71 ( V_14 , V_350 , V_356 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_155 |= V_358 ;
V_2 -> V_359 = 0 ;
F_13 ( V_2 ) ;
}
}
if ( V_2 -> V_14 . V_109 . type == V_112 &&
( V_335 & F_210 ( V_14 ) ) ) {
F_71 ( V_14 , V_350 , F_210 ( V_14 ) ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_140 |= V_360 ;
F_13 ( V_2 ) ;
}
}
}
static void F_215 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_361 ++ ;
V_2 -> V_140 |= V_362 ;
V_2 -> V_363 = V_172 ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_71 ( V_14 , V_364 , V_365 ) ;
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
F_71 ( V_14 , V_366 , V_118 ) ;
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
F_71 ( V_14 , V_364 , V_118 ) ;
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
static inline void F_221 ( struct V_1 * V_2 , bool V_367 ,
bool V_368 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_118 = ( V_313 & ~ V_119 ) ;
if ( V_2 -> V_140 & V_362 )
V_118 &= ~ V_316 ;
if ( V_2 -> V_155 & V_337 )
switch ( V_2 -> V_14 . V_109 . type ) {
case V_112 :
V_118 |= F_222 ( V_14 ) ;
break;
case V_113 :
case V_114 :
case V_115 :
V_118 |= V_369 ;
break;
default:
break;
}
if ( V_2 -> V_140 & V_349 )
V_118 |= F_223 ( V_14 ) ;
switch ( V_2 -> V_14 . V_109 . type ) {
case V_112 :
V_118 |= F_223 ( V_14 ) ;
V_118 |= F_224 ( V_14 ) ;
case V_113 :
case V_114 :
case V_115 :
if ( V_2 -> V_14 . V_21 == V_370 )
V_118 |= F_222 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_14 . V_345 . type == V_371 )
V_118 |= V_357 ;
V_118 |= V_372 ;
V_118 |= V_315 ;
break;
default:
break;
}
if ( ( V_2 -> V_140 & V_373 ) &&
! ( V_2 -> V_155 & V_374 ) )
V_118 |= V_375 ;
F_71 ( & V_2 -> V_14 , V_366 , V_118 ) ;
if ( V_367 )
F_217 ( V_2 , ~ 0 ) ;
if ( V_368 )
F_216 ( & V_2 -> V_14 ) ;
}
static T_11 F_225 ( int V_376 , void * V_93 )
{
struct V_1 * V_2 = V_93 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_335 ;
V_335 = F_37 ( V_14 , V_120 ) ;
V_335 &= 0xFFFF0000 ;
F_71 ( V_14 , V_350 , V_335 ) ;
if ( V_335 & V_341 )
F_215 ( V_2 ) ;
if ( V_335 & V_377 )
F_226 ( V_2 ) ;
switch ( V_14 -> V_109 . type ) {
case V_112 :
case V_113 :
case V_114 :
case V_115 :
if ( V_14 -> V_345 . type == V_371 &&
( V_335 & V_357 ) ) {
V_2 -> V_155 |= V_378 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_350 ,
V_357 ) ;
}
if ( V_335 & V_379 ) {
F_105 ( V_380 , L_72 ) ;
V_2 -> V_155 |= V_156 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_350 , V_379 ) ;
}
if ( V_335 & V_381 ) {
int V_382 = 0 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ ) {
struct V_58 * V_121 = V_2 -> V_59 [ V_49 ] ;
if ( F_227 ( V_383 ,
& V_121 -> V_35 ) )
V_382 ++ ;
}
if ( V_382 ) {
F_71 ( V_14 , V_364 , V_384 ) ;
V_2 -> V_155 |= V_374 ;
F_13 ( V_2 ) ;
}
}
F_213 ( V_2 , V_335 ) ;
F_211 ( V_2 , V_335 ) ;
break;
default:
break;
}
F_209 ( V_2 , V_335 ) ;
if ( F_24 ( V_335 & V_385 ) )
F_228 ( V_2 , V_335 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_221 ( V_2 , false , false ) ;
return V_386 ;
}
static T_11 F_229 ( int V_376 , void * V_93 )
{
struct V_158 * V_159 = V_93 ;
if ( V_159 -> V_301 . V_121 || V_159 -> V_163 . V_121 )
F_230 ( & V_159 -> V_257 ) ;
return V_386 ;
}
int F_231 ( struct V_302 * V_257 , int V_162 )
{
struct V_158 * V_159 =
F_196 ( V_257 , struct V_158 , V_257 ) ;
struct V_1 * V_2 = V_159 -> V_2 ;
struct V_58 * V_121 ;
int V_387 , V_388 = 0 ;
bool V_389 = true ;
#ifdef F_232
if ( V_2 -> V_140 & V_179 )
F_119 ( V_159 ) ;
#endif
F_121 (ring, q_vector->tx)
V_389 &= ! ! F_94 ( V_159 , V_121 ) ;
if ( ! F_233 ( V_159 ) )
return V_162 ;
if ( V_159 -> V_301 . V_89 > 1 )
V_387 = F_205 ( V_162 / V_159 -> V_301 . V_89 , 1 ) ;
else
V_387 = V_162 ;
F_121 (ring, q_vector->rx) {
int V_306 = F_191 ( V_159 , V_121 ,
V_387 ) ;
V_388 += V_306 ;
V_389 &= ( V_306 < V_387 ) ;
}
F_234 ( V_159 ) ;
if ( ! V_389 )
return V_162 ;
F_235 ( V_257 , V_388 ) ;
if ( V_2 -> V_390 & 1 )
F_204 ( V_159 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_217 ( V_2 , ( ( T_6 ) 1 << V_159 -> V_308 ) ) ;
return 0 ;
}
static int F_236 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_56 ;
int V_391 , V_17 ;
int V_392 = 0 , V_393 = 0 ;
for ( V_391 = 0 ; V_391 < V_2 -> V_193 ; V_391 ++ ) {
struct V_158 * V_159 = V_2 -> V_159 [ V_391 ] ;
struct V_394 * V_395 = & V_2 -> V_396 [ V_391 ] ;
if ( V_159 -> V_163 . V_121 && V_159 -> V_301 . V_121 ) {
snprintf ( V_159 -> V_54 , sizeof( V_159 -> V_54 ) - 1 ,
L_73 , V_56 -> V_54 , L_74 , V_392 ++ ) ;
V_393 ++ ;
} else if ( V_159 -> V_301 . V_121 ) {
snprintf ( V_159 -> V_54 , sizeof( V_159 -> V_54 ) - 1 ,
L_73 , V_56 -> V_54 , L_75 , V_392 ++ ) ;
} else if ( V_159 -> V_163 . V_121 ) {
snprintf ( V_159 -> V_54 , sizeof( V_159 -> V_54 ) - 1 ,
L_73 , V_56 -> V_54 , L_76 , V_393 ++ ) ;
} else {
continue;
}
V_17 = F_237 ( V_395 -> V_391 , & F_229 , 0 ,
V_159 -> V_54 , V_159 ) ;
if ( V_17 ) {
F_103 ( V_173 , L_77
L_78 , V_17 ) ;
goto V_397;
}
if ( V_2 -> V_140 & V_373 ) {
F_238 ( V_395 -> V_391 ,
& V_159 -> V_398 ) ;
}
}
V_17 = F_237 ( V_2 -> V_396 [ V_391 ] . V_391 ,
F_225 , 0 , V_56 -> V_54 , V_2 ) ;
if ( V_17 ) {
F_103 ( V_173 , L_79 , V_17 ) ;
goto V_397;
}
return 0 ;
V_397:
while ( V_391 ) {
V_391 -- ;
F_238 ( V_2 -> V_396 [ V_391 ] . V_391 ,
NULL ) ;
F_239 ( V_2 -> V_396 [ V_391 ] . V_391 ,
V_2 -> V_159 [ V_391 ] ) ;
}
V_2 -> V_140 &= ~ V_399 ;
F_240 ( V_2 -> V_9 ) ;
F_241 ( V_2 -> V_396 ) ;
V_2 -> V_396 = NULL ;
return V_17 ;
}
static T_11 F_242 ( int V_376 , void * V_93 )
{
struct V_1 * V_2 = V_93 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_158 * V_159 = V_2 -> V_159 [ 0 ] ;
T_1 V_335 ;
F_71 ( V_14 , V_364 , V_400 ) ;
V_335 = F_37 ( V_14 , V_350 ) ;
if ( ! V_335 ) {
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_221 ( V_2 , true , true ) ;
return V_401 ;
}
if ( V_335 & V_341 )
F_215 ( V_2 ) ;
switch ( V_14 -> V_109 . type ) {
case V_112 :
F_213 ( V_2 , V_335 ) ;
case V_113 :
case V_114 :
case V_115 :
if ( V_335 & V_379 ) {
F_105 ( V_380 , L_72 ) ;
V_2 -> V_155 |= V_156 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_350 , V_379 ) ;
}
F_211 ( V_2 , V_335 ) ;
break;
default:
break;
}
F_209 ( V_2 , V_335 ) ;
if ( F_24 ( V_335 & V_385 ) )
F_228 ( V_2 , V_335 ) ;
F_230 ( & V_159 -> V_257 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_221 ( V_2 , false , false ) ;
return V_386 ;
}
static int F_243 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_56 ;
int V_17 ;
if ( V_2 -> V_140 & V_399 )
V_17 = F_236 ( V_2 ) ;
else if ( V_2 -> V_140 & V_402 )
V_17 = F_237 ( V_2 -> V_9 -> V_376 , F_242 , 0 ,
V_56 -> V_54 , V_2 ) ;
else
V_17 = F_237 ( V_2 -> V_9 -> V_376 , F_242 , V_403 ,
V_56 -> V_54 , V_2 ) ;
if ( V_17 )
F_103 ( V_173 , L_80 , V_17 ) ;
return V_17 ;
}
static void F_244 ( struct V_1 * V_2 )
{
int V_391 ;
if ( ! ( V_2 -> V_140 & V_399 ) ) {
F_239 ( V_2 -> V_9 -> V_376 , V_2 ) ;
return;
}
for ( V_391 = 0 ; V_391 < V_2 -> V_193 ; V_391 ++ ) {
struct V_158 * V_159 = V_2 -> V_159 [ V_391 ] ;
struct V_394 * V_395 = & V_2 -> V_396 [ V_391 ] ;
if ( ! V_159 -> V_301 . V_121 && ! V_159 -> V_163 . V_121 )
continue;
F_238 ( V_395 -> V_391 , NULL ) ;
F_239 ( V_395 -> V_391 , V_159 ) ;
}
F_239 ( V_2 -> V_396 [ V_391 ++ ] . V_391 , V_2 ) ;
}
static inline void F_245 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_109 . type ) {
case V_110 :
F_71 ( & V_2 -> V_14 , V_364 , ~ 0 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
F_71 ( & V_2 -> V_14 , V_364 , 0xFFFF0000 ) ;
F_71 ( & V_2 -> V_14 , F_220 ( 0 ) , ~ 0 ) ;
F_71 ( & V_2 -> V_14 , F_220 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_216 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_140 & V_399 ) {
int V_391 ;
for ( V_391 = 0 ; V_391 < V_2 -> V_193 ; V_391 ++ )
F_246 ( V_2 -> V_396 [ V_391 ] . V_391 ) ;
F_246 ( V_2 -> V_396 [ V_391 ++ ] . V_391 ) ;
} else {
F_246 ( V_2 -> V_9 -> V_376 ) ;
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
T_6 V_404 = V_121 -> V_82 ;
int V_405 = 10 ;
T_1 V_406 = V_407 ;
T_4 V_150 = V_121 -> V_150 ;
F_71 ( V_14 , F_50 ( V_150 ) , 0 ) ;
F_216 ( V_14 ) ;
F_71 ( V_14 , F_45 ( V_150 ) ,
( V_404 & F_249 ( 32 ) ) ) ;
F_71 ( V_14 , F_46 ( V_150 ) , ( V_404 >> 32 ) ) ;
F_71 ( V_14 , F_47 ( V_150 ) ,
V_121 -> V_89 * sizeof( union V_62 ) ) ;
F_71 ( V_14 , F_48 ( V_150 ) , 0 ) ;
F_71 ( V_14 , F_49 ( V_150 ) , 0 ) ;
V_121 -> V_147 = V_2 -> V_408 + F_49 ( V_150 ) ;
if ( ! V_121 -> V_159 || ( V_121 -> V_159 -> V_323 < V_332 ) )
V_406 |= ( 1 << 16 ) ;
else
V_406 |= ( 8 << 16 ) ;
V_406 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_140 & V_373 ) {
V_121 -> V_409 = V_2 -> V_409 ;
V_121 -> V_410 = 0 ;
F_250 ( V_383 , & V_121 -> V_35 ) ;
} else {
V_121 -> V_409 = 0 ;
}
if ( ! F_15 ( V_411 , & V_121 -> V_35 ) ) {
struct V_158 * V_159 = V_121 -> V_159 ;
if ( V_159 )
F_251 ( V_121 -> V_56 ,
& V_159 -> V_398 ,
V_121 -> V_87 ) ;
}
F_34 ( V_133 , & V_121 -> V_35 ) ;
F_71 ( V_14 , F_50 ( V_150 ) , V_406 ) ;
if ( V_14 -> V_109 . type == V_110 &&
! ( F_37 ( V_14 , V_412 ) & V_413 ) )
return;
do {
F_252 ( 1000 , 2000 ) ;
V_406 = F_37 ( V_14 , F_50 ( V_150 ) ) ;
} while ( -- V_405 && ! ( V_406 & V_407 ) );
if ( ! V_405 )
F_103 ( V_157 , L_82 , V_150 ) ;
}
static void F_253 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_414 , V_415 ;
T_4 V_416 = F_254 ( V_2 -> V_56 ) ;
if ( V_14 -> V_109 . type == V_110 )
return;
V_414 = F_37 ( V_14 , V_417 ) ;
V_414 |= V_418 ;
F_71 ( V_14 , V_417 , V_414 ) ;
if ( V_2 -> V_140 & V_419 ) {
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
F_71 ( V_14 , V_430 , V_415 ) ;
if ( V_416 ) {
T_1 V_431 = F_37 ( V_14 , V_432 ) ;
V_431 |= V_433 ;
F_71 ( V_14 , V_432 , V_431 ) ;
}
V_414 &= ~ V_418 ;
F_71 ( V_14 , V_417 , V_414 ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_434 ;
T_1 V_49 ;
F_253 ( V_2 ) ;
if ( V_14 -> V_109 . type != V_110 ) {
V_434 = F_37 ( V_14 , V_435 ) ;
V_434 |= V_436 ;
F_71 ( V_14 , V_435 , V_434 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ )
F_248 ( V_2 , V_2 -> V_59 [ V_49 ] ) ;
}
static void F_256 ( struct V_1 * V_2 ,
struct V_58 * V_121 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_150 = V_121 -> V_150 ;
T_1 V_437 = F_37 ( V_14 , F_36 ( V_150 ) ) ;
V_437 |= V_438 ;
F_71 ( V_14 , F_36 ( V_150 ) , V_437 ) ;
}
static void F_257 ( struct V_1 * V_2 ,
struct V_58 * V_121 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_150 = V_121 -> V_150 ;
T_1 V_437 = F_37 ( V_14 , F_36 ( V_150 ) ) ;
V_437 &= ~ V_438 ;
F_71 ( V_14 , F_36 ( V_150 ) , V_437 ) ;
}
static void F_258 ( struct V_1 * V_2 ,
struct V_58 * V_68 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_437 ;
T_4 V_150 = V_68 -> V_150 ;
if ( V_14 -> V_109 . type == V_110 ) {
T_2 V_118 = V_2 -> V_424 [ V_425 ] . V_118 ;
V_150 &= V_118 ;
}
V_437 = V_272 << V_439 ;
V_437 |= F_69 ( V_68 ) >> V_440 ;
V_437 |= V_441 ;
F_71 ( V_14 , F_36 ( V_150 ) , V_437 ) ;
}
T_1 F_259 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_109 . type < V_114 )
return 128 ;
else if ( V_2 -> V_140 & V_419 )
return 64 ;
else
return 512 ;
}
void F_260 ( struct V_1 * V_2 )
{
T_1 V_49 , V_442 = F_259 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_443 = 0 ;
T_1 V_444 ;
T_4 * V_445 = V_2 -> V_446 ;
if ( V_2 -> V_14 . V_109 . type == V_110 )
V_444 = 0x11 ;
else
V_444 = 0x1 ;
for ( V_49 = 0 ; V_49 < V_442 ; V_49 ++ ) {
V_443 |= V_444 * V_445 [ V_49 ] << ( V_49 & 0x3 ) * 8 ;
if ( ( V_49 & 3 ) == 3 ) {
if ( V_49 < 128 )
F_71 ( V_14 , F_261 ( V_49 >> 2 ) , V_443 ) ;
else
F_71 ( V_14 , F_262 ( ( V_49 >> 2 ) - 32 ) ,
V_443 ) ;
V_443 = 0 ;
}
}
}
static void F_263 ( struct V_1 * V_2 )
{
T_1 V_49 , V_442 = F_259 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_447 = 0 ;
unsigned int V_448 = V_2 -> V_309 ;
for ( V_49 = 0 ; V_49 < V_442 ; V_49 ++ ) {
V_447 |= ( T_1 ) V_2 -> V_446 [ V_49 ] << ( V_49 & 0x3 ) * 8 ;
if ( ( V_49 & 3 ) == 3 ) {
F_71 ( V_14 , F_264 ( V_49 >> 2 , V_448 ) ,
V_447 ) ;
V_447 = 0 ;
}
}
}
static void F_265 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_49 , V_50 ;
T_1 V_442 = F_259 ( V_2 ) ;
T_2 V_449 = V_2 -> V_424 [ V_425 ] . V_426 ;
if ( ( V_2 -> V_140 & V_419 ) && ( V_449 < 2 ) )
V_449 = 2 ;
for ( V_49 = 0 ; V_49 < 10 ; V_49 ++ )
F_71 ( V_14 , F_266 ( V_49 ) , V_2 -> V_450 [ V_49 ] ) ;
memset ( V_2 -> V_446 , 0 , sizeof( V_2 -> V_446 ) ) ;
for ( V_49 = 0 , V_50 = 0 ; V_49 < V_442 ; V_49 ++ , V_50 ++ ) {
if ( V_50 == V_449 )
V_50 = 0 ;
V_2 -> V_446 [ V_49 ] = V_50 ;
}
F_260 ( V_2 ) ;
}
static void F_267 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_449 = V_2 -> V_424 [ V_425 ] . V_426 ;
unsigned int V_448 = V_2 -> V_309 ;
int V_49 , V_50 ;
for ( V_49 = 0 ; V_49 < 10 ; V_49 ++ )
F_71 ( V_14 , F_268 ( V_49 , V_448 ) ,
V_2 -> V_450 [ V_49 ] ) ;
for ( V_49 = 0 , V_50 = 0 ; V_49 < 64 ; V_49 ++ , V_50 ++ ) {
if ( V_50 == V_449 )
V_50 = 0 ;
V_2 -> V_446 [ V_49 ] = V_50 ;
}
F_263 ( V_2 ) ;
}
static void F_269 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_451 = 0 , V_452 = 0 , V_453 = 0 ;
T_1 V_454 ;
V_454 = F_37 ( V_14 , V_455 ) ;
V_454 |= V_456 ;
F_71 ( V_14 , V_455 , V_454 ) ;
if ( V_2 -> V_14 . V_109 . type == V_110 ) {
if ( V_2 -> V_424 [ V_425 ] . V_118 )
V_451 = V_457 ;
} else {
T_4 V_416 = F_254 ( V_2 -> V_56 ) ;
if ( V_2 -> V_140 & V_419 ) {
if ( V_416 > 4 )
V_451 = V_458 ;
else if ( V_416 > 1 )
V_451 = V_459 ;
else if ( V_2 -> V_424 [ V_425 ] . V_426 == 4 )
V_451 = V_460 ;
else
V_451 = V_461 ;
} else {
if ( V_416 > 4 )
V_451 = V_462 ;
else if ( V_416 > 1 )
V_451 = V_463 ;
else
V_451 = V_457 ;
}
}
V_452 |= V_464 |
V_465 |
V_466 |
V_467 ;
if ( V_2 -> V_155 & V_468 )
V_452 |= V_469 ;
if ( V_2 -> V_155 & V_470 )
V_452 |= V_471 ;
F_270 ( V_2 -> V_450 , sizeof( V_2 -> V_450 ) ) ;
if ( ( V_14 -> V_109 . type >= V_114 ) &&
( V_2 -> V_140 & V_419 ) ) {
unsigned int V_448 = V_2 -> V_309 ;
V_451 |= V_472 ;
F_71 ( V_14 , V_473 , V_451 ) ;
F_267 ( V_2 ) ;
V_453 = V_457 ;
V_453 |= V_452 ;
F_71 ( V_14 , F_271 ( V_448 ) , V_453 ) ;
} else {
F_265 ( V_2 ) ;
V_451 |= V_452 ;
F_71 ( V_14 , V_473 , V_451 ) ;
}
}
static void F_272 ( struct V_1 * V_2 ,
struct V_58 * V_121 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_474 ;
T_4 V_150 = V_121 -> V_150 ;
if ( ! F_164 ( V_121 ) )
return;
V_474 = F_37 ( V_14 , F_273 ( V_150 ) ) ;
V_474 |= V_475 ;
V_474 |= V_476 ;
F_71 ( V_14 , F_273 ( V_150 ) , V_474 ) ;
}
static void F_274 ( struct V_1 * V_2 ,
struct V_58 * V_121 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_405 = V_477 ;
T_1 V_478 ;
T_4 V_150 = V_121 -> V_150 ;
if ( F_22 ( V_14 -> V_40 ) )
return;
if ( V_14 -> V_109 . type == V_110 &&
! ( F_37 ( V_14 , V_412 ) & V_413 ) )
return;
do {
F_252 ( 1000 , 2000 ) ;
V_478 = F_37 ( V_14 , F_42 ( V_150 ) ) ;
} while ( -- V_405 && ! ( V_478 & V_479 ) );
if ( ! V_405 ) {
F_103 ( V_157 , L_83
L_84 , V_150 ) ;
}
}
void F_275 ( struct V_1 * V_2 ,
struct V_58 * V_121 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_405 = V_477 ;
T_1 V_478 ;
T_4 V_150 = V_121 -> V_150 ;
if ( F_22 ( V_14 -> V_40 ) )
return;
V_478 = F_37 ( V_14 , F_42 ( V_150 ) ) ;
V_478 &= ~ V_479 ;
F_71 ( V_14 , F_42 ( V_150 ) , V_478 ) ;
if ( V_14 -> V_109 . type == V_110 &&
! ( F_37 ( V_14 , V_412 ) & V_413 ) )
return;
do {
F_276 ( 10 ) ;
V_478 = F_37 ( V_14 , F_42 ( V_150 ) ) ;
} while ( -- V_405 && ( V_478 & V_479 ) );
if ( ! V_405 ) {
F_103 ( V_157 , L_85
L_84 , V_150 ) ;
}
}
void F_277 ( struct V_1 * V_2 ,
struct V_58 * V_121 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_480 = V_121 -> V_82 ;
T_1 V_478 ;
T_4 V_150 = V_121 -> V_150 ;
V_478 = F_37 ( V_14 , F_42 ( V_150 ) ) ;
F_275 ( V_2 , V_121 ) ;
F_71 ( V_14 , F_43 ( V_150 ) , ( V_480 & F_249 ( 32 ) ) ) ;
F_71 ( V_14 , F_44 ( V_150 ) , ( V_480 >> 32 ) ) ;
F_71 ( V_14 , F_39 ( V_150 ) ,
V_121 -> V_89 * sizeof( union V_69 ) ) ;
F_71 ( V_14 , F_40 ( V_150 ) , 0 ) ;
F_71 ( V_14 , F_41 ( V_150 ) , 0 ) ;
V_121 -> V_147 = V_2 -> V_408 + F_41 ( V_150 ) ;
F_258 ( V_2 , V_121 ) ;
F_272 ( V_2 , V_121 ) ;
if ( V_14 -> V_109 . type == V_110 ) {
V_478 &= ~ 0x3FFFFF ;
V_478 |= 0x080420 ;
}
V_478 |= V_479 ;
F_71 ( V_14 , F_42 ( V_150 ) , V_478 ) ;
F_274 ( V_2 , V_121 ) ;
F_143 ( V_121 , F_110 ( V_121 ) ) ;
}
static void F_278 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_449 = V_2 -> V_424 [ V_425 ] . V_426 ;
T_2 V_481 ;
T_1 V_482 = V_483 |
V_484 |
V_485 |
V_486 |
V_487 ;
if ( V_14 -> V_109 . type == V_110 )
return;
if ( V_449 > 3 )
V_482 |= 2 << 29 ;
else if ( V_449 > 1 )
V_482 |= 1 << 29 ;
F_279 (pool, &adapter->fwd_bitmask, 32 )
F_71 ( V_14 , F_280 ( F_281 ( V_481 ) ) , V_482 ) ;
}
static void F_282 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_178 , V_488 ;
T_1 V_489 , V_490 ;
int V_49 ;
if ( ! ( V_2 -> V_140 & V_419 ) )
return;
V_490 = F_37 ( V_14 , V_491 ) ;
V_490 |= V_492 ;
V_490 &= ~ V_493 ;
V_490 |= F_281 ( 0 ) << V_494 ;
V_490 |= V_495 ;
F_71 ( V_14 , V_491 , V_490 ) ;
V_488 = F_281 ( 0 ) % 32 ;
V_178 = ( F_281 ( 0 ) >= 32 ) ? 1 : 0 ;
F_71 ( V_14 , F_283 ( V_178 ) , ( ~ 0 ) << V_488 ) ;
F_71 ( V_14 , F_283 ( V_178 ^ 1 ) , V_178 - 1 ) ;
F_71 ( V_14 , F_284 ( V_178 ) , ( ~ 0 ) << V_488 ) ;
F_71 ( V_14 , F_284 ( V_178 ^ 1 ) , V_178 - 1 ) ;
if ( V_2 -> V_496 == V_497 )
F_71 ( V_14 , V_498 , V_499 ) ;
V_14 -> V_109 . V_342 . V_500 ( V_14 , 0 , F_281 ( 0 ) ) ;
switch ( V_2 -> V_424 [ V_501 ] . V_118 ) {
case V_502 :
V_489 = V_503 ;
break;
case V_504 :
V_489 = V_505 ;
break;
default:
V_489 = V_506 ;
break;
}
F_71 ( V_14 , V_507 , V_489 ) ;
V_14 -> V_109 . V_342 . V_508 ( V_14 , ( V_2 -> V_309 != 0 ) ,
V_2 -> V_309 ) ;
if ( V_14 -> V_109 . V_342 . V_509 ) {
F_71 ( V_14 , F_285 ( V_510 ) ,
( V_511 |
V_512 |
V_513 ) ) ;
F_71 ( V_14 , F_285 ( V_514 ) ,
( V_511 |
V_512 |
V_515 ) ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_309 ; V_49 ++ ) {
if ( ! V_2 -> V_516 [ V_49 ] . V_517 )
F_286 ( V_2 -> V_56 , V_49 , false ) ;
if ( V_14 -> V_109 . V_342 . V_509 )
V_14 -> V_109 . V_342 . V_509 ( V_14 , true , V_49 ) ;
F_287 ( V_2 -> V_56 , V_49 ,
V_2 -> V_516 [ V_49 ] . V_518 ) ;
}
}
static void F_288 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_55 * V_56 = V_2 -> V_56 ;
int V_519 = V_56 -> V_297 + V_520 + V_521 ;
struct V_58 * V_68 ;
int V_49 ;
T_1 V_522 , V_523 ;
#ifdef F_175
if ( ( V_2 -> V_140 & V_524 ) &&
( V_519 < V_525 ) )
V_519 = V_525 ;
#endif
if ( V_519 < ( V_526 + V_521 ) )
V_519 = ( V_526 + V_521 ) ;
V_522 = F_37 ( V_14 , V_527 ) ;
if ( V_519 != ( V_522 >> V_528 ) ) {
V_522 &= ~ V_529 ;
V_522 |= V_519 << V_528 ;
F_71 ( V_14 , V_527 , V_522 ) ;
}
V_523 = F_37 ( V_14 , V_530 ) ;
V_523 |= V_531 ;
F_71 ( V_14 , V_530 , V_523 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_94 ; V_49 ++ ) {
V_68 = V_2 -> V_68 [ V_49 ] ;
if ( V_2 -> V_155 & V_532 )
F_289 ( V_68 ) ;
else
F_290 ( V_68 ) ;
}
}
static void F_291 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_533 = F_37 ( V_14 , V_534 ) ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
V_533 |= V_535 ;
break;
case V_114 :
case V_115 :
if ( V_2 -> V_309 )
V_533 |= V_536 ;
case V_112 :
case V_113 :
F_71 ( V_14 , V_537 ,
( V_538 | F_37 ( V_14 , V_537 ) ) ) ;
V_533 &= ~ V_539 ;
V_533 |= ( V_540 | V_541 ) ;
V_533 |= V_542 ;
break;
default:
return;
}
F_71 ( V_14 , V_534 , V_533 ) ;
}
static void F_292 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
T_1 V_184 , V_543 ;
V_14 -> V_109 . V_342 . V_544 ( V_14 ) ;
F_278 ( V_2 ) ;
F_291 ( V_2 ) ;
V_543 = F_37 ( V_14 , V_545 ) ;
V_543 &= ~ V_546 ;
if ( ! ( V_2 -> V_155 & V_532 ) )
V_543 |= V_546 ;
F_71 ( V_14 , V_545 , V_543 ) ;
F_269 ( V_2 ) ;
F_288 ( V_2 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_94 ; V_49 ++ )
F_277 ( V_2 , V_2 -> V_68 [ V_49 ] ) ;
V_184 = F_37 ( V_14 , V_547 ) ;
if ( V_14 -> V_109 . type == V_110 )
V_184 |= V_548 ;
V_184 |= V_549 ;
V_14 -> V_109 . V_342 . V_550 ( V_14 , V_184 ) ;
}
static int F_293 ( struct V_55 * V_56 ,
T_12 V_551 , T_2 V_253 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_109 . V_342 . V_552 ( & V_2 -> V_14 , V_253 , F_281 ( 0 ) , true ) ;
F_250 ( V_253 , V_2 -> V_553 ) ;
return 0 ;
}
static int F_294 ( struct V_55 * V_56 ,
T_12 V_551 , T_2 V_253 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_109 . V_342 . V_552 ( & V_2 -> V_14 , V_253 , F_281 ( 0 ) , false ) ;
F_34 ( V_253 , V_2 -> V_553 ) ;
return 0 ;
}
static void F_295 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_554 ;
int V_49 , V_50 ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
V_554 = F_37 ( V_14 , V_555 ) ;
V_554 &= ~ V_556 ;
F_71 ( V_14 , V_555 , V_554 ) ;
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
V_554 = F_37 ( V_14 , F_42 ( V_50 ) ) ;
V_554 &= ~ V_557 ;
F_71 ( V_14 , F_42 ( V_50 ) , V_554 ) ;
}
break;
default:
break;
}
}
static void F_296 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_554 ;
int V_49 , V_50 ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
V_554 = F_37 ( V_14 , V_555 ) ;
V_554 |= V_556 ;
F_71 ( V_14 , V_555 , V_554 ) ;
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
V_554 = F_37 ( V_14 , F_42 ( V_50 ) ) ;
V_554 |= V_557 ;
F_71 ( V_14 , F_42 ( V_50 ) , V_554 ) ;
}
break;
default:
break;
}
}
static void F_297 ( struct V_1 * V_2 )
{
T_2 V_253 ;
F_293 ( V_2 -> V_56 , F_156 ( V_255 ) , 0 ) ;
F_279 (vid, adapter->active_vlans, VLAN_N_VID)
F_293 ( V_2 -> V_56 , F_156 ( V_255 ) , V_253 ) ;
}
static int F_298 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! F_57 ( V_56 ) )
return 0 ;
if ( V_14 -> V_109 . V_342 . V_558 )
V_14 -> V_109 . V_342 . V_558 ( V_14 , V_56 ) ;
else
return - V_559 ;
#ifdef F_299
F_300 ( V_2 ) ;
#endif
return F_301 ( V_56 ) ;
}
void F_302 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_109 . V_560 ; V_49 ++ ) {
if ( V_2 -> V_561 [ V_49 ] . V_35 & V_562 )
V_14 -> V_109 . V_342 . V_563 ( V_14 , V_49 , V_2 -> V_561 [ V_49 ] . V_564 ,
V_2 -> V_561 [ V_49 ] . V_105 ,
V_565 ) ;
else
V_14 -> V_109 . V_342 . V_566 ( V_14 , V_49 ) ;
V_2 -> V_561 [ V_49 ] . V_35 &= ~ ( V_567 ) ;
}
}
static void F_303 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_109 . V_560 ; V_49 ++ ) {
if ( V_2 -> V_561 [ V_49 ] . V_35 & V_567 ) {
if ( V_2 -> V_561 [ V_49 ] . V_35 &
V_562 )
V_14 -> V_109 . V_342 . V_563 ( V_14 , V_49 ,
V_2 -> V_561 [ V_49 ] . V_564 ,
V_2 -> V_561 [ V_49 ] . V_105 ,
V_565 ) ;
else
V_14 -> V_109 . V_342 . V_566 ( V_14 , V_49 ) ;
V_2 -> V_561 [ V_49 ] . V_35 &=
~ ( V_567 ) ;
}
}
}
static void F_304 ( struct V_1 * V_2 )
{
int V_49 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_109 . V_560 ; V_49 ++ ) {
V_2 -> V_561 [ V_49 ] . V_35 |= V_567 ;
V_2 -> V_561 [ V_49 ] . V_35 &= ~ V_562 ;
F_305 ( V_2 -> V_561 [ V_49 ] . V_564 ) ;
V_2 -> V_561 [ V_49 ] . V_105 = 0 ;
}
F_303 ( V_2 ) ;
}
static int F_306 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 , V_89 = 0 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_109 . V_560 ; V_49 ++ ) {
if ( V_2 -> V_561 [ V_49 ] . V_35 == 0 )
V_89 ++ ;
}
return V_89 ;
}
static void F_307 ( struct V_1 * V_2 ,
T_4 * V_564 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
memcpy ( & V_2 -> V_561 [ 0 ] . V_564 , V_564 , V_568 ) ;
V_2 -> V_561 [ 0 ] . V_105 = F_281 ( 0 ) ;
V_2 -> V_561 [ 0 ] . V_35 = ( V_569 |
V_562 ) ;
V_14 -> V_109 . V_342 . V_563 ( V_14 , 0 , V_2 -> V_561 [ 0 ] . V_564 ,
V_2 -> V_561 [ 0 ] . V_105 ,
V_565 ) ;
}
int F_308 ( struct V_1 * V_2 , T_4 * V_564 , T_2 V_105 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( F_309 ( V_564 ) )
return - V_570 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_109 . V_560 ; V_49 ++ ) {
if ( V_2 -> V_561 [ V_49 ] . V_35 & V_562 )
continue;
V_2 -> V_561 [ V_49 ] . V_35 |= ( V_567 |
V_562 ) ;
F_310 ( V_2 -> V_561 [ V_49 ] . V_564 , V_564 ) ;
V_2 -> V_561 [ V_49 ] . V_105 = V_105 ;
F_303 ( V_2 ) ;
return V_49 ;
}
return - V_559 ;
}
int F_311 ( struct V_1 * V_2 , T_4 * V_564 , T_2 V_105 )
{
int V_49 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_309 ( V_564 ) )
return - V_570 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_109 . V_560 ; V_49 ++ ) {
if ( F_312 ( V_564 , V_2 -> V_561 [ V_49 ] . V_564 ) &&
V_2 -> V_561 [ V_49 ] . V_105 == V_105 ) {
V_2 -> V_561 [ V_49 ] . V_35 |= V_567 ;
V_2 -> V_561 [ V_49 ] . V_35 &= ~ V_562 ;
F_305 ( V_2 -> V_561 [ V_49 ] . V_564 ) ;
V_2 -> V_561 [ V_49 ] . V_105 = 0 ;
F_303 ( V_2 ) ;
return 0 ;
}
}
return - V_559 ;
}
static int F_313 ( struct V_55 * V_56 , int V_571 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
int V_89 = 0 ;
if ( F_314 ( V_56 ) > F_306 ( V_2 ) )
return - V_559 ;
if ( ! F_315 ( V_56 ) ) {
struct V_572 * V_573 ;
F_316 (ha, netdev) {
F_311 ( V_2 , V_573 -> V_564 , V_571 ) ;
F_308 ( V_2 , V_573 -> V_564 , V_571 ) ;
V_89 ++ ;
}
}
return V_89 ;
}
void F_317 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_574 , V_575 = V_576 | V_577 ;
T_1 V_554 ;
int V_89 ;
V_574 = F_37 ( V_14 , V_578 ) ;
V_554 = F_37 ( V_14 , V_555 ) ;
V_574 &= ~ V_579 ;
V_574 |= V_580 ;
V_574 |= V_581 ;
V_574 |= V_582 ;
V_574 &= ~ ( V_583 | V_584 ) ;
V_554 &= ~ ( V_585 | V_586 ) ;
if ( V_56 -> V_140 & V_587 ) {
V_14 -> V_588 . V_589 = true ;
V_574 |= ( V_583 | V_584 ) ;
V_575 |= V_590 ;
if ( V_2 -> V_140 & ( V_591 |
V_419 ) )
V_554 |= ( V_585 | V_586 ) ;
} else {
if ( V_56 -> V_140 & V_592 ) {
V_574 |= V_584 ;
V_575 |= V_590 ;
}
V_554 |= V_585 ;
V_14 -> V_588 . V_589 = false ;
}
V_89 = F_313 ( V_56 , F_281 ( 0 ) ) ;
if ( V_89 < 0 ) {
V_574 |= V_583 ;
V_575 |= V_593 ;
}
V_89 = F_298 ( V_56 ) ;
if ( V_89 < 0 ) {
V_574 |= V_584 ;
V_575 |= V_590 ;
} else if ( V_89 ) {
V_575 |= V_594 ;
}
if ( V_14 -> V_109 . type != V_110 ) {
V_575 |= F_37 ( V_14 , F_318 ( F_281 ( 0 ) ) ) &
~ ( V_590 | V_594 |
V_593 ) ;
F_71 ( V_14 , F_318 ( F_281 ( 0 ) ) , V_575 ) ;
}
if ( V_2 -> V_56 -> V_201 & V_276 ) {
V_574 |= ( V_579 |
V_580 |
V_582 ) ;
V_574 &= ~ ( V_581 ) ;
}
F_71 ( V_14 , V_555 , V_554 ) ;
F_71 ( V_14 , V_578 , V_574 ) ;
if ( V_56 -> V_201 & V_251 )
F_296 ( V_2 ) ;
else
F_295 ( V_2 ) ;
}
static void F_319 ( struct V_1 * V_2 )
{
int V_595 ;
for ( V_595 = 0 ; V_595 < V_2 -> V_193 ; V_595 ++ ) {
F_320 ( V_2 -> V_159 [ V_595 ] ) ;
F_321 ( & V_2 -> V_159 [ V_595 ] -> V_257 ) ;
}
}
static void F_322 ( struct V_1 * V_2 )
{
int V_595 ;
for ( V_595 = 0 ; V_595 < V_2 -> V_193 ; V_595 ++ ) {
F_323 ( & V_2 -> V_159 [ V_595 ] -> V_257 ) ;
while ( ! F_324 ( V_2 -> V_159 [ V_595 ] ) ) {
F_51 ( L_86 , V_595 ) ;
F_252 ( 1000 , 20000 ) ;
}
}
}
static void F_325 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_109 . type ) {
case V_114 :
case V_115 :
F_71 ( & V_2 -> V_14 , V_596 , 0 ) ;
#ifdef F_326
V_2 -> V_597 = 0 ;
#endif
break;
default:
break;
}
}
static void F_327 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_519 = V_2 -> V_56 -> V_297 + V_520 + V_521 ;
if ( ! ( V_2 -> V_140 & V_141 ) ) {
if ( V_14 -> V_109 . type == V_110 )
F_328 ( V_2 -> V_56 , 65536 ) ;
return;
}
if ( V_14 -> V_109 . type == V_110 )
F_328 ( V_2 -> V_56 , 32768 ) ;
#ifdef F_175
if ( V_2 -> V_56 -> V_201 & V_598 )
V_519 = F_205 ( V_519 , V_525 ) ;
#endif
if ( V_2 -> V_599 & V_600 ) {
F_329 ( V_14 , & V_2 -> V_137 , V_519 ,
V_601 ) ;
F_329 ( V_14 , & V_2 -> V_137 , V_519 ,
V_602 ) ;
F_330 ( V_14 , & V_2 -> V_137 ) ;
} else if ( V_2 -> V_603 && V_2 -> V_139 ) {
F_331 ( & V_2 -> V_14 ,
V_2 -> V_603 ,
V_519 ) ;
F_332 ( & V_2 -> V_14 ,
V_2 -> V_139 -> V_136 ,
V_2 -> V_603 -> V_604 ) ;
}
if ( V_14 -> V_109 . type != V_110 ) {
T_1 V_605 = 0 ;
T_2 V_449 = V_2 -> V_424 [ V_425 ] . V_426 - 1 ;
while ( V_449 ) {
V_605 ++ ;
V_449 >>= 1 ;
}
F_71 ( V_14 , V_606 , V_605 * 0x11111111 ) ;
}
}
static int F_333 ( struct V_1 * V_2 , int V_607 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_55 * V_74 = V_2 -> V_56 ;
int V_380 , V_135 , V_608 , V_609 ;
T_1 V_610 , V_611 ;
V_135 = V_380 = V_74 -> V_297 + V_520 + V_521 + V_612 ;
#ifdef F_175
if ( ( V_74 -> V_201 & V_598 ) &&
( V_135 < V_525 ) &&
( V_607 == F_334 ( V_2 ) ) )
V_135 = V_525 ;
#endif
switch ( V_14 -> V_109 . type ) {
case V_113 :
case V_114 :
case V_115 :
V_610 = F_335 ( V_380 , V_135 ) ;
break;
default:
V_610 = F_336 ( V_380 , V_135 ) ;
break;
}
if ( V_2 -> V_140 & V_419 )
V_610 += F_337 ( V_135 ) ;
V_608 = F_338 ( V_610 ) ;
V_611 = F_37 ( V_14 , F_339 ( V_607 ) ) >> 10 ;
V_609 = V_611 - V_608 ;
if ( V_609 < 0 ) {
F_93 ( V_157 , L_87
L_88
L_89 , V_607 ) ;
V_609 = V_135 + 1 ;
}
return V_609 ;
}
static int F_340 ( struct V_1 * V_2 , int V_607 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_55 * V_74 = V_2 -> V_56 ;
int V_135 ;
T_1 V_610 ;
V_135 = V_74 -> V_297 + V_520 + V_521 ;
#ifdef F_175
if ( ( V_74 -> V_201 & V_598 ) &&
( V_135 < V_525 ) &&
( V_607 == F_86 ( V_74 , V_2 -> V_613 . V_614 ) ) )
V_135 = V_525 ;
#endif
switch ( V_14 -> V_109 . type ) {
case V_113 :
case V_114 :
case V_115 :
V_610 = F_341 ( V_135 ) ;
break;
default:
V_610 = F_342 ( V_135 ) ;
break;
}
return F_338 ( V_610 ) ;
}
static void F_343 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_615 = F_254 ( V_2 -> V_56 ) ;
int V_49 ;
if ( ! V_615 )
V_615 = 1 ;
for ( V_49 = 0 ; V_49 < V_615 ; V_49 ++ ) {
V_14 -> V_126 . V_616 [ V_49 ] = F_333 ( V_2 , V_49 ) ;
V_14 -> V_126 . V_617 [ V_49 ] = F_340 ( V_2 , V_49 ) ;
if ( V_14 -> V_126 . V_617 [ V_49 ] > V_14 -> V_126 . V_616 [ V_49 ] )
V_14 -> V_126 . V_617 [ V_49 ] = 0 ;
}
for (; V_49 < V_618 ; V_49 ++ )
V_14 -> V_126 . V_616 [ V_49 ] = 0 ;
}
static void F_344 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_619 ;
T_4 V_135 = F_254 ( V_2 -> V_56 ) ;
if ( V_2 -> V_140 & V_373 ||
V_2 -> V_140 & V_620 )
V_619 = 32 << V_2 -> V_621 ;
else
V_619 = 0 ;
V_14 -> V_109 . V_342 . V_622 ( V_14 , V_135 , V_619 , V_623 ) ;
F_343 ( V_2 ) ;
}
static void F_345 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_624 * V_625 ;
struct V_626 * V_627 ;
F_346 ( & V_2 -> V_628 ) ;
if ( ! F_347 ( & V_2 -> V_629 ) )
F_348 ( V_14 , & V_2 -> V_630 ) ;
F_349 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_350 ( V_14 ,
& V_627 -> V_627 ,
V_627 -> V_631 ,
( V_627 -> V_632 == V_633 ) ?
V_633 :
V_2 -> V_68 [ V_627 -> V_632 ] -> V_150 ) ;
}
F_351 ( & V_2 -> V_628 ) ;
}
static void F_352 ( struct V_55 * V_74 , unsigned int V_481 ,
struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_575 ;
V_575 = F_37 ( V_14 , F_318 ( V_481 ) ) ;
V_575 |= ( V_594 | V_576 | V_577 ) ;
V_575 &= ~ V_590 ;
if ( V_74 -> V_140 & V_592 ) {
V_575 |= V_590 ;
} else {
V_575 |= V_594 ;
V_14 -> V_109 . V_342 . V_558 ( V_14 , V_74 ) ;
}
F_313 ( V_2 -> V_56 , V_481 ) ;
F_71 ( V_14 , F_318 ( V_481 ) , V_575 ) ;
}
static void F_353 ( struct V_634 * V_635 )
{
struct V_1 * V_2 = V_635 -> V_149 ;
int V_449 = V_2 -> V_636 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_481 = V_635 -> V_481 ;
T_1 V_482 = V_483 |
V_484 |
V_485 |
V_486 |
V_487 ;
if ( V_14 -> V_109 . type == V_110 )
return;
if ( V_449 > 3 )
V_482 |= 2 << 29 ;
else if ( V_449 > 1 )
V_482 |= 1 << 29 ;
F_71 ( V_14 , F_280 ( F_281 ( V_481 ) ) , V_482 ) ;
}
static void F_354 ( struct V_58 * V_68 )
{
struct V_194 * V_74 = V_68 -> V_74 ;
unsigned long V_281 ;
T_2 V_49 ;
if ( ! V_68 -> V_72 )
return;
for ( V_49 = 0 ; V_49 < V_68 -> V_89 ; V_49 ++ ) {
struct V_71 * V_280 = & V_68 -> V_72 [ V_49 ] ;
if ( V_280 -> V_90 ) {
struct V_199 * V_90 = V_280 -> V_90 ;
if ( F_151 ( V_90 ) -> V_274 )
F_80 ( V_74 ,
F_151 ( V_90 ) -> V_82 ,
F_69 ( V_68 ) ,
V_238 ) ;
F_355 ( V_90 ) ;
V_280 -> V_90 = NULL ;
}
if ( ! V_280 -> V_99 )
continue;
F_80 ( V_74 , V_280 -> V_82 ,
F_140 ( V_68 ) , V_238 ) ;
F_142 ( V_280 -> V_99 , F_138 ( V_68 ) ) ;
V_280 -> V_99 = NULL ;
}
V_281 = sizeof( struct V_71 ) * V_68 -> V_89 ;
memset ( V_68 -> V_72 , 0 , V_281 ) ;
memset ( V_68 -> V_88 , 0 , V_68 -> V_281 ) ;
V_68 -> V_242 = 0 ;
V_68 -> V_80 = 0 ;
V_68 -> V_81 = 0 ;
}
static void F_356 ( struct V_634 * V_635 ,
struct V_58 * V_68 )
{
struct V_1 * V_2 = V_635 -> V_149 ;
int V_108 = V_68 -> V_87 + V_635 -> V_637 ;
F_275 ( V_2 , V_68 ) ;
F_252 ( 10000 , 20000 ) ;
F_219 ( V_2 , ( ( T_6 ) 1 << V_108 ) ) ;
F_354 ( V_68 ) ;
V_68 -> V_148 = NULL ;
}
static int F_357 ( struct V_55 * V_638 ,
struct V_634 * V_639 )
{
struct V_1 * V_2 = V_639 -> V_149 ;
unsigned int V_640 = V_639 -> V_637 ;
unsigned int V_641 = V_639 -> V_642 ;
int V_49 ;
F_358 ( V_638 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_636 ; V_49 ++ ) {
F_356 ( V_639 , V_2 -> V_68 [ V_640 + V_49 ] ) ;
V_2 -> V_68 [ V_640 + V_49 ] -> V_56 = V_2 -> V_56 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_636 ; V_49 ++ ) {
V_2 -> V_59 [ V_641 + V_49 ] -> V_148 = NULL ;
V_2 -> V_59 [ V_641 + V_49 ] -> V_56 = V_2 -> V_56 ;
}
return 0 ;
}
static int F_359 ( struct V_55 * V_638 ,
struct V_634 * V_639 )
{
struct V_1 * V_2 = V_639 -> V_149 ;
unsigned int V_640 , V_641 , V_367 ;
int V_49 , V_643 , V_17 = 0 ;
if ( ! F_14 ( V_639 -> V_481 , & V_2 -> V_644 ) )
return 0 ;
V_643 = V_639 -> V_481 * V_2 -> V_636 ;
F_360 ( V_638 , L_90 ,
V_639 -> V_481 , V_2 -> V_645 ,
V_643 , V_643 + V_2 -> V_636 ,
V_2 -> V_644 ) ;
V_639 -> V_56 = V_638 ;
V_639 -> V_637 = V_640 = V_643 ;
V_639 -> V_642 = V_641 = V_643 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_636 ; V_49 ++ )
F_356 ( V_639 , V_2 -> V_68 [ V_640 + V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_636 ; V_49 ++ ) {
V_2 -> V_68 [ V_640 + V_49 ] -> V_56 = V_638 ;
V_2 -> V_68 [ V_640 + V_49 ] -> V_148 = V_639 ;
F_277 ( V_2 , V_2 -> V_68 [ V_640 + V_49 ] ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_636 ; V_49 ++ ) {
V_2 -> V_59 [ V_641 + V_49 ] -> V_56 = V_638 ;
V_2 -> V_59 [ V_641 + V_49 ] -> V_148 = V_639 ;
}
V_367 = F_361 (unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues) ;
V_17 = F_362 ( V_638 , V_367 ) ;
if ( V_17 )
goto V_646;
V_17 = F_363 ( V_638 , V_367 ) ;
if ( V_17 )
goto V_646;
if ( F_364 ( V_638 -> V_647 ) )
F_308 ( V_2 , V_638 -> V_647 , V_639 -> V_481 ) ;
F_353 ( V_639 ) ;
F_352 ( V_638 , V_639 -> V_481 , V_2 ) ;
return V_17 ;
V_646:
F_357 ( V_638 , V_639 ) ;
return V_17 ;
}
static void F_365 ( struct V_1 * V_2 )
{
struct V_55 * V_96 ;
struct V_648 * V_649 ;
int V_17 ;
F_366 (adapter->netdev, upper, iter) {
if ( F_367 ( V_96 ) ) {
struct V_650 * V_651 = F_89 ( V_96 ) ;
struct V_634 * V_635 = V_651 -> V_652 ;
if ( V_651 -> V_652 ) {
V_17 = F_359 ( V_96 , V_635 ) ;
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
V_14 -> V_109 . V_342 . V_653 ( V_14 ) ;
break;
default:
break;
}
if ( V_2 -> V_140 & V_373 ) {
F_370 ( & V_2 -> V_14 ,
V_2 -> V_621 ) ;
} else if ( V_2 -> V_140 & V_620 ) {
F_371 ( & V_2 -> V_14 ,
V_2 -> V_621 ) ;
F_345 ( V_2 ) ;
}
switch ( V_14 -> V_109 . type ) {
case V_112 :
case V_113 :
V_14 -> V_109 . V_342 . V_654 ( V_14 ) ;
break;
default:
break;
}
#ifdef F_232
if ( V_2 -> V_140 & V_196 )
F_123 ( V_2 ) ;
#endif
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
V_2 -> V_155 |= V_655 ;
V_2 -> V_155 |= V_358 ;
V_2 -> V_359 = 0 ;
}
static int F_374 ( struct V_15 * V_14 )
{
T_1 V_20 ;
bool V_656 , V_344 = false ;
int V_657 = V_658 ;
if ( V_14 -> V_109 . V_342 . V_343 )
V_657 = V_14 -> V_109 . V_342 . V_343 ( V_14 , & V_20 , & V_344 , false ) ;
if ( V_657 )
return V_657 ;
V_20 = V_14 -> V_345 . V_659 ;
if ( ( ! V_20 ) && ( V_14 -> V_109 . V_342 . V_660 ) )
V_657 = V_14 -> V_109 . V_342 . V_660 ( V_14 , & V_20 ,
& V_656 ) ;
if ( V_657 )
return V_657 ;
if ( V_14 -> V_109 . V_342 . V_661 )
V_657 = V_14 -> V_109 . V_342 . V_661 ( V_14 , V_20 , V_344 ) ;
return V_657 ;
}
static void F_375 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_662 = 0 ;
if ( V_2 -> V_140 & V_399 ) {
V_662 = V_663 | V_664 |
V_665 ;
V_662 |= V_666 ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
F_71 ( V_14 , V_667 , V_668 ) ;
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
F_71 ( V_14 , V_667 , V_668 ) ;
}
if ( V_2 -> V_140 & V_419 ) {
V_662 &= ~ V_669 ;
switch ( V_2 -> V_424 [ V_501 ] . V_118 ) {
case V_502 :
V_662 |= V_670 ;
break;
case V_504 :
V_662 |= V_671 ;
break;
default:
V_662 |= V_672 ;
break;
}
}
if ( V_2 -> V_155 & V_337 ) {
switch ( V_2 -> V_14 . V_109 . type ) {
case V_112 :
V_662 |= V_673 ;
break;
default:
break;
}
}
if ( V_2 -> V_140 & V_349 )
V_662 |= F_377 ( V_14 ) ;
switch ( V_14 -> V_109 . type ) {
case V_112 :
V_662 |= V_674 | V_675 ;
break;
case V_115 :
V_662 |= V_676 ;
break;
default:
break;
}
F_71 ( V_14 , V_677 , V_662 ) ;
}
static void F_378 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 ;
T_1 V_101 ;
F_72 ( V_2 ) ;
F_375 ( V_2 ) ;
if ( V_2 -> V_140 & V_399 )
F_200 ( V_2 ) ;
else
F_247 ( V_2 ) ;
if ( V_14 -> V_109 . V_342 . V_678 )
V_14 -> V_109 . V_342 . V_678 ( V_14 ) ;
if ( V_14 -> V_345 . V_342 . V_679 )
V_14 -> V_345 . V_342 . V_679 ( V_14 , true ) ;
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
F_37 ( V_14 , V_350 ) ;
F_221 ( V_2 , true , true ) ;
if ( V_2 -> V_140 & V_349 ) {
T_1 V_680 = F_37 ( V_14 , V_681 ) ;
if ( V_680 & V_682 )
F_208 ( V_157 , L_71 ) ;
}
V_2 -> V_140 |= V_362 ;
V_2 -> V_363 = V_172 ;
F_379 ( & V_2 -> V_683 , V_172 ) ;
V_101 = F_37 ( V_14 , V_102 ) ;
V_101 |= V_684 ;
F_71 ( V_14 , V_102 , V_101 ) ;
}
void F_380 ( struct V_1 * V_2 )
{
F_381 ( F_382 () ) ;
V_2 -> V_56 -> V_75 = V_172 ;
while ( F_15 ( V_685 , & V_2 -> V_35 ) )
F_252 ( 1000 , 2000 ) ;
F_383 ( V_2 ) ;
if ( V_2 -> V_140 & V_419 )
F_384 ( 2000 ) ;
F_385 ( V_2 ) ;
F_34 ( V_685 , & V_2 -> V_35 ) ;
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
T_4 V_686 [ V_568 ] ;
if ( F_22 ( V_14 -> V_40 ) )
return;
while ( F_15 ( V_687 , & V_2 -> V_35 ) )
F_252 ( 1000 , 2000 ) ;
V_2 -> V_155 &= ~ ( V_655 |
V_358 ) ;
V_2 -> V_140 &= ~ V_360 ;
V_17 = V_14 -> V_109 . V_342 . V_688 ( V_14 ) ;
switch ( V_17 ) {
case 0 :
case V_689 :
case V_690 :
break;
case V_691 :
F_18 ( L_92 ) ;
break;
case V_692 :
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
F_34 ( V_687 , & V_2 -> V_35 ) ;
memcpy ( V_686 , & V_2 -> V_561 [ 0 ] . V_564 , V_56 -> V_693 ) ;
F_304 ( V_2 ) ;
F_307 ( V_2 , V_686 ) ;
if ( V_14 -> V_109 . V_694 )
V_14 -> V_109 . V_342 . V_695 ( V_14 , F_281 ( 0 ) ) ;
if ( F_14 ( V_696 , & V_2 -> V_35 ) )
F_387 ( V_2 ) ;
if ( V_14 -> V_345 . V_342 . V_679 ) {
if ( ! F_57 ( V_2 -> V_56 ) && ! V_2 -> V_697 )
V_14 -> V_345 . V_342 . V_679 ( V_14 , false ) ;
else
V_14 -> V_345 . V_342 . V_679 ( V_14 , true ) ;
}
}
static void F_388 ( struct V_58 * V_59 )
{
struct V_60 * V_79 ;
unsigned long V_281 ;
T_2 V_49 ;
if ( ! V_59 -> V_79 )
return;
for ( V_49 = 0 ; V_49 < V_59 -> V_89 ; V_49 ++ ) {
V_79 = & V_59 -> V_79 [ V_49 ] ;
F_77 ( V_59 , V_79 ) ;
}
F_389 ( F_107 ( V_59 ) ) ;
V_281 = sizeof( struct V_60 ) * V_59 -> V_89 ;
memset ( V_59 -> V_79 , 0 , V_281 ) ;
memset ( V_59 -> V_88 , 0 , V_59 -> V_281 ) ;
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
struct V_624 * V_625 ;
struct V_626 * V_627 ;
F_346 ( & V_2 -> V_628 ) ;
F_349 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_393 ( & V_627 -> V_698 ) ;
F_241 ( V_627 ) ;
}
V_2 -> V_699 = 0 ;
F_351 ( & V_2 -> V_628 ) ;
}
void F_383 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_56 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_55 * V_96 ;
struct V_648 * V_649 ;
int V_49 ;
if ( F_15 ( V_34 , & V_2 -> V_35 ) )
return;
V_14 -> V_109 . V_342 . V_544 ( V_14 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_94 ; V_49 ++ )
F_275 ( V_2 , V_2 -> V_68 [ V_49 ] ) ;
F_252 ( 10000 , 20000 ) ;
F_358 ( V_56 ) ;
F_394 ( V_56 ) ;
F_395 ( V_56 ) ;
F_366 (adapter->netdev, upper, iter) {
if ( F_367 ( V_96 ) ) {
struct V_650 * V_254 = F_89 ( V_96 ) ;
if ( V_254 -> V_652 ) {
F_358 ( V_96 ) ;
F_394 ( V_96 ) ;
F_395 ( V_96 ) ;
}
}
}
F_245 ( V_2 ) ;
F_322 ( V_2 ) ;
V_2 -> V_155 &= ~ ( V_374 |
V_156 ) ;
V_2 -> V_140 &= ~ V_362 ;
F_396 ( & V_2 -> V_683 ) ;
if ( V_2 -> V_309 ) {
F_71 ( & V_2 -> V_14 , V_311 , 0 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_309 ; V_49 ++ )
V_2 -> V_516 [ V_49 ] . V_700 = false ;
F_397 ( V_2 ) ;
F_398 ( V_2 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ ) {
T_4 V_150 = V_2 -> V_59 [ V_49 ] -> V_150 ;
F_71 ( V_14 , F_50 ( V_150 ) , V_701 ) ;
}
switch ( V_14 -> V_109 . type ) {
case V_112 :
case V_113 :
case V_114 :
case V_115 :
F_71 ( V_14 , V_435 ,
( F_37 ( V_14 , V_435 ) &
~ V_436 ) ) ;
break;
default:
break;
}
if ( ! F_399 ( V_2 -> V_9 ) )
F_386 ( V_2 ) ;
if ( V_14 -> V_109 . V_342 . V_702 )
V_14 -> V_109 . V_342 . V_702 ( V_14 ) ;
F_391 ( V_2 ) ;
F_390 ( V_2 ) ;
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
unsigned int V_209 , V_703 ;
T_1 V_704 ;
#ifdef F_369
int V_50 ;
struct V_705 * V_135 ;
#endif
V_14 -> V_706 = V_9 -> V_707 ;
V_14 -> V_21 = V_9 -> V_194 ;
V_14 -> V_708 = V_9 -> V_709 ;
V_14 -> V_710 = V_9 -> V_711 ;
V_14 -> V_712 = V_9 -> V_713 ;
V_209 = F_361 ( int , F_402 ( V_2 ) , F_403 () ) ;
V_2 -> V_424 [ V_425 ] . V_714 = V_209 ;
V_2 -> V_155 |= V_715 ;
V_2 -> V_716 = V_717 ;
V_2 -> V_409 = 20 ;
V_703 = F_361 ( int , V_718 , F_403 () ) ;
V_2 -> V_424 [ V_719 ] . V_714 = V_703 ;
V_2 -> V_621 = V_720 ;
#ifdef F_232
V_2 -> V_140 |= V_196 ;
#endif
#ifdef F_175
V_2 -> V_140 |= V_721 ;
V_2 -> V_140 &= ~ V_524 ;
#ifdef F_369
V_2 -> V_613 . V_614 = V_722 ;
#endif
#endif
V_2 -> V_561 = F_404 ( sizeof( struct V_723 ) *
V_14 -> V_109 . V_560 ,
V_724 ) ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
V_2 -> V_155 &= ~ V_715 ;
if ( V_14 -> V_21 == V_725 )
V_2 -> V_140 |= V_349 ;
V_2 -> V_716 = V_726 ;
V_2 -> V_424 [ V_719 ] . V_714 = 0 ;
V_2 -> V_409 = 0 ;
V_2 -> V_621 = 0 ;
#ifdef F_175
V_2 -> V_140 &= ~ V_721 ;
V_2 -> V_140 &= ~ V_524 ;
#ifdef F_369
V_2 -> V_613 . V_614 = 0 ;
#endif
#endif
break;
case V_112 :
if ( V_14 -> V_21 == V_339 )
V_2 -> V_155 |= V_337 ;
break;
case V_113 :
V_704 = F_37 ( V_14 , F_405 ( V_14 ) ) ;
if ( V_704 & V_727 )
V_2 -> V_155 |= V_337 ;
break;
case V_115 :
case V_114 :
#ifdef F_232
V_2 -> V_140 &= ~ V_196 ;
#endif
#ifdef F_326
V_2 -> V_140 |= V_728 ;
#endif
break;
default:
break;
}
#ifdef F_175
F_406 ( & V_2 -> V_613 . V_729 ) ;
#endif
F_406 ( & V_2 -> V_628 ) ;
#ifdef F_369
switch ( V_14 -> V_109 . type ) {
case V_113 :
case V_114 :
case V_115 :
V_2 -> V_137 . V_730 . V_731 = V_732 ;
V_2 -> V_137 . V_730 . V_733 = V_732 ;
break;
default:
V_2 -> V_137 . V_730 . V_731 = V_618 ;
V_2 -> V_137 . V_730 . V_733 = V_618 ;
break;
}
for ( V_50 = 0 ; V_50 < V_618 ; V_50 ++ ) {
V_135 = & V_2 -> V_137 . V_734 [ V_50 ] ;
V_135 -> V_735 [ V_601 ] . V_736 = 0 ;
V_135 -> V_735 [ V_601 ] . V_737 = 12 + ( V_50 & 1 ) ;
V_135 -> V_735 [ V_602 ] . V_736 = 0 ;
V_135 -> V_735 [ V_602 ] . V_737 = 12 + ( V_50 & 1 ) ;
V_135 -> V_738 = V_739 ;
}
V_135 = & V_2 -> V_137 . V_734 [ 0 ] ;
V_135 -> V_735 [ V_601 ] . V_740 = 0xFF ;
V_135 -> V_735 [ V_602 ] . V_740 = 0xFF ;
V_2 -> V_137 . V_741 [ V_601 ] [ 0 ] = 100 ;
V_2 -> V_137 . V_741 [ V_602 ] [ 0 ] = 100 ;
V_2 -> V_137 . V_138 = false ;
V_2 -> V_742 = 0x00 ;
V_2 -> V_599 = V_743 | V_600 ;
memcpy ( & V_2 -> V_744 , & V_2 -> V_137 ,
sizeof( V_2 -> V_744 ) ) ;
#endif
V_14 -> V_126 . V_745 = V_128 ;
V_14 -> V_126 . V_127 = V_128 ;
F_343 ( V_2 ) ;
V_14 -> V_126 . V_746 = V_747 ;
V_14 -> V_126 . V_748 = true ;
V_14 -> V_126 . V_749 = F_407 ( V_14 ) ;
#ifdef F_299
if ( V_750 > 0 )
F_11 ( L_100 ) ;
if ( V_14 -> V_109 . type != V_110 ) {
if ( V_750 > V_751 ) {
V_2 -> V_309 = 0 ;
F_11 ( L_101 ) ;
} else {
V_2 -> V_309 = V_750 ;
}
}
#endif
V_2 -> V_390 = 1 ;
V_2 -> V_752 = 1 ;
V_2 -> V_753 = V_754 ;
V_2 -> V_755 = V_756 ;
V_2 -> V_757 = V_758 ;
if ( F_408 ( V_14 ) ) {
F_18 ( L_102 ) ;
return - V_759 ;
}
F_250 ( 0 , & V_2 -> V_644 ) ;
F_250 ( V_34 , & V_2 -> V_35 ) ;
return 0 ;
}
int F_409 ( struct V_58 * V_59 )
{
struct V_194 * V_74 = V_59 -> V_74 ;
int V_760 = F_410 ( V_74 ) ;
int V_761 = - 1 ;
int V_281 ;
V_281 = sizeof( struct V_60 ) * V_59 -> V_89 ;
if ( V_59 -> V_159 )
V_761 = V_59 -> V_159 -> V_762 ;
V_59 -> V_79 = F_411 ( V_281 , V_761 ) ;
if ( ! V_59 -> V_79 )
V_59 -> V_79 = F_412 ( V_281 ) ;
if ( ! V_59 -> V_79 )
goto V_17;
F_413 ( & V_59 -> V_170 ) ;
V_59 -> V_281 = V_59 -> V_89 * sizeof( union V_62 ) ;
V_59 -> V_281 = F_169 ( V_59 -> V_281 , 4096 ) ;
F_414 ( V_74 , V_761 ) ;
V_59 -> V_88 = F_415 ( V_74 ,
V_59 -> V_281 ,
& V_59 -> V_82 ,
V_763 ) ;
F_414 ( V_74 , V_760 ) ;
if ( ! V_59 -> V_88 )
V_59 -> V_88 = F_415 ( V_74 , V_59 -> V_281 ,
& V_59 -> V_82 , V_763 ) ;
if ( ! V_59 -> V_88 )
goto V_17;
V_59 -> V_81 = 0 ;
V_59 -> V_80 = 0 ;
return 0 ;
V_17:
F_416 ( V_59 -> V_79 ) ;
V_59 -> V_79 = NULL ;
F_417 ( V_74 , L_103 ) ;
return - V_559 ;
}
static int F_418 ( struct V_1 * V_2 )
{
int V_49 , V_17 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ ) {
V_17 = F_409 ( V_2 -> V_59 [ V_49 ] ) ;
if ( ! V_17 )
continue;
F_103 ( V_173 , L_104 , V_49 ) ;
goto V_764;
}
return 0 ;
V_764:
while ( V_49 -- )
F_419 ( V_2 -> V_59 [ V_49 ] ) ;
return V_17 ;
}
int F_420 ( struct V_58 * V_68 )
{
struct V_194 * V_74 = V_68 -> V_74 ;
int V_760 = F_410 ( V_74 ) ;
int V_761 = - 1 ;
int V_281 ;
V_281 = sizeof( struct V_71 ) * V_68 -> V_89 ;
if ( V_68 -> V_159 )
V_761 = V_68 -> V_159 -> V_762 ;
V_68 -> V_72 = F_411 ( V_281 , V_761 ) ;
if ( ! V_68 -> V_72 )
V_68 -> V_72 = F_412 ( V_281 ) ;
if ( ! V_68 -> V_72 )
goto V_17;
F_413 ( & V_68 -> V_170 ) ;
V_68 -> V_281 = V_68 -> V_89 * sizeof( union V_69 ) ;
V_68 -> V_281 = F_169 ( V_68 -> V_281 , 4096 ) ;
F_414 ( V_74 , V_761 ) ;
V_68 -> V_88 = F_415 ( V_74 ,
V_68 -> V_281 ,
& V_68 -> V_82 ,
V_763 ) ;
F_414 ( V_74 , V_760 ) ;
if ( ! V_68 -> V_88 )
V_68 -> V_88 = F_415 ( V_74 , V_68 -> V_281 ,
& V_68 -> V_82 , V_763 ) ;
if ( ! V_68 -> V_88 )
goto V_17;
V_68 -> V_80 = 0 ;
V_68 -> V_81 = 0 ;
return 0 ;
V_17:
F_416 ( V_68 -> V_72 ) ;
V_68 -> V_72 = NULL ;
F_417 ( V_74 , L_105 ) ;
return - V_559 ;
}
static int F_421 ( struct V_1 * V_2 )
{
int V_49 , V_17 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_94 ; V_49 ++ ) {
V_17 = F_420 ( V_2 -> V_68 [ V_49 ] ) ;
if ( ! V_17 )
continue;
F_103 ( V_173 , L_106 , V_49 ) ;
goto V_765;
}
#ifdef F_175
V_17 = F_422 ( V_2 ) ;
if ( ! V_17 )
#endif
return 0 ;
V_765:
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
F_424 ( V_59 -> V_74 , V_59 -> V_281 ,
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
F_424 ( V_68 -> V_74 , V_68 -> V_281 ,
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
static int F_428 ( struct V_55 * V_56 , int V_766 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
int V_519 = V_766 + V_520 + V_521 ;
if ( ( V_766 < 68 ) || ( V_519 > V_767 ) )
return - V_570 ;
if ( ( V_2 -> V_140 & V_419 ) &&
( V_2 -> V_14 . V_109 . type == V_112 ) &&
( V_519 > ( V_526 + V_521 ) ) )
F_93 ( V_173 , L_107 ) ;
F_105 ( V_173 , L_108 , V_56 -> V_297 , V_766 ) ;
V_56 -> V_297 = V_766 ;
if ( F_57 ( V_56 ) )
F_380 ( V_2 ) ;
return 0 ;
}
static int F_429 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 , V_367 ;
if ( F_14 ( V_768 , & V_2 -> V_35 ) )
return - V_769 ;
F_394 ( V_56 ) ;
V_17 = F_418 ( V_2 ) ;
if ( V_17 )
goto V_764;
V_17 = F_421 ( V_2 ) ;
if ( V_17 )
goto V_765;
F_368 ( V_2 ) ;
V_17 = F_243 ( V_2 ) ;
if ( V_17 )
goto V_770;
if ( V_2 -> V_645 > 1 )
V_367 = V_2 -> V_636 ;
else
V_367 = V_2 -> V_78 ;
V_17 = F_362 ( V_56 , V_367 ) ;
if ( V_17 )
goto V_771;
if ( V_2 -> V_645 > 1 &&
V_2 -> V_94 > V_772 )
V_367 = V_772 ;
else
V_367 = V_2 -> V_94 ;
V_17 = F_363 ( V_56 , V_367 ) ;
if ( V_17 )
goto V_771;
F_430 ( V_2 ) ;
F_378 ( V_2 ) ;
F_325 ( V_2 ) ;
#ifdef F_326
F_431 ( V_56 ) ;
#endif
return 0 ;
V_771:
F_244 ( V_2 ) ;
V_770:
F_426 ( V_2 ) ;
if ( V_14 -> V_345 . V_342 . V_679 && ! V_2 -> V_697 )
V_14 -> V_345 . V_342 . V_679 ( & V_2 -> V_14 , false ) ;
V_765:
F_425 ( V_2 ) ;
V_764:
F_386 ( V_2 ) ;
return V_17 ;
}
static void F_432 ( struct V_1 * V_2 )
{
F_433 ( V_2 ) ;
if ( V_2 -> V_14 . V_345 . V_342 . V_773 ) {
V_2 -> V_14 . V_345 . V_774 = true ;
F_383 ( V_2 ) ;
V_2 -> V_14 . V_345 . V_342 . V_773 ( & V_2 -> V_14 ) ;
V_2 -> V_14 . V_345 . V_774 = false ;
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
V_2 -> V_14 . V_40 = V_2 -> V_408 ;
F_438 ( V_9 , V_775 ) ;
F_439 ( V_9 ) ;
F_440 ( V_9 ) ;
V_17 = F_441 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_109 ) ;
return V_17 ;
}
F_33 () ;
F_34 ( V_776 , & V_2 -> V_35 ) ;
F_442 ( V_9 ) ;
F_443 ( V_9 , false ) ;
F_386 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_777 , ~ 0 ) ;
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
static int F_448 ( struct V_5 * V_9 , bool * V_778 )
{
struct V_1 * V_2 = F_437 ( V_9 ) ;
struct V_55 * V_56 = V_2 -> V_56 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_779 , V_574 ;
T_1 V_780 = V_2 -> V_697 ;
#ifdef F_449
int V_781 = 0 ;
#endif
F_450 ( V_56 ) ;
F_444 () ;
if ( F_57 ( V_56 ) )
F_432 ( V_2 ) ;
F_446 () ;
F_451 ( V_2 ) ;
#ifdef F_449
V_781 = F_440 ( V_9 ) ;
if ( V_781 )
return V_781 ;
#endif
if ( V_14 -> V_109 . V_342 . V_782 )
V_14 -> V_109 . V_342 . V_782 ( V_14 ) ;
if ( V_780 ) {
F_317 ( V_56 ) ;
if ( V_14 -> V_109 . V_342 . V_678 )
V_14 -> V_109 . V_342 . V_678 ( V_14 ) ;
if ( V_780 & V_783 ) {
V_574 = F_37 ( V_14 , V_578 ) ;
V_574 |= V_584 ;
F_71 ( V_14 , V_578 , V_574 ) ;
}
V_779 = F_37 ( V_14 , V_784 ) ;
V_779 |= V_785 ;
F_71 ( V_14 , V_784 , V_779 ) ;
F_71 ( V_14 , V_786 , V_780 ) ;
} else {
F_71 ( V_14 , V_787 , 0 ) ;
F_71 ( V_14 , V_786 , 0 ) ;
}
switch ( V_14 -> V_109 . type ) {
case V_110 :
F_443 ( V_9 , false ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
F_443 ( V_9 , ! ! V_780 ) ;
break;
default:
break;
}
* V_778 = ! ! V_780 ;
if ( V_14 -> V_345 . V_342 . V_679 && ! * V_778 )
V_14 -> V_345 . V_342 . V_679 ( V_14 , false ) ;
F_70 ( V_2 ) ;
if ( ! F_15 ( V_776 , & V_2 -> V_35 ) )
F_452 ( V_9 ) ;
return 0 ;
}
static int F_453 ( struct V_5 * V_9 , T_13 V_35 )
{
int V_781 ;
bool V_788 ;
V_781 = F_448 ( V_9 , & V_788 ) ;
if ( V_781 )
return V_781 ;
if ( V_788 ) {
F_454 ( V_9 ) ;
} else {
F_443 ( V_9 , false ) ;
F_438 ( V_9 , V_789 ) ;
}
return 0 ;
}
static void F_455 ( struct V_5 * V_9 )
{
bool V_788 ;
F_448 ( V_9 , & V_788 ) ;
if ( V_790 == V_791 ) {
F_443 ( V_9 , V_788 ) ;
F_438 ( V_9 , V_789 ) ;
}
}
void F_456 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_56 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_123 * V_124 = & V_2 -> V_125 ;
T_6 V_792 = 0 ;
T_1 V_49 , V_793 = 0 , V_794 , V_795 , V_796 , V_797 , V_798 ;
T_6 V_266 = 0 , V_175 = 0 , V_799 = 0 ;
T_6 V_237 = 0 , V_290 = 0 ;
T_6 V_171 = 0 , V_145 = 0 , V_800 = 0 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_685 , & V_2 -> V_35 ) )
return;
if ( V_2 -> V_155 & V_532 ) {
T_6 V_248 = 0 ;
T_6 V_249 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_94 ; V_49 ++ ) {
V_248 += V_2 -> V_68 [ V_49 ] -> V_225 . V_248 ;
V_249 += V_2 -> V_68 [ V_49 ] -> V_225 . V_249 ;
}
V_2 -> V_801 = V_248 ;
V_2 -> V_802 = V_249 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_94 ; V_49 ++ ) {
struct V_58 * V_68 = V_2 -> V_68 [ V_49 ] ;
V_266 += V_68 -> V_225 . V_266 ;
V_237 += V_68 -> V_225 . V_237 ;
V_290 += V_68 -> V_225 . V_290 ;
V_800 += V_68 -> V_225 . V_226 ;
V_171 += V_68 -> V_125 . V_171 ;
V_145 += V_68 -> V_125 . V_145 ;
}
V_2 -> V_266 = V_266 ;
V_2 -> V_237 = V_237 ;
V_2 -> V_290 = V_290 ;
V_2 -> V_800 = V_800 ;
V_56 -> V_125 . V_803 = V_171 ;
V_56 -> V_125 . V_804 = V_145 ;
V_171 = 0 ;
V_145 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ ) {
struct V_58 * V_59 = V_2 -> V_59 [ V_49 ] ;
V_175 += V_59 -> V_153 . V_175 ;
V_799 += V_59 -> V_153 . V_799 ;
V_171 += V_59 -> V_125 . V_171 ;
V_145 += V_59 -> V_125 . V_145 ;
}
V_2 -> V_175 = V_175 ;
V_2 -> V_799 = V_799 ;
V_56 -> V_125 . V_805 = V_171 ;
V_56 -> V_125 . V_806 = V_145 ;
V_124 -> V_807 += F_37 ( V_14 , V_808 ) ;
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
V_794 = F_37 ( V_14 , F_457 ( V_49 ) ) ;
V_793 += V_794 ;
V_124 -> V_794 [ V_49 ] += V_794 ;
V_792 += V_124 -> V_794 [ V_49 ] ;
V_124 -> V_809 [ V_49 ] += F_37 ( V_14 , F_458 ( V_49 ) ) ;
V_124 -> V_810 [ V_49 ] += F_37 ( V_14 , F_459 ( V_49 ) ) ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
V_124 -> V_811 [ V_49 ] += F_37 ( V_14 , F_460 ( V_49 ) ) ;
V_124 -> V_812 [ V_49 ] += F_37 ( V_14 , F_461 ( V_49 ) ) ;
V_124 -> V_813 [ V_49 ] += F_37 ( V_14 , F_462 ( V_49 ) ) ;
V_124 -> V_814 [ V_49 ] +=
F_37 ( V_14 , F_463 ( V_49 ) ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_124 -> V_814 [ V_49 ] +=
F_37 ( V_14 , F_464 ( V_49 ) ) ;
break;
default:
break;
}
}
for ( V_49 = 0 ; V_49 < 16 ; V_49 ++ ) {
V_124 -> V_815 [ V_49 ] += F_37 ( V_14 , F_465 ( V_49 ) ) ;
V_124 -> V_816 [ V_49 ] += F_37 ( V_14 , F_466 ( V_49 ) ) ;
if ( ( V_14 -> V_109 . type == V_112 ) ||
( V_14 -> V_109 . type == V_113 ) ||
( V_14 -> V_109 . type == V_114 ) ||
( V_14 -> V_109 . type == V_115 ) ) {
V_124 -> V_812 [ V_49 ] += F_37 ( V_14 , F_467 ( V_49 ) ) ;
F_37 ( V_14 , F_468 ( V_49 ) ) ;
V_124 -> V_813 [ V_49 ] += F_37 ( V_14 , F_469 ( V_49 ) ) ;
F_37 ( V_14 , F_470 ( V_49 ) ) ;
}
}
V_124 -> V_817 += F_37 ( V_14 , V_818 ) ;
V_124 -> V_817 -= V_793 ;
F_83 ( V_2 ) ;
switch ( V_14 -> V_109 . type ) {
case V_110 :
V_124 -> V_819 += F_37 ( V_14 , V_820 ) ;
V_124 -> V_821 += F_37 ( V_14 , V_822 ) ;
V_124 -> V_823 += F_37 ( V_14 , V_824 ) ;
V_124 -> V_825 += F_37 ( V_14 , V_826 ) ;
break;
case V_113 :
case V_114 :
case V_115 :
V_124 -> V_827 += F_37 ( V_14 , V_828 ) ;
V_124 -> V_829 += F_37 ( V_14 , V_830 ) ;
V_124 -> V_831 += F_37 ( V_14 , V_832 ) ;
V_124 -> V_833 += F_37 ( V_14 , V_834 ) ;
case V_112 :
for ( V_49 = 0 ; V_49 < 16 ; V_49 ++ )
V_2 -> V_835 +=
F_37 ( V_14 , F_471 ( V_49 ) ) ;
V_124 -> V_821 += F_37 ( V_14 , V_836 ) ;
F_37 ( V_14 , V_822 ) ;
V_124 -> V_823 += F_37 ( V_14 , V_837 ) ;
F_37 ( V_14 , V_824 ) ;
V_124 -> V_825 += F_37 ( V_14 , V_838 ) ;
F_37 ( V_14 , V_826 ) ;
V_124 -> V_819 += F_37 ( V_14 , V_839 ) ;
V_124 -> V_840 += F_37 ( V_14 , V_841 ) ;
V_124 -> V_842 += F_37 ( V_14 , V_843 ) ;
#ifdef F_175
V_124 -> V_844 += F_37 ( V_14 , V_845 ) ;
V_124 -> V_846 += F_37 ( V_14 , V_847 ) ;
V_124 -> V_848 += F_37 ( V_14 , V_849 ) ;
V_124 -> V_850 += F_37 ( V_14 , V_851 ) ;
V_124 -> V_852 += F_37 ( V_14 , V_853 ) ;
V_124 -> V_854 += F_37 ( V_14 , V_855 ) ;
if ( V_2 -> V_613 . V_856 ) {
struct V_857 * V_613 = & V_2 -> V_613 ;
struct V_858 * V_856 ;
unsigned int V_176 ;
T_6 V_859 = 0 , V_860 = 0 ;
F_472 (cpu) {
V_856 = F_473 ( V_613 -> V_856 , V_176 ) ;
V_859 += V_856 -> V_859 ;
V_860 += V_856 -> V_860 ;
}
V_124 -> V_861 = V_859 ;
V_124 -> V_862 = V_860 ;
}
#endif
break;
default:
break;
}
V_795 = F_37 ( V_14 , V_863 ) ;
V_124 -> V_795 += V_795 ;
V_124 -> V_864 += F_37 ( V_14 , V_865 ) ;
if ( V_14 -> V_109 . type == V_110 )
V_124 -> V_864 -= V_795 ;
V_124 -> V_866 += F_37 ( V_14 , V_867 ) ;
V_124 -> V_868 += F_37 ( V_14 , V_869 ) ;
V_124 -> V_870 += F_37 ( V_14 , V_871 ) ;
V_124 -> V_872 += F_37 ( V_14 , V_873 ) ;
V_124 -> V_874 += F_37 ( V_14 , V_875 ) ;
V_124 -> V_876 += F_37 ( V_14 , V_877 ) ;
V_124 -> V_878 += F_37 ( V_14 , V_879 ) ;
V_124 -> V_880 += F_37 ( V_14 , V_881 ) ;
V_796 = F_37 ( V_14 , V_882 ) ;
V_124 -> V_883 += V_796 ;
V_797 = F_37 ( V_14 , V_884 ) ;
V_124 -> V_885 += V_797 ;
V_124 -> V_886 += F_37 ( V_14 , V_887 ) ;
V_124 -> V_888 += F_37 ( V_14 , V_889 ) ;
V_798 = V_796 + V_797 ;
V_124 -> V_886 -= V_798 ;
V_124 -> V_888 -= V_798 ;
V_124 -> V_823 -= ( V_798 * ( V_890 + V_521 ) ) ;
V_124 -> V_891 += F_37 ( V_14 , V_892 ) ;
V_124 -> V_893 += F_37 ( V_14 , V_894 ) ;
V_124 -> V_895 += F_37 ( V_14 , V_896 ) ;
V_124 -> V_897 += F_37 ( V_14 , V_898 ) ;
V_124 -> V_899 += F_37 ( V_14 , V_900 ) ;
V_124 -> V_899 -= V_798 ;
V_124 -> V_901 += F_37 ( V_14 , V_902 ) ;
V_124 -> V_903 += F_37 ( V_14 , V_904 ) ;
V_124 -> V_905 += F_37 ( V_14 , V_906 ) ;
V_124 -> V_907 += F_37 ( V_14 , V_908 ) ;
V_124 -> V_909 += F_37 ( V_14 , V_910 ) ;
V_124 -> V_911 += F_37 ( V_14 , V_912 ) ;
V_56 -> V_125 . V_913 = V_124 -> V_864 ;
V_56 -> V_125 . V_914 = V_124 -> V_807 + V_124 -> V_880 ;
V_56 -> V_125 . V_915 = 0 ;
V_56 -> V_125 . V_916 = V_124 -> V_880 ;
V_56 -> V_125 . V_917 = V_124 -> V_807 ;
V_56 -> V_125 . V_918 = V_792 ;
}
static void F_474 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( ! ( V_2 -> V_155 & V_374 ) )
return;
V_2 -> V_155 &= ~ V_374 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
if ( ! ( V_2 -> V_140 & V_373 ) )
return;
V_2 -> V_919 ++ ;
if ( F_475 ( V_14 ) == 0 ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ )
F_250 ( V_383 ,
& ( V_2 -> V_59 [ V_49 ] -> V_35 ) ) ;
F_71 ( V_14 , V_366 , V_375 ) ;
} else {
F_103 ( V_173 , L_110
L_111 ) ;
}
}
static void F_476 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_920 = 0 ;
int V_49 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_685 , & V_2 -> V_35 ) )
return;
if ( F_109 ( V_2 -> V_56 ) ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ )
F_477 ( V_2 -> V_59 [ V_49 ] ) ;
}
if ( ! ( V_2 -> V_140 & V_399 ) ) {
F_71 ( V_14 , V_120 ,
( V_921 | V_922 ) ) ;
} else {
for ( V_49 = 0 ; V_49 < V_2 -> V_193 ; V_49 ++ ) {
struct V_158 * V_923 = V_2 -> V_159 [ V_49 ] ;
if ( V_923 -> V_301 . V_121 || V_923 -> V_163 . V_121 )
V_920 |= ( ( T_6 ) 1 << V_49 ) ;
}
}
F_75 ( V_2 , V_920 ) ;
}
static void F_478 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_924 = V_2 -> V_924 ;
bool V_344 = V_2 -> V_344 ;
bool V_136 = V_2 -> V_137 . V_138 ;
if ( ! ( V_2 -> V_140 & V_362 ) )
return;
if ( V_14 -> V_109 . V_342 . V_343 ) {
V_14 -> V_109 . V_342 . V_343 ( V_14 , & V_924 , & V_344 , false ) ;
} else {
V_924 = V_925 ;
V_344 = true ;
}
if ( V_2 -> V_139 )
V_136 |= ! ! ( V_2 -> V_139 -> V_136 ) ;
if ( V_344 && ! ( ( V_2 -> V_140 & V_141 ) && V_136 ) ) {
V_14 -> V_109 . V_342 . V_926 ( V_14 ) ;
F_479 ( V_2 ) ;
}
if ( V_344 ||
F_480 ( V_172 , ( V_2 -> V_363 +
V_927 ) ) ) {
V_2 -> V_140 &= ~ V_362 ;
F_71 ( V_14 , V_366 , V_365 ) ;
F_216 ( V_14 ) ;
}
V_2 -> V_344 = V_344 ;
V_2 -> V_924 = V_924 ;
}
static void F_481 ( struct V_1 * V_2 )
{
#ifdef F_369
struct V_55 * V_56 = V_2 -> V_56 ;
struct V_928 V_929 = {
. V_930 = V_931 ,
. V_256 = 0 ,
} ;
T_4 V_614 = 0 ;
if ( V_2 -> V_599 & V_932 )
V_614 = F_482 ( V_56 , & V_929 ) ;
V_2 -> V_933 = ( V_614 > 1 ) ? ( F_483 ( V_614 ) - 1 ) : 0 ;
#endif
}
static void F_484 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_56 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_55 * V_96 ;
struct V_648 * V_649 ;
T_1 V_924 = V_2 -> V_924 ;
const char * V_934 ;
bool V_935 , V_936 ;
if ( F_109 ( V_56 ) )
return;
V_2 -> V_155 &= ~ V_655 ;
switch ( V_14 -> V_109 . type ) {
case V_110 : {
T_1 V_937 = F_37 ( V_14 , V_578 ) ;
T_1 V_938 = F_37 ( V_14 , V_939 ) ;
V_935 = ! ! ( V_937 & V_940 ) ;
V_936 = ! ! ( V_938 & V_941 ) ;
}
break;
case V_113 :
case V_114 :
case V_115 :
case V_112 : {
T_1 V_942 = F_37 ( V_14 , V_943 ) ;
T_1 V_944 = F_37 ( V_14 , V_945 ) ;
V_935 = ! ! ( V_942 & V_946 ) ;
V_936 = ! ! ( V_944 & V_947 ) ;
}
break;
default:
V_936 = false ;
V_935 = false ;
break;
}
V_2 -> V_948 = V_172 ;
if ( F_14 ( V_696 , & V_2 -> V_35 ) )
F_485 ( V_2 ) ;
switch ( V_924 ) {
case V_925 :
V_934 = L_112 ;
break;
case V_949 :
V_934 = L_113 ;
break;
case V_950 :
V_934 = L_114 ;
break;
case V_951 :
V_934 = L_115 ;
break;
default:
V_934 = L_116 ;
break;
}
F_105 ( V_157 , L_117 , V_934 ,
( ( V_935 && V_936 ) ? L_118 :
( V_935 ? L_119 :
( V_936 ? L_120 : L_121 ) ) ) ) ;
F_486 ( V_56 ) ;
F_487 ( V_2 ) ;
F_488 ( V_2 -> V_56 ) ;
F_444 () ;
F_366 (adapter->netdev, upper, iter) {
if ( F_367 ( V_96 ) ) {
struct V_650 * V_254 = F_89 ( V_96 ) ;
if ( V_254 -> V_652 )
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
V_2 -> V_344 = false ;
V_2 -> V_924 = 0 ;
if ( ! F_109 ( V_56 ) )
return;
if ( F_212 ( V_14 ) && V_14 -> V_109 . type == V_110 )
V_2 -> V_155 |= V_655 ;
if ( F_14 ( V_696 , & V_2 -> V_35 ) )
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
struct V_952 * V_953 = & V_2 -> V_424 [ V_501 ] ;
T_1 V_954 = F_492 ( 1 , ~ V_953 -> V_118 ) ;
int V_49 , V_50 ;
if ( ! V_2 -> V_309 )
return false ;
if ( V_14 -> V_109 . type >= V_114 )
return false ;
for ( V_49 = 0 ; V_49 < V_2 -> V_309 ; V_49 ++ ) {
for ( V_50 = 0 ; V_50 < V_954 ; V_50 ++ ) {
T_1 V_955 , V_956 ;
V_955 = F_37 ( V_14 , F_493 ( V_954 , V_49 , V_50 ) ) ;
V_956 = F_37 ( V_14 , F_494 ( V_954 , V_49 , V_50 ) ) ;
if ( V_955 != V_956 )
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
struct V_5 * V_957 )
{
if ( ! F_497 ( V_957 ) )
F_11 ( L_124 ) ;
F_18 ( L_125 , F_498 ( V_957 ) ) ;
F_499 ( V_957 , V_958 , V_959 ) ;
F_384 ( 100 ) ;
}
static void F_500 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
struct V_5 * V_957 ;
T_1 V_960 ;
int V_961 ;
unsigned short V_962 ;
if ( ! ( F_109 ( V_2 -> V_56 ) ) )
return;
V_960 = F_37 ( V_14 , V_963 ) ;
if ( V_960 )
return;
if ( ! V_9 )
return;
V_961 = F_501 ( V_9 , V_964 ) ;
if ( ! V_961 )
return;
F_25 ( V_9 , V_961 + V_965 , & V_962 ) ;
V_957 = F_502 ( V_9 -> V_707 , V_962 , NULL ) ;
while ( V_957 ) {
if ( V_957 -> V_966 && ( V_957 -> V_967 == V_9 ) ) {
T_2 V_968 ;
F_25 ( V_957 , V_969 , & V_968 ) ;
if ( V_968 & V_970 )
F_496 ( V_2 , V_957 ) ;
}
V_957 = F_502 ( V_9 -> V_707 , V_962 , V_957 ) ;
}
}
static void F_503 ( struct V_1 * V_2 )
{
T_1 V_971 ;
if ( V_2 -> V_14 . V_109 . type == V_110 ||
V_2 -> V_309 == 0 )
return;
V_971 = F_37 ( & V_2 -> V_14 , V_972 ) ;
if ( ! V_971 )
return;
F_93 ( V_157 , L_126 , V_971 ) ;
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
F_14 ( V_685 , & V_2 -> V_35 ) )
return;
F_478 ( V_2 ) ;
if ( V_2 -> V_344 )
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
if ( ! ( V_2 -> V_155 & V_655 ) &&
! ( V_2 -> V_155 & V_358 ) )
return;
if ( V_2 -> V_359 &&
F_480 ( V_2 -> V_359 , V_172 ) )
return;
if ( F_15 ( V_687 , & V_2 -> V_35 ) )
return;
V_2 -> V_359 = V_172 + V_973 - 1 ;
V_17 = V_14 -> V_345 . V_342 . V_974 ( V_14 ) ;
if ( V_17 == V_690 )
goto V_975;
if ( V_17 == V_689 ) {
V_2 -> V_155 |= V_358 ;
}
if ( V_17 )
goto V_975;
if ( ! ( V_2 -> V_155 & V_358 ) )
goto V_975;
V_2 -> V_155 &= ~ V_358 ;
if ( V_14 -> V_109 . type == V_110 )
V_17 = V_14 -> V_345 . V_342 . V_976 ( V_14 ) ;
else
V_17 = V_14 -> V_109 . V_342 . V_977 ( V_14 ) ;
if ( V_17 == V_690 )
goto V_975;
V_2 -> V_140 |= V_360 ;
F_105 ( V_173 , L_127 , V_14 -> V_345 . V_978 ) ;
V_975:
F_34 ( V_687 , & V_2 -> V_35 ) ;
if ( ( V_17 == V_690 ) &&
( V_2 -> V_56 -> V_979 == V_980 ) ) {
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
bool V_656 = false ;
if ( ! ( V_2 -> V_140 & V_360 ) )
return;
if ( F_15 ( V_687 , & V_2 -> V_35 ) )
return;
V_2 -> V_140 &= ~ V_360 ;
V_20 = V_14 -> V_345 . V_659 ;
if ( ( ! V_20 ) && ( V_14 -> V_109 . V_342 . V_660 ) ) {
V_14 -> V_109 . V_342 . V_660 ( V_14 , & V_20 , & V_656 ) ;
if ( ! V_656 ) {
if ( V_20 & V_925 )
V_20 = V_925 ;
}
}
if ( V_14 -> V_109 . V_342 . V_661 )
V_14 -> V_109 . V_342 . V_661 ( V_14 , V_20 , true ) ;
V_2 -> V_140 |= V_362 ;
V_2 -> V_363 = V_172 ;
F_34 ( V_687 , & V_2 -> V_35 ) ;
}
static void F_508 ( unsigned long V_93 )
{
struct V_1 * V_2 = (struct V_1 * ) V_93 ;
unsigned long V_981 ;
if ( V_2 -> V_140 & V_362 )
V_981 = V_982 / 10 ;
else
V_981 = V_982 * 2 ;
F_379 ( & V_2 -> V_683 , V_981 + V_172 ) ;
F_13 ( V_2 ) ;
}
static void F_509 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_166 ;
if ( ! ( V_2 -> V_155 & V_378 ) )
return;
V_2 -> V_155 &= ~ V_378 ;
if ( ! V_14 -> V_345 . V_342 . V_983 )
return;
V_166 = V_14 -> V_345 . V_342 . V_983 ( & V_2 -> V_14 ) ;
if ( V_166 != V_347 )
return;
F_208 ( V_157 , L_70 , V_348 ) ;
}
static void F_510 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_155 & V_156 ) )
return;
V_2 -> V_155 &= ~ V_156 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_685 , & V_2 -> V_35 ) )
return;
F_54 ( V_2 ) ;
F_511 ( V_2 -> V_56 , L_132 ) ;
V_2 -> V_174 ++ ;
F_444 () ;
F_380 ( V_2 ) ;
F_446 () ;
}
static void F_512 ( struct V_984 * V_985 )
{
struct V_1 * V_2 = F_196 ( V_985 ,
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
if ( V_2 -> V_155 & V_986 ) {
V_2 -> V_155 &= ~ V_986 ;
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
if ( F_14 ( V_696 , & V_2 -> V_35 ) ) {
F_513 ( V_2 ) ;
F_514 ( V_2 ) ;
}
F_31 ( V_2 ) ;
}
static int F_515 ( struct V_58 * V_59 ,
struct V_60 * V_987 ,
T_4 * V_243 )
{
struct V_199 * V_90 = V_987 -> V_90 ;
T_1 V_988 , V_989 ;
T_1 V_990 , V_991 ;
int V_17 ;
if ( V_90 -> V_231 != V_992 )
return 0 ;
if ( ! F_516 ( V_90 ) )
return 0 ;
V_17 = F_517 ( V_90 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_989 = V_993 ;
if ( V_987 -> V_256 == F_156 ( V_994 ) ) {
struct V_995 * V_996 = F_518 ( V_90 ) ;
V_996 -> V_997 = 0 ;
V_996 -> V_998 = 0 ;
F_519 ( V_90 ) -> V_998 = ~ F_520 ( V_996 -> V_999 ,
V_996 -> V_1000 , 0 ,
V_1001 ,
0 ) ;
V_989 |= V_1002 ;
V_987 -> V_1003 |= V_1004 |
V_1005 |
V_1006 ;
} else if ( F_521 ( V_90 ) ) {
F_522 ( V_90 ) -> V_1007 = 0 ;
F_519 ( V_90 ) -> V_998 =
~ F_523 ( & F_522 ( V_90 ) -> V_999 ,
& F_522 ( V_90 ) -> V_1000 ,
0 , V_1001 , 0 ) ;
V_987 -> V_1003 |= V_1004 |
V_1005 ;
}
V_991 = F_524 ( V_90 ) ;
* V_243 = F_525 ( V_90 ) + V_991 ;
V_987 -> V_169 = F_149 ( V_90 ) -> V_169 ;
V_987 -> V_168 += ( V_987 -> V_169 - 1 ) * * V_243 ;
V_990 = V_991 << V_1008 ;
V_990 |= F_149 ( V_90 ) -> V_244 << V_1009 ;
V_988 = F_526 ( V_90 ) ;
V_988 |= F_527 ( V_90 ) << V_1010 ;
V_988 |= V_987 -> V_1003 & V_1011 ;
F_528 ( V_59 , V_988 , 0 , V_989 ,
V_990 ) ;
return 1 ;
}
static void F_529 ( struct V_58 * V_59 ,
struct V_60 * V_987 )
{
struct V_199 * V_90 = V_987 -> V_90 ;
T_1 V_988 = 0 ;
T_1 V_990 = 0 ;
T_1 V_989 = 0 ;
if ( V_90 -> V_231 != V_992 ) {
if ( ! ( V_987 -> V_1003 & V_1012 ) &&
! ( V_987 -> V_1003 & V_1013 ) )
return;
V_988 = F_527 ( V_90 ) <<
V_1010 ;
} else {
T_4 V_1014 = 0 ;
union {
struct V_995 * V_1015 ;
struct V_1016 * V_1017 ;
T_4 * V_1018 ;
} V_1019 ;
union {
struct V_1020 * V_1020 ;
T_4 * V_1018 ;
} V_1021 ;
if ( V_90 -> V_222 ) {
V_1019 . V_1018 = F_530 ( V_90 ) ;
V_1021 . V_1018 = F_531 ( V_90 ) ;
V_988 = F_532 ( V_90 ) <<
V_1010 ;
} else {
V_1019 . V_1018 = F_533 ( V_90 ) ;
V_1021 . V_1018 = F_534 ( V_90 ) ;
V_988 = F_527 ( V_90 ) <<
V_1010 ;
}
switch ( V_1019 . V_1015 -> V_1022 ) {
case V_1023 :
V_988 |= V_1021 . V_1018 - V_1019 . V_1018 ;
V_989 |= V_1002 ;
V_1014 = V_1019 . V_1015 -> V_256 ;
break;
case 6 :
V_988 |= V_1021 . V_1018 - V_1019 . V_1018 ;
V_1014 = V_1019 . V_1017 -> V_1024 ;
break;
default:
if ( F_24 ( F_535 () ) ) {
F_536 ( V_59 -> V_74 ,
L_133 ,
V_1019 . V_1015 -> V_1022 ) ;
}
}
switch ( V_1014 ) {
case V_1001 :
V_989 |= V_993 ;
V_990 = ( V_1021 . V_1020 -> V_1025 * 4 ) <<
V_1008 ;
break;
case V_1026 :
V_989 |= V_1027 ;
V_990 = sizeof( struct V_1028 ) <<
V_1008 ;
break;
case V_1029 :
V_990 = sizeof( struct V_1030 ) <<
V_1008 ;
break;
default:
if ( F_24 ( F_535 () ) ) {
F_536 ( V_59 -> V_74 ,
L_134 ,
V_1014 ) ;
}
break;
}
V_987 -> V_1003 |= V_1005 ;
}
V_988 |= V_987 -> V_1003 & V_1011 ;
F_528 ( V_59 , V_988 , 0 ,
V_989 , V_990 ) ;
}
static T_1 F_537 ( struct V_199 * V_90 , T_1 V_1003 )
{
T_1 V_1031 = V_1032 |
V_1033 |
V_1034 ;
V_1031 |= F_538 ( V_1003 , V_1012 ,
V_1035 ) ;
V_1031 |= F_538 ( V_1003 , V_1004 ,
V_1036 ) ;
V_1031 |= F_538 ( V_1003 , V_1037 ,
V_1038 ) ;
V_1031 ^= F_538 ( V_90 -> V_1039 , 1 , V_1034 ) ;
return V_1031 ;
}
static void F_539 ( union V_62 * V_63 ,
T_1 V_1003 , unsigned int V_1040 )
{
T_1 V_1041 = V_1040 << V_1042 ;
V_1041 |= F_538 ( V_1003 ,
V_1005 ,
V_1043 ) ;
V_1041 |= F_538 ( V_1003 ,
V_1006 ,
V_1044 ) ;
V_1041 |= F_538 ( V_1003 ,
V_1013 ,
V_1045 ) ;
V_63 -> V_240 . V_1041 = F_96 ( V_1041 ) ;
}
static int F_540 ( struct V_58 * V_59 , T_2 V_281 )
{
F_104 ( V_59 -> V_56 , V_59 -> V_87 ) ;
F_111 () ;
if ( F_99 ( F_110 ( V_59 ) < V_281 ) )
return - V_769 ;
F_541 ( V_59 -> V_56 , V_59 -> V_87 ) ;
++ V_59 -> V_153 . V_175 ;
return 0 ;
}
static inline int F_542 ( struct V_58 * V_59 , T_2 V_281 )
{
if ( F_99 ( F_110 ( V_59 ) >= V_281 ) )
return 0 ;
return F_540 ( V_59 , V_281 ) ;
}
static void F_543 ( struct V_58 * V_59 ,
struct V_60 * V_987 ,
const T_4 V_243 )
{
struct V_199 * V_90 = V_987 -> V_90 ;
struct V_60 * V_61 ;
union V_62 * V_63 ;
struct V_267 * V_268 ;
T_9 V_82 ;
unsigned int V_273 , V_281 ;
T_1 V_1003 = V_987 -> V_1003 ;
T_1 V_1031 = F_537 ( V_90 , V_1003 ) ;
T_2 V_49 = V_59 -> V_81 ;
V_63 = F_61 ( V_59 , V_49 ) ;
F_539 ( V_63 , V_1003 , V_90 -> V_83 - V_243 ) ;
V_281 = F_148 ( V_90 ) ;
V_273 = V_90 -> V_273 ;
#ifdef F_175
if ( V_1003 & V_1046 ) {
if ( V_273 < sizeof( struct V_300 ) ) {
V_281 -= sizeof( struct V_300 ) - V_273 ;
V_273 = 0 ;
} else {
V_273 -= sizeof( struct V_300 ) ;
}
}
#endif
V_82 = F_544 ( V_59 -> V_74 , V_90 -> V_93 , V_281 , V_122 ) ;
V_61 = V_987 ;
for ( V_268 = & F_149 ( V_90 ) -> V_269 [ 0 ] ; ; V_268 ++ ) {
if ( F_141 ( V_59 -> V_74 , V_82 ) )
goto V_1047;
F_81 ( V_61 , V_83 , V_281 ) ;
F_545 ( V_61 , V_82 , V_82 ) ;
V_63 -> V_240 . V_1048 = F_144 ( V_82 ) ;
while ( F_24 ( V_281 > V_1049 ) ) {
V_63 -> V_240 . V_1050 =
F_96 ( V_1031 ^ V_1049 ) ;
V_49 ++ ;
V_63 ++ ;
if ( V_49 == V_59 -> V_89 ) {
V_63 = F_61 ( V_59 , 0 ) ;
V_49 = 0 ;
}
V_63 -> V_240 . V_1041 = 0 ;
V_82 += V_1049 ;
V_281 -= V_1049 ;
V_63 -> V_240 . V_1048 = F_144 ( V_82 ) ;
}
if ( F_99 ( ! V_273 ) )
break;
V_63 -> V_240 . V_1050 = F_96 ( V_1031 ^ V_281 ) ;
V_49 ++ ;
V_63 ++ ;
if ( V_49 == V_59 -> V_89 ) {
V_63 = F_61 ( V_59 , 0 ) ;
V_49 = 0 ;
}
V_63 -> V_240 . V_1041 = 0 ;
#ifdef F_175
V_281 = F_361 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_281 = F_546 ( V_268 ) ;
#endif
V_273 -= V_281 ;
V_82 = F_547 ( V_59 -> V_74 , V_268 , 0 , V_281 ,
V_122 ) ;
V_61 = & V_59 -> V_79 [ V_49 ] ;
}
V_1031 |= V_281 | V_1051 ;
V_63 -> V_240 . V_1050 = F_96 ( V_1031 ) ;
F_548 ( F_107 ( V_59 ) , V_987 -> V_168 ) ;
V_987 -> V_85 = V_172 ;
F_145 () ;
V_987 -> V_84 = V_63 ;
V_49 ++ ;
if ( V_49 == V_59 -> V_89 )
V_49 = 0 ;
V_59 -> V_81 = V_49 ;
F_542 ( V_59 , V_1052 ) ;
if ( F_549 ( F_107 ( V_59 ) ) || ! V_90 -> V_1053 ) {
F_146 ( V_49 , V_59 -> V_147 ) ;
F_550 () ;
}
return;
V_1047:
F_417 ( V_59 -> V_74 , L_135 ) ;
for (; ; ) {
V_61 = & V_59 -> V_79 [ V_49 ] ;
F_77 ( V_59 , V_61 ) ;
if ( V_61 == V_987 )
break;
if ( V_49 == 0 )
V_49 = V_59 -> V_89 ;
V_49 -- ;
}
V_59 -> V_81 = V_49 ;
}
static void F_551 ( struct V_58 * V_121 ,
struct V_60 * V_987 )
{
struct V_158 * V_159 = V_121 -> V_159 ;
union V_1054 V_1055 = { . V_1056 = 0 } ;
union V_1054 V_1057 = { . V_1056 = 0 } ;
union {
unsigned char * V_1058 ;
struct V_995 * V_1015 ;
struct V_1016 * V_1017 ;
} V_1059 ;
struct V_1020 * V_1060 ;
struct V_199 * V_90 ;
#ifdef F_326
T_4 V_1061 = false ;
#endif
T_12 V_1062 ;
if ( ! V_159 )
return;
if ( ! V_121 -> V_409 )
return;
V_121 -> V_410 ++ ;
V_90 = V_987 -> V_90 ;
V_1059 . V_1058 = F_533 ( V_90 ) ;
if ( V_90 -> V_222 ) {
#ifdef F_326
struct V_1 * V_2 = V_159 -> V_2 ;
if ( ! V_2 -> V_597 )
return;
if ( V_987 -> V_256 != F_156 ( V_994 ) ||
V_1059 . V_1015 -> V_1022 != V_1023 ||
V_1059 . V_1015 -> V_256 != V_1029 ) {
return;
}
if ( F_552 ( F_553 ( V_90 ) -> V_1063 ) != V_2 -> V_597 )
return;
V_1061 = true ;
V_1059 . V_1058 = F_530 ( V_90 ) ;
V_1060 = F_554 ( V_90 ) ;
#else
return;
#endif
} else {
if ( ( V_987 -> V_256 != F_156 ( V_1064 ) ||
V_1059 . V_1017 -> V_1024 != V_1001 ) &&
( V_987 -> V_256 != F_156 ( V_994 ) ||
V_1059 . V_1015 -> V_256 != V_1001 ) )
return;
V_1060 = F_519 ( V_90 ) ;
}
if ( ! V_1060 || V_1060 -> V_1065 )
return;
if ( ! V_1060 -> V_1066 && ( V_121 -> V_410 < V_121 -> V_409 ) )
return;
V_121 -> V_410 = 0 ;
V_1062 = F_156 ( V_987 -> V_1003 >> V_1067 ) ;
V_1055 . V_1068 . V_1062 = V_1062 ;
if ( V_987 -> V_1003 & ( V_1069 | V_1012 ) )
V_1057 . V_1070 . V_1071 ^= V_1060 -> V_1063 ^ F_156 ( V_255 ) ;
else
V_1057 . V_1070 . V_1071 ^= V_1060 -> V_1063 ^ V_987 -> V_256 ;
V_1057 . V_1070 . V_1072 ^= V_1060 -> V_1073 ;
if ( V_987 -> V_256 == F_156 ( V_994 ) ) {
V_1055 . V_1068 . V_1074 = V_1075 ;
V_1057 . V_1076 ^= V_1059 . V_1015 -> V_999 ^ V_1059 . V_1015 -> V_1000 ;
} else {
V_1055 . V_1068 . V_1074 = V_1077 ;
V_1057 . V_1076 ^= V_1059 . V_1017 -> V_999 . V_1078 [ 0 ] ^
V_1059 . V_1017 -> V_999 . V_1078 [ 1 ] ^
V_1059 . V_1017 -> V_999 . V_1078 [ 2 ] ^
V_1059 . V_1017 -> V_999 . V_1078 [ 3 ] ^
V_1059 . V_1017 -> V_1000 . V_1078 [ 0 ] ^
V_1059 . V_1017 -> V_1000 . V_1078 [ 1 ] ^
V_1059 . V_1017 -> V_1000 . V_1078 [ 2 ] ^
V_1059 . V_1017 -> V_1000 . V_1078 [ 3 ] ;
}
#ifdef F_326
if ( V_1061 )
V_1055 . V_1068 . V_1074 |= V_1079 ;
#endif
F_555 ( & V_159 -> V_2 -> V_14 ,
V_1055 , V_1057 , V_121 -> V_87 ) ;
}
static T_2 F_556 ( struct V_55 * V_74 , struct V_199 * V_90 ,
void * V_1080 , T_15 V_1081 )
{
struct V_634 * V_1082 = V_1080 ;
#ifdef F_175
struct V_1 * V_2 ;
struct V_952 * V_1083 ;
int V_1084 ;
#endif
if ( V_1082 )
return V_90 -> V_1085 + V_1082 -> V_642 ;
#ifdef F_175
switch ( F_557 ( V_90 ) ) {
case F_156 ( V_1086 ) :
case F_156 ( V_1087 ) :
V_2 = F_89 ( V_74 ) ;
if ( V_2 -> V_140 & V_524 )
break;
default:
return V_1081 ( V_74 , V_90 ) ;
}
V_1083 = & V_2 -> V_424 [ V_1088 ] ;
V_1084 = F_558 ( V_90 ) ? F_559 ( V_90 ) :
F_560 () ;
while ( V_1084 >= V_1083 -> V_426 )
V_1084 -= V_1083 -> V_426 ;
return V_1084 + V_1083 -> V_1089 ;
#else
return V_1081 ( V_74 , V_90 ) ;
#endif
}
T_16 F_561 ( struct V_199 * V_90 ,
struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_60 * V_987 ;
int V_1090 ;
T_1 V_1003 = 0 ;
unsigned short V_1083 ;
T_2 V_89 = F_562 ( F_148 ( V_90 ) ) ;
T_12 V_256 = V_90 -> V_256 ;
T_4 V_243 = 0 ;
for ( V_1083 = 0 ; V_1083 < F_149 ( V_90 ) -> V_287 ; V_1083 ++ )
V_89 += F_562 ( F_149 ( V_90 ) -> V_269 [ V_1083 ] . V_281 ) ;
if ( F_542 ( V_59 , V_89 + 3 ) ) {
V_59 -> V_153 . V_799 ++ ;
return V_1091 ;
}
V_987 = & V_59 -> V_79 [ V_59 -> V_81 ] ;
V_987 -> V_90 = V_90 ;
V_987 -> V_168 = V_90 -> V_83 ;
V_987 -> V_169 = 1 ;
if ( F_563 ( V_90 ) ) {
V_1003 |= F_564 ( V_90 ) << V_1067 ;
V_1003 |= V_1012 ;
} else if ( V_256 == F_156 ( V_255 ) ) {
struct V_1092 * V_1093 , V_1094 ;
V_1093 = F_565 ( V_90 , V_520 , sizeof( V_1094 ) , & V_1094 ) ;
if ( ! V_1093 )
goto V_1095;
V_1003 |= F_552 ( V_1093 -> V_1096 ) <<
V_1067 ;
V_1003 |= V_1069 ;
}
V_256 = F_557 ( V_90 ) ;
if ( F_24 ( F_149 ( V_90 ) -> V_1003 & V_1097 ) &&
V_2 -> V_1098 &&
! F_566 ( V_1099 ,
& V_2 -> V_35 ) ) {
F_149 ( V_90 ) -> V_1003 |= V_1100 ;
V_1003 |= V_1037 ;
V_2 -> V_1101 = F_567 ( V_90 ) ;
V_2 -> V_1102 = V_172 ;
F_16 ( & V_2 -> V_1103 ) ;
}
F_568 ( V_90 ) ;
#ifdef F_299
if ( V_2 -> V_140 & V_419 )
V_1003 |= V_1013 ;
#endif
if ( ( V_2 -> V_140 & V_141 ) &&
( ( V_1003 & ( V_1012 | V_1069 ) ) ||
( V_90 -> V_1104 != V_1105 ) ) ) {
V_1003 &= ~ V_1106 ;
V_1003 |= ( V_90 -> V_1104 & 0x7 ) <<
V_1107 ;
if ( V_1003 & V_1069 ) {
struct V_1108 * V_1093 ;
if ( F_517 ( V_90 , 0 ) )
goto V_1095;
V_1093 = (struct V_1108 * ) V_90 -> V_93 ;
V_1093 -> V_1096 = F_156 ( V_1003 >>
V_1067 ) ;
} else {
V_1003 |= V_1012 ;
}
}
V_987 -> V_1003 = V_1003 ;
V_987 -> V_256 = V_256 ;
#ifdef F_175
if ( ( V_256 == F_156 ( V_1086 ) ) &&
( V_59 -> V_56 -> V_201 & ( V_1109 | V_1110 ) ) ) {
V_1090 = F_569 ( V_59 , V_987 , & V_243 ) ;
if ( V_1090 < 0 )
goto V_1095;
goto V_1111;
}
#endif
V_1090 = F_515 ( V_59 , V_987 , & V_243 ) ;
if ( V_1090 < 0 )
goto V_1095;
else if ( ! V_1090 )
F_529 ( V_59 , V_987 ) ;
if ( F_14 ( V_383 , & V_59 -> V_35 ) )
F_551 ( V_59 , V_987 ) ;
#ifdef F_175
V_1111:
#endif
F_543 ( V_59 , V_987 , V_243 ) ;
return V_1112 ;
V_1095:
F_78 ( V_987 -> V_90 ) ;
V_987 -> V_90 = NULL ;
return V_1112 ;
}
static T_16 F_570 ( struct V_199 * V_90 ,
struct V_55 * V_56 ,
struct V_58 * V_121 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
struct V_58 * V_59 ;
if ( F_571 ( V_90 , 17 ) )
return V_1112 ;
V_59 = V_121 ? V_121 : V_2 -> V_59 [ V_90 -> V_1085 ] ;
return F_561 ( V_90 , V_2 , V_59 ) ;
}
static T_16 F_572 ( struct V_199 * V_90 ,
struct V_55 * V_56 )
{
return F_570 ( V_90 , V_56 , NULL ) ;
}
static int F_573 ( struct V_55 * V_56 , void * V_1113 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1114 * V_564 = V_1113 ;
int V_657 ;
if ( ! F_364 ( V_564 -> V_1115 ) )
return - V_1116 ;
F_311 ( V_2 , V_14 -> V_109 . V_564 , F_281 ( 0 ) ) ;
memcpy ( V_56 -> V_647 , V_564 -> V_1115 , V_56 -> V_693 ) ;
memcpy ( V_14 -> V_109 . V_564 , V_564 -> V_1115 , V_56 -> V_693 ) ;
V_657 = F_308 ( V_2 , V_14 -> V_109 . V_564 , F_281 ( 0 ) ) ;
return V_657 > 0 ? 0 : V_657 ;
}
static int
F_574 ( struct V_55 * V_56 , int V_1117 , int V_1118 , T_2 V_564 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_4 ;
int V_1119 ;
if ( V_1117 != V_14 -> V_345 . V_1120 . V_1117 )
return - V_570 ;
V_1119 = V_14 -> V_345 . V_342 . V_1121 ( V_14 , V_564 , V_1118 , & V_4 ) ;
if ( ! V_1119 )
V_1119 = V_4 ;
return V_1119 ;
}
static int F_575 ( struct V_55 * V_56 , int V_1117 , int V_1118 ,
T_2 V_564 , T_2 V_4 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_1117 != V_14 -> V_345 . V_1120 . V_1117 )
return - V_570 ;
return V_14 -> V_345 . V_342 . V_1122 ( V_14 , V_564 , V_1118 , V_4 ) ;
}
static int F_576 ( struct V_55 * V_56 , struct V_1123 * V_1124 , int V_1125 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
switch ( V_1125 ) {
case V_1126 :
return F_577 ( V_2 , V_1124 ) ;
case V_1127 :
return F_578 ( V_2 , V_1124 ) ;
default:
return F_579 ( & V_2 -> V_14 . V_345 . V_1120 , F_580 ( V_1124 ) , V_1125 ) ;
}
}
static int F_581 ( struct V_55 * V_74 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_74 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_364 ( V_14 -> V_109 . V_1128 ) ) {
F_444 () ;
V_17 = F_582 ( V_74 , V_14 -> V_109 . V_1128 , V_1129 ) ;
F_446 () ;
V_14 -> V_109 . V_342 . V_695 ( V_14 , F_281 ( 0 ) ) ;
}
return V_17 ;
}
static int F_583 ( struct V_55 * V_74 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_74 ) ;
struct V_1130 * V_109 = & V_2 -> V_14 . V_109 ;
if ( F_364 ( V_109 -> V_1128 ) ) {
F_444 () ;
V_17 = F_584 ( V_74 , V_109 -> V_1128 , V_1129 ) ;
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
for ( V_49 = 0 ; V_49 < V_2 -> V_193 ; V_49 ++ )
F_229 ( 0 , V_2 -> V_159 [ V_49 ] ) ;
}
static struct V_1131 * F_586 ( struct V_55 * V_56 ,
struct V_1131 * V_125 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
int V_49 ;
F_587 () ;
for ( V_49 = 0 ; V_49 < V_2 -> V_94 ; V_49 ++ ) {
struct V_58 * V_121 = F_21 ( V_2 -> V_68 [ V_49 ] ) ;
T_6 V_171 , V_145 ;
unsigned int V_1132 ;
if ( V_121 ) {
do {
V_1132 = F_588 ( & V_121 -> V_170 ) ;
V_145 = V_121 -> V_125 . V_145 ;
V_171 = V_121 -> V_125 . V_171 ;
} while ( F_589 ( & V_121 -> V_170 , V_1132 ) );
V_125 -> V_804 += V_145 ;
V_125 -> V_803 += V_171 ;
}
}
for ( V_49 = 0 ; V_49 < V_2 -> V_78 ; V_49 ++ ) {
struct V_58 * V_121 = F_21 ( V_2 -> V_59 [ V_49 ] ) ;
T_6 V_171 , V_145 ;
unsigned int V_1132 ;
if ( V_121 ) {
do {
V_1132 = F_588 ( & V_121 -> V_170 ) ;
V_145 = V_121 -> V_125 . V_145 ;
V_171 = V_121 -> V_125 . V_171 ;
} while ( F_589 ( & V_121 -> V_170 , V_1132 ) );
V_125 -> V_806 += V_145 ;
V_125 -> V_805 += V_171 ;
}
}
F_590 () ;
V_125 -> V_913 = V_56 -> V_125 . V_913 ;
V_125 -> V_914 = V_56 -> V_125 . V_914 ;
V_125 -> V_916 = V_56 -> V_125 . V_916 ;
V_125 -> V_917 = V_56 -> V_125 . V_917 ;
V_125 -> V_918 = V_56 -> V_125 . V_918 ;
return V_125 ;
}
static void F_591 ( struct V_1 * V_2 , T_4 V_135 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_3 , V_1133 ;
int V_49 ;
if ( V_14 -> V_109 . type == V_110 )
return;
V_3 = F_37 ( V_14 , V_1134 ) ;
V_1133 = V_3 ;
for ( V_49 = 0 ; V_49 < V_618 ; V_49 ++ ) {
T_4 V_1135 = V_3 >> ( V_49 * V_1136 ) ;
if ( V_1135 > V_135 )
V_3 &= ~ ( 0x7 << V_1136 ) ;
}
if ( V_3 != V_1133 )
F_71 ( V_14 , V_1134 , V_3 ) ;
return;
}
static void F_592 ( struct V_1 * V_2 )
{
struct V_55 * V_74 = V_2 -> V_56 ;
struct V_1137 * V_137 = & V_2 -> V_137 ;
struct V_1138 * V_1139 = V_2 -> V_603 ;
T_4 V_1140 ;
for ( V_1140 = 0 ; V_1140 < V_1141 ; V_1140 ++ ) {
T_4 V_135 = 0 ;
if ( V_2 -> V_599 & V_600 )
V_135 = F_593 ( V_137 , 0 , V_1140 ) ;
else if ( V_1139 )
V_135 = V_1139 -> V_604 [ V_1140 ] ;
F_594 ( V_74 , V_1140 , V_135 ) ;
}
}
int F_595 ( struct V_55 * V_74 , T_4 V_135 )
{
struct V_1 * V_2 = F_89 ( V_74 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
bool V_1142 ;
if ( V_135 > V_2 -> V_137 . V_730 . V_731 )
return - V_570 ;
if ( V_14 -> V_109 . type == V_110 && V_135 && V_135 < V_618 )
return - V_570 ;
V_1142 = ( F_596 ( & V_2 -> V_644 , 32 ) > 1 ) ;
if ( V_135 && V_1142 && V_2 -> V_645 > V_1143 )
return - V_769 ;
if ( F_57 ( V_74 ) )
F_434 ( V_74 ) ;
else
F_386 ( V_2 ) ;
F_451 ( V_2 ) ;
#ifdef F_369
if ( V_135 ) {
F_597 ( V_74 , V_135 ) ;
F_592 ( V_2 ) ;
V_2 -> V_140 |= V_141 ;
if ( V_2 -> V_14 . V_109 . type == V_110 ) {
V_2 -> V_1144 = V_2 -> V_14 . V_126 . V_745 ;
V_2 -> V_14 . V_126 . V_745 = V_1145 ;
}
} else {
F_598 ( V_74 ) ;
if ( V_2 -> V_14 . V_109 . type == V_110 )
V_2 -> V_14 . V_126 . V_745 = V_2 -> V_1144 ;
V_2 -> V_140 &= ~ V_141 ;
V_2 -> V_744 . V_138 = false ;
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
T_17 V_201 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
if ( ! ( V_201 & V_219 ) )
V_201 &= ~ V_1146 ;
if ( ! ( V_2 -> V_155 & V_715 ) )
V_201 &= ~ V_1146 ;
return V_201 ;
}
static int F_602 ( struct V_55 * V_56 ,
T_17 V_201 )
{
struct V_1 * V_2 = F_89 ( V_56 ) ;
T_17 V_1147 = V_56 -> V_201 ^ V_201 ;
bool V_1148 = false ;
if ( ! ( V_201 & V_1146 ) ) {
if ( V_2 -> V_155 & V_532 )
V_1148 = true ;
V_2 -> V_155 &= ~ V_532 ;
} else if ( ( V_2 -> V_155 & V_715 ) &&
! ( V_2 -> V_155 & V_532 ) ) {
if ( V_2 -> V_390 == 1 ||
V_2 -> V_390 > V_1149 ) {
V_2 -> V_155 |= V_532 ;
V_1148 = true ;
} else if ( ( V_1147 ^ V_201 ) & V_1146 ) {
F_105 ( V_173 , L_136
L_137 ) ;
}
}
switch ( V_201 & V_1150 ) {
case V_1150 :
if ( ! ( V_2 -> V_140 & V_620 ) )
V_1148 = true ;
V_2 -> V_140 &= ~ V_373 ;
V_2 -> V_140 |= V_620 ;
break;
default:
if ( V_2 -> V_140 & V_620 )
V_1148 = true ;
V_2 -> V_140 &= ~ V_620 ;
if ( V_2 -> V_140 & V_419 )
break;
if ( F_254 ( V_56 ) > 1 )
break;
if ( V_2 -> V_424 [ V_425 ] . V_714 <= 1 )
break;
if ( ! V_2 -> V_409 )
break;
V_2 -> V_140 |= V_373 ;
break;
}
if ( V_201 & V_251 )
F_296 ( V_2 ) ;
else
F_295 ( V_2 ) ;
if ( V_1147 & V_276 )
V_1148 = true ;
V_56 -> V_201 = V_201 ;
#ifdef F_326
if ( ( V_2 -> V_140 & V_728 ) ) {
if ( V_201 & V_219 )
V_2 -> V_155 |= V_986 ;
else
F_325 ( V_2 ) ;
}
#endif
if ( V_1148 )
F_600 ( V_56 ) ;
return 0 ;
}
static void F_603 ( struct V_55 * V_74 , T_18 V_1151 ,
T_12 V_1070 )
{
struct V_1 * V_2 = F_89 ( V_74 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1152 = F_552 ( V_1070 ) ;
if ( ! ( V_2 -> V_140 & V_728 ) )
return;
if ( V_1151 == V_1153 )
return;
if ( V_2 -> V_597 == V_1152 )
return;
if ( V_2 -> V_597 ) {
F_604 ( V_74 ,
L_138 ,
V_1152 ) ;
return;
}
V_2 -> V_597 = V_1152 ;
F_71 ( V_14 , V_596 , V_1152 ) ;
}
static void F_605 ( struct V_55 * V_74 , T_18 V_1151 ,
T_12 V_1070 )
{
struct V_1 * V_2 = F_89 ( V_74 ) ;
T_2 V_1152 = F_552 ( V_1070 ) ;
if ( ! ( V_2 -> V_140 & V_728 ) )
return;
if ( V_1151 == V_1153 )
return;
if ( V_2 -> V_597 != V_1152 ) {
F_604 ( V_74 , L_139 ,
V_1152 ) ;
return;
}
F_325 ( V_2 ) ;
V_2 -> V_155 |= V_986 ;
}
static int F_606 ( struct V_1154 * V_1155 , struct V_1156 * V_1157 [] ,
struct V_55 * V_74 ,
const unsigned char * V_564 , T_2 V_253 ,
T_2 V_140 )
{
if ( F_607 ( V_564 ) || F_608 ( V_564 ) ) {
if ( V_1158 <= F_314 ( V_74 ) )
return - V_559 ;
}
return F_609 ( V_1155 , V_1157 , V_74 , V_564 , V_253 , V_140 ) ;
}
static int F_610 ( struct V_1 * V_2 ,
T_19 V_1159 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
unsigned int V_1113 , V_1160 ;
T_1 V_490 ;
switch ( V_1159 ) {
case V_1161 :
F_71 ( & V_2 -> V_14 , V_498 , 0 ) ;
V_490 = F_37 ( V_14 , V_1162 ) ;
V_490 |= V_495 ;
F_71 ( V_14 , V_1162 , V_490 ) ;
V_1160 = V_2 -> V_309 + V_2 -> V_645 ;
for ( V_1113 = 0 ; V_1113 < V_1160 ; V_1113 ++ ) {
if ( V_14 -> V_109 . V_342 . V_1163 )
V_14 -> V_109 . V_342 . V_1163 ( V_14 ,
true ,
V_1113 ) ;
}
break;
case V_497 :
F_71 ( & V_2 -> V_14 , V_498 ,
V_499 ) ;
V_490 = F_37 ( V_14 , V_1162 ) ;
if ( ! V_2 -> V_309 )
V_490 &= ~ V_495 ;
F_71 ( V_14 , V_1162 , V_490 ) ;
V_1160 = V_2 -> V_309 + V_2 -> V_645 ;
for ( V_1113 = 0 ; V_1113 < V_1160 ; V_1113 ++ ) {
if ( V_14 -> V_109 . V_342 . V_1163 )
V_14 -> V_109 . V_342 . V_1163 ( V_14 ,
false ,
V_1113 ) ;
}
break;
default:
return - V_570 ;
}
V_2 -> V_496 = V_1159 ;
F_105 ( V_157 , L_140 ,
V_1159 == V_1161 ? L_141 : L_142 ) ;
return 0 ;
}
static int F_611 ( struct V_55 * V_74 ,
struct V_1164 * V_1165 , T_2 V_140 )
{
struct V_1 * V_2 = F_89 ( V_74 ) ;
struct V_1156 * V_1166 , * V_1167 ;
int V_1168 ;
if ( ! ( V_2 -> V_140 & V_419 ) )
return - V_1169 ;
V_1167 = F_612 ( V_1165 , sizeof( struct V_1170 ) , V_1171 ) ;
if ( ! V_1167 )
return - V_570 ;
F_613 (attr, br_spec, rem) {
int V_166 ;
T_19 V_1159 ;
if ( F_614 ( V_1166 ) != V_1172 )
continue;
if ( F_615 ( V_1166 ) < sizeof( V_1159 ) )
return - V_570 ;
V_1159 = F_616 ( V_1166 ) ;
V_166 = F_610 ( V_2 , V_1159 ) ;
if ( V_166 )
return V_166 ;
break;
}
return 0 ;
}
static int F_617 ( struct V_199 * V_90 , T_1 V_1173 , T_1 V_1174 ,
struct V_55 * V_74 ,
T_1 V_1175 , int V_1176 )
{
struct V_1 * V_2 = F_89 ( V_74 ) ;
if ( ! ( V_2 -> V_140 & V_419 ) )
return 0 ;
return F_618 ( V_90 , V_1173 , V_1174 , V_74 ,
V_2 -> V_496 , 0 , 0 , V_1176 ,
V_1175 , NULL ) ;
}
static void * F_619 ( struct V_55 * V_9 , struct V_55 * V_638 )
{
struct V_634 * V_1082 = NULL ;
struct V_1 * V_2 = F_89 ( V_9 ) ;
int V_1177 = V_2 -> V_309 + V_2 -> V_645 ;
unsigned int V_714 ;
int V_481 , V_17 ;
if ( V_1177 >= V_1178 )
return F_620 ( - V_570 ) ;
#ifdef F_621
if ( V_638 -> V_94 != V_638 -> V_78 ) {
F_604 ( V_9 , L_143 ,
V_638 -> V_54 ) ;
return F_620 ( - V_570 ) ;
}
#endif
if ( V_638 -> V_78 > V_772 ||
V_638 -> V_78 == V_1179 ) {
F_604 ( V_9 ,
L_144 ,
V_9 -> V_54 ) ;
return F_620 ( - V_570 ) ;
}
if ( ( ( V_2 -> V_140 & V_141 ) &&
V_2 -> V_645 > V_1143 - 1 ) ||
( V_2 -> V_645 > V_1180 ) )
return F_620 ( - V_769 ) ;
V_1082 = F_404 ( sizeof( * V_1082 ) , V_763 ) ;
if ( ! V_1082 )
return F_620 ( - V_559 ) ;
V_481 = F_596 ( & V_2 -> V_644 , 32 ) ;
V_2 -> V_645 ++ ;
F_250 ( V_481 , & V_2 -> V_644 ) ;
V_714 = F_622 ( & V_2 -> V_644 , 32 ) ;
V_2 -> V_140 |= V_591 | V_419 ;
V_2 -> V_424 [ V_501 ] . V_714 = V_714 + 1 ;
V_2 -> V_424 [ V_425 ] . V_714 = V_638 -> V_78 ;
V_17 = F_595 ( V_9 , F_254 ( V_9 ) ) ;
if ( V_17 )
goto V_1181;
V_1082 -> V_481 = V_481 ;
V_1082 -> V_149 = V_2 ;
V_17 = F_359 ( V_638 , V_1082 ) ;
if ( V_17 )
goto V_1181;
F_623 ( V_638 ) ;
return V_1082 ;
V_1181:
F_604 ( V_9 ,
L_145 , V_638 -> V_54 ) ;
F_34 ( V_481 , & V_2 -> V_644 ) ;
V_2 -> V_645 -- ;
F_241 ( V_1082 ) ;
return F_620 ( V_17 ) ;
}
static void F_624 ( struct V_55 * V_9 , void * V_1182 )
{
struct V_634 * V_1082 = V_1182 ;
struct V_1 * V_2 = V_1082 -> V_149 ;
unsigned int V_714 ;
F_34 ( V_1082 -> V_481 , & V_2 -> V_644 ) ;
V_2 -> V_645 -- ;
V_714 = F_622 ( & V_2 -> V_644 , 32 ) ;
V_2 -> V_424 [ V_501 ] . V_714 = V_714 + 1 ;
F_357 ( V_1082 -> V_56 , V_1082 ) ;
F_595 ( V_9 , F_254 ( V_9 ) ) ;
F_360 ( V_9 , L_90 ,
V_1082 -> V_481 , V_2 -> V_645 ,
V_1082 -> V_637 ,
V_1082 -> V_637 + V_2 -> V_636 ,
V_2 -> V_644 ) ;
F_241 ( V_1082 ) ;
}
static T_17
F_625 ( struct V_199 * V_90 , struct V_55 * V_74 ,
T_17 V_201 )
{
if ( ! V_90 -> V_222 )
return V_201 ;
if ( F_24 ( F_626 ( V_90 ) - F_534 ( V_90 ) >
V_1183 ) )
return V_201 & ~ V_1184 ;
return V_201 ;
}
static inline int F_627 ( struct V_1 * V_2 )
{
struct V_5 * V_395 , * V_9 = V_2 -> V_9 ;
int V_1185 = 0 ;
if ( F_8 ( & V_2 -> V_14 ) )
V_1185 = 4 ;
F_628 (entry, &adapter->pdev->bus->devices, bus_list) {
if ( V_395 -> V_966 )
continue;
if ( ( V_395 -> V_707 != V_9 -> V_707 ) ||
( V_395 -> V_194 != V_9 -> V_194 ) )
return - 1 ;
V_1185 ++ ;
}
return V_1185 ;
}
int F_629 ( struct V_1 * V_2 , T_2 V_21 ,
T_2 V_1186 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1187 = V_2 -> V_1188 & V_1189 ;
int V_1190 = 0 ;
switch ( V_21 ) {
case V_1191 :
switch ( V_1186 ) {
case V_1192 :
case V_1193 :
if ( V_14 -> V_10 . V_1194 != 0 )
break;
case V_1195 :
case V_1196 :
case V_1197 :
case V_1198 :
case V_1199 :
V_1190 = 1 ;
break;
}
break;
case V_1200 :
switch ( V_1186 ) {
case V_1201 :
V_1190 = 1 ;
break;
}
break;
case V_1202 :
if ( V_1186 != V_1203 )
V_1190 = 1 ;
break;
case V_1204 :
V_1190 = 1 ;
break;
case V_1205 :
case V_1206 :
case V_1207 :
case V_1208 :
case V_1209 :
case V_1210 :
if ( ( V_1187 == V_1211 ) ||
( ( V_1187 == V_1212 ) &&
( V_14 -> V_10 . V_1194 == 0 ) ) ) {
V_1190 = 1 ;
}
break;
}
return V_1190 ;
}
static void F_630 ( struct V_1 * V_2 )
{
#ifdef F_631
struct V_1213 * V_1214 = F_632 ( V_2 -> V_9 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
const unsigned char * V_564 ;
V_564 = F_633 ( V_1214 ) ;
if ( V_564 ) {
F_310 ( V_14 -> V_109 . V_1215 , V_564 ) ;
return;
}
#endif
#ifdef F_634
F_310 ( V_14 -> V_109 . V_1215 , V_1216 -> V_1217 ) ;
#endif
}
static int F_635 ( struct V_5 * V_9 , const struct V_1218 * V_1219 )
{
struct V_55 * V_56 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_14 ;
const struct V_1220 * V_1221 = V_1222 [ V_1219 -> V_1223 ] ;
int V_49 , V_17 , V_1224 , V_24 ;
unsigned int V_426 = V_1225 ;
T_4 V_1226 [ V_1227 ] ;
bool V_1228 = false ;
#ifdef F_175
T_2 V_1229 ;
#endif
T_1 V_1230 ;
if ( V_9 -> V_966 ) {
F_636 ( 1 , V_1231 L_146 ,
F_498 ( V_9 ) , V_9 -> V_707 , V_9 -> V_194 ) ;
return - V_570 ;
}
V_17 = F_441 ( V_9 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_637 ( & V_9 -> V_74 , F_249 ( 64 ) ) ) {
V_1224 = 1 ;
} else {
V_17 = F_637 ( & V_9 -> V_74 , F_249 ( 32 ) ) ;
if ( V_17 ) {
F_417 ( & V_9 -> V_74 ,
L_147 ) ;
goto V_1232;
}
V_1224 = 0 ;
}
V_17 = F_638 ( V_9 , F_639 ( V_9 ,
V_1233 ) , V_1234 ) ;
if ( V_17 ) {
F_417 ( & V_9 -> V_74 ,
L_148 , V_17 ) ;
goto V_1235;
}
F_640 ( V_9 ) ;
F_442 ( V_9 ) ;
F_440 ( V_9 ) ;
if ( V_1221 -> V_109 == V_110 ) {
#ifdef F_369
V_426 = 4 * V_618 ;
#else
V_426 = V_1236 ;
#endif
}
V_56 = F_641 ( sizeof( struct V_1 ) , V_426 ) ;
if ( ! V_56 ) {
V_17 = - V_559 ;
goto V_1237;
}
F_642 ( V_56 , & V_9 -> V_74 ) ;
V_2 = F_89 ( V_56 ) ;
V_2 -> V_56 = V_56 ;
V_2 -> V_9 = V_9 ;
V_14 = & V_2 -> V_14 ;
V_14 -> V_39 = V_2 ;
V_2 -> V_1238 = F_643 ( V_1239 , V_1240 ) ;
V_14 -> V_40 = F_644 ( F_645 ( V_9 , 0 ) ,
F_646 ( V_9 , 0 ) ) ;
V_2 -> V_408 = V_14 -> V_40 ;
if ( ! V_14 -> V_40 ) {
V_17 = - V_759 ;
goto V_1241;
}
V_56 -> V_1242 = & V_1243 ;
F_647 ( V_56 ) ;
V_56 -> V_1244 = 5 * V_982 ;
F_648 ( V_56 -> V_54 , F_498 ( V_9 ) , sizeof( V_56 -> V_54 ) ) ;
memcpy ( & V_14 -> V_109 . V_342 , V_1221 -> V_1245 , sizeof( V_14 -> V_109 . V_342 ) ) ;
V_14 -> V_109 . type = V_1221 -> V_109 ;
V_14 -> V_1246 = V_1221 -> V_1246 ;
memcpy ( & V_14 -> V_1247 . V_342 , V_1221 -> V_1248 , sizeof( V_14 -> V_1247 . V_342 ) ) ;
V_1230 = F_37 ( V_14 , F_649 ( V_14 ) ) ;
if ( F_22 ( V_14 -> V_40 ) ) {
V_17 = - V_759 ;
goto V_1241;
}
if ( ! ( V_1230 & ( 1 << 8 ) ) )
V_14 -> V_1247 . V_342 . V_240 = & V_1249 ;
memcpy ( & V_14 -> V_345 . V_342 , V_1221 -> V_1250 , sizeof( V_14 -> V_345 . V_342 ) ) ;
V_14 -> V_345 . V_978 = V_1251 ;
V_14 -> V_345 . V_1120 . V_1117 = V_1252 ;
V_14 -> V_345 . V_1120 . V_1253 = 0 ;
V_14 -> V_345 . V_1120 . V_1254 = V_1255 | V_1256 ;
V_14 -> V_345 . V_1120 . V_74 = V_56 ;
V_14 -> V_345 . V_1120 . V_1257 = F_574 ;
V_14 -> V_345 . V_1120 . V_1258 = F_575 ;
V_1221 -> V_1259 ( V_14 ) ;
V_17 = F_401 ( V_2 ) ;
if ( V_17 )
goto V_1260;
switch ( V_2 -> V_14 . V_109 . type ) {
case V_112 :
case V_113 :
case V_114 :
case V_115 :
F_71 ( & V_2 -> V_14 , V_777 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_140 & V_349 ) {
T_1 V_680 = F_37 ( V_14 , V_681 ) ;
if ( V_680 & V_682 )
F_208 ( V_173 , L_71 ) ;
}
if ( V_1261 )
V_14 -> V_1261 = V_1261 ;
V_14 -> V_345 . V_1262 = true ;
V_17 = V_14 -> V_109 . V_342 . V_1263 ( V_14 ) ;
V_14 -> V_345 . V_1262 = false ;
if ( V_17 == V_689 ) {
V_17 = 0 ;
} else if ( V_17 == V_690 ) {
F_18 ( L_149 ) ;
F_18 ( L_150 ) ;
goto V_1260;
} else if ( V_17 ) {
F_18 ( L_151 , V_17 ) ;
goto V_1260;
}
#ifdef F_299
if ( V_2 -> V_14 . V_109 . type == V_110 )
goto V_1264;
F_650 ( V_14 ) ;
memcpy ( & V_14 -> V_1265 . V_342 , V_1221 -> V_1266 , sizeof( V_14 -> V_1265 . V_342 ) ) ;
F_651 ( V_9 , V_751 ) ;
F_652 ( V_2 ) ;
V_1264:
#endif
V_56 -> V_201 = V_1267 |
V_1268 |
V_1269 |
V_1270 |
V_251 |
V_1271 |
V_1272 |
V_202 |
V_219 ;
V_56 -> V_1273 = V_56 -> V_201 | V_1274 ;
switch ( V_2 -> V_14 . V_109 . type ) {
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_56 -> V_201 |= V_1275 ;
V_56 -> V_1273 |= V_1275 |
V_1150 ;
break;
default:
break;
}
V_56 -> V_1273 |= V_276 ;
V_56 -> V_201 |= V_1276 ;
V_56 -> V_1277 |= V_1271 ;
V_56 -> V_1277 |= V_1272 ;
V_56 -> V_1277 |= V_1268 ;
V_56 -> V_1277 |= V_1269 ;
V_56 -> V_1277 |= V_1267 ;
V_56 -> V_1278 |= V_1267 | V_1268 |
V_1269 ;
V_56 -> V_1279 |= V_1280 ;
V_56 -> V_1279 |= V_1281 ;
#ifdef F_326
switch ( V_2 -> V_14 . V_109 . type ) {
case V_114 :
case V_115 :
V_56 -> V_1278 |= V_219 |
V_1268 |
V_1269 ;
break;
default:
break;
}
#endif
#ifdef F_369
V_56 -> V_1282 = & V_1282 ;
#endif
#ifdef F_175
if ( V_2 -> V_140 & V_721 ) {
unsigned int V_1283 ;
if ( V_14 -> V_109 . V_342 . V_1284 ) {
V_14 -> V_109 . V_342 . V_1284 ( V_14 , & V_1229 ) ;
if ( V_1229 & V_1285 )
V_2 -> V_140 &= ~ V_721 ;
}
V_1283 = F_361 ( int , V_1286 , F_403 () ) ;
V_2 -> V_424 [ V_1088 ] . V_714 = V_1283 ;
V_56 -> V_201 |= V_1109 |
V_1110 ;
V_56 -> V_1277 |= V_1109 |
V_1110 |
V_598 ;
}
#endif
if ( V_1224 ) {
V_56 -> V_201 |= V_1287 ;
V_56 -> V_1277 |= V_1287 ;
}
if ( V_2 -> V_155 & V_715 )
V_56 -> V_1273 |= V_1146 ;
if ( V_2 -> V_155 & V_532 )
V_56 -> V_201 |= V_1146 ;
if ( V_14 -> V_1247 . V_342 . V_1288 ( V_14 , NULL ) < 0 ) {
F_18 ( L_152 ) ;
V_17 = - V_759 ;
goto V_1260;
}
F_630 ( V_2 ) ;
memcpy ( V_56 -> V_647 , V_14 -> V_109 . V_1215 , V_56 -> V_693 ) ;
if ( ! F_364 ( V_56 -> V_647 ) ) {
F_18 ( L_153 ) ;
V_17 = - V_759 ;
goto V_1260;
}
F_307 ( V_2 , V_14 -> V_109 . V_1215 ) ;
F_653 ( & V_2 -> V_683 , & F_508 ,
( unsigned long ) V_2 ) ;
if ( F_22 ( V_14 -> V_40 ) ) {
V_17 = - V_759 ;
goto V_1260;
}
F_654 ( & V_2 -> V_38 , F_512 ) ;
F_250 ( V_41 , & V_2 -> V_35 ) ;
F_34 ( V_37 , & V_2 -> V_35 ) ;
V_17 = F_445 ( V_2 ) ;
if ( V_17 )
goto V_1260;
V_2 -> V_697 = 0 ;
V_14 -> V_1247 . V_342 . V_240 ( V_14 , 0x2c , & V_2 -> V_1188 ) ;
V_14 -> V_1289 = F_629 ( V_2 , V_9 -> V_194 ,
V_9 -> V_713 ) ;
if ( V_14 -> V_1289 )
V_2 -> V_697 = V_1290 ;
F_655 ( & V_2 -> V_9 -> V_74 , V_2 -> V_697 ) ;
V_14 -> V_1247 . V_342 . V_240 ( V_14 , 0x2e , & V_2 -> V_1291 ) ;
V_14 -> V_1247 . V_342 . V_240 ( V_14 , 0x2d , & V_2 -> V_1292 ) ;
if ( F_8 ( V_14 ) )
F_5 ( V_2 ) ;
else
V_14 -> V_109 . V_342 . V_1293 ( V_14 ) ;
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
V_17 = F_657 ( V_14 , V_1226 , sizeof( V_1226 ) ) ;
if ( V_17 )
F_648 ( V_1226 , L_7 , sizeof( V_1226 ) ) ;
if ( F_212 ( V_14 ) && V_14 -> V_345 . V_978 != V_1294 )
F_12 ( L_154 ,
V_14 -> V_109 . type , V_14 -> V_345 . type , V_14 -> V_345 . V_978 ,
V_1226 ) ;
else
F_12 ( L_155 ,
V_14 -> V_109 . type , V_14 -> V_345 . type , V_1226 ) ;
F_12 ( L_156 , V_56 -> V_647 ) ;
V_17 = V_14 -> V_109 . V_342 . V_1295 ( V_14 ) ;
if ( V_17 == V_692 ) {
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
goto V_1296;
F_659 ( V_9 , V_2 ) ;
if ( V_14 -> V_109 . V_342 . V_702 )
V_14 -> V_109 . V_342 . V_702 ( V_14 ) ;
F_394 ( V_56 ) ;
#ifdef F_232
if ( F_126 ( & V_9 -> V_74 ) == 0 ) {
V_2 -> V_140 |= V_179 ;
F_123 ( V_2 ) ;
}
#endif
if ( V_2 -> V_140 & V_419 ) {
F_105 ( V_173 , L_161 , V_2 -> V_309 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_309 ; V_49 ++ )
F_660 ( V_9 , ( V_49 | 0x10000000 ) ) ;
}
if ( V_14 -> V_109 . V_342 . V_1297 )
V_14 -> V_109 . V_342 . V_1297 ( V_14 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_581 ( V_56 ) ;
F_12 ( L_70 , V_1298 ) ;
#ifdef F_661
if ( F_662 ( V_2 ) )
F_103 ( V_173 , L_162 ) ;
#endif
F_663 ( V_2 ) ;
if ( F_664 ( V_14 ) && F_212 ( V_14 ) && V_14 -> V_109 . V_342 . V_661 )
V_14 -> V_109 . V_342 . V_661 ( V_14 ,
V_925 | V_950 ,
true ) ;
return 0 ;
V_1296:
F_70 ( V_2 ) ;
F_451 ( V_2 ) ;
V_1260:
F_665 ( V_2 ) ;
V_2 -> V_155 &= ~ V_655 ;
F_666 ( V_2 -> V_408 ) ;
F_241 ( V_2 -> V_561 ) ;
V_1241:
V_1228 = ! F_15 ( V_776 , & V_2 -> V_35 ) ;
F_667 ( V_56 ) ;
V_1237:
F_668 ( V_9 ,
F_639 ( V_9 , V_1233 ) ) ;
V_1235:
V_1232:
if ( ! V_2 || V_1228 )
F_452 ( V_9 ) ;
return V_17 ;
}
static void F_669 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_437 ( V_9 ) ;
struct V_55 * V_56 ;
bool V_1228 ;
if ( ! V_2 )
return;
V_56 = V_2 -> V_56 ;
F_670 ( V_2 ) ;
F_250 ( V_36 , & V_2 -> V_35 ) ;
F_671 ( & V_2 -> V_38 ) ;
#ifdef F_232
if ( V_2 -> V_140 & V_179 ) {
V_2 -> V_140 &= ~ V_179 ;
F_127 ( & V_9 -> V_74 ) ;
F_71 ( & V_2 -> V_14 , V_190 ,
V_192 ) ;
}
#endif
#ifdef F_661
F_672 ( V_2 ) ;
#endif
F_583 ( V_56 ) ;
#ifdef F_299
F_665 ( V_2 ) ;
#endif
if ( V_56 -> V_979 == V_980 )
F_506 ( V_56 ) ;
F_451 ( V_2 ) ;
F_70 ( V_2 ) ;
#ifdef F_673
F_241 ( V_2 -> V_139 ) ;
F_241 ( V_2 -> V_603 ) ;
#endif
F_666 ( V_2 -> V_408 ) ;
F_668 ( V_9 , F_639 ( V_9 ,
V_1233 ) ) ;
F_12 ( L_163 ) ;
F_241 ( V_2 -> V_561 ) ;
V_1228 = ! F_15 ( V_776 , & V_2 -> V_35 ) ;
F_667 ( V_56 ) ;
F_674 ( V_9 ) ;
if ( V_1228 )
F_452 ( V_9 ) ;
}
static T_20 F_675 ( struct V_5 * V_9 ,
T_21 V_35 )
{
struct V_1 * V_2 = F_437 ( V_9 ) ;
struct V_55 * V_56 = V_2 -> V_56 ;
#ifdef F_299
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_1299 , * V_957 ;
T_1 V_1300 , V_1301 , V_1302 , V_1303 ;
int V_1304 , V_961 ;
T_2 V_1305 , V_1306 ;
if ( V_2 -> V_14 . V_109 . type == V_110 ||
V_2 -> V_309 == 0 )
goto V_1307;
V_1299 = V_9 -> V_10 -> V_12 ;
while ( V_1299 && ( F_676 ( V_1299 ) != V_1308 ) )
V_1299 = V_1299 -> V_10 -> V_12 ;
if ( ! V_1299 )
goto V_1307;
V_961 = F_501 ( V_1299 , V_1309 ) ;
if ( ! V_961 )
goto V_1307;
V_1300 = F_27 ( V_14 , V_961 + V_1310 ) ;
V_1301 = F_27 ( V_14 , V_961 + V_1310 + 4 ) ;
V_1302 = F_27 ( V_14 , V_961 + V_1310 + 8 ) ;
V_1303 = F_27 ( V_14 , V_961 + V_1310 + 12 ) ;
if ( F_22 ( V_14 -> V_40 ) )
goto V_1307;
V_1305 = V_1301 >> 16 ;
if ( ! ( V_1305 & 0x0080 ) )
goto V_1307;
V_1306 = V_1305 & 0x01 ;
if ( ( V_1306 & 1 ) == ( V_9 -> V_1311 & 1 ) ) {
unsigned int V_21 ;
V_1304 = ( V_1305 & 0x7F ) >> 1 ;
F_18 ( L_164 , V_1304 ) ;
F_18 ( L_165
L_166 ,
V_1300 , V_1301 , V_1302 , V_1303 ) ;
switch ( V_2 -> V_14 . V_109 . type ) {
case V_112 :
V_21 = V_1312 ;
break;
case V_113 :
V_21 = V_1313 ;
break;
case V_114 :
V_21 = V_1314 ;
break;
case V_115 :
V_21 = V_1315 ;
break;
default:
V_21 = 0 ;
break;
}
V_957 = F_502 ( V_1316 , V_21 , NULL ) ;
while ( V_957 ) {
if ( V_957 -> V_1311 == ( V_1305 & 0xFF ) )
break;
V_957 = F_502 ( V_1316 ,
V_21 , V_957 ) ;
}
if ( V_957 ) {
F_496 ( V_2 , V_957 ) ;
F_677 ( V_957 ) ;
}
F_678 ( V_9 ) ;
}
V_2 -> V_1317 ++ ;
return V_1318 ;
V_1307:
#endif
if ( ! F_14 ( V_41 , & V_2 -> V_35 ) )
return V_1319 ;
F_444 () ;
F_450 ( V_56 ) ;
if ( V_35 == V_1320 ) {
F_446 () ;
return V_1319 ;
}
if ( F_57 ( V_56 ) )
F_383 ( V_2 ) ;
if ( ! F_15 ( V_776 , & V_2 -> V_35 ) )
F_452 ( V_9 ) ;
F_446 () ;
return V_1321 ;
}
static T_20 F_679 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_437 ( V_9 ) ;
T_20 V_1322 ;
int V_17 ;
if ( F_441 ( V_9 ) ) {
F_103 ( V_173 , L_167 ) ;
V_1322 = V_1319 ;
} else {
F_33 () ;
F_34 ( V_776 , & V_2 -> V_35 ) ;
V_2 -> V_14 . V_40 = V_2 -> V_408 ;
F_442 ( V_9 ) ;
F_439 ( V_9 ) ;
F_440 ( V_9 ) ;
F_443 ( V_9 , false ) ;
F_386 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_777 , ~ 0 ) ;
V_1322 = V_1318 ;
}
V_17 = F_678 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_168
L_169 , V_17 ) ;
}
return V_1322 ;
}
static void F_680 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_437 ( V_9 ) ;
struct V_55 * V_56 = V_2 -> V_56 ;
#ifdef F_299
if ( V_2 -> V_1317 ) {
F_105 ( V_157 , L_170 ) ;
V_2 -> V_1317 -- ;
return;
}
#endif
if ( F_57 ( V_56 ) )
F_385 ( V_2 ) ;
F_447 ( V_56 ) ;
}
static int T_22 F_681 ( void )
{
int V_657 ;
F_51 ( L_171 , V_1323 , V_1324 ) ;
F_51 ( L_70 , V_1325 ) ;
F_682 () ;
V_657 = F_683 ( & V_1326 ) ;
if ( V_657 ) {
F_684 () ;
return V_657 ;
}
#ifdef F_232
F_685 ( & V_1327 ) ;
#endif
return 0 ;
}
static void T_23 F_686 ( void )
{
#ifdef F_232
F_687 ( & V_1327 ) ;
#endif
F_688 ( & V_1326 ) ;
F_684 () ;
}
static int F_689 ( struct V_1328 * V_1329 , unsigned long V_195 ,
void * V_1113 )
{
int V_1330 ;
V_1330 = F_690 ( & V_1326 . V_1331 , NULL , & V_195 ,
F_124 ) ;
return V_1330 ? V_1332 : V_1333 ;
}
