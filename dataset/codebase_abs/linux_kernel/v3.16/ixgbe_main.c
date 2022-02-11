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
goto exit;
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
goto exit;
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
exit:
return;
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
bool V_152 = false ;
F_91 ( V_58 ) ;
if ( ( V_149 == V_148 ) && V_151 ) {
V_152 = F_15 ( V_130 ,
& V_58 -> V_34 ) ;
} else {
V_58 -> V_150 . V_149 = V_148 ;
F_34 ( V_130 , & V_58 -> V_34 ) ;
}
return V_152 ;
}
static void F_92 ( struct V_1 * V_2 )
{
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_153 |= V_154 ;
F_93 ( V_155 , L_60 ) ;
F_13 ( V_2 ) ;
}
}
static bool F_94 ( struct V_156 * V_157 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = V_157 -> V_2 ;
struct V_59 * V_60 ;
union V_61 * V_62 ;
unsigned int V_158 = 0 , V_159 = 0 ;
unsigned int V_160 = V_157 -> V_161 . V_162 ;
unsigned int V_48 = V_58 -> V_79 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return true ;
V_60 = & V_58 -> V_78 [ V_48 ] ;
V_62 = F_61 ( V_58 , V_48 ) ;
V_48 -= V_58 -> V_88 ;
do {
union V_61 * V_163 = V_60 -> V_83 ;
if ( ! V_163 )
break;
F_95 () ;
if ( ! ( V_163 -> V_94 . V_164 & F_96 ( V_165 ) ) )
break;
V_60 -> V_83 = NULL ;
V_158 += V_60 -> V_166 ;
V_159 += V_60 -> V_167 ;
F_78 ( V_60 -> V_89 ) ;
F_79 ( V_58 -> V_73 ,
F_58 ( V_60 , V_81 ) ,
F_59 ( V_60 , V_82 ) ,
V_119 ) ;
V_60 -> V_89 = NULL ;
F_81 ( V_60 , V_82 , 0 ) ;
while ( V_62 != V_163 ) {
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
V_160 -- ;
} while ( F_98 ( V_160 ) );
V_48 += V_58 -> V_88 ;
V_58 -> V_79 = V_48 ;
F_99 ( & V_58 -> V_168 ) ;
V_58 -> V_122 . V_169 += V_158 ;
V_58 -> V_122 . V_142 += V_159 ;
F_100 ( & V_58 -> V_168 ) ;
V_157 -> V_161 . V_158 += V_158 ;
V_157 -> V_161 . V_159 += V_159 ;
if ( F_101 ( V_58 ) && F_90 ( V_58 ) ) {
struct V_15 * V_14 = & V_2 -> V_14 ;
F_102 ( V_155 , L_61
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
V_58 -> V_78 [ V_48 ] . V_84 , V_170 ) ;
F_103 ( V_58 -> V_55 , V_58 -> V_86 ) ;
F_104 ( V_171 ,
L_69 ,
V_2 -> V_172 + 1 , V_58 -> V_86 ) ;
F_92 ( V_2 ) ;
return true ;
}
F_105 ( F_106 ( V_58 ) ,
V_159 , V_158 ) ;
#define F_107 (DESC_NEEDED * 2)
if ( F_24 ( V_159 && F_108 ( V_58 -> V_55 ) &&
( F_109 ( V_58 ) >= F_107 ) ) ) {
F_110 () ;
if ( F_111 ( V_58 -> V_55 ,
V_58 -> V_86 )
&& ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
F_112 ( V_58 -> V_55 ,
V_58 -> V_86 ) ;
++ V_58 -> V_150 . V_173 ;
}
}
return ! ! V_160 ;
}
static void F_113 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
int V_174 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_175 = F_114 ( V_58 -> V_73 , V_174 ) ;
T_2 V_176 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_176 = F_115 ( V_58 -> V_147 ) ;
break;
case V_111 :
case V_112 :
V_176 = F_116 ( V_58 -> V_147 ) ;
V_175 <<= V_177 ;
break;
default:
return;
}
V_175 |= V_178 |
V_179 |
V_180 ;
F_71 ( V_14 , V_176 , V_175 ) ;
}
static void F_117 ( struct V_1 * V_2 ,
struct V_57 * V_67 ,
int V_174 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_181 = F_114 ( V_67 -> V_73 , V_174 ) ;
T_4 V_147 = V_67 -> V_147 ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
V_181 <<= V_182 ;
break;
default:
break;
}
V_181 |= V_183 |
V_184 ;
F_71 ( V_14 , F_38 ( V_147 ) , V_181 ) ;
}
static void F_118 ( struct V_156 * V_157 )
{
struct V_1 * V_2 = V_157 -> V_2 ;
struct V_57 * V_118 ;
int V_174 = F_119 () ;
if ( V_157 -> V_174 == V_174 )
goto V_185;
F_120 (ring, q_vector->tx)
F_113 ( V_2 , V_118 , V_174 ) ;
F_120 (ring, q_vector->rx)
F_117 ( V_2 , V_118 , V_174 ) ;
V_157 -> V_174 = V_174 ;
V_185:
F_121 () ;
}
static void F_122 ( struct V_1 * V_2 )
{
int V_48 ;
if ( ! ( V_2 -> V_137 & V_186 ) )
return;
F_71 ( & V_2 -> V_14 , V_187 , 2 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_188 ; V_48 ++ ) {
V_2 -> V_157 [ V_48 ] -> V_174 = - 1 ;
F_118 ( V_2 -> V_157 [ V_48 ] ) ;
}
}
static int F_123 ( struct V_189 * V_73 , void * V_92 )
{
struct V_1 * V_2 = F_124 ( V_73 ) ;
unsigned long V_190 = * ( unsigned long * ) V_92 ;
if ( ! ( V_2 -> V_137 & V_191 ) )
return 0 ;
switch ( V_190 ) {
case V_192 :
if ( V_2 -> V_137 & V_186 )
break;
if ( F_125 ( V_73 ) == 0 ) {
V_2 -> V_137 |= V_186 ;
F_122 ( V_2 ) ;
break;
}
case V_193 :
if ( V_2 -> V_137 & V_186 ) {
F_126 ( V_73 ) ;
V_2 -> V_137 &= ~ V_186 ;
F_71 ( & V_2 -> V_14 , V_187 , 1 ) ;
}
break;
}
return 0 ;
}
static inline void F_127 ( struct V_57 * V_118 ,
union V_68 * V_69 ,
struct V_194 * V_89 )
{
if ( V_118 -> V_55 -> V_195 & V_196 )
F_128 ( V_89 ,
F_67 ( V_69 -> V_94 . V_197 . V_198 . V_199 ) ,
V_200 ) ;
}
static inline bool F_129 ( struct V_57 * V_118 ,
union V_68 * V_69 )
{
T_8 V_201 = V_69 -> V_94 . V_197 . V_202 . V_203 . V_201 ;
return F_14 ( V_204 , & V_118 -> V_34 ) &&
( ( V_201 & F_130 ( V_205 ) ) ==
( F_130 ( V_206 <<
V_207 ) ) ) ;
}
static inline void F_131 ( struct V_57 * V_118 ,
union V_68 * V_69 ,
struct V_194 * V_89 )
{
F_132 ( V_89 ) ;
if ( ! ( V_118 -> V_55 -> V_195 & V_208 ) )
return;
if ( F_133 ( V_69 , V_209 ) &&
F_133 ( V_69 , V_210 ) ) {
V_118 -> V_211 . V_212 ++ ;
return;
}
if ( ! F_133 ( V_69 , V_213 ) )
return;
if ( F_133 ( V_69 , V_214 ) ) {
T_8 V_201 = V_69 -> V_94 . V_197 . V_202 . V_203 . V_201 ;
if ( ( V_201 & F_130 ( V_215 ) ) &&
F_14 ( V_216 , & V_118 -> V_34 ) )
return;
V_118 -> V_211 . V_212 ++ ;
return;
}
V_89 -> V_217 = V_218 ;
}
static inline void F_134 ( struct V_57 * V_67 , T_1 V_219 )
{
V_67 -> V_80 = V_219 ;
V_67 -> V_220 = V_219 ;
F_135 () ;
F_136 ( V_67 , V_219 ) ;
}
static bool F_137 ( struct V_57 * V_67 ,
struct V_70 * V_221 )
{
struct V_98 * V_98 = V_221 -> V_98 ;
T_9 V_81 = V_221 -> V_81 ;
if ( F_98 ( V_81 ) )
return true ;
if ( F_98 ( ! V_98 ) ) {
V_98 = F_138 ( V_222 | V_223 | V_224 ,
V_221 -> V_89 , F_139 ( V_67 ) ) ;
if ( F_24 ( ! V_98 ) ) {
V_67 -> V_211 . V_225 ++ ;
return false ;
}
V_221 -> V_98 = V_98 ;
}
V_81 = F_140 ( V_67 -> V_73 , V_98 , 0 ,
F_141 ( V_67 ) , V_226 ) ;
if ( F_142 ( V_67 -> V_73 , V_81 ) ) {
F_143 ( V_98 , F_139 ( V_67 ) ) ;
V_221 -> V_98 = NULL ;
V_67 -> V_211 . V_225 ++ ;
return false ;
}
V_221 -> V_81 = V_81 ;
V_221 -> V_99 = 0 ;
return true ;
}
void F_144 ( struct V_57 * V_67 , T_2 V_227 )
{
union V_68 * V_69 ;
struct V_70 * V_221 ;
T_2 V_48 = V_67 -> V_80 ;
if ( ! V_227 )
return;
V_69 = F_66 ( V_67 , V_48 ) ;
V_221 = & V_67 -> V_71 [ V_48 ] ;
V_48 -= V_67 -> V_88 ;
do {
if ( ! F_137 ( V_67 , V_221 ) )
break;
V_69 -> V_228 . V_229 = F_145 ( V_221 -> V_81 + V_221 -> V_99 ) ;
V_69 ++ ;
V_221 ++ ;
V_48 ++ ;
if ( F_24 ( ! V_48 ) ) {
V_69 = F_66 ( V_67 , 0 ) ;
V_221 = V_67 -> V_71 ;
V_48 -= V_67 -> V_88 ;
}
V_69 -> V_228 . V_230 = 0 ;
V_227 -- ;
} while ( V_227 );
V_48 += V_67 -> V_88 ;
if ( V_67 -> V_80 != V_48 )
F_134 ( V_67 , V_48 ) ;
}
static unsigned int F_146 ( unsigned char * V_92 ,
unsigned int V_231 )
{
union {
unsigned char * V_232 ;
struct V_233 * V_234 ;
struct V_235 * V_236 ;
struct V_237 * V_238 ;
struct V_239 * V_240 ;
} V_241 ;
T_10 V_242 ;
T_4 V_243 = 0 ;
T_4 V_244 ;
if ( V_231 < V_245 )
return V_231 ;
V_241 . V_232 = V_92 ;
V_242 = V_241 . V_234 -> V_246 ;
V_241 . V_232 += V_245 ;
if ( V_242 == F_147 ( V_247 ) ) {
if ( ( V_241 . V_232 - V_92 ) > ( V_231 - V_248 ) )
return V_231 ;
V_242 = V_241 . V_236 -> V_249 ;
V_241 . V_232 += V_248 ;
}
if ( V_242 == F_147 ( V_250 ) ) {
if ( ( V_241 . V_232 - V_92 ) > ( V_231 - sizeof( struct V_237 ) ) )
return V_231 ;
V_244 = ( V_241 . V_232 [ 0 ] & 0x0F ) << 2 ;
if ( V_244 < sizeof( struct V_237 ) )
return V_241 . V_232 - V_92 ;
if ( ! ( V_241 . V_238 -> V_251 & F_147 ( V_252 ) ) )
V_243 = V_241 . V_238 -> V_242 ;
} else if ( V_242 == F_147 ( V_253 ) ) {
if ( ( V_241 . V_232 - V_92 ) > ( V_231 - sizeof( struct V_239 ) ) )
return V_231 ;
V_243 = V_241 . V_240 -> V_243 ;
V_244 = sizeof( struct V_239 ) ;
#ifdef F_148
} else if ( V_242 == F_147 ( V_254 ) ) {
if ( ( V_241 . V_232 - V_92 ) > ( V_231 - V_255 ) )
return V_231 ;
V_244 = V_255 ;
#endif
} else {
return V_241 . V_232 - V_92 ;
}
V_241 . V_232 += V_244 ;
if ( V_243 == V_256 ) {
if ( ( V_241 . V_232 - V_92 ) > ( V_231 - sizeof( struct V_257 ) ) )
return V_231 ;
V_244 = ( V_241 . V_232 [ 12 ] & 0xF0 ) >> 2 ;
if ( V_244 < sizeof( struct V_257 ) )
return V_241 . V_232 - V_92 ;
V_241 . V_232 += V_244 ;
} else if ( V_243 == V_258 ) {
if ( ( V_241 . V_232 - V_92 ) > ( V_231 - sizeof( struct V_259 ) ) )
return V_231 ;
V_241 . V_232 += sizeof( struct V_259 ) ;
}
if ( ( V_241 . V_232 - V_92 ) < V_231 )
return V_241 . V_232 - V_92 ;
else
return V_231 ;
}
static void F_149 ( struct V_57 * V_118 ,
struct V_194 * V_89 )
{
T_2 V_260 = F_150 ( V_89 ) ;
F_151 ( V_89 ) -> V_261 = F_152 ( ( V_89 -> V_82 - V_260 ) ,
F_153 ( V_89 ) -> V_262 ) ;
F_151 ( V_89 ) -> V_263 = V_264 ;
}
static void F_154 ( struct V_57 * V_67 ,
struct V_194 * V_89 )
{
if ( ! F_153 ( V_89 ) -> V_262 )
return;
V_67 -> V_211 . V_265 += F_153 ( V_89 ) -> V_262 ;
V_67 -> V_211 . V_266 ++ ;
F_149 ( V_67 , V_89 ) ;
F_153 ( V_89 ) -> V_262 = 0 ;
}
static void F_155 ( struct V_57 * V_67 ,
union V_68 * V_69 ,
struct V_194 * V_89 )
{
struct V_54 * V_73 = V_67 -> V_55 ;
F_154 ( V_67 , V_89 ) ;
F_127 ( V_67 , V_69 , V_89 ) ;
F_131 ( V_67 , V_69 , V_89 ) ;
if ( F_24 ( F_133 ( V_69 , V_267 ) ) )
F_156 ( V_67 -> V_157 -> V_2 , V_89 ) ;
if ( ( V_73 -> V_195 & V_268 ) &&
F_133 ( V_69 , V_269 ) ) {
T_2 V_270 = F_157 ( V_69 -> V_94 . V_95 . V_236 ) ;
F_158 ( V_89 , F_147 ( V_247 ) , V_270 ) ;
}
F_159 ( V_89 , V_67 -> V_86 ) ;
V_89 -> V_242 = F_160 ( V_89 , V_73 ) ;
}
static void F_161 ( struct V_156 * V_157 ,
struct V_194 * V_89 )
{
struct V_1 * V_2 = V_157 -> V_2 ;
if ( F_162 ( V_157 ) )
F_163 ( V_89 ) ;
else if ( ! ( V_2 -> V_137 & V_271 ) )
F_164 ( & V_157 -> V_272 , V_89 ) ;
else
F_165 ( V_89 ) ;
}
static bool F_166 ( struct V_57 * V_67 ,
union V_68 * V_69 ,
struct V_194 * V_89 )
{
T_1 V_273 = V_67 -> V_79 + 1 ;
V_273 = ( V_273 < V_67 -> V_88 ) ? V_273 : 0 ;
V_67 -> V_79 = V_273 ;
F_97 ( F_66 ( V_67 , V_273 ) ) ;
if ( F_167 ( V_67 ) ) {
T_11 V_274 = V_69 -> V_94 . V_197 . V_202 . V_92 &
F_96 ( V_275 ) ;
if ( F_24 ( V_274 ) ) {
T_1 V_276 = F_67 ( V_274 ) ;
V_276 >>= V_277 ;
F_153 ( V_89 ) -> V_262 += V_276 - 1 ;
V_273 = F_67 ( V_69 -> V_94 . V_95 . V_96 ) ;
V_273 &= V_278 ;
V_273 >>= V_279 ;
}
}
if ( F_98 ( F_133 ( V_69 , V_280 ) ) )
return false ;
V_67 -> V_71 [ V_273 ] . V_89 = V_89 ;
V_67 -> V_211 . V_281 ++ ;
return true ;
}
static void F_168 ( struct V_57 * V_67 ,
struct V_194 * V_89 )
{
struct V_282 * V_283 = & F_151 ( V_89 ) -> V_284 [ 0 ] ;
unsigned char * V_285 ;
unsigned int V_286 ;
V_285 = F_169 ( V_283 ) ;
V_286 = F_146 ( V_285 , V_287 ) ;
F_170 ( V_89 , V_285 , F_171 ( V_286 , sizeof( long ) ) ) ;
F_172 ( V_283 , V_286 ) ;
V_283 -> V_99 += V_286 ;
V_89 -> V_288 -= V_286 ;
V_89 -> V_144 += V_286 ;
}
static void F_173 ( struct V_57 * V_67 ,
struct V_194 * V_89 )
{
if ( F_24 ( F_153 ( V_89 ) -> V_289 ) ) {
F_80 ( V_67 -> V_73 , F_153 ( V_89 ) -> V_81 ,
F_141 ( V_67 ) , V_226 ) ;
F_153 ( V_89 ) -> V_289 = false ;
} else {
struct V_282 * V_283 = & F_151 ( V_89 ) -> V_284 [ 0 ] ;
F_174 ( V_67 -> V_73 ,
F_153 ( V_89 ) -> V_81 ,
V_283 -> V_99 ,
F_69 ( V_67 ) ,
V_226 ) ;
}
F_153 ( V_89 ) -> V_81 = 0 ;
}
static bool F_175 ( struct V_57 * V_67 ,
union V_68 * V_69 ,
struct V_194 * V_89 )
{
struct V_54 * V_55 = V_67 -> V_55 ;
if ( F_24 ( F_133 ( V_69 ,
V_290 ) &&
! ( V_55 -> V_195 & V_291 ) ) ) {
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
int V_292 = 60 - V_89 -> V_82 ;
if ( F_177 ( V_89 , V_292 ) )
return true ;
F_178 ( V_89 , V_292 ) ;
}
return false ;
}
static void F_179 ( struct V_57 * V_67 ,
struct V_70 * V_293 )
{
struct V_70 * V_294 ;
T_2 V_295 = V_67 -> V_220 ;
V_294 = & V_67 -> V_71 [ V_295 ] ;
V_295 ++ ;
V_67 -> V_220 = ( V_295 < V_67 -> V_88 ) ? V_295 : 0 ;
V_294 -> V_98 = V_293 -> V_98 ;
V_294 -> V_81 = V_293 -> V_81 ;
V_294 -> V_99 = V_293 -> V_99 ;
F_180 ( V_67 -> V_73 , V_294 -> V_81 ,
V_294 -> V_99 ,
F_69 ( V_67 ) ,
V_226 ) ;
}
static bool F_181 ( struct V_57 * V_67 ,
struct V_70 * V_296 ,
union V_68 * V_69 ,
struct V_194 * V_89 )
{
struct V_98 * V_98 = V_296 -> V_98 ;
unsigned int V_297 = F_157 ( V_69 -> V_94 . V_95 . V_298 ) ;
#if ( V_299 < 8192 )
unsigned int V_300 = F_69 ( V_67 ) ;
#else
unsigned int V_300 = F_171 ( V_297 , V_301 ) ;
unsigned int V_302 = F_141 ( V_67 ) -
F_69 ( V_67 ) ;
#endif
if ( ( V_297 <= V_287 ) && ! F_176 ( V_89 ) ) {
unsigned char * V_285 = F_68 ( V_98 ) + V_296 -> V_99 ;
memcpy ( F_178 ( V_89 , V_297 ) , V_285 , F_171 ( V_297 , sizeof( long ) ) ) ;
if ( F_98 ( F_182 ( V_98 ) == F_183 () ) )
return true ;
F_184 ( V_98 ) ;
return false ;
}
F_185 ( V_89 , F_151 ( V_89 ) -> V_303 , V_98 ,
V_296 -> V_99 , V_297 , V_300 ) ;
if ( F_24 ( F_182 ( V_98 ) != F_183 () ) )
return false ;
#if ( V_299 < 8192 )
if ( F_24 ( F_186 ( V_98 ) != 1 ) )
return false ;
V_296 -> V_99 ^= V_300 ;
F_187 ( & V_98 -> V_304 , 2 ) ;
#else
V_296 -> V_99 += V_300 ;
if ( V_296 -> V_99 > V_302 )
return false ;
F_188 ( V_98 ) ;
#endif
return true ;
}
static struct V_194 * F_189 ( struct V_57 * V_67 ,
union V_68 * V_69 )
{
struct V_70 * V_296 ;
struct V_194 * V_89 ;
struct V_98 * V_98 ;
V_296 = & V_67 -> V_71 [ V_67 -> V_79 ] ;
V_98 = V_296 -> V_98 ;
F_190 ( V_98 ) ;
V_89 = V_296 -> V_89 ;
if ( F_98 ( ! V_89 ) ) {
void * V_305 = F_68 ( V_98 ) +
V_296 -> V_99 ;
F_97 ( V_305 ) ;
#if V_301 < 128
F_97 ( V_305 + V_301 ) ;
#endif
V_89 = F_191 ( V_67 -> V_55 ,
V_287 ) ;
if ( F_24 ( ! V_89 ) ) {
V_67 -> V_211 . V_306 ++ ;
return NULL ;
}
F_190 ( V_89 -> V_92 ) ;
if ( F_98 ( F_133 ( V_69 , V_280 ) ) )
goto V_307;
F_153 ( V_89 ) -> V_81 = V_296 -> V_81 ;
} else {
if ( F_133 ( V_69 , V_280 ) )
F_173 ( V_67 , V_89 ) ;
V_307:
F_174 ( V_67 -> V_73 ,
V_296 -> V_81 ,
V_296 -> V_99 ,
F_69 ( V_67 ) ,
V_226 ) ;
}
if ( F_181 ( V_67 , V_296 , V_69 , V_89 ) ) {
F_179 ( V_67 , V_296 ) ;
} else if ( F_153 ( V_89 ) -> V_81 == V_296 -> V_81 ) {
F_153 ( V_89 ) -> V_289 = true ;
} else {
F_80 ( V_67 -> V_73 , V_296 -> V_81 ,
F_141 ( V_67 ) ,
V_226 ) ;
}
V_296 -> V_89 = NULL ;
V_296 -> V_81 = 0 ;
V_296 -> V_98 = NULL ;
return V_89 ;
}
static int F_192 ( struct V_156 * V_157 ,
struct V_57 * V_67 ,
const int V_160 )
{
unsigned int V_308 = 0 , V_309 = 0 ;
#ifdef F_148
struct V_1 * V_2 = V_157 -> V_2 ;
int V_310 ;
unsigned int V_311 = 0 ;
#endif
T_2 V_227 = F_109 ( V_67 ) ;
while ( F_98 ( V_309 < V_160 ) ) {
union V_68 * V_69 ;
struct V_194 * V_89 ;
if ( V_227 >= V_312 ) {
F_144 ( V_67 , V_227 ) ;
V_227 = 0 ;
}
V_69 = F_66 ( V_67 , V_67 -> V_79 ) ;
if ( ! F_133 ( V_69 , V_97 ) )
break;
F_193 () ;
V_89 = F_189 ( V_67 , V_69 ) ;
if ( ! V_89 )
break;
V_227 ++ ;
if ( F_166 ( V_67 , V_69 , V_89 ) )
continue;
if ( F_175 ( V_67 , V_69 , V_89 ) )
continue;
V_308 += V_89 -> V_82 ;
F_155 ( V_67 , V_69 , V_89 ) ;
#ifdef F_148
if ( F_129 ( V_67 , V_69 ) ) {
V_310 = F_194 ( V_2 , V_69 , V_89 ) ;
if ( V_310 > 0 ) {
if ( ! V_311 ) {
V_311 = V_67 -> V_55 -> V_313 -
sizeof( struct V_314 ) -
sizeof( struct V_315 ) -
sizeof( struct V_316 ) ;
if ( V_311 > 512 )
V_311 &= ~ 511 ;
}
V_308 += V_310 ;
V_309 += F_152 ( V_310 ,
V_311 ) ;
}
if ( ! V_310 ) {
F_78 ( V_89 ) ;
continue;
}
}
#endif
F_195 ( V_89 , & V_157 -> V_272 ) ;
F_161 ( V_157 , V_89 ) ;
V_309 ++ ;
}
F_99 ( & V_67 -> V_168 ) ;
V_67 -> V_122 . V_142 += V_309 ;
V_67 -> V_122 . V_169 += V_308 ;
F_100 ( & V_67 -> V_168 ) ;
V_157 -> V_317 . V_159 += V_309 ;
V_157 -> V_317 . V_158 += V_308 ;
if ( V_227 )
F_144 ( V_67 , V_227 ) ;
return V_309 ;
}
static int F_196 ( struct V_318 * V_272 )
{
struct V_156 * V_157 =
F_197 ( V_272 , struct V_156 , V_272 ) ;
struct V_1 * V_2 = V_157 -> V_2 ;
struct V_57 * V_118 ;
int V_319 = 0 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return V_320 ;
if ( ! F_198 ( V_157 ) )
return V_321 ;
F_120 (ring, q_vector->rx) {
V_319 = F_192 ( V_157 , V_118 , 4 ) ;
#ifdef F_199
if ( V_319 )
V_118 -> V_122 . V_322 += V_319 ;
else
V_118 -> V_122 . V_323 ++ ;
#endif
if ( V_319 )
break;
}
F_200 ( V_157 ) ;
return V_319 ;
}
static void F_201 ( struct V_1 * V_2 )
{
struct V_156 * V_157 ;
int V_324 ;
T_1 V_115 ;
if ( V_2 -> V_325 > 32 ) {
T_1 V_326 = ( 1 << ( V_2 -> V_325 - 32 ) ) - 1 ;
F_71 ( & V_2 -> V_14 , V_327 , V_326 ) ;
}
for ( V_324 = 0 ; V_324 < V_2 -> V_188 ; V_324 ++ ) {
struct V_57 * V_118 ;
V_157 = V_2 -> V_157 [ V_324 ] ;
F_120 (ring, q_vector->rx)
F_73 ( V_2 , 0 , V_118 -> V_147 , V_324 ) ;
F_120 (ring, q_vector->tx)
F_73 ( V_2 , 1 , V_118 -> V_147 , V_324 ) ;
F_202 ( V_157 ) ;
}
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
F_73 ( V_2 , - 1 , V_328 ,
V_324 ) ;
break;
case V_111 :
case V_112 :
F_73 ( V_2 , - 1 , 1 , V_324 ) ;
break;
default:
break;
}
F_71 ( & V_2 -> V_14 , F_203 ( V_324 ) , 1950 ) ;
V_115 = V_329 ;
V_115 &= ~ ( V_330 |
V_331 |
V_332 ) ;
F_71 ( & V_2 -> V_14 , V_333 , V_115 ) ;
}
static void F_204 ( struct V_156 * V_157 ,
struct V_334 * V_335 )
{
int V_169 = V_335 -> V_158 ;
int V_142 = V_335 -> V_159 ;
T_1 V_336 ;
T_6 V_337 ;
T_4 V_338 = V_335 -> V_339 ;
if ( V_142 == 0 )
return;
V_336 = V_157 -> V_339 >> 2 ;
if ( V_336 == 0 )
return;
V_337 = V_169 / V_336 ;
switch ( V_338 ) {
case V_340 :
if ( V_337 > 10 )
V_338 = V_341 ;
break;
case V_341 :
if ( V_337 > 20 )
V_338 = V_342 ;
else if ( V_337 <= 10 )
V_338 = V_340 ;
break;
case V_342 :
if ( V_337 <= 20 )
V_338 = V_341 ;
break;
}
V_335 -> V_158 = 0 ;
V_335 -> V_159 = 0 ;
V_335 -> V_339 = V_338 ;
}
void F_202 ( struct V_156 * V_157 )
{
struct V_1 * V_2 = V_157 -> V_2 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_324 = V_157 -> V_324 ;
T_1 V_343 = V_157 -> V_339 & V_344 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
V_343 |= ( V_343 << 16 ) ;
break;
case V_111 :
case V_112 :
V_343 |= V_345 ;
break;
default:
break;
}
F_71 ( V_14 , F_203 ( V_324 ) , V_343 ) ;
}
static void F_205 ( struct V_156 * V_157 )
{
T_1 V_346 = V_157 -> V_339 ;
T_4 V_347 ;
F_204 ( V_157 , & V_157 -> V_161 ) ;
F_204 ( V_157 , & V_157 -> V_317 ) ;
V_347 = F_206 ( V_157 -> V_317 . V_339 , V_157 -> V_161 . V_339 ) ;
switch ( V_347 ) {
case V_340 :
V_346 = V_348 ;
break;
case V_341 :
V_346 = V_349 ;
break;
case V_342 :
V_346 = V_350 ;
break;
default:
break;
}
if ( V_346 != V_157 -> V_339 ) {
V_346 = ( 10 * V_346 * V_157 -> V_339 ) /
( ( 9 * V_346 ) + V_157 -> V_339 ) ;
V_157 -> V_339 = V_346 ;
F_202 ( V_157 ) ;
}
}
static void F_207 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_351 = V_2 -> V_352 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
if ( ! ( V_2 -> V_153 & V_353 ) &&
! ( V_2 -> V_153 & V_354 ) )
return;
V_2 -> V_153 &= ~ V_354 ;
switch ( V_14 -> V_21 ) {
case V_355 :
if ( ! ( V_351 & V_356 ) &&
! ( V_351 & V_357 ) )
return;
if ( ! ( V_351 & V_357 ) && V_14 -> V_108 . V_358 . V_359 ) {
T_1 V_20 ;
bool V_360 = false ;
V_14 -> V_108 . V_358 . V_359 ( V_14 , & V_20 , & V_360 , false ) ;
if ( V_360 )
return;
}
if ( V_14 -> V_361 . V_358 . V_362 ( V_14 ) != V_363 )
return;
break;
default:
if ( ! ( V_351 & V_356 ) )
return;
break;
}
F_208 ( V_155 ,
L_70
L_71
L_72 ) ;
V_2 -> V_352 = 0 ;
}
static void F_209 ( struct V_1 * V_2 , T_1 V_351 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ( V_2 -> V_137 & V_364 ) &&
( V_351 & V_365 ) ) {
F_208 ( V_171 , L_73 ) ;
F_71 ( V_14 , V_366 , V_365 ) ;
}
}
static void F_210 ( struct V_1 * V_2 , T_1 V_351 )
{
if ( ! ( V_2 -> V_153 & V_353 ) )
return;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
if ( ( ( V_351 & V_356 ) || ( V_351 & V_357 ) ) &&
( ! F_14 ( V_33 , & V_2 -> V_34 ) ) ) {
V_2 -> V_352 = V_351 ;
V_2 -> V_153 |= V_354 ;
F_13 ( V_2 ) ;
return;
}
return;
case V_112 :
if ( ! ( V_351 & V_367 ) )
return;
break;
default:
return;
}
F_208 ( V_155 ,
L_70
L_71
L_72 ) ;
}
static void F_211 ( struct V_1 * V_2 , T_1 V_351 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_351 & V_368 ) {
F_71 ( V_14 , V_366 , V_368 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_153 |= V_369 ;
F_13 ( V_2 ) ;
}
}
if ( V_351 & V_365 ) {
F_71 ( V_14 , V_366 , V_365 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_137 |= V_370 ;
F_13 ( V_2 ) ;
}
}
}
static void F_212 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_371 ++ ;
V_2 -> V_137 |= V_372 ;
V_2 -> V_373 = V_170 ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
F_71 ( V_14 , V_374 , V_375 ) ;
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
F_71 ( V_14 , V_376 , V_115 ) ;
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
F_71 ( V_14 , V_374 , V_115 ) ;
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
static inline void F_218 ( struct V_1 * V_2 , bool V_377 ,
bool V_378 )
{
T_1 V_115 = ( V_329 & ~ V_116 ) ;
if ( V_2 -> V_137 & V_372 )
V_115 &= ~ V_332 ;
if ( V_2 -> V_153 & V_353 )
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_115 |= V_379 ;
break;
case V_112 :
V_115 |= V_380 ;
break;
default:
break;
}
if ( V_2 -> V_137 & V_364 )
V_115 |= V_381 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_115 |= V_381 ;
V_115 |= V_382 ;
case V_112 :
V_115 |= V_383 ;
V_115 |= V_331 ;
break;
default:
break;
}
if ( V_2 -> V_14 . V_108 . type == V_112 )
V_115 |= V_384 ;
if ( ( V_2 -> V_137 & V_385 ) &&
! ( V_2 -> V_153 & V_386 ) )
V_115 |= V_387 ;
F_71 ( & V_2 -> V_14 , V_376 , V_115 ) ;
if ( V_377 )
F_214 ( V_2 , ~ 0 ) ;
if ( V_378 )
F_213 ( & V_2 -> V_14 ) ;
}
static T_12 F_219 ( int V_388 , void * V_92 )
{
struct V_1 * V_2 = V_92 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_351 ;
V_351 = F_37 ( V_14 , V_117 ) ;
V_351 &= 0xFFFF0000 ;
F_71 ( V_14 , V_366 , V_351 ) ;
if ( V_351 & V_357 )
F_212 ( V_2 ) ;
if ( V_351 & V_389 )
F_220 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
if ( V_351 & V_390 ) {
F_104 ( V_391 , L_74 ) ;
V_2 -> V_153 |= V_154 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_366 , V_390 ) ;
}
if ( V_351 & V_392 ) {
int V_393 = 0 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_118 = V_2 -> V_58 [ V_48 ] ;
if ( F_221 ( V_394 ,
& V_118 -> V_34 ) )
V_393 ++ ;
}
if ( V_393 ) {
F_71 ( V_14 , V_374 , V_395 ) ;
V_2 -> V_153 |= V_386 ;
F_13 ( V_2 ) ;
}
}
F_211 ( V_2 , V_351 ) ;
F_210 ( V_2 , V_351 ) ;
break;
default:
break;
}
F_209 ( V_2 , V_351 ) ;
if ( F_24 ( V_351 & V_396 ) )
F_222 ( V_2 , V_351 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_218 ( V_2 , false , false ) ;
return V_397 ;
}
static T_12 F_223 ( int V_388 , void * V_92 )
{
struct V_156 * V_157 = V_92 ;
if ( V_157 -> V_317 . V_118 || V_157 -> V_161 . V_118 )
F_224 ( & V_157 -> V_272 ) ;
return V_397 ;
}
int F_225 ( struct V_318 * V_272 , int V_160 )
{
struct V_156 * V_157 =
F_197 ( V_272 , struct V_156 , V_272 ) ;
struct V_1 * V_2 = V_157 -> V_2 ;
struct V_57 * V_118 ;
int V_398 ;
bool V_399 = true ;
#ifdef F_226
if ( V_2 -> V_137 & V_186 )
F_118 ( V_157 ) ;
#endif
F_120 (ring, q_vector->tx)
V_399 &= ! ! F_94 ( V_157 , V_118 ) ;
if ( ! F_227 ( V_157 ) )
return V_160 ;
if ( V_157 -> V_317 . V_88 > 1 )
V_398 = F_206 ( V_160 / V_157 -> V_317 . V_88 , 1 ) ;
else
V_398 = V_160 ;
F_120 (ring, q_vector->rx)
V_399 &= ( F_192 ( V_157 , V_118 ,
V_398 ) < V_398 ) ;
F_228 ( V_157 ) ;
if ( ! V_399 )
return V_160 ;
F_229 ( V_272 ) ;
if ( V_2 -> V_400 & 1 )
F_205 ( V_157 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_214 ( V_2 , ( ( T_6 ) 1 << V_157 -> V_324 ) ) ;
return 0 ;
}
static int F_230 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
int V_401 , V_17 ;
int V_402 = 0 , V_403 = 0 ;
for ( V_401 = 0 ; V_401 < V_2 -> V_188 ; V_401 ++ ) {
struct V_156 * V_157 = V_2 -> V_157 [ V_401 ] ;
struct V_404 * V_405 = & V_2 -> V_406 [ V_401 ] ;
if ( V_157 -> V_161 . V_118 && V_157 -> V_317 . V_118 ) {
snprintf ( V_157 -> V_53 , sizeof( V_157 -> V_53 ) - 1 ,
L_75 , V_55 -> V_53 , L_76 , V_402 ++ ) ;
V_403 ++ ;
} else if ( V_157 -> V_317 . V_118 ) {
snprintf ( V_157 -> V_53 , sizeof( V_157 -> V_53 ) - 1 ,
L_75 , V_55 -> V_53 , L_77 , V_402 ++ ) ;
} else if ( V_157 -> V_161 . V_118 ) {
snprintf ( V_157 -> V_53 , sizeof( V_157 -> V_53 ) - 1 ,
L_75 , V_55 -> V_53 , L_78 , V_403 ++ ) ;
} else {
continue;
}
V_17 = F_231 ( V_405 -> V_401 , & F_223 , 0 ,
V_157 -> V_53 , V_157 ) ;
if ( V_17 ) {
F_102 ( V_171 , L_79
L_80 , V_17 ) ;
goto V_407;
}
if ( V_2 -> V_137 & V_385 ) {
F_232 ( V_405 -> V_401 ,
& V_157 -> V_408 ) ;
}
}
V_17 = F_231 ( V_2 -> V_406 [ V_401 ] . V_401 ,
F_219 , 0 , V_55 -> V_53 , V_2 ) ;
if ( V_17 ) {
F_102 ( V_171 , L_81 , V_17 ) ;
goto V_407;
}
return 0 ;
V_407:
while ( V_401 ) {
V_401 -- ;
F_232 ( V_2 -> V_406 [ V_401 ] . V_401 ,
NULL ) ;
F_233 ( V_2 -> V_406 [ V_401 ] . V_401 ,
V_2 -> V_157 [ V_401 ] ) ;
}
V_2 -> V_137 &= ~ V_409 ;
F_234 ( V_2 -> V_9 ) ;
F_235 ( V_2 -> V_406 ) ;
V_2 -> V_406 = NULL ;
return V_17 ;
}
static T_12 F_236 ( int V_388 , void * V_92 )
{
struct V_1 * V_2 = V_92 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_156 * V_157 = V_2 -> V_157 [ 0 ] ;
T_1 V_351 ;
F_71 ( V_14 , V_374 , V_410 ) ;
V_351 = F_37 ( V_14 , V_366 ) ;
if ( ! V_351 ) {
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_218 ( V_2 , true , true ) ;
return V_411 ;
}
if ( V_351 & V_357 )
F_212 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_111 :
F_211 ( V_2 , V_351 ) ;
case V_112 :
if ( V_351 & V_390 ) {
F_104 ( V_391 , L_74 ) ;
V_2 -> V_153 |= V_154 ;
F_13 ( V_2 ) ;
F_71 ( V_14 , V_366 , V_390 ) ;
}
F_210 ( V_2 , V_351 ) ;
break;
default:
break;
}
F_209 ( V_2 , V_351 ) ;
if ( F_24 ( V_351 & V_396 ) )
F_222 ( V_2 , V_351 ) ;
F_224 ( & V_157 -> V_272 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_218 ( V_2 , false , false ) ;
return V_397 ;
}
static int F_237 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
int V_17 ;
if ( V_2 -> V_137 & V_409 )
V_17 = F_230 ( V_2 ) ;
else if ( V_2 -> V_137 & V_412 )
V_17 = F_231 ( V_2 -> V_9 -> V_388 , F_236 , 0 ,
V_55 -> V_53 , V_2 ) ;
else
V_17 = F_231 ( V_2 -> V_9 -> V_388 , F_236 , V_413 ,
V_55 -> V_53 , V_2 ) ;
if ( V_17 )
F_102 ( V_171 , L_82 , V_17 ) ;
return V_17 ;
}
static void F_238 ( struct V_1 * V_2 )
{
int V_401 ;
if ( ! ( V_2 -> V_137 & V_409 ) ) {
F_233 ( V_2 -> V_9 -> V_388 , V_2 ) ;
return;
}
for ( V_401 = 0 ; V_401 < V_2 -> V_188 ; V_401 ++ ) {
struct V_156 * V_157 = V_2 -> V_157 [ V_401 ] ;
struct V_404 * V_405 = & V_2 -> V_406 [ V_401 ] ;
if ( ! V_157 -> V_317 . V_118 && ! V_157 -> V_161 . V_118 )
continue;
F_232 ( V_405 -> V_401 , NULL ) ;
F_233 ( V_405 -> V_401 , V_157 ) ;
}
F_233 ( V_2 -> V_406 [ V_401 ++ ] . V_401 , V_2 ) ;
}
static inline void F_239 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_108 . type ) {
case V_109 :
F_71 ( & V_2 -> V_14 , V_374 , ~ 0 ) ;
break;
case V_111 :
case V_112 :
F_71 ( & V_2 -> V_14 , V_374 , 0xFFFF0000 ) ;
F_71 ( & V_2 -> V_14 , F_217 ( 0 ) , ~ 0 ) ;
F_71 ( & V_2 -> V_14 , F_217 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_213 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_137 & V_409 ) {
int V_401 ;
for ( V_401 = 0 ; V_401 < V_2 -> V_188 ; V_401 ++ )
F_240 ( V_2 -> V_406 [ V_401 ] . V_401 ) ;
F_240 ( V_2 -> V_406 [ V_401 ++ ] . V_401 ) ;
} else {
F_240 ( V_2 -> V_9 -> V_388 ) ;
}
}
static void F_241 ( struct V_1 * V_2 )
{
struct V_156 * V_157 = V_2 -> V_157 [ 0 ] ;
F_202 ( V_157 ) ;
F_73 ( V_2 , 0 , 0 , 0 ) ;
F_73 ( V_2 , 1 , 0 , 0 ) ;
F_104 ( V_14 , L_83 ) ;
}
void F_242 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_414 = V_118 -> V_81 ;
int V_415 = 10 ;
T_1 V_416 = V_417 ;
T_4 V_147 = V_118 -> V_147 ;
F_71 ( V_14 , F_50 ( V_147 ) , 0 ) ;
F_213 ( V_14 ) ;
F_71 ( V_14 , F_45 ( V_147 ) ,
( V_414 & F_243 ( 32 ) ) ) ;
F_71 ( V_14 , F_46 ( V_147 ) , ( V_414 >> 32 ) ) ;
F_71 ( V_14 , F_47 ( V_147 ) ,
V_118 -> V_88 * sizeof( union V_61 ) ) ;
F_71 ( V_14 , F_48 ( V_147 ) , 0 ) ;
F_71 ( V_14 , F_49 ( V_147 ) , 0 ) ;
V_118 -> V_144 = V_2 -> V_418 + F_49 ( V_147 ) ;
#if F_244 ( V_419 )
if ( ! V_118 -> V_157 || ( V_118 -> V_157 -> V_339 < V_348 ) )
#else
if ( ! V_118 -> V_157 || ( V_118 -> V_157 -> V_339 < 8 ) )
#endif
V_416 |= ( 1 << 16 ) ;
else
V_416 |= ( 8 << 16 ) ;
V_416 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_137 & V_385 ) {
V_118 -> V_420 = V_2 -> V_420 ;
V_118 -> V_421 = 0 ;
F_245 ( V_394 , & V_118 -> V_34 ) ;
} else {
V_118 -> V_420 = 0 ;
}
if ( ! F_15 ( V_422 , & V_118 -> V_34 ) ) {
struct V_156 * V_157 = V_118 -> V_157 ;
if ( V_157 )
F_246 ( V_118 -> V_55 ,
& V_157 -> V_408 ,
V_118 -> V_86 ) ;
}
F_34 ( V_130 , & V_118 -> V_34 ) ;
F_71 ( V_14 , F_50 ( V_147 ) , V_416 ) ;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_423 ) & V_424 ) )
return;
do {
F_247 ( 1000 , 2000 ) ;
V_416 = F_37 ( V_14 , F_50 ( V_147 ) ) ;
} while ( -- V_415 && ! ( V_416 & V_417 ) );
if ( ! V_415 )
F_102 ( V_155 , L_84 , V_147 ) ;
}
static void F_248 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_425 , V_426 ;
T_4 V_427 = F_249 ( V_2 -> V_55 ) ;
if ( V_14 -> V_108 . type == V_109 )
return;
V_425 = F_37 ( V_14 , V_428 ) ;
V_425 |= V_429 ;
F_71 ( V_14 , V_428 , V_425 ) ;
if ( V_2 -> V_137 & V_430 ) {
V_426 = V_431 ;
if ( V_427 > 4 )
V_426 |= V_432 | V_433 ;
else if ( V_427 > 1 )
V_426 |= V_432 | V_434 ;
else if ( V_2 -> V_435 [ V_436 ] . V_437 == 4 )
V_426 |= V_438 ;
else
V_426 |= V_439 ;
} else {
if ( V_427 > 4 )
V_426 = V_432 | V_433 ;
else if ( V_427 > 1 )
V_426 = V_432 | V_434 ;
else
V_426 = V_440 ;
}
F_71 ( V_14 , V_441 , V_426 ) ;
if ( V_427 ) {
T_1 V_442 = F_37 ( V_14 , V_443 ) ;
V_442 |= V_444 ;
F_71 ( V_14 , V_443 , V_442 ) ;
}
V_425 &= ~ V_429 ;
F_71 ( V_14 , V_428 , V_425 ) ;
}
static void F_250 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_445 ;
T_1 V_48 ;
F_248 ( V_2 ) ;
if ( V_14 -> V_108 . type != V_109 ) {
V_445 = F_37 ( V_14 , V_446 ) ;
V_445 |= V_447 ;
F_71 ( V_14 , V_446 , V_445 ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_242 ( V_2 , V_2 -> V_58 [ V_48 ] ) ;
}
static void F_251 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_147 = V_118 -> V_147 ;
T_1 V_448 = F_37 ( V_14 , F_36 ( V_147 ) ) ;
V_448 |= V_449 ;
F_71 ( V_14 , F_36 ( V_147 ) , V_448 ) ;
}
static void F_252 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_147 = V_118 -> V_147 ;
T_1 V_448 = F_37 ( V_14 , F_36 ( V_147 ) ) ;
V_448 &= ~ V_449 ;
F_71 ( V_14 , F_36 ( V_147 ) , V_448 ) ;
}
static void F_253 ( struct V_1 * V_2 ,
struct V_57 * V_67 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_448 ;
T_4 V_147 = V_67 -> V_147 ;
if ( V_14 -> V_108 . type == V_109 ) {
T_2 V_115 = V_2 -> V_435 [ V_436 ] . V_115 ;
V_147 &= V_115 ;
}
V_448 = V_287 << V_450 ;
V_448 |= F_69 ( V_67 ) >> V_451 ;
V_448 |= V_452 ;
F_71 ( V_14 , F_36 ( V_147 ) , V_448 ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
static const T_1 V_453 [ 10 ] = { 0xE291D73D , 0x1805EC6C , 0x2A94B30D ,
0xA54F2BEC , 0xEA49AF7C , 0xE214AD3D , 0xB855AABE ,
0x6A3E67EA , 0x14364D17 , 0x3BED200D } ;
T_1 V_454 = 0 , V_455 = 0 ;
T_1 V_456 ;
int V_48 , V_49 ;
T_2 V_457 = V_2 -> V_435 [ V_436 ] . V_437 ;
if ( ( V_2 -> V_137 & V_430 ) && ( V_457 < 2 ) )
V_457 = 2 ;
for ( V_48 = 0 ; V_48 < 10 ; V_48 ++ )
F_71 ( V_14 , F_255 ( V_48 ) , V_453 [ V_48 ] ) ;
for ( V_48 = 0 , V_49 = 0 ; V_48 < 128 ; V_48 ++ , V_49 ++ ) {
if ( V_49 == V_457 )
V_49 = 0 ;
V_455 = ( V_455 << 8 ) | ( V_49 * 0x11 ) ;
if ( ( V_48 & 3 ) == 3 )
F_71 ( V_14 , F_256 ( V_48 >> 2 ) , V_455 ) ;
}
V_456 = F_37 ( V_14 , V_458 ) ;
V_456 |= V_459 ;
F_71 ( V_14 , V_458 , V_456 ) ;
if ( V_2 -> V_14 . V_108 . type == V_109 ) {
if ( V_2 -> V_435 [ V_436 ] . V_115 )
V_454 = V_460 ;
} else {
T_4 V_427 = F_249 ( V_2 -> V_55 ) ;
if ( V_2 -> V_137 & V_430 ) {
if ( V_427 > 4 )
V_454 = V_461 ;
else if ( V_427 > 1 )
V_454 = V_462 ;
else if ( V_2 -> V_435 [ V_436 ] . V_437 == 4 )
V_454 = V_463 ;
else
V_454 = V_464 ;
} else {
if ( V_427 > 4 )
V_454 = V_465 ;
else if ( V_427 > 1 )
V_454 = V_466 ;
else
V_454 = V_460 ;
}
}
V_454 |= V_467 |
V_468 |
V_469 |
V_470 ;
if ( V_2 -> V_153 & V_471 )
V_454 |= V_472 ;
if ( V_2 -> V_153 & V_473 )
V_454 |= V_474 ;
F_71 ( V_14 , V_475 , V_454 ) ;
}
static void F_257 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_476 ;
T_4 V_147 = V_118 -> V_147 ;
if ( ! F_167 ( V_118 ) )
return;
V_476 = F_37 ( V_14 , F_258 ( V_147 ) ) ;
V_476 |= V_477 ;
V_476 |= V_478 ;
F_71 ( V_14 , F_258 ( V_147 ) , V_476 ) ;
}
static void F_259 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_415 = V_479 ;
T_1 V_480 ;
T_4 V_147 = V_118 -> V_147 ;
if ( F_22 ( V_14 -> V_39 ) )
return;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_423 ) & V_424 ) )
return;
do {
F_247 ( 1000 , 2000 ) ;
V_480 = F_37 ( V_14 , F_42 ( V_147 ) ) ;
} while ( -- V_415 && ! ( V_480 & V_481 ) );
if ( ! V_415 ) {
F_102 ( V_155 , L_85
L_86 , V_147 ) ;
}
}
void F_260 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_415 = V_479 ;
T_1 V_480 ;
T_4 V_147 = V_118 -> V_147 ;
if ( F_22 ( V_14 -> V_39 ) )
return;
V_480 = F_37 ( V_14 , F_42 ( V_147 ) ) ;
V_480 &= ~ V_481 ;
F_71 ( V_14 , F_42 ( V_147 ) , V_480 ) ;
if ( V_14 -> V_108 . type == V_109 &&
! ( F_37 ( V_14 , V_423 ) & V_424 ) )
return;
do {
F_261 ( 10 ) ;
V_480 = F_37 ( V_14 , F_42 ( V_147 ) ) ;
} while ( -- V_415 && ( V_480 & V_481 ) );
if ( ! V_415 ) {
F_102 ( V_155 , L_87
L_86 , V_147 ) ;
}
}
void F_262 ( struct V_1 * V_2 ,
struct V_57 * V_118 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_482 = V_118 -> V_81 ;
T_1 V_480 ;
T_4 V_147 = V_118 -> V_147 ;
V_480 = F_37 ( V_14 , F_42 ( V_147 ) ) ;
F_260 ( V_2 , V_118 ) ;
F_71 ( V_14 , F_43 ( V_147 ) , ( V_482 & F_243 ( 32 ) ) ) ;
F_71 ( V_14 , F_44 ( V_147 ) , ( V_482 >> 32 ) ) ;
F_71 ( V_14 , F_39 ( V_147 ) ,
V_118 -> V_88 * sizeof( union V_68 ) ) ;
F_71 ( V_14 , F_40 ( V_147 ) , 0 ) ;
F_71 ( V_14 , F_41 ( V_147 ) , 0 ) ;
V_118 -> V_144 = V_2 -> V_418 + F_41 ( V_147 ) ;
F_253 ( V_2 , V_118 ) ;
F_257 ( V_2 , V_118 ) ;
if ( V_14 -> V_108 . type == V_109 ) {
V_480 &= ~ 0x3FFFFF ;
V_480 |= 0x080420 ;
}
V_480 |= V_481 ;
F_71 ( V_14 , F_42 ( V_147 ) , V_480 ) ;
F_259 ( V_2 , V_118 ) ;
F_144 ( V_118 , F_109 ( V_118 ) ) ;
}
static void F_263 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_457 = V_2 -> V_435 [ V_436 ] . V_437 ;
T_2 V_483 ;
T_1 V_484 = V_485 |
V_486 |
V_487 |
V_488 |
V_489 ;
if ( V_14 -> V_108 . type == V_109 )
return;
if ( V_457 > 3 )
V_484 |= 2 << 29 ;
else if ( V_457 > 1 )
V_484 |= 1 << 29 ;
F_264 (pool, &adapter->fwd_bitmask, 32 )
F_71 ( V_14 , F_265 ( F_266 ( V_483 ) ) , V_484 ) ;
}
static void F_267 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_176 , V_490 ;
T_1 V_491 , V_492 ;
int V_48 ;
if ( ! ( V_2 -> V_137 & V_430 ) )
return;
V_492 = F_37 ( V_14 , V_493 ) ;
V_492 |= V_494 ;
V_492 &= ~ V_495 ;
V_492 |= F_266 ( 0 ) << V_496 ;
V_492 |= V_497 ;
F_71 ( V_14 , V_493 , V_492 ) ;
V_490 = F_266 ( 0 ) % 32 ;
V_176 = ( F_266 ( 0 ) >= 32 ) ? 1 : 0 ;
F_71 ( V_14 , F_268 ( V_176 ) , ( ~ 0 ) << V_490 ) ;
F_71 ( V_14 , F_268 ( V_176 ^ 1 ) , V_176 - 1 ) ;
F_71 ( V_14 , F_269 ( V_176 ) , ( ~ 0 ) << V_490 ) ;
F_71 ( V_14 , F_269 ( V_176 ^ 1 ) , V_176 - 1 ) ;
if ( V_2 -> V_153 & V_498 )
F_71 ( V_14 , V_499 , V_500 ) ;
V_14 -> V_108 . V_358 . V_501 ( V_14 , 0 , F_266 ( 0 ) ) ;
switch ( V_2 -> V_435 [ V_502 ] . V_115 ) {
case V_503 :
V_491 = V_504 ;
break;
case V_505 :
V_491 = V_506 ;
break;
default:
V_491 = V_507 ;
break;
}
F_71 ( V_14 , V_508 , V_491 ) ;
V_14 -> V_108 . V_358 . V_509 ( V_14 , ( V_2 -> V_325 != 0 ) ,
V_2 -> V_325 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_325 ; V_48 ++ ) {
if ( ! V_2 -> V_510 [ V_48 ] . V_511 )
F_270 ( V_2 -> V_55 , V_48 , false ) ;
}
}
static void F_271 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_55 = V_2 -> V_55 ;
int V_512 = V_55 -> V_313 + V_245 + V_513 ;
struct V_57 * V_67 ;
int V_48 ;
T_1 V_514 , V_515 ;
#ifdef F_148
if ( ( V_2 -> V_137 & V_516 ) &&
( V_512 < V_517 ) )
V_512 = V_517 ;
#endif
if ( V_512 < ( V_518 + V_513 ) )
V_512 = ( V_518 + V_513 ) ;
V_514 = F_37 ( V_14 , V_519 ) ;
if ( V_512 != ( V_514 >> V_520 ) ) {
V_514 &= ~ V_521 ;
V_514 |= V_512 << V_520 ;
F_71 ( V_14 , V_519 , V_514 ) ;
}
V_515 = F_37 ( V_14 , V_522 ) ;
V_515 |= V_523 ;
F_71 ( V_14 , V_522 , V_515 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_67 = V_2 -> V_67 [ V_48 ] ;
if ( V_2 -> V_153 & V_524 )
F_272 ( V_67 ) ;
else
F_273 ( V_67 ) ;
}
}
static void F_274 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_525 = F_37 ( V_14 , V_526 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_525 |= V_527 ;
break;
case V_111 :
case V_112 :
F_71 ( V_14 , V_528 ,
( V_529 | F_37 ( V_14 , V_528 ) ) ) ;
V_525 &= ~ V_530 ;
V_525 |= ( V_531 | V_532 ) ;
V_525 |= V_533 ;
break;
default:
return;
}
F_71 ( V_14 , V_526 , V_525 ) ;
}
static void F_275 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
T_1 V_181 , V_534 ;
V_181 = F_37 ( V_14 , V_535 ) ;
F_71 ( V_14 , V_535 , V_181 & ~ V_536 ) ;
F_263 ( V_2 ) ;
F_274 ( V_2 ) ;
V_534 = F_37 ( V_14 , V_537 ) ;
V_534 &= ~ V_538 ;
if ( ! ( V_2 -> V_153 & V_524 ) )
V_534 |= V_538 ;
F_71 ( V_14 , V_537 , V_534 ) ;
F_254 ( V_2 ) ;
F_271 ( V_2 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
F_262 ( V_2 , V_2 -> V_67 [ V_48 ] ) ;
if ( V_14 -> V_108 . type == V_109 )
V_181 |= V_539 ;
V_181 |= V_536 ;
V_14 -> V_108 . V_358 . V_540 ( V_14 , V_181 ) ;
}
static int F_276 ( struct V_54 * V_55 ,
T_10 V_541 , T_2 V_270 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_108 . V_358 . V_542 ( & V_2 -> V_14 , V_270 , F_266 ( 0 ) , true ) ;
F_245 ( V_270 , V_2 -> V_543 ) ;
return 0 ;
}
static int F_277 ( struct V_54 * V_55 ,
T_10 V_541 , T_2 V_270 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_108 . V_358 . V_542 ( & V_2 -> V_14 , V_270 , F_266 ( 0 ) , false ) ;
F_34 ( V_270 , V_2 -> V_543 ) ;
return 0 ;
}
static void F_278 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_544 ;
int V_48 , V_49 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_544 = F_37 ( V_14 , V_545 ) ;
V_544 &= ~ V_546 ;
F_71 ( V_14 , V_545 , V_544 ) ;
break;
case V_111 :
case V_112 :
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_118 = V_2 -> V_67 [ V_48 ] ;
if ( V_118 -> V_145 )
continue;
V_49 = V_118 -> V_147 ;
V_544 = F_37 ( V_14 , F_42 ( V_49 ) ) ;
V_544 &= ~ V_547 ;
F_71 ( V_14 , F_42 ( V_49 ) , V_544 ) ;
}
break;
default:
break;
}
}
static void F_279 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_544 ;
int V_48 , V_49 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_544 = F_37 ( V_14 , V_545 ) ;
V_544 |= V_546 ;
F_71 ( V_14 , V_545 , V_544 ) ;
break;
case V_111 :
case V_112 :
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_118 = V_2 -> V_67 [ V_48 ] ;
if ( V_118 -> V_145 )
continue;
V_49 = V_118 -> V_147 ;
V_544 = F_37 ( V_14 , F_42 ( V_49 ) ) ;
V_544 |= V_547 ;
F_71 ( V_14 , F_42 ( V_49 ) , V_544 ) ;
}
break;
default:
break;
}
}
static void F_280 ( struct V_1 * V_2 )
{
T_2 V_270 ;
F_276 ( V_2 -> V_55 , F_147 ( V_247 ) , 0 ) ;
F_264 (vid, adapter->active_vlans, VLAN_N_VID)
F_276 ( V_2 -> V_55 , F_147 ( V_247 ) , V_270 ) ;
}
static int F_281 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ! F_57 ( V_55 ) )
return 0 ;
if ( V_14 -> V_108 . V_358 . V_548 )
V_14 -> V_108 . V_358 . V_548 ( V_14 , V_55 ) ;
else
return - V_549 ;
#ifdef F_282
F_283 ( V_2 ) ;
#endif
return F_284 ( V_55 ) ;
}
void F_285 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_550 ; V_48 ++ ) {
if ( V_2 -> V_551 [ V_48 ] . V_34 & V_552 )
V_14 -> V_108 . V_358 . V_553 ( V_14 , V_48 , V_2 -> V_551 [ V_48 ] . V_554 ,
V_2 -> V_551 [ V_48 ] . V_104 ,
V_555 ) ;
else
V_14 -> V_108 . V_358 . V_556 ( V_14 , V_48 ) ;
V_2 -> V_551 [ V_48 ] . V_34 &= ~ ( V_557 ) ;
}
}
static void F_286 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_550 ; V_48 ++ ) {
if ( V_2 -> V_551 [ V_48 ] . V_34 & V_557 ) {
if ( V_2 -> V_551 [ V_48 ] . V_34 &
V_552 )
V_14 -> V_108 . V_358 . V_553 ( V_14 , V_48 ,
V_2 -> V_551 [ V_48 ] . V_554 ,
V_2 -> V_551 [ V_48 ] . V_104 ,
V_555 ) ;
else
V_14 -> V_108 . V_358 . V_556 ( V_14 , V_48 ) ;
V_2 -> V_551 [ V_48 ] . V_34 &=
~ ( V_557 ) ;
}
}
}
static void F_287 ( struct V_1 * V_2 )
{
int V_48 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_550 ; V_48 ++ ) {
V_2 -> V_551 [ V_48 ] . V_34 |= V_557 ;
V_2 -> V_551 [ V_48 ] . V_34 &= ~ V_552 ;
memset ( V_2 -> V_551 [ V_48 ] . V_554 , 0 , V_558 ) ;
V_2 -> V_551 [ V_48 ] . V_104 = 0 ;
}
F_286 ( V_2 ) ;
}
static int F_288 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 , V_88 = 0 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_550 ; V_48 ++ ) {
if ( V_2 -> V_551 [ V_48 ] . V_34 == 0 )
V_88 ++ ;
}
return V_88 ;
}
static void F_289 ( struct V_1 * V_2 ,
T_4 * V_554 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
memcpy ( & V_2 -> V_551 [ 0 ] . V_554 , V_554 , V_558 ) ;
V_2 -> V_551 [ 0 ] . V_104 = F_266 ( 0 ) ;
V_2 -> V_551 [ 0 ] . V_34 = ( V_559 |
V_552 ) ;
V_14 -> V_108 . V_358 . V_553 ( V_14 , 0 , V_2 -> V_551 [ 0 ] . V_554 ,
V_2 -> V_551 [ 0 ] . V_104 ,
V_555 ) ;
}
int F_290 ( struct V_1 * V_2 , T_4 * V_554 , T_2 V_104 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
if ( F_291 ( V_554 ) )
return - V_560 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_550 ; V_48 ++ ) {
if ( V_2 -> V_551 [ V_48 ] . V_34 & V_552 )
continue;
V_2 -> V_551 [ V_48 ] . V_34 |= ( V_557 |
V_552 ) ;
F_292 ( V_2 -> V_551 [ V_48 ] . V_554 , V_554 ) ;
V_2 -> V_551 [ V_48 ] . V_104 = V_104 ;
F_286 ( V_2 ) ;
return V_48 ;
}
return - V_549 ;
}
int F_293 ( struct V_1 * V_2 , T_4 * V_554 , T_2 V_104 )
{
int V_48 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_291 ( V_554 ) )
return - V_560 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_108 . V_550 ; V_48 ++ ) {
if ( F_294 ( V_554 , V_2 -> V_551 [ V_48 ] . V_554 ) &&
V_2 -> V_551 [ V_48 ] . V_104 == V_104 ) {
V_2 -> V_551 [ V_48 ] . V_34 |= V_557 ;
V_2 -> V_551 [ V_48 ] . V_34 &= ~ V_552 ;
memset ( V_2 -> V_551 [ V_48 ] . V_554 , 0 , V_558 ) ;
V_2 -> V_551 [ V_48 ] . V_104 = 0 ;
F_286 ( V_2 ) ;
return 0 ;
}
}
return - V_549 ;
}
static int F_295 ( struct V_54 * V_55 , int V_561 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_88 = 0 ;
if ( F_296 ( V_55 ) > F_288 ( V_2 ) )
return - V_549 ;
if ( ! F_297 ( V_55 ) ) {
struct V_562 * V_563 ;
F_298 (ha, netdev) {
F_293 ( V_2 , V_563 -> V_554 , V_561 ) ;
F_290 ( V_2 , V_563 -> V_554 , V_561 ) ;
V_88 ++ ;
}
}
return V_88 ;
}
void F_299 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_564 , V_565 = V_566 | V_567 ;
T_1 V_544 ;
int V_88 ;
V_564 = F_37 ( V_14 , V_568 ) ;
V_544 = F_37 ( V_14 , V_545 ) ;
V_564 &= ~ V_569 ;
V_564 |= V_570 ;
V_564 |= V_571 ;
V_564 |= V_572 ;
V_564 &= ~ ( V_573 | V_574 ) ;
V_544 &= ~ ( V_575 | V_576 ) ;
if ( V_55 -> V_137 & V_577 ) {
V_14 -> V_578 . V_579 = true ;
V_564 |= ( V_573 | V_574 ) ;
V_565 |= V_580 ;
if ( ! ( V_2 -> V_137 & ( V_581 |
V_430 ) ) )
V_544 |= ( V_575 | V_576 ) ;
} else {
if ( V_55 -> V_137 & V_582 ) {
V_564 |= V_574 ;
V_565 |= V_580 ;
}
V_544 |= V_575 ;
V_14 -> V_578 . V_579 = false ;
}
V_88 = F_295 ( V_55 , F_266 ( 0 ) ) ;
if ( V_88 < 0 ) {
V_564 |= V_573 ;
V_565 |= V_583 ;
}
V_88 = F_281 ( V_55 ) ;
if ( V_88 < 0 ) {
V_564 |= V_574 ;
V_565 |= V_580 ;
} else if ( V_88 ) {
V_565 |= V_584 ;
}
if ( V_14 -> V_108 . type != V_109 ) {
V_565 |= F_37 ( V_14 , F_300 ( F_266 ( 0 ) ) ) &
~ ( V_580 | V_584 |
V_583 ) ;
F_71 ( V_14 , F_300 ( F_266 ( 0 ) ) , V_565 ) ;
}
if ( V_2 -> V_55 -> V_195 & V_291 ) {
V_564 |= ( V_569 |
V_570 |
V_572 ) ;
V_564 &= ~ ( V_571 ) ;
}
F_71 ( V_14 , V_545 , V_544 ) ;
F_71 ( V_14 , V_568 , V_564 ) ;
if ( V_55 -> V_195 & V_268 )
F_279 ( V_2 ) ;
else
F_278 ( V_2 ) ;
}
static void F_301 ( struct V_1 * V_2 )
{
int V_585 ;
for ( V_585 = 0 ; V_585 < V_2 -> V_188 ; V_585 ++ ) {
F_302 ( V_2 -> V_157 [ V_585 ] ) ;
F_303 ( & V_2 -> V_157 [ V_585 ] -> V_272 ) ;
}
}
static void F_304 ( struct V_1 * V_2 )
{
int V_585 ;
for ( V_585 = 0 ; V_585 < V_2 -> V_188 ; V_585 ++ ) {
F_305 ( & V_2 -> V_157 [ V_585 ] -> V_272 ) ;
while ( ! F_306 ( V_2 -> V_157 [ V_585 ] ) ) {
F_51 ( L_88 , V_585 ) ;
F_247 ( 1000 , 20000 ) ;
}
}
}
static void F_307 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_512 = V_2 -> V_55 -> V_313 + V_245 + V_513 ;
if ( ! ( V_2 -> V_137 & V_138 ) ) {
if ( V_14 -> V_108 . type == V_109 )
F_308 ( V_2 -> V_55 , 65536 ) ;
return;
}
if ( V_14 -> V_108 . type == V_109 )
F_308 ( V_2 -> V_55 , 32768 ) ;
#ifdef F_148
if ( V_2 -> V_55 -> V_195 & V_586 )
V_512 = F_206 ( V_512 , V_517 ) ;
#endif
if ( V_2 -> V_587 & V_588 ) {
F_309 ( V_14 , & V_2 -> V_134 , V_512 ,
V_589 ) ;
F_309 ( V_14 , & V_2 -> V_134 , V_512 ,
V_590 ) ;
F_310 ( V_14 , & V_2 -> V_134 ) ;
} else if ( V_2 -> V_591 && V_2 -> V_136 ) {
F_311 ( & V_2 -> V_14 ,
V_2 -> V_591 ,
V_512 ) ;
F_312 ( & V_2 -> V_14 ,
V_2 -> V_136 -> V_133 ,
V_2 -> V_591 -> V_592 ) ;
}
if ( V_14 -> V_108 . type != V_109 ) {
T_1 V_593 = 0 ;
T_2 V_457 = V_2 -> V_435 [ V_436 ] . V_437 - 1 ;
while ( V_457 ) {
V_593 ++ ;
V_457 >>= 1 ;
}
F_71 ( V_14 , V_594 , V_593 * 0x11111111 ) ;
}
}
static int F_313 ( struct V_1 * V_2 , int V_595 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_73 = V_2 -> V_55 ;
int V_391 , V_132 , V_596 , V_597 ;
T_1 V_598 , V_599 ;
V_132 = V_391 = V_73 -> V_313 + V_245 + V_513 + V_600 ;
#ifdef F_148
if ( ( V_73 -> V_195 & V_586 ) &&
( V_132 < V_517 ) &&
( V_595 == F_314 ( V_2 ) ) )
V_132 = V_517 ;
#endif
switch ( V_14 -> V_108 . type ) {
case V_112 :
V_598 = F_315 ( V_391 , V_132 ) ;
break;
default:
V_598 = F_316 ( V_391 , V_132 ) ;
break;
}
if ( V_2 -> V_137 & V_430 )
V_598 += F_317 ( V_132 ) ;
V_596 = F_318 ( V_598 ) ;
V_599 = F_37 ( V_14 , F_319 ( V_595 ) ) >> 10 ;
V_597 = V_599 - V_596 ;
if ( V_597 < 0 ) {
F_93 ( V_155 , L_89
L_90
L_91 , V_595 ) ;
V_597 = V_132 + 1 ;
}
return V_597 ;
}
static int F_320 ( struct V_1 * V_2 , int V_595 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_73 = V_2 -> V_55 ;
int V_132 ;
T_1 V_598 ;
V_132 = V_73 -> V_313 + V_245 + V_513 ;
#ifdef F_148
if ( ( V_73 -> V_195 & V_586 ) &&
( V_132 < V_517 ) &&
( V_595 == F_86 ( V_73 , V_2 -> V_601 . V_602 ) ) )
V_132 = V_517 ;
#endif
switch ( V_14 -> V_108 . type ) {
case V_112 :
V_598 = F_321 ( V_132 ) ;
break;
default:
V_598 = F_322 ( V_132 ) ;
break;
}
return F_318 ( V_598 ) ;
}
static void F_323 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_603 = F_249 ( V_2 -> V_55 ) ;
int V_48 ;
if ( ! V_603 )
V_603 = 1 ;
for ( V_48 = 0 ; V_48 < V_603 ; V_48 ++ ) {
V_14 -> V_123 . V_604 [ V_48 ] = F_313 ( V_2 , V_48 ) ;
V_14 -> V_123 . V_605 [ V_48 ] = F_320 ( V_2 , V_48 ) ;
if ( V_14 -> V_123 . V_605 [ V_48 ] > V_14 -> V_123 . V_604 [ V_48 ] )
V_14 -> V_123 . V_605 [ V_48 ] = 0 ;
}
for (; V_48 < V_606 ; V_48 ++ )
V_14 -> V_123 . V_604 [ V_48 ] = 0 ;
}
static void F_324 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_607 ;
T_4 V_132 = F_249 ( V_2 -> V_55 ) ;
if ( V_2 -> V_137 & V_385 ||
V_2 -> V_137 & V_608 )
V_607 = 32 << V_2 -> V_609 ;
else
V_607 = 0 ;
V_14 -> V_108 . V_358 . V_610 ( V_14 , V_132 , V_607 , V_611 ) ;
F_323 ( V_2 ) ;
}
static void F_325 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_612 * V_613 ;
struct V_614 * V_615 ;
F_326 ( & V_2 -> V_616 ) ;
if ( ! F_327 ( & V_2 -> V_617 ) )
F_328 ( V_14 , & V_2 -> V_618 ) ;
F_329 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_330 ( V_14 ,
& V_615 -> V_615 ,
V_615 -> V_619 ,
( V_615 -> V_620 == V_621 ) ?
V_621 :
V_2 -> V_67 [ V_615 -> V_620 ] -> V_147 ) ;
}
F_331 ( & V_2 -> V_616 ) ;
}
static void F_332 ( struct V_54 * V_73 , unsigned int V_483 ,
struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_565 ;
V_565 = F_37 ( V_14 , F_300 ( V_483 ) ) ;
V_565 |= ( V_584 | V_566 | V_567 ) ;
V_565 &= ~ V_580 ;
if ( V_73 -> V_137 & V_582 ) {
V_565 |= V_580 ;
} else {
V_565 |= V_584 ;
V_14 -> V_108 . V_358 . V_548 ( V_14 , V_73 ) ;
}
F_295 ( V_2 -> V_55 , V_483 ) ;
F_71 ( V_14 , F_300 ( V_483 ) , V_565 ) ;
}
static void F_333 ( struct V_622 * V_623 )
{
struct V_1 * V_2 = V_623 -> V_146 ;
int V_457 = V_2 -> V_624 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_483 = V_623 -> V_483 ;
T_1 V_484 = V_485 |
V_486 |
V_487 |
V_488 |
V_489 ;
if ( V_14 -> V_108 . type == V_109 )
return;
if ( V_457 > 3 )
V_484 |= 2 << 29 ;
else if ( V_457 > 1 )
V_484 |= 1 << 29 ;
F_71 ( V_14 , F_265 ( F_266 ( V_483 ) ) , V_484 ) ;
}
static void F_334 ( struct V_57 * V_67 )
{
struct V_189 * V_73 = V_67 -> V_73 ;
unsigned long V_297 ;
T_2 V_48 ;
if ( ! V_67 -> V_71 )
return;
for ( V_48 = 0 ; V_48 < V_67 -> V_88 ; V_48 ++ ) {
struct V_70 * V_296 ;
V_296 = & V_67 -> V_71 [ V_48 ] ;
if ( V_296 -> V_89 ) {
struct V_194 * V_89 = V_296 -> V_89 ;
if ( F_153 ( V_89 ) -> V_289 ) {
F_80 ( V_73 ,
F_153 ( V_89 ) -> V_81 ,
F_69 ( V_67 ) ,
V_226 ) ;
F_153 ( V_89 ) -> V_289 = false ;
}
F_335 ( V_89 ) ;
}
V_296 -> V_89 = NULL ;
if ( V_296 -> V_81 )
F_80 ( V_73 , V_296 -> V_81 ,
F_141 ( V_67 ) ,
V_226 ) ;
V_296 -> V_81 = 0 ;
if ( V_296 -> V_98 )
F_143 ( V_296 -> V_98 ,
F_139 ( V_67 ) ) ;
V_296 -> V_98 = NULL ;
}
V_297 = sizeof( struct V_70 ) * V_67 -> V_88 ;
memset ( V_67 -> V_71 , 0 , V_297 ) ;
memset ( V_67 -> V_87 , 0 , V_67 -> V_297 ) ;
V_67 -> V_220 = 0 ;
V_67 -> V_79 = 0 ;
V_67 -> V_80 = 0 ;
}
static void F_336 ( struct V_622 * V_623 ,
struct V_57 * V_67 )
{
struct V_1 * V_2 = V_623 -> V_146 ;
int V_107 = V_67 -> V_86 + V_623 -> V_625 ;
F_260 ( V_2 , V_67 ) ;
F_247 ( 10000 , 20000 ) ;
F_216 ( V_2 , ( ( T_6 ) 1 << V_107 ) ) ;
F_334 ( V_67 ) ;
V_67 -> V_145 = NULL ;
}
static int F_337 ( struct V_54 * V_626 ,
struct V_622 * V_627 )
{
struct V_1 * V_2 = V_627 -> V_146 ;
unsigned int V_628 = V_627 -> V_625 ;
unsigned int V_629 = V_627 -> V_630 ;
int V_48 ;
F_338 ( V_626 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_624 ; V_48 ++ ) {
F_336 ( V_627 , V_2 -> V_67 [ V_628 + V_48 ] ) ;
V_2 -> V_67 [ V_628 + V_48 ] -> V_55 = V_2 -> V_55 ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_624 ; V_48 ++ ) {
V_2 -> V_58 [ V_629 + V_48 ] -> V_145 = NULL ;
V_2 -> V_58 [ V_629 + V_48 ] -> V_55 = V_2 -> V_55 ;
}
return 0 ;
}
static int F_339 ( struct V_54 * V_626 ,
struct V_622 * V_627 )
{
struct V_1 * V_2 = V_627 -> V_146 ;
unsigned int V_628 , V_629 , V_377 ;
int V_48 , V_631 , V_17 = 0 ;
if ( ! F_14 ( V_627 -> V_483 , & V_2 -> V_632 ) )
return 0 ;
V_631 = V_627 -> V_483 * V_2 -> V_624 ;
F_340 ( V_626 , L_92 ,
V_627 -> V_483 , V_2 -> V_633 ,
V_631 , V_631 + V_2 -> V_624 ,
V_2 -> V_632 ) ;
V_627 -> V_55 = V_626 ;
V_627 -> V_625 = V_628 = V_631 ;
V_627 -> V_630 = V_629 = V_631 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_624 ; V_48 ++ )
F_336 ( V_627 , V_2 -> V_67 [ V_628 + V_48 ] ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_624 ; V_48 ++ ) {
V_2 -> V_67 [ V_628 + V_48 ] -> V_55 = V_626 ;
V_2 -> V_67 [ V_628 + V_48 ] -> V_145 = V_627 ;
F_262 ( V_2 , V_2 -> V_67 [ V_628 + V_48 ] ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_624 ; V_48 ++ ) {
V_2 -> V_58 [ V_629 + V_48 ] -> V_55 = V_626 ;
V_2 -> V_58 [ V_629 + V_48 ] -> V_145 = V_627 ;
}
V_377 = F_341 (unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues) ;
V_17 = F_342 ( V_626 , V_377 ) ;
if ( V_17 )
goto V_634;
V_17 = F_343 ( V_626 , V_377 ) ;
if ( V_17 )
goto V_634;
if ( F_344 ( V_626 -> V_635 ) )
F_290 ( V_2 , V_626 -> V_635 , V_627 -> V_483 ) ;
F_333 ( V_627 ) ;
F_332 ( V_626 , V_627 -> V_483 , V_2 ) ;
return V_17 ;
V_634:
F_337 ( V_626 , V_627 ) ;
return V_17 ;
}
static void F_345 ( struct V_1 * V_2 )
{
struct V_54 * V_95 ;
struct V_636 * V_637 ;
int V_17 ;
F_346 (adapter->netdev, upper, iter) {
if ( F_347 ( V_95 ) ) {
struct V_638 * V_639 = F_89 ( V_95 ) ;
struct V_622 * V_623 = V_639 -> V_640 ;
if ( V_639 -> V_640 ) {
V_17 = F_339 ( V_95 , V_623 ) ;
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
V_14 -> V_108 . V_358 . V_641 ( V_14 ) ;
break;
default:
break;
}
if ( V_2 -> V_137 & V_385 ) {
F_350 ( & V_2 -> V_14 ,
V_2 -> V_609 ) ;
} else if ( V_2 -> V_137 & V_608 ) {
F_351 ( & V_2 -> V_14 ,
V_2 -> V_609 ) ;
F_325 ( V_2 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
V_14 -> V_108 . V_358 . V_642 ( V_14 ) ;
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
switch ( V_14 -> V_361 . type ) {
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
case V_655 :
return true ;
case V_656 :
if ( V_14 -> V_108 . type == V_109 )
return true ;
default:
return false ;
}
}
static void F_354 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_108 . type == V_109 )
V_2 -> V_153 |= V_657 ;
V_2 -> V_153 |= V_369 ;
}
static int F_355 ( struct V_15 * V_14 )
{
T_1 V_20 ;
bool V_658 , V_360 = false ;
T_1 V_152 = V_659 ;
if ( V_14 -> V_108 . V_358 . V_359 )
V_152 = V_14 -> V_108 . V_358 . V_359 ( V_14 , & V_20 , & V_360 , false ) ;
if ( V_152 )
goto V_660;
V_20 = V_14 -> V_361 . V_661 ;
if ( ( ! V_20 ) && ( V_14 -> V_108 . V_358 . V_662 ) )
V_152 = V_14 -> V_108 . V_358 . V_662 ( V_14 , & V_20 ,
& V_658 ) ;
if ( V_152 )
goto V_660;
if ( V_14 -> V_108 . V_358 . V_663 )
V_152 = V_14 -> V_108 . V_358 . V_663 ( V_14 , V_20 , V_360 ) ;
V_660:
return V_152 ;
}
static void F_356 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_664 = 0 ;
if ( V_2 -> V_137 & V_409 ) {
V_664 = V_665 | V_666 |
V_667 ;
V_664 |= V_668 ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
F_71 ( V_14 , V_669 , V_670 ) ;
break;
case V_111 :
case V_112 :
default:
F_71 ( V_14 , F_357 ( 0 ) , 0xFFFFFFFF ) ;
F_71 ( V_14 , F_357 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_71 ( V_14 , V_669 , V_670 ) ;
}
if ( V_2 -> V_137 & V_430 ) {
V_664 &= ~ V_671 ;
switch ( V_2 -> V_435 [ V_502 ] . V_115 ) {
case V_503 :
V_664 |= V_672 ;
break;
case V_505 :
V_664 |= V_673 ;
break;
default:
V_664 |= V_674 ;
break;
}
}
if ( V_2 -> V_153 & V_353 ) {
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_664 |= V_675 ;
break;
case V_112 :
V_664 |= V_380 ;
break;
default:
break;
}
}
if ( V_2 -> V_137 & V_364 )
V_664 |= V_676 ;
if ( V_14 -> V_108 . type == V_111 ) {
V_664 |= V_676 ;
V_664 |= V_677 ;
}
F_71 ( V_14 , V_678 , V_664 ) ;
}
static void F_358 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 ;
T_1 V_100 ;
F_72 ( V_2 ) ;
F_356 ( V_2 ) ;
if ( V_2 -> V_137 & V_409 )
F_201 ( V_2 ) ;
else
F_241 ( V_2 ) ;
if ( V_14 -> V_108 . V_358 . V_679 )
V_14 -> V_108 . V_358 . V_679 ( V_14 ) ;
F_33 () ;
F_34 ( V_33 , & V_2 -> V_34 ) ;
F_301 ( V_2 ) ;
if ( F_353 ( V_14 ) ) {
F_354 ( V_2 ) ;
} else {
V_17 = F_355 ( V_14 ) ;
if ( V_17 )
F_102 ( V_171 , L_93 , V_17 ) ;
}
F_37 ( V_14 , V_366 ) ;
F_218 ( V_2 , true , true ) ;
if ( V_2 -> V_137 & V_364 ) {
T_1 V_680 = F_37 ( V_14 , V_681 ) ;
if ( V_680 & V_682 )
F_208 ( V_155 , L_73 ) ;
}
V_2 -> V_137 |= V_372 ;
V_2 -> V_373 = V_170 ;
F_359 ( & V_2 -> V_683 , V_170 ) ;
V_100 = F_37 ( V_14 , V_101 ) ;
V_100 |= V_684 ;
F_71 ( V_14 , V_101 , V_100 ) ;
}
void F_360 ( struct V_1 * V_2 )
{
F_361 ( F_362 () ) ;
V_2 -> V_55 -> V_74 = V_170 ;
while ( F_15 ( V_685 , & V_2 -> V_34 ) )
F_247 ( 1000 , 2000 ) ;
F_363 ( V_2 ) ;
if ( V_2 -> V_137 & V_430 )
F_364 ( 2000 ) ;
F_365 ( V_2 ) ;
F_34 ( V_685 , & V_2 -> V_34 ) ;
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
T_4 V_686 [ V_558 ] ;
if ( F_22 ( V_14 -> V_39 ) )
return;
while ( F_15 ( V_687 , & V_2 -> V_34 ) )
F_247 ( 1000 , 2000 ) ;
V_2 -> V_153 &= ~ ( V_657 |
V_369 ) ;
V_2 -> V_137 &= ~ V_370 ;
V_17 = V_14 -> V_108 . V_358 . V_688 ( V_14 ) ;
switch ( V_17 ) {
case 0 :
case V_689 :
case V_690 :
break;
case V_691 :
F_18 ( L_94 ) ;
break;
case V_692 :
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
F_34 ( V_687 , & V_2 -> V_34 ) ;
memcpy ( V_686 , & V_2 -> V_551 [ 0 ] . V_554 , V_55 -> V_693 ) ;
F_287 ( V_2 ) ;
F_289 ( V_2 , V_686 ) ;
if ( V_14 -> V_108 . V_694 )
V_14 -> V_108 . V_358 . V_695 ( V_14 , F_266 ( 0 ) ) ;
if ( F_14 ( V_696 , & V_2 -> V_34 ) )
F_367 ( V_2 ) ;
}
static void F_368 ( struct V_57 * V_58 )
{
struct V_59 * V_78 ;
unsigned long V_297 ;
T_2 V_48 ;
if ( ! V_58 -> V_78 )
return;
for ( V_48 = 0 ; V_48 < V_58 -> V_88 ; V_48 ++ ) {
V_78 = & V_58 -> V_78 [ V_48 ] ;
F_77 ( V_58 , V_78 ) ;
}
F_369 ( F_106 ( V_58 ) ) ;
V_297 = sizeof( struct V_59 ) * V_58 -> V_88 ;
memset ( V_58 -> V_78 , 0 , V_297 ) ;
memset ( V_58 -> V_87 , 0 , V_58 -> V_297 ) ;
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
struct V_612 * V_613 ;
struct V_614 * V_615 ;
F_326 ( & V_2 -> V_616 ) ;
F_329 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_373 ( & V_615 -> V_697 ) ;
F_235 ( V_615 ) ;
}
V_2 -> V_698 = 0 ;
F_331 ( & V_2 -> V_616 ) ;
}
void F_363 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_95 ;
struct V_636 * V_637 ;
T_1 V_181 ;
int V_48 ;
if ( F_15 ( V_33 , & V_2 -> V_34 ) )
return;
V_181 = F_37 ( V_14 , V_535 ) ;
F_71 ( V_14 , V_535 , V_181 & ~ V_536 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ )
F_260 ( V_2 , V_2 -> V_67 [ V_48 ] ) ;
F_247 ( 10000 , 20000 ) ;
F_338 ( V_55 ) ;
F_374 ( V_55 ) ;
F_375 ( V_55 ) ;
F_346 (adapter->netdev, upper, iter) {
if ( F_347 ( V_95 ) ) {
struct V_638 * V_236 = F_89 ( V_95 ) ;
if ( V_236 -> V_640 ) {
F_338 ( V_95 ) ;
F_374 ( V_95 ) ;
F_375 ( V_95 ) ;
}
}
}
F_239 ( V_2 ) ;
F_304 ( V_2 ) ;
V_2 -> V_153 &= ~ ( V_386 |
V_154 ) ;
V_2 -> V_137 &= ~ V_372 ;
F_376 ( & V_2 -> V_683 ) ;
if ( V_2 -> V_325 ) {
F_71 ( & V_2 -> V_14 , V_327 , 0 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_325 ; V_48 ++ )
V_2 -> V_510 [ V_48 ] . V_699 = false ;
F_377 ( V_2 ) ;
F_378 ( V_2 ) ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
T_4 V_147 = V_2 -> V_58 [ V_48 ] -> V_147 ;
F_71 ( V_14 , F_50 ( V_147 ) , V_700 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_111 :
case V_112 :
F_71 ( V_14 , V_446 ,
( F_37 ( V_14 , V_446 ) &
~ V_447 ) ) ;
break;
default:
break;
}
if ( ! F_379 ( V_2 -> V_9 ) )
F_366 ( V_2 ) ;
if ( V_14 -> V_108 . V_358 . V_701 )
V_14 -> V_108 . V_358 . V_701 ( V_14 ) ;
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
unsigned int V_199 , V_702 ;
T_1 V_703 ;
#ifdef F_349
int V_49 ;
struct V_704 * V_132 ;
#endif
V_14 -> V_705 = V_9 -> V_706 ;
V_14 -> V_21 = V_9 -> V_189 ;
V_14 -> V_707 = V_9 -> V_708 ;
V_14 -> V_709 = V_9 -> V_710 ;
V_14 -> V_711 = V_9 -> V_712 ;
V_199 = F_341 ( int , V_713 , F_382 () ) ;
V_2 -> V_435 [ V_436 ] . V_714 = V_199 ;
V_2 -> V_153 |= V_715 ;
V_2 -> V_153 |= V_524 ;
V_2 -> V_716 = V_717 ;
V_2 -> V_420 = 20 ;
V_702 = F_341 ( int , V_718 , F_382 () ) ;
V_2 -> V_435 [ V_719 ] . V_714 = V_702 ;
V_2 -> V_609 = V_720 ;
#ifdef F_226
V_2 -> V_137 |= V_191 ;
#endif
#ifdef F_148
V_2 -> V_137 |= V_721 ;
V_2 -> V_137 &= ~ V_516 ;
#ifdef F_349
V_2 -> V_601 . V_602 = V_722 ;
#endif
#endif
V_2 -> V_551 = F_383 ( sizeof( struct V_723 ) *
V_14 -> V_108 . V_550 ,
V_222 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_2 -> V_153 &= ~ V_715 ;
V_2 -> V_153 &= ~ V_524 ;
if ( V_14 -> V_21 == V_724 )
V_2 -> V_137 |= V_364 ;
V_2 -> V_716 = V_725 ;
V_2 -> V_435 [ V_719 ] . V_714 = 0 ;
V_2 -> V_420 = 0 ;
V_2 -> V_609 = 0 ;
#ifdef F_148
V_2 -> V_137 &= ~ V_721 ;
V_2 -> V_137 &= ~ V_516 ;
#ifdef F_349
V_2 -> V_601 . V_602 = 0 ;
#endif
#endif
break;
case V_111 :
if ( V_14 -> V_21 == V_355 )
V_2 -> V_153 |= V_353 ;
break;
case V_112 :
V_703 = F_37 ( V_14 , V_726 ) ;
if ( V_703 & V_727 )
V_2 -> V_153 |= V_353 ;
break;
default:
break;
}
#ifdef F_148
F_384 ( & V_2 -> V_601 . V_728 ) ;
#endif
F_384 ( & V_2 -> V_616 ) ;
#ifdef F_349
switch ( V_14 -> V_108 . type ) {
case V_112 :
V_2 -> V_134 . V_729 . V_730 = V_731 ;
V_2 -> V_134 . V_729 . V_732 = V_731 ;
break;
default:
V_2 -> V_134 . V_729 . V_730 = V_606 ;
V_2 -> V_134 . V_729 . V_732 = V_606 ;
break;
}
for ( V_49 = 0 ; V_49 < V_606 ; V_49 ++ ) {
V_132 = & V_2 -> V_134 . V_733 [ V_49 ] ;
V_132 -> V_734 [ V_589 ] . V_735 = 0 ;
V_132 -> V_734 [ V_589 ] . V_736 = 12 + ( V_49 & 1 ) ;
V_132 -> V_734 [ V_590 ] . V_735 = 0 ;
V_132 -> V_734 [ V_590 ] . V_736 = 12 + ( V_49 & 1 ) ;
V_132 -> V_737 = V_738 ;
}
V_132 = & V_2 -> V_134 . V_733 [ 0 ] ;
V_132 -> V_734 [ V_589 ] . V_739 = 0xFF ;
V_132 -> V_734 [ V_590 ] . V_739 = 0xFF ;
V_2 -> V_134 . V_740 [ V_589 ] [ 0 ] = 100 ;
V_2 -> V_134 . V_740 [ V_590 ] [ 0 ] = 100 ;
V_2 -> V_134 . V_135 = false ;
V_2 -> V_741 = 0x00 ;
V_2 -> V_587 = V_742 | V_588 ;
memcpy ( & V_2 -> V_743 , & V_2 -> V_134 ,
sizeof( V_2 -> V_743 ) ) ;
#endif
V_14 -> V_123 . V_744 = V_125 ;
V_14 -> V_123 . V_124 = V_125 ;
F_323 ( V_2 ) ;
V_14 -> V_123 . V_745 = V_746 ;
V_14 -> V_123 . V_747 = true ;
V_14 -> V_123 . V_748 = F_385 ( V_14 ) ;
#ifdef F_282
if ( V_749 > 0 )
F_11 ( L_102 ) ;
if ( V_14 -> V_108 . type != V_109 ) {
if ( V_749 > V_750 ) {
V_2 -> V_325 = 0 ;
F_11 ( L_103 ) ;
} else {
V_2 -> V_325 = V_749 ;
}
}
#endif
V_2 -> V_400 = 1 ;
V_2 -> V_751 = 1 ;
V_2 -> V_752 = V_753 ;
V_2 -> V_754 = V_755 ;
V_2 -> V_756 = V_757 ;
if ( F_386 ( V_14 ) ) {
F_18 ( L_104 ) ;
return - V_758 ;
}
F_245 ( 0 , & V_2 -> V_632 ) ;
F_245 ( V_33 , & V_2 -> V_34 ) ;
return 0 ;
}
int F_387 ( struct V_57 * V_58 )
{
struct V_189 * V_73 = V_58 -> V_73 ;
int V_759 = F_388 ( V_73 ) ;
int V_760 = - 1 ;
int V_297 ;
V_297 = sizeof( struct V_59 ) * V_58 -> V_88 ;
if ( V_58 -> V_157 )
V_760 = V_58 -> V_157 -> V_760 ;
V_58 -> V_78 = F_389 ( V_297 , V_760 ) ;
if ( ! V_58 -> V_78 )
V_58 -> V_78 = F_390 ( V_297 ) ;
if ( ! V_58 -> V_78 )
goto V_17;
F_391 ( & V_58 -> V_168 ) ;
V_58 -> V_297 = V_58 -> V_88 * sizeof( union V_61 ) ;
V_58 -> V_297 = F_171 ( V_58 -> V_297 , 4096 ) ;
F_392 ( V_73 , V_760 ) ;
V_58 -> V_87 = F_393 ( V_73 ,
V_58 -> V_297 ,
& V_58 -> V_81 ,
V_761 ) ;
F_392 ( V_73 , V_759 ) ;
if ( ! V_58 -> V_87 )
V_58 -> V_87 = F_393 ( V_73 , V_58 -> V_297 ,
& V_58 -> V_81 , V_761 ) ;
if ( ! V_58 -> V_87 )
goto V_17;
V_58 -> V_80 = 0 ;
V_58 -> V_79 = 0 ;
return 0 ;
V_17:
F_394 ( V_58 -> V_78 ) ;
V_58 -> V_78 = NULL ;
F_395 ( V_73 , L_105 ) ;
return - V_549 ;
}
static int F_396 ( struct V_1 * V_2 )
{
int V_48 , V_17 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
V_17 = F_387 ( V_2 -> V_58 [ V_48 ] ) ;
if ( ! V_17 )
continue;
F_102 ( V_171 , L_106 , V_48 ) ;
goto V_762;
}
return 0 ;
V_762:
while ( V_48 -- )
F_397 ( V_2 -> V_58 [ V_48 ] ) ;
return V_17 ;
}
int F_398 ( struct V_57 * V_67 )
{
struct V_189 * V_73 = V_67 -> V_73 ;
int V_759 = F_388 ( V_73 ) ;
int V_760 = - 1 ;
int V_297 ;
V_297 = sizeof( struct V_70 ) * V_67 -> V_88 ;
if ( V_67 -> V_157 )
V_760 = V_67 -> V_157 -> V_760 ;
V_67 -> V_71 = F_389 ( V_297 , V_760 ) ;
if ( ! V_67 -> V_71 )
V_67 -> V_71 = F_390 ( V_297 ) ;
if ( ! V_67 -> V_71 )
goto V_17;
F_391 ( & V_67 -> V_168 ) ;
V_67 -> V_297 = V_67 -> V_88 * sizeof( union V_68 ) ;
V_67 -> V_297 = F_171 ( V_67 -> V_297 , 4096 ) ;
F_392 ( V_73 , V_760 ) ;
V_67 -> V_87 = F_393 ( V_73 ,
V_67 -> V_297 ,
& V_67 -> V_81 ,
V_761 ) ;
F_392 ( V_73 , V_759 ) ;
if ( ! V_67 -> V_87 )
V_67 -> V_87 = F_393 ( V_73 , V_67 -> V_297 ,
& V_67 -> V_81 , V_761 ) ;
if ( ! V_67 -> V_87 )
goto V_17;
V_67 -> V_79 = 0 ;
V_67 -> V_80 = 0 ;
return 0 ;
V_17:
F_394 ( V_67 -> V_71 ) ;
V_67 -> V_71 = NULL ;
F_395 ( V_73 , L_107 ) ;
return - V_549 ;
}
static int F_399 ( struct V_1 * V_2 )
{
int V_48 , V_17 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_17 = F_398 ( V_2 -> V_67 [ V_48 ] ) ;
if ( ! V_17 )
continue;
F_102 ( V_171 , L_108 , V_48 ) ;
goto V_763;
}
#ifdef F_148
V_17 = F_400 ( V_2 ) ;
if ( ! V_17 )
#endif
return 0 ;
V_763:
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
F_402 ( V_58 -> V_73 , V_58 -> V_297 ,
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
F_402 ( V_67 -> V_73 , V_67 -> V_297 ,
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
static int F_406 ( struct V_54 * V_55 , int V_764 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_512 = V_764 + V_245 + V_513 ;
if ( ( V_764 < 68 ) || ( V_512 > V_765 ) )
return - V_560 ;
if ( ( V_2 -> V_137 & V_430 ) &&
( V_2 -> V_14 . V_108 . type == V_111 ) &&
( V_512 > ( V_518 + V_513 ) ) )
F_93 ( V_171 , L_109 ) ;
F_104 ( V_171 , L_110 , V_55 -> V_313 , V_764 ) ;
V_55 -> V_313 = V_764 ;
if ( F_57 ( V_55 ) )
F_360 ( V_2 ) ;
return 0 ;
}
static int F_407 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_17 , V_377 ;
if ( F_14 ( V_766 , & V_2 -> V_34 ) )
return - V_767 ;
F_374 ( V_55 ) ;
V_17 = F_396 ( V_2 ) ;
if ( V_17 )
goto V_762;
V_17 = F_399 ( V_2 ) ;
if ( V_17 )
goto V_763;
F_348 ( V_2 ) ;
V_17 = F_237 ( V_2 ) ;
if ( V_17 )
goto V_768;
if ( V_2 -> V_633 > 1 )
V_377 = V_2 -> V_624 ;
else
V_377 = V_2 -> V_77 ;
V_17 = F_342 ( V_55 , V_377 ) ;
if ( V_17 )
goto V_769;
if ( V_2 -> V_633 > 1 &&
V_2 -> V_93 > V_770 )
V_377 = V_770 ;
else
V_377 = V_2 -> V_93 ;
V_17 = F_343 ( V_55 , V_377 ) ;
if ( V_17 )
goto V_769;
F_408 ( V_2 ) ;
F_358 ( V_2 ) ;
return 0 ;
V_769:
F_238 ( V_2 ) ;
V_768:
F_404 ( V_2 ) ;
V_763:
F_403 ( V_2 ) ;
V_762:
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
V_2 -> V_14 . V_39 = V_2 -> V_418 ;
F_415 ( V_9 , V_771 ) ;
F_416 ( V_9 ) ;
F_417 ( V_9 ) ;
V_17 = F_418 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_111 ) ;
return V_17 ;
}
F_33 () ;
F_34 ( V_772 , & V_2 -> V_34 ) ;
F_419 ( V_9 ) ;
F_420 ( V_9 , false ) ;
F_366 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_773 , ~ 0 ) ;
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
static int F_425 ( struct V_5 * V_9 , bool * V_774 )
{
struct V_1 * V_2 = F_414 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_775 , V_564 ;
T_1 V_776 = V_2 -> V_777 ;
#ifdef F_426
int V_778 = 0 ;
#endif
F_427 ( V_55 ) ;
F_421 () ;
if ( F_57 ( V_55 ) )
F_409 ( V_2 ) ;
F_423 () ;
F_428 ( V_2 ) ;
#ifdef F_426
V_778 = F_417 ( V_9 ) ;
if ( V_778 )
return V_778 ;
#endif
if ( V_14 -> V_108 . V_358 . V_779 )
V_14 -> V_108 . V_358 . V_779 ( V_14 ) ;
if ( V_776 ) {
F_299 ( V_55 ) ;
if ( V_14 -> V_108 . V_358 . V_679 )
V_14 -> V_108 . V_358 . V_679 ( V_14 ) ;
if ( V_776 & V_780 ) {
V_564 = F_37 ( V_14 , V_568 ) ;
V_564 |= V_574 ;
F_71 ( V_14 , V_568 , V_564 ) ;
}
V_775 = F_37 ( V_14 , V_781 ) ;
V_775 |= V_782 ;
F_71 ( V_14 , V_781 , V_775 ) ;
F_71 ( V_14 , V_783 , V_776 ) ;
} else {
F_71 ( V_14 , V_784 , 0 ) ;
F_71 ( V_14 , V_783 , 0 ) ;
}
switch ( V_14 -> V_108 . type ) {
case V_109 :
F_420 ( V_9 , false ) ;
break;
case V_111 :
case V_112 :
F_420 ( V_9 , ! ! V_776 ) ;
break;
default:
break;
}
* V_774 = ! ! V_776 ;
F_70 ( V_2 ) ;
if ( ! F_15 ( V_772 , & V_2 -> V_34 ) )
F_429 ( V_9 ) ;
return 0 ;
}
static int F_430 ( struct V_5 * V_9 , T_13 V_34 )
{
int V_778 ;
bool V_785 ;
V_778 = F_425 ( V_9 , & V_785 ) ;
if ( V_778 )
return V_778 ;
if ( V_785 ) {
F_431 ( V_9 ) ;
} else {
F_420 ( V_9 , false ) ;
F_415 ( V_9 , V_786 ) ;
}
return 0 ;
}
static void F_432 ( struct V_5 * V_9 )
{
bool V_785 ;
F_425 ( V_9 , & V_785 ) ;
if ( V_787 == V_788 ) {
F_420 ( V_9 , V_785 ) ;
F_415 ( V_9 , V_786 ) ;
}
}
void F_433 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_120 * V_121 = & V_2 -> V_122 ;
T_6 V_789 = 0 ;
T_1 V_48 , V_790 = 0 , V_791 , V_792 , V_793 , V_794 , V_795 ;
T_6 V_281 = 0 , V_173 = 0 , V_796 = 0 ;
T_6 V_225 = 0 , V_306 = 0 ;
T_6 V_169 = 0 , V_142 = 0 , V_797 = 0 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_685 , & V_2 -> V_34 ) )
return;
if ( V_2 -> V_153 & V_524 ) {
T_6 V_265 = 0 ;
T_6 V_266 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
V_265 += V_2 -> V_67 [ V_48 ] -> V_211 . V_265 ;
V_266 += V_2 -> V_67 [ V_48 ] -> V_211 . V_266 ;
}
V_2 -> V_798 = V_265 ;
V_2 -> V_799 = V_266 ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_67 = V_2 -> V_67 [ V_48 ] ;
V_281 += V_67 -> V_211 . V_281 ;
V_225 += V_67 -> V_211 . V_225 ;
V_306 += V_67 -> V_211 . V_306 ;
V_797 += V_67 -> V_211 . V_212 ;
V_169 += V_67 -> V_122 . V_169 ;
V_142 += V_67 -> V_122 . V_142 ;
}
V_2 -> V_281 = V_281 ;
V_2 -> V_225 = V_225 ;
V_2 -> V_306 = V_306 ;
V_2 -> V_797 = V_797 ;
V_55 -> V_122 . V_800 = V_169 ;
V_55 -> V_122 . V_801 = V_142 ;
V_169 = 0 ;
V_142 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_58 = V_2 -> V_58 [ V_48 ] ;
V_173 += V_58 -> V_150 . V_173 ;
V_796 += V_58 -> V_150 . V_796 ;
V_169 += V_58 -> V_122 . V_169 ;
V_142 += V_58 -> V_122 . V_142 ;
}
V_2 -> V_173 = V_173 ;
V_2 -> V_796 = V_796 ;
V_55 -> V_122 . V_802 = V_169 ;
V_55 -> V_122 . V_803 = V_142 ;
V_121 -> V_804 += F_37 ( V_14 , V_805 ) ;
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ ) {
V_791 = F_37 ( V_14 , F_434 ( V_48 ) ) ;
V_790 += V_791 ;
V_121 -> V_791 [ V_48 ] += V_791 ;
V_789 += V_121 -> V_791 [ V_48 ] ;
V_121 -> V_806 [ V_48 ] += F_37 ( V_14 , F_435 ( V_48 ) ) ;
V_121 -> V_807 [ V_48 ] += F_37 ( V_14 , F_436 ( V_48 ) ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_121 -> V_808 [ V_48 ] += F_37 ( V_14 , F_437 ( V_48 ) ) ;
V_121 -> V_809 [ V_48 ] += F_37 ( V_14 , F_438 ( V_48 ) ) ;
V_121 -> V_810 [ V_48 ] += F_37 ( V_14 , F_439 ( V_48 ) ) ;
V_121 -> V_811 [ V_48 ] +=
F_37 ( V_14 , F_440 ( V_48 ) ) ;
break;
case V_111 :
case V_112 :
V_121 -> V_811 [ V_48 ] +=
F_37 ( V_14 , F_441 ( V_48 ) ) ;
break;
default:
break;
}
}
for ( V_48 = 0 ; V_48 < 16 ; V_48 ++ ) {
V_121 -> V_812 [ V_48 ] += F_37 ( V_14 , F_442 ( V_48 ) ) ;
V_121 -> V_813 [ V_48 ] += F_37 ( V_14 , F_443 ( V_48 ) ) ;
if ( ( V_14 -> V_108 . type == V_111 ) ||
( V_14 -> V_108 . type == V_112 ) ) {
V_121 -> V_809 [ V_48 ] += F_37 ( V_14 , F_444 ( V_48 ) ) ;
F_37 ( V_14 , F_445 ( V_48 ) ) ;
V_121 -> V_810 [ V_48 ] += F_37 ( V_14 , F_446 ( V_48 ) ) ;
F_37 ( V_14 , F_447 ( V_48 ) ) ;
}
}
V_121 -> V_814 += F_37 ( V_14 , V_815 ) ;
V_121 -> V_814 -= V_790 ;
F_83 ( V_2 ) ;
switch ( V_14 -> V_108 . type ) {
case V_109 :
V_121 -> V_816 += F_37 ( V_14 , V_817 ) ;
V_121 -> V_818 += F_37 ( V_14 , V_819 ) ;
V_121 -> V_820 += F_37 ( V_14 , V_821 ) ;
V_121 -> V_822 += F_37 ( V_14 , V_823 ) ;
break;
case V_112 :
V_121 -> V_824 += F_37 ( V_14 , V_825 ) ;
V_121 -> V_826 += F_37 ( V_14 , V_827 ) ;
V_121 -> V_828 += F_37 ( V_14 , V_829 ) ;
V_121 -> V_830 += F_37 ( V_14 , V_831 ) ;
case V_111 :
for ( V_48 = 0 ; V_48 < 16 ; V_48 ++ )
V_2 -> V_832 +=
F_37 ( V_14 , F_448 ( V_48 ) ) ;
V_121 -> V_818 += F_37 ( V_14 , V_833 ) ;
F_37 ( V_14 , V_819 ) ;
V_121 -> V_820 += F_37 ( V_14 , V_834 ) ;
F_37 ( V_14 , V_821 ) ;
V_121 -> V_822 += F_37 ( V_14 , V_835 ) ;
F_37 ( V_14 , V_823 ) ;
V_121 -> V_816 += F_37 ( V_14 , V_836 ) ;
V_121 -> V_837 += F_37 ( V_14 , V_838 ) ;
V_121 -> V_839 += F_37 ( V_14 , V_840 ) ;
#ifdef F_148
V_121 -> V_841 += F_37 ( V_14 , V_842 ) ;
V_121 -> V_843 += F_37 ( V_14 , V_844 ) ;
V_121 -> V_845 += F_37 ( V_14 , V_846 ) ;
V_121 -> V_847 += F_37 ( V_14 , V_848 ) ;
V_121 -> V_849 += F_37 ( V_14 , V_850 ) ;
V_121 -> V_851 += F_37 ( V_14 , V_852 ) ;
if ( V_2 -> V_601 . V_853 ) {
struct V_854 * V_601 = & V_2 -> V_601 ;
struct V_855 * V_853 ;
unsigned int V_174 ;
T_6 V_856 = 0 , V_857 = 0 ;
F_449 (cpu) {
V_853 = F_450 ( V_601 -> V_853 , V_174 ) ;
V_856 += V_853 -> V_856 ;
V_857 += V_853 -> V_857 ;
}
V_121 -> V_858 = V_856 ;
V_121 -> V_859 = V_857 ;
}
#endif
break;
default:
break;
}
V_792 = F_37 ( V_14 , V_860 ) ;
V_121 -> V_792 += V_792 ;
V_121 -> V_861 += F_37 ( V_14 , V_862 ) ;
if ( V_14 -> V_108 . type == V_109 )
V_121 -> V_861 -= V_792 ;
V_121 -> V_863 += F_37 ( V_14 , V_864 ) ;
V_121 -> V_865 += F_37 ( V_14 , V_866 ) ;
V_121 -> V_867 += F_37 ( V_14 , V_868 ) ;
V_121 -> V_869 += F_37 ( V_14 , V_870 ) ;
V_121 -> V_871 += F_37 ( V_14 , V_872 ) ;
V_121 -> V_873 += F_37 ( V_14 , V_874 ) ;
V_121 -> V_875 += F_37 ( V_14 , V_876 ) ;
V_121 -> V_877 += F_37 ( V_14 , V_878 ) ;
V_793 = F_37 ( V_14 , V_879 ) ;
V_121 -> V_880 += V_793 ;
V_794 = F_37 ( V_14 , V_881 ) ;
V_121 -> V_882 += V_794 ;
V_121 -> V_883 += F_37 ( V_14 , V_884 ) ;
V_121 -> V_885 += F_37 ( V_14 , V_886 ) ;
V_795 = V_793 + V_794 ;
V_121 -> V_883 -= V_795 ;
V_121 -> V_885 -= V_795 ;
V_121 -> V_820 -= ( V_795 * ( V_887 + V_513 ) ) ;
V_121 -> V_888 += F_37 ( V_14 , V_889 ) ;
V_121 -> V_890 += F_37 ( V_14 , V_891 ) ;
V_121 -> V_892 += F_37 ( V_14 , V_893 ) ;
V_121 -> V_894 += F_37 ( V_14 , V_895 ) ;
V_121 -> V_896 += F_37 ( V_14 , V_897 ) ;
V_121 -> V_896 -= V_795 ;
V_121 -> V_898 += F_37 ( V_14 , V_899 ) ;
V_121 -> V_900 += F_37 ( V_14 , V_901 ) ;
V_121 -> V_902 += F_37 ( V_14 , V_903 ) ;
V_121 -> V_904 += F_37 ( V_14 , V_905 ) ;
V_121 -> V_906 += F_37 ( V_14 , V_907 ) ;
V_121 -> V_908 += F_37 ( V_14 , V_909 ) ;
V_55 -> V_122 . V_910 = V_121 -> V_861 ;
V_55 -> V_122 . V_911 = V_121 -> V_804 + V_121 -> V_877 ;
V_55 -> V_122 . V_912 = 0 ;
V_55 -> V_122 . V_913 = V_121 -> V_877 ;
V_55 -> V_122 . V_914 = V_121 -> V_804 ;
V_55 -> V_122 . V_915 = V_789 ;
}
static void F_451 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_48 ;
if ( ! ( V_2 -> V_153 & V_386 ) )
return;
V_2 -> V_153 &= ~ V_386 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
if ( ! ( V_2 -> V_137 & V_385 ) )
return;
V_2 -> V_916 ++ ;
if ( F_452 ( V_14 ) == 0 ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_245 ( V_394 ,
& ( V_2 -> V_58 [ V_48 ] -> V_34 ) ) ;
F_71 ( V_14 , V_376 , V_387 ) ;
} else {
F_102 ( V_171 , L_112
L_113 ) ;
}
}
static void F_453 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_917 = 0 ;
int V_48 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_685 , & V_2 -> V_34 ) )
return;
if ( F_108 ( V_2 -> V_55 ) ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ )
F_454 ( V_2 -> V_58 [ V_48 ] ) ;
}
if ( ! ( V_2 -> V_137 & V_409 ) ) {
F_71 ( V_14 , V_117 ,
( V_918 | V_919 ) ) ;
} else {
for ( V_48 = 0 ; V_48 < V_2 -> V_188 ; V_48 ++ ) {
struct V_156 * V_920 = V_2 -> V_157 [ V_48 ] ;
if ( V_920 -> V_317 . V_118 || V_920 -> V_161 . V_118 )
V_917 |= ( ( T_6 ) 1 << V_48 ) ;
}
}
F_75 ( V_2 , V_917 ) ;
}
static void F_455 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_921 = V_2 -> V_921 ;
bool V_360 = V_2 -> V_360 ;
bool V_133 = V_2 -> V_134 . V_135 ;
if ( ! ( V_2 -> V_137 & V_372 ) )
return;
if ( V_14 -> V_108 . V_358 . V_359 ) {
V_14 -> V_108 . V_358 . V_359 ( V_14 , & V_921 , & V_360 , false ) ;
} else {
V_921 = V_922 ;
V_360 = true ;
}
if ( V_2 -> V_136 )
V_133 |= ! ! ( V_2 -> V_136 -> V_133 ) ;
if ( V_360 && ! ( ( V_2 -> V_137 & V_138 ) && V_133 ) ) {
V_14 -> V_108 . V_358 . V_923 ( V_14 ) ;
F_456 ( V_2 ) ;
}
if ( V_360 ||
F_457 ( V_170 , ( V_2 -> V_373 +
V_924 ) ) ) {
V_2 -> V_137 &= ~ V_372 ;
F_71 ( V_14 , V_376 , V_375 ) ;
F_213 ( V_14 ) ;
}
V_2 -> V_360 = V_360 ;
V_2 -> V_921 = V_921 ;
}
static void F_458 ( struct V_1 * V_2 )
{
#ifdef F_349
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_925 V_926 = {
. V_927 = V_928 ,
. V_242 = 0 ,
} ;
T_4 V_602 = 0 ;
if ( V_2 -> V_587 & V_929 )
V_602 = F_459 ( V_55 , & V_926 ) ;
V_2 -> V_930 = ( V_602 > 1 ) ? ( F_460 ( V_602 ) - 1 ) : 0 ;
#endif
}
static void F_461 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_95 ;
struct V_636 * V_637 ;
T_1 V_921 = V_2 -> V_921 ;
bool V_931 , V_932 ;
if ( F_108 ( V_55 ) )
return;
V_2 -> V_153 &= ~ V_657 ;
switch ( V_14 -> V_108 . type ) {
case V_109 : {
T_1 V_933 = F_37 ( V_14 , V_568 ) ;
T_1 V_934 = F_37 ( V_14 , V_935 ) ;
V_931 = ! ! ( V_933 & V_936 ) ;
V_932 = ! ! ( V_934 & V_937 ) ;
}
break;
case V_112 :
case V_111 : {
T_1 V_938 = F_37 ( V_14 , V_939 ) ;
T_1 V_940 = F_37 ( V_14 , V_941 ) ;
V_931 = ! ! ( V_938 & V_942 ) ;
V_932 = ! ! ( V_940 & V_943 ) ;
}
break;
default:
V_932 = false ;
V_931 = false ;
break;
}
V_2 -> V_944 = V_170 ;
if ( F_14 ( V_696 , & V_2 -> V_34 ) )
F_462 ( V_2 ) ;
F_104 ( V_155 , L_114 ,
( V_921 == V_922 ?
L_115 :
( V_921 == V_945 ?
L_116 :
( V_921 == V_946 ?
L_117 :
L_118 ) ) ) ,
( ( V_931 && V_932 ) ? L_119 :
( V_931 ? L_120 :
( V_932 ? L_121 : L_122 ) ) ) ) ;
F_463 ( V_55 ) ;
F_464 ( V_2 ) ;
F_465 ( V_2 -> V_55 ) ;
F_421 () ;
F_346 (adapter->netdev, upper, iter) {
if ( F_347 ( V_95 ) ) {
struct V_638 * V_236 = F_89 ( V_95 ) ;
if ( V_236 -> V_640 )
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
V_2 -> V_360 = false ;
V_2 -> V_921 = 0 ;
if ( ! F_108 ( V_55 ) )
return;
if ( F_353 ( V_14 ) && V_14 -> V_108 . type == V_109 )
V_2 -> V_153 |= V_657 ;
if ( F_14 ( V_696 , & V_2 -> V_34 ) )
F_462 ( V_2 ) ;
F_104 ( V_155 , L_123 ) ;
F_374 ( V_55 ) ;
F_377 ( V_2 ) ;
}
static void F_467 ( struct V_1 * V_2 )
{
int V_48 ;
int V_947 = 0 ;
if ( ! F_108 ( V_2 -> V_55 ) ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_58 = V_2 -> V_58 [ V_48 ] ;
if ( V_58 -> V_80 != V_58 -> V_79 ) {
V_947 = 1 ;
break;
}
}
if ( V_947 ) {
F_93 ( V_155 , L_124 ) ;
V_2 -> V_153 |= V_154 ;
}
}
}
static void F_468 ( struct V_1 * V_2 )
{
T_1 V_948 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ||
V_2 -> V_325 == 0 )
return;
V_948 = F_37 ( & V_2 -> V_14 , V_949 ) ;
if ( ! V_948 )
return;
F_93 ( V_155 , L_125 , V_948 ) ;
}
static void F_469 ( struct V_1 * V_2 )
{
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_685 , & V_2 -> V_34 ) )
return;
F_455 ( V_2 ) ;
if ( V_2 -> V_360 )
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
if ( ! ( V_2 -> V_153 & V_657 ) &&
! ( V_2 -> V_153 & V_369 ) )
return;
if ( F_15 ( V_687 , & V_2 -> V_34 ) )
return;
V_17 = V_14 -> V_361 . V_358 . V_950 ( V_14 ) ;
if ( V_17 == V_690 )
goto V_951;
if ( V_17 == V_689 ) {
V_2 -> V_153 |= V_369 ;
}
if ( V_17 )
goto V_951;
if ( ! ( V_2 -> V_153 & V_369 ) )
goto V_951;
V_2 -> V_153 &= ~ V_369 ;
if ( V_14 -> V_108 . type == V_109 )
V_17 = V_14 -> V_361 . V_358 . V_952 ( V_14 ) ;
else
V_17 = V_14 -> V_108 . V_358 . V_953 ( V_14 ) ;
if ( V_17 == V_690 )
goto V_951;
V_2 -> V_137 |= V_370 ;
F_104 ( V_171 , L_126 , V_14 -> V_361 . V_954 ) ;
V_951:
F_34 ( V_687 , & V_2 -> V_34 ) ;
if ( ( V_17 == V_690 ) &&
( V_2 -> V_55 -> V_955 == V_956 ) ) {
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
bool V_658 = false ;
if ( ! ( V_2 -> V_137 & V_370 ) )
return;
if ( F_15 ( V_687 , & V_2 -> V_34 ) )
return;
V_2 -> V_137 &= ~ V_370 ;
V_20 = V_14 -> V_361 . V_661 ;
if ( ( ! V_20 ) && ( V_14 -> V_108 . V_358 . V_662 ) ) {
V_14 -> V_108 . V_358 . V_662 ( V_14 , & V_20 , & V_658 ) ;
if ( ! V_658 ) {
if ( V_20 & V_922 )
V_20 = V_922 ;
}
}
if ( V_14 -> V_108 . V_358 . V_663 )
V_14 -> V_108 . V_358 . V_663 ( V_14 , V_20 , true ) ;
V_2 -> V_137 |= V_372 ;
V_2 -> V_373 = V_170 ;
F_34 ( V_687 , & V_2 -> V_34 ) ;
}
static void F_473 ( struct V_1 * V_2 )
{
int V_957 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_54 * V_55 = V_2 -> V_55 ;
T_1 V_958 ;
T_1 V_959 , V_960 ;
V_958 = F_37 ( V_14 , V_961 ) ;
if ( V_958 )
return;
for ( V_957 = 0 ; V_957 < V_2 -> V_325 ; V_957 ++ ) {
V_959 = ( V_957 << 16 ) | 0x80000000 ;
V_959 |= V_962 ;
F_71 ( V_14 , V_963 , V_959 ) ;
V_960 = F_37 ( V_14 , V_964 ) ;
V_959 &= 0x7FFFFFFF ;
F_71 ( V_14 , V_963 , V_959 ) ;
V_960 >>= 16 ;
if ( V_960 & V_965 ) {
F_474 ( V_55 , L_131 , V_957 ) ;
V_959 = ( V_957 << 16 ) | 0x80000000 ;
V_959 |= 0xA8 ;
F_71 ( V_14 , V_963 , V_959 ) ;
V_960 = 0x00008000 ;
F_71 ( V_14 , V_964 , V_960 ) ;
V_959 &= 0x7FFFFFFF ;
F_71 ( V_14 , V_963 , V_959 ) ;
}
}
}
static void F_475 ( unsigned long V_92 )
{
struct V_1 * V_2 = (struct V_1 * ) V_92 ;
unsigned long V_966 ;
bool V_967 = true ;
if ( V_2 -> V_137 & V_372 )
V_966 = V_968 / 10 ;
else
V_966 = V_968 * 2 ;
#ifdef F_282
if ( ! V_2 -> V_325 ||
( V_2 -> V_137 & V_372 ) )
goto V_969;
F_473 ( V_2 ) ;
V_966 = V_968 / 50 ;
V_2 -> V_970 ++ ;
if ( V_2 -> V_970 >= 100 )
V_2 -> V_970 = 0 ;
else
V_967 = false ;
V_969:
#endif
F_359 ( & V_2 -> V_683 , V_966 + V_170 ) ;
if ( V_967 )
F_13 ( V_2 ) ;
}
static void F_476 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_153 & V_154 ) )
return;
V_2 -> V_153 &= ~ V_154 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_685 , & V_2 -> V_34 ) )
return;
F_54 ( V_2 ) ;
F_474 ( V_2 -> V_55 , L_132 ) ;
V_2 -> V_172 ++ ;
F_421 () ;
F_360 ( V_2 ) ;
F_423 () ;
}
static void F_477 ( struct V_971 * V_972 )
{
struct V_1 * V_2 = F_197 ( V_972 ,
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
if ( F_14 ( V_696 , & V_2 -> V_34 ) ) {
F_478 ( V_2 ) ;
F_479 ( V_2 ) ;
}
F_31 ( V_2 ) ;
}
static int F_480 ( struct V_57 * V_58 ,
struct V_59 * V_973 ,
T_4 * V_260 )
{
struct V_194 * V_89 = V_973 -> V_89 ;
T_1 V_974 , V_975 ;
T_1 V_976 , V_977 ;
int V_17 ;
if ( V_89 -> V_217 != V_978 )
return 0 ;
if ( ! F_481 ( V_89 ) )
return 0 ;
V_17 = F_482 ( V_89 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_975 = V_979 ;
if ( V_973 -> V_242 == F_147 ( V_250 ) ) {
struct V_237 * V_980 = F_483 ( V_89 ) ;
V_980 -> V_981 = 0 ;
V_980 -> V_982 = 0 ;
F_484 ( V_89 ) -> V_982 = ~ F_485 ( V_980 -> V_983 ,
V_980 -> V_984 , 0 ,
V_256 ,
0 ) ;
V_975 |= V_985 ;
V_973 -> V_986 |= V_987 |
V_988 |
V_989 ;
} else if ( F_486 ( V_89 ) ) {
F_487 ( V_89 ) -> V_990 = 0 ;
F_484 ( V_89 ) -> V_982 =
~ F_488 ( & F_487 ( V_89 ) -> V_983 ,
& F_487 ( V_89 ) -> V_984 ,
0 , V_256 , 0 ) ;
V_973 -> V_986 |= V_987 |
V_988 ;
}
V_977 = F_489 ( V_89 ) ;
* V_260 = F_490 ( V_89 ) + V_977 ;
V_973 -> V_167 = F_151 ( V_89 ) -> V_167 ;
V_973 -> V_166 += ( V_973 -> V_167 - 1 ) * * V_260 ;
V_976 = V_977 << V_991 ;
V_976 |= F_151 ( V_89 ) -> V_261 << V_992 ;
V_974 = F_491 ( V_89 ) ;
V_974 |= F_492 ( V_89 ) << V_993 ;
V_974 |= V_973 -> V_986 & V_994 ;
F_493 ( V_58 , V_974 , 0 , V_975 ,
V_976 ) ;
return 1 ;
}
static void F_494 ( struct V_57 * V_58 ,
struct V_59 * V_973 )
{
struct V_194 * V_89 = V_973 -> V_89 ;
T_1 V_974 = 0 ;
T_1 V_976 = 0 ;
T_1 V_975 = 0 ;
if ( V_89 -> V_217 != V_978 ) {
if ( ! ( V_973 -> V_986 & V_995 ) &&
! ( V_973 -> V_986 & V_996 ) )
return;
} else {
T_4 V_997 = 0 ;
switch ( V_973 -> V_242 ) {
case F_147 ( V_250 ) :
V_974 |= F_491 ( V_89 ) ;
V_975 |= V_985 ;
V_997 = F_483 ( V_89 ) -> V_242 ;
break;
case F_147 ( V_253 ) :
V_974 |= F_491 ( V_89 ) ;
V_997 = F_487 ( V_89 ) -> V_243 ;
break;
default:
if ( F_24 ( F_495 () ) ) {
F_496 ( V_58 -> V_73 ,
L_133 ,
V_973 -> V_242 ) ;
}
break;
}
switch ( V_997 ) {
case V_256 :
V_975 |= V_979 ;
V_976 = F_489 ( V_89 ) <<
V_991 ;
break;
case V_998 :
V_975 |= V_999 ;
V_976 = sizeof( struct V_1000 ) <<
V_991 ;
break;
case V_258 :
V_976 = sizeof( struct V_259 ) <<
V_991 ;
break;
default:
if ( F_24 ( F_495 () ) ) {
F_496 ( V_58 -> V_73 ,
L_134 ,
V_997 ) ;
}
break;
}
V_973 -> V_986 |= V_988 ;
}
V_974 |= F_492 ( V_89 ) << V_993 ;
V_974 |= V_973 -> V_986 & V_994 ;
F_493 ( V_58 , V_974 , 0 ,
V_975 , V_976 ) ;
}
static T_1 F_497 ( struct V_194 * V_89 , T_1 V_986 )
{
T_1 V_1001 = V_1002 |
V_1003 |
V_1004 ;
V_1001 |= F_498 ( V_986 , V_995 ,
V_1005 ) ;
V_1001 |= F_498 ( V_986 , V_987 ,
V_1006 ) ;
V_1001 |= F_498 ( V_986 , V_1007 ,
V_1008 ) ;
V_1001 ^= F_498 ( V_89 -> V_1009 , 1 , V_1004 ) ;
return V_1001 ;
}
static void F_499 ( union V_61 * V_62 ,
T_1 V_986 , unsigned int V_1010 )
{
T_1 V_1011 = V_1010 << V_1012 ;
V_1011 |= F_498 ( V_986 ,
V_988 ,
V_1013 ) ;
V_1011 |= F_498 ( V_986 ,
V_989 ,
V_1014 ) ;
V_1011 |= F_498 ( V_986 ,
V_996 ,
V_1015 ) ;
V_62 -> V_228 . V_1011 = F_96 ( V_1011 ) ;
}
static void F_500 ( struct V_57 * V_58 ,
struct V_59 * V_973 ,
const T_4 V_260 )
{
struct V_194 * V_89 = V_973 -> V_89 ;
struct V_59 * V_60 ;
union V_61 * V_62 ;
struct V_282 * V_283 ;
T_9 V_81 ;
unsigned int V_288 , V_297 ;
T_1 V_986 = V_973 -> V_986 ;
T_1 V_1001 = F_497 ( V_89 , V_986 ) ;
T_2 V_48 = V_58 -> V_80 ;
V_62 = F_61 ( V_58 , V_48 ) ;
F_499 ( V_62 , V_986 , V_89 -> V_82 - V_260 ) ;
V_297 = F_150 ( V_89 ) ;
V_288 = V_89 -> V_288 ;
#ifdef F_148
if ( V_986 & V_1016 ) {
if ( V_288 < sizeof( struct V_316 ) ) {
V_297 -= sizeof( struct V_316 ) - V_288 ;
V_288 = 0 ;
} else {
V_288 -= sizeof( struct V_316 ) ;
}
}
#endif
V_81 = F_501 ( V_58 -> V_73 , V_89 -> V_92 , V_297 , V_119 ) ;
V_60 = V_973 ;
for ( V_283 = & F_151 ( V_89 ) -> V_284 [ 0 ] ; ; V_283 ++ ) {
if ( F_142 ( V_58 -> V_73 , V_81 ) )
goto V_1017;
F_81 ( V_60 , V_82 , V_297 ) ;
F_502 ( V_60 , V_81 , V_81 ) ;
V_62 -> V_228 . V_1018 = F_145 ( V_81 ) ;
while ( F_24 ( V_297 > V_1019 ) ) {
V_62 -> V_228 . V_1020 =
F_96 ( V_1001 ^ V_1019 ) ;
V_48 ++ ;
V_62 ++ ;
if ( V_48 == V_58 -> V_88 ) {
V_62 = F_61 ( V_58 , 0 ) ;
V_48 = 0 ;
}
V_62 -> V_228 . V_1011 = 0 ;
V_81 += V_1019 ;
V_297 -= V_1019 ;
V_62 -> V_228 . V_1018 = F_145 ( V_81 ) ;
}
if ( F_98 ( ! V_288 ) )
break;
V_62 -> V_228 . V_1020 = F_96 ( V_1001 ^ V_297 ) ;
V_48 ++ ;
V_62 ++ ;
if ( V_48 == V_58 -> V_88 ) {
V_62 = F_61 ( V_58 , 0 ) ;
V_48 = 0 ;
}
V_62 -> V_228 . V_1011 = 0 ;
#ifdef F_148
V_297 = F_341 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_297 = F_503 ( V_283 ) ;
#endif
V_288 -= V_297 ;
V_81 = F_504 ( V_58 -> V_73 , V_283 , 0 , V_297 ,
V_119 ) ;
V_60 = & V_58 -> V_78 [ V_48 ] ;
}
V_1001 |= V_297 | V_1021 ;
V_62 -> V_228 . V_1020 = F_96 ( V_1001 ) ;
F_505 ( F_106 ( V_58 ) , V_973 -> V_166 ) ;
V_973 -> V_84 = V_170 ;
F_135 () ;
V_973 -> V_83 = V_62 ;
V_48 ++ ;
if ( V_48 == V_58 -> V_88 )
V_48 = 0 ;
V_58 -> V_80 = V_48 ;
F_136 ( V_58 , V_48 ) ;
return;
V_1017:
F_395 ( V_58 -> V_73 , L_135 ) ;
for (; ; ) {
V_60 = & V_58 -> V_78 [ V_48 ] ;
F_77 ( V_58 , V_60 ) ;
if ( V_60 == V_973 )
break;
if ( V_48 == 0 )
V_48 = V_58 -> V_88 ;
V_48 -- ;
}
V_58 -> V_80 = V_48 ;
}
static void F_506 ( struct V_57 * V_118 ,
struct V_59 * V_973 )
{
struct V_156 * V_157 = V_118 -> V_157 ;
union V_1022 V_1023 = { . V_1024 = 0 } ;
union V_1022 V_1025 = { . V_1024 = 0 } ;
union {
unsigned char * V_232 ;
struct V_237 * V_238 ;
struct V_239 * V_240 ;
} V_241 ;
struct V_257 * V_1026 ;
T_10 V_1027 ;
if ( ! V_157 )
return;
if ( ! V_118 -> V_420 )
return;
V_118 -> V_421 ++ ;
V_241 . V_232 = F_507 ( V_973 -> V_89 ) ;
if ( ( V_973 -> V_242 != F_147 ( V_253 ) ||
V_241 . V_240 -> V_243 != V_256 ) &&
( V_973 -> V_242 != F_147 ( V_250 ) ||
V_241 . V_238 -> V_242 != V_256 ) )
return;
V_1026 = F_484 ( V_973 -> V_89 ) ;
if ( ! V_1026 || V_1026 -> V_1028 )
return;
if ( ! V_1026 -> V_1029 && ( V_118 -> V_421 < V_118 -> V_420 ) )
return;
V_118 -> V_421 = 0 ;
V_1027 = F_147 ( V_973 -> V_986 >> V_1030 ) ;
V_1023 . V_1031 . V_1027 = V_1027 ;
if ( V_973 -> V_986 & ( V_1032 | V_995 ) )
V_1025 . V_1033 . V_1034 ^= V_1026 -> V_1035 ^ F_147 ( V_247 ) ;
else
V_1025 . V_1033 . V_1034 ^= V_1026 -> V_1035 ^ V_973 -> V_242 ;
V_1025 . V_1033 . V_1036 ^= V_1026 -> V_1037 ;
if ( V_973 -> V_242 == F_147 ( V_250 ) ) {
V_1023 . V_1031 . V_1038 = V_1039 ;
V_1025 . V_1040 ^= V_241 . V_238 -> V_983 ^ V_241 . V_238 -> V_984 ;
} else {
V_1023 . V_1031 . V_1038 = V_1041 ;
V_1025 . V_1040 ^= V_241 . V_240 -> V_983 . V_1042 [ 0 ] ^
V_241 . V_240 -> V_983 . V_1042 [ 1 ] ^
V_241 . V_240 -> V_983 . V_1042 [ 2 ] ^
V_241 . V_240 -> V_983 . V_1042 [ 3 ] ^
V_241 . V_240 -> V_984 . V_1042 [ 0 ] ^
V_241 . V_240 -> V_984 . V_1042 [ 1 ] ^
V_241 . V_240 -> V_984 . V_1042 [ 2 ] ^
V_241 . V_240 -> V_984 . V_1042 [ 3 ] ;
}
F_508 ( & V_157 -> V_2 -> V_14 ,
V_1023 , V_1025 , V_118 -> V_86 ) ;
}
static int F_509 ( struct V_57 * V_58 , T_2 V_297 )
{
F_103 ( V_58 -> V_55 , V_58 -> V_86 ) ;
F_110 () ;
if ( F_98 ( F_109 ( V_58 ) < V_297 ) )
return - V_767 ;
F_510 ( V_58 -> V_55 , V_58 -> V_86 ) ;
++ V_58 -> V_150 . V_173 ;
return 0 ;
}
static inline int F_511 ( struct V_57 * V_58 , T_2 V_297 )
{
if ( F_98 ( F_109 ( V_58 ) >= V_297 ) )
return 0 ;
return F_509 ( V_58 , V_297 ) ;
}
static T_2 F_512 ( struct V_54 * V_73 , struct V_194 * V_89 ,
void * V_1043 , T_14 V_1044 )
{
struct V_622 * V_1045 = V_1043 ;
#ifdef F_148
struct V_1 * V_2 ;
struct V_1046 * V_1047 ;
int V_1048 ;
#endif
if ( V_1045 )
return V_89 -> V_1049 + V_1045 -> V_630 ;
#ifdef F_148
switch ( F_513 ( V_89 ) ) {
case F_147 ( V_254 ) :
case F_147 ( V_1050 ) :
V_2 = F_89 ( V_73 ) ;
if ( V_2 -> V_137 & V_516 )
break;
default:
return V_1044 ( V_73 , V_89 ) ;
}
V_1047 = & V_2 -> V_435 [ V_1051 ] ;
V_1048 = F_514 ( V_89 ) ? F_515 ( V_89 ) :
F_516 () ;
while ( V_1048 >= V_1047 -> V_437 )
V_1048 -= V_1047 -> V_437 ;
return V_1048 + V_1047 -> V_1052 ;
#else
return V_1044 ( V_73 , V_89 ) ;
#endif
}
T_15 F_517 ( struct V_194 * V_89 ,
struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_59 * V_973 ;
int V_1053 ;
T_1 V_986 = 0 ;
unsigned short V_1047 ;
T_2 V_88 = F_518 ( F_150 ( V_89 ) ) ;
T_10 V_242 = V_89 -> V_242 ;
T_4 V_260 = 0 ;
for ( V_1047 = 0 ; V_1047 < F_151 ( V_89 ) -> V_303 ; V_1047 ++ )
V_88 += F_518 ( F_151 ( V_89 ) -> V_284 [ V_1047 ] . V_297 ) ;
if ( F_511 ( V_58 , V_88 + 3 ) ) {
V_58 -> V_150 . V_796 ++ ;
return V_1054 ;
}
V_973 = & V_58 -> V_78 [ V_58 -> V_80 ] ;
V_973 -> V_89 = V_89 ;
V_973 -> V_166 = V_89 -> V_82 ;
V_973 -> V_167 = 1 ;
if ( F_519 ( V_89 ) ) {
V_986 |= F_520 ( V_89 ) << V_1030 ;
V_986 |= V_995 ;
} else if ( V_242 == F_147 ( V_247 ) ) {
struct V_235 * V_1055 , V_1056 ;
V_1055 = F_521 ( V_89 , V_245 , sizeof( V_1056 ) , & V_1056 ) ;
if ( ! V_1055 )
goto V_1057;
V_242 = V_1055 -> V_249 ;
V_986 |= F_522 ( V_1055 -> V_1058 ) <<
V_1030 ;
V_986 |= V_1032 ;
}
if ( F_24 ( F_151 ( V_89 ) -> V_986 & V_1059 &&
! F_523 ( V_1060 ,
& V_2 -> V_34 ) ) ) {
F_151 ( V_89 ) -> V_986 |= V_1061 ;
V_986 |= V_1007 ;
V_2 -> V_1062 = F_524 ( V_89 ) ;
V_2 -> V_1063 = V_170 ;
F_16 ( & V_2 -> V_1064 ) ;
}
F_525 ( V_89 ) ;
#ifdef F_282
if ( V_2 -> V_137 & V_430 )
V_986 |= V_996 ;
#endif
if ( ( V_2 -> V_137 & V_138 ) &&
( ( V_986 & ( V_995 | V_1032 ) ) ||
( V_89 -> V_1065 != V_1066 ) ) ) {
V_986 &= ~ V_1067 ;
V_986 |= ( V_89 -> V_1065 & 0x7 ) <<
V_1068 ;
if ( V_986 & V_1032 ) {
struct V_1069 * V_1055 ;
if ( F_482 ( V_89 , 0 ) )
goto V_1057;
V_1055 = (struct V_1069 * ) V_89 -> V_92 ;
V_1055 -> V_1058 = F_147 ( V_986 >>
V_1030 ) ;
} else {
V_986 |= V_995 ;
}
}
V_973 -> V_986 = V_986 ;
V_973 -> V_242 = V_242 ;
#ifdef F_148
if ( ( V_242 == F_147 ( V_254 ) ) &&
( V_58 -> V_55 -> V_195 & ( V_1070 | V_1071 ) ) ) {
V_1053 = F_526 ( V_58 , V_973 , & V_260 ) ;
if ( V_1053 < 0 )
goto V_1057;
goto V_1072;
}
#endif
V_1053 = F_480 ( V_58 , V_973 , & V_260 ) ;
if ( V_1053 < 0 )
goto V_1057;
else if ( ! V_1053 )
F_494 ( V_58 , V_973 ) ;
if ( F_14 ( V_394 , & V_58 -> V_34 ) )
F_506 ( V_58 , V_973 ) ;
#ifdef F_148
V_1072:
#endif
F_500 ( V_58 , V_973 , V_260 ) ;
F_511 ( V_58 , V_1073 ) ;
return V_1074 ;
V_1057:
F_78 ( V_973 -> V_89 ) ;
V_973 -> V_89 = NULL ;
return V_1074 ;
}
static T_15 F_527 ( struct V_194 * V_89 ,
struct V_54 * V_55 ,
struct V_57 * V_118 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_57 * V_58 ;
if ( F_24 ( V_89 -> V_82 < 17 ) ) {
if ( F_177 ( V_89 , 17 - V_89 -> V_82 ) )
return V_1074 ;
V_89 -> V_82 = 17 ;
F_528 ( V_89 , 17 ) ;
}
V_58 = V_118 ? V_118 : V_2 -> V_58 [ V_89 -> V_1049 ] ;
return F_517 ( V_89 , V_2 , V_58 ) ;
}
static T_15 F_529 ( struct V_194 * V_89 ,
struct V_54 * V_55 )
{
return F_527 ( V_89 , V_55 , NULL ) ;
}
static int F_530 ( struct V_54 * V_55 , void * V_1075 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1076 * V_554 = V_1075 ;
int V_152 ;
if ( ! F_344 ( V_554 -> V_1077 ) )
return - V_1078 ;
F_293 ( V_2 , V_14 -> V_108 . V_554 , F_266 ( 0 ) ) ;
memcpy ( V_55 -> V_635 , V_554 -> V_1077 , V_55 -> V_693 ) ;
memcpy ( V_14 -> V_108 . V_554 , V_554 -> V_1077 , V_55 -> V_693 ) ;
V_152 = F_290 ( V_2 , V_14 -> V_108 . V_554 , F_266 ( 0 ) ) ;
return V_152 > 0 ? 0 : V_152 ;
}
static int
F_531 ( struct V_54 * V_55 , int V_1079 , int V_1080 , T_2 V_554 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_4 ;
int V_1081 ;
if ( V_1079 != V_14 -> V_361 . V_1082 . V_1079 )
return - V_560 ;
V_1081 = V_14 -> V_361 . V_358 . V_1083 ( V_14 , V_554 , V_1080 , & V_4 ) ;
if ( ! V_1081 )
V_1081 = V_4 ;
return V_1081 ;
}
static int F_532 ( struct V_54 * V_55 , int V_1079 , int V_1080 ,
T_2 V_554 , T_2 V_4 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_1079 != V_14 -> V_361 . V_1082 . V_1079 )
return - V_560 ;
return V_14 -> V_361 . V_358 . V_1084 ( V_14 , V_554 , V_1080 , V_4 ) ;
}
static int F_533 ( struct V_54 * V_55 , struct V_1085 * V_1086 , int V_1087 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
switch ( V_1087 ) {
case V_1088 :
return F_534 ( V_2 , V_1086 ) ;
case V_1089 :
return F_535 ( V_2 , V_1086 ) ;
default:
return F_536 ( & V_2 -> V_14 . V_361 . V_1082 , F_537 ( V_1086 ) , V_1087 ) ;
}
}
static int F_538 ( struct V_54 * V_73 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_344 ( V_14 -> V_108 . V_1090 ) ) {
F_421 () ;
V_17 = F_539 ( V_73 , V_14 -> V_108 . V_1090 , V_1091 ) ;
F_423 () ;
V_14 -> V_108 . V_358 . V_695 ( V_14 , F_266 ( 0 ) ) ;
}
return V_17 ;
}
static int F_540 ( struct V_54 * V_73 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_1092 * V_108 = & V_2 -> V_14 . V_108 ;
if ( F_344 ( V_108 -> V_1090 ) ) {
F_421 () ;
V_17 = F_541 ( V_73 , V_108 -> V_1090 , V_1091 ) ;
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
V_2 -> V_137 |= V_271 ;
if ( V_2 -> V_137 & V_409 ) {
for ( V_48 = 0 ; V_48 < V_2 -> V_188 ; V_48 ++ )
F_223 ( 0 , V_2 -> V_157 [ V_48 ] ) ;
} else {
F_236 ( V_2 -> V_9 -> V_388 , V_55 ) ;
}
V_2 -> V_137 &= ~ V_271 ;
}
static struct V_1093 * F_543 ( struct V_54 * V_55 ,
struct V_1093 * V_122 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
int V_48 ;
F_544 () ;
for ( V_48 = 0 ; V_48 < V_2 -> V_93 ; V_48 ++ ) {
struct V_57 * V_118 = F_21 ( V_2 -> V_67 [ V_48 ] ) ;
T_6 V_169 , V_142 ;
unsigned int V_1094 ;
if ( V_118 ) {
do {
V_1094 = F_545 ( & V_118 -> V_168 ) ;
V_142 = V_118 -> V_122 . V_142 ;
V_169 = V_118 -> V_122 . V_169 ;
} while ( F_546 ( & V_118 -> V_168 , V_1094 ) );
V_122 -> V_801 += V_142 ;
V_122 -> V_800 += V_169 ;
}
}
for ( V_48 = 0 ; V_48 < V_2 -> V_77 ; V_48 ++ ) {
struct V_57 * V_118 = F_21 ( V_2 -> V_58 [ V_48 ] ) ;
T_6 V_169 , V_142 ;
unsigned int V_1094 ;
if ( V_118 ) {
do {
V_1094 = F_545 ( & V_118 -> V_168 ) ;
V_142 = V_118 -> V_122 . V_142 ;
V_169 = V_118 -> V_122 . V_169 ;
} while ( F_546 ( & V_118 -> V_168 , V_1094 ) );
V_122 -> V_803 += V_142 ;
V_122 -> V_802 += V_169 ;
}
}
F_547 () ;
V_122 -> V_910 = V_55 -> V_122 . V_910 ;
V_122 -> V_911 = V_55 -> V_122 . V_911 ;
V_122 -> V_913 = V_55 -> V_122 . V_913 ;
V_122 -> V_914 = V_55 -> V_122 . V_914 ;
V_122 -> V_915 = V_55 -> V_122 . V_915 ;
return V_122 ;
}
static void F_548 ( struct V_1 * V_2 , T_4 V_132 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_3 , V_1095 ;
int V_48 ;
if ( V_14 -> V_108 . type == V_109 )
return;
V_3 = F_37 ( V_14 , V_1096 ) ;
V_1095 = V_3 ;
for ( V_48 = 0 ; V_48 < V_606 ; V_48 ++ ) {
T_4 V_1097 = V_3 >> ( V_48 * V_1098 ) ;
if ( V_1097 > V_132 )
V_3 &= ~ ( 0x7 << V_1098 ) ;
}
if ( V_3 != V_1095 )
F_71 ( V_14 , V_1096 , V_3 ) ;
return;
}
static void F_549 ( struct V_1 * V_2 )
{
struct V_54 * V_73 = V_2 -> V_55 ;
struct V_1099 * V_134 = & V_2 -> V_134 ;
struct V_1100 * V_1101 = V_2 -> V_591 ;
T_4 V_1102 ;
for ( V_1102 = 0 ; V_1102 < V_1103 ; V_1102 ++ ) {
T_4 V_132 = 0 ;
if ( V_2 -> V_587 & V_588 )
V_132 = F_550 ( V_134 , 0 , V_1102 ) ;
else if ( V_1101 )
V_132 = V_1101 -> V_592 [ V_1102 ] ;
F_551 ( V_73 , V_1102 , V_132 ) ;
}
}
int F_552 ( struct V_54 * V_73 , T_4 V_132 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
bool V_1104 ;
if ( V_132 > V_2 -> V_134 . V_729 . V_730 ||
( V_14 -> V_108 . type == V_109 &&
V_132 < V_606 ) )
return - V_560 ;
V_1104 = ( F_553 ( & V_2 -> V_632 , 32 ) > 1 ) ;
if ( V_132 && V_1104 && V_2 -> V_633 > V_1105 )
return - V_767 ;
if ( F_57 ( V_73 ) )
F_411 ( V_73 ) ;
F_428 ( V_2 ) ;
#ifdef F_349
if ( V_132 ) {
F_554 ( V_73 , V_132 ) ;
F_549 ( V_2 ) ;
V_2 -> V_137 |= V_138 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ) {
V_2 -> V_1106 = V_2 -> V_14 . V_123 . V_744 ;
V_2 -> V_14 . V_123 . V_744 = V_1107 ;
}
} else {
F_555 ( V_73 ) ;
if ( V_2 -> V_14 . V_108 . type == V_109 )
V_2 -> V_14 . V_123 . V_744 = V_2 -> V_1106 ;
V_2 -> V_137 &= ~ V_138 ;
V_2 -> V_743 . V_135 = false ;
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
T_16 V_195 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
if ( ! ( V_195 & V_208 ) )
V_195 &= ~ V_1108 ;
if ( ! ( V_2 -> V_153 & V_715 ) )
V_195 &= ~ V_1108 ;
return V_195 ;
}
static int F_559 ( struct V_54 * V_55 ,
T_16 V_195 )
{
struct V_1 * V_2 = F_89 ( V_55 ) ;
T_16 V_1109 = V_55 -> V_195 ^ V_195 ;
bool V_1110 = false ;
if ( ! ( V_195 & V_1108 ) ) {
if ( V_2 -> V_153 & V_524 )
V_1110 = true ;
V_2 -> V_153 &= ~ V_524 ;
} else if ( ( V_2 -> V_153 & V_715 ) &&
! ( V_2 -> V_153 & V_524 ) ) {
if ( V_2 -> V_400 == 1 ||
V_2 -> V_400 > V_1111 ) {
V_2 -> V_153 |= V_524 ;
V_1110 = true ;
} else if ( ( V_1109 ^ V_195 ) & V_1108 ) {
F_104 ( V_171 , L_136
L_137 ) ;
}
}
switch ( V_195 & V_1112 ) {
case V_1112 :
if ( ! ( V_2 -> V_137 & V_608 ) )
V_1110 = true ;
V_2 -> V_137 &= ~ V_385 ;
V_2 -> V_137 |= V_608 ;
break;
default:
if ( V_2 -> V_137 & V_608 )
V_1110 = true ;
V_2 -> V_137 &= ~ V_608 ;
if ( V_2 -> V_137 & V_430 )
break;
if ( F_249 ( V_55 ) > 1 )
break;
if ( V_2 -> V_435 [ V_436 ] . V_714 <= 1 )
break;
if ( ! V_2 -> V_420 )
break;
V_2 -> V_137 |= V_385 ;
break;
}
if ( V_195 & V_268 )
F_279 ( V_2 ) ;
else
F_278 ( V_2 ) ;
if ( V_1109 & V_291 )
V_1110 = true ;
V_55 -> V_195 = V_195 ;
if ( V_1110 )
F_557 ( V_55 ) ;
return 0 ;
}
static int F_560 ( struct V_1113 * V_1114 , struct V_1115 * V_1116 [] ,
struct V_54 * V_73 ,
const unsigned char * V_554 ,
T_2 V_137 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
int V_17 ;
if ( ! ( V_2 -> V_137 & V_430 ) )
return F_561 ( V_1114 , V_1116 , V_73 , V_554 , V_137 ) ;
if ( V_1114 -> V_1117 && ! ( V_1114 -> V_1117 & V_1118 ) ) {
F_51 ( L_138 ,
V_1119 ) ;
return - V_560 ;
}
if ( F_562 ( V_554 ) || F_563 ( V_554 ) ) {
T_1 V_1120 = V_1121 ;
if ( F_296 ( V_73 ) < V_1120 )
V_17 = F_564 ( V_73 , V_554 ) ;
else
V_17 = - V_549 ;
} else if ( F_565 ( V_554 ) ) {
V_17 = F_566 ( V_73 , V_554 ) ;
} else {
V_17 = - V_560 ;
}
if ( V_17 == - V_1122 && ! ( V_137 & V_1123 ) )
V_17 = 0 ;
return V_17 ;
}
static int F_567 ( struct V_54 * V_73 ,
struct V_1124 * V_1125 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
struct V_1115 * V_1126 , * V_1127 ;
int V_1128 ;
if ( ! ( V_2 -> V_137 & V_430 ) )
return - V_1129 ;
V_1127 = F_568 ( V_1125 , sizeof( struct V_1130 ) , V_1131 ) ;
F_569 (attr, br_spec, rem) {
T_17 V_1132 ;
T_1 V_3 = 0 ;
if ( F_570 ( V_1126 ) != V_1133 )
continue;
V_1132 = F_571 ( V_1126 ) ;
if ( V_1132 == V_1134 ) {
V_3 = 0 ;
V_2 -> V_153 &= ~ V_498 ;
} else if ( V_1132 == V_1135 ) {
V_3 = V_500 ;
V_2 -> V_153 |= V_498 ;
} else
return - V_560 ;
F_71 ( & V_2 -> V_14 , V_499 , V_3 ) ;
F_104 ( V_155 , L_139 ,
V_1132 == V_1134 ? L_140 : L_141 ) ;
}
return 0 ;
}
static int F_572 ( struct V_194 * V_89 , T_1 V_1136 , T_1 V_1137 ,
struct V_54 * V_73 ,
T_1 V_1138 )
{
struct V_1 * V_2 = F_89 ( V_73 ) ;
T_2 V_1132 ;
if ( ! ( V_2 -> V_137 & V_430 ) )
return 0 ;
if ( V_2 -> V_153 & V_498 )
V_1132 = V_1135 ;
else
V_1132 = V_1134 ;
return F_573 ( V_89 , V_1136 , V_1137 , V_73 , V_1132 ) ;
}
static void * F_574 ( struct V_54 * V_9 , struct V_54 * V_626 )
{
struct V_622 * V_1045 = NULL ;
struct V_1 * V_2 = F_89 ( V_9 ) ;
unsigned int V_714 ;
int V_483 , V_17 ;
#ifdef F_575
if ( V_626 -> V_93 != V_626 -> V_77 ) {
F_576 ( V_9 , L_142 ,
V_626 -> V_53 ) ;
return F_577 ( - V_560 ) ;
}
#endif
if ( V_626 -> V_77 > V_770 ||
V_626 -> V_77 == V_1139 ) {
F_576 ( V_9 ,
L_143 ,
V_9 -> V_53 ) ;
return F_577 ( - V_560 ) ;
}
if ( ( ( V_2 -> V_137 & V_138 ) &&
V_2 -> V_633 > V_1105 - 1 ) ||
( V_2 -> V_633 > V_1140 ) )
return F_577 ( - V_767 ) ;
V_1045 = F_578 ( 1 , sizeof( struct V_622 ) , V_761 ) ;
if ( ! V_1045 )
return F_577 ( - V_549 ) ;
V_483 = F_553 ( & V_2 -> V_632 , 32 ) ;
V_2 -> V_633 ++ ;
F_245 ( V_483 , & V_2 -> V_632 ) ;
V_714 = F_579 ( & V_2 -> V_632 , 32 ) ;
V_2 -> V_137 |= V_581 | V_430 ;
V_2 -> V_435 [ V_502 ] . V_714 = V_714 + 1 ;
V_2 -> V_435 [ V_436 ] . V_714 = V_626 -> V_77 ;
V_17 = F_552 ( V_9 , F_249 ( V_9 ) ) ;
if ( V_17 )
goto V_1141;
V_1045 -> V_483 = V_483 ;
V_1045 -> V_146 = V_2 ;
V_17 = F_339 ( V_626 , V_1045 ) ;
if ( V_17 )
goto V_1141;
F_580 ( V_626 ) ;
return V_1045 ;
V_1141:
F_576 ( V_9 ,
L_144 , V_626 -> V_53 ) ;
F_34 ( V_483 , & V_2 -> V_632 ) ;
V_2 -> V_633 -- ;
F_235 ( V_1045 ) ;
return F_577 ( V_17 ) ;
}
static void F_581 ( struct V_54 * V_9 , void * V_1142 )
{
struct V_622 * V_1045 = V_1142 ;
struct V_1 * V_2 = V_1045 -> V_146 ;
unsigned int V_714 ;
F_34 ( V_1045 -> V_483 , & V_2 -> V_632 ) ;
V_2 -> V_633 -- ;
V_714 = F_579 ( & V_2 -> V_632 , 32 ) ;
V_2 -> V_435 [ V_502 ] . V_714 = V_714 + 1 ;
F_337 ( V_1045 -> V_55 , V_1045 ) ;
F_552 ( V_9 , F_249 ( V_9 ) ) ;
F_340 ( V_9 , L_92 ,
V_1045 -> V_483 , V_2 -> V_633 ,
V_1045 -> V_625 ,
V_1045 -> V_625 + V_2 -> V_624 ,
V_2 -> V_632 ) ;
F_235 ( V_1045 ) ;
}
static inline int F_582 ( struct V_1 * V_2 )
{
struct V_636 * V_405 ;
int V_1143 = 0 ;
if ( F_8 ( & V_2 -> V_14 ) ) {
V_1143 = 4 ;
} else {
F_583 (entry, &adapter->pdev->bus_list) {
struct V_5 * V_9 =
F_584 ( V_405 , struct V_5 , V_1144 ) ;
if ( ! V_9 -> V_1145 )
V_1143 ++ ;
}
}
return V_1143 ;
}
int F_585 ( struct V_1 * V_2 , T_2 V_21 ,
T_2 V_1146 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1147 = V_2 -> V_1148 & V_1149 ;
int V_1150 = 0 ;
switch ( V_21 ) {
case V_1151 :
switch ( V_1146 ) {
case V_1152 :
case V_1153 :
if ( V_14 -> V_10 . V_1154 != 0 )
break;
case V_1155 :
case V_1156 :
case V_1157 :
case V_1158 :
case V_1159 :
V_1150 = 1 ;
break;
}
break;
case V_1160 :
switch ( V_1146 ) {
case V_1161 :
V_1150 = 1 ;
break;
}
break;
case V_1162 :
if ( V_1146 != V_1163 )
V_1150 = 1 ;
break;
case V_1164 :
V_1150 = 1 ;
break;
case V_1165 :
case V_1166 :
if ( ( V_1147 == V_1167 ) ||
( ( V_1147 == V_1168 ) &&
( V_14 -> V_10 . V_1154 == 0 ) ) ) {
V_1150 = 1 ;
}
break;
}
return V_1150 ;
}
static int F_586 ( struct V_5 * V_9 , const struct V_1169 * V_1170 )
{
struct V_54 * V_55 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_14 ;
const struct V_1171 * V_1172 = V_1173 [ V_1170 -> V_1174 ] ;
static int V_1175 ;
int V_48 , V_17 , V_1176 , V_24 ;
unsigned int V_437 = V_1177 ;
T_4 V_1178 [ V_1179 ] ;
#ifdef F_148
T_2 V_1180 ;
#endif
T_1 V_1181 ;
if ( V_9 -> V_1145 ) {
F_587 ( 1 , V_1182 L_145 ,
F_588 ( V_9 ) , V_9 -> V_706 , V_9 -> V_189 ) ;
return - V_560 ;
}
V_17 = F_418 ( V_9 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_589 ( & V_9 -> V_73 , F_243 ( 64 ) ) ) {
V_1176 = 1 ;
} else {
V_17 = F_589 ( & V_9 -> V_73 , F_243 ( 32 ) ) ;
if ( V_17 ) {
F_395 ( & V_9 -> V_73 ,
L_146 ) ;
goto V_1183;
}
V_1176 = 0 ;
}
V_17 = F_590 ( V_9 , F_591 ( V_9 ,
V_1184 ) , V_1119 ) ;
if ( V_17 ) {
F_395 ( & V_9 -> V_73 ,
L_147 , V_17 ) ;
goto V_1185;
}
F_592 ( V_9 ) ;
F_419 ( V_9 ) ;
F_417 ( V_9 ) ;
if ( V_1172 -> V_108 == V_109 ) {
#ifdef F_349
V_437 = 4 * V_606 ;
#else
V_437 = V_713 ;
#endif
}
V_55 = F_593 ( sizeof( struct V_1 ) , V_437 ) ;
if ( ! V_55 ) {
V_17 = - V_549 ;
goto V_1186;
}
F_594 ( V_55 , & V_9 -> V_73 ) ;
V_2 = F_89 ( V_55 ) ;
F_595 ( V_9 , V_2 ) ;
V_2 -> V_55 = V_55 ;
V_2 -> V_9 = V_9 ;
V_14 = & V_2 -> V_14 ;
V_14 -> V_38 = V_2 ;
V_2 -> V_1187 = F_596 ( V_1188 , V_1189 ) ;
V_14 -> V_39 = F_597 ( F_598 ( V_9 , 0 ) ,
F_599 ( V_9 , 0 ) ) ;
V_2 -> V_418 = V_14 -> V_39 ;
if ( ! V_14 -> V_39 ) {
V_17 = - V_758 ;
goto V_1190;
}
V_55 -> V_1191 = & V_1192 ;
F_600 ( V_55 ) ;
V_55 -> V_1193 = 5 * V_968 ;
strncpy ( V_55 -> V_53 , F_588 ( V_9 ) , sizeof( V_55 -> V_53 ) - 1 ) ;
V_2 -> V_1194 = V_1175 ;
memcpy ( & V_14 -> V_108 . V_358 , V_1172 -> V_1195 , sizeof( V_14 -> V_108 . V_358 ) ) ;
V_14 -> V_108 . type = V_1172 -> V_108 ;
memcpy ( & V_14 -> V_1196 . V_358 , V_1172 -> V_1197 , sizeof( V_14 -> V_1196 . V_358 ) ) ;
V_1181 = F_37 ( V_14 , V_1198 ) ;
if ( F_22 ( V_14 -> V_39 ) ) {
V_17 = - V_758 ;
goto V_1190;
}
if ( ! ( V_1181 & ( 1 << 8 ) ) )
V_14 -> V_1196 . V_358 . V_228 = & V_1199 ;
memcpy ( & V_14 -> V_361 . V_358 , V_1172 -> V_1200 , sizeof( V_14 -> V_361 . V_358 ) ) ;
V_14 -> V_361 . V_954 = V_1201 ;
V_14 -> V_361 . V_1082 . V_1079 = V_1202 ;
V_14 -> V_361 . V_1082 . V_1203 = 0 ;
V_14 -> V_361 . V_1082 . V_1204 = V_1205 | V_1206 ;
V_14 -> V_361 . V_1082 . V_73 = V_55 ;
V_14 -> V_361 . V_1082 . V_1207 = F_531 ;
V_14 -> V_361 . V_1082 . V_1208 = F_532 ;
V_1172 -> V_1209 ( V_14 ) ;
V_17 = F_381 ( V_2 ) ;
if ( V_17 )
goto V_1210;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
case V_112 :
F_71 ( & V_2 -> V_14 , V_773 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_137 & V_364 ) {
T_1 V_680 = F_37 ( V_14 , V_681 ) ;
if ( V_680 & V_682 )
F_208 ( V_171 , L_73 ) ;
}
if ( V_1211 )
V_14 -> V_1211 = V_1211 ;
V_14 -> V_361 . V_1212 = true ;
V_17 = V_14 -> V_108 . V_358 . V_1213 ( V_14 ) ;
V_14 -> V_361 . V_1212 = false ;
if ( V_17 == V_689 &&
V_14 -> V_108 . type == V_109 ) {
V_17 = 0 ;
} else if ( V_17 == V_690 ) {
F_18 ( L_148 ) ;
F_18 ( L_149 ) ;
goto V_1210;
} else if ( V_17 ) {
F_18 ( L_150 , V_17 ) ;
goto V_1210;
}
#ifdef F_282
if ( V_2 -> V_14 . V_108 . type == V_109 )
goto V_1214;
F_601 ( V_14 ) ;
memcpy ( & V_14 -> V_1215 . V_358 , V_1172 -> V_1216 , sizeof( V_14 -> V_1215 . V_358 ) ) ;
F_602 ( V_9 , V_750 ) ;
F_603 ( V_2 ) ;
V_1214:
#endif
V_55 -> V_195 = V_1217 |
V_1218 |
V_1219 |
V_1220 |
V_268 |
V_1221 |
V_1222 |
V_1223 |
V_196 |
V_208 ;
V_55 -> V_1224 = V_55 -> V_195 | V_1225 ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
case V_112 :
V_55 -> V_195 |= V_1226 ;
V_55 -> V_1224 |= V_1226 |
V_1112 ;
break;
default:
break;
}
V_55 -> V_1224 |= V_291 ;
V_55 -> V_1227 |= V_1222 ;
V_55 -> V_1227 |= V_1223 ;
V_55 -> V_1227 |= V_1218 ;
V_55 -> V_1227 |= V_1219 ;
V_55 -> V_1227 |= V_1217 ;
V_55 -> V_1228 |= V_1229 ;
V_55 -> V_1228 |= V_1230 ;
#ifdef F_349
V_55 -> V_1231 = & V_1231 ;
#endif
#ifdef F_148
if ( V_2 -> V_137 & V_721 ) {
unsigned int V_1232 ;
if ( V_14 -> V_108 . V_358 . V_1233 ) {
V_14 -> V_108 . V_358 . V_1233 ( V_14 , & V_1180 ) ;
if ( V_1180 & V_1234 )
V_2 -> V_137 &= ~ V_721 ;
}
V_1232 = F_341 ( int , V_1235 , F_382 () ) ;
V_2 -> V_435 [ V_1051 ] . V_714 = V_1232 ;
V_55 -> V_195 |= V_1070 |
V_1071 ;
V_55 -> V_1227 |= V_1070 |
V_1071 |
V_586 ;
}
#endif
if ( V_1176 ) {
V_55 -> V_195 |= V_1236 ;
V_55 -> V_1227 |= V_1236 ;
}
if ( V_2 -> V_153 & V_715 )
V_55 -> V_1224 |= V_1108 ;
if ( V_2 -> V_153 & V_524 )
V_55 -> V_195 |= V_1108 ;
if ( V_14 -> V_1196 . V_358 . V_1237 ( V_14 , NULL ) < 0 ) {
F_18 ( L_151 ) ;
V_17 = - V_758 ;
goto V_1210;
}
memcpy ( V_55 -> V_635 , V_14 -> V_108 . V_1238 , V_55 -> V_693 ) ;
if ( ! F_344 ( V_55 -> V_635 ) ) {
F_18 ( L_152 ) ;
V_17 = - V_758 ;
goto V_1210;
}
F_289 ( V_2 , V_14 -> V_108 . V_1238 ) ;
F_604 ( & V_2 -> V_683 , & F_475 ,
( unsigned long ) V_2 ) ;
if ( F_22 ( V_14 -> V_39 ) ) {
V_17 = - V_758 ;
goto V_1210;
}
F_605 ( & V_2 -> V_37 , F_477 ) ;
F_245 ( V_40 , & V_2 -> V_34 ) ;
F_34 ( V_36 , & V_2 -> V_34 ) ;
V_17 = F_422 ( V_2 ) ;
if ( V_17 )
goto V_1210;
V_2 -> V_777 = 0 ;
V_14 -> V_1196 . V_358 . V_228 ( V_14 , 0x2c , & V_2 -> V_1148 ) ;
V_14 -> V_1239 = F_585 ( V_2 , V_9 -> V_189 ,
V_9 -> V_712 ) ;
if ( V_14 -> V_1239 )
V_2 -> V_777 = V_1240 ;
F_606 ( & V_2 -> V_9 -> V_73 , V_2 -> V_777 ) ;
V_14 -> V_1196 . V_358 . V_228 ( V_14 , 0x2e , & V_2 -> V_1241 ) ;
V_14 -> V_1196 . V_358 . V_228 ( V_14 , 0x2d , & V_2 -> V_1242 ) ;
V_14 -> V_108 . V_358 . V_1243 ( V_14 ) ;
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
F_9 ( V_2 , V_24 ) ;
V_17 = F_608 ( V_14 , V_1178 , V_1179 ) ;
if ( V_17 )
strncpy ( V_1178 , L_7 , V_1179 ) ;
if ( F_353 ( V_14 ) && V_14 -> V_361 . V_954 != V_1244 )
F_12 ( L_153 ,
V_14 -> V_108 . type , V_14 -> V_361 . type , V_14 -> V_361 . V_954 ,
V_1178 ) ;
else
F_12 ( L_154 ,
V_14 -> V_108 . type , V_14 -> V_361 . type , V_1178 ) ;
F_12 ( L_155 , V_55 -> V_635 ) ;
V_17 = V_14 -> V_108 . V_358 . V_1245 ( V_14 ) ;
if ( V_17 == V_692 ) {
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
goto V_1246;
if ( V_14 -> V_108 . V_358 . V_701 )
V_14 -> V_108 . V_358 . V_701 ( V_14 ) ;
F_374 ( V_55 ) ;
#ifdef F_226
if ( F_125 ( & V_9 -> V_73 ) == 0 ) {
V_2 -> V_137 |= V_186 ;
F_122 ( V_2 ) ;
}
#endif
if ( V_2 -> V_137 & V_430 ) {
F_104 ( V_171 , L_160 , V_2 -> V_325 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_325 ; V_48 ++ )
F_610 ( V_9 , ( V_48 | 0x10000000 ) ) ;
}
if ( V_14 -> V_108 . V_358 . V_1247 )
V_14 -> V_108 . V_358 . V_1247 ( V_14 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_538 ( V_55 ) ;
F_12 ( L_161 , V_1248 ) ;
V_1175 ++ ;
#ifdef F_611
if ( F_612 ( V_2 ) )
F_102 ( V_171 , L_162 ) ;
#endif
F_613 ( V_2 ) ;
if ( F_614 ( V_14 ) && F_353 ( V_14 ) && V_14 -> V_108 . V_358 . V_663 )
V_14 -> V_108 . V_358 . V_663 ( V_14 ,
V_922 | V_945 ,
true ) ;
return 0 ;
V_1246:
F_70 ( V_2 ) ;
F_428 ( V_2 ) ;
V_1210:
F_615 ( V_2 ) ;
V_2 -> V_153 &= ~ V_657 ;
F_616 ( V_2 -> V_418 ) ;
F_235 ( V_2 -> V_551 ) ;
V_1190:
F_617 ( V_55 ) ;
V_1186:
F_618 ( V_9 ,
F_591 ( V_9 , V_1184 ) ) ;
V_1185:
V_1183:
if ( ! F_15 ( V_772 , & V_2 -> V_34 ) )
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
if ( V_2 -> V_137 & V_186 ) {
V_2 -> V_137 &= ~ V_186 ;
F_126 ( & V_9 -> V_73 ) ;
F_71 ( & V_2 -> V_14 , V_187 , 1 ) ;
}
#endif
#ifdef F_611
F_622 ( V_2 ) ;
#endif
F_540 ( V_55 ) ;
if ( V_55 -> V_955 == V_956 )
F_471 ( V_55 ) ;
#ifdef F_282
if ( V_749 )
F_615 ( V_2 ) ;
#endif
F_428 ( V_2 ) ;
F_70 ( V_2 ) ;
#ifdef F_623
F_235 ( V_2 -> V_136 ) ;
F_235 ( V_2 -> V_591 ) ;
#endif
F_616 ( V_2 -> V_418 ) ;
F_618 ( V_9 , F_591 ( V_9 ,
V_1184 ) ) ;
F_12 ( L_163 ) ;
F_235 ( V_2 -> V_551 ) ;
F_617 ( V_55 ) ;
F_624 ( V_9 ) ;
if ( ! F_15 ( V_772 , & V_2 -> V_34 ) )
F_429 ( V_9 ) ;
}
static T_18 F_625 ( struct V_5 * V_9 ,
T_19 V_34 )
{
struct V_1 * V_2 = F_414 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
#ifdef F_282
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_1249 , * V_1250 ;
T_1 V_1251 , V_1252 , V_1253 , V_1254 ;
int V_957 , V_1255 ;
T_2 V_1256 , V_1257 ;
if ( V_2 -> V_14 . V_108 . type == V_109 ||
V_2 -> V_325 == 0 )
goto V_1258;
V_1249 = V_9 -> V_10 -> V_12 ;
while ( V_1249 && ( F_626 ( V_1249 ) != V_1259 ) )
V_1249 = V_1249 -> V_10 -> V_12 ;
if ( ! V_1249 )
goto V_1258;
V_1255 = F_627 ( V_1249 , V_1260 ) ;
if ( ! V_1255 )
goto V_1258;
V_1251 = F_27 ( V_14 , V_1255 + V_1261 ) ;
V_1252 = F_27 ( V_14 , V_1255 + V_1261 + 4 ) ;
V_1253 = F_27 ( V_14 , V_1255 + V_1261 + 8 ) ;
V_1254 = F_27 ( V_14 , V_1255 + V_1261 + 12 ) ;
if ( F_22 ( V_14 -> V_39 ) )
goto V_1258;
V_1256 = V_1252 >> 16 ;
if ( ! ( V_1256 & 0x0080 ) )
goto V_1258;
V_1257 = V_1256 & 0x01 ;
if ( ( V_1257 & 1 ) == ( V_9 -> V_1262 & 1 ) ) {
unsigned int V_21 ;
V_957 = ( V_1256 & 0x7F ) >> 1 ;
F_18 ( L_164 , V_957 ) ;
F_18 ( L_165
L_166 ,
V_1251 , V_1252 , V_1253 , V_1254 ) ;
switch ( V_2 -> V_14 . V_108 . type ) {
case V_111 :
V_21 = V_1263 ;
break;
case V_112 :
V_21 = V_1264 ;
break;
default:
V_21 = 0 ;
break;
}
V_1250 = F_628 ( V_1265 , V_21 , NULL ) ;
while ( V_1250 ) {
if ( V_1250 -> V_1262 == ( V_1256 & 0xFF ) )
break;
V_1250 = F_628 ( V_1265 ,
V_21 , V_1250 ) ;
}
if ( V_1250 ) {
F_18 ( L_167 , V_957 ) ;
F_629 ( V_1250 , 0xA8 , 0x00008000 ) ;
F_630 ( V_1250 ) ;
}
F_631 ( V_9 ) ;
}
V_2 -> V_1266 ++ ;
return V_1267 ;
V_1258:
#endif
if ( ! F_14 ( V_40 , & V_2 -> V_34 ) )
return V_1268 ;
F_421 () ;
F_427 ( V_55 ) ;
if ( V_34 == V_1269 ) {
F_423 () ;
return V_1268 ;
}
if ( F_57 ( V_55 ) )
F_363 ( V_2 ) ;
if ( ! F_15 ( V_772 , & V_2 -> V_34 ) )
F_429 ( V_9 ) ;
F_423 () ;
return V_1270 ;
}
static T_18 F_632 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_414 ( V_9 ) ;
T_18 V_1271 ;
int V_17 ;
if ( F_418 ( V_9 ) ) {
F_102 ( V_171 , L_168 ) ;
V_1271 = V_1268 ;
} else {
F_33 () ;
F_34 ( V_772 , & V_2 -> V_34 ) ;
V_2 -> V_14 . V_39 = V_2 -> V_418 ;
F_419 ( V_9 ) ;
F_416 ( V_9 ) ;
F_417 ( V_9 ) ;
F_420 ( V_9 , false ) ;
F_366 ( V_2 ) ;
F_71 ( & V_2 -> V_14 , V_773 , ~ 0 ) ;
V_1271 = V_1267 ;
}
V_17 = F_631 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_169
L_170 , V_17 ) ;
}
return V_1271 ;
}
static void F_633 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_414 ( V_9 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
#ifdef F_282
if ( V_2 -> V_1266 ) {
F_104 ( V_155 , L_171 ) ;
V_2 -> V_1266 -- ;
return;
}
#endif
if ( F_57 ( V_55 ) )
F_365 ( V_2 ) ;
F_424 ( V_55 ) ;
}
static int T_20 F_634 ( void )
{
int V_152 ;
F_51 ( L_172 , V_1272 , V_1273 ) ;
F_51 ( L_161 , V_1274 ) ;
F_635 () ;
V_152 = F_636 ( & V_1275 ) ;
if ( V_152 ) {
F_637 () ;
return V_152 ;
}
#ifdef F_226
F_638 ( & V_1276 ) ;
#endif
return 0 ;
}
static void T_21 F_639 ( void )
{
#ifdef F_226
F_640 ( & V_1276 ) ;
#endif
F_641 ( & V_1275 ) ;
F_637 () ;
F_642 () ;
}
static int F_643 ( struct V_1277 * V_1278 , unsigned long V_190 ,
void * V_1075 )
{
int V_1279 ;
V_1279 = F_644 ( & V_1275 . V_1280 , NULL , & V_190 ,
F_123 ) ;
return V_1279 ? V_1281 : V_1282 ;
}
