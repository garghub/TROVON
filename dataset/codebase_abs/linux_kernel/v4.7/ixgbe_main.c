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
F_60 ( V_62 ) ,
V_62 -> V_81 ) ;
}
F_59 ( & V_2 -> V_9 -> V_80 , L_24 ) ;
F_54 ( L_25 ) ;
for ( V_55 = (struct V_54 * ) V_82 ;
V_55 -> V_60 ; V_55 ++ ) {
F_38 ( V_14 , V_55 ) ;
}
if ( ! V_62 || ! F_61 ( V_62 ) )
return;
F_59 ( & V_2 -> V_9 -> V_80 , L_26 ) ;
F_54 ( L_27 ,
L_28 ,
L_29 , L_30 , L_31 ) ;
for ( V_63 = 0 ; V_63 < V_2 -> V_83 ; V_63 ++ ) {
V_65 = V_2 -> V_65 [ V_63 ] ;
V_67 = & V_65 -> V_84 [ V_65 -> V_85 ] ;
F_54 ( L_32 ,
V_63 , V_65 -> V_86 , V_65 -> V_85 ,
( T_6 ) F_62 ( V_67 , V_87 ) ,
F_63 ( V_67 , V_88 ) ,
V_67 -> V_89 ,
( T_6 ) V_67 -> V_90 ) ;
}
if ( ! F_64 ( V_2 ) )
goto V_91;
F_59 ( & V_2 -> V_9 -> V_80 , L_33 ) ;
for ( V_63 = 0 ; V_63 < V_2 -> V_83 ; V_63 ++ ) {
V_65 = V_2 -> V_65 [ V_63 ] ;
F_54 ( L_34 ) ;
F_54 ( L_35 , V_65 -> V_92 ) ;
F_54 ( L_34 ) ;
F_54 ( L_36 ,
L_37 ,
L_38 ,
L_29 , L_30 , L_31 , L_39 ) ;
for ( V_49 = 0 ; V_65 -> V_93 && ( V_49 < V_65 -> V_94 ) ; V_49 ++ ) {
V_69 = F_65 ( V_65 , V_49 ) ;
V_67 = & V_65 -> V_84 [ V_49 ] ;
V_73 = (struct V_70 * ) V_69 ;
if ( F_63 ( V_67 , V_88 ) > 0 ) {
F_54 ( L_40 ,
V_49 ,
F_66 ( V_73 -> V_71 ) ,
F_66 ( V_73 -> V_72 ) ,
( T_6 ) F_62 ( V_67 , V_87 ) ,
F_63 ( V_67 , V_88 ) ,
V_67 -> V_89 ,
( T_6 ) V_67 -> V_90 ,
V_67 -> V_95 ) ;
if ( V_49 == V_65 -> V_86 &&
V_49 == V_65 -> V_85 )
F_56 ( L_41 ) ;
else if ( V_49 == V_65 -> V_86 )
F_56 ( L_42 ) ;
else if ( V_49 == V_65 -> V_85 )
F_56 ( L_43 ) ;
else
F_56 ( L_19 ) ;
if ( F_67 ( V_2 ) &&
V_67 -> V_95 )
F_68 ( V_96 , L_44 ,
V_97 , 16 , 1 ,
V_67 -> V_95 -> V_98 ,
F_63 ( V_67 , V_88 ) ,
true ) ;
}
}
}
V_91:
F_59 ( & V_2 -> V_9 -> V_80 , L_45 ) ;
F_54 ( L_46 ) ;
for ( V_63 = 0 ; V_63 < V_2 -> V_99 ; V_63 ++ ) {
V_74 = V_2 -> V_74 [ V_63 ] ;
F_54 ( L_47 ,
V_63 , V_74 -> V_86 , V_74 -> V_85 ) ;
}
if ( ! F_69 ( V_2 ) )
return;
F_59 ( & V_2 -> V_9 -> V_80 , L_48 ) ;
for ( V_63 = 0 ; V_63 < V_2 -> V_99 ; V_63 ++ ) {
V_74 = V_2 -> V_74 [ V_63 ] ;
F_54 ( L_34 ) ;
F_54 ( L_49 , V_74 -> V_92 ) ;
F_54 ( L_34 ) ;
F_54 ( L_50 ,
L_51 ,
L_52 ,
L_53 ) ;
F_54 ( L_50 ,
L_54 ,
L_55 ,
L_56 ) ;
for ( V_49 = 0 ; V_49 < V_74 -> V_94 ; V_49 ++ ) {
V_78 = & V_74 -> V_78 [ V_49 ] ;
V_76 = F_70 ( V_74 , V_49 ) ;
V_73 = (struct V_70 * ) V_76 ;
V_79 = F_71 ( V_76 -> V_100 . V_101 . V_102 ) ;
if ( V_79 & V_103 ) {
F_54 ( L_57
L_58 , V_49 ,
F_66 ( V_73 -> V_71 ) ,
F_66 ( V_73 -> V_72 ) ,
V_78 -> V_95 ) ;
} else {
F_54 ( L_59
L_60 , V_49 ,
F_66 ( V_73 -> V_71 ) ,
F_66 ( V_73 -> V_72 ) ,
( T_6 ) V_78 -> V_87 ,
V_78 -> V_95 ) ;
if ( F_67 ( V_2 ) &&
V_78 -> V_87 ) {
F_68 ( V_96 , L_44 ,
V_97 , 16 , 1 ,
F_72 ( V_78 -> V_104 ) +
V_78 -> V_105 ,
F_73 ( V_74 ) , true ) ;
}
}
if ( V_49 == V_74 -> V_86 )
F_56 ( L_42 ) ;
else if ( V_49 == V_74 -> V_85 )
F_56 ( L_43 ) ;
else
F_56 ( L_19 ) ;
}
}
}
static void F_74 ( struct V_1 * V_2 )
{
T_1 V_106 ;
V_106 = F_40 ( & V_2 -> V_14 , V_107 ) ;
F_75 ( & V_2 -> V_14 , V_107 ,
V_106 & ~ V_108 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
T_1 V_106 ;
V_106 = F_40 ( & V_2 -> V_14 , V_107 ) ;
F_75 ( & V_2 -> V_14 , V_107 ,
V_106 | V_108 ) ;
}
static void F_77 ( struct V_1 * V_2 , T_7 V_109 ,
T_4 V_110 , T_4 V_111 )
{
T_1 V_112 , V_113 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_111 |= V_116 ;
if ( V_109 == - 1 )
V_109 = 0 ;
V_113 = ( ( ( V_109 * 64 ) + V_110 ) >> 2 ) & 0x1F ;
V_112 = F_40 ( V_14 , F_78 ( V_113 ) ) ;
V_112 &= ~ ( 0xFF << ( 8 * ( V_110 & 0x3 ) ) ) ;
V_112 |= ( V_111 << ( 8 * ( V_110 & 0x3 ) ) ) ;
F_75 ( V_14 , F_78 ( V_113 ) , V_112 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
if ( V_109 == - 1 ) {
V_111 |= V_116 ;
V_113 = ( ( V_110 & 1 ) * 8 ) ;
V_112 = F_40 ( & V_2 -> V_14 , V_122 ) ;
V_112 &= ~ ( 0xFF << V_113 ) ;
V_112 |= ( V_111 << V_113 ) ;
F_75 ( & V_2 -> V_14 , V_122 , V_112 ) ;
break;
} else {
V_111 |= V_116 ;
V_113 = ( ( 16 * ( V_110 & 1 ) ) + ( 8 * V_109 ) ) ;
V_112 = F_40 ( V_14 , F_78 ( V_110 >> 1 ) ) ;
V_112 &= ~ ( 0xFF << V_113 ) ;
V_112 |= ( V_111 << V_113 ) ;
F_75 ( V_14 , F_78 ( V_110 >> 1 ) , V_112 ) ;
break;
}
default:
break;
}
}
static inline void F_79 ( struct V_1 * V_2 ,
T_6 V_123 )
{
T_1 V_124 ;
switch ( V_2 -> V_14 . V_114 . type ) {
case V_115 :
V_124 = ( V_125 & V_123 ) ;
F_75 ( & V_2 -> V_14 , V_126 , V_124 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_124 = ( V_123 & 0xFFFFFFFF ) ;
F_75 ( & V_2 -> V_14 , F_80 ( 0 ) , V_124 ) ;
V_124 = ( V_123 >> 32 ) ;
F_75 ( & V_2 -> V_14 , F_80 ( 1 ) , V_124 ) ;
break;
default:
break;
}
}
void F_81 ( struct V_64 * V_127 ,
struct V_66 * V_67 )
{
if ( V_67 -> V_95 ) {
F_82 ( V_67 -> V_95 ) ;
if ( F_63 ( V_67 , V_88 ) )
F_83 ( V_127 -> V_80 ,
F_62 ( V_67 , V_87 ) ,
F_63 ( V_67 , V_88 ) ,
V_128 ) ;
} else if ( F_63 ( V_67 , V_88 ) ) {
F_84 ( V_127 -> V_80 ,
F_62 ( V_67 , V_87 ) ,
F_63 ( V_67 , V_88 ) ,
V_128 ) ;
}
V_67 -> V_89 = NULL ;
V_67 -> V_95 = NULL ;
F_85 ( V_67 , V_88 , 0 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_129 * V_130 = & V_2 -> V_131 ;
int V_49 ;
T_1 V_98 ;
if ( ( V_14 -> V_132 . V_133 != V_134 ) &&
( V_14 -> V_132 . V_133 != V_135 ) )
return;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_98 = F_40 ( V_14 , V_136 ) ;
break;
default:
V_98 = F_40 ( V_14 , V_137 ) ;
}
V_130 -> V_138 += V_98 ;
if ( ! V_98 )
return;
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ )
F_37 ( V_139 ,
& V_2 -> V_65 [ V_49 ] -> V_35 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_129 * V_130 = & V_2 -> V_131 ;
T_1 V_140 [ 8 ] = { 0 } ;
T_4 V_141 ;
int V_49 ;
bool V_142 = V_2 -> V_143 . V_144 ;
if ( V_2 -> V_145 )
V_142 |= ! ! ( V_2 -> V_145 -> V_142 ) ;
if ( ! ( V_2 -> V_146 & V_147 ) || ! V_142 ) {
F_86 ( V_2 ) ;
return;
}
for ( V_49 = 0 ; V_49 < V_148 ; V_49 ++ ) {
T_1 V_149 ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_149 = F_40 ( V_14 , F_88 ( V_49 ) ) ;
break;
default:
V_149 = F_40 ( V_14 , F_89 ( V_49 ) ) ;
}
V_130 -> V_149 [ V_49 ] += V_149 ;
V_141 = F_90 ( V_2 -> V_62 , V_49 ) ;
V_140 [ V_141 ] += V_149 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ ) {
struct V_64 * V_65 = V_2 -> V_65 [ V_49 ] ;
V_141 = V_65 -> V_150 ;
if ( V_140 [ V_141 ] )
F_37 ( V_139 , & V_65 -> V_35 ) ;
}
}
static T_6 F_91 ( struct V_64 * V_127 )
{
return V_127 -> V_131 . V_151 ;
}
static T_6 F_92 ( struct V_64 * V_127 )
{
struct V_1 * V_2 ;
struct V_15 * V_14 ;
T_1 V_152 , V_153 ;
if ( V_127 -> V_154 )
V_2 = V_127 -> V_154 -> V_155 ;
else
V_2 = F_93 ( V_127 -> V_62 ) ;
V_14 = & V_2 -> V_14 ;
V_152 = F_40 ( V_14 , F_51 ( V_127 -> V_156 ) ) ;
V_153 = F_40 ( V_14 , F_52 ( V_127 -> V_156 ) ) ;
if ( V_152 != V_153 )
return ( V_152 < V_153 ) ?
V_153 - V_152 : ( V_153 + V_127 -> V_94 - V_152 ) ;
return 0 ;
}
static inline bool F_94 ( struct V_64 * V_65 )
{
T_1 V_157 = F_91 ( V_65 ) ;
T_1 V_158 = V_65 -> V_159 . V_158 ;
T_1 V_160 = F_92 ( V_65 ) ;
F_95 ( V_65 ) ;
if ( V_158 == V_157 && V_160 )
return F_15 ( V_139 ,
& V_65 -> V_35 ) ;
V_65 -> V_159 . V_158 = V_157 ;
F_37 ( V_139 , & V_65 -> V_35 ) ;
return false ;
}
static void F_96 ( struct V_1 * V_2 )
{
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_161 |= V_162 ;
F_27 ( V_163 , L_61 ) ;
F_13 ( V_2 ) ;
}
}
static int F_97 ( struct V_61 * V_62 ,
int V_92 , T_1 V_164 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_165 = F_98 ( V_2 ) ;
if ( ! V_164 )
return 0 ;
V_165 <<= V_166 ;
V_165 /= V_164 ;
V_165 &= V_167 |
V_168 ;
V_165 |= V_169 ;
F_75 ( V_14 , V_170 , V_92 ) ;
F_75 ( V_14 , V_171 , V_165 ) ;
return 0 ;
}
static bool F_99 ( struct V_172 * V_173 ,
struct V_64 * V_65 , int V_174 )
{
struct V_1 * V_2 = V_173 -> V_2 ;
struct V_66 * V_67 ;
union V_68 * V_69 ;
unsigned int V_175 = 0 , V_176 = 0 ;
unsigned int V_177 = V_173 -> V_178 . V_179 ;
unsigned int V_49 = V_65 -> V_85 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return true ;
V_67 = & V_65 -> V_84 [ V_49 ] ;
V_69 = F_65 ( V_65 , V_49 ) ;
V_49 -= V_65 -> V_94 ;
do {
union V_68 * V_180 = V_67 -> V_89 ;
if ( ! V_180 )
break;
F_100 () ;
if ( ! ( V_180 -> V_100 . V_181 & F_101 ( V_182 ) ) )
break;
V_67 -> V_89 = NULL ;
V_175 += V_67 -> V_183 ;
V_176 += V_67 -> V_184 ;
F_102 ( V_67 -> V_95 , V_174 ) ;
F_83 ( V_65 -> V_80 ,
F_62 ( V_67 , V_87 ) ,
F_63 ( V_67 , V_88 ) ,
V_128 ) ;
V_67 -> V_95 = NULL ;
F_85 ( V_67 , V_88 , 0 ) ;
while ( V_69 != V_180 ) {
V_67 ++ ;
V_69 ++ ;
V_49 ++ ;
if ( F_23 ( ! V_49 ) ) {
V_49 -= V_65 -> V_94 ;
V_67 = V_65 -> V_84 ;
V_69 = F_65 ( V_65 , 0 ) ;
}
if ( F_63 ( V_67 , V_88 ) ) {
F_84 ( V_65 -> V_80 ,
F_62 ( V_67 , V_87 ) ,
F_63 ( V_67 , V_88 ) ,
V_128 ) ;
F_85 ( V_67 , V_88 , 0 ) ;
}
}
V_67 ++ ;
V_69 ++ ;
V_49 ++ ;
if ( F_23 ( ! V_49 ) ) {
V_49 -= V_65 -> V_94 ;
V_67 = V_65 -> V_84 ;
V_69 = F_65 ( V_65 , 0 ) ;
}
F_103 ( V_69 ) ;
V_177 -- ;
} while ( F_25 ( V_177 ) );
V_49 += V_65 -> V_94 ;
V_65 -> V_85 = V_49 ;
F_104 ( & V_65 -> V_185 ) ;
V_65 -> V_131 . V_186 += V_175 ;
V_65 -> V_131 . V_151 += V_176 ;
F_105 ( & V_65 -> V_185 ) ;
V_173 -> V_178 . V_175 += V_175 ;
V_173 -> V_178 . V_176 += V_176 ;
if ( F_106 ( V_65 ) && F_94 ( V_65 ) ) {
struct V_15 * V_14 = & V_2 -> V_14 ;
F_107 ( V_163 , L_62
L_63
L_64
L_65
L_66
L_67
L_68
L_69 ,
V_65 -> V_92 ,
F_40 ( V_14 , F_51 ( V_65 -> V_156 ) ) ,
F_40 ( V_14 , F_52 ( V_65 -> V_156 ) ) ,
V_65 -> V_86 , V_49 ,
V_65 -> V_84 [ V_49 ] . V_90 , V_187 ) ;
F_108 ( V_65 -> V_62 , V_65 -> V_92 ) ;
F_109 ( V_188 ,
L_70 ,
V_2 -> V_189 + 1 , V_65 -> V_92 ) ;
F_96 ( V_2 ) ;
return true ;
}
F_110 ( F_111 ( V_65 ) ,
V_176 , V_175 ) ;
#define F_112 (DESC_NEEDED * 2)
if ( F_23 ( V_176 && F_113 ( V_65 -> V_62 ) &&
( F_114 ( V_65 ) >= F_112 ) ) ) {
F_115 () ;
if ( F_116 ( V_65 -> V_62 ,
V_65 -> V_92 )
&& ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_117 ( V_65 -> V_62 ,
V_65 -> V_92 ) ;
++ V_65 -> V_159 . V_190 ;
}
}
return ! ! V_177 ;
}
static void F_118 ( struct V_1 * V_2 ,
struct V_64 * V_65 ,
int V_191 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_192 = 0 ;
T_2 V_193 ;
if ( V_2 -> V_146 & V_194 )
V_192 = F_119 ( V_65 -> V_80 , V_191 ) ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_193 = F_120 ( V_65 -> V_156 ) ;
break;
case V_117 :
case V_118 :
V_193 = F_121 ( V_65 -> V_156 ) ;
V_192 <<= V_195 ;
break;
default:
return;
}
V_192 |= V_196 |
V_197 |
V_198 ;
F_75 ( V_14 , V_193 , V_192 ) ;
}
static void F_122 ( struct V_1 * V_2 ,
struct V_64 * V_74 ,
int V_191 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_199 = 0 ;
T_4 V_156 = V_74 -> V_156 ;
if ( V_2 -> V_146 & V_194 )
V_199 = F_119 ( V_74 -> V_80 , V_191 ) ;
switch ( V_14 -> V_114 . type ) {
case V_117 :
case V_118 :
V_199 <<= V_200 ;
break;
default:
break;
}
V_199 |= V_201 |
V_202 |
V_203 ;
F_75 ( V_14 , F_41 ( V_156 ) , V_199 ) ;
}
static void F_123 ( struct V_172 * V_173 )
{
struct V_1 * V_2 = V_173 -> V_2 ;
struct V_64 * V_127 ;
int V_191 = F_124 () ;
if ( V_173 -> V_191 == V_191 )
goto V_204;
F_125 (ring, q_vector->tx)
F_118 ( V_2 , V_127 , V_191 ) ;
F_125 (ring, q_vector->rx)
F_122 ( V_2 , V_127 , V_191 ) ;
V_173 -> V_191 = V_191 ;
V_204:
F_126 () ;
}
static void F_127 ( struct V_1 * V_2 )
{
int V_49 ;
if ( V_2 -> V_146 & V_194 )
F_75 ( & V_2 -> V_14 , V_205 ,
V_206 ) ;
else
F_75 ( & V_2 -> V_14 , V_205 ,
V_207 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_208 ; V_49 ++ ) {
V_2 -> V_173 [ V_49 ] -> V_191 = - 1 ;
F_123 ( V_2 -> V_173 [ V_49 ] ) ;
}
}
static int F_128 ( struct V_209 * V_80 , void * V_98 )
{
struct V_1 * V_2 = F_129 ( V_80 ) ;
unsigned long V_210 = * ( unsigned long * ) V_98 ;
if ( ! ( V_2 -> V_146 & V_211 ) )
return 0 ;
switch ( V_210 ) {
case V_212 :
if ( V_2 -> V_146 & V_194 )
break;
if ( F_130 ( V_80 ) == 0 ) {
V_2 -> V_146 |= V_194 ;
F_75 ( & V_2 -> V_14 , V_205 ,
V_206 ) ;
break;
}
case V_213 :
if ( V_2 -> V_146 & V_194 ) {
F_131 ( V_80 ) ;
V_2 -> V_146 &= ~ V_194 ;
F_75 ( & V_2 -> V_14 , V_205 ,
V_207 ) ;
}
break;
}
return 0 ;
}
static inline void F_132 ( struct V_64 * V_127 ,
union V_75 * V_76 ,
struct V_214 * V_95 )
{
T_2 V_215 ;
if ( ! ( V_127 -> V_62 -> V_216 & V_217 ) )
return;
V_215 = F_133 ( V_76 -> V_100 . V_218 . V_219 . V_220 . V_221 ) &
V_222 ;
if ( ! V_215 )
return;
F_134 ( V_95 , F_71 ( V_76 -> V_100 . V_218 . V_223 . V_224 ) ,
( V_225 & ( 1ul << V_215 ) ) ?
V_226 : V_227 ) ;
}
static inline bool F_135 ( struct V_64 * V_127 ,
union V_75 * V_76 )
{
T_8 V_221 = V_76 -> V_100 . V_218 . V_219 . V_220 . V_221 ;
return F_14 ( V_228 , & V_127 -> V_35 ) &&
( ( V_221 & F_136 ( V_229 ) ) ==
( F_136 ( V_230 <<
V_231 ) ) ) ;
}
static inline void F_137 ( struct V_64 * V_127 ,
union V_75 * V_76 ,
struct V_214 * V_95 )
{
T_8 V_221 = V_76 -> V_100 . V_218 . V_219 . V_220 . V_221 ;
T_8 V_232 = V_76 -> V_100 . V_218 . V_219 . V_220 . V_232 ;
bool V_233 = false ;
F_138 ( V_95 ) ;
if ( ! ( V_127 -> V_62 -> V_216 & V_234 ) )
return;
if ( ( V_221 & F_136 ( V_235 ) ) &&
( V_232 & F_136 ( V_236 >> 16 ) ) ) {
V_233 = true ;
V_95 -> V_237 = 1 ;
}
if ( F_139 ( V_76 , V_238 ) &&
F_139 ( V_76 , V_239 ) ) {
V_127 -> V_240 . V_241 ++ ;
return;
}
if ( ! F_139 ( V_76 , V_242 ) )
return;
if ( F_139 ( V_76 , V_243 ) ) {
if ( ( V_221 & F_136 ( V_244 ) ) &&
F_14 ( V_245 , & V_127 -> V_35 ) )
return;
V_127 -> V_240 . V_241 ++ ;
return;
}
V_95 -> V_246 = V_247 ;
if ( V_233 ) {
if ( ! F_139 ( V_76 , V_248 ) )
return;
if ( F_139 ( V_76 , V_249 ) ) {
V_95 -> V_246 = V_250 ;
return;
}
V_95 -> V_251 = 1 ;
}
}
static bool F_140 ( struct V_64 * V_74 ,
struct V_77 * V_252 )
{
struct V_104 * V_104 = V_252 -> V_104 ;
T_9 V_87 ;
if ( F_25 ( V_104 ) )
return true ;
V_104 = F_141 ( F_142 ( V_74 ) ) ;
if ( F_23 ( ! V_104 ) ) {
V_74 -> V_240 . V_253 ++ ;
return false ;
}
V_87 = F_143 ( V_74 -> V_80 , V_104 , 0 ,
F_144 ( V_74 ) , V_254 ) ;
if ( F_145 ( V_74 -> V_80 , V_87 ) ) {
F_146 ( V_104 , F_142 ( V_74 ) ) ;
V_74 -> V_240 . V_253 ++ ;
return false ;
}
V_252 -> V_87 = V_87 ;
V_252 -> V_104 = V_104 ;
V_252 -> V_105 = 0 ;
return true ;
}
void F_147 ( struct V_64 * V_74 , T_2 V_255 )
{
union V_75 * V_76 ;
struct V_77 * V_252 ;
T_2 V_49 = V_74 -> V_86 ;
if ( ! V_255 )
return;
V_76 = F_70 ( V_74 , V_49 ) ;
V_252 = & V_74 -> V_78 [ V_49 ] ;
V_49 -= V_74 -> V_94 ;
do {
if ( ! F_140 ( V_74 , V_252 ) )
break;
V_76 -> V_256 . V_257 = F_148 ( V_252 -> V_87 + V_252 -> V_105 ) ;
V_76 ++ ;
V_252 ++ ;
V_49 ++ ;
if ( F_23 ( ! V_49 ) ) {
V_76 = F_70 ( V_74 , 0 ) ;
V_252 = V_74 -> V_78 ;
V_49 -= V_74 -> V_94 ;
}
V_76 -> V_100 . V_101 . V_102 = 0 ;
V_255 -- ;
} while ( V_255 );
V_49 += V_74 -> V_94 ;
if ( V_74 -> V_86 != V_49 ) {
V_74 -> V_86 = V_49 ;
V_74 -> V_258 = V_49 ;
F_149 () ;
F_150 ( V_49 , V_74 -> V_153 ) ;
}
}
static void F_151 ( struct V_64 * V_127 ,
struct V_214 * V_95 )
{
T_2 V_259 = F_152 ( V_95 ) ;
F_153 ( V_95 ) -> V_260 = F_154 ( ( V_95 -> V_88 - V_259 ) ,
F_155 ( V_95 ) -> V_261 ) ;
F_153 ( V_95 ) -> V_262 = V_263 ;
}
static void F_156 ( struct V_64 * V_74 ,
struct V_214 * V_95 )
{
if ( ! F_155 ( V_95 ) -> V_261 )
return;
V_74 -> V_240 . V_264 += F_155 ( V_95 ) -> V_261 ;
V_74 -> V_240 . V_265 ++ ;
F_151 ( V_74 , V_95 ) ;
F_155 ( V_95 ) -> V_261 = 0 ;
}
static void F_157 ( struct V_64 * V_74 ,
union V_75 * V_76 ,
struct V_214 * V_95 )
{
struct V_61 * V_80 = V_74 -> V_62 ;
T_1 V_146 = V_74 -> V_173 -> V_2 -> V_146 ;
F_156 ( V_74 , V_95 ) ;
F_132 ( V_74 , V_76 , V_95 ) ;
F_137 ( V_74 , V_76 , V_95 ) ;
if ( F_23 ( V_146 & V_266 ) )
F_158 ( V_74 , V_76 , V_95 ) ;
if ( ( V_80 -> V_216 & V_267 ) &&
F_139 ( V_76 , V_268 ) ) {
T_2 V_269 = F_133 ( V_76 -> V_100 . V_101 . V_270 ) ;
F_159 ( V_95 , F_160 ( V_271 ) , V_269 ) ;
}
F_161 ( V_95 , V_74 -> V_92 ) ;
V_95 -> V_272 = F_162 ( V_95 , V_80 ) ;
}
static void F_163 ( struct V_172 * V_173 ,
struct V_214 * V_95 )
{
F_164 ( V_95 , & V_173 -> V_273 ) ;
if ( F_165 ( V_173 ) )
F_166 ( V_95 ) ;
else
F_167 ( & V_173 -> V_273 , V_95 ) ;
}
static bool F_168 ( struct V_64 * V_74 ,
union V_75 * V_76 ,
struct V_214 * V_95 )
{
T_1 V_274 = V_74 -> V_85 + 1 ;
V_274 = ( V_274 < V_74 -> V_94 ) ? V_274 : 0 ;
V_74 -> V_85 = V_274 ;
F_103 ( F_70 ( V_74 , V_274 ) ) ;
if ( F_169 ( V_74 ) ) {
T_10 V_275 = V_76 -> V_100 . V_218 . V_219 . V_98 &
F_101 ( V_276 ) ;
if ( F_23 ( V_275 ) ) {
T_1 V_277 = F_71 ( V_275 ) ;
V_277 >>= V_278 ;
F_155 ( V_95 ) -> V_261 += V_277 - 1 ;
V_274 = F_71 ( V_76 -> V_100 . V_101 . V_102 ) ;
V_274 &= V_279 ;
V_274 >>= V_280 ;
}
}
if ( F_25 ( F_139 ( V_76 , V_281 ) ) )
return false ;
V_74 -> V_78 [ V_274 ] . V_95 = V_95 ;
V_74 -> V_240 . V_282 ++ ;
return true ;
}
static void F_170 ( struct V_64 * V_74 ,
struct V_214 * V_95 )
{
struct V_283 * V_284 = & F_153 ( V_95 ) -> V_285 [ 0 ] ;
unsigned char * V_286 ;
unsigned int V_287 ;
V_286 = F_171 ( V_284 ) ;
V_287 = F_172 ( V_286 , V_288 ) ;
F_173 ( V_95 , V_286 , F_174 ( V_287 , sizeof( long ) ) ) ;
F_175 ( V_284 , V_287 ) ;
V_284 -> V_105 += V_287 ;
V_95 -> V_289 -= V_287 ;
V_95 -> V_153 += V_287 ;
}
static void F_176 ( struct V_64 * V_74 ,
struct V_214 * V_95 )
{
if ( F_23 ( F_155 ( V_95 ) -> V_290 ) ) {
F_84 ( V_74 -> V_80 , F_155 ( V_95 ) -> V_87 ,
F_144 ( V_74 ) , V_254 ) ;
F_155 ( V_95 ) -> V_290 = false ;
} else {
struct V_283 * V_284 = & F_153 ( V_95 ) -> V_285 [ 0 ] ;
F_177 ( V_74 -> V_80 ,
F_155 ( V_95 ) -> V_87 ,
V_284 -> V_105 ,
F_73 ( V_74 ) ,
V_254 ) ;
}
F_155 ( V_95 ) -> V_87 = 0 ;
}
static bool F_178 ( struct V_64 * V_74 ,
union V_75 * V_76 ,
struct V_214 * V_95 )
{
struct V_61 * V_62 = V_74 -> V_62 ;
if ( F_23 ( F_139 ( V_76 ,
V_291 ) &&
! ( V_62 -> V_216 & V_292 ) ) ) {
F_82 ( V_95 ) ;
return true ;
}
if ( F_179 ( V_95 ) )
F_170 ( V_74 , V_95 ) ;
#ifdef F_180
if ( F_135 ( V_74 , V_76 ) )
return false ;
#endif
if ( F_181 ( V_95 ) )
return true ;
return false ;
}
static void F_182 ( struct V_64 * V_74 ,
struct V_77 * V_293 )
{
struct V_77 * V_294 ;
T_2 V_295 = V_74 -> V_258 ;
V_294 = & V_74 -> V_78 [ V_295 ] ;
V_295 ++ ;
V_74 -> V_258 = ( V_295 < V_74 -> V_94 ) ? V_295 : 0 ;
* V_294 = * V_293 ;
F_183 ( V_74 -> V_80 , V_294 -> V_87 ,
V_294 -> V_105 ,
F_73 ( V_74 ) ,
V_254 ) ;
}
static inline bool F_184 ( struct V_104 * V_104 )
{
return ( F_185 ( V_104 ) != F_186 () ) || F_187 ( V_104 ) ;
}
static bool F_188 ( struct V_64 * V_74 ,
struct V_77 * V_296 ,
union V_75 * V_76 ,
struct V_214 * V_95 )
{
struct V_104 * V_104 = V_296 -> V_104 ;
unsigned int V_297 = F_133 ( V_76 -> V_100 . V_101 . V_298 ) ;
#if ( V_299 < 8192 )
unsigned int V_300 = F_73 ( V_74 ) ;
#else
unsigned int V_300 = F_174 ( V_297 , V_301 ) ;
unsigned int V_302 = F_144 ( V_74 ) -
F_73 ( V_74 ) ;
#endif
if ( ( V_297 <= V_288 ) && ! F_179 ( V_95 ) ) {
unsigned char * V_286 = F_72 ( V_104 ) + V_296 -> V_105 ;
memcpy ( F_189 ( V_95 , V_297 ) , V_286 , F_174 ( V_297 , sizeof( long ) ) ) ;
if ( F_25 ( ! F_184 ( V_104 ) ) )
return true ;
F_146 ( V_104 , F_142 ( V_74 ) ) ;
return false ;
}
F_190 ( V_95 , F_153 ( V_95 ) -> V_303 , V_104 ,
V_296 -> V_105 , V_297 , V_300 ) ;
if ( F_23 ( F_184 ( V_104 ) ) )
return false ;
#if ( V_299 < 8192 )
if ( F_23 ( F_191 ( V_104 ) != 1 ) )
return false ;
V_296 -> V_105 ^= V_300 ;
#else
V_296 -> V_105 += V_300 ;
if ( V_296 -> V_105 > V_302 )
return false ;
#endif
F_192 ( V_104 ) ;
return true ;
}
static struct V_214 * F_193 ( struct V_64 * V_74 ,
union V_75 * V_76 )
{
struct V_77 * V_296 ;
struct V_214 * V_95 ;
struct V_104 * V_104 ;
V_296 = & V_74 -> V_78 [ V_74 -> V_85 ] ;
V_104 = V_296 -> V_104 ;
F_194 ( V_104 ) ;
V_95 = V_296 -> V_95 ;
if ( F_25 ( ! V_95 ) ) {
void * V_304 = F_72 ( V_104 ) +
V_296 -> V_105 ;
F_103 ( V_304 ) ;
#if V_301 < 128
F_103 ( V_304 + V_301 ) ;
#endif
V_95 = F_195 ( & V_74 -> V_173 -> V_273 ,
V_288 ) ;
if ( F_23 ( ! V_95 ) ) {
V_74 -> V_240 . V_305 ++ ;
return NULL ;
}
F_194 ( V_95 -> V_98 ) ;
if ( F_25 ( F_139 ( V_76 , V_281 ) ) )
goto V_306;
F_155 ( V_95 ) -> V_87 = V_296 -> V_87 ;
} else {
if ( F_139 ( V_76 , V_281 ) )
F_176 ( V_74 , V_95 ) ;
V_306:
F_177 ( V_74 -> V_80 ,
V_296 -> V_87 ,
V_296 -> V_105 ,
F_73 ( V_74 ) ,
V_254 ) ;
V_296 -> V_95 = NULL ;
}
if ( F_188 ( V_74 , V_296 , V_76 , V_95 ) ) {
F_182 ( V_74 , V_296 ) ;
} else if ( F_155 ( V_95 ) -> V_87 == V_296 -> V_87 ) {
F_155 ( V_95 ) -> V_290 = true ;
} else {
F_84 ( V_74 -> V_80 , V_296 -> V_87 ,
F_144 ( V_74 ) ,
V_254 ) ;
}
V_296 -> V_104 = NULL ;
return V_95 ;
}
static int F_196 ( struct V_172 * V_173 ,
struct V_64 * V_74 ,
const int V_177 )
{
unsigned int V_307 = 0 , V_308 = 0 ;
#ifdef F_180
struct V_1 * V_2 = V_173 -> V_2 ;
int V_309 ;
unsigned int V_310 = 0 ;
#endif
T_2 V_255 = F_114 ( V_74 ) ;
while ( F_25 ( V_308 < V_177 ) ) {
union V_75 * V_76 ;
struct V_214 * V_95 ;
if ( V_255 >= V_311 ) {
F_147 ( V_74 , V_255 ) ;
V_255 = 0 ;
}
V_76 = F_70 ( V_74 , V_74 -> V_85 ) ;
if ( ! V_76 -> V_100 . V_101 . V_102 )
break;
F_197 () ;
V_95 = F_193 ( V_74 , V_76 ) ;
if ( ! V_95 )
break;
V_255 ++ ;
if ( F_168 ( V_74 , V_76 , V_95 ) )
continue;
if ( F_178 ( V_74 , V_76 , V_95 ) )
continue;
V_307 += V_95 -> V_88 ;
F_157 ( V_74 , V_76 , V_95 ) ;
#ifdef F_180
if ( F_135 ( V_74 , V_76 ) ) {
V_309 = F_198 ( V_2 , V_76 , V_95 ) ;
if ( V_309 > 0 ) {
if ( ! V_310 ) {
V_310 = V_74 -> V_62 -> V_312 -
sizeof( struct V_313 ) -
sizeof( struct V_314 ) -
sizeof( struct V_315 ) ;
if ( V_310 > 512 )
V_310 &= ~ 511 ;
}
V_307 += V_309 ;
V_308 += F_154 ( V_309 ,
V_310 ) ;
}
if ( ! V_309 ) {
F_82 ( V_95 ) ;
continue;
}
}
#endif
F_163 ( V_173 , V_95 ) ;
V_308 ++ ;
}
F_104 ( & V_74 -> V_185 ) ;
V_74 -> V_131 . V_151 += V_308 ;
V_74 -> V_131 . V_186 += V_307 ;
F_105 ( & V_74 -> V_185 ) ;
V_173 -> V_316 . V_176 += V_308 ;
V_173 -> V_316 . V_175 += V_307 ;
return V_308 ;
}
static int F_199 ( struct V_317 * V_273 )
{
struct V_172 * V_173 =
F_200 ( V_273 , struct V_172 , V_273 ) ;
struct V_1 * V_2 = V_173 -> V_2 ;
struct V_64 * V_127 ;
int V_318 = 0 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return V_319 ;
if ( ! F_201 ( V_173 ) )
return V_320 ;
F_125 (ring, q_vector->rx) {
V_318 = F_196 ( V_173 , V_127 , 4 ) ;
#ifdef F_202
if ( V_318 )
V_127 -> V_131 . V_321 += V_318 ;
else
V_127 -> V_131 . V_322 ++ ;
#endif
if ( V_318 )
break;
}
F_203 ( V_173 ) ;
return V_318 ;
}
static void F_204 ( struct V_1 * V_2 )
{
struct V_172 * V_173 ;
int V_323 ;
T_1 V_124 ;
if ( V_2 -> V_324 > 32 ) {
T_1 V_325 = F_205 ( V_2 -> V_324 - 32 ) - 1 ;
F_75 ( & V_2 -> V_14 , V_326 , V_325 ) ;
}
for ( V_323 = 0 ; V_323 < V_2 -> V_208 ; V_323 ++ ) {
struct V_64 * V_127 ;
V_173 = V_2 -> V_173 [ V_323 ] ;
F_125 (ring, q_vector->rx)
F_77 ( V_2 , 0 , V_127 -> V_156 , V_323 ) ;
F_125 (ring, q_vector->tx)
F_77 ( V_2 , 1 , V_127 -> V_156 , V_323 ) ;
F_206 ( V_173 ) ;
}
switch ( V_2 -> V_14 . V_114 . type ) {
case V_115 :
F_77 ( V_2 , - 1 , V_327 ,
V_323 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
F_77 ( V_2 , - 1 , 1 , V_323 ) ;
break;
default:
break;
}
F_75 ( & V_2 -> V_14 , F_207 ( V_323 ) , 1950 ) ;
V_124 = V_328 ;
V_124 &= ~ ( V_329 |
V_330 |
V_331 ) ;
F_75 ( & V_2 -> V_14 , V_332 , V_124 ) ;
}
static void F_208 ( struct V_172 * V_173 ,
struct V_333 * V_334 )
{
int V_186 = V_334 -> V_175 ;
int V_151 = V_334 -> V_176 ;
T_1 V_335 ;
T_6 V_336 ;
T_4 V_337 = V_334 -> V_338 ;
if ( V_151 == 0 )
return;
V_335 = V_173 -> V_338 >> 2 ;
if ( V_335 == 0 )
return;
V_336 = V_186 / V_335 ;
switch ( V_337 ) {
case V_339 :
if ( V_336 > 10 )
V_337 = V_340 ;
break;
case V_340 :
if ( V_336 > 20 )
V_337 = V_341 ;
else if ( V_336 <= 10 )
V_337 = V_339 ;
break;
case V_341 :
if ( V_336 <= 20 )
V_337 = V_340 ;
break;
}
V_334 -> V_175 = 0 ;
V_334 -> V_176 = 0 ;
V_334 -> V_338 = V_337 ;
}
void F_206 ( struct V_172 * V_173 )
{
struct V_1 * V_2 = V_173 -> V_2 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_323 = V_173 -> V_323 ;
T_1 V_342 = V_173 -> V_338 & V_343 ;
switch ( V_2 -> V_14 . V_114 . type ) {
case V_115 :
V_342 |= ( V_342 << 16 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_342 |= V_344 ;
break;
default:
break;
}
F_75 ( V_14 , F_207 ( V_323 ) , V_342 ) ;
}
static void F_209 ( struct V_172 * V_173 )
{
T_1 V_345 = V_173 -> V_338 ;
T_4 V_346 ;
F_208 ( V_173 , & V_173 -> V_178 ) ;
F_208 ( V_173 , & V_173 -> V_316 ) ;
V_346 = F_210 ( V_173 -> V_316 . V_338 , V_173 -> V_178 . V_338 ) ;
switch ( V_346 ) {
case V_339 :
V_345 = V_347 ;
break;
case V_340 :
V_345 = V_348 ;
break;
case V_341 :
V_345 = V_349 ;
break;
default:
break;
}
if ( V_345 != V_173 -> V_338 ) {
V_345 = ( 10 * V_345 * V_173 -> V_338 ) /
( ( 9 * V_345 ) + V_173 -> V_338 ) ;
V_173 -> V_338 = V_345 ;
F_206 ( V_173 ) ;
}
}
static void F_211 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_350 = V_2 -> V_351 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
if ( ! ( V_2 -> V_161 & V_352 ) &&
! ( V_2 -> V_161 & V_353 ) )
return;
V_2 -> V_161 &= ~ V_353 ;
switch ( V_14 -> V_21 ) {
case V_354 :
if ( ! ( V_350 & V_355 ) &&
! ( V_350 & V_356 ) )
return;
if ( ! ( V_350 & V_356 ) && V_14 -> V_114 . V_357 . V_358 ) {
T_1 V_20 ;
bool V_359 = false ;
V_14 -> V_114 . V_357 . V_358 ( V_14 , & V_20 , & V_359 , false ) ;
if ( V_359 )
return;
}
if ( V_14 -> V_46 . V_357 . V_360 ( V_14 ) != V_361 )
return;
break;
default:
if ( V_2 -> V_14 . V_114 . type >= V_118 )
return;
if ( ! ( V_350 & F_212 ( V_14 ) ) )
return;
break;
}
F_213 ( V_163 , L_71 , V_362 ) ;
V_2 -> V_351 = 0 ;
}
static void F_214 ( struct V_1 * V_2 , T_1 V_350 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ( V_2 -> V_146 & V_363 ) &&
( V_350 & F_215 ( V_14 ) ) ) {
F_213 ( V_188 , L_72 ) ;
F_75 ( V_14 , V_364 , F_215 ( V_14 ) ) ;
}
}
static void F_216 ( struct V_1 * V_2 , T_1 V_350 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! ( V_2 -> V_161 & V_352 ) )
return;
switch ( V_2 -> V_14 . V_114 . type ) {
case V_117 :
if ( ( ( V_350 & F_212 ( V_14 ) ) ||
( V_350 & V_356 ) ) &&
( ! F_14 ( V_34 , & V_2 -> V_35 ) ) ) {
V_2 -> V_351 = V_350 ;
V_2 -> V_161 |= V_353 ;
F_13 ( V_2 ) ;
return;
}
return;
case V_118 :
if ( ! ( V_350 & V_365 ) )
return;
break;
default:
return;
}
F_213 ( V_163 , L_71 , V_362 ) ;
}
static inline bool F_217 ( struct V_15 * V_14 )
{
switch ( V_14 -> V_114 . type ) {
case V_115 :
if ( V_14 -> V_46 . type == V_366 )
return true ;
return false ;
case V_117 :
case V_120 :
case V_121 :
switch ( V_14 -> V_114 . V_357 . V_367 ( V_14 ) ) {
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
static void F_218 ( struct V_1 * V_2 , T_1 V_350 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_370 = F_219 ( V_14 ) ;
if ( ! F_217 ( V_14 ) )
return;
if ( V_14 -> V_114 . type >= V_118 )
V_370 = V_371 ;
if ( V_350 & V_370 ) {
F_75 ( V_14 , V_364 , V_370 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_161 |= V_372 ;
V_2 -> V_373 = 0 ;
F_13 ( V_2 ) ;
}
}
if ( V_2 -> V_14 . V_114 . type == V_117 &&
( V_350 & F_215 ( V_14 ) ) ) {
F_75 ( V_14 , V_364 , F_215 ( V_14 ) ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_146 |= V_374 ;
F_13 ( V_2 ) ;
}
}
}
static void F_220 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_375 ++ ;
V_2 -> V_146 |= V_376 ;
V_2 -> V_377 = V_187 ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_75 ( V_14 , V_378 , V_379 ) ;
F_221 ( V_14 ) ;
F_13 ( V_2 ) ;
}
}
static inline void F_222 ( struct V_1 * V_2 ,
T_6 V_123 )
{
T_1 V_124 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_124 = ( V_125 & V_123 ) ;
F_75 ( V_14 , V_380 , V_124 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_124 = ( V_123 & 0xFFFFFFFF ) ;
if ( V_124 )
F_75 ( V_14 , F_223 ( 0 ) , V_124 ) ;
V_124 = ( V_123 >> 32 ) ;
if ( V_124 )
F_75 ( V_14 , F_223 ( 1 ) , V_124 ) ;
break;
default:
break;
}
}
static inline void F_224 ( struct V_1 * V_2 ,
T_6 V_123 )
{
T_1 V_124 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_124 = ( V_125 & V_123 ) ;
F_75 ( V_14 , V_378 , V_124 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_124 = ( V_123 & 0xFFFFFFFF ) ;
if ( V_124 )
F_75 ( V_14 , F_225 ( 0 ) , V_124 ) ;
V_124 = ( V_123 >> 32 ) ;
if ( V_124 )
F_75 ( V_14 , F_225 ( 1 ) , V_124 ) ;
break;
default:
break;
}
}
static inline void F_226 ( struct V_1 * V_2 , bool V_381 ,
bool V_382 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_124 = ( V_328 & ~ V_125 ) ;
if ( V_2 -> V_146 & V_376 )
V_124 &= ~ V_331 ;
if ( V_2 -> V_161 & V_352 )
switch ( V_2 -> V_14 . V_114 . type ) {
case V_117 :
V_124 |= F_227 ( V_14 ) ;
break;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_124 |= V_383 ;
break;
default:
break;
}
if ( V_2 -> V_146 & V_363 )
V_124 |= F_228 ( V_14 ) ;
switch ( V_2 -> V_14 . V_114 . type ) {
case V_117 :
V_124 |= F_228 ( V_14 ) ;
V_124 |= F_229 ( V_14 ) ;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
if ( V_2 -> V_14 . V_21 == V_384 ||
V_2 -> V_14 . V_21 == V_385 ||
V_2 -> V_14 . V_21 == V_386 )
V_124 |= F_227 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_14 . V_46 . type == V_387 )
V_124 |= V_371 ;
V_124 |= V_388 ;
V_124 |= V_330 ;
break;
default:
break;
}
if ( ( V_2 -> V_146 & V_389 ) &&
! ( V_2 -> V_161 & V_390 ) )
V_124 |= V_391 ;
F_75 ( & V_2 -> V_14 , V_380 , V_124 ) ;
if ( V_381 )
F_222 ( V_2 , ~ 0 ) ;
if ( V_382 )
F_221 ( & V_2 -> V_14 ) ;
}
static T_11 F_230 ( int V_392 , void * V_98 )
{
struct V_1 * V_2 = V_98 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_350 ;
V_350 = F_40 ( V_14 , V_126 ) ;
V_350 &= 0xFFFF0000 ;
F_75 ( V_14 , V_364 , V_350 ) ;
if ( V_350 & V_356 )
F_220 ( V_2 ) ;
if ( V_350 & V_393 )
F_231 ( V_2 ) ;
switch ( V_14 -> V_114 . type ) {
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
if ( V_14 -> V_46 . type == V_387 &&
( V_350 & V_371 ) ) {
V_2 -> V_161 |= V_394 ;
F_13 ( V_2 ) ;
F_75 ( V_14 , V_364 ,
V_371 ) ;
}
if ( V_350 & V_395 ) {
F_109 ( V_396 , L_73 ) ;
V_2 -> V_161 |= V_162 ;
F_13 ( V_2 ) ;
F_75 ( V_14 , V_364 , V_395 ) ;
}
if ( V_350 & V_397 ) {
int V_398 = 0 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ ) {
struct V_64 * V_127 = V_2 -> V_65 [ V_49 ] ;
if ( F_232 ( V_399 ,
& V_127 -> V_35 ) )
V_398 ++ ;
}
if ( V_398 ) {
F_75 ( V_14 , V_378 , V_400 ) ;
V_2 -> V_161 |= V_390 ;
F_13 ( V_2 ) ;
}
}
F_218 ( V_2 , V_350 ) ;
F_216 ( V_2 , V_350 ) ;
break;
default:
break;
}
F_214 ( V_2 , V_350 ) ;
if ( F_23 ( V_350 & V_401 ) )
F_233 ( V_2 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_226 ( V_2 , false , false ) ;
return V_402 ;
}
static T_11 F_234 ( int V_392 , void * V_98 )
{
struct V_172 * V_173 = V_98 ;
if ( V_173 -> V_316 . V_127 || V_173 -> V_178 . V_127 )
F_235 ( & V_173 -> V_273 ) ;
return V_402 ;
}
int F_236 ( struct V_317 * V_273 , int V_177 )
{
struct V_172 * V_173 =
F_200 ( V_273 , struct V_172 , V_273 ) ;
struct V_1 * V_2 = V_173 -> V_2 ;
struct V_64 * V_127 ;
int V_403 , V_404 = 0 ;
bool V_405 = true ;
#ifdef F_237
if ( V_2 -> V_146 & V_194 )
F_123 ( V_173 ) ;
#endif
F_125 (ring, q_vector->tx) {
if ( ! F_99 ( V_173 , V_127 , V_177 ) )
V_405 = false ;
}
if ( ( V_177 <= 0 ) || ! F_238 ( V_173 ) )
return V_177 ;
if ( V_173 -> V_316 . V_94 > 1 )
V_403 = F_210 ( V_177 / V_173 -> V_316 . V_94 , 1 ) ;
else
V_403 = V_177 ;
F_125 (ring, q_vector->rx) {
int V_321 = F_196 ( V_173 , V_127 ,
V_403 ) ;
V_404 += V_321 ;
if ( V_321 >= V_403 )
V_405 = false ;
}
F_239 ( V_173 ) ;
if ( ! V_405 )
return V_177 ;
F_240 ( V_273 , V_404 ) ;
if ( V_2 -> V_406 & 1 )
F_209 ( V_173 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_222 ( V_2 , F_241 ( V_173 -> V_323 ) ) ;
return F_242 ( V_404 , V_177 - 1 ) ;
}
static int F_243 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
int V_407 , V_17 ;
int V_408 = 0 , V_409 = 0 ;
for ( V_407 = 0 ; V_407 < V_2 -> V_208 ; V_407 ++ ) {
struct V_172 * V_173 = V_2 -> V_173 [ V_407 ] ;
struct V_410 * V_411 = & V_2 -> V_412 [ V_407 ] ;
if ( V_173 -> V_178 . V_127 && V_173 -> V_316 . V_127 ) {
snprintf ( V_173 -> V_60 , sizeof( V_173 -> V_60 ) - 1 ,
L_74 , V_62 -> V_60 , L_75 , V_408 ++ ) ;
V_409 ++ ;
} else if ( V_173 -> V_316 . V_127 ) {
snprintf ( V_173 -> V_60 , sizeof( V_173 -> V_60 ) - 1 ,
L_74 , V_62 -> V_60 , L_76 , V_408 ++ ) ;
} else if ( V_173 -> V_178 . V_127 ) {
snprintf ( V_173 -> V_60 , sizeof( V_173 -> V_60 ) - 1 ,
L_74 , V_62 -> V_60 , L_77 , V_409 ++ ) ;
} else {
continue;
}
V_17 = F_244 ( V_411 -> V_407 , & F_234 , 0 ,
V_173 -> V_60 , V_173 ) ;
if ( V_17 ) {
F_107 ( V_188 , L_78
L_79 , V_17 ) ;
goto V_413;
}
if ( V_2 -> V_146 & V_389 ) {
F_245 ( V_411 -> V_407 ,
& V_173 -> V_414 ) ;
}
}
V_17 = F_244 ( V_2 -> V_412 [ V_407 ] . V_407 ,
F_230 , 0 , V_62 -> V_60 , V_2 ) ;
if ( V_17 ) {
F_107 ( V_188 , L_80 , V_17 ) ;
goto V_413;
}
return 0 ;
V_413:
while ( V_407 ) {
V_407 -- ;
F_245 ( V_2 -> V_412 [ V_407 ] . V_407 ,
NULL ) ;
F_246 ( V_2 -> V_412 [ V_407 ] . V_407 ,
V_2 -> V_173 [ V_407 ] ) ;
}
V_2 -> V_146 &= ~ V_415 ;
F_247 ( V_2 -> V_9 ) ;
F_248 ( V_2 -> V_412 ) ;
V_2 -> V_412 = NULL ;
return V_17 ;
}
static T_11 F_249 ( int V_392 , void * V_98 )
{
struct V_1 * V_2 = V_98 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_172 * V_173 = V_2 -> V_173 [ 0 ] ;
T_1 V_350 ;
F_75 ( V_14 , V_378 , V_416 ) ;
V_350 = F_40 ( V_14 , V_364 ) ;
if ( ! V_350 ) {
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_226 ( V_2 , true , true ) ;
return V_417 ;
}
if ( V_350 & V_356 )
F_220 ( V_2 ) ;
switch ( V_14 -> V_114 . type ) {
case V_117 :
F_218 ( V_2 , V_350 ) ;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
if ( V_350 & V_395 ) {
F_109 ( V_396 , L_73 ) ;
V_2 -> V_161 |= V_162 ;
F_13 ( V_2 ) ;
F_75 ( V_14 , V_364 , V_395 ) ;
}
F_216 ( V_2 , V_350 ) ;
break;
default:
break;
}
F_214 ( V_2 , V_350 ) ;
if ( F_23 ( V_350 & V_401 ) )
F_233 ( V_2 ) ;
F_235 ( & V_173 -> V_273 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_226 ( V_2 , false , false ) ;
return V_402 ;
}
static int F_250 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
int V_17 ;
if ( V_2 -> V_146 & V_415 )
V_17 = F_243 ( V_2 ) ;
else if ( V_2 -> V_146 & V_418 )
V_17 = F_244 ( V_2 -> V_9 -> V_392 , F_249 , 0 ,
V_62 -> V_60 , V_2 ) ;
else
V_17 = F_244 ( V_2 -> V_9 -> V_392 , F_249 , V_419 ,
V_62 -> V_60 , V_2 ) ;
if ( V_17 )
F_107 ( V_188 , L_81 , V_17 ) ;
return V_17 ;
}
static void F_251 ( struct V_1 * V_2 )
{
int V_407 ;
if ( ! ( V_2 -> V_146 & V_415 ) ) {
F_246 ( V_2 -> V_9 -> V_392 , V_2 ) ;
return;
}
for ( V_407 = 0 ; V_407 < V_2 -> V_208 ; V_407 ++ ) {
struct V_172 * V_173 = V_2 -> V_173 [ V_407 ] ;
struct V_410 * V_411 = & V_2 -> V_412 [ V_407 ] ;
if ( ! V_173 -> V_316 . V_127 && ! V_173 -> V_178 . V_127 )
continue;
F_245 ( V_411 -> V_407 , NULL ) ;
F_246 ( V_411 -> V_407 , V_173 ) ;
}
F_246 ( V_2 -> V_412 [ V_407 ++ ] . V_407 , V_2 ) ;
}
static inline void F_252 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_114 . type ) {
case V_115 :
F_75 ( & V_2 -> V_14 , V_378 , ~ 0 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
F_75 ( & V_2 -> V_14 , V_378 , 0xFFFF0000 ) ;
F_75 ( & V_2 -> V_14 , F_225 ( 0 ) , ~ 0 ) ;
F_75 ( & V_2 -> V_14 , F_225 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_221 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_146 & V_415 ) {
int V_407 ;
for ( V_407 = 0 ; V_407 < V_2 -> V_208 ; V_407 ++ )
F_253 ( V_2 -> V_412 [ V_407 ] . V_407 ) ;
F_253 ( V_2 -> V_412 [ V_407 ++ ] . V_407 ) ;
} else {
F_253 ( V_2 -> V_9 -> V_392 ) ;
}
}
static void F_254 ( struct V_1 * V_2 )
{
struct V_172 * V_173 = V_2 -> V_173 [ 0 ] ;
F_206 ( V_173 ) ;
F_77 ( V_2 , 0 , 0 , 0 ) ;
F_77 ( V_2 , 1 , 0 , 0 ) ;
F_109 ( V_14 , L_82 ) ;
}
void F_255 ( struct V_1 * V_2 ,
struct V_64 * V_127 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_420 = V_127 -> V_87 ;
int V_421 = 10 ;
T_1 V_422 = V_423 ;
T_4 V_156 = V_127 -> V_156 ;
F_75 ( V_14 , F_53 ( V_156 ) , 0 ) ;
F_221 ( V_14 ) ;
F_75 ( V_14 , F_48 ( V_156 ) ,
( V_420 & F_256 ( 32 ) ) ) ;
F_75 ( V_14 , F_49 ( V_156 ) , ( V_420 >> 32 ) ) ;
F_75 ( V_14 , F_50 ( V_156 ) ,
V_127 -> V_94 * sizeof( union V_68 ) ) ;
F_75 ( V_14 , F_51 ( V_156 ) , 0 ) ;
F_75 ( V_14 , F_52 ( V_156 ) , 0 ) ;
V_127 -> V_153 = V_2 -> V_424 + F_52 ( V_156 ) ;
if ( ! V_127 -> V_173 || ( V_127 -> V_173 -> V_338 < V_347 ) )
V_422 |= 1u << 16 ;
else
V_422 |= 8u << 16 ;
V_422 |= ( 1u << 8 ) |
32 ;
if ( V_2 -> V_146 & V_389 ) {
V_127 -> V_425 = V_2 -> V_425 ;
V_127 -> V_426 = 0 ;
F_257 ( V_399 , & V_127 -> V_35 ) ;
} else {
V_127 -> V_425 = 0 ;
}
if ( ! F_15 ( V_427 , & V_127 -> V_35 ) ) {
struct V_172 * V_173 = V_127 -> V_173 ;
if ( V_173 )
F_258 ( V_127 -> V_62 ,
& V_173 -> V_414 ,
V_127 -> V_92 ) ;
}
F_37 ( V_139 , & V_127 -> V_35 ) ;
F_75 ( V_14 , F_53 ( V_156 ) , V_422 ) ;
if ( V_14 -> V_114 . type == V_115 &&
! ( F_40 ( V_14 , V_428 ) & V_429 ) )
return;
do {
F_259 ( 1000 , 2000 ) ;
V_422 = F_40 ( V_14 , F_53 ( V_156 ) ) ;
} while ( -- V_421 && ! ( V_422 & V_423 ) );
if ( ! V_421 )
F_107 ( V_163 , L_83 , V_156 ) ;
}
static void F_260 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_430 , V_431 ;
T_4 V_432 = F_261 ( V_2 -> V_62 ) ;
if ( V_14 -> V_114 . type == V_115 )
return;
V_430 = F_40 ( V_14 , V_433 ) ;
V_430 |= V_434 ;
F_75 ( V_14 , V_433 , V_430 ) ;
if ( V_2 -> V_146 & V_435 ) {
V_431 = V_436 ;
if ( V_432 > 4 )
V_431 |= V_437 | V_438 ;
else if ( V_432 > 1 )
V_431 |= V_437 | V_439 ;
else if ( V_2 -> V_440 [ V_441 ] . V_442 == 4 )
V_431 |= V_443 ;
else
V_431 |= V_444 ;
} else {
if ( V_432 > 4 )
V_431 = V_437 | V_438 ;
else if ( V_432 > 1 )
V_431 = V_437 | V_439 ;
else
V_431 = V_445 ;
}
F_75 ( V_14 , V_446 , V_431 ) ;
if ( V_432 ) {
T_1 V_447 = F_40 ( V_14 , V_448 ) ;
V_447 |= V_449 ;
F_75 ( V_14 , V_448 , V_447 ) ;
}
V_430 &= ~ V_434 ;
F_75 ( V_14 , V_433 , V_430 ) ;
}
static void F_262 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_450 ;
T_1 V_49 ;
F_260 ( V_2 ) ;
if ( V_14 -> V_114 . type != V_115 ) {
V_450 = F_40 ( V_14 , V_451 ) ;
V_450 |= V_452 ;
F_75 ( V_14 , V_451 , V_450 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ )
F_255 ( V_2 , V_2 -> V_65 [ V_49 ] ) ;
}
static void F_263 ( struct V_1 * V_2 ,
struct V_64 * V_127 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_156 = V_127 -> V_156 ;
T_1 V_453 = F_40 ( V_14 , F_39 ( V_156 ) ) ;
V_453 |= V_454 ;
F_75 ( V_14 , F_39 ( V_156 ) , V_453 ) ;
}
static void F_264 ( struct V_1 * V_2 ,
struct V_64 * V_127 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_156 = V_127 -> V_156 ;
T_1 V_453 = F_40 ( V_14 , F_39 ( V_156 ) ) ;
V_453 &= ~ V_454 ;
F_75 ( V_14 , F_39 ( V_156 ) , V_453 ) ;
}
static void F_265 ( struct V_1 * V_2 ,
struct V_64 * V_74 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_453 ;
T_4 V_156 = V_74 -> V_156 ;
if ( V_14 -> V_114 . type == V_115 ) {
T_2 V_124 = V_2 -> V_440 [ V_441 ] . V_124 ;
V_156 &= V_124 ;
}
V_453 = V_288 << V_455 ;
V_453 |= F_73 ( V_74 ) >> V_456 ;
V_453 |= V_457 ;
F_75 ( V_14 , F_39 ( V_156 ) , V_453 ) ;
}
T_1 F_266 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_114 . type < V_119 )
return 128 ;
else if ( V_2 -> V_146 & V_435 )
return 64 ;
else
return 512 ;
}
void F_267 ( struct V_1 * V_2 )
{
T_1 V_49 , V_458 = F_266 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_459 = 0 ;
T_1 V_460 ;
T_4 * V_461 = V_2 -> V_462 ;
if ( V_2 -> V_14 . V_114 . type == V_115 )
V_460 = 0x11 ;
else
V_460 = 0x1 ;
for ( V_49 = 0 ; V_49 < V_458 ; V_49 ++ ) {
V_459 |= V_460 * V_461 [ V_49 ] << ( V_49 & 0x3 ) * 8 ;
if ( ( V_49 & 3 ) == 3 ) {
if ( V_49 < 128 )
F_75 ( V_14 , F_268 ( V_49 >> 2 ) , V_459 ) ;
else
F_75 ( V_14 , F_269 ( ( V_49 >> 2 ) - 32 ) ,
V_459 ) ;
V_459 = 0 ;
}
}
}
static void F_270 ( struct V_1 * V_2 )
{
T_1 V_49 , V_458 = F_266 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_463 = 0 ;
unsigned int V_464 = V_2 -> V_324 ;
for ( V_49 = 0 ; V_49 < V_458 ; V_49 ++ ) {
V_463 |= ( T_1 ) V_2 -> V_462 [ V_49 ] << ( V_49 & 0x3 ) * 8 ;
if ( ( V_49 & 3 ) == 3 ) {
F_75 ( V_14 , F_271 ( V_49 >> 2 , V_464 ) ,
V_463 ) ;
V_463 = 0 ;
}
}
}
static void F_272 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_49 , V_56 ;
T_1 V_458 = F_266 ( V_2 ) ;
T_2 V_465 = V_2 -> V_440 [ V_441 ] . V_442 ;
if ( ( V_2 -> V_146 & V_435 ) && ( V_465 < 2 ) )
V_465 = 2 ;
for ( V_49 = 0 ; V_49 < 10 ; V_49 ++ )
F_75 ( V_14 , F_273 ( V_49 ) , V_2 -> V_466 [ V_49 ] ) ;
memset ( V_2 -> V_462 , 0 , sizeof( V_2 -> V_462 ) ) ;
for ( V_49 = 0 , V_56 = 0 ; V_49 < V_458 ; V_49 ++ , V_56 ++ ) {
if ( V_56 == V_465 )
V_56 = 0 ;
V_2 -> V_462 [ V_49 ] = V_56 ;
}
F_267 ( V_2 ) ;
}
static void F_274 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_465 = V_2 -> V_440 [ V_441 ] . V_442 ;
unsigned int V_464 = V_2 -> V_324 ;
int V_49 , V_56 ;
for ( V_49 = 0 ; V_49 < 10 ; V_49 ++ )
F_75 ( V_14 , F_275 ( V_49 , V_464 ) ,
V_2 -> V_466 [ V_49 ] ) ;
for ( V_49 = 0 , V_56 = 0 ; V_49 < 64 ; V_49 ++ , V_56 ++ ) {
if ( V_56 == V_465 )
V_56 = 0 ;
V_2 -> V_462 [ V_49 ] = V_56 ;
}
F_270 ( V_2 ) ;
}
static void F_276 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_467 = 0 , V_468 = 0 , V_469 = 0 ;
T_1 V_470 ;
V_470 = F_40 ( V_14 , V_471 ) ;
V_470 |= V_472 ;
F_75 ( V_14 , V_471 , V_470 ) ;
if ( V_2 -> V_14 . V_114 . type == V_115 ) {
if ( V_2 -> V_440 [ V_441 ] . V_124 )
V_467 = V_473 ;
} else {
T_4 V_432 = F_261 ( V_2 -> V_62 ) ;
if ( V_2 -> V_146 & V_435 ) {
if ( V_432 > 4 )
V_467 = V_474 ;
else if ( V_432 > 1 )
V_467 = V_475 ;
else if ( V_2 -> V_440 [ V_441 ] . V_442 == 4 )
V_467 = V_476 ;
else
V_467 = V_477 ;
} else {
if ( V_432 > 4 )
V_467 = V_478 ;
else if ( V_432 > 1 )
V_467 = V_479 ;
else
V_467 = V_473 ;
}
}
V_468 |= V_480 |
V_481 |
V_482 |
V_483 ;
if ( V_2 -> V_161 & V_484 )
V_468 |= V_485 ;
if ( V_2 -> V_161 & V_486 )
V_468 |= V_487 ;
F_277 ( V_2 -> V_466 , sizeof( V_2 -> V_466 ) ) ;
if ( ( V_14 -> V_114 . type >= V_119 ) &&
( V_2 -> V_146 & V_435 ) ) {
unsigned int V_464 = V_2 -> V_324 ;
V_467 |= V_488 ;
F_75 ( V_14 , V_489 , V_467 ) ;
F_274 ( V_2 ) ;
V_469 = V_473 ;
V_469 |= V_468 ;
F_75 ( V_14 , F_278 ( V_464 ) , V_469 ) ;
} else {
F_272 ( V_2 ) ;
V_467 |= V_468 ;
F_75 ( V_14 , V_489 , V_467 ) ;
}
}
static void F_279 ( struct V_1 * V_2 ,
struct V_64 * V_127 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_490 ;
T_4 V_156 = V_127 -> V_156 ;
if ( ! F_169 ( V_127 ) )
return;
V_490 = F_40 ( V_14 , F_280 ( V_156 ) ) ;
V_490 |= V_491 ;
V_490 |= V_492 ;
F_75 ( V_14 , F_280 ( V_156 ) , V_490 ) ;
}
static void F_281 ( struct V_1 * V_2 ,
struct V_64 * V_127 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_421 = V_493 ;
T_1 V_494 ;
T_4 V_156 = V_127 -> V_156 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
if ( V_14 -> V_114 . type == V_115 &&
! ( F_40 ( V_14 , V_428 ) & V_429 ) )
return;
do {
F_259 ( 1000 , 2000 ) ;
V_494 = F_40 ( V_14 , F_45 ( V_156 ) ) ;
} while ( -- V_421 && ! ( V_494 & V_495 ) );
if ( ! V_421 ) {
F_107 ( V_163 , L_84
L_85 , V_156 ) ;
}
}
void F_282 ( struct V_1 * V_2 ,
struct V_64 * V_127 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_421 = V_493 ;
T_1 V_494 ;
T_4 V_156 = V_127 -> V_156 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
V_494 = F_40 ( V_14 , F_45 ( V_156 ) ) ;
V_494 &= ~ V_495 ;
F_75 ( V_14 , F_45 ( V_156 ) , V_494 ) ;
if ( V_14 -> V_114 . type == V_115 &&
! ( F_40 ( V_14 , V_428 ) & V_429 ) )
return;
do {
F_26 ( 10 ) ;
V_494 = F_40 ( V_14 , F_45 ( V_156 ) ) ;
} while ( -- V_421 && ( V_494 & V_495 ) );
if ( ! V_421 ) {
F_107 ( V_163 , L_86
L_85 , V_156 ) ;
}
}
void F_283 ( struct V_1 * V_2 ,
struct V_64 * V_127 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_496 = V_127 -> V_87 ;
T_1 V_494 ;
T_4 V_156 = V_127 -> V_156 ;
V_494 = F_40 ( V_14 , F_45 ( V_156 ) ) ;
F_282 ( V_2 , V_127 ) ;
F_75 ( V_14 , F_46 ( V_156 ) , ( V_496 & F_256 ( 32 ) ) ) ;
F_75 ( V_14 , F_47 ( V_156 ) , ( V_496 >> 32 ) ) ;
F_75 ( V_14 , F_42 ( V_156 ) ,
V_127 -> V_94 * sizeof( union V_75 ) ) ;
F_221 ( V_14 ) ;
F_75 ( V_14 , F_43 ( V_156 ) , 0 ) ;
F_75 ( V_14 , F_44 ( V_156 ) , 0 ) ;
V_127 -> V_153 = V_2 -> V_424 + F_44 ( V_156 ) ;
F_265 ( V_2 , V_127 ) ;
F_279 ( V_2 , V_127 ) ;
if ( V_14 -> V_114 . type == V_115 ) {
V_494 &= ~ 0x3FFFFF ;
V_494 |= 0x080420 ;
}
V_494 |= V_495 ;
F_75 ( V_14 , F_45 ( V_156 ) , V_494 ) ;
F_281 ( V_2 , V_127 ) ;
F_147 ( V_127 , F_114 ( V_127 ) ) ;
}
static void F_284 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_465 = V_2 -> V_440 [ V_441 ] . V_442 ;
T_2 V_497 ;
T_1 V_498 = V_499 |
V_500 |
V_501 |
V_502 |
V_503 ;
if ( V_14 -> V_114 . type == V_115 )
return;
if ( V_465 > 3 )
V_498 |= 2u << 29 ;
else if ( V_465 > 1 )
V_498 |= 1u << 29 ;
F_285 (pool, &adapter->fwd_bitmask, 32 )
F_75 ( V_14 , F_286 ( F_287 ( V_497 ) ) , V_498 ) ;
}
static void F_288 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_193 , V_504 ;
T_1 V_505 , V_506 ;
int V_49 ;
if ( ! ( V_2 -> V_146 & V_435 ) )
return;
V_506 = F_40 ( V_14 , V_507 ) ;
V_506 |= V_508 ;
V_506 &= ~ V_509 ;
V_506 |= F_287 ( 0 ) << V_510 ;
V_506 |= V_511 ;
F_75 ( V_14 , V_507 , V_506 ) ;
V_504 = F_287 ( 0 ) % 32 ;
V_193 = ( F_287 ( 0 ) >= 32 ) ? 1 : 0 ;
F_75 ( V_14 , F_289 ( V_193 ) , F_290 ( 31 , V_504 ) ) ;
F_75 ( V_14 , F_289 ( V_193 ^ 1 ) , V_193 - 1 ) ;
F_75 ( V_14 , F_291 ( V_193 ) , F_290 ( 31 , V_504 ) ) ;
F_75 ( V_14 , F_291 ( V_193 ^ 1 ) , V_193 - 1 ) ;
if ( V_2 -> V_512 == V_513 )
F_75 ( V_14 , V_514 , V_515 ) ;
V_14 -> V_114 . V_357 . V_516 ( V_14 , 0 , F_287 ( 0 ) ) ;
V_2 -> V_161 &= ~ V_517 ;
switch ( V_2 -> V_440 [ V_518 ] . V_124 ) {
case V_519 :
V_505 = V_520 ;
break;
case V_521 :
V_505 = V_522 ;
break;
default:
V_505 = V_523 ;
break;
}
F_75 ( V_14 , V_524 , V_505 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_324 ; V_49 ++ ) {
F_292 ( V_2 -> V_62 , V_49 ,
V_2 -> V_525 [ V_49 ] . V_526 ) ;
F_293 ( V_2 -> V_62 , V_49 ,
V_2 -> V_525 [ V_49 ] . V_527 ) ;
}
}
static void F_294 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_61 * V_62 = V_2 -> V_62 ;
int V_528 = V_62 -> V_312 + V_529 + V_530 ;
struct V_64 * V_74 ;
int V_49 ;
T_1 V_531 , V_532 ;
#ifdef F_180
if ( ( V_2 -> V_146 & V_533 ) &&
( V_528 < V_534 ) )
V_528 = V_534 ;
#endif
if ( V_528 < ( V_535 + V_530 ) )
V_528 = ( V_535 + V_530 ) ;
V_531 = F_40 ( V_14 , V_536 ) ;
if ( V_528 != ( V_531 >> V_537 ) ) {
V_531 &= ~ V_538 ;
V_531 |= V_528 << V_537 ;
F_75 ( V_14 , V_536 , V_531 ) ;
}
V_532 = F_40 ( V_14 , V_539 ) ;
V_532 |= V_540 ;
F_75 ( V_14 , V_539 , V_532 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ ) {
V_74 = V_2 -> V_74 [ V_49 ] ;
if ( V_2 -> V_161 & V_541 )
F_295 ( V_74 ) ;
else
F_296 ( V_74 ) ;
}
}
static void F_297 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_542 = F_40 ( V_14 , V_543 ) ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_542 |= V_544 ;
break;
case V_119 :
case V_120 :
case V_121 :
if ( V_2 -> V_324 )
V_542 |= V_545 ;
case V_117 :
case V_118 :
F_75 ( V_14 , V_546 ,
( V_547 | F_40 ( V_14 , V_546 ) ) ) ;
V_542 &= ~ V_548 ;
V_542 |= ( V_549 | V_550 ) ;
V_542 |= V_551 ;
break;
default:
return;
}
F_75 ( V_14 , V_543 , V_542 ) ;
}
static void F_298 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
T_1 V_199 , V_552 ;
V_14 -> V_114 . V_357 . V_553 ( V_14 ) ;
F_284 ( V_2 ) ;
F_297 ( V_2 ) ;
V_552 = F_40 ( V_14 , V_554 ) ;
V_552 &= ~ V_555 ;
if ( ! ( V_2 -> V_161 & V_541 ) )
V_552 |= V_555 ;
F_75 ( V_14 , V_554 , V_552 ) ;
F_276 ( V_2 ) ;
F_294 ( V_2 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ )
F_283 ( V_2 , V_2 -> V_74 [ V_49 ] ) ;
V_199 = F_40 ( V_14 , V_556 ) ;
if ( V_14 -> V_114 . type == V_115 )
V_199 |= V_557 ;
V_199 |= V_558 ;
V_14 -> V_114 . V_357 . V_559 ( V_14 , V_199 ) ;
}
static int F_299 ( struct V_61 * V_62 ,
T_12 V_560 , T_2 V_269 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! V_269 || ! ( V_2 -> V_161 & V_517 ) )
V_14 -> V_114 . V_357 . V_561 ( & V_2 -> V_14 , V_269 , F_287 ( 0 ) , true , ! ! V_269 ) ;
F_257 ( V_269 , V_2 -> V_562 ) ;
return 0 ;
}
static int F_300 ( struct V_15 * V_14 , T_1 V_270 )
{
T_1 V_563 ;
int V_564 ;
if ( V_270 == 0 )
return 0 ;
for ( V_564 = V_565 ; -- V_564 ; ) {
V_563 = F_40 ( V_14 , F_301 ( V_564 ) ) ;
if ( ( V_563 & V_566 ) == V_270 )
break;
}
return V_564 ;
}
void F_302 ( struct V_1 * V_2 , T_1 V_269 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_567 , V_568 ;
int V_564 ;
V_564 = F_300 ( V_14 , V_269 ) ;
if ( ! V_564 )
return;
V_568 = V_564 * 2 + ( F_287 ( 0 ) / 32 ) ;
V_567 = ~ F_205 ( F_287 ( 0 ) % 32 ) ;
V_567 &= F_40 ( V_14 , F_303 ( V_568 ) ) ;
if ( ! V_567 && ! F_40 ( V_14 , F_303 ( V_568 ^ 1 ) ) ) {
if ( ! ( V_2 -> V_161 & V_517 ) )
F_75 ( V_14 , F_303 ( V_568 ) , 0 ) ;
F_75 ( V_14 , F_301 ( V_564 ) , 0 ) ;
}
}
static int F_304 ( struct V_61 * V_62 ,
T_12 V_560 , T_2 V_269 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_269 && ! ( V_2 -> V_161 & V_517 ) )
V_14 -> V_114 . V_357 . V_561 ( V_14 , V_269 , F_287 ( 0 ) , false , true ) ;
F_37 ( V_269 , V_2 -> V_562 ) ;
return 0 ;
}
static void F_305 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_569 ;
int V_49 , V_56 ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_569 = F_40 ( V_14 , V_570 ) ;
V_569 &= ~ V_571 ;
F_75 ( V_14 , V_570 , V_569 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ ) {
struct V_64 * V_127 = V_2 -> V_74 [ V_49 ] ;
if ( V_127 -> V_154 )
continue;
V_56 = V_127 -> V_156 ;
V_569 = F_40 ( V_14 , F_45 ( V_56 ) ) ;
V_569 &= ~ V_572 ;
F_75 ( V_14 , F_45 ( V_56 ) , V_569 ) ;
}
break;
default:
break;
}
}
static void F_306 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_569 ;
int V_49 , V_56 ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_569 = F_40 ( V_14 , V_570 ) ;
V_569 |= V_571 ;
F_75 ( V_14 , V_570 , V_569 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ ) {
struct V_64 * V_127 = V_2 -> V_74 [ V_49 ] ;
if ( V_127 -> V_154 )
continue;
V_56 = V_127 -> V_156 ;
V_569 = F_40 ( V_14 , F_45 ( V_56 ) ) ;
V_569 |= V_572 ;
F_75 ( V_14 , F_45 ( V_56 ) , V_569 ) ;
}
break;
default:
break;
}
}
static void F_307 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_569 , V_49 ;
switch ( V_14 -> V_114 . type ) {
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
default:
if ( V_2 -> V_146 & V_573 )
break;
case V_115 :
V_569 = F_40 ( V_14 , V_570 ) ;
V_569 &= ~ ( V_574 | V_575 ) ;
F_75 ( V_14 , V_570 , V_569 ) ;
return;
}
if ( V_2 -> V_161 & V_517 )
return;
V_2 -> V_161 |= V_517 ;
for ( V_49 = V_565 ; -- V_49 ; ) {
T_1 V_193 = F_303 ( V_49 * 2 + F_287 ( 0 ) / 32 ) ;
T_1 V_576 = F_40 ( V_14 , V_193 ) ;
V_576 |= F_205 ( F_287 ( 0 ) % 32 ) ;
F_75 ( V_14 , V_193 , V_576 ) ;
}
for ( V_49 = V_14 -> V_114 . V_577 ; V_49 -- ; )
F_75 ( V_14 , F_308 ( V_49 ) , ~ 0U ) ;
}
static void F_309 ( struct V_1 * V_2 , T_1 V_578 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_579 [ V_580 ] = { 0 } ;
T_1 V_581 = V_578 * 32 ;
T_1 V_582 = V_581 + ( V_580 * 32 ) ;
T_1 V_49 , V_269 , V_568 , V_567 ;
for ( V_49 = V_565 ; -- V_49 ; ) {
T_1 V_563 = F_40 ( V_14 , F_301 ( V_49 ) ) ;
V_269 = V_563 & V_566 ;
if ( V_269 < V_581 || V_269 >= V_582 )
continue;
if ( V_563 ) {
V_579 [ ( V_269 - V_581 ) / 32 ] |= F_205 ( V_269 % 32 ) ;
if ( F_14 ( V_269 , V_2 -> V_562 ) )
continue;
}
V_568 = V_49 * 2 + F_287 ( 0 ) / 32 ;
V_567 = ~ F_205 ( F_287 ( 0 ) % 32 ) ;
V_567 &= F_40 ( V_14 , F_303 ( V_568 ) ) ;
F_75 ( V_14 , F_303 ( V_568 ) , V_567 ) ;
}
for ( V_49 = V_580 ; V_49 -- ; ) {
V_269 = ( V_578 + V_49 ) * 32 ;
V_568 = V_269 / V_583 ;
V_567 = V_269 % V_583 ;
V_579 [ V_49 ] |= V_2 -> V_562 [ V_568 ] >> V_567 ;
F_75 ( V_14 , F_308 ( V_578 + V_49 ) , V_579 [ V_49 ] ) ;
}
}
static void F_310 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_569 , V_49 ;
switch ( V_14 -> V_114 . type ) {
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
default:
if ( V_2 -> V_146 & V_573 )
break;
case V_115 :
V_569 = F_40 ( V_14 , V_570 ) ;
V_569 &= ~ V_575 ;
V_569 |= V_574 ;
F_75 ( V_14 , V_570 , V_569 ) ;
return;
}
if ( ! ( V_2 -> V_161 & V_517 ) )
return;
V_2 -> V_161 &= ~ V_517 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_114 . V_577 ; V_49 += V_580 )
F_309 ( V_2 , V_49 ) ;
}
static void F_311 ( struct V_1 * V_2 )
{
T_2 V_269 = 1 ;
F_299 ( V_2 -> V_62 , F_160 ( V_271 ) , 0 ) ;
F_312 (vid, adapter->active_vlans, VLAN_N_VID)
F_299 ( V_2 -> V_62 , F_160 ( V_271 ) , V_269 ) ;
}
static int F_313 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! F_61 ( V_62 ) )
return 0 ;
if ( V_14 -> V_114 . V_357 . V_584 )
V_14 -> V_114 . V_357 . V_584 ( V_14 , V_62 ) ;
else
return - V_585 ;
#ifdef F_314
F_315 ( V_2 ) ;
#endif
return F_316 ( V_62 ) ;
}
void F_317 ( struct V_1 * V_2 )
{
struct V_586 * V_587 = & V_2 -> V_587 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_114 . V_588 ; V_49 ++ , V_587 ++ ) {
V_587 -> V_35 &= ~ V_589 ;
if ( V_587 -> V_35 & V_590 )
V_14 -> V_114 . V_357 . V_591 ( V_14 , V_49 ,
V_587 -> V_592 ,
V_587 -> V_497 ,
V_593 ) ;
else
V_14 -> V_114 . V_357 . V_594 ( V_14 , V_49 ) ;
}
}
static void F_318 ( struct V_1 * V_2 )
{
struct V_586 * V_587 = & V_2 -> V_587 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_114 . V_588 ; V_49 ++ , V_587 ++ ) {
if ( ! ( V_587 -> V_35 & V_589 ) )
continue;
V_587 -> V_35 &= ~ V_589 ;
if ( V_587 -> V_35 & V_590 )
V_14 -> V_114 . V_357 . V_591 ( V_14 , V_49 ,
V_587 -> V_592 ,
V_587 -> V_497 ,
V_593 ) ;
else
V_14 -> V_114 . V_357 . V_594 ( V_14 , V_49 ) ;
}
}
static void F_319 ( struct V_1 * V_2 )
{
struct V_586 * V_587 = & V_2 -> V_587 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_114 . V_588 ; V_49 ++ , V_587 ++ ) {
V_587 -> V_35 |= V_589 ;
V_587 -> V_35 &= ~ V_590 ;
}
F_318 ( V_2 ) ;
}
static int F_320 ( struct V_1 * V_2 , T_2 V_497 )
{
struct V_586 * V_587 = & V_2 -> V_587 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 , V_94 = 0 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_114 . V_588 ; V_49 ++ , V_587 ++ ) {
if ( V_587 -> V_35 & V_595 )
continue;
if ( V_587 -> V_35 & V_590 ) {
if ( V_587 -> V_497 != V_497 )
continue;
}
V_94 ++ ;
}
return V_94 ;
}
static void F_321 ( struct V_1 * V_2 )
{
struct V_586 * V_587 = & V_2 -> V_587 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
memcpy ( & V_587 -> V_592 , V_14 -> V_114 . V_592 , V_596 ) ;
V_587 -> V_497 = F_287 ( 0 ) ;
V_587 -> V_35 = V_595 | V_590 ;
V_14 -> V_114 . V_357 . V_591 ( V_14 , 0 , V_587 -> V_592 , V_587 -> V_497 ,
V_593 ) ;
}
int F_322 ( struct V_1 * V_2 ,
const T_4 * V_592 , T_2 V_497 )
{
struct V_586 * V_587 = & V_2 -> V_587 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( F_323 ( V_592 ) )
return - V_597 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_114 . V_588 ; V_49 ++ , V_587 ++ ) {
if ( V_587 -> V_35 & V_590 )
continue;
F_324 ( V_587 -> V_592 , V_592 ) ;
V_587 -> V_497 = V_497 ;
V_587 -> V_35 |= V_589 |
V_590 ;
F_318 ( V_2 ) ;
return V_49 ;
}
return - V_585 ;
}
int F_325 ( struct V_1 * V_2 ,
const T_4 * V_592 , T_2 V_497 )
{
struct V_586 * V_587 = & V_2 -> V_587 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( F_323 ( V_592 ) )
return - V_597 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_114 . V_588 ; V_49 ++ , V_587 ++ ) {
if ( ! ( V_587 -> V_35 & V_590 ) )
continue;
if ( V_587 -> V_497 != V_497 )
continue;
if ( ! F_326 ( V_592 , V_587 -> V_592 ) )
continue;
V_587 -> V_35 |= V_589 ;
V_587 -> V_35 &= ~ V_590 ;
F_318 ( V_2 ) ;
return 0 ;
}
return - V_585 ;
}
static int F_327 ( struct V_61 * V_62 , int V_598 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
int V_94 = 0 ;
if ( F_328 ( V_62 ) > F_320 ( V_2 , V_598 ) )
return - V_585 ;
if ( ! F_329 ( V_62 ) ) {
struct V_599 * V_600 ;
F_330 (ha, netdev) {
F_325 ( V_2 , V_600 -> V_592 , V_598 ) ;
F_322 ( V_2 , V_600 -> V_592 , V_598 ) ;
V_94 ++ ;
}
}
return V_94 ;
}
static int F_331 ( struct V_61 * V_62 , const unsigned char * V_592 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
int V_601 ;
V_601 = F_322 ( V_2 , V_592 , F_287 ( 0 ) ) ;
return F_332 ( int , V_601 , 0 ) ;
}
static int F_333 ( struct V_61 * V_62 , const unsigned char * V_592 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
F_325 ( V_2 , V_592 , F_287 ( 0 ) ) ;
return 0 ;
}
void F_334 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_602 , V_603 = V_604 | V_605 ;
T_13 V_216 = V_62 -> V_216 ;
int V_94 ;
V_602 = F_40 ( V_14 , V_606 ) ;
V_602 &= ~ V_607 ;
V_602 |= V_608 ;
V_602 |= V_609 ;
V_602 |= V_610 ;
V_602 &= ~ ( V_611 | V_612 ) ;
if ( V_62 -> V_146 & V_613 ) {
V_14 -> V_614 . V_615 = true ;
V_602 |= ( V_611 | V_612 ) ;
V_603 |= V_616 ;
V_216 &= ~ V_617 ;
} else {
if ( V_62 -> V_146 & V_618 ) {
V_602 |= V_612 ;
V_603 |= V_616 ;
}
V_14 -> V_614 . V_615 = false ;
}
if ( F_335 ( V_62 , F_331 , F_333 ) ) {
V_602 |= V_611 ;
V_603 |= V_619 ;
}
V_94 = F_313 ( V_62 ) ;
if ( V_94 < 0 ) {
V_602 |= V_612 ;
V_603 |= V_616 ;
} else if ( V_94 ) {
V_603 |= V_620 ;
}
if ( V_14 -> V_114 . type != V_115 ) {
V_603 |= F_40 ( V_14 , F_336 ( F_287 ( 0 ) ) ) &
~ ( V_616 | V_620 |
V_619 ) ;
F_75 ( V_14 , F_336 ( F_287 ( 0 ) ) , V_603 ) ;
}
if ( V_216 & V_292 ) {
V_602 |= ( V_607 |
V_608 |
V_610 ) ;
V_602 &= ~ ( V_609 ) ;
}
F_75 ( V_14 , V_606 , V_602 ) ;
if ( V_216 & V_267 )
F_306 ( V_2 ) ;
else
F_305 ( V_2 ) ;
if ( V_216 & V_617 )
F_310 ( V_2 ) ;
else
F_307 ( V_2 ) ;
}
static void F_337 ( struct V_1 * V_2 )
{
int V_621 ;
for ( V_621 = 0 ; V_621 < V_2 -> V_208 ; V_621 ++ ) {
F_338 ( V_2 -> V_173 [ V_621 ] ) ;
F_339 ( & V_2 -> V_173 [ V_621 ] -> V_273 ) ;
}
}
static void F_340 ( struct V_1 * V_2 )
{
int V_621 ;
for ( V_621 = 0 ; V_621 < V_2 -> V_208 ; V_621 ++ ) {
F_341 ( & V_2 -> V_173 [ V_621 ] -> V_273 ) ;
while ( ! F_342 ( V_2 -> V_173 [ V_621 ] ) ) {
F_54 ( L_87 , V_621 ) ;
F_259 ( 1000 , 20000 ) ;
}
}
}
static void F_343 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_114 . type ) {
case V_119 :
case V_120 :
case V_121 :
F_75 ( & V_2 -> V_14 , V_622 , 0 ) ;
V_2 -> V_623 = 0 ;
break;
default:
break;
}
}
static void F_344 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_528 = V_2 -> V_62 -> V_312 + V_529 + V_530 ;
if ( ! ( V_2 -> V_146 & V_147 ) ) {
if ( V_14 -> V_114 . type == V_115 )
F_345 ( V_2 -> V_62 , 65536 ) ;
return;
}
if ( V_14 -> V_114 . type == V_115 )
F_345 ( V_2 -> V_62 , 32768 ) ;
#ifdef F_180
if ( V_2 -> V_62 -> V_216 & V_624 )
V_528 = F_210 ( V_528 , V_534 ) ;
#endif
if ( V_2 -> V_625 & V_626 ) {
F_346 ( V_14 , & V_2 -> V_143 , V_528 ,
V_627 ) ;
F_346 ( V_14 , & V_2 -> V_143 , V_528 ,
V_628 ) ;
F_347 ( V_14 , & V_2 -> V_143 ) ;
} else if ( V_2 -> V_629 && V_2 -> V_145 ) {
F_348 ( & V_2 -> V_14 ,
V_2 -> V_629 ,
V_528 ) ;
F_349 ( & V_2 -> V_14 ,
V_2 -> V_145 -> V_142 ,
V_2 -> V_629 -> V_630 ) ;
}
if ( V_14 -> V_114 . type != V_115 ) {
T_1 V_631 = 0 ;
T_2 V_465 = V_2 -> V_440 [ V_441 ] . V_442 - 1 ;
while ( V_465 ) {
V_631 ++ ;
V_465 >>= 1 ;
}
F_75 ( V_14 , V_632 , V_631 * 0x11111111 ) ;
}
}
static int F_350 ( struct V_1 * V_2 , int V_633 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_61 * V_80 = V_2 -> V_62 ;
int V_396 , V_141 , V_634 , V_635 ;
T_1 V_636 , V_637 ;
V_141 = V_396 = V_80 -> V_312 + V_529 + V_530 + V_638 ;
#ifdef F_180
if ( ( V_80 -> V_216 & V_624 ) &&
( V_141 < V_534 ) &&
( V_633 == F_351 ( V_2 ) ) )
V_141 = V_534 ;
#endif
switch ( V_14 -> V_114 . type ) {
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_636 = F_352 ( V_396 , V_141 ) ;
break;
default:
V_636 = F_353 ( V_396 , V_141 ) ;
break;
}
if ( V_2 -> V_146 & V_435 )
V_636 += F_354 ( V_141 ) ;
V_634 = F_355 ( V_636 ) ;
V_637 = F_40 ( V_14 , F_356 ( V_633 ) ) >> 10 ;
V_635 = V_637 - V_634 ;
if ( V_635 < 0 ) {
F_27 ( V_163 , L_88
L_89
L_90 , V_633 ) ;
V_635 = V_141 + 1 ;
}
return V_635 ;
}
static int F_357 ( struct V_1 * V_2 , int V_633 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_61 * V_80 = V_2 -> V_62 ;
int V_141 ;
T_1 V_636 ;
V_141 = V_80 -> V_312 + V_529 + V_530 ;
#ifdef F_180
if ( ( V_80 -> V_216 & V_624 ) &&
( V_141 < V_534 ) &&
( V_633 == F_90 ( V_80 , V_2 -> V_639 . V_640 ) ) )
V_141 = V_534 ;
#endif
switch ( V_14 -> V_114 . type ) {
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_636 = F_358 ( V_141 ) ;
break;
default:
V_636 = F_359 ( V_141 ) ;
break;
}
return F_355 ( V_636 ) ;
}
static void F_360 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_641 = F_261 ( V_2 -> V_62 ) ;
int V_49 ;
if ( ! V_641 )
V_641 = 1 ;
for ( V_49 = 0 ; V_49 < V_641 ; V_49 ++ ) {
V_14 -> V_132 . V_642 [ V_49 ] = F_350 ( V_2 , V_49 ) ;
V_14 -> V_132 . V_643 [ V_49 ] = F_357 ( V_2 , V_49 ) ;
if ( V_14 -> V_132 . V_643 [ V_49 ] > V_14 -> V_132 . V_642 [ V_49 ] )
V_14 -> V_132 . V_643 [ V_49 ] = 0 ;
}
for (; V_49 < V_644 ; V_49 ++ )
V_14 -> V_132 . V_642 [ V_49 ] = 0 ;
}
static void F_361 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_645 ;
T_4 V_141 = F_261 ( V_2 -> V_62 ) ;
if ( V_2 -> V_146 & V_389 ||
V_2 -> V_146 & V_646 )
V_645 = 32 << V_2 -> V_647 ;
else
V_645 = 0 ;
V_14 -> V_114 . V_357 . V_648 ( V_14 , V_141 , V_645 , V_649 ) ;
F_360 ( V_2 ) ;
}
static void F_362 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_650 * V_651 ;
struct V_652 * V_653 ;
F_363 ( & V_2 -> V_654 ) ;
if ( ! F_364 ( & V_2 -> V_655 ) )
F_365 ( V_14 , & V_2 -> V_656 ) ;
F_366 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_367 ( V_14 ,
& V_653 -> V_653 ,
V_653 -> V_657 ,
( V_653 -> V_658 == V_659 ) ?
V_659 :
V_2 -> V_74 [ V_653 -> V_658 ] -> V_156 ) ;
}
F_368 ( & V_2 -> V_654 ) ;
}
static void F_369 ( struct V_61 * V_80 , unsigned int V_497 ,
struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_603 ;
V_603 = F_40 ( V_14 , F_336 ( V_497 ) ) ;
V_603 |= ( V_620 | V_604 | V_605 ) ;
V_603 &= ~ V_616 ;
if ( V_80 -> V_146 & V_618 ) {
V_603 |= V_616 ;
} else {
V_603 |= V_620 ;
V_14 -> V_114 . V_357 . V_584 ( V_14 , V_80 ) ;
}
F_327 ( V_2 -> V_62 , V_497 ) ;
F_75 ( V_14 , F_336 ( V_497 ) , V_603 ) ;
}
static void F_370 ( struct V_660 * V_661 )
{
struct V_1 * V_2 = V_661 -> V_155 ;
int V_465 = V_2 -> V_662 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_497 = V_661 -> V_497 ;
T_1 V_498 = V_499 |
V_500 |
V_501 |
V_502 |
V_503 ;
if ( V_14 -> V_114 . type == V_115 )
return;
if ( V_465 > 3 )
V_498 |= 2u << 29 ;
else if ( V_465 > 1 )
V_498 |= 1u << 29 ;
F_75 ( V_14 , F_286 ( F_287 ( V_497 ) ) , V_498 ) ;
}
static void F_371 ( struct V_64 * V_74 )
{
struct V_209 * V_80 = V_74 -> V_80 ;
unsigned long V_297 ;
T_2 V_49 ;
if ( ! V_74 -> V_78 )
return;
for ( V_49 = 0 ; V_49 < V_74 -> V_94 ; V_49 ++ ) {
struct V_77 * V_296 = & V_74 -> V_78 [ V_49 ] ;
if ( V_296 -> V_95 ) {
struct V_214 * V_95 = V_296 -> V_95 ;
if ( F_155 ( V_95 ) -> V_290 )
F_84 ( V_80 ,
F_155 ( V_95 ) -> V_87 ,
F_73 ( V_74 ) ,
V_254 ) ;
F_372 ( V_95 ) ;
V_296 -> V_95 = NULL ;
}
if ( ! V_296 -> V_104 )
continue;
F_84 ( V_80 , V_296 -> V_87 ,
F_144 ( V_74 ) , V_254 ) ;
F_146 ( V_296 -> V_104 , F_142 ( V_74 ) ) ;
V_296 -> V_104 = NULL ;
}
V_297 = sizeof( struct V_77 ) * V_74 -> V_94 ;
memset ( V_74 -> V_78 , 0 , V_297 ) ;
memset ( V_74 -> V_93 , 0 , V_74 -> V_297 ) ;
V_74 -> V_258 = 0 ;
V_74 -> V_85 = 0 ;
V_74 -> V_86 = 0 ;
}
static void F_373 ( struct V_660 * V_661 ,
struct V_64 * V_74 )
{
struct V_1 * V_2 = V_661 -> V_155 ;
int V_113 = V_74 -> V_92 + V_661 -> V_663 ;
F_282 ( V_2 , V_74 ) ;
F_259 ( 10000 , 20000 ) ;
F_224 ( V_2 , F_241 ( V_113 ) ) ;
F_371 ( V_74 ) ;
V_74 -> V_154 = NULL ;
}
static int F_374 ( struct V_61 * V_664 ,
struct V_660 * V_665 )
{
struct V_1 * V_2 = V_665 -> V_155 ;
unsigned int V_666 = V_665 -> V_663 ;
unsigned int V_667 = V_665 -> V_668 ;
int V_49 ;
F_375 ( V_664 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_662 ; V_49 ++ ) {
F_373 ( V_665 , V_2 -> V_74 [ V_666 + V_49 ] ) ;
V_2 -> V_74 [ V_666 + V_49 ] -> V_62 = V_2 -> V_62 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_662 ; V_49 ++ ) {
V_2 -> V_65 [ V_667 + V_49 ] -> V_154 = NULL ;
V_2 -> V_65 [ V_667 + V_49 ] -> V_62 = V_2 -> V_62 ;
}
return 0 ;
}
static int F_376 ( struct V_61 * V_664 ,
struct V_660 * V_665 )
{
struct V_1 * V_2 = V_665 -> V_155 ;
unsigned int V_666 , V_667 , V_381 ;
int V_49 , V_669 , V_17 = 0 ;
if ( ! F_14 ( V_665 -> V_497 , & V_2 -> V_670 ) )
return 0 ;
V_669 = V_665 -> V_497 * V_2 -> V_662 ;
F_377 ( V_664 , L_91 ,
V_665 -> V_497 , V_2 -> V_671 ,
V_669 , V_669 + V_2 -> V_662 ,
V_2 -> V_670 ) ;
V_665 -> V_62 = V_664 ;
V_665 -> V_663 = V_666 = V_669 ;
V_665 -> V_668 = V_667 = V_669 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_662 ; V_49 ++ )
F_373 ( V_665 , V_2 -> V_74 [ V_666 + V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_662 ; V_49 ++ ) {
V_2 -> V_74 [ V_666 + V_49 ] -> V_62 = V_664 ;
V_2 -> V_74 [ V_666 + V_49 ] -> V_154 = V_665 ;
F_283 ( V_2 , V_2 -> V_74 [ V_666 + V_49 ] ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_662 ; V_49 ++ ) {
V_2 -> V_65 [ V_667 + V_49 ] -> V_62 = V_664 ;
V_2 -> V_65 [ V_667 + V_49 ] -> V_154 = V_665 ;
}
V_381 = F_332 (unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues) ;
V_17 = F_378 ( V_664 , V_381 ) ;
if ( V_17 )
goto V_672;
V_17 = F_379 ( V_664 , V_381 ) ;
if ( V_17 )
goto V_672;
if ( F_380 ( V_664 -> V_673 ) )
F_322 ( V_2 , V_664 -> V_673 , V_665 -> V_497 ) ;
F_370 ( V_665 ) ;
F_369 ( V_664 , V_665 -> V_497 , V_2 ) ;
return V_17 ;
V_672:
F_374 ( V_664 , V_665 ) ;
return V_17 ;
}
static void F_381 ( struct V_1 * V_2 )
{
struct V_61 * V_101 ;
struct V_674 * V_675 ;
int V_17 ;
F_382 (adapter->netdev, upper, iter) {
if ( F_383 ( V_101 ) ) {
struct V_676 * V_677 = F_93 ( V_101 ) ;
struct V_660 * V_661 = V_677 -> V_678 ;
if ( V_677 -> V_678 ) {
V_17 = F_376 ( V_101 , V_661 ) ;
if ( V_17 )
continue;
}
}
}
}
static void F_384 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
F_361 ( V_2 ) ;
#ifdef F_385
F_344 ( V_2 ) ;
#endif
F_288 ( V_2 ) ;
F_334 ( V_2 -> V_62 ) ;
F_311 ( V_2 ) ;
switch ( V_14 -> V_114 . type ) {
case V_117 :
case V_118 :
V_14 -> V_114 . V_357 . V_679 ( V_14 ) ;
break;
default:
break;
}
if ( V_2 -> V_146 & V_389 ) {
F_386 ( & V_2 -> V_14 ,
V_2 -> V_647 ) ;
} else if ( V_2 -> V_146 & V_646 ) {
F_387 ( & V_2 -> V_14 ,
V_2 -> V_647 ) ;
F_362 ( V_2 ) ;
}
switch ( V_14 -> V_114 . type ) {
case V_117 :
case V_118 :
V_14 -> V_114 . V_357 . V_680 ( V_14 ) ;
break;
default:
break;
}
#ifdef F_237
if ( V_2 -> V_146 & V_211 )
F_127 ( V_2 ) ;
#endif
#ifdef F_180
F_388 ( V_2 ) ;
#endif
F_262 ( V_2 ) ;
F_298 ( V_2 ) ;
F_381 ( V_2 ) ;
}
static void F_389 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_114 . type == V_115 )
V_2 -> V_161 |= V_681 ;
V_2 -> V_161 |= V_372 ;
V_2 -> V_373 = 0 ;
}
static int F_390 ( struct V_15 * V_14 )
{
T_1 V_20 ;
bool V_682 , V_359 = false ;
int V_601 = V_683 ;
if ( V_14 -> V_114 . V_357 . V_358 )
V_601 = V_14 -> V_114 . V_357 . V_358 ( V_14 , & V_20 , & V_359 , false ) ;
if ( V_601 )
return V_601 ;
V_20 = V_14 -> V_46 . V_684 ;
if ( ( ! V_20 ) && ( V_14 -> V_114 . V_357 . V_685 ) )
V_601 = V_14 -> V_114 . V_357 . V_685 ( V_14 , & V_20 ,
& V_682 ) ;
if ( V_601 )
return V_601 ;
if ( V_14 -> V_114 . V_357 . V_686 )
V_601 = V_14 -> V_114 . V_357 . V_686 ( V_14 , V_20 , V_359 ) ;
return V_601 ;
}
static void F_391 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_687 = 0 ;
if ( V_2 -> V_146 & V_415 ) {
V_687 = V_688 | V_689 |
V_690 ;
V_687 |= V_691 ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
F_75 ( V_14 , V_692 , V_693 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
default:
F_75 ( V_14 , F_392 ( 0 ) , 0xFFFFFFFF ) ;
F_75 ( V_14 , F_392 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_75 ( V_14 , V_692 , V_693 ) ;
}
if ( V_2 -> V_146 & V_435 ) {
V_687 &= ~ V_694 ;
switch ( V_2 -> V_440 [ V_518 ] . V_124 ) {
case V_519 :
V_687 |= V_695 ;
break;
case V_521 :
V_687 |= V_696 ;
break;
default:
V_687 |= V_697 ;
break;
}
}
if ( V_2 -> V_161 & V_352 ) {
switch ( V_2 -> V_14 . V_114 . type ) {
case V_117 :
V_687 |= V_698 ;
break;
default:
break;
}
}
if ( V_2 -> V_146 & V_363 )
V_687 |= F_393 ( V_14 ) ;
switch ( V_14 -> V_114 . type ) {
case V_117 :
V_687 |= V_699 | V_700 ;
break;
case V_120 :
case V_121 :
V_687 |= V_701 ;
break;
default:
break;
}
F_75 ( V_14 , V_702 , V_687 ) ;
}
static void F_394 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 ;
T_1 V_106 ;
F_76 ( V_2 ) ;
F_391 ( V_2 ) ;
if ( V_2 -> V_146 & V_415 )
F_204 ( V_2 ) ;
else
F_254 ( V_2 ) ;
if ( V_14 -> V_114 . V_357 . V_703 )
V_14 -> V_114 . V_357 . V_703 ( V_14 ) ;
if ( V_14 -> V_46 . V_357 . V_704 )
V_14 -> V_46 . V_357 . V_704 ( V_14 , true ) ;
F_36 () ;
F_37 ( V_34 , & V_2 -> V_35 ) ;
F_337 ( V_2 ) ;
if ( F_217 ( V_14 ) ) {
F_389 ( V_2 ) ;
} else {
V_17 = F_390 ( V_14 ) ;
if ( V_17 )
F_107 ( V_188 , L_92 , V_17 ) ;
}
F_40 ( V_14 , V_364 ) ;
F_226 ( V_2 , true , true ) ;
if ( V_2 -> V_146 & V_363 ) {
T_1 V_705 = F_40 ( V_14 , V_706 ) ;
if ( V_705 & V_707 )
F_213 ( V_163 , L_72 ) ;
}
V_2 -> V_146 |= V_376 ;
V_2 -> V_377 = V_187 ;
F_395 ( & V_2 -> V_708 , V_187 ) ;
V_106 = F_40 ( V_14 , V_107 ) ;
V_106 |= V_709 ;
F_75 ( V_14 , V_107 , V_106 ) ;
}
void F_396 ( struct V_1 * V_2 )
{
F_397 ( F_398 () ) ;
F_399 ( V_2 -> V_62 ) ;
while ( F_15 ( V_710 , & V_2 -> V_35 ) )
F_259 ( 1000 , 2000 ) ;
F_400 ( V_2 ) ;
if ( V_2 -> V_146 & V_435 )
F_401 ( 2000 ) ;
F_402 ( V_2 ) ;
F_37 ( V_710 , & V_2 -> V_35 ) ;
}
void F_402 ( struct V_1 * V_2 )
{
F_384 ( V_2 ) ;
F_394 ( V_2 ) ;
}
void F_403 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_61 * V_62 = V_2 -> V_62 ;
int V_17 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
while ( F_15 ( V_711 , & V_2 -> V_35 ) )
F_259 ( 1000 , 2000 ) ;
V_2 -> V_161 &= ~ ( V_681 |
V_372 ) ;
V_2 -> V_146 &= ~ V_374 ;
V_17 = V_14 -> V_114 . V_357 . V_712 ( V_14 ) ;
switch ( V_17 ) {
case 0 :
case V_713 :
case V_714 :
break;
case V_715 :
F_18 ( L_93 ) ;
break;
case V_716 :
F_11 ( L_94
L_95
L_96
L_97
L_98
L_99 ) ;
break;
default:
F_18 ( L_100 , V_17 ) ;
}
F_37 ( V_711 , & V_2 -> V_35 ) ;
F_319 ( V_2 ) ;
F_404 ( V_62 , NULL ) ;
F_321 ( V_2 ) ;
if ( V_14 -> V_114 . V_717 )
V_14 -> V_114 . V_357 . V_718 ( V_14 , F_287 ( 0 ) ) ;
if ( F_14 ( V_719 , & V_2 -> V_35 ) )
F_405 ( V_2 ) ;
if ( V_14 -> V_46 . V_357 . V_704 ) {
if ( ! F_61 ( V_2 -> V_62 ) && ! V_2 -> V_720 )
V_14 -> V_46 . V_357 . V_704 ( V_14 , false ) ;
else
V_14 -> V_46 . V_357 . V_704 ( V_14 , true ) ;
}
}
static void F_406 ( struct V_64 * V_65 )
{
struct V_66 * V_84 ;
unsigned long V_297 ;
T_2 V_49 ;
if ( ! V_65 -> V_84 )
return;
for ( V_49 = 0 ; V_49 < V_65 -> V_94 ; V_49 ++ ) {
V_84 = & V_65 -> V_84 [ V_49 ] ;
F_81 ( V_65 , V_84 ) ;
}
F_407 ( F_111 ( V_65 ) ) ;
V_297 = sizeof( struct V_66 ) * V_65 -> V_94 ;
memset ( V_65 -> V_84 , 0 , V_297 ) ;
memset ( V_65 -> V_93 , 0 , V_65 -> V_297 ) ;
V_65 -> V_86 = 0 ;
V_65 -> V_85 = 0 ;
}
static void F_408 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ )
F_371 ( V_2 -> V_74 [ V_49 ] ) ;
}
static void F_409 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ )
F_406 ( V_2 -> V_65 [ V_49 ] ) ;
}
static void F_410 ( struct V_1 * V_2 )
{
struct V_650 * V_651 ;
struct V_652 * V_653 ;
F_363 ( & V_2 -> V_654 ) ;
F_366 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_411 ( & V_653 -> V_721 ) ;
F_248 ( V_653 ) ;
}
V_2 -> V_722 = 0 ;
F_368 ( & V_2 -> V_654 ) ;
}
void F_400 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_61 * V_101 ;
struct V_674 * V_675 ;
int V_49 ;
if ( F_15 ( V_34 , & V_2 -> V_35 ) )
return;
V_14 -> V_114 . V_357 . V_553 ( V_14 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ )
F_282 ( V_2 , V_2 -> V_74 [ V_49 ] ) ;
F_259 ( 10000 , 20000 ) ;
F_375 ( V_62 ) ;
F_412 ( V_62 ) ;
F_413 ( V_62 ) ;
F_382 (adapter->netdev, upper, iter) {
if ( F_383 ( V_101 ) ) {
struct V_676 * V_270 = F_93 ( V_101 ) ;
if ( V_270 -> V_678 ) {
F_375 ( V_101 ) ;
F_412 ( V_101 ) ;
F_413 ( V_101 ) ;
}
}
}
F_252 ( V_2 ) ;
F_340 ( V_2 ) ;
V_2 -> V_161 &= ~ ( V_390 |
V_162 ) ;
V_2 -> V_146 &= ~ V_376 ;
F_414 ( & V_2 -> V_708 ) ;
if ( V_2 -> V_324 ) {
F_75 ( & V_2 -> V_14 , V_326 , 0 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_324 ; V_49 ++ )
V_2 -> V_525 [ V_49 ] . V_723 = false ;
F_415 ( V_2 ) ;
F_416 ( V_2 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ ) {
T_4 V_156 = V_2 -> V_65 [ V_49 ] -> V_156 ;
F_75 ( V_14 , F_53 ( V_156 ) , V_724 ) ;
}
switch ( V_14 -> V_114 . type ) {
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
F_75 ( V_14 , V_451 ,
( F_40 ( V_14 , V_451 ) &
~ V_452 ) ) ;
break;
default:
break;
}
if ( ! F_417 ( V_2 -> V_9 ) )
F_403 ( V_2 ) ;
if ( V_14 -> V_114 . V_357 . V_725 )
V_14 -> V_114 . V_357 . V_725 ( V_14 ) ;
F_409 ( V_2 ) ;
F_408 ( V_2 ) ;
}
static void F_418 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
F_96 ( V_2 ) ;
}
static void F_419 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_726 * V_141 ;
int V_56 ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
case V_117 :
V_2 -> V_143 . V_727 . V_728 = V_644 ;
V_2 -> V_143 . V_727 . V_729 = V_644 ;
break;
case V_118 :
case V_119 :
V_2 -> V_143 . V_727 . V_728 = V_730 ;
V_2 -> V_143 . V_727 . V_729 = V_730 ;
break;
case V_120 :
case V_121 :
default:
V_2 -> V_143 . V_727 . V_728 = V_731 ;
V_2 -> V_143 . V_727 . V_729 = V_731 ;
break;
}
for ( V_56 = 0 ; V_56 < V_644 ; V_56 ++ ) {
V_141 = & V_2 -> V_143 . V_732 [ V_56 ] ;
V_141 -> V_733 [ V_627 ] . V_734 = 0 ;
V_141 -> V_733 [ V_627 ] . V_735 = 12 + ( V_56 & 1 ) ;
V_141 -> V_733 [ V_628 ] . V_734 = 0 ;
V_141 -> V_733 [ V_628 ] . V_735 = 12 + ( V_56 & 1 ) ;
V_141 -> V_736 = V_737 ;
}
V_141 = & V_2 -> V_143 . V_732 [ 0 ] ;
V_141 -> V_733 [ V_627 ] . V_738 = 0xFF ;
V_141 -> V_733 [ V_628 ] . V_738 = 0xFF ;
V_2 -> V_143 . V_739 [ V_627 ] [ 0 ] = 100 ;
V_2 -> V_143 . V_739 [ V_628 ] [ 0 ] = 100 ;
V_2 -> V_143 . V_144 = false ;
V_2 -> V_740 = 0x00 ;
if ( V_2 -> V_146 & V_741 )
V_2 -> V_625 = V_742 | V_626 ;
memcpy ( & V_2 -> V_743 , & V_2 -> V_143 ,
sizeof( V_2 -> V_743 ) ) ;
}
static int F_420 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_224 , V_744 ;
T_1 V_745 ;
T_2 V_746 ;
int V_49 ;
V_14 -> V_747 = V_9 -> V_748 ;
V_14 -> V_21 = V_9 -> V_209 ;
V_14 -> V_749 = V_9 -> V_750 ;
V_14 -> V_751 = V_9 -> V_752 ;
V_14 -> V_753 = V_9 -> V_754 ;
V_224 = F_332 ( int , F_421 ( V_2 ) , F_422 () ) ;
V_2 -> V_440 [ V_441 ] . V_755 = V_224 ;
V_2 -> V_161 |= V_756 ;
V_2 -> V_757 = V_758 ;
V_2 -> V_425 = 20 ;
V_744 = F_332 ( int , V_759 , F_422 () ) ;
V_2 -> V_440 [ V_760 ] . V_755 = V_744 ;
V_2 -> V_647 = V_761 ;
#ifdef F_237
V_2 -> V_146 |= V_211 ;
#endif
#ifdef F_385
V_2 -> V_146 |= V_741 ;
V_2 -> V_146 &= ~ V_147 ;
#endif
#ifdef F_180
V_2 -> V_146 |= V_762 ;
V_2 -> V_146 &= ~ V_533 ;
#ifdef F_385
V_2 -> V_639 . V_640 = V_763 ;
#endif
#endif
V_2 -> V_764 [ 0 ] = F_423 ( sizeof( * V_2 -> V_764 [ 0 ] ) ,
V_765 ) ;
if ( ! V_2 -> V_764 [ 0 ] )
return - V_585 ;
V_2 -> V_764 [ 0 ] -> V_766 = V_767 ;
for ( V_49 = 1 ; V_49 < V_768 ; V_49 ++ )
V_2 -> V_764 [ V_49 ] = NULL ;
V_2 -> V_587 = F_423 ( sizeof( struct V_586 ) *
V_14 -> V_114 . V_588 ,
V_769 ) ;
if ( ! V_2 -> V_587 )
return - V_585 ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_2 -> V_161 &= ~ V_756 ;
if ( V_14 -> V_21 == V_770 )
V_2 -> V_146 |= V_363 ;
V_2 -> V_757 = V_771 ;
V_2 -> V_440 [ V_760 ] . V_755 = 0 ;
V_2 -> V_425 = 0 ;
V_2 -> V_647 = 0 ;
#ifdef F_180
V_2 -> V_146 &= ~ V_762 ;
V_2 -> V_146 &= ~ V_533 ;
#ifdef F_385
V_2 -> V_639 . V_640 = 0 ;
#endif
#endif
break;
case V_117 :
if ( V_14 -> V_21 == V_354 )
V_2 -> V_161 |= V_352 ;
break;
case V_118 :
V_745 = F_40 ( V_14 , F_424 ( V_14 ) ) ;
if ( V_745 & V_772 )
V_2 -> V_161 |= V_352 ;
break;
case V_120 :
case V_121 :
#ifdef F_385
V_2 -> V_146 &= ~ V_741 ;
#endif
#ifdef F_180
V_2 -> V_146 &= ~ V_762 ;
#ifdef F_385
V_2 -> V_639 . V_640 = 0 ;
#endif
#endif
case V_119 :
#ifdef F_237
V_2 -> V_146 &= ~ V_211 ;
#endif
#ifdef F_425
V_2 -> V_146 |= V_773 ;
#endif
break;
default:
break;
}
#ifdef F_180
F_426 ( & V_2 -> V_639 . V_774 ) ;
#endif
F_426 ( & V_2 -> V_654 ) ;
#ifdef F_385
F_419 ( V_2 ) ;
#endif
V_14 -> V_132 . V_775 = V_134 ;
V_14 -> V_132 . V_133 = V_134 ;
F_360 ( V_2 ) ;
V_14 -> V_132 . V_776 = V_777 ;
V_14 -> V_132 . V_778 = true ;
V_14 -> V_132 . V_779 = F_427 ( V_14 ) ;
#ifdef F_314
if ( V_780 > 0 )
F_11 ( L_101 ) ;
if ( V_14 -> V_114 . type != V_115 ) {
if ( V_780 > V_781 ) {
V_2 -> V_324 = 0 ;
F_11 ( L_102 ) ;
} else {
V_2 -> V_324 = V_780 ;
}
}
#endif
V_2 -> V_406 = 1 ;
V_2 -> V_782 = 1 ;
V_2 -> V_783 = V_784 ;
V_2 -> V_785 = V_786 ;
switch ( V_14 -> V_114 . type ) {
case V_117 :
case V_120 :
case V_121 :
V_14 -> V_114 . V_357 . V_787 ( V_14 , & V_746 ) ;
if ( V_746 & V_788 )
V_2 -> V_789 = false ;
else
V_2 -> V_789 = true ;
break;
default:
V_2 -> V_789 = false ;
break;
}
V_2 -> V_790 = V_791 ;
if ( F_428 ( V_14 ) ) {
F_18 ( L_103 ) ;
return - V_792 ;
}
F_257 ( 0 , & V_2 -> V_670 ) ;
F_257 ( V_34 , & V_2 -> V_35 ) ;
return 0 ;
}
int F_429 ( struct V_64 * V_65 )
{
struct V_209 * V_80 = V_65 -> V_80 ;
int V_793 = F_430 ( V_80 ) ;
int V_794 = - 1 ;
int V_297 ;
V_297 = sizeof( struct V_66 ) * V_65 -> V_94 ;
if ( V_65 -> V_173 )
V_794 = V_65 -> V_173 -> V_795 ;
V_65 -> V_84 = F_431 ( V_297 , V_794 ) ;
if ( ! V_65 -> V_84 )
V_65 -> V_84 = F_432 ( V_297 ) ;
if ( ! V_65 -> V_84 )
goto V_17;
F_433 ( & V_65 -> V_185 ) ;
V_65 -> V_297 = V_65 -> V_94 * sizeof( union V_68 ) ;
V_65 -> V_297 = F_174 ( V_65 -> V_297 , 4096 ) ;
F_434 ( V_80 , V_794 ) ;
V_65 -> V_93 = F_435 ( V_80 ,
V_65 -> V_297 ,
& V_65 -> V_87 ,
V_765 ) ;
F_434 ( V_80 , V_793 ) ;
if ( ! V_65 -> V_93 )
V_65 -> V_93 = F_435 ( V_80 , V_65 -> V_297 ,
& V_65 -> V_87 , V_765 ) ;
if ( ! V_65 -> V_93 )
goto V_17;
V_65 -> V_86 = 0 ;
V_65 -> V_85 = 0 ;
return 0 ;
V_17:
F_436 ( V_65 -> V_84 ) ;
V_65 -> V_84 = NULL ;
F_437 ( V_80 , L_104 ) ;
return - V_585 ;
}
static int F_438 ( struct V_1 * V_2 )
{
int V_49 , V_17 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ ) {
V_17 = F_429 ( V_2 -> V_65 [ V_49 ] ) ;
if ( ! V_17 )
continue;
F_107 ( V_188 , L_105 , V_49 ) ;
goto V_796;
}
return 0 ;
V_796:
while ( V_49 -- )
F_439 ( V_2 -> V_65 [ V_49 ] ) ;
return V_17 ;
}
int F_440 ( struct V_64 * V_74 )
{
struct V_209 * V_80 = V_74 -> V_80 ;
int V_793 = F_430 ( V_80 ) ;
int V_794 = - 1 ;
int V_297 ;
V_297 = sizeof( struct V_77 ) * V_74 -> V_94 ;
if ( V_74 -> V_173 )
V_794 = V_74 -> V_173 -> V_795 ;
V_74 -> V_78 = F_431 ( V_297 , V_794 ) ;
if ( ! V_74 -> V_78 )
V_74 -> V_78 = F_432 ( V_297 ) ;
if ( ! V_74 -> V_78 )
goto V_17;
F_433 ( & V_74 -> V_185 ) ;
V_74 -> V_297 = V_74 -> V_94 * sizeof( union V_75 ) ;
V_74 -> V_297 = F_174 ( V_74 -> V_297 , 4096 ) ;
F_434 ( V_80 , V_794 ) ;
V_74 -> V_93 = F_435 ( V_80 ,
V_74 -> V_297 ,
& V_74 -> V_87 ,
V_765 ) ;
F_434 ( V_80 , V_793 ) ;
if ( ! V_74 -> V_93 )
V_74 -> V_93 = F_435 ( V_80 , V_74 -> V_297 ,
& V_74 -> V_87 , V_765 ) ;
if ( ! V_74 -> V_93 )
goto V_17;
V_74 -> V_85 = 0 ;
V_74 -> V_86 = 0 ;
return 0 ;
V_17:
F_436 ( V_74 -> V_78 ) ;
V_74 -> V_78 = NULL ;
F_437 ( V_80 , L_106 ) ;
return - V_585 ;
}
static int F_441 ( struct V_1 * V_2 )
{
int V_49 , V_17 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ ) {
V_17 = F_440 ( V_2 -> V_74 [ V_49 ] ) ;
if ( ! V_17 )
continue;
F_107 ( V_188 , L_107 , V_49 ) ;
goto V_797;
}
#ifdef F_180
V_17 = F_442 ( V_2 ) ;
if ( ! V_17 )
#endif
return 0 ;
V_797:
while ( V_49 -- )
F_443 ( V_2 -> V_74 [ V_49 ] ) ;
return V_17 ;
}
void F_439 ( struct V_64 * V_65 )
{
F_406 ( V_65 ) ;
F_436 ( V_65 -> V_84 ) ;
V_65 -> V_84 = NULL ;
if ( ! V_65 -> V_93 )
return;
F_444 ( V_65 -> V_80 , V_65 -> V_297 ,
V_65 -> V_93 , V_65 -> V_87 ) ;
V_65 -> V_93 = NULL ;
}
static void F_445 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ )
if ( V_2 -> V_65 [ V_49 ] -> V_93 )
F_439 ( V_2 -> V_65 [ V_49 ] ) ;
}
void F_443 ( struct V_64 * V_74 )
{
F_371 ( V_74 ) ;
F_436 ( V_74 -> V_78 ) ;
V_74 -> V_78 = NULL ;
if ( ! V_74 -> V_93 )
return;
F_444 ( V_74 -> V_80 , V_74 -> V_297 ,
V_74 -> V_93 , V_74 -> V_87 ) ;
V_74 -> V_93 = NULL ;
}
static void F_446 ( struct V_1 * V_2 )
{
int V_49 ;
#ifdef F_180
F_447 ( V_2 ) ;
#endif
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ )
if ( V_2 -> V_74 [ V_49 ] -> V_93 )
F_443 ( V_2 -> V_74 [ V_49 ] ) ;
}
static int F_448 ( struct V_61 * V_62 , int V_798 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
int V_528 = V_798 + V_529 + V_530 ;
if ( ( V_798 < 68 ) || ( V_528 > V_799 ) )
return - V_597 ;
if ( ( V_2 -> V_146 & V_435 ) &&
( V_2 -> V_14 . V_114 . type == V_117 ) &&
( V_528 > ( V_535 + V_530 ) ) )
F_27 ( V_188 , L_108 ) ;
F_109 ( V_188 , L_109 , V_62 -> V_312 , V_798 ) ;
V_62 -> V_312 = V_798 ;
if ( F_61 ( V_62 ) )
F_396 ( V_2 ) ;
return 0 ;
}
int F_449 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 , V_381 ;
if ( F_14 ( V_800 , & V_2 -> V_35 ) )
return - V_801 ;
F_412 ( V_62 ) ;
V_17 = F_438 ( V_2 ) ;
if ( V_17 )
goto V_796;
V_17 = F_441 ( V_2 ) ;
if ( V_17 )
goto V_797;
F_384 ( V_2 ) ;
V_17 = F_250 ( V_2 ) ;
if ( V_17 )
goto V_802;
if ( V_2 -> V_671 > 1 )
V_381 = V_2 -> V_662 ;
else
V_381 = V_2 -> V_83 ;
V_17 = F_378 ( V_62 , V_381 ) ;
if ( V_17 )
goto V_803;
if ( V_2 -> V_671 > 1 &&
V_2 -> V_99 > V_804 )
V_381 = V_804 ;
else
V_381 = V_2 -> V_99 ;
V_17 = F_379 ( V_62 , V_381 ) ;
if ( V_17 )
goto V_803;
F_450 ( V_2 ) ;
F_394 ( V_2 ) ;
F_343 ( V_2 ) ;
#ifdef F_425
F_451 ( V_62 ) ;
#endif
return 0 ;
V_803:
F_251 ( V_2 ) ;
V_802:
F_446 ( V_2 ) ;
if ( V_14 -> V_46 . V_357 . V_704 && ! V_2 -> V_720 )
V_14 -> V_46 . V_357 . V_704 ( & V_2 -> V_14 , false ) ;
V_797:
F_445 ( V_2 ) ;
V_796:
F_403 ( V_2 ) ;
return V_17 ;
}
static void F_452 ( struct V_1 * V_2 )
{
F_453 ( V_2 ) ;
if ( V_2 -> V_14 . V_46 . V_357 . V_805 ) {
V_2 -> V_14 . V_46 . V_806 = true ;
F_400 ( V_2 ) ;
V_2 -> V_14 . V_46 . V_357 . V_805 ( & V_2 -> V_14 ) ;
V_2 -> V_14 . V_46 . V_806 = false ;
} else {
F_400 ( V_2 ) ;
}
F_251 ( V_2 ) ;
F_445 ( V_2 ) ;
F_446 ( V_2 ) ;
}
int F_454 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
F_455 ( V_2 ) ;
F_452 ( V_2 ) ;
F_410 ( V_2 ) ;
F_74 ( V_2 ) ;
return 0 ;
}
static int F_456 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_457 ( V_9 ) ;
struct V_61 * V_62 = V_2 -> V_62 ;
T_1 V_17 ;
V_2 -> V_14 . V_41 = V_2 -> V_424 ;
F_458 ( V_9 , V_807 ) ;
F_459 ( V_9 ) ;
F_460 ( V_9 ) ;
V_17 = F_461 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_110 ) ;
return V_17 ;
}
F_36 () ;
F_37 ( V_808 , & V_2 -> V_35 ) ;
F_462 ( V_9 ) ;
F_463 ( V_9 , false ) ;
F_403 ( V_2 ) ;
F_75 ( & V_2 -> V_14 , V_809 , ~ 0 ) ;
F_464 () ;
V_17 = F_465 ( V_2 ) ;
if ( ! V_17 && F_61 ( V_62 ) )
V_17 = F_449 ( V_62 ) ;
F_466 () ;
if ( V_17 )
return V_17 ;
F_467 ( V_62 ) ;
return 0 ;
}
static int F_468 ( struct V_5 * V_9 , bool * V_810 )
{
struct V_1 * V_2 = F_457 ( V_9 ) ;
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_811 , V_602 ;
T_1 V_812 = V_2 -> V_720 ;
#ifdef F_469
int V_813 = 0 ;
#endif
F_470 ( V_62 ) ;
F_464 () ;
if ( F_61 ( V_62 ) )
F_452 ( V_2 ) ;
F_466 () ;
F_471 ( V_2 ) ;
#ifdef F_469
V_813 = F_460 ( V_9 ) ;
if ( V_813 )
return V_813 ;
#endif
if ( V_14 -> V_114 . V_357 . V_814 )
V_14 -> V_114 . V_357 . V_814 ( V_14 ) ;
if ( V_812 ) {
F_334 ( V_62 ) ;
if ( V_14 -> V_114 . V_357 . V_703 )
V_14 -> V_114 . V_357 . V_703 ( V_14 ) ;
if ( V_812 & V_815 ) {
V_602 = F_40 ( V_14 , V_606 ) ;
V_602 |= V_612 ;
F_75 ( V_14 , V_606 , V_602 ) ;
}
V_811 = F_40 ( V_14 , V_816 ) ;
V_811 |= V_817 ;
F_75 ( V_14 , V_816 , V_811 ) ;
F_75 ( V_14 , V_818 , V_812 ) ;
} else {
F_75 ( V_14 , V_819 , 0 ) ;
F_75 ( V_14 , V_818 , 0 ) ;
}
switch ( V_14 -> V_114 . type ) {
case V_115 :
F_463 ( V_9 , false ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
F_463 ( V_9 , ! ! V_812 ) ;
break;
default:
break;
}
* V_810 = ! ! V_812 ;
if ( V_14 -> V_46 . V_357 . V_704 && ! * V_810 )
V_14 -> V_46 . V_357 . V_704 ( V_14 , false ) ;
F_74 ( V_2 ) ;
if ( ! F_15 ( V_808 , & V_2 -> V_35 ) )
F_472 ( V_9 ) ;
return 0 ;
}
static int F_473 ( struct V_5 * V_9 , T_14 V_35 )
{
int V_813 ;
bool V_820 ;
V_813 = F_468 ( V_9 , & V_820 ) ;
if ( V_813 )
return V_813 ;
if ( V_820 ) {
F_474 ( V_9 ) ;
} else {
F_463 ( V_9 , false ) ;
F_458 ( V_9 , V_821 ) ;
}
return 0 ;
}
static void F_475 ( struct V_5 * V_9 )
{
bool V_820 ;
F_468 ( V_9 , & V_820 ) ;
if ( V_822 == V_823 ) {
F_463 ( V_9 , V_820 ) ;
F_458 ( V_9 , V_821 ) ;
}
}
void F_476 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_129 * V_130 = & V_2 -> V_131 ;
T_6 V_824 = 0 ;
T_1 V_49 , V_825 = 0 , V_826 , V_827 , V_828 , V_829 , V_830 ;
T_6 V_282 = 0 , V_190 = 0 , V_831 = 0 ;
T_6 V_253 = 0 , V_305 = 0 ;
T_6 V_186 = 0 , V_151 = 0 , V_832 = 0 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_710 , & V_2 -> V_35 ) )
return;
if ( V_2 -> V_161 & V_541 ) {
T_6 V_264 = 0 ;
T_6 V_265 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ ) {
V_264 += V_2 -> V_74 [ V_49 ] -> V_240 . V_264 ;
V_265 += V_2 -> V_74 [ V_49 ] -> V_240 . V_265 ;
}
V_2 -> V_833 = V_264 ;
V_2 -> V_834 = V_265 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ ) {
struct V_64 * V_74 = V_2 -> V_74 [ V_49 ] ;
V_282 += V_74 -> V_240 . V_282 ;
V_253 += V_74 -> V_240 . V_253 ;
V_305 += V_74 -> V_240 . V_305 ;
V_832 += V_74 -> V_240 . V_241 ;
V_186 += V_74 -> V_131 . V_186 ;
V_151 += V_74 -> V_131 . V_151 ;
}
V_2 -> V_282 = V_282 ;
V_2 -> V_253 = V_253 ;
V_2 -> V_305 = V_305 ;
V_2 -> V_832 = V_832 ;
V_62 -> V_131 . V_835 = V_186 ;
V_62 -> V_131 . V_836 = V_151 ;
V_186 = 0 ;
V_151 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ ) {
struct V_64 * V_65 = V_2 -> V_65 [ V_49 ] ;
V_190 += V_65 -> V_159 . V_190 ;
V_831 += V_65 -> V_159 . V_831 ;
V_186 += V_65 -> V_131 . V_186 ;
V_151 += V_65 -> V_131 . V_151 ;
}
V_2 -> V_190 = V_190 ;
V_2 -> V_831 = V_831 ;
V_62 -> V_131 . V_837 = V_186 ;
V_62 -> V_131 . V_838 = V_151 ;
V_130 -> V_839 += F_40 ( V_14 , V_840 ) ;
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
V_826 = F_40 ( V_14 , F_477 ( V_49 ) ) ;
V_825 += V_826 ;
V_130 -> V_826 [ V_49 ] += V_826 ;
V_824 += V_130 -> V_826 [ V_49 ] ;
V_130 -> V_841 [ V_49 ] += F_40 ( V_14 , F_478 ( V_49 ) ) ;
V_130 -> V_842 [ V_49 ] += F_40 ( V_14 , F_479 ( V_49 ) ) ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_130 -> V_843 [ V_49 ] += F_40 ( V_14 , F_480 ( V_49 ) ) ;
V_130 -> V_844 [ V_49 ] += F_40 ( V_14 , F_481 ( V_49 ) ) ;
V_130 -> V_845 [ V_49 ] += F_40 ( V_14 , F_482 ( V_49 ) ) ;
V_130 -> V_846 [ V_49 ] +=
F_40 ( V_14 , F_483 ( V_49 ) ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_130 -> V_846 [ V_49 ] +=
F_40 ( V_14 , F_484 ( V_49 ) ) ;
break;
default:
break;
}
}
for ( V_49 = 0 ; V_49 < 16 ; V_49 ++ ) {
V_130 -> V_847 [ V_49 ] += F_40 ( V_14 , F_485 ( V_49 ) ) ;
V_130 -> V_848 [ V_49 ] += F_40 ( V_14 , F_486 ( V_49 ) ) ;
if ( ( V_14 -> V_114 . type == V_117 ) ||
( V_14 -> V_114 . type == V_118 ) ||
( V_14 -> V_114 . type == V_119 ) ||
( V_14 -> V_114 . type == V_120 ) ||
( V_14 -> V_114 . type == V_121 ) ) {
V_130 -> V_844 [ V_49 ] += F_40 ( V_14 , F_487 ( V_49 ) ) ;
F_40 ( V_14 , F_488 ( V_49 ) ) ;
V_130 -> V_845 [ V_49 ] += F_40 ( V_14 , F_489 ( V_49 ) ) ;
F_40 ( V_14 , F_490 ( V_49 ) ) ;
}
}
V_130 -> V_849 += F_40 ( V_14 , V_850 ) ;
V_130 -> V_849 -= V_825 ;
F_87 ( V_2 ) ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_130 -> V_851 += F_40 ( V_14 , V_852 ) ;
V_130 -> V_853 += F_40 ( V_14 , V_854 ) ;
V_130 -> V_855 += F_40 ( V_14 , V_856 ) ;
V_130 -> V_857 += F_40 ( V_14 , V_858 ) ;
break;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_130 -> V_859 += F_40 ( V_14 , V_860 ) ;
V_130 -> V_861 += F_40 ( V_14 , V_862 ) ;
V_130 -> V_863 += F_40 ( V_14 , V_864 ) ;
V_130 -> V_865 += F_40 ( V_14 , V_866 ) ;
case V_117 :
for ( V_49 = 0 ; V_49 < 16 ; V_49 ++ )
V_2 -> V_867 +=
F_40 ( V_14 , F_491 ( V_49 ) ) ;
V_130 -> V_853 += F_40 ( V_14 , V_868 ) ;
F_40 ( V_14 , V_854 ) ;
V_130 -> V_855 += F_40 ( V_14 , V_869 ) ;
F_40 ( V_14 , V_856 ) ;
V_130 -> V_857 += F_40 ( V_14 , V_870 ) ;
F_40 ( V_14 , V_858 ) ;
V_130 -> V_851 += F_40 ( V_14 , V_871 ) ;
V_130 -> V_872 += F_40 ( V_14 , V_873 ) ;
V_130 -> V_874 += F_40 ( V_14 , V_875 ) ;
#ifdef F_180
V_130 -> V_876 += F_40 ( V_14 , V_877 ) ;
V_130 -> V_878 += F_40 ( V_14 , V_879 ) ;
V_130 -> V_880 += F_40 ( V_14 , V_881 ) ;
V_130 -> V_882 += F_40 ( V_14 , V_883 ) ;
V_130 -> V_884 += F_40 ( V_14 , V_885 ) ;
V_130 -> V_886 += F_40 ( V_14 , V_887 ) ;
if ( V_2 -> V_639 . V_888 ) {
struct V_889 * V_639 = & V_2 -> V_639 ;
struct V_890 * V_888 ;
unsigned int V_191 ;
T_6 V_891 = 0 , V_892 = 0 ;
F_492 (cpu) {
V_888 = F_493 ( V_639 -> V_888 , V_191 ) ;
V_891 += V_888 -> V_891 ;
V_892 += V_888 -> V_892 ;
}
V_130 -> V_893 = V_891 ;
V_130 -> V_894 = V_892 ;
}
#endif
break;
default:
break;
}
V_827 = F_40 ( V_14 , V_895 ) ;
V_130 -> V_827 += V_827 ;
V_130 -> V_896 += F_40 ( V_14 , V_897 ) ;
if ( V_14 -> V_114 . type == V_115 )
V_130 -> V_896 -= V_827 ;
V_130 -> V_898 += F_40 ( V_14 , V_899 ) ;
V_130 -> V_900 += F_40 ( V_14 , V_901 ) ;
V_130 -> V_902 += F_40 ( V_14 , V_903 ) ;
V_130 -> V_904 += F_40 ( V_14 , V_905 ) ;
V_130 -> V_906 += F_40 ( V_14 , V_907 ) ;
V_130 -> V_908 += F_40 ( V_14 , V_909 ) ;
V_130 -> V_910 += F_40 ( V_14 , V_911 ) ;
V_130 -> V_912 += F_40 ( V_14 , V_913 ) ;
V_828 = F_40 ( V_14 , V_914 ) ;
V_130 -> V_915 += V_828 ;
V_829 = F_40 ( V_14 , V_916 ) ;
V_130 -> V_917 += V_829 ;
V_130 -> V_918 += F_40 ( V_14 , V_919 ) ;
V_130 -> V_920 += F_40 ( V_14 , V_921 ) ;
V_830 = V_828 + V_829 ;
V_130 -> V_918 -= V_830 ;
V_130 -> V_920 -= V_830 ;
V_130 -> V_855 -= ( V_830 * ( V_922 + V_530 ) ) ;
V_130 -> V_923 += F_40 ( V_14 , V_924 ) ;
V_130 -> V_925 += F_40 ( V_14 , V_926 ) ;
V_130 -> V_927 += F_40 ( V_14 , V_928 ) ;
V_130 -> V_929 += F_40 ( V_14 , V_930 ) ;
V_130 -> V_931 += F_40 ( V_14 , V_932 ) ;
V_130 -> V_931 -= V_830 ;
V_130 -> V_933 += F_40 ( V_14 , V_934 ) ;
V_130 -> V_935 += F_40 ( V_14 , V_936 ) ;
V_130 -> V_937 += F_40 ( V_14 , V_938 ) ;
V_130 -> V_939 += F_40 ( V_14 , V_940 ) ;
V_130 -> V_941 += F_40 ( V_14 , V_942 ) ;
V_130 -> V_943 += F_40 ( V_14 , V_944 ) ;
V_62 -> V_131 . V_945 = V_130 -> V_896 ;
V_62 -> V_131 . V_946 = V_130 -> V_839 + V_130 -> V_912 ;
V_62 -> V_131 . V_947 = 0 ;
V_62 -> V_131 . V_948 = V_130 -> V_912 ;
V_62 -> V_131 . V_949 = V_130 -> V_839 ;
V_62 -> V_131 . V_950 = V_824 ;
}
static void F_494 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( ! ( V_2 -> V_161 & V_390 ) )
return;
V_2 -> V_161 &= ~ V_390 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
if ( ! ( V_2 -> V_146 & V_389 ) )
return;
V_2 -> V_951 ++ ;
if ( F_495 ( V_14 ) == 0 ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ )
F_257 ( V_399 ,
& ( V_2 -> V_65 [ V_49 ] -> V_35 ) ) ;
F_75 ( V_14 , V_380 , V_391 ) ;
} else {
F_107 ( V_188 , L_111
L_112 ) ;
}
}
static void F_496 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_952 = 0 ;
int V_49 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_710 , & V_2 -> V_35 ) )
return;
if ( F_113 ( V_2 -> V_62 ) ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ )
F_497 ( V_2 -> V_65 [ V_49 ] ) ;
}
if ( ! ( V_2 -> V_146 & V_415 ) ) {
F_75 ( V_14 , V_126 ,
( V_953 | V_954 ) ) ;
} else {
for ( V_49 = 0 ; V_49 < V_2 -> V_208 ; V_49 ++ ) {
struct V_172 * V_955 = V_2 -> V_173 [ V_49 ] ;
if ( V_955 -> V_316 . V_127 || V_955 -> V_178 . V_127 )
V_952 |= F_241 ( V_49 ) ;
}
}
F_79 ( V_2 , V_952 ) ;
}
static void F_498 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_956 = V_2 -> V_956 ;
bool V_359 = V_2 -> V_359 ;
bool V_142 = V_2 -> V_143 . V_144 ;
if ( ! ( V_2 -> V_146 & V_376 ) )
return;
if ( V_14 -> V_114 . V_357 . V_358 ) {
V_14 -> V_114 . V_357 . V_358 ( V_14 , & V_956 , & V_359 , false ) ;
} else {
V_956 = V_957 ;
V_359 = true ;
}
if ( V_2 -> V_789 ) {
T_1 V_958 ;
V_958 = F_40 ( V_14 , V_706 ) &
V_959 ;
if ( F_217 ( V_14 ) && V_359 && ! V_958 )
V_359 = false ;
}
if ( V_2 -> V_145 )
V_142 |= ! ! ( V_2 -> V_145 -> V_142 ) ;
if ( V_359 && ! ( ( V_2 -> V_146 & V_147 ) && V_142 ) ) {
V_14 -> V_114 . V_357 . V_960 ( V_14 ) ;
F_499 ( V_2 ) ;
}
if ( V_359 ||
F_500 ( V_187 , ( V_2 -> V_377 +
V_961 ) ) ) {
V_2 -> V_146 &= ~ V_376 ;
F_75 ( V_14 , V_380 , V_379 ) ;
F_221 ( V_14 ) ;
}
V_2 -> V_359 = V_359 ;
V_2 -> V_956 = V_956 ;
}
static void F_501 ( struct V_1 * V_2 )
{
#ifdef F_385
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_962 V_963 = {
. V_964 = V_965 ,
. V_272 = 0 ,
} ;
T_4 V_640 = 0 ;
if ( V_2 -> V_625 & V_966 )
V_640 = F_502 ( V_62 , & V_963 ) ;
V_2 -> V_967 = ( V_640 > 1 ) ? ( F_503 ( V_640 ) - 1 ) : 0 ;
#endif
}
static void F_504 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_61 * V_101 ;
struct V_674 * V_675 ;
T_1 V_956 = V_2 -> V_956 ;
const char * V_968 ;
bool V_969 , V_970 ;
if ( F_113 ( V_62 ) )
return;
V_2 -> V_161 &= ~ V_681 ;
switch ( V_14 -> V_114 . type ) {
case V_115 : {
T_1 V_971 = F_40 ( V_14 , V_606 ) ;
T_1 V_972 = F_40 ( V_14 , V_973 ) ;
V_969 = ! ! ( V_971 & V_974 ) ;
V_970 = ! ! ( V_972 & V_975 ) ;
}
break;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_117 : {
T_1 V_976 = F_40 ( V_14 , V_977 ) ;
T_1 V_978 = F_40 ( V_14 , V_979 ) ;
V_969 = ! ! ( V_976 & V_980 ) ;
V_970 = ! ! ( V_978 & V_981 ) ;
}
break;
default:
V_970 = false ;
V_969 = false ;
break;
}
V_2 -> V_982 = V_187 ;
if ( F_14 ( V_719 , & V_2 -> V_35 ) )
F_505 ( V_2 ) ;
switch ( V_956 ) {
case V_957 :
V_968 = L_113 ;
break;
case V_983 :
V_968 = L_114 ;
break;
case V_984 :
V_968 = L_115 ;
break;
case V_985 :
V_968 = L_116 ;
break;
default:
V_968 = L_117 ;
break;
}
F_109 ( V_163 , L_118 , V_968 ,
( ( V_969 && V_970 ) ? L_119 :
( V_969 ? L_120 :
( V_970 ? L_121 : L_122 ) ) ) ) ;
F_506 ( V_62 ) ;
F_507 ( V_2 ) ;
F_508 ( V_2 -> V_62 ) ;
F_464 () ;
F_382 (adapter->netdev, upper, iter) {
if ( F_383 ( V_101 ) ) {
struct V_676 * V_270 = F_93 ( V_101 ) ;
if ( V_270 -> V_678 )
F_508 ( V_101 ) ;
}
}
F_466 () ;
F_501 ( V_2 ) ;
F_415 ( V_2 ) ;
}
static void F_509 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_359 = false ;
V_2 -> V_956 = 0 ;
if ( ! F_113 ( V_62 ) )
return;
if ( F_217 ( V_14 ) && V_14 -> V_114 . type == V_115 )
V_2 -> V_161 |= V_681 ;
if ( F_14 ( V_719 , & V_2 -> V_35 ) )
F_505 ( V_2 ) ;
F_109 ( V_163 , L_123 ) ;
F_412 ( V_62 ) ;
F_415 ( V_2 ) ;
}
static bool F_510 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ ) {
struct V_64 * V_65 = V_2 -> V_65 [ V_49 ] ;
if ( V_65 -> V_86 != V_65 -> V_85 )
return true ;
}
return false ;
}
static bool F_511 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_986 * V_987 = & V_2 -> V_440 [ V_518 ] ;
T_1 V_988 = F_512 ( 1 , ~ V_987 -> V_124 ) ;
int V_49 , V_56 ;
if ( ! V_2 -> V_324 )
return false ;
if ( V_14 -> V_114 . type >= V_119 )
return false ;
for ( V_49 = 0 ; V_49 < V_2 -> V_324 ; V_49 ++ ) {
for ( V_56 = 0 ; V_56 < V_988 ; V_56 ++ ) {
T_1 V_989 , V_990 ;
V_989 = F_40 ( V_14 , F_513 ( V_988 , V_49 , V_56 ) ) ;
V_990 = F_40 ( V_14 , F_514 ( V_988 , V_49 , V_56 ) ) ;
if ( V_989 != V_990 )
return true ;
}
}
return false ;
}
static void F_515 ( struct V_1 * V_2 )
{
if ( ! F_113 ( V_2 -> V_62 ) ) {
if ( F_510 ( V_2 ) ||
F_511 ( V_2 ) ) {
F_27 ( V_163 , L_124 ) ;
V_2 -> V_161 |= V_162 ;
}
}
}
static inline void F_516 ( struct V_1 * V_2 ,
struct V_5 * V_991 )
{
if ( ! F_517 ( V_991 ) )
F_11 ( L_125 ) ;
F_18 ( L_126 , F_518 ( V_991 ) ) ;
F_519 ( V_991 , V_992 , V_993 ) ;
F_401 ( 100 ) ;
}
static void F_520 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_994 ;
T_1 V_995 ;
if ( ! ( F_113 ( V_2 -> V_62 ) ) )
return;
V_995 = F_40 ( V_14 , V_996 ) ;
if ( V_995 )
return;
if ( ! V_9 )
return;
for ( V_994 = 0 ; V_994 < V_2 -> V_324 ; ++ V_994 ) {
struct V_5 * V_991 = V_2 -> V_525 [ V_994 ] . V_991 ;
T_2 V_997 ;
if ( ! V_991 )
continue;
F_28 ( V_991 , V_998 , & V_997 ) ;
if ( V_997 != V_13 &&
V_997 & V_999 )
F_516 ( V_2 , V_991 ) ;
}
}
static void F_521 ( struct V_1 * V_2 )
{
T_1 V_1000 ;
if ( V_2 -> V_14 . V_114 . type == V_115 ||
V_2 -> V_324 == 0 )
return;
V_1000 = F_40 ( & V_2 -> V_14 , V_1001 ) ;
if ( ! V_1000 )
return;
F_27 ( V_163 , L_127 , V_1000 ) ;
}
static void F_521 ( struct V_1 T_15 * V_2 )
{
}
static void
F_520 ( struct V_1 T_15 * V_2 )
{
}
static void F_522 ( struct V_1 * V_2 )
{
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_710 , & V_2 -> V_35 ) )
return;
F_498 ( V_2 ) ;
if ( V_2 -> V_359 )
F_504 ( V_2 ) ;
else
F_509 ( V_2 ) ;
F_520 ( V_2 ) ;
F_521 ( V_2 ) ;
F_476 ( V_2 ) ;
F_515 ( V_2 ) ;
}
static void F_523 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_3 V_17 ;
if ( V_2 -> V_789 ) {
T_1 V_958 ;
V_958 = F_40 ( V_14 , V_706 ) &
V_959 ;
if ( ! V_958 )
return;
}
if ( ! ( V_2 -> V_161 & V_681 ) &&
! ( V_2 -> V_161 & V_372 ) )
return;
if ( V_2 -> V_373 &&
F_500 ( V_2 -> V_373 , V_187 ) )
return;
if ( F_15 ( V_711 , & V_2 -> V_35 ) )
return;
V_2 -> V_373 = V_187 + V_1002 - 1 ;
V_17 = V_14 -> V_46 . V_357 . V_1003 ( V_14 ) ;
if ( V_17 == V_714 )
goto V_1004;
if ( V_17 == V_713 ) {
V_2 -> V_161 |= V_372 ;
}
if ( V_17 )
goto V_1004;
if ( ! ( V_2 -> V_161 & V_372 ) )
goto V_1004;
V_2 -> V_161 &= ~ V_372 ;
if ( V_14 -> V_114 . type == V_115 )
V_17 = V_14 -> V_46 . V_357 . V_1005 ( V_14 ) ;
else
V_17 = V_14 -> V_114 . V_357 . V_1006 ( V_14 ) ;
if ( V_17 == V_714 )
goto V_1004;
V_2 -> V_146 |= V_374 ;
F_109 ( V_188 , L_128 , V_14 -> V_46 . V_1007 ) ;
V_1004:
F_37 ( V_711 , & V_2 -> V_35 ) ;
if ( ( V_17 == V_714 ) &&
( V_2 -> V_62 -> V_1008 == V_1009 ) ) {
F_18 ( L_129
L_130 ) ;
F_18 ( L_131
L_132 ) ;
F_524 ( V_2 -> V_62 ) ;
}
}
static void F_525 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_20 ;
bool V_682 = false ;
if ( ! ( V_2 -> V_146 & V_374 ) )
return;
if ( F_15 ( V_711 , & V_2 -> V_35 ) )
return;
V_2 -> V_146 &= ~ V_374 ;
V_20 = V_14 -> V_46 . V_684 ;
if ( ( ! V_20 ) && ( V_14 -> V_114 . V_357 . V_685 ) ) {
V_14 -> V_114 . V_357 . V_685 ( V_14 , & V_20 , & V_682 ) ;
if ( ! V_682 ) {
if ( V_20 & V_957 )
V_20 = V_957 ;
}
}
if ( V_14 -> V_114 . V_357 . V_686 )
V_14 -> V_114 . V_357 . V_686 ( V_14 , V_20 , true ) ;
V_2 -> V_146 |= V_376 ;
V_2 -> V_377 = V_187 ;
F_37 ( V_711 , & V_2 -> V_35 ) ;
}
static void F_526 ( unsigned long V_98 )
{
struct V_1 * V_2 = (struct V_1 * ) V_98 ;
unsigned long V_1010 ;
if ( V_2 -> V_146 & V_376 )
V_1010 = V_1011 / 10 ;
else
V_1010 = V_1011 * 2 ;
F_395 ( & V_2 -> V_708 , V_1010 + V_187 ) ;
F_13 ( V_2 ) ;
}
static void F_527 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_181 ;
if ( ! ( V_2 -> V_161 & V_394 ) )
return;
V_2 -> V_161 &= ~ V_394 ;
if ( ! V_14 -> V_46 . V_357 . V_1012 )
return;
V_181 = V_14 -> V_46 . V_357 . V_1012 ( & V_2 -> V_14 ) ;
if ( V_181 != V_361 )
return;
F_213 ( V_163 , L_71 , V_362 ) ;
}
static void F_528 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_161 & V_162 ) )
return;
V_2 -> V_161 &= ~ V_162 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_710 , & V_2 -> V_35 ) )
return;
F_57 ( V_2 ) ;
F_529 ( V_2 -> V_62 , L_133 ) ;
V_2 -> V_189 ++ ;
F_464 () ;
F_396 ( V_2 ) ;
F_466 () ;
}
static void F_530 ( struct V_1013 * V_1014 )
{
struct V_1 * V_2 = F_200 ( V_1014 ,
struct V_1 ,
V_39 ) ;
if ( F_22 ( V_2 -> V_14 . V_41 ) ) {
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_464 () ;
F_400 ( V_2 ) ;
F_466 () ;
}
F_34 ( V_2 ) ;
return;
}
#ifdef F_425
F_464 () ;
if ( V_2 -> V_161 & V_1015 ) {
V_2 -> V_161 &= ~ V_1015 ;
F_451 ( V_2 -> V_62 ) ;
}
F_466 () ;
#endif
F_528 ( V_2 ) ;
F_527 ( V_2 ) ;
F_523 ( V_2 ) ;
F_525 ( V_2 ) ;
F_211 ( V_2 ) ;
F_522 ( V_2 ) ;
F_494 ( V_2 ) ;
F_496 ( V_2 ) ;
if ( F_14 ( V_719 , & V_2 -> V_35 ) ) {
F_531 ( V_2 ) ;
F_532 ( V_2 ) ;
}
F_34 ( V_2 ) ;
}
static int F_533 ( struct V_64 * V_65 ,
struct V_66 * V_1016 ,
T_4 * V_259 )
{
T_1 V_1017 , V_1018 , V_1019 ;
struct V_214 * V_95 = V_1016 -> V_95 ;
union {
struct V_1020 * V_1021 ;
struct V_1022 * V_1023 ;
unsigned char * V_1024 ;
} V_1025 ;
union {
struct V_1026 * V_1027 ;
unsigned char * V_1024 ;
} V_1028 ;
T_1 V_1029 , V_1030 ;
int V_17 ;
if ( V_95 -> V_246 != V_1031 )
return 0 ;
if ( ! F_534 ( V_95 ) )
return 0 ;
V_17 = F_535 ( V_95 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_1025 . V_1024 = F_536 ( V_95 ) ;
V_1028 . V_1024 = F_537 ( V_95 ) ;
V_1018 = V_1032 ;
if ( V_1025 . V_1021 -> V_1033 == 4 ) {
V_1025 . V_1021 -> V_1034 = F_538 ( F_539 ( F_540 ( V_95 ) ,
F_541 ( V_1028 . V_1027 -> V_1034 ) ) ) ;
V_1018 |= V_1035 ;
V_1025 . V_1021 -> V_1036 = 0 ;
V_1016 -> V_1037 |= V_1038 |
V_1039 |
V_1040 ;
} else {
V_1025 . V_1023 -> V_1041 = 0 ;
V_1016 -> V_1037 |= V_1038 |
V_1039 ;
}
V_1030 = V_1028 . V_1024 - V_95 -> V_98 ;
* V_259 = ( V_1028 . V_1027 -> V_1042 * 4 ) + V_1030 ;
V_1029 = V_95 -> V_88 - V_1030 ;
F_542 ( & V_1028 . V_1027 -> V_1034 , F_543 ( V_1029 ) ) ;
V_1016 -> V_184 = F_153 ( V_95 ) -> V_184 ;
V_1016 -> V_183 += ( V_1016 -> V_184 - 1 ) * * V_259 ;
V_1019 = ( * V_259 - V_1030 ) << V_1043 ;
V_1019 |= F_153 ( V_95 ) -> V_260 << V_1044 ;
V_1017 = V_1028 . V_1024 - V_1025 . V_1024 ;
V_1017 |= ( V_1025 . V_1024 - V_95 -> V_98 ) << V_1045 ;
V_1017 |= V_1016 -> V_1037 & V_1046 ;
F_544 ( V_65 , V_1017 , 0 , V_1018 ,
V_1019 ) ;
return 1 ;
}
static inline bool F_545 ( struct V_214 * V_95 )
{
unsigned int V_1047 = 0 ;
F_546 ( V_95 , & V_1047 , V_1048 , NULL , NULL ) ;
return V_1047 == F_547 ( V_95 ) ;
}
static void F_548 ( struct V_64 * V_65 ,
struct V_66 * V_1016 )
{
struct V_214 * V_95 = V_1016 -> V_95 ;
T_1 V_1017 = 0 ;
T_1 V_1018 = 0 ;
if ( V_95 -> V_246 != V_1031 ) {
V_1049:
if ( ! ( V_1016 -> V_1037 & ( V_1050 |
V_1051 ) ) )
return;
goto V_1052;
}
switch ( V_95 -> V_1053 ) {
case F_549 ( struct V_1026 , V_1034 ) :
V_1018 = V_1032 ;
case F_549 ( struct V_1054 , V_1034 ) :
break;
case F_549 ( struct V_1055 , V_1056 ) :
if ( ( ( V_1016 -> V_272 == F_160 ( V_1057 ) ) &&
( F_550 ( V_95 ) -> V_272 == V_1048 ) ) ||
( ( V_1016 -> V_272 == F_160 ( V_1058 ) ) &&
F_545 ( V_95 ) ) ) {
V_1018 = V_1059 ;
break;
}
default:
F_551 ( V_95 ) ;
goto V_1049;
}
V_1016 -> V_1037 |= V_1039 ;
V_1017 = F_547 ( V_95 ) -
F_552 ( V_95 ) ;
V_1052:
V_1017 |= F_552 ( V_95 ) << V_1045 ;
V_1017 |= V_1016 -> V_1037 & V_1046 ;
F_544 ( V_65 , V_1017 , 0 , V_1018 , 0 ) ;
}
static T_1 F_553 ( struct V_214 * V_95 , T_1 V_1037 )
{
T_1 V_1060 = V_1061 |
V_1062 |
V_1063 ;
V_1060 |= F_554 ( V_1037 , V_1050 ,
V_1064 ) ;
V_1060 |= F_554 ( V_1037 , V_1038 ,
V_1065 ) ;
V_1060 |= F_554 ( V_1037 , V_1066 ,
V_1067 ) ;
V_1060 ^= F_554 ( V_95 -> V_1068 , 1 , V_1063 ) ;
return V_1060 ;
}
static void F_555 ( union V_68 * V_69 ,
T_1 V_1037 , unsigned int V_1029 )
{
T_1 V_1069 = V_1029 << V_1070 ;
V_1069 |= F_554 ( V_1037 ,
V_1039 ,
V_1071 ) ;
V_1069 |= F_554 ( V_1037 ,
V_1040 ,
V_1072 ) ;
V_1069 |= F_554 ( V_1037 ,
V_1051 ,
V_1073 ) ;
V_69 -> V_256 . V_1069 = F_101 ( V_1069 ) ;
}
static int F_556 ( struct V_64 * V_65 , T_2 V_297 )
{
F_108 ( V_65 -> V_62 , V_65 -> V_92 ) ;
F_115 () ;
if ( F_25 ( F_114 ( V_65 ) < V_297 ) )
return - V_801 ;
F_557 ( V_65 -> V_62 , V_65 -> V_92 ) ;
++ V_65 -> V_159 . V_190 ;
return 0 ;
}
static inline int F_558 ( struct V_64 * V_65 , T_2 V_297 )
{
if ( F_25 ( F_114 ( V_65 ) >= V_297 ) )
return 0 ;
return F_556 ( V_65 , V_297 ) ;
}
static void F_559 ( struct V_64 * V_65 ,
struct V_66 * V_1016 ,
const T_4 V_259 )
{
struct V_214 * V_95 = V_1016 -> V_95 ;
struct V_66 * V_67 ;
union V_68 * V_69 ;
struct V_283 * V_284 ;
T_9 V_87 ;
unsigned int V_289 , V_297 ;
T_1 V_1037 = V_1016 -> V_1037 ;
T_1 V_1060 = F_553 ( V_95 , V_1037 ) ;
T_2 V_49 = V_65 -> V_86 ;
V_69 = F_65 ( V_65 , V_49 ) ;
F_555 ( V_69 , V_1037 , V_95 -> V_88 - V_259 ) ;
V_297 = F_152 ( V_95 ) ;
V_289 = V_95 -> V_289 ;
#ifdef F_180
if ( V_1037 & V_1074 ) {
if ( V_289 < sizeof( struct V_315 ) ) {
V_297 -= sizeof( struct V_315 ) - V_289 ;
V_289 = 0 ;
} else {
V_289 -= sizeof( struct V_315 ) ;
}
}
#endif
V_87 = F_560 ( V_65 -> V_80 , V_95 -> V_98 , V_297 , V_128 ) ;
V_67 = V_1016 ;
for ( V_284 = & F_153 ( V_95 ) -> V_285 [ 0 ] ; ; V_284 ++ ) {
if ( F_145 ( V_65 -> V_80 , V_87 ) )
goto V_1075;
F_85 ( V_67 , V_88 , V_297 ) ;
F_561 ( V_67 , V_87 , V_87 ) ;
V_69 -> V_256 . V_1076 = F_148 ( V_87 ) ;
while ( F_23 ( V_297 > V_1077 ) ) {
V_69 -> V_256 . V_1078 =
F_101 ( V_1060 ^ V_1077 ) ;
V_49 ++ ;
V_69 ++ ;
if ( V_49 == V_65 -> V_94 ) {
V_69 = F_65 ( V_65 , 0 ) ;
V_49 = 0 ;
}
V_69 -> V_256 . V_1069 = 0 ;
V_87 += V_1077 ;
V_297 -= V_1077 ;
V_69 -> V_256 . V_1076 = F_148 ( V_87 ) ;
}
if ( F_25 ( ! V_289 ) )
break;
V_69 -> V_256 . V_1078 = F_101 ( V_1060 ^ V_297 ) ;
V_49 ++ ;
V_69 ++ ;
if ( V_49 == V_65 -> V_94 ) {
V_69 = F_65 ( V_65 , 0 ) ;
V_49 = 0 ;
}
V_69 -> V_256 . V_1069 = 0 ;
#ifdef F_180
V_297 = F_332 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_297 = F_562 ( V_284 ) ;
#endif
V_289 -= V_297 ;
V_87 = F_563 ( V_65 -> V_80 , V_284 , 0 , V_297 ,
V_128 ) ;
V_67 = & V_65 -> V_84 [ V_49 ] ;
}
V_1060 |= V_297 | V_1079 ;
V_69 -> V_256 . V_1078 = F_101 ( V_1060 ) ;
F_564 ( F_111 ( V_65 ) , V_1016 -> V_183 ) ;
V_1016 -> V_90 = V_187 ;
F_149 () ;
V_1016 -> V_89 = V_69 ;
V_49 ++ ;
if ( V_49 == V_65 -> V_94 )
V_49 = 0 ;
V_65 -> V_86 = V_49 ;
F_558 ( V_65 , V_1080 ) ;
if ( F_565 ( F_111 ( V_65 ) ) || ! V_95 -> V_1081 ) {
F_150 ( V_49 , V_65 -> V_153 ) ;
F_566 () ;
}
return;
V_1075:
F_437 ( V_65 -> V_80 , L_134 ) ;
for (; ; ) {
V_67 = & V_65 -> V_84 [ V_49 ] ;
F_81 ( V_65 , V_67 ) ;
if ( V_67 == V_1016 )
break;
if ( V_49 == 0 )
V_49 = V_65 -> V_94 ;
V_49 -- ;
}
V_65 -> V_86 = V_49 ;
}
static void F_567 ( struct V_64 * V_127 ,
struct V_66 * V_1016 )
{
struct V_172 * V_173 = V_127 -> V_173 ;
union V_1082 V_1083 = { . V_1084 = 0 } ;
union V_1082 V_1085 = { . V_1084 = 0 } ;
union {
unsigned char * V_1086 ;
struct V_1020 * V_1087 ;
struct V_1022 * V_1088 ;
} V_1024 ;
struct V_1026 * V_1089 ;
unsigned int V_1090 ;
struct V_214 * V_95 ;
T_12 V_1091 ;
int V_1092 ;
if ( ! V_173 )
return;
if ( ! V_127 -> V_425 )
return;
V_127 -> V_426 ++ ;
if ( ( V_1016 -> V_272 != F_160 ( V_1057 ) ) &&
( V_1016 -> V_272 != F_160 ( V_1058 ) ) )
return;
V_95 = V_1016 -> V_95 ;
V_1024 . V_1086 = F_536 ( V_95 ) ;
#ifdef F_425
if ( V_95 -> V_237 &&
V_1016 -> V_272 == F_160 ( V_1057 ) &&
V_1024 . V_1087 -> V_272 != V_1093 ) {
struct V_1 * V_2 = V_173 -> V_2 ;
if ( V_2 -> V_623 &&
F_568 ( V_95 ) -> V_1094 == V_2 -> V_623 )
V_1024 . V_1086 = F_569 ( V_95 ) ;
}
#endif
switch ( V_1024 . V_1087 -> V_1033 ) {
case V_1095 :
V_1090 = ( V_1024 . V_1086 [ 0 ] & 0x0F ) << 2 ;
V_1092 = V_1024 . V_1087 -> V_272 ;
break;
case 6 :
V_1090 = V_1024 . V_1086 - V_95 -> V_98 ;
V_1092 = F_546 ( V_95 , & V_1090 , V_1096 , NULL , NULL ) ;
V_1090 -= V_1024 . V_1086 - V_95 -> V_98 ;
break;
default:
return;
}
if ( V_1092 != V_1096 )
return;
V_1089 = (struct V_1026 * ) ( V_1024 . V_1086 + V_1090 ) ;
if ( V_1089 -> V_1097 )
return;
if ( ! V_1089 -> V_1098 && ( V_127 -> V_426 < V_127 -> V_425 ) )
return;
V_127 -> V_426 = 0 ;
V_1091 = F_160 ( V_1016 -> V_1037 >> V_1099 ) ;
V_1083 . V_1100 . V_1091 = V_1091 ;
if ( V_1016 -> V_1037 & ( V_1101 | V_1050 ) )
V_1085 . V_1102 . V_1103 ^= V_1089 -> V_1094 ^ F_160 ( V_271 ) ;
else
V_1085 . V_1102 . V_1103 ^= V_1089 -> V_1094 ^ V_1016 -> V_272 ;
V_1085 . V_1102 . V_1104 ^= V_1089 -> V_1105 ;
switch ( V_1024 . V_1087 -> V_1033 ) {
case V_1095 :
V_1083 . V_1100 . V_1106 = V_1107 ;
V_1085 . V_1025 ^= V_1024 . V_1087 -> V_1108 ^ V_1024 . V_1087 -> V_1109 ;
break;
case 6 :
V_1083 . V_1100 . V_1106 = V_1110 ;
V_1085 . V_1025 ^= V_1024 . V_1088 -> V_1108 . V_1111 [ 0 ] ^
V_1024 . V_1088 -> V_1108 . V_1111 [ 1 ] ^
V_1024 . V_1088 -> V_1108 . V_1111 [ 2 ] ^
V_1024 . V_1088 -> V_1108 . V_1111 [ 3 ] ^
V_1024 . V_1088 -> V_1109 . V_1111 [ 0 ] ^
V_1024 . V_1088 -> V_1109 . V_1111 [ 1 ] ^
V_1024 . V_1088 -> V_1109 . V_1111 [ 2 ] ^
V_1024 . V_1088 -> V_1109 . V_1111 [ 3 ] ;
break;
default:
break;
}
if ( V_1024 . V_1086 != F_536 ( V_95 ) )
V_1083 . V_1100 . V_1106 |= V_1112 ;
F_570 ( & V_173 -> V_2 -> V_14 ,
V_1083 , V_1085 , V_127 -> V_92 ) ;
}
static T_2 F_571 ( struct V_61 * V_80 , struct V_214 * V_95 ,
void * V_1113 , T_16 V_1114 )
{
struct V_660 * V_1115 = V_1113 ;
#ifdef F_180
struct V_1 * V_2 ;
struct V_986 * V_1116 ;
int V_1117 ;
#endif
if ( V_1115 )
return V_95 -> V_1118 + V_1115 -> V_668 ;
#ifdef F_180
switch ( F_572 ( V_95 ) ) {
case F_160 ( V_1119 ) :
case F_160 ( V_1120 ) :
V_2 = F_93 ( V_80 ) ;
if ( V_2 -> V_146 & V_533 )
break;
default:
return V_1114 ( V_80 , V_95 ) ;
}
V_1116 = & V_2 -> V_440 [ V_1121 ] ;
V_1117 = F_573 ( V_95 ) ? F_574 ( V_95 ) :
F_575 () ;
while ( V_1117 >= V_1116 -> V_442 )
V_1117 -= V_1116 -> V_442 ;
return V_1117 + V_1116 -> V_1047 ;
#else
return V_1114 ( V_80 , V_95 ) ;
#endif
}
T_17 F_576 ( struct V_214 * V_95 ,
struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_66 * V_1016 ;
int V_1122 ;
T_1 V_1037 = 0 ;
unsigned short V_1116 ;
T_2 V_94 = F_577 ( F_152 ( V_95 ) ) ;
T_12 V_272 = V_95 -> V_272 ;
T_4 V_259 = 0 ;
for ( V_1116 = 0 ; V_1116 < F_153 ( V_95 ) -> V_303 ; V_1116 ++ )
V_94 += F_577 ( F_153 ( V_95 ) -> V_285 [ V_1116 ] . V_297 ) ;
if ( F_558 ( V_65 , V_94 + 3 ) ) {
V_65 -> V_159 . V_831 ++ ;
return V_1123 ;
}
V_1016 = & V_65 -> V_84 [ V_65 -> V_86 ] ;
V_1016 -> V_95 = V_95 ;
V_1016 -> V_183 = V_95 -> V_88 ;
V_1016 -> V_184 = 1 ;
if ( F_578 ( V_95 ) ) {
V_1037 |= F_579 ( V_95 ) << V_1099 ;
V_1037 |= V_1050 ;
} else if ( V_272 == F_160 ( V_271 ) ) {
struct V_1124 * V_1125 , V_1126 ;
V_1125 = F_580 ( V_95 , V_529 , sizeof( V_1126 ) , & V_1126 ) ;
if ( ! V_1125 )
goto V_1127;
V_1037 |= F_581 ( V_1125 -> V_1128 ) <<
V_1099 ;
V_1037 |= V_1101 ;
}
V_272 = F_572 ( V_95 ) ;
if ( F_23 ( F_153 ( V_95 ) -> V_1037 & V_1129 ) &&
V_2 -> V_1130 &&
! F_582 ( V_1131 ,
& V_2 -> V_35 ) ) {
F_153 ( V_95 ) -> V_1037 |= V_1132 ;
V_1037 |= V_1066 ;
V_2 -> V_1133 = F_583 ( V_95 ) ;
V_2 -> V_1134 = V_187 ;
F_584 ( & V_2 -> V_1135 ) ;
}
F_585 ( V_95 ) ;
#ifdef F_314
if ( V_2 -> V_146 & V_435 )
V_1037 |= V_1051 ;
#endif
if ( ( V_2 -> V_146 & V_147 ) &&
( ( V_1037 & ( V_1050 | V_1101 ) ) ||
( V_95 -> V_1136 != V_1137 ) ) ) {
V_1037 &= ~ V_1138 ;
V_1037 |= ( V_95 -> V_1136 & 0x7 ) <<
V_1139 ;
if ( V_1037 & V_1101 ) {
struct V_1140 * V_1125 ;
if ( F_535 ( V_95 , 0 ) )
goto V_1127;
V_1125 = (struct V_1140 * ) V_95 -> V_98 ;
V_1125 -> V_1128 = F_160 ( V_1037 >>
V_1099 ) ;
} else {
V_1037 |= V_1050 ;
}
}
V_1016 -> V_1037 = V_1037 ;
V_1016 -> V_272 = V_272 ;
#ifdef F_180
if ( ( V_272 == F_160 ( V_1119 ) ) &&
( V_65 -> V_62 -> V_216 & ( V_1141 | V_1142 ) ) ) {
V_1122 = F_586 ( V_65 , V_1016 , & V_259 ) ;
if ( V_1122 < 0 )
goto V_1127;
goto V_1143;
}
#endif
V_1122 = F_533 ( V_65 , V_1016 , & V_259 ) ;
if ( V_1122 < 0 )
goto V_1127;
else if ( ! V_1122 )
F_548 ( V_65 , V_1016 ) ;
if ( F_14 ( V_399 , & V_65 -> V_35 ) )
F_567 ( V_65 , V_1016 ) ;
#ifdef F_180
V_1143:
#endif
F_559 ( V_65 , V_1016 , V_259 ) ;
return V_1144 ;
V_1127:
F_82 ( V_1016 -> V_95 ) ;
V_1016 -> V_95 = NULL ;
return V_1144 ;
}
static T_17 F_587 ( struct V_214 * V_95 ,
struct V_61 * V_62 ,
struct V_64 * V_127 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_64 * V_65 ;
if ( F_588 ( V_95 , 17 ) )
return V_1144 ;
V_65 = V_127 ? V_127 : V_2 -> V_65 [ V_95 -> V_1118 ] ;
return F_576 ( V_95 , V_2 , V_65 ) ;
}
static T_17 F_589 ( struct V_214 * V_95 ,
struct V_61 * V_62 )
{
return F_587 ( V_95 , V_62 , NULL ) ;
}
static int F_590 ( struct V_61 * V_62 , void * V_1145 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1146 * V_592 = V_1145 ;
if ( ! F_380 ( V_592 -> V_1147 ) )
return - V_1148 ;
memcpy ( V_62 -> V_673 , V_592 -> V_1147 , V_62 -> V_1149 ) ;
memcpy ( V_14 -> V_114 . V_592 , V_592 -> V_1147 , V_62 -> V_1149 ) ;
F_321 ( V_2 ) ;
return 0 ;
}
static int
F_591 ( struct V_61 * V_62 , int V_1150 , int V_1151 , T_2 V_592 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_4 ;
int V_1152 ;
if ( V_1150 != V_14 -> V_46 . V_1153 . V_1150 )
return - V_597 ;
V_1152 = V_14 -> V_46 . V_357 . V_1154 ( V_14 , V_592 , V_1151 , & V_4 ) ;
if ( ! V_1152 )
V_1152 = V_4 ;
return V_1152 ;
}
static int F_592 ( struct V_61 * V_62 , int V_1150 , int V_1151 ,
T_2 V_592 , T_2 V_4 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_1150 != V_14 -> V_46 . V_1153 . V_1150 )
return - V_597 ;
return V_14 -> V_46 . V_357 . V_1155 ( V_14 , V_592 , V_1151 , V_4 ) ;
}
static int F_593 ( struct V_61 * V_62 , struct V_1156 * V_1157 , int V_1158 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
switch ( V_1158 ) {
case V_1159 :
return F_594 ( V_2 , V_1157 ) ;
case V_1160 :
return F_595 ( V_2 , V_1157 ) ;
default:
return F_596 ( & V_2 -> V_14 . V_46 . V_1153 , F_597 ( V_1157 ) , V_1158 ) ;
}
}
static int F_598 ( struct V_61 * V_80 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_93 ( V_80 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_380 ( V_14 -> V_114 . V_1161 ) ) {
F_464 () ;
V_17 = F_599 ( V_80 , V_14 -> V_114 . V_1161 , V_1162 ) ;
F_466 () ;
V_14 -> V_114 . V_357 . V_718 ( V_14 , F_287 ( 0 ) ) ;
}
return V_17 ;
}
static int F_600 ( struct V_61 * V_80 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_93 ( V_80 ) ;
struct V_1163 * V_114 = & V_2 -> V_14 . V_114 ;
if ( F_380 ( V_114 -> V_1161 ) ) {
F_464 () ;
V_17 = F_601 ( V_80 , V_114 -> V_1161 , V_1162 ) ;
F_466 () ;
}
return V_17 ;
}
static void F_602 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
int V_49 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
for ( V_49 = 0 ; V_49 < V_2 -> V_208 ; V_49 ++ )
F_234 ( 0 , V_2 -> V_173 [ V_49 ] ) ;
}
static struct V_1164 * F_603 ( struct V_61 * V_62 ,
struct V_1164 * V_131 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
int V_49 ;
F_604 () ;
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ ) {
struct V_64 * V_127 = F_21 ( V_2 -> V_74 [ V_49 ] ) ;
T_6 V_186 , V_151 ;
unsigned int V_1165 ;
if ( V_127 ) {
do {
V_1165 = F_605 ( & V_127 -> V_185 ) ;
V_151 = V_127 -> V_131 . V_151 ;
V_186 = V_127 -> V_131 . V_186 ;
} while ( F_606 ( & V_127 -> V_185 , V_1165 ) );
V_131 -> V_836 += V_151 ;
V_131 -> V_835 += V_186 ;
}
}
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ ) {
struct V_64 * V_127 = F_21 ( V_2 -> V_65 [ V_49 ] ) ;
T_6 V_186 , V_151 ;
unsigned int V_1165 ;
if ( V_127 ) {
do {
V_1165 = F_605 ( & V_127 -> V_185 ) ;
V_151 = V_127 -> V_131 . V_151 ;
V_186 = V_127 -> V_131 . V_186 ;
} while ( F_606 ( & V_127 -> V_185 , V_1165 ) );
V_131 -> V_838 += V_151 ;
V_131 -> V_837 += V_186 ;
}
}
F_607 () ;
V_131 -> V_945 = V_62 -> V_131 . V_945 ;
V_131 -> V_946 = V_62 -> V_131 . V_946 ;
V_131 -> V_948 = V_62 -> V_131 . V_948 ;
V_131 -> V_949 = V_62 -> V_131 . V_949 ;
V_131 -> V_950 = V_62 -> V_131 . V_950 ;
return V_131 ;
}
static void F_608 ( struct V_1 * V_2 , T_4 V_141 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_3 , V_1166 ;
int V_49 ;
if ( V_14 -> V_114 . type == V_115 )
return;
V_3 = F_40 ( V_14 , V_1167 ) ;
V_1166 = V_3 ;
for ( V_49 = 0 ; V_49 < V_644 ; V_49 ++ ) {
T_4 V_1168 = V_3 >> ( V_49 * V_1169 ) ;
if ( V_1168 > V_141 )
V_3 &= ~ ( 0x7 << V_1169 ) ;
}
if ( V_3 != V_1166 )
F_75 ( V_14 , V_1167 , V_3 ) ;
return;
}
static void F_609 ( struct V_1 * V_2 )
{
struct V_61 * V_80 = V_2 -> V_62 ;
struct V_1170 * V_143 = & V_2 -> V_143 ;
struct V_1171 * V_1172 = V_2 -> V_629 ;
T_4 V_1173 ;
for ( V_1173 = 0 ; V_1173 < V_1174 ; V_1173 ++ ) {
T_4 V_141 = 0 ;
if ( V_2 -> V_625 & V_626 )
V_141 = F_610 ( V_143 , 0 , V_1173 ) ;
else if ( V_1172 )
V_141 = V_1172 -> V_630 [ V_1173 ] ;
F_611 ( V_80 , V_1173 , V_141 ) ;
}
}
int F_612 ( struct V_61 * V_80 , T_4 V_141 )
{
struct V_1 * V_2 = F_93 ( V_80 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
bool V_1175 ;
if ( V_141 > V_2 -> V_143 . V_727 . V_728 )
return - V_597 ;
if ( V_14 -> V_114 . type == V_115 && V_141 && V_141 < V_644 )
return - V_597 ;
V_1175 = ( F_613 ( & V_2 -> V_670 , 32 ) > 1 ) ;
if ( V_141 && V_1175 && V_2 -> V_671 > V_1176 )
return - V_801 ;
if ( F_61 ( V_80 ) )
F_454 ( V_80 ) ;
else
F_403 ( V_2 ) ;
F_471 ( V_2 ) ;
#ifdef F_385
if ( V_141 ) {
F_614 ( V_80 , V_141 ) ;
F_609 ( V_2 ) ;
V_2 -> V_146 |= V_147 ;
if ( V_2 -> V_14 . V_114 . type == V_115 ) {
V_2 -> V_1177 = V_2 -> V_14 . V_132 . V_775 ;
V_2 -> V_14 . V_132 . V_775 = V_1178 ;
}
} else {
F_615 ( V_80 ) ;
if ( V_2 -> V_14 . V_114 . type == V_115 )
V_2 -> V_14 . V_132 . V_775 = V_2 -> V_1177 ;
V_2 -> V_146 &= ~ V_147 ;
V_2 -> V_743 . V_144 = false ;
V_2 -> V_143 . V_144 = false ;
}
F_608 ( V_2 , V_141 ) ;
#endif
F_465 ( V_2 ) ;
if ( F_61 ( V_80 ) )
return F_449 ( V_80 ) ;
return 0 ;
}
static int F_616 ( struct V_1 * V_2 ,
struct V_1179 * V_1180 )
{
T_1 V_1181 = F_617 ( V_1180 -> V_1182 . V_1183 ) ;
T_1 V_1184 ;
int V_17 ;
if ( ( V_1181 != 0x800 ) && ( V_1181 >= V_768 ) )
return - V_597 ;
V_1184 = V_1180 -> V_1182 . V_1183 & 0xfffff ;
F_363 ( & V_2 -> V_654 ) ;
V_17 = F_618 ( V_2 , NULL , V_1184 ) ;
F_368 ( & V_2 -> V_654 ) ;
return V_17 ;
}
static int F_619 ( struct V_1 * V_2 ,
T_12 V_272 ,
struct V_1179 * V_1180 )
{
T_1 V_1181 = F_617 ( V_1180 -> V_1185 . V_1183 ) ;
if ( V_1181 >= V_768 )
return - V_597 ;
if ( V_1180 -> V_1185 . V_1186 > 0 )
return - V_597 ;
F_257 ( V_1181 - 1 , & V_2 -> V_1187 ) ;
return 0 ;
}
static int F_620 ( struct V_1 * V_2 ,
struct V_1179 * V_1180 )
{
T_1 V_1181 = F_617 ( V_1180 -> V_1185 . V_1183 ) ;
if ( V_1181 >= V_768 )
return - V_597 ;
F_37 ( V_1181 - 1 , & V_2 -> V_1187 ) ;
return 0 ;
}
static int F_621 ( struct V_1 * V_2 , int V_1188 ,
T_4 * V_110 , T_6 * V_658 )
{
unsigned int V_324 = V_2 -> V_324 , V_994 ;
struct V_61 * V_101 ;
struct V_674 * V_675 ;
for ( V_994 = 0 ; V_994 < V_324 ; ++ V_994 ) {
V_101 = F_457 ( V_2 -> V_525 [ V_994 ] . V_991 ) ;
if ( V_101 -> V_1188 == V_1188 ) {
if ( V_2 -> V_671 > 1 )
* V_110 = V_994 * 2 ;
else
* V_110 = V_994 * V_2 -> V_662 ;
* V_658 = V_994 + 1 ;
* V_658 <<= V_1189 ;
return 0 ;
}
}
F_382 (adapter->netdev, upper, iter) {
if ( F_383 ( V_101 ) ) {
struct V_676 * V_677 = F_93 ( V_101 ) ;
struct V_660 * V_661 = V_677 -> V_678 ;
if ( V_661 && V_661 -> V_62 -> V_1188 == V_1188 ) {
* V_110 = V_2 -> V_74 [ V_661 -> V_663 ] -> V_156 ;
* V_658 = * V_110 ;
return 0 ;
}
}
}
return - V_597 ;
}
static int F_622 ( struct V_1 * V_2 ,
struct V_1190 * V_1191 , T_6 * V_658 , T_4 * V_110 )
{
const struct V_1192 * V_71 ;
int V_17 ;
if ( F_623 ( V_1191 ) )
return - V_597 ;
F_624 (a, exts) {
if ( F_625 ( V_71 ) ) {
* V_658 = V_659 ;
* V_110 = V_659 ;
return 0 ;
}
if ( F_626 ( V_71 ) ) {
int V_1188 = F_627 ( V_71 ) ;
V_17 = F_621 ( V_2 , V_1188 , V_110 ,
V_658 ) ;
if ( V_17 == 0 )
return V_17 ;
}
}
return - V_597 ;
}
static int F_622 ( struct V_1 * V_2 ,
struct V_1190 * V_1191 , T_6 * V_658 , T_4 * V_110 )
{
return - V_597 ;
}
static int F_628 ( struct V_652 * V_1083 ,
union V_1193 * V_124 ,
struct V_1179 * V_1180 ,
struct V_1194 * V_1195 ,
struct V_1196 * V_1197 )
{
int V_49 , V_56 , V_1198 ;
T_18 V_1199 , V_1200 ;
bool V_1201 = false , V_1202 = false ;
for ( V_49 = 0 ; V_49 < V_1180 -> V_1182 . V_1203 -> V_1204 ; V_49 ++ ) {
V_1198 = V_1180 -> V_1182 . V_1203 -> V_1205 [ V_49 ] . V_1198 ;
V_1199 = V_1180 -> V_1182 . V_1203 -> V_1205 [ V_49 ] . V_1199 ;
V_1200 = V_1180 -> V_1182 . V_1203 -> V_1205 [ V_49 ] . V_124 ;
for ( V_56 = 0 ; V_1195 [ V_56 ] . V_1199 ; V_56 ++ ) {
if ( V_1195 [ V_56 ] . V_1198 == V_1198 ) {
V_1195 [ V_56 ] . V_1199 ( V_1083 , V_124 , V_1199 , V_1200 ) ;
V_1083 -> V_653 . V_1100 . V_1106 |=
V_1195 [ V_56 ] . type ;
V_1201 = true ;
break;
}
}
if ( V_1197 ) {
if ( V_1197 -> V_1198 == V_1180 -> V_1182 . V_1203 -> V_1205 [ V_49 ] . V_1198 &&
V_1197 -> V_1199 == V_1180 -> V_1182 . V_1203 -> V_1205 [ V_49 ] . V_1199 &&
V_1197 -> V_124 == V_1180 -> V_1182 . V_1203 -> V_1205 [ V_49 ] . V_124 )
V_1202 = true ;
else
continue;
}
}
if ( V_1197 && ! V_1202 )
return - V_597 ;
if ( ! V_1201 )
return 0 ;
V_124 -> V_1100 . V_1106 = V_1206 |
V_1207 ;
if ( V_1083 -> V_653 . V_1100 . V_1106 == V_1208 )
V_124 -> V_1100 . V_1106 &= V_1206 ;
return 0 ;
}
static int F_629 ( struct V_1 * V_2 ,
T_12 V_272 ,
struct V_1179 * V_1180 )
{
T_1 V_1184 = V_1180 -> V_1182 . V_1183 & 0xfffff ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1194 * V_1195 ;
struct V_652 * V_1083 = NULL ;
union V_1193 * V_124 = NULL ;
struct V_1209 * V_1210 = NULL ;
int V_49 , V_17 = - V_597 ;
T_4 V_110 ;
T_1 V_1181 , V_1211 ;
V_1181 = F_617 ( V_1180 -> V_1182 . V_1183 ) ;
V_1211 = F_617 ( V_1180 -> V_1182 . V_1212 ) ;
if ( V_272 != F_160 ( V_1057 ) )
return V_17 ;
if ( V_1184 >= ( ( 1024 << V_2 -> V_647 ) - 2 ) ) {
F_107 ( V_163 , L_135 ) ;
return V_17 ;
}
if ( V_1181 == 0x800 ) {
V_1195 = ( V_2 -> V_764 [ 0 ] ) -> V_766 ;
} else {
if ( V_1181 >= V_768 )
return V_17 ;
if ( ! V_2 -> V_764 [ V_1181 ] )
return V_17 ;
V_1195 = ( V_2 -> V_764 [ V_1181 ] ) -> V_766 ;
}
if ( ! V_1195 )
return V_17 ;
if ( V_1211 ) {
struct V_1196 * V_1197 = V_1213 ;
if ( V_1211 >= V_768 )
return V_17 ;
if ( ! F_14 ( V_1211 - 1 , & V_2 -> V_1187 ) )
return V_17 ;
for ( V_49 = 0 ; V_1197 [ V_49 ] . V_1210 ; V_49 ++ ) {
if ( V_1197 [ V_49 ] . V_1214 != V_1180 -> V_1182 . V_1203 -> V_1215 ||
V_1197 [ V_49 ] . V_1216 != V_1180 -> V_1182 . V_1203 -> V_1217 ||
V_1197 [ V_49 ] . V_1200 != V_1180 -> V_1182 . V_1203 -> V_1218 )
return V_17 ;
V_1210 = F_423 ( sizeof( * V_1210 ) , V_765 ) ;
if ( ! V_1210 )
return - V_585 ;
V_1083 = F_423 ( sizeof( * V_1083 ) , V_765 ) ;
if ( ! V_1083 ) {
V_17 = - V_585 ;
goto V_1219;
}
V_124 = F_423 ( sizeof( * V_124 ) , V_765 ) ;
if ( ! V_124 ) {
V_17 = - V_585 ;
goto V_1220;
}
V_1210 -> V_1083 = V_1083 ;
V_1210 -> V_124 = V_124 ;
V_17 = F_628 ( V_1083 , V_124 , V_1180 ,
V_1195 , & V_1197 [ V_49 ] ) ;
if ( ! V_17 ) {
V_1210 -> V_766 = V_1197 [ V_49 ] . V_1210 ;
V_2 -> V_764 [ V_1211 ] = V_1210 ;
break;
}
}
return 0 ;
}
V_1083 = F_423 ( sizeof( * V_1083 ) , V_765 ) ;
if ( ! V_1083 )
return - V_585 ;
V_124 = F_423 ( sizeof( * V_124 ) , V_765 ) ;
if ( ! V_124 ) {
V_17 = - V_585 ;
goto V_1220;
}
if ( ( V_1181 != 0x800 ) && ( V_2 -> V_764 [ V_1181 ] ) ) {
if ( ( V_2 -> V_764 [ V_1181 ] ) -> V_1083 )
memcpy ( V_1083 , ( V_2 -> V_764 [ V_1181 ] ) -> V_1083 ,
sizeof( * V_1083 ) ) ;
if ( ( V_2 -> V_764 [ V_1181 ] ) -> V_124 )
memcpy ( V_124 , ( V_2 -> V_764 [ V_1181 ] ) -> V_124 ,
sizeof( * V_124 ) ) ;
}
V_17 = F_628 ( V_1083 , V_124 , V_1180 , V_1195 , NULL ) ;
if ( V_17 )
goto V_1221;
V_17 = F_622 ( V_2 , V_1180 -> V_1182 . V_1191 , & V_1083 -> V_658 ,
& V_110 ) ;
if ( V_17 < 0 )
goto V_1221;
V_1083 -> V_657 = V_1184 ;
F_363 ( & V_2 -> V_654 ) ;
if ( F_364 ( & V_2 -> V_655 ) ) {
memcpy ( & V_2 -> V_656 , V_124 , sizeof( * V_124 ) ) ;
V_17 = F_365 ( V_14 , V_124 ) ;
if ( V_17 )
goto V_1222;
} else if ( memcmp ( & V_2 -> V_656 , V_124 , sizeof( * V_124 ) ) ) {
V_17 = - V_597 ;
goto V_1222;
}
F_630 ( & V_1083 -> V_653 , V_124 ) ;
V_17 = F_367 ( V_14 , & V_1083 -> V_653 ,
V_1083 -> V_657 , V_110 ) ;
if ( ! V_17 )
F_618 ( V_2 , V_1083 , V_1083 -> V_657 ) ;
F_368 ( & V_2 -> V_654 ) ;
F_248 ( V_124 ) ;
return V_17 ;
V_1222:
F_368 ( & V_2 -> V_654 ) ;
V_1221:
F_248 ( V_124 ) ;
V_1220:
F_248 ( V_1083 ) ;
V_1219:
F_248 ( V_1210 ) ;
return V_17 ;
}
static int F_631 ( struct V_61 * V_80 , T_1 V_1183 , T_12 V_560 ,
struct V_1223 * V_141 )
{
struct V_1 * V_2 = F_93 ( V_80 ) ;
if ( F_632 ( V_1183 ) == F_632 ( V_1224 ) &&
V_141 -> type == V_1225 ) {
switch ( V_141 -> V_1226 -> V_1227 ) {
case V_1228 :
case V_1229 :
return F_629 ( V_2 ,
V_560 , V_141 -> V_1226 ) ;
case V_1230 :
return F_616 ( V_2 , V_141 -> V_1226 ) ;
case V_1231 :
case V_1232 :
return F_619 ( V_2 , V_560 ,
V_141 -> V_1226 ) ;
case V_1233 :
return F_620 ( V_2 ,
V_141 -> V_1226 ) ;
default:
return - V_597 ;
}
}
if ( V_141 -> type != V_1234 )
return - V_597 ;
return F_612 ( V_80 , V_141 -> V_141 ) ;
}
void F_633 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
F_464 () ;
F_612 ( V_62 , F_261 ( V_62 ) ) ;
F_466 () ;
}
void F_634 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
if ( F_61 ( V_62 ) )
F_396 ( V_2 ) ;
else
F_403 ( V_2 ) ;
}
static T_13 F_635 ( struct V_61 * V_62 ,
T_13 V_216 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
if ( ! ( V_216 & V_234 ) )
V_216 &= ~ V_1235 ;
if ( ! ( V_2 -> V_161 & V_756 ) )
V_216 &= ~ V_1235 ;
return V_216 ;
}
static int F_636 ( struct V_61 * V_62 ,
T_13 V_216 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
T_13 V_1236 = V_62 -> V_216 ^ V_216 ;
bool V_1237 = false ;
if ( ! ( V_216 & V_1235 ) ) {
if ( V_2 -> V_161 & V_541 )
V_1237 = true ;
V_2 -> V_161 &= ~ V_541 ;
} else if ( ( V_2 -> V_161 & V_756 ) &&
! ( V_2 -> V_161 & V_541 ) ) {
if ( V_2 -> V_406 == 1 ||
V_2 -> V_406 > V_1238 ) {
V_2 -> V_161 |= V_541 ;
V_1237 = true ;
} else if ( ( V_1236 ^ V_216 ) & V_1235 ) {
F_109 ( V_188 , L_136
L_137 ) ;
}
}
if ( ( V_216 & V_1239 ) || ( V_216 & V_1240 ) ) {
if ( ! ( V_2 -> V_146 & V_646 ) )
V_1237 = true ;
V_2 -> V_146 &= ~ V_389 ;
V_2 -> V_146 |= V_646 ;
} else {
if ( V_2 -> V_146 & V_646 )
V_1237 = true ;
V_2 -> V_146 &= ~ V_646 ;
if ( V_2 -> V_146 & V_435 ||
( F_261 ( V_62 ) > 1 ) ||
( V_2 -> V_440 [ V_441 ] . V_755 <= 1 ) ||
( ! V_2 -> V_425 ) )
;
else
V_2 -> V_146 |= V_389 ;
}
if ( V_1236 & V_292 )
V_1237 = true ;
V_62 -> V_216 = V_216 ;
#ifdef F_425
if ( ( V_2 -> V_146 & V_773 ) ) {
if ( V_216 & V_234 )
V_2 -> V_161 |= V_1015 ;
else
F_343 ( V_2 ) ;
}
#endif
if ( V_1237 )
F_634 ( V_62 ) ;
else if ( V_1236 & ( V_267 |
V_617 ) )
F_334 ( V_62 ) ;
return 0 ;
}
static void F_637 ( struct V_61 * V_80 , T_19 V_1241 ,
T_12 V_1102 )
{
struct V_1 * V_2 = F_93 ( V_80 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! ( V_2 -> V_146 & V_773 ) )
return;
if ( V_1241 == V_1242 )
return;
if ( V_2 -> V_623 == V_1102 )
return;
if ( V_2 -> V_623 ) {
F_638 ( V_80 ,
L_138 ,
F_581 ( V_1102 ) ) ;
return;
}
V_2 -> V_623 = V_1102 ;
F_75 ( V_14 , V_622 , F_581 ( V_1102 ) ) ;
}
static void F_639 ( struct V_61 * V_80 , T_19 V_1241 ,
T_12 V_1102 )
{
struct V_1 * V_2 = F_93 ( V_80 ) ;
if ( ! ( V_2 -> V_146 & V_773 ) )
return;
if ( V_1241 == V_1242 )
return;
if ( V_2 -> V_623 != V_1102 ) {
F_638 ( V_80 , L_139 ,
F_581 ( V_1102 ) ) ;
return;
}
F_343 ( V_2 ) ;
V_2 -> V_161 |= V_1015 ;
}
static int F_640 ( struct V_1243 * V_1244 , struct V_1245 * V_1246 [] ,
struct V_61 * V_80 ,
const unsigned char * V_592 , T_2 V_269 ,
T_2 V_146 )
{
if ( F_641 ( V_592 ) || F_642 ( V_592 ) ) {
struct V_1 * V_2 = F_93 ( V_80 ) ;
T_2 V_497 = F_287 ( 0 ) ;
if ( F_328 ( V_80 ) >= F_320 ( V_2 , V_497 ) )
return - V_585 ;
}
return F_643 ( V_1244 , V_1246 , V_80 , V_592 , V_269 , V_146 ) ;
}
static int F_644 ( struct V_1 * V_2 ,
T_20 V_1247 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
unsigned int V_1145 , V_1248 ;
T_1 V_506 ;
switch ( V_1247 ) {
case V_1249 :
F_75 ( & V_2 -> V_14 , V_514 , 0 ) ;
V_506 = F_40 ( V_14 , V_1250 ) ;
V_506 |= V_511 ;
F_75 ( V_14 , V_1250 , V_506 ) ;
V_1248 = V_2 -> V_324 + V_2 -> V_671 ;
for ( V_1145 = 0 ; V_1145 < V_1248 ; V_1145 ++ ) {
if ( V_14 -> V_114 . V_357 . V_1251 )
V_14 -> V_114 . V_357 . V_1251 ( V_14 ,
true ,
V_1145 ) ;
}
break;
case V_513 :
F_75 ( & V_2 -> V_14 , V_514 ,
V_515 ) ;
V_506 = F_40 ( V_14 , V_1250 ) ;
if ( ! V_2 -> V_324 )
V_506 &= ~ V_511 ;
F_75 ( V_14 , V_1250 , V_506 ) ;
V_1248 = V_2 -> V_324 + V_2 -> V_671 ;
for ( V_1145 = 0 ; V_1145 < V_1248 ; V_1145 ++ ) {
if ( V_14 -> V_114 . V_357 . V_1251 )
V_14 -> V_114 . V_357 . V_1251 ( V_14 ,
false ,
V_1145 ) ;
}
break;
default:
return - V_597 ;
}
V_2 -> V_512 = V_1247 ;
F_109 ( V_163 , L_140 ,
V_1247 == V_1249 ? L_141 : L_142 ) ;
return 0 ;
}
static int F_645 ( struct V_61 * V_80 ,
struct V_1252 * V_1253 , T_2 V_146 )
{
struct V_1 * V_2 = F_93 ( V_80 ) ;
struct V_1245 * V_1254 , * V_1255 ;
int V_1256 ;
if ( ! ( V_2 -> V_146 & V_435 ) )
return - V_1257 ;
V_1255 = F_646 ( V_1253 , sizeof( struct V_1258 ) , V_1259 ) ;
if ( ! V_1255 )
return - V_597 ;
F_647 (attr, br_spec, rem) {
int V_181 ;
T_20 V_1247 ;
if ( F_648 ( V_1254 ) != V_1260 )
continue;
if ( F_649 ( V_1254 ) < sizeof( V_1247 ) )
return - V_597 ;
V_1247 = F_650 ( V_1254 ) ;
V_181 = F_644 ( V_2 , V_1247 ) ;
if ( V_181 )
return V_181 ;
break;
}
return 0 ;
}
static int F_651 ( struct V_214 * V_95 , T_1 V_1261 , T_1 V_1262 ,
struct V_61 * V_80 ,
T_1 V_1263 , int V_1264 )
{
struct V_1 * V_2 = F_93 ( V_80 ) ;
if ( ! ( V_2 -> V_146 & V_435 ) )
return 0 ;
return F_652 ( V_95 , V_1261 , V_1262 , V_80 ,
V_2 -> V_512 , 0 , 0 , V_1264 ,
V_1263 , NULL ) ;
}
static void * F_653 ( struct V_61 * V_9 , struct V_61 * V_664 )
{
struct V_660 * V_1115 = NULL ;
struct V_1 * V_2 = F_93 ( V_9 ) ;
int V_1265 = V_2 -> V_324 + V_2 -> V_671 ;
unsigned int V_755 ;
int V_497 , V_17 ;
if ( V_1265 >= V_1266 )
return F_654 ( - V_597 ) ;
#ifdef F_655
if ( V_664 -> V_99 != V_664 -> V_83 ) {
F_638 ( V_9 , L_143 ,
V_664 -> V_60 ) ;
return F_654 ( - V_597 ) ;
}
#endif
if ( V_664 -> V_83 > V_804 ||
V_664 -> V_83 == V_1267 ) {
F_638 ( V_9 ,
L_144 ,
V_9 -> V_60 ) ;
return F_654 ( - V_597 ) ;
}
if ( ( ( V_2 -> V_146 & V_147 ) &&
V_2 -> V_671 > V_1176 - 1 ) ||
( V_2 -> V_671 > V_1268 ) )
return F_654 ( - V_801 ) ;
V_1115 = F_423 ( sizeof( * V_1115 ) , V_765 ) ;
if ( ! V_1115 )
return F_654 ( - V_585 ) ;
V_497 = F_613 ( & V_2 -> V_670 , 32 ) ;
V_2 -> V_671 ++ ;
F_257 ( V_497 , & V_2 -> V_670 ) ;
V_755 = F_656 ( & V_2 -> V_670 , 32 ) ;
V_2 -> V_146 |= V_573 | V_435 ;
V_2 -> V_440 [ V_518 ] . V_755 = V_755 + 1 ;
V_2 -> V_440 [ V_441 ] . V_755 = V_664 -> V_83 ;
V_17 = F_612 ( V_9 , F_261 ( V_9 ) ) ;
if ( V_17 )
goto V_1269;
V_1115 -> V_497 = V_497 ;
V_1115 -> V_155 = V_2 ;
V_17 = F_376 ( V_664 , V_1115 ) ;
if ( V_17 )
goto V_1269;
F_657 ( V_664 ) ;
return V_1115 ;
V_1269:
F_638 ( V_9 ,
L_145 , V_664 -> V_60 ) ;
F_37 ( V_497 , & V_2 -> V_670 ) ;
V_2 -> V_671 -- ;
F_248 ( V_1115 ) ;
return F_654 ( V_17 ) ;
}
static void F_658 ( struct V_61 * V_9 , void * V_1270 )
{
struct V_660 * V_1115 = V_1270 ;
struct V_1 * V_2 = V_1115 -> V_155 ;
unsigned int V_755 ;
F_37 ( V_1115 -> V_497 , & V_2 -> V_670 ) ;
V_2 -> V_671 -- ;
V_755 = F_656 ( & V_2 -> V_670 , 32 ) ;
V_2 -> V_440 [ V_518 ] . V_755 = V_755 + 1 ;
F_374 ( V_1115 -> V_62 , V_1115 ) ;
F_612 ( V_9 , F_261 ( V_9 ) ) ;
F_377 ( V_9 , L_91 ,
V_1115 -> V_497 , V_2 -> V_671 ,
V_1115 -> V_663 ,
V_1115 -> V_663 + V_2 -> V_662 ,
V_2 -> V_670 ) ;
F_248 ( V_1115 ) ;
}
static T_13
F_659 ( struct V_214 * V_95 , struct V_61 * V_80 ,
T_13 V_216 )
{
unsigned int V_1271 , V_1272 ;
V_1272 = F_536 ( V_95 ) - V_95 -> V_98 ;
if ( F_23 ( V_1272 > V_1273 ) )
return V_216 & ~ ( V_1274 |
V_1275 |
V_1276 |
V_1277 |
V_1278 ) ;
V_1271 = F_537 ( V_95 ) - F_536 ( V_95 ) ;
if ( F_23 ( V_1271 > V_1279 ) )
return V_216 & ~ ( V_1274 |
V_1275 |
V_1277 |
V_1278 ) ;
if ( V_95 -> V_237 && ! ( V_216 & V_1280 ) )
V_216 &= ~ V_1277 ;
return V_216 ;
}
static inline int F_660 ( struct V_1 * V_2 )
{
struct V_5 * V_411 , * V_9 = V_2 -> V_9 ;
int V_1281 = 0 ;
if ( F_8 ( & V_2 -> V_14 ) )
V_1281 = 4 ;
F_661 (entry, &adapter->pdev->bus->devices, bus_list) {
if ( V_411 -> V_1282 )
continue;
if ( ( V_411 -> V_748 != V_9 -> V_748 ) ||
( V_411 -> V_209 != V_9 -> V_209 ) )
return - 1 ;
V_1281 ++ ;
}
return V_1281 ;
}
bool F_662 ( struct V_1 * V_2 , T_2 V_21 ,
T_2 V_1283 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1284 = V_2 -> V_1285 & V_1286 ;
if ( V_14 -> V_114 . type == V_115 )
return false ;
if ( V_14 -> V_114 . type >= V_118 ) {
if ( ( V_1284 == V_1287 ) ||
( ( V_1284 == V_1288 ) &&
( V_14 -> V_10 . V_1289 == 0 ) ) )
return true ;
}
switch ( V_21 ) {
case V_1290 :
switch ( V_1283 ) {
case V_1291 :
case V_1292 :
case V_1293 :
case V_1294 :
if ( V_14 -> V_10 . V_1289 != 0 )
break;
case V_1295 :
case V_1296 :
case V_1297 :
case V_1298 :
case V_1299 :
case V_1300 :
case V_1301 :
return true ;
}
break;
case V_1302 :
switch ( V_1283 ) {
case V_1303 :
return true ;
}
break;
case V_1304 :
if ( V_1283 != V_1305 )
return true ;
break;
case V_1306 :
return true ;
default:
break;
}
return false ;
}
static int F_663 ( struct V_5 * V_9 , const struct V_1307 * V_1308 )
{
struct V_61 * V_62 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_14 ;
const struct V_1309 * V_1310 = V_1311 [ V_1308 -> V_1312 ] ;
int V_49 , V_17 , V_1313 , V_24 ;
unsigned int V_442 = V_1314 ;
T_4 V_1315 [ V_1316 ] ;
bool V_1317 = false ;
#ifdef F_180
T_2 V_746 ;
#endif
T_1 V_1318 ;
if ( V_9 -> V_1282 ) {
F_664 ( 1 , V_1319 L_146 ,
F_518 ( V_9 ) , V_9 -> V_748 , V_9 -> V_209 ) ;
return - V_597 ;
}
V_17 = F_461 ( V_9 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_665 ( & V_9 -> V_80 , F_256 ( 64 ) ) ) {
V_1313 = 1 ;
} else {
V_17 = F_665 ( & V_9 -> V_80 , F_256 ( 32 ) ) ;
if ( V_17 ) {
F_437 ( & V_9 -> V_80 ,
L_147 ) ;
goto V_1320;
}
V_1313 = 0 ;
}
V_17 = F_666 ( V_9 , F_667 ( V_9 ,
V_1321 ) , V_1322 ) ;
if ( V_17 ) {
F_437 ( & V_9 -> V_80 ,
L_148 , V_17 ) ;
goto V_1323;
}
F_668 ( V_9 ) ;
F_462 ( V_9 ) ;
F_460 ( V_9 ) ;
if ( V_1310 -> V_114 == V_115 ) {
#ifdef F_385
V_442 = 4 * V_644 ;
#else
V_442 = V_1324 ;
#endif
}
V_62 = F_669 ( sizeof( struct V_1 ) , V_442 ) ;
if ( ! V_62 ) {
V_17 = - V_585 ;
goto V_1325;
}
F_670 ( V_62 , & V_9 -> V_80 ) ;
V_2 = F_93 ( V_62 ) ;
V_2 -> V_62 = V_62 ;
V_2 -> V_9 = V_9 ;
V_14 = & V_2 -> V_14 ;
V_14 -> V_40 = V_2 ;
V_2 -> V_1326 = F_671 ( V_1327 , V_1328 ) ;
V_14 -> V_41 = F_672 ( F_673 ( V_9 , 0 ) ,
F_674 ( V_9 , 0 ) ) ;
V_2 -> V_424 = V_14 -> V_41 ;
if ( ! V_14 -> V_41 ) {
V_17 = - V_792 ;
goto V_1329;
}
V_62 -> V_1330 = & V_1331 ;
F_675 ( V_62 ) ;
V_62 -> V_1332 = 5 * V_1011 ;
F_676 ( V_62 -> V_60 , F_518 ( V_9 ) , sizeof( V_62 -> V_60 ) ) ;
V_14 -> V_114 . V_357 = * V_1310 -> V_1333 ;
V_14 -> V_114 . type = V_1310 -> V_114 ;
V_14 -> V_1334 = V_1310 -> V_1334 ;
V_14 -> V_1335 . V_357 = * V_1310 -> V_1336 ;
V_1318 = F_40 ( V_14 , F_677 ( V_14 ) ) ;
if ( F_22 ( V_14 -> V_41 ) ) {
V_17 = - V_792 ;
goto V_1329;
}
if ( ! ( V_1318 & F_205 ( 8 ) ) )
V_14 -> V_1335 . V_357 . V_256 = & V_1337 ;
V_14 -> V_46 . V_357 = * V_1310 -> V_1338 ;
V_14 -> V_46 . V_1007 = V_1339 ;
V_14 -> V_46 . V_1153 . V_1150 = V_1340 ;
V_14 -> V_46 . V_1153 . V_1341 = 0 ;
V_14 -> V_46 . V_1153 . V_1342 = V_1343 | V_1344 ;
V_14 -> V_46 . V_1153 . V_80 = V_62 ;
V_14 -> V_46 . V_1153 . V_1345 = F_591 ;
V_14 -> V_46 . V_1153 . V_1346 = F_592 ;
V_1310 -> V_1347 ( V_14 ) ;
V_17 = F_420 ( V_2 ) ;
if ( V_17 )
goto V_1348;
if ( V_14 -> V_114 . V_357 . V_1349 )
V_14 -> V_114 . V_357 . V_1349 ( V_14 ) ;
switch ( V_2 -> V_14 . V_114 . type ) {
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
F_75 ( & V_2 -> V_14 , V_809 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_146 & V_363 ) {
T_1 V_705 = F_40 ( V_14 , V_706 ) ;
if ( V_705 & V_707 )
F_213 ( V_188 , L_72 ) ;
}
if ( V_1350 )
V_14 -> V_1350 = V_1350 ;
V_14 -> V_46 . V_1351 = true ;
V_17 = V_14 -> V_114 . V_357 . V_1352 ( V_14 ) ;
V_14 -> V_46 . V_1351 = false ;
if ( V_17 == V_713 ) {
V_17 = 0 ;
} else if ( V_17 == V_714 ) {
F_18 ( L_149 ) ;
F_18 ( L_150 ) ;
goto V_1348;
} else if ( V_17 ) {
F_18 ( L_151 , V_17 ) ;
goto V_1348;
}
#ifdef F_314
if ( V_2 -> V_14 . V_114 . type == V_115 )
goto V_1353;
F_678 ( V_14 ) ;
V_14 -> V_1354 . V_357 = V_1310 -> V_1355 ;
F_679 ( V_9 , V_781 ) ;
F_680 ( V_2 ) ;
V_1353:
#endif
V_62 -> V_216 = V_1356 |
V_1277 |
V_1278 |
V_217 |
V_234 |
V_1274 ;
#define F_681 (NETIF_F_GSO_GRE | \
NETIF_F_GSO_GRE_CSUM | \
NETIF_F_GSO_IPXIP4 | \
NETIF_F_GSO_IPXIP6 | \
NETIF_F_GSO_UDP_TUNNEL | \
NETIF_F_GSO_UDP_TUNNEL_CSUM)
V_62 -> V_1357 = F_681 ;
V_62 -> V_216 |= V_1358 |
F_681 ;
if ( V_14 -> V_114 . type >= V_117 )
V_62 -> V_216 |= V_1275 ;
V_62 -> V_1359 |= V_62 -> V_216 |
V_267 |
V_1276 |
V_292 |
V_1360 ;
if ( V_14 -> V_114 . type >= V_117 )
V_62 -> V_1359 |= V_1239 |
V_1240 ;
if ( V_1313 )
V_62 -> V_216 |= V_1361 ;
V_62 -> V_1362 |= V_62 -> V_216 | V_1280 ;
V_62 -> V_1363 |= V_62 -> V_1362 ;
V_62 -> V_1364 |= V_1274 ;
V_62 -> V_216 |= V_617 |
V_267 |
V_1276 ;
V_62 -> V_1365 |= V_1366 ;
V_62 -> V_1365 |= V_1367 ;
#ifdef F_385
if ( V_2 -> V_146 & V_741 )
V_62 -> V_1368 = & V_1368 ;
#endif
#ifdef F_180
if ( V_2 -> V_146 & V_762 ) {
unsigned int V_1369 ;
if ( V_14 -> V_114 . V_357 . V_787 ) {
V_14 -> V_114 . V_357 . V_787 ( V_14 , & V_746 ) ;
if ( V_746 & V_1370 )
V_2 -> V_146 &= ~ V_762 ;
}
V_1369 = F_332 ( int , V_1371 , F_422 () ) ;
V_2 -> V_440 [ V_1121 ] . V_755 = V_1369 ;
V_62 -> V_216 |= V_1141 |
V_1142 ;
V_62 -> V_1362 |= V_1141 |
V_1142 |
V_624 ;
}
#endif
if ( V_2 -> V_161 & V_756 )
V_62 -> V_1359 |= V_1235 ;
if ( V_2 -> V_161 & V_541 )
V_62 -> V_216 |= V_1235 ;
if ( V_14 -> V_1335 . V_357 . V_1372 ( V_14 , NULL ) < 0 ) {
F_18 ( L_152 ) ;
V_17 = - V_792 ;
goto V_1348;
}
F_682 ( & V_2 -> V_9 -> V_80 ,
V_2 -> V_14 . V_114 . V_1373 ) ;
memcpy ( V_62 -> V_673 , V_14 -> V_114 . V_1373 , V_62 -> V_1149 ) ;
if ( ! F_380 ( V_62 -> V_673 ) ) {
F_18 ( L_153 ) ;
V_17 = - V_792 ;
goto V_1348;
}
F_324 ( V_14 -> V_114 . V_592 , V_14 -> V_114 . V_1373 ) ;
F_321 ( V_2 ) ;
F_683 ( & V_2 -> V_708 , & F_526 ,
( unsigned long ) V_2 ) ;
if ( F_22 ( V_14 -> V_41 ) ) {
V_17 = - V_792 ;
goto V_1348;
}
F_684 ( & V_2 -> V_39 , F_530 ) ;
F_257 ( V_42 , & V_2 -> V_35 ) ;
F_37 ( V_37 , & V_2 -> V_35 ) ;
V_17 = F_465 ( V_2 ) ;
if ( V_17 )
goto V_1348;
V_2 -> V_720 = 0 ;
V_14 -> V_1335 . V_357 . V_256 ( V_14 , 0x2c , & V_2 -> V_1285 ) ;
V_14 -> V_1374 = F_662 ( V_2 , V_9 -> V_209 ,
V_9 -> V_754 ) ;
if ( V_14 -> V_1374 )
V_2 -> V_720 = V_1375 ;
F_685 ( & V_2 -> V_9 -> V_80 , V_2 -> V_720 ) ;
V_14 -> V_1335 . V_357 . V_256 ( V_14 , 0x2e , & V_2 -> V_1376 ) ;
V_14 -> V_1335 . V_357 . V_256 ( V_14 , 0x2d , & V_2 -> V_1377 ) ;
if ( F_8 ( V_14 ) )
F_5 ( V_2 ) ;
else
V_14 -> V_114 . V_357 . V_1378 ( V_14 ) ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_24 = F_242 ( F_660 ( V_2 ) * 10 , 16 ) ;
break;
default:
V_24 = F_660 ( V_2 ) * 10 ;
break;
}
if ( V_24 > 0 )
F_9 ( V_2 , V_24 ) ;
V_17 = F_686 ( V_14 , V_1315 , sizeof( V_1315 ) ) ;
if ( V_17 )
F_676 ( V_1315 , L_7 , sizeof( V_1315 ) ) ;
if ( F_217 ( V_14 ) && V_14 -> V_46 . V_1007 != V_1379 )
F_12 ( L_154 ,
V_14 -> V_114 . type , V_14 -> V_46 . type , V_14 -> V_46 . V_1007 ,
V_1315 ) ;
else
F_12 ( L_155 ,
V_14 -> V_114 . type , V_14 -> V_46 . type , V_1315 ) ;
F_12 ( L_156 , V_62 -> V_673 ) ;
V_17 = V_14 -> V_114 . V_357 . V_1380 ( V_14 ) ;
if ( V_17 == V_716 ) {
F_11 ( L_94
L_157
L_158
L_159
L_98
L_99 ) ;
}
strcpy ( V_62 -> V_60 , L_160 ) ;
V_17 = F_687 ( V_62 ) ;
if ( V_17 )
goto V_1381;
F_688 ( V_9 , V_2 ) ;
if ( V_14 -> V_114 . V_357 . V_725 )
V_14 -> V_114 . V_357 . V_725 ( V_14 ) ;
F_412 ( V_62 ) ;
#ifdef F_237
if ( F_130 ( & V_9 -> V_80 ) == 0 ) {
V_2 -> V_146 |= V_194 ;
F_127 ( V_2 ) ;
}
#endif
if ( V_2 -> V_146 & V_435 ) {
F_109 ( V_188 , L_161 , V_2 -> V_324 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_324 ; V_49 ++ )
F_689 ( V_9 , ( V_49 | 0x10000000 ) ) ;
}
if ( V_14 -> V_114 . V_357 . V_1382 )
V_14 -> V_114 . V_357 . V_1382 ( V_14 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_598 ( V_62 ) ;
F_12 ( L_71 , V_1383 ) ;
#ifdef F_690
if ( F_691 ( V_2 ) )
F_107 ( V_188 , L_162 ) ;
#endif
F_692 ( V_2 ) ;
if ( F_693 ( V_14 ) && F_217 ( V_14 ) && V_14 -> V_114 . V_357 . V_686 )
V_14 -> V_114 . V_357 . V_686 ( V_14 ,
V_957 | V_984 ,
true ) ;
return 0 ;
V_1381:
F_74 ( V_2 ) ;
F_471 ( V_2 ) ;
V_1348:
F_694 ( V_2 ) ;
V_2 -> V_161 &= ~ V_681 ;
F_695 ( V_2 -> V_424 ) ;
F_248 ( V_2 -> V_764 [ 0 ] ) ;
F_248 ( V_2 -> V_587 ) ;
V_1329:
V_1317 = ! F_15 ( V_808 , & V_2 -> V_35 ) ;
F_696 ( V_62 ) ;
V_1325:
F_697 ( V_9 ,
F_667 ( V_9 , V_1321 ) ) ;
V_1323:
V_1320:
if ( ! V_2 || V_1317 )
F_472 ( V_9 ) ;
return V_17 ;
}
static void F_698 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_457 ( V_9 ) ;
struct V_61 * V_62 ;
bool V_1317 ;
int V_49 ;
if ( ! V_2 )
return;
V_62 = V_2 -> V_62 ;
F_699 ( V_2 ) ;
F_257 ( V_36 , & V_2 -> V_35 ) ;
F_700 ( & V_2 -> V_39 ) ;
#ifdef F_237
if ( V_2 -> V_146 & V_194 ) {
V_2 -> V_146 &= ~ V_194 ;
F_131 ( & V_9 -> V_80 ) ;
F_75 ( & V_2 -> V_14 , V_205 ,
V_207 ) ;
}
#endif
#ifdef F_690
F_701 ( V_2 ) ;
#endif
F_600 ( V_62 ) ;
#ifdef F_314
F_694 ( V_2 ) ;
#endif
if ( V_62 -> V_1008 == V_1009 )
F_524 ( V_62 ) ;
F_471 ( V_2 ) ;
F_74 ( V_2 ) ;
#ifdef F_702
F_248 ( V_2 -> V_145 ) ;
F_248 ( V_2 -> V_629 ) ;
#endif
F_695 ( V_2 -> V_424 ) ;
F_697 ( V_9 , F_667 ( V_9 ,
V_1321 ) ) ;
F_12 ( L_163 ) ;
for ( V_49 = 0 ; V_49 < V_768 ; V_49 ++ ) {
if ( V_2 -> V_764 [ V_49 ] ) {
F_248 ( V_2 -> V_764 [ V_49 ] -> V_1083 ) ;
F_248 ( V_2 -> V_764 [ V_49 ] -> V_124 ) ;
}
F_248 ( V_2 -> V_764 [ V_49 ] ) ;
}
F_248 ( V_2 -> V_587 ) ;
V_1317 = ! F_15 ( V_808 , & V_2 -> V_35 ) ;
F_696 ( V_62 ) ;
F_703 ( V_9 ) ;
if ( V_1317 )
F_472 ( V_9 ) ;
}
static T_21 F_704 ( struct V_5 * V_9 ,
T_22 V_35 )
{
struct V_1 * V_2 = F_457 ( V_9 ) ;
struct V_61 * V_62 = V_2 -> V_62 ;
#ifdef F_314
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_1384 , * V_991 ;
T_1 V_1385 , V_1386 , V_1387 , V_1388 ;
int V_994 , V_1389 ;
T_2 V_1390 , V_1391 ;
if ( V_2 -> V_14 . V_114 . type == V_115 ||
V_2 -> V_324 == 0 )
goto V_1392;
V_1384 = V_9 -> V_10 -> V_12 ;
while ( V_1384 && ( F_705 ( V_1384 ) != V_1393 ) )
V_1384 = V_1384 -> V_10 -> V_12 ;
if ( ! V_1384 )
goto V_1392;
V_1389 = F_706 ( V_1384 , V_1394 ) ;
if ( ! V_1389 )
goto V_1392;
V_1385 = F_30 ( V_14 , V_1389 + V_1395 ) ;
V_1386 = F_30 ( V_14 , V_1389 + V_1395 + 4 ) ;
V_1387 = F_30 ( V_14 , V_1389 + V_1395 + 8 ) ;
V_1388 = F_30 ( V_14 , V_1389 + V_1395 + 12 ) ;
if ( F_22 ( V_14 -> V_41 ) )
goto V_1392;
V_1390 = V_1386 >> 16 ;
if ( ! ( V_1390 & 0x0080 ) )
goto V_1392;
V_1391 = V_1390 & 0x01 ;
if ( ( V_1391 & 1 ) == ( V_9 -> V_1396 & 1 ) ) {
unsigned int V_21 ;
V_994 = ( V_1390 & 0x7F ) >> 1 ;
F_18 ( L_164 , V_994 ) ;
F_18 ( L_165
L_166 ,
V_1385 , V_1386 , V_1387 , V_1388 ) ;
switch ( V_2 -> V_14 . V_114 . type ) {
case V_117 :
V_21 = V_1397 ;
break;
case V_118 :
V_21 = V_1398 ;
break;
case V_119 :
V_21 = V_1399 ;
break;
case V_120 :
V_21 = V_1400 ;
break;
case V_121 :
V_21 = V_1401 ;
break;
default:
V_21 = 0 ;
break;
}
V_991 = F_707 ( V_1402 , V_21 , NULL ) ;
while ( V_991 ) {
if ( V_991 -> V_1396 == ( V_1390 & 0xFF ) )
break;
V_991 = F_707 ( V_1402 ,
V_21 , V_991 ) ;
}
if ( V_991 ) {
F_516 ( V_2 , V_991 ) ;
F_708 ( V_991 ) ;
}
F_709 ( V_9 ) ;
}
V_2 -> V_1403 ++ ;
return V_1404 ;
V_1392:
#endif
if ( ! F_14 ( V_42 , & V_2 -> V_35 ) )
return V_1405 ;
F_464 () ;
F_470 ( V_62 ) ;
if ( V_35 == V_1406 ) {
F_466 () ;
return V_1405 ;
}
if ( F_61 ( V_62 ) )
F_400 ( V_2 ) ;
if ( ! F_15 ( V_808 , & V_2 -> V_35 ) )
F_472 ( V_9 ) ;
F_466 () ;
return V_1407 ;
}
static T_21 F_710 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_457 ( V_9 ) ;
T_21 V_1408 ;
int V_17 ;
if ( F_461 ( V_9 ) ) {
F_107 ( V_188 , L_167 ) ;
V_1408 = V_1405 ;
} else {
F_36 () ;
F_37 ( V_808 , & V_2 -> V_35 ) ;
V_2 -> V_14 . V_41 = V_2 -> V_424 ;
F_462 ( V_9 ) ;
F_459 ( V_9 ) ;
F_460 ( V_9 ) ;
F_463 ( V_9 , false ) ;
F_403 ( V_2 ) ;
F_75 ( & V_2 -> V_14 , V_809 , ~ 0 ) ;
V_1408 = V_1404 ;
}
V_17 = F_709 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_168
L_169 , V_17 ) ;
}
return V_1408 ;
}
static void F_711 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_457 ( V_9 ) ;
struct V_61 * V_62 = V_2 -> V_62 ;
#ifdef F_314
if ( V_2 -> V_1403 ) {
F_109 ( V_163 , L_170 ) ;
V_2 -> V_1403 -- ;
return;
}
#endif
if ( F_61 ( V_62 ) )
F_402 ( V_2 ) ;
F_467 ( V_62 ) ;
}
static int T_23 F_712 ( void )
{
int V_601 ;
F_54 ( L_171 , V_1409 , V_1410 ) ;
F_54 ( L_71 , V_1411 ) ;
V_38 = F_713 ( V_1322 ) ;
if ( ! V_38 ) {
F_55 ( L_172 , V_1322 ) ;
return - V_585 ;
}
F_714 () ;
V_601 = F_715 ( & V_1412 ) ;
if ( V_601 ) {
F_716 () ;
return V_601 ;
}
#ifdef F_237
F_717 ( & V_1413 ) ;
#endif
return 0 ;
}
static void T_24 F_718 ( void )
{
#ifdef F_237
F_719 ( & V_1413 ) ;
#endif
F_720 ( & V_1412 ) ;
F_716 () ;
if ( V_38 ) {
F_721 ( V_38 ) ;
V_38 = NULL ;
}
}
static int F_722 ( struct V_1414 * V_1415 , unsigned long V_210 ,
void * V_1145 )
{
int V_1416 ;
V_1416 = F_723 ( & V_1412 . V_1417 , NULL , & V_210 ,
F_128 ) ;
return V_1416 ? V_1418 : V_1419 ;
}
