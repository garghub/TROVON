static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 * V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_9 = V_2 -> V_10 -> V_11 -> V_12 ;
if ( ! V_9 )
return - 1 ;
V_7 = V_9 -> V_13 ;
if ( ! V_7 )
return - 1 ;
V_5 = F_2 ( V_7 , V_14 ) ;
if ( ! V_5 )
return - 1 ;
F_3 ( V_7 , V_5 + V_3 , V_4 ) ;
return 0 ;
}
static T_3 F_4 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_2 V_17 = 0 ;
int V_18 ;
V_16 -> V_11 . type = V_19 ;
V_18 = F_1 ( V_2 , 18 , & V_17 ) ;
if ( V_18 )
return V_18 ;
V_16 -> V_11 . V_20 = F_5 ( V_17 ) ;
V_16 -> V_11 . V_21 = F_6 ( V_17 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( ! F_8 ( V_22 , & V_2 -> V_23 ) &&
! F_9 ( V_24 , & V_2 -> V_23 ) )
F_10 ( & V_2 -> V_25 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( ! F_8 ( V_24 , & V_2 -> V_23 ) ) ;
F_13 () ;
F_14 ( V_24 , & V_2 -> V_23 ) ;
}
static void F_15 ( struct V_15 * V_16 , struct V_26 * V_27 )
{
int V_28 = 0 , V_29 = 0 ;
char V_30 [ 16 ] ;
T_1 V_31 [ 64 ] ;
switch ( V_27 -> V_32 ) {
case F_16 ( 0 ) :
for ( V_28 = 0 ; V_28 < 64 ; V_28 ++ )
V_31 [ V_28 ] = F_17 ( V_16 , F_16 ( V_28 ) ) ;
break;
case F_18 ( 0 ) :
for ( V_28 = 0 ; V_28 < 64 ; V_28 ++ )
V_31 [ V_28 ] = F_17 ( V_16 , F_18 ( V_28 ) ) ;
break;
case F_19 ( 0 ) :
for ( V_28 = 0 ; V_28 < 64 ; V_28 ++ )
V_31 [ V_28 ] = F_17 ( V_16 , F_19 ( V_28 ) ) ;
break;
case F_20 ( 0 ) :
for ( V_28 = 0 ; V_28 < 64 ; V_28 ++ )
V_31 [ V_28 ] = F_17 ( V_16 , F_20 ( V_28 ) ) ;
break;
case F_21 ( 0 ) :
for ( V_28 = 0 ; V_28 < 64 ; V_28 ++ )
V_31 [ V_28 ] = F_17 ( V_16 , F_21 ( V_28 ) ) ;
break;
case F_22 ( 0 ) :
for ( V_28 = 0 ; V_28 < 64 ; V_28 ++ )
V_31 [ V_28 ] = F_17 ( V_16 , F_22 ( V_28 ) ) ;
break;
case F_23 ( 0 ) :
for ( V_28 = 0 ; V_28 < 64 ; V_28 ++ )
V_31 [ V_28 ] = F_17 ( V_16 , F_23 ( V_28 ) ) ;
break;
case F_24 ( 0 ) :
for ( V_28 = 0 ; V_28 < 64 ; V_28 ++ )
V_31 [ V_28 ] = F_17 ( V_16 , F_24 ( V_28 ) ) ;
break;
case F_25 ( 0 ) :
for ( V_28 = 0 ; V_28 < 64 ; V_28 ++ )
V_31 [ V_28 ] = F_17 ( V_16 , F_25 ( V_28 ) ) ;
break;
case F_26 ( 0 ) :
for ( V_28 = 0 ; V_28 < 64 ; V_28 ++ )
V_31 [ V_28 ] = F_17 ( V_16 , F_26 ( V_28 ) ) ;
break;
case F_27 ( 0 ) :
for ( V_28 = 0 ; V_28 < 64 ; V_28 ++ )
V_31 [ V_28 ] = F_17 ( V_16 , F_27 ( V_28 ) ) ;
break;
case F_28 ( 0 ) :
for ( V_28 = 0 ; V_28 < 64 ; V_28 ++ )
V_31 [ V_28 ] = F_17 ( V_16 , F_28 ( V_28 ) ) ;
break;
case F_29 ( 0 ) :
for ( V_28 = 0 ; V_28 < 64 ; V_28 ++ )
V_31 [ V_28 ] = F_17 ( V_16 , F_29 ( V_28 ) ) ;
break;
case F_30 ( 0 ) :
for ( V_28 = 0 ; V_28 < 64 ; V_28 ++ )
V_31 [ V_28 ] = F_17 ( V_16 , F_30 ( V_28 ) ) ;
break;
default:
F_31 ( L_1 , V_27 -> V_33 ,
F_17 ( V_16 , V_27 -> V_32 ) ) ;
return;
}
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ ) {
snprintf ( V_30 , 16 , L_2 , V_27 -> V_33 , V_28 * 8 , V_28 * 8 + 7 ) ;
F_32 ( L_3 , V_30 ) ;
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ )
F_33 ( L_4 , V_31 [ V_28 * 8 + V_29 ] ) ;
F_33 ( L_5 ) ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_26 * V_27 ;
int V_36 = 0 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
union V_41 * V_42 ;
struct V_43 { T_4 V_44 ; T_4 V_45 ; } * V_46 ;
struct V_37 * V_47 ;
union V_48 * V_49 ;
struct V_50 * V_51 ;
T_1 V_52 ;
int V_28 = 0 ;
if ( ! F_35 ( V_2 ) )
return;
if ( V_35 ) {
F_36 ( & V_2 -> V_10 -> V_53 , L_6 ) ;
F_31 ( L_7
L_8 ) ;
F_31 ( L_9 ,
V_35 -> V_33 ,
V_35 -> V_23 ,
V_35 -> V_54 ,
V_35 -> V_55 ) ;
}
F_36 ( & V_2 -> V_10 -> V_53 , L_10 ) ;
F_31 ( L_11 ) ;
for ( V_27 = (struct V_26 * ) V_56 ;
V_27 -> V_33 ; V_27 ++ ) {
F_15 ( V_16 , V_27 ) ;
}
if ( ! V_35 || ! F_37 ( V_35 ) )
goto exit;
F_36 ( & V_2 -> V_10 -> V_53 , L_12 ) ;
F_31 ( L_13 ,
L_14 ,
L_15 , L_16 , L_17 ) ;
for ( V_36 = 0 ; V_36 < V_2 -> V_57 ; V_36 ++ ) {
V_38 = V_2 -> V_38 [ V_36 ] ;
V_40 = & V_38 -> V_58 [ V_38 -> V_59 ] ;
F_31 ( L_18 ,
V_36 , V_38 -> V_60 , V_38 -> V_59 ,
( T_4 ) F_38 ( V_40 , V_61 ) ,
F_39 ( V_40 , V_62 ) ,
V_40 -> V_63 ,
( T_4 ) V_40 -> V_64 ) ;
}
if ( ! F_40 ( V_2 ) )
goto V_65;
F_36 ( & V_2 -> V_10 -> V_53 , L_19 ) ;
for ( V_36 = 0 ; V_36 < V_2 -> V_57 ; V_36 ++ ) {
V_38 = V_2 -> V_38 [ V_36 ] ;
F_31 ( L_20 ) ;
F_31 ( L_21 , V_38 -> V_66 ) ;
F_31 ( L_20 ) ;
F_31 ( L_22 ,
L_23 ,
L_24 ,
L_15 , L_16 , L_17 , L_25 ) ;
for ( V_28 = 0 ; V_38 -> V_67 && ( V_28 < V_38 -> V_68 ) ; V_28 ++ ) {
V_42 = F_41 ( V_38 , V_28 ) ;
V_40 = & V_38 -> V_58 [ V_28 ] ;
V_46 = (struct V_43 * ) V_42 ;
if ( F_39 ( V_40 , V_62 ) > 0 ) {
F_31 ( L_26 ,
V_28 ,
F_42 ( V_46 -> V_44 ) ,
F_42 ( V_46 -> V_45 ) ,
( T_4 ) F_38 ( V_40 , V_61 ) ,
F_39 ( V_40 , V_62 ) ,
V_40 -> V_63 ,
( T_4 ) V_40 -> V_64 ,
V_40 -> V_69 ) ;
if ( V_28 == V_38 -> V_60 &&
V_28 == V_38 -> V_59 )
F_33 ( L_27 ) ;
else if ( V_28 == V_38 -> V_60 )
F_33 ( L_28 ) ;
else if ( V_28 == V_38 -> V_59 )
F_33 ( L_29 ) ;
else
F_33 ( L_5 ) ;
if ( F_43 ( V_2 ) &&
V_40 -> V_69 )
F_44 ( V_70 , L_30 ,
V_71 , 16 , 1 ,
V_40 -> V_69 -> V_72 ,
F_39 ( V_40 , V_62 ) ,
true ) ;
}
}
}
V_65:
F_36 ( & V_2 -> V_10 -> V_53 , L_31 ) ;
F_31 ( L_32 ) ;
for ( V_36 = 0 ; V_36 < V_2 -> V_73 ; V_36 ++ ) {
V_47 = V_2 -> V_47 [ V_36 ] ;
F_31 ( L_33 ,
V_36 , V_47 -> V_60 , V_47 -> V_59 ) ;
}
if ( ! F_45 ( V_2 ) )
goto exit;
F_36 ( & V_2 -> V_10 -> V_53 , L_34 ) ;
for ( V_36 = 0 ; V_36 < V_2 -> V_73 ; V_36 ++ ) {
V_47 = V_2 -> V_47 [ V_36 ] ;
F_31 ( L_20 ) ;
F_31 ( L_35 , V_47 -> V_66 ) ;
F_31 ( L_20 ) ;
F_31 ( L_36 ,
L_37 ,
L_38 ,
L_39 ) ;
F_31 ( L_36 ,
L_40 ,
L_41 ,
L_42 ) ;
for ( V_28 = 0 ; V_28 < V_47 -> V_68 ; V_28 ++ ) {
V_51 = & V_47 -> V_51 [ V_28 ] ;
V_49 = F_46 ( V_47 , V_28 ) ;
V_46 = (struct V_43 * ) V_49 ;
V_52 = F_47 ( V_49 -> V_74 . V_75 . V_76 ) ;
if ( V_52 & V_77 ) {
F_31 ( L_43
L_44 , V_28 ,
F_42 ( V_46 -> V_44 ) ,
F_42 ( V_46 -> V_45 ) ,
V_51 -> V_69 ) ;
} else {
F_31 ( L_45
L_46 , V_28 ,
F_42 ( V_46 -> V_44 ) ,
F_42 ( V_46 -> V_45 ) ,
( T_4 ) V_51 -> V_61 ,
V_51 -> V_69 ) ;
if ( F_43 ( V_2 ) &&
V_51 -> V_61 ) {
F_44 ( V_70 , L_30 ,
V_71 , 16 , 1 ,
F_48 ( V_51 -> V_78 ) +
V_51 -> V_79 ,
F_49 ( V_47 ) , true ) ;
}
}
if ( V_28 == V_47 -> V_60 )
F_33 ( L_28 ) ;
else if ( V_28 == V_47 -> V_59 )
F_33 ( L_29 ) ;
else
F_33 ( L_5 ) ;
}
}
exit:
return;
}
static void F_50 ( struct V_1 * V_2 )
{
T_1 V_80 ;
V_80 = F_17 ( & V_2 -> V_16 , V_81 ) ;
F_51 ( & V_2 -> V_16 , V_81 ,
V_80 & ~ V_82 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
T_1 V_80 ;
V_80 = F_17 ( & V_2 -> V_16 , V_81 ) ;
F_51 ( & V_2 -> V_16 , V_81 ,
V_80 | V_82 ) ;
}
static void F_53 ( struct V_1 * V_2 , T_5 V_83 ,
T_6 V_84 , T_6 V_85 )
{
T_1 V_86 , V_87 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_85 |= V_90 ;
if ( V_83 == - 1 )
V_83 = 0 ;
V_87 = ( ( ( V_83 * 64 ) + V_84 ) >> 2 ) & 0x1F ;
V_86 = F_17 ( V_16 , F_54 ( V_87 ) ) ;
V_86 &= ~ ( 0xFF << ( 8 * ( V_84 & 0x3 ) ) ) ;
V_86 |= ( V_85 << ( 8 * ( V_84 & 0x3 ) ) ) ;
F_51 ( V_16 , F_54 ( V_87 ) , V_86 ) ;
break;
case V_91 :
case V_92 :
if ( V_83 == - 1 ) {
V_85 |= V_90 ;
V_87 = ( ( V_84 & 1 ) * 8 ) ;
V_86 = F_17 ( & V_2 -> V_16 , V_93 ) ;
V_86 &= ~ ( 0xFF << V_87 ) ;
V_86 |= ( V_85 << V_87 ) ;
F_51 ( & V_2 -> V_16 , V_93 , V_86 ) ;
break;
} else {
V_85 |= V_90 ;
V_87 = ( ( 16 * ( V_84 & 1 ) ) + ( 8 * V_83 ) ) ;
V_86 = F_17 ( V_16 , F_54 ( V_84 >> 1 ) ) ;
V_86 &= ~ ( 0xFF << V_87 ) ;
V_86 |= ( V_85 << V_87 ) ;
F_51 ( V_16 , F_54 ( V_84 >> 1 ) , V_86 ) ;
break;
}
default:
break;
}
}
static inline void F_55 ( struct V_1 * V_2 ,
T_4 V_94 )
{
T_1 V_95 ;
switch ( V_2 -> V_16 . V_88 . type ) {
case V_89 :
V_95 = ( V_96 & V_94 ) ;
F_51 ( & V_2 -> V_16 , V_97 , V_95 ) ;
break;
case V_91 :
case V_92 :
V_95 = ( V_94 & 0xFFFFFFFF ) ;
F_51 ( & V_2 -> V_16 , F_56 ( 0 ) , V_95 ) ;
V_95 = ( V_94 >> 32 ) ;
F_51 ( & V_2 -> V_16 , F_56 ( 1 ) , V_95 ) ;
break;
default:
break;
}
}
void F_57 ( struct V_37 * V_98 ,
struct V_39 * V_40 )
{
if ( V_40 -> V_69 ) {
F_58 ( V_40 -> V_69 ) ;
if ( F_39 ( V_40 , V_62 ) )
F_59 ( V_98 -> V_53 ,
F_38 ( V_40 , V_61 ) ,
F_39 ( V_40 , V_62 ) ,
V_99 ) ;
} else if ( F_39 ( V_40 , V_62 ) ) {
F_60 ( V_98 -> V_53 ,
F_38 ( V_40 , V_61 ) ,
F_39 ( V_40 , V_62 ) ,
V_99 ) ;
}
V_40 -> V_63 = NULL ;
V_40 -> V_69 = NULL ;
F_61 ( V_40 , V_62 , 0 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_100 * V_101 = & V_2 -> V_102 ;
int V_28 ;
T_1 V_72 ;
if ( ( V_16 -> V_103 . V_104 != V_105 ) &&
( V_16 -> V_103 . V_104 != V_106 ) )
return;
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_72 = F_17 ( V_16 , V_107 ) ;
break;
default:
V_72 = F_17 ( V_16 , V_108 ) ;
}
V_101 -> V_109 += V_72 ;
if ( ! V_72 )
return;
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ )
F_14 ( V_110 ,
& V_2 -> V_38 [ V_28 ] -> V_23 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_100 * V_101 = & V_2 -> V_102 ;
T_1 V_111 [ 8 ] = { 0 } ;
T_6 V_112 ;
int V_28 ;
bool V_113 = V_2 -> V_114 . V_115 ;
if ( V_2 -> V_116 )
V_113 |= ! ! ( V_2 -> V_116 -> V_113 ) ;
if ( ! ( V_2 -> V_117 & V_118 ) || ! V_113 ) {
F_62 ( V_2 ) ;
return;
}
for ( V_28 = 0 ; V_28 < V_119 ; V_28 ++ ) {
T_1 V_120 ;
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_120 = F_17 ( V_16 , F_64 ( V_28 ) ) ;
break;
default:
V_120 = F_17 ( V_16 , F_65 ( V_28 ) ) ;
}
V_101 -> V_120 [ V_28 ] += V_120 ;
V_112 = F_66 ( V_2 -> V_35 , V_28 ) ;
V_111 [ V_112 ] += V_120 ;
}
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ ) {
struct V_37 * V_38 = V_2 -> V_38 [ V_28 ] ;
V_112 = V_38 -> V_121 ;
if ( V_111 [ V_112 ] )
F_14 ( V_110 , & V_38 -> V_23 ) ;
}
}
static T_4 F_67 ( struct V_37 * V_98 )
{
return V_98 -> V_102 . V_122 ;
}
static T_4 F_68 ( struct V_37 * V_98 )
{
struct V_1 * V_2 = F_69 ( V_98 -> V_35 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_123 = F_17 ( V_16 , F_28 ( V_98 -> V_124 ) ) ;
T_1 V_125 = F_17 ( V_16 , F_29 ( V_98 -> V_124 ) ) ;
if ( V_123 != V_125 )
return ( V_123 < V_125 ) ?
V_125 - V_123 : ( V_125 + V_98 -> V_68 - V_123 ) ;
return 0 ;
}
static inline bool F_70 ( struct V_37 * V_38 )
{
T_1 V_126 = F_67 ( V_38 ) ;
T_1 V_127 = V_38 -> V_128 . V_127 ;
T_1 V_129 = F_68 ( V_38 ) ;
bool V_130 = false ;
F_71 ( V_38 ) ;
if ( ( V_127 == V_126 ) && V_129 ) {
V_130 = F_9 ( V_110 ,
& V_38 -> V_23 ) ;
} else {
V_38 -> V_128 . V_127 = V_126 ;
F_14 ( V_110 , & V_38 -> V_23 ) ;
}
return V_130 ;
}
static void F_72 ( struct V_1 * V_2 )
{
if ( ! F_8 ( V_22 , & V_2 -> V_23 ) ) {
V_2 -> V_131 |= V_132 ;
F_73 ( V_133 , L_47 ) ;
F_7 ( V_2 ) ;
}
}
static bool F_74 ( struct V_134 * V_135 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = V_135 -> V_2 ;
struct V_39 * V_40 ;
union V_41 * V_42 ;
unsigned int V_136 = 0 , V_137 = 0 ;
unsigned int V_138 = V_135 -> V_139 . V_140 ;
unsigned int V_28 = V_38 -> V_59 ;
if ( F_8 ( V_22 , & V_2 -> V_23 ) )
return true ;
V_40 = & V_38 -> V_58 [ V_28 ] ;
V_42 = F_41 ( V_38 , V_28 ) ;
V_28 -= V_38 -> V_68 ;
do {
union V_41 * V_141 = V_40 -> V_63 ;
if ( ! V_141 )
break;
F_75 () ;
if ( ! ( V_141 -> V_74 . V_142 & F_76 ( V_143 ) ) )
break;
V_40 -> V_63 = NULL ;
V_136 += V_40 -> V_144 ;
V_137 += V_40 -> V_145 ;
F_58 ( V_40 -> V_69 ) ;
F_59 ( V_38 -> V_53 ,
F_38 ( V_40 , V_61 ) ,
F_39 ( V_40 , V_62 ) ,
V_99 ) ;
V_40 -> V_69 = NULL ;
F_61 ( V_40 , V_62 , 0 ) ;
while ( V_42 != V_141 ) {
V_40 ++ ;
V_42 ++ ;
V_28 ++ ;
if ( F_77 ( ! V_28 ) ) {
V_28 -= V_38 -> V_68 ;
V_40 = V_38 -> V_58 ;
V_42 = F_41 ( V_38 , 0 ) ;
}
if ( F_39 ( V_40 , V_62 ) ) {
F_60 ( V_38 -> V_53 ,
F_38 ( V_40 , V_61 ) ,
F_39 ( V_40 , V_62 ) ,
V_99 ) ;
F_61 ( V_40 , V_62 , 0 ) ;
}
}
V_40 ++ ;
V_42 ++ ;
V_28 ++ ;
if ( F_77 ( ! V_28 ) ) {
V_28 -= V_38 -> V_68 ;
V_40 = V_38 -> V_58 ;
V_42 = F_41 ( V_38 , 0 ) ;
}
F_78 ( V_42 ) ;
V_138 -- ;
} while ( F_79 ( V_138 ) );
V_28 += V_38 -> V_68 ;
V_38 -> V_59 = V_28 ;
F_80 ( & V_38 -> V_146 ) ;
V_38 -> V_102 . V_147 += V_136 ;
V_38 -> V_102 . V_122 += V_137 ;
F_81 ( & V_38 -> V_146 ) ;
V_135 -> V_139 . V_136 += V_136 ;
V_135 -> V_139 . V_137 += V_137 ;
if ( F_82 ( V_38 ) && F_70 ( V_38 ) ) {
struct V_15 * V_16 = & V_2 -> V_16 ;
F_83 ( V_133 , L_48
L_49
L_50
L_51
L_52
L_53
L_54
L_55 ,
V_38 -> V_66 ,
F_17 ( V_16 , F_28 ( V_38 -> V_124 ) ) ,
F_17 ( V_16 , F_29 ( V_38 -> V_124 ) ) ,
V_38 -> V_60 , V_28 ,
V_38 -> V_58 [ V_28 ] . V_64 , V_148 ) ;
F_84 ( V_38 -> V_35 , V_38 -> V_66 ) ;
F_85 ( V_149 ,
L_56 ,
V_2 -> V_150 + 1 , V_38 -> V_66 ) ;
F_72 ( V_2 ) ;
return true ;
}
F_86 ( F_87 ( V_38 ) ,
V_137 , V_136 ) ;
#define F_88 (DESC_NEEDED * 2)
if ( F_77 ( V_137 && F_89 ( V_38 -> V_35 ) &&
( F_90 ( V_38 ) >= F_88 ) ) ) {
F_91 () ;
if ( F_92 ( V_38 -> V_35 ,
V_38 -> V_66 )
&& ! F_8 ( V_22 , & V_2 -> V_23 ) ) {
F_93 ( V_38 -> V_35 ,
V_38 -> V_66 ) ;
++ V_38 -> V_128 . V_151 ;
}
}
return ! ! V_138 ;
}
static void F_94 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
int V_152 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_153 = F_95 ( V_38 -> V_53 , V_152 ) ;
T_2 V_154 ;
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_154 = F_96 ( V_38 -> V_124 ) ;
break;
case V_91 :
case V_92 :
V_154 = F_97 ( V_38 -> V_124 ) ;
V_153 <<= V_155 ;
break;
default:
return;
}
V_153 |= V_156 |
V_157 |
V_158 ;
F_51 ( V_16 , V_154 , V_153 ) ;
}
static void F_98 ( struct V_1 * V_2 ,
struct V_37 * V_47 ,
int V_152 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_159 = F_95 ( V_47 -> V_53 , V_152 ) ;
T_6 V_124 = V_47 -> V_124 ;
switch ( V_16 -> V_88 . type ) {
case V_91 :
case V_92 :
V_159 <<= V_160 ;
break;
default:
break;
}
V_159 |= V_161 |
V_162 ;
F_51 ( V_16 , F_18 ( V_124 ) , V_159 ) ;
}
static void F_99 ( struct V_134 * V_135 )
{
struct V_1 * V_2 = V_135 -> V_2 ;
struct V_37 * V_98 ;
int V_152 = F_100 () ;
if ( V_135 -> V_152 == V_152 )
goto V_163;
F_101 (ring, q_vector->tx)
F_94 ( V_2 , V_98 , V_152 ) ;
F_101 (ring, q_vector->rx)
F_98 ( V_2 , V_98 , V_152 ) ;
V_135 -> V_152 = V_152 ;
V_163:
F_102 () ;
}
static void F_103 ( struct V_1 * V_2 )
{
int V_28 ;
if ( ! ( V_2 -> V_117 & V_164 ) )
return;
F_51 ( & V_2 -> V_16 , V_165 , 2 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_166 ; V_28 ++ ) {
V_2 -> V_135 [ V_28 ] -> V_152 = - 1 ;
F_99 ( V_2 -> V_135 [ V_28 ] ) ;
}
}
static int F_104 ( struct V_167 * V_53 , void * V_72 )
{
struct V_1 * V_2 = F_105 ( V_53 ) ;
unsigned long V_168 = * ( unsigned long * ) V_72 ;
if ( ! ( V_2 -> V_117 & V_169 ) )
return 0 ;
switch ( V_168 ) {
case V_170 :
if ( V_2 -> V_117 & V_164 )
break;
if ( F_106 ( V_53 ) == 0 ) {
V_2 -> V_117 |= V_164 ;
F_103 ( V_2 ) ;
break;
}
case V_171 :
if ( V_2 -> V_117 & V_164 ) {
F_107 ( V_53 ) ;
V_2 -> V_117 &= ~ V_164 ;
F_51 ( & V_2 -> V_16 , V_165 , 1 ) ;
}
break;
}
return 0 ;
}
static inline void F_108 ( struct V_37 * V_98 ,
union V_48 * V_49 ,
struct V_172 * V_69 )
{
if ( V_98 -> V_35 -> V_173 & V_174 )
V_69 -> V_175 = F_47 ( V_49 -> V_74 . V_176 . V_177 . V_178 ) ;
}
static inline bool F_109 ( struct V_37 * V_98 ,
union V_48 * V_49 )
{
T_7 V_179 = V_49 -> V_74 . V_176 . V_180 . V_181 . V_179 ;
return F_8 ( V_182 , & V_98 -> V_23 ) &&
( ( V_179 & F_110 ( V_183 ) ) ==
( F_110 ( V_184 <<
V_185 ) ) ) ;
}
static inline void F_111 ( struct V_37 * V_98 ,
union V_48 * V_49 ,
struct V_172 * V_69 )
{
F_112 ( V_69 ) ;
if ( ! ( V_98 -> V_35 -> V_173 & V_186 ) )
return;
if ( F_113 ( V_49 , V_187 ) &&
F_113 ( V_49 , V_188 ) ) {
V_98 -> V_189 . V_190 ++ ;
return;
}
if ( ! F_113 ( V_49 , V_191 ) )
return;
if ( F_113 ( V_49 , V_192 ) ) {
T_7 V_179 = V_49 -> V_74 . V_176 . V_180 . V_181 . V_179 ;
if ( ( V_179 & F_110 ( V_193 ) ) &&
F_8 ( V_194 , & V_98 -> V_23 ) )
return;
V_98 -> V_189 . V_190 ++ ;
return;
}
V_69 -> V_195 = V_196 ;
}
static inline void F_114 ( struct V_37 * V_47 , T_1 V_197 )
{
V_47 -> V_60 = V_197 ;
V_47 -> V_198 = V_197 ;
F_115 () ;
F_116 ( V_197 , V_47 -> V_125 ) ;
}
static bool F_117 ( struct V_37 * V_47 ,
struct V_50 * V_199 )
{
struct V_78 * V_78 = V_199 -> V_78 ;
T_8 V_61 = V_199 -> V_61 ;
if ( F_79 ( V_61 ) )
return true ;
if ( F_79 ( ! V_78 ) ) {
V_78 = F_118 ( V_200 | V_201 | V_202 ,
V_199 -> V_69 , F_119 ( V_47 ) ) ;
if ( F_77 ( ! V_78 ) ) {
V_47 -> V_189 . V_203 ++ ;
return false ;
}
V_199 -> V_78 = V_78 ;
}
V_61 = F_120 ( V_47 -> V_53 , V_78 , 0 ,
F_121 ( V_47 ) , V_204 ) ;
if ( F_122 ( V_47 -> V_53 , V_61 ) ) {
F_123 ( V_78 , F_119 ( V_47 ) ) ;
V_199 -> V_78 = NULL ;
V_47 -> V_189 . V_203 ++ ;
return false ;
}
V_199 -> V_61 = V_61 ;
V_199 -> V_79 = 0 ;
return true ;
}
void F_124 ( struct V_37 * V_47 , T_2 V_205 )
{
union V_48 * V_49 ;
struct V_50 * V_199 ;
T_2 V_28 = V_47 -> V_60 ;
if ( ! V_205 )
return;
V_49 = F_46 ( V_47 , V_28 ) ;
V_199 = & V_47 -> V_51 [ V_28 ] ;
V_28 -= V_47 -> V_68 ;
do {
if ( ! F_117 ( V_47 , V_199 ) )
break;
V_49 -> V_206 . V_207 = F_125 ( V_199 -> V_61 + V_199 -> V_79 ) ;
V_49 ++ ;
V_199 ++ ;
V_28 ++ ;
if ( F_77 ( ! V_28 ) ) {
V_49 = F_46 ( V_47 , 0 ) ;
V_199 = V_47 -> V_51 ;
V_28 -= V_47 -> V_68 ;
}
V_49 -> V_206 . V_208 = 0 ;
V_205 -- ;
} while ( V_205 );
V_28 += V_47 -> V_68 ;
if ( V_47 -> V_60 != V_28 )
F_114 ( V_47 , V_28 ) ;
}
static unsigned int F_126 ( unsigned char * V_72 ,
unsigned int V_209 )
{
union {
unsigned char * V_210 ;
struct V_211 * V_212 ;
struct V_213 * V_214 ;
struct V_215 * V_216 ;
struct V_217 * V_218 ;
} V_219 ;
T_9 V_220 ;
T_6 V_221 = 0 ;
T_6 V_222 ;
if ( V_209 < V_223 )
return V_209 ;
V_219 . V_210 = V_72 ;
V_220 = V_219 . V_212 -> V_224 ;
V_219 . V_210 += V_223 ;
if ( V_220 == F_127 ( V_225 ) ) {
if ( ( V_219 . V_210 - V_72 ) > ( V_209 - V_226 ) )
return V_209 ;
V_220 = V_219 . V_214 -> V_227 ;
V_219 . V_210 += V_226 ;
}
if ( V_220 == F_127 ( V_228 ) ) {
if ( ( V_219 . V_210 - V_72 ) > ( V_209 - sizeof( struct V_215 ) ) )
return V_209 ;
V_222 = ( V_219 . V_210 [ 0 ] & 0x0F ) << 2 ;
if ( V_222 < sizeof( struct V_215 ) )
return V_219 . V_210 - V_72 ;
if ( ! ( V_219 . V_216 -> V_229 & F_128 ( V_230 ) ) )
V_221 = V_219 . V_216 -> V_220 ;
} else if ( V_220 == F_127 ( V_231 ) ) {
if ( ( V_219 . V_210 - V_72 ) > ( V_209 - sizeof( struct V_217 ) ) )
return V_209 ;
V_221 = V_219 . V_218 -> V_221 ;
V_222 = sizeof( struct V_217 ) ;
#ifdef F_129
} else if ( V_220 == F_127 ( V_232 ) ) {
if ( ( V_219 . V_210 - V_72 ) > ( V_209 - V_233 ) )
return V_209 ;
V_222 = V_233 ;
#endif
} else {
return V_219 . V_210 - V_72 ;
}
V_219 . V_210 += V_222 ;
if ( V_221 == V_234 ) {
if ( ( V_219 . V_210 - V_72 ) > ( V_209 - sizeof( struct V_235 ) ) )
return V_209 ;
V_222 = ( V_219 . V_210 [ 12 ] & 0xF0 ) >> 2 ;
if ( V_222 < sizeof( struct V_235 ) )
return V_219 . V_210 - V_72 ;
V_219 . V_210 += V_222 ;
} else if ( V_221 == V_236 ) {
if ( ( V_219 . V_210 - V_72 ) > ( V_209 - sizeof( struct V_237 ) ) )
return V_209 ;
V_219 . V_210 += sizeof( struct V_237 ) ;
}
if ( ( V_219 . V_210 - V_72 ) < V_209 )
return V_219 . V_210 - V_72 ;
else
return V_209 ;
}
static void F_130 ( struct V_37 * V_98 ,
struct V_172 * V_69 )
{
T_2 V_238 = F_131 ( V_69 ) ;
F_132 ( V_69 ) -> V_239 = F_133 ( ( V_69 -> V_62 - V_238 ) ,
F_134 ( V_69 ) -> V_240 ) ;
F_132 ( V_69 ) -> V_241 = V_242 ;
}
static void F_135 ( struct V_37 * V_47 ,
struct V_172 * V_69 )
{
if ( ! F_134 ( V_69 ) -> V_240 )
return;
V_47 -> V_189 . V_243 += F_134 ( V_69 ) -> V_240 ;
V_47 -> V_189 . V_244 ++ ;
F_130 ( V_47 , V_69 ) ;
F_134 ( V_69 ) -> V_240 = 0 ;
}
static void F_136 ( struct V_37 * V_47 ,
union V_48 * V_49 ,
struct V_172 * V_69 )
{
struct V_34 * V_53 = V_47 -> V_35 ;
F_135 ( V_47 , V_69 ) ;
F_108 ( V_47 , V_49 , V_69 ) ;
F_111 ( V_47 , V_49 , V_69 ) ;
F_137 ( V_47 , V_49 , V_69 ) ;
if ( ( V_53 -> V_173 & V_245 ) &&
F_113 ( V_49 , V_246 ) ) {
T_2 V_247 = F_138 ( V_49 -> V_74 . V_75 . V_214 ) ;
F_139 ( V_69 , F_128 ( V_225 ) , V_247 ) ;
}
F_140 ( V_69 , V_47 -> V_66 ) ;
V_69 -> V_220 = F_141 ( V_69 , V_53 ) ;
}
static void F_142 ( struct V_134 * V_135 ,
struct V_172 * V_69 )
{
struct V_1 * V_2 = V_135 -> V_2 ;
if ( ! ( V_2 -> V_117 & V_248 ) )
F_143 ( & V_135 -> V_249 , V_69 ) ;
else
F_144 ( V_69 ) ;
}
static bool F_145 ( struct V_37 * V_47 ,
union V_48 * V_49 ,
struct V_172 * V_69 )
{
T_1 V_250 = V_47 -> V_59 + 1 ;
V_250 = ( V_250 < V_47 -> V_68 ) ? V_250 : 0 ;
V_47 -> V_59 = V_250 ;
F_78 ( F_46 ( V_47 , V_250 ) ) ;
if ( F_146 ( V_47 ) ) {
T_10 V_251 = V_49 -> V_74 . V_176 . V_180 . V_72 &
F_76 ( V_252 ) ;
if ( F_77 ( V_251 ) ) {
T_1 V_253 = F_47 ( V_251 ) ;
V_253 >>= V_254 ;
F_134 ( V_69 ) -> V_240 += V_253 - 1 ;
V_250 = F_47 ( V_49 -> V_74 . V_75 . V_76 ) ;
V_250 &= V_255 ;
V_250 >>= V_256 ;
}
}
if ( F_79 ( F_113 ( V_49 , V_257 ) ) )
return false ;
V_47 -> V_51 [ V_250 ] . V_69 = V_69 ;
V_47 -> V_189 . V_258 ++ ;
return true ;
}
static void F_147 ( struct V_37 * V_47 ,
struct V_172 * V_69 )
{
struct V_259 * V_260 = & F_132 ( V_69 ) -> V_261 [ 0 ] ;
unsigned char * V_262 ;
unsigned int V_263 ;
V_262 = F_148 ( V_260 ) ;
V_263 = F_126 ( V_262 , V_264 ) ;
F_149 ( V_69 , V_262 , F_150 ( V_263 , sizeof( long ) ) ) ;
F_151 ( V_260 , V_263 ) ;
V_260 -> V_79 += V_263 ;
V_69 -> V_265 -= V_263 ;
V_69 -> V_125 += V_263 ;
}
static void F_152 ( struct V_37 * V_47 ,
struct V_172 * V_69 )
{
if ( F_77 ( F_134 ( V_69 ) -> V_266 ) ) {
F_60 ( V_47 -> V_53 , F_134 ( V_69 ) -> V_61 ,
F_121 ( V_47 ) , V_204 ) ;
F_134 ( V_69 ) -> V_266 = false ;
} else {
struct V_259 * V_260 = & F_132 ( V_69 ) -> V_261 [ 0 ] ;
F_153 ( V_47 -> V_53 ,
F_134 ( V_69 ) -> V_61 ,
V_260 -> V_79 ,
F_49 ( V_47 ) ,
V_204 ) ;
}
F_134 ( V_69 ) -> V_61 = 0 ;
}
static bool F_154 ( struct V_37 * V_47 ,
union V_48 * V_49 ,
struct V_172 * V_69 )
{
struct V_34 * V_35 = V_47 -> V_35 ;
if ( F_77 ( F_113 ( V_49 ,
V_267 ) &&
! ( V_35 -> V_173 & V_268 ) ) ) {
F_58 ( V_69 ) ;
return true ;
}
if ( F_155 ( V_69 ) )
F_147 ( V_47 , V_69 ) ;
#ifdef F_129
if ( F_109 ( V_47 , V_49 ) )
return false ;
#endif
if ( F_77 ( V_69 -> V_62 < 60 ) ) {
int V_269 = 60 - V_69 -> V_62 ;
if ( F_156 ( V_69 , V_269 ) )
return true ;
F_157 ( V_69 , V_269 ) ;
}
return false ;
}
static void F_158 ( struct V_37 * V_47 ,
struct V_50 * V_270 )
{
struct V_50 * V_271 ;
T_2 V_272 = V_47 -> V_198 ;
V_271 = & V_47 -> V_51 [ V_272 ] ;
V_272 ++ ;
V_47 -> V_198 = ( V_272 < V_47 -> V_68 ) ? V_272 : 0 ;
V_271 -> V_78 = V_270 -> V_78 ;
V_271 -> V_61 = V_270 -> V_61 ;
V_271 -> V_79 = V_270 -> V_79 ;
F_159 ( V_47 -> V_53 , V_271 -> V_61 ,
V_271 -> V_79 ,
F_49 ( V_47 ) ,
V_204 ) ;
}
static bool F_160 ( struct V_37 * V_47 ,
struct V_50 * V_273 ,
union V_48 * V_49 ,
struct V_172 * V_69 )
{
struct V_78 * V_78 = V_273 -> V_78 ;
unsigned int V_274 = F_138 ( V_49 -> V_74 . V_75 . V_275 ) ;
#if ( V_276 < 8192 )
unsigned int V_277 = F_49 ( V_47 ) ;
#else
unsigned int V_277 = F_150 ( V_274 , V_278 ) ;
unsigned int V_279 = F_121 ( V_47 ) -
F_49 ( V_47 ) ;
#endif
if ( ( V_274 <= V_264 ) && ! F_155 ( V_69 ) ) {
unsigned char * V_262 = F_48 ( V_78 ) + V_273 -> V_79 ;
memcpy ( F_157 ( V_69 , V_274 ) , V_262 , F_150 ( V_274 , sizeof( long ) ) ) ;
if ( F_79 ( F_161 ( V_78 ) == F_162 () ) )
return true ;
F_163 ( V_78 ) ;
return false ;
}
F_164 ( V_69 , F_132 ( V_69 ) -> V_280 , V_78 ,
V_273 -> V_79 , V_274 , V_277 ) ;
if ( F_77 ( F_161 ( V_78 ) != F_162 () ) )
return false ;
#if ( V_276 < 8192 )
if ( F_77 ( F_165 ( V_78 ) != 1 ) )
return false ;
V_273 -> V_79 ^= V_277 ;
F_166 ( & V_78 -> V_281 , 2 ) ;
#else
V_273 -> V_79 += V_277 ;
if ( V_273 -> V_79 > V_279 )
return false ;
F_167 ( V_78 ) ;
#endif
return true ;
}
static struct V_172 * F_168 ( struct V_37 * V_47 ,
union V_48 * V_49 )
{
struct V_50 * V_273 ;
struct V_172 * V_69 ;
struct V_78 * V_78 ;
V_273 = & V_47 -> V_51 [ V_47 -> V_59 ] ;
V_78 = V_273 -> V_78 ;
F_169 ( V_78 ) ;
V_69 = V_273 -> V_69 ;
if ( F_79 ( ! V_69 ) ) {
void * V_282 = F_48 ( V_78 ) +
V_273 -> V_79 ;
F_78 ( V_282 ) ;
#if V_278 < 128
F_78 ( V_282 + V_278 ) ;
#endif
V_69 = F_170 ( V_47 -> V_35 ,
V_264 ) ;
if ( F_77 ( ! V_69 ) ) {
V_47 -> V_189 . V_283 ++ ;
return NULL ;
}
F_169 ( V_69 -> V_72 ) ;
if ( F_79 ( F_113 ( V_49 , V_257 ) ) )
goto V_284;
F_134 ( V_69 ) -> V_61 = V_273 -> V_61 ;
} else {
if ( F_113 ( V_49 , V_257 ) )
F_152 ( V_47 , V_69 ) ;
V_284:
F_153 ( V_47 -> V_53 ,
V_273 -> V_61 ,
V_273 -> V_79 ,
F_49 ( V_47 ) ,
V_204 ) ;
}
if ( F_160 ( V_47 , V_273 , V_49 , V_69 ) ) {
F_158 ( V_47 , V_273 ) ;
} else if ( F_134 ( V_69 ) -> V_61 == V_273 -> V_61 ) {
F_134 ( V_69 ) -> V_266 = true ;
} else {
F_60 ( V_47 -> V_53 , V_273 -> V_61 ,
F_121 ( V_47 ) ,
V_204 ) ;
}
V_273 -> V_69 = NULL ;
V_273 -> V_61 = 0 ;
V_273 -> V_78 = NULL ;
return V_69 ;
}
static bool F_171 ( struct V_134 * V_135 ,
struct V_37 * V_47 ,
const int V_138 )
{
unsigned int V_285 = 0 , V_286 = 0 ;
#ifdef F_129
struct V_1 * V_2 = V_135 -> V_2 ;
int V_287 ;
unsigned int V_288 = 0 ;
#endif
T_2 V_205 = F_90 ( V_47 ) ;
do {
union V_48 * V_49 ;
struct V_172 * V_69 ;
if ( V_205 >= V_289 ) {
F_124 ( V_47 , V_205 ) ;
V_205 = 0 ;
}
V_49 = F_46 ( V_47 , V_47 -> V_59 ) ;
if ( ! F_113 ( V_49 , V_77 ) )
break;
F_172 () ;
V_69 = F_168 ( V_47 , V_49 ) ;
if ( ! V_69 )
break;
V_205 ++ ;
if ( F_145 ( V_47 , V_49 , V_69 ) )
continue;
if ( F_154 ( V_47 , V_49 , V_69 ) )
continue;
V_285 += V_69 -> V_62 ;
F_136 ( V_47 , V_49 , V_69 ) ;
#ifdef F_129
if ( F_109 ( V_47 , V_49 ) ) {
V_287 = F_173 ( V_2 , V_49 , V_69 ) ;
if ( V_287 > 0 ) {
if ( ! V_288 ) {
V_288 = V_47 -> V_35 -> V_290 -
sizeof( struct V_291 ) -
sizeof( struct V_292 ) -
sizeof( struct V_293 ) ;
if ( V_288 > 512 )
V_288 &= ~ 511 ;
}
V_285 += V_287 ;
V_286 += F_133 ( V_287 ,
V_288 ) ;
}
if ( ! V_287 ) {
F_58 ( V_69 ) ;
continue;
}
}
#endif
F_142 ( V_135 , V_69 ) ;
V_286 ++ ;
} while ( F_79 ( V_286 < V_138 ) );
F_80 ( & V_47 -> V_146 ) ;
V_47 -> V_102 . V_122 += V_286 ;
V_47 -> V_102 . V_147 += V_285 ;
F_81 ( & V_47 -> V_146 ) ;
V_135 -> V_294 . V_137 += V_286 ;
V_135 -> V_294 . V_136 += V_285 ;
if ( V_205 )
F_124 ( V_47 , V_205 ) ;
return ( V_286 < V_138 ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
struct V_134 * V_135 ;
int V_295 ;
T_1 V_95 ;
if ( V_2 -> V_296 > 32 ) {
T_1 V_297 = ( 1 << ( V_2 -> V_296 - 32 ) ) - 1 ;
F_51 ( & V_2 -> V_16 , V_298 , V_297 ) ;
}
for ( V_295 = 0 ; V_295 < V_2 -> V_166 ; V_295 ++ ) {
struct V_37 * V_98 ;
V_135 = V_2 -> V_135 [ V_295 ] ;
F_101 (ring, q_vector->rx)
F_53 ( V_2 , 0 , V_98 -> V_124 , V_295 ) ;
F_101 (ring, q_vector->tx)
F_53 ( V_2 , 1 , V_98 -> V_124 , V_295 ) ;
F_175 ( V_135 ) ;
}
switch ( V_2 -> V_16 . V_88 . type ) {
case V_89 :
F_53 ( V_2 , - 1 , V_299 ,
V_295 ) ;
break;
case V_91 :
case V_92 :
F_53 ( V_2 , - 1 , 1 , V_295 ) ;
break;
default:
break;
}
F_51 ( & V_2 -> V_16 , F_176 ( V_295 ) , 1950 ) ;
V_95 = V_300 ;
V_95 &= ~ ( V_301 |
V_302 |
V_303 ) ;
F_51 ( & V_2 -> V_16 , V_304 , V_95 ) ;
}
static void F_177 ( struct V_134 * V_135 ,
struct V_305 * V_306 )
{
int V_147 = V_306 -> V_136 ;
int V_122 = V_306 -> V_137 ;
T_1 V_307 ;
T_4 V_308 ;
T_6 V_309 = V_306 -> V_310 ;
if ( V_122 == 0 )
return;
V_307 = V_135 -> V_310 >> 2 ;
if ( V_307 == 0 )
return;
V_308 = V_147 / V_307 ;
switch ( V_309 ) {
case V_311 :
if ( V_308 > 10 )
V_309 = V_312 ;
break;
case V_312 :
if ( V_308 > 20 )
V_309 = V_313 ;
else if ( V_308 <= 10 )
V_309 = V_311 ;
break;
case V_313 :
if ( V_308 <= 20 )
V_309 = V_312 ;
break;
}
V_306 -> V_136 = 0 ;
V_306 -> V_137 = 0 ;
V_306 -> V_310 = V_309 ;
}
void F_175 ( struct V_134 * V_135 )
{
struct V_1 * V_2 = V_135 -> V_2 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_295 = V_135 -> V_295 ;
T_1 V_314 = V_135 -> V_310 & V_315 ;
switch ( V_2 -> V_16 . V_88 . type ) {
case V_89 :
V_314 |= ( V_314 << 16 ) ;
break;
case V_91 :
case V_92 :
V_314 |= V_316 ;
break;
default:
break;
}
F_51 ( V_16 , F_176 ( V_295 ) , V_314 ) ;
}
static void F_178 ( struct V_134 * V_135 )
{
T_1 V_317 = V_135 -> V_310 ;
T_6 V_318 ;
F_177 ( V_135 , & V_135 -> V_139 ) ;
F_177 ( V_135 , & V_135 -> V_294 ) ;
V_318 = F_179 ( V_135 -> V_294 . V_310 , V_135 -> V_139 . V_310 ) ;
switch ( V_318 ) {
case V_311 :
V_317 = V_319 ;
break;
case V_312 :
V_317 = V_320 ;
break;
case V_313 :
V_317 = V_321 ;
break;
default:
break;
}
if ( V_317 != V_135 -> V_310 ) {
V_317 = ( 10 * V_317 * V_135 -> V_310 ) /
( ( 9 * V_317 ) + V_135 -> V_310 ) ;
V_135 -> V_310 = V_317 ;
F_175 ( V_135 ) ;
}
}
static void F_180 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_322 = V_2 -> V_323 ;
if ( F_8 ( V_22 , & V_2 -> V_23 ) )
return;
if ( ! ( V_2 -> V_131 & V_324 ) &&
! ( V_2 -> V_131 & V_325 ) )
return;
V_2 -> V_131 &= ~ V_325 ;
switch ( V_16 -> V_326 ) {
case V_327 :
if ( ! ( V_322 & V_328 ) &&
! ( V_322 & V_329 ) )
return;
if ( ! ( V_322 & V_329 ) && V_16 -> V_88 . V_330 . V_331 ) {
T_1 V_21 ;
bool V_332 = false ;
V_16 -> V_88 . V_330 . V_331 ( V_16 , & V_21 , & V_332 , false ) ;
if ( V_332 )
return;
}
if ( V_16 -> V_333 . V_330 . V_334 ( V_16 ) != V_335 )
return;
break;
default:
if ( ! ( V_322 & V_328 ) )
return;
break;
}
F_181 ( V_133 ,
L_57
L_58
L_59 ) ;
V_2 -> V_323 = 0 ;
}
static void F_182 ( struct V_1 * V_2 , T_1 V_322 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
if ( ( V_2 -> V_117 & V_336 ) &&
( V_322 & V_337 ) ) {
F_181 ( V_149 , L_60 ) ;
F_51 ( V_16 , V_338 , V_337 ) ;
}
}
static void F_183 ( struct V_1 * V_2 , T_1 V_322 )
{
if ( ! ( V_2 -> V_131 & V_324 ) )
return;
switch ( V_2 -> V_16 . V_88 . type ) {
case V_91 :
if ( ( ( V_322 & V_328 ) || ( V_322 & V_329 ) ) &&
( ! F_8 ( V_22 , & V_2 -> V_23 ) ) ) {
V_2 -> V_323 = V_322 ;
V_2 -> V_131 |= V_325 ;
F_7 ( V_2 ) ;
return;
}
return;
case V_92 :
if ( ! ( V_322 & V_339 ) )
return;
break;
default:
return;
}
F_181 ( V_133 ,
L_57
L_58
L_59 ) ;
}
static void F_184 ( struct V_1 * V_2 , T_1 V_322 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
if ( V_322 & V_340 ) {
F_51 ( V_16 , V_338 , V_340 ) ;
if ( ! F_8 ( V_22 , & V_2 -> V_23 ) ) {
V_2 -> V_131 |= V_341 ;
F_7 ( V_2 ) ;
}
}
if ( V_322 & V_337 ) {
F_51 ( V_16 , V_338 , V_337 ) ;
if ( ! F_8 ( V_22 , & V_2 -> V_23 ) ) {
V_2 -> V_117 |= V_342 ;
F_7 ( V_2 ) ;
}
}
}
static void F_185 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
V_2 -> V_343 ++ ;
V_2 -> V_117 |= V_344 ;
V_2 -> V_345 = V_148 ;
if ( ! F_8 ( V_22 , & V_2 -> V_23 ) ) {
F_51 ( V_16 , V_346 , V_347 ) ;
F_186 ( V_16 ) ;
F_7 ( V_2 ) ;
}
}
static inline void F_187 ( struct V_1 * V_2 ,
T_4 V_94 )
{
T_1 V_95 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_95 = ( V_96 & V_94 ) ;
F_51 ( V_16 , V_348 , V_95 ) ;
break;
case V_91 :
case V_92 :
V_95 = ( V_94 & 0xFFFFFFFF ) ;
if ( V_95 )
F_51 ( V_16 , F_188 ( 0 ) , V_95 ) ;
V_95 = ( V_94 >> 32 ) ;
if ( V_95 )
F_51 ( V_16 , F_188 ( 1 ) , V_95 ) ;
break;
default:
break;
}
}
static inline void F_189 ( struct V_1 * V_2 ,
T_4 V_94 )
{
T_1 V_95 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_95 = ( V_96 & V_94 ) ;
F_51 ( V_16 , V_346 , V_95 ) ;
break;
case V_91 :
case V_92 :
V_95 = ( V_94 & 0xFFFFFFFF ) ;
if ( V_95 )
F_51 ( V_16 , F_190 ( 0 ) , V_95 ) ;
V_95 = ( V_94 >> 32 ) ;
if ( V_95 )
F_51 ( V_16 , F_190 ( 1 ) , V_95 ) ;
break;
default:
break;
}
}
static inline void F_191 ( struct V_1 * V_2 , bool V_349 ,
bool V_350 )
{
T_1 V_95 = ( V_300 & ~ V_96 ) ;
if ( V_2 -> V_117 & V_344 )
V_95 &= ~ V_303 ;
if ( V_2 -> V_131 & V_324 )
switch ( V_2 -> V_16 . V_88 . type ) {
case V_91 :
V_95 |= V_351 ;
break;
case V_92 :
V_95 |= V_352 ;
break;
default:
break;
}
if ( V_2 -> V_117 & V_336 )
V_95 |= V_353 ;
switch ( V_2 -> V_16 . V_88 . type ) {
case V_91 :
V_95 |= V_353 ;
V_95 |= V_354 ;
case V_92 :
V_95 |= V_355 ;
V_95 |= V_302 ;
break;
default:
break;
}
if ( V_2 -> V_16 . V_88 . type == V_92 )
V_95 |= V_356 ;
if ( ( V_2 -> V_117 & V_357 ) &&
! ( V_2 -> V_131 & V_358 ) )
V_95 |= V_359 ;
F_51 ( & V_2 -> V_16 , V_348 , V_95 ) ;
if ( V_349 )
F_187 ( V_2 , ~ 0 ) ;
if ( V_350 )
F_186 ( & V_2 -> V_16 ) ;
}
static T_11 F_192 ( int V_360 , void * V_72 )
{
struct V_1 * V_2 = V_72 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_322 ;
V_322 = F_17 ( V_16 , V_97 ) ;
V_322 &= 0xFFFF0000 ;
F_51 ( V_16 , V_338 , V_322 ) ;
if ( V_322 & V_329 )
F_185 ( V_2 ) ;
if ( V_322 & V_361 )
F_193 ( V_2 ) ;
switch ( V_16 -> V_88 . type ) {
case V_91 :
case V_92 :
if ( V_322 & V_362 )
F_85 ( V_363 , L_61
L_62 ) ;
if ( V_322 & V_364 ) {
int V_365 = 0 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ ) {
struct V_37 * V_98 = V_2 -> V_38 [ V_28 ] ;
if ( F_194 ( V_366 ,
& V_98 -> V_23 ) )
V_365 ++ ;
}
if ( V_365 ) {
F_51 ( V_16 , V_346 , V_367 ) ;
V_2 -> V_131 |= V_358 ;
F_7 ( V_2 ) ;
}
}
F_184 ( V_2 , V_322 ) ;
F_183 ( V_2 , V_322 ) ;
break;
default:
break;
}
F_182 ( V_2 , V_322 ) ;
if ( F_77 ( V_322 & V_368 ) )
F_195 ( V_2 , V_322 ) ;
if ( ! F_8 ( V_22 , & V_2 -> V_23 ) )
F_191 ( V_2 , false , false ) ;
return V_369 ;
}
static T_11 F_196 ( int V_360 , void * V_72 )
{
struct V_134 * V_135 = V_72 ;
if ( V_135 -> V_294 . V_98 || V_135 -> V_139 . V_98 )
F_197 ( & V_135 -> V_249 ) ;
return V_369 ;
}
int F_198 ( struct V_370 * V_249 , int V_138 )
{
struct V_134 * V_135 =
F_199 ( V_249 , struct V_134 , V_249 ) ;
struct V_1 * V_2 = V_135 -> V_2 ;
struct V_37 * V_98 ;
int V_371 ;
bool V_372 = true ;
#ifdef F_200
if ( V_2 -> V_117 & V_164 )
F_99 ( V_135 ) ;
#endif
F_101 (ring, q_vector->tx)
V_372 &= ! ! F_74 ( V_135 , V_98 ) ;
if ( V_135 -> V_294 . V_68 > 1 )
V_371 = F_179 ( V_138 / V_135 -> V_294 . V_68 , 1 ) ;
else
V_371 = V_138 ;
F_101 (ring, q_vector->rx)
V_372 &= F_171 ( V_135 , V_98 ,
V_371 ) ;
if ( ! V_372 )
return V_138 ;
F_201 ( V_249 ) ;
if ( V_2 -> V_373 & 1 )
F_178 ( V_135 ) ;
if ( ! F_8 ( V_22 , & V_2 -> V_23 ) )
F_187 ( V_2 , ( ( T_4 ) 1 << V_135 -> V_295 ) ) ;
return 0 ;
}
static int F_202 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
int V_374 , V_18 ;
int V_375 = 0 , V_376 = 0 ;
for ( V_374 = 0 ; V_374 < V_2 -> V_166 ; V_374 ++ ) {
struct V_134 * V_135 = V_2 -> V_135 [ V_374 ] ;
struct V_377 * V_378 = & V_2 -> V_379 [ V_374 ] ;
if ( V_135 -> V_139 . V_98 && V_135 -> V_294 . V_98 ) {
snprintf ( V_135 -> V_33 , sizeof( V_135 -> V_33 ) - 1 ,
L_63 , V_35 -> V_33 , L_64 , V_375 ++ ) ;
V_376 ++ ;
} else if ( V_135 -> V_294 . V_98 ) {
snprintf ( V_135 -> V_33 , sizeof( V_135 -> V_33 ) - 1 ,
L_63 , V_35 -> V_33 , L_65 , V_375 ++ ) ;
} else if ( V_135 -> V_139 . V_98 ) {
snprintf ( V_135 -> V_33 , sizeof( V_135 -> V_33 ) - 1 ,
L_63 , V_35 -> V_33 , L_66 , V_376 ++ ) ;
} else {
continue;
}
V_18 = F_203 ( V_378 -> V_374 , & F_196 , 0 ,
V_135 -> V_33 , V_135 ) ;
if ( V_18 ) {
F_83 ( V_149 , L_67
L_68 , V_18 ) ;
goto V_380;
}
if ( V_2 -> V_117 & V_357 ) {
F_204 ( V_378 -> V_374 ,
& V_135 -> V_381 ) ;
}
}
V_18 = F_203 ( V_2 -> V_379 [ V_374 ] . V_374 ,
F_192 , 0 , V_35 -> V_33 , V_2 ) ;
if ( V_18 ) {
F_83 ( V_149 , L_69 , V_18 ) ;
goto V_380;
}
return 0 ;
V_380:
while ( V_374 ) {
V_374 -- ;
F_204 ( V_2 -> V_379 [ V_374 ] . V_374 ,
NULL ) ;
F_205 ( V_2 -> V_379 [ V_374 ] . V_374 ,
V_2 -> V_135 [ V_374 ] ) ;
}
V_2 -> V_117 &= ~ V_382 ;
F_206 ( V_2 -> V_10 ) ;
F_207 ( V_2 -> V_379 ) ;
V_2 -> V_379 = NULL ;
return V_18 ;
}
static T_11 F_208 ( int V_360 , void * V_72 )
{
struct V_1 * V_2 = V_72 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_134 * V_135 = V_2 -> V_135 [ 0 ] ;
T_1 V_322 ;
F_51 ( V_16 , V_346 , V_383 ) ;
V_322 = F_17 ( V_16 , V_338 ) ;
if ( ! V_322 ) {
if ( ! F_8 ( V_22 , & V_2 -> V_23 ) )
F_191 ( V_2 , true , true ) ;
return V_384 ;
}
if ( V_322 & V_329 )
F_185 ( V_2 ) ;
switch ( V_16 -> V_88 . type ) {
case V_91 :
F_184 ( V_2 , V_322 ) ;
case V_92 :
if ( V_322 & V_362 )
F_85 ( V_363 , L_70
L_62 ) ;
F_183 ( V_2 , V_322 ) ;
break;
default:
break;
}
F_182 ( V_2 , V_322 ) ;
if ( F_77 ( V_322 & V_368 ) )
F_195 ( V_2 , V_322 ) ;
F_197 ( & V_135 -> V_249 ) ;
if ( ! F_8 ( V_22 , & V_2 -> V_23 ) )
F_191 ( V_2 , false , false ) ;
return V_369 ;
}
static int F_209 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
int V_18 ;
if ( V_2 -> V_117 & V_382 )
V_18 = F_202 ( V_2 ) ;
else if ( V_2 -> V_117 & V_385 )
V_18 = F_203 ( V_2 -> V_10 -> V_360 , F_208 , 0 ,
V_35 -> V_33 , V_2 ) ;
else
V_18 = F_203 ( V_2 -> V_10 -> V_360 , F_208 , V_386 ,
V_35 -> V_33 , V_2 ) ;
if ( V_18 )
F_83 ( V_149 , L_71 , V_18 ) ;
return V_18 ;
}
static void F_210 ( struct V_1 * V_2 )
{
int V_374 ;
if ( ! ( V_2 -> V_117 & V_382 ) ) {
F_205 ( V_2 -> V_10 -> V_360 , V_2 ) ;
return;
}
for ( V_374 = 0 ; V_374 < V_2 -> V_166 ; V_374 ++ ) {
struct V_134 * V_135 = V_2 -> V_135 [ V_374 ] ;
struct V_377 * V_378 = & V_2 -> V_379 [ V_374 ] ;
if ( ! V_135 -> V_294 . V_98 && ! V_135 -> V_139 . V_98 )
continue;
F_204 ( V_378 -> V_374 , NULL ) ;
F_205 ( V_378 -> V_374 , V_135 ) ;
}
F_205 ( V_2 -> V_379 [ V_374 ++ ] . V_374 , V_2 ) ;
}
static inline void F_211 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_16 . V_88 . type ) {
case V_89 :
F_51 ( & V_2 -> V_16 , V_346 , ~ 0 ) ;
break;
case V_91 :
case V_92 :
F_51 ( & V_2 -> V_16 , V_346 , 0xFFFF0000 ) ;
F_51 ( & V_2 -> V_16 , F_190 ( 0 ) , ~ 0 ) ;
F_51 ( & V_2 -> V_16 , F_190 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_186 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_117 & V_382 ) {
int V_374 ;
for ( V_374 = 0 ; V_374 < V_2 -> V_166 ; V_374 ++ )
F_212 ( V_2 -> V_379 [ V_374 ] . V_374 ) ;
F_212 ( V_2 -> V_379 [ V_374 ++ ] . V_374 ) ;
} else {
F_212 ( V_2 -> V_10 -> V_360 ) ;
}
}
static void F_213 ( struct V_1 * V_2 )
{
struct V_134 * V_135 = V_2 -> V_135 [ 0 ] ;
F_175 ( V_135 ) ;
F_53 ( V_2 , 0 , 0 , 0 ) ;
F_53 ( V_2 , 1 , 0 , 0 ) ;
F_85 ( V_16 , L_72 ) ;
}
void F_214 ( struct V_1 * V_2 ,
struct V_37 * V_98 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_4 V_387 = V_98 -> V_61 ;
int V_388 = 10 ;
T_1 V_389 = V_390 ;
T_6 V_124 = V_98 -> V_124 ;
F_51 ( V_16 , F_30 ( V_124 ) , 0 ) ;
F_186 ( V_16 ) ;
F_51 ( V_16 , F_25 ( V_124 ) ,
( V_387 & F_215 ( 32 ) ) ) ;
F_51 ( V_16 , F_26 ( V_124 ) , ( V_387 >> 32 ) ) ;
F_51 ( V_16 , F_27 ( V_124 ) ,
V_98 -> V_68 * sizeof( union V_41 ) ) ;
F_51 ( V_16 , F_28 ( V_124 ) , 0 ) ;
F_51 ( V_16 , F_29 ( V_124 ) , 0 ) ;
V_98 -> V_125 = V_16 -> V_391 + F_29 ( V_124 ) ;
#if F_216 ( V_392 )
if ( ! V_98 -> V_135 || ( V_98 -> V_135 -> V_310 < V_319 ) )
#else
if ( ! V_98 -> V_135 || ( V_98 -> V_135 -> V_310 < 8 ) )
#endif
V_389 |= ( 1 << 16 ) ;
else
V_389 |= ( 8 << 16 ) ;
V_389 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_117 & V_357 ) {
V_98 -> V_393 = V_2 -> V_393 ;
V_98 -> V_394 = 0 ;
F_217 ( V_366 , & V_98 -> V_23 ) ;
} else {
V_98 -> V_393 = 0 ;
}
if ( ! F_9 ( V_395 , & V_98 -> V_23 ) ) {
struct V_134 * V_135 = V_98 -> V_135 ;
if ( V_135 )
F_218 ( V_2 -> V_35 ,
& V_135 -> V_381 ,
V_98 -> V_66 ) ;
}
F_14 ( V_110 , & V_98 -> V_23 ) ;
F_51 ( V_16 , F_30 ( V_124 ) , V_389 ) ;
if ( V_16 -> V_88 . type == V_89 &&
! ( F_17 ( V_16 , V_396 ) & V_397 ) )
return;
do {
F_219 ( 1000 , 2000 ) ;
V_389 = F_17 ( V_16 , F_30 ( V_124 ) ) ;
} while ( -- V_388 && ! ( V_389 & V_390 ) );
if ( ! V_388 )
F_83 ( V_133 , L_73 , V_124 ) ;
}
static void F_220 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_398 , V_399 ;
T_6 V_400 = F_221 ( V_2 -> V_35 ) ;
if ( V_16 -> V_88 . type == V_89 )
return;
V_398 = F_17 ( V_16 , V_401 ) ;
V_398 |= V_402 ;
F_51 ( V_16 , V_401 , V_398 ) ;
if ( V_2 -> V_117 & V_403 ) {
V_399 = V_404 ;
if ( V_400 > 4 )
V_399 |= V_405 | V_406 ;
else if ( V_400 > 1 )
V_399 |= V_405 | V_407 ;
else if ( V_2 -> V_408 [ V_409 ] . V_410 == 4 )
V_399 |= V_411 ;
else
V_399 |= V_412 ;
} else {
if ( V_400 > 4 )
V_399 = V_405 | V_406 ;
else if ( V_400 > 1 )
V_399 = V_405 | V_407 ;
else
V_399 = V_413 ;
}
F_51 ( V_16 , V_414 , V_399 ) ;
if ( V_400 ) {
T_1 V_415 = F_17 ( V_16 , V_416 ) ;
V_415 |= V_417 ;
F_51 ( V_16 , V_416 , V_415 ) ;
}
V_398 &= ~ V_402 ;
F_51 ( V_16 , V_401 , V_398 ) ;
}
static void F_222 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_418 ;
T_1 V_28 ;
F_220 ( V_2 ) ;
if ( V_16 -> V_88 . type != V_89 ) {
V_418 = F_17 ( V_16 , V_419 ) ;
V_418 |= V_420 ;
F_51 ( V_16 , V_419 , V_418 ) ;
}
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ )
F_214 ( V_2 , V_2 -> V_38 [ V_28 ] ) ;
}
static void F_223 ( struct V_1 * V_2 ,
struct V_37 * V_98 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_6 V_124 = V_98 -> V_124 ;
T_1 V_421 = F_17 ( V_16 , F_16 ( V_124 ) ) ;
V_421 |= V_422 ;
F_51 ( V_16 , F_16 ( V_124 ) , V_421 ) ;
}
static void F_224 ( struct V_1 * V_2 ,
struct V_37 * V_98 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_6 V_124 = V_98 -> V_124 ;
T_1 V_421 = F_17 ( V_16 , F_16 ( V_124 ) ) ;
V_421 &= ~ V_422 ;
F_51 ( V_16 , F_16 ( V_124 ) , V_421 ) ;
}
static void F_225 ( struct V_1 * V_2 ,
struct V_37 * V_47 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_421 ;
T_6 V_124 = V_47 -> V_124 ;
if ( V_16 -> V_88 . type == V_89 ) {
T_2 V_95 = V_2 -> V_408 [ V_409 ] . V_95 ;
V_124 &= V_95 ;
}
V_421 = V_264 << V_423 ;
V_421 |= F_49 ( V_47 ) >> V_424 ;
V_421 |= V_425 ;
F_51 ( V_16 , F_16 ( V_124 ) , V_421 ) ;
}
static void F_226 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
static const T_1 V_426 [ 10 ] = { 0xE291D73D , 0x1805EC6C , 0x2A94B30D ,
0xA54F2BEC , 0xEA49AF7C , 0xE214AD3D , 0xB855AABE ,
0x6A3E67EA , 0x14364D17 , 0x3BED200D } ;
T_1 V_427 = 0 , V_428 = 0 ;
T_1 V_429 ;
int V_28 , V_29 ;
T_2 V_430 = V_2 -> V_408 [ V_409 ] . V_410 ;
if ( ( V_2 -> V_117 & V_403 ) && ( V_430 < 2 ) )
V_430 = 2 ;
for ( V_28 = 0 ; V_28 < 10 ; V_28 ++ )
F_51 ( V_16 , F_227 ( V_28 ) , V_426 [ V_28 ] ) ;
for ( V_28 = 0 , V_29 = 0 ; V_28 < 128 ; V_28 ++ , V_29 ++ ) {
if ( V_29 == V_430 )
V_29 = 0 ;
V_428 = ( V_428 << 8 ) | ( V_29 * 0x11 ) ;
if ( ( V_28 & 3 ) == 3 )
F_51 ( V_16 , F_228 ( V_28 >> 2 ) , V_428 ) ;
}
V_429 = F_17 ( V_16 , V_431 ) ;
V_429 |= V_432 ;
F_51 ( V_16 , V_431 , V_429 ) ;
if ( V_2 -> V_16 . V_88 . type == V_89 ) {
if ( V_2 -> V_408 [ V_409 ] . V_95 )
V_427 = V_433 ;
} else {
T_6 V_400 = F_221 ( V_2 -> V_35 ) ;
if ( V_2 -> V_117 & V_403 ) {
if ( V_400 > 4 )
V_427 = V_434 ;
else if ( V_400 > 1 )
V_427 = V_435 ;
else if ( V_2 -> V_408 [ V_409 ] . V_410 == 4 )
V_427 = V_436 ;
else
V_427 = V_437 ;
} else {
if ( V_400 > 4 )
V_427 = V_438 ;
else if ( V_400 > 1 )
V_427 = V_439 ;
else
V_427 = V_433 ;
}
}
V_427 |= V_440 |
V_441 |
V_442 |
V_443 ;
if ( V_2 -> V_131 & V_444 )
V_427 |= V_445 ;
if ( V_2 -> V_131 & V_446 )
V_427 |= V_447 ;
F_51 ( V_16 , V_448 , V_427 ) ;
}
static void F_229 ( struct V_1 * V_2 ,
struct V_37 * V_98 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_449 ;
T_6 V_124 = V_98 -> V_124 ;
if ( ! F_146 ( V_98 ) )
return;
V_449 = F_17 ( V_16 , F_230 ( V_124 ) ) ;
V_449 |= V_450 ;
V_449 |= V_451 ;
F_51 ( V_16 , F_230 ( V_124 ) , V_449 ) ;
}
static void F_231 ( struct V_1 * V_2 ,
struct V_37 * V_98 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_388 = V_452 ;
T_1 V_453 ;
T_6 V_124 = V_98 -> V_124 ;
if ( V_16 -> V_88 . type == V_89 &&
! ( F_17 ( V_16 , V_396 ) & V_397 ) )
return;
do {
F_219 ( 1000 , 2000 ) ;
V_453 = F_17 ( V_16 , F_22 ( V_124 ) ) ;
} while ( -- V_388 && ! ( V_453 & V_454 ) );
if ( ! V_388 ) {
F_83 ( V_133 , L_74
L_75 , V_124 ) ;
}
}
void F_232 ( struct V_1 * V_2 ,
struct V_37 * V_98 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_388 = V_452 ;
T_1 V_453 ;
T_6 V_124 = V_98 -> V_124 ;
V_453 = F_17 ( V_16 , F_22 ( V_124 ) ) ;
V_453 &= ~ V_454 ;
F_51 ( V_16 , F_22 ( V_124 ) , V_453 ) ;
if ( V_16 -> V_88 . type == V_89 &&
! ( F_17 ( V_16 , V_396 ) & V_397 ) )
return;
do {
F_233 ( 10 ) ;
V_453 = F_17 ( V_16 , F_22 ( V_124 ) ) ;
} while ( -- V_388 && ( V_453 & V_454 ) );
if ( ! V_388 ) {
F_83 ( V_133 , L_76
L_75 , V_124 ) ;
}
}
void F_234 ( struct V_1 * V_2 ,
struct V_37 * V_98 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_4 V_455 = V_98 -> V_61 ;
T_1 V_453 ;
T_6 V_124 = V_98 -> V_124 ;
V_453 = F_17 ( V_16 , F_22 ( V_124 ) ) ;
F_232 ( V_2 , V_98 ) ;
F_51 ( V_16 , F_23 ( V_124 ) , ( V_455 & F_215 ( 32 ) ) ) ;
F_51 ( V_16 , F_24 ( V_124 ) , ( V_455 >> 32 ) ) ;
F_51 ( V_16 , F_19 ( V_124 ) ,
V_98 -> V_68 * sizeof( union V_48 ) ) ;
F_51 ( V_16 , F_20 ( V_124 ) , 0 ) ;
F_51 ( V_16 , F_21 ( V_124 ) , 0 ) ;
V_98 -> V_125 = V_16 -> V_391 + F_21 ( V_124 ) ;
F_225 ( V_2 , V_98 ) ;
F_229 ( V_2 , V_98 ) ;
if ( V_16 -> V_88 . type == V_89 ) {
V_453 &= ~ 0x3FFFFF ;
V_453 |= 0x080420 ;
}
V_453 |= V_454 ;
F_51 ( V_16 , F_22 ( V_124 ) , V_453 ) ;
F_231 ( V_2 , V_98 ) ;
F_124 ( V_98 , F_90 ( V_98 ) ) ;
}
static void F_235 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_430 = V_2 -> V_408 [ V_409 ] . V_410 ;
int V_456 ;
T_1 V_457 = V_458 |
V_459 |
V_460 |
V_461 |
V_462 ;
if ( V_16 -> V_88 . type == V_89 )
return;
if ( V_430 > 3 )
V_457 |= 2 << 29 ;
else if ( V_430 > 1 )
V_457 |= 1 << 29 ;
for ( V_456 = 0 ; V_456 < V_2 -> V_463 ; V_456 ++ )
F_51 ( V_16 , F_236 ( F_237 ( V_456 ) ) ,
V_457 ) ;
}
static void F_238 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_154 , V_464 ;
T_1 V_465 , V_466 ;
int V_28 ;
if ( ! ( V_2 -> V_117 & V_403 ) )
return;
V_466 = F_17 ( V_16 , V_467 ) ;
V_466 |= V_468 ;
V_466 &= ~ V_469 ;
V_466 |= F_237 ( 0 ) << V_470 ;
V_466 |= V_471 ;
F_51 ( V_16 , V_467 , V_466 ) ;
V_464 = F_237 ( 0 ) % 32 ;
V_154 = ( F_237 ( 0 ) >= 32 ) ? 1 : 0 ;
F_51 ( V_16 , F_239 ( V_154 ) , ( ~ 0 ) << V_464 ) ;
F_51 ( V_16 , F_239 ( V_154 ^ 1 ) , V_154 - 1 ) ;
F_51 ( V_16 , F_240 ( V_154 ) , ( ~ 0 ) << V_464 ) ;
F_51 ( V_16 , F_240 ( V_154 ^ 1 ) , V_154 - 1 ) ;
if ( V_2 -> V_131 & V_472 )
F_51 ( V_16 , V_473 , V_474 ) ;
V_16 -> V_88 . V_330 . V_475 ( V_16 , 0 , F_237 ( 0 ) ) ;
switch ( V_2 -> V_408 [ V_476 ] . V_95 ) {
case V_477 :
V_465 = V_478 ;
break;
case V_479 :
V_465 = V_480 ;
break;
default:
V_465 = V_481 ;
break;
}
F_51 ( V_16 , V_482 , V_465 ) ;
V_16 -> V_88 . V_330 . V_483 ( V_16 , ( V_2 -> V_296 != 0 ) ,
V_2 -> V_296 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_296 ; V_28 ++ ) {
if ( ! V_2 -> V_484 [ V_28 ] . V_485 )
F_241 ( V_2 -> V_35 , V_28 , false ) ;
}
}
static void F_242 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_34 * V_35 = V_2 -> V_35 ;
int V_486 = V_35 -> V_290 + V_223 + V_487 ;
struct V_37 * V_47 ;
int V_28 ;
T_1 V_488 , V_489 ;
#ifdef F_129
if ( ( V_2 -> V_117 & V_490 ) &&
( V_486 < V_491 ) )
V_486 = V_491 ;
#endif
if ( V_486 < ( V_492 + V_487 ) )
V_486 = ( V_492 + V_487 ) ;
V_488 = F_17 ( V_16 , V_493 ) ;
if ( V_486 != ( V_488 >> V_494 ) ) {
V_488 &= ~ V_495 ;
V_488 |= V_486 << V_494 ;
F_51 ( V_16 , V_493 , V_488 ) ;
}
V_489 = F_17 ( V_16 , V_496 ) ;
V_489 |= V_497 ;
F_51 ( V_16 , V_496 , V_489 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ ) {
V_47 = V_2 -> V_47 [ V_28 ] ;
if ( V_2 -> V_131 & V_498 )
F_243 ( V_47 ) ;
else
F_244 ( V_47 ) ;
}
}
static void F_245 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_499 = F_17 ( V_16 , V_500 ) ;
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_499 |= V_501 ;
break;
case V_91 :
case V_92 :
F_51 ( V_16 , V_502 ,
( V_503 | F_17 ( V_16 , V_502 ) ) ) ;
V_499 &= ~ V_504 ;
V_499 |= ( V_505 | V_506 ) ;
V_499 |= V_507 ;
break;
default:
return;
}
F_51 ( V_16 , V_500 , V_499 ) ;
}
static void F_246 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_28 ;
T_1 V_159 ;
V_159 = F_17 ( V_16 , V_508 ) ;
F_51 ( V_16 , V_508 , V_159 & ~ V_509 ) ;
F_235 ( V_2 ) ;
F_245 ( V_2 ) ;
F_226 ( V_2 ) ;
F_242 ( V_2 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ )
F_234 ( V_2 , V_2 -> V_47 [ V_28 ] ) ;
if ( V_16 -> V_88 . type == V_89 )
V_159 |= V_510 ;
V_159 |= V_509 ;
V_16 -> V_88 . V_330 . V_511 ( V_16 , V_159 ) ;
}
static int F_247 ( struct V_34 * V_35 ,
T_9 V_512 , T_2 V_247 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
V_16 -> V_88 . V_330 . V_513 ( & V_2 -> V_16 , V_247 , F_237 ( 0 ) , true ) ;
F_217 ( V_247 , V_2 -> V_514 ) ;
return 0 ;
}
static int F_248 ( struct V_34 * V_35 ,
T_9 V_512 , T_2 V_247 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
V_16 -> V_88 . V_330 . V_513 ( & V_2 -> V_16 , V_247 , F_237 ( 0 ) , false ) ;
F_14 ( V_247 , V_2 -> V_514 ) ;
return 0 ;
}
static void F_249 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_515 ;
V_515 = F_17 ( V_16 , V_516 ) ;
V_515 &= ~ ( V_517 | V_518 ) ;
F_51 ( V_16 , V_516 , V_515 ) ;
}
static void F_250 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_515 ;
V_515 = F_17 ( V_16 , V_516 ) ;
V_515 |= V_517 ;
V_515 &= ~ V_518 ;
F_51 ( V_16 , V_516 , V_515 ) ;
}
static void F_251 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_515 ;
int V_28 , V_29 ;
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_515 = F_17 ( V_16 , V_516 ) ;
V_515 &= ~ V_519 ;
F_51 ( V_16 , V_516 , V_515 ) ;
break;
case V_91 :
case V_92 :
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ ) {
V_29 = V_2 -> V_47 [ V_28 ] -> V_124 ;
V_515 = F_17 ( V_16 , F_22 ( V_29 ) ) ;
V_515 &= ~ V_520 ;
F_51 ( V_16 , F_22 ( V_29 ) , V_515 ) ;
}
break;
default:
break;
}
}
static void F_252 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_515 ;
int V_28 , V_29 ;
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_515 = F_17 ( V_16 , V_516 ) ;
V_515 |= V_519 ;
F_51 ( V_16 , V_516 , V_515 ) ;
break;
case V_91 :
case V_92 :
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ ) {
V_29 = V_2 -> V_47 [ V_28 ] -> V_124 ;
V_515 = F_17 ( V_16 , F_22 ( V_29 ) ) ;
V_515 |= V_520 ;
F_51 ( V_16 , F_22 ( V_29 ) , V_515 ) ;
}
break;
default:
break;
}
}
static void F_253 ( struct V_1 * V_2 )
{
T_2 V_247 ;
F_247 ( V_2 -> V_35 , F_128 ( V_225 ) , 0 ) ;
F_254 (vid, adapter->active_vlans, VLAN_N_VID)
F_247 ( V_2 -> V_35 , F_128 ( V_225 ) , V_247 ) ;
}
static int F_255 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
unsigned int V_521 = V_16 -> V_88 . V_522 - 1 ;
int V_68 = 0 ;
if ( V_2 -> V_117 & V_403 )
V_521 = V_523 - 1 ;
if ( F_256 ( V_35 ) > V_521 )
return - V_524 ;
if ( ! F_257 ( V_35 ) ) {
struct V_525 * V_526 ;
if ( ! V_16 -> V_88 . V_330 . V_527 )
return - V_524 ;
F_258 (ha, netdev) {
if ( ! V_521 )
break;
V_16 -> V_88 . V_330 . V_527 ( V_16 , V_521 -- , V_526 -> V_528 ,
F_237 ( 0 ) , V_529 ) ;
V_68 ++ ;
}
}
for (; V_521 > 0 ; V_521 -- )
V_16 -> V_88 . V_330 . V_530 ( V_16 , V_521 ) ;
return V_68 ;
}
void F_259 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_531 , V_532 = V_533 | V_534 ;
int V_68 ;
V_531 = F_17 ( V_16 , V_535 ) ;
V_531 &= ~ V_536 ;
V_531 |= V_537 ;
V_531 |= V_538 ;
V_531 |= V_539 ;
V_531 &= ~ ( V_540 | V_541 ) ;
if ( V_35 -> V_117 & V_542 ) {
V_16 -> V_543 . V_544 = true ;
V_531 |= ( V_540 | V_541 ) ;
V_532 |= ( V_545 | V_546 ) ;
F_249 ( V_2 ) ;
} else {
if ( V_35 -> V_117 & V_547 ) {
V_531 |= V_541 ;
V_532 |= V_546 ;
} else {
V_16 -> V_88 . V_330 . V_548 ( V_16 , V_35 ) ;
V_532 |= V_549 ;
}
F_250 ( V_2 ) ;
V_16 -> V_543 . V_544 = false ;
}
V_68 = F_255 ( V_35 ) ;
if ( V_68 < 0 ) {
V_531 |= V_540 ;
V_532 |= V_545 ;
}
if ( V_2 -> V_296 )
F_260 ( V_2 ) ;
if ( V_16 -> V_88 . type != V_89 ) {
V_532 |= F_17 ( V_16 , F_261 ( F_237 ( 0 ) ) ) &
~ ( V_546 | V_549 |
V_545 ) ;
F_51 ( V_16 , F_261 ( F_237 ( 0 ) ) , V_532 ) ;
}
if ( V_2 -> V_35 -> V_173 & V_268 ) {
V_531 |= ( V_536 |
V_537 |
V_539 ) ;
V_531 &= ~ ( V_538 ) ;
}
F_51 ( V_16 , V_535 , V_531 ) ;
if ( V_35 -> V_173 & V_245 )
F_252 ( V_2 ) ;
else
F_251 ( V_2 ) ;
}
static void F_262 ( struct V_1 * V_2 )
{
int V_550 ;
for ( V_550 = 0 ; V_550 < V_2 -> V_166 ; V_550 ++ )
F_263 ( & V_2 -> V_135 [ V_550 ] -> V_249 ) ;
}
static void F_264 ( struct V_1 * V_2 )
{
int V_550 ;
for ( V_550 = 0 ; V_550 < V_2 -> V_166 ; V_550 ++ )
F_265 ( & V_2 -> V_135 [ V_550 ] -> V_249 ) ;
}
static void F_266 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_486 = V_2 -> V_35 -> V_290 + V_223 + V_487 ;
if ( ! ( V_2 -> V_117 & V_118 ) ) {
if ( V_16 -> V_88 . type == V_89 )
F_267 ( V_2 -> V_35 , 65536 ) ;
return;
}
if ( V_16 -> V_88 . type == V_89 )
F_267 ( V_2 -> V_35 , 32768 ) ;
#ifdef F_129
if ( V_2 -> V_35 -> V_173 & V_551 )
V_486 = F_179 ( V_486 , V_491 ) ;
#endif
if ( V_2 -> V_552 & V_553 ) {
F_268 ( V_16 , & V_2 -> V_114 , V_486 ,
V_554 ) ;
F_268 ( V_16 , & V_2 -> V_114 , V_486 ,
V_555 ) ;
F_269 ( V_16 , & V_2 -> V_114 ) ;
} else if ( V_2 -> V_556 && V_2 -> V_116 ) {
F_270 ( & V_2 -> V_16 ,
V_2 -> V_556 ,
V_486 ) ;
F_271 ( & V_2 -> V_16 ,
V_2 -> V_116 -> V_113 ,
V_2 -> V_556 -> V_557 ) ;
}
if ( V_16 -> V_88 . type != V_89 ) {
T_1 V_558 = 0 ;
T_2 V_430 = V_2 -> V_408 [ V_409 ] . V_410 - 1 ;
while ( V_430 ) {
V_558 ++ ;
V_430 >>= 1 ;
}
F_51 ( V_16 , V_559 , V_558 * 0x11111111 ) ;
}
}
static int F_272 ( struct V_1 * V_2 , int V_560 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_34 * V_53 = V_2 -> V_35 ;
int V_363 , V_112 , V_561 , V_562 ;
T_1 V_563 , V_564 ;
V_112 = V_363 = V_53 -> V_290 + V_223 + V_487 + V_565 ;
#ifdef F_129
if ( ( V_53 -> V_173 & V_551 ) &&
( V_112 < V_491 ) &&
( V_560 == F_273 ( V_2 ) ) )
V_112 = V_491 ;
#endif
switch ( V_16 -> V_88 . type ) {
case V_92 :
V_563 = F_274 ( V_363 , V_112 ) ;
break;
default:
V_563 = F_275 ( V_363 , V_112 ) ;
break;
}
if ( V_2 -> V_117 & V_403 )
V_563 += F_276 ( V_112 ) ;
V_561 = F_277 ( V_563 ) ;
V_564 = F_17 ( V_16 , F_278 ( V_560 ) ) >> 10 ;
V_562 = V_564 - V_561 ;
if ( V_562 < 0 ) {
F_73 ( V_133 , L_77
L_78
L_79 , V_560 ) ;
V_562 = V_112 + 1 ;
}
return V_562 ;
}
static int F_279 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_34 * V_53 = V_2 -> V_35 ;
int V_112 ;
T_1 V_563 ;
V_112 = V_53 -> V_290 + V_223 + V_487 ;
switch ( V_16 -> V_88 . type ) {
case V_92 :
V_563 = F_280 ( V_112 ) ;
break;
default:
V_563 = F_281 ( V_112 ) ;
break;
}
return F_277 ( V_563 ) ;
}
static void F_282 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_566 = F_221 ( V_2 -> V_35 ) ;
int V_28 ;
if ( ! V_566 )
V_566 = 1 ;
V_16 -> V_103 . V_567 = F_279 ( V_2 ) ;
for ( V_28 = 0 ; V_28 < V_566 ; V_28 ++ ) {
V_16 -> V_103 . V_568 [ V_28 ] = F_272 ( V_2 , V_28 ) ;
if ( V_16 -> V_103 . V_567 > V_16 -> V_103 . V_568 [ V_28 ] )
V_16 -> V_103 . V_567 = 0 ;
}
}
static void F_283 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_569 ;
T_6 V_112 = F_221 ( V_2 -> V_35 ) ;
if ( V_2 -> V_117 & V_357 ||
V_2 -> V_117 & V_570 )
V_569 = 32 << V_2 -> V_571 ;
else
V_569 = 0 ;
V_16 -> V_88 . V_330 . V_572 ( V_16 , V_112 , V_569 , V_573 ) ;
F_282 ( V_2 ) ;
}
static void F_284 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_574 * V_575 ;
struct V_576 * V_577 ;
F_285 ( & V_2 -> V_578 ) ;
if ( ! F_286 ( & V_2 -> V_579 ) )
F_287 ( V_16 , & V_2 -> V_580 ) ;
F_288 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_289 ( V_16 ,
& V_577 -> V_577 ,
V_577 -> V_581 ,
( V_577 -> V_582 == V_583 ) ?
V_583 :
V_2 -> V_47 [ V_577 -> V_582 ] -> V_124 ) ;
}
F_290 ( & V_2 -> V_578 ) ;
}
static void F_291 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
F_283 ( V_2 ) ;
#ifdef F_292
F_266 ( V_2 ) ;
#endif
F_238 ( V_2 ) ;
F_259 ( V_2 -> V_35 ) ;
F_253 ( V_2 ) ;
switch ( V_16 -> V_88 . type ) {
case V_91 :
case V_92 :
V_16 -> V_88 . V_330 . V_584 ( V_16 ) ;
break;
default:
break;
}
if ( V_2 -> V_117 & V_357 ) {
F_293 ( & V_2 -> V_16 ,
V_2 -> V_571 ) ;
} else if ( V_2 -> V_117 & V_570 ) {
F_294 ( & V_2 -> V_16 ,
V_2 -> V_571 ) ;
F_284 ( V_2 ) ;
}
switch ( V_16 -> V_88 . type ) {
case V_91 :
case V_92 :
V_16 -> V_88 . V_330 . V_585 ( V_16 ) ;
break;
default:
break;
}
#ifdef F_129
F_295 ( V_2 ) ;
#endif
F_222 ( V_2 ) ;
F_246 ( V_2 ) ;
}
static inline bool F_296 ( struct V_15 * V_16 )
{
switch ( V_16 -> V_333 . type ) {
case V_586 :
case V_587 :
case V_588 :
case V_589 :
case V_590 :
case V_591 :
case V_592 :
case V_593 :
return true ;
case V_594 :
if ( V_16 -> V_88 . type == V_89 )
return true ;
default:
return false ;
}
}
static void F_297 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 . V_88 . type == V_89 )
V_2 -> V_131 |= V_595 ;
V_2 -> V_131 |= V_341 ;
}
static int F_298 ( struct V_15 * V_16 )
{
T_1 V_21 ;
bool V_596 , V_332 = false ;
T_1 V_130 = V_597 ;
if ( V_16 -> V_88 . V_330 . V_331 )
V_130 = V_16 -> V_88 . V_330 . V_331 ( V_16 , & V_21 , & V_332 , false ) ;
if ( V_130 )
goto V_598;
V_21 = V_16 -> V_333 . V_599 ;
if ( ( ! V_21 ) && ( V_16 -> V_88 . V_330 . V_600 ) )
V_130 = V_16 -> V_88 . V_330 . V_600 ( V_16 , & V_21 ,
& V_596 ) ;
if ( V_130 )
goto V_598;
if ( V_16 -> V_88 . V_330 . V_601 )
V_130 = V_16 -> V_88 . V_330 . V_601 ( V_16 , V_21 , V_332 ) ;
V_598:
return V_130 ;
}
static void F_299 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_602 = 0 ;
if ( V_2 -> V_117 & V_382 ) {
V_602 = V_603 | V_604 |
V_605 ;
V_602 |= V_606 ;
switch ( V_16 -> V_88 . type ) {
case V_89 :
F_51 ( V_16 , V_607 , V_608 ) ;
break;
case V_91 :
case V_92 :
default:
F_51 ( V_16 , F_300 ( 0 ) , 0xFFFFFFFF ) ;
F_51 ( V_16 , F_300 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_51 ( V_16 , V_607 , V_608 ) ;
}
if ( V_2 -> V_117 & V_403 ) {
V_602 &= ~ V_609 ;
switch ( V_2 -> V_408 [ V_476 ] . V_95 ) {
case V_477 :
V_602 |= V_610 ;
break;
case V_479 :
V_602 |= V_611 ;
break;
default:
V_602 |= V_612 ;
break;
}
}
if ( V_2 -> V_131 & V_324 ) {
switch ( V_2 -> V_16 . V_88 . type ) {
case V_91 :
V_602 |= V_613 ;
break;
case V_92 :
V_602 |= V_352 ;
break;
default:
break;
}
}
if ( V_2 -> V_117 & V_336 )
V_602 |= V_614 ;
if ( V_16 -> V_88 . type == V_91 ) {
V_602 |= V_614 ;
V_602 |= V_615 ;
}
F_51 ( V_16 , V_616 , V_602 ) ;
}
static void F_301 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_18 ;
T_1 V_80 ;
F_52 ( V_2 ) ;
F_299 ( V_2 ) ;
if ( V_2 -> V_117 & V_382 )
F_174 ( V_2 ) ;
else
F_213 ( V_2 ) ;
if ( V_16 -> V_88 . V_330 . V_617 )
V_16 -> V_88 . V_330 . V_617 ( V_16 ) ;
F_14 ( V_22 , & V_2 -> V_23 ) ;
F_262 ( V_2 ) ;
if ( F_296 ( V_16 ) ) {
F_297 ( V_2 ) ;
} else {
V_18 = F_298 ( V_16 ) ;
if ( V_18 )
F_83 ( V_149 , L_80 , V_18 ) ;
}
F_17 ( V_16 , V_338 ) ;
F_191 ( V_2 , true , true ) ;
if ( V_2 -> V_117 & V_336 ) {
T_1 V_618 = F_17 ( V_16 , V_619 ) ;
if ( V_618 & V_620 )
F_181 ( V_133 , L_60 ) ;
}
F_302 ( V_2 -> V_35 ) ;
V_2 -> V_117 |= V_344 ;
V_2 -> V_345 = V_148 ;
F_303 ( & V_2 -> V_621 , V_148 ) ;
V_80 = F_17 ( V_16 , V_81 ) ;
V_80 |= V_622 ;
F_51 ( V_16 , V_81 , V_80 ) ;
}
void F_304 ( struct V_1 * V_2 )
{
F_305 ( F_306 () ) ;
V_2 -> V_35 -> V_54 = V_148 ;
while ( F_9 ( V_623 , & V_2 -> V_23 ) )
F_219 ( 1000 , 2000 ) ;
F_307 ( V_2 ) ;
if ( V_2 -> V_117 & V_403 )
F_308 ( 2000 ) ;
F_309 ( V_2 ) ;
F_14 ( V_623 , & V_2 -> V_23 ) ;
}
void F_309 ( struct V_1 * V_2 )
{
F_291 ( V_2 ) ;
F_301 ( V_2 ) ;
}
void F_310 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_18 ;
while ( F_9 ( V_624 , & V_2 -> V_23 ) )
F_219 ( 1000 , 2000 ) ;
V_2 -> V_131 &= ~ ( V_595 |
V_341 ) ;
V_2 -> V_117 &= ~ V_342 ;
V_18 = V_16 -> V_88 . V_330 . V_625 ( V_16 ) ;
switch ( V_18 ) {
case 0 :
case V_626 :
case V_627 :
break;
case V_628 :
F_311 ( L_81 ) ;
break;
case V_629 :
F_312 ( L_82
L_83
L_84
L_85
L_86
L_87 ) ;
break;
default:
F_311 ( L_88 , V_18 ) ;
}
F_14 ( V_624 , & V_2 -> V_23 ) ;
V_16 -> V_88 . V_330 . V_527 ( V_16 , 0 , V_16 -> V_88 . V_528 , F_237 ( 0 ) , V_529 ) ;
if ( V_16 -> V_88 . V_630 )
V_16 -> V_88 . V_330 . V_631 ( V_16 , F_237 ( 0 ) ) ;
if ( V_2 -> V_131 & V_632 )
F_313 ( V_2 ) ;
}
static void F_314 ( struct V_37 * V_47 )
{
struct V_167 * V_53 = V_47 -> V_53 ;
unsigned long V_274 ;
T_2 V_28 ;
if ( ! V_47 -> V_51 )
return;
for ( V_28 = 0 ; V_28 < V_47 -> V_68 ; V_28 ++ ) {
struct V_50 * V_273 ;
V_273 = & V_47 -> V_51 [ V_28 ] ;
if ( V_273 -> V_69 ) {
struct V_172 * V_69 = V_273 -> V_69 ;
if ( F_134 ( V_69 ) -> V_266 ) {
F_60 ( V_53 ,
F_134 ( V_69 ) -> V_61 ,
F_49 ( V_47 ) ,
V_204 ) ;
F_134 ( V_69 ) -> V_266 = false ;
}
F_315 ( V_69 ) ;
}
V_273 -> V_69 = NULL ;
if ( V_273 -> V_61 )
F_60 ( V_53 , V_273 -> V_61 ,
F_121 ( V_47 ) ,
V_204 ) ;
V_273 -> V_61 = 0 ;
if ( V_273 -> V_78 )
F_123 ( V_273 -> V_78 ,
F_119 ( V_47 ) ) ;
V_273 -> V_78 = NULL ;
}
V_274 = sizeof( struct V_50 ) * V_47 -> V_68 ;
memset ( V_47 -> V_51 , 0 , V_274 ) ;
memset ( V_47 -> V_67 , 0 , V_47 -> V_274 ) ;
V_47 -> V_198 = 0 ;
V_47 -> V_59 = 0 ;
V_47 -> V_60 = 0 ;
}
static void F_316 ( struct V_37 * V_38 )
{
struct V_39 * V_58 ;
unsigned long V_274 ;
T_2 V_28 ;
if ( ! V_38 -> V_58 )
return;
for ( V_28 = 0 ; V_28 < V_38 -> V_68 ; V_28 ++ ) {
V_58 = & V_38 -> V_58 [ V_28 ] ;
F_57 ( V_38 , V_58 ) ;
}
F_317 ( F_87 ( V_38 ) ) ;
V_274 = sizeof( struct V_39 ) * V_38 -> V_68 ;
memset ( V_38 -> V_58 , 0 , V_274 ) ;
memset ( V_38 -> V_67 , 0 , V_38 -> V_274 ) ;
V_38 -> V_60 = 0 ;
V_38 -> V_59 = 0 ;
}
static void F_318 ( struct V_1 * V_2 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ )
F_314 ( V_2 -> V_47 [ V_28 ] ) ;
}
static void F_319 ( struct V_1 * V_2 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ )
F_316 ( V_2 -> V_38 [ V_28 ] ) ;
}
static void F_320 ( struct V_1 * V_2 )
{
struct V_574 * V_575 ;
struct V_576 * V_577 ;
F_285 ( & V_2 -> V_578 ) ;
F_288 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_321 ( & V_577 -> V_633 ) ;
F_207 ( V_577 ) ;
}
V_2 -> V_634 = 0 ;
F_290 ( & V_2 -> V_578 ) ;
}
void F_307 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_159 ;
int V_28 ;
F_217 ( V_22 , & V_2 -> V_23 ) ;
V_159 = F_17 ( V_16 , V_508 ) ;
F_51 ( V_16 , V_508 , V_159 & ~ V_509 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ )
F_232 ( V_2 , V_2 -> V_47 [ V_28 ] ) ;
F_219 ( 10000 , 20000 ) ;
F_322 ( V_35 ) ;
F_323 ( V_35 ) ;
F_324 ( V_35 ) ;
F_211 ( V_2 ) ;
F_264 ( V_2 ) ;
V_2 -> V_131 &= ~ ( V_358 |
V_132 ) ;
V_2 -> V_117 &= ~ V_344 ;
F_325 ( & V_2 -> V_621 ) ;
if ( V_2 -> V_296 ) {
F_51 ( & V_2 -> V_16 , V_298 , 0 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_296 ; V_28 ++ )
V_2 -> V_484 [ V_28 ] . V_635 = false ;
F_326 ( V_2 ) ;
F_327 ( V_2 ) ;
}
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ ) {
T_6 V_124 = V_2 -> V_38 [ V_28 ] -> V_124 ;
F_51 ( V_16 , F_30 ( V_124 ) , V_636 ) ;
}
switch ( V_16 -> V_88 . type ) {
case V_91 :
case V_92 :
F_51 ( V_16 , V_419 ,
( F_17 ( V_16 , V_419 ) &
~ V_420 ) ) ;
break;
default:
break;
}
if ( ! F_328 ( V_2 -> V_10 ) )
F_310 ( V_2 ) ;
if ( V_16 -> V_88 . V_330 . V_637 )
V_16 -> V_88 . V_330 . V_637 ( V_16 ) ;
F_319 ( V_2 ) ;
F_318 ( V_2 ) ;
#ifdef F_200
F_103 ( V_2 ) ;
#endif
}
static void F_329 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
F_72 ( V_2 ) ;
}
static int F_330 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_6 * V_10 = V_2 -> V_10 ;
unsigned int V_178 , V_638 ;
T_1 V_639 ;
#ifdef F_292
int V_29 ;
struct V_640 * V_112 ;
#endif
V_16 -> V_641 = V_10 -> V_642 ;
V_16 -> V_326 = V_10 -> V_167 ;
V_16 -> V_643 = V_10 -> V_644 ;
V_16 -> V_645 = V_10 -> V_646 ;
V_16 -> V_647 = V_10 -> V_648 ;
V_178 = F_331 ( int , V_649 , F_332 () ) ;
V_2 -> V_408 [ V_409 ] . V_650 = V_178 ;
V_2 -> V_131 |= V_651 ;
V_2 -> V_131 |= V_498 ;
V_2 -> V_652 = V_653 ;
V_2 -> V_393 = 20 ;
V_638 = F_331 ( int , V_654 , F_332 () ) ;
V_2 -> V_408 [ V_655 ] . V_650 = V_638 ;
V_2 -> V_571 = V_656 ;
#ifdef F_200
V_2 -> V_117 |= V_169 ;
#endif
#ifdef F_129
V_2 -> V_117 |= V_657 ;
V_2 -> V_117 &= ~ V_490 ;
#ifdef F_292
V_2 -> V_658 . V_659 = V_660 ;
#endif
#endif
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_2 -> V_131 &= ~ V_651 ;
V_2 -> V_131 &= ~ V_498 ;
if ( V_16 -> V_326 == V_661 )
V_2 -> V_117 |= V_336 ;
V_2 -> V_652 = V_662 ;
V_2 -> V_408 [ V_655 ] . V_650 = 0 ;
V_2 -> V_393 = 0 ;
V_2 -> V_571 = 0 ;
#ifdef F_129
V_2 -> V_117 &= ~ V_657 ;
V_2 -> V_117 &= ~ V_490 ;
#ifdef F_292
V_2 -> V_658 . V_659 = 0 ;
#endif
#endif
break;
case V_91 :
if ( V_16 -> V_326 == V_327 )
V_2 -> V_131 |= V_324 ;
break;
case V_92 :
V_639 = F_17 ( V_16 , V_663 ) ;
if ( V_639 & V_664 )
V_2 -> V_131 |= V_324 ;
break;
default:
break;
}
#ifdef F_129
F_333 ( & V_2 -> V_658 . V_665 ) ;
#endif
F_333 ( & V_2 -> V_578 ) ;
#ifdef F_292
switch ( V_16 -> V_88 . type ) {
case V_92 :
V_2 -> V_114 . V_666 . V_667 = V_668 ;
V_2 -> V_114 . V_666 . V_669 = V_668 ;
break;
default:
V_2 -> V_114 . V_666 . V_667 = V_670 ;
V_2 -> V_114 . V_666 . V_669 = V_670 ;
break;
}
for ( V_29 = 0 ; V_29 < V_670 ; V_29 ++ ) {
V_112 = & V_2 -> V_114 . V_671 [ V_29 ] ;
V_112 -> V_672 [ V_554 ] . V_673 = 0 ;
V_112 -> V_672 [ V_554 ] . V_674 = 12 + ( V_29 & 1 ) ;
V_112 -> V_672 [ V_555 ] . V_673 = 0 ;
V_112 -> V_672 [ V_555 ] . V_674 = 12 + ( V_29 & 1 ) ;
V_112 -> V_675 = V_676 ;
}
V_112 = & V_2 -> V_114 . V_671 [ 0 ] ;
V_112 -> V_672 [ V_554 ] . V_677 = 0xFF ;
V_112 -> V_672 [ V_555 ] . V_677 = 0xFF ;
V_2 -> V_114 . V_678 [ V_554 ] [ 0 ] = 100 ;
V_2 -> V_114 . V_678 [ V_555 ] [ 0 ] = 100 ;
V_2 -> V_114 . V_115 = false ;
V_2 -> V_679 = 0x00 ;
V_2 -> V_552 = V_680 | V_553 ;
memcpy ( & V_2 -> V_681 , & V_2 -> V_114 ,
sizeof( V_2 -> V_681 ) ) ;
#endif
V_16 -> V_103 . V_682 = V_105 ;
V_16 -> V_103 . V_104 = V_105 ;
F_282 ( V_2 ) ;
V_16 -> V_103 . V_683 = V_684 ;
V_16 -> V_103 . V_685 = true ;
V_16 -> V_103 . V_686 =
( F_334 ( V_16 ) == 0 ) ? false : true ;
#ifdef F_335
if ( V_16 -> V_88 . type != V_89 )
V_2 -> V_296 = ( V_687 > 63 ) ? 0 : V_687 ;
#endif
V_2 -> V_373 = 1 ;
V_2 -> V_688 = 1 ;
V_2 -> V_689 = V_690 ;
V_2 -> V_691 = V_692 ;
V_2 -> V_693 = V_694 ;
if ( F_336 ( V_16 ) ) {
F_311 ( L_89 ) ;
return - V_695 ;
}
F_217 ( V_22 , & V_2 -> V_23 ) ;
return 0 ;
}
int F_337 ( struct V_37 * V_38 )
{
struct V_167 * V_53 = V_38 -> V_53 ;
int V_696 = F_338 ( V_53 ) ;
int V_697 = - 1 ;
int V_274 ;
V_274 = sizeof( struct V_39 ) * V_38 -> V_68 ;
if ( V_38 -> V_135 )
V_697 = V_38 -> V_135 -> V_697 ;
V_38 -> V_58 = F_339 ( V_274 , V_697 ) ;
if ( ! V_38 -> V_58 )
V_38 -> V_58 = F_340 ( V_274 ) ;
if ( ! V_38 -> V_58 )
goto V_18;
V_38 -> V_274 = V_38 -> V_68 * sizeof( union V_41 ) ;
V_38 -> V_274 = F_150 ( V_38 -> V_274 , 4096 ) ;
F_341 ( V_53 , V_697 ) ;
V_38 -> V_67 = F_342 ( V_53 ,
V_38 -> V_274 ,
& V_38 -> V_61 ,
V_698 ) ;
F_341 ( V_53 , V_696 ) ;
if ( ! V_38 -> V_67 )
V_38 -> V_67 = F_342 ( V_53 , V_38 -> V_274 ,
& V_38 -> V_61 , V_698 ) ;
if ( ! V_38 -> V_67 )
goto V_18;
V_38 -> V_60 = 0 ;
V_38 -> V_59 = 0 ;
return 0 ;
V_18:
F_343 ( V_38 -> V_58 ) ;
V_38 -> V_58 = NULL ;
F_344 ( V_53 , L_90 ) ;
return - V_524 ;
}
static int F_345 ( struct V_1 * V_2 )
{
int V_28 , V_18 = 0 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ ) {
V_18 = F_337 ( V_2 -> V_38 [ V_28 ] ) ;
if ( ! V_18 )
continue;
F_83 ( V_149 , L_91 , V_28 ) ;
goto V_699;
}
return 0 ;
V_699:
while ( V_28 -- )
F_346 ( V_2 -> V_38 [ V_28 ] ) ;
return V_18 ;
}
int F_347 ( struct V_37 * V_47 )
{
struct V_167 * V_53 = V_47 -> V_53 ;
int V_696 = F_338 ( V_53 ) ;
int V_697 = - 1 ;
int V_274 ;
V_274 = sizeof( struct V_50 ) * V_47 -> V_68 ;
if ( V_47 -> V_135 )
V_697 = V_47 -> V_135 -> V_697 ;
V_47 -> V_51 = F_339 ( V_274 , V_697 ) ;
if ( ! V_47 -> V_51 )
V_47 -> V_51 = F_340 ( V_274 ) ;
if ( ! V_47 -> V_51 )
goto V_18;
V_47 -> V_274 = V_47 -> V_68 * sizeof( union V_48 ) ;
V_47 -> V_274 = F_150 ( V_47 -> V_274 , 4096 ) ;
F_341 ( V_53 , V_697 ) ;
V_47 -> V_67 = F_342 ( V_53 ,
V_47 -> V_274 ,
& V_47 -> V_61 ,
V_698 ) ;
F_341 ( V_53 , V_696 ) ;
if ( ! V_47 -> V_67 )
V_47 -> V_67 = F_342 ( V_53 , V_47 -> V_274 ,
& V_47 -> V_61 , V_698 ) ;
if ( ! V_47 -> V_67 )
goto V_18;
V_47 -> V_59 = 0 ;
V_47 -> V_60 = 0 ;
return 0 ;
V_18:
F_343 ( V_47 -> V_51 ) ;
V_47 -> V_51 = NULL ;
F_344 ( V_53 , L_92 ) ;
return - V_524 ;
}
static int F_348 ( struct V_1 * V_2 )
{
int V_28 , V_18 = 0 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ ) {
V_18 = F_347 ( V_2 -> V_47 [ V_28 ] ) ;
if ( ! V_18 )
continue;
F_83 ( V_149 , L_93 , V_28 ) ;
goto V_700;
}
#ifdef F_129
V_18 = F_349 ( V_2 ) ;
if ( ! V_18 )
#endif
return 0 ;
V_700:
while ( V_28 -- )
F_350 ( V_2 -> V_47 [ V_28 ] ) ;
return V_18 ;
}
void F_346 ( struct V_37 * V_38 )
{
F_316 ( V_38 ) ;
F_343 ( V_38 -> V_58 ) ;
V_38 -> V_58 = NULL ;
if ( ! V_38 -> V_67 )
return;
F_351 ( V_38 -> V_53 , V_38 -> V_274 ,
V_38 -> V_67 , V_38 -> V_61 ) ;
V_38 -> V_67 = NULL ;
}
static void F_352 ( struct V_1 * V_2 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ )
if ( V_2 -> V_38 [ V_28 ] -> V_67 )
F_346 ( V_2 -> V_38 [ V_28 ] ) ;
}
void F_350 ( struct V_37 * V_47 )
{
F_314 ( V_47 ) ;
F_343 ( V_47 -> V_51 ) ;
V_47 -> V_51 = NULL ;
if ( ! V_47 -> V_67 )
return;
F_351 ( V_47 -> V_53 , V_47 -> V_274 ,
V_47 -> V_67 , V_47 -> V_61 ) ;
V_47 -> V_67 = NULL ;
}
static void F_353 ( struct V_1 * V_2 )
{
int V_28 ;
#ifdef F_129
F_354 ( V_2 ) ;
#endif
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ )
if ( V_2 -> V_47 [ V_28 ] -> V_67 )
F_350 ( V_2 -> V_47 [ V_28 ] ) ;
}
static int F_355 ( struct V_34 * V_35 , int V_701 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
int V_486 = V_701 + V_223 + V_487 ;
if ( ( V_701 < 68 ) || ( V_486 > V_702 ) )
return - V_703 ;
if ( ( V_2 -> V_117 & V_403 ) &&
( V_2 -> V_16 . V_88 . type == V_91 ) &&
( V_486 > ( V_492 + V_487 ) ) )
F_73 ( V_149 , L_94 ) ;
F_85 ( V_149 , L_95 , V_35 -> V_290 , V_701 ) ;
V_35 -> V_290 = V_701 ;
if ( F_37 ( V_35 ) )
F_304 ( V_2 ) ;
return 0 ;
}
static int F_356 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
int V_18 ;
if ( F_8 ( V_704 , & V_2 -> V_23 ) )
return - V_705 ;
F_323 ( V_35 ) ;
V_18 = F_345 ( V_2 ) ;
if ( V_18 )
goto V_699;
V_18 = F_348 ( V_2 ) ;
if ( V_18 )
goto V_700;
F_291 ( V_2 ) ;
V_18 = F_209 ( V_2 ) ;
if ( V_18 )
goto V_706;
V_18 = F_357 ( V_35 ,
V_2 -> V_463 > 1 ? 1 :
V_2 -> V_57 ) ;
if ( V_18 )
goto V_707;
V_18 = F_358 ( V_35 ,
V_2 -> V_463 > 1 ? 1 :
V_2 -> V_73 ) ;
if ( V_18 )
goto V_707;
F_359 ( V_2 ) ;
F_301 ( V_2 ) ;
return 0 ;
V_707:
F_210 ( V_2 ) ;
V_706:
F_353 ( V_2 ) ;
V_700:
F_352 ( V_2 ) ;
V_699:
F_310 ( V_2 ) ;
return V_18 ;
}
static int F_360 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
F_361 ( V_2 ) ;
F_307 ( V_2 ) ;
F_210 ( V_2 ) ;
F_320 ( V_2 ) ;
F_352 ( V_2 ) ;
F_353 ( V_2 ) ;
F_50 ( V_2 ) ;
return 0 ;
}
static int F_362 ( struct V_6 * V_10 )
{
struct V_1 * V_2 = F_363 ( V_10 ) ;
struct V_34 * V_35 = V_2 -> V_35 ;
T_1 V_18 ;
F_364 ( V_10 , V_708 ) ;
F_365 ( V_10 ) ;
F_366 ( V_10 ) ;
V_18 = F_367 ( V_10 ) ;
if ( V_18 ) {
F_311 ( L_96 ) ;
return V_18 ;
}
F_368 ( V_10 ) ;
F_369 ( V_10 , false ) ;
F_310 ( V_2 ) ;
F_51 ( & V_2 -> V_16 , V_709 , ~ 0 ) ;
F_370 () ;
V_18 = F_371 ( V_2 ) ;
if ( ! V_18 && F_37 ( V_35 ) )
V_18 = F_356 ( V_35 ) ;
F_372 () ;
if ( V_18 )
return V_18 ;
F_373 ( V_35 ) ;
return 0 ;
}
static int F_374 ( struct V_6 * V_10 , bool * V_710 )
{
struct V_1 * V_2 = F_363 ( V_10 ) ;
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_711 , V_531 ;
T_1 V_712 = V_2 -> V_713 ;
#ifdef F_375
int V_714 = 0 ;
#endif
F_376 ( V_35 ) ;
F_370 () ;
if ( F_37 ( V_35 ) ) {
F_307 ( V_2 ) ;
F_210 ( V_2 ) ;
F_352 ( V_2 ) ;
F_353 ( V_2 ) ;
}
F_372 () ;
F_377 ( V_2 ) ;
#ifdef F_375
V_714 = F_366 ( V_10 ) ;
if ( V_714 )
return V_714 ;
#endif
if ( V_712 ) {
F_259 ( V_35 ) ;
if ( V_16 -> V_88 . V_330 . V_617 )
V_16 -> V_88 . V_330 . V_617 ( V_16 ) ;
if ( V_712 & V_715 ) {
V_531 = F_17 ( V_16 , V_535 ) ;
V_531 |= V_541 ;
F_51 ( V_16 , V_535 , V_531 ) ;
}
V_711 = F_17 ( V_16 , V_716 ) ;
V_711 |= V_717 ;
F_51 ( V_16 , V_716 , V_711 ) ;
F_51 ( V_16 , V_718 , V_712 ) ;
} else {
F_51 ( V_16 , V_719 , 0 ) ;
F_51 ( V_16 , V_718 , 0 ) ;
}
switch ( V_16 -> V_88 . type ) {
case V_89 :
F_369 ( V_10 , false ) ;
break;
case V_91 :
case V_92 :
F_369 ( V_10 , ! ! V_712 ) ;
break;
default:
break;
}
* V_710 = ! ! V_712 ;
F_50 ( V_2 ) ;
F_378 ( V_10 ) ;
return 0 ;
}
static int F_379 ( struct V_6 * V_10 , T_12 V_23 )
{
int V_714 ;
bool V_720 ;
V_714 = F_374 ( V_10 , & V_720 ) ;
if ( V_714 )
return V_714 ;
if ( V_720 ) {
F_380 ( V_10 ) ;
} else {
F_369 ( V_10 , false ) ;
F_364 ( V_10 , V_721 ) ;
}
return 0 ;
}
static void F_381 ( struct V_6 * V_10 )
{
bool V_720 ;
F_374 ( V_10 , & V_720 ) ;
if ( V_722 == V_723 ) {
F_369 ( V_10 , V_720 ) ;
F_364 ( V_10 , V_721 ) ;
}
}
void F_382 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_100 * V_101 = & V_2 -> V_102 ;
T_4 V_724 = 0 ;
T_1 V_28 , V_725 = 0 , V_726 , V_727 , V_728 , V_729 , V_730 ;
T_4 V_258 = 0 , V_151 = 0 , V_731 = 0 ;
T_4 V_203 = 0 , V_283 = 0 ;
T_4 V_147 = 0 , V_122 = 0 , V_732 = 0 ;
if ( F_8 ( V_22 , & V_2 -> V_23 ) ||
F_8 ( V_623 , & V_2 -> V_23 ) )
return;
if ( V_2 -> V_131 & V_498 ) {
T_4 V_243 = 0 ;
T_4 V_244 = 0 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ ) {
V_243 += V_2 -> V_47 [ V_28 ] -> V_189 . V_243 ;
V_244 += V_2 -> V_47 [ V_28 ] -> V_189 . V_244 ;
}
V_2 -> V_733 = V_243 ;
V_2 -> V_734 = V_244 ;
}
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ ) {
struct V_37 * V_47 = V_2 -> V_47 [ V_28 ] ;
V_258 += V_47 -> V_189 . V_258 ;
V_203 += V_47 -> V_189 . V_203 ;
V_283 += V_47 -> V_189 . V_283 ;
V_732 += V_47 -> V_189 . V_190 ;
V_147 += V_47 -> V_102 . V_147 ;
V_122 += V_47 -> V_102 . V_122 ;
}
V_2 -> V_258 = V_258 ;
V_2 -> V_203 = V_203 ;
V_2 -> V_283 = V_283 ;
V_2 -> V_732 = V_732 ;
V_35 -> V_102 . V_735 = V_147 ;
V_35 -> V_102 . V_736 = V_122 ;
V_147 = 0 ;
V_122 = 0 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ ) {
struct V_37 * V_38 = V_2 -> V_38 [ V_28 ] ;
V_151 += V_38 -> V_128 . V_151 ;
V_731 += V_38 -> V_128 . V_731 ;
V_147 += V_38 -> V_102 . V_147 ;
V_122 += V_38 -> V_102 . V_122 ;
}
V_2 -> V_151 = V_151 ;
V_2 -> V_731 = V_731 ;
V_35 -> V_102 . V_737 = V_147 ;
V_35 -> V_102 . V_738 = V_122 ;
V_101 -> V_739 += F_17 ( V_16 , V_740 ) ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ ) {
V_726 = F_17 ( V_16 , F_383 ( V_28 ) ) ;
V_725 += V_726 ;
V_101 -> V_726 [ V_28 ] += V_726 ;
V_724 += V_101 -> V_726 [ V_28 ] ;
V_101 -> V_741 [ V_28 ] += F_17 ( V_16 , F_384 ( V_28 ) ) ;
V_101 -> V_742 [ V_28 ] += F_17 ( V_16 , F_385 ( V_28 ) ) ;
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_101 -> V_743 [ V_28 ] += F_17 ( V_16 , F_386 ( V_28 ) ) ;
V_101 -> V_744 [ V_28 ] += F_17 ( V_16 , F_387 ( V_28 ) ) ;
V_101 -> V_745 [ V_28 ] += F_17 ( V_16 , F_388 ( V_28 ) ) ;
V_101 -> V_746 [ V_28 ] +=
F_17 ( V_16 , F_389 ( V_28 ) ) ;
break;
case V_91 :
case V_92 :
V_101 -> V_746 [ V_28 ] +=
F_17 ( V_16 , F_390 ( V_28 ) ) ;
break;
default:
break;
}
}
for ( V_28 = 0 ; V_28 < 16 ; V_28 ++ ) {
V_101 -> V_747 [ V_28 ] += F_17 ( V_16 , F_391 ( V_28 ) ) ;
V_101 -> V_748 [ V_28 ] += F_17 ( V_16 , F_392 ( V_28 ) ) ;
if ( ( V_16 -> V_88 . type == V_91 ) ||
( V_16 -> V_88 . type == V_92 ) ) {
V_101 -> V_744 [ V_28 ] += F_17 ( V_16 , F_393 ( V_28 ) ) ;
F_17 ( V_16 , F_394 ( V_28 ) ) ;
V_101 -> V_745 [ V_28 ] += F_17 ( V_16 , F_395 ( V_28 ) ) ;
F_17 ( V_16 , F_396 ( V_28 ) ) ;
}
}
V_101 -> V_749 += F_17 ( V_16 , V_750 ) ;
V_101 -> V_749 -= V_725 ;
F_63 ( V_2 ) ;
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_101 -> V_751 += F_17 ( V_16 , V_752 ) ;
V_101 -> V_753 += F_17 ( V_16 , V_754 ) ;
V_101 -> V_755 += F_17 ( V_16 , V_756 ) ;
V_101 -> V_757 += F_17 ( V_16 , V_758 ) ;
break;
case V_92 :
V_101 -> V_759 += F_17 ( V_16 , V_760 ) ;
V_101 -> V_761 += F_17 ( V_16 , V_762 ) ;
V_101 -> V_763 += F_17 ( V_16 , V_764 ) ;
V_101 -> V_765 += F_17 ( V_16 , V_766 ) ;
case V_91 :
for ( V_28 = 0 ; V_28 < 16 ; V_28 ++ )
V_2 -> V_767 +=
F_17 ( V_16 , F_397 ( V_28 ) ) ;
V_101 -> V_753 += F_17 ( V_16 , V_768 ) ;
F_17 ( V_16 , V_754 ) ;
V_101 -> V_755 += F_17 ( V_16 , V_769 ) ;
F_17 ( V_16 , V_756 ) ;
V_101 -> V_757 += F_17 ( V_16 , V_770 ) ;
F_17 ( V_16 , V_758 ) ;
V_101 -> V_751 += F_17 ( V_16 , V_771 ) ;
V_101 -> V_772 += F_17 ( V_16 , V_773 ) ;
V_101 -> V_774 += F_17 ( V_16 , V_775 ) ;
#ifdef F_129
V_101 -> V_776 += F_17 ( V_16 , V_777 ) ;
V_101 -> V_778 += F_17 ( V_16 , V_779 ) ;
V_101 -> V_780 += F_17 ( V_16 , V_781 ) ;
V_101 -> V_782 += F_17 ( V_16 , V_783 ) ;
V_101 -> V_784 += F_17 ( V_16 , V_785 ) ;
V_101 -> V_786 += F_17 ( V_16 , V_787 ) ;
if ( V_2 -> V_658 . V_788 ) {
struct V_789 * V_658 = & V_2 -> V_658 ;
struct V_790 * V_788 ;
unsigned int V_152 ;
T_4 V_791 = 0 , V_792 = 0 ;
F_398 (cpu) {
V_788 = F_399 ( V_658 -> V_788 , V_152 ) ;
V_791 += V_788 -> V_791 ;
V_792 += V_788 -> V_792 ;
}
V_101 -> V_793 = V_791 ;
V_101 -> V_794 = V_792 ;
}
#endif
break;
default:
break;
}
V_727 = F_17 ( V_16 , V_795 ) ;
V_101 -> V_727 += V_727 ;
V_101 -> V_796 += F_17 ( V_16 , V_797 ) ;
if ( V_16 -> V_88 . type == V_89 )
V_101 -> V_796 -= V_727 ;
V_101 -> V_798 += F_17 ( V_16 , V_799 ) ;
V_101 -> V_800 += F_17 ( V_16 , V_801 ) ;
V_101 -> V_802 += F_17 ( V_16 , V_803 ) ;
V_101 -> V_804 += F_17 ( V_16 , V_805 ) ;
V_101 -> V_806 += F_17 ( V_16 , V_807 ) ;
V_101 -> V_808 += F_17 ( V_16 , V_809 ) ;
V_101 -> V_810 += F_17 ( V_16 , V_811 ) ;
V_101 -> V_812 += F_17 ( V_16 , V_813 ) ;
V_728 = F_17 ( V_16 , V_814 ) ;
V_101 -> V_815 += V_728 ;
V_729 = F_17 ( V_16 , V_816 ) ;
V_101 -> V_817 += V_729 ;
V_101 -> V_818 += F_17 ( V_16 , V_819 ) ;
V_101 -> V_820 += F_17 ( V_16 , V_821 ) ;
V_730 = V_728 + V_729 ;
V_101 -> V_818 -= V_730 ;
V_101 -> V_820 -= V_730 ;
V_101 -> V_755 -= ( V_730 * ( V_822 + V_487 ) ) ;
V_101 -> V_823 += F_17 ( V_16 , V_824 ) ;
V_101 -> V_825 += F_17 ( V_16 , V_826 ) ;
V_101 -> V_827 += F_17 ( V_16 , V_828 ) ;
V_101 -> V_829 += F_17 ( V_16 , V_830 ) ;
V_101 -> V_831 += F_17 ( V_16 , V_832 ) ;
V_101 -> V_831 -= V_730 ;
V_101 -> V_833 += F_17 ( V_16 , V_834 ) ;
V_101 -> V_835 += F_17 ( V_16 , V_836 ) ;
V_101 -> V_837 += F_17 ( V_16 , V_838 ) ;
V_101 -> V_839 += F_17 ( V_16 , V_840 ) ;
V_101 -> V_841 += F_17 ( V_16 , V_842 ) ;
V_101 -> V_843 += F_17 ( V_16 , V_844 ) ;
V_35 -> V_102 . V_845 = V_101 -> V_796 ;
V_35 -> V_102 . V_846 = V_101 -> V_739 + V_101 -> V_812 ;
V_35 -> V_102 . V_847 = 0 ;
V_35 -> V_102 . V_848 = V_101 -> V_812 ;
V_35 -> V_102 . V_849 = V_101 -> V_739 ;
V_35 -> V_102 . V_850 = V_724 ;
}
static void F_400 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_28 ;
if ( ! ( V_2 -> V_131 & V_358 ) )
return;
V_2 -> V_131 &= ~ V_358 ;
if ( F_8 ( V_22 , & V_2 -> V_23 ) )
return;
if ( ! ( V_2 -> V_117 & V_357 ) )
return;
V_2 -> V_851 ++ ;
if ( F_401 ( V_16 ) == 0 ) {
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ )
F_217 ( V_366 ,
& ( V_2 -> V_38 [ V_28 ] -> V_23 ) ) ;
F_51 ( V_16 , V_348 , V_359 ) ;
} else {
F_83 ( V_149 , L_97
L_98 ) ;
}
}
static void F_402 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_4 V_852 = 0 ;
int V_28 ;
if ( F_8 ( V_22 , & V_2 -> V_23 ) ||
F_8 ( V_623 , & V_2 -> V_23 ) )
return;
if ( F_89 ( V_2 -> V_35 ) ) {
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ )
F_403 ( V_2 -> V_38 [ V_28 ] ) ;
}
if ( ! ( V_2 -> V_117 & V_382 ) ) {
F_51 ( V_16 , V_97 ,
( V_853 | V_854 ) ) ;
} else {
for ( V_28 = 0 ; V_28 < V_2 -> V_166 ; V_28 ++ ) {
struct V_134 * V_855 = V_2 -> V_135 [ V_28 ] ;
if ( V_855 -> V_294 . V_98 || V_855 -> V_139 . V_98 )
V_852 |= ( ( T_4 ) 1 << V_28 ) ;
}
}
F_55 ( V_2 , V_852 ) ;
}
static void F_404 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_856 = V_2 -> V_856 ;
bool V_332 = V_2 -> V_332 ;
bool V_113 = V_2 -> V_114 . V_115 ;
if ( ! ( V_2 -> V_117 & V_344 ) )
return;
if ( V_16 -> V_88 . V_330 . V_331 ) {
V_16 -> V_88 . V_330 . V_331 ( V_16 , & V_856 , & V_332 , false ) ;
} else {
V_856 = V_857 ;
V_332 = true ;
}
if ( V_2 -> V_116 )
V_113 |= ! ! ( V_2 -> V_116 -> V_113 ) ;
if ( V_332 && ! ( ( V_2 -> V_117 & V_118 ) && V_113 ) ) {
V_16 -> V_88 . V_330 . V_858 ( V_16 ) ;
F_405 ( V_2 ) ;
}
if ( V_332 ||
F_406 ( V_148 , ( V_2 -> V_345 +
V_859 ) ) ) {
V_2 -> V_117 &= ~ V_344 ;
F_51 ( V_16 , V_348 , V_347 ) ;
F_186 ( V_16 ) ;
}
V_2 -> V_332 = V_332 ;
V_2 -> V_856 = V_856 ;
}
static void F_407 ( struct V_1 * V_2 )
{
#ifdef F_292
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_860 V_861 = {
. V_862 = V_863 ,
. V_220 = 0 ,
} ;
T_6 V_659 = 0 ;
if ( V_2 -> V_552 & V_864 )
V_659 = F_408 ( V_35 , & V_861 ) ;
V_2 -> V_865 = ( V_659 > 1 ) ? ( F_409 ( V_659 ) - 1 ) : 0 ;
#endif
}
static void F_410 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_856 = V_2 -> V_856 ;
bool V_866 , V_867 ;
if ( F_89 ( V_35 ) )
return;
V_2 -> V_131 &= ~ V_595 ;
switch ( V_16 -> V_88 . type ) {
case V_89 : {
T_1 V_868 = F_17 ( V_16 , V_535 ) ;
T_1 V_869 = F_17 ( V_16 , V_870 ) ;
V_866 = ! ! ( V_868 & V_871 ) ;
V_867 = ! ! ( V_869 & V_872 ) ;
}
break;
case V_92 :
case V_91 : {
T_1 V_873 = F_17 ( V_16 , V_874 ) ;
T_1 V_875 = F_17 ( V_16 , V_876 ) ;
V_866 = ! ! ( V_873 & V_877 ) ;
V_867 = ! ! ( V_875 & V_878 ) ;
}
break;
default:
V_867 = false ;
V_866 = false ;
break;
}
V_2 -> V_879 = V_148 ;
if ( V_2 -> V_131 & V_632 )
F_411 ( V_2 ) ;
F_85 ( V_133 , L_99 ,
( V_856 == V_857 ?
L_100 :
( V_856 == V_880 ?
L_101 :
( V_856 == V_881 ?
L_102 :
L_103 ) ) ) ,
( ( V_866 && V_867 ) ? L_104 :
( V_866 ? L_105 :
( V_867 ? L_106 : L_107 ) ) ) ) ;
F_412 ( V_35 ) ;
F_413 ( V_2 ) ;
F_407 ( V_2 ) ;
F_326 ( V_2 ) ;
}
static void F_414 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
V_2 -> V_332 = false ;
V_2 -> V_856 = 0 ;
if ( ! F_89 ( V_35 ) )
return;
if ( F_296 ( V_16 ) && V_16 -> V_88 . type == V_89 )
V_2 -> V_131 |= V_595 ;
if ( V_2 -> V_131 & V_632 )
F_411 ( V_2 ) ;
F_85 ( V_133 , L_108 ) ;
F_323 ( V_35 ) ;
F_326 ( V_2 ) ;
}
static void F_415 ( struct V_1 * V_2 )
{
int V_28 ;
int V_882 = 0 ;
if ( ! F_89 ( V_2 -> V_35 ) ) {
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ ) {
struct V_37 * V_38 = V_2 -> V_38 [ V_28 ] ;
if ( V_38 -> V_60 != V_38 -> V_59 ) {
V_882 = 1 ;
break;
}
}
if ( V_882 ) {
F_73 ( V_133 , L_109 ) ;
V_2 -> V_131 |= V_132 ;
}
}
}
static void F_416 ( struct V_1 * V_2 )
{
T_1 V_883 ;
if ( V_2 -> V_16 . V_88 . type == V_89 ||
V_2 -> V_296 == 0 )
return;
V_883 = F_17 ( & V_2 -> V_16 , V_884 ) ;
if ( ! V_883 )
return;
F_73 ( V_133 , L_110 , V_883 ) ;
}
static void F_417 ( struct V_1 * V_2 )
{
if ( F_8 ( V_22 , & V_2 -> V_23 ) ||
F_8 ( V_623 , & V_2 -> V_23 ) )
return;
F_404 ( V_2 ) ;
if ( V_2 -> V_332 )
F_410 ( V_2 ) ;
else
F_414 ( V_2 ) ;
F_416 ( V_2 ) ;
F_382 ( V_2 ) ;
F_415 ( V_2 ) ;
}
static void F_418 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_3 V_18 ;
if ( ! ( V_2 -> V_131 & V_595 ) &&
! ( V_2 -> V_131 & V_341 ) )
return;
if ( F_8 ( V_885 , & V_2 -> V_23 ) )
return;
if ( F_9 ( V_624 , & V_2 -> V_23 ) )
return;
V_18 = V_16 -> V_333 . V_330 . V_886 ( V_16 ) ;
if ( V_18 == V_627 )
goto V_887;
if ( V_18 == V_626 ) {
V_2 -> V_131 |= V_341 ;
}
if ( V_18 )
goto V_887;
if ( ! ( V_2 -> V_131 & V_341 ) )
goto V_887;
V_2 -> V_131 &= ~ V_341 ;
if ( V_16 -> V_88 . type == V_89 )
V_18 = V_16 -> V_333 . V_330 . V_888 ( V_16 ) ;
else
V_18 = V_16 -> V_88 . V_330 . V_889 ( V_16 ) ;
if ( V_18 == V_627 )
goto V_887;
V_2 -> V_117 |= V_342 ;
F_85 ( V_149 , L_111 , V_16 -> V_333 . V_890 ) ;
V_887:
F_14 ( V_624 , & V_2 -> V_23 ) ;
if ( ( V_18 == V_627 ) &&
( V_2 -> V_35 -> V_891 == V_892 ) ) {
F_311 ( L_112
L_113 ) ;
F_311 ( L_114
L_115 ) ;
F_419 ( V_2 -> V_35 ) ;
}
}
static void F_420 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_21 ;
bool V_596 = false ;
if ( ! ( V_2 -> V_117 & V_342 ) )
return;
if ( F_9 ( V_624 , & V_2 -> V_23 ) )
return;
V_2 -> V_117 &= ~ V_342 ;
V_21 = V_16 -> V_333 . V_599 ;
if ( ( ! V_21 ) && ( V_16 -> V_88 . V_330 . V_600 ) )
V_16 -> V_88 . V_330 . V_600 ( V_16 , & V_21 , & V_596 ) ;
if ( V_16 -> V_88 . V_330 . V_601 )
V_16 -> V_88 . V_330 . V_601 ( V_16 , V_21 , true ) ;
V_2 -> V_117 |= V_344 ;
V_2 -> V_345 = V_148 ;
F_14 ( V_624 , & V_2 -> V_23 ) ;
}
static void F_421 ( struct V_1 * V_2 )
{
int V_893 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_34 * V_35 = V_2 -> V_35 ;
T_1 V_894 ;
T_1 V_895 , V_896 ;
V_894 = F_17 ( V_16 , V_897 ) ;
if ( V_894 )
return;
for ( V_893 = 0 ; V_893 < V_2 -> V_296 ; V_893 ++ ) {
V_895 = ( V_893 << 16 ) | 0x80000000 ;
V_895 |= V_898 ;
F_51 ( V_16 , V_899 , V_895 ) ;
V_896 = F_17 ( V_16 , V_900 ) ;
V_895 &= 0x7FFFFFFF ;
F_51 ( V_16 , V_899 , V_895 ) ;
V_896 >>= 16 ;
if ( V_896 & V_901 ) {
F_422 ( V_35 , L_116 , V_893 ) ;
V_895 = ( V_893 << 16 ) | 0x80000000 ;
V_895 |= 0xA8 ;
F_51 ( V_16 , V_899 , V_895 ) ;
V_896 = 0x00008000 ;
F_51 ( V_16 , V_900 , V_896 ) ;
V_895 &= 0x7FFFFFFF ;
F_51 ( V_16 , V_899 , V_895 ) ;
}
}
}
static void F_423 ( unsigned long V_72 )
{
struct V_1 * V_2 = (struct V_1 * ) V_72 ;
unsigned long V_902 ;
bool V_903 = true ;
if ( V_2 -> V_117 & V_344 )
V_902 = V_904 / 10 ;
else
V_902 = V_904 * 2 ;
#ifdef F_335
if ( ! V_2 -> V_296 ||
( V_2 -> V_117 & V_344 ) )
goto V_905;
F_421 ( V_2 ) ;
V_902 = V_904 / 50 ;
V_2 -> V_906 ++ ;
if ( V_2 -> V_906 >= 100 )
V_2 -> V_906 = 0 ;
else
V_903 = false ;
V_905:
#endif
F_303 ( & V_2 -> V_621 , V_902 + V_148 ) ;
if ( V_903 )
F_7 ( V_2 ) ;
}
static void F_424 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_131 & V_132 ) )
return;
V_2 -> V_131 &= ~ V_132 ;
if ( F_8 ( V_22 , & V_2 -> V_23 ) ||
F_8 ( V_623 , & V_2 -> V_23 ) )
return;
F_34 ( V_2 ) ;
F_422 ( V_2 -> V_35 , L_117 ) ;
V_2 -> V_150 ++ ;
F_304 ( V_2 ) ;
}
static void F_425 ( struct V_907 * V_908 )
{
struct V_1 * V_2 = F_199 ( V_908 ,
struct V_1 ,
V_25 ) ;
F_424 ( V_2 ) ;
F_418 ( V_2 ) ;
F_420 ( V_2 ) ;
F_180 ( V_2 ) ;
F_417 ( V_2 ) ;
F_400 ( V_2 ) ;
F_402 ( V_2 ) ;
if ( V_2 -> V_131 & V_632 ) {
F_426 ( V_2 ) ;
F_427 ( V_2 ) ;
}
F_11 ( V_2 ) ;
}
static int F_428 ( struct V_37 * V_38 ,
struct V_39 * V_909 ,
T_6 * V_238 )
{
struct V_172 * V_69 = V_909 -> V_69 ;
T_1 V_910 , V_911 ;
T_1 V_912 , V_913 ;
if ( V_69 -> V_195 != V_914 )
return 0 ;
if ( ! F_429 ( V_69 ) )
return 0 ;
if ( F_430 ( V_69 ) ) {
int V_18 = F_431 ( V_69 , 0 , 0 , V_200 ) ;
if ( V_18 )
return V_18 ;
}
V_911 = V_915 ;
if ( V_909 -> V_220 == F_127 ( V_228 ) ) {
struct V_215 * V_916 = F_432 ( V_69 ) ;
V_916 -> V_917 = 0 ;
V_916 -> V_918 = 0 ;
F_433 ( V_69 ) -> V_918 = ~ F_434 ( V_916 -> V_919 ,
V_916 -> V_920 , 0 ,
V_234 ,
0 ) ;
V_911 |= V_921 ;
V_909 -> V_922 |= V_923 |
V_924 |
V_925 ;
} else if ( F_435 ( V_69 ) ) {
F_436 ( V_69 ) -> V_926 = 0 ;
F_433 ( V_69 ) -> V_918 =
~ F_437 ( & F_436 ( V_69 ) -> V_919 ,
& F_436 ( V_69 ) -> V_920 ,
0 , V_234 , 0 ) ;
V_909 -> V_922 |= V_923 |
V_924 ;
}
V_913 = F_438 ( V_69 ) ;
* V_238 = F_439 ( V_69 ) + V_913 ;
V_909 -> V_145 = F_132 ( V_69 ) -> V_145 ;
V_909 -> V_144 += ( V_909 -> V_145 - 1 ) * * V_238 ;
V_912 = V_913 << V_927 ;
V_912 |= F_132 ( V_69 ) -> V_239 << V_928 ;
V_910 = F_440 ( V_69 ) ;
V_910 |= F_441 ( V_69 ) << V_929 ;
V_910 |= V_909 -> V_922 & V_930 ;
F_442 ( V_38 , V_910 , 0 , V_911 ,
V_912 ) ;
return 1 ;
}
static void F_443 ( struct V_37 * V_38 ,
struct V_39 * V_909 )
{
struct V_172 * V_69 = V_909 -> V_69 ;
T_1 V_910 = 0 ;
T_1 V_912 = 0 ;
T_1 V_911 = 0 ;
if ( V_69 -> V_195 != V_914 ) {
if ( ! ( V_909 -> V_922 & V_931 ) &&
! ( V_909 -> V_922 & V_932 ) )
return;
} else {
T_6 V_933 = 0 ;
switch ( V_909 -> V_220 ) {
case F_127 ( V_228 ) :
V_910 |= F_440 ( V_69 ) ;
V_911 |= V_921 ;
V_933 = F_432 ( V_69 ) -> V_220 ;
break;
case F_127 ( V_231 ) :
V_910 |= F_440 ( V_69 ) ;
V_933 = F_436 ( V_69 ) -> V_221 ;
break;
default:
if ( F_77 ( F_444 () ) ) {
F_445 ( V_38 -> V_53 ,
L_118 ,
V_909 -> V_220 ) ;
}
break;
}
switch ( V_933 ) {
case V_234 :
V_911 |= V_915 ;
V_912 = F_438 ( V_69 ) <<
V_927 ;
break;
case V_934 :
V_911 |= V_935 ;
V_912 = sizeof( struct V_936 ) <<
V_927 ;
break;
case V_236 :
V_912 = sizeof( struct V_237 ) <<
V_927 ;
break;
default:
if ( F_77 ( F_444 () ) ) {
F_445 ( V_38 -> V_53 ,
L_119 ,
V_933 ) ;
}
break;
}
V_909 -> V_922 |= V_924 ;
}
V_910 |= F_441 ( V_69 ) << V_929 ;
V_910 |= V_909 -> V_922 & V_930 ;
F_442 ( V_38 , V_910 , 0 ,
V_911 , V_912 ) ;
}
static T_1 F_446 ( struct V_172 * V_69 , T_1 V_922 )
{
T_1 V_937 = V_938 |
V_939 |
V_940 ;
V_937 |= F_447 ( V_922 , V_931 ,
V_941 ) ;
V_937 |= F_447 ( V_922 , V_923 ,
V_942 ) ;
V_937 |= F_447 ( V_922 , V_943 ,
V_944 ) ;
V_937 ^= F_447 ( V_69 -> V_945 , 1 , V_940 ) ;
return V_937 ;
}
static void F_448 ( union V_41 * V_42 ,
T_1 V_922 , unsigned int V_946 )
{
T_1 V_947 = V_946 << V_948 ;
V_947 |= F_447 ( V_922 ,
V_924 ,
V_949 ) ;
V_947 |= F_447 ( V_922 ,
V_925 ,
V_950 ) ;
V_947 |= F_447 ( V_922 ,
V_932 ,
V_951 ) ;
V_42 -> V_206 . V_947 = F_76 ( V_947 ) ;
}
static void F_449 ( struct V_37 * V_38 ,
struct V_39 * V_909 ,
const T_6 V_238 )
{
struct V_172 * V_69 = V_909 -> V_69 ;
struct V_39 * V_40 ;
union V_41 * V_42 ;
struct V_259 * V_260 ;
T_8 V_61 ;
unsigned int V_265 , V_274 ;
T_1 V_922 = V_909 -> V_922 ;
T_1 V_937 = F_446 ( V_69 , V_922 ) ;
T_2 V_28 = V_38 -> V_60 ;
V_42 = F_41 ( V_38 , V_28 ) ;
F_448 ( V_42 , V_922 , V_69 -> V_62 - V_238 ) ;
V_274 = F_131 ( V_69 ) ;
V_265 = V_69 -> V_265 ;
#ifdef F_129
if ( V_922 & V_952 ) {
if ( V_265 < sizeof( struct V_293 ) ) {
V_274 -= sizeof( struct V_293 ) - V_265 ;
V_265 = 0 ;
} else {
V_265 -= sizeof( struct V_293 ) ;
}
}
#endif
V_61 = F_450 ( V_38 -> V_53 , V_69 -> V_72 , V_274 , V_99 ) ;
V_40 = V_909 ;
for ( V_260 = & F_132 ( V_69 ) -> V_261 [ 0 ] ; ; V_260 ++ ) {
if ( F_122 ( V_38 -> V_53 , V_61 ) )
goto V_953;
F_61 ( V_40 , V_62 , V_274 ) ;
F_451 ( V_40 , V_61 , V_61 ) ;
V_42 -> V_206 . V_954 = F_125 ( V_61 ) ;
while ( F_77 ( V_274 > V_955 ) ) {
V_42 -> V_206 . V_956 =
F_76 ( V_937 ^ V_955 ) ;
V_28 ++ ;
V_42 ++ ;
if ( V_28 == V_38 -> V_68 ) {
V_42 = F_41 ( V_38 , 0 ) ;
V_28 = 0 ;
}
V_42 -> V_206 . V_947 = 0 ;
V_61 += V_955 ;
V_274 -= V_955 ;
V_42 -> V_206 . V_954 = F_125 ( V_61 ) ;
}
if ( F_79 ( ! V_265 ) )
break;
V_42 -> V_206 . V_956 = F_76 ( V_937 ^ V_274 ) ;
V_28 ++ ;
V_42 ++ ;
if ( V_28 == V_38 -> V_68 ) {
V_42 = F_41 ( V_38 , 0 ) ;
V_28 = 0 ;
}
V_42 -> V_206 . V_947 = 0 ;
#ifdef F_129
V_274 = F_331 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_274 = F_452 ( V_260 ) ;
#endif
V_265 -= V_274 ;
V_61 = F_453 ( V_38 -> V_53 , V_260 , 0 , V_274 ,
V_99 ) ;
V_40 = & V_38 -> V_58 [ V_28 ] ;
}
V_937 |= V_274 | V_957 ;
V_42 -> V_206 . V_956 = F_76 ( V_937 ) ;
F_454 ( F_87 ( V_38 ) , V_909 -> V_144 ) ;
V_909 -> V_64 = V_148 ;
F_115 () ;
V_909 -> V_63 = V_42 ;
V_28 ++ ;
if ( V_28 == V_38 -> V_68 )
V_28 = 0 ;
V_38 -> V_60 = V_28 ;
F_116 ( V_28 , V_38 -> V_125 ) ;
return;
V_953:
F_344 ( V_38 -> V_53 , L_120 ) ;
for (; ; ) {
V_40 = & V_38 -> V_58 [ V_28 ] ;
F_57 ( V_38 , V_40 ) ;
if ( V_40 == V_909 )
break;
if ( V_28 == 0 )
V_28 = V_38 -> V_68 ;
V_28 -- ;
}
V_38 -> V_60 = V_28 ;
}
static void F_455 ( struct V_37 * V_98 ,
struct V_39 * V_909 )
{
struct V_134 * V_135 = V_98 -> V_135 ;
union V_958 V_959 = { . V_960 = 0 } ;
union V_958 V_961 = { . V_960 = 0 } ;
union {
unsigned char * V_210 ;
struct V_215 * V_216 ;
struct V_217 * V_218 ;
} V_219 ;
struct V_235 * V_962 ;
T_9 V_963 ;
if ( ! V_135 )
return;
if ( ! V_98 -> V_393 )
return;
V_98 -> V_394 ++ ;
V_219 . V_210 = F_456 ( V_909 -> V_69 ) ;
if ( ( V_909 -> V_220 != F_127 ( V_231 ) ||
V_219 . V_218 -> V_221 != V_234 ) &&
( V_909 -> V_220 != F_127 ( V_228 ) ||
V_219 . V_216 -> V_220 != V_234 ) )
return;
V_962 = F_433 ( V_909 -> V_69 ) ;
if ( ! V_962 || V_962 -> V_964 )
return;
if ( ! V_962 -> V_965 && ( V_98 -> V_394 < V_98 -> V_393 ) )
return;
V_98 -> V_394 = 0 ;
V_963 = F_128 ( V_909 -> V_922 >> V_966 ) ;
V_959 . V_967 . V_963 = V_963 ;
if ( V_909 -> V_922 & ( V_968 | V_931 ) )
V_961 . V_969 . V_970 ^= V_962 -> V_971 ^ F_127 ( V_225 ) ;
else
V_961 . V_969 . V_970 ^= V_962 -> V_971 ^ V_909 -> V_220 ;
V_961 . V_969 . V_972 ^= V_962 -> V_973 ;
if ( V_909 -> V_220 == F_127 ( V_228 ) ) {
V_959 . V_967 . V_974 = V_975 ;
V_961 . V_976 ^= V_219 . V_216 -> V_919 ^ V_219 . V_216 -> V_920 ;
} else {
V_959 . V_967 . V_974 = V_977 ;
V_961 . V_976 ^= V_219 . V_218 -> V_919 . V_978 [ 0 ] ^
V_219 . V_218 -> V_919 . V_978 [ 1 ] ^
V_219 . V_218 -> V_919 . V_978 [ 2 ] ^
V_219 . V_218 -> V_919 . V_978 [ 3 ] ^
V_219 . V_218 -> V_920 . V_978 [ 0 ] ^
V_219 . V_218 -> V_920 . V_978 [ 1 ] ^
V_219 . V_218 -> V_920 . V_978 [ 2 ] ^
V_219 . V_218 -> V_920 . V_978 [ 3 ] ;
}
F_457 ( & V_135 -> V_2 -> V_16 ,
V_959 , V_961 , V_98 -> V_66 ) ;
}
static int F_458 ( struct V_37 * V_38 , T_2 V_274 )
{
F_84 ( V_38 -> V_35 , V_38 -> V_66 ) ;
F_91 () ;
if ( F_79 ( F_90 ( V_38 ) < V_274 ) )
return - V_705 ;
F_459 ( V_38 -> V_35 , V_38 -> V_66 ) ;
++ V_38 -> V_128 . V_151 ;
return 0 ;
}
static inline int F_460 ( struct V_37 * V_38 , T_2 V_274 )
{
if ( F_79 ( F_90 ( V_38 ) >= V_274 ) )
return 0 ;
return F_458 ( V_38 , V_274 ) ;
}
static T_2 F_461 ( struct V_34 * V_53 , struct V_172 * V_69 )
{
struct V_1 * V_2 ;
struct V_979 * V_980 ;
int V_981 ;
switch ( F_462 ( V_69 ) ) {
case F_127 ( V_232 ) :
case F_127 ( V_982 ) :
V_2 = F_69 ( V_53 ) ;
if ( V_2 -> V_117 & V_490 )
break;
default:
return F_463 ( V_53 , V_69 ) ;
}
V_980 = & V_2 -> V_408 [ V_983 ] ;
V_981 = F_464 ( V_69 ) ? F_465 ( V_69 ) :
F_466 () ;
while ( V_981 >= V_980 -> V_410 )
V_981 -= V_980 -> V_410 ;
return V_981 + V_980 -> V_984 ;
}
T_13 F_467 ( struct V_172 * V_69 ,
struct V_1 * V_2 ,
struct V_37 * V_38 )
{
struct V_39 * V_909 ;
int V_985 ;
T_1 V_922 = 0 ;
unsigned short V_980 ;
T_2 V_68 = F_468 ( F_131 ( V_69 ) ) ;
T_9 V_220 = V_69 -> V_220 ;
T_6 V_238 = 0 ;
for ( V_980 = 0 ; V_980 < F_132 ( V_69 ) -> V_280 ; V_980 ++ )
V_68 += F_468 ( F_132 ( V_69 ) -> V_261 [ V_980 ] . V_274 ) ;
if ( F_460 ( V_38 , V_68 + 3 ) ) {
V_38 -> V_128 . V_731 ++ ;
return V_986 ;
}
V_909 = & V_38 -> V_58 [ V_38 -> V_60 ] ;
V_909 -> V_69 = V_69 ;
V_909 -> V_144 = V_69 -> V_62 ;
V_909 -> V_145 = 1 ;
if ( F_469 ( V_69 ) ) {
V_922 |= F_470 ( V_69 ) << V_966 ;
V_922 |= V_931 ;
} else if ( V_220 == F_127 ( V_225 ) ) {
struct V_213 * V_987 , V_988 ;
V_987 = F_471 ( V_69 , V_223 , sizeof( V_988 ) , & V_988 ) ;
if ( ! V_987 )
goto V_989;
V_220 = V_987 -> V_227 ;
V_922 |= F_472 ( V_987 -> V_990 ) <<
V_966 ;
V_922 |= V_968 ;
}
F_473 ( V_69 ) ;
if ( F_77 ( F_132 ( V_69 ) -> V_922 & V_991 ) ) {
F_132 ( V_69 ) -> V_922 |= V_992 ;
V_922 |= V_943 ;
V_2 -> V_993 = F_474 ( V_69 ) ;
V_2 -> V_994 = V_148 ;
F_10 ( & V_2 -> V_995 ) ;
}
#ifdef F_335
if ( V_2 -> V_117 & V_403 )
V_922 |= V_932 ;
#endif
if ( ( V_2 -> V_117 & V_118 ) &&
( ( V_922 & ( V_931 | V_968 ) ) ||
( V_69 -> V_996 != V_997 ) ) ) {
V_922 &= ~ V_998 ;
V_922 |= ( V_69 -> V_996 & 0x7 ) <<
V_999 ;
if ( V_922 & V_968 ) {
struct V_1000 * V_987 ;
if ( F_430 ( V_69 ) &&
F_431 ( V_69 , 0 , 0 , V_200 ) )
goto V_989;
V_987 = (struct V_1000 * ) V_69 -> V_72 ;
V_987 -> V_990 = F_128 ( V_922 >>
V_966 ) ;
} else {
V_922 |= V_931 ;
}
}
V_909 -> V_922 = V_922 ;
V_909 -> V_220 = V_220 ;
#ifdef F_129
if ( ( V_220 == F_127 ( V_232 ) ) &&
( V_38 -> V_35 -> V_173 & ( V_1001 | V_1002 ) ) ) {
V_985 = F_475 ( V_38 , V_909 , & V_238 ) ;
if ( V_985 < 0 )
goto V_989;
goto V_1003;
}
#endif
V_985 = F_428 ( V_38 , V_909 , & V_238 ) ;
if ( V_985 < 0 )
goto V_989;
else if ( ! V_985 )
F_443 ( V_38 , V_909 ) ;
if ( F_8 ( V_366 , & V_38 -> V_23 ) )
F_455 ( V_38 , V_909 ) ;
#ifdef F_129
V_1003:
#endif
F_449 ( V_38 , V_909 , V_238 ) ;
F_460 ( V_38 , V_1004 ) ;
return V_1005 ;
V_989:
F_58 ( V_909 -> V_69 ) ;
V_909 -> V_69 = NULL ;
return V_1005 ;
}
static T_13 F_476 ( struct V_172 * V_69 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
struct V_37 * V_38 ;
if ( F_77 ( V_69 -> V_62 < 17 ) ) {
if ( F_156 ( V_69 , 17 - V_69 -> V_62 ) )
return V_1005 ;
V_69 -> V_62 = 17 ;
F_477 ( V_69 , 17 ) ;
}
V_38 = V_2 -> V_38 [ V_69 -> V_1006 ] ;
return F_467 ( V_69 , V_2 , V_38 ) ;
}
static int F_478 ( struct V_34 * V_35 , void * V_456 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_1007 * V_528 = V_456 ;
if ( ! F_479 ( V_528 -> V_1008 ) )
return - V_1009 ;
memcpy ( V_35 -> V_1010 , V_528 -> V_1008 , V_35 -> V_1011 ) ;
memcpy ( V_16 -> V_88 . V_528 , V_528 -> V_1008 , V_35 -> V_1011 ) ;
V_16 -> V_88 . V_330 . V_527 ( V_16 , 0 , V_16 -> V_88 . V_528 , F_237 ( 0 ) , V_529 ) ;
return 0 ;
}
static int
F_480 ( struct V_34 * V_35 , int V_1012 , int V_1013 , T_2 V_528 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_2 V_4 ;
int V_1014 ;
if ( V_1012 != V_16 -> V_333 . V_1015 . V_1012 )
return - V_703 ;
V_1014 = V_16 -> V_333 . V_330 . V_1016 ( V_16 , V_528 , V_1013 , & V_4 ) ;
if ( ! V_1014 )
V_1014 = V_4 ;
return V_1014 ;
}
static int F_481 ( struct V_34 * V_35 , int V_1012 , int V_1013 ,
T_2 V_528 , T_2 V_4 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
if ( V_1012 != V_16 -> V_333 . V_1015 . V_1012 )
return - V_703 ;
return V_16 -> V_333 . V_330 . V_1017 ( V_16 , V_528 , V_1013 , V_4 ) ;
}
static int F_482 ( struct V_34 * V_35 , struct V_1018 * V_1019 , int V_1020 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
switch ( V_1020 ) {
case V_1021 :
return F_483 ( V_2 , V_1019 , V_1020 ) ;
default:
return F_484 ( & V_2 -> V_16 . V_333 . V_1015 , F_485 ( V_1019 ) , V_1020 ) ;
}
}
static int F_486 ( struct V_34 * V_53 )
{
int V_18 = 0 ;
struct V_1 * V_2 = F_69 ( V_53 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
if ( F_479 ( V_16 -> V_88 . V_1022 ) ) {
F_370 () ;
V_18 = F_487 ( V_53 , V_16 -> V_88 . V_1022 , V_1023 ) ;
F_372 () ;
V_16 -> V_88 . V_330 . V_631 ( V_16 , F_237 ( 0 ) ) ;
}
return V_18 ;
}
static int F_488 ( struct V_34 * V_53 )
{
int V_18 = 0 ;
struct V_1 * V_2 = F_69 ( V_53 ) ;
struct V_1024 * V_88 = & V_2 -> V_16 . V_88 ;
if ( F_479 ( V_88 -> V_1022 ) ) {
F_370 () ;
V_18 = F_489 ( V_53 , V_88 -> V_1022 , V_1023 ) ;
F_372 () ;
}
return V_18 ;
}
static void F_490 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
int V_28 ;
if ( F_8 ( V_22 , & V_2 -> V_23 ) )
return;
V_2 -> V_117 |= V_248 ;
if ( V_2 -> V_117 & V_382 ) {
for ( V_28 = 0 ; V_28 < V_2 -> V_166 ; V_28 ++ )
F_196 ( 0 , V_2 -> V_135 [ V_28 ] ) ;
} else {
F_208 ( V_2 -> V_10 -> V_360 , V_35 ) ;
}
V_2 -> V_117 &= ~ V_248 ;
}
static struct V_1025 * F_491 ( struct V_34 * V_35 ,
struct V_1025 * V_102 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
int V_28 ;
F_492 () ;
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ ) {
struct V_37 * V_98 = F_493 ( V_2 -> V_47 [ V_28 ] ) ;
T_4 V_147 , V_122 ;
unsigned int V_1026 ;
if ( V_98 ) {
do {
V_1026 = F_494 ( & V_98 -> V_146 ) ;
V_122 = V_98 -> V_102 . V_122 ;
V_147 = V_98 -> V_102 . V_147 ;
} while ( F_495 ( & V_98 -> V_146 , V_1026 ) );
V_102 -> V_736 += V_122 ;
V_102 -> V_735 += V_147 ;
}
}
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ ) {
struct V_37 * V_98 = F_493 ( V_2 -> V_38 [ V_28 ] ) ;
T_4 V_147 , V_122 ;
unsigned int V_1026 ;
if ( V_98 ) {
do {
V_1026 = F_494 ( & V_98 -> V_146 ) ;
V_122 = V_98 -> V_102 . V_122 ;
V_147 = V_98 -> V_102 . V_147 ;
} while ( F_495 ( & V_98 -> V_146 , V_1026 ) );
V_102 -> V_738 += V_122 ;
V_102 -> V_737 += V_147 ;
}
}
F_496 () ;
V_102 -> V_845 = V_35 -> V_102 . V_845 ;
V_102 -> V_846 = V_35 -> V_102 . V_846 ;
V_102 -> V_848 = V_35 -> V_102 . V_848 ;
V_102 -> V_849 = V_35 -> V_102 . V_849 ;
V_102 -> V_850 = V_35 -> V_102 . V_850 ;
return V_102 ;
}
static void F_497 ( struct V_1 * V_2 , T_6 V_112 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_3 , V_1027 ;
int V_28 ;
if ( V_16 -> V_88 . type == V_89 )
return;
V_3 = F_17 ( V_16 , V_1028 ) ;
V_1027 = V_3 ;
for ( V_28 = 0 ; V_28 < V_670 ; V_28 ++ ) {
T_6 V_1029 = V_3 >> ( V_28 * V_1030 ) ;
if ( V_1029 > V_112 )
V_3 &= ~ ( 0x7 << V_1030 ) ;
}
if ( V_3 != V_1027 )
F_51 ( V_16 , V_1028 , V_3 ) ;
return;
}
static void F_498 ( struct V_1 * V_2 )
{
struct V_34 * V_53 = V_2 -> V_35 ;
struct V_1031 * V_114 = & V_2 -> V_114 ;
struct V_1032 * V_1033 = V_2 -> V_556 ;
T_6 V_1034 ;
for ( V_1034 = 0 ; V_1034 < V_1035 ; V_1034 ++ ) {
T_6 V_112 = 0 ;
if ( V_2 -> V_552 & V_553 )
V_112 = F_499 ( V_114 , 0 , V_1034 ) ;
else if ( V_1033 )
V_112 = V_1033 -> V_557 [ V_1034 ] ;
F_500 ( V_53 , V_1034 , V_112 ) ;
}
}
int F_501 ( struct V_34 * V_53 , T_6 V_112 )
{
struct V_1 * V_2 = F_69 ( V_53 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
if ( V_112 > V_2 -> V_114 . V_666 . V_667 ||
( V_16 -> V_88 . type == V_89 &&
V_112 < V_670 ) )
return - V_703 ;
if ( F_37 ( V_53 ) )
F_360 ( V_53 ) ;
F_377 ( V_2 ) ;
#ifdef F_292
if ( V_112 ) {
F_502 ( V_53 , V_112 ) ;
F_498 ( V_2 ) ;
V_2 -> V_117 |= V_118 ;
if ( V_2 -> V_16 . V_88 . type == V_89 ) {
V_2 -> V_1036 = V_2 -> V_16 . V_103 . V_682 ;
V_2 -> V_16 . V_103 . V_682 = V_1037 ;
}
} else {
F_503 ( V_53 ) ;
if ( V_2 -> V_16 . V_88 . type == V_89 )
V_2 -> V_16 . V_103 . V_682 = V_2 -> V_1036 ;
V_2 -> V_117 &= ~ V_118 ;
V_2 -> V_681 . V_115 = false ;
V_2 -> V_114 . V_115 = false ;
}
F_497 ( V_2 , V_112 ) ;
#endif
F_371 ( V_2 ) ;
if ( F_37 ( V_53 ) )
return F_356 ( V_53 ) ;
return 0 ;
}
void F_504 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
F_370 () ;
F_501 ( V_35 , F_221 ( V_35 ) ) ;
F_372 () ;
}
void F_505 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
if ( F_37 ( V_35 ) )
F_304 ( V_2 ) ;
else
F_310 ( V_2 ) ;
}
static T_14 F_506 ( struct V_34 * V_35 ,
T_14 V_173 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
if ( ! ( V_173 & V_186 ) )
V_173 &= ~ V_1038 ;
if ( ! ( V_2 -> V_131 & V_651 ) )
V_173 &= ~ V_1038 ;
return V_173 ;
}
static int F_507 ( struct V_34 * V_35 ,
T_14 V_173 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
T_14 V_1039 = V_35 -> V_173 ^ V_173 ;
bool V_1040 = false ;
if ( ! ( V_173 & V_1038 ) ) {
if ( V_2 -> V_131 & V_498 )
V_1040 = true ;
V_2 -> V_131 &= ~ V_498 ;
} else if ( ( V_2 -> V_131 & V_651 ) &&
! ( V_2 -> V_131 & V_498 ) ) {
if ( V_2 -> V_373 == 1 ||
V_2 -> V_373 > V_1041 ) {
V_2 -> V_131 |= V_498 ;
V_1040 = true ;
} else if ( ( V_1039 ^ V_173 ) & V_1038 ) {
F_85 ( V_149 , L_121
L_122 ) ;
}
}
switch ( V_173 & V_1042 ) {
case V_1042 :
if ( ! ( V_2 -> V_117 & V_570 ) )
V_1040 = true ;
V_2 -> V_117 &= ~ V_357 ;
V_2 -> V_117 |= V_570 ;
break;
default:
if ( V_2 -> V_117 & V_570 )
V_1040 = true ;
V_2 -> V_117 &= ~ V_570 ;
if ( V_2 -> V_117 & V_403 )
break;
if ( F_221 ( V_35 ) > 1 )
break;
if ( V_2 -> V_408 [ V_409 ] . V_650 <= 1 )
break;
if ( ! V_2 -> V_393 )
break;
V_2 -> V_117 |= V_357 ;
break;
}
if ( V_173 & V_245 )
F_252 ( V_2 ) ;
else
F_251 ( V_2 ) ;
if ( V_1039 & V_268 )
V_1040 = true ;
V_35 -> V_173 = V_173 ;
if ( V_1040 )
F_505 ( V_35 ) ;
return 0 ;
}
static int F_508 ( struct V_1043 * V_1044 , struct V_1045 * V_1046 [] ,
struct V_34 * V_53 ,
const unsigned char * V_528 ,
T_2 V_117 )
{
struct V_1 * V_2 = F_69 ( V_53 ) ;
int V_18 ;
if ( ! ( V_2 -> V_117 & V_403 ) )
return F_509 ( V_1044 , V_1046 , V_53 , V_528 , V_117 ) ;
if ( V_1044 -> V_1047 && ! ( V_1044 -> V_1047 & V_1048 ) ) {
F_31 ( L_123 ,
V_1049 ) ;
return - V_703 ;
}
if ( F_510 ( V_528 ) || F_511 ( V_528 ) ) {
T_1 V_1050 = V_523 ;
if ( F_256 ( V_53 ) < V_1050 )
V_18 = F_512 ( V_53 , V_528 ) ;
else
V_18 = - V_524 ;
} else if ( F_513 ( V_528 ) ) {
V_18 = F_514 ( V_53 , V_528 ) ;
} else {
V_18 = - V_703 ;
}
if ( V_18 == - V_1051 && ! ( V_117 & V_1052 ) )
V_18 = 0 ;
return V_18 ;
}
static int F_515 ( struct V_34 * V_53 ,
struct V_1053 * V_1054 )
{
struct V_1 * V_2 = F_69 ( V_53 ) ;
struct V_1045 * V_1055 , * V_1056 ;
int V_1057 ;
if ( ! ( V_2 -> V_117 & V_403 ) )
return - V_1058 ;
V_1056 = F_516 ( V_1054 , sizeof( struct V_1059 ) , V_1060 ) ;
F_517 (attr, br_spec, rem) {
T_15 V_1061 ;
T_1 V_3 = 0 ;
if ( F_518 ( V_1055 ) != V_1062 )
continue;
V_1061 = F_519 ( V_1055 ) ;
if ( V_1061 == V_1063 ) {
V_3 = 0 ;
V_2 -> V_131 &= ~ V_472 ;
} else if ( V_1061 == V_1064 ) {
V_3 = V_474 ;
V_2 -> V_131 |= V_472 ;
} else
return - V_703 ;
F_51 ( & V_2 -> V_16 , V_473 , V_3 ) ;
F_85 ( V_133 , L_124 ,
V_1061 == V_1063 ? L_125 : L_126 ) ;
}
return 0 ;
}
static int F_520 ( struct V_172 * V_69 , T_1 V_1065 , T_1 V_1066 ,
struct V_34 * V_53 ,
T_1 V_1067 )
{
struct V_1 * V_2 = F_69 ( V_53 ) ;
T_2 V_1061 ;
if ( ! ( V_2 -> V_117 & V_403 ) )
return 0 ;
if ( V_2 -> V_131 & V_472 )
V_1061 = V_1064 ;
else
V_1061 = V_1063 ;
return F_521 ( V_69 , V_1065 , V_1066 , V_53 , V_1061 ) ;
}
int F_522 ( struct V_1 * V_2 , T_2 V_326 ,
T_2 V_1068 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_2 V_1069 = V_2 -> V_1070 & V_1071 ;
int V_1072 = 0 ;
switch ( V_326 ) {
case V_1073 :
switch ( V_1068 ) {
case V_1074 :
if ( V_16 -> V_11 . V_1075 != 0 )
break;
case V_1076 :
case V_1077 :
case V_1078 :
case V_1079 :
case V_1080 :
V_1072 = 1 ;
break;
}
break;
case V_1081 :
switch ( V_1068 ) {
case V_1082 :
V_1072 = 1 ;
break;
}
break;
case V_1083 :
if ( V_1068 != V_1084 )
V_1072 = 1 ;
break;
case V_1085 :
V_1072 = 1 ;
break;
case V_1086 :
case V_1087 :
if ( ( V_1069 == V_1088 ) ||
( ( V_1069 == V_1089 ) &&
( V_16 -> V_11 . V_1075 == 0 ) ) ) {
V_1072 = 1 ;
}
break;
}
return V_1072 ;
}
static int F_523 ( struct V_6 * V_10 , const struct V_1090 * V_1091 )
{
struct V_34 * V_35 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_16 ;
const struct V_1092 * V_1093 = V_1094 [ V_1091 -> V_1095 ] ;
static int V_1096 ;
int V_28 , V_18 , V_1097 ;
unsigned int V_410 = V_1098 ;
T_6 V_1099 [ V_1100 ] ;
#ifdef F_129
T_2 V_1101 ;
#endif
T_1 V_1102 ;
if ( V_10 -> V_1103 ) {
F_524 ( 1 , V_1104 L_127 ,
F_525 ( V_10 ) , V_10 -> V_642 , V_10 -> V_167 ) ;
return - V_703 ;
}
V_18 = F_367 ( V_10 ) ;
if ( V_18 )
return V_18 ;
if ( ! F_526 ( & V_10 -> V_53 , F_215 ( 64 ) ) &&
! F_527 ( & V_10 -> V_53 , F_215 ( 64 ) ) ) {
V_1097 = 1 ;
} else {
V_18 = F_526 ( & V_10 -> V_53 , F_215 ( 32 ) ) ;
if ( V_18 ) {
V_18 = F_527 ( & V_10 -> V_53 ,
F_215 ( 32 ) ) ;
if ( V_18 ) {
F_344 ( & V_10 -> V_53 ,
L_128 ) ;
goto V_1105;
}
}
V_1097 = 0 ;
}
V_18 = F_528 ( V_10 , F_529 ( V_10 ,
V_1106 ) , V_1049 ) ;
if ( V_18 ) {
F_344 ( & V_10 -> V_53 ,
L_129 , V_18 ) ;
goto V_1107;
}
F_530 ( V_10 ) ;
F_368 ( V_10 ) ;
F_366 ( V_10 ) ;
if ( V_1093 -> V_88 == V_89 ) {
#ifdef F_292
V_410 = 4 * V_670 ;
#else
V_410 = V_649 ;
#endif
}
V_35 = F_531 ( sizeof( struct V_1 ) , V_410 ) ;
if ( ! V_35 ) {
V_18 = - V_524 ;
goto V_1108;
}
F_532 ( V_35 , & V_10 -> V_53 ) ;
V_2 = F_69 ( V_35 ) ;
F_533 ( V_10 , V_2 ) ;
V_2 -> V_35 = V_35 ;
V_2 -> V_10 = V_10 ;
V_16 = & V_2 -> V_16 ;
V_16 -> V_1109 = V_2 ;
V_2 -> V_1110 = F_534 ( V_1111 , V_1112 ) ;
V_16 -> V_391 = F_535 ( F_536 ( V_10 , 0 ) ,
F_537 ( V_10 , 0 ) ) ;
if ( ! V_16 -> V_391 ) {
V_18 = - V_695 ;
goto V_1113;
}
V_35 -> V_1114 = & V_1115 ;
F_538 ( V_35 ) ;
V_35 -> V_1116 = 5 * V_904 ;
strncpy ( V_35 -> V_33 , F_525 ( V_10 ) , sizeof( V_35 -> V_33 ) - 1 ) ;
V_2 -> V_1117 = V_1096 ;
memcpy ( & V_16 -> V_88 . V_330 , V_1093 -> V_1118 , sizeof( V_16 -> V_88 . V_330 ) ) ;
V_16 -> V_88 . type = V_1093 -> V_88 ;
memcpy ( & V_16 -> V_1119 . V_330 , V_1093 -> V_1120 , sizeof( V_16 -> V_1119 . V_330 ) ) ;
V_1102 = F_17 ( V_16 , V_1121 ) ;
if ( ! ( V_1102 & ( 1 << 8 ) ) )
V_16 -> V_1119 . V_330 . V_206 = & V_1122 ;
memcpy ( & V_16 -> V_333 . V_330 , V_1093 -> V_1123 , sizeof( V_16 -> V_333 . V_330 ) ) ;
V_16 -> V_333 . V_890 = V_1124 ;
V_16 -> V_333 . V_1015 . V_1012 = V_1125 ;
V_16 -> V_333 . V_1015 . V_1126 = 0 ;
V_16 -> V_333 . V_1015 . V_1127 = V_1128 | V_1129 ;
V_16 -> V_333 . V_1015 . V_53 = V_35 ;
V_16 -> V_333 . V_1015 . V_1130 = F_480 ;
V_16 -> V_333 . V_1015 . V_1131 = F_481 ;
V_1093 -> V_1132 ( V_16 ) ;
V_18 = F_330 ( V_2 ) ;
if ( V_18 )
goto V_1133;
if ( V_16 -> V_88 . V_330 . V_1134 )
V_16 -> V_1134 = V_16 -> V_88 . V_330 . V_1134 ( V_16 ) ;
switch ( V_2 -> V_16 . V_88 . type ) {
case V_91 :
case V_92 :
F_51 ( & V_2 -> V_16 , V_709 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_117 & V_336 ) {
T_1 V_618 = F_17 ( V_16 , V_619 ) ;
if ( V_618 & V_620 )
F_181 ( V_149 , L_60 ) ;
}
if ( V_1135 )
V_16 -> V_1135 = V_1135 ;
V_16 -> V_333 . V_1136 = true ;
V_18 = V_16 -> V_88 . V_330 . V_1137 ( V_16 ) ;
V_16 -> V_333 . V_1136 = false ;
if ( V_18 == V_626 &&
V_16 -> V_88 . type == V_89 ) {
V_18 = 0 ;
} else if ( V_18 == V_627 ) {
F_311 ( L_130
L_131 ) ;
F_311 ( L_132
L_133 ) ;
goto V_1133;
} else if ( V_18 ) {
F_311 ( L_134 , V_18 ) ;
goto V_1133;
}
#ifdef F_335
if ( V_2 -> V_16 . V_88 . type == V_89 )
goto V_1138;
F_539 ( V_16 ) ;
memcpy ( & V_16 -> V_1139 . V_330 , V_1093 -> V_1140 , sizeof( V_16 -> V_1139 . V_330 ) ) ;
F_540 ( V_2 ) ;
F_541 ( V_10 , 63 ) ;
V_1138:
#endif
V_35 -> V_173 = V_1141 |
V_1142 |
V_1143 |
V_1144 |
V_245 |
V_1145 |
V_1146 |
V_1147 |
V_174 |
V_186 ;
V_35 -> V_1148 = V_35 -> V_173 ;
switch ( V_2 -> V_16 . V_88 . type ) {
case V_91 :
case V_92 :
V_35 -> V_173 |= V_1149 ;
V_35 -> V_1148 |= V_1149 |
V_1042 ;
break;
default:
break;
}
V_35 -> V_1148 |= V_268 ;
V_35 -> V_1150 |= V_1146 ;
V_35 -> V_1150 |= V_1147 ;
V_35 -> V_1150 |= V_1142 ;
V_35 -> V_1150 |= V_1143 ;
V_35 -> V_1150 |= V_1141 ;
V_35 -> V_1151 |= V_1152 ;
V_35 -> V_1151 |= V_1153 ;
#ifdef F_292
V_35 -> V_1154 = & V_1154 ;
#endif
#ifdef F_129
if ( V_2 -> V_117 & V_657 ) {
unsigned int V_1155 ;
if ( V_16 -> V_88 . V_330 . V_1156 ) {
V_16 -> V_88 . V_330 . V_1156 ( V_16 , & V_1101 ) ;
if ( V_1101 & V_1157 )
V_2 -> V_117 &= ~ V_657 ;
}
V_1155 = F_331 ( int , V_1158 , F_332 () ) ;
V_2 -> V_408 [ V_983 ] . V_650 = V_1155 ;
V_35 -> V_173 |= V_1001 |
V_1002 ;
V_35 -> V_1150 |= V_1001 |
V_1002 |
V_551 ;
}
#endif
if ( V_1097 ) {
V_35 -> V_173 |= V_1159 ;
V_35 -> V_1150 |= V_1159 ;
}
if ( V_2 -> V_131 & V_651 )
V_35 -> V_1148 |= V_1038 ;
if ( V_2 -> V_131 & V_498 )
V_35 -> V_173 |= V_1038 ;
if ( V_16 -> V_1119 . V_330 . V_1160 ( V_16 , NULL ) < 0 ) {
F_311 ( L_135 ) ;
V_18 = - V_695 ;
goto V_1133;
}
memcpy ( V_35 -> V_1010 , V_16 -> V_88 . V_1161 , V_35 -> V_1011 ) ;
if ( ! F_479 ( V_35 -> V_1010 ) ) {
F_311 ( L_136 ) ;
V_18 = - V_695 ;
goto V_1133;
}
F_542 ( & V_2 -> V_621 , & F_423 ,
( unsigned long ) V_2 ) ;
F_543 ( & V_2 -> V_25 , F_425 ) ;
F_14 ( V_24 , & V_2 -> V_23 ) ;
V_18 = F_371 ( V_2 ) ;
if ( V_18 )
goto V_1133;
V_2 -> V_713 = 0 ;
V_16 -> V_1119 . V_330 . V_206 ( V_16 , 0x2c , & V_2 -> V_1070 ) ;
V_16 -> V_1162 = F_522 ( V_2 , V_10 -> V_167 ,
V_10 -> V_648 ) ;
if ( V_16 -> V_1162 )
V_2 -> V_713 = V_1163 ;
F_544 ( & V_2 -> V_10 -> V_53 , V_2 -> V_713 ) ;
V_16 -> V_1119 . V_330 . V_206 ( V_16 , 0x2e , & V_2 -> V_1164 ) ;
V_16 -> V_1119 . V_330 . V_206 ( V_16 , 0x2d , & V_2 -> V_1165 ) ;
V_16 -> V_88 . V_330 . V_1166 ( V_16 ) ;
if ( V_16 -> V_326 == V_1167 )
F_4 ( V_2 ) ;
F_545 ( L_137 ,
( V_16 -> V_11 . V_21 == V_1168 ? L_138 :
V_16 -> V_11 . V_21 == V_1169 ? L_139 :
V_16 -> V_11 . V_21 == V_1170 ? L_140 :
L_141 ) ,
( V_16 -> V_11 . V_20 == V_1171 ? L_142 :
V_16 -> V_11 . V_20 == V_1172 ? L_143 :
V_16 -> V_11 . V_20 == V_1173 ? L_144 :
L_141 ) ,
V_35 -> V_1010 ) ;
V_18 = F_546 ( V_16 , V_1099 , V_1100 ) ;
if ( V_18 )
strncpy ( V_1099 , L_141 , V_1100 ) ;
if ( F_296 ( V_16 ) && V_16 -> V_333 . V_890 != V_1174 )
F_545 ( L_145 ,
V_16 -> V_88 . type , V_16 -> V_333 . type , V_16 -> V_333 . V_890 ,
V_1099 ) ;
else
F_545 ( L_146 ,
V_16 -> V_88 . type , V_16 -> V_333 . type , V_1099 ) ;
if ( V_16 -> V_11 . V_20 <= V_1172 ) {
F_312 ( L_147
L_148 ) ;
F_312 ( L_149
L_150 ) ;
}
V_18 = V_16 -> V_88 . V_330 . V_1175 ( V_16 ) ;
if ( V_18 == V_629 ) {
F_312 ( L_82
L_151
L_152
L_153
L_86
L_87 ) ;
}
strcpy ( V_35 -> V_33 , L_154 ) ;
V_18 = F_547 ( V_35 ) ;
if ( V_18 )
goto V_1176;
if ( V_16 -> V_88 . V_330 . V_637 )
V_16 -> V_88 . V_330 . V_637 ( V_16 ) ;
F_323 ( V_35 ) ;
#ifdef F_200
if ( F_106 ( & V_10 -> V_53 ) == 0 ) {
V_2 -> V_117 |= V_164 ;
F_103 ( V_2 ) ;
}
#endif
if ( V_2 -> V_117 & V_403 ) {
F_85 ( V_149 , L_155 , V_2 -> V_296 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_296 ; V_28 ++ )
F_548 ( V_10 , ( V_28 | 0x10000000 ) ) ;
}
if ( V_16 -> V_88 . V_330 . V_1177 )
V_16 -> V_88 . V_330 . V_1177 ( V_16 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_486 ( V_35 ) ;
F_545 ( L_156 , V_1178 ) ;
V_1096 ++ ;
#ifdef F_549
if ( F_550 ( V_2 ) )
F_83 ( V_149 , L_157 ) ;
#endif
F_551 ( V_2 ) ;
if ( V_16 -> V_1134 && V_16 -> V_88 . V_330 . V_601 )
V_16 -> V_88 . V_330 . V_601 ( V_16 ,
V_857 | V_880 ,
true ) ;
return 0 ;
V_1176:
F_50 ( V_2 ) ;
F_377 ( V_2 ) ;
V_1133:
F_552 ( V_2 ) ;
V_2 -> V_131 &= ~ V_595 ;
F_553 ( V_16 -> V_391 ) ;
V_1113:
F_554 ( V_35 ) ;
V_1108:
F_555 ( V_10 ,
F_529 ( V_10 , V_1106 ) ) ;
V_1107:
V_1105:
F_378 ( V_10 ) ;
return V_18 ;
}
static void F_556 ( struct V_6 * V_10 )
{
struct V_1 * V_2 = F_363 ( V_10 ) ;
struct V_34 * V_35 = V_2 -> V_35 ;
F_557 ( V_2 ) ;
F_217 ( V_22 , & V_2 -> V_23 ) ;
F_558 ( & V_2 -> V_25 ) ;
#ifdef F_200
if ( V_2 -> V_117 & V_164 ) {
V_2 -> V_117 &= ~ V_164 ;
F_107 ( & V_10 -> V_53 ) ;
F_51 ( & V_2 -> V_16 , V_165 , 1 ) ;
}
#endif
#ifdef F_549
F_559 ( V_2 ) ;
#endif
F_488 ( V_35 ) ;
if ( V_35 -> V_891 == V_892 )
F_419 ( V_35 ) ;
#ifdef F_335
if ( V_687 )
F_552 ( V_2 ) ;
#endif
F_377 ( V_2 ) ;
F_50 ( V_2 ) ;
#ifdef F_560
F_207 ( V_2 -> V_116 ) ;
F_207 ( V_2 -> V_556 ) ;
#endif
F_553 ( V_2 -> V_16 . V_391 ) ;
F_555 ( V_10 , F_529 ( V_10 ,
V_1106 ) ) ;
F_545 ( L_158 ) ;
F_554 ( V_35 ) ;
F_561 ( V_10 ) ;
F_378 ( V_10 ) ;
}
static T_16 F_562 ( struct V_6 * V_10 ,
T_17 V_23 )
{
struct V_1 * V_2 = F_363 ( V_10 ) ;
struct V_34 * V_35 = V_2 -> V_35 ;
#ifdef F_335
struct V_6 * V_1179 , * V_1180 ;
T_1 V_1181 , V_1182 , V_1183 , V_1184 ;
int V_893 , V_5 ;
T_2 V_1185 , V_1186 ;
if ( V_2 -> V_16 . V_88 . type == V_89 ||
V_2 -> V_296 == 0 )
goto V_1187;
V_1179 = V_10 -> V_11 -> V_13 ;
while ( V_1179 && ( F_563 ( V_1179 ) != V_1188 ) )
V_1179 = V_1179 -> V_11 -> V_13 ;
if ( ! V_1179 )
goto V_1187;
V_5 = F_564 ( V_1179 , V_1189 ) ;
if ( ! V_5 )
goto V_1187;
F_565 ( V_1179 , V_5 + V_1190 , & V_1181 ) ;
F_565 ( V_1179 , V_5 + V_1190 + 4 , & V_1182 ) ;
F_565 ( V_1179 , V_5 + V_1190 + 8 , & V_1183 ) ;
F_565 ( V_1179 , V_5 + V_1190 + 12 , & V_1184 ) ;
V_1185 = V_1182 >> 16 ;
if ( ! ( V_1185 & 0x0080 ) )
goto V_1187;
V_1186 = V_1185 & 0x01 ;
if ( ( V_1186 & 1 ) == ( V_10 -> V_1191 & 1 ) ) {
unsigned int V_326 ;
V_893 = ( V_1185 & 0x7F ) >> 1 ;
F_311 ( L_159 , V_893 ) ;
F_311 ( L_160
L_161 ,
V_1181 , V_1182 , V_1183 , V_1184 ) ;
switch ( V_2 -> V_16 . V_88 . type ) {
case V_91 :
V_326 = V_1192 ;
break;
case V_92 :
V_326 = V_1193 ;
break;
default:
V_326 = 0 ;
break;
}
V_1180 = F_566 ( V_1194 , V_326 , NULL ) ;
while ( V_1180 ) {
if ( V_1180 -> V_1191 == ( V_1185 & 0xFF ) )
break;
V_1180 = F_566 ( V_1194 ,
V_326 , V_1180 ) ;
}
if ( V_1180 ) {
F_311 ( L_162 , V_893 ) ;
F_567 ( V_1180 , 0xA8 , 0x00008000 ) ;
F_568 ( V_1180 ) ;
}
F_569 ( V_10 ) ;
}
V_2 -> V_1195 ++ ;
return V_1196 ;
V_1187:
#endif
F_376 ( V_35 ) ;
if ( V_23 == V_1197 )
return V_1198 ;
if ( F_37 ( V_35 ) )
F_307 ( V_2 ) ;
F_378 ( V_10 ) ;
return V_1199 ;
}
static T_16 F_570 ( struct V_6 * V_10 )
{
struct V_1 * V_2 = F_363 ( V_10 ) ;
T_16 V_1200 ;
int V_18 ;
if ( F_367 ( V_10 ) ) {
F_83 ( V_149 , L_163 ) ;
V_1200 = V_1198 ;
} else {
F_368 ( V_10 ) ;
F_365 ( V_10 ) ;
F_366 ( V_10 ) ;
F_369 ( V_10 , false ) ;
F_310 ( V_2 ) ;
F_51 ( & V_2 -> V_16 , V_709 , ~ 0 ) ;
V_1200 = V_1196 ;
}
V_18 = F_569 ( V_10 ) ;
if ( V_18 ) {
F_311 ( L_164
L_165 , V_18 ) ;
}
return V_1200 ;
}
static void F_571 ( struct V_6 * V_10 )
{
struct V_1 * V_2 = F_363 ( V_10 ) ;
struct V_34 * V_35 = V_2 -> V_35 ;
#ifdef F_335
if ( V_2 -> V_1195 ) {
F_85 ( V_133 , L_166 ) ;
V_2 -> V_1195 -- ;
return;
}
#endif
if ( F_37 ( V_35 ) )
F_309 ( V_2 ) ;
F_373 ( V_35 ) ;
}
static int T_18 F_572 ( void )
{
int V_130 ;
F_31 ( L_167 , V_1201 , V_1202 ) ;
F_31 ( L_156 , V_1203 ) ;
F_573 () ;
V_130 = F_574 ( & V_1204 ) ;
if ( V_130 ) {
F_575 () ;
return V_130 ;
}
#ifdef F_200
F_576 ( & V_1205 ) ;
#endif
return 0 ;
}
static void T_19 F_577 ( void )
{
#ifdef F_200
F_578 ( & V_1205 ) ;
#endif
F_579 ( & V_1204 ) ;
F_575 () ;
F_580 () ;
}
static int F_581 ( struct V_1206 * V_1207 , unsigned long V_168 ,
void * V_456 )
{
int V_1208 ;
V_1208 = F_582 ( & V_1204 . V_1209 , NULL , & V_168 ,
F_104 ) ;
return V_1208 ? V_1210 : V_1211 ;
}
