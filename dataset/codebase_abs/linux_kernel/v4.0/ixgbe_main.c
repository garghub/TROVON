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
T_8 V_202 = V_69 -> V_94 . V_198 . V_203 . V_204 . V_202 ;
T_8 V_209 = V_69 -> V_94 . V_198 . V_203 . V_204 . V_209 ;
bool V_210 = false ;
F_133 ( V_89 ) ;
if ( ! ( V_120 -> V_55 -> V_196 & V_211 ) )
return;
if ( ( V_202 & F_131 ( V_212 ) ) &&
( V_209 & F_131 ( V_213 >> 16 ) ) ) {
V_210 = true ;
V_89 -> V_214 = 1 ;
V_89 -> V_215 = V_216 ;
}
if ( F_134 ( V_69 , V_217 ) &&
F_134 ( V_69 , V_218 ) ) {
V_120 -> V_219 . V_220 ++ ;
return;
}
if ( ! F_134 ( V_69 , V_221 ) )
return;
if ( F_134 ( V_69 , V_222 ) ) {
if ( ( V_202 & F_131 ( V_223 ) ) &&
F_14 ( V_224 , & V_120 -> V_34 ) )
return;
V_120 -> V_219 . V_220 ++ ;
return;
}
V_89 -> V_215 = V_225 ;
if ( V_210 ) {
if ( ! F_134 ( V_69 , V_226 ) )
return;
if ( F_134 ( V_69 , V_227 ) ) {
V_120 -> V_219 . V_220 ++ ;
return;
}
V_89 -> V_228 = 1 ;
}
}
static bool F_135 ( struct V_57 * V_67 ,
struct V_70 * V_229 )
{
struct V_98 * V_98 = V_229 -> V_98 ;
T_9 V_81 ;
if ( F_99 ( V_98 ) )
return true ;
V_98 = F_136 ( F_137 ( V_67 ) ) ;
if ( F_24 ( ! V_98 ) ) {
V_67 -> V_219 . V_230 ++ ;
return false ;
}
V_81 = F_138 ( V_67 -> V_73 , V_98 , 0 ,
F_139 ( V_67 ) , V_231 ) ;
if ( F_140 ( V_67 -> V_73 , V_81 ) ) {
F_141 ( V_98 , F_137 ( V_67 ) ) ;
V_67 -> V_219 . V_230 ++ ;
return false ;
}
V_229 -> V_81 = V_81 ;
V_229 -> V_98 = V_98 ;
V_229 -> V_99 = 0 ;
return true ;
}
void F_142 ( struct V_57 * V_67 , T_2 V_232 )
{
union V_68 * V_69 ;
struct V_70 * V_229 ;
T_2 V_48 = V_67 -> V_80 ;
if ( ! V_232 )
return;
V_69 = F_66 ( V_67 , V_48 ) ;
V_229 = & V_67 -> V_71 [ V_48 ] ;
V_48 -= V_67 -> V_88 ;
do {
if ( ! F_135 ( V_67 , V_229 ) )
break;
V_69 -> V_233 . V_234 = F_143 ( V_229 -> V_81 + V_229 -> V_99 ) ;
V_69 ++ ;
V_229 ++ ;
V_48 ++ ;
if ( F_24 ( ! V_48 ) ) {
V_69 = F_66 ( V_67 , 0 ) ;
V_229 = V_67 -> V_71 ;
V_48 -= V_67 -> V_88 ;
}
V_69 -> V_94 . V_95 . V_96 = 0 ;
V_232 -- ;
} while ( V_232 );
V_48 += V_67 -> V_88 ;
if ( V_67 -> V_80 != V_48 ) {
V_67 -> V_80 = V_48 ;
V_67 -> V_235 = V_48 ;
F_144 () ;
F_145 ( V_48 , V_67 -> V_146 ) ;
}
}
static void F_146 ( struct V_57 * V_120 ,
struct V_195 * V_89 )
{
T_2 V_236 = F_147 ( V_89 ) ;
F_148 ( V_89 ) -> V_237 = F_149 ( ( V_89 -> V_82 - V_236 ) ,
F_150 ( V_89 ) -> V_238 ) ;
F_148 ( V_89 ) -> V_239 = V_240 ;
}
static void F_151 ( struct V_57 * V_67 ,
struct V_195 * V_89 )
{
if ( ! F_150 ( V_89 ) -> V_238 )
return;
V_67 -> V_219 . V_241 += F_150 ( V_89 ) -> V_238 ;
V_67 -> V_219 . V_242 ++ ;
F_146 ( V_67 , V_89 ) ;
F_150 ( V_89 ) -> V_238 = 0 ;
}
static void F_152 ( struct V_57 * V_67 ,
union V_68 * V_69 ,
struct V_195 * V_89 )
{
struct V_54 * V_73 = V_67 -> V_55 ;
F_151 ( V_67 , V_89 ) ;
F_128 ( V_67 , V_69 , V_89 ) ;
F_132 ( V_67 , V_69 , V_89 ) ;
if ( F_24 ( F_134 ( V_69 , V_243 ) ) )
F_153 ( V_67 -> V_158 -> V_2 , V_89 ) ;
if ( ( V_73 -> V_196 & V_244 ) &&
F_134 ( V_69 , V_245 ) ) {
T_2 V_246 = F_154 ( V_69 -> V_94 . V_95 . V_247 ) ;
F_155 ( V_89 , F_156 ( V_248 ) , V_246 ) ;
}
F_157 ( V_89 , V_67 -> V_86 ) ;
V_89 -> V_249 = F_158 ( V_89 , V_73 ) ;
}
static void F_159 ( struct V_157 * V_158 ,
struct V_195 * V_89 )
{
struct V_1 * V_2 = V_158 -> V_2 ;
if ( F_160 ( V_158 ) )
F_161 ( V_89 ) ;
else if ( ! ( V_2 -> V_139 & V_250 ) )
F_162 ( & V_158 -> V_251 , V_89 ) ;
else
F_163 ( V_89 ) ;
}
static bool F_164 ( struct V_57 * V_67 ,
union V_68 * V_69 ,
struct V_195 * V_89 )
{
T_1 V_252 = V_67 -> V_79 + 1 ;
V_252 = ( V_252 < V_67 -> V_88 ) ? V_252 : 0 ;
V_67 -> V_79 = V_252 ;
F_98 ( F_66 ( V_67 , V_252 ) ) ;
if ( F_165 ( V_67 ) ) {
T_10 V_253 = V_69 -> V_94 . V_198 . V_203 . V_92 &
F_96 ( V_254 ) ;
if ( F_24 ( V_253 ) ) {
T_1 V_255 = F_67 ( V_253 ) ;
V_255 >>= V_256 ;
F_150 ( V_89 ) -> V_238 += V_255 - 1 ;
V_252 = F_67 ( V_69 -> V_94 . V_95 . V_96 ) ;
V_252 &= V_257 ;
V_252 >>= V_258 ;
}
}
if ( F_99 ( F_134 ( V_69 , V_259 ) ) )
return false ;
V_67 -> V_71 [ V_252 ] . V_89 = V_89 ;
V_67 -> V_219 . V_260 ++ ;
return true ;
}
static void F_166 ( struct V_57 * V_67 ,
struct V_195 * V_89 )
{
struct V_261 * V_262 = & F_148 ( V_89 ) -> V_263 [ 0 ] ;
unsigned char * V_264 ;
unsigned int V_265 ;
V_264 = F_167 ( V_262 ) ;
V_265 = F_168 ( V_264 , V_266 ) ;
F_169 ( V_89 , V_264 , F_170 ( V_265 , sizeof( long ) ) ) ;
F_171 ( V_262 , V_265 ) ;
V_262 -> V_99 += V_265 ;
V_89 -> V_267 -= V_265 ;
V_89 -> V_146 += V_265 ;
}
static void F_172 ( struct V_57 * V_67 ,
struct V_195 * V_89 )
{
if ( F_24 ( F_150 ( V_89 ) -> V_268 ) ) {
F_80 ( V_67 -> V_73 , F_150 ( V_89 ) -> V_81 ,
F_139 ( V_67 ) , V_231 ) ;
F_150 ( V_89 ) -> V_268 = false ;
} else {
struct V_261 * V_262 = & F_148 ( V_89 ) -> V_263 [ 0 ] ;
F_173 ( V_67 -> V_73 ,
F_150 ( V_89 ) -> V_81 ,
V_262 -> V_99 ,
F_69 ( V_67 ) ,
V_231 ) ;
}
F_150 ( V_89 ) -> V_81 = 0 ;
}
static bool F_174 ( struct V_57 * V_67 ,
union V_68 * V_69 ,
struct V_195 * V_89 )
{
struct V_54 * V_55 = V_67 -> V_55 ;
if ( F_24 ( F_134 ( V_69 ,
V_269 ) &&
! ( V_55 -> V_196 & V_270 ) ) ) {
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
struct V_70 * V_271 )
{
struct V_70 * V_272 ;
T_2 V_273 = V_67 -> V_235 ;
V_272 = & V_67 -> V_71 [ V_273 ] ;
V_273 ++ ;
V_67 -> V_235 = ( V_273 < V_67 -> V_88 ) ? V_273 : 0 ;
* V_272 = * V_271 ;
F_179 ( V_67 -> V_73 , V_272 -> V_81 ,
V_272 -> V_99 ,
F_69 ( V_67 ) ,
V_231 ) ;
}
static inline bool F_180 ( struct V_98 * V_98 )
{
return ( F_181 ( V_98 ) != F_182 () ) || V_98 -> V_274 ;
}
static bool F_183 ( struct V_57 * V_67 ,
struct V_70 * V_275 ,
union V_68 * V_69 ,
struct V_195 * V_89 )
{
struct V_98 * V_98 = V_275 -> V_98 ;
unsigned int V_276 = F_154 ( V_69 -> V_94 . V_95 . V_277 ) ;
#if ( V_278 < 8192 )
unsigned int V_279 = F_69 ( V_67 ) ;
#else
unsigned int V_279 = F_170 ( V_276 , V_280 ) ;
unsigned int V_281 = F_139 ( V_67 ) -
F_69 ( V_67 ) ;
#endif
if ( ( V_276 <= V_266 ) && ! F_175 ( V_89 ) ) {
unsigned char * V_264 = F_68 ( V_98 ) + V_275 -> V_99 ;
memcpy ( F_184 ( V_89 , V_276 ) , V_264 , F_170 ( V_276 , sizeof( long ) ) ) ;
if ( F_99 ( ! F_180 ( V_98 ) ) )
return true ;
F_141 ( V_98 , F_137 ( V_67 ) ) ;
return false ;
}
F_185 ( V_89 , F_148 ( V_89 ) -> V_282 , V_98 ,
V_275 -> V_99 , V_276 , V_279 ) ;
if ( F_24 ( F_180 ( V_98 ) ) )
return false ;
#if ( V_278 < 8192 )
if ( F_24 ( F_186 ( V_98 ) != 1 ) )
return false ;
V_275 -> V_99 ^= V_279 ;
#else
V_275 -> V_99 += V_279 ;
if ( V_275 -> V_99 > V_281 )
return false ;
#endif
F_187 ( & V_98 -> V_283 ) ;
return true ;
}
static struct V_195 * F_188 ( struct V_57 * V_67 ,
union V_68 * V_69 )
{
struct V_70 * V_275 ;
struct V_195 * V_89 ;
struct V_98 * V_98 ;
V_275 = & V_67 -> V_71 [ V_67 -> V_79 ] ;
V_98 = V_275 -> V_98 ;
F_189 ( V_98 ) ;
V_89 = V_275 -> V_89 ;
if ( F_99 ( ! V_89 ) ) {
void * V_284 = F_68 ( V_98 ) +
V_275 -> V_99 ;
F_98 ( V_284 ) ;
#if V_280 < 128
F_98 ( V_284 + V_280 ) ;
#endif
V_89 = F_190 ( & V_67 -> V_158 -> V_251 ,
V_266 ) ;
if ( F_24 ( ! V_89 ) ) {
V_67 -> V_219 . V_285 ++ ;
return NULL ;
}
F_189 ( V_89 -> V_92 ) ;
if ( F_99 ( F_134 ( V_69 , V_259 ) ) )
goto V_286;
F_150 ( V_89 ) -> V_81 = V_275 -> V_81 ;
} else {
if ( F_134 ( V_69 , V_259 ) )
F_172 ( V_67 , V_89 ) ;
V_286:
F_173 ( V_67 -> V_73 ,
V_275 -> V_81 ,
V_275 -> V_99 ,
F_69 ( V_67 ) ,
V_231 ) ;
V_275 -> V_89 = NULL ;
}
if ( F_183 ( V_67 , V_275 , V_69 , V_89 ) ) {
F_178 ( V_67 , V_275 ) ;
} else if ( F_150 ( V_89 ) -> V_81 == V_275 -> V_81 ) {
F_150 ( V_89 ) -> V_268 = true ;
} else {
F_80 ( V_67 -> V_73 , V_275 -> V_81 ,
F_139 ( V_67 ) ,
V_231 ) ;
}
V_275 -> V_98 = NULL ;
return V_89 ;
}
static int F_191 ( struct V_157 * V_158 ,
struct V_57 * V_67 ,
const int V_161 )
{
unsigned int V_287 = 0 , V_288 = 0 ;
#ifdef F_176
struct V_1 * V_2 = V_158 -> V_2 ;
int V_289 ;
unsigned int V_290 = 0 ;
#endif
T_2 V_232 = F_110 ( V_67 ) ;
while ( F_99 ( V_288 < V_161 ) ) {
union V_68 * V_69 ;
struct V_195 * V_89 ;
if ( V_232 >= V_291 ) {
F_142 ( V_67 , V_232 ) ;
V_232 = 0 ;
}
V_69 = F_66 ( V_67 , V_67 -> V_79 ) ;
if ( ! V_69 -> V_94 . V_95 . V_96 )
break;
F_192 () ;
V_89 = F_188 ( V_67 , V_69 ) ;
if ( ! V_89 )
break;
V_232 ++ ;
if ( F_164 ( V_67 , V_69 , V_89 ) )
continue;
if ( F_174 ( V_67 , V_69 , V_89 ) )
continue;
V_287 += V_89 -> V_82 ;
F_152 ( V_67 , V_69 , V_89 ) ;
#ifdef F_176
if ( F_130 ( V_67 , V_69 ) ) {
V_289 = F_193 ( V_2 , V_69 , V_89 ) ;
if ( V_289 > 0 ) {
if ( ! V_290 ) {
V_290 = V_67 -> V_55 -> V_292 -
sizeof( struct V_293 ) -
sizeof( struct V_294 ) -
sizeof( struct V_295 ) ;
if ( V_290 > 512 )
V_290 &= ~ 511 ;
}
V_287 += V_289 ;
V_288 += F_149 ( V_289 ,
V_290 ) ;
}
if ( ! V_289 ) {
F_78 ( V_89 ) ;
continue;
}
}
#endif
F_194 ( V_89 , & V_158 -> V_251 ) ;
F_159 ( V_158 , V_89 ) ;
V_288 ++ ;
}
F_100 ( & V_67 -> V_169 ) ;
V_67 -> V_124 . V_144 += V_288 ;
V_67 -> V_124 . V_170 += V_287 ;
F_101 ( & V_67 -> V_169 ) ;
V_158 -> V_296 . V_160 += V_288 ;
V_158 -> V_296 . V_159 += V_287 ;
return V_288 ;
}
static int F_195 ( struct V_297 * V_251 )
{
struct V_157 * V_158 =
F_196 ( V_251 , struct V_157 , V_251 ) ;
struct V_1 * V_2 = V_158 -> V_2 ;
struct V_57 * V_120 ;
int V_298 = 0 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return V_299 ;
if ( ! F_197 ( V_158 ) )
return V_300 ;
F_121 (ring, q_vector->rx) {
V_298 = F_191 ( V_158 , V_120 , 4 ) ;
#ifdef F_198
if ( V_298 )
V_120 -> V_124 . V_301 += V_298 ;
else
V_120 -> V_124 . V_302 ++ ;
#endif
if ( V_298 )
break;
}
F_199 ( V_158 ) ;
return V_298 ;
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_157 * V_158 ;
int V_303 ;
T_1 V_117 ;
if ( V_2 -> V_304 > 32 ) {
T_1 V_305 = ( 1 << ( V_2 -> V_304 - 32 ) ) - 1 ;
F_71 ( & V_2 -> V_14 , V_306 , V_305 ) ;
}
for ( V_303 = 0 ; V_303 < V_2 -> V_189 ; V_303 ++ ) {
struct V_57 * V_120 ;
V_158 = V_2 -> V_158 [ V_303 ] ;
F_121 (ring, q_vector->rx)
F_73 ( V_2 , 0 , V_120 -> V_149 , V_303 ) ;
F_121 (ring, q_vector->tx)
F_73 ( V_2 , 1 , V_120 -> V_149 , V_303 ) ;
F_201 ( V_158 ) ;
}
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
F_73 ( V_2 , - 1 , V_307 ,
V_303 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_73 ( V_2 , - 1 , 1 , V_303 ) ;
break;
default:
break;
}
F_71 ( & V_2 -> V_14 , F_202 ( V_303 ) , 1950 ) ;
V_117 = V_308 ;
V_117 &= ~ ( V_309 |
V_310 |
V_311 ) ;
F_71 ( & V_2 -> V_14 , V_312 , V_117 ) ;
}
static void F_203 ( struct V_157 * V_158 ,
struct V_313 * V_314 )
{
int V_170 = V_314 -> V_159 ;
int V_144 = V_314 -> V_160 ;
T_1 V_315 ;
T_6 V_316 ;
T_4 V_317 = V_314 -> V_318 ;
if ( V_144 == 0 )
return;
V_315 = V_158 -> V_318 >> 2 ;
if ( V_315 == 0 )
return;
V_316 = V_170 / V_315 ;
switch ( V_317 ) {
case V_319 :
if ( V_316 > 10 )
V_317 = V_320 ;
break;
case V_320 :
if ( V_316 > 20 )
V_317 = V_321 ;
else if ( V_316 <= 10 )
V_317 = V_319 ;
break;
case V_321 :
if ( V_316 <= 20 )
V_317 = V_320 ;
break;
}
V_314 -> V_159 = 0 ;
V_314 -> V_160 = 0 ;
V_314 -> V_318 = V_317 ;
}
void F_201 ( struct V_157 * V_158 )
{
struct V_1 * V_2 = V_158 -> V_2 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_303 = V_158 -> V_303 ;
T_1 V_322 = V_158 -> V_318 & V_323 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
V_322 |= ( V_322 << 16 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_322 |= V_324 ;
break;
default:
break;
}
F_71 ( V_14 , F_202 ( V_303 ) , V_322 ) ;
}
static void F_204 ( struct V_157 * V_158 )
{
T_1 V_325 = V_158 -> V_318 ;
T_4 V_326 ;
F_203 ( V_158 , & V_158 -> V_162 ) ;
F_203 ( V_158 , & V_158 -> V_296 ) ;
V_326 = F_205 ( V_158 -> V_296 . V_318 , V_158 -> V_162 . V_318 ) ;
switch ( V_326 ) {
case V_319 :
V_325 = V_327 ;
break;
case V_320 :
V_325 = V_328 ;
break;
case V_321 :
V_325 = V_329 ;
break;
default:
break;
}
if ( V_325 != V_158 -> V_318 ) {
V_325 = ( 10 * V_325 * V_158 -> V_318 ) /
( ( 9 * V_325 ) + V_158 -> V_318 ) ;
V_158 -> V_318 = V_325 ;
F_201 ( V_158 ) ;
}
}
static void F_206 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_330 = V_2 -> V_331 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
if ( ! ( V_2 -> V_154 & V_332 ) &&
! ( V_2 -> V_154 & V_333 ) )
return;
V_2 -> V_154 &= ~ V_333 ;
switch ( V_14 -> V_21 ) {
case V_334 :
if ( ! ( V_330 & V_335 ) &&
! ( V_330 & V_336 ) )
return;
if ( ! ( V_330 & V_336 ) && V_14 -> V_108 . V_337 . V_338 ) {
T_1 V_20 ;
bool V_339 = false ;
V_14 -> V_108 . V_337 . V_338 ( V_14 , & V_20 , & V_339 , false ) ;
if ( V_339 )
return;
}
if ( V_14 -> V_340 . V_337 . V_341 ( V_14 ) != V_342 )
return;
break;
default:
if ( ! ( V_330 & V_335 ) )
return;
break;
}
F_207 ( V_156 ,
L_70
L_71
L_72 ) ;
V_2 -> V_331 = 0 ;
}
static void F_208 ( struct V_1 * V_2 , T_1 V_330 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ( V_2 -> V_139 & V_343 ) &&
( V_330 & V_344 ) ) {
F_207 ( V_172 , L_73 ) ;
F_71 ( V_14 , V_345 , V_344 ) ;
}
}
static void F_209 ( struct V_1 * V_2 , T_1 V_330 )
{
if ( ! ( V_2 -> V_154 & V_332 ) )
return;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
if ( ( ( V_330 & V_335 ) || ( V_330 & V_336 ) ) &&
( ! F_14 ( V_33 , & V_2 -> V_34 ) ) ) {
V_2 -> V_331 = V_330 ;
V_2 -> V_154 |= V_333 ;
F_13 ( V_2 ) ;
return;
}
return;
case V_112 :
if ( ! ( V_330 & V_346 ) )
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
static void F_210 ( struct V_1 * V_2 , T_1 V_330 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_330 & V_347 ) {
F_71 ( V_14 , V_345 , V_347 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_154 |= V_348 ;
F_13 ( V_2 ) ;
}
}
if ( V_330 & V_344 ) {
F_71 ( V_14 , V_345 , V_344 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_139 |= V_349 ;
F_13 ( V_2 ) ;
}
}
}
static void F_211 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_350 ++ ;
V_2 -> V_139 |= V_351 ;
V_2 -> V_352 = V_171 ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
F_71 ( V_14 , V_353 , V_354 ) ;
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
F_71 ( V_14 , V_355 , V_117 ) ;
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
F_71 ( V_14 , V_353 , V_117 ) ;
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
static inline void F_217 ( struct V_1 * V_2 , bool V_356 ,
bool V_357 )
{
T_1 V_117 = ( V_308 & ~ V_118 ) ;
if ( V_2 -> V_139 & V_351 )
V_117 &= ~ V_311 ;
if ( V_2 -> V_154 & V_332 )
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_117 |= V_358 ;
break;
case V_112 :
case V_113 :
case V_114 :
V_117 |= V_359 ;
break;
default:
break;
}
if ( V_2 -> V_139 & V_343 )
V_117 |= V_360 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_117 |= V_360 ;
V_117 |= V_361 ;
case V_112 :
case V_113 :
case V_114 :
V_117 |= V_362 ;
V_117 |= V_310 ;
break;
default:
break;
}
if ( ( V_2 -> V_139 & V_363 ) &&
! ( V_2 -> V_154 & V_364 ) )
V_117 |= V_365 ;
F_71 ( & V_2 -> V_14 , V_355 , V_117 ) ;
if ( V_356 )
F_213 ( V_2 , ~ 0 ) ;
if ( V_357 )
F_212 ( & V_2 -> V_14 ) ;
}
static T_11 F_218 ( int V_366 , void * V_92 )
{
struct V_1 * V_2 = V_92 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_330 ;
V_330 = F_37 ( V_14 , V_119 ) ;
V_330 &= 0xFFFF0000 ;
F_71 ( V_14 , V_345 , V_330 ) ;
if ( V_330 & V_336 )
F_211 ( V_2 ) ;
if ( V_330 & V_367 )
F_219 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
if ( V_330 & V_368 ) {
F_105 ( V_369 , L_74 ) ;
V_2 -> V_154 |= V_155 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_345 , V_368 ) ;
}
if ( V_330 & V_370 ) {
int V_371 = 0 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_120 = V_2 -> V_58 [ V_48 ] ;
if ( F_220 ( V_372 ,
& V_120 -> V_34 ) )
V_371 ++ ;
}
if ( V_371 ) {
F_71 ( V_14 , V_353 , V_373 ) ;
V_2 -> V_154 |= V_364 ;
F_13 ( V_2 ) ;
}
}
F_210 ( V_2 , V_330 ) ;
F_209 ( V_2 , V_330 ) ;
break;
default:
break;
}
F_208 ( V_2 , V_330 ) ;
if ( F_24 ( V_330 & V_374 ) )
F_221 ( V_2 , V_330 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_217 ( V_2 , false , false ) ;
return V_375 ;
}
static T_11 F_222 ( int V_366 , void * V_92 )
{
struct V_157 * V_158 = V_92 ;
if ( V_158 -> V_296 . V_120 || V_158 -> V_162 . V_120 )
F_223 ( & V_158 -> V_251 ) ;
return V_375 ;
}
int F_224 ( struct V_297 * V_251 , int V_161 )
{
struct V_157 * V_158 =
F_196 ( V_251 , struct V_157 , V_251 ) ;
struct V_1 * V_2 = V_158 -> V_2 ;
struct V_57 * V_120 ;
int V_376 ;
bool V_377 = true ;
#ifdef F_225
if ( V_2 -> V_139 & V_187 )
F_119 ( V_158 ) ;
#endif
F_121 (ring, q_vector->tx)
V_377 &= ! ! F_94 ( V_158 , V_120 ) ;
if ( ! F_226 ( V_158 ) )
return V_161 ;
if ( V_158 -> V_296 . V_88 > 1 )
V_376 = F_205 ( V_161 / V_158 -> V_296 . V_88 , 1 ) ;
else
V_376 = V_161 ;
F_121 (ring, q_vector->rx)
V_377 &= ( F_191 ( V_158 , V_120 ,
V_376 ) < V_376 ) ;
F_227 ( V_158 ) ;
if ( ! V_377 )
return V_161 ;
F_228 ( V_251 ) ;
if ( V_2 -> V_378 & 1 )
F_204 ( V_158 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_213 ( V_2 , ( ( T_6 ) 1 << V_158 -> V_303 ) ) ;
return 0 ;
}
static int F_229 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
int V_379 , V_17 ;
int V_380 = 0 , V_381 = 0 ;
for ( V_379 = 0 ; V_379 < V_2 -> V_189 ; V_379 ++ ) {
struct V_157 * V_158 = V_2 -> V_158 [ V_379 ] ;
struct V_382 * V_383 = & V_2 -> V_384 [ V_379 ] ;
if ( V_158 -> V_162 . V_120 && V_158 -> V_296 . V_120 ) {
snprintf ( V_158 -> V_53 , sizeof( V_158 -> V_53 ) - 1 ,
L_75 , V_55 -> V_53 , L_76 , V_380 ++ ) ;
V_381 ++ ;
} else if ( V_158 -> V_296 . V_120 ) {
snprintf ( V_158 -> V_53 , sizeof( V_158 -> V_53 ) - 1 ,
L_75 , V_55 -> V_53 , L_77 , V_380 ++ ) ;
} else if ( V_158 -> V_162 . V_120 ) {
snprintf ( V_158 -> V_53 , sizeof( V_158 -> V_53 ) - 1 ,
L_75 , V_55 -> V_53 , L_78 , V_381 ++ ) ;
} else {
continue;
}
V_17 = F_230 ( V_383 -> V_379 , & F_222 , 0 ,
V_158 -> V_53 , V_158 ) ;
if ( V_17 ) {
F_103 ( V_172 , L_79
L_80 , V_17 ) ;
goto V_385;
}
if ( V_2 -> V_139 & V_363 ) {
F_231 ( V_383 -> V_379 ,
& V_158 -> V_386 ) ;
}
}
V_17 = F_230 ( V_2 -> V_384 [ V_379 ] . V_379 ,
F_218 , 0 , V_55 -> V_53 , V_2 ) ;
if ( V_17 ) {
F_103 ( V_172 , L_81 , V_17 ) ;
goto V_385;
}
return 0 ;
V_385:
while ( V_379 ) {
V_379 -- ;
F_231 ( V_2 -> V_384 [ V_379 ] . V_379 ,
NULL ) ;
F_232 ( V_2 -> V_384 [ V_379 ] . V_379 ,
V_2 -> V_158 [ V_379 ] ) ;
}
V_2 -> V_139 &= ~ V_387 ;
F_233 ( V_2 -> V_9 ) ;
F_234 ( V_2 -> V_384 ) ;
V_2 -> V_384 = NULL ;
return V_17 ;
}
static T_11 F_235 ( int V_366 , void * V_92 )
{
struct V_1 * V_2 = V_92 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_157 * V_158 = V_2 -> V_158 [ 0 ] ;
T_1 V_330 ;
F_71 ( V_14 , V_353 , V_388 ) ;
V_330 = F_37 ( V_14 , V_345 ) ;
if ( ! V_330 ) {
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_217 ( V_2 , true , true ) ;
return V_389 ;
}
if ( V_330 & V_336 )
F_211 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
F_210 ( V_2 , V_330 ) ;
case V_112 :
case V_113 :
case V_114 :
if ( V_330 & V_368 ) {
F_105 ( V_369 , L_74 ) ;
V_2 -> V_154 |= V_155 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_345 , V_368 ) ;
}
F_209 ( V_2 , V_330 ) ;
break;
default:
break;
}
F_208 ( V_2 , V_330 ) ;
if ( F_24 ( V_330 & V_374 ) )
F_221 ( V_2 , V_330 ) ;
F_223 ( & V_158 -> V_251 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_217 ( V_2 , false , false ) ;
return V_375 ;
}
static int F_236 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
int V_17 ;
if ( V_2 -> V_139 & V_387 )
V_17 = F_229 ( V_2 ) ;
else if ( V_2 -> V_139 & V_390 )
V_17 = F_230 ( V_2 -> V_9 -> V_366 , F_235 , 0 ,
V_55 -> V_53 , V_2 ) ;
else
V_17 = F_230 ( V_2 -> V_9 -> V_366 , F_235 , V_391 ,
V_55 -> V_53 , V_2 ) ;
if ( V_17 )
F_103 ( V_172 , L_82 , V_17 ) ;
return V_17 ;
}
static void F_237 ( struct V_1 * V_2 )
{
int V_379 ;
if ( ! ( V_2 -> V_139 & V_387 ) ) {
F_232 ( V_2 -> V_9 -> V_366 , V_2 ) ;
return;
}
for ( V_379 = 0 ; V_379 < V_2 -> V_189 ; V_379 ++ ) {
struct V_157 * V_158 = V_2 -> V_158 [ V_379 ] ;
struct V_382 * V_383 = & V_2 -> V_384 [ V_379 ] ;
if ( ! V_158 -> V_296 . V_120 && ! V_158 -> V_162 . V_120 )
continue;
F_231 ( V_383 -> V_379 , NULL ) ;
F_232 ( V_383 -> V_379 , V_158 ) ;
}
F_232 ( V_2 -> V_384 [ V_379 ++ ] . V_379 , V_2 ) ;
}
static inline void F_238 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
F_71 ( & V_2 -> V_14 , V_353 , ~ 0 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_71 ( & V_2 -> V_14 , V_353 , 0xFFFF0000 ) ;
F_71 ( & V_2 -> V_14 , F_216 ( 0 ) , ~ 0 ) ;
F_71 ( & V_2 -> V_14 , F_216 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_212 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_139 & V_387 ) {
int V_379 ;
for ( V_379 = 0 ; V_379 < V_2 -> V_189 ; V_379 ++ )
F_239 ( V_2 -> V_384 [ V_379 ] . V_379 ) ;
F_239 ( V_2 -> V_384 [ V_379 ++ ] . V_379 ) ;
} else {
F_239 ( V_2 -> V_9 -> V_366 ) ;
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
T_6 V_392 = V_120 -> V_81 ;
int V_393 = 10 ;
T_1 V_394 = V_395 ;
T_4 V_149 = V_120 -> V_149 ;
F_71 ( V_14 , F_50 ( V_149 ) , 0 ) ;
F_212 ( V_14 ) ;
F_71 ( V_14 , F_45 ( V_149 ) ,
( V_392 & F_242 ( 32 ) ) ) ;
F_71 ( V_14 , F_46 ( V_149 ) , ( V_392 >> 32 ) ) ;
F_71 ( V_14 , F_47 ( V_149 ) ,
V_120 -> V_88 * sizeof( union V_61 ) ) ;
F_71 ( V_14 , F_48 ( V_149 ) , 0 ) ;
F_71 ( V_14 , F_49 ( V_149 ) , 0 ) ;
V_120 -> V_146 = V_2 -> V_396 + F_49 ( V_149 ) ;
if ( ! V_120 -> V_158 || ( V_120 -> V_158 -> V_318 < V_327 ) )
V_394 |= ( 1 << 16 ) ;
else
V_394 |= ( 8 << 16 ) ;
V_394 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_139 & V_363 ) {
V_120 -> V_397 = V_2 -> V_397 ;
V_120 -> V_398 = 0 ;
F_243 ( V_372 , & V_120 -> V_34 ) ;
} else {
V_120 -> V_397 = 0 ;
}
if ( ! F_15 ( V_399 , & V_120 -> V_34 ) ) {
struct V_157 * V_158 = V_120 -> V_158 ;
if ( V_158 )
F_244 ( V_120 -> V_55 ,
& V_158 -> V_386 ,
V_120 -> V_86 ) ;
}
F_34 ( V_132 , & V_120 -> V_34 ) ;
F_71 ( V_14 , F_50 ( V_149 ) , V_394 ) ;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_400 ) & V_401 ) )
return;
do {
F_245 ( 1000 , 2000 ) ;
V_394 = F_37 ( V_14 , F_50 ( V_149 ) ) ;
} while ( -- V_393 && ! ( V_394 & V_395 ) );
if ( ! V_393 )
F_103 ( V_156 , L_84 , V_149 ) ;
}
static void F_246 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_402 , V_403 ;
T_4 V_404 = F_247 ( V_2 -> V_55 ) ;
if ( V_14 -> V_108 . type == V_109 )
return;
V_402 = F_37 ( V_14 , V_405 ) ;
V_402 |= V_406 ;
F_71 ( V_14 , V_405 , V_402 ) ;
if ( V_2 -> V_139 & V_407 ) {
V_403 = V_408 ;
if ( V_404 > 4 )
V_403 |= V_409 | V_410 ;
else if ( V_404 > 1 )
V_403 |= V_409 | V_411 ;
else if ( V_2 -> V_412 [ V_413 ] . V_414 == 4 )
V_403 |= V_415 ;
else
V_403 |= V_416 ;
} else {
if ( V_404 > 4 )
V_403 = V_409 | V_410 ;
else if ( V_404 > 1 )
V_403 = V_409 | V_411 ;
else
V_403 = V_417 ;
}
F_71 ( V_14 , V_418 , V_403 ) ;
if ( V_404 ) {
T_1 V_419 = F_37 ( V_14 , V_420 ) ;
V_419 |= V_421 ;
F_71 ( V_14 , V_420 , V_419 ) ;
}
V_402 &= ~ V_406 ;
F_71 ( V_14 , V_405 , V_402 ) ;
}
static void F_248 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_422 ;
T_1 V_48 ;
F_246 ( V_2 ) ;
if ( V_14 -> V_108 . type != V_109 ) {
V_422 = F_37 ( V_14 , V_423 ) ;
V_422 |= V_424 ;
F_71 ( V_14 , V_423 , V_422 ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_241 ( V_2 , V_2 -> V_58 [ V_48 ] ) ;
}
static void F_249 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_149 = V_120 -> V_149 ;
T_1 V_425 = F_37 ( V_14 , F_36 ( V_149 ) ) ;
V_425 |= V_426 ;
F_71 ( V_14 , F_36 ( V_149 ) , V_425 ) ;
}
static void F_250 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_149 = V_120 -> V_149 ;
T_1 V_425 = F_37 ( V_14 , F_36 ( V_149 ) ) ;
V_425 &= ~ V_426 ;
F_71 ( V_14 , F_36 ( V_149 ) , V_425 ) ;
}
static void F_251 ( struct V_1 * V_2 ,
struct V_57 * V_67 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_425 ;
T_4 V_149 = V_67 -> V_149 ;
if ( V_14 -> V_108 . type == V_109 ) {
T_2 V_117 = V_2 -> V_412 [ V_413 ] . V_117 ;
V_149 &= V_117 ;
}
V_425 = V_266 << V_427 ;
V_425 |= F_69 ( V_67 ) >> V_428 ;
V_425 |= V_429 ;
F_71 ( V_14 , F_36 ( V_149 ) , V_425 ) ;
}
static void F_252 ( struct V_1 * V_2 , const T_1 * V_430 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_431 = 0 ;
int V_48 , V_49 ;
int V_432 = 128 ;
T_2 V_433 = V_2 -> V_412 [ V_413 ] . V_414 ;
int V_434 ;
if ( ( V_2 -> V_139 & V_407 ) && ( V_433 < 2 ) )
V_433 = 2 ;
for ( V_48 = 0 ; V_48 < 10 ; V_48 ++ )
F_71 ( V_14 , F_253 ( V_48 ) , V_430 [ V_48 ] ) ;
if ( V_2 -> V_14 . V_108 . type == V_109 )
V_434 = 0x11 ;
else
V_434 = 0x1 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_113 :
case V_114 :
if ( ! ( V_2 -> V_139 & V_407 ) )
V_432 = 512 ;
default:
break;
}
for ( V_48 = 0 , V_49 = 0 ; V_48 < V_432 ; V_48 ++ , V_49 ++ ) {
if ( V_49 == V_433 )
V_49 = 0 ;
V_431 = ( V_431 << 8 ) | ( V_49 * V_434 ) ;
if ( ( V_48 & 3 ) == 3 ) {
if ( V_48 < 128 )
F_71 ( V_14 , F_254 ( V_48 >> 2 ) , V_431 ) ;
else
F_71 ( V_14 , F_255 ( ( V_48 >> 2 ) - 32 ) ,
V_431 ) ;
}
}
}
static void F_256 ( struct V_1 * V_2 , const T_1 * V_430 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_435 = 0 ;
T_2 V_433 = V_2 -> V_412 [ V_413 ] . V_414 ;
unsigned int V_436 = V_2 -> V_304 ;
int V_48 , V_49 ;
for ( V_48 = 0 ; V_48 < 10 ; V_48 ++ )
F_71 ( V_14 , F_257 ( V_48 , V_436 ) , V_430 [ V_48 ] ) ;
for ( V_48 = 0 , V_49 = 0 ; V_48 < 64 ; V_48 ++ , V_49 ++ ) {
if ( V_49 == V_433 )
V_49 = 0 ;
V_435 = ( V_435 << 8 ) | V_49 ;
if ( ( V_48 & 3 ) == 3 )
F_71 ( V_14 , F_258 ( V_48 >> 2 , V_436 ) ,
V_435 ) ;
}
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_437 = 0 , V_438 = 0 , V_439 = 0 ;
T_1 V_440 [ 10 ] ;
T_1 V_441 ;
V_441 = F_37 ( V_14 , V_442 ) ;
V_441 |= V_443 ;
F_71 ( V_14 , V_442 , V_441 ) ;
if ( V_2 -> V_14 . V_108 . type == V_109 ) {
if ( V_2 -> V_412 [ V_413 ] . V_117 )
V_437 = V_444 ;
} else {
T_4 V_404 = F_247 ( V_2 -> V_55 ) ;
if ( V_2 -> V_139 & V_407 ) {
if ( V_404 > 4 )
V_437 = V_445 ;
else if ( V_404 > 1 )
V_437 = V_446 ;
else if ( V_2 -> V_412 [ V_413 ] . V_414 == 4 )
V_437 = V_447 ;
else
V_437 = V_448 ;
} else {
if ( V_404 > 4 )
V_437 = V_449 ;
else if ( V_404 > 1 )
V_437 = V_450 ;
else
V_437 = V_444 ;
}
}
V_438 |= V_451 |
V_452 |
V_453 |
V_454 ;
if ( V_2 -> V_154 & V_455 )
V_438 |= V_456 ;
if ( V_2 -> V_154 & V_457 )
V_438 |= V_458 ;
F_260 ( V_440 , sizeof( V_440 ) ) ;
if ( ( V_14 -> V_108 . type >= V_113 ) &&
( V_2 -> V_139 & V_407 ) ) {
unsigned int V_436 = V_2 -> V_304 ;
V_437 |= V_459 ;
F_71 ( V_14 , V_460 , V_437 ) ;
F_256 ( V_2 , V_440 ) ;
V_439 = V_444 ;
V_439 |= V_438 ;
F_71 ( V_14 , F_261 ( V_436 ) , V_439 ) ;
} else {
F_252 ( V_2 , V_440 ) ;
V_437 |= V_438 ;
F_71 ( V_14 , V_460 , V_437 ) ;
}
}
static void F_262 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_461 ;
T_4 V_149 = V_120 -> V_149 ;
if ( ! F_165 ( V_120 ) )
return;
V_461 = F_37 ( V_14 , F_263 ( V_149 ) ) ;
V_461 |= V_462 ;
V_461 |= V_463 ;
F_71 ( V_14 , F_263 ( V_149 ) , V_461 ) ;
}
static void F_264 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_393 = V_464 ;
T_1 V_465 ;
T_4 V_149 = V_120 -> V_149 ;
if ( F_22 ( V_14 -> V_39 ) )
return;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_400 ) & V_401 ) )
return;
do {
F_245 ( 1000 , 2000 ) ;
V_465 = F_37 ( V_14 , F_42 ( V_149 ) ) ;
} while ( -- V_393 && ! ( V_465 & V_466 ) );
if ( ! V_393 ) {
F_103 ( V_156 , L_85
L_86 , V_149 ) ;
}
}
void F_265 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_393 = V_464 ;
T_1 V_465 ;
T_4 V_149 = V_120 -> V_149 ;
if ( F_22 ( V_14 -> V_39 ) )
return;
V_465 = F_37 ( V_14 , F_42 ( V_149 ) ) ;
V_465 &= ~ V_466 ;
F_71 ( V_14 , F_42 ( V_149 ) , V_465 ) ;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_400 ) & V_401 ) )
return;
do {
F_266 ( 10 ) ;
V_465 = F_37 ( V_14 , F_42 ( V_149 ) ) ;
} while ( -- V_393 && ( V_465 & V_466 ) );
if ( ! V_393 ) {
F_103 ( V_156 , L_87
L_86 , V_149 ) ;
}
}
void F_267 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_467 = V_120 -> V_81 ;
T_1 V_465 ;
T_4 V_149 = V_120 -> V_149 ;
V_465 = F_37 ( V_14 , F_42 ( V_149 ) ) ;
F_265 ( V_2 , V_120 ) ;
F_71 ( V_14 , F_43 ( V_149 ) , ( V_467 & F_242 ( 32 ) ) ) ;
F_71 ( V_14 , F_44 ( V_149 ) , ( V_467 >> 32 ) ) ;
F_71 ( V_14 , F_39 ( V_149 ) ,
V_120 -> V_88 * sizeof( union V_68 ) ) ;
F_71 ( V_14 , F_40 ( V_149 ) , 0 ) ;
F_71 ( V_14 , F_41 ( V_149 ) , 0 ) ;
V_120 -> V_146 = V_2 -> V_396 + F_41 ( V_149 ) ;
F_251 ( V_2 , V_120 ) ;
F_262 ( V_2 , V_120 ) ;
if ( V_14 -> V_108 . type == V_109 ) {
V_465 &= ~ 0x3FFFFF ;
V_465 |= 0x080420 ;
}
V_465 |= V_466 ;
F_71 ( V_14 , F_42 ( V_149 ) , V_465 ) ;
F_264 ( V_2 , V_120 ) ;
F_142 ( V_120 , F_110 ( V_120 ) ) ;
}
static void F_268 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_433 = V_2 -> V_412 [ V_413 ] . V_414 ;
T_2 V_468 ;
T_1 V_469 = V_470 |
V_471 |
V_472 |
V_473 |
V_474 ;
if ( V_14 -> V_108 . type == V_109 )
return;
if ( V_433 > 3 )
V_469 |= 2 << 29 ;
else if ( V_433 > 1 )
V_469 |= 1 << 29 ;
F_269 (pool, &adapter->fwd_bitmask, 32 )
F_71 ( V_14 , F_270 ( F_271 ( V_468 ) ) , V_469 ) ;
}
static void F_272 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_177 , V_475 ;
T_1 V_476 , V_477 ;
int V_48 ;
if ( ! ( V_2 -> V_139 & V_407 ) )
return;
V_477 = F_37 ( V_14 , V_478 ) ;
V_477 |= V_479 ;
V_477 &= ~ V_480 ;
V_477 |= F_271 ( 0 ) << V_481 ;
V_477 |= V_482 ;
F_71 ( V_14 , V_478 , V_477 ) ;
V_475 = F_271 ( 0 ) % 32 ;
V_177 = ( F_271 ( 0 ) >= 32 ) ? 1 : 0 ;
F_71 ( V_14 , F_273 ( V_177 ) , ( ~ 0 ) << V_475 ) ;
F_71 ( V_14 , F_273 ( V_177 ^ 1 ) , V_177 - 1 ) ;
F_71 ( V_14 , F_274 ( V_177 ) , ( ~ 0 ) << V_475 ) ;
F_71 ( V_14 , F_274 ( V_177 ^ 1 ) , V_177 - 1 ) ;
if ( V_2 -> V_154 & V_483 )
F_71 ( V_14 , V_484 , V_485 ) ;
V_14 -> V_108 . V_337 . V_486 ( V_14 , 0 , F_271 ( 0 ) ) ;
switch ( V_2 -> V_412 [ V_487 ] . V_117 ) {
case V_488 :
V_476 = V_489 ;
break;
case V_490 :
V_476 = V_491 ;
break;
default:
V_476 = V_492 ;
break;
}
F_71 ( V_14 , V_493 , V_476 ) ;
V_14 -> V_108 . V_337 . V_494 ( V_14 , ( V_2 -> V_304 != 0 ) ,
V_2 -> V_304 ) ;
if ( V_14 -> V_108 . V_337 . V_495 )
F_71 ( V_14 , F_275 ( V_496 ) ,
( V_497 |
V_498 |
V_499 ) ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_304 ; V_48 ++ ) {
if ( ! V_2 -> V_500 [ V_48 ] . V_501 )
F_276 ( V_2 -> V_55 , V_48 , false ) ;
if ( V_14 -> V_108 . V_337 . V_495 )
V_14 -> V_108 . V_337 . V_495 ( V_14 , true , V_48 ) ;
}
}
static void F_277 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_55 = V_2 -> V_55 ;
int V_502 = V_55 -> V_292 + V_503 + V_504 ;
struct V_57 * V_67 ;
int V_48 ;
T_1 V_505 , V_506 ;
#ifdef F_176
if ( ( V_2 -> V_139 & V_507 ) &&
( V_502 < V_508 ) )
V_502 = V_508 ;
#endif
if ( V_502 < ( V_509 + V_504 ) )
V_502 = ( V_509 + V_504 ) ;
V_505 = F_37 ( V_14 , V_510 ) ;
if ( V_502 != ( V_505 >> V_511 ) ) {
V_505 &= ~ V_512 ;
V_505 |= V_502 << V_511 ;
F_71 ( V_14 , V_510 , V_505 ) ;
}
V_506 = F_37 ( V_14 , V_513 ) ;
V_506 |= V_514 ;
F_71 ( V_14 , V_513 , V_506 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_67 = V_2 -> V_67 [ V_48 ] ;
if ( V_2 -> V_154 & V_515 )
F_278 ( V_67 ) ;
else
F_279 ( V_67 ) ;
}
}
static void F_280 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_516 = F_37 ( V_14 , V_517 ) ;
switch ( V_14 -> V_108 . type ) {
case V_113 :
case V_114 :
case V_109 :
V_516 |= V_518 ;
break;
case V_111 :
case V_112 :
F_71 ( V_14 , V_519 ,
( V_520 | F_37 ( V_14 , V_519 ) ) ) ;
V_516 &= ~ V_521 ;
V_516 |= ( V_522 | V_523 ) ;
V_516 |= V_524 ;
break;
default:
return;
}
F_71 ( V_14 , V_517 , V_516 ) ;
}
static void F_281 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
T_1 V_182 , V_525 ;
V_182 = F_37 ( V_14 , V_526 ) ;
F_71 ( V_14 , V_526 , V_182 & ~ V_527 ) ;
F_268 ( V_2 ) ;
F_280 ( V_2 ) ;
V_525 = F_37 ( V_14 , V_528 ) ;
V_525 &= ~ V_529 ;
if ( ! ( V_2 -> V_154 & V_515 ) )
V_525 |= V_529 ;
F_71 ( V_14 , V_528 , V_525 ) ;
F_259 ( V_2 ) ;
F_277 ( V_2 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
F_267 ( V_2 , V_2 -> V_67 [ V_48 ] ) ;
if ( V_14 -> V_108 . type == V_109 )
V_182 |= V_530 ;
V_182 |= V_527 ;
V_14 -> V_108 . V_337 . V_531 ( V_14 , V_182 ) ;
}
static int F_282 ( struct V_54 * V_55 ,
T_12 V_532 , T_2 V_246 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_108 . V_337 . V_533 ( & V_2 -> V_14 , V_246 , F_271 ( 0 ) , true ) ;
F_243 ( V_246 , V_2 -> V_534 ) ;
return 0 ;
}
static int F_283 ( struct V_54 * V_55 ,
T_12 V_532 , T_2 V_246 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_108 . V_337 . V_533 ( & V_2 -> V_14 , V_246 , F_271 ( 0 ) , false ) ;
F_34 ( V_246 , V_2 -> V_534 ) ;
return 0 ;
}
static void F_284 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_535 ;
int V_48 , V_49 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_535 = F_37 ( V_14 , V_536 ) ;
V_535 &= ~ V_537 ;
F_71 ( V_14 , V_536 , V_535 ) ;
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
V_535 = F_37 ( V_14 , F_42 ( V_49 ) ) ;
V_535 &= ~ V_538 ;
F_71 ( V_14 , F_42 ( V_49 ) , V_535 ) ;
}
break;
default:
break;
}
}
static void F_285 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_535 ;
int V_48 , V_49 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_535 = F_37 ( V_14 , V_536 ) ;
V_535 |= V_537 ;
F_71 ( V_14 , V_536 , V_535 ) ;
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
V_535 = F_37 ( V_14 , F_42 ( V_49 ) ) ;
V_535 |= V_538 ;
F_71 ( V_14 , F_42 ( V_49 ) , V_535 ) ;
}
break;
default:
break;
}
}
static void F_286 ( struct V_1 * V_2 )
{
T_2 V_246 ;
F_282 ( V_2 -> V_55 , F_156 ( V_248 ) , 0 ) ;
F_269 (vid, adapter->active_vlans, VLAN_N_VID)
F_282 ( V_2 -> V_55 , F_156 ( V_248 ) , V_246 ) ;
}
static int F_287 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! F_57 ( V_55 ) )
return 0 ;
if ( V_14 -> V_108 . V_337 . V_539 )
V_14 -> V_108 . V_337 . V_539 ( V_14 , V_55 ) ;
else
return - V_540 ;
#ifdef F_288
F_289 ( V_2 ) ;
#endif
return F_290 ( V_55 ) ;
}
void F_291 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_541 ; V_48 ++ ) {
if ( V_2 -> V_542 [ V_48 ] . V_34 & V_543 )
V_14 -> V_108 . V_337 . V_544 ( V_14 , V_48 , V_2 -> V_542 [ V_48 ] . V_545 ,
V_2 -> V_542 [ V_48 ] . V_104 ,
V_546 ) ;
else
V_14 -> V_108 . V_337 . V_547 ( V_14 , V_48 ) ;
V_2 -> V_542 [ V_48 ] . V_34 &= ~ ( V_548 ) ;
}
}
static void F_292 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_541 ; V_48 ++ ) {
if ( V_2 -> V_542 [ V_48 ] . V_34 & V_548 ) {
if ( V_2 -> V_542 [ V_48 ] . V_34 &
V_543 )
V_14 -> V_108 . V_337 . V_544 ( V_14 , V_48 ,
V_2 -> V_542 [ V_48 ] . V_545 ,
V_2 -> V_542 [ V_48 ] . V_104 ,
V_546 ) ;
else
V_14 -> V_108 . V_337 . V_547 ( V_14 , V_48 ) ;
V_2 -> V_542 [ V_48 ] . V_34 &=
~ ( V_548 ) ;
}
}
}
static void F_293 ( struct V_1 * V_2 )
{
int V_48 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_541 ; V_48 ++ ) {
V_2 -> V_542 [ V_48 ] . V_34 |= V_548 ;
V_2 -> V_542 [ V_48 ] . V_34 &= ~ V_543 ;
memset ( V_2 -> V_542 [ V_48 ] . V_545 , 0 , V_549 ) ;
V_2 -> V_542 [ V_48 ] . V_104 = 0 ;
}
F_292 ( V_2 ) ;
}
static int F_294 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 , V_88 = 0 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_541 ; V_48 ++ ) {
if ( V_2 -> V_542 [ V_48 ] . V_34 == 0 )
V_88 ++ ;
}
return V_88 ;
}
static void F_295 ( struct V_1 * V_2 ,
T_4 * V_545 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
memcpy ( & V_2 -> V_542 [ 0 ] . V_545 , V_545 , V_549 ) ;
V_2 -> V_542 [ 0 ] . V_104 = F_271 ( 0 ) ;
V_2 -> V_542 [ 0 ] . V_34 = ( V_550 |
V_543 ) ;
V_14 -> V_108 . V_337 . V_544 ( V_14 , 0 , V_2 -> V_542 [ 0 ] . V_545 ,
V_2 -> V_542 [ 0 ] . V_104 ,
V_546 ) ;
}
int F_296 ( struct V_1 * V_2 , T_4 * V_545 , T_2 V_104 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
if ( F_297 ( V_545 ) )
return - V_551 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_541 ; V_48 ++ ) {
if ( V_2 -> V_542 [ V_48 ] . V_34 & V_543 )
continue;
V_2 -> V_542 [ V_48 ] . V_34 |= ( V_548 |
V_543 ) ;
F_298 ( V_2 -> V_542 [ V_48 ] . V_545 , V_545 ) ;
V_2 -> V_542 [ V_48 ] . V_104 = V_104 ;
F_292 ( V_2 ) ;
return V_48 ;
}
return - V_540 ;
}
int F_299 ( struct V_1 * V_2 , T_4 * V_545 , T_2 V_104 )
{
int V_48 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_297 ( V_545 ) )
return - V_551 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_541 ; V_48 ++ ) {
if ( F_300 ( V_545 , V_2 -> V_542 [ V_48 ] . V_545 ) &&
V_2 -> V_542 [ V_48 ] . V_104 == V_104 ) {
V_2 -> V_542 [ V_48 ] . V_34 |= V_548 ;
V_2 -> V_542 [ V_48 ] . V_34 &= ~ V_543 ;
memset ( V_2 -> V_542 [ V_48 ] . V_545 , 0 , V_549 ) ;
V_2 -> V_542 [ V_48 ] . V_104 = 0 ;
F_292 ( V_2 ) ;
return 0 ;
}
}
return - V_540 ;
}
static int F_301 ( struct V_54 * V_55 , int V_552 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_88 = 0 ;
if ( F_302 ( V_55 ) > F_294 ( V_2 ) )
return - V_540 ;
if ( ! F_303 ( V_55 ) ) {
struct V_553 * V_554 ;
F_304 (ha, netdev) {
F_299 ( V_2 , V_554 -> V_545 , V_552 ) ;
F_296 ( V_2 , V_554 -> V_545 , V_552 ) ;
V_88 ++ ;
}
}
return V_88 ;
}
void F_305 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_555 , V_556 = V_557 | V_558 ;
T_1 V_535 ;
int V_88 ;
V_555 = F_37 ( V_14 , V_559 ) ;
V_535 = F_37 ( V_14 , V_536 ) ;
V_555 &= ~ V_560 ;
V_555 |= V_561 ;
V_555 |= V_562 ;
V_555 |= V_563 ;
V_555 &= ~ ( V_564 | V_565 ) ;
V_535 &= ~ ( V_566 | V_567 ) ;
if ( V_55 -> V_139 & V_568 ) {
V_14 -> V_569 . V_570 = true ;
V_555 |= ( V_564 | V_565 ) ;
V_556 |= V_571 ;
if ( V_2 -> V_139 & ( V_572 |
V_407 ) )
V_535 |= ( V_566 | V_567 ) ;
} else {
if ( V_55 -> V_139 & V_573 ) {
V_555 |= V_565 ;
V_556 |= V_571 ;
}
V_535 |= V_566 ;
V_14 -> V_569 . V_570 = false ;
}
V_88 = F_301 ( V_55 , F_271 ( 0 ) ) ;
if ( V_88 < 0 ) {
V_555 |= V_564 ;
V_556 |= V_574 ;
}
V_88 = F_287 ( V_55 ) ;
if ( V_88 < 0 ) {
V_555 |= V_565 ;
V_556 |= V_571 ;
} else if ( V_88 ) {
V_556 |= V_575 ;
}
if ( V_14 -> V_108 . type != V_109 ) {
V_556 |= F_37 ( V_14 , F_306 ( F_271 ( 0 ) ) ) &
~ ( V_571 | V_575 |
V_574 ) ;
F_71 ( V_14 , F_306 ( F_271 ( 0 ) ) , V_556 ) ;
}
if ( V_2 -> V_55 -> V_196 & V_270 ) {
V_555 |= ( V_560 |
V_561 |
V_563 ) ;
V_555 &= ~ ( V_562 ) ;
}
F_71 ( V_14 , V_536 , V_535 ) ;
F_71 ( V_14 , V_559 , V_555 ) ;
if ( V_55 -> V_196 & V_244 )
F_285 ( V_2 ) ;
else
F_284 ( V_2 ) ;
}
static void F_307 ( struct V_1 * V_2 )
{
int V_576 ;
for ( V_576 = 0 ; V_576 < V_2 -> V_189 ; V_576 ++ ) {
F_308 ( V_2 -> V_158 [ V_576 ] ) ;
F_309 ( & V_2 -> V_158 [ V_576 ] -> V_251 ) ;
}
}
static void F_310 ( struct V_1 * V_2 )
{
int V_576 ;
for ( V_576 = 0 ; V_576 < V_2 -> V_189 ; V_576 ++ ) {
F_311 ( & V_2 -> V_158 [ V_576 ] -> V_251 ) ;
while ( ! F_312 ( V_2 -> V_158 [ V_576 ] ) ) {
F_51 ( L_88 , V_576 ) ;
F_245 ( 1000 , 20000 ) ;
}
}
}
static void F_313 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_502 = V_2 -> V_55 -> V_292 + V_503 + V_504 ;
if ( ! ( V_2 -> V_139 & V_140 ) ) {
if ( V_14 -> V_108 . type == V_109 )
F_314 ( V_2 -> V_55 , 65536 ) ;
return;
}
if ( V_14 -> V_108 . type == V_109 )
F_314 ( V_2 -> V_55 , 32768 ) ;
#ifdef F_176
if ( V_2 -> V_55 -> V_196 & V_577 )
V_502 = F_205 ( V_502 , V_508 ) ;
#endif
if ( V_2 -> V_578 & V_579 ) {
F_315 ( V_14 , & V_2 -> V_136 , V_502 ,
V_580 ) ;
F_315 ( V_14 , & V_2 -> V_136 , V_502 ,
V_581 ) ;
F_316 ( V_14 , & V_2 -> V_136 ) ;
} else if ( V_2 -> V_582 && V_2 -> V_138 ) {
F_317 ( & V_2 -> V_14 ,
V_2 -> V_582 ,
V_502 ) ;
F_318 ( & V_2 -> V_14 ,
V_2 -> V_138 -> V_135 ,
V_2 -> V_582 -> V_583 ) ;
}
if ( V_14 -> V_108 . type != V_109 ) {
T_1 V_584 = 0 ;
T_2 V_433 = V_2 -> V_412 [ V_413 ] . V_414 - 1 ;
while ( V_433 ) {
V_584 ++ ;
V_433 >>= 1 ;
}
F_71 ( V_14 , V_585 , V_584 * 0x11111111 ) ;
}
}
static int F_319 ( struct V_1 * V_2 , int V_586 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_73 = V_2 -> V_55 ;
int V_369 , V_134 , V_587 , V_588 ;
T_1 V_589 , V_590 ;
V_134 = V_369 = V_73 -> V_292 + V_503 + V_504 + V_591 ;
#ifdef F_176
if ( ( V_73 -> V_196 & V_577 ) &&
( V_134 < V_508 ) &&
( V_586 == F_320 ( V_2 ) ) )
V_134 = V_508 ;
#endif
switch ( V_14 -> V_108 . type ) {
case V_112 :
case V_113 :
case V_114 :
V_589 = F_321 ( V_369 , V_134 ) ;
break;
default:
V_589 = F_322 ( V_369 , V_134 ) ;
break;
}
if ( V_2 -> V_139 & V_407 )
V_589 += F_323 ( V_134 ) ;
V_587 = F_324 ( V_589 ) ;
V_590 = F_37 ( V_14 , F_325 ( V_586 ) ) >> 10 ;
V_588 = V_590 - V_587 ;
if ( V_588 < 0 ) {
F_93 ( V_156 , L_89
L_90
L_91 , V_586 ) ;
V_588 = V_134 + 1 ;
}
return V_588 ;
}
static int F_326 ( struct V_1 * V_2 , int V_586 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_73 = V_2 -> V_55 ;
int V_134 ;
T_1 V_589 ;
V_134 = V_73 -> V_292 + V_503 + V_504 ;
#ifdef F_176
if ( ( V_73 -> V_196 & V_577 ) &&
( V_134 < V_508 ) &&
( V_586 == F_86 ( V_73 , V_2 -> V_592 . V_593 ) ) )
V_134 = V_508 ;
#endif
switch ( V_14 -> V_108 . type ) {
case V_112 :
case V_113 :
case V_114 :
V_589 = F_327 ( V_134 ) ;
break;
default:
V_589 = F_328 ( V_134 ) ;
break;
}
return F_324 ( V_589 ) ;
}
static void F_329 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_594 = F_247 ( V_2 -> V_55 ) ;
int V_48 ;
if ( ! V_594 )
V_594 = 1 ;
for ( V_48 = 0 ; V_48 < V_594 ; V_48 ++ ) {
V_14 -> V_125 . V_595 [ V_48 ] = F_319 ( V_2 , V_48 ) ;
V_14 -> V_125 . V_596 [ V_48 ] = F_326 ( V_2 , V_48 ) ;
if ( V_14 -> V_125 . V_596 [ V_48 ] > V_14 -> V_125 . V_595 [ V_48 ] )
V_14 -> V_125 . V_596 [ V_48 ] = 0 ;
}
for (; V_48 < V_597 ; V_48 ++ )
V_14 -> V_125 . V_595 [ V_48 ] = 0 ;
}
static void F_330 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_598 ;
T_4 V_134 = F_247 ( V_2 -> V_55 ) ;
if ( V_2 -> V_139 & V_363 ||
V_2 -> V_139 & V_599 )
V_598 = 32 << V_2 -> V_600 ;
else
V_598 = 0 ;
V_14 -> V_108 . V_337 . V_601 ( V_14 , V_134 , V_598 , V_602 ) ;
F_329 ( V_2 ) ;
}
static void F_331 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_603 * V_604 ;
struct V_605 * V_606 ;
F_332 ( & V_2 -> V_607 ) ;
if ( ! F_333 ( & V_2 -> V_608 ) )
F_334 ( V_14 , & V_2 -> V_609 ) ;
F_335 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_336 ( V_14 ,
& V_606 -> V_606 ,
V_606 -> V_610 ,
( V_606 -> V_611 == V_612 ) ?
V_612 :
V_2 -> V_67 [ V_606 -> V_611 ] -> V_149 ) ;
}
F_337 ( & V_2 -> V_607 ) ;
}
static void F_338 ( struct V_54 * V_73 , unsigned int V_468 ,
struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_556 ;
V_556 = F_37 ( V_14 , F_306 ( V_468 ) ) ;
V_556 |= ( V_575 | V_557 | V_558 ) ;
V_556 &= ~ V_571 ;
if ( V_73 -> V_139 & V_573 ) {
V_556 |= V_571 ;
} else {
V_556 |= V_575 ;
V_14 -> V_108 . V_337 . V_539 ( V_14 , V_73 ) ;
}
F_301 ( V_2 -> V_55 , V_468 ) ;
F_71 ( V_14 , F_306 ( V_468 ) , V_556 ) ;
}
static void F_339 ( struct V_613 * V_614 )
{
struct V_1 * V_2 = V_614 -> V_148 ;
int V_433 = V_2 -> V_615 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_468 = V_614 -> V_468 ;
T_1 V_469 = V_470 |
V_471 |
V_472 |
V_473 |
V_474 ;
if ( V_14 -> V_108 . type == V_109 )
return;
if ( V_433 > 3 )
V_469 |= 2 << 29 ;
else if ( V_433 > 1 )
V_469 |= 1 << 29 ;
F_71 ( V_14 , F_270 ( F_271 ( V_468 ) ) , V_469 ) ;
}
static void F_340 ( struct V_57 * V_67 )
{
struct V_190 * V_73 = V_67 -> V_73 ;
unsigned long V_276 ;
T_2 V_48 ;
if ( ! V_67 -> V_71 )
return;
for ( V_48 = 0 ; V_48 < V_67 -> V_88 ; V_48 ++ ) {
struct V_70 * V_275 = & V_67 -> V_71 [ V_48 ] ;
if ( V_275 -> V_89 ) {
struct V_195 * V_89 = V_275 -> V_89 ;
if ( F_150 ( V_89 ) -> V_268 )
F_80 ( V_73 ,
F_150 ( V_89 ) -> V_81 ,
F_69 ( V_67 ) ,
V_231 ) ;
F_341 ( V_89 ) ;
V_275 -> V_89 = NULL ;
}
if ( ! V_275 -> V_98 )
continue;
F_80 ( V_73 , V_275 -> V_81 ,
F_139 ( V_67 ) , V_231 ) ;
F_141 ( V_275 -> V_98 , F_137 ( V_67 ) ) ;
V_275 -> V_98 = NULL ;
}
V_276 = sizeof( struct V_70 ) * V_67 -> V_88 ;
memset ( V_67 -> V_71 , 0 , V_276 ) ;
memset ( V_67 -> V_87 , 0 , V_67 -> V_276 ) ;
V_67 -> V_235 = 0 ;
V_67 -> V_79 = 0 ;
V_67 -> V_80 = 0 ;
}
static void F_342 ( struct V_613 * V_614 ,
struct V_57 * V_67 )
{
struct V_1 * V_2 = V_614 -> V_148 ;
int V_107 = V_67 -> V_86 + V_614 -> V_616 ;
F_265 ( V_2 , V_67 ) ;
F_245 ( 10000 , 20000 ) ;
F_215 ( V_2 , ( ( T_6 ) 1 << V_107 ) ) ;
F_340 ( V_67 ) ;
V_67 -> V_147 = NULL ;
}
static int F_343 ( struct V_54 * V_617 ,
struct V_613 * V_618 )
{
struct V_1 * V_2 = V_618 -> V_148 ;
unsigned int V_619 = V_618 -> V_616 ;
unsigned int V_620 = V_618 -> V_621 ;
int V_48 ;
F_344 ( V_617 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_615 ; V_48 ++ ) {
F_342 ( V_618 , V_2 -> V_67 [ V_619 + V_48 ] ) ;
V_2 -> V_67 [ V_619 + V_48 ] -> V_55 = V_2 -> V_55 ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_615 ; V_48 ++ ) {
V_2 -> V_58 [ V_620 + V_48 ] -> V_147 = NULL ;
V_2 -> V_58 [ V_620 + V_48 ] -> V_55 = V_2 -> V_55 ;
}
return 0 ;
}
static int F_345 ( struct V_54 * V_617 ,
struct V_613 * V_618 )
{
struct V_1 * V_2 = V_618 -> V_148 ;
unsigned int V_619 , V_620 , V_356 ;
int V_48 , V_622 , V_17 = 0 ;
if ( ! F_14 ( V_618 -> V_468 , & V_2 -> V_623 ) )
return 0 ;
V_622 = V_618 -> V_468 * V_2 -> V_615 ;
F_346 ( V_617 , L_92 ,
V_618 -> V_468 , V_2 -> V_624 ,
V_622 , V_622 + V_2 -> V_615 ,
V_2 -> V_623 ) ;
V_618 -> V_55 = V_617 ;
V_618 -> V_616 = V_619 = V_622 ;
V_618 -> V_621 = V_620 = V_622 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_615 ; V_48 ++ )
F_342 ( V_618 , V_2 -> V_67 [ V_619 + V_48 ] ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_615 ; V_48 ++ ) {
V_2 -> V_67 [ V_619 + V_48 ] -> V_55 = V_617 ;
V_2 -> V_67 [ V_619 + V_48 ] -> V_147 = V_618 ;
F_267 ( V_2 , V_2 -> V_67 [ V_619 + V_48 ] ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_615 ; V_48 ++ ) {
V_2 -> V_58 [ V_620 + V_48 ] -> V_55 = V_617 ;
V_2 -> V_58 [ V_620 + V_48 ] -> V_147 = V_618 ;
}
V_356 = F_347 (unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues) ;
V_17 = F_348 ( V_617 , V_356 ) ;
if ( V_17 )
goto V_625;
V_17 = F_349 ( V_617 , V_356 ) ;
if ( V_17 )
goto V_625;
if ( F_350 ( V_617 -> V_626 ) )
F_296 ( V_2 , V_617 -> V_626 , V_618 -> V_468 ) ;
F_339 ( V_618 ) ;
F_338 ( V_617 , V_618 -> V_468 , V_2 ) ;
return V_17 ;
V_625:
F_343 ( V_617 , V_618 ) ;
return V_17 ;
}
static void F_351 ( struct V_1 * V_2 )
{
struct V_54 * V_95 ;
struct V_627 * V_628 ;
int V_17 ;
F_352 (adapter->netdev, upper, iter) {
if ( F_353 ( V_95 ) ) {
struct V_629 * V_630 = F_89 ( V_95 ) ;
struct V_613 * V_614 = V_630 -> V_631 ;
if ( V_630 -> V_631 ) {
V_17 = F_345 ( V_95 , V_614 ) ;
if ( V_17 )
continue;
}
}
}
}
static void F_354 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
F_330 ( V_2 ) ;
#ifdef F_355
F_313 ( V_2 ) ;
#endif
F_272 ( V_2 ) ;
F_305 ( V_2 -> V_55 ) ;
F_286 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
V_14 -> V_108 . V_337 . V_632 ( V_14 ) ;
break;
default:
break;
}
if ( V_2 -> V_139 & V_363 ) {
F_356 ( & V_2 -> V_14 ,
V_2 -> V_600 ) ;
} else if ( V_2 -> V_139 & V_599 ) {
F_357 ( & V_2 -> V_14 ,
V_2 -> V_600 ) ;
F_331 ( V_2 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
V_14 -> V_108 . V_337 . V_633 ( V_14 ) ;
break;
default:
break;
}
#ifdef F_176
F_358 ( V_2 ) ;
#endif
F_248 ( V_2 ) ;
F_281 ( V_2 ) ;
F_351 ( V_2 ) ;
}
static inline bool F_359 ( struct V_15 * V_14 )
{
switch ( V_14 -> V_340 . type ) {
case V_634 :
case V_635 :
case V_636 :
case V_637 :
case V_638 :
case V_639 :
case V_640 :
case V_641 :
case V_642 :
case V_643 :
case V_644 :
case V_645 :
case V_646 :
return true ;
case V_647 :
if ( V_14 -> V_108 . type == V_109 )
return true ;
default:
return false ;
}
}
static void F_360 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_108 . type == V_109 )
V_2 -> V_154 |= V_648 ;
V_2 -> V_154 |= V_348 ;
}
static int F_361 ( struct V_15 * V_14 )
{
T_1 V_20 ;
bool V_649 , V_339 = false ;
T_1 V_650 = V_651 ;
if ( V_14 -> V_108 . V_337 . V_338 )
V_650 = V_14 -> V_108 . V_337 . V_338 ( V_14 , & V_20 , & V_339 , false ) ;
if ( V_650 )
return V_650 ;
V_20 = V_14 -> V_340 . V_652 ;
if ( ( ! V_20 ) && ( V_14 -> V_108 . V_337 . V_653 ) )
V_650 = V_14 -> V_108 . V_337 . V_653 ( V_14 , & V_20 ,
& V_649 ) ;
if ( V_650 )
return V_650 ;
if ( V_14 -> V_108 . V_337 . V_654 )
V_650 = V_14 -> V_108 . V_337 . V_654 ( V_14 , V_20 , V_339 ) ;
return V_650 ;
}
static void F_362 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_655 = 0 ;
if ( V_2 -> V_139 & V_387 ) {
V_655 = V_656 | V_657 |
V_658 ;
V_655 |= V_659 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
F_71 ( V_14 , V_660 , V_661 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
default:
F_71 ( V_14 , F_363 ( 0 ) , 0xFFFFFFFF ) ;
F_71 ( V_14 , F_363 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_71 ( V_14 , V_660 , V_661 ) ;
}
if ( V_2 -> V_139 & V_407 ) {
V_655 &= ~ V_662 ;
switch ( V_2 -> V_412 [ V_487 ] . V_117 ) {
case V_488 :
V_655 |= V_663 ;
break;
case V_490 :
V_655 |= V_664 ;
break;
default:
V_655 |= V_665 ;
break;
}
}
if ( V_2 -> V_154 & V_332 ) {
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_655 |= V_666 ;
break;
case V_112 :
V_655 |= V_359 ;
break;
default:
break;
}
}
if ( V_2 -> V_139 & V_343 )
V_655 |= V_667 ;
if ( V_14 -> V_108 . type == V_111 ) {
V_655 |= V_667 ;
V_655 |= V_668 ;
}
F_71 ( V_14 , V_669 , V_655 ) ;
}
static void F_364 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 ;
T_1 V_100 ;
F_72 ( V_2 ) ;
F_362 ( V_2 ) ;
if ( V_2 -> V_139 & V_387 )
F_200 ( V_2 ) ;
else
F_240 ( V_2 ) ;
if ( V_14 -> V_108 . V_337 . V_670 )
V_14 -> V_108 . V_337 . V_670 ( V_14 ) ;
F_33 () ;
F_34 ( V_33 , & V_2 -> V_34 ) ;
F_307 ( V_2 ) ;
if ( F_359 ( V_14 ) ) {
F_360 ( V_2 ) ;
} else {
V_17 = F_361 ( V_14 ) ;
if ( V_17 )
F_103 ( V_172 , L_93 , V_17 ) ;
}
F_37 ( V_14 , V_345 ) ;
F_217 ( V_2 , true , true ) ;
if ( V_2 -> V_139 & V_343 ) {
T_1 V_671 = F_37 ( V_14 , V_672 ) ;
if ( V_671 & V_673 )
F_207 ( V_156 , L_73 ) ;
}
V_2 -> V_139 |= V_351 ;
V_2 -> V_352 = V_171 ;
F_365 ( & V_2 -> V_674 , V_171 ) ;
V_100 = F_37 ( V_14 , V_101 ) ;
V_100 |= V_675 ;
F_71 ( V_14 , V_101 , V_100 ) ;
}
void F_366 ( struct V_1 * V_2 )
{
F_367 ( F_368 () ) ;
V_2 -> V_55 -> V_74 = V_171 ;
while ( F_15 ( V_676 , & V_2 -> V_34 ) )
F_245 ( 1000 , 2000 ) ;
F_369 ( V_2 ) ;
if ( V_2 -> V_139 & V_407 )
F_370 ( 2000 ) ;
F_371 ( V_2 ) ;
F_34 ( V_676 , & V_2 -> V_34 ) ;
}
void F_371 ( struct V_1 * V_2 )
{
F_354 ( V_2 ) ;
F_364 ( V_2 ) ;
}
void F_372 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_55 = V_2 -> V_55 ;
int V_17 ;
T_4 V_677 [ V_549 ] ;
if ( F_22 ( V_14 -> V_39 ) )
return;
while ( F_15 ( V_678 , & V_2 -> V_34 ) )
F_245 ( 1000 , 2000 ) ;
V_2 -> V_154 &= ~ ( V_648 |
V_348 ) ;
V_2 -> V_139 &= ~ V_349 ;
V_17 = V_14 -> V_108 . V_337 . V_679 ( V_14 ) ;
switch ( V_17 ) {
case 0 :
case V_680 :
case V_681 :
break;
case V_682 :
F_18 ( L_94 ) ;
break;
case V_683 :
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
F_34 ( V_678 , & V_2 -> V_34 ) ;
memcpy ( V_677 , & V_2 -> V_542 [ 0 ] . V_545 , V_55 -> V_684 ) ;
F_293 ( V_2 ) ;
F_295 ( V_2 , V_677 ) ;
if ( V_14 -> V_108 . V_685 )
V_14 -> V_108 . V_337 . V_686 ( V_14 , F_271 ( 0 ) ) ;
if ( F_14 ( V_687 , & V_2 -> V_34 ) )
F_373 ( V_2 ) ;
}
static void F_374 ( struct V_57 * V_58 )
{
struct V_59 * V_78 ;
unsigned long V_276 ;
T_2 V_48 ;
if ( ! V_58 -> V_78 )
return;
for ( V_48 = 0 ; V_48 < V_58 -> V_88 ; V_48 ++ ) {
V_78 = & V_58 -> V_78 [ V_48 ] ;
F_77 ( V_58 , V_78 ) ;
}
F_375 ( F_107 ( V_58 ) ) ;
V_276 = sizeof( struct V_59 ) * V_58 -> V_88 ;
memset ( V_58 -> V_78 , 0 , V_276 ) ;
memset ( V_58 -> V_87 , 0 , V_58 -> V_276 ) ;
V_58 -> V_80 = 0 ;
V_58 -> V_79 = 0 ;
}
static void F_376 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
F_340 ( V_2 -> V_67 [ V_48 ] ) ;
}
static void F_377 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_374 ( V_2 -> V_58 [ V_48 ] ) ;
}
static void F_378 ( struct V_1 * V_2 )
{
struct V_603 * V_604 ;
struct V_605 * V_606 ;
F_332 ( & V_2 -> V_607 ) ;
F_335 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_379 ( & V_606 -> V_688 ) ;
F_234 ( V_606 ) ;
}
V_2 -> V_689 = 0 ;
F_337 ( & V_2 -> V_607 ) ;
}
void F_369 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_95 ;
struct V_627 * V_628 ;
T_1 V_182 ;
int V_48 ;
if ( F_15 ( V_33 , & V_2 -> V_34 ) )
return;
V_182 = F_37 ( V_14 , V_526 ) ;
F_71 ( V_14 , V_526 , V_182 & ~ V_527 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
F_265 ( V_2 , V_2 -> V_67 [ V_48 ] ) ;
F_245 ( 10000 , 20000 ) ;
F_344 ( V_55 ) ;
F_380 ( V_55 ) ;
F_381 ( V_55 ) ;
F_352 (adapter->netdev, upper, iter) {
if ( F_353 ( V_95 ) ) {
struct V_629 * V_247 = F_89 ( V_95 ) ;
if ( V_247 -> V_631 ) {
F_344 ( V_95 ) ;
F_380 ( V_95 ) ;
F_381 ( V_95 ) ;
}
}
}
F_238 ( V_2 ) ;
F_310 ( V_2 ) ;
V_2 -> V_154 &= ~ ( V_364 |
V_155 ) ;
V_2 -> V_139 &= ~ V_351 ;
F_382 ( & V_2 -> V_674 ) ;
if ( V_2 -> V_304 ) {
F_71 ( & V_2 -> V_14 , V_306 , 0 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_304 ; V_48 ++ )
V_2 -> V_500 [ V_48 ] . V_690 = false ;
F_383 ( V_2 ) ;
F_384 ( V_2 ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
T_4 V_149 = V_2 -> V_58 [ V_48 ] -> V_149 ;
F_71 ( V_14 , F_50 ( V_149 ) , V_691 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_71 ( V_14 , V_423 ,
( F_37 ( V_14 , V_423 ) &
~ V_424 ) ) ;
break;
default:
break;
}
if ( ! F_385 ( V_2 -> V_9 ) )
F_372 ( V_2 ) ;
if ( V_14 -> V_108 . V_337 . V_692 )
V_14 -> V_108 . V_337 . V_692 ( V_14 ) ;
F_377 ( V_2 ) ;
F_376 ( V_2 ) ;
#ifdef F_225
F_123 ( V_2 ) ;
#endif
}
static void F_386 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
F_92 ( V_2 ) ;
}
static int F_387 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_200 , V_693 ;
T_1 V_694 ;
#ifdef F_355
int V_49 ;
struct V_695 * V_134 ;
#endif
V_14 -> V_696 = V_9 -> V_697 ;
V_14 -> V_21 = V_9 -> V_190 ;
V_14 -> V_698 = V_9 -> V_699 ;
V_14 -> V_700 = V_9 -> V_701 ;
V_14 -> V_702 = V_9 -> V_703 ;
V_200 = F_347 ( int , F_388 ( V_2 ) , F_389 () ) ;
V_2 -> V_412 [ V_413 ] . V_704 = V_200 ;
V_2 -> V_154 |= V_705 ;
V_2 -> V_154 |= V_515 ;
V_2 -> V_706 = V_707 ;
V_2 -> V_397 = 20 ;
V_693 = F_347 ( int , V_708 , F_389 () ) ;
V_2 -> V_412 [ V_709 ] . V_704 = V_693 ;
V_2 -> V_600 = V_710 ;
#ifdef F_225
V_2 -> V_139 |= V_192 ;
#endif
#ifdef F_176
V_2 -> V_139 |= V_711 ;
V_2 -> V_139 &= ~ V_507 ;
#ifdef F_355
V_2 -> V_592 . V_593 = V_712 ;
#endif
#endif
V_2 -> V_542 = F_390 ( sizeof( struct V_713 ) *
V_14 -> V_108 . V_541 ,
V_714 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_2 -> V_154 &= ~ V_705 ;
V_2 -> V_154 &= ~ V_515 ;
if ( V_14 -> V_21 == V_715 )
V_2 -> V_139 |= V_343 ;
V_2 -> V_706 = V_716 ;
V_2 -> V_412 [ V_709 ] . V_704 = 0 ;
V_2 -> V_397 = 0 ;
V_2 -> V_600 = 0 ;
#ifdef F_176
V_2 -> V_139 &= ~ V_711 ;
V_2 -> V_139 &= ~ V_507 ;
#ifdef F_355
V_2 -> V_592 . V_593 = 0 ;
#endif
#endif
break;
case V_111 :
if ( V_14 -> V_21 == V_334 )
V_2 -> V_154 |= V_332 ;
break;
case V_112 :
V_694 = F_37 ( V_14 , V_717 ) ;
if ( V_694 & V_718 )
V_2 -> V_154 |= V_332 ;
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
F_391 ( & V_2 -> V_592 . V_719 ) ;
#endif
F_391 ( & V_2 -> V_607 ) ;
#ifdef F_355
switch ( V_14 -> V_108 . type ) {
case V_112 :
case V_113 :
case V_114 :
V_2 -> V_136 . V_720 . V_721 = V_722 ;
V_2 -> V_136 . V_720 . V_723 = V_722 ;
break;
default:
V_2 -> V_136 . V_720 . V_721 = V_597 ;
V_2 -> V_136 . V_720 . V_723 = V_597 ;
break;
}
for ( V_49 = 0 ; V_49 < V_597 ; V_49 ++ ) {
V_134 = & V_2 -> V_136 . V_724 [ V_49 ] ;
V_134 -> V_725 [ V_580 ] . V_726 = 0 ;
V_134 -> V_725 [ V_580 ] . V_727 = 12 + ( V_49 & 1 ) ;
V_134 -> V_725 [ V_581 ] . V_726 = 0 ;
V_134 -> V_725 [ V_581 ] . V_727 = 12 + ( V_49 & 1 ) ;
V_134 -> V_728 = V_729 ;
}
V_134 = & V_2 -> V_136 . V_724 [ 0 ] ;
V_134 -> V_725 [ V_580 ] . V_730 = 0xFF ;
V_134 -> V_725 [ V_581 ] . V_730 = 0xFF ;
V_2 -> V_136 . V_731 [ V_580 ] [ 0 ] = 100 ;
V_2 -> V_136 . V_731 [ V_581 ] [ 0 ] = 100 ;
V_2 -> V_136 . V_137 = false ;
V_2 -> V_732 = 0x00 ;
V_2 -> V_578 = V_733 | V_579 ;
memcpy ( & V_2 -> V_734 , & V_2 -> V_136 ,
sizeof( V_2 -> V_734 ) ) ;
#endif
V_14 -> V_125 . V_735 = V_127 ;
V_14 -> V_125 . V_126 = V_127 ;
F_329 ( V_2 ) ;
V_14 -> V_125 . V_736 = V_737 ;
V_14 -> V_125 . V_738 = true ;
V_14 -> V_125 . V_739 = F_392 ( V_14 ) ;
#ifdef F_288
if ( V_740 > 0 )
F_11 ( L_102 ) ;
if ( V_14 -> V_108 . type != V_109 ) {
if ( V_740 > V_741 ) {
V_2 -> V_304 = 0 ;
F_11 ( L_103 ) ;
} else {
V_2 -> V_304 = V_740 ;
}
}
#endif
V_2 -> V_378 = 1 ;
V_2 -> V_742 = 1 ;
V_2 -> V_743 = V_744 ;
V_2 -> V_745 = V_746 ;
V_2 -> V_747 = V_748 ;
if ( F_393 ( V_14 ) ) {
F_18 ( L_104 ) ;
return - V_749 ;
}
F_243 ( 0 , & V_2 -> V_623 ) ;
F_243 ( V_33 , & V_2 -> V_34 ) ;
return 0 ;
}
int F_394 ( struct V_57 * V_58 )
{
struct V_190 * V_73 = V_58 -> V_73 ;
int V_750 = F_395 ( V_73 ) ;
int V_751 = - 1 ;
int V_276 ;
V_276 = sizeof( struct V_59 ) * V_58 -> V_88 ;
if ( V_58 -> V_158 )
V_751 = V_58 -> V_158 -> V_752 ;
V_58 -> V_78 = F_396 ( V_276 , V_751 ) ;
if ( ! V_58 -> V_78 )
V_58 -> V_78 = F_397 ( V_276 ) ;
if ( ! V_58 -> V_78 )
goto V_17;
F_398 ( & V_58 -> V_169 ) ;
V_58 -> V_276 = V_58 -> V_88 * sizeof( union V_61 ) ;
V_58 -> V_276 = F_170 ( V_58 -> V_276 , 4096 ) ;
F_399 ( V_73 , V_751 ) ;
V_58 -> V_87 = F_400 ( V_73 ,
V_58 -> V_276 ,
& V_58 -> V_81 ,
V_753 ) ;
F_399 ( V_73 , V_750 ) ;
if ( ! V_58 -> V_87 )
V_58 -> V_87 = F_400 ( V_73 , V_58 -> V_276 ,
& V_58 -> V_81 , V_753 ) ;
if ( ! V_58 -> V_87 )
goto V_17;
V_58 -> V_80 = 0 ;
V_58 -> V_79 = 0 ;
return 0 ;
V_17:
F_401 ( V_58 -> V_78 ) ;
V_58 -> V_78 = NULL ;
F_402 ( V_73 , L_105 ) ;
return - V_540 ;
}
static int F_403 ( struct V_1 * V_2 )
{
int V_48 , V_17 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
V_17 = F_394 ( V_2 -> V_58 [ V_48 ] ) ;
if ( ! V_17 )
continue;
F_103 ( V_172 , L_106 , V_48 ) ;
goto V_754;
}
return 0 ;
V_754:
while ( V_48 -- )
F_404 ( V_2 -> V_58 [ V_48 ] ) ;
return V_17 ;
}
int F_405 ( struct V_57 * V_67 )
{
struct V_190 * V_73 = V_67 -> V_73 ;
int V_750 = F_395 ( V_73 ) ;
int V_751 = - 1 ;
int V_276 ;
V_276 = sizeof( struct V_70 ) * V_67 -> V_88 ;
if ( V_67 -> V_158 )
V_751 = V_67 -> V_158 -> V_752 ;
V_67 -> V_71 = F_396 ( V_276 , V_751 ) ;
if ( ! V_67 -> V_71 )
V_67 -> V_71 = F_397 ( V_276 ) ;
if ( ! V_67 -> V_71 )
goto V_17;
F_398 ( & V_67 -> V_169 ) ;
V_67 -> V_276 = V_67 -> V_88 * sizeof( union V_68 ) ;
V_67 -> V_276 = F_170 ( V_67 -> V_276 , 4096 ) ;
F_399 ( V_73 , V_751 ) ;
V_67 -> V_87 = F_400 ( V_73 ,
V_67 -> V_276 ,
& V_67 -> V_81 ,
V_753 ) ;
F_399 ( V_73 , V_750 ) ;
if ( ! V_67 -> V_87 )
V_67 -> V_87 = F_400 ( V_73 , V_67 -> V_276 ,
& V_67 -> V_81 , V_753 ) ;
if ( ! V_67 -> V_87 )
goto V_17;
V_67 -> V_79 = 0 ;
V_67 -> V_80 = 0 ;
return 0 ;
V_17:
F_401 ( V_67 -> V_71 ) ;
V_67 -> V_71 = NULL ;
F_402 ( V_73 , L_107 ) ;
return - V_540 ;
}
static int F_406 ( struct V_1 * V_2 )
{
int V_48 , V_17 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_17 = F_405 ( V_2 -> V_67 [ V_48 ] ) ;
if ( ! V_17 )
continue;
F_103 ( V_172 , L_108 , V_48 ) ;
goto V_755;
}
#ifdef F_176
V_17 = F_407 ( V_2 ) ;
if ( ! V_17 )
#endif
return 0 ;
V_755:
while ( V_48 -- )
F_408 ( V_2 -> V_67 [ V_48 ] ) ;
return V_17 ;
}
void F_404 ( struct V_57 * V_58 )
{
F_374 ( V_58 ) ;
F_401 ( V_58 -> V_78 ) ;
V_58 -> V_78 = NULL ;
if ( ! V_58 -> V_87 )
return;
F_409 ( V_58 -> V_73 , V_58 -> V_276 ,
V_58 -> V_87 , V_58 -> V_81 ) ;
V_58 -> V_87 = NULL ;
}
static void F_410 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
if ( V_2 -> V_58 [ V_48 ] -> V_87 )
F_404 ( V_2 -> V_58 [ V_48 ] ) ;
}
void F_408 ( struct V_57 * V_67 )
{
F_340 ( V_67 ) ;
F_401 ( V_67 -> V_71 ) ;
V_67 -> V_71 = NULL ;
if ( ! V_67 -> V_87 )
return;
F_409 ( V_67 -> V_73 , V_67 -> V_276 ,
V_67 -> V_87 , V_67 -> V_81 ) ;
V_67 -> V_87 = NULL ;
}
static void F_411 ( struct V_1 * V_2 )
{
int V_48 ;
#ifdef F_176
F_412 ( V_2 ) ;
#endif
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
if ( V_2 -> V_67 [ V_48 ] -> V_87 )
F_408 ( V_2 -> V_67 [ V_48 ] ) ;
}
static int F_413 ( struct V_54 * V_55 , int V_756 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_502 = V_756 + V_503 + V_504 ;
if ( ( V_756 < 68 ) || ( V_502 > V_757 ) )
return - V_551 ;
if ( ( V_2 -> V_139 & V_407 ) &&
( V_2 -> V_14 . V_108 . type == V_111 ) &&
( V_502 > ( V_509 + V_504 ) ) )
F_93 ( V_172 , L_109 ) ;
F_105 ( V_172 , L_110 , V_55 -> V_292 , V_756 ) ;
V_55 -> V_292 = V_756 ;
if ( F_57 ( V_55 ) )
F_366 ( V_2 ) ;
return 0 ;
}
static int F_414 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_17 , V_356 ;
if ( F_14 ( V_758 , & V_2 -> V_34 ) )
return - V_759 ;
F_380 ( V_55 ) ;
V_17 = F_403 ( V_2 ) ;
if ( V_17 )
goto V_754;
V_17 = F_406 ( V_2 ) ;
if ( V_17 )
goto V_755;
F_354 ( V_2 ) ;
V_17 = F_236 ( V_2 ) ;
if ( V_17 )
goto V_760;
if ( V_2 -> V_624 > 1 )
V_356 = V_2 -> V_615 ;
else
V_356 = V_2 -> V_77 ;
V_17 = F_348 ( V_55 , V_356 ) ;
if ( V_17 )
goto V_761;
if ( V_2 -> V_624 > 1 &&
V_2 -> V_93 > V_762 )
V_356 = V_762 ;
else
V_356 = V_2 -> V_93 ;
V_17 = F_349 ( V_55 , V_356 ) ;
if ( V_17 )
goto V_761;
F_415 ( V_2 ) ;
F_364 ( V_2 ) ;
#if F_416 ( V_763 )
F_417 ( V_55 ) ;
#endif
return 0 ;
V_761:
F_237 ( V_2 ) ;
V_760:
F_411 ( V_2 ) ;
V_755:
F_410 ( V_2 ) ;
V_754:
F_372 ( V_2 ) ;
return V_17 ;
}
static void F_418 ( struct V_1 * V_2 )
{
F_419 ( V_2 ) ;
F_369 ( V_2 ) ;
F_237 ( V_2 ) ;
F_410 ( V_2 ) ;
F_411 ( V_2 ) ;
}
static int F_420 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
F_421 ( V_2 ) ;
F_418 ( V_2 ) ;
F_378 ( V_2 ) ;
F_70 ( V_2 ) ;
return 0 ;
}
static int F_422 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_423 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
T_1 V_17 ;
V_2 -> V_14 . V_39 = V_2 -> V_396 ;
F_424 ( V_9 , V_764 ) ;
F_425 ( V_9 ) ;
F_426 ( V_9 ) ;
V_17 = F_427 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_111 ) ;
return V_17 ;
}
F_33 () ;
F_34 ( V_765 , & V_2 -> V_34 ) ;
F_428 ( V_9 ) ;
F_429 ( V_9 , false ) ;
F_372 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_766 , ~ 0 ) ;
F_430 () ;
V_17 = F_431 ( V_2 ) ;
if ( ! V_17 && F_57 ( V_55 ) )
V_17 = F_414 ( V_55 ) ;
F_432 () ;
if ( V_17 )
return V_17 ;
F_433 ( V_55 ) ;
return 0 ;
}
static int F_434 ( struct V_5 * V_9 , bool * V_767 )
{
struct V_1 * V_2 = F_423 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_768 , V_555 ;
T_1 V_769 = V_2 -> V_770 ;
#ifdef F_435
int V_771 = 0 ;
#endif
F_436 ( V_55 ) ;
F_430 () ;
if ( F_57 ( V_55 ) )
F_418 ( V_2 ) ;
F_432 () ;
F_437 ( V_2 ) ;
#ifdef F_435
V_771 = F_426 ( V_9 ) ;
if ( V_771 )
return V_771 ;
#endif
if ( V_14 -> V_108 . V_337 . V_772 )
V_14 -> V_108 . V_337 . V_772 ( V_14 ) ;
if ( V_769 ) {
F_305 ( V_55 ) ;
if ( V_14 -> V_108 . V_337 . V_670 )
V_14 -> V_108 . V_337 . V_670 ( V_14 ) ;
if ( V_769 & V_773 ) {
V_555 = F_37 ( V_14 , V_559 ) ;
V_555 |= V_565 ;
F_71 ( V_14 , V_559 , V_555 ) ;
}
V_768 = F_37 ( V_14 , V_774 ) ;
V_768 |= V_775 ;
F_71 ( V_14 , V_774 , V_768 ) ;
F_71 ( V_14 , V_776 , V_769 ) ;
} else {
F_71 ( V_14 , V_777 , 0 ) ;
F_71 ( V_14 , V_776 , 0 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_109 :
F_429 ( V_9 , false ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_429 ( V_9 , ! ! V_769 ) ;
break;
default:
break;
}
* V_767 = ! ! V_769 ;
F_70 ( V_2 ) ;
if ( ! F_15 ( V_765 , & V_2 -> V_34 ) )
F_438 ( V_9 ) ;
return 0 ;
}
static int F_439 ( struct V_5 * V_9 , T_13 V_34 )
{
int V_771 ;
bool V_778 ;
V_771 = F_434 ( V_9 , & V_778 ) ;
if ( V_771 )
return V_771 ;
if ( V_778 ) {
F_440 ( V_9 ) ;
} else {
F_429 ( V_9 , false ) ;
F_424 ( V_9 , V_779 ) ;
}
return 0 ;
}
static void F_441 ( struct V_5 * V_9 )
{
bool V_778 ;
F_434 ( V_9 , & V_778 ) ;
if ( V_780 == V_781 ) {
F_429 ( V_9 , V_778 ) ;
F_424 ( V_9 , V_779 ) ;
}
}
void F_442 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_122 * V_123 = & V_2 -> V_124 ;
T_6 V_782 = 0 ;
T_1 V_48 , V_783 = 0 , V_784 , V_785 , V_786 , V_787 , V_788 ;
T_6 V_260 = 0 , V_174 = 0 , V_789 = 0 ;
T_6 V_230 = 0 , V_285 = 0 ;
T_6 V_170 = 0 , V_144 = 0 , V_790 = 0 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_676 , & V_2 -> V_34 ) )
return;
if ( V_2 -> V_154 & V_515 ) {
T_6 V_241 = 0 ;
T_6 V_242 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_241 += V_2 -> V_67 [ V_48 ] -> V_219 . V_241 ;
V_242 += V_2 -> V_67 [ V_48 ] -> V_219 . V_242 ;
}
V_2 -> V_791 = V_241 ;
V_2 -> V_792 = V_242 ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_67 = V_2 -> V_67 [ V_48 ] ;
V_260 += V_67 -> V_219 . V_260 ;
V_230 += V_67 -> V_219 . V_230 ;
V_285 += V_67 -> V_219 . V_285 ;
V_790 += V_67 -> V_219 . V_220 ;
V_170 += V_67 -> V_124 . V_170 ;
V_144 += V_67 -> V_124 . V_144 ;
}
V_2 -> V_260 = V_260 ;
V_2 -> V_230 = V_230 ;
V_2 -> V_285 = V_285 ;
V_2 -> V_790 = V_790 ;
V_55 -> V_124 . V_793 = V_170 ;
V_55 -> V_124 . V_794 = V_144 ;
V_170 = 0 ;
V_144 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_58 = V_2 -> V_58 [ V_48 ] ;
V_174 += V_58 -> V_152 . V_174 ;
V_789 += V_58 -> V_152 . V_789 ;
V_170 += V_58 -> V_124 . V_170 ;
V_144 += V_58 -> V_124 . V_144 ;
}
V_2 -> V_174 = V_174 ;
V_2 -> V_789 = V_789 ;
V_55 -> V_124 . V_795 = V_170 ;
V_55 -> V_124 . V_796 = V_144 ;
V_123 -> V_797 += F_37 ( V_14 , V_798 ) ;
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ ) {
V_784 = F_37 ( V_14 , F_443 ( V_48 ) ) ;
V_783 += V_784 ;
V_123 -> V_784 [ V_48 ] += V_784 ;
V_782 += V_123 -> V_784 [ V_48 ] ;
V_123 -> V_799 [ V_48 ] += F_37 ( V_14 , F_444 ( V_48 ) ) ;
V_123 -> V_800 [ V_48 ] += F_37 ( V_14 , F_445 ( V_48 ) ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_123 -> V_801 [ V_48 ] += F_37 ( V_14 , F_446 ( V_48 ) ) ;
V_123 -> V_802 [ V_48 ] += F_37 ( V_14 , F_447 ( V_48 ) ) ;
V_123 -> V_803 [ V_48 ] += F_37 ( V_14 , F_448 ( V_48 ) ) ;
V_123 -> V_804 [ V_48 ] +=
F_37 ( V_14 , F_449 ( V_48 ) ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_123 -> V_804 [ V_48 ] +=
F_37 ( V_14 , F_450 ( V_48 ) ) ;
break;
default:
break;
}
}
for ( V_48 = 0 ; V_48 < 16 ; V_48 ++ ) {
V_123 -> V_805 [ V_48 ] += F_37 ( V_14 , F_451 ( V_48 ) ) ;
V_123 -> V_806 [ V_48 ] += F_37 ( V_14 , F_452 ( V_48 ) ) ;
if ( ( V_14 -> V_108 . type == V_111 ) ||
( V_14 -> V_108 . type == V_112 ) ||
( V_14 -> V_108 . type == V_113 ) ||
( V_14 -> V_108 . type == V_114 ) ) {
V_123 -> V_802 [ V_48 ] += F_37 ( V_14 , F_453 ( V_48 ) ) ;
F_37 ( V_14 , F_454 ( V_48 ) ) ;
V_123 -> V_803 [ V_48 ] += F_37 ( V_14 , F_455 ( V_48 ) ) ;
F_37 ( V_14 , F_456 ( V_48 ) ) ;
}
}
V_123 -> V_807 += F_37 ( V_14 , V_808 ) ;
V_123 -> V_807 -= V_783 ;
F_83 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_123 -> V_809 += F_37 ( V_14 , V_810 ) ;
V_123 -> V_811 += F_37 ( V_14 , V_812 ) ;
V_123 -> V_813 += F_37 ( V_14 , V_814 ) ;
V_123 -> V_815 += F_37 ( V_14 , V_816 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
V_123 -> V_817 += F_37 ( V_14 , V_818 ) ;
V_123 -> V_819 += F_37 ( V_14 , V_820 ) ;
V_123 -> V_821 += F_37 ( V_14 , V_822 ) ;
V_123 -> V_823 += F_37 ( V_14 , V_824 ) ;
case V_111 :
for ( V_48 = 0 ; V_48 < 16 ; V_48 ++ )
V_2 -> V_825 +=
F_37 ( V_14 , F_457 ( V_48 ) ) ;
V_123 -> V_811 += F_37 ( V_14 , V_826 ) ;
F_37 ( V_14 , V_812 ) ;
V_123 -> V_813 += F_37 ( V_14 , V_827 ) ;
F_37 ( V_14 , V_814 ) ;
V_123 -> V_815 += F_37 ( V_14 , V_828 ) ;
F_37 ( V_14 , V_816 ) ;
V_123 -> V_809 += F_37 ( V_14 , V_829 ) ;
V_123 -> V_830 += F_37 ( V_14 , V_831 ) ;
V_123 -> V_832 += F_37 ( V_14 , V_833 ) ;
#ifdef F_176
V_123 -> V_834 += F_37 ( V_14 , V_835 ) ;
V_123 -> V_836 += F_37 ( V_14 , V_837 ) ;
V_123 -> V_838 += F_37 ( V_14 , V_839 ) ;
V_123 -> V_840 += F_37 ( V_14 , V_841 ) ;
V_123 -> V_842 += F_37 ( V_14 , V_843 ) ;
V_123 -> V_844 += F_37 ( V_14 , V_845 ) ;
if ( V_2 -> V_592 . V_846 ) {
struct V_847 * V_592 = & V_2 -> V_592 ;
struct V_848 * V_846 ;
unsigned int V_175 ;
T_6 V_849 = 0 , V_850 = 0 ;
F_458 (cpu) {
V_846 = F_459 ( V_592 -> V_846 , V_175 ) ;
V_849 += V_846 -> V_849 ;
V_850 += V_846 -> V_850 ;
}
V_123 -> V_851 = V_849 ;
V_123 -> V_852 = V_850 ;
}
#endif
break;
default:
break;
}
V_785 = F_37 ( V_14 , V_853 ) ;
V_123 -> V_785 += V_785 ;
V_123 -> V_854 += F_37 ( V_14 , V_855 ) ;
if ( V_14 -> V_108 . type == V_109 )
V_123 -> V_854 -= V_785 ;
V_123 -> V_856 += F_37 ( V_14 , V_857 ) ;
V_123 -> V_858 += F_37 ( V_14 , V_859 ) ;
V_123 -> V_860 += F_37 ( V_14 , V_861 ) ;
V_123 -> V_862 += F_37 ( V_14 , V_863 ) ;
V_123 -> V_864 += F_37 ( V_14 , V_865 ) ;
V_123 -> V_866 += F_37 ( V_14 , V_867 ) ;
V_123 -> V_868 += F_37 ( V_14 , V_869 ) ;
V_123 -> V_870 += F_37 ( V_14 , V_871 ) ;
V_786 = F_37 ( V_14 , V_872 ) ;
V_123 -> V_873 += V_786 ;
V_787 = F_37 ( V_14 , V_874 ) ;
V_123 -> V_875 += V_787 ;
V_123 -> V_876 += F_37 ( V_14 , V_877 ) ;
V_123 -> V_878 += F_37 ( V_14 , V_879 ) ;
V_788 = V_786 + V_787 ;
V_123 -> V_876 -= V_788 ;
V_123 -> V_878 -= V_788 ;
V_123 -> V_813 -= ( V_788 * ( V_880 + V_504 ) ) ;
V_123 -> V_881 += F_37 ( V_14 , V_882 ) ;
V_123 -> V_883 += F_37 ( V_14 , V_884 ) ;
V_123 -> V_885 += F_37 ( V_14 , V_886 ) ;
V_123 -> V_887 += F_37 ( V_14 , V_888 ) ;
V_123 -> V_889 += F_37 ( V_14 , V_890 ) ;
V_123 -> V_889 -= V_788 ;
V_123 -> V_891 += F_37 ( V_14 , V_892 ) ;
V_123 -> V_893 += F_37 ( V_14 , V_894 ) ;
V_123 -> V_895 += F_37 ( V_14 , V_896 ) ;
V_123 -> V_897 += F_37 ( V_14 , V_898 ) ;
V_123 -> V_899 += F_37 ( V_14 , V_900 ) ;
V_123 -> V_901 += F_37 ( V_14 , V_902 ) ;
V_55 -> V_124 . V_903 = V_123 -> V_854 ;
V_55 -> V_124 . V_904 = V_123 -> V_797 + V_123 -> V_870 ;
V_55 -> V_124 . V_905 = 0 ;
V_55 -> V_124 . V_906 = V_123 -> V_870 ;
V_55 -> V_124 . V_907 = V_123 -> V_797 ;
V_55 -> V_124 . V_908 = V_782 ;
}
static void F_460 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
if ( ! ( V_2 -> V_154 & V_364 ) )
return;
V_2 -> V_154 &= ~ V_364 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
if ( ! ( V_2 -> V_139 & V_363 ) )
return;
V_2 -> V_909 ++ ;
if ( F_461 ( V_14 ) == 0 ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_243 ( V_372 ,
& ( V_2 -> V_58 [ V_48 ] -> V_34 ) ) ;
F_71 ( V_14 , V_355 , V_365 ) ;
} else {
F_103 ( V_172 , L_112
L_113 ) ;
}
}
static void F_462 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_910 = 0 ;
int V_48 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_676 , & V_2 -> V_34 ) )
return;
if ( F_109 ( V_2 -> V_55 ) ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_463 ( V_2 -> V_58 [ V_48 ] ) ;
}
if ( ! ( V_2 -> V_139 & V_387 ) ) {
F_71 ( V_14 , V_119 ,
( V_911 | V_912 ) ) ;
} else {
for ( V_48 = 0 ; V_48 < V_2 -> V_189 ; V_48 ++ ) {
struct V_157 * V_913 = V_2 -> V_158 [ V_48 ] ;
if ( V_913 -> V_296 . V_120 || V_913 -> V_162 . V_120 )
V_910 |= ( ( T_6 ) 1 << V_48 ) ;
}
}
F_75 ( V_2 , V_910 ) ;
}
static void F_464 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_914 = V_2 -> V_914 ;
bool V_339 = V_2 -> V_339 ;
bool V_135 = V_2 -> V_136 . V_137 ;
if ( ! ( V_2 -> V_139 & V_351 ) )
return;
if ( V_14 -> V_108 . V_337 . V_338 ) {
V_14 -> V_108 . V_337 . V_338 ( V_14 , & V_914 , & V_339 , false ) ;
} else {
V_914 = V_915 ;
V_339 = true ;
}
if ( V_2 -> V_138 )
V_135 |= ! ! ( V_2 -> V_138 -> V_135 ) ;
if ( V_339 && ! ( ( V_2 -> V_139 & V_140 ) && V_135 ) ) {
V_14 -> V_108 . V_337 . V_916 ( V_14 ) ;
F_465 ( V_2 ) ;
}
if ( V_339 ||
F_466 ( V_171 , ( V_2 -> V_352 +
V_917 ) ) ) {
V_2 -> V_139 &= ~ V_351 ;
F_71 ( V_14 , V_355 , V_354 ) ;
F_212 ( V_14 ) ;
}
V_2 -> V_339 = V_339 ;
V_2 -> V_914 = V_914 ;
}
static void F_467 ( struct V_1 * V_2 )
{
#ifdef F_355
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_918 V_919 = {
. V_920 = V_921 ,
. V_249 = 0 ,
} ;
T_4 V_593 = 0 ;
if ( V_2 -> V_578 & V_922 )
V_593 = F_468 ( V_55 , & V_919 ) ;
V_2 -> V_923 = ( V_593 > 1 ) ? ( F_469 ( V_593 ) - 1 ) : 0 ;
#endif
}
static void F_470 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_95 ;
struct V_627 * V_628 ;
T_1 V_914 = V_2 -> V_914 ;
bool V_924 , V_925 ;
if ( F_109 ( V_55 ) )
return;
V_2 -> V_154 &= ~ V_648 ;
switch ( V_14 -> V_108 . type ) {
case V_109 : {
T_1 V_926 = F_37 ( V_14 , V_559 ) ;
T_1 V_927 = F_37 ( V_14 , V_928 ) ;
V_924 = ! ! ( V_926 & V_929 ) ;
V_925 = ! ! ( V_927 & V_930 ) ;
}
break;
case V_112 :
case V_113 :
case V_114 :
case V_111 : {
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
V_2 -> V_937 = V_171 ;
if ( F_14 ( V_687 , & V_2 -> V_34 ) )
F_471 ( V_2 ) ;
F_105 ( V_156 , L_114 ,
( V_914 == V_915 ?
L_115 :
( V_914 == V_938 ?
L_116 :
( V_914 == V_939 ?
L_117 :
L_118 ) ) ) ,
( ( V_924 && V_925 ) ? L_119 :
( V_924 ? L_120 :
( V_925 ? L_121 : L_122 ) ) ) ) ;
F_472 ( V_55 ) ;
F_473 ( V_2 ) ;
F_474 ( V_2 -> V_55 ) ;
F_430 () ;
F_352 (adapter->netdev, upper, iter) {
if ( F_353 ( V_95 ) ) {
struct V_629 * V_247 = F_89 ( V_95 ) ;
if ( V_247 -> V_631 )
F_474 ( V_95 ) ;
}
}
F_432 () ;
F_467 ( V_2 ) ;
F_383 ( V_2 ) ;
}
static void F_475 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_339 = false ;
V_2 -> V_914 = 0 ;
if ( ! F_109 ( V_55 ) )
return;
if ( F_359 ( V_14 ) && V_14 -> V_108 . type == V_109 )
V_2 -> V_154 |= V_648 ;
if ( F_14 ( V_687 , & V_2 -> V_34 ) )
F_471 ( V_2 ) ;
F_105 ( V_156 , L_123 ) ;
F_380 ( V_55 ) ;
F_383 ( V_2 ) ;
}
static bool F_476 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_58 = V_2 -> V_58 [ V_48 ] ;
if ( V_58 -> V_80 != V_58 -> V_79 )
return true ;
}
return false ;
}
static bool F_477 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_940 * V_941 = & V_2 -> V_412 [ V_487 ] ;
T_1 V_942 = F_478 ( 1 , ~ V_941 -> V_117 ) ;
int V_48 , V_49 ;
if ( ! V_2 -> V_304 )
return false ;
if ( V_14 -> V_108 . type >= V_113 )
return false ;
for ( V_48 = 0 ; V_48 < V_2 -> V_304 ; V_48 ++ ) {
for ( V_49 = 0 ; V_49 < V_942 ; V_49 ++ ) {
T_1 V_943 , V_944 ;
V_943 = F_37 ( V_14 , F_479 ( V_942 , V_48 , V_49 ) ) ;
V_944 = F_37 ( V_14 , F_480 ( V_942 , V_48 , V_49 ) ) ;
if ( V_943 != V_944 )
return true ;
}
}
return false ;
}
static void F_481 ( struct V_1 * V_2 )
{
if ( ! F_109 ( V_2 -> V_55 ) ) {
if ( F_476 ( V_2 ) ||
F_477 ( V_2 ) ) {
F_93 ( V_156 , L_124 ) ;
V_2 -> V_154 |= V_155 ;
}
}
}
static inline void F_482 ( struct V_1 * V_2 ,
struct V_5 * V_945 )
{
if ( ! F_483 ( V_945 ) )
F_11 ( L_125 ) ;
F_18 ( L_126 , F_484 ( V_945 ) ) ;
F_485 ( V_945 , V_946 , V_947 ) ;
F_370 ( 100 ) ;
}
static void F_486 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
struct V_5 * V_945 ;
T_1 V_948 ;
int V_949 ;
unsigned short V_950 ;
if ( ! ( F_109 ( V_2 -> V_55 ) ) )
return;
V_948 = F_37 ( V_14 , V_951 ) ;
if ( V_948 )
return;
if ( ! V_9 )
return;
V_949 = F_487 ( V_9 , V_952 ) ;
if ( ! V_949 )
return;
F_25 ( V_9 , V_949 + V_953 , & V_950 ) ;
V_945 = F_488 ( V_9 -> V_697 , V_950 , NULL ) ;
while ( V_945 ) {
if ( V_945 -> V_954 && ( V_945 -> V_955 == V_9 ) ) {
T_2 V_956 ;
F_25 ( V_945 , V_957 , & V_956 ) ;
if ( V_956 & V_958 )
F_482 ( V_2 , V_945 ) ;
}
V_945 = F_488 ( V_9 -> V_697 , V_950 , V_945 ) ;
}
}
static void F_489 ( struct V_1 * V_2 )
{
T_1 V_959 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ||
V_2 -> V_304 == 0 )
return;
V_959 = F_37 ( & V_2 -> V_14 , V_960 ) ;
if ( ! V_959 )
return;
F_93 ( V_156 , L_127 , V_959 ) ;
}
static void F_489 ( struct V_1 T_14 * V_2 )
{
}
static void
F_486 ( struct V_1 T_14 * V_2 )
{
}
static void F_490 ( struct V_1 * V_2 )
{
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_676 , & V_2 -> V_34 ) )
return;
F_464 ( V_2 ) ;
if ( V_2 -> V_339 )
F_470 ( V_2 ) ;
else
F_475 ( V_2 ) ;
F_486 ( V_2 ) ;
F_489 ( V_2 ) ;
F_442 ( V_2 ) ;
F_481 ( V_2 ) ;
}
static void F_491 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_3 V_17 ;
if ( ! ( V_2 -> V_154 & V_648 ) &&
! ( V_2 -> V_154 & V_348 ) )
return;
if ( F_15 ( V_678 , & V_2 -> V_34 ) )
return;
V_17 = V_14 -> V_340 . V_337 . V_961 ( V_14 ) ;
if ( V_17 == V_681 )
goto V_962;
if ( V_17 == V_680 ) {
V_2 -> V_154 |= V_348 ;
}
if ( V_17 )
goto V_962;
if ( ! ( V_2 -> V_154 & V_348 ) )
goto V_962;
V_2 -> V_154 &= ~ V_348 ;
if ( V_14 -> V_108 . type == V_109 )
V_17 = V_14 -> V_340 . V_337 . V_963 ( V_14 ) ;
else
V_17 = V_14 -> V_108 . V_337 . V_964 ( V_14 ) ;
if ( V_17 == V_681 )
goto V_962;
V_2 -> V_139 |= V_349 ;
F_105 ( V_172 , L_128 , V_14 -> V_340 . V_965 ) ;
V_962:
F_34 ( V_678 , & V_2 -> V_34 ) ;
if ( ( V_17 == V_681 ) &&
( V_2 -> V_55 -> V_966 == V_967 ) ) {
F_18 ( L_129
L_130 ) ;
F_18 ( L_131
L_132 ) ;
F_492 ( V_2 -> V_55 ) ;
}
}
static void F_493 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_20 ;
bool V_649 = false ;
if ( ! ( V_2 -> V_139 & V_349 ) )
return;
if ( F_15 ( V_678 , & V_2 -> V_34 ) )
return;
V_2 -> V_139 &= ~ V_349 ;
V_20 = V_14 -> V_340 . V_652 ;
if ( ( ! V_20 ) && ( V_14 -> V_108 . V_337 . V_653 ) ) {
V_14 -> V_108 . V_337 . V_653 ( V_14 , & V_20 , & V_649 ) ;
if ( ! V_649 ) {
if ( V_20 & V_915 )
V_20 = V_915 ;
}
}
if ( V_14 -> V_108 . V_337 . V_654 )
V_14 -> V_108 . V_337 . V_654 ( V_14 , V_20 , true ) ;
V_2 -> V_139 |= V_351 ;
V_2 -> V_352 = V_171 ;
F_34 ( V_678 , & V_2 -> V_34 ) ;
}
static void F_494 ( unsigned long V_92 )
{
struct V_1 * V_2 = (struct V_1 * ) V_92 ;
unsigned long V_968 ;
if ( V_2 -> V_139 & V_351 )
V_968 = V_969 / 10 ;
else
V_968 = V_969 * 2 ;
F_365 ( & V_2 -> V_674 , V_968 + V_171 ) ;
F_13 ( V_2 ) ;
}
static void F_495 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_154 & V_155 ) )
return;
V_2 -> V_154 &= ~ V_155 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_676 , & V_2 -> V_34 ) )
return;
F_54 ( V_2 ) ;
F_496 ( V_2 -> V_55 , L_133 ) ;
V_2 -> V_173 ++ ;
F_430 () ;
F_366 ( V_2 ) ;
F_432 () ;
}
static void F_497 ( struct V_970 * V_971 )
{
struct V_1 * V_2 = F_196 ( V_971 ,
struct V_1 ,
V_37 ) ;
if ( F_22 ( V_2 -> V_14 . V_39 ) ) {
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
F_430 () ;
F_369 ( V_2 ) ;
F_432 () ;
}
F_31 ( V_2 ) ;
return;
}
F_495 ( V_2 ) ;
F_491 ( V_2 ) ;
F_493 ( V_2 ) ;
F_206 ( V_2 ) ;
F_490 ( V_2 ) ;
F_460 ( V_2 ) ;
F_462 ( V_2 ) ;
if ( F_14 ( V_687 , & V_2 -> V_34 ) ) {
F_498 ( V_2 ) ;
F_499 ( V_2 ) ;
}
F_31 ( V_2 ) ;
}
static int F_500 ( struct V_57 * V_58 ,
struct V_59 * V_972 ,
T_4 * V_236 )
{
struct V_195 * V_89 = V_972 -> V_89 ;
T_1 V_973 , V_974 ;
T_1 V_975 , V_976 ;
int V_17 ;
if ( V_89 -> V_215 != V_977 )
return 0 ;
if ( ! F_501 ( V_89 ) )
return 0 ;
V_17 = F_502 ( V_89 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_974 = V_978 ;
if ( V_972 -> V_249 == F_156 ( V_979 ) ) {
struct V_980 * V_981 = F_503 ( V_89 ) ;
V_981 -> V_982 = 0 ;
V_981 -> V_983 = 0 ;
F_504 ( V_89 ) -> V_983 = ~ F_505 ( V_981 -> V_984 ,
V_981 -> V_985 , 0 ,
V_986 ,
0 ) ;
V_974 |= V_987 ;
V_972 -> V_988 |= V_989 |
V_990 |
V_991 ;
} else if ( F_506 ( V_89 ) ) {
F_507 ( V_89 ) -> V_992 = 0 ;
F_504 ( V_89 ) -> V_983 =
~ F_508 ( & F_507 ( V_89 ) -> V_984 ,
& F_507 ( V_89 ) -> V_985 ,
0 , V_986 , 0 ) ;
V_972 -> V_988 |= V_989 |
V_990 ;
}
V_976 = F_509 ( V_89 ) ;
* V_236 = F_510 ( V_89 ) + V_976 ;
V_972 -> V_168 = F_148 ( V_89 ) -> V_168 ;
V_972 -> V_167 += ( V_972 -> V_168 - 1 ) * * V_236 ;
V_975 = V_976 << V_993 ;
V_975 |= F_148 ( V_89 ) -> V_237 << V_994 ;
V_973 = F_511 ( V_89 ) ;
V_973 |= F_512 ( V_89 ) << V_995 ;
V_973 |= V_972 -> V_988 & V_996 ;
F_513 ( V_58 , V_973 , 0 , V_974 ,
V_975 ) ;
return 1 ;
}
static void F_514 ( struct V_57 * V_58 ,
struct V_59 * V_972 )
{
struct V_195 * V_89 = V_972 -> V_89 ;
T_1 V_973 = 0 ;
T_1 V_975 = 0 ;
T_1 V_974 = 0 ;
if ( V_89 -> V_215 != V_977 ) {
if ( ! ( V_972 -> V_988 & V_997 ) &&
! ( V_972 -> V_988 & V_998 ) )
return;
} else {
T_4 V_999 = 0 ;
switch ( V_972 -> V_249 ) {
case F_156 ( V_979 ) :
V_973 |= F_511 ( V_89 ) ;
V_974 |= V_987 ;
V_999 = F_503 ( V_89 ) -> V_249 ;
break;
case F_156 ( V_1000 ) :
V_973 |= F_511 ( V_89 ) ;
V_999 = F_507 ( V_89 ) -> V_1001 ;
break;
default:
if ( F_24 ( F_515 () ) ) {
F_516 ( V_58 -> V_73 ,
L_134 ,
V_972 -> V_249 ) ;
}
break;
}
switch ( V_999 ) {
case V_986 :
V_974 |= V_978 ;
V_975 = F_509 ( V_89 ) <<
V_993 ;
break;
case V_1002 :
V_974 |= V_1003 ;
V_975 = sizeof( struct V_1004 ) <<
V_993 ;
break;
case V_1005 :
V_975 = sizeof( struct V_1006 ) <<
V_993 ;
break;
default:
if ( F_24 ( F_515 () ) ) {
F_516 ( V_58 -> V_73 ,
L_135 ,
V_999 ) ;
}
break;
}
V_972 -> V_988 |= V_990 ;
}
V_973 |= F_512 ( V_89 ) << V_995 ;
V_973 |= V_972 -> V_988 & V_996 ;
F_513 ( V_58 , V_973 , 0 ,
V_974 , V_975 ) ;
}
static T_1 F_517 ( struct V_195 * V_89 , T_1 V_988 )
{
T_1 V_1007 = V_1008 |
V_1009 |
V_1010 ;
V_1007 |= F_518 ( V_988 , V_997 ,
V_1011 ) ;
V_1007 |= F_518 ( V_988 , V_989 ,
V_1012 ) ;
V_1007 |= F_518 ( V_988 , V_1013 ,
V_1014 ) ;
V_1007 ^= F_518 ( V_89 -> V_1015 , 1 , V_1010 ) ;
return V_1007 ;
}
static void F_519 ( union V_61 * V_62 ,
T_1 V_988 , unsigned int V_1016 )
{
T_1 V_1017 = V_1016 << V_1018 ;
V_1017 |= F_518 ( V_988 ,
V_990 ,
V_1019 ) ;
V_1017 |= F_518 ( V_988 ,
V_991 ,
V_1020 ) ;
V_1017 |= F_518 ( V_988 ,
V_998 ,
V_1021 ) ;
V_62 -> V_233 . V_1017 = F_96 ( V_1017 ) ;
}
static int F_520 ( struct V_57 * V_58 , T_2 V_276 )
{
F_104 ( V_58 -> V_55 , V_58 -> V_86 ) ;
F_111 () ;
if ( F_99 ( F_110 ( V_58 ) < V_276 ) )
return - V_759 ;
F_521 ( V_58 -> V_55 , V_58 -> V_86 ) ;
++ V_58 -> V_152 . V_174 ;
return 0 ;
}
static inline int F_522 ( struct V_57 * V_58 , T_2 V_276 )
{
if ( F_99 ( F_110 ( V_58 ) >= V_276 ) )
return 0 ;
return F_520 ( V_58 , V_276 ) ;
}
static void F_523 ( struct V_57 * V_58 ,
struct V_59 * V_972 ,
const T_4 V_236 )
{
struct V_195 * V_89 = V_972 -> V_89 ;
struct V_59 * V_60 ;
union V_61 * V_62 ;
struct V_261 * V_262 ;
T_9 V_81 ;
unsigned int V_267 , V_276 ;
T_1 V_988 = V_972 -> V_988 ;
T_1 V_1007 = F_517 ( V_89 , V_988 ) ;
T_2 V_48 = V_58 -> V_80 ;
V_62 = F_61 ( V_58 , V_48 ) ;
F_519 ( V_62 , V_988 , V_89 -> V_82 - V_236 ) ;
V_276 = F_147 ( V_89 ) ;
V_267 = V_89 -> V_267 ;
#ifdef F_176
if ( V_988 & V_1022 ) {
if ( V_267 < sizeof( struct V_295 ) ) {
V_276 -= sizeof( struct V_295 ) - V_267 ;
V_267 = 0 ;
} else {
V_267 -= sizeof( struct V_295 ) ;
}
}
#endif
V_81 = F_524 ( V_58 -> V_73 , V_89 -> V_92 , V_276 , V_121 ) ;
V_60 = V_972 ;
for ( V_262 = & F_148 ( V_89 ) -> V_263 [ 0 ] ; ; V_262 ++ ) {
if ( F_140 ( V_58 -> V_73 , V_81 ) )
goto V_1023;
F_81 ( V_60 , V_82 , V_276 ) ;
F_525 ( V_60 , V_81 , V_81 ) ;
V_62 -> V_233 . V_1024 = F_143 ( V_81 ) ;
while ( F_24 ( V_276 > V_1025 ) ) {
V_62 -> V_233 . V_1026 =
F_96 ( V_1007 ^ V_1025 ) ;
V_48 ++ ;
V_62 ++ ;
if ( V_48 == V_58 -> V_88 ) {
V_62 = F_61 ( V_58 , 0 ) ;
V_48 = 0 ;
}
V_62 -> V_233 . V_1017 = 0 ;
V_81 += V_1025 ;
V_276 -= V_1025 ;
V_62 -> V_233 . V_1024 = F_143 ( V_81 ) ;
}
if ( F_99 ( ! V_267 ) )
break;
V_62 -> V_233 . V_1026 = F_96 ( V_1007 ^ V_276 ) ;
V_48 ++ ;
V_62 ++ ;
if ( V_48 == V_58 -> V_88 ) {
V_62 = F_61 ( V_58 , 0 ) ;
V_48 = 0 ;
}
V_62 -> V_233 . V_1017 = 0 ;
#ifdef F_176
V_276 = F_347 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_276 = F_526 ( V_262 ) ;
#endif
V_267 -= V_276 ;
V_81 = F_527 ( V_58 -> V_73 , V_262 , 0 , V_276 ,
V_121 ) ;
V_60 = & V_58 -> V_78 [ V_48 ] ;
}
V_1007 |= V_276 | V_1027 ;
V_62 -> V_233 . V_1026 = F_96 ( V_1007 ) ;
F_528 ( F_107 ( V_58 ) , V_972 -> V_167 ) ;
V_972 -> V_84 = V_171 ;
F_144 () ;
V_972 -> V_83 = V_62 ;
V_48 ++ ;
if ( V_48 == V_58 -> V_88 )
V_48 = 0 ;
V_58 -> V_80 = V_48 ;
F_522 ( V_58 , V_1028 ) ;
if ( F_529 ( F_107 ( V_58 ) ) || ! V_89 -> V_1029 ) {
F_145 ( V_48 , V_58 -> V_146 ) ;
F_530 () ;
}
return;
V_1023:
F_402 ( V_58 -> V_73 , L_136 ) ;
for (; ; ) {
V_60 = & V_58 -> V_78 [ V_48 ] ;
F_77 ( V_58 , V_60 ) ;
if ( V_60 == V_972 )
break;
if ( V_48 == 0 )
V_48 = V_58 -> V_88 ;
V_48 -- ;
}
V_58 -> V_80 = V_48 ;
}
static void F_531 ( struct V_57 * V_120 ,
struct V_59 * V_972 )
{
struct V_157 * V_158 = V_120 -> V_158 ;
union V_1030 V_1031 = { . V_1032 = 0 } ;
union V_1030 V_1033 = { . V_1032 = 0 } ;
union {
unsigned char * V_1034 ;
struct V_980 * V_1035 ;
struct V_1036 * V_1037 ;
} V_1038 ;
struct V_1039 * V_1040 ;
T_12 V_1041 ;
if ( ! V_158 )
return;
if ( ! V_120 -> V_397 )
return;
V_120 -> V_398 ++ ;
V_1038 . V_1034 = F_532 ( V_972 -> V_89 ) ;
if ( ( V_972 -> V_249 != F_156 ( V_1000 ) ||
V_1038 . V_1037 -> V_1001 != V_986 ) &&
( V_972 -> V_249 != F_156 ( V_979 ) ||
V_1038 . V_1035 -> V_249 != V_986 ) )
return;
V_1040 = F_504 ( V_972 -> V_89 ) ;
if ( ! V_1040 || V_1040 -> V_1042 )
return;
if ( ! V_1040 -> V_1043 && ( V_120 -> V_398 < V_120 -> V_397 ) )
return;
V_120 -> V_398 = 0 ;
V_1041 = F_156 ( V_972 -> V_988 >> V_1044 ) ;
V_1031 . V_1045 . V_1041 = V_1041 ;
if ( V_972 -> V_988 & ( V_1046 | V_997 ) )
V_1033 . V_1047 . V_1048 ^= V_1040 -> V_1049 ^ F_156 ( V_248 ) ;
else
V_1033 . V_1047 . V_1048 ^= V_1040 -> V_1049 ^ V_972 -> V_249 ;
V_1033 . V_1047 . V_1050 ^= V_1040 -> V_1051 ;
if ( V_972 -> V_249 == F_156 ( V_979 ) ) {
V_1031 . V_1045 . V_1052 = V_1053 ;
V_1033 . V_1054 ^= V_1038 . V_1035 -> V_984 ^ V_1038 . V_1035 -> V_985 ;
} else {
V_1031 . V_1045 . V_1052 = V_1055 ;
V_1033 . V_1054 ^= V_1038 . V_1037 -> V_984 . V_1056 [ 0 ] ^
V_1038 . V_1037 -> V_984 . V_1056 [ 1 ] ^
V_1038 . V_1037 -> V_984 . V_1056 [ 2 ] ^
V_1038 . V_1037 -> V_984 . V_1056 [ 3 ] ^
V_1038 . V_1037 -> V_985 . V_1056 [ 0 ] ^
V_1038 . V_1037 -> V_985 . V_1056 [ 1 ] ^
V_1038 . V_1037 -> V_985 . V_1056 [ 2 ] ^
V_1038 . V_1037 -> V_985 . V_1056 [ 3 ] ;
}
F_533 ( & V_158 -> V_2 -> V_14 ,
V_1031 , V_1033 , V_120 -> V_86 ) ;
}
static T_2 F_534 ( struct V_54 * V_73 , struct V_195 * V_89 ,
void * V_1057 , T_15 V_1058 )
{
struct V_613 * V_1059 = V_1057 ;
#ifdef F_176
struct V_1 * V_2 ;
struct V_940 * V_1060 ;
int V_1061 ;
#endif
if ( V_1059 )
return V_89 -> V_1062 + V_1059 -> V_621 ;
#ifdef F_176
switch ( F_535 ( V_89 ) ) {
case F_156 ( V_1063 ) :
case F_156 ( V_1064 ) :
V_2 = F_89 ( V_73 ) ;
if ( V_2 -> V_139 & V_507 )
break;
default:
return V_1058 ( V_73 , V_89 ) ;
}
V_1060 = & V_2 -> V_412 [ V_1065 ] ;
V_1061 = F_536 ( V_89 ) ? F_537 ( V_89 ) :
F_538 () ;
while ( V_1061 >= V_1060 -> V_414 )
V_1061 -= V_1060 -> V_414 ;
return V_1061 + V_1060 -> V_1066 ;
#else
return V_1058 ( V_73 , V_89 ) ;
#endif
}
T_16 F_539 ( struct V_195 * V_89 ,
struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_59 * V_972 ;
int V_1067 ;
T_1 V_988 = 0 ;
unsigned short V_1060 ;
T_2 V_88 = F_540 ( F_147 ( V_89 ) ) ;
T_12 V_249 = V_89 -> V_249 ;
T_4 V_236 = 0 ;
for ( V_1060 = 0 ; V_1060 < F_148 ( V_89 ) -> V_282 ; V_1060 ++ )
V_88 += F_540 ( F_148 ( V_89 ) -> V_263 [ V_1060 ] . V_276 ) ;
if ( F_522 ( V_58 , V_88 + 3 ) ) {
V_58 -> V_152 . V_789 ++ ;
return V_1068 ;
}
V_972 = & V_58 -> V_78 [ V_58 -> V_80 ] ;
V_972 -> V_89 = V_89 ;
V_972 -> V_167 = V_89 -> V_82 ;
V_972 -> V_168 = 1 ;
if ( F_541 ( V_89 ) ) {
V_988 |= F_542 ( V_89 ) << V_1044 ;
V_988 |= V_997 ;
} else if ( V_249 == F_156 ( V_248 ) ) {
struct V_1069 * V_1070 , V_1071 ;
V_1070 = F_543 ( V_89 , V_503 , sizeof( V_1071 ) , & V_1071 ) ;
if ( ! V_1070 )
goto V_1072;
V_988 |= F_544 ( V_1070 -> V_1073 ) <<
V_1044 ;
V_988 |= V_1046 ;
}
V_249 = F_535 ( V_89 ) ;
if ( F_24 ( F_148 ( V_89 ) -> V_988 & V_1074 ) &&
V_2 -> V_1075 &&
! F_545 ( V_1076 ,
& V_2 -> V_34 ) ) {
F_148 ( V_89 ) -> V_988 |= V_1077 ;
V_988 |= V_1013 ;
V_2 -> V_1078 = F_546 ( V_89 ) ;
V_2 -> V_1079 = V_171 ;
F_16 ( & V_2 -> V_1080 ) ;
}
F_547 ( V_89 ) ;
#ifdef F_288
if ( V_2 -> V_139 & V_407 )
V_988 |= V_998 ;
#endif
if ( ( V_2 -> V_139 & V_140 ) &&
( ( V_988 & ( V_997 | V_1046 ) ) ||
( V_89 -> V_1081 != V_1082 ) ) ) {
V_988 &= ~ V_1083 ;
V_988 |= ( V_89 -> V_1081 & 0x7 ) <<
V_1084 ;
if ( V_988 & V_1046 ) {
struct V_1085 * V_1070 ;
if ( F_502 ( V_89 , 0 ) )
goto V_1072;
V_1070 = (struct V_1085 * ) V_89 -> V_92 ;
V_1070 -> V_1073 = F_156 ( V_988 >>
V_1044 ) ;
} else {
V_988 |= V_997 ;
}
}
V_972 -> V_988 = V_988 ;
V_972 -> V_249 = V_249 ;
#ifdef F_176
if ( ( V_249 == F_156 ( V_1063 ) ) &&
( V_58 -> V_55 -> V_196 & ( V_1086 | V_1087 ) ) ) {
V_1067 = F_548 ( V_58 , V_972 , & V_236 ) ;
if ( V_1067 < 0 )
goto V_1072;
goto V_1088;
}
#endif
V_1067 = F_500 ( V_58 , V_972 , & V_236 ) ;
if ( V_1067 < 0 )
goto V_1072;
else if ( ! V_1067 )
F_514 ( V_58 , V_972 ) ;
if ( F_14 ( V_372 , & V_58 -> V_34 ) )
F_531 ( V_58 , V_972 ) ;
#ifdef F_176
V_1088:
#endif
F_523 ( V_58 , V_972 , V_236 ) ;
return V_1089 ;
V_1072:
F_78 ( V_972 -> V_89 ) ;
V_972 -> V_89 = NULL ;
return V_1089 ;
}
static T_16 F_549 ( struct V_195 * V_89 ,
struct V_54 * V_55 ,
struct V_57 * V_120 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_57 * V_58 ;
if ( F_550 ( V_89 , 17 ) )
return V_1089 ;
V_58 = V_120 ? V_120 : V_2 -> V_58 [ V_89 -> V_1062 ] ;
return F_539 ( V_89 , V_2 , V_58 ) ;
}
static T_16 F_551 ( struct V_195 * V_89 ,
struct V_54 * V_55 )
{
return F_549 ( V_89 , V_55 , NULL ) ;
}
static int F_552 ( struct V_54 * V_55 , void * V_1090 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1091 * V_545 = V_1090 ;
int V_650 ;
if ( ! F_350 ( V_545 -> V_1092 ) )
return - V_1093 ;
F_299 ( V_2 , V_14 -> V_108 . V_545 , F_271 ( 0 ) ) ;
memcpy ( V_55 -> V_626 , V_545 -> V_1092 , V_55 -> V_684 ) ;
memcpy ( V_14 -> V_108 . V_545 , V_545 -> V_1092 , V_55 -> V_684 ) ;
V_650 = F_296 ( V_2 , V_14 -> V_108 . V_545 , F_271 ( 0 ) ) ;
return V_650 > 0 ? 0 : V_650 ;
}
static int
F_553 ( struct V_54 * V_55 , int V_1094 , int V_1095 , T_2 V_545 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_4 ;
int V_1096 ;
if ( V_1094 != V_14 -> V_340 . V_1097 . V_1094 )
return - V_551 ;
V_1096 = V_14 -> V_340 . V_337 . V_1098 ( V_14 , V_545 , V_1095 , & V_4 ) ;
if ( ! V_1096 )
V_1096 = V_4 ;
return V_1096 ;
}
static int F_554 ( struct V_54 * V_55 , int V_1094 , int V_1095 ,
T_2 V_545 , T_2 V_4 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_1094 != V_14 -> V_340 . V_1097 . V_1094 )
return - V_551 ;
return V_14 -> V_340 . V_337 . V_1099 ( V_14 , V_545 , V_1095 , V_4 ) ;
}
static int F_555 ( struct V_54 * V_55 , struct V_1100 * V_1101 , int V_1102 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
switch ( V_1102 ) {
case V_1103 :
return F_556 ( V_2 , V_1101 ) ;
case V_1104 :
return F_557 ( V_2 , V_1101 ) ;
default:
return F_558 ( & V_2 -> V_14 . V_340 . V_1097 , F_559 ( V_1101 ) , V_1102 ) ;
}
}
static int F_560 ( struct V_54 * V_73 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_350 ( V_14 -> V_108 . V_1105 ) ) {
F_430 () ;
V_17 = F_561 ( V_73 , V_14 -> V_108 . V_1105 , V_1106 ) ;
F_432 () ;
V_14 -> V_108 . V_337 . V_686 ( V_14 , F_271 ( 0 ) ) ;
}
return V_17 ;
}
static int F_562 ( struct V_54 * V_73 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_1107 * V_108 = & V_2 -> V_14 . V_108 ;
if ( F_350 ( V_108 -> V_1105 ) ) {
F_430 () ;
V_17 = F_563 ( V_73 , V_108 -> V_1105 , V_1106 ) ;
F_432 () ;
}
return V_17 ;
}
static void F_564 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_48 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
V_2 -> V_139 |= V_250 ;
if ( V_2 -> V_139 & V_387 ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_189 ; V_48 ++ )
F_222 ( 0 , V_2 -> V_158 [ V_48 ] ) ;
} else {
F_235 ( V_2 -> V_9 -> V_366 , V_55 ) ;
}
V_2 -> V_139 &= ~ V_250 ;
}
static struct V_1108 * F_565 ( struct V_54 * V_55 ,
struct V_1108 * V_124 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_48 ;
F_566 () ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_120 = F_21 ( V_2 -> V_67 [ V_48 ] ) ;
T_6 V_170 , V_144 ;
unsigned int V_1109 ;
if ( V_120 ) {
do {
V_1109 = F_567 ( & V_120 -> V_169 ) ;
V_144 = V_120 -> V_124 . V_144 ;
V_170 = V_120 -> V_124 . V_170 ;
} while ( F_568 ( & V_120 -> V_169 , V_1109 ) );
V_124 -> V_794 += V_144 ;
V_124 -> V_793 += V_170 ;
}
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_120 = F_21 ( V_2 -> V_58 [ V_48 ] ) ;
T_6 V_170 , V_144 ;
unsigned int V_1109 ;
if ( V_120 ) {
do {
V_1109 = F_567 ( & V_120 -> V_169 ) ;
V_144 = V_120 -> V_124 . V_144 ;
V_170 = V_120 -> V_124 . V_170 ;
} while ( F_568 ( & V_120 -> V_169 , V_1109 ) );
V_124 -> V_796 += V_144 ;
V_124 -> V_795 += V_170 ;
}
}
F_569 () ;
V_124 -> V_903 = V_55 -> V_124 . V_903 ;
V_124 -> V_904 = V_55 -> V_124 . V_904 ;
V_124 -> V_906 = V_55 -> V_124 . V_906 ;
V_124 -> V_907 = V_55 -> V_124 . V_907 ;
V_124 -> V_908 = V_55 -> V_124 . V_908 ;
return V_124 ;
}
static void F_570 ( struct V_1 * V_2 , T_4 V_134 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_3 , V_1110 ;
int V_48 ;
if ( V_14 -> V_108 . type == V_109 )
return;
V_3 = F_37 ( V_14 , V_1111 ) ;
V_1110 = V_3 ;
for ( V_48 = 0 ; V_48 < V_597 ; V_48 ++ ) {
T_4 V_1112 = V_3 >> ( V_48 * V_1113 ) ;
if ( V_1112 > V_134 )
V_3 &= ~ ( 0x7 << V_1113 ) ;
}
if ( V_3 != V_1110 )
F_71 ( V_14 , V_1111 , V_3 ) ;
return;
}
static void F_571 ( struct V_1 * V_2 )
{
struct V_54 * V_73 = V_2 -> V_55 ;
struct V_1114 * V_136 = & V_2 -> V_136 ;
struct V_1115 * V_1116 = V_2 -> V_582 ;
T_4 V_1117 ;
for ( V_1117 = 0 ; V_1117 < V_1118 ; V_1117 ++ ) {
T_4 V_134 = 0 ;
if ( V_2 -> V_578 & V_579 )
V_134 = F_572 ( V_136 , 0 , V_1117 ) ;
else if ( V_1116 )
V_134 = V_1116 -> V_583 [ V_1117 ] ;
F_573 ( V_73 , V_1117 , V_134 ) ;
}
}
int F_574 ( struct V_54 * V_73 , T_4 V_134 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
bool V_1119 ;
if ( V_134 > V_2 -> V_136 . V_720 . V_721 ||
( V_14 -> V_108 . type == V_109 &&
V_134 < V_597 ) )
return - V_551 ;
V_1119 = ( F_575 ( & V_2 -> V_623 , 32 ) > 1 ) ;
if ( V_134 && V_1119 && V_2 -> V_624 > V_1120 )
return - V_759 ;
if ( F_57 ( V_73 ) )
F_420 ( V_73 ) ;
F_437 ( V_2 ) ;
#ifdef F_355
if ( V_134 ) {
F_576 ( V_73 , V_134 ) ;
F_571 ( V_2 ) ;
V_2 -> V_139 |= V_140 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ) {
V_2 -> V_1121 = V_2 -> V_14 . V_125 . V_735 ;
V_2 -> V_14 . V_125 . V_735 = V_1122 ;
}
} else {
F_577 ( V_73 ) ;
if ( V_2 -> V_14 . V_108 . type == V_109 )
V_2 -> V_14 . V_125 . V_735 = V_2 -> V_1121 ;
V_2 -> V_139 &= ~ V_140 ;
V_2 -> V_734 . V_137 = false ;
V_2 -> V_136 . V_137 = false ;
}
F_570 ( V_2 , V_134 ) ;
#endif
F_431 ( V_2 ) ;
if ( F_57 ( V_73 ) )
return F_414 ( V_73 ) ;
return 0 ;
}
void F_578 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
F_430 () ;
F_574 ( V_55 , F_247 ( V_55 ) ) ;
F_432 () ;
}
void F_579 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
if ( F_57 ( V_55 ) )
F_366 ( V_2 ) ;
else
F_372 ( V_2 ) ;
}
static T_17 F_580 ( struct V_54 * V_55 ,
T_17 V_196 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
if ( ! ( V_196 & V_211 ) )
V_196 &= ~ V_1123 ;
if ( ! ( V_2 -> V_154 & V_705 ) )
V_196 &= ~ V_1123 ;
return V_196 ;
}
static int F_581 ( struct V_54 * V_55 ,
T_17 V_196 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
T_17 V_1124 = V_55 -> V_196 ^ V_196 ;
bool V_1125 = false ;
if ( ! ( V_196 & V_1123 ) ) {
if ( V_2 -> V_154 & V_515 )
V_1125 = true ;
V_2 -> V_154 &= ~ V_515 ;
} else if ( ( V_2 -> V_154 & V_705 ) &&
! ( V_2 -> V_154 & V_515 ) ) {
if ( V_2 -> V_378 == 1 ||
V_2 -> V_378 > V_1126 ) {
V_2 -> V_154 |= V_515 ;
V_1125 = true ;
} else if ( ( V_1124 ^ V_196 ) & V_1123 ) {
F_105 ( V_172 , L_137
L_138 ) ;
}
}
switch ( V_196 & V_1127 ) {
case V_1127 :
if ( ! ( V_2 -> V_139 & V_599 ) )
V_1125 = true ;
V_2 -> V_139 &= ~ V_363 ;
V_2 -> V_139 |= V_599 ;
break;
default:
if ( V_2 -> V_139 & V_599 )
V_1125 = true ;
V_2 -> V_139 &= ~ V_599 ;
if ( V_2 -> V_139 & V_407 )
break;
if ( F_247 ( V_55 ) > 1 )
break;
if ( V_2 -> V_412 [ V_413 ] . V_704 <= 1 )
break;
if ( ! V_2 -> V_397 )
break;
V_2 -> V_139 |= V_363 ;
break;
}
if ( V_196 & V_244 )
F_285 ( V_2 ) ;
else
F_284 ( V_2 ) ;
if ( V_1124 & V_270 )
V_1125 = true ;
V_55 -> V_196 = V_196 ;
if ( V_1125 )
F_579 ( V_55 ) ;
return 0 ;
}
static void F_582 ( struct V_54 * V_73 , T_18 V_1128 ,
T_12 V_1047 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1129 = F_544 ( V_1047 ) ;
if ( V_1128 == V_1130 )
return;
if ( V_2 -> V_1131 == V_1129 ) {
F_583 ( V_73 , L_139 , V_1129 ) ;
return;
}
if ( V_2 -> V_1131 ) {
F_583 ( V_73 ,
L_140 ,
V_1129 ) ;
return;
}
V_2 -> V_1131 = V_1129 ;
F_71 ( V_14 , V_1132 , V_1129 ) ;
}
static void F_584 ( struct V_54 * V_73 , T_18 V_1128 ,
T_12 V_1047 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1129 = F_544 ( V_1047 ) ;
if ( V_1128 == V_1130 )
return;
if ( V_2 -> V_1131 != V_1129 ) {
F_583 ( V_73 , L_141 ,
V_1129 ) ;
return;
}
V_2 -> V_1131 = 0 ;
F_71 ( V_14 , V_1132 , 0 ) ;
}
static int F_585 ( struct V_1133 * V_1134 , struct V_1135 * V_1136 [] ,
struct V_54 * V_73 ,
const unsigned char * V_545 , T_2 V_246 ,
T_2 V_139 )
{
if ( F_586 ( V_545 ) || F_587 ( V_545 ) ) {
if ( V_1137 <= F_302 ( V_73 ) )
return - V_540 ;
}
return F_588 ( V_1134 , V_1136 , V_73 , V_545 , V_246 , V_139 ) ;
}
static int F_589 ( struct V_54 * V_73 ,
struct V_1138 * V_1139 , T_2 V_139 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_1135 * V_1140 , * V_1141 ;
int V_1142 ;
if ( ! ( V_2 -> V_139 & V_407 ) )
return - V_1143 ;
V_1141 = F_590 ( V_1139 , sizeof( struct V_1144 ) , V_1145 ) ;
if ( ! V_1141 )
return - V_551 ;
F_591 (attr, br_spec, rem) {
T_19 V_1146 ;
T_1 V_3 = 0 ;
if ( F_592 ( V_1140 ) != V_1147 )
continue;
if ( F_593 ( V_1140 ) < sizeof( V_1146 ) )
return - V_551 ;
V_1146 = F_594 ( V_1140 ) ;
if ( V_1146 == V_1148 ) {
V_3 = 0 ;
V_2 -> V_154 &= ~ V_483 ;
} else if ( V_1146 == V_1149 ) {
V_3 = V_485 ;
V_2 -> V_154 |= V_483 ;
} else
return - V_551 ;
F_71 ( & V_2 -> V_14 , V_484 , V_3 ) ;
F_105 ( V_156 , L_142 ,
V_1146 == V_1148 ? L_143 : L_144 ) ;
}
return 0 ;
}
static int F_595 ( struct V_195 * V_89 , T_1 V_1150 , T_1 V_1151 ,
struct V_54 * V_73 ,
T_1 V_1152 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
T_2 V_1146 ;
if ( ! ( V_2 -> V_139 & V_407 ) )
return 0 ;
if ( V_2 -> V_154 & V_483 )
V_1146 = V_1149 ;
else
V_1146 = V_1148 ;
return F_596 ( V_89 , V_1150 , V_1151 , V_73 , V_1146 , 0 , 0 ) ;
}
static void * F_597 ( struct V_54 * V_9 , struct V_54 * V_617 )
{
struct V_613 * V_1059 = NULL ;
struct V_1 * V_2 = F_89 ( V_9 ) ;
int V_1153 = V_2 -> V_304 + V_2 -> V_624 ;
unsigned int V_704 ;
int V_468 , V_17 ;
if ( V_1153 >= V_1154 )
return F_598 ( - V_551 ) ;
#ifdef F_599
if ( V_617 -> V_93 != V_617 -> V_77 ) {
F_583 ( V_9 , L_145 ,
V_617 -> V_53 ) ;
return F_598 ( - V_551 ) ;
}
#endif
if ( V_617 -> V_77 > V_762 ||
V_617 -> V_77 == V_1155 ) {
F_583 ( V_9 ,
L_146 ,
V_9 -> V_53 ) ;
return F_598 ( - V_551 ) ;
}
if ( ( ( V_2 -> V_139 & V_140 ) &&
V_2 -> V_624 > V_1120 - 1 ) ||
( V_2 -> V_624 > V_1156 ) )
return F_598 ( - V_759 ) ;
V_1059 = F_600 ( 1 , sizeof( struct V_613 ) , V_753 ) ;
if ( ! V_1059 )
return F_598 ( - V_540 ) ;
V_468 = F_575 ( & V_2 -> V_623 , 32 ) ;
V_2 -> V_624 ++ ;
F_243 ( V_468 , & V_2 -> V_623 ) ;
V_704 = F_601 ( & V_2 -> V_623 , 32 ) ;
V_2 -> V_139 |= V_572 | V_407 ;
V_2 -> V_412 [ V_487 ] . V_704 = V_704 + 1 ;
V_2 -> V_412 [ V_413 ] . V_704 = V_617 -> V_77 ;
V_17 = F_574 ( V_9 , F_247 ( V_9 ) ) ;
if ( V_17 )
goto V_1157;
V_1059 -> V_468 = V_468 ;
V_1059 -> V_148 = V_2 ;
V_17 = F_345 ( V_617 , V_1059 ) ;
if ( V_17 )
goto V_1157;
F_602 ( V_617 ) ;
return V_1059 ;
V_1157:
F_583 ( V_9 ,
L_147 , V_617 -> V_53 ) ;
F_34 ( V_468 , & V_2 -> V_623 ) ;
V_2 -> V_624 -- ;
F_234 ( V_1059 ) ;
return F_598 ( V_17 ) ;
}
static void F_603 ( struct V_54 * V_9 , void * V_1158 )
{
struct V_613 * V_1059 = V_1158 ;
struct V_1 * V_2 = V_1059 -> V_148 ;
unsigned int V_704 ;
F_34 ( V_1059 -> V_468 , & V_2 -> V_623 ) ;
V_2 -> V_624 -- ;
V_704 = F_601 ( & V_2 -> V_623 , 32 ) ;
V_2 -> V_412 [ V_487 ] . V_704 = V_704 + 1 ;
F_343 ( V_1059 -> V_55 , V_1059 ) ;
F_574 ( V_9 , F_247 ( V_9 ) ) ;
F_346 ( V_9 , L_92 ,
V_1059 -> V_468 , V_2 -> V_624 ,
V_1059 -> V_616 ,
V_1059 -> V_616 + V_2 -> V_615 ,
V_2 -> V_623 ) ;
F_234 ( V_1059 ) ;
}
static inline int F_604 ( struct V_1 * V_2 )
{
struct V_5 * V_383 , * V_9 = V_2 -> V_9 ;
int V_1159 = 0 ;
if ( F_8 ( & V_2 -> V_14 ) )
V_1159 = 4 ;
F_605 (entry, &adapter->pdev->bus->devices, bus_list) {
if ( V_383 -> V_954 )
continue;
if ( ( V_383 -> V_697 != V_9 -> V_697 ) ||
( V_383 -> V_190 != V_9 -> V_190 ) )
return - 1 ;
V_1159 ++ ;
}
return V_1159 ;
}
int F_606 ( struct V_1 * V_2 , T_2 V_21 ,
T_2 V_1160 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1161 = V_2 -> V_1162 & V_1163 ;
int V_1164 = 0 ;
switch ( V_21 ) {
case V_1165 :
switch ( V_1160 ) {
case V_1166 :
case V_1167 :
if ( V_14 -> V_10 . V_1168 != 0 )
break;
case V_1169 :
case V_1170 :
case V_1171 :
case V_1172 :
case V_1173 :
V_1164 = 1 ;
break;
}
break;
case V_1174 :
switch ( V_1160 ) {
case V_1175 :
V_1164 = 1 ;
break;
}
break;
case V_1176 :
if ( V_1160 != V_1177 )
V_1164 = 1 ;
break;
case V_1178 :
V_1164 = 1 ;
break;
case V_1179 :
case V_1180 :
if ( ( V_1161 == V_1181 ) ||
( ( V_1161 == V_1182 ) &&
( V_14 -> V_10 . V_1168 == 0 ) ) ) {
V_1164 = 1 ;
}
break;
}
return V_1164 ;
}
static void F_607 ( struct V_1 * V_2 )
{
#ifdef F_608
struct V_1183 * V_1184 = F_609 ( V_2 -> V_9 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
const unsigned char * V_545 ;
V_545 = F_610 ( V_1184 ) ;
if ( V_545 ) {
F_298 ( V_14 -> V_108 . V_1185 , V_545 ) ;
return;
}
#endif
#ifdef F_611
F_298 ( V_14 -> V_108 . V_1185 , V_1186 -> V_1187 ) ;
#endif
}
static int F_612 ( struct V_5 * V_9 , const struct V_1188 * V_1189 )
{
struct V_54 * V_55 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_14 ;
const struct V_1190 * V_1191 = V_1192 [ V_1189 -> V_1193 ] ;
int V_48 , V_17 , V_1194 , V_24 ;
unsigned int V_414 = V_1195 ;
T_4 V_1196 [ V_1197 ] ;
bool V_1198 = false ;
#ifdef F_176
T_2 V_1199 ;
#endif
T_1 V_1200 ;
if ( V_9 -> V_954 ) {
F_613 ( 1 , V_1201 L_148 ,
F_484 ( V_9 ) , V_9 -> V_697 , V_9 -> V_190 ) ;
return - V_551 ;
}
V_17 = F_427 ( V_9 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_614 ( & V_9 -> V_73 , F_242 ( 64 ) ) ) {
V_1194 = 1 ;
} else {
V_17 = F_614 ( & V_9 -> V_73 , F_242 ( 32 ) ) ;
if ( V_17 ) {
F_402 ( & V_9 -> V_73 ,
L_149 ) ;
goto V_1202;
}
V_1194 = 0 ;
}
V_17 = F_615 ( V_9 , F_616 ( V_9 ,
V_1203 ) , V_1204 ) ;
if ( V_17 ) {
F_402 ( & V_9 -> V_73 ,
L_150 , V_17 ) ;
goto V_1205;
}
F_617 ( V_9 ) ;
F_428 ( V_9 ) ;
F_426 ( V_9 ) ;
if ( V_1191 -> V_108 == V_109 ) {
#ifdef F_355
V_414 = 4 * V_597 ;
#else
V_414 = V_1206 ;
#endif
}
V_55 = F_618 ( sizeof( struct V_1 ) , V_414 ) ;
if ( ! V_55 ) {
V_17 = - V_540 ;
goto V_1207;
}
F_619 ( V_55 , & V_9 -> V_73 ) ;
V_2 = F_89 ( V_55 ) ;
V_2 -> V_55 = V_55 ;
V_2 -> V_9 = V_9 ;
V_14 = & V_2 -> V_14 ;
V_14 -> V_38 = V_2 ;
V_2 -> V_1208 = F_620 ( V_1209 , V_1210 ) ;
V_14 -> V_39 = F_621 ( F_622 ( V_9 , 0 ) ,
F_623 ( V_9 , 0 ) ) ;
V_2 -> V_396 = V_14 -> V_39 ;
if ( ! V_14 -> V_39 ) {
V_17 = - V_749 ;
goto V_1211;
}
V_55 -> V_1212 = & V_1213 ;
F_624 ( V_55 ) ;
V_55 -> V_1214 = 5 * V_969 ;
F_625 ( V_55 -> V_53 , F_484 ( V_9 ) , sizeof( V_55 -> V_53 ) ) ;
memcpy ( & V_14 -> V_108 . V_337 , V_1191 -> V_1215 , sizeof( V_14 -> V_108 . V_337 ) ) ;
V_14 -> V_108 . type = V_1191 -> V_108 ;
memcpy ( & V_14 -> V_1216 . V_337 , V_1191 -> V_1217 , sizeof( V_14 -> V_1216 . V_337 ) ) ;
V_1200 = F_37 ( V_14 , V_1218 ) ;
if ( F_22 ( V_14 -> V_39 ) ) {
V_17 = - V_749 ;
goto V_1211;
}
if ( ! ( V_1200 & ( 1 << 8 ) ) )
V_14 -> V_1216 . V_337 . V_233 = & V_1219 ;
memcpy ( & V_14 -> V_340 . V_337 , V_1191 -> V_1220 , sizeof( V_14 -> V_340 . V_337 ) ) ;
V_14 -> V_340 . V_965 = V_1221 ;
V_14 -> V_340 . V_1097 . V_1094 = V_1222 ;
V_14 -> V_340 . V_1097 . V_1223 = 0 ;
V_14 -> V_340 . V_1097 . V_1224 = V_1225 | V_1226 ;
V_14 -> V_340 . V_1097 . V_73 = V_55 ;
V_14 -> V_340 . V_1097 . V_1227 = F_553 ;
V_14 -> V_340 . V_1097 . V_1228 = F_554 ;
V_1191 -> V_1229 ( V_14 ) ;
V_17 = F_387 ( V_2 ) ;
if ( V_17 )
goto V_1230;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_71 ( & V_2 -> V_14 , V_766 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_139 & V_343 ) {
T_1 V_671 = F_37 ( V_14 , V_672 ) ;
if ( V_671 & V_673 )
F_207 ( V_172 , L_73 ) ;
}
if ( V_1231 )
V_14 -> V_1231 = V_1231 ;
V_14 -> V_340 . V_1232 = true ;
V_17 = V_14 -> V_108 . V_337 . V_1233 ( V_14 ) ;
V_14 -> V_340 . V_1232 = false ;
if ( V_17 == V_680 &&
V_14 -> V_108 . type == V_109 ) {
V_17 = 0 ;
} else if ( V_17 == V_681 ) {
F_18 ( L_151 ) ;
F_18 ( L_152 ) ;
goto V_1230;
} else if ( V_17 ) {
F_18 ( L_153 , V_17 ) ;
goto V_1230;
}
#ifdef F_288
if ( V_2 -> V_14 . V_108 . type == V_109 )
goto V_1234;
F_626 ( V_14 ) ;
memcpy ( & V_14 -> V_1235 . V_337 , V_1191 -> V_1236 , sizeof( V_14 -> V_1235 . V_337 ) ) ;
F_627 ( V_9 , V_741 ) ;
F_628 ( V_2 ) ;
V_1234:
#endif
V_55 -> V_196 = V_1237 |
V_1238 |
V_1239 |
V_1240 |
V_244 |
V_1241 |
V_1242 |
V_1243 |
V_197 |
V_211 ;
V_55 -> V_1244 = V_55 -> V_196 | V_1245 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_55 -> V_196 |= V_1246 ;
V_55 -> V_1244 |= V_1246 |
V_1127 ;
break;
default:
break;
}
V_55 -> V_1244 |= V_270 ;
V_55 -> V_1247 |= V_1242 ;
V_55 -> V_1247 |= V_1243 ;
V_55 -> V_1247 |= V_1238 ;
V_55 -> V_1247 |= V_1239 ;
V_55 -> V_1247 |= V_1237 ;
V_55 -> V_1248 |= V_1249 ;
V_55 -> V_1248 |= V_1250 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_113 :
case V_114 :
V_55 -> V_1251 |= V_211 ;
break;
default:
break;
}
#ifdef F_355
V_55 -> V_1252 = & V_1252 ;
#endif
#ifdef F_176
if ( V_2 -> V_139 & V_711 ) {
unsigned int V_1253 ;
if ( V_14 -> V_108 . V_337 . V_1254 ) {
V_14 -> V_108 . V_337 . V_1254 ( V_14 , & V_1199 ) ;
if ( V_1199 & V_1255 )
V_2 -> V_139 &= ~ V_711 ;
}
V_1253 = F_347 ( int , V_1256 , F_389 () ) ;
V_2 -> V_412 [ V_1065 ] . V_704 = V_1253 ;
V_55 -> V_196 |= V_1086 |
V_1087 ;
V_55 -> V_1247 |= V_1086 |
V_1087 |
V_577 ;
}
#endif
if ( V_1194 ) {
V_55 -> V_196 |= V_1257 ;
V_55 -> V_1247 |= V_1257 ;
}
if ( V_2 -> V_154 & V_705 )
V_55 -> V_1244 |= V_1123 ;
if ( V_2 -> V_154 & V_515 )
V_55 -> V_196 |= V_1123 ;
if ( V_14 -> V_1216 . V_337 . V_1258 ( V_14 , NULL ) < 0 ) {
F_18 ( L_154 ) ;
V_17 = - V_749 ;
goto V_1230;
}
F_607 ( V_2 ) ;
memcpy ( V_55 -> V_626 , V_14 -> V_108 . V_1185 , V_55 -> V_684 ) ;
if ( ! F_350 ( V_55 -> V_626 ) ) {
F_18 ( L_155 ) ;
V_17 = - V_749 ;
goto V_1230;
}
F_295 ( V_2 , V_14 -> V_108 . V_1185 ) ;
F_629 ( & V_2 -> V_674 , & F_494 ,
( unsigned long ) V_2 ) ;
if ( F_22 ( V_14 -> V_39 ) ) {
V_17 = - V_749 ;
goto V_1230;
}
F_630 ( & V_2 -> V_37 , F_497 ) ;
F_243 ( V_40 , & V_2 -> V_34 ) ;
F_34 ( V_36 , & V_2 -> V_34 ) ;
V_17 = F_431 ( V_2 ) ;
if ( V_17 )
goto V_1230;
V_2 -> V_770 = 0 ;
V_14 -> V_1216 . V_337 . V_233 ( V_14 , 0x2c , & V_2 -> V_1162 ) ;
V_14 -> V_1259 = F_606 ( V_2 , V_9 -> V_190 ,
V_9 -> V_703 ) ;
if ( V_14 -> V_1259 )
V_2 -> V_770 = V_1260 ;
F_631 ( & V_2 -> V_9 -> V_73 , V_2 -> V_770 ) ;
V_14 -> V_1216 . V_337 . V_233 ( V_14 , 0x2e , & V_2 -> V_1261 ) ;
V_14 -> V_1216 . V_337 . V_233 ( V_14 , 0x2d , & V_2 -> V_1262 ) ;
V_14 -> V_108 . V_337 . V_1263 ( V_14 ) ;
if ( F_8 ( V_14 ) )
F_5 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_24 = F_632 ( F_604 ( V_2 ) * 10 , 16 ) ;
break;
default:
V_24 = F_604 ( V_2 ) * 10 ;
break;
}
if ( V_24 > 0 )
F_9 ( V_2 , V_24 ) ;
V_17 = F_633 ( V_14 , V_1196 , sizeof( V_1196 ) ) ;
if ( V_17 )
F_625 ( V_1196 , L_7 , sizeof( V_1196 ) ) ;
if ( F_359 ( V_14 ) && V_14 -> V_340 . V_965 != V_1264 )
F_12 ( L_156 ,
V_14 -> V_108 . type , V_14 -> V_340 . type , V_14 -> V_340 . V_965 ,
V_1196 ) ;
else
F_12 ( L_157 ,
V_14 -> V_108 . type , V_14 -> V_340 . type , V_1196 ) ;
F_12 ( L_158 , V_55 -> V_626 ) ;
V_17 = V_14 -> V_108 . V_337 . V_1265 ( V_14 ) ;
if ( V_17 == V_683 ) {
F_11 ( L_95
L_159
L_160
L_161
L_99
L_100 ) ;
}
strcpy ( V_55 -> V_53 , L_162 ) ;
V_17 = F_634 ( V_55 ) ;
if ( V_17 )
goto V_1266;
F_635 ( V_9 , V_2 ) ;
if ( V_14 -> V_108 . V_337 . V_692 )
V_14 -> V_108 . V_337 . V_692 ( V_14 ) ;
F_380 ( V_55 ) ;
#ifdef F_225
if ( F_126 ( & V_9 -> V_73 ) == 0 ) {
V_2 -> V_139 |= V_187 ;
F_123 ( V_2 ) ;
}
#endif
if ( V_2 -> V_139 & V_407 ) {
F_105 ( V_172 , L_163 , V_2 -> V_304 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_304 ; V_48 ++ )
F_636 ( V_9 , ( V_48 | 0x10000000 ) ) ;
}
if ( V_14 -> V_108 . V_337 . V_1267 )
V_14 -> V_108 . V_337 . V_1267 ( V_14 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_560 ( V_55 ) ;
F_12 ( L_164 , V_1268 ) ;
#ifdef F_637
if ( F_638 ( V_2 ) )
F_103 ( V_172 , L_165 ) ;
#endif
F_639 ( V_2 ) ;
if ( F_640 ( V_14 ) && F_359 ( V_14 ) && V_14 -> V_108 . V_337 . V_654 )
V_14 -> V_108 . V_337 . V_654 ( V_14 ,
V_915 | V_938 ,
true ) ;
return 0 ;
V_1266:
F_70 ( V_2 ) ;
F_437 ( V_2 ) ;
V_1230:
F_641 ( V_2 ) ;
V_2 -> V_154 &= ~ V_648 ;
F_642 ( V_2 -> V_396 ) ;
F_234 ( V_2 -> V_542 ) ;
V_1211:
V_1198 = ! F_15 ( V_765 , & V_2 -> V_34 ) ;
F_643 ( V_55 ) ;
V_1207:
F_644 ( V_9 ,
F_616 ( V_9 , V_1203 ) ) ;
V_1205:
V_1202:
if ( ! V_2 || V_1198 )
F_438 ( V_9 ) ;
return V_17 ;
}
static void F_645 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_423 ( V_9 ) ;
struct V_54 * V_55 ;
bool V_1198 ;
if ( ! V_2 )
return;
V_55 = V_2 -> V_55 ;
F_646 ( V_2 ) ;
F_243 ( V_35 , & V_2 -> V_34 ) ;
F_647 ( & V_2 -> V_37 ) ;
#ifdef F_225
if ( V_2 -> V_139 & V_187 ) {
V_2 -> V_139 &= ~ V_187 ;
F_127 ( & V_9 -> V_73 ) ;
F_71 ( & V_2 -> V_14 , V_188 , 1 ) ;
}
#endif
#ifdef F_637
F_648 ( V_2 ) ;
#endif
F_562 ( V_55 ) ;
if ( V_55 -> V_966 == V_967 )
F_492 ( V_55 ) ;
#ifdef F_288
if ( V_740 )
F_641 ( V_2 ) ;
#endif
F_437 ( V_2 ) ;
F_70 ( V_2 ) ;
#ifdef F_649
F_234 ( V_2 -> V_138 ) ;
F_234 ( V_2 -> V_582 ) ;
#endif
F_642 ( V_2 -> V_396 ) ;
F_644 ( V_9 , F_616 ( V_9 ,
V_1203 ) ) ;
F_12 ( L_166 ) ;
F_234 ( V_2 -> V_542 ) ;
V_1198 = ! F_15 ( V_765 , & V_2 -> V_34 ) ;
F_643 ( V_55 ) ;
F_650 ( V_9 ) ;
if ( V_1198 )
F_438 ( V_9 ) ;
}
static T_20 F_651 ( struct V_5 * V_9 ,
T_21 V_34 )
{
struct V_1 * V_2 = F_423 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
#ifdef F_288
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_1269 , * V_945 ;
T_1 V_1270 , V_1271 , V_1272 , V_1273 ;
int V_1274 , V_949 ;
T_2 V_1275 , V_1276 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ||
V_2 -> V_304 == 0 )
goto V_1277;
V_1269 = V_9 -> V_10 -> V_12 ;
while ( V_1269 && ( F_652 ( V_1269 ) != V_1278 ) )
V_1269 = V_1269 -> V_10 -> V_12 ;
if ( ! V_1269 )
goto V_1277;
V_949 = F_487 ( V_1269 , V_1279 ) ;
if ( ! V_949 )
goto V_1277;
V_1270 = F_27 ( V_14 , V_949 + V_1280 ) ;
V_1271 = F_27 ( V_14 , V_949 + V_1280 + 4 ) ;
V_1272 = F_27 ( V_14 , V_949 + V_1280 + 8 ) ;
V_1273 = F_27 ( V_14 , V_949 + V_1280 + 12 ) ;
if ( F_22 ( V_14 -> V_39 ) )
goto V_1277;
V_1275 = V_1271 >> 16 ;
if ( ! ( V_1275 & 0x0080 ) )
goto V_1277;
V_1276 = V_1275 & 0x01 ;
if ( ( V_1276 & 1 ) == ( V_9 -> V_1281 & 1 ) ) {
unsigned int V_21 ;
V_1274 = ( V_1275 & 0x7F ) >> 1 ;
F_18 ( L_167 , V_1274 ) ;
F_18 ( L_168
L_169 ,
V_1270 , V_1271 , V_1272 , V_1273 ) ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_21 = V_1282 ;
break;
case V_112 :
V_21 = V_1283 ;
break;
case V_113 :
V_21 = V_1284 ;
break;
case V_114 :
V_21 = V_1285 ;
break;
default:
V_21 = 0 ;
break;
}
V_945 = F_488 ( V_1286 , V_21 , NULL ) ;
while ( V_945 ) {
if ( V_945 -> V_1281 == ( V_1275 & 0xFF ) )
break;
V_945 = F_488 ( V_1286 ,
V_21 , V_945 ) ;
}
if ( V_945 ) {
F_482 ( V_2 , V_945 ) ;
F_653 ( V_945 ) ;
}
F_654 ( V_9 ) ;
}
V_2 -> V_1287 ++ ;
return V_1288 ;
V_1277:
#endif
if ( ! F_14 ( V_40 , & V_2 -> V_34 ) )
return V_1289 ;
F_430 () ;
F_436 ( V_55 ) ;
if ( V_34 == V_1290 ) {
F_432 () ;
return V_1289 ;
}
if ( F_57 ( V_55 ) )
F_369 ( V_2 ) ;
if ( ! F_15 ( V_765 , & V_2 -> V_34 ) )
F_438 ( V_9 ) ;
F_432 () ;
return V_1291 ;
}
static T_20 F_655 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_423 ( V_9 ) ;
T_20 V_1292 ;
int V_17 ;
if ( F_427 ( V_9 ) ) {
F_103 ( V_172 , L_170 ) ;
V_1292 = V_1289 ;
} else {
F_33 () ;
F_34 ( V_765 , & V_2 -> V_34 ) ;
V_2 -> V_14 . V_39 = V_2 -> V_396 ;
F_428 ( V_9 ) ;
F_425 ( V_9 ) ;
F_426 ( V_9 ) ;
F_429 ( V_9 , false ) ;
F_372 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_766 , ~ 0 ) ;
V_1292 = V_1288 ;
}
V_17 = F_654 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_171
L_172 , V_17 ) ;
}
return V_1292 ;
}
static void F_656 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_423 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
#ifdef F_288
if ( V_2 -> V_1287 ) {
F_105 ( V_156 , L_173 ) ;
V_2 -> V_1287 -- ;
return;
}
#endif
if ( F_57 ( V_55 ) )
F_371 ( V_2 ) ;
F_433 ( V_55 ) ;
}
static int T_22 F_657 ( void )
{
int V_650 ;
F_51 ( L_174 , V_1293 , V_1294 ) ;
F_51 ( L_164 , V_1295 ) ;
F_658 () ;
V_650 = F_659 ( & V_1296 ) ;
if ( V_650 ) {
F_660 () ;
return V_650 ;
}
#ifdef F_225
F_661 ( & V_1297 ) ;
#endif
return 0 ;
}
static void T_23 F_662 ( void )
{
#ifdef F_225
F_663 ( & V_1297 ) ;
#endif
F_664 ( & V_1296 ) ;
F_660 () ;
F_665 () ;
}
static int F_666 ( struct V_1298 * V_1299 , unsigned long V_191 ,
void * V_1090 )
{
int V_1300 ;
V_1300 = F_667 ( & V_1296 . V_1301 , NULL , & V_191 ,
F_124 ) ;
return V_1300 ? V_1302 : V_1303 ;
}
