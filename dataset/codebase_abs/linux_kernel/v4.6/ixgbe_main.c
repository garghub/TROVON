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
V_4 = F_23 ( V_45 + V_3 ) ;
if ( F_24 ( V_4 == V_44 ) )
F_19 ( V_14 , V_3 ) ;
return V_4 ;
}
static bool F_4 ( struct V_15 * V_14 , struct V_5 * V_9 )
{
T_2 V_4 ;
F_25 ( V_9 , V_46 , & V_4 ) ;
if ( V_4 == V_13 ) {
F_17 ( V_14 ) ;
return true ;
}
return false ;
}
T_2 F_26 ( struct V_15 * V_14 , T_1 V_3 )
{
struct V_1 * V_2 = V_14 -> V_40 ;
T_2 V_4 ;
if ( F_22 ( V_14 -> V_41 ) )
return V_13 ;
F_25 ( V_2 -> V_9 , V_3 , & V_4 ) ;
if ( V_4 == V_13 &&
F_4 ( V_14 , V_2 -> V_9 ) )
return V_13 ;
return V_4 ;
}
static T_1 F_27 ( struct V_15 * V_14 , T_1 V_3 )
{
struct V_1 * V_2 = V_14 -> V_40 ;
T_1 V_4 ;
if ( F_22 ( V_14 -> V_41 ) )
return V_47 ;
F_28 ( V_2 -> V_9 , V_3 , & V_4 ) ;
if ( V_4 == V_47 &&
F_4 ( V_14 , V_2 -> V_9 ) )
return V_47 ;
return V_4 ;
}
void F_29 ( struct V_15 * V_14 , T_1 V_3 , T_2 V_4 )
{
struct V_1 * V_2 = V_14 -> V_40 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
F_30 ( V_2 -> V_9 , V_3 , V_4 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_32 ( ! F_14 ( V_37 , & V_2 -> V_35 ) ) ;
F_33 () ;
F_34 ( V_37 , & V_2 -> V_35 ) ;
}
static void F_35 ( struct V_15 * V_14 , struct V_48 * V_49 )
{
int V_50 = 0 , V_51 = 0 ;
char V_52 [ 16 ] ;
T_1 V_53 [ 64 ] ;
switch ( V_49 -> V_54 ) {
case F_36 ( 0 ) :
for ( V_50 = 0 ; V_50 < 64 ; V_50 ++ )
V_53 [ V_50 ] = F_37 ( V_14 , F_36 ( V_50 ) ) ;
break;
case F_38 ( 0 ) :
for ( V_50 = 0 ; V_50 < 64 ; V_50 ++ )
V_53 [ V_50 ] = F_37 ( V_14 , F_38 ( V_50 ) ) ;
break;
case F_39 ( 0 ) :
for ( V_50 = 0 ; V_50 < 64 ; V_50 ++ )
V_53 [ V_50 ] = F_37 ( V_14 , F_39 ( V_50 ) ) ;
break;
case F_40 ( 0 ) :
for ( V_50 = 0 ; V_50 < 64 ; V_50 ++ )
V_53 [ V_50 ] = F_37 ( V_14 , F_40 ( V_50 ) ) ;
break;
case F_41 ( 0 ) :
for ( V_50 = 0 ; V_50 < 64 ; V_50 ++ )
V_53 [ V_50 ] = F_37 ( V_14 , F_41 ( V_50 ) ) ;
break;
case F_42 ( 0 ) :
for ( V_50 = 0 ; V_50 < 64 ; V_50 ++ )
V_53 [ V_50 ] = F_37 ( V_14 , F_42 ( V_50 ) ) ;
break;
case F_43 ( 0 ) :
for ( V_50 = 0 ; V_50 < 64 ; V_50 ++ )
V_53 [ V_50 ] = F_37 ( V_14 , F_43 ( V_50 ) ) ;
break;
case F_44 ( 0 ) :
for ( V_50 = 0 ; V_50 < 64 ; V_50 ++ )
V_53 [ V_50 ] = F_37 ( V_14 , F_44 ( V_50 ) ) ;
break;
case F_45 ( 0 ) :
for ( V_50 = 0 ; V_50 < 64 ; V_50 ++ )
V_53 [ V_50 ] = F_37 ( V_14 , F_45 ( V_50 ) ) ;
break;
case F_46 ( 0 ) :
for ( V_50 = 0 ; V_50 < 64 ; V_50 ++ )
V_53 [ V_50 ] = F_37 ( V_14 , F_46 ( V_50 ) ) ;
break;
case F_47 ( 0 ) :
for ( V_50 = 0 ; V_50 < 64 ; V_50 ++ )
V_53 [ V_50 ] = F_37 ( V_14 , F_47 ( V_50 ) ) ;
break;
case F_48 ( 0 ) :
for ( V_50 = 0 ; V_50 < 64 ; V_50 ++ )
V_53 [ V_50 ] = F_37 ( V_14 , F_48 ( V_50 ) ) ;
break;
case F_49 ( 0 ) :
for ( V_50 = 0 ; V_50 < 64 ; V_50 ++ )
V_53 [ V_50 ] = F_37 ( V_14 , F_49 ( V_50 ) ) ;
break;
case F_50 ( 0 ) :
for ( V_50 = 0 ; V_50 < 64 ; V_50 ++ )
V_53 [ V_50 ] = F_37 ( V_14 , F_50 ( V_50 ) ) ;
break;
default:
F_51 ( L_14 , V_49 -> V_55 ,
F_37 ( V_14 , V_49 -> V_54 ) ) ;
return;
}
for ( V_50 = 0 ; V_50 < 8 ; V_50 ++ ) {
snprintf ( V_52 , 16 , L_15 , V_49 -> V_55 , V_50 * 8 , V_50 * 8 + 7 ) ;
F_52 ( L_16 , V_52 ) ;
for ( V_51 = 0 ; V_51 < 8 ; V_51 ++ )
F_53 ( L_17 , V_53 [ V_50 * 8 + V_51 ] ) ;
F_53 ( L_18 ) ;
}
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = V_2 -> V_57 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_48 * V_49 ;
int V_58 = 0 ;
struct V_59 * V_60 ;
struct V_61 * V_62 ;
union V_63 * V_64 ;
struct V_65 { T_6 V_66 ; T_6 V_67 ; } * V_68 ;
struct V_59 * V_69 ;
union V_70 * V_71 ;
struct V_72 * V_73 ;
T_1 V_74 ;
int V_50 = 0 ;
if ( ! F_55 ( V_2 ) )
return;
if ( V_57 ) {
F_56 ( & V_2 -> V_9 -> V_75 , L_19 ) ;
F_51 ( L_20
L_21 ) ;
F_51 ( L_22 ,
V_57 -> V_55 ,
V_57 -> V_35 ,
V_57 -> V_76 ,
V_57 -> V_77 ) ;
}
F_56 ( & V_2 -> V_9 -> V_75 , L_23 ) ;
F_51 ( L_24 ) ;
for ( V_49 = (struct V_48 * ) V_78 ;
V_49 -> V_55 ; V_49 ++ ) {
F_35 ( V_14 , V_49 ) ;
}
if ( ! V_57 || ! F_57 ( V_57 ) )
return;
F_56 ( & V_2 -> V_9 -> V_75 , L_25 ) ;
F_51 ( L_26 ,
L_27 ,
L_28 , L_29 , L_30 ) ;
for ( V_58 = 0 ; V_58 < V_2 -> V_79 ; V_58 ++ ) {
V_60 = V_2 -> V_60 [ V_58 ] ;
V_62 = & V_60 -> V_80 [ V_60 -> V_81 ] ;
F_51 ( L_31 ,
V_58 , V_60 -> V_82 , V_60 -> V_81 ,
( T_6 ) F_58 ( V_62 , V_83 ) ,
F_59 ( V_62 , V_84 ) ,
V_62 -> V_85 ,
( T_6 ) V_62 -> V_86 ) ;
}
if ( ! F_60 ( V_2 ) )
goto V_87;
F_56 ( & V_2 -> V_9 -> V_75 , L_32 ) ;
for ( V_58 = 0 ; V_58 < V_2 -> V_79 ; V_58 ++ ) {
V_60 = V_2 -> V_60 [ V_58 ] ;
F_51 ( L_33 ) ;
F_51 ( L_34 , V_60 -> V_88 ) ;
F_51 ( L_33 ) ;
F_51 ( L_35 ,
L_36 ,
L_37 ,
L_28 , L_29 , L_30 , L_38 ) ;
for ( V_50 = 0 ; V_60 -> V_89 && ( V_50 < V_60 -> V_90 ) ; V_50 ++ ) {
V_64 = F_61 ( V_60 , V_50 ) ;
V_62 = & V_60 -> V_80 [ V_50 ] ;
V_68 = (struct V_65 * ) V_64 ;
if ( F_59 ( V_62 , V_84 ) > 0 ) {
F_51 ( L_39 ,
V_50 ,
F_62 ( V_68 -> V_66 ) ,
F_62 ( V_68 -> V_67 ) ,
( T_6 ) F_58 ( V_62 , V_83 ) ,
F_59 ( V_62 , V_84 ) ,
V_62 -> V_85 ,
( T_6 ) V_62 -> V_86 ,
V_62 -> V_91 ) ;
if ( V_50 == V_60 -> V_82 &&
V_50 == V_60 -> V_81 )
F_53 ( L_40 ) ;
else if ( V_50 == V_60 -> V_82 )
F_53 ( L_41 ) ;
else if ( V_50 == V_60 -> V_81 )
F_53 ( L_42 ) ;
else
F_53 ( L_18 ) ;
if ( F_63 ( V_2 ) &&
V_62 -> V_91 )
F_64 ( V_92 , L_43 ,
V_93 , 16 , 1 ,
V_62 -> V_91 -> V_94 ,
F_59 ( V_62 , V_84 ) ,
true ) ;
}
}
}
V_87:
F_56 ( & V_2 -> V_9 -> V_75 , L_44 ) ;
F_51 ( L_45 ) ;
for ( V_58 = 0 ; V_58 < V_2 -> V_95 ; V_58 ++ ) {
V_69 = V_2 -> V_69 [ V_58 ] ;
F_51 ( L_46 ,
V_58 , V_69 -> V_82 , V_69 -> V_81 ) ;
}
if ( ! F_65 ( V_2 ) )
return;
F_56 ( & V_2 -> V_9 -> V_75 , L_47 ) ;
for ( V_58 = 0 ; V_58 < V_2 -> V_95 ; V_58 ++ ) {
V_69 = V_2 -> V_69 [ V_58 ] ;
F_51 ( L_33 ) ;
F_51 ( L_48 , V_69 -> V_88 ) ;
F_51 ( L_33 ) ;
F_51 ( L_49 ,
L_50 ,
L_51 ,
L_52 ) ;
F_51 ( L_49 ,
L_53 ,
L_54 ,
L_55 ) ;
for ( V_50 = 0 ; V_50 < V_69 -> V_90 ; V_50 ++ ) {
V_73 = & V_69 -> V_73 [ V_50 ] ;
V_71 = F_66 ( V_69 , V_50 ) ;
V_68 = (struct V_65 * ) V_71 ;
V_74 = F_67 ( V_71 -> V_96 . V_97 . V_98 ) ;
if ( V_74 & V_99 ) {
F_51 ( L_56
L_57 , V_50 ,
F_62 ( V_68 -> V_66 ) ,
F_62 ( V_68 -> V_67 ) ,
V_73 -> V_91 ) ;
} else {
F_51 ( L_58
L_59 , V_50 ,
F_62 ( V_68 -> V_66 ) ,
F_62 ( V_68 -> V_67 ) ,
( T_6 ) V_73 -> V_83 ,
V_73 -> V_91 ) ;
if ( F_63 ( V_2 ) &&
V_73 -> V_83 ) {
F_64 ( V_92 , L_43 ,
V_93 , 16 , 1 ,
F_68 ( V_73 -> V_100 ) +
V_73 -> V_101 ,
F_69 ( V_69 ) , true ) ;
}
}
if ( V_50 == V_69 -> V_82 )
F_53 ( L_41 ) ;
else if ( V_50 == V_69 -> V_81 )
F_53 ( L_42 ) ;
else
F_53 ( L_18 ) ;
}
}
}
static void F_70 ( struct V_1 * V_2 )
{
T_1 V_102 ;
V_102 = F_37 ( & V_2 -> V_14 , V_103 ) ;
F_71 ( & V_2 -> V_14 , V_103 ,
V_102 & ~ V_104 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
T_1 V_102 ;
V_102 = F_37 ( & V_2 -> V_14 , V_103 ) ;
F_71 ( & V_2 -> V_14 , V_103 ,
V_102 | V_104 ) ;
}
static void F_73 ( struct V_1 * V_2 , T_7 V_105 ,
T_4 V_106 , T_4 V_107 )
{
T_1 V_108 , V_109 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_110 . type ) {
case V_111 :
V_107 |= V_112 ;
if ( V_105 == - 1 )
V_105 = 0 ;
V_109 = ( ( ( V_105 * 64 ) + V_106 ) >> 2 ) & 0x1F ;
V_108 = F_37 ( V_14 , F_74 ( V_109 ) ) ;
V_108 &= ~ ( 0xFF << ( 8 * ( V_106 & 0x3 ) ) ) ;
V_108 |= ( V_107 << ( 8 * ( V_106 & 0x3 ) ) ) ;
F_71 ( V_14 , F_74 ( V_109 ) , V_108 ) ;
break;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
if ( V_105 == - 1 ) {
V_107 |= V_112 ;
V_109 = ( ( V_106 & 1 ) * 8 ) ;
V_108 = F_37 ( & V_2 -> V_14 , V_117 ) ;
V_108 &= ~ ( 0xFF << V_109 ) ;
V_108 |= ( V_107 << V_109 ) ;
F_71 ( & V_2 -> V_14 , V_117 , V_108 ) ;
break;
} else {
V_107 |= V_112 ;
V_109 = ( ( 16 * ( V_106 & 1 ) ) + ( 8 * V_105 ) ) ;
V_108 = F_37 ( V_14 , F_74 ( V_106 >> 1 ) ) ;
V_108 &= ~ ( 0xFF << V_109 ) ;
V_108 |= ( V_107 << V_109 ) ;
F_71 ( V_14 , F_74 ( V_106 >> 1 ) , V_108 ) ;
break;
}
default:
break;
}
}
static inline void F_75 ( struct V_1 * V_2 ,
T_6 V_118 )
{
T_1 V_119 ;
switch ( V_2 -> V_14 . V_110 . type ) {
case V_111 :
V_119 = ( V_120 & V_118 ) ;
F_71 ( & V_2 -> V_14 , V_121 , V_119 ) ;
break;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
V_119 = ( V_118 & 0xFFFFFFFF ) ;
F_71 ( & V_2 -> V_14 , F_76 ( 0 ) , V_119 ) ;
V_119 = ( V_118 >> 32 ) ;
F_71 ( & V_2 -> V_14 , F_76 ( 1 ) , V_119 ) ;
break;
default:
break;
}
}
void F_77 ( struct V_59 * V_122 ,
struct V_61 * V_62 )
{
if ( V_62 -> V_91 ) {
F_78 ( V_62 -> V_91 ) ;
if ( F_59 ( V_62 , V_84 ) )
F_79 ( V_122 -> V_75 ,
F_58 ( V_62 , V_83 ) ,
F_59 ( V_62 , V_84 ) ,
V_123 ) ;
} else if ( F_59 ( V_62 , V_84 ) ) {
F_80 ( V_122 -> V_75 ,
F_58 ( V_62 , V_83 ) ,
F_59 ( V_62 , V_84 ) ,
V_123 ) ;
}
V_62 -> V_85 = NULL ;
V_62 -> V_91 = NULL ;
F_81 ( V_62 , V_84 , 0 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_124 * V_125 = & V_2 -> V_126 ;
int V_50 ;
T_1 V_94 ;
if ( ( V_14 -> V_127 . V_128 != V_129 ) &&
( V_14 -> V_127 . V_128 != V_130 ) )
return;
switch ( V_14 -> V_110 . type ) {
case V_111 :
V_94 = F_37 ( V_14 , V_131 ) ;
break;
default:
V_94 = F_37 ( V_14 , V_132 ) ;
}
V_125 -> V_133 += V_94 ;
if ( ! V_94 )
return;
for ( V_50 = 0 ; V_50 < V_2 -> V_79 ; V_50 ++ )
F_34 ( V_134 ,
& V_2 -> V_60 [ V_50 ] -> V_35 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_124 * V_125 = & V_2 -> V_126 ;
T_1 V_135 [ 8 ] = { 0 } ;
T_4 V_136 ;
int V_50 ;
bool V_137 = V_2 -> V_138 . V_139 ;
if ( V_2 -> V_140 )
V_137 |= ! ! ( V_2 -> V_140 -> V_137 ) ;
if ( ! ( V_2 -> V_141 & V_142 ) || ! V_137 ) {
F_82 ( V_2 ) ;
return;
}
for ( V_50 = 0 ; V_50 < V_143 ; V_50 ++ ) {
T_1 V_144 ;
switch ( V_14 -> V_110 . type ) {
case V_111 :
V_144 = F_37 ( V_14 , F_84 ( V_50 ) ) ;
break;
default:
V_144 = F_37 ( V_14 , F_85 ( V_50 ) ) ;
}
V_125 -> V_144 [ V_50 ] += V_144 ;
V_136 = F_86 ( V_2 -> V_57 , V_50 ) ;
V_135 [ V_136 ] += V_144 ;
}
for ( V_50 = 0 ; V_50 < V_2 -> V_79 ; V_50 ++ ) {
struct V_59 * V_60 = V_2 -> V_60 [ V_50 ] ;
V_136 = V_60 -> V_145 ;
if ( V_135 [ V_136 ] )
F_34 ( V_134 , & V_60 -> V_35 ) ;
}
}
static T_6 F_87 ( struct V_59 * V_122 )
{
return V_122 -> V_126 . V_146 ;
}
static T_6 F_88 ( struct V_59 * V_122 )
{
struct V_1 * V_2 ;
struct V_15 * V_14 ;
T_1 V_147 , V_148 ;
if ( V_122 -> V_149 )
V_2 = V_122 -> V_149 -> V_150 ;
else
V_2 = F_89 ( V_122 -> V_57 ) ;
V_14 = & V_2 -> V_14 ;
V_147 = F_37 ( V_14 , F_48 ( V_122 -> V_151 ) ) ;
V_148 = F_37 ( V_14 , F_49 ( V_122 -> V_151 ) ) ;
if ( V_147 != V_148 )
return ( V_147 < V_148 ) ?
V_148 - V_147 : ( V_148 + V_122 -> V_90 - V_147 ) ;
return 0 ;
}
static inline bool F_90 ( struct V_59 * V_60 )
{
T_1 V_152 = F_87 ( V_60 ) ;
T_1 V_153 = V_60 -> V_154 . V_153 ;
T_1 V_155 = F_88 ( V_60 ) ;
F_91 ( V_60 ) ;
if ( V_153 == V_152 && V_155 )
return F_15 ( V_134 ,
& V_60 -> V_35 ) ;
V_60 -> V_154 . V_153 = V_152 ;
F_34 ( V_134 , & V_60 -> V_35 ) ;
return false ;
}
static void F_92 ( struct V_1 * V_2 )
{
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_156 |= V_157 ;
F_93 ( V_158 , L_60 ) ;
F_13 ( V_2 ) ;
}
}
static bool F_94 ( struct V_159 * V_160 ,
struct V_59 * V_60 , int V_161 )
{
struct V_1 * V_2 = V_160 -> V_2 ;
struct V_61 * V_62 ;
union V_63 * V_64 ;
unsigned int V_162 = 0 , V_163 = 0 ;
unsigned int V_164 = V_160 -> V_165 . V_166 ;
unsigned int V_50 = V_60 -> V_81 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return true ;
V_62 = & V_60 -> V_80 [ V_50 ] ;
V_64 = F_61 ( V_60 , V_50 ) ;
V_50 -= V_60 -> V_90 ;
do {
union V_63 * V_167 = V_62 -> V_85 ;
if ( ! V_167 )
break;
F_95 () ;
if ( ! ( V_167 -> V_96 . V_168 & F_96 ( V_169 ) ) )
break;
V_62 -> V_85 = NULL ;
V_162 += V_62 -> V_170 ;
V_163 += V_62 -> V_171 ;
F_97 ( V_62 -> V_91 , V_161 ) ;
F_79 ( V_60 -> V_75 ,
F_58 ( V_62 , V_83 ) ,
F_59 ( V_62 , V_84 ) ,
V_123 ) ;
V_62 -> V_91 = NULL ;
F_81 ( V_62 , V_84 , 0 ) ;
while ( V_64 != V_167 ) {
V_62 ++ ;
V_64 ++ ;
V_50 ++ ;
if ( F_24 ( ! V_50 ) ) {
V_50 -= V_60 -> V_90 ;
V_62 = V_60 -> V_80 ;
V_64 = F_61 ( V_60 , 0 ) ;
}
if ( F_59 ( V_62 , V_84 ) ) {
F_80 ( V_60 -> V_75 ,
F_58 ( V_62 , V_83 ) ,
F_59 ( V_62 , V_84 ) ,
V_123 ) ;
F_81 ( V_62 , V_84 , 0 ) ;
}
}
V_62 ++ ;
V_64 ++ ;
V_50 ++ ;
if ( F_24 ( ! V_50 ) ) {
V_50 -= V_60 -> V_90 ;
V_62 = V_60 -> V_80 ;
V_64 = F_61 ( V_60 , 0 ) ;
}
F_98 ( V_64 ) ;
V_164 -- ;
} while ( F_99 ( V_164 ) );
V_50 += V_60 -> V_90 ;
V_60 -> V_81 = V_50 ;
F_100 ( & V_60 -> V_172 ) ;
V_60 -> V_126 . V_173 += V_162 ;
V_60 -> V_126 . V_146 += V_163 ;
F_101 ( & V_60 -> V_172 ) ;
V_160 -> V_165 . V_162 += V_162 ;
V_160 -> V_165 . V_163 += V_163 ;
if ( F_102 ( V_60 ) && F_90 ( V_60 ) ) {
struct V_15 * V_14 = & V_2 -> V_14 ;
F_103 ( V_158 , L_61
L_62
L_63
L_64
L_65
L_66
L_67
L_68 ,
V_60 -> V_88 ,
F_37 ( V_14 , F_48 ( V_60 -> V_151 ) ) ,
F_37 ( V_14 , F_49 ( V_60 -> V_151 ) ) ,
V_60 -> V_82 , V_50 ,
V_60 -> V_80 [ V_50 ] . V_86 , V_174 ) ;
F_104 ( V_60 -> V_57 , V_60 -> V_88 ) ;
F_105 ( V_175 ,
L_69 ,
V_2 -> V_176 + 1 , V_60 -> V_88 ) ;
F_92 ( V_2 ) ;
return true ;
}
F_106 ( F_107 ( V_60 ) ,
V_163 , V_162 ) ;
#define F_108 (DESC_NEEDED * 2)
if ( F_24 ( V_163 && F_109 ( V_60 -> V_57 ) &&
( F_110 ( V_60 ) >= F_108 ) ) ) {
F_111 () ;
if ( F_112 ( V_60 -> V_57 ,
V_60 -> V_88 )
&& ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_113 ( V_60 -> V_57 ,
V_60 -> V_88 ) ;
++ V_60 -> V_154 . V_177 ;
}
}
return ! ! V_164 ;
}
static void F_114 ( struct V_1 * V_2 ,
struct V_59 * V_60 ,
int V_178 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_179 = 0 ;
T_2 V_180 ;
if ( V_2 -> V_141 & V_181 )
V_179 = F_115 ( V_60 -> V_75 , V_178 ) ;
switch ( V_14 -> V_110 . type ) {
case V_111 :
V_180 = F_116 ( V_60 -> V_151 ) ;
break;
case V_113 :
case V_114 :
V_180 = F_117 ( V_60 -> V_151 ) ;
V_179 <<= V_182 ;
break;
default:
return;
}
V_179 |= V_183 |
V_184 |
V_185 ;
F_71 ( V_14 , V_180 , V_179 ) ;
}
static void F_118 ( struct V_1 * V_2 ,
struct V_59 * V_69 ,
int V_178 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_186 = 0 ;
T_4 V_151 = V_69 -> V_151 ;
if ( V_2 -> V_141 & V_181 )
V_186 = F_115 ( V_69 -> V_75 , V_178 ) ;
switch ( V_14 -> V_110 . type ) {
case V_113 :
case V_114 :
V_186 <<= V_187 ;
break;
default:
break;
}
V_186 |= V_188 |
V_189 |
V_190 ;
F_71 ( V_14 , F_38 ( V_151 ) , V_186 ) ;
}
static void F_119 ( struct V_159 * V_160 )
{
struct V_1 * V_2 = V_160 -> V_2 ;
struct V_59 * V_122 ;
int V_178 = F_120 () ;
if ( V_160 -> V_178 == V_178 )
goto V_191;
F_121 (ring, q_vector->tx)
F_114 ( V_2 , V_122 , V_178 ) ;
F_121 (ring, q_vector->rx)
F_118 ( V_2 , V_122 , V_178 ) ;
V_160 -> V_178 = V_178 ;
V_191:
F_122 () ;
}
static void F_123 ( struct V_1 * V_2 )
{
int V_50 ;
if ( V_2 -> V_141 & V_181 )
F_71 ( & V_2 -> V_14 , V_192 ,
V_193 ) ;
else
F_71 ( & V_2 -> V_14 , V_192 ,
V_194 ) ;
for ( V_50 = 0 ; V_50 < V_2 -> V_195 ; V_50 ++ ) {
V_2 -> V_160 [ V_50 ] -> V_178 = - 1 ;
F_119 ( V_2 -> V_160 [ V_50 ] ) ;
}
}
static int F_124 ( struct V_196 * V_75 , void * V_94 )
{
struct V_1 * V_2 = F_125 ( V_75 ) ;
unsigned long V_197 = * ( unsigned long * ) V_94 ;
if ( ! ( V_2 -> V_141 & V_198 ) )
return 0 ;
switch ( V_197 ) {
case V_199 :
if ( V_2 -> V_141 & V_181 )
break;
if ( F_126 ( V_75 ) == 0 ) {
V_2 -> V_141 |= V_181 ;
F_71 ( & V_2 -> V_14 , V_192 ,
V_193 ) ;
break;
}
case V_200 :
if ( V_2 -> V_141 & V_181 ) {
F_127 ( V_75 ) ;
V_2 -> V_141 &= ~ V_181 ;
F_71 ( & V_2 -> V_14 , V_192 ,
V_194 ) ;
}
break;
}
return 0 ;
}
static inline void F_128 ( struct V_59 * V_122 ,
union V_70 * V_71 ,
struct V_201 * V_91 )
{
T_2 V_202 ;
if ( ! ( V_122 -> V_57 -> V_203 & V_204 ) )
return;
V_202 = F_129 ( V_71 -> V_96 . V_205 . V_206 . V_207 . V_208 ) &
V_209 ;
if ( ! V_202 )
return;
F_130 ( V_91 , F_67 ( V_71 -> V_96 . V_205 . V_210 . V_211 ) ,
( V_212 & ( 1ul << V_202 ) ) ?
V_213 : V_214 ) ;
}
static inline bool F_131 ( struct V_59 * V_122 ,
union V_70 * V_71 )
{
T_8 V_208 = V_71 -> V_96 . V_205 . V_206 . V_207 . V_208 ;
return F_14 ( V_215 , & V_122 -> V_35 ) &&
( ( V_208 & F_132 ( V_216 ) ) ==
( F_132 ( V_217 <<
V_218 ) ) ) ;
}
static inline void F_133 ( struct V_59 * V_122 ,
union V_70 * V_71 ,
struct V_201 * V_91 )
{
T_8 V_208 = V_71 -> V_96 . V_205 . V_206 . V_207 . V_208 ;
T_8 V_219 = V_71 -> V_96 . V_205 . V_206 . V_207 . V_219 ;
bool V_220 = false ;
F_134 ( V_91 ) ;
if ( ! ( V_122 -> V_57 -> V_203 & V_221 ) )
return;
if ( ( V_208 & F_132 ( V_222 ) ) &&
( V_219 & F_132 ( V_223 >> 16 ) ) ) {
V_220 = true ;
V_91 -> V_224 = 1 ;
}
if ( F_135 ( V_71 , V_225 ) &&
F_135 ( V_71 , V_226 ) ) {
V_122 -> V_227 . V_228 ++ ;
return;
}
if ( ! F_135 ( V_71 , V_229 ) )
return;
if ( F_135 ( V_71 , V_230 ) ) {
if ( ( V_208 & F_132 ( V_231 ) ) &&
F_14 ( V_232 , & V_122 -> V_35 ) )
return;
V_122 -> V_227 . V_228 ++ ;
return;
}
V_91 -> V_233 = V_234 ;
if ( V_220 ) {
if ( ! F_135 ( V_71 , V_235 ) )
return;
if ( F_135 ( V_71 , V_236 ) ) {
V_91 -> V_233 = V_237 ;
return;
}
V_91 -> V_238 = 1 ;
}
}
static bool F_136 ( struct V_59 * V_69 ,
struct V_72 * V_239 )
{
struct V_100 * V_100 = V_239 -> V_100 ;
T_9 V_83 ;
if ( F_99 ( V_100 ) )
return true ;
V_100 = F_137 ( F_138 ( V_69 ) ) ;
if ( F_24 ( ! V_100 ) ) {
V_69 -> V_227 . V_240 ++ ;
return false ;
}
V_83 = F_139 ( V_69 -> V_75 , V_100 , 0 ,
F_140 ( V_69 ) , V_241 ) ;
if ( F_141 ( V_69 -> V_75 , V_83 ) ) {
F_142 ( V_100 , F_138 ( V_69 ) ) ;
V_69 -> V_227 . V_240 ++ ;
return false ;
}
V_239 -> V_83 = V_83 ;
V_239 -> V_100 = V_100 ;
V_239 -> V_101 = 0 ;
return true ;
}
void F_143 ( struct V_59 * V_69 , T_2 V_242 )
{
union V_70 * V_71 ;
struct V_72 * V_239 ;
T_2 V_50 = V_69 -> V_82 ;
if ( ! V_242 )
return;
V_71 = F_66 ( V_69 , V_50 ) ;
V_239 = & V_69 -> V_73 [ V_50 ] ;
V_50 -= V_69 -> V_90 ;
do {
if ( ! F_136 ( V_69 , V_239 ) )
break;
V_71 -> V_243 . V_244 = F_144 ( V_239 -> V_83 + V_239 -> V_101 ) ;
V_71 ++ ;
V_239 ++ ;
V_50 ++ ;
if ( F_24 ( ! V_50 ) ) {
V_71 = F_66 ( V_69 , 0 ) ;
V_239 = V_69 -> V_73 ;
V_50 -= V_69 -> V_90 ;
}
V_71 -> V_96 . V_97 . V_98 = 0 ;
V_242 -- ;
} while ( V_242 );
V_50 += V_69 -> V_90 ;
if ( V_69 -> V_82 != V_50 ) {
V_69 -> V_82 = V_50 ;
V_69 -> V_245 = V_50 ;
F_145 () ;
F_146 ( V_50 , V_69 -> V_148 ) ;
}
}
static void F_147 ( struct V_59 * V_122 ,
struct V_201 * V_91 )
{
T_2 V_246 = F_148 ( V_91 ) ;
F_149 ( V_91 ) -> V_247 = F_150 ( ( V_91 -> V_84 - V_246 ) ,
F_151 ( V_91 ) -> V_248 ) ;
F_149 ( V_91 ) -> V_249 = V_250 ;
}
static void F_152 ( struct V_59 * V_69 ,
struct V_201 * V_91 )
{
if ( ! F_151 ( V_91 ) -> V_248 )
return;
V_69 -> V_227 . V_251 += F_151 ( V_91 ) -> V_248 ;
V_69 -> V_227 . V_252 ++ ;
F_147 ( V_69 , V_91 ) ;
F_151 ( V_91 ) -> V_248 = 0 ;
}
static void F_153 ( struct V_59 * V_69 ,
union V_70 * V_71 ,
struct V_201 * V_91 )
{
struct V_56 * V_75 = V_69 -> V_57 ;
T_1 V_141 = V_69 -> V_160 -> V_2 -> V_141 ;
F_152 ( V_69 , V_91 ) ;
F_128 ( V_69 , V_71 , V_91 ) ;
F_133 ( V_69 , V_71 , V_91 ) ;
if ( F_24 ( V_141 & V_253 ) )
F_154 ( V_69 , V_71 , V_91 ) ;
if ( ( V_75 -> V_203 & V_254 ) &&
F_135 ( V_71 , V_255 ) ) {
T_2 V_256 = F_129 ( V_71 -> V_96 . V_97 . V_257 ) ;
F_155 ( V_91 , F_156 ( V_258 ) , V_256 ) ;
}
F_157 ( V_91 , V_69 -> V_88 ) ;
V_91 -> V_259 = F_158 ( V_91 , V_75 ) ;
}
static void F_159 ( struct V_159 * V_160 ,
struct V_201 * V_91 )
{
F_160 ( V_91 , & V_160 -> V_260 ) ;
if ( F_161 ( V_160 ) )
F_162 ( V_91 ) ;
else
F_163 ( & V_160 -> V_260 , V_91 ) ;
}
static bool F_164 ( struct V_59 * V_69 ,
union V_70 * V_71 ,
struct V_201 * V_91 )
{
T_1 V_261 = V_69 -> V_81 + 1 ;
V_261 = ( V_261 < V_69 -> V_90 ) ? V_261 : 0 ;
V_69 -> V_81 = V_261 ;
F_98 ( F_66 ( V_69 , V_261 ) ) ;
if ( F_165 ( V_69 ) ) {
T_10 V_262 = V_71 -> V_96 . V_205 . V_206 . V_94 &
F_96 ( V_263 ) ;
if ( F_24 ( V_262 ) ) {
T_1 V_264 = F_67 ( V_262 ) ;
V_264 >>= V_265 ;
F_151 ( V_91 ) -> V_248 += V_264 - 1 ;
V_261 = F_67 ( V_71 -> V_96 . V_97 . V_98 ) ;
V_261 &= V_266 ;
V_261 >>= V_267 ;
}
}
if ( F_99 ( F_135 ( V_71 , V_268 ) ) )
return false ;
V_69 -> V_73 [ V_261 ] . V_91 = V_91 ;
V_69 -> V_227 . V_269 ++ ;
return true ;
}
static void F_166 ( struct V_59 * V_69 ,
struct V_201 * V_91 )
{
struct V_270 * V_271 = & F_149 ( V_91 ) -> V_272 [ 0 ] ;
unsigned char * V_273 ;
unsigned int V_274 ;
V_273 = F_167 ( V_271 ) ;
V_274 = F_168 ( V_273 , V_275 ) ;
F_169 ( V_91 , V_273 , F_170 ( V_274 , sizeof( long ) ) ) ;
F_171 ( V_271 , V_274 ) ;
V_271 -> V_101 += V_274 ;
V_91 -> V_276 -= V_274 ;
V_91 -> V_148 += V_274 ;
}
static void F_172 ( struct V_59 * V_69 ,
struct V_201 * V_91 )
{
if ( F_24 ( F_151 ( V_91 ) -> V_277 ) ) {
F_80 ( V_69 -> V_75 , F_151 ( V_91 ) -> V_83 ,
F_140 ( V_69 ) , V_241 ) ;
F_151 ( V_91 ) -> V_277 = false ;
} else {
struct V_270 * V_271 = & F_149 ( V_91 ) -> V_272 [ 0 ] ;
F_173 ( V_69 -> V_75 ,
F_151 ( V_91 ) -> V_83 ,
V_271 -> V_101 ,
F_69 ( V_69 ) ,
V_241 ) ;
}
F_151 ( V_91 ) -> V_83 = 0 ;
}
static bool F_174 ( struct V_59 * V_69 ,
union V_70 * V_71 ,
struct V_201 * V_91 )
{
struct V_56 * V_57 = V_69 -> V_57 ;
if ( F_24 ( F_135 ( V_71 ,
V_278 ) &&
! ( V_57 -> V_203 & V_279 ) ) ) {
F_78 ( V_91 ) ;
return true ;
}
if ( F_175 ( V_91 ) )
F_166 ( V_69 , V_91 ) ;
#ifdef F_176
if ( F_131 ( V_69 , V_71 ) )
return false ;
#endif
if ( F_177 ( V_91 ) )
return true ;
return false ;
}
static void F_178 ( struct V_59 * V_69 ,
struct V_72 * V_280 )
{
struct V_72 * V_281 ;
T_2 V_282 = V_69 -> V_245 ;
V_281 = & V_69 -> V_73 [ V_282 ] ;
V_282 ++ ;
V_69 -> V_245 = ( V_282 < V_69 -> V_90 ) ? V_282 : 0 ;
* V_281 = * V_280 ;
F_179 ( V_69 -> V_75 , V_281 -> V_83 ,
V_281 -> V_101 ,
F_69 ( V_69 ) ,
V_241 ) ;
}
static inline bool F_180 ( struct V_100 * V_100 )
{
return ( F_181 ( V_100 ) != F_182 () ) || F_183 ( V_100 ) ;
}
static bool F_184 ( struct V_59 * V_69 ,
struct V_72 * V_283 ,
union V_70 * V_71 ,
struct V_201 * V_91 )
{
struct V_100 * V_100 = V_283 -> V_100 ;
unsigned int V_284 = F_129 ( V_71 -> V_96 . V_97 . V_285 ) ;
#if ( V_286 < 8192 )
unsigned int V_287 = F_69 ( V_69 ) ;
#else
unsigned int V_287 = F_170 ( V_284 , V_288 ) ;
unsigned int V_289 = F_140 ( V_69 ) -
F_69 ( V_69 ) ;
#endif
if ( ( V_284 <= V_275 ) && ! F_175 ( V_91 ) ) {
unsigned char * V_273 = F_68 ( V_100 ) + V_283 -> V_101 ;
memcpy ( F_185 ( V_91 , V_284 ) , V_273 , F_170 ( V_284 , sizeof( long ) ) ) ;
if ( F_99 ( ! F_180 ( V_100 ) ) )
return true ;
F_142 ( V_100 , F_138 ( V_69 ) ) ;
return false ;
}
F_186 ( V_91 , F_149 ( V_91 ) -> V_290 , V_100 ,
V_283 -> V_101 , V_284 , V_287 ) ;
if ( F_24 ( F_180 ( V_100 ) ) )
return false ;
#if ( V_286 < 8192 )
if ( F_24 ( F_187 ( V_100 ) != 1 ) )
return false ;
V_283 -> V_101 ^= V_287 ;
#else
V_283 -> V_101 += V_287 ;
if ( V_283 -> V_101 > V_289 )
return false ;
#endif
F_188 ( V_100 ) ;
return true ;
}
static struct V_201 * F_189 ( struct V_59 * V_69 ,
union V_70 * V_71 )
{
struct V_72 * V_283 ;
struct V_201 * V_91 ;
struct V_100 * V_100 ;
V_283 = & V_69 -> V_73 [ V_69 -> V_81 ] ;
V_100 = V_283 -> V_100 ;
F_190 ( V_100 ) ;
V_91 = V_283 -> V_91 ;
if ( F_99 ( ! V_91 ) ) {
void * V_291 = F_68 ( V_100 ) +
V_283 -> V_101 ;
F_98 ( V_291 ) ;
#if V_288 < 128
F_98 ( V_291 + V_288 ) ;
#endif
V_91 = F_191 ( & V_69 -> V_160 -> V_260 ,
V_275 ) ;
if ( F_24 ( ! V_91 ) ) {
V_69 -> V_227 . V_292 ++ ;
return NULL ;
}
F_190 ( V_91 -> V_94 ) ;
if ( F_99 ( F_135 ( V_71 , V_268 ) ) )
goto V_293;
F_151 ( V_91 ) -> V_83 = V_283 -> V_83 ;
} else {
if ( F_135 ( V_71 , V_268 ) )
F_172 ( V_69 , V_91 ) ;
V_293:
F_173 ( V_69 -> V_75 ,
V_283 -> V_83 ,
V_283 -> V_101 ,
F_69 ( V_69 ) ,
V_241 ) ;
V_283 -> V_91 = NULL ;
}
if ( F_184 ( V_69 , V_283 , V_71 , V_91 ) ) {
F_178 ( V_69 , V_283 ) ;
} else if ( F_151 ( V_91 ) -> V_83 == V_283 -> V_83 ) {
F_151 ( V_91 ) -> V_277 = true ;
} else {
F_80 ( V_69 -> V_75 , V_283 -> V_83 ,
F_140 ( V_69 ) ,
V_241 ) ;
}
V_283 -> V_100 = NULL ;
return V_91 ;
}
static int F_192 ( struct V_159 * V_160 ,
struct V_59 * V_69 ,
const int V_164 )
{
unsigned int V_294 = 0 , V_295 = 0 ;
#ifdef F_176
struct V_1 * V_2 = V_160 -> V_2 ;
int V_296 ;
unsigned int V_297 = 0 ;
#endif
T_2 V_242 = F_110 ( V_69 ) ;
while ( F_99 ( V_295 < V_164 ) ) {
union V_70 * V_71 ;
struct V_201 * V_91 ;
if ( V_242 >= V_298 ) {
F_143 ( V_69 , V_242 ) ;
V_242 = 0 ;
}
V_71 = F_66 ( V_69 , V_69 -> V_81 ) ;
if ( ! V_71 -> V_96 . V_97 . V_98 )
break;
F_193 () ;
V_91 = F_189 ( V_69 , V_71 ) ;
if ( ! V_91 )
break;
V_242 ++ ;
if ( F_164 ( V_69 , V_71 , V_91 ) )
continue;
if ( F_174 ( V_69 , V_71 , V_91 ) )
continue;
V_294 += V_91 -> V_84 ;
F_153 ( V_69 , V_71 , V_91 ) ;
#ifdef F_176
if ( F_131 ( V_69 , V_71 ) ) {
V_296 = F_194 ( V_2 , V_71 , V_91 ) ;
if ( V_296 > 0 ) {
if ( ! V_297 ) {
V_297 = V_69 -> V_57 -> V_299 -
sizeof( struct V_300 ) -
sizeof( struct V_301 ) -
sizeof( struct V_302 ) ;
if ( V_297 > 512 )
V_297 &= ~ 511 ;
}
V_294 += V_296 ;
V_295 += F_150 ( V_296 ,
V_297 ) ;
}
if ( ! V_296 ) {
F_78 ( V_91 ) ;
continue;
}
}
#endif
F_159 ( V_160 , V_91 ) ;
V_295 ++ ;
}
F_100 ( & V_69 -> V_172 ) ;
V_69 -> V_126 . V_146 += V_295 ;
V_69 -> V_126 . V_173 += V_294 ;
F_101 ( & V_69 -> V_172 ) ;
V_160 -> V_303 . V_163 += V_295 ;
V_160 -> V_303 . V_162 += V_294 ;
return V_295 ;
}
static int F_195 ( struct V_304 * V_260 )
{
struct V_159 * V_160 =
F_196 ( V_260 , struct V_159 , V_260 ) ;
struct V_1 * V_2 = V_160 -> V_2 ;
struct V_59 * V_122 ;
int V_305 = 0 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return V_306 ;
if ( ! F_197 ( V_160 ) )
return V_307 ;
F_121 (ring, q_vector->rx) {
V_305 = F_192 ( V_160 , V_122 , 4 ) ;
#ifdef F_198
if ( V_305 )
V_122 -> V_126 . V_308 += V_305 ;
else
V_122 -> V_126 . V_309 ++ ;
#endif
if ( V_305 )
break;
}
F_199 ( V_160 ) ;
return V_305 ;
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_159 * V_160 ;
int V_310 ;
T_1 V_119 ;
if ( V_2 -> V_311 > 32 ) {
T_1 V_312 = ( 1 << ( V_2 -> V_311 - 32 ) ) - 1 ;
F_71 ( & V_2 -> V_14 , V_313 , V_312 ) ;
}
for ( V_310 = 0 ; V_310 < V_2 -> V_195 ; V_310 ++ ) {
struct V_59 * V_122 ;
V_160 = V_2 -> V_160 [ V_310 ] ;
F_121 (ring, q_vector->rx)
F_73 ( V_2 , 0 , V_122 -> V_151 , V_310 ) ;
F_121 (ring, q_vector->tx)
F_73 ( V_2 , 1 , V_122 -> V_151 , V_310 ) ;
F_201 ( V_160 ) ;
}
switch ( V_2 -> V_14 . V_110 . type ) {
case V_111 :
F_73 ( V_2 , - 1 , V_314 ,
V_310 ) ;
break;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
F_73 ( V_2 , - 1 , 1 , V_310 ) ;
break;
default:
break;
}
F_71 ( & V_2 -> V_14 , F_202 ( V_310 ) , 1950 ) ;
V_119 = V_315 ;
V_119 &= ~ ( V_316 |
V_317 |
V_318 ) ;
F_71 ( & V_2 -> V_14 , V_319 , V_119 ) ;
}
static void F_203 ( struct V_159 * V_160 ,
struct V_320 * V_321 )
{
int V_173 = V_321 -> V_162 ;
int V_146 = V_321 -> V_163 ;
T_1 V_322 ;
T_6 V_323 ;
T_4 V_324 = V_321 -> V_325 ;
if ( V_146 == 0 )
return;
V_322 = V_160 -> V_325 >> 2 ;
if ( V_322 == 0 )
return;
V_323 = V_173 / V_322 ;
switch ( V_324 ) {
case V_326 :
if ( V_323 > 10 )
V_324 = V_327 ;
break;
case V_327 :
if ( V_323 > 20 )
V_324 = V_328 ;
else if ( V_323 <= 10 )
V_324 = V_326 ;
break;
case V_328 :
if ( V_323 <= 20 )
V_324 = V_327 ;
break;
}
V_321 -> V_162 = 0 ;
V_321 -> V_163 = 0 ;
V_321 -> V_325 = V_324 ;
}
void F_201 ( struct V_159 * V_160 )
{
struct V_1 * V_2 = V_160 -> V_2 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_310 = V_160 -> V_310 ;
T_1 V_329 = V_160 -> V_325 & V_330 ;
switch ( V_2 -> V_14 . V_110 . type ) {
case V_111 :
V_329 |= ( V_329 << 16 ) ;
break;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
V_329 |= V_331 ;
break;
default:
break;
}
F_71 ( V_14 , F_202 ( V_310 ) , V_329 ) ;
}
static void F_204 ( struct V_159 * V_160 )
{
T_1 V_332 = V_160 -> V_325 ;
T_4 V_333 ;
F_203 ( V_160 , & V_160 -> V_165 ) ;
F_203 ( V_160 , & V_160 -> V_303 ) ;
V_333 = F_205 ( V_160 -> V_303 . V_325 , V_160 -> V_165 . V_325 ) ;
switch ( V_333 ) {
case V_326 :
V_332 = V_334 ;
break;
case V_327 :
V_332 = V_335 ;
break;
case V_328 :
V_332 = V_336 ;
break;
default:
break;
}
if ( V_332 != V_160 -> V_325 ) {
V_332 = ( 10 * V_332 * V_160 -> V_325 ) /
( ( 9 * V_332 ) + V_160 -> V_325 ) ;
V_160 -> V_325 = V_332 ;
F_201 ( V_160 ) ;
}
}
static void F_206 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_337 = V_2 -> V_338 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
if ( ! ( V_2 -> V_156 & V_339 ) &&
! ( V_2 -> V_156 & V_340 ) )
return;
V_2 -> V_156 &= ~ V_340 ;
switch ( V_14 -> V_21 ) {
case V_341 :
if ( ! ( V_337 & V_342 ) &&
! ( V_337 & V_343 ) )
return;
if ( ! ( V_337 & V_343 ) && V_14 -> V_110 . V_344 . V_345 ) {
T_1 V_20 ;
bool V_346 = false ;
V_14 -> V_110 . V_344 . V_345 ( V_14 , & V_20 , & V_346 , false ) ;
if ( V_346 )
return;
}
if ( V_14 -> V_347 . V_344 . V_348 ( V_14 ) != V_349 )
return;
break;
default:
if ( V_2 -> V_14 . V_110 . type >= V_114 )
return;
if ( ! ( V_337 & F_207 ( V_14 ) ) )
return;
break;
}
F_208 ( V_158 , L_70 , V_350 ) ;
V_2 -> V_338 = 0 ;
}
static void F_209 ( struct V_1 * V_2 , T_1 V_337 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ( V_2 -> V_141 & V_351 ) &&
( V_337 & F_210 ( V_14 ) ) ) {
F_208 ( V_175 , L_71 ) ;
F_71 ( V_14 , V_352 , F_210 ( V_14 ) ) ;
}
}
static void F_211 ( struct V_1 * V_2 , T_1 V_337 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! ( V_2 -> V_156 & V_339 ) )
return;
switch ( V_2 -> V_14 . V_110 . type ) {
case V_113 :
if ( ( ( V_337 & F_207 ( V_14 ) ) ||
( V_337 & V_343 ) ) &&
( ! F_14 ( V_34 , & V_2 -> V_35 ) ) ) {
V_2 -> V_338 = V_337 ;
V_2 -> V_156 |= V_340 ;
F_13 ( V_2 ) ;
return;
}
return;
case V_114 :
if ( ! ( V_337 & V_353 ) )
return;
break;
default:
return;
}
F_208 ( V_158 , L_70 , V_350 ) ;
}
static inline bool F_212 ( struct V_15 * V_14 )
{
switch ( V_14 -> V_110 . type ) {
case V_111 :
if ( V_14 -> V_347 . type == V_354 )
return true ;
return false ;
case V_113 :
case V_116 :
switch ( V_14 -> V_110 . V_344 . V_355 ( V_14 ) ) {
case V_356 :
case V_357 :
return true ;
default:
return false ;
}
default:
return false ;
}
}
static void F_213 ( struct V_1 * V_2 , T_1 V_337 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_358 = F_214 ( V_14 ) ;
if ( ! F_212 ( V_14 ) )
return;
if ( V_14 -> V_110 . type >= V_114 )
V_358 = V_359 ;
if ( V_337 & V_358 ) {
F_71 ( V_14 , V_352 , V_358 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_156 |= V_360 ;
V_2 -> V_361 = 0 ;
F_13 ( V_2 ) ;
}
}
if ( V_2 -> V_14 . V_110 . type == V_113 &&
( V_337 & F_210 ( V_14 ) ) ) {
F_71 ( V_14 , V_352 , F_210 ( V_14 ) ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_141 |= V_362 ;
F_13 ( V_2 ) ;
}
}
}
static void F_215 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_363 ++ ;
V_2 -> V_141 |= V_364 ;
V_2 -> V_365 = V_174 ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_71 ( V_14 , V_366 , V_367 ) ;
F_216 ( V_14 ) ;
F_13 ( V_2 ) ;
}
}
static inline void F_217 ( struct V_1 * V_2 ,
T_6 V_118 )
{
T_1 V_119 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_110 . type ) {
case V_111 :
V_119 = ( V_120 & V_118 ) ;
F_71 ( V_14 , V_368 , V_119 ) ;
break;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
V_119 = ( V_118 & 0xFFFFFFFF ) ;
if ( V_119 )
F_71 ( V_14 , F_218 ( 0 ) , V_119 ) ;
V_119 = ( V_118 >> 32 ) ;
if ( V_119 )
F_71 ( V_14 , F_218 ( 1 ) , V_119 ) ;
break;
default:
break;
}
}
static inline void F_219 ( struct V_1 * V_2 ,
T_6 V_118 )
{
T_1 V_119 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_110 . type ) {
case V_111 :
V_119 = ( V_120 & V_118 ) ;
F_71 ( V_14 , V_366 , V_119 ) ;
break;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
V_119 = ( V_118 & 0xFFFFFFFF ) ;
if ( V_119 )
F_71 ( V_14 , F_220 ( 0 ) , V_119 ) ;
V_119 = ( V_118 >> 32 ) ;
if ( V_119 )
F_71 ( V_14 , F_220 ( 1 ) , V_119 ) ;
break;
default:
break;
}
}
static inline void F_221 ( struct V_1 * V_2 , bool V_369 ,
bool V_370 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_119 = ( V_315 & ~ V_120 ) ;
if ( V_2 -> V_141 & V_364 )
V_119 &= ~ V_318 ;
if ( V_2 -> V_156 & V_339 )
switch ( V_2 -> V_14 . V_110 . type ) {
case V_113 :
V_119 |= F_222 ( V_14 ) ;
break;
case V_114 :
case V_115 :
case V_116 :
V_119 |= V_371 ;
break;
default:
break;
}
if ( V_2 -> V_141 & V_351 )
V_119 |= F_223 ( V_14 ) ;
switch ( V_2 -> V_14 . V_110 . type ) {
case V_113 :
V_119 |= F_223 ( V_14 ) ;
V_119 |= F_224 ( V_14 ) ;
case V_114 :
case V_115 :
case V_116 :
if ( V_2 -> V_14 . V_21 == V_372 )
V_119 |= F_222 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_14 . V_347 . type == V_373 )
V_119 |= V_359 ;
V_119 |= V_374 ;
V_119 |= V_317 ;
break;
default:
break;
}
if ( ( V_2 -> V_141 & V_375 ) &&
! ( V_2 -> V_156 & V_376 ) )
V_119 |= V_377 ;
F_71 ( & V_2 -> V_14 , V_368 , V_119 ) ;
if ( V_369 )
F_217 ( V_2 , ~ 0 ) ;
if ( V_370 )
F_216 ( & V_2 -> V_14 ) ;
}
static T_11 F_225 ( int V_378 , void * V_94 )
{
struct V_1 * V_2 = V_94 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_337 ;
V_337 = F_37 ( V_14 , V_121 ) ;
V_337 &= 0xFFFF0000 ;
F_71 ( V_14 , V_352 , V_337 ) ;
if ( V_337 & V_343 )
F_215 ( V_2 ) ;
if ( V_337 & V_379 )
F_226 ( V_2 ) ;
switch ( V_14 -> V_110 . type ) {
case V_113 :
case V_114 :
case V_115 :
case V_116 :
if ( V_14 -> V_347 . type == V_373 &&
( V_337 & V_359 ) ) {
V_2 -> V_156 |= V_380 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_352 ,
V_359 ) ;
}
if ( V_337 & V_381 ) {
F_105 ( V_382 , L_72 ) ;
V_2 -> V_156 |= V_157 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_352 , V_381 ) ;
}
if ( V_337 & V_383 ) {
int V_384 = 0 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_79 ; V_50 ++ ) {
struct V_59 * V_122 = V_2 -> V_60 [ V_50 ] ;
if ( F_227 ( V_385 ,
& V_122 -> V_35 ) )
V_384 ++ ;
}
if ( V_384 ) {
F_71 ( V_14 , V_366 , V_386 ) ;
V_2 -> V_156 |= V_376 ;
F_13 ( V_2 ) ;
}
}
F_213 ( V_2 , V_337 ) ;
F_211 ( V_2 , V_337 ) ;
break;
default:
break;
}
F_209 ( V_2 , V_337 ) ;
if ( F_24 ( V_337 & V_387 ) )
F_228 ( V_2 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_221 ( V_2 , false , false ) ;
return V_388 ;
}
static T_11 F_229 ( int V_378 , void * V_94 )
{
struct V_159 * V_160 = V_94 ;
if ( V_160 -> V_303 . V_122 || V_160 -> V_165 . V_122 )
F_230 ( & V_160 -> V_260 ) ;
return V_388 ;
}
int F_231 ( struct V_304 * V_260 , int V_164 )
{
struct V_159 * V_160 =
F_196 ( V_260 , struct V_159 , V_260 ) ;
struct V_1 * V_2 = V_160 -> V_2 ;
struct V_59 * V_122 ;
int V_389 , V_390 = 0 ;
bool V_391 = true ;
#ifdef F_232
if ( V_2 -> V_141 & V_181 )
F_119 ( V_160 ) ;
#endif
F_121 (ring, q_vector->tx)
V_391 &= ! ! F_94 ( V_160 , V_122 , V_164 ) ;
if ( ( V_164 <= 0 ) || ! F_233 ( V_160 ) )
return V_164 ;
if ( V_160 -> V_303 . V_90 > 1 )
V_389 = F_205 ( V_164 / V_160 -> V_303 . V_90 , 1 ) ;
else
V_389 = V_164 ;
F_121 (ring, q_vector->rx) {
int V_308 = F_192 ( V_160 , V_122 ,
V_389 ) ;
V_390 += V_308 ;
V_391 &= ( V_308 < V_389 ) ;
}
F_234 ( V_160 ) ;
if ( ! V_391 )
return V_164 ;
F_235 ( V_260 , V_390 ) ;
if ( V_2 -> V_392 & 1 )
F_204 ( V_160 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_217 ( V_2 , ( ( T_6 ) 1 << V_160 -> V_310 ) ) ;
return 0 ;
}
static int F_236 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = V_2 -> V_57 ;
int V_393 , V_17 ;
int V_394 = 0 , V_395 = 0 ;
for ( V_393 = 0 ; V_393 < V_2 -> V_195 ; V_393 ++ ) {
struct V_159 * V_160 = V_2 -> V_160 [ V_393 ] ;
struct V_396 * V_397 = & V_2 -> V_398 [ V_393 ] ;
if ( V_160 -> V_165 . V_122 && V_160 -> V_303 . V_122 ) {
snprintf ( V_160 -> V_55 , sizeof( V_160 -> V_55 ) - 1 ,
L_73 , V_57 -> V_55 , L_74 , V_394 ++ ) ;
V_395 ++ ;
} else if ( V_160 -> V_303 . V_122 ) {
snprintf ( V_160 -> V_55 , sizeof( V_160 -> V_55 ) - 1 ,
L_73 , V_57 -> V_55 , L_75 , V_394 ++ ) ;
} else if ( V_160 -> V_165 . V_122 ) {
snprintf ( V_160 -> V_55 , sizeof( V_160 -> V_55 ) - 1 ,
L_73 , V_57 -> V_55 , L_76 , V_395 ++ ) ;
} else {
continue;
}
V_17 = F_237 ( V_397 -> V_393 , & F_229 , 0 ,
V_160 -> V_55 , V_160 ) ;
if ( V_17 ) {
F_103 ( V_175 , L_77
L_78 , V_17 ) ;
goto V_399;
}
if ( V_2 -> V_141 & V_375 ) {
F_238 ( V_397 -> V_393 ,
& V_160 -> V_400 ) ;
}
}
V_17 = F_237 ( V_2 -> V_398 [ V_393 ] . V_393 ,
F_225 , 0 , V_57 -> V_55 , V_2 ) ;
if ( V_17 ) {
F_103 ( V_175 , L_79 , V_17 ) ;
goto V_399;
}
return 0 ;
V_399:
while ( V_393 ) {
V_393 -- ;
F_238 ( V_2 -> V_398 [ V_393 ] . V_393 ,
NULL ) ;
F_239 ( V_2 -> V_398 [ V_393 ] . V_393 ,
V_2 -> V_160 [ V_393 ] ) ;
}
V_2 -> V_141 &= ~ V_401 ;
F_240 ( V_2 -> V_9 ) ;
F_241 ( V_2 -> V_398 ) ;
V_2 -> V_398 = NULL ;
return V_17 ;
}
static T_11 F_242 ( int V_378 , void * V_94 )
{
struct V_1 * V_2 = V_94 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_159 * V_160 = V_2 -> V_160 [ 0 ] ;
T_1 V_337 ;
F_71 ( V_14 , V_366 , V_402 ) ;
V_337 = F_37 ( V_14 , V_352 ) ;
if ( ! V_337 ) {
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_221 ( V_2 , true , true ) ;
return V_403 ;
}
if ( V_337 & V_343 )
F_215 ( V_2 ) ;
switch ( V_14 -> V_110 . type ) {
case V_113 :
F_213 ( V_2 , V_337 ) ;
case V_114 :
case V_115 :
case V_116 :
if ( V_337 & V_381 ) {
F_105 ( V_382 , L_72 ) ;
V_2 -> V_156 |= V_157 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_352 , V_381 ) ;
}
F_211 ( V_2 , V_337 ) ;
break;
default:
break;
}
F_209 ( V_2 , V_337 ) ;
if ( F_24 ( V_337 & V_387 ) )
F_228 ( V_2 ) ;
F_230 ( & V_160 -> V_260 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_221 ( V_2 , false , false ) ;
return V_388 ;
}
static int F_243 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = V_2 -> V_57 ;
int V_17 ;
if ( V_2 -> V_141 & V_401 )
V_17 = F_236 ( V_2 ) ;
else if ( V_2 -> V_141 & V_404 )
V_17 = F_237 ( V_2 -> V_9 -> V_378 , F_242 , 0 ,
V_57 -> V_55 , V_2 ) ;
else
V_17 = F_237 ( V_2 -> V_9 -> V_378 , F_242 , V_405 ,
V_57 -> V_55 , V_2 ) ;
if ( V_17 )
F_103 ( V_175 , L_80 , V_17 ) ;
return V_17 ;
}
static void F_244 ( struct V_1 * V_2 )
{
int V_393 ;
if ( ! ( V_2 -> V_141 & V_401 ) ) {
F_239 ( V_2 -> V_9 -> V_378 , V_2 ) ;
return;
}
for ( V_393 = 0 ; V_393 < V_2 -> V_195 ; V_393 ++ ) {
struct V_159 * V_160 = V_2 -> V_160 [ V_393 ] ;
struct V_396 * V_397 = & V_2 -> V_398 [ V_393 ] ;
if ( ! V_160 -> V_303 . V_122 && ! V_160 -> V_165 . V_122 )
continue;
F_238 ( V_397 -> V_393 , NULL ) ;
F_239 ( V_397 -> V_393 , V_160 ) ;
}
F_239 ( V_2 -> V_398 [ V_393 ++ ] . V_393 , V_2 ) ;
}
static inline void F_245 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_110 . type ) {
case V_111 :
F_71 ( & V_2 -> V_14 , V_366 , ~ 0 ) ;
break;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
F_71 ( & V_2 -> V_14 , V_366 , 0xFFFF0000 ) ;
F_71 ( & V_2 -> V_14 , F_220 ( 0 ) , ~ 0 ) ;
F_71 ( & V_2 -> V_14 , F_220 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_216 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_141 & V_401 ) {
int V_393 ;
for ( V_393 = 0 ; V_393 < V_2 -> V_195 ; V_393 ++ )
F_246 ( V_2 -> V_398 [ V_393 ] . V_393 ) ;
F_246 ( V_2 -> V_398 [ V_393 ++ ] . V_393 ) ;
} else {
F_246 ( V_2 -> V_9 -> V_378 ) ;
}
}
static void F_247 ( struct V_1 * V_2 )
{
struct V_159 * V_160 = V_2 -> V_160 [ 0 ] ;
F_201 ( V_160 ) ;
F_73 ( V_2 , 0 , 0 , 0 ) ;
F_73 ( V_2 , 1 , 0 , 0 ) ;
F_105 ( V_14 , L_81 ) ;
}
void F_248 ( struct V_1 * V_2 ,
struct V_59 * V_122 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_406 = V_122 -> V_83 ;
int V_407 = 10 ;
T_1 V_408 = V_409 ;
T_4 V_151 = V_122 -> V_151 ;
F_71 ( V_14 , F_50 ( V_151 ) , 0 ) ;
F_216 ( V_14 ) ;
F_71 ( V_14 , F_45 ( V_151 ) ,
( V_406 & F_249 ( 32 ) ) ) ;
F_71 ( V_14 , F_46 ( V_151 ) , ( V_406 >> 32 ) ) ;
F_71 ( V_14 , F_47 ( V_151 ) ,
V_122 -> V_90 * sizeof( union V_63 ) ) ;
F_71 ( V_14 , F_48 ( V_151 ) , 0 ) ;
F_71 ( V_14 , F_49 ( V_151 ) , 0 ) ;
V_122 -> V_148 = V_2 -> V_410 + F_49 ( V_151 ) ;
if ( ! V_122 -> V_160 || ( V_122 -> V_160 -> V_325 < V_334 ) )
V_408 |= ( 1 << 16 ) ;
else
V_408 |= ( 8 << 16 ) ;
V_408 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_141 & V_375 ) {
V_122 -> V_411 = V_2 -> V_411 ;
V_122 -> V_412 = 0 ;
F_250 ( V_385 , & V_122 -> V_35 ) ;
} else {
V_122 -> V_411 = 0 ;
}
if ( ! F_15 ( V_413 , & V_122 -> V_35 ) ) {
struct V_159 * V_160 = V_122 -> V_160 ;
if ( V_160 )
F_251 ( V_122 -> V_57 ,
& V_160 -> V_400 ,
V_122 -> V_88 ) ;
}
F_34 ( V_134 , & V_122 -> V_35 ) ;
F_71 ( V_14 , F_50 ( V_151 ) , V_408 ) ;
if ( V_14 -> V_110 . type == V_111 &&
! ( F_37 ( V_14 , V_414 ) & V_415 ) )
return;
do {
F_252 ( 1000 , 2000 ) ;
V_408 = F_37 ( V_14 , F_50 ( V_151 ) ) ;
} while ( -- V_407 && ! ( V_408 & V_409 ) );
if ( ! V_407 )
F_103 ( V_158 , L_82 , V_151 ) ;
}
static void F_253 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_416 , V_417 ;
T_4 V_418 = F_254 ( V_2 -> V_57 ) ;
if ( V_14 -> V_110 . type == V_111 )
return;
V_416 = F_37 ( V_14 , V_419 ) ;
V_416 |= V_420 ;
F_71 ( V_14 , V_419 , V_416 ) ;
if ( V_2 -> V_141 & V_421 ) {
V_417 = V_422 ;
if ( V_418 > 4 )
V_417 |= V_423 | V_424 ;
else if ( V_418 > 1 )
V_417 |= V_423 | V_425 ;
else if ( V_2 -> V_426 [ V_427 ] . V_428 == 4 )
V_417 |= V_429 ;
else
V_417 |= V_430 ;
} else {
if ( V_418 > 4 )
V_417 = V_423 | V_424 ;
else if ( V_418 > 1 )
V_417 = V_423 | V_425 ;
else
V_417 = V_431 ;
}
F_71 ( V_14 , V_432 , V_417 ) ;
if ( V_418 ) {
T_1 V_433 = F_37 ( V_14 , V_434 ) ;
V_433 |= V_435 ;
F_71 ( V_14 , V_434 , V_433 ) ;
}
V_416 &= ~ V_420 ;
F_71 ( V_14 , V_419 , V_416 ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_436 ;
T_1 V_50 ;
F_253 ( V_2 ) ;
if ( V_14 -> V_110 . type != V_111 ) {
V_436 = F_37 ( V_14 , V_437 ) ;
V_436 |= V_438 ;
F_71 ( V_14 , V_437 , V_436 ) ;
}
for ( V_50 = 0 ; V_50 < V_2 -> V_79 ; V_50 ++ )
F_248 ( V_2 , V_2 -> V_60 [ V_50 ] ) ;
}
static void F_256 ( struct V_1 * V_2 ,
struct V_59 * V_122 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_151 = V_122 -> V_151 ;
T_1 V_439 = F_37 ( V_14 , F_36 ( V_151 ) ) ;
V_439 |= V_440 ;
F_71 ( V_14 , F_36 ( V_151 ) , V_439 ) ;
}
static void F_257 ( struct V_1 * V_2 ,
struct V_59 * V_122 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_151 = V_122 -> V_151 ;
T_1 V_439 = F_37 ( V_14 , F_36 ( V_151 ) ) ;
V_439 &= ~ V_440 ;
F_71 ( V_14 , F_36 ( V_151 ) , V_439 ) ;
}
static void F_258 ( struct V_1 * V_2 ,
struct V_59 * V_69 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_439 ;
T_4 V_151 = V_69 -> V_151 ;
if ( V_14 -> V_110 . type == V_111 ) {
T_2 V_119 = V_2 -> V_426 [ V_427 ] . V_119 ;
V_151 &= V_119 ;
}
V_439 = V_275 << V_441 ;
V_439 |= F_69 ( V_69 ) >> V_442 ;
V_439 |= V_443 ;
F_71 ( V_14 , F_36 ( V_151 ) , V_439 ) ;
}
T_1 F_259 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_110 . type < V_115 )
return 128 ;
else if ( V_2 -> V_141 & V_421 )
return 64 ;
else
return 512 ;
}
void F_260 ( struct V_1 * V_2 )
{
T_1 V_50 , V_444 = F_259 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_445 = 0 ;
T_1 V_446 ;
T_4 * V_447 = V_2 -> V_448 ;
if ( V_2 -> V_14 . V_110 . type == V_111 )
V_446 = 0x11 ;
else
V_446 = 0x1 ;
for ( V_50 = 0 ; V_50 < V_444 ; V_50 ++ ) {
V_445 |= V_446 * V_447 [ V_50 ] << ( V_50 & 0x3 ) * 8 ;
if ( ( V_50 & 3 ) == 3 ) {
if ( V_50 < 128 )
F_71 ( V_14 , F_261 ( V_50 >> 2 ) , V_445 ) ;
else
F_71 ( V_14 , F_262 ( ( V_50 >> 2 ) - 32 ) ,
V_445 ) ;
V_445 = 0 ;
}
}
}
static void F_263 ( struct V_1 * V_2 )
{
T_1 V_50 , V_444 = F_259 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_449 = 0 ;
unsigned int V_450 = V_2 -> V_311 ;
for ( V_50 = 0 ; V_50 < V_444 ; V_50 ++ ) {
V_449 |= ( T_1 ) V_2 -> V_448 [ V_50 ] << ( V_50 & 0x3 ) * 8 ;
if ( ( V_50 & 3 ) == 3 ) {
F_71 ( V_14 , F_264 ( V_50 >> 2 , V_450 ) ,
V_449 ) ;
V_449 = 0 ;
}
}
}
static void F_265 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_50 , V_51 ;
T_1 V_444 = F_259 ( V_2 ) ;
T_2 V_451 = V_2 -> V_426 [ V_427 ] . V_428 ;
if ( ( V_2 -> V_141 & V_421 ) && ( V_451 < 2 ) )
V_451 = 2 ;
for ( V_50 = 0 ; V_50 < 10 ; V_50 ++ )
F_71 ( V_14 , F_266 ( V_50 ) , V_2 -> V_452 [ V_50 ] ) ;
memset ( V_2 -> V_448 , 0 , sizeof( V_2 -> V_448 ) ) ;
for ( V_50 = 0 , V_51 = 0 ; V_50 < V_444 ; V_50 ++ , V_51 ++ ) {
if ( V_51 == V_451 )
V_51 = 0 ;
V_2 -> V_448 [ V_50 ] = V_51 ;
}
F_260 ( V_2 ) ;
}
static void F_267 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_451 = V_2 -> V_426 [ V_427 ] . V_428 ;
unsigned int V_450 = V_2 -> V_311 ;
int V_50 , V_51 ;
for ( V_50 = 0 ; V_50 < 10 ; V_50 ++ )
F_71 ( V_14 , F_268 ( V_50 , V_450 ) ,
V_2 -> V_452 [ V_50 ] ) ;
for ( V_50 = 0 , V_51 = 0 ; V_50 < 64 ; V_50 ++ , V_51 ++ ) {
if ( V_51 == V_451 )
V_51 = 0 ;
V_2 -> V_448 [ V_50 ] = V_51 ;
}
F_263 ( V_2 ) ;
}
static void F_269 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_453 = 0 , V_454 = 0 , V_455 = 0 ;
T_1 V_456 ;
V_456 = F_37 ( V_14 , V_457 ) ;
V_456 |= V_458 ;
F_71 ( V_14 , V_457 , V_456 ) ;
if ( V_2 -> V_14 . V_110 . type == V_111 ) {
if ( V_2 -> V_426 [ V_427 ] . V_119 )
V_453 = V_459 ;
} else {
T_4 V_418 = F_254 ( V_2 -> V_57 ) ;
if ( V_2 -> V_141 & V_421 ) {
if ( V_418 > 4 )
V_453 = V_460 ;
else if ( V_418 > 1 )
V_453 = V_461 ;
else if ( V_2 -> V_426 [ V_427 ] . V_428 == 4 )
V_453 = V_462 ;
else
V_453 = V_463 ;
} else {
if ( V_418 > 4 )
V_453 = V_464 ;
else if ( V_418 > 1 )
V_453 = V_465 ;
else
V_453 = V_459 ;
}
}
V_454 |= V_466 |
V_467 |
V_468 |
V_469 ;
if ( V_2 -> V_156 & V_470 )
V_454 |= V_471 ;
if ( V_2 -> V_156 & V_472 )
V_454 |= V_473 ;
F_270 ( V_2 -> V_452 , sizeof( V_2 -> V_452 ) ) ;
if ( ( V_14 -> V_110 . type >= V_115 ) &&
( V_2 -> V_141 & V_421 ) ) {
unsigned int V_450 = V_2 -> V_311 ;
V_453 |= V_474 ;
F_71 ( V_14 , V_475 , V_453 ) ;
F_267 ( V_2 ) ;
V_455 = V_459 ;
V_455 |= V_454 ;
F_71 ( V_14 , F_271 ( V_450 ) , V_455 ) ;
} else {
F_265 ( V_2 ) ;
V_453 |= V_454 ;
F_71 ( V_14 , V_475 , V_453 ) ;
}
}
static void F_272 ( struct V_1 * V_2 ,
struct V_59 * V_122 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_476 ;
T_4 V_151 = V_122 -> V_151 ;
if ( ! F_165 ( V_122 ) )
return;
V_476 = F_37 ( V_14 , F_273 ( V_151 ) ) ;
V_476 |= V_477 ;
V_476 |= V_478 ;
F_71 ( V_14 , F_273 ( V_151 ) , V_476 ) ;
}
static void F_274 ( struct V_1 * V_2 ,
struct V_59 * V_122 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_407 = V_479 ;
T_1 V_480 ;
T_4 V_151 = V_122 -> V_151 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
if ( V_14 -> V_110 . type == V_111 &&
! ( F_37 ( V_14 , V_414 ) & V_415 ) )
return;
do {
F_252 ( 1000 , 2000 ) ;
V_480 = F_37 ( V_14 , F_42 ( V_151 ) ) ;
} while ( -- V_407 && ! ( V_480 & V_481 ) );
if ( ! V_407 ) {
F_103 ( V_158 , L_83
L_84 , V_151 ) ;
}
}
void F_275 ( struct V_1 * V_2 ,
struct V_59 * V_122 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_407 = V_479 ;
T_1 V_480 ;
T_4 V_151 = V_122 -> V_151 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
V_480 = F_37 ( V_14 , F_42 ( V_151 ) ) ;
V_480 &= ~ V_481 ;
F_71 ( V_14 , F_42 ( V_151 ) , V_480 ) ;
if ( V_14 -> V_110 . type == V_111 &&
! ( F_37 ( V_14 , V_414 ) & V_415 ) )
return;
do {
F_276 ( 10 ) ;
V_480 = F_37 ( V_14 , F_42 ( V_151 ) ) ;
} while ( -- V_407 && ( V_480 & V_481 ) );
if ( ! V_407 ) {
F_103 ( V_158 , L_85
L_84 , V_151 ) ;
}
}
void F_277 ( struct V_1 * V_2 ,
struct V_59 * V_122 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_482 = V_122 -> V_83 ;
T_1 V_480 ;
T_4 V_151 = V_122 -> V_151 ;
V_480 = F_37 ( V_14 , F_42 ( V_151 ) ) ;
F_275 ( V_2 , V_122 ) ;
F_71 ( V_14 , F_43 ( V_151 ) , ( V_482 & F_249 ( 32 ) ) ) ;
F_71 ( V_14 , F_44 ( V_151 ) , ( V_482 >> 32 ) ) ;
F_71 ( V_14 , F_39 ( V_151 ) ,
V_122 -> V_90 * sizeof( union V_70 ) ) ;
F_216 ( V_14 ) ;
F_71 ( V_14 , F_40 ( V_151 ) , 0 ) ;
F_71 ( V_14 , F_41 ( V_151 ) , 0 ) ;
V_122 -> V_148 = V_2 -> V_410 + F_41 ( V_151 ) ;
F_258 ( V_2 , V_122 ) ;
F_272 ( V_2 , V_122 ) ;
if ( V_14 -> V_110 . type == V_111 ) {
V_480 &= ~ 0x3FFFFF ;
V_480 |= 0x080420 ;
}
V_480 |= V_481 ;
F_71 ( V_14 , F_42 ( V_151 ) , V_480 ) ;
F_274 ( V_2 , V_122 ) ;
F_143 ( V_122 , F_110 ( V_122 ) ) ;
}
static void F_278 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_451 = V_2 -> V_426 [ V_427 ] . V_428 ;
T_2 V_483 ;
T_1 V_484 = V_485 |
V_486 |
V_487 |
V_488 |
V_489 ;
if ( V_14 -> V_110 . type == V_111 )
return;
if ( V_451 > 3 )
V_484 |= 2 << 29 ;
else if ( V_451 > 1 )
V_484 |= 1 << 29 ;
F_279 (pool, &adapter->fwd_bitmask, 32 )
F_71 ( V_14 , F_280 ( F_281 ( V_483 ) ) , V_484 ) ;
}
static void F_282 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_180 , V_490 ;
T_1 V_491 , V_492 ;
int V_50 ;
if ( ! ( V_2 -> V_141 & V_421 ) )
return;
V_492 = F_37 ( V_14 , V_493 ) ;
V_492 |= V_494 ;
V_492 &= ~ V_495 ;
V_492 |= F_281 ( 0 ) << V_496 ;
V_492 |= V_497 ;
F_71 ( V_14 , V_493 , V_492 ) ;
V_490 = F_281 ( 0 ) % 32 ;
V_180 = ( F_281 ( 0 ) >= 32 ) ? 1 : 0 ;
F_71 ( V_14 , F_283 ( V_180 ) , ( ~ 0 ) << V_490 ) ;
F_71 ( V_14 , F_283 ( V_180 ^ 1 ) , V_180 - 1 ) ;
F_71 ( V_14 , F_284 ( V_180 ) , ( ~ 0 ) << V_490 ) ;
F_71 ( V_14 , F_284 ( V_180 ^ 1 ) , V_180 - 1 ) ;
if ( V_2 -> V_498 == V_499 )
F_71 ( V_14 , V_500 , V_501 ) ;
V_14 -> V_110 . V_344 . V_502 ( V_14 , 0 , F_281 ( 0 ) ) ;
V_2 -> V_156 &= ~ V_503 ;
switch ( V_2 -> V_426 [ V_504 ] . V_119 ) {
case V_505 :
V_491 = V_506 ;
break;
case V_507 :
V_491 = V_508 ;
break;
default:
V_491 = V_509 ;
break;
}
F_71 ( V_14 , V_510 , V_491 ) ;
V_14 -> V_110 . V_344 . V_511 ( V_14 , ( V_2 -> V_311 != 0 ) ,
V_2 -> V_311 ) ;
if ( V_14 -> V_110 . V_344 . V_512 ) {
F_71 ( V_14 , F_285 ( V_513 ) ,
( V_514 |
V_515 |
V_516 ) ) ;
F_71 ( V_14 , F_285 ( V_517 ) ,
( V_514 |
V_515 |
V_518 ) ) ;
}
for ( V_50 = 0 ; V_50 < V_2 -> V_311 ; V_50 ++ ) {
if ( ! V_2 -> V_519 [ V_50 ] . V_520 )
F_286 ( V_2 -> V_57 , V_50 , false ) ;
if ( V_14 -> V_110 . V_344 . V_512 )
V_14 -> V_110 . V_344 . V_512 ( V_14 , true , V_50 ) ;
F_287 ( V_2 -> V_57 , V_50 ,
V_2 -> V_519 [ V_50 ] . V_521 ) ;
}
}
static void F_288 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_56 * V_57 = V_2 -> V_57 ;
int V_522 = V_57 -> V_299 + V_523 + V_524 ;
struct V_59 * V_69 ;
int V_50 ;
T_1 V_525 , V_526 ;
#ifdef F_176
if ( ( V_2 -> V_141 & V_527 ) &&
( V_522 < V_528 ) )
V_522 = V_528 ;
#endif
if ( V_522 < ( V_529 + V_524 ) )
V_522 = ( V_529 + V_524 ) ;
V_525 = F_37 ( V_14 , V_530 ) ;
if ( V_522 != ( V_525 >> V_531 ) ) {
V_525 &= ~ V_532 ;
V_525 |= V_522 << V_531 ;
F_71 ( V_14 , V_530 , V_525 ) ;
}
V_526 = F_37 ( V_14 , V_533 ) ;
V_526 |= V_534 ;
F_71 ( V_14 , V_533 , V_526 ) ;
for ( V_50 = 0 ; V_50 < V_2 -> V_95 ; V_50 ++ ) {
V_69 = V_2 -> V_69 [ V_50 ] ;
if ( V_2 -> V_156 & V_535 )
F_289 ( V_69 ) ;
else
F_290 ( V_69 ) ;
}
}
static void F_291 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_536 = F_37 ( V_14 , V_537 ) ;
switch ( V_14 -> V_110 . type ) {
case V_111 :
V_536 |= V_538 ;
break;
case V_115 :
case V_116 :
if ( V_2 -> V_311 )
V_536 |= V_539 ;
case V_113 :
case V_114 :
F_71 ( V_14 , V_540 ,
( V_541 | F_37 ( V_14 , V_540 ) ) ) ;
V_536 &= ~ V_542 ;
V_536 |= ( V_543 | V_544 ) ;
V_536 |= V_545 ;
break;
default:
return;
}
F_71 ( V_14 , V_537 , V_536 ) ;
}
static void F_292 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_50 ;
T_1 V_186 , V_546 ;
V_14 -> V_110 . V_344 . V_547 ( V_14 ) ;
F_278 ( V_2 ) ;
F_291 ( V_2 ) ;
V_546 = F_37 ( V_14 , V_548 ) ;
V_546 &= ~ V_549 ;
if ( ! ( V_2 -> V_156 & V_535 ) )
V_546 |= V_549 ;
F_71 ( V_14 , V_548 , V_546 ) ;
F_269 ( V_2 ) ;
F_288 ( V_2 ) ;
for ( V_50 = 0 ; V_50 < V_2 -> V_95 ; V_50 ++ )
F_277 ( V_2 , V_2 -> V_69 [ V_50 ] ) ;
V_186 = F_37 ( V_14 , V_550 ) ;
if ( V_14 -> V_110 . type == V_111 )
V_186 |= V_551 ;
V_186 |= V_552 ;
V_14 -> V_110 . V_344 . V_553 ( V_14 , V_186 ) ;
}
static int F_293 ( struct V_56 * V_57 ,
T_12 V_554 , T_2 V_256 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_110 . V_344 . V_555 ( & V_2 -> V_14 , V_256 , F_281 ( 0 ) , true , true ) ;
F_250 ( V_256 , V_2 -> V_556 ) ;
return 0 ;
}
static int F_294 ( struct V_15 * V_14 , T_1 V_257 )
{
T_1 V_557 ;
int V_558 ;
if ( V_257 == 0 )
return 0 ;
for ( V_558 = V_559 ; -- V_558 ; ) {
V_557 = F_37 ( V_14 , F_295 ( V_558 ) ) ;
if ( ( V_557 & V_560 ) == V_257 )
break;
}
return V_558 ;
}
void F_296 ( struct V_1 * V_2 , T_1 V_256 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_561 , V_562 ;
int V_558 ;
V_558 = F_294 ( V_14 , V_256 ) ;
if ( ! V_558 )
return;
V_562 = V_558 * 2 + ( F_281 ( 0 ) / 32 ) ;
V_561 = ~ ( 1 << ( F_281 ( 0 ) ) % 32 ) ;
V_561 &= F_37 ( V_14 , F_297 ( V_562 ) ) ;
if ( ! V_561 && ! F_37 ( V_14 , F_297 ( V_562 ^ 1 ) ) ) {
if ( ! ( V_2 -> V_156 & V_503 ) )
F_71 ( V_14 , F_297 ( V_562 ) , 0 ) ;
F_71 ( V_14 , F_295 ( V_558 ) , 0 ) ;
}
}
static int F_298 ( struct V_56 * V_57 ,
T_12 V_554 , T_2 V_256 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_2 -> V_156 & V_503 )
F_296 ( V_2 , V_256 ) ;
else
V_14 -> V_110 . V_344 . V_555 ( V_14 , V_256 , F_281 ( 0 ) , false , true ) ;
F_34 ( V_256 , V_2 -> V_556 ) ;
return 0 ;
}
static void F_299 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_563 ;
int V_50 , V_51 ;
switch ( V_14 -> V_110 . type ) {
case V_111 :
V_563 = F_37 ( V_14 , V_564 ) ;
V_563 &= ~ V_565 ;
F_71 ( V_14 , V_564 , V_563 ) ;
break;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
for ( V_50 = 0 ; V_50 < V_2 -> V_95 ; V_50 ++ ) {
struct V_59 * V_122 = V_2 -> V_69 [ V_50 ] ;
if ( V_122 -> V_149 )
continue;
V_51 = V_122 -> V_151 ;
V_563 = F_37 ( V_14 , F_42 ( V_51 ) ) ;
V_563 &= ~ V_566 ;
F_71 ( V_14 , F_42 ( V_51 ) , V_563 ) ;
}
break;
default:
break;
}
}
static void F_300 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_563 ;
int V_50 , V_51 ;
switch ( V_14 -> V_110 . type ) {
case V_111 :
V_563 = F_37 ( V_14 , V_564 ) ;
V_563 |= V_565 ;
F_71 ( V_14 , V_564 , V_563 ) ;
break;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
for ( V_50 = 0 ; V_50 < V_2 -> V_95 ; V_50 ++ ) {
struct V_59 * V_122 = V_2 -> V_69 [ V_50 ] ;
if ( V_122 -> V_149 )
continue;
V_51 = V_122 -> V_151 ;
V_563 = F_37 ( V_14 , F_42 ( V_51 ) ) ;
V_563 |= V_566 ;
F_71 ( V_14 , F_42 ( V_51 ) , V_563 ) ;
}
break;
default:
break;
}
}
static void F_301 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_563 , V_50 ;
switch ( V_14 -> V_110 . type ) {
case V_113 :
case V_114 :
case V_115 :
case V_116 :
default:
if ( V_2 -> V_141 & V_567 )
break;
case V_111 :
V_563 = F_37 ( V_14 , V_564 ) ;
V_563 &= ~ ( V_568 | V_569 ) ;
F_71 ( V_14 , V_564 , V_563 ) ;
return;
}
if ( V_2 -> V_156 & V_503 )
return;
V_2 -> V_156 |= V_503 ;
for ( V_50 = V_559 ; -- V_50 ; ) {
T_1 V_180 = F_297 ( V_50 * 2 + F_281 ( 0 ) / 32 ) ;
T_1 V_570 = F_37 ( V_14 , V_180 ) ;
V_570 |= 1 << ( F_281 ( 0 ) % 32 ) ;
F_71 ( V_14 , V_180 , V_570 ) ;
}
for ( V_50 = V_14 -> V_110 . V_571 ; V_50 -- ; )
F_71 ( V_14 , F_302 ( V_50 ) , ~ 0U ) ;
}
static void F_303 ( struct V_1 * V_2 , T_1 V_572 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_573 [ V_574 ] = { 0 } ;
T_1 V_575 = V_572 * 32 ;
T_1 V_576 = V_575 + ( V_574 * 32 ) ;
T_1 V_50 , V_256 , V_562 , V_561 ;
for ( V_50 = V_559 ; -- V_50 ; ) {
T_1 V_557 = F_37 ( V_14 , F_295 ( V_50 ) ) ;
V_256 = V_557 & V_560 ;
if ( V_256 < V_575 || V_256 >= V_576 )
continue;
if ( V_557 ) {
V_573 [ ( V_256 - V_575 ) / 32 ] |= 1 << ( V_256 % 32 ) ;
if ( F_14 ( V_256 , V_2 -> V_556 ) )
continue;
}
V_562 = V_50 * 2 + F_281 ( 0 ) / 32 ;
V_561 = ~ ( 1 << ( F_281 ( 0 ) % 32 ) ) ;
V_561 &= F_37 ( V_14 , F_297 ( V_562 ) ) ;
F_71 ( V_14 , F_297 ( V_562 ) , V_561 ) ;
}
for ( V_50 = V_574 ; V_50 -- ; ) {
V_256 = ( V_572 + V_50 ) * 32 ;
V_562 = V_256 / V_577 ;
V_561 = V_256 % V_577 ;
V_573 [ V_50 ] |= V_2 -> V_556 [ V_562 ] >> V_561 ;
F_71 ( V_14 , F_302 ( V_572 + V_50 ) , V_573 [ V_50 ] ) ;
}
}
static void F_304 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_563 , V_50 ;
switch ( V_14 -> V_110 . type ) {
case V_113 :
case V_114 :
case V_115 :
case V_116 :
default:
if ( V_2 -> V_141 & V_567 )
break;
case V_111 :
V_563 = F_37 ( V_14 , V_564 ) ;
V_563 &= ~ V_569 ;
V_563 |= V_568 ;
F_71 ( V_14 , V_564 , V_563 ) ;
return;
}
if ( ! ( V_2 -> V_156 & V_503 ) )
return;
V_2 -> V_156 &= ~ V_503 ;
for ( V_50 = 0 ; V_50 < V_14 -> V_110 . V_571 ; V_50 += V_574 )
F_303 ( V_2 , V_50 ) ;
}
static void F_305 ( struct V_1 * V_2 )
{
T_2 V_256 ;
F_293 ( V_2 -> V_57 , F_156 ( V_258 ) , 0 ) ;
F_279 (vid, adapter->active_vlans, VLAN_N_VID)
F_293 ( V_2 -> V_57 , F_156 ( V_258 ) , V_256 ) ;
}
static int F_306 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! F_57 ( V_57 ) )
return 0 ;
if ( V_14 -> V_110 . V_344 . V_578 )
V_14 -> V_110 . V_344 . V_578 ( V_14 , V_57 ) ;
else
return - V_579 ;
#ifdef F_307
F_308 ( V_2 ) ;
#endif
return F_309 ( V_57 ) ;
}
void F_310 ( struct V_1 * V_2 )
{
struct V_580 * V_581 = & V_2 -> V_581 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_14 -> V_110 . V_582 ; V_50 ++ , V_581 ++ ) {
V_581 -> V_35 &= ~ V_583 ;
if ( V_581 -> V_35 & V_584 )
V_14 -> V_110 . V_344 . V_585 ( V_14 , V_50 ,
V_581 -> V_586 ,
V_581 -> V_483 ,
V_587 ) ;
else
V_14 -> V_110 . V_344 . V_588 ( V_14 , V_50 ) ;
}
}
static void F_311 ( struct V_1 * V_2 )
{
struct V_580 * V_581 = & V_2 -> V_581 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_14 -> V_110 . V_582 ; V_50 ++ , V_581 ++ ) {
if ( ! ( V_581 -> V_35 & V_583 ) )
continue;
V_581 -> V_35 &= ~ V_583 ;
if ( V_581 -> V_35 & V_584 )
V_14 -> V_110 . V_344 . V_585 ( V_14 , V_50 ,
V_581 -> V_586 ,
V_581 -> V_483 ,
V_587 ) ;
else
V_14 -> V_110 . V_344 . V_588 ( V_14 , V_50 ) ;
}
}
static void F_312 ( struct V_1 * V_2 )
{
struct V_580 * V_581 = & V_2 -> V_581 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_14 -> V_110 . V_582 ; V_50 ++ , V_581 ++ ) {
V_581 -> V_35 |= V_583 ;
V_581 -> V_35 &= ~ V_584 ;
}
F_311 ( V_2 ) ;
}
static int F_313 ( struct V_1 * V_2 , T_2 V_483 )
{
struct V_580 * V_581 = & V_2 -> V_581 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_50 , V_90 = 0 ;
for ( V_50 = 0 ; V_50 < V_14 -> V_110 . V_582 ; V_50 ++ , V_581 ++ ) {
if ( V_581 -> V_35 & V_589 )
continue;
if ( V_581 -> V_35 & V_584 ) {
if ( V_581 -> V_483 != V_483 )
continue;
}
V_90 ++ ;
}
return V_90 ;
}
static void F_314 ( struct V_1 * V_2 )
{
struct V_580 * V_581 = & V_2 -> V_581 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
memcpy ( & V_581 -> V_586 , V_14 -> V_110 . V_586 , V_590 ) ;
V_581 -> V_483 = F_281 ( 0 ) ;
V_581 -> V_35 = V_589 | V_584 ;
V_14 -> V_110 . V_344 . V_585 ( V_14 , 0 , V_581 -> V_586 , V_581 -> V_483 ,
V_587 ) ;
}
int F_315 ( struct V_1 * V_2 ,
const T_4 * V_586 , T_2 V_483 )
{
struct V_580 * V_581 = & V_2 -> V_581 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_50 ;
if ( F_316 ( V_586 ) )
return - V_591 ;
for ( V_50 = 0 ; V_50 < V_14 -> V_110 . V_582 ; V_50 ++ , V_581 ++ ) {
if ( V_581 -> V_35 & V_584 )
continue;
F_317 ( V_581 -> V_586 , V_586 ) ;
V_581 -> V_483 = V_483 ;
V_581 -> V_35 |= V_583 |
V_584 ;
F_311 ( V_2 ) ;
return V_50 ;
}
return - V_579 ;
}
int F_318 ( struct V_1 * V_2 ,
const T_4 * V_586 , T_2 V_483 )
{
struct V_580 * V_581 = & V_2 -> V_581 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_50 ;
if ( F_316 ( V_586 ) )
return - V_591 ;
for ( V_50 = 0 ; V_50 < V_14 -> V_110 . V_582 ; V_50 ++ , V_581 ++ ) {
if ( ! ( V_581 -> V_35 & V_584 ) )
continue;
if ( V_581 -> V_483 != V_483 )
continue;
if ( ! F_319 ( V_586 , V_581 -> V_586 ) )
continue;
V_581 -> V_35 |= V_583 ;
V_581 -> V_35 &= ~ V_584 ;
F_311 ( V_2 ) ;
return 0 ;
}
return - V_579 ;
}
static int F_320 ( struct V_56 * V_57 , int V_592 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
int V_90 = 0 ;
if ( F_321 ( V_57 ) > F_313 ( V_2 , V_592 ) )
return - V_579 ;
if ( ! F_322 ( V_57 ) ) {
struct V_593 * V_594 ;
F_323 (ha, netdev) {
F_318 ( V_2 , V_594 -> V_586 , V_592 ) ;
F_315 ( V_2 , V_594 -> V_586 , V_592 ) ;
V_90 ++ ;
}
}
return V_90 ;
}
static int F_324 ( struct V_56 * V_57 , const unsigned char * V_586 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
int V_595 ;
V_595 = F_315 ( V_2 , V_586 , F_281 ( 0 ) ) ;
return F_325 ( int , V_595 , 0 ) ;
}
static int F_326 ( struct V_56 * V_57 , const unsigned char * V_586 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
F_318 ( V_2 , V_586 , F_281 ( 0 ) ) ;
return 0 ;
}
void F_327 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_596 , V_597 = V_598 | V_599 ;
int V_90 ;
V_596 = F_37 ( V_14 , V_600 ) ;
V_596 &= ~ V_601 ;
V_596 |= V_602 ;
V_596 |= V_603 ;
V_596 |= V_604 ;
V_596 &= ~ ( V_605 | V_606 ) ;
if ( V_57 -> V_141 & V_607 ) {
V_14 -> V_608 . V_609 = true ;
V_596 |= ( V_605 | V_606 ) ;
V_597 |= V_610 ;
F_301 ( V_2 ) ;
} else {
if ( V_57 -> V_141 & V_611 ) {
V_596 |= V_606 ;
V_597 |= V_610 ;
}
V_14 -> V_608 . V_609 = false ;
F_304 ( V_2 ) ;
}
if ( F_328 ( V_57 , F_324 , F_326 ) ) {
V_596 |= V_605 ;
V_597 |= V_612 ;
}
V_90 = F_306 ( V_57 ) ;
if ( V_90 < 0 ) {
V_596 |= V_606 ;
V_597 |= V_610 ;
} else if ( V_90 ) {
V_597 |= V_613 ;
}
if ( V_14 -> V_110 . type != V_111 ) {
V_597 |= F_37 ( V_14 , F_329 ( F_281 ( 0 ) ) ) &
~ ( V_610 | V_613 |
V_612 ) ;
F_71 ( V_14 , F_329 ( F_281 ( 0 ) ) , V_597 ) ;
}
if ( V_2 -> V_57 -> V_203 & V_279 ) {
V_596 |= ( V_601 |
V_602 |
V_604 ) ;
V_596 &= ~ ( V_603 ) ;
}
F_71 ( V_14 , V_600 , V_596 ) ;
if ( V_57 -> V_203 & V_254 )
F_300 ( V_2 ) ;
else
F_299 ( V_2 ) ;
}
static void F_330 ( struct V_1 * V_2 )
{
int V_614 ;
for ( V_614 = 0 ; V_614 < V_2 -> V_195 ; V_614 ++ ) {
F_331 ( V_2 -> V_160 [ V_614 ] ) ;
F_332 ( & V_2 -> V_160 [ V_614 ] -> V_260 ) ;
}
}
static void F_333 ( struct V_1 * V_2 )
{
int V_614 ;
for ( V_614 = 0 ; V_614 < V_2 -> V_195 ; V_614 ++ ) {
F_334 ( & V_2 -> V_160 [ V_614 ] -> V_260 ) ;
while ( ! F_335 ( V_2 -> V_160 [ V_614 ] ) ) {
F_51 ( L_86 , V_614 ) ;
F_252 ( 1000 , 20000 ) ;
}
}
}
static void F_336 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_110 . type ) {
case V_115 :
case V_116 :
F_71 ( & V_2 -> V_14 , V_615 , 0 ) ;
V_2 -> V_616 = 0 ;
break;
default:
break;
}
}
static void F_337 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_522 = V_2 -> V_57 -> V_299 + V_523 + V_524 ;
if ( ! ( V_2 -> V_141 & V_142 ) ) {
if ( V_14 -> V_110 . type == V_111 )
F_338 ( V_2 -> V_57 , 65536 ) ;
return;
}
if ( V_14 -> V_110 . type == V_111 )
F_338 ( V_2 -> V_57 , 32768 ) ;
#ifdef F_176
if ( V_2 -> V_57 -> V_203 & V_617 )
V_522 = F_205 ( V_522 , V_528 ) ;
#endif
if ( V_2 -> V_618 & V_619 ) {
F_339 ( V_14 , & V_2 -> V_138 , V_522 ,
V_620 ) ;
F_339 ( V_14 , & V_2 -> V_138 , V_522 ,
V_621 ) ;
F_340 ( V_14 , & V_2 -> V_138 ) ;
} else if ( V_2 -> V_622 && V_2 -> V_140 ) {
F_341 ( & V_2 -> V_14 ,
V_2 -> V_622 ,
V_522 ) ;
F_342 ( & V_2 -> V_14 ,
V_2 -> V_140 -> V_137 ,
V_2 -> V_622 -> V_623 ) ;
}
if ( V_14 -> V_110 . type != V_111 ) {
T_1 V_624 = 0 ;
T_2 V_451 = V_2 -> V_426 [ V_427 ] . V_428 - 1 ;
while ( V_451 ) {
V_624 ++ ;
V_451 >>= 1 ;
}
F_71 ( V_14 , V_625 , V_624 * 0x11111111 ) ;
}
}
static int F_343 ( struct V_1 * V_2 , int V_626 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_56 * V_75 = V_2 -> V_57 ;
int V_382 , V_136 , V_627 , V_628 ;
T_1 V_629 , V_630 ;
V_136 = V_382 = V_75 -> V_299 + V_523 + V_524 + V_631 ;
#ifdef F_176
if ( ( V_75 -> V_203 & V_617 ) &&
( V_136 < V_528 ) &&
( V_626 == F_344 ( V_2 ) ) )
V_136 = V_528 ;
#endif
switch ( V_14 -> V_110 . type ) {
case V_114 :
case V_115 :
case V_116 :
V_629 = F_345 ( V_382 , V_136 ) ;
break;
default:
V_629 = F_346 ( V_382 , V_136 ) ;
break;
}
if ( V_2 -> V_141 & V_421 )
V_629 += F_347 ( V_136 ) ;
V_627 = F_348 ( V_629 ) ;
V_630 = F_37 ( V_14 , F_349 ( V_626 ) ) >> 10 ;
V_628 = V_630 - V_627 ;
if ( V_628 < 0 ) {
F_93 ( V_158 , L_87
L_88
L_89 , V_626 ) ;
V_628 = V_136 + 1 ;
}
return V_628 ;
}
static int F_350 ( struct V_1 * V_2 , int V_626 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_56 * V_75 = V_2 -> V_57 ;
int V_136 ;
T_1 V_629 ;
V_136 = V_75 -> V_299 + V_523 + V_524 ;
#ifdef F_176
if ( ( V_75 -> V_203 & V_617 ) &&
( V_136 < V_528 ) &&
( V_626 == F_86 ( V_75 , V_2 -> V_632 . V_633 ) ) )
V_136 = V_528 ;
#endif
switch ( V_14 -> V_110 . type ) {
case V_114 :
case V_115 :
case V_116 :
V_629 = F_351 ( V_136 ) ;
break;
default:
V_629 = F_352 ( V_136 ) ;
break;
}
return F_348 ( V_629 ) ;
}
static void F_353 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_634 = F_254 ( V_2 -> V_57 ) ;
int V_50 ;
if ( ! V_634 )
V_634 = 1 ;
for ( V_50 = 0 ; V_50 < V_634 ; V_50 ++ ) {
V_14 -> V_127 . V_635 [ V_50 ] = F_343 ( V_2 , V_50 ) ;
V_14 -> V_127 . V_636 [ V_50 ] = F_350 ( V_2 , V_50 ) ;
if ( V_14 -> V_127 . V_636 [ V_50 ] > V_14 -> V_127 . V_635 [ V_50 ] )
V_14 -> V_127 . V_636 [ V_50 ] = 0 ;
}
for (; V_50 < V_637 ; V_50 ++ )
V_14 -> V_127 . V_635 [ V_50 ] = 0 ;
}
static void F_354 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_638 ;
T_4 V_136 = F_254 ( V_2 -> V_57 ) ;
if ( V_2 -> V_141 & V_375 ||
V_2 -> V_141 & V_639 )
V_638 = 32 << V_2 -> V_640 ;
else
V_638 = 0 ;
V_14 -> V_110 . V_344 . V_641 ( V_14 , V_136 , V_638 , V_642 ) ;
F_353 ( V_2 ) ;
}
static void F_355 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_643 * V_644 ;
struct V_645 * V_646 ;
F_356 ( & V_2 -> V_647 ) ;
if ( ! F_357 ( & V_2 -> V_648 ) )
F_358 ( V_14 , & V_2 -> V_649 ) ;
F_359 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_360 ( V_14 ,
& V_646 -> V_646 ,
V_646 -> V_650 ,
( V_646 -> V_651 == V_652 ) ?
V_652 :
V_2 -> V_69 [ V_646 -> V_651 ] -> V_151 ) ;
}
F_361 ( & V_2 -> V_647 ) ;
}
static void F_362 ( struct V_56 * V_75 , unsigned int V_483 ,
struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_597 ;
V_597 = F_37 ( V_14 , F_329 ( V_483 ) ) ;
V_597 |= ( V_613 | V_598 | V_599 ) ;
V_597 &= ~ V_610 ;
if ( V_75 -> V_141 & V_611 ) {
V_597 |= V_610 ;
} else {
V_597 |= V_613 ;
V_14 -> V_110 . V_344 . V_578 ( V_14 , V_75 ) ;
}
F_320 ( V_2 -> V_57 , V_483 ) ;
F_71 ( V_14 , F_329 ( V_483 ) , V_597 ) ;
}
static void F_363 ( struct V_653 * V_654 )
{
struct V_1 * V_2 = V_654 -> V_150 ;
int V_451 = V_2 -> V_655 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_483 = V_654 -> V_483 ;
T_1 V_484 = V_485 |
V_486 |
V_487 |
V_488 |
V_489 ;
if ( V_14 -> V_110 . type == V_111 )
return;
if ( V_451 > 3 )
V_484 |= 2 << 29 ;
else if ( V_451 > 1 )
V_484 |= 1 << 29 ;
F_71 ( V_14 , F_280 ( F_281 ( V_483 ) ) , V_484 ) ;
}
static void F_364 ( struct V_59 * V_69 )
{
struct V_196 * V_75 = V_69 -> V_75 ;
unsigned long V_284 ;
T_2 V_50 ;
if ( ! V_69 -> V_73 )
return;
for ( V_50 = 0 ; V_50 < V_69 -> V_90 ; V_50 ++ ) {
struct V_72 * V_283 = & V_69 -> V_73 [ V_50 ] ;
if ( V_283 -> V_91 ) {
struct V_201 * V_91 = V_283 -> V_91 ;
if ( F_151 ( V_91 ) -> V_277 )
F_80 ( V_75 ,
F_151 ( V_91 ) -> V_83 ,
F_69 ( V_69 ) ,
V_241 ) ;
F_365 ( V_91 ) ;
V_283 -> V_91 = NULL ;
}
if ( ! V_283 -> V_100 )
continue;
F_80 ( V_75 , V_283 -> V_83 ,
F_140 ( V_69 ) , V_241 ) ;
F_142 ( V_283 -> V_100 , F_138 ( V_69 ) ) ;
V_283 -> V_100 = NULL ;
}
V_284 = sizeof( struct V_72 ) * V_69 -> V_90 ;
memset ( V_69 -> V_73 , 0 , V_284 ) ;
memset ( V_69 -> V_89 , 0 , V_69 -> V_284 ) ;
V_69 -> V_245 = 0 ;
V_69 -> V_81 = 0 ;
V_69 -> V_82 = 0 ;
}
static void F_366 ( struct V_653 * V_654 ,
struct V_59 * V_69 )
{
struct V_1 * V_2 = V_654 -> V_150 ;
int V_109 = V_69 -> V_88 + V_654 -> V_656 ;
F_275 ( V_2 , V_69 ) ;
F_252 ( 10000 , 20000 ) ;
F_219 ( V_2 , ( ( T_6 ) 1 << V_109 ) ) ;
F_364 ( V_69 ) ;
V_69 -> V_149 = NULL ;
}
static int F_367 ( struct V_56 * V_657 ,
struct V_653 * V_658 )
{
struct V_1 * V_2 = V_658 -> V_150 ;
unsigned int V_659 = V_658 -> V_656 ;
unsigned int V_660 = V_658 -> V_661 ;
int V_50 ;
F_368 ( V_657 ) ;
for ( V_50 = 0 ; V_50 < V_2 -> V_655 ; V_50 ++ ) {
F_366 ( V_658 , V_2 -> V_69 [ V_659 + V_50 ] ) ;
V_2 -> V_69 [ V_659 + V_50 ] -> V_57 = V_2 -> V_57 ;
}
for ( V_50 = 0 ; V_50 < V_2 -> V_655 ; V_50 ++ ) {
V_2 -> V_60 [ V_660 + V_50 ] -> V_149 = NULL ;
V_2 -> V_60 [ V_660 + V_50 ] -> V_57 = V_2 -> V_57 ;
}
return 0 ;
}
static int F_369 ( struct V_56 * V_657 ,
struct V_653 * V_658 )
{
struct V_1 * V_2 = V_658 -> V_150 ;
unsigned int V_659 , V_660 , V_369 ;
int V_50 , V_662 , V_17 = 0 ;
if ( ! F_14 ( V_658 -> V_483 , & V_2 -> V_663 ) )
return 0 ;
V_662 = V_658 -> V_483 * V_2 -> V_655 ;
F_370 ( V_657 , L_90 ,
V_658 -> V_483 , V_2 -> V_664 ,
V_662 , V_662 + V_2 -> V_655 ,
V_2 -> V_663 ) ;
V_658 -> V_57 = V_657 ;
V_658 -> V_656 = V_659 = V_662 ;
V_658 -> V_661 = V_660 = V_662 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_655 ; V_50 ++ )
F_366 ( V_658 , V_2 -> V_69 [ V_659 + V_50 ] ) ;
for ( V_50 = 0 ; V_50 < V_2 -> V_655 ; V_50 ++ ) {
V_2 -> V_69 [ V_659 + V_50 ] -> V_57 = V_657 ;
V_2 -> V_69 [ V_659 + V_50 ] -> V_149 = V_658 ;
F_277 ( V_2 , V_2 -> V_69 [ V_659 + V_50 ] ) ;
}
for ( V_50 = 0 ; V_50 < V_2 -> V_655 ; V_50 ++ ) {
V_2 -> V_60 [ V_660 + V_50 ] -> V_57 = V_657 ;
V_2 -> V_60 [ V_660 + V_50 ] -> V_149 = V_658 ;
}
V_369 = F_325 (unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues) ;
V_17 = F_371 ( V_657 , V_369 ) ;
if ( V_17 )
goto V_665;
V_17 = F_372 ( V_657 , V_369 ) ;
if ( V_17 )
goto V_665;
if ( F_373 ( V_657 -> V_666 ) )
F_315 ( V_2 , V_657 -> V_666 , V_658 -> V_483 ) ;
F_363 ( V_658 ) ;
F_362 ( V_657 , V_658 -> V_483 , V_2 ) ;
return V_17 ;
V_665:
F_367 ( V_657 , V_658 ) ;
return V_17 ;
}
static void F_374 ( struct V_1 * V_2 )
{
struct V_56 * V_97 ;
struct V_667 * V_668 ;
int V_17 ;
F_375 (adapter->netdev, upper, iter) {
if ( F_376 ( V_97 ) ) {
struct V_669 * V_670 = F_89 ( V_97 ) ;
struct V_653 * V_654 = V_670 -> V_671 ;
if ( V_670 -> V_671 ) {
V_17 = F_369 ( V_97 , V_654 ) ;
if ( V_17 )
continue;
}
}
}
}
static void F_377 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
F_354 ( V_2 ) ;
#ifdef F_378
F_337 ( V_2 ) ;
#endif
F_282 ( V_2 ) ;
F_327 ( V_2 -> V_57 ) ;
F_305 ( V_2 ) ;
switch ( V_14 -> V_110 . type ) {
case V_113 :
case V_114 :
V_14 -> V_110 . V_344 . V_672 ( V_14 ) ;
break;
default:
break;
}
if ( V_2 -> V_141 & V_375 ) {
F_379 ( & V_2 -> V_14 ,
V_2 -> V_640 ) ;
} else if ( V_2 -> V_141 & V_639 ) {
F_380 ( & V_2 -> V_14 ,
V_2 -> V_640 ) ;
F_355 ( V_2 ) ;
}
switch ( V_14 -> V_110 . type ) {
case V_113 :
case V_114 :
V_14 -> V_110 . V_344 . V_673 ( V_14 ) ;
break;
default:
break;
}
#ifdef F_232
if ( V_2 -> V_141 & V_198 )
F_123 ( V_2 ) ;
#endif
#ifdef F_176
F_381 ( V_2 ) ;
#endif
F_255 ( V_2 ) ;
F_292 ( V_2 ) ;
F_374 ( V_2 ) ;
}
static void F_382 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_110 . type == V_111 )
V_2 -> V_156 |= V_674 ;
V_2 -> V_156 |= V_360 ;
V_2 -> V_361 = 0 ;
}
static int F_383 ( struct V_15 * V_14 )
{
T_1 V_20 ;
bool V_675 , V_346 = false ;
int V_595 = V_676 ;
if ( V_14 -> V_110 . V_344 . V_345 )
V_595 = V_14 -> V_110 . V_344 . V_345 ( V_14 , & V_20 , & V_346 , false ) ;
if ( V_595 )
return V_595 ;
V_20 = V_14 -> V_347 . V_677 ;
if ( ( ! V_20 ) && ( V_14 -> V_110 . V_344 . V_678 ) )
V_595 = V_14 -> V_110 . V_344 . V_678 ( V_14 , & V_20 ,
& V_675 ) ;
if ( V_595 )
return V_595 ;
if ( V_14 -> V_110 . V_344 . V_679 )
V_595 = V_14 -> V_110 . V_344 . V_679 ( V_14 , V_20 , V_346 ) ;
return V_595 ;
}
static void F_384 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_680 = 0 ;
if ( V_2 -> V_141 & V_401 ) {
V_680 = V_681 | V_682 |
V_683 ;
V_680 |= V_684 ;
switch ( V_14 -> V_110 . type ) {
case V_111 :
F_71 ( V_14 , V_685 , V_686 ) ;
break;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
default:
F_71 ( V_14 , F_385 ( 0 ) , 0xFFFFFFFF ) ;
F_71 ( V_14 , F_385 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_71 ( V_14 , V_685 , V_686 ) ;
}
if ( V_2 -> V_141 & V_421 ) {
V_680 &= ~ V_687 ;
switch ( V_2 -> V_426 [ V_504 ] . V_119 ) {
case V_505 :
V_680 |= V_688 ;
break;
case V_507 :
V_680 |= V_689 ;
break;
default:
V_680 |= V_690 ;
break;
}
}
if ( V_2 -> V_156 & V_339 ) {
switch ( V_2 -> V_14 . V_110 . type ) {
case V_113 :
V_680 |= V_691 ;
break;
default:
break;
}
}
if ( V_2 -> V_141 & V_351 )
V_680 |= F_386 ( V_14 ) ;
switch ( V_14 -> V_110 . type ) {
case V_113 :
V_680 |= V_692 | V_693 ;
break;
case V_116 :
V_680 |= V_694 ;
break;
default:
break;
}
F_71 ( V_14 , V_695 , V_680 ) ;
}
static void F_387 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 ;
T_1 V_102 ;
F_72 ( V_2 ) ;
F_384 ( V_2 ) ;
if ( V_2 -> V_141 & V_401 )
F_200 ( V_2 ) ;
else
F_247 ( V_2 ) ;
if ( V_14 -> V_110 . V_344 . V_696 )
V_14 -> V_110 . V_344 . V_696 ( V_14 ) ;
if ( V_14 -> V_347 . V_344 . V_697 )
V_14 -> V_347 . V_344 . V_697 ( V_14 , true ) ;
F_33 () ;
F_34 ( V_34 , & V_2 -> V_35 ) ;
F_330 ( V_2 ) ;
if ( F_212 ( V_14 ) ) {
F_382 ( V_2 ) ;
} else {
V_17 = F_383 ( V_14 ) ;
if ( V_17 )
F_103 ( V_175 , L_91 , V_17 ) ;
}
F_37 ( V_14 , V_352 ) ;
F_221 ( V_2 , true , true ) ;
if ( V_2 -> V_141 & V_351 ) {
T_1 V_698 = F_37 ( V_14 , V_699 ) ;
if ( V_698 & V_700 )
F_208 ( V_158 , L_71 ) ;
}
V_2 -> V_141 |= V_364 ;
V_2 -> V_365 = V_174 ;
F_388 ( & V_2 -> V_701 , V_174 ) ;
V_102 = F_37 ( V_14 , V_103 ) ;
V_102 |= V_702 ;
F_71 ( V_14 , V_103 , V_102 ) ;
}
void F_389 ( struct V_1 * V_2 )
{
F_390 ( F_391 () ) ;
V_2 -> V_57 -> V_76 = V_174 ;
while ( F_15 ( V_703 , & V_2 -> V_35 ) )
F_252 ( 1000 , 2000 ) ;
F_392 ( V_2 ) ;
if ( V_2 -> V_141 & V_421 )
F_393 ( 2000 ) ;
F_394 ( V_2 ) ;
F_34 ( V_703 , & V_2 -> V_35 ) ;
}
void F_394 ( struct V_1 * V_2 )
{
F_377 ( V_2 ) ;
F_387 ( V_2 ) ;
}
void F_395 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_56 * V_57 = V_2 -> V_57 ;
int V_17 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
while ( F_15 ( V_704 , & V_2 -> V_35 ) )
F_252 ( 1000 , 2000 ) ;
V_2 -> V_156 &= ~ ( V_674 |
V_360 ) ;
V_2 -> V_141 &= ~ V_362 ;
V_17 = V_14 -> V_110 . V_344 . V_705 ( V_14 ) ;
switch ( V_17 ) {
case 0 :
case V_706 :
case V_707 :
break;
case V_708 :
F_18 ( L_92 ) ;
break;
case V_709 :
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
F_34 ( V_704 , & V_2 -> V_35 ) ;
F_312 ( V_2 ) ;
F_396 ( V_57 , NULL ) ;
F_314 ( V_2 ) ;
if ( V_14 -> V_110 . V_710 )
V_14 -> V_110 . V_344 . V_711 ( V_14 , F_281 ( 0 ) ) ;
if ( F_14 ( V_712 , & V_2 -> V_35 ) )
F_397 ( V_2 ) ;
if ( V_14 -> V_347 . V_344 . V_697 ) {
if ( ! F_57 ( V_2 -> V_57 ) && ! V_2 -> V_713 )
V_14 -> V_347 . V_344 . V_697 ( V_14 , false ) ;
else
V_14 -> V_347 . V_344 . V_697 ( V_14 , true ) ;
}
}
static void F_398 ( struct V_59 * V_60 )
{
struct V_61 * V_80 ;
unsigned long V_284 ;
T_2 V_50 ;
if ( ! V_60 -> V_80 )
return;
for ( V_50 = 0 ; V_50 < V_60 -> V_90 ; V_50 ++ ) {
V_80 = & V_60 -> V_80 [ V_50 ] ;
F_77 ( V_60 , V_80 ) ;
}
F_399 ( F_107 ( V_60 ) ) ;
V_284 = sizeof( struct V_61 ) * V_60 -> V_90 ;
memset ( V_60 -> V_80 , 0 , V_284 ) ;
memset ( V_60 -> V_89 , 0 , V_60 -> V_284 ) ;
V_60 -> V_82 = 0 ;
V_60 -> V_81 = 0 ;
}
static void F_400 ( struct V_1 * V_2 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_95 ; V_50 ++ )
F_364 ( V_2 -> V_69 [ V_50 ] ) ;
}
static void F_401 ( struct V_1 * V_2 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_79 ; V_50 ++ )
F_398 ( V_2 -> V_60 [ V_50 ] ) ;
}
static void F_402 ( struct V_1 * V_2 )
{
struct V_643 * V_644 ;
struct V_645 * V_646 ;
F_356 ( & V_2 -> V_647 ) ;
F_359 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_403 ( & V_646 -> V_714 ) ;
F_241 ( V_646 ) ;
}
V_2 -> V_715 = 0 ;
F_361 ( & V_2 -> V_647 ) ;
}
void F_392 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = V_2 -> V_57 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_56 * V_97 ;
struct V_667 * V_668 ;
int V_50 ;
if ( F_15 ( V_34 , & V_2 -> V_35 ) )
return;
V_14 -> V_110 . V_344 . V_547 ( V_14 ) ;
for ( V_50 = 0 ; V_50 < V_2 -> V_95 ; V_50 ++ )
F_275 ( V_2 , V_2 -> V_69 [ V_50 ] ) ;
F_252 ( 10000 , 20000 ) ;
F_368 ( V_57 ) ;
F_404 ( V_57 ) ;
F_405 ( V_57 ) ;
F_375 (adapter->netdev, upper, iter) {
if ( F_376 ( V_97 ) ) {
struct V_669 * V_257 = F_89 ( V_97 ) ;
if ( V_257 -> V_671 ) {
F_368 ( V_97 ) ;
F_404 ( V_97 ) ;
F_405 ( V_97 ) ;
}
}
}
F_245 ( V_2 ) ;
F_333 ( V_2 ) ;
V_2 -> V_156 &= ~ ( V_376 |
V_157 ) ;
V_2 -> V_141 &= ~ V_364 ;
F_406 ( & V_2 -> V_701 ) ;
if ( V_2 -> V_311 ) {
F_71 ( & V_2 -> V_14 , V_313 , 0 ) ;
for ( V_50 = 0 ; V_50 < V_2 -> V_311 ; V_50 ++ )
V_2 -> V_519 [ V_50 ] . V_716 = false ;
F_407 ( V_2 ) ;
F_408 ( V_2 ) ;
}
for ( V_50 = 0 ; V_50 < V_2 -> V_79 ; V_50 ++ ) {
T_4 V_151 = V_2 -> V_60 [ V_50 ] -> V_151 ;
F_71 ( V_14 , F_50 ( V_151 ) , V_717 ) ;
}
switch ( V_14 -> V_110 . type ) {
case V_113 :
case V_114 :
case V_115 :
case V_116 :
F_71 ( V_14 , V_437 ,
( F_37 ( V_14 , V_437 ) &
~ V_438 ) ) ;
break;
default:
break;
}
if ( ! F_409 ( V_2 -> V_9 ) )
F_395 ( V_2 ) ;
if ( V_14 -> V_110 . V_344 . V_718 )
V_14 -> V_110 . V_344 . V_718 ( V_14 ) ;
F_401 ( V_2 ) ;
F_400 ( V_2 ) ;
}
static void F_410 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
F_92 ( V_2 ) ;
}
static int F_411 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_211 , V_719 ;
T_1 V_720 ;
#ifdef F_378
int V_51 ;
struct V_721 * V_136 ;
#endif
V_14 -> V_722 = V_9 -> V_723 ;
V_14 -> V_21 = V_9 -> V_196 ;
V_14 -> V_724 = V_9 -> V_725 ;
V_14 -> V_726 = V_9 -> V_727 ;
V_14 -> V_728 = V_9 -> V_729 ;
V_211 = F_325 ( int , F_412 ( V_2 ) , F_413 () ) ;
V_2 -> V_426 [ V_427 ] . V_730 = V_211 ;
V_2 -> V_156 |= V_731 ;
V_2 -> V_732 = V_733 ;
V_2 -> V_411 = 20 ;
V_719 = F_325 ( int , V_734 , F_413 () ) ;
V_2 -> V_426 [ V_735 ] . V_730 = V_719 ;
V_2 -> V_640 = V_736 ;
#ifdef F_232
V_2 -> V_141 |= V_198 ;
#endif
#ifdef F_176
V_2 -> V_141 |= V_737 ;
V_2 -> V_141 &= ~ V_527 ;
#ifdef F_378
V_2 -> V_632 . V_633 = V_738 ;
#endif
#endif
V_2 -> V_739 [ 0 ] = V_740 ;
V_2 -> V_581 = F_414 ( sizeof( struct V_580 ) *
V_14 -> V_110 . V_582 ,
V_741 ) ;
if ( ! V_2 -> V_581 )
return - V_579 ;
switch ( V_14 -> V_110 . type ) {
case V_111 :
V_2 -> V_156 &= ~ V_731 ;
if ( V_14 -> V_21 == V_742 )
V_2 -> V_141 |= V_351 ;
V_2 -> V_732 = V_743 ;
V_2 -> V_426 [ V_735 ] . V_730 = 0 ;
V_2 -> V_411 = 0 ;
V_2 -> V_640 = 0 ;
#ifdef F_176
V_2 -> V_141 &= ~ V_737 ;
V_2 -> V_141 &= ~ V_527 ;
#ifdef F_378
V_2 -> V_632 . V_633 = 0 ;
#endif
#endif
break;
case V_113 :
if ( V_14 -> V_21 == V_341 )
V_2 -> V_156 |= V_339 ;
break;
case V_114 :
V_720 = F_37 ( V_14 , F_415 ( V_14 ) ) ;
if ( V_720 & V_744 )
V_2 -> V_156 |= V_339 ;
break;
case V_116 :
case V_115 :
#ifdef F_232
V_2 -> V_141 &= ~ V_198 ;
#endif
#ifdef F_416
V_2 -> V_141 |= V_745 ;
#endif
break;
default:
break;
}
#ifdef F_176
F_417 ( & V_2 -> V_632 . V_746 ) ;
#endif
F_417 ( & V_2 -> V_647 ) ;
#ifdef F_378
switch ( V_14 -> V_110 . type ) {
case V_114 :
case V_115 :
case V_116 :
V_2 -> V_138 . V_747 . V_748 = V_749 ;
V_2 -> V_138 . V_747 . V_750 = V_749 ;
break;
default:
V_2 -> V_138 . V_747 . V_748 = V_637 ;
V_2 -> V_138 . V_747 . V_750 = V_637 ;
break;
}
for ( V_51 = 0 ; V_51 < V_637 ; V_51 ++ ) {
V_136 = & V_2 -> V_138 . V_751 [ V_51 ] ;
V_136 -> V_752 [ V_620 ] . V_753 = 0 ;
V_136 -> V_752 [ V_620 ] . V_754 = 12 + ( V_51 & 1 ) ;
V_136 -> V_752 [ V_621 ] . V_753 = 0 ;
V_136 -> V_752 [ V_621 ] . V_754 = 12 + ( V_51 & 1 ) ;
V_136 -> V_755 = V_756 ;
}
V_136 = & V_2 -> V_138 . V_751 [ 0 ] ;
V_136 -> V_752 [ V_620 ] . V_757 = 0xFF ;
V_136 -> V_752 [ V_621 ] . V_757 = 0xFF ;
V_2 -> V_138 . V_758 [ V_620 ] [ 0 ] = 100 ;
V_2 -> V_138 . V_758 [ V_621 ] [ 0 ] = 100 ;
V_2 -> V_138 . V_139 = false ;
V_2 -> V_759 = 0x00 ;
V_2 -> V_618 = V_760 | V_619 ;
memcpy ( & V_2 -> V_761 , & V_2 -> V_138 ,
sizeof( V_2 -> V_761 ) ) ;
#endif
V_14 -> V_127 . V_762 = V_129 ;
V_14 -> V_127 . V_128 = V_129 ;
F_353 ( V_2 ) ;
V_14 -> V_127 . V_763 = V_764 ;
V_14 -> V_127 . V_765 = true ;
V_14 -> V_127 . V_766 = F_418 ( V_14 ) ;
#ifdef F_307
if ( V_767 > 0 )
F_11 ( L_100 ) ;
if ( V_14 -> V_110 . type != V_111 ) {
if ( V_767 > V_768 ) {
V_2 -> V_311 = 0 ;
F_11 ( L_101 ) ;
} else {
V_2 -> V_311 = V_767 ;
}
}
#endif
V_2 -> V_392 = 1 ;
V_2 -> V_769 = 1 ;
V_2 -> V_770 = V_771 ;
V_2 -> V_772 = V_773 ;
V_2 -> V_774 = V_775 ;
if ( F_419 ( V_14 ) ) {
F_18 ( L_102 ) ;
return - V_776 ;
}
F_250 ( 0 , & V_2 -> V_663 ) ;
F_250 ( V_34 , & V_2 -> V_35 ) ;
return 0 ;
}
int F_420 ( struct V_59 * V_60 )
{
struct V_196 * V_75 = V_60 -> V_75 ;
int V_777 = F_421 ( V_75 ) ;
int V_778 = - 1 ;
int V_284 ;
V_284 = sizeof( struct V_61 ) * V_60 -> V_90 ;
if ( V_60 -> V_160 )
V_778 = V_60 -> V_160 -> V_779 ;
V_60 -> V_80 = F_422 ( V_284 , V_778 ) ;
if ( ! V_60 -> V_80 )
V_60 -> V_80 = F_423 ( V_284 ) ;
if ( ! V_60 -> V_80 )
goto V_17;
F_424 ( & V_60 -> V_172 ) ;
V_60 -> V_284 = V_60 -> V_90 * sizeof( union V_63 ) ;
V_60 -> V_284 = F_170 ( V_60 -> V_284 , 4096 ) ;
F_425 ( V_75 , V_778 ) ;
V_60 -> V_89 = F_426 ( V_75 ,
V_60 -> V_284 ,
& V_60 -> V_83 ,
V_780 ) ;
F_425 ( V_75 , V_777 ) ;
if ( ! V_60 -> V_89 )
V_60 -> V_89 = F_426 ( V_75 , V_60 -> V_284 ,
& V_60 -> V_83 , V_780 ) ;
if ( ! V_60 -> V_89 )
goto V_17;
V_60 -> V_82 = 0 ;
V_60 -> V_81 = 0 ;
return 0 ;
V_17:
F_427 ( V_60 -> V_80 ) ;
V_60 -> V_80 = NULL ;
F_428 ( V_75 , L_103 ) ;
return - V_579 ;
}
static int F_429 ( struct V_1 * V_2 )
{
int V_50 , V_17 = 0 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_79 ; V_50 ++ ) {
V_17 = F_420 ( V_2 -> V_60 [ V_50 ] ) ;
if ( ! V_17 )
continue;
F_103 ( V_175 , L_104 , V_50 ) ;
goto V_781;
}
return 0 ;
V_781:
while ( V_50 -- )
F_430 ( V_2 -> V_60 [ V_50 ] ) ;
return V_17 ;
}
int F_431 ( struct V_59 * V_69 )
{
struct V_196 * V_75 = V_69 -> V_75 ;
int V_777 = F_421 ( V_75 ) ;
int V_778 = - 1 ;
int V_284 ;
V_284 = sizeof( struct V_72 ) * V_69 -> V_90 ;
if ( V_69 -> V_160 )
V_778 = V_69 -> V_160 -> V_779 ;
V_69 -> V_73 = F_422 ( V_284 , V_778 ) ;
if ( ! V_69 -> V_73 )
V_69 -> V_73 = F_423 ( V_284 ) ;
if ( ! V_69 -> V_73 )
goto V_17;
F_424 ( & V_69 -> V_172 ) ;
V_69 -> V_284 = V_69 -> V_90 * sizeof( union V_70 ) ;
V_69 -> V_284 = F_170 ( V_69 -> V_284 , 4096 ) ;
F_425 ( V_75 , V_778 ) ;
V_69 -> V_89 = F_426 ( V_75 ,
V_69 -> V_284 ,
& V_69 -> V_83 ,
V_780 ) ;
F_425 ( V_75 , V_777 ) ;
if ( ! V_69 -> V_89 )
V_69 -> V_89 = F_426 ( V_75 , V_69 -> V_284 ,
& V_69 -> V_83 , V_780 ) ;
if ( ! V_69 -> V_89 )
goto V_17;
V_69 -> V_81 = 0 ;
V_69 -> V_82 = 0 ;
return 0 ;
V_17:
F_427 ( V_69 -> V_73 ) ;
V_69 -> V_73 = NULL ;
F_428 ( V_75 , L_105 ) ;
return - V_579 ;
}
static int F_432 ( struct V_1 * V_2 )
{
int V_50 , V_17 = 0 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_95 ; V_50 ++ ) {
V_17 = F_431 ( V_2 -> V_69 [ V_50 ] ) ;
if ( ! V_17 )
continue;
F_103 ( V_175 , L_106 , V_50 ) ;
goto V_782;
}
#ifdef F_176
V_17 = F_433 ( V_2 ) ;
if ( ! V_17 )
#endif
return 0 ;
V_782:
while ( V_50 -- )
F_434 ( V_2 -> V_69 [ V_50 ] ) ;
return V_17 ;
}
void F_430 ( struct V_59 * V_60 )
{
F_398 ( V_60 ) ;
F_427 ( V_60 -> V_80 ) ;
V_60 -> V_80 = NULL ;
if ( ! V_60 -> V_89 )
return;
F_435 ( V_60 -> V_75 , V_60 -> V_284 ,
V_60 -> V_89 , V_60 -> V_83 ) ;
V_60 -> V_89 = NULL ;
}
static void F_436 ( struct V_1 * V_2 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_79 ; V_50 ++ )
if ( V_2 -> V_60 [ V_50 ] -> V_89 )
F_430 ( V_2 -> V_60 [ V_50 ] ) ;
}
void F_434 ( struct V_59 * V_69 )
{
F_364 ( V_69 ) ;
F_427 ( V_69 -> V_73 ) ;
V_69 -> V_73 = NULL ;
if ( ! V_69 -> V_89 )
return;
F_435 ( V_69 -> V_75 , V_69 -> V_284 ,
V_69 -> V_89 , V_69 -> V_83 ) ;
V_69 -> V_89 = NULL ;
}
static void F_437 ( struct V_1 * V_2 )
{
int V_50 ;
#ifdef F_176
F_438 ( V_2 ) ;
#endif
for ( V_50 = 0 ; V_50 < V_2 -> V_95 ; V_50 ++ )
if ( V_2 -> V_69 [ V_50 ] -> V_89 )
F_434 ( V_2 -> V_69 [ V_50 ] ) ;
}
static int F_439 ( struct V_56 * V_57 , int V_783 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
int V_522 = V_783 + V_523 + V_524 ;
if ( ( V_783 < 68 ) || ( V_522 > V_784 ) )
return - V_591 ;
if ( ( V_2 -> V_141 & V_421 ) &&
( V_2 -> V_14 . V_110 . type == V_113 ) &&
( V_522 > ( V_529 + V_524 ) ) )
F_93 ( V_175 , L_107 ) ;
F_105 ( V_175 , L_108 , V_57 -> V_299 , V_783 ) ;
V_57 -> V_299 = V_783 ;
if ( F_57 ( V_57 ) )
F_389 ( V_2 ) ;
return 0 ;
}
int F_440 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 , V_369 ;
if ( F_14 ( V_785 , & V_2 -> V_35 ) )
return - V_786 ;
F_404 ( V_57 ) ;
V_17 = F_429 ( V_2 ) ;
if ( V_17 )
goto V_781;
V_17 = F_432 ( V_2 ) ;
if ( V_17 )
goto V_782;
F_377 ( V_2 ) ;
V_17 = F_243 ( V_2 ) ;
if ( V_17 )
goto V_787;
if ( V_2 -> V_664 > 1 )
V_369 = V_2 -> V_655 ;
else
V_369 = V_2 -> V_79 ;
V_17 = F_371 ( V_57 , V_369 ) ;
if ( V_17 )
goto V_788;
if ( V_2 -> V_664 > 1 &&
V_2 -> V_95 > V_789 )
V_369 = V_789 ;
else
V_369 = V_2 -> V_95 ;
V_17 = F_372 ( V_57 , V_369 ) ;
if ( V_17 )
goto V_788;
F_441 ( V_2 ) ;
F_387 ( V_2 ) ;
F_336 ( V_2 ) ;
#ifdef F_416
F_442 ( V_57 ) ;
#endif
return 0 ;
V_788:
F_244 ( V_2 ) ;
V_787:
F_437 ( V_2 ) ;
if ( V_14 -> V_347 . V_344 . V_697 && ! V_2 -> V_713 )
V_14 -> V_347 . V_344 . V_697 ( & V_2 -> V_14 , false ) ;
V_782:
F_436 ( V_2 ) ;
V_781:
F_395 ( V_2 ) ;
return V_17 ;
}
static void F_443 ( struct V_1 * V_2 )
{
F_444 ( V_2 ) ;
if ( V_2 -> V_14 . V_347 . V_344 . V_790 ) {
V_2 -> V_14 . V_347 . V_791 = true ;
F_392 ( V_2 ) ;
V_2 -> V_14 . V_347 . V_344 . V_790 ( & V_2 -> V_14 ) ;
V_2 -> V_14 . V_347 . V_791 = false ;
} else {
F_392 ( V_2 ) ;
}
F_244 ( V_2 ) ;
F_436 ( V_2 ) ;
F_437 ( V_2 ) ;
}
int F_445 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
F_446 ( V_2 ) ;
F_443 ( V_2 ) ;
F_402 ( V_2 ) ;
F_70 ( V_2 ) ;
return 0 ;
}
static int F_447 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_448 ( V_9 ) ;
struct V_56 * V_57 = V_2 -> V_57 ;
T_1 V_17 ;
V_2 -> V_14 . V_41 = V_2 -> V_410 ;
F_449 ( V_9 , V_792 ) ;
F_450 ( V_9 ) ;
F_451 ( V_9 ) ;
V_17 = F_452 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_109 ) ;
return V_17 ;
}
F_33 () ;
F_34 ( V_793 , & V_2 -> V_35 ) ;
F_453 ( V_9 ) ;
F_454 ( V_9 , false ) ;
F_395 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_794 , ~ 0 ) ;
F_455 () ;
V_17 = F_456 ( V_2 ) ;
if ( ! V_17 && F_57 ( V_57 ) )
V_17 = F_440 ( V_57 ) ;
F_457 () ;
if ( V_17 )
return V_17 ;
F_458 ( V_57 ) ;
return 0 ;
}
static int F_459 ( struct V_5 * V_9 , bool * V_795 )
{
struct V_1 * V_2 = F_448 ( V_9 ) ;
struct V_56 * V_57 = V_2 -> V_57 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_796 , V_596 ;
T_1 V_797 = V_2 -> V_713 ;
#ifdef F_460
int V_798 = 0 ;
#endif
F_461 ( V_57 ) ;
F_455 () ;
if ( F_57 ( V_57 ) )
F_443 ( V_2 ) ;
F_457 () ;
F_462 ( V_2 ) ;
#ifdef F_460
V_798 = F_451 ( V_9 ) ;
if ( V_798 )
return V_798 ;
#endif
if ( V_14 -> V_110 . V_344 . V_799 )
V_14 -> V_110 . V_344 . V_799 ( V_14 ) ;
if ( V_797 ) {
F_327 ( V_57 ) ;
if ( V_14 -> V_110 . V_344 . V_696 )
V_14 -> V_110 . V_344 . V_696 ( V_14 ) ;
if ( V_797 & V_800 ) {
V_596 = F_37 ( V_14 , V_600 ) ;
V_596 |= V_606 ;
F_71 ( V_14 , V_600 , V_596 ) ;
}
V_796 = F_37 ( V_14 , V_801 ) ;
V_796 |= V_802 ;
F_71 ( V_14 , V_801 , V_796 ) ;
F_71 ( V_14 , V_803 , V_797 ) ;
} else {
F_71 ( V_14 , V_804 , 0 ) ;
F_71 ( V_14 , V_803 , 0 ) ;
}
switch ( V_14 -> V_110 . type ) {
case V_111 :
F_454 ( V_9 , false ) ;
break;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
F_454 ( V_9 , ! ! V_797 ) ;
break;
default:
break;
}
* V_795 = ! ! V_797 ;
if ( V_14 -> V_347 . V_344 . V_697 && ! * V_795 )
V_14 -> V_347 . V_344 . V_697 ( V_14 , false ) ;
F_70 ( V_2 ) ;
if ( ! F_15 ( V_793 , & V_2 -> V_35 ) )
F_463 ( V_9 ) ;
return 0 ;
}
static int F_464 ( struct V_5 * V_9 , T_13 V_35 )
{
int V_798 ;
bool V_805 ;
V_798 = F_459 ( V_9 , & V_805 ) ;
if ( V_798 )
return V_798 ;
if ( V_805 ) {
F_465 ( V_9 ) ;
} else {
F_454 ( V_9 , false ) ;
F_449 ( V_9 , V_806 ) ;
}
return 0 ;
}
static void F_466 ( struct V_5 * V_9 )
{
bool V_805 ;
F_459 ( V_9 , & V_805 ) ;
if ( V_807 == V_808 ) {
F_454 ( V_9 , V_805 ) ;
F_449 ( V_9 , V_806 ) ;
}
}
void F_467 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = V_2 -> V_57 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_124 * V_125 = & V_2 -> V_126 ;
T_6 V_809 = 0 ;
T_1 V_50 , V_810 = 0 , V_811 , V_812 , V_813 , V_814 , V_815 ;
T_6 V_269 = 0 , V_177 = 0 , V_816 = 0 ;
T_6 V_240 = 0 , V_292 = 0 ;
T_6 V_173 = 0 , V_146 = 0 , V_817 = 0 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_703 , & V_2 -> V_35 ) )
return;
if ( V_2 -> V_156 & V_535 ) {
T_6 V_251 = 0 ;
T_6 V_252 = 0 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_95 ; V_50 ++ ) {
V_251 += V_2 -> V_69 [ V_50 ] -> V_227 . V_251 ;
V_252 += V_2 -> V_69 [ V_50 ] -> V_227 . V_252 ;
}
V_2 -> V_818 = V_251 ;
V_2 -> V_819 = V_252 ;
}
for ( V_50 = 0 ; V_50 < V_2 -> V_95 ; V_50 ++ ) {
struct V_59 * V_69 = V_2 -> V_69 [ V_50 ] ;
V_269 += V_69 -> V_227 . V_269 ;
V_240 += V_69 -> V_227 . V_240 ;
V_292 += V_69 -> V_227 . V_292 ;
V_817 += V_69 -> V_227 . V_228 ;
V_173 += V_69 -> V_126 . V_173 ;
V_146 += V_69 -> V_126 . V_146 ;
}
V_2 -> V_269 = V_269 ;
V_2 -> V_240 = V_240 ;
V_2 -> V_292 = V_292 ;
V_2 -> V_817 = V_817 ;
V_57 -> V_126 . V_820 = V_173 ;
V_57 -> V_126 . V_821 = V_146 ;
V_173 = 0 ;
V_146 = 0 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_79 ; V_50 ++ ) {
struct V_59 * V_60 = V_2 -> V_60 [ V_50 ] ;
V_177 += V_60 -> V_154 . V_177 ;
V_816 += V_60 -> V_154 . V_816 ;
V_173 += V_60 -> V_126 . V_173 ;
V_146 += V_60 -> V_126 . V_146 ;
}
V_2 -> V_177 = V_177 ;
V_2 -> V_816 = V_816 ;
V_57 -> V_126 . V_822 = V_173 ;
V_57 -> V_126 . V_823 = V_146 ;
V_125 -> V_824 += F_37 ( V_14 , V_825 ) ;
for ( V_50 = 0 ; V_50 < 8 ; V_50 ++ ) {
V_811 = F_37 ( V_14 , F_468 ( V_50 ) ) ;
V_810 += V_811 ;
V_125 -> V_811 [ V_50 ] += V_811 ;
V_809 += V_125 -> V_811 [ V_50 ] ;
V_125 -> V_826 [ V_50 ] += F_37 ( V_14 , F_469 ( V_50 ) ) ;
V_125 -> V_827 [ V_50 ] += F_37 ( V_14 , F_470 ( V_50 ) ) ;
switch ( V_14 -> V_110 . type ) {
case V_111 :
V_125 -> V_828 [ V_50 ] += F_37 ( V_14 , F_471 ( V_50 ) ) ;
V_125 -> V_829 [ V_50 ] += F_37 ( V_14 , F_472 ( V_50 ) ) ;
V_125 -> V_830 [ V_50 ] += F_37 ( V_14 , F_473 ( V_50 ) ) ;
V_125 -> V_831 [ V_50 ] +=
F_37 ( V_14 , F_474 ( V_50 ) ) ;
break;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
V_125 -> V_831 [ V_50 ] +=
F_37 ( V_14 , F_475 ( V_50 ) ) ;
break;
default:
break;
}
}
for ( V_50 = 0 ; V_50 < 16 ; V_50 ++ ) {
V_125 -> V_832 [ V_50 ] += F_37 ( V_14 , F_476 ( V_50 ) ) ;
V_125 -> V_833 [ V_50 ] += F_37 ( V_14 , F_477 ( V_50 ) ) ;
if ( ( V_14 -> V_110 . type == V_113 ) ||
( V_14 -> V_110 . type == V_114 ) ||
( V_14 -> V_110 . type == V_115 ) ||
( V_14 -> V_110 . type == V_116 ) ) {
V_125 -> V_829 [ V_50 ] += F_37 ( V_14 , F_478 ( V_50 ) ) ;
F_37 ( V_14 , F_479 ( V_50 ) ) ;
V_125 -> V_830 [ V_50 ] += F_37 ( V_14 , F_480 ( V_50 ) ) ;
F_37 ( V_14 , F_481 ( V_50 ) ) ;
}
}
V_125 -> V_834 += F_37 ( V_14 , V_835 ) ;
V_125 -> V_834 -= V_810 ;
F_83 ( V_2 ) ;
switch ( V_14 -> V_110 . type ) {
case V_111 :
V_125 -> V_836 += F_37 ( V_14 , V_837 ) ;
V_125 -> V_838 += F_37 ( V_14 , V_839 ) ;
V_125 -> V_840 += F_37 ( V_14 , V_841 ) ;
V_125 -> V_842 += F_37 ( V_14 , V_843 ) ;
break;
case V_114 :
case V_115 :
case V_116 :
V_125 -> V_844 += F_37 ( V_14 , V_845 ) ;
V_125 -> V_846 += F_37 ( V_14 , V_847 ) ;
V_125 -> V_848 += F_37 ( V_14 , V_849 ) ;
V_125 -> V_850 += F_37 ( V_14 , V_851 ) ;
case V_113 :
for ( V_50 = 0 ; V_50 < 16 ; V_50 ++ )
V_2 -> V_852 +=
F_37 ( V_14 , F_482 ( V_50 ) ) ;
V_125 -> V_838 += F_37 ( V_14 , V_853 ) ;
F_37 ( V_14 , V_839 ) ;
V_125 -> V_840 += F_37 ( V_14 , V_854 ) ;
F_37 ( V_14 , V_841 ) ;
V_125 -> V_842 += F_37 ( V_14 , V_855 ) ;
F_37 ( V_14 , V_843 ) ;
V_125 -> V_836 += F_37 ( V_14 , V_856 ) ;
V_125 -> V_857 += F_37 ( V_14 , V_858 ) ;
V_125 -> V_859 += F_37 ( V_14 , V_860 ) ;
#ifdef F_176
V_125 -> V_861 += F_37 ( V_14 , V_862 ) ;
V_125 -> V_863 += F_37 ( V_14 , V_864 ) ;
V_125 -> V_865 += F_37 ( V_14 , V_866 ) ;
V_125 -> V_867 += F_37 ( V_14 , V_868 ) ;
V_125 -> V_869 += F_37 ( V_14 , V_870 ) ;
V_125 -> V_871 += F_37 ( V_14 , V_872 ) ;
if ( V_2 -> V_632 . V_873 ) {
struct V_874 * V_632 = & V_2 -> V_632 ;
struct V_875 * V_873 ;
unsigned int V_178 ;
T_6 V_876 = 0 , V_877 = 0 ;
F_483 (cpu) {
V_873 = F_484 ( V_632 -> V_873 , V_178 ) ;
V_876 += V_873 -> V_876 ;
V_877 += V_873 -> V_877 ;
}
V_125 -> V_878 = V_876 ;
V_125 -> V_879 = V_877 ;
}
#endif
break;
default:
break;
}
V_812 = F_37 ( V_14 , V_880 ) ;
V_125 -> V_812 += V_812 ;
V_125 -> V_881 += F_37 ( V_14 , V_882 ) ;
if ( V_14 -> V_110 . type == V_111 )
V_125 -> V_881 -= V_812 ;
V_125 -> V_883 += F_37 ( V_14 , V_884 ) ;
V_125 -> V_885 += F_37 ( V_14 , V_886 ) ;
V_125 -> V_887 += F_37 ( V_14 , V_888 ) ;
V_125 -> V_889 += F_37 ( V_14 , V_890 ) ;
V_125 -> V_891 += F_37 ( V_14 , V_892 ) ;
V_125 -> V_893 += F_37 ( V_14 , V_894 ) ;
V_125 -> V_895 += F_37 ( V_14 , V_896 ) ;
V_125 -> V_897 += F_37 ( V_14 , V_898 ) ;
V_813 = F_37 ( V_14 , V_899 ) ;
V_125 -> V_900 += V_813 ;
V_814 = F_37 ( V_14 , V_901 ) ;
V_125 -> V_902 += V_814 ;
V_125 -> V_903 += F_37 ( V_14 , V_904 ) ;
V_125 -> V_905 += F_37 ( V_14 , V_906 ) ;
V_815 = V_813 + V_814 ;
V_125 -> V_903 -= V_815 ;
V_125 -> V_905 -= V_815 ;
V_125 -> V_840 -= ( V_815 * ( V_907 + V_524 ) ) ;
V_125 -> V_908 += F_37 ( V_14 , V_909 ) ;
V_125 -> V_910 += F_37 ( V_14 , V_911 ) ;
V_125 -> V_912 += F_37 ( V_14 , V_913 ) ;
V_125 -> V_914 += F_37 ( V_14 , V_915 ) ;
V_125 -> V_916 += F_37 ( V_14 , V_917 ) ;
V_125 -> V_916 -= V_815 ;
V_125 -> V_918 += F_37 ( V_14 , V_919 ) ;
V_125 -> V_920 += F_37 ( V_14 , V_921 ) ;
V_125 -> V_922 += F_37 ( V_14 , V_923 ) ;
V_125 -> V_924 += F_37 ( V_14 , V_925 ) ;
V_125 -> V_926 += F_37 ( V_14 , V_927 ) ;
V_125 -> V_928 += F_37 ( V_14 , V_929 ) ;
V_57 -> V_126 . V_930 = V_125 -> V_881 ;
V_57 -> V_126 . V_931 = V_125 -> V_824 + V_125 -> V_897 ;
V_57 -> V_126 . V_932 = 0 ;
V_57 -> V_126 . V_933 = V_125 -> V_897 ;
V_57 -> V_126 . V_934 = V_125 -> V_824 ;
V_57 -> V_126 . V_935 = V_809 ;
}
static void F_485 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_50 ;
if ( ! ( V_2 -> V_156 & V_376 ) )
return;
V_2 -> V_156 &= ~ V_376 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
if ( ! ( V_2 -> V_141 & V_375 ) )
return;
V_2 -> V_936 ++ ;
if ( F_486 ( V_14 ) == 0 ) {
for ( V_50 = 0 ; V_50 < V_2 -> V_79 ; V_50 ++ )
F_250 ( V_385 ,
& ( V_2 -> V_60 [ V_50 ] -> V_35 ) ) ;
F_71 ( V_14 , V_368 , V_377 ) ;
} else {
F_103 ( V_175 , L_110
L_111 ) ;
}
}
static void F_487 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_937 = 0 ;
int V_50 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_703 , & V_2 -> V_35 ) )
return;
if ( F_109 ( V_2 -> V_57 ) ) {
for ( V_50 = 0 ; V_50 < V_2 -> V_79 ; V_50 ++ )
F_488 ( V_2 -> V_60 [ V_50 ] ) ;
}
if ( ! ( V_2 -> V_141 & V_401 ) ) {
F_71 ( V_14 , V_121 ,
( V_938 | V_939 ) ) ;
} else {
for ( V_50 = 0 ; V_50 < V_2 -> V_195 ; V_50 ++ ) {
struct V_159 * V_940 = V_2 -> V_160 [ V_50 ] ;
if ( V_940 -> V_303 . V_122 || V_940 -> V_165 . V_122 )
V_937 |= ( ( T_6 ) 1 << V_50 ) ;
}
}
F_75 ( V_2 , V_937 ) ;
}
static void F_489 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_941 = V_2 -> V_941 ;
bool V_346 = V_2 -> V_346 ;
bool V_137 = V_2 -> V_138 . V_139 ;
if ( ! ( V_2 -> V_141 & V_364 ) )
return;
if ( V_14 -> V_110 . V_344 . V_345 ) {
V_14 -> V_110 . V_344 . V_345 ( V_14 , & V_941 , & V_346 , false ) ;
} else {
V_941 = V_942 ;
V_346 = true ;
}
if ( V_2 -> V_140 )
V_137 |= ! ! ( V_2 -> V_140 -> V_137 ) ;
if ( V_346 && ! ( ( V_2 -> V_141 & V_142 ) && V_137 ) ) {
V_14 -> V_110 . V_344 . V_943 ( V_14 ) ;
F_490 ( V_2 ) ;
}
if ( V_346 ||
F_491 ( V_174 , ( V_2 -> V_365 +
V_944 ) ) ) {
V_2 -> V_141 &= ~ V_364 ;
F_71 ( V_14 , V_368 , V_367 ) ;
F_216 ( V_14 ) ;
}
V_2 -> V_346 = V_346 ;
V_2 -> V_941 = V_941 ;
}
static void F_492 ( struct V_1 * V_2 )
{
#ifdef F_378
struct V_56 * V_57 = V_2 -> V_57 ;
struct V_945 V_946 = {
. V_947 = V_948 ,
. V_259 = 0 ,
} ;
T_4 V_633 = 0 ;
if ( V_2 -> V_618 & V_949 )
V_633 = F_493 ( V_57 , & V_946 ) ;
V_2 -> V_950 = ( V_633 > 1 ) ? ( F_494 ( V_633 ) - 1 ) : 0 ;
#endif
}
static void F_495 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = V_2 -> V_57 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_56 * V_97 ;
struct V_667 * V_668 ;
T_1 V_941 = V_2 -> V_941 ;
const char * V_951 ;
bool V_952 , V_953 ;
if ( F_109 ( V_57 ) )
return;
V_2 -> V_156 &= ~ V_674 ;
switch ( V_14 -> V_110 . type ) {
case V_111 : {
T_1 V_954 = F_37 ( V_14 , V_600 ) ;
T_1 V_955 = F_37 ( V_14 , V_956 ) ;
V_952 = ! ! ( V_954 & V_957 ) ;
V_953 = ! ! ( V_955 & V_958 ) ;
}
break;
case V_114 :
case V_115 :
case V_116 :
case V_113 : {
T_1 V_959 = F_37 ( V_14 , V_960 ) ;
T_1 V_961 = F_37 ( V_14 , V_962 ) ;
V_952 = ! ! ( V_959 & V_963 ) ;
V_953 = ! ! ( V_961 & V_964 ) ;
}
break;
default:
V_953 = false ;
V_952 = false ;
break;
}
V_2 -> V_965 = V_174 ;
if ( F_14 ( V_712 , & V_2 -> V_35 ) )
F_496 ( V_2 ) ;
switch ( V_941 ) {
case V_942 :
V_951 = L_112 ;
break;
case V_966 :
V_951 = L_113 ;
break;
case V_967 :
V_951 = L_114 ;
break;
case V_968 :
V_951 = L_115 ;
break;
default:
V_951 = L_116 ;
break;
}
F_105 ( V_158 , L_117 , V_951 ,
( ( V_952 && V_953 ) ? L_118 :
( V_952 ? L_119 :
( V_953 ? L_120 : L_121 ) ) ) ) ;
F_497 ( V_57 ) ;
F_498 ( V_2 ) ;
F_499 ( V_2 -> V_57 ) ;
F_455 () ;
F_375 (adapter->netdev, upper, iter) {
if ( F_376 ( V_97 ) ) {
struct V_669 * V_257 = F_89 ( V_97 ) ;
if ( V_257 -> V_671 )
F_499 ( V_97 ) ;
}
}
F_457 () ;
F_492 ( V_2 ) ;
F_407 ( V_2 ) ;
}
static void F_500 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = V_2 -> V_57 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_346 = false ;
V_2 -> V_941 = 0 ;
if ( ! F_109 ( V_57 ) )
return;
if ( F_212 ( V_14 ) && V_14 -> V_110 . type == V_111 )
V_2 -> V_156 |= V_674 ;
if ( F_14 ( V_712 , & V_2 -> V_35 ) )
F_496 ( V_2 ) ;
F_105 ( V_158 , L_122 ) ;
F_404 ( V_57 ) ;
F_407 ( V_2 ) ;
}
static bool F_501 ( struct V_1 * V_2 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_79 ; V_50 ++ ) {
struct V_59 * V_60 = V_2 -> V_60 [ V_50 ] ;
if ( V_60 -> V_82 != V_60 -> V_81 )
return true ;
}
return false ;
}
static bool F_502 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_969 * V_970 = & V_2 -> V_426 [ V_504 ] ;
T_1 V_971 = F_503 ( 1 , ~ V_970 -> V_119 ) ;
int V_50 , V_51 ;
if ( ! V_2 -> V_311 )
return false ;
if ( V_14 -> V_110 . type >= V_115 )
return false ;
for ( V_50 = 0 ; V_50 < V_2 -> V_311 ; V_50 ++ ) {
for ( V_51 = 0 ; V_51 < V_971 ; V_51 ++ ) {
T_1 V_972 , V_973 ;
V_972 = F_37 ( V_14 , F_504 ( V_971 , V_50 , V_51 ) ) ;
V_973 = F_37 ( V_14 , F_505 ( V_971 , V_50 , V_51 ) ) ;
if ( V_972 != V_973 )
return true ;
}
}
return false ;
}
static void F_506 ( struct V_1 * V_2 )
{
if ( ! F_109 ( V_2 -> V_57 ) ) {
if ( F_501 ( V_2 ) ||
F_502 ( V_2 ) ) {
F_93 ( V_158 , L_123 ) ;
V_2 -> V_156 |= V_157 ;
}
}
}
static inline void F_507 ( struct V_1 * V_2 ,
struct V_5 * V_974 )
{
if ( ! F_508 ( V_974 ) )
F_11 ( L_124 ) ;
F_18 ( L_125 , F_509 ( V_974 ) ) ;
F_510 ( V_974 , V_975 , V_976 ) ;
F_393 ( 100 ) ;
}
static void F_511 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_977 ;
T_1 V_978 ;
if ( ! ( F_109 ( V_2 -> V_57 ) ) )
return;
V_978 = F_37 ( V_14 , V_979 ) ;
if ( V_978 )
return;
if ( ! V_9 )
return;
for ( V_977 = 0 ; V_977 < V_2 -> V_311 ; ++ V_977 ) {
struct V_5 * V_974 = V_2 -> V_519 [ V_977 ] . V_974 ;
T_2 V_980 ;
if ( ! V_974 )
continue;
F_25 ( V_974 , V_981 , & V_980 ) ;
if ( V_980 != V_13 &&
V_980 & V_982 )
F_507 ( V_2 , V_974 ) ;
}
}
static void F_512 ( struct V_1 * V_2 )
{
T_1 V_983 ;
if ( V_2 -> V_14 . V_110 . type == V_111 ||
V_2 -> V_311 == 0 )
return;
V_983 = F_37 ( & V_2 -> V_14 , V_984 ) ;
if ( ! V_983 )
return;
F_93 ( V_158 , L_126 , V_983 ) ;
}
static void F_512 ( struct V_1 T_14 * V_2 )
{
}
static void
F_511 ( struct V_1 T_14 * V_2 )
{
}
static void F_513 ( struct V_1 * V_2 )
{
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_703 , & V_2 -> V_35 ) )
return;
F_489 ( V_2 ) ;
if ( V_2 -> V_346 )
F_495 ( V_2 ) ;
else
F_500 ( V_2 ) ;
F_511 ( V_2 ) ;
F_512 ( V_2 ) ;
F_467 ( V_2 ) ;
F_506 ( V_2 ) ;
}
static void F_514 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_3 V_17 ;
if ( ! ( V_2 -> V_156 & V_674 ) &&
! ( V_2 -> V_156 & V_360 ) )
return;
if ( V_2 -> V_361 &&
F_491 ( V_2 -> V_361 , V_174 ) )
return;
if ( F_15 ( V_704 , & V_2 -> V_35 ) )
return;
V_2 -> V_361 = V_174 + V_985 - 1 ;
V_17 = V_14 -> V_347 . V_344 . V_986 ( V_14 ) ;
if ( V_17 == V_707 )
goto V_987;
if ( V_17 == V_706 ) {
V_2 -> V_156 |= V_360 ;
}
if ( V_17 )
goto V_987;
if ( ! ( V_2 -> V_156 & V_360 ) )
goto V_987;
V_2 -> V_156 &= ~ V_360 ;
if ( V_14 -> V_110 . type == V_111 )
V_17 = V_14 -> V_347 . V_344 . V_988 ( V_14 ) ;
else
V_17 = V_14 -> V_110 . V_344 . V_989 ( V_14 ) ;
if ( V_17 == V_707 )
goto V_987;
V_2 -> V_141 |= V_362 ;
F_105 ( V_175 , L_127 , V_14 -> V_347 . V_990 ) ;
V_987:
F_34 ( V_704 , & V_2 -> V_35 ) ;
if ( ( V_17 == V_707 ) &&
( V_2 -> V_57 -> V_991 == V_992 ) ) {
F_18 ( L_128
L_129 ) ;
F_18 ( L_130
L_131 ) ;
F_515 ( V_2 -> V_57 ) ;
}
}
static void F_516 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_20 ;
bool V_675 = false ;
if ( ! ( V_2 -> V_141 & V_362 ) )
return;
if ( F_15 ( V_704 , & V_2 -> V_35 ) )
return;
V_2 -> V_141 &= ~ V_362 ;
V_20 = V_14 -> V_347 . V_677 ;
if ( ( ! V_20 ) && ( V_14 -> V_110 . V_344 . V_678 ) ) {
V_14 -> V_110 . V_344 . V_678 ( V_14 , & V_20 , & V_675 ) ;
if ( ! V_675 ) {
if ( V_20 & V_942 )
V_20 = V_942 ;
}
}
if ( V_14 -> V_110 . V_344 . V_679 )
V_14 -> V_110 . V_344 . V_679 ( V_14 , V_20 , true ) ;
V_2 -> V_141 |= V_364 ;
V_2 -> V_365 = V_174 ;
F_34 ( V_704 , & V_2 -> V_35 ) ;
}
static void F_517 ( unsigned long V_94 )
{
struct V_1 * V_2 = (struct V_1 * ) V_94 ;
unsigned long V_993 ;
if ( V_2 -> V_141 & V_364 )
V_993 = V_994 / 10 ;
else
V_993 = V_994 * 2 ;
F_388 ( & V_2 -> V_701 , V_993 + V_174 ) ;
F_13 ( V_2 ) ;
}
static void F_518 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_168 ;
if ( ! ( V_2 -> V_156 & V_380 ) )
return;
V_2 -> V_156 &= ~ V_380 ;
if ( ! V_14 -> V_347 . V_344 . V_995 )
return;
V_168 = V_14 -> V_347 . V_344 . V_995 ( & V_2 -> V_14 ) ;
if ( V_168 != V_349 )
return;
F_208 ( V_158 , L_70 , V_350 ) ;
}
static void F_519 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_156 & V_157 ) )
return;
V_2 -> V_156 &= ~ V_157 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_703 , & V_2 -> V_35 ) )
return;
F_54 ( V_2 ) ;
F_520 ( V_2 -> V_57 , L_132 ) ;
V_2 -> V_176 ++ ;
F_455 () ;
F_389 ( V_2 ) ;
F_457 () ;
}
static void F_521 ( struct V_996 * V_997 )
{
struct V_1 * V_2 = F_196 ( V_997 ,
struct V_1 ,
V_39 ) ;
if ( F_22 ( V_2 -> V_14 . V_41 ) ) {
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_455 () ;
F_392 ( V_2 ) ;
F_457 () ;
}
F_31 ( V_2 ) ;
return;
}
#ifdef F_416
if ( V_2 -> V_156 & V_998 ) {
V_2 -> V_156 &= ~ V_998 ;
F_442 ( V_2 -> V_57 ) ;
}
#endif
F_519 ( V_2 ) ;
F_518 ( V_2 ) ;
F_514 ( V_2 ) ;
F_516 ( V_2 ) ;
F_206 ( V_2 ) ;
F_513 ( V_2 ) ;
F_485 ( V_2 ) ;
F_487 ( V_2 ) ;
if ( F_14 ( V_712 , & V_2 -> V_35 ) ) {
F_522 ( V_2 ) ;
F_523 ( V_2 ) ;
}
F_31 ( V_2 ) ;
}
static int F_524 ( struct V_59 * V_60 ,
struct V_61 * V_999 ,
T_4 * V_246 )
{
struct V_201 * V_91 = V_999 -> V_91 ;
T_1 V_1000 , V_1001 ;
T_1 V_1002 , V_1003 ;
int V_17 ;
if ( V_91 -> V_233 != V_1004 )
return 0 ;
if ( ! F_525 ( V_91 ) )
return 0 ;
V_17 = F_526 ( V_91 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_1001 = V_1005 ;
if ( V_999 -> V_259 == F_156 ( V_1006 ) ) {
struct V_1007 * V_1008 = F_527 ( V_91 ) ;
V_1008 -> V_1009 = 0 ;
V_1008 -> V_1010 = 0 ;
F_528 ( V_91 ) -> V_1010 = ~ F_529 ( V_1008 -> V_1011 ,
V_1008 -> V_1012 , 0 ,
V_1013 ,
0 ) ;
V_1001 |= V_1014 ;
V_999 -> V_1015 |= V_1016 |
V_1017 |
V_1018 ;
} else if ( F_530 ( V_91 ) ) {
F_531 ( V_91 ) -> V_1019 = 0 ;
F_528 ( V_91 ) -> V_1010 =
~ F_532 ( & F_531 ( V_91 ) -> V_1011 ,
& F_531 ( V_91 ) -> V_1012 ,
0 , V_1013 , 0 ) ;
V_999 -> V_1015 |= V_1016 |
V_1017 ;
}
V_1003 = F_533 ( V_91 ) ;
* V_246 = F_534 ( V_91 ) + V_1003 ;
V_999 -> V_171 = F_149 ( V_91 ) -> V_171 ;
V_999 -> V_170 += ( V_999 -> V_171 - 1 ) * * V_246 ;
V_1002 = V_1003 << V_1020 ;
V_1002 |= F_149 ( V_91 ) -> V_247 << V_1021 ;
V_1000 = F_535 ( V_91 ) ;
V_1000 |= F_536 ( V_91 ) << V_1022 ;
V_1000 |= V_999 -> V_1015 & V_1023 ;
F_537 ( V_60 , V_1000 , 0 , V_1001 ,
V_1002 ) ;
return 1 ;
}
static void F_538 ( struct V_59 * V_60 ,
struct V_61 * V_999 )
{
struct V_201 * V_91 = V_999 -> V_91 ;
T_1 V_1000 = 0 ;
T_1 V_1002 = 0 ;
T_1 V_1001 = 0 ;
if ( V_91 -> V_233 != V_1004 ) {
if ( ! ( V_999 -> V_1015 & V_1024 ) &&
! ( V_999 -> V_1015 & V_1025 ) )
return;
V_1000 = F_536 ( V_91 ) <<
V_1022 ;
} else {
T_4 V_1026 = 0 ;
union {
struct V_1007 * V_1027 ;
struct V_1028 * V_1029 ;
T_4 * V_1030 ;
} V_1031 ;
union {
struct V_1032 * V_1032 ;
T_4 * V_1030 ;
} V_1033 ;
T_12 V_1034 ;
if ( V_91 -> V_224 ) {
V_1031 . V_1030 = F_539 ( V_91 ) ;
V_1033 . V_1030 = F_540 ( V_91 ) ;
V_1000 = F_541 ( V_91 ) <<
V_1022 ;
} else {
V_1031 . V_1030 = F_542 ( V_91 ) ;
V_1033 . V_1030 = F_543 ( V_91 ) ;
V_1000 = F_536 ( V_91 ) <<
V_1022 ;
}
switch ( V_1031 . V_1027 -> V_1035 ) {
case V_1036 :
V_1000 |= V_1033 . V_1030 - V_1031 . V_1030 ;
V_1001 |= V_1014 ;
V_1026 = V_1031 . V_1027 -> V_259 ;
break;
case 6 :
V_1000 |= V_1033 . V_1030 - V_1031 . V_1030 ;
V_1026 = V_1031 . V_1029 -> V_1037 ;
if ( F_99 ( ( V_1033 . V_1030 - V_1031 . V_1030 ) ==
sizeof( struct V_1028 ) ) )
break;
F_544 ( V_91 , V_1031 . V_1030 - V_91 -> V_94 +
sizeof( struct V_1028 ) ,
& V_1026 , & V_1034 ) ;
if ( F_24 ( V_1034 ) )
V_1026 = V_1038 ;
break;
default:
break;
}
switch ( V_1026 ) {
case V_1013 :
V_1001 |= V_1005 ;
V_1002 = ( V_1033 . V_1032 -> V_1039 * 4 ) <<
V_1020 ;
break;
case V_1040 :
V_1001 |= V_1041 ;
V_1002 = sizeof( struct V_1042 ) <<
V_1020 ;
break;
case V_1043 :
V_1002 = sizeof( struct V_1044 ) <<
V_1020 ;
break;
default:
if ( F_24 ( F_545 () ) ) {
F_546 ( V_60 -> V_75 ,
L_133 ,
V_1031 . V_1027 -> V_1035 , V_1026 ) ;
}
F_547 ( V_91 ) ;
goto V_1045;
}
V_999 -> V_1015 |= V_1017 ;
}
V_1045:
V_1000 |= V_999 -> V_1015 & V_1023 ;
F_537 ( V_60 , V_1000 , 0 ,
V_1001 , V_1002 ) ;
}
static T_1 F_548 ( struct V_201 * V_91 , T_1 V_1015 )
{
T_1 V_1046 = V_1047 |
V_1048 |
V_1049 ;
V_1046 |= F_549 ( V_1015 , V_1024 ,
V_1050 ) ;
V_1046 |= F_549 ( V_1015 , V_1016 ,
V_1051 ) ;
V_1046 |= F_549 ( V_1015 , V_1052 ,
V_1053 ) ;
V_1046 ^= F_549 ( V_91 -> V_1054 , 1 , V_1049 ) ;
return V_1046 ;
}
static void F_550 ( union V_63 * V_64 ,
T_1 V_1015 , unsigned int V_1055 )
{
T_1 V_1056 = V_1055 << V_1057 ;
V_1056 |= F_549 ( V_1015 ,
V_1017 ,
V_1058 ) ;
V_1056 |= F_549 ( V_1015 ,
V_1018 ,
V_1059 ) ;
V_1056 |= F_549 ( V_1015 ,
V_1025 ,
V_1060 ) ;
V_64 -> V_243 . V_1056 = F_96 ( V_1056 ) ;
}
static int F_551 ( struct V_59 * V_60 , T_2 V_284 )
{
F_104 ( V_60 -> V_57 , V_60 -> V_88 ) ;
F_111 () ;
if ( F_99 ( F_110 ( V_60 ) < V_284 ) )
return - V_786 ;
F_552 ( V_60 -> V_57 , V_60 -> V_88 ) ;
++ V_60 -> V_154 . V_177 ;
return 0 ;
}
static inline int F_553 ( struct V_59 * V_60 , T_2 V_284 )
{
if ( F_99 ( F_110 ( V_60 ) >= V_284 ) )
return 0 ;
return F_551 ( V_60 , V_284 ) ;
}
static void F_554 ( struct V_59 * V_60 ,
struct V_61 * V_999 ,
const T_4 V_246 )
{
struct V_201 * V_91 = V_999 -> V_91 ;
struct V_61 * V_62 ;
union V_63 * V_64 ;
struct V_270 * V_271 ;
T_9 V_83 ;
unsigned int V_276 , V_284 ;
T_1 V_1015 = V_999 -> V_1015 ;
T_1 V_1046 = F_548 ( V_91 , V_1015 ) ;
T_2 V_50 = V_60 -> V_82 ;
V_64 = F_61 ( V_60 , V_50 ) ;
F_550 ( V_64 , V_1015 , V_91 -> V_84 - V_246 ) ;
V_284 = F_148 ( V_91 ) ;
V_276 = V_91 -> V_276 ;
#ifdef F_176
if ( V_1015 & V_1061 ) {
if ( V_276 < sizeof( struct V_302 ) ) {
V_284 -= sizeof( struct V_302 ) - V_276 ;
V_276 = 0 ;
} else {
V_276 -= sizeof( struct V_302 ) ;
}
}
#endif
V_83 = F_555 ( V_60 -> V_75 , V_91 -> V_94 , V_284 , V_123 ) ;
V_62 = V_999 ;
for ( V_271 = & F_149 ( V_91 ) -> V_272 [ 0 ] ; ; V_271 ++ ) {
if ( F_141 ( V_60 -> V_75 , V_83 ) )
goto V_1062;
F_81 ( V_62 , V_84 , V_284 ) ;
F_556 ( V_62 , V_83 , V_83 ) ;
V_64 -> V_243 . V_1063 = F_144 ( V_83 ) ;
while ( F_24 ( V_284 > V_1064 ) ) {
V_64 -> V_243 . V_1065 =
F_96 ( V_1046 ^ V_1064 ) ;
V_50 ++ ;
V_64 ++ ;
if ( V_50 == V_60 -> V_90 ) {
V_64 = F_61 ( V_60 , 0 ) ;
V_50 = 0 ;
}
V_64 -> V_243 . V_1056 = 0 ;
V_83 += V_1064 ;
V_284 -= V_1064 ;
V_64 -> V_243 . V_1063 = F_144 ( V_83 ) ;
}
if ( F_99 ( ! V_276 ) )
break;
V_64 -> V_243 . V_1065 = F_96 ( V_1046 ^ V_284 ) ;
V_50 ++ ;
V_64 ++ ;
if ( V_50 == V_60 -> V_90 ) {
V_64 = F_61 ( V_60 , 0 ) ;
V_50 = 0 ;
}
V_64 -> V_243 . V_1056 = 0 ;
#ifdef F_176
V_284 = F_325 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_284 = F_557 ( V_271 ) ;
#endif
V_276 -= V_284 ;
V_83 = F_558 ( V_60 -> V_75 , V_271 , 0 , V_284 ,
V_123 ) ;
V_62 = & V_60 -> V_80 [ V_50 ] ;
}
V_1046 |= V_284 | V_1066 ;
V_64 -> V_243 . V_1065 = F_96 ( V_1046 ) ;
F_559 ( F_107 ( V_60 ) , V_999 -> V_170 ) ;
V_999 -> V_86 = V_174 ;
F_145 () ;
V_999 -> V_85 = V_64 ;
V_50 ++ ;
if ( V_50 == V_60 -> V_90 )
V_50 = 0 ;
V_60 -> V_82 = V_50 ;
F_553 ( V_60 , V_1067 ) ;
if ( F_560 ( F_107 ( V_60 ) ) || ! V_91 -> V_1068 ) {
F_146 ( V_50 , V_60 -> V_148 ) ;
F_561 () ;
}
return;
V_1062:
F_428 ( V_60 -> V_75 , L_134 ) ;
for (; ; ) {
V_62 = & V_60 -> V_80 [ V_50 ] ;
F_77 ( V_60 , V_62 ) ;
if ( V_62 == V_999 )
break;
if ( V_50 == 0 )
V_50 = V_60 -> V_90 ;
V_50 -- ;
}
V_60 -> V_82 = V_50 ;
}
static void F_562 ( struct V_59 * V_122 ,
struct V_61 * V_999 )
{
struct V_159 * V_160 = V_122 -> V_160 ;
union V_1069 V_1070 = { . V_1071 = 0 } ;
union V_1069 V_1072 = { . V_1071 = 0 } ;
union {
unsigned char * V_1073 ;
struct V_1007 * V_1027 ;
struct V_1028 * V_1029 ;
} V_1074 ;
struct V_1032 * V_1075 ;
unsigned int V_1076 ;
struct V_201 * V_91 ;
T_12 V_1077 ;
int V_1078 ;
if ( ! V_160 )
return;
if ( ! V_122 -> V_411 )
return;
V_122 -> V_412 ++ ;
if ( ( V_999 -> V_259 != F_156 ( V_1006 ) ) &&
( V_999 -> V_259 != F_156 ( V_1079 ) ) )
return;
V_91 = V_999 -> V_91 ;
V_1074 . V_1073 = F_542 ( V_91 ) ;
#ifdef F_416
if ( V_91 -> V_224 &&
V_999 -> V_259 == F_156 ( V_1006 ) &&
V_1074 . V_1027 -> V_259 != V_1043 ) {
struct V_1 * V_2 = V_160 -> V_2 ;
if ( V_2 -> V_616 &&
F_563 ( V_91 ) -> V_1080 == V_2 -> V_616 )
V_1074 . V_1073 = F_539 ( V_91 ) ;
}
#endif
switch ( V_1074 . V_1027 -> V_1035 ) {
case V_1036 :
V_1076 = ( V_1074 . V_1073 [ 0 ] & 0x0F ) << 2 ;
V_1078 = V_1074 . V_1027 -> V_259 ;
break;
case 6 :
V_1076 = V_1074 . V_1073 - V_91 -> V_94 ;
V_1078 = F_564 ( V_91 , & V_1076 , V_1013 , NULL , NULL ) ;
V_1076 -= V_1074 . V_1073 - V_91 -> V_94 ;
break;
default:
return;
}
if ( V_1078 != V_1013 )
return;
V_1075 = (struct V_1032 * ) ( V_1074 . V_1073 + V_1076 ) ;
if ( V_1075 -> V_1081 )
return;
if ( ! V_1075 -> V_1082 && ( V_122 -> V_412 < V_122 -> V_411 ) )
return;
V_122 -> V_412 = 0 ;
V_1077 = F_156 ( V_999 -> V_1015 >> V_1083 ) ;
V_1070 . V_1084 . V_1077 = V_1077 ;
if ( V_999 -> V_1015 & ( V_1085 | V_1024 ) )
V_1072 . V_1086 . V_1087 ^= V_1075 -> V_1080 ^ F_156 ( V_258 ) ;
else
V_1072 . V_1086 . V_1087 ^= V_1075 -> V_1080 ^ V_999 -> V_259 ;
V_1072 . V_1086 . V_1088 ^= V_1075 -> V_1089 ;
switch ( V_1074 . V_1027 -> V_1035 ) {
case V_1036 :
V_1070 . V_1084 . V_1090 = V_1091 ;
V_1072 . V_1092 ^= V_1074 . V_1027 -> V_1011 ^ V_1074 . V_1027 -> V_1012 ;
break;
case 6 :
V_1070 . V_1084 . V_1090 = V_1093 ;
V_1072 . V_1092 ^= V_1074 . V_1029 -> V_1011 . V_1094 [ 0 ] ^
V_1074 . V_1029 -> V_1011 . V_1094 [ 1 ] ^
V_1074 . V_1029 -> V_1011 . V_1094 [ 2 ] ^
V_1074 . V_1029 -> V_1011 . V_1094 [ 3 ] ^
V_1074 . V_1029 -> V_1012 . V_1094 [ 0 ] ^
V_1074 . V_1029 -> V_1012 . V_1094 [ 1 ] ^
V_1074 . V_1029 -> V_1012 . V_1094 [ 2 ] ^
V_1074 . V_1029 -> V_1012 . V_1094 [ 3 ] ;
break;
default:
break;
}
if ( V_1074 . V_1073 != F_542 ( V_91 ) )
V_1070 . V_1084 . V_1090 |= V_1095 ;
F_565 ( & V_160 -> V_2 -> V_14 ,
V_1070 , V_1072 , V_122 -> V_88 ) ;
}
static T_2 F_566 ( struct V_56 * V_75 , struct V_201 * V_91 ,
void * V_1096 , T_15 V_1097 )
{
struct V_653 * V_1098 = V_1096 ;
#ifdef F_176
struct V_1 * V_2 ;
struct V_969 * V_1099 ;
int V_1100 ;
#endif
if ( V_1098 )
return V_91 -> V_1101 + V_1098 -> V_661 ;
#ifdef F_176
switch ( F_567 ( V_91 ) ) {
case F_156 ( V_1102 ) :
case F_156 ( V_1103 ) :
V_2 = F_89 ( V_75 ) ;
if ( V_2 -> V_141 & V_527 )
break;
default:
return V_1097 ( V_75 , V_91 ) ;
}
V_1099 = & V_2 -> V_426 [ V_1104 ] ;
V_1100 = F_568 ( V_91 ) ? F_569 ( V_91 ) :
F_570 () ;
while ( V_1100 >= V_1099 -> V_428 )
V_1100 -= V_1099 -> V_428 ;
return V_1100 + V_1099 -> V_1105 ;
#else
return V_1097 ( V_75 , V_91 ) ;
#endif
}
T_16 F_571 ( struct V_201 * V_91 ,
struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_61 * V_999 ;
int V_1106 ;
T_1 V_1015 = 0 ;
unsigned short V_1099 ;
T_2 V_90 = F_572 ( F_148 ( V_91 ) ) ;
T_12 V_259 = V_91 -> V_259 ;
T_4 V_246 = 0 ;
for ( V_1099 = 0 ; V_1099 < F_149 ( V_91 ) -> V_290 ; V_1099 ++ )
V_90 += F_572 ( F_149 ( V_91 ) -> V_272 [ V_1099 ] . V_284 ) ;
if ( F_553 ( V_60 , V_90 + 3 ) ) {
V_60 -> V_154 . V_816 ++ ;
return V_1107 ;
}
V_999 = & V_60 -> V_80 [ V_60 -> V_82 ] ;
V_999 -> V_91 = V_91 ;
V_999 -> V_170 = V_91 -> V_84 ;
V_999 -> V_171 = 1 ;
if ( F_573 ( V_91 ) ) {
V_1015 |= F_574 ( V_91 ) << V_1083 ;
V_1015 |= V_1024 ;
} else if ( V_259 == F_156 ( V_258 ) ) {
struct V_1108 * V_1109 , V_1110 ;
V_1109 = F_575 ( V_91 , V_523 , sizeof( V_1110 ) , & V_1110 ) ;
if ( ! V_1109 )
goto V_1111;
V_1015 |= F_576 ( V_1109 -> V_1112 ) <<
V_1083 ;
V_1015 |= V_1085 ;
}
V_259 = F_567 ( V_91 ) ;
if ( F_24 ( F_149 ( V_91 ) -> V_1015 & V_1113 ) &&
V_2 -> V_1114 &&
! F_577 ( V_1115 ,
& V_2 -> V_35 ) ) {
F_149 ( V_91 ) -> V_1015 |= V_1116 ;
V_1015 |= V_1052 ;
V_2 -> V_1117 = F_578 ( V_91 ) ;
V_2 -> V_1118 = V_174 ;
F_579 ( & V_2 -> V_1119 ) ;
}
F_580 ( V_91 ) ;
#ifdef F_307
if ( V_2 -> V_141 & V_421 )
V_1015 |= V_1025 ;
#endif
if ( ( V_2 -> V_141 & V_142 ) &&
( ( V_1015 & ( V_1024 | V_1085 ) ) ||
( V_91 -> V_1120 != V_1121 ) ) ) {
V_1015 &= ~ V_1122 ;
V_1015 |= ( V_91 -> V_1120 & 0x7 ) <<
V_1123 ;
if ( V_1015 & V_1085 ) {
struct V_1124 * V_1109 ;
if ( F_526 ( V_91 , 0 ) )
goto V_1111;
V_1109 = (struct V_1124 * ) V_91 -> V_94 ;
V_1109 -> V_1112 = F_156 ( V_1015 >>
V_1083 ) ;
} else {
V_1015 |= V_1024 ;
}
}
V_999 -> V_1015 = V_1015 ;
V_999 -> V_259 = V_259 ;
#ifdef F_176
if ( ( V_259 == F_156 ( V_1102 ) ) &&
( V_60 -> V_57 -> V_203 & ( V_1125 | V_1126 ) ) ) {
V_1106 = F_581 ( V_60 , V_999 , & V_246 ) ;
if ( V_1106 < 0 )
goto V_1111;
goto V_1127;
}
#endif
V_1106 = F_524 ( V_60 , V_999 , & V_246 ) ;
if ( V_1106 < 0 )
goto V_1111;
else if ( ! V_1106 )
F_538 ( V_60 , V_999 ) ;
if ( F_14 ( V_385 , & V_60 -> V_35 ) )
F_562 ( V_60 , V_999 ) ;
#ifdef F_176
V_1127:
#endif
F_554 ( V_60 , V_999 , V_246 ) ;
return V_1128 ;
V_1111:
F_78 ( V_999 -> V_91 ) ;
V_999 -> V_91 = NULL ;
return V_1128 ;
}
static T_16 F_582 ( struct V_201 * V_91 ,
struct V_56 * V_57 ,
struct V_59 * V_122 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
struct V_59 * V_60 ;
if ( F_583 ( V_91 , 17 ) )
return V_1128 ;
V_60 = V_122 ? V_122 : V_2 -> V_60 [ V_91 -> V_1101 ] ;
return F_571 ( V_91 , V_2 , V_60 ) ;
}
static T_16 F_584 ( struct V_201 * V_91 ,
struct V_56 * V_57 )
{
return F_582 ( V_91 , V_57 , NULL ) ;
}
static int F_585 ( struct V_56 * V_57 , void * V_1129 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1130 * V_586 = V_1129 ;
if ( ! F_373 ( V_586 -> V_1131 ) )
return - V_1132 ;
memcpy ( V_57 -> V_666 , V_586 -> V_1131 , V_57 -> V_1133 ) ;
memcpy ( V_14 -> V_110 . V_586 , V_586 -> V_1131 , V_57 -> V_1133 ) ;
F_314 ( V_2 ) ;
return 0 ;
}
static int
F_586 ( struct V_56 * V_57 , int V_1134 , int V_1135 , T_2 V_586 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_4 ;
int V_1136 ;
if ( V_1134 != V_14 -> V_347 . V_1137 . V_1134 )
return - V_591 ;
V_1136 = V_14 -> V_347 . V_344 . V_1138 ( V_14 , V_586 , V_1135 , & V_4 ) ;
if ( ! V_1136 )
V_1136 = V_4 ;
return V_1136 ;
}
static int F_587 ( struct V_56 * V_57 , int V_1134 , int V_1135 ,
T_2 V_586 , T_2 V_4 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_1134 != V_14 -> V_347 . V_1137 . V_1134 )
return - V_591 ;
return V_14 -> V_347 . V_344 . V_1139 ( V_14 , V_586 , V_1135 , V_4 ) ;
}
static int F_588 ( struct V_56 * V_57 , struct V_1140 * V_1141 , int V_1142 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
switch ( V_1142 ) {
case V_1143 :
return F_589 ( V_2 , V_1141 ) ;
case V_1144 :
return F_590 ( V_2 , V_1141 ) ;
default:
return F_591 ( & V_2 -> V_14 . V_347 . V_1137 , F_592 ( V_1141 ) , V_1142 ) ;
}
}
static int F_593 ( struct V_56 * V_75 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_75 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_373 ( V_14 -> V_110 . V_1145 ) ) {
F_455 () ;
V_17 = F_594 ( V_75 , V_14 -> V_110 . V_1145 , V_1146 ) ;
F_457 () ;
V_14 -> V_110 . V_344 . V_711 ( V_14 , F_281 ( 0 ) ) ;
}
return V_17 ;
}
static int F_595 ( struct V_56 * V_75 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_75 ) ;
struct V_1147 * V_110 = & V_2 -> V_14 . V_110 ;
if ( F_373 ( V_110 -> V_1145 ) ) {
F_455 () ;
V_17 = F_596 ( V_75 , V_110 -> V_1145 , V_1146 ) ;
F_457 () ;
}
return V_17 ;
}
static void F_597 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
int V_50 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
for ( V_50 = 0 ; V_50 < V_2 -> V_195 ; V_50 ++ )
F_229 ( 0 , V_2 -> V_160 [ V_50 ] ) ;
}
static struct V_1148 * F_598 ( struct V_56 * V_57 ,
struct V_1148 * V_126 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
int V_50 ;
F_599 () ;
for ( V_50 = 0 ; V_50 < V_2 -> V_95 ; V_50 ++ ) {
struct V_59 * V_122 = F_21 ( V_2 -> V_69 [ V_50 ] ) ;
T_6 V_173 , V_146 ;
unsigned int V_1149 ;
if ( V_122 ) {
do {
V_1149 = F_600 ( & V_122 -> V_172 ) ;
V_146 = V_122 -> V_126 . V_146 ;
V_173 = V_122 -> V_126 . V_173 ;
} while ( F_601 ( & V_122 -> V_172 , V_1149 ) );
V_126 -> V_821 += V_146 ;
V_126 -> V_820 += V_173 ;
}
}
for ( V_50 = 0 ; V_50 < V_2 -> V_79 ; V_50 ++ ) {
struct V_59 * V_122 = F_21 ( V_2 -> V_60 [ V_50 ] ) ;
T_6 V_173 , V_146 ;
unsigned int V_1149 ;
if ( V_122 ) {
do {
V_1149 = F_600 ( & V_122 -> V_172 ) ;
V_146 = V_122 -> V_126 . V_146 ;
V_173 = V_122 -> V_126 . V_173 ;
} while ( F_601 ( & V_122 -> V_172 , V_1149 ) );
V_126 -> V_823 += V_146 ;
V_126 -> V_822 += V_173 ;
}
}
F_602 () ;
V_126 -> V_930 = V_57 -> V_126 . V_930 ;
V_126 -> V_931 = V_57 -> V_126 . V_931 ;
V_126 -> V_933 = V_57 -> V_126 . V_933 ;
V_126 -> V_934 = V_57 -> V_126 . V_934 ;
V_126 -> V_935 = V_57 -> V_126 . V_935 ;
return V_126 ;
}
static void F_603 ( struct V_1 * V_2 , T_4 V_136 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_3 , V_1150 ;
int V_50 ;
if ( V_14 -> V_110 . type == V_111 )
return;
V_3 = F_37 ( V_14 , V_1151 ) ;
V_1150 = V_3 ;
for ( V_50 = 0 ; V_50 < V_637 ; V_50 ++ ) {
T_4 V_1152 = V_3 >> ( V_50 * V_1153 ) ;
if ( V_1152 > V_136 )
V_3 &= ~ ( 0x7 << V_1153 ) ;
}
if ( V_3 != V_1150 )
F_71 ( V_14 , V_1151 , V_3 ) ;
return;
}
static void F_604 ( struct V_1 * V_2 )
{
struct V_56 * V_75 = V_2 -> V_57 ;
struct V_1154 * V_138 = & V_2 -> V_138 ;
struct V_1155 * V_1156 = V_2 -> V_622 ;
T_4 V_1157 ;
for ( V_1157 = 0 ; V_1157 < V_1158 ; V_1157 ++ ) {
T_4 V_136 = 0 ;
if ( V_2 -> V_618 & V_619 )
V_136 = F_605 ( V_138 , 0 , V_1157 ) ;
else if ( V_1156 )
V_136 = V_1156 -> V_623 [ V_1157 ] ;
F_606 ( V_75 , V_1157 , V_136 ) ;
}
}
int F_607 ( struct V_56 * V_75 , T_4 V_136 )
{
struct V_1 * V_2 = F_89 ( V_75 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
bool V_1159 ;
if ( V_136 > V_2 -> V_138 . V_747 . V_748 )
return - V_591 ;
if ( V_14 -> V_110 . type == V_111 && V_136 && V_136 < V_637 )
return - V_591 ;
V_1159 = ( F_608 ( & V_2 -> V_663 , 32 ) > 1 ) ;
if ( V_136 && V_1159 && V_2 -> V_664 > V_1160 )
return - V_786 ;
if ( F_57 ( V_75 ) )
F_445 ( V_75 ) ;
else
F_395 ( V_2 ) ;
F_462 ( V_2 ) ;
#ifdef F_378
if ( V_136 ) {
F_609 ( V_75 , V_136 ) ;
F_604 ( V_2 ) ;
V_2 -> V_141 |= V_142 ;
if ( V_2 -> V_14 . V_110 . type == V_111 ) {
V_2 -> V_1161 = V_2 -> V_14 . V_127 . V_762 ;
V_2 -> V_14 . V_127 . V_762 = V_1162 ;
}
} else {
F_610 ( V_75 ) ;
if ( V_2 -> V_14 . V_110 . type == V_111 )
V_2 -> V_14 . V_127 . V_762 = V_2 -> V_1161 ;
V_2 -> V_141 &= ~ V_142 ;
V_2 -> V_761 . V_139 = false ;
V_2 -> V_138 . V_139 = false ;
}
F_603 ( V_2 , V_136 ) ;
#endif
F_456 ( V_2 ) ;
if ( F_57 ( V_75 ) )
return F_440 ( V_75 ) ;
return 0 ;
}
static int F_611 ( struct V_1 * V_2 ,
struct V_1163 * V_1164 )
{
T_1 V_1165 = F_612 ( V_1164 -> V_1166 . V_1167 ) ;
T_1 V_1168 ;
int V_17 ;
if ( ( V_1165 != 0x800 ) && ( V_1165 >= V_1169 ) )
return - V_591 ;
V_1168 = V_1164 -> V_1166 . V_1167 & 0xfffff ;
F_356 ( & V_2 -> V_647 ) ;
V_17 = F_613 ( V_2 , NULL , V_1168 ) ;
F_361 ( & V_2 -> V_647 ) ;
return V_17 ;
}
static int F_614 ( struct V_1 * V_2 ,
T_12 V_259 ,
struct V_1163 * V_1164 )
{
T_1 V_1165 = F_612 ( V_1164 -> V_1170 . V_1167 ) ;
if ( V_1165 >= V_1169 )
return - V_591 ;
if ( V_1164 -> V_1170 . V_1171 > 0 )
return - V_591 ;
F_250 ( V_1165 - 1 , & V_2 -> V_1172 ) ;
return 0 ;
}
static int F_615 ( struct V_1 * V_2 ,
struct V_1163 * V_1164 )
{
T_1 V_1165 = F_612 ( V_1164 -> V_1170 . V_1167 ) ;
if ( V_1165 >= V_1169 )
return - V_591 ;
F_34 ( V_1165 - 1 , & V_2 -> V_1172 ) ;
return 0 ;
}
static int F_616 ( struct V_1 * V_2 ,
T_12 V_259 ,
struct V_1163 * V_1164 )
{
T_1 V_1168 = V_1164 -> V_1166 . V_1167 & 0xfffff ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1173 * V_1174 ;
struct V_645 * V_1070 ;
union V_1175 V_119 ;
#ifdef F_617
const struct V_1176 * V_66 ;
#endif
int V_50 , V_17 = 0 ;
T_4 V_106 ;
T_1 V_1165 , V_1177 ;
memset ( & V_119 , 0 , sizeof( union V_1175 ) ) ;
V_1165 = F_612 ( V_1164 -> V_1166 . V_1167 ) ;
V_1177 = F_612 ( V_1164 -> V_1166 . V_1178 ) ;
if ( V_259 != F_156 ( V_1006 ) )
return - V_591 ;
if ( V_1177 ) {
struct V_1179 * V_1037 = V_1180 ;
if ( V_1177 >= V_1169 )
return - V_591 ;
if ( ! F_14 ( V_1177 - 1 , & V_2 -> V_1172 ) )
return - V_591 ;
for ( V_50 = 0 ; V_1037 [ V_50 ] . V_1181 ; V_50 ++ ) {
if ( V_1037 -> V_1182 != V_1164 -> V_1166 . V_1183 -> V_1184 ||
V_1037 -> V_1185 != V_1164 -> V_1166 . V_1183 -> V_1186 ||
V_1037 -> V_1187 != V_1164 -> V_1166 . V_1183 -> V_1188 ||
V_1164 -> V_1166 . V_1183 -> V_1189 > 1 )
return - V_591 ;
if ( V_1037 -> V_1190 != V_1164 -> V_1166 . V_1183 -> V_1191 [ 0 ] . V_1190 ||
V_1037 -> V_1192 != V_1164 -> V_1166 . V_1183 -> V_1191 [ 0 ] . V_1192 ||
V_1037 -> V_119 != V_1164 -> V_1166 . V_1183 -> V_1191 [ 0 ] . V_119 )
return - V_591 ;
V_2 -> V_739 [ V_1177 ] = V_1037 -> V_1181 ;
}
return 0 ;
}
if ( V_1168 >= ( ( 1024 << V_2 -> V_640 ) - 2 ) ) {
F_103 ( V_158 , L_135 ) ;
return - V_591 ;
}
if ( V_1165 == 0x800 ) {
V_1174 = V_2 -> V_739 [ 0 ] ;
} else {
if ( V_1165 >= V_1169 )
return - V_591 ;
V_1174 = V_2 -> V_739 [ V_1165 ] ;
}
if ( ! V_1174 )
return - V_591 ;
V_1070 = F_414 ( sizeof( * V_1070 ) , V_780 ) ;
if ( ! V_1070 )
return - V_579 ;
for ( V_50 = 0 ; V_50 < V_1164 -> V_1166 . V_1183 -> V_1189 ; V_50 ++ ) {
int V_1190 = V_1164 -> V_1166 . V_1183 -> V_1191 [ V_50 ] . V_1190 ;
T_17 V_1192 = V_1164 -> V_1166 . V_1183 -> V_1191 [ V_50 ] . V_1192 ;
T_17 V_1187 = V_1164 -> V_1166 . V_1183 -> V_1191 [ V_50 ] . V_119 ;
bool V_1193 = false ;
int V_51 ;
for ( V_51 = 0 ; V_1174 [ V_51 ] . V_1192 ; V_51 ++ ) {
if ( V_1174 [ V_51 ] . V_1190 == V_1190 ) {
V_1174 [ V_51 ] . V_1192 ( V_1070 , & V_119 , V_1192 , V_1187 ) ;
V_1070 -> V_646 . V_1084 . V_1090 |=
V_1174 [ V_51 ] . type ;
V_1193 = true ;
break;
}
}
if ( ! V_1193 )
goto V_1194;
}
V_119 . V_1084 . V_1090 = V_1195 |
V_1196 ;
if ( V_1070 -> V_646 . V_1084 . V_1090 == V_1197 )
V_119 . V_1084 . V_1090 &= V_1195 ;
#ifdef F_617
if ( F_618 ( & V_1164 -> V_1166 . V_1198 -> V_1199 ) )
goto V_1194;
F_619 (a, &cls->knode.exts->actions, list) {
if ( ! F_620 ( V_66 ) )
goto V_1194;
}
#endif
V_1070 -> V_651 = V_652 ;
V_106 = V_652 ;
V_1070 -> V_650 = V_1168 ;
F_356 ( & V_2 -> V_647 ) ;
if ( F_357 ( & V_2 -> V_648 ) ) {
memcpy ( & V_2 -> V_649 , & V_119 , sizeof( V_119 ) ) ;
V_17 = F_358 ( V_14 , & V_119 ) ;
if ( V_17 )
goto V_1200;
} else if ( memcmp ( & V_2 -> V_649 , & V_119 , sizeof( V_119 ) ) ) {
V_17 = - V_591 ;
goto V_1200;
}
F_621 ( & V_1070 -> V_646 , & V_119 ) ;
V_17 = F_360 ( V_14 , & V_1070 -> V_646 ,
V_1070 -> V_650 , V_106 ) ;
if ( ! V_17 )
F_613 ( V_2 , V_1070 , V_1070 -> V_650 ) ;
F_361 ( & V_2 -> V_647 ) ;
return V_17 ;
V_1200:
F_361 ( & V_2 -> V_647 ) ;
V_1194:
F_241 ( V_1070 ) ;
return - V_591 ;
}
static int F_622 ( struct V_56 * V_75 , T_1 V_1167 , T_12 V_554 ,
struct V_1201 * V_136 )
{
struct V_1 * V_2 = F_89 ( V_75 ) ;
if ( F_623 ( V_1167 ) == F_623 ( V_1202 ) &&
V_136 -> type == V_1203 ) {
switch ( V_136 -> V_1204 -> V_1205 ) {
case V_1206 :
case V_1207 :
return F_616 ( V_2 ,
V_554 , V_136 -> V_1204 ) ;
case V_1208 :
return F_611 ( V_2 , V_136 -> V_1204 ) ;
case V_1209 :
case V_1210 :
return F_614 ( V_2 , V_554 ,
V_136 -> V_1204 ) ;
case V_1211 :
return F_615 ( V_2 ,
V_136 -> V_1204 ) ;
default:
return - V_591 ;
}
}
if ( V_136 -> type != V_1212 )
return - V_591 ;
return F_607 ( V_75 , V_136 -> V_136 ) ;
}
void F_624 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = V_2 -> V_57 ;
F_455 () ;
F_607 ( V_57 , F_254 ( V_57 ) ) ;
F_457 () ;
}
void F_625 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
if ( F_57 ( V_57 ) )
F_389 ( V_2 ) ;
else
F_395 ( V_2 ) ;
}
static T_18 F_626 ( struct V_56 * V_57 ,
T_18 V_203 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
if ( ! ( V_203 & V_221 ) )
V_203 &= ~ V_1213 ;
if ( ! ( V_2 -> V_156 & V_731 ) )
V_203 &= ~ V_1213 ;
return V_203 ;
}
static int F_627 ( struct V_56 * V_57 ,
T_18 V_203 )
{
struct V_1 * V_2 = F_89 ( V_57 ) ;
T_18 V_1214 = V_57 -> V_203 ^ V_203 ;
bool V_1215 = false ;
if ( ! ( V_203 & V_1213 ) ) {
if ( V_2 -> V_156 & V_535 )
V_1215 = true ;
V_2 -> V_156 &= ~ V_535 ;
} else if ( ( V_2 -> V_156 & V_731 ) &&
! ( V_2 -> V_156 & V_535 ) ) {
if ( V_2 -> V_392 == 1 ||
V_2 -> V_392 > V_1216 ) {
V_2 -> V_156 |= V_535 ;
V_1215 = true ;
} else if ( ( V_1214 ^ V_203 ) & V_1213 ) {
F_105 ( V_175 , L_136
L_137 ) ;
}
}
if ( ( V_203 & V_1217 ) || ( V_203 & V_1218 ) ) {
if ( ! ( V_2 -> V_141 & V_639 ) )
V_1215 = true ;
V_2 -> V_141 &= ~ V_375 ;
V_2 -> V_141 |= V_639 ;
} else {
if ( V_2 -> V_141 & V_639 )
V_1215 = true ;
V_2 -> V_141 &= ~ V_639 ;
if ( V_2 -> V_141 & V_421 ||
( F_254 ( V_57 ) > 1 ) ||
( V_2 -> V_426 [ V_427 ] . V_730 <= 1 ) ||
( ! V_2 -> V_411 ) )
;
else
V_2 -> V_141 |= V_375 ;
}
if ( V_203 & V_254 )
F_300 ( V_2 ) ;
else
F_299 ( V_2 ) ;
if ( V_1214 & V_279 )
V_1215 = true ;
V_57 -> V_203 = V_203 ;
#ifdef F_416
if ( ( V_2 -> V_141 & V_745 ) ) {
if ( V_203 & V_221 )
V_2 -> V_156 |= V_998 ;
else
F_336 ( V_2 ) ;
}
#endif
if ( V_1215 )
F_625 ( V_57 ) ;
return 0 ;
}
static void F_628 ( struct V_56 * V_75 , T_19 V_1219 ,
T_12 V_1086 )
{
struct V_1 * V_2 = F_89 ( V_75 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! ( V_2 -> V_141 & V_745 ) )
return;
if ( V_1219 == V_1220 )
return;
if ( V_2 -> V_616 == V_1086 )
return;
if ( V_2 -> V_616 ) {
F_629 ( V_75 ,
L_138 ,
F_576 ( V_1086 ) ) ;
return;
}
V_2 -> V_616 = V_1086 ;
F_71 ( V_14 , V_615 , F_576 ( V_1086 ) ) ;
}
static void F_630 ( struct V_56 * V_75 , T_19 V_1219 ,
T_12 V_1086 )
{
struct V_1 * V_2 = F_89 ( V_75 ) ;
if ( ! ( V_2 -> V_141 & V_745 ) )
return;
if ( V_1219 == V_1220 )
return;
if ( V_2 -> V_616 != V_1086 ) {
F_629 ( V_75 , L_139 ,
F_576 ( V_1086 ) ) ;
return;
}
F_336 ( V_2 ) ;
V_2 -> V_156 |= V_998 ;
}
static int F_631 ( struct V_1221 * V_1222 , struct V_1223 * V_1224 [] ,
struct V_56 * V_75 ,
const unsigned char * V_586 , T_2 V_256 ,
T_2 V_141 )
{
if ( F_632 ( V_586 ) || F_633 ( V_586 ) ) {
struct V_1 * V_2 = F_89 ( V_75 ) ;
T_2 V_483 = F_281 ( 0 ) ;
if ( F_321 ( V_75 ) >= F_313 ( V_2 , V_483 ) )
return - V_579 ;
}
return F_634 ( V_1222 , V_1224 , V_75 , V_586 , V_256 , V_141 ) ;
}
static int F_635 ( struct V_1 * V_2 ,
T_20 V_1225 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
unsigned int V_1129 , V_1226 ;
T_1 V_492 ;
switch ( V_1225 ) {
case V_1227 :
F_71 ( & V_2 -> V_14 , V_500 , 0 ) ;
V_492 = F_37 ( V_14 , V_1228 ) ;
V_492 |= V_497 ;
F_71 ( V_14 , V_1228 , V_492 ) ;
V_1226 = V_2 -> V_311 + V_2 -> V_664 ;
for ( V_1129 = 0 ; V_1129 < V_1226 ; V_1129 ++ ) {
if ( V_14 -> V_110 . V_344 . V_1229 )
V_14 -> V_110 . V_344 . V_1229 ( V_14 ,
true ,
V_1129 ) ;
}
break;
case V_499 :
F_71 ( & V_2 -> V_14 , V_500 ,
V_501 ) ;
V_492 = F_37 ( V_14 , V_1228 ) ;
if ( ! V_2 -> V_311 )
V_492 &= ~ V_497 ;
F_71 ( V_14 , V_1228 , V_492 ) ;
V_1226 = V_2 -> V_311 + V_2 -> V_664 ;
for ( V_1129 = 0 ; V_1129 < V_1226 ; V_1129 ++ ) {
if ( V_14 -> V_110 . V_344 . V_1229 )
V_14 -> V_110 . V_344 . V_1229 ( V_14 ,
false ,
V_1129 ) ;
}
break;
default:
return - V_591 ;
}
V_2 -> V_498 = V_1225 ;
F_105 ( V_158 , L_140 ,
V_1225 == V_1227 ? L_141 : L_142 ) ;
return 0 ;
}
static int F_636 ( struct V_56 * V_75 ,
struct V_1230 * V_1231 , T_2 V_141 )
{
struct V_1 * V_2 = F_89 ( V_75 ) ;
struct V_1223 * V_1232 , * V_1233 ;
int V_1234 ;
if ( ! ( V_2 -> V_141 & V_421 ) )
return - V_1235 ;
V_1233 = F_637 ( V_1231 , sizeof( struct V_1236 ) , V_1237 ) ;
if ( ! V_1233 )
return - V_591 ;
F_638 (attr, br_spec, rem) {
int V_168 ;
T_20 V_1225 ;
if ( F_639 ( V_1232 ) != V_1238 )
continue;
if ( F_640 ( V_1232 ) < sizeof( V_1225 ) )
return - V_591 ;
V_1225 = F_641 ( V_1232 ) ;
V_168 = F_635 ( V_2 , V_1225 ) ;
if ( V_168 )
return V_168 ;
break;
}
return 0 ;
}
static int F_642 ( struct V_201 * V_91 , T_1 V_1239 , T_1 V_1240 ,
struct V_56 * V_75 ,
T_1 V_1241 , int V_1242 )
{
struct V_1 * V_2 = F_89 ( V_75 ) ;
if ( ! ( V_2 -> V_141 & V_421 ) )
return 0 ;
return F_643 ( V_91 , V_1239 , V_1240 , V_75 ,
V_2 -> V_498 , 0 , 0 , V_1242 ,
V_1241 , NULL ) ;
}
static void * F_644 ( struct V_56 * V_9 , struct V_56 * V_657 )
{
struct V_653 * V_1098 = NULL ;
struct V_1 * V_2 = F_89 ( V_9 ) ;
int V_1243 = V_2 -> V_311 + V_2 -> V_664 ;
unsigned int V_730 ;
int V_483 , V_17 ;
if ( V_1243 >= V_1244 )
return F_645 ( - V_591 ) ;
#ifdef F_646
if ( V_657 -> V_95 != V_657 -> V_79 ) {
F_629 ( V_9 , L_143 ,
V_657 -> V_55 ) ;
return F_645 ( - V_591 ) ;
}
#endif
if ( V_657 -> V_79 > V_789 ||
V_657 -> V_79 == V_1245 ) {
F_629 ( V_9 ,
L_144 ,
V_9 -> V_55 ) ;
return F_645 ( - V_591 ) ;
}
if ( ( ( V_2 -> V_141 & V_142 ) &&
V_2 -> V_664 > V_1160 - 1 ) ||
( V_2 -> V_664 > V_1246 ) )
return F_645 ( - V_786 ) ;
V_1098 = F_414 ( sizeof( * V_1098 ) , V_780 ) ;
if ( ! V_1098 )
return F_645 ( - V_579 ) ;
V_483 = F_608 ( & V_2 -> V_663 , 32 ) ;
V_2 -> V_664 ++ ;
F_250 ( V_483 , & V_2 -> V_663 ) ;
V_730 = F_647 ( & V_2 -> V_663 , 32 ) ;
V_2 -> V_141 |= V_567 | V_421 ;
V_2 -> V_426 [ V_504 ] . V_730 = V_730 + 1 ;
V_2 -> V_426 [ V_427 ] . V_730 = V_657 -> V_79 ;
V_17 = F_607 ( V_9 , F_254 ( V_9 ) ) ;
if ( V_17 )
goto V_1247;
V_1098 -> V_483 = V_483 ;
V_1098 -> V_150 = V_2 ;
V_17 = F_369 ( V_657 , V_1098 ) ;
if ( V_17 )
goto V_1247;
F_648 ( V_657 ) ;
return V_1098 ;
V_1247:
F_629 ( V_9 ,
L_145 , V_657 -> V_55 ) ;
F_34 ( V_483 , & V_2 -> V_663 ) ;
V_2 -> V_664 -- ;
F_241 ( V_1098 ) ;
return F_645 ( V_17 ) ;
}
static void F_649 ( struct V_56 * V_9 , void * V_1248 )
{
struct V_653 * V_1098 = V_1248 ;
struct V_1 * V_2 = V_1098 -> V_150 ;
unsigned int V_730 ;
F_34 ( V_1098 -> V_483 , & V_2 -> V_663 ) ;
V_2 -> V_664 -- ;
V_730 = F_647 ( & V_2 -> V_663 , 32 ) ;
V_2 -> V_426 [ V_504 ] . V_730 = V_730 + 1 ;
F_367 ( V_1098 -> V_57 , V_1098 ) ;
F_607 ( V_9 , F_254 ( V_9 ) ) ;
F_370 ( V_9 , L_90 ,
V_1098 -> V_483 , V_2 -> V_664 ,
V_1098 -> V_656 ,
V_1098 -> V_656 + V_2 -> V_655 ,
V_2 -> V_663 ) ;
F_241 ( V_1098 ) ;
}
static T_18
F_650 ( struct V_201 * V_91 , struct V_56 * V_75 ,
T_18 V_203 )
{
if ( ! V_91 -> V_224 )
return V_203 ;
if ( F_24 ( F_651 ( V_91 ) - F_543 ( V_91 ) >
V_1249 ) )
return V_203 & ~ V_1250 ;
return V_203 ;
}
static inline int F_652 ( struct V_1 * V_2 )
{
struct V_5 * V_397 , * V_9 = V_2 -> V_9 ;
int V_1251 = 0 ;
if ( F_8 ( & V_2 -> V_14 ) )
V_1251 = 4 ;
F_619 (entry, &adapter->pdev->bus->devices, bus_list) {
if ( V_397 -> V_1252 )
continue;
if ( ( V_397 -> V_723 != V_9 -> V_723 ) ||
( V_397 -> V_196 != V_9 -> V_196 ) )
return - 1 ;
V_1251 ++ ;
}
return V_1251 ;
}
int F_653 ( struct V_1 * V_2 , T_2 V_21 ,
T_2 V_1253 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1254 = V_2 -> V_1255 & V_1256 ;
int V_1257 = 0 ;
switch ( V_21 ) {
case V_1258 :
switch ( V_1253 ) {
case V_1259 :
case V_1260 :
if ( V_14 -> V_10 . V_1261 != 0 )
break;
case V_1262 :
case V_1263 :
case V_1264 :
case V_1265 :
case V_1266 :
V_1257 = 1 ;
break;
}
break;
case V_1267 :
switch ( V_1253 ) {
case V_1268 :
V_1257 = 1 ;
break;
}
break;
case V_1269 :
if ( V_1253 != V_1270 )
V_1257 = 1 ;
break;
case V_1271 :
V_1257 = 1 ;
break;
case V_1272 :
case V_1273 :
case V_1274 :
case V_1275 :
case V_1276 :
case V_1277 :
if ( ( V_1254 == V_1278 ) ||
( ( V_1254 == V_1279 ) &&
( V_14 -> V_10 . V_1261 == 0 ) ) ) {
V_1257 = 1 ;
}
break;
}
return V_1257 ;
}
static void F_654 ( struct V_1 * V_2 )
{
#ifdef F_655
struct V_1280 * V_1281 = F_656 ( V_2 -> V_9 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
const unsigned char * V_586 ;
V_586 = F_657 ( V_1281 ) ;
if ( V_586 ) {
F_317 ( V_14 -> V_110 . V_1282 , V_586 ) ;
return;
}
#endif
#ifdef F_658
F_317 ( V_14 -> V_110 . V_1282 , V_1283 -> V_1284 ) ;
#endif
}
static int F_659 ( struct V_5 * V_9 , const struct V_1285 * V_1286 )
{
struct V_56 * V_57 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_14 ;
const struct V_1287 * V_1288 = V_1289 [ V_1286 -> V_1290 ] ;
int V_50 , V_17 , V_1291 , V_24 ;
unsigned int V_428 = V_1292 ;
T_4 V_1293 [ V_1294 ] ;
bool V_1295 = false ;
#ifdef F_176
T_2 V_1296 ;
#endif
T_1 V_1297 ;
if ( V_9 -> V_1252 ) {
F_660 ( 1 , V_1298 L_146 ,
F_509 ( V_9 ) , V_9 -> V_723 , V_9 -> V_196 ) ;
return - V_591 ;
}
V_17 = F_452 ( V_9 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_661 ( & V_9 -> V_75 , F_249 ( 64 ) ) ) {
V_1291 = 1 ;
} else {
V_17 = F_661 ( & V_9 -> V_75 , F_249 ( 32 ) ) ;
if ( V_17 ) {
F_428 ( & V_9 -> V_75 ,
L_147 ) ;
goto V_1299;
}
V_1291 = 0 ;
}
V_17 = F_662 ( V_9 , F_663 ( V_9 ,
V_1300 ) , V_1301 ) ;
if ( V_17 ) {
F_428 ( & V_9 -> V_75 ,
L_148 , V_17 ) ;
goto V_1302;
}
F_664 ( V_9 ) ;
F_453 ( V_9 ) ;
F_451 ( V_9 ) ;
if ( V_1288 -> V_110 == V_111 ) {
#ifdef F_378
V_428 = 4 * V_637 ;
#else
V_428 = V_1303 ;
#endif
}
V_57 = F_665 ( sizeof( struct V_1 ) , V_428 ) ;
if ( ! V_57 ) {
V_17 = - V_579 ;
goto V_1304;
}
F_666 ( V_57 , & V_9 -> V_75 ) ;
V_2 = F_89 ( V_57 ) ;
V_2 -> V_57 = V_57 ;
V_2 -> V_9 = V_9 ;
V_14 = & V_2 -> V_14 ;
V_14 -> V_40 = V_2 ;
V_2 -> V_1305 = F_667 ( V_1306 , V_1307 ) ;
V_14 -> V_41 = F_668 ( F_669 ( V_9 , 0 ) ,
F_670 ( V_9 , 0 ) ) ;
V_2 -> V_410 = V_14 -> V_41 ;
if ( ! V_14 -> V_41 ) {
V_17 = - V_776 ;
goto V_1308;
}
V_57 -> V_1309 = & V_1310 ;
F_671 ( V_57 ) ;
V_57 -> V_1311 = 5 * V_994 ;
F_672 ( V_57 -> V_55 , F_509 ( V_9 ) , sizeof( V_57 -> V_55 ) ) ;
memcpy ( & V_14 -> V_110 . V_344 , V_1288 -> V_1312 , sizeof( V_14 -> V_110 . V_344 ) ) ;
V_14 -> V_110 . type = V_1288 -> V_110 ;
V_14 -> V_1313 = V_1288 -> V_1313 ;
memcpy ( & V_14 -> V_1314 . V_344 , V_1288 -> V_1315 , sizeof( V_14 -> V_1314 . V_344 ) ) ;
V_1297 = F_37 ( V_14 , F_673 ( V_14 ) ) ;
if ( F_22 ( V_14 -> V_41 ) ) {
V_17 = - V_776 ;
goto V_1308;
}
if ( ! ( V_1297 & ( 1 << 8 ) ) )
V_14 -> V_1314 . V_344 . V_243 = & V_1316 ;
memcpy ( & V_14 -> V_347 . V_344 , V_1288 -> V_1317 , sizeof( V_14 -> V_347 . V_344 ) ) ;
V_14 -> V_347 . V_990 = V_1318 ;
V_14 -> V_347 . V_1137 . V_1134 = V_1319 ;
V_14 -> V_347 . V_1137 . V_1320 = 0 ;
V_14 -> V_347 . V_1137 . V_1321 = V_1322 | V_1323 ;
V_14 -> V_347 . V_1137 . V_75 = V_57 ;
V_14 -> V_347 . V_1137 . V_1324 = F_586 ;
V_14 -> V_347 . V_1137 . V_1325 = F_587 ;
V_1288 -> V_1326 ( V_14 ) ;
V_17 = F_411 ( V_2 ) ;
if ( V_17 )
goto V_1327;
switch ( V_2 -> V_14 . V_110 . type ) {
case V_113 :
case V_114 :
case V_115 :
case V_116 :
F_71 ( & V_2 -> V_14 , V_794 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_141 & V_351 ) {
T_1 V_698 = F_37 ( V_14 , V_699 ) ;
if ( V_698 & V_700 )
F_208 ( V_175 , L_71 ) ;
}
if ( V_1328 )
V_14 -> V_1328 = V_1328 ;
V_14 -> V_347 . V_1329 = true ;
V_17 = V_14 -> V_110 . V_344 . V_1330 ( V_14 ) ;
V_14 -> V_347 . V_1329 = false ;
if ( V_17 == V_706 ) {
V_17 = 0 ;
} else if ( V_17 == V_707 ) {
F_18 ( L_149 ) ;
F_18 ( L_150 ) ;
goto V_1327;
} else if ( V_17 ) {
F_18 ( L_151 , V_17 ) ;
goto V_1327;
}
#ifdef F_307
if ( V_2 -> V_14 . V_110 . type == V_111 )
goto V_1331;
F_674 ( V_14 ) ;
memcpy ( & V_14 -> V_1332 . V_344 , V_1288 -> V_1333 , sizeof( V_14 -> V_1332 . V_344 ) ) ;
F_675 ( V_9 , V_768 ) ;
F_676 ( V_2 ) ;
V_1331:
#endif
V_57 -> V_203 = V_1334 |
V_1335 |
V_1336 |
V_1337 |
V_254 |
V_1338 |
V_1339 |
V_204 |
V_221 ;
V_57 -> V_1340 = V_57 -> V_203 | V_1341 ;
switch ( V_2 -> V_14 . V_110 . type ) {
case V_113 :
case V_114 :
case V_115 :
case V_116 :
V_57 -> V_203 |= V_1342 ;
V_57 -> V_1340 |= V_1342 |
V_1217 |
V_1218 ;
break;
default:
break;
}
V_57 -> V_1340 |= V_279 ;
V_57 -> V_203 |= V_1343 ;
V_57 -> V_1344 |= V_1338 ;
V_57 -> V_1344 |= V_1339 ;
V_57 -> V_1344 |= V_1335 ;
V_57 -> V_1344 |= V_1336 ;
V_57 -> V_1344 |= V_1334 ;
V_57 -> V_1345 |= V_1335 | V_1336 ;
V_57 -> V_1346 |= V_1347 ;
V_57 -> V_1346 |= V_1348 ;
#ifdef F_378
V_57 -> V_1349 = & V_1349 ;
#endif
#ifdef F_176
if ( V_2 -> V_141 & V_737 ) {
unsigned int V_1350 ;
if ( V_14 -> V_110 . V_344 . V_1351 ) {
V_14 -> V_110 . V_344 . V_1351 ( V_14 , & V_1296 ) ;
if ( V_1296 & V_1352 )
V_2 -> V_141 &= ~ V_737 ;
}
V_1350 = F_325 ( int , V_1353 , F_413 () ) ;
V_2 -> V_426 [ V_1104 ] . V_730 = V_1350 ;
V_57 -> V_203 |= V_1125 |
V_1126 ;
V_57 -> V_1344 |= V_1125 |
V_1126 |
V_617 ;
}
#endif
if ( V_1291 ) {
V_57 -> V_203 |= V_1354 ;
V_57 -> V_1344 |= V_1354 ;
}
if ( V_2 -> V_156 & V_731 )
V_57 -> V_1340 |= V_1213 ;
if ( V_2 -> V_156 & V_535 )
V_57 -> V_203 |= V_1213 ;
if ( V_14 -> V_1314 . V_344 . V_1355 ( V_14 , NULL ) < 0 ) {
F_18 ( L_152 ) ;
V_17 = - V_776 ;
goto V_1327;
}
F_654 ( V_2 ) ;
memcpy ( V_57 -> V_666 , V_14 -> V_110 . V_1282 , V_57 -> V_1133 ) ;
if ( ! F_373 ( V_57 -> V_666 ) ) {
F_18 ( L_153 ) ;
V_17 = - V_776 ;
goto V_1327;
}
F_317 ( V_14 -> V_110 . V_586 , V_14 -> V_110 . V_1282 ) ;
F_314 ( V_2 ) ;
F_677 ( & V_2 -> V_701 , & F_517 ,
( unsigned long ) V_2 ) ;
if ( F_22 ( V_14 -> V_41 ) ) {
V_17 = - V_776 ;
goto V_1327;
}
F_678 ( & V_2 -> V_39 , F_521 ) ;
F_250 ( V_42 , & V_2 -> V_35 ) ;
F_34 ( V_37 , & V_2 -> V_35 ) ;
V_17 = F_456 ( V_2 ) ;
if ( V_17 )
goto V_1327;
V_2 -> V_713 = 0 ;
V_14 -> V_1314 . V_344 . V_243 ( V_14 , 0x2c , & V_2 -> V_1255 ) ;
V_14 -> V_1356 = F_653 ( V_2 , V_9 -> V_196 ,
V_9 -> V_729 ) ;
if ( V_14 -> V_1356 )
V_2 -> V_713 = V_1357 ;
F_679 ( & V_2 -> V_9 -> V_75 , V_2 -> V_713 ) ;
V_14 -> V_1314 . V_344 . V_243 ( V_14 , 0x2e , & V_2 -> V_1358 ) ;
V_14 -> V_1314 . V_344 . V_243 ( V_14 , 0x2d , & V_2 -> V_1359 ) ;
if ( F_8 ( V_14 ) )
F_5 ( V_2 ) ;
else
V_14 -> V_110 . V_344 . V_1360 ( V_14 ) ;
switch ( V_14 -> V_110 . type ) {
case V_111 :
V_24 = F_680 ( F_652 ( V_2 ) * 10 , 16 ) ;
break;
default:
V_24 = F_652 ( V_2 ) * 10 ;
break;
}
if ( V_24 > 0 )
F_9 ( V_2 , V_24 ) ;
V_17 = F_681 ( V_14 , V_1293 , sizeof( V_1293 ) ) ;
if ( V_17 )
F_672 ( V_1293 , L_7 , sizeof( V_1293 ) ) ;
if ( F_212 ( V_14 ) && V_14 -> V_347 . V_990 != V_1361 )
F_12 ( L_154 ,
V_14 -> V_110 . type , V_14 -> V_347 . type , V_14 -> V_347 . V_990 ,
V_1293 ) ;
else
F_12 ( L_155 ,
V_14 -> V_110 . type , V_14 -> V_347 . type , V_1293 ) ;
F_12 ( L_156 , V_57 -> V_666 ) ;
V_17 = V_14 -> V_110 . V_344 . V_1362 ( V_14 ) ;
if ( V_17 == V_709 ) {
F_11 ( L_93
L_157
L_158
L_159
L_97
L_98 ) ;
}
strcpy ( V_57 -> V_55 , L_160 ) ;
V_17 = F_682 ( V_57 ) ;
if ( V_17 )
goto V_1363;
F_683 ( V_9 , V_2 ) ;
if ( V_14 -> V_110 . V_344 . V_718 )
V_14 -> V_110 . V_344 . V_718 ( V_14 ) ;
F_404 ( V_57 ) ;
#ifdef F_232
if ( F_126 ( & V_9 -> V_75 ) == 0 ) {
V_2 -> V_141 |= V_181 ;
F_123 ( V_2 ) ;
}
#endif
if ( V_2 -> V_141 & V_421 ) {
F_105 ( V_175 , L_161 , V_2 -> V_311 ) ;
for ( V_50 = 0 ; V_50 < V_2 -> V_311 ; V_50 ++ )
F_684 ( V_9 , ( V_50 | 0x10000000 ) ) ;
}
if ( V_14 -> V_110 . V_344 . V_1364 )
V_14 -> V_110 . V_344 . V_1364 ( V_14 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_593 ( V_57 ) ;
F_12 ( L_70 , V_1365 ) ;
#ifdef F_685
if ( F_686 ( V_2 ) )
F_103 ( V_175 , L_162 ) ;
#endif
F_687 ( V_2 ) ;
if ( F_688 ( V_14 ) && F_212 ( V_14 ) && V_14 -> V_110 . V_344 . V_679 )
V_14 -> V_110 . V_344 . V_679 ( V_14 ,
V_942 | V_967 ,
true ) ;
return 0 ;
V_1363:
F_70 ( V_2 ) ;
F_462 ( V_2 ) ;
V_1327:
F_689 ( V_2 ) ;
V_2 -> V_156 &= ~ V_674 ;
F_690 ( V_2 -> V_410 ) ;
F_241 ( V_2 -> V_581 ) ;
V_1308:
V_1295 = ! F_15 ( V_793 , & V_2 -> V_35 ) ;
F_691 ( V_57 ) ;
V_1304:
F_692 ( V_9 ,
F_663 ( V_9 , V_1300 ) ) ;
V_1302:
V_1299:
if ( ! V_2 || V_1295 )
F_463 ( V_9 ) ;
return V_17 ;
}
static void F_693 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_448 ( V_9 ) ;
struct V_56 * V_57 ;
bool V_1295 ;
if ( ! V_2 )
return;
V_57 = V_2 -> V_57 ;
F_694 ( V_2 ) ;
F_250 ( V_36 , & V_2 -> V_35 ) ;
F_695 ( & V_2 -> V_39 ) ;
#ifdef F_232
if ( V_2 -> V_141 & V_181 ) {
V_2 -> V_141 &= ~ V_181 ;
F_127 ( & V_9 -> V_75 ) ;
F_71 ( & V_2 -> V_14 , V_192 ,
V_194 ) ;
}
#endif
#ifdef F_685
F_696 ( V_2 ) ;
#endif
F_595 ( V_57 ) ;
#ifdef F_307
F_689 ( V_2 ) ;
#endif
if ( V_57 -> V_991 == V_992 )
F_515 ( V_57 ) ;
F_462 ( V_2 ) ;
F_70 ( V_2 ) ;
#ifdef F_697
F_241 ( V_2 -> V_140 ) ;
F_241 ( V_2 -> V_622 ) ;
#endif
F_690 ( V_2 -> V_410 ) ;
F_692 ( V_9 , F_663 ( V_9 ,
V_1300 ) ) ;
F_12 ( L_163 ) ;
F_241 ( V_2 -> V_581 ) ;
V_1295 = ! F_15 ( V_793 , & V_2 -> V_35 ) ;
F_691 ( V_57 ) ;
F_698 ( V_9 ) ;
if ( V_1295 )
F_463 ( V_9 ) ;
}
static T_21 F_699 ( struct V_5 * V_9 ,
T_22 V_35 )
{
struct V_1 * V_2 = F_448 ( V_9 ) ;
struct V_56 * V_57 = V_2 -> V_57 ;
#ifdef F_307
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_1366 , * V_974 ;
T_1 V_1367 , V_1368 , V_1369 , V_1370 ;
int V_977 , V_1371 ;
T_2 V_1372 , V_1373 ;
if ( V_2 -> V_14 . V_110 . type == V_111 ||
V_2 -> V_311 == 0 )
goto V_1374;
V_1366 = V_9 -> V_10 -> V_12 ;
while ( V_1366 && ( F_700 ( V_1366 ) != V_1375 ) )
V_1366 = V_1366 -> V_10 -> V_12 ;
if ( ! V_1366 )
goto V_1374;
V_1371 = F_701 ( V_1366 , V_1376 ) ;
if ( ! V_1371 )
goto V_1374;
V_1367 = F_27 ( V_14 , V_1371 + V_1377 ) ;
V_1368 = F_27 ( V_14 , V_1371 + V_1377 + 4 ) ;
V_1369 = F_27 ( V_14 , V_1371 + V_1377 + 8 ) ;
V_1370 = F_27 ( V_14 , V_1371 + V_1377 + 12 ) ;
if ( F_22 ( V_14 -> V_41 ) )
goto V_1374;
V_1372 = V_1368 >> 16 ;
if ( ! ( V_1372 & 0x0080 ) )
goto V_1374;
V_1373 = V_1372 & 0x01 ;
if ( ( V_1373 & 1 ) == ( V_9 -> V_1378 & 1 ) ) {
unsigned int V_21 ;
V_977 = ( V_1372 & 0x7F ) >> 1 ;
F_18 ( L_164 , V_977 ) ;
F_18 ( L_165
L_166 ,
V_1367 , V_1368 , V_1369 , V_1370 ) ;
switch ( V_2 -> V_14 . V_110 . type ) {
case V_113 :
V_21 = V_1379 ;
break;
case V_114 :
V_21 = V_1380 ;
break;
case V_115 :
V_21 = V_1381 ;
break;
case V_116 :
V_21 = V_1382 ;
break;
default:
V_21 = 0 ;
break;
}
V_974 = F_702 ( V_1383 , V_21 , NULL ) ;
while ( V_974 ) {
if ( V_974 -> V_1378 == ( V_1372 & 0xFF ) )
break;
V_974 = F_702 ( V_1383 ,
V_21 , V_974 ) ;
}
if ( V_974 ) {
F_507 ( V_2 , V_974 ) ;
F_703 ( V_974 ) ;
}
F_704 ( V_9 ) ;
}
V_2 -> V_1384 ++ ;
return V_1385 ;
V_1374:
#endif
if ( ! F_14 ( V_42 , & V_2 -> V_35 ) )
return V_1386 ;
F_455 () ;
F_461 ( V_57 ) ;
if ( V_35 == V_1387 ) {
F_457 () ;
return V_1386 ;
}
if ( F_57 ( V_57 ) )
F_392 ( V_2 ) ;
if ( ! F_15 ( V_793 , & V_2 -> V_35 ) )
F_463 ( V_9 ) ;
F_457 () ;
return V_1388 ;
}
static T_21 F_705 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_448 ( V_9 ) ;
T_21 V_1389 ;
int V_17 ;
if ( F_452 ( V_9 ) ) {
F_103 ( V_175 , L_167 ) ;
V_1389 = V_1386 ;
} else {
F_33 () ;
F_34 ( V_793 , & V_2 -> V_35 ) ;
V_2 -> V_14 . V_41 = V_2 -> V_410 ;
F_453 ( V_9 ) ;
F_450 ( V_9 ) ;
F_451 ( V_9 ) ;
F_454 ( V_9 , false ) ;
F_395 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_794 , ~ 0 ) ;
V_1389 = V_1385 ;
}
V_17 = F_704 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_168
L_169 , V_17 ) ;
}
return V_1389 ;
}
static void F_706 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_448 ( V_9 ) ;
struct V_56 * V_57 = V_2 -> V_57 ;
#ifdef F_307
if ( V_2 -> V_1384 ) {
F_105 ( V_158 , L_170 ) ;
V_2 -> V_1384 -- ;
return;
}
#endif
if ( F_57 ( V_57 ) )
F_394 ( V_2 ) ;
F_458 ( V_57 ) ;
}
static int T_23 F_707 ( void )
{
int V_595 ;
F_51 ( L_171 , V_1390 , V_1391 ) ;
F_51 ( L_70 , V_1392 ) ;
V_38 = F_708 ( V_1301 ) ;
if ( ! V_38 ) {
F_52 ( L_172 , V_1301 ) ;
return - V_579 ;
}
F_709 () ;
V_595 = F_710 ( & V_1393 ) ;
if ( V_595 ) {
F_711 () ;
return V_595 ;
}
#ifdef F_232
F_712 ( & V_1394 ) ;
#endif
return 0 ;
}
static void T_24 F_713 ( void )
{
#ifdef F_232
F_714 ( & V_1394 ) ;
#endif
F_715 ( & V_1393 ) ;
F_711 () ;
if ( V_38 ) {
F_716 ( V_38 ) ;
V_38 = NULL ;
}
}
static int F_717 ( struct V_1395 * V_1396 , unsigned long V_197 ,
void * V_1129 )
{
int V_1397 ;
V_1397 = F_718 ( & V_1393 . V_1398 , NULL , & V_197 ,
F_124 ) ;
return V_1397 ? V_1399 : V_1400 ;
}
