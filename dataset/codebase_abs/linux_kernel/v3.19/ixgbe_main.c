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
int V_25 = 0 ;
enum V_26 V_20 = V_27 ;
enum V_28 V_19 = V_29 ;
struct V_5 * V_9 ;
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
case V_30 :
V_25 = 2 * V_19 ;
break;
case V_31 :
V_25 = 4 * V_19 ;
break;
case V_32 :
V_25 = 8 * V_19 ;
break;
default:
F_11 ( L_1 ) ;
return;
}
F_12 ( L_2 ,
V_25 ) ;
F_12 ( L_3 ,
( V_20 == V_32 ? L_4 :
V_20 == V_31 ? L_5 :
V_20 == V_30 ? L_6 :
L_7 ) ,
V_19 ,
( V_20 == V_30 ? L_8 :
V_20 == V_31 ? L_8 :
V_20 == V_32 ? L_9 :
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
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) &&
! F_14 ( V_35 , & V_2 -> V_34 ) &&
! F_15 ( V_36 , & V_2 -> V_34 ) )
F_16 ( & V_2 -> V_37 ) ;
}
static void F_17 ( struct V_15 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_38 ;
if ( ! V_14 -> V_39 )
return;
V_14 -> V_39 = NULL ;
F_18 ( L_13 ) ;
if ( F_14 ( V_40 , & V_2 -> V_34 ) )
F_13 ( V_2 ) ;
}
static void F_19 ( struct V_15 * V_14 , T_1 V_3 )
{
T_1 V_4 ;
if ( V_3 == V_41 ) {
F_17 ( V_14 ) ;
return;
}
V_4 = F_20 ( V_14 , V_41 ) ;
if ( V_4 == V_42 )
F_17 ( V_14 ) ;
}
T_1 F_20 ( struct V_15 * V_14 , T_1 V_3 )
{
T_4 T_5 * V_43 = F_21 ( V_14 -> V_39 ) ;
T_1 V_4 ;
if ( F_22 ( V_43 ) )
return V_42 ;
V_4 = F_23 ( V_43 + V_3 ) ;
if ( F_24 ( V_4 == V_42 ) )
F_19 ( V_14 , V_3 ) ;
return V_4 ;
}
static bool F_4 ( struct V_15 * V_14 , struct V_5 * V_9 )
{
T_2 V_4 ;
F_25 ( V_9 , V_44 , & V_4 ) ;
if ( V_4 == V_13 ) {
F_17 ( V_14 ) ;
return true ;
}
return false ;
}
T_2 F_26 ( struct V_15 * V_14 , T_1 V_3 )
{
struct V_1 * V_2 = V_14 -> V_38 ;
T_2 V_4 ;
if ( F_22 ( V_14 -> V_39 ) )
return V_13 ;
F_25 ( V_2 -> V_9 , V_3 , & V_4 ) ;
if ( V_4 == V_13 &&
F_4 ( V_14 , V_2 -> V_9 ) )
return V_13 ;
return V_4 ;
}
static T_1 F_27 ( struct V_15 * V_14 , T_1 V_3 )
{
struct V_1 * V_2 = V_14 -> V_38 ;
T_1 V_4 ;
if ( F_22 ( V_14 -> V_39 ) )
return V_45 ;
F_28 ( V_2 -> V_9 , V_3 , & V_4 ) ;
if ( V_4 == V_45 &&
F_4 ( V_14 , V_2 -> V_9 ) )
return V_45 ;
return V_4 ;
}
void F_29 ( struct V_15 * V_14 , T_1 V_3 , T_2 V_4 )
{
struct V_1 * V_2 = V_14 -> V_38 ;
if ( F_22 ( V_14 -> V_39 ) )
return;
F_30 ( V_2 -> V_9 , V_3 , V_4 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_32 ( ! F_14 ( V_36 , & V_2 -> V_34 ) ) ;
F_33 () ;
F_34 ( V_36 , & V_2 -> V_34 ) ;
}
static void F_35 ( struct V_15 * V_14 , struct V_46 * V_47 )
{
int V_48 = 0 , V_49 = 0 ;
char V_50 [ 16 ] ;
T_1 V_51 [ 64 ] ;
switch ( V_47 -> V_52 ) {
case F_36 ( 0 ) :
for ( V_48 = 0 ; V_48 < 64 ; V_48 ++ )
V_51 [ V_48 ] = F_37 ( V_14 , F_36 ( V_48 ) ) ;
break;
case F_38 ( 0 ) :
for ( V_48 = 0 ; V_48 < 64 ; V_48 ++ )
V_51 [ V_48 ] = F_37 ( V_14 , F_38 ( V_48 ) ) ;
break;
case F_39 ( 0 ) :
for ( V_48 = 0 ; V_48 < 64 ; V_48 ++ )
V_51 [ V_48 ] = F_37 ( V_14 , F_39 ( V_48 ) ) ;
break;
case F_40 ( 0 ) :
for ( V_48 = 0 ; V_48 < 64 ; V_48 ++ )
V_51 [ V_48 ] = F_37 ( V_14 , F_40 ( V_48 ) ) ;
break;
case F_41 ( 0 ) :
for ( V_48 = 0 ; V_48 < 64 ; V_48 ++ )
V_51 [ V_48 ] = F_37 ( V_14 , F_41 ( V_48 ) ) ;
break;
case F_42 ( 0 ) :
for ( V_48 = 0 ; V_48 < 64 ; V_48 ++ )
V_51 [ V_48 ] = F_37 ( V_14 , F_42 ( V_48 ) ) ;
break;
case F_43 ( 0 ) :
for ( V_48 = 0 ; V_48 < 64 ; V_48 ++ )
V_51 [ V_48 ] = F_37 ( V_14 , F_43 ( V_48 ) ) ;
break;
case F_44 ( 0 ) :
for ( V_48 = 0 ; V_48 < 64 ; V_48 ++ )
V_51 [ V_48 ] = F_37 ( V_14 , F_44 ( V_48 ) ) ;
break;
case F_45 ( 0 ) :
for ( V_48 = 0 ; V_48 < 64 ; V_48 ++ )
V_51 [ V_48 ] = F_37 ( V_14 , F_45 ( V_48 ) ) ;
break;
case F_46 ( 0 ) :
for ( V_48 = 0 ; V_48 < 64 ; V_48 ++ )
V_51 [ V_48 ] = F_37 ( V_14 , F_46 ( V_48 ) ) ;
break;
case F_47 ( 0 ) :
for ( V_48 = 0 ; V_48 < 64 ; V_48 ++ )
V_51 [ V_48 ] = F_37 ( V_14 , F_47 ( V_48 ) ) ;
break;
case F_48 ( 0 ) :
for ( V_48 = 0 ; V_48 < 64 ; V_48 ++ )
V_51 [ V_48 ] = F_37 ( V_14 , F_48 ( V_48 ) ) ;
break;
case F_49 ( 0 ) :
for ( V_48 = 0 ; V_48 < 64 ; V_48 ++ )
V_51 [ V_48 ] = F_37 ( V_14 , F_49 ( V_48 ) ) ;
break;
case F_50 ( 0 ) :
for ( V_48 = 0 ; V_48 < 64 ; V_48 ++ )
V_51 [ V_48 ] = F_37 ( V_14 , F_50 ( V_48 ) ) ;
break;
default:
F_51 ( L_14 , V_47 -> V_53 ,
F_37 ( V_14 , V_47 -> V_52 ) ) ;
return;
}
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ ) {
snprintf ( V_50 , 16 , L_15 , V_47 -> V_53 , V_48 * 8 , V_48 * 8 + 7 ) ;
F_52 ( L_16 , V_50 ) ;
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ )
F_53 ( L_17 , V_51 [ V_48 * 8 + V_49 ] ) ;
F_53 ( L_18 ) ;
}
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_46 * V_47 ;
int V_56 = 0 ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
union V_61 * V_62 ;
struct V_63 { T_6 V_64 ; T_6 V_65 ; } * V_66 ;
struct V_57 * V_67 ;
union V_68 * V_69 ;
struct V_70 * V_71 ;
T_1 V_72 ;
int V_48 = 0 ;
if ( ! F_55 ( V_2 ) )
return;
if ( V_55 ) {
F_56 ( & V_2 -> V_9 -> V_73 , L_19 ) ;
F_51 ( L_20
L_21 ) ;
F_51 ( L_22 ,
V_55 -> V_53 ,
V_55 -> V_34 ,
V_55 -> V_74 ,
V_55 -> V_75 ) ;
}
F_56 ( & V_2 -> V_9 -> V_73 , L_23 ) ;
F_51 ( L_24 ) ;
for ( V_47 = (struct V_46 * ) V_76 ;
V_47 -> V_53 ; V_47 ++ ) {
F_35 ( V_14 , V_47 ) ;
}
if ( ! V_55 || ! F_57 ( V_55 ) )
return;
F_56 ( & V_2 -> V_9 -> V_73 , L_25 ) ;
F_51 ( L_26 ,
L_27 ,
L_28 , L_29 , L_30 ) ;
for ( V_56 = 0 ; V_56 < V_2 -> V_77 ; V_56 ++ ) {
V_58 = V_2 -> V_58 [ V_56 ] ;
V_60 = & V_58 -> V_78 [ V_58 -> V_79 ] ;
F_51 ( L_31 ,
V_56 , V_58 -> V_80 , V_58 -> V_79 ,
( T_6 ) F_58 ( V_60 , V_81 ) ,
F_59 ( V_60 , V_82 ) ,
V_60 -> V_83 ,
( T_6 ) V_60 -> V_84 ) ;
}
if ( ! F_60 ( V_2 ) )
goto V_85;
F_56 ( & V_2 -> V_9 -> V_73 , L_32 ) ;
for ( V_56 = 0 ; V_56 < V_2 -> V_77 ; V_56 ++ ) {
V_58 = V_2 -> V_58 [ V_56 ] ;
F_51 ( L_33 ) ;
F_51 ( L_34 , V_58 -> V_86 ) ;
F_51 ( L_33 ) ;
F_51 ( L_35 ,
L_36 ,
L_37 ,
L_28 , L_29 , L_30 , L_38 ) ;
for ( V_48 = 0 ; V_58 -> V_87 && ( V_48 < V_58 -> V_88 ) ; V_48 ++ ) {
V_62 = F_61 ( V_58 , V_48 ) ;
V_60 = & V_58 -> V_78 [ V_48 ] ;
V_66 = (struct V_63 * ) V_62 ;
if ( F_59 ( V_60 , V_82 ) > 0 ) {
F_51 ( L_39 ,
V_48 ,
F_62 ( V_66 -> V_64 ) ,
F_62 ( V_66 -> V_65 ) ,
( T_6 ) F_58 ( V_60 , V_81 ) ,
F_59 ( V_60 , V_82 ) ,
V_60 -> V_83 ,
( T_6 ) V_60 -> V_84 ,
V_60 -> V_89 ) ;
if ( V_48 == V_58 -> V_80 &&
V_48 == V_58 -> V_79 )
F_53 ( L_40 ) ;
else if ( V_48 == V_58 -> V_80 )
F_53 ( L_41 ) ;
else if ( V_48 == V_58 -> V_79 )
F_53 ( L_42 ) ;
else
F_53 ( L_18 ) ;
if ( F_63 ( V_2 ) &&
V_60 -> V_89 )
F_64 ( V_90 , L_43 ,
V_91 , 16 , 1 ,
V_60 -> V_89 -> V_92 ,
F_59 ( V_60 , V_82 ) ,
true ) ;
}
}
}
V_85:
F_56 ( & V_2 -> V_9 -> V_73 , L_44 ) ;
F_51 ( L_45 ) ;
for ( V_56 = 0 ; V_56 < V_2 -> V_93 ; V_56 ++ ) {
V_67 = V_2 -> V_67 [ V_56 ] ;
F_51 ( L_46 ,
V_56 , V_67 -> V_80 , V_67 -> V_79 ) ;
}
if ( ! F_65 ( V_2 ) )
return;
F_56 ( & V_2 -> V_9 -> V_73 , L_47 ) ;
for ( V_56 = 0 ; V_56 < V_2 -> V_93 ; V_56 ++ ) {
V_67 = V_2 -> V_67 [ V_56 ] ;
F_51 ( L_33 ) ;
F_51 ( L_48 , V_67 -> V_86 ) ;
F_51 ( L_33 ) ;
F_51 ( L_49 ,
L_50 ,
L_51 ,
L_52 ) ;
F_51 ( L_49 ,
L_53 ,
L_54 ,
L_55 ) ;
for ( V_48 = 0 ; V_48 < V_67 -> V_88 ; V_48 ++ ) {
V_71 = & V_67 -> V_71 [ V_48 ] ;
V_69 = F_66 ( V_67 , V_48 ) ;
V_66 = (struct V_63 * ) V_69 ;
V_72 = F_67 ( V_69 -> V_94 . V_95 . V_96 ) ;
if ( V_72 & V_97 ) {
F_51 ( L_56
L_57 , V_48 ,
F_62 ( V_66 -> V_64 ) ,
F_62 ( V_66 -> V_65 ) ,
V_71 -> V_89 ) ;
} else {
F_51 ( L_58
L_59 , V_48 ,
F_62 ( V_66 -> V_64 ) ,
F_62 ( V_66 -> V_65 ) ,
( T_6 ) V_71 -> V_81 ,
V_71 -> V_89 ) ;
if ( F_63 ( V_2 ) &&
V_71 -> V_81 ) {
F_64 ( V_90 , L_43 ,
V_91 , 16 , 1 ,
F_68 ( V_71 -> V_98 ) +
V_71 -> V_99 ,
F_69 ( V_67 ) , true ) ;
}
}
if ( V_48 == V_67 -> V_80 )
F_53 ( L_41 ) ;
else if ( V_48 == V_67 -> V_79 )
F_53 ( L_42 ) ;
else
F_53 ( L_18 ) ;
}
}
}
static void F_70 ( struct V_1 * V_2 )
{
T_1 V_100 ;
V_100 = F_37 ( & V_2 -> V_14 , V_101 ) ;
F_71 ( & V_2 -> V_14 , V_101 ,
V_100 & ~ V_102 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
T_1 V_100 ;
V_100 = F_37 ( & V_2 -> V_14 , V_101 ) ;
F_71 ( & V_2 -> V_14 , V_101 ,
V_100 | V_102 ) ;
}
static void F_73 ( struct V_1 * V_2 , T_7 V_103 ,
T_4 V_104 , T_4 V_105 )
{
T_1 V_106 , V_107 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_105 |= V_110 ;
if ( V_103 == - 1 )
V_103 = 0 ;
V_107 = ( ( ( V_103 * 64 ) + V_104 ) >> 2 ) & 0x1F ;
V_106 = F_37 ( V_14 , F_74 ( V_107 ) ) ;
V_106 &= ~ ( 0xFF << ( 8 * ( V_104 & 0x3 ) ) ) ;
V_106 |= ( V_105 << ( 8 * ( V_104 & 0x3 ) ) ) ;
F_71 ( V_14 , F_74 ( V_107 ) , V_106 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
if ( V_103 == - 1 ) {
V_105 |= V_110 ;
V_107 = ( ( V_104 & 1 ) * 8 ) ;
V_106 = F_37 ( & V_2 -> V_14 , V_115 ) ;
V_106 &= ~ ( 0xFF << V_107 ) ;
V_106 |= ( V_105 << V_107 ) ;
F_71 ( & V_2 -> V_14 , V_115 , V_106 ) ;
break;
} else {
V_105 |= V_110 ;
V_107 = ( ( 16 * ( V_104 & 1 ) ) + ( 8 * V_103 ) ) ;
V_106 = F_37 ( V_14 , F_74 ( V_104 >> 1 ) ) ;
V_106 &= ~ ( 0xFF << V_107 ) ;
V_106 |= ( V_105 << V_107 ) ;
F_71 ( V_14 , F_74 ( V_104 >> 1 ) , V_106 ) ;
break;
}
default:
break;
}
}
static inline void F_75 ( struct V_1 * V_2 ,
T_6 V_116 )
{
T_1 V_117 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
V_117 = ( V_118 & V_116 ) ;
F_71 ( & V_2 -> V_14 , V_119 , V_117 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_117 = ( V_116 & 0xFFFFFFFF ) ;
F_71 ( & V_2 -> V_14 , F_76 ( 0 ) , V_117 ) ;
V_117 = ( V_116 >> 32 ) ;
F_71 ( & V_2 -> V_14 , F_76 ( 1 ) , V_117 ) ;
break;
default:
break;
}
}
void F_77 ( struct V_57 * V_120 ,
struct V_59 * V_60 )
{
if ( V_60 -> V_89 ) {
F_78 ( V_60 -> V_89 ) ;
if ( F_59 ( V_60 , V_82 ) )
F_79 ( V_120 -> V_73 ,
F_58 ( V_60 , V_81 ) ,
F_59 ( V_60 , V_82 ) ,
V_121 ) ;
} else if ( F_59 ( V_60 , V_82 ) ) {
F_80 ( V_120 -> V_73 ,
F_58 ( V_60 , V_81 ) ,
F_59 ( V_60 , V_82 ) ,
V_121 ) ;
}
V_60 -> V_83 = NULL ;
V_60 -> V_89 = NULL ;
F_81 ( V_60 , V_82 , 0 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_122 * V_123 = & V_2 -> V_124 ;
int V_48 ;
T_1 V_92 ;
if ( ( V_14 -> V_125 . V_126 != V_127 ) &&
( V_14 -> V_125 . V_126 != V_128 ) )
return;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_92 = F_37 ( V_14 , V_129 ) ;
break;
default:
V_92 = F_37 ( V_14 , V_130 ) ;
}
V_123 -> V_131 += V_92 ;
if ( ! V_92 )
return;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_34 ( V_132 ,
& V_2 -> V_58 [ V_48 ] -> V_34 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_122 * V_123 = & V_2 -> V_124 ;
T_1 V_133 [ 8 ] = { 0 } ;
T_4 V_134 ;
int V_48 ;
bool V_135 = V_2 -> V_136 . V_137 ;
if ( V_2 -> V_138 )
V_135 |= ! ! ( V_2 -> V_138 -> V_135 ) ;
if ( ! ( V_2 -> V_139 & V_140 ) || ! V_135 ) {
F_82 ( V_2 ) ;
return;
}
for ( V_48 = 0 ; V_48 < V_141 ; V_48 ++ ) {
T_1 V_142 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_142 = F_37 ( V_14 , F_84 ( V_48 ) ) ;
break;
default:
V_142 = F_37 ( V_14 , F_85 ( V_48 ) ) ;
}
V_123 -> V_142 [ V_48 ] += V_142 ;
V_134 = F_86 ( V_2 -> V_55 , V_48 ) ;
V_133 [ V_134 ] += V_142 ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_58 = V_2 -> V_58 [ V_48 ] ;
V_134 = V_58 -> V_143 ;
if ( V_133 [ V_134 ] )
F_34 ( V_132 , & V_58 -> V_34 ) ;
}
}
static T_6 F_87 ( struct V_57 * V_120 )
{
return V_120 -> V_124 . V_144 ;
}
static T_6 F_88 ( struct V_57 * V_120 )
{
struct V_1 * V_2 ;
struct V_15 * V_14 ;
T_1 V_145 , V_146 ;
if ( V_120 -> V_147 )
V_2 = V_120 -> V_147 -> V_148 ;
else
V_2 = F_89 ( V_120 -> V_55 ) ;
V_14 = & V_2 -> V_14 ;
V_145 = F_37 ( V_14 , F_48 ( V_120 -> V_149 ) ) ;
V_146 = F_37 ( V_14 , F_49 ( V_120 -> V_149 ) ) ;
if ( V_145 != V_146 )
return ( V_145 < V_146 ) ?
V_146 - V_145 : ( V_146 + V_120 -> V_88 - V_145 ) ;
return 0 ;
}
static inline bool F_90 ( struct V_57 * V_58 )
{
T_1 V_150 = F_87 ( V_58 ) ;
T_1 V_151 = V_58 -> V_152 . V_151 ;
T_1 V_153 = F_88 ( V_58 ) ;
F_91 ( V_58 ) ;
if ( V_151 == V_150 && V_153 )
return F_15 ( V_132 ,
& V_58 -> V_34 ) ;
V_58 -> V_152 . V_151 = V_150 ;
F_34 ( V_132 , & V_58 -> V_34 ) ;
return false ;
}
static void F_92 ( struct V_1 * V_2 )
{
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_154 |= V_155 ;
F_93 ( V_156 , L_60 ) ;
F_13 ( V_2 ) ;
}
}
static bool F_94 ( struct V_157 * V_158 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = V_158 -> V_2 ;
struct V_59 * V_60 ;
union V_61 * V_62 ;
unsigned int V_159 = 0 , V_160 = 0 ;
unsigned int V_161 = V_158 -> V_162 . V_163 ;
unsigned int V_48 = V_58 -> V_79 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return true ;
V_60 = & V_58 -> V_78 [ V_48 ] ;
V_62 = F_61 ( V_58 , V_48 ) ;
V_48 -= V_58 -> V_88 ;
do {
union V_61 * V_164 = V_60 -> V_83 ;
if ( ! V_164 )
break;
F_95 () ;
if ( ! ( V_164 -> V_94 . V_165 & F_96 ( V_166 ) ) )
break;
V_60 -> V_83 = NULL ;
V_159 += V_60 -> V_167 ;
V_160 += V_60 -> V_168 ;
F_97 ( V_60 -> V_89 ) ;
F_79 ( V_58 -> V_73 ,
F_58 ( V_60 , V_81 ) ,
F_59 ( V_60 , V_82 ) ,
V_121 ) ;
V_60 -> V_89 = NULL ;
F_81 ( V_60 , V_82 , 0 ) ;
while ( V_62 != V_164 ) {
V_60 ++ ;
V_62 ++ ;
V_48 ++ ;
if ( F_24 ( ! V_48 ) ) {
V_48 -= V_58 -> V_88 ;
V_60 = V_58 -> V_78 ;
V_62 = F_61 ( V_58 , 0 ) ;
}
if ( F_59 ( V_60 , V_82 ) ) {
F_80 ( V_58 -> V_73 ,
F_58 ( V_60 , V_81 ) ,
F_59 ( V_60 , V_82 ) ,
V_121 ) ;
F_81 ( V_60 , V_82 , 0 ) ;
}
}
V_60 ++ ;
V_62 ++ ;
V_48 ++ ;
if ( F_24 ( ! V_48 ) ) {
V_48 -= V_58 -> V_88 ;
V_60 = V_58 -> V_78 ;
V_62 = F_61 ( V_58 , 0 ) ;
}
F_98 ( V_62 ) ;
V_161 -- ;
} while ( F_99 ( V_161 ) );
V_48 += V_58 -> V_88 ;
V_58 -> V_79 = V_48 ;
F_100 ( & V_58 -> V_169 ) ;
V_58 -> V_124 . V_170 += V_159 ;
V_58 -> V_124 . V_144 += V_160 ;
F_101 ( & V_58 -> V_169 ) ;
V_158 -> V_162 . V_159 += V_159 ;
V_158 -> V_162 . V_160 += V_160 ;
if ( F_102 ( V_58 ) && F_90 ( V_58 ) ) {
struct V_15 * V_14 = & V_2 -> V_14 ;
F_103 ( V_156 , L_61
L_62
L_63
L_64
L_65
L_66
L_67
L_68 ,
V_58 -> V_86 ,
F_37 ( V_14 , F_48 ( V_58 -> V_149 ) ) ,
F_37 ( V_14 , F_49 ( V_58 -> V_149 ) ) ,
V_58 -> V_80 , V_48 ,
V_58 -> V_78 [ V_48 ] . V_84 , V_171 ) ;
F_104 ( V_58 -> V_55 , V_58 -> V_86 ) ;
F_105 ( V_172 ,
L_69 ,
V_2 -> V_173 + 1 , V_58 -> V_86 ) ;
F_92 ( V_2 ) ;
return true ;
}
F_106 ( F_107 ( V_58 ) ,
V_160 , V_159 ) ;
#define F_108 (DESC_NEEDED * 2)
if ( F_24 ( V_160 && F_109 ( V_58 -> V_55 ) &&
( F_110 ( V_58 ) >= F_108 ) ) ) {
F_111 () ;
if ( F_112 ( V_58 -> V_55 ,
V_58 -> V_86 )
&& ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
F_113 ( V_58 -> V_55 ,
V_58 -> V_86 ) ;
++ V_58 -> V_152 . V_174 ;
}
}
return ! ! V_161 ;
}
static void F_114 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
int V_175 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_176 = F_115 ( V_58 -> V_73 , V_175 ) ;
T_2 V_177 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_177 = F_116 ( V_58 -> V_149 ) ;
break;
case V_111 :
case V_112 :
V_177 = F_117 ( V_58 -> V_149 ) ;
V_176 <<= V_178 ;
break;
default:
return;
}
V_176 |= V_179 |
V_180 |
V_181 ;
F_71 ( V_14 , V_177 , V_176 ) ;
}
static void F_118 ( struct V_1 * V_2 ,
struct V_57 * V_67 ,
int V_175 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_182 = F_115 ( V_67 -> V_73 , V_175 ) ;
T_4 V_149 = V_67 -> V_149 ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
V_182 <<= V_183 ;
break;
default:
break;
}
V_182 |= V_184 |
V_185 ;
F_71 ( V_14 , F_38 ( V_149 ) , V_182 ) ;
}
static void F_119 ( struct V_157 * V_158 )
{
struct V_1 * V_2 = V_158 -> V_2 ;
struct V_57 * V_120 ;
int V_175 = F_120 () ;
if ( V_158 -> V_175 == V_175 )
goto V_186;
F_121 (ring, q_vector->tx)
F_114 ( V_2 , V_120 , V_175 ) ;
F_121 (ring, q_vector->rx)
F_118 ( V_2 , V_120 , V_175 ) ;
V_158 -> V_175 = V_175 ;
V_186:
F_122 () ;
}
static void F_123 ( struct V_1 * V_2 )
{
int V_48 ;
if ( ! ( V_2 -> V_139 & V_187 ) )
return;
F_71 ( & V_2 -> V_14 , V_188 , 2 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_189 ; V_48 ++ ) {
V_2 -> V_158 [ V_48 ] -> V_175 = - 1 ;
F_119 ( V_2 -> V_158 [ V_48 ] ) ;
}
}
static int F_124 ( struct V_190 * V_73 , void * V_92 )
{
struct V_1 * V_2 = F_125 ( V_73 ) ;
unsigned long V_191 = * ( unsigned long * ) V_92 ;
if ( ! ( V_2 -> V_139 & V_192 ) )
return 0 ;
switch ( V_191 ) {
case V_193 :
if ( V_2 -> V_139 & V_187 )
break;
if ( F_126 ( V_73 ) == 0 ) {
V_2 -> V_139 |= V_187 ;
F_123 ( V_2 ) ;
break;
}
case V_194 :
if ( V_2 -> V_139 & V_187 ) {
F_127 ( V_73 ) ;
V_2 -> V_139 &= ~ V_187 ;
F_71 ( & V_2 -> V_14 , V_188 , 1 ) ;
}
break;
}
return 0 ;
}
static inline void F_128 ( struct V_57 * V_120 ,
union V_68 * V_69 ,
struct V_195 * V_89 )
{
if ( V_120 -> V_55 -> V_196 & V_197 )
F_129 ( V_89 ,
F_67 ( V_69 -> V_94 . V_198 . V_199 . V_200 ) ,
V_201 ) ;
}
static inline bool F_130 ( struct V_57 * V_120 ,
union V_68 * V_69 )
{
T_8 V_202 = V_69 -> V_94 . V_198 . V_203 . V_204 . V_202 ;
return F_14 ( V_205 , & V_120 -> V_34 ) &&
( ( V_202 & F_131 ( V_206 ) ) ==
( F_131 ( V_207 <<
V_208 ) ) ) ;
}
static inline void F_132 ( struct V_57 * V_120 ,
union V_68 * V_69 ,
struct V_195 * V_89 )
{
F_133 ( V_89 ) ;
if ( ! ( V_120 -> V_55 -> V_196 & V_209 ) )
return;
if ( F_134 ( V_69 , V_210 ) &&
F_134 ( V_69 , V_211 ) ) {
V_120 -> V_212 . V_213 ++ ;
return;
}
if ( ! F_134 ( V_69 , V_214 ) )
return;
if ( F_134 ( V_69 , V_215 ) ) {
T_8 V_202 = V_69 -> V_94 . V_198 . V_203 . V_204 . V_202 ;
if ( ( V_202 & F_131 ( V_216 ) ) &&
F_14 ( V_217 , & V_120 -> V_34 ) )
return;
V_120 -> V_212 . V_213 ++ ;
return;
}
V_89 -> V_218 = V_219 ;
}
static bool F_135 ( struct V_57 * V_67 ,
struct V_70 * V_220 )
{
struct V_98 * V_98 = V_220 -> V_98 ;
T_9 V_81 ;
if ( F_99 ( V_98 ) )
return true ;
V_98 = F_136 ( F_137 ( V_67 ) ) ;
if ( F_24 ( ! V_98 ) ) {
V_67 -> V_212 . V_221 ++ ;
return false ;
}
V_81 = F_138 ( V_67 -> V_73 , V_98 , 0 ,
F_139 ( V_67 ) , V_222 ) ;
if ( F_140 ( V_67 -> V_73 , V_81 ) ) {
F_141 ( V_98 , F_137 ( V_67 ) ) ;
V_67 -> V_212 . V_221 ++ ;
return false ;
}
V_220 -> V_81 = V_81 ;
V_220 -> V_98 = V_98 ;
V_220 -> V_99 = 0 ;
return true ;
}
void F_142 ( struct V_57 * V_67 , T_2 V_223 )
{
union V_68 * V_69 ;
struct V_70 * V_220 ;
T_2 V_48 = V_67 -> V_80 ;
if ( ! V_223 )
return;
V_69 = F_66 ( V_67 , V_48 ) ;
V_220 = & V_67 -> V_71 [ V_48 ] ;
V_48 -= V_67 -> V_88 ;
do {
if ( ! F_135 ( V_67 , V_220 ) )
break;
V_69 -> V_224 . V_225 = F_143 ( V_220 -> V_81 + V_220 -> V_99 ) ;
V_69 ++ ;
V_220 ++ ;
V_48 ++ ;
if ( F_24 ( ! V_48 ) ) {
V_69 = F_66 ( V_67 , 0 ) ;
V_220 = V_67 -> V_71 ;
V_48 -= V_67 -> V_88 ;
}
V_69 -> V_94 . V_95 . V_96 = 0 ;
V_223 -- ;
} while ( V_223 );
V_48 += V_67 -> V_88 ;
if ( V_67 -> V_80 != V_48 ) {
V_67 -> V_80 = V_48 ;
V_67 -> V_226 = V_48 ;
F_144 () ;
F_145 ( V_48 , V_67 -> V_146 ) ;
}
}
static void F_146 ( struct V_57 * V_120 ,
struct V_195 * V_89 )
{
T_2 V_227 = F_147 ( V_89 ) ;
F_148 ( V_89 ) -> V_228 = F_149 ( ( V_89 -> V_82 - V_227 ) ,
F_150 ( V_89 ) -> V_229 ) ;
F_148 ( V_89 ) -> V_230 = V_231 ;
}
static void F_151 ( struct V_57 * V_67 ,
struct V_195 * V_89 )
{
if ( ! F_150 ( V_89 ) -> V_229 )
return;
V_67 -> V_212 . V_232 += F_150 ( V_89 ) -> V_229 ;
V_67 -> V_212 . V_233 ++ ;
F_146 ( V_67 , V_89 ) ;
F_150 ( V_89 ) -> V_229 = 0 ;
}
static void F_152 ( struct V_57 * V_67 ,
union V_68 * V_69 ,
struct V_195 * V_89 )
{
struct V_54 * V_73 = V_67 -> V_55 ;
F_151 ( V_67 , V_89 ) ;
F_128 ( V_67 , V_69 , V_89 ) ;
F_132 ( V_67 , V_69 , V_89 ) ;
if ( F_24 ( F_134 ( V_69 , V_234 ) ) )
F_153 ( V_67 -> V_158 -> V_2 , V_89 ) ;
if ( ( V_73 -> V_196 & V_235 ) &&
F_134 ( V_69 , V_236 ) ) {
T_2 V_237 = F_154 ( V_69 -> V_94 . V_95 . V_238 ) ;
F_155 ( V_89 , F_156 ( V_239 ) , V_237 ) ;
}
F_157 ( V_89 , V_67 -> V_86 ) ;
V_89 -> V_240 = F_158 ( V_89 , V_73 ) ;
}
static void F_159 ( struct V_157 * V_158 ,
struct V_195 * V_89 )
{
struct V_1 * V_2 = V_158 -> V_2 ;
if ( F_160 ( V_158 ) )
F_161 ( V_89 ) ;
else if ( ! ( V_2 -> V_139 & V_241 ) )
F_162 ( & V_158 -> V_242 , V_89 ) ;
else
F_163 ( V_89 ) ;
}
static bool F_164 ( struct V_57 * V_67 ,
union V_68 * V_69 ,
struct V_195 * V_89 )
{
T_1 V_243 = V_67 -> V_79 + 1 ;
V_243 = ( V_243 < V_67 -> V_88 ) ? V_243 : 0 ;
V_67 -> V_79 = V_243 ;
F_98 ( F_66 ( V_67 , V_243 ) ) ;
if ( F_165 ( V_67 ) ) {
T_10 V_244 = V_69 -> V_94 . V_198 . V_203 . V_92 &
F_96 ( V_245 ) ;
if ( F_24 ( V_244 ) ) {
T_1 V_246 = F_67 ( V_244 ) ;
V_246 >>= V_247 ;
F_150 ( V_89 ) -> V_229 += V_246 - 1 ;
V_243 = F_67 ( V_69 -> V_94 . V_95 . V_96 ) ;
V_243 &= V_248 ;
V_243 >>= V_249 ;
}
}
if ( F_99 ( F_134 ( V_69 , V_250 ) ) )
return false ;
V_67 -> V_71 [ V_243 ] . V_89 = V_89 ;
V_67 -> V_212 . V_251 ++ ;
return true ;
}
static void F_166 ( struct V_57 * V_67 ,
struct V_195 * V_89 )
{
struct V_252 * V_253 = & F_148 ( V_89 ) -> V_254 [ 0 ] ;
unsigned char * V_255 ;
unsigned int V_256 ;
V_255 = F_167 ( V_253 ) ;
V_256 = F_168 ( V_255 , V_257 ) ;
F_169 ( V_89 , V_255 , F_170 ( V_256 , sizeof( long ) ) ) ;
F_171 ( V_253 , V_256 ) ;
V_253 -> V_99 += V_256 ;
V_89 -> V_258 -= V_256 ;
V_89 -> V_146 += V_256 ;
}
static void F_172 ( struct V_57 * V_67 ,
struct V_195 * V_89 )
{
if ( F_24 ( F_150 ( V_89 ) -> V_259 ) ) {
F_80 ( V_67 -> V_73 , F_150 ( V_89 ) -> V_81 ,
F_139 ( V_67 ) , V_222 ) ;
F_150 ( V_89 ) -> V_259 = false ;
} else {
struct V_252 * V_253 = & F_148 ( V_89 ) -> V_254 [ 0 ] ;
F_173 ( V_67 -> V_73 ,
F_150 ( V_89 ) -> V_81 ,
V_253 -> V_99 ,
F_69 ( V_67 ) ,
V_222 ) ;
}
F_150 ( V_89 ) -> V_81 = 0 ;
}
static bool F_174 ( struct V_57 * V_67 ,
union V_68 * V_69 ,
struct V_195 * V_89 )
{
struct V_54 * V_55 = V_67 -> V_55 ;
if ( F_24 ( F_134 ( V_69 ,
V_260 ) &&
! ( V_55 -> V_196 & V_261 ) ) ) {
F_78 ( V_89 ) ;
return true ;
}
if ( F_175 ( V_89 ) )
F_166 ( V_67 , V_89 ) ;
#ifdef F_176
if ( F_130 ( V_67 , V_69 ) )
return false ;
#endif
if ( F_177 ( V_89 ) )
return true ;
return false ;
}
static void F_178 ( struct V_57 * V_67 ,
struct V_70 * V_262 )
{
struct V_70 * V_263 ;
T_2 V_264 = V_67 -> V_226 ;
V_263 = & V_67 -> V_71 [ V_264 ] ;
V_264 ++ ;
V_67 -> V_226 = ( V_264 < V_67 -> V_88 ) ? V_264 : 0 ;
* V_263 = * V_262 ;
F_179 ( V_67 -> V_73 , V_263 -> V_81 ,
V_263 -> V_99 ,
F_69 ( V_67 ) ,
V_222 ) ;
}
static inline bool F_180 ( struct V_98 * V_98 )
{
return ( F_181 ( V_98 ) != F_182 () ) || V_98 -> V_265 ;
}
static bool F_183 ( struct V_57 * V_67 ,
struct V_70 * V_266 ,
union V_68 * V_69 ,
struct V_195 * V_89 )
{
struct V_98 * V_98 = V_266 -> V_98 ;
unsigned int V_267 = F_154 ( V_69 -> V_94 . V_95 . V_268 ) ;
#if ( V_269 < 8192 )
unsigned int V_270 = F_69 ( V_67 ) ;
#else
unsigned int V_270 = F_170 ( V_267 , V_271 ) ;
unsigned int V_272 = F_139 ( V_67 ) -
F_69 ( V_67 ) ;
#endif
if ( ( V_267 <= V_257 ) && ! F_175 ( V_89 ) ) {
unsigned char * V_255 = F_68 ( V_98 ) + V_266 -> V_99 ;
memcpy ( F_184 ( V_89 , V_267 ) , V_255 , F_170 ( V_267 , sizeof( long ) ) ) ;
if ( F_99 ( ! F_180 ( V_98 ) ) )
return true ;
F_141 ( V_98 , F_137 ( V_67 ) ) ;
return false ;
}
F_185 ( V_89 , F_148 ( V_89 ) -> V_273 , V_98 ,
V_266 -> V_99 , V_267 , V_270 ) ;
if ( F_24 ( F_180 ( V_98 ) ) )
return false ;
#if ( V_269 < 8192 )
if ( F_24 ( F_186 ( V_98 ) != 1 ) )
return false ;
V_266 -> V_99 ^= V_270 ;
#else
V_266 -> V_99 += V_270 ;
if ( V_266 -> V_99 > V_272 )
return false ;
#endif
F_187 ( & V_98 -> V_274 ) ;
return true ;
}
static struct V_195 * F_188 ( struct V_57 * V_67 ,
union V_68 * V_69 )
{
struct V_70 * V_266 ;
struct V_195 * V_89 ;
struct V_98 * V_98 ;
V_266 = & V_67 -> V_71 [ V_67 -> V_79 ] ;
V_98 = V_266 -> V_98 ;
F_189 ( V_98 ) ;
V_89 = V_266 -> V_89 ;
if ( F_99 ( ! V_89 ) ) {
void * V_275 = F_68 ( V_98 ) +
V_266 -> V_99 ;
F_98 ( V_275 ) ;
#if V_271 < 128
F_98 ( V_275 + V_271 ) ;
#endif
V_89 = F_190 ( & V_67 -> V_158 -> V_242 ,
V_257 ) ;
if ( F_24 ( ! V_89 ) ) {
V_67 -> V_212 . V_276 ++ ;
return NULL ;
}
F_189 ( V_89 -> V_92 ) ;
if ( F_99 ( F_134 ( V_69 , V_250 ) ) )
goto V_277;
F_150 ( V_89 ) -> V_81 = V_266 -> V_81 ;
} else {
if ( F_134 ( V_69 , V_250 ) )
F_172 ( V_67 , V_89 ) ;
V_277:
F_173 ( V_67 -> V_73 ,
V_266 -> V_81 ,
V_266 -> V_99 ,
F_69 ( V_67 ) ,
V_222 ) ;
V_266 -> V_89 = NULL ;
}
if ( F_183 ( V_67 , V_266 , V_69 , V_89 ) ) {
F_178 ( V_67 , V_266 ) ;
} else if ( F_150 ( V_89 ) -> V_81 == V_266 -> V_81 ) {
F_150 ( V_89 ) -> V_259 = true ;
} else {
F_80 ( V_67 -> V_73 , V_266 -> V_81 ,
F_139 ( V_67 ) ,
V_222 ) ;
}
V_266 -> V_98 = NULL ;
return V_89 ;
}
static int F_191 ( struct V_157 * V_158 ,
struct V_57 * V_67 ,
const int V_161 )
{
unsigned int V_278 = 0 , V_279 = 0 ;
#ifdef F_176
struct V_1 * V_2 = V_158 -> V_2 ;
int V_280 ;
unsigned int V_281 = 0 ;
#endif
T_2 V_223 = F_110 ( V_67 ) ;
while ( F_99 ( V_279 < V_161 ) ) {
union V_68 * V_69 ;
struct V_195 * V_89 ;
if ( V_223 >= V_282 ) {
F_142 ( V_67 , V_223 ) ;
V_223 = 0 ;
}
V_69 = F_66 ( V_67 , V_67 -> V_79 ) ;
if ( ! V_69 -> V_94 . V_95 . V_96 )
break;
F_192 () ;
V_89 = F_188 ( V_67 , V_69 ) ;
if ( ! V_89 )
break;
V_223 ++ ;
if ( F_164 ( V_67 , V_69 , V_89 ) )
continue;
if ( F_174 ( V_67 , V_69 , V_89 ) )
continue;
V_278 += V_89 -> V_82 ;
F_152 ( V_67 , V_69 , V_89 ) ;
#ifdef F_176
if ( F_130 ( V_67 , V_69 ) ) {
V_280 = F_193 ( V_2 , V_69 , V_89 ) ;
if ( V_280 > 0 ) {
if ( ! V_281 ) {
V_281 = V_67 -> V_55 -> V_283 -
sizeof( struct V_284 ) -
sizeof( struct V_285 ) -
sizeof( struct V_286 ) ;
if ( V_281 > 512 )
V_281 &= ~ 511 ;
}
V_278 += V_280 ;
V_279 += F_149 ( V_280 ,
V_281 ) ;
}
if ( ! V_280 ) {
F_78 ( V_89 ) ;
continue;
}
}
#endif
F_194 ( V_89 , & V_158 -> V_242 ) ;
F_159 ( V_158 , V_89 ) ;
V_279 ++ ;
}
F_100 ( & V_67 -> V_169 ) ;
V_67 -> V_124 . V_144 += V_279 ;
V_67 -> V_124 . V_170 += V_278 ;
F_101 ( & V_67 -> V_169 ) ;
V_158 -> V_287 . V_160 += V_279 ;
V_158 -> V_287 . V_159 += V_278 ;
return V_279 ;
}
static int F_195 ( struct V_288 * V_242 )
{
struct V_157 * V_158 =
F_196 ( V_242 , struct V_157 , V_242 ) ;
struct V_1 * V_2 = V_158 -> V_2 ;
struct V_57 * V_120 ;
int V_289 = 0 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return V_290 ;
if ( ! F_197 ( V_158 ) )
return V_291 ;
F_121 (ring, q_vector->rx) {
V_289 = F_191 ( V_158 , V_120 , 4 ) ;
#ifdef F_198
if ( V_289 )
V_120 -> V_124 . V_292 += V_289 ;
else
V_120 -> V_124 . V_293 ++ ;
#endif
if ( V_289 )
break;
}
F_199 ( V_158 ) ;
return V_289 ;
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_157 * V_158 ;
int V_294 ;
T_1 V_117 ;
if ( V_2 -> V_295 > 32 ) {
T_1 V_296 = ( 1 << ( V_2 -> V_295 - 32 ) ) - 1 ;
F_71 ( & V_2 -> V_14 , V_297 , V_296 ) ;
}
for ( V_294 = 0 ; V_294 < V_2 -> V_189 ; V_294 ++ ) {
struct V_57 * V_120 ;
V_158 = V_2 -> V_158 [ V_294 ] ;
F_121 (ring, q_vector->rx)
F_73 ( V_2 , 0 , V_120 -> V_149 , V_294 ) ;
F_121 (ring, q_vector->tx)
F_73 ( V_2 , 1 , V_120 -> V_149 , V_294 ) ;
F_201 ( V_158 ) ;
}
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
F_73 ( V_2 , - 1 , V_298 ,
V_294 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_73 ( V_2 , - 1 , 1 , V_294 ) ;
break;
default:
break;
}
F_71 ( & V_2 -> V_14 , F_202 ( V_294 ) , 1950 ) ;
V_117 = V_299 ;
V_117 &= ~ ( V_300 |
V_301 |
V_302 ) ;
F_71 ( & V_2 -> V_14 , V_303 , V_117 ) ;
}
static void F_203 ( struct V_157 * V_158 ,
struct V_304 * V_305 )
{
int V_170 = V_305 -> V_159 ;
int V_144 = V_305 -> V_160 ;
T_1 V_306 ;
T_6 V_307 ;
T_4 V_308 = V_305 -> V_309 ;
if ( V_144 == 0 )
return;
V_306 = V_158 -> V_309 >> 2 ;
if ( V_306 == 0 )
return;
V_307 = V_170 / V_306 ;
switch ( V_308 ) {
case V_310 :
if ( V_307 > 10 )
V_308 = V_311 ;
break;
case V_311 :
if ( V_307 > 20 )
V_308 = V_312 ;
else if ( V_307 <= 10 )
V_308 = V_310 ;
break;
case V_312 :
if ( V_307 <= 20 )
V_308 = V_311 ;
break;
}
V_305 -> V_159 = 0 ;
V_305 -> V_160 = 0 ;
V_305 -> V_309 = V_308 ;
}
void F_201 ( struct V_157 * V_158 )
{
struct V_1 * V_2 = V_158 -> V_2 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_294 = V_158 -> V_294 ;
T_1 V_313 = V_158 -> V_309 & V_314 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
V_313 |= ( V_313 << 16 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_313 |= V_315 ;
break;
default:
break;
}
F_71 ( V_14 , F_202 ( V_294 ) , V_313 ) ;
}
static void F_204 ( struct V_157 * V_158 )
{
T_1 V_316 = V_158 -> V_309 ;
T_4 V_317 ;
F_203 ( V_158 , & V_158 -> V_162 ) ;
F_203 ( V_158 , & V_158 -> V_287 ) ;
V_317 = F_205 ( V_158 -> V_287 . V_309 , V_158 -> V_162 . V_309 ) ;
switch ( V_317 ) {
case V_310 :
V_316 = V_318 ;
break;
case V_311 :
V_316 = V_319 ;
break;
case V_312 :
V_316 = V_320 ;
break;
default:
break;
}
if ( V_316 != V_158 -> V_309 ) {
V_316 = ( 10 * V_316 * V_158 -> V_309 ) /
( ( 9 * V_316 ) + V_158 -> V_309 ) ;
V_158 -> V_309 = V_316 ;
F_201 ( V_158 ) ;
}
}
static void F_206 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_321 = V_2 -> V_322 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
if ( ! ( V_2 -> V_154 & V_323 ) &&
! ( V_2 -> V_154 & V_324 ) )
return;
V_2 -> V_154 &= ~ V_324 ;
switch ( V_14 -> V_21 ) {
case V_325 :
if ( ! ( V_321 & V_326 ) &&
! ( V_321 & V_327 ) )
return;
if ( ! ( V_321 & V_327 ) && V_14 -> V_108 . V_328 . V_329 ) {
T_1 V_20 ;
bool V_330 = false ;
V_14 -> V_108 . V_328 . V_329 ( V_14 , & V_20 , & V_330 , false ) ;
if ( V_330 )
return;
}
if ( V_14 -> V_331 . V_328 . V_332 ( V_14 ) != V_333 )
return;
break;
default:
if ( ! ( V_321 & V_326 ) )
return;
break;
}
F_207 ( V_156 ,
L_70
L_71
L_72 ) ;
V_2 -> V_322 = 0 ;
}
static void F_208 ( struct V_1 * V_2 , T_1 V_321 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ( V_2 -> V_139 & V_334 ) &&
( V_321 & V_335 ) ) {
F_207 ( V_172 , L_73 ) ;
F_71 ( V_14 , V_336 , V_335 ) ;
}
}
static void F_209 ( struct V_1 * V_2 , T_1 V_321 )
{
if ( ! ( V_2 -> V_154 & V_323 ) )
return;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
if ( ( ( V_321 & V_326 ) || ( V_321 & V_327 ) ) &&
( ! F_14 ( V_33 , & V_2 -> V_34 ) ) ) {
V_2 -> V_322 = V_321 ;
V_2 -> V_154 |= V_324 ;
F_13 ( V_2 ) ;
return;
}
return;
case V_112 :
if ( ! ( V_321 & V_337 ) )
return;
break;
default:
return;
}
F_207 ( V_156 ,
L_70
L_71
L_72 ) ;
}
static void F_210 ( struct V_1 * V_2 , T_1 V_321 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_321 & V_338 ) {
F_71 ( V_14 , V_336 , V_338 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_154 |= V_339 ;
F_13 ( V_2 ) ;
}
}
if ( V_321 & V_335 ) {
F_71 ( V_14 , V_336 , V_335 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_139 |= V_340 ;
F_13 ( V_2 ) ;
}
}
}
static void F_211 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_341 ++ ;
V_2 -> V_139 |= V_342 ;
V_2 -> V_343 = V_171 ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
F_71 ( V_14 , V_344 , V_345 ) ;
F_212 ( V_14 ) ;
F_13 ( V_2 ) ;
}
}
static inline void F_213 ( struct V_1 * V_2 ,
T_6 V_116 )
{
T_1 V_117 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_117 = ( V_118 & V_116 ) ;
F_71 ( V_14 , V_346 , V_117 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_117 = ( V_116 & 0xFFFFFFFF ) ;
if ( V_117 )
F_71 ( V_14 , F_214 ( 0 ) , V_117 ) ;
V_117 = ( V_116 >> 32 ) ;
if ( V_117 )
F_71 ( V_14 , F_214 ( 1 ) , V_117 ) ;
break;
default:
break;
}
}
static inline void F_215 ( struct V_1 * V_2 ,
T_6 V_116 )
{
T_1 V_117 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_117 = ( V_118 & V_116 ) ;
F_71 ( V_14 , V_344 , V_117 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_117 = ( V_116 & 0xFFFFFFFF ) ;
if ( V_117 )
F_71 ( V_14 , F_216 ( 0 ) , V_117 ) ;
V_117 = ( V_116 >> 32 ) ;
if ( V_117 )
F_71 ( V_14 , F_216 ( 1 ) , V_117 ) ;
break;
default:
break;
}
}
static inline void F_217 ( struct V_1 * V_2 , bool V_347 ,
bool V_348 )
{
T_1 V_117 = ( V_299 & ~ V_118 ) ;
if ( V_2 -> V_139 & V_342 )
V_117 &= ~ V_302 ;
if ( V_2 -> V_154 & V_323 )
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_117 |= V_349 ;
break;
case V_112 :
case V_113 :
case V_114 :
V_117 |= V_350 ;
break;
default:
break;
}
if ( V_2 -> V_139 & V_334 )
V_117 |= V_351 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_117 |= V_351 ;
V_117 |= V_352 ;
case V_112 :
case V_113 :
case V_114 :
V_117 |= V_353 ;
V_117 |= V_301 ;
break;
default:
break;
}
if ( ( V_2 -> V_139 & V_354 ) &&
! ( V_2 -> V_154 & V_355 ) )
V_117 |= V_356 ;
F_71 ( & V_2 -> V_14 , V_346 , V_117 ) ;
if ( V_347 )
F_213 ( V_2 , ~ 0 ) ;
if ( V_348 )
F_212 ( & V_2 -> V_14 ) ;
}
static T_11 F_218 ( int V_357 , void * V_92 )
{
struct V_1 * V_2 = V_92 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_321 ;
V_321 = F_37 ( V_14 , V_119 ) ;
V_321 &= 0xFFFF0000 ;
F_71 ( V_14 , V_336 , V_321 ) ;
if ( V_321 & V_327 )
F_211 ( V_2 ) ;
if ( V_321 & V_358 )
F_219 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
if ( V_321 & V_359 ) {
F_105 ( V_360 , L_74 ) ;
V_2 -> V_154 |= V_155 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_336 , V_359 ) ;
}
if ( V_321 & V_361 ) {
int V_362 = 0 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_120 = V_2 -> V_58 [ V_48 ] ;
if ( F_220 ( V_363 ,
& V_120 -> V_34 ) )
V_362 ++ ;
}
if ( V_362 ) {
F_71 ( V_14 , V_344 , V_364 ) ;
V_2 -> V_154 |= V_355 ;
F_13 ( V_2 ) ;
}
}
F_210 ( V_2 , V_321 ) ;
F_209 ( V_2 , V_321 ) ;
break;
default:
break;
}
F_208 ( V_2 , V_321 ) ;
if ( F_24 ( V_321 & V_365 ) )
F_221 ( V_2 , V_321 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_217 ( V_2 , false , false ) ;
return V_366 ;
}
static T_11 F_222 ( int V_357 , void * V_92 )
{
struct V_157 * V_158 = V_92 ;
if ( V_158 -> V_287 . V_120 || V_158 -> V_162 . V_120 )
F_223 ( & V_158 -> V_242 ) ;
return V_366 ;
}
int F_224 ( struct V_288 * V_242 , int V_161 )
{
struct V_157 * V_158 =
F_196 ( V_242 , struct V_157 , V_242 ) ;
struct V_1 * V_2 = V_158 -> V_2 ;
struct V_57 * V_120 ;
int V_367 ;
bool V_368 = true ;
#ifdef F_225
if ( V_2 -> V_139 & V_187 )
F_119 ( V_158 ) ;
#endif
F_121 (ring, q_vector->tx)
V_368 &= ! ! F_94 ( V_158 , V_120 ) ;
if ( ! F_226 ( V_158 ) )
return V_161 ;
if ( V_158 -> V_287 . V_88 > 1 )
V_367 = F_205 ( V_161 / V_158 -> V_287 . V_88 , 1 ) ;
else
V_367 = V_161 ;
F_121 (ring, q_vector->rx)
V_368 &= ( F_191 ( V_158 , V_120 ,
V_367 ) < V_367 ) ;
F_227 ( V_158 ) ;
if ( ! V_368 )
return V_161 ;
F_228 ( V_242 ) ;
if ( V_2 -> V_369 & 1 )
F_204 ( V_158 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_213 ( V_2 , ( ( T_6 ) 1 << V_158 -> V_294 ) ) ;
return 0 ;
}
static int F_229 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
int V_370 , V_17 ;
int V_371 = 0 , V_372 = 0 ;
for ( V_370 = 0 ; V_370 < V_2 -> V_189 ; V_370 ++ ) {
struct V_157 * V_158 = V_2 -> V_158 [ V_370 ] ;
struct V_373 * V_374 = & V_2 -> V_375 [ V_370 ] ;
if ( V_158 -> V_162 . V_120 && V_158 -> V_287 . V_120 ) {
snprintf ( V_158 -> V_53 , sizeof( V_158 -> V_53 ) - 1 ,
L_75 , V_55 -> V_53 , L_76 , V_371 ++ ) ;
V_372 ++ ;
} else if ( V_158 -> V_287 . V_120 ) {
snprintf ( V_158 -> V_53 , sizeof( V_158 -> V_53 ) - 1 ,
L_75 , V_55 -> V_53 , L_77 , V_371 ++ ) ;
} else if ( V_158 -> V_162 . V_120 ) {
snprintf ( V_158 -> V_53 , sizeof( V_158 -> V_53 ) - 1 ,
L_75 , V_55 -> V_53 , L_78 , V_372 ++ ) ;
} else {
continue;
}
V_17 = F_230 ( V_374 -> V_370 , & F_222 , 0 ,
V_158 -> V_53 , V_158 ) ;
if ( V_17 ) {
F_103 ( V_172 , L_79
L_80 , V_17 ) ;
goto V_376;
}
if ( V_2 -> V_139 & V_354 ) {
F_231 ( V_374 -> V_370 ,
& V_158 -> V_377 ) ;
}
}
V_17 = F_230 ( V_2 -> V_375 [ V_370 ] . V_370 ,
F_218 , 0 , V_55 -> V_53 , V_2 ) ;
if ( V_17 ) {
F_103 ( V_172 , L_81 , V_17 ) ;
goto V_376;
}
return 0 ;
V_376:
while ( V_370 ) {
V_370 -- ;
F_231 ( V_2 -> V_375 [ V_370 ] . V_370 ,
NULL ) ;
F_232 ( V_2 -> V_375 [ V_370 ] . V_370 ,
V_2 -> V_158 [ V_370 ] ) ;
}
V_2 -> V_139 &= ~ V_378 ;
F_233 ( V_2 -> V_9 ) ;
F_234 ( V_2 -> V_375 ) ;
V_2 -> V_375 = NULL ;
return V_17 ;
}
static T_11 F_235 ( int V_357 , void * V_92 )
{
struct V_1 * V_2 = V_92 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_157 * V_158 = V_2 -> V_158 [ 0 ] ;
T_1 V_321 ;
F_71 ( V_14 , V_344 , V_379 ) ;
V_321 = F_37 ( V_14 , V_336 ) ;
if ( ! V_321 ) {
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_217 ( V_2 , true , true ) ;
return V_380 ;
}
if ( V_321 & V_327 )
F_211 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
F_210 ( V_2 , V_321 ) ;
case V_112 :
case V_113 :
case V_114 :
if ( V_321 & V_359 ) {
F_105 ( V_360 , L_74 ) ;
V_2 -> V_154 |= V_155 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_336 , V_359 ) ;
}
F_209 ( V_2 , V_321 ) ;
break;
default:
break;
}
F_208 ( V_2 , V_321 ) ;
if ( F_24 ( V_321 & V_365 ) )
F_221 ( V_2 , V_321 ) ;
F_223 ( & V_158 -> V_242 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_217 ( V_2 , false , false ) ;
return V_366 ;
}
static int F_236 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
int V_17 ;
if ( V_2 -> V_139 & V_378 )
V_17 = F_229 ( V_2 ) ;
else if ( V_2 -> V_139 & V_381 )
V_17 = F_230 ( V_2 -> V_9 -> V_357 , F_235 , 0 ,
V_55 -> V_53 , V_2 ) ;
else
V_17 = F_230 ( V_2 -> V_9 -> V_357 , F_235 , V_382 ,
V_55 -> V_53 , V_2 ) ;
if ( V_17 )
F_103 ( V_172 , L_82 , V_17 ) ;
return V_17 ;
}
static void F_237 ( struct V_1 * V_2 )
{
int V_370 ;
if ( ! ( V_2 -> V_139 & V_378 ) ) {
F_232 ( V_2 -> V_9 -> V_357 , V_2 ) ;
return;
}
for ( V_370 = 0 ; V_370 < V_2 -> V_189 ; V_370 ++ ) {
struct V_157 * V_158 = V_2 -> V_158 [ V_370 ] ;
struct V_373 * V_374 = & V_2 -> V_375 [ V_370 ] ;
if ( ! V_158 -> V_287 . V_120 && ! V_158 -> V_162 . V_120 )
continue;
F_231 ( V_374 -> V_370 , NULL ) ;
F_232 ( V_374 -> V_370 , V_158 ) ;
}
F_232 ( V_2 -> V_375 [ V_370 ++ ] . V_370 , V_2 ) ;
}
static inline void F_238 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
F_71 ( & V_2 -> V_14 , V_344 , ~ 0 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_71 ( & V_2 -> V_14 , V_344 , 0xFFFF0000 ) ;
F_71 ( & V_2 -> V_14 , F_216 ( 0 ) , ~ 0 ) ;
F_71 ( & V_2 -> V_14 , F_216 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_212 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_139 & V_378 ) {
int V_370 ;
for ( V_370 = 0 ; V_370 < V_2 -> V_189 ; V_370 ++ )
F_239 ( V_2 -> V_375 [ V_370 ] . V_370 ) ;
F_239 ( V_2 -> V_375 [ V_370 ++ ] . V_370 ) ;
} else {
F_239 ( V_2 -> V_9 -> V_357 ) ;
}
}
static void F_240 ( struct V_1 * V_2 )
{
struct V_157 * V_158 = V_2 -> V_158 [ 0 ] ;
F_201 ( V_158 ) ;
F_73 ( V_2 , 0 , 0 , 0 ) ;
F_73 ( V_2 , 1 , 0 , 0 ) ;
F_105 ( V_14 , L_83 ) ;
}
void F_241 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_383 = V_120 -> V_81 ;
int V_384 = 10 ;
T_1 V_385 = V_386 ;
T_4 V_149 = V_120 -> V_149 ;
F_71 ( V_14 , F_50 ( V_149 ) , 0 ) ;
F_212 ( V_14 ) ;
F_71 ( V_14 , F_45 ( V_149 ) ,
( V_383 & F_242 ( 32 ) ) ) ;
F_71 ( V_14 , F_46 ( V_149 ) , ( V_383 >> 32 ) ) ;
F_71 ( V_14 , F_47 ( V_149 ) ,
V_120 -> V_88 * sizeof( union V_61 ) ) ;
F_71 ( V_14 , F_48 ( V_149 ) , 0 ) ;
F_71 ( V_14 , F_49 ( V_149 ) , 0 ) ;
V_120 -> V_146 = V_2 -> V_387 + F_49 ( V_149 ) ;
if ( ! V_120 -> V_158 || ( V_120 -> V_158 -> V_309 < V_318 ) )
V_385 |= ( 1 << 16 ) ;
else
V_385 |= ( 8 << 16 ) ;
V_385 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_139 & V_354 ) {
V_120 -> V_388 = V_2 -> V_388 ;
V_120 -> V_389 = 0 ;
F_243 ( V_363 , & V_120 -> V_34 ) ;
} else {
V_120 -> V_388 = 0 ;
}
if ( ! F_15 ( V_390 , & V_120 -> V_34 ) ) {
struct V_157 * V_158 = V_120 -> V_158 ;
if ( V_158 )
F_244 ( V_120 -> V_55 ,
& V_158 -> V_377 ,
V_120 -> V_86 ) ;
}
F_34 ( V_132 , & V_120 -> V_34 ) ;
F_71 ( V_14 , F_50 ( V_149 ) , V_385 ) ;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_391 ) & V_392 ) )
return;
do {
F_245 ( 1000 , 2000 ) ;
V_385 = F_37 ( V_14 , F_50 ( V_149 ) ) ;
} while ( -- V_384 && ! ( V_385 & V_386 ) );
if ( ! V_384 )
F_103 ( V_156 , L_84 , V_149 ) ;
}
static void F_246 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_393 , V_394 ;
T_4 V_395 = F_247 ( V_2 -> V_55 ) ;
if ( V_14 -> V_108 . type == V_109 )
return;
V_393 = F_37 ( V_14 , V_396 ) ;
V_393 |= V_397 ;
F_71 ( V_14 , V_396 , V_393 ) ;
if ( V_2 -> V_139 & V_398 ) {
V_394 = V_399 ;
if ( V_395 > 4 )
V_394 |= V_400 | V_401 ;
else if ( V_395 > 1 )
V_394 |= V_400 | V_402 ;
else if ( V_2 -> V_403 [ V_404 ] . V_405 == 4 )
V_394 |= V_406 ;
else
V_394 |= V_407 ;
} else {
if ( V_395 > 4 )
V_394 = V_400 | V_401 ;
else if ( V_395 > 1 )
V_394 = V_400 | V_402 ;
else
V_394 = V_408 ;
}
F_71 ( V_14 , V_409 , V_394 ) ;
if ( V_395 ) {
T_1 V_410 = F_37 ( V_14 , V_411 ) ;
V_410 |= V_412 ;
F_71 ( V_14 , V_411 , V_410 ) ;
}
V_393 &= ~ V_397 ;
F_71 ( V_14 , V_396 , V_393 ) ;
}
static void F_248 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_413 ;
T_1 V_48 ;
F_246 ( V_2 ) ;
if ( V_14 -> V_108 . type != V_109 ) {
V_413 = F_37 ( V_14 , V_414 ) ;
V_413 |= V_415 ;
F_71 ( V_14 , V_414 , V_413 ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_241 ( V_2 , V_2 -> V_58 [ V_48 ] ) ;
}
static void F_249 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_149 = V_120 -> V_149 ;
T_1 V_416 = F_37 ( V_14 , F_36 ( V_149 ) ) ;
V_416 |= V_417 ;
F_71 ( V_14 , F_36 ( V_149 ) , V_416 ) ;
}
static void F_250 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_149 = V_120 -> V_149 ;
T_1 V_416 = F_37 ( V_14 , F_36 ( V_149 ) ) ;
V_416 &= ~ V_417 ;
F_71 ( V_14 , F_36 ( V_149 ) , V_416 ) ;
}
static void F_251 ( struct V_1 * V_2 ,
struct V_57 * V_67 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_416 ;
T_4 V_149 = V_67 -> V_149 ;
if ( V_14 -> V_108 . type == V_109 ) {
T_2 V_117 = V_2 -> V_403 [ V_404 ] . V_117 ;
V_149 &= V_117 ;
}
V_416 = V_257 << V_418 ;
V_416 |= F_69 ( V_67 ) >> V_419 ;
V_416 |= V_420 ;
F_71 ( V_14 , F_36 ( V_149 ) , V_416 ) ;
}
static void F_252 ( struct V_1 * V_2 , const T_1 * V_421 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_422 = 0 ;
int V_48 , V_49 ;
int V_423 = 128 ;
T_2 V_424 = V_2 -> V_403 [ V_404 ] . V_405 ;
int V_425 ;
if ( ( V_2 -> V_139 & V_398 ) && ( V_424 < 2 ) )
V_424 = 2 ;
for ( V_48 = 0 ; V_48 < 10 ; V_48 ++ )
F_71 ( V_14 , F_253 ( V_48 ) , V_421 [ V_48 ] ) ;
if ( V_2 -> V_14 . V_108 . type == V_109 )
V_425 = 0x11 ;
else
V_425 = 0x1 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_113 :
case V_114 :
if ( ! ( V_2 -> V_139 & V_398 ) )
V_423 = 512 ;
default:
break;
}
for ( V_48 = 0 , V_49 = 0 ; V_48 < V_423 ; V_48 ++ , V_49 ++ ) {
if ( V_49 == V_424 )
V_49 = 0 ;
V_422 = ( V_422 << 8 ) | ( V_49 * V_425 ) ;
if ( ( V_48 & 3 ) == 3 ) {
if ( V_48 < 128 )
F_71 ( V_14 , F_254 ( V_48 >> 2 ) , V_422 ) ;
else
F_71 ( V_14 , F_255 ( ( V_48 >> 2 ) - 32 ) ,
V_422 ) ;
}
}
}
static void F_256 ( struct V_1 * V_2 , const T_1 * V_421 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_426 = 0 ;
T_2 V_424 = V_2 -> V_403 [ V_404 ] . V_405 ;
unsigned int V_427 = V_2 -> V_295 ;
int V_48 , V_49 ;
for ( V_48 = 0 ; V_48 < 10 ; V_48 ++ )
F_71 ( V_14 , F_257 ( V_48 , V_427 ) , V_421 [ V_48 ] ) ;
for ( V_48 = 0 , V_49 = 0 ; V_48 < 64 ; V_48 ++ , V_49 ++ ) {
if ( V_49 == V_424 )
V_49 = 0 ;
V_426 = ( V_426 << 8 ) | V_49 ;
if ( ( V_48 & 3 ) == 3 )
F_71 ( V_14 , F_258 ( V_48 >> 2 , V_427 ) ,
V_426 ) ;
}
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_428 = 0 , V_429 = 0 , V_430 = 0 ;
T_1 V_431 [ 10 ] ;
T_1 V_432 ;
V_432 = F_37 ( V_14 , V_433 ) ;
V_432 |= V_434 ;
F_71 ( V_14 , V_433 , V_432 ) ;
if ( V_2 -> V_14 . V_108 . type == V_109 ) {
if ( V_2 -> V_403 [ V_404 ] . V_117 )
V_428 = V_435 ;
} else {
T_4 V_395 = F_247 ( V_2 -> V_55 ) ;
if ( V_2 -> V_139 & V_398 ) {
if ( V_395 > 4 )
V_428 = V_436 ;
else if ( V_395 > 1 )
V_428 = V_437 ;
else if ( V_2 -> V_403 [ V_404 ] . V_405 == 4 )
V_428 = V_438 ;
else
V_428 = V_439 ;
} else {
if ( V_395 > 4 )
V_428 = V_440 ;
else if ( V_395 > 1 )
V_428 = V_441 ;
else
V_428 = V_435 ;
}
}
V_429 |= V_442 |
V_443 |
V_444 |
V_445 ;
if ( V_2 -> V_154 & V_446 )
V_429 |= V_447 ;
if ( V_2 -> V_154 & V_448 )
V_429 |= V_449 ;
F_260 ( V_431 , sizeof( V_431 ) ) ;
if ( ( V_14 -> V_108 . type >= V_113 ) &&
( V_2 -> V_139 & V_398 ) ) {
unsigned int V_427 = V_2 -> V_295 ;
V_428 |= V_450 ;
F_71 ( V_14 , V_451 , V_428 ) ;
F_256 ( V_2 , V_431 ) ;
V_430 = V_435 ;
V_430 |= V_429 ;
F_71 ( V_14 , F_261 ( V_427 ) , V_430 ) ;
} else {
F_252 ( V_2 , V_431 ) ;
V_428 |= V_429 ;
F_71 ( V_14 , V_451 , V_428 ) ;
}
}
static void F_262 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_452 ;
T_4 V_149 = V_120 -> V_149 ;
if ( ! F_165 ( V_120 ) )
return;
V_452 = F_37 ( V_14 , F_263 ( V_149 ) ) ;
V_452 |= V_453 ;
V_452 |= V_454 ;
F_71 ( V_14 , F_263 ( V_149 ) , V_452 ) ;
}
static void F_264 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_384 = V_455 ;
T_1 V_456 ;
T_4 V_149 = V_120 -> V_149 ;
if ( F_22 ( V_14 -> V_39 ) )
return;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_391 ) & V_392 ) )
return;
do {
F_245 ( 1000 , 2000 ) ;
V_456 = F_37 ( V_14 , F_42 ( V_149 ) ) ;
} while ( -- V_384 && ! ( V_456 & V_457 ) );
if ( ! V_384 ) {
F_103 ( V_156 , L_85
L_86 , V_149 ) ;
}
}
void F_265 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_384 = V_455 ;
T_1 V_456 ;
T_4 V_149 = V_120 -> V_149 ;
if ( F_22 ( V_14 -> V_39 ) )
return;
V_456 = F_37 ( V_14 , F_42 ( V_149 ) ) ;
V_456 &= ~ V_457 ;
F_71 ( V_14 , F_42 ( V_149 ) , V_456 ) ;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_391 ) & V_392 ) )
return;
do {
F_266 ( 10 ) ;
V_456 = F_37 ( V_14 , F_42 ( V_149 ) ) ;
} while ( -- V_384 && ( V_456 & V_457 ) );
if ( ! V_384 ) {
F_103 ( V_156 , L_87
L_86 , V_149 ) ;
}
}
void F_267 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_458 = V_120 -> V_81 ;
T_1 V_456 ;
T_4 V_149 = V_120 -> V_149 ;
V_456 = F_37 ( V_14 , F_42 ( V_149 ) ) ;
F_265 ( V_2 , V_120 ) ;
F_71 ( V_14 , F_43 ( V_149 ) , ( V_458 & F_242 ( 32 ) ) ) ;
F_71 ( V_14 , F_44 ( V_149 ) , ( V_458 >> 32 ) ) ;
F_71 ( V_14 , F_39 ( V_149 ) ,
V_120 -> V_88 * sizeof( union V_68 ) ) ;
F_71 ( V_14 , F_40 ( V_149 ) , 0 ) ;
F_71 ( V_14 , F_41 ( V_149 ) , 0 ) ;
V_120 -> V_146 = V_2 -> V_387 + F_41 ( V_149 ) ;
F_251 ( V_2 , V_120 ) ;
F_262 ( V_2 , V_120 ) ;
if ( V_14 -> V_108 . type == V_109 ) {
V_456 &= ~ 0x3FFFFF ;
V_456 |= 0x080420 ;
}
V_456 |= V_457 ;
F_71 ( V_14 , F_42 ( V_149 ) , V_456 ) ;
F_264 ( V_2 , V_120 ) ;
F_142 ( V_120 , F_110 ( V_120 ) ) ;
}
static void F_268 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_424 = V_2 -> V_403 [ V_404 ] . V_405 ;
T_2 V_459 ;
T_1 V_460 = V_461 |
V_462 |
V_463 |
V_464 |
V_465 ;
if ( V_14 -> V_108 . type == V_109 )
return;
if ( V_424 > 3 )
V_460 |= 2 << 29 ;
else if ( V_424 > 1 )
V_460 |= 1 << 29 ;
F_269 (pool, &adapter->fwd_bitmask, 32 )
F_71 ( V_14 , F_270 ( F_271 ( V_459 ) ) , V_460 ) ;
}
static void F_272 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_177 , V_466 ;
T_1 V_467 , V_468 ;
int V_48 ;
if ( ! ( V_2 -> V_139 & V_398 ) )
return;
V_468 = F_37 ( V_14 , V_469 ) ;
V_468 |= V_470 ;
V_468 &= ~ V_471 ;
V_468 |= F_271 ( 0 ) << V_472 ;
V_468 |= V_473 ;
F_71 ( V_14 , V_469 , V_468 ) ;
V_466 = F_271 ( 0 ) % 32 ;
V_177 = ( F_271 ( 0 ) >= 32 ) ? 1 : 0 ;
F_71 ( V_14 , F_273 ( V_177 ) , ( ~ 0 ) << V_466 ) ;
F_71 ( V_14 , F_273 ( V_177 ^ 1 ) , V_177 - 1 ) ;
F_71 ( V_14 , F_274 ( V_177 ) , ( ~ 0 ) << V_466 ) ;
F_71 ( V_14 , F_274 ( V_177 ^ 1 ) , V_177 - 1 ) ;
if ( V_2 -> V_154 & V_474 )
F_71 ( V_14 , V_475 , V_476 ) ;
V_14 -> V_108 . V_328 . V_477 ( V_14 , 0 , F_271 ( 0 ) ) ;
switch ( V_2 -> V_403 [ V_478 ] . V_117 ) {
case V_479 :
V_467 = V_480 ;
break;
case V_481 :
V_467 = V_482 ;
break;
default:
V_467 = V_483 ;
break;
}
F_71 ( V_14 , V_484 , V_467 ) ;
V_14 -> V_108 . V_328 . V_485 ( V_14 , ( V_2 -> V_295 != 0 ) ,
V_2 -> V_295 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_295 ; V_48 ++ ) {
if ( ! V_2 -> V_486 [ V_48 ] . V_487 )
F_275 ( V_2 -> V_55 , V_48 , false ) ;
}
}
static void F_276 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_55 = V_2 -> V_55 ;
int V_488 = V_55 -> V_283 + V_489 + V_490 ;
struct V_57 * V_67 ;
int V_48 ;
T_1 V_491 , V_492 ;
#ifdef F_176
if ( ( V_2 -> V_139 & V_493 ) &&
( V_488 < V_494 ) )
V_488 = V_494 ;
#endif
if ( V_488 < ( V_495 + V_490 ) )
V_488 = ( V_495 + V_490 ) ;
V_491 = F_37 ( V_14 , V_496 ) ;
if ( V_488 != ( V_491 >> V_497 ) ) {
V_491 &= ~ V_498 ;
V_491 |= V_488 << V_497 ;
F_71 ( V_14 , V_496 , V_491 ) ;
}
V_492 = F_37 ( V_14 , V_499 ) ;
V_492 |= V_500 ;
F_71 ( V_14 , V_499 , V_492 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_67 = V_2 -> V_67 [ V_48 ] ;
if ( V_2 -> V_154 & V_501 )
F_277 ( V_67 ) ;
else
F_278 ( V_67 ) ;
}
}
static void F_279 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_502 = F_37 ( V_14 , V_503 ) ;
switch ( V_14 -> V_108 . type ) {
case V_113 :
case V_114 :
case V_109 :
V_502 |= V_504 ;
break;
case V_111 :
case V_112 :
F_71 ( V_14 , V_505 ,
( V_506 | F_37 ( V_14 , V_505 ) ) ) ;
V_502 &= ~ V_507 ;
V_502 |= ( V_508 | V_509 ) ;
V_502 |= V_510 ;
break;
default:
return;
}
F_71 ( V_14 , V_503 , V_502 ) ;
}
static void F_280 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
T_1 V_182 , V_511 ;
V_182 = F_37 ( V_14 , V_512 ) ;
F_71 ( V_14 , V_512 , V_182 & ~ V_513 ) ;
F_268 ( V_2 ) ;
F_279 ( V_2 ) ;
V_511 = F_37 ( V_14 , V_514 ) ;
V_511 &= ~ V_515 ;
if ( ! ( V_2 -> V_154 & V_501 ) )
V_511 |= V_515 ;
F_71 ( V_14 , V_514 , V_511 ) ;
F_259 ( V_2 ) ;
F_276 ( V_2 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
F_267 ( V_2 , V_2 -> V_67 [ V_48 ] ) ;
if ( V_14 -> V_108 . type == V_109 )
V_182 |= V_516 ;
V_182 |= V_513 ;
V_14 -> V_108 . V_328 . V_517 ( V_14 , V_182 ) ;
}
static int F_281 ( struct V_54 * V_55 ,
T_12 V_518 , T_2 V_237 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_108 . V_328 . V_519 ( & V_2 -> V_14 , V_237 , F_271 ( 0 ) , true ) ;
F_243 ( V_237 , V_2 -> V_520 ) ;
return 0 ;
}
static int F_282 ( struct V_54 * V_55 ,
T_12 V_518 , T_2 V_237 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_108 . V_328 . V_519 ( & V_2 -> V_14 , V_237 , F_271 ( 0 ) , false ) ;
F_34 ( V_237 , V_2 -> V_520 ) ;
return 0 ;
}
static void F_283 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_521 ;
int V_48 , V_49 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_521 = F_37 ( V_14 , V_522 ) ;
V_521 &= ~ V_523 ;
F_71 ( V_14 , V_522 , V_521 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_120 = V_2 -> V_67 [ V_48 ] ;
if ( V_120 -> V_147 )
continue;
V_49 = V_120 -> V_149 ;
V_521 = F_37 ( V_14 , F_42 ( V_49 ) ) ;
V_521 &= ~ V_524 ;
F_71 ( V_14 , F_42 ( V_49 ) , V_521 ) ;
}
break;
default:
break;
}
}
static void F_284 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_521 ;
int V_48 , V_49 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_521 = F_37 ( V_14 , V_522 ) ;
V_521 |= V_523 ;
F_71 ( V_14 , V_522 , V_521 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_120 = V_2 -> V_67 [ V_48 ] ;
if ( V_120 -> V_147 )
continue;
V_49 = V_120 -> V_149 ;
V_521 = F_37 ( V_14 , F_42 ( V_49 ) ) ;
V_521 |= V_524 ;
F_71 ( V_14 , F_42 ( V_49 ) , V_521 ) ;
}
break;
default:
break;
}
}
static void F_285 ( struct V_1 * V_2 )
{
T_2 V_237 ;
F_281 ( V_2 -> V_55 , F_156 ( V_239 ) , 0 ) ;
F_269 (vid, adapter->active_vlans, VLAN_N_VID)
F_281 ( V_2 -> V_55 , F_156 ( V_239 ) , V_237 ) ;
}
static int F_286 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! F_57 ( V_55 ) )
return 0 ;
if ( V_14 -> V_108 . V_328 . V_525 )
V_14 -> V_108 . V_328 . V_525 ( V_14 , V_55 ) ;
else
return - V_526 ;
#ifdef F_287
F_288 ( V_2 ) ;
#endif
return F_289 ( V_55 ) ;
}
void F_290 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_527 ; V_48 ++ ) {
if ( V_2 -> V_528 [ V_48 ] . V_34 & V_529 )
V_14 -> V_108 . V_328 . V_530 ( V_14 , V_48 , V_2 -> V_528 [ V_48 ] . V_531 ,
V_2 -> V_528 [ V_48 ] . V_104 ,
V_532 ) ;
else
V_14 -> V_108 . V_328 . V_533 ( V_14 , V_48 ) ;
V_2 -> V_528 [ V_48 ] . V_34 &= ~ ( V_534 ) ;
}
}
static void F_291 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_527 ; V_48 ++ ) {
if ( V_2 -> V_528 [ V_48 ] . V_34 & V_534 ) {
if ( V_2 -> V_528 [ V_48 ] . V_34 &
V_529 )
V_14 -> V_108 . V_328 . V_530 ( V_14 , V_48 ,
V_2 -> V_528 [ V_48 ] . V_531 ,
V_2 -> V_528 [ V_48 ] . V_104 ,
V_532 ) ;
else
V_14 -> V_108 . V_328 . V_533 ( V_14 , V_48 ) ;
V_2 -> V_528 [ V_48 ] . V_34 &=
~ ( V_534 ) ;
}
}
}
static void F_292 ( struct V_1 * V_2 )
{
int V_48 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_527 ; V_48 ++ ) {
V_2 -> V_528 [ V_48 ] . V_34 |= V_534 ;
V_2 -> V_528 [ V_48 ] . V_34 &= ~ V_529 ;
memset ( V_2 -> V_528 [ V_48 ] . V_531 , 0 , V_535 ) ;
V_2 -> V_528 [ V_48 ] . V_104 = 0 ;
}
F_291 ( V_2 ) ;
}
static int F_293 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 , V_88 = 0 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_527 ; V_48 ++ ) {
if ( V_2 -> V_528 [ V_48 ] . V_34 == 0 )
V_88 ++ ;
}
return V_88 ;
}
static void F_294 ( struct V_1 * V_2 ,
T_4 * V_531 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
memcpy ( & V_2 -> V_528 [ 0 ] . V_531 , V_531 , V_535 ) ;
V_2 -> V_528 [ 0 ] . V_104 = F_271 ( 0 ) ;
V_2 -> V_528 [ 0 ] . V_34 = ( V_536 |
V_529 ) ;
V_14 -> V_108 . V_328 . V_530 ( V_14 , 0 , V_2 -> V_528 [ 0 ] . V_531 ,
V_2 -> V_528 [ 0 ] . V_104 ,
V_532 ) ;
}
int F_295 ( struct V_1 * V_2 , T_4 * V_531 , T_2 V_104 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
if ( F_296 ( V_531 ) )
return - V_537 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_527 ; V_48 ++ ) {
if ( V_2 -> V_528 [ V_48 ] . V_34 & V_529 )
continue;
V_2 -> V_528 [ V_48 ] . V_34 |= ( V_534 |
V_529 ) ;
F_297 ( V_2 -> V_528 [ V_48 ] . V_531 , V_531 ) ;
V_2 -> V_528 [ V_48 ] . V_104 = V_104 ;
F_291 ( V_2 ) ;
return V_48 ;
}
return - V_526 ;
}
int F_298 ( struct V_1 * V_2 , T_4 * V_531 , T_2 V_104 )
{
int V_48 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_296 ( V_531 ) )
return - V_537 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_527 ; V_48 ++ ) {
if ( F_299 ( V_531 , V_2 -> V_528 [ V_48 ] . V_531 ) &&
V_2 -> V_528 [ V_48 ] . V_104 == V_104 ) {
V_2 -> V_528 [ V_48 ] . V_34 |= V_534 ;
V_2 -> V_528 [ V_48 ] . V_34 &= ~ V_529 ;
memset ( V_2 -> V_528 [ V_48 ] . V_531 , 0 , V_535 ) ;
V_2 -> V_528 [ V_48 ] . V_104 = 0 ;
F_291 ( V_2 ) ;
return 0 ;
}
}
return - V_526 ;
}
static int F_300 ( struct V_54 * V_55 , int V_538 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_88 = 0 ;
if ( F_301 ( V_55 ) > F_293 ( V_2 ) )
return - V_526 ;
if ( ! F_302 ( V_55 ) ) {
struct V_539 * V_540 ;
F_303 (ha, netdev) {
F_298 ( V_2 , V_540 -> V_531 , V_538 ) ;
F_295 ( V_2 , V_540 -> V_531 , V_538 ) ;
V_88 ++ ;
}
}
return V_88 ;
}
void F_304 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_541 , V_542 = V_543 | V_544 ;
T_1 V_521 ;
int V_88 ;
V_541 = F_37 ( V_14 , V_545 ) ;
V_521 = F_37 ( V_14 , V_522 ) ;
V_541 &= ~ V_546 ;
V_541 |= V_547 ;
V_541 |= V_548 ;
V_541 |= V_549 ;
V_541 &= ~ ( V_550 | V_551 ) ;
V_521 &= ~ ( V_552 | V_553 ) ;
if ( V_55 -> V_139 & V_554 ) {
V_14 -> V_555 . V_556 = true ;
V_541 |= ( V_550 | V_551 ) ;
V_542 |= V_557 ;
if ( V_2 -> V_139 & ( V_558 |
V_398 ) )
V_521 |= ( V_552 | V_553 ) ;
} else {
if ( V_55 -> V_139 & V_559 ) {
V_541 |= V_551 ;
V_542 |= V_557 ;
}
V_521 |= V_552 ;
V_14 -> V_555 . V_556 = false ;
}
V_88 = F_300 ( V_55 , F_271 ( 0 ) ) ;
if ( V_88 < 0 ) {
V_541 |= V_550 ;
V_542 |= V_560 ;
}
V_88 = F_286 ( V_55 ) ;
if ( V_88 < 0 ) {
V_541 |= V_551 ;
V_542 |= V_557 ;
} else if ( V_88 ) {
V_542 |= V_561 ;
}
if ( V_14 -> V_108 . type != V_109 ) {
V_542 |= F_37 ( V_14 , F_305 ( F_271 ( 0 ) ) ) &
~ ( V_557 | V_561 |
V_560 ) ;
F_71 ( V_14 , F_305 ( F_271 ( 0 ) ) , V_542 ) ;
}
if ( V_2 -> V_55 -> V_196 & V_261 ) {
V_541 |= ( V_546 |
V_547 |
V_549 ) ;
V_541 &= ~ ( V_548 ) ;
}
F_71 ( V_14 , V_522 , V_521 ) ;
F_71 ( V_14 , V_545 , V_541 ) ;
if ( V_55 -> V_196 & V_235 )
F_284 ( V_2 ) ;
else
F_283 ( V_2 ) ;
}
static void F_306 ( struct V_1 * V_2 )
{
int V_562 ;
for ( V_562 = 0 ; V_562 < V_2 -> V_189 ; V_562 ++ ) {
F_307 ( V_2 -> V_158 [ V_562 ] ) ;
F_308 ( & V_2 -> V_158 [ V_562 ] -> V_242 ) ;
}
}
static void F_309 ( struct V_1 * V_2 )
{
int V_562 ;
for ( V_562 = 0 ; V_562 < V_2 -> V_189 ; V_562 ++ ) {
F_310 ( & V_2 -> V_158 [ V_562 ] -> V_242 ) ;
while ( ! F_311 ( V_2 -> V_158 [ V_562 ] ) ) {
F_51 ( L_88 , V_562 ) ;
F_245 ( 1000 , 20000 ) ;
}
}
}
static void F_312 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_488 = V_2 -> V_55 -> V_283 + V_489 + V_490 ;
if ( ! ( V_2 -> V_139 & V_140 ) ) {
if ( V_14 -> V_108 . type == V_109 )
F_313 ( V_2 -> V_55 , 65536 ) ;
return;
}
if ( V_14 -> V_108 . type == V_109 )
F_313 ( V_2 -> V_55 , 32768 ) ;
#ifdef F_176
if ( V_2 -> V_55 -> V_196 & V_563 )
V_488 = F_205 ( V_488 , V_494 ) ;
#endif
if ( V_2 -> V_564 & V_565 ) {
F_314 ( V_14 , & V_2 -> V_136 , V_488 ,
V_566 ) ;
F_314 ( V_14 , & V_2 -> V_136 , V_488 ,
V_567 ) ;
F_315 ( V_14 , & V_2 -> V_136 ) ;
} else if ( V_2 -> V_568 && V_2 -> V_138 ) {
F_316 ( & V_2 -> V_14 ,
V_2 -> V_568 ,
V_488 ) ;
F_317 ( & V_2 -> V_14 ,
V_2 -> V_138 -> V_135 ,
V_2 -> V_568 -> V_569 ) ;
}
if ( V_14 -> V_108 . type != V_109 ) {
T_1 V_570 = 0 ;
T_2 V_424 = V_2 -> V_403 [ V_404 ] . V_405 - 1 ;
while ( V_424 ) {
V_570 ++ ;
V_424 >>= 1 ;
}
F_71 ( V_14 , V_571 , V_570 * 0x11111111 ) ;
}
}
static int F_318 ( struct V_1 * V_2 , int V_572 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_73 = V_2 -> V_55 ;
int V_360 , V_134 , V_573 , V_574 ;
T_1 V_575 , V_576 ;
V_134 = V_360 = V_73 -> V_283 + V_489 + V_490 + V_577 ;
#ifdef F_176
if ( ( V_73 -> V_196 & V_563 ) &&
( V_134 < V_494 ) &&
( V_572 == F_319 ( V_2 ) ) )
V_134 = V_494 ;
#endif
switch ( V_14 -> V_108 . type ) {
case V_112 :
case V_113 :
case V_114 :
V_575 = F_320 ( V_360 , V_134 ) ;
break;
default:
V_575 = F_321 ( V_360 , V_134 ) ;
break;
}
if ( V_2 -> V_139 & V_398 )
V_575 += F_322 ( V_134 ) ;
V_573 = F_323 ( V_575 ) ;
V_576 = F_37 ( V_14 , F_324 ( V_572 ) ) >> 10 ;
V_574 = V_576 - V_573 ;
if ( V_574 < 0 ) {
F_93 ( V_156 , L_89
L_90
L_91 , V_572 ) ;
V_574 = V_134 + 1 ;
}
return V_574 ;
}
static int F_325 ( struct V_1 * V_2 , int V_572 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_73 = V_2 -> V_55 ;
int V_134 ;
T_1 V_575 ;
V_134 = V_73 -> V_283 + V_489 + V_490 ;
#ifdef F_176
if ( ( V_73 -> V_196 & V_563 ) &&
( V_134 < V_494 ) &&
( V_572 == F_86 ( V_73 , V_2 -> V_578 . V_579 ) ) )
V_134 = V_494 ;
#endif
switch ( V_14 -> V_108 . type ) {
case V_112 :
case V_113 :
case V_114 :
V_575 = F_326 ( V_134 ) ;
break;
default:
V_575 = F_327 ( V_134 ) ;
break;
}
return F_323 ( V_575 ) ;
}
static void F_328 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_580 = F_247 ( V_2 -> V_55 ) ;
int V_48 ;
if ( ! V_580 )
V_580 = 1 ;
for ( V_48 = 0 ; V_48 < V_580 ; V_48 ++ ) {
V_14 -> V_125 . V_581 [ V_48 ] = F_318 ( V_2 , V_48 ) ;
V_14 -> V_125 . V_582 [ V_48 ] = F_325 ( V_2 , V_48 ) ;
if ( V_14 -> V_125 . V_582 [ V_48 ] > V_14 -> V_125 . V_581 [ V_48 ] )
V_14 -> V_125 . V_582 [ V_48 ] = 0 ;
}
for (; V_48 < V_583 ; V_48 ++ )
V_14 -> V_125 . V_581 [ V_48 ] = 0 ;
}
static void F_329 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_584 ;
T_4 V_134 = F_247 ( V_2 -> V_55 ) ;
if ( V_2 -> V_139 & V_354 ||
V_2 -> V_139 & V_585 )
V_584 = 32 << V_2 -> V_586 ;
else
V_584 = 0 ;
V_14 -> V_108 . V_328 . V_587 ( V_14 , V_134 , V_584 , V_588 ) ;
F_328 ( V_2 ) ;
}
static void F_330 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_589 * V_590 ;
struct V_591 * V_592 ;
F_331 ( & V_2 -> V_593 ) ;
if ( ! F_332 ( & V_2 -> V_594 ) )
F_333 ( V_14 , & V_2 -> V_595 ) ;
F_334 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_335 ( V_14 ,
& V_592 -> V_592 ,
V_592 -> V_596 ,
( V_592 -> V_597 == V_598 ) ?
V_598 :
V_2 -> V_67 [ V_592 -> V_597 ] -> V_149 ) ;
}
F_336 ( & V_2 -> V_593 ) ;
}
static void F_337 ( struct V_54 * V_73 , unsigned int V_459 ,
struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_542 ;
V_542 = F_37 ( V_14 , F_305 ( V_459 ) ) ;
V_542 |= ( V_561 | V_543 | V_544 ) ;
V_542 &= ~ V_557 ;
if ( V_73 -> V_139 & V_559 ) {
V_542 |= V_557 ;
} else {
V_542 |= V_561 ;
V_14 -> V_108 . V_328 . V_525 ( V_14 , V_73 ) ;
}
F_300 ( V_2 -> V_55 , V_459 ) ;
F_71 ( V_14 , F_305 ( V_459 ) , V_542 ) ;
}
static void F_338 ( struct V_599 * V_600 )
{
struct V_1 * V_2 = V_600 -> V_148 ;
int V_424 = V_2 -> V_601 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_459 = V_600 -> V_459 ;
T_1 V_460 = V_461 |
V_462 |
V_463 |
V_464 |
V_465 ;
if ( V_14 -> V_108 . type == V_109 )
return;
if ( V_424 > 3 )
V_460 |= 2 << 29 ;
else if ( V_424 > 1 )
V_460 |= 1 << 29 ;
F_71 ( V_14 , F_270 ( F_271 ( V_459 ) ) , V_460 ) ;
}
static void F_339 ( struct V_57 * V_67 )
{
struct V_190 * V_73 = V_67 -> V_73 ;
unsigned long V_267 ;
T_2 V_48 ;
if ( ! V_67 -> V_71 )
return;
for ( V_48 = 0 ; V_48 < V_67 -> V_88 ; V_48 ++ ) {
struct V_70 * V_266 = & V_67 -> V_71 [ V_48 ] ;
if ( V_266 -> V_89 ) {
struct V_195 * V_89 = V_266 -> V_89 ;
if ( F_150 ( V_89 ) -> V_259 )
F_80 ( V_73 ,
F_150 ( V_89 ) -> V_81 ,
F_69 ( V_67 ) ,
V_222 ) ;
F_340 ( V_89 ) ;
V_266 -> V_89 = NULL ;
}
if ( ! V_266 -> V_98 )
continue;
F_80 ( V_73 , V_266 -> V_81 ,
F_139 ( V_67 ) , V_222 ) ;
F_141 ( V_266 -> V_98 , F_137 ( V_67 ) ) ;
V_266 -> V_98 = NULL ;
}
V_267 = sizeof( struct V_70 ) * V_67 -> V_88 ;
memset ( V_67 -> V_71 , 0 , V_267 ) ;
memset ( V_67 -> V_87 , 0 , V_67 -> V_267 ) ;
V_67 -> V_226 = 0 ;
V_67 -> V_79 = 0 ;
V_67 -> V_80 = 0 ;
}
static void F_341 ( struct V_599 * V_600 ,
struct V_57 * V_67 )
{
struct V_1 * V_2 = V_600 -> V_148 ;
int V_107 = V_67 -> V_86 + V_600 -> V_602 ;
F_265 ( V_2 , V_67 ) ;
F_245 ( 10000 , 20000 ) ;
F_215 ( V_2 , ( ( T_6 ) 1 << V_107 ) ) ;
F_339 ( V_67 ) ;
V_67 -> V_147 = NULL ;
}
static int F_342 ( struct V_54 * V_603 ,
struct V_599 * V_604 )
{
struct V_1 * V_2 = V_604 -> V_148 ;
unsigned int V_605 = V_604 -> V_602 ;
unsigned int V_606 = V_604 -> V_607 ;
int V_48 ;
F_343 ( V_603 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_601 ; V_48 ++ ) {
F_341 ( V_604 , V_2 -> V_67 [ V_605 + V_48 ] ) ;
V_2 -> V_67 [ V_605 + V_48 ] -> V_55 = V_2 -> V_55 ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_601 ; V_48 ++ ) {
V_2 -> V_58 [ V_606 + V_48 ] -> V_147 = NULL ;
V_2 -> V_58 [ V_606 + V_48 ] -> V_55 = V_2 -> V_55 ;
}
return 0 ;
}
static int F_344 ( struct V_54 * V_603 ,
struct V_599 * V_604 )
{
struct V_1 * V_2 = V_604 -> V_148 ;
unsigned int V_605 , V_606 , V_347 ;
int V_48 , V_608 , V_17 = 0 ;
if ( ! F_14 ( V_604 -> V_459 , & V_2 -> V_609 ) )
return 0 ;
V_608 = V_604 -> V_459 * V_2 -> V_601 ;
F_345 ( V_603 , L_92 ,
V_604 -> V_459 , V_2 -> V_610 ,
V_608 , V_608 + V_2 -> V_601 ,
V_2 -> V_609 ) ;
V_604 -> V_55 = V_603 ;
V_604 -> V_602 = V_605 = V_608 ;
V_604 -> V_607 = V_606 = V_608 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_601 ; V_48 ++ )
F_341 ( V_604 , V_2 -> V_67 [ V_605 + V_48 ] ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_601 ; V_48 ++ ) {
V_2 -> V_67 [ V_605 + V_48 ] -> V_55 = V_603 ;
V_2 -> V_67 [ V_605 + V_48 ] -> V_147 = V_604 ;
F_267 ( V_2 , V_2 -> V_67 [ V_605 + V_48 ] ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_601 ; V_48 ++ ) {
V_2 -> V_58 [ V_606 + V_48 ] -> V_55 = V_603 ;
V_2 -> V_58 [ V_606 + V_48 ] -> V_147 = V_604 ;
}
V_347 = F_346 (unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues) ;
V_17 = F_347 ( V_603 , V_347 ) ;
if ( V_17 )
goto V_611;
V_17 = F_348 ( V_603 , V_347 ) ;
if ( V_17 )
goto V_611;
if ( F_349 ( V_603 -> V_612 ) )
F_295 ( V_2 , V_603 -> V_612 , V_604 -> V_459 ) ;
F_338 ( V_604 ) ;
F_337 ( V_603 , V_604 -> V_459 , V_2 ) ;
return V_17 ;
V_611:
F_342 ( V_603 , V_604 ) ;
return V_17 ;
}
static void F_350 ( struct V_1 * V_2 )
{
struct V_54 * V_95 ;
struct V_613 * V_614 ;
int V_17 ;
F_351 (adapter->netdev, upper, iter) {
if ( F_352 ( V_95 ) ) {
struct V_615 * V_616 = F_89 ( V_95 ) ;
struct V_599 * V_600 = V_616 -> V_617 ;
if ( V_616 -> V_617 ) {
V_17 = F_344 ( V_95 , V_600 ) ;
if ( V_17 )
continue;
}
}
}
}
static void F_353 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
F_329 ( V_2 ) ;
#ifdef F_354
F_312 ( V_2 ) ;
#endif
F_272 ( V_2 ) ;
F_304 ( V_2 -> V_55 ) ;
F_285 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
V_14 -> V_108 . V_328 . V_618 ( V_14 ) ;
break;
default:
break;
}
if ( V_2 -> V_139 & V_354 ) {
F_355 ( & V_2 -> V_14 ,
V_2 -> V_586 ) ;
} else if ( V_2 -> V_139 & V_585 ) {
F_356 ( & V_2 -> V_14 ,
V_2 -> V_586 ) ;
F_330 ( V_2 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
V_14 -> V_108 . V_328 . V_619 ( V_14 ) ;
break;
default:
break;
}
#ifdef F_176
F_357 ( V_2 ) ;
#endif
F_248 ( V_2 ) ;
F_280 ( V_2 ) ;
F_350 ( V_2 ) ;
}
static inline bool F_358 ( struct V_15 * V_14 )
{
switch ( V_14 -> V_331 . type ) {
case V_620 :
case V_621 :
case V_622 :
case V_623 :
case V_624 :
case V_625 :
case V_626 :
case V_627 :
case V_628 :
case V_629 :
case V_630 :
case V_631 :
case V_632 :
return true ;
case V_633 :
if ( V_14 -> V_108 . type == V_109 )
return true ;
default:
return false ;
}
}
static void F_359 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_108 . type == V_109 )
V_2 -> V_154 |= V_634 ;
V_2 -> V_154 |= V_339 ;
}
static int F_360 ( struct V_15 * V_14 )
{
T_1 V_20 ;
bool V_635 , V_330 = false ;
T_1 V_636 = V_637 ;
if ( V_14 -> V_108 . V_328 . V_329 )
V_636 = V_14 -> V_108 . V_328 . V_329 ( V_14 , & V_20 , & V_330 , false ) ;
if ( V_636 )
return V_636 ;
V_20 = V_14 -> V_331 . V_638 ;
if ( ( ! V_20 ) && ( V_14 -> V_108 . V_328 . V_639 ) )
V_636 = V_14 -> V_108 . V_328 . V_639 ( V_14 , & V_20 ,
& V_635 ) ;
if ( V_636 )
return V_636 ;
if ( V_14 -> V_108 . V_328 . V_640 )
V_636 = V_14 -> V_108 . V_328 . V_640 ( V_14 , V_20 , V_330 ) ;
return V_636 ;
}
static void F_361 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_641 = 0 ;
if ( V_2 -> V_139 & V_378 ) {
V_641 = V_642 | V_643 |
V_644 ;
V_641 |= V_645 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
F_71 ( V_14 , V_646 , V_647 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
default:
F_71 ( V_14 , F_362 ( 0 ) , 0xFFFFFFFF ) ;
F_71 ( V_14 , F_362 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_71 ( V_14 , V_646 , V_647 ) ;
}
if ( V_2 -> V_139 & V_398 ) {
V_641 &= ~ V_648 ;
switch ( V_2 -> V_403 [ V_478 ] . V_117 ) {
case V_479 :
V_641 |= V_649 ;
break;
case V_481 :
V_641 |= V_650 ;
break;
default:
V_641 |= V_651 ;
break;
}
}
if ( V_2 -> V_154 & V_323 ) {
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_641 |= V_652 ;
break;
case V_112 :
V_641 |= V_350 ;
break;
default:
break;
}
}
if ( V_2 -> V_139 & V_334 )
V_641 |= V_653 ;
if ( V_14 -> V_108 . type == V_111 ) {
V_641 |= V_653 ;
V_641 |= V_654 ;
}
F_71 ( V_14 , V_655 , V_641 ) ;
}
static void F_363 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 ;
T_1 V_100 ;
F_72 ( V_2 ) ;
F_361 ( V_2 ) ;
if ( V_2 -> V_139 & V_378 )
F_200 ( V_2 ) ;
else
F_240 ( V_2 ) ;
if ( V_14 -> V_108 . V_328 . V_656 )
V_14 -> V_108 . V_328 . V_656 ( V_14 ) ;
F_33 () ;
F_34 ( V_33 , & V_2 -> V_34 ) ;
F_306 ( V_2 ) ;
if ( F_358 ( V_14 ) ) {
F_359 ( V_2 ) ;
} else {
V_17 = F_360 ( V_14 ) ;
if ( V_17 )
F_103 ( V_172 , L_93 , V_17 ) ;
}
F_37 ( V_14 , V_336 ) ;
F_217 ( V_2 , true , true ) ;
if ( V_2 -> V_139 & V_334 ) {
T_1 V_657 = F_37 ( V_14 , V_658 ) ;
if ( V_657 & V_659 )
F_207 ( V_156 , L_73 ) ;
}
V_2 -> V_139 |= V_342 ;
V_2 -> V_343 = V_171 ;
F_364 ( & V_2 -> V_660 , V_171 ) ;
V_100 = F_37 ( V_14 , V_101 ) ;
V_100 |= V_661 ;
F_71 ( V_14 , V_101 , V_100 ) ;
}
void F_365 ( struct V_1 * V_2 )
{
F_366 ( F_367 () ) ;
V_2 -> V_55 -> V_74 = V_171 ;
while ( F_15 ( V_662 , & V_2 -> V_34 ) )
F_245 ( 1000 , 2000 ) ;
F_368 ( V_2 ) ;
if ( V_2 -> V_139 & V_398 )
F_369 ( 2000 ) ;
F_370 ( V_2 ) ;
F_34 ( V_662 , & V_2 -> V_34 ) ;
}
void F_370 ( struct V_1 * V_2 )
{
F_353 ( V_2 ) ;
F_363 ( V_2 ) ;
}
void F_371 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_55 = V_2 -> V_55 ;
int V_17 ;
T_4 V_663 [ V_535 ] ;
if ( F_22 ( V_14 -> V_39 ) )
return;
while ( F_15 ( V_664 , & V_2 -> V_34 ) )
F_245 ( 1000 , 2000 ) ;
V_2 -> V_154 &= ~ ( V_634 |
V_339 ) ;
V_2 -> V_139 &= ~ V_340 ;
V_17 = V_14 -> V_108 . V_328 . V_665 ( V_14 ) ;
switch ( V_17 ) {
case 0 :
case V_666 :
case V_667 :
break;
case V_668 :
F_18 ( L_94 ) ;
break;
case V_669 :
F_11 ( L_95
L_96
L_97
L_98
L_99
L_100 ) ;
break;
default:
F_18 ( L_101 , V_17 ) ;
}
F_34 ( V_664 , & V_2 -> V_34 ) ;
memcpy ( V_663 , & V_2 -> V_528 [ 0 ] . V_531 , V_55 -> V_670 ) ;
F_292 ( V_2 ) ;
F_294 ( V_2 , V_663 ) ;
if ( V_14 -> V_108 . V_671 )
V_14 -> V_108 . V_328 . V_672 ( V_14 , F_271 ( 0 ) ) ;
if ( F_14 ( V_673 , & V_2 -> V_34 ) )
F_372 ( V_2 ) ;
}
static void F_373 ( struct V_57 * V_58 )
{
struct V_59 * V_78 ;
unsigned long V_267 ;
T_2 V_48 ;
if ( ! V_58 -> V_78 )
return;
for ( V_48 = 0 ; V_48 < V_58 -> V_88 ; V_48 ++ ) {
V_78 = & V_58 -> V_78 [ V_48 ] ;
F_77 ( V_58 , V_78 ) ;
}
F_374 ( F_107 ( V_58 ) ) ;
V_267 = sizeof( struct V_59 ) * V_58 -> V_88 ;
memset ( V_58 -> V_78 , 0 , V_267 ) ;
memset ( V_58 -> V_87 , 0 , V_58 -> V_267 ) ;
V_58 -> V_80 = 0 ;
V_58 -> V_79 = 0 ;
}
static void F_375 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
F_339 ( V_2 -> V_67 [ V_48 ] ) ;
}
static void F_376 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_373 ( V_2 -> V_58 [ V_48 ] ) ;
}
static void F_377 ( struct V_1 * V_2 )
{
struct V_589 * V_590 ;
struct V_591 * V_592 ;
F_331 ( & V_2 -> V_593 ) ;
F_334 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_378 ( & V_592 -> V_674 ) ;
F_234 ( V_592 ) ;
}
V_2 -> V_675 = 0 ;
F_336 ( & V_2 -> V_593 ) ;
}
void F_368 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_95 ;
struct V_613 * V_614 ;
T_1 V_182 ;
int V_48 ;
if ( F_15 ( V_33 , & V_2 -> V_34 ) )
return;
V_182 = F_37 ( V_14 , V_512 ) ;
F_71 ( V_14 , V_512 , V_182 & ~ V_513 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
F_265 ( V_2 , V_2 -> V_67 [ V_48 ] ) ;
F_245 ( 10000 , 20000 ) ;
F_343 ( V_55 ) ;
F_379 ( V_55 ) ;
F_380 ( V_55 ) ;
F_351 (adapter->netdev, upper, iter) {
if ( F_352 ( V_95 ) ) {
struct V_615 * V_238 = F_89 ( V_95 ) ;
if ( V_238 -> V_617 ) {
F_343 ( V_95 ) ;
F_379 ( V_95 ) ;
F_380 ( V_95 ) ;
}
}
}
F_238 ( V_2 ) ;
F_309 ( V_2 ) ;
V_2 -> V_154 &= ~ ( V_355 |
V_155 ) ;
V_2 -> V_139 &= ~ V_342 ;
F_381 ( & V_2 -> V_660 ) ;
if ( V_2 -> V_295 ) {
F_71 ( & V_2 -> V_14 , V_297 , 0 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_295 ; V_48 ++ )
V_2 -> V_486 [ V_48 ] . V_676 = false ;
F_382 ( V_2 ) ;
F_383 ( V_2 ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
T_4 V_149 = V_2 -> V_58 [ V_48 ] -> V_149 ;
F_71 ( V_14 , F_50 ( V_149 ) , V_677 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_71 ( V_14 , V_414 ,
( F_37 ( V_14 , V_414 ) &
~ V_415 ) ) ;
break;
default:
break;
}
if ( ! F_384 ( V_2 -> V_9 ) )
F_371 ( V_2 ) ;
if ( V_14 -> V_108 . V_328 . V_678 )
V_14 -> V_108 . V_328 . V_678 ( V_14 ) ;
F_376 ( V_2 ) ;
F_375 ( V_2 ) ;
#ifdef F_225
F_123 ( V_2 ) ;
#endif
}
static void F_385 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
F_92 ( V_2 ) ;
}
static int F_386 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_200 , V_679 ;
T_1 V_680 ;
#ifdef F_354
int V_49 ;
struct V_681 * V_134 ;
#endif
V_14 -> V_682 = V_9 -> V_683 ;
V_14 -> V_21 = V_9 -> V_190 ;
V_14 -> V_684 = V_9 -> V_685 ;
V_14 -> V_686 = V_9 -> V_687 ;
V_14 -> V_688 = V_9 -> V_689 ;
V_200 = F_346 ( int , F_387 ( V_2 ) , F_388 () ) ;
V_2 -> V_403 [ V_404 ] . V_690 = V_200 ;
V_2 -> V_154 |= V_691 ;
V_2 -> V_154 |= V_501 ;
V_2 -> V_692 = V_693 ;
V_2 -> V_388 = 20 ;
V_679 = F_346 ( int , V_694 , F_388 () ) ;
V_2 -> V_403 [ V_695 ] . V_690 = V_679 ;
V_2 -> V_586 = V_696 ;
#ifdef F_225
V_2 -> V_139 |= V_192 ;
#endif
#ifdef F_176
V_2 -> V_139 |= V_697 ;
V_2 -> V_139 &= ~ V_493 ;
#ifdef F_354
V_2 -> V_578 . V_579 = V_698 ;
#endif
#endif
V_2 -> V_528 = F_389 ( sizeof( struct V_699 ) *
V_14 -> V_108 . V_527 ,
V_700 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_2 -> V_154 &= ~ V_691 ;
V_2 -> V_154 &= ~ V_501 ;
if ( V_14 -> V_21 == V_701 )
V_2 -> V_139 |= V_334 ;
V_2 -> V_692 = V_702 ;
V_2 -> V_403 [ V_695 ] . V_690 = 0 ;
V_2 -> V_388 = 0 ;
V_2 -> V_586 = 0 ;
#ifdef F_176
V_2 -> V_139 &= ~ V_697 ;
V_2 -> V_139 &= ~ V_493 ;
#ifdef F_354
V_2 -> V_578 . V_579 = 0 ;
#endif
#endif
break;
case V_111 :
if ( V_14 -> V_21 == V_325 )
V_2 -> V_154 |= V_323 ;
break;
case V_112 :
V_680 = F_37 ( V_14 , V_703 ) ;
if ( V_680 & V_704 )
V_2 -> V_154 |= V_323 ;
break;
case V_114 :
case V_113 :
#ifdef F_225
V_2 -> V_139 &= ~ V_192 ;
#endif
break;
default:
break;
}
#ifdef F_176
F_390 ( & V_2 -> V_578 . V_705 ) ;
#endif
F_390 ( & V_2 -> V_593 ) ;
#ifdef F_354
switch ( V_14 -> V_108 . type ) {
case V_112 :
case V_113 :
case V_114 :
V_2 -> V_136 . V_706 . V_707 = V_708 ;
V_2 -> V_136 . V_706 . V_709 = V_708 ;
break;
default:
V_2 -> V_136 . V_706 . V_707 = V_583 ;
V_2 -> V_136 . V_706 . V_709 = V_583 ;
break;
}
for ( V_49 = 0 ; V_49 < V_583 ; V_49 ++ ) {
V_134 = & V_2 -> V_136 . V_710 [ V_49 ] ;
V_134 -> V_711 [ V_566 ] . V_712 = 0 ;
V_134 -> V_711 [ V_566 ] . V_713 = 12 + ( V_49 & 1 ) ;
V_134 -> V_711 [ V_567 ] . V_712 = 0 ;
V_134 -> V_711 [ V_567 ] . V_713 = 12 + ( V_49 & 1 ) ;
V_134 -> V_714 = V_715 ;
}
V_134 = & V_2 -> V_136 . V_710 [ 0 ] ;
V_134 -> V_711 [ V_566 ] . V_716 = 0xFF ;
V_134 -> V_711 [ V_567 ] . V_716 = 0xFF ;
V_2 -> V_136 . V_717 [ V_566 ] [ 0 ] = 100 ;
V_2 -> V_136 . V_717 [ V_567 ] [ 0 ] = 100 ;
V_2 -> V_136 . V_137 = false ;
V_2 -> V_718 = 0x00 ;
V_2 -> V_564 = V_719 | V_565 ;
memcpy ( & V_2 -> V_720 , & V_2 -> V_136 ,
sizeof( V_2 -> V_720 ) ) ;
#endif
V_14 -> V_125 . V_721 = V_127 ;
V_14 -> V_125 . V_126 = V_127 ;
F_328 ( V_2 ) ;
V_14 -> V_125 . V_722 = V_723 ;
V_14 -> V_125 . V_724 = true ;
V_14 -> V_125 . V_725 = F_391 ( V_14 ) ;
#ifdef F_287
if ( V_726 > 0 )
F_11 ( L_102 ) ;
if ( V_14 -> V_108 . type != V_109 ) {
if ( V_726 > V_727 ) {
V_2 -> V_295 = 0 ;
F_11 ( L_103 ) ;
} else {
V_2 -> V_295 = V_726 ;
}
}
#endif
V_2 -> V_369 = 1 ;
V_2 -> V_728 = 1 ;
V_2 -> V_729 = V_730 ;
V_2 -> V_731 = V_732 ;
V_2 -> V_733 = V_734 ;
if ( F_392 ( V_14 ) ) {
F_18 ( L_104 ) ;
return - V_735 ;
}
F_243 ( 0 , & V_2 -> V_609 ) ;
F_243 ( V_33 , & V_2 -> V_34 ) ;
return 0 ;
}
int F_393 ( struct V_57 * V_58 )
{
struct V_190 * V_73 = V_58 -> V_73 ;
int V_736 = F_394 ( V_73 ) ;
int V_737 = - 1 ;
int V_267 ;
V_267 = sizeof( struct V_59 ) * V_58 -> V_88 ;
if ( V_58 -> V_158 )
V_737 = V_58 -> V_158 -> V_738 ;
V_58 -> V_78 = F_395 ( V_267 , V_737 ) ;
if ( ! V_58 -> V_78 )
V_58 -> V_78 = F_396 ( V_267 ) ;
if ( ! V_58 -> V_78 )
goto V_17;
F_397 ( & V_58 -> V_169 ) ;
V_58 -> V_267 = V_58 -> V_88 * sizeof( union V_61 ) ;
V_58 -> V_267 = F_170 ( V_58 -> V_267 , 4096 ) ;
F_398 ( V_73 , V_737 ) ;
V_58 -> V_87 = F_399 ( V_73 ,
V_58 -> V_267 ,
& V_58 -> V_81 ,
V_739 ) ;
F_398 ( V_73 , V_736 ) ;
if ( ! V_58 -> V_87 )
V_58 -> V_87 = F_399 ( V_73 , V_58 -> V_267 ,
& V_58 -> V_81 , V_739 ) ;
if ( ! V_58 -> V_87 )
goto V_17;
V_58 -> V_80 = 0 ;
V_58 -> V_79 = 0 ;
return 0 ;
V_17:
F_400 ( V_58 -> V_78 ) ;
V_58 -> V_78 = NULL ;
F_401 ( V_73 , L_105 ) ;
return - V_526 ;
}
static int F_402 ( struct V_1 * V_2 )
{
int V_48 , V_17 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
V_17 = F_393 ( V_2 -> V_58 [ V_48 ] ) ;
if ( ! V_17 )
continue;
F_103 ( V_172 , L_106 , V_48 ) ;
goto V_740;
}
return 0 ;
V_740:
while ( V_48 -- )
F_403 ( V_2 -> V_58 [ V_48 ] ) ;
return V_17 ;
}
int F_404 ( struct V_57 * V_67 )
{
struct V_190 * V_73 = V_67 -> V_73 ;
int V_736 = F_394 ( V_73 ) ;
int V_737 = - 1 ;
int V_267 ;
V_267 = sizeof( struct V_70 ) * V_67 -> V_88 ;
if ( V_67 -> V_158 )
V_737 = V_67 -> V_158 -> V_738 ;
V_67 -> V_71 = F_395 ( V_267 , V_737 ) ;
if ( ! V_67 -> V_71 )
V_67 -> V_71 = F_396 ( V_267 ) ;
if ( ! V_67 -> V_71 )
goto V_17;
F_397 ( & V_67 -> V_169 ) ;
V_67 -> V_267 = V_67 -> V_88 * sizeof( union V_68 ) ;
V_67 -> V_267 = F_170 ( V_67 -> V_267 , 4096 ) ;
F_398 ( V_73 , V_737 ) ;
V_67 -> V_87 = F_399 ( V_73 ,
V_67 -> V_267 ,
& V_67 -> V_81 ,
V_739 ) ;
F_398 ( V_73 , V_736 ) ;
if ( ! V_67 -> V_87 )
V_67 -> V_87 = F_399 ( V_73 , V_67 -> V_267 ,
& V_67 -> V_81 , V_739 ) ;
if ( ! V_67 -> V_87 )
goto V_17;
V_67 -> V_79 = 0 ;
V_67 -> V_80 = 0 ;
return 0 ;
V_17:
F_400 ( V_67 -> V_71 ) ;
V_67 -> V_71 = NULL ;
F_401 ( V_73 , L_107 ) ;
return - V_526 ;
}
static int F_405 ( struct V_1 * V_2 )
{
int V_48 , V_17 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_17 = F_404 ( V_2 -> V_67 [ V_48 ] ) ;
if ( ! V_17 )
continue;
F_103 ( V_172 , L_108 , V_48 ) ;
goto V_741;
}
#ifdef F_176
V_17 = F_406 ( V_2 ) ;
if ( ! V_17 )
#endif
return 0 ;
V_741:
while ( V_48 -- )
F_407 ( V_2 -> V_67 [ V_48 ] ) ;
return V_17 ;
}
void F_403 ( struct V_57 * V_58 )
{
F_373 ( V_58 ) ;
F_400 ( V_58 -> V_78 ) ;
V_58 -> V_78 = NULL ;
if ( ! V_58 -> V_87 )
return;
F_408 ( V_58 -> V_73 , V_58 -> V_267 ,
V_58 -> V_87 , V_58 -> V_81 ) ;
V_58 -> V_87 = NULL ;
}
static void F_409 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
if ( V_2 -> V_58 [ V_48 ] -> V_87 )
F_403 ( V_2 -> V_58 [ V_48 ] ) ;
}
void F_407 ( struct V_57 * V_67 )
{
F_339 ( V_67 ) ;
F_400 ( V_67 -> V_71 ) ;
V_67 -> V_71 = NULL ;
if ( ! V_67 -> V_87 )
return;
F_408 ( V_67 -> V_73 , V_67 -> V_267 ,
V_67 -> V_87 , V_67 -> V_81 ) ;
V_67 -> V_87 = NULL ;
}
static void F_410 ( struct V_1 * V_2 )
{
int V_48 ;
#ifdef F_176
F_411 ( V_2 ) ;
#endif
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
if ( V_2 -> V_67 [ V_48 ] -> V_87 )
F_407 ( V_2 -> V_67 [ V_48 ] ) ;
}
static int F_412 ( struct V_54 * V_55 , int V_742 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_488 = V_742 + V_489 + V_490 ;
if ( ( V_742 < 68 ) || ( V_488 > V_743 ) )
return - V_537 ;
if ( ( V_2 -> V_139 & V_398 ) &&
( V_2 -> V_14 . V_108 . type == V_111 ) &&
( V_488 > ( V_495 + V_490 ) ) )
F_93 ( V_172 , L_109 ) ;
F_105 ( V_172 , L_110 , V_55 -> V_283 , V_742 ) ;
V_55 -> V_283 = V_742 ;
if ( F_57 ( V_55 ) )
F_365 ( V_2 ) ;
return 0 ;
}
static int F_413 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_17 , V_347 ;
if ( F_14 ( V_744 , & V_2 -> V_34 ) )
return - V_745 ;
F_379 ( V_55 ) ;
V_17 = F_402 ( V_2 ) ;
if ( V_17 )
goto V_740;
V_17 = F_405 ( V_2 ) ;
if ( V_17 )
goto V_741;
F_353 ( V_2 ) ;
V_17 = F_236 ( V_2 ) ;
if ( V_17 )
goto V_746;
if ( V_2 -> V_610 > 1 )
V_347 = V_2 -> V_601 ;
else
V_347 = V_2 -> V_77 ;
V_17 = F_347 ( V_55 , V_347 ) ;
if ( V_17 )
goto V_747;
if ( V_2 -> V_610 > 1 &&
V_2 -> V_93 > V_748 )
V_347 = V_748 ;
else
V_347 = V_2 -> V_93 ;
V_17 = F_348 ( V_55 , V_347 ) ;
if ( V_17 )
goto V_747;
F_414 ( V_2 ) ;
F_363 ( V_2 ) ;
return 0 ;
V_747:
F_237 ( V_2 ) ;
V_746:
F_410 ( V_2 ) ;
V_741:
F_409 ( V_2 ) ;
V_740:
F_371 ( V_2 ) ;
return V_17 ;
}
static void F_415 ( struct V_1 * V_2 )
{
F_416 ( V_2 ) ;
F_368 ( V_2 ) ;
F_237 ( V_2 ) ;
F_409 ( V_2 ) ;
F_410 ( V_2 ) ;
}
static int F_417 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
F_418 ( V_2 ) ;
F_415 ( V_2 ) ;
F_377 ( V_2 ) ;
F_70 ( V_2 ) ;
return 0 ;
}
static int F_419 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_420 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
T_1 V_17 ;
V_2 -> V_14 . V_39 = V_2 -> V_387 ;
F_421 ( V_9 , V_749 ) ;
F_422 ( V_9 ) ;
F_423 ( V_9 ) ;
V_17 = F_424 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_111 ) ;
return V_17 ;
}
F_33 () ;
F_34 ( V_750 , & V_2 -> V_34 ) ;
F_425 ( V_9 ) ;
F_426 ( V_9 , false ) ;
F_371 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_751 , ~ 0 ) ;
F_427 () ;
V_17 = F_428 ( V_2 ) ;
if ( ! V_17 && F_57 ( V_55 ) )
V_17 = F_413 ( V_55 ) ;
F_429 () ;
if ( V_17 )
return V_17 ;
F_430 ( V_55 ) ;
return 0 ;
}
static int F_431 ( struct V_5 * V_9 , bool * V_752 )
{
struct V_1 * V_2 = F_420 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_753 , V_541 ;
T_1 V_754 = V_2 -> V_755 ;
#ifdef F_432
int V_756 = 0 ;
#endif
F_433 ( V_55 ) ;
F_427 () ;
if ( F_57 ( V_55 ) )
F_415 ( V_2 ) ;
F_429 () ;
F_434 ( V_2 ) ;
#ifdef F_432
V_756 = F_423 ( V_9 ) ;
if ( V_756 )
return V_756 ;
#endif
if ( V_14 -> V_108 . V_328 . V_757 )
V_14 -> V_108 . V_328 . V_757 ( V_14 ) ;
if ( V_754 ) {
F_304 ( V_55 ) ;
if ( V_14 -> V_108 . V_328 . V_656 )
V_14 -> V_108 . V_328 . V_656 ( V_14 ) ;
if ( V_754 & V_758 ) {
V_541 = F_37 ( V_14 , V_545 ) ;
V_541 |= V_551 ;
F_71 ( V_14 , V_545 , V_541 ) ;
}
V_753 = F_37 ( V_14 , V_759 ) ;
V_753 |= V_760 ;
F_71 ( V_14 , V_759 , V_753 ) ;
F_71 ( V_14 , V_761 , V_754 ) ;
} else {
F_71 ( V_14 , V_762 , 0 ) ;
F_71 ( V_14 , V_761 , 0 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_109 :
F_426 ( V_9 , false ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_426 ( V_9 , ! ! V_754 ) ;
break;
default:
break;
}
* V_752 = ! ! V_754 ;
F_70 ( V_2 ) ;
if ( ! F_15 ( V_750 , & V_2 -> V_34 ) )
F_435 ( V_9 ) ;
return 0 ;
}
static int F_436 ( struct V_5 * V_9 , T_13 V_34 )
{
int V_756 ;
bool V_763 ;
V_756 = F_431 ( V_9 , & V_763 ) ;
if ( V_756 )
return V_756 ;
if ( V_763 ) {
F_437 ( V_9 ) ;
} else {
F_426 ( V_9 , false ) ;
F_421 ( V_9 , V_764 ) ;
}
return 0 ;
}
static void F_438 ( struct V_5 * V_9 )
{
bool V_763 ;
F_431 ( V_9 , & V_763 ) ;
if ( V_765 == V_766 ) {
F_426 ( V_9 , V_763 ) ;
F_421 ( V_9 , V_764 ) ;
}
}
void F_439 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_122 * V_123 = & V_2 -> V_124 ;
T_6 V_767 = 0 ;
T_1 V_48 , V_768 = 0 , V_769 , V_770 , V_771 , V_772 , V_773 ;
T_6 V_251 = 0 , V_174 = 0 , V_774 = 0 ;
T_6 V_221 = 0 , V_276 = 0 ;
T_6 V_170 = 0 , V_144 = 0 , V_775 = 0 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_662 , & V_2 -> V_34 ) )
return;
if ( V_2 -> V_154 & V_501 ) {
T_6 V_232 = 0 ;
T_6 V_233 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_232 += V_2 -> V_67 [ V_48 ] -> V_212 . V_232 ;
V_233 += V_2 -> V_67 [ V_48 ] -> V_212 . V_233 ;
}
V_2 -> V_776 = V_232 ;
V_2 -> V_777 = V_233 ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_67 = V_2 -> V_67 [ V_48 ] ;
V_251 += V_67 -> V_212 . V_251 ;
V_221 += V_67 -> V_212 . V_221 ;
V_276 += V_67 -> V_212 . V_276 ;
V_775 += V_67 -> V_212 . V_213 ;
V_170 += V_67 -> V_124 . V_170 ;
V_144 += V_67 -> V_124 . V_144 ;
}
V_2 -> V_251 = V_251 ;
V_2 -> V_221 = V_221 ;
V_2 -> V_276 = V_276 ;
V_2 -> V_775 = V_775 ;
V_55 -> V_124 . V_778 = V_170 ;
V_55 -> V_124 . V_779 = V_144 ;
V_170 = 0 ;
V_144 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_58 = V_2 -> V_58 [ V_48 ] ;
V_174 += V_58 -> V_152 . V_174 ;
V_774 += V_58 -> V_152 . V_774 ;
V_170 += V_58 -> V_124 . V_170 ;
V_144 += V_58 -> V_124 . V_144 ;
}
V_2 -> V_174 = V_174 ;
V_2 -> V_774 = V_774 ;
V_55 -> V_124 . V_780 = V_170 ;
V_55 -> V_124 . V_781 = V_144 ;
V_123 -> V_782 += F_37 ( V_14 , V_783 ) ;
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ ) {
V_769 = F_37 ( V_14 , F_440 ( V_48 ) ) ;
V_768 += V_769 ;
V_123 -> V_769 [ V_48 ] += V_769 ;
V_767 += V_123 -> V_769 [ V_48 ] ;
V_123 -> V_784 [ V_48 ] += F_37 ( V_14 , F_441 ( V_48 ) ) ;
V_123 -> V_785 [ V_48 ] += F_37 ( V_14 , F_442 ( V_48 ) ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_123 -> V_786 [ V_48 ] += F_37 ( V_14 , F_443 ( V_48 ) ) ;
V_123 -> V_787 [ V_48 ] += F_37 ( V_14 , F_444 ( V_48 ) ) ;
V_123 -> V_788 [ V_48 ] += F_37 ( V_14 , F_445 ( V_48 ) ) ;
V_123 -> V_789 [ V_48 ] +=
F_37 ( V_14 , F_446 ( V_48 ) ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_123 -> V_789 [ V_48 ] +=
F_37 ( V_14 , F_447 ( V_48 ) ) ;
break;
default:
break;
}
}
for ( V_48 = 0 ; V_48 < 16 ; V_48 ++ ) {
V_123 -> V_790 [ V_48 ] += F_37 ( V_14 , F_448 ( V_48 ) ) ;
V_123 -> V_791 [ V_48 ] += F_37 ( V_14 , F_449 ( V_48 ) ) ;
if ( ( V_14 -> V_108 . type == V_111 ) ||
( V_14 -> V_108 . type == V_112 ) ||
( V_14 -> V_108 . type == V_113 ) ||
( V_14 -> V_108 . type == V_114 ) ) {
V_123 -> V_787 [ V_48 ] += F_37 ( V_14 , F_450 ( V_48 ) ) ;
F_37 ( V_14 , F_451 ( V_48 ) ) ;
V_123 -> V_788 [ V_48 ] += F_37 ( V_14 , F_452 ( V_48 ) ) ;
F_37 ( V_14 , F_453 ( V_48 ) ) ;
}
}
V_123 -> V_792 += F_37 ( V_14 , V_793 ) ;
V_123 -> V_792 -= V_768 ;
F_83 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_123 -> V_794 += F_37 ( V_14 , V_795 ) ;
V_123 -> V_796 += F_37 ( V_14 , V_797 ) ;
V_123 -> V_798 += F_37 ( V_14 , V_799 ) ;
V_123 -> V_800 += F_37 ( V_14 , V_801 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
V_123 -> V_802 += F_37 ( V_14 , V_803 ) ;
V_123 -> V_804 += F_37 ( V_14 , V_805 ) ;
V_123 -> V_806 += F_37 ( V_14 , V_807 ) ;
V_123 -> V_808 += F_37 ( V_14 , V_809 ) ;
case V_111 :
for ( V_48 = 0 ; V_48 < 16 ; V_48 ++ )
V_2 -> V_810 +=
F_37 ( V_14 , F_454 ( V_48 ) ) ;
V_123 -> V_796 += F_37 ( V_14 , V_811 ) ;
F_37 ( V_14 , V_797 ) ;
V_123 -> V_798 += F_37 ( V_14 , V_812 ) ;
F_37 ( V_14 , V_799 ) ;
V_123 -> V_800 += F_37 ( V_14 , V_813 ) ;
F_37 ( V_14 , V_801 ) ;
V_123 -> V_794 += F_37 ( V_14 , V_814 ) ;
V_123 -> V_815 += F_37 ( V_14 , V_816 ) ;
V_123 -> V_817 += F_37 ( V_14 , V_818 ) ;
#ifdef F_176
V_123 -> V_819 += F_37 ( V_14 , V_820 ) ;
V_123 -> V_821 += F_37 ( V_14 , V_822 ) ;
V_123 -> V_823 += F_37 ( V_14 , V_824 ) ;
V_123 -> V_825 += F_37 ( V_14 , V_826 ) ;
V_123 -> V_827 += F_37 ( V_14 , V_828 ) ;
V_123 -> V_829 += F_37 ( V_14 , V_830 ) ;
if ( V_2 -> V_578 . V_831 ) {
struct V_832 * V_578 = & V_2 -> V_578 ;
struct V_833 * V_831 ;
unsigned int V_175 ;
T_6 V_834 = 0 , V_835 = 0 ;
F_455 (cpu) {
V_831 = F_456 ( V_578 -> V_831 , V_175 ) ;
V_834 += V_831 -> V_834 ;
V_835 += V_831 -> V_835 ;
}
V_123 -> V_836 = V_834 ;
V_123 -> V_837 = V_835 ;
}
#endif
break;
default:
break;
}
V_770 = F_37 ( V_14 , V_838 ) ;
V_123 -> V_770 += V_770 ;
V_123 -> V_839 += F_37 ( V_14 , V_840 ) ;
if ( V_14 -> V_108 . type == V_109 )
V_123 -> V_839 -= V_770 ;
V_123 -> V_841 += F_37 ( V_14 , V_842 ) ;
V_123 -> V_843 += F_37 ( V_14 , V_844 ) ;
V_123 -> V_845 += F_37 ( V_14 , V_846 ) ;
V_123 -> V_847 += F_37 ( V_14 , V_848 ) ;
V_123 -> V_849 += F_37 ( V_14 , V_850 ) ;
V_123 -> V_851 += F_37 ( V_14 , V_852 ) ;
V_123 -> V_853 += F_37 ( V_14 , V_854 ) ;
V_123 -> V_855 += F_37 ( V_14 , V_856 ) ;
V_771 = F_37 ( V_14 , V_857 ) ;
V_123 -> V_858 += V_771 ;
V_772 = F_37 ( V_14 , V_859 ) ;
V_123 -> V_860 += V_772 ;
V_123 -> V_861 += F_37 ( V_14 , V_862 ) ;
V_123 -> V_863 += F_37 ( V_14 , V_864 ) ;
V_773 = V_771 + V_772 ;
V_123 -> V_861 -= V_773 ;
V_123 -> V_863 -= V_773 ;
V_123 -> V_798 -= ( V_773 * ( V_865 + V_490 ) ) ;
V_123 -> V_866 += F_37 ( V_14 , V_867 ) ;
V_123 -> V_868 += F_37 ( V_14 , V_869 ) ;
V_123 -> V_870 += F_37 ( V_14 , V_871 ) ;
V_123 -> V_872 += F_37 ( V_14 , V_873 ) ;
V_123 -> V_874 += F_37 ( V_14 , V_875 ) ;
V_123 -> V_874 -= V_773 ;
V_123 -> V_876 += F_37 ( V_14 , V_877 ) ;
V_123 -> V_878 += F_37 ( V_14 , V_879 ) ;
V_123 -> V_880 += F_37 ( V_14 , V_881 ) ;
V_123 -> V_882 += F_37 ( V_14 , V_883 ) ;
V_123 -> V_884 += F_37 ( V_14 , V_885 ) ;
V_123 -> V_886 += F_37 ( V_14 , V_887 ) ;
V_55 -> V_124 . V_888 = V_123 -> V_839 ;
V_55 -> V_124 . V_889 = V_123 -> V_782 + V_123 -> V_855 ;
V_55 -> V_124 . V_890 = 0 ;
V_55 -> V_124 . V_891 = V_123 -> V_855 ;
V_55 -> V_124 . V_892 = V_123 -> V_782 ;
V_55 -> V_124 . V_893 = V_767 ;
}
static void F_457 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
if ( ! ( V_2 -> V_154 & V_355 ) )
return;
V_2 -> V_154 &= ~ V_355 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
if ( ! ( V_2 -> V_139 & V_354 ) )
return;
V_2 -> V_894 ++ ;
if ( F_458 ( V_14 ) == 0 ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_243 ( V_363 ,
& ( V_2 -> V_58 [ V_48 ] -> V_34 ) ) ;
F_71 ( V_14 , V_346 , V_356 ) ;
} else {
F_103 ( V_172 , L_112
L_113 ) ;
}
}
static void F_459 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_895 = 0 ;
int V_48 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_662 , & V_2 -> V_34 ) )
return;
if ( F_109 ( V_2 -> V_55 ) ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_460 ( V_2 -> V_58 [ V_48 ] ) ;
}
if ( ! ( V_2 -> V_139 & V_378 ) ) {
F_71 ( V_14 , V_119 ,
( V_896 | V_897 ) ) ;
} else {
for ( V_48 = 0 ; V_48 < V_2 -> V_189 ; V_48 ++ ) {
struct V_157 * V_898 = V_2 -> V_158 [ V_48 ] ;
if ( V_898 -> V_287 . V_120 || V_898 -> V_162 . V_120 )
V_895 |= ( ( T_6 ) 1 << V_48 ) ;
}
}
F_75 ( V_2 , V_895 ) ;
}
static void F_461 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_899 = V_2 -> V_899 ;
bool V_330 = V_2 -> V_330 ;
bool V_135 = V_2 -> V_136 . V_137 ;
if ( ! ( V_2 -> V_139 & V_342 ) )
return;
if ( V_14 -> V_108 . V_328 . V_329 ) {
V_14 -> V_108 . V_328 . V_329 ( V_14 , & V_899 , & V_330 , false ) ;
} else {
V_899 = V_900 ;
V_330 = true ;
}
if ( V_2 -> V_138 )
V_135 |= ! ! ( V_2 -> V_138 -> V_135 ) ;
if ( V_330 && ! ( ( V_2 -> V_139 & V_140 ) && V_135 ) ) {
V_14 -> V_108 . V_328 . V_901 ( V_14 ) ;
F_462 ( V_2 ) ;
}
if ( V_330 ||
F_463 ( V_171 , ( V_2 -> V_343 +
V_902 ) ) ) {
V_2 -> V_139 &= ~ V_342 ;
F_71 ( V_14 , V_346 , V_345 ) ;
F_212 ( V_14 ) ;
}
V_2 -> V_330 = V_330 ;
V_2 -> V_899 = V_899 ;
}
static void F_464 ( struct V_1 * V_2 )
{
#ifdef F_354
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_903 V_904 = {
. V_905 = V_906 ,
. V_240 = 0 ,
} ;
T_4 V_579 = 0 ;
if ( V_2 -> V_564 & V_907 )
V_579 = F_465 ( V_55 , & V_904 ) ;
V_2 -> V_908 = ( V_579 > 1 ) ? ( F_466 ( V_579 ) - 1 ) : 0 ;
#endif
}
static void F_467 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_95 ;
struct V_613 * V_614 ;
T_1 V_899 = V_2 -> V_899 ;
bool V_909 , V_910 ;
if ( F_109 ( V_55 ) )
return;
V_2 -> V_154 &= ~ V_634 ;
switch ( V_14 -> V_108 . type ) {
case V_109 : {
T_1 V_911 = F_37 ( V_14 , V_545 ) ;
T_1 V_912 = F_37 ( V_14 , V_913 ) ;
V_909 = ! ! ( V_911 & V_914 ) ;
V_910 = ! ! ( V_912 & V_915 ) ;
}
break;
case V_112 :
case V_113 :
case V_114 :
case V_111 : {
T_1 V_916 = F_37 ( V_14 , V_917 ) ;
T_1 V_918 = F_37 ( V_14 , V_919 ) ;
V_909 = ! ! ( V_916 & V_920 ) ;
V_910 = ! ! ( V_918 & V_921 ) ;
}
break;
default:
V_910 = false ;
V_909 = false ;
break;
}
V_2 -> V_922 = V_171 ;
if ( F_14 ( V_673 , & V_2 -> V_34 ) )
F_468 ( V_2 ) ;
F_105 ( V_156 , L_114 ,
( V_899 == V_900 ?
L_115 :
( V_899 == V_923 ?
L_116 :
( V_899 == V_924 ?
L_117 :
L_118 ) ) ) ,
( ( V_909 && V_910 ) ? L_119 :
( V_909 ? L_120 :
( V_910 ? L_121 : L_122 ) ) ) ) ;
F_469 ( V_55 ) ;
F_470 ( V_2 ) ;
F_471 ( V_2 -> V_55 ) ;
F_427 () ;
F_351 (adapter->netdev, upper, iter) {
if ( F_352 ( V_95 ) ) {
struct V_615 * V_238 = F_89 ( V_95 ) ;
if ( V_238 -> V_617 )
F_471 ( V_95 ) ;
}
}
F_429 () ;
F_464 ( V_2 ) ;
F_382 ( V_2 ) ;
}
static void F_472 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_330 = false ;
V_2 -> V_899 = 0 ;
if ( ! F_109 ( V_55 ) )
return;
if ( F_358 ( V_14 ) && V_14 -> V_108 . type == V_109 )
V_2 -> V_154 |= V_634 ;
if ( F_14 ( V_673 , & V_2 -> V_34 ) )
F_468 ( V_2 ) ;
F_105 ( V_156 , L_123 ) ;
F_379 ( V_55 ) ;
F_382 ( V_2 ) ;
}
static bool F_473 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_58 = V_2 -> V_58 [ V_48 ] ;
if ( V_58 -> V_80 != V_58 -> V_79 )
return true ;
}
return false ;
}
static bool F_474 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_925 * V_926 = & V_2 -> V_403 [ V_478 ] ;
T_1 V_927 = F_475 ( 1 , ~ V_926 -> V_117 ) ;
int V_48 , V_49 ;
if ( ! V_2 -> V_295 )
return false ;
if ( V_14 -> V_108 . type >= V_113 )
return false ;
for ( V_48 = 0 ; V_48 < V_2 -> V_295 ; V_48 ++ ) {
for ( V_49 = 0 ; V_49 < V_927 ; V_49 ++ ) {
T_1 V_928 , V_929 ;
V_928 = F_37 ( V_14 , F_476 ( V_927 , V_48 , V_49 ) ) ;
V_929 = F_37 ( V_14 , F_477 ( V_927 , V_48 , V_49 ) ) ;
if ( V_928 != V_929 )
return true ;
}
}
return false ;
}
static void F_478 ( struct V_1 * V_2 )
{
if ( ! F_109 ( V_2 -> V_55 ) ) {
if ( F_473 ( V_2 ) ||
F_474 ( V_2 ) ) {
F_93 ( V_156 , L_124 ) ;
V_2 -> V_154 |= V_155 ;
}
}
}
static inline void F_479 ( struct V_1 * V_2 ,
struct V_5 * V_930 )
{
if ( ! F_480 ( V_930 ) )
F_11 ( L_125 ) ;
F_18 ( L_126 , F_481 ( V_930 ) ) ;
F_482 ( V_930 , V_931 , V_932 ) ;
F_369 ( 100 ) ;
}
static void F_483 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
struct V_5 * V_930 ;
T_1 V_933 ;
int V_934 ;
unsigned short V_935 ;
if ( ! ( F_109 ( V_2 -> V_55 ) ) )
return;
V_933 = F_37 ( V_14 , V_936 ) ;
if ( V_933 )
return;
if ( ! V_9 )
return;
V_934 = F_484 ( V_9 , V_937 ) ;
if ( ! V_934 )
return;
F_25 ( V_9 , V_934 + V_938 , & V_935 ) ;
V_930 = F_485 ( V_9 -> V_683 , V_935 , NULL ) ;
while ( V_930 ) {
if ( V_930 -> V_939 && ( V_930 -> V_940 == V_9 ) ) {
T_2 V_941 ;
F_25 ( V_930 , V_942 , & V_941 ) ;
if ( V_941 & V_943 )
F_479 ( V_2 , V_930 ) ;
}
V_930 = F_485 ( V_9 -> V_683 , V_935 , V_930 ) ;
}
}
static void F_486 ( struct V_1 * V_2 )
{
T_1 V_944 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ||
V_2 -> V_295 == 0 )
return;
V_944 = F_37 ( & V_2 -> V_14 , V_945 ) ;
if ( ! V_944 )
return;
F_93 ( V_156 , L_127 , V_944 ) ;
}
static void F_486 ( struct V_1 T_14 * V_2 )
{
}
static void
F_483 ( struct V_1 T_14 * V_2 )
{
}
static void F_487 ( struct V_1 * V_2 )
{
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_662 , & V_2 -> V_34 ) )
return;
F_461 ( V_2 ) ;
if ( V_2 -> V_330 )
F_467 ( V_2 ) ;
else
F_472 ( V_2 ) ;
F_483 ( V_2 ) ;
F_486 ( V_2 ) ;
F_439 ( V_2 ) ;
F_478 ( V_2 ) ;
}
static void F_488 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_3 V_17 ;
if ( ! ( V_2 -> V_154 & V_634 ) &&
! ( V_2 -> V_154 & V_339 ) )
return;
if ( F_15 ( V_664 , & V_2 -> V_34 ) )
return;
V_17 = V_14 -> V_331 . V_328 . V_946 ( V_14 ) ;
if ( V_17 == V_667 )
goto V_947;
if ( V_17 == V_666 ) {
V_2 -> V_154 |= V_339 ;
}
if ( V_17 )
goto V_947;
if ( ! ( V_2 -> V_154 & V_339 ) )
goto V_947;
V_2 -> V_154 &= ~ V_339 ;
if ( V_14 -> V_108 . type == V_109 )
V_17 = V_14 -> V_331 . V_328 . V_948 ( V_14 ) ;
else
V_17 = V_14 -> V_108 . V_328 . V_949 ( V_14 ) ;
if ( V_17 == V_667 )
goto V_947;
V_2 -> V_139 |= V_340 ;
F_105 ( V_172 , L_128 , V_14 -> V_331 . V_950 ) ;
V_947:
F_34 ( V_664 , & V_2 -> V_34 ) ;
if ( ( V_17 == V_667 ) &&
( V_2 -> V_55 -> V_951 == V_952 ) ) {
F_18 ( L_129
L_130 ) ;
F_18 ( L_131
L_132 ) ;
F_489 ( V_2 -> V_55 ) ;
}
}
static void F_490 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_20 ;
bool V_635 = false ;
if ( ! ( V_2 -> V_139 & V_340 ) )
return;
if ( F_15 ( V_664 , & V_2 -> V_34 ) )
return;
V_2 -> V_139 &= ~ V_340 ;
V_20 = V_14 -> V_331 . V_638 ;
if ( ( ! V_20 ) && ( V_14 -> V_108 . V_328 . V_639 ) ) {
V_14 -> V_108 . V_328 . V_639 ( V_14 , & V_20 , & V_635 ) ;
if ( ! V_635 ) {
if ( V_20 & V_900 )
V_20 = V_900 ;
}
}
if ( V_14 -> V_108 . V_328 . V_640 )
V_14 -> V_108 . V_328 . V_640 ( V_14 , V_20 , true ) ;
V_2 -> V_139 |= V_342 ;
V_2 -> V_343 = V_171 ;
F_34 ( V_664 , & V_2 -> V_34 ) ;
}
static void F_491 ( unsigned long V_92 )
{
struct V_1 * V_2 = (struct V_1 * ) V_92 ;
unsigned long V_953 ;
if ( V_2 -> V_139 & V_342 )
V_953 = V_954 / 10 ;
else
V_953 = V_954 * 2 ;
F_364 ( & V_2 -> V_660 , V_953 + V_171 ) ;
F_13 ( V_2 ) ;
}
static void F_492 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_154 & V_155 ) )
return;
V_2 -> V_154 &= ~ V_155 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_662 , & V_2 -> V_34 ) )
return;
F_54 ( V_2 ) ;
F_493 ( V_2 -> V_55 , L_133 ) ;
V_2 -> V_173 ++ ;
F_427 () ;
F_365 ( V_2 ) ;
F_429 () ;
}
static void F_494 ( struct V_955 * V_956 )
{
struct V_1 * V_2 = F_196 ( V_956 ,
struct V_1 ,
V_37 ) ;
if ( F_22 ( V_2 -> V_14 . V_39 ) ) {
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
F_427 () ;
F_368 ( V_2 ) ;
F_429 () ;
}
F_31 ( V_2 ) ;
return;
}
F_492 ( V_2 ) ;
F_488 ( V_2 ) ;
F_490 ( V_2 ) ;
F_206 ( V_2 ) ;
F_487 ( V_2 ) ;
F_457 ( V_2 ) ;
F_459 ( V_2 ) ;
if ( F_14 ( V_673 , & V_2 -> V_34 ) ) {
F_495 ( V_2 ) ;
F_496 ( V_2 ) ;
}
F_31 ( V_2 ) ;
}
static int F_497 ( struct V_57 * V_58 ,
struct V_59 * V_957 ,
T_4 * V_227 )
{
struct V_195 * V_89 = V_957 -> V_89 ;
T_1 V_958 , V_959 ;
T_1 V_960 , V_961 ;
int V_17 ;
if ( V_89 -> V_218 != V_962 )
return 0 ;
if ( ! F_498 ( V_89 ) )
return 0 ;
V_17 = F_499 ( V_89 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_959 = V_963 ;
if ( V_957 -> V_240 == F_156 ( V_964 ) ) {
struct V_965 * V_966 = F_500 ( V_89 ) ;
V_966 -> V_967 = 0 ;
V_966 -> V_968 = 0 ;
F_501 ( V_89 ) -> V_968 = ~ F_502 ( V_966 -> V_969 ,
V_966 -> V_970 , 0 ,
V_971 ,
0 ) ;
V_959 |= V_972 ;
V_957 -> V_973 |= V_974 |
V_975 |
V_976 ;
} else if ( F_503 ( V_89 ) ) {
F_504 ( V_89 ) -> V_977 = 0 ;
F_501 ( V_89 ) -> V_968 =
~ F_505 ( & F_504 ( V_89 ) -> V_969 ,
& F_504 ( V_89 ) -> V_970 ,
0 , V_971 , 0 ) ;
V_957 -> V_973 |= V_974 |
V_975 ;
}
V_961 = F_506 ( V_89 ) ;
* V_227 = F_507 ( V_89 ) + V_961 ;
V_957 -> V_168 = F_148 ( V_89 ) -> V_168 ;
V_957 -> V_167 += ( V_957 -> V_168 - 1 ) * * V_227 ;
V_960 = V_961 << V_978 ;
V_960 |= F_148 ( V_89 ) -> V_228 << V_979 ;
V_958 = F_508 ( V_89 ) ;
V_958 |= F_509 ( V_89 ) << V_980 ;
V_958 |= V_957 -> V_973 & V_981 ;
F_510 ( V_58 , V_958 , 0 , V_959 ,
V_960 ) ;
return 1 ;
}
static void F_511 ( struct V_57 * V_58 ,
struct V_59 * V_957 )
{
struct V_195 * V_89 = V_957 -> V_89 ;
T_1 V_958 = 0 ;
T_1 V_960 = 0 ;
T_1 V_959 = 0 ;
if ( V_89 -> V_218 != V_962 ) {
if ( ! ( V_957 -> V_973 & V_982 ) &&
! ( V_957 -> V_973 & V_983 ) )
return;
} else {
T_4 V_984 = 0 ;
switch ( V_957 -> V_240 ) {
case F_156 ( V_964 ) :
V_958 |= F_508 ( V_89 ) ;
V_959 |= V_972 ;
V_984 = F_500 ( V_89 ) -> V_240 ;
break;
case F_156 ( V_985 ) :
V_958 |= F_508 ( V_89 ) ;
V_984 = F_504 ( V_89 ) -> V_986 ;
break;
default:
if ( F_24 ( F_512 () ) ) {
F_513 ( V_58 -> V_73 ,
L_134 ,
V_957 -> V_240 ) ;
}
break;
}
switch ( V_984 ) {
case V_971 :
V_959 |= V_963 ;
V_960 = F_506 ( V_89 ) <<
V_978 ;
break;
case V_987 :
V_959 |= V_988 ;
V_960 = sizeof( struct V_989 ) <<
V_978 ;
break;
case V_990 :
V_960 = sizeof( struct V_991 ) <<
V_978 ;
break;
default:
if ( F_24 ( F_512 () ) ) {
F_513 ( V_58 -> V_73 ,
L_135 ,
V_984 ) ;
}
break;
}
V_957 -> V_973 |= V_975 ;
}
V_958 |= F_509 ( V_89 ) << V_980 ;
V_958 |= V_957 -> V_973 & V_981 ;
F_510 ( V_58 , V_958 , 0 ,
V_959 , V_960 ) ;
}
static T_1 F_514 ( struct V_195 * V_89 , T_1 V_973 )
{
T_1 V_992 = V_993 |
V_994 |
V_995 ;
V_992 |= F_515 ( V_973 , V_982 ,
V_996 ) ;
V_992 |= F_515 ( V_973 , V_974 ,
V_997 ) ;
V_992 |= F_515 ( V_973 , V_998 ,
V_999 ) ;
V_992 ^= F_515 ( V_89 -> V_1000 , 1 , V_995 ) ;
return V_992 ;
}
static void F_516 ( union V_61 * V_62 ,
T_1 V_973 , unsigned int V_1001 )
{
T_1 V_1002 = V_1001 << V_1003 ;
V_1002 |= F_515 ( V_973 ,
V_975 ,
V_1004 ) ;
V_1002 |= F_515 ( V_973 ,
V_976 ,
V_1005 ) ;
V_1002 |= F_515 ( V_973 ,
V_983 ,
V_1006 ) ;
V_62 -> V_224 . V_1002 = F_96 ( V_1002 ) ;
}
static int F_517 ( struct V_57 * V_58 , T_2 V_267 )
{
F_104 ( V_58 -> V_55 , V_58 -> V_86 ) ;
F_111 () ;
if ( F_99 ( F_110 ( V_58 ) < V_267 ) )
return - V_745 ;
F_518 ( V_58 -> V_55 , V_58 -> V_86 ) ;
++ V_58 -> V_152 . V_174 ;
return 0 ;
}
static inline int F_519 ( struct V_57 * V_58 , T_2 V_267 )
{
if ( F_99 ( F_110 ( V_58 ) >= V_267 ) )
return 0 ;
return F_517 ( V_58 , V_267 ) ;
}
static void F_520 ( struct V_57 * V_58 ,
struct V_59 * V_957 ,
const T_4 V_227 )
{
struct V_195 * V_89 = V_957 -> V_89 ;
struct V_59 * V_60 ;
union V_61 * V_62 ;
struct V_252 * V_253 ;
T_9 V_81 ;
unsigned int V_258 , V_267 ;
T_1 V_973 = V_957 -> V_973 ;
T_1 V_992 = F_514 ( V_89 , V_973 ) ;
T_2 V_48 = V_58 -> V_80 ;
V_62 = F_61 ( V_58 , V_48 ) ;
F_516 ( V_62 , V_973 , V_89 -> V_82 - V_227 ) ;
V_267 = F_147 ( V_89 ) ;
V_258 = V_89 -> V_258 ;
#ifdef F_176
if ( V_973 & V_1007 ) {
if ( V_258 < sizeof( struct V_286 ) ) {
V_267 -= sizeof( struct V_286 ) - V_258 ;
V_258 = 0 ;
} else {
V_258 -= sizeof( struct V_286 ) ;
}
}
#endif
V_81 = F_521 ( V_58 -> V_73 , V_89 -> V_92 , V_267 , V_121 ) ;
V_60 = V_957 ;
for ( V_253 = & F_148 ( V_89 ) -> V_254 [ 0 ] ; ; V_253 ++ ) {
if ( F_140 ( V_58 -> V_73 , V_81 ) )
goto V_1008;
F_81 ( V_60 , V_82 , V_267 ) ;
F_522 ( V_60 , V_81 , V_81 ) ;
V_62 -> V_224 . V_1009 = F_143 ( V_81 ) ;
while ( F_24 ( V_267 > V_1010 ) ) {
V_62 -> V_224 . V_1011 =
F_96 ( V_992 ^ V_1010 ) ;
V_48 ++ ;
V_62 ++ ;
if ( V_48 == V_58 -> V_88 ) {
V_62 = F_61 ( V_58 , 0 ) ;
V_48 = 0 ;
}
V_62 -> V_224 . V_1002 = 0 ;
V_81 += V_1010 ;
V_267 -= V_1010 ;
V_62 -> V_224 . V_1009 = F_143 ( V_81 ) ;
}
if ( F_99 ( ! V_258 ) )
break;
V_62 -> V_224 . V_1011 = F_96 ( V_992 ^ V_267 ) ;
V_48 ++ ;
V_62 ++ ;
if ( V_48 == V_58 -> V_88 ) {
V_62 = F_61 ( V_58 , 0 ) ;
V_48 = 0 ;
}
V_62 -> V_224 . V_1002 = 0 ;
#ifdef F_176
V_267 = F_346 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_267 = F_523 ( V_253 ) ;
#endif
V_258 -= V_267 ;
V_81 = F_524 ( V_58 -> V_73 , V_253 , 0 , V_267 ,
V_121 ) ;
V_60 = & V_58 -> V_78 [ V_48 ] ;
}
V_992 |= V_267 | V_1012 ;
V_62 -> V_224 . V_1011 = F_96 ( V_992 ) ;
F_525 ( F_107 ( V_58 ) , V_957 -> V_167 ) ;
V_957 -> V_84 = V_171 ;
F_144 () ;
V_957 -> V_83 = V_62 ;
V_48 ++ ;
if ( V_48 == V_58 -> V_88 )
V_48 = 0 ;
V_58 -> V_80 = V_48 ;
F_519 ( V_58 , V_1013 ) ;
if ( F_526 ( F_107 ( V_58 ) ) || ! V_89 -> V_1014 ) {
F_145 ( V_48 , V_58 -> V_146 ) ;
F_527 () ;
}
return;
V_1008:
F_401 ( V_58 -> V_73 , L_136 ) ;
for (; ; ) {
V_60 = & V_58 -> V_78 [ V_48 ] ;
F_77 ( V_58 , V_60 ) ;
if ( V_60 == V_957 )
break;
if ( V_48 == 0 )
V_48 = V_58 -> V_88 ;
V_48 -- ;
}
V_58 -> V_80 = V_48 ;
}
static void F_528 ( struct V_57 * V_120 ,
struct V_59 * V_957 )
{
struct V_157 * V_158 = V_120 -> V_158 ;
union V_1015 V_1016 = { . V_1017 = 0 } ;
union V_1015 V_1018 = { . V_1017 = 0 } ;
union {
unsigned char * V_1019 ;
struct V_965 * V_1020 ;
struct V_1021 * V_1022 ;
} V_1023 ;
struct V_1024 * V_1025 ;
T_12 V_1026 ;
if ( ! V_158 )
return;
if ( ! V_120 -> V_388 )
return;
V_120 -> V_389 ++ ;
V_1023 . V_1019 = F_529 ( V_957 -> V_89 ) ;
if ( ( V_957 -> V_240 != F_156 ( V_985 ) ||
V_1023 . V_1022 -> V_986 != V_971 ) &&
( V_957 -> V_240 != F_156 ( V_964 ) ||
V_1023 . V_1020 -> V_240 != V_971 ) )
return;
V_1025 = F_501 ( V_957 -> V_89 ) ;
if ( ! V_1025 || V_1025 -> V_1027 )
return;
if ( ! V_1025 -> V_1028 && ( V_120 -> V_389 < V_120 -> V_388 ) )
return;
V_120 -> V_389 = 0 ;
V_1026 = F_156 ( V_957 -> V_973 >> V_1029 ) ;
V_1016 . V_1030 . V_1026 = V_1026 ;
if ( V_957 -> V_973 & ( V_1031 | V_982 ) )
V_1018 . V_1032 . V_1033 ^= V_1025 -> V_1034 ^ F_156 ( V_239 ) ;
else
V_1018 . V_1032 . V_1033 ^= V_1025 -> V_1034 ^ V_957 -> V_240 ;
V_1018 . V_1032 . V_1035 ^= V_1025 -> V_1036 ;
if ( V_957 -> V_240 == F_156 ( V_964 ) ) {
V_1016 . V_1030 . V_1037 = V_1038 ;
V_1018 . V_1039 ^= V_1023 . V_1020 -> V_969 ^ V_1023 . V_1020 -> V_970 ;
} else {
V_1016 . V_1030 . V_1037 = V_1040 ;
V_1018 . V_1039 ^= V_1023 . V_1022 -> V_969 . V_1041 [ 0 ] ^
V_1023 . V_1022 -> V_969 . V_1041 [ 1 ] ^
V_1023 . V_1022 -> V_969 . V_1041 [ 2 ] ^
V_1023 . V_1022 -> V_969 . V_1041 [ 3 ] ^
V_1023 . V_1022 -> V_970 . V_1041 [ 0 ] ^
V_1023 . V_1022 -> V_970 . V_1041 [ 1 ] ^
V_1023 . V_1022 -> V_970 . V_1041 [ 2 ] ^
V_1023 . V_1022 -> V_970 . V_1041 [ 3 ] ;
}
F_530 ( & V_158 -> V_2 -> V_14 ,
V_1016 , V_1018 , V_120 -> V_86 ) ;
}
static T_2 F_531 ( struct V_54 * V_73 , struct V_195 * V_89 ,
void * V_1042 , T_15 V_1043 )
{
struct V_599 * V_1044 = V_1042 ;
#ifdef F_176
struct V_1 * V_2 ;
struct V_925 * V_1045 ;
int V_1046 ;
#endif
if ( V_1044 )
return V_89 -> V_1047 + V_1044 -> V_607 ;
#ifdef F_176
switch ( F_532 ( V_89 ) ) {
case F_156 ( V_1048 ) :
case F_156 ( V_1049 ) :
V_2 = F_89 ( V_73 ) ;
if ( V_2 -> V_139 & V_493 )
break;
default:
return V_1043 ( V_73 , V_89 ) ;
}
V_1045 = & V_2 -> V_403 [ V_1050 ] ;
V_1046 = F_533 ( V_89 ) ? F_534 ( V_89 ) :
F_535 () ;
while ( V_1046 >= V_1045 -> V_405 )
V_1046 -= V_1045 -> V_405 ;
return V_1046 + V_1045 -> V_1051 ;
#else
return V_1043 ( V_73 , V_89 ) ;
#endif
}
T_16 F_536 ( struct V_195 * V_89 ,
struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_59 * V_957 ;
int V_1052 ;
T_1 V_973 = 0 ;
unsigned short V_1045 ;
T_2 V_88 = F_537 ( F_147 ( V_89 ) ) ;
T_12 V_240 = V_89 -> V_240 ;
T_4 V_227 = 0 ;
for ( V_1045 = 0 ; V_1045 < F_148 ( V_89 ) -> V_273 ; V_1045 ++ )
V_88 += F_537 ( F_148 ( V_89 ) -> V_254 [ V_1045 ] . V_267 ) ;
if ( F_519 ( V_58 , V_88 + 3 ) ) {
V_58 -> V_152 . V_774 ++ ;
return V_1053 ;
}
V_957 = & V_58 -> V_78 [ V_58 -> V_80 ] ;
V_957 -> V_89 = V_89 ;
V_957 -> V_167 = V_89 -> V_82 ;
V_957 -> V_168 = 1 ;
if ( F_538 ( V_89 ) ) {
V_973 |= F_539 ( V_89 ) << V_1029 ;
V_973 |= V_982 ;
} else if ( V_240 == F_156 ( V_239 ) ) {
struct V_1054 * V_1055 , V_1056 ;
V_1055 = F_540 ( V_89 , V_489 , sizeof( V_1056 ) , & V_1056 ) ;
if ( ! V_1055 )
goto V_1057;
V_973 |= F_541 ( V_1055 -> V_1058 ) <<
V_1029 ;
V_973 |= V_1031 ;
}
V_240 = F_532 ( V_89 ) ;
if ( F_24 ( F_148 ( V_89 ) -> V_973 & V_1059 ) &&
V_2 -> V_1060 &&
! F_542 ( V_1061 ,
& V_2 -> V_34 ) ) {
F_148 ( V_89 ) -> V_973 |= V_1062 ;
V_973 |= V_998 ;
V_2 -> V_1063 = F_543 ( V_89 ) ;
V_2 -> V_1064 = V_171 ;
F_16 ( & V_2 -> V_1065 ) ;
}
F_544 ( V_89 ) ;
#ifdef F_287
if ( V_2 -> V_139 & V_398 )
V_973 |= V_983 ;
#endif
if ( ( V_2 -> V_139 & V_140 ) &&
( ( V_973 & ( V_982 | V_1031 ) ) ||
( V_89 -> V_1066 != V_1067 ) ) ) {
V_973 &= ~ V_1068 ;
V_973 |= ( V_89 -> V_1066 & 0x7 ) <<
V_1069 ;
if ( V_973 & V_1031 ) {
struct V_1070 * V_1055 ;
if ( F_499 ( V_89 , 0 ) )
goto V_1057;
V_1055 = (struct V_1070 * ) V_89 -> V_92 ;
V_1055 -> V_1058 = F_156 ( V_973 >>
V_1029 ) ;
} else {
V_973 |= V_982 ;
}
}
V_957 -> V_973 = V_973 ;
V_957 -> V_240 = V_240 ;
#ifdef F_176
if ( ( V_240 == F_156 ( V_1048 ) ) &&
( V_58 -> V_55 -> V_196 & ( V_1071 | V_1072 ) ) ) {
V_1052 = F_545 ( V_58 , V_957 , & V_227 ) ;
if ( V_1052 < 0 )
goto V_1057;
goto V_1073;
}
#endif
V_1052 = F_497 ( V_58 , V_957 , & V_227 ) ;
if ( V_1052 < 0 )
goto V_1057;
else if ( ! V_1052 )
F_511 ( V_58 , V_957 ) ;
if ( F_14 ( V_363 , & V_58 -> V_34 ) )
F_528 ( V_58 , V_957 ) ;
#ifdef F_176
V_1073:
#endif
F_520 ( V_58 , V_957 , V_227 ) ;
return V_1074 ;
V_1057:
F_78 ( V_957 -> V_89 ) ;
V_957 -> V_89 = NULL ;
return V_1074 ;
}
static T_16 F_546 ( struct V_195 * V_89 ,
struct V_54 * V_55 ,
struct V_57 * V_120 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_57 * V_58 ;
if ( F_547 ( V_89 , 17 ) )
return V_1074 ;
V_58 = V_120 ? V_120 : V_2 -> V_58 [ V_89 -> V_1047 ] ;
return F_536 ( V_89 , V_2 , V_58 ) ;
}
static T_16 F_548 ( struct V_195 * V_89 ,
struct V_54 * V_55 )
{
return F_546 ( V_89 , V_55 , NULL ) ;
}
static int F_549 ( struct V_54 * V_55 , void * V_1075 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1076 * V_531 = V_1075 ;
int V_636 ;
if ( ! F_349 ( V_531 -> V_1077 ) )
return - V_1078 ;
F_298 ( V_2 , V_14 -> V_108 . V_531 , F_271 ( 0 ) ) ;
memcpy ( V_55 -> V_612 , V_531 -> V_1077 , V_55 -> V_670 ) ;
memcpy ( V_14 -> V_108 . V_531 , V_531 -> V_1077 , V_55 -> V_670 ) ;
V_636 = F_295 ( V_2 , V_14 -> V_108 . V_531 , F_271 ( 0 ) ) ;
return V_636 > 0 ? 0 : V_636 ;
}
static int
F_550 ( struct V_54 * V_55 , int V_1079 , int V_1080 , T_2 V_531 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_4 ;
int V_1081 ;
if ( V_1079 != V_14 -> V_331 . V_1082 . V_1079 )
return - V_537 ;
V_1081 = V_14 -> V_331 . V_328 . V_1083 ( V_14 , V_531 , V_1080 , & V_4 ) ;
if ( ! V_1081 )
V_1081 = V_4 ;
return V_1081 ;
}
static int F_551 ( struct V_54 * V_55 , int V_1079 , int V_1080 ,
T_2 V_531 , T_2 V_4 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_1079 != V_14 -> V_331 . V_1082 . V_1079 )
return - V_537 ;
return V_14 -> V_331 . V_328 . V_1084 ( V_14 , V_531 , V_1080 , V_4 ) ;
}
static int F_552 ( struct V_54 * V_55 , struct V_1085 * V_1086 , int V_1087 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
switch ( V_1087 ) {
case V_1088 :
return F_553 ( V_2 , V_1086 ) ;
case V_1089 :
return F_554 ( V_2 , V_1086 ) ;
default:
return F_555 ( & V_2 -> V_14 . V_331 . V_1082 , F_556 ( V_1086 ) , V_1087 ) ;
}
}
static int F_557 ( struct V_54 * V_73 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_349 ( V_14 -> V_108 . V_1090 ) ) {
F_427 () ;
V_17 = F_558 ( V_73 , V_14 -> V_108 . V_1090 , V_1091 ) ;
F_429 () ;
V_14 -> V_108 . V_328 . V_672 ( V_14 , F_271 ( 0 ) ) ;
}
return V_17 ;
}
static int F_559 ( struct V_54 * V_73 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_1092 * V_108 = & V_2 -> V_14 . V_108 ;
if ( F_349 ( V_108 -> V_1090 ) ) {
F_427 () ;
V_17 = F_560 ( V_73 , V_108 -> V_1090 , V_1091 ) ;
F_429 () ;
}
return V_17 ;
}
static void F_561 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_48 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
V_2 -> V_139 |= V_241 ;
if ( V_2 -> V_139 & V_378 ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_189 ; V_48 ++ )
F_222 ( 0 , V_2 -> V_158 [ V_48 ] ) ;
} else {
F_235 ( V_2 -> V_9 -> V_357 , V_55 ) ;
}
V_2 -> V_139 &= ~ V_241 ;
}
static struct V_1093 * F_562 ( struct V_54 * V_55 ,
struct V_1093 * V_124 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_48 ;
F_563 () ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_120 = F_21 ( V_2 -> V_67 [ V_48 ] ) ;
T_6 V_170 , V_144 ;
unsigned int V_1094 ;
if ( V_120 ) {
do {
V_1094 = F_564 ( & V_120 -> V_169 ) ;
V_144 = V_120 -> V_124 . V_144 ;
V_170 = V_120 -> V_124 . V_170 ;
} while ( F_565 ( & V_120 -> V_169 , V_1094 ) );
V_124 -> V_779 += V_144 ;
V_124 -> V_778 += V_170 ;
}
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_120 = F_21 ( V_2 -> V_58 [ V_48 ] ) ;
T_6 V_170 , V_144 ;
unsigned int V_1094 ;
if ( V_120 ) {
do {
V_1094 = F_564 ( & V_120 -> V_169 ) ;
V_144 = V_120 -> V_124 . V_144 ;
V_170 = V_120 -> V_124 . V_170 ;
} while ( F_565 ( & V_120 -> V_169 , V_1094 ) );
V_124 -> V_781 += V_144 ;
V_124 -> V_780 += V_170 ;
}
}
F_566 () ;
V_124 -> V_888 = V_55 -> V_124 . V_888 ;
V_124 -> V_889 = V_55 -> V_124 . V_889 ;
V_124 -> V_891 = V_55 -> V_124 . V_891 ;
V_124 -> V_892 = V_55 -> V_124 . V_892 ;
V_124 -> V_893 = V_55 -> V_124 . V_893 ;
return V_124 ;
}
static void F_567 ( struct V_1 * V_2 , T_4 V_134 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_3 , V_1095 ;
int V_48 ;
if ( V_14 -> V_108 . type == V_109 )
return;
V_3 = F_37 ( V_14 , V_1096 ) ;
V_1095 = V_3 ;
for ( V_48 = 0 ; V_48 < V_583 ; V_48 ++ ) {
T_4 V_1097 = V_3 >> ( V_48 * V_1098 ) ;
if ( V_1097 > V_134 )
V_3 &= ~ ( 0x7 << V_1098 ) ;
}
if ( V_3 != V_1095 )
F_71 ( V_14 , V_1096 , V_3 ) ;
return;
}
static void F_568 ( struct V_1 * V_2 )
{
struct V_54 * V_73 = V_2 -> V_55 ;
struct V_1099 * V_136 = & V_2 -> V_136 ;
struct V_1100 * V_1101 = V_2 -> V_568 ;
T_4 V_1102 ;
for ( V_1102 = 0 ; V_1102 < V_1103 ; V_1102 ++ ) {
T_4 V_134 = 0 ;
if ( V_2 -> V_564 & V_565 )
V_134 = F_569 ( V_136 , 0 , V_1102 ) ;
else if ( V_1101 )
V_134 = V_1101 -> V_569 [ V_1102 ] ;
F_570 ( V_73 , V_1102 , V_134 ) ;
}
}
int F_571 ( struct V_54 * V_73 , T_4 V_134 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
bool V_1104 ;
if ( V_134 > V_2 -> V_136 . V_706 . V_707 ||
( V_14 -> V_108 . type == V_109 &&
V_134 < V_583 ) )
return - V_537 ;
V_1104 = ( F_572 ( & V_2 -> V_609 , 32 ) > 1 ) ;
if ( V_134 && V_1104 && V_2 -> V_610 > V_1105 )
return - V_745 ;
if ( F_57 ( V_73 ) )
F_417 ( V_73 ) ;
F_434 ( V_2 ) ;
#ifdef F_354
if ( V_134 ) {
F_573 ( V_73 , V_134 ) ;
F_568 ( V_2 ) ;
V_2 -> V_139 |= V_140 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ) {
V_2 -> V_1106 = V_2 -> V_14 . V_125 . V_721 ;
V_2 -> V_14 . V_125 . V_721 = V_1107 ;
}
} else {
F_574 ( V_73 ) ;
if ( V_2 -> V_14 . V_108 . type == V_109 )
V_2 -> V_14 . V_125 . V_721 = V_2 -> V_1106 ;
V_2 -> V_139 &= ~ V_140 ;
V_2 -> V_720 . V_137 = false ;
V_2 -> V_136 . V_137 = false ;
}
F_567 ( V_2 , V_134 ) ;
#endif
F_428 ( V_2 ) ;
if ( F_57 ( V_73 ) )
return F_413 ( V_73 ) ;
return 0 ;
}
void F_575 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
F_427 () ;
F_571 ( V_55 , F_247 ( V_55 ) ) ;
F_429 () ;
}
void F_576 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
if ( F_57 ( V_55 ) )
F_365 ( V_2 ) ;
else
F_371 ( V_2 ) ;
}
static T_17 F_577 ( struct V_54 * V_55 ,
T_17 V_196 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
if ( ! ( V_196 & V_209 ) )
V_196 &= ~ V_1108 ;
if ( ! ( V_2 -> V_154 & V_691 ) )
V_196 &= ~ V_1108 ;
return V_196 ;
}
static int F_578 ( struct V_54 * V_55 ,
T_17 V_196 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
T_17 V_1109 = V_55 -> V_196 ^ V_196 ;
bool V_1110 = false ;
if ( ! ( V_196 & V_1108 ) ) {
if ( V_2 -> V_154 & V_501 )
V_1110 = true ;
V_2 -> V_154 &= ~ V_501 ;
} else if ( ( V_2 -> V_154 & V_691 ) &&
! ( V_2 -> V_154 & V_501 ) ) {
if ( V_2 -> V_369 == 1 ||
V_2 -> V_369 > V_1111 ) {
V_2 -> V_154 |= V_501 ;
V_1110 = true ;
} else if ( ( V_1109 ^ V_196 ) & V_1108 ) {
F_105 ( V_172 , L_137
L_138 ) ;
}
}
switch ( V_196 & V_1112 ) {
case V_1112 :
if ( ! ( V_2 -> V_139 & V_585 ) )
V_1110 = true ;
V_2 -> V_139 &= ~ V_354 ;
V_2 -> V_139 |= V_585 ;
break;
default:
if ( V_2 -> V_139 & V_585 )
V_1110 = true ;
V_2 -> V_139 &= ~ V_585 ;
if ( V_2 -> V_139 & V_398 )
break;
if ( F_247 ( V_55 ) > 1 )
break;
if ( V_2 -> V_403 [ V_404 ] . V_690 <= 1 )
break;
if ( ! V_2 -> V_388 )
break;
V_2 -> V_139 |= V_354 ;
break;
}
if ( V_196 & V_235 )
F_284 ( V_2 ) ;
else
F_283 ( V_2 ) ;
if ( V_1109 & V_261 )
V_1110 = true ;
V_55 -> V_196 = V_196 ;
if ( V_1110 )
F_576 ( V_55 ) ;
return 0 ;
}
static int F_579 ( struct V_1113 * V_1114 , struct V_1115 * V_1116 [] ,
struct V_54 * V_73 ,
const unsigned char * V_531 , T_2 V_237 ,
T_2 V_139 )
{
if ( F_580 ( V_531 ) || F_581 ( V_531 ) ) {
if ( V_1117 <= F_301 ( V_73 ) )
return - V_526 ;
}
return F_582 ( V_1114 , V_1116 , V_73 , V_531 , V_237 , V_139 ) ;
}
static int F_583 ( struct V_54 * V_73 ,
struct V_1118 * V_1119 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_1115 * V_1120 , * V_1121 ;
int V_1122 ;
if ( ! ( V_2 -> V_139 & V_398 ) )
return - V_1123 ;
V_1121 = F_584 ( V_1119 , sizeof( struct V_1124 ) , V_1125 ) ;
if ( ! V_1121 )
return - V_537 ;
F_585 (attr, br_spec, rem) {
T_18 V_1126 ;
T_1 V_3 = 0 ;
if ( F_586 ( V_1120 ) != V_1127 )
continue;
if ( F_587 ( V_1120 ) < sizeof( V_1126 ) )
return - V_537 ;
V_1126 = F_588 ( V_1120 ) ;
if ( V_1126 == V_1128 ) {
V_3 = 0 ;
V_2 -> V_154 &= ~ V_474 ;
} else if ( V_1126 == V_1129 ) {
V_3 = V_476 ;
V_2 -> V_154 |= V_474 ;
} else
return - V_537 ;
F_71 ( & V_2 -> V_14 , V_475 , V_3 ) ;
F_105 ( V_156 , L_139 ,
V_1126 == V_1128 ? L_140 : L_141 ) ;
}
return 0 ;
}
static int F_589 ( struct V_195 * V_89 , T_1 V_1130 , T_1 V_1131 ,
struct V_54 * V_73 ,
T_1 V_1132 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
T_2 V_1126 ;
if ( ! ( V_2 -> V_139 & V_398 ) )
return 0 ;
if ( V_2 -> V_154 & V_474 )
V_1126 = V_1129 ;
else
V_1126 = V_1128 ;
return F_590 ( V_89 , V_1130 , V_1131 , V_73 , V_1126 , 0 , 0 ) ;
}
static void * F_591 ( struct V_54 * V_9 , struct V_54 * V_603 )
{
struct V_599 * V_1044 = NULL ;
struct V_1 * V_2 = F_89 ( V_9 ) ;
int V_1133 = V_2 -> V_295 + V_2 -> V_610 ;
unsigned int V_690 ;
int V_459 , V_17 ;
if ( V_1133 >= V_1134 )
return F_592 ( - V_537 ) ;
#ifdef F_593
if ( V_603 -> V_93 != V_603 -> V_77 ) {
F_594 ( V_9 , L_142 ,
V_603 -> V_53 ) ;
return F_592 ( - V_537 ) ;
}
#endif
if ( V_603 -> V_77 > V_748 ||
V_603 -> V_77 == V_1135 ) {
F_594 ( V_9 ,
L_143 ,
V_9 -> V_53 ) ;
return F_592 ( - V_537 ) ;
}
if ( ( ( V_2 -> V_139 & V_140 ) &&
V_2 -> V_610 > V_1105 - 1 ) ||
( V_2 -> V_610 > V_1136 ) )
return F_592 ( - V_745 ) ;
V_1044 = F_595 ( 1 , sizeof( struct V_599 ) , V_739 ) ;
if ( ! V_1044 )
return F_592 ( - V_526 ) ;
V_459 = F_572 ( & V_2 -> V_609 , 32 ) ;
V_2 -> V_610 ++ ;
F_243 ( V_459 , & V_2 -> V_609 ) ;
V_690 = F_596 ( & V_2 -> V_609 , 32 ) ;
V_2 -> V_139 |= V_558 | V_398 ;
V_2 -> V_403 [ V_478 ] . V_690 = V_690 + 1 ;
V_2 -> V_403 [ V_404 ] . V_690 = V_603 -> V_77 ;
V_17 = F_571 ( V_9 , F_247 ( V_9 ) ) ;
if ( V_17 )
goto V_1137;
V_1044 -> V_459 = V_459 ;
V_1044 -> V_148 = V_2 ;
V_17 = F_344 ( V_603 , V_1044 ) ;
if ( V_17 )
goto V_1137;
F_597 ( V_603 ) ;
return V_1044 ;
V_1137:
F_594 ( V_9 ,
L_144 , V_603 -> V_53 ) ;
F_34 ( V_459 , & V_2 -> V_609 ) ;
V_2 -> V_610 -- ;
F_234 ( V_1044 ) ;
return F_592 ( V_17 ) ;
}
static void F_598 ( struct V_54 * V_9 , void * V_1138 )
{
struct V_599 * V_1044 = V_1138 ;
struct V_1 * V_2 = V_1044 -> V_148 ;
unsigned int V_690 ;
F_34 ( V_1044 -> V_459 , & V_2 -> V_609 ) ;
V_2 -> V_610 -- ;
V_690 = F_596 ( & V_2 -> V_609 , 32 ) ;
V_2 -> V_403 [ V_478 ] . V_690 = V_690 + 1 ;
F_342 ( V_1044 -> V_55 , V_1044 ) ;
F_571 ( V_9 , F_247 ( V_9 ) ) ;
F_345 ( V_9 , L_92 ,
V_1044 -> V_459 , V_2 -> V_610 ,
V_1044 -> V_602 ,
V_1044 -> V_602 + V_2 -> V_601 ,
V_2 -> V_609 ) ;
F_234 ( V_1044 ) ;
}
static inline int F_599 ( struct V_1 * V_2 )
{
struct V_5 * V_374 , * V_9 = V_2 -> V_9 ;
int V_1139 = 0 ;
if ( F_8 ( & V_2 -> V_14 ) )
V_1139 = 4 ;
F_600 (entry, &adapter->pdev->bus->devices, bus_list) {
if ( V_374 -> V_939 )
continue;
if ( ( V_374 -> V_683 != V_9 -> V_683 ) ||
( V_374 -> V_190 != V_9 -> V_190 ) )
return - 1 ;
V_1139 ++ ;
}
return V_1139 ;
}
int F_601 ( struct V_1 * V_2 , T_2 V_21 ,
T_2 V_1140 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1141 = V_2 -> V_1142 & V_1143 ;
int V_1144 = 0 ;
switch ( V_21 ) {
case V_1145 :
switch ( V_1140 ) {
case V_1146 :
case V_1147 :
if ( V_14 -> V_10 . V_1148 != 0 )
break;
case V_1149 :
case V_1150 :
case V_1151 :
case V_1152 :
case V_1153 :
V_1144 = 1 ;
break;
}
break;
case V_1154 :
switch ( V_1140 ) {
case V_1155 :
V_1144 = 1 ;
break;
}
break;
case V_1156 :
if ( V_1140 != V_1157 )
V_1144 = 1 ;
break;
case V_1158 :
V_1144 = 1 ;
break;
case V_1159 :
case V_1160 :
if ( ( V_1141 == V_1161 ) ||
( ( V_1141 == V_1162 ) &&
( V_14 -> V_10 . V_1148 == 0 ) ) ) {
V_1144 = 1 ;
}
break;
}
return V_1144 ;
}
static void F_602 ( struct V_1 * V_2 )
{
#ifdef F_603
struct V_1163 * V_1164 = F_604 ( V_2 -> V_9 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
const unsigned char * V_531 ;
V_531 = F_605 ( V_1164 ) ;
if ( V_531 ) {
F_297 ( V_14 -> V_108 . V_1165 , V_531 ) ;
return;
}
#endif
#ifdef F_606
F_297 ( V_14 -> V_108 . V_1165 , V_1166 -> V_1167 ) ;
#endif
}
static int F_607 ( struct V_5 * V_9 , const struct V_1168 * V_1169 )
{
struct V_54 * V_55 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_14 ;
const struct V_1170 * V_1171 = V_1172 [ V_1169 -> V_1173 ] ;
int V_48 , V_17 , V_1174 , V_24 ;
unsigned int V_405 = V_1175 ;
T_4 V_1176 [ V_1177 ] ;
bool V_1178 = false ;
#ifdef F_176
T_2 V_1179 ;
#endif
T_1 V_1180 ;
if ( V_9 -> V_939 ) {
F_608 ( 1 , V_1181 L_145 ,
F_481 ( V_9 ) , V_9 -> V_683 , V_9 -> V_190 ) ;
return - V_537 ;
}
V_17 = F_424 ( V_9 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_609 ( & V_9 -> V_73 , F_242 ( 64 ) ) ) {
V_1174 = 1 ;
} else {
V_17 = F_609 ( & V_9 -> V_73 , F_242 ( 32 ) ) ;
if ( V_17 ) {
F_401 ( & V_9 -> V_73 ,
L_146 ) ;
goto V_1182;
}
V_1174 = 0 ;
}
V_17 = F_610 ( V_9 , F_611 ( V_9 ,
V_1183 ) , V_1184 ) ;
if ( V_17 ) {
F_401 ( & V_9 -> V_73 ,
L_147 , V_17 ) ;
goto V_1185;
}
F_612 ( V_9 ) ;
F_425 ( V_9 ) ;
F_423 ( V_9 ) ;
if ( V_1171 -> V_108 == V_109 ) {
#ifdef F_354
V_405 = 4 * V_583 ;
#else
V_405 = V_1186 ;
#endif
}
V_55 = F_613 ( sizeof( struct V_1 ) , V_405 ) ;
if ( ! V_55 ) {
V_17 = - V_526 ;
goto V_1187;
}
F_614 ( V_55 , & V_9 -> V_73 ) ;
V_2 = F_89 ( V_55 ) ;
V_2 -> V_55 = V_55 ;
V_2 -> V_9 = V_9 ;
V_14 = & V_2 -> V_14 ;
V_14 -> V_38 = V_2 ;
V_2 -> V_1188 = F_615 ( V_1189 , V_1190 ) ;
V_14 -> V_39 = F_616 ( F_617 ( V_9 , 0 ) ,
F_618 ( V_9 , 0 ) ) ;
V_2 -> V_387 = V_14 -> V_39 ;
if ( ! V_14 -> V_39 ) {
V_17 = - V_735 ;
goto V_1191;
}
V_55 -> V_1192 = & V_1193 ;
F_619 ( V_55 ) ;
V_55 -> V_1194 = 5 * V_954 ;
F_620 ( V_55 -> V_53 , F_481 ( V_9 ) , sizeof( V_55 -> V_53 ) ) ;
memcpy ( & V_14 -> V_108 . V_328 , V_1171 -> V_1195 , sizeof( V_14 -> V_108 . V_328 ) ) ;
V_14 -> V_108 . type = V_1171 -> V_108 ;
memcpy ( & V_14 -> V_1196 . V_328 , V_1171 -> V_1197 , sizeof( V_14 -> V_1196 . V_328 ) ) ;
V_1180 = F_37 ( V_14 , V_1198 ) ;
if ( F_22 ( V_14 -> V_39 ) ) {
V_17 = - V_735 ;
goto V_1191;
}
if ( ! ( V_1180 & ( 1 << 8 ) ) )
V_14 -> V_1196 . V_328 . V_224 = & V_1199 ;
memcpy ( & V_14 -> V_331 . V_328 , V_1171 -> V_1200 , sizeof( V_14 -> V_331 . V_328 ) ) ;
V_14 -> V_331 . V_950 = V_1201 ;
V_14 -> V_331 . V_1082 . V_1079 = V_1202 ;
V_14 -> V_331 . V_1082 . V_1203 = 0 ;
V_14 -> V_331 . V_1082 . V_1204 = V_1205 | V_1206 ;
V_14 -> V_331 . V_1082 . V_73 = V_55 ;
V_14 -> V_331 . V_1082 . V_1207 = F_550 ;
V_14 -> V_331 . V_1082 . V_1208 = F_551 ;
V_1171 -> V_1209 ( V_14 ) ;
V_17 = F_386 ( V_2 ) ;
if ( V_17 )
goto V_1210;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_71 ( & V_2 -> V_14 , V_751 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_139 & V_334 ) {
T_1 V_657 = F_37 ( V_14 , V_658 ) ;
if ( V_657 & V_659 )
F_207 ( V_172 , L_73 ) ;
}
if ( V_1211 )
V_14 -> V_1211 = V_1211 ;
V_14 -> V_331 . V_1212 = true ;
V_17 = V_14 -> V_108 . V_328 . V_1213 ( V_14 ) ;
V_14 -> V_331 . V_1212 = false ;
if ( V_17 == V_666 &&
V_14 -> V_108 . type == V_109 ) {
V_17 = 0 ;
} else if ( V_17 == V_667 ) {
F_18 ( L_148 ) ;
F_18 ( L_149 ) ;
goto V_1210;
} else if ( V_17 ) {
F_18 ( L_150 , V_17 ) ;
goto V_1210;
}
#ifdef F_287
if ( V_2 -> V_14 . V_108 . type == V_109 )
goto V_1214;
F_621 ( V_14 ) ;
memcpy ( & V_14 -> V_1215 . V_328 , V_1171 -> V_1216 , sizeof( V_14 -> V_1215 . V_328 ) ) ;
F_622 ( V_9 , V_727 ) ;
F_623 ( V_2 ) ;
V_1214:
#endif
V_55 -> V_196 = V_1217 |
V_1218 |
V_1219 |
V_1220 |
V_235 |
V_1221 |
V_1222 |
V_1223 |
V_197 |
V_209 ;
V_55 -> V_1224 = V_55 -> V_196 | V_1225 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_55 -> V_196 |= V_1226 ;
V_55 -> V_1224 |= V_1226 |
V_1112 ;
break;
default:
break;
}
V_55 -> V_1224 |= V_261 ;
V_55 -> V_1227 |= V_1222 ;
V_55 -> V_1227 |= V_1223 ;
V_55 -> V_1227 |= V_1218 ;
V_55 -> V_1227 |= V_1219 ;
V_55 -> V_1227 |= V_1217 ;
V_55 -> V_1228 |= V_1229 ;
V_55 -> V_1228 |= V_1230 ;
#ifdef F_354
V_55 -> V_1231 = & V_1231 ;
#endif
#ifdef F_176
if ( V_2 -> V_139 & V_697 ) {
unsigned int V_1232 ;
if ( V_14 -> V_108 . V_328 . V_1233 ) {
V_14 -> V_108 . V_328 . V_1233 ( V_14 , & V_1179 ) ;
if ( V_1179 & V_1234 )
V_2 -> V_139 &= ~ V_697 ;
}
V_1232 = F_346 ( int , V_1235 , F_388 () ) ;
V_2 -> V_403 [ V_1050 ] . V_690 = V_1232 ;
V_55 -> V_196 |= V_1071 |
V_1072 ;
V_55 -> V_1227 |= V_1071 |
V_1072 |
V_563 ;
}
#endif
if ( V_1174 ) {
V_55 -> V_196 |= V_1236 ;
V_55 -> V_1227 |= V_1236 ;
}
if ( V_2 -> V_154 & V_691 )
V_55 -> V_1224 |= V_1108 ;
if ( V_2 -> V_154 & V_501 )
V_55 -> V_196 |= V_1108 ;
if ( V_14 -> V_1196 . V_328 . V_1237 ( V_14 , NULL ) < 0 ) {
F_18 ( L_151 ) ;
V_17 = - V_735 ;
goto V_1210;
}
F_602 ( V_2 ) ;
memcpy ( V_55 -> V_612 , V_14 -> V_108 . V_1165 , V_55 -> V_670 ) ;
if ( ! F_349 ( V_55 -> V_612 ) ) {
F_18 ( L_152 ) ;
V_17 = - V_735 ;
goto V_1210;
}
F_294 ( V_2 , V_14 -> V_108 . V_1165 ) ;
F_624 ( & V_2 -> V_660 , & F_491 ,
( unsigned long ) V_2 ) ;
if ( F_22 ( V_14 -> V_39 ) ) {
V_17 = - V_735 ;
goto V_1210;
}
F_625 ( & V_2 -> V_37 , F_494 ) ;
F_243 ( V_40 , & V_2 -> V_34 ) ;
F_34 ( V_36 , & V_2 -> V_34 ) ;
V_17 = F_428 ( V_2 ) ;
if ( V_17 )
goto V_1210;
V_2 -> V_755 = 0 ;
V_14 -> V_1196 . V_328 . V_224 ( V_14 , 0x2c , & V_2 -> V_1142 ) ;
V_14 -> V_1238 = F_601 ( V_2 , V_9 -> V_190 ,
V_9 -> V_689 ) ;
if ( V_14 -> V_1238 )
V_2 -> V_755 = V_1239 ;
F_626 ( & V_2 -> V_9 -> V_73 , V_2 -> V_755 ) ;
V_14 -> V_1196 . V_328 . V_224 ( V_14 , 0x2e , & V_2 -> V_1240 ) ;
V_14 -> V_1196 . V_328 . V_224 ( V_14 , 0x2d , & V_2 -> V_1241 ) ;
V_14 -> V_108 . V_328 . V_1242 ( V_14 ) ;
if ( F_8 ( V_14 ) )
F_5 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_24 = F_627 ( F_599 ( V_2 ) * 10 , 16 ) ;
break;
default:
V_24 = F_599 ( V_2 ) * 10 ;
break;
}
if ( V_24 > 0 )
F_9 ( V_2 , V_24 ) ;
V_17 = F_628 ( V_14 , V_1176 , sizeof( V_1176 ) ) ;
if ( V_17 )
F_620 ( V_1176 , L_7 , sizeof( V_1176 ) ) ;
if ( F_358 ( V_14 ) && V_14 -> V_331 . V_950 != V_1243 )
F_12 ( L_153 ,
V_14 -> V_108 . type , V_14 -> V_331 . type , V_14 -> V_331 . V_950 ,
V_1176 ) ;
else
F_12 ( L_154 ,
V_14 -> V_108 . type , V_14 -> V_331 . type , V_1176 ) ;
F_12 ( L_155 , V_55 -> V_612 ) ;
V_17 = V_14 -> V_108 . V_328 . V_1244 ( V_14 ) ;
if ( V_17 == V_669 ) {
F_11 ( L_95
L_156
L_157
L_158
L_99
L_100 ) ;
}
strcpy ( V_55 -> V_53 , L_159 ) ;
V_17 = F_629 ( V_55 ) ;
if ( V_17 )
goto V_1245;
F_630 ( V_9 , V_2 ) ;
if ( V_14 -> V_108 . V_328 . V_678 )
V_14 -> V_108 . V_328 . V_678 ( V_14 ) ;
F_379 ( V_55 ) ;
#ifdef F_225
if ( F_126 ( & V_9 -> V_73 ) == 0 ) {
V_2 -> V_139 |= V_187 ;
F_123 ( V_2 ) ;
}
#endif
if ( V_2 -> V_139 & V_398 ) {
F_105 ( V_172 , L_160 , V_2 -> V_295 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_295 ; V_48 ++ )
F_631 ( V_9 , ( V_48 | 0x10000000 ) ) ;
}
if ( V_14 -> V_108 . V_328 . V_1246 )
V_14 -> V_108 . V_328 . V_1246 ( V_14 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_557 ( V_55 ) ;
F_12 ( L_161 , V_1247 ) ;
#ifdef F_632
if ( F_633 ( V_2 ) )
F_103 ( V_172 , L_162 ) ;
#endif
F_634 ( V_2 ) ;
if ( F_635 ( V_14 ) && F_358 ( V_14 ) && V_14 -> V_108 . V_328 . V_640 )
V_14 -> V_108 . V_328 . V_640 ( V_14 ,
V_900 | V_923 ,
true ) ;
return 0 ;
V_1245:
F_70 ( V_2 ) ;
F_434 ( V_2 ) ;
V_1210:
F_636 ( V_2 ) ;
V_2 -> V_154 &= ~ V_634 ;
F_637 ( V_2 -> V_387 ) ;
F_234 ( V_2 -> V_528 ) ;
V_1191:
V_1178 = ! F_15 ( V_750 , & V_2 -> V_34 ) ;
F_638 ( V_55 ) ;
V_1187:
F_639 ( V_9 ,
F_611 ( V_9 , V_1183 ) ) ;
V_1185:
V_1182:
if ( ! V_2 || V_1178 )
F_435 ( V_9 ) ;
return V_17 ;
}
static void F_640 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_420 ( V_9 ) ;
struct V_54 * V_55 ;
bool V_1178 ;
if ( ! V_2 )
return;
V_55 = V_2 -> V_55 ;
F_641 ( V_2 ) ;
F_243 ( V_35 , & V_2 -> V_34 ) ;
F_642 ( & V_2 -> V_37 ) ;
#ifdef F_225
if ( V_2 -> V_139 & V_187 ) {
V_2 -> V_139 &= ~ V_187 ;
F_127 ( & V_9 -> V_73 ) ;
F_71 ( & V_2 -> V_14 , V_188 , 1 ) ;
}
#endif
#ifdef F_632
F_643 ( V_2 ) ;
#endif
F_559 ( V_55 ) ;
if ( V_55 -> V_951 == V_952 )
F_489 ( V_55 ) ;
#ifdef F_287
if ( V_726 )
F_636 ( V_2 ) ;
#endif
F_434 ( V_2 ) ;
F_70 ( V_2 ) ;
#ifdef F_644
F_234 ( V_2 -> V_138 ) ;
F_234 ( V_2 -> V_568 ) ;
#endif
F_637 ( V_2 -> V_387 ) ;
F_639 ( V_9 , F_611 ( V_9 ,
V_1183 ) ) ;
F_12 ( L_163 ) ;
F_234 ( V_2 -> V_528 ) ;
V_1178 = ! F_15 ( V_750 , & V_2 -> V_34 ) ;
F_638 ( V_55 ) ;
F_645 ( V_9 ) ;
if ( V_1178 )
F_435 ( V_9 ) ;
}
static T_19 F_646 ( struct V_5 * V_9 ,
T_20 V_34 )
{
struct V_1 * V_2 = F_420 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
#ifdef F_287
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_1248 , * V_930 ;
T_1 V_1249 , V_1250 , V_1251 , V_1252 ;
int V_1253 , V_934 ;
T_2 V_1254 , V_1255 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ||
V_2 -> V_295 == 0 )
goto V_1256;
V_1248 = V_9 -> V_10 -> V_12 ;
while ( V_1248 && ( F_647 ( V_1248 ) != V_1257 ) )
V_1248 = V_1248 -> V_10 -> V_12 ;
if ( ! V_1248 )
goto V_1256;
V_934 = F_484 ( V_1248 , V_1258 ) ;
if ( ! V_934 )
goto V_1256;
V_1249 = F_27 ( V_14 , V_934 + V_1259 ) ;
V_1250 = F_27 ( V_14 , V_934 + V_1259 + 4 ) ;
V_1251 = F_27 ( V_14 , V_934 + V_1259 + 8 ) ;
V_1252 = F_27 ( V_14 , V_934 + V_1259 + 12 ) ;
if ( F_22 ( V_14 -> V_39 ) )
goto V_1256;
V_1254 = V_1250 >> 16 ;
if ( ! ( V_1254 & 0x0080 ) )
goto V_1256;
V_1255 = V_1254 & 0x01 ;
if ( ( V_1255 & 1 ) == ( V_9 -> V_1260 & 1 ) ) {
unsigned int V_21 ;
V_1253 = ( V_1254 & 0x7F ) >> 1 ;
F_18 ( L_164 , V_1253 ) ;
F_18 ( L_165
L_166 ,
V_1249 , V_1250 , V_1251 , V_1252 ) ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_21 = V_1261 ;
break;
case V_112 :
V_21 = V_1262 ;
break;
case V_113 :
V_21 = V_1263 ;
break;
case V_114 :
V_21 = V_1264 ;
break;
default:
V_21 = 0 ;
break;
}
V_930 = F_485 ( V_1265 , V_21 , NULL ) ;
while ( V_930 ) {
if ( V_930 -> V_1260 == ( V_1254 & 0xFF ) )
break;
V_930 = F_485 ( V_1265 ,
V_21 , V_930 ) ;
}
if ( V_930 ) {
F_479 ( V_2 , V_930 ) ;
F_648 ( V_930 ) ;
}
F_649 ( V_9 ) ;
}
V_2 -> V_1266 ++ ;
return V_1267 ;
V_1256:
#endif
if ( ! F_14 ( V_40 , & V_2 -> V_34 ) )
return V_1268 ;
F_427 () ;
F_433 ( V_55 ) ;
if ( V_34 == V_1269 ) {
F_429 () ;
return V_1268 ;
}
if ( F_57 ( V_55 ) )
F_368 ( V_2 ) ;
if ( ! F_15 ( V_750 , & V_2 -> V_34 ) )
F_435 ( V_9 ) ;
F_429 () ;
return V_1270 ;
}
static T_19 F_650 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_420 ( V_9 ) ;
T_19 V_1271 ;
int V_17 ;
if ( F_424 ( V_9 ) ) {
F_103 ( V_172 , L_167 ) ;
V_1271 = V_1268 ;
} else {
F_33 () ;
F_34 ( V_750 , & V_2 -> V_34 ) ;
V_2 -> V_14 . V_39 = V_2 -> V_387 ;
F_425 ( V_9 ) ;
F_422 ( V_9 ) ;
F_423 ( V_9 ) ;
F_426 ( V_9 , false ) ;
F_371 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_751 , ~ 0 ) ;
V_1271 = V_1267 ;
}
V_17 = F_649 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_168
L_169 , V_17 ) ;
}
return V_1271 ;
}
static void F_651 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_420 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
#ifdef F_287
if ( V_2 -> V_1266 ) {
F_105 ( V_156 , L_170 ) ;
V_2 -> V_1266 -- ;
return;
}
#endif
if ( F_57 ( V_55 ) )
F_370 ( V_2 ) ;
F_430 ( V_55 ) ;
}
static int T_21 F_652 ( void )
{
int V_636 ;
F_51 ( L_171 , V_1272 , V_1273 ) ;
F_51 ( L_161 , V_1274 ) ;
F_653 () ;
V_636 = F_654 ( & V_1275 ) ;
if ( V_636 ) {
F_655 () ;
return V_636 ;
}
#ifdef F_225
F_656 ( & V_1276 ) ;
#endif
return 0 ;
}
static void T_22 F_657 ( void )
{
#ifdef F_225
F_658 ( & V_1276 ) ;
#endif
F_659 ( & V_1275 ) ;
F_655 () ;
F_660 () ;
}
static int F_661 ( struct V_1277 * V_1278 , unsigned long V_191 ,
void * V_1075 )
{
int V_1279 ;
V_1279 = F_662 ( & V_1275 . V_1280 , NULL , & V_191 ,
F_124 ) ;
return V_1279 ? V_1281 : V_1282 ;
}
