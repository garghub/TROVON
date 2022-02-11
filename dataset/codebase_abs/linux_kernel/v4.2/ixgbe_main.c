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
return ( F_180 ( V_98 ) != F_181 () ) || F_182 ( V_98 ) ;
}
static bool F_183 ( struct V_57 * V_67 ,
struct V_70 * V_273 ,
union V_68 * V_69 ,
struct V_195 * V_89 )
{
struct V_98 * V_98 = V_273 -> V_98 ;
unsigned int V_274 = F_154 ( V_69 -> V_94 . V_95 . V_275 ) ;
#if ( V_276 < 8192 )
unsigned int V_277 = F_69 ( V_67 ) ;
#else
unsigned int V_277 = F_169 ( V_274 , V_278 ) ;
unsigned int V_279 = F_139 ( V_67 ) -
F_69 ( V_67 ) ;
#endif
if ( ( V_274 <= V_265 ) && ! F_174 ( V_89 ) ) {
unsigned char * V_263 = F_68 ( V_98 ) + V_273 -> V_99 ;
memcpy ( F_184 ( V_89 , V_274 ) , V_263 , F_169 ( V_274 , sizeof( long ) ) ) ;
if ( F_99 ( ! F_179 ( V_98 ) ) )
return true ;
F_141 ( V_98 , F_137 ( V_67 ) ) ;
return false ;
}
F_185 ( V_89 , F_148 ( V_89 ) -> V_280 , V_98 ,
V_273 -> V_99 , V_274 , V_277 ) ;
if ( F_24 ( F_179 ( V_98 ) ) )
return false ;
#if ( V_276 < 8192 )
if ( F_24 ( F_186 ( V_98 ) != 1 ) )
return false ;
V_273 -> V_99 ^= V_277 ;
#else
V_273 -> V_99 += V_277 ;
if ( V_273 -> V_99 > V_279 )
return false ;
#endif
F_187 ( & V_98 -> V_281 ) ;
return true ;
}
static struct V_195 * F_188 ( struct V_57 * V_67 ,
union V_68 * V_69 )
{
struct V_70 * V_273 ;
struct V_195 * V_89 ;
struct V_98 * V_98 ;
V_273 = & V_67 -> V_71 [ V_67 -> V_79 ] ;
V_98 = V_273 -> V_98 ;
F_189 ( V_98 ) ;
V_89 = V_273 -> V_89 ;
if ( F_99 ( ! V_89 ) ) {
void * V_282 = F_68 ( V_98 ) +
V_273 -> V_99 ;
F_98 ( V_282 ) ;
#if V_278 < 128
F_98 ( V_282 + V_278 ) ;
#endif
V_89 = F_190 ( & V_67 -> V_158 -> V_250 ,
V_265 ) ;
if ( F_24 ( ! V_89 ) ) {
V_67 -> V_219 . V_283 ++ ;
return NULL ;
}
F_189 ( V_89 -> V_92 ) ;
if ( F_99 ( F_134 ( V_69 , V_258 ) ) )
goto V_284;
F_150 ( V_89 ) -> V_81 = V_273 -> V_81 ;
} else {
if ( F_134 ( V_69 , V_258 ) )
F_171 ( V_67 , V_89 ) ;
V_284:
F_172 ( V_67 -> V_73 ,
V_273 -> V_81 ,
V_273 -> V_99 ,
F_69 ( V_67 ) ,
V_231 ) ;
V_273 -> V_89 = NULL ;
}
if ( F_183 ( V_67 , V_273 , V_69 , V_89 ) ) {
F_177 ( V_67 , V_273 ) ;
} else if ( F_150 ( V_89 ) -> V_81 == V_273 -> V_81 ) {
F_150 ( V_89 ) -> V_267 = true ;
} else {
F_80 ( V_67 -> V_73 , V_273 -> V_81 ,
F_139 ( V_67 ) ,
V_231 ) ;
}
V_273 -> V_98 = NULL ;
return V_89 ;
}
static int F_191 ( struct V_157 * V_158 ,
struct V_57 * V_67 ,
const int V_161 )
{
unsigned int V_285 = 0 , V_286 = 0 ;
#ifdef F_175
struct V_1 * V_2 = V_158 -> V_2 ;
int V_287 ;
unsigned int V_288 = 0 ;
#endif
T_2 V_232 = F_110 ( V_67 ) ;
while ( F_99 ( V_286 < V_161 ) ) {
union V_68 * V_69 ;
struct V_195 * V_89 ;
if ( V_232 >= V_289 ) {
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
if ( F_163 ( V_67 , V_69 , V_89 ) )
continue;
if ( F_173 ( V_67 , V_69 , V_89 ) )
continue;
V_285 += V_89 -> V_82 ;
F_152 ( V_67 , V_69 , V_89 ) ;
#ifdef F_175
if ( F_130 ( V_67 , V_69 ) ) {
V_287 = F_193 ( V_2 , V_69 , V_89 ) ;
if ( V_287 > 0 ) {
if ( ! V_288 ) {
V_288 = V_67 -> V_55 -> V_290 -
sizeof( struct V_291 ) -
sizeof( struct V_292 ) -
sizeof( struct V_293 ) ;
if ( V_288 > 512 )
V_288 &= ~ 511 ;
}
V_285 += V_287 ;
V_286 += F_149 ( V_287 ,
V_288 ) ;
}
if ( ! V_287 ) {
F_78 ( V_89 ) ;
continue;
}
}
#endif
F_194 ( V_89 , & V_158 -> V_250 ) ;
F_159 ( V_158 , V_89 ) ;
V_286 ++ ;
}
F_100 ( & V_67 -> V_169 ) ;
V_67 -> V_124 . V_144 += V_286 ;
V_67 -> V_124 . V_170 += V_285 ;
F_101 ( & V_67 -> V_169 ) ;
V_158 -> V_294 . V_160 += V_286 ;
V_158 -> V_294 . V_159 += V_285 ;
return V_286 ;
}
static int F_195 ( struct V_295 * V_250 )
{
struct V_157 * V_158 =
F_196 ( V_250 , struct V_157 , V_250 ) ;
struct V_1 * V_2 = V_158 -> V_2 ;
struct V_57 * V_120 ;
int V_296 = 0 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return V_297 ;
if ( ! F_197 ( V_158 ) )
return V_298 ;
F_121 (ring, q_vector->rx) {
V_296 = F_191 ( V_158 , V_120 , 4 ) ;
#ifdef F_198
if ( V_296 )
V_120 -> V_124 . V_299 += V_296 ;
else
V_120 -> V_124 . V_300 ++ ;
#endif
if ( V_296 )
break;
}
F_199 ( V_158 ) ;
return V_296 ;
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_157 * V_158 ;
int V_301 ;
T_1 V_117 ;
if ( V_2 -> V_302 > 32 ) {
T_1 V_303 = ( 1 << ( V_2 -> V_302 - 32 ) ) - 1 ;
F_71 ( & V_2 -> V_14 , V_304 , V_303 ) ;
}
for ( V_301 = 0 ; V_301 < V_2 -> V_189 ; V_301 ++ ) {
struct V_57 * V_120 ;
V_158 = V_2 -> V_158 [ V_301 ] ;
F_121 (ring, q_vector->rx)
F_73 ( V_2 , 0 , V_120 -> V_149 , V_301 ) ;
F_121 (ring, q_vector->tx)
F_73 ( V_2 , 1 , V_120 -> V_149 , V_301 ) ;
F_201 ( V_158 ) ;
}
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
F_73 ( V_2 , - 1 , V_305 ,
V_301 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_73 ( V_2 , - 1 , 1 , V_301 ) ;
break;
default:
break;
}
F_71 ( & V_2 -> V_14 , F_202 ( V_301 ) , 1950 ) ;
V_117 = V_306 ;
V_117 &= ~ ( V_307 |
V_308 |
V_309 ) ;
F_71 ( & V_2 -> V_14 , V_310 , V_117 ) ;
}
static void F_203 ( struct V_157 * V_158 ,
struct V_311 * V_312 )
{
int V_170 = V_312 -> V_159 ;
int V_144 = V_312 -> V_160 ;
T_1 V_313 ;
T_6 V_314 ;
T_4 V_315 = V_312 -> V_316 ;
if ( V_144 == 0 )
return;
V_313 = V_158 -> V_316 >> 2 ;
if ( V_313 == 0 )
return;
V_314 = V_170 / V_313 ;
switch ( V_315 ) {
case V_317 :
if ( V_314 > 10 )
V_315 = V_318 ;
break;
case V_318 :
if ( V_314 > 20 )
V_315 = V_319 ;
else if ( V_314 <= 10 )
V_315 = V_317 ;
break;
case V_319 :
if ( V_314 <= 20 )
V_315 = V_318 ;
break;
}
V_312 -> V_159 = 0 ;
V_312 -> V_160 = 0 ;
V_312 -> V_316 = V_315 ;
}
void F_201 ( struct V_157 * V_158 )
{
struct V_1 * V_2 = V_158 -> V_2 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_301 = V_158 -> V_301 ;
T_1 V_320 = V_158 -> V_316 & V_321 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
V_320 |= ( V_320 << 16 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_320 |= V_322 ;
break;
default:
break;
}
F_71 ( V_14 , F_202 ( V_301 ) , V_320 ) ;
}
static void F_204 ( struct V_157 * V_158 )
{
T_1 V_323 = V_158 -> V_316 ;
T_4 V_324 ;
F_203 ( V_158 , & V_158 -> V_162 ) ;
F_203 ( V_158 , & V_158 -> V_294 ) ;
V_324 = F_205 ( V_158 -> V_294 . V_316 , V_158 -> V_162 . V_316 ) ;
switch ( V_324 ) {
case V_317 :
V_323 = V_325 ;
break;
case V_318 :
V_323 = V_326 ;
break;
case V_319 :
V_323 = V_327 ;
break;
default:
break;
}
if ( V_323 != V_158 -> V_316 ) {
V_323 = ( 10 * V_323 * V_158 -> V_316 ) /
( ( 9 * V_323 ) + V_158 -> V_316 ) ;
V_158 -> V_316 = V_323 ;
F_201 ( V_158 ) ;
}
}
static void F_206 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_328 = V_2 -> V_329 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
if ( ! ( V_2 -> V_154 & V_330 ) &&
! ( V_2 -> V_154 & V_331 ) )
return;
V_2 -> V_154 &= ~ V_331 ;
switch ( V_14 -> V_21 ) {
case V_332 :
if ( ! ( V_328 & V_333 ) &&
! ( V_328 & V_334 ) )
return;
if ( ! ( V_328 & V_334 ) && V_14 -> V_108 . V_335 . V_336 ) {
T_1 V_20 ;
bool V_337 = false ;
V_14 -> V_108 . V_335 . V_336 ( V_14 , & V_20 , & V_337 , false ) ;
if ( V_337 )
return;
}
if ( V_14 -> V_338 . V_335 . V_339 ( V_14 ) != V_340 )
return;
break;
default:
if ( V_2 -> V_14 . V_108 . type >= V_112 )
return;
if ( ! ( V_328 & F_207 ( V_14 ) ) )
return;
break;
}
F_208 ( V_156 , L_70 , V_341 ) ;
V_2 -> V_329 = 0 ;
}
static void F_209 ( struct V_1 * V_2 , T_1 V_328 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ( V_2 -> V_139 & V_342 ) &&
( V_328 & F_210 ( V_14 ) ) ) {
F_208 ( V_172 , L_71 ) ;
F_71 ( V_14 , V_343 , F_210 ( V_14 ) ) ;
}
}
static void F_211 ( struct V_1 * V_2 , T_1 V_328 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! ( V_2 -> V_154 & V_330 ) )
return;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
if ( ( ( V_328 & F_207 ( V_14 ) ) ||
( V_328 & V_334 ) ) &&
( ! F_14 ( V_33 , & V_2 -> V_34 ) ) ) {
V_2 -> V_329 = V_328 ;
V_2 -> V_154 |= V_331 ;
F_13 ( V_2 ) ;
return;
}
return;
case V_112 :
if ( ! ( V_328 & V_344 ) )
return;
break;
default:
return;
}
F_208 ( V_156 , L_70 , V_341 ) ;
}
static inline bool F_212 ( struct V_15 * V_14 )
{
switch ( V_14 -> V_108 . type ) {
case V_109 :
if ( V_14 -> V_338 . type == V_345 )
return true ;
return false ;
case V_111 :
case V_114 :
switch ( V_14 -> V_108 . V_335 . V_346 ( V_14 ) ) {
case V_347 :
case V_348 :
return true ;
default:
return false ;
}
default:
return false ;
}
}
static void F_213 ( struct V_1 * V_2 , T_1 V_328 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_328 & F_214 ( V_14 ) ) {
F_71 ( V_14 , V_343 , F_214 ( V_14 ) ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_154 |= V_349 ;
F_13 ( V_2 ) ;
}
}
if ( V_328 & F_210 ( V_14 ) ) {
F_71 ( V_14 , V_343 , F_210 ( V_14 ) ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_139 |= V_350 ;
F_13 ( V_2 ) ;
}
}
}
static void F_215 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_351 ++ ;
V_2 -> V_139 |= V_352 ;
V_2 -> V_353 = V_171 ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
F_71 ( V_14 , V_354 , V_355 ) ;
F_216 ( V_14 ) ;
F_13 ( V_2 ) ;
}
}
static inline void F_217 ( struct V_1 * V_2 ,
T_6 V_116 )
{
T_1 V_117 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_117 = ( V_118 & V_116 ) ;
F_71 ( V_14 , V_356 , V_117 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_117 = ( V_116 & 0xFFFFFFFF ) ;
if ( V_117 )
F_71 ( V_14 , F_218 ( 0 ) , V_117 ) ;
V_117 = ( V_116 >> 32 ) ;
if ( V_117 )
F_71 ( V_14 , F_218 ( 1 ) , V_117 ) ;
break;
default:
break;
}
}
static inline void F_219 ( struct V_1 * V_2 ,
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
F_71 ( V_14 , F_220 ( 0 ) , V_117 ) ;
V_117 = ( V_116 >> 32 ) ;
if ( V_117 )
F_71 ( V_14 , F_220 ( 1 ) , V_117 ) ;
break;
default:
break;
}
}
static inline void F_221 ( struct V_1 * V_2 , bool V_357 ,
bool V_358 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_117 = ( V_306 & ~ V_118 ) ;
if ( V_2 -> V_139 & V_352 )
V_117 &= ~ V_309 ;
if ( V_2 -> V_154 & V_330 )
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_117 |= F_222 ( V_14 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
V_117 |= V_359 ;
break;
default:
break;
}
if ( V_2 -> V_139 & V_342 )
V_117 |= F_223 ( V_14 ) ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_117 |= F_223 ( V_14 ) ;
V_117 |= F_224 ( V_14 ) ;
case V_112 :
case V_113 :
case V_114 :
if ( V_2 -> V_14 . V_338 . type == V_360 )
V_117 |= V_361 ;
V_117 |= V_362 ;
V_117 |= V_308 ;
break;
default:
break;
}
if ( ( V_2 -> V_139 & V_363 ) &&
! ( V_2 -> V_154 & V_364 ) )
V_117 |= V_365 ;
F_71 ( & V_2 -> V_14 , V_356 , V_117 ) ;
if ( V_357 )
F_217 ( V_2 , ~ 0 ) ;
if ( V_358 )
F_216 ( & V_2 -> V_14 ) ;
}
static T_11 F_225 ( int V_366 , void * V_92 )
{
struct V_1 * V_2 = V_92 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_328 ;
V_328 = F_37 ( V_14 , V_119 ) ;
V_328 &= 0xFFFF0000 ;
F_71 ( V_14 , V_343 , V_328 ) ;
if ( V_328 & V_334 )
F_215 ( V_2 ) ;
if ( V_328 & V_367 )
F_226 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
if ( V_14 -> V_338 . type == V_360 &&
( V_328 & V_361 ) ) {
V_2 -> V_154 |= V_368 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_343 ,
V_361 ) ;
}
if ( V_328 & V_369 ) {
F_105 ( V_370 , L_72 ) ;
V_2 -> V_154 |= V_155 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_343 , V_369 ) ;
}
if ( V_328 & V_371 ) {
int V_372 = 0 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_120 = V_2 -> V_58 [ V_48 ] ;
if ( F_227 ( V_373 ,
& V_120 -> V_34 ) )
V_372 ++ ;
}
if ( V_372 ) {
F_71 ( V_14 , V_354 , V_374 ) ;
V_2 -> V_154 |= V_364 ;
F_13 ( V_2 ) ;
}
}
F_213 ( V_2 , V_328 ) ;
F_211 ( V_2 , V_328 ) ;
break;
default:
break;
}
F_209 ( V_2 , V_328 ) ;
if ( F_24 ( V_328 & V_375 ) )
F_228 ( V_2 , V_328 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_221 ( V_2 , false , false ) ;
return V_376 ;
}
static T_11 F_229 ( int V_366 , void * V_92 )
{
struct V_157 * V_158 = V_92 ;
if ( V_158 -> V_294 . V_120 || V_158 -> V_162 . V_120 )
F_230 ( & V_158 -> V_250 ) ;
return V_376 ;
}
int F_231 ( struct V_295 * V_250 , int V_161 )
{
struct V_157 * V_158 =
F_196 ( V_250 , struct V_157 , V_250 ) ;
struct V_1 * V_2 = V_158 -> V_2 ;
struct V_57 * V_120 ;
int V_377 ;
bool V_378 = true ;
#ifdef F_232
if ( V_2 -> V_139 & V_187 )
F_119 ( V_158 ) ;
#endif
F_121 (ring, q_vector->tx)
V_378 &= ! ! F_94 ( V_158 , V_120 ) ;
if ( ! F_233 ( V_158 ) )
return V_161 ;
if ( V_158 -> V_294 . V_88 > 1 )
V_377 = F_205 ( V_161 / V_158 -> V_294 . V_88 , 1 ) ;
else
V_377 = V_161 ;
F_121 (ring, q_vector->rx)
V_378 &= ( F_191 ( V_158 , V_120 ,
V_377 ) < V_377 ) ;
F_234 ( V_158 ) ;
if ( ! V_378 )
return V_161 ;
F_235 ( V_250 ) ;
if ( V_2 -> V_379 & 1 )
F_204 ( V_158 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_217 ( V_2 , ( ( T_6 ) 1 << V_158 -> V_301 ) ) ;
return 0 ;
}
static int F_236 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
int V_380 , V_17 ;
int V_381 = 0 , V_382 = 0 ;
for ( V_380 = 0 ; V_380 < V_2 -> V_189 ; V_380 ++ ) {
struct V_157 * V_158 = V_2 -> V_158 [ V_380 ] ;
struct V_383 * V_384 = & V_2 -> V_385 [ V_380 ] ;
if ( V_158 -> V_162 . V_120 && V_158 -> V_294 . V_120 ) {
snprintf ( V_158 -> V_53 , sizeof( V_158 -> V_53 ) - 1 ,
L_73 , V_55 -> V_53 , L_74 , V_381 ++ ) ;
V_382 ++ ;
} else if ( V_158 -> V_294 . V_120 ) {
snprintf ( V_158 -> V_53 , sizeof( V_158 -> V_53 ) - 1 ,
L_73 , V_55 -> V_53 , L_75 , V_381 ++ ) ;
} else if ( V_158 -> V_162 . V_120 ) {
snprintf ( V_158 -> V_53 , sizeof( V_158 -> V_53 ) - 1 ,
L_73 , V_55 -> V_53 , L_76 , V_382 ++ ) ;
} else {
continue;
}
V_17 = F_237 ( V_384 -> V_380 , & F_229 , 0 ,
V_158 -> V_53 , V_158 ) ;
if ( V_17 ) {
F_103 ( V_172 , L_77
L_78 , V_17 ) ;
goto V_386;
}
if ( V_2 -> V_139 & V_363 ) {
F_238 ( V_384 -> V_380 ,
& V_158 -> V_387 ) ;
}
}
V_17 = F_237 ( V_2 -> V_385 [ V_380 ] . V_380 ,
F_225 , 0 , V_55 -> V_53 , V_2 ) ;
if ( V_17 ) {
F_103 ( V_172 , L_79 , V_17 ) ;
goto V_386;
}
return 0 ;
V_386:
while ( V_380 ) {
V_380 -- ;
F_238 ( V_2 -> V_385 [ V_380 ] . V_380 ,
NULL ) ;
F_239 ( V_2 -> V_385 [ V_380 ] . V_380 ,
V_2 -> V_158 [ V_380 ] ) ;
}
V_2 -> V_139 &= ~ V_388 ;
F_240 ( V_2 -> V_9 ) ;
F_241 ( V_2 -> V_385 ) ;
V_2 -> V_385 = NULL ;
return V_17 ;
}
static T_11 F_242 ( int V_366 , void * V_92 )
{
struct V_1 * V_2 = V_92 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_157 * V_158 = V_2 -> V_158 [ 0 ] ;
T_1 V_328 ;
F_71 ( V_14 , V_354 , V_389 ) ;
V_328 = F_37 ( V_14 , V_343 ) ;
if ( ! V_328 ) {
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_221 ( V_2 , true , true ) ;
return V_390 ;
}
if ( V_328 & V_334 )
F_215 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
F_213 ( V_2 , V_328 ) ;
case V_112 :
case V_113 :
case V_114 :
if ( V_328 & V_369 ) {
F_105 ( V_370 , L_72 ) ;
V_2 -> V_154 |= V_155 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_343 , V_369 ) ;
}
F_211 ( V_2 , V_328 ) ;
break;
default:
break;
}
F_209 ( V_2 , V_328 ) ;
if ( F_24 ( V_328 & V_375 ) )
F_228 ( V_2 , V_328 ) ;
F_230 ( & V_158 -> V_250 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_221 ( V_2 , false , false ) ;
return V_376 ;
}
static int F_243 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
int V_17 ;
if ( V_2 -> V_139 & V_388 )
V_17 = F_236 ( V_2 ) ;
else if ( V_2 -> V_139 & V_391 )
V_17 = F_237 ( V_2 -> V_9 -> V_366 , F_242 , 0 ,
V_55 -> V_53 , V_2 ) ;
else
V_17 = F_237 ( V_2 -> V_9 -> V_366 , F_242 , V_392 ,
V_55 -> V_53 , V_2 ) ;
if ( V_17 )
F_103 ( V_172 , L_80 , V_17 ) ;
return V_17 ;
}
static void F_244 ( struct V_1 * V_2 )
{
int V_380 ;
if ( ! ( V_2 -> V_139 & V_388 ) ) {
F_239 ( V_2 -> V_9 -> V_366 , V_2 ) ;
return;
}
for ( V_380 = 0 ; V_380 < V_2 -> V_189 ; V_380 ++ ) {
struct V_157 * V_158 = V_2 -> V_158 [ V_380 ] ;
struct V_383 * V_384 = & V_2 -> V_385 [ V_380 ] ;
if ( ! V_158 -> V_294 . V_120 && ! V_158 -> V_162 . V_120 )
continue;
F_238 ( V_384 -> V_380 , NULL ) ;
F_239 ( V_384 -> V_380 , V_158 ) ;
}
F_239 ( V_2 -> V_385 [ V_380 ++ ] . V_380 , V_2 ) ;
}
static inline void F_245 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
F_71 ( & V_2 -> V_14 , V_354 , ~ 0 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_71 ( & V_2 -> V_14 , V_354 , 0xFFFF0000 ) ;
F_71 ( & V_2 -> V_14 , F_220 ( 0 ) , ~ 0 ) ;
F_71 ( & V_2 -> V_14 , F_220 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_216 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_139 & V_388 ) {
int V_380 ;
for ( V_380 = 0 ; V_380 < V_2 -> V_189 ; V_380 ++ )
F_246 ( V_2 -> V_385 [ V_380 ] . V_380 ) ;
F_246 ( V_2 -> V_385 [ V_380 ++ ] . V_380 ) ;
} else {
F_246 ( V_2 -> V_9 -> V_366 ) ;
}
}
static void F_247 ( struct V_1 * V_2 )
{
struct V_157 * V_158 = V_2 -> V_158 [ 0 ] ;
F_201 ( V_158 ) ;
F_73 ( V_2 , 0 , 0 , 0 ) ;
F_73 ( V_2 , 1 , 0 , 0 ) ;
F_105 ( V_14 , L_81 ) ;
}
void F_248 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_393 = V_120 -> V_81 ;
int V_394 = 10 ;
T_1 V_395 = V_396 ;
T_4 V_149 = V_120 -> V_149 ;
F_71 ( V_14 , F_50 ( V_149 ) , 0 ) ;
F_216 ( V_14 ) ;
F_71 ( V_14 , F_45 ( V_149 ) ,
( V_393 & F_249 ( 32 ) ) ) ;
F_71 ( V_14 , F_46 ( V_149 ) , ( V_393 >> 32 ) ) ;
F_71 ( V_14 , F_47 ( V_149 ) ,
V_120 -> V_88 * sizeof( union V_61 ) ) ;
F_71 ( V_14 , F_48 ( V_149 ) , 0 ) ;
F_71 ( V_14 , F_49 ( V_149 ) , 0 ) ;
V_120 -> V_146 = V_2 -> V_397 + F_49 ( V_149 ) ;
if ( ! V_120 -> V_158 || ( V_120 -> V_158 -> V_316 < V_325 ) )
V_395 |= ( 1 << 16 ) ;
else
V_395 |= ( 8 << 16 ) ;
V_395 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_139 & V_363 ) {
V_120 -> V_398 = V_2 -> V_398 ;
V_120 -> V_399 = 0 ;
F_250 ( V_373 , & V_120 -> V_34 ) ;
} else {
V_120 -> V_398 = 0 ;
}
if ( ! F_15 ( V_400 , & V_120 -> V_34 ) ) {
struct V_157 * V_158 = V_120 -> V_158 ;
if ( V_158 )
F_251 ( V_120 -> V_55 ,
& V_158 -> V_387 ,
V_120 -> V_86 ) ;
}
F_34 ( V_132 , & V_120 -> V_34 ) ;
F_71 ( V_14 , F_50 ( V_149 ) , V_395 ) ;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_401 ) & V_402 ) )
return;
do {
F_252 ( 1000 , 2000 ) ;
V_395 = F_37 ( V_14 , F_50 ( V_149 ) ) ;
} while ( -- V_394 && ! ( V_395 & V_396 ) );
if ( ! V_394 )
F_103 ( V_156 , L_82 , V_149 ) ;
}
static void F_253 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_403 , V_404 ;
T_4 V_405 = F_254 ( V_2 -> V_55 ) ;
if ( V_14 -> V_108 . type == V_109 )
return;
V_403 = F_37 ( V_14 , V_406 ) ;
V_403 |= V_407 ;
F_71 ( V_14 , V_406 , V_403 ) ;
if ( V_2 -> V_139 & V_408 ) {
V_404 = V_409 ;
if ( V_405 > 4 )
V_404 |= V_410 | V_411 ;
else if ( V_405 > 1 )
V_404 |= V_410 | V_412 ;
else if ( V_2 -> V_413 [ V_414 ] . V_415 == 4 )
V_404 |= V_416 ;
else
V_404 |= V_417 ;
} else {
if ( V_405 > 4 )
V_404 = V_410 | V_411 ;
else if ( V_405 > 1 )
V_404 = V_410 | V_412 ;
else
V_404 = V_418 ;
}
F_71 ( V_14 , V_419 , V_404 ) ;
if ( V_405 ) {
T_1 V_420 = F_37 ( V_14 , V_421 ) ;
V_420 |= V_422 ;
F_71 ( V_14 , V_421 , V_420 ) ;
}
V_403 &= ~ V_407 ;
F_71 ( V_14 , V_406 , V_403 ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_423 ;
T_1 V_48 ;
F_253 ( V_2 ) ;
if ( V_14 -> V_108 . type != V_109 ) {
V_423 = F_37 ( V_14 , V_424 ) ;
V_423 |= V_425 ;
F_71 ( V_14 , V_424 , V_423 ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_248 ( V_2 , V_2 -> V_58 [ V_48 ] ) ;
}
static void F_256 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_149 = V_120 -> V_149 ;
T_1 V_426 = F_37 ( V_14 , F_36 ( V_149 ) ) ;
V_426 |= V_427 ;
F_71 ( V_14 , F_36 ( V_149 ) , V_426 ) ;
}
static void F_257 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_149 = V_120 -> V_149 ;
T_1 V_426 = F_37 ( V_14 , F_36 ( V_149 ) ) ;
V_426 &= ~ V_427 ;
F_71 ( V_14 , F_36 ( V_149 ) , V_426 ) ;
}
static void F_258 ( struct V_1 * V_2 ,
struct V_57 * V_67 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_426 ;
T_4 V_149 = V_67 -> V_149 ;
if ( V_14 -> V_108 . type == V_109 ) {
T_2 V_117 = V_2 -> V_413 [ V_414 ] . V_117 ;
V_149 &= V_117 ;
}
V_426 = V_265 << V_428 ;
V_426 |= F_69 ( V_67 ) >> V_429 ;
V_426 |= V_430 ;
F_71 ( V_14 , F_36 ( V_149 ) , V_426 ) ;
}
T_1 F_259 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_108 . type < V_113 )
return 128 ;
else if ( V_2 -> V_139 & V_408 )
return 64 ;
else
return 512 ;
}
static void F_260 ( struct V_1 * V_2 )
{
T_1 V_48 , V_431 = F_259 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_432 = 0 ;
T_1 V_433 ;
T_4 * V_434 = V_2 -> V_435 ;
if ( V_2 -> V_14 . V_108 . type == V_109 )
V_433 = 0x11 ;
else
V_433 = 0x1 ;
for ( V_48 = 0 ; V_48 < V_431 ; V_48 ++ ) {
V_432 |= V_433 * V_434 [ V_48 ] << ( V_48 & 0x3 ) * 8 ;
if ( ( V_48 & 3 ) == 3 ) {
if ( V_48 < 128 )
F_71 ( V_14 , F_261 ( V_48 >> 2 ) , V_432 ) ;
else
F_71 ( V_14 , F_262 ( ( V_48 >> 2 ) - 32 ) ,
V_432 ) ;
V_432 = 0 ;
}
}
}
static void F_263 ( struct V_1 * V_2 )
{
T_1 V_48 , V_431 = F_259 ( V_2 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_436 = 0 ;
unsigned int V_437 = V_2 -> V_302 ;
for ( V_48 = 0 ; V_48 < V_431 ; V_48 ++ ) {
V_436 |= ( T_1 ) V_2 -> V_435 [ V_48 ] << ( V_48 & 0x3 ) * 8 ;
if ( ( V_48 & 3 ) == 3 ) {
F_71 ( V_14 , F_264 ( V_48 >> 2 , V_437 ) ,
V_436 ) ;
V_436 = 0 ;
}
}
}
static void F_265 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_48 , V_49 ;
T_1 V_431 = F_259 ( V_2 ) ;
T_2 V_438 = V_2 -> V_413 [ V_414 ] . V_415 ;
if ( ( V_2 -> V_139 & V_408 ) && ( V_438 < 2 ) )
V_438 = 2 ;
for ( V_48 = 0 ; V_48 < 10 ; V_48 ++ )
F_71 ( V_14 , F_266 ( V_48 ) , V_2 -> V_439 [ V_48 ] ) ;
memset ( V_2 -> V_435 , 0 , sizeof( V_2 -> V_435 ) ) ;
for ( V_48 = 0 , V_49 = 0 ; V_48 < V_431 ; V_48 ++ , V_49 ++ ) {
if ( V_49 == V_438 )
V_49 = 0 ;
V_2 -> V_435 [ V_48 ] = V_49 ;
}
F_260 ( V_2 ) ;
}
static void F_267 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_438 = V_2 -> V_413 [ V_414 ] . V_415 ;
unsigned int V_437 = V_2 -> V_302 ;
int V_48 , V_49 ;
for ( V_48 = 0 ; V_48 < 10 ; V_48 ++ )
F_71 ( V_14 , F_268 ( V_48 , V_437 ) ,
V_2 -> V_439 [ V_48 ] ) ;
for ( V_48 = 0 , V_49 = 0 ; V_48 < 64 ; V_48 ++ , V_49 ++ ) {
if ( V_49 == V_438 )
V_49 = 0 ;
V_2 -> V_435 [ V_48 ] = V_49 ;
}
F_263 ( V_2 ) ;
}
static void F_269 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_440 = 0 , V_441 = 0 , V_442 = 0 ;
T_1 V_443 ;
V_443 = F_37 ( V_14 , V_444 ) ;
V_443 |= V_445 ;
F_71 ( V_14 , V_444 , V_443 ) ;
if ( V_2 -> V_14 . V_108 . type == V_109 ) {
if ( V_2 -> V_413 [ V_414 ] . V_117 )
V_440 = V_446 ;
} else {
T_4 V_405 = F_254 ( V_2 -> V_55 ) ;
if ( V_2 -> V_139 & V_408 ) {
if ( V_405 > 4 )
V_440 = V_447 ;
else if ( V_405 > 1 )
V_440 = V_448 ;
else if ( V_2 -> V_413 [ V_414 ] . V_415 == 4 )
V_440 = V_449 ;
else
V_440 = V_450 ;
} else {
if ( V_405 > 4 )
V_440 = V_451 ;
else if ( V_405 > 1 )
V_440 = V_452 ;
else
V_440 = V_446 ;
}
}
V_441 |= V_453 |
V_454 |
V_455 |
V_456 ;
if ( V_2 -> V_154 & V_457 )
V_441 |= V_458 ;
if ( V_2 -> V_154 & V_459 )
V_441 |= V_460 ;
F_270 ( V_2 -> V_439 , sizeof( V_2 -> V_439 ) ) ;
if ( ( V_14 -> V_108 . type >= V_113 ) &&
( V_2 -> V_139 & V_408 ) ) {
unsigned int V_437 = V_2 -> V_302 ;
V_440 |= V_461 ;
F_71 ( V_14 , V_462 , V_440 ) ;
F_267 ( V_2 ) ;
V_442 = V_446 ;
V_442 |= V_441 ;
F_71 ( V_14 , F_271 ( V_437 ) , V_442 ) ;
} else {
F_265 ( V_2 ) ;
V_440 |= V_441 ;
F_71 ( V_14 , V_462 , V_440 ) ;
}
}
static void F_272 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_463 ;
T_4 V_149 = V_120 -> V_149 ;
if ( ! F_164 ( V_120 ) )
return;
V_463 = F_37 ( V_14 , F_273 ( V_149 ) ) ;
V_463 |= V_464 ;
V_463 |= V_465 ;
F_71 ( V_14 , F_273 ( V_149 ) , V_463 ) ;
}
static void F_274 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_394 = V_466 ;
T_1 V_467 ;
T_4 V_149 = V_120 -> V_149 ;
if ( F_22 ( V_14 -> V_39 ) )
return;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_401 ) & V_402 ) )
return;
do {
F_252 ( 1000 , 2000 ) ;
V_467 = F_37 ( V_14 , F_42 ( V_149 ) ) ;
} while ( -- V_394 && ! ( V_467 & V_468 ) );
if ( ! V_394 ) {
F_103 ( V_156 , L_83
L_84 , V_149 ) ;
}
}
void F_275 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_394 = V_466 ;
T_1 V_467 ;
T_4 V_149 = V_120 -> V_149 ;
if ( F_22 ( V_14 -> V_39 ) )
return;
V_467 = F_37 ( V_14 , F_42 ( V_149 ) ) ;
V_467 &= ~ V_468 ;
F_71 ( V_14 , F_42 ( V_149 ) , V_467 ) ;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_401 ) & V_402 ) )
return;
do {
F_276 ( 10 ) ;
V_467 = F_37 ( V_14 , F_42 ( V_149 ) ) ;
} while ( -- V_394 && ( V_467 & V_468 ) );
if ( ! V_394 ) {
F_103 ( V_156 , L_85
L_84 , V_149 ) ;
}
}
void F_277 ( struct V_1 * V_2 ,
struct V_57 * V_120 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_469 = V_120 -> V_81 ;
T_1 V_467 ;
T_4 V_149 = V_120 -> V_149 ;
V_467 = F_37 ( V_14 , F_42 ( V_149 ) ) ;
F_275 ( V_2 , V_120 ) ;
F_71 ( V_14 , F_43 ( V_149 ) , ( V_469 & F_249 ( 32 ) ) ) ;
F_71 ( V_14 , F_44 ( V_149 ) , ( V_469 >> 32 ) ) ;
F_71 ( V_14 , F_39 ( V_149 ) ,
V_120 -> V_88 * sizeof( union V_68 ) ) ;
F_71 ( V_14 , F_40 ( V_149 ) , 0 ) ;
F_71 ( V_14 , F_41 ( V_149 ) , 0 ) ;
V_120 -> V_146 = V_2 -> V_397 + F_41 ( V_149 ) ;
F_258 ( V_2 , V_120 ) ;
F_272 ( V_2 , V_120 ) ;
if ( V_14 -> V_108 . type == V_109 ) {
V_467 &= ~ 0x3FFFFF ;
V_467 |= 0x080420 ;
}
V_467 |= V_468 ;
F_71 ( V_14 , F_42 ( V_149 ) , V_467 ) ;
F_274 ( V_2 , V_120 ) ;
F_142 ( V_120 , F_110 ( V_120 ) ) ;
}
static void F_278 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_438 = V_2 -> V_413 [ V_414 ] . V_415 ;
T_2 V_470 ;
T_1 V_471 = V_472 |
V_473 |
V_474 |
V_475 |
V_476 ;
if ( V_14 -> V_108 . type == V_109 )
return;
if ( V_438 > 3 )
V_471 |= 2 << 29 ;
else if ( V_438 > 1 )
V_471 |= 1 << 29 ;
F_279 (pool, &adapter->fwd_bitmask, 32 )
F_71 ( V_14 , F_280 ( F_281 ( V_470 ) ) , V_471 ) ;
}
static void F_282 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_177 , V_477 ;
T_1 V_478 , V_479 ;
int V_48 ;
if ( ! ( V_2 -> V_139 & V_408 ) )
return;
V_479 = F_37 ( V_14 , V_480 ) ;
V_479 |= V_481 ;
V_479 &= ~ V_482 ;
V_479 |= F_281 ( 0 ) << V_483 ;
V_479 |= V_484 ;
F_71 ( V_14 , V_480 , V_479 ) ;
V_477 = F_281 ( 0 ) % 32 ;
V_177 = ( F_281 ( 0 ) >= 32 ) ? 1 : 0 ;
F_71 ( V_14 , F_283 ( V_177 ) , ( ~ 0 ) << V_477 ) ;
F_71 ( V_14 , F_283 ( V_177 ^ 1 ) , V_177 - 1 ) ;
F_71 ( V_14 , F_284 ( V_177 ) , ( ~ 0 ) << V_477 ) ;
F_71 ( V_14 , F_284 ( V_177 ^ 1 ) , V_177 - 1 ) ;
if ( V_2 -> V_485 == V_486 )
F_71 ( V_14 , V_487 , V_488 ) ;
V_14 -> V_108 . V_335 . V_489 ( V_14 , 0 , F_281 ( 0 ) ) ;
switch ( V_2 -> V_413 [ V_490 ] . V_117 ) {
case V_491 :
V_478 = V_492 ;
break;
case V_493 :
V_478 = V_494 ;
break;
default:
V_478 = V_495 ;
break;
}
F_71 ( V_14 , V_496 , V_478 ) ;
V_14 -> V_108 . V_335 . V_497 ( V_14 , ( V_2 -> V_302 != 0 ) ,
V_2 -> V_302 ) ;
if ( V_14 -> V_108 . V_335 . V_498 )
F_71 ( V_14 , F_285 ( V_499 ) ,
( V_500 |
V_501 |
V_502 ) ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_302 ; V_48 ++ ) {
if ( ! V_2 -> V_503 [ V_48 ] . V_504 )
F_286 ( V_2 -> V_55 , V_48 , false ) ;
if ( V_14 -> V_108 . V_335 . V_498 )
V_14 -> V_108 . V_335 . V_498 ( V_14 , true , V_48 ) ;
F_287 ( V_2 -> V_55 , V_48 ,
V_2 -> V_503 [ V_48 ] . V_505 ) ;
}
}
static void F_288 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_55 = V_2 -> V_55 ;
int V_506 = V_55 -> V_290 + V_507 + V_508 ;
struct V_57 * V_67 ;
int V_48 ;
T_1 V_509 , V_510 ;
#ifdef F_175
if ( ( V_2 -> V_139 & V_511 ) &&
( V_506 < V_512 ) )
V_506 = V_512 ;
#endif
if ( V_506 < ( V_513 + V_508 ) )
V_506 = ( V_513 + V_508 ) ;
V_509 = F_37 ( V_14 , V_514 ) ;
if ( V_506 != ( V_509 >> V_515 ) ) {
V_509 &= ~ V_516 ;
V_509 |= V_506 << V_515 ;
F_71 ( V_14 , V_514 , V_509 ) ;
}
V_510 = F_37 ( V_14 , V_517 ) ;
V_510 |= V_518 ;
F_71 ( V_14 , V_517 , V_510 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_67 = V_2 -> V_67 [ V_48 ] ;
if ( V_2 -> V_154 & V_519 )
F_289 ( V_67 ) ;
else
F_290 ( V_67 ) ;
}
}
static void F_291 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_520 = F_37 ( V_14 , V_521 ) ;
switch ( V_14 -> V_108 . type ) {
case V_113 :
case V_114 :
case V_109 :
V_520 |= V_522 ;
break;
case V_111 :
case V_112 :
F_71 ( V_14 , V_523 ,
( V_524 | F_37 ( V_14 , V_523 ) ) ) ;
V_520 &= ~ V_525 ;
V_520 |= ( V_526 | V_527 ) ;
V_520 |= V_528 ;
break;
default:
return;
}
F_71 ( V_14 , V_521 , V_520 ) ;
}
static void F_292 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
T_1 V_182 , V_529 ;
V_14 -> V_108 . V_335 . V_530 ( V_14 ) ;
F_278 ( V_2 ) ;
F_291 ( V_2 ) ;
V_529 = F_37 ( V_14 , V_531 ) ;
V_529 &= ~ V_532 ;
if ( ! ( V_2 -> V_154 & V_519 ) )
V_529 |= V_532 ;
F_71 ( V_14 , V_531 , V_529 ) ;
F_269 ( V_2 ) ;
F_288 ( V_2 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
F_277 ( V_2 , V_2 -> V_67 [ V_48 ] ) ;
V_182 = F_37 ( V_14 , V_533 ) ;
if ( V_14 -> V_108 . type == V_109 )
V_182 |= V_534 ;
V_182 |= V_535 ;
V_14 -> V_108 . V_335 . V_536 ( V_14 , V_182 ) ;
}
static int F_293 ( struct V_54 * V_55 ,
T_12 V_537 , T_2 V_246 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_108 . V_335 . V_538 ( & V_2 -> V_14 , V_246 , F_281 ( 0 ) , true ) ;
F_250 ( V_246 , V_2 -> V_539 ) ;
return 0 ;
}
static int F_294 ( struct V_54 * V_55 ,
T_12 V_537 , T_2 V_246 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_108 . V_335 . V_538 ( & V_2 -> V_14 , V_246 , F_281 ( 0 ) , false ) ;
F_34 ( V_246 , V_2 -> V_539 ) ;
return 0 ;
}
static void F_295 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_540 ;
int V_48 , V_49 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_540 = F_37 ( V_14 , V_541 ) ;
V_540 &= ~ V_542 ;
F_71 ( V_14 , V_541 , V_540 ) ;
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
V_540 = F_37 ( V_14 , F_42 ( V_49 ) ) ;
V_540 &= ~ V_543 ;
F_71 ( V_14 , F_42 ( V_49 ) , V_540 ) ;
}
break;
default:
break;
}
}
static void F_296 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_540 ;
int V_48 , V_49 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_540 = F_37 ( V_14 , V_541 ) ;
V_540 |= V_542 ;
F_71 ( V_14 , V_541 , V_540 ) ;
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
V_540 = F_37 ( V_14 , F_42 ( V_49 ) ) ;
V_540 |= V_543 ;
F_71 ( V_14 , F_42 ( V_49 ) , V_540 ) ;
}
break;
default:
break;
}
}
static void F_297 ( struct V_1 * V_2 )
{
T_2 V_246 ;
F_293 ( V_2 -> V_55 , F_156 ( V_248 ) , 0 ) ;
F_279 (vid, adapter->active_vlans, VLAN_N_VID)
F_293 ( V_2 -> V_55 , F_156 ( V_248 ) , V_246 ) ;
}
static int F_298 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! F_57 ( V_55 ) )
return 0 ;
if ( V_14 -> V_108 . V_335 . V_544 )
V_14 -> V_108 . V_335 . V_544 ( V_14 , V_55 ) ;
else
return - V_545 ;
#ifdef F_299
F_300 ( V_2 ) ;
#endif
return F_301 ( V_55 ) ;
}
void F_302 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_546 ; V_48 ++ ) {
if ( V_2 -> V_547 [ V_48 ] . V_34 & V_548 )
V_14 -> V_108 . V_335 . V_549 ( V_14 , V_48 , V_2 -> V_547 [ V_48 ] . V_550 ,
V_2 -> V_547 [ V_48 ] . V_104 ,
V_551 ) ;
else
V_14 -> V_108 . V_335 . V_552 ( V_14 , V_48 ) ;
V_2 -> V_547 [ V_48 ] . V_34 &= ~ ( V_553 ) ;
}
}
static void F_303 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_546 ; V_48 ++ ) {
if ( V_2 -> V_547 [ V_48 ] . V_34 & V_553 ) {
if ( V_2 -> V_547 [ V_48 ] . V_34 &
V_548 )
V_14 -> V_108 . V_335 . V_549 ( V_14 , V_48 ,
V_2 -> V_547 [ V_48 ] . V_550 ,
V_2 -> V_547 [ V_48 ] . V_104 ,
V_551 ) ;
else
V_14 -> V_108 . V_335 . V_552 ( V_14 , V_48 ) ;
V_2 -> V_547 [ V_48 ] . V_34 &=
~ ( V_553 ) ;
}
}
}
static void F_304 ( struct V_1 * V_2 )
{
int V_48 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_546 ; V_48 ++ ) {
V_2 -> V_547 [ V_48 ] . V_34 |= V_553 ;
V_2 -> V_547 [ V_48 ] . V_34 &= ~ V_548 ;
F_305 ( V_2 -> V_547 [ V_48 ] . V_550 ) ;
V_2 -> V_547 [ V_48 ] . V_104 = 0 ;
}
F_303 ( V_2 ) ;
}
static int F_306 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 , V_88 = 0 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_546 ; V_48 ++ ) {
if ( V_2 -> V_547 [ V_48 ] . V_34 == 0 )
V_88 ++ ;
}
return V_88 ;
}
static void F_307 ( struct V_1 * V_2 ,
T_4 * V_550 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
memcpy ( & V_2 -> V_547 [ 0 ] . V_550 , V_550 , V_554 ) ;
V_2 -> V_547 [ 0 ] . V_104 = F_281 ( 0 ) ;
V_2 -> V_547 [ 0 ] . V_34 = ( V_555 |
V_548 ) ;
V_14 -> V_108 . V_335 . V_549 ( V_14 , 0 , V_2 -> V_547 [ 0 ] . V_550 ,
V_2 -> V_547 [ 0 ] . V_104 ,
V_551 ) ;
}
int F_308 ( struct V_1 * V_2 , T_4 * V_550 , T_2 V_104 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
if ( F_309 ( V_550 ) )
return - V_556 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_546 ; V_48 ++ ) {
if ( V_2 -> V_547 [ V_48 ] . V_34 & V_548 )
continue;
V_2 -> V_547 [ V_48 ] . V_34 |= ( V_553 |
V_548 ) ;
F_310 ( V_2 -> V_547 [ V_48 ] . V_550 , V_550 ) ;
V_2 -> V_547 [ V_48 ] . V_104 = V_104 ;
F_303 ( V_2 ) ;
return V_48 ;
}
return - V_545 ;
}
int F_311 ( struct V_1 * V_2 , T_4 * V_550 , T_2 V_104 )
{
int V_48 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_309 ( V_550 ) )
return - V_556 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_546 ; V_48 ++ ) {
if ( F_312 ( V_550 , V_2 -> V_547 [ V_48 ] . V_550 ) &&
V_2 -> V_547 [ V_48 ] . V_104 == V_104 ) {
V_2 -> V_547 [ V_48 ] . V_34 |= V_553 ;
V_2 -> V_547 [ V_48 ] . V_34 &= ~ V_548 ;
F_305 ( V_2 -> V_547 [ V_48 ] . V_550 ) ;
V_2 -> V_547 [ V_48 ] . V_104 = 0 ;
F_303 ( V_2 ) ;
return 0 ;
}
}
return - V_545 ;
}
static int F_313 ( struct V_54 * V_55 , int V_557 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_88 = 0 ;
if ( F_314 ( V_55 ) > F_306 ( V_2 ) )
return - V_545 ;
if ( ! F_315 ( V_55 ) ) {
struct V_558 * V_559 ;
F_316 (ha, netdev) {
F_311 ( V_2 , V_559 -> V_550 , V_557 ) ;
F_308 ( V_2 , V_559 -> V_550 , V_557 ) ;
V_88 ++ ;
}
}
return V_88 ;
}
void F_317 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_560 , V_561 = V_562 | V_563 ;
T_1 V_540 ;
int V_88 ;
V_560 = F_37 ( V_14 , V_564 ) ;
V_540 = F_37 ( V_14 , V_541 ) ;
V_560 &= ~ V_565 ;
V_560 |= V_566 ;
V_560 |= V_567 ;
V_560 |= V_568 ;
V_560 &= ~ ( V_569 | V_570 ) ;
V_540 &= ~ ( V_571 | V_572 ) ;
if ( V_55 -> V_139 & V_573 ) {
V_14 -> V_574 . V_575 = true ;
V_560 |= ( V_569 | V_570 ) ;
V_561 |= V_576 ;
if ( V_2 -> V_139 & ( V_577 |
V_408 ) )
V_540 |= ( V_571 | V_572 ) ;
} else {
if ( V_55 -> V_139 & V_578 ) {
V_560 |= V_570 ;
V_561 |= V_576 ;
}
V_540 |= V_571 ;
V_14 -> V_574 . V_575 = false ;
}
V_88 = F_313 ( V_55 , F_281 ( 0 ) ) ;
if ( V_88 < 0 ) {
V_560 |= V_569 ;
V_561 |= V_579 ;
}
V_88 = F_298 ( V_55 ) ;
if ( V_88 < 0 ) {
V_560 |= V_570 ;
V_561 |= V_576 ;
} else if ( V_88 ) {
V_561 |= V_580 ;
}
if ( V_14 -> V_108 . type != V_109 ) {
V_561 |= F_37 ( V_14 , F_318 ( F_281 ( 0 ) ) ) &
~ ( V_576 | V_580 |
V_579 ) ;
F_71 ( V_14 , F_318 ( F_281 ( 0 ) ) , V_561 ) ;
}
if ( V_2 -> V_55 -> V_196 & V_269 ) {
V_560 |= ( V_565 |
V_566 |
V_568 ) ;
V_560 &= ~ ( V_567 ) ;
}
F_71 ( V_14 , V_541 , V_540 ) ;
F_71 ( V_14 , V_564 , V_560 ) ;
if ( V_55 -> V_196 & V_244 )
F_296 ( V_2 ) ;
else
F_295 ( V_2 ) ;
}
static void F_319 ( struct V_1 * V_2 )
{
int V_581 ;
for ( V_581 = 0 ; V_581 < V_2 -> V_189 ; V_581 ++ ) {
F_320 ( V_2 -> V_158 [ V_581 ] ) ;
F_321 ( & V_2 -> V_158 [ V_581 ] -> V_250 ) ;
}
}
static void F_322 ( struct V_1 * V_2 )
{
int V_581 ;
for ( V_581 = 0 ; V_581 < V_2 -> V_189 ; V_581 ++ ) {
F_323 ( & V_2 -> V_158 [ V_581 ] -> V_250 ) ;
while ( ! F_324 ( V_2 -> V_158 [ V_581 ] ) ) {
F_51 ( L_86 , V_581 ) ;
F_252 ( 1000 , 20000 ) ;
}
}
}
static void F_325 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_506 = V_2 -> V_55 -> V_290 + V_507 + V_508 ;
if ( ! ( V_2 -> V_139 & V_140 ) ) {
if ( V_14 -> V_108 . type == V_109 )
F_326 ( V_2 -> V_55 , 65536 ) ;
return;
}
if ( V_14 -> V_108 . type == V_109 )
F_326 ( V_2 -> V_55 , 32768 ) ;
#ifdef F_175
if ( V_2 -> V_55 -> V_196 & V_582 )
V_506 = F_205 ( V_506 , V_512 ) ;
#endif
if ( V_2 -> V_583 & V_584 ) {
F_327 ( V_14 , & V_2 -> V_136 , V_506 ,
V_585 ) ;
F_327 ( V_14 , & V_2 -> V_136 , V_506 ,
V_586 ) ;
F_328 ( V_14 , & V_2 -> V_136 ) ;
} else if ( V_2 -> V_587 && V_2 -> V_138 ) {
F_329 ( & V_2 -> V_14 ,
V_2 -> V_587 ,
V_506 ) ;
F_330 ( & V_2 -> V_14 ,
V_2 -> V_138 -> V_135 ,
V_2 -> V_587 -> V_588 ) ;
}
if ( V_14 -> V_108 . type != V_109 ) {
T_1 V_589 = 0 ;
T_2 V_438 = V_2 -> V_413 [ V_414 ] . V_415 - 1 ;
while ( V_438 ) {
V_589 ++ ;
V_438 >>= 1 ;
}
F_71 ( V_14 , V_590 , V_589 * 0x11111111 ) ;
}
}
static int F_331 ( struct V_1 * V_2 , int V_591 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_73 = V_2 -> V_55 ;
int V_370 , V_134 , V_592 , V_593 ;
T_1 V_594 , V_595 ;
V_134 = V_370 = V_73 -> V_290 + V_507 + V_508 + V_596 ;
#ifdef F_175
if ( ( V_73 -> V_196 & V_582 ) &&
( V_134 < V_512 ) &&
( V_591 == F_332 ( V_2 ) ) )
V_134 = V_512 ;
#endif
switch ( V_14 -> V_108 . type ) {
case V_112 :
case V_113 :
case V_114 :
V_594 = F_333 ( V_370 , V_134 ) ;
break;
default:
V_594 = F_334 ( V_370 , V_134 ) ;
break;
}
if ( V_2 -> V_139 & V_408 )
V_594 += F_335 ( V_134 ) ;
V_592 = F_336 ( V_594 ) ;
V_595 = F_37 ( V_14 , F_337 ( V_591 ) ) >> 10 ;
V_593 = V_595 - V_592 ;
if ( V_593 < 0 ) {
F_93 ( V_156 , L_87
L_88
L_89 , V_591 ) ;
V_593 = V_134 + 1 ;
}
return V_593 ;
}
static int F_338 ( struct V_1 * V_2 , int V_591 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_73 = V_2 -> V_55 ;
int V_134 ;
T_1 V_594 ;
V_134 = V_73 -> V_290 + V_507 + V_508 ;
#ifdef F_175
if ( ( V_73 -> V_196 & V_582 ) &&
( V_134 < V_512 ) &&
( V_591 == F_86 ( V_73 , V_2 -> V_597 . V_598 ) ) )
V_134 = V_512 ;
#endif
switch ( V_14 -> V_108 . type ) {
case V_112 :
case V_113 :
case V_114 :
V_594 = F_339 ( V_134 ) ;
break;
default:
V_594 = F_340 ( V_134 ) ;
break;
}
return F_336 ( V_594 ) ;
}
static void F_341 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_599 = F_254 ( V_2 -> V_55 ) ;
int V_48 ;
if ( ! V_599 )
V_599 = 1 ;
for ( V_48 = 0 ; V_48 < V_599 ; V_48 ++ ) {
V_14 -> V_125 . V_600 [ V_48 ] = F_331 ( V_2 , V_48 ) ;
V_14 -> V_125 . V_601 [ V_48 ] = F_338 ( V_2 , V_48 ) ;
if ( V_14 -> V_125 . V_601 [ V_48 ] > V_14 -> V_125 . V_600 [ V_48 ] )
V_14 -> V_125 . V_601 [ V_48 ] = 0 ;
}
for (; V_48 < V_602 ; V_48 ++ )
V_14 -> V_125 . V_600 [ V_48 ] = 0 ;
}
static void F_342 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_603 ;
T_4 V_134 = F_254 ( V_2 -> V_55 ) ;
if ( V_2 -> V_139 & V_363 ||
V_2 -> V_139 & V_604 )
V_603 = 32 << V_2 -> V_605 ;
else
V_603 = 0 ;
V_14 -> V_108 . V_335 . V_606 ( V_14 , V_134 , V_603 , V_607 ) ;
F_341 ( V_2 ) ;
}
static void F_343 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_608 * V_609 ;
struct V_610 * V_611 ;
F_344 ( & V_2 -> V_612 ) ;
if ( ! F_345 ( & V_2 -> V_613 ) )
F_346 ( V_14 , & V_2 -> V_614 ) ;
F_347 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_348 ( V_14 ,
& V_611 -> V_611 ,
V_611 -> V_615 ,
( V_611 -> V_616 == V_617 ) ?
V_617 :
V_2 -> V_67 [ V_611 -> V_616 ] -> V_149 ) ;
}
F_349 ( & V_2 -> V_612 ) ;
}
static void F_350 ( struct V_54 * V_73 , unsigned int V_470 ,
struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_561 ;
V_561 = F_37 ( V_14 , F_318 ( V_470 ) ) ;
V_561 |= ( V_580 | V_562 | V_563 ) ;
V_561 &= ~ V_576 ;
if ( V_73 -> V_139 & V_578 ) {
V_561 |= V_576 ;
} else {
V_561 |= V_580 ;
V_14 -> V_108 . V_335 . V_544 ( V_14 , V_73 ) ;
}
F_313 ( V_2 -> V_55 , V_470 ) ;
F_71 ( V_14 , F_318 ( V_470 ) , V_561 ) ;
}
static void F_351 ( struct V_618 * V_619 )
{
struct V_1 * V_2 = V_619 -> V_148 ;
int V_438 = V_2 -> V_620 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_470 = V_619 -> V_470 ;
T_1 V_471 = V_472 |
V_473 |
V_474 |
V_475 |
V_476 ;
if ( V_14 -> V_108 . type == V_109 )
return;
if ( V_438 > 3 )
V_471 |= 2 << 29 ;
else if ( V_438 > 1 )
V_471 |= 1 << 29 ;
F_71 ( V_14 , F_280 ( F_281 ( V_470 ) ) , V_471 ) ;
}
static void F_352 ( struct V_57 * V_67 )
{
struct V_190 * V_73 = V_67 -> V_73 ;
unsigned long V_274 ;
T_2 V_48 ;
if ( ! V_67 -> V_71 )
return;
for ( V_48 = 0 ; V_48 < V_67 -> V_88 ; V_48 ++ ) {
struct V_70 * V_273 = & V_67 -> V_71 [ V_48 ] ;
if ( V_273 -> V_89 ) {
struct V_195 * V_89 = V_273 -> V_89 ;
if ( F_150 ( V_89 ) -> V_267 )
F_80 ( V_73 ,
F_150 ( V_89 ) -> V_81 ,
F_69 ( V_67 ) ,
V_231 ) ;
F_353 ( V_89 ) ;
V_273 -> V_89 = NULL ;
}
if ( ! V_273 -> V_98 )
continue;
F_80 ( V_73 , V_273 -> V_81 ,
F_139 ( V_67 ) , V_231 ) ;
F_141 ( V_273 -> V_98 , F_137 ( V_67 ) ) ;
V_273 -> V_98 = NULL ;
}
V_274 = sizeof( struct V_70 ) * V_67 -> V_88 ;
memset ( V_67 -> V_71 , 0 , V_274 ) ;
memset ( V_67 -> V_87 , 0 , V_67 -> V_274 ) ;
V_67 -> V_235 = 0 ;
V_67 -> V_79 = 0 ;
V_67 -> V_80 = 0 ;
}
static void F_354 ( struct V_618 * V_619 ,
struct V_57 * V_67 )
{
struct V_1 * V_2 = V_619 -> V_148 ;
int V_107 = V_67 -> V_86 + V_619 -> V_621 ;
F_275 ( V_2 , V_67 ) ;
F_252 ( 10000 , 20000 ) ;
F_219 ( V_2 , ( ( T_6 ) 1 << V_107 ) ) ;
F_352 ( V_67 ) ;
V_67 -> V_147 = NULL ;
}
static int F_355 ( struct V_54 * V_622 ,
struct V_618 * V_623 )
{
struct V_1 * V_2 = V_623 -> V_148 ;
unsigned int V_624 = V_623 -> V_621 ;
unsigned int V_625 = V_623 -> V_626 ;
int V_48 ;
F_356 ( V_622 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_620 ; V_48 ++ ) {
F_354 ( V_623 , V_2 -> V_67 [ V_624 + V_48 ] ) ;
V_2 -> V_67 [ V_624 + V_48 ] -> V_55 = V_2 -> V_55 ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_620 ; V_48 ++ ) {
V_2 -> V_58 [ V_625 + V_48 ] -> V_147 = NULL ;
V_2 -> V_58 [ V_625 + V_48 ] -> V_55 = V_2 -> V_55 ;
}
return 0 ;
}
static int F_357 ( struct V_54 * V_622 ,
struct V_618 * V_623 )
{
struct V_1 * V_2 = V_623 -> V_148 ;
unsigned int V_624 , V_625 , V_357 ;
int V_48 , V_627 , V_17 = 0 ;
if ( ! F_14 ( V_623 -> V_470 , & V_2 -> V_628 ) )
return 0 ;
V_627 = V_623 -> V_470 * V_2 -> V_620 ;
F_358 ( V_622 , L_90 ,
V_623 -> V_470 , V_2 -> V_629 ,
V_627 , V_627 + V_2 -> V_620 ,
V_2 -> V_628 ) ;
V_623 -> V_55 = V_622 ;
V_623 -> V_621 = V_624 = V_627 ;
V_623 -> V_626 = V_625 = V_627 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_620 ; V_48 ++ )
F_354 ( V_623 , V_2 -> V_67 [ V_624 + V_48 ] ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_620 ; V_48 ++ ) {
V_2 -> V_67 [ V_624 + V_48 ] -> V_55 = V_622 ;
V_2 -> V_67 [ V_624 + V_48 ] -> V_147 = V_623 ;
F_277 ( V_2 , V_2 -> V_67 [ V_624 + V_48 ] ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_620 ; V_48 ++ ) {
V_2 -> V_58 [ V_625 + V_48 ] -> V_55 = V_622 ;
V_2 -> V_58 [ V_625 + V_48 ] -> V_147 = V_623 ;
}
V_357 = F_359 (unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues) ;
V_17 = F_360 ( V_622 , V_357 ) ;
if ( V_17 )
goto V_630;
V_17 = F_361 ( V_622 , V_357 ) ;
if ( V_17 )
goto V_630;
if ( F_362 ( V_622 -> V_631 ) )
F_308 ( V_2 , V_622 -> V_631 , V_623 -> V_470 ) ;
F_351 ( V_623 ) ;
F_350 ( V_622 , V_623 -> V_470 , V_2 ) ;
return V_17 ;
V_630:
F_355 ( V_622 , V_623 ) ;
return V_17 ;
}
static void F_363 ( struct V_1 * V_2 )
{
struct V_54 * V_95 ;
struct V_632 * V_633 ;
int V_17 ;
F_364 (adapter->netdev, upper, iter) {
if ( F_365 ( V_95 ) ) {
struct V_634 * V_635 = F_89 ( V_95 ) ;
struct V_618 * V_619 = V_635 -> V_636 ;
if ( V_635 -> V_636 ) {
V_17 = F_357 ( V_95 , V_619 ) ;
if ( V_17 )
continue;
}
}
}
}
static void F_366 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
F_342 ( V_2 ) ;
#ifdef F_367
F_325 ( V_2 ) ;
#endif
F_282 ( V_2 ) ;
F_317 ( V_2 -> V_55 ) ;
F_297 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
V_14 -> V_108 . V_335 . V_637 ( V_14 ) ;
break;
default:
break;
}
if ( V_2 -> V_139 & V_363 ) {
F_368 ( & V_2 -> V_14 ,
V_2 -> V_605 ) ;
} else if ( V_2 -> V_139 & V_604 ) {
F_369 ( & V_2 -> V_14 ,
V_2 -> V_605 ) ;
F_343 ( V_2 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
V_14 -> V_108 . V_335 . V_638 ( V_14 ) ;
break;
default:
break;
}
#ifdef F_175
F_370 ( V_2 ) ;
#endif
F_255 ( V_2 ) ;
F_292 ( V_2 ) ;
F_363 ( V_2 ) ;
}
static void F_371 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_108 . type == V_109 )
V_2 -> V_154 |= V_639 ;
V_2 -> V_154 |= V_349 ;
}
static int F_372 ( struct V_15 * V_14 )
{
T_1 V_20 ;
bool V_640 , V_337 = false ;
int V_641 = V_642 ;
if ( V_14 -> V_108 . V_335 . V_336 )
V_641 = V_14 -> V_108 . V_335 . V_336 ( V_14 , & V_20 , & V_337 , false ) ;
if ( V_641 )
return V_641 ;
V_20 = V_14 -> V_338 . V_643 ;
if ( ( ! V_20 ) && ( V_14 -> V_108 . V_335 . V_644 ) )
V_641 = V_14 -> V_108 . V_335 . V_644 ( V_14 , & V_20 ,
& V_640 ) ;
if ( V_641 )
return V_641 ;
if ( V_14 -> V_108 . V_335 . V_645 )
V_641 = V_14 -> V_108 . V_335 . V_645 ( V_14 , V_20 , V_337 ) ;
return V_641 ;
}
static void F_373 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_646 = 0 ;
if ( V_2 -> V_139 & V_388 ) {
V_646 = V_647 | V_648 |
V_649 ;
V_646 |= V_650 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
F_71 ( V_14 , V_651 , V_652 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
default:
F_71 ( V_14 , F_374 ( 0 ) , 0xFFFFFFFF ) ;
F_71 ( V_14 , F_374 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_71 ( V_14 , V_651 , V_652 ) ;
}
if ( V_2 -> V_139 & V_408 ) {
V_646 &= ~ V_653 ;
switch ( V_2 -> V_413 [ V_490 ] . V_117 ) {
case V_491 :
V_646 |= V_654 ;
break;
case V_493 :
V_646 |= V_655 ;
break;
default:
V_646 |= V_656 ;
break;
}
}
if ( V_2 -> V_154 & V_330 ) {
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_646 |= V_657 ;
break;
case V_112 :
V_646 |= V_359 ;
break;
default:
break;
}
}
if ( V_2 -> V_139 & V_342 )
V_646 |= F_375 ( V_14 ) ;
if ( V_14 -> V_108 . type == V_111 ) {
V_646 |= V_658 ;
V_646 |= V_659 ;
}
F_71 ( V_14 , V_660 , V_646 ) ;
}
static void F_376 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 ;
T_1 V_100 ;
F_72 ( V_2 ) ;
F_373 ( V_2 ) ;
if ( V_2 -> V_139 & V_388 )
F_200 ( V_2 ) ;
else
F_247 ( V_2 ) ;
if ( V_14 -> V_108 . V_335 . V_661 )
V_14 -> V_108 . V_335 . V_661 ( V_14 ) ;
if ( V_14 -> V_338 . V_335 . V_662 )
V_14 -> V_338 . V_335 . V_662 ( V_14 , true ) ;
F_33 () ;
F_34 ( V_33 , & V_2 -> V_34 ) ;
F_319 ( V_2 ) ;
if ( F_212 ( V_14 ) ) {
F_371 ( V_2 ) ;
} else {
V_17 = F_372 ( V_14 ) ;
if ( V_17 )
F_103 ( V_172 , L_91 , V_17 ) ;
}
F_37 ( V_14 , V_343 ) ;
F_221 ( V_2 , true , true ) ;
if ( V_2 -> V_139 & V_342 ) {
T_1 V_663 = F_37 ( V_14 , V_664 ) ;
if ( V_663 & V_665 )
F_208 ( V_156 , L_71 ) ;
}
V_2 -> V_139 |= V_352 ;
V_2 -> V_353 = V_171 ;
F_377 ( & V_2 -> V_666 , V_171 ) ;
V_100 = F_37 ( V_14 , V_101 ) ;
V_100 |= V_667 ;
F_71 ( V_14 , V_101 , V_100 ) ;
}
void F_378 ( struct V_1 * V_2 )
{
F_379 ( F_380 () ) ;
V_2 -> V_55 -> V_74 = V_171 ;
while ( F_15 ( V_668 , & V_2 -> V_34 ) )
F_252 ( 1000 , 2000 ) ;
F_381 ( V_2 ) ;
if ( V_2 -> V_139 & V_408 )
F_382 ( 2000 ) ;
F_383 ( V_2 ) ;
F_34 ( V_668 , & V_2 -> V_34 ) ;
}
void F_383 ( struct V_1 * V_2 )
{
F_366 ( V_2 ) ;
F_376 ( V_2 ) ;
}
void F_384 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_55 = V_2 -> V_55 ;
int V_17 ;
T_4 V_669 [ V_554 ] ;
if ( F_22 ( V_14 -> V_39 ) )
return;
while ( F_15 ( V_670 , & V_2 -> V_34 ) )
F_252 ( 1000 , 2000 ) ;
V_2 -> V_154 &= ~ ( V_639 |
V_349 ) ;
V_2 -> V_139 &= ~ V_350 ;
V_17 = V_14 -> V_108 . V_335 . V_671 ( V_14 ) ;
switch ( V_17 ) {
case 0 :
case V_672 :
case V_673 :
break;
case V_674 :
F_18 ( L_92 ) ;
break;
case V_675 :
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
F_34 ( V_670 , & V_2 -> V_34 ) ;
memcpy ( V_669 , & V_2 -> V_547 [ 0 ] . V_550 , V_55 -> V_676 ) ;
F_304 ( V_2 ) ;
F_307 ( V_2 , V_669 ) ;
if ( V_14 -> V_108 . V_677 )
V_14 -> V_108 . V_335 . V_678 ( V_14 , F_281 ( 0 ) ) ;
if ( F_14 ( V_679 , & V_2 -> V_34 ) )
F_385 ( V_2 ) ;
if ( V_14 -> V_338 . V_335 . V_662 ) {
if ( ! F_57 ( V_2 -> V_55 ) && ! V_2 -> V_680 )
V_14 -> V_338 . V_335 . V_662 ( V_14 , false ) ;
else
V_14 -> V_338 . V_335 . V_662 ( V_14 , true ) ;
}
}
static void F_386 ( struct V_57 * V_58 )
{
struct V_59 * V_78 ;
unsigned long V_274 ;
T_2 V_48 ;
if ( ! V_58 -> V_78 )
return;
for ( V_48 = 0 ; V_48 < V_58 -> V_88 ; V_48 ++ ) {
V_78 = & V_58 -> V_78 [ V_48 ] ;
F_77 ( V_58 , V_78 ) ;
}
F_387 ( F_107 ( V_58 ) ) ;
V_274 = sizeof( struct V_59 ) * V_58 -> V_88 ;
memset ( V_58 -> V_78 , 0 , V_274 ) ;
memset ( V_58 -> V_87 , 0 , V_58 -> V_274 ) ;
V_58 -> V_80 = 0 ;
V_58 -> V_79 = 0 ;
}
static void F_388 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
F_352 ( V_2 -> V_67 [ V_48 ] ) ;
}
static void F_389 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_386 ( V_2 -> V_58 [ V_48 ] ) ;
}
static void F_390 ( struct V_1 * V_2 )
{
struct V_608 * V_609 ;
struct V_610 * V_611 ;
F_344 ( & V_2 -> V_612 ) ;
F_347 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_391 ( & V_611 -> V_681 ) ;
F_241 ( V_611 ) ;
}
V_2 -> V_682 = 0 ;
F_349 ( & V_2 -> V_612 ) ;
}
void F_381 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_95 ;
struct V_632 * V_633 ;
int V_48 ;
if ( F_15 ( V_33 , & V_2 -> V_34 ) )
return;
V_14 -> V_108 . V_335 . V_530 ( V_14 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
F_275 ( V_2 , V_2 -> V_67 [ V_48 ] ) ;
F_252 ( 10000 , 20000 ) ;
F_356 ( V_55 ) ;
F_392 ( V_55 ) ;
F_393 ( V_55 ) ;
F_364 (adapter->netdev, upper, iter) {
if ( F_365 ( V_95 ) ) {
struct V_634 * V_247 = F_89 ( V_95 ) ;
if ( V_247 -> V_636 ) {
F_356 ( V_95 ) ;
F_392 ( V_95 ) ;
F_393 ( V_95 ) ;
}
}
}
F_245 ( V_2 ) ;
F_322 ( V_2 ) ;
V_2 -> V_154 &= ~ ( V_364 |
V_155 ) ;
V_2 -> V_139 &= ~ V_352 ;
F_394 ( & V_2 -> V_666 ) ;
if ( V_2 -> V_302 ) {
F_71 ( & V_2 -> V_14 , V_304 , 0 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_302 ; V_48 ++ )
V_2 -> V_503 [ V_48 ] . V_683 = false ;
F_395 ( V_2 ) ;
F_396 ( V_2 ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
T_4 V_149 = V_2 -> V_58 [ V_48 ] -> V_149 ;
F_71 ( V_14 , F_50 ( V_149 ) , V_684 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_71 ( V_14 , V_424 ,
( F_37 ( V_14 , V_424 ) &
~ V_425 ) ) ;
break;
default:
break;
}
if ( ! F_397 ( V_2 -> V_9 ) )
F_384 ( V_2 ) ;
if ( V_14 -> V_108 . V_335 . V_685 )
V_14 -> V_108 . V_335 . V_685 ( V_14 ) ;
F_389 ( V_2 ) ;
F_388 ( V_2 ) ;
#ifdef F_232
F_123 ( V_2 ) ;
#endif
}
static void F_398 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
F_92 ( V_2 ) ;
}
static int F_399 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_200 , V_686 ;
T_1 V_687 ;
#ifdef F_367
int V_49 ;
struct V_688 * V_134 ;
#endif
V_14 -> V_689 = V_9 -> V_690 ;
V_14 -> V_21 = V_9 -> V_190 ;
V_14 -> V_691 = V_9 -> V_692 ;
V_14 -> V_693 = V_9 -> V_694 ;
V_14 -> V_695 = V_9 -> V_696 ;
V_200 = F_359 ( int , F_400 ( V_2 ) , F_401 () ) ;
V_2 -> V_413 [ V_414 ] . V_697 = V_200 ;
V_2 -> V_154 |= V_698 ;
V_2 -> V_154 |= V_519 ;
V_2 -> V_699 = V_700 ;
V_2 -> V_398 = 20 ;
V_686 = F_359 ( int , V_701 , F_401 () ) ;
V_2 -> V_413 [ V_702 ] . V_697 = V_686 ;
V_2 -> V_605 = V_703 ;
#ifdef F_232
V_2 -> V_139 |= V_192 ;
#endif
#ifdef F_175
V_2 -> V_139 |= V_704 ;
V_2 -> V_139 &= ~ V_511 ;
#ifdef F_367
V_2 -> V_597 . V_598 = V_705 ;
#endif
#endif
V_2 -> V_547 = F_402 ( sizeof( struct V_706 ) *
V_14 -> V_108 . V_546 ,
V_707 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_2 -> V_154 &= ~ V_698 ;
V_2 -> V_154 &= ~ V_519 ;
if ( V_14 -> V_21 == V_708 )
V_2 -> V_139 |= V_342 ;
V_2 -> V_699 = V_709 ;
V_2 -> V_413 [ V_702 ] . V_697 = 0 ;
V_2 -> V_398 = 0 ;
V_2 -> V_605 = 0 ;
#ifdef F_175
V_2 -> V_139 &= ~ V_704 ;
V_2 -> V_139 &= ~ V_511 ;
#ifdef F_367
V_2 -> V_597 . V_598 = 0 ;
#endif
#endif
break;
case V_111 :
if ( V_14 -> V_21 == V_332 )
V_2 -> V_154 |= V_330 ;
break;
case V_112 :
V_687 = F_37 ( V_14 , F_403 ( V_14 ) ) ;
if ( V_687 & V_710 )
V_2 -> V_154 |= V_330 ;
break;
case V_114 :
case V_113 :
#ifdef F_232
V_2 -> V_139 &= ~ V_192 ;
#endif
break;
default:
break;
}
#ifdef F_175
F_404 ( & V_2 -> V_597 . V_711 ) ;
#endif
F_404 ( & V_2 -> V_612 ) ;
#ifdef F_367
switch ( V_14 -> V_108 . type ) {
case V_112 :
case V_113 :
case V_114 :
V_2 -> V_136 . V_712 . V_713 = V_714 ;
V_2 -> V_136 . V_712 . V_715 = V_714 ;
break;
default:
V_2 -> V_136 . V_712 . V_713 = V_602 ;
V_2 -> V_136 . V_712 . V_715 = V_602 ;
break;
}
for ( V_49 = 0 ; V_49 < V_602 ; V_49 ++ ) {
V_134 = & V_2 -> V_136 . V_716 [ V_49 ] ;
V_134 -> V_717 [ V_585 ] . V_718 = 0 ;
V_134 -> V_717 [ V_585 ] . V_719 = 12 + ( V_49 & 1 ) ;
V_134 -> V_717 [ V_586 ] . V_718 = 0 ;
V_134 -> V_717 [ V_586 ] . V_719 = 12 + ( V_49 & 1 ) ;
V_134 -> V_720 = V_721 ;
}
V_134 = & V_2 -> V_136 . V_716 [ 0 ] ;
V_134 -> V_717 [ V_585 ] . V_722 = 0xFF ;
V_134 -> V_717 [ V_586 ] . V_722 = 0xFF ;
V_2 -> V_136 . V_723 [ V_585 ] [ 0 ] = 100 ;
V_2 -> V_136 . V_723 [ V_586 ] [ 0 ] = 100 ;
V_2 -> V_136 . V_137 = false ;
V_2 -> V_724 = 0x00 ;
V_2 -> V_583 = V_725 | V_584 ;
memcpy ( & V_2 -> V_726 , & V_2 -> V_136 ,
sizeof( V_2 -> V_726 ) ) ;
#endif
V_14 -> V_125 . V_727 = V_127 ;
V_14 -> V_125 . V_126 = V_127 ;
F_341 ( V_2 ) ;
V_14 -> V_125 . V_728 = V_729 ;
V_14 -> V_125 . V_730 = true ;
V_14 -> V_125 . V_731 = F_405 ( V_14 ) ;
#ifdef F_299
if ( V_732 > 0 )
F_11 ( L_100 ) ;
if ( V_14 -> V_108 . type != V_109 ) {
if ( V_732 > V_733 ) {
V_2 -> V_302 = 0 ;
F_11 ( L_101 ) ;
} else {
V_2 -> V_302 = V_732 ;
}
}
#endif
V_2 -> V_379 = 1 ;
V_2 -> V_734 = 1 ;
V_2 -> V_735 = V_736 ;
V_2 -> V_737 = V_738 ;
V_2 -> V_739 = V_740 ;
if ( F_406 ( V_14 ) ) {
F_18 ( L_102 ) ;
return - V_741 ;
}
F_250 ( 0 , & V_2 -> V_628 ) ;
F_250 ( V_33 , & V_2 -> V_34 ) ;
return 0 ;
}
int F_407 ( struct V_57 * V_58 )
{
struct V_190 * V_73 = V_58 -> V_73 ;
int V_742 = F_408 ( V_73 ) ;
int V_743 = - 1 ;
int V_274 ;
V_274 = sizeof( struct V_59 ) * V_58 -> V_88 ;
if ( V_58 -> V_158 )
V_743 = V_58 -> V_158 -> V_744 ;
V_58 -> V_78 = F_409 ( V_274 , V_743 ) ;
if ( ! V_58 -> V_78 )
V_58 -> V_78 = F_410 ( V_274 ) ;
if ( ! V_58 -> V_78 )
goto V_17;
F_411 ( & V_58 -> V_169 ) ;
V_58 -> V_274 = V_58 -> V_88 * sizeof( union V_61 ) ;
V_58 -> V_274 = F_169 ( V_58 -> V_274 , 4096 ) ;
F_412 ( V_73 , V_743 ) ;
V_58 -> V_87 = F_413 ( V_73 ,
V_58 -> V_274 ,
& V_58 -> V_81 ,
V_745 ) ;
F_412 ( V_73 , V_742 ) ;
if ( ! V_58 -> V_87 )
V_58 -> V_87 = F_413 ( V_73 , V_58 -> V_274 ,
& V_58 -> V_81 , V_745 ) ;
if ( ! V_58 -> V_87 )
goto V_17;
V_58 -> V_80 = 0 ;
V_58 -> V_79 = 0 ;
return 0 ;
V_17:
F_414 ( V_58 -> V_78 ) ;
V_58 -> V_78 = NULL ;
F_415 ( V_73 , L_103 ) ;
return - V_545 ;
}
static int F_416 ( struct V_1 * V_2 )
{
int V_48 , V_17 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
V_17 = F_407 ( V_2 -> V_58 [ V_48 ] ) ;
if ( ! V_17 )
continue;
F_103 ( V_172 , L_104 , V_48 ) ;
goto V_746;
}
return 0 ;
V_746:
while ( V_48 -- )
F_417 ( V_2 -> V_58 [ V_48 ] ) ;
return V_17 ;
}
int F_418 ( struct V_57 * V_67 )
{
struct V_190 * V_73 = V_67 -> V_73 ;
int V_742 = F_408 ( V_73 ) ;
int V_743 = - 1 ;
int V_274 ;
V_274 = sizeof( struct V_70 ) * V_67 -> V_88 ;
if ( V_67 -> V_158 )
V_743 = V_67 -> V_158 -> V_744 ;
V_67 -> V_71 = F_409 ( V_274 , V_743 ) ;
if ( ! V_67 -> V_71 )
V_67 -> V_71 = F_410 ( V_274 ) ;
if ( ! V_67 -> V_71 )
goto V_17;
F_411 ( & V_67 -> V_169 ) ;
V_67 -> V_274 = V_67 -> V_88 * sizeof( union V_68 ) ;
V_67 -> V_274 = F_169 ( V_67 -> V_274 , 4096 ) ;
F_412 ( V_73 , V_743 ) ;
V_67 -> V_87 = F_413 ( V_73 ,
V_67 -> V_274 ,
& V_67 -> V_81 ,
V_745 ) ;
F_412 ( V_73 , V_742 ) ;
if ( ! V_67 -> V_87 )
V_67 -> V_87 = F_413 ( V_73 , V_67 -> V_274 ,
& V_67 -> V_81 , V_745 ) ;
if ( ! V_67 -> V_87 )
goto V_17;
V_67 -> V_79 = 0 ;
V_67 -> V_80 = 0 ;
return 0 ;
V_17:
F_414 ( V_67 -> V_71 ) ;
V_67 -> V_71 = NULL ;
F_415 ( V_73 , L_105 ) ;
return - V_545 ;
}
static int F_419 ( struct V_1 * V_2 )
{
int V_48 , V_17 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_17 = F_418 ( V_2 -> V_67 [ V_48 ] ) ;
if ( ! V_17 )
continue;
F_103 ( V_172 , L_106 , V_48 ) ;
goto V_747;
}
#ifdef F_175
V_17 = F_420 ( V_2 ) ;
if ( ! V_17 )
#endif
return 0 ;
V_747:
while ( V_48 -- )
F_421 ( V_2 -> V_67 [ V_48 ] ) ;
return V_17 ;
}
void F_417 ( struct V_57 * V_58 )
{
F_386 ( V_58 ) ;
F_414 ( V_58 -> V_78 ) ;
V_58 -> V_78 = NULL ;
if ( ! V_58 -> V_87 )
return;
F_422 ( V_58 -> V_73 , V_58 -> V_274 ,
V_58 -> V_87 , V_58 -> V_81 ) ;
V_58 -> V_87 = NULL ;
}
static void F_423 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
if ( V_2 -> V_58 [ V_48 ] -> V_87 )
F_417 ( V_2 -> V_58 [ V_48 ] ) ;
}
void F_421 ( struct V_57 * V_67 )
{
F_352 ( V_67 ) ;
F_414 ( V_67 -> V_71 ) ;
V_67 -> V_71 = NULL ;
if ( ! V_67 -> V_87 )
return;
F_422 ( V_67 -> V_73 , V_67 -> V_274 ,
V_67 -> V_87 , V_67 -> V_81 ) ;
V_67 -> V_87 = NULL ;
}
static void F_424 ( struct V_1 * V_2 )
{
int V_48 ;
#ifdef F_175
F_425 ( V_2 ) ;
#endif
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
if ( V_2 -> V_67 [ V_48 ] -> V_87 )
F_421 ( V_2 -> V_67 [ V_48 ] ) ;
}
static int F_426 ( struct V_54 * V_55 , int V_748 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_506 = V_748 + V_507 + V_508 ;
if ( ( V_748 < 68 ) || ( V_506 > V_749 ) )
return - V_556 ;
if ( ( V_2 -> V_139 & V_408 ) &&
( V_2 -> V_14 . V_108 . type == V_111 ) &&
( V_506 > ( V_513 + V_508 ) ) )
F_93 ( V_172 , L_107 ) ;
F_105 ( V_172 , L_108 , V_55 -> V_290 , V_748 ) ;
V_55 -> V_290 = V_748 ;
if ( F_57 ( V_55 ) )
F_378 ( V_2 ) ;
return 0 ;
}
static int F_427 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 , V_357 ;
if ( F_14 ( V_750 , & V_2 -> V_34 ) )
return - V_751 ;
F_392 ( V_55 ) ;
V_17 = F_416 ( V_2 ) ;
if ( V_17 )
goto V_746;
V_17 = F_419 ( V_2 ) ;
if ( V_17 )
goto V_747;
F_366 ( V_2 ) ;
V_17 = F_243 ( V_2 ) ;
if ( V_17 )
goto V_752;
if ( V_2 -> V_629 > 1 )
V_357 = V_2 -> V_620 ;
else
V_357 = V_2 -> V_77 ;
V_17 = F_360 ( V_55 , V_357 ) ;
if ( V_17 )
goto V_753;
if ( V_2 -> V_629 > 1 &&
V_2 -> V_93 > V_754 )
V_357 = V_754 ;
else
V_357 = V_2 -> V_93 ;
V_17 = F_361 ( V_55 , V_357 ) ;
if ( V_17 )
goto V_753;
F_428 ( V_2 ) ;
F_376 ( V_2 ) ;
#if F_429 ( V_755 )
F_430 ( V_55 ) ;
#endif
return 0 ;
V_753:
F_244 ( V_2 ) ;
V_752:
F_424 ( V_2 ) ;
if ( V_14 -> V_338 . V_335 . V_662 && ! V_2 -> V_680 )
V_14 -> V_338 . V_335 . V_662 ( & V_2 -> V_14 , false ) ;
V_747:
F_423 ( V_2 ) ;
V_746:
F_384 ( V_2 ) ;
return V_17 ;
}
static void F_431 ( struct V_1 * V_2 )
{
F_432 ( V_2 ) ;
F_381 ( V_2 ) ;
F_244 ( V_2 ) ;
F_423 ( V_2 ) ;
F_424 ( V_2 ) ;
}
static int F_433 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
F_434 ( V_2 ) ;
F_431 ( V_2 ) ;
F_390 ( V_2 ) ;
F_70 ( V_2 ) ;
return 0 ;
}
static int F_435 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_436 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
T_1 V_17 ;
V_2 -> V_14 . V_39 = V_2 -> V_397 ;
F_437 ( V_9 , V_756 ) ;
F_438 ( V_9 ) ;
F_439 ( V_9 ) ;
V_17 = F_440 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_109 ) ;
return V_17 ;
}
F_33 () ;
F_34 ( V_757 , & V_2 -> V_34 ) ;
F_441 ( V_9 ) ;
F_442 ( V_9 , false ) ;
F_384 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_758 , ~ 0 ) ;
F_443 () ;
V_17 = F_444 ( V_2 ) ;
if ( ! V_17 && F_57 ( V_55 ) )
V_17 = F_427 ( V_55 ) ;
F_445 () ;
if ( V_17 )
return V_17 ;
F_446 ( V_55 ) ;
return 0 ;
}
static int F_447 ( struct V_5 * V_9 , bool * V_759 )
{
struct V_1 * V_2 = F_436 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_760 , V_560 ;
T_1 V_761 = V_2 -> V_680 ;
#ifdef F_448
int V_762 = 0 ;
#endif
F_449 ( V_55 ) ;
F_443 () ;
if ( F_57 ( V_55 ) )
F_431 ( V_2 ) ;
F_445 () ;
F_450 ( V_2 ) ;
#ifdef F_448
V_762 = F_439 ( V_9 ) ;
if ( V_762 )
return V_762 ;
#endif
if ( V_14 -> V_108 . V_335 . V_763 )
V_14 -> V_108 . V_335 . V_763 ( V_14 ) ;
if ( V_761 ) {
F_317 ( V_55 ) ;
if ( V_14 -> V_108 . V_335 . V_661 )
V_14 -> V_108 . V_335 . V_661 ( V_14 ) ;
if ( V_761 & V_764 ) {
V_560 = F_37 ( V_14 , V_564 ) ;
V_560 |= V_570 ;
F_71 ( V_14 , V_564 , V_560 ) ;
}
V_760 = F_37 ( V_14 , V_765 ) ;
V_760 |= V_766 ;
F_71 ( V_14 , V_765 , V_760 ) ;
F_71 ( V_14 , V_767 , V_761 ) ;
} else {
F_71 ( V_14 , V_768 , 0 ) ;
F_71 ( V_14 , V_767 , 0 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_109 :
F_442 ( V_9 , false ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_442 ( V_9 , ! ! V_761 ) ;
break;
default:
break;
}
* V_759 = ! ! V_761 ;
if ( V_14 -> V_338 . V_335 . V_662 && ! * V_759 )
V_14 -> V_338 . V_335 . V_662 ( V_14 , false ) ;
F_70 ( V_2 ) ;
if ( ! F_15 ( V_757 , & V_2 -> V_34 ) )
F_451 ( V_9 ) ;
return 0 ;
}
static int F_452 ( struct V_5 * V_9 , T_13 V_34 )
{
int V_762 ;
bool V_769 ;
V_762 = F_447 ( V_9 , & V_769 ) ;
if ( V_762 )
return V_762 ;
if ( V_769 ) {
F_453 ( V_9 ) ;
} else {
F_442 ( V_9 , false ) ;
F_437 ( V_9 , V_770 ) ;
}
return 0 ;
}
static void F_454 ( struct V_5 * V_9 )
{
bool V_769 ;
F_447 ( V_9 , & V_769 ) ;
if ( V_771 == V_772 ) {
F_442 ( V_9 , V_769 ) ;
F_437 ( V_9 , V_770 ) ;
}
}
void F_455 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_122 * V_123 = & V_2 -> V_124 ;
T_6 V_773 = 0 ;
T_1 V_48 , V_774 = 0 , V_775 , V_776 , V_777 , V_778 , V_779 ;
T_6 V_259 = 0 , V_174 = 0 , V_780 = 0 ;
T_6 V_230 = 0 , V_283 = 0 ;
T_6 V_170 = 0 , V_144 = 0 , V_781 = 0 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_668 , & V_2 -> V_34 ) )
return;
if ( V_2 -> V_154 & V_519 ) {
T_6 V_241 = 0 ;
T_6 V_242 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_241 += V_2 -> V_67 [ V_48 ] -> V_219 . V_241 ;
V_242 += V_2 -> V_67 [ V_48 ] -> V_219 . V_242 ;
}
V_2 -> V_782 = V_241 ;
V_2 -> V_783 = V_242 ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_67 = V_2 -> V_67 [ V_48 ] ;
V_259 += V_67 -> V_219 . V_259 ;
V_230 += V_67 -> V_219 . V_230 ;
V_283 += V_67 -> V_219 . V_283 ;
V_781 += V_67 -> V_219 . V_220 ;
V_170 += V_67 -> V_124 . V_170 ;
V_144 += V_67 -> V_124 . V_144 ;
}
V_2 -> V_259 = V_259 ;
V_2 -> V_230 = V_230 ;
V_2 -> V_283 = V_283 ;
V_2 -> V_781 = V_781 ;
V_55 -> V_124 . V_784 = V_170 ;
V_55 -> V_124 . V_785 = V_144 ;
V_170 = 0 ;
V_144 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_58 = V_2 -> V_58 [ V_48 ] ;
V_174 += V_58 -> V_152 . V_174 ;
V_780 += V_58 -> V_152 . V_780 ;
V_170 += V_58 -> V_124 . V_170 ;
V_144 += V_58 -> V_124 . V_144 ;
}
V_2 -> V_174 = V_174 ;
V_2 -> V_780 = V_780 ;
V_55 -> V_124 . V_786 = V_170 ;
V_55 -> V_124 . V_787 = V_144 ;
V_123 -> V_788 += F_37 ( V_14 , V_789 ) ;
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ ) {
V_775 = F_37 ( V_14 , F_456 ( V_48 ) ) ;
V_774 += V_775 ;
V_123 -> V_775 [ V_48 ] += V_775 ;
V_773 += V_123 -> V_775 [ V_48 ] ;
V_123 -> V_790 [ V_48 ] += F_37 ( V_14 , F_457 ( V_48 ) ) ;
V_123 -> V_791 [ V_48 ] += F_37 ( V_14 , F_458 ( V_48 ) ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_123 -> V_792 [ V_48 ] += F_37 ( V_14 , F_459 ( V_48 ) ) ;
V_123 -> V_793 [ V_48 ] += F_37 ( V_14 , F_460 ( V_48 ) ) ;
V_123 -> V_794 [ V_48 ] += F_37 ( V_14 , F_461 ( V_48 ) ) ;
V_123 -> V_795 [ V_48 ] +=
F_37 ( V_14 , F_462 ( V_48 ) ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_123 -> V_795 [ V_48 ] +=
F_37 ( V_14 , F_463 ( V_48 ) ) ;
break;
default:
break;
}
}
for ( V_48 = 0 ; V_48 < 16 ; V_48 ++ ) {
V_123 -> V_796 [ V_48 ] += F_37 ( V_14 , F_464 ( V_48 ) ) ;
V_123 -> V_797 [ V_48 ] += F_37 ( V_14 , F_465 ( V_48 ) ) ;
if ( ( V_14 -> V_108 . type == V_111 ) ||
( V_14 -> V_108 . type == V_112 ) ||
( V_14 -> V_108 . type == V_113 ) ||
( V_14 -> V_108 . type == V_114 ) ) {
V_123 -> V_793 [ V_48 ] += F_37 ( V_14 , F_466 ( V_48 ) ) ;
F_37 ( V_14 , F_467 ( V_48 ) ) ;
V_123 -> V_794 [ V_48 ] += F_37 ( V_14 , F_468 ( V_48 ) ) ;
F_37 ( V_14 , F_469 ( V_48 ) ) ;
}
}
V_123 -> V_798 += F_37 ( V_14 , V_799 ) ;
V_123 -> V_798 -= V_774 ;
F_83 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_123 -> V_800 += F_37 ( V_14 , V_801 ) ;
V_123 -> V_802 += F_37 ( V_14 , V_803 ) ;
V_123 -> V_804 += F_37 ( V_14 , V_805 ) ;
V_123 -> V_806 += F_37 ( V_14 , V_807 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
V_123 -> V_808 += F_37 ( V_14 , V_809 ) ;
V_123 -> V_810 += F_37 ( V_14 , V_811 ) ;
V_123 -> V_812 += F_37 ( V_14 , V_813 ) ;
V_123 -> V_814 += F_37 ( V_14 , V_815 ) ;
case V_111 :
for ( V_48 = 0 ; V_48 < 16 ; V_48 ++ )
V_2 -> V_816 +=
F_37 ( V_14 , F_470 ( V_48 ) ) ;
V_123 -> V_802 += F_37 ( V_14 , V_817 ) ;
F_37 ( V_14 , V_803 ) ;
V_123 -> V_804 += F_37 ( V_14 , V_818 ) ;
F_37 ( V_14 , V_805 ) ;
V_123 -> V_806 += F_37 ( V_14 , V_819 ) ;
F_37 ( V_14 , V_807 ) ;
V_123 -> V_800 += F_37 ( V_14 , V_820 ) ;
V_123 -> V_821 += F_37 ( V_14 , V_822 ) ;
V_123 -> V_823 += F_37 ( V_14 , V_824 ) ;
#ifdef F_175
V_123 -> V_825 += F_37 ( V_14 , V_826 ) ;
V_123 -> V_827 += F_37 ( V_14 , V_828 ) ;
V_123 -> V_829 += F_37 ( V_14 , V_830 ) ;
V_123 -> V_831 += F_37 ( V_14 , V_832 ) ;
V_123 -> V_833 += F_37 ( V_14 , V_834 ) ;
V_123 -> V_835 += F_37 ( V_14 , V_836 ) ;
if ( V_2 -> V_597 . V_837 ) {
struct V_838 * V_597 = & V_2 -> V_597 ;
struct V_839 * V_837 ;
unsigned int V_175 ;
T_6 V_840 = 0 , V_841 = 0 ;
F_471 (cpu) {
V_837 = F_472 ( V_597 -> V_837 , V_175 ) ;
V_840 += V_837 -> V_840 ;
V_841 += V_837 -> V_841 ;
}
V_123 -> V_842 = V_840 ;
V_123 -> V_843 = V_841 ;
}
#endif
break;
default:
break;
}
V_776 = F_37 ( V_14 , V_844 ) ;
V_123 -> V_776 += V_776 ;
V_123 -> V_845 += F_37 ( V_14 , V_846 ) ;
if ( V_14 -> V_108 . type == V_109 )
V_123 -> V_845 -= V_776 ;
V_123 -> V_847 += F_37 ( V_14 , V_848 ) ;
V_123 -> V_849 += F_37 ( V_14 , V_850 ) ;
V_123 -> V_851 += F_37 ( V_14 , V_852 ) ;
V_123 -> V_853 += F_37 ( V_14 , V_854 ) ;
V_123 -> V_855 += F_37 ( V_14 , V_856 ) ;
V_123 -> V_857 += F_37 ( V_14 , V_858 ) ;
V_123 -> V_859 += F_37 ( V_14 , V_860 ) ;
V_123 -> V_861 += F_37 ( V_14 , V_862 ) ;
V_777 = F_37 ( V_14 , V_863 ) ;
V_123 -> V_864 += V_777 ;
V_778 = F_37 ( V_14 , V_865 ) ;
V_123 -> V_866 += V_778 ;
V_123 -> V_867 += F_37 ( V_14 , V_868 ) ;
V_123 -> V_869 += F_37 ( V_14 , V_870 ) ;
V_779 = V_777 + V_778 ;
V_123 -> V_867 -= V_779 ;
V_123 -> V_869 -= V_779 ;
V_123 -> V_804 -= ( V_779 * ( V_871 + V_508 ) ) ;
V_123 -> V_872 += F_37 ( V_14 , V_873 ) ;
V_123 -> V_874 += F_37 ( V_14 , V_875 ) ;
V_123 -> V_876 += F_37 ( V_14 , V_877 ) ;
V_123 -> V_878 += F_37 ( V_14 , V_879 ) ;
V_123 -> V_880 += F_37 ( V_14 , V_881 ) ;
V_123 -> V_880 -= V_779 ;
V_123 -> V_882 += F_37 ( V_14 , V_883 ) ;
V_123 -> V_884 += F_37 ( V_14 , V_885 ) ;
V_123 -> V_886 += F_37 ( V_14 , V_887 ) ;
V_123 -> V_888 += F_37 ( V_14 , V_889 ) ;
V_123 -> V_890 += F_37 ( V_14 , V_891 ) ;
V_123 -> V_892 += F_37 ( V_14 , V_893 ) ;
V_55 -> V_124 . V_894 = V_123 -> V_845 ;
V_55 -> V_124 . V_895 = V_123 -> V_788 + V_123 -> V_861 ;
V_55 -> V_124 . V_896 = 0 ;
V_55 -> V_124 . V_897 = V_123 -> V_861 ;
V_55 -> V_124 . V_898 = V_123 -> V_788 ;
V_55 -> V_124 . V_899 = V_773 ;
}
static void F_473 ( struct V_1 * V_2 )
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
V_2 -> V_900 ++ ;
if ( F_474 ( V_14 ) == 0 ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_250 ( V_373 ,
& ( V_2 -> V_58 [ V_48 ] -> V_34 ) ) ;
F_71 ( V_14 , V_356 , V_365 ) ;
} else {
F_103 ( V_172 , L_110
L_111 ) ;
}
}
static void F_475 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_901 = 0 ;
int V_48 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_668 , & V_2 -> V_34 ) )
return;
if ( F_109 ( V_2 -> V_55 ) ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_476 ( V_2 -> V_58 [ V_48 ] ) ;
}
if ( ! ( V_2 -> V_139 & V_388 ) ) {
F_71 ( V_14 , V_119 ,
( V_902 | V_903 ) ) ;
} else {
for ( V_48 = 0 ; V_48 < V_2 -> V_189 ; V_48 ++ ) {
struct V_157 * V_904 = V_2 -> V_158 [ V_48 ] ;
if ( V_904 -> V_294 . V_120 || V_904 -> V_162 . V_120 )
V_901 |= ( ( T_6 ) 1 << V_48 ) ;
}
}
F_75 ( V_2 , V_901 ) ;
}
static void F_477 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_905 = V_2 -> V_905 ;
bool V_337 = V_2 -> V_337 ;
bool V_135 = V_2 -> V_136 . V_137 ;
if ( ! ( V_2 -> V_139 & V_352 ) )
return;
if ( V_14 -> V_108 . V_335 . V_336 ) {
V_14 -> V_108 . V_335 . V_336 ( V_14 , & V_905 , & V_337 , false ) ;
} else {
V_905 = V_906 ;
V_337 = true ;
}
if ( V_2 -> V_138 )
V_135 |= ! ! ( V_2 -> V_138 -> V_135 ) ;
if ( V_337 && ! ( ( V_2 -> V_139 & V_140 ) && V_135 ) ) {
V_14 -> V_108 . V_335 . V_907 ( V_14 ) ;
F_478 ( V_2 ) ;
}
if ( V_337 ||
F_479 ( V_171 , ( V_2 -> V_353 +
V_908 ) ) ) {
V_2 -> V_139 &= ~ V_352 ;
F_71 ( V_14 , V_356 , V_355 ) ;
F_216 ( V_14 ) ;
}
V_2 -> V_337 = V_337 ;
V_2 -> V_905 = V_905 ;
}
static void F_480 ( struct V_1 * V_2 )
{
#ifdef F_367
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_909 V_910 = {
. V_911 = V_912 ,
. V_249 = 0 ,
} ;
T_4 V_598 = 0 ;
if ( V_2 -> V_583 & V_913 )
V_598 = F_481 ( V_55 , & V_910 ) ;
V_2 -> V_914 = ( V_598 > 1 ) ? ( F_482 ( V_598 ) - 1 ) : 0 ;
#endif
}
static void F_483 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_95 ;
struct V_632 * V_633 ;
T_1 V_905 = V_2 -> V_905 ;
bool V_915 , V_916 ;
if ( F_109 ( V_55 ) )
return;
V_2 -> V_154 &= ~ V_639 ;
switch ( V_14 -> V_108 . type ) {
case V_109 : {
T_1 V_917 = F_37 ( V_14 , V_564 ) ;
T_1 V_918 = F_37 ( V_14 , V_919 ) ;
V_915 = ! ! ( V_917 & V_920 ) ;
V_916 = ! ! ( V_918 & V_921 ) ;
}
break;
case V_112 :
case V_113 :
case V_114 :
case V_111 : {
T_1 V_922 = F_37 ( V_14 , V_923 ) ;
T_1 V_924 = F_37 ( V_14 , V_925 ) ;
V_915 = ! ! ( V_922 & V_926 ) ;
V_916 = ! ! ( V_924 & V_927 ) ;
}
break;
default:
V_916 = false ;
V_915 = false ;
break;
}
V_2 -> V_928 = V_171 ;
if ( F_14 ( V_679 , & V_2 -> V_34 ) )
F_484 ( V_2 ) ;
F_105 ( V_156 , L_112 ,
( V_905 == V_906 ?
L_113 :
( V_905 == V_929 ?
L_114 :
( V_905 == V_930 ?
L_115 :
L_116 ) ) ) ,
( ( V_915 && V_916 ) ? L_117 :
( V_915 ? L_118 :
( V_916 ? L_119 : L_120 ) ) ) ) ;
F_485 ( V_55 ) ;
F_486 ( V_2 ) ;
F_487 ( V_2 -> V_55 ) ;
F_443 () ;
F_364 (adapter->netdev, upper, iter) {
if ( F_365 ( V_95 ) ) {
struct V_634 * V_247 = F_89 ( V_95 ) ;
if ( V_247 -> V_636 )
F_487 ( V_95 ) ;
}
}
F_445 () ;
F_480 ( V_2 ) ;
F_395 ( V_2 ) ;
}
static void F_488 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_337 = false ;
V_2 -> V_905 = 0 ;
if ( ! F_109 ( V_55 ) )
return;
if ( F_212 ( V_14 ) && V_14 -> V_108 . type == V_109 )
V_2 -> V_154 |= V_639 ;
if ( F_14 ( V_679 , & V_2 -> V_34 ) )
F_484 ( V_2 ) ;
F_105 ( V_156 , L_121 ) ;
F_392 ( V_55 ) ;
F_395 ( V_2 ) ;
}
static bool F_489 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_58 = V_2 -> V_58 [ V_48 ] ;
if ( V_58 -> V_80 != V_58 -> V_79 )
return true ;
}
return false ;
}
static bool F_490 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_931 * V_932 = & V_2 -> V_413 [ V_490 ] ;
T_1 V_933 = F_491 ( 1 , ~ V_932 -> V_117 ) ;
int V_48 , V_49 ;
if ( ! V_2 -> V_302 )
return false ;
if ( V_14 -> V_108 . type >= V_113 )
return false ;
for ( V_48 = 0 ; V_48 < V_2 -> V_302 ; V_48 ++ ) {
for ( V_49 = 0 ; V_49 < V_933 ; V_49 ++ ) {
T_1 V_934 , V_935 ;
V_934 = F_37 ( V_14 , F_492 ( V_933 , V_48 , V_49 ) ) ;
V_935 = F_37 ( V_14 , F_493 ( V_933 , V_48 , V_49 ) ) ;
if ( V_934 != V_935 )
return true ;
}
}
return false ;
}
static void F_494 ( struct V_1 * V_2 )
{
if ( ! F_109 ( V_2 -> V_55 ) ) {
if ( F_489 ( V_2 ) ||
F_490 ( V_2 ) ) {
F_93 ( V_156 , L_122 ) ;
V_2 -> V_154 |= V_155 ;
}
}
}
static inline void F_495 ( struct V_1 * V_2 ,
struct V_5 * V_936 )
{
if ( ! F_496 ( V_936 ) )
F_11 ( L_123 ) ;
F_18 ( L_124 , F_497 ( V_936 ) ) ;
F_498 ( V_936 , V_937 , V_938 ) ;
F_382 ( 100 ) ;
}
static void F_499 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
struct V_5 * V_936 ;
T_1 V_939 ;
int V_940 ;
unsigned short V_941 ;
if ( ! ( F_109 ( V_2 -> V_55 ) ) )
return;
V_939 = F_37 ( V_14 , V_942 ) ;
if ( V_939 )
return;
if ( ! V_9 )
return;
V_940 = F_500 ( V_9 , V_943 ) ;
if ( ! V_940 )
return;
F_25 ( V_9 , V_940 + V_944 , & V_941 ) ;
V_936 = F_501 ( V_9 -> V_690 , V_941 , NULL ) ;
while ( V_936 ) {
if ( V_936 -> V_945 && ( V_936 -> V_946 == V_9 ) ) {
T_2 V_947 ;
F_25 ( V_936 , V_948 , & V_947 ) ;
if ( V_947 & V_949 )
F_495 ( V_2 , V_936 ) ;
}
V_936 = F_501 ( V_9 -> V_690 , V_941 , V_936 ) ;
}
}
static void F_502 ( struct V_1 * V_2 )
{
T_1 V_950 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ||
V_2 -> V_302 == 0 )
return;
V_950 = F_37 ( & V_2 -> V_14 , V_951 ) ;
if ( ! V_950 )
return;
F_93 ( V_156 , L_125 , V_950 ) ;
}
static void F_502 ( struct V_1 T_14 * V_2 )
{
}
static void
F_499 ( struct V_1 T_14 * V_2 )
{
}
static void F_503 ( struct V_1 * V_2 )
{
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_668 , & V_2 -> V_34 ) )
return;
F_477 ( V_2 ) ;
if ( V_2 -> V_337 )
F_483 ( V_2 ) ;
else
F_488 ( V_2 ) ;
F_499 ( V_2 ) ;
F_502 ( V_2 ) ;
F_455 ( V_2 ) ;
F_494 ( V_2 ) ;
}
static void F_504 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_3 V_17 ;
if ( ! ( V_2 -> V_154 & V_639 ) &&
! ( V_2 -> V_154 & V_349 ) )
return;
if ( F_15 ( V_670 , & V_2 -> V_34 ) )
return;
V_17 = V_14 -> V_338 . V_335 . V_952 ( V_14 ) ;
if ( V_17 == V_673 )
goto V_953;
if ( V_17 == V_672 ) {
V_2 -> V_154 |= V_349 ;
}
if ( V_17 )
goto V_953;
if ( ! ( V_2 -> V_154 & V_349 ) )
goto V_953;
V_2 -> V_154 &= ~ V_349 ;
if ( V_14 -> V_108 . type == V_109 )
V_17 = V_14 -> V_338 . V_335 . V_954 ( V_14 ) ;
else
V_17 = V_14 -> V_108 . V_335 . V_955 ( V_14 ) ;
if ( V_17 == V_673 )
goto V_953;
V_2 -> V_139 |= V_350 ;
F_105 ( V_172 , L_126 , V_14 -> V_338 . V_956 ) ;
V_953:
F_34 ( V_670 , & V_2 -> V_34 ) ;
if ( ( V_17 == V_673 ) &&
( V_2 -> V_55 -> V_957 == V_958 ) ) {
F_18 ( L_127
L_128 ) ;
F_18 ( L_129
L_130 ) ;
F_505 ( V_2 -> V_55 ) ;
}
}
static void F_506 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_20 ;
bool V_640 = false ;
if ( ! ( V_2 -> V_139 & V_350 ) )
return;
if ( F_15 ( V_670 , & V_2 -> V_34 ) )
return;
V_2 -> V_139 &= ~ V_350 ;
V_20 = V_14 -> V_338 . V_643 ;
if ( ( ! V_20 ) && ( V_14 -> V_108 . V_335 . V_644 ) ) {
V_14 -> V_108 . V_335 . V_644 ( V_14 , & V_20 , & V_640 ) ;
if ( ! V_640 ) {
if ( V_20 & V_906 )
V_20 = V_906 ;
}
}
if ( V_14 -> V_108 . V_335 . V_645 )
V_14 -> V_108 . V_335 . V_645 ( V_14 , V_20 , true ) ;
V_2 -> V_139 |= V_352 ;
V_2 -> V_353 = V_171 ;
F_34 ( V_670 , & V_2 -> V_34 ) ;
}
static void F_507 ( unsigned long V_92 )
{
struct V_1 * V_2 = (struct V_1 * ) V_92 ;
unsigned long V_959 ;
if ( V_2 -> V_139 & V_352 )
V_959 = V_960 / 10 ;
else
V_959 = V_960 * 2 ;
F_377 ( & V_2 -> V_666 , V_959 + V_171 ) ;
F_13 ( V_2 ) ;
}
static void F_508 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_165 ;
if ( ! ( V_2 -> V_154 & V_368 ) )
return;
V_2 -> V_154 &= ~ V_368 ;
if ( ! V_14 -> V_338 . V_335 . V_961 )
return;
V_165 = V_14 -> V_338 . V_335 . V_961 ( & V_2 -> V_14 ) ;
if ( V_165 != V_340 )
return;
F_208 ( V_156 , L_70 , V_341 ) ;
}
static void F_509 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_154 & V_155 ) )
return;
V_2 -> V_154 &= ~ V_155 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_668 , & V_2 -> V_34 ) )
return;
F_54 ( V_2 ) ;
F_510 ( V_2 -> V_55 , L_131 ) ;
V_2 -> V_173 ++ ;
F_443 () ;
F_378 ( V_2 ) ;
F_445 () ;
}
static void F_511 ( struct V_962 * V_963 )
{
struct V_1 * V_2 = F_196 ( V_963 ,
struct V_1 ,
V_37 ) ;
if ( F_22 ( V_2 -> V_14 . V_39 ) ) {
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
F_443 () ;
F_381 ( V_2 ) ;
F_445 () ;
}
F_31 ( V_2 ) ;
return;
}
F_509 ( V_2 ) ;
F_508 ( V_2 ) ;
F_504 ( V_2 ) ;
F_506 ( V_2 ) ;
F_206 ( V_2 ) ;
F_503 ( V_2 ) ;
F_473 ( V_2 ) ;
F_475 ( V_2 ) ;
if ( F_14 ( V_679 , & V_2 -> V_34 ) ) {
F_512 ( V_2 ) ;
F_513 ( V_2 ) ;
}
F_31 ( V_2 ) ;
}
static int F_514 ( struct V_57 * V_58 ,
struct V_59 * V_964 ,
T_4 * V_236 )
{
struct V_195 * V_89 = V_964 -> V_89 ;
T_1 V_965 , V_966 ;
T_1 V_967 , V_968 ;
int V_17 ;
if ( V_89 -> V_215 != V_969 )
return 0 ;
if ( ! F_515 ( V_89 ) )
return 0 ;
V_17 = F_516 ( V_89 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_966 = V_970 ;
if ( V_964 -> V_249 == F_156 ( V_971 ) ) {
struct V_972 * V_973 = F_517 ( V_89 ) ;
V_973 -> V_974 = 0 ;
V_973 -> V_975 = 0 ;
F_518 ( V_89 ) -> V_975 = ~ F_519 ( V_973 -> V_976 ,
V_973 -> V_977 , 0 ,
V_978 ,
0 ) ;
V_966 |= V_979 ;
V_964 -> V_980 |= V_981 |
V_982 |
V_983 ;
} else if ( F_520 ( V_89 ) ) {
F_521 ( V_89 ) -> V_984 = 0 ;
F_518 ( V_89 ) -> V_975 =
~ F_522 ( & F_521 ( V_89 ) -> V_976 ,
& F_521 ( V_89 ) -> V_977 ,
0 , V_978 , 0 ) ;
V_964 -> V_980 |= V_981 |
V_982 ;
}
V_968 = F_523 ( V_89 ) ;
* V_236 = F_524 ( V_89 ) + V_968 ;
V_964 -> V_168 = F_148 ( V_89 ) -> V_168 ;
V_964 -> V_167 += ( V_964 -> V_168 - 1 ) * * V_236 ;
V_967 = V_968 << V_985 ;
V_967 |= F_148 ( V_89 ) -> V_237 << V_986 ;
V_965 = F_525 ( V_89 ) ;
V_965 |= F_526 ( V_89 ) << V_987 ;
V_965 |= V_964 -> V_980 & V_988 ;
F_527 ( V_58 , V_965 , 0 , V_966 ,
V_967 ) ;
return 1 ;
}
static void F_528 ( struct V_57 * V_58 ,
struct V_59 * V_964 )
{
struct V_195 * V_89 = V_964 -> V_89 ;
T_1 V_965 = 0 ;
T_1 V_967 = 0 ;
T_1 V_966 = 0 ;
if ( V_89 -> V_215 != V_969 ) {
if ( ! ( V_964 -> V_980 & V_989 ) &&
! ( V_964 -> V_980 & V_990 ) )
return;
} else {
T_4 V_991 = 0 ;
switch ( V_964 -> V_249 ) {
case F_156 ( V_971 ) :
V_965 |= F_525 ( V_89 ) ;
V_966 |= V_979 ;
V_991 = F_517 ( V_89 ) -> V_249 ;
break;
case F_156 ( V_992 ) :
V_965 |= F_525 ( V_89 ) ;
V_991 = F_521 ( V_89 ) -> V_993 ;
break;
default:
if ( F_24 ( F_529 () ) ) {
F_530 ( V_58 -> V_73 ,
L_132 ,
V_964 -> V_249 ) ;
}
break;
}
switch ( V_991 ) {
case V_978 :
V_966 |= V_970 ;
V_967 = F_523 ( V_89 ) <<
V_985 ;
break;
case V_994 :
V_966 |= V_995 ;
V_967 = sizeof( struct V_996 ) <<
V_985 ;
break;
case V_997 :
V_967 = sizeof( struct V_998 ) <<
V_985 ;
break;
default:
if ( F_24 ( F_529 () ) ) {
F_530 ( V_58 -> V_73 ,
L_133 ,
V_991 ) ;
}
break;
}
V_964 -> V_980 |= V_982 ;
}
V_965 |= F_526 ( V_89 ) << V_987 ;
V_965 |= V_964 -> V_980 & V_988 ;
F_527 ( V_58 , V_965 , 0 ,
V_966 , V_967 ) ;
}
static T_1 F_531 ( struct V_195 * V_89 , T_1 V_980 )
{
T_1 V_999 = V_1000 |
V_1001 |
V_1002 ;
V_999 |= F_532 ( V_980 , V_989 ,
V_1003 ) ;
V_999 |= F_532 ( V_980 , V_981 ,
V_1004 ) ;
V_999 |= F_532 ( V_980 , V_1005 ,
V_1006 ) ;
V_999 ^= F_532 ( V_89 -> V_1007 , 1 , V_1002 ) ;
return V_999 ;
}
static void F_533 ( union V_61 * V_62 ,
T_1 V_980 , unsigned int V_1008 )
{
T_1 V_1009 = V_1008 << V_1010 ;
V_1009 |= F_532 ( V_980 ,
V_982 ,
V_1011 ) ;
V_1009 |= F_532 ( V_980 ,
V_983 ,
V_1012 ) ;
V_1009 |= F_532 ( V_980 ,
V_990 ,
V_1013 ) ;
V_62 -> V_233 . V_1009 = F_96 ( V_1009 ) ;
}
static int F_534 ( struct V_57 * V_58 , T_2 V_274 )
{
F_104 ( V_58 -> V_55 , V_58 -> V_86 ) ;
F_111 () ;
if ( F_99 ( F_110 ( V_58 ) < V_274 ) )
return - V_751 ;
F_535 ( V_58 -> V_55 , V_58 -> V_86 ) ;
++ V_58 -> V_152 . V_174 ;
return 0 ;
}
static inline int F_536 ( struct V_57 * V_58 , T_2 V_274 )
{
if ( F_99 ( F_110 ( V_58 ) >= V_274 ) )
return 0 ;
return F_534 ( V_58 , V_274 ) ;
}
static void F_537 ( struct V_57 * V_58 ,
struct V_59 * V_964 ,
const T_4 V_236 )
{
struct V_195 * V_89 = V_964 -> V_89 ;
struct V_59 * V_60 ;
union V_61 * V_62 ;
struct V_260 * V_261 ;
T_9 V_81 ;
unsigned int V_266 , V_274 ;
T_1 V_980 = V_964 -> V_980 ;
T_1 V_999 = F_531 ( V_89 , V_980 ) ;
T_2 V_48 = V_58 -> V_80 ;
V_62 = F_61 ( V_58 , V_48 ) ;
F_533 ( V_62 , V_980 , V_89 -> V_82 - V_236 ) ;
V_274 = F_147 ( V_89 ) ;
V_266 = V_89 -> V_266 ;
#ifdef F_175
if ( V_980 & V_1014 ) {
if ( V_266 < sizeof( struct V_293 ) ) {
V_274 -= sizeof( struct V_293 ) - V_266 ;
V_266 = 0 ;
} else {
V_266 -= sizeof( struct V_293 ) ;
}
}
#endif
V_81 = F_538 ( V_58 -> V_73 , V_89 -> V_92 , V_274 , V_121 ) ;
V_60 = V_964 ;
for ( V_261 = & F_148 ( V_89 ) -> V_262 [ 0 ] ; ; V_261 ++ ) {
if ( F_140 ( V_58 -> V_73 , V_81 ) )
goto V_1015;
F_81 ( V_60 , V_82 , V_274 ) ;
F_539 ( V_60 , V_81 , V_81 ) ;
V_62 -> V_233 . V_1016 = F_143 ( V_81 ) ;
while ( F_24 ( V_274 > V_1017 ) ) {
V_62 -> V_233 . V_1018 =
F_96 ( V_999 ^ V_1017 ) ;
V_48 ++ ;
V_62 ++ ;
if ( V_48 == V_58 -> V_88 ) {
V_62 = F_61 ( V_58 , 0 ) ;
V_48 = 0 ;
}
V_62 -> V_233 . V_1009 = 0 ;
V_81 += V_1017 ;
V_274 -= V_1017 ;
V_62 -> V_233 . V_1016 = F_143 ( V_81 ) ;
}
if ( F_99 ( ! V_266 ) )
break;
V_62 -> V_233 . V_1018 = F_96 ( V_999 ^ V_274 ) ;
V_48 ++ ;
V_62 ++ ;
if ( V_48 == V_58 -> V_88 ) {
V_62 = F_61 ( V_58 , 0 ) ;
V_48 = 0 ;
}
V_62 -> V_233 . V_1009 = 0 ;
#ifdef F_175
V_274 = F_359 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_274 = F_540 ( V_261 ) ;
#endif
V_266 -= V_274 ;
V_81 = F_541 ( V_58 -> V_73 , V_261 , 0 , V_274 ,
V_121 ) ;
V_60 = & V_58 -> V_78 [ V_48 ] ;
}
V_999 |= V_274 | V_1019 ;
V_62 -> V_233 . V_1018 = F_96 ( V_999 ) ;
F_542 ( F_107 ( V_58 ) , V_964 -> V_167 ) ;
V_964 -> V_84 = V_171 ;
F_144 () ;
V_964 -> V_83 = V_62 ;
V_48 ++ ;
if ( V_48 == V_58 -> V_88 )
V_48 = 0 ;
V_58 -> V_80 = V_48 ;
F_536 ( V_58 , V_1020 ) ;
if ( F_543 ( F_107 ( V_58 ) ) || ! V_89 -> V_1021 ) {
F_145 ( V_48 , V_58 -> V_146 ) ;
F_544 () ;
}
return;
V_1015:
F_415 ( V_58 -> V_73 , L_134 ) ;
for (; ; ) {
V_60 = & V_58 -> V_78 [ V_48 ] ;
F_77 ( V_58 , V_60 ) ;
if ( V_60 == V_964 )
break;
if ( V_48 == 0 )
V_48 = V_58 -> V_88 ;
V_48 -- ;
}
V_58 -> V_80 = V_48 ;
}
static void F_545 ( struct V_57 * V_120 ,
struct V_59 * V_964 )
{
struct V_157 * V_158 = V_120 -> V_158 ;
union V_1022 V_1023 = { . V_1024 = 0 } ;
union V_1022 V_1025 = { . V_1024 = 0 } ;
union {
unsigned char * V_1026 ;
struct V_972 * V_1027 ;
struct V_1028 * V_1029 ;
} V_1030 ;
struct V_1031 * V_1032 ;
T_12 V_1033 ;
if ( ! V_158 )
return;
if ( ! V_120 -> V_398 )
return;
V_120 -> V_399 ++ ;
V_1030 . V_1026 = F_546 ( V_964 -> V_89 ) ;
if ( ( V_964 -> V_249 != F_156 ( V_992 ) ||
V_1030 . V_1029 -> V_993 != V_978 ) &&
( V_964 -> V_249 != F_156 ( V_971 ) ||
V_1030 . V_1027 -> V_249 != V_978 ) )
return;
V_1032 = F_518 ( V_964 -> V_89 ) ;
if ( ! V_1032 || V_1032 -> V_1034 )
return;
if ( ! V_1032 -> V_1035 && ( V_120 -> V_399 < V_120 -> V_398 ) )
return;
V_120 -> V_399 = 0 ;
V_1033 = F_156 ( V_964 -> V_980 >> V_1036 ) ;
V_1023 . V_1037 . V_1033 = V_1033 ;
if ( V_964 -> V_980 & ( V_1038 | V_989 ) )
V_1025 . V_1039 . V_1040 ^= V_1032 -> V_1041 ^ F_156 ( V_248 ) ;
else
V_1025 . V_1039 . V_1040 ^= V_1032 -> V_1041 ^ V_964 -> V_249 ;
V_1025 . V_1039 . V_1042 ^= V_1032 -> V_1043 ;
if ( V_964 -> V_249 == F_156 ( V_971 ) ) {
V_1023 . V_1037 . V_1044 = V_1045 ;
V_1025 . V_1046 ^= V_1030 . V_1027 -> V_976 ^ V_1030 . V_1027 -> V_977 ;
} else {
V_1023 . V_1037 . V_1044 = V_1047 ;
V_1025 . V_1046 ^= V_1030 . V_1029 -> V_976 . V_1048 [ 0 ] ^
V_1030 . V_1029 -> V_976 . V_1048 [ 1 ] ^
V_1030 . V_1029 -> V_976 . V_1048 [ 2 ] ^
V_1030 . V_1029 -> V_976 . V_1048 [ 3 ] ^
V_1030 . V_1029 -> V_977 . V_1048 [ 0 ] ^
V_1030 . V_1029 -> V_977 . V_1048 [ 1 ] ^
V_1030 . V_1029 -> V_977 . V_1048 [ 2 ] ^
V_1030 . V_1029 -> V_977 . V_1048 [ 3 ] ;
}
F_547 ( & V_158 -> V_2 -> V_14 ,
V_1023 , V_1025 , V_120 -> V_86 ) ;
}
static T_2 F_548 ( struct V_54 * V_73 , struct V_195 * V_89 ,
void * V_1049 , T_15 V_1050 )
{
struct V_618 * V_1051 = V_1049 ;
#ifdef F_175
struct V_1 * V_2 ;
struct V_931 * V_1052 ;
int V_1053 ;
#endif
if ( V_1051 )
return V_89 -> V_1054 + V_1051 -> V_626 ;
#ifdef F_175
switch ( F_549 ( V_89 ) ) {
case F_156 ( V_1055 ) :
case F_156 ( V_1056 ) :
V_2 = F_89 ( V_73 ) ;
if ( V_2 -> V_139 & V_511 )
break;
default:
return V_1050 ( V_73 , V_89 ) ;
}
V_1052 = & V_2 -> V_413 [ V_1057 ] ;
V_1053 = F_550 ( V_89 ) ? F_551 ( V_89 ) :
F_552 () ;
while ( V_1053 >= V_1052 -> V_415 )
V_1053 -= V_1052 -> V_415 ;
return V_1053 + V_1052 -> V_1058 ;
#else
return V_1050 ( V_73 , V_89 ) ;
#endif
}
T_16 F_553 ( struct V_195 * V_89 ,
struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_59 * V_964 ;
int V_1059 ;
T_1 V_980 = 0 ;
unsigned short V_1052 ;
T_2 V_88 = F_554 ( F_147 ( V_89 ) ) ;
T_12 V_249 = V_89 -> V_249 ;
T_4 V_236 = 0 ;
for ( V_1052 = 0 ; V_1052 < F_148 ( V_89 ) -> V_280 ; V_1052 ++ )
V_88 += F_554 ( F_148 ( V_89 ) -> V_262 [ V_1052 ] . V_274 ) ;
if ( F_536 ( V_58 , V_88 + 3 ) ) {
V_58 -> V_152 . V_780 ++ ;
return V_1060 ;
}
V_964 = & V_58 -> V_78 [ V_58 -> V_80 ] ;
V_964 -> V_89 = V_89 ;
V_964 -> V_167 = V_89 -> V_82 ;
V_964 -> V_168 = 1 ;
if ( F_555 ( V_89 ) ) {
V_980 |= F_556 ( V_89 ) << V_1036 ;
V_980 |= V_989 ;
} else if ( V_249 == F_156 ( V_248 ) ) {
struct V_1061 * V_1062 , V_1063 ;
V_1062 = F_557 ( V_89 , V_507 , sizeof( V_1063 ) , & V_1063 ) ;
if ( ! V_1062 )
goto V_1064;
V_980 |= F_558 ( V_1062 -> V_1065 ) <<
V_1036 ;
V_980 |= V_1038 ;
}
V_249 = F_549 ( V_89 ) ;
if ( F_24 ( F_148 ( V_89 ) -> V_980 & V_1066 ) &&
V_2 -> V_1067 &&
! F_559 ( V_1068 ,
& V_2 -> V_34 ) ) {
F_148 ( V_89 ) -> V_980 |= V_1069 ;
V_980 |= V_1005 ;
V_2 -> V_1070 = F_560 ( V_89 ) ;
V_2 -> V_1071 = V_171 ;
F_16 ( & V_2 -> V_1072 ) ;
}
F_561 ( V_89 ) ;
#ifdef F_299
if ( V_2 -> V_139 & V_408 )
V_980 |= V_990 ;
#endif
if ( ( V_2 -> V_139 & V_140 ) &&
( ( V_980 & ( V_989 | V_1038 ) ) ||
( V_89 -> V_1073 != V_1074 ) ) ) {
V_980 &= ~ V_1075 ;
V_980 |= ( V_89 -> V_1073 & 0x7 ) <<
V_1076 ;
if ( V_980 & V_1038 ) {
struct V_1077 * V_1062 ;
if ( F_516 ( V_89 , 0 ) )
goto V_1064;
V_1062 = (struct V_1077 * ) V_89 -> V_92 ;
V_1062 -> V_1065 = F_156 ( V_980 >>
V_1036 ) ;
} else {
V_980 |= V_989 ;
}
}
V_964 -> V_980 = V_980 ;
V_964 -> V_249 = V_249 ;
#ifdef F_175
if ( ( V_249 == F_156 ( V_1055 ) ) &&
( V_58 -> V_55 -> V_196 & ( V_1078 | V_1079 ) ) ) {
V_1059 = F_562 ( V_58 , V_964 , & V_236 ) ;
if ( V_1059 < 0 )
goto V_1064;
goto V_1080;
}
#endif
V_1059 = F_514 ( V_58 , V_964 , & V_236 ) ;
if ( V_1059 < 0 )
goto V_1064;
else if ( ! V_1059 )
F_528 ( V_58 , V_964 ) ;
if ( F_14 ( V_373 , & V_58 -> V_34 ) )
F_545 ( V_58 , V_964 ) ;
#ifdef F_175
V_1080:
#endif
F_537 ( V_58 , V_964 , V_236 ) ;
return V_1081 ;
V_1064:
F_78 ( V_964 -> V_89 ) ;
V_964 -> V_89 = NULL ;
return V_1081 ;
}
static T_16 F_563 ( struct V_195 * V_89 ,
struct V_54 * V_55 ,
struct V_57 * V_120 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_57 * V_58 ;
if ( F_564 ( V_89 , 17 ) )
return V_1081 ;
V_58 = V_120 ? V_120 : V_2 -> V_58 [ V_89 -> V_1054 ] ;
return F_553 ( V_89 , V_2 , V_58 ) ;
}
static T_16 F_565 ( struct V_195 * V_89 ,
struct V_54 * V_55 )
{
return F_563 ( V_89 , V_55 , NULL ) ;
}
static int F_566 ( struct V_54 * V_55 , void * V_1082 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1083 * V_550 = V_1082 ;
int V_641 ;
if ( ! F_362 ( V_550 -> V_1084 ) )
return - V_1085 ;
F_311 ( V_2 , V_14 -> V_108 . V_550 , F_281 ( 0 ) ) ;
memcpy ( V_55 -> V_631 , V_550 -> V_1084 , V_55 -> V_676 ) ;
memcpy ( V_14 -> V_108 . V_550 , V_550 -> V_1084 , V_55 -> V_676 ) ;
V_641 = F_308 ( V_2 , V_14 -> V_108 . V_550 , F_281 ( 0 ) ) ;
return V_641 > 0 ? 0 : V_641 ;
}
static int
F_567 ( struct V_54 * V_55 , int V_1086 , int V_1087 , T_2 V_550 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_4 ;
int V_1088 ;
if ( V_1086 != V_14 -> V_338 . V_1089 . V_1086 )
return - V_556 ;
V_1088 = V_14 -> V_338 . V_335 . V_1090 ( V_14 , V_550 , V_1087 , & V_4 ) ;
if ( ! V_1088 )
V_1088 = V_4 ;
return V_1088 ;
}
static int F_568 ( struct V_54 * V_55 , int V_1086 , int V_1087 ,
T_2 V_550 , T_2 V_4 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_1086 != V_14 -> V_338 . V_1089 . V_1086 )
return - V_556 ;
return V_14 -> V_338 . V_335 . V_1091 ( V_14 , V_550 , V_1087 , V_4 ) ;
}
static int F_569 ( struct V_54 * V_55 , struct V_1092 * V_1093 , int V_1094 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
switch ( V_1094 ) {
case V_1095 :
return F_570 ( V_2 , V_1093 ) ;
case V_1096 :
return F_571 ( V_2 , V_1093 ) ;
default:
return F_572 ( & V_2 -> V_14 . V_338 . V_1089 , F_573 ( V_1093 ) , V_1094 ) ;
}
}
static int F_574 ( struct V_54 * V_73 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_362 ( V_14 -> V_108 . V_1097 ) ) {
F_443 () ;
V_17 = F_575 ( V_73 , V_14 -> V_108 . V_1097 , V_1098 ) ;
F_445 () ;
V_14 -> V_108 . V_335 . V_678 ( V_14 , F_281 ( 0 ) ) ;
}
return V_17 ;
}
static int F_576 ( struct V_54 * V_73 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_1099 * V_108 = & V_2 -> V_14 . V_108 ;
if ( F_362 ( V_108 -> V_1097 ) ) {
F_443 () ;
V_17 = F_577 ( V_73 , V_108 -> V_1097 , V_1098 ) ;
F_445 () ;
}
return V_17 ;
}
static void F_578 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_48 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
for ( V_48 = 0 ; V_48 < V_2 -> V_189 ; V_48 ++ )
F_229 ( 0 , V_2 -> V_158 [ V_48 ] ) ;
}
static struct V_1100 * F_579 ( struct V_54 * V_55 ,
struct V_1100 * V_124 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_48 ;
F_580 () ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_120 = F_21 ( V_2 -> V_67 [ V_48 ] ) ;
T_6 V_170 , V_144 ;
unsigned int V_1101 ;
if ( V_120 ) {
do {
V_1101 = F_581 ( & V_120 -> V_169 ) ;
V_144 = V_120 -> V_124 . V_144 ;
V_170 = V_120 -> V_124 . V_170 ;
} while ( F_582 ( & V_120 -> V_169 , V_1101 ) );
V_124 -> V_785 += V_144 ;
V_124 -> V_784 += V_170 ;
}
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_120 = F_21 ( V_2 -> V_58 [ V_48 ] ) ;
T_6 V_170 , V_144 ;
unsigned int V_1101 ;
if ( V_120 ) {
do {
V_1101 = F_581 ( & V_120 -> V_169 ) ;
V_144 = V_120 -> V_124 . V_144 ;
V_170 = V_120 -> V_124 . V_170 ;
} while ( F_582 ( & V_120 -> V_169 , V_1101 ) );
V_124 -> V_787 += V_144 ;
V_124 -> V_786 += V_170 ;
}
}
F_583 () ;
V_124 -> V_894 = V_55 -> V_124 . V_894 ;
V_124 -> V_895 = V_55 -> V_124 . V_895 ;
V_124 -> V_897 = V_55 -> V_124 . V_897 ;
V_124 -> V_898 = V_55 -> V_124 . V_898 ;
V_124 -> V_899 = V_55 -> V_124 . V_899 ;
return V_124 ;
}
static void F_584 ( struct V_1 * V_2 , T_4 V_134 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_3 , V_1102 ;
int V_48 ;
if ( V_14 -> V_108 . type == V_109 )
return;
V_3 = F_37 ( V_14 , V_1103 ) ;
V_1102 = V_3 ;
for ( V_48 = 0 ; V_48 < V_602 ; V_48 ++ ) {
T_4 V_1104 = V_3 >> ( V_48 * V_1105 ) ;
if ( V_1104 > V_134 )
V_3 &= ~ ( 0x7 << V_1105 ) ;
}
if ( V_3 != V_1102 )
F_71 ( V_14 , V_1103 , V_3 ) ;
return;
}
static void F_585 ( struct V_1 * V_2 )
{
struct V_54 * V_73 = V_2 -> V_55 ;
struct V_1106 * V_136 = & V_2 -> V_136 ;
struct V_1107 * V_1108 = V_2 -> V_587 ;
T_4 V_1109 ;
for ( V_1109 = 0 ; V_1109 < V_1110 ; V_1109 ++ ) {
T_4 V_134 = 0 ;
if ( V_2 -> V_583 & V_584 )
V_134 = F_586 ( V_136 , 0 , V_1109 ) ;
else if ( V_1108 )
V_134 = V_1108 -> V_588 [ V_1109 ] ;
F_587 ( V_73 , V_1109 , V_134 ) ;
}
}
int F_588 ( struct V_54 * V_73 , T_4 V_134 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
bool V_1111 ;
if ( V_134 > V_2 -> V_136 . V_712 . V_713 ||
( V_14 -> V_108 . type == V_109 &&
V_134 < V_602 ) )
return - V_556 ;
V_1111 = ( F_589 ( & V_2 -> V_628 , 32 ) > 1 ) ;
if ( V_134 && V_1111 && V_2 -> V_629 > V_1112 )
return - V_751 ;
if ( F_57 ( V_73 ) )
F_433 ( V_73 ) ;
F_450 ( V_2 ) ;
#ifdef F_367
if ( V_134 ) {
F_590 ( V_73 , V_134 ) ;
F_585 ( V_2 ) ;
V_2 -> V_139 |= V_140 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ) {
V_2 -> V_1113 = V_2 -> V_14 . V_125 . V_727 ;
V_2 -> V_14 . V_125 . V_727 = V_1114 ;
}
} else {
F_591 ( V_73 ) ;
if ( V_2 -> V_14 . V_108 . type == V_109 )
V_2 -> V_14 . V_125 . V_727 = V_2 -> V_1113 ;
V_2 -> V_139 &= ~ V_140 ;
V_2 -> V_726 . V_137 = false ;
V_2 -> V_136 . V_137 = false ;
}
F_584 ( V_2 , V_134 ) ;
#endif
F_444 ( V_2 ) ;
if ( F_57 ( V_73 ) )
return F_427 ( V_73 ) ;
return 0 ;
}
void F_592 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
F_443 () ;
F_588 ( V_55 , F_254 ( V_55 ) ) ;
F_445 () ;
}
void F_593 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
if ( F_57 ( V_55 ) )
F_378 ( V_2 ) ;
else
F_384 ( V_2 ) ;
}
static T_17 F_594 ( struct V_54 * V_55 ,
T_17 V_196 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
if ( ! ( V_196 & V_211 ) )
V_196 &= ~ V_1115 ;
if ( ! ( V_2 -> V_154 & V_698 ) )
V_196 &= ~ V_1115 ;
return V_196 ;
}
static int F_595 ( struct V_54 * V_55 ,
T_17 V_196 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
T_17 V_1116 = V_55 -> V_196 ^ V_196 ;
bool V_1117 = false ;
if ( ! ( V_196 & V_1115 ) ) {
if ( V_2 -> V_154 & V_519 )
V_1117 = true ;
V_2 -> V_154 &= ~ V_519 ;
} else if ( ( V_2 -> V_154 & V_698 ) &&
! ( V_2 -> V_154 & V_519 ) ) {
if ( V_2 -> V_379 == 1 ||
V_2 -> V_379 > V_1118 ) {
V_2 -> V_154 |= V_519 ;
V_1117 = true ;
} else if ( ( V_1116 ^ V_196 ) & V_1115 ) {
F_105 ( V_172 , L_135
L_136 ) ;
}
}
switch ( V_196 & V_1119 ) {
case V_1119 :
if ( ! ( V_2 -> V_139 & V_604 ) )
V_1117 = true ;
V_2 -> V_139 &= ~ V_363 ;
V_2 -> V_139 |= V_604 ;
break;
default:
if ( V_2 -> V_139 & V_604 )
V_1117 = true ;
V_2 -> V_139 &= ~ V_604 ;
if ( V_2 -> V_139 & V_408 )
break;
if ( F_254 ( V_55 ) > 1 )
break;
if ( V_2 -> V_413 [ V_414 ] . V_697 <= 1 )
break;
if ( ! V_2 -> V_398 )
break;
V_2 -> V_139 |= V_363 ;
break;
}
if ( V_196 & V_244 )
F_296 ( V_2 ) ;
else
F_295 ( V_2 ) ;
if ( V_1116 & V_269 )
V_1117 = true ;
V_55 -> V_196 = V_196 ;
if ( V_1117 )
F_593 ( V_55 ) ;
return 0 ;
}
static void F_596 ( struct V_54 * V_73 , T_18 V_1120 ,
T_12 V_1039 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1121 = F_558 ( V_1039 ) ;
if ( V_1120 == V_1122 )
return;
if ( V_2 -> V_1123 == V_1121 ) {
F_597 ( V_73 , L_137 , V_1121 ) ;
return;
}
if ( V_2 -> V_1123 ) {
F_597 ( V_73 ,
L_138 ,
V_1121 ) ;
return;
}
V_2 -> V_1123 = V_1121 ;
F_71 ( V_14 , V_1124 , V_1121 ) ;
}
static void F_598 ( struct V_54 * V_73 , T_18 V_1120 ,
T_12 V_1039 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1121 = F_558 ( V_1039 ) ;
if ( V_1120 == V_1122 )
return;
if ( V_2 -> V_1123 != V_1121 ) {
F_597 ( V_73 , L_139 ,
V_1121 ) ;
return;
}
V_2 -> V_1123 = 0 ;
F_71 ( V_14 , V_1124 , 0 ) ;
}
static int F_599 ( struct V_1125 * V_1126 , struct V_1127 * V_1128 [] ,
struct V_54 * V_73 ,
const unsigned char * V_550 , T_2 V_246 ,
T_2 V_139 )
{
if ( F_600 ( V_550 ) || F_601 ( V_550 ) ) {
if ( V_1129 <= F_314 ( V_73 ) )
return - V_545 ;
}
return F_602 ( V_1126 , V_1128 , V_73 , V_550 , V_246 , V_139 ) ;
}
static int F_603 ( struct V_1 * V_2 ,
T_19 V_1130 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
unsigned int V_1082 , V_1131 ;
T_1 V_479 ;
switch ( V_1130 ) {
case V_1132 :
F_71 ( & V_2 -> V_14 , V_487 , 0 ) ;
V_479 = F_37 ( V_14 , V_1133 ) ;
V_479 |= V_484 ;
F_71 ( V_14 , V_1133 , V_479 ) ;
V_1131 = V_2 -> V_302 + V_2 -> V_629 ;
for ( V_1082 = 0 ; V_1082 < V_1131 ; V_1082 ++ ) {
if ( V_14 -> V_108 . V_335 . V_1134 )
V_14 -> V_108 . V_335 . V_1134 ( V_14 ,
true ,
V_1082 ) ;
}
break;
case V_486 :
F_71 ( & V_2 -> V_14 , V_487 ,
V_488 ) ;
V_479 = F_37 ( V_14 , V_1133 ) ;
if ( ! V_2 -> V_302 )
V_479 &= ~ V_484 ;
F_71 ( V_14 , V_1133 , V_479 ) ;
V_1131 = V_2 -> V_302 + V_2 -> V_629 ;
for ( V_1082 = 0 ; V_1082 < V_1131 ; V_1082 ++ ) {
if ( V_14 -> V_108 . V_335 . V_1134 )
V_14 -> V_108 . V_335 . V_1134 ( V_14 ,
false ,
V_1082 ) ;
}
break;
default:
return - V_556 ;
}
V_2 -> V_485 = V_1130 ;
F_105 ( V_156 , L_140 ,
V_1130 == V_1132 ? L_141 : L_142 ) ;
return 0 ;
}
static int F_604 ( struct V_54 * V_73 ,
struct V_1135 * V_1136 , T_2 V_139 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_1127 * V_1137 , * V_1138 ;
int V_1139 ;
if ( ! ( V_2 -> V_139 & V_408 ) )
return - V_1140 ;
V_1138 = F_605 ( V_1136 , sizeof( struct V_1141 ) , V_1142 ) ;
if ( ! V_1138 )
return - V_556 ;
F_606 (attr, br_spec, rem) {
int V_165 ;
T_19 V_1130 ;
if ( F_607 ( V_1137 ) != V_1143 )
continue;
if ( F_608 ( V_1137 ) < sizeof( V_1130 ) )
return - V_556 ;
V_1130 = F_609 ( V_1137 ) ;
V_165 = F_603 ( V_2 , V_1130 ) ;
if ( V_165 )
return V_165 ;
break;
}
return 0 ;
}
static int F_610 ( struct V_195 * V_89 , T_1 V_1144 , T_1 V_1145 ,
struct V_54 * V_73 ,
T_1 V_1146 , int V_1147 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
if ( ! ( V_2 -> V_139 & V_408 ) )
return 0 ;
return F_611 ( V_89 , V_1144 , V_1145 , V_73 ,
V_2 -> V_485 , 0 , 0 , V_1147 ,
V_1146 , NULL ) ;
}
static void * F_612 ( struct V_54 * V_9 , struct V_54 * V_622 )
{
struct V_618 * V_1051 = NULL ;
struct V_1 * V_2 = F_89 ( V_9 ) ;
int V_1148 = V_2 -> V_302 + V_2 -> V_629 ;
unsigned int V_697 ;
int V_470 , V_17 ;
if ( V_1148 >= V_1149 )
return F_613 ( - V_556 ) ;
#ifdef F_614
if ( V_622 -> V_93 != V_622 -> V_77 ) {
F_597 ( V_9 , L_143 ,
V_622 -> V_53 ) ;
return F_613 ( - V_556 ) ;
}
#endif
if ( V_622 -> V_77 > V_754 ||
V_622 -> V_77 == V_1150 ) {
F_597 ( V_9 ,
L_144 ,
V_9 -> V_53 ) ;
return F_613 ( - V_556 ) ;
}
if ( ( ( V_2 -> V_139 & V_140 ) &&
V_2 -> V_629 > V_1112 - 1 ) ||
( V_2 -> V_629 > V_1151 ) )
return F_613 ( - V_751 ) ;
V_1051 = F_615 ( 1 , sizeof( struct V_618 ) , V_745 ) ;
if ( ! V_1051 )
return F_613 ( - V_545 ) ;
V_470 = F_589 ( & V_2 -> V_628 , 32 ) ;
V_2 -> V_629 ++ ;
F_250 ( V_470 , & V_2 -> V_628 ) ;
V_697 = F_616 ( & V_2 -> V_628 , 32 ) ;
V_2 -> V_139 |= V_577 | V_408 ;
V_2 -> V_413 [ V_490 ] . V_697 = V_697 + 1 ;
V_2 -> V_413 [ V_414 ] . V_697 = V_622 -> V_77 ;
V_17 = F_588 ( V_9 , F_254 ( V_9 ) ) ;
if ( V_17 )
goto V_1152;
V_1051 -> V_470 = V_470 ;
V_1051 -> V_148 = V_2 ;
V_17 = F_357 ( V_622 , V_1051 ) ;
if ( V_17 )
goto V_1152;
F_617 ( V_622 ) ;
return V_1051 ;
V_1152:
F_597 ( V_9 ,
L_145 , V_622 -> V_53 ) ;
F_34 ( V_470 , & V_2 -> V_628 ) ;
V_2 -> V_629 -- ;
F_241 ( V_1051 ) ;
return F_613 ( V_17 ) ;
}
static void F_618 ( struct V_54 * V_9 , void * V_1153 )
{
struct V_618 * V_1051 = V_1153 ;
struct V_1 * V_2 = V_1051 -> V_148 ;
unsigned int V_697 ;
F_34 ( V_1051 -> V_470 , & V_2 -> V_628 ) ;
V_2 -> V_629 -- ;
V_697 = F_616 ( & V_2 -> V_628 , 32 ) ;
V_2 -> V_413 [ V_490 ] . V_697 = V_697 + 1 ;
F_355 ( V_1051 -> V_55 , V_1051 ) ;
F_588 ( V_9 , F_254 ( V_9 ) ) ;
F_358 ( V_9 , L_90 ,
V_1051 -> V_470 , V_2 -> V_629 ,
V_1051 -> V_621 ,
V_1051 -> V_621 + V_2 -> V_620 ,
V_2 -> V_628 ) ;
F_241 ( V_1051 ) ;
}
static inline int F_619 ( struct V_1 * V_2 )
{
struct V_5 * V_384 , * V_9 = V_2 -> V_9 ;
int V_1154 = 0 ;
if ( F_8 ( & V_2 -> V_14 ) )
V_1154 = 4 ;
F_620 (entry, &adapter->pdev->bus->devices, bus_list) {
if ( V_384 -> V_945 )
continue;
if ( ( V_384 -> V_690 != V_9 -> V_690 ) ||
( V_384 -> V_190 != V_9 -> V_190 ) )
return - 1 ;
V_1154 ++ ;
}
return V_1154 ;
}
int F_621 ( struct V_1 * V_2 , T_2 V_21 ,
T_2 V_1155 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1156 = V_2 -> V_1157 & V_1158 ;
int V_1159 = 0 ;
switch ( V_21 ) {
case V_1160 :
switch ( V_1155 ) {
case V_1161 :
case V_1162 :
if ( V_14 -> V_10 . V_1163 != 0 )
break;
case V_1164 :
case V_1165 :
case V_1166 :
case V_1167 :
case V_1168 :
V_1159 = 1 ;
break;
}
break;
case V_1169 :
switch ( V_1155 ) {
case V_1170 :
V_1159 = 1 ;
break;
}
break;
case V_1171 :
if ( V_1155 != V_1172 )
V_1159 = 1 ;
break;
case V_1173 :
V_1159 = 1 ;
break;
case V_1174 :
case V_1175 :
case V_1176 :
case V_1177 :
case V_1178 :
case V_1179 :
if ( ( V_1156 == V_1180 ) ||
( ( V_1156 == V_1181 ) &&
( V_14 -> V_10 . V_1163 == 0 ) ) ) {
V_1159 = 1 ;
}
break;
}
return V_1159 ;
}
static void F_622 ( struct V_1 * V_2 )
{
#ifdef F_623
struct V_1182 * V_1183 = F_624 ( V_2 -> V_9 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
const unsigned char * V_550 ;
V_550 = F_625 ( V_1183 ) ;
if ( V_550 ) {
F_310 ( V_14 -> V_108 . V_1184 , V_550 ) ;
return;
}
#endif
#ifdef F_626
F_310 ( V_14 -> V_108 . V_1184 , V_1185 -> V_1186 ) ;
#endif
}
static int F_627 ( struct V_5 * V_9 , const struct V_1187 * V_1188 )
{
struct V_54 * V_55 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_14 ;
const struct V_1189 * V_1190 = V_1191 [ V_1188 -> V_1192 ] ;
int V_48 , V_17 , V_1193 , V_24 ;
unsigned int V_415 = V_1194 ;
T_4 V_1195 [ V_1196 ] ;
bool V_1197 = false ;
#ifdef F_175
T_2 V_1198 ;
#endif
T_1 V_1199 ;
if ( V_9 -> V_945 ) {
F_628 ( 1 , V_1200 L_146 ,
F_497 ( V_9 ) , V_9 -> V_690 , V_9 -> V_190 ) ;
return - V_556 ;
}
V_17 = F_440 ( V_9 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_629 ( & V_9 -> V_73 , F_249 ( 64 ) ) ) {
V_1193 = 1 ;
} else {
V_17 = F_629 ( & V_9 -> V_73 , F_249 ( 32 ) ) ;
if ( V_17 ) {
F_415 ( & V_9 -> V_73 ,
L_147 ) ;
goto V_1201;
}
V_1193 = 0 ;
}
V_17 = F_630 ( V_9 , F_631 ( V_9 ,
V_1202 ) , V_1203 ) ;
if ( V_17 ) {
F_415 ( & V_9 -> V_73 ,
L_148 , V_17 ) ;
goto V_1204;
}
F_632 ( V_9 ) ;
F_441 ( V_9 ) ;
F_439 ( V_9 ) ;
if ( V_1190 -> V_108 == V_109 ) {
#ifdef F_367
V_415 = 4 * V_602 ;
#else
V_415 = V_1205 ;
#endif
}
V_55 = F_633 ( sizeof( struct V_1 ) , V_415 ) ;
if ( ! V_55 ) {
V_17 = - V_545 ;
goto V_1206;
}
F_634 ( V_55 , & V_9 -> V_73 ) ;
V_2 = F_89 ( V_55 ) ;
V_2 -> V_55 = V_55 ;
V_2 -> V_9 = V_9 ;
V_14 = & V_2 -> V_14 ;
V_14 -> V_38 = V_2 ;
V_2 -> V_1207 = F_635 ( V_1208 , V_1209 ) ;
V_14 -> V_39 = F_636 ( F_637 ( V_9 , 0 ) ,
F_638 ( V_9 , 0 ) ) ;
V_2 -> V_397 = V_14 -> V_39 ;
if ( ! V_14 -> V_39 ) {
V_17 = - V_741 ;
goto V_1210;
}
V_55 -> V_1211 = & V_1212 ;
F_639 ( V_55 ) ;
V_55 -> V_1213 = 5 * V_960 ;
F_640 ( V_55 -> V_53 , F_497 ( V_9 ) , sizeof( V_55 -> V_53 ) ) ;
memcpy ( & V_14 -> V_108 . V_335 , V_1190 -> V_1214 , sizeof( V_14 -> V_108 . V_335 ) ) ;
V_14 -> V_108 . type = V_1190 -> V_108 ;
V_14 -> V_1215 = V_1190 -> V_1215 ;
memcpy ( & V_14 -> V_1216 . V_335 , V_1190 -> V_1217 , sizeof( V_14 -> V_1216 . V_335 ) ) ;
V_1199 = F_37 ( V_14 , F_641 ( V_14 ) ) ;
if ( F_22 ( V_14 -> V_39 ) ) {
V_17 = - V_741 ;
goto V_1210;
}
if ( ! ( V_1199 & ( 1 << 8 ) ) )
V_14 -> V_1216 . V_335 . V_233 = & V_1218 ;
memcpy ( & V_14 -> V_338 . V_335 , V_1190 -> V_1219 , sizeof( V_14 -> V_338 . V_335 ) ) ;
V_14 -> V_338 . V_956 = V_1220 ;
V_14 -> V_338 . V_1089 . V_1086 = V_1221 ;
V_14 -> V_338 . V_1089 . V_1222 = 0 ;
V_14 -> V_338 . V_1089 . V_1223 = V_1224 | V_1225 ;
V_14 -> V_338 . V_1089 . V_73 = V_55 ;
V_14 -> V_338 . V_1089 . V_1226 = F_567 ;
V_14 -> V_338 . V_1089 . V_1227 = F_568 ;
V_1190 -> V_1228 ( V_14 ) ;
V_17 = F_399 ( V_2 ) ;
if ( V_17 )
goto V_1229;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_71 ( & V_2 -> V_14 , V_758 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_139 & V_342 ) {
T_1 V_663 = F_37 ( V_14 , V_664 ) ;
if ( V_663 & V_665 )
F_208 ( V_172 , L_71 ) ;
}
if ( V_1230 )
V_14 -> V_1230 = V_1230 ;
V_14 -> V_338 . V_1231 = true ;
V_17 = V_14 -> V_108 . V_335 . V_1232 ( V_14 ) ;
V_14 -> V_338 . V_1231 = false ;
if ( V_17 == V_672 &&
V_14 -> V_108 . type == V_109 ) {
V_17 = 0 ;
} else if ( V_17 == V_673 ) {
F_18 ( L_149 ) ;
F_18 ( L_150 ) ;
goto V_1229;
} else if ( V_17 ) {
F_18 ( L_151 , V_17 ) ;
goto V_1229;
}
#ifdef F_299
if ( V_2 -> V_14 . V_108 . type == V_109 )
goto V_1233;
F_642 ( V_14 ) ;
memcpy ( & V_14 -> V_1234 . V_335 , V_1190 -> V_1235 , sizeof( V_14 -> V_1234 . V_335 ) ) ;
F_643 ( V_9 , V_733 ) ;
F_644 ( V_2 ) ;
V_1233:
#endif
V_55 -> V_196 = V_1236 |
V_1237 |
V_1238 |
V_1239 |
V_244 |
V_1240 |
V_1241 |
V_197 |
V_211 ;
V_55 -> V_1242 = V_55 -> V_196 | V_1243 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_55 -> V_196 |= V_1244 ;
V_55 -> V_1242 |= V_1244 |
V_1119 ;
break;
default:
break;
}
V_55 -> V_1242 |= V_269 ;
V_55 -> V_196 |= V_1245 ;
V_55 -> V_1246 |= V_1240 ;
V_55 -> V_1246 |= V_1241 ;
V_55 -> V_1246 |= V_1237 ;
V_55 -> V_1246 |= V_1238 ;
V_55 -> V_1246 |= V_1236 ;
V_55 -> V_1247 |= V_1248 ;
V_55 -> V_1247 |= V_1249 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_113 :
case V_114 :
V_55 -> V_1250 |= V_211 ;
break;
default:
break;
}
#ifdef F_367
V_55 -> V_1251 = & V_1251 ;
#endif
#ifdef F_175
if ( V_2 -> V_139 & V_704 ) {
unsigned int V_1252 ;
if ( V_14 -> V_108 . V_335 . V_1253 ) {
V_14 -> V_108 . V_335 . V_1253 ( V_14 , & V_1198 ) ;
if ( V_1198 & V_1254 )
V_2 -> V_139 &= ~ V_704 ;
}
V_1252 = F_359 ( int , V_1255 , F_401 () ) ;
V_2 -> V_413 [ V_1057 ] . V_697 = V_1252 ;
V_55 -> V_196 |= V_1078 |
V_1079 ;
V_55 -> V_1246 |= V_1078 |
V_1079 |
V_582 ;
}
#endif
if ( V_1193 ) {
V_55 -> V_196 |= V_1256 ;
V_55 -> V_1246 |= V_1256 ;
}
if ( V_2 -> V_154 & V_698 )
V_55 -> V_1242 |= V_1115 ;
if ( V_2 -> V_154 & V_519 )
V_55 -> V_196 |= V_1115 ;
if ( V_14 -> V_1216 . V_335 . V_1257 ( V_14 , NULL ) < 0 ) {
F_18 ( L_152 ) ;
V_17 = - V_741 ;
goto V_1229;
}
F_622 ( V_2 ) ;
memcpy ( V_55 -> V_631 , V_14 -> V_108 . V_1184 , V_55 -> V_676 ) ;
if ( ! F_362 ( V_55 -> V_631 ) ) {
F_18 ( L_153 ) ;
V_17 = - V_741 ;
goto V_1229;
}
F_307 ( V_2 , V_14 -> V_108 . V_1184 ) ;
F_645 ( & V_2 -> V_666 , & F_507 ,
( unsigned long ) V_2 ) ;
if ( F_22 ( V_14 -> V_39 ) ) {
V_17 = - V_741 ;
goto V_1229;
}
F_646 ( & V_2 -> V_37 , F_511 ) ;
F_250 ( V_40 , & V_2 -> V_34 ) ;
F_34 ( V_36 , & V_2 -> V_34 ) ;
V_17 = F_444 ( V_2 ) ;
if ( V_17 )
goto V_1229;
V_2 -> V_680 = 0 ;
V_14 -> V_1216 . V_335 . V_233 ( V_14 , 0x2c , & V_2 -> V_1157 ) ;
V_14 -> V_1258 = F_621 ( V_2 , V_9 -> V_190 ,
V_9 -> V_696 ) ;
if ( V_14 -> V_1258 )
V_2 -> V_680 = V_1259 ;
F_647 ( & V_2 -> V_9 -> V_73 , V_2 -> V_680 ) ;
V_14 -> V_1216 . V_335 . V_233 ( V_14 , 0x2e , & V_2 -> V_1260 ) ;
V_14 -> V_1216 . V_335 . V_233 ( V_14 , 0x2d , & V_2 -> V_1261 ) ;
V_14 -> V_108 . V_335 . V_1262 ( V_14 ) ;
if ( F_8 ( V_14 ) )
F_5 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_24 = F_648 ( F_619 ( V_2 ) * 10 , 16 ) ;
break;
default:
V_24 = F_619 ( V_2 ) * 10 ;
break;
}
if ( V_24 > 0 )
F_9 ( V_2 , V_24 ) ;
V_17 = F_649 ( V_14 , V_1195 , sizeof( V_1195 ) ) ;
if ( V_17 )
F_640 ( V_1195 , L_7 , sizeof( V_1195 ) ) ;
if ( F_212 ( V_14 ) && V_14 -> V_338 . V_956 != V_1263 )
F_12 ( L_154 ,
V_14 -> V_108 . type , V_14 -> V_338 . type , V_14 -> V_338 . V_956 ,
V_1195 ) ;
else
F_12 ( L_155 ,
V_14 -> V_108 . type , V_14 -> V_338 . type , V_1195 ) ;
F_12 ( L_156 , V_55 -> V_631 ) ;
V_17 = V_14 -> V_108 . V_335 . V_1264 ( V_14 ) ;
if ( V_17 == V_675 ) {
F_11 ( L_93
L_157
L_158
L_159
L_97
L_98 ) ;
}
strcpy ( V_55 -> V_53 , L_160 ) ;
V_17 = F_650 ( V_55 ) ;
if ( V_17 )
goto V_1265;
F_651 ( V_9 , V_2 ) ;
if ( V_14 -> V_108 . V_335 . V_685 )
V_14 -> V_108 . V_335 . V_685 ( V_14 ) ;
F_392 ( V_55 ) ;
#ifdef F_232
if ( F_126 ( & V_9 -> V_73 ) == 0 ) {
V_2 -> V_139 |= V_187 ;
F_123 ( V_2 ) ;
}
#endif
if ( V_2 -> V_139 & V_408 ) {
F_105 ( V_172 , L_161 , V_2 -> V_302 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_302 ; V_48 ++ )
F_652 ( V_9 , ( V_48 | 0x10000000 ) ) ;
}
if ( V_14 -> V_108 . V_335 . V_1266 )
V_14 -> V_108 . V_335 . V_1266 ( V_14 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_574 ( V_55 ) ;
F_12 ( L_70 , V_1267 ) ;
#ifdef F_653
if ( F_654 ( V_2 ) )
F_103 ( V_172 , L_162 ) ;
#endif
F_655 ( V_2 ) ;
if ( F_656 ( V_14 ) && F_212 ( V_14 ) && V_14 -> V_108 . V_335 . V_645 )
V_14 -> V_108 . V_335 . V_645 ( V_14 ,
V_906 | V_929 ,
true ) ;
return 0 ;
V_1265:
F_70 ( V_2 ) ;
F_450 ( V_2 ) ;
V_1229:
F_657 ( V_2 ) ;
V_2 -> V_154 &= ~ V_639 ;
F_658 ( V_2 -> V_397 ) ;
F_241 ( V_2 -> V_547 ) ;
V_1210:
V_1197 = ! F_15 ( V_757 , & V_2 -> V_34 ) ;
F_659 ( V_55 ) ;
V_1206:
F_660 ( V_9 ,
F_631 ( V_9 , V_1202 ) ) ;
V_1204:
V_1201:
if ( ! V_2 || V_1197 )
F_451 ( V_9 ) ;
return V_17 ;
}
static void F_661 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_436 ( V_9 ) ;
struct V_54 * V_55 ;
bool V_1197 ;
if ( ! V_2 )
return;
V_55 = V_2 -> V_55 ;
F_662 ( V_2 ) ;
F_250 ( V_35 , & V_2 -> V_34 ) ;
F_663 ( & V_2 -> V_37 ) ;
#ifdef F_232
if ( V_2 -> V_139 & V_187 ) {
V_2 -> V_139 &= ~ V_187 ;
F_127 ( & V_9 -> V_73 ) ;
F_71 ( & V_2 -> V_14 , V_188 , 1 ) ;
}
#endif
#ifdef F_653
F_664 ( V_2 ) ;
#endif
F_576 ( V_55 ) ;
if ( V_55 -> V_957 == V_958 )
F_505 ( V_55 ) ;
#ifdef F_299
if ( V_732 )
F_657 ( V_2 ) ;
#endif
F_450 ( V_2 ) ;
F_70 ( V_2 ) ;
#ifdef F_665
F_241 ( V_2 -> V_138 ) ;
F_241 ( V_2 -> V_587 ) ;
#endif
F_658 ( V_2 -> V_397 ) ;
F_660 ( V_9 , F_631 ( V_9 ,
V_1202 ) ) ;
F_12 ( L_163 ) ;
F_241 ( V_2 -> V_547 ) ;
V_1197 = ! F_15 ( V_757 , & V_2 -> V_34 ) ;
F_659 ( V_55 ) ;
F_666 ( V_9 ) ;
if ( V_1197 )
F_451 ( V_9 ) ;
}
static T_20 F_667 ( struct V_5 * V_9 ,
T_21 V_34 )
{
struct V_1 * V_2 = F_436 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
#ifdef F_299
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_1268 , * V_936 ;
T_1 V_1269 , V_1270 , V_1271 , V_1272 ;
int V_1273 , V_940 ;
T_2 V_1274 , V_1275 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ||
V_2 -> V_302 == 0 )
goto V_1276;
V_1268 = V_9 -> V_10 -> V_12 ;
while ( V_1268 && ( F_668 ( V_1268 ) != V_1277 ) )
V_1268 = V_1268 -> V_10 -> V_12 ;
if ( ! V_1268 )
goto V_1276;
V_940 = F_500 ( V_1268 , V_1278 ) ;
if ( ! V_940 )
goto V_1276;
V_1269 = F_27 ( V_14 , V_940 + V_1279 ) ;
V_1270 = F_27 ( V_14 , V_940 + V_1279 + 4 ) ;
V_1271 = F_27 ( V_14 , V_940 + V_1279 + 8 ) ;
V_1272 = F_27 ( V_14 , V_940 + V_1279 + 12 ) ;
if ( F_22 ( V_14 -> V_39 ) )
goto V_1276;
V_1274 = V_1270 >> 16 ;
if ( ! ( V_1274 & 0x0080 ) )
goto V_1276;
V_1275 = V_1274 & 0x01 ;
if ( ( V_1275 & 1 ) == ( V_9 -> V_1280 & 1 ) ) {
unsigned int V_21 ;
V_1273 = ( V_1274 & 0x7F ) >> 1 ;
F_18 ( L_164 , V_1273 ) ;
F_18 ( L_165
L_166 ,
V_1269 , V_1270 , V_1271 , V_1272 ) ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_21 = V_1281 ;
break;
case V_112 :
V_21 = V_1282 ;
break;
case V_113 :
V_21 = V_1283 ;
break;
case V_114 :
V_21 = V_1284 ;
break;
default:
V_21 = 0 ;
break;
}
V_936 = F_501 ( V_1285 , V_21 , NULL ) ;
while ( V_936 ) {
if ( V_936 -> V_1280 == ( V_1274 & 0xFF ) )
break;
V_936 = F_501 ( V_1285 ,
V_21 , V_936 ) ;
}
if ( V_936 ) {
F_495 ( V_2 , V_936 ) ;
F_669 ( V_936 ) ;
}
F_670 ( V_9 ) ;
}
V_2 -> V_1286 ++ ;
return V_1287 ;
V_1276:
#endif
if ( ! F_14 ( V_40 , & V_2 -> V_34 ) )
return V_1288 ;
F_443 () ;
F_449 ( V_55 ) ;
if ( V_34 == V_1289 ) {
F_445 () ;
return V_1288 ;
}
if ( F_57 ( V_55 ) )
F_381 ( V_2 ) ;
if ( ! F_15 ( V_757 , & V_2 -> V_34 ) )
F_451 ( V_9 ) ;
F_445 () ;
return V_1290 ;
}
static T_20 F_671 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_436 ( V_9 ) ;
T_20 V_1291 ;
int V_17 ;
if ( F_440 ( V_9 ) ) {
F_103 ( V_172 , L_167 ) ;
V_1291 = V_1288 ;
} else {
F_33 () ;
F_34 ( V_757 , & V_2 -> V_34 ) ;
V_2 -> V_14 . V_39 = V_2 -> V_397 ;
F_441 ( V_9 ) ;
F_438 ( V_9 ) ;
F_439 ( V_9 ) ;
F_442 ( V_9 , false ) ;
F_384 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_758 , ~ 0 ) ;
V_1291 = V_1287 ;
}
V_17 = F_670 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_168
L_169 , V_17 ) ;
}
return V_1291 ;
}
static void F_672 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_436 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
#ifdef F_299
if ( V_2 -> V_1286 ) {
F_105 ( V_156 , L_170 ) ;
V_2 -> V_1286 -- ;
return;
}
#endif
if ( F_57 ( V_55 ) )
F_383 ( V_2 ) ;
F_446 ( V_55 ) ;
}
static int T_22 F_673 ( void )
{
int V_641 ;
F_51 ( L_171 , V_1292 , V_1293 ) ;
F_51 ( L_70 , V_1294 ) ;
F_674 () ;
V_641 = F_675 ( & V_1295 ) ;
if ( V_641 ) {
F_676 () ;
return V_641 ;
}
#ifdef F_232
F_677 ( & V_1296 ) ;
#endif
return 0 ;
}
static void T_23 F_678 ( void )
{
#ifdef F_232
F_679 ( & V_1296 ) ;
#endif
F_680 ( & V_1295 ) ;
F_676 () ;
}
static int F_681 ( struct V_1297 * V_1298 , unsigned long V_191 ,
void * V_1082 )
{
int V_1299 ;
V_1299 = F_682 ( & V_1295 . V_1300 , NULL , & V_191 ,
F_124 ) ;
return V_1299 ? V_1301 : V_1302 ;
}
