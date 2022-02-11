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
F_97 ( V_161 , & V_2 -> V_35 ) ;
F_27 ( V_162 , L_61 ) ;
F_13 ( V_2 ) ;
}
}
static int F_98 ( struct V_61 * V_62 ,
int V_92 , T_1 V_163 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_164 = F_99 ( V_2 ) ;
if ( ! V_163 )
return 0 ;
V_164 <<= V_165 ;
V_164 /= V_163 ;
V_164 &= V_166 |
V_167 ;
V_164 |= V_168 ;
F_75 ( V_14 , V_169 , V_92 ) ;
F_75 ( V_14 , V_170 , V_164 ) ;
return 0 ;
}
static bool F_100 ( struct V_171 * V_172 ,
struct V_64 * V_65 , int V_173 )
{
struct V_1 * V_2 = V_172 -> V_2 ;
struct V_66 * V_67 ;
union V_68 * V_69 ;
unsigned int V_174 = 0 , V_175 = 0 ;
unsigned int V_176 = V_172 -> V_177 . V_178 ;
unsigned int V_49 = V_65 -> V_85 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return true ;
V_67 = & V_65 -> V_84 [ V_49 ] ;
V_69 = F_65 ( V_65 , V_49 ) ;
V_49 -= V_65 -> V_94 ;
do {
union V_68 * V_179 = V_67 -> V_89 ;
if ( ! V_179 )
break;
F_101 () ;
if ( ! ( V_179 -> V_100 . V_180 & F_102 ( V_181 ) ) )
break;
V_67 -> V_89 = NULL ;
V_174 += V_67 -> V_182 ;
V_175 += V_67 -> V_183 ;
F_103 ( V_67 -> V_95 , V_173 ) ;
F_83 ( V_65 -> V_80 ,
F_62 ( V_67 , V_87 ) ,
F_63 ( V_67 , V_88 ) ,
V_128 ) ;
V_67 -> V_95 = NULL ;
F_85 ( V_67 , V_88 , 0 ) ;
while ( V_69 != V_179 ) {
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
F_104 ( V_69 ) ;
V_176 -- ;
} while ( F_25 ( V_176 ) );
V_49 += V_65 -> V_94 ;
V_65 -> V_85 = V_49 ;
F_105 ( & V_65 -> V_184 ) ;
V_65 -> V_131 . V_185 += V_174 ;
V_65 -> V_131 . V_151 += V_175 ;
F_106 ( & V_65 -> V_184 ) ;
V_172 -> V_177 . V_174 += V_174 ;
V_172 -> V_177 . V_175 += V_175 ;
if ( F_107 ( V_65 ) && F_94 ( V_65 ) ) {
struct V_15 * V_14 = & V_2 -> V_14 ;
F_108 ( V_162 , L_62
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
V_65 -> V_84 [ V_49 ] . V_90 , V_186 ) ;
F_109 ( V_65 -> V_62 , V_65 -> V_92 ) ;
F_110 ( V_187 ,
L_70 ,
V_2 -> V_188 + 1 , V_65 -> V_92 ) ;
F_96 ( V_2 ) ;
return true ;
}
F_111 ( F_112 ( V_65 ) ,
V_175 , V_174 ) ;
#define F_113 (DESC_NEEDED * 2)
if ( F_23 ( V_175 && F_114 ( V_65 -> V_62 ) &&
( F_115 ( V_65 ) >= F_113 ) ) ) {
F_116 () ;
if ( F_117 ( V_65 -> V_62 ,
V_65 -> V_92 )
&& ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_118 ( V_65 -> V_62 ,
V_65 -> V_92 ) ;
++ V_65 -> V_159 . V_189 ;
}
}
return ! ! V_176 ;
}
static void F_119 ( struct V_1 * V_2 ,
struct V_64 * V_65 ,
int V_190 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_191 = 0 ;
T_2 V_192 ;
if ( V_2 -> V_146 & V_193 )
V_191 = F_120 ( V_65 -> V_80 , V_190 ) ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_192 = F_121 ( V_65 -> V_156 ) ;
break;
case V_117 :
case V_118 :
V_192 = F_122 ( V_65 -> V_156 ) ;
V_191 <<= V_194 ;
break;
default:
return;
}
V_191 |= V_195 |
V_196 |
V_197 ;
F_75 ( V_14 , V_192 , V_191 ) ;
}
static void F_123 ( struct V_1 * V_2 ,
struct V_64 * V_74 ,
int V_190 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_198 = 0 ;
T_4 V_156 = V_74 -> V_156 ;
if ( V_2 -> V_146 & V_193 )
V_198 = F_120 ( V_74 -> V_80 , V_190 ) ;
switch ( V_14 -> V_114 . type ) {
case V_117 :
case V_118 :
V_198 <<= V_199 ;
break;
default:
break;
}
V_198 |= V_200 |
V_201 |
V_202 ;
F_75 ( V_14 , F_41 ( V_156 ) , V_198 ) ;
}
static void F_124 ( struct V_171 * V_172 )
{
struct V_1 * V_2 = V_172 -> V_2 ;
struct V_64 * V_127 ;
int V_190 = F_125 () ;
if ( V_172 -> V_190 == V_190 )
goto V_203;
F_126 (ring, q_vector->tx)
F_119 ( V_2 , V_127 , V_190 ) ;
F_126 (ring, q_vector->rx)
F_123 ( V_2 , V_127 , V_190 ) ;
V_172 -> V_190 = V_190 ;
V_203:
F_127 () ;
}
static void F_128 ( struct V_1 * V_2 )
{
int V_49 ;
if ( V_2 -> V_146 & V_193 )
F_75 ( & V_2 -> V_14 , V_204 ,
V_205 ) ;
else
F_75 ( & V_2 -> V_14 , V_204 ,
V_206 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_207 ; V_49 ++ ) {
V_2 -> V_172 [ V_49 ] -> V_190 = - 1 ;
F_124 ( V_2 -> V_172 [ V_49 ] ) ;
}
}
static int F_129 ( struct V_208 * V_80 , void * V_98 )
{
struct V_1 * V_2 = F_130 ( V_80 ) ;
unsigned long V_209 = * ( unsigned long * ) V_98 ;
if ( ! ( V_2 -> V_146 & V_210 ) )
return 0 ;
switch ( V_209 ) {
case V_211 :
if ( V_2 -> V_146 & V_193 )
break;
if ( F_131 ( V_80 ) == 0 ) {
V_2 -> V_146 |= V_193 ;
F_75 ( & V_2 -> V_14 , V_204 ,
V_205 ) ;
break;
}
case V_212 :
if ( V_2 -> V_146 & V_193 ) {
F_132 ( V_80 ) ;
V_2 -> V_146 &= ~ V_193 ;
F_75 ( & V_2 -> V_14 , V_204 ,
V_206 ) ;
}
break;
}
return 0 ;
}
static inline void F_133 ( struct V_64 * V_127 ,
union V_75 * V_76 ,
struct V_213 * V_95 )
{
T_2 V_214 ;
if ( ! ( V_127 -> V_62 -> V_215 & V_216 ) )
return;
V_214 = F_134 ( V_76 -> V_100 . V_217 . V_218 . V_219 . V_220 ) &
V_221 ;
if ( ! V_214 )
return;
F_135 ( V_95 , F_71 ( V_76 -> V_100 . V_217 . V_222 . V_223 ) ,
( V_224 & ( 1ul << V_214 ) ) ?
V_225 : V_226 ) ;
}
static inline bool F_136 ( struct V_64 * V_127 ,
union V_75 * V_76 )
{
T_8 V_220 = V_76 -> V_100 . V_217 . V_218 . V_219 . V_220 ;
return F_14 ( V_227 , & V_127 -> V_35 ) &&
( ( V_220 & F_137 ( V_228 ) ) ==
( F_137 ( V_229 <<
V_230 ) ) ) ;
}
static inline void F_138 ( struct V_64 * V_127 ,
union V_75 * V_76 ,
struct V_213 * V_95 )
{
T_8 V_220 = V_76 -> V_100 . V_217 . V_218 . V_219 . V_220 ;
bool V_231 = false ;
F_139 ( V_95 ) ;
if ( ! ( V_127 -> V_62 -> V_215 & V_232 ) )
return;
if ( V_220 & F_137 ( V_233 ) ) {
V_231 = true ;
V_95 -> V_234 = 1 ;
}
if ( F_140 ( V_76 , V_235 ) &&
F_140 ( V_76 , V_236 ) ) {
V_127 -> V_237 . V_238 ++ ;
return;
}
if ( ! F_140 ( V_76 , V_239 ) )
return;
if ( F_140 ( V_76 , V_240 ) ) {
if ( ( V_220 & F_137 ( V_241 ) ) &&
F_14 ( V_242 , & V_127 -> V_35 ) )
return;
V_127 -> V_237 . V_238 ++ ;
return;
}
V_95 -> V_243 = V_244 ;
if ( V_231 ) {
if ( ! F_140 ( V_76 , V_245 ) )
return;
if ( F_140 ( V_76 , V_246 ) ) {
V_95 -> V_243 = V_247 ;
return;
}
V_95 -> V_248 = 1 ;
}
}
static bool F_141 ( struct V_64 * V_74 ,
struct V_77 * V_249 )
{
struct V_104 * V_104 = V_249 -> V_104 ;
T_9 V_87 ;
if ( F_25 ( V_104 ) )
return true ;
V_104 = F_142 ( F_143 ( V_74 ) ) ;
if ( F_23 ( ! V_104 ) ) {
V_74 -> V_237 . V_250 ++ ;
return false ;
}
V_87 = F_144 ( V_74 -> V_80 , V_104 , 0 ,
F_145 ( V_74 ) , V_251 ) ;
if ( F_146 ( V_74 -> V_80 , V_87 ) ) {
F_147 ( V_104 , F_143 ( V_74 ) ) ;
V_74 -> V_237 . V_250 ++ ;
return false ;
}
V_249 -> V_87 = V_87 ;
V_249 -> V_104 = V_104 ;
V_249 -> V_105 = 0 ;
return true ;
}
void F_148 ( struct V_64 * V_74 , T_2 V_252 )
{
union V_75 * V_76 ;
struct V_77 * V_249 ;
T_2 V_49 = V_74 -> V_86 ;
if ( ! V_252 )
return;
V_76 = F_70 ( V_74 , V_49 ) ;
V_249 = & V_74 -> V_78 [ V_49 ] ;
V_49 -= V_74 -> V_94 ;
do {
if ( ! F_141 ( V_74 , V_249 ) )
break;
V_76 -> V_253 . V_254 = F_149 ( V_249 -> V_87 + V_249 -> V_105 ) ;
V_76 ++ ;
V_249 ++ ;
V_49 ++ ;
if ( F_23 ( ! V_49 ) ) {
V_76 = F_70 ( V_74 , 0 ) ;
V_249 = V_74 -> V_78 ;
V_49 -= V_74 -> V_94 ;
}
V_76 -> V_100 . V_101 . V_102 = 0 ;
V_252 -- ;
} while ( V_252 );
V_49 += V_74 -> V_94 ;
if ( V_74 -> V_86 != V_49 ) {
V_74 -> V_86 = V_49 ;
V_74 -> V_255 = V_49 ;
F_150 () ;
F_151 ( V_49 , V_74 -> V_153 ) ;
}
}
static void F_152 ( struct V_64 * V_127 ,
struct V_213 * V_95 )
{
T_2 V_256 = F_153 ( V_95 ) ;
F_154 ( V_95 ) -> V_257 = F_155 ( ( V_95 -> V_88 - V_256 ) ,
F_156 ( V_95 ) -> V_258 ) ;
F_154 ( V_95 ) -> V_259 = V_260 ;
}
static void F_157 ( struct V_64 * V_74 ,
struct V_213 * V_95 )
{
if ( ! F_156 ( V_95 ) -> V_258 )
return;
V_74 -> V_237 . V_261 += F_156 ( V_95 ) -> V_258 ;
V_74 -> V_237 . V_262 ++ ;
F_152 ( V_74 , V_95 ) ;
F_156 ( V_95 ) -> V_258 = 0 ;
}
static void F_158 ( struct V_64 * V_74 ,
union V_75 * V_76 ,
struct V_213 * V_95 )
{
struct V_61 * V_80 = V_74 -> V_62 ;
T_1 V_146 = V_74 -> V_172 -> V_2 -> V_146 ;
F_157 ( V_74 , V_95 ) ;
F_133 ( V_74 , V_76 , V_95 ) ;
F_138 ( V_74 , V_76 , V_95 ) ;
if ( F_23 ( V_146 & V_263 ) )
F_159 ( V_74 , V_76 , V_95 ) ;
if ( ( V_80 -> V_215 & V_264 ) &&
F_140 ( V_76 , V_265 ) ) {
T_2 V_266 = F_134 ( V_76 -> V_100 . V_101 . V_267 ) ;
F_160 ( V_95 , F_161 ( V_268 ) , V_266 ) ;
}
F_162 ( V_95 , V_74 -> V_92 ) ;
V_95 -> V_269 = F_163 ( V_95 , V_80 ) ;
}
static void F_164 ( struct V_171 * V_172 ,
struct V_213 * V_95 )
{
F_165 ( V_95 , & V_172 -> V_270 ) ;
if ( F_166 ( V_172 ) )
F_167 ( V_95 ) ;
else
F_168 ( & V_172 -> V_270 , V_95 ) ;
}
static bool F_169 ( struct V_64 * V_74 ,
union V_75 * V_76 ,
struct V_213 * V_95 )
{
T_1 V_271 = V_74 -> V_85 + 1 ;
V_271 = ( V_271 < V_74 -> V_94 ) ? V_271 : 0 ;
V_74 -> V_85 = V_271 ;
F_104 ( F_70 ( V_74 , V_271 ) ) ;
if ( F_170 ( V_74 ) ) {
T_10 V_272 = V_76 -> V_100 . V_217 . V_218 . V_98 &
F_102 ( V_273 ) ;
if ( F_23 ( V_272 ) ) {
T_1 V_274 = F_71 ( V_272 ) ;
V_274 >>= V_275 ;
F_156 ( V_95 ) -> V_258 += V_274 - 1 ;
V_271 = F_71 ( V_76 -> V_100 . V_101 . V_102 ) ;
V_271 &= V_276 ;
V_271 >>= V_277 ;
}
}
if ( F_25 ( F_140 ( V_76 , V_278 ) ) )
return false ;
V_74 -> V_78 [ V_271 ] . V_95 = V_95 ;
V_74 -> V_237 . V_279 ++ ;
return true ;
}
static void F_171 ( struct V_64 * V_74 ,
struct V_213 * V_95 )
{
struct V_280 * V_281 = & F_154 ( V_95 ) -> V_282 [ 0 ] ;
unsigned char * V_283 ;
unsigned int V_284 ;
V_283 = F_172 ( V_281 ) ;
V_284 = F_173 ( V_283 , V_285 ) ;
F_174 ( V_95 , V_283 , F_175 ( V_284 , sizeof( long ) ) ) ;
F_176 ( V_281 , V_284 ) ;
V_281 -> V_105 += V_284 ;
V_95 -> V_286 -= V_284 ;
V_95 -> V_153 += V_284 ;
}
static void F_177 ( struct V_64 * V_74 ,
struct V_213 * V_95 )
{
if ( F_23 ( F_156 ( V_95 ) -> V_287 ) ) {
F_84 ( V_74 -> V_80 , F_156 ( V_95 ) -> V_87 ,
F_145 ( V_74 ) , V_251 ) ;
F_156 ( V_95 ) -> V_287 = false ;
} else {
struct V_280 * V_281 = & F_154 ( V_95 ) -> V_282 [ 0 ] ;
F_178 ( V_74 -> V_80 ,
F_156 ( V_95 ) -> V_87 ,
V_281 -> V_105 ,
F_73 ( V_74 ) ,
V_251 ) ;
}
F_156 ( V_95 ) -> V_87 = 0 ;
}
static bool F_179 ( struct V_64 * V_74 ,
union V_75 * V_76 ,
struct V_213 * V_95 )
{
struct V_61 * V_62 = V_74 -> V_62 ;
if ( F_23 ( F_140 ( V_76 ,
V_288 ) &&
! ( V_62 -> V_215 & V_289 ) ) ) {
F_82 ( V_95 ) ;
return true ;
}
if ( F_180 ( V_95 ) )
F_171 ( V_74 , V_95 ) ;
#ifdef F_181
if ( F_136 ( V_74 , V_76 ) )
return false ;
#endif
if ( F_182 ( V_95 ) )
return true ;
return false ;
}
static void F_183 ( struct V_64 * V_74 ,
struct V_77 * V_290 )
{
struct V_77 * V_291 ;
T_2 V_292 = V_74 -> V_255 ;
V_291 = & V_74 -> V_78 [ V_292 ] ;
V_292 ++ ;
V_74 -> V_255 = ( V_292 < V_74 -> V_94 ) ? V_292 : 0 ;
* V_291 = * V_290 ;
F_184 ( V_74 -> V_80 , V_291 -> V_87 ,
V_291 -> V_105 ,
F_73 ( V_74 ) ,
V_251 ) ;
}
static inline bool F_185 ( struct V_104 * V_104 )
{
return ( F_186 ( V_104 ) != F_187 () ) || F_188 ( V_104 ) ;
}
static bool F_189 ( struct V_64 * V_74 ,
struct V_77 * V_293 ,
union V_75 * V_76 ,
struct V_213 * V_95 )
{
struct V_104 * V_104 = V_293 -> V_104 ;
unsigned int V_294 = F_134 ( V_76 -> V_100 . V_101 . V_295 ) ;
#if ( V_296 < 8192 )
unsigned int V_297 = F_73 ( V_74 ) ;
#else
unsigned int V_297 = F_175 ( V_294 , V_298 ) ;
unsigned int V_299 = F_145 ( V_74 ) -
F_73 ( V_74 ) ;
#endif
if ( ( V_294 <= V_285 ) && ! F_180 ( V_95 ) ) {
unsigned char * V_283 = F_72 ( V_104 ) + V_293 -> V_105 ;
memcpy ( F_190 ( V_95 , V_294 ) , V_283 , F_175 ( V_294 , sizeof( long ) ) ) ;
if ( F_25 ( ! F_185 ( V_104 ) ) )
return true ;
F_147 ( V_104 , F_143 ( V_74 ) ) ;
return false ;
}
F_191 ( V_95 , F_154 ( V_95 ) -> V_300 , V_104 ,
V_293 -> V_105 , V_294 , V_297 ) ;
if ( F_23 ( F_185 ( V_104 ) ) )
return false ;
#if ( V_296 < 8192 )
if ( F_23 ( F_192 ( V_104 ) != 1 ) )
return false ;
V_293 -> V_105 ^= V_297 ;
#else
V_293 -> V_105 += V_297 ;
if ( V_293 -> V_105 > V_299 )
return false ;
#endif
F_193 ( V_104 ) ;
return true ;
}
static struct V_213 * F_194 ( struct V_64 * V_74 ,
union V_75 * V_76 )
{
struct V_77 * V_293 ;
struct V_213 * V_95 ;
struct V_104 * V_104 ;
V_293 = & V_74 -> V_78 [ V_74 -> V_85 ] ;
V_104 = V_293 -> V_104 ;
F_195 ( V_104 ) ;
V_95 = V_293 -> V_95 ;
if ( F_25 ( ! V_95 ) ) {
void * V_301 = F_72 ( V_104 ) +
V_293 -> V_105 ;
F_104 ( V_301 ) ;
#if V_298 < 128
F_104 ( V_301 + V_298 ) ;
#endif
V_95 = F_196 ( & V_74 -> V_172 -> V_270 ,
V_285 ) ;
if ( F_23 ( ! V_95 ) ) {
V_74 -> V_237 . V_302 ++ ;
return NULL ;
}
F_195 ( V_95 -> V_98 ) ;
if ( F_25 ( F_140 ( V_76 , V_278 ) ) )
goto V_303;
F_156 ( V_95 ) -> V_87 = V_293 -> V_87 ;
} else {
if ( F_140 ( V_76 , V_278 ) )
F_177 ( V_74 , V_95 ) ;
V_303:
F_178 ( V_74 -> V_80 ,
V_293 -> V_87 ,
V_293 -> V_105 ,
F_73 ( V_74 ) ,
V_251 ) ;
V_293 -> V_95 = NULL ;
}
if ( F_189 ( V_74 , V_293 , V_76 , V_95 ) ) {
F_183 ( V_74 , V_293 ) ;
} else if ( F_156 ( V_95 ) -> V_87 == V_293 -> V_87 ) {
F_156 ( V_95 ) -> V_287 = true ;
} else {
F_84 ( V_74 -> V_80 , V_293 -> V_87 ,
F_145 ( V_74 ) ,
V_251 ) ;
}
V_293 -> V_104 = NULL ;
return V_95 ;
}
static int F_197 ( struct V_171 * V_172 ,
struct V_64 * V_74 ,
const int V_176 )
{
unsigned int V_304 = 0 , V_305 = 0 ;
#ifdef F_181
struct V_1 * V_2 = V_172 -> V_2 ;
int V_306 ;
unsigned int V_307 = 0 ;
#endif
T_2 V_252 = F_115 ( V_74 ) ;
while ( F_25 ( V_305 < V_176 ) ) {
union V_75 * V_76 ;
struct V_213 * V_95 ;
if ( V_252 >= V_308 ) {
F_148 ( V_74 , V_252 ) ;
V_252 = 0 ;
}
V_76 = F_70 ( V_74 , V_74 -> V_85 ) ;
if ( ! V_76 -> V_100 . V_101 . V_102 )
break;
F_198 () ;
V_95 = F_194 ( V_74 , V_76 ) ;
if ( ! V_95 )
break;
V_252 ++ ;
if ( F_169 ( V_74 , V_76 , V_95 ) )
continue;
if ( F_179 ( V_74 , V_76 , V_95 ) )
continue;
V_304 += V_95 -> V_88 ;
F_158 ( V_74 , V_76 , V_95 ) ;
#ifdef F_181
if ( F_136 ( V_74 , V_76 ) ) {
V_306 = F_199 ( V_2 , V_76 , V_95 ) ;
if ( V_306 > 0 ) {
if ( ! V_307 ) {
V_307 = V_74 -> V_62 -> V_309 -
sizeof( struct V_310 ) -
sizeof( struct V_311 ) -
sizeof( struct V_312 ) ;
if ( V_307 > 512 )
V_307 &= ~ 511 ;
}
V_304 += V_306 ;
V_305 += F_155 ( V_306 ,
V_307 ) ;
}
if ( ! V_306 ) {
F_82 ( V_95 ) ;
continue;
}
}
#endif
F_164 ( V_172 , V_95 ) ;
V_305 ++ ;
}
F_105 ( & V_74 -> V_184 ) ;
V_74 -> V_131 . V_151 += V_305 ;
V_74 -> V_131 . V_185 += V_304 ;
F_106 ( & V_74 -> V_184 ) ;
V_172 -> V_313 . V_175 += V_305 ;
V_172 -> V_313 . V_174 += V_304 ;
return V_305 ;
}
static int F_200 ( struct V_314 * V_270 )
{
struct V_171 * V_172 =
F_201 ( V_270 , struct V_171 , V_270 ) ;
struct V_1 * V_2 = V_172 -> V_2 ;
struct V_64 * V_127 ;
int V_315 = 0 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return V_316 ;
if ( ! F_202 ( V_172 ) )
return V_317 ;
F_126 (ring, q_vector->rx) {
V_315 = F_197 ( V_172 , V_127 , 4 ) ;
#ifdef F_203
if ( V_315 )
V_127 -> V_131 . V_318 += V_315 ;
else
V_127 -> V_131 . V_319 ++ ;
#endif
if ( V_315 )
break;
}
F_204 ( V_172 ) ;
return V_315 ;
}
static void F_205 ( struct V_1 * V_2 )
{
struct V_171 * V_172 ;
int V_320 ;
T_1 V_124 ;
if ( V_2 -> V_321 > 32 ) {
T_1 V_322 = F_206 ( V_2 -> V_321 - 32 ) - 1 ;
F_75 ( & V_2 -> V_14 , V_323 , V_322 ) ;
}
for ( V_320 = 0 ; V_320 < V_2 -> V_207 ; V_320 ++ ) {
struct V_64 * V_127 ;
V_172 = V_2 -> V_172 [ V_320 ] ;
F_126 (ring, q_vector->rx)
F_77 ( V_2 , 0 , V_127 -> V_156 , V_320 ) ;
F_126 (ring, q_vector->tx)
F_77 ( V_2 , 1 , V_127 -> V_156 , V_320 ) ;
F_207 ( V_172 ) ;
}
switch ( V_2 -> V_14 . V_114 . type ) {
case V_115 :
F_77 ( V_2 , - 1 , V_324 ,
V_320 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
F_77 ( V_2 , - 1 , 1 , V_320 ) ;
break;
default:
break;
}
F_75 ( & V_2 -> V_14 , F_208 ( V_320 ) , 1950 ) ;
V_124 = V_325 ;
V_124 &= ~ ( V_326 |
V_327 |
V_328 ) ;
F_75 ( & V_2 -> V_14 , V_329 , V_124 ) ;
}
static void F_209 ( struct V_171 * V_172 ,
struct V_330 * V_331 )
{
int V_185 = V_331 -> V_174 ;
int V_151 = V_331 -> V_175 ;
T_1 V_332 ;
T_6 V_333 ;
T_4 V_334 = V_331 -> V_335 ;
if ( V_151 == 0 )
return;
V_332 = V_172 -> V_335 >> 2 ;
if ( V_332 == 0 )
return;
V_333 = V_185 / V_332 ;
switch ( V_334 ) {
case V_336 :
if ( V_333 > 10 )
V_334 = V_337 ;
break;
case V_337 :
if ( V_333 > 20 )
V_334 = V_338 ;
else if ( V_333 <= 10 )
V_334 = V_336 ;
break;
case V_338 :
if ( V_333 <= 20 )
V_334 = V_337 ;
break;
}
V_331 -> V_174 = 0 ;
V_331 -> V_175 = 0 ;
V_331 -> V_335 = V_334 ;
}
void F_207 ( struct V_171 * V_172 )
{
struct V_1 * V_2 = V_172 -> V_2 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_320 = V_172 -> V_320 ;
T_1 V_339 = V_172 -> V_335 & V_340 ;
switch ( V_2 -> V_14 . V_114 . type ) {
case V_115 :
V_339 |= ( V_339 << 16 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_339 |= V_341 ;
break;
default:
break;
}
F_75 ( V_14 , F_208 ( V_320 ) , V_339 ) ;
}
static void F_210 ( struct V_171 * V_172 )
{
T_1 V_342 = V_172 -> V_335 ;
T_4 V_343 ;
F_209 ( V_172 , & V_172 -> V_177 ) ;
F_209 ( V_172 , & V_172 -> V_313 ) ;
V_343 = F_211 ( V_172 -> V_313 . V_335 , V_172 -> V_177 . V_335 ) ;
switch ( V_343 ) {
case V_336 :
V_342 = V_344 ;
break;
case V_337 :
V_342 = V_345 ;
break;
case V_338 :
V_342 = V_346 ;
break;
default:
break;
}
if ( V_342 != V_172 -> V_335 ) {
V_342 = ( 10 * V_342 * V_172 -> V_335 ) /
( ( 9 * V_342 ) + V_172 -> V_335 ) ;
V_172 -> V_335 = V_342 ;
F_207 ( V_172 ) ;
}
}
static void F_212 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_347 = V_2 -> V_348 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
if ( ! ( V_2 -> V_349 & V_350 ) &&
! ( V_2 -> V_349 & V_351 ) )
return;
V_2 -> V_349 &= ~ V_351 ;
switch ( V_14 -> V_21 ) {
case V_352 :
if ( ! ( V_347 & V_353 ) &&
! ( V_347 & V_354 ) )
return;
if ( ! ( V_347 & V_354 ) && V_14 -> V_114 . V_355 . V_356 ) {
T_1 V_20 ;
bool V_357 = false ;
V_14 -> V_114 . V_355 . V_356 ( V_14 , & V_20 , & V_357 , false ) ;
if ( V_357 )
return;
}
if ( V_14 -> V_46 . V_355 . V_358 ( V_14 ) != V_359 )
return;
break;
default:
if ( V_2 -> V_14 . V_114 . type >= V_118 )
return;
if ( ! ( V_347 & F_213 ( V_14 ) ) )
return;
break;
}
F_214 ( V_162 , L_71 , V_360 ) ;
V_2 -> V_348 = 0 ;
}
static void F_215 ( struct V_1 * V_2 , T_1 V_347 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ( V_2 -> V_146 & V_361 ) &&
( V_347 & F_216 ( V_14 ) ) ) {
F_214 ( V_187 , L_72 ) ;
F_75 ( V_14 , V_362 , F_216 ( V_14 ) ) ;
}
}
static void F_217 ( struct V_1 * V_2 , T_1 V_347 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! ( V_2 -> V_349 & V_350 ) )
return;
switch ( V_2 -> V_14 . V_114 . type ) {
case V_117 :
if ( ( ( V_347 & F_213 ( V_14 ) ) ||
( V_347 & V_354 ) ) &&
( ! F_14 ( V_34 , & V_2 -> V_35 ) ) ) {
V_2 -> V_348 = V_347 ;
V_2 -> V_349 |= V_351 ;
F_13 ( V_2 ) ;
return;
}
return;
case V_118 :
if ( ! ( V_347 & V_363 ) )
return;
break;
default:
return;
}
F_214 ( V_162 , L_71 , V_360 ) ;
}
static inline bool F_218 ( struct V_15 * V_14 )
{
switch ( V_14 -> V_114 . type ) {
case V_115 :
if ( V_14 -> V_46 . type == V_364 )
return true ;
return false ;
case V_117 :
case V_120 :
case V_121 :
switch ( V_14 -> V_114 . V_355 . V_365 ( V_14 ) ) {
case V_366 :
case V_367 :
return true ;
default:
return false ;
}
default:
return false ;
}
}
static void F_219 ( struct V_1 * V_2 , T_1 V_347 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_368 = F_220 ( V_14 ) ;
if ( ! F_218 ( V_14 ) )
return;
if ( V_14 -> V_114 . type >= V_118 )
V_368 = V_369 ;
if ( V_347 & V_368 ) {
F_75 ( V_14 , V_362 , V_368 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_349 |= V_370 ;
V_2 -> V_371 = 0 ;
F_13 ( V_2 ) ;
}
}
if ( V_2 -> V_14 . V_114 . type == V_117 &&
( V_347 & F_216 ( V_14 ) ) ) {
F_75 ( V_14 , V_362 , F_216 ( V_14 ) ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
V_2 -> V_146 |= V_372 ;
F_13 ( V_2 ) ;
}
}
}
static void F_221 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_373 ++ ;
V_2 -> V_146 |= V_374 ;
V_2 -> V_375 = V_186 ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_75 ( V_14 , V_376 , V_377 ) ;
F_222 ( V_14 ) ;
F_13 ( V_2 ) ;
}
}
static inline void F_223 ( struct V_1 * V_2 ,
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
F_75 ( V_14 , F_224 ( 0 ) , V_124 ) ;
V_124 = ( V_123 >> 32 ) ;
if ( V_124 )
F_75 ( V_14 , F_224 ( 1 ) , V_124 ) ;
break;
default:
break;
}
}
static inline void F_225 ( struct V_1 * V_2 ,
T_6 V_123 )
{
T_1 V_124 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_124 = ( V_125 & V_123 ) ;
F_75 ( V_14 , V_376 , V_124 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_124 = ( V_123 & 0xFFFFFFFF ) ;
if ( V_124 )
F_75 ( V_14 , F_226 ( 0 ) , V_124 ) ;
V_124 = ( V_123 >> 32 ) ;
if ( V_124 )
F_75 ( V_14 , F_226 ( 1 ) , V_124 ) ;
break;
default:
break;
}
}
static inline void F_227 ( struct V_1 * V_2 , bool V_379 ,
bool V_380 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_124 = ( V_325 & ~ V_125 ) ;
if ( V_2 -> V_146 & V_374 )
V_124 &= ~ V_328 ;
if ( V_2 -> V_349 & V_350 )
switch ( V_2 -> V_14 . V_114 . type ) {
case V_117 :
V_124 |= F_228 ( V_14 ) ;
break;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_124 |= V_381 ;
break;
default:
break;
}
if ( V_2 -> V_146 & V_361 )
V_124 |= F_229 ( V_14 ) ;
switch ( V_2 -> V_14 . V_114 . type ) {
case V_117 :
V_124 |= F_229 ( V_14 ) ;
V_124 |= F_230 ( V_14 ) ;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
if ( V_2 -> V_14 . V_21 == V_382 ||
V_2 -> V_14 . V_21 == V_383 ||
V_2 -> V_14 . V_21 == V_384 )
V_124 |= F_228 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_14 . V_46 . type == V_385 )
V_124 |= V_369 ;
V_124 |= V_386 ;
V_124 |= V_327 ;
break;
default:
break;
}
if ( ( V_2 -> V_146 & V_387 ) &&
! ( V_2 -> V_349 & V_388 ) )
V_124 |= V_389 ;
F_75 ( & V_2 -> V_14 , V_378 , V_124 ) ;
if ( V_379 )
F_223 ( V_2 , ~ 0 ) ;
if ( V_380 )
F_222 ( & V_2 -> V_14 ) ;
}
static T_11 F_231 ( int V_390 , void * V_98 )
{
struct V_1 * V_2 = V_98 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_347 ;
V_347 = F_40 ( V_14 , V_126 ) ;
V_347 &= 0xFFFF0000 ;
F_75 ( V_14 , V_362 , V_347 ) ;
if ( V_347 & V_354 )
F_221 ( V_2 ) ;
if ( V_347 & V_391 )
F_232 ( V_2 ) ;
switch ( V_14 -> V_114 . type ) {
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
if ( V_14 -> V_46 . type == V_385 &&
( V_347 & V_369 ) ) {
V_2 -> V_349 |= V_392 ;
F_13 ( V_2 ) ;
F_75 ( V_14 , V_362 ,
V_369 ) ;
}
if ( V_347 & V_393 ) {
F_110 ( V_394 , L_73 ) ;
F_97 ( V_161 , & V_2 -> V_35 ) ;
F_13 ( V_2 ) ;
F_75 ( V_14 , V_362 , V_393 ) ;
}
if ( V_347 & V_395 ) {
int V_396 = 0 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ ) {
struct V_64 * V_127 = V_2 -> V_65 [ V_49 ] ;
if ( F_233 ( V_397 ,
& V_127 -> V_35 ) )
V_396 ++ ;
}
if ( V_396 ) {
F_75 ( V_14 , V_376 , V_398 ) ;
V_2 -> V_349 |= V_388 ;
F_13 ( V_2 ) ;
}
}
F_219 ( V_2 , V_347 ) ;
F_217 ( V_2 , V_347 ) ;
break;
default:
break;
}
F_215 ( V_2 , V_347 ) ;
if ( F_23 ( V_347 & V_399 ) )
F_234 ( V_2 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_227 ( V_2 , false , false ) ;
return V_400 ;
}
static T_11 F_235 ( int V_390 , void * V_98 )
{
struct V_171 * V_172 = V_98 ;
if ( V_172 -> V_313 . V_127 || V_172 -> V_177 . V_127 )
F_236 ( & V_172 -> V_270 ) ;
return V_400 ;
}
int F_237 ( struct V_314 * V_270 , int V_176 )
{
struct V_171 * V_172 =
F_201 ( V_270 , struct V_171 , V_270 ) ;
struct V_1 * V_2 = V_172 -> V_2 ;
struct V_64 * V_127 ;
int V_401 , V_402 = 0 ;
bool V_403 = true ;
#ifdef F_238
if ( V_2 -> V_146 & V_193 )
F_124 ( V_172 ) ;
#endif
F_126 (ring, q_vector->tx) {
if ( ! F_100 ( V_172 , V_127 , V_176 ) )
V_403 = false ;
}
if ( ( V_176 <= 0 ) || ! F_239 ( V_172 ) )
return V_176 ;
if ( V_172 -> V_313 . V_94 > 1 )
V_401 = F_211 ( V_176 / V_172 -> V_313 . V_94 , 1 ) ;
else
V_401 = V_176 ;
F_126 (ring, q_vector->rx) {
int V_318 = F_197 ( V_172 , V_127 ,
V_401 ) ;
V_402 += V_318 ;
if ( V_318 >= V_401 )
V_403 = false ;
}
F_240 ( V_172 ) ;
if ( ! V_403 )
return V_176 ;
F_241 ( V_270 , V_402 ) ;
if ( V_2 -> V_404 & 1 )
F_210 ( V_172 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_223 ( V_2 , F_242 ( V_172 -> V_320 ) ) ;
return F_243 ( V_402 , V_176 - 1 ) ;
}
static int F_244 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
int V_405 , V_17 ;
int V_406 = 0 , V_407 = 0 ;
for ( V_405 = 0 ; V_405 < V_2 -> V_207 ; V_405 ++ ) {
struct V_171 * V_172 = V_2 -> V_172 [ V_405 ] ;
struct V_408 * V_409 = & V_2 -> V_410 [ V_405 ] ;
if ( V_172 -> V_177 . V_127 && V_172 -> V_313 . V_127 ) {
snprintf ( V_172 -> V_60 , sizeof( V_172 -> V_60 ) - 1 ,
L_74 , V_62 -> V_60 , L_75 , V_406 ++ ) ;
V_407 ++ ;
} else if ( V_172 -> V_313 . V_127 ) {
snprintf ( V_172 -> V_60 , sizeof( V_172 -> V_60 ) - 1 ,
L_74 , V_62 -> V_60 , L_76 , V_406 ++ ) ;
} else if ( V_172 -> V_177 . V_127 ) {
snprintf ( V_172 -> V_60 , sizeof( V_172 -> V_60 ) - 1 ,
L_74 , V_62 -> V_60 , L_77 , V_407 ++ ) ;
} else {
continue;
}
V_17 = F_245 ( V_409 -> V_405 , & F_235 , 0 ,
V_172 -> V_60 , V_172 ) ;
if ( V_17 ) {
F_108 ( V_187 , L_78
L_79 , V_17 ) ;
goto V_411;
}
if ( V_2 -> V_146 & V_387 ) {
F_246 ( V_409 -> V_405 ,
& V_172 -> V_412 ) ;
}
}
V_17 = F_245 ( V_2 -> V_410 [ V_405 ] . V_405 ,
F_231 , 0 , V_62 -> V_60 , V_2 ) ;
if ( V_17 ) {
F_108 ( V_187 , L_80 , V_17 ) ;
goto V_411;
}
return 0 ;
V_411:
while ( V_405 ) {
V_405 -- ;
F_246 ( V_2 -> V_410 [ V_405 ] . V_405 ,
NULL ) ;
F_247 ( V_2 -> V_410 [ V_405 ] . V_405 ,
V_2 -> V_172 [ V_405 ] ) ;
}
V_2 -> V_146 &= ~ V_413 ;
F_248 ( V_2 -> V_9 ) ;
F_249 ( V_2 -> V_410 ) ;
V_2 -> V_410 = NULL ;
return V_17 ;
}
static T_11 F_250 ( int V_390 , void * V_98 )
{
struct V_1 * V_2 = V_98 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_171 * V_172 = V_2 -> V_172 [ 0 ] ;
T_1 V_347 ;
F_75 ( V_14 , V_376 , V_414 ) ;
V_347 = F_40 ( V_14 , V_362 ) ;
if ( ! V_347 ) {
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_227 ( V_2 , true , true ) ;
return V_415 ;
}
if ( V_347 & V_354 )
F_221 ( V_2 ) ;
switch ( V_14 -> V_114 . type ) {
case V_117 :
F_219 ( V_2 , V_347 ) ;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
if ( V_347 & V_393 ) {
F_110 ( V_394 , L_73 ) ;
F_97 ( V_161 , & V_2 -> V_35 ) ;
F_13 ( V_2 ) ;
F_75 ( V_14 , V_362 , V_393 ) ;
}
F_217 ( V_2 , V_347 ) ;
break;
default:
break;
}
F_215 ( V_2 , V_347 ) ;
if ( F_23 ( V_347 & V_399 ) )
F_234 ( V_2 ) ;
F_236 ( & V_172 -> V_270 ) ;
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) )
F_227 ( V_2 , false , false ) ;
return V_400 ;
}
static int F_251 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
int V_17 ;
if ( V_2 -> V_146 & V_413 )
V_17 = F_244 ( V_2 ) ;
else if ( V_2 -> V_146 & V_416 )
V_17 = F_245 ( V_2 -> V_9 -> V_390 , F_250 , 0 ,
V_62 -> V_60 , V_2 ) ;
else
V_17 = F_245 ( V_2 -> V_9 -> V_390 , F_250 , V_417 ,
V_62 -> V_60 , V_2 ) ;
if ( V_17 )
F_108 ( V_187 , L_81 , V_17 ) ;
return V_17 ;
}
static void F_252 ( struct V_1 * V_2 )
{
int V_405 ;
if ( ! ( V_2 -> V_146 & V_413 ) ) {
F_247 ( V_2 -> V_9 -> V_390 , V_2 ) ;
return;
}
for ( V_405 = 0 ; V_405 < V_2 -> V_207 ; V_405 ++ ) {
struct V_171 * V_172 = V_2 -> V_172 [ V_405 ] ;
struct V_408 * V_409 = & V_2 -> V_410 [ V_405 ] ;
if ( ! V_172 -> V_313 . V_127 && ! V_172 -> V_177 . V_127 )
continue;
F_246 ( V_409 -> V_405 , NULL ) ;
F_247 ( V_409 -> V_405 , V_172 ) ;
}
F_247 ( V_2 -> V_410 [ V_405 ] . V_405 , V_2 ) ;
}
static inline void F_253 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_114 . type ) {
case V_115 :
F_75 ( & V_2 -> V_14 , V_376 , ~ 0 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
F_75 ( & V_2 -> V_14 , V_376 , 0xFFFF0000 ) ;
F_75 ( & V_2 -> V_14 , F_226 ( 0 ) , ~ 0 ) ;
F_75 ( & V_2 -> V_14 , F_226 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_222 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_146 & V_413 ) {
int V_405 ;
for ( V_405 = 0 ; V_405 < V_2 -> V_207 ; V_405 ++ )
F_254 ( V_2 -> V_410 [ V_405 ] . V_405 ) ;
F_254 ( V_2 -> V_410 [ V_405 ++ ] . V_405 ) ;
} else {
F_254 ( V_2 -> V_9 -> V_390 ) ;
}
}
static void F_255 ( struct V_1 * V_2 )
{
struct V_171 * V_172 = V_2 -> V_172 [ 0 ] ;
F_207 ( V_172 ) ;
F_77 ( V_2 , 0 , 0 , 0 ) ;
F_77 ( V_2 , 1 , 0 , 0 ) ;
F_110 ( V_14 , L_82 ) ;
}
void F_256 ( struct V_1 * V_2 ,
struct V_64 * V_127 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_418 = V_127 -> V_87 ;
int V_419 = 10 ;
T_1 V_420 = V_421 ;
T_4 V_156 = V_127 -> V_156 ;
F_75 ( V_14 , F_53 ( V_156 ) , 0 ) ;
F_222 ( V_14 ) ;
F_75 ( V_14 , F_48 ( V_156 ) ,
( V_418 & F_257 ( 32 ) ) ) ;
F_75 ( V_14 , F_49 ( V_156 ) , ( V_418 >> 32 ) ) ;
F_75 ( V_14 , F_50 ( V_156 ) ,
V_127 -> V_94 * sizeof( union V_68 ) ) ;
F_75 ( V_14 , F_51 ( V_156 ) , 0 ) ;
F_75 ( V_14 , F_52 ( V_156 ) , 0 ) ;
V_127 -> V_153 = V_2 -> V_422 + F_52 ( V_156 ) ;
if ( ! V_127 -> V_172 || ( V_127 -> V_172 -> V_335 < V_344 ) )
V_420 |= 1u << 16 ;
else
V_420 |= 8u << 16 ;
V_420 |= ( 1u << 8 ) |
32 ;
if ( V_2 -> V_146 & V_387 ) {
V_127 -> V_423 = V_2 -> V_423 ;
V_127 -> V_424 = 0 ;
F_97 ( V_397 , & V_127 -> V_35 ) ;
} else {
V_127 -> V_423 = 0 ;
}
if ( ! F_15 ( V_425 , & V_127 -> V_35 ) ) {
struct V_171 * V_172 = V_127 -> V_172 ;
if ( V_172 )
F_258 ( V_127 -> V_62 ,
& V_172 -> V_412 ,
V_127 -> V_92 ) ;
}
F_37 ( V_139 , & V_127 -> V_35 ) ;
F_75 ( V_14 , F_53 ( V_156 ) , V_420 ) ;
if ( V_14 -> V_114 . type == V_115 &&
! ( F_40 ( V_14 , V_426 ) & V_427 ) )
return;
do {
F_259 ( 1000 , 2000 ) ;
V_420 = F_40 ( V_14 , F_53 ( V_156 ) ) ;
} while ( -- V_419 && ! ( V_420 & V_421 ) );
if ( ! V_419 )
F_260 ( V_14 , L_83 , V_156 ) ;
}
static void F_261 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_428 , V_429 ;
T_4 V_430 = F_262 ( V_2 -> V_62 ) ;
if ( V_14 -> V_114 . type == V_115 )
return;
V_428 = F_40 ( V_14 , V_431 ) ;
V_428 |= V_432 ;
F_75 ( V_14 , V_431 , V_428 ) ;
if ( V_2 -> V_146 & V_433 ) {
V_429 = V_434 ;
if ( V_430 > 4 )
V_429 |= V_435 | V_436 ;
else if ( V_430 > 1 )
V_429 |= V_435 | V_437 ;
else if ( V_2 -> V_438 [ V_439 ] . V_124 ==
V_440 )
V_429 |= V_441 ;
else
V_429 |= V_442 ;
} else {
if ( V_430 > 4 )
V_429 = V_435 | V_436 ;
else if ( V_430 > 1 )
V_429 = V_435 | V_437 ;
else
V_429 = V_443 ;
}
F_75 ( V_14 , V_444 , V_429 ) ;
if ( V_430 ) {
T_1 V_445 = F_40 ( V_14 , V_446 ) ;
V_445 |= V_447 ;
F_75 ( V_14 , V_446 , V_445 ) ;
}
V_428 &= ~ V_432 ;
F_75 ( V_14 , V_431 , V_428 ) ;
}
static void F_263 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_448 ;
T_1 V_49 ;
F_261 ( V_2 ) ;
if ( V_14 -> V_114 . type != V_115 ) {
V_448 = F_40 ( V_14 , V_449 ) ;
V_448 |= V_450 ;
F_75 ( V_14 , V_449 , V_448 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ )
F_256 ( V_2 , V_2 -> V_65 [ V_49 ] ) ;
}
static void F_264 ( struct V_1 * V_2 ,
struct V_64 * V_127 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_156 = V_127 -> V_156 ;
T_1 V_451 = F_40 ( V_14 , F_39 ( V_156 ) ) ;
V_451 |= V_452 ;
F_75 ( V_14 , F_39 ( V_156 ) , V_451 ) ;
}
static void F_265 ( struct V_1 * V_2 ,
struct V_64 * V_127 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_156 = V_127 -> V_156 ;
T_1 V_451 = F_40 ( V_14 , F_39 ( V_156 ) ) ;
V_451 &= ~ V_452 ;
F_75 ( V_14 , F_39 ( V_156 ) , V_451 ) ;
}
static void F_266 ( struct V_1 * V_2 ,
struct V_64 * V_74 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_451 ;
T_4 V_156 = V_74 -> V_156 ;
if ( V_14 -> V_114 . type == V_115 ) {
T_2 V_124 = V_2 -> V_438 [ V_453 ] . V_124 ;
V_156 &= V_124 ;
}
V_451 = V_285 << V_454 ;
V_451 |= F_73 ( V_74 ) >> V_455 ;
V_451 |= V_456 ;
F_75 ( V_14 , F_39 ( V_156 ) , V_451 ) ;
}
T_1 F_267 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_114 . type < V_119 )
return 128 ;
else if ( V_2 -> V_146 & V_433 )
return 64 ;
else
return 512 ;
}
void F_268 ( struct V_1 * V_2 )
{
T_1 V_49 , V_457 = F_267 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_458 = 0 ;
T_1 V_459 ;
T_4 * V_460 = V_2 -> V_461 ;
if ( V_2 -> V_14 . V_114 . type == V_115 )
V_459 = 0x11 ;
else
V_459 = 0x1 ;
for ( V_49 = 0 ; V_49 < V_457 ; V_49 ++ ) {
V_458 |= V_459 * V_460 [ V_49 ] << ( V_49 & 0x3 ) * 8 ;
if ( ( V_49 & 3 ) == 3 ) {
if ( V_49 < 128 )
F_75 ( V_14 , F_269 ( V_49 >> 2 ) , V_458 ) ;
else
F_75 ( V_14 , F_270 ( ( V_49 >> 2 ) - 32 ) ,
V_458 ) ;
V_458 = 0 ;
}
}
}
static void F_271 ( struct V_1 * V_2 )
{
T_1 V_49 , V_457 = F_267 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_462 = 0 ;
unsigned int V_463 = V_2 -> V_321 ;
for ( V_49 = 0 ; V_49 < V_457 ; V_49 ++ ) {
V_462 |= ( T_1 ) V_2 -> V_461 [ V_49 ] << ( V_49 & 0x3 ) * 8 ;
if ( ( V_49 & 3 ) == 3 ) {
F_75 ( V_14 , F_272 ( V_49 >> 2 , V_463 ) ,
V_462 ) ;
V_462 = 0 ;
}
}
}
static void F_273 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_49 , V_56 ;
T_1 V_457 = F_267 ( V_2 ) ;
T_2 V_464 = V_2 -> V_438 [ V_453 ] . V_465 ;
if ( ( V_2 -> V_146 & V_433 ) && ( V_464 < 4 ) )
V_464 = 4 ;
for ( V_49 = 0 ; V_49 < 10 ; V_49 ++ )
F_75 ( V_14 , F_274 ( V_49 ) , V_2 -> V_466 [ V_49 ] ) ;
memset ( V_2 -> V_461 , 0 , sizeof( V_2 -> V_461 ) ) ;
for ( V_49 = 0 , V_56 = 0 ; V_49 < V_457 ; V_49 ++ , V_56 ++ ) {
if ( V_56 == V_464 )
V_56 = 0 ;
V_2 -> V_461 [ V_49 ] = V_56 ;
}
F_268 ( V_2 ) ;
}
static void F_275 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_464 = V_2 -> V_438 [ V_453 ] . V_465 ;
unsigned int V_463 = V_2 -> V_321 ;
int V_49 , V_56 ;
for ( V_49 = 0 ; V_49 < 10 ; V_49 ++ )
F_75 ( V_14 , F_276 ( V_49 , V_463 ) ,
V_2 -> V_466 [ V_49 ] ) ;
for ( V_49 = 0 , V_56 = 0 ; V_49 < 64 ; V_49 ++ , V_56 ++ ) {
if ( V_56 == V_464 )
V_56 = 0 ;
V_2 -> V_461 [ V_49 ] = V_56 ;
}
F_271 ( V_2 ) ;
}
static void F_277 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_467 = 0 , V_468 = 0 , V_469 = 0 ;
T_1 V_470 ;
V_470 = F_40 ( V_14 , V_471 ) ;
V_470 |= V_472 ;
F_75 ( V_14 , V_471 , V_470 ) ;
if ( V_2 -> V_14 . V_114 . type == V_115 ) {
if ( V_2 -> V_438 [ V_453 ] . V_124 )
V_467 = V_473 ;
} else {
T_4 V_430 = F_262 ( V_2 -> V_62 ) ;
if ( V_2 -> V_146 & V_433 ) {
if ( V_430 > 4 )
V_467 = V_474 ;
else if ( V_430 > 1 )
V_467 = V_475 ;
else if ( V_2 -> V_438 [ V_439 ] . V_124 ==
V_440 )
V_467 = V_476 ;
else
V_467 = V_477 ;
} else {
if ( V_430 > 4 )
V_467 = V_478 ;
else if ( V_430 > 1 )
V_467 = V_479 ;
else
V_467 = V_473 ;
}
}
V_468 |= V_480 |
V_481 |
V_482 |
V_483 ;
if ( V_2 -> V_349 & V_484 )
V_468 |= V_485 ;
if ( V_2 -> V_349 & V_486 )
V_468 |= V_487 ;
F_278 ( V_2 -> V_466 , sizeof( V_2 -> V_466 ) ) ;
if ( ( V_14 -> V_114 . type >= V_119 ) &&
( V_2 -> V_146 & V_433 ) ) {
unsigned int V_463 = V_2 -> V_321 ;
V_467 |= V_488 ;
F_75 ( V_14 , V_489 , V_467 ) ;
F_275 ( V_2 ) ;
V_469 = V_473 ;
V_469 |= V_468 ;
F_75 ( V_14 , F_279 ( V_463 ) , V_469 ) ;
} else {
F_273 ( V_2 ) ;
V_467 |= V_468 ;
F_75 ( V_14 , V_489 , V_467 ) ;
}
}
static void F_280 ( struct V_1 * V_2 ,
struct V_64 * V_127 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_490 ;
T_4 V_156 = V_127 -> V_156 ;
if ( ! F_170 ( V_127 ) )
return;
V_490 = F_40 ( V_14 , F_281 ( V_156 ) ) ;
V_490 |= V_491 ;
V_490 |= V_492 ;
F_75 ( V_14 , F_281 ( V_156 ) , V_490 ) ;
}
static void F_282 ( struct V_1 * V_2 ,
struct V_64 * V_127 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_419 = V_493 ;
T_1 V_494 ;
T_4 V_156 = V_127 -> V_156 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
if ( V_14 -> V_114 . type == V_115 &&
! ( F_40 ( V_14 , V_426 ) & V_427 ) )
return;
do {
F_259 ( 1000 , 2000 ) ;
V_494 = F_40 ( V_14 , F_45 ( V_156 ) ) ;
} while ( -- V_419 && ! ( V_494 & V_495 ) );
if ( ! V_419 ) {
F_108 ( V_162 , L_84
L_85 , V_156 ) ;
}
}
void F_283 ( struct V_1 * V_2 ,
struct V_64 * V_127 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_419 = V_493 ;
T_1 V_494 ;
T_4 V_156 = V_127 -> V_156 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
V_494 = F_40 ( V_14 , F_45 ( V_156 ) ) ;
V_494 &= ~ V_495 ;
F_75 ( V_14 , F_45 ( V_156 ) , V_494 ) ;
if ( V_14 -> V_114 . type == V_115 &&
! ( F_40 ( V_14 , V_426 ) & V_427 ) )
return;
do {
F_26 ( 10 ) ;
V_494 = F_40 ( V_14 , F_45 ( V_156 ) ) ;
} while ( -- V_419 && ( V_494 & V_495 ) );
if ( ! V_419 ) {
F_108 ( V_162 , L_86
L_85 , V_156 ) ;
}
}
void F_284 ( struct V_1 * V_2 ,
struct V_64 * V_127 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_496 = V_127 -> V_87 ;
T_1 V_494 ;
T_4 V_156 = V_127 -> V_156 ;
V_494 = F_40 ( V_14 , F_45 ( V_156 ) ) ;
F_283 ( V_2 , V_127 ) ;
F_75 ( V_14 , F_46 ( V_156 ) , ( V_496 & F_257 ( 32 ) ) ) ;
F_75 ( V_14 , F_47 ( V_156 ) , ( V_496 >> 32 ) ) ;
F_75 ( V_14 , F_42 ( V_156 ) ,
V_127 -> V_94 * sizeof( union V_75 ) ) ;
F_222 ( V_14 ) ;
F_75 ( V_14 , F_43 ( V_156 ) , 0 ) ;
F_75 ( V_14 , F_44 ( V_156 ) , 0 ) ;
V_127 -> V_153 = V_2 -> V_422 + F_44 ( V_156 ) ;
F_266 ( V_2 , V_127 ) ;
F_280 ( V_2 , V_127 ) ;
if ( V_14 -> V_114 . type == V_115 ) {
V_494 &= ~ 0x3FFFFF ;
V_494 |= 0x080420 ;
}
V_494 |= V_495 ;
F_75 ( V_14 , F_45 ( V_156 ) , V_494 ) ;
F_282 ( V_2 , V_127 ) ;
F_148 ( V_127 , F_115 ( V_127 ) ) ;
}
static void F_285 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_464 = V_2 -> V_438 [ V_453 ] . V_465 ;
T_2 V_497 ;
T_1 V_498 = V_499 |
V_500 |
V_501 |
V_502 |
V_503 ;
if ( V_14 -> V_114 . type == V_115 )
return;
if ( V_464 > 3 )
V_498 |= 2u << 29 ;
else if ( V_464 > 1 )
V_498 |= 1u << 29 ;
F_286 (pool, &adapter->fwd_bitmask, 32 )
F_75 ( V_14 , F_287 ( F_288 ( V_497 ) ) , V_498 ) ;
}
static void F_289 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_192 , V_504 ;
T_1 V_505 , V_506 ;
int V_49 ;
if ( ! ( V_2 -> V_146 & V_433 ) )
return;
V_506 = F_40 ( V_14 , V_507 ) ;
V_506 |= V_508 ;
V_506 &= ~ V_509 ;
V_506 |= F_288 ( 0 ) << V_510 ;
V_506 |= V_511 ;
F_75 ( V_14 , V_507 , V_506 ) ;
V_504 = F_288 ( 0 ) % 32 ;
V_192 = ( F_288 ( 0 ) >= 32 ) ? 1 : 0 ;
F_75 ( V_14 , F_290 ( V_192 ) , F_291 ( 31 , V_504 ) ) ;
F_75 ( V_14 , F_290 ( V_192 ^ 1 ) , V_192 - 1 ) ;
F_75 ( V_14 , F_292 ( V_192 ) , F_291 ( 31 , V_504 ) ) ;
F_75 ( V_14 , F_292 ( V_192 ^ 1 ) , V_192 - 1 ) ;
if ( V_2 -> V_512 == V_513 )
F_75 ( V_14 , V_514 , V_515 ) ;
V_14 -> V_114 . V_355 . V_516 ( V_14 , 0 , F_288 ( 0 ) ) ;
V_2 -> V_349 &= ~ V_517 ;
switch ( V_2 -> V_438 [ V_439 ] . V_124 ) {
case V_518 :
V_505 = V_519 ;
break;
case V_440 :
V_505 = V_520 ;
break;
default:
V_505 = V_521 ;
break;
}
F_75 ( V_14 , V_522 , V_505 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_321 ; V_49 ++ ) {
F_293 ( V_2 -> V_62 , V_49 ,
V_2 -> V_523 [ V_49 ] . V_524 ) ;
F_294 ( V_2 -> V_62 , V_49 ,
V_2 -> V_523 [ V_49 ] . V_525 ) ;
}
}
static void F_295 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_61 * V_62 = V_2 -> V_62 ;
int V_526 = V_62 -> V_309 + V_527 + V_528 ;
struct V_64 * V_74 ;
int V_49 ;
T_1 V_529 , V_530 ;
#ifdef F_181
if ( ( V_2 -> V_146 & V_531 ) &&
( V_526 < V_532 ) )
V_526 = V_532 ;
#endif
if ( V_526 < ( V_533 + V_528 ) )
V_526 = ( V_533 + V_528 ) ;
V_529 = F_40 ( V_14 , V_534 ) ;
if ( V_526 != ( V_529 >> V_535 ) ) {
V_529 &= ~ V_536 ;
V_529 |= V_526 << V_535 ;
F_75 ( V_14 , V_534 , V_529 ) ;
}
V_530 = F_40 ( V_14 , V_537 ) ;
V_530 |= V_538 ;
F_75 ( V_14 , V_537 , V_530 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ ) {
V_74 = V_2 -> V_74 [ V_49 ] ;
if ( V_2 -> V_349 & V_539 )
F_296 ( V_74 ) ;
else
F_297 ( V_74 ) ;
}
}
static void F_298 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_540 = F_40 ( V_14 , V_541 ) ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_540 |= V_542 ;
break;
case V_119 :
case V_120 :
case V_121 :
if ( V_2 -> V_321 )
V_540 |= V_543 ;
case V_117 :
case V_118 :
F_75 ( V_14 , V_544 ,
( V_545 | F_40 ( V_14 , V_544 ) ) ) ;
V_540 &= ~ V_546 ;
V_540 |= ( V_547 | V_548 ) ;
V_540 |= V_549 ;
break;
default:
return;
}
F_75 ( V_14 , V_541 , V_540 ) ;
}
static void F_299 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
T_1 V_198 , V_550 ;
V_14 -> V_114 . V_355 . V_551 ( V_14 ) ;
F_285 ( V_2 ) ;
F_298 ( V_2 ) ;
V_550 = F_40 ( V_14 , V_552 ) ;
V_550 &= ~ V_553 ;
if ( ! ( V_2 -> V_349 & V_539 ) )
V_550 |= V_553 ;
V_550 |= ( V_554 | V_555 ) ;
F_75 ( V_14 , V_552 , V_550 ) ;
F_277 ( V_2 ) ;
F_295 ( V_2 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ )
F_284 ( V_2 , V_2 -> V_74 [ V_49 ] ) ;
V_198 = F_40 ( V_14 , V_556 ) ;
if ( V_14 -> V_114 . type == V_115 )
V_198 |= V_557 ;
V_198 |= V_558 ;
V_14 -> V_114 . V_355 . V_559 ( V_14 , V_198 ) ;
}
static int F_300 ( struct V_61 * V_62 ,
T_12 V_560 , T_2 V_266 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! V_266 || ! ( V_2 -> V_349 & V_517 ) )
V_14 -> V_114 . V_355 . V_561 ( & V_2 -> V_14 , V_266 , F_288 ( 0 ) , true , ! ! V_266 ) ;
F_97 ( V_266 , V_2 -> V_562 ) ;
return 0 ;
}
static int F_301 ( struct V_15 * V_14 , T_1 V_267 )
{
T_1 V_563 ;
int V_564 ;
if ( V_267 == 0 )
return 0 ;
for ( V_564 = V_565 ; -- V_564 ; ) {
V_563 = F_40 ( V_14 , F_302 ( V_564 ) ) ;
if ( ( V_563 & V_566 ) == V_267 )
break;
}
return V_564 ;
}
void F_303 ( struct V_1 * V_2 , T_1 V_266 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_567 , V_568 ;
int V_564 ;
V_564 = F_301 ( V_14 , V_266 ) ;
if ( ! V_564 )
return;
V_568 = V_564 * 2 + ( F_288 ( 0 ) / 32 ) ;
V_567 = ~ F_206 ( F_288 ( 0 ) % 32 ) ;
V_567 &= F_40 ( V_14 , F_304 ( V_568 ) ) ;
if ( ! V_567 && ! F_40 ( V_14 , F_304 ( V_568 ^ 1 ) ) ) {
if ( ! ( V_2 -> V_349 & V_517 ) )
F_75 ( V_14 , F_304 ( V_568 ) , 0 ) ;
F_75 ( V_14 , F_302 ( V_564 ) , 0 ) ;
}
}
static int F_305 ( struct V_61 * V_62 ,
T_12 V_560 , T_2 V_266 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_266 && ! ( V_2 -> V_349 & V_517 ) )
V_14 -> V_114 . V_355 . V_561 ( V_14 , V_266 , F_288 ( 0 ) , false , true ) ;
F_37 ( V_266 , V_2 -> V_562 ) ;
return 0 ;
}
static void F_306 ( struct V_1 * V_2 )
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
static void F_307 ( struct V_1 * V_2 )
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
static void F_308 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_569 , V_49 ;
V_569 = F_40 ( V_14 , V_570 ) ;
if ( V_2 -> V_146 & V_573 ) {
V_569 |= V_574 ;
F_75 ( V_14 , V_570 , V_569 ) ;
} else {
V_569 &= ~ V_574 ;
F_75 ( V_14 , V_570 , V_569 ) ;
return;
}
if ( V_14 -> V_114 . type == V_115 )
return;
if ( V_2 -> V_349 & V_517 )
return;
V_2 -> V_349 |= V_517 ;
for ( V_49 = V_565 ; -- V_49 ; ) {
T_1 V_192 = F_304 ( V_49 * 2 + F_288 ( 0 ) / 32 ) ;
T_1 V_575 = F_40 ( V_14 , V_192 ) ;
V_575 |= F_206 ( F_288 ( 0 ) % 32 ) ;
F_75 ( V_14 , V_192 , V_575 ) ;
}
for ( V_49 = V_14 -> V_114 . V_576 ; V_49 -- ; )
F_75 ( V_14 , F_309 ( V_49 ) , ~ 0U ) ;
}
static void F_310 ( struct V_1 * V_2 , T_1 V_577 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_578 [ V_579 ] = { 0 } ;
T_1 V_580 = V_577 * 32 ;
T_1 V_581 = V_580 + ( V_579 * 32 ) ;
T_1 V_49 , V_266 , V_568 , V_567 ;
for ( V_49 = V_565 ; -- V_49 ; ) {
T_1 V_563 = F_40 ( V_14 , F_302 ( V_49 ) ) ;
V_266 = V_563 & V_566 ;
if ( V_266 < V_580 || V_266 >= V_581 )
continue;
if ( V_563 ) {
V_578 [ ( V_266 - V_580 ) / 32 ] |= F_206 ( V_266 % 32 ) ;
if ( F_14 ( V_266 , V_2 -> V_562 ) )
continue;
}
V_568 = V_49 * 2 + F_288 ( 0 ) / 32 ;
V_567 = ~ F_206 ( F_288 ( 0 ) % 32 ) ;
V_567 &= F_40 ( V_14 , F_304 ( V_568 ) ) ;
F_75 ( V_14 , F_304 ( V_568 ) , V_567 ) ;
}
for ( V_49 = V_579 ; V_49 -- ; ) {
V_266 = ( V_577 + V_49 ) * 32 ;
V_568 = V_266 / V_582 ;
V_567 = V_266 % V_582 ;
V_578 [ V_49 ] |= V_2 -> V_562 [ V_568 ] >> V_567 ;
F_75 ( V_14 , F_309 ( V_577 + V_49 ) , V_578 [ V_49 ] ) ;
}
}
static void F_311 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_569 , V_49 ;
V_569 = F_40 ( V_14 , V_570 ) ;
V_569 |= V_574 ;
F_75 ( V_14 , V_570 , V_569 ) ;
if ( ! ( V_2 -> V_146 & V_573 ) ||
V_14 -> V_114 . type == V_115 )
return;
if ( ! ( V_2 -> V_349 & V_517 ) )
return;
V_2 -> V_349 &= ~ V_517 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_114 . V_576 ; V_49 += V_579 )
F_310 ( V_2 , V_49 ) ;
}
static void F_312 ( struct V_1 * V_2 )
{
T_2 V_266 = 1 ;
F_300 ( V_2 -> V_62 , F_161 ( V_268 ) , 0 ) ;
F_313 (vid, adapter->active_vlans, VLAN_N_VID)
F_300 ( V_2 -> V_62 , F_161 ( V_268 ) , V_266 ) ;
}
static int F_314 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! F_61 ( V_62 ) )
return 0 ;
if ( V_14 -> V_114 . V_355 . V_583 )
V_14 -> V_114 . V_355 . V_583 ( V_14 , V_62 ) ;
else
return - V_584 ;
#ifdef F_315
F_316 ( V_2 ) ;
#endif
return F_317 ( V_62 ) ;
}
void F_318 ( struct V_1 * V_2 )
{
struct V_585 * V_586 = & V_2 -> V_586 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_114 . V_587 ; V_49 ++ , V_586 ++ ) {
V_586 -> V_35 &= ~ V_588 ;
if ( V_586 -> V_35 & V_589 )
V_14 -> V_114 . V_355 . V_590 ( V_14 , V_49 ,
V_586 -> V_591 ,
V_586 -> V_497 ,
V_592 ) ;
else
V_14 -> V_114 . V_355 . V_593 ( V_14 , V_49 ) ;
}
}
static void F_319 ( struct V_1 * V_2 )
{
struct V_585 * V_586 = & V_2 -> V_586 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_114 . V_587 ; V_49 ++ , V_586 ++ ) {
if ( ! ( V_586 -> V_35 & V_588 ) )
continue;
V_586 -> V_35 &= ~ V_588 ;
if ( V_586 -> V_35 & V_589 )
V_14 -> V_114 . V_355 . V_590 ( V_14 , V_49 ,
V_586 -> V_591 ,
V_586 -> V_497 ,
V_592 ) ;
else
V_14 -> V_114 . V_355 . V_593 ( V_14 , V_49 ) ;
}
}
static void F_320 ( struct V_1 * V_2 )
{
struct V_585 * V_586 = & V_2 -> V_586 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_114 . V_587 ; V_49 ++ , V_586 ++ ) {
V_586 -> V_35 |= V_588 ;
V_586 -> V_35 &= ~ V_589 ;
}
F_319 ( V_2 ) ;
}
static int F_321 ( struct V_1 * V_2 , T_2 V_497 )
{
struct V_585 * V_586 = & V_2 -> V_586 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 , V_94 = 0 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_114 . V_587 ; V_49 ++ , V_586 ++ ) {
if ( V_586 -> V_35 & V_594 )
continue;
if ( V_586 -> V_35 & V_589 ) {
if ( V_586 -> V_497 != V_497 )
continue;
}
V_94 ++ ;
}
return V_94 ;
}
static void F_322 ( struct V_1 * V_2 )
{
struct V_585 * V_586 = & V_2 -> V_586 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
memcpy ( & V_586 -> V_591 , V_14 -> V_114 . V_591 , V_595 ) ;
V_586 -> V_497 = F_288 ( 0 ) ;
V_586 -> V_35 = V_594 | V_589 ;
V_14 -> V_114 . V_355 . V_590 ( V_14 , 0 , V_586 -> V_591 , V_586 -> V_497 ,
V_592 ) ;
}
int F_323 ( struct V_1 * V_2 ,
const T_4 * V_591 , T_2 V_497 )
{
struct V_585 * V_586 = & V_2 -> V_586 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( F_324 ( V_591 ) )
return - V_596 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_114 . V_587 ; V_49 ++ , V_586 ++ ) {
if ( V_586 -> V_35 & V_589 )
continue;
F_325 ( V_586 -> V_591 , V_591 ) ;
V_586 -> V_497 = V_497 ;
V_586 -> V_35 |= V_588 |
V_589 ;
F_319 ( V_2 ) ;
return V_49 ;
}
return - V_584 ;
}
int F_326 ( struct V_1 * V_2 ,
const T_4 * V_591 , T_2 V_497 )
{
struct V_585 * V_586 = & V_2 -> V_586 [ 0 ] ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( F_324 ( V_591 ) )
return - V_596 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_114 . V_587 ; V_49 ++ , V_586 ++ ) {
if ( ! ( V_586 -> V_35 & V_589 ) )
continue;
if ( V_586 -> V_497 != V_497 )
continue;
if ( ! F_327 ( V_591 , V_586 -> V_591 ) )
continue;
V_586 -> V_35 |= V_588 ;
V_586 -> V_35 &= ~ V_589 ;
F_319 ( V_2 ) ;
return 0 ;
}
return - V_584 ;
}
static int F_328 ( struct V_61 * V_62 , int V_597 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
int V_94 = 0 ;
if ( F_329 ( V_62 ) > F_321 ( V_2 , V_597 ) )
return - V_584 ;
if ( ! F_330 ( V_62 ) ) {
struct V_598 * V_599 ;
F_331 (ha, netdev) {
F_326 ( V_2 , V_599 -> V_591 , V_597 ) ;
F_323 ( V_2 , V_599 -> V_591 , V_597 ) ;
V_94 ++ ;
}
}
return V_94 ;
}
static int F_332 ( struct V_61 * V_62 , const unsigned char * V_591 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
int V_600 ;
V_600 = F_323 ( V_2 , V_591 , F_288 ( 0 ) ) ;
return F_333 ( int , V_600 , 0 ) ;
}
static int F_334 ( struct V_61 * V_62 , const unsigned char * V_591 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
F_326 ( V_2 , V_591 , F_288 ( 0 ) ) ;
return 0 ;
}
void F_335 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_601 , V_602 = V_603 | V_604 ;
T_13 V_215 = V_62 -> V_215 ;
int V_94 ;
V_601 = F_40 ( V_14 , V_605 ) ;
V_601 &= ~ V_606 ;
V_601 |= V_607 ;
V_601 |= V_608 ;
V_601 |= V_609 ;
V_601 &= ~ ( V_610 | V_611 ) ;
if ( V_62 -> V_146 & V_612 ) {
V_14 -> V_613 . V_614 = true ;
V_601 |= ( V_610 | V_611 ) ;
V_602 |= V_615 ;
V_215 &= ~ V_616 ;
} else {
if ( V_62 -> V_146 & V_617 ) {
V_601 |= V_611 ;
V_602 |= V_615 ;
}
V_14 -> V_613 . V_614 = false ;
}
if ( F_336 ( V_62 , F_332 , F_334 ) ) {
V_601 |= V_610 ;
V_602 |= V_618 ;
}
V_94 = F_314 ( V_62 ) ;
if ( V_94 < 0 ) {
V_601 |= V_611 ;
V_602 |= V_615 ;
} else if ( V_94 ) {
V_602 |= V_619 ;
}
if ( V_14 -> V_114 . type != V_115 ) {
V_602 |= F_40 ( V_14 , F_337 ( F_288 ( 0 ) ) ) &
~ ( V_615 | V_619 |
V_618 ) ;
F_75 ( V_14 , F_337 ( F_288 ( 0 ) ) , V_602 ) ;
}
if ( V_215 & V_289 ) {
V_601 |= ( V_606 |
V_607 |
V_609 ) ;
V_601 &= ~ ( V_608 ) ;
}
F_75 ( V_14 , V_605 , V_601 ) ;
if ( V_215 & V_264 )
F_307 ( V_2 ) ;
else
F_306 ( V_2 ) ;
if ( V_215 & V_616 )
F_311 ( V_2 ) ;
else
F_308 ( V_2 ) ;
}
static void F_338 ( struct V_1 * V_2 )
{
int V_620 ;
for ( V_620 = 0 ; V_620 < V_2 -> V_207 ; V_620 ++ ) {
F_339 ( V_2 -> V_172 [ V_620 ] ) ;
F_340 ( & V_2 -> V_172 [ V_620 ] -> V_270 ) ;
}
}
static void F_341 ( struct V_1 * V_2 )
{
int V_620 ;
for ( V_620 = 0 ; V_620 < V_2 -> V_207 ; V_620 ++ ) {
F_342 ( & V_2 -> V_172 [ V_620 ] -> V_270 ) ;
while ( ! F_343 ( V_2 -> V_172 [ V_620 ] ) ) {
F_54 ( L_87 , V_620 ) ;
F_259 ( 1000 , 20000 ) ;
}
}
}
static void F_344 ( struct V_1 * V_2 , T_1 V_124 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_621 ;
if ( ! ( V_2 -> V_146 & ( V_622 |
V_623 ) ) )
return;
V_621 = F_40 ( V_14 , V_624 ) && ~ V_124 ;
F_75 ( V_14 , V_624 , V_621 ) ;
if ( V_124 & V_625 )
V_2 -> V_626 = 0 ;
if ( V_124 & V_627 )
V_2 -> V_628 = 0 ;
}
static void F_345 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_526 = V_2 -> V_62 -> V_309 + V_527 + V_528 ;
if ( ! ( V_2 -> V_146 & V_147 ) ) {
if ( V_14 -> V_114 . type == V_115 )
F_346 ( V_2 -> V_62 , 65536 ) ;
return;
}
if ( V_14 -> V_114 . type == V_115 )
F_346 ( V_2 -> V_62 , 32768 ) ;
#ifdef F_181
if ( V_2 -> V_62 -> V_215 & V_629 )
V_526 = F_211 ( V_526 , V_532 ) ;
#endif
if ( V_2 -> V_630 & V_631 ) {
F_347 ( V_14 , & V_2 -> V_143 , V_526 ,
V_632 ) ;
F_347 ( V_14 , & V_2 -> V_143 , V_526 ,
V_633 ) ;
F_348 ( V_14 , & V_2 -> V_143 ) ;
} else if ( V_2 -> V_634 && V_2 -> V_145 ) {
F_349 ( & V_2 -> V_14 ,
V_2 -> V_634 ,
V_526 ) ;
F_350 ( & V_2 -> V_14 ,
V_2 -> V_145 -> V_142 ,
V_2 -> V_634 -> V_635 ) ;
}
if ( V_14 -> V_114 . type != V_115 ) {
T_1 V_636 = 0 ;
T_2 V_464 = V_2 -> V_438 [ V_453 ] . V_465 - 1 ;
while ( V_464 ) {
V_636 ++ ;
V_464 >>= 1 ;
}
F_75 ( V_14 , V_637 , V_636 * 0x11111111 ) ;
}
}
static int F_351 ( struct V_1 * V_2 , int V_638 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_61 * V_80 = V_2 -> V_62 ;
int V_394 , V_141 , V_639 , V_640 ;
T_1 V_641 , V_642 ;
V_141 = V_394 = V_80 -> V_309 + V_527 + V_528 + V_643 ;
#ifdef F_181
if ( ( V_80 -> V_215 & V_629 ) &&
( V_141 < V_532 ) &&
( V_638 == F_352 ( V_2 ) ) )
V_141 = V_532 ;
#endif
switch ( V_14 -> V_114 . type ) {
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_641 = F_353 ( V_394 , V_141 ) ;
break;
default:
V_641 = F_354 ( V_394 , V_141 ) ;
break;
}
if ( V_2 -> V_146 & V_433 )
V_641 += F_355 ( V_141 ) ;
V_639 = F_356 ( V_641 ) ;
V_642 = F_40 ( V_14 , F_357 ( V_638 ) ) >> 10 ;
V_640 = V_642 - V_639 ;
if ( V_640 < 0 ) {
F_27 ( V_162 , L_88
L_89
L_90 , V_638 ) ;
V_640 = V_141 + 1 ;
}
return V_640 ;
}
static int F_358 ( struct V_1 * V_2 , int V_638 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_61 * V_80 = V_2 -> V_62 ;
int V_141 ;
T_1 V_641 ;
V_141 = V_80 -> V_309 + V_527 + V_528 ;
#ifdef F_181
if ( ( V_80 -> V_215 & V_629 ) &&
( V_141 < V_532 ) &&
( V_638 == F_90 ( V_80 , V_2 -> V_644 . V_645 ) ) )
V_141 = V_532 ;
#endif
switch ( V_14 -> V_114 . type ) {
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_641 = F_359 ( V_141 ) ;
break;
default:
V_641 = F_360 ( V_141 ) ;
break;
}
return F_356 ( V_641 ) ;
}
static void F_361 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_646 = F_262 ( V_2 -> V_62 ) ;
int V_49 ;
if ( ! V_646 )
V_646 = 1 ;
for ( V_49 = 0 ; V_49 < V_646 ; V_49 ++ ) {
V_14 -> V_132 . V_647 [ V_49 ] = F_351 ( V_2 , V_49 ) ;
V_14 -> V_132 . V_648 [ V_49 ] = F_358 ( V_2 , V_49 ) ;
if ( V_14 -> V_132 . V_648 [ V_49 ] > V_14 -> V_132 . V_647 [ V_49 ] )
V_14 -> V_132 . V_648 [ V_49 ] = 0 ;
}
for (; V_49 < V_649 ; V_49 ++ )
V_14 -> V_132 . V_647 [ V_49 ] = 0 ;
}
static void F_362 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_650 ;
T_4 V_141 = F_262 ( V_2 -> V_62 ) ;
if ( V_2 -> V_146 & V_387 ||
V_2 -> V_146 & V_651 )
V_650 = 32 << V_2 -> V_652 ;
else
V_650 = 0 ;
V_14 -> V_114 . V_355 . V_653 ( V_14 , V_141 , V_650 , V_654 ) ;
F_361 ( V_2 ) ;
}
static void F_363 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_655 * V_656 ;
struct V_657 * V_658 ;
F_364 ( & V_2 -> V_659 ) ;
if ( ! F_365 ( & V_2 -> V_660 ) )
F_366 ( V_14 , & V_2 -> V_661 ) ;
F_367 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_368 ( V_14 ,
& V_658 -> V_658 ,
V_658 -> V_662 ,
( V_658 -> V_663 == V_664 ) ?
V_664 :
V_2 -> V_74 [ V_658 -> V_663 ] -> V_156 ) ;
}
F_369 ( & V_2 -> V_659 ) ;
}
static void F_370 ( struct V_61 * V_80 , unsigned int V_497 ,
struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_602 ;
V_602 = F_40 ( V_14 , F_337 ( V_497 ) ) ;
V_602 |= ( V_619 | V_603 | V_604 ) ;
V_602 &= ~ V_615 ;
if ( V_80 -> V_146 & V_617 ) {
V_602 |= V_615 ;
} else {
V_602 |= V_619 ;
V_14 -> V_114 . V_355 . V_583 ( V_14 , V_80 ) ;
}
F_328 ( V_2 -> V_62 , V_497 ) ;
F_75 ( V_14 , F_337 ( V_497 ) , V_602 ) ;
}
static void F_371 ( struct V_665 * V_666 )
{
struct V_1 * V_2 = V_666 -> V_155 ;
int V_464 = V_2 -> V_667 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_497 = V_666 -> V_497 ;
T_1 V_498 = V_499 |
V_500 |
V_501 |
V_502 |
V_503 ;
if ( V_14 -> V_114 . type == V_115 )
return;
if ( V_464 > 3 )
V_498 |= 2u << 29 ;
else if ( V_464 > 1 )
V_498 |= 1u << 29 ;
F_75 ( V_14 , F_287 ( F_288 ( V_497 ) ) , V_498 ) ;
}
static void F_372 ( struct V_64 * V_74 )
{
struct V_208 * V_80 = V_74 -> V_80 ;
unsigned long V_294 ;
T_2 V_49 ;
if ( ! V_74 -> V_78 )
return;
for ( V_49 = 0 ; V_49 < V_74 -> V_94 ; V_49 ++ ) {
struct V_77 * V_293 = & V_74 -> V_78 [ V_49 ] ;
if ( V_293 -> V_95 ) {
struct V_213 * V_95 = V_293 -> V_95 ;
if ( F_156 ( V_95 ) -> V_287 )
F_84 ( V_80 ,
F_156 ( V_95 ) -> V_87 ,
F_73 ( V_74 ) ,
V_251 ) ;
F_373 ( V_95 ) ;
V_293 -> V_95 = NULL ;
}
if ( ! V_293 -> V_104 )
continue;
F_84 ( V_80 , V_293 -> V_87 ,
F_145 ( V_74 ) , V_251 ) ;
F_147 ( V_293 -> V_104 , F_143 ( V_74 ) ) ;
V_293 -> V_104 = NULL ;
}
V_294 = sizeof( struct V_77 ) * V_74 -> V_94 ;
memset ( V_74 -> V_78 , 0 , V_294 ) ;
memset ( V_74 -> V_93 , 0 , V_74 -> V_294 ) ;
V_74 -> V_255 = 0 ;
V_74 -> V_85 = 0 ;
V_74 -> V_86 = 0 ;
}
static void F_374 ( struct V_665 * V_666 ,
struct V_64 * V_74 )
{
struct V_1 * V_2 = V_666 -> V_155 ;
int V_113 = V_74 -> V_92 + V_666 -> V_668 ;
F_283 ( V_2 , V_74 ) ;
F_259 ( 10000 , 20000 ) ;
F_225 ( V_2 , F_242 ( V_113 ) ) ;
F_372 ( V_74 ) ;
V_74 -> V_154 = NULL ;
}
static int F_375 ( struct V_61 * V_669 ,
struct V_665 * V_670 )
{
struct V_1 * V_2 = V_670 -> V_155 ;
unsigned int V_671 = V_670 -> V_668 ;
unsigned int V_672 = V_670 -> V_673 ;
int V_49 ;
F_376 ( V_669 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_667 ; V_49 ++ ) {
F_374 ( V_670 , V_2 -> V_74 [ V_671 + V_49 ] ) ;
V_2 -> V_74 [ V_671 + V_49 ] -> V_62 = V_2 -> V_62 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_667 ; V_49 ++ ) {
V_2 -> V_65 [ V_672 + V_49 ] -> V_154 = NULL ;
V_2 -> V_65 [ V_672 + V_49 ] -> V_62 = V_2 -> V_62 ;
}
return 0 ;
}
static int F_377 ( struct V_61 * V_669 ,
struct V_665 * V_670 )
{
struct V_1 * V_2 = V_670 -> V_155 ;
unsigned int V_671 , V_672 , V_379 ;
int V_49 , V_674 , V_17 = 0 ;
if ( ! F_14 ( V_670 -> V_497 , & V_2 -> V_675 ) )
return 0 ;
V_674 = V_670 -> V_497 * V_2 -> V_667 ;
F_378 ( V_669 , L_91 ,
V_670 -> V_497 , V_2 -> V_676 ,
V_674 , V_674 + V_2 -> V_667 ,
V_2 -> V_675 ) ;
V_670 -> V_62 = V_669 ;
V_670 -> V_668 = V_671 = V_674 ;
V_670 -> V_673 = V_672 = V_674 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_667 ; V_49 ++ )
F_374 ( V_670 , V_2 -> V_74 [ V_671 + V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_667 ; V_49 ++ ) {
V_2 -> V_74 [ V_671 + V_49 ] -> V_62 = V_669 ;
V_2 -> V_74 [ V_671 + V_49 ] -> V_154 = V_670 ;
F_284 ( V_2 , V_2 -> V_74 [ V_671 + V_49 ] ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_667 ; V_49 ++ ) {
V_2 -> V_65 [ V_672 + V_49 ] -> V_62 = V_669 ;
V_2 -> V_65 [ V_672 + V_49 ] -> V_154 = V_670 ;
}
V_379 = F_333 (unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues) ;
V_17 = F_379 ( V_669 , V_379 ) ;
if ( V_17 )
goto V_677;
V_17 = F_380 ( V_669 , V_379 ) ;
if ( V_17 )
goto V_677;
if ( F_381 ( V_669 -> V_678 ) )
F_323 ( V_2 , V_669 -> V_678 , V_670 -> V_497 ) ;
F_371 ( V_670 ) ;
F_370 ( V_669 , V_670 -> V_497 , V_2 ) ;
return V_17 ;
V_677:
F_375 ( V_669 , V_670 ) ;
return V_17 ;
}
static void F_382 ( struct V_1 * V_2 )
{
struct V_61 * V_101 ;
struct V_679 * V_680 ;
int V_17 ;
F_383 (adapter->netdev, upper, iter) {
if ( F_384 ( V_101 ) ) {
struct V_681 * V_682 = F_93 ( V_101 ) ;
struct V_665 * V_666 = V_682 -> V_683 ;
if ( V_682 -> V_683 ) {
V_17 = F_377 ( V_101 , V_666 ) ;
if ( V_17 )
continue;
}
}
}
}
static void F_385 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
F_362 ( V_2 ) ;
#ifdef F_386
F_345 ( V_2 ) ;
#endif
F_289 ( V_2 ) ;
F_335 ( V_2 -> V_62 ) ;
F_312 ( V_2 ) ;
switch ( V_14 -> V_114 . type ) {
case V_117 :
case V_118 :
V_14 -> V_114 . V_355 . V_684 ( V_14 ) ;
break;
default:
break;
}
if ( V_2 -> V_146 & V_387 ) {
F_387 ( & V_2 -> V_14 ,
V_2 -> V_652 ) ;
} else if ( V_2 -> V_146 & V_651 ) {
F_388 ( & V_2 -> V_14 ,
V_2 -> V_652 ) ;
F_363 ( V_2 ) ;
}
switch ( V_14 -> V_114 . type ) {
case V_117 :
case V_118 :
V_14 -> V_114 . V_355 . V_685 ( V_14 ) ;
break;
default:
break;
}
#ifdef F_238
if ( V_2 -> V_146 & V_210 )
F_128 ( V_2 ) ;
#endif
#ifdef F_181
F_389 ( V_2 ) ;
#endif
F_263 ( V_2 ) ;
F_299 ( V_2 ) ;
F_382 ( V_2 ) ;
}
static void F_390 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_114 . type == V_115 )
V_2 -> V_349 |= V_686 ;
V_2 -> V_349 |= V_370 ;
V_2 -> V_371 = 0 ;
}
static int F_391 ( struct V_15 * V_14 )
{
T_1 V_20 ;
bool V_687 , V_357 = false ;
int V_600 = V_688 ;
if ( V_14 -> V_114 . V_355 . V_356 )
V_600 = V_14 -> V_114 . V_355 . V_356 ( V_14 , & V_20 , & V_357 , false ) ;
if ( V_600 )
return V_600 ;
V_20 = V_14 -> V_46 . V_689 ;
if ( ( ! V_20 ) && ( V_14 -> V_114 . V_355 . V_690 ) )
V_600 = V_14 -> V_114 . V_355 . V_690 ( V_14 , & V_20 ,
& V_687 ) ;
if ( V_600 )
return V_600 ;
if ( V_14 -> V_114 . V_355 . V_691 )
V_600 = V_14 -> V_114 . V_355 . V_691 ( V_14 , V_20 , V_357 ) ;
return V_600 ;
}
static void F_392 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_692 = 0 ;
if ( V_2 -> V_146 & V_413 ) {
V_692 = V_693 | V_694 |
V_695 ;
V_692 |= V_696 ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
F_75 ( V_14 , V_697 , V_698 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
default:
F_75 ( V_14 , F_393 ( 0 ) , 0xFFFFFFFF ) ;
F_75 ( V_14 , F_393 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_75 ( V_14 , V_697 , V_698 ) ;
}
if ( V_2 -> V_146 & V_433 ) {
V_692 &= ~ V_699 ;
switch ( V_2 -> V_438 [ V_439 ] . V_124 ) {
case V_518 :
V_692 |= V_700 ;
break;
case V_440 :
V_692 |= V_701 ;
break;
default:
V_692 |= V_702 ;
break;
}
}
if ( V_2 -> V_349 & V_350 ) {
switch ( V_2 -> V_14 . V_114 . type ) {
case V_117 :
V_692 |= V_703 ;
break;
default:
break;
}
}
if ( V_2 -> V_146 & V_361 )
V_692 |= F_394 ( V_14 ) ;
switch ( V_14 -> V_114 . type ) {
case V_117 :
V_692 |= V_704 | V_705 ;
break;
case V_120 :
case V_121 :
V_692 |= V_706 ;
break;
default:
break;
}
F_75 ( V_14 , V_707 , V_692 ) ;
}
static void F_395 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 ;
T_1 V_106 ;
F_76 ( V_2 ) ;
F_392 ( V_2 ) ;
if ( V_2 -> V_146 & V_413 )
F_205 ( V_2 ) ;
else
F_255 ( V_2 ) ;
if ( V_14 -> V_114 . V_355 . V_708 )
V_14 -> V_114 . V_355 . V_708 ( V_14 ) ;
if ( V_14 -> V_46 . V_355 . V_709 )
V_14 -> V_46 . V_355 . V_709 ( V_14 , true ) ;
F_36 () ;
F_37 ( V_34 , & V_2 -> V_35 ) ;
F_338 ( V_2 ) ;
if ( F_218 ( V_14 ) ) {
F_390 ( V_2 ) ;
} else {
V_17 = F_391 ( V_14 ) ;
if ( V_17 )
F_108 ( V_187 , L_92 , V_17 ) ;
}
F_40 ( V_14 , V_362 ) ;
F_227 ( V_2 , true , true ) ;
if ( V_2 -> V_146 & V_361 ) {
T_1 V_710 = F_40 ( V_14 , V_711 ) ;
if ( V_710 & V_712 )
F_214 ( V_162 , L_72 ) ;
}
V_2 -> V_146 |= V_374 ;
V_2 -> V_375 = V_186 ;
F_396 ( & V_2 -> V_713 , V_186 ) ;
V_106 = F_40 ( V_14 , V_107 ) ;
V_106 |= V_714 ;
F_75 ( V_14 , V_107 , V_106 ) ;
}
void F_397 ( struct V_1 * V_2 )
{
F_398 ( F_399 () ) ;
F_400 ( V_2 -> V_62 ) ;
while ( F_15 ( V_715 , & V_2 -> V_35 ) )
F_259 ( 1000 , 2000 ) ;
F_401 ( V_2 ) ;
if ( V_2 -> V_146 & V_433 )
F_402 ( 2000 ) ;
F_403 ( V_2 ) ;
F_37 ( V_715 , & V_2 -> V_35 ) ;
}
void F_403 ( struct V_1 * V_2 )
{
F_385 ( V_2 ) ;
F_395 ( V_2 ) ;
}
void F_404 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_61 * V_62 = V_2 -> V_62 ;
int V_17 ;
if ( F_22 ( V_14 -> V_41 ) )
return;
while ( F_15 ( V_716 , & V_2 -> V_35 ) )
F_259 ( 1000 , 2000 ) ;
V_2 -> V_349 &= ~ ( V_686 |
V_370 ) ;
V_2 -> V_146 &= ~ V_372 ;
V_17 = V_14 -> V_114 . V_355 . V_717 ( V_14 ) ;
switch ( V_17 ) {
case 0 :
case V_718 :
case V_719 :
break;
case V_720 :
F_18 ( L_93 ) ;
break;
case V_721 :
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
F_37 ( V_716 , & V_2 -> V_35 ) ;
F_320 ( V_2 ) ;
F_405 ( V_62 , NULL ) ;
F_322 ( V_2 ) ;
if ( V_14 -> V_114 . V_722 )
V_14 -> V_114 . V_355 . V_723 ( V_14 , F_288 ( 0 ) ) ;
if ( F_14 ( V_724 , & V_2 -> V_35 ) )
F_406 ( V_2 ) ;
if ( V_14 -> V_46 . V_355 . V_709 ) {
if ( ! F_61 ( V_2 -> V_62 ) && ! V_2 -> V_725 )
V_14 -> V_46 . V_355 . V_709 ( V_14 , false ) ;
else
V_14 -> V_46 . V_355 . V_709 ( V_14 , true ) ;
}
}
static void F_407 ( struct V_64 * V_65 )
{
struct V_66 * V_84 ;
unsigned long V_294 ;
T_2 V_49 ;
if ( ! V_65 -> V_84 )
return;
for ( V_49 = 0 ; V_49 < V_65 -> V_94 ; V_49 ++ ) {
V_84 = & V_65 -> V_84 [ V_49 ] ;
F_81 ( V_65 , V_84 ) ;
}
F_408 ( F_112 ( V_65 ) ) ;
V_294 = sizeof( struct V_66 ) * V_65 -> V_94 ;
memset ( V_65 -> V_84 , 0 , V_294 ) ;
memset ( V_65 -> V_93 , 0 , V_65 -> V_294 ) ;
V_65 -> V_86 = 0 ;
V_65 -> V_85 = 0 ;
}
static void F_409 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ )
F_372 ( V_2 -> V_74 [ V_49 ] ) ;
}
static void F_410 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ )
F_407 ( V_2 -> V_65 [ V_49 ] ) ;
}
static void F_411 ( struct V_1 * V_2 )
{
struct V_655 * V_656 ;
struct V_657 * V_658 ;
F_364 ( & V_2 -> V_659 ) ;
F_367 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_412 ( & V_658 -> V_726 ) ;
F_249 ( V_658 ) ;
}
V_2 -> V_727 = 0 ;
F_369 ( & V_2 -> V_659 ) ;
}
void F_401 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_61 * V_101 ;
struct V_679 * V_680 ;
int V_49 ;
if ( F_15 ( V_34 , & V_2 -> V_35 ) )
return;
V_14 -> V_114 . V_355 . V_551 ( V_14 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ )
F_283 ( V_2 , V_2 -> V_74 [ V_49 ] ) ;
F_259 ( 10000 , 20000 ) ;
F_376 ( V_62 ) ;
F_413 ( V_62 ) ;
F_414 ( V_62 ) ;
F_383 (adapter->netdev, upper, iter) {
if ( F_384 ( V_101 ) ) {
struct V_681 * V_267 = F_93 ( V_101 ) ;
if ( V_267 -> V_683 ) {
F_376 ( V_101 ) ;
F_413 ( V_101 ) ;
F_414 ( V_101 ) ;
}
}
}
F_253 ( V_2 ) ;
F_341 ( V_2 ) ;
F_37 ( V_161 , & V_2 -> V_35 ) ;
V_2 -> V_349 &= ~ V_388 ;
V_2 -> V_146 &= ~ V_374 ;
F_415 ( & V_2 -> V_713 ) ;
if ( V_2 -> V_321 ) {
F_75 ( & V_2 -> V_14 , V_323 , 0 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_321 ; V_49 ++ )
V_2 -> V_523 [ V_49 ] . V_728 = false ;
F_416 ( V_2 ) ;
F_417 ( V_2 ) ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ ) {
T_4 V_156 = V_2 -> V_65 [ V_49 ] -> V_156 ;
F_75 ( V_14 , F_53 ( V_156 ) , V_729 ) ;
}
switch ( V_14 -> V_114 . type ) {
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
F_75 ( V_14 , V_449 ,
( F_40 ( V_14 , V_449 ) &
~ V_450 ) ) ;
break;
default:
break;
}
if ( ! F_418 ( V_2 -> V_9 ) )
F_404 ( V_2 ) ;
if ( V_14 -> V_114 . V_355 . V_730 )
V_14 -> V_114 . V_355 . V_730 ( V_14 ) ;
F_410 ( V_2 ) ;
F_409 ( V_2 ) ;
}
static void F_419 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
F_96 ( V_2 ) ;
}
static void F_420 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_731 * V_141 ;
int V_56 ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
case V_117 :
V_2 -> V_143 . V_732 . V_733 = V_649 ;
V_2 -> V_143 . V_732 . V_734 = V_649 ;
break;
case V_118 :
case V_119 :
V_2 -> V_143 . V_732 . V_733 = V_735 ;
V_2 -> V_143 . V_732 . V_734 = V_735 ;
break;
case V_120 :
case V_121 :
default:
V_2 -> V_143 . V_732 . V_733 = V_736 ;
V_2 -> V_143 . V_732 . V_734 = V_736 ;
break;
}
for ( V_56 = 0 ; V_56 < V_649 ; V_56 ++ ) {
V_141 = & V_2 -> V_143 . V_737 [ V_56 ] ;
V_141 -> V_738 [ V_632 ] . V_739 = 0 ;
V_141 -> V_738 [ V_632 ] . V_740 = 12 + ( V_56 & 1 ) ;
V_141 -> V_738 [ V_633 ] . V_739 = 0 ;
V_141 -> V_738 [ V_633 ] . V_740 = 12 + ( V_56 & 1 ) ;
V_141 -> V_741 = V_742 ;
}
V_141 = & V_2 -> V_143 . V_737 [ 0 ] ;
V_141 -> V_738 [ V_632 ] . V_743 = 0xFF ;
V_141 -> V_738 [ V_633 ] . V_743 = 0xFF ;
V_2 -> V_143 . V_744 [ V_632 ] [ 0 ] = 100 ;
V_2 -> V_143 . V_744 [ V_633 ] [ 0 ] = 100 ;
V_2 -> V_143 . V_144 = false ;
V_2 -> V_745 = 0x00 ;
if ( V_2 -> V_146 & V_746 )
V_2 -> V_630 = V_747 | V_631 ;
memcpy ( & V_2 -> V_748 , & V_2 -> V_143 ,
sizeof( V_2 -> V_748 ) ) ;
}
static int F_421 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_223 , V_749 ;
T_1 V_750 ;
int V_49 ;
V_14 -> V_751 = V_9 -> V_752 ;
V_14 -> V_21 = V_9 -> V_208 ;
V_14 -> V_753 = V_9 -> V_754 ;
V_14 -> V_755 = V_9 -> V_756 ;
V_14 -> V_757 = V_9 -> V_758 ;
V_223 = F_333 ( int , F_422 ( V_2 ) , F_423 () ) ;
V_2 -> V_438 [ V_453 ] . V_759 = V_223 ;
V_2 -> V_349 |= V_760 ;
V_2 -> V_761 = V_762 ;
V_2 -> V_423 = 20 ;
V_749 = F_333 ( int , V_763 , F_423 () ) ;
V_2 -> V_438 [ V_764 ] . V_759 = V_749 ;
V_2 -> V_652 = V_765 ;
#ifdef F_238
V_2 -> V_146 |= V_210 ;
#endif
#ifdef F_386
V_2 -> V_146 |= V_746 ;
V_2 -> V_146 &= ~ V_147 ;
#endif
#ifdef F_181
V_2 -> V_146 |= V_766 ;
V_2 -> V_146 &= ~ V_531 ;
#ifdef F_386
V_2 -> V_644 . V_645 = V_767 ;
#endif
#endif
V_2 -> V_768 [ 0 ] = F_424 ( sizeof( * V_2 -> V_768 [ 0 ] ) ,
V_769 ) ;
if ( ! V_2 -> V_768 [ 0 ] )
return - V_584 ;
V_2 -> V_768 [ 0 ] -> V_770 = V_771 ;
for ( V_49 = 1 ; V_49 < V_772 ; V_49 ++ )
V_2 -> V_768 [ V_49 ] = NULL ;
V_2 -> V_586 = F_424 ( sizeof( struct V_585 ) *
V_14 -> V_114 . V_587 ,
V_773 ) ;
if ( ! V_2 -> V_586 )
return - V_584 ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_2 -> V_349 &= ~ V_760 ;
if ( V_14 -> V_21 == V_774 )
V_2 -> V_146 |= V_361 ;
V_2 -> V_761 = V_775 ;
V_2 -> V_438 [ V_764 ] . V_759 = 0 ;
V_2 -> V_423 = 0 ;
V_2 -> V_652 = 0 ;
#ifdef F_181
V_2 -> V_146 &= ~ V_766 ;
V_2 -> V_146 &= ~ V_531 ;
#ifdef F_386
V_2 -> V_644 . V_645 = 0 ;
#endif
#endif
break;
case V_117 :
if ( V_14 -> V_21 == V_352 )
V_2 -> V_349 |= V_350 ;
break;
case V_118 :
V_750 = F_40 ( V_14 , F_425 ( V_14 ) ) ;
if ( V_750 & V_776 )
V_2 -> V_349 |= V_350 ;
break;
case V_121 :
V_2 -> V_146 |= V_623 ;
case V_120 :
#ifdef F_386
V_2 -> V_146 &= ~ V_746 ;
#endif
#ifdef F_181
V_2 -> V_146 &= ~ V_766 ;
#ifdef F_386
V_2 -> V_644 . V_645 = 0 ;
#endif
#endif
case V_119 :
#ifdef F_238
V_2 -> V_146 &= ~ V_210 ;
#endif
V_2 -> V_146 |= V_622 ;
break;
default:
break;
}
#ifdef F_181
F_426 ( & V_2 -> V_644 . V_777 ) ;
#endif
F_426 ( & V_2 -> V_659 ) ;
#ifdef F_386
F_420 ( V_2 ) ;
#endif
V_14 -> V_132 . V_778 = V_134 ;
V_14 -> V_132 . V_133 = V_134 ;
F_361 ( V_2 ) ;
V_14 -> V_132 . V_779 = V_780 ;
V_14 -> V_132 . V_781 = true ;
V_14 -> V_132 . V_782 = F_427 ( V_14 ) ;
#ifdef F_315
if ( V_783 > 0 )
F_11 ( L_101 ) ;
if ( V_14 -> V_114 . type != V_115 ) {
if ( V_783 > V_784 ) {
V_2 -> V_321 = 0 ;
F_11 ( L_102 ) ;
} else {
V_2 -> V_321 = V_783 ;
}
}
#endif
V_2 -> V_404 = 1 ;
V_2 -> V_785 = 1 ;
V_2 -> V_786 = V_787 ;
V_2 -> V_788 = V_789 ;
V_2 -> V_790 = V_791 ;
if ( F_428 ( V_14 ) ) {
F_18 ( L_103 ) ;
return - V_792 ;
}
F_97 ( 0 , & V_2 -> V_675 ) ;
F_97 ( V_34 , & V_2 -> V_35 ) ;
return 0 ;
}
int F_429 ( struct V_64 * V_65 )
{
struct V_208 * V_80 = V_65 -> V_80 ;
int V_793 = F_430 ( V_80 ) ;
int V_794 = - 1 ;
int V_294 ;
V_294 = sizeof( struct V_66 ) * V_65 -> V_94 ;
if ( V_65 -> V_172 )
V_794 = V_65 -> V_172 -> V_795 ;
V_65 -> V_84 = F_431 ( V_294 , V_794 ) ;
if ( ! V_65 -> V_84 )
V_65 -> V_84 = F_432 ( V_294 ) ;
if ( ! V_65 -> V_84 )
goto V_17;
F_433 ( & V_65 -> V_184 ) ;
V_65 -> V_294 = V_65 -> V_94 * sizeof( union V_68 ) ;
V_65 -> V_294 = F_175 ( V_65 -> V_294 , 4096 ) ;
F_434 ( V_80 , V_794 ) ;
V_65 -> V_93 = F_435 ( V_80 ,
V_65 -> V_294 ,
& V_65 -> V_87 ,
V_769 ) ;
F_434 ( V_80 , V_793 ) ;
if ( ! V_65 -> V_93 )
V_65 -> V_93 = F_435 ( V_80 , V_65 -> V_294 ,
& V_65 -> V_87 , V_769 ) ;
if ( ! V_65 -> V_93 )
goto V_17;
V_65 -> V_86 = 0 ;
V_65 -> V_85 = 0 ;
return 0 ;
V_17:
F_436 ( V_65 -> V_84 ) ;
V_65 -> V_84 = NULL ;
F_437 ( V_80 , L_104 ) ;
return - V_584 ;
}
static int F_438 ( struct V_1 * V_2 )
{
int V_49 , V_17 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ ) {
V_17 = F_429 ( V_2 -> V_65 [ V_49 ] ) ;
if ( ! V_17 )
continue;
F_108 ( V_187 , L_105 , V_49 ) ;
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
struct V_208 * V_80 = V_74 -> V_80 ;
int V_793 = F_430 ( V_80 ) ;
int V_794 = - 1 ;
int V_294 ;
V_294 = sizeof( struct V_77 ) * V_74 -> V_94 ;
if ( V_74 -> V_172 )
V_794 = V_74 -> V_172 -> V_795 ;
V_74 -> V_78 = F_431 ( V_294 , V_794 ) ;
if ( ! V_74 -> V_78 )
V_74 -> V_78 = F_432 ( V_294 ) ;
if ( ! V_74 -> V_78 )
goto V_17;
F_433 ( & V_74 -> V_184 ) ;
V_74 -> V_294 = V_74 -> V_94 * sizeof( union V_75 ) ;
V_74 -> V_294 = F_175 ( V_74 -> V_294 , 4096 ) ;
F_434 ( V_80 , V_794 ) ;
V_74 -> V_93 = F_435 ( V_80 ,
V_74 -> V_294 ,
& V_74 -> V_87 ,
V_769 ) ;
F_434 ( V_80 , V_793 ) ;
if ( ! V_74 -> V_93 )
V_74 -> V_93 = F_435 ( V_80 , V_74 -> V_294 ,
& V_74 -> V_87 , V_769 ) ;
if ( ! V_74 -> V_93 )
goto V_17;
V_74 -> V_85 = 0 ;
V_74 -> V_86 = 0 ;
return 0 ;
V_17:
F_436 ( V_74 -> V_78 ) ;
V_74 -> V_78 = NULL ;
F_437 ( V_80 , L_106 ) ;
return - V_584 ;
}
static int F_441 ( struct V_1 * V_2 )
{
int V_49 , V_17 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ ) {
V_17 = F_440 ( V_2 -> V_74 [ V_49 ] ) ;
if ( ! V_17 )
continue;
F_108 ( V_187 , L_107 , V_49 ) ;
goto V_797;
}
#ifdef F_181
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
F_407 ( V_65 ) ;
F_436 ( V_65 -> V_84 ) ;
V_65 -> V_84 = NULL ;
if ( ! V_65 -> V_93 )
return;
F_444 ( V_65 -> V_80 , V_65 -> V_294 ,
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
F_372 ( V_74 ) ;
F_436 ( V_74 -> V_78 ) ;
V_74 -> V_78 = NULL ;
if ( ! V_74 -> V_93 )
return;
F_444 ( V_74 -> V_80 , V_74 -> V_294 ,
V_74 -> V_93 , V_74 -> V_87 ) ;
V_74 -> V_93 = NULL ;
}
static void F_446 ( struct V_1 * V_2 )
{
int V_49 ;
#ifdef F_181
F_447 ( V_2 ) ;
#endif
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ )
if ( V_2 -> V_74 [ V_49 ] -> V_93 )
F_443 ( V_2 -> V_74 [ V_49 ] ) ;
}
static int F_448 ( struct V_61 * V_62 , int V_798 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
int V_526 = V_798 + V_527 + V_528 ;
if ( ( V_798 < 68 ) || ( V_526 > V_799 ) )
return - V_596 ;
if ( ( V_2 -> V_146 & V_433 ) &&
( V_2 -> V_14 . V_114 . type == V_117 ) &&
( V_526 > ( V_533 + V_528 ) ) )
F_27 ( V_187 , L_108 ) ;
F_110 ( V_187 , L_109 , V_62 -> V_309 , V_798 ) ;
V_62 -> V_309 = V_798 ;
if ( F_61 ( V_62 ) )
F_397 ( V_2 ) ;
return 0 ;
}
int F_449 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 , V_379 ;
if ( F_14 ( V_800 , & V_2 -> V_35 ) )
return - V_801 ;
F_413 ( V_62 ) ;
V_17 = F_438 ( V_2 ) ;
if ( V_17 )
goto V_796;
V_17 = F_441 ( V_2 ) ;
if ( V_17 )
goto V_797;
F_385 ( V_2 ) ;
V_17 = F_251 ( V_2 ) ;
if ( V_17 )
goto V_802;
if ( V_2 -> V_676 > 1 )
V_379 = V_2 -> V_667 ;
else
V_379 = V_2 -> V_83 ;
V_17 = F_379 ( V_62 , V_379 ) ;
if ( V_17 )
goto V_803;
if ( V_2 -> V_676 > 1 &&
V_2 -> V_99 > V_804 )
V_379 = V_804 ;
else
V_379 = V_2 -> V_99 ;
V_17 = F_380 ( V_62 , V_379 ) ;
if ( V_17 )
goto V_803;
F_450 ( V_2 ) ;
F_395 ( V_2 ) ;
F_344 ( V_2 , V_805 ) ;
F_451 ( V_62 ) ;
return 0 ;
V_803:
F_252 ( V_2 ) ;
V_802:
F_446 ( V_2 ) ;
if ( V_14 -> V_46 . V_355 . V_709 && ! V_2 -> V_725 )
V_14 -> V_46 . V_355 . V_709 ( & V_2 -> V_14 , false ) ;
V_797:
F_445 ( V_2 ) ;
V_796:
F_404 ( V_2 ) ;
return V_17 ;
}
static void F_452 ( struct V_1 * V_2 )
{
F_453 ( V_2 ) ;
if ( V_2 -> V_14 . V_46 . V_355 . V_806 ) {
V_2 -> V_14 . V_46 . V_807 = true ;
F_401 ( V_2 ) ;
V_2 -> V_14 . V_46 . V_355 . V_806 ( & V_2 -> V_14 ) ;
V_2 -> V_14 . V_46 . V_807 = false ;
} else {
F_401 ( V_2 ) ;
}
F_252 ( V_2 ) ;
F_445 ( V_2 ) ;
F_446 ( V_2 ) ;
}
int F_454 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
F_455 ( V_2 ) ;
F_452 ( V_2 ) ;
F_411 ( V_2 ) ;
F_74 ( V_2 ) ;
return 0 ;
}
static int F_456 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_457 ( V_9 ) ;
struct V_61 * V_62 = V_2 -> V_62 ;
T_1 V_17 ;
V_2 -> V_14 . V_41 = V_2 -> V_422 ;
F_458 ( V_9 , V_808 ) ;
F_459 ( V_9 ) ;
F_460 ( V_9 ) ;
V_17 = F_461 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_110 ) ;
return V_17 ;
}
F_36 () ;
F_37 ( V_809 , & V_2 -> V_35 ) ;
F_462 ( V_9 ) ;
F_463 ( V_9 , false ) ;
F_404 ( V_2 ) ;
F_75 ( & V_2 -> V_14 , V_810 , ~ 0 ) ;
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
static int F_468 ( struct V_5 * V_9 , bool * V_811 )
{
struct V_1 * V_2 = F_457 ( V_9 ) ;
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_812 , V_601 ;
T_1 V_813 = V_2 -> V_725 ;
#ifdef F_469
int V_814 = 0 ;
#endif
F_470 ( V_62 ) ;
F_464 () ;
if ( F_61 ( V_62 ) )
F_452 ( V_2 ) ;
F_466 () ;
F_471 ( V_2 ) ;
#ifdef F_469
V_814 = F_460 ( V_9 ) ;
if ( V_814 )
return V_814 ;
#endif
if ( V_14 -> V_114 . V_355 . V_815 )
V_14 -> V_114 . V_355 . V_815 ( V_14 ) ;
if ( V_813 ) {
F_335 ( V_62 ) ;
if ( V_14 -> V_114 . V_355 . V_708 )
V_14 -> V_114 . V_355 . V_708 ( V_14 ) ;
if ( V_813 & V_816 ) {
V_601 = F_40 ( V_14 , V_605 ) ;
V_601 |= V_611 ;
F_75 ( V_14 , V_605 , V_601 ) ;
}
V_812 = F_40 ( V_14 , V_817 ) ;
V_812 |= V_818 ;
F_75 ( V_14 , V_817 , V_812 ) ;
F_75 ( V_14 , V_819 , V_813 ) ;
} else {
F_75 ( V_14 , V_820 , 0 ) ;
F_75 ( V_14 , V_819 , 0 ) ;
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
F_463 ( V_9 , ! ! V_813 ) ;
break;
default:
break;
}
* V_811 = ! ! V_813 ;
if ( V_14 -> V_46 . V_355 . V_709 && ! * V_811 )
V_14 -> V_46 . V_355 . V_709 ( V_14 , false ) ;
F_74 ( V_2 ) ;
if ( ! F_15 ( V_809 , & V_2 -> V_35 ) )
F_472 ( V_9 ) ;
return 0 ;
}
static int F_473 ( struct V_5 * V_9 , T_14 V_35 )
{
int V_814 ;
bool V_821 ;
V_814 = F_468 ( V_9 , & V_821 ) ;
if ( V_814 )
return V_814 ;
if ( V_821 ) {
F_474 ( V_9 ) ;
} else {
F_463 ( V_9 , false ) ;
F_458 ( V_9 , V_822 ) ;
}
return 0 ;
}
static void F_475 ( struct V_5 * V_9 )
{
bool V_821 ;
F_468 ( V_9 , & V_821 ) ;
if ( V_823 == V_824 ) {
F_463 ( V_9 , V_821 ) ;
F_458 ( V_9 , V_822 ) ;
}
}
void F_476 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_129 * V_130 = & V_2 -> V_131 ;
T_6 V_825 = 0 ;
T_1 V_49 , V_826 = 0 , V_827 , V_828 , V_829 , V_830 , V_831 ;
T_6 V_279 = 0 , V_189 = 0 , V_832 = 0 ;
T_6 V_250 = 0 , V_302 = 0 ;
T_6 V_185 = 0 , V_151 = 0 , V_833 = 0 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_715 , & V_2 -> V_35 ) )
return;
if ( V_2 -> V_349 & V_539 ) {
T_6 V_261 = 0 ;
T_6 V_262 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ ) {
V_261 += V_2 -> V_74 [ V_49 ] -> V_237 . V_261 ;
V_262 += V_2 -> V_74 [ V_49 ] -> V_237 . V_262 ;
}
V_2 -> V_834 = V_261 ;
V_2 -> V_835 = V_262 ;
}
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ ) {
struct V_64 * V_74 = V_2 -> V_74 [ V_49 ] ;
V_279 += V_74 -> V_237 . V_279 ;
V_250 += V_74 -> V_237 . V_250 ;
V_302 += V_74 -> V_237 . V_302 ;
V_833 += V_74 -> V_237 . V_238 ;
V_185 += V_74 -> V_131 . V_185 ;
V_151 += V_74 -> V_131 . V_151 ;
}
V_2 -> V_279 = V_279 ;
V_2 -> V_250 = V_250 ;
V_2 -> V_302 = V_302 ;
V_2 -> V_833 = V_833 ;
V_62 -> V_131 . V_836 = V_185 ;
V_62 -> V_131 . V_837 = V_151 ;
V_185 = 0 ;
V_151 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ ) {
struct V_64 * V_65 = V_2 -> V_65 [ V_49 ] ;
V_189 += V_65 -> V_159 . V_189 ;
V_832 += V_65 -> V_159 . V_832 ;
V_185 += V_65 -> V_131 . V_185 ;
V_151 += V_65 -> V_131 . V_151 ;
}
V_2 -> V_189 = V_189 ;
V_2 -> V_832 = V_832 ;
V_62 -> V_131 . V_838 = V_185 ;
V_62 -> V_131 . V_839 = V_151 ;
V_130 -> V_840 += F_40 ( V_14 , V_841 ) ;
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
V_827 = F_40 ( V_14 , F_477 ( V_49 ) ) ;
V_826 += V_827 ;
V_130 -> V_827 [ V_49 ] += V_827 ;
V_825 += V_130 -> V_827 [ V_49 ] ;
V_130 -> V_842 [ V_49 ] += F_40 ( V_14 , F_478 ( V_49 ) ) ;
V_130 -> V_843 [ V_49 ] += F_40 ( V_14 , F_479 ( V_49 ) ) ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_130 -> V_844 [ V_49 ] += F_40 ( V_14 , F_480 ( V_49 ) ) ;
V_130 -> V_845 [ V_49 ] += F_40 ( V_14 , F_481 ( V_49 ) ) ;
V_130 -> V_846 [ V_49 ] += F_40 ( V_14 , F_482 ( V_49 ) ) ;
V_130 -> V_847 [ V_49 ] +=
F_40 ( V_14 , F_483 ( V_49 ) ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_130 -> V_847 [ V_49 ] +=
F_40 ( V_14 , F_484 ( V_49 ) ) ;
break;
default:
break;
}
}
for ( V_49 = 0 ; V_49 < 16 ; V_49 ++ ) {
V_130 -> V_848 [ V_49 ] += F_40 ( V_14 , F_485 ( V_49 ) ) ;
V_130 -> V_849 [ V_49 ] += F_40 ( V_14 , F_486 ( V_49 ) ) ;
if ( ( V_14 -> V_114 . type == V_117 ) ||
( V_14 -> V_114 . type == V_118 ) ||
( V_14 -> V_114 . type == V_119 ) ||
( V_14 -> V_114 . type == V_120 ) ||
( V_14 -> V_114 . type == V_121 ) ) {
V_130 -> V_845 [ V_49 ] += F_40 ( V_14 , F_487 ( V_49 ) ) ;
F_40 ( V_14 , F_488 ( V_49 ) ) ;
V_130 -> V_846 [ V_49 ] += F_40 ( V_14 , F_489 ( V_49 ) ) ;
F_40 ( V_14 , F_490 ( V_49 ) ) ;
}
}
V_130 -> V_850 += F_40 ( V_14 , V_851 ) ;
V_130 -> V_850 -= V_826 ;
F_87 ( V_2 ) ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_130 -> V_852 += F_40 ( V_14 , V_853 ) ;
V_130 -> V_854 += F_40 ( V_14 , V_855 ) ;
V_130 -> V_856 += F_40 ( V_14 , V_857 ) ;
V_130 -> V_858 += F_40 ( V_14 , V_859 ) ;
break;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_130 -> V_860 += F_40 ( V_14 , V_861 ) ;
V_130 -> V_862 += F_40 ( V_14 , V_863 ) ;
V_130 -> V_864 += F_40 ( V_14 , V_865 ) ;
V_130 -> V_866 += F_40 ( V_14 , V_867 ) ;
case V_117 :
for ( V_49 = 0 ; V_49 < 16 ; V_49 ++ )
V_2 -> V_868 +=
F_40 ( V_14 , F_491 ( V_49 ) ) ;
V_130 -> V_854 += F_40 ( V_14 , V_869 ) ;
F_40 ( V_14 , V_855 ) ;
V_130 -> V_856 += F_40 ( V_14 , V_870 ) ;
F_40 ( V_14 , V_857 ) ;
V_130 -> V_858 += F_40 ( V_14 , V_871 ) ;
F_40 ( V_14 , V_859 ) ;
V_130 -> V_852 += F_40 ( V_14 , V_872 ) ;
V_130 -> V_873 += F_40 ( V_14 , V_874 ) ;
V_130 -> V_875 += F_40 ( V_14 , V_876 ) ;
#ifdef F_181
V_130 -> V_877 += F_40 ( V_14 , V_878 ) ;
V_130 -> V_879 += F_40 ( V_14 , V_880 ) ;
V_130 -> V_881 += F_40 ( V_14 , V_882 ) ;
V_130 -> V_883 += F_40 ( V_14 , V_884 ) ;
V_130 -> V_885 += F_40 ( V_14 , V_886 ) ;
V_130 -> V_887 += F_40 ( V_14 , V_888 ) ;
if ( V_2 -> V_644 . V_889 ) {
struct V_890 * V_644 = & V_2 -> V_644 ;
struct V_891 * V_889 ;
unsigned int V_190 ;
T_6 V_892 = 0 , V_893 = 0 ;
F_492 (cpu) {
V_889 = F_493 ( V_644 -> V_889 , V_190 ) ;
V_892 += V_889 -> V_892 ;
V_893 += V_889 -> V_893 ;
}
V_130 -> V_894 = V_892 ;
V_130 -> V_895 = V_893 ;
}
#endif
break;
default:
break;
}
V_828 = F_40 ( V_14 , V_896 ) ;
V_130 -> V_828 += V_828 ;
V_130 -> V_897 += F_40 ( V_14 , V_898 ) ;
if ( V_14 -> V_114 . type == V_115 )
V_130 -> V_897 -= V_828 ;
V_130 -> V_899 += F_40 ( V_14 , V_900 ) ;
V_130 -> V_901 += F_40 ( V_14 , V_902 ) ;
V_130 -> V_903 += F_40 ( V_14 , V_904 ) ;
V_130 -> V_905 += F_40 ( V_14 , V_906 ) ;
V_130 -> V_907 += F_40 ( V_14 , V_908 ) ;
V_130 -> V_909 += F_40 ( V_14 , V_910 ) ;
V_130 -> V_911 += F_40 ( V_14 , V_912 ) ;
V_130 -> V_913 += F_40 ( V_14 , V_914 ) ;
V_829 = F_40 ( V_14 , V_915 ) ;
V_130 -> V_916 += V_829 ;
V_830 = F_40 ( V_14 , V_917 ) ;
V_130 -> V_918 += V_830 ;
V_130 -> V_919 += F_40 ( V_14 , V_920 ) ;
V_130 -> V_921 += F_40 ( V_14 , V_922 ) ;
V_831 = V_829 + V_830 ;
V_130 -> V_919 -= V_831 ;
V_130 -> V_921 -= V_831 ;
V_130 -> V_856 -= ( V_831 * ( V_923 + V_528 ) ) ;
V_130 -> V_924 += F_40 ( V_14 , V_925 ) ;
V_130 -> V_926 += F_40 ( V_14 , V_927 ) ;
V_130 -> V_928 += F_40 ( V_14 , V_929 ) ;
V_130 -> V_930 += F_40 ( V_14 , V_931 ) ;
V_130 -> V_932 += F_40 ( V_14 , V_933 ) ;
V_130 -> V_932 -= V_831 ;
V_130 -> V_934 += F_40 ( V_14 , V_935 ) ;
V_130 -> V_936 += F_40 ( V_14 , V_937 ) ;
V_130 -> V_938 += F_40 ( V_14 , V_939 ) ;
V_130 -> V_940 += F_40 ( V_14 , V_941 ) ;
V_130 -> V_942 += F_40 ( V_14 , V_943 ) ;
V_130 -> V_944 += F_40 ( V_14 , V_945 ) ;
V_62 -> V_131 . V_946 = V_130 -> V_897 ;
V_62 -> V_131 . V_947 = V_130 -> V_840 + V_130 -> V_913 ;
V_62 -> V_131 . V_948 = 0 ;
V_62 -> V_131 . V_949 = V_130 -> V_913 ;
V_62 -> V_131 . V_950 = V_130 -> V_840 ;
V_62 -> V_131 . V_951 = V_825 ;
}
static void F_494 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_49 ;
if ( ! ( V_2 -> V_349 & V_388 ) )
return;
V_2 -> V_349 &= ~ V_388 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
if ( ! ( V_2 -> V_146 & V_387 ) )
return;
V_2 -> V_952 ++ ;
if ( F_495 ( V_14 ) == 0 ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ )
F_97 ( V_397 ,
& ( V_2 -> V_65 [ V_49 ] -> V_35 ) ) ;
F_75 ( V_14 , V_378 , V_389 ) ;
} else {
F_108 ( V_187 , L_111
L_112 ) ;
}
}
static void F_496 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_953 = 0 ;
int V_49 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_715 , & V_2 -> V_35 ) )
return;
if ( F_114 ( V_2 -> V_62 ) ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ )
F_497 ( V_2 -> V_65 [ V_49 ] ) ;
}
if ( ! ( V_2 -> V_146 & V_413 ) ) {
F_75 ( V_14 , V_126 ,
( V_954 | V_955 ) ) ;
} else {
for ( V_49 = 0 ; V_49 < V_2 -> V_207 ; V_49 ++ ) {
struct V_171 * V_956 = V_2 -> V_172 [ V_49 ] ;
if ( V_956 -> V_313 . V_127 || V_956 -> V_177 . V_127 )
V_953 |= F_242 ( V_49 ) ;
}
}
F_79 ( V_2 , V_953 ) ;
}
static void F_498 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_957 = V_2 -> V_957 ;
bool V_357 = V_2 -> V_357 ;
bool V_142 = V_2 -> V_143 . V_144 ;
if ( ! ( V_2 -> V_146 & V_374 ) )
return;
if ( V_14 -> V_114 . V_355 . V_356 ) {
V_14 -> V_114 . V_355 . V_356 ( V_14 , & V_957 , & V_357 , false ) ;
} else {
V_957 = V_958 ;
V_357 = true ;
}
if ( V_2 -> V_145 )
V_142 |= ! ! ( V_2 -> V_145 -> V_142 ) ;
if ( V_357 && ! ( ( V_2 -> V_146 & V_147 ) && V_142 ) ) {
V_14 -> V_114 . V_355 . V_959 ( V_14 ) ;
F_499 ( V_2 ) ;
}
if ( V_357 ||
F_500 ( V_186 , ( V_2 -> V_375 +
V_960 ) ) ) {
V_2 -> V_146 &= ~ V_374 ;
F_75 ( V_14 , V_378 , V_377 ) ;
F_222 ( V_14 ) ;
}
V_2 -> V_357 = V_357 ;
V_2 -> V_957 = V_957 ;
}
static void F_501 ( struct V_1 * V_2 )
{
#ifdef F_386
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_961 V_962 = {
. V_963 = V_964 ,
. V_269 = 0 ,
} ;
T_4 V_645 = 0 ;
if ( V_2 -> V_630 & V_965 )
V_645 = F_502 ( V_62 , & V_962 ) ;
V_2 -> V_966 = ( V_645 > 1 ) ? ( F_503 ( V_645 ) - 1 ) : 0 ;
#endif
}
static void F_504 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_61 * V_101 ;
struct V_679 * V_680 ;
T_1 V_957 = V_2 -> V_957 ;
const char * V_967 ;
bool V_968 , V_969 ;
if ( F_114 ( V_62 ) )
return;
V_2 -> V_349 &= ~ V_686 ;
switch ( V_14 -> V_114 . type ) {
case V_115 : {
T_1 V_970 = F_40 ( V_14 , V_605 ) ;
T_1 V_971 = F_40 ( V_14 , V_972 ) ;
V_968 = ! ! ( V_970 & V_973 ) ;
V_969 = ! ! ( V_971 & V_974 ) ;
}
break;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_117 : {
T_1 V_975 = F_40 ( V_14 , V_976 ) ;
T_1 V_977 = F_40 ( V_14 , V_978 ) ;
V_968 = ! ! ( V_975 & V_979 ) ;
V_969 = ! ! ( V_977 & V_980 ) ;
}
break;
default:
V_969 = false ;
V_968 = false ;
break;
}
V_2 -> V_981 = V_186 ;
if ( F_14 ( V_724 , & V_2 -> V_35 ) )
F_505 ( V_2 ) ;
switch ( V_957 ) {
case V_958 :
V_967 = L_113 ;
break;
case V_982 :
V_967 = L_114 ;
break;
case V_983 :
V_967 = L_115 ;
break;
case V_984 :
V_967 = L_116 ;
break;
default:
V_967 = L_117 ;
break;
}
F_110 ( V_162 , L_118 , V_967 ,
( ( V_968 && V_969 ) ? L_119 :
( V_968 ? L_120 :
( V_969 ? L_121 : L_122 ) ) ) ) ;
F_506 ( V_62 ) ;
F_507 ( V_2 ) ;
F_508 ( V_2 -> V_62 ) ;
F_464 () ;
F_383 (adapter->netdev, upper, iter) {
if ( F_384 ( V_101 ) ) {
struct V_681 * V_267 = F_93 ( V_101 ) ;
if ( V_267 -> V_683 )
F_508 ( V_101 ) ;
}
}
F_466 () ;
F_501 ( V_2 ) ;
F_416 ( V_2 ) ;
}
static void F_509 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_357 = false ;
V_2 -> V_957 = 0 ;
if ( ! F_114 ( V_62 ) )
return;
if ( F_218 ( V_14 ) && V_14 -> V_114 . type == V_115 )
V_2 -> V_349 |= V_686 ;
if ( F_14 ( V_724 , & V_2 -> V_35 ) )
F_505 ( V_2 ) ;
F_110 ( V_162 , L_123 ) ;
F_413 ( V_62 ) ;
F_416 ( V_2 ) ;
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
struct V_985 * V_986 = & V_2 -> V_438 [ V_439 ] ;
T_1 V_987 = F_512 ( 1 , ~ V_986 -> V_124 ) ;
int V_49 , V_56 ;
if ( ! V_2 -> V_321 )
return false ;
if ( V_14 -> V_114 . type >= V_119 )
return false ;
for ( V_49 = 0 ; V_49 < V_2 -> V_321 ; V_49 ++ ) {
for ( V_56 = 0 ; V_56 < V_987 ; V_56 ++ ) {
T_1 V_988 , V_989 ;
V_988 = F_40 ( V_14 , F_513 ( V_987 , V_49 , V_56 ) ) ;
V_989 = F_40 ( V_14 , F_514 ( V_987 , V_49 , V_56 ) ) ;
if ( V_988 != V_989 )
return true ;
}
}
return false ;
}
static void F_515 ( struct V_1 * V_2 )
{
if ( ! F_114 ( V_2 -> V_62 ) ) {
if ( F_510 ( V_2 ) ||
F_511 ( V_2 ) ) {
F_27 ( V_162 , L_124 ) ;
F_97 ( V_161 , & V_2 -> V_35 ) ;
}
}
}
static inline void F_516 ( struct V_1 * V_2 ,
struct V_5 * V_990 )
{
if ( ! F_517 ( V_990 ) )
F_11 ( L_125 ) ;
F_18 ( L_126 , F_518 ( V_990 ) ) ;
F_519 ( V_990 , V_991 , V_992 ) ;
F_402 ( 100 ) ;
}
static void F_520 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_993 ;
T_1 V_994 ;
if ( ! ( F_114 ( V_2 -> V_62 ) ) )
return;
V_994 = F_40 ( V_14 , V_995 ) ;
if ( V_994 )
return;
if ( ! V_9 )
return;
for ( V_993 = 0 ; V_993 < V_2 -> V_321 ; ++ V_993 ) {
struct V_5 * V_990 = V_2 -> V_523 [ V_993 ] . V_990 ;
T_2 V_996 ;
if ( ! V_990 )
continue;
F_28 ( V_990 , V_997 , & V_996 ) ;
if ( V_996 != V_13 &&
V_996 & V_998 )
F_516 ( V_2 , V_990 ) ;
}
}
static void F_521 ( struct V_1 * V_2 )
{
T_1 V_999 ;
if ( V_2 -> V_14 . V_114 . type == V_115 ||
V_2 -> V_321 == 0 )
return;
V_999 = F_40 ( & V_2 -> V_14 , V_1000 ) ;
if ( ! V_999 )
return;
F_27 ( V_162 , L_127 , V_999 ) ;
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
F_14 ( V_715 , & V_2 -> V_35 ) )
return;
F_498 ( V_2 ) ;
if ( V_2 -> V_357 )
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
if ( ! ( V_2 -> V_349 & V_686 ) &&
! ( V_2 -> V_349 & V_370 ) )
return;
if ( V_2 -> V_371 &&
F_500 ( V_2 -> V_371 , V_186 ) )
return;
if ( F_15 ( V_716 , & V_2 -> V_35 ) )
return;
V_2 -> V_371 = V_186 + V_1001 - 1 ;
V_17 = V_14 -> V_46 . V_355 . V_1002 ( V_14 ) ;
if ( V_17 == V_719 )
goto V_1003;
if ( V_17 == V_718 ) {
V_2 -> V_349 |= V_370 ;
}
if ( V_17 )
goto V_1003;
if ( ! ( V_2 -> V_349 & V_370 ) )
goto V_1003;
V_2 -> V_349 &= ~ V_370 ;
if ( V_14 -> V_114 . type == V_115 )
V_17 = V_14 -> V_46 . V_355 . V_1004 ( V_14 ) ;
else
V_17 = V_14 -> V_114 . V_355 . V_1005 ( V_14 ) ;
if ( V_17 == V_719 )
goto V_1003;
V_2 -> V_146 |= V_372 ;
F_110 ( V_187 , L_128 , V_14 -> V_46 . V_1006 ) ;
V_1003:
F_37 ( V_716 , & V_2 -> V_35 ) ;
if ( ( V_17 == V_719 ) &&
( V_2 -> V_62 -> V_1007 == V_1008 ) ) {
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
bool V_687 = false ;
if ( ! ( V_2 -> V_146 & V_372 ) )
return;
if ( F_15 ( V_716 , & V_2 -> V_35 ) )
return;
V_2 -> V_146 &= ~ V_372 ;
V_20 = V_14 -> V_46 . V_689 ;
if ( ( ! V_20 ) && ( V_14 -> V_114 . V_355 . V_690 ) ) {
V_14 -> V_114 . V_355 . V_690 ( V_14 , & V_20 , & V_687 ) ;
if ( ! V_687 ) {
if ( V_20 & V_958 )
V_20 = V_958 ;
}
}
if ( V_14 -> V_114 . V_355 . V_691 )
V_14 -> V_114 . V_355 . V_691 ( V_14 , V_20 , true ) ;
V_2 -> V_146 |= V_374 ;
V_2 -> V_375 = V_186 ;
F_37 ( V_716 , & V_2 -> V_35 ) ;
}
static void F_526 ( unsigned long V_98 )
{
struct V_1 * V_2 = (struct V_1 * ) V_98 ;
unsigned long V_1009 ;
if ( V_2 -> V_146 & V_374 )
V_1009 = V_1010 / 10 ;
else
V_1009 = V_1010 * 2 ;
F_396 ( & V_2 -> V_713 , V_1009 + V_186 ) ;
F_13 ( V_2 ) ;
}
static void F_527 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_180 ;
if ( ! ( V_2 -> V_349 & V_392 ) )
return;
V_2 -> V_349 &= ~ V_392 ;
if ( ! V_14 -> V_46 . V_355 . V_1011 )
return;
V_180 = V_14 -> V_46 . V_355 . V_1011 ( & V_2 -> V_14 ) ;
if ( V_180 != V_359 )
return;
F_214 ( V_162 , L_71 , V_360 ) ;
}
static void F_528 ( struct V_1 * V_2 )
{
if ( ! F_233 ( V_161 , & V_2 -> V_35 ) )
return;
if ( F_14 ( V_34 , & V_2 -> V_35 ) ||
F_14 ( V_36 , & V_2 -> V_35 ) ||
F_14 ( V_715 , & V_2 -> V_35 ) )
return;
F_57 ( V_2 ) ;
F_529 ( V_2 -> V_62 , L_133 ) ;
V_2 -> V_188 ++ ;
F_464 () ;
F_397 ( V_2 ) ;
F_466 () ;
}
static void F_530 ( struct V_1012 * V_1013 )
{
struct V_1 * V_2 = F_201 ( V_1013 ,
struct V_1 ,
V_39 ) ;
if ( F_22 ( V_2 -> V_14 . V_41 ) ) {
if ( ! F_14 ( V_34 , & V_2 -> V_35 ) ) {
F_464 () ;
F_401 ( V_2 ) ;
F_466 () ;
}
F_34 ( V_2 ) ;
return;
}
if ( V_2 -> V_349 & V_1014 ) {
F_464 () ;
V_2 -> V_349 &= ~ V_1014 ;
F_451 ( V_2 -> V_62 ) ;
F_466 () ;
}
F_528 ( V_2 ) ;
F_527 ( V_2 ) ;
F_523 ( V_2 ) ;
F_525 ( V_2 ) ;
F_212 ( V_2 ) ;
F_522 ( V_2 ) ;
F_494 ( V_2 ) ;
F_496 ( V_2 ) ;
if ( F_14 ( V_724 , & V_2 -> V_35 ) ) {
F_531 ( V_2 ) ;
F_532 ( V_2 ) ;
}
F_34 ( V_2 ) ;
}
static int F_533 ( struct V_64 * V_65 ,
struct V_66 * V_1015 ,
T_4 * V_256 )
{
T_1 V_1016 , V_1017 , V_1018 ;
struct V_213 * V_95 = V_1015 -> V_95 ;
union {
struct V_1019 * V_1020 ;
struct V_1021 * V_1022 ;
unsigned char * V_1023 ;
} V_1024 ;
union {
struct V_1025 * V_1026 ;
unsigned char * V_1023 ;
} V_1027 ;
T_1 V_1028 , V_1029 ;
int V_17 ;
if ( V_95 -> V_243 != V_1030 )
return 0 ;
if ( ! F_534 ( V_95 ) )
return 0 ;
V_17 = F_535 ( V_95 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_1024 . V_1023 = F_536 ( V_95 ) ;
V_1027 . V_1023 = F_537 ( V_95 ) ;
V_1017 = V_1031 ;
if ( V_1024 . V_1020 -> V_1032 == 4 ) {
unsigned char * V_1033 = F_537 ( V_95 ) ;
unsigned char * V_1034 = V_1024 . V_1023 + ( V_1024 . V_1020 -> V_1035 * 4 ) ;
V_1024 . V_1020 -> V_1036 = F_538 ( F_539 ( V_1034 ,
V_1033 - V_1034 ,
0 ) ) ;
V_1017 |= V_1037 ;
V_1024 . V_1020 -> V_1038 = 0 ;
V_1015 -> V_1039 |= V_1040 |
V_1041 |
V_1042 ;
} else {
V_1024 . V_1022 -> V_1043 = 0 ;
V_1015 -> V_1039 |= V_1040 |
V_1041 ;
}
V_1029 = V_1027 . V_1023 - V_95 -> V_98 ;
* V_256 = ( V_1027 . V_1026 -> V_1044 * 4 ) + V_1029 ;
V_1028 = V_95 -> V_88 - V_1029 ;
F_540 ( & V_1027 . V_1026 -> V_1036 , F_541 ( V_1028 ) ) ;
V_1015 -> V_183 = F_154 ( V_95 ) -> V_183 ;
V_1015 -> V_182 += ( V_1015 -> V_183 - 1 ) * * V_256 ;
V_1018 = ( * V_256 - V_1029 ) << V_1045 ;
V_1018 |= F_154 ( V_95 ) -> V_257 << V_1046 ;
V_1016 = V_1027 . V_1023 - V_1024 . V_1023 ;
V_1016 |= ( V_1024 . V_1023 - V_95 -> V_98 ) << V_1047 ;
V_1016 |= V_1015 -> V_1039 & V_1048 ;
F_542 ( V_65 , V_1016 , 0 , V_1017 ,
V_1018 ) ;
return 1 ;
}
static inline bool F_543 ( struct V_213 * V_95 )
{
unsigned int V_1049 = 0 ;
F_544 ( V_95 , & V_1049 , V_1050 , NULL , NULL ) ;
return V_1049 == F_545 ( V_95 ) ;
}
static void F_546 ( struct V_64 * V_65 ,
struct V_66 * V_1015 )
{
struct V_213 * V_95 = V_1015 -> V_95 ;
T_1 V_1016 = 0 ;
T_1 V_1017 = 0 ;
if ( V_95 -> V_243 != V_1030 ) {
V_1051:
if ( ! ( V_1015 -> V_1039 & ( V_1052 |
V_1053 ) ) )
return;
goto V_1054;
}
switch ( V_95 -> V_1055 ) {
case F_547 ( struct V_1025 , V_1036 ) :
V_1017 = V_1031 ;
case F_547 ( struct V_1056 , V_1036 ) :
break;
case F_547 ( struct V_1057 , V_1058 ) :
if ( ( ( V_1015 -> V_269 == F_161 ( V_1059 ) ) &&
( F_548 ( V_95 ) -> V_269 == V_1050 ) ) ||
( ( V_1015 -> V_269 == F_161 ( V_1060 ) ) &&
F_543 ( V_95 ) ) ) {
V_1017 = V_1061 ;
break;
}
default:
F_549 ( V_95 ) ;
goto V_1051;
}
V_1015 -> V_1039 |= V_1041 ;
V_1016 = F_545 ( V_95 ) -
F_550 ( V_95 ) ;
V_1054:
V_1016 |= F_550 ( V_95 ) << V_1047 ;
V_1016 |= V_1015 -> V_1039 & V_1048 ;
F_542 ( V_65 , V_1016 , 0 , V_1017 , 0 ) ;
}
static T_1 F_551 ( struct V_213 * V_95 , T_1 V_1039 )
{
T_1 V_1062 = V_1063 |
V_1064 |
V_1065 ;
V_1062 |= F_552 ( V_1039 , V_1052 ,
V_1066 ) ;
V_1062 |= F_552 ( V_1039 , V_1040 ,
V_1067 ) ;
V_1062 |= F_552 ( V_1039 , V_1068 ,
V_1069 ) ;
V_1062 ^= F_552 ( V_95 -> V_1070 , 1 , V_1065 ) ;
return V_1062 ;
}
static void F_553 ( union V_68 * V_69 ,
T_1 V_1039 , unsigned int V_1028 )
{
T_1 V_1071 = V_1028 << V_1072 ;
V_1071 |= F_552 ( V_1039 ,
V_1041 ,
V_1073 ) ;
V_1071 |= F_552 ( V_1039 ,
V_1042 ,
V_1074 ) ;
V_1071 |= F_552 ( V_1039 ,
V_1053 ,
V_1075 ) ;
V_69 -> V_253 . V_1071 = F_102 ( V_1071 ) ;
}
static int F_554 ( struct V_64 * V_65 , T_2 V_294 )
{
F_109 ( V_65 -> V_62 , V_65 -> V_92 ) ;
F_116 () ;
if ( F_25 ( F_115 ( V_65 ) < V_294 ) )
return - V_801 ;
F_555 ( V_65 -> V_62 , V_65 -> V_92 ) ;
++ V_65 -> V_159 . V_189 ;
return 0 ;
}
static inline int F_556 ( struct V_64 * V_65 , T_2 V_294 )
{
if ( F_25 ( F_115 ( V_65 ) >= V_294 ) )
return 0 ;
return F_554 ( V_65 , V_294 ) ;
}
static void F_557 ( struct V_64 * V_65 ,
struct V_66 * V_1015 ,
const T_4 V_256 )
{
struct V_213 * V_95 = V_1015 -> V_95 ;
struct V_66 * V_67 ;
union V_68 * V_69 ;
struct V_280 * V_281 ;
T_9 V_87 ;
unsigned int V_286 , V_294 ;
T_1 V_1039 = V_1015 -> V_1039 ;
T_1 V_1062 = F_551 ( V_95 , V_1039 ) ;
T_2 V_49 = V_65 -> V_86 ;
V_69 = F_65 ( V_65 , V_49 ) ;
F_553 ( V_69 , V_1039 , V_95 -> V_88 - V_256 ) ;
V_294 = F_153 ( V_95 ) ;
V_286 = V_95 -> V_286 ;
#ifdef F_181
if ( V_1039 & V_1076 ) {
if ( V_286 < sizeof( struct V_312 ) ) {
V_294 -= sizeof( struct V_312 ) - V_286 ;
V_286 = 0 ;
} else {
V_286 -= sizeof( struct V_312 ) ;
}
}
#endif
V_87 = F_558 ( V_65 -> V_80 , V_95 -> V_98 , V_294 , V_128 ) ;
V_67 = V_1015 ;
for ( V_281 = & F_154 ( V_95 ) -> V_282 [ 0 ] ; ; V_281 ++ ) {
if ( F_146 ( V_65 -> V_80 , V_87 ) )
goto V_1077;
F_85 ( V_67 , V_88 , V_294 ) ;
F_559 ( V_67 , V_87 , V_87 ) ;
V_69 -> V_253 . V_1078 = F_149 ( V_87 ) ;
while ( F_23 ( V_294 > V_1079 ) ) {
V_69 -> V_253 . V_1080 =
F_102 ( V_1062 ^ V_1079 ) ;
V_49 ++ ;
V_69 ++ ;
if ( V_49 == V_65 -> V_94 ) {
V_69 = F_65 ( V_65 , 0 ) ;
V_49 = 0 ;
}
V_69 -> V_253 . V_1071 = 0 ;
V_87 += V_1079 ;
V_294 -= V_1079 ;
V_69 -> V_253 . V_1078 = F_149 ( V_87 ) ;
}
if ( F_25 ( ! V_286 ) )
break;
V_69 -> V_253 . V_1080 = F_102 ( V_1062 ^ V_294 ) ;
V_49 ++ ;
V_69 ++ ;
if ( V_49 == V_65 -> V_94 ) {
V_69 = F_65 ( V_65 , 0 ) ;
V_49 = 0 ;
}
V_69 -> V_253 . V_1071 = 0 ;
#ifdef F_181
V_294 = F_333 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_294 = F_560 ( V_281 ) ;
#endif
V_286 -= V_294 ;
V_87 = F_561 ( V_65 -> V_80 , V_281 , 0 , V_294 ,
V_128 ) ;
V_67 = & V_65 -> V_84 [ V_49 ] ;
}
V_1062 |= V_294 | V_1081 ;
V_69 -> V_253 . V_1080 = F_102 ( V_1062 ) ;
F_562 ( F_112 ( V_65 ) , V_1015 -> V_182 ) ;
V_1015 -> V_90 = V_186 ;
F_150 () ;
V_1015 -> V_89 = V_69 ;
V_49 ++ ;
if ( V_49 == V_65 -> V_94 )
V_49 = 0 ;
V_65 -> V_86 = V_49 ;
F_556 ( V_65 , V_1082 ) ;
if ( F_563 ( F_112 ( V_65 ) ) || ! V_95 -> V_1083 ) {
F_151 ( V_49 , V_65 -> V_153 ) ;
F_564 () ;
}
return;
V_1077:
F_437 ( V_65 -> V_80 , L_134 ) ;
for (; ; ) {
V_67 = & V_65 -> V_84 [ V_49 ] ;
F_81 ( V_65 , V_67 ) ;
if ( V_67 == V_1015 )
break;
if ( V_49 == 0 )
V_49 = V_65 -> V_94 ;
V_49 -- ;
}
V_65 -> V_86 = V_49 ;
}
static void F_565 ( struct V_64 * V_127 ,
struct V_66 * V_1015 )
{
struct V_171 * V_172 = V_127 -> V_172 ;
union V_1084 V_1085 = { . V_1086 = 0 } ;
union V_1084 V_1087 = { . V_1086 = 0 } ;
union {
unsigned char * V_1088 ;
struct V_1019 * V_1089 ;
struct V_1021 * V_1090 ;
} V_1023 ;
struct V_1025 * V_1091 ;
unsigned int V_1092 ;
struct V_213 * V_95 ;
T_12 V_1093 ;
int V_1094 ;
if ( ! V_172 )
return;
if ( ! V_127 -> V_423 )
return;
V_127 -> V_424 ++ ;
if ( ( V_1015 -> V_269 != F_161 ( V_1059 ) ) &&
( V_1015 -> V_269 != F_161 ( V_1060 ) ) )
return;
V_95 = V_1015 -> V_95 ;
V_1023 . V_1088 = F_536 ( V_95 ) ;
if ( V_95 -> V_234 &&
V_1015 -> V_269 == F_161 ( V_1059 ) &&
V_1023 . V_1089 -> V_269 != V_1095 ) {
struct V_1 * V_2 = V_172 -> V_2 ;
if ( V_2 -> V_626 &&
F_566 ( V_95 ) -> V_1096 == V_2 -> V_626 )
V_1023 . V_1088 = F_567 ( V_95 ) ;
if ( V_2 -> V_628 &&
F_566 ( V_95 ) -> V_1096 == V_2 -> V_628 )
V_1023 . V_1088 = F_567 ( V_95 ) ;
}
switch ( V_1023 . V_1089 -> V_1032 ) {
case V_1097 :
V_1092 = ( V_1023 . V_1088 [ 0 ] & 0x0F ) << 2 ;
V_1094 = V_1023 . V_1089 -> V_269 ;
break;
case 6 :
V_1092 = V_1023 . V_1088 - V_95 -> V_98 ;
V_1094 = F_544 ( V_95 , & V_1092 , V_1098 , NULL , NULL ) ;
V_1092 -= V_1023 . V_1088 - V_95 -> V_98 ;
break;
default:
return;
}
if ( V_1094 != V_1098 )
return;
V_1091 = (struct V_1025 * ) ( V_1023 . V_1088 + V_1092 ) ;
if ( V_1091 -> V_1099 )
return;
if ( ! V_1091 -> V_1100 && ( V_127 -> V_424 < V_127 -> V_423 ) )
return;
V_127 -> V_424 = 0 ;
V_1093 = F_161 ( V_1015 -> V_1039 >> V_1101 ) ;
V_1085 . V_1102 . V_1093 = V_1093 ;
if ( V_1015 -> V_1039 & ( V_1103 | V_1052 ) )
V_1087 . V_1104 . V_1105 ^= V_1091 -> V_1096 ^ F_161 ( V_268 ) ;
else
V_1087 . V_1104 . V_1105 ^= V_1091 -> V_1096 ^ V_1015 -> V_269 ;
V_1087 . V_1104 . V_1106 ^= V_1091 -> V_1107 ;
switch ( V_1023 . V_1089 -> V_1032 ) {
case V_1097 :
V_1085 . V_1102 . V_1108 = V_1109 ;
V_1087 . V_1024 ^= V_1023 . V_1089 -> V_1110 ^ V_1023 . V_1089 -> V_1111 ;
break;
case 6 :
V_1085 . V_1102 . V_1108 = V_1112 ;
V_1087 . V_1024 ^= V_1023 . V_1090 -> V_1110 . V_1113 [ 0 ] ^
V_1023 . V_1090 -> V_1110 . V_1113 [ 1 ] ^
V_1023 . V_1090 -> V_1110 . V_1113 [ 2 ] ^
V_1023 . V_1090 -> V_1110 . V_1113 [ 3 ] ^
V_1023 . V_1090 -> V_1111 . V_1113 [ 0 ] ^
V_1023 . V_1090 -> V_1111 . V_1113 [ 1 ] ^
V_1023 . V_1090 -> V_1111 . V_1113 [ 2 ] ^
V_1023 . V_1090 -> V_1111 . V_1113 [ 3 ] ;
break;
default:
break;
}
if ( V_1023 . V_1088 != F_536 ( V_95 ) )
V_1085 . V_1102 . V_1108 |= V_1114 ;
F_568 ( & V_172 -> V_2 -> V_14 ,
V_1085 , V_1087 , V_127 -> V_92 ) ;
}
static T_2 F_569 ( struct V_61 * V_80 , struct V_213 * V_95 ,
void * V_1115 , T_16 V_1116 )
{
struct V_665 * V_1117 = V_1115 ;
#ifdef F_181
struct V_1 * V_2 ;
struct V_985 * V_1118 ;
int V_1119 ;
#endif
if ( V_1117 )
return V_95 -> V_1120 + V_1117 -> V_673 ;
#ifdef F_181
switch ( F_570 ( V_95 ) ) {
case F_161 ( V_1121 ) :
case F_161 ( V_1122 ) :
V_2 = F_93 ( V_80 ) ;
if ( V_2 -> V_146 & V_531 )
break;
default:
return V_1116 ( V_80 , V_95 ) ;
}
V_1118 = & V_2 -> V_438 [ V_1123 ] ;
V_1119 = F_571 ( V_95 ) ? F_572 ( V_95 ) :
F_573 () ;
while ( V_1119 >= V_1118 -> V_465 )
V_1119 -= V_1118 -> V_465 ;
return V_1119 + V_1118 -> V_1049 ;
#else
return V_1116 ( V_80 , V_95 ) ;
#endif
}
T_17 F_574 ( struct V_213 * V_95 ,
struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_66 * V_1015 ;
int V_1124 ;
T_1 V_1039 = 0 ;
unsigned short V_1118 ;
T_2 V_94 = F_575 ( F_153 ( V_95 ) ) ;
T_12 V_269 = V_95 -> V_269 ;
T_4 V_256 = 0 ;
for ( V_1118 = 0 ; V_1118 < F_154 ( V_95 ) -> V_300 ; V_1118 ++ )
V_94 += F_575 ( F_154 ( V_95 ) -> V_282 [ V_1118 ] . V_294 ) ;
if ( F_556 ( V_65 , V_94 + 3 ) ) {
V_65 -> V_159 . V_832 ++ ;
return V_1125 ;
}
V_1015 = & V_65 -> V_84 [ V_65 -> V_86 ] ;
V_1015 -> V_95 = V_95 ;
V_1015 -> V_182 = V_95 -> V_88 ;
V_1015 -> V_183 = 1 ;
if ( F_576 ( V_95 ) ) {
V_1039 |= F_577 ( V_95 ) << V_1101 ;
V_1039 |= V_1052 ;
} else if ( V_269 == F_161 ( V_268 ) ) {
struct V_1126 * V_1127 , V_1128 ;
V_1127 = F_578 ( V_95 , V_527 , sizeof( V_1128 ) , & V_1128 ) ;
if ( ! V_1127 )
goto V_1129;
V_1039 |= F_579 ( V_1127 -> V_1130 ) <<
V_1101 ;
V_1039 |= V_1103 ;
}
V_269 = F_570 ( V_95 ) ;
if ( F_23 ( F_154 ( V_95 ) -> V_1039 & V_1131 ) &&
V_2 -> V_1132 &&
! F_580 ( V_1133 ,
& V_2 -> V_35 ) ) {
F_154 ( V_95 ) -> V_1039 |= V_1134 ;
V_1039 |= V_1068 ;
V_2 -> V_1135 = F_581 ( V_95 ) ;
V_2 -> V_1136 = V_186 ;
F_582 ( & V_2 -> V_1137 ) ;
}
F_583 ( V_95 ) ;
#ifdef F_315
if ( V_2 -> V_146 & V_433 )
V_1039 |= V_1053 ;
#endif
if ( ( V_2 -> V_146 & V_147 ) &&
( ( V_1039 & ( V_1052 | V_1103 ) ) ||
( V_95 -> V_1138 != V_1139 ) ) ) {
V_1039 &= ~ V_1140 ;
V_1039 |= ( V_95 -> V_1138 & 0x7 ) <<
V_1141 ;
if ( V_1039 & V_1103 ) {
struct V_1142 * V_1127 ;
if ( F_535 ( V_95 , 0 ) )
goto V_1129;
V_1127 = (struct V_1142 * ) V_95 -> V_98 ;
V_1127 -> V_1130 = F_161 ( V_1039 >>
V_1101 ) ;
} else {
V_1039 |= V_1052 ;
}
}
V_1015 -> V_1039 = V_1039 ;
V_1015 -> V_269 = V_269 ;
#ifdef F_181
if ( ( V_269 == F_161 ( V_1121 ) ) &&
( V_65 -> V_62 -> V_215 & ( V_1143 | V_1144 ) ) ) {
V_1124 = F_584 ( V_65 , V_1015 , & V_256 ) ;
if ( V_1124 < 0 )
goto V_1129;
goto V_1145;
}
#endif
V_1124 = F_533 ( V_65 , V_1015 , & V_256 ) ;
if ( V_1124 < 0 )
goto V_1129;
else if ( ! V_1124 )
F_546 ( V_65 , V_1015 ) ;
if ( F_14 ( V_397 , & V_65 -> V_35 ) )
F_565 ( V_65 , V_1015 ) ;
#ifdef F_181
V_1145:
#endif
F_557 ( V_65 , V_1015 , V_256 ) ;
return V_1146 ;
V_1129:
F_82 ( V_1015 -> V_95 ) ;
V_1015 -> V_95 = NULL ;
return V_1146 ;
}
static T_17 F_585 ( struct V_213 * V_95 ,
struct V_61 * V_62 ,
struct V_64 * V_127 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_64 * V_65 ;
if ( F_586 ( V_95 , 17 ) )
return V_1146 ;
V_65 = V_127 ? V_127 : V_2 -> V_65 [ V_95 -> V_1120 ] ;
return F_574 ( V_95 , V_2 , V_65 ) ;
}
static T_17 F_587 ( struct V_213 * V_95 ,
struct V_61 * V_62 )
{
return F_585 ( V_95 , V_62 , NULL ) ;
}
static int F_588 ( struct V_61 * V_62 , void * V_1147 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1148 * V_591 = V_1147 ;
if ( ! F_381 ( V_591 -> V_1149 ) )
return - V_1150 ;
memcpy ( V_62 -> V_678 , V_591 -> V_1149 , V_62 -> V_1151 ) ;
memcpy ( V_14 -> V_114 . V_591 , V_591 -> V_1149 , V_62 -> V_1151 ) ;
F_322 ( V_2 ) ;
return 0 ;
}
static int
F_589 ( struct V_61 * V_62 , int V_1152 , int V_1153 , T_2 V_591 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_4 ;
int V_1154 ;
if ( V_1152 != V_14 -> V_46 . V_1155 . V_1152 )
return - V_596 ;
V_1154 = V_14 -> V_46 . V_355 . V_1156 ( V_14 , V_591 , V_1153 , & V_4 ) ;
if ( ! V_1154 )
V_1154 = V_4 ;
return V_1154 ;
}
static int F_590 ( struct V_61 * V_62 , int V_1152 , int V_1153 ,
T_2 V_591 , T_2 V_4 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_1152 != V_14 -> V_46 . V_1155 . V_1152 )
return - V_596 ;
return V_14 -> V_46 . V_355 . V_1157 ( V_14 , V_591 , V_1153 , V_4 ) ;
}
static int F_591 ( struct V_61 * V_62 , struct V_1158 * V_1159 , int V_1160 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
switch ( V_1160 ) {
case V_1161 :
return F_592 ( V_2 , V_1159 ) ;
case V_1162 :
return F_593 ( V_2 , V_1159 ) ;
default:
return F_594 ( & V_2 -> V_14 . V_46 . V_1155 , F_595 ( V_1159 ) , V_1160 ) ;
}
}
static int F_596 ( struct V_61 * V_80 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_93 ( V_80 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_381 ( V_14 -> V_114 . V_1163 ) ) {
F_464 () ;
V_17 = F_597 ( V_80 , V_14 -> V_114 . V_1163 , V_1164 ) ;
F_466 () ;
V_14 -> V_114 . V_355 . V_723 ( V_14 , F_288 ( 0 ) ) ;
}
return V_17 ;
}
static int F_598 ( struct V_61 * V_80 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_93 ( V_80 ) ;
struct V_1165 * V_114 = & V_2 -> V_14 . V_114 ;
if ( F_381 ( V_114 -> V_1163 ) ) {
F_464 () ;
V_17 = F_599 ( V_80 , V_114 -> V_1163 , V_1164 ) ;
F_466 () ;
}
return V_17 ;
}
static void F_600 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
int V_49 ;
if ( F_14 ( V_34 , & V_2 -> V_35 ) )
return;
for ( V_49 = 0 ; V_49 < V_2 -> V_207 ; V_49 ++ )
F_235 ( 0 , V_2 -> V_172 [ V_49 ] ) ;
}
static struct V_1166 * F_601 ( struct V_61 * V_62 ,
struct V_1166 * V_131 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
int V_49 ;
F_602 () ;
for ( V_49 = 0 ; V_49 < V_2 -> V_99 ; V_49 ++ ) {
struct V_64 * V_127 = F_21 ( V_2 -> V_74 [ V_49 ] ) ;
T_6 V_185 , V_151 ;
unsigned int V_1167 ;
if ( V_127 ) {
do {
V_1167 = F_603 ( & V_127 -> V_184 ) ;
V_151 = V_127 -> V_131 . V_151 ;
V_185 = V_127 -> V_131 . V_185 ;
} while ( F_604 ( & V_127 -> V_184 , V_1167 ) );
V_131 -> V_837 += V_151 ;
V_131 -> V_836 += V_185 ;
}
}
for ( V_49 = 0 ; V_49 < V_2 -> V_83 ; V_49 ++ ) {
struct V_64 * V_127 = F_21 ( V_2 -> V_65 [ V_49 ] ) ;
T_6 V_185 , V_151 ;
unsigned int V_1167 ;
if ( V_127 ) {
do {
V_1167 = F_603 ( & V_127 -> V_184 ) ;
V_151 = V_127 -> V_131 . V_151 ;
V_185 = V_127 -> V_131 . V_185 ;
} while ( F_604 ( & V_127 -> V_184 , V_1167 ) );
V_131 -> V_839 += V_151 ;
V_131 -> V_838 += V_185 ;
}
}
F_605 () ;
V_131 -> V_946 = V_62 -> V_131 . V_946 ;
V_131 -> V_947 = V_62 -> V_131 . V_947 ;
V_131 -> V_949 = V_62 -> V_131 . V_949 ;
V_131 -> V_950 = V_62 -> V_131 . V_950 ;
V_131 -> V_951 = V_62 -> V_131 . V_951 ;
return V_131 ;
}
static void F_606 ( struct V_1 * V_2 , T_4 V_141 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_3 , V_1168 ;
int V_49 ;
if ( V_14 -> V_114 . type == V_115 )
return;
V_3 = F_40 ( V_14 , V_1169 ) ;
V_1168 = V_3 ;
for ( V_49 = 0 ; V_49 < V_649 ; V_49 ++ ) {
T_4 V_1170 = V_3 >> ( V_49 * V_1171 ) ;
if ( V_1170 > V_141 )
V_3 &= ~ ( 0x7 << V_1171 ) ;
}
if ( V_3 != V_1168 )
F_75 ( V_14 , V_1169 , V_3 ) ;
return;
}
static void F_607 ( struct V_1 * V_2 )
{
struct V_61 * V_80 = V_2 -> V_62 ;
struct V_1172 * V_143 = & V_2 -> V_143 ;
struct V_1173 * V_1174 = V_2 -> V_634 ;
T_4 V_1175 ;
for ( V_1175 = 0 ; V_1175 < V_1176 ; V_1175 ++ ) {
T_4 V_141 = 0 ;
if ( V_2 -> V_630 & V_631 )
V_141 = F_608 ( V_143 , 0 , V_1175 ) ;
else if ( V_1174 )
V_141 = V_1174 -> V_635 [ V_1175 ] ;
F_609 ( V_80 , V_1175 , V_141 ) ;
}
}
int F_610 ( struct V_61 * V_80 , T_4 V_141 )
{
struct V_1 * V_2 = F_93 ( V_80 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
bool V_1177 ;
if ( V_141 > V_2 -> V_143 . V_732 . V_733 )
return - V_596 ;
if ( V_14 -> V_114 . type == V_115 && V_141 && V_141 < V_649 )
return - V_596 ;
V_1177 = ( F_611 ( & V_2 -> V_675 , 32 ) > 1 ) ;
if ( V_141 && V_1177 && V_2 -> V_676 > V_1178 )
return - V_801 ;
if ( F_61 ( V_80 ) )
F_454 ( V_80 ) ;
else
F_404 ( V_2 ) ;
F_471 ( V_2 ) ;
#ifdef F_386
if ( V_141 ) {
F_612 ( V_80 , V_141 ) ;
F_607 ( V_2 ) ;
V_2 -> V_146 |= V_147 ;
if ( V_2 -> V_14 . V_114 . type == V_115 ) {
V_2 -> V_1179 = V_2 -> V_14 . V_132 . V_778 ;
V_2 -> V_14 . V_132 . V_778 = V_1180 ;
}
} else {
F_613 ( V_80 ) ;
if ( V_2 -> V_14 . V_114 . type == V_115 )
V_2 -> V_14 . V_132 . V_778 = V_2 -> V_1179 ;
V_2 -> V_146 &= ~ V_147 ;
V_2 -> V_748 . V_144 = false ;
V_2 -> V_143 . V_144 = false ;
}
F_606 ( V_2 , V_141 ) ;
#endif
F_465 ( V_2 ) ;
if ( F_61 ( V_80 ) )
return F_449 ( V_80 ) ;
return 0 ;
}
static int F_614 ( struct V_1 * V_2 ,
struct V_1181 * V_1182 )
{
T_1 V_1183 = V_1182 -> V_1184 . V_1185 ;
T_1 V_1186 = F_615 ( V_1182 -> V_1184 . V_1185 ) ;
T_1 V_1187 = V_1182 -> V_1184 . V_1185 & 0xfffff ;
int V_17 = 0 , V_49 , V_56 ;
struct V_1188 * V_1189 = NULL ;
if ( V_1187 > V_1190 )
return - V_596 ;
if ( ( V_1186 != 0x800 ) && ( V_1186 >= V_772 ) )
return - V_596 ;
if ( V_1186 != 0x800 ) {
V_1189 = V_2 -> V_768 [ V_1186 ] ;
if ( ! V_1189 )
return - V_596 ;
if ( ! F_14 ( V_1187 - 1 , V_1189 -> V_1191 ) )
return - V_596 ;
F_37 ( V_1187 - 1 , V_1189 -> V_1191 ) ;
}
for ( V_49 = 1 ; V_49 < V_772 ; V_49 ++ ) {
V_1189 = V_2 -> V_768 [ V_49 ] ;
if ( V_1189 && V_1189 -> V_1192 == V_1183 ) {
for ( V_56 = 0 ; V_56 < V_1190 ; V_56 ++ ) {
if ( ! F_14 ( V_56 , V_1189 -> V_1191 ) )
continue;
F_364 ( & V_2 -> V_659 ) ;
V_17 = F_616 ( V_2 ,
NULL ,
V_56 + 1 ) ;
F_369 ( & V_2 -> V_659 ) ;
F_37 ( V_56 , V_1189 -> V_1191 ) ;
}
F_249 ( V_1189 -> V_1085 ) ;
F_249 ( V_1189 -> V_124 ) ;
F_249 ( V_1189 ) ;
V_2 -> V_768 [ V_49 ] = NULL ;
return V_17 ;
}
}
F_364 ( & V_2 -> V_659 ) ;
V_17 = F_616 ( V_2 , NULL , V_1187 ) ;
F_369 ( & V_2 -> V_659 ) ;
return V_17 ;
}
static int F_617 ( struct V_1 * V_2 ,
T_12 V_269 ,
struct V_1181 * V_1182 )
{
T_1 V_1186 = F_615 ( V_1182 -> V_1193 . V_1185 ) ;
if ( V_1186 >= V_772 )
return - V_596 ;
if ( V_1182 -> V_1193 . V_1194 > 0 )
return - V_596 ;
F_97 ( V_1186 - 1 , & V_2 -> V_1195 ) ;
return 0 ;
}
static int F_618 ( struct V_1 * V_2 ,
struct V_1181 * V_1182 )
{
T_1 V_1186 = F_615 ( V_1182 -> V_1193 . V_1185 ) ;
if ( V_1186 >= V_772 )
return - V_596 ;
F_37 ( V_1186 - 1 , & V_2 -> V_1195 ) ;
return 0 ;
}
static int F_619 ( struct V_1 * V_2 , int V_1196 ,
T_4 * V_110 , T_6 * V_663 )
{
unsigned int V_321 = V_2 -> V_321 , V_993 ;
struct V_61 * V_101 ;
struct V_679 * V_680 ;
for ( V_993 = 0 ; V_993 < V_321 ; ++ V_993 ) {
V_101 = F_457 ( V_2 -> V_523 [ V_993 ] . V_990 ) ;
if ( V_101 -> V_1196 == V_1196 ) {
if ( V_2 -> V_676 > 1 )
* V_110 = V_993 * 2 ;
else
* V_110 = V_993 * V_2 -> V_667 ;
* V_663 = V_993 + 1 ;
* V_663 <<= V_1197 ;
return 0 ;
}
}
F_383 (adapter->netdev, upper, iter) {
if ( F_384 ( V_101 ) ) {
struct V_681 * V_682 = F_93 ( V_101 ) ;
struct V_665 * V_666 = V_682 -> V_683 ;
if ( V_666 && V_666 -> V_62 -> V_1196 == V_1196 ) {
* V_110 = V_2 -> V_74 [ V_666 -> V_668 ] -> V_156 ;
* V_663 = * V_110 ;
return 0 ;
}
}
}
return - V_596 ;
}
static int F_620 ( struct V_1 * V_2 ,
struct V_1198 * V_1199 , T_6 * V_663 , T_4 * V_110 )
{
const struct V_1200 * V_71 ;
F_621 ( V_1201 ) ;
int V_17 ;
if ( F_622 ( V_1199 ) )
return - V_596 ;
F_623 ( V_1199 , & V_1201 ) ;
F_624 (a, &actions, list) {
if ( F_625 ( V_71 ) ) {
* V_663 = V_664 ;
* V_110 = V_664 ;
return 0 ;
}
if ( F_626 ( V_71 ) ) {
int V_1196 = F_627 ( V_71 ) ;
V_17 = F_619 ( V_2 , V_1196 , V_110 ,
V_663 ) ;
if ( V_17 == 0 )
return V_17 ;
}
}
return - V_596 ;
}
static int F_620 ( struct V_1 * V_2 ,
struct V_1198 * V_1199 , T_6 * V_663 , T_4 * V_110 )
{
return - V_596 ;
}
static int F_628 ( struct V_657 * V_1085 ,
union V_1202 * V_124 ,
struct V_1181 * V_1182 ,
struct V_1203 * V_1204 ,
struct V_1205 * V_1206 )
{
int V_49 , V_56 , V_1207 ;
T_18 V_1208 , V_1209 ;
bool V_1210 = false , V_1211 = false ;
for ( V_49 = 0 ; V_49 < V_1182 -> V_1184 . V_1212 -> V_1213 ; V_49 ++ ) {
V_1207 = V_1182 -> V_1184 . V_1212 -> V_1214 [ V_49 ] . V_1207 ;
V_1208 = V_1182 -> V_1184 . V_1212 -> V_1214 [ V_49 ] . V_1208 ;
V_1209 = V_1182 -> V_1184 . V_1212 -> V_1214 [ V_49 ] . V_124 ;
for ( V_56 = 0 ; V_1204 [ V_56 ] . V_1208 ; V_56 ++ ) {
if ( V_1204 [ V_56 ] . V_1207 == V_1207 ) {
V_1204 [ V_56 ] . V_1208 ( V_1085 , V_124 , V_1208 , V_1209 ) ;
V_1085 -> V_658 . V_1102 . V_1108 |=
V_1204 [ V_56 ] . type ;
V_1210 = true ;
break;
}
}
if ( V_1206 ) {
if ( V_1206 -> V_1207 == V_1182 -> V_1184 . V_1212 -> V_1214 [ V_49 ] . V_1207 &&
V_1206 -> V_1208 == V_1182 -> V_1184 . V_1212 -> V_1214 [ V_49 ] . V_1208 &&
V_1206 -> V_124 == V_1182 -> V_1184 . V_1212 -> V_1214 [ V_49 ] . V_124 )
V_1211 = true ;
else
continue;
}
}
if ( V_1206 && ! V_1211 )
return - V_596 ;
if ( ! V_1210 )
return 0 ;
V_124 -> V_1102 . V_1108 = V_1215 |
V_1216 ;
if ( V_1085 -> V_658 . V_1102 . V_1108 == V_1217 )
V_124 -> V_1102 . V_1108 &= V_1215 ;
return 0 ;
}
static int F_629 ( struct V_1 * V_2 ,
T_12 V_269 ,
struct V_1181 * V_1182 )
{
T_1 V_1187 = V_1182 -> V_1184 . V_1185 & 0xfffff ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1203 * V_1204 ;
struct V_657 * V_1085 = NULL ;
union V_1202 * V_124 = NULL ;
struct V_1188 * V_1189 = NULL ;
int V_49 , V_17 = - V_596 ;
T_4 V_110 ;
T_1 V_1186 , V_1218 ;
V_1186 = F_615 ( V_1182 -> V_1184 . V_1185 ) ;
V_1218 = F_615 ( V_1182 -> V_1184 . V_1219 ) ;
if ( V_269 != F_161 ( V_1059 ) )
return V_17 ;
if ( V_1187 >= ( ( 1024 << V_2 -> V_652 ) - 2 ) ) {
F_108 ( V_162 , L_135 ) ;
return V_17 ;
}
if ( V_1186 == 0x800 ) {
V_1204 = ( V_2 -> V_768 [ 0 ] ) -> V_770 ;
} else {
if ( V_1186 >= V_772 )
return V_17 ;
if ( ! V_2 -> V_768 [ V_1186 ] )
return V_17 ;
V_1204 = ( V_2 -> V_768 [ V_1186 ] ) -> V_770 ;
}
if ( ! V_1204 )
return V_17 ;
if ( V_1218 ) {
struct V_1205 * V_1206 = V_1220 ;
if ( V_1218 >= V_772 )
return V_17 ;
if ( ! F_14 ( V_1218 - 1 , & V_2 -> V_1195 ) )
return V_17 ;
if ( V_2 -> V_768 [ V_1218 ] &&
( V_2 -> V_768 [ V_1218 ] ) -> V_1192 ) {
F_108 ( V_162 , L_136 ,
V_1218 ) ;
return V_17 ;
}
for ( V_49 = 0 ; V_1206 [ V_49 ] . V_1189 ; V_49 ++ ) {
if ( V_1206 [ V_49 ] . V_1221 != V_1182 -> V_1184 . V_1212 -> V_1222 ||
V_1206 [ V_49 ] . V_1223 != V_1182 -> V_1184 . V_1212 -> V_1224 ||
V_1206 [ V_49 ] . V_1209 != V_1182 -> V_1184 . V_1212 -> V_1225 )
return V_17 ;
V_1189 = F_424 ( sizeof( * V_1189 ) , V_769 ) ;
if ( ! V_1189 )
return - V_584 ;
V_1085 = F_424 ( sizeof( * V_1085 ) , V_769 ) ;
if ( ! V_1085 ) {
V_17 = - V_584 ;
goto V_1226;
}
V_124 = F_424 ( sizeof( * V_124 ) , V_769 ) ;
if ( ! V_124 ) {
V_17 = - V_584 ;
goto V_1227;
}
V_1189 -> V_1085 = V_1085 ;
V_1189 -> V_124 = V_124 ;
V_1189 -> V_1192 = V_1182 -> V_1184 . V_1185 ;
V_17 = F_628 ( V_1085 , V_124 , V_1182 ,
V_1204 , & V_1206 [ V_49 ] ) ;
if ( ! V_17 ) {
V_1189 -> V_770 = V_1206 [ V_49 ] . V_1189 ;
V_2 -> V_768 [ V_1218 ] = V_1189 ;
break;
}
}
return 0 ;
}
V_1085 = F_424 ( sizeof( * V_1085 ) , V_769 ) ;
if ( ! V_1085 )
return - V_584 ;
V_124 = F_424 ( sizeof( * V_124 ) , V_769 ) ;
if ( ! V_124 ) {
V_17 = - V_584 ;
goto V_1227;
}
if ( ( V_1186 != 0x800 ) && ( V_2 -> V_768 [ V_1186 ] ) ) {
if ( ( V_2 -> V_768 [ V_1186 ] ) -> V_1085 )
memcpy ( V_1085 , ( V_2 -> V_768 [ V_1186 ] ) -> V_1085 ,
sizeof( * V_1085 ) ) ;
if ( ( V_2 -> V_768 [ V_1186 ] ) -> V_124 )
memcpy ( V_124 , ( V_2 -> V_768 [ V_1186 ] ) -> V_124 ,
sizeof( * V_124 ) ) ;
for ( V_49 = 1 ; V_49 < V_772 ; V_49 ++ ) {
struct V_1188 * V_394 = V_2 -> V_768 [ V_49 ] ;
if ( V_394 && ( F_14 ( V_1187 - 1 , V_394 -> V_1191 ) ) ) {
F_108 ( V_162 , L_137 ,
V_1187 ) ;
V_17 = - V_596 ;
goto V_1228;
}
}
}
V_17 = F_628 ( V_1085 , V_124 , V_1182 , V_1204 , NULL ) ;
if ( V_17 )
goto V_1228;
V_17 = F_620 ( V_2 , V_1182 -> V_1184 . V_1199 , & V_1085 -> V_663 ,
& V_110 ) ;
if ( V_17 < 0 )
goto V_1228;
V_1085 -> V_662 = V_1187 ;
F_364 ( & V_2 -> V_659 ) ;
if ( F_365 ( & V_2 -> V_660 ) ) {
memcpy ( & V_2 -> V_661 , V_124 , sizeof( * V_124 ) ) ;
V_17 = F_366 ( V_14 , V_124 ) ;
if ( V_17 )
goto V_1229;
} else if ( memcmp ( & V_2 -> V_661 , V_124 , sizeof( * V_124 ) ) ) {
V_17 = - V_596 ;
goto V_1229;
}
F_630 ( & V_1085 -> V_658 , V_124 ) ;
V_17 = F_368 ( V_14 , & V_1085 -> V_658 ,
V_1085 -> V_662 , V_110 ) ;
if ( ! V_17 )
F_616 ( V_2 , V_1085 , V_1085 -> V_662 ) ;
F_369 ( & V_2 -> V_659 ) ;
if ( ( V_1186 != 0x800 ) && ( V_2 -> V_768 [ V_1186 ] ) )
F_97 ( V_1187 - 1 , ( V_2 -> V_768 [ V_1186 ] ) -> V_1191 ) ;
F_249 ( V_124 ) ;
return V_17 ;
V_1229:
F_369 ( & V_2 -> V_659 ) ;
V_1228:
F_249 ( V_124 ) ;
V_1227:
F_249 ( V_1085 ) ;
V_1226:
F_249 ( V_1189 ) ;
return V_17 ;
}
static int F_631 ( struct V_61 * V_80 , T_1 V_1185 , T_12 V_560 ,
struct V_1230 * V_141 )
{
struct V_1 * V_2 = F_93 ( V_80 ) ;
if ( F_632 ( V_1185 ) == F_632 ( V_1231 ) &&
V_141 -> type == V_1232 ) {
switch ( V_141 -> V_1233 -> V_1234 ) {
case V_1235 :
case V_1236 :
return F_629 ( V_2 ,
V_560 , V_141 -> V_1233 ) ;
case V_1237 :
return F_614 ( V_2 , V_141 -> V_1233 ) ;
case V_1238 :
case V_1239 :
return F_617 ( V_2 , V_560 ,
V_141 -> V_1233 ) ;
case V_1240 :
return F_618 ( V_2 ,
V_141 -> V_1233 ) ;
default:
return - V_596 ;
}
}
if ( V_141 -> type != V_1241 )
return - V_596 ;
return F_610 ( V_80 , V_141 -> V_141 ) ;
}
void F_633 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
F_464 () ;
F_610 ( V_62 , F_262 ( V_62 ) ) ;
F_466 () ;
}
void F_634 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
if ( F_61 ( V_62 ) )
F_397 ( V_2 ) ;
else
F_404 ( V_2 ) ;
}
static T_13 F_635 ( struct V_61 * V_62 ,
T_13 V_215 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
if ( ! ( V_215 & V_232 ) )
V_215 &= ~ V_1242 ;
if ( ! ( V_2 -> V_349 & V_760 ) )
V_215 &= ~ V_1242 ;
return V_215 ;
}
static int F_636 ( struct V_61 * V_62 ,
T_13 V_215 )
{
struct V_1 * V_2 = F_93 ( V_62 ) ;
T_13 V_1243 = V_62 -> V_215 ^ V_215 ;
bool V_1244 = false ;
if ( ! ( V_215 & V_1242 ) ) {
if ( V_2 -> V_349 & V_539 )
V_1244 = true ;
V_2 -> V_349 &= ~ V_539 ;
} else if ( ( V_2 -> V_349 & V_760 ) &&
! ( V_2 -> V_349 & V_539 ) ) {
if ( V_2 -> V_404 == 1 ||
V_2 -> V_404 > V_1245 ) {
V_2 -> V_349 |= V_539 ;
V_1244 = true ;
} else if ( ( V_1243 ^ V_215 ) & V_1242 ) {
F_110 ( V_187 , L_138
L_139 ) ;
}
}
if ( ( V_215 & V_1246 ) || ( V_215 & V_1247 ) ) {
if ( ! ( V_2 -> V_146 & V_651 ) )
V_1244 = true ;
V_2 -> V_146 &= ~ V_387 ;
V_2 -> V_146 |= V_651 ;
} else {
if ( V_2 -> V_146 & V_651 )
V_1244 = true ;
V_2 -> V_146 &= ~ V_651 ;
if ( V_2 -> V_146 & V_433 ||
( F_262 ( V_62 ) > 1 ) ||
( V_2 -> V_438 [ V_453 ] . V_759 <= 1 ) ||
( ! V_2 -> V_423 ) )
;
else
V_2 -> V_146 |= V_387 ;
}
if ( V_1243 & V_289 )
V_1244 = true ;
V_62 -> V_215 = V_215 ;
if ( ( V_2 -> V_146 & V_622 ) ) {
if ( V_215 & V_232 ) {
V_2 -> V_349 |= V_1014 ;
} else {
T_1 V_1248 = V_625 ;
F_344 ( V_2 , V_1248 ) ;
}
}
if ( ( V_2 -> V_146 & V_623 ) ) {
if ( V_215 & V_232 ) {
V_2 -> V_349 |= V_1014 ;
} else {
T_1 V_1248 = V_627 ;
F_344 ( V_2 , V_1248 ) ;
}
}
if ( V_1244 )
F_634 ( V_62 ) ;
else if ( V_1243 & ( V_264 |
V_616 ) )
F_335 ( V_62 ) ;
return 0 ;
}
static void F_637 ( struct V_61 * V_80 ,
struct V_1249 * V_407 )
{
struct V_1 * V_2 = F_93 ( V_80 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_12 V_1104 = V_407 -> V_1104 ;
T_1 V_1250 = 0 ;
T_1 V_3 ;
if ( V_407 -> V_1251 != V_1252 )
return;
switch ( V_407 -> type ) {
case V_1253 :
if ( ! ( V_2 -> V_146 & V_622 ) )
return;
if ( V_2 -> V_626 == V_1104 )
return;
if ( V_2 -> V_626 ) {
F_638 ( V_80 ,
L_140 ,
F_579 ( V_2 -> V_626 ) ,
F_579 ( V_1104 ) ) ;
return;
}
V_2 -> V_626 = V_1104 ;
break;
case V_1254 :
if ( ! ( V_2 -> V_146 & V_623 ) )
return;
if ( V_2 -> V_628 == V_1104 )
return;
if ( V_2 -> V_628 ) {
F_638 ( V_80 ,
L_141 ,
F_579 ( V_2 -> V_628 ) ,
F_579 ( V_1104 ) ) ;
return;
}
V_1250 = V_1255 ;
V_2 -> V_628 = V_1104 ;
break;
default:
return;
}
V_3 = F_40 ( V_14 , V_624 ) | F_579 ( V_1104 ) << V_1250 ;
F_75 ( V_14 , V_624 , V_3 ) ;
}
static void F_639 ( struct V_61 * V_80 ,
struct V_1249 * V_407 )
{
struct V_1 * V_2 = F_93 ( V_80 ) ;
T_1 V_1248 ;
if ( V_407 -> type != V_1253 &&
V_407 -> type != V_1254 )
return;
if ( V_407 -> V_1251 != V_1252 )
return;
switch ( V_407 -> type ) {
case V_1253 :
if ( ! ( V_2 -> V_146 & V_622 ) )
return;
if ( V_2 -> V_626 != V_407 -> V_1104 ) {
F_638 ( V_80 , L_142 ,
F_579 ( V_407 -> V_1104 ) ) ;
return;
}
V_1248 = V_625 ;
break;
case V_1254 :
if ( ! ( V_2 -> V_146 & V_623 ) )
return;
if ( V_2 -> V_628 != V_407 -> V_1104 ) {
F_638 ( V_80 , L_143 ,
F_579 ( V_407 -> V_1104 ) ) ;
return;
}
V_1248 = V_627 ;
break;
default:
return;
}
F_344 ( V_2 , V_1248 ) ;
V_2 -> V_349 |= V_1014 ;
}
static int F_640 ( struct V_1256 * V_1257 , struct V_1258 * V_1259 [] ,
struct V_61 * V_80 ,
const unsigned char * V_591 , T_2 V_266 ,
T_2 V_146 )
{
if ( F_641 ( V_591 ) || F_642 ( V_591 ) ) {
struct V_1 * V_2 = F_93 ( V_80 ) ;
T_2 V_497 = F_288 ( 0 ) ;
if ( F_329 ( V_80 ) >= F_321 ( V_2 , V_497 ) )
return - V_584 ;
}
return F_643 ( V_1257 , V_1259 , V_80 , V_591 , V_266 , V_146 ) ;
}
static int F_644 ( struct V_1 * V_2 ,
T_19 V_1260 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
unsigned int V_1147 , V_1261 ;
T_1 V_506 ;
switch ( V_1260 ) {
case V_1262 :
F_75 ( & V_2 -> V_14 , V_514 , 0 ) ;
V_506 = F_40 ( V_14 , V_1263 ) ;
V_506 |= V_511 ;
F_75 ( V_14 , V_1263 , V_506 ) ;
V_1261 = V_2 -> V_321 + V_2 -> V_676 ;
for ( V_1147 = 0 ; V_1147 < V_1261 ; V_1147 ++ ) {
if ( V_14 -> V_114 . V_355 . V_1264 )
V_14 -> V_114 . V_355 . V_1264 ( V_14 ,
true ,
V_1147 ) ;
}
break;
case V_513 :
F_75 ( & V_2 -> V_14 , V_514 ,
V_515 ) ;
V_506 = F_40 ( V_14 , V_1263 ) ;
if ( ! V_2 -> V_321 )
V_506 &= ~ V_511 ;
F_75 ( V_14 , V_1263 , V_506 ) ;
V_1261 = V_2 -> V_321 + V_2 -> V_676 ;
for ( V_1147 = 0 ; V_1147 < V_1261 ; V_1147 ++ ) {
if ( V_14 -> V_114 . V_355 . V_1264 )
V_14 -> V_114 . V_355 . V_1264 ( V_14 ,
false ,
V_1147 ) ;
}
break;
default:
return - V_596 ;
}
V_2 -> V_512 = V_1260 ;
F_110 ( V_162 , L_144 ,
V_1260 == V_1262 ? L_145 : L_146 ) ;
return 0 ;
}
static int F_645 ( struct V_61 * V_80 ,
struct V_1265 * V_1266 , T_2 V_146 )
{
struct V_1 * V_2 = F_93 ( V_80 ) ;
struct V_1258 * V_1267 , * V_1268 ;
int V_1269 ;
if ( ! ( V_2 -> V_146 & V_433 ) )
return - V_1270 ;
V_1268 = F_646 ( V_1266 , sizeof( struct V_1271 ) , V_1272 ) ;
if ( ! V_1268 )
return - V_596 ;
F_647 (attr, br_spec, rem) {
int V_180 ;
T_19 V_1260 ;
if ( F_648 ( V_1267 ) != V_1273 )
continue;
if ( F_649 ( V_1267 ) < sizeof( V_1260 ) )
return - V_596 ;
V_1260 = F_650 ( V_1267 ) ;
V_180 = F_644 ( V_2 , V_1260 ) ;
if ( V_180 )
return V_180 ;
break;
}
return 0 ;
}
static int F_651 ( struct V_213 * V_95 , T_1 V_1274 , T_1 V_1275 ,
struct V_61 * V_80 ,
T_1 V_1276 , int V_1277 )
{
struct V_1 * V_2 = F_93 ( V_80 ) ;
if ( ! ( V_2 -> V_146 & V_433 ) )
return 0 ;
return F_652 ( V_95 , V_1274 , V_1275 , V_80 ,
V_2 -> V_512 , 0 , 0 , V_1277 ,
V_1276 , NULL ) ;
}
static void * F_653 ( struct V_61 * V_9 , struct V_61 * V_669 )
{
struct V_665 * V_1117 = NULL ;
struct V_1 * V_2 = F_93 ( V_9 ) ;
int V_1278 = V_2 -> V_321 + V_2 -> V_676 ;
unsigned int V_759 ;
int V_497 , V_17 ;
if ( V_1278 >= V_1279 )
return F_654 ( - V_596 ) ;
#ifdef F_655
if ( V_669 -> V_99 != V_669 -> V_83 ) {
F_638 ( V_9 , L_147 ,
V_669 -> V_60 ) ;
return F_654 ( - V_596 ) ;
}
#endif
if ( V_669 -> V_83 > V_804 ||
V_669 -> V_83 == V_1280 ) {
F_638 ( V_9 ,
L_148 ,
V_9 -> V_60 ) ;
return F_654 ( - V_596 ) ;
}
if ( ( ( V_2 -> V_146 & V_147 ) &&
V_2 -> V_676 > V_1178 - 1 ) ||
( V_2 -> V_676 > V_1281 ) )
return F_654 ( - V_801 ) ;
V_1117 = F_424 ( sizeof( * V_1117 ) , V_769 ) ;
if ( ! V_1117 )
return F_654 ( - V_584 ) ;
V_497 = F_611 ( & V_2 -> V_675 , 32 ) ;
V_2 -> V_676 ++ ;
F_97 ( V_497 , & V_2 -> V_675 ) ;
V_759 = F_656 ( & V_2 -> V_675 , 32 ) ;
V_2 -> V_146 |= V_573 | V_433 ;
V_2 -> V_438 [ V_439 ] . V_759 = V_759 + 1 ;
V_2 -> V_438 [ V_453 ] . V_759 = V_669 -> V_83 ;
V_17 = F_610 ( V_9 , F_262 ( V_9 ) ) ;
if ( V_17 )
goto V_1282;
V_1117 -> V_497 = V_497 ;
V_1117 -> V_155 = V_2 ;
if ( F_61 ( V_9 ) ) {
V_17 = F_377 ( V_669 , V_1117 ) ;
if ( V_17 )
goto V_1282;
F_657 ( V_669 ) ;
}
return V_1117 ;
V_1282:
F_638 ( V_9 ,
L_149 , V_669 -> V_60 ) ;
F_37 ( V_497 , & V_2 -> V_675 ) ;
V_2 -> V_676 -- ;
F_249 ( V_1117 ) ;
return F_654 ( V_17 ) ;
}
static void F_658 ( struct V_61 * V_9 , void * V_1283 )
{
struct V_665 * V_1117 = V_1283 ;
struct V_1 * V_2 = V_1117 -> V_155 ;
unsigned int V_759 ;
F_37 ( V_1117 -> V_497 , & V_2 -> V_675 ) ;
V_2 -> V_676 -- ;
V_759 = F_656 ( & V_2 -> V_675 , 32 ) ;
V_2 -> V_438 [ V_439 ] . V_759 = V_759 + 1 ;
F_375 ( V_1117 -> V_62 , V_1117 ) ;
F_610 ( V_9 , F_262 ( V_9 ) ) ;
F_378 ( V_9 , L_91 ,
V_1117 -> V_497 , V_2 -> V_676 ,
V_1117 -> V_668 ,
V_1117 -> V_668 + V_2 -> V_667 ,
V_2 -> V_675 ) ;
F_249 ( V_1117 ) ;
}
static T_13
F_659 ( struct V_213 * V_95 , struct V_61 * V_80 ,
T_13 V_215 )
{
unsigned int V_1284 , V_1285 ;
V_1285 = F_536 ( V_95 ) - V_95 -> V_98 ;
if ( F_23 ( V_1285 > V_1286 ) )
return V_215 & ~ ( V_1287 |
V_1288 |
V_1289 |
V_1290 |
V_1291 ) ;
V_1284 = F_537 ( V_95 ) - F_536 ( V_95 ) ;
if ( F_23 ( V_1284 > V_1292 ) )
return V_215 & ~ ( V_1287 |
V_1288 |
V_1290 |
V_1291 ) ;
if ( V_95 -> V_234 && ! ( V_215 & V_1293 ) )
V_215 &= ~ V_1290 ;
return V_215 ;
}
static inline int F_660 ( struct V_1 * V_2 )
{
struct V_5 * V_409 , * V_9 = V_2 -> V_9 ;
int V_1294 = 0 ;
if ( F_8 ( & V_2 -> V_14 ) )
V_1294 = 4 ;
F_624 (entry, &adapter->pdev->bus->devices, bus_list) {
if ( V_409 -> V_1295 )
continue;
if ( ( V_409 -> V_752 != V_9 -> V_752 ) ||
( V_409 -> V_208 != V_9 -> V_208 ) )
return - 1 ;
V_1294 ++ ;
}
return V_1294 ;
}
bool F_661 ( struct V_1 * V_2 , T_2 V_21 ,
T_2 V_1296 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1297 = V_2 -> V_1298 & V_1299 ;
if ( V_14 -> V_114 . type == V_115 )
return false ;
if ( V_14 -> V_114 . type >= V_118 ) {
if ( ( V_1297 == V_1300 ) ||
( ( V_1297 == V_1301 ) &&
( V_14 -> V_10 . V_1302 == 0 ) ) )
return true ;
}
switch ( V_21 ) {
case V_1303 :
switch ( V_1296 ) {
case V_1304 :
case V_1305 :
case V_1306 :
case V_1307 :
if ( V_14 -> V_10 . V_1302 != 0 )
break;
case V_1308 :
case V_1309 :
case V_1310 :
case V_1311 :
case V_1312 :
case V_1313 :
case V_1314 :
return true ;
}
break;
case V_1315 :
switch ( V_1296 ) {
case V_1316 :
return true ;
}
break;
case V_1317 :
if ( V_1296 != V_1318 )
return true ;
break;
case V_1319 :
return true ;
default:
break;
}
return false ;
}
static int F_662 ( struct V_5 * V_9 , const struct V_1320 * V_1321 )
{
struct V_61 * V_62 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_14 ;
const struct V_1322 * V_1323 = V_1324 [ V_1321 -> V_1325 ] ;
int V_49 , V_17 , V_1326 , V_24 ;
unsigned int V_465 = V_1327 ;
T_4 V_1328 [ V_1329 ] ;
bool V_1330 = false ;
#ifdef F_181
T_2 V_1331 ;
#endif
T_1 V_1332 ;
if ( V_9 -> V_1295 ) {
F_663 ( 1 , V_1333 L_150 ,
F_518 ( V_9 ) , V_9 -> V_752 , V_9 -> V_208 ) ;
return - V_596 ;
}
V_17 = F_461 ( V_9 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_664 ( & V_9 -> V_80 , F_257 ( 64 ) ) ) {
V_1326 = 1 ;
} else {
V_17 = F_664 ( & V_9 -> V_80 , F_257 ( 32 ) ) ;
if ( V_17 ) {
F_437 ( & V_9 -> V_80 ,
L_151 ) ;
goto V_1334;
}
V_1326 = 0 ;
}
V_17 = F_665 ( V_9 , V_1335 ) ;
if ( V_17 ) {
F_437 ( & V_9 -> V_80 ,
L_152 , V_17 ) ;
goto V_1336;
}
F_666 ( V_9 ) ;
F_462 ( V_9 ) ;
F_460 ( V_9 ) ;
if ( V_1323 -> V_114 == V_115 ) {
#ifdef F_386
V_465 = 4 * V_649 ;
#else
V_465 = V_1337 ;
#endif
}
V_62 = F_667 ( sizeof( struct V_1 ) , V_465 ) ;
if ( ! V_62 ) {
V_17 = - V_584 ;
goto V_1338;
}
F_668 ( V_62 , & V_9 -> V_80 ) ;
V_2 = F_93 ( V_62 ) ;
V_2 -> V_62 = V_62 ;
V_2 -> V_9 = V_9 ;
V_14 = & V_2 -> V_14 ;
V_14 -> V_40 = V_2 ;
V_2 -> V_1339 = F_669 ( V_1340 , V_1341 ) ;
V_14 -> V_41 = F_670 ( F_671 ( V_9 , 0 ) ,
F_672 ( V_9 , 0 ) ) ;
V_2 -> V_422 = V_14 -> V_41 ;
if ( ! V_14 -> V_41 ) {
V_17 = - V_792 ;
goto V_1342;
}
V_62 -> V_1343 = & V_1344 ;
F_673 ( V_62 ) ;
V_62 -> V_1345 = 5 * V_1010 ;
F_674 ( V_62 -> V_60 , F_518 ( V_9 ) , sizeof( V_62 -> V_60 ) ) ;
V_14 -> V_114 . V_355 = * V_1323 -> V_1346 ;
V_14 -> V_114 . type = V_1323 -> V_114 ;
V_14 -> V_1347 = V_1323 -> V_1347 ;
V_14 -> V_1348 . V_355 = * V_1323 -> V_1349 ;
V_1332 = F_40 ( V_14 , F_675 ( V_14 ) ) ;
if ( F_22 ( V_14 -> V_41 ) ) {
V_17 = - V_792 ;
goto V_1342;
}
if ( ! ( V_1332 & F_206 ( 8 ) ) )
V_14 -> V_1348 . V_355 . V_253 = & V_1350 ;
V_14 -> V_46 . V_355 = * V_1323 -> V_1351 ;
V_14 -> V_46 . V_1006 = V_1352 ;
V_14 -> V_46 . V_1155 . V_1152 = V_1353 ;
V_14 -> V_46 . V_1155 . V_1354 = 0 ;
V_14 -> V_46 . V_1155 . V_1355 = V_1356 | V_1357 ;
V_14 -> V_46 . V_1155 . V_80 = V_62 ;
V_14 -> V_46 . V_1155 . V_1358 = F_589 ;
V_14 -> V_46 . V_1155 . V_1359 = F_590 ;
V_1323 -> V_1360 ( V_14 ) ;
V_17 = F_421 ( V_2 ) ;
if ( V_17 )
goto V_1361;
if ( V_14 -> V_114 . V_355 . V_1362 )
V_14 -> V_114 . V_355 . V_1362 ( V_14 ) ;
switch ( V_2 -> V_14 . V_114 . type ) {
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
F_75 ( & V_2 -> V_14 , V_810 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_146 & V_361 ) {
T_1 V_710 = F_40 ( V_14 , V_711 ) ;
if ( V_710 & V_712 )
F_214 ( V_187 , L_72 ) ;
}
if ( V_1363 )
V_14 -> V_1363 = V_1363 ;
V_14 -> V_46 . V_1364 = true ;
V_17 = V_14 -> V_114 . V_355 . V_1365 ( V_14 ) ;
V_14 -> V_46 . V_1364 = false ;
if ( V_17 == V_718 ) {
V_17 = 0 ;
} else if ( V_17 == V_719 ) {
F_18 ( L_153 ) ;
F_18 ( L_154 ) ;
goto V_1361;
} else if ( V_17 ) {
F_18 ( L_155 , V_17 ) ;
goto V_1361;
}
#ifdef F_315
if ( V_2 -> V_14 . V_114 . type == V_115 )
goto V_1366;
F_676 ( V_14 ) ;
V_14 -> V_1367 . V_355 = V_1323 -> V_1368 ;
F_677 ( V_9 , V_784 ) ;
F_678 ( V_2 ) ;
V_1366:
#endif
V_62 -> V_215 = V_1369 |
V_1290 |
V_1291 |
V_216 |
V_232 |
V_1287 ;
#define F_679 (NETIF_F_GSO_GRE | \
NETIF_F_GSO_GRE_CSUM | \
NETIF_F_GSO_IPXIP4 | \
NETIF_F_GSO_IPXIP6 | \
NETIF_F_GSO_UDP_TUNNEL | \
NETIF_F_GSO_UDP_TUNNEL_CSUM)
V_62 -> V_1370 = F_679 ;
V_62 -> V_215 |= V_1371 |
F_679 ;
if ( V_14 -> V_114 . type >= V_117 )
V_62 -> V_215 |= V_1288 ;
V_62 -> V_1372 |= V_62 -> V_215 |
V_616 |
V_264 |
V_1289 |
V_289 |
V_1373 ;
if ( V_14 -> V_114 . type >= V_117 )
V_62 -> V_1372 |= V_1246 |
V_1247 ;
if ( V_1326 )
V_62 -> V_215 |= V_1374 ;
V_62 -> V_1375 |= V_62 -> V_215 | V_1293 ;
V_62 -> V_1376 |= V_62 -> V_1375 ;
V_62 -> V_1377 |= V_1287 ;
V_62 -> V_215 |= V_616 |
V_264 |
V_1289 ;
V_62 -> V_1378 |= V_1379 ;
V_62 -> V_1378 |= V_1380 ;
#ifdef F_386
if ( V_2 -> V_146 & V_746 )
V_62 -> V_1381 = & V_1381 ;
#endif
#ifdef F_181
if ( V_2 -> V_146 & V_766 ) {
unsigned int V_1382 ;
if ( V_14 -> V_114 . V_355 . V_1383 ) {
V_14 -> V_114 . V_355 . V_1383 ( V_14 , & V_1331 ) ;
if ( V_1331 & V_1384 )
V_2 -> V_146 &= ~ V_766 ;
}
V_1382 = F_333 ( int , V_1385 , F_423 () ) ;
V_2 -> V_438 [ V_1123 ] . V_759 = V_1382 ;
V_62 -> V_215 |= V_1143 |
V_1144 ;
V_62 -> V_1375 |= V_1143 |
V_1144 |
V_629 ;
}
#endif
if ( V_2 -> V_349 & V_760 )
V_62 -> V_1372 |= V_1242 ;
if ( V_2 -> V_349 & V_539 )
V_62 -> V_215 |= V_1242 ;
if ( V_14 -> V_1348 . V_355 . V_1386 ( V_14 , NULL ) < 0 ) {
F_18 ( L_156 ) ;
V_17 = - V_792 ;
goto V_1361;
}
F_680 ( & V_2 -> V_9 -> V_80 ,
V_2 -> V_14 . V_114 . V_1387 ) ;
memcpy ( V_62 -> V_678 , V_14 -> V_114 . V_1387 , V_62 -> V_1151 ) ;
if ( ! F_381 ( V_62 -> V_678 ) ) {
F_18 ( L_157 ) ;
V_17 = - V_792 ;
goto V_1361;
}
F_325 ( V_14 -> V_114 . V_591 , V_14 -> V_114 . V_1387 ) ;
F_322 ( V_2 ) ;
F_681 ( & V_2 -> V_713 , & F_526 ,
( unsigned long ) V_2 ) ;
if ( F_22 ( V_14 -> V_41 ) ) {
V_17 = - V_792 ;
goto V_1361;
}
F_682 ( & V_2 -> V_39 , F_530 ) ;
F_97 ( V_42 , & V_2 -> V_35 ) ;
F_37 ( V_37 , & V_2 -> V_35 ) ;
V_17 = F_465 ( V_2 ) ;
if ( V_17 )
goto V_1361;
V_2 -> V_725 = 0 ;
V_14 -> V_1348 . V_355 . V_253 ( V_14 , 0x2c , & V_2 -> V_1298 ) ;
V_14 -> V_1388 = F_661 ( V_2 , V_9 -> V_208 ,
V_9 -> V_758 ) ;
if ( V_14 -> V_1388 )
V_2 -> V_725 = V_1389 ;
F_683 ( & V_2 -> V_9 -> V_80 , V_2 -> V_725 ) ;
V_14 -> V_1348 . V_355 . V_253 ( V_14 , 0x2e , & V_2 -> V_1390 ) ;
V_14 -> V_1348 . V_355 . V_253 ( V_14 , 0x2d , & V_2 -> V_1391 ) ;
if ( F_8 ( V_14 ) )
F_5 ( V_2 ) ;
else
V_14 -> V_114 . V_355 . V_1392 ( V_14 ) ;
switch ( V_14 -> V_114 . type ) {
case V_115 :
V_24 = F_243 ( F_660 ( V_2 ) * 10 , 16 ) ;
break;
default:
V_24 = F_660 ( V_2 ) * 10 ;
break;
}
if ( V_24 > 0 )
F_9 ( V_2 , V_24 ) ;
V_17 = F_684 ( V_14 , V_1328 , sizeof( V_1328 ) ) ;
if ( V_17 )
F_674 ( V_1328 , L_7 , sizeof( V_1328 ) ) ;
if ( F_218 ( V_14 ) && V_14 -> V_46 . V_1006 != V_1393 )
F_12 ( L_158 ,
V_14 -> V_114 . type , V_14 -> V_46 . type , V_14 -> V_46 . V_1006 ,
V_1328 ) ;
else
F_12 ( L_159 ,
V_14 -> V_114 . type , V_14 -> V_46 . type , V_1328 ) ;
F_12 ( L_160 , V_62 -> V_678 ) ;
V_17 = V_14 -> V_114 . V_355 . V_1394 ( V_14 ) ;
if ( V_17 == V_721 ) {
F_11 ( L_94
L_161
L_162
L_163
L_98
L_99 ) ;
}
strcpy ( V_62 -> V_60 , L_164 ) ;
V_17 = F_685 ( V_62 ) ;
if ( V_17 )
goto V_1395;
F_686 ( V_9 , V_2 ) ;
if ( V_14 -> V_114 . V_355 . V_730 )
V_14 -> V_114 . V_355 . V_730 ( V_14 ) ;
F_413 ( V_62 ) ;
#ifdef F_238
if ( F_131 ( & V_9 -> V_80 ) == 0 ) {
V_2 -> V_146 |= V_193 ;
F_128 ( V_2 ) ;
}
#endif
if ( V_2 -> V_146 & V_433 ) {
F_110 ( V_187 , L_165 , V_2 -> V_321 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_321 ; V_49 ++ )
F_687 ( V_9 , ( V_49 | 0x10000000 ) ) ;
}
if ( V_14 -> V_114 . V_355 . V_1396 )
V_14 -> V_114 . V_355 . V_1396 ( V_14 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_596 ( V_62 ) ;
F_12 ( L_71 , V_1397 ) ;
#ifdef F_688
if ( F_689 ( V_2 ) )
F_108 ( V_187 , L_166 ) ;
#endif
F_690 ( V_2 ) ;
if ( F_691 ( V_14 ) && F_218 ( V_14 ) && V_14 -> V_114 . V_355 . V_691 )
V_14 -> V_114 . V_355 . V_691 ( V_14 ,
V_958 | V_983 ,
true ) ;
return 0 ;
V_1395:
F_74 ( V_2 ) ;
F_471 ( V_2 ) ;
V_1361:
F_692 ( V_2 ) ;
V_2 -> V_349 &= ~ V_686 ;
F_693 ( V_2 -> V_422 ) ;
F_249 ( V_2 -> V_768 [ 0 ] ) ;
F_249 ( V_2 -> V_586 ) ;
V_1342:
V_1330 = ! F_15 ( V_809 , & V_2 -> V_35 ) ;
F_694 ( V_62 ) ;
V_1338:
F_695 ( V_9 ) ;
V_1336:
V_1334:
if ( ! V_2 || V_1330 )
F_472 ( V_9 ) ;
return V_17 ;
}
static void F_696 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_457 ( V_9 ) ;
struct V_61 * V_62 ;
bool V_1330 ;
int V_49 ;
if ( ! V_2 )
return;
V_62 = V_2 -> V_62 ;
F_697 ( V_2 ) ;
F_97 ( V_36 , & V_2 -> V_35 ) ;
F_698 ( & V_2 -> V_39 ) ;
#ifdef F_238
if ( V_2 -> V_146 & V_193 ) {
V_2 -> V_146 &= ~ V_193 ;
F_132 ( & V_9 -> V_80 ) ;
F_75 ( & V_2 -> V_14 , V_204 ,
V_206 ) ;
}
#endif
#ifdef F_688
F_699 ( V_2 ) ;
#endif
F_598 ( V_62 ) ;
#ifdef F_315
F_692 ( V_2 ) ;
#endif
if ( V_62 -> V_1007 == V_1008 )
F_524 ( V_62 ) ;
F_471 ( V_2 ) ;
F_74 ( V_2 ) ;
#ifdef F_700
F_249 ( V_2 -> V_145 ) ;
F_249 ( V_2 -> V_634 ) ;
#endif
F_693 ( V_2 -> V_422 ) ;
F_695 ( V_9 ) ;
F_12 ( L_167 ) ;
for ( V_49 = 0 ; V_49 < V_772 ; V_49 ++ ) {
if ( V_2 -> V_768 [ V_49 ] ) {
F_249 ( V_2 -> V_768 [ V_49 ] -> V_1085 ) ;
F_249 ( V_2 -> V_768 [ V_49 ] -> V_124 ) ;
}
F_249 ( V_2 -> V_768 [ V_49 ] ) ;
}
F_249 ( V_2 -> V_586 ) ;
V_1330 = ! F_15 ( V_809 , & V_2 -> V_35 ) ;
F_694 ( V_62 ) ;
F_701 ( V_9 ) ;
if ( V_1330 )
F_472 ( V_9 ) ;
}
static T_20 F_702 ( struct V_5 * V_9 ,
T_21 V_35 )
{
struct V_1 * V_2 = F_457 ( V_9 ) ;
struct V_61 * V_62 = V_2 -> V_62 ;
#ifdef F_315
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_1398 , * V_990 ;
T_1 V_1399 , V_1400 , V_1401 , V_1402 ;
int V_993 , V_1403 ;
T_2 V_1404 , V_1405 ;
if ( V_2 -> V_14 . V_114 . type == V_115 ||
V_2 -> V_321 == 0 )
goto V_1406;
V_1398 = V_9 -> V_10 -> V_12 ;
while ( V_1398 && ( F_703 ( V_1398 ) != V_1407 ) )
V_1398 = V_1398 -> V_10 -> V_12 ;
if ( ! V_1398 )
goto V_1406;
V_1403 = F_704 ( V_1398 , V_1408 ) ;
if ( ! V_1403 )
goto V_1406;
V_1399 = F_30 ( V_14 , V_1403 + V_1409 ) ;
V_1400 = F_30 ( V_14 , V_1403 + V_1409 + 4 ) ;
V_1401 = F_30 ( V_14 , V_1403 + V_1409 + 8 ) ;
V_1402 = F_30 ( V_14 , V_1403 + V_1409 + 12 ) ;
if ( F_22 ( V_14 -> V_41 ) )
goto V_1406;
V_1404 = V_1400 >> 16 ;
if ( ! ( V_1404 & 0x0080 ) )
goto V_1406;
V_1405 = V_1404 & 0x01 ;
if ( ( V_1405 & 1 ) == ( V_9 -> V_1410 & 1 ) ) {
unsigned int V_21 ;
V_993 = ( V_1404 & 0x7F ) >> 1 ;
F_18 ( L_168 , V_993 ) ;
F_18 ( L_169
L_170 ,
V_1399 , V_1400 , V_1401 , V_1402 ) ;
switch ( V_2 -> V_14 . V_114 . type ) {
case V_117 :
V_21 = V_1411 ;
break;
case V_118 :
V_21 = V_1412 ;
break;
case V_119 :
V_21 = V_1413 ;
break;
case V_120 :
V_21 = V_1414 ;
break;
case V_121 :
V_21 = V_1415 ;
break;
default:
V_21 = 0 ;
break;
}
V_990 = F_705 ( V_1416 , V_21 , NULL ) ;
while ( V_990 ) {
if ( V_990 -> V_1410 == ( V_1404 & 0xFF ) )
break;
V_990 = F_705 ( V_1416 ,
V_21 , V_990 ) ;
}
if ( V_990 ) {
F_516 ( V_2 , V_990 ) ;
F_706 ( V_990 ) ;
}
F_707 ( V_9 ) ;
}
V_2 -> V_1417 ++ ;
return V_1418 ;
V_1406:
#endif
if ( ! F_14 ( V_42 , & V_2 -> V_35 ) )
return V_1419 ;
F_464 () ;
F_470 ( V_62 ) ;
if ( V_35 == V_1420 ) {
F_466 () ;
return V_1419 ;
}
if ( F_61 ( V_62 ) )
F_401 ( V_2 ) ;
if ( ! F_15 ( V_809 , & V_2 -> V_35 ) )
F_472 ( V_9 ) ;
F_466 () ;
return V_1421 ;
}
static T_20 F_708 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_457 ( V_9 ) ;
T_20 V_1422 ;
int V_17 ;
if ( F_461 ( V_9 ) ) {
F_108 ( V_187 , L_171 ) ;
V_1422 = V_1419 ;
} else {
F_36 () ;
F_37 ( V_809 , & V_2 -> V_35 ) ;
V_2 -> V_14 . V_41 = V_2 -> V_422 ;
F_462 ( V_9 ) ;
F_459 ( V_9 ) ;
F_460 ( V_9 ) ;
F_463 ( V_9 , false ) ;
F_404 ( V_2 ) ;
F_75 ( & V_2 -> V_14 , V_810 , ~ 0 ) ;
V_1422 = V_1418 ;
}
V_17 = F_707 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_172
L_173 , V_17 ) ;
}
return V_1422 ;
}
static void F_709 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_457 ( V_9 ) ;
struct V_61 * V_62 = V_2 -> V_62 ;
#ifdef F_315
if ( V_2 -> V_1417 ) {
F_110 ( V_162 , L_174 ) ;
V_2 -> V_1417 -- ;
return;
}
#endif
if ( F_61 ( V_62 ) )
F_403 ( V_2 ) ;
F_467 ( V_62 ) ;
}
static int T_22 F_710 ( void )
{
int V_600 ;
F_54 ( L_175 , V_1423 , V_1424 ) ;
F_54 ( L_71 , V_1425 ) ;
V_38 = F_711 ( V_1335 ) ;
if ( ! V_38 ) {
F_55 ( L_176 , V_1335 ) ;
return - V_584 ;
}
F_712 () ;
V_600 = F_713 ( & V_1426 ) ;
if ( V_600 ) {
F_714 ( V_38 ) ;
F_715 () ;
return V_600 ;
}
#ifdef F_238
F_716 ( & V_1427 ) ;
#endif
return 0 ;
}
static void T_23 F_717 ( void )
{
#ifdef F_238
F_718 ( & V_1427 ) ;
#endif
F_719 ( & V_1426 ) ;
F_715 () ;
if ( V_38 ) {
F_714 ( V_38 ) ;
V_38 = NULL ;
}
}
static int F_720 ( struct V_1428 * V_1429 , unsigned long V_209 ,
void * V_1147 )
{
int V_1430 ;
V_1430 = F_721 ( & V_1426 . V_1431 , NULL , & V_209 ,
F_129 ) ;
return V_1430 ? V_1432 : V_1433 ;
}
