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
void F_19 ( struct V_15 * V_14 , T_1 V_3 )
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
static bool F_4 ( struct V_15 * V_14 , struct V_5 * V_9 )
{
T_2 V_4 ;
F_21 ( V_9 , V_43 , & V_4 ) ;
if ( V_4 == V_13 ) {
F_17 ( V_14 ) ;
return true ;
}
return false ;
}
T_2 F_22 ( struct V_15 * V_14 , T_1 V_3 )
{
struct V_1 * V_2 = V_14 -> V_38 ;
T_2 V_4 ;
if ( F_23 ( V_14 -> V_39 ) )
return V_13 ;
F_21 ( V_2 -> V_9 , V_3 , & V_4 ) ;
if ( V_4 == V_13 &&
F_4 ( V_14 , V_2 -> V_9 ) )
return V_13 ;
return V_4 ;
}
static T_1 F_24 ( struct V_15 * V_14 , T_1 V_3 )
{
struct V_1 * V_2 = V_14 -> V_38 ;
T_1 V_4 ;
if ( F_23 ( V_14 -> V_39 ) )
return V_44 ;
F_25 ( V_2 -> V_9 , V_3 , & V_4 ) ;
if ( V_4 == V_44 &&
F_4 ( V_14 , V_2 -> V_9 ) )
return V_44 ;
return V_4 ;
}
void F_26 ( struct V_15 * V_14 , T_1 V_3 , T_2 V_4 )
{
struct V_1 * V_2 = V_14 -> V_38 ;
if ( F_23 ( V_14 -> V_39 ) )
return;
F_27 ( V_2 -> V_9 , V_3 , V_4 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( ! F_14 ( V_36 , & V_2 -> V_34 ) ) ;
F_30 () ;
F_31 ( V_36 , & V_2 -> V_34 ) ;
}
static void F_32 ( struct V_15 * V_14 , struct V_45 * V_46 )
{
int V_47 = 0 , V_48 = 0 ;
char V_49 [ 16 ] ;
T_1 V_50 [ 64 ] ;
switch ( V_46 -> V_51 ) {
case F_33 ( 0 ) :
for ( V_47 = 0 ; V_47 < 64 ; V_47 ++ )
V_50 [ V_47 ] = F_34 ( V_14 , F_33 ( V_47 ) ) ;
break;
case F_35 ( 0 ) :
for ( V_47 = 0 ; V_47 < 64 ; V_47 ++ )
V_50 [ V_47 ] = F_34 ( V_14 , F_35 ( V_47 ) ) ;
break;
case F_36 ( 0 ) :
for ( V_47 = 0 ; V_47 < 64 ; V_47 ++ )
V_50 [ V_47 ] = F_34 ( V_14 , F_36 ( V_47 ) ) ;
break;
case F_37 ( 0 ) :
for ( V_47 = 0 ; V_47 < 64 ; V_47 ++ )
V_50 [ V_47 ] = F_34 ( V_14 , F_37 ( V_47 ) ) ;
break;
case F_38 ( 0 ) :
for ( V_47 = 0 ; V_47 < 64 ; V_47 ++ )
V_50 [ V_47 ] = F_34 ( V_14 , F_38 ( V_47 ) ) ;
break;
case F_39 ( 0 ) :
for ( V_47 = 0 ; V_47 < 64 ; V_47 ++ )
V_50 [ V_47 ] = F_34 ( V_14 , F_39 ( V_47 ) ) ;
break;
case F_40 ( 0 ) :
for ( V_47 = 0 ; V_47 < 64 ; V_47 ++ )
V_50 [ V_47 ] = F_34 ( V_14 , F_40 ( V_47 ) ) ;
break;
case F_41 ( 0 ) :
for ( V_47 = 0 ; V_47 < 64 ; V_47 ++ )
V_50 [ V_47 ] = F_34 ( V_14 , F_41 ( V_47 ) ) ;
break;
case F_42 ( 0 ) :
for ( V_47 = 0 ; V_47 < 64 ; V_47 ++ )
V_50 [ V_47 ] = F_34 ( V_14 , F_42 ( V_47 ) ) ;
break;
case F_43 ( 0 ) :
for ( V_47 = 0 ; V_47 < 64 ; V_47 ++ )
V_50 [ V_47 ] = F_34 ( V_14 , F_43 ( V_47 ) ) ;
break;
case F_44 ( 0 ) :
for ( V_47 = 0 ; V_47 < 64 ; V_47 ++ )
V_50 [ V_47 ] = F_34 ( V_14 , F_44 ( V_47 ) ) ;
break;
case F_45 ( 0 ) :
for ( V_47 = 0 ; V_47 < 64 ; V_47 ++ )
V_50 [ V_47 ] = F_34 ( V_14 , F_45 ( V_47 ) ) ;
break;
case F_46 ( 0 ) :
for ( V_47 = 0 ; V_47 < 64 ; V_47 ++ )
V_50 [ V_47 ] = F_34 ( V_14 , F_46 ( V_47 ) ) ;
break;
case F_47 ( 0 ) :
for ( V_47 = 0 ; V_47 < 64 ; V_47 ++ )
V_50 [ V_47 ] = F_34 ( V_14 , F_47 ( V_47 ) ) ;
break;
default:
F_48 ( L_14 , V_46 -> V_52 ,
F_34 ( V_14 , V_46 -> V_51 ) ) ;
return;
}
for ( V_47 = 0 ; V_47 < 8 ; V_47 ++ ) {
snprintf ( V_49 , 16 , L_15 , V_46 -> V_52 , V_47 * 8 , V_47 * 8 + 7 ) ;
F_49 ( L_16 , V_49 ) ;
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ )
F_50 ( L_17 , V_50 [ V_47 * 8 + V_48 ] ) ;
F_50 ( L_18 ) ;
}
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = V_2 -> V_54 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_45 * V_46 ;
int V_55 = 0 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
union V_60 * V_61 ;
struct V_62 { T_4 V_63 ; T_4 V_64 ; } * V_65 ;
struct V_56 * V_66 ;
union V_67 * V_68 ;
struct V_69 * V_70 ;
T_1 V_71 ;
int V_47 = 0 ;
if ( ! F_52 ( V_2 ) )
return;
if ( V_54 ) {
F_53 ( & V_2 -> V_9 -> V_72 , L_19 ) ;
F_48 ( L_20
L_21 ) ;
F_48 ( L_22 ,
V_54 -> V_52 ,
V_54 -> V_34 ,
V_54 -> V_73 ,
V_54 -> V_74 ) ;
}
F_53 ( & V_2 -> V_9 -> V_72 , L_23 ) ;
F_48 ( L_24 ) ;
for ( V_46 = (struct V_45 * ) V_75 ;
V_46 -> V_52 ; V_46 ++ ) {
F_32 ( V_14 , V_46 ) ;
}
if ( ! V_54 || ! F_54 ( V_54 ) )
goto exit;
F_53 ( & V_2 -> V_9 -> V_72 , L_25 ) ;
F_48 ( L_26 ,
L_27 ,
L_28 , L_29 , L_30 ) ;
for ( V_55 = 0 ; V_55 < V_2 -> V_76 ; V_55 ++ ) {
V_57 = V_2 -> V_57 [ V_55 ] ;
V_59 = & V_57 -> V_77 [ V_57 -> V_78 ] ;
F_48 ( L_31 ,
V_55 , V_57 -> V_79 , V_57 -> V_78 ,
( T_4 ) F_55 ( V_59 , V_80 ) ,
F_56 ( V_59 , V_81 ) ,
V_59 -> V_82 ,
( T_4 ) V_59 -> V_83 ) ;
}
if ( ! F_57 ( V_2 ) )
goto V_84;
F_53 ( & V_2 -> V_9 -> V_72 , L_32 ) ;
for ( V_55 = 0 ; V_55 < V_2 -> V_76 ; V_55 ++ ) {
V_57 = V_2 -> V_57 [ V_55 ] ;
F_48 ( L_33 ) ;
F_48 ( L_34 , V_57 -> V_85 ) ;
F_48 ( L_33 ) ;
F_48 ( L_35 ,
L_36 ,
L_37 ,
L_28 , L_29 , L_30 , L_38 ) ;
for ( V_47 = 0 ; V_57 -> V_86 && ( V_47 < V_57 -> V_87 ) ; V_47 ++ ) {
V_61 = F_58 ( V_57 , V_47 ) ;
V_59 = & V_57 -> V_77 [ V_47 ] ;
V_65 = (struct V_62 * ) V_61 ;
if ( F_56 ( V_59 , V_81 ) > 0 ) {
F_48 ( L_39 ,
V_47 ,
F_59 ( V_65 -> V_63 ) ,
F_59 ( V_65 -> V_64 ) ,
( T_4 ) F_55 ( V_59 , V_80 ) ,
F_56 ( V_59 , V_81 ) ,
V_59 -> V_82 ,
( T_4 ) V_59 -> V_83 ,
V_59 -> V_88 ) ;
if ( V_47 == V_57 -> V_79 &&
V_47 == V_57 -> V_78 )
F_50 ( L_40 ) ;
else if ( V_47 == V_57 -> V_79 )
F_50 ( L_41 ) ;
else if ( V_47 == V_57 -> V_78 )
F_50 ( L_42 ) ;
else
F_50 ( L_18 ) ;
if ( F_60 ( V_2 ) &&
V_59 -> V_88 )
F_61 ( V_89 , L_43 ,
V_90 , 16 , 1 ,
V_59 -> V_88 -> V_91 ,
F_56 ( V_59 , V_81 ) ,
true ) ;
}
}
}
V_84:
F_53 ( & V_2 -> V_9 -> V_72 , L_44 ) ;
F_48 ( L_45 ) ;
for ( V_55 = 0 ; V_55 < V_2 -> V_92 ; V_55 ++ ) {
V_66 = V_2 -> V_66 [ V_55 ] ;
F_48 ( L_46 ,
V_55 , V_66 -> V_79 , V_66 -> V_78 ) ;
}
if ( ! F_62 ( V_2 ) )
goto exit;
F_53 ( & V_2 -> V_9 -> V_72 , L_47 ) ;
for ( V_55 = 0 ; V_55 < V_2 -> V_92 ; V_55 ++ ) {
V_66 = V_2 -> V_66 [ V_55 ] ;
F_48 ( L_33 ) ;
F_48 ( L_48 , V_66 -> V_85 ) ;
F_48 ( L_33 ) ;
F_48 ( L_49 ,
L_50 ,
L_51 ,
L_52 ) ;
F_48 ( L_49 ,
L_53 ,
L_54 ,
L_55 ) ;
for ( V_47 = 0 ; V_47 < V_66 -> V_87 ; V_47 ++ ) {
V_70 = & V_66 -> V_70 [ V_47 ] ;
V_68 = F_63 ( V_66 , V_47 ) ;
V_65 = (struct V_62 * ) V_68 ;
V_71 = F_64 ( V_68 -> V_93 . V_94 . V_95 ) ;
if ( V_71 & V_96 ) {
F_48 ( L_56
L_57 , V_47 ,
F_59 ( V_65 -> V_63 ) ,
F_59 ( V_65 -> V_64 ) ,
V_70 -> V_88 ) ;
} else {
F_48 ( L_58
L_59 , V_47 ,
F_59 ( V_65 -> V_63 ) ,
F_59 ( V_65 -> V_64 ) ,
( T_4 ) V_70 -> V_80 ,
V_70 -> V_88 ) ;
if ( F_60 ( V_2 ) &&
V_70 -> V_80 ) {
F_61 ( V_89 , L_43 ,
V_90 , 16 , 1 ,
F_65 ( V_70 -> V_97 ) +
V_70 -> V_98 ,
F_66 ( V_66 ) , true ) ;
}
}
if ( V_47 == V_66 -> V_79 )
F_50 ( L_41 ) ;
else if ( V_47 == V_66 -> V_78 )
F_50 ( L_42 ) ;
else
F_50 ( L_18 ) ;
}
}
exit:
return;
}
static void F_67 ( struct V_1 * V_2 )
{
T_1 V_99 ;
V_99 = F_34 ( & V_2 -> V_14 , V_100 ) ;
F_68 ( & V_2 -> V_14 , V_100 ,
V_99 & ~ V_101 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
T_1 V_99 ;
V_99 = F_34 ( & V_2 -> V_14 , V_100 ) ;
F_68 ( & V_2 -> V_14 , V_100 ,
V_99 | V_101 ) ;
}
static void F_70 ( struct V_1 * V_2 , T_5 V_102 ,
T_6 V_103 , T_6 V_104 )
{
T_1 V_105 , V_106 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_107 . type ) {
case V_108 :
V_104 |= V_109 ;
if ( V_102 == - 1 )
V_102 = 0 ;
V_106 = ( ( ( V_102 * 64 ) + V_103 ) >> 2 ) & 0x1F ;
V_105 = F_34 ( V_14 , F_71 ( V_106 ) ) ;
V_105 &= ~ ( 0xFF << ( 8 * ( V_103 & 0x3 ) ) ) ;
V_105 |= ( V_104 << ( 8 * ( V_103 & 0x3 ) ) ) ;
F_68 ( V_14 , F_71 ( V_106 ) , V_105 ) ;
break;
case V_110 :
case V_111 :
if ( V_102 == - 1 ) {
V_104 |= V_109 ;
V_106 = ( ( V_103 & 1 ) * 8 ) ;
V_105 = F_34 ( & V_2 -> V_14 , V_112 ) ;
V_105 &= ~ ( 0xFF << V_106 ) ;
V_105 |= ( V_104 << V_106 ) ;
F_68 ( & V_2 -> V_14 , V_112 , V_105 ) ;
break;
} else {
V_104 |= V_109 ;
V_106 = ( ( 16 * ( V_103 & 1 ) ) + ( 8 * V_102 ) ) ;
V_105 = F_34 ( V_14 , F_71 ( V_103 >> 1 ) ) ;
V_105 &= ~ ( 0xFF << V_106 ) ;
V_105 |= ( V_104 << V_106 ) ;
F_68 ( V_14 , F_71 ( V_103 >> 1 ) , V_105 ) ;
break;
}
default:
break;
}
}
static inline void F_72 ( struct V_1 * V_2 ,
T_4 V_113 )
{
T_1 V_114 ;
switch ( V_2 -> V_14 . V_107 . type ) {
case V_108 :
V_114 = ( V_115 & V_113 ) ;
F_68 ( & V_2 -> V_14 , V_116 , V_114 ) ;
break;
case V_110 :
case V_111 :
V_114 = ( V_113 & 0xFFFFFFFF ) ;
F_68 ( & V_2 -> V_14 , F_73 ( 0 ) , V_114 ) ;
V_114 = ( V_113 >> 32 ) ;
F_68 ( & V_2 -> V_14 , F_73 ( 1 ) , V_114 ) ;
break;
default:
break;
}
}
void F_74 ( struct V_56 * V_117 ,
struct V_58 * V_59 )
{
if ( V_59 -> V_88 ) {
F_75 ( V_59 -> V_88 ) ;
if ( F_56 ( V_59 , V_81 ) )
F_76 ( V_117 -> V_72 ,
F_55 ( V_59 , V_80 ) ,
F_56 ( V_59 , V_81 ) ,
V_118 ) ;
} else if ( F_56 ( V_59 , V_81 ) ) {
F_77 ( V_117 -> V_72 ,
F_55 ( V_59 , V_80 ) ,
F_56 ( V_59 , V_81 ) ,
V_118 ) ;
}
V_59 -> V_82 = NULL ;
V_59 -> V_88 = NULL ;
F_78 ( V_59 , V_81 , 0 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_119 * V_120 = & V_2 -> V_121 ;
int V_47 ;
T_1 V_91 ;
if ( ( V_14 -> V_122 . V_123 != V_124 ) &&
( V_14 -> V_122 . V_123 != V_125 ) )
return;
switch ( V_14 -> V_107 . type ) {
case V_108 :
V_91 = F_34 ( V_14 , V_126 ) ;
break;
default:
V_91 = F_34 ( V_14 , V_127 ) ;
}
V_120 -> V_128 += V_91 ;
if ( ! V_91 )
return;
for ( V_47 = 0 ; V_47 < V_2 -> V_76 ; V_47 ++ )
F_31 ( V_129 ,
& V_2 -> V_57 [ V_47 ] -> V_34 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_119 * V_120 = & V_2 -> V_121 ;
T_1 V_130 [ 8 ] = { 0 } ;
T_6 V_131 ;
int V_47 ;
bool V_132 = V_2 -> V_133 . V_134 ;
if ( V_2 -> V_135 )
V_132 |= ! ! ( V_2 -> V_135 -> V_132 ) ;
if ( ! ( V_2 -> V_136 & V_137 ) || ! V_132 ) {
F_79 ( V_2 ) ;
return;
}
for ( V_47 = 0 ; V_47 < V_138 ; V_47 ++ ) {
T_1 V_139 ;
switch ( V_14 -> V_107 . type ) {
case V_108 :
V_139 = F_34 ( V_14 , F_81 ( V_47 ) ) ;
break;
default:
V_139 = F_34 ( V_14 , F_82 ( V_47 ) ) ;
}
V_120 -> V_139 [ V_47 ] += V_139 ;
V_131 = F_83 ( V_2 -> V_54 , V_47 ) ;
V_130 [ V_131 ] += V_139 ;
}
for ( V_47 = 0 ; V_47 < V_2 -> V_76 ; V_47 ++ ) {
struct V_56 * V_57 = V_2 -> V_57 [ V_47 ] ;
V_131 = V_57 -> V_140 ;
if ( V_130 [ V_131 ] )
F_31 ( V_129 , & V_57 -> V_34 ) ;
}
}
static T_4 F_84 ( struct V_56 * V_117 )
{
return V_117 -> V_121 . V_141 ;
}
static T_4 F_85 ( struct V_56 * V_117 )
{
struct V_1 * V_2 ;
struct V_15 * V_14 ;
T_1 V_142 , V_143 ;
if ( V_117 -> V_144 )
V_2 = V_117 -> V_144 -> V_145 ;
else
V_2 = F_86 ( V_117 -> V_54 ) ;
V_14 = & V_2 -> V_14 ;
V_142 = F_34 ( V_14 , F_45 ( V_117 -> V_146 ) ) ;
V_143 = F_34 ( V_14 , F_46 ( V_117 -> V_146 ) ) ;
if ( V_142 != V_143 )
return ( V_142 < V_143 ) ?
V_143 - V_142 : ( V_143 + V_117 -> V_87 - V_142 ) ;
return 0 ;
}
static inline bool F_87 ( struct V_56 * V_57 )
{
T_1 V_147 = F_84 ( V_57 ) ;
T_1 V_148 = V_57 -> V_149 . V_148 ;
T_1 V_150 = F_85 ( V_57 ) ;
bool V_151 = false ;
F_88 ( V_57 ) ;
if ( ( V_148 == V_147 ) && V_150 ) {
V_151 = F_15 ( V_129 ,
& V_57 -> V_34 ) ;
} else {
V_57 -> V_149 . V_148 = V_147 ;
F_31 ( V_129 , & V_57 -> V_34 ) ;
}
return V_151 ;
}
static void F_89 ( struct V_1 * V_2 )
{
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_152 |= V_153 ;
F_90 ( V_154 , L_60 ) ;
F_13 ( V_2 ) ;
}
}
static bool F_91 ( struct V_155 * V_156 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = V_156 -> V_2 ;
struct V_58 * V_59 ;
union V_60 * V_61 ;
unsigned int V_157 = 0 , V_158 = 0 ;
unsigned int V_159 = V_156 -> V_160 . V_161 ;
unsigned int V_47 = V_57 -> V_78 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return true ;
V_59 = & V_57 -> V_77 [ V_47 ] ;
V_61 = F_58 ( V_57 , V_47 ) ;
V_47 -= V_57 -> V_87 ;
do {
union V_60 * V_162 = V_59 -> V_82 ;
if ( ! V_162 )
break;
F_92 () ;
if ( ! ( V_162 -> V_93 . V_163 & F_93 ( V_164 ) ) )
break;
V_59 -> V_82 = NULL ;
V_157 += V_59 -> V_165 ;
V_158 += V_59 -> V_166 ;
F_75 ( V_59 -> V_88 ) ;
F_76 ( V_57 -> V_72 ,
F_55 ( V_59 , V_80 ) ,
F_56 ( V_59 , V_81 ) ,
V_118 ) ;
V_59 -> V_88 = NULL ;
F_78 ( V_59 , V_81 , 0 ) ;
while ( V_61 != V_162 ) {
V_59 ++ ;
V_61 ++ ;
V_47 ++ ;
if ( F_94 ( ! V_47 ) ) {
V_47 -= V_57 -> V_87 ;
V_59 = V_57 -> V_77 ;
V_61 = F_58 ( V_57 , 0 ) ;
}
if ( F_56 ( V_59 , V_81 ) ) {
F_77 ( V_57 -> V_72 ,
F_55 ( V_59 , V_80 ) ,
F_56 ( V_59 , V_81 ) ,
V_118 ) ;
F_78 ( V_59 , V_81 , 0 ) ;
}
}
V_59 ++ ;
V_61 ++ ;
V_47 ++ ;
if ( F_94 ( ! V_47 ) ) {
V_47 -= V_57 -> V_87 ;
V_59 = V_57 -> V_77 ;
V_61 = F_58 ( V_57 , 0 ) ;
}
F_95 ( V_61 ) ;
V_159 -- ;
} while ( F_96 ( V_159 ) );
V_47 += V_57 -> V_87 ;
V_57 -> V_78 = V_47 ;
F_97 ( & V_57 -> V_167 ) ;
V_57 -> V_121 . V_168 += V_157 ;
V_57 -> V_121 . V_141 += V_158 ;
F_98 ( & V_57 -> V_167 ) ;
V_156 -> V_160 . V_157 += V_157 ;
V_156 -> V_160 . V_158 += V_158 ;
if ( F_99 ( V_57 ) && F_87 ( V_57 ) ) {
struct V_15 * V_14 = & V_2 -> V_14 ;
F_100 ( V_154 , L_61
L_62
L_63
L_64
L_65
L_66
L_67
L_68 ,
V_57 -> V_85 ,
F_34 ( V_14 , F_45 ( V_57 -> V_146 ) ) ,
F_34 ( V_14 , F_46 ( V_57 -> V_146 ) ) ,
V_57 -> V_79 , V_47 ,
V_57 -> V_77 [ V_47 ] . V_83 , V_169 ) ;
F_101 ( V_57 -> V_54 , V_57 -> V_85 ) ;
F_102 ( V_170 ,
L_69 ,
V_2 -> V_171 + 1 , V_57 -> V_85 ) ;
F_89 ( V_2 ) ;
return true ;
}
F_103 ( F_104 ( V_57 ) ,
V_158 , V_157 ) ;
#define F_105 (DESC_NEEDED * 2)
if ( F_94 ( V_158 && F_106 ( V_57 -> V_54 ) &&
( F_107 ( V_57 ) >= F_105 ) ) ) {
F_108 () ;
if ( F_109 ( V_57 -> V_54 ,
V_57 -> V_85 )
&& ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
F_110 ( V_57 -> V_54 ,
V_57 -> V_85 ) ;
++ V_57 -> V_149 . V_172 ;
}
}
return ! ! V_159 ;
}
static void F_111 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
int V_173 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_174 = F_112 ( V_57 -> V_72 , V_173 ) ;
T_2 V_175 ;
switch ( V_14 -> V_107 . type ) {
case V_108 :
V_175 = F_113 ( V_57 -> V_146 ) ;
break;
case V_110 :
case V_111 :
V_175 = F_114 ( V_57 -> V_146 ) ;
V_174 <<= V_176 ;
break;
default:
return;
}
V_174 |= V_177 |
V_178 |
V_179 ;
F_68 ( V_14 , V_175 , V_174 ) ;
}
static void F_115 ( struct V_1 * V_2 ,
struct V_56 * V_66 ,
int V_173 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_180 = F_112 ( V_66 -> V_72 , V_173 ) ;
T_6 V_146 = V_66 -> V_146 ;
switch ( V_14 -> V_107 . type ) {
case V_110 :
case V_111 :
V_180 <<= V_181 ;
break;
default:
break;
}
V_180 |= V_182 |
V_183 ;
F_68 ( V_14 , F_35 ( V_146 ) , V_180 ) ;
}
static void F_116 ( struct V_155 * V_156 )
{
struct V_1 * V_2 = V_156 -> V_2 ;
struct V_56 * V_117 ;
int V_173 = F_117 () ;
if ( V_156 -> V_173 == V_173 )
goto V_184;
F_118 (ring, q_vector->tx)
F_111 ( V_2 , V_117 , V_173 ) ;
F_118 (ring, q_vector->rx)
F_115 ( V_2 , V_117 , V_173 ) ;
V_156 -> V_173 = V_173 ;
V_184:
F_119 () ;
}
static void F_120 ( struct V_1 * V_2 )
{
int V_47 ;
if ( ! ( V_2 -> V_136 & V_185 ) )
return;
F_68 ( & V_2 -> V_14 , V_186 , 2 ) ;
for ( V_47 = 0 ; V_47 < V_2 -> V_187 ; V_47 ++ ) {
V_2 -> V_156 [ V_47 ] -> V_173 = - 1 ;
F_116 ( V_2 -> V_156 [ V_47 ] ) ;
}
}
static int F_121 ( struct V_188 * V_72 , void * V_91 )
{
struct V_1 * V_2 = F_122 ( V_72 ) ;
unsigned long V_189 = * ( unsigned long * ) V_91 ;
if ( ! ( V_2 -> V_136 & V_190 ) )
return 0 ;
switch ( V_189 ) {
case V_191 :
if ( V_2 -> V_136 & V_185 )
break;
if ( F_123 ( V_72 ) == 0 ) {
V_2 -> V_136 |= V_185 ;
F_120 ( V_2 ) ;
break;
}
case V_192 :
if ( V_2 -> V_136 & V_185 ) {
F_124 ( V_72 ) ;
V_2 -> V_136 &= ~ V_185 ;
F_68 ( & V_2 -> V_14 , V_186 , 1 ) ;
}
break;
}
return 0 ;
}
static inline void F_125 ( struct V_56 * V_117 ,
union V_67 * V_68 ,
struct V_193 * V_88 )
{
if ( V_117 -> V_54 -> V_194 & V_195 )
F_126 ( V_88 ,
F_64 ( V_68 -> V_93 . V_196 . V_197 . V_198 ) ,
V_199 ) ;
}
static inline bool F_127 ( struct V_56 * V_117 ,
union V_67 * V_68 )
{
T_7 V_200 = V_68 -> V_93 . V_196 . V_201 . V_202 . V_200 ;
return F_14 ( V_203 , & V_117 -> V_34 ) &&
( ( V_200 & F_128 ( V_204 ) ) ==
( F_128 ( V_205 <<
V_206 ) ) ) ;
}
static inline void F_129 ( struct V_56 * V_117 ,
union V_67 * V_68 ,
struct V_193 * V_88 )
{
F_130 ( V_88 ) ;
if ( ! ( V_117 -> V_54 -> V_194 & V_207 ) )
return;
if ( F_131 ( V_68 , V_208 ) &&
F_131 ( V_68 , V_209 ) ) {
V_117 -> V_210 . V_211 ++ ;
return;
}
if ( ! F_131 ( V_68 , V_212 ) )
return;
if ( F_131 ( V_68 , V_213 ) ) {
T_7 V_200 = V_68 -> V_93 . V_196 . V_201 . V_202 . V_200 ;
if ( ( V_200 & F_128 ( V_214 ) ) &&
F_14 ( V_215 , & V_117 -> V_34 ) )
return;
V_117 -> V_210 . V_211 ++ ;
return;
}
V_88 -> V_216 = V_217 ;
}
static inline void F_132 ( struct V_56 * V_66 , T_1 V_218 )
{
V_66 -> V_79 = V_218 ;
V_66 -> V_219 = V_218 ;
F_133 () ;
F_134 ( V_66 , V_218 ) ;
}
static bool F_135 ( struct V_56 * V_66 ,
struct V_69 * V_220 )
{
struct V_97 * V_97 = V_220 -> V_97 ;
T_8 V_80 = V_220 -> V_80 ;
if ( F_96 ( V_80 ) )
return true ;
if ( F_96 ( ! V_97 ) ) {
V_97 = F_136 ( V_221 | V_222 | V_223 ,
V_220 -> V_88 , F_137 ( V_66 ) ) ;
if ( F_94 ( ! V_97 ) ) {
V_66 -> V_210 . V_224 ++ ;
return false ;
}
V_220 -> V_97 = V_97 ;
}
V_80 = F_138 ( V_66 -> V_72 , V_97 , 0 ,
F_139 ( V_66 ) , V_225 ) ;
if ( F_140 ( V_66 -> V_72 , V_80 ) ) {
F_141 ( V_97 , F_137 ( V_66 ) ) ;
V_220 -> V_97 = NULL ;
V_66 -> V_210 . V_224 ++ ;
return false ;
}
V_220 -> V_80 = V_80 ;
V_220 -> V_98 = 0 ;
return true ;
}
void F_142 ( struct V_56 * V_66 , T_2 V_226 )
{
union V_67 * V_68 ;
struct V_69 * V_220 ;
T_2 V_47 = V_66 -> V_79 ;
if ( ! V_226 )
return;
V_68 = F_63 ( V_66 , V_47 ) ;
V_220 = & V_66 -> V_70 [ V_47 ] ;
V_47 -= V_66 -> V_87 ;
do {
if ( ! F_135 ( V_66 , V_220 ) )
break;
V_68 -> V_227 . V_228 = F_143 ( V_220 -> V_80 + V_220 -> V_98 ) ;
V_68 ++ ;
V_220 ++ ;
V_47 ++ ;
if ( F_94 ( ! V_47 ) ) {
V_68 = F_63 ( V_66 , 0 ) ;
V_220 = V_66 -> V_70 ;
V_47 -= V_66 -> V_87 ;
}
V_68 -> V_227 . V_229 = 0 ;
V_226 -- ;
} while ( V_226 );
V_47 += V_66 -> V_87 ;
if ( V_66 -> V_79 != V_47 )
F_132 ( V_66 , V_47 ) ;
}
static unsigned int F_144 ( unsigned char * V_91 ,
unsigned int V_230 )
{
union {
unsigned char * V_231 ;
struct V_232 * V_233 ;
struct V_234 * V_235 ;
struct V_236 * V_237 ;
struct V_238 * V_239 ;
} V_240 ;
T_9 V_241 ;
T_6 V_242 = 0 ;
T_6 V_243 ;
if ( V_230 < V_244 )
return V_230 ;
V_240 . V_231 = V_91 ;
V_241 = V_240 . V_233 -> V_245 ;
V_240 . V_231 += V_244 ;
if ( V_241 == F_145 ( V_246 ) ) {
if ( ( V_240 . V_231 - V_91 ) > ( V_230 - V_247 ) )
return V_230 ;
V_241 = V_240 . V_235 -> V_248 ;
V_240 . V_231 += V_247 ;
}
if ( V_241 == F_145 ( V_249 ) ) {
if ( ( V_240 . V_231 - V_91 ) > ( V_230 - sizeof( struct V_236 ) ) )
return V_230 ;
V_243 = ( V_240 . V_231 [ 0 ] & 0x0F ) << 2 ;
if ( V_243 < sizeof( struct V_236 ) )
return V_240 . V_231 - V_91 ;
if ( ! ( V_240 . V_237 -> V_250 & F_145 ( V_251 ) ) )
V_242 = V_240 . V_237 -> V_241 ;
} else if ( V_241 == F_145 ( V_252 ) ) {
if ( ( V_240 . V_231 - V_91 ) > ( V_230 - sizeof( struct V_238 ) ) )
return V_230 ;
V_242 = V_240 . V_239 -> V_242 ;
V_243 = sizeof( struct V_238 ) ;
#ifdef F_146
} else if ( V_241 == F_145 ( V_253 ) ) {
if ( ( V_240 . V_231 - V_91 ) > ( V_230 - V_254 ) )
return V_230 ;
V_243 = V_254 ;
#endif
} else {
return V_240 . V_231 - V_91 ;
}
V_240 . V_231 += V_243 ;
if ( V_242 == V_255 ) {
if ( ( V_240 . V_231 - V_91 ) > ( V_230 - sizeof( struct V_256 ) ) )
return V_230 ;
V_243 = ( V_240 . V_231 [ 12 ] & 0xF0 ) >> 2 ;
if ( V_243 < sizeof( struct V_256 ) )
return V_240 . V_231 - V_91 ;
V_240 . V_231 += V_243 ;
} else if ( V_242 == V_257 ) {
if ( ( V_240 . V_231 - V_91 ) > ( V_230 - sizeof( struct V_258 ) ) )
return V_230 ;
V_240 . V_231 += sizeof( struct V_258 ) ;
}
if ( ( V_240 . V_231 - V_91 ) < V_230 )
return V_240 . V_231 - V_91 ;
else
return V_230 ;
}
static void F_147 ( struct V_56 * V_117 ,
struct V_193 * V_88 )
{
T_2 V_259 = F_148 ( V_88 ) ;
F_149 ( V_88 ) -> V_260 = F_150 ( ( V_88 -> V_81 - V_259 ) ,
F_151 ( V_88 ) -> V_261 ) ;
F_149 ( V_88 ) -> V_262 = V_263 ;
}
static void F_152 ( struct V_56 * V_66 ,
struct V_193 * V_88 )
{
if ( ! F_151 ( V_88 ) -> V_261 )
return;
V_66 -> V_210 . V_264 += F_151 ( V_88 ) -> V_261 ;
V_66 -> V_210 . V_265 ++ ;
F_147 ( V_66 , V_88 ) ;
F_151 ( V_88 ) -> V_261 = 0 ;
}
static void F_153 ( struct V_56 * V_66 ,
union V_67 * V_68 ,
struct V_193 * V_88 )
{
struct V_53 * V_72 = V_66 -> V_54 ;
F_152 ( V_66 , V_88 ) ;
F_125 ( V_66 , V_68 , V_88 ) ;
F_129 ( V_66 , V_68 , V_88 ) ;
if ( F_94 ( F_131 ( V_68 , V_266 ) ) )
F_154 ( V_66 -> V_156 -> V_2 , V_88 ) ;
if ( ( V_72 -> V_194 & V_267 ) &&
F_131 ( V_68 , V_268 ) ) {
T_2 V_269 = F_155 ( V_68 -> V_93 . V_94 . V_235 ) ;
F_156 ( V_88 , F_145 ( V_246 ) , V_269 ) ;
}
F_157 ( V_88 , V_66 -> V_85 ) ;
V_88 -> V_241 = F_158 ( V_88 , V_72 ) ;
}
static void F_159 ( struct V_155 * V_156 ,
struct V_193 * V_88 )
{
struct V_1 * V_2 = V_156 -> V_2 ;
if ( F_160 ( V_156 ) )
F_161 ( V_88 ) ;
else if ( ! ( V_2 -> V_136 & V_270 ) )
F_162 ( & V_156 -> V_271 , V_88 ) ;
else
F_163 ( V_88 ) ;
}
static bool F_164 ( struct V_56 * V_66 ,
union V_67 * V_68 ,
struct V_193 * V_88 )
{
T_1 V_272 = V_66 -> V_78 + 1 ;
V_272 = ( V_272 < V_66 -> V_87 ) ? V_272 : 0 ;
V_66 -> V_78 = V_272 ;
F_95 ( F_63 ( V_66 , V_272 ) ) ;
if ( F_165 ( V_66 ) ) {
T_10 V_273 = V_68 -> V_93 . V_196 . V_201 . V_91 &
F_93 ( V_274 ) ;
if ( F_94 ( V_273 ) ) {
T_1 V_275 = F_64 ( V_273 ) ;
V_275 >>= V_276 ;
F_151 ( V_88 ) -> V_261 += V_275 - 1 ;
V_272 = F_64 ( V_68 -> V_93 . V_94 . V_95 ) ;
V_272 &= V_277 ;
V_272 >>= V_278 ;
}
}
if ( F_96 ( F_131 ( V_68 , V_279 ) ) )
return false ;
V_66 -> V_70 [ V_272 ] . V_88 = V_88 ;
V_66 -> V_210 . V_280 ++ ;
return true ;
}
static void F_166 ( struct V_56 * V_66 ,
struct V_193 * V_88 )
{
struct V_281 * V_282 = & F_149 ( V_88 ) -> V_283 [ 0 ] ;
unsigned char * V_284 ;
unsigned int V_285 ;
V_284 = F_167 ( V_282 ) ;
V_285 = F_144 ( V_284 , V_286 ) ;
F_168 ( V_88 , V_284 , F_169 ( V_285 , sizeof( long ) ) ) ;
F_170 ( V_282 , V_285 ) ;
V_282 -> V_98 += V_285 ;
V_88 -> V_287 -= V_285 ;
V_88 -> V_143 += V_285 ;
}
static void F_171 ( struct V_56 * V_66 ,
struct V_193 * V_88 )
{
if ( F_94 ( F_151 ( V_88 ) -> V_288 ) ) {
F_77 ( V_66 -> V_72 , F_151 ( V_88 ) -> V_80 ,
F_139 ( V_66 ) , V_225 ) ;
F_151 ( V_88 ) -> V_288 = false ;
} else {
struct V_281 * V_282 = & F_149 ( V_88 ) -> V_283 [ 0 ] ;
F_172 ( V_66 -> V_72 ,
F_151 ( V_88 ) -> V_80 ,
V_282 -> V_98 ,
F_66 ( V_66 ) ,
V_225 ) ;
}
F_151 ( V_88 ) -> V_80 = 0 ;
}
static bool F_173 ( struct V_56 * V_66 ,
union V_67 * V_68 ,
struct V_193 * V_88 )
{
struct V_53 * V_54 = V_66 -> V_54 ;
if ( F_94 ( F_131 ( V_68 ,
V_289 ) &&
! ( V_54 -> V_194 & V_290 ) ) ) {
F_75 ( V_88 ) ;
return true ;
}
if ( F_174 ( V_88 ) )
F_166 ( V_66 , V_88 ) ;
#ifdef F_146
if ( F_127 ( V_66 , V_68 ) )
return false ;
#endif
if ( F_94 ( V_88 -> V_81 < 60 ) ) {
int V_291 = 60 - V_88 -> V_81 ;
if ( F_175 ( V_88 , V_291 ) )
return true ;
F_176 ( V_88 , V_291 ) ;
}
return false ;
}
static void F_177 ( struct V_56 * V_66 ,
struct V_69 * V_292 )
{
struct V_69 * V_293 ;
T_2 V_294 = V_66 -> V_219 ;
V_293 = & V_66 -> V_70 [ V_294 ] ;
V_294 ++ ;
V_66 -> V_219 = ( V_294 < V_66 -> V_87 ) ? V_294 : 0 ;
V_293 -> V_97 = V_292 -> V_97 ;
V_293 -> V_80 = V_292 -> V_80 ;
V_293 -> V_98 = V_292 -> V_98 ;
F_178 ( V_66 -> V_72 , V_293 -> V_80 ,
V_293 -> V_98 ,
F_66 ( V_66 ) ,
V_225 ) ;
}
static bool F_179 ( struct V_56 * V_66 ,
struct V_69 * V_295 ,
union V_67 * V_68 ,
struct V_193 * V_88 )
{
struct V_97 * V_97 = V_295 -> V_97 ;
unsigned int V_296 = F_155 ( V_68 -> V_93 . V_94 . V_297 ) ;
#if ( V_298 < 8192 )
unsigned int V_299 = F_66 ( V_66 ) ;
#else
unsigned int V_299 = F_169 ( V_296 , V_300 ) ;
unsigned int V_301 = F_139 ( V_66 ) -
F_66 ( V_66 ) ;
#endif
if ( ( V_296 <= V_286 ) && ! F_174 ( V_88 ) ) {
unsigned char * V_284 = F_65 ( V_97 ) + V_295 -> V_98 ;
memcpy ( F_176 ( V_88 , V_296 ) , V_284 , F_169 ( V_296 , sizeof( long ) ) ) ;
if ( F_96 ( F_180 ( V_97 ) == F_181 () ) )
return true ;
F_182 ( V_97 ) ;
return false ;
}
F_183 ( V_88 , F_149 ( V_88 ) -> V_302 , V_97 ,
V_295 -> V_98 , V_296 , V_299 ) ;
if ( F_94 ( F_180 ( V_97 ) != F_181 () ) )
return false ;
#if ( V_298 < 8192 )
if ( F_94 ( F_184 ( V_97 ) != 1 ) )
return false ;
V_295 -> V_98 ^= V_299 ;
F_185 ( & V_97 -> V_303 , 2 ) ;
#else
V_295 -> V_98 += V_299 ;
if ( V_295 -> V_98 > V_301 )
return false ;
F_186 ( V_97 ) ;
#endif
return true ;
}
static struct V_193 * F_187 ( struct V_56 * V_66 ,
union V_67 * V_68 )
{
struct V_69 * V_295 ;
struct V_193 * V_88 ;
struct V_97 * V_97 ;
V_295 = & V_66 -> V_70 [ V_66 -> V_78 ] ;
V_97 = V_295 -> V_97 ;
F_188 ( V_97 ) ;
V_88 = V_295 -> V_88 ;
if ( F_96 ( ! V_88 ) ) {
void * V_304 = F_65 ( V_97 ) +
V_295 -> V_98 ;
F_95 ( V_304 ) ;
#if V_300 < 128
F_95 ( V_304 + V_300 ) ;
#endif
V_88 = F_189 ( V_66 -> V_54 ,
V_286 ) ;
if ( F_94 ( ! V_88 ) ) {
V_66 -> V_210 . V_305 ++ ;
return NULL ;
}
F_188 ( V_88 -> V_91 ) ;
if ( F_96 ( F_131 ( V_68 , V_279 ) ) )
goto V_306;
F_151 ( V_88 ) -> V_80 = V_295 -> V_80 ;
} else {
if ( F_131 ( V_68 , V_279 ) )
F_171 ( V_66 , V_88 ) ;
V_306:
F_172 ( V_66 -> V_72 ,
V_295 -> V_80 ,
V_295 -> V_98 ,
F_66 ( V_66 ) ,
V_225 ) ;
}
if ( F_179 ( V_66 , V_295 , V_68 , V_88 ) ) {
F_177 ( V_66 , V_295 ) ;
} else if ( F_151 ( V_88 ) -> V_80 == V_295 -> V_80 ) {
F_151 ( V_88 ) -> V_288 = true ;
} else {
F_77 ( V_66 -> V_72 , V_295 -> V_80 ,
F_139 ( V_66 ) ,
V_225 ) ;
}
V_295 -> V_88 = NULL ;
V_295 -> V_80 = 0 ;
V_295 -> V_97 = NULL ;
return V_88 ;
}
static int F_190 ( struct V_155 * V_156 ,
struct V_56 * V_66 ,
const int V_159 )
{
unsigned int V_307 = 0 , V_308 = 0 ;
#ifdef F_146
struct V_1 * V_2 = V_156 -> V_2 ;
int V_309 ;
unsigned int V_310 = 0 ;
#endif
T_2 V_226 = F_107 ( V_66 ) ;
while ( F_96 ( V_308 < V_159 ) ) {
union V_67 * V_68 ;
struct V_193 * V_88 ;
if ( V_226 >= V_311 ) {
F_142 ( V_66 , V_226 ) ;
V_226 = 0 ;
}
V_68 = F_63 ( V_66 , V_66 -> V_78 ) ;
if ( ! F_131 ( V_68 , V_96 ) )
break;
F_191 () ;
V_88 = F_187 ( V_66 , V_68 ) ;
if ( ! V_88 )
break;
V_226 ++ ;
if ( F_164 ( V_66 , V_68 , V_88 ) )
continue;
if ( F_173 ( V_66 , V_68 , V_88 ) )
continue;
V_307 += V_88 -> V_81 ;
F_153 ( V_66 , V_68 , V_88 ) ;
#ifdef F_146
if ( F_127 ( V_66 , V_68 ) ) {
V_309 = F_192 ( V_2 , V_68 , V_88 ) ;
if ( V_309 > 0 ) {
if ( ! V_310 ) {
V_310 = V_66 -> V_54 -> V_312 -
sizeof( struct V_313 ) -
sizeof( struct V_314 ) -
sizeof( struct V_315 ) ;
if ( V_310 > 512 )
V_310 &= ~ 511 ;
}
V_307 += V_309 ;
V_308 += F_150 ( V_309 ,
V_310 ) ;
}
if ( ! V_309 ) {
F_75 ( V_88 ) ;
continue;
}
}
#endif
F_193 ( V_88 , & V_156 -> V_271 ) ;
F_159 ( V_156 , V_88 ) ;
V_308 ++ ;
}
F_97 ( & V_66 -> V_167 ) ;
V_66 -> V_121 . V_141 += V_308 ;
V_66 -> V_121 . V_168 += V_307 ;
F_98 ( & V_66 -> V_167 ) ;
V_156 -> V_316 . V_158 += V_308 ;
V_156 -> V_316 . V_157 += V_307 ;
if ( V_226 )
F_142 ( V_66 , V_226 ) ;
return V_308 ;
}
static int F_194 ( struct V_317 * V_271 )
{
struct V_155 * V_156 =
F_195 ( V_271 , struct V_155 , V_271 ) ;
struct V_1 * V_2 = V_156 -> V_2 ;
struct V_56 * V_117 ;
int V_318 = 0 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return V_319 ;
if ( ! F_196 ( V_156 ) )
return V_320 ;
F_118 (ring, q_vector->rx) {
V_318 = F_190 ( V_156 , V_117 , 4 ) ;
#ifdef F_197
if ( V_318 )
V_117 -> V_121 . V_321 += V_318 ;
else
V_117 -> V_121 . V_322 ++ ;
#endif
if ( V_318 )
break;
}
F_198 ( V_156 ) ;
return V_318 ;
}
static void F_199 ( struct V_1 * V_2 )
{
struct V_155 * V_156 ;
int V_323 ;
T_1 V_114 ;
if ( V_2 -> V_324 > 32 ) {
T_1 V_325 = ( 1 << ( V_2 -> V_324 - 32 ) ) - 1 ;
F_68 ( & V_2 -> V_14 , V_326 , V_325 ) ;
}
for ( V_323 = 0 ; V_323 < V_2 -> V_187 ; V_323 ++ ) {
struct V_56 * V_117 ;
V_156 = V_2 -> V_156 [ V_323 ] ;
F_118 (ring, q_vector->rx)
F_70 ( V_2 , 0 , V_117 -> V_146 , V_323 ) ;
F_118 (ring, q_vector->tx)
F_70 ( V_2 , 1 , V_117 -> V_146 , V_323 ) ;
F_200 ( V_156 ) ;
}
switch ( V_2 -> V_14 . V_107 . type ) {
case V_108 :
F_70 ( V_2 , - 1 , V_327 ,
V_323 ) ;
break;
case V_110 :
case V_111 :
F_70 ( V_2 , - 1 , 1 , V_323 ) ;
break;
default:
break;
}
F_68 ( & V_2 -> V_14 , F_201 ( V_323 ) , 1950 ) ;
V_114 = V_328 ;
V_114 &= ~ ( V_329 |
V_330 |
V_331 ) ;
F_68 ( & V_2 -> V_14 , V_332 , V_114 ) ;
}
static void F_202 ( struct V_155 * V_156 ,
struct V_333 * V_334 )
{
int V_168 = V_334 -> V_157 ;
int V_141 = V_334 -> V_158 ;
T_1 V_335 ;
T_4 V_336 ;
T_6 V_337 = V_334 -> V_338 ;
if ( V_141 == 0 )
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
void F_200 ( struct V_155 * V_156 )
{
struct V_1 * V_2 = V_156 -> V_2 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_323 = V_156 -> V_323 ;
T_1 V_342 = V_156 -> V_338 & V_343 ;
switch ( V_2 -> V_14 . V_107 . type ) {
case V_108 :
V_342 |= ( V_342 << 16 ) ;
break;
case V_110 :
case V_111 :
V_342 |= V_344 ;
break;
default:
break;
}
F_68 ( V_14 , F_201 ( V_323 ) , V_342 ) ;
}
static void F_203 ( struct V_155 * V_156 )
{
T_1 V_345 = V_156 -> V_338 ;
T_6 V_346 ;
F_202 ( V_156 , & V_156 -> V_160 ) ;
F_202 ( V_156 , & V_156 -> V_316 ) ;
V_346 = F_204 ( V_156 -> V_316 . V_338 , V_156 -> V_160 . V_338 ) ;
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
F_200 ( V_156 ) ;
}
}
static void F_205 ( struct V_1 * V_2 )
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
if ( ! ( V_350 & V_356 ) && V_14 -> V_107 . V_357 . V_358 ) {
T_1 V_20 ;
bool V_359 = false ;
V_14 -> V_107 . V_357 . V_358 ( V_14 , & V_20 , & V_359 , false ) ;
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
F_206 ( V_154 ,
L_70
L_71
L_72 ) ;
V_2 -> V_351 = 0 ;
}
static void F_207 ( struct V_1 * V_2 , T_1 V_350 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( ( V_2 -> V_136 & V_363 ) &&
( V_350 & V_364 ) ) {
F_206 ( V_170 , L_73 ) ;
F_68 ( V_14 , V_365 , V_364 ) ;
}
}
static void F_208 ( struct V_1 * V_2 , T_1 V_350 )
{
if ( ! ( V_2 -> V_152 & V_352 ) )
return;
switch ( V_2 -> V_14 . V_107 . type ) {
case V_110 :
if ( ( ( V_350 & V_355 ) || ( V_350 & V_356 ) ) &&
( ! F_14 ( V_33 , & V_2 -> V_34 ) ) ) {
V_2 -> V_351 = V_350 ;
V_2 -> V_152 |= V_353 ;
F_13 ( V_2 ) ;
return;
}
return;
case V_111 :
if ( ! ( V_350 & V_366 ) )
return;
break;
default:
return;
}
F_206 ( V_154 ,
L_70
L_71
L_72 ) ;
}
static void F_209 ( struct V_1 * V_2 , T_1 V_350 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_350 & V_367 ) {
F_68 ( V_14 , V_365 , V_367 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_152 |= V_368 ;
F_13 ( V_2 ) ;
}
}
if ( V_350 & V_364 ) {
F_68 ( V_14 , V_365 , V_364 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
V_2 -> V_136 |= V_369 ;
F_13 ( V_2 ) ;
}
}
}
static void F_210 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_370 ++ ;
V_2 -> V_136 |= V_371 ;
V_2 -> V_372 = V_169 ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
F_68 ( V_14 , V_373 , V_374 ) ;
F_211 ( V_14 ) ;
F_13 ( V_2 ) ;
}
}
static inline void F_212 ( struct V_1 * V_2 ,
T_4 V_113 )
{
T_1 V_114 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_107 . type ) {
case V_108 :
V_114 = ( V_115 & V_113 ) ;
F_68 ( V_14 , V_375 , V_114 ) ;
break;
case V_110 :
case V_111 :
V_114 = ( V_113 & 0xFFFFFFFF ) ;
if ( V_114 )
F_68 ( V_14 , F_213 ( 0 ) , V_114 ) ;
V_114 = ( V_113 >> 32 ) ;
if ( V_114 )
F_68 ( V_14 , F_213 ( 1 ) , V_114 ) ;
break;
default:
break;
}
}
static inline void F_214 ( struct V_1 * V_2 ,
T_4 V_113 )
{
T_1 V_114 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_107 . type ) {
case V_108 :
V_114 = ( V_115 & V_113 ) ;
F_68 ( V_14 , V_373 , V_114 ) ;
break;
case V_110 :
case V_111 :
V_114 = ( V_113 & 0xFFFFFFFF ) ;
if ( V_114 )
F_68 ( V_14 , F_215 ( 0 ) , V_114 ) ;
V_114 = ( V_113 >> 32 ) ;
if ( V_114 )
F_68 ( V_14 , F_215 ( 1 ) , V_114 ) ;
break;
default:
break;
}
}
static inline void F_216 ( struct V_1 * V_2 , bool V_376 ,
bool V_377 )
{
T_1 V_114 = ( V_328 & ~ V_115 ) ;
if ( V_2 -> V_136 & V_371 )
V_114 &= ~ V_331 ;
if ( V_2 -> V_152 & V_352 )
switch ( V_2 -> V_14 . V_107 . type ) {
case V_110 :
V_114 |= V_378 ;
break;
case V_111 :
V_114 |= V_379 ;
break;
default:
break;
}
if ( V_2 -> V_136 & V_363 )
V_114 |= V_380 ;
switch ( V_2 -> V_14 . V_107 . type ) {
case V_110 :
V_114 |= V_380 ;
V_114 |= V_381 ;
case V_111 :
V_114 |= V_382 ;
V_114 |= V_330 ;
break;
default:
break;
}
if ( V_2 -> V_14 . V_107 . type == V_111 )
V_114 |= V_383 ;
if ( ( V_2 -> V_136 & V_384 ) &&
! ( V_2 -> V_152 & V_385 ) )
V_114 |= V_386 ;
F_68 ( & V_2 -> V_14 , V_375 , V_114 ) ;
if ( V_376 )
F_212 ( V_2 , ~ 0 ) ;
if ( V_377 )
F_211 ( & V_2 -> V_14 ) ;
}
static T_11 F_217 ( int V_387 , void * V_91 )
{
struct V_1 * V_2 = V_91 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_350 ;
V_350 = F_34 ( V_14 , V_116 ) ;
V_350 &= 0xFFFF0000 ;
F_68 ( V_14 , V_365 , V_350 ) ;
if ( V_350 & V_356 )
F_210 ( V_2 ) ;
if ( V_350 & V_388 )
F_218 ( V_2 ) ;
switch ( V_14 -> V_107 . type ) {
case V_110 :
case V_111 :
if ( V_350 & V_389 ) {
F_102 ( V_390 , L_74 ) ;
V_2 -> V_152 |= V_153 ;
F_13 ( V_2 ) ;
F_68 ( V_14 , V_365 , V_389 ) ;
}
if ( V_350 & V_391 ) {
int V_392 = 0 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_76 ; V_47 ++ ) {
struct V_56 * V_117 = V_2 -> V_57 [ V_47 ] ;
if ( F_219 ( V_393 ,
& V_117 -> V_34 ) )
V_392 ++ ;
}
if ( V_392 ) {
F_68 ( V_14 , V_373 , V_394 ) ;
V_2 -> V_152 |= V_385 ;
F_13 ( V_2 ) ;
}
}
F_209 ( V_2 , V_350 ) ;
F_208 ( V_2 , V_350 ) ;
break;
default:
break;
}
F_207 ( V_2 , V_350 ) ;
if ( F_94 ( V_350 & V_395 ) )
F_220 ( V_2 , V_350 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_216 ( V_2 , false , false ) ;
return V_396 ;
}
static T_11 F_221 ( int V_387 , void * V_91 )
{
struct V_155 * V_156 = V_91 ;
if ( V_156 -> V_316 . V_117 || V_156 -> V_160 . V_117 )
F_222 ( & V_156 -> V_271 ) ;
return V_396 ;
}
int F_223 ( struct V_317 * V_271 , int V_159 )
{
struct V_155 * V_156 =
F_195 ( V_271 , struct V_155 , V_271 ) ;
struct V_1 * V_2 = V_156 -> V_2 ;
struct V_56 * V_117 ;
int V_397 ;
bool V_398 = true ;
#ifdef F_224
if ( V_2 -> V_136 & V_185 )
F_116 ( V_156 ) ;
#endif
F_118 (ring, q_vector->tx)
V_398 &= ! ! F_91 ( V_156 , V_117 ) ;
if ( ! F_225 ( V_156 ) )
return V_159 ;
if ( V_156 -> V_316 . V_87 > 1 )
V_397 = F_204 ( V_159 / V_156 -> V_316 . V_87 , 1 ) ;
else
V_397 = V_159 ;
F_118 (ring, q_vector->rx)
V_398 &= ( F_190 ( V_156 , V_117 ,
V_397 ) < V_397 ) ;
F_226 ( V_156 ) ;
if ( ! V_398 )
return V_159 ;
F_227 ( V_271 ) ;
if ( V_2 -> V_399 & 1 )
F_203 ( V_156 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_212 ( V_2 , ( ( T_4 ) 1 << V_156 -> V_323 ) ) ;
return 0 ;
}
static int F_228 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = V_2 -> V_54 ;
int V_400 , V_17 ;
int V_401 = 0 , V_402 = 0 ;
for ( V_400 = 0 ; V_400 < V_2 -> V_187 ; V_400 ++ ) {
struct V_155 * V_156 = V_2 -> V_156 [ V_400 ] ;
struct V_403 * V_404 = & V_2 -> V_405 [ V_400 ] ;
if ( V_156 -> V_160 . V_117 && V_156 -> V_316 . V_117 ) {
snprintf ( V_156 -> V_52 , sizeof( V_156 -> V_52 ) - 1 ,
L_75 , V_54 -> V_52 , L_76 , V_401 ++ ) ;
V_402 ++ ;
} else if ( V_156 -> V_316 . V_117 ) {
snprintf ( V_156 -> V_52 , sizeof( V_156 -> V_52 ) - 1 ,
L_75 , V_54 -> V_52 , L_77 , V_401 ++ ) ;
} else if ( V_156 -> V_160 . V_117 ) {
snprintf ( V_156 -> V_52 , sizeof( V_156 -> V_52 ) - 1 ,
L_75 , V_54 -> V_52 , L_78 , V_402 ++ ) ;
} else {
continue;
}
V_17 = F_229 ( V_404 -> V_400 , & F_221 , 0 ,
V_156 -> V_52 , V_156 ) ;
if ( V_17 ) {
F_100 ( V_170 , L_79
L_80 , V_17 ) ;
goto V_406;
}
if ( V_2 -> V_136 & V_384 ) {
F_230 ( V_404 -> V_400 ,
& V_156 -> V_407 ) ;
}
}
V_17 = F_229 ( V_2 -> V_405 [ V_400 ] . V_400 ,
F_217 , 0 , V_54 -> V_52 , V_2 ) ;
if ( V_17 ) {
F_100 ( V_170 , L_81 , V_17 ) ;
goto V_406;
}
return 0 ;
V_406:
while ( V_400 ) {
V_400 -- ;
F_230 ( V_2 -> V_405 [ V_400 ] . V_400 ,
NULL ) ;
F_231 ( V_2 -> V_405 [ V_400 ] . V_400 ,
V_2 -> V_156 [ V_400 ] ) ;
}
V_2 -> V_136 &= ~ V_408 ;
F_232 ( V_2 -> V_9 ) ;
F_233 ( V_2 -> V_405 ) ;
V_2 -> V_405 = NULL ;
return V_17 ;
}
static T_11 F_234 ( int V_387 , void * V_91 )
{
struct V_1 * V_2 = V_91 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_155 * V_156 = V_2 -> V_156 [ 0 ] ;
T_1 V_350 ;
F_68 ( V_14 , V_373 , V_409 ) ;
V_350 = F_34 ( V_14 , V_365 ) ;
if ( ! V_350 ) {
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_216 ( V_2 , true , true ) ;
return V_410 ;
}
if ( V_350 & V_356 )
F_210 ( V_2 ) ;
switch ( V_14 -> V_107 . type ) {
case V_110 :
F_209 ( V_2 , V_350 ) ;
case V_111 :
if ( V_350 & V_389 ) {
F_102 ( V_390 , L_74 ) ;
V_2 -> V_152 |= V_153 ;
F_13 ( V_2 ) ;
F_68 ( V_14 , V_365 , V_389 ) ;
}
F_208 ( V_2 , V_350 ) ;
break;
default:
break;
}
F_207 ( V_2 , V_350 ) ;
if ( F_94 ( V_350 & V_395 ) )
F_220 ( V_2 , V_350 ) ;
F_222 ( & V_156 -> V_271 ) ;
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) )
F_216 ( V_2 , false , false ) ;
return V_396 ;
}
static int F_235 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = V_2 -> V_54 ;
int V_17 ;
if ( V_2 -> V_136 & V_408 )
V_17 = F_228 ( V_2 ) ;
else if ( V_2 -> V_136 & V_411 )
V_17 = F_229 ( V_2 -> V_9 -> V_387 , F_234 , 0 ,
V_54 -> V_52 , V_2 ) ;
else
V_17 = F_229 ( V_2 -> V_9 -> V_387 , F_234 , V_412 ,
V_54 -> V_52 , V_2 ) ;
if ( V_17 )
F_100 ( V_170 , L_82 , V_17 ) ;
return V_17 ;
}
static void F_236 ( struct V_1 * V_2 )
{
int V_400 ;
if ( ! ( V_2 -> V_136 & V_408 ) ) {
F_231 ( V_2 -> V_9 -> V_387 , V_2 ) ;
return;
}
for ( V_400 = 0 ; V_400 < V_2 -> V_187 ; V_400 ++ ) {
struct V_155 * V_156 = V_2 -> V_156 [ V_400 ] ;
struct V_403 * V_404 = & V_2 -> V_405 [ V_400 ] ;
if ( ! V_156 -> V_316 . V_117 && ! V_156 -> V_160 . V_117 )
continue;
F_230 ( V_404 -> V_400 , NULL ) ;
F_231 ( V_404 -> V_400 , V_156 ) ;
}
F_231 ( V_2 -> V_405 [ V_400 ++ ] . V_400 , V_2 ) ;
}
static inline void F_237 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_14 . V_107 . type ) {
case V_108 :
F_68 ( & V_2 -> V_14 , V_373 , ~ 0 ) ;
break;
case V_110 :
case V_111 :
F_68 ( & V_2 -> V_14 , V_373 , 0xFFFF0000 ) ;
F_68 ( & V_2 -> V_14 , F_215 ( 0 ) , ~ 0 ) ;
F_68 ( & V_2 -> V_14 , F_215 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_211 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_136 & V_408 ) {
int V_400 ;
for ( V_400 = 0 ; V_400 < V_2 -> V_187 ; V_400 ++ )
F_238 ( V_2 -> V_405 [ V_400 ] . V_400 ) ;
F_238 ( V_2 -> V_405 [ V_400 ++ ] . V_400 ) ;
} else {
F_238 ( V_2 -> V_9 -> V_387 ) ;
}
}
static void F_239 ( struct V_1 * V_2 )
{
struct V_155 * V_156 = V_2 -> V_156 [ 0 ] ;
F_200 ( V_156 ) ;
F_70 ( V_2 , 0 , 0 , 0 ) ;
F_70 ( V_2 , 1 , 0 , 0 ) ;
F_102 ( V_14 , L_83 ) ;
}
void F_240 ( struct V_1 * V_2 ,
struct V_56 * V_117 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_413 = V_117 -> V_80 ;
int V_414 = 10 ;
T_1 V_415 = V_416 ;
T_6 V_146 = V_117 -> V_146 ;
F_68 ( V_14 , F_47 ( V_146 ) , 0 ) ;
F_211 ( V_14 ) ;
F_68 ( V_14 , F_42 ( V_146 ) ,
( V_413 & F_241 ( 32 ) ) ) ;
F_68 ( V_14 , F_43 ( V_146 ) , ( V_413 >> 32 ) ) ;
F_68 ( V_14 , F_44 ( V_146 ) ,
V_117 -> V_87 * sizeof( union V_60 ) ) ;
F_68 ( V_14 , F_45 ( V_146 ) , 0 ) ;
F_68 ( V_14 , F_46 ( V_146 ) , 0 ) ;
V_117 -> V_143 = V_2 -> V_417 + F_46 ( V_146 ) ;
#if F_242 ( V_418 )
if ( ! V_117 -> V_156 || ( V_117 -> V_156 -> V_338 < V_347 ) )
#else
if ( ! V_117 -> V_156 || ( V_117 -> V_156 -> V_338 < 8 ) )
#endif
V_415 |= ( 1 << 16 ) ;
else
V_415 |= ( 8 << 16 ) ;
V_415 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_136 & V_384 ) {
V_117 -> V_419 = V_2 -> V_419 ;
V_117 -> V_420 = 0 ;
F_243 ( V_393 , & V_117 -> V_34 ) ;
} else {
V_117 -> V_419 = 0 ;
}
if ( ! F_15 ( V_421 , & V_117 -> V_34 ) ) {
struct V_155 * V_156 = V_117 -> V_156 ;
if ( V_156 )
F_244 ( V_117 -> V_54 ,
& V_156 -> V_407 ,
V_117 -> V_85 ) ;
}
F_31 ( V_129 , & V_117 -> V_34 ) ;
F_68 ( V_14 , F_47 ( V_146 ) , V_415 ) ;
if ( V_14 -> V_107 . type == V_108 &&
! ( F_34 ( V_14 , V_422 ) & V_423 ) )
return;
do {
F_245 ( 1000 , 2000 ) ;
V_415 = F_34 ( V_14 , F_47 ( V_146 ) ) ;
} while ( -- V_414 && ! ( V_415 & V_416 ) );
if ( ! V_414 )
F_100 ( V_154 , L_84 , V_146 ) ;
}
static void F_246 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_424 , V_425 ;
T_6 V_426 = F_247 ( V_2 -> V_54 ) ;
if ( V_14 -> V_107 . type == V_108 )
return;
V_424 = F_34 ( V_14 , V_427 ) ;
V_424 |= V_428 ;
F_68 ( V_14 , V_427 , V_424 ) ;
if ( V_2 -> V_136 & V_429 ) {
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
F_68 ( V_14 , V_440 , V_425 ) ;
if ( V_426 ) {
T_1 V_441 = F_34 ( V_14 , V_442 ) ;
V_441 |= V_443 ;
F_68 ( V_14 , V_442 , V_441 ) ;
}
V_424 &= ~ V_428 ;
F_68 ( V_14 , V_427 , V_424 ) ;
}
static void F_248 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_444 ;
T_1 V_47 ;
F_246 ( V_2 ) ;
if ( V_14 -> V_107 . type != V_108 ) {
V_444 = F_34 ( V_14 , V_445 ) ;
V_444 |= V_446 ;
F_68 ( V_14 , V_445 , V_444 ) ;
}
for ( V_47 = 0 ; V_47 < V_2 -> V_76 ; V_47 ++ )
F_240 ( V_2 , V_2 -> V_57 [ V_47 ] ) ;
}
static void F_249 ( struct V_1 * V_2 ,
struct V_56 * V_117 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_146 = V_117 -> V_146 ;
T_1 V_447 = F_34 ( V_14 , F_33 ( V_146 ) ) ;
V_447 |= V_448 ;
F_68 ( V_14 , F_33 ( V_146 ) , V_447 ) ;
}
static void F_250 ( struct V_1 * V_2 ,
struct V_56 * V_117 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_6 V_146 = V_117 -> V_146 ;
T_1 V_447 = F_34 ( V_14 , F_33 ( V_146 ) ) ;
V_447 &= ~ V_448 ;
F_68 ( V_14 , F_33 ( V_146 ) , V_447 ) ;
}
static void F_251 ( struct V_1 * V_2 ,
struct V_56 * V_66 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_447 ;
T_6 V_146 = V_66 -> V_146 ;
if ( V_14 -> V_107 . type == V_108 ) {
T_2 V_114 = V_2 -> V_434 [ V_435 ] . V_114 ;
V_146 &= V_114 ;
}
V_447 = V_286 << V_449 ;
V_447 |= F_66 ( V_66 ) >> V_450 ;
V_447 |= V_451 ;
F_68 ( V_14 , F_33 ( V_146 ) , V_447 ) ;
}
static void F_252 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
static const T_1 V_452 [ 10 ] = { 0xE291D73D , 0x1805EC6C , 0x2A94B30D ,
0xA54F2BEC , 0xEA49AF7C , 0xE214AD3D , 0xB855AABE ,
0x6A3E67EA , 0x14364D17 , 0x3BED200D } ;
T_1 V_453 = 0 , V_454 = 0 ;
T_1 V_455 ;
int V_47 , V_48 ;
T_2 V_456 = V_2 -> V_434 [ V_435 ] . V_436 ;
if ( ( V_2 -> V_136 & V_429 ) && ( V_456 < 2 ) )
V_456 = 2 ;
for ( V_47 = 0 ; V_47 < 10 ; V_47 ++ )
F_68 ( V_14 , F_253 ( V_47 ) , V_452 [ V_47 ] ) ;
for ( V_47 = 0 , V_48 = 0 ; V_47 < 128 ; V_47 ++ , V_48 ++ ) {
if ( V_48 == V_456 )
V_48 = 0 ;
V_454 = ( V_454 << 8 ) | ( V_48 * 0x11 ) ;
if ( ( V_47 & 3 ) == 3 )
F_68 ( V_14 , F_254 ( V_47 >> 2 ) , V_454 ) ;
}
V_455 = F_34 ( V_14 , V_457 ) ;
V_455 |= V_458 ;
F_68 ( V_14 , V_457 , V_455 ) ;
if ( V_2 -> V_14 . V_107 . type == V_108 ) {
if ( V_2 -> V_434 [ V_435 ] . V_114 )
V_453 = V_459 ;
} else {
T_6 V_426 = F_247 ( V_2 -> V_54 ) ;
if ( V_2 -> V_136 & V_429 ) {
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
F_68 ( V_14 , V_474 , V_453 ) ;
}
static void F_255 ( struct V_1 * V_2 ,
struct V_56 * V_117 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_475 ;
T_6 V_146 = V_117 -> V_146 ;
if ( ! F_165 ( V_117 ) )
return;
V_475 = F_34 ( V_14 , F_256 ( V_146 ) ) ;
V_475 |= V_476 ;
V_475 |= V_477 ;
F_68 ( V_14 , F_256 ( V_146 ) , V_475 ) ;
}
static void F_257 ( struct V_1 * V_2 ,
struct V_56 * V_117 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_414 = V_478 ;
T_1 V_479 ;
T_6 V_146 = V_117 -> V_146 ;
if ( F_23 ( V_14 -> V_39 ) )
return;
if ( V_14 -> V_107 . type == V_108 &&
! ( F_34 ( V_14 , V_422 ) & V_423 ) )
return;
do {
F_245 ( 1000 , 2000 ) ;
V_479 = F_34 ( V_14 , F_39 ( V_146 ) ) ;
} while ( -- V_414 && ! ( V_479 & V_480 ) );
if ( ! V_414 ) {
F_100 ( V_154 , L_85
L_86 , V_146 ) ;
}
}
void F_258 ( struct V_1 * V_2 ,
struct V_56 * V_117 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_414 = V_478 ;
T_1 V_479 ;
T_6 V_146 = V_117 -> V_146 ;
if ( F_23 ( V_14 -> V_39 ) )
return;
V_479 = F_34 ( V_14 , F_39 ( V_146 ) ) ;
V_479 &= ~ V_480 ;
F_68 ( V_14 , F_39 ( V_146 ) , V_479 ) ;
if ( V_14 -> V_107 . type == V_108 &&
! ( F_34 ( V_14 , V_422 ) & V_423 ) )
return;
do {
F_259 ( 10 ) ;
V_479 = F_34 ( V_14 , F_39 ( V_146 ) ) ;
} while ( -- V_414 && ( V_479 & V_480 ) );
if ( ! V_414 ) {
F_100 ( V_154 , L_87
L_86 , V_146 ) ;
}
}
void F_260 ( struct V_1 * V_2 ,
struct V_56 * V_117 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_481 = V_117 -> V_80 ;
T_1 V_479 ;
T_6 V_146 = V_117 -> V_146 ;
V_479 = F_34 ( V_14 , F_39 ( V_146 ) ) ;
F_258 ( V_2 , V_117 ) ;
F_68 ( V_14 , F_40 ( V_146 ) , ( V_481 & F_241 ( 32 ) ) ) ;
F_68 ( V_14 , F_41 ( V_146 ) , ( V_481 >> 32 ) ) ;
F_68 ( V_14 , F_36 ( V_146 ) ,
V_117 -> V_87 * sizeof( union V_67 ) ) ;
F_68 ( V_14 , F_37 ( V_146 ) , 0 ) ;
F_68 ( V_14 , F_38 ( V_146 ) , 0 ) ;
V_117 -> V_143 = V_2 -> V_417 + F_38 ( V_146 ) ;
F_251 ( V_2 , V_117 ) ;
F_255 ( V_2 , V_117 ) ;
if ( V_14 -> V_107 . type == V_108 ) {
V_479 &= ~ 0x3FFFFF ;
V_479 |= 0x080420 ;
}
V_479 |= V_480 ;
F_68 ( V_14 , F_39 ( V_146 ) , V_479 ) ;
F_257 ( V_2 , V_117 ) ;
F_142 ( V_117 , F_107 ( V_117 ) ) ;
}
static void F_261 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_456 = V_2 -> V_434 [ V_435 ] . V_436 ;
T_2 V_482 ;
T_1 V_483 = V_484 |
V_485 |
V_486 |
V_487 |
V_488 ;
if ( V_14 -> V_107 . type == V_108 )
return;
if ( V_456 > 3 )
V_483 |= 2 << 29 ;
else if ( V_456 > 1 )
V_483 |= 1 << 29 ;
F_262 (pool, &adapter->fwd_bitmask, 32 )
F_68 ( V_14 , F_263 ( F_264 ( V_482 ) ) , V_483 ) ;
}
static void F_265 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_175 , V_489 ;
T_1 V_490 , V_491 ;
int V_47 ;
if ( ! ( V_2 -> V_136 & V_429 ) )
return;
V_491 = F_34 ( V_14 , V_492 ) ;
V_491 |= V_493 ;
V_491 &= ~ V_494 ;
V_491 |= F_264 ( 0 ) << V_495 ;
V_491 |= V_496 ;
F_68 ( V_14 , V_492 , V_491 ) ;
V_489 = F_264 ( 0 ) % 32 ;
V_175 = ( F_264 ( 0 ) >= 32 ) ? 1 : 0 ;
F_68 ( V_14 , F_266 ( V_175 ) , ( ~ 0 ) << V_489 ) ;
F_68 ( V_14 , F_266 ( V_175 ^ 1 ) , V_175 - 1 ) ;
F_68 ( V_14 , F_267 ( V_175 ) , ( ~ 0 ) << V_489 ) ;
F_68 ( V_14 , F_267 ( V_175 ^ 1 ) , V_175 - 1 ) ;
if ( V_2 -> V_152 & V_497 )
F_68 ( V_14 , V_498 , V_499 ) ;
V_14 -> V_107 . V_357 . V_500 ( V_14 , 0 , F_264 ( 0 ) ) ;
switch ( V_2 -> V_434 [ V_501 ] . V_114 ) {
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
F_68 ( V_14 , V_507 , V_490 ) ;
V_14 -> V_107 . V_357 . V_508 ( V_14 , ( V_2 -> V_324 != 0 ) ,
V_2 -> V_324 ) ;
for ( V_47 = 0 ; V_47 < V_2 -> V_324 ; V_47 ++ ) {
if ( ! V_2 -> V_509 [ V_47 ] . V_510 )
F_268 ( V_2 -> V_54 , V_47 , false ) ;
}
}
static void F_269 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_53 * V_54 = V_2 -> V_54 ;
int V_511 = V_54 -> V_312 + V_244 + V_512 ;
struct V_56 * V_66 ;
int V_47 ;
T_1 V_513 , V_514 ;
#ifdef F_146
if ( ( V_2 -> V_136 & V_515 ) &&
( V_511 < V_516 ) )
V_511 = V_516 ;
#endif
if ( V_511 < ( V_517 + V_512 ) )
V_511 = ( V_517 + V_512 ) ;
V_513 = F_34 ( V_14 , V_518 ) ;
if ( V_511 != ( V_513 >> V_519 ) ) {
V_513 &= ~ V_520 ;
V_513 |= V_511 << V_519 ;
F_68 ( V_14 , V_518 , V_513 ) ;
}
V_514 = F_34 ( V_14 , V_521 ) ;
V_514 |= V_522 ;
F_68 ( V_14 , V_521 , V_514 ) ;
for ( V_47 = 0 ; V_47 < V_2 -> V_92 ; V_47 ++ ) {
V_66 = V_2 -> V_66 [ V_47 ] ;
if ( V_2 -> V_152 & V_523 )
F_270 ( V_66 ) ;
else
F_271 ( V_66 ) ;
}
}
static void F_272 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_524 = F_34 ( V_14 , V_525 ) ;
switch ( V_14 -> V_107 . type ) {
case V_108 :
V_524 |= V_526 ;
break;
case V_110 :
case V_111 :
F_68 ( V_14 , V_527 ,
( V_528 | F_34 ( V_14 , V_527 ) ) ) ;
V_524 &= ~ V_529 ;
V_524 |= ( V_530 | V_531 ) ;
V_524 |= V_532 ;
break;
default:
return;
}
F_68 ( V_14 , V_525 , V_524 ) ;
}
static void F_273 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_47 ;
T_1 V_180 , V_533 ;
V_180 = F_34 ( V_14 , V_534 ) ;
F_68 ( V_14 , V_534 , V_180 & ~ V_535 ) ;
F_261 ( V_2 ) ;
F_272 ( V_2 ) ;
V_533 = F_34 ( V_14 , V_536 ) ;
V_533 &= ~ V_537 ;
if ( ! ( V_2 -> V_152 & V_523 ) )
V_533 |= V_537 ;
F_68 ( V_14 , V_536 , V_533 ) ;
F_252 ( V_2 ) ;
F_269 ( V_2 ) ;
for ( V_47 = 0 ; V_47 < V_2 -> V_92 ; V_47 ++ )
F_260 ( V_2 , V_2 -> V_66 [ V_47 ] ) ;
if ( V_14 -> V_107 . type == V_108 )
V_180 |= V_538 ;
V_180 |= V_535 ;
V_14 -> V_107 . V_357 . V_539 ( V_14 , V_180 ) ;
}
static int F_274 ( struct V_53 * V_54 ,
T_9 V_540 , T_2 V_269 )
{
struct V_1 * V_2 = F_86 ( V_54 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_107 . V_357 . V_541 ( & V_2 -> V_14 , V_269 , F_264 ( 0 ) , true ) ;
F_243 ( V_269 , V_2 -> V_542 ) ;
return 0 ;
}
static int F_275 ( struct V_53 * V_54 ,
T_9 V_540 , T_2 V_269 )
{
struct V_1 * V_2 = F_86 ( V_54 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_14 -> V_107 . V_357 . V_541 ( & V_2 -> V_14 , V_269 , F_264 ( 0 ) , false ) ;
F_31 ( V_269 , V_2 -> V_542 ) ;
return 0 ;
}
static void F_276 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_543 ;
V_543 = F_34 ( V_14 , V_544 ) ;
V_543 &= ~ ( V_545 | V_546 ) ;
F_68 ( V_14 , V_544 , V_543 ) ;
}
static void F_277 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_543 ;
V_543 = F_34 ( V_14 , V_544 ) ;
V_543 |= V_545 ;
V_543 &= ~ V_546 ;
F_68 ( V_14 , V_544 , V_543 ) ;
}
static void F_278 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_543 ;
int V_47 , V_48 ;
switch ( V_14 -> V_107 . type ) {
case V_108 :
V_543 = F_34 ( V_14 , V_544 ) ;
V_543 &= ~ V_547 ;
F_68 ( V_14 , V_544 , V_543 ) ;
break;
case V_110 :
case V_111 :
for ( V_47 = 0 ; V_47 < V_2 -> V_92 ; V_47 ++ ) {
struct V_56 * V_117 = V_2 -> V_66 [ V_47 ] ;
if ( V_117 -> V_144 )
continue;
V_48 = V_117 -> V_146 ;
V_543 = F_34 ( V_14 , F_39 ( V_48 ) ) ;
V_543 &= ~ V_548 ;
F_68 ( V_14 , F_39 ( V_48 ) , V_543 ) ;
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
int V_47 , V_48 ;
switch ( V_14 -> V_107 . type ) {
case V_108 :
V_543 = F_34 ( V_14 , V_544 ) ;
V_543 |= V_547 ;
F_68 ( V_14 , V_544 , V_543 ) ;
break;
case V_110 :
case V_111 :
for ( V_47 = 0 ; V_47 < V_2 -> V_92 ; V_47 ++ ) {
struct V_56 * V_117 = V_2 -> V_66 [ V_47 ] ;
if ( V_117 -> V_144 )
continue;
V_48 = V_117 -> V_146 ;
V_543 = F_34 ( V_14 , F_39 ( V_48 ) ) ;
V_543 |= V_548 ;
F_68 ( V_14 , F_39 ( V_48 ) , V_543 ) ;
}
break;
default:
break;
}
}
static void F_280 ( struct V_1 * V_2 )
{
T_2 V_269 ;
F_274 ( V_2 -> V_54 , F_145 ( V_246 ) , 0 ) ;
F_262 (vid, adapter->active_vlans, VLAN_N_VID)
F_274 ( V_2 -> V_54 , F_145 ( V_246 ) , V_269 ) ;
}
static int F_281 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_86 ( V_54 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
unsigned int V_549 = V_14 -> V_107 . V_550 - 1 ;
int V_87 = 0 ;
if ( V_2 -> V_136 & V_429 )
V_549 = V_551 - 1 ;
if ( F_282 ( V_54 ) > V_549 )
return - V_552 ;
if ( ! F_283 ( V_54 ) ) {
struct V_553 * V_554 ;
if ( ! V_14 -> V_107 . V_357 . V_555 )
return - V_552 ;
F_284 (ha, netdev) {
if ( ! V_549 )
break;
V_14 -> V_107 . V_357 . V_555 ( V_14 , V_549 -- , V_554 -> V_556 ,
F_264 ( 0 ) , V_557 ) ;
V_87 ++ ;
}
}
for (; V_549 > 0 ; V_549 -- )
V_14 -> V_107 . V_357 . V_558 ( V_14 , V_549 ) ;
return V_87 ;
}
void F_285 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_86 ( V_54 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_559 , V_560 = V_561 | V_562 ;
int V_87 ;
V_559 = F_34 ( V_14 , V_563 ) ;
V_559 &= ~ V_564 ;
V_559 |= V_565 ;
V_559 |= V_566 ;
V_559 |= V_567 ;
V_559 &= ~ ( V_568 | V_569 ) ;
if ( V_54 -> V_136 & V_570 ) {
V_14 -> V_571 . V_572 = true ;
V_559 |= ( V_568 | V_569 ) ;
V_560 |= ( V_573 | V_574 ) ;
if ( ! ( V_2 -> V_136 & ( V_575 |
V_429 ) ) )
F_276 ( V_2 ) ;
else
F_277 ( V_2 ) ;
} else {
if ( V_54 -> V_136 & V_576 ) {
V_559 |= V_569 ;
V_560 |= V_574 ;
}
F_277 ( V_2 ) ;
V_14 -> V_571 . V_572 = false ;
}
V_87 = F_281 ( V_54 ) ;
if ( V_87 < 0 ) {
V_559 |= V_568 ;
V_560 |= V_573 ;
}
V_14 -> V_107 . V_357 . V_577 ( V_14 , V_54 ) ;
V_560 |= V_578 ;
if ( V_2 -> V_324 )
F_286 ( V_2 ) ;
if ( V_14 -> V_107 . type != V_108 ) {
V_560 |= F_34 ( V_14 , F_287 ( F_264 ( 0 ) ) ) &
~ ( V_574 | V_578 |
V_573 ) ;
F_68 ( V_14 , F_287 ( F_264 ( 0 ) ) , V_560 ) ;
}
if ( V_2 -> V_54 -> V_194 & V_290 ) {
V_559 |= ( V_564 |
V_565 |
V_567 ) ;
V_559 &= ~ ( V_566 ) ;
}
F_68 ( V_14 , V_563 , V_559 ) ;
if ( V_54 -> V_194 & V_267 )
F_279 ( V_2 ) ;
else
F_278 ( V_2 ) ;
}
static void F_288 ( struct V_1 * V_2 )
{
int V_579 ;
for ( V_579 = 0 ; V_579 < V_2 -> V_187 ; V_579 ++ ) {
F_289 ( V_2 -> V_156 [ V_579 ] ) ;
F_290 ( & V_2 -> V_156 [ V_579 ] -> V_271 ) ;
}
}
static void F_291 ( struct V_1 * V_2 )
{
int V_579 ;
for ( V_579 = 0 ; V_579 < V_2 -> V_187 ; V_579 ++ ) {
F_292 ( & V_2 -> V_156 [ V_579 ] -> V_271 ) ;
while ( ! F_293 ( V_2 -> V_156 [ V_579 ] ) ) {
F_48 ( L_88 , V_579 ) ;
F_245 ( 1000 , 20000 ) ;
}
}
}
static void F_294 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_511 = V_2 -> V_54 -> V_312 + V_244 + V_512 ;
if ( ! ( V_2 -> V_136 & V_137 ) ) {
if ( V_14 -> V_107 . type == V_108 )
F_295 ( V_2 -> V_54 , 65536 ) ;
return;
}
if ( V_14 -> V_107 . type == V_108 )
F_295 ( V_2 -> V_54 , 32768 ) ;
#ifdef F_146
if ( V_2 -> V_54 -> V_194 & V_580 )
V_511 = F_204 ( V_511 , V_516 ) ;
#endif
if ( V_2 -> V_581 & V_582 ) {
F_296 ( V_14 , & V_2 -> V_133 , V_511 ,
V_583 ) ;
F_296 ( V_14 , & V_2 -> V_133 , V_511 ,
V_584 ) ;
F_297 ( V_14 , & V_2 -> V_133 ) ;
} else if ( V_2 -> V_585 && V_2 -> V_135 ) {
F_298 ( & V_2 -> V_14 ,
V_2 -> V_585 ,
V_511 ) ;
F_299 ( & V_2 -> V_14 ,
V_2 -> V_135 -> V_132 ,
V_2 -> V_585 -> V_586 ) ;
}
if ( V_14 -> V_107 . type != V_108 ) {
T_1 V_587 = 0 ;
T_2 V_456 = V_2 -> V_434 [ V_435 ] . V_436 - 1 ;
while ( V_456 ) {
V_587 ++ ;
V_456 >>= 1 ;
}
F_68 ( V_14 , V_588 , V_587 * 0x11111111 ) ;
}
}
static int F_300 ( struct V_1 * V_2 , int V_589 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_53 * V_72 = V_2 -> V_54 ;
int V_390 , V_131 , V_590 , V_591 ;
T_1 V_592 , V_593 ;
V_131 = V_390 = V_72 -> V_312 + V_244 + V_512 + V_594 ;
#ifdef F_146
if ( ( V_72 -> V_194 & V_580 ) &&
( V_131 < V_516 ) &&
( V_589 == F_301 ( V_2 ) ) )
V_131 = V_516 ;
#endif
switch ( V_14 -> V_107 . type ) {
case V_111 :
V_592 = F_302 ( V_390 , V_131 ) ;
break;
default:
V_592 = F_303 ( V_390 , V_131 ) ;
break;
}
if ( V_2 -> V_136 & V_429 )
V_592 += F_304 ( V_131 ) ;
V_590 = F_305 ( V_592 ) ;
V_593 = F_34 ( V_14 , F_306 ( V_589 ) ) >> 10 ;
V_591 = V_593 - V_590 ;
if ( V_591 < 0 ) {
F_90 ( V_154 , L_89
L_90
L_91 , V_589 ) ;
V_591 = V_131 + 1 ;
}
return V_591 ;
}
static int F_307 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_53 * V_72 = V_2 -> V_54 ;
int V_131 ;
T_1 V_592 ;
V_131 = V_72 -> V_312 + V_244 + V_512 ;
switch ( V_14 -> V_107 . type ) {
case V_111 :
V_592 = F_308 ( V_131 ) ;
break;
default:
V_592 = F_309 ( V_131 ) ;
break;
}
return F_305 ( V_592 ) ;
}
static void F_310 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_595 = F_247 ( V_2 -> V_54 ) ;
int V_47 ;
if ( ! V_595 )
V_595 = 1 ;
V_14 -> V_122 . V_596 = F_307 ( V_2 ) ;
for ( V_47 = 0 ; V_47 < V_595 ; V_47 ++ ) {
V_14 -> V_122 . V_597 [ V_47 ] = F_300 ( V_2 , V_47 ) ;
if ( V_14 -> V_122 . V_596 > V_14 -> V_122 . V_597 [ V_47 ] )
V_14 -> V_122 . V_596 = 0 ;
}
}
static void F_311 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_598 ;
T_6 V_131 = F_247 ( V_2 -> V_54 ) ;
if ( V_2 -> V_136 & V_384 ||
V_2 -> V_136 & V_599 )
V_598 = 32 << V_2 -> V_600 ;
else
V_598 = 0 ;
V_14 -> V_107 . V_357 . V_601 ( V_14 , V_131 , V_598 , V_602 ) ;
F_310 ( V_2 ) ;
}
static void F_312 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_603 * V_604 ;
struct V_605 * V_606 ;
F_313 ( & V_2 -> V_607 ) ;
if ( ! F_314 ( & V_2 -> V_608 ) )
F_315 ( V_14 , & V_2 -> V_609 ) ;
F_316 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_317 ( V_14 ,
& V_606 -> V_606 ,
V_606 -> V_610 ,
( V_606 -> V_611 == V_612 ) ?
V_612 :
V_2 -> V_66 [ V_606 -> V_611 ] -> V_146 ) ;
}
F_318 ( & V_2 -> V_607 ) ;
}
static void F_319 ( struct V_53 * V_72 , unsigned int V_482 ,
struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_560 ;
V_560 = F_34 ( V_14 , F_287 ( V_482 ) ) ;
V_560 |= ( V_578 | V_561 | V_562 ) ;
V_560 &= ~ V_574 ;
if ( V_72 -> V_136 & V_576 ) {
V_560 |= V_574 ;
} else {
V_560 |= V_578 ;
V_14 -> V_107 . V_357 . V_577 ( V_14 , V_72 ) ;
}
F_281 ( V_2 -> V_54 ) ;
F_68 ( V_14 , F_287 ( V_482 ) , V_560 ) ;
}
static void F_320 ( struct V_1 * V_2 ,
T_6 * V_556 , T_2 V_482 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
unsigned int V_404 ;
V_404 = V_14 -> V_107 . V_550 - V_482 ;
V_14 -> V_107 . V_357 . V_555 ( V_14 , V_404 , V_556 , F_264 ( V_482 ) , V_557 ) ;
}
static void F_321 ( struct V_613 * V_614 )
{
struct V_1 * V_2 = V_614 -> V_145 ;
int V_456 = V_2 -> V_615 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_482 = V_614 -> V_482 ;
T_1 V_483 = V_484 |
V_485 |
V_486 |
V_487 |
V_488 ;
if ( V_14 -> V_107 . type == V_108 )
return;
if ( V_456 > 3 )
V_483 |= 2 << 29 ;
else if ( V_456 > 1 )
V_483 |= 1 << 29 ;
F_68 ( V_14 , F_263 ( F_264 ( V_482 ) ) , V_483 ) ;
}
static void F_322 ( struct V_56 * V_66 )
{
struct V_188 * V_72 = V_66 -> V_72 ;
unsigned long V_296 ;
T_2 V_47 ;
if ( ! V_66 -> V_70 )
return;
for ( V_47 = 0 ; V_47 < V_66 -> V_87 ; V_47 ++ ) {
struct V_69 * V_295 ;
V_295 = & V_66 -> V_70 [ V_47 ] ;
if ( V_295 -> V_88 ) {
struct V_193 * V_88 = V_295 -> V_88 ;
if ( F_151 ( V_88 ) -> V_288 ) {
F_77 ( V_72 ,
F_151 ( V_88 ) -> V_80 ,
F_66 ( V_66 ) ,
V_225 ) ;
F_151 ( V_88 ) -> V_288 = false ;
}
F_323 ( V_88 ) ;
}
V_295 -> V_88 = NULL ;
if ( V_295 -> V_80 )
F_77 ( V_72 , V_295 -> V_80 ,
F_139 ( V_66 ) ,
V_225 ) ;
V_295 -> V_80 = 0 ;
if ( V_295 -> V_97 )
F_141 ( V_295 -> V_97 ,
F_137 ( V_66 ) ) ;
V_295 -> V_97 = NULL ;
}
V_296 = sizeof( struct V_69 ) * V_66 -> V_87 ;
memset ( V_66 -> V_70 , 0 , V_296 ) ;
memset ( V_66 -> V_86 , 0 , V_66 -> V_296 ) ;
V_66 -> V_219 = 0 ;
V_66 -> V_78 = 0 ;
V_66 -> V_79 = 0 ;
}
static void F_324 ( struct V_613 * V_614 ,
struct V_56 * V_66 )
{
struct V_1 * V_2 = V_614 -> V_145 ;
int V_106 = V_66 -> V_85 + V_614 -> V_616 ;
F_258 ( V_2 , V_66 ) ;
F_245 ( 10000 , 20000 ) ;
F_214 ( V_2 , ( ( T_4 ) 1 << V_106 ) ) ;
F_322 ( V_66 ) ;
V_66 -> V_144 = NULL ;
}
static int F_325 ( struct V_53 * V_617 ,
struct V_613 * V_618 )
{
struct V_1 * V_2 = V_618 -> V_145 ;
unsigned int V_619 = V_618 -> V_616 ;
unsigned int V_620 = V_618 -> V_621 ;
int V_47 ;
F_326 ( V_617 ) ;
for ( V_47 = 0 ; V_47 < V_2 -> V_615 ; V_47 ++ ) {
F_324 ( V_618 , V_2 -> V_66 [ V_619 + V_47 ] ) ;
V_2 -> V_66 [ V_619 + V_47 ] -> V_54 = V_2 -> V_54 ;
}
for ( V_47 = 0 ; V_47 < V_2 -> V_615 ; V_47 ++ ) {
V_2 -> V_57 [ V_620 + V_47 ] -> V_144 = NULL ;
V_2 -> V_57 [ V_620 + V_47 ] -> V_54 = V_2 -> V_54 ;
}
return 0 ;
}
static int F_327 ( struct V_53 * V_617 ,
struct V_613 * V_618 )
{
struct V_1 * V_2 = V_618 -> V_145 ;
unsigned int V_619 , V_620 , V_376 ;
int V_47 , V_622 , V_17 = 0 ;
if ( ! F_14 ( V_618 -> V_482 , & V_2 -> V_623 ) )
return 0 ;
V_622 = V_618 -> V_482 * V_2 -> V_615 ;
F_328 ( V_617 , L_92 ,
V_618 -> V_482 , V_2 -> V_624 ,
V_622 , V_622 + V_2 -> V_615 ,
V_2 -> V_623 ) ;
V_618 -> V_54 = V_617 ;
V_618 -> V_616 = V_619 = V_622 ;
V_618 -> V_621 = V_620 = V_622 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_615 ; V_47 ++ )
F_324 ( V_618 , V_2 -> V_66 [ V_619 + V_47 ] ) ;
for ( V_47 = 0 ; V_47 < V_2 -> V_615 ; V_47 ++ ) {
V_2 -> V_66 [ V_619 + V_47 ] -> V_54 = V_617 ;
V_2 -> V_66 [ V_619 + V_47 ] -> V_144 = V_618 ;
F_260 ( V_2 , V_2 -> V_66 [ V_619 + V_47 ] ) ;
}
for ( V_47 = 0 ; V_47 < V_2 -> V_615 ; V_47 ++ ) {
V_2 -> V_57 [ V_620 + V_47 ] -> V_54 = V_617 ;
V_2 -> V_57 [ V_620 + V_47 ] -> V_144 = V_618 ;
}
V_376 = F_329 (unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues) ;
V_17 = F_330 ( V_617 , V_376 ) ;
if ( V_17 )
goto V_625;
V_17 = F_331 ( V_617 , V_376 ) ;
if ( V_17 )
goto V_625;
if ( F_332 ( V_617 -> V_626 ) )
F_320 ( V_2 , V_617 -> V_626 , V_618 -> V_482 ) ;
F_321 ( V_618 ) ;
F_319 ( V_617 , V_618 -> V_482 , V_2 ) ;
return V_17 ;
V_625:
F_325 ( V_617 , V_618 ) ;
return V_17 ;
}
static void F_333 ( struct V_1 * V_2 )
{
struct V_53 * V_94 ;
struct V_627 * V_628 ;
int V_17 ;
F_334 (adapter->netdev, upper, iter) {
if ( F_335 ( V_94 ) ) {
struct V_629 * V_630 = F_86 ( V_94 ) ;
struct V_613 * V_614 = V_630 -> V_631 ;
if ( V_630 -> V_631 ) {
V_17 = F_327 ( V_94 , V_614 ) ;
if ( V_17 )
continue;
}
}
}
}
static void F_336 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
F_311 ( V_2 ) ;
#ifdef F_337
F_294 ( V_2 ) ;
#endif
F_265 ( V_2 ) ;
F_285 ( V_2 -> V_54 ) ;
F_280 ( V_2 ) ;
switch ( V_14 -> V_107 . type ) {
case V_110 :
case V_111 :
V_14 -> V_107 . V_357 . V_632 ( V_14 ) ;
break;
default:
break;
}
if ( V_2 -> V_136 & V_384 ) {
F_338 ( & V_2 -> V_14 ,
V_2 -> V_600 ) ;
} else if ( V_2 -> V_136 & V_599 ) {
F_339 ( & V_2 -> V_14 ,
V_2 -> V_600 ) ;
F_312 ( V_2 ) ;
}
switch ( V_14 -> V_107 . type ) {
case V_110 :
case V_111 :
V_14 -> V_107 . V_357 . V_633 ( V_14 ) ;
break;
default:
break;
}
#ifdef F_146
F_340 ( V_2 ) ;
#endif
F_248 ( V_2 ) ;
F_273 ( V_2 ) ;
F_333 ( V_2 ) ;
}
static inline bool F_341 ( struct V_15 * V_14 )
{
switch ( V_14 -> V_360 . type ) {
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
return true ;
case V_646 :
if ( V_14 -> V_107 . type == V_108 )
return true ;
default:
return false ;
}
}
static void F_342 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_107 . type == V_108 )
V_2 -> V_152 |= V_647 ;
V_2 -> V_152 |= V_368 ;
}
static int F_343 ( struct V_15 * V_14 )
{
T_1 V_20 ;
bool V_648 , V_359 = false ;
T_1 V_151 = V_649 ;
if ( V_14 -> V_107 . V_357 . V_358 )
V_151 = V_14 -> V_107 . V_357 . V_358 ( V_14 , & V_20 , & V_359 , false ) ;
if ( V_151 )
goto V_650;
V_20 = V_14 -> V_360 . V_651 ;
if ( ( ! V_20 ) && ( V_14 -> V_107 . V_357 . V_652 ) )
V_151 = V_14 -> V_107 . V_357 . V_652 ( V_14 , & V_20 ,
& V_648 ) ;
if ( V_151 )
goto V_650;
if ( V_14 -> V_107 . V_357 . V_653 )
V_151 = V_14 -> V_107 . V_357 . V_653 ( V_14 , V_20 , V_359 ) ;
V_650:
return V_151 ;
}
static void F_344 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_654 = 0 ;
if ( V_2 -> V_136 & V_408 ) {
V_654 = V_655 | V_656 |
V_657 ;
V_654 |= V_658 ;
switch ( V_14 -> V_107 . type ) {
case V_108 :
F_68 ( V_14 , V_659 , V_660 ) ;
break;
case V_110 :
case V_111 :
default:
F_68 ( V_14 , F_345 ( 0 ) , 0xFFFFFFFF ) ;
F_68 ( V_14 , F_345 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_68 ( V_14 , V_659 , V_660 ) ;
}
if ( V_2 -> V_136 & V_429 ) {
V_654 &= ~ V_661 ;
switch ( V_2 -> V_434 [ V_501 ] . V_114 ) {
case V_502 :
V_654 |= V_662 ;
break;
case V_504 :
V_654 |= V_663 ;
break;
default:
V_654 |= V_664 ;
break;
}
}
if ( V_2 -> V_152 & V_352 ) {
switch ( V_2 -> V_14 . V_107 . type ) {
case V_110 :
V_654 |= V_665 ;
break;
case V_111 :
V_654 |= V_379 ;
break;
default:
break;
}
}
if ( V_2 -> V_136 & V_363 )
V_654 |= V_666 ;
if ( V_14 -> V_107 . type == V_110 ) {
V_654 |= V_666 ;
V_654 |= V_667 ;
}
F_68 ( V_14 , V_668 , V_654 ) ;
}
static void F_346 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 ;
T_1 V_99 ;
F_69 ( V_2 ) ;
F_344 ( V_2 ) ;
if ( V_2 -> V_136 & V_408 )
F_199 ( V_2 ) ;
else
F_239 ( V_2 ) ;
if ( V_14 -> V_107 . V_357 . V_669 )
V_14 -> V_107 . V_357 . V_669 ( V_14 ) ;
F_30 () ;
F_31 ( V_33 , & V_2 -> V_34 ) ;
F_288 ( V_2 ) ;
if ( F_341 ( V_14 ) ) {
F_342 ( V_2 ) ;
} else {
V_17 = F_343 ( V_14 ) ;
if ( V_17 )
F_100 ( V_170 , L_93 , V_17 ) ;
}
F_34 ( V_14 , V_365 ) ;
F_216 ( V_2 , true , true ) ;
if ( V_2 -> V_136 & V_363 ) {
T_1 V_670 = F_34 ( V_14 , V_671 ) ;
if ( V_670 & V_672 )
F_206 ( V_154 , L_73 ) ;
}
V_2 -> V_136 |= V_371 ;
V_2 -> V_372 = V_169 ;
F_347 ( & V_2 -> V_673 , V_169 ) ;
V_99 = F_34 ( V_14 , V_100 ) ;
V_99 |= V_674 ;
F_68 ( V_14 , V_100 , V_99 ) ;
}
void F_348 ( struct V_1 * V_2 )
{
F_349 ( F_350 () ) ;
V_2 -> V_54 -> V_73 = V_169 ;
while ( F_15 ( V_675 , & V_2 -> V_34 ) )
F_245 ( 1000 , 2000 ) ;
F_351 ( V_2 ) ;
if ( V_2 -> V_136 & V_429 )
F_352 ( 2000 ) ;
F_353 ( V_2 ) ;
F_31 ( V_675 , & V_2 -> V_34 ) ;
}
void F_353 ( struct V_1 * V_2 )
{
F_336 ( V_2 ) ;
F_346 ( V_2 ) ;
}
void F_354 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_17 ;
if ( F_23 ( V_14 -> V_39 ) )
return;
while ( F_15 ( V_676 , & V_2 -> V_34 ) )
F_245 ( 1000 , 2000 ) ;
V_2 -> V_152 &= ~ ( V_647 |
V_368 ) ;
V_2 -> V_136 &= ~ V_369 ;
V_17 = V_14 -> V_107 . V_357 . V_677 ( V_14 ) ;
switch ( V_17 ) {
case 0 :
case V_678 :
case V_679 :
break;
case V_680 :
F_18 ( L_94 ) ;
break;
case V_681 :
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
F_31 ( V_676 , & V_2 -> V_34 ) ;
V_14 -> V_107 . V_357 . V_555 ( V_14 , 0 , V_14 -> V_107 . V_556 , F_264 ( 0 ) , V_557 ) ;
if ( V_14 -> V_107 . V_682 )
V_14 -> V_107 . V_357 . V_683 ( V_14 , F_264 ( 0 ) ) ;
if ( F_14 ( V_684 , & V_2 -> V_34 ) )
F_355 ( V_2 ) ;
}
static void F_356 ( struct V_56 * V_57 )
{
struct V_58 * V_77 ;
unsigned long V_296 ;
T_2 V_47 ;
if ( ! V_57 -> V_77 )
return;
for ( V_47 = 0 ; V_47 < V_57 -> V_87 ; V_47 ++ ) {
V_77 = & V_57 -> V_77 [ V_47 ] ;
F_74 ( V_57 , V_77 ) ;
}
F_357 ( F_104 ( V_57 ) ) ;
V_296 = sizeof( struct V_58 ) * V_57 -> V_87 ;
memset ( V_57 -> V_77 , 0 , V_296 ) ;
memset ( V_57 -> V_86 , 0 , V_57 -> V_296 ) ;
V_57 -> V_79 = 0 ;
V_57 -> V_78 = 0 ;
}
static void F_358 ( struct V_1 * V_2 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_92 ; V_47 ++ )
F_322 ( V_2 -> V_66 [ V_47 ] ) ;
}
static void F_359 ( struct V_1 * V_2 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_76 ; V_47 ++ )
F_356 ( V_2 -> V_57 [ V_47 ] ) ;
}
static void F_360 ( struct V_1 * V_2 )
{
struct V_603 * V_604 ;
struct V_605 * V_606 ;
F_313 ( & V_2 -> V_607 ) ;
F_316 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_361 ( & V_606 -> V_685 ) ;
F_233 ( V_606 ) ;
}
V_2 -> V_686 = 0 ;
F_318 ( & V_2 -> V_607 ) ;
}
void F_351 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = V_2 -> V_54 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_53 * V_94 ;
struct V_627 * V_628 ;
T_1 V_180 ;
int V_47 ;
if ( F_15 ( V_33 , & V_2 -> V_34 ) )
return;
V_180 = F_34 ( V_14 , V_534 ) ;
F_68 ( V_14 , V_534 , V_180 & ~ V_535 ) ;
for ( V_47 = 0 ; V_47 < V_2 -> V_92 ; V_47 ++ )
F_258 ( V_2 , V_2 -> V_66 [ V_47 ] ) ;
F_245 ( 10000 , 20000 ) ;
F_326 ( V_54 ) ;
F_362 ( V_54 ) ;
F_363 ( V_54 ) ;
F_334 (adapter->netdev, upper, iter) {
if ( F_335 ( V_94 ) ) {
struct V_629 * V_235 = F_86 ( V_94 ) ;
if ( V_235 -> V_631 ) {
F_326 ( V_94 ) ;
F_362 ( V_94 ) ;
F_363 ( V_94 ) ;
}
}
}
F_237 ( V_2 ) ;
F_291 ( V_2 ) ;
V_2 -> V_152 &= ~ ( V_385 |
V_153 ) ;
V_2 -> V_136 &= ~ V_371 ;
F_364 ( & V_2 -> V_673 ) ;
if ( V_2 -> V_324 ) {
F_68 ( & V_2 -> V_14 , V_326 , 0 ) ;
for ( V_47 = 0 ; V_47 < V_2 -> V_324 ; V_47 ++ )
V_2 -> V_509 [ V_47 ] . V_687 = false ;
F_365 ( V_2 ) ;
F_366 ( V_2 ) ;
}
for ( V_47 = 0 ; V_47 < V_2 -> V_76 ; V_47 ++ ) {
T_6 V_146 = V_2 -> V_57 [ V_47 ] -> V_146 ;
F_68 ( V_14 , F_47 ( V_146 ) , V_688 ) ;
}
switch ( V_14 -> V_107 . type ) {
case V_110 :
case V_111 :
F_68 ( V_14 , V_445 ,
( F_34 ( V_14 , V_445 ) &
~ V_446 ) ) ;
break;
default:
break;
}
if ( ! F_367 ( V_2 -> V_9 ) )
F_354 ( V_2 ) ;
if ( V_14 -> V_107 . V_357 . V_689 )
V_14 -> V_107 . V_357 . V_689 ( V_14 ) ;
F_359 ( V_2 ) ;
F_358 ( V_2 ) ;
#ifdef F_224
F_120 ( V_2 ) ;
#endif
}
static void F_368 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_86 ( V_54 ) ;
F_89 ( V_2 ) ;
}
static int F_369 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_9 = V_2 -> V_9 ;
unsigned int V_198 , V_690 ;
T_1 V_691 ;
#ifdef F_337
int V_48 ;
struct V_692 * V_131 ;
#endif
V_14 -> V_693 = V_9 -> V_694 ;
V_14 -> V_21 = V_9 -> V_188 ;
V_14 -> V_695 = V_9 -> V_696 ;
V_14 -> V_697 = V_9 -> V_698 ;
V_14 -> V_699 = V_9 -> V_700 ;
V_198 = F_329 ( int , V_701 , F_370 () ) ;
V_2 -> V_434 [ V_435 ] . V_702 = V_198 ;
V_2 -> V_152 |= V_703 ;
V_2 -> V_152 |= V_523 ;
V_2 -> V_704 = V_705 ;
V_2 -> V_419 = 20 ;
V_690 = F_329 ( int , V_706 , F_370 () ) ;
V_2 -> V_434 [ V_707 ] . V_702 = V_690 ;
V_2 -> V_600 = V_708 ;
#ifdef F_224
V_2 -> V_136 |= V_190 ;
#endif
#ifdef F_146
V_2 -> V_136 |= V_709 ;
V_2 -> V_136 &= ~ V_515 ;
#ifdef F_337
V_2 -> V_710 . V_711 = V_712 ;
#endif
#endif
switch ( V_14 -> V_107 . type ) {
case V_108 :
V_2 -> V_152 &= ~ V_703 ;
V_2 -> V_152 &= ~ V_523 ;
if ( V_14 -> V_21 == V_713 )
V_2 -> V_136 |= V_363 ;
V_2 -> V_704 = V_714 ;
V_2 -> V_434 [ V_707 ] . V_702 = 0 ;
V_2 -> V_419 = 0 ;
V_2 -> V_600 = 0 ;
#ifdef F_146
V_2 -> V_136 &= ~ V_709 ;
V_2 -> V_136 &= ~ V_515 ;
#ifdef F_337
V_2 -> V_710 . V_711 = 0 ;
#endif
#endif
break;
case V_110 :
if ( V_14 -> V_21 == V_354 )
V_2 -> V_152 |= V_352 ;
break;
case V_111 :
V_691 = F_34 ( V_14 , V_715 ) ;
if ( V_691 & V_716 )
V_2 -> V_152 |= V_352 ;
break;
default:
break;
}
#ifdef F_146
F_371 ( & V_2 -> V_710 . V_717 ) ;
#endif
F_371 ( & V_2 -> V_607 ) ;
#ifdef F_337
switch ( V_14 -> V_107 . type ) {
case V_111 :
V_2 -> V_133 . V_718 . V_719 = V_720 ;
V_2 -> V_133 . V_718 . V_721 = V_720 ;
break;
default:
V_2 -> V_133 . V_718 . V_719 = V_722 ;
V_2 -> V_133 . V_718 . V_721 = V_722 ;
break;
}
for ( V_48 = 0 ; V_48 < V_722 ; V_48 ++ ) {
V_131 = & V_2 -> V_133 . V_723 [ V_48 ] ;
V_131 -> V_724 [ V_583 ] . V_725 = 0 ;
V_131 -> V_724 [ V_583 ] . V_726 = 12 + ( V_48 & 1 ) ;
V_131 -> V_724 [ V_584 ] . V_725 = 0 ;
V_131 -> V_724 [ V_584 ] . V_726 = 12 + ( V_48 & 1 ) ;
V_131 -> V_727 = V_728 ;
}
V_131 = & V_2 -> V_133 . V_723 [ 0 ] ;
V_131 -> V_724 [ V_583 ] . V_729 = 0xFF ;
V_131 -> V_724 [ V_584 ] . V_729 = 0xFF ;
V_2 -> V_133 . V_730 [ V_583 ] [ 0 ] = 100 ;
V_2 -> V_133 . V_730 [ V_584 ] [ 0 ] = 100 ;
V_2 -> V_133 . V_134 = false ;
V_2 -> V_731 = 0x00 ;
V_2 -> V_581 = V_732 | V_582 ;
memcpy ( & V_2 -> V_733 , & V_2 -> V_133 ,
sizeof( V_2 -> V_733 ) ) ;
#endif
V_14 -> V_122 . V_734 = V_124 ;
V_14 -> V_122 . V_123 = V_124 ;
F_310 ( V_2 ) ;
V_14 -> V_122 . V_735 = V_736 ;
V_14 -> V_122 . V_737 = true ;
V_14 -> V_122 . V_738 = F_372 ( V_14 ) ;
#ifdef F_373
if ( V_739 > 0 )
F_11 ( L_102 ) ;
if ( V_14 -> V_107 . type != V_108 ) {
if ( V_739 > V_740 ) {
V_2 -> V_324 = 0 ;
F_11 ( L_103 ) ;
} else {
V_2 -> V_324 = V_739 ;
}
}
#endif
V_2 -> V_399 = 1 ;
V_2 -> V_741 = 1 ;
V_2 -> V_742 = V_743 ;
V_2 -> V_744 = V_745 ;
V_2 -> V_746 = V_747 ;
if ( F_374 ( V_14 ) ) {
F_18 ( L_104 ) ;
return - V_748 ;
}
F_243 ( 0 , & V_2 -> V_623 ) ;
F_243 ( V_33 , & V_2 -> V_34 ) ;
return 0 ;
}
int F_375 ( struct V_56 * V_57 )
{
struct V_188 * V_72 = V_57 -> V_72 ;
int V_749 = F_376 ( V_72 ) ;
int V_750 = - 1 ;
int V_296 ;
V_296 = sizeof( struct V_58 ) * V_57 -> V_87 ;
if ( V_57 -> V_156 )
V_750 = V_57 -> V_156 -> V_750 ;
V_57 -> V_77 = F_377 ( V_296 , V_750 ) ;
if ( ! V_57 -> V_77 )
V_57 -> V_77 = F_378 ( V_296 ) ;
if ( ! V_57 -> V_77 )
goto V_17;
F_379 ( & V_57 -> V_167 ) ;
V_57 -> V_296 = V_57 -> V_87 * sizeof( union V_60 ) ;
V_57 -> V_296 = F_169 ( V_57 -> V_296 , 4096 ) ;
F_380 ( V_72 , V_750 ) ;
V_57 -> V_86 = F_381 ( V_72 ,
V_57 -> V_296 ,
& V_57 -> V_80 ,
V_751 ) ;
F_380 ( V_72 , V_749 ) ;
if ( ! V_57 -> V_86 )
V_57 -> V_86 = F_381 ( V_72 , V_57 -> V_296 ,
& V_57 -> V_80 , V_751 ) ;
if ( ! V_57 -> V_86 )
goto V_17;
V_57 -> V_79 = 0 ;
V_57 -> V_78 = 0 ;
return 0 ;
V_17:
F_382 ( V_57 -> V_77 ) ;
V_57 -> V_77 = NULL ;
F_383 ( V_72 , L_105 ) ;
return - V_552 ;
}
static int F_384 ( struct V_1 * V_2 )
{
int V_47 , V_17 = 0 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_76 ; V_47 ++ ) {
V_17 = F_375 ( V_2 -> V_57 [ V_47 ] ) ;
if ( ! V_17 )
continue;
F_100 ( V_170 , L_106 , V_47 ) ;
goto V_752;
}
return 0 ;
V_752:
while ( V_47 -- )
F_385 ( V_2 -> V_57 [ V_47 ] ) ;
return V_17 ;
}
int F_386 ( struct V_56 * V_66 )
{
struct V_188 * V_72 = V_66 -> V_72 ;
int V_749 = F_376 ( V_72 ) ;
int V_750 = - 1 ;
int V_296 ;
V_296 = sizeof( struct V_69 ) * V_66 -> V_87 ;
if ( V_66 -> V_156 )
V_750 = V_66 -> V_156 -> V_750 ;
V_66 -> V_70 = F_377 ( V_296 , V_750 ) ;
if ( ! V_66 -> V_70 )
V_66 -> V_70 = F_378 ( V_296 ) ;
if ( ! V_66 -> V_70 )
goto V_17;
F_379 ( & V_66 -> V_167 ) ;
V_66 -> V_296 = V_66 -> V_87 * sizeof( union V_67 ) ;
V_66 -> V_296 = F_169 ( V_66 -> V_296 , 4096 ) ;
F_380 ( V_72 , V_750 ) ;
V_66 -> V_86 = F_381 ( V_72 ,
V_66 -> V_296 ,
& V_66 -> V_80 ,
V_751 ) ;
F_380 ( V_72 , V_749 ) ;
if ( ! V_66 -> V_86 )
V_66 -> V_86 = F_381 ( V_72 , V_66 -> V_296 ,
& V_66 -> V_80 , V_751 ) ;
if ( ! V_66 -> V_86 )
goto V_17;
V_66 -> V_78 = 0 ;
V_66 -> V_79 = 0 ;
return 0 ;
V_17:
F_382 ( V_66 -> V_70 ) ;
V_66 -> V_70 = NULL ;
F_383 ( V_72 , L_107 ) ;
return - V_552 ;
}
static int F_387 ( struct V_1 * V_2 )
{
int V_47 , V_17 = 0 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_92 ; V_47 ++ ) {
V_17 = F_386 ( V_2 -> V_66 [ V_47 ] ) ;
if ( ! V_17 )
continue;
F_100 ( V_170 , L_108 , V_47 ) ;
goto V_753;
}
#ifdef F_146
V_17 = F_388 ( V_2 ) ;
if ( ! V_17 )
#endif
return 0 ;
V_753:
while ( V_47 -- )
F_389 ( V_2 -> V_66 [ V_47 ] ) ;
return V_17 ;
}
void F_385 ( struct V_56 * V_57 )
{
F_356 ( V_57 ) ;
F_382 ( V_57 -> V_77 ) ;
V_57 -> V_77 = NULL ;
if ( ! V_57 -> V_86 )
return;
F_390 ( V_57 -> V_72 , V_57 -> V_296 ,
V_57 -> V_86 , V_57 -> V_80 ) ;
V_57 -> V_86 = NULL ;
}
static void F_391 ( struct V_1 * V_2 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_76 ; V_47 ++ )
if ( V_2 -> V_57 [ V_47 ] -> V_86 )
F_385 ( V_2 -> V_57 [ V_47 ] ) ;
}
void F_389 ( struct V_56 * V_66 )
{
F_322 ( V_66 ) ;
F_382 ( V_66 -> V_70 ) ;
V_66 -> V_70 = NULL ;
if ( ! V_66 -> V_86 )
return;
F_390 ( V_66 -> V_72 , V_66 -> V_296 ,
V_66 -> V_86 , V_66 -> V_80 ) ;
V_66 -> V_86 = NULL ;
}
static void F_392 ( struct V_1 * V_2 )
{
int V_47 ;
#ifdef F_146
F_393 ( V_2 ) ;
#endif
for ( V_47 = 0 ; V_47 < V_2 -> V_92 ; V_47 ++ )
if ( V_2 -> V_66 [ V_47 ] -> V_86 )
F_389 ( V_2 -> V_66 [ V_47 ] ) ;
}
static int F_394 ( struct V_53 * V_54 , int V_754 )
{
struct V_1 * V_2 = F_86 ( V_54 ) ;
int V_511 = V_754 + V_244 + V_512 ;
if ( ( V_754 < 68 ) || ( V_511 > V_755 ) )
return - V_756 ;
if ( ( V_2 -> V_136 & V_429 ) &&
( V_2 -> V_14 . V_107 . type == V_110 ) &&
( V_511 > ( V_517 + V_512 ) ) )
F_90 ( V_170 , L_109 ) ;
F_102 ( V_170 , L_110 , V_54 -> V_312 , V_754 ) ;
V_54 -> V_312 = V_754 ;
if ( F_54 ( V_54 ) )
F_348 ( V_2 ) ;
return 0 ;
}
static int F_395 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_86 ( V_54 ) ;
int V_17 , V_376 ;
if ( F_14 ( V_757 , & V_2 -> V_34 ) )
return - V_758 ;
F_362 ( V_54 ) ;
V_17 = F_384 ( V_2 ) ;
if ( V_17 )
goto V_752;
V_17 = F_387 ( V_2 ) ;
if ( V_17 )
goto V_753;
F_336 ( V_2 ) ;
V_17 = F_235 ( V_2 ) ;
if ( V_17 )
goto V_759;
if ( V_2 -> V_624 > 1 )
V_376 = V_2 -> V_615 ;
else
V_376 = V_2 -> V_76 ;
V_17 = F_330 ( V_54 , V_376 ) ;
if ( V_17 )
goto V_760;
if ( V_2 -> V_624 > 1 &&
V_2 -> V_92 > V_761 )
V_376 = V_761 ;
else
V_376 = V_2 -> V_92 ;
V_17 = F_331 ( V_54 , V_376 ) ;
if ( V_17 )
goto V_760;
F_396 ( V_2 ) ;
F_346 ( V_2 ) ;
return 0 ;
V_760:
F_236 ( V_2 ) ;
V_759:
F_392 ( V_2 ) ;
V_753:
F_391 ( V_2 ) ;
V_752:
F_354 ( V_2 ) ;
return V_17 ;
}
static int F_397 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_86 ( V_54 ) ;
F_398 ( V_2 ) ;
F_351 ( V_2 ) ;
F_236 ( V_2 ) ;
F_360 ( V_2 ) ;
F_391 ( V_2 ) ;
F_392 ( V_2 ) ;
F_67 ( V_2 ) ;
return 0 ;
}
static int F_399 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_400 ( V_9 ) ;
struct V_53 * V_54 = V_2 -> V_54 ;
T_1 V_17 ;
V_2 -> V_14 . V_39 = V_2 -> V_417 ;
F_401 ( V_9 , V_762 ) ;
F_402 ( V_9 ) ;
F_403 ( V_9 ) ;
V_17 = F_404 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_111 ) ;
return V_17 ;
}
F_30 () ;
F_31 ( V_763 , & V_2 -> V_34 ) ;
F_405 ( V_9 ) ;
F_406 ( V_9 , false ) ;
F_354 ( V_2 ) ;
F_68 ( & V_2 -> V_14 , V_764 , ~ 0 ) ;
F_407 () ;
V_17 = F_408 ( V_2 ) ;
if ( ! V_17 && F_54 ( V_54 ) )
V_17 = F_395 ( V_54 ) ;
F_409 () ;
if ( V_17 )
return V_17 ;
F_410 ( V_54 ) ;
return 0 ;
}
static int F_411 ( struct V_5 * V_9 , bool * V_765 )
{
struct V_1 * V_2 = F_400 ( V_9 ) ;
struct V_53 * V_54 = V_2 -> V_54 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_766 , V_559 ;
T_1 V_767 = V_2 -> V_768 ;
#ifdef F_412
int V_769 = 0 ;
#endif
F_413 ( V_54 ) ;
F_407 () ;
if ( F_54 ( V_54 ) ) {
F_351 ( V_2 ) ;
F_236 ( V_2 ) ;
F_391 ( V_2 ) ;
F_392 ( V_2 ) ;
}
F_409 () ;
F_414 ( V_2 ) ;
#ifdef F_412
V_769 = F_403 ( V_9 ) ;
if ( V_769 )
return V_769 ;
#endif
if ( V_14 -> V_107 . V_357 . V_770 )
V_14 -> V_107 . V_357 . V_770 ( V_14 ) ;
if ( V_767 ) {
F_285 ( V_54 ) ;
if ( V_14 -> V_107 . V_357 . V_669 )
V_14 -> V_107 . V_357 . V_669 ( V_14 ) ;
if ( V_767 & V_771 ) {
V_559 = F_34 ( V_14 , V_563 ) ;
V_559 |= V_569 ;
F_68 ( V_14 , V_563 , V_559 ) ;
}
V_766 = F_34 ( V_14 , V_772 ) ;
V_766 |= V_773 ;
F_68 ( V_14 , V_772 , V_766 ) ;
F_68 ( V_14 , V_774 , V_767 ) ;
} else {
F_68 ( V_14 , V_775 , 0 ) ;
F_68 ( V_14 , V_774 , 0 ) ;
}
switch ( V_14 -> V_107 . type ) {
case V_108 :
F_406 ( V_9 , false ) ;
break;
case V_110 :
case V_111 :
F_406 ( V_9 , ! ! V_767 ) ;
break;
default:
break;
}
* V_765 = ! ! V_767 ;
F_67 ( V_2 ) ;
if ( ! F_15 ( V_763 , & V_2 -> V_34 ) )
F_415 ( V_9 ) ;
return 0 ;
}
static int F_416 ( struct V_5 * V_9 , T_12 V_34 )
{
int V_769 ;
bool V_776 ;
V_769 = F_411 ( V_9 , & V_776 ) ;
if ( V_769 )
return V_769 ;
if ( V_776 ) {
F_417 ( V_9 ) ;
} else {
F_406 ( V_9 , false ) ;
F_401 ( V_9 , V_777 ) ;
}
return 0 ;
}
static void F_418 ( struct V_5 * V_9 )
{
bool V_776 ;
F_411 ( V_9 , & V_776 ) ;
if ( V_778 == V_779 ) {
F_406 ( V_9 , V_776 ) ;
F_401 ( V_9 , V_777 ) ;
}
}
void F_419 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = V_2 -> V_54 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_119 * V_120 = & V_2 -> V_121 ;
T_4 V_780 = 0 ;
T_1 V_47 , V_781 = 0 , V_782 , V_783 , V_784 , V_785 , V_786 ;
T_4 V_280 = 0 , V_172 = 0 , V_787 = 0 ;
T_4 V_224 = 0 , V_305 = 0 ;
T_4 V_168 = 0 , V_141 = 0 , V_788 = 0 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_675 , & V_2 -> V_34 ) )
return;
if ( V_2 -> V_152 & V_523 ) {
T_4 V_264 = 0 ;
T_4 V_265 = 0 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_92 ; V_47 ++ ) {
V_264 += V_2 -> V_66 [ V_47 ] -> V_210 . V_264 ;
V_265 += V_2 -> V_66 [ V_47 ] -> V_210 . V_265 ;
}
V_2 -> V_789 = V_264 ;
V_2 -> V_790 = V_265 ;
}
for ( V_47 = 0 ; V_47 < V_2 -> V_92 ; V_47 ++ ) {
struct V_56 * V_66 = V_2 -> V_66 [ V_47 ] ;
V_280 += V_66 -> V_210 . V_280 ;
V_224 += V_66 -> V_210 . V_224 ;
V_305 += V_66 -> V_210 . V_305 ;
V_788 += V_66 -> V_210 . V_211 ;
V_168 += V_66 -> V_121 . V_168 ;
V_141 += V_66 -> V_121 . V_141 ;
}
V_2 -> V_280 = V_280 ;
V_2 -> V_224 = V_224 ;
V_2 -> V_305 = V_305 ;
V_2 -> V_788 = V_788 ;
V_54 -> V_121 . V_791 = V_168 ;
V_54 -> V_121 . V_792 = V_141 ;
V_168 = 0 ;
V_141 = 0 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_76 ; V_47 ++ ) {
struct V_56 * V_57 = V_2 -> V_57 [ V_47 ] ;
V_172 += V_57 -> V_149 . V_172 ;
V_787 += V_57 -> V_149 . V_787 ;
V_168 += V_57 -> V_121 . V_168 ;
V_141 += V_57 -> V_121 . V_141 ;
}
V_2 -> V_172 = V_172 ;
V_2 -> V_787 = V_787 ;
V_54 -> V_121 . V_793 = V_168 ;
V_54 -> V_121 . V_794 = V_141 ;
V_120 -> V_795 += F_34 ( V_14 , V_796 ) ;
for ( V_47 = 0 ; V_47 < 8 ; V_47 ++ ) {
V_782 = F_34 ( V_14 , F_420 ( V_47 ) ) ;
V_781 += V_782 ;
V_120 -> V_782 [ V_47 ] += V_782 ;
V_780 += V_120 -> V_782 [ V_47 ] ;
V_120 -> V_797 [ V_47 ] += F_34 ( V_14 , F_421 ( V_47 ) ) ;
V_120 -> V_798 [ V_47 ] += F_34 ( V_14 , F_422 ( V_47 ) ) ;
switch ( V_14 -> V_107 . type ) {
case V_108 :
V_120 -> V_799 [ V_47 ] += F_34 ( V_14 , F_423 ( V_47 ) ) ;
V_120 -> V_800 [ V_47 ] += F_34 ( V_14 , F_424 ( V_47 ) ) ;
V_120 -> V_801 [ V_47 ] += F_34 ( V_14 , F_425 ( V_47 ) ) ;
V_120 -> V_802 [ V_47 ] +=
F_34 ( V_14 , F_426 ( V_47 ) ) ;
break;
case V_110 :
case V_111 :
V_120 -> V_802 [ V_47 ] +=
F_34 ( V_14 , F_427 ( V_47 ) ) ;
break;
default:
break;
}
}
for ( V_47 = 0 ; V_47 < 16 ; V_47 ++ ) {
V_120 -> V_803 [ V_47 ] += F_34 ( V_14 , F_428 ( V_47 ) ) ;
V_120 -> V_804 [ V_47 ] += F_34 ( V_14 , F_429 ( V_47 ) ) ;
if ( ( V_14 -> V_107 . type == V_110 ) ||
( V_14 -> V_107 . type == V_111 ) ) {
V_120 -> V_800 [ V_47 ] += F_34 ( V_14 , F_430 ( V_47 ) ) ;
F_34 ( V_14 , F_431 ( V_47 ) ) ;
V_120 -> V_801 [ V_47 ] += F_34 ( V_14 , F_432 ( V_47 ) ) ;
F_34 ( V_14 , F_433 ( V_47 ) ) ;
}
}
V_120 -> V_805 += F_34 ( V_14 , V_806 ) ;
V_120 -> V_805 -= V_781 ;
F_80 ( V_2 ) ;
switch ( V_14 -> V_107 . type ) {
case V_108 :
V_120 -> V_807 += F_34 ( V_14 , V_808 ) ;
V_120 -> V_809 += F_34 ( V_14 , V_810 ) ;
V_120 -> V_811 += F_34 ( V_14 , V_812 ) ;
V_120 -> V_813 += F_34 ( V_14 , V_814 ) ;
break;
case V_111 :
V_120 -> V_815 += F_34 ( V_14 , V_816 ) ;
V_120 -> V_817 += F_34 ( V_14 , V_818 ) ;
V_120 -> V_819 += F_34 ( V_14 , V_820 ) ;
V_120 -> V_821 += F_34 ( V_14 , V_822 ) ;
case V_110 :
for ( V_47 = 0 ; V_47 < 16 ; V_47 ++ )
V_2 -> V_823 +=
F_34 ( V_14 , F_434 ( V_47 ) ) ;
V_120 -> V_809 += F_34 ( V_14 , V_824 ) ;
F_34 ( V_14 , V_810 ) ;
V_120 -> V_811 += F_34 ( V_14 , V_825 ) ;
F_34 ( V_14 , V_812 ) ;
V_120 -> V_813 += F_34 ( V_14 , V_826 ) ;
F_34 ( V_14 , V_814 ) ;
V_120 -> V_807 += F_34 ( V_14 , V_827 ) ;
V_120 -> V_828 += F_34 ( V_14 , V_829 ) ;
V_120 -> V_830 += F_34 ( V_14 , V_831 ) ;
#ifdef F_146
V_120 -> V_832 += F_34 ( V_14 , V_833 ) ;
V_120 -> V_834 += F_34 ( V_14 , V_835 ) ;
V_120 -> V_836 += F_34 ( V_14 , V_837 ) ;
V_120 -> V_838 += F_34 ( V_14 , V_839 ) ;
V_120 -> V_840 += F_34 ( V_14 , V_841 ) ;
V_120 -> V_842 += F_34 ( V_14 , V_843 ) ;
if ( V_2 -> V_710 . V_844 ) {
struct V_845 * V_710 = & V_2 -> V_710 ;
struct V_846 * V_844 ;
unsigned int V_173 ;
T_4 V_847 = 0 , V_848 = 0 ;
F_435 (cpu) {
V_844 = F_436 ( V_710 -> V_844 , V_173 ) ;
V_847 += V_844 -> V_847 ;
V_848 += V_844 -> V_848 ;
}
V_120 -> V_849 = V_847 ;
V_120 -> V_850 = V_848 ;
}
#endif
break;
default:
break;
}
V_783 = F_34 ( V_14 , V_851 ) ;
V_120 -> V_783 += V_783 ;
V_120 -> V_852 += F_34 ( V_14 , V_853 ) ;
if ( V_14 -> V_107 . type == V_108 )
V_120 -> V_852 -= V_783 ;
V_120 -> V_854 += F_34 ( V_14 , V_855 ) ;
V_120 -> V_856 += F_34 ( V_14 , V_857 ) ;
V_120 -> V_858 += F_34 ( V_14 , V_859 ) ;
V_120 -> V_860 += F_34 ( V_14 , V_861 ) ;
V_120 -> V_862 += F_34 ( V_14 , V_863 ) ;
V_120 -> V_864 += F_34 ( V_14 , V_865 ) ;
V_120 -> V_866 += F_34 ( V_14 , V_867 ) ;
V_120 -> V_868 += F_34 ( V_14 , V_869 ) ;
V_784 = F_34 ( V_14 , V_870 ) ;
V_120 -> V_871 += V_784 ;
V_785 = F_34 ( V_14 , V_872 ) ;
V_120 -> V_873 += V_785 ;
V_120 -> V_874 += F_34 ( V_14 , V_875 ) ;
V_120 -> V_876 += F_34 ( V_14 , V_877 ) ;
V_786 = V_784 + V_785 ;
V_120 -> V_874 -= V_786 ;
V_120 -> V_876 -= V_786 ;
V_120 -> V_811 -= ( V_786 * ( V_878 + V_512 ) ) ;
V_120 -> V_879 += F_34 ( V_14 , V_880 ) ;
V_120 -> V_881 += F_34 ( V_14 , V_882 ) ;
V_120 -> V_883 += F_34 ( V_14 , V_884 ) ;
V_120 -> V_885 += F_34 ( V_14 , V_886 ) ;
V_120 -> V_887 += F_34 ( V_14 , V_888 ) ;
V_120 -> V_887 -= V_786 ;
V_120 -> V_889 += F_34 ( V_14 , V_890 ) ;
V_120 -> V_891 += F_34 ( V_14 , V_892 ) ;
V_120 -> V_893 += F_34 ( V_14 , V_894 ) ;
V_120 -> V_895 += F_34 ( V_14 , V_896 ) ;
V_120 -> V_897 += F_34 ( V_14 , V_898 ) ;
V_120 -> V_899 += F_34 ( V_14 , V_900 ) ;
V_54 -> V_121 . V_901 = V_120 -> V_852 ;
V_54 -> V_121 . V_902 = V_120 -> V_795 + V_120 -> V_868 ;
V_54 -> V_121 . V_903 = 0 ;
V_54 -> V_121 . V_904 = V_120 -> V_868 ;
V_54 -> V_121 . V_905 = V_120 -> V_795 ;
V_54 -> V_121 . V_906 = V_780 ;
}
static void F_437 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
int V_47 ;
if ( ! ( V_2 -> V_152 & V_385 ) )
return;
V_2 -> V_152 &= ~ V_385 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
if ( ! ( V_2 -> V_136 & V_384 ) )
return;
V_2 -> V_907 ++ ;
if ( F_438 ( V_14 ) == 0 ) {
for ( V_47 = 0 ; V_47 < V_2 -> V_76 ; V_47 ++ )
F_243 ( V_393 ,
& ( V_2 -> V_57 [ V_47 ] -> V_34 ) ) ;
F_68 ( V_14 , V_375 , V_386 ) ;
} else {
F_100 ( V_170 , L_112
L_113 ) ;
}
}
static void F_439 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_4 V_908 = 0 ;
int V_47 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_675 , & V_2 -> V_34 ) )
return;
if ( F_106 ( V_2 -> V_54 ) ) {
for ( V_47 = 0 ; V_47 < V_2 -> V_76 ; V_47 ++ )
F_440 ( V_2 -> V_57 [ V_47 ] ) ;
}
if ( ! ( V_2 -> V_136 & V_408 ) ) {
F_68 ( V_14 , V_116 ,
( V_909 | V_910 ) ) ;
} else {
for ( V_47 = 0 ; V_47 < V_2 -> V_187 ; V_47 ++ ) {
struct V_155 * V_911 = V_2 -> V_156 [ V_47 ] ;
if ( V_911 -> V_316 . V_117 || V_911 -> V_160 . V_117 )
V_908 |= ( ( T_4 ) 1 << V_47 ) ;
}
}
F_72 ( V_2 , V_908 ) ;
}
static void F_441 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_912 = V_2 -> V_912 ;
bool V_359 = V_2 -> V_359 ;
bool V_132 = V_2 -> V_133 . V_134 ;
if ( ! ( V_2 -> V_136 & V_371 ) )
return;
if ( V_14 -> V_107 . V_357 . V_358 ) {
V_14 -> V_107 . V_357 . V_358 ( V_14 , & V_912 , & V_359 , false ) ;
} else {
V_912 = V_913 ;
V_359 = true ;
}
if ( V_2 -> V_135 )
V_132 |= ! ! ( V_2 -> V_135 -> V_132 ) ;
if ( V_359 && ! ( ( V_2 -> V_136 & V_137 ) && V_132 ) ) {
V_14 -> V_107 . V_357 . V_914 ( V_14 ) ;
F_442 ( V_2 ) ;
}
if ( V_359 ||
F_443 ( V_169 , ( V_2 -> V_372 +
V_915 ) ) ) {
V_2 -> V_136 &= ~ V_371 ;
F_68 ( V_14 , V_375 , V_374 ) ;
F_211 ( V_14 ) ;
}
V_2 -> V_359 = V_359 ;
V_2 -> V_912 = V_912 ;
}
static void F_444 ( struct V_1 * V_2 )
{
#ifdef F_337
struct V_53 * V_54 = V_2 -> V_54 ;
struct V_916 V_917 = {
. V_918 = V_919 ,
. V_241 = 0 ,
} ;
T_6 V_711 = 0 ;
if ( V_2 -> V_581 & V_920 )
V_711 = F_445 ( V_54 , & V_917 ) ;
V_2 -> V_921 = ( V_711 > 1 ) ? ( F_446 ( V_711 ) - 1 ) : 0 ;
#endif
}
static void F_447 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = V_2 -> V_54 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_53 * V_94 ;
struct V_627 * V_628 ;
T_1 V_912 = V_2 -> V_912 ;
bool V_922 , V_923 ;
if ( F_106 ( V_54 ) )
return;
V_2 -> V_152 &= ~ V_647 ;
switch ( V_14 -> V_107 . type ) {
case V_108 : {
T_1 V_924 = F_34 ( V_14 , V_563 ) ;
T_1 V_925 = F_34 ( V_14 , V_926 ) ;
V_922 = ! ! ( V_924 & V_927 ) ;
V_923 = ! ! ( V_925 & V_928 ) ;
}
break;
case V_111 :
case V_110 : {
T_1 V_929 = F_34 ( V_14 , V_930 ) ;
T_1 V_931 = F_34 ( V_14 , V_932 ) ;
V_922 = ! ! ( V_929 & V_933 ) ;
V_923 = ! ! ( V_931 & V_934 ) ;
}
break;
default:
V_923 = false ;
V_922 = false ;
break;
}
V_2 -> V_935 = V_169 ;
if ( F_14 ( V_684 , & V_2 -> V_34 ) )
F_448 ( V_2 ) ;
F_102 ( V_154 , L_114 ,
( V_912 == V_913 ?
L_115 :
( V_912 == V_936 ?
L_116 :
( V_912 == V_937 ?
L_117 :
L_118 ) ) ) ,
( ( V_922 && V_923 ) ? L_119 :
( V_922 ? L_120 :
( V_923 ? L_121 : L_122 ) ) ) ) ;
F_449 ( V_54 ) ;
F_450 ( V_2 ) ;
F_451 ( V_2 -> V_54 ) ;
F_407 () ;
F_334 (adapter->netdev, upper, iter) {
if ( F_335 ( V_94 ) ) {
struct V_629 * V_235 = F_86 ( V_94 ) ;
if ( V_235 -> V_631 )
F_451 ( V_94 ) ;
}
}
F_409 () ;
F_444 ( V_2 ) ;
F_365 ( V_2 ) ;
}
static void F_452 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = V_2 -> V_54 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
V_2 -> V_359 = false ;
V_2 -> V_912 = 0 ;
if ( ! F_106 ( V_54 ) )
return;
if ( F_341 ( V_14 ) && V_14 -> V_107 . type == V_108 )
V_2 -> V_152 |= V_647 ;
if ( F_14 ( V_684 , & V_2 -> V_34 ) )
F_448 ( V_2 ) ;
F_102 ( V_154 , L_123 ) ;
F_362 ( V_54 ) ;
F_365 ( V_2 ) ;
}
static void F_453 ( struct V_1 * V_2 )
{
int V_47 ;
int V_938 = 0 ;
if ( ! F_106 ( V_2 -> V_54 ) ) {
for ( V_47 = 0 ; V_47 < V_2 -> V_76 ; V_47 ++ ) {
struct V_56 * V_57 = V_2 -> V_57 [ V_47 ] ;
if ( V_57 -> V_79 != V_57 -> V_78 ) {
V_938 = 1 ;
break;
}
}
if ( V_938 ) {
F_90 ( V_154 , L_124 ) ;
V_2 -> V_152 |= V_153 ;
}
}
}
static void F_454 ( struct V_1 * V_2 )
{
T_1 V_939 ;
if ( V_2 -> V_14 . V_107 . type == V_108 ||
V_2 -> V_324 == 0 )
return;
V_939 = F_34 ( & V_2 -> V_14 , V_940 ) ;
if ( ! V_939 )
return;
F_90 ( V_154 , L_125 , V_939 ) ;
}
static void F_455 ( struct V_1 * V_2 )
{
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_675 , & V_2 -> V_34 ) )
return;
F_441 ( V_2 ) ;
if ( V_2 -> V_359 )
F_447 ( V_2 ) ;
else
F_452 ( V_2 ) ;
F_454 ( V_2 ) ;
F_419 ( V_2 ) ;
F_453 ( V_2 ) ;
}
static void F_456 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_3 V_17 ;
if ( ! ( V_2 -> V_152 & V_647 ) &&
! ( V_2 -> V_152 & V_368 ) )
return;
if ( F_15 ( V_676 , & V_2 -> V_34 ) )
return;
V_17 = V_14 -> V_360 . V_357 . V_941 ( V_14 ) ;
if ( V_17 == V_679 )
goto V_942;
if ( V_17 == V_678 ) {
V_2 -> V_152 |= V_368 ;
}
if ( V_17 )
goto V_942;
if ( ! ( V_2 -> V_152 & V_368 ) )
goto V_942;
V_2 -> V_152 &= ~ V_368 ;
if ( V_14 -> V_107 . type == V_108 )
V_17 = V_14 -> V_360 . V_357 . V_943 ( V_14 ) ;
else
V_17 = V_14 -> V_107 . V_357 . V_944 ( V_14 ) ;
if ( V_17 == V_679 )
goto V_942;
V_2 -> V_136 |= V_369 ;
F_102 ( V_170 , L_126 , V_14 -> V_360 . V_945 ) ;
V_942:
F_31 ( V_676 , & V_2 -> V_34 ) ;
if ( ( V_17 == V_679 ) &&
( V_2 -> V_54 -> V_946 == V_947 ) ) {
F_18 ( L_127
L_128 ) ;
F_18 ( L_129
L_130 ) ;
F_457 ( V_2 -> V_54 ) ;
}
}
static void F_458 ( struct V_1 * V_2 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_20 ;
bool V_648 = false ;
if ( ! ( V_2 -> V_136 & V_369 ) )
return;
if ( F_15 ( V_676 , & V_2 -> V_34 ) )
return;
V_2 -> V_136 &= ~ V_369 ;
V_20 = V_14 -> V_360 . V_651 ;
if ( ( ! V_20 ) && ( V_14 -> V_107 . V_357 . V_652 ) ) {
V_14 -> V_107 . V_357 . V_652 ( V_14 , & V_20 , & V_648 ) ;
if ( ! V_648 ) {
if ( V_20 & V_913 )
V_20 = V_913 ;
}
}
if ( V_14 -> V_107 . V_357 . V_653 )
V_14 -> V_107 . V_357 . V_653 ( V_14 , V_20 , true ) ;
V_2 -> V_136 |= V_371 ;
V_2 -> V_372 = V_169 ;
F_31 ( V_676 , & V_2 -> V_34 ) ;
}
static void F_459 ( struct V_1 * V_2 )
{
int V_948 ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_53 * V_54 = V_2 -> V_54 ;
T_1 V_949 ;
T_1 V_950 , V_951 ;
V_949 = F_34 ( V_14 , V_952 ) ;
if ( V_949 )
return;
for ( V_948 = 0 ; V_948 < V_2 -> V_324 ; V_948 ++ ) {
V_950 = ( V_948 << 16 ) | 0x80000000 ;
V_950 |= V_953 ;
F_68 ( V_14 , V_954 , V_950 ) ;
V_951 = F_34 ( V_14 , V_955 ) ;
V_950 &= 0x7FFFFFFF ;
F_68 ( V_14 , V_954 , V_950 ) ;
V_951 >>= 16 ;
if ( V_951 & V_956 ) {
F_460 ( V_54 , L_131 , V_948 ) ;
V_950 = ( V_948 << 16 ) | 0x80000000 ;
V_950 |= 0xA8 ;
F_68 ( V_14 , V_954 , V_950 ) ;
V_951 = 0x00008000 ;
F_68 ( V_14 , V_955 , V_951 ) ;
V_950 &= 0x7FFFFFFF ;
F_68 ( V_14 , V_954 , V_950 ) ;
}
}
}
static void F_461 ( unsigned long V_91 )
{
struct V_1 * V_2 = (struct V_1 * ) V_91 ;
unsigned long V_957 ;
bool V_958 = true ;
if ( V_2 -> V_136 & V_371 )
V_957 = V_959 / 10 ;
else
V_957 = V_959 * 2 ;
#ifdef F_373
if ( ! V_2 -> V_324 ||
( V_2 -> V_136 & V_371 ) )
goto V_960;
F_459 ( V_2 ) ;
V_957 = V_959 / 50 ;
V_2 -> V_961 ++ ;
if ( V_2 -> V_961 >= 100 )
V_2 -> V_961 = 0 ;
else
V_958 = false ;
V_960:
#endif
F_347 ( & V_2 -> V_673 , V_957 + V_169 ) ;
if ( V_958 )
F_13 ( V_2 ) ;
}
static void F_462 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_152 & V_153 ) )
return;
V_2 -> V_152 &= ~ V_153 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) ||
F_14 ( V_35 , & V_2 -> V_34 ) ||
F_14 ( V_675 , & V_2 -> V_34 ) )
return;
F_51 ( V_2 ) ;
F_460 ( V_2 -> V_54 , L_132 ) ;
V_2 -> V_171 ++ ;
F_407 () ;
F_348 ( V_2 ) ;
F_409 () ;
}
static void F_463 ( struct V_962 * V_963 )
{
struct V_1 * V_2 = F_195 ( V_963 ,
struct V_1 ,
V_37 ) ;
if ( F_23 ( V_2 -> V_14 . V_39 ) ) {
if ( ! F_14 ( V_33 , & V_2 -> V_34 ) ) {
F_407 () ;
F_351 ( V_2 ) ;
F_409 () ;
}
F_28 ( V_2 ) ;
return;
}
F_462 ( V_2 ) ;
F_456 ( V_2 ) ;
F_458 ( V_2 ) ;
F_205 ( V_2 ) ;
F_455 ( V_2 ) ;
F_437 ( V_2 ) ;
F_439 ( V_2 ) ;
if ( F_14 ( V_684 , & V_2 -> V_34 ) ) {
F_464 ( V_2 ) ;
F_465 ( V_2 ) ;
}
F_28 ( V_2 ) ;
}
static int F_466 ( struct V_56 * V_57 ,
struct V_58 * V_964 ,
T_6 * V_259 )
{
struct V_193 * V_88 = V_964 -> V_88 ;
T_1 V_965 , V_966 ;
T_1 V_967 , V_968 ;
int V_17 ;
if ( V_88 -> V_216 != V_969 )
return 0 ;
if ( ! F_467 ( V_88 ) )
return 0 ;
V_17 = F_468 ( V_88 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_966 = V_970 ;
if ( V_964 -> V_241 == F_145 ( V_249 ) ) {
struct V_236 * V_971 = F_469 ( V_88 ) ;
V_971 -> V_972 = 0 ;
V_971 -> V_973 = 0 ;
F_470 ( V_88 ) -> V_973 = ~ F_471 ( V_971 -> V_974 ,
V_971 -> V_975 , 0 ,
V_255 ,
0 ) ;
V_966 |= V_976 ;
V_964 -> V_977 |= V_978 |
V_979 |
V_980 ;
} else if ( F_472 ( V_88 ) ) {
F_473 ( V_88 ) -> V_981 = 0 ;
F_470 ( V_88 ) -> V_973 =
~ F_474 ( & F_473 ( V_88 ) -> V_974 ,
& F_473 ( V_88 ) -> V_975 ,
0 , V_255 , 0 ) ;
V_964 -> V_977 |= V_978 |
V_979 ;
}
V_968 = F_475 ( V_88 ) ;
* V_259 = F_476 ( V_88 ) + V_968 ;
V_964 -> V_166 = F_149 ( V_88 ) -> V_166 ;
V_964 -> V_165 += ( V_964 -> V_166 - 1 ) * * V_259 ;
V_967 = V_968 << V_982 ;
V_967 |= F_149 ( V_88 ) -> V_260 << V_983 ;
V_965 = F_477 ( V_88 ) ;
V_965 |= F_478 ( V_88 ) << V_984 ;
V_965 |= V_964 -> V_977 & V_985 ;
F_479 ( V_57 , V_965 , 0 , V_966 ,
V_967 ) ;
return 1 ;
}
static void F_480 ( struct V_56 * V_57 ,
struct V_58 * V_964 )
{
struct V_193 * V_88 = V_964 -> V_88 ;
T_1 V_965 = 0 ;
T_1 V_967 = 0 ;
T_1 V_966 = 0 ;
if ( V_88 -> V_216 != V_969 ) {
if ( ! ( V_964 -> V_977 & V_986 ) &&
! ( V_964 -> V_977 & V_987 ) )
return;
} else {
T_6 V_988 = 0 ;
switch ( V_964 -> V_241 ) {
case F_145 ( V_249 ) :
V_965 |= F_477 ( V_88 ) ;
V_966 |= V_976 ;
V_988 = F_469 ( V_88 ) -> V_241 ;
break;
case F_145 ( V_252 ) :
V_965 |= F_477 ( V_88 ) ;
V_988 = F_473 ( V_88 ) -> V_242 ;
break;
default:
if ( F_94 ( F_481 () ) ) {
F_482 ( V_57 -> V_72 ,
L_133 ,
V_964 -> V_241 ) ;
}
break;
}
switch ( V_988 ) {
case V_255 :
V_966 |= V_970 ;
V_967 = F_475 ( V_88 ) <<
V_982 ;
break;
case V_989 :
V_966 |= V_990 ;
V_967 = sizeof( struct V_991 ) <<
V_982 ;
break;
case V_257 :
V_967 = sizeof( struct V_258 ) <<
V_982 ;
break;
default:
if ( F_94 ( F_481 () ) ) {
F_482 ( V_57 -> V_72 ,
L_134 ,
V_988 ) ;
}
break;
}
V_964 -> V_977 |= V_979 ;
}
V_965 |= F_478 ( V_88 ) << V_984 ;
V_965 |= V_964 -> V_977 & V_985 ;
F_479 ( V_57 , V_965 , 0 ,
V_966 , V_967 ) ;
}
static T_1 F_483 ( struct V_193 * V_88 , T_1 V_977 )
{
T_1 V_992 = V_993 |
V_994 |
V_995 ;
V_992 |= F_484 ( V_977 , V_986 ,
V_996 ) ;
V_992 |= F_484 ( V_977 , V_978 ,
V_997 ) ;
V_992 |= F_484 ( V_977 , V_998 ,
V_999 ) ;
V_992 ^= F_484 ( V_88 -> V_1000 , 1 , V_995 ) ;
return V_992 ;
}
static void F_485 ( union V_60 * V_61 ,
T_1 V_977 , unsigned int V_1001 )
{
T_1 V_1002 = V_1001 << V_1003 ;
V_1002 |= F_484 ( V_977 ,
V_979 ,
V_1004 ) ;
V_1002 |= F_484 ( V_977 ,
V_980 ,
V_1005 ) ;
V_1002 |= F_484 ( V_977 ,
V_987 ,
V_1006 ) ;
V_61 -> V_227 . V_1002 = F_93 ( V_1002 ) ;
}
static void F_486 ( struct V_56 * V_57 ,
struct V_58 * V_964 ,
const T_6 V_259 )
{
struct V_193 * V_88 = V_964 -> V_88 ;
struct V_58 * V_59 ;
union V_60 * V_61 ;
struct V_281 * V_282 ;
T_8 V_80 ;
unsigned int V_287 , V_296 ;
T_1 V_977 = V_964 -> V_977 ;
T_1 V_992 = F_483 ( V_88 , V_977 ) ;
T_2 V_47 = V_57 -> V_79 ;
V_61 = F_58 ( V_57 , V_47 ) ;
F_485 ( V_61 , V_977 , V_88 -> V_81 - V_259 ) ;
V_296 = F_148 ( V_88 ) ;
V_287 = V_88 -> V_287 ;
#ifdef F_146
if ( V_977 & V_1007 ) {
if ( V_287 < sizeof( struct V_315 ) ) {
V_296 -= sizeof( struct V_315 ) - V_287 ;
V_287 = 0 ;
} else {
V_287 -= sizeof( struct V_315 ) ;
}
}
#endif
V_80 = F_487 ( V_57 -> V_72 , V_88 -> V_91 , V_296 , V_118 ) ;
V_59 = V_964 ;
for ( V_282 = & F_149 ( V_88 ) -> V_283 [ 0 ] ; ; V_282 ++ ) {
if ( F_140 ( V_57 -> V_72 , V_80 ) )
goto V_1008;
F_78 ( V_59 , V_81 , V_296 ) ;
F_488 ( V_59 , V_80 , V_80 ) ;
V_61 -> V_227 . V_1009 = F_143 ( V_80 ) ;
while ( F_94 ( V_296 > V_1010 ) ) {
V_61 -> V_227 . V_1011 =
F_93 ( V_992 ^ V_1010 ) ;
V_47 ++ ;
V_61 ++ ;
if ( V_47 == V_57 -> V_87 ) {
V_61 = F_58 ( V_57 , 0 ) ;
V_47 = 0 ;
}
V_61 -> V_227 . V_1002 = 0 ;
V_80 += V_1010 ;
V_296 -= V_1010 ;
V_61 -> V_227 . V_1009 = F_143 ( V_80 ) ;
}
if ( F_96 ( ! V_287 ) )
break;
V_61 -> V_227 . V_1011 = F_93 ( V_992 ^ V_296 ) ;
V_47 ++ ;
V_61 ++ ;
if ( V_47 == V_57 -> V_87 ) {
V_61 = F_58 ( V_57 , 0 ) ;
V_47 = 0 ;
}
V_61 -> V_227 . V_1002 = 0 ;
#ifdef F_146
V_296 = F_329 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_296 = F_489 ( V_282 ) ;
#endif
V_287 -= V_296 ;
V_80 = F_490 ( V_57 -> V_72 , V_282 , 0 , V_296 ,
V_118 ) ;
V_59 = & V_57 -> V_77 [ V_47 ] ;
}
V_992 |= V_296 | V_1012 ;
V_61 -> V_227 . V_1011 = F_93 ( V_992 ) ;
F_491 ( F_104 ( V_57 ) , V_964 -> V_165 ) ;
V_964 -> V_83 = V_169 ;
F_133 () ;
V_964 -> V_82 = V_61 ;
V_47 ++ ;
if ( V_47 == V_57 -> V_87 )
V_47 = 0 ;
V_57 -> V_79 = V_47 ;
F_134 ( V_57 , V_47 ) ;
return;
V_1008:
F_383 ( V_57 -> V_72 , L_135 ) ;
for (; ; ) {
V_59 = & V_57 -> V_77 [ V_47 ] ;
F_74 ( V_57 , V_59 ) ;
if ( V_59 == V_964 )
break;
if ( V_47 == 0 )
V_47 = V_57 -> V_87 ;
V_47 -- ;
}
V_57 -> V_79 = V_47 ;
}
static void F_492 ( struct V_56 * V_117 ,
struct V_58 * V_964 )
{
struct V_155 * V_156 = V_117 -> V_156 ;
union V_1013 V_1014 = { . V_1015 = 0 } ;
union V_1013 V_1016 = { . V_1015 = 0 } ;
union {
unsigned char * V_231 ;
struct V_236 * V_237 ;
struct V_238 * V_239 ;
} V_240 ;
struct V_256 * V_1017 ;
T_9 V_1018 ;
if ( ! V_156 )
return;
if ( ! V_117 -> V_419 )
return;
V_117 -> V_420 ++ ;
V_240 . V_231 = F_493 ( V_964 -> V_88 ) ;
if ( ( V_964 -> V_241 != F_145 ( V_252 ) ||
V_240 . V_239 -> V_242 != V_255 ) &&
( V_964 -> V_241 != F_145 ( V_249 ) ||
V_240 . V_237 -> V_241 != V_255 ) )
return;
V_1017 = F_470 ( V_964 -> V_88 ) ;
if ( ! V_1017 || V_1017 -> V_1019 )
return;
if ( ! V_1017 -> V_1020 && ( V_117 -> V_420 < V_117 -> V_419 ) )
return;
V_117 -> V_420 = 0 ;
V_1018 = F_145 ( V_964 -> V_977 >> V_1021 ) ;
V_1014 . V_1022 . V_1018 = V_1018 ;
if ( V_964 -> V_977 & ( V_1023 | V_986 ) )
V_1016 . V_1024 . V_1025 ^= V_1017 -> V_1026 ^ F_145 ( V_246 ) ;
else
V_1016 . V_1024 . V_1025 ^= V_1017 -> V_1026 ^ V_964 -> V_241 ;
V_1016 . V_1024 . V_1027 ^= V_1017 -> V_1028 ;
if ( V_964 -> V_241 == F_145 ( V_249 ) ) {
V_1014 . V_1022 . V_1029 = V_1030 ;
V_1016 . V_1031 ^= V_240 . V_237 -> V_974 ^ V_240 . V_237 -> V_975 ;
} else {
V_1014 . V_1022 . V_1029 = V_1032 ;
V_1016 . V_1031 ^= V_240 . V_239 -> V_974 . V_1033 [ 0 ] ^
V_240 . V_239 -> V_974 . V_1033 [ 1 ] ^
V_240 . V_239 -> V_974 . V_1033 [ 2 ] ^
V_240 . V_239 -> V_974 . V_1033 [ 3 ] ^
V_240 . V_239 -> V_975 . V_1033 [ 0 ] ^
V_240 . V_239 -> V_975 . V_1033 [ 1 ] ^
V_240 . V_239 -> V_975 . V_1033 [ 2 ] ^
V_240 . V_239 -> V_975 . V_1033 [ 3 ] ;
}
F_494 ( & V_156 -> V_2 -> V_14 ,
V_1014 , V_1016 , V_117 -> V_85 ) ;
}
static int F_495 ( struct V_56 * V_57 , T_2 V_296 )
{
F_101 ( V_57 -> V_54 , V_57 -> V_85 ) ;
F_108 () ;
if ( F_96 ( F_107 ( V_57 ) < V_296 ) )
return - V_758 ;
F_496 ( V_57 -> V_54 , V_57 -> V_85 ) ;
++ V_57 -> V_149 . V_172 ;
return 0 ;
}
static inline int F_497 ( struct V_56 * V_57 , T_2 V_296 )
{
if ( F_96 ( F_107 ( V_57 ) >= V_296 ) )
return 0 ;
return F_495 ( V_57 , V_296 ) ;
}
static T_2 F_498 ( struct V_53 * V_72 , struct V_193 * V_88 ,
void * V_1034 , T_13 V_1035 )
{
struct V_613 * V_1036 = V_1034 ;
#ifdef F_146
struct V_1 * V_2 ;
struct V_1037 * V_1038 ;
int V_1039 ;
#endif
if ( V_1036 )
return V_88 -> V_1040 + V_1036 -> V_621 ;
#ifdef F_146
switch ( F_499 ( V_88 ) ) {
case F_145 ( V_253 ) :
case F_145 ( V_1041 ) :
V_2 = F_86 ( V_72 ) ;
if ( V_2 -> V_136 & V_515 )
break;
default:
return V_1035 ( V_72 , V_88 ) ;
}
V_1038 = & V_2 -> V_434 [ V_1042 ] ;
V_1039 = F_500 ( V_88 ) ? F_501 ( V_88 ) :
F_502 () ;
while ( V_1039 >= V_1038 -> V_436 )
V_1039 -= V_1038 -> V_436 ;
return V_1039 + V_1038 -> V_1043 ;
#else
return V_1035 ( V_72 , V_88 ) ;
#endif
}
T_14 F_503 ( struct V_193 * V_88 ,
struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_58 * V_964 ;
int V_1044 ;
T_1 V_977 = 0 ;
unsigned short V_1038 ;
T_2 V_87 = F_504 ( F_148 ( V_88 ) ) ;
T_9 V_241 = V_88 -> V_241 ;
T_6 V_259 = 0 ;
for ( V_1038 = 0 ; V_1038 < F_149 ( V_88 ) -> V_302 ; V_1038 ++ )
V_87 += F_504 ( F_149 ( V_88 ) -> V_283 [ V_1038 ] . V_296 ) ;
if ( F_497 ( V_57 , V_87 + 3 ) ) {
V_57 -> V_149 . V_787 ++ ;
return V_1045 ;
}
V_964 = & V_57 -> V_77 [ V_57 -> V_79 ] ;
V_964 -> V_88 = V_88 ;
V_964 -> V_165 = V_88 -> V_81 ;
V_964 -> V_166 = 1 ;
if ( F_505 ( V_88 ) ) {
V_977 |= F_506 ( V_88 ) << V_1021 ;
V_977 |= V_986 ;
} else if ( V_241 == F_145 ( V_246 ) ) {
struct V_234 * V_1046 , V_1047 ;
V_1046 = F_507 ( V_88 , V_244 , sizeof( V_1047 ) , & V_1047 ) ;
if ( ! V_1046 )
goto V_1048;
V_241 = V_1046 -> V_248 ;
V_977 |= F_508 ( V_1046 -> V_1049 ) <<
V_1021 ;
V_977 |= V_1023 ;
}
if ( F_94 ( F_149 ( V_88 ) -> V_977 & V_1050 &&
! F_509 ( V_1051 ,
& V_2 -> V_34 ) ) ) {
F_149 ( V_88 ) -> V_977 |= V_1052 ;
V_977 |= V_998 ;
V_2 -> V_1053 = F_510 ( V_88 ) ;
V_2 -> V_1054 = V_169 ;
F_16 ( & V_2 -> V_1055 ) ;
}
F_511 ( V_88 ) ;
#ifdef F_373
if ( V_2 -> V_136 & V_429 )
V_977 |= V_987 ;
#endif
if ( ( V_2 -> V_136 & V_137 ) &&
( ( V_977 & ( V_986 | V_1023 ) ) ||
( V_88 -> V_1056 != V_1057 ) ) ) {
V_977 &= ~ V_1058 ;
V_977 |= ( V_88 -> V_1056 & 0x7 ) <<
V_1059 ;
if ( V_977 & V_1023 ) {
struct V_1060 * V_1046 ;
if ( F_468 ( V_88 , 0 ) )
goto V_1048;
V_1046 = (struct V_1060 * ) V_88 -> V_91 ;
V_1046 -> V_1049 = F_145 ( V_977 >>
V_1021 ) ;
} else {
V_977 |= V_986 ;
}
}
V_964 -> V_977 = V_977 ;
V_964 -> V_241 = V_241 ;
#ifdef F_146
if ( ( V_241 == F_145 ( V_253 ) ) &&
( V_57 -> V_54 -> V_194 & ( V_1061 | V_1062 ) ) ) {
V_1044 = F_512 ( V_57 , V_964 , & V_259 ) ;
if ( V_1044 < 0 )
goto V_1048;
goto V_1063;
}
#endif
V_1044 = F_466 ( V_57 , V_964 , & V_259 ) ;
if ( V_1044 < 0 )
goto V_1048;
else if ( ! V_1044 )
F_480 ( V_57 , V_964 ) ;
if ( F_14 ( V_393 , & V_57 -> V_34 ) )
F_492 ( V_57 , V_964 ) ;
#ifdef F_146
V_1063:
#endif
F_486 ( V_57 , V_964 , V_259 ) ;
F_497 ( V_57 , V_1064 ) ;
return V_1065 ;
V_1048:
F_75 ( V_964 -> V_88 ) ;
V_964 -> V_88 = NULL ;
return V_1065 ;
}
static T_14 F_513 ( struct V_193 * V_88 ,
struct V_53 * V_54 ,
struct V_56 * V_117 )
{
struct V_1 * V_2 = F_86 ( V_54 ) ;
struct V_56 * V_57 ;
if ( F_94 ( V_88 -> V_81 < 17 ) ) {
if ( F_175 ( V_88 , 17 - V_88 -> V_81 ) )
return V_1065 ;
V_88 -> V_81 = 17 ;
F_514 ( V_88 , 17 ) ;
}
V_57 = V_117 ? V_117 : V_2 -> V_57 [ V_88 -> V_1040 ] ;
return F_503 ( V_88 , V_2 , V_57 ) ;
}
static T_14 F_515 ( struct V_193 * V_88 ,
struct V_53 * V_54 )
{
return F_513 ( V_88 , V_54 , NULL ) ;
}
static int F_516 ( struct V_53 * V_54 , void * V_1066 )
{
struct V_1 * V_2 = F_86 ( V_54 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_1067 * V_556 = V_1066 ;
if ( ! F_332 ( V_556 -> V_1068 ) )
return - V_1069 ;
memcpy ( V_54 -> V_626 , V_556 -> V_1068 , V_54 -> V_1070 ) ;
memcpy ( V_14 -> V_107 . V_556 , V_556 -> V_1068 , V_54 -> V_1070 ) ;
V_14 -> V_107 . V_357 . V_555 ( V_14 , 0 , V_14 -> V_107 . V_556 , F_264 ( 0 ) , V_557 ) ;
return 0 ;
}
static int
F_517 ( struct V_53 * V_54 , int V_1071 , int V_1072 , T_2 V_556 )
{
struct V_1 * V_2 = F_86 ( V_54 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_4 ;
int V_1073 ;
if ( V_1071 != V_14 -> V_360 . V_1074 . V_1071 )
return - V_756 ;
V_1073 = V_14 -> V_360 . V_357 . V_1075 ( V_14 , V_556 , V_1072 , & V_4 ) ;
if ( ! V_1073 )
V_1073 = V_4 ;
return V_1073 ;
}
static int F_518 ( struct V_53 * V_54 , int V_1071 , int V_1072 ,
T_2 V_556 , T_2 V_4 )
{
struct V_1 * V_2 = F_86 ( V_54 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( V_1071 != V_14 -> V_360 . V_1074 . V_1071 )
return - V_756 ;
return V_14 -> V_360 . V_357 . V_1076 ( V_14 , V_556 , V_1072 , V_4 ) ;
}
static int F_519 ( struct V_53 * V_54 , struct V_1077 * V_1078 , int V_1079 )
{
struct V_1 * V_2 = F_86 ( V_54 ) ;
switch ( V_1079 ) {
case V_1080 :
return F_520 ( V_2 , V_1078 ) ;
case V_1081 :
return F_521 ( V_2 , V_1078 ) ;
default:
return F_522 ( & V_2 -> V_14 . V_360 . V_1074 , F_523 ( V_1078 ) , V_1079 ) ;
}
}
static int F_524 ( struct V_53 * V_72 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_86 ( V_72 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
if ( F_332 ( V_14 -> V_107 . V_1082 ) ) {
F_407 () ;
V_17 = F_525 ( V_72 , V_14 -> V_107 . V_1082 , V_1083 ) ;
F_409 () ;
V_14 -> V_107 . V_357 . V_683 ( V_14 , F_264 ( 0 ) ) ;
}
return V_17 ;
}
static int F_526 ( struct V_53 * V_72 )
{
int V_17 = 0 ;
struct V_1 * V_2 = F_86 ( V_72 ) ;
struct V_1084 * V_107 = & V_2 -> V_14 . V_107 ;
if ( F_332 ( V_107 -> V_1082 ) ) {
F_407 () ;
V_17 = F_527 ( V_72 , V_107 -> V_1082 , V_1083 ) ;
F_409 () ;
}
return V_17 ;
}
static void F_528 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_86 ( V_54 ) ;
int V_47 ;
if ( F_14 ( V_33 , & V_2 -> V_34 ) )
return;
V_2 -> V_136 |= V_270 ;
if ( V_2 -> V_136 & V_408 ) {
for ( V_47 = 0 ; V_47 < V_2 -> V_187 ; V_47 ++ )
F_221 ( 0 , V_2 -> V_156 [ V_47 ] ) ;
} else {
F_234 ( V_2 -> V_9 -> V_387 , V_54 ) ;
}
V_2 -> V_136 &= ~ V_270 ;
}
static struct V_1085 * F_529 ( struct V_53 * V_54 ,
struct V_1085 * V_121 )
{
struct V_1 * V_2 = F_86 ( V_54 ) ;
int V_47 ;
F_530 () ;
for ( V_47 = 0 ; V_47 < V_2 -> V_92 ; V_47 ++ ) {
struct V_56 * V_117 = F_531 ( V_2 -> V_66 [ V_47 ] ) ;
T_4 V_168 , V_141 ;
unsigned int V_1086 ;
if ( V_117 ) {
do {
V_1086 = F_532 ( & V_117 -> V_167 ) ;
V_141 = V_117 -> V_121 . V_141 ;
V_168 = V_117 -> V_121 . V_168 ;
} while ( F_533 ( & V_117 -> V_167 , V_1086 ) );
V_121 -> V_792 += V_141 ;
V_121 -> V_791 += V_168 ;
}
}
for ( V_47 = 0 ; V_47 < V_2 -> V_76 ; V_47 ++ ) {
struct V_56 * V_117 = F_531 ( V_2 -> V_57 [ V_47 ] ) ;
T_4 V_168 , V_141 ;
unsigned int V_1086 ;
if ( V_117 ) {
do {
V_1086 = F_532 ( & V_117 -> V_167 ) ;
V_141 = V_117 -> V_121 . V_141 ;
V_168 = V_117 -> V_121 . V_168 ;
} while ( F_533 ( & V_117 -> V_167 , V_1086 ) );
V_121 -> V_794 += V_141 ;
V_121 -> V_793 += V_168 ;
}
}
F_534 () ;
V_121 -> V_901 = V_54 -> V_121 . V_901 ;
V_121 -> V_902 = V_54 -> V_121 . V_902 ;
V_121 -> V_904 = V_54 -> V_121 . V_904 ;
V_121 -> V_905 = V_54 -> V_121 . V_905 ;
V_121 -> V_906 = V_54 -> V_121 . V_906 ;
return V_121 ;
}
static void F_535 ( struct V_1 * V_2 , T_6 V_131 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_1 V_3 , V_1087 ;
int V_47 ;
if ( V_14 -> V_107 . type == V_108 )
return;
V_3 = F_34 ( V_14 , V_1088 ) ;
V_1087 = V_3 ;
for ( V_47 = 0 ; V_47 < V_722 ; V_47 ++ ) {
T_6 V_1089 = V_3 >> ( V_47 * V_1090 ) ;
if ( V_1089 > V_131 )
V_3 &= ~ ( 0x7 << V_1090 ) ;
}
if ( V_3 != V_1087 )
F_68 ( V_14 , V_1088 , V_3 ) ;
return;
}
static void F_536 ( struct V_1 * V_2 )
{
struct V_53 * V_72 = V_2 -> V_54 ;
struct V_1091 * V_133 = & V_2 -> V_133 ;
struct V_1092 * V_1093 = V_2 -> V_585 ;
T_6 V_1094 ;
for ( V_1094 = 0 ; V_1094 < V_1095 ; V_1094 ++ ) {
T_6 V_131 = 0 ;
if ( V_2 -> V_581 & V_582 )
V_131 = F_537 ( V_133 , 0 , V_1094 ) ;
else if ( V_1093 )
V_131 = V_1093 -> V_586 [ V_1094 ] ;
F_538 ( V_72 , V_1094 , V_131 ) ;
}
}
int F_539 ( struct V_53 * V_72 , T_6 V_131 )
{
struct V_1 * V_2 = F_86 ( V_72 ) ;
struct V_15 * V_14 = & V_2 -> V_14 ;
bool V_1096 ;
if ( V_131 > V_2 -> V_133 . V_718 . V_719 ||
( V_14 -> V_107 . type == V_108 &&
V_131 < V_722 ) )
return - V_756 ;
V_1096 = ( F_540 ( & V_2 -> V_623 , 32 ) > 1 ) ;
if ( V_131 && V_1096 && V_2 -> V_624 > V_1097 )
return - V_758 ;
if ( F_54 ( V_72 ) )
F_397 ( V_72 ) ;
F_414 ( V_2 ) ;
#ifdef F_337
if ( V_131 ) {
F_541 ( V_72 , V_131 ) ;
F_536 ( V_2 ) ;
V_2 -> V_136 |= V_137 ;
if ( V_2 -> V_14 . V_107 . type == V_108 ) {
V_2 -> V_1098 = V_2 -> V_14 . V_122 . V_734 ;
V_2 -> V_14 . V_122 . V_734 = V_1099 ;
}
} else {
F_542 ( V_72 ) ;
if ( V_2 -> V_14 . V_107 . type == V_108 )
V_2 -> V_14 . V_122 . V_734 = V_2 -> V_1098 ;
V_2 -> V_136 &= ~ V_137 ;
V_2 -> V_733 . V_134 = false ;
V_2 -> V_133 . V_134 = false ;
}
F_535 ( V_2 , V_131 ) ;
#endif
F_408 ( V_2 ) ;
if ( F_54 ( V_72 ) )
return F_395 ( V_72 ) ;
return 0 ;
}
void F_543 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = V_2 -> V_54 ;
F_407 () ;
F_539 ( V_54 , F_247 ( V_54 ) ) ;
F_409 () ;
}
void F_544 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_86 ( V_54 ) ;
if ( F_54 ( V_54 ) )
F_348 ( V_2 ) ;
else
F_354 ( V_2 ) ;
}
static T_15 F_545 ( struct V_53 * V_54 ,
T_15 V_194 )
{
struct V_1 * V_2 = F_86 ( V_54 ) ;
if ( ! ( V_194 & V_207 ) )
V_194 &= ~ V_1100 ;
if ( ! ( V_2 -> V_152 & V_703 ) )
V_194 &= ~ V_1100 ;
return V_194 ;
}
static int F_546 ( struct V_53 * V_54 ,
T_15 V_194 )
{
struct V_1 * V_2 = F_86 ( V_54 ) ;
T_15 V_1101 = V_54 -> V_194 ^ V_194 ;
bool V_1102 = false ;
if ( ! ( V_194 & V_1100 ) ) {
if ( V_2 -> V_152 & V_523 )
V_1102 = true ;
V_2 -> V_152 &= ~ V_523 ;
} else if ( ( V_2 -> V_152 & V_703 ) &&
! ( V_2 -> V_152 & V_523 ) ) {
if ( V_2 -> V_399 == 1 ||
V_2 -> V_399 > V_1103 ) {
V_2 -> V_152 |= V_523 ;
V_1102 = true ;
} else if ( ( V_1101 ^ V_194 ) & V_1100 ) {
F_102 ( V_170 , L_136
L_137 ) ;
}
}
switch ( V_194 & V_1104 ) {
case V_1104 :
if ( ! ( V_2 -> V_136 & V_599 ) )
V_1102 = true ;
V_2 -> V_136 &= ~ V_384 ;
V_2 -> V_136 |= V_599 ;
break;
default:
if ( V_2 -> V_136 & V_599 )
V_1102 = true ;
V_2 -> V_136 &= ~ V_599 ;
if ( V_2 -> V_136 & V_429 )
break;
if ( F_247 ( V_54 ) > 1 )
break;
if ( V_2 -> V_434 [ V_435 ] . V_702 <= 1 )
break;
if ( ! V_2 -> V_419 )
break;
V_2 -> V_136 |= V_384 ;
break;
}
if ( V_194 & V_267 )
F_279 ( V_2 ) ;
else
F_278 ( V_2 ) ;
if ( V_1101 & V_290 )
V_1102 = true ;
V_54 -> V_194 = V_194 ;
if ( V_1102 )
F_544 ( V_54 ) ;
return 0 ;
}
static int F_547 ( struct V_1105 * V_1106 , struct V_1107 * V_1108 [] ,
struct V_53 * V_72 ,
const unsigned char * V_556 ,
T_2 V_136 )
{
struct V_1 * V_2 = F_86 ( V_72 ) ;
int V_17 ;
if ( ! ( V_2 -> V_136 & V_429 ) )
return F_548 ( V_1106 , V_1108 , V_72 , V_556 , V_136 ) ;
if ( V_1106 -> V_1109 && ! ( V_1106 -> V_1109 & V_1110 ) ) {
F_48 ( L_138 ,
V_1111 ) ;
return - V_756 ;
}
if ( F_549 ( V_556 ) || F_550 ( V_556 ) ) {
T_1 V_1112 = V_551 ;
if ( F_282 ( V_72 ) < V_1112 )
V_17 = F_551 ( V_72 , V_556 ) ;
else
V_17 = - V_552 ;
} else if ( F_552 ( V_556 ) ) {
V_17 = F_553 ( V_72 , V_556 ) ;
} else {
V_17 = - V_756 ;
}
if ( V_17 == - V_1113 && ! ( V_136 & V_1114 ) )
V_17 = 0 ;
return V_17 ;
}
static int F_554 ( struct V_53 * V_72 ,
struct V_1115 * V_1116 )
{
struct V_1 * V_2 = F_86 ( V_72 ) ;
struct V_1107 * V_1117 , * V_1118 ;
int V_1119 ;
if ( ! ( V_2 -> V_136 & V_429 ) )
return - V_1120 ;
V_1118 = F_555 ( V_1116 , sizeof( struct V_1121 ) , V_1122 ) ;
F_556 (attr, br_spec, rem) {
T_16 V_1123 ;
T_1 V_3 = 0 ;
if ( F_557 ( V_1117 ) != V_1124 )
continue;
V_1123 = F_558 ( V_1117 ) ;
if ( V_1123 == V_1125 ) {
V_3 = 0 ;
V_2 -> V_152 &= ~ V_497 ;
} else if ( V_1123 == V_1126 ) {
V_3 = V_499 ;
V_2 -> V_152 |= V_497 ;
} else
return - V_756 ;
F_68 ( & V_2 -> V_14 , V_498 , V_3 ) ;
F_102 ( V_154 , L_139 ,
V_1123 == V_1125 ? L_140 : L_141 ) ;
}
return 0 ;
}
static int F_559 ( struct V_193 * V_88 , T_1 V_1127 , T_1 V_1128 ,
struct V_53 * V_72 ,
T_1 V_1129 )
{
struct V_1 * V_2 = F_86 ( V_72 ) ;
T_2 V_1123 ;
if ( ! ( V_2 -> V_136 & V_429 ) )
return 0 ;
if ( V_2 -> V_152 & V_497 )
V_1123 = V_1126 ;
else
V_1123 = V_1125 ;
return F_560 ( V_88 , V_1127 , V_1128 , V_72 , V_1123 ) ;
}
static void * F_561 ( struct V_53 * V_9 , struct V_53 * V_617 )
{
struct V_613 * V_1036 = NULL ;
struct V_1 * V_2 = F_86 ( V_9 ) ;
unsigned int V_702 ;
int V_482 , V_17 ;
#ifdef F_562
if ( V_617 -> V_92 != V_617 -> V_76 ) {
F_563 ( V_9 , L_142 ,
V_617 -> V_52 ) ;
return F_564 ( - V_756 ) ;
}
#endif
if ( V_617 -> V_76 > V_761 ||
V_617 -> V_76 == V_1130 ) {
F_563 ( V_9 ,
L_143 ,
V_9 -> V_52 ) ;
return F_564 ( - V_756 ) ;
}
if ( ( ( V_2 -> V_136 & V_137 ) &&
V_2 -> V_624 > V_1097 - 1 ) ||
( V_2 -> V_624 > V_1131 ) )
return F_564 ( - V_758 ) ;
V_1036 = F_565 ( 1 , sizeof( struct V_613 ) , V_751 ) ;
if ( ! V_1036 )
return F_564 ( - V_552 ) ;
V_482 = F_540 ( & V_2 -> V_623 , 32 ) ;
V_2 -> V_624 ++ ;
F_243 ( V_482 , & V_2 -> V_623 ) ;
V_702 = F_566 ( & V_2 -> V_623 , 32 ) ;
V_2 -> V_136 |= V_575 | V_429 ;
V_2 -> V_434 [ V_501 ] . V_702 = V_702 + 1 ;
V_2 -> V_434 [ V_435 ] . V_702 = V_617 -> V_76 ;
V_17 = F_539 ( V_9 , F_247 ( V_9 ) ) ;
if ( V_17 )
goto V_1132;
V_1036 -> V_482 = V_482 ;
V_1036 -> V_145 = V_2 ;
V_17 = F_327 ( V_617 , V_1036 ) ;
if ( V_17 )
goto V_1132;
F_567 ( V_617 ) ;
return V_1036 ;
V_1132:
F_563 ( V_9 ,
L_144 , V_617 -> V_52 ) ;
F_31 ( V_482 , & V_2 -> V_623 ) ;
V_2 -> V_624 -- ;
F_233 ( V_1036 ) ;
return F_564 ( V_17 ) ;
}
static void F_568 ( struct V_53 * V_9 , void * V_1133 )
{
struct V_613 * V_1036 = V_1133 ;
struct V_1 * V_2 = V_1036 -> V_145 ;
unsigned int V_702 ;
F_31 ( V_1036 -> V_482 , & V_2 -> V_623 ) ;
V_2 -> V_624 -- ;
V_702 = F_566 ( & V_2 -> V_623 , 32 ) ;
V_2 -> V_434 [ V_501 ] . V_702 = V_702 + 1 ;
F_325 ( V_1036 -> V_54 , V_1036 ) ;
F_539 ( V_9 , F_247 ( V_9 ) ) ;
F_328 ( V_9 , L_92 ,
V_1036 -> V_482 , V_2 -> V_624 ,
V_1036 -> V_616 ,
V_1036 -> V_616 + V_2 -> V_615 ,
V_2 -> V_623 ) ;
F_233 ( V_1036 ) ;
}
static inline int F_569 ( struct V_1 * V_2 )
{
struct V_627 * V_404 ;
int V_1134 = 0 ;
if ( F_8 ( & V_2 -> V_14 ) ) {
V_1134 = 4 ;
} else {
F_570 (entry, &adapter->pdev->bus_list) {
struct V_5 * V_9 =
F_571 ( V_404 , struct V_5 , V_1135 ) ;
if ( ! V_9 -> V_1136 )
V_1134 ++ ;
}
}
return V_1134 ;
}
int F_572 ( struct V_1 * V_2 , T_2 V_21 ,
T_2 V_1137 )
{
struct V_15 * V_14 = & V_2 -> V_14 ;
T_2 V_1138 = V_2 -> V_1139 & V_1140 ;
int V_1141 = 0 ;
switch ( V_21 ) {
case V_1142 :
switch ( V_1137 ) {
case V_1143 :
case V_1144 :
if ( V_14 -> V_10 . V_1145 != 0 )
break;
case V_1146 :
case V_1147 :
case V_1148 :
case V_1149 :
case V_1150 :
V_1141 = 1 ;
break;
}
break;
case V_1151 :
switch ( V_1137 ) {
case V_1152 :
V_1141 = 1 ;
break;
}
break;
case V_1153 :
if ( V_1137 != V_1154 )
V_1141 = 1 ;
break;
case V_1155 :
V_1141 = 1 ;
break;
case V_1156 :
case V_1157 :
if ( ( V_1138 == V_1158 ) ||
( ( V_1138 == V_1159 ) &&
( V_14 -> V_10 . V_1145 == 0 ) ) ) {
V_1141 = 1 ;
}
break;
}
return V_1141 ;
}
static int F_573 ( struct V_5 * V_9 , const struct V_1160 * V_1161 )
{
struct V_53 * V_54 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_14 ;
const struct V_1162 * V_1163 = V_1164 [ V_1161 -> V_1165 ] ;
static int V_1166 ;
int V_47 , V_17 , V_1167 , V_24 ;
unsigned int V_436 = V_1168 ;
T_6 V_1169 [ V_1170 ] ;
#ifdef F_146
T_2 V_1171 ;
#endif
T_1 V_1172 ;
if ( V_9 -> V_1136 ) {
F_574 ( 1 , V_1173 L_145 ,
F_575 ( V_9 ) , V_9 -> V_694 , V_9 -> V_188 ) ;
return - V_756 ;
}
V_17 = F_404 ( V_9 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_576 ( & V_9 -> V_72 , F_241 ( 64 ) ) ) {
V_1167 = 1 ;
} else {
V_17 = F_576 ( & V_9 -> V_72 , F_241 ( 32 ) ) ;
if ( V_17 ) {
F_383 ( & V_9 -> V_72 ,
L_146 ) ;
goto V_1174;
}
V_1167 = 0 ;
}
V_17 = F_577 ( V_9 , F_578 ( V_9 ,
V_1175 ) , V_1111 ) ;
if ( V_17 ) {
F_383 ( & V_9 -> V_72 ,
L_147 , V_17 ) ;
goto V_1176;
}
F_579 ( V_9 ) ;
F_405 ( V_9 ) ;
F_403 ( V_9 ) ;
if ( V_1163 -> V_107 == V_108 ) {
#ifdef F_337
V_436 = 4 * V_722 ;
#else
V_436 = V_701 ;
#endif
}
V_54 = F_580 ( sizeof( struct V_1 ) , V_436 ) ;
if ( ! V_54 ) {
V_17 = - V_552 ;
goto V_1177;
}
F_581 ( V_54 , & V_9 -> V_72 ) ;
V_2 = F_86 ( V_54 ) ;
F_582 ( V_9 , V_2 ) ;
V_2 -> V_54 = V_54 ;
V_2 -> V_9 = V_9 ;
V_14 = & V_2 -> V_14 ;
V_14 -> V_38 = V_2 ;
V_2 -> V_1178 = F_583 ( V_1179 , V_1180 ) ;
V_14 -> V_39 = F_584 ( F_585 ( V_9 , 0 ) ,
F_586 ( V_9 , 0 ) ) ;
V_2 -> V_417 = V_14 -> V_39 ;
if ( ! V_14 -> V_39 ) {
V_17 = - V_748 ;
goto V_1181;
}
V_54 -> V_1182 = & V_1183 ;
F_587 ( V_54 ) ;
V_54 -> V_1184 = 5 * V_959 ;
strncpy ( V_54 -> V_52 , F_575 ( V_9 ) , sizeof( V_54 -> V_52 ) - 1 ) ;
V_2 -> V_1185 = V_1166 ;
memcpy ( & V_14 -> V_107 . V_357 , V_1163 -> V_1186 , sizeof( V_14 -> V_107 . V_357 ) ) ;
V_14 -> V_107 . type = V_1163 -> V_107 ;
memcpy ( & V_14 -> V_1187 . V_357 , V_1163 -> V_1188 , sizeof( V_14 -> V_1187 . V_357 ) ) ;
V_1172 = F_34 ( V_14 , V_1189 ) ;
if ( F_23 ( V_14 -> V_39 ) ) {
V_17 = - V_748 ;
goto V_1181;
}
if ( ! ( V_1172 & ( 1 << 8 ) ) )
V_14 -> V_1187 . V_357 . V_227 = & V_1190 ;
memcpy ( & V_14 -> V_360 . V_357 , V_1163 -> V_1191 , sizeof( V_14 -> V_360 . V_357 ) ) ;
V_14 -> V_360 . V_945 = V_1192 ;
V_14 -> V_360 . V_1074 . V_1071 = V_1193 ;
V_14 -> V_360 . V_1074 . V_1194 = 0 ;
V_14 -> V_360 . V_1074 . V_1195 = V_1196 | V_1197 ;
V_14 -> V_360 . V_1074 . V_72 = V_54 ;
V_14 -> V_360 . V_1074 . V_1198 = F_517 ;
V_14 -> V_360 . V_1074 . V_1199 = F_518 ;
V_1163 -> V_1200 ( V_14 ) ;
V_17 = F_369 ( V_2 ) ;
if ( V_17 )
goto V_1201;
switch ( V_2 -> V_14 . V_107 . type ) {
case V_110 :
case V_111 :
F_68 ( & V_2 -> V_14 , V_764 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_136 & V_363 ) {
T_1 V_670 = F_34 ( V_14 , V_671 ) ;
if ( V_670 & V_672 )
F_206 ( V_170 , L_73 ) ;
}
if ( V_1202 )
V_14 -> V_1202 = V_1202 ;
V_14 -> V_360 . V_1203 = true ;
V_17 = V_14 -> V_107 . V_357 . V_1204 ( V_14 ) ;
V_14 -> V_360 . V_1203 = false ;
if ( V_17 == V_678 &&
V_14 -> V_107 . type == V_108 ) {
V_17 = 0 ;
} else if ( V_17 == V_679 ) {
F_18 ( L_148 ) ;
F_18 ( L_149 ) ;
goto V_1201;
} else if ( V_17 ) {
F_18 ( L_150 , V_17 ) ;
goto V_1201;
}
#ifdef F_373
if ( V_2 -> V_14 . V_107 . type == V_108 )
goto V_1205;
F_588 ( V_14 ) ;
memcpy ( & V_14 -> V_1206 . V_357 , V_1163 -> V_1207 , sizeof( V_14 -> V_1206 . V_357 ) ) ;
F_589 ( V_9 , V_740 ) ;
F_590 ( V_2 ) ;
V_1205:
#endif
V_54 -> V_194 = V_1208 |
V_1209 |
V_1210 |
V_1211 |
V_267 |
V_1212 |
V_1213 |
V_1214 |
V_195 |
V_207 ;
V_54 -> V_1215 = V_54 -> V_194 | V_1216 ;
switch ( V_2 -> V_14 . V_107 . type ) {
case V_110 :
case V_111 :
V_54 -> V_194 |= V_1217 ;
V_54 -> V_1215 |= V_1217 |
V_1104 ;
break;
default:
break;
}
V_54 -> V_1215 |= V_290 ;
V_54 -> V_1218 |= V_1213 ;
V_54 -> V_1218 |= V_1214 ;
V_54 -> V_1218 |= V_1209 ;
V_54 -> V_1218 |= V_1210 ;
V_54 -> V_1218 |= V_1208 ;
V_54 -> V_1219 |= V_1220 ;
V_54 -> V_1219 |= V_1221 ;
#ifdef F_337
V_54 -> V_1222 = & V_1222 ;
#endif
#ifdef F_146
if ( V_2 -> V_136 & V_709 ) {
unsigned int V_1223 ;
if ( V_14 -> V_107 . V_357 . V_1224 ) {
V_14 -> V_107 . V_357 . V_1224 ( V_14 , & V_1171 ) ;
if ( V_1171 & V_1225 )
V_2 -> V_136 &= ~ V_709 ;
}
V_1223 = F_329 ( int , V_1226 , F_370 () ) ;
V_2 -> V_434 [ V_1042 ] . V_702 = V_1223 ;
V_54 -> V_194 |= V_1061 |
V_1062 ;
V_54 -> V_1218 |= V_1061 |
V_1062 |
V_580 ;
}
#endif
if ( V_1167 ) {
V_54 -> V_194 |= V_1227 ;
V_54 -> V_1218 |= V_1227 ;
}
if ( V_2 -> V_152 & V_703 )
V_54 -> V_1215 |= V_1100 ;
if ( V_2 -> V_152 & V_523 )
V_54 -> V_194 |= V_1100 ;
if ( V_14 -> V_1187 . V_357 . V_1228 ( V_14 , NULL ) < 0 ) {
F_18 ( L_151 ) ;
V_17 = - V_748 ;
goto V_1201;
}
memcpy ( V_54 -> V_626 , V_14 -> V_107 . V_1229 , V_54 -> V_1070 ) ;
if ( ! F_332 ( V_54 -> V_626 ) ) {
F_18 ( L_152 ) ;
V_17 = - V_748 ;
goto V_1201;
}
F_591 ( & V_2 -> V_673 , & F_461 ,
( unsigned long ) V_2 ) ;
if ( F_23 ( V_14 -> V_39 ) ) {
V_17 = - V_748 ;
goto V_1201;
}
F_592 ( & V_2 -> V_37 , F_463 ) ;
F_243 ( V_40 , & V_2 -> V_34 ) ;
F_31 ( V_36 , & V_2 -> V_34 ) ;
V_17 = F_408 ( V_2 ) ;
if ( V_17 )
goto V_1201;
V_2 -> V_768 = 0 ;
V_14 -> V_1187 . V_357 . V_227 ( V_14 , 0x2c , & V_2 -> V_1139 ) ;
V_14 -> V_1230 = F_572 ( V_2 , V_9 -> V_188 ,
V_9 -> V_700 ) ;
if ( V_14 -> V_1230 )
V_2 -> V_768 = V_1231 ;
F_593 ( & V_2 -> V_9 -> V_72 , V_2 -> V_768 ) ;
V_14 -> V_1187 . V_357 . V_227 ( V_14 , 0x2e , & V_2 -> V_1232 ) ;
V_14 -> V_1187 . V_357 . V_227 ( V_14 , 0x2d , & V_2 -> V_1233 ) ;
V_14 -> V_107 . V_357 . V_1234 ( V_14 ) ;
if ( F_8 ( V_14 ) )
F_5 ( V_2 ) ;
switch ( V_14 -> V_107 . type ) {
case V_108 :
V_24 = F_594 ( F_569 ( V_2 ) * 10 , 16 ) ;
break;
default:
V_24 = F_569 ( V_2 ) * 10 ;
break;
}
F_9 ( V_2 , V_24 ) ;
V_17 = F_595 ( V_14 , V_1169 , V_1170 ) ;
if ( V_17 )
strncpy ( V_1169 , L_7 , V_1170 ) ;
if ( F_341 ( V_14 ) && V_14 -> V_360 . V_945 != V_1235 )
F_12 ( L_153 ,
V_14 -> V_107 . type , V_14 -> V_360 . type , V_14 -> V_360 . V_945 ,
V_1169 ) ;
else
F_12 ( L_154 ,
V_14 -> V_107 . type , V_14 -> V_360 . type , V_1169 ) ;
F_12 ( L_155 , V_54 -> V_626 ) ;
V_17 = V_14 -> V_107 . V_357 . V_1236 ( V_14 ) ;
if ( V_17 == V_681 ) {
F_11 ( L_95
L_156
L_157
L_158
L_99
L_100 ) ;
}
strcpy ( V_54 -> V_52 , L_159 ) ;
V_17 = F_596 ( V_54 ) ;
if ( V_17 )
goto V_1237;
if ( V_14 -> V_107 . V_357 . V_689 )
V_14 -> V_107 . V_357 . V_689 ( V_14 ) ;
F_362 ( V_54 ) ;
#ifdef F_224
if ( F_123 ( & V_9 -> V_72 ) == 0 ) {
V_2 -> V_136 |= V_185 ;
F_120 ( V_2 ) ;
}
#endif
if ( V_2 -> V_136 & V_429 ) {
F_102 ( V_170 , L_160 , V_2 -> V_324 ) ;
for ( V_47 = 0 ; V_47 < V_2 -> V_324 ; V_47 ++ )
F_597 ( V_9 , ( V_47 | 0x10000000 ) ) ;
}
if ( V_14 -> V_107 . V_357 . V_1238 )
V_14 -> V_107 . V_357 . V_1238 ( V_14 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_524 ( V_54 ) ;
F_12 ( L_161 , V_1239 ) ;
V_1166 ++ ;
#ifdef F_598
if ( F_599 ( V_2 ) )
F_100 ( V_170 , L_162 ) ;
#endif
F_600 ( V_2 ) ;
if ( F_601 ( V_14 ) && V_14 -> V_107 . V_357 . V_653 )
V_14 -> V_107 . V_357 . V_653 ( V_14 ,
V_913 | V_936 ,
true ) ;
return 0 ;
V_1237:
F_67 ( V_2 ) ;
F_414 ( V_2 ) ;
V_1201:
F_602 ( V_2 ) ;
V_2 -> V_152 &= ~ V_647 ;
F_603 ( V_2 -> V_417 ) ;
V_1181:
F_604 ( V_54 ) ;
V_1177:
F_605 ( V_9 ,
F_578 ( V_9 , V_1175 ) ) ;
V_1176:
V_1174:
if ( ! F_15 ( V_763 , & V_2 -> V_34 ) )
F_415 ( V_9 ) ;
return V_17 ;
}
static void F_606 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_400 ( V_9 ) ;
struct V_53 * V_54 = V_2 -> V_54 ;
F_607 ( V_2 ) ;
F_243 ( V_35 , & V_2 -> V_34 ) ;
F_608 ( & V_2 -> V_37 ) ;
#ifdef F_224
if ( V_2 -> V_136 & V_185 ) {
V_2 -> V_136 &= ~ V_185 ;
F_124 ( & V_9 -> V_72 ) ;
F_68 ( & V_2 -> V_14 , V_186 , 1 ) ;
}
#endif
#ifdef F_598
F_609 ( V_2 ) ;
#endif
F_526 ( V_54 ) ;
if ( V_54 -> V_946 == V_947 )
F_457 ( V_54 ) ;
#ifdef F_373
if ( V_739 )
F_602 ( V_2 ) ;
#endif
F_414 ( V_2 ) ;
F_67 ( V_2 ) ;
#ifdef F_610
F_233 ( V_2 -> V_135 ) ;
F_233 ( V_2 -> V_585 ) ;
#endif
F_603 ( V_2 -> V_417 ) ;
F_605 ( V_9 , F_578 ( V_9 ,
V_1175 ) ) ;
F_12 ( L_163 ) ;
F_604 ( V_54 ) ;
F_611 ( V_9 ) ;
if ( ! F_15 ( V_763 , & V_2 -> V_34 ) )
F_415 ( V_9 ) ;
}
static T_17 F_612 ( struct V_5 * V_9 ,
T_18 V_34 )
{
struct V_1 * V_2 = F_400 ( V_9 ) ;
struct V_53 * V_54 = V_2 -> V_54 ;
#ifdef F_373
struct V_15 * V_14 = & V_2 -> V_14 ;
struct V_5 * V_1240 , * V_1241 ;
T_1 V_1242 , V_1243 , V_1244 , V_1245 ;
int V_948 , V_1246 ;
T_2 V_1247 , V_1248 ;
if ( V_2 -> V_14 . V_107 . type == V_108 ||
V_2 -> V_324 == 0 )
goto V_1249;
V_1240 = V_9 -> V_10 -> V_12 ;
while ( V_1240 && ( F_613 ( V_1240 ) != V_1250 ) )
V_1240 = V_1240 -> V_10 -> V_12 ;
if ( ! V_1240 )
goto V_1249;
V_1246 = F_614 ( V_1240 , V_1251 ) ;
if ( ! V_1246 )
goto V_1249;
V_1242 = F_24 ( V_14 , V_1246 + V_1252 ) ;
V_1243 = F_24 ( V_14 , V_1246 + V_1252 + 4 ) ;
V_1244 = F_24 ( V_14 , V_1246 + V_1252 + 8 ) ;
V_1245 = F_24 ( V_14 , V_1246 + V_1252 + 12 ) ;
if ( F_23 ( V_14 -> V_39 ) )
goto V_1249;
V_1247 = V_1243 >> 16 ;
if ( ! ( V_1247 & 0x0080 ) )
goto V_1249;
V_1248 = V_1247 & 0x01 ;
if ( ( V_1248 & 1 ) == ( V_9 -> V_1253 & 1 ) ) {
unsigned int V_21 ;
V_948 = ( V_1247 & 0x7F ) >> 1 ;
F_18 ( L_164 , V_948 ) ;
F_18 ( L_165
L_166 ,
V_1242 , V_1243 , V_1244 , V_1245 ) ;
switch ( V_2 -> V_14 . V_107 . type ) {
case V_110 :
V_21 = V_1254 ;
break;
case V_111 :
V_21 = V_1255 ;
break;
default:
V_21 = 0 ;
break;
}
V_1241 = F_615 ( V_1256 , V_21 , NULL ) ;
while ( V_1241 ) {
if ( V_1241 -> V_1253 == ( V_1247 & 0xFF ) )
break;
V_1241 = F_615 ( V_1256 ,
V_21 , V_1241 ) ;
}
if ( V_1241 ) {
F_18 ( L_167 , V_948 ) ;
F_616 ( V_1241 , 0xA8 , 0x00008000 ) ;
F_617 ( V_1241 ) ;
}
F_618 ( V_9 ) ;
}
V_2 -> V_1257 ++ ;
return V_1258 ;
V_1249:
#endif
if ( ! F_14 ( V_40 , & V_2 -> V_34 ) )
return V_1259 ;
F_407 () ;
F_413 ( V_54 ) ;
if ( V_34 == V_1260 ) {
F_409 () ;
return V_1259 ;
}
if ( F_54 ( V_54 ) )
F_351 ( V_2 ) ;
if ( ! F_15 ( V_763 , & V_2 -> V_34 ) )
F_415 ( V_9 ) ;
F_409 () ;
return V_1261 ;
}
static T_17 F_619 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_400 ( V_9 ) ;
T_17 V_1262 ;
int V_17 ;
if ( F_404 ( V_9 ) ) {
F_100 ( V_170 , L_168 ) ;
V_1262 = V_1259 ;
} else {
F_30 () ;
F_31 ( V_763 , & V_2 -> V_34 ) ;
V_2 -> V_14 . V_39 = V_2 -> V_417 ;
F_405 ( V_9 ) ;
F_402 ( V_9 ) ;
F_403 ( V_9 ) ;
F_406 ( V_9 , false ) ;
F_354 ( V_2 ) ;
F_68 ( & V_2 -> V_14 , V_764 , ~ 0 ) ;
V_1262 = V_1258 ;
}
V_17 = F_618 ( V_9 ) ;
if ( V_17 ) {
F_18 ( L_169
L_170 , V_17 ) ;
}
return V_1262 ;
}
static void F_620 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = F_400 ( V_9 ) ;
struct V_53 * V_54 = V_2 -> V_54 ;
#ifdef F_373
if ( V_2 -> V_1257 ) {
F_102 ( V_154 , L_171 ) ;
V_2 -> V_1257 -- ;
return;
}
#endif
if ( F_54 ( V_54 ) )
F_353 ( V_2 ) ;
F_410 ( V_54 ) ;
}
static int T_19 F_621 ( void )
{
int V_151 ;
F_48 ( L_172 , V_1263 , V_1264 ) ;
F_48 ( L_161 , V_1265 ) ;
F_622 () ;
V_151 = F_623 ( & V_1266 ) ;
if ( V_151 ) {
F_624 () ;
return V_151 ;
}
#ifdef F_224
F_625 ( & V_1267 ) ;
#endif
return 0 ;
}
static void T_20 F_626 ( void )
{
#ifdef F_224
F_627 ( & V_1267 ) ;
#endif
F_628 ( & V_1266 ) ;
F_624 () ;
F_629 () ;
}
static int F_630 ( struct V_1268 * V_1269 , unsigned long V_189 ,
void * V_1066 )
{
int V_1270 ;
V_1270 = F_631 ( & V_1266 . V_1271 , NULL , & V_189 ,
F_121 ) ;
return V_1270 ? V_1272 : V_1273 ;
}
