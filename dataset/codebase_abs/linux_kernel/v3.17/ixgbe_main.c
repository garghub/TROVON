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
if ( V_103 == - 1 ) {
V_105 |= V_110 ;
V_107 = ( ( V_104 & 1 ) * 8 ) ;
V_106 = F_37 ( & V_2 -> V_14 , V_113 ) ;
V_106 &= ~ ( 0xFF << V_107 ) ;
V_106 |= ( V_105 << V_107 ) ;
F_71 ( & V_2 -> V_14 , V_113 , V_106 ) ;
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
T_6 V_114 )
{
T_1 V_115 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
V_115 = ( V_116 & V_114 ) ;
F_71 ( & V_2 -> V_14 , V_117 , V_115 ) ;
break;
case V_111 :
case V_112 :
V_115 = ( V_114 & 0xFFFFFFFF ) ;
F_71 ( & V_2 -> V_14 , F_76 ( 0 ) , V_115 ) ;
V_115 = ( V_114 >> 32 ) ;
F_71 ( & V_2 -> V_14 , F_76 ( 1 ) , V_115 ) ;
break;
default:
break;
}
}
void F_77 ( struct V_57 * V_118 ,
struct V_59 * V_60 )
{
if ( V_60 -> V_89 ) {
F_78 ( V_60 -> V_89 ) ;
if ( F_59 ( V_60 , V_82 ) )
F_79 ( V_118 -> V_73 ,
F_58 ( V_60 , V_81 ) ,
F_59 ( V_60 , V_82 ) ,
V_119 ) ;
} else if ( F_59 ( V_60 , V_82 ) ) {
F_80 ( V_118 -> V_73 ,
F_58 ( V_60 , V_81 ) ,
F_59 ( V_60 , V_82 ) ,
V_119 ) ;
}
V_60 -> V_83 = NULL ;
V_60 -> V_89 = NULL ;
F_81 ( V_60 , V_82 , 0 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_120 * V_121 = & V_2 -> V_122 ;
int V_48 ;
T_1 V_92 ;
if ( ( V_14 -> V_123 . V_124 != V_125 ) &&
( V_14 -> V_123 . V_124 != V_126 ) )
return;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_92 = F_37 ( V_14 , V_127 ) ;
break;
default:
V_92 = F_37 ( V_14 , V_128 ) ;
}
V_121 -> V_129 += V_92 ;
if ( ! V_92 )
return;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_34 ( V_130 ,
& V_2 -> V_58 [ V_48 ] -> V_34 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_120 * V_121 = & V_2 -> V_122 ;
T_1 V_131 [ 8 ] = { 0 } ;
T_4 V_132 ;
int V_48 ;
bool V_133 = V_2 -> V_134 . V_135 ;
if ( V_2 -> V_136 )
V_133 |= ! ! ( V_2 -> V_136 -> V_133 ) ;
if ( ! ( V_2 -> V_137 & V_138 ) || ! V_133 ) {
F_82 ( V_2 ) ;
return;
}
for ( V_48 = 0 ; V_48 < V_139 ; V_48 ++ ) {
T_1 V_140 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_140 = F_37 ( V_14 , F_84 ( V_48 ) ) ;
break;
default:
V_140 = F_37 ( V_14 , F_85 ( V_48 ) ) ;
}
V_121 -> V_140 [ V_48 ] += V_140 ;
V_132 = F_86 ( V_2 -> V_55 , V_48 ) ;
V_131 [ V_132 ] += V_140 ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_58 = V_2 -> V_58 [ V_48 ] ;
V_132 = V_58 -> V_141 ;
if ( V_131 [ V_132 ] )
F_34 ( V_130 , & V_58 -> V_34 ) ;
}
}
static T_6 F_87 ( struct V_57 * V_118 )
{
return V_118 -> V_122 . V_142 ;
}
static T_6 F_88 ( struct V_57 * V_118 )
{
struct V_1 * V_2 ;
struct V_15 * V_14 ;
T_1 V_143 , V_144 ;
if ( V_118 -> V_145 )
V_2 = V_118 -> V_145 -> V_146 ;
else
V_2 = F_89 ( V_118 -> V_55 ) ;
V_14 = & V_2 -> V_14 ;
V_143 = F_37 ( V_14 , F_48 ( V_118 -> V_147 ) ) ;
V_144 = F_37 ( V_14 , F_49 ( V_118 -> V_147 ) ) ;
if ( V_143 != V_144 )
return ( V_143 < V_144 ) ?
V_144 - V_143 : ( V_144 + V_118 -> V_88 - V_143 ) ;
return 0 ;
}
static inline bool F_90 ( struct V_57 * V_58 )
{
T_1 V_148 = F_87 ( V_58 ) ;
T_1 V_149 = V_58 -> V_150 . V_149 ;
T_1 V_151 = F_88 ( V_58 ) ;
F_91 ( V_58 ) ;
if ( V_149 == V_148 && V_151 )
return F_15 ( V_130 ,
& V_58 -> V_34 ) ;
V_58 -> V_150 . V_149 = V_148 ;
F_34 ( V_130 , & V_58 -> V_34 ) ;
return false ;
}
static void F_92 ( struct V_1 * V_2 )
{
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_152 |= V_153 ;
F_93 ( V_154 , L_60 ) ;
F_13 ( V_2 ) ;
}
}
static bool F_94 ( struct V_155 * V_156 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = V_156 -> V_2 ;
struct V_59 * V_60 ;
union V_61 * V_62 ;
unsigned int V_157 = 0 , V_158 = 0 ;
unsigned int V_159 = V_156 -> V_160 . V_161 ;
unsigned int V_48 = V_58 -> V_79 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return true ;
V_60 = & V_58 -> V_78 [ V_48 ] ;
V_62 = F_61 ( V_58 , V_48 ) ;
V_48 -= V_58 -> V_88 ;
do {
union V_61 * V_162 = V_60 -> V_83 ;
if ( ! V_162 )
break;
F_95 () ;
if ( ! ( V_162 -> V_94 . V_163 & F_96 ( V_164 ) ) )
break;
V_60 -> V_83 = NULL ;
V_157 += V_60 -> V_165 ;
V_158 += V_60 -> V_166 ;
F_78 ( V_60 -> V_89 ) ;
F_79 ( V_58 -> V_73 ,
F_58 ( V_60 , V_81 ) ,
F_59 ( V_60 , V_82 ) ,
V_119 ) ;
V_60 -> V_89 = NULL ;
F_81 ( V_60 , V_82 , 0 ) ;
while ( V_62 != V_162 ) {
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
V_119 ) ;
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
F_97 ( V_62 ) ;
V_159 -- ;
} while ( F_98 ( V_159 ) );
V_48 += V_58 -> V_88 ;
V_58 -> V_79 = V_48 ;
F_99 ( & V_58 -> V_167 ) ;
V_58 -> V_122 . V_168 += V_157 ;
V_58 -> V_122 . V_142 += V_158 ;
F_100 ( & V_58 -> V_167 ) ;
V_156 -> V_160 . V_157 += V_157 ;
V_156 -> V_160 . V_158 += V_158 ;
if ( F_101 ( V_58 ) && F_90 ( V_58 ) ) {
struct V_15 * V_14 = & V_2 -> V_14 ;
F_102 ( V_154 , L_61
L_62
L_63
L_64
L_65
L_66
L_67
L_68 ,
V_58 -> V_86 ,
F_37 ( V_14 , F_48 ( V_58 -> V_147 ) ) ,
F_37 ( V_14 , F_49 ( V_58 -> V_147 ) ) ,
V_58 -> V_80 , V_48 ,
V_58 -> V_78 [ V_48 ] . V_84 , V_169 ) ;
F_103 ( V_58 -> V_55 , V_58 -> V_86 ) ;
F_104 ( V_170 ,
L_69 ,
V_2 -> V_171 + 1 , V_58 -> V_86 ) ;
F_92 ( V_2 ) ;
return true ;
}
F_105 ( F_106 ( V_58 ) ,
V_158 , V_157 ) ;
#define F_107 (DESC_NEEDED * 2)
if ( F_24 ( V_158 && F_108 ( V_58 -> V_55 ) &&
( F_109 ( V_58 ) >= F_107 ) ) ) {
F_110 () ;
if ( F_111 ( V_58 -> V_55 ,
V_58 -> V_86 )
&& ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
F_112 ( V_58 -> V_55 ,
V_58 -> V_86 ) ;
++ V_58 -> V_150 . V_172 ;
}
}
return ! ! V_159 ;
}
static void F_113 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
int V_173 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_174 = F_114 ( V_58 -> V_73 , V_173 ) ;
T_2 V_175 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_175 = F_115 ( V_58 -> V_147 ) ;
break;
case V_111 :
case V_112 :
V_175 = F_116 ( V_58 -> V_147 ) ;
V_174 <<= V_176 ;
break;
default:
return;
}
V_174 |= V_177 |
V_178 |
V_179 ;
F_71 ( V_14 , V_175 , V_174 ) ;
}
static void F_117 ( struct V_1 * V_2 ,
struct V_57 * V_67 ,
int V_173 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_180 = F_114 ( V_67 -> V_73 , V_173 ) ;
T_4 V_147 = V_67 -> V_147 ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
V_180 <<= V_181 ;
break;
default:
break;
}
V_180 |= V_182 |
V_183 ;
F_71 ( V_14 , F_38 ( V_147 ) , V_180 ) ;
}
static void F_118 ( struct V_155 * V_156 )
{
struct V_1 * V_2 = V_156 -> V_2 ;
struct V_57 * V_118 ;
int V_173 = F_119 () ;
if ( V_156 -> V_173 == V_173 )
goto V_184;
F_120 (ring, q_vector->tx)
F_113 ( V_2 , V_118 , V_173 ) ;
F_120 (ring, q_vector->rx)
F_117 ( V_2 , V_118 , V_173 ) ;
V_156 -> V_173 = V_173 ;
V_184:
F_121 () ;
}
static void F_122 ( struct V_1 * V_2 )
{
int V_48 ;
if ( ! ( V_2 -> V_137 & V_185 ) )
return;
F_71 ( & V_2 -> V_14 , V_186 , 2 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_187 ; V_48 ++ ) {
V_2 -> V_156 [ V_48 ] -> V_173 = - 1 ;
F_118 ( V_2 -> V_156 [ V_48 ] ) ;
}
}
static int F_123 ( struct V_188 * V_73 , void * V_92 )
{
struct V_1 * V_2 = F_124 ( V_73 ) ;
unsigned long V_189 = * ( unsigned long * ) V_92 ;
if ( ! ( V_2 -> V_137 & V_190 ) )
return 0 ;
switch ( V_189 ) {
case V_191 :
if ( V_2 -> V_137 & V_185 )
break;
if ( F_125 ( V_73 ) == 0 ) {
V_2 -> V_137 |= V_185 ;
F_122 ( V_2 ) ;
break;
}
case V_192 :
if ( V_2 -> V_137 & V_185 ) {
F_126 ( V_73 ) ;
V_2 -> V_137 &= ~ V_185 ;
F_71 ( & V_2 -> V_14 , V_186 , 1 ) ;
}
break;
}
return 0 ;
}
static inline void F_127 ( struct V_57 * V_118 ,
union V_68 * V_69 ,
struct V_193 * V_89 )
{
if ( V_118 -> V_55 -> V_194 & V_195 )
F_128 ( V_89 ,
F_67 ( V_69 -> V_94 . V_196 . V_197 . V_198 ) ,
V_199 ) ;
}
static inline bool F_129 ( struct V_57 * V_118 ,
union V_68 * V_69 )
{
T_8 V_200 = V_69 -> V_94 . V_196 . V_201 . V_202 . V_200 ;
return F_14 ( V_203 , & V_118 -> V_34 ) &&
( ( V_200 & F_130 ( V_204 ) ) ==
( F_130 ( V_205 <<
V_206 ) ) ) ;
}
static inline void F_131 ( struct V_57 * V_118 ,
union V_68 * V_69 ,
struct V_193 * V_89 )
{
F_132 ( V_89 ) ;
if ( ! ( V_118 -> V_55 -> V_194 & V_207 ) )
return;
if ( F_133 ( V_69 , V_208 ) &&
F_133 ( V_69 , V_209 ) ) {
V_118 -> V_210 . V_211 ++ ;
return;
}
if ( ! F_133 ( V_69 , V_212 ) )
return;
if ( F_133 ( V_69 , V_213 ) ) {
T_8 V_200 = V_69 -> V_94 . V_196 . V_201 . V_202 . V_200 ;
if ( ( V_200 & F_130 ( V_214 ) ) &&
F_14 ( V_215 , & V_118 -> V_34 ) )
return;
V_118 -> V_210 . V_211 ++ ;
return;
}
V_89 -> V_216 = V_217 ;
}
static inline void F_134 ( struct V_57 * V_67 , T_1 V_218 )
{
V_67 -> V_80 = V_218 ;
V_67 -> V_219 = V_218 ;
F_135 () ;
F_136 ( V_67 , V_218 ) ;
}
static bool F_137 ( struct V_57 * V_67 ,
struct V_70 * V_220 )
{
struct V_98 * V_98 = V_220 -> V_98 ;
T_9 V_81 = V_220 -> V_81 ;
if ( F_98 ( V_81 ) )
return true ;
if ( F_98 ( ! V_98 ) ) {
V_98 = F_138 ( V_221 | V_222 | V_223 ,
V_220 -> V_89 , F_139 ( V_67 ) ) ;
if ( F_24 ( ! V_98 ) ) {
V_67 -> V_210 . V_224 ++ ;
return false ;
}
V_220 -> V_98 = V_98 ;
}
V_81 = F_140 ( V_67 -> V_73 , V_98 , 0 ,
F_141 ( V_67 ) , V_225 ) ;
if ( F_142 ( V_67 -> V_73 , V_81 ) ) {
F_143 ( V_98 , F_139 ( V_67 ) ) ;
V_220 -> V_98 = NULL ;
V_67 -> V_210 . V_224 ++ ;
return false ;
}
V_220 -> V_81 = V_81 ;
V_220 -> V_99 = 0 ;
return true ;
}
void F_144 ( struct V_57 * V_67 , T_2 V_226 )
{
union V_68 * V_69 ;
struct V_70 * V_220 ;
T_2 V_48 = V_67 -> V_80 ;
if ( ! V_226 )
return;
V_69 = F_66 ( V_67 , V_48 ) ;
V_220 = & V_67 -> V_71 [ V_48 ] ;
V_48 -= V_67 -> V_88 ;
do {
if ( ! F_137 ( V_67 , V_220 ) )
break;
V_69 -> V_227 . V_228 = F_145 ( V_220 -> V_81 + V_220 -> V_99 ) ;
V_69 ++ ;
V_220 ++ ;
V_48 ++ ;
if ( F_24 ( ! V_48 ) ) {
V_69 = F_66 ( V_67 , 0 ) ;
V_220 = V_67 -> V_71 ;
V_48 -= V_67 -> V_88 ;
}
V_69 -> V_227 . V_229 = 0 ;
V_226 -- ;
} while ( V_226 );
V_48 += V_67 -> V_88 ;
if ( V_67 -> V_80 != V_48 )
F_134 ( V_67 , V_48 ) ;
}
static unsigned int F_146 ( unsigned char * V_92 ,
unsigned int V_230 )
{
union {
unsigned char * V_231 ;
struct V_232 * V_233 ;
struct V_234 * V_235 ;
struct V_236 * V_237 ;
struct V_238 * V_239 ;
} V_240 ;
T_10 V_241 ;
T_4 V_242 = 0 ;
T_4 V_243 ;
if ( V_230 < V_244 )
return V_230 ;
V_240 . V_231 = V_92 ;
V_241 = V_240 . V_233 -> V_245 ;
V_240 . V_231 += V_244 ;
if ( V_241 == F_147 ( V_246 ) ) {
if ( ( V_240 . V_231 - V_92 ) > ( V_230 - V_247 ) )
return V_230 ;
V_241 = V_240 . V_235 -> V_248 ;
V_240 . V_231 += V_247 ;
}
if ( V_241 == F_147 ( V_249 ) ) {
if ( ( V_240 . V_231 - V_92 ) > ( V_230 - sizeof( struct V_236 ) ) )
return V_230 ;
V_243 = ( V_240 . V_231 [ 0 ] & 0x0F ) << 2 ;
if ( V_243 < sizeof( struct V_236 ) )
return V_240 . V_231 - V_92 ;
if ( ! ( V_240 . V_237 -> V_250 & F_147 ( V_251 ) ) )
V_242 = V_240 . V_237 -> V_241 ;
} else if ( V_241 == F_147 ( V_252 ) ) {
if ( ( V_240 . V_231 - V_92 ) > ( V_230 - sizeof( struct V_238 ) ) )
return V_230 ;
V_242 = V_240 . V_239 -> V_242 ;
V_243 = sizeof( struct V_238 ) ;
#ifdef F_148
} else if ( V_241 == F_147 ( V_253 ) ) {
if ( ( V_240 . V_231 - V_92 ) > ( V_230 - V_254 ) )
return V_230 ;
V_243 = V_254 ;
#endif
} else {
return V_240 . V_231 - V_92 ;
}
V_240 . V_231 += V_243 ;
if ( V_242 == V_255 ) {
if ( ( V_240 . V_231 - V_92 ) > ( V_230 - sizeof( struct V_256 ) ) )
return V_230 ;
V_243 = ( V_240 . V_231 [ 12 ] & 0xF0 ) >> 2 ;
if ( V_243 < sizeof( struct V_256 ) )
return V_240 . V_231 - V_92 ;
V_240 . V_231 += V_243 ;
} else if ( V_242 == V_257 ) {
if ( ( V_240 . V_231 - V_92 ) > ( V_230 - sizeof( struct V_258 ) ) )
return V_230 ;
V_240 . V_231 += sizeof( struct V_258 ) ;
}
if ( ( V_240 . V_231 - V_92 ) < V_230 )
return V_240 . V_231 - V_92 ;
else
return V_230 ;
}
static void F_149 ( struct V_57 * V_118 ,
struct V_193 * V_89 )
{
T_2 V_259 = F_150 ( V_89 ) ;
F_151 ( V_89 ) -> V_260 = F_152 ( ( V_89 -> V_82 - V_259 ) ,
F_153 ( V_89 ) -> V_261 ) ;
F_151 ( V_89 ) -> V_262 = V_263 ;
}
static void F_154 ( struct V_57 * V_67 ,
struct V_193 * V_89 )
{
if ( ! F_153 ( V_89 ) -> V_261 )
return;
V_67 -> V_210 . V_264 += F_153 ( V_89 ) -> V_261 ;
V_67 -> V_210 . V_265 ++ ;
F_149 ( V_67 , V_89 ) ;
F_153 ( V_89 ) -> V_261 = 0 ;
}
static void F_155 ( struct V_57 * V_67 ,
union V_68 * V_69 ,
struct V_193 * V_89 )
{
struct V_54 * V_73 = V_67 -> V_55 ;
F_154 ( V_67 , V_89 ) ;
F_127 ( V_67 , V_69 , V_89 ) ;
F_131 ( V_67 , V_69 , V_89 ) ;
if ( F_24 ( F_133 ( V_69 , V_266 ) ) )
F_156 ( V_67 -> V_156 -> V_2 , V_89 ) ;
if ( ( V_73 -> V_194 & V_267 ) &&
F_133 ( V_69 , V_268 ) ) {
T_2 V_269 = F_157 ( V_69 -> V_94 . V_95 . V_235 ) ;
F_158 ( V_89 , F_147 ( V_246 ) , V_269 ) ;
}
F_159 ( V_89 , V_67 -> V_86 ) ;
V_89 -> V_241 = F_160 ( V_89 , V_73 ) ;
}
static void F_161 ( struct V_155 * V_156 ,
struct V_193 * V_89 )
{
struct V_1 * V_2 = V_156 -> V_2 ;
if ( F_162 ( V_156 ) )
F_163 ( V_89 ) ;
else if ( ! ( V_2 -> V_137 & V_270 ) )
F_164 ( & V_156 -> V_271 , V_89 ) ;
else
F_165 ( V_89 ) ;
}
static bool F_166 ( struct V_57 * V_67 ,
union V_68 * V_69 ,
struct V_193 * V_89 )
{
T_1 V_272 = V_67 -> V_79 + 1 ;
V_272 = ( V_272 < V_67 -> V_88 ) ? V_272 : 0 ;
V_67 -> V_79 = V_272 ;
F_97 ( F_66 ( V_67 , V_272 ) ) ;
if ( F_167 ( V_67 ) ) {
T_11 V_273 = V_69 -> V_94 . V_196 . V_201 . V_92 &
F_96 ( V_274 ) ;
if ( F_24 ( V_273 ) ) {
T_1 V_275 = F_67 ( V_273 ) ;
V_275 >>= V_276 ;
F_153 ( V_89 ) -> V_261 += V_275 - 1 ;
V_272 = F_67 ( V_69 -> V_94 . V_95 . V_96 ) ;
V_272 &= V_277 ;
V_272 >>= V_278 ;
}
}
if ( F_98 ( F_133 ( V_69 , V_279 ) ) )
return false ;
V_67 -> V_71 [ V_272 ] . V_89 = V_89 ;
V_67 -> V_210 . V_280 ++ ;
return true ;
}
static void F_168 ( struct V_57 * V_67 ,
struct V_193 * V_89 )
{
struct V_281 * V_282 = & F_151 ( V_89 ) -> V_283 [ 0 ] ;
unsigned char * V_284 ;
unsigned int V_285 ;
V_284 = F_169 ( V_282 ) ;
V_285 = F_146 ( V_284 , V_286 ) ;
F_170 ( V_89 , V_284 , F_171 ( V_285 , sizeof( long ) ) ) ;
F_172 ( V_282 , V_285 ) ;
V_282 -> V_99 += V_285 ;
V_89 -> V_287 -= V_285 ;
V_89 -> V_144 += V_285 ;
}
static void F_173 ( struct V_57 * V_67 ,
struct V_193 * V_89 )
{
if ( F_24 ( F_153 ( V_89 ) -> V_288 ) ) {
F_80 ( V_67 -> V_73 , F_153 ( V_89 ) -> V_81 ,
F_141 ( V_67 ) , V_225 ) ;
F_153 ( V_89 ) -> V_288 = false ;
} else {
struct V_281 * V_282 = & F_151 ( V_89 ) -> V_283 [ 0 ] ;
F_174 ( V_67 -> V_73 ,
F_153 ( V_89 ) -> V_81 ,
V_282 -> V_99 ,
F_69 ( V_67 ) ,
V_225 ) ;
}
F_153 ( V_89 ) -> V_81 = 0 ;
}
static bool F_175 ( struct V_57 * V_67 ,
union V_68 * V_69 ,
struct V_193 * V_89 )
{
struct V_54 * V_55 = V_67 -> V_55 ;
if ( F_24 ( F_133 ( V_69 ,
V_289 ) &&
! ( V_55 -> V_194 & V_290 ) ) ) {
F_78 ( V_89 ) ;
return true ;
}
if ( F_176 ( V_89 ) )
F_168 ( V_67 , V_89 ) ;
#ifdef F_148
if ( F_129 ( V_67 , V_69 ) )
return false ;
#endif
if ( F_24 ( V_89 -> V_82 < 60 ) ) {
int V_291 = 60 - V_89 -> V_82 ;
if ( F_177 ( V_89 , V_291 ) )
return true ;
F_178 ( V_89 , V_291 ) ;
}
return false ;
}
static void F_179 ( struct V_57 * V_67 ,
struct V_70 * V_292 )
{
struct V_70 * V_293 ;
T_2 V_294 = V_67 -> V_219 ;
V_293 = & V_67 -> V_71 [ V_294 ] ;
V_294 ++ ;
V_67 -> V_219 = ( V_294 < V_67 -> V_88 ) ? V_294 : 0 ;
V_293 -> V_98 = V_292 -> V_98 ;
V_293 -> V_81 = V_292 -> V_81 ;
V_293 -> V_99 = V_292 -> V_99 ;
F_180 ( V_67 -> V_73 , V_293 -> V_81 ,
V_293 -> V_99 ,
F_69 ( V_67 ) ,
V_225 ) ;
}
static bool F_181 ( struct V_57 * V_67 ,
struct V_70 * V_295 ,
union V_68 * V_69 ,
struct V_193 * V_89 )
{
struct V_98 * V_98 = V_295 -> V_98 ;
unsigned int V_296 = F_157 ( V_69 -> V_94 . V_95 . V_297 ) ;
#if ( V_298 < 8192 )
unsigned int V_299 = F_69 ( V_67 ) ;
#else
unsigned int V_299 = F_171 ( V_296 , V_300 ) ;
unsigned int V_301 = F_141 ( V_67 ) -
F_69 ( V_67 ) ;
#endif
if ( ( V_296 <= V_286 ) && ! F_176 ( V_89 ) ) {
unsigned char * V_284 = F_68 ( V_98 ) + V_295 -> V_99 ;
memcpy ( F_178 ( V_89 , V_296 ) , V_284 , F_171 ( V_296 , sizeof( long ) ) ) ;
if ( F_98 ( F_182 ( V_98 ) == F_183 () ) )
return true ;
F_184 ( V_98 ) ;
return false ;
}
F_185 ( V_89 , F_151 ( V_89 ) -> V_302 , V_98 ,
V_295 -> V_99 , V_296 , V_299 ) ;
if ( F_24 ( F_182 ( V_98 ) != F_183 () ) )
return false ;
#if ( V_298 < 8192 )
if ( F_24 ( F_186 ( V_98 ) != 1 ) )
return false ;
V_295 -> V_99 ^= V_299 ;
F_187 ( & V_98 -> V_303 , 2 ) ;
#else
V_295 -> V_99 += V_299 ;
if ( V_295 -> V_99 > V_301 )
return false ;
F_188 ( V_98 ) ;
#endif
return true ;
}
static struct V_193 * F_189 ( struct V_57 * V_67 ,
union V_68 * V_69 )
{
struct V_70 * V_295 ;
struct V_193 * V_89 ;
struct V_98 * V_98 ;
V_295 = & V_67 -> V_71 [ V_67 -> V_79 ] ;
V_98 = V_295 -> V_98 ;
F_190 ( V_98 ) ;
V_89 = V_295 -> V_89 ;
if ( F_98 ( ! V_89 ) ) {
void * V_304 = F_68 ( V_98 ) +
V_295 -> V_99 ;
F_97 ( V_304 ) ;
#if V_300 < 128
F_97 ( V_304 + V_300 ) ;
#endif
V_89 = F_191 ( V_67 -> V_55 ,
V_286 ) ;
if ( F_24 ( ! V_89 ) ) {
V_67 -> V_210 . V_305 ++ ;
return NULL ;
}
F_190 ( V_89 -> V_92 ) ;
if ( F_98 ( F_133 ( V_69 , V_279 ) ) )
goto V_306;
F_153 ( V_89 ) -> V_81 = V_295 -> V_81 ;
} else {
if ( F_133 ( V_69 , V_279 ) )
F_173 ( V_67 , V_89 ) ;
V_306:
F_174 ( V_67 -> V_73 ,
V_295 -> V_81 ,
V_295 -> V_99 ,
F_69 ( V_67 ) ,
V_225 ) ;
}
if ( F_181 ( V_67 , V_295 , V_69 , V_89 ) ) {
F_179 ( V_67 , V_295 ) ;
} else if ( F_153 ( V_89 ) -> V_81 == V_295 -> V_81 ) {
F_153 ( V_89 ) -> V_288 = true ;
} else {
F_80 ( V_67 -> V_73 , V_295 -> V_81 ,
F_141 ( V_67 ) ,
V_225 ) ;
}
V_295 -> V_89 = NULL ;
V_295 -> V_81 = 0 ;
V_295 -> V_98 = NULL ;
return V_89 ;
}
static int F_192 ( struct V_155 * V_156 ,
struct V_57 * V_67 ,
const int V_159 )
{
unsigned int V_307 = 0 , V_308 = 0 ;
#ifdef F_148
struct V_1 * V_2 = V_156 -> V_2 ;
int V_309 ;
unsigned int V_310 = 0 ;
#endif
T_2 V_226 = F_109 ( V_67 ) ;
while ( F_98 ( V_308 < V_159 ) ) {
union V_68 * V_69 ;
struct V_193 * V_89 ;
if ( V_226 >= V_311 ) {
F_144 ( V_67 , V_226 ) ;
V_226 = 0 ;
}
V_69 = F_66 ( V_67 , V_67 -> V_79 ) ;
if ( ! F_133 ( V_69 , V_97 ) )
break;
F_193 () ;
V_89 = F_189 ( V_67 , V_69 ) ;
if ( ! V_89 )
break;
V_226 ++ ;
if ( F_166 ( V_67 , V_69 , V_89 ) )
continue;
if ( F_175 ( V_67 , V_69 , V_89 ) )
continue;
V_307 += V_89 -> V_82 ;
F_155 ( V_67 , V_69 , V_89 ) ;
#ifdef F_148
if ( F_129 ( V_67 , V_69 ) ) {
V_309 = F_194 ( V_2 , V_69 , V_89 ) ;
if ( V_309 > 0 ) {
if ( ! V_310 ) {
V_310 = V_67 -> V_55 -> V_312 -
sizeof( struct V_313 ) -
sizeof( struct V_314 ) -
sizeof( struct V_315 ) ;
if ( V_310 > 512 )
V_310 &= ~ 511 ;
}
V_307 += V_309 ;
V_308 += F_152 ( V_309 ,
V_310 ) ;
}
if ( ! V_309 ) {
F_78 ( V_89 ) ;
continue;
}
}
#endif
F_195 ( V_89 , & V_156 -> V_271 ) ;
F_161 ( V_156 , V_89 ) ;
V_308 ++ ;
}
F_99 ( & V_67 -> V_167 ) ;
V_67 -> V_122 . V_142 += V_308 ;
V_67 -> V_122 . V_168 += V_307 ;
F_100 ( & V_67 -> V_167 ) ;
V_156 -> V_316 . V_158 += V_308 ;
V_156 -> V_316 . V_157 += V_307 ;
if ( V_226 )
F_144 ( V_67 , V_226 ) ;
return V_308 ;
}
static int F_196 ( struct V_317 * V_271 )
{
struct V_155 * V_156 =
F_197 ( V_271 , struct V_155 , V_271 ) ;
struct V_1 * V_2 = V_156 -> V_2 ;
struct V_57 * V_118 ;
int V_318 = 0 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return V_319 ;
if ( ! F_198 ( V_156 ) )
return V_320 ;
F_120 (ring, q_vector->rx) {
V_318 = F_192 ( V_156 , V_118 , 4 ) ;
#ifdef F_199
if ( V_318 )
V_118 -> V_122 . V_321 += V_318 ;
else
V_118 -> V_122 . V_322 ++ ;
#endif
if ( V_318 )
break;
}
F_200 ( V_156 ) ;
return V_318 ;
}
static void F_201 ( struct V_1 * V_2 )
{
struct V_155 * V_156 ;
int V_323 ;
T_1 V_115 ;
if ( V_2 -> V_324 > 32 ) {
T_1 V_325 = ( 1 << ( V_2 -> V_324 - 32 ) ) - 1 ;
F_71 ( & V_2 -> V_14 , V_326 , V_325 ) ;
}
for ( V_323 = 0 ; V_323 < V_2 -> V_187 ; V_323 ++ ) {
struct V_57 * V_118 ;
V_156 = V_2 -> V_156 [ V_323 ] ;
F_120 (ring, q_vector->rx)
F_73 ( V_2 , 0 , V_118 -> V_147 , V_323 ) ;
F_120 (ring, q_vector->tx)
F_73 ( V_2 , 1 , V_118 -> V_147 , V_323 ) ;
F_202 ( V_156 ) ;
}
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
F_73 ( V_2 , - 1 , V_327 ,
V_323 ) ;
break;
case V_111 :
case V_112 :
F_73 ( V_2 , - 1 , 1 , V_323 ) ;
break;
default:
break;
}
F_71 ( & V_2 -> V_14 , F_203 ( V_323 ) , 1950 ) ;
V_115 = V_328 ;
V_115 &= ~ ( V_329 |
V_330 |
V_331 ) ;
F_71 ( & V_2 -> V_14 , V_332 , V_115 ) ;
}
static void F_204 ( struct V_155 * V_156 ,
struct V_333 * V_334 )
{
int V_168 = V_334 -> V_157 ;
int V_142 = V_334 -> V_158 ;
T_1 V_335 ;
T_6 V_336 ;
T_4 V_337 = V_334 -> V_338 ;
if ( V_142 == 0 )
return;
V_335 = V_156 -> V_338 >> 2 ;
if ( V_335 == 0 )
return;
V_336 = V_168 / V_335 ;
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
V_334 -> V_157 = 0 ;
V_334 -> V_158 = 0 ;
V_334 -> V_338 = V_337 ;
}
void F_202 ( struct V_155 * V_156 )
{
struct V_1 * V_2 = V_156 -> V_2 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_323 = V_156 -> V_323 ;
T_1 V_342 = V_156 -> V_338 & V_343 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
V_342 |= ( V_342 << 16 ) ;
break;
case V_111 :
case V_112 :
V_342 |= V_344 ;
break;
default:
break;
}
F_71 ( V_14 , F_203 ( V_323 ) , V_342 ) ;
}
static void F_205 ( struct V_155 * V_156 )
{
T_1 V_345 = V_156 -> V_338 ;
T_4 V_346 ;
F_204 ( V_156 , & V_156 -> V_160 ) ;
F_204 ( V_156 , & V_156 -> V_316 ) ;
V_346 = F_206 ( V_156 -> V_316 . V_338 , V_156 -> V_160 . V_338 ) ;
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
if ( V_345 != V_156 -> V_338 ) {
V_345 = ( 10 * V_345 * V_156 -> V_338 ) /
( ( 9 * V_345 ) + V_156 -> V_338 ) ;
V_156 -> V_338 = V_345 ;
F_202 ( V_156 ) ;
}
}
static void F_207 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_350 = V_2 -> V_351 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
if ( ! ( V_2 -> V_152 & V_352 ) &&
! ( V_2 -> V_152 & V_353 ) )
return;
V_2 -> V_152 &= ~ V_353 ;
switch ( V_14 -> V_21 ) {
case V_354 :
if ( ! ( V_350 & V_355 ) &&
! ( V_350 & V_356 ) )
return;
if ( ! ( V_350 & V_356 ) && V_14 -> V_108 . V_357 . V_358 ) {
T_1 V_20 ;
bool V_359 = false ;
V_14 -> V_108 . V_357 . V_358 ( V_14 , & V_20 , & V_359 , false ) ;
if ( V_359 )
return;
}
if ( V_14 -> V_360 . V_357 . V_361 ( V_14 ) != V_362 )
return;
break;
default:
if ( ! ( V_350 & V_355 ) )
return;
break;
}
F_208 ( V_154 ,
L_70
L_71
L_72 ) ;
V_2 -> V_351 = 0 ;
}
static void F_209 ( struct V_1 * V_2 , T_1 V_350 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ( V_2 -> V_137 & V_363 ) &&
( V_350 & V_364 ) ) {
F_208 ( V_170 , L_73 ) ;
F_71 ( V_14 , V_365 , V_364 ) ;
}
}
static void F_210 ( struct V_1 * V_2 , T_1 V_350 )
{
if ( ! ( V_2 -> V_152 & V_352 ) )
return;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
if ( ( ( V_350 & V_355 ) || ( V_350 & V_356 ) ) &&
( ! F_14 ( V_33 , & V_2 -> V_34 ) ) ) {
V_2 -> V_351 = V_350 ;
V_2 -> V_152 |= V_353 ;
F_13 ( V_2 ) ;
return;
}
return;
case V_112 :
if ( ! ( V_350 & V_366 ) )
return;
break;
default:
return;
}
F_208 ( V_154 ,
L_70
L_71
L_72 ) ;
}
static void F_211 ( struct V_1 * V_2 , T_1 V_350 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_350 & V_367 ) {
F_71 ( V_14 , V_365 , V_367 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_152 |= V_368 ;
F_13 ( V_2 ) ;
}
}
if ( V_350 & V_364 ) {
F_71 ( V_14 , V_365 , V_364 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_137 |= V_369 ;
F_13 ( V_2 ) ;
}
}
}
static void F_212 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_370 ++ ;
V_2 -> V_137 |= V_371 ;
V_2 -> V_372 = V_169 ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
F_71 ( V_14 , V_373 , V_374 ) ;
F_213 ( V_14 ) ;
F_13 ( V_2 ) ;
}
}
static inline void F_214 ( struct V_1 * V_2 ,
T_6 V_114 )
{
T_1 V_115 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_115 = ( V_116 & V_114 ) ;
F_71 ( V_14 , V_375 , V_115 ) ;
break;
case V_111 :
case V_112 :
V_115 = ( V_114 & 0xFFFFFFFF ) ;
if ( V_115 )
F_71 ( V_14 , F_215 ( 0 ) , V_115 ) ;
V_115 = ( V_114 >> 32 ) ;
if ( V_115 )
F_71 ( V_14 , F_215 ( 1 ) , V_115 ) ;
break;
default:
break;
}
}
static inline void F_216 ( struct V_1 * V_2 ,
T_6 V_114 )
{
T_1 V_115 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_115 = ( V_116 & V_114 ) ;
F_71 ( V_14 , V_373 , V_115 ) ;
break;
case V_111 :
case V_112 :
V_115 = ( V_114 & 0xFFFFFFFF ) ;
if ( V_115 )
F_71 ( V_14 , F_217 ( 0 ) , V_115 ) ;
V_115 = ( V_114 >> 32 ) ;
if ( V_115 )
F_71 ( V_14 , F_217 ( 1 ) , V_115 ) ;
break;
default:
break;
}
}
static inline void F_218 ( struct V_1 * V_2 , bool V_376 ,
bool V_377 )
{
T_1 V_115 = ( V_328 & ~ V_116 ) ;
if ( V_2 -> V_137 & V_371 )
V_115 &= ~ V_331 ;
if ( V_2 -> V_152 & V_352 )
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_115 |= V_378 ;
break;
case V_112 :
V_115 |= V_379 ;
break;
default:
break;
}
if ( V_2 -> V_137 & V_363 )
V_115 |= V_380 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_115 |= V_380 ;
V_115 |= V_381 ;
case V_112 :
V_115 |= V_382 ;
V_115 |= V_330 ;
break;
default:
break;
}
if ( V_2 -> V_14 . V_108 . type == V_112 )
V_115 |= V_383 ;
if ( ( V_2 -> V_137 & V_384 ) &&
! ( V_2 -> V_152 & V_385 ) )
V_115 |= V_386 ;
F_71 ( & V_2 -> V_14 , V_375 , V_115 ) ;
if ( V_376 )
F_214 ( V_2 , ~ 0 ) ;
if ( V_377 )
F_213 ( & V_2 -> V_14 ) ;
}
static T_12 F_219 ( int V_387 , void * V_92 )
{
struct V_1 * V_2 = V_92 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_350 ;
V_350 = F_37 ( V_14 , V_117 ) ;
V_350 &= 0xFFFF0000 ;
F_71 ( V_14 , V_365 , V_350 ) ;
if ( V_350 & V_356 )
F_212 ( V_2 ) ;
if ( V_350 & V_388 )
F_220 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
if ( V_350 & V_389 ) {
F_104 ( V_390 , L_74 ) ;
V_2 -> V_152 |= V_153 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_365 , V_389 ) ;
}
if ( V_350 & V_391 ) {
int V_392 = 0 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_118 = V_2 -> V_58 [ V_48 ] ;
if ( F_221 ( V_393 ,
& V_118 -> V_34 ) )
V_392 ++ ;
}
if ( V_392 ) {
F_71 ( V_14 , V_373 , V_394 ) ;
V_2 -> V_152 |= V_385 ;
F_13 ( V_2 ) ;
}
}
F_211 ( V_2 , V_350 ) ;
F_210 ( V_2 , V_350 ) ;
break;
default:
break;
}
F_209 ( V_2 , V_350 ) ;
if ( F_24 ( V_350 & V_395 ) )
F_222 ( V_2 , V_350 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_218 ( V_2 , false , false ) ;
return V_396 ;
}
static T_12 F_223 ( int V_387 , void * V_92 )
{
struct V_155 * V_156 = V_92 ;
if ( V_156 -> V_316 . V_118 || V_156 -> V_160 . V_118 )
F_224 ( & V_156 -> V_271 ) ;
return V_396 ;
}
int F_225 ( struct V_317 * V_271 , int V_159 )
{
struct V_155 * V_156 =
F_197 ( V_271 , struct V_155 , V_271 ) ;
struct V_1 * V_2 = V_156 -> V_2 ;
struct V_57 * V_118 ;
int V_397 ;
bool V_398 = true ;
#ifdef F_226
if ( V_2 -> V_137 & V_185 )
F_118 ( V_156 ) ;
#endif
F_120 (ring, q_vector->tx)
V_398 &= ! ! F_94 ( V_156 , V_118 ) ;
if ( ! F_227 ( V_156 ) )
return V_159 ;
if ( V_156 -> V_316 . V_88 > 1 )
V_397 = F_206 ( V_159 / V_156 -> V_316 . V_88 , 1 ) ;
else
V_397 = V_159 ;
F_120 (ring, q_vector->rx)
V_398 &= ( F_192 ( V_156 , V_118 ,
V_397 ) < V_397 ) ;
F_228 ( V_156 ) ;
if ( ! V_398 )
return V_159 ;
F_229 ( V_271 ) ;
if ( V_2 -> V_399 & 1 )
F_205 ( V_156 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_214 ( V_2 , ( ( T_6 ) 1 << V_156 -> V_323 ) ) ;
return 0 ;
}
static int F_230 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
int V_400 , V_17 ;
int V_401 = 0 , V_402 = 0 ;
for ( V_400 = 0 ; V_400 < V_2 -> V_187 ; V_400 ++ ) {
struct V_155 * V_156 = V_2 -> V_156 [ V_400 ] ;
struct V_403 * V_404 = & V_2 -> V_405 [ V_400 ] ;
if ( V_156 -> V_160 . V_118 && V_156 -> V_316 . V_118 ) {
snprintf ( V_156 -> V_53 , sizeof( V_156 -> V_53 ) - 1 ,
L_75 , V_55 -> V_53 , L_76 , V_401 ++ ) ;
V_402 ++ ;
} else if ( V_156 -> V_316 . V_118 ) {
snprintf ( V_156 -> V_53 , sizeof( V_156 -> V_53 ) - 1 ,
L_75 , V_55 -> V_53 , L_77 , V_401 ++ ) ;
} else if ( V_156 -> V_160 . V_118 ) {
snprintf ( V_156 -> V_53 , sizeof( V_156 -> V_53 ) - 1 ,
L_75 , V_55 -> V_53 , L_78 , V_402 ++ ) ;
} else {
continue;
}
V_17 = F_231 ( V_404 -> V_400 , & F_223 , 0 ,
V_156 -> V_53 , V_156 ) ;
if ( V_17 ) {
F_102 ( V_170 , L_79
L_80 , V_17 ) ;
goto V_406;
}
if ( V_2 -> V_137 & V_384 ) {
F_232 ( V_404 -> V_400 ,
& V_156 -> V_407 ) ;
}
}
V_17 = F_231 ( V_2 -> V_405 [ V_400 ] . V_400 ,
F_219 , 0 , V_55 -> V_53 , V_2 ) ;
if ( V_17 ) {
F_102 ( V_170 , L_81 , V_17 ) ;
goto V_406;
}
return 0 ;
V_406:
while ( V_400 ) {
V_400 -- ;
F_232 ( V_2 -> V_405 [ V_400 ] . V_400 ,
NULL ) ;
F_233 ( V_2 -> V_405 [ V_400 ] . V_400 ,
V_2 -> V_156 [ V_400 ] ) ;
}
V_2 -> V_137 &= ~ V_408 ;
F_234 ( V_2 -> V_9 ) ;
F_235 ( V_2 -> V_405 ) ;
V_2 -> V_405 = NULL ;
return V_17 ;
}
static T_12 F_236 ( int V_387 , void * V_92 )
{
struct V_1 * V_2 = V_92 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_155 * V_156 = V_2 -> V_156 [ 0 ] ;
T_1 V_350 ;
F_71 ( V_14 , V_373 , V_409 ) ;
V_350 = F_37 ( V_14 , V_365 ) ;
if ( ! V_350 ) {
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_218 ( V_2 , true , true ) ;
return V_410 ;
}
if ( V_350 & V_356 )
F_212 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
F_211 ( V_2 , V_350 ) ;
case V_112 :
if ( V_350 & V_389 ) {
F_104 ( V_390 , L_74 ) ;
V_2 -> V_152 |= V_153 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_365 , V_389 ) ;
}
F_210 ( V_2 , V_350 ) ;
break;
default:
break;
}
F_209 ( V_2 , V_350 ) ;
if ( F_24 ( V_350 & V_395 ) )
F_222 ( V_2 , V_350 ) ;
F_224 ( & V_156 -> V_271 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_218 ( V_2 , false , false ) ;
return V_396 ;
}
static int F_237 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
int V_17 ;
if ( V_2 -> V_137 & V_408 )
V_17 = F_230 ( V_2 ) ;
else if ( V_2 -> V_137 & V_411 )
V_17 = F_231 ( V_2 -> V_9 -> V_387 , F_236 , 0 ,
V_55 -> V_53 , V_2 ) ;
else
V_17 = F_231 ( V_2 -> V_9 -> V_387 , F_236 , V_412 ,
V_55 -> V_53 , V_2 ) ;
if ( V_17 )
F_102 ( V_170 , L_82 , V_17 ) ;
return V_17 ;
}
static void F_238 ( struct V_1 * V_2 )
{
int V_400 ;
if ( ! ( V_2 -> V_137 & V_408 ) ) {
F_233 ( V_2 -> V_9 -> V_387 , V_2 ) ;
return;
}
for ( V_400 = 0 ; V_400 < V_2 -> V_187 ; V_400 ++ ) {
struct V_155 * V_156 = V_2 -> V_156 [ V_400 ] ;
struct V_403 * V_404 = & V_2 -> V_405 [ V_400 ] ;
if ( ! V_156 -> V_316 . V_118 && ! V_156 -> V_160 . V_118 )
continue;
F_232 ( V_404 -> V_400 , NULL ) ;
F_233 ( V_404 -> V_400 , V_156 ) ;
}
F_233 ( V_2 -> V_405 [ V_400 ++ ] . V_400 , V_2 ) ;
}
static inline void F_239 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
F_71 ( & V_2 -> V_14 , V_373 , ~ 0 ) ;
break;
case V_111 :
case V_112 :
F_71 ( & V_2 -> V_14 , V_373 , 0xFFFF0000 ) ;
F_71 ( & V_2 -> V_14 , F_217 ( 0 ) , ~ 0 ) ;
F_71 ( & V_2 -> V_14 , F_217 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_213 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_137 & V_408 ) {
int V_400 ;
for ( V_400 = 0 ; V_400 < V_2 -> V_187 ; V_400 ++ )
F_240 ( V_2 -> V_405 [ V_400 ] . V_400 ) ;
F_240 ( V_2 -> V_405 [ V_400 ++ ] . V_400 ) ;
} else {
F_240 ( V_2 -> V_9 -> V_387 ) ;
}
}
static void F_241 ( struct V_1 * V_2 )
{
struct V_155 * V_156 = V_2 -> V_156 [ 0 ] ;
F_202 ( V_156 ) ;
F_73 ( V_2 , 0 , 0 , 0 ) ;
F_73 ( V_2 , 1 , 0 , 0 ) ;
F_104 ( V_14 , L_83 ) ;
}
void F_242 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_413 = V_118 -> V_81 ;
int V_414 = 10 ;
T_1 V_415 = V_416 ;
T_4 V_147 = V_118 -> V_147 ;
F_71 ( V_14 , F_50 ( V_147 ) , 0 ) ;
F_213 ( V_14 ) ;
F_71 ( V_14 , F_45 ( V_147 ) ,
( V_413 & F_243 ( 32 ) ) ) ;
F_71 ( V_14 , F_46 ( V_147 ) , ( V_413 >> 32 ) ) ;
F_71 ( V_14 , F_47 ( V_147 ) ,
V_118 -> V_88 * sizeof( union V_61 ) ) ;
F_71 ( V_14 , F_48 ( V_147 ) , 0 ) ;
F_71 ( V_14 , F_49 ( V_147 ) , 0 ) ;
V_118 -> V_144 = V_2 -> V_417 + F_49 ( V_147 ) ;
#if F_244 ( V_418 )
if ( ! V_118 -> V_156 || ( V_118 -> V_156 -> V_338 < V_347 ) )
#else
if ( ! V_118 -> V_156 || ( V_118 -> V_156 -> V_338 < 8 ) )
#endif
V_415 |= ( 1 << 16 ) ;
else
V_415 |= ( 8 << 16 ) ;
V_415 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_137 & V_384 ) {
V_118 -> V_419 = V_2 -> V_419 ;
V_118 -> V_420 = 0 ;
F_245 ( V_393 , & V_118 -> V_34 ) ;
} else {
V_118 -> V_419 = 0 ;
}
if ( ! F_15 ( V_421 , & V_118 -> V_34 ) ) {
struct V_155 * V_156 = V_118 -> V_156 ;
if ( V_156 )
F_246 ( V_118 -> V_55 ,
& V_156 -> V_407 ,
V_118 -> V_86 ) ;
}
F_34 ( V_130 , & V_118 -> V_34 ) ;
F_71 ( V_14 , F_50 ( V_147 ) , V_415 ) ;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_422 ) & V_423 ) )
return;
do {
F_247 ( 1000 , 2000 ) ;
V_415 = F_37 ( V_14 , F_50 ( V_147 ) ) ;
} while ( -- V_414 && ! ( V_415 & V_416 ) );
if ( ! V_414 )
F_102 ( V_154 , L_84 , V_147 ) ;
}
static void F_248 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_424 , V_425 ;
T_4 V_426 = F_249 ( V_2 -> V_55 ) ;
if ( V_14 -> V_108 . type == V_109 )
return;
V_424 = F_37 ( V_14 , V_427 ) ;
V_424 |= V_428 ;
F_71 ( V_14 , V_427 , V_424 ) ;
if ( V_2 -> V_137 & V_429 ) {
V_425 = V_430 ;
if ( V_426 > 4 )
V_425 |= V_431 | V_432 ;
else if ( V_426 > 1 )
V_425 |= V_431 | V_433 ;
else if ( V_2 -> V_434 [ V_435 ] . V_436 == 4 )
V_425 |= V_437 ;
else
V_425 |= V_438 ;
} else {
if ( V_426 > 4 )
V_425 = V_431 | V_432 ;
else if ( V_426 > 1 )
V_425 = V_431 | V_433 ;
else
V_425 = V_439 ;
}
F_71 ( V_14 , V_440 , V_425 ) ;
if ( V_426 ) {
T_1 V_441 = F_37 ( V_14 , V_442 ) ;
V_441 |= V_443 ;
F_71 ( V_14 , V_442 , V_441 ) ;
}
V_424 &= ~ V_428 ;
F_71 ( V_14 , V_427 , V_424 ) ;
}
static void F_250 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_444 ;
T_1 V_48 ;
F_248 ( V_2 ) ;
if ( V_14 -> V_108 . type != V_109 ) {
V_444 = F_37 ( V_14 , V_445 ) ;
V_444 |= V_446 ;
F_71 ( V_14 , V_445 , V_444 ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_242 ( V_2 , V_2 -> V_58 [ V_48 ] ) ;
}
static void F_251 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_147 = V_118 -> V_147 ;
T_1 V_447 = F_37 ( V_14 , F_36 ( V_147 ) ) ;
V_447 |= V_448 ;
F_71 ( V_14 , F_36 ( V_147 ) , V_447 ) ;
}
static void F_252 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_147 = V_118 -> V_147 ;
T_1 V_447 = F_37 ( V_14 , F_36 ( V_147 ) ) ;
V_447 &= ~ V_448 ;
F_71 ( V_14 , F_36 ( V_147 ) , V_447 ) ;
}
static void F_253 ( struct V_1 * V_2 ,
struct V_57 * V_67 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_447 ;
T_4 V_147 = V_67 -> V_147 ;
if ( V_14 -> V_108 . type == V_109 ) {
T_2 V_115 = V_2 -> V_434 [ V_435 ] . V_115 ;
V_147 &= V_115 ;
}
V_447 = V_286 << V_449 ;
V_447 |= F_69 ( V_67 ) >> V_450 ;
V_447 |= V_451 ;
F_71 ( V_14 , F_36 ( V_147 ) , V_447 ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
static const T_1 V_452 [ 10 ] = { 0xE291D73D , 0x1805EC6C , 0x2A94B30D ,
0xA54F2BEC , 0xEA49AF7C , 0xE214AD3D , 0xB855AABE ,
0x6A3E67EA , 0x14364D17 , 0x3BED200D } ;
T_1 V_453 = 0 , V_454 = 0 ;
T_1 V_455 ;
int V_48 , V_49 ;
T_2 V_456 = V_2 -> V_434 [ V_435 ] . V_436 ;
if ( ( V_2 -> V_137 & V_429 ) && ( V_456 < 2 ) )
V_456 = 2 ;
for ( V_48 = 0 ; V_48 < 10 ; V_48 ++ )
F_71 ( V_14 , F_255 ( V_48 ) , V_452 [ V_48 ] ) ;
for ( V_48 = 0 , V_49 = 0 ; V_48 < 128 ; V_48 ++ , V_49 ++ ) {
if ( V_49 == V_456 )
V_49 = 0 ;
V_454 = ( V_454 << 8 ) | ( V_49 * 0x11 ) ;
if ( ( V_48 & 3 ) == 3 )
F_71 ( V_14 , F_256 ( V_48 >> 2 ) , V_454 ) ;
}
V_455 = F_37 ( V_14 , V_457 ) ;
V_455 |= V_458 ;
F_71 ( V_14 , V_457 , V_455 ) ;
if ( V_2 -> V_14 . V_108 . type == V_109 ) {
if ( V_2 -> V_434 [ V_435 ] . V_115 )
V_453 = V_459 ;
} else {
T_4 V_426 = F_249 ( V_2 -> V_55 ) ;
if ( V_2 -> V_137 & V_429 ) {
if ( V_426 > 4 )
V_453 = V_460 ;
else if ( V_426 > 1 )
V_453 = V_461 ;
else if ( V_2 -> V_434 [ V_435 ] . V_436 == 4 )
V_453 = V_462 ;
else
V_453 = V_463 ;
} else {
if ( V_426 > 4 )
V_453 = V_464 ;
else if ( V_426 > 1 )
V_453 = V_465 ;
else
V_453 = V_459 ;
}
}
V_453 |= V_466 |
V_467 |
V_468 |
V_469 ;
if ( V_2 -> V_152 & V_470 )
V_453 |= V_471 ;
if ( V_2 -> V_152 & V_472 )
V_453 |= V_473 ;
F_71 ( V_14 , V_474 , V_453 ) ;
}
static void F_257 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_475 ;
T_4 V_147 = V_118 -> V_147 ;
if ( ! F_167 ( V_118 ) )
return;
V_475 = F_37 ( V_14 , F_258 ( V_147 ) ) ;
V_475 |= V_476 ;
V_475 |= V_477 ;
F_71 ( V_14 , F_258 ( V_147 ) , V_475 ) ;
}
static void F_259 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_414 = V_478 ;
T_1 V_479 ;
T_4 V_147 = V_118 -> V_147 ;
if ( F_22 ( V_14 -> V_39 ) )
return;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_422 ) & V_423 ) )
return;
do {
F_247 ( 1000 , 2000 ) ;
V_479 = F_37 ( V_14 , F_42 ( V_147 ) ) ;
} while ( -- V_414 && ! ( V_479 & V_480 ) );
if ( ! V_414 ) {
F_102 ( V_154 , L_85
L_86 , V_147 ) ;
}
}
void F_260 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_414 = V_478 ;
T_1 V_479 ;
T_4 V_147 = V_118 -> V_147 ;
if ( F_22 ( V_14 -> V_39 ) )
return;
V_479 = F_37 ( V_14 , F_42 ( V_147 ) ) ;
V_479 &= ~ V_480 ;
F_71 ( V_14 , F_42 ( V_147 ) , V_479 ) ;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_422 ) & V_423 ) )
return;
do {
F_261 ( 10 ) ;
V_479 = F_37 ( V_14 , F_42 ( V_147 ) ) ;
} while ( -- V_414 && ( V_479 & V_480 ) );
if ( ! V_414 ) {
F_102 ( V_154 , L_87
L_86 , V_147 ) ;
}
}
void F_262 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_481 = V_118 -> V_81 ;
T_1 V_479 ;
T_4 V_147 = V_118 -> V_147 ;
V_479 = F_37 ( V_14 , F_42 ( V_147 ) ) ;
F_260 ( V_2 , V_118 ) ;
F_71 ( V_14 , F_43 ( V_147 ) , ( V_481 & F_243 ( 32 ) ) ) ;
F_71 ( V_14 , F_44 ( V_147 ) , ( V_481 >> 32 ) ) ;
F_71 ( V_14 , F_39 ( V_147 ) ,
V_118 -> V_88 * sizeof( union V_68 ) ) ;
F_71 ( V_14 , F_40 ( V_147 ) , 0 ) ;
F_71 ( V_14 , F_41 ( V_147 ) , 0 ) ;
V_118 -> V_144 = V_2 -> V_417 + F_41 ( V_147 ) ;
F_253 ( V_2 , V_118 ) ;
F_257 ( V_2 , V_118 ) ;
if ( V_14 -> V_108 . type == V_109 ) {
V_479 &= ~ 0x3FFFFF ;
V_479 |= 0x080420 ;
}
V_479 |= V_480 ;
F_71 ( V_14 , F_42 ( V_147 ) , V_479 ) ;
F_259 ( V_2 , V_118 ) ;
F_144 ( V_118 , F_109 ( V_118 ) ) ;
}
static void F_263 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_456 = V_2 -> V_434 [ V_435 ] . V_436 ;
T_2 V_482 ;
T_1 V_483 = V_484 |
V_485 |
V_486 |
V_487 |
V_488 ;
if ( V_14 -> V_108 . type == V_109 )
return;
if ( V_456 > 3 )
V_483 |= 2 << 29 ;
else if ( V_456 > 1 )
V_483 |= 1 << 29 ;
F_264 (pool, &adapter->fwd_bitmask, 32 )
F_71 ( V_14 , F_265 ( F_266 ( V_482 ) ) , V_483 ) ;
}
static void F_267 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_175 , V_489 ;
T_1 V_490 , V_491 ;
int V_48 ;
if ( ! ( V_2 -> V_137 & V_429 ) )
return;
V_491 = F_37 ( V_14 , V_492 ) ;
V_491 |= V_493 ;
V_491 &= ~ V_494 ;
V_491 |= F_266 ( 0 ) << V_495 ;
V_491 |= V_496 ;
F_71 ( V_14 , V_492 , V_491 ) ;
V_489 = F_266 ( 0 ) % 32 ;
V_175 = ( F_266 ( 0 ) >= 32 ) ? 1 : 0 ;
F_71 ( V_14 , F_268 ( V_175 ) , ( ~ 0 ) << V_489 ) ;
F_71 ( V_14 , F_268 ( V_175 ^ 1 ) , V_175 - 1 ) ;
F_71 ( V_14 , F_269 ( V_175 ) , ( ~ 0 ) << V_489 ) ;
F_71 ( V_14 , F_269 ( V_175 ^ 1 ) , V_175 - 1 ) ;
if ( V_2 -> V_152 & V_497 )
F_71 ( V_14 , V_498 , V_499 ) ;
V_14 -> V_108 . V_357 . V_500 ( V_14 , 0 , F_266 ( 0 ) ) ;
switch ( V_2 -> V_434 [ V_501 ] . V_115 ) {
case V_502 :
V_490 = V_503 ;
break;
case V_504 :
V_490 = V_505 ;
break;
default:
V_490 = V_506 ;
break;
}
F_71 ( V_14 , V_507 , V_490 ) ;
V_14 -> V_108 . V_357 . V_508 ( V_14 , ( V_2 -> V_324 != 0 ) ,
V_2 -> V_324 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_324 ; V_48 ++ ) {
if ( ! V_2 -> V_509 [ V_48 ] . V_510 )
F_270 ( V_2 -> V_55 , V_48 , false ) ;
}
}
static void F_271 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_55 = V_2 -> V_55 ;
int V_511 = V_55 -> V_312 + V_244 + V_512 ;
struct V_57 * V_67 ;
int V_48 ;
T_1 V_513 , V_514 ;
#ifdef F_148
if ( ( V_2 -> V_137 & V_515 ) &&
( V_511 < V_516 ) )
V_511 = V_516 ;
#endif
if ( V_511 < ( V_517 + V_512 ) )
V_511 = ( V_517 + V_512 ) ;
V_513 = F_37 ( V_14 , V_518 ) ;
if ( V_511 != ( V_513 >> V_519 ) ) {
V_513 &= ~ V_520 ;
V_513 |= V_511 << V_519 ;
F_71 ( V_14 , V_518 , V_513 ) ;
}
V_514 = F_37 ( V_14 , V_521 ) ;
V_514 |= V_522 ;
F_71 ( V_14 , V_521 , V_514 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_67 = V_2 -> V_67 [ V_48 ] ;
if ( V_2 -> V_152 & V_523 )
F_272 ( V_67 ) ;
else
F_273 ( V_67 ) ;
}
}
static void F_274 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_524 = F_37 ( V_14 , V_525 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_524 |= V_526 ;
break;
case V_111 :
case V_112 :
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
static void F_275 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
T_1 V_180 , V_533 ;
V_180 = F_37 ( V_14 , V_534 ) ;
F_71 ( V_14 , V_534 , V_180 & ~ V_535 ) ;
F_263 ( V_2 ) ;
F_274 ( V_2 ) ;
V_533 = F_37 ( V_14 , V_536 ) ;
V_533 &= ~ V_537 ;
if ( ! ( V_2 -> V_152 & V_523 ) )
V_533 |= V_537 ;
F_71 ( V_14 , V_536 , V_533 ) ;
F_254 ( V_2 ) ;
F_271 ( V_2 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
F_262 ( V_2 , V_2 -> V_67 [ V_48 ] ) ;
if ( V_14 -> V_108 . type == V_109 )
V_180 |= V_538 ;
V_180 |= V_535 ;
V_14 -> V_108 . V_357 . V_539 ( V_14 , V_180 ) ;
}
static int F_276 ( struct V_54 * V_55 ,
T_10 V_540 , T_2 V_269 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_108 . V_357 . V_541 ( & V_2 -> V_14 , V_269 , F_266 ( 0 ) , true ) ;
F_245 ( V_269 , V_2 -> V_542 ) ;
return 0 ;
}
static int F_277 ( struct V_54 * V_55 ,
T_10 V_540 , T_2 V_269 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_108 . V_357 . V_541 ( & V_2 -> V_14 , V_269 , F_266 ( 0 ) , false ) ;
F_34 ( V_269 , V_2 -> V_542 ) ;
return 0 ;
}
static void F_278 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_543 ;
int V_48 , V_49 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_543 = F_37 ( V_14 , V_544 ) ;
V_543 &= ~ V_545 ;
F_71 ( V_14 , V_544 , V_543 ) ;
break;
case V_111 :
case V_112 :
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_118 = V_2 -> V_67 [ V_48 ] ;
if ( V_118 -> V_145 )
continue;
V_49 = V_118 -> V_147 ;
V_543 = F_37 ( V_14 , F_42 ( V_49 ) ) ;
V_543 &= ~ V_546 ;
F_71 ( V_14 , F_42 ( V_49 ) , V_543 ) ;
}
break;
default:
break;
}
}
static void F_279 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_543 ;
int V_48 , V_49 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_543 = F_37 ( V_14 , V_544 ) ;
V_543 |= V_545 ;
F_71 ( V_14 , V_544 , V_543 ) ;
break;
case V_111 :
case V_112 :
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_118 = V_2 -> V_67 [ V_48 ] ;
if ( V_118 -> V_145 )
continue;
V_49 = V_118 -> V_147 ;
V_543 = F_37 ( V_14 , F_42 ( V_49 ) ) ;
V_543 |= V_546 ;
F_71 ( V_14 , F_42 ( V_49 ) , V_543 ) ;
}
break;
default:
break;
}
}
static void F_280 ( struct V_1 * V_2 )
{
T_2 V_269 ;
F_276 ( V_2 -> V_55 , F_147 ( V_246 ) , 0 ) ;
F_264 (vid, adapter->active_vlans, VLAN_N_VID)
F_276 ( V_2 -> V_55 , F_147 ( V_246 ) , V_269 ) ;
}
static int F_281 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! F_57 ( V_55 ) )
return 0 ;
if ( V_14 -> V_108 . V_357 . V_547 )
V_14 -> V_108 . V_357 . V_547 ( V_14 , V_55 ) ;
else
return - V_548 ;
#ifdef F_282
F_283 ( V_2 ) ;
#endif
return F_284 ( V_55 ) ;
}
void F_285 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_549 ; V_48 ++ ) {
if ( V_2 -> V_550 [ V_48 ] . V_34 & V_551 )
V_14 -> V_108 . V_357 . V_552 ( V_14 , V_48 , V_2 -> V_550 [ V_48 ] . V_553 ,
V_2 -> V_550 [ V_48 ] . V_104 ,
V_554 ) ;
else
V_14 -> V_108 . V_357 . V_555 ( V_14 , V_48 ) ;
V_2 -> V_550 [ V_48 ] . V_34 &= ~ ( V_556 ) ;
}
}
static void F_286 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_549 ; V_48 ++ ) {
if ( V_2 -> V_550 [ V_48 ] . V_34 & V_556 ) {
if ( V_2 -> V_550 [ V_48 ] . V_34 &
V_551 )
V_14 -> V_108 . V_357 . V_552 ( V_14 , V_48 ,
V_2 -> V_550 [ V_48 ] . V_553 ,
V_2 -> V_550 [ V_48 ] . V_104 ,
V_554 ) ;
else
V_14 -> V_108 . V_357 . V_555 ( V_14 , V_48 ) ;
V_2 -> V_550 [ V_48 ] . V_34 &=
~ ( V_556 ) ;
}
}
}
static void F_287 ( struct V_1 * V_2 )
{
int V_48 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_549 ; V_48 ++ ) {
V_2 -> V_550 [ V_48 ] . V_34 |= V_556 ;
V_2 -> V_550 [ V_48 ] . V_34 &= ~ V_551 ;
memset ( V_2 -> V_550 [ V_48 ] . V_553 , 0 , V_557 ) ;
V_2 -> V_550 [ V_48 ] . V_104 = 0 ;
}
F_286 ( V_2 ) ;
}
static int F_288 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 , V_88 = 0 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_549 ; V_48 ++ ) {
if ( V_2 -> V_550 [ V_48 ] . V_34 == 0 )
V_88 ++ ;
}
return V_88 ;
}
static void F_289 ( struct V_1 * V_2 ,
T_4 * V_553 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
memcpy ( & V_2 -> V_550 [ 0 ] . V_553 , V_553 , V_557 ) ;
V_2 -> V_550 [ 0 ] . V_104 = F_266 ( 0 ) ;
V_2 -> V_550 [ 0 ] . V_34 = ( V_558 |
V_551 ) ;
V_14 -> V_108 . V_357 . V_552 ( V_14 , 0 , V_2 -> V_550 [ 0 ] . V_553 ,
V_2 -> V_550 [ 0 ] . V_104 ,
V_554 ) ;
}
int F_290 ( struct V_1 * V_2 , T_4 * V_553 , T_2 V_104 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
if ( F_291 ( V_553 ) )
return - V_559 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_549 ; V_48 ++ ) {
if ( V_2 -> V_550 [ V_48 ] . V_34 & V_551 )
continue;
V_2 -> V_550 [ V_48 ] . V_34 |= ( V_556 |
V_551 ) ;
F_292 ( V_2 -> V_550 [ V_48 ] . V_553 , V_553 ) ;
V_2 -> V_550 [ V_48 ] . V_104 = V_104 ;
F_286 ( V_2 ) ;
return V_48 ;
}
return - V_548 ;
}
int F_293 ( struct V_1 * V_2 , T_4 * V_553 , T_2 V_104 )
{
int V_48 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_291 ( V_553 ) )
return - V_559 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_549 ; V_48 ++ ) {
if ( F_294 ( V_553 , V_2 -> V_550 [ V_48 ] . V_553 ) &&
V_2 -> V_550 [ V_48 ] . V_104 == V_104 ) {
V_2 -> V_550 [ V_48 ] . V_34 |= V_556 ;
V_2 -> V_550 [ V_48 ] . V_34 &= ~ V_551 ;
memset ( V_2 -> V_550 [ V_48 ] . V_553 , 0 , V_557 ) ;
V_2 -> V_550 [ V_48 ] . V_104 = 0 ;
F_286 ( V_2 ) ;
return 0 ;
}
}
return - V_548 ;
}
static int F_295 ( struct V_54 * V_55 , int V_560 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_88 = 0 ;
if ( F_296 ( V_55 ) > F_288 ( V_2 ) )
return - V_548 ;
if ( ! F_297 ( V_55 ) ) {
struct V_561 * V_562 ;
F_298 (ha, netdev) {
F_293 ( V_2 , V_562 -> V_553 , V_560 ) ;
F_290 ( V_2 , V_562 -> V_553 , V_560 ) ;
V_88 ++ ;
}
}
return V_88 ;
}
void F_299 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_563 , V_564 = V_565 | V_566 ;
T_1 V_543 ;
int V_88 ;
V_563 = F_37 ( V_14 , V_567 ) ;
V_543 = F_37 ( V_14 , V_544 ) ;
V_563 &= ~ V_568 ;
V_563 |= V_569 ;
V_563 |= V_570 ;
V_563 |= V_571 ;
V_563 &= ~ ( V_572 | V_573 ) ;
V_543 &= ~ ( V_574 | V_575 ) ;
if ( V_55 -> V_137 & V_576 ) {
V_14 -> V_577 . V_578 = true ;
V_563 |= ( V_572 | V_573 ) ;
V_564 |= V_579 ;
if ( ! ( V_2 -> V_137 & ( V_580 |
V_429 ) ) )
V_543 |= ( V_574 | V_575 ) ;
} else {
if ( V_55 -> V_137 & V_581 ) {
V_563 |= V_573 ;
V_564 |= V_579 ;
}
V_543 |= V_574 ;
V_14 -> V_577 . V_578 = false ;
}
V_88 = F_295 ( V_55 , F_266 ( 0 ) ) ;
if ( V_88 < 0 ) {
V_563 |= V_572 ;
V_564 |= V_582 ;
}
V_88 = F_281 ( V_55 ) ;
if ( V_88 < 0 ) {
V_563 |= V_573 ;
V_564 |= V_579 ;
} else if ( V_88 ) {
V_564 |= V_583 ;
}
if ( V_14 -> V_108 . type != V_109 ) {
V_564 |= F_37 ( V_14 , F_300 ( F_266 ( 0 ) ) ) &
~ ( V_579 | V_583 |
V_582 ) ;
F_71 ( V_14 , F_300 ( F_266 ( 0 ) ) , V_564 ) ;
}
if ( V_2 -> V_55 -> V_194 & V_290 ) {
V_563 |= ( V_568 |
V_569 |
V_571 ) ;
V_563 &= ~ ( V_570 ) ;
}
F_71 ( V_14 , V_544 , V_543 ) ;
F_71 ( V_14 , V_567 , V_563 ) ;
if ( V_55 -> V_194 & V_267 )
F_279 ( V_2 ) ;
else
F_278 ( V_2 ) ;
}
static void F_301 ( struct V_1 * V_2 )
{
int V_584 ;
for ( V_584 = 0 ; V_584 < V_2 -> V_187 ; V_584 ++ ) {
F_302 ( V_2 -> V_156 [ V_584 ] ) ;
F_303 ( & V_2 -> V_156 [ V_584 ] -> V_271 ) ;
}
}
static void F_304 ( struct V_1 * V_2 )
{
int V_584 ;
for ( V_584 = 0 ; V_584 < V_2 -> V_187 ; V_584 ++ ) {
F_305 ( & V_2 -> V_156 [ V_584 ] -> V_271 ) ;
while ( ! F_306 ( V_2 -> V_156 [ V_584 ] ) ) {
F_51 ( L_88 , V_584 ) ;
F_247 ( 1000 , 20000 ) ;
}
}
}
static void F_307 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_511 = V_2 -> V_55 -> V_312 + V_244 + V_512 ;
if ( ! ( V_2 -> V_137 & V_138 ) ) {
if ( V_14 -> V_108 . type == V_109 )
F_308 ( V_2 -> V_55 , 65536 ) ;
return;
}
if ( V_14 -> V_108 . type == V_109 )
F_308 ( V_2 -> V_55 , 32768 ) ;
#ifdef F_148
if ( V_2 -> V_55 -> V_194 & V_585 )
V_511 = F_206 ( V_511 , V_516 ) ;
#endif
if ( V_2 -> V_586 & V_587 ) {
F_309 ( V_14 , & V_2 -> V_134 , V_511 ,
V_588 ) ;
F_309 ( V_14 , & V_2 -> V_134 , V_511 ,
V_589 ) ;
F_310 ( V_14 , & V_2 -> V_134 ) ;
} else if ( V_2 -> V_590 && V_2 -> V_136 ) {
F_311 ( & V_2 -> V_14 ,
V_2 -> V_590 ,
V_511 ) ;
F_312 ( & V_2 -> V_14 ,
V_2 -> V_136 -> V_133 ,
V_2 -> V_590 -> V_591 ) ;
}
if ( V_14 -> V_108 . type != V_109 ) {
T_1 V_592 = 0 ;
T_2 V_456 = V_2 -> V_434 [ V_435 ] . V_436 - 1 ;
while ( V_456 ) {
V_592 ++ ;
V_456 >>= 1 ;
}
F_71 ( V_14 , V_593 , V_592 * 0x11111111 ) ;
}
}
static int F_313 ( struct V_1 * V_2 , int V_594 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_73 = V_2 -> V_55 ;
int V_390 , V_132 , V_595 , V_596 ;
T_1 V_597 , V_598 ;
V_132 = V_390 = V_73 -> V_312 + V_244 + V_512 + V_599 ;
#ifdef F_148
if ( ( V_73 -> V_194 & V_585 ) &&
( V_132 < V_516 ) &&
( V_594 == F_314 ( V_2 ) ) )
V_132 = V_516 ;
#endif
switch ( V_14 -> V_108 . type ) {
case V_112 :
V_597 = F_315 ( V_390 , V_132 ) ;
break;
default:
V_597 = F_316 ( V_390 , V_132 ) ;
break;
}
if ( V_2 -> V_137 & V_429 )
V_597 += F_317 ( V_132 ) ;
V_595 = F_318 ( V_597 ) ;
V_598 = F_37 ( V_14 , F_319 ( V_594 ) ) >> 10 ;
V_596 = V_598 - V_595 ;
if ( V_596 < 0 ) {
F_93 ( V_154 , L_89
L_90
L_91 , V_594 ) ;
V_596 = V_132 + 1 ;
}
return V_596 ;
}
static int F_320 ( struct V_1 * V_2 , int V_594 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_73 = V_2 -> V_55 ;
int V_132 ;
T_1 V_597 ;
V_132 = V_73 -> V_312 + V_244 + V_512 ;
#ifdef F_148
if ( ( V_73 -> V_194 & V_585 ) &&
( V_132 < V_516 ) &&
( V_594 == F_86 ( V_73 , V_2 -> V_600 . V_601 ) ) )
V_132 = V_516 ;
#endif
switch ( V_14 -> V_108 . type ) {
case V_112 :
V_597 = F_321 ( V_132 ) ;
break;
default:
V_597 = F_322 ( V_132 ) ;
break;
}
return F_318 ( V_597 ) ;
}
static void F_323 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_602 = F_249 ( V_2 -> V_55 ) ;
int V_48 ;
if ( ! V_602 )
V_602 = 1 ;
for ( V_48 = 0 ; V_48 < V_602 ; V_48 ++ ) {
V_14 -> V_123 . V_603 [ V_48 ] = F_313 ( V_2 , V_48 ) ;
V_14 -> V_123 . V_604 [ V_48 ] = F_320 ( V_2 , V_48 ) ;
if ( V_14 -> V_123 . V_604 [ V_48 ] > V_14 -> V_123 . V_603 [ V_48 ] )
V_14 -> V_123 . V_604 [ V_48 ] = 0 ;
}
for (; V_48 < V_605 ; V_48 ++ )
V_14 -> V_123 . V_603 [ V_48 ] = 0 ;
}
static void F_324 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_606 ;
T_4 V_132 = F_249 ( V_2 -> V_55 ) ;
if ( V_2 -> V_137 & V_384 ||
V_2 -> V_137 & V_607 )
V_606 = 32 << V_2 -> V_608 ;
else
V_606 = 0 ;
V_14 -> V_108 . V_357 . V_609 ( V_14 , V_132 , V_606 , V_610 ) ;
F_323 ( V_2 ) ;
}
static void F_325 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_611 * V_612 ;
struct V_613 * V_614 ;
F_326 ( & V_2 -> V_615 ) ;
if ( ! F_327 ( & V_2 -> V_616 ) )
F_328 ( V_14 , & V_2 -> V_617 ) ;
F_329 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_330 ( V_14 ,
& V_614 -> V_614 ,
V_614 -> V_618 ,
( V_614 -> V_619 == V_620 ) ?
V_620 :
V_2 -> V_67 [ V_614 -> V_619 ] -> V_147 ) ;
}
F_331 ( & V_2 -> V_615 ) ;
}
static void F_332 ( struct V_54 * V_73 , unsigned int V_482 ,
struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_564 ;
V_564 = F_37 ( V_14 , F_300 ( V_482 ) ) ;
V_564 |= ( V_583 | V_565 | V_566 ) ;
V_564 &= ~ V_579 ;
if ( V_73 -> V_137 & V_581 ) {
V_564 |= V_579 ;
} else {
V_564 |= V_583 ;
V_14 -> V_108 . V_357 . V_547 ( V_14 , V_73 ) ;
}
F_295 ( V_2 -> V_55 , V_482 ) ;
F_71 ( V_14 , F_300 ( V_482 ) , V_564 ) ;
}
static void F_333 ( struct V_621 * V_622 )
{
struct V_1 * V_2 = V_622 -> V_146 ;
int V_456 = V_2 -> V_623 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_482 = V_622 -> V_482 ;
T_1 V_483 = V_484 |
V_485 |
V_486 |
V_487 |
V_488 ;
if ( V_14 -> V_108 . type == V_109 )
return;
if ( V_456 > 3 )
V_483 |= 2 << 29 ;
else if ( V_456 > 1 )
V_483 |= 1 << 29 ;
F_71 ( V_14 , F_265 ( F_266 ( V_482 ) ) , V_483 ) ;
}
static void F_334 ( struct V_57 * V_67 )
{
struct V_188 * V_73 = V_67 -> V_73 ;
unsigned long V_296 ;
T_2 V_48 ;
if ( ! V_67 -> V_71 )
return;
for ( V_48 = 0 ; V_48 < V_67 -> V_88 ; V_48 ++ ) {
struct V_70 * V_295 ;
V_295 = & V_67 -> V_71 [ V_48 ] ;
if ( V_295 -> V_89 ) {
struct V_193 * V_89 = V_295 -> V_89 ;
if ( F_153 ( V_89 ) -> V_288 ) {
F_80 ( V_73 ,
F_153 ( V_89 ) -> V_81 ,
F_69 ( V_67 ) ,
V_225 ) ;
F_153 ( V_89 ) -> V_288 = false ;
}
F_335 ( V_89 ) ;
}
V_295 -> V_89 = NULL ;
if ( V_295 -> V_81 )
F_80 ( V_73 , V_295 -> V_81 ,
F_141 ( V_67 ) ,
V_225 ) ;
V_295 -> V_81 = 0 ;
if ( V_295 -> V_98 )
F_143 ( V_295 -> V_98 ,
F_139 ( V_67 ) ) ;
V_295 -> V_98 = NULL ;
}
V_296 = sizeof( struct V_70 ) * V_67 -> V_88 ;
memset ( V_67 -> V_71 , 0 , V_296 ) ;
memset ( V_67 -> V_87 , 0 , V_67 -> V_296 ) ;
V_67 -> V_219 = 0 ;
V_67 -> V_79 = 0 ;
V_67 -> V_80 = 0 ;
}
static void F_336 ( struct V_621 * V_622 ,
struct V_57 * V_67 )
{
struct V_1 * V_2 = V_622 -> V_146 ;
int V_107 = V_67 -> V_86 + V_622 -> V_624 ;
F_260 ( V_2 , V_67 ) ;
F_247 ( 10000 , 20000 ) ;
F_216 ( V_2 , ( ( T_6 ) 1 << V_107 ) ) ;
F_334 ( V_67 ) ;
V_67 -> V_145 = NULL ;
}
static int F_337 ( struct V_54 * V_625 ,
struct V_621 * V_626 )
{
struct V_1 * V_2 = V_626 -> V_146 ;
unsigned int V_627 = V_626 -> V_624 ;
unsigned int V_628 = V_626 -> V_629 ;
int V_48 ;
F_338 ( V_625 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_623 ; V_48 ++ ) {
F_336 ( V_626 , V_2 -> V_67 [ V_627 + V_48 ] ) ;
V_2 -> V_67 [ V_627 + V_48 ] -> V_55 = V_2 -> V_55 ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_623 ; V_48 ++ ) {
V_2 -> V_58 [ V_628 + V_48 ] -> V_145 = NULL ;
V_2 -> V_58 [ V_628 + V_48 ] -> V_55 = V_2 -> V_55 ;
}
return 0 ;
}
static int F_339 ( struct V_54 * V_625 ,
struct V_621 * V_626 )
{
struct V_1 * V_2 = V_626 -> V_146 ;
unsigned int V_627 , V_628 , V_376 ;
int V_48 , V_630 , V_17 = 0 ;
if ( ! F_14 ( V_626 -> V_482 , & V_2 -> V_631 ) )
return 0 ;
V_630 = V_626 -> V_482 * V_2 -> V_623 ;
F_340 ( V_625 , L_92 ,
V_626 -> V_482 , V_2 -> V_632 ,
V_630 , V_630 + V_2 -> V_623 ,
V_2 -> V_631 ) ;
V_626 -> V_55 = V_625 ;
V_626 -> V_624 = V_627 = V_630 ;
V_626 -> V_629 = V_628 = V_630 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_623 ; V_48 ++ )
F_336 ( V_626 , V_2 -> V_67 [ V_627 + V_48 ] ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_623 ; V_48 ++ ) {
V_2 -> V_67 [ V_627 + V_48 ] -> V_55 = V_625 ;
V_2 -> V_67 [ V_627 + V_48 ] -> V_145 = V_626 ;
F_262 ( V_2 , V_2 -> V_67 [ V_627 + V_48 ] ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_623 ; V_48 ++ ) {
V_2 -> V_58 [ V_628 + V_48 ] -> V_55 = V_625 ;
V_2 -> V_58 [ V_628 + V_48 ] -> V_145 = V_626 ;
}
V_376 = F_341 (unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues) ;
V_17 = F_342 ( V_625 , V_376 ) ;
if ( V_17 )
goto V_633;
V_17 = F_343 ( V_625 , V_376 ) ;
if ( V_17 )
goto V_633;
if ( F_344 ( V_625 -> V_634 ) )
F_290 ( V_2 , V_625 -> V_634 , V_626 -> V_482 ) ;
F_333 ( V_626 ) ;
F_332 ( V_625 , V_626 -> V_482 , V_2 ) ;
return V_17 ;
V_633:
F_337 ( V_625 , V_626 ) ;
return V_17 ;
}
static void F_345 ( struct V_1 * V_2 )
{
struct V_54 * V_95 ;
struct V_635 * V_636 ;
int V_17 ;
F_346 (adapter->netdev, upper, iter) {
if ( F_347 ( V_95 ) ) {
struct V_637 * V_638 = F_89 ( V_95 ) ;
struct V_621 * V_622 = V_638 -> V_639 ;
if ( V_638 -> V_639 ) {
V_17 = F_339 ( V_95 , V_622 ) ;
if ( V_17 )
continue;
}
}
}
}
static void F_348 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
F_324 ( V_2 ) ;
#ifdef F_349
F_307 ( V_2 ) ;
#endif
F_267 ( V_2 ) ;
F_299 ( V_2 -> V_55 ) ;
F_280 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
V_14 -> V_108 . V_357 . V_640 ( V_14 ) ;
break;
default:
break;
}
if ( V_2 -> V_137 & V_384 ) {
F_350 ( & V_2 -> V_14 ,
V_2 -> V_608 ) ;
} else if ( V_2 -> V_137 & V_607 ) {
F_351 ( & V_2 -> V_14 ,
V_2 -> V_608 ) ;
F_325 ( V_2 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
V_14 -> V_108 . V_357 . V_641 ( V_14 ) ;
break;
default:
break;
}
#ifdef F_148
F_352 ( V_2 ) ;
#endif
F_250 ( V_2 ) ;
F_275 ( V_2 ) ;
F_345 ( V_2 ) ;
}
static inline bool F_353 ( struct V_15 * V_14 )
{
switch ( V_14 -> V_360 . type ) {
case V_642 :
case V_643 :
case V_644 :
case V_645 :
case V_646 :
case V_647 :
case V_648 :
case V_649 :
case V_650 :
case V_651 :
case V_652 :
case V_653 :
case V_654 :
return true ;
case V_655 :
if ( V_14 -> V_108 . type == V_109 )
return true ;
default:
return false ;
}
}
static void F_354 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_108 . type == V_109 )
V_2 -> V_152 |= V_656 ;
V_2 -> V_152 |= V_368 ;
}
static int F_355 ( struct V_15 * V_14 )
{
T_1 V_20 ;
bool V_657 , V_359 = false ;
T_1 V_658 = V_659 ;
if ( V_14 -> V_108 . V_357 . V_358 )
V_658 = V_14 -> V_108 . V_357 . V_358 ( V_14 , & V_20 , & V_359 , false ) ;
if ( V_658 )
return V_658 ;
V_20 = V_14 -> V_360 . V_660 ;
if ( ( ! V_20 ) && ( V_14 -> V_108 . V_357 . V_661 ) )
V_658 = V_14 -> V_108 . V_357 . V_661 ( V_14 , & V_20 ,
& V_657 ) ;
if ( V_658 )
return V_658 ;
if ( V_14 -> V_108 . V_357 . V_662 )
V_658 = V_14 -> V_108 . V_357 . V_662 ( V_14 , V_20 , V_359 ) ;
return V_658 ;
}
static void F_356 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_663 = 0 ;
if ( V_2 -> V_137 & V_408 ) {
V_663 = V_664 | V_665 |
V_666 ;
V_663 |= V_667 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
F_71 ( V_14 , V_668 , V_669 ) ;
break;
case V_111 :
case V_112 :
default:
F_71 ( V_14 , F_357 ( 0 ) , 0xFFFFFFFF ) ;
F_71 ( V_14 , F_357 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_71 ( V_14 , V_668 , V_669 ) ;
}
if ( V_2 -> V_137 & V_429 ) {
V_663 &= ~ V_670 ;
switch ( V_2 -> V_434 [ V_501 ] . V_115 ) {
case V_502 :
V_663 |= V_671 ;
break;
case V_504 :
V_663 |= V_672 ;
break;
default:
V_663 |= V_673 ;
break;
}
}
if ( V_2 -> V_152 & V_352 ) {
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_663 |= V_674 ;
break;
case V_112 :
V_663 |= V_379 ;
break;
default:
break;
}
}
if ( V_2 -> V_137 & V_363 )
V_663 |= V_675 ;
if ( V_14 -> V_108 . type == V_111 ) {
V_663 |= V_675 ;
V_663 |= V_676 ;
}
F_71 ( V_14 , V_677 , V_663 ) ;
}
static void F_358 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 ;
T_1 V_100 ;
F_72 ( V_2 ) ;
F_356 ( V_2 ) ;
if ( V_2 -> V_137 & V_408 )
F_201 ( V_2 ) ;
else
F_241 ( V_2 ) ;
if ( V_14 -> V_108 . V_357 . V_678 )
V_14 -> V_108 . V_357 . V_678 ( V_14 ) ;
F_33 () ;
F_34 ( V_33 , & V_2 -> V_34 ) ;
F_301 ( V_2 ) ;
if ( F_353 ( V_14 ) ) {
F_354 ( V_2 ) ;
} else {
V_17 = F_355 ( V_14 ) ;
if ( V_17 )
F_102 ( V_170 , L_93 , V_17 ) ;
}
F_37 ( V_14 , V_365 ) ;
F_218 ( V_2 , true , true ) ;
if ( V_2 -> V_137 & V_363 ) {
T_1 V_679 = F_37 ( V_14 , V_680 ) ;
if ( V_679 & V_681 )
F_208 ( V_154 , L_73 ) ;
}
V_2 -> V_137 |= V_371 ;
V_2 -> V_372 = V_169 ;
F_359 ( & V_2 -> V_682 , V_169 ) ;
V_100 = F_37 ( V_14 , V_101 ) ;
V_100 |= V_683 ;
F_71 ( V_14 , V_101 , V_100 ) ;
}
void F_360 ( struct V_1 * V_2 )
{
F_361 ( F_362 () ) ;
V_2 -> V_55 -> V_74 = V_169 ;
while ( F_15 ( V_684 , & V_2 -> V_34 ) )
F_247 ( 1000 , 2000 ) ;
F_363 ( V_2 ) ;
if ( V_2 -> V_137 & V_429 )
F_364 ( 2000 ) ;
F_365 ( V_2 ) ;
F_34 ( V_684 , & V_2 -> V_34 ) ;
}
void F_365 ( struct V_1 * V_2 )
{
F_348 ( V_2 ) ;
F_358 ( V_2 ) ;
}
void F_366 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_55 = V_2 -> V_55 ;
int V_17 ;
T_4 V_685 [ V_557 ] ;
if ( F_22 ( V_14 -> V_39 ) )
return;
while ( F_15 ( V_686 , & V_2 -> V_34 ) )
F_247 ( 1000 , 2000 ) ;
V_2 -> V_152 &= ~ ( V_656 |
V_368 ) ;
V_2 -> V_137 &= ~ V_369 ;
V_17 = V_14 -> V_108 . V_357 . V_687 ( V_14 ) ;
switch ( V_17 ) {
case 0 :
case V_688 :
case V_689 :
break;
case V_690 :
F_18 ( L_94 ) ;
break;
case V_691 :
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
F_34 ( V_686 , & V_2 -> V_34 ) ;
memcpy ( V_685 , & V_2 -> V_550 [ 0 ] . V_553 , V_55 -> V_692 ) ;
F_287 ( V_2 ) ;
F_289 ( V_2 , V_685 ) ;
if ( V_14 -> V_108 . V_693 )
V_14 -> V_108 . V_357 . V_694 ( V_14 , F_266 ( 0 ) ) ;
if ( F_14 ( V_695 , & V_2 -> V_34 ) )
F_367 ( V_2 ) ;
}
static void F_368 ( struct V_57 * V_58 )
{
struct V_59 * V_78 ;
unsigned long V_296 ;
T_2 V_48 ;
if ( ! V_58 -> V_78 )
return;
for ( V_48 = 0 ; V_48 < V_58 -> V_88 ; V_48 ++ ) {
V_78 = & V_58 -> V_78 [ V_48 ] ;
F_77 ( V_58 , V_78 ) ;
}
F_369 ( F_106 ( V_58 ) ) ;
V_296 = sizeof( struct V_59 ) * V_58 -> V_88 ;
memset ( V_58 -> V_78 , 0 , V_296 ) ;
memset ( V_58 -> V_87 , 0 , V_58 -> V_296 ) ;
V_58 -> V_80 = 0 ;
V_58 -> V_79 = 0 ;
}
static void F_370 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
F_334 ( V_2 -> V_67 [ V_48 ] ) ;
}
static void F_371 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_368 ( V_2 -> V_58 [ V_48 ] ) ;
}
static void F_372 ( struct V_1 * V_2 )
{
struct V_611 * V_612 ;
struct V_613 * V_614 ;
F_326 ( & V_2 -> V_615 ) ;
F_329 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_373 ( & V_614 -> V_696 ) ;
F_235 ( V_614 ) ;
}
V_2 -> V_697 = 0 ;
F_331 ( & V_2 -> V_615 ) ;
}
void F_363 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_95 ;
struct V_635 * V_636 ;
T_1 V_180 ;
int V_48 ;
if ( F_15 ( V_33 , & V_2 -> V_34 ) )
return;
V_180 = F_37 ( V_14 , V_534 ) ;
F_71 ( V_14 , V_534 , V_180 & ~ V_535 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
F_260 ( V_2 , V_2 -> V_67 [ V_48 ] ) ;
F_247 ( 10000 , 20000 ) ;
F_338 ( V_55 ) ;
F_374 ( V_55 ) ;
F_375 ( V_55 ) ;
F_346 (adapter->netdev, upper, iter) {
if ( F_347 ( V_95 ) ) {
struct V_637 * V_235 = F_89 ( V_95 ) ;
if ( V_235 -> V_639 ) {
F_338 ( V_95 ) ;
F_374 ( V_95 ) ;
F_375 ( V_95 ) ;
}
}
}
F_239 ( V_2 ) ;
F_304 ( V_2 ) ;
V_2 -> V_152 &= ~ ( V_385 |
V_153 ) ;
V_2 -> V_137 &= ~ V_371 ;
F_376 ( & V_2 -> V_682 ) ;
if ( V_2 -> V_324 ) {
F_71 ( & V_2 -> V_14 , V_326 , 0 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_324 ; V_48 ++ )
V_2 -> V_509 [ V_48 ] . V_698 = false ;
F_377 ( V_2 ) ;
F_378 ( V_2 ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
T_4 V_147 = V_2 -> V_58 [ V_48 ] -> V_147 ;
F_71 ( V_14 , F_50 ( V_147 ) , V_699 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
F_71 ( V_14 , V_445 ,
( F_37 ( V_14 , V_445 ) &
~ V_446 ) ) ;
break;
default:
break;
}
if ( ! F_379 ( V_2 -> V_9 ) )
F_366 ( V_2 ) ;
if ( V_14 -> V_108 . V_357 . V_700 )
V_14 -> V_108 . V_357 . V_700 ( V_14 ) ;
F_371 ( V_2 ) ;
F_370 ( V_2 ) ;
#ifdef F_226
F_122 ( V_2 ) ;
#endif
}
static void F_380 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
F_92 ( V_2 ) ;
}
static int F_381 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_198 , V_701 ;
T_1 V_702 ;
#ifdef F_349
int V_49 ;
struct V_703 * V_132 ;
#endif
V_14 -> V_704 = V_9 -> V_705 ;
V_14 -> V_21 = V_9 -> V_188 ;
V_14 -> V_706 = V_9 -> V_707 ;
V_14 -> V_708 = V_9 -> V_709 ;
V_14 -> V_710 = V_9 -> V_711 ;
V_198 = F_341 ( int , V_712 , F_382 () ) ;
V_2 -> V_434 [ V_435 ] . V_713 = V_198 ;
V_2 -> V_152 |= V_714 ;
V_2 -> V_152 |= V_523 ;
V_2 -> V_715 = V_716 ;
V_2 -> V_419 = 20 ;
V_701 = F_341 ( int , V_717 , F_382 () ) ;
V_2 -> V_434 [ V_718 ] . V_713 = V_701 ;
V_2 -> V_608 = V_719 ;
#ifdef F_226
V_2 -> V_137 |= V_190 ;
#endif
#ifdef F_148
V_2 -> V_137 |= V_720 ;
V_2 -> V_137 &= ~ V_515 ;
#ifdef F_349
V_2 -> V_600 . V_601 = V_721 ;
#endif
#endif
V_2 -> V_550 = F_383 ( sizeof( struct V_722 ) *
V_14 -> V_108 . V_549 ,
V_221 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_2 -> V_152 &= ~ V_714 ;
V_2 -> V_152 &= ~ V_523 ;
if ( V_14 -> V_21 == V_723 )
V_2 -> V_137 |= V_363 ;
V_2 -> V_715 = V_724 ;
V_2 -> V_434 [ V_718 ] . V_713 = 0 ;
V_2 -> V_419 = 0 ;
V_2 -> V_608 = 0 ;
#ifdef F_148
V_2 -> V_137 &= ~ V_720 ;
V_2 -> V_137 &= ~ V_515 ;
#ifdef F_349
V_2 -> V_600 . V_601 = 0 ;
#endif
#endif
break;
case V_111 :
if ( V_14 -> V_21 == V_354 )
V_2 -> V_152 |= V_352 ;
break;
case V_112 :
V_702 = F_37 ( V_14 , V_725 ) ;
if ( V_702 & V_726 )
V_2 -> V_152 |= V_352 ;
break;
default:
break;
}
#ifdef F_148
F_384 ( & V_2 -> V_600 . V_727 ) ;
#endif
F_384 ( & V_2 -> V_615 ) ;
#ifdef F_349
switch ( V_14 -> V_108 . type ) {
case V_112 :
V_2 -> V_134 . V_728 . V_729 = V_730 ;
V_2 -> V_134 . V_728 . V_731 = V_730 ;
break;
default:
V_2 -> V_134 . V_728 . V_729 = V_605 ;
V_2 -> V_134 . V_728 . V_731 = V_605 ;
break;
}
for ( V_49 = 0 ; V_49 < V_605 ; V_49 ++ ) {
V_132 = & V_2 -> V_134 . V_732 [ V_49 ] ;
V_132 -> V_733 [ V_588 ] . V_734 = 0 ;
V_132 -> V_733 [ V_588 ] . V_735 = 12 + ( V_49 & 1 ) ;
V_132 -> V_733 [ V_589 ] . V_734 = 0 ;
V_132 -> V_733 [ V_589 ] . V_735 = 12 + ( V_49 & 1 ) ;
V_132 -> V_736 = V_737 ;
}
V_132 = & V_2 -> V_134 . V_732 [ 0 ] ;
V_132 -> V_733 [ V_588 ] . V_738 = 0xFF ;
V_132 -> V_733 [ V_589 ] . V_738 = 0xFF ;
V_2 -> V_134 . V_739 [ V_588 ] [ 0 ] = 100 ;
V_2 -> V_134 . V_739 [ V_589 ] [ 0 ] = 100 ;
V_2 -> V_134 . V_135 = false ;
V_2 -> V_740 = 0x00 ;
V_2 -> V_586 = V_741 | V_587 ;
memcpy ( & V_2 -> V_742 , & V_2 -> V_134 ,
sizeof( V_2 -> V_742 ) ) ;
#endif
V_14 -> V_123 . V_743 = V_125 ;
V_14 -> V_123 . V_124 = V_125 ;
F_323 ( V_2 ) ;
V_14 -> V_123 . V_744 = V_745 ;
V_14 -> V_123 . V_746 = true ;
V_14 -> V_123 . V_747 = F_385 ( V_14 ) ;
#ifdef F_282
if ( V_748 > 0 )
F_11 ( L_102 ) ;
if ( V_14 -> V_108 . type != V_109 ) {
if ( V_748 > V_749 ) {
V_2 -> V_324 = 0 ;
F_11 ( L_103 ) ;
} else {
V_2 -> V_324 = V_748 ;
}
}
#endif
V_2 -> V_399 = 1 ;
V_2 -> V_750 = 1 ;
V_2 -> V_751 = V_752 ;
V_2 -> V_753 = V_754 ;
V_2 -> V_755 = V_756 ;
if ( F_386 ( V_14 ) ) {
F_18 ( L_104 ) ;
return - V_757 ;
}
F_245 ( 0 , & V_2 -> V_631 ) ;
F_245 ( V_33 , & V_2 -> V_34 ) ;
return 0 ;
}
int F_387 ( struct V_57 * V_58 )
{
struct V_188 * V_73 = V_58 -> V_73 ;
int V_758 = F_388 ( V_73 ) ;
int V_759 = - 1 ;
int V_296 ;
V_296 = sizeof( struct V_59 ) * V_58 -> V_88 ;
if ( V_58 -> V_156 )
V_759 = V_58 -> V_156 -> V_759 ;
V_58 -> V_78 = F_389 ( V_296 , V_759 ) ;
if ( ! V_58 -> V_78 )
V_58 -> V_78 = F_390 ( V_296 ) ;
if ( ! V_58 -> V_78 )
goto V_17;
F_391 ( & V_58 -> V_167 ) ;
V_58 -> V_296 = V_58 -> V_88 * sizeof( union V_61 ) ;
V_58 -> V_296 = F_171 ( V_58 -> V_296 , 4096 ) ;
F_392 ( V_73 , V_759 ) ;
V_58 -> V_87 = F_393 ( V_73 ,
V_58 -> V_296 ,
& V_58 -> V_81 ,
V_760 ) ;
F_392 ( V_73 , V_758 ) ;
if ( ! V_58 -> V_87 )
V_58 -> V_87 = F_393 ( V_73 , V_58 -> V_296 ,
& V_58 -> V_81 , V_760 ) ;
if ( ! V_58 -> V_87 )
goto V_17;
V_58 -> V_80 = 0 ;
V_58 -> V_79 = 0 ;
return 0 ;
V_17:
F_394 ( V_58 -> V_78 ) ;
V_58 -> V_78 = NULL ;
F_395 ( V_73 , L_105 ) ;
return - V_548 ;
}
static int F_396 ( struct V_1 * V_2 )
{
int V_48 , V_17 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
V_17 = F_387 ( V_2 -> V_58 [ V_48 ] ) ;
if ( ! V_17 )
continue;
F_102 ( V_170 , L_106 , V_48 ) ;
goto V_761;
}
return 0 ;
V_761:
while ( V_48 -- )
F_397 ( V_2 -> V_58 [ V_48 ] ) ;
return V_17 ;
}
int F_398 ( struct V_57 * V_67 )
{
struct V_188 * V_73 = V_67 -> V_73 ;
int V_758 = F_388 ( V_73 ) ;
int V_759 = - 1 ;
int V_296 ;
V_296 = sizeof( struct V_70 ) * V_67 -> V_88 ;
if ( V_67 -> V_156 )
V_759 = V_67 -> V_156 -> V_759 ;
V_67 -> V_71 = F_389 ( V_296 , V_759 ) ;
if ( ! V_67 -> V_71 )
V_67 -> V_71 = F_390 ( V_296 ) ;
if ( ! V_67 -> V_71 )
goto V_17;
F_391 ( & V_67 -> V_167 ) ;
V_67 -> V_296 = V_67 -> V_88 * sizeof( union V_68 ) ;
V_67 -> V_296 = F_171 ( V_67 -> V_296 , 4096 ) ;
F_392 ( V_73 , V_759 ) ;
V_67 -> V_87 = F_393 ( V_73 ,
V_67 -> V_296 ,
& V_67 -> V_81 ,
V_760 ) ;
F_392 ( V_73 , V_758 ) ;
if ( ! V_67 -> V_87 )
V_67 -> V_87 = F_393 ( V_73 , V_67 -> V_296 ,
& V_67 -> V_81 , V_760 ) ;
if ( ! V_67 -> V_87 )
goto V_17;
V_67 -> V_79 = 0 ;
V_67 -> V_80 = 0 ;
return 0 ;
V_17:
F_394 ( V_67 -> V_71 ) ;
V_67 -> V_71 = NULL ;
F_395 ( V_73 , L_107 ) ;
return - V_548 ;
}
static int F_399 ( struct V_1 * V_2 )
{
int V_48 , V_17 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_17 = F_398 ( V_2 -> V_67 [ V_48 ] ) ;
if ( ! V_17 )
continue;
F_102 ( V_170 , L_108 , V_48 ) ;
goto V_762;
}
#ifdef F_148
V_17 = F_400 ( V_2 ) ;
if ( ! V_17 )
#endif
return 0 ;
V_762:
while ( V_48 -- )
F_401 ( V_2 -> V_67 [ V_48 ] ) ;
return V_17 ;
}
void F_397 ( struct V_57 * V_58 )
{
F_368 ( V_58 ) ;
F_394 ( V_58 -> V_78 ) ;
V_58 -> V_78 = NULL ;
if ( ! V_58 -> V_87 )
return;
F_402 ( V_58 -> V_73 , V_58 -> V_296 ,
V_58 -> V_87 , V_58 -> V_81 ) ;
V_58 -> V_87 = NULL ;
}
static void F_403 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
if ( V_2 -> V_58 [ V_48 ] -> V_87 )
F_397 ( V_2 -> V_58 [ V_48 ] ) ;
}
void F_401 ( struct V_57 * V_67 )
{
F_334 ( V_67 ) ;
F_394 ( V_67 -> V_71 ) ;
V_67 -> V_71 = NULL ;
if ( ! V_67 -> V_87 )
return;
F_402 ( V_67 -> V_73 , V_67 -> V_296 ,
V_67 -> V_87 , V_67 -> V_81 ) ;
V_67 -> V_87 = NULL ;
}
static void F_404 ( struct V_1 * V_2 )
{
int V_48 ;
#ifdef F_148
F_405 ( V_2 ) ;
#endif
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
if ( V_2 -> V_67 [ V_48 ] -> V_87 )
F_401 ( V_2 -> V_67 [ V_48 ] ) ;
}
static int F_406 ( struct V_54 * V_55 , int V_763 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_511 = V_763 + V_244 + V_512 ;
if ( ( V_763 < 68 ) || ( V_511 > V_764 ) )
return - V_559 ;
if ( ( V_2 -> V_137 & V_429 ) &&
( V_2 -> V_14 . V_108 . type == V_111 ) &&
( V_511 > ( V_517 + V_512 ) ) )
F_93 ( V_170 , L_109 ) ;
F_104 ( V_170 , L_110 , V_55 -> V_312 , V_763 ) ;
V_55 -> V_312 = V_763 ;
if ( F_57 ( V_55 ) )
F_360 ( V_2 ) ;
return 0 ;
}
static int F_407 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_17 , V_376 ;
if ( F_14 ( V_765 , & V_2 -> V_34 ) )
return - V_766 ;
F_374 ( V_55 ) ;
V_17 = F_396 ( V_2 ) ;
if ( V_17 )
goto V_761;
V_17 = F_399 ( V_2 ) ;
if ( V_17 )
goto V_762;
F_348 ( V_2 ) ;
V_17 = F_237 ( V_2 ) ;
if ( V_17 )
goto V_767;
if ( V_2 -> V_632 > 1 )
V_376 = V_2 -> V_623 ;
else
V_376 = V_2 -> V_77 ;
V_17 = F_342 ( V_55 , V_376 ) ;
if ( V_17 )
goto V_768;
if ( V_2 -> V_632 > 1 &&
V_2 -> V_93 > V_769 )
V_376 = V_769 ;
else
V_376 = V_2 -> V_93 ;
V_17 = F_343 ( V_55 , V_376 ) ;
if ( V_17 )
goto V_768;
F_408 ( V_2 ) ;
F_358 ( V_2 ) ;
return 0 ;
V_768:
F_238 ( V_2 ) ;
V_767:
F_404 ( V_2 ) ;
V_762:
F_403 ( V_2 ) ;
V_761:
F_366 ( V_2 ) ;
return V_17 ;
}
static void F_409 ( struct V_1 * V_2 )
{
F_410 ( V_2 ) ;
F_363 ( V_2 ) ;
F_238 ( V_2 ) ;
F_403 ( V_2 ) ;
F_404 ( V_2 ) ;
}
static int F_411 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
F_412 ( V_2 ) ;
F_409 ( V_2 ) ;
F_372 ( V_2 ) ;
F_70 ( V_2 ) ;
return 0 ;
}
static int F_413 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_414 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
T_1 V_17 ;
V_2 -> V_14 . V_39 = V_2 -> V_417 ;
F_415 ( V_9 , V_770 ) ;
F_416 ( V_9 ) ;
F_417 ( V_9 ) ;
V_17 = F_418 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_111 ) ;
return V_17 ;
}
F_33 () ;
F_34 ( V_771 , & V_2 -> V_34 ) ;
F_419 ( V_9 ) ;
F_420 ( V_9 , false ) ;
F_366 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_772 , ~ 0 ) ;
F_421 () ;
V_17 = F_422 ( V_2 ) ;
if ( ! V_17 && F_57 ( V_55 ) )
V_17 = F_407 ( V_55 ) ;
F_423 () ;
if ( V_17 )
return V_17 ;
F_424 ( V_55 ) ;
return 0 ;
}
static int F_425 ( struct V_5 * V_9 , bool * V_773 )
{
struct V_1 * V_2 = F_414 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_774 , V_563 ;
T_1 V_775 = V_2 -> V_776 ;
#ifdef F_426
int V_777 = 0 ;
#endif
F_427 ( V_55 ) ;
F_421 () ;
if ( F_57 ( V_55 ) )
F_409 ( V_2 ) ;
F_423 () ;
F_428 ( V_2 ) ;
#ifdef F_426
V_777 = F_417 ( V_9 ) ;
if ( V_777 )
return V_777 ;
#endif
if ( V_14 -> V_108 . V_357 . V_778 )
V_14 -> V_108 . V_357 . V_778 ( V_14 ) ;
if ( V_775 ) {
F_299 ( V_55 ) ;
if ( V_14 -> V_108 . V_357 . V_678 )
V_14 -> V_108 . V_357 . V_678 ( V_14 ) ;
if ( V_775 & V_779 ) {
V_563 = F_37 ( V_14 , V_567 ) ;
V_563 |= V_573 ;
F_71 ( V_14 , V_567 , V_563 ) ;
}
V_774 = F_37 ( V_14 , V_780 ) ;
V_774 |= V_781 ;
F_71 ( V_14 , V_780 , V_774 ) ;
F_71 ( V_14 , V_782 , V_775 ) ;
} else {
F_71 ( V_14 , V_783 , 0 ) ;
F_71 ( V_14 , V_782 , 0 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_109 :
F_420 ( V_9 , false ) ;
break;
case V_111 :
case V_112 :
F_420 ( V_9 , ! ! V_775 ) ;
break;
default:
break;
}
* V_773 = ! ! V_775 ;
F_70 ( V_2 ) ;
if ( ! F_15 ( V_771 , & V_2 -> V_34 ) )
F_429 ( V_9 ) ;
return 0 ;
}
static int F_430 ( struct V_5 * V_9 , T_13 V_34 )
{
int V_777 ;
bool V_784 ;
V_777 = F_425 ( V_9 , & V_784 ) ;
if ( V_777 )
return V_777 ;
if ( V_784 ) {
F_431 ( V_9 ) ;
} else {
F_420 ( V_9 , false ) ;
F_415 ( V_9 , V_785 ) ;
}
return 0 ;
}
static void F_432 ( struct V_5 * V_9 )
{
bool V_784 ;
F_425 ( V_9 , & V_784 ) ;
if ( V_786 == V_787 ) {
F_420 ( V_9 , V_784 ) ;
F_415 ( V_9 , V_785 ) ;
}
}
void F_433 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_120 * V_121 = & V_2 -> V_122 ;
T_6 V_788 = 0 ;
T_1 V_48 , V_789 = 0 , V_790 , V_791 , V_792 , V_793 , V_794 ;
T_6 V_280 = 0 , V_172 = 0 , V_795 = 0 ;
T_6 V_224 = 0 , V_305 = 0 ;
T_6 V_168 = 0 , V_142 = 0 , V_796 = 0 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_684 , & V_2 -> V_34 ) )
return;
if ( V_2 -> V_152 & V_523 ) {
T_6 V_264 = 0 ;
T_6 V_265 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_264 += V_2 -> V_67 [ V_48 ] -> V_210 . V_264 ;
V_265 += V_2 -> V_67 [ V_48 ] -> V_210 . V_265 ;
}
V_2 -> V_797 = V_264 ;
V_2 -> V_798 = V_265 ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_67 = V_2 -> V_67 [ V_48 ] ;
V_280 += V_67 -> V_210 . V_280 ;
V_224 += V_67 -> V_210 . V_224 ;
V_305 += V_67 -> V_210 . V_305 ;
V_796 += V_67 -> V_210 . V_211 ;
V_168 += V_67 -> V_122 . V_168 ;
V_142 += V_67 -> V_122 . V_142 ;
}
V_2 -> V_280 = V_280 ;
V_2 -> V_224 = V_224 ;
V_2 -> V_305 = V_305 ;
V_2 -> V_796 = V_796 ;
V_55 -> V_122 . V_799 = V_168 ;
V_55 -> V_122 . V_800 = V_142 ;
V_168 = 0 ;
V_142 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_58 = V_2 -> V_58 [ V_48 ] ;
V_172 += V_58 -> V_150 . V_172 ;
V_795 += V_58 -> V_150 . V_795 ;
V_168 += V_58 -> V_122 . V_168 ;
V_142 += V_58 -> V_122 . V_142 ;
}
V_2 -> V_172 = V_172 ;
V_2 -> V_795 = V_795 ;
V_55 -> V_122 . V_801 = V_168 ;
V_55 -> V_122 . V_802 = V_142 ;
V_121 -> V_803 += F_37 ( V_14 , V_804 ) ;
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ ) {
V_790 = F_37 ( V_14 , F_434 ( V_48 ) ) ;
V_789 += V_790 ;
V_121 -> V_790 [ V_48 ] += V_790 ;
V_788 += V_121 -> V_790 [ V_48 ] ;
V_121 -> V_805 [ V_48 ] += F_37 ( V_14 , F_435 ( V_48 ) ) ;
V_121 -> V_806 [ V_48 ] += F_37 ( V_14 , F_436 ( V_48 ) ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_121 -> V_807 [ V_48 ] += F_37 ( V_14 , F_437 ( V_48 ) ) ;
V_121 -> V_808 [ V_48 ] += F_37 ( V_14 , F_438 ( V_48 ) ) ;
V_121 -> V_809 [ V_48 ] += F_37 ( V_14 , F_439 ( V_48 ) ) ;
V_121 -> V_810 [ V_48 ] +=
F_37 ( V_14 , F_440 ( V_48 ) ) ;
break;
case V_111 :
case V_112 :
V_121 -> V_810 [ V_48 ] +=
F_37 ( V_14 , F_441 ( V_48 ) ) ;
break;
default:
break;
}
}
for ( V_48 = 0 ; V_48 < 16 ; V_48 ++ ) {
V_121 -> V_811 [ V_48 ] += F_37 ( V_14 , F_442 ( V_48 ) ) ;
V_121 -> V_812 [ V_48 ] += F_37 ( V_14 , F_443 ( V_48 ) ) ;
if ( ( V_14 -> V_108 . type == V_111 ) ||
( V_14 -> V_108 . type == V_112 ) ) {
V_121 -> V_808 [ V_48 ] += F_37 ( V_14 , F_444 ( V_48 ) ) ;
F_37 ( V_14 , F_445 ( V_48 ) ) ;
V_121 -> V_809 [ V_48 ] += F_37 ( V_14 , F_446 ( V_48 ) ) ;
F_37 ( V_14 , F_447 ( V_48 ) ) ;
}
}
V_121 -> V_813 += F_37 ( V_14 , V_814 ) ;
V_121 -> V_813 -= V_789 ;
F_83 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_121 -> V_815 += F_37 ( V_14 , V_816 ) ;
V_121 -> V_817 += F_37 ( V_14 , V_818 ) ;
V_121 -> V_819 += F_37 ( V_14 , V_820 ) ;
V_121 -> V_821 += F_37 ( V_14 , V_822 ) ;
break;
case V_112 :
V_121 -> V_823 += F_37 ( V_14 , V_824 ) ;
V_121 -> V_825 += F_37 ( V_14 , V_826 ) ;
V_121 -> V_827 += F_37 ( V_14 , V_828 ) ;
V_121 -> V_829 += F_37 ( V_14 , V_830 ) ;
case V_111 :
for ( V_48 = 0 ; V_48 < 16 ; V_48 ++ )
V_2 -> V_831 +=
F_37 ( V_14 , F_448 ( V_48 ) ) ;
V_121 -> V_817 += F_37 ( V_14 , V_832 ) ;
F_37 ( V_14 , V_818 ) ;
V_121 -> V_819 += F_37 ( V_14 , V_833 ) ;
F_37 ( V_14 , V_820 ) ;
V_121 -> V_821 += F_37 ( V_14 , V_834 ) ;
F_37 ( V_14 , V_822 ) ;
V_121 -> V_815 += F_37 ( V_14 , V_835 ) ;
V_121 -> V_836 += F_37 ( V_14 , V_837 ) ;
V_121 -> V_838 += F_37 ( V_14 , V_839 ) ;
#ifdef F_148
V_121 -> V_840 += F_37 ( V_14 , V_841 ) ;
V_121 -> V_842 += F_37 ( V_14 , V_843 ) ;
V_121 -> V_844 += F_37 ( V_14 , V_845 ) ;
V_121 -> V_846 += F_37 ( V_14 , V_847 ) ;
V_121 -> V_848 += F_37 ( V_14 , V_849 ) ;
V_121 -> V_850 += F_37 ( V_14 , V_851 ) ;
if ( V_2 -> V_600 . V_852 ) {
struct V_853 * V_600 = & V_2 -> V_600 ;
struct V_854 * V_852 ;
unsigned int V_173 ;
T_6 V_855 = 0 , V_856 = 0 ;
F_449 (cpu) {
V_852 = F_450 ( V_600 -> V_852 , V_173 ) ;
V_855 += V_852 -> V_855 ;
V_856 += V_852 -> V_856 ;
}
V_121 -> V_857 = V_855 ;
V_121 -> V_858 = V_856 ;
}
#endif
break;
default:
break;
}
V_791 = F_37 ( V_14 , V_859 ) ;
V_121 -> V_791 += V_791 ;
V_121 -> V_860 += F_37 ( V_14 , V_861 ) ;
if ( V_14 -> V_108 . type == V_109 )
V_121 -> V_860 -= V_791 ;
V_121 -> V_862 += F_37 ( V_14 , V_863 ) ;
V_121 -> V_864 += F_37 ( V_14 , V_865 ) ;
V_121 -> V_866 += F_37 ( V_14 , V_867 ) ;
V_121 -> V_868 += F_37 ( V_14 , V_869 ) ;
V_121 -> V_870 += F_37 ( V_14 , V_871 ) ;
V_121 -> V_872 += F_37 ( V_14 , V_873 ) ;
V_121 -> V_874 += F_37 ( V_14 , V_875 ) ;
V_121 -> V_876 += F_37 ( V_14 , V_877 ) ;
V_792 = F_37 ( V_14 , V_878 ) ;
V_121 -> V_879 += V_792 ;
V_793 = F_37 ( V_14 , V_880 ) ;
V_121 -> V_881 += V_793 ;
V_121 -> V_882 += F_37 ( V_14 , V_883 ) ;
V_121 -> V_884 += F_37 ( V_14 , V_885 ) ;
V_794 = V_792 + V_793 ;
V_121 -> V_882 -= V_794 ;
V_121 -> V_884 -= V_794 ;
V_121 -> V_819 -= ( V_794 * ( V_886 + V_512 ) ) ;
V_121 -> V_887 += F_37 ( V_14 , V_888 ) ;
V_121 -> V_889 += F_37 ( V_14 , V_890 ) ;
V_121 -> V_891 += F_37 ( V_14 , V_892 ) ;
V_121 -> V_893 += F_37 ( V_14 , V_894 ) ;
V_121 -> V_895 += F_37 ( V_14 , V_896 ) ;
V_121 -> V_895 -= V_794 ;
V_121 -> V_897 += F_37 ( V_14 , V_898 ) ;
V_121 -> V_899 += F_37 ( V_14 , V_900 ) ;
V_121 -> V_901 += F_37 ( V_14 , V_902 ) ;
V_121 -> V_903 += F_37 ( V_14 , V_904 ) ;
V_121 -> V_905 += F_37 ( V_14 , V_906 ) ;
V_121 -> V_907 += F_37 ( V_14 , V_908 ) ;
V_55 -> V_122 . V_909 = V_121 -> V_860 ;
V_55 -> V_122 . V_910 = V_121 -> V_803 + V_121 -> V_876 ;
V_55 -> V_122 . V_911 = 0 ;
V_55 -> V_122 . V_912 = V_121 -> V_876 ;
V_55 -> V_122 . V_913 = V_121 -> V_803 ;
V_55 -> V_122 . V_914 = V_788 ;
}
static void F_451 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
if ( ! ( V_2 -> V_152 & V_385 ) )
return;
V_2 -> V_152 &= ~ V_385 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
if ( ! ( V_2 -> V_137 & V_384 ) )
return;
V_2 -> V_915 ++ ;
if ( F_452 ( V_14 ) == 0 ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_245 ( V_393 ,
& ( V_2 -> V_58 [ V_48 ] -> V_34 ) ) ;
F_71 ( V_14 , V_375 , V_386 ) ;
} else {
F_102 ( V_170 , L_112
L_113 ) ;
}
}
static void F_453 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_916 = 0 ;
int V_48 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_684 , & V_2 -> V_34 ) )
return;
if ( F_108 ( V_2 -> V_55 ) ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_454 ( V_2 -> V_58 [ V_48 ] ) ;
}
if ( ! ( V_2 -> V_137 & V_408 ) ) {
F_71 ( V_14 , V_117 ,
( V_917 | V_918 ) ) ;
} else {
for ( V_48 = 0 ; V_48 < V_2 -> V_187 ; V_48 ++ ) {
struct V_155 * V_919 = V_2 -> V_156 [ V_48 ] ;
if ( V_919 -> V_316 . V_118 || V_919 -> V_160 . V_118 )
V_916 |= ( ( T_6 ) 1 << V_48 ) ;
}
}
F_75 ( V_2 , V_916 ) ;
}
static void F_455 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_920 = V_2 -> V_920 ;
bool V_359 = V_2 -> V_359 ;
bool V_133 = V_2 -> V_134 . V_135 ;
if ( ! ( V_2 -> V_137 & V_371 ) )
return;
if ( V_14 -> V_108 . V_357 . V_358 ) {
V_14 -> V_108 . V_357 . V_358 ( V_14 , & V_920 , & V_359 , false ) ;
} else {
V_920 = V_921 ;
V_359 = true ;
}
if ( V_2 -> V_136 )
V_133 |= ! ! ( V_2 -> V_136 -> V_133 ) ;
if ( V_359 && ! ( ( V_2 -> V_137 & V_138 ) && V_133 ) ) {
V_14 -> V_108 . V_357 . V_922 ( V_14 ) ;
F_456 ( V_2 ) ;
}
if ( V_359 ||
F_457 ( V_169 , ( V_2 -> V_372 +
V_923 ) ) ) {
V_2 -> V_137 &= ~ V_371 ;
F_71 ( V_14 , V_375 , V_374 ) ;
F_213 ( V_14 ) ;
}
V_2 -> V_359 = V_359 ;
V_2 -> V_920 = V_920 ;
}
static void F_458 ( struct V_1 * V_2 )
{
#ifdef F_349
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_924 V_925 = {
. V_926 = V_927 ,
. V_241 = 0 ,
} ;
T_4 V_601 = 0 ;
if ( V_2 -> V_586 & V_928 )
V_601 = F_459 ( V_55 , & V_925 ) ;
V_2 -> V_929 = ( V_601 > 1 ) ? ( F_460 ( V_601 ) - 1 ) : 0 ;
#endif
}
static void F_461 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_95 ;
struct V_635 * V_636 ;
T_1 V_920 = V_2 -> V_920 ;
bool V_930 , V_931 ;
if ( F_108 ( V_55 ) )
return;
V_2 -> V_152 &= ~ V_656 ;
switch ( V_14 -> V_108 . type ) {
case V_109 : {
T_1 V_932 = F_37 ( V_14 , V_567 ) ;
T_1 V_933 = F_37 ( V_14 , V_934 ) ;
V_930 = ! ! ( V_932 & V_935 ) ;
V_931 = ! ! ( V_933 & V_936 ) ;
}
break;
case V_112 :
case V_111 : {
T_1 V_937 = F_37 ( V_14 , V_938 ) ;
T_1 V_939 = F_37 ( V_14 , V_940 ) ;
V_930 = ! ! ( V_937 & V_941 ) ;
V_931 = ! ! ( V_939 & V_942 ) ;
}
break;
default:
V_931 = false ;
V_930 = false ;
break;
}
V_2 -> V_943 = V_169 ;
if ( F_14 ( V_695 , & V_2 -> V_34 ) )
F_462 ( V_2 ) ;
F_104 ( V_154 , L_114 ,
( V_920 == V_921 ?
L_115 :
( V_920 == V_944 ?
L_116 :
( V_920 == V_945 ?
L_117 :
L_118 ) ) ) ,
( ( V_930 && V_931 ) ? L_119 :
( V_930 ? L_120 :
( V_931 ? L_121 : L_122 ) ) ) ) ;
F_463 ( V_55 ) ;
F_464 ( V_2 ) ;
F_465 ( V_2 -> V_55 ) ;
F_421 () ;
F_346 (adapter->netdev, upper, iter) {
if ( F_347 ( V_95 ) ) {
struct V_637 * V_235 = F_89 ( V_95 ) ;
if ( V_235 -> V_639 )
F_465 ( V_95 ) ;
}
}
F_423 () ;
F_458 ( V_2 ) ;
F_377 ( V_2 ) ;
}
static void F_466 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_359 = false ;
V_2 -> V_920 = 0 ;
if ( ! F_108 ( V_55 ) )
return;
if ( F_353 ( V_14 ) && V_14 -> V_108 . type == V_109 )
V_2 -> V_152 |= V_656 ;
if ( F_14 ( V_695 , & V_2 -> V_34 ) )
F_462 ( V_2 ) ;
F_104 ( V_154 , L_123 ) ;
F_374 ( V_55 ) ;
F_377 ( V_2 ) ;
}
static void F_467 ( struct V_1 * V_2 )
{
int V_48 ;
int V_946 = 0 ;
if ( ! F_108 ( V_2 -> V_55 ) ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_58 = V_2 -> V_58 [ V_48 ] ;
if ( V_58 -> V_80 != V_58 -> V_79 ) {
V_946 = 1 ;
break;
}
}
if ( V_946 ) {
F_93 ( V_154 , L_124 ) ;
V_2 -> V_152 |= V_153 ;
}
}
}
static void F_468 ( struct V_1 * V_2 )
{
T_1 V_947 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ||
V_2 -> V_324 == 0 )
return;
V_947 = F_37 ( & V_2 -> V_14 , V_948 ) ;
if ( ! V_947 )
return;
F_93 ( V_154 , L_125 , V_947 ) ;
}
static void F_469 ( struct V_1 * V_2 )
{
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_684 , & V_2 -> V_34 ) )
return;
F_455 ( V_2 ) ;
if ( V_2 -> V_359 )
F_461 ( V_2 ) ;
else
F_466 ( V_2 ) ;
F_468 ( V_2 ) ;
F_433 ( V_2 ) ;
F_467 ( V_2 ) ;
}
static void F_470 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_3 V_17 ;
if ( ! ( V_2 -> V_152 & V_656 ) &&
! ( V_2 -> V_152 & V_368 ) )
return;
if ( F_15 ( V_686 , & V_2 -> V_34 ) )
return;
V_17 = V_14 -> V_360 . V_357 . V_949 ( V_14 ) ;
if ( V_17 == V_689 )
goto V_950;
if ( V_17 == V_688 ) {
V_2 -> V_152 |= V_368 ;
}
if ( V_17 )
goto V_950;
if ( ! ( V_2 -> V_152 & V_368 ) )
goto V_950;
V_2 -> V_152 &= ~ V_368 ;
if ( V_14 -> V_108 . type == V_109 )
V_17 = V_14 -> V_360 . V_357 . V_951 ( V_14 ) ;
else
V_17 = V_14 -> V_108 . V_357 . V_952 ( V_14 ) ;
if ( V_17 == V_689 )
goto V_950;
V_2 -> V_137 |= V_369 ;
F_104 ( V_170 , L_126 , V_14 -> V_360 . V_953 ) ;
V_950:
F_34 ( V_686 , & V_2 -> V_34 ) ;
if ( ( V_17 == V_689 ) &&
( V_2 -> V_55 -> V_954 == V_955 ) ) {
F_18 ( L_127
L_128 ) ;
F_18 ( L_129
L_130 ) ;
F_471 ( V_2 -> V_55 ) ;
}
}
static void F_472 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_20 ;
bool V_657 = false ;
if ( ! ( V_2 -> V_137 & V_369 ) )
return;
if ( F_15 ( V_686 , & V_2 -> V_34 ) )
return;
V_2 -> V_137 &= ~ V_369 ;
V_20 = V_14 -> V_360 . V_660 ;
if ( ( ! V_20 ) && ( V_14 -> V_108 . V_357 . V_661 ) ) {
V_14 -> V_108 . V_357 . V_661 ( V_14 , & V_20 , & V_657 ) ;
if ( ! V_657 ) {
if ( V_20 & V_921 )
V_20 = V_921 ;
}
}
if ( V_14 -> V_108 . V_357 . V_662 )
V_14 -> V_108 . V_357 . V_662 ( V_14 , V_20 , true ) ;
V_2 -> V_137 |= V_371 ;
V_2 -> V_372 = V_169 ;
F_34 ( V_686 , & V_2 -> V_34 ) ;
}
static void F_473 ( struct V_1 * V_2 )
{
int V_956 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_55 = V_2 -> V_55 ;
T_1 V_957 ;
T_1 V_958 , V_959 ;
V_957 = F_37 ( V_14 , V_960 ) ;
if ( V_957 )
return;
for ( V_956 = 0 ; V_956 < V_2 -> V_324 ; V_956 ++ ) {
V_958 = ( V_956 << 16 ) | 0x80000000 ;
V_958 |= V_961 ;
F_71 ( V_14 , V_962 , V_958 ) ;
V_959 = F_37 ( V_14 , V_963 ) ;
V_958 &= 0x7FFFFFFF ;
F_71 ( V_14 , V_962 , V_958 ) ;
V_959 >>= 16 ;
if ( V_959 & V_964 ) {
F_474 ( V_55 , L_131 , V_956 ) ;
V_958 = ( V_956 << 16 ) | 0x80000000 ;
V_958 |= 0xA8 ;
F_71 ( V_14 , V_962 , V_958 ) ;
V_959 = 0x00008000 ;
F_71 ( V_14 , V_963 , V_959 ) ;
V_958 &= 0x7FFFFFFF ;
F_71 ( V_14 , V_962 , V_958 ) ;
}
}
}
static void F_475 ( unsigned long V_92 )
{
struct V_1 * V_2 = (struct V_1 * ) V_92 ;
unsigned long V_965 ;
bool V_966 = true ;
if ( V_2 -> V_137 & V_371 )
V_965 = V_967 / 10 ;
else
V_965 = V_967 * 2 ;
#ifdef F_282
if ( ! V_2 -> V_324 ||
( V_2 -> V_137 & V_371 ) )
goto V_968;
F_473 ( V_2 ) ;
V_965 = V_967 / 50 ;
V_2 -> V_969 ++ ;
if ( V_2 -> V_969 >= 100 )
V_2 -> V_969 = 0 ;
else
V_966 = false ;
V_968:
#endif
F_359 ( & V_2 -> V_682 , V_965 + V_169 ) ;
if ( V_966 )
F_13 ( V_2 ) ;
}
static void F_476 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_152 & V_153 ) )
return;
V_2 -> V_152 &= ~ V_153 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_684 , & V_2 -> V_34 ) )
return;
F_54 ( V_2 ) ;
F_474 ( V_2 -> V_55 , L_132 ) ;
V_2 -> V_171 ++ ;
F_421 () ;
F_360 ( V_2 ) ;
F_423 () ;
}
static void F_477 ( struct V_970 * V_971 )
{
struct V_1 * V_2 = F_197 ( V_971 ,
struct V_1 ,
V_37 ) ;
if ( F_22 ( V_2 -> V_14 . V_39 ) ) {
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
F_421 () ;
F_363 ( V_2 ) ;
F_423 () ;
}
F_31 ( V_2 ) ;
return;
}
F_476 ( V_2 ) ;
F_470 ( V_2 ) ;
F_472 ( V_2 ) ;
F_207 ( V_2 ) ;
F_469 ( V_2 ) ;
F_451 ( V_2 ) ;
F_453 ( V_2 ) ;
if ( F_14 ( V_695 , & V_2 -> V_34 ) ) {
F_478 ( V_2 ) ;
F_479 ( V_2 ) ;
}
F_31 ( V_2 ) ;
}
static int F_480 ( struct V_57 * V_58 ,
struct V_59 * V_972 ,
T_4 * V_259 )
{
struct V_193 * V_89 = V_972 -> V_89 ;
T_1 V_973 , V_974 ;
T_1 V_975 , V_976 ;
int V_17 ;
if ( V_89 -> V_216 != V_977 )
return 0 ;
if ( ! F_481 ( V_89 ) )
return 0 ;
V_17 = F_482 ( V_89 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_974 = V_978 ;
if ( V_972 -> V_241 == F_147 ( V_249 ) ) {
struct V_236 * V_979 = F_483 ( V_89 ) ;
V_979 -> V_980 = 0 ;
V_979 -> V_981 = 0 ;
F_484 ( V_89 ) -> V_981 = ~ F_485 ( V_979 -> V_982 ,
V_979 -> V_983 , 0 ,
V_255 ,
0 ) ;
V_974 |= V_984 ;
V_972 -> V_985 |= V_986 |
V_987 |
V_988 ;
} else if ( F_486 ( V_89 ) ) {
F_487 ( V_89 ) -> V_989 = 0 ;
F_484 ( V_89 ) -> V_981 =
~ F_488 ( & F_487 ( V_89 ) -> V_982 ,
& F_487 ( V_89 ) -> V_983 ,
0 , V_255 , 0 ) ;
V_972 -> V_985 |= V_986 |
V_987 ;
}
V_976 = F_489 ( V_89 ) ;
* V_259 = F_490 ( V_89 ) + V_976 ;
V_972 -> V_166 = F_151 ( V_89 ) -> V_166 ;
V_972 -> V_165 += ( V_972 -> V_166 - 1 ) * * V_259 ;
V_975 = V_976 << V_990 ;
V_975 |= F_151 ( V_89 ) -> V_260 << V_991 ;
V_973 = F_491 ( V_89 ) ;
V_973 |= F_492 ( V_89 ) << V_992 ;
V_973 |= V_972 -> V_985 & V_993 ;
F_493 ( V_58 , V_973 , 0 , V_974 ,
V_975 ) ;
return 1 ;
}
static void F_494 ( struct V_57 * V_58 ,
struct V_59 * V_972 )
{
struct V_193 * V_89 = V_972 -> V_89 ;
T_1 V_973 = 0 ;
T_1 V_975 = 0 ;
T_1 V_974 = 0 ;
if ( V_89 -> V_216 != V_977 ) {
if ( ! ( V_972 -> V_985 & V_994 ) &&
! ( V_972 -> V_985 & V_995 ) )
return;
} else {
T_4 V_996 = 0 ;
switch ( V_972 -> V_241 ) {
case F_147 ( V_249 ) :
V_973 |= F_491 ( V_89 ) ;
V_974 |= V_984 ;
V_996 = F_483 ( V_89 ) -> V_241 ;
break;
case F_147 ( V_252 ) :
V_973 |= F_491 ( V_89 ) ;
V_996 = F_487 ( V_89 ) -> V_242 ;
break;
default:
if ( F_24 ( F_495 () ) ) {
F_496 ( V_58 -> V_73 ,
L_133 ,
V_972 -> V_241 ) ;
}
break;
}
switch ( V_996 ) {
case V_255 :
V_974 |= V_978 ;
V_975 = F_489 ( V_89 ) <<
V_990 ;
break;
case V_997 :
V_974 |= V_998 ;
V_975 = sizeof( struct V_999 ) <<
V_990 ;
break;
case V_257 :
V_975 = sizeof( struct V_258 ) <<
V_990 ;
break;
default:
if ( F_24 ( F_495 () ) ) {
F_496 ( V_58 -> V_73 ,
L_134 ,
V_996 ) ;
}
break;
}
V_972 -> V_985 |= V_987 ;
}
V_973 |= F_492 ( V_89 ) << V_992 ;
V_973 |= V_972 -> V_985 & V_993 ;
F_493 ( V_58 , V_973 , 0 ,
V_974 , V_975 ) ;
}
static T_1 F_497 ( struct V_193 * V_89 , T_1 V_985 )
{
T_1 V_1000 = V_1001 |
V_1002 |
V_1003 ;
V_1000 |= F_498 ( V_985 , V_994 ,
V_1004 ) ;
V_1000 |= F_498 ( V_985 , V_986 ,
V_1005 ) ;
V_1000 |= F_498 ( V_985 , V_1006 ,
V_1007 ) ;
V_1000 ^= F_498 ( V_89 -> V_1008 , 1 , V_1003 ) ;
return V_1000 ;
}
static void F_499 ( union V_61 * V_62 ,
T_1 V_985 , unsigned int V_1009 )
{
T_1 V_1010 = V_1009 << V_1011 ;
V_1010 |= F_498 ( V_985 ,
V_987 ,
V_1012 ) ;
V_1010 |= F_498 ( V_985 ,
V_988 ,
V_1013 ) ;
V_1010 |= F_498 ( V_985 ,
V_995 ,
V_1014 ) ;
V_62 -> V_227 . V_1010 = F_96 ( V_1010 ) ;
}
static void F_500 ( struct V_57 * V_58 ,
struct V_59 * V_972 ,
const T_4 V_259 )
{
struct V_193 * V_89 = V_972 -> V_89 ;
struct V_59 * V_60 ;
union V_61 * V_62 ;
struct V_281 * V_282 ;
T_9 V_81 ;
unsigned int V_287 , V_296 ;
T_1 V_985 = V_972 -> V_985 ;
T_1 V_1000 = F_497 ( V_89 , V_985 ) ;
T_2 V_48 = V_58 -> V_80 ;
V_62 = F_61 ( V_58 , V_48 ) ;
F_499 ( V_62 , V_985 , V_89 -> V_82 - V_259 ) ;
V_296 = F_150 ( V_89 ) ;
V_287 = V_89 -> V_287 ;
#ifdef F_148
if ( V_985 & V_1015 ) {
if ( V_287 < sizeof( struct V_315 ) ) {
V_296 -= sizeof( struct V_315 ) - V_287 ;
V_287 = 0 ;
} else {
V_287 -= sizeof( struct V_315 ) ;
}
}
#endif
V_81 = F_501 ( V_58 -> V_73 , V_89 -> V_92 , V_296 , V_119 ) ;
V_60 = V_972 ;
for ( V_282 = & F_151 ( V_89 ) -> V_283 [ 0 ] ; ; V_282 ++ ) {
if ( F_142 ( V_58 -> V_73 , V_81 ) )
goto V_1016;
F_81 ( V_60 , V_82 , V_296 ) ;
F_502 ( V_60 , V_81 , V_81 ) ;
V_62 -> V_227 . V_1017 = F_145 ( V_81 ) ;
while ( F_24 ( V_296 > V_1018 ) ) {
V_62 -> V_227 . V_1019 =
F_96 ( V_1000 ^ V_1018 ) ;
V_48 ++ ;
V_62 ++ ;
if ( V_48 == V_58 -> V_88 ) {
V_62 = F_61 ( V_58 , 0 ) ;
V_48 = 0 ;
}
V_62 -> V_227 . V_1010 = 0 ;
V_81 += V_1018 ;
V_296 -= V_1018 ;
V_62 -> V_227 . V_1017 = F_145 ( V_81 ) ;
}
if ( F_98 ( ! V_287 ) )
break;
V_62 -> V_227 . V_1019 = F_96 ( V_1000 ^ V_296 ) ;
V_48 ++ ;
V_62 ++ ;
if ( V_48 == V_58 -> V_88 ) {
V_62 = F_61 ( V_58 , 0 ) ;
V_48 = 0 ;
}
V_62 -> V_227 . V_1010 = 0 ;
#ifdef F_148
V_296 = F_341 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_296 = F_503 ( V_282 ) ;
#endif
V_287 -= V_296 ;
V_81 = F_504 ( V_58 -> V_73 , V_282 , 0 , V_296 ,
V_119 ) ;
V_60 = & V_58 -> V_78 [ V_48 ] ;
}
V_1000 |= V_296 | V_1020 ;
V_62 -> V_227 . V_1019 = F_96 ( V_1000 ) ;
F_505 ( F_106 ( V_58 ) , V_972 -> V_165 ) ;
V_972 -> V_84 = V_169 ;
F_135 () ;
V_972 -> V_83 = V_62 ;
V_48 ++ ;
if ( V_48 == V_58 -> V_88 )
V_48 = 0 ;
V_58 -> V_80 = V_48 ;
F_136 ( V_58 , V_48 ) ;
return;
V_1016:
F_395 ( V_58 -> V_73 , L_135 ) ;
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
static void F_506 ( struct V_57 * V_118 ,
struct V_59 * V_972 )
{
struct V_155 * V_156 = V_118 -> V_156 ;
union V_1021 V_1022 = { . V_1023 = 0 } ;
union V_1021 V_1024 = { . V_1023 = 0 } ;
union {
unsigned char * V_231 ;
struct V_236 * V_237 ;
struct V_238 * V_239 ;
} V_240 ;
struct V_256 * V_1025 ;
T_10 V_1026 ;
if ( ! V_156 )
return;
if ( ! V_118 -> V_419 )
return;
V_118 -> V_420 ++ ;
V_240 . V_231 = F_507 ( V_972 -> V_89 ) ;
if ( ( V_972 -> V_241 != F_147 ( V_252 ) ||
V_240 . V_239 -> V_242 != V_255 ) &&
( V_972 -> V_241 != F_147 ( V_249 ) ||
V_240 . V_237 -> V_241 != V_255 ) )
return;
V_1025 = F_484 ( V_972 -> V_89 ) ;
if ( ! V_1025 || V_1025 -> V_1027 )
return;
if ( ! V_1025 -> V_1028 && ( V_118 -> V_420 < V_118 -> V_419 ) )
return;
V_118 -> V_420 = 0 ;
V_1026 = F_147 ( V_972 -> V_985 >> V_1029 ) ;
V_1022 . V_1030 . V_1026 = V_1026 ;
if ( V_972 -> V_985 & ( V_1031 | V_994 ) )
V_1024 . V_1032 . V_1033 ^= V_1025 -> V_1034 ^ F_147 ( V_246 ) ;
else
V_1024 . V_1032 . V_1033 ^= V_1025 -> V_1034 ^ V_972 -> V_241 ;
V_1024 . V_1032 . V_1035 ^= V_1025 -> V_1036 ;
if ( V_972 -> V_241 == F_147 ( V_249 ) ) {
V_1022 . V_1030 . V_1037 = V_1038 ;
V_1024 . V_1039 ^= V_240 . V_237 -> V_982 ^ V_240 . V_237 -> V_983 ;
} else {
V_1022 . V_1030 . V_1037 = V_1040 ;
V_1024 . V_1039 ^= V_240 . V_239 -> V_982 . V_1041 [ 0 ] ^
V_240 . V_239 -> V_982 . V_1041 [ 1 ] ^
V_240 . V_239 -> V_982 . V_1041 [ 2 ] ^
V_240 . V_239 -> V_982 . V_1041 [ 3 ] ^
V_240 . V_239 -> V_983 . V_1041 [ 0 ] ^
V_240 . V_239 -> V_983 . V_1041 [ 1 ] ^
V_240 . V_239 -> V_983 . V_1041 [ 2 ] ^
V_240 . V_239 -> V_983 . V_1041 [ 3 ] ;
}
F_508 ( & V_156 -> V_2 -> V_14 ,
V_1022 , V_1024 , V_118 -> V_86 ) ;
}
static int F_509 ( struct V_57 * V_58 , T_2 V_296 )
{
F_103 ( V_58 -> V_55 , V_58 -> V_86 ) ;
F_110 () ;
if ( F_98 ( F_109 ( V_58 ) < V_296 ) )
return - V_766 ;
F_510 ( V_58 -> V_55 , V_58 -> V_86 ) ;
++ V_58 -> V_150 . V_172 ;
return 0 ;
}
static inline int F_511 ( struct V_57 * V_58 , T_2 V_296 )
{
if ( F_98 ( F_109 ( V_58 ) >= V_296 ) )
return 0 ;
return F_509 ( V_58 , V_296 ) ;
}
static T_2 F_512 ( struct V_54 * V_73 , struct V_193 * V_89 ,
void * V_1042 , T_14 V_1043 )
{
struct V_621 * V_1044 = V_1042 ;
#ifdef F_148
struct V_1 * V_2 ;
struct V_1045 * V_1046 ;
int V_1047 ;
#endif
if ( V_1044 )
return V_89 -> V_1048 + V_1044 -> V_629 ;
#ifdef F_148
switch ( F_513 ( V_89 ) ) {
case F_147 ( V_253 ) :
case F_147 ( V_1049 ) :
V_2 = F_89 ( V_73 ) ;
if ( V_2 -> V_137 & V_515 )
break;
default:
return V_1043 ( V_73 , V_89 ) ;
}
V_1046 = & V_2 -> V_434 [ V_1050 ] ;
V_1047 = F_514 ( V_89 ) ? F_515 ( V_89 ) :
F_516 () ;
while ( V_1047 >= V_1046 -> V_436 )
V_1047 -= V_1046 -> V_436 ;
return V_1047 + V_1046 -> V_1051 ;
#else
return V_1043 ( V_73 , V_89 ) ;
#endif
}
T_15 F_517 ( struct V_193 * V_89 ,
struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_59 * V_972 ;
int V_1052 ;
T_1 V_985 = 0 ;
unsigned short V_1046 ;
T_2 V_88 = F_518 ( F_150 ( V_89 ) ) ;
T_10 V_241 = V_89 -> V_241 ;
T_4 V_259 = 0 ;
for ( V_1046 = 0 ; V_1046 < F_151 ( V_89 ) -> V_302 ; V_1046 ++ )
V_88 += F_518 ( F_151 ( V_89 ) -> V_283 [ V_1046 ] . V_296 ) ;
if ( F_511 ( V_58 , V_88 + 3 ) ) {
V_58 -> V_150 . V_795 ++ ;
return V_1053 ;
}
V_972 = & V_58 -> V_78 [ V_58 -> V_80 ] ;
V_972 -> V_89 = V_89 ;
V_972 -> V_165 = V_89 -> V_82 ;
V_972 -> V_166 = 1 ;
if ( F_519 ( V_89 ) ) {
V_985 |= F_520 ( V_89 ) << V_1029 ;
V_985 |= V_994 ;
} else if ( V_241 == F_147 ( V_246 ) ) {
struct V_234 * V_1054 , V_1055 ;
V_1054 = F_521 ( V_89 , V_244 , sizeof( V_1055 ) , & V_1055 ) ;
if ( ! V_1054 )
goto V_1056;
V_241 = V_1054 -> V_248 ;
V_985 |= F_522 ( V_1054 -> V_1057 ) <<
V_1029 ;
V_985 |= V_1031 ;
}
if ( F_24 ( F_151 ( V_89 ) -> V_985 & V_1058 &&
! F_523 ( V_1059 ,
& V_2 -> V_34 ) ) ) {
F_151 ( V_89 ) -> V_985 |= V_1060 ;
V_985 |= V_1006 ;
V_2 -> V_1061 = F_524 ( V_89 ) ;
V_2 -> V_1062 = V_169 ;
F_16 ( & V_2 -> V_1063 ) ;
}
F_525 ( V_89 ) ;
#ifdef F_282
if ( V_2 -> V_137 & V_429 )
V_985 |= V_995 ;
#endif
if ( ( V_2 -> V_137 & V_138 ) &&
( ( V_985 & ( V_994 | V_1031 ) ) ||
( V_89 -> V_1064 != V_1065 ) ) ) {
V_985 &= ~ V_1066 ;
V_985 |= ( V_89 -> V_1064 & 0x7 ) <<
V_1067 ;
if ( V_985 & V_1031 ) {
struct V_1068 * V_1054 ;
if ( F_482 ( V_89 , 0 ) )
goto V_1056;
V_1054 = (struct V_1068 * ) V_89 -> V_92 ;
V_1054 -> V_1057 = F_147 ( V_985 >>
V_1029 ) ;
} else {
V_985 |= V_994 ;
}
}
V_972 -> V_985 = V_985 ;
V_972 -> V_241 = V_241 ;
#ifdef F_148
if ( ( V_241 == F_147 ( V_253 ) ) &&
( V_58 -> V_55 -> V_194 & ( V_1069 | V_1070 ) ) ) {
V_1052 = F_526 ( V_58 , V_972 , & V_259 ) ;
if ( V_1052 < 0 )
goto V_1056;
goto V_1071;
}
#endif
V_1052 = F_480 ( V_58 , V_972 , & V_259 ) ;
if ( V_1052 < 0 )
goto V_1056;
else if ( ! V_1052 )
F_494 ( V_58 , V_972 ) ;
if ( F_14 ( V_393 , & V_58 -> V_34 ) )
F_506 ( V_58 , V_972 ) ;
#ifdef F_148
V_1071:
#endif
F_500 ( V_58 , V_972 , V_259 ) ;
F_511 ( V_58 , V_1072 ) ;
return V_1073 ;
V_1056:
F_78 ( V_972 -> V_89 ) ;
V_972 -> V_89 = NULL ;
return V_1073 ;
}
static T_15 F_527 ( struct V_193 * V_89 ,
struct V_54 * V_55 ,
struct V_57 * V_118 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_57 * V_58 ;
if ( F_24 ( V_89 -> V_82 < 17 ) ) {
if ( F_177 ( V_89 , 17 - V_89 -> V_82 ) )
return V_1073 ;
V_89 -> V_82 = 17 ;
F_528 ( V_89 , 17 ) ;
}
V_58 = V_118 ? V_118 : V_2 -> V_58 [ V_89 -> V_1048 ] ;
return F_517 ( V_89 , V_2 , V_58 ) ;
}
static T_15 F_529 ( struct V_193 * V_89 ,
struct V_54 * V_55 )
{
return F_527 ( V_89 , V_55 , NULL ) ;
}
static int F_530 ( struct V_54 * V_55 , void * V_1074 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1075 * V_553 = V_1074 ;
int V_658 ;
if ( ! F_344 ( V_553 -> V_1076 ) )
return - V_1077 ;
F_293 ( V_2 , V_14 -> V_108 . V_553 , F_266 ( 0 ) ) ;
memcpy ( V_55 -> V_634 , V_553 -> V_1076 , V_55 -> V_692 ) ;
memcpy ( V_14 -> V_108 . V_553 , V_553 -> V_1076 , V_55 -> V_692 ) ;
V_658 = F_290 ( V_2 , V_14 -> V_108 . V_553 , F_266 ( 0 ) ) ;
return V_658 > 0 ? 0 : V_658 ;
}
static int
F_531 ( struct V_54 * V_55 , int V_1078 , int V_1079 , T_2 V_553 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_4 ;
int V_1080 ;
if ( V_1078 != V_14 -> V_360 . V_1081 . V_1078 )
return - V_559 ;
V_1080 = V_14 -> V_360 . V_357 . V_1082 ( V_14 , V_553 , V_1079 , & V_4 ) ;
if ( ! V_1080 )
V_1080 = V_4 ;
return V_1080 ;
}
static int F_532 ( struct V_54 * V_55 , int V_1078 , int V_1079 ,
T_2 V_553 , T_2 V_4 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_1078 != V_14 -> V_360 . V_1081 . V_1078 )
return - V_559 ;
return V_14 -> V_360 . V_357 . V_1083 ( V_14 , V_553 , V_1079 , V_4 ) ;
}
static int F_533 ( struct V_54 * V_55 , struct V_1084 * V_1085 , int V_1086 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
switch ( V_1086 ) {
case V_1087 :
return F_534 ( V_2 , V_1085 ) ;
case V_1088 :
return F_535 ( V_2 , V_1085 ) ;
default:
return F_536 ( & V_2 -> V_14 . V_360 . V_1081 , F_537 ( V_1085 ) , V_1086 ) ;
}
}
static int F_538 ( struct V_54 * V_73 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_344 ( V_14 -> V_108 . V_1089 ) ) {
F_421 () ;
V_17 = F_539 ( V_73 , V_14 -> V_108 . V_1089 , V_1090 ) ;
F_423 () ;
V_14 -> V_108 . V_357 . V_694 ( V_14 , F_266 ( 0 ) ) ;
}
return V_17 ;
}
static int F_540 ( struct V_54 * V_73 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_1091 * V_108 = & V_2 -> V_14 . V_108 ;
if ( F_344 ( V_108 -> V_1089 ) ) {
F_421 () ;
V_17 = F_541 ( V_73 , V_108 -> V_1089 , V_1090 ) ;
F_423 () ;
}
return V_17 ;
}
static void F_542 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_48 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
V_2 -> V_137 |= V_270 ;
if ( V_2 -> V_137 & V_408 ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_187 ; V_48 ++ )
F_223 ( 0 , V_2 -> V_156 [ V_48 ] ) ;
} else {
F_236 ( V_2 -> V_9 -> V_387 , V_55 ) ;
}
V_2 -> V_137 &= ~ V_270 ;
}
static struct V_1092 * F_543 ( struct V_54 * V_55 ,
struct V_1092 * V_122 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_48 ;
F_544 () ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_118 = F_21 ( V_2 -> V_67 [ V_48 ] ) ;
T_6 V_168 , V_142 ;
unsigned int V_1093 ;
if ( V_118 ) {
do {
V_1093 = F_545 ( & V_118 -> V_167 ) ;
V_142 = V_118 -> V_122 . V_142 ;
V_168 = V_118 -> V_122 . V_168 ;
} while ( F_546 ( & V_118 -> V_167 , V_1093 ) );
V_122 -> V_800 += V_142 ;
V_122 -> V_799 += V_168 ;
}
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_118 = F_21 ( V_2 -> V_58 [ V_48 ] ) ;
T_6 V_168 , V_142 ;
unsigned int V_1093 ;
if ( V_118 ) {
do {
V_1093 = F_545 ( & V_118 -> V_167 ) ;
V_142 = V_118 -> V_122 . V_142 ;
V_168 = V_118 -> V_122 . V_168 ;
} while ( F_546 ( & V_118 -> V_167 , V_1093 ) );
V_122 -> V_802 += V_142 ;
V_122 -> V_801 += V_168 ;
}
}
F_547 () ;
V_122 -> V_909 = V_55 -> V_122 . V_909 ;
V_122 -> V_910 = V_55 -> V_122 . V_910 ;
V_122 -> V_912 = V_55 -> V_122 . V_912 ;
V_122 -> V_913 = V_55 -> V_122 . V_913 ;
V_122 -> V_914 = V_55 -> V_122 . V_914 ;
return V_122 ;
}
static void F_548 ( struct V_1 * V_2 , T_4 V_132 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_3 , V_1094 ;
int V_48 ;
if ( V_14 -> V_108 . type == V_109 )
return;
V_3 = F_37 ( V_14 , V_1095 ) ;
V_1094 = V_3 ;
for ( V_48 = 0 ; V_48 < V_605 ; V_48 ++ ) {
T_4 V_1096 = V_3 >> ( V_48 * V_1097 ) ;
if ( V_1096 > V_132 )
V_3 &= ~ ( 0x7 << V_1097 ) ;
}
if ( V_3 != V_1094 )
F_71 ( V_14 , V_1095 , V_3 ) ;
return;
}
static void F_549 ( struct V_1 * V_2 )
{
struct V_54 * V_73 = V_2 -> V_55 ;
struct V_1098 * V_134 = & V_2 -> V_134 ;
struct V_1099 * V_1100 = V_2 -> V_590 ;
T_4 V_1101 ;
for ( V_1101 = 0 ; V_1101 < V_1102 ; V_1101 ++ ) {
T_4 V_132 = 0 ;
if ( V_2 -> V_586 & V_587 )
V_132 = F_550 ( V_134 , 0 , V_1101 ) ;
else if ( V_1100 )
V_132 = V_1100 -> V_591 [ V_1101 ] ;
F_551 ( V_73 , V_1101 , V_132 ) ;
}
}
int F_552 ( struct V_54 * V_73 , T_4 V_132 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
bool V_1103 ;
if ( V_132 > V_2 -> V_134 . V_728 . V_729 ||
( V_14 -> V_108 . type == V_109 &&
V_132 < V_605 ) )
return - V_559 ;
V_1103 = ( F_553 ( & V_2 -> V_631 , 32 ) > 1 ) ;
if ( V_132 && V_1103 && V_2 -> V_632 > V_1104 )
return - V_766 ;
if ( F_57 ( V_73 ) )
F_411 ( V_73 ) ;
F_428 ( V_2 ) ;
#ifdef F_349
if ( V_132 ) {
F_554 ( V_73 , V_132 ) ;
F_549 ( V_2 ) ;
V_2 -> V_137 |= V_138 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ) {
V_2 -> V_1105 = V_2 -> V_14 . V_123 . V_743 ;
V_2 -> V_14 . V_123 . V_743 = V_1106 ;
}
} else {
F_555 ( V_73 ) ;
if ( V_2 -> V_14 . V_108 . type == V_109 )
V_2 -> V_14 . V_123 . V_743 = V_2 -> V_1105 ;
V_2 -> V_137 &= ~ V_138 ;
V_2 -> V_742 . V_135 = false ;
V_2 -> V_134 . V_135 = false ;
}
F_548 ( V_2 , V_132 ) ;
#endif
F_422 ( V_2 ) ;
if ( F_57 ( V_73 ) )
return F_407 ( V_73 ) ;
return 0 ;
}
void F_556 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
F_421 () ;
F_552 ( V_55 , F_249 ( V_55 ) ) ;
F_423 () ;
}
void F_557 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
if ( F_57 ( V_55 ) )
F_360 ( V_2 ) ;
else
F_366 ( V_2 ) ;
}
static T_16 F_558 ( struct V_54 * V_55 ,
T_16 V_194 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
if ( ! ( V_194 & V_207 ) )
V_194 &= ~ V_1107 ;
if ( ! ( V_2 -> V_152 & V_714 ) )
V_194 &= ~ V_1107 ;
return V_194 ;
}
static int F_559 ( struct V_54 * V_55 ,
T_16 V_194 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
T_16 V_1108 = V_55 -> V_194 ^ V_194 ;
bool V_1109 = false ;
if ( ! ( V_194 & V_1107 ) ) {
if ( V_2 -> V_152 & V_523 )
V_1109 = true ;
V_2 -> V_152 &= ~ V_523 ;
} else if ( ( V_2 -> V_152 & V_714 ) &&
! ( V_2 -> V_152 & V_523 ) ) {
if ( V_2 -> V_399 == 1 ||
V_2 -> V_399 > V_1110 ) {
V_2 -> V_152 |= V_523 ;
V_1109 = true ;
} else if ( ( V_1108 ^ V_194 ) & V_1107 ) {
F_104 ( V_170 , L_136
L_137 ) ;
}
}
switch ( V_194 & V_1111 ) {
case V_1111 :
if ( ! ( V_2 -> V_137 & V_607 ) )
V_1109 = true ;
V_2 -> V_137 &= ~ V_384 ;
V_2 -> V_137 |= V_607 ;
break;
default:
if ( V_2 -> V_137 & V_607 )
V_1109 = true ;
V_2 -> V_137 &= ~ V_607 ;
if ( V_2 -> V_137 & V_429 )
break;
if ( F_249 ( V_55 ) > 1 )
break;
if ( V_2 -> V_434 [ V_435 ] . V_713 <= 1 )
break;
if ( ! V_2 -> V_419 )
break;
V_2 -> V_137 |= V_384 ;
break;
}
if ( V_194 & V_267 )
F_279 ( V_2 ) ;
else
F_278 ( V_2 ) ;
if ( V_1108 & V_290 )
V_1109 = true ;
V_55 -> V_194 = V_194 ;
if ( V_1109 )
F_557 ( V_55 ) ;
return 0 ;
}
static int F_560 ( struct V_1112 * V_1113 , struct V_1114 * V_1115 [] ,
struct V_54 * V_73 ,
const unsigned char * V_553 ,
T_2 V_137 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
int V_17 ;
if ( ! ( V_2 -> V_137 & V_429 ) )
return F_561 ( V_1113 , V_1115 , V_73 , V_553 , V_137 ) ;
if ( V_1113 -> V_1116 && ! ( V_1113 -> V_1116 & V_1117 ) ) {
F_51 ( L_138 ,
V_1118 ) ;
return - V_559 ;
}
if ( F_562 ( V_553 ) || F_563 ( V_553 ) ) {
T_1 V_1119 = V_1120 ;
if ( F_296 ( V_73 ) < V_1119 )
V_17 = F_564 ( V_73 , V_553 ) ;
else
V_17 = - V_548 ;
} else if ( F_565 ( V_553 ) ) {
V_17 = F_566 ( V_73 , V_553 ) ;
} else {
V_17 = - V_559 ;
}
if ( V_17 == - V_1121 && ! ( V_137 & V_1122 ) )
V_17 = 0 ;
return V_17 ;
}
static int F_567 ( struct V_54 * V_73 ,
struct V_1123 * V_1124 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_1114 * V_1125 , * V_1126 ;
int V_1127 ;
if ( ! ( V_2 -> V_137 & V_429 ) )
return - V_1128 ;
V_1126 = F_568 ( V_1124 , sizeof( struct V_1129 ) , V_1130 ) ;
F_569 (attr, br_spec, rem) {
T_17 V_1131 ;
T_1 V_3 = 0 ;
if ( F_570 ( V_1125 ) != V_1132 )
continue;
V_1131 = F_571 ( V_1125 ) ;
if ( V_1131 == V_1133 ) {
V_3 = 0 ;
V_2 -> V_152 &= ~ V_497 ;
} else if ( V_1131 == V_1134 ) {
V_3 = V_499 ;
V_2 -> V_152 |= V_497 ;
} else
return - V_559 ;
F_71 ( & V_2 -> V_14 , V_498 , V_3 ) ;
F_104 ( V_154 , L_139 ,
V_1131 == V_1133 ? L_140 : L_141 ) ;
}
return 0 ;
}
static int F_572 ( struct V_193 * V_89 , T_1 V_1135 , T_1 V_1136 ,
struct V_54 * V_73 ,
T_1 V_1137 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
T_2 V_1131 ;
if ( ! ( V_2 -> V_137 & V_429 ) )
return 0 ;
if ( V_2 -> V_152 & V_497 )
V_1131 = V_1134 ;
else
V_1131 = V_1133 ;
return F_573 ( V_89 , V_1135 , V_1136 , V_73 , V_1131 ) ;
}
static void * F_574 ( struct V_54 * V_9 , struct V_54 * V_625 )
{
struct V_621 * V_1044 = NULL ;
struct V_1 * V_2 = F_89 ( V_9 ) ;
unsigned int V_713 ;
int V_482 , V_17 ;
#ifdef F_575
if ( V_625 -> V_93 != V_625 -> V_77 ) {
F_576 ( V_9 , L_142 ,
V_625 -> V_53 ) ;
return F_577 ( - V_559 ) ;
}
#endif
if ( V_625 -> V_77 > V_769 ||
V_625 -> V_77 == V_1138 ) {
F_576 ( V_9 ,
L_143 ,
V_9 -> V_53 ) ;
return F_577 ( - V_559 ) ;
}
if ( ( ( V_2 -> V_137 & V_138 ) &&
V_2 -> V_632 > V_1104 - 1 ) ||
( V_2 -> V_632 > V_1139 ) )
return F_577 ( - V_766 ) ;
V_1044 = F_578 ( 1 , sizeof( struct V_621 ) , V_760 ) ;
if ( ! V_1044 )
return F_577 ( - V_548 ) ;
V_482 = F_553 ( & V_2 -> V_631 , 32 ) ;
V_2 -> V_632 ++ ;
F_245 ( V_482 , & V_2 -> V_631 ) ;
V_713 = F_579 ( & V_2 -> V_631 , 32 ) ;
V_2 -> V_137 |= V_580 | V_429 ;
V_2 -> V_434 [ V_501 ] . V_713 = V_713 + 1 ;
V_2 -> V_434 [ V_435 ] . V_713 = V_625 -> V_77 ;
V_17 = F_552 ( V_9 , F_249 ( V_9 ) ) ;
if ( V_17 )
goto V_1140;
V_1044 -> V_482 = V_482 ;
V_1044 -> V_146 = V_2 ;
V_17 = F_339 ( V_625 , V_1044 ) ;
if ( V_17 )
goto V_1140;
F_580 ( V_625 ) ;
return V_1044 ;
V_1140:
F_576 ( V_9 ,
L_144 , V_625 -> V_53 ) ;
F_34 ( V_482 , & V_2 -> V_631 ) ;
V_2 -> V_632 -- ;
F_235 ( V_1044 ) ;
return F_577 ( V_17 ) ;
}
static void F_581 ( struct V_54 * V_9 , void * V_1141 )
{
struct V_621 * V_1044 = V_1141 ;
struct V_1 * V_2 = V_1044 -> V_146 ;
unsigned int V_713 ;
F_34 ( V_1044 -> V_482 , & V_2 -> V_631 ) ;
V_2 -> V_632 -- ;
V_713 = F_579 ( & V_2 -> V_631 , 32 ) ;
V_2 -> V_434 [ V_501 ] . V_713 = V_713 + 1 ;
F_337 ( V_1044 -> V_55 , V_1044 ) ;
F_552 ( V_9 , F_249 ( V_9 ) ) ;
F_340 ( V_9 , L_92 ,
V_1044 -> V_482 , V_2 -> V_632 ,
V_1044 -> V_624 ,
V_1044 -> V_624 + V_2 -> V_623 ,
V_2 -> V_631 ) ;
F_235 ( V_1044 ) ;
}
static inline int F_582 ( struct V_1 * V_2 )
{
struct V_5 * V_404 , * V_9 = V_2 -> V_9 ;
int V_1142 = 0 ;
if ( F_8 ( & V_2 -> V_14 ) )
V_1142 = 4 ;
F_583 (entry, &adapter->pdev->bus->devices, bus_list) {
if ( V_404 -> V_1143 )
continue;
if ( ( V_404 -> V_705 != V_9 -> V_705 ) ||
( V_404 -> V_188 != V_9 -> V_188 ) )
return - 1 ;
V_1142 ++ ;
}
return V_1142 ;
}
int F_584 ( struct V_1 * V_2 , T_2 V_21 ,
T_2 V_1144 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1145 = V_2 -> V_1146 & V_1147 ;
int V_1148 = 0 ;
switch ( V_21 ) {
case V_1149 :
switch ( V_1144 ) {
case V_1150 :
case V_1151 :
if ( V_14 -> V_10 . V_1152 != 0 )
break;
case V_1153 :
case V_1154 :
case V_1155 :
case V_1156 :
case V_1157 :
V_1148 = 1 ;
break;
}
break;
case V_1158 :
switch ( V_1144 ) {
case V_1159 :
V_1148 = 1 ;
break;
}
break;
case V_1160 :
if ( V_1144 != V_1161 )
V_1148 = 1 ;
break;
case V_1162 :
V_1148 = 1 ;
break;
case V_1163 :
case V_1164 :
if ( ( V_1145 == V_1165 ) ||
( ( V_1145 == V_1166 ) &&
( V_14 -> V_10 . V_1152 == 0 ) ) ) {
V_1148 = 1 ;
}
break;
}
return V_1148 ;
}
static int F_585 ( struct V_5 * V_9 , const struct V_1167 * V_1168 )
{
struct V_54 * V_55 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_14 ;
const struct V_1169 * V_1170 = V_1171 [ V_1168 -> V_1172 ] ;
static int V_1173 ;
int V_48 , V_17 , V_1174 , V_24 ;
unsigned int V_436 = V_1175 ;
T_4 V_1176 [ V_1177 ] ;
#ifdef F_148
T_2 V_1178 ;
#endif
T_1 V_1179 ;
if ( V_9 -> V_1143 ) {
F_586 ( 1 , V_1180 L_145 ,
F_587 ( V_9 ) , V_9 -> V_705 , V_9 -> V_188 ) ;
return - V_559 ;
}
V_17 = F_418 ( V_9 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_588 ( & V_9 -> V_73 , F_243 ( 64 ) ) ) {
V_1174 = 1 ;
} else {
V_17 = F_588 ( & V_9 -> V_73 , F_243 ( 32 ) ) ;
if ( V_17 ) {
F_395 ( & V_9 -> V_73 ,
L_146 ) ;
goto V_1181;
}
V_1174 = 0 ;
}
V_17 = F_589 ( V_9 , F_590 ( V_9 ,
V_1182 ) , V_1118 ) ;
if ( V_17 ) {
F_395 ( & V_9 -> V_73 ,
L_147 , V_17 ) ;
goto V_1183;
}
F_591 ( V_9 ) ;
F_419 ( V_9 ) ;
F_417 ( V_9 ) ;
if ( V_1170 -> V_108 == V_109 ) {
#ifdef F_349
V_436 = 4 * V_605 ;
#else
V_436 = V_712 ;
#endif
}
V_55 = F_592 ( sizeof( struct V_1 ) , V_436 ) ;
if ( ! V_55 ) {
V_17 = - V_548 ;
goto V_1184;
}
F_593 ( V_55 , & V_9 -> V_73 ) ;
V_2 = F_89 ( V_55 ) ;
F_594 ( V_9 , V_2 ) ;
V_2 -> V_55 = V_55 ;
V_2 -> V_9 = V_9 ;
V_14 = & V_2 -> V_14 ;
V_14 -> V_38 = V_2 ;
V_2 -> V_1185 = F_595 ( V_1186 , V_1187 ) ;
V_14 -> V_39 = F_596 ( F_597 ( V_9 , 0 ) ,
F_598 ( V_9 , 0 ) ) ;
V_2 -> V_417 = V_14 -> V_39 ;
if ( ! V_14 -> V_39 ) {
V_17 = - V_757 ;
goto V_1188;
}
V_55 -> V_1189 = & V_1190 ;
F_599 ( V_55 ) ;
V_55 -> V_1191 = 5 * V_967 ;
F_600 ( V_55 -> V_53 , F_587 ( V_9 ) , sizeof( V_55 -> V_53 ) ) ;
V_2 -> V_1192 = V_1173 ;
memcpy ( & V_14 -> V_108 . V_357 , V_1170 -> V_1193 , sizeof( V_14 -> V_108 . V_357 ) ) ;
V_14 -> V_108 . type = V_1170 -> V_108 ;
memcpy ( & V_14 -> V_1194 . V_357 , V_1170 -> V_1195 , sizeof( V_14 -> V_1194 . V_357 ) ) ;
V_1179 = F_37 ( V_14 , V_1196 ) ;
if ( F_22 ( V_14 -> V_39 ) ) {
V_17 = - V_757 ;
goto V_1188;
}
if ( ! ( V_1179 & ( 1 << 8 ) ) )
V_14 -> V_1194 . V_357 . V_227 = & V_1197 ;
memcpy ( & V_14 -> V_360 . V_357 , V_1170 -> V_1198 , sizeof( V_14 -> V_360 . V_357 ) ) ;
V_14 -> V_360 . V_953 = V_1199 ;
V_14 -> V_360 . V_1081 . V_1078 = V_1200 ;
V_14 -> V_360 . V_1081 . V_1201 = 0 ;
V_14 -> V_360 . V_1081 . V_1202 = V_1203 | V_1204 ;
V_14 -> V_360 . V_1081 . V_73 = V_55 ;
V_14 -> V_360 . V_1081 . V_1205 = F_531 ;
V_14 -> V_360 . V_1081 . V_1206 = F_532 ;
V_1170 -> V_1207 ( V_14 ) ;
V_17 = F_381 ( V_2 ) ;
if ( V_17 )
goto V_1208;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
case V_112 :
F_71 ( & V_2 -> V_14 , V_772 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_137 & V_363 ) {
T_1 V_679 = F_37 ( V_14 , V_680 ) ;
if ( V_679 & V_681 )
F_208 ( V_170 , L_73 ) ;
}
if ( V_1209 )
V_14 -> V_1209 = V_1209 ;
V_14 -> V_360 . V_1210 = true ;
V_17 = V_14 -> V_108 . V_357 . V_1211 ( V_14 ) ;
V_14 -> V_360 . V_1210 = false ;
if ( V_17 == V_688 &&
V_14 -> V_108 . type == V_109 ) {
V_17 = 0 ;
} else if ( V_17 == V_689 ) {
F_18 ( L_148 ) ;
F_18 ( L_149 ) ;
goto V_1208;
} else if ( V_17 ) {
F_18 ( L_150 , V_17 ) ;
goto V_1208;
}
#ifdef F_282
if ( V_2 -> V_14 . V_108 . type == V_109 )
goto V_1212;
F_601 ( V_14 ) ;
memcpy ( & V_14 -> V_1213 . V_357 , V_1170 -> V_1214 , sizeof( V_14 -> V_1213 . V_357 ) ) ;
F_602 ( V_9 , V_749 ) ;
F_603 ( V_2 ) ;
V_1212:
#endif
V_55 -> V_194 = V_1215 |
V_1216 |
V_1217 |
V_1218 |
V_267 |
V_1219 |
V_1220 |
V_1221 |
V_195 |
V_207 ;
V_55 -> V_1222 = V_55 -> V_194 | V_1223 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
case V_112 :
V_55 -> V_194 |= V_1224 ;
V_55 -> V_1222 |= V_1224 |
V_1111 ;
break;
default:
break;
}
V_55 -> V_1222 |= V_290 ;
V_55 -> V_1225 |= V_1220 ;
V_55 -> V_1225 |= V_1221 ;
V_55 -> V_1225 |= V_1216 ;
V_55 -> V_1225 |= V_1217 ;
V_55 -> V_1225 |= V_1215 ;
V_55 -> V_1226 |= V_1227 ;
V_55 -> V_1226 |= V_1228 ;
#ifdef F_349
V_55 -> V_1229 = & V_1229 ;
#endif
#ifdef F_148
if ( V_2 -> V_137 & V_720 ) {
unsigned int V_1230 ;
if ( V_14 -> V_108 . V_357 . V_1231 ) {
V_14 -> V_108 . V_357 . V_1231 ( V_14 , & V_1178 ) ;
if ( V_1178 & V_1232 )
V_2 -> V_137 &= ~ V_720 ;
}
V_1230 = F_341 ( int , V_1233 , F_382 () ) ;
V_2 -> V_434 [ V_1050 ] . V_713 = V_1230 ;
V_55 -> V_194 |= V_1069 |
V_1070 ;
V_55 -> V_1225 |= V_1069 |
V_1070 |
V_585 ;
}
#endif
if ( V_1174 ) {
V_55 -> V_194 |= V_1234 ;
V_55 -> V_1225 |= V_1234 ;
}
if ( V_2 -> V_152 & V_714 )
V_55 -> V_1222 |= V_1107 ;
if ( V_2 -> V_152 & V_523 )
V_55 -> V_194 |= V_1107 ;
if ( V_14 -> V_1194 . V_357 . V_1235 ( V_14 , NULL ) < 0 ) {
F_18 ( L_151 ) ;
V_17 = - V_757 ;
goto V_1208;
}
memcpy ( V_55 -> V_634 , V_14 -> V_108 . V_1236 , V_55 -> V_692 ) ;
if ( ! F_344 ( V_55 -> V_634 ) ) {
F_18 ( L_152 ) ;
V_17 = - V_757 ;
goto V_1208;
}
F_289 ( V_2 , V_14 -> V_108 . V_1236 ) ;
F_604 ( & V_2 -> V_682 , & F_475 ,
( unsigned long ) V_2 ) ;
if ( F_22 ( V_14 -> V_39 ) ) {
V_17 = - V_757 ;
goto V_1208;
}
F_605 ( & V_2 -> V_37 , F_477 ) ;
F_245 ( V_40 , & V_2 -> V_34 ) ;
F_34 ( V_36 , & V_2 -> V_34 ) ;
V_17 = F_422 ( V_2 ) ;
if ( V_17 )
goto V_1208;
V_2 -> V_776 = 0 ;
V_14 -> V_1194 . V_357 . V_227 ( V_14 , 0x2c , & V_2 -> V_1146 ) ;
V_14 -> V_1237 = F_584 ( V_2 , V_9 -> V_188 ,
V_9 -> V_711 ) ;
if ( V_14 -> V_1237 )
V_2 -> V_776 = V_1238 ;
F_606 ( & V_2 -> V_9 -> V_73 , V_2 -> V_776 ) ;
V_14 -> V_1194 . V_357 . V_227 ( V_14 , 0x2e , & V_2 -> V_1239 ) ;
V_14 -> V_1194 . V_357 . V_227 ( V_14 , 0x2d , & V_2 -> V_1240 ) ;
V_14 -> V_108 . V_357 . V_1241 ( V_14 ) ;
if ( F_8 ( V_14 ) )
F_5 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_24 = F_607 ( F_582 ( V_2 ) * 10 , 16 ) ;
break;
default:
V_24 = F_582 ( V_2 ) * 10 ;
break;
}
if ( V_24 > 0 )
F_9 ( V_2 , V_24 ) ;
V_17 = F_608 ( V_14 , V_1176 , sizeof( V_1176 ) ) ;
if ( V_17 )
F_600 ( V_1176 , L_7 , sizeof( V_1176 ) ) ;
if ( F_353 ( V_14 ) && V_14 -> V_360 . V_953 != V_1242 )
F_12 ( L_153 ,
V_14 -> V_108 . type , V_14 -> V_360 . type , V_14 -> V_360 . V_953 ,
V_1176 ) ;
else
F_12 ( L_154 ,
V_14 -> V_108 . type , V_14 -> V_360 . type , V_1176 ) ;
F_12 ( L_155 , V_55 -> V_634 ) ;
V_17 = V_14 -> V_108 . V_357 . V_1243 ( V_14 ) ;
if ( V_17 == V_691 ) {
F_11 ( L_95
L_156
L_157
L_158
L_99
L_100 ) ;
}
strcpy ( V_55 -> V_53 , L_159 ) ;
V_17 = F_609 ( V_55 ) ;
if ( V_17 )
goto V_1244;
if ( V_14 -> V_108 . V_357 . V_700 )
V_14 -> V_108 . V_357 . V_700 ( V_14 ) ;
F_374 ( V_55 ) ;
#ifdef F_226
if ( F_125 ( & V_9 -> V_73 ) == 0 ) {
V_2 -> V_137 |= V_185 ;
F_122 ( V_2 ) ;
}
#endif
if ( V_2 -> V_137 & V_429 ) {
F_104 ( V_170 , L_160 , V_2 -> V_324 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_324 ; V_48 ++ )
F_610 ( V_9 , ( V_48 | 0x10000000 ) ) ;
}
if ( V_14 -> V_108 . V_357 . V_1245 )
V_14 -> V_108 . V_357 . V_1245 ( V_14 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_538 ( V_55 ) ;
F_12 ( L_161 , V_1246 ) ;
V_1173 ++ ;
#ifdef F_611
if ( F_612 ( V_2 ) )
F_102 ( V_170 , L_162 ) ;
#endif
F_613 ( V_2 ) ;
if ( F_614 ( V_14 ) && F_353 ( V_14 ) && V_14 -> V_108 . V_357 . V_662 )
V_14 -> V_108 . V_357 . V_662 ( V_14 ,
V_921 | V_944 ,
true ) ;
return 0 ;
V_1244:
F_70 ( V_2 ) ;
F_428 ( V_2 ) ;
V_1208:
F_615 ( V_2 ) ;
V_2 -> V_152 &= ~ V_656 ;
F_616 ( V_2 -> V_417 ) ;
F_235 ( V_2 -> V_550 ) ;
V_1188:
F_617 ( V_55 ) ;
V_1184:
F_618 ( V_9 ,
F_590 ( V_9 , V_1182 ) ) ;
V_1183:
V_1181:
if ( ! V_2 || ! F_15 ( V_771 , & V_2 -> V_34 ) )
F_429 ( V_9 ) ;
return V_17 ;
}
static void F_619 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_414 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
F_620 ( V_2 ) ;
F_245 ( V_35 , & V_2 -> V_34 ) ;
F_621 ( & V_2 -> V_37 ) ;
#ifdef F_226
if ( V_2 -> V_137 & V_185 ) {
V_2 -> V_137 &= ~ V_185 ;
F_126 ( & V_9 -> V_73 ) ;
F_71 ( & V_2 -> V_14 , V_186 , 1 ) ;
}
#endif
#ifdef F_611
F_622 ( V_2 ) ;
#endif
F_540 ( V_55 ) ;
if ( V_55 -> V_954 == V_955 )
F_471 ( V_55 ) ;
#ifdef F_282
if ( V_748 )
F_615 ( V_2 ) ;
#endif
F_428 ( V_2 ) ;
F_70 ( V_2 ) ;
#ifdef F_623
F_235 ( V_2 -> V_136 ) ;
F_235 ( V_2 -> V_590 ) ;
#endif
F_616 ( V_2 -> V_417 ) ;
F_618 ( V_9 , F_590 ( V_9 ,
V_1182 ) ) ;
F_12 ( L_163 ) ;
F_235 ( V_2 -> V_550 ) ;
F_617 ( V_55 ) ;
F_624 ( V_9 ) ;
if ( ! F_15 ( V_771 , & V_2 -> V_34 ) )
F_429 ( V_9 ) ;
}
static T_18 F_625 ( struct V_5 * V_9 ,
T_19 V_34 )
{
struct V_1 * V_2 = F_414 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
#ifdef F_282
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_1247 , * V_1248 ;
T_1 V_1249 , V_1250 , V_1251 , V_1252 ;
int V_956 , V_1253 ;
T_2 V_1254 , V_1255 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ||
V_2 -> V_324 == 0 )
goto V_1256;
V_1247 = V_9 -> V_10 -> V_12 ;
while ( V_1247 && ( F_626 ( V_1247 ) != V_1257 ) )
V_1247 = V_1247 -> V_10 -> V_12 ;
if ( ! V_1247 )
goto V_1256;
V_1253 = F_627 ( V_1247 , V_1258 ) ;
if ( ! V_1253 )
goto V_1256;
V_1249 = F_27 ( V_14 , V_1253 + V_1259 ) ;
V_1250 = F_27 ( V_14 , V_1253 + V_1259 + 4 ) ;
V_1251 = F_27 ( V_14 , V_1253 + V_1259 + 8 ) ;
V_1252 = F_27 ( V_14 , V_1253 + V_1259 + 12 ) ;
if ( F_22 ( V_14 -> V_39 ) )
goto V_1256;
V_1254 = V_1250 >> 16 ;
if ( ! ( V_1254 & 0x0080 ) )
goto V_1256;
V_1255 = V_1254 & 0x01 ;
if ( ( V_1255 & 1 ) == ( V_9 -> V_1260 & 1 ) ) {
unsigned int V_21 ;
V_956 = ( V_1254 & 0x7F ) >> 1 ;
F_18 ( L_164 , V_956 ) ;
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
default:
V_21 = 0 ;
break;
}
V_1248 = F_628 ( V_1263 , V_21 , NULL ) ;
while ( V_1248 ) {
if ( V_1248 -> V_1260 == ( V_1254 & 0xFF ) )
break;
V_1248 = F_628 ( V_1263 ,
V_21 , V_1248 ) ;
}
if ( V_1248 ) {
F_18 ( L_167 , V_956 ) ;
F_629 ( V_1248 , 0xA8 , 0x00008000 ) ;
F_630 ( V_1248 ) ;
}
F_631 ( V_9 ) ;
}
V_2 -> V_1264 ++ ;
return V_1265 ;
V_1256:
#endif
if ( ! F_14 ( V_40 , & V_2 -> V_34 ) )
return V_1266 ;
F_421 () ;
F_427 ( V_55 ) ;
if ( V_34 == V_1267 ) {
F_423 () ;
return V_1266 ;
}
if ( F_57 ( V_55 ) )
F_363 ( V_2 ) ;
if ( ! F_15 ( V_771 , & V_2 -> V_34 ) )
F_429 ( V_9 ) ;
F_423 () ;
return V_1268 ;
}
static T_18 F_632 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_414 ( V_9 ) ;
T_18 V_1269 ;
int V_17 ;
if ( F_418 ( V_9 ) ) {
F_102 ( V_170 , L_168 ) ;
V_1269 = V_1266 ;
} else {
F_33 () ;
F_34 ( V_771 , & V_2 -> V_34 ) ;
V_2 -> V_14 . V_39 = V_2 -> V_417 ;
F_419 ( V_9 ) ;
F_416 ( V_9 ) ;
F_417 ( V_9 ) ;
F_420 ( V_9 , false ) ;
F_366 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_772 , ~ 0 ) ;
V_1269 = V_1265 ;
}
V_17 = F_631 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_169
L_170 , V_17 ) ;
}
return V_1269 ;
}
static void F_633 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_414 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
#ifdef F_282
if ( V_2 -> V_1264 ) {
F_104 ( V_154 , L_171 ) ;
V_2 -> V_1264 -- ;
return;
}
#endif
if ( F_57 ( V_55 ) )
F_365 ( V_2 ) ;
F_424 ( V_55 ) ;
}
static int T_20 F_634 ( void )
{
int V_658 ;
F_51 ( L_172 , V_1270 , V_1271 ) ;
F_51 ( L_161 , V_1272 ) ;
F_635 () ;
V_658 = F_636 ( & V_1273 ) ;
if ( V_658 ) {
F_637 () ;
return V_658 ;
}
#ifdef F_226
F_638 ( & V_1274 ) ;
#endif
return 0 ;
}
static void T_21 F_639 ( void )
{
#ifdef F_226
F_640 ( & V_1274 ) ;
#endif
F_641 ( & V_1273 ) ;
F_637 () ;
F_642 () ;
}
static int F_643 ( struct V_1275 * V_1276 , unsigned long V_189 ,
void * V_1074 )
{
int V_1277 ;
V_1277 = F_644 ( & V_1273 . V_1278 , NULL , & V_189 ,
F_123 ) ;
return V_1277 ? V_1279 : V_1280 ;
}
