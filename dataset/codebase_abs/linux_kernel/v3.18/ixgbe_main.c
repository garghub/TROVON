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
F_97 ( V_60 -> V_89 ) ;
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
F_98 ( V_62 ) ;
V_159 -- ;
} while ( F_99 ( V_159 ) );
V_48 += V_58 -> V_88 ;
V_58 -> V_79 = V_48 ;
F_100 ( & V_58 -> V_167 ) ;
V_58 -> V_122 . V_168 += V_157 ;
V_58 -> V_122 . V_142 += V_158 ;
F_101 ( & V_58 -> V_167 ) ;
V_156 -> V_160 . V_157 += V_157 ;
V_156 -> V_160 . V_158 += V_158 ;
if ( F_102 ( V_58 ) && F_90 ( V_58 ) ) {
struct V_15 * V_14 = & V_2 -> V_14 ;
F_103 ( V_154 , L_61
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
F_104 ( V_58 -> V_55 , V_58 -> V_86 ) ;
F_105 ( V_170 ,
L_69 ,
V_2 -> V_171 + 1 , V_58 -> V_86 ) ;
F_92 ( V_2 ) ;
return true ;
}
F_106 ( F_107 ( V_58 ) ,
V_158 , V_157 ) ;
#define F_108 (DESC_NEEDED * 2)
if ( F_24 ( V_158 && F_109 ( V_58 -> V_55 ) &&
( F_110 ( V_58 ) >= F_108 ) ) ) {
F_111 () ;
if ( F_112 ( V_58 -> V_55 ,
V_58 -> V_86 )
&& ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
F_113 ( V_58 -> V_55 ,
V_58 -> V_86 ) ;
++ V_58 -> V_150 . V_172 ;
}
}
return ! ! V_159 ;
}
static void F_114 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
int V_173 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_174 = F_115 ( V_58 -> V_73 , V_173 ) ;
T_2 V_175 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_175 = F_116 ( V_58 -> V_147 ) ;
break;
case V_111 :
case V_112 :
V_175 = F_117 ( V_58 -> V_147 ) ;
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
static void F_118 ( struct V_1 * V_2 ,
struct V_57 * V_67 ,
int V_173 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_180 = F_115 ( V_67 -> V_73 , V_173 ) ;
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
static void F_119 ( struct V_155 * V_156 )
{
struct V_1 * V_2 = V_156 -> V_2 ;
struct V_57 * V_118 ;
int V_173 = F_120 () ;
if ( V_156 -> V_173 == V_173 )
goto V_184;
F_121 (ring, q_vector->tx)
F_114 ( V_2 , V_118 , V_173 ) ;
F_121 (ring, q_vector->rx)
F_118 ( V_2 , V_118 , V_173 ) ;
V_156 -> V_173 = V_173 ;
V_184:
F_122 () ;
}
static void F_123 ( struct V_1 * V_2 )
{
int V_48 ;
if ( ! ( V_2 -> V_137 & V_185 ) )
return;
F_71 ( & V_2 -> V_14 , V_186 , 2 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_187 ; V_48 ++ ) {
V_2 -> V_156 [ V_48 ] -> V_173 = - 1 ;
F_119 ( V_2 -> V_156 [ V_48 ] ) ;
}
}
static int F_124 ( struct V_188 * V_73 , void * V_92 )
{
struct V_1 * V_2 = F_125 ( V_73 ) ;
unsigned long V_189 = * ( unsigned long * ) V_92 ;
if ( ! ( V_2 -> V_137 & V_190 ) )
return 0 ;
switch ( V_189 ) {
case V_191 :
if ( V_2 -> V_137 & V_185 )
break;
if ( F_126 ( V_73 ) == 0 ) {
V_2 -> V_137 |= V_185 ;
F_123 ( V_2 ) ;
break;
}
case V_192 :
if ( V_2 -> V_137 & V_185 ) {
F_127 ( V_73 ) ;
V_2 -> V_137 &= ~ V_185 ;
F_71 ( & V_2 -> V_14 , V_186 , 1 ) ;
}
break;
}
return 0 ;
}
static inline void F_128 ( struct V_57 * V_118 ,
union V_68 * V_69 ,
struct V_193 * V_89 )
{
if ( V_118 -> V_55 -> V_194 & V_195 )
F_129 ( V_89 ,
F_67 ( V_69 -> V_94 . V_196 . V_197 . V_198 ) ,
V_199 ) ;
}
static inline bool F_130 ( struct V_57 * V_118 ,
union V_68 * V_69 )
{
T_8 V_200 = V_69 -> V_94 . V_196 . V_201 . V_202 . V_200 ;
return F_14 ( V_203 , & V_118 -> V_34 ) &&
( ( V_200 & F_131 ( V_204 ) ) ==
( F_131 ( V_205 <<
V_206 ) ) ) ;
}
static inline void F_132 ( struct V_57 * V_118 ,
union V_68 * V_69 ,
struct V_193 * V_89 )
{
F_133 ( V_89 ) ;
if ( ! ( V_118 -> V_55 -> V_194 & V_207 ) )
return;
if ( F_134 ( V_69 , V_208 ) &&
F_134 ( V_69 , V_209 ) ) {
V_118 -> V_210 . V_211 ++ ;
return;
}
if ( ! F_134 ( V_69 , V_212 ) )
return;
if ( F_134 ( V_69 , V_213 ) ) {
T_8 V_200 = V_69 -> V_94 . V_196 . V_201 . V_202 . V_200 ;
if ( ( V_200 & F_131 ( V_214 ) ) &&
F_14 ( V_215 , & V_118 -> V_34 ) )
return;
V_118 -> V_210 . V_211 ++ ;
return;
}
V_89 -> V_216 = V_217 ;
}
static inline void F_135 ( struct V_57 * V_67 , T_1 V_218 )
{
V_67 -> V_80 = V_218 ;
V_67 -> V_219 = V_218 ;
F_136 () ;
F_137 ( V_67 , V_218 ) ;
}
static bool F_138 ( struct V_57 * V_67 ,
struct V_70 * V_220 )
{
struct V_98 * V_98 = V_220 -> V_98 ;
T_9 V_81 = V_220 -> V_81 ;
if ( F_99 ( V_81 ) )
return true ;
if ( F_99 ( ! V_98 ) ) {
V_98 = F_139 ( V_221 | V_222 | V_223 ,
V_220 -> V_89 , F_140 ( V_67 ) ) ;
if ( F_24 ( ! V_98 ) ) {
V_67 -> V_210 . V_224 ++ ;
return false ;
}
V_220 -> V_98 = V_98 ;
}
V_81 = F_141 ( V_67 -> V_73 , V_98 , 0 ,
F_142 ( V_67 ) , V_225 ) ;
if ( F_143 ( V_67 -> V_73 , V_81 ) ) {
F_144 ( V_98 , F_140 ( V_67 ) ) ;
V_220 -> V_98 = NULL ;
V_67 -> V_210 . V_224 ++ ;
return false ;
}
V_220 -> V_81 = V_81 ;
V_220 -> V_99 = 0 ;
return true ;
}
void F_145 ( struct V_57 * V_67 , T_2 V_226 )
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
if ( ! F_138 ( V_67 , V_220 ) )
break;
V_69 -> V_227 . V_228 = F_146 ( V_220 -> V_81 + V_220 -> V_99 ) ;
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
F_135 ( V_67 , V_48 ) ;
}
static void F_147 ( struct V_57 * V_118 ,
struct V_193 * V_89 )
{
T_2 V_230 = F_148 ( V_89 ) ;
F_149 ( V_89 ) -> V_231 = F_150 ( ( V_89 -> V_82 - V_230 ) ,
F_151 ( V_89 ) -> V_232 ) ;
F_149 ( V_89 ) -> V_233 = V_234 ;
}
static void F_152 ( struct V_57 * V_67 ,
struct V_193 * V_89 )
{
if ( ! F_151 ( V_89 ) -> V_232 )
return;
V_67 -> V_210 . V_235 += F_151 ( V_89 ) -> V_232 ;
V_67 -> V_210 . V_236 ++ ;
F_147 ( V_67 , V_89 ) ;
F_151 ( V_89 ) -> V_232 = 0 ;
}
static void F_153 ( struct V_57 * V_67 ,
union V_68 * V_69 ,
struct V_193 * V_89 )
{
struct V_54 * V_73 = V_67 -> V_55 ;
F_152 ( V_67 , V_89 ) ;
F_128 ( V_67 , V_69 , V_89 ) ;
F_132 ( V_67 , V_69 , V_89 ) ;
if ( F_24 ( F_134 ( V_69 , V_237 ) ) )
F_154 ( V_67 -> V_156 -> V_2 , V_89 ) ;
if ( ( V_73 -> V_194 & V_238 ) &&
F_134 ( V_69 , V_239 ) ) {
T_2 V_240 = F_155 ( V_69 -> V_94 . V_95 . V_241 ) ;
F_156 ( V_89 , F_157 ( V_242 ) , V_240 ) ;
}
F_158 ( V_89 , V_67 -> V_86 ) ;
V_89 -> V_243 = F_159 ( V_89 , V_73 ) ;
}
static void F_160 ( struct V_155 * V_156 ,
struct V_193 * V_89 )
{
struct V_1 * V_2 = V_156 -> V_2 ;
if ( F_161 ( V_156 ) )
F_162 ( V_89 ) ;
else if ( ! ( V_2 -> V_137 & V_244 ) )
F_163 ( & V_156 -> V_245 , V_89 ) ;
else
F_164 ( V_89 ) ;
}
static bool F_165 ( struct V_57 * V_67 ,
union V_68 * V_69 ,
struct V_193 * V_89 )
{
T_1 V_246 = V_67 -> V_79 + 1 ;
V_246 = ( V_246 < V_67 -> V_88 ) ? V_246 : 0 ;
V_67 -> V_79 = V_246 ;
F_98 ( F_66 ( V_67 , V_246 ) ) ;
if ( F_166 ( V_67 ) ) {
T_10 V_247 = V_69 -> V_94 . V_196 . V_201 . V_92 &
F_96 ( V_248 ) ;
if ( F_24 ( V_247 ) ) {
T_1 V_249 = F_67 ( V_247 ) ;
V_249 >>= V_250 ;
F_151 ( V_89 ) -> V_232 += V_249 - 1 ;
V_246 = F_67 ( V_69 -> V_94 . V_95 . V_96 ) ;
V_246 &= V_251 ;
V_246 >>= V_252 ;
}
}
if ( F_99 ( F_134 ( V_69 , V_253 ) ) )
return false ;
V_67 -> V_71 [ V_246 ] . V_89 = V_89 ;
V_67 -> V_210 . V_254 ++ ;
return true ;
}
static void F_167 ( struct V_57 * V_67 ,
struct V_193 * V_89 )
{
struct V_255 * V_256 = & F_149 ( V_89 ) -> V_257 [ 0 ] ;
unsigned char * V_258 ;
unsigned int V_259 ;
V_258 = F_168 ( V_256 ) ;
V_259 = F_169 ( V_258 , V_260 ) ;
F_170 ( V_89 , V_258 , F_171 ( V_259 , sizeof( long ) ) ) ;
F_172 ( V_256 , V_259 ) ;
V_256 -> V_99 += V_259 ;
V_89 -> V_261 -= V_259 ;
V_89 -> V_144 += V_259 ;
}
static void F_173 ( struct V_57 * V_67 ,
struct V_193 * V_89 )
{
if ( F_24 ( F_151 ( V_89 ) -> V_262 ) ) {
F_80 ( V_67 -> V_73 , F_151 ( V_89 ) -> V_81 ,
F_142 ( V_67 ) , V_225 ) ;
F_151 ( V_89 ) -> V_262 = false ;
} else {
struct V_255 * V_256 = & F_149 ( V_89 ) -> V_257 [ 0 ] ;
F_174 ( V_67 -> V_73 ,
F_151 ( V_89 ) -> V_81 ,
V_256 -> V_99 ,
F_69 ( V_67 ) ,
V_225 ) ;
}
F_151 ( V_89 ) -> V_81 = 0 ;
}
static bool F_175 ( struct V_57 * V_67 ,
union V_68 * V_69 ,
struct V_193 * V_89 )
{
struct V_54 * V_55 = V_67 -> V_55 ;
if ( F_24 ( F_134 ( V_69 ,
V_263 ) &&
! ( V_55 -> V_194 & V_264 ) ) ) {
F_78 ( V_89 ) ;
return true ;
}
if ( F_176 ( V_89 ) )
F_167 ( V_67 , V_89 ) ;
#ifdef F_177
if ( F_130 ( V_67 , V_69 ) )
return false ;
#endif
if ( F_24 ( V_89 -> V_82 < 60 ) ) {
int V_265 = 60 - V_89 -> V_82 ;
if ( F_178 ( V_89 , V_265 ) )
return true ;
F_179 ( V_89 , V_265 ) ;
}
return false ;
}
static void F_180 ( struct V_57 * V_67 ,
struct V_70 * V_266 )
{
struct V_70 * V_267 ;
T_2 V_268 = V_67 -> V_219 ;
V_267 = & V_67 -> V_71 [ V_268 ] ;
V_268 ++ ;
V_67 -> V_219 = ( V_268 < V_67 -> V_88 ) ? V_268 : 0 ;
V_267 -> V_98 = V_266 -> V_98 ;
V_267 -> V_81 = V_266 -> V_81 ;
V_267 -> V_99 = V_266 -> V_99 ;
F_181 ( V_67 -> V_73 , V_267 -> V_81 ,
V_267 -> V_99 ,
F_69 ( V_67 ) ,
V_225 ) ;
}
static bool F_182 ( struct V_57 * V_67 ,
struct V_70 * V_269 ,
union V_68 * V_69 ,
struct V_193 * V_89 )
{
struct V_98 * V_98 = V_269 -> V_98 ;
unsigned int V_270 = F_155 ( V_69 -> V_94 . V_95 . V_271 ) ;
#if ( V_272 < 8192 )
unsigned int V_273 = F_69 ( V_67 ) ;
#else
unsigned int V_273 = F_171 ( V_270 , V_274 ) ;
unsigned int V_275 = F_142 ( V_67 ) -
F_69 ( V_67 ) ;
#endif
if ( ( V_270 <= V_260 ) && ! F_176 ( V_89 ) ) {
unsigned char * V_258 = F_68 ( V_98 ) + V_269 -> V_99 ;
memcpy ( F_179 ( V_89 , V_270 ) , V_258 , F_171 ( V_270 , sizeof( long ) ) ) ;
if ( F_99 ( F_183 ( V_98 ) == F_184 () ) )
return true ;
F_185 ( V_98 ) ;
return false ;
}
F_186 ( V_89 , F_149 ( V_89 ) -> V_276 , V_98 ,
V_269 -> V_99 , V_270 , V_273 ) ;
if ( F_24 ( F_183 ( V_98 ) != F_184 () ) )
return false ;
#if ( V_272 < 8192 )
if ( F_24 ( F_187 ( V_98 ) != 1 ) )
return false ;
V_269 -> V_99 ^= V_273 ;
F_188 ( & V_98 -> V_277 ) ;
#else
V_269 -> V_99 += V_273 ;
if ( V_269 -> V_99 > V_275 )
return false ;
F_189 ( V_98 ) ;
#endif
return true ;
}
static struct V_193 * F_190 ( struct V_57 * V_67 ,
union V_68 * V_69 )
{
struct V_70 * V_269 ;
struct V_193 * V_89 ;
struct V_98 * V_98 ;
V_269 = & V_67 -> V_71 [ V_67 -> V_79 ] ;
V_98 = V_269 -> V_98 ;
F_191 ( V_98 ) ;
V_89 = V_269 -> V_89 ;
if ( F_99 ( ! V_89 ) ) {
void * V_278 = F_68 ( V_98 ) +
V_269 -> V_99 ;
F_98 ( V_278 ) ;
#if V_274 < 128
F_98 ( V_278 + V_274 ) ;
#endif
V_89 = F_192 ( V_67 -> V_55 ,
V_260 ) ;
if ( F_24 ( ! V_89 ) ) {
V_67 -> V_210 . V_279 ++ ;
return NULL ;
}
F_191 ( V_89 -> V_92 ) ;
if ( F_99 ( F_134 ( V_69 , V_253 ) ) )
goto V_280;
F_151 ( V_89 ) -> V_81 = V_269 -> V_81 ;
} else {
if ( F_134 ( V_69 , V_253 ) )
F_173 ( V_67 , V_89 ) ;
V_280:
F_174 ( V_67 -> V_73 ,
V_269 -> V_81 ,
V_269 -> V_99 ,
F_69 ( V_67 ) ,
V_225 ) ;
}
if ( F_182 ( V_67 , V_269 , V_69 , V_89 ) ) {
F_180 ( V_67 , V_269 ) ;
} else if ( F_151 ( V_89 ) -> V_81 == V_269 -> V_81 ) {
F_151 ( V_89 ) -> V_262 = true ;
} else {
F_80 ( V_67 -> V_73 , V_269 -> V_81 ,
F_142 ( V_67 ) ,
V_225 ) ;
}
V_269 -> V_89 = NULL ;
V_269 -> V_81 = 0 ;
V_269 -> V_98 = NULL ;
return V_89 ;
}
static int F_193 ( struct V_155 * V_156 ,
struct V_57 * V_67 ,
const int V_159 )
{
unsigned int V_281 = 0 , V_282 = 0 ;
#ifdef F_177
struct V_1 * V_2 = V_156 -> V_2 ;
int V_283 ;
unsigned int V_284 = 0 ;
#endif
T_2 V_226 = F_110 ( V_67 ) ;
while ( F_99 ( V_282 < V_159 ) ) {
union V_68 * V_69 ;
struct V_193 * V_89 ;
if ( V_226 >= V_285 ) {
F_145 ( V_67 , V_226 ) ;
V_226 = 0 ;
}
V_69 = F_66 ( V_67 , V_67 -> V_79 ) ;
if ( ! F_134 ( V_69 , V_97 ) )
break;
F_194 () ;
V_89 = F_190 ( V_67 , V_69 ) ;
if ( ! V_89 )
break;
V_226 ++ ;
if ( F_165 ( V_67 , V_69 , V_89 ) )
continue;
if ( F_175 ( V_67 , V_69 , V_89 ) )
continue;
V_281 += V_89 -> V_82 ;
F_153 ( V_67 , V_69 , V_89 ) ;
#ifdef F_177
if ( F_130 ( V_67 , V_69 ) ) {
V_283 = F_195 ( V_2 , V_69 , V_89 ) ;
if ( V_283 > 0 ) {
if ( ! V_284 ) {
V_284 = V_67 -> V_55 -> V_286 -
sizeof( struct V_287 ) -
sizeof( struct V_288 ) -
sizeof( struct V_289 ) ;
if ( V_284 > 512 )
V_284 &= ~ 511 ;
}
V_281 += V_283 ;
V_282 += F_150 ( V_283 ,
V_284 ) ;
}
if ( ! V_283 ) {
F_78 ( V_89 ) ;
continue;
}
}
#endif
F_196 ( V_89 , & V_156 -> V_245 ) ;
F_160 ( V_156 , V_89 ) ;
V_282 ++ ;
}
F_100 ( & V_67 -> V_167 ) ;
V_67 -> V_122 . V_142 += V_282 ;
V_67 -> V_122 . V_168 += V_281 ;
F_101 ( & V_67 -> V_167 ) ;
V_156 -> V_290 . V_158 += V_282 ;
V_156 -> V_290 . V_157 += V_281 ;
return V_282 ;
}
static int F_197 ( struct V_291 * V_245 )
{
struct V_155 * V_156 =
F_198 ( V_245 , struct V_155 , V_245 ) ;
struct V_1 * V_2 = V_156 -> V_2 ;
struct V_57 * V_118 ;
int V_292 = 0 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return V_293 ;
if ( ! F_199 ( V_156 ) )
return V_294 ;
F_121 (ring, q_vector->rx) {
V_292 = F_193 ( V_156 , V_118 , 4 ) ;
#ifdef F_200
if ( V_292 )
V_118 -> V_122 . V_295 += V_292 ;
else
V_118 -> V_122 . V_296 ++ ;
#endif
if ( V_292 )
break;
}
F_201 ( V_156 ) ;
return V_292 ;
}
static void F_202 ( struct V_1 * V_2 )
{
struct V_155 * V_156 ;
int V_297 ;
T_1 V_115 ;
if ( V_2 -> V_298 > 32 ) {
T_1 V_299 = ( 1 << ( V_2 -> V_298 - 32 ) ) - 1 ;
F_71 ( & V_2 -> V_14 , V_300 , V_299 ) ;
}
for ( V_297 = 0 ; V_297 < V_2 -> V_187 ; V_297 ++ ) {
struct V_57 * V_118 ;
V_156 = V_2 -> V_156 [ V_297 ] ;
F_121 (ring, q_vector->rx)
F_73 ( V_2 , 0 , V_118 -> V_147 , V_297 ) ;
F_121 (ring, q_vector->tx)
F_73 ( V_2 , 1 , V_118 -> V_147 , V_297 ) ;
F_203 ( V_156 ) ;
}
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
F_73 ( V_2 , - 1 , V_301 ,
V_297 ) ;
break;
case V_111 :
case V_112 :
F_73 ( V_2 , - 1 , 1 , V_297 ) ;
break;
default:
break;
}
F_71 ( & V_2 -> V_14 , F_204 ( V_297 ) , 1950 ) ;
V_115 = V_302 ;
V_115 &= ~ ( V_303 |
V_304 |
V_305 ) ;
F_71 ( & V_2 -> V_14 , V_306 , V_115 ) ;
}
static void F_205 ( struct V_155 * V_156 ,
struct V_307 * V_308 )
{
int V_168 = V_308 -> V_157 ;
int V_142 = V_308 -> V_158 ;
T_1 V_309 ;
T_6 V_310 ;
T_4 V_311 = V_308 -> V_312 ;
if ( V_142 == 0 )
return;
V_309 = V_156 -> V_312 >> 2 ;
if ( V_309 == 0 )
return;
V_310 = V_168 / V_309 ;
switch ( V_311 ) {
case V_313 :
if ( V_310 > 10 )
V_311 = V_314 ;
break;
case V_314 :
if ( V_310 > 20 )
V_311 = V_315 ;
else if ( V_310 <= 10 )
V_311 = V_313 ;
break;
case V_315 :
if ( V_310 <= 20 )
V_311 = V_314 ;
break;
}
V_308 -> V_157 = 0 ;
V_308 -> V_158 = 0 ;
V_308 -> V_312 = V_311 ;
}
void F_203 ( struct V_155 * V_156 )
{
struct V_1 * V_2 = V_156 -> V_2 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_297 = V_156 -> V_297 ;
T_1 V_316 = V_156 -> V_312 & V_317 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
V_316 |= ( V_316 << 16 ) ;
break;
case V_111 :
case V_112 :
V_316 |= V_318 ;
break;
default:
break;
}
F_71 ( V_14 , F_204 ( V_297 ) , V_316 ) ;
}
static void F_206 ( struct V_155 * V_156 )
{
T_1 V_319 = V_156 -> V_312 ;
T_4 V_320 ;
F_205 ( V_156 , & V_156 -> V_160 ) ;
F_205 ( V_156 , & V_156 -> V_290 ) ;
V_320 = F_207 ( V_156 -> V_290 . V_312 , V_156 -> V_160 . V_312 ) ;
switch ( V_320 ) {
case V_313 :
V_319 = V_321 ;
break;
case V_314 :
V_319 = V_322 ;
break;
case V_315 :
V_319 = V_323 ;
break;
default:
break;
}
if ( V_319 != V_156 -> V_312 ) {
V_319 = ( 10 * V_319 * V_156 -> V_312 ) /
( ( 9 * V_319 ) + V_156 -> V_312 ) ;
V_156 -> V_312 = V_319 ;
F_203 ( V_156 ) ;
}
}
static void F_208 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_324 = V_2 -> V_325 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
if ( ! ( V_2 -> V_152 & V_326 ) &&
! ( V_2 -> V_152 & V_327 ) )
return;
V_2 -> V_152 &= ~ V_327 ;
switch ( V_14 -> V_21 ) {
case V_328 :
if ( ! ( V_324 & V_329 ) &&
! ( V_324 & V_330 ) )
return;
if ( ! ( V_324 & V_330 ) && V_14 -> V_108 . V_331 . V_332 ) {
T_1 V_20 ;
bool V_333 = false ;
V_14 -> V_108 . V_331 . V_332 ( V_14 , & V_20 , & V_333 , false ) ;
if ( V_333 )
return;
}
if ( V_14 -> V_334 . V_331 . V_335 ( V_14 ) != V_336 )
return;
break;
default:
if ( ! ( V_324 & V_329 ) )
return;
break;
}
F_209 ( V_154 ,
L_70
L_71
L_72 ) ;
V_2 -> V_325 = 0 ;
}
static void F_210 ( struct V_1 * V_2 , T_1 V_324 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ( V_2 -> V_137 & V_337 ) &&
( V_324 & V_338 ) ) {
F_209 ( V_170 , L_73 ) ;
F_71 ( V_14 , V_339 , V_338 ) ;
}
}
static void F_211 ( struct V_1 * V_2 , T_1 V_324 )
{
if ( ! ( V_2 -> V_152 & V_326 ) )
return;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
if ( ( ( V_324 & V_329 ) || ( V_324 & V_330 ) ) &&
( ! F_14 ( V_33 , & V_2 -> V_34 ) ) ) {
V_2 -> V_325 = V_324 ;
V_2 -> V_152 |= V_327 ;
F_13 ( V_2 ) ;
return;
}
return;
case V_112 :
if ( ! ( V_324 & V_340 ) )
return;
break;
default:
return;
}
F_209 ( V_154 ,
L_70
L_71
L_72 ) ;
}
static void F_212 ( struct V_1 * V_2 , T_1 V_324 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_324 & V_341 ) {
F_71 ( V_14 , V_339 , V_341 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_152 |= V_342 ;
F_13 ( V_2 ) ;
}
}
if ( V_324 & V_338 ) {
F_71 ( V_14 , V_339 , V_338 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_137 |= V_343 ;
F_13 ( V_2 ) ;
}
}
}
static void F_213 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_344 ++ ;
V_2 -> V_137 |= V_345 ;
V_2 -> V_346 = V_169 ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
F_71 ( V_14 , V_347 , V_348 ) ;
F_214 ( V_14 ) ;
F_13 ( V_2 ) ;
}
}
static inline void F_215 ( struct V_1 * V_2 ,
T_6 V_114 )
{
T_1 V_115 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_115 = ( V_116 & V_114 ) ;
F_71 ( V_14 , V_349 , V_115 ) ;
break;
case V_111 :
case V_112 :
V_115 = ( V_114 & 0xFFFFFFFF ) ;
if ( V_115 )
F_71 ( V_14 , F_216 ( 0 ) , V_115 ) ;
V_115 = ( V_114 >> 32 ) ;
if ( V_115 )
F_71 ( V_14 , F_216 ( 1 ) , V_115 ) ;
break;
default:
break;
}
}
static inline void F_217 ( struct V_1 * V_2 ,
T_6 V_114 )
{
T_1 V_115 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_115 = ( V_116 & V_114 ) ;
F_71 ( V_14 , V_347 , V_115 ) ;
break;
case V_111 :
case V_112 :
V_115 = ( V_114 & 0xFFFFFFFF ) ;
if ( V_115 )
F_71 ( V_14 , F_218 ( 0 ) , V_115 ) ;
V_115 = ( V_114 >> 32 ) ;
if ( V_115 )
F_71 ( V_14 , F_218 ( 1 ) , V_115 ) ;
break;
default:
break;
}
}
static inline void F_219 ( struct V_1 * V_2 , bool V_350 ,
bool V_351 )
{
T_1 V_115 = ( V_302 & ~ V_116 ) ;
if ( V_2 -> V_137 & V_345 )
V_115 &= ~ V_305 ;
if ( V_2 -> V_152 & V_326 )
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_115 |= V_352 ;
break;
case V_112 :
V_115 |= V_353 ;
break;
default:
break;
}
if ( V_2 -> V_137 & V_337 )
V_115 |= V_354 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_115 |= V_354 ;
V_115 |= V_355 ;
case V_112 :
V_115 |= V_356 ;
V_115 |= V_304 ;
break;
default:
break;
}
if ( V_2 -> V_14 . V_108 . type == V_112 )
V_115 |= V_357 ;
if ( ( V_2 -> V_137 & V_358 ) &&
! ( V_2 -> V_152 & V_359 ) )
V_115 |= V_360 ;
F_71 ( & V_2 -> V_14 , V_349 , V_115 ) ;
if ( V_350 )
F_215 ( V_2 , ~ 0 ) ;
if ( V_351 )
F_214 ( & V_2 -> V_14 ) ;
}
static T_11 F_220 ( int V_361 , void * V_92 )
{
struct V_1 * V_2 = V_92 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_324 ;
V_324 = F_37 ( V_14 , V_117 ) ;
V_324 &= 0xFFFF0000 ;
F_71 ( V_14 , V_339 , V_324 ) ;
if ( V_324 & V_330 )
F_213 ( V_2 ) ;
if ( V_324 & V_362 )
F_221 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
if ( V_324 & V_363 ) {
F_105 ( V_364 , L_74 ) ;
V_2 -> V_152 |= V_153 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_339 , V_363 ) ;
}
if ( V_324 & V_365 ) {
int V_366 = 0 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_118 = V_2 -> V_58 [ V_48 ] ;
if ( F_222 ( V_367 ,
& V_118 -> V_34 ) )
V_366 ++ ;
}
if ( V_366 ) {
F_71 ( V_14 , V_347 , V_368 ) ;
V_2 -> V_152 |= V_359 ;
F_13 ( V_2 ) ;
}
}
F_212 ( V_2 , V_324 ) ;
F_211 ( V_2 , V_324 ) ;
break;
default:
break;
}
F_210 ( V_2 , V_324 ) ;
if ( F_24 ( V_324 & V_369 ) )
F_223 ( V_2 , V_324 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_219 ( V_2 , false , false ) ;
return V_370 ;
}
static T_11 F_224 ( int V_361 , void * V_92 )
{
struct V_155 * V_156 = V_92 ;
if ( V_156 -> V_290 . V_118 || V_156 -> V_160 . V_118 )
F_225 ( & V_156 -> V_245 ) ;
return V_370 ;
}
int F_226 ( struct V_291 * V_245 , int V_159 )
{
struct V_155 * V_156 =
F_198 ( V_245 , struct V_155 , V_245 ) ;
struct V_1 * V_2 = V_156 -> V_2 ;
struct V_57 * V_118 ;
int V_371 ;
bool V_372 = true ;
#ifdef F_227
if ( V_2 -> V_137 & V_185 )
F_119 ( V_156 ) ;
#endif
F_121 (ring, q_vector->tx)
V_372 &= ! ! F_94 ( V_156 , V_118 ) ;
if ( ! F_228 ( V_156 ) )
return V_159 ;
if ( V_156 -> V_290 . V_88 > 1 )
V_371 = F_207 ( V_159 / V_156 -> V_290 . V_88 , 1 ) ;
else
V_371 = V_159 ;
F_121 (ring, q_vector->rx)
V_372 &= ( F_193 ( V_156 , V_118 ,
V_371 ) < V_371 ) ;
F_229 ( V_156 ) ;
if ( ! V_372 )
return V_159 ;
F_230 ( V_245 ) ;
if ( V_2 -> V_373 & 1 )
F_206 ( V_156 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_215 ( V_2 , ( ( T_6 ) 1 << V_156 -> V_297 ) ) ;
return 0 ;
}
static int F_231 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
int V_374 , V_17 ;
int V_375 = 0 , V_376 = 0 ;
for ( V_374 = 0 ; V_374 < V_2 -> V_187 ; V_374 ++ ) {
struct V_155 * V_156 = V_2 -> V_156 [ V_374 ] ;
struct V_377 * V_378 = & V_2 -> V_379 [ V_374 ] ;
if ( V_156 -> V_160 . V_118 && V_156 -> V_290 . V_118 ) {
snprintf ( V_156 -> V_53 , sizeof( V_156 -> V_53 ) - 1 ,
L_75 , V_55 -> V_53 , L_76 , V_375 ++ ) ;
V_376 ++ ;
} else if ( V_156 -> V_290 . V_118 ) {
snprintf ( V_156 -> V_53 , sizeof( V_156 -> V_53 ) - 1 ,
L_75 , V_55 -> V_53 , L_77 , V_375 ++ ) ;
} else if ( V_156 -> V_160 . V_118 ) {
snprintf ( V_156 -> V_53 , sizeof( V_156 -> V_53 ) - 1 ,
L_75 , V_55 -> V_53 , L_78 , V_376 ++ ) ;
} else {
continue;
}
V_17 = F_232 ( V_378 -> V_374 , & F_224 , 0 ,
V_156 -> V_53 , V_156 ) ;
if ( V_17 ) {
F_103 ( V_170 , L_79
L_80 , V_17 ) ;
goto V_380;
}
if ( V_2 -> V_137 & V_358 ) {
F_233 ( V_378 -> V_374 ,
& V_156 -> V_381 ) ;
}
}
V_17 = F_232 ( V_2 -> V_379 [ V_374 ] . V_374 ,
F_220 , 0 , V_55 -> V_53 , V_2 ) ;
if ( V_17 ) {
F_103 ( V_170 , L_81 , V_17 ) ;
goto V_380;
}
return 0 ;
V_380:
while ( V_374 ) {
V_374 -- ;
F_233 ( V_2 -> V_379 [ V_374 ] . V_374 ,
NULL ) ;
F_234 ( V_2 -> V_379 [ V_374 ] . V_374 ,
V_2 -> V_156 [ V_374 ] ) ;
}
V_2 -> V_137 &= ~ V_382 ;
F_235 ( V_2 -> V_9 ) ;
F_236 ( V_2 -> V_379 ) ;
V_2 -> V_379 = NULL ;
return V_17 ;
}
static T_11 F_237 ( int V_361 , void * V_92 )
{
struct V_1 * V_2 = V_92 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_155 * V_156 = V_2 -> V_156 [ 0 ] ;
T_1 V_324 ;
F_71 ( V_14 , V_347 , V_383 ) ;
V_324 = F_37 ( V_14 , V_339 ) ;
if ( ! V_324 ) {
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_219 ( V_2 , true , true ) ;
return V_384 ;
}
if ( V_324 & V_330 )
F_213 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
F_212 ( V_2 , V_324 ) ;
case V_112 :
if ( V_324 & V_363 ) {
F_105 ( V_364 , L_74 ) ;
V_2 -> V_152 |= V_153 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_339 , V_363 ) ;
}
F_211 ( V_2 , V_324 ) ;
break;
default:
break;
}
F_210 ( V_2 , V_324 ) ;
if ( F_24 ( V_324 & V_369 ) )
F_223 ( V_2 , V_324 ) ;
F_225 ( & V_156 -> V_245 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_219 ( V_2 , false , false ) ;
return V_370 ;
}
static int F_238 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
int V_17 ;
if ( V_2 -> V_137 & V_382 )
V_17 = F_231 ( V_2 ) ;
else if ( V_2 -> V_137 & V_385 )
V_17 = F_232 ( V_2 -> V_9 -> V_361 , F_237 , 0 ,
V_55 -> V_53 , V_2 ) ;
else
V_17 = F_232 ( V_2 -> V_9 -> V_361 , F_237 , V_386 ,
V_55 -> V_53 , V_2 ) ;
if ( V_17 )
F_103 ( V_170 , L_82 , V_17 ) ;
return V_17 ;
}
static void F_239 ( struct V_1 * V_2 )
{
int V_374 ;
if ( ! ( V_2 -> V_137 & V_382 ) ) {
F_234 ( V_2 -> V_9 -> V_361 , V_2 ) ;
return;
}
for ( V_374 = 0 ; V_374 < V_2 -> V_187 ; V_374 ++ ) {
struct V_155 * V_156 = V_2 -> V_156 [ V_374 ] ;
struct V_377 * V_378 = & V_2 -> V_379 [ V_374 ] ;
if ( ! V_156 -> V_290 . V_118 && ! V_156 -> V_160 . V_118 )
continue;
F_233 ( V_378 -> V_374 , NULL ) ;
F_234 ( V_378 -> V_374 , V_156 ) ;
}
F_234 ( V_2 -> V_379 [ V_374 ++ ] . V_374 , V_2 ) ;
}
static inline void F_240 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
F_71 ( & V_2 -> V_14 , V_347 , ~ 0 ) ;
break;
case V_111 :
case V_112 :
F_71 ( & V_2 -> V_14 , V_347 , 0xFFFF0000 ) ;
F_71 ( & V_2 -> V_14 , F_218 ( 0 ) , ~ 0 ) ;
F_71 ( & V_2 -> V_14 , F_218 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_214 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_137 & V_382 ) {
int V_374 ;
for ( V_374 = 0 ; V_374 < V_2 -> V_187 ; V_374 ++ )
F_241 ( V_2 -> V_379 [ V_374 ] . V_374 ) ;
F_241 ( V_2 -> V_379 [ V_374 ++ ] . V_374 ) ;
} else {
F_241 ( V_2 -> V_9 -> V_361 ) ;
}
}
static void F_242 ( struct V_1 * V_2 )
{
struct V_155 * V_156 = V_2 -> V_156 [ 0 ] ;
F_203 ( V_156 ) ;
F_73 ( V_2 , 0 , 0 , 0 ) ;
F_73 ( V_2 , 1 , 0 , 0 ) ;
F_105 ( V_14 , L_83 ) ;
}
void F_243 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_387 = V_118 -> V_81 ;
int V_388 = 10 ;
T_1 V_389 = V_390 ;
T_4 V_147 = V_118 -> V_147 ;
F_71 ( V_14 , F_50 ( V_147 ) , 0 ) ;
F_214 ( V_14 ) ;
F_71 ( V_14 , F_45 ( V_147 ) ,
( V_387 & F_244 ( 32 ) ) ) ;
F_71 ( V_14 , F_46 ( V_147 ) , ( V_387 >> 32 ) ) ;
F_71 ( V_14 , F_47 ( V_147 ) ,
V_118 -> V_88 * sizeof( union V_61 ) ) ;
F_71 ( V_14 , F_48 ( V_147 ) , 0 ) ;
F_71 ( V_14 , F_49 ( V_147 ) , 0 ) ;
V_118 -> V_144 = V_2 -> V_391 + F_49 ( V_147 ) ;
if ( ! V_118 -> V_156 || ( V_118 -> V_156 -> V_312 < V_321 ) )
V_389 |= ( 1 << 16 ) ;
else
V_389 |= ( 8 << 16 ) ;
V_389 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_137 & V_358 ) {
V_118 -> V_392 = V_2 -> V_392 ;
V_118 -> V_393 = 0 ;
F_245 ( V_367 , & V_118 -> V_34 ) ;
} else {
V_118 -> V_392 = 0 ;
}
if ( ! F_15 ( V_394 , & V_118 -> V_34 ) ) {
struct V_155 * V_156 = V_118 -> V_156 ;
if ( V_156 )
F_246 ( V_118 -> V_55 ,
& V_156 -> V_381 ,
V_118 -> V_86 ) ;
}
F_34 ( V_130 , & V_118 -> V_34 ) ;
F_71 ( V_14 , F_50 ( V_147 ) , V_389 ) ;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_395 ) & V_396 ) )
return;
do {
F_247 ( 1000 , 2000 ) ;
V_389 = F_37 ( V_14 , F_50 ( V_147 ) ) ;
} while ( -- V_388 && ! ( V_389 & V_390 ) );
if ( ! V_388 )
F_103 ( V_154 , L_84 , V_147 ) ;
}
static void F_248 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_397 , V_398 ;
T_4 V_399 = F_249 ( V_2 -> V_55 ) ;
if ( V_14 -> V_108 . type == V_109 )
return;
V_397 = F_37 ( V_14 , V_400 ) ;
V_397 |= V_401 ;
F_71 ( V_14 , V_400 , V_397 ) ;
if ( V_2 -> V_137 & V_402 ) {
V_398 = V_403 ;
if ( V_399 > 4 )
V_398 |= V_404 | V_405 ;
else if ( V_399 > 1 )
V_398 |= V_404 | V_406 ;
else if ( V_2 -> V_407 [ V_408 ] . V_409 == 4 )
V_398 |= V_410 ;
else
V_398 |= V_411 ;
} else {
if ( V_399 > 4 )
V_398 = V_404 | V_405 ;
else if ( V_399 > 1 )
V_398 = V_404 | V_406 ;
else
V_398 = V_412 ;
}
F_71 ( V_14 , V_413 , V_398 ) ;
if ( V_399 ) {
T_1 V_414 = F_37 ( V_14 , V_415 ) ;
V_414 |= V_416 ;
F_71 ( V_14 , V_415 , V_414 ) ;
}
V_397 &= ~ V_401 ;
F_71 ( V_14 , V_400 , V_397 ) ;
}
static void F_250 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_417 ;
T_1 V_48 ;
F_248 ( V_2 ) ;
if ( V_14 -> V_108 . type != V_109 ) {
V_417 = F_37 ( V_14 , V_418 ) ;
V_417 |= V_419 ;
F_71 ( V_14 , V_418 , V_417 ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_243 ( V_2 , V_2 -> V_58 [ V_48 ] ) ;
}
static void F_251 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_147 = V_118 -> V_147 ;
T_1 V_420 = F_37 ( V_14 , F_36 ( V_147 ) ) ;
V_420 |= V_421 ;
F_71 ( V_14 , F_36 ( V_147 ) , V_420 ) ;
}
static void F_252 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_147 = V_118 -> V_147 ;
T_1 V_420 = F_37 ( V_14 , F_36 ( V_147 ) ) ;
V_420 &= ~ V_421 ;
F_71 ( V_14 , F_36 ( V_147 ) , V_420 ) ;
}
static void F_253 ( struct V_1 * V_2 ,
struct V_57 * V_67 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_420 ;
T_4 V_147 = V_67 -> V_147 ;
if ( V_14 -> V_108 . type == V_109 ) {
T_2 V_115 = V_2 -> V_407 [ V_408 ] . V_115 ;
V_147 &= V_115 ;
}
V_420 = V_260 << V_422 ;
V_420 |= F_69 ( V_67 ) >> V_423 ;
V_420 |= V_424 ;
F_71 ( V_14 , F_36 ( V_147 ) , V_420 ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
static const T_1 V_425 [ 10 ] = { 0xE291D73D , 0x1805EC6C , 0x2A94B30D ,
0xA54F2BEC , 0xEA49AF7C , 0xE214AD3D , 0xB855AABE ,
0x6A3E67EA , 0x14364D17 , 0x3BED200D } ;
T_1 V_426 = 0 , V_427 = 0 ;
T_1 V_428 ;
int V_48 , V_49 ;
T_2 V_429 = V_2 -> V_407 [ V_408 ] . V_409 ;
if ( ( V_2 -> V_137 & V_402 ) && ( V_429 < 2 ) )
V_429 = 2 ;
for ( V_48 = 0 ; V_48 < 10 ; V_48 ++ )
F_71 ( V_14 , F_255 ( V_48 ) , V_425 [ V_48 ] ) ;
for ( V_48 = 0 , V_49 = 0 ; V_48 < 128 ; V_48 ++ , V_49 ++ ) {
if ( V_49 == V_429 )
V_49 = 0 ;
V_427 = ( V_427 << 8 ) | ( V_49 * 0x11 ) ;
if ( ( V_48 & 3 ) == 3 )
F_71 ( V_14 , F_256 ( V_48 >> 2 ) , V_427 ) ;
}
V_428 = F_37 ( V_14 , V_430 ) ;
V_428 |= V_431 ;
F_71 ( V_14 , V_430 , V_428 ) ;
if ( V_2 -> V_14 . V_108 . type == V_109 ) {
if ( V_2 -> V_407 [ V_408 ] . V_115 )
V_426 = V_432 ;
} else {
T_4 V_399 = F_249 ( V_2 -> V_55 ) ;
if ( V_2 -> V_137 & V_402 ) {
if ( V_399 > 4 )
V_426 = V_433 ;
else if ( V_399 > 1 )
V_426 = V_434 ;
else if ( V_2 -> V_407 [ V_408 ] . V_409 == 4 )
V_426 = V_435 ;
else
V_426 = V_436 ;
} else {
if ( V_399 > 4 )
V_426 = V_437 ;
else if ( V_399 > 1 )
V_426 = V_438 ;
else
V_426 = V_432 ;
}
}
V_426 |= V_439 |
V_440 |
V_441 |
V_442 ;
if ( V_2 -> V_152 & V_443 )
V_426 |= V_444 ;
if ( V_2 -> V_152 & V_445 )
V_426 |= V_446 ;
F_71 ( V_14 , V_447 , V_426 ) ;
}
static void F_257 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_448 ;
T_4 V_147 = V_118 -> V_147 ;
if ( ! F_166 ( V_118 ) )
return;
V_448 = F_37 ( V_14 , F_258 ( V_147 ) ) ;
V_448 |= V_449 ;
V_448 |= V_450 ;
F_71 ( V_14 , F_258 ( V_147 ) , V_448 ) ;
}
static void F_259 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_388 = V_451 ;
T_1 V_452 ;
T_4 V_147 = V_118 -> V_147 ;
if ( F_22 ( V_14 -> V_39 ) )
return;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_395 ) & V_396 ) )
return;
do {
F_247 ( 1000 , 2000 ) ;
V_452 = F_37 ( V_14 , F_42 ( V_147 ) ) ;
} while ( -- V_388 && ! ( V_452 & V_453 ) );
if ( ! V_388 ) {
F_103 ( V_154 , L_85
L_86 , V_147 ) ;
}
}
void F_260 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_388 = V_451 ;
T_1 V_452 ;
T_4 V_147 = V_118 -> V_147 ;
if ( F_22 ( V_14 -> V_39 ) )
return;
V_452 = F_37 ( V_14 , F_42 ( V_147 ) ) ;
V_452 &= ~ V_453 ;
F_71 ( V_14 , F_42 ( V_147 ) , V_452 ) ;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_395 ) & V_396 ) )
return;
do {
F_261 ( 10 ) ;
V_452 = F_37 ( V_14 , F_42 ( V_147 ) ) ;
} while ( -- V_388 && ( V_452 & V_453 ) );
if ( ! V_388 ) {
F_103 ( V_154 , L_87
L_86 , V_147 ) ;
}
}
void F_262 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_454 = V_118 -> V_81 ;
T_1 V_452 ;
T_4 V_147 = V_118 -> V_147 ;
V_452 = F_37 ( V_14 , F_42 ( V_147 ) ) ;
F_260 ( V_2 , V_118 ) ;
F_71 ( V_14 , F_43 ( V_147 ) , ( V_454 & F_244 ( 32 ) ) ) ;
F_71 ( V_14 , F_44 ( V_147 ) , ( V_454 >> 32 ) ) ;
F_71 ( V_14 , F_39 ( V_147 ) ,
V_118 -> V_88 * sizeof( union V_68 ) ) ;
F_71 ( V_14 , F_40 ( V_147 ) , 0 ) ;
F_71 ( V_14 , F_41 ( V_147 ) , 0 ) ;
V_118 -> V_144 = V_2 -> V_391 + F_41 ( V_147 ) ;
F_253 ( V_2 , V_118 ) ;
F_257 ( V_2 , V_118 ) ;
if ( V_14 -> V_108 . type == V_109 ) {
V_452 &= ~ 0x3FFFFF ;
V_452 |= 0x080420 ;
}
V_452 |= V_453 ;
F_71 ( V_14 , F_42 ( V_147 ) , V_452 ) ;
F_259 ( V_2 , V_118 ) ;
F_145 ( V_118 , F_110 ( V_118 ) ) ;
}
static void F_263 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_429 = V_2 -> V_407 [ V_408 ] . V_409 ;
T_2 V_455 ;
T_1 V_456 = V_457 |
V_458 |
V_459 |
V_460 |
V_461 ;
if ( V_14 -> V_108 . type == V_109 )
return;
if ( V_429 > 3 )
V_456 |= 2 << 29 ;
else if ( V_429 > 1 )
V_456 |= 1 << 29 ;
F_264 (pool, &adapter->fwd_bitmask, 32 )
F_71 ( V_14 , F_265 ( F_266 ( V_455 ) ) , V_456 ) ;
}
static void F_267 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_175 , V_462 ;
T_1 V_463 , V_464 ;
int V_48 ;
if ( ! ( V_2 -> V_137 & V_402 ) )
return;
V_464 = F_37 ( V_14 , V_465 ) ;
V_464 |= V_466 ;
V_464 &= ~ V_467 ;
V_464 |= F_266 ( 0 ) << V_468 ;
V_464 |= V_469 ;
F_71 ( V_14 , V_465 , V_464 ) ;
V_462 = F_266 ( 0 ) % 32 ;
V_175 = ( F_266 ( 0 ) >= 32 ) ? 1 : 0 ;
F_71 ( V_14 , F_268 ( V_175 ) , ( ~ 0 ) << V_462 ) ;
F_71 ( V_14 , F_268 ( V_175 ^ 1 ) , V_175 - 1 ) ;
F_71 ( V_14 , F_269 ( V_175 ) , ( ~ 0 ) << V_462 ) ;
F_71 ( V_14 , F_269 ( V_175 ^ 1 ) , V_175 - 1 ) ;
if ( V_2 -> V_152 & V_470 )
F_71 ( V_14 , V_471 , V_472 ) ;
V_14 -> V_108 . V_331 . V_473 ( V_14 , 0 , F_266 ( 0 ) ) ;
switch ( V_2 -> V_407 [ V_474 ] . V_115 ) {
case V_475 :
V_463 = V_476 ;
break;
case V_477 :
V_463 = V_478 ;
break;
default:
V_463 = V_479 ;
break;
}
F_71 ( V_14 , V_480 , V_463 ) ;
V_14 -> V_108 . V_331 . V_481 ( V_14 , ( V_2 -> V_298 != 0 ) ,
V_2 -> V_298 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_298 ; V_48 ++ ) {
if ( ! V_2 -> V_482 [ V_48 ] . V_483 )
F_270 ( V_2 -> V_55 , V_48 , false ) ;
}
}
static void F_271 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_55 = V_2 -> V_55 ;
int V_484 = V_55 -> V_286 + V_485 + V_486 ;
struct V_57 * V_67 ;
int V_48 ;
T_1 V_487 , V_488 ;
#ifdef F_177
if ( ( V_2 -> V_137 & V_489 ) &&
( V_484 < V_490 ) )
V_484 = V_490 ;
#endif
if ( V_484 < ( V_491 + V_486 ) )
V_484 = ( V_491 + V_486 ) ;
V_487 = F_37 ( V_14 , V_492 ) ;
if ( V_484 != ( V_487 >> V_493 ) ) {
V_487 &= ~ V_494 ;
V_487 |= V_484 << V_493 ;
F_71 ( V_14 , V_492 , V_487 ) ;
}
V_488 = F_37 ( V_14 , V_495 ) ;
V_488 |= V_496 ;
F_71 ( V_14 , V_495 , V_488 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_67 = V_2 -> V_67 [ V_48 ] ;
if ( V_2 -> V_152 & V_497 )
F_272 ( V_67 ) ;
else
F_273 ( V_67 ) ;
}
}
static void F_274 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_498 = F_37 ( V_14 , V_499 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_498 |= V_500 ;
break;
case V_111 :
case V_112 :
F_71 ( V_14 , V_501 ,
( V_502 | F_37 ( V_14 , V_501 ) ) ) ;
V_498 &= ~ V_503 ;
V_498 |= ( V_504 | V_505 ) ;
V_498 |= V_506 ;
break;
default:
return;
}
F_71 ( V_14 , V_499 , V_498 ) ;
}
static void F_275 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
T_1 V_180 , V_507 ;
V_180 = F_37 ( V_14 , V_508 ) ;
F_71 ( V_14 , V_508 , V_180 & ~ V_509 ) ;
F_263 ( V_2 ) ;
F_274 ( V_2 ) ;
V_507 = F_37 ( V_14 , V_510 ) ;
V_507 &= ~ V_511 ;
if ( ! ( V_2 -> V_152 & V_497 ) )
V_507 |= V_511 ;
F_71 ( V_14 , V_510 , V_507 ) ;
F_254 ( V_2 ) ;
F_271 ( V_2 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
F_262 ( V_2 , V_2 -> V_67 [ V_48 ] ) ;
if ( V_14 -> V_108 . type == V_109 )
V_180 |= V_512 ;
V_180 |= V_509 ;
V_14 -> V_108 . V_331 . V_513 ( V_14 , V_180 ) ;
}
static int F_276 ( struct V_54 * V_55 ,
T_12 V_514 , T_2 V_240 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_108 . V_331 . V_515 ( & V_2 -> V_14 , V_240 , F_266 ( 0 ) , true ) ;
F_245 ( V_240 , V_2 -> V_516 ) ;
return 0 ;
}
static int F_277 ( struct V_54 * V_55 ,
T_12 V_514 , T_2 V_240 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_108 . V_331 . V_515 ( & V_2 -> V_14 , V_240 , F_266 ( 0 ) , false ) ;
F_34 ( V_240 , V_2 -> V_516 ) ;
return 0 ;
}
static void F_278 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_517 ;
int V_48 , V_49 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_517 = F_37 ( V_14 , V_518 ) ;
V_517 &= ~ V_519 ;
F_71 ( V_14 , V_518 , V_517 ) ;
break;
case V_111 :
case V_112 :
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_118 = V_2 -> V_67 [ V_48 ] ;
if ( V_118 -> V_145 )
continue;
V_49 = V_118 -> V_147 ;
V_517 = F_37 ( V_14 , F_42 ( V_49 ) ) ;
V_517 &= ~ V_520 ;
F_71 ( V_14 , F_42 ( V_49 ) , V_517 ) ;
}
break;
default:
break;
}
}
static void F_279 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_517 ;
int V_48 , V_49 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_517 = F_37 ( V_14 , V_518 ) ;
V_517 |= V_519 ;
F_71 ( V_14 , V_518 , V_517 ) ;
break;
case V_111 :
case V_112 :
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_118 = V_2 -> V_67 [ V_48 ] ;
if ( V_118 -> V_145 )
continue;
V_49 = V_118 -> V_147 ;
V_517 = F_37 ( V_14 , F_42 ( V_49 ) ) ;
V_517 |= V_520 ;
F_71 ( V_14 , F_42 ( V_49 ) , V_517 ) ;
}
break;
default:
break;
}
}
static void F_280 ( struct V_1 * V_2 )
{
T_2 V_240 ;
F_276 ( V_2 -> V_55 , F_157 ( V_242 ) , 0 ) ;
F_264 (vid, adapter->active_vlans, VLAN_N_VID)
F_276 ( V_2 -> V_55 , F_157 ( V_242 ) , V_240 ) ;
}
static int F_281 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! F_57 ( V_55 ) )
return 0 ;
if ( V_14 -> V_108 . V_331 . V_521 )
V_14 -> V_108 . V_331 . V_521 ( V_14 , V_55 ) ;
else
return - V_522 ;
#ifdef F_282
F_283 ( V_2 ) ;
#endif
return F_284 ( V_55 ) ;
}
void F_285 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_523 ; V_48 ++ ) {
if ( V_2 -> V_524 [ V_48 ] . V_34 & V_525 )
V_14 -> V_108 . V_331 . V_526 ( V_14 , V_48 , V_2 -> V_524 [ V_48 ] . V_527 ,
V_2 -> V_524 [ V_48 ] . V_104 ,
V_528 ) ;
else
V_14 -> V_108 . V_331 . V_529 ( V_14 , V_48 ) ;
V_2 -> V_524 [ V_48 ] . V_34 &= ~ ( V_530 ) ;
}
}
static void F_286 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_523 ; V_48 ++ ) {
if ( V_2 -> V_524 [ V_48 ] . V_34 & V_530 ) {
if ( V_2 -> V_524 [ V_48 ] . V_34 &
V_525 )
V_14 -> V_108 . V_331 . V_526 ( V_14 , V_48 ,
V_2 -> V_524 [ V_48 ] . V_527 ,
V_2 -> V_524 [ V_48 ] . V_104 ,
V_528 ) ;
else
V_14 -> V_108 . V_331 . V_529 ( V_14 , V_48 ) ;
V_2 -> V_524 [ V_48 ] . V_34 &=
~ ( V_530 ) ;
}
}
}
static void F_287 ( struct V_1 * V_2 )
{
int V_48 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_523 ; V_48 ++ ) {
V_2 -> V_524 [ V_48 ] . V_34 |= V_530 ;
V_2 -> V_524 [ V_48 ] . V_34 &= ~ V_525 ;
memset ( V_2 -> V_524 [ V_48 ] . V_527 , 0 , V_531 ) ;
V_2 -> V_524 [ V_48 ] . V_104 = 0 ;
}
F_286 ( V_2 ) ;
}
static int F_288 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 , V_88 = 0 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_523 ; V_48 ++ ) {
if ( V_2 -> V_524 [ V_48 ] . V_34 == 0 )
V_88 ++ ;
}
return V_88 ;
}
static void F_289 ( struct V_1 * V_2 ,
T_4 * V_527 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
memcpy ( & V_2 -> V_524 [ 0 ] . V_527 , V_527 , V_531 ) ;
V_2 -> V_524 [ 0 ] . V_104 = F_266 ( 0 ) ;
V_2 -> V_524 [ 0 ] . V_34 = ( V_532 |
V_525 ) ;
V_14 -> V_108 . V_331 . V_526 ( V_14 , 0 , V_2 -> V_524 [ 0 ] . V_527 ,
V_2 -> V_524 [ 0 ] . V_104 ,
V_528 ) ;
}
int F_290 ( struct V_1 * V_2 , T_4 * V_527 , T_2 V_104 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
if ( F_291 ( V_527 ) )
return - V_533 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_523 ; V_48 ++ ) {
if ( V_2 -> V_524 [ V_48 ] . V_34 & V_525 )
continue;
V_2 -> V_524 [ V_48 ] . V_34 |= ( V_530 |
V_525 ) ;
F_292 ( V_2 -> V_524 [ V_48 ] . V_527 , V_527 ) ;
V_2 -> V_524 [ V_48 ] . V_104 = V_104 ;
F_286 ( V_2 ) ;
return V_48 ;
}
return - V_522 ;
}
int F_293 ( struct V_1 * V_2 , T_4 * V_527 , T_2 V_104 )
{
int V_48 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_291 ( V_527 ) )
return - V_533 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_523 ; V_48 ++ ) {
if ( F_294 ( V_527 , V_2 -> V_524 [ V_48 ] . V_527 ) &&
V_2 -> V_524 [ V_48 ] . V_104 == V_104 ) {
V_2 -> V_524 [ V_48 ] . V_34 |= V_530 ;
V_2 -> V_524 [ V_48 ] . V_34 &= ~ V_525 ;
memset ( V_2 -> V_524 [ V_48 ] . V_527 , 0 , V_531 ) ;
V_2 -> V_524 [ V_48 ] . V_104 = 0 ;
F_286 ( V_2 ) ;
return 0 ;
}
}
return - V_522 ;
}
static int F_295 ( struct V_54 * V_55 , int V_534 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_88 = 0 ;
if ( F_296 ( V_55 ) > F_288 ( V_2 ) )
return - V_522 ;
if ( ! F_297 ( V_55 ) ) {
struct V_535 * V_536 ;
F_298 (ha, netdev) {
F_293 ( V_2 , V_536 -> V_527 , V_534 ) ;
F_290 ( V_2 , V_536 -> V_527 , V_534 ) ;
V_88 ++ ;
}
}
return V_88 ;
}
void F_299 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_537 , V_538 = V_539 | V_540 ;
T_1 V_517 ;
int V_88 ;
V_537 = F_37 ( V_14 , V_541 ) ;
V_517 = F_37 ( V_14 , V_518 ) ;
V_537 &= ~ V_542 ;
V_537 |= V_543 ;
V_537 |= V_544 ;
V_537 |= V_545 ;
V_537 &= ~ ( V_546 | V_547 ) ;
V_517 &= ~ ( V_548 | V_549 ) ;
if ( V_55 -> V_137 & V_550 ) {
V_14 -> V_551 . V_552 = true ;
V_537 |= ( V_546 | V_547 ) ;
V_538 |= V_553 ;
if ( V_2 -> V_137 & ( V_554 |
V_402 ) )
V_517 |= ( V_548 | V_549 ) ;
} else {
if ( V_55 -> V_137 & V_555 ) {
V_537 |= V_547 ;
V_538 |= V_553 ;
}
V_517 |= V_548 ;
V_14 -> V_551 . V_552 = false ;
}
V_88 = F_295 ( V_55 , F_266 ( 0 ) ) ;
if ( V_88 < 0 ) {
V_537 |= V_546 ;
V_538 |= V_556 ;
}
V_88 = F_281 ( V_55 ) ;
if ( V_88 < 0 ) {
V_537 |= V_547 ;
V_538 |= V_553 ;
} else if ( V_88 ) {
V_538 |= V_557 ;
}
if ( V_14 -> V_108 . type != V_109 ) {
V_538 |= F_37 ( V_14 , F_300 ( F_266 ( 0 ) ) ) &
~ ( V_553 | V_557 |
V_556 ) ;
F_71 ( V_14 , F_300 ( F_266 ( 0 ) ) , V_538 ) ;
}
if ( V_2 -> V_55 -> V_194 & V_264 ) {
V_537 |= ( V_542 |
V_543 |
V_545 ) ;
V_537 &= ~ ( V_544 ) ;
}
F_71 ( V_14 , V_518 , V_517 ) ;
F_71 ( V_14 , V_541 , V_537 ) ;
if ( V_55 -> V_194 & V_238 )
F_279 ( V_2 ) ;
else
F_278 ( V_2 ) ;
}
static void F_301 ( struct V_1 * V_2 )
{
int V_558 ;
for ( V_558 = 0 ; V_558 < V_2 -> V_187 ; V_558 ++ ) {
F_302 ( V_2 -> V_156 [ V_558 ] ) ;
F_303 ( & V_2 -> V_156 [ V_558 ] -> V_245 ) ;
}
}
static void F_304 ( struct V_1 * V_2 )
{
int V_558 ;
for ( V_558 = 0 ; V_558 < V_2 -> V_187 ; V_558 ++ ) {
F_305 ( & V_2 -> V_156 [ V_558 ] -> V_245 ) ;
while ( ! F_306 ( V_2 -> V_156 [ V_558 ] ) ) {
F_51 ( L_88 , V_558 ) ;
F_247 ( 1000 , 20000 ) ;
}
}
}
static void F_307 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_484 = V_2 -> V_55 -> V_286 + V_485 + V_486 ;
if ( ! ( V_2 -> V_137 & V_138 ) ) {
if ( V_14 -> V_108 . type == V_109 )
F_308 ( V_2 -> V_55 , 65536 ) ;
return;
}
if ( V_14 -> V_108 . type == V_109 )
F_308 ( V_2 -> V_55 , 32768 ) ;
#ifdef F_177
if ( V_2 -> V_55 -> V_194 & V_559 )
V_484 = F_207 ( V_484 , V_490 ) ;
#endif
if ( V_2 -> V_560 & V_561 ) {
F_309 ( V_14 , & V_2 -> V_134 , V_484 ,
V_562 ) ;
F_309 ( V_14 , & V_2 -> V_134 , V_484 ,
V_563 ) ;
F_310 ( V_14 , & V_2 -> V_134 ) ;
} else if ( V_2 -> V_564 && V_2 -> V_136 ) {
F_311 ( & V_2 -> V_14 ,
V_2 -> V_564 ,
V_484 ) ;
F_312 ( & V_2 -> V_14 ,
V_2 -> V_136 -> V_133 ,
V_2 -> V_564 -> V_565 ) ;
}
if ( V_14 -> V_108 . type != V_109 ) {
T_1 V_566 = 0 ;
T_2 V_429 = V_2 -> V_407 [ V_408 ] . V_409 - 1 ;
while ( V_429 ) {
V_566 ++ ;
V_429 >>= 1 ;
}
F_71 ( V_14 , V_567 , V_566 * 0x11111111 ) ;
}
}
static int F_313 ( struct V_1 * V_2 , int V_568 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_73 = V_2 -> V_55 ;
int V_364 , V_132 , V_569 , V_570 ;
T_1 V_571 , V_572 ;
V_132 = V_364 = V_73 -> V_286 + V_485 + V_486 + V_573 ;
#ifdef F_177
if ( ( V_73 -> V_194 & V_559 ) &&
( V_132 < V_490 ) &&
( V_568 == F_314 ( V_2 ) ) )
V_132 = V_490 ;
#endif
switch ( V_14 -> V_108 . type ) {
case V_112 :
V_571 = F_315 ( V_364 , V_132 ) ;
break;
default:
V_571 = F_316 ( V_364 , V_132 ) ;
break;
}
if ( V_2 -> V_137 & V_402 )
V_571 += F_317 ( V_132 ) ;
V_569 = F_318 ( V_571 ) ;
V_572 = F_37 ( V_14 , F_319 ( V_568 ) ) >> 10 ;
V_570 = V_572 - V_569 ;
if ( V_570 < 0 ) {
F_93 ( V_154 , L_89
L_90
L_91 , V_568 ) ;
V_570 = V_132 + 1 ;
}
return V_570 ;
}
static int F_320 ( struct V_1 * V_2 , int V_568 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_73 = V_2 -> V_55 ;
int V_132 ;
T_1 V_571 ;
V_132 = V_73 -> V_286 + V_485 + V_486 ;
#ifdef F_177
if ( ( V_73 -> V_194 & V_559 ) &&
( V_132 < V_490 ) &&
( V_568 == F_86 ( V_73 , V_2 -> V_574 . V_575 ) ) )
V_132 = V_490 ;
#endif
switch ( V_14 -> V_108 . type ) {
case V_112 :
V_571 = F_321 ( V_132 ) ;
break;
default:
V_571 = F_322 ( V_132 ) ;
break;
}
return F_318 ( V_571 ) ;
}
static void F_323 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_576 = F_249 ( V_2 -> V_55 ) ;
int V_48 ;
if ( ! V_576 )
V_576 = 1 ;
for ( V_48 = 0 ; V_48 < V_576 ; V_48 ++ ) {
V_14 -> V_123 . V_577 [ V_48 ] = F_313 ( V_2 , V_48 ) ;
V_14 -> V_123 . V_578 [ V_48 ] = F_320 ( V_2 , V_48 ) ;
if ( V_14 -> V_123 . V_578 [ V_48 ] > V_14 -> V_123 . V_577 [ V_48 ] )
V_14 -> V_123 . V_578 [ V_48 ] = 0 ;
}
for (; V_48 < V_579 ; V_48 ++ )
V_14 -> V_123 . V_577 [ V_48 ] = 0 ;
}
static void F_324 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_580 ;
T_4 V_132 = F_249 ( V_2 -> V_55 ) ;
if ( V_2 -> V_137 & V_358 ||
V_2 -> V_137 & V_581 )
V_580 = 32 << V_2 -> V_582 ;
else
V_580 = 0 ;
V_14 -> V_108 . V_331 . V_583 ( V_14 , V_132 , V_580 , V_584 ) ;
F_323 ( V_2 ) ;
}
static void F_325 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_585 * V_586 ;
struct V_587 * V_588 ;
F_326 ( & V_2 -> V_589 ) ;
if ( ! F_327 ( & V_2 -> V_590 ) )
F_328 ( V_14 , & V_2 -> V_591 ) ;
F_329 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_330 ( V_14 ,
& V_588 -> V_588 ,
V_588 -> V_592 ,
( V_588 -> V_593 == V_594 ) ?
V_594 :
V_2 -> V_67 [ V_588 -> V_593 ] -> V_147 ) ;
}
F_331 ( & V_2 -> V_589 ) ;
}
static void F_332 ( struct V_54 * V_73 , unsigned int V_455 ,
struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_538 ;
V_538 = F_37 ( V_14 , F_300 ( V_455 ) ) ;
V_538 |= ( V_557 | V_539 | V_540 ) ;
V_538 &= ~ V_553 ;
if ( V_73 -> V_137 & V_555 ) {
V_538 |= V_553 ;
} else {
V_538 |= V_557 ;
V_14 -> V_108 . V_331 . V_521 ( V_14 , V_73 ) ;
}
F_295 ( V_2 -> V_55 , V_455 ) ;
F_71 ( V_14 , F_300 ( V_455 ) , V_538 ) ;
}
static void F_333 ( struct V_595 * V_596 )
{
struct V_1 * V_2 = V_596 -> V_146 ;
int V_429 = V_2 -> V_597 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_455 = V_596 -> V_455 ;
T_1 V_456 = V_457 |
V_458 |
V_459 |
V_460 |
V_461 ;
if ( V_14 -> V_108 . type == V_109 )
return;
if ( V_429 > 3 )
V_456 |= 2 << 29 ;
else if ( V_429 > 1 )
V_456 |= 1 << 29 ;
F_71 ( V_14 , F_265 ( F_266 ( V_455 ) ) , V_456 ) ;
}
static void F_334 ( struct V_57 * V_67 )
{
struct V_188 * V_73 = V_67 -> V_73 ;
unsigned long V_270 ;
T_2 V_48 ;
if ( ! V_67 -> V_71 )
return;
for ( V_48 = 0 ; V_48 < V_67 -> V_88 ; V_48 ++ ) {
struct V_70 * V_269 ;
V_269 = & V_67 -> V_71 [ V_48 ] ;
if ( V_269 -> V_89 ) {
struct V_193 * V_89 = V_269 -> V_89 ;
if ( F_151 ( V_89 ) -> V_262 ) {
F_80 ( V_73 ,
F_151 ( V_89 ) -> V_81 ,
F_69 ( V_67 ) ,
V_225 ) ;
F_151 ( V_89 ) -> V_262 = false ;
}
F_335 ( V_89 ) ;
V_269 -> V_89 = NULL ;
}
if ( V_269 -> V_81 )
F_80 ( V_73 , V_269 -> V_81 ,
F_142 ( V_67 ) ,
V_225 ) ;
V_269 -> V_81 = 0 ;
if ( V_269 -> V_98 )
F_144 ( V_269 -> V_98 ,
F_140 ( V_67 ) ) ;
V_269 -> V_98 = NULL ;
}
V_270 = sizeof( struct V_70 ) * V_67 -> V_88 ;
memset ( V_67 -> V_71 , 0 , V_270 ) ;
memset ( V_67 -> V_87 , 0 , V_67 -> V_270 ) ;
V_67 -> V_219 = 0 ;
V_67 -> V_79 = 0 ;
V_67 -> V_80 = 0 ;
}
static void F_336 ( struct V_595 * V_596 ,
struct V_57 * V_67 )
{
struct V_1 * V_2 = V_596 -> V_146 ;
int V_107 = V_67 -> V_86 + V_596 -> V_598 ;
F_260 ( V_2 , V_67 ) ;
F_247 ( 10000 , 20000 ) ;
F_217 ( V_2 , ( ( T_6 ) 1 << V_107 ) ) ;
F_334 ( V_67 ) ;
V_67 -> V_145 = NULL ;
}
static int F_337 ( struct V_54 * V_599 ,
struct V_595 * V_600 )
{
struct V_1 * V_2 = V_600 -> V_146 ;
unsigned int V_601 = V_600 -> V_598 ;
unsigned int V_602 = V_600 -> V_603 ;
int V_48 ;
F_338 ( V_599 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_597 ; V_48 ++ ) {
F_336 ( V_600 , V_2 -> V_67 [ V_601 + V_48 ] ) ;
V_2 -> V_67 [ V_601 + V_48 ] -> V_55 = V_2 -> V_55 ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_597 ; V_48 ++ ) {
V_2 -> V_58 [ V_602 + V_48 ] -> V_145 = NULL ;
V_2 -> V_58 [ V_602 + V_48 ] -> V_55 = V_2 -> V_55 ;
}
return 0 ;
}
static int F_339 ( struct V_54 * V_599 ,
struct V_595 * V_600 )
{
struct V_1 * V_2 = V_600 -> V_146 ;
unsigned int V_601 , V_602 , V_350 ;
int V_48 , V_604 , V_17 = 0 ;
if ( ! F_14 ( V_600 -> V_455 , & V_2 -> V_605 ) )
return 0 ;
V_604 = V_600 -> V_455 * V_2 -> V_597 ;
F_340 ( V_599 , L_92 ,
V_600 -> V_455 , V_2 -> V_606 ,
V_604 , V_604 + V_2 -> V_597 ,
V_2 -> V_605 ) ;
V_600 -> V_55 = V_599 ;
V_600 -> V_598 = V_601 = V_604 ;
V_600 -> V_603 = V_602 = V_604 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_597 ; V_48 ++ )
F_336 ( V_600 , V_2 -> V_67 [ V_601 + V_48 ] ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_597 ; V_48 ++ ) {
V_2 -> V_67 [ V_601 + V_48 ] -> V_55 = V_599 ;
V_2 -> V_67 [ V_601 + V_48 ] -> V_145 = V_600 ;
F_262 ( V_2 , V_2 -> V_67 [ V_601 + V_48 ] ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_597 ; V_48 ++ ) {
V_2 -> V_58 [ V_602 + V_48 ] -> V_55 = V_599 ;
V_2 -> V_58 [ V_602 + V_48 ] -> V_145 = V_600 ;
}
V_350 = F_341 (unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues) ;
V_17 = F_342 ( V_599 , V_350 ) ;
if ( V_17 )
goto V_607;
V_17 = F_343 ( V_599 , V_350 ) ;
if ( V_17 )
goto V_607;
if ( F_344 ( V_599 -> V_608 ) )
F_290 ( V_2 , V_599 -> V_608 , V_600 -> V_455 ) ;
F_333 ( V_600 ) ;
F_332 ( V_599 , V_600 -> V_455 , V_2 ) ;
return V_17 ;
V_607:
F_337 ( V_599 , V_600 ) ;
return V_17 ;
}
static void F_345 ( struct V_1 * V_2 )
{
struct V_54 * V_95 ;
struct V_609 * V_610 ;
int V_17 ;
F_346 (adapter->netdev, upper, iter) {
if ( F_347 ( V_95 ) ) {
struct V_611 * V_612 = F_89 ( V_95 ) ;
struct V_595 * V_596 = V_612 -> V_613 ;
if ( V_612 -> V_613 ) {
V_17 = F_339 ( V_95 , V_596 ) ;
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
V_14 -> V_108 . V_331 . V_614 ( V_14 ) ;
break;
default:
break;
}
if ( V_2 -> V_137 & V_358 ) {
F_350 ( & V_2 -> V_14 ,
V_2 -> V_582 ) ;
} else if ( V_2 -> V_137 & V_581 ) {
F_351 ( & V_2 -> V_14 ,
V_2 -> V_582 ) ;
F_325 ( V_2 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
V_14 -> V_108 . V_331 . V_615 ( V_14 ) ;
break;
default:
break;
}
#ifdef F_177
F_352 ( V_2 ) ;
#endif
F_250 ( V_2 ) ;
F_275 ( V_2 ) ;
F_345 ( V_2 ) ;
}
static inline bool F_353 ( struct V_15 * V_14 )
{
switch ( V_14 -> V_334 . type ) {
case V_616 :
case V_617 :
case V_618 :
case V_619 :
case V_620 :
case V_621 :
case V_622 :
case V_623 :
case V_624 :
case V_625 :
case V_626 :
case V_627 :
case V_628 :
return true ;
case V_629 :
if ( V_14 -> V_108 . type == V_109 )
return true ;
default:
return false ;
}
}
static void F_354 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_108 . type == V_109 )
V_2 -> V_152 |= V_630 ;
V_2 -> V_152 |= V_342 ;
}
static int F_355 ( struct V_15 * V_14 )
{
T_1 V_20 ;
bool V_631 , V_333 = false ;
T_1 V_632 = V_633 ;
if ( V_14 -> V_108 . V_331 . V_332 )
V_632 = V_14 -> V_108 . V_331 . V_332 ( V_14 , & V_20 , & V_333 , false ) ;
if ( V_632 )
return V_632 ;
V_20 = V_14 -> V_334 . V_634 ;
if ( ( ! V_20 ) && ( V_14 -> V_108 . V_331 . V_635 ) )
V_632 = V_14 -> V_108 . V_331 . V_635 ( V_14 , & V_20 ,
& V_631 ) ;
if ( V_632 )
return V_632 ;
if ( V_14 -> V_108 . V_331 . V_636 )
V_632 = V_14 -> V_108 . V_331 . V_636 ( V_14 , V_20 , V_333 ) ;
return V_632 ;
}
static void F_356 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_637 = 0 ;
if ( V_2 -> V_137 & V_382 ) {
V_637 = V_638 | V_639 |
V_640 ;
V_637 |= V_641 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
F_71 ( V_14 , V_642 , V_643 ) ;
break;
case V_111 :
case V_112 :
default:
F_71 ( V_14 , F_357 ( 0 ) , 0xFFFFFFFF ) ;
F_71 ( V_14 , F_357 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_71 ( V_14 , V_642 , V_643 ) ;
}
if ( V_2 -> V_137 & V_402 ) {
V_637 &= ~ V_644 ;
switch ( V_2 -> V_407 [ V_474 ] . V_115 ) {
case V_475 :
V_637 |= V_645 ;
break;
case V_477 :
V_637 |= V_646 ;
break;
default:
V_637 |= V_647 ;
break;
}
}
if ( V_2 -> V_152 & V_326 ) {
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_637 |= V_648 ;
break;
case V_112 :
V_637 |= V_353 ;
break;
default:
break;
}
}
if ( V_2 -> V_137 & V_337 )
V_637 |= V_649 ;
if ( V_14 -> V_108 . type == V_111 ) {
V_637 |= V_649 ;
V_637 |= V_650 ;
}
F_71 ( V_14 , V_651 , V_637 ) ;
}
static void F_358 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 ;
T_1 V_100 ;
F_72 ( V_2 ) ;
F_356 ( V_2 ) ;
if ( V_2 -> V_137 & V_382 )
F_202 ( V_2 ) ;
else
F_242 ( V_2 ) ;
if ( V_14 -> V_108 . V_331 . V_652 )
V_14 -> V_108 . V_331 . V_652 ( V_14 ) ;
F_33 () ;
F_34 ( V_33 , & V_2 -> V_34 ) ;
F_301 ( V_2 ) ;
if ( F_353 ( V_14 ) ) {
F_354 ( V_2 ) ;
} else {
V_17 = F_355 ( V_14 ) ;
if ( V_17 )
F_103 ( V_170 , L_93 , V_17 ) ;
}
F_37 ( V_14 , V_339 ) ;
F_219 ( V_2 , true , true ) ;
if ( V_2 -> V_137 & V_337 ) {
T_1 V_653 = F_37 ( V_14 , V_654 ) ;
if ( V_653 & V_655 )
F_209 ( V_154 , L_73 ) ;
}
V_2 -> V_137 |= V_345 ;
V_2 -> V_346 = V_169 ;
F_359 ( & V_2 -> V_656 , V_169 ) ;
V_100 = F_37 ( V_14 , V_101 ) ;
V_100 |= V_657 ;
F_71 ( V_14 , V_101 , V_100 ) ;
}
void F_360 ( struct V_1 * V_2 )
{
F_361 ( F_362 () ) ;
V_2 -> V_55 -> V_74 = V_169 ;
while ( F_15 ( V_658 , & V_2 -> V_34 ) )
F_247 ( 1000 , 2000 ) ;
F_363 ( V_2 ) ;
if ( V_2 -> V_137 & V_402 )
F_364 ( 2000 ) ;
F_365 ( V_2 ) ;
F_34 ( V_658 , & V_2 -> V_34 ) ;
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
T_4 V_659 [ V_531 ] ;
if ( F_22 ( V_14 -> V_39 ) )
return;
while ( F_15 ( V_660 , & V_2 -> V_34 ) )
F_247 ( 1000 , 2000 ) ;
V_2 -> V_152 &= ~ ( V_630 |
V_342 ) ;
V_2 -> V_137 &= ~ V_343 ;
V_17 = V_14 -> V_108 . V_331 . V_661 ( V_14 ) ;
switch ( V_17 ) {
case 0 :
case V_662 :
case V_663 :
break;
case V_664 :
F_18 ( L_94 ) ;
break;
case V_665 :
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
F_34 ( V_660 , & V_2 -> V_34 ) ;
memcpy ( V_659 , & V_2 -> V_524 [ 0 ] . V_527 , V_55 -> V_666 ) ;
F_287 ( V_2 ) ;
F_289 ( V_2 , V_659 ) ;
if ( V_14 -> V_108 . V_667 )
V_14 -> V_108 . V_331 . V_668 ( V_14 , F_266 ( 0 ) ) ;
if ( F_14 ( V_669 , & V_2 -> V_34 ) )
F_367 ( V_2 ) ;
}
static void F_368 ( struct V_57 * V_58 )
{
struct V_59 * V_78 ;
unsigned long V_270 ;
T_2 V_48 ;
if ( ! V_58 -> V_78 )
return;
for ( V_48 = 0 ; V_48 < V_58 -> V_88 ; V_48 ++ ) {
V_78 = & V_58 -> V_78 [ V_48 ] ;
F_77 ( V_58 , V_78 ) ;
}
F_369 ( F_107 ( V_58 ) ) ;
V_270 = sizeof( struct V_59 ) * V_58 -> V_88 ;
memset ( V_58 -> V_78 , 0 , V_270 ) ;
memset ( V_58 -> V_87 , 0 , V_58 -> V_270 ) ;
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
struct V_585 * V_586 ;
struct V_587 * V_588 ;
F_326 ( & V_2 -> V_589 ) ;
F_329 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_373 ( & V_588 -> V_670 ) ;
F_236 ( V_588 ) ;
}
V_2 -> V_671 = 0 ;
F_331 ( & V_2 -> V_589 ) ;
}
void F_363 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_95 ;
struct V_609 * V_610 ;
T_1 V_180 ;
int V_48 ;
if ( F_15 ( V_33 , & V_2 -> V_34 ) )
return;
V_180 = F_37 ( V_14 , V_508 ) ;
F_71 ( V_14 , V_508 , V_180 & ~ V_509 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
F_260 ( V_2 , V_2 -> V_67 [ V_48 ] ) ;
F_247 ( 10000 , 20000 ) ;
F_338 ( V_55 ) ;
F_374 ( V_55 ) ;
F_375 ( V_55 ) ;
F_346 (adapter->netdev, upper, iter) {
if ( F_347 ( V_95 ) ) {
struct V_611 * V_241 = F_89 ( V_95 ) ;
if ( V_241 -> V_613 ) {
F_338 ( V_95 ) ;
F_374 ( V_95 ) ;
F_375 ( V_95 ) ;
}
}
}
F_240 ( V_2 ) ;
F_304 ( V_2 ) ;
V_2 -> V_152 &= ~ ( V_359 |
V_153 ) ;
V_2 -> V_137 &= ~ V_345 ;
F_376 ( & V_2 -> V_656 ) ;
if ( V_2 -> V_298 ) {
F_71 ( & V_2 -> V_14 , V_300 , 0 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_298 ; V_48 ++ )
V_2 -> V_482 [ V_48 ] . V_672 = false ;
F_377 ( V_2 ) ;
F_378 ( V_2 ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
T_4 V_147 = V_2 -> V_58 [ V_48 ] -> V_147 ;
F_71 ( V_14 , F_50 ( V_147 ) , V_673 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
F_71 ( V_14 , V_418 ,
( F_37 ( V_14 , V_418 ) &
~ V_419 ) ) ;
break;
default:
break;
}
if ( ! F_379 ( V_2 -> V_9 ) )
F_366 ( V_2 ) ;
if ( V_14 -> V_108 . V_331 . V_674 )
V_14 -> V_108 . V_331 . V_674 ( V_14 ) ;
F_371 ( V_2 ) ;
F_370 ( V_2 ) ;
#ifdef F_227
F_123 ( V_2 ) ;
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
unsigned int V_198 , V_675 ;
T_1 V_676 ;
#ifdef F_349
int V_49 ;
struct V_677 * V_132 ;
#endif
V_14 -> V_678 = V_9 -> V_679 ;
V_14 -> V_21 = V_9 -> V_188 ;
V_14 -> V_680 = V_9 -> V_681 ;
V_14 -> V_682 = V_9 -> V_683 ;
V_14 -> V_684 = V_9 -> V_685 ;
V_198 = F_341 ( int , V_686 , F_382 () ) ;
V_2 -> V_407 [ V_408 ] . V_687 = V_198 ;
V_2 -> V_152 |= V_688 ;
V_2 -> V_152 |= V_497 ;
V_2 -> V_689 = V_690 ;
V_2 -> V_392 = 20 ;
V_675 = F_341 ( int , V_691 , F_382 () ) ;
V_2 -> V_407 [ V_692 ] . V_687 = V_675 ;
V_2 -> V_582 = V_693 ;
#ifdef F_227
V_2 -> V_137 |= V_190 ;
#endif
#ifdef F_177
V_2 -> V_137 |= V_694 ;
V_2 -> V_137 &= ~ V_489 ;
#ifdef F_349
V_2 -> V_574 . V_575 = V_695 ;
#endif
#endif
V_2 -> V_524 = F_383 ( sizeof( struct V_696 ) *
V_14 -> V_108 . V_523 ,
V_221 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_2 -> V_152 &= ~ V_688 ;
V_2 -> V_152 &= ~ V_497 ;
if ( V_14 -> V_21 == V_697 )
V_2 -> V_137 |= V_337 ;
V_2 -> V_689 = V_698 ;
V_2 -> V_407 [ V_692 ] . V_687 = 0 ;
V_2 -> V_392 = 0 ;
V_2 -> V_582 = 0 ;
#ifdef F_177
V_2 -> V_137 &= ~ V_694 ;
V_2 -> V_137 &= ~ V_489 ;
#ifdef F_349
V_2 -> V_574 . V_575 = 0 ;
#endif
#endif
break;
case V_111 :
if ( V_14 -> V_21 == V_328 )
V_2 -> V_152 |= V_326 ;
break;
case V_112 :
V_676 = F_37 ( V_14 , V_699 ) ;
if ( V_676 & V_700 )
V_2 -> V_152 |= V_326 ;
break;
default:
break;
}
#ifdef F_177
F_384 ( & V_2 -> V_574 . V_701 ) ;
#endif
F_384 ( & V_2 -> V_589 ) ;
#ifdef F_349
switch ( V_14 -> V_108 . type ) {
case V_112 :
V_2 -> V_134 . V_702 . V_703 = V_704 ;
V_2 -> V_134 . V_702 . V_705 = V_704 ;
break;
default:
V_2 -> V_134 . V_702 . V_703 = V_579 ;
V_2 -> V_134 . V_702 . V_705 = V_579 ;
break;
}
for ( V_49 = 0 ; V_49 < V_579 ; V_49 ++ ) {
V_132 = & V_2 -> V_134 . V_706 [ V_49 ] ;
V_132 -> V_707 [ V_562 ] . V_708 = 0 ;
V_132 -> V_707 [ V_562 ] . V_709 = 12 + ( V_49 & 1 ) ;
V_132 -> V_707 [ V_563 ] . V_708 = 0 ;
V_132 -> V_707 [ V_563 ] . V_709 = 12 + ( V_49 & 1 ) ;
V_132 -> V_710 = V_711 ;
}
V_132 = & V_2 -> V_134 . V_706 [ 0 ] ;
V_132 -> V_707 [ V_562 ] . V_712 = 0xFF ;
V_132 -> V_707 [ V_563 ] . V_712 = 0xFF ;
V_2 -> V_134 . V_713 [ V_562 ] [ 0 ] = 100 ;
V_2 -> V_134 . V_713 [ V_563 ] [ 0 ] = 100 ;
V_2 -> V_134 . V_135 = false ;
V_2 -> V_714 = 0x00 ;
V_2 -> V_560 = V_715 | V_561 ;
memcpy ( & V_2 -> V_716 , & V_2 -> V_134 ,
sizeof( V_2 -> V_716 ) ) ;
#endif
V_14 -> V_123 . V_717 = V_125 ;
V_14 -> V_123 . V_124 = V_125 ;
F_323 ( V_2 ) ;
V_14 -> V_123 . V_718 = V_719 ;
V_14 -> V_123 . V_720 = true ;
V_14 -> V_123 . V_721 = F_385 ( V_14 ) ;
#ifdef F_282
if ( V_722 > 0 )
F_11 ( L_102 ) ;
if ( V_14 -> V_108 . type != V_109 ) {
if ( V_722 > V_723 ) {
V_2 -> V_298 = 0 ;
F_11 ( L_103 ) ;
} else {
V_2 -> V_298 = V_722 ;
}
}
#endif
V_2 -> V_373 = 1 ;
V_2 -> V_724 = 1 ;
V_2 -> V_725 = V_726 ;
V_2 -> V_727 = V_728 ;
V_2 -> V_729 = V_730 ;
if ( F_386 ( V_14 ) ) {
F_18 ( L_104 ) ;
return - V_731 ;
}
F_245 ( 0 , & V_2 -> V_605 ) ;
F_245 ( V_33 , & V_2 -> V_34 ) ;
return 0 ;
}
int F_387 ( struct V_57 * V_58 )
{
struct V_188 * V_73 = V_58 -> V_73 ;
int V_732 = F_388 ( V_73 ) ;
int V_733 = - 1 ;
int V_270 ;
V_270 = sizeof( struct V_59 ) * V_58 -> V_88 ;
if ( V_58 -> V_156 )
V_733 = V_58 -> V_156 -> V_734 ;
V_58 -> V_78 = F_389 ( V_270 , V_733 ) ;
if ( ! V_58 -> V_78 )
V_58 -> V_78 = F_390 ( V_270 ) ;
if ( ! V_58 -> V_78 )
goto V_17;
F_391 ( & V_58 -> V_167 ) ;
V_58 -> V_270 = V_58 -> V_88 * sizeof( union V_61 ) ;
V_58 -> V_270 = F_171 ( V_58 -> V_270 , 4096 ) ;
F_392 ( V_73 , V_733 ) ;
V_58 -> V_87 = F_393 ( V_73 ,
V_58 -> V_270 ,
& V_58 -> V_81 ,
V_735 ) ;
F_392 ( V_73 , V_732 ) ;
if ( ! V_58 -> V_87 )
V_58 -> V_87 = F_393 ( V_73 , V_58 -> V_270 ,
& V_58 -> V_81 , V_735 ) ;
if ( ! V_58 -> V_87 )
goto V_17;
V_58 -> V_80 = 0 ;
V_58 -> V_79 = 0 ;
return 0 ;
V_17:
F_394 ( V_58 -> V_78 ) ;
V_58 -> V_78 = NULL ;
F_395 ( V_73 , L_105 ) ;
return - V_522 ;
}
static int F_396 ( struct V_1 * V_2 )
{
int V_48 , V_17 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
V_17 = F_387 ( V_2 -> V_58 [ V_48 ] ) ;
if ( ! V_17 )
continue;
F_103 ( V_170 , L_106 , V_48 ) ;
goto V_736;
}
return 0 ;
V_736:
while ( V_48 -- )
F_397 ( V_2 -> V_58 [ V_48 ] ) ;
return V_17 ;
}
int F_398 ( struct V_57 * V_67 )
{
struct V_188 * V_73 = V_67 -> V_73 ;
int V_732 = F_388 ( V_73 ) ;
int V_733 = - 1 ;
int V_270 ;
V_270 = sizeof( struct V_70 ) * V_67 -> V_88 ;
if ( V_67 -> V_156 )
V_733 = V_67 -> V_156 -> V_734 ;
V_67 -> V_71 = F_389 ( V_270 , V_733 ) ;
if ( ! V_67 -> V_71 )
V_67 -> V_71 = F_390 ( V_270 ) ;
if ( ! V_67 -> V_71 )
goto V_17;
F_391 ( & V_67 -> V_167 ) ;
V_67 -> V_270 = V_67 -> V_88 * sizeof( union V_68 ) ;
V_67 -> V_270 = F_171 ( V_67 -> V_270 , 4096 ) ;
F_392 ( V_73 , V_733 ) ;
V_67 -> V_87 = F_393 ( V_73 ,
V_67 -> V_270 ,
& V_67 -> V_81 ,
V_735 ) ;
F_392 ( V_73 , V_732 ) ;
if ( ! V_67 -> V_87 )
V_67 -> V_87 = F_393 ( V_73 , V_67 -> V_270 ,
& V_67 -> V_81 , V_735 ) ;
if ( ! V_67 -> V_87 )
goto V_17;
V_67 -> V_79 = 0 ;
V_67 -> V_80 = 0 ;
return 0 ;
V_17:
F_394 ( V_67 -> V_71 ) ;
V_67 -> V_71 = NULL ;
F_395 ( V_73 , L_107 ) ;
return - V_522 ;
}
static int F_399 ( struct V_1 * V_2 )
{
int V_48 , V_17 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_17 = F_398 ( V_2 -> V_67 [ V_48 ] ) ;
if ( ! V_17 )
continue;
F_103 ( V_170 , L_108 , V_48 ) ;
goto V_737;
}
#ifdef F_177
V_17 = F_400 ( V_2 ) ;
if ( ! V_17 )
#endif
return 0 ;
V_737:
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
F_402 ( V_58 -> V_73 , V_58 -> V_270 ,
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
F_402 ( V_67 -> V_73 , V_67 -> V_270 ,
V_67 -> V_87 , V_67 -> V_81 ) ;
V_67 -> V_87 = NULL ;
}
static void F_404 ( struct V_1 * V_2 )
{
int V_48 ;
#ifdef F_177
F_405 ( V_2 ) ;
#endif
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
if ( V_2 -> V_67 [ V_48 ] -> V_87 )
F_401 ( V_2 -> V_67 [ V_48 ] ) ;
}
static int F_406 ( struct V_54 * V_55 , int V_738 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_484 = V_738 + V_485 + V_486 ;
if ( ( V_738 < 68 ) || ( V_484 > V_739 ) )
return - V_533 ;
if ( ( V_2 -> V_137 & V_402 ) &&
( V_2 -> V_14 . V_108 . type == V_111 ) &&
( V_484 > ( V_491 + V_486 ) ) )
F_93 ( V_170 , L_109 ) ;
F_105 ( V_170 , L_110 , V_55 -> V_286 , V_738 ) ;
V_55 -> V_286 = V_738 ;
if ( F_57 ( V_55 ) )
F_360 ( V_2 ) ;
return 0 ;
}
static int F_407 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_17 , V_350 ;
if ( F_14 ( V_740 , & V_2 -> V_34 ) )
return - V_741 ;
F_374 ( V_55 ) ;
V_17 = F_396 ( V_2 ) ;
if ( V_17 )
goto V_736;
V_17 = F_399 ( V_2 ) ;
if ( V_17 )
goto V_737;
F_348 ( V_2 ) ;
V_17 = F_238 ( V_2 ) ;
if ( V_17 )
goto V_742;
if ( V_2 -> V_606 > 1 )
V_350 = V_2 -> V_597 ;
else
V_350 = V_2 -> V_77 ;
V_17 = F_342 ( V_55 , V_350 ) ;
if ( V_17 )
goto V_743;
if ( V_2 -> V_606 > 1 &&
V_2 -> V_93 > V_744 )
V_350 = V_744 ;
else
V_350 = V_2 -> V_93 ;
V_17 = F_343 ( V_55 , V_350 ) ;
if ( V_17 )
goto V_743;
F_408 ( V_2 ) ;
F_358 ( V_2 ) ;
return 0 ;
V_743:
F_239 ( V_2 ) ;
V_742:
F_404 ( V_2 ) ;
V_737:
F_403 ( V_2 ) ;
V_736:
F_366 ( V_2 ) ;
return V_17 ;
}
static void F_409 ( struct V_1 * V_2 )
{
F_410 ( V_2 ) ;
F_363 ( V_2 ) ;
F_239 ( V_2 ) ;
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
V_2 -> V_14 . V_39 = V_2 -> V_391 ;
F_415 ( V_9 , V_745 ) ;
F_416 ( V_9 ) ;
F_417 ( V_9 ) ;
V_17 = F_418 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_111 ) ;
return V_17 ;
}
F_33 () ;
F_34 ( V_746 , & V_2 -> V_34 ) ;
F_419 ( V_9 ) ;
F_420 ( V_9 , false ) ;
F_366 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_747 , ~ 0 ) ;
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
static int F_425 ( struct V_5 * V_9 , bool * V_748 )
{
struct V_1 * V_2 = F_414 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_749 , V_537 ;
T_1 V_750 = V_2 -> V_751 ;
#ifdef F_426
int V_752 = 0 ;
#endif
F_427 ( V_55 ) ;
F_421 () ;
if ( F_57 ( V_55 ) )
F_409 ( V_2 ) ;
F_423 () ;
F_428 ( V_2 ) ;
#ifdef F_426
V_752 = F_417 ( V_9 ) ;
if ( V_752 )
return V_752 ;
#endif
if ( V_14 -> V_108 . V_331 . V_753 )
V_14 -> V_108 . V_331 . V_753 ( V_14 ) ;
if ( V_750 ) {
F_299 ( V_55 ) ;
if ( V_14 -> V_108 . V_331 . V_652 )
V_14 -> V_108 . V_331 . V_652 ( V_14 ) ;
if ( V_750 & V_754 ) {
V_537 = F_37 ( V_14 , V_541 ) ;
V_537 |= V_547 ;
F_71 ( V_14 , V_541 , V_537 ) ;
}
V_749 = F_37 ( V_14 , V_755 ) ;
V_749 |= V_756 ;
F_71 ( V_14 , V_755 , V_749 ) ;
F_71 ( V_14 , V_757 , V_750 ) ;
} else {
F_71 ( V_14 , V_758 , 0 ) ;
F_71 ( V_14 , V_757 , 0 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_109 :
F_420 ( V_9 , false ) ;
break;
case V_111 :
case V_112 :
F_420 ( V_9 , ! ! V_750 ) ;
break;
default:
break;
}
* V_748 = ! ! V_750 ;
F_70 ( V_2 ) ;
if ( ! F_15 ( V_746 , & V_2 -> V_34 ) )
F_429 ( V_9 ) ;
return 0 ;
}
static int F_430 ( struct V_5 * V_9 , T_13 V_34 )
{
int V_752 ;
bool V_759 ;
V_752 = F_425 ( V_9 , & V_759 ) ;
if ( V_752 )
return V_752 ;
if ( V_759 ) {
F_431 ( V_9 ) ;
} else {
F_420 ( V_9 , false ) ;
F_415 ( V_9 , V_760 ) ;
}
return 0 ;
}
static void F_432 ( struct V_5 * V_9 )
{
bool V_759 ;
F_425 ( V_9 , & V_759 ) ;
if ( V_761 == V_762 ) {
F_420 ( V_9 , V_759 ) ;
F_415 ( V_9 , V_760 ) ;
}
}
void F_433 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_120 * V_121 = & V_2 -> V_122 ;
T_6 V_763 = 0 ;
T_1 V_48 , V_764 = 0 , V_765 , V_766 , V_767 , V_768 , V_769 ;
T_6 V_254 = 0 , V_172 = 0 , V_770 = 0 ;
T_6 V_224 = 0 , V_279 = 0 ;
T_6 V_168 = 0 , V_142 = 0 , V_771 = 0 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_658 , & V_2 -> V_34 ) )
return;
if ( V_2 -> V_152 & V_497 ) {
T_6 V_235 = 0 ;
T_6 V_236 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_235 += V_2 -> V_67 [ V_48 ] -> V_210 . V_235 ;
V_236 += V_2 -> V_67 [ V_48 ] -> V_210 . V_236 ;
}
V_2 -> V_772 = V_235 ;
V_2 -> V_773 = V_236 ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_67 = V_2 -> V_67 [ V_48 ] ;
V_254 += V_67 -> V_210 . V_254 ;
V_224 += V_67 -> V_210 . V_224 ;
V_279 += V_67 -> V_210 . V_279 ;
V_771 += V_67 -> V_210 . V_211 ;
V_168 += V_67 -> V_122 . V_168 ;
V_142 += V_67 -> V_122 . V_142 ;
}
V_2 -> V_254 = V_254 ;
V_2 -> V_224 = V_224 ;
V_2 -> V_279 = V_279 ;
V_2 -> V_771 = V_771 ;
V_55 -> V_122 . V_774 = V_168 ;
V_55 -> V_122 . V_775 = V_142 ;
V_168 = 0 ;
V_142 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_58 = V_2 -> V_58 [ V_48 ] ;
V_172 += V_58 -> V_150 . V_172 ;
V_770 += V_58 -> V_150 . V_770 ;
V_168 += V_58 -> V_122 . V_168 ;
V_142 += V_58 -> V_122 . V_142 ;
}
V_2 -> V_172 = V_172 ;
V_2 -> V_770 = V_770 ;
V_55 -> V_122 . V_776 = V_168 ;
V_55 -> V_122 . V_777 = V_142 ;
V_121 -> V_778 += F_37 ( V_14 , V_779 ) ;
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ ) {
V_765 = F_37 ( V_14 , F_434 ( V_48 ) ) ;
V_764 += V_765 ;
V_121 -> V_765 [ V_48 ] += V_765 ;
V_763 += V_121 -> V_765 [ V_48 ] ;
V_121 -> V_780 [ V_48 ] += F_37 ( V_14 , F_435 ( V_48 ) ) ;
V_121 -> V_781 [ V_48 ] += F_37 ( V_14 , F_436 ( V_48 ) ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_121 -> V_782 [ V_48 ] += F_37 ( V_14 , F_437 ( V_48 ) ) ;
V_121 -> V_783 [ V_48 ] += F_37 ( V_14 , F_438 ( V_48 ) ) ;
V_121 -> V_784 [ V_48 ] += F_37 ( V_14 , F_439 ( V_48 ) ) ;
V_121 -> V_785 [ V_48 ] +=
F_37 ( V_14 , F_440 ( V_48 ) ) ;
break;
case V_111 :
case V_112 :
V_121 -> V_785 [ V_48 ] +=
F_37 ( V_14 , F_441 ( V_48 ) ) ;
break;
default:
break;
}
}
for ( V_48 = 0 ; V_48 < 16 ; V_48 ++ ) {
V_121 -> V_786 [ V_48 ] += F_37 ( V_14 , F_442 ( V_48 ) ) ;
V_121 -> V_787 [ V_48 ] += F_37 ( V_14 , F_443 ( V_48 ) ) ;
if ( ( V_14 -> V_108 . type == V_111 ) ||
( V_14 -> V_108 . type == V_112 ) ) {
V_121 -> V_783 [ V_48 ] += F_37 ( V_14 , F_444 ( V_48 ) ) ;
F_37 ( V_14 , F_445 ( V_48 ) ) ;
V_121 -> V_784 [ V_48 ] += F_37 ( V_14 , F_446 ( V_48 ) ) ;
F_37 ( V_14 , F_447 ( V_48 ) ) ;
}
}
V_121 -> V_788 += F_37 ( V_14 , V_789 ) ;
V_121 -> V_788 -= V_764 ;
F_83 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_121 -> V_790 += F_37 ( V_14 , V_791 ) ;
V_121 -> V_792 += F_37 ( V_14 , V_793 ) ;
V_121 -> V_794 += F_37 ( V_14 , V_795 ) ;
V_121 -> V_796 += F_37 ( V_14 , V_797 ) ;
break;
case V_112 :
V_121 -> V_798 += F_37 ( V_14 , V_799 ) ;
V_121 -> V_800 += F_37 ( V_14 , V_801 ) ;
V_121 -> V_802 += F_37 ( V_14 , V_803 ) ;
V_121 -> V_804 += F_37 ( V_14 , V_805 ) ;
case V_111 :
for ( V_48 = 0 ; V_48 < 16 ; V_48 ++ )
V_2 -> V_806 +=
F_37 ( V_14 , F_448 ( V_48 ) ) ;
V_121 -> V_792 += F_37 ( V_14 , V_807 ) ;
F_37 ( V_14 , V_793 ) ;
V_121 -> V_794 += F_37 ( V_14 , V_808 ) ;
F_37 ( V_14 , V_795 ) ;
V_121 -> V_796 += F_37 ( V_14 , V_809 ) ;
F_37 ( V_14 , V_797 ) ;
V_121 -> V_790 += F_37 ( V_14 , V_810 ) ;
V_121 -> V_811 += F_37 ( V_14 , V_812 ) ;
V_121 -> V_813 += F_37 ( V_14 , V_814 ) ;
#ifdef F_177
V_121 -> V_815 += F_37 ( V_14 , V_816 ) ;
V_121 -> V_817 += F_37 ( V_14 , V_818 ) ;
V_121 -> V_819 += F_37 ( V_14 , V_820 ) ;
V_121 -> V_821 += F_37 ( V_14 , V_822 ) ;
V_121 -> V_823 += F_37 ( V_14 , V_824 ) ;
V_121 -> V_825 += F_37 ( V_14 , V_826 ) ;
if ( V_2 -> V_574 . V_827 ) {
struct V_828 * V_574 = & V_2 -> V_574 ;
struct V_829 * V_827 ;
unsigned int V_173 ;
T_6 V_830 = 0 , V_831 = 0 ;
F_449 (cpu) {
V_827 = F_450 ( V_574 -> V_827 , V_173 ) ;
V_830 += V_827 -> V_830 ;
V_831 += V_827 -> V_831 ;
}
V_121 -> V_832 = V_830 ;
V_121 -> V_833 = V_831 ;
}
#endif
break;
default:
break;
}
V_766 = F_37 ( V_14 , V_834 ) ;
V_121 -> V_766 += V_766 ;
V_121 -> V_835 += F_37 ( V_14 , V_836 ) ;
if ( V_14 -> V_108 . type == V_109 )
V_121 -> V_835 -= V_766 ;
V_121 -> V_837 += F_37 ( V_14 , V_838 ) ;
V_121 -> V_839 += F_37 ( V_14 , V_840 ) ;
V_121 -> V_841 += F_37 ( V_14 , V_842 ) ;
V_121 -> V_843 += F_37 ( V_14 , V_844 ) ;
V_121 -> V_845 += F_37 ( V_14 , V_846 ) ;
V_121 -> V_847 += F_37 ( V_14 , V_848 ) ;
V_121 -> V_849 += F_37 ( V_14 , V_850 ) ;
V_121 -> V_851 += F_37 ( V_14 , V_852 ) ;
V_767 = F_37 ( V_14 , V_853 ) ;
V_121 -> V_854 += V_767 ;
V_768 = F_37 ( V_14 , V_855 ) ;
V_121 -> V_856 += V_768 ;
V_121 -> V_857 += F_37 ( V_14 , V_858 ) ;
V_121 -> V_859 += F_37 ( V_14 , V_860 ) ;
V_769 = V_767 + V_768 ;
V_121 -> V_857 -= V_769 ;
V_121 -> V_859 -= V_769 ;
V_121 -> V_794 -= ( V_769 * ( V_861 + V_486 ) ) ;
V_121 -> V_862 += F_37 ( V_14 , V_863 ) ;
V_121 -> V_864 += F_37 ( V_14 , V_865 ) ;
V_121 -> V_866 += F_37 ( V_14 , V_867 ) ;
V_121 -> V_868 += F_37 ( V_14 , V_869 ) ;
V_121 -> V_870 += F_37 ( V_14 , V_871 ) ;
V_121 -> V_870 -= V_769 ;
V_121 -> V_872 += F_37 ( V_14 , V_873 ) ;
V_121 -> V_874 += F_37 ( V_14 , V_875 ) ;
V_121 -> V_876 += F_37 ( V_14 , V_877 ) ;
V_121 -> V_878 += F_37 ( V_14 , V_879 ) ;
V_121 -> V_880 += F_37 ( V_14 , V_881 ) ;
V_121 -> V_882 += F_37 ( V_14 , V_883 ) ;
V_55 -> V_122 . V_884 = V_121 -> V_835 ;
V_55 -> V_122 . V_885 = V_121 -> V_778 + V_121 -> V_851 ;
V_55 -> V_122 . V_886 = 0 ;
V_55 -> V_122 . V_887 = V_121 -> V_851 ;
V_55 -> V_122 . V_888 = V_121 -> V_778 ;
V_55 -> V_122 . V_889 = V_763 ;
}
static void F_451 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
if ( ! ( V_2 -> V_152 & V_359 ) )
return;
V_2 -> V_152 &= ~ V_359 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
if ( ! ( V_2 -> V_137 & V_358 ) )
return;
V_2 -> V_890 ++ ;
if ( F_452 ( V_14 ) == 0 ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_245 ( V_367 ,
& ( V_2 -> V_58 [ V_48 ] -> V_34 ) ) ;
F_71 ( V_14 , V_349 , V_360 ) ;
} else {
F_103 ( V_170 , L_112
L_113 ) ;
}
}
static void F_453 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_891 = 0 ;
int V_48 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_658 , & V_2 -> V_34 ) )
return;
if ( F_109 ( V_2 -> V_55 ) ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_454 ( V_2 -> V_58 [ V_48 ] ) ;
}
if ( ! ( V_2 -> V_137 & V_382 ) ) {
F_71 ( V_14 , V_117 ,
( V_892 | V_893 ) ) ;
} else {
for ( V_48 = 0 ; V_48 < V_2 -> V_187 ; V_48 ++ ) {
struct V_155 * V_894 = V_2 -> V_156 [ V_48 ] ;
if ( V_894 -> V_290 . V_118 || V_894 -> V_160 . V_118 )
V_891 |= ( ( T_6 ) 1 << V_48 ) ;
}
}
F_75 ( V_2 , V_891 ) ;
}
static void F_455 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_895 = V_2 -> V_895 ;
bool V_333 = V_2 -> V_333 ;
bool V_133 = V_2 -> V_134 . V_135 ;
if ( ! ( V_2 -> V_137 & V_345 ) )
return;
if ( V_14 -> V_108 . V_331 . V_332 ) {
V_14 -> V_108 . V_331 . V_332 ( V_14 , & V_895 , & V_333 , false ) ;
} else {
V_895 = V_896 ;
V_333 = true ;
}
if ( V_2 -> V_136 )
V_133 |= ! ! ( V_2 -> V_136 -> V_133 ) ;
if ( V_333 && ! ( ( V_2 -> V_137 & V_138 ) && V_133 ) ) {
V_14 -> V_108 . V_331 . V_897 ( V_14 ) ;
F_456 ( V_2 ) ;
}
if ( V_333 ||
F_457 ( V_169 , ( V_2 -> V_346 +
V_898 ) ) ) {
V_2 -> V_137 &= ~ V_345 ;
F_71 ( V_14 , V_349 , V_348 ) ;
F_214 ( V_14 ) ;
}
V_2 -> V_333 = V_333 ;
V_2 -> V_895 = V_895 ;
}
static void F_458 ( struct V_1 * V_2 )
{
#ifdef F_349
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_899 V_900 = {
. V_901 = V_902 ,
. V_243 = 0 ,
} ;
T_4 V_575 = 0 ;
if ( V_2 -> V_560 & V_903 )
V_575 = F_459 ( V_55 , & V_900 ) ;
V_2 -> V_904 = ( V_575 > 1 ) ? ( F_460 ( V_575 ) - 1 ) : 0 ;
#endif
}
static void F_461 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_95 ;
struct V_609 * V_610 ;
T_1 V_895 = V_2 -> V_895 ;
bool V_905 , V_906 ;
if ( F_109 ( V_55 ) )
return;
V_2 -> V_152 &= ~ V_630 ;
switch ( V_14 -> V_108 . type ) {
case V_109 : {
T_1 V_907 = F_37 ( V_14 , V_541 ) ;
T_1 V_908 = F_37 ( V_14 , V_909 ) ;
V_905 = ! ! ( V_907 & V_910 ) ;
V_906 = ! ! ( V_908 & V_911 ) ;
}
break;
case V_112 :
case V_111 : {
T_1 V_912 = F_37 ( V_14 , V_913 ) ;
T_1 V_914 = F_37 ( V_14 , V_915 ) ;
V_905 = ! ! ( V_912 & V_916 ) ;
V_906 = ! ! ( V_914 & V_917 ) ;
}
break;
default:
V_906 = false ;
V_905 = false ;
break;
}
V_2 -> V_918 = V_169 ;
if ( F_14 ( V_669 , & V_2 -> V_34 ) )
F_462 ( V_2 ) ;
F_105 ( V_154 , L_114 ,
( V_895 == V_896 ?
L_115 :
( V_895 == V_919 ?
L_116 :
( V_895 == V_920 ?
L_117 :
L_118 ) ) ) ,
( ( V_905 && V_906 ) ? L_119 :
( V_905 ? L_120 :
( V_906 ? L_121 : L_122 ) ) ) ) ;
F_463 ( V_55 ) ;
F_464 ( V_2 ) ;
F_465 ( V_2 -> V_55 ) ;
F_421 () ;
F_346 (adapter->netdev, upper, iter) {
if ( F_347 ( V_95 ) ) {
struct V_611 * V_241 = F_89 ( V_95 ) ;
if ( V_241 -> V_613 )
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
V_2 -> V_333 = false ;
V_2 -> V_895 = 0 ;
if ( ! F_109 ( V_55 ) )
return;
if ( F_353 ( V_14 ) && V_14 -> V_108 . type == V_109 )
V_2 -> V_152 |= V_630 ;
if ( F_14 ( V_669 , & V_2 -> V_34 ) )
F_462 ( V_2 ) ;
F_105 ( V_154 , L_123 ) ;
F_374 ( V_55 ) ;
F_377 ( V_2 ) ;
}
static bool F_467 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_58 = V_2 -> V_58 [ V_48 ] ;
if ( V_58 -> V_80 != V_58 -> V_79 )
return true ;
}
return false ;
}
static bool F_468 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_921 * V_922 = & V_2 -> V_407 [ V_474 ] ;
T_1 V_923 = F_469 ( 1 , ~ V_922 -> V_115 ) ;
int V_48 , V_49 ;
if ( ! V_2 -> V_298 )
return false ;
for ( V_48 = 0 ; V_48 < V_2 -> V_298 ; V_48 ++ ) {
for ( V_49 = 0 ; V_49 < V_923 ; V_49 ++ ) {
T_1 V_924 , V_925 ;
V_924 = F_37 ( V_14 , F_470 ( V_923 , V_48 , V_49 ) ) ;
V_925 = F_37 ( V_14 , F_471 ( V_923 , V_48 , V_49 ) ) ;
if ( V_924 != V_925 )
return true ;
}
}
return false ;
}
static void F_472 ( struct V_1 * V_2 )
{
if ( ! F_109 ( V_2 -> V_55 ) ) {
if ( F_467 ( V_2 ) ||
F_468 ( V_2 ) ) {
F_93 ( V_154 , L_124 ) ;
V_2 -> V_152 |= V_153 ;
}
}
}
static void F_473 ( struct V_1 * V_2 )
{
T_1 V_926 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ||
V_2 -> V_298 == 0 )
return;
V_926 = F_37 ( & V_2 -> V_14 , V_927 ) ;
if ( ! V_926 )
return;
F_93 ( V_154 , L_125 , V_926 ) ;
}
static void F_474 ( struct V_1 * V_2 )
{
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_658 , & V_2 -> V_34 ) )
return;
F_455 ( V_2 ) ;
if ( V_2 -> V_333 )
F_461 ( V_2 ) ;
else
F_466 ( V_2 ) ;
F_473 ( V_2 ) ;
F_433 ( V_2 ) ;
F_472 ( V_2 ) ;
}
static void F_475 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_3 V_17 ;
if ( ! ( V_2 -> V_152 & V_630 ) &&
! ( V_2 -> V_152 & V_342 ) )
return;
if ( F_15 ( V_660 , & V_2 -> V_34 ) )
return;
V_17 = V_14 -> V_334 . V_331 . V_928 ( V_14 ) ;
if ( V_17 == V_663 )
goto V_929;
if ( V_17 == V_662 ) {
V_2 -> V_152 |= V_342 ;
}
if ( V_17 )
goto V_929;
if ( ! ( V_2 -> V_152 & V_342 ) )
goto V_929;
V_2 -> V_152 &= ~ V_342 ;
if ( V_14 -> V_108 . type == V_109 )
V_17 = V_14 -> V_334 . V_331 . V_930 ( V_14 ) ;
else
V_17 = V_14 -> V_108 . V_331 . V_931 ( V_14 ) ;
if ( V_17 == V_663 )
goto V_929;
V_2 -> V_137 |= V_343 ;
F_105 ( V_170 , L_126 , V_14 -> V_334 . V_932 ) ;
V_929:
F_34 ( V_660 , & V_2 -> V_34 ) ;
if ( ( V_17 == V_663 ) &&
( V_2 -> V_55 -> V_933 == V_934 ) ) {
F_18 ( L_127
L_128 ) ;
F_18 ( L_129
L_130 ) ;
F_476 ( V_2 -> V_55 ) ;
}
}
static void F_477 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_20 ;
bool V_631 = false ;
if ( ! ( V_2 -> V_137 & V_343 ) )
return;
if ( F_15 ( V_660 , & V_2 -> V_34 ) )
return;
V_2 -> V_137 &= ~ V_343 ;
V_20 = V_14 -> V_334 . V_634 ;
if ( ( ! V_20 ) && ( V_14 -> V_108 . V_331 . V_635 ) ) {
V_14 -> V_108 . V_331 . V_635 ( V_14 , & V_20 , & V_631 ) ;
if ( ! V_631 ) {
if ( V_20 & V_896 )
V_20 = V_896 ;
}
}
if ( V_14 -> V_108 . V_331 . V_636 )
V_14 -> V_108 . V_331 . V_636 ( V_14 , V_20 , true ) ;
V_2 -> V_137 |= V_345 ;
V_2 -> V_346 = V_169 ;
F_34 ( V_660 , & V_2 -> V_34 ) ;
}
static void F_478 ( struct V_1 * V_2 )
{
int V_935 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_55 = V_2 -> V_55 ;
T_1 V_936 ;
T_1 V_937 , V_938 ;
V_936 = F_37 ( V_14 , V_939 ) ;
if ( V_936 )
return;
for ( V_935 = 0 ; V_935 < V_2 -> V_298 ; V_935 ++ ) {
V_937 = ( V_935 << 16 ) | 0x80000000 ;
V_937 |= V_940 ;
F_71 ( V_14 , V_941 , V_937 ) ;
V_938 = F_37 ( V_14 , V_942 ) ;
V_937 &= 0x7FFFFFFF ;
F_71 ( V_14 , V_941 , V_937 ) ;
V_938 >>= 16 ;
if ( V_938 & V_943 ) {
F_479 ( V_55 , L_131 , V_935 ) ;
V_937 = ( V_935 << 16 ) | 0x80000000 ;
V_937 |= 0xA8 ;
F_71 ( V_14 , V_941 , V_937 ) ;
V_938 = 0x00008000 ;
F_71 ( V_14 , V_942 , V_938 ) ;
V_937 &= 0x7FFFFFFF ;
F_71 ( V_14 , V_941 , V_937 ) ;
}
}
}
static void F_480 ( unsigned long V_92 )
{
struct V_1 * V_2 = (struct V_1 * ) V_92 ;
unsigned long V_944 ;
bool V_945 = true ;
if ( V_2 -> V_137 & V_345 )
V_944 = V_946 / 10 ;
else
V_944 = V_946 * 2 ;
#ifdef F_282
if ( ! V_2 -> V_298 ||
( V_2 -> V_137 & V_345 ) )
goto V_947;
F_478 ( V_2 ) ;
V_944 = V_946 / 50 ;
V_2 -> V_948 ++ ;
if ( V_2 -> V_948 >= 100 )
V_2 -> V_948 = 0 ;
else
V_945 = false ;
V_947:
#endif
F_359 ( & V_2 -> V_656 , V_944 + V_169 ) ;
if ( V_945 )
F_13 ( V_2 ) ;
}
static void F_481 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_152 & V_153 ) )
return;
V_2 -> V_152 &= ~ V_153 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_658 , & V_2 -> V_34 ) )
return;
F_54 ( V_2 ) ;
F_479 ( V_2 -> V_55 , L_132 ) ;
V_2 -> V_171 ++ ;
F_421 () ;
F_360 ( V_2 ) ;
F_423 () ;
}
static void F_482 ( struct V_949 * V_950 )
{
struct V_1 * V_2 = F_198 ( V_950 ,
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
F_481 ( V_2 ) ;
F_475 ( V_2 ) ;
F_477 ( V_2 ) ;
F_208 ( V_2 ) ;
F_474 ( V_2 ) ;
F_451 ( V_2 ) ;
F_453 ( V_2 ) ;
if ( F_14 ( V_669 , & V_2 -> V_34 ) ) {
F_483 ( V_2 ) ;
F_484 ( V_2 ) ;
}
F_31 ( V_2 ) ;
}
static int F_485 ( struct V_57 * V_58 ,
struct V_59 * V_951 ,
T_4 * V_230 )
{
struct V_193 * V_89 = V_951 -> V_89 ;
T_1 V_952 , V_953 ;
T_1 V_954 , V_955 ;
int V_17 ;
if ( V_89 -> V_216 != V_956 )
return 0 ;
if ( ! F_486 ( V_89 ) )
return 0 ;
V_17 = F_487 ( V_89 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_953 = V_957 ;
if ( V_951 -> V_243 == F_157 ( V_958 ) ) {
struct V_959 * V_960 = F_488 ( V_89 ) ;
V_960 -> V_961 = 0 ;
V_960 -> V_962 = 0 ;
F_489 ( V_89 ) -> V_962 = ~ F_490 ( V_960 -> V_963 ,
V_960 -> V_964 , 0 ,
V_965 ,
0 ) ;
V_953 |= V_966 ;
V_951 -> V_967 |= V_968 |
V_969 |
V_970 ;
} else if ( F_491 ( V_89 ) ) {
F_492 ( V_89 ) -> V_971 = 0 ;
F_489 ( V_89 ) -> V_962 =
~ F_493 ( & F_492 ( V_89 ) -> V_963 ,
& F_492 ( V_89 ) -> V_964 ,
0 , V_965 , 0 ) ;
V_951 -> V_967 |= V_968 |
V_969 ;
}
V_955 = F_494 ( V_89 ) ;
* V_230 = F_495 ( V_89 ) + V_955 ;
V_951 -> V_166 = F_149 ( V_89 ) -> V_166 ;
V_951 -> V_165 += ( V_951 -> V_166 - 1 ) * * V_230 ;
V_954 = V_955 << V_972 ;
V_954 |= F_149 ( V_89 ) -> V_231 << V_973 ;
V_952 = F_496 ( V_89 ) ;
V_952 |= F_497 ( V_89 ) << V_974 ;
V_952 |= V_951 -> V_967 & V_975 ;
F_498 ( V_58 , V_952 , 0 , V_953 ,
V_954 ) ;
return 1 ;
}
static void F_499 ( struct V_57 * V_58 ,
struct V_59 * V_951 )
{
struct V_193 * V_89 = V_951 -> V_89 ;
T_1 V_952 = 0 ;
T_1 V_954 = 0 ;
T_1 V_953 = 0 ;
if ( V_89 -> V_216 != V_956 ) {
if ( ! ( V_951 -> V_967 & V_976 ) &&
! ( V_951 -> V_967 & V_977 ) )
return;
} else {
T_4 V_978 = 0 ;
switch ( V_951 -> V_243 ) {
case F_157 ( V_958 ) :
V_952 |= F_496 ( V_89 ) ;
V_953 |= V_966 ;
V_978 = F_488 ( V_89 ) -> V_243 ;
break;
case F_157 ( V_979 ) :
V_952 |= F_496 ( V_89 ) ;
V_978 = F_492 ( V_89 ) -> V_980 ;
break;
default:
if ( F_24 ( F_500 () ) ) {
F_501 ( V_58 -> V_73 ,
L_133 ,
V_951 -> V_243 ) ;
}
break;
}
switch ( V_978 ) {
case V_965 :
V_953 |= V_957 ;
V_954 = F_494 ( V_89 ) <<
V_972 ;
break;
case V_981 :
V_953 |= V_982 ;
V_954 = sizeof( struct V_983 ) <<
V_972 ;
break;
case V_984 :
V_954 = sizeof( struct V_985 ) <<
V_972 ;
break;
default:
if ( F_24 ( F_500 () ) ) {
F_501 ( V_58 -> V_73 ,
L_134 ,
V_978 ) ;
}
break;
}
V_951 -> V_967 |= V_969 ;
}
V_952 |= F_497 ( V_89 ) << V_974 ;
V_952 |= V_951 -> V_967 & V_975 ;
F_498 ( V_58 , V_952 , 0 ,
V_953 , V_954 ) ;
}
static T_1 F_502 ( struct V_193 * V_89 , T_1 V_967 )
{
T_1 V_986 = V_987 |
V_988 |
V_989 ;
V_986 |= F_503 ( V_967 , V_976 ,
V_990 ) ;
V_986 |= F_503 ( V_967 , V_968 ,
V_991 ) ;
V_986 |= F_503 ( V_967 , V_992 ,
V_993 ) ;
V_986 ^= F_503 ( V_89 -> V_994 , 1 , V_989 ) ;
return V_986 ;
}
static void F_504 ( union V_61 * V_62 ,
T_1 V_967 , unsigned int V_995 )
{
T_1 V_996 = V_995 << V_997 ;
V_996 |= F_503 ( V_967 ,
V_969 ,
V_998 ) ;
V_996 |= F_503 ( V_967 ,
V_970 ,
V_999 ) ;
V_996 |= F_503 ( V_967 ,
V_977 ,
V_1000 ) ;
V_62 -> V_227 . V_996 = F_96 ( V_996 ) ;
}
static int F_505 ( struct V_57 * V_58 , T_2 V_270 )
{
F_104 ( V_58 -> V_55 , V_58 -> V_86 ) ;
F_111 () ;
if ( F_99 ( F_110 ( V_58 ) < V_270 ) )
return - V_741 ;
F_506 ( V_58 -> V_55 , V_58 -> V_86 ) ;
++ V_58 -> V_150 . V_172 ;
return 0 ;
}
static inline int F_507 ( struct V_57 * V_58 , T_2 V_270 )
{
if ( F_99 ( F_110 ( V_58 ) >= V_270 ) )
return 0 ;
return F_505 ( V_58 , V_270 ) ;
}
static void F_508 ( struct V_57 * V_58 ,
struct V_59 * V_951 ,
const T_4 V_230 )
{
struct V_193 * V_89 = V_951 -> V_89 ;
struct V_59 * V_60 ;
union V_61 * V_62 ;
struct V_255 * V_256 ;
T_9 V_81 ;
unsigned int V_261 , V_270 ;
T_1 V_967 = V_951 -> V_967 ;
T_1 V_986 = F_502 ( V_89 , V_967 ) ;
T_2 V_48 = V_58 -> V_80 ;
V_62 = F_61 ( V_58 , V_48 ) ;
F_504 ( V_62 , V_967 , V_89 -> V_82 - V_230 ) ;
V_270 = F_148 ( V_89 ) ;
V_261 = V_89 -> V_261 ;
#ifdef F_177
if ( V_967 & V_1001 ) {
if ( V_261 < sizeof( struct V_289 ) ) {
V_270 -= sizeof( struct V_289 ) - V_261 ;
V_261 = 0 ;
} else {
V_261 -= sizeof( struct V_289 ) ;
}
}
#endif
V_81 = F_509 ( V_58 -> V_73 , V_89 -> V_92 , V_270 , V_119 ) ;
V_60 = V_951 ;
for ( V_256 = & F_149 ( V_89 ) -> V_257 [ 0 ] ; ; V_256 ++ ) {
if ( F_143 ( V_58 -> V_73 , V_81 ) )
goto V_1002;
F_81 ( V_60 , V_82 , V_270 ) ;
F_510 ( V_60 , V_81 , V_81 ) ;
V_62 -> V_227 . V_1003 = F_146 ( V_81 ) ;
while ( F_24 ( V_270 > V_1004 ) ) {
V_62 -> V_227 . V_1005 =
F_96 ( V_986 ^ V_1004 ) ;
V_48 ++ ;
V_62 ++ ;
if ( V_48 == V_58 -> V_88 ) {
V_62 = F_61 ( V_58 , 0 ) ;
V_48 = 0 ;
}
V_62 -> V_227 . V_996 = 0 ;
V_81 += V_1004 ;
V_270 -= V_1004 ;
V_62 -> V_227 . V_1003 = F_146 ( V_81 ) ;
}
if ( F_99 ( ! V_261 ) )
break;
V_62 -> V_227 . V_1005 = F_96 ( V_986 ^ V_270 ) ;
V_48 ++ ;
V_62 ++ ;
if ( V_48 == V_58 -> V_88 ) {
V_62 = F_61 ( V_58 , 0 ) ;
V_48 = 0 ;
}
V_62 -> V_227 . V_996 = 0 ;
#ifdef F_177
V_270 = F_341 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_270 = F_511 ( V_256 ) ;
#endif
V_261 -= V_270 ;
V_81 = F_512 ( V_58 -> V_73 , V_256 , 0 , V_270 ,
V_119 ) ;
V_60 = & V_58 -> V_78 [ V_48 ] ;
}
V_986 |= V_270 | V_1006 ;
V_62 -> V_227 . V_1005 = F_96 ( V_986 ) ;
F_513 ( F_107 ( V_58 ) , V_951 -> V_165 ) ;
V_951 -> V_84 = V_169 ;
F_136 () ;
V_951 -> V_83 = V_62 ;
V_48 ++ ;
if ( V_48 == V_58 -> V_88 )
V_48 = 0 ;
V_58 -> V_80 = V_48 ;
F_507 ( V_58 , V_1007 ) ;
if ( F_514 ( F_107 ( V_58 ) ) || ! V_89 -> V_1008 ) {
F_137 ( V_58 , V_48 ) ;
}
return;
V_1002:
F_395 ( V_58 -> V_73 , L_135 ) ;
for (; ; ) {
V_60 = & V_58 -> V_78 [ V_48 ] ;
F_77 ( V_58 , V_60 ) ;
if ( V_60 == V_951 )
break;
if ( V_48 == 0 )
V_48 = V_58 -> V_88 ;
V_48 -- ;
}
V_58 -> V_80 = V_48 ;
}
static void F_515 ( struct V_57 * V_118 ,
struct V_59 * V_951 )
{
struct V_155 * V_156 = V_118 -> V_156 ;
union V_1009 V_1010 = { . V_1011 = 0 } ;
union V_1009 V_1012 = { . V_1011 = 0 } ;
union {
unsigned char * V_1013 ;
struct V_959 * V_1014 ;
struct V_1015 * V_1016 ;
} V_1017 ;
struct V_1018 * V_1019 ;
T_12 V_1020 ;
if ( ! V_156 )
return;
if ( ! V_118 -> V_392 )
return;
V_118 -> V_393 ++ ;
V_1017 . V_1013 = F_516 ( V_951 -> V_89 ) ;
if ( ( V_951 -> V_243 != F_157 ( V_979 ) ||
V_1017 . V_1016 -> V_980 != V_965 ) &&
( V_951 -> V_243 != F_157 ( V_958 ) ||
V_1017 . V_1014 -> V_243 != V_965 ) )
return;
V_1019 = F_489 ( V_951 -> V_89 ) ;
if ( ! V_1019 || V_1019 -> V_1021 )
return;
if ( ! V_1019 -> V_1022 && ( V_118 -> V_393 < V_118 -> V_392 ) )
return;
V_118 -> V_393 = 0 ;
V_1020 = F_157 ( V_951 -> V_967 >> V_1023 ) ;
V_1010 . V_1024 . V_1020 = V_1020 ;
if ( V_951 -> V_967 & ( V_1025 | V_976 ) )
V_1012 . V_1026 . V_1027 ^= V_1019 -> V_1028 ^ F_157 ( V_242 ) ;
else
V_1012 . V_1026 . V_1027 ^= V_1019 -> V_1028 ^ V_951 -> V_243 ;
V_1012 . V_1026 . V_1029 ^= V_1019 -> V_1030 ;
if ( V_951 -> V_243 == F_157 ( V_958 ) ) {
V_1010 . V_1024 . V_1031 = V_1032 ;
V_1012 . V_1033 ^= V_1017 . V_1014 -> V_963 ^ V_1017 . V_1014 -> V_964 ;
} else {
V_1010 . V_1024 . V_1031 = V_1034 ;
V_1012 . V_1033 ^= V_1017 . V_1016 -> V_963 . V_1035 [ 0 ] ^
V_1017 . V_1016 -> V_963 . V_1035 [ 1 ] ^
V_1017 . V_1016 -> V_963 . V_1035 [ 2 ] ^
V_1017 . V_1016 -> V_963 . V_1035 [ 3 ] ^
V_1017 . V_1016 -> V_964 . V_1035 [ 0 ] ^
V_1017 . V_1016 -> V_964 . V_1035 [ 1 ] ^
V_1017 . V_1016 -> V_964 . V_1035 [ 2 ] ^
V_1017 . V_1016 -> V_964 . V_1035 [ 3 ] ;
}
F_517 ( & V_156 -> V_2 -> V_14 ,
V_1010 , V_1012 , V_118 -> V_86 ) ;
}
static T_2 F_518 ( struct V_54 * V_73 , struct V_193 * V_89 ,
void * V_1036 , T_14 V_1037 )
{
struct V_595 * V_1038 = V_1036 ;
#ifdef F_177
struct V_1 * V_2 ;
struct V_921 * V_1039 ;
int V_1040 ;
#endif
if ( V_1038 )
return V_89 -> V_1041 + V_1038 -> V_603 ;
#ifdef F_177
switch ( F_519 ( V_89 ) ) {
case F_157 ( V_1042 ) :
case F_157 ( V_1043 ) :
V_2 = F_89 ( V_73 ) ;
if ( V_2 -> V_137 & V_489 )
break;
default:
return V_1037 ( V_73 , V_89 ) ;
}
V_1039 = & V_2 -> V_407 [ V_1044 ] ;
V_1040 = F_520 ( V_89 ) ? F_521 ( V_89 ) :
F_522 () ;
while ( V_1040 >= V_1039 -> V_409 )
V_1040 -= V_1039 -> V_409 ;
return V_1040 + V_1039 -> V_1045 ;
#else
return V_1037 ( V_73 , V_89 ) ;
#endif
}
T_15 F_523 ( struct V_193 * V_89 ,
struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_59 * V_951 ;
int V_1046 ;
T_1 V_967 = 0 ;
unsigned short V_1039 ;
T_2 V_88 = F_524 ( F_148 ( V_89 ) ) ;
T_12 V_243 = V_89 -> V_243 ;
T_4 V_230 = 0 ;
for ( V_1039 = 0 ; V_1039 < F_149 ( V_89 ) -> V_276 ; V_1039 ++ )
V_88 += F_524 ( F_149 ( V_89 ) -> V_257 [ V_1039 ] . V_270 ) ;
if ( F_507 ( V_58 , V_88 + 3 ) ) {
V_58 -> V_150 . V_770 ++ ;
return V_1047 ;
}
V_951 = & V_58 -> V_78 [ V_58 -> V_80 ] ;
V_951 -> V_89 = V_89 ;
V_951 -> V_165 = V_89 -> V_82 ;
V_951 -> V_166 = 1 ;
if ( F_525 ( V_89 ) ) {
V_967 |= F_526 ( V_89 ) << V_1023 ;
V_967 |= V_976 ;
} else if ( V_243 == F_157 ( V_242 ) ) {
struct V_1048 * V_1049 , V_1050 ;
V_1049 = F_527 ( V_89 , V_485 , sizeof( V_1050 ) , & V_1050 ) ;
if ( ! V_1049 )
goto V_1051;
V_243 = V_1049 -> V_1052 ;
V_967 |= F_528 ( V_1049 -> V_1053 ) <<
V_1023 ;
V_967 |= V_1025 ;
}
if ( F_24 ( F_149 ( V_89 ) -> V_967 & V_1054 ) &&
V_2 -> V_1055 &&
! F_529 ( V_1056 ,
& V_2 -> V_34 ) ) {
F_149 ( V_89 ) -> V_967 |= V_1057 ;
V_967 |= V_992 ;
V_2 -> V_1058 = F_530 ( V_89 ) ;
V_2 -> V_1059 = V_169 ;
F_16 ( & V_2 -> V_1060 ) ;
}
F_531 ( V_89 ) ;
#ifdef F_282
if ( V_2 -> V_137 & V_402 )
V_967 |= V_977 ;
#endif
if ( ( V_2 -> V_137 & V_138 ) &&
( ( V_967 & ( V_976 | V_1025 ) ) ||
( V_89 -> V_1061 != V_1062 ) ) ) {
V_967 &= ~ V_1063 ;
V_967 |= ( V_89 -> V_1061 & 0x7 ) <<
V_1064 ;
if ( V_967 & V_1025 ) {
struct V_1065 * V_1049 ;
if ( F_487 ( V_89 , 0 ) )
goto V_1051;
V_1049 = (struct V_1065 * ) V_89 -> V_92 ;
V_1049 -> V_1053 = F_157 ( V_967 >>
V_1023 ) ;
} else {
V_967 |= V_976 ;
}
}
V_951 -> V_967 = V_967 ;
V_951 -> V_243 = V_243 ;
#ifdef F_177
if ( ( V_243 == F_157 ( V_1042 ) ) &&
( V_58 -> V_55 -> V_194 & ( V_1066 | V_1067 ) ) ) {
V_1046 = F_532 ( V_58 , V_951 , & V_230 ) ;
if ( V_1046 < 0 )
goto V_1051;
goto V_1068;
}
#endif
V_1046 = F_485 ( V_58 , V_951 , & V_230 ) ;
if ( V_1046 < 0 )
goto V_1051;
else if ( ! V_1046 )
F_499 ( V_58 , V_951 ) ;
if ( F_14 ( V_367 , & V_58 -> V_34 ) )
F_515 ( V_58 , V_951 ) ;
#ifdef F_177
V_1068:
#endif
F_508 ( V_58 , V_951 , V_230 ) ;
return V_1069 ;
V_1051:
F_78 ( V_951 -> V_89 ) ;
V_951 -> V_89 = NULL ;
return V_1069 ;
}
static T_15 F_533 ( struct V_193 * V_89 ,
struct V_54 * V_55 ,
struct V_57 * V_118 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_57 * V_58 ;
if ( F_24 ( V_89 -> V_82 < 17 ) ) {
if ( F_178 ( V_89 , 17 - V_89 -> V_82 ) )
return V_1069 ;
V_89 -> V_82 = 17 ;
F_534 ( V_89 , 17 ) ;
}
V_58 = V_118 ? V_118 : V_2 -> V_58 [ V_89 -> V_1041 ] ;
return F_523 ( V_89 , V_2 , V_58 ) ;
}
static T_15 F_535 ( struct V_193 * V_89 ,
struct V_54 * V_55 )
{
return F_533 ( V_89 , V_55 , NULL ) ;
}
static int F_536 ( struct V_54 * V_55 , void * V_1070 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1071 * V_527 = V_1070 ;
int V_632 ;
if ( ! F_344 ( V_527 -> V_1072 ) )
return - V_1073 ;
F_293 ( V_2 , V_14 -> V_108 . V_527 , F_266 ( 0 ) ) ;
memcpy ( V_55 -> V_608 , V_527 -> V_1072 , V_55 -> V_666 ) ;
memcpy ( V_14 -> V_108 . V_527 , V_527 -> V_1072 , V_55 -> V_666 ) ;
V_632 = F_290 ( V_2 , V_14 -> V_108 . V_527 , F_266 ( 0 ) ) ;
return V_632 > 0 ? 0 : V_632 ;
}
static int
F_537 ( struct V_54 * V_55 , int V_1074 , int V_1075 , T_2 V_527 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_4 ;
int V_1076 ;
if ( V_1074 != V_14 -> V_334 . V_1077 . V_1074 )
return - V_533 ;
V_1076 = V_14 -> V_334 . V_331 . V_1078 ( V_14 , V_527 , V_1075 , & V_4 ) ;
if ( ! V_1076 )
V_1076 = V_4 ;
return V_1076 ;
}
static int F_538 ( struct V_54 * V_55 , int V_1074 , int V_1075 ,
T_2 V_527 , T_2 V_4 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_1074 != V_14 -> V_334 . V_1077 . V_1074 )
return - V_533 ;
return V_14 -> V_334 . V_331 . V_1079 ( V_14 , V_527 , V_1075 , V_4 ) ;
}
static int F_539 ( struct V_54 * V_55 , struct V_1080 * V_1081 , int V_1082 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
switch ( V_1082 ) {
case V_1083 :
return F_540 ( V_2 , V_1081 ) ;
case V_1084 :
return F_541 ( V_2 , V_1081 ) ;
default:
return F_542 ( & V_2 -> V_14 . V_334 . V_1077 , F_543 ( V_1081 ) , V_1082 ) ;
}
}
static int F_544 ( struct V_54 * V_73 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_344 ( V_14 -> V_108 . V_1085 ) ) {
F_421 () ;
V_17 = F_545 ( V_73 , V_14 -> V_108 . V_1085 , V_1086 ) ;
F_423 () ;
V_14 -> V_108 . V_331 . V_668 ( V_14 , F_266 ( 0 ) ) ;
}
return V_17 ;
}
static int F_546 ( struct V_54 * V_73 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_1087 * V_108 = & V_2 -> V_14 . V_108 ;
if ( F_344 ( V_108 -> V_1085 ) ) {
F_421 () ;
V_17 = F_547 ( V_73 , V_108 -> V_1085 , V_1086 ) ;
F_423 () ;
}
return V_17 ;
}
static void F_548 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_48 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
V_2 -> V_137 |= V_244 ;
if ( V_2 -> V_137 & V_382 ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_187 ; V_48 ++ )
F_224 ( 0 , V_2 -> V_156 [ V_48 ] ) ;
} else {
F_237 ( V_2 -> V_9 -> V_361 , V_55 ) ;
}
V_2 -> V_137 &= ~ V_244 ;
}
static struct V_1088 * F_549 ( struct V_54 * V_55 ,
struct V_1088 * V_122 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_48 ;
F_550 () ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_118 = F_21 ( V_2 -> V_67 [ V_48 ] ) ;
T_6 V_168 , V_142 ;
unsigned int V_1089 ;
if ( V_118 ) {
do {
V_1089 = F_551 ( & V_118 -> V_167 ) ;
V_142 = V_118 -> V_122 . V_142 ;
V_168 = V_118 -> V_122 . V_168 ;
} while ( F_552 ( & V_118 -> V_167 , V_1089 ) );
V_122 -> V_775 += V_142 ;
V_122 -> V_774 += V_168 ;
}
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_118 = F_21 ( V_2 -> V_58 [ V_48 ] ) ;
T_6 V_168 , V_142 ;
unsigned int V_1089 ;
if ( V_118 ) {
do {
V_1089 = F_551 ( & V_118 -> V_167 ) ;
V_142 = V_118 -> V_122 . V_142 ;
V_168 = V_118 -> V_122 . V_168 ;
} while ( F_552 ( & V_118 -> V_167 , V_1089 ) );
V_122 -> V_777 += V_142 ;
V_122 -> V_776 += V_168 ;
}
}
F_553 () ;
V_122 -> V_884 = V_55 -> V_122 . V_884 ;
V_122 -> V_885 = V_55 -> V_122 . V_885 ;
V_122 -> V_887 = V_55 -> V_122 . V_887 ;
V_122 -> V_888 = V_55 -> V_122 . V_888 ;
V_122 -> V_889 = V_55 -> V_122 . V_889 ;
return V_122 ;
}
static void F_554 ( struct V_1 * V_2 , T_4 V_132 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_3 , V_1090 ;
int V_48 ;
if ( V_14 -> V_108 . type == V_109 )
return;
V_3 = F_37 ( V_14 , V_1091 ) ;
V_1090 = V_3 ;
for ( V_48 = 0 ; V_48 < V_579 ; V_48 ++ ) {
T_4 V_1092 = V_3 >> ( V_48 * V_1093 ) ;
if ( V_1092 > V_132 )
V_3 &= ~ ( 0x7 << V_1093 ) ;
}
if ( V_3 != V_1090 )
F_71 ( V_14 , V_1091 , V_3 ) ;
return;
}
static void F_555 ( struct V_1 * V_2 )
{
struct V_54 * V_73 = V_2 -> V_55 ;
struct V_1094 * V_134 = & V_2 -> V_134 ;
struct V_1095 * V_1096 = V_2 -> V_564 ;
T_4 V_1097 ;
for ( V_1097 = 0 ; V_1097 < V_1098 ; V_1097 ++ ) {
T_4 V_132 = 0 ;
if ( V_2 -> V_560 & V_561 )
V_132 = F_556 ( V_134 , 0 , V_1097 ) ;
else if ( V_1096 )
V_132 = V_1096 -> V_565 [ V_1097 ] ;
F_557 ( V_73 , V_1097 , V_132 ) ;
}
}
int F_558 ( struct V_54 * V_73 , T_4 V_132 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
bool V_1099 ;
if ( V_132 > V_2 -> V_134 . V_702 . V_703 ||
( V_14 -> V_108 . type == V_109 &&
V_132 < V_579 ) )
return - V_533 ;
V_1099 = ( F_559 ( & V_2 -> V_605 , 32 ) > 1 ) ;
if ( V_132 && V_1099 && V_2 -> V_606 > V_1100 )
return - V_741 ;
if ( F_57 ( V_73 ) )
F_411 ( V_73 ) ;
F_428 ( V_2 ) ;
#ifdef F_349
if ( V_132 ) {
F_560 ( V_73 , V_132 ) ;
F_555 ( V_2 ) ;
V_2 -> V_137 |= V_138 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ) {
V_2 -> V_1101 = V_2 -> V_14 . V_123 . V_717 ;
V_2 -> V_14 . V_123 . V_717 = V_1102 ;
}
} else {
F_561 ( V_73 ) ;
if ( V_2 -> V_14 . V_108 . type == V_109 )
V_2 -> V_14 . V_123 . V_717 = V_2 -> V_1101 ;
V_2 -> V_137 &= ~ V_138 ;
V_2 -> V_716 . V_135 = false ;
V_2 -> V_134 . V_135 = false ;
}
F_554 ( V_2 , V_132 ) ;
#endif
F_422 ( V_2 ) ;
if ( F_57 ( V_73 ) )
return F_407 ( V_73 ) ;
return 0 ;
}
void F_562 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
F_421 () ;
F_558 ( V_55 , F_249 ( V_55 ) ) ;
F_423 () ;
}
void F_563 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
if ( F_57 ( V_55 ) )
F_360 ( V_2 ) ;
else
F_366 ( V_2 ) ;
}
static T_16 F_564 ( struct V_54 * V_55 ,
T_16 V_194 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
if ( ! ( V_194 & V_207 ) )
V_194 &= ~ V_1103 ;
if ( ! ( V_2 -> V_152 & V_688 ) )
V_194 &= ~ V_1103 ;
return V_194 ;
}
static int F_565 ( struct V_54 * V_55 ,
T_16 V_194 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
T_16 V_1104 = V_55 -> V_194 ^ V_194 ;
bool V_1105 = false ;
if ( ! ( V_194 & V_1103 ) ) {
if ( V_2 -> V_152 & V_497 )
V_1105 = true ;
V_2 -> V_152 &= ~ V_497 ;
} else if ( ( V_2 -> V_152 & V_688 ) &&
! ( V_2 -> V_152 & V_497 ) ) {
if ( V_2 -> V_373 == 1 ||
V_2 -> V_373 > V_1106 ) {
V_2 -> V_152 |= V_497 ;
V_1105 = true ;
} else if ( ( V_1104 ^ V_194 ) & V_1103 ) {
F_105 ( V_170 , L_136
L_137 ) ;
}
}
switch ( V_194 & V_1107 ) {
case V_1107 :
if ( ! ( V_2 -> V_137 & V_581 ) )
V_1105 = true ;
V_2 -> V_137 &= ~ V_358 ;
V_2 -> V_137 |= V_581 ;
break;
default:
if ( V_2 -> V_137 & V_581 )
V_1105 = true ;
V_2 -> V_137 &= ~ V_581 ;
if ( V_2 -> V_137 & V_402 )
break;
if ( F_249 ( V_55 ) > 1 )
break;
if ( V_2 -> V_407 [ V_408 ] . V_687 <= 1 )
break;
if ( ! V_2 -> V_392 )
break;
V_2 -> V_137 |= V_358 ;
break;
}
if ( V_194 & V_238 )
F_279 ( V_2 ) ;
else
F_278 ( V_2 ) ;
if ( V_1104 & V_264 )
V_1105 = true ;
V_55 -> V_194 = V_194 ;
if ( V_1105 )
F_563 ( V_55 ) ;
return 0 ;
}
static int F_566 ( struct V_1108 * V_1109 , struct V_1110 * V_1111 [] ,
struct V_54 * V_73 ,
const unsigned char * V_527 ,
T_2 V_137 )
{
if ( F_567 ( V_527 ) || F_568 ( V_527 ) ) {
if ( V_1112 <= F_296 ( V_73 ) )
return - V_522 ;
}
return F_569 ( V_1109 , V_1111 , V_73 , V_527 , V_137 ) ;
}
static int F_570 ( struct V_54 * V_73 ,
struct V_1113 * V_1114 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_1110 * V_1115 , * V_1116 ;
int V_1117 ;
if ( ! ( V_2 -> V_137 & V_402 ) )
return - V_1118 ;
V_1116 = F_571 ( V_1114 , sizeof( struct V_1119 ) , V_1120 ) ;
if ( ! V_1116 )
return - V_533 ;
F_572 (attr, br_spec, rem) {
T_17 V_1121 ;
T_1 V_3 = 0 ;
if ( F_573 ( V_1115 ) != V_1122 )
continue;
if ( F_574 ( V_1115 ) < sizeof( V_1121 ) )
return - V_533 ;
V_1121 = F_575 ( V_1115 ) ;
if ( V_1121 == V_1123 ) {
V_3 = 0 ;
V_2 -> V_152 &= ~ V_470 ;
} else if ( V_1121 == V_1124 ) {
V_3 = V_472 ;
V_2 -> V_152 |= V_470 ;
} else
return - V_533 ;
F_71 ( & V_2 -> V_14 , V_471 , V_3 ) ;
F_105 ( V_154 , L_138 ,
V_1121 == V_1123 ? L_139 : L_140 ) ;
}
return 0 ;
}
static int F_576 ( struct V_193 * V_89 , T_1 V_1125 , T_1 V_1126 ,
struct V_54 * V_73 ,
T_1 V_1127 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
T_2 V_1121 ;
if ( ! ( V_2 -> V_137 & V_402 ) )
return 0 ;
if ( V_2 -> V_152 & V_470 )
V_1121 = V_1124 ;
else
V_1121 = V_1123 ;
return F_577 ( V_89 , V_1125 , V_1126 , V_73 , V_1121 ) ;
}
static void * F_578 ( struct V_54 * V_9 , struct V_54 * V_599 )
{
struct V_595 * V_1038 = NULL ;
struct V_1 * V_2 = F_89 ( V_9 ) ;
int V_1128 = V_2 -> V_298 + V_2 -> V_606 ;
unsigned int V_687 ;
int V_455 , V_17 ;
if ( V_1128 >= V_1129 )
return F_579 ( - V_533 ) ;
#ifdef F_580
if ( V_599 -> V_93 != V_599 -> V_77 ) {
F_581 ( V_9 , L_141 ,
V_599 -> V_53 ) ;
return F_579 ( - V_533 ) ;
}
#endif
if ( V_599 -> V_77 > V_744 ||
V_599 -> V_77 == V_1130 ) {
F_581 ( V_9 ,
L_142 ,
V_9 -> V_53 ) ;
return F_579 ( - V_533 ) ;
}
if ( ( ( V_2 -> V_137 & V_138 ) &&
V_2 -> V_606 > V_1100 - 1 ) ||
( V_2 -> V_606 > V_1131 ) )
return F_579 ( - V_741 ) ;
V_1038 = F_582 ( 1 , sizeof( struct V_595 ) , V_735 ) ;
if ( ! V_1038 )
return F_579 ( - V_522 ) ;
V_455 = F_559 ( & V_2 -> V_605 , 32 ) ;
V_2 -> V_606 ++ ;
F_245 ( V_455 , & V_2 -> V_605 ) ;
V_687 = F_583 ( & V_2 -> V_605 , 32 ) ;
V_2 -> V_137 |= V_554 | V_402 ;
V_2 -> V_407 [ V_474 ] . V_687 = V_687 + 1 ;
V_2 -> V_407 [ V_408 ] . V_687 = V_599 -> V_77 ;
V_17 = F_558 ( V_9 , F_249 ( V_9 ) ) ;
if ( V_17 )
goto V_1132;
V_1038 -> V_455 = V_455 ;
V_1038 -> V_146 = V_2 ;
V_17 = F_339 ( V_599 , V_1038 ) ;
if ( V_17 )
goto V_1132;
F_584 ( V_599 ) ;
return V_1038 ;
V_1132:
F_581 ( V_9 ,
L_143 , V_599 -> V_53 ) ;
F_34 ( V_455 , & V_2 -> V_605 ) ;
V_2 -> V_606 -- ;
F_236 ( V_1038 ) ;
return F_579 ( V_17 ) ;
}
static void F_585 ( struct V_54 * V_9 , void * V_1133 )
{
struct V_595 * V_1038 = V_1133 ;
struct V_1 * V_2 = V_1038 -> V_146 ;
unsigned int V_687 ;
F_34 ( V_1038 -> V_455 , & V_2 -> V_605 ) ;
V_2 -> V_606 -- ;
V_687 = F_583 ( & V_2 -> V_605 , 32 ) ;
V_2 -> V_407 [ V_474 ] . V_687 = V_687 + 1 ;
F_337 ( V_1038 -> V_55 , V_1038 ) ;
F_558 ( V_9 , F_249 ( V_9 ) ) ;
F_340 ( V_9 , L_92 ,
V_1038 -> V_455 , V_2 -> V_606 ,
V_1038 -> V_598 ,
V_1038 -> V_598 + V_2 -> V_597 ,
V_2 -> V_605 ) ;
F_236 ( V_1038 ) ;
}
static inline int F_586 ( struct V_1 * V_2 )
{
struct V_5 * V_378 , * V_9 = V_2 -> V_9 ;
int V_1134 = 0 ;
if ( F_8 ( & V_2 -> V_14 ) )
V_1134 = 4 ;
F_587 (entry, &adapter->pdev->bus->devices, bus_list) {
if ( V_378 -> V_1135 )
continue;
if ( ( V_378 -> V_679 != V_9 -> V_679 ) ||
( V_378 -> V_188 != V_9 -> V_188 ) )
return - 1 ;
V_1134 ++ ;
}
return V_1134 ;
}
int F_588 ( struct V_1 * V_2 , T_2 V_21 ,
T_2 V_1136 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1137 = V_2 -> V_1138 & V_1139 ;
int V_1140 = 0 ;
switch ( V_21 ) {
case V_1141 :
switch ( V_1136 ) {
case V_1142 :
case V_1143 :
if ( V_14 -> V_10 . V_1144 != 0 )
break;
case V_1145 :
case V_1146 :
case V_1147 :
case V_1148 :
case V_1149 :
V_1140 = 1 ;
break;
}
break;
case V_1150 :
switch ( V_1136 ) {
case V_1151 :
V_1140 = 1 ;
break;
}
break;
case V_1152 :
if ( V_1136 != V_1153 )
V_1140 = 1 ;
break;
case V_1154 :
V_1140 = 1 ;
break;
case V_1155 :
case V_1156 :
if ( ( V_1137 == V_1157 ) ||
( ( V_1137 == V_1158 ) &&
( V_14 -> V_10 . V_1144 == 0 ) ) ) {
V_1140 = 1 ;
}
break;
}
return V_1140 ;
}
static int F_589 ( struct V_5 * V_9 , const struct V_1159 * V_1160 )
{
struct V_54 * V_55 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_14 ;
const struct V_1161 * V_1162 = V_1163 [ V_1160 -> V_1164 ] ;
int V_48 , V_17 , V_1165 , V_24 ;
unsigned int V_409 = V_1166 ;
T_4 V_1167 [ V_1168 ] ;
bool V_1169 = false ;
#ifdef F_177
T_2 V_1170 ;
#endif
T_1 V_1171 ;
if ( V_9 -> V_1135 ) {
F_590 ( 1 , V_1172 L_144 ,
F_591 ( V_9 ) , V_9 -> V_679 , V_9 -> V_188 ) ;
return - V_533 ;
}
V_17 = F_418 ( V_9 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_592 ( & V_9 -> V_73 , F_244 ( 64 ) ) ) {
V_1165 = 1 ;
} else {
V_17 = F_592 ( & V_9 -> V_73 , F_244 ( 32 ) ) ;
if ( V_17 ) {
F_395 ( & V_9 -> V_73 ,
L_145 ) ;
goto V_1173;
}
V_1165 = 0 ;
}
V_17 = F_593 ( V_9 , F_594 ( V_9 ,
V_1174 ) , V_1175 ) ;
if ( V_17 ) {
F_395 ( & V_9 -> V_73 ,
L_146 , V_17 ) ;
goto V_1176;
}
F_595 ( V_9 ) ;
F_419 ( V_9 ) ;
F_417 ( V_9 ) ;
if ( V_1162 -> V_108 == V_109 ) {
#ifdef F_349
V_409 = 4 * V_579 ;
#else
V_409 = V_686 ;
#endif
}
V_55 = F_596 ( sizeof( struct V_1 ) , V_409 ) ;
if ( ! V_55 ) {
V_17 = - V_522 ;
goto V_1177;
}
F_597 ( V_55 , & V_9 -> V_73 ) ;
V_2 = F_89 ( V_55 ) ;
F_598 ( V_9 , V_2 ) ;
V_2 -> V_55 = V_55 ;
V_2 -> V_9 = V_9 ;
V_14 = & V_2 -> V_14 ;
V_14 -> V_38 = V_2 ;
V_2 -> V_1178 = F_599 ( V_1179 , V_1180 ) ;
V_14 -> V_39 = F_600 ( F_601 ( V_9 , 0 ) ,
F_602 ( V_9 , 0 ) ) ;
V_2 -> V_391 = V_14 -> V_39 ;
if ( ! V_14 -> V_39 ) {
V_17 = - V_731 ;
goto V_1181;
}
V_55 -> V_1182 = & V_1183 ;
F_603 ( V_55 ) ;
V_55 -> V_1184 = 5 * V_946 ;
F_604 ( V_55 -> V_53 , F_591 ( V_9 ) , sizeof( V_55 -> V_53 ) ) ;
memcpy ( & V_14 -> V_108 . V_331 , V_1162 -> V_1185 , sizeof( V_14 -> V_108 . V_331 ) ) ;
V_14 -> V_108 . type = V_1162 -> V_108 ;
memcpy ( & V_14 -> V_1186 . V_331 , V_1162 -> V_1187 , sizeof( V_14 -> V_1186 . V_331 ) ) ;
V_1171 = F_37 ( V_14 , V_1188 ) ;
if ( F_22 ( V_14 -> V_39 ) ) {
V_17 = - V_731 ;
goto V_1181;
}
if ( ! ( V_1171 & ( 1 << 8 ) ) )
V_14 -> V_1186 . V_331 . V_227 = & V_1189 ;
memcpy ( & V_14 -> V_334 . V_331 , V_1162 -> V_1190 , sizeof( V_14 -> V_334 . V_331 ) ) ;
V_14 -> V_334 . V_932 = V_1191 ;
V_14 -> V_334 . V_1077 . V_1074 = V_1192 ;
V_14 -> V_334 . V_1077 . V_1193 = 0 ;
V_14 -> V_334 . V_1077 . V_1194 = V_1195 | V_1196 ;
V_14 -> V_334 . V_1077 . V_73 = V_55 ;
V_14 -> V_334 . V_1077 . V_1197 = F_537 ;
V_14 -> V_334 . V_1077 . V_1198 = F_538 ;
V_1162 -> V_1199 ( V_14 ) ;
V_17 = F_381 ( V_2 ) ;
if ( V_17 )
goto V_1200;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
case V_112 :
F_71 ( & V_2 -> V_14 , V_747 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_137 & V_337 ) {
T_1 V_653 = F_37 ( V_14 , V_654 ) ;
if ( V_653 & V_655 )
F_209 ( V_170 , L_73 ) ;
}
if ( V_1201 )
V_14 -> V_1201 = V_1201 ;
V_14 -> V_334 . V_1202 = true ;
V_17 = V_14 -> V_108 . V_331 . V_1203 ( V_14 ) ;
V_14 -> V_334 . V_1202 = false ;
if ( V_17 == V_662 &&
V_14 -> V_108 . type == V_109 ) {
V_17 = 0 ;
} else if ( V_17 == V_663 ) {
F_18 ( L_147 ) ;
F_18 ( L_148 ) ;
goto V_1200;
} else if ( V_17 ) {
F_18 ( L_149 , V_17 ) ;
goto V_1200;
}
#ifdef F_282
if ( V_2 -> V_14 . V_108 . type == V_109 )
goto V_1204;
F_605 ( V_14 ) ;
memcpy ( & V_14 -> V_1205 . V_331 , V_1162 -> V_1206 , sizeof( V_14 -> V_1205 . V_331 ) ) ;
F_606 ( V_9 , V_723 ) ;
F_607 ( V_2 ) ;
V_1204:
#endif
V_55 -> V_194 = V_1207 |
V_1208 |
V_1209 |
V_1210 |
V_238 |
V_1211 |
V_1212 |
V_1213 |
V_195 |
V_207 ;
V_55 -> V_1214 = V_55 -> V_194 | V_1215 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
case V_112 :
V_55 -> V_194 |= V_1216 ;
V_55 -> V_1214 |= V_1216 |
V_1107 ;
break;
default:
break;
}
V_55 -> V_1214 |= V_264 ;
V_55 -> V_1217 |= V_1212 ;
V_55 -> V_1217 |= V_1213 ;
V_55 -> V_1217 |= V_1208 ;
V_55 -> V_1217 |= V_1209 ;
V_55 -> V_1217 |= V_1207 ;
V_55 -> V_1218 |= V_1219 ;
V_55 -> V_1218 |= V_1220 ;
#ifdef F_349
V_55 -> V_1221 = & V_1221 ;
#endif
#ifdef F_177
if ( V_2 -> V_137 & V_694 ) {
unsigned int V_1222 ;
if ( V_14 -> V_108 . V_331 . V_1223 ) {
V_14 -> V_108 . V_331 . V_1223 ( V_14 , & V_1170 ) ;
if ( V_1170 & V_1224 )
V_2 -> V_137 &= ~ V_694 ;
}
V_1222 = F_341 ( int , V_1225 , F_382 () ) ;
V_2 -> V_407 [ V_1044 ] . V_687 = V_1222 ;
V_55 -> V_194 |= V_1066 |
V_1067 ;
V_55 -> V_1217 |= V_1066 |
V_1067 |
V_559 ;
}
#endif
if ( V_1165 ) {
V_55 -> V_194 |= V_1226 ;
V_55 -> V_1217 |= V_1226 ;
}
if ( V_2 -> V_152 & V_688 )
V_55 -> V_1214 |= V_1103 ;
if ( V_2 -> V_152 & V_497 )
V_55 -> V_194 |= V_1103 ;
if ( V_14 -> V_1186 . V_331 . V_1227 ( V_14 , NULL ) < 0 ) {
F_18 ( L_150 ) ;
V_17 = - V_731 ;
goto V_1200;
}
memcpy ( V_55 -> V_608 , V_14 -> V_108 . V_1228 , V_55 -> V_666 ) ;
if ( ! F_344 ( V_55 -> V_608 ) ) {
F_18 ( L_151 ) ;
V_17 = - V_731 ;
goto V_1200;
}
F_289 ( V_2 , V_14 -> V_108 . V_1228 ) ;
F_608 ( & V_2 -> V_656 , & F_480 ,
( unsigned long ) V_2 ) ;
if ( F_22 ( V_14 -> V_39 ) ) {
V_17 = - V_731 ;
goto V_1200;
}
F_609 ( & V_2 -> V_37 , F_482 ) ;
F_245 ( V_40 , & V_2 -> V_34 ) ;
F_34 ( V_36 , & V_2 -> V_34 ) ;
V_17 = F_422 ( V_2 ) ;
if ( V_17 )
goto V_1200;
V_2 -> V_751 = 0 ;
V_14 -> V_1186 . V_331 . V_227 ( V_14 , 0x2c , & V_2 -> V_1138 ) ;
V_14 -> V_1229 = F_588 ( V_2 , V_9 -> V_188 ,
V_9 -> V_685 ) ;
if ( V_14 -> V_1229 )
V_2 -> V_751 = V_1230 ;
F_610 ( & V_2 -> V_9 -> V_73 , V_2 -> V_751 ) ;
V_14 -> V_1186 . V_331 . V_227 ( V_14 , 0x2e , & V_2 -> V_1231 ) ;
V_14 -> V_1186 . V_331 . V_227 ( V_14 , 0x2d , & V_2 -> V_1232 ) ;
V_14 -> V_108 . V_331 . V_1233 ( V_14 ) ;
if ( F_8 ( V_14 ) )
F_5 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_24 = F_611 ( F_586 ( V_2 ) * 10 , 16 ) ;
break;
default:
V_24 = F_586 ( V_2 ) * 10 ;
break;
}
if ( V_24 > 0 )
F_9 ( V_2 , V_24 ) ;
V_17 = F_612 ( V_14 , V_1167 , sizeof( V_1167 ) ) ;
if ( V_17 )
F_604 ( V_1167 , L_7 , sizeof( V_1167 ) ) ;
if ( F_353 ( V_14 ) && V_14 -> V_334 . V_932 != V_1234 )
F_12 ( L_152 ,
V_14 -> V_108 . type , V_14 -> V_334 . type , V_14 -> V_334 . V_932 ,
V_1167 ) ;
else
F_12 ( L_153 ,
V_14 -> V_108 . type , V_14 -> V_334 . type , V_1167 ) ;
F_12 ( L_154 , V_55 -> V_608 ) ;
V_17 = V_14 -> V_108 . V_331 . V_1235 ( V_14 ) ;
if ( V_17 == V_665 ) {
F_11 ( L_95
L_155
L_156
L_157
L_99
L_100 ) ;
}
strcpy ( V_55 -> V_53 , L_158 ) ;
V_17 = F_613 ( V_55 ) ;
if ( V_17 )
goto V_1236;
if ( V_14 -> V_108 . V_331 . V_674 )
V_14 -> V_108 . V_331 . V_674 ( V_14 ) ;
F_374 ( V_55 ) ;
#ifdef F_227
if ( F_126 ( & V_9 -> V_73 ) == 0 ) {
V_2 -> V_137 |= V_185 ;
F_123 ( V_2 ) ;
}
#endif
if ( V_2 -> V_137 & V_402 ) {
F_105 ( V_170 , L_159 , V_2 -> V_298 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_298 ; V_48 ++ )
F_614 ( V_9 , ( V_48 | 0x10000000 ) ) ;
}
if ( V_14 -> V_108 . V_331 . V_1237 )
V_14 -> V_108 . V_331 . V_1237 ( V_14 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_544 ( V_55 ) ;
F_12 ( L_160 , V_1238 ) ;
#ifdef F_615
if ( F_616 ( V_2 ) )
F_103 ( V_170 , L_161 ) ;
#endif
F_617 ( V_2 ) ;
if ( F_618 ( V_14 ) && F_353 ( V_14 ) && V_14 -> V_108 . V_331 . V_636 )
V_14 -> V_108 . V_331 . V_636 ( V_14 ,
V_896 | V_919 ,
true ) ;
return 0 ;
V_1236:
F_70 ( V_2 ) ;
F_428 ( V_2 ) ;
V_1200:
F_619 ( V_2 ) ;
V_2 -> V_152 &= ~ V_630 ;
F_620 ( V_2 -> V_391 ) ;
F_236 ( V_2 -> V_524 ) ;
V_1181:
V_1169 = ! F_15 ( V_746 , & V_2 -> V_34 ) ;
F_621 ( V_55 ) ;
V_1177:
F_622 ( V_9 ,
F_594 ( V_9 , V_1174 ) ) ;
V_1176:
V_1173:
if ( ! V_2 || V_1169 )
F_429 ( V_9 ) ;
return V_17 ;
}
static void F_623 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_414 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
bool V_1169 ;
F_624 ( V_2 ) ;
F_245 ( V_35 , & V_2 -> V_34 ) ;
F_625 ( & V_2 -> V_37 ) ;
#ifdef F_227
if ( V_2 -> V_137 & V_185 ) {
V_2 -> V_137 &= ~ V_185 ;
F_127 ( & V_9 -> V_73 ) ;
F_71 ( & V_2 -> V_14 , V_186 , 1 ) ;
}
#endif
#ifdef F_615
F_626 ( V_2 ) ;
#endif
F_546 ( V_55 ) ;
if ( V_55 -> V_933 == V_934 )
F_476 ( V_55 ) ;
#ifdef F_282
if ( V_722 )
F_619 ( V_2 ) ;
#endif
F_428 ( V_2 ) ;
F_70 ( V_2 ) ;
#ifdef F_627
F_236 ( V_2 -> V_136 ) ;
F_236 ( V_2 -> V_564 ) ;
#endif
F_620 ( V_2 -> V_391 ) ;
F_622 ( V_9 , F_594 ( V_9 ,
V_1174 ) ) ;
F_12 ( L_162 ) ;
F_236 ( V_2 -> V_524 ) ;
V_1169 = ! F_15 ( V_746 , & V_2 -> V_34 ) ;
F_621 ( V_55 ) ;
F_628 ( V_9 ) ;
if ( V_1169 )
F_429 ( V_9 ) ;
}
static T_18 F_629 ( struct V_5 * V_9 ,
T_19 V_34 )
{
struct V_1 * V_2 = F_414 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
#ifdef F_282
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_1239 , * V_1240 ;
T_1 V_1241 , V_1242 , V_1243 , V_1244 ;
int V_935 , V_1245 ;
T_2 V_1246 , V_1247 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ||
V_2 -> V_298 == 0 )
goto V_1248;
V_1239 = V_9 -> V_10 -> V_12 ;
while ( V_1239 && ( F_630 ( V_1239 ) != V_1249 ) )
V_1239 = V_1239 -> V_10 -> V_12 ;
if ( ! V_1239 )
goto V_1248;
V_1245 = F_631 ( V_1239 , V_1250 ) ;
if ( ! V_1245 )
goto V_1248;
V_1241 = F_27 ( V_14 , V_1245 + V_1251 ) ;
V_1242 = F_27 ( V_14 , V_1245 + V_1251 + 4 ) ;
V_1243 = F_27 ( V_14 , V_1245 + V_1251 + 8 ) ;
V_1244 = F_27 ( V_14 , V_1245 + V_1251 + 12 ) ;
if ( F_22 ( V_14 -> V_39 ) )
goto V_1248;
V_1246 = V_1242 >> 16 ;
if ( ! ( V_1246 & 0x0080 ) )
goto V_1248;
V_1247 = V_1246 & 0x01 ;
if ( ( V_1247 & 1 ) == ( V_9 -> V_1252 & 1 ) ) {
unsigned int V_21 ;
V_935 = ( V_1246 & 0x7F ) >> 1 ;
F_18 ( L_163 , V_935 ) ;
F_18 ( L_164
L_165 ,
V_1241 , V_1242 , V_1243 , V_1244 ) ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_21 = V_1253 ;
break;
case V_112 :
V_21 = V_1254 ;
break;
default:
V_21 = 0 ;
break;
}
V_1240 = F_632 ( V_1255 , V_21 , NULL ) ;
while ( V_1240 ) {
if ( V_1240 -> V_1252 == ( V_1246 & 0xFF ) )
break;
V_1240 = F_632 ( V_1255 ,
V_21 , V_1240 ) ;
}
if ( V_1240 ) {
F_18 ( L_166 , V_935 ) ;
F_633 ( V_1240 , 0xA8 , 0x00008000 ) ;
F_634 ( V_1240 ) ;
}
F_635 ( V_9 ) ;
}
V_2 -> V_1256 ++ ;
return V_1257 ;
V_1248:
#endif
if ( ! F_14 ( V_40 , & V_2 -> V_34 ) )
return V_1258 ;
F_421 () ;
F_427 ( V_55 ) ;
if ( V_34 == V_1259 ) {
F_423 () ;
return V_1258 ;
}
if ( F_57 ( V_55 ) )
F_363 ( V_2 ) ;
if ( ! F_15 ( V_746 , & V_2 -> V_34 ) )
F_429 ( V_9 ) ;
F_423 () ;
return V_1260 ;
}
static T_18 F_636 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_414 ( V_9 ) ;
T_18 V_1261 ;
int V_17 ;
if ( F_418 ( V_9 ) ) {
F_103 ( V_170 , L_167 ) ;
V_1261 = V_1258 ;
} else {
F_33 () ;
F_34 ( V_746 , & V_2 -> V_34 ) ;
V_2 -> V_14 . V_39 = V_2 -> V_391 ;
F_419 ( V_9 ) ;
F_416 ( V_9 ) ;
F_417 ( V_9 ) ;
F_420 ( V_9 , false ) ;
F_366 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_747 , ~ 0 ) ;
V_1261 = V_1257 ;
}
V_17 = F_635 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_168
L_169 , V_17 ) ;
}
return V_1261 ;
}
static void F_637 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_414 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
#ifdef F_282
if ( V_2 -> V_1256 ) {
F_105 ( V_154 , L_170 ) ;
V_2 -> V_1256 -- ;
return;
}
#endif
if ( F_57 ( V_55 ) )
F_365 ( V_2 ) ;
F_424 ( V_55 ) ;
}
static int T_20 F_638 ( void )
{
int V_632 ;
F_51 ( L_171 , V_1262 , V_1263 ) ;
F_51 ( L_160 , V_1264 ) ;
F_639 () ;
V_632 = F_640 ( & V_1265 ) ;
if ( V_632 ) {
F_641 () ;
return V_632 ;
}
#ifdef F_227
F_642 ( & V_1266 ) ;
#endif
return 0 ;
}
static void T_21 F_643 ( void )
{
#ifdef F_227
F_644 ( & V_1266 ) ;
#endif
F_645 ( & V_1265 ) ;
F_641 () ;
F_646 () ;
}
static int F_647 ( struct V_1267 * V_1268 , unsigned long V_189 ,
void * V_1070 )
{
int V_1269 ;
V_1269 = F_648 ( & V_1265 . V_1270 , NULL , & V_189 ,
F_124 ) ;
return V_1269 ? V_1271 : V_1272 ;
}
