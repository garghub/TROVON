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
if ( F_160 ( V_158 ) )
F_161 ( V_89 ) ;
else
F_162 ( & V_158 -> V_250 , V_89 ) ;
}
static bool F_163 ( struct V_57 * V_67 ,
union V_68 * V_69 ,
struct V_195 * V_89 )
{
T_1 V_251 = V_67 -> V_79 + 1 ;
V_251 = ( V_251 < V_67 -> V_88 ) ? V_251 : 0 ;
V_67 -> V_79 = V_251 ;
F_98 ( F_66 ( V_67 , V_251 ) ) ;
if ( F_164 ( V_67 ) ) {
T_10 V_252 = V_69 -> V_94 . V_198 . V_203 . V_92 &
F_96 ( V_253 ) ;
if ( F_24 ( V_252 ) ) {
T_1 V_254 = F_67 ( V_252 ) ;
V_254 >>= V_255 ;
F_150 ( V_89 ) -> V_238 += V_254 - 1 ;
V_251 = F_67 ( V_69 -> V_94 . V_95 . V_96 ) ;
V_251 &= V_256 ;
V_251 >>= V_257 ;
}
}
if ( F_99 ( F_134 ( V_69 , V_258 ) ) )
return false ;
V_67 -> V_71 [ V_251 ] . V_89 = V_89 ;
V_67 -> V_219 . V_259 ++ ;
return true ;
}
static void F_165 ( struct V_57 * V_67 ,
struct V_195 * V_89 )
{
struct V_260 * V_261 = & F_148 ( V_89 ) -> V_262 [ 0 ] ;
unsigned char * V_263 ;
unsigned int V_264 ;
V_263 = F_166 ( V_261 ) ;
V_264 = F_167 ( V_263 , V_265 ) ;
F_168 ( V_89 , V_263 , F_169 ( V_264 , sizeof( long ) ) ) ;
F_170 ( V_261 , V_264 ) ;
V_261 -> V_99 += V_264 ;
V_89 -> V_266 -= V_264 ;
V_89 -> V_146 += V_264 ;
}
static void F_171 ( struct V_57 * V_67 ,
struct V_195 * V_89 )
{
if ( F_24 ( F_150 ( V_89 ) -> V_267 ) ) {
F_80 ( V_67 -> V_73 , F_150 ( V_89 ) -> V_81 ,
F_139 ( V_67 ) , V_231 ) ;
F_150 ( V_89 ) -> V_267 = false ;
} else {
struct V_260 * V_261 = & F_148 ( V_89 ) -> V_262 [ 0 ] ;
F_172 ( V_67 -> V_73 ,
F_150 ( V_89 ) -> V_81 ,
V_261 -> V_99 ,
F_69 ( V_67 ) ,
V_231 ) ;
}
F_150 ( V_89 ) -> V_81 = 0 ;
}
static bool F_173 ( struct V_57 * V_67 ,
union V_68 * V_69 ,
struct V_195 * V_89 )
{
struct V_54 * V_55 = V_67 -> V_55 ;
if ( F_24 ( F_134 ( V_69 ,
V_268 ) &&
! ( V_55 -> V_196 & V_269 ) ) ) {
F_78 ( V_89 ) ;
return true ;
}
if ( F_174 ( V_89 ) )
F_165 ( V_67 , V_89 ) ;
#ifdef F_175
if ( F_130 ( V_67 , V_69 ) )
return false ;
#endif
if ( F_176 ( V_89 ) )
return true ;
return false ;
}
static void F_177 ( struct V_57 * V_67 ,
struct V_70 * V_270 )
{
struct V_70 * V_271 ;
T_2 V_272 = V_67 -> V_235 ;
V_271 = & V_67 -> V_71 [ V_272 ] ;
V_272 ++ ;
V_67 -> V_235 = ( V_272 < V_67 -> V_88 ) ? V_272 : 0 ;
* V_271 = * V_270 ;
F_178 ( V_67 -> V_73 , V_271 -> V_81 ,
V_271 -> V_99 ,
F_69 ( V_67 ) ,
V_231 ) ;
}
static inline bool F_179 ( struct V_98 * V_98 )
{
return ( F_180 ( V_98 ) != F_181 () ) || V_98 -> V_273 ;
}
static bool F_182 ( struct V_57 * V_67 ,
struct V_70 * V_274 ,
union V_68 * V_69 ,
struct V_195 * V_89 )
{
struct V_98 * V_98 = V_274 -> V_98 ;
unsigned int V_275 = F_154 ( V_69 -> V_94 . V_95 . V_276 ) ;
#if ( V_277 < 8192 )
unsigned int V_278 = F_69 ( V_67 ) ;
#else
unsigned int V_278 = F_169 ( V_275 , V_279 ) ;
unsigned int V_280 = F_139 ( V_67 ) -
F_69 ( V_67 ) ;
#endif
if ( ( V_275 <= V_265 ) && ! F_174 ( V_89 ) ) {
unsigned char * V_263 = F_68 ( V_98 ) + V_274 -> V_99 ;
memcpy ( F_183 ( V_89 , V_275 ) , V_263 , F_169 ( V_275 , sizeof( long ) ) ) ;
if ( F_99 ( ! F_179 ( V_98 ) ) )
return true ;
F_141 ( V_98 , F_137 ( V_67 ) ) ;
return false ;
}
F_184 ( V_89 , F_148 ( V_89 ) -> V_281 , V_98 ,
V_274 -> V_99 , V_275 , V_278 ) ;
if ( F_24 ( F_179 ( V_98 ) ) )
return false ;
#if ( V_277 < 8192 )
if ( F_24 ( F_185 ( V_98 ) != 1 ) )
return false ;
V_274 -> V_99 ^= V_278 ;
#else
V_274 -> V_99 += V_278 ;
if ( V_274 -> V_99 > V_280 )
return false ;
#endif
F_186 ( & V_98 -> V_282 ) ;
return true ;
}
static struct V_195 * F_187 ( struct V_57 * V_67 ,
union V_68 * V_69 )
{
struct V_70 * V_274 ;
struct V_195 * V_89 ;
struct V_98 * V_98 ;
V_274 = & V_67 -> V_71 [ V_67 -> V_79 ] ;
V_98 = V_274 -> V_98 ;
F_188 ( V_98 ) ;
V_89 = V_274 -> V_89 ;
if ( F_99 ( ! V_89 ) ) {
void * V_283 = F_68 ( V_98 ) +
V_274 -> V_99 ;
F_98 ( V_283 ) ;
#if V_279 < 128
F_98 ( V_283 + V_279 ) ;
#endif
V_89 = F_189 ( & V_67 -> V_158 -> V_250 ,
V_265 ) ;
if ( F_24 ( ! V_89 ) ) {
V_67 -> V_219 . V_284 ++ ;
return NULL ;
}
F_188 ( V_89 -> V_92 ) ;
if ( F_99 ( F_134 ( V_69 , V_258 ) ) )
goto V_285;
F_150 ( V_89 ) -> V_81 = V_274 -> V_81 ;
} else {
if ( F_134 ( V_69 , V_258 ) )
F_171 ( V_67 , V_89 ) ;
V_285:
F_172 ( V_67 -> V_73 ,
V_274 -> V_81 ,
V_274 -> V_99 ,
F_69 ( V_67 ) ,
V_231 ) ;
V_274 -> V_89 = NULL ;
}
if ( F_182 ( V_67 , V_274 , V_69 , V_89 ) ) {
F_177 ( V_67 , V_274 ) ;
} else if ( F_150 ( V_89 ) -> V_81 == V_274 -> V_81 ) {
F_150 ( V_89 ) -> V_267 = true ;
} else {
F_80 ( V_67 -> V_73 , V_274 -> V_81 ,
F_139 ( V_67 ) ,
V_231 ) ;
}
V_274 -> V_98 = NULL ;
return V_89 ;
}
static int F_190 ( struct V_157 * V_158 ,
struct V_57 * V_67 ,
const int V_161 )
{
unsigned int V_286 = 0 , V_287 = 0 ;
#ifdef F_175
struct V_1 * V_2 = V_158 -> V_2 ;
int V_288 ;
unsigned int V_289 = 0 ;
#endif
T_2 V_232 = F_110 ( V_67 ) ;
while ( F_99 ( V_287 < V_161 ) ) {
union V_68 * V_69 ;
struct V_195 * V_89 ;
if ( V_232 >= V_290 ) {
F_142 ( V_67 , V_232 ) ;
V_232 = 0 ;
}
V_69 = F_66 ( V_67 , V_67 -> V_79 ) ;
if ( ! V_69 -> V_94 . V_95 . V_96 )
break;
F_191 () ;
V_89 = F_187 ( V_67 , V_69 ) ;
if ( ! V_89 )
break;
V_232 ++ ;
if ( F_163 ( V_67 , V_69 , V_89 ) )
continue;
if ( F_173 ( V_67 , V_69 , V_89 ) )
continue;
V_286 += V_89 -> V_82 ;
F_152 ( V_67 , V_69 , V_89 ) ;
#ifdef F_175
if ( F_130 ( V_67 , V_69 ) ) {
V_288 = F_192 ( V_2 , V_69 , V_89 ) ;
if ( V_288 > 0 ) {
if ( ! V_289 ) {
V_289 = V_67 -> V_55 -> V_291 -
sizeof( struct V_292 ) -
sizeof( struct V_293 ) -
sizeof( struct V_294 ) ;
if ( V_289 > 512 )
V_289 &= ~ 511 ;
}
V_286 += V_288 ;
V_287 += F_149 ( V_288 ,
V_289 ) ;
}
if ( ! V_288 ) {
F_78 ( V_89 ) ;
continue;
}
}
#endif
F_193 ( V_89 , & V_158 -> V_250 ) ;
F_159 ( V_158 , V_89 ) ;
V_287 ++ ;
}
F_100 ( & V_67 -> V_169 ) ;
V_67 -> V_124 . V_144 += V_287 ;
V_67 -> V_124 . V_170 += V_286 ;
F_101 ( & V_67 -> V_169 ) ;
V_158 -> V_295 . V_160 += V_287 ;
V_158 -> V_295 . V_159 += V_286 ;
return V_287 ;
}
static int F_194 ( struct V_296 * V_250 )
{
struct V_157 * V_158 =
F_195 ( V_250 , struct V_157 , V_250 ) ;
struct V_1 * V_2 = V_158 -> V_2 ;
struct V_57 * V_120 ;
int V_297 = 0 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return V_298 ;
if ( ! F_196 ( V_158 ) )
return V_299 ;
F_121 (ring, q_vector->rx) {
V_297 = F_190 ( V_158 , V_120 , 4 ) ;
#ifdef F_197
if ( V_297 )
V_120 -> V_124 . V_300 += V_297 ;
else
V_120 -> V_124 . V_301 ++ ;
#endif
if ( V_297 )
break;
}
F_198 ( V_158 ) ;
return V_297 ;
}
static void F_199 ( struct V_1 * V_2 )
{
struct V_157 * V_158 ;
int V_302 ;
T_1 V_117 ;
if ( V_2 -> V_303 > 32 ) {
T_1 V_304 = ( 1 << ( V_2 -> V_303 - 32 ) ) - 1 ;
F_71 ( & V_2 -> V_14 , V_305 , V_304 ) ;
}
for ( V_302 = 0 ; V_302 < V_2 -> V_189 ; V_302 ++ ) {
struct V_57 * V_120 ;
V_158 = V_2 -> V_158 [ V_302 ] ;
F_121 (ring, q_vector->rx)
F_73 ( V_2 , 0 , V_120 -> V_149 , V_302 ) ;
F_121 (ring, q_vector->tx)
F_73 ( V_2 , 1 , V_120 -> V_149 , V_302 ) ;
F_200 ( V_158 ) ;
}
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
F_73 ( V_2 , - 1 , V_306 ,
V_302 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_73 ( V_2 , - 1 , 1 , V_302 ) ;
break;
default:
break;
}
F_71 ( & V_2 -> V_14 , F_201 ( V_302 ) , 1950 ) ;
V_117 = V_307 ;
V_117 &= ~ ( V_308 |
V_309 |
V_310 ) ;
F_71 ( & V_2 -> V_14 , V_311 , V_117 ) ;
}
static void F_202 ( struct V_157 * V_158 ,
struct V_312 * V_313 )
{
int V_170 = V_313 -> V_159 ;
int V_144 = V_313 -> V_160 ;
T_1 V_314 ;
T_6 V_315 ;
T_4 V_316 = V_313 -> V_317 ;
if ( V_144 == 0 )
return;
V_314 = V_158 -> V_317 >> 2 ;
if ( V_314 == 0 )
return;
V_315 = V_170 / V_314 ;
switch ( V_316 ) {
case V_318 :
if ( V_315 > 10 )
V_316 = V_319 ;
break;
case V_319 :
if ( V_315 > 20 )
V_316 = V_320 ;
else if ( V_315 <= 10 )
V_316 = V_318 ;
break;
case V_320 :
if ( V_315 <= 20 )
V_316 = V_319 ;
break;
}
V_313 -> V_159 = 0 ;
V_313 -> V_160 = 0 ;
V_313 -> V_317 = V_316 ;
}
void F_200 ( struct V_157 * V_158 )
{
struct V_1 * V_2 = V_158 -> V_2 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_302 = V_158 -> V_302 ;
T_1 V_321 = V_158 -> V_317 & V_322 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
V_321 |= ( V_321 << 16 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_321 |= V_323 ;
break;
default:
break;
}
F_71 ( V_14 , F_201 ( V_302 ) , V_321 ) ;
}
static void F_203 ( struct V_157 * V_158 )
{
T_1 V_324 = V_158 -> V_317 ;
T_4 V_325 ;
F_202 ( V_158 , & V_158 -> V_162 ) ;
F_202 ( V_158 , & V_158 -> V_295 ) ;
V_325 = F_204 ( V_158 -> V_295 . V_317 , V_158 -> V_162 . V_317 ) ;
switch ( V_325 ) {
case V_318 :
V_324 = V_326 ;
break;
case V_319 :
V_324 = V_327 ;
break;
case V_320 :
V_324 = V_328 ;
break;
default:
break;
}
if ( V_324 != V_158 -> V_317 ) {
V_324 = ( 10 * V_324 * V_158 -> V_317 ) /
( ( 9 * V_324 ) + V_158 -> V_317 ) ;
V_158 -> V_317 = V_324 ;
F_200 ( V_158 ) ;
}
}
static void F_205 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_329 = V_2 -> V_330 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
if ( ! ( V_2 -> V_154 & V_331 ) &&
! ( V_2 -> V_154 & V_332 ) )
return;
V_2 -> V_154 &= ~ V_332 ;
switch ( V_14 -> V_21 ) {
case V_333 :
if ( ! ( V_329 & V_334 ) &&
! ( V_329 & V_335 ) )
return;
if ( ! ( V_329 & V_335 ) && V_14 -> V_108 . V_336 . V_337 ) {
T_1 V_20 ;
bool V_338 = false ;
V_14 -> V_108 . V_336 . V_337 ( V_14 , & V_20 , & V_338 , false ) ;
if ( V_338 )
return;
}
if ( V_14 -> V_339 . V_336 . V_340 ( V_14 ) != V_341 )
return;
break;
default:
if ( ! ( V_329 & V_334 ) )
return;
break;
}
F_206 ( V_156 ,
L_70
L_71
L_72 ) ;
V_2 -> V_330 = 0 ;
}
static void F_207 ( struct V_1 * V_2 , T_1 V_329 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ( V_2 -> V_139 & V_342 ) &&
( V_329 & V_343 ) ) {
F_206 ( V_172 , L_73 ) ;
F_71 ( V_14 , V_344 , V_343 ) ;
}
}
static void F_208 ( struct V_1 * V_2 , T_1 V_329 )
{
if ( ! ( V_2 -> V_154 & V_331 ) )
return;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
if ( ( ( V_329 & V_334 ) || ( V_329 & V_335 ) ) &&
( ! F_14 ( V_33 , & V_2 -> V_34 ) ) ) {
V_2 -> V_330 = V_329 ;
V_2 -> V_154 |= V_332 ;
F_13 ( V_2 ) ;
return;
}
return;
case V_112 :
if ( ! ( V_329 & V_345 ) )
return;
break;
default:
return;
}
F_206 ( V_156 ,
L_70
L_71
L_72 ) ;
}
static void F_209 ( struct V_1 * V_2 , T_1 V_329 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_329 & V_346 ) {
F_71 ( V_14 , V_344 , V_346 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_154 |= V_347 ;
F_13 ( V_2 ) ;
}
}
if ( V_329 & V_343 ) {
F_71 ( V_14 , V_344 , V_343 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_139 |= V_348 ;
F_13 ( V_2 ) ;
}
}
}
static void F_210 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_349 ++ ;
V_2 -> V_139 |= V_350 ;
V_2 -> V_351 = V_171 ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
F_71 ( V_14 , V_352 , V_353 ) ;
F_211 ( V_14 ) ;
F_13 ( V_2 ) ;
}
}
static inline void F_212 ( struct V_1 * V_2 ,
T_6 V_116 )
{
T_1 V_117 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_117 = ( V_118 & V_116 ) ;
F_71 ( V_14 , V_354 , V_117 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_117 = ( V_116 & 0xFFFFFFFF ) ;
if ( V_117 )
F_71 ( V_14 , F_213 ( 0 ) , V_117 ) ;
V_117 = ( V_116 >> 32 ) ;
if ( V_117 )
F_71 ( V_14 , F_213 ( 1 ) , V_117 ) ;
break;
default:
break;
}
}
static inline void F_214 ( struct V_1 * V_2 ,
T_6 V_116 )
{
T_1 V_117 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_117 = ( V_118 & V_116 ) ;
F_71 ( V_14 , V_352 , V_117 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_117 = ( V_116 & 0xFFFFFFFF ) ;
if ( V_117 )
F_71 ( V_14 , F_215 ( 0 ) , V_117 ) ;
V_117 = ( V_116 >> 32 ) ;
if ( V_117 )
F_71 ( V_14 , F_215 ( 1 ) , V_117 ) ;
break;
default:
break;
}
}
static inline void F_216 ( struct V_1 * V_2 , bool V_355 ,
bool V_356 )
{
T_1 V_117 = ( V_307 & ~ V_118 ) ;
if ( V_2 -> V_139 & V_350 )
V_117 &= ~ V_310 ;
if ( V_2 -> V_154 & V_331 )
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_117 |= V_357 ;
break;
case V_112 :
case V_113 :
case V_114 :
V_117 |= V_358 ;
break;
default:
break;
}
if ( V_2 -> V_139 & V_342 )
V_117 |= V_359 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_117 |= V_359 ;
V_117 |= V_360 ;
case V_112 :
case V_113 :
case V_114 :
V_117 |= V_361 ;
V_117 |= V_309 ;
break;
default:
break;
}
if ( ( V_2 -> V_139 & V_362 ) &&
! ( V_2 -> V_154 & V_363 ) )
V_117 |= V_364 ;
F_71 ( & V_2 -> V_14 , V_354 , V_117 ) ;
if ( V_355 )
F_212 ( V_2 , ~ 0 ) ;
if ( V_356 )
F_211 ( & V_2 -> V_14 ) ;
}
static T_11 F_217 ( int V_365 , void * V_92 )
{
struct V_1 * V_2 = V_92 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_329 ;
V_329 = F_37 ( V_14 , V_119 ) ;
V_329 &= 0xFFFF0000 ;
F_71 ( V_14 , V_344 , V_329 ) ;
if ( V_329 & V_335 )
F_210 ( V_2 ) ;
if ( V_329 & V_366 )
F_218 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
if ( V_329 & V_367 ) {
F_105 ( V_368 , L_74 ) ;
V_2 -> V_154 |= V_155 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_344 , V_367 ) ;
}
if ( V_329 & V_369 ) {
int V_370 = 0 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_120 = V_2 -> V_58 [ V_48 ] ;
if ( F_219 ( V_371 ,
& V_120 -> V_34 ) )
V_370 ++ ;
}
if ( V_370 ) {
F_71 ( V_14 , V_352 , V_372 ) ;
V_2 -> V_154 |= V_363 ;
F_13 ( V_2 ) ;
}
}
F_209 ( V_2 , V_329 ) ;
F_208 ( V_2 , V_329 ) ;
break;
default:
break;
}
F_207 ( V_2 , V_329 ) ;
if ( F_24 ( V_329 & V_373 ) )
F_220 ( V_2 , V_329 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_216 ( V_2 , false , false ) ;
return V_374 ;
}
static T_11 F_221 ( int V_365 , void * V_92 )
{
struct V_157 * V_158 = V_92 ;
if ( V_158 -> V_295 . V_120 || V_158 -> V_162 . V_120 )
F_222 ( & V_158 -> V_250 ) ;
return V_374 ;
}
int F_223 ( struct V_296 * V_250 , int V_161 )
{
struct V_157 * V_158 =
F_195 ( V_250 , struct V_157 , V_250 ) ;
struct V_1 * V_2 = V_158 -> V_2 ;
struct V_57 * V_120 ;
int V_375 ;
bool V_376 = true ;
#ifdef F_224
if ( V_2 -> V_139 & V_187 )
F_119 ( V_158 ) ;
#endif
F_121 (ring, q_vector->tx)
V_376 &= ! ! F_94 ( V_158 , V_120 ) ;
if ( ! F_225 ( V_158 ) )
return V_161 ;
if ( V_158 -> V_295 . V_88 > 1 )
V_375 = F_204 ( V_161 / V_158 -> V_295 . V_88 , 1 ) ;
else
V_375 = V_161 ;
F_121 (ring, q_vector->rx)
V_376 &= ( F_190 ( V_158 , V_120 ,
V_375 ) < V_375 ) ;
F_226 ( V_158 ) ;
if ( ! V_376 )
return V_161 ;
F_227 ( V_250 ) ;
if ( V_2 -> V_377 & 1 )
F_203 ( V_158 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_212 ( V_2 , ( ( T_6 ) 1 << V_158 -> V_302 ) ) ;
return 0 ;
}
static int F_228 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
int V_378 , V_17 ;
int V_379 = 0 , V_380 = 0 ;
for ( V_378 = 0 ; V_378 < V_2 -> V_189 ; V_378 ++ ) {
struct V_157 * V_158 = V_2 -> V_158 [ V_378 ] ;
struct V_381 * V_382 = & V_2 -> V_383 [ V_378 ] ;
if ( V_158 -> V_162 . V_120 && V_158 -> V_295 . V_120 ) {
snprintf ( V_158 -> V_53 , sizeof( V_158 -> V_53 ) - 1 ,
L_75 , V_55 -> V_53 , L_76 , V_379 ++ ) ;
V_380 ++ ;
} else if ( V_158 -> V_295 . V_120 ) {
snprintf ( V_158 -> V_53 , sizeof( V_158 -> V_53 ) - 1 ,
L_75 , V_55 -> V_53 , L_77 , V_379 ++ ) ;
} else if ( V_158 -> V_162 . V_120 ) {
snprintf ( V_158 -> V_53 , sizeof( V_158 -> V_53 ) - 1 ,
L_75 , V_55 -> V_53 , L_78 , V_380 ++ ) ;
} else {
continue;
}
V_17 = F_229 ( V_382 -> V_378 , & F_221 , 0 ,
V_158 -> V_53 , V_158 ) ;
if ( V_17 ) {
F_103 ( V_172 , L_79
L_80 , V_17 ) ;
goto V_384;
}
if ( V_2 -> V_139 & V_362 ) {
F_230 ( V_382 -> V_378 ,
& V_158 -> V_385 ) ;
}
}
V_17 = F_229 ( V_2 -> V_383 [ V_378 ] . V_378 ,
F_217 , 0 , V_55 -> V_53 , V_2 ) ;
if ( V_17 ) {
F_103 ( V_172 , L_81 , V_17 ) ;
goto V_384;
}
return 0 ;
V_384:
while ( V_378 ) {
V_378 -- ;
F_230 ( V_2 -> V_383 [ V_378 ] . V_378 ,
NULL ) ;
F_231 ( V_2 -> V_383 [ V_378 ] . V_378 ,
V_2 -> V_158 [ V_378 ] ) ;
}
V_2 -> V_139 &= ~ V_386 ;
F_232 ( V_2 -> V_9 ) ;
F_233 ( V_2 -> V_383 ) ;
V_2 -> V_383 = NULL ;
return V_17 ;
}
static T_11 F_234 ( int V_365 , void * V_92 )
{
struct V_1 * V_2 = V_92 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_157 * V_158 = V_2 -> V_158 [ 0 ] ;
T_1 V_329 ;
F_71 ( V_14 , V_352 , V_387 ) ;
V_329 = F_37 ( V_14 , V_344 ) ;
if ( ! V_329 ) {
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_216 ( V_2 , true , true ) ;
return V_388 ;
}
if ( V_329 & V_335 )
F_210 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
F_209 ( V_2 , V_329 ) ;
case V_112 :
case V_113 :
case V_114 :
if ( V_329 & V_367 ) {
F_105 ( V_368 , L_74 ) ;
V_2 -> V_154 |= V_155 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_344 , V_367 ) ;
}
F_208 ( V_2 , V_329 ) ;
break;
default:
break;
}
F_207 ( V_2 , V_329 ) ;
if ( F_24 ( V_329 & V_373 ) )
F_220 ( V_2 , V_329 ) ;
F_222 ( & V_158 -> V_250 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_216 ( V_2 , false , false ) ;
return V_374 ;
}
static int F_235 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
int V_17 ;
if ( V_2 -> V_139 & V_386 )
V_17 = F_228 ( V_2 ) ;
else if ( V_2 -> V_139 & V_389 )
V_17 = F_229 ( V_2 -> V_9 -> V_365 , F_234 , 0 ,
V_55 -> V_53 , V_2 ) ;
else
V_17 = F_229 ( V_2 -> V_9 -> V_365 , F_234 , V_390 ,
V_55 -> V_53 , V_2 ) ;
if ( V_17 )
F_103 ( V_172 , L_82 , V_17 ) ;
return V_17 ;
}
static void F_236 ( struct V_1 * V_2 )
{
int V_378 ;
if ( ! ( V_2 -> V_139 & V_386 ) ) {
F_231 ( V_2 -> V_9 -> V_365 , V_2 ) ;
return;
}
for ( V_378 = 0 ; V_378 < V_2 -> V_189 ; V_378 ++ ) {
struct V_157 * V_158 = V_2 -> V_158 [ V_378 ] ;
struct V_381 * V_382 = & V_2 -> V_383 [ V_378 ] ;
if ( ! V_158 -> V_295 . V_120 && ! V_158 -> V_162 . V_120 )
continue;
F_230 ( V_382 -> V_378 , NULL ) ;
F_231 ( V_382 -> V_378 , V_158 ) ;
}
F_231 ( V_2 -> V_383 [ V_378 ++ ] . V_378 , V_2 ) ;
}
static inline void F_237 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
F_71 ( & V_2 -> V_14 , V_352 , ~ 0 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_71 ( & V_2 -> V_14 , V_352 , 0xFFFF0000 ) ;
F_71 ( & V_2 -> V_14 , F_215 ( 0 ) , ~ 0 ) ;
F_71 ( & V_2 -> V_14 , F_215 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_211 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_139 & V_386 ) {
int V_378 ;
for ( V_378 = 0 ; V_378 < V_2 -> V_189 ; V_378 ++ )
F_238 ( V_2 -> V_383 [ V_378 ] . V_378 ) ;
F_238 ( V_2 -> V_383 [ V_378 ++ ] . V_378 ) ;
} else {
F_238 ( V_2 -> V_9 -> V_365 ) ;
}
}
static void F_239 ( struct V_1 * V_2 )
{
struct V_157 * V_158 = V_2 -> V_158 [ 0 ] ;
F_200 ( V_158 ) ;
F_73 ( V_2 , 0 , 0 , 0 ) ;
F_73 ( V_2 , 1 , 0 , 0 ) ;
F_105 ( V_14 , L_83 ) ;
}
void F_240 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_391 = V_120 -> V_81 ;
int V_392 = 10 ;
T_1 V_393 = V_394 ;
T_4 V_149 = V_120 -> V_149 ;
F_71 ( V_14 , F_50 ( V_149 ) , 0 ) ;
F_211 ( V_14 ) ;
F_71 ( V_14 , F_45 ( V_149 ) ,
( V_391 & F_241 ( 32 ) ) ) ;
F_71 ( V_14 , F_46 ( V_149 ) , ( V_391 >> 32 ) ) ;
F_71 ( V_14 , F_47 ( V_149 ) ,
V_120 -> V_88 * sizeof( union V_61 ) ) ;
F_71 ( V_14 , F_48 ( V_149 ) , 0 ) ;
F_71 ( V_14 , F_49 ( V_149 ) , 0 ) ;
V_120 -> V_146 = V_2 -> V_395 + F_49 ( V_149 ) ;
if ( ! V_120 -> V_158 || ( V_120 -> V_158 -> V_317 < V_326 ) )
V_393 |= ( 1 << 16 ) ;
else
V_393 |= ( 8 << 16 ) ;
V_393 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_139 & V_362 ) {
V_120 -> V_396 = V_2 -> V_396 ;
V_120 -> V_397 = 0 ;
F_242 ( V_371 , & V_120 -> V_34 ) ;
} else {
V_120 -> V_396 = 0 ;
}
if ( ! F_15 ( V_398 , & V_120 -> V_34 ) ) {
struct V_157 * V_158 = V_120 -> V_158 ;
if ( V_158 )
F_243 ( V_120 -> V_55 ,
& V_158 -> V_385 ,
V_120 -> V_86 ) ;
}
F_34 ( V_132 , & V_120 -> V_34 ) ;
F_71 ( V_14 , F_50 ( V_149 ) , V_393 ) ;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_399 ) & V_400 ) )
return;
do {
F_244 ( 1000 , 2000 ) ;
V_393 = F_37 ( V_14 , F_50 ( V_149 ) ) ;
} while ( -- V_392 && ! ( V_393 & V_394 ) );
if ( ! V_392 )
F_103 ( V_156 , L_84 , V_149 ) ;
}
static void F_245 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_401 , V_402 ;
T_4 V_403 = F_246 ( V_2 -> V_55 ) ;
if ( V_14 -> V_108 . type == V_109 )
return;
V_401 = F_37 ( V_14 , V_404 ) ;
V_401 |= V_405 ;
F_71 ( V_14 , V_404 , V_401 ) ;
if ( V_2 -> V_139 & V_406 ) {
V_402 = V_407 ;
if ( V_403 > 4 )
V_402 |= V_408 | V_409 ;
else if ( V_403 > 1 )
V_402 |= V_408 | V_410 ;
else if ( V_2 -> V_411 [ V_412 ] . V_413 == 4 )
V_402 |= V_414 ;
else
V_402 |= V_415 ;
} else {
if ( V_403 > 4 )
V_402 = V_408 | V_409 ;
else if ( V_403 > 1 )
V_402 = V_408 | V_410 ;
else
V_402 = V_416 ;
}
F_71 ( V_14 , V_417 , V_402 ) ;
if ( V_403 ) {
T_1 V_418 = F_37 ( V_14 , V_419 ) ;
V_418 |= V_420 ;
F_71 ( V_14 , V_419 , V_418 ) ;
}
V_401 &= ~ V_405 ;
F_71 ( V_14 , V_404 , V_401 ) ;
}
static void F_247 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_421 ;
T_1 V_48 ;
F_245 ( V_2 ) ;
if ( V_14 -> V_108 . type != V_109 ) {
V_421 = F_37 ( V_14 , V_422 ) ;
V_421 |= V_423 ;
F_71 ( V_14 , V_422 , V_421 ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_240 ( V_2 , V_2 -> V_58 [ V_48 ] ) ;
}
static void F_248 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_149 = V_120 -> V_149 ;
T_1 V_424 = F_37 ( V_14 , F_36 ( V_149 ) ) ;
V_424 |= V_425 ;
F_71 ( V_14 , F_36 ( V_149 ) , V_424 ) ;
}
static void F_249 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_149 = V_120 -> V_149 ;
T_1 V_424 = F_37 ( V_14 , F_36 ( V_149 ) ) ;
V_424 &= ~ V_425 ;
F_71 ( V_14 , F_36 ( V_149 ) , V_424 ) ;
}
static void F_250 ( struct V_1 * V_2 ,
struct V_57 * V_67 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_424 ;
T_4 V_149 = V_67 -> V_149 ;
if ( V_14 -> V_108 . type == V_109 ) {
T_2 V_117 = V_2 -> V_411 [ V_412 ] . V_117 ;
V_149 &= V_117 ;
}
V_424 = V_265 << V_426 ;
V_424 |= F_69 ( V_67 ) >> V_427 ;
V_424 |= V_428 ;
F_71 ( V_14 , F_36 ( V_149 ) , V_424 ) ;
}
T_1 F_251 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_108 . type < V_113 )
return 128 ;
else if ( V_2 -> V_139 & V_406 )
return 64 ;
else
return 512 ;
}
static void F_252 ( struct V_1 * V_2 )
{
T_1 V_48 , V_429 = F_251 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_430 = 0 ;
T_1 V_431 ;
T_4 * V_432 = V_2 -> V_433 ;
if ( V_2 -> V_14 . V_108 . type == V_109 )
V_431 = 0x11 ;
else
V_431 = 0x1 ;
for ( V_48 = 0 ; V_48 < V_429 ; V_48 ++ ) {
V_430 |= V_431 * V_432 [ V_48 ] << ( V_48 & 0x3 ) * 8 ;
if ( ( V_48 & 3 ) == 3 ) {
if ( V_48 < 128 )
F_71 ( V_14 , F_253 ( V_48 >> 2 ) , V_430 ) ;
else
F_71 ( V_14 , F_254 ( ( V_48 >> 2 ) - 32 ) ,
V_430 ) ;
V_430 = 0 ;
}
}
}
static void F_255 ( struct V_1 * V_2 )
{
T_1 V_48 , V_429 = F_251 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_434 = 0 ;
unsigned int V_435 = V_2 -> V_303 ;
for ( V_48 = 0 ; V_48 < V_429 ; V_48 ++ ) {
V_434 |= ( T_1 ) V_2 -> V_433 [ V_48 ] << ( V_48 & 0x3 ) * 8 ;
if ( ( V_48 & 3 ) == 3 ) {
F_71 ( V_14 , F_256 ( V_48 >> 2 , V_435 ) ,
V_434 ) ;
V_434 = 0 ;
}
}
}
static void F_257 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_48 , V_49 ;
T_1 V_429 = F_251 ( V_2 ) ;
T_2 V_436 = V_2 -> V_411 [ V_412 ] . V_413 ;
if ( ( V_2 -> V_139 & V_406 ) && ( V_436 < 2 ) )
V_436 = 2 ;
for ( V_48 = 0 ; V_48 < 10 ; V_48 ++ )
F_71 ( V_14 , F_258 ( V_48 ) , V_2 -> V_437 [ V_48 ] ) ;
memset ( V_2 -> V_433 , 0 , sizeof( V_2 -> V_433 ) ) ;
for ( V_48 = 0 , V_49 = 0 ; V_48 < V_429 ; V_48 ++ , V_49 ++ ) {
if ( V_49 == V_436 )
V_49 = 0 ;
V_2 -> V_433 [ V_48 ] = V_49 ;
}
F_252 ( V_2 ) ;
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_436 = V_2 -> V_411 [ V_412 ] . V_413 ;
unsigned int V_435 = V_2 -> V_303 ;
int V_48 , V_49 ;
for ( V_48 = 0 ; V_48 < 10 ; V_48 ++ )
F_71 ( V_14 , F_260 ( V_48 , V_435 ) ,
V_2 -> V_437 [ V_48 ] ) ;
for ( V_48 = 0 , V_49 = 0 ; V_48 < 64 ; V_48 ++ , V_49 ++ ) {
if ( V_49 == V_436 )
V_49 = 0 ;
V_2 -> V_433 [ V_48 ] = V_49 ;
}
F_255 ( V_2 ) ;
}
static void F_261 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_438 = 0 , V_439 = 0 , V_440 = 0 ;
T_1 V_441 ;
V_441 = F_37 ( V_14 , V_442 ) ;
V_441 |= V_443 ;
F_71 ( V_14 , V_442 , V_441 ) ;
if ( V_2 -> V_14 . V_108 . type == V_109 ) {
if ( V_2 -> V_411 [ V_412 ] . V_117 )
V_438 = V_444 ;
} else {
T_4 V_403 = F_246 ( V_2 -> V_55 ) ;
if ( V_2 -> V_139 & V_406 ) {
if ( V_403 > 4 )
V_438 = V_445 ;
else if ( V_403 > 1 )
V_438 = V_446 ;
else if ( V_2 -> V_411 [ V_412 ] . V_413 == 4 )
V_438 = V_447 ;
else
V_438 = V_448 ;
} else {
if ( V_403 > 4 )
V_438 = V_449 ;
else if ( V_403 > 1 )
V_438 = V_450 ;
else
V_438 = V_444 ;
}
}
V_439 |= V_451 |
V_452 |
V_453 |
V_454 ;
if ( V_2 -> V_154 & V_455 )
V_439 |= V_456 ;
if ( V_2 -> V_154 & V_457 )
V_439 |= V_458 ;
F_262 ( V_2 -> V_437 , sizeof( V_2 -> V_437 ) ) ;
if ( ( V_14 -> V_108 . type >= V_113 ) &&
( V_2 -> V_139 & V_406 ) ) {
unsigned int V_435 = V_2 -> V_303 ;
V_438 |= V_459 ;
F_71 ( V_14 , V_460 , V_438 ) ;
F_259 ( V_2 ) ;
V_440 = V_444 ;
V_440 |= V_439 ;
F_71 ( V_14 , F_263 ( V_435 ) , V_440 ) ;
} else {
F_257 ( V_2 ) ;
V_438 |= V_439 ;
F_71 ( V_14 , V_460 , V_438 ) ;
}
}
static void F_264 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_461 ;
T_4 V_149 = V_120 -> V_149 ;
if ( ! F_164 ( V_120 ) )
return;
V_461 = F_37 ( V_14 , F_265 ( V_149 ) ) ;
V_461 |= V_462 ;
V_461 |= V_463 ;
F_71 ( V_14 , F_265 ( V_149 ) , V_461 ) ;
}
static void F_266 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_392 = V_464 ;
T_1 V_465 ;
T_4 V_149 = V_120 -> V_149 ;
if ( F_22 ( V_14 -> V_39 ) )
return;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_399 ) & V_400 ) )
return;
do {
F_244 ( 1000 , 2000 ) ;
V_465 = F_37 ( V_14 , F_42 ( V_149 ) ) ;
} while ( -- V_392 && ! ( V_465 & V_466 ) );
if ( ! V_392 ) {
F_103 ( V_156 , L_85
L_86 , V_149 ) ;
}
}
void F_267 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_392 = V_464 ;
T_1 V_465 ;
T_4 V_149 = V_120 -> V_149 ;
if ( F_22 ( V_14 -> V_39 ) )
return;
V_465 = F_37 ( V_14 , F_42 ( V_149 ) ) ;
V_465 &= ~ V_466 ;
F_71 ( V_14 , F_42 ( V_149 ) , V_465 ) ;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_399 ) & V_400 ) )
return;
do {
F_268 ( 10 ) ;
V_465 = F_37 ( V_14 , F_42 ( V_149 ) ) ;
} while ( -- V_392 && ( V_465 & V_466 ) );
if ( ! V_392 ) {
F_103 ( V_156 , L_87
L_86 , V_149 ) ;
}
}
void F_269 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_467 = V_120 -> V_81 ;
T_1 V_465 ;
T_4 V_149 = V_120 -> V_149 ;
V_465 = F_37 ( V_14 , F_42 ( V_149 ) ) ;
F_267 ( V_2 , V_120 ) ;
F_71 ( V_14 , F_43 ( V_149 ) , ( V_467 & F_241 ( 32 ) ) ) ;
F_71 ( V_14 , F_44 ( V_149 ) , ( V_467 >> 32 ) ) ;
F_71 ( V_14 , F_39 ( V_149 ) ,
V_120 -> V_88 * sizeof( union V_68 ) ) ;
F_71 ( V_14 , F_40 ( V_149 ) , 0 ) ;
F_71 ( V_14 , F_41 ( V_149 ) , 0 ) ;
V_120 -> V_146 = V_2 -> V_395 + F_41 ( V_149 ) ;
F_250 ( V_2 , V_120 ) ;
F_264 ( V_2 , V_120 ) ;
if ( V_14 -> V_108 . type == V_109 ) {
V_465 &= ~ 0x3FFFFF ;
V_465 |= 0x080420 ;
}
V_465 |= V_466 ;
F_71 ( V_14 , F_42 ( V_149 ) , V_465 ) ;
F_266 ( V_2 , V_120 ) ;
F_142 ( V_120 , F_110 ( V_120 ) ) ;
}
static void F_270 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_436 = V_2 -> V_411 [ V_412 ] . V_413 ;
T_2 V_468 ;
T_1 V_469 = V_470 |
V_471 |
V_472 |
V_473 |
V_474 ;
if ( V_14 -> V_108 . type == V_109 )
return;
if ( V_436 > 3 )
V_469 |= 2 << 29 ;
else if ( V_436 > 1 )
V_469 |= 1 << 29 ;
F_271 (pool, &adapter->fwd_bitmask, 32 )
F_71 ( V_14 , F_272 ( F_273 ( V_468 ) ) , V_469 ) ;
}
static void F_274 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_177 , V_475 ;
T_1 V_476 , V_477 ;
int V_48 ;
if ( ! ( V_2 -> V_139 & V_406 ) )
return;
V_477 = F_37 ( V_14 , V_478 ) ;
V_477 |= V_479 ;
V_477 &= ~ V_480 ;
V_477 |= F_273 ( 0 ) << V_481 ;
V_477 |= V_482 ;
F_71 ( V_14 , V_478 , V_477 ) ;
V_475 = F_273 ( 0 ) % 32 ;
V_177 = ( F_273 ( 0 ) >= 32 ) ? 1 : 0 ;
F_71 ( V_14 , F_275 ( V_177 ) , ( ~ 0 ) << V_475 ) ;
F_71 ( V_14 , F_275 ( V_177 ^ 1 ) , V_177 - 1 ) ;
F_71 ( V_14 , F_276 ( V_177 ) , ( ~ 0 ) << V_475 ) ;
F_71 ( V_14 , F_276 ( V_177 ^ 1 ) , V_177 - 1 ) ;
if ( V_2 -> V_483 == V_484 )
F_71 ( V_14 , V_485 , V_486 ) ;
V_14 -> V_108 . V_336 . V_487 ( V_14 , 0 , F_273 ( 0 ) ) ;
switch ( V_2 -> V_411 [ V_488 ] . V_117 ) {
case V_489 :
V_476 = V_490 ;
break;
case V_491 :
V_476 = V_492 ;
break;
default:
V_476 = V_493 ;
break;
}
F_71 ( V_14 , V_494 , V_476 ) ;
V_14 -> V_108 . V_336 . V_495 ( V_14 , ( V_2 -> V_303 != 0 ) ,
V_2 -> V_303 ) ;
if ( V_14 -> V_108 . V_336 . V_496 )
F_71 ( V_14 , F_277 ( V_497 ) ,
( V_498 |
V_499 |
V_500 ) ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_303 ; V_48 ++ ) {
if ( ! V_2 -> V_501 [ V_48 ] . V_502 )
F_278 ( V_2 -> V_55 , V_48 , false ) ;
if ( V_14 -> V_108 . V_336 . V_496 )
V_14 -> V_108 . V_336 . V_496 ( V_14 , true , V_48 ) ;
F_279 ( V_2 -> V_55 , V_48 ,
V_2 -> V_501 [ V_48 ] . V_503 ) ;
}
}
static void F_280 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_55 = V_2 -> V_55 ;
int V_504 = V_55 -> V_291 + V_505 + V_506 ;
struct V_57 * V_67 ;
int V_48 ;
T_1 V_507 , V_508 ;
#ifdef F_175
if ( ( V_2 -> V_139 & V_509 ) &&
( V_504 < V_510 ) )
V_504 = V_510 ;
#endif
if ( V_504 < ( V_511 + V_506 ) )
V_504 = ( V_511 + V_506 ) ;
V_507 = F_37 ( V_14 , V_512 ) ;
if ( V_504 != ( V_507 >> V_513 ) ) {
V_507 &= ~ V_514 ;
V_507 |= V_504 << V_513 ;
F_71 ( V_14 , V_512 , V_507 ) ;
}
V_508 = F_37 ( V_14 , V_515 ) ;
V_508 |= V_516 ;
F_71 ( V_14 , V_515 , V_508 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_67 = V_2 -> V_67 [ V_48 ] ;
if ( V_2 -> V_154 & V_517 )
F_281 ( V_67 ) ;
else
F_282 ( V_67 ) ;
}
}
static void F_283 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_518 = F_37 ( V_14 , V_519 ) ;
switch ( V_14 -> V_108 . type ) {
case V_113 :
case V_114 :
case V_109 :
V_518 |= V_520 ;
break;
case V_111 :
case V_112 :
F_71 ( V_14 , V_521 ,
( V_522 | F_37 ( V_14 , V_521 ) ) ) ;
V_518 &= ~ V_523 ;
V_518 |= ( V_524 | V_525 ) ;
V_518 |= V_526 ;
break;
default:
return;
}
F_71 ( V_14 , V_519 , V_518 ) ;
}
static void F_284 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
T_1 V_182 , V_527 ;
V_14 -> V_108 . V_336 . V_528 ( V_14 ) ;
F_270 ( V_2 ) ;
F_283 ( V_2 ) ;
V_527 = F_37 ( V_14 , V_529 ) ;
V_527 &= ~ V_530 ;
if ( ! ( V_2 -> V_154 & V_517 ) )
V_527 |= V_530 ;
F_71 ( V_14 , V_529 , V_527 ) ;
F_261 ( V_2 ) ;
F_280 ( V_2 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
F_269 ( V_2 , V_2 -> V_67 [ V_48 ] ) ;
V_182 = F_37 ( V_14 , V_531 ) ;
if ( V_14 -> V_108 . type == V_109 )
V_182 |= V_532 ;
V_182 |= V_533 ;
V_14 -> V_108 . V_336 . V_534 ( V_14 , V_182 ) ;
}
static int F_285 ( struct V_54 * V_55 ,
T_12 V_535 , T_2 V_246 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_108 . V_336 . V_536 ( & V_2 -> V_14 , V_246 , F_273 ( 0 ) , true ) ;
F_242 ( V_246 , V_2 -> V_537 ) ;
return 0 ;
}
static int F_286 ( struct V_54 * V_55 ,
T_12 V_535 , T_2 V_246 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_108 . V_336 . V_536 ( & V_2 -> V_14 , V_246 , F_273 ( 0 ) , false ) ;
F_34 ( V_246 , V_2 -> V_537 ) ;
return 0 ;
}
static void F_287 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_538 ;
int V_48 , V_49 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_538 = F_37 ( V_14 , V_539 ) ;
V_538 &= ~ V_540 ;
F_71 ( V_14 , V_539 , V_538 ) ;
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
V_538 = F_37 ( V_14 , F_42 ( V_49 ) ) ;
V_538 &= ~ V_541 ;
F_71 ( V_14 , F_42 ( V_49 ) , V_538 ) ;
}
break;
default:
break;
}
}
static void F_288 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_538 ;
int V_48 , V_49 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_538 = F_37 ( V_14 , V_539 ) ;
V_538 |= V_540 ;
F_71 ( V_14 , V_539 , V_538 ) ;
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
V_538 = F_37 ( V_14 , F_42 ( V_49 ) ) ;
V_538 |= V_541 ;
F_71 ( V_14 , F_42 ( V_49 ) , V_538 ) ;
}
break;
default:
break;
}
}
static void F_289 ( struct V_1 * V_2 )
{
T_2 V_246 ;
F_285 ( V_2 -> V_55 , F_156 ( V_248 ) , 0 ) ;
F_271 (vid, adapter->active_vlans, VLAN_N_VID)
F_285 ( V_2 -> V_55 , F_156 ( V_248 ) , V_246 ) ;
}
static int F_290 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! F_57 ( V_55 ) )
return 0 ;
if ( V_14 -> V_108 . V_336 . V_542 )
V_14 -> V_108 . V_336 . V_542 ( V_14 , V_55 ) ;
else
return - V_543 ;
#ifdef F_291
F_292 ( V_2 ) ;
#endif
return F_293 ( V_55 ) ;
}
void F_294 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_544 ; V_48 ++ ) {
if ( V_2 -> V_545 [ V_48 ] . V_34 & V_546 )
V_14 -> V_108 . V_336 . V_547 ( V_14 , V_48 , V_2 -> V_545 [ V_48 ] . V_548 ,
V_2 -> V_545 [ V_48 ] . V_104 ,
V_549 ) ;
else
V_14 -> V_108 . V_336 . V_550 ( V_14 , V_48 ) ;
V_2 -> V_545 [ V_48 ] . V_34 &= ~ ( V_551 ) ;
}
}
static void F_295 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_544 ; V_48 ++ ) {
if ( V_2 -> V_545 [ V_48 ] . V_34 & V_551 ) {
if ( V_2 -> V_545 [ V_48 ] . V_34 &
V_546 )
V_14 -> V_108 . V_336 . V_547 ( V_14 , V_48 ,
V_2 -> V_545 [ V_48 ] . V_548 ,
V_2 -> V_545 [ V_48 ] . V_104 ,
V_549 ) ;
else
V_14 -> V_108 . V_336 . V_550 ( V_14 , V_48 ) ;
V_2 -> V_545 [ V_48 ] . V_34 &=
~ ( V_551 ) ;
}
}
}
static void F_296 ( struct V_1 * V_2 )
{
int V_48 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_544 ; V_48 ++ ) {
V_2 -> V_545 [ V_48 ] . V_34 |= V_551 ;
V_2 -> V_545 [ V_48 ] . V_34 &= ~ V_546 ;
F_297 ( V_2 -> V_545 [ V_48 ] . V_548 ) ;
V_2 -> V_545 [ V_48 ] . V_104 = 0 ;
}
F_295 ( V_2 ) ;
}
static int F_298 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 , V_88 = 0 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_544 ; V_48 ++ ) {
if ( V_2 -> V_545 [ V_48 ] . V_34 == 0 )
V_88 ++ ;
}
return V_88 ;
}
static void F_299 ( struct V_1 * V_2 ,
T_4 * V_548 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
memcpy ( & V_2 -> V_545 [ 0 ] . V_548 , V_548 , V_552 ) ;
V_2 -> V_545 [ 0 ] . V_104 = F_273 ( 0 ) ;
V_2 -> V_545 [ 0 ] . V_34 = ( V_553 |
V_546 ) ;
V_14 -> V_108 . V_336 . V_547 ( V_14 , 0 , V_2 -> V_545 [ 0 ] . V_548 ,
V_2 -> V_545 [ 0 ] . V_104 ,
V_549 ) ;
}
int F_300 ( struct V_1 * V_2 , T_4 * V_548 , T_2 V_104 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
if ( F_301 ( V_548 ) )
return - V_554 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_544 ; V_48 ++ ) {
if ( V_2 -> V_545 [ V_48 ] . V_34 & V_546 )
continue;
V_2 -> V_545 [ V_48 ] . V_34 |= ( V_551 |
V_546 ) ;
F_302 ( V_2 -> V_545 [ V_48 ] . V_548 , V_548 ) ;
V_2 -> V_545 [ V_48 ] . V_104 = V_104 ;
F_295 ( V_2 ) ;
return V_48 ;
}
return - V_543 ;
}
int F_303 ( struct V_1 * V_2 , T_4 * V_548 , T_2 V_104 )
{
int V_48 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_301 ( V_548 ) )
return - V_554 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_544 ; V_48 ++ ) {
if ( F_304 ( V_548 , V_2 -> V_545 [ V_48 ] . V_548 ) &&
V_2 -> V_545 [ V_48 ] . V_104 == V_104 ) {
V_2 -> V_545 [ V_48 ] . V_34 |= V_551 ;
V_2 -> V_545 [ V_48 ] . V_34 &= ~ V_546 ;
F_297 ( V_2 -> V_545 [ V_48 ] . V_548 ) ;
V_2 -> V_545 [ V_48 ] . V_104 = 0 ;
F_295 ( V_2 ) ;
return 0 ;
}
}
return - V_543 ;
}
static int F_305 ( struct V_54 * V_55 , int V_555 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_88 = 0 ;
if ( F_306 ( V_55 ) > F_298 ( V_2 ) )
return - V_543 ;
if ( ! F_307 ( V_55 ) ) {
struct V_556 * V_557 ;
F_308 (ha, netdev) {
F_303 ( V_2 , V_557 -> V_548 , V_555 ) ;
F_300 ( V_2 , V_557 -> V_548 , V_555 ) ;
V_88 ++ ;
}
}
return V_88 ;
}
void F_309 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_558 , V_559 = V_560 | V_561 ;
T_1 V_538 ;
int V_88 ;
V_558 = F_37 ( V_14 , V_562 ) ;
V_538 = F_37 ( V_14 , V_539 ) ;
V_558 &= ~ V_563 ;
V_558 |= V_564 ;
V_558 |= V_565 ;
V_558 |= V_566 ;
V_558 &= ~ ( V_567 | V_568 ) ;
V_538 &= ~ ( V_569 | V_570 ) ;
if ( V_55 -> V_139 & V_571 ) {
V_14 -> V_572 . V_573 = true ;
V_558 |= ( V_567 | V_568 ) ;
V_559 |= V_574 ;
if ( V_2 -> V_139 & ( V_575 |
V_406 ) )
V_538 |= ( V_569 | V_570 ) ;
} else {
if ( V_55 -> V_139 & V_576 ) {
V_558 |= V_568 ;
V_559 |= V_574 ;
}
V_538 |= V_569 ;
V_14 -> V_572 . V_573 = false ;
}
V_88 = F_305 ( V_55 , F_273 ( 0 ) ) ;
if ( V_88 < 0 ) {
V_558 |= V_567 ;
V_559 |= V_577 ;
}
V_88 = F_290 ( V_55 ) ;
if ( V_88 < 0 ) {
V_558 |= V_568 ;
V_559 |= V_574 ;
} else if ( V_88 ) {
V_559 |= V_578 ;
}
if ( V_14 -> V_108 . type != V_109 ) {
V_559 |= F_37 ( V_14 , F_310 ( F_273 ( 0 ) ) ) &
~ ( V_574 | V_578 |
V_577 ) ;
F_71 ( V_14 , F_310 ( F_273 ( 0 ) ) , V_559 ) ;
}
if ( V_2 -> V_55 -> V_196 & V_269 ) {
V_558 |= ( V_563 |
V_564 |
V_566 ) ;
V_558 &= ~ ( V_565 ) ;
}
F_71 ( V_14 , V_539 , V_538 ) ;
F_71 ( V_14 , V_562 , V_558 ) ;
if ( V_55 -> V_196 & V_244 )
F_288 ( V_2 ) ;
else
F_287 ( V_2 ) ;
}
static void F_311 ( struct V_1 * V_2 )
{
int V_579 ;
for ( V_579 = 0 ; V_579 < V_2 -> V_189 ; V_579 ++ ) {
F_312 ( V_2 -> V_158 [ V_579 ] ) ;
F_313 ( & V_2 -> V_158 [ V_579 ] -> V_250 ) ;
}
}
static void F_314 ( struct V_1 * V_2 )
{
int V_579 ;
for ( V_579 = 0 ; V_579 < V_2 -> V_189 ; V_579 ++ ) {
F_315 ( & V_2 -> V_158 [ V_579 ] -> V_250 ) ;
while ( ! F_316 ( V_2 -> V_158 [ V_579 ] ) ) {
F_51 ( L_88 , V_579 ) ;
F_244 ( 1000 , 20000 ) ;
}
}
}
static void F_317 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_504 = V_2 -> V_55 -> V_291 + V_505 + V_506 ;
if ( ! ( V_2 -> V_139 & V_140 ) ) {
if ( V_14 -> V_108 . type == V_109 )
F_318 ( V_2 -> V_55 , 65536 ) ;
return;
}
if ( V_14 -> V_108 . type == V_109 )
F_318 ( V_2 -> V_55 , 32768 ) ;
#ifdef F_175
if ( V_2 -> V_55 -> V_196 & V_580 )
V_504 = F_204 ( V_504 , V_510 ) ;
#endif
if ( V_2 -> V_581 & V_582 ) {
F_319 ( V_14 , & V_2 -> V_136 , V_504 ,
V_583 ) ;
F_319 ( V_14 , & V_2 -> V_136 , V_504 ,
V_584 ) ;
F_320 ( V_14 , & V_2 -> V_136 ) ;
} else if ( V_2 -> V_585 && V_2 -> V_138 ) {
F_321 ( & V_2 -> V_14 ,
V_2 -> V_585 ,
V_504 ) ;
F_322 ( & V_2 -> V_14 ,
V_2 -> V_138 -> V_135 ,
V_2 -> V_585 -> V_586 ) ;
}
if ( V_14 -> V_108 . type != V_109 ) {
T_1 V_587 = 0 ;
T_2 V_436 = V_2 -> V_411 [ V_412 ] . V_413 - 1 ;
while ( V_436 ) {
V_587 ++ ;
V_436 >>= 1 ;
}
F_71 ( V_14 , V_588 , V_587 * 0x11111111 ) ;
}
}
static int F_323 ( struct V_1 * V_2 , int V_589 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_73 = V_2 -> V_55 ;
int V_368 , V_134 , V_590 , V_591 ;
T_1 V_592 , V_593 ;
V_134 = V_368 = V_73 -> V_291 + V_505 + V_506 + V_594 ;
#ifdef F_175
if ( ( V_73 -> V_196 & V_580 ) &&
( V_134 < V_510 ) &&
( V_589 == F_324 ( V_2 ) ) )
V_134 = V_510 ;
#endif
switch ( V_14 -> V_108 . type ) {
case V_112 :
case V_113 :
case V_114 :
V_592 = F_325 ( V_368 , V_134 ) ;
break;
default:
V_592 = F_326 ( V_368 , V_134 ) ;
break;
}
if ( V_2 -> V_139 & V_406 )
V_592 += F_327 ( V_134 ) ;
V_590 = F_328 ( V_592 ) ;
V_593 = F_37 ( V_14 , F_329 ( V_589 ) ) >> 10 ;
V_591 = V_593 - V_590 ;
if ( V_591 < 0 ) {
F_93 ( V_156 , L_89
L_90
L_91 , V_589 ) ;
V_591 = V_134 + 1 ;
}
return V_591 ;
}
static int F_330 ( struct V_1 * V_2 , int V_589 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_73 = V_2 -> V_55 ;
int V_134 ;
T_1 V_592 ;
V_134 = V_73 -> V_291 + V_505 + V_506 ;
#ifdef F_175
if ( ( V_73 -> V_196 & V_580 ) &&
( V_134 < V_510 ) &&
( V_589 == F_86 ( V_73 , V_2 -> V_595 . V_596 ) ) )
V_134 = V_510 ;
#endif
switch ( V_14 -> V_108 . type ) {
case V_112 :
case V_113 :
case V_114 :
V_592 = F_331 ( V_134 ) ;
break;
default:
V_592 = F_332 ( V_134 ) ;
break;
}
return F_328 ( V_592 ) ;
}
static void F_333 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_597 = F_246 ( V_2 -> V_55 ) ;
int V_48 ;
if ( ! V_597 )
V_597 = 1 ;
for ( V_48 = 0 ; V_48 < V_597 ; V_48 ++ ) {
V_14 -> V_125 . V_598 [ V_48 ] = F_323 ( V_2 , V_48 ) ;
V_14 -> V_125 . V_599 [ V_48 ] = F_330 ( V_2 , V_48 ) ;
if ( V_14 -> V_125 . V_599 [ V_48 ] > V_14 -> V_125 . V_598 [ V_48 ] )
V_14 -> V_125 . V_599 [ V_48 ] = 0 ;
}
for (; V_48 < V_600 ; V_48 ++ )
V_14 -> V_125 . V_598 [ V_48 ] = 0 ;
}
static void F_334 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_601 ;
T_4 V_134 = F_246 ( V_2 -> V_55 ) ;
if ( V_2 -> V_139 & V_362 ||
V_2 -> V_139 & V_602 )
V_601 = 32 << V_2 -> V_603 ;
else
V_601 = 0 ;
V_14 -> V_108 . V_336 . V_604 ( V_14 , V_134 , V_601 , V_605 ) ;
F_333 ( V_2 ) ;
}
static void F_335 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_606 * V_607 ;
struct V_608 * V_609 ;
F_336 ( & V_2 -> V_610 ) ;
if ( ! F_337 ( & V_2 -> V_611 ) )
F_338 ( V_14 , & V_2 -> V_612 ) ;
F_339 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_340 ( V_14 ,
& V_609 -> V_609 ,
V_609 -> V_613 ,
( V_609 -> V_614 == V_615 ) ?
V_615 :
V_2 -> V_67 [ V_609 -> V_614 ] -> V_149 ) ;
}
F_341 ( & V_2 -> V_610 ) ;
}
static void F_342 ( struct V_54 * V_73 , unsigned int V_468 ,
struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_559 ;
V_559 = F_37 ( V_14 , F_310 ( V_468 ) ) ;
V_559 |= ( V_578 | V_560 | V_561 ) ;
V_559 &= ~ V_574 ;
if ( V_73 -> V_139 & V_576 ) {
V_559 |= V_574 ;
} else {
V_559 |= V_578 ;
V_14 -> V_108 . V_336 . V_542 ( V_14 , V_73 ) ;
}
F_305 ( V_2 -> V_55 , V_468 ) ;
F_71 ( V_14 , F_310 ( V_468 ) , V_559 ) ;
}
static void F_343 ( struct V_616 * V_617 )
{
struct V_1 * V_2 = V_617 -> V_148 ;
int V_436 = V_2 -> V_618 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_468 = V_617 -> V_468 ;
T_1 V_469 = V_470 |
V_471 |
V_472 |
V_473 |
V_474 ;
if ( V_14 -> V_108 . type == V_109 )
return;
if ( V_436 > 3 )
V_469 |= 2 << 29 ;
else if ( V_436 > 1 )
V_469 |= 1 << 29 ;
F_71 ( V_14 , F_272 ( F_273 ( V_468 ) ) , V_469 ) ;
}
static void F_344 ( struct V_57 * V_67 )
{
struct V_190 * V_73 = V_67 -> V_73 ;
unsigned long V_275 ;
T_2 V_48 ;
if ( ! V_67 -> V_71 )
return;
for ( V_48 = 0 ; V_48 < V_67 -> V_88 ; V_48 ++ ) {
struct V_70 * V_274 = & V_67 -> V_71 [ V_48 ] ;
if ( V_274 -> V_89 ) {
struct V_195 * V_89 = V_274 -> V_89 ;
if ( F_150 ( V_89 ) -> V_267 )
F_80 ( V_73 ,
F_150 ( V_89 ) -> V_81 ,
F_69 ( V_67 ) ,
V_231 ) ;
F_345 ( V_89 ) ;
V_274 -> V_89 = NULL ;
}
if ( ! V_274 -> V_98 )
continue;
F_80 ( V_73 , V_274 -> V_81 ,
F_139 ( V_67 ) , V_231 ) ;
F_141 ( V_274 -> V_98 , F_137 ( V_67 ) ) ;
V_274 -> V_98 = NULL ;
}
V_275 = sizeof( struct V_70 ) * V_67 -> V_88 ;
memset ( V_67 -> V_71 , 0 , V_275 ) ;
memset ( V_67 -> V_87 , 0 , V_67 -> V_275 ) ;
V_67 -> V_235 = 0 ;
V_67 -> V_79 = 0 ;
V_67 -> V_80 = 0 ;
}
static void F_346 ( struct V_616 * V_617 ,
struct V_57 * V_67 )
{
struct V_1 * V_2 = V_617 -> V_148 ;
int V_107 = V_67 -> V_86 + V_617 -> V_619 ;
F_267 ( V_2 , V_67 ) ;
F_244 ( 10000 , 20000 ) ;
F_214 ( V_2 , ( ( T_6 ) 1 << V_107 ) ) ;
F_344 ( V_67 ) ;
V_67 -> V_147 = NULL ;
}
static int F_347 ( struct V_54 * V_620 ,
struct V_616 * V_621 )
{
struct V_1 * V_2 = V_621 -> V_148 ;
unsigned int V_622 = V_621 -> V_619 ;
unsigned int V_623 = V_621 -> V_624 ;
int V_48 ;
F_348 ( V_620 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_618 ; V_48 ++ ) {
F_346 ( V_621 , V_2 -> V_67 [ V_622 + V_48 ] ) ;
V_2 -> V_67 [ V_622 + V_48 ] -> V_55 = V_2 -> V_55 ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_618 ; V_48 ++ ) {
V_2 -> V_58 [ V_623 + V_48 ] -> V_147 = NULL ;
V_2 -> V_58 [ V_623 + V_48 ] -> V_55 = V_2 -> V_55 ;
}
return 0 ;
}
static int F_349 ( struct V_54 * V_620 ,
struct V_616 * V_621 )
{
struct V_1 * V_2 = V_621 -> V_148 ;
unsigned int V_622 , V_623 , V_355 ;
int V_48 , V_625 , V_17 = 0 ;
if ( ! F_14 ( V_621 -> V_468 , & V_2 -> V_626 ) )
return 0 ;
V_625 = V_621 -> V_468 * V_2 -> V_618 ;
F_350 ( V_620 , L_92 ,
V_621 -> V_468 , V_2 -> V_627 ,
V_625 , V_625 + V_2 -> V_618 ,
V_2 -> V_626 ) ;
V_621 -> V_55 = V_620 ;
V_621 -> V_619 = V_622 = V_625 ;
V_621 -> V_624 = V_623 = V_625 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_618 ; V_48 ++ )
F_346 ( V_621 , V_2 -> V_67 [ V_622 + V_48 ] ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_618 ; V_48 ++ ) {
V_2 -> V_67 [ V_622 + V_48 ] -> V_55 = V_620 ;
V_2 -> V_67 [ V_622 + V_48 ] -> V_147 = V_621 ;
F_269 ( V_2 , V_2 -> V_67 [ V_622 + V_48 ] ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_618 ; V_48 ++ ) {
V_2 -> V_58 [ V_623 + V_48 ] -> V_55 = V_620 ;
V_2 -> V_58 [ V_623 + V_48 ] -> V_147 = V_621 ;
}
V_355 = F_351 (unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues) ;
V_17 = F_352 ( V_620 , V_355 ) ;
if ( V_17 )
goto V_628;
V_17 = F_353 ( V_620 , V_355 ) ;
if ( V_17 )
goto V_628;
if ( F_354 ( V_620 -> V_629 ) )
F_300 ( V_2 , V_620 -> V_629 , V_621 -> V_468 ) ;
F_343 ( V_621 ) ;
F_342 ( V_620 , V_621 -> V_468 , V_2 ) ;
return V_17 ;
V_628:
F_347 ( V_620 , V_621 ) ;
return V_17 ;
}
static void F_355 ( struct V_1 * V_2 )
{
struct V_54 * V_95 ;
struct V_630 * V_631 ;
int V_17 ;
F_356 (adapter->netdev, upper, iter) {
if ( F_357 ( V_95 ) ) {
struct V_632 * V_633 = F_89 ( V_95 ) ;
struct V_616 * V_617 = V_633 -> V_634 ;
if ( V_633 -> V_634 ) {
V_17 = F_349 ( V_95 , V_617 ) ;
if ( V_17 )
continue;
}
}
}
}
static void F_358 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
F_334 ( V_2 ) ;
#ifdef F_359
F_317 ( V_2 ) ;
#endif
F_274 ( V_2 ) ;
F_309 ( V_2 -> V_55 ) ;
F_289 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
V_14 -> V_108 . V_336 . V_635 ( V_14 ) ;
break;
default:
break;
}
if ( V_2 -> V_139 & V_362 ) {
F_360 ( & V_2 -> V_14 ,
V_2 -> V_603 ) ;
} else if ( V_2 -> V_139 & V_602 ) {
F_361 ( & V_2 -> V_14 ,
V_2 -> V_603 ) ;
F_335 ( V_2 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
V_14 -> V_108 . V_336 . V_636 ( V_14 ) ;
break;
default:
break;
}
#ifdef F_175
F_362 ( V_2 ) ;
#endif
F_247 ( V_2 ) ;
F_284 ( V_2 ) ;
F_355 ( V_2 ) ;
}
static inline bool F_363 ( struct V_15 * V_14 )
{
switch ( V_14 -> V_339 . type ) {
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
case V_647 :
case V_648 :
case V_649 :
return true ;
case V_650 :
if ( V_14 -> V_108 . type == V_109 )
return true ;
default:
return false ;
}
}
static void F_364 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_108 . type == V_109 )
V_2 -> V_154 |= V_651 ;
V_2 -> V_154 |= V_347 ;
}
static int F_365 ( struct V_15 * V_14 )
{
T_1 V_20 ;
bool V_652 , V_338 = false ;
T_1 V_653 = V_654 ;
if ( V_14 -> V_108 . V_336 . V_337 )
V_653 = V_14 -> V_108 . V_336 . V_337 ( V_14 , & V_20 , & V_338 , false ) ;
if ( V_653 )
return V_653 ;
V_20 = V_14 -> V_339 . V_655 ;
if ( ( ! V_20 ) && ( V_14 -> V_108 . V_336 . V_656 ) )
V_653 = V_14 -> V_108 . V_336 . V_656 ( V_14 , & V_20 ,
& V_652 ) ;
if ( V_653 )
return V_653 ;
if ( V_14 -> V_108 . V_336 . V_657 )
V_653 = V_14 -> V_108 . V_336 . V_657 ( V_14 , V_20 , V_338 ) ;
return V_653 ;
}
static void F_366 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_658 = 0 ;
if ( V_2 -> V_139 & V_386 ) {
V_658 = V_659 | V_660 |
V_661 ;
V_658 |= V_662 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
F_71 ( V_14 , V_663 , V_664 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
default:
F_71 ( V_14 , F_367 ( 0 ) , 0xFFFFFFFF ) ;
F_71 ( V_14 , F_367 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_71 ( V_14 , V_663 , V_664 ) ;
}
if ( V_2 -> V_139 & V_406 ) {
V_658 &= ~ V_665 ;
switch ( V_2 -> V_411 [ V_488 ] . V_117 ) {
case V_489 :
V_658 |= V_666 ;
break;
case V_491 :
V_658 |= V_667 ;
break;
default:
V_658 |= V_668 ;
break;
}
}
if ( V_2 -> V_154 & V_331 ) {
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_658 |= V_669 ;
break;
case V_112 :
V_658 |= V_358 ;
break;
default:
break;
}
}
if ( V_2 -> V_139 & V_342 )
V_658 |= V_670 ;
if ( V_14 -> V_108 . type == V_111 ) {
V_658 |= V_670 ;
V_658 |= V_671 ;
}
F_71 ( V_14 , V_672 , V_658 ) ;
}
static void F_368 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 ;
T_1 V_100 ;
F_72 ( V_2 ) ;
F_366 ( V_2 ) ;
if ( V_2 -> V_139 & V_386 )
F_199 ( V_2 ) ;
else
F_239 ( V_2 ) ;
if ( V_14 -> V_108 . V_336 . V_673 )
V_14 -> V_108 . V_336 . V_673 ( V_14 ) ;
F_33 () ;
F_34 ( V_33 , & V_2 -> V_34 ) ;
F_311 ( V_2 ) ;
if ( F_363 ( V_14 ) ) {
F_364 ( V_2 ) ;
} else {
V_17 = F_365 ( V_14 ) ;
if ( V_17 )
F_103 ( V_172 , L_93 , V_17 ) ;
}
F_37 ( V_14 , V_344 ) ;
F_216 ( V_2 , true , true ) ;
if ( V_2 -> V_139 & V_342 ) {
T_1 V_674 = F_37 ( V_14 , V_675 ) ;
if ( V_674 & V_676 )
F_206 ( V_156 , L_73 ) ;
}
V_2 -> V_139 |= V_350 ;
V_2 -> V_351 = V_171 ;
F_369 ( & V_2 -> V_677 , V_171 ) ;
V_100 = F_37 ( V_14 , V_101 ) ;
V_100 |= V_678 ;
F_71 ( V_14 , V_101 , V_100 ) ;
}
void F_370 ( struct V_1 * V_2 )
{
F_371 ( F_372 () ) ;
V_2 -> V_55 -> V_74 = V_171 ;
while ( F_15 ( V_679 , & V_2 -> V_34 ) )
F_244 ( 1000 , 2000 ) ;
F_373 ( V_2 ) ;
if ( V_2 -> V_139 & V_406 )
F_374 ( 2000 ) ;
F_375 ( V_2 ) ;
F_34 ( V_679 , & V_2 -> V_34 ) ;
}
void F_375 ( struct V_1 * V_2 )
{
F_358 ( V_2 ) ;
F_368 ( V_2 ) ;
}
void F_376 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_55 = V_2 -> V_55 ;
int V_17 ;
T_4 V_680 [ V_552 ] ;
if ( F_22 ( V_14 -> V_39 ) )
return;
while ( F_15 ( V_681 , & V_2 -> V_34 ) )
F_244 ( 1000 , 2000 ) ;
V_2 -> V_154 &= ~ ( V_651 |
V_347 ) ;
V_2 -> V_139 &= ~ V_348 ;
V_17 = V_14 -> V_108 . V_336 . V_682 ( V_14 ) ;
switch ( V_17 ) {
case 0 :
case V_683 :
case V_684 :
break;
case V_685 :
F_18 ( L_94 ) ;
break;
case V_686 :
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
F_34 ( V_681 , & V_2 -> V_34 ) ;
memcpy ( V_680 , & V_2 -> V_545 [ 0 ] . V_548 , V_55 -> V_687 ) ;
F_296 ( V_2 ) ;
F_299 ( V_2 , V_680 ) ;
if ( V_14 -> V_108 . V_688 )
V_14 -> V_108 . V_336 . V_689 ( V_14 , F_273 ( 0 ) ) ;
if ( F_14 ( V_690 , & V_2 -> V_34 ) )
F_377 ( V_2 ) ;
}
static void F_378 ( struct V_57 * V_58 )
{
struct V_59 * V_78 ;
unsigned long V_275 ;
T_2 V_48 ;
if ( ! V_58 -> V_78 )
return;
for ( V_48 = 0 ; V_48 < V_58 -> V_88 ; V_48 ++ ) {
V_78 = & V_58 -> V_78 [ V_48 ] ;
F_77 ( V_58 , V_78 ) ;
}
F_379 ( F_107 ( V_58 ) ) ;
V_275 = sizeof( struct V_59 ) * V_58 -> V_88 ;
memset ( V_58 -> V_78 , 0 , V_275 ) ;
memset ( V_58 -> V_87 , 0 , V_58 -> V_275 ) ;
V_58 -> V_80 = 0 ;
V_58 -> V_79 = 0 ;
}
static void F_380 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
F_344 ( V_2 -> V_67 [ V_48 ] ) ;
}
static void F_381 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_378 ( V_2 -> V_58 [ V_48 ] ) ;
}
static void F_382 ( struct V_1 * V_2 )
{
struct V_606 * V_607 ;
struct V_608 * V_609 ;
F_336 ( & V_2 -> V_610 ) ;
F_339 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_383 ( & V_609 -> V_691 ) ;
F_233 ( V_609 ) ;
}
V_2 -> V_692 = 0 ;
F_341 ( & V_2 -> V_610 ) ;
}
void F_373 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_95 ;
struct V_630 * V_631 ;
int V_48 ;
if ( F_15 ( V_33 , & V_2 -> V_34 ) )
return;
V_14 -> V_108 . V_336 . V_528 ( V_14 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
F_267 ( V_2 , V_2 -> V_67 [ V_48 ] ) ;
F_244 ( 10000 , 20000 ) ;
F_348 ( V_55 ) ;
F_384 ( V_55 ) ;
F_385 ( V_55 ) ;
F_356 (adapter->netdev, upper, iter) {
if ( F_357 ( V_95 ) ) {
struct V_632 * V_247 = F_89 ( V_95 ) ;
if ( V_247 -> V_634 ) {
F_348 ( V_95 ) ;
F_384 ( V_95 ) ;
F_385 ( V_95 ) ;
}
}
}
F_237 ( V_2 ) ;
F_314 ( V_2 ) ;
V_2 -> V_154 &= ~ ( V_363 |
V_155 ) ;
V_2 -> V_139 &= ~ V_350 ;
F_386 ( & V_2 -> V_677 ) ;
if ( V_2 -> V_303 ) {
F_71 ( & V_2 -> V_14 , V_305 , 0 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_303 ; V_48 ++ )
V_2 -> V_501 [ V_48 ] . V_693 = false ;
F_387 ( V_2 ) ;
F_388 ( V_2 ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
T_4 V_149 = V_2 -> V_58 [ V_48 ] -> V_149 ;
F_71 ( V_14 , F_50 ( V_149 ) , V_694 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_71 ( V_14 , V_422 ,
( F_37 ( V_14 , V_422 ) &
~ V_423 ) ) ;
break;
default:
break;
}
if ( ! F_389 ( V_2 -> V_9 ) )
F_376 ( V_2 ) ;
if ( V_14 -> V_108 . V_336 . V_695 )
V_14 -> V_108 . V_336 . V_695 ( V_14 ) ;
F_381 ( V_2 ) ;
F_380 ( V_2 ) ;
#ifdef F_224
F_123 ( V_2 ) ;
#endif
}
static void F_390 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
F_92 ( V_2 ) ;
}
static int F_391 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_200 , V_696 ;
T_1 V_697 ;
#ifdef F_359
int V_49 ;
struct V_698 * V_134 ;
#endif
V_14 -> V_699 = V_9 -> V_700 ;
V_14 -> V_21 = V_9 -> V_190 ;
V_14 -> V_701 = V_9 -> V_702 ;
V_14 -> V_703 = V_9 -> V_704 ;
V_14 -> V_705 = V_9 -> V_706 ;
V_200 = F_351 ( int , F_392 ( V_2 ) , F_393 () ) ;
V_2 -> V_411 [ V_412 ] . V_707 = V_200 ;
V_2 -> V_154 |= V_708 ;
V_2 -> V_154 |= V_517 ;
V_2 -> V_709 = V_710 ;
V_2 -> V_396 = 20 ;
V_696 = F_351 ( int , V_711 , F_393 () ) ;
V_2 -> V_411 [ V_712 ] . V_707 = V_696 ;
V_2 -> V_603 = V_713 ;
#ifdef F_224
V_2 -> V_139 |= V_192 ;
#endif
#ifdef F_175
V_2 -> V_139 |= V_714 ;
V_2 -> V_139 &= ~ V_509 ;
#ifdef F_359
V_2 -> V_595 . V_596 = V_715 ;
#endif
#endif
V_2 -> V_545 = F_394 ( sizeof( struct V_716 ) *
V_14 -> V_108 . V_544 ,
V_717 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_2 -> V_154 &= ~ V_708 ;
V_2 -> V_154 &= ~ V_517 ;
if ( V_14 -> V_21 == V_718 )
V_2 -> V_139 |= V_342 ;
V_2 -> V_709 = V_719 ;
V_2 -> V_411 [ V_712 ] . V_707 = 0 ;
V_2 -> V_396 = 0 ;
V_2 -> V_603 = 0 ;
#ifdef F_175
V_2 -> V_139 &= ~ V_714 ;
V_2 -> V_139 &= ~ V_509 ;
#ifdef F_359
V_2 -> V_595 . V_596 = 0 ;
#endif
#endif
break;
case V_111 :
if ( V_14 -> V_21 == V_333 )
V_2 -> V_154 |= V_331 ;
break;
case V_112 :
V_697 = F_37 ( V_14 , V_720 ) ;
if ( V_697 & V_721 )
V_2 -> V_154 |= V_331 ;
break;
case V_114 :
case V_113 :
#ifdef F_224
V_2 -> V_139 &= ~ V_192 ;
#endif
break;
default:
break;
}
#ifdef F_175
F_395 ( & V_2 -> V_595 . V_722 ) ;
#endif
F_395 ( & V_2 -> V_610 ) ;
#ifdef F_359
switch ( V_14 -> V_108 . type ) {
case V_112 :
case V_113 :
case V_114 :
V_2 -> V_136 . V_723 . V_724 = V_725 ;
V_2 -> V_136 . V_723 . V_726 = V_725 ;
break;
default:
V_2 -> V_136 . V_723 . V_724 = V_600 ;
V_2 -> V_136 . V_723 . V_726 = V_600 ;
break;
}
for ( V_49 = 0 ; V_49 < V_600 ; V_49 ++ ) {
V_134 = & V_2 -> V_136 . V_727 [ V_49 ] ;
V_134 -> V_728 [ V_583 ] . V_729 = 0 ;
V_134 -> V_728 [ V_583 ] . V_730 = 12 + ( V_49 & 1 ) ;
V_134 -> V_728 [ V_584 ] . V_729 = 0 ;
V_134 -> V_728 [ V_584 ] . V_730 = 12 + ( V_49 & 1 ) ;
V_134 -> V_731 = V_732 ;
}
V_134 = & V_2 -> V_136 . V_727 [ 0 ] ;
V_134 -> V_728 [ V_583 ] . V_733 = 0xFF ;
V_134 -> V_728 [ V_584 ] . V_733 = 0xFF ;
V_2 -> V_136 . V_734 [ V_583 ] [ 0 ] = 100 ;
V_2 -> V_136 . V_734 [ V_584 ] [ 0 ] = 100 ;
V_2 -> V_136 . V_137 = false ;
V_2 -> V_735 = 0x00 ;
V_2 -> V_581 = V_736 | V_582 ;
memcpy ( & V_2 -> V_737 , & V_2 -> V_136 ,
sizeof( V_2 -> V_737 ) ) ;
#endif
V_14 -> V_125 . V_738 = V_127 ;
V_14 -> V_125 . V_126 = V_127 ;
F_333 ( V_2 ) ;
V_14 -> V_125 . V_739 = V_740 ;
V_14 -> V_125 . V_741 = true ;
V_14 -> V_125 . V_742 = F_396 ( V_14 ) ;
#ifdef F_291
if ( V_743 > 0 )
F_11 ( L_102 ) ;
if ( V_14 -> V_108 . type != V_109 ) {
if ( V_743 > V_744 ) {
V_2 -> V_303 = 0 ;
F_11 ( L_103 ) ;
} else {
V_2 -> V_303 = V_743 ;
}
}
#endif
V_2 -> V_377 = 1 ;
V_2 -> V_745 = 1 ;
V_2 -> V_746 = V_747 ;
V_2 -> V_748 = V_749 ;
V_2 -> V_750 = V_751 ;
if ( F_397 ( V_14 ) ) {
F_18 ( L_104 ) ;
return - V_752 ;
}
F_242 ( 0 , & V_2 -> V_626 ) ;
F_242 ( V_33 , & V_2 -> V_34 ) ;
return 0 ;
}
int F_398 ( struct V_57 * V_58 )
{
struct V_190 * V_73 = V_58 -> V_73 ;
int V_753 = F_399 ( V_73 ) ;
int V_754 = - 1 ;
int V_275 ;
V_275 = sizeof( struct V_59 ) * V_58 -> V_88 ;
if ( V_58 -> V_158 )
V_754 = V_58 -> V_158 -> V_755 ;
V_58 -> V_78 = F_400 ( V_275 , V_754 ) ;
if ( ! V_58 -> V_78 )
V_58 -> V_78 = F_401 ( V_275 ) ;
if ( ! V_58 -> V_78 )
goto V_17;
F_402 ( & V_58 -> V_169 ) ;
V_58 -> V_275 = V_58 -> V_88 * sizeof( union V_61 ) ;
V_58 -> V_275 = F_169 ( V_58 -> V_275 , 4096 ) ;
F_403 ( V_73 , V_754 ) ;
V_58 -> V_87 = F_404 ( V_73 ,
V_58 -> V_275 ,
& V_58 -> V_81 ,
V_756 ) ;
F_403 ( V_73 , V_753 ) ;
if ( ! V_58 -> V_87 )
V_58 -> V_87 = F_404 ( V_73 , V_58 -> V_275 ,
& V_58 -> V_81 , V_756 ) ;
if ( ! V_58 -> V_87 )
goto V_17;
V_58 -> V_80 = 0 ;
V_58 -> V_79 = 0 ;
return 0 ;
V_17:
F_405 ( V_58 -> V_78 ) ;
V_58 -> V_78 = NULL ;
F_406 ( V_73 , L_105 ) ;
return - V_543 ;
}
static int F_407 ( struct V_1 * V_2 )
{
int V_48 , V_17 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
V_17 = F_398 ( V_2 -> V_58 [ V_48 ] ) ;
if ( ! V_17 )
continue;
F_103 ( V_172 , L_106 , V_48 ) ;
goto V_757;
}
return 0 ;
V_757:
while ( V_48 -- )
F_408 ( V_2 -> V_58 [ V_48 ] ) ;
return V_17 ;
}
int F_409 ( struct V_57 * V_67 )
{
struct V_190 * V_73 = V_67 -> V_73 ;
int V_753 = F_399 ( V_73 ) ;
int V_754 = - 1 ;
int V_275 ;
V_275 = sizeof( struct V_70 ) * V_67 -> V_88 ;
if ( V_67 -> V_158 )
V_754 = V_67 -> V_158 -> V_755 ;
V_67 -> V_71 = F_400 ( V_275 , V_754 ) ;
if ( ! V_67 -> V_71 )
V_67 -> V_71 = F_401 ( V_275 ) ;
if ( ! V_67 -> V_71 )
goto V_17;
F_402 ( & V_67 -> V_169 ) ;
V_67 -> V_275 = V_67 -> V_88 * sizeof( union V_68 ) ;
V_67 -> V_275 = F_169 ( V_67 -> V_275 , 4096 ) ;
F_403 ( V_73 , V_754 ) ;
V_67 -> V_87 = F_404 ( V_73 ,
V_67 -> V_275 ,
& V_67 -> V_81 ,
V_756 ) ;
F_403 ( V_73 , V_753 ) ;
if ( ! V_67 -> V_87 )
V_67 -> V_87 = F_404 ( V_73 , V_67 -> V_275 ,
& V_67 -> V_81 , V_756 ) ;
if ( ! V_67 -> V_87 )
goto V_17;
V_67 -> V_79 = 0 ;
V_67 -> V_80 = 0 ;
return 0 ;
V_17:
F_405 ( V_67 -> V_71 ) ;
V_67 -> V_71 = NULL ;
F_406 ( V_73 , L_107 ) ;
return - V_543 ;
}
static int F_410 ( struct V_1 * V_2 )
{
int V_48 , V_17 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_17 = F_409 ( V_2 -> V_67 [ V_48 ] ) ;
if ( ! V_17 )
continue;
F_103 ( V_172 , L_108 , V_48 ) ;
goto V_758;
}
#ifdef F_175
V_17 = F_411 ( V_2 ) ;
if ( ! V_17 )
#endif
return 0 ;
V_758:
while ( V_48 -- )
F_412 ( V_2 -> V_67 [ V_48 ] ) ;
return V_17 ;
}
void F_408 ( struct V_57 * V_58 )
{
F_378 ( V_58 ) ;
F_405 ( V_58 -> V_78 ) ;
V_58 -> V_78 = NULL ;
if ( ! V_58 -> V_87 )
return;
F_413 ( V_58 -> V_73 , V_58 -> V_275 ,
V_58 -> V_87 , V_58 -> V_81 ) ;
V_58 -> V_87 = NULL ;
}
static void F_414 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
if ( V_2 -> V_58 [ V_48 ] -> V_87 )
F_408 ( V_2 -> V_58 [ V_48 ] ) ;
}
void F_412 ( struct V_57 * V_67 )
{
F_344 ( V_67 ) ;
F_405 ( V_67 -> V_71 ) ;
V_67 -> V_71 = NULL ;
if ( ! V_67 -> V_87 )
return;
F_413 ( V_67 -> V_73 , V_67 -> V_275 ,
V_67 -> V_87 , V_67 -> V_81 ) ;
V_67 -> V_87 = NULL ;
}
static void F_415 ( struct V_1 * V_2 )
{
int V_48 ;
#ifdef F_175
F_416 ( V_2 ) ;
#endif
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
if ( V_2 -> V_67 [ V_48 ] -> V_87 )
F_412 ( V_2 -> V_67 [ V_48 ] ) ;
}
static int F_417 ( struct V_54 * V_55 , int V_759 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_504 = V_759 + V_505 + V_506 ;
if ( ( V_759 < 68 ) || ( V_504 > V_760 ) )
return - V_554 ;
if ( ( V_2 -> V_139 & V_406 ) &&
( V_2 -> V_14 . V_108 . type == V_111 ) &&
( V_504 > ( V_511 + V_506 ) ) )
F_93 ( V_172 , L_109 ) ;
F_105 ( V_172 , L_110 , V_55 -> V_291 , V_759 ) ;
V_55 -> V_291 = V_759 ;
if ( F_57 ( V_55 ) )
F_370 ( V_2 ) ;
return 0 ;
}
static int F_418 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_17 , V_355 ;
if ( F_14 ( V_761 , & V_2 -> V_34 ) )
return - V_762 ;
F_384 ( V_55 ) ;
V_17 = F_407 ( V_2 ) ;
if ( V_17 )
goto V_757;
V_17 = F_410 ( V_2 ) ;
if ( V_17 )
goto V_758;
F_358 ( V_2 ) ;
V_17 = F_235 ( V_2 ) ;
if ( V_17 )
goto V_763;
if ( V_2 -> V_627 > 1 )
V_355 = V_2 -> V_618 ;
else
V_355 = V_2 -> V_77 ;
V_17 = F_352 ( V_55 , V_355 ) ;
if ( V_17 )
goto V_764;
if ( V_2 -> V_627 > 1 &&
V_2 -> V_93 > V_765 )
V_355 = V_765 ;
else
V_355 = V_2 -> V_93 ;
V_17 = F_353 ( V_55 , V_355 ) ;
if ( V_17 )
goto V_764;
F_419 ( V_2 ) ;
F_368 ( V_2 ) ;
#if F_420 ( V_766 )
F_421 ( V_55 ) ;
#endif
return 0 ;
V_764:
F_236 ( V_2 ) ;
V_763:
F_415 ( V_2 ) ;
V_758:
F_414 ( V_2 ) ;
V_757:
F_376 ( V_2 ) ;
return V_17 ;
}
static void F_422 ( struct V_1 * V_2 )
{
F_423 ( V_2 ) ;
F_373 ( V_2 ) ;
F_236 ( V_2 ) ;
F_414 ( V_2 ) ;
F_415 ( V_2 ) ;
}
static int F_424 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
F_425 ( V_2 ) ;
F_422 ( V_2 ) ;
F_382 ( V_2 ) ;
F_70 ( V_2 ) ;
return 0 ;
}
static int F_426 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_427 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
T_1 V_17 ;
V_2 -> V_14 . V_39 = V_2 -> V_395 ;
F_428 ( V_9 , V_767 ) ;
F_429 ( V_9 ) ;
F_430 ( V_9 ) ;
V_17 = F_431 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_111 ) ;
return V_17 ;
}
F_33 () ;
F_34 ( V_768 , & V_2 -> V_34 ) ;
F_432 ( V_9 ) ;
F_433 ( V_9 , false ) ;
F_376 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_769 , ~ 0 ) ;
F_434 () ;
V_17 = F_435 ( V_2 ) ;
if ( ! V_17 && F_57 ( V_55 ) )
V_17 = F_418 ( V_55 ) ;
F_436 () ;
if ( V_17 )
return V_17 ;
F_437 ( V_55 ) ;
return 0 ;
}
static int F_438 ( struct V_5 * V_9 , bool * V_770 )
{
struct V_1 * V_2 = F_427 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_771 , V_558 ;
T_1 V_772 = V_2 -> V_773 ;
#ifdef F_439
int V_774 = 0 ;
#endif
F_440 ( V_55 ) ;
F_434 () ;
if ( F_57 ( V_55 ) )
F_422 ( V_2 ) ;
F_436 () ;
F_441 ( V_2 ) ;
#ifdef F_439
V_774 = F_430 ( V_9 ) ;
if ( V_774 )
return V_774 ;
#endif
if ( V_14 -> V_108 . V_336 . V_775 )
V_14 -> V_108 . V_336 . V_775 ( V_14 ) ;
if ( V_772 ) {
F_309 ( V_55 ) ;
if ( V_14 -> V_108 . V_336 . V_673 )
V_14 -> V_108 . V_336 . V_673 ( V_14 ) ;
if ( V_772 & V_776 ) {
V_558 = F_37 ( V_14 , V_562 ) ;
V_558 |= V_568 ;
F_71 ( V_14 , V_562 , V_558 ) ;
}
V_771 = F_37 ( V_14 , V_777 ) ;
V_771 |= V_778 ;
F_71 ( V_14 , V_777 , V_771 ) ;
F_71 ( V_14 , V_779 , V_772 ) ;
} else {
F_71 ( V_14 , V_780 , 0 ) ;
F_71 ( V_14 , V_779 , 0 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_109 :
F_433 ( V_9 , false ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_433 ( V_9 , ! ! V_772 ) ;
break;
default:
break;
}
* V_770 = ! ! V_772 ;
F_70 ( V_2 ) ;
if ( ! F_15 ( V_768 , & V_2 -> V_34 ) )
F_442 ( V_9 ) ;
return 0 ;
}
static int F_443 ( struct V_5 * V_9 , T_13 V_34 )
{
int V_774 ;
bool V_781 ;
V_774 = F_438 ( V_9 , & V_781 ) ;
if ( V_774 )
return V_774 ;
if ( V_781 ) {
F_444 ( V_9 ) ;
} else {
F_433 ( V_9 , false ) ;
F_428 ( V_9 , V_782 ) ;
}
return 0 ;
}
static void F_445 ( struct V_5 * V_9 )
{
bool V_781 ;
F_438 ( V_9 , & V_781 ) ;
if ( V_783 == V_784 ) {
F_433 ( V_9 , V_781 ) ;
F_428 ( V_9 , V_782 ) ;
}
}
void F_446 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_122 * V_123 = & V_2 -> V_124 ;
T_6 V_785 = 0 ;
T_1 V_48 , V_786 = 0 , V_787 , V_788 , V_789 , V_790 , V_791 ;
T_6 V_259 = 0 , V_174 = 0 , V_792 = 0 ;
T_6 V_230 = 0 , V_284 = 0 ;
T_6 V_170 = 0 , V_144 = 0 , V_793 = 0 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_679 , & V_2 -> V_34 ) )
return;
if ( V_2 -> V_154 & V_517 ) {
T_6 V_241 = 0 ;
T_6 V_242 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_241 += V_2 -> V_67 [ V_48 ] -> V_219 . V_241 ;
V_242 += V_2 -> V_67 [ V_48 ] -> V_219 . V_242 ;
}
V_2 -> V_794 = V_241 ;
V_2 -> V_795 = V_242 ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_67 = V_2 -> V_67 [ V_48 ] ;
V_259 += V_67 -> V_219 . V_259 ;
V_230 += V_67 -> V_219 . V_230 ;
V_284 += V_67 -> V_219 . V_284 ;
V_793 += V_67 -> V_219 . V_220 ;
V_170 += V_67 -> V_124 . V_170 ;
V_144 += V_67 -> V_124 . V_144 ;
}
V_2 -> V_259 = V_259 ;
V_2 -> V_230 = V_230 ;
V_2 -> V_284 = V_284 ;
V_2 -> V_793 = V_793 ;
V_55 -> V_124 . V_796 = V_170 ;
V_55 -> V_124 . V_797 = V_144 ;
V_170 = 0 ;
V_144 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_58 = V_2 -> V_58 [ V_48 ] ;
V_174 += V_58 -> V_152 . V_174 ;
V_792 += V_58 -> V_152 . V_792 ;
V_170 += V_58 -> V_124 . V_170 ;
V_144 += V_58 -> V_124 . V_144 ;
}
V_2 -> V_174 = V_174 ;
V_2 -> V_792 = V_792 ;
V_55 -> V_124 . V_798 = V_170 ;
V_55 -> V_124 . V_799 = V_144 ;
V_123 -> V_800 += F_37 ( V_14 , V_801 ) ;
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ ) {
V_787 = F_37 ( V_14 , F_447 ( V_48 ) ) ;
V_786 += V_787 ;
V_123 -> V_787 [ V_48 ] += V_787 ;
V_785 += V_123 -> V_787 [ V_48 ] ;
V_123 -> V_802 [ V_48 ] += F_37 ( V_14 , F_448 ( V_48 ) ) ;
V_123 -> V_803 [ V_48 ] += F_37 ( V_14 , F_449 ( V_48 ) ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_123 -> V_804 [ V_48 ] += F_37 ( V_14 , F_450 ( V_48 ) ) ;
V_123 -> V_805 [ V_48 ] += F_37 ( V_14 , F_451 ( V_48 ) ) ;
V_123 -> V_806 [ V_48 ] += F_37 ( V_14 , F_452 ( V_48 ) ) ;
V_123 -> V_807 [ V_48 ] +=
F_37 ( V_14 , F_453 ( V_48 ) ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_123 -> V_807 [ V_48 ] +=
F_37 ( V_14 , F_454 ( V_48 ) ) ;
break;
default:
break;
}
}
for ( V_48 = 0 ; V_48 < 16 ; V_48 ++ ) {
V_123 -> V_808 [ V_48 ] += F_37 ( V_14 , F_455 ( V_48 ) ) ;
V_123 -> V_809 [ V_48 ] += F_37 ( V_14 , F_456 ( V_48 ) ) ;
if ( ( V_14 -> V_108 . type == V_111 ) ||
( V_14 -> V_108 . type == V_112 ) ||
( V_14 -> V_108 . type == V_113 ) ||
( V_14 -> V_108 . type == V_114 ) ) {
V_123 -> V_805 [ V_48 ] += F_37 ( V_14 , F_457 ( V_48 ) ) ;
F_37 ( V_14 , F_458 ( V_48 ) ) ;
V_123 -> V_806 [ V_48 ] += F_37 ( V_14 , F_459 ( V_48 ) ) ;
F_37 ( V_14 , F_460 ( V_48 ) ) ;
}
}
V_123 -> V_810 += F_37 ( V_14 , V_811 ) ;
V_123 -> V_810 -= V_786 ;
F_83 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_123 -> V_812 += F_37 ( V_14 , V_813 ) ;
V_123 -> V_814 += F_37 ( V_14 , V_815 ) ;
V_123 -> V_816 += F_37 ( V_14 , V_817 ) ;
V_123 -> V_818 += F_37 ( V_14 , V_819 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
V_123 -> V_820 += F_37 ( V_14 , V_821 ) ;
V_123 -> V_822 += F_37 ( V_14 , V_823 ) ;
V_123 -> V_824 += F_37 ( V_14 , V_825 ) ;
V_123 -> V_826 += F_37 ( V_14 , V_827 ) ;
case V_111 :
for ( V_48 = 0 ; V_48 < 16 ; V_48 ++ )
V_2 -> V_828 +=
F_37 ( V_14 , F_461 ( V_48 ) ) ;
V_123 -> V_814 += F_37 ( V_14 , V_829 ) ;
F_37 ( V_14 , V_815 ) ;
V_123 -> V_816 += F_37 ( V_14 , V_830 ) ;
F_37 ( V_14 , V_817 ) ;
V_123 -> V_818 += F_37 ( V_14 , V_831 ) ;
F_37 ( V_14 , V_819 ) ;
V_123 -> V_812 += F_37 ( V_14 , V_832 ) ;
V_123 -> V_833 += F_37 ( V_14 , V_834 ) ;
V_123 -> V_835 += F_37 ( V_14 , V_836 ) ;
#ifdef F_175
V_123 -> V_837 += F_37 ( V_14 , V_838 ) ;
V_123 -> V_839 += F_37 ( V_14 , V_840 ) ;
V_123 -> V_841 += F_37 ( V_14 , V_842 ) ;
V_123 -> V_843 += F_37 ( V_14 , V_844 ) ;
V_123 -> V_845 += F_37 ( V_14 , V_846 ) ;
V_123 -> V_847 += F_37 ( V_14 , V_848 ) ;
if ( V_2 -> V_595 . V_849 ) {
struct V_850 * V_595 = & V_2 -> V_595 ;
struct V_851 * V_849 ;
unsigned int V_175 ;
T_6 V_852 = 0 , V_853 = 0 ;
F_462 (cpu) {
V_849 = F_463 ( V_595 -> V_849 , V_175 ) ;
V_852 += V_849 -> V_852 ;
V_853 += V_849 -> V_853 ;
}
V_123 -> V_854 = V_852 ;
V_123 -> V_855 = V_853 ;
}
#endif
break;
default:
break;
}
V_788 = F_37 ( V_14 , V_856 ) ;
V_123 -> V_788 += V_788 ;
V_123 -> V_857 += F_37 ( V_14 , V_858 ) ;
if ( V_14 -> V_108 . type == V_109 )
V_123 -> V_857 -= V_788 ;
V_123 -> V_859 += F_37 ( V_14 , V_860 ) ;
V_123 -> V_861 += F_37 ( V_14 , V_862 ) ;
V_123 -> V_863 += F_37 ( V_14 , V_864 ) ;
V_123 -> V_865 += F_37 ( V_14 , V_866 ) ;
V_123 -> V_867 += F_37 ( V_14 , V_868 ) ;
V_123 -> V_869 += F_37 ( V_14 , V_870 ) ;
V_123 -> V_871 += F_37 ( V_14 , V_872 ) ;
V_123 -> V_873 += F_37 ( V_14 , V_874 ) ;
V_789 = F_37 ( V_14 , V_875 ) ;
V_123 -> V_876 += V_789 ;
V_790 = F_37 ( V_14 , V_877 ) ;
V_123 -> V_878 += V_790 ;
V_123 -> V_879 += F_37 ( V_14 , V_880 ) ;
V_123 -> V_881 += F_37 ( V_14 , V_882 ) ;
V_791 = V_789 + V_790 ;
V_123 -> V_879 -= V_791 ;
V_123 -> V_881 -= V_791 ;
V_123 -> V_816 -= ( V_791 * ( V_883 + V_506 ) ) ;
V_123 -> V_884 += F_37 ( V_14 , V_885 ) ;
V_123 -> V_886 += F_37 ( V_14 , V_887 ) ;
V_123 -> V_888 += F_37 ( V_14 , V_889 ) ;
V_123 -> V_890 += F_37 ( V_14 , V_891 ) ;
V_123 -> V_892 += F_37 ( V_14 , V_893 ) ;
V_123 -> V_892 -= V_791 ;
V_123 -> V_894 += F_37 ( V_14 , V_895 ) ;
V_123 -> V_896 += F_37 ( V_14 , V_897 ) ;
V_123 -> V_898 += F_37 ( V_14 , V_899 ) ;
V_123 -> V_900 += F_37 ( V_14 , V_901 ) ;
V_123 -> V_902 += F_37 ( V_14 , V_903 ) ;
V_123 -> V_904 += F_37 ( V_14 , V_905 ) ;
V_55 -> V_124 . V_906 = V_123 -> V_857 ;
V_55 -> V_124 . V_907 = V_123 -> V_800 + V_123 -> V_873 ;
V_55 -> V_124 . V_908 = 0 ;
V_55 -> V_124 . V_909 = V_123 -> V_873 ;
V_55 -> V_124 . V_910 = V_123 -> V_800 ;
V_55 -> V_124 . V_911 = V_785 ;
}
static void F_464 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
if ( ! ( V_2 -> V_154 & V_363 ) )
return;
V_2 -> V_154 &= ~ V_363 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
if ( ! ( V_2 -> V_139 & V_362 ) )
return;
V_2 -> V_912 ++ ;
if ( F_465 ( V_14 ) == 0 ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_242 ( V_371 ,
& ( V_2 -> V_58 [ V_48 ] -> V_34 ) ) ;
F_71 ( V_14 , V_354 , V_364 ) ;
} else {
F_103 ( V_172 , L_112
L_113 ) ;
}
}
static void F_466 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_913 = 0 ;
int V_48 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_679 , & V_2 -> V_34 ) )
return;
if ( F_109 ( V_2 -> V_55 ) ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_467 ( V_2 -> V_58 [ V_48 ] ) ;
}
if ( ! ( V_2 -> V_139 & V_386 ) ) {
F_71 ( V_14 , V_119 ,
( V_914 | V_915 ) ) ;
} else {
for ( V_48 = 0 ; V_48 < V_2 -> V_189 ; V_48 ++ ) {
struct V_157 * V_916 = V_2 -> V_158 [ V_48 ] ;
if ( V_916 -> V_295 . V_120 || V_916 -> V_162 . V_120 )
V_913 |= ( ( T_6 ) 1 << V_48 ) ;
}
}
F_75 ( V_2 , V_913 ) ;
}
static void F_468 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_917 = V_2 -> V_917 ;
bool V_338 = V_2 -> V_338 ;
bool V_135 = V_2 -> V_136 . V_137 ;
if ( ! ( V_2 -> V_139 & V_350 ) )
return;
if ( V_14 -> V_108 . V_336 . V_337 ) {
V_14 -> V_108 . V_336 . V_337 ( V_14 , & V_917 , & V_338 , false ) ;
} else {
V_917 = V_918 ;
V_338 = true ;
}
if ( V_2 -> V_138 )
V_135 |= ! ! ( V_2 -> V_138 -> V_135 ) ;
if ( V_338 && ! ( ( V_2 -> V_139 & V_140 ) && V_135 ) ) {
V_14 -> V_108 . V_336 . V_919 ( V_14 ) ;
F_469 ( V_2 ) ;
}
if ( V_338 ||
F_470 ( V_171 , ( V_2 -> V_351 +
V_920 ) ) ) {
V_2 -> V_139 &= ~ V_350 ;
F_71 ( V_14 , V_354 , V_353 ) ;
F_211 ( V_14 ) ;
}
V_2 -> V_338 = V_338 ;
V_2 -> V_917 = V_917 ;
}
static void F_471 ( struct V_1 * V_2 )
{
#ifdef F_359
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_921 V_922 = {
. V_923 = V_924 ,
. V_249 = 0 ,
} ;
T_4 V_596 = 0 ;
if ( V_2 -> V_581 & V_925 )
V_596 = F_472 ( V_55 , & V_922 ) ;
V_2 -> V_926 = ( V_596 > 1 ) ? ( F_473 ( V_596 ) - 1 ) : 0 ;
#endif
}
static void F_474 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_95 ;
struct V_630 * V_631 ;
T_1 V_917 = V_2 -> V_917 ;
bool V_927 , V_928 ;
if ( F_109 ( V_55 ) )
return;
V_2 -> V_154 &= ~ V_651 ;
switch ( V_14 -> V_108 . type ) {
case V_109 : {
T_1 V_929 = F_37 ( V_14 , V_562 ) ;
T_1 V_930 = F_37 ( V_14 , V_931 ) ;
V_927 = ! ! ( V_929 & V_932 ) ;
V_928 = ! ! ( V_930 & V_933 ) ;
}
break;
case V_112 :
case V_113 :
case V_114 :
case V_111 : {
T_1 V_934 = F_37 ( V_14 , V_935 ) ;
T_1 V_936 = F_37 ( V_14 , V_937 ) ;
V_927 = ! ! ( V_934 & V_938 ) ;
V_928 = ! ! ( V_936 & V_939 ) ;
}
break;
default:
V_928 = false ;
V_927 = false ;
break;
}
V_2 -> V_940 = V_171 ;
if ( F_14 ( V_690 , & V_2 -> V_34 ) )
F_475 ( V_2 ) ;
F_105 ( V_156 , L_114 ,
( V_917 == V_918 ?
L_115 :
( V_917 == V_941 ?
L_116 :
( V_917 == V_942 ?
L_117 :
L_118 ) ) ) ,
( ( V_927 && V_928 ) ? L_119 :
( V_927 ? L_120 :
( V_928 ? L_121 : L_122 ) ) ) ) ;
F_476 ( V_55 ) ;
F_477 ( V_2 ) ;
F_478 ( V_2 -> V_55 ) ;
F_434 () ;
F_356 (adapter->netdev, upper, iter) {
if ( F_357 ( V_95 ) ) {
struct V_632 * V_247 = F_89 ( V_95 ) ;
if ( V_247 -> V_634 )
F_478 ( V_95 ) ;
}
}
F_436 () ;
F_471 ( V_2 ) ;
F_387 ( V_2 ) ;
}
static void F_479 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_338 = false ;
V_2 -> V_917 = 0 ;
if ( ! F_109 ( V_55 ) )
return;
if ( F_363 ( V_14 ) && V_14 -> V_108 . type == V_109 )
V_2 -> V_154 |= V_651 ;
if ( F_14 ( V_690 , & V_2 -> V_34 ) )
F_475 ( V_2 ) ;
F_105 ( V_156 , L_123 ) ;
F_384 ( V_55 ) ;
F_387 ( V_2 ) ;
}
static bool F_480 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_58 = V_2 -> V_58 [ V_48 ] ;
if ( V_58 -> V_80 != V_58 -> V_79 )
return true ;
}
return false ;
}
static bool F_481 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_943 * V_944 = & V_2 -> V_411 [ V_488 ] ;
T_1 V_945 = F_482 ( 1 , ~ V_944 -> V_117 ) ;
int V_48 , V_49 ;
if ( ! V_2 -> V_303 )
return false ;
if ( V_14 -> V_108 . type >= V_113 )
return false ;
for ( V_48 = 0 ; V_48 < V_2 -> V_303 ; V_48 ++ ) {
for ( V_49 = 0 ; V_49 < V_945 ; V_49 ++ ) {
T_1 V_946 , V_947 ;
V_946 = F_37 ( V_14 , F_483 ( V_945 , V_48 , V_49 ) ) ;
V_947 = F_37 ( V_14 , F_484 ( V_945 , V_48 , V_49 ) ) ;
if ( V_946 != V_947 )
return true ;
}
}
return false ;
}
static void F_485 ( struct V_1 * V_2 )
{
if ( ! F_109 ( V_2 -> V_55 ) ) {
if ( F_480 ( V_2 ) ||
F_481 ( V_2 ) ) {
F_93 ( V_156 , L_124 ) ;
V_2 -> V_154 |= V_155 ;
}
}
}
static inline void F_486 ( struct V_1 * V_2 ,
struct V_5 * V_948 )
{
if ( ! F_487 ( V_948 ) )
F_11 ( L_125 ) ;
F_18 ( L_126 , F_488 ( V_948 ) ) ;
F_489 ( V_948 , V_949 , V_950 ) ;
F_374 ( 100 ) ;
}
static void F_490 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
struct V_5 * V_948 ;
T_1 V_951 ;
int V_952 ;
unsigned short V_953 ;
if ( ! ( F_109 ( V_2 -> V_55 ) ) )
return;
V_951 = F_37 ( V_14 , V_954 ) ;
if ( V_951 )
return;
if ( ! V_9 )
return;
V_952 = F_491 ( V_9 , V_955 ) ;
if ( ! V_952 )
return;
F_25 ( V_9 , V_952 + V_956 , & V_953 ) ;
V_948 = F_492 ( V_9 -> V_700 , V_953 , NULL ) ;
while ( V_948 ) {
if ( V_948 -> V_957 && ( V_948 -> V_958 == V_9 ) ) {
T_2 V_959 ;
F_25 ( V_948 , V_960 , & V_959 ) ;
if ( V_959 & V_961 )
F_486 ( V_2 , V_948 ) ;
}
V_948 = F_492 ( V_9 -> V_700 , V_953 , V_948 ) ;
}
}
static void F_493 ( struct V_1 * V_2 )
{
T_1 V_962 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ||
V_2 -> V_303 == 0 )
return;
V_962 = F_37 ( & V_2 -> V_14 , V_963 ) ;
if ( ! V_962 )
return;
F_93 ( V_156 , L_127 , V_962 ) ;
}
static void F_493 ( struct V_1 T_14 * V_2 )
{
}
static void
F_490 ( struct V_1 T_14 * V_2 )
{
}
static void F_494 ( struct V_1 * V_2 )
{
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_679 , & V_2 -> V_34 ) )
return;
F_468 ( V_2 ) ;
if ( V_2 -> V_338 )
F_474 ( V_2 ) ;
else
F_479 ( V_2 ) ;
F_490 ( V_2 ) ;
F_493 ( V_2 ) ;
F_446 ( V_2 ) ;
F_485 ( V_2 ) ;
}
static void F_495 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_3 V_17 ;
if ( ! ( V_2 -> V_154 & V_651 ) &&
! ( V_2 -> V_154 & V_347 ) )
return;
if ( F_15 ( V_681 , & V_2 -> V_34 ) )
return;
V_17 = V_14 -> V_339 . V_336 . V_964 ( V_14 ) ;
if ( V_17 == V_684 )
goto V_965;
if ( V_17 == V_683 ) {
V_2 -> V_154 |= V_347 ;
}
if ( V_17 )
goto V_965;
if ( ! ( V_2 -> V_154 & V_347 ) )
goto V_965;
V_2 -> V_154 &= ~ V_347 ;
if ( V_14 -> V_108 . type == V_109 )
V_17 = V_14 -> V_339 . V_336 . V_966 ( V_14 ) ;
else
V_17 = V_14 -> V_108 . V_336 . V_967 ( V_14 ) ;
if ( V_17 == V_684 )
goto V_965;
V_2 -> V_139 |= V_348 ;
F_105 ( V_172 , L_128 , V_14 -> V_339 . V_968 ) ;
V_965:
F_34 ( V_681 , & V_2 -> V_34 ) ;
if ( ( V_17 == V_684 ) &&
( V_2 -> V_55 -> V_969 == V_970 ) ) {
F_18 ( L_129
L_130 ) ;
F_18 ( L_131
L_132 ) ;
F_496 ( V_2 -> V_55 ) ;
}
}
static void F_497 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_20 ;
bool V_652 = false ;
if ( ! ( V_2 -> V_139 & V_348 ) )
return;
if ( F_15 ( V_681 , & V_2 -> V_34 ) )
return;
V_2 -> V_139 &= ~ V_348 ;
V_20 = V_14 -> V_339 . V_655 ;
if ( ( ! V_20 ) && ( V_14 -> V_108 . V_336 . V_656 ) ) {
V_14 -> V_108 . V_336 . V_656 ( V_14 , & V_20 , & V_652 ) ;
if ( ! V_652 ) {
if ( V_20 & V_918 )
V_20 = V_918 ;
}
}
if ( V_14 -> V_108 . V_336 . V_657 )
V_14 -> V_108 . V_336 . V_657 ( V_14 , V_20 , true ) ;
V_2 -> V_139 |= V_350 ;
V_2 -> V_351 = V_171 ;
F_34 ( V_681 , & V_2 -> V_34 ) ;
}
static void F_498 ( unsigned long V_92 )
{
struct V_1 * V_2 = (struct V_1 * ) V_92 ;
unsigned long V_971 ;
if ( V_2 -> V_139 & V_350 )
V_971 = V_972 / 10 ;
else
V_971 = V_972 * 2 ;
F_369 ( & V_2 -> V_677 , V_971 + V_171 ) ;
F_13 ( V_2 ) ;
}
static void F_499 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_154 & V_155 ) )
return;
V_2 -> V_154 &= ~ V_155 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_679 , & V_2 -> V_34 ) )
return;
F_54 ( V_2 ) ;
F_500 ( V_2 -> V_55 , L_133 ) ;
V_2 -> V_173 ++ ;
F_434 () ;
F_370 ( V_2 ) ;
F_436 () ;
}
static void F_501 ( struct V_973 * V_974 )
{
struct V_1 * V_2 = F_195 ( V_974 ,
struct V_1 ,
V_37 ) ;
if ( F_22 ( V_2 -> V_14 . V_39 ) ) {
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
F_434 () ;
F_373 ( V_2 ) ;
F_436 () ;
}
F_31 ( V_2 ) ;
return;
}
F_499 ( V_2 ) ;
F_495 ( V_2 ) ;
F_497 ( V_2 ) ;
F_205 ( V_2 ) ;
F_494 ( V_2 ) ;
F_464 ( V_2 ) ;
F_466 ( V_2 ) ;
if ( F_14 ( V_690 , & V_2 -> V_34 ) ) {
F_502 ( V_2 ) ;
F_503 ( V_2 ) ;
}
F_31 ( V_2 ) ;
}
static int F_504 ( struct V_57 * V_58 ,
struct V_59 * V_975 ,
T_4 * V_236 )
{
struct V_195 * V_89 = V_975 -> V_89 ;
T_1 V_976 , V_977 ;
T_1 V_978 , V_979 ;
int V_17 ;
if ( V_89 -> V_215 != V_980 )
return 0 ;
if ( ! F_505 ( V_89 ) )
return 0 ;
V_17 = F_506 ( V_89 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_977 = V_981 ;
if ( V_975 -> V_249 == F_156 ( V_982 ) ) {
struct V_983 * V_984 = F_507 ( V_89 ) ;
V_984 -> V_985 = 0 ;
V_984 -> V_986 = 0 ;
F_508 ( V_89 ) -> V_986 = ~ F_509 ( V_984 -> V_987 ,
V_984 -> V_988 , 0 ,
V_989 ,
0 ) ;
V_977 |= V_990 ;
V_975 -> V_991 |= V_992 |
V_993 |
V_994 ;
} else if ( F_510 ( V_89 ) ) {
F_511 ( V_89 ) -> V_995 = 0 ;
F_508 ( V_89 ) -> V_986 =
~ F_512 ( & F_511 ( V_89 ) -> V_987 ,
& F_511 ( V_89 ) -> V_988 ,
0 , V_989 , 0 ) ;
V_975 -> V_991 |= V_992 |
V_993 ;
}
V_979 = F_513 ( V_89 ) ;
* V_236 = F_514 ( V_89 ) + V_979 ;
V_975 -> V_168 = F_148 ( V_89 ) -> V_168 ;
V_975 -> V_167 += ( V_975 -> V_168 - 1 ) * * V_236 ;
V_978 = V_979 << V_996 ;
V_978 |= F_148 ( V_89 ) -> V_237 << V_997 ;
V_976 = F_515 ( V_89 ) ;
V_976 |= F_516 ( V_89 ) << V_998 ;
V_976 |= V_975 -> V_991 & V_999 ;
F_517 ( V_58 , V_976 , 0 , V_977 ,
V_978 ) ;
return 1 ;
}
static void F_518 ( struct V_57 * V_58 ,
struct V_59 * V_975 )
{
struct V_195 * V_89 = V_975 -> V_89 ;
T_1 V_976 = 0 ;
T_1 V_978 = 0 ;
T_1 V_977 = 0 ;
if ( V_89 -> V_215 != V_980 ) {
if ( ! ( V_975 -> V_991 & V_1000 ) &&
! ( V_975 -> V_991 & V_1001 ) )
return;
} else {
T_4 V_1002 = 0 ;
switch ( V_975 -> V_249 ) {
case F_156 ( V_982 ) :
V_976 |= F_515 ( V_89 ) ;
V_977 |= V_990 ;
V_1002 = F_507 ( V_89 ) -> V_249 ;
break;
case F_156 ( V_1003 ) :
V_976 |= F_515 ( V_89 ) ;
V_1002 = F_511 ( V_89 ) -> V_1004 ;
break;
default:
if ( F_24 ( F_519 () ) ) {
F_520 ( V_58 -> V_73 ,
L_134 ,
V_975 -> V_249 ) ;
}
break;
}
switch ( V_1002 ) {
case V_989 :
V_977 |= V_981 ;
V_978 = F_513 ( V_89 ) <<
V_996 ;
break;
case V_1005 :
V_977 |= V_1006 ;
V_978 = sizeof( struct V_1007 ) <<
V_996 ;
break;
case V_1008 :
V_978 = sizeof( struct V_1009 ) <<
V_996 ;
break;
default:
if ( F_24 ( F_519 () ) ) {
F_520 ( V_58 -> V_73 ,
L_135 ,
V_1002 ) ;
}
break;
}
V_975 -> V_991 |= V_993 ;
}
V_976 |= F_516 ( V_89 ) << V_998 ;
V_976 |= V_975 -> V_991 & V_999 ;
F_517 ( V_58 , V_976 , 0 ,
V_977 , V_978 ) ;
}
static T_1 F_521 ( struct V_195 * V_89 , T_1 V_991 )
{
T_1 V_1010 = V_1011 |
V_1012 |
V_1013 ;
V_1010 |= F_522 ( V_991 , V_1000 ,
V_1014 ) ;
V_1010 |= F_522 ( V_991 , V_992 ,
V_1015 ) ;
V_1010 |= F_522 ( V_991 , V_1016 ,
V_1017 ) ;
V_1010 ^= F_522 ( V_89 -> V_1018 , 1 , V_1013 ) ;
return V_1010 ;
}
static void F_523 ( union V_61 * V_62 ,
T_1 V_991 , unsigned int V_1019 )
{
T_1 V_1020 = V_1019 << V_1021 ;
V_1020 |= F_522 ( V_991 ,
V_993 ,
V_1022 ) ;
V_1020 |= F_522 ( V_991 ,
V_994 ,
V_1023 ) ;
V_1020 |= F_522 ( V_991 ,
V_1001 ,
V_1024 ) ;
V_62 -> V_233 . V_1020 = F_96 ( V_1020 ) ;
}
static int F_524 ( struct V_57 * V_58 , T_2 V_275 )
{
F_104 ( V_58 -> V_55 , V_58 -> V_86 ) ;
F_111 () ;
if ( F_99 ( F_110 ( V_58 ) < V_275 ) )
return - V_762 ;
F_525 ( V_58 -> V_55 , V_58 -> V_86 ) ;
++ V_58 -> V_152 . V_174 ;
return 0 ;
}
static inline int F_526 ( struct V_57 * V_58 , T_2 V_275 )
{
if ( F_99 ( F_110 ( V_58 ) >= V_275 ) )
return 0 ;
return F_524 ( V_58 , V_275 ) ;
}
static void F_527 ( struct V_57 * V_58 ,
struct V_59 * V_975 ,
const T_4 V_236 )
{
struct V_195 * V_89 = V_975 -> V_89 ;
struct V_59 * V_60 ;
union V_61 * V_62 ;
struct V_260 * V_261 ;
T_9 V_81 ;
unsigned int V_266 , V_275 ;
T_1 V_991 = V_975 -> V_991 ;
T_1 V_1010 = F_521 ( V_89 , V_991 ) ;
T_2 V_48 = V_58 -> V_80 ;
V_62 = F_61 ( V_58 , V_48 ) ;
F_523 ( V_62 , V_991 , V_89 -> V_82 - V_236 ) ;
V_275 = F_147 ( V_89 ) ;
V_266 = V_89 -> V_266 ;
#ifdef F_175
if ( V_991 & V_1025 ) {
if ( V_266 < sizeof( struct V_294 ) ) {
V_275 -= sizeof( struct V_294 ) - V_266 ;
V_266 = 0 ;
} else {
V_266 -= sizeof( struct V_294 ) ;
}
}
#endif
V_81 = F_528 ( V_58 -> V_73 , V_89 -> V_92 , V_275 , V_121 ) ;
V_60 = V_975 ;
for ( V_261 = & F_148 ( V_89 ) -> V_262 [ 0 ] ; ; V_261 ++ ) {
if ( F_140 ( V_58 -> V_73 , V_81 ) )
goto V_1026;
F_81 ( V_60 , V_82 , V_275 ) ;
F_529 ( V_60 , V_81 , V_81 ) ;
V_62 -> V_233 . V_1027 = F_143 ( V_81 ) ;
while ( F_24 ( V_275 > V_1028 ) ) {
V_62 -> V_233 . V_1029 =
F_96 ( V_1010 ^ V_1028 ) ;
V_48 ++ ;
V_62 ++ ;
if ( V_48 == V_58 -> V_88 ) {
V_62 = F_61 ( V_58 , 0 ) ;
V_48 = 0 ;
}
V_62 -> V_233 . V_1020 = 0 ;
V_81 += V_1028 ;
V_275 -= V_1028 ;
V_62 -> V_233 . V_1027 = F_143 ( V_81 ) ;
}
if ( F_99 ( ! V_266 ) )
break;
V_62 -> V_233 . V_1029 = F_96 ( V_1010 ^ V_275 ) ;
V_48 ++ ;
V_62 ++ ;
if ( V_48 == V_58 -> V_88 ) {
V_62 = F_61 ( V_58 , 0 ) ;
V_48 = 0 ;
}
V_62 -> V_233 . V_1020 = 0 ;
#ifdef F_175
V_275 = F_351 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_275 = F_530 ( V_261 ) ;
#endif
V_266 -= V_275 ;
V_81 = F_531 ( V_58 -> V_73 , V_261 , 0 , V_275 ,
V_121 ) ;
V_60 = & V_58 -> V_78 [ V_48 ] ;
}
V_1010 |= V_275 | V_1030 ;
V_62 -> V_233 . V_1029 = F_96 ( V_1010 ) ;
F_532 ( F_107 ( V_58 ) , V_975 -> V_167 ) ;
V_975 -> V_84 = V_171 ;
F_144 () ;
V_975 -> V_83 = V_62 ;
V_48 ++ ;
if ( V_48 == V_58 -> V_88 )
V_48 = 0 ;
V_58 -> V_80 = V_48 ;
F_526 ( V_58 , V_1031 ) ;
if ( F_533 ( F_107 ( V_58 ) ) || ! V_89 -> V_1032 ) {
F_145 ( V_48 , V_58 -> V_146 ) ;
F_534 () ;
}
return;
V_1026:
F_406 ( V_58 -> V_73 , L_136 ) ;
for (; ; ) {
V_60 = & V_58 -> V_78 [ V_48 ] ;
F_77 ( V_58 , V_60 ) ;
if ( V_60 == V_975 )
break;
if ( V_48 == 0 )
V_48 = V_58 -> V_88 ;
V_48 -- ;
}
V_58 -> V_80 = V_48 ;
}
static void F_535 ( struct V_57 * V_120 ,
struct V_59 * V_975 )
{
struct V_157 * V_158 = V_120 -> V_158 ;
union V_1033 V_1034 = { . V_1035 = 0 } ;
union V_1033 V_1036 = { . V_1035 = 0 } ;
union {
unsigned char * V_1037 ;
struct V_983 * V_1038 ;
struct V_1039 * V_1040 ;
} V_1041 ;
struct V_1042 * V_1043 ;
T_12 V_1044 ;
if ( ! V_158 )
return;
if ( ! V_120 -> V_396 )
return;
V_120 -> V_397 ++ ;
V_1041 . V_1037 = F_536 ( V_975 -> V_89 ) ;
if ( ( V_975 -> V_249 != F_156 ( V_1003 ) ||
V_1041 . V_1040 -> V_1004 != V_989 ) &&
( V_975 -> V_249 != F_156 ( V_982 ) ||
V_1041 . V_1038 -> V_249 != V_989 ) )
return;
V_1043 = F_508 ( V_975 -> V_89 ) ;
if ( ! V_1043 || V_1043 -> V_1045 )
return;
if ( ! V_1043 -> V_1046 && ( V_120 -> V_397 < V_120 -> V_396 ) )
return;
V_120 -> V_397 = 0 ;
V_1044 = F_156 ( V_975 -> V_991 >> V_1047 ) ;
V_1034 . V_1048 . V_1044 = V_1044 ;
if ( V_975 -> V_991 & ( V_1049 | V_1000 ) )
V_1036 . V_1050 . V_1051 ^= V_1043 -> V_1052 ^ F_156 ( V_248 ) ;
else
V_1036 . V_1050 . V_1051 ^= V_1043 -> V_1052 ^ V_975 -> V_249 ;
V_1036 . V_1050 . V_1053 ^= V_1043 -> V_1054 ;
if ( V_975 -> V_249 == F_156 ( V_982 ) ) {
V_1034 . V_1048 . V_1055 = V_1056 ;
V_1036 . V_1057 ^= V_1041 . V_1038 -> V_987 ^ V_1041 . V_1038 -> V_988 ;
} else {
V_1034 . V_1048 . V_1055 = V_1058 ;
V_1036 . V_1057 ^= V_1041 . V_1040 -> V_987 . V_1059 [ 0 ] ^
V_1041 . V_1040 -> V_987 . V_1059 [ 1 ] ^
V_1041 . V_1040 -> V_987 . V_1059 [ 2 ] ^
V_1041 . V_1040 -> V_987 . V_1059 [ 3 ] ^
V_1041 . V_1040 -> V_988 . V_1059 [ 0 ] ^
V_1041 . V_1040 -> V_988 . V_1059 [ 1 ] ^
V_1041 . V_1040 -> V_988 . V_1059 [ 2 ] ^
V_1041 . V_1040 -> V_988 . V_1059 [ 3 ] ;
}
F_537 ( & V_158 -> V_2 -> V_14 ,
V_1034 , V_1036 , V_120 -> V_86 ) ;
}
static T_2 F_538 ( struct V_54 * V_73 , struct V_195 * V_89 ,
void * V_1060 , T_15 V_1061 )
{
struct V_616 * V_1062 = V_1060 ;
#ifdef F_175
struct V_1 * V_2 ;
struct V_943 * V_1063 ;
int V_1064 ;
#endif
if ( V_1062 )
return V_89 -> V_1065 + V_1062 -> V_624 ;
#ifdef F_175
switch ( F_539 ( V_89 ) ) {
case F_156 ( V_1066 ) :
case F_156 ( V_1067 ) :
V_2 = F_89 ( V_73 ) ;
if ( V_2 -> V_139 & V_509 )
break;
default:
return V_1061 ( V_73 , V_89 ) ;
}
V_1063 = & V_2 -> V_411 [ V_1068 ] ;
V_1064 = F_540 ( V_89 ) ? F_541 ( V_89 ) :
F_542 () ;
while ( V_1064 >= V_1063 -> V_413 )
V_1064 -= V_1063 -> V_413 ;
return V_1064 + V_1063 -> V_1069 ;
#else
return V_1061 ( V_73 , V_89 ) ;
#endif
}
T_16 F_543 ( struct V_195 * V_89 ,
struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_59 * V_975 ;
int V_1070 ;
T_1 V_991 = 0 ;
unsigned short V_1063 ;
T_2 V_88 = F_544 ( F_147 ( V_89 ) ) ;
T_12 V_249 = V_89 -> V_249 ;
T_4 V_236 = 0 ;
for ( V_1063 = 0 ; V_1063 < F_148 ( V_89 ) -> V_281 ; V_1063 ++ )
V_88 += F_544 ( F_148 ( V_89 ) -> V_262 [ V_1063 ] . V_275 ) ;
if ( F_526 ( V_58 , V_88 + 3 ) ) {
V_58 -> V_152 . V_792 ++ ;
return V_1071 ;
}
V_975 = & V_58 -> V_78 [ V_58 -> V_80 ] ;
V_975 -> V_89 = V_89 ;
V_975 -> V_167 = V_89 -> V_82 ;
V_975 -> V_168 = 1 ;
if ( F_545 ( V_89 ) ) {
V_991 |= F_546 ( V_89 ) << V_1047 ;
V_991 |= V_1000 ;
} else if ( V_249 == F_156 ( V_248 ) ) {
struct V_1072 * V_1073 , V_1074 ;
V_1073 = F_547 ( V_89 , V_505 , sizeof( V_1074 ) , & V_1074 ) ;
if ( ! V_1073 )
goto V_1075;
V_991 |= F_548 ( V_1073 -> V_1076 ) <<
V_1047 ;
V_991 |= V_1049 ;
}
V_249 = F_539 ( V_89 ) ;
if ( F_24 ( F_148 ( V_89 ) -> V_991 & V_1077 ) &&
V_2 -> V_1078 &&
! F_549 ( V_1079 ,
& V_2 -> V_34 ) ) {
F_148 ( V_89 ) -> V_991 |= V_1080 ;
V_991 |= V_1016 ;
V_2 -> V_1081 = F_550 ( V_89 ) ;
V_2 -> V_1082 = V_171 ;
F_16 ( & V_2 -> V_1083 ) ;
}
F_551 ( V_89 ) ;
#ifdef F_291
if ( V_2 -> V_139 & V_406 )
V_991 |= V_1001 ;
#endif
if ( ( V_2 -> V_139 & V_140 ) &&
( ( V_991 & ( V_1000 | V_1049 ) ) ||
( V_89 -> V_1084 != V_1085 ) ) ) {
V_991 &= ~ V_1086 ;
V_991 |= ( V_89 -> V_1084 & 0x7 ) <<
V_1087 ;
if ( V_991 & V_1049 ) {
struct V_1088 * V_1073 ;
if ( F_506 ( V_89 , 0 ) )
goto V_1075;
V_1073 = (struct V_1088 * ) V_89 -> V_92 ;
V_1073 -> V_1076 = F_156 ( V_991 >>
V_1047 ) ;
} else {
V_991 |= V_1000 ;
}
}
V_975 -> V_991 = V_991 ;
V_975 -> V_249 = V_249 ;
#ifdef F_175
if ( ( V_249 == F_156 ( V_1066 ) ) &&
( V_58 -> V_55 -> V_196 & ( V_1089 | V_1090 ) ) ) {
V_1070 = F_552 ( V_58 , V_975 , & V_236 ) ;
if ( V_1070 < 0 )
goto V_1075;
goto V_1091;
}
#endif
V_1070 = F_504 ( V_58 , V_975 , & V_236 ) ;
if ( V_1070 < 0 )
goto V_1075;
else if ( ! V_1070 )
F_518 ( V_58 , V_975 ) ;
if ( F_14 ( V_371 , & V_58 -> V_34 ) )
F_535 ( V_58 , V_975 ) ;
#ifdef F_175
V_1091:
#endif
F_527 ( V_58 , V_975 , V_236 ) ;
return V_1092 ;
V_1075:
F_78 ( V_975 -> V_89 ) ;
V_975 -> V_89 = NULL ;
return V_1092 ;
}
static T_16 F_553 ( struct V_195 * V_89 ,
struct V_54 * V_55 ,
struct V_57 * V_120 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_57 * V_58 ;
if ( F_554 ( V_89 , 17 ) )
return V_1092 ;
V_58 = V_120 ? V_120 : V_2 -> V_58 [ V_89 -> V_1065 ] ;
return F_543 ( V_89 , V_2 , V_58 ) ;
}
static T_16 F_555 ( struct V_195 * V_89 ,
struct V_54 * V_55 )
{
return F_553 ( V_89 , V_55 , NULL ) ;
}
static int F_556 ( struct V_54 * V_55 , void * V_1093 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1094 * V_548 = V_1093 ;
int V_653 ;
if ( ! F_354 ( V_548 -> V_1095 ) )
return - V_1096 ;
F_303 ( V_2 , V_14 -> V_108 . V_548 , F_273 ( 0 ) ) ;
memcpy ( V_55 -> V_629 , V_548 -> V_1095 , V_55 -> V_687 ) ;
memcpy ( V_14 -> V_108 . V_548 , V_548 -> V_1095 , V_55 -> V_687 ) ;
V_653 = F_300 ( V_2 , V_14 -> V_108 . V_548 , F_273 ( 0 ) ) ;
return V_653 > 0 ? 0 : V_653 ;
}
static int
F_557 ( struct V_54 * V_55 , int V_1097 , int V_1098 , T_2 V_548 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_4 ;
int V_1099 ;
if ( V_1097 != V_14 -> V_339 . V_1100 . V_1097 )
return - V_554 ;
V_1099 = V_14 -> V_339 . V_336 . V_1101 ( V_14 , V_548 , V_1098 , & V_4 ) ;
if ( ! V_1099 )
V_1099 = V_4 ;
return V_1099 ;
}
static int F_558 ( struct V_54 * V_55 , int V_1097 , int V_1098 ,
T_2 V_548 , T_2 V_4 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_1097 != V_14 -> V_339 . V_1100 . V_1097 )
return - V_554 ;
return V_14 -> V_339 . V_336 . V_1102 ( V_14 , V_548 , V_1098 , V_4 ) ;
}
static int F_559 ( struct V_54 * V_55 , struct V_1103 * V_1104 , int V_1105 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
switch ( V_1105 ) {
case V_1106 :
return F_560 ( V_2 , V_1104 ) ;
case V_1107 :
return F_561 ( V_2 , V_1104 ) ;
default:
return F_562 ( & V_2 -> V_14 . V_339 . V_1100 , F_563 ( V_1104 ) , V_1105 ) ;
}
}
static int F_564 ( struct V_54 * V_73 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_354 ( V_14 -> V_108 . V_1108 ) ) {
F_434 () ;
V_17 = F_565 ( V_73 , V_14 -> V_108 . V_1108 , V_1109 ) ;
F_436 () ;
V_14 -> V_108 . V_336 . V_689 ( V_14 , F_273 ( 0 ) ) ;
}
return V_17 ;
}
static int F_566 ( struct V_54 * V_73 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_1110 * V_108 = & V_2 -> V_14 . V_108 ;
if ( F_354 ( V_108 -> V_1108 ) ) {
F_434 () ;
V_17 = F_567 ( V_73 , V_108 -> V_1108 , V_1109 ) ;
F_436 () ;
}
return V_17 ;
}
static void F_568 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_48 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
for ( V_48 = 0 ; V_48 < V_2 -> V_189 ; V_48 ++ )
F_221 ( 0 , V_2 -> V_158 [ V_48 ] ) ;
}
static struct V_1111 * F_569 ( struct V_54 * V_55 ,
struct V_1111 * V_124 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_48 ;
F_570 () ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_120 = F_21 ( V_2 -> V_67 [ V_48 ] ) ;
T_6 V_170 , V_144 ;
unsigned int V_1112 ;
if ( V_120 ) {
do {
V_1112 = F_571 ( & V_120 -> V_169 ) ;
V_144 = V_120 -> V_124 . V_144 ;
V_170 = V_120 -> V_124 . V_170 ;
} while ( F_572 ( & V_120 -> V_169 , V_1112 ) );
V_124 -> V_797 += V_144 ;
V_124 -> V_796 += V_170 ;
}
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_120 = F_21 ( V_2 -> V_58 [ V_48 ] ) ;
T_6 V_170 , V_144 ;
unsigned int V_1112 ;
if ( V_120 ) {
do {
V_1112 = F_571 ( & V_120 -> V_169 ) ;
V_144 = V_120 -> V_124 . V_144 ;
V_170 = V_120 -> V_124 . V_170 ;
} while ( F_572 ( & V_120 -> V_169 , V_1112 ) );
V_124 -> V_799 += V_144 ;
V_124 -> V_798 += V_170 ;
}
}
F_573 () ;
V_124 -> V_906 = V_55 -> V_124 . V_906 ;
V_124 -> V_907 = V_55 -> V_124 . V_907 ;
V_124 -> V_909 = V_55 -> V_124 . V_909 ;
V_124 -> V_910 = V_55 -> V_124 . V_910 ;
V_124 -> V_911 = V_55 -> V_124 . V_911 ;
return V_124 ;
}
static void F_574 ( struct V_1 * V_2 , T_4 V_134 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_3 , V_1113 ;
int V_48 ;
if ( V_14 -> V_108 . type == V_109 )
return;
V_3 = F_37 ( V_14 , V_1114 ) ;
V_1113 = V_3 ;
for ( V_48 = 0 ; V_48 < V_600 ; V_48 ++ ) {
T_4 V_1115 = V_3 >> ( V_48 * V_1116 ) ;
if ( V_1115 > V_134 )
V_3 &= ~ ( 0x7 << V_1116 ) ;
}
if ( V_3 != V_1113 )
F_71 ( V_14 , V_1114 , V_3 ) ;
return;
}
static void F_575 ( struct V_1 * V_2 )
{
struct V_54 * V_73 = V_2 -> V_55 ;
struct V_1117 * V_136 = & V_2 -> V_136 ;
struct V_1118 * V_1119 = V_2 -> V_585 ;
T_4 V_1120 ;
for ( V_1120 = 0 ; V_1120 < V_1121 ; V_1120 ++ ) {
T_4 V_134 = 0 ;
if ( V_2 -> V_581 & V_582 )
V_134 = F_576 ( V_136 , 0 , V_1120 ) ;
else if ( V_1119 )
V_134 = V_1119 -> V_586 [ V_1120 ] ;
F_577 ( V_73 , V_1120 , V_134 ) ;
}
}
int F_578 ( struct V_54 * V_73 , T_4 V_134 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
bool V_1122 ;
if ( V_134 > V_2 -> V_136 . V_723 . V_724 ||
( V_14 -> V_108 . type == V_109 &&
V_134 < V_600 ) )
return - V_554 ;
V_1122 = ( F_579 ( & V_2 -> V_626 , 32 ) > 1 ) ;
if ( V_134 && V_1122 && V_2 -> V_627 > V_1123 )
return - V_762 ;
if ( F_57 ( V_73 ) )
F_424 ( V_73 ) ;
F_441 ( V_2 ) ;
#ifdef F_359
if ( V_134 ) {
F_580 ( V_73 , V_134 ) ;
F_575 ( V_2 ) ;
V_2 -> V_139 |= V_140 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ) {
V_2 -> V_1124 = V_2 -> V_14 . V_125 . V_738 ;
V_2 -> V_14 . V_125 . V_738 = V_1125 ;
}
} else {
F_581 ( V_73 ) ;
if ( V_2 -> V_14 . V_108 . type == V_109 )
V_2 -> V_14 . V_125 . V_738 = V_2 -> V_1124 ;
V_2 -> V_139 &= ~ V_140 ;
V_2 -> V_737 . V_137 = false ;
V_2 -> V_136 . V_137 = false ;
}
F_574 ( V_2 , V_134 ) ;
#endif
F_435 ( V_2 ) ;
if ( F_57 ( V_73 ) )
return F_418 ( V_73 ) ;
return 0 ;
}
void F_582 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
F_434 () ;
F_578 ( V_55 , F_246 ( V_55 ) ) ;
F_436 () ;
}
void F_583 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
if ( F_57 ( V_55 ) )
F_370 ( V_2 ) ;
else
F_376 ( V_2 ) ;
}
static T_17 F_584 ( struct V_54 * V_55 ,
T_17 V_196 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
if ( ! ( V_196 & V_211 ) )
V_196 &= ~ V_1126 ;
if ( ! ( V_2 -> V_154 & V_708 ) )
V_196 &= ~ V_1126 ;
return V_196 ;
}
static int F_585 ( struct V_54 * V_55 ,
T_17 V_196 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
T_17 V_1127 = V_55 -> V_196 ^ V_196 ;
bool V_1128 = false ;
if ( ! ( V_196 & V_1126 ) ) {
if ( V_2 -> V_154 & V_517 )
V_1128 = true ;
V_2 -> V_154 &= ~ V_517 ;
} else if ( ( V_2 -> V_154 & V_708 ) &&
! ( V_2 -> V_154 & V_517 ) ) {
if ( V_2 -> V_377 == 1 ||
V_2 -> V_377 > V_1129 ) {
V_2 -> V_154 |= V_517 ;
V_1128 = true ;
} else if ( ( V_1127 ^ V_196 ) & V_1126 ) {
F_105 ( V_172 , L_137
L_138 ) ;
}
}
switch ( V_196 & V_1130 ) {
case V_1130 :
if ( ! ( V_2 -> V_139 & V_602 ) )
V_1128 = true ;
V_2 -> V_139 &= ~ V_362 ;
V_2 -> V_139 |= V_602 ;
break;
default:
if ( V_2 -> V_139 & V_602 )
V_1128 = true ;
V_2 -> V_139 &= ~ V_602 ;
if ( V_2 -> V_139 & V_406 )
break;
if ( F_246 ( V_55 ) > 1 )
break;
if ( V_2 -> V_411 [ V_412 ] . V_707 <= 1 )
break;
if ( ! V_2 -> V_396 )
break;
V_2 -> V_139 |= V_362 ;
break;
}
if ( V_196 & V_244 )
F_288 ( V_2 ) ;
else
F_287 ( V_2 ) ;
if ( V_1127 & V_269 )
V_1128 = true ;
V_55 -> V_196 = V_196 ;
if ( V_1128 )
F_583 ( V_55 ) ;
return 0 ;
}
static void F_586 ( struct V_54 * V_73 , T_18 V_1131 ,
T_12 V_1050 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1132 = F_548 ( V_1050 ) ;
if ( V_1131 == V_1133 )
return;
if ( V_2 -> V_1134 == V_1132 ) {
F_587 ( V_73 , L_139 , V_1132 ) ;
return;
}
if ( V_2 -> V_1134 ) {
F_587 ( V_73 ,
L_140 ,
V_1132 ) ;
return;
}
V_2 -> V_1134 = V_1132 ;
F_71 ( V_14 , V_1135 , V_1132 ) ;
}
static void F_588 ( struct V_54 * V_73 , T_18 V_1131 ,
T_12 V_1050 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1132 = F_548 ( V_1050 ) ;
if ( V_1131 == V_1133 )
return;
if ( V_2 -> V_1134 != V_1132 ) {
F_587 ( V_73 , L_141 ,
V_1132 ) ;
return;
}
V_2 -> V_1134 = 0 ;
F_71 ( V_14 , V_1135 , 0 ) ;
}
static int F_589 ( struct V_1136 * V_1137 , struct V_1138 * V_1139 [] ,
struct V_54 * V_73 ,
const unsigned char * V_548 , T_2 V_246 ,
T_2 V_139 )
{
if ( F_590 ( V_548 ) || F_591 ( V_548 ) ) {
if ( V_1140 <= F_306 ( V_73 ) )
return - V_543 ;
}
return F_592 ( V_1137 , V_1139 , V_73 , V_548 , V_246 , V_139 ) ;
}
static int F_593 ( struct V_1 * V_2 ,
T_19 V_1141 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
unsigned int V_1093 , V_1142 ;
T_1 V_477 ;
switch ( V_1141 ) {
case V_1143 :
F_71 ( & V_2 -> V_14 , V_485 , 0 ) ;
V_477 = F_37 ( V_14 , V_1144 ) ;
V_477 |= V_482 ;
F_71 ( V_14 , V_1144 , V_477 ) ;
V_1142 = V_2 -> V_303 + V_2 -> V_627 ;
for ( V_1093 = 0 ; V_1093 < V_1142 ; V_1093 ++ ) {
if ( V_14 -> V_108 . V_336 . V_1145 )
V_14 -> V_108 . V_336 . V_1145 ( V_14 ,
true ,
V_1093 ) ;
}
break;
case V_484 :
F_71 ( & V_2 -> V_14 , V_485 ,
V_486 ) ;
V_477 = F_37 ( V_14 , V_1144 ) ;
if ( ! V_2 -> V_303 )
V_477 &= ~ V_482 ;
F_71 ( V_14 , V_1144 , V_477 ) ;
V_1142 = V_2 -> V_303 + V_2 -> V_627 ;
for ( V_1093 = 0 ; V_1093 < V_1142 ; V_1093 ++ ) {
if ( V_14 -> V_108 . V_336 . V_1145 )
V_14 -> V_108 . V_336 . V_1145 ( V_14 ,
false ,
V_1093 ) ;
}
break;
default:
return - V_554 ;
}
V_2 -> V_483 = V_1141 ;
F_105 ( V_156 , L_142 ,
V_1141 == V_1143 ? L_143 : L_144 ) ;
return 0 ;
}
static int F_594 ( struct V_54 * V_73 ,
struct V_1146 * V_1147 , T_2 V_139 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_1138 * V_1148 , * V_1149 ;
int V_1150 ;
if ( ! ( V_2 -> V_139 & V_406 ) )
return - V_1151 ;
V_1149 = F_595 ( V_1147 , sizeof( struct V_1152 ) , V_1153 ) ;
if ( ! V_1149 )
return - V_554 ;
F_596 (attr, br_spec, rem) {
T_1 V_165 ;
T_19 V_1141 ;
if ( F_597 ( V_1148 ) != V_1154 )
continue;
if ( F_598 ( V_1148 ) < sizeof( V_1141 ) )
return - V_554 ;
V_1141 = F_599 ( V_1148 ) ;
V_165 = F_593 ( V_2 , V_1141 ) ;
if ( V_165 )
return V_165 ;
break;
}
return 0 ;
}
static int F_600 ( struct V_195 * V_89 , T_1 V_1155 , T_1 V_1156 ,
struct V_54 * V_73 ,
T_1 V_1157 , int V_1158 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
if ( ! ( V_2 -> V_139 & V_406 ) )
return 0 ;
return F_601 ( V_89 , V_1155 , V_1156 , V_73 ,
V_2 -> V_483 , 0 , 0 , V_1158 ) ;
}
static void * F_602 ( struct V_54 * V_9 , struct V_54 * V_620 )
{
struct V_616 * V_1062 = NULL ;
struct V_1 * V_2 = F_89 ( V_9 ) ;
int V_1159 = V_2 -> V_303 + V_2 -> V_627 ;
unsigned int V_707 ;
int V_468 , V_17 ;
if ( V_1159 >= V_1160 )
return F_603 ( - V_554 ) ;
#ifdef F_604
if ( V_620 -> V_93 != V_620 -> V_77 ) {
F_587 ( V_9 , L_145 ,
V_620 -> V_53 ) ;
return F_603 ( - V_554 ) ;
}
#endif
if ( V_620 -> V_77 > V_765 ||
V_620 -> V_77 == V_1161 ) {
F_587 ( V_9 ,
L_146 ,
V_9 -> V_53 ) ;
return F_603 ( - V_554 ) ;
}
if ( ( ( V_2 -> V_139 & V_140 ) &&
V_2 -> V_627 > V_1123 - 1 ) ||
( V_2 -> V_627 > V_1162 ) )
return F_603 ( - V_762 ) ;
V_1062 = F_605 ( 1 , sizeof( struct V_616 ) , V_756 ) ;
if ( ! V_1062 )
return F_603 ( - V_543 ) ;
V_468 = F_579 ( & V_2 -> V_626 , 32 ) ;
V_2 -> V_627 ++ ;
F_242 ( V_468 , & V_2 -> V_626 ) ;
V_707 = F_606 ( & V_2 -> V_626 , 32 ) ;
V_2 -> V_139 |= V_575 | V_406 ;
V_2 -> V_411 [ V_488 ] . V_707 = V_707 + 1 ;
V_2 -> V_411 [ V_412 ] . V_707 = V_620 -> V_77 ;
V_17 = F_578 ( V_9 , F_246 ( V_9 ) ) ;
if ( V_17 )
goto V_1163;
V_1062 -> V_468 = V_468 ;
V_1062 -> V_148 = V_2 ;
V_17 = F_349 ( V_620 , V_1062 ) ;
if ( V_17 )
goto V_1163;
F_607 ( V_620 ) ;
return V_1062 ;
V_1163:
F_587 ( V_9 ,
L_147 , V_620 -> V_53 ) ;
F_34 ( V_468 , & V_2 -> V_626 ) ;
V_2 -> V_627 -- ;
F_233 ( V_1062 ) ;
return F_603 ( V_17 ) ;
}
static void F_608 ( struct V_54 * V_9 , void * V_1164 )
{
struct V_616 * V_1062 = V_1164 ;
struct V_1 * V_2 = V_1062 -> V_148 ;
unsigned int V_707 ;
F_34 ( V_1062 -> V_468 , & V_2 -> V_626 ) ;
V_2 -> V_627 -- ;
V_707 = F_606 ( & V_2 -> V_626 , 32 ) ;
V_2 -> V_411 [ V_488 ] . V_707 = V_707 + 1 ;
F_347 ( V_1062 -> V_55 , V_1062 ) ;
F_578 ( V_9 , F_246 ( V_9 ) ) ;
F_350 ( V_9 , L_92 ,
V_1062 -> V_468 , V_2 -> V_627 ,
V_1062 -> V_619 ,
V_1062 -> V_619 + V_2 -> V_618 ,
V_2 -> V_626 ) ;
F_233 ( V_1062 ) ;
}
static inline int F_609 ( struct V_1 * V_2 )
{
struct V_5 * V_382 , * V_9 = V_2 -> V_9 ;
int V_1165 = 0 ;
if ( F_8 ( & V_2 -> V_14 ) )
V_1165 = 4 ;
F_610 (entry, &adapter->pdev->bus->devices, bus_list) {
if ( V_382 -> V_957 )
continue;
if ( ( V_382 -> V_700 != V_9 -> V_700 ) ||
( V_382 -> V_190 != V_9 -> V_190 ) )
return - 1 ;
V_1165 ++ ;
}
return V_1165 ;
}
int F_611 ( struct V_1 * V_2 , T_2 V_21 ,
T_2 V_1166 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1167 = V_2 -> V_1168 & V_1169 ;
int V_1170 = 0 ;
switch ( V_21 ) {
case V_1171 :
switch ( V_1166 ) {
case V_1172 :
case V_1173 :
if ( V_14 -> V_10 . V_1174 != 0 )
break;
case V_1175 :
case V_1176 :
case V_1177 :
case V_1178 :
case V_1179 :
V_1170 = 1 ;
break;
}
break;
case V_1180 :
switch ( V_1166 ) {
case V_1181 :
V_1170 = 1 ;
break;
}
break;
case V_1182 :
if ( V_1166 != V_1183 )
V_1170 = 1 ;
break;
case V_1184 :
V_1170 = 1 ;
break;
case V_1185 :
case V_1186 :
if ( ( V_1167 == V_1187 ) ||
( ( V_1167 == V_1188 ) &&
( V_14 -> V_10 . V_1174 == 0 ) ) ) {
V_1170 = 1 ;
}
break;
}
return V_1170 ;
}
static void F_612 ( struct V_1 * V_2 )
{
#ifdef F_613
struct V_1189 * V_1190 = F_614 ( V_2 -> V_9 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
const unsigned char * V_548 ;
V_548 = F_615 ( V_1190 ) ;
if ( V_548 ) {
F_302 ( V_14 -> V_108 . V_1191 , V_548 ) ;
return;
}
#endif
#ifdef F_616
F_302 ( V_14 -> V_108 . V_1191 , V_1192 -> V_1193 ) ;
#endif
}
static int F_617 ( struct V_5 * V_9 , const struct V_1194 * V_1195 )
{
struct V_54 * V_55 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_14 ;
const struct V_1196 * V_1197 = V_1198 [ V_1195 -> V_1199 ] ;
int V_48 , V_17 , V_1200 , V_24 ;
unsigned int V_413 = V_1201 ;
T_4 V_1202 [ V_1203 ] ;
bool V_1204 = false ;
#ifdef F_175
T_2 V_1205 ;
#endif
T_1 V_1206 ;
if ( V_9 -> V_957 ) {
F_618 ( 1 , V_1207 L_148 ,
F_488 ( V_9 ) , V_9 -> V_700 , V_9 -> V_190 ) ;
return - V_554 ;
}
V_17 = F_431 ( V_9 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_619 ( & V_9 -> V_73 , F_241 ( 64 ) ) ) {
V_1200 = 1 ;
} else {
V_17 = F_619 ( & V_9 -> V_73 , F_241 ( 32 ) ) ;
if ( V_17 ) {
F_406 ( & V_9 -> V_73 ,
L_149 ) ;
goto V_1208;
}
V_1200 = 0 ;
}
V_17 = F_620 ( V_9 , F_621 ( V_9 ,
V_1209 ) , V_1210 ) ;
if ( V_17 ) {
F_406 ( & V_9 -> V_73 ,
L_150 , V_17 ) ;
goto V_1211;
}
F_622 ( V_9 ) ;
F_432 ( V_9 ) ;
F_430 ( V_9 ) ;
if ( V_1197 -> V_108 == V_109 ) {
#ifdef F_359
V_413 = 4 * V_600 ;
#else
V_413 = V_1212 ;
#endif
}
V_55 = F_623 ( sizeof( struct V_1 ) , V_413 ) ;
if ( ! V_55 ) {
V_17 = - V_543 ;
goto V_1213;
}
F_624 ( V_55 , & V_9 -> V_73 ) ;
V_2 = F_89 ( V_55 ) ;
V_2 -> V_55 = V_55 ;
V_2 -> V_9 = V_9 ;
V_14 = & V_2 -> V_14 ;
V_14 -> V_38 = V_2 ;
V_2 -> V_1214 = F_625 ( V_1215 , V_1216 ) ;
V_14 -> V_39 = F_626 ( F_627 ( V_9 , 0 ) ,
F_628 ( V_9 , 0 ) ) ;
V_2 -> V_395 = V_14 -> V_39 ;
if ( ! V_14 -> V_39 ) {
V_17 = - V_752 ;
goto V_1217;
}
V_55 -> V_1218 = & V_1219 ;
F_629 ( V_55 ) ;
V_55 -> V_1220 = 5 * V_972 ;
F_630 ( V_55 -> V_53 , F_488 ( V_9 ) , sizeof( V_55 -> V_53 ) ) ;
memcpy ( & V_14 -> V_108 . V_336 , V_1197 -> V_1221 , sizeof( V_14 -> V_108 . V_336 ) ) ;
V_14 -> V_108 . type = V_1197 -> V_108 ;
memcpy ( & V_14 -> V_1222 . V_336 , V_1197 -> V_1223 , sizeof( V_14 -> V_1222 . V_336 ) ) ;
V_1206 = F_37 ( V_14 , V_1224 ) ;
if ( F_22 ( V_14 -> V_39 ) ) {
V_17 = - V_752 ;
goto V_1217;
}
if ( ! ( V_1206 & ( 1 << 8 ) ) )
V_14 -> V_1222 . V_336 . V_233 = & V_1225 ;
memcpy ( & V_14 -> V_339 . V_336 , V_1197 -> V_1226 , sizeof( V_14 -> V_339 . V_336 ) ) ;
V_14 -> V_339 . V_968 = V_1227 ;
V_14 -> V_339 . V_1100 . V_1097 = V_1228 ;
V_14 -> V_339 . V_1100 . V_1229 = 0 ;
V_14 -> V_339 . V_1100 . V_1230 = V_1231 | V_1232 ;
V_14 -> V_339 . V_1100 . V_73 = V_55 ;
V_14 -> V_339 . V_1100 . V_1233 = F_557 ;
V_14 -> V_339 . V_1100 . V_1234 = F_558 ;
V_1197 -> V_1235 ( V_14 ) ;
V_17 = F_391 ( V_2 ) ;
if ( V_17 )
goto V_1236;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_71 ( & V_2 -> V_14 , V_769 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_139 & V_342 ) {
T_1 V_674 = F_37 ( V_14 , V_675 ) ;
if ( V_674 & V_676 )
F_206 ( V_172 , L_73 ) ;
}
if ( V_1237 )
V_14 -> V_1237 = V_1237 ;
V_14 -> V_339 . V_1238 = true ;
V_17 = V_14 -> V_108 . V_336 . V_1239 ( V_14 ) ;
V_14 -> V_339 . V_1238 = false ;
if ( V_17 == V_683 &&
V_14 -> V_108 . type == V_109 ) {
V_17 = 0 ;
} else if ( V_17 == V_684 ) {
F_18 ( L_151 ) ;
F_18 ( L_152 ) ;
goto V_1236;
} else if ( V_17 ) {
F_18 ( L_153 , V_17 ) ;
goto V_1236;
}
#ifdef F_291
if ( V_2 -> V_14 . V_108 . type == V_109 )
goto V_1240;
F_631 ( V_14 ) ;
memcpy ( & V_14 -> V_1241 . V_336 , V_1197 -> V_1242 , sizeof( V_14 -> V_1241 . V_336 ) ) ;
F_632 ( V_9 , V_744 ) ;
F_633 ( V_2 ) ;
V_1240:
#endif
V_55 -> V_196 = V_1243 |
V_1244 |
V_1245 |
V_1246 |
V_244 |
V_1247 |
V_1248 |
V_197 |
V_211 ;
V_55 -> V_1249 = V_55 -> V_196 | V_1250 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_55 -> V_196 |= V_1251 ;
V_55 -> V_1249 |= V_1251 |
V_1130 ;
break;
default:
break;
}
V_55 -> V_1249 |= V_269 ;
V_55 -> V_196 |= V_1252 ;
V_55 -> V_1253 |= V_1247 ;
V_55 -> V_1253 |= V_1248 ;
V_55 -> V_1253 |= V_1244 ;
V_55 -> V_1253 |= V_1245 ;
V_55 -> V_1253 |= V_1243 ;
V_55 -> V_1254 |= V_1255 ;
V_55 -> V_1254 |= V_1256 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_113 :
case V_114 :
V_55 -> V_1257 |= V_211 ;
break;
default:
break;
}
#ifdef F_359
V_55 -> V_1258 = & V_1258 ;
#endif
#ifdef F_175
if ( V_2 -> V_139 & V_714 ) {
unsigned int V_1259 ;
if ( V_14 -> V_108 . V_336 . V_1260 ) {
V_14 -> V_108 . V_336 . V_1260 ( V_14 , & V_1205 ) ;
if ( V_1205 & V_1261 )
V_2 -> V_139 &= ~ V_714 ;
}
V_1259 = F_351 ( int , V_1262 , F_393 () ) ;
V_2 -> V_411 [ V_1068 ] . V_707 = V_1259 ;
V_55 -> V_196 |= V_1089 |
V_1090 ;
V_55 -> V_1253 |= V_1089 |
V_1090 |
V_580 ;
}
#endif
if ( V_1200 ) {
V_55 -> V_196 |= V_1263 ;
V_55 -> V_1253 |= V_1263 ;
}
if ( V_2 -> V_154 & V_708 )
V_55 -> V_1249 |= V_1126 ;
if ( V_2 -> V_154 & V_517 )
V_55 -> V_196 |= V_1126 ;
if ( V_14 -> V_1222 . V_336 . V_1264 ( V_14 , NULL ) < 0 ) {
F_18 ( L_154 ) ;
V_17 = - V_752 ;
goto V_1236;
}
F_612 ( V_2 ) ;
memcpy ( V_55 -> V_629 , V_14 -> V_108 . V_1191 , V_55 -> V_687 ) ;
if ( ! F_354 ( V_55 -> V_629 ) ) {
F_18 ( L_155 ) ;
V_17 = - V_752 ;
goto V_1236;
}
F_299 ( V_2 , V_14 -> V_108 . V_1191 ) ;
F_634 ( & V_2 -> V_677 , & F_498 ,
( unsigned long ) V_2 ) ;
if ( F_22 ( V_14 -> V_39 ) ) {
V_17 = - V_752 ;
goto V_1236;
}
F_635 ( & V_2 -> V_37 , F_501 ) ;
F_242 ( V_40 , & V_2 -> V_34 ) ;
F_34 ( V_36 , & V_2 -> V_34 ) ;
V_17 = F_435 ( V_2 ) ;
if ( V_17 )
goto V_1236;
V_2 -> V_773 = 0 ;
V_14 -> V_1222 . V_336 . V_233 ( V_14 , 0x2c , & V_2 -> V_1168 ) ;
V_14 -> V_1265 = F_611 ( V_2 , V_9 -> V_190 ,
V_9 -> V_706 ) ;
if ( V_14 -> V_1265 )
V_2 -> V_773 = V_1266 ;
F_636 ( & V_2 -> V_9 -> V_73 , V_2 -> V_773 ) ;
V_14 -> V_1222 . V_336 . V_233 ( V_14 , 0x2e , & V_2 -> V_1267 ) ;
V_14 -> V_1222 . V_336 . V_233 ( V_14 , 0x2d , & V_2 -> V_1268 ) ;
V_14 -> V_108 . V_336 . V_1269 ( V_14 ) ;
if ( F_8 ( V_14 ) )
F_5 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_24 = F_637 ( F_609 ( V_2 ) * 10 , 16 ) ;
break;
default:
V_24 = F_609 ( V_2 ) * 10 ;
break;
}
if ( V_24 > 0 )
F_9 ( V_2 , V_24 ) ;
V_17 = F_638 ( V_14 , V_1202 , sizeof( V_1202 ) ) ;
if ( V_17 )
F_630 ( V_1202 , L_7 , sizeof( V_1202 ) ) ;
if ( F_363 ( V_14 ) && V_14 -> V_339 . V_968 != V_1270 )
F_12 ( L_156 ,
V_14 -> V_108 . type , V_14 -> V_339 . type , V_14 -> V_339 . V_968 ,
V_1202 ) ;
else
F_12 ( L_157 ,
V_14 -> V_108 . type , V_14 -> V_339 . type , V_1202 ) ;
F_12 ( L_158 , V_55 -> V_629 ) ;
V_17 = V_14 -> V_108 . V_336 . V_1271 ( V_14 ) ;
if ( V_17 == V_686 ) {
F_11 ( L_95
L_159
L_160
L_161
L_99
L_100 ) ;
}
strcpy ( V_55 -> V_53 , L_162 ) ;
V_17 = F_639 ( V_55 ) ;
if ( V_17 )
goto V_1272;
F_640 ( V_9 , V_2 ) ;
if ( V_14 -> V_108 . V_336 . V_695 )
V_14 -> V_108 . V_336 . V_695 ( V_14 ) ;
F_384 ( V_55 ) ;
#ifdef F_224
if ( F_126 ( & V_9 -> V_73 ) == 0 ) {
V_2 -> V_139 |= V_187 ;
F_123 ( V_2 ) ;
}
#endif
if ( V_2 -> V_139 & V_406 ) {
F_105 ( V_172 , L_163 , V_2 -> V_303 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_303 ; V_48 ++ )
F_641 ( V_9 , ( V_48 | 0x10000000 ) ) ;
}
if ( V_14 -> V_108 . V_336 . V_1273 )
V_14 -> V_108 . V_336 . V_1273 ( V_14 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_564 ( V_55 ) ;
F_12 ( L_164 , V_1274 ) ;
#ifdef F_642
if ( F_643 ( V_2 ) )
F_103 ( V_172 , L_165 ) ;
#endif
F_644 ( V_2 ) ;
if ( F_645 ( V_14 ) && F_363 ( V_14 ) && V_14 -> V_108 . V_336 . V_657 )
V_14 -> V_108 . V_336 . V_657 ( V_14 ,
V_918 | V_941 ,
true ) ;
return 0 ;
V_1272:
F_70 ( V_2 ) ;
F_441 ( V_2 ) ;
V_1236:
F_646 ( V_2 ) ;
V_2 -> V_154 &= ~ V_651 ;
F_647 ( V_2 -> V_395 ) ;
F_233 ( V_2 -> V_545 ) ;
V_1217:
V_1204 = ! F_15 ( V_768 , & V_2 -> V_34 ) ;
F_648 ( V_55 ) ;
V_1213:
F_649 ( V_9 ,
F_621 ( V_9 , V_1209 ) ) ;
V_1211:
V_1208:
if ( ! V_2 || V_1204 )
F_442 ( V_9 ) ;
return V_17 ;
}
static void F_650 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_427 ( V_9 ) ;
struct V_54 * V_55 ;
bool V_1204 ;
if ( ! V_2 )
return;
V_55 = V_2 -> V_55 ;
F_651 ( V_2 ) ;
F_242 ( V_35 , & V_2 -> V_34 ) ;
F_652 ( & V_2 -> V_37 ) ;
#ifdef F_224
if ( V_2 -> V_139 & V_187 ) {
V_2 -> V_139 &= ~ V_187 ;
F_127 ( & V_9 -> V_73 ) ;
F_71 ( & V_2 -> V_14 , V_188 , 1 ) ;
}
#endif
#ifdef F_642
F_653 ( V_2 ) ;
#endif
F_566 ( V_55 ) ;
if ( V_55 -> V_969 == V_970 )
F_496 ( V_55 ) ;
#ifdef F_291
if ( V_743 )
F_646 ( V_2 ) ;
#endif
F_441 ( V_2 ) ;
F_70 ( V_2 ) ;
#ifdef F_654
F_233 ( V_2 -> V_138 ) ;
F_233 ( V_2 -> V_585 ) ;
#endif
F_647 ( V_2 -> V_395 ) ;
F_649 ( V_9 , F_621 ( V_9 ,
V_1209 ) ) ;
F_12 ( L_166 ) ;
F_233 ( V_2 -> V_545 ) ;
V_1204 = ! F_15 ( V_768 , & V_2 -> V_34 ) ;
F_648 ( V_55 ) ;
F_655 ( V_9 ) ;
if ( V_1204 )
F_442 ( V_9 ) ;
}
static T_20 F_656 ( struct V_5 * V_9 ,
T_21 V_34 )
{
struct V_1 * V_2 = F_427 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
#ifdef F_291
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_1275 , * V_948 ;
T_1 V_1276 , V_1277 , V_1278 , V_1279 ;
int V_1280 , V_952 ;
T_2 V_1281 , V_1282 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ||
V_2 -> V_303 == 0 )
goto V_1283;
V_1275 = V_9 -> V_10 -> V_12 ;
while ( V_1275 && ( F_657 ( V_1275 ) != V_1284 ) )
V_1275 = V_1275 -> V_10 -> V_12 ;
if ( ! V_1275 )
goto V_1283;
V_952 = F_491 ( V_1275 , V_1285 ) ;
if ( ! V_952 )
goto V_1283;
V_1276 = F_27 ( V_14 , V_952 + V_1286 ) ;
V_1277 = F_27 ( V_14 , V_952 + V_1286 + 4 ) ;
V_1278 = F_27 ( V_14 , V_952 + V_1286 + 8 ) ;
V_1279 = F_27 ( V_14 , V_952 + V_1286 + 12 ) ;
if ( F_22 ( V_14 -> V_39 ) )
goto V_1283;
V_1281 = V_1277 >> 16 ;
if ( ! ( V_1281 & 0x0080 ) )
goto V_1283;
V_1282 = V_1281 & 0x01 ;
if ( ( V_1282 & 1 ) == ( V_9 -> V_1287 & 1 ) ) {
unsigned int V_21 ;
V_1280 = ( V_1281 & 0x7F ) >> 1 ;
F_18 ( L_167 , V_1280 ) ;
F_18 ( L_168
L_169 ,
V_1276 , V_1277 , V_1278 , V_1279 ) ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_21 = V_1288 ;
break;
case V_112 :
V_21 = V_1289 ;
break;
case V_113 :
V_21 = V_1290 ;
break;
case V_114 :
V_21 = V_1291 ;
break;
default:
V_21 = 0 ;
break;
}
V_948 = F_492 ( V_1292 , V_21 , NULL ) ;
while ( V_948 ) {
if ( V_948 -> V_1287 == ( V_1281 & 0xFF ) )
break;
V_948 = F_492 ( V_1292 ,
V_21 , V_948 ) ;
}
if ( V_948 ) {
F_486 ( V_2 , V_948 ) ;
F_658 ( V_948 ) ;
}
F_659 ( V_9 ) ;
}
V_2 -> V_1293 ++ ;
return V_1294 ;
V_1283:
#endif
if ( ! F_14 ( V_40 , & V_2 -> V_34 ) )
return V_1295 ;
F_434 () ;
F_440 ( V_55 ) ;
if ( V_34 == V_1296 ) {
F_436 () ;
return V_1295 ;
}
if ( F_57 ( V_55 ) )
F_373 ( V_2 ) ;
if ( ! F_15 ( V_768 , & V_2 -> V_34 ) )
F_442 ( V_9 ) ;
F_436 () ;
return V_1297 ;
}
static T_20 F_660 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_427 ( V_9 ) ;
T_20 V_1298 ;
int V_17 ;
if ( F_431 ( V_9 ) ) {
F_103 ( V_172 , L_170 ) ;
V_1298 = V_1295 ;
} else {
F_33 () ;
F_34 ( V_768 , & V_2 -> V_34 ) ;
V_2 -> V_14 . V_39 = V_2 -> V_395 ;
F_432 ( V_9 ) ;
F_429 ( V_9 ) ;
F_430 ( V_9 ) ;
F_433 ( V_9 , false ) ;
F_376 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_769 , ~ 0 ) ;
V_1298 = V_1294 ;
}
V_17 = F_659 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_171
L_172 , V_17 ) ;
}
return V_1298 ;
}
static void F_661 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_427 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
#ifdef F_291
if ( V_2 -> V_1293 ) {
F_105 ( V_156 , L_173 ) ;
V_2 -> V_1293 -- ;
return;
}
#endif
if ( F_57 ( V_55 ) )
F_375 ( V_2 ) ;
F_437 ( V_55 ) ;
}
static int T_22 F_662 ( void )
{
int V_653 ;
F_51 ( L_174 , V_1299 , V_1300 ) ;
F_51 ( L_164 , V_1301 ) ;
F_663 () ;
V_653 = F_664 ( & V_1302 ) ;
if ( V_653 ) {
F_665 () ;
return V_653 ;
}
#ifdef F_224
F_666 ( & V_1303 ) ;
#endif
return 0 ;
}
static void T_23 F_667 ( void )
{
#ifdef F_224
F_668 ( & V_1303 ) ;
#endif
F_669 ( & V_1302 ) ;
F_665 () ;
}
static int F_670 ( struct V_1304 * V_1305 , unsigned long V_191 ,
void * V_1093 )
{
int V_1306 ;
V_1306 = F_671 ( & V_1302 . V_1307 , NULL , & V_191 ,
F_124 ) ;
return V_1306 ? V_1308 : V_1309 ;
}
