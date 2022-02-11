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
if ( F_143 ( V_135 ) )
F_144 ( V_69 ) ;
else if ( ! ( V_2 -> V_117 & V_248 ) )
F_145 ( & V_135 -> V_249 , V_69 ) ;
else
F_146 ( V_69 ) ;
}
static bool F_147 ( struct V_37 * V_47 ,
union V_48 * V_49 ,
struct V_172 * V_69 )
{
T_1 V_250 = V_47 -> V_59 + 1 ;
V_250 = ( V_250 < V_47 -> V_68 ) ? V_250 : 0 ;
V_47 -> V_59 = V_250 ;
F_78 ( F_46 ( V_47 , V_250 ) ) ;
if ( F_148 ( V_47 ) ) {
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
static void F_149 ( struct V_37 * V_47 ,
struct V_172 * V_69 )
{
struct V_259 * V_260 = & F_132 ( V_69 ) -> V_261 [ 0 ] ;
unsigned char * V_262 ;
unsigned int V_263 ;
V_262 = F_150 ( V_260 ) ;
V_263 = F_126 ( V_262 , V_264 ) ;
F_151 ( V_69 , V_262 , F_152 ( V_263 , sizeof( long ) ) ) ;
F_153 ( V_260 , V_263 ) ;
V_260 -> V_79 += V_263 ;
V_69 -> V_265 -= V_263 ;
V_69 -> V_125 += V_263 ;
}
static void F_154 ( struct V_37 * V_47 ,
struct V_172 * V_69 )
{
if ( F_77 ( F_134 ( V_69 ) -> V_266 ) ) {
F_60 ( V_47 -> V_53 , F_134 ( V_69 ) -> V_61 ,
F_121 ( V_47 ) , V_204 ) ;
F_134 ( V_69 ) -> V_266 = false ;
} else {
struct V_259 * V_260 = & F_132 ( V_69 ) -> V_261 [ 0 ] ;
F_155 ( V_47 -> V_53 ,
F_134 ( V_69 ) -> V_61 ,
V_260 -> V_79 ,
F_49 ( V_47 ) ,
V_204 ) ;
}
F_134 ( V_69 ) -> V_61 = 0 ;
}
static bool F_156 ( struct V_37 * V_47 ,
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
if ( F_157 ( V_69 ) )
F_149 ( V_47 , V_69 ) ;
#ifdef F_129
if ( F_109 ( V_47 , V_49 ) )
return false ;
#endif
if ( F_77 ( V_69 -> V_62 < 60 ) ) {
int V_269 = 60 - V_69 -> V_62 ;
if ( F_158 ( V_69 , V_269 ) )
return true ;
F_159 ( V_69 , V_269 ) ;
}
return false ;
}
static void F_160 ( struct V_37 * V_47 ,
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
F_161 ( V_47 -> V_53 , V_271 -> V_61 ,
V_271 -> V_79 ,
F_49 ( V_47 ) ,
V_204 ) ;
}
static bool F_162 ( struct V_37 * V_47 ,
struct V_50 * V_273 ,
union V_48 * V_49 ,
struct V_172 * V_69 )
{
struct V_78 * V_78 = V_273 -> V_78 ;
unsigned int V_274 = F_138 ( V_49 -> V_74 . V_75 . V_275 ) ;
#if ( V_276 < 8192 )
unsigned int V_277 = F_49 ( V_47 ) ;
#else
unsigned int V_277 = F_152 ( V_274 , V_278 ) ;
unsigned int V_279 = F_121 ( V_47 ) -
F_49 ( V_47 ) ;
#endif
if ( ( V_274 <= V_264 ) && ! F_157 ( V_69 ) ) {
unsigned char * V_262 = F_48 ( V_78 ) + V_273 -> V_79 ;
memcpy ( F_159 ( V_69 , V_274 ) , V_262 , F_152 ( V_274 , sizeof( long ) ) ) ;
if ( F_79 ( F_163 ( V_78 ) == F_164 () ) )
return true ;
F_165 ( V_78 ) ;
return false ;
}
F_166 ( V_69 , F_132 ( V_69 ) -> V_280 , V_78 ,
V_273 -> V_79 , V_274 , V_277 ) ;
if ( F_77 ( F_163 ( V_78 ) != F_164 () ) )
return false ;
#if ( V_276 < 8192 )
if ( F_77 ( F_167 ( V_78 ) != 1 ) )
return false ;
V_273 -> V_79 ^= V_277 ;
F_168 ( & V_78 -> V_281 , 2 ) ;
#else
V_273 -> V_79 += V_277 ;
if ( V_273 -> V_79 > V_279 )
return false ;
F_169 ( V_78 ) ;
#endif
return true ;
}
static struct V_172 * F_170 ( struct V_37 * V_47 ,
union V_48 * V_49 )
{
struct V_50 * V_273 ;
struct V_172 * V_69 ;
struct V_78 * V_78 ;
V_273 = & V_47 -> V_51 [ V_47 -> V_59 ] ;
V_78 = V_273 -> V_78 ;
F_171 ( V_78 ) ;
V_69 = V_273 -> V_69 ;
if ( F_79 ( ! V_69 ) ) {
void * V_282 = F_48 ( V_78 ) +
V_273 -> V_79 ;
F_78 ( V_282 ) ;
#if V_278 < 128
F_78 ( V_282 + V_278 ) ;
#endif
V_69 = F_172 ( V_47 -> V_35 ,
V_264 ) ;
if ( F_77 ( ! V_69 ) ) {
V_47 -> V_189 . V_283 ++ ;
return NULL ;
}
F_171 ( V_69 -> V_72 ) ;
if ( F_79 ( F_113 ( V_49 , V_257 ) ) )
goto V_284;
F_134 ( V_69 ) -> V_61 = V_273 -> V_61 ;
} else {
if ( F_113 ( V_49 , V_257 ) )
F_154 ( V_47 , V_69 ) ;
V_284:
F_155 ( V_47 -> V_53 ,
V_273 -> V_61 ,
V_273 -> V_79 ,
F_49 ( V_47 ) ,
V_204 ) ;
}
if ( F_162 ( V_47 , V_273 , V_49 , V_69 ) ) {
F_160 ( V_47 , V_273 ) ;
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
static int F_173 ( struct V_134 * V_135 ,
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
F_174 () ;
V_69 = F_170 ( V_47 , V_49 ) ;
if ( ! V_69 )
break;
V_205 ++ ;
if ( F_147 ( V_47 , V_49 , V_69 ) )
continue;
if ( F_156 ( V_47 , V_49 , V_69 ) )
continue;
V_285 += V_69 -> V_62 ;
F_136 ( V_47 , V_49 , V_69 ) ;
#ifdef F_129
if ( F_109 ( V_47 , V_49 ) ) {
V_287 = F_175 ( V_2 , V_49 , V_69 ) ;
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
F_176 ( V_69 , & V_135 -> V_249 ) ;
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
return V_286 ;
}
static int F_177 ( struct V_295 * V_249 )
{
struct V_134 * V_135 =
F_178 ( V_249 , struct V_134 , V_249 ) ;
struct V_1 * V_2 = V_135 -> V_2 ;
struct V_37 * V_98 ;
int V_296 = 0 ;
if ( F_8 ( V_22 , & V_2 -> V_23 ) )
return V_297 ;
if ( ! F_179 ( V_135 ) )
return V_298 ;
F_101 (ring, q_vector->rx) {
V_296 = F_173 ( V_135 , V_98 , 4 ) ;
#ifdef F_180
if ( V_296 )
V_98 -> V_102 . V_299 += V_296 ;
else
V_98 -> V_102 . V_300 ++ ;
#endif
if ( V_296 )
break;
}
F_181 ( V_135 ) ;
return V_296 ;
}
static void F_182 ( struct V_1 * V_2 )
{
struct V_134 * V_135 ;
int V_301 ;
T_1 V_95 ;
if ( V_2 -> V_302 > 32 ) {
T_1 V_303 = ( 1 << ( V_2 -> V_302 - 32 ) ) - 1 ;
F_51 ( & V_2 -> V_16 , V_304 , V_303 ) ;
}
for ( V_301 = 0 ; V_301 < V_2 -> V_166 ; V_301 ++ ) {
struct V_37 * V_98 ;
V_135 = V_2 -> V_135 [ V_301 ] ;
F_101 (ring, q_vector->rx)
F_53 ( V_2 , 0 , V_98 -> V_124 , V_301 ) ;
F_101 (ring, q_vector->tx)
F_53 ( V_2 , 1 , V_98 -> V_124 , V_301 ) ;
F_183 ( V_135 ) ;
}
switch ( V_2 -> V_16 . V_88 . type ) {
case V_89 :
F_53 ( V_2 , - 1 , V_305 ,
V_301 ) ;
break;
case V_91 :
case V_92 :
F_53 ( V_2 , - 1 , 1 , V_301 ) ;
break;
default:
break;
}
F_51 ( & V_2 -> V_16 , F_184 ( V_301 ) , 1950 ) ;
V_95 = V_306 ;
V_95 &= ~ ( V_307 |
V_308 |
V_309 ) ;
F_51 ( & V_2 -> V_16 , V_310 , V_95 ) ;
}
static void F_185 ( struct V_134 * V_135 ,
struct V_311 * V_312 )
{
int V_147 = V_312 -> V_136 ;
int V_122 = V_312 -> V_137 ;
T_1 V_313 ;
T_4 V_314 ;
T_6 V_315 = V_312 -> V_316 ;
if ( V_122 == 0 )
return;
V_313 = V_135 -> V_316 >> 2 ;
if ( V_313 == 0 )
return;
V_314 = V_147 / V_313 ;
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
V_312 -> V_136 = 0 ;
V_312 -> V_137 = 0 ;
V_312 -> V_316 = V_315 ;
}
void F_183 ( struct V_134 * V_135 )
{
struct V_1 * V_2 = V_135 -> V_2 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_301 = V_135 -> V_301 ;
T_1 V_320 = V_135 -> V_316 & V_321 ;
switch ( V_2 -> V_16 . V_88 . type ) {
case V_89 :
V_320 |= ( V_320 << 16 ) ;
break;
case V_91 :
case V_92 :
V_320 |= V_322 ;
break;
default:
break;
}
F_51 ( V_16 , F_184 ( V_301 ) , V_320 ) ;
}
static void F_186 ( struct V_134 * V_135 )
{
T_1 V_323 = V_135 -> V_316 ;
T_6 V_324 ;
F_185 ( V_135 , & V_135 -> V_139 ) ;
F_185 ( V_135 , & V_135 -> V_294 ) ;
V_324 = F_187 ( V_135 -> V_294 . V_316 , V_135 -> V_139 . V_316 ) ;
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
if ( V_323 != V_135 -> V_316 ) {
V_323 = ( 10 * V_323 * V_135 -> V_316 ) /
( ( 9 * V_323 ) + V_135 -> V_316 ) ;
V_135 -> V_316 = V_323 ;
F_183 ( V_135 ) ;
}
}
static void F_188 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_328 = V_2 -> V_329 ;
if ( F_8 ( V_22 , & V_2 -> V_23 ) )
return;
if ( ! ( V_2 -> V_131 & V_330 ) &&
! ( V_2 -> V_131 & V_331 ) )
return;
V_2 -> V_131 &= ~ V_331 ;
switch ( V_16 -> V_332 ) {
case V_333 :
if ( ! ( V_328 & V_334 ) &&
! ( V_328 & V_335 ) )
return;
if ( ! ( V_328 & V_335 ) && V_16 -> V_88 . V_336 . V_337 ) {
T_1 V_21 ;
bool V_338 = false ;
V_16 -> V_88 . V_336 . V_337 ( V_16 , & V_21 , & V_338 , false ) ;
if ( V_338 )
return;
}
if ( V_16 -> V_339 . V_336 . V_340 ( V_16 ) != V_341 )
return;
break;
default:
if ( ! ( V_328 & V_334 ) )
return;
break;
}
F_189 ( V_133 ,
L_57
L_58
L_59 ) ;
V_2 -> V_329 = 0 ;
}
static void F_190 ( struct V_1 * V_2 , T_1 V_328 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
if ( ( V_2 -> V_117 & V_342 ) &&
( V_328 & V_343 ) ) {
F_189 ( V_149 , L_60 ) ;
F_51 ( V_16 , V_344 , V_343 ) ;
}
}
static void F_191 ( struct V_1 * V_2 , T_1 V_328 )
{
if ( ! ( V_2 -> V_131 & V_330 ) )
return;
switch ( V_2 -> V_16 . V_88 . type ) {
case V_91 :
if ( ( ( V_328 & V_334 ) || ( V_328 & V_335 ) ) &&
( ! F_8 ( V_22 , & V_2 -> V_23 ) ) ) {
V_2 -> V_329 = V_328 ;
V_2 -> V_131 |= V_331 ;
F_7 ( V_2 ) ;
return;
}
return;
case V_92 :
if ( ! ( V_328 & V_345 ) )
return;
break;
default:
return;
}
F_189 ( V_133 ,
L_57
L_58
L_59 ) ;
}
static void F_192 ( struct V_1 * V_2 , T_1 V_328 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
if ( V_328 & V_346 ) {
F_51 ( V_16 , V_344 , V_346 ) ;
if ( ! F_8 ( V_22 , & V_2 -> V_23 ) ) {
V_2 -> V_131 |= V_347 ;
F_7 ( V_2 ) ;
}
}
if ( V_328 & V_343 ) {
F_51 ( V_16 , V_344 , V_343 ) ;
if ( ! F_8 ( V_22 , & V_2 -> V_23 ) ) {
V_2 -> V_117 |= V_348 ;
F_7 ( V_2 ) ;
}
}
}
static void F_193 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
V_2 -> V_349 ++ ;
V_2 -> V_117 |= V_350 ;
V_2 -> V_351 = V_148 ;
if ( ! F_8 ( V_22 , & V_2 -> V_23 ) ) {
F_51 ( V_16 , V_352 , V_353 ) ;
F_194 ( V_16 ) ;
F_7 ( V_2 ) ;
}
}
static inline void F_195 ( struct V_1 * V_2 ,
T_4 V_94 )
{
T_1 V_95 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_95 = ( V_96 & V_94 ) ;
F_51 ( V_16 , V_354 , V_95 ) ;
break;
case V_91 :
case V_92 :
V_95 = ( V_94 & 0xFFFFFFFF ) ;
if ( V_95 )
F_51 ( V_16 , F_196 ( 0 ) , V_95 ) ;
V_95 = ( V_94 >> 32 ) ;
if ( V_95 )
F_51 ( V_16 , F_196 ( 1 ) , V_95 ) ;
break;
default:
break;
}
}
static inline void F_197 ( struct V_1 * V_2 ,
T_4 V_94 )
{
T_1 V_95 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_95 = ( V_96 & V_94 ) ;
F_51 ( V_16 , V_352 , V_95 ) ;
break;
case V_91 :
case V_92 :
V_95 = ( V_94 & 0xFFFFFFFF ) ;
if ( V_95 )
F_51 ( V_16 , F_198 ( 0 ) , V_95 ) ;
V_95 = ( V_94 >> 32 ) ;
if ( V_95 )
F_51 ( V_16 , F_198 ( 1 ) , V_95 ) ;
break;
default:
break;
}
}
static inline void F_199 ( struct V_1 * V_2 , bool V_355 ,
bool V_356 )
{
T_1 V_95 = ( V_306 & ~ V_96 ) ;
if ( V_2 -> V_117 & V_350 )
V_95 &= ~ V_309 ;
if ( V_2 -> V_131 & V_330 )
switch ( V_2 -> V_16 . V_88 . type ) {
case V_91 :
V_95 |= V_357 ;
break;
case V_92 :
V_95 |= V_358 ;
break;
default:
break;
}
if ( V_2 -> V_117 & V_342 )
V_95 |= V_359 ;
switch ( V_2 -> V_16 . V_88 . type ) {
case V_91 :
V_95 |= V_359 ;
V_95 |= V_360 ;
case V_92 :
V_95 |= V_361 ;
V_95 |= V_308 ;
break;
default:
break;
}
if ( V_2 -> V_16 . V_88 . type == V_92 )
V_95 |= V_362 ;
if ( ( V_2 -> V_117 & V_363 ) &&
! ( V_2 -> V_131 & V_364 ) )
V_95 |= V_365 ;
F_51 ( & V_2 -> V_16 , V_354 , V_95 ) ;
if ( V_355 )
F_195 ( V_2 , ~ 0 ) ;
if ( V_356 )
F_194 ( & V_2 -> V_16 ) ;
}
static T_11 F_200 ( int V_366 , void * V_72 )
{
struct V_1 * V_2 = V_72 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_328 ;
V_328 = F_17 ( V_16 , V_97 ) ;
V_328 &= 0xFFFF0000 ;
F_51 ( V_16 , V_344 , V_328 ) ;
if ( V_328 & V_335 )
F_193 ( V_2 ) ;
if ( V_328 & V_367 )
F_201 ( V_2 ) ;
switch ( V_16 -> V_88 . type ) {
case V_91 :
case V_92 :
if ( V_328 & V_368 )
F_85 ( V_369 , L_61
L_62 ) ;
if ( V_328 & V_370 ) {
int V_371 = 0 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ ) {
struct V_37 * V_98 = V_2 -> V_38 [ V_28 ] ;
if ( F_202 ( V_372 ,
& V_98 -> V_23 ) )
V_371 ++ ;
}
if ( V_371 ) {
F_51 ( V_16 , V_352 , V_373 ) ;
V_2 -> V_131 |= V_364 ;
F_7 ( V_2 ) ;
}
}
F_192 ( V_2 , V_328 ) ;
F_191 ( V_2 , V_328 ) ;
break;
default:
break;
}
F_190 ( V_2 , V_328 ) ;
if ( F_77 ( V_328 & V_374 ) )
F_203 ( V_2 , V_328 ) ;
if ( ! F_8 ( V_22 , & V_2 -> V_23 ) )
F_199 ( V_2 , false , false ) ;
return V_375 ;
}
static T_11 F_204 ( int V_366 , void * V_72 )
{
struct V_134 * V_135 = V_72 ;
if ( V_135 -> V_294 . V_98 || V_135 -> V_139 . V_98 )
F_205 ( & V_135 -> V_249 ) ;
return V_375 ;
}
int F_206 ( struct V_295 * V_249 , int V_138 )
{
struct V_134 * V_135 =
F_178 ( V_249 , struct V_134 , V_249 ) ;
struct V_1 * V_2 = V_135 -> V_2 ;
struct V_37 * V_98 ;
int V_376 ;
bool V_377 = true ;
#ifdef F_207
if ( V_2 -> V_117 & V_164 )
F_99 ( V_135 ) ;
#endif
F_101 (ring, q_vector->tx)
V_377 &= ! ! F_74 ( V_135 , V_98 ) ;
if ( ! F_208 ( V_135 ) )
return V_138 ;
if ( V_135 -> V_294 . V_68 > 1 )
V_376 = F_187 ( V_138 / V_135 -> V_294 . V_68 , 1 ) ;
else
V_376 = V_138 ;
F_101 (ring, q_vector->rx)
V_377 &= ( F_173 ( V_135 , V_98 ,
V_376 ) < V_376 ) ;
F_209 ( V_135 ) ;
if ( ! V_377 )
return V_138 ;
F_210 ( V_249 ) ;
if ( V_2 -> V_378 & 1 )
F_186 ( V_135 ) ;
if ( ! F_8 ( V_22 , & V_2 -> V_23 ) )
F_195 ( V_2 , ( ( T_4 ) 1 << V_135 -> V_301 ) ) ;
return 0 ;
}
static int F_211 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
int V_379 , V_18 ;
int V_380 = 0 , V_381 = 0 ;
for ( V_379 = 0 ; V_379 < V_2 -> V_166 ; V_379 ++ ) {
struct V_134 * V_135 = V_2 -> V_135 [ V_379 ] ;
struct V_382 * V_383 = & V_2 -> V_384 [ V_379 ] ;
if ( V_135 -> V_139 . V_98 && V_135 -> V_294 . V_98 ) {
snprintf ( V_135 -> V_33 , sizeof( V_135 -> V_33 ) - 1 ,
L_63 , V_35 -> V_33 , L_64 , V_380 ++ ) ;
V_381 ++ ;
} else if ( V_135 -> V_294 . V_98 ) {
snprintf ( V_135 -> V_33 , sizeof( V_135 -> V_33 ) - 1 ,
L_63 , V_35 -> V_33 , L_65 , V_380 ++ ) ;
} else if ( V_135 -> V_139 . V_98 ) {
snprintf ( V_135 -> V_33 , sizeof( V_135 -> V_33 ) - 1 ,
L_63 , V_35 -> V_33 , L_66 , V_381 ++ ) ;
} else {
continue;
}
V_18 = F_212 ( V_383 -> V_379 , & F_204 , 0 ,
V_135 -> V_33 , V_135 ) ;
if ( V_18 ) {
F_83 ( V_149 , L_67
L_68 , V_18 ) ;
goto V_385;
}
if ( V_2 -> V_117 & V_363 ) {
F_213 ( V_383 -> V_379 ,
& V_135 -> V_386 ) ;
}
}
V_18 = F_212 ( V_2 -> V_384 [ V_379 ] . V_379 ,
F_200 , 0 , V_35 -> V_33 , V_2 ) ;
if ( V_18 ) {
F_83 ( V_149 , L_69 , V_18 ) ;
goto V_385;
}
return 0 ;
V_385:
while ( V_379 ) {
V_379 -- ;
F_213 ( V_2 -> V_384 [ V_379 ] . V_379 ,
NULL ) ;
F_214 ( V_2 -> V_384 [ V_379 ] . V_379 ,
V_2 -> V_135 [ V_379 ] ) ;
}
V_2 -> V_117 &= ~ V_387 ;
F_215 ( V_2 -> V_10 ) ;
F_216 ( V_2 -> V_384 ) ;
V_2 -> V_384 = NULL ;
return V_18 ;
}
static T_11 F_217 ( int V_366 , void * V_72 )
{
struct V_1 * V_2 = V_72 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_134 * V_135 = V_2 -> V_135 [ 0 ] ;
T_1 V_328 ;
F_51 ( V_16 , V_352 , V_388 ) ;
V_328 = F_17 ( V_16 , V_344 ) ;
if ( ! V_328 ) {
if ( ! F_8 ( V_22 , & V_2 -> V_23 ) )
F_199 ( V_2 , true , true ) ;
return V_389 ;
}
if ( V_328 & V_335 )
F_193 ( V_2 ) ;
switch ( V_16 -> V_88 . type ) {
case V_91 :
F_192 ( V_2 , V_328 ) ;
case V_92 :
if ( V_328 & V_368 )
F_85 ( V_369 , L_70
L_62 ) ;
F_191 ( V_2 , V_328 ) ;
break;
default:
break;
}
F_190 ( V_2 , V_328 ) ;
if ( F_77 ( V_328 & V_374 ) )
F_203 ( V_2 , V_328 ) ;
F_205 ( & V_135 -> V_249 ) ;
if ( ! F_8 ( V_22 , & V_2 -> V_23 ) )
F_199 ( V_2 , false , false ) ;
return V_375 ;
}
static int F_218 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
int V_18 ;
if ( V_2 -> V_117 & V_387 )
V_18 = F_211 ( V_2 ) ;
else if ( V_2 -> V_117 & V_390 )
V_18 = F_212 ( V_2 -> V_10 -> V_366 , F_217 , 0 ,
V_35 -> V_33 , V_2 ) ;
else
V_18 = F_212 ( V_2 -> V_10 -> V_366 , F_217 , V_391 ,
V_35 -> V_33 , V_2 ) ;
if ( V_18 )
F_83 ( V_149 , L_71 , V_18 ) ;
return V_18 ;
}
static void F_219 ( struct V_1 * V_2 )
{
int V_379 ;
if ( ! ( V_2 -> V_117 & V_387 ) ) {
F_214 ( V_2 -> V_10 -> V_366 , V_2 ) ;
return;
}
for ( V_379 = 0 ; V_379 < V_2 -> V_166 ; V_379 ++ ) {
struct V_134 * V_135 = V_2 -> V_135 [ V_379 ] ;
struct V_382 * V_383 = & V_2 -> V_384 [ V_379 ] ;
if ( ! V_135 -> V_294 . V_98 && ! V_135 -> V_139 . V_98 )
continue;
F_213 ( V_383 -> V_379 , NULL ) ;
F_214 ( V_383 -> V_379 , V_135 ) ;
}
F_214 ( V_2 -> V_384 [ V_379 ++ ] . V_379 , V_2 ) ;
}
static inline void F_220 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_16 . V_88 . type ) {
case V_89 :
F_51 ( & V_2 -> V_16 , V_352 , ~ 0 ) ;
break;
case V_91 :
case V_92 :
F_51 ( & V_2 -> V_16 , V_352 , 0xFFFF0000 ) ;
F_51 ( & V_2 -> V_16 , F_198 ( 0 ) , ~ 0 ) ;
F_51 ( & V_2 -> V_16 , F_198 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_194 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_117 & V_387 ) {
int V_379 ;
for ( V_379 = 0 ; V_379 < V_2 -> V_166 ; V_379 ++ )
F_221 ( V_2 -> V_384 [ V_379 ] . V_379 ) ;
F_221 ( V_2 -> V_384 [ V_379 ++ ] . V_379 ) ;
} else {
F_221 ( V_2 -> V_10 -> V_366 ) ;
}
}
static void F_222 ( struct V_1 * V_2 )
{
struct V_134 * V_135 = V_2 -> V_135 [ 0 ] ;
F_183 ( V_135 ) ;
F_53 ( V_2 , 0 , 0 , 0 ) ;
F_53 ( V_2 , 1 , 0 , 0 ) ;
F_85 ( V_16 , L_72 ) ;
}
void F_223 ( struct V_1 * V_2 ,
struct V_37 * V_98 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_4 V_392 = V_98 -> V_61 ;
int V_393 = 10 ;
T_1 V_394 = V_395 ;
T_6 V_124 = V_98 -> V_124 ;
F_51 ( V_16 , F_30 ( V_124 ) , 0 ) ;
F_194 ( V_16 ) ;
F_51 ( V_16 , F_25 ( V_124 ) ,
( V_392 & F_224 ( 32 ) ) ) ;
F_51 ( V_16 , F_26 ( V_124 ) , ( V_392 >> 32 ) ) ;
F_51 ( V_16 , F_27 ( V_124 ) ,
V_98 -> V_68 * sizeof( union V_41 ) ) ;
F_51 ( V_16 , F_28 ( V_124 ) , 0 ) ;
F_51 ( V_16 , F_29 ( V_124 ) , 0 ) ;
V_98 -> V_125 = V_16 -> V_396 + F_29 ( V_124 ) ;
#if F_225 ( V_397 )
if ( ! V_98 -> V_135 || ( V_98 -> V_135 -> V_316 < V_325 ) )
#else
if ( ! V_98 -> V_135 || ( V_98 -> V_135 -> V_316 < 8 ) )
#endif
V_394 |= ( 1 << 16 ) ;
else
V_394 |= ( 8 << 16 ) ;
V_394 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_117 & V_363 ) {
V_98 -> V_398 = V_2 -> V_398 ;
V_98 -> V_399 = 0 ;
F_226 ( V_372 , & V_98 -> V_23 ) ;
} else {
V_98 -> V_398 = 0 ;
}
if ( ! F_9 ( V_400 , & V_98 -> V_23 ) ) {
struct V_134 * V_135 = V_98 -> V_135 ;
if ( V_135 )
F_227 ( V_2 -> V_35 ,
& V_135 -> V_386 ,
V_98 -> V_66 ) ;
}
F_14 ( V_110 , & V_98 -> V_23 ) ;
F_51 ( V_16 , F_30 ( V_124 ) , V_394 ) ;
if ( V_16 -> V_88 . type == V_89 &&
! ( F_17 ( V_16 , V_401 ) & V_402 ) )
return;
do {
F_228 ( 1000 , 2000 ) ;
V_394 = F_17 ( V_16 , F_30 ( V_124 ) ) ;
} while ( -- V_393 && ! ( V_394 & V_395 ) );
if ( ! V_393 )
F_83 ( V_133 , L_73 , V_124 ) ;
}
static void F_229 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_403 , V_404 ;
T_6 V_405 = F_230 ( V_2 -> V_35 ) ;
if ( V_16 -> V_88 . type == V_89 )
return;
V_403 = F_17 ( V_16 , V_406 ) ;
V_403 |= V_407 ;
F_51 ( V_16 , V_406 , V_403 ) ;
if ( V_2 -> V_117 & V_408 ) {
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
F_51 ( V_16 , V_419 , V_404 ) ;
if ( V_405 ) {
T_1 V_420 = F_17 ( V_16 , V_421 ) ;
V_420 |= V_422 ;
F_51 ( V_16 , V_421 , V_420 ) ;
}
V_403 &= ~ V_407 ;
F_51 ( V_16 , V_406 , V_403 ) ;
}
static void F_231 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_423 ;
T_1 V_28 ;
F_229 ( V_2 ) ;
if ( V_16 -> V_88 . type != V_89 ) {
V_423 = F_17 ( V_16 , V_424 ) ;
V_423 |= V_425 ;
F_51 ( V_16 , V_424 , V_423 ) ;
}
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ )
F_223 ( V_2 , V_2 -> V_38 [ V_28 ] ) ;
}
static void F_232 ( struct V_1 * V_2 ,
struct V_37 * V_98 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_6 V_124 = V_98 -> V_124 ;
T_1 V_426 = F_17 ( V_16 , F_16 ( V_124 ) ) ;
V_426 |= V_427 ;
F_51 ( V_16 , F_16 ( V_124 ) , V_426 ) ;
}
static void F_233 ( struct V_1 * V_2 ,
struct V_37 * V_98 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_6 V_124 = V_98 -> V_124 ;
T_1 V_426 = F_17 ( V_16 , F_16 ( V_124 ) ) ;
V_426 &= ~ V_427 ;
F_51 ( V_16 , F_16 ( V_124 ) , V_426 ) ;
}
static void F_234 ( struct V_1 * V_2 ,
struct V_37 * V_47 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_426 ;
T_6 V_124 = V_47 -> V_124 ;
if ( V_16 -> V_88 . type == V_89 ) {
T_2 V_95 = V_2 -> V_413 [ V_414 ] . V_95 ;
V_124 &= V_95 ;
}
V_426 = V_264 << V_428 ;
V_426 |= F_49 ( V_47 ) >> V_429 ;
V_426 |= V_430 ;
F_51 ( V_16 , F_16 ( V_124 ) , V_426 ) ;
}
static void F_235 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
static const T_1 V_431 [ 10 ] = { 0xE291D73D , 0x1805EC6C , 0x2A94B30D ,
0xA54F2BEC , 0xEA49AF7C , 0xE214AD3D , 0xB855AABE ,
0x6A3E67EA , 0x14364D17 , 0x3BED200D } ;
T_1 V_432 = 0 , V_433 = 0 ;
T_1 V_434 ;
int V_28 , V_29 ;
T_2 V_435 = V_2 -> V_413 [ V_414 ] . V_415 ;
if ( ( V_2 -> V_117 & V_408 ) && ( V_435 < 2 ) )
V_435 = 2 ;
for ( V_28 = 0 ; V_28 < 10 ; V_28 ++ )
F_51 ( V_16 , F_236 ( V_28 ) , V_431 [ V_28 ] ) ;
for ( V_28 = 0 , V_29 = 0 ; V_28 < 128 ; V_28 ++ , V_29 ++ ) {
if ( V_29 == V_435 )
V_29 = 0 ;
V_433 = ( V_433 << 8 ) | ( V_29 * 0x11 ) ;
if ( ( V_28 & 3 ) == 3 )
F_51 ( V_16 , F_237 ( V_28 >> 2 ) , V_433 ) ;
}
V_434 = F_17 ( V_16 , V_436 ) ;
V_434 |= V_437 ;
F_51 ( V_16 , V_436 , V_434 ) ;
if ( V_2 -> V_16 . V_88 . type == V_89 ) {
if ( V_2 -> V_413 [ V_414 ] . V_95 )
V_432 = V_438 ;
} else {
T_6 V_405 = F_230 ( V_2 -> V_35 ) ;
if ( V_2 -> V_117 & V_408 ) {
if ( V_405 > 4 )
V_432 = V_439 ;
else if ( V_405 > 1 )
V_432 = V_440 ;
else if ( V_2 -> V_413 [ V_414 ] . V_415 == 4 )
V_432 = V_441 ;
else
V_432 = V_442 ;
} else {
if ( V_405 > 4 )
V_432 = V_443 ;
else if ( V_405 > 1 )
V_432 = V_444 ;
else
V_432 = V_438 ;
}
}
V_432 |= V_445 |
V_446 |
V_447 |
V_448 ;
if ( V_2 -> V_131 & V_449 )
V_432 |= V_450 ;
if ( V_2 -> V_131 & V_451 )
V_432 |= V_452 ;
F_51 ( V_16 , V_453 , V_432 ) ;
}
static void F_238 ( struct V_1 * V_2 ,
struct V_37 * V_98 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_454 ;
T_6 V_124 = V_98 -> V_124 ;
if ( ! F_148 ( V_98 ) )
return;
V_454 = F_17 ( V_16 , F_239 ( V_124 ) ) ;
V_454 |= V_455 ;
V_454 |= V_456 ;
F_51 ( V_16 , F_239 ( V_124 ) , V_454 ) ;
}
static void F_240 ( struct V_1 * V_2 ,
struct V_37 * V_98 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_393 = V_457 ;
T_1 V_458 ;
T_6 V_124 = V_98 -> V_124 ;
if ( V_16 -> V_88 . type == V_89 &&
! ( F_17 ( V_16 , V_401 ) & V_402 ) )
return;
do {
F_228 ( 1000 , 2000 ) ;
V_458 = F_17 ( V_16 , F_22 ( V_124 ) ) ;
} while ( -- V_393 && ! ( V_458 & V_459 ) );
if ( ! V_393 ) {
F_83 ( V_133 , L_74
L_75 , V_124 ) ;
}
}
void F_241 ( struct V_1 * V_2 ,
struct V_37 * V_98 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_393 = V_457 ;
T_1 V_458 ;
T_6 V_124 = V_98 -> V_124 ;
V_458 = F_17 ( V_16 , F_22 ( V_124 ) ) ;
V_458 &= ~ V_459 ;
F_51 ( V_16 , F_22 ( V_124 ) , V_458 ) ;
if ( V_16 -> V_88 . type == V_89 &&
! ( F_17 ( V_16 , V_401 ) & V_402 ) )
return;
do {
F_242 ( 10 ) ;
V_458 = F_17 ( V_16 , F_22 ( V_124 ) ) ;
} while ( -- V_393 && ( V_458 & V_459 ) );
if ( ! V_393 ) {
F_83 ( V_133 , L_76
L_75 , V_124 ) ;
}
}
void F_243 ( struct V_1 * V_2 ,
struct V_37 * V_98 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_4 V_460 = V_98 -> V_61 ;
T_1 V_458 ;
T_6 V_124 = V_98 -> V_124 ;
V_458 = F_17 ( V_16 , F_22 ( V_124 ) ) ;
F_241 ( V_2 , V_98 ) ;
F_51 ( V_16 , F_23 ( V_124 ) , ( V_460 & F_224 ( 32 ) ) ) ;
F_51 ( V_16 , F_24 ( V_124 ) , ( V_460 >> 32 ) ) ;
F_51 ( V_16 , F_19 ( V_124 ) ,
V_98 -> V_68 * sizeof( union V_48 ) ) ;
F_51 ( V_16 , F_20 ( V_124 ) , 0 ) ;
F_51 ( V_16 , F_21 ( V_124 ) , 0 ) ;
V_98 -> V_125 = V_16 -> V_396 + F_21 ( V_124 ) ;
F_234 ( V_2 , V_98 ) ;
F_238 ( V_2 , V_98 ) ;
if ( V_16 -> V_88 . type == V_89 ) {
V_458 &= ~ 0x3FFFFF ;
V_458 |= 0x080420 ;
}
V_458 |= V_459 ;
F_51 ( V_16 , F_22 ( V_124 ) , V_458 ) ;
F_240 ( V_2 , V_98 ) ;
F_124 ( V_98 , F_90 ( V_98 ) ) ;
}
static void F_244 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_435 = V_2 -> V_413 [ V_414 ] . V_415 ;
int V_461 ;
T_1 V_462 = V_463 |
V_464 |
V_465 |
V_466 |
V_467 ;
if ( V_16 -> V_88 . type == V_89 )
return;
if ( V_435 > 3 )
V_462 |= 2 << 29 ;
else if ( V_435 > 1 )
V_462 |= 1 << 29 ;
for ( V_461 = 0 ; V_461 < V_2 -> V_468 ; V_461 ++ )
F_51 ( V_16 , F_245 ( F_246 ( V_461 ) ) ,
V_462 ) ;
}
static void F_247 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_154 , V_469 ;
T_1 V_470 , V_471 ;
int V_28 ;
if ( ! ( V_2 -> V_117 & V_408 ) )
return;
V_471 = F_17 ( V_16 , V_472 ) ;
V_471 |= V_473 ;
V_471 &= ~ V_474 ;
V_471 |= F_246 ( 0 ) << V_475 ;
V_471 |= V_476 ;
F_51 ( V_16 , V_472 , V_471 ) ;
V_469 = F_246 ( 0 ) % 32 ;
V_154 = ( F_246 ( 0 ) >= 32 ) ? 1 : 0 ;
F_51 ( V_16 , F_248 ( V_154 ) , ( ~ 0 ) << V_469 ) ;
F_51 ( V_16 , F_248 ( V_154 ^ 1 ) , V_154 - 1 ) ;
F_51 ( V_16 , F_249 ( V_154 ) , ( ~ 0 ) << V_469 ) ;
F_51 ( V_16 , F_249 ( V_154 ^ 1 ) , V_154 - 1 ) ;
if ( V_2 -> V_131 & V_477 )
F_51 ( V_16 , V_478 , V_479 ) ;
V_16 -> V_88 . V_336 . V_480 ( V_16 , 0 , F_246 ( 0 ) ) ;
switch ( V_2 -> V_413 [ V_481 ] . V_95 ) {
case V_482 :
V_470 = V_483 ;
break;
case V_484 :
V_470 = V_485 ;
break;
default:
V_470 = V_486 ;
break;
}
F_51 ( V_16 , V_487 , V_470 ) ;
V_16 -> V_88 . V_336 . V_488 ( V_16 , ( V_2 -> V_302 != 0 ) ,
V_2 -> V_302 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_302 ; V_28 ++ ) {
if ( ! V_2 -> V_489 [ V_28 ] . V_490 )
F_250 ( V_2 -> V_35 , V_28 , false ) ;
}
}
static void F_251 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_34 * V_35 = V_2 -> V_35 ;
int V_491 = V_35 -> V_290 + V_223 + V_492 ;
struct V_37 * V_47 ;
int V_28 ;
T_1 V_493 , V_494 ;
#ifdef F_129
if ( ( V_2 -> V_117 & V_495 ) &&
( V_491 < V_496 ) )
V_491 = V_496 ;
#endif
if ( V_491 < ( V_497 + V_492 ) )
V_491 = ( V_497 + V_492 ) ;
V_493 = F_17 ( V_16 , V_498 ) ;
if ( V_491 != ( V_493 >> V_499 ) ) {
V_493 &= ~ V_500 ;
V_493 |= V_491 << V_499 ;
F_51 ( V_16 , V_498 , V_493 ) ;
}
V_494 = F_17 ( V_16 , V_501 ) ;
V_494 |= V_502 ;
F_51 ( V_16 , V_501 , V_494 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ ) {
V_47 = V_2 -> V_47 [ V_28 ] ;
if ( V_2 -> V_131 & V_503 )
F_252 ( V_47 ) ;
else
F_253 ( V_47 ) ;
}
}
static void F_254 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_504 = F_17 ( V_16 , V_505 ) ;
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_504 |= V_506 ;
break;
case V_91 :
case V_92 :
F_51 ( V_16 , V_507 ,
( V_508 | F_17 ( V_16 , V_507 ) ) ) ;
V_504 &= ~ V_509 ;
V_504 |= ( V_510 | V_511 ) ;
V_504 |= V_512 ;
break;
default:
return;
}
F_51 ( V_16 , V_505 , V_504 ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_28 ;
T_1 V_159 ;
V_159 = F_17 ( V_16 , V_513 ) ;
F_51 ( V_16 , V_513 , V_159 & ~ V_514 ) ;
F_244 ( V_2 ) ;
F_254 ( V_2 ) ;
F_235 ( V_2 ) ;
F_251 ( V_2 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ )
F_243 ( V_2 , V_2 -> V_47 [ V_28 ] ) ;
if ( V_16 -> V_88 . type == V_89 )
V_159 |= V_515 ;
V_159 |= V_514 ;
V_16 -> V_88 . V_336 . V_516 ( V_16 , V_159 ) ;
}
static int F_256 ( struct V_34 * V_35 ,
T_9 V_517 , T_2 V_247 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
V_16 -> V_88 . V_336 . V_518 ( & V_2 -> V_16 , V_247 , F_246 ( 0 ) , true ) ;
F_226 ( V_247 , V_2 -> V_519 ) ;
return 0 ;
}
static int F_257 ( struct V_34 * V_35 ,
T_9 V_517 , T_2 V_247 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
V_16 -> V_88 . V_336 . V_518 ( & V_2 -> V_16 , V_247 , F_246 ( 0 ) , false ) ;
F_14 ( V_247 , V_2 -> V_519 ) ;
return 0 ;
}
static void F_258 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_520 ;
V_520 = F_17 ( V_16 , V_521 ) ;
V_520 &= ~ ( V_522 | V_523 ) ;
F_51 ( V_16 , V_521 , V_520 ) ;
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_520 ;
V_520 = F_17 ( V_16 , V_521 ) ;
V_520 |= V_522 ;
V_520 &= ~ V_523 ;
F_51 ( V_16 , V_521 , V_520 ) ;
}
static void F_260 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_520 ;
int V_28 , V_29 ;
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_520 = F_17 ( V_16 , V_521 ) ;
V_520 &= ~ V_524 ;
F_51 ( V_16 , V_521 , V_520 ) ;
break;
case V_91 :
case V_92 :
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ ) {
V_29 = V_2 -> V_47 [ V_28 ] -> V_124 ;
V_520 = F_17 ( V_16 , F_22 ( V_29 ) ) ;
V_520 &= ~ V_525 ;
F_51 ( V_16 , F_22 ( V_29 ) , V_520 ) ;
}
break;
default:
break;
}
}
static void F_261 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_520 ;
int V_28 , V_29 ;
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_520 = F_17 ( V_16 , V_521 ) ;
V_520 |= V_524 ;
F_51 ( V_16 , V_521 , V_520 ) ;
break;
case V_91 :
case V_92 :
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ ) {
V_29 = V_2 -> V_47 [ V_28 ] -> V_124 ;
V_520 = F_17 ( V_16 , F_22 ( V_29 ) ) ;
V_520 |= V_525 ;
F_51 ( V_16 , F_22 ( V_29 ) , V_520 ) ;
}
break;
default:
break;
}
}
static void F_262 ( struct V_1 * V_2 )
{
T_2 V_247 ;
F_256 ( V_2 -> V_35 , F_128 ( V_225 ) , 0 ) ;
F_263 (vid, adapter->active_vlans, VLAN_N_VID)
F_256 ( V_2 -> V_35 , F_128 ( V_225 ) , V_247 ) ;
}
static int F_264 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
unsigned int V_526 = V_16 -> V_88 . V_527 - 1 ;
int V_68 = 0 ;
if ( V_2 -> V_117 & V_408 )
V_526 = V_528 - 1 ;
if ( F_265 ( V_35 ) > V_526 )
return - V_529 ;
if ( ! F_266 ( V_35 ) ) {
struct V_530 * V_531 ;
if ( ! V_16 -> V_88 . V_336 . V_532 )
return - V_529 ;
F_267 (ha, netdev) {
if ( ! V_526 )
break;
V_16 -> V_88 . V_336 . V_532 ( V_16 , V_526 -- , V_531 -> V_533 ,
F_246 ( 0 ) , V_534 ) ;
V_68 ++ ;
}
}
for (; V_526 > 0 ; V_526 -- )
V_16 -> V_88 . V_336 . V_535 ( V_16 , V_526 ) ;
return V_68 ;
}
void F_268 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_536 , V_537 = V_538 | V_539 ;
int V_68 ;
V_536 = F_17 ( V_16 , V_540 ) ;
V_536 &= ~ V_541 ;
V_536 |= V_542 ;
V_536 |= V_543 ;
V_536 |= V_544 ;
V_536 &= ~ ( V_545 | V_546 ) ;
if ( V_35 -> V_117 & V_547 ) {
V_16 -> V_548 . V_549 = true ;
V_536 |= ( V_545 | V_546 ) ;
V_537 |= ( V_550 | V_551 ) ;
F_258 ( V_2 ) ;
} else {
if ( V_35 -> V_117 & V_552 ) {
V_536 |= V_546 ;
V_537 |= V_551 ;
} else {
V_16 -> V_88 . V_336 . V_553 ( V_16 , V_35 ) ;
V_537 |= V_554 ;
}
F_259 ( V_2 ) ;
V_16 -> V_548 . V_549 = false ;
}
V_68 = F_264 ( V_35 ) ;
if ( V_68 < 0 ) {
V_536 |= V_545 ;
V_537 |= V_550 ;
}
if ( V_2 -> V_302 )
F_269 ( V_2 ) ;
if ( V_16 -> V_88 . type != V_89 ) {
V_537 |= F_17 ( V_16 , F_270 ( F_246 ( 0 ) ) ) &
~ ( V_551 | V_554 |
V_550 ) ;
F_51 ( V_16 , F_270 ( F_246 ( 0 ) ) , V_537 ) ;
}
if ( V_2 -> V_35 -> V_173 & V_268 ) {
V_536 |= ( V_541 |
V_542 |
V_544 ) ;
V_536 &= ~ ( V_543 ) ;
}
F_51 ( V_16 , V_540 , V_536 ) ;
if ( V_35 -> V_173 & V_245 )
F_261 ( V_2 ) ;
else
F_260 ( V_2 ) ;
}
static void F_271 ( struct V_1 * V_2 )
{
int V_555 ;
for ( V_555 = 0 ; V_555 < V_2 -> V_166 ; V_555 ++ ) {
F_272 ( V_2 -> V_135 [ V_555 ] ) ;
F_273 ( & V_2 -> V_135 [ V_555 ] -> V_249 ) ;
}
}
static void F_274 ( struct V_1 * V_2 )
{
int V_555 ;
F_275 () ;
for ( V_555 = 0 ; V_555 < V_2 -> V_166 ; V_555 ++ ) {
F_276 ( & V_2 -> V_135 [ V_555 ] -> V_249 ) ;
while ( ! F_208 ( V_2 -> V_135 [ V_555 ] ) ) {
F_31 ( L_77 , V_555 ) ;
F_277 ( 1 ) ;
}
}
F_278 () ;
}
static void F_279 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_491 = V_2 -> V_35 -> V_290 + V_223 + V_492 ;
if ( ! ( V_2 -> V_117 & V_118 ) ) {
if ( V_16 -> V_88 . type == V_89 )
F_280 ( V_2 -> V_35 , 65536 ) ;
return;
}
if ( V_16 -> V_88 . type == V_89 )
F_280 ( V_2 -> V_35 , 32768 ) ;
#ifdef F_129
if ( V_2 -> V_35 -> V_173 & V_556 )
V_491 = F_187 ( V_491 , V_496 ) ;
#endif
if ( V_2 -> V_557 & V_558 ) {
F_281 ( V_16 , & V_2 -> V_114 , V_491 ,
V_559 ) ;
F_281 ( V_16 , & V_2 -> V_114 , V_491 ,
V_560 ) ;
F_282 ( V_16 , & V_2 -> V_114 ) ;
} else if ( V_2 -> V_561 && V_2 -> V_116 ) {
F_283 ( & V_2 -> V_16 ,
V_2 -> V_561 ,
V_491 ) ;
F_284 ( & V_2 -> V_16 ,
V_2 -> V_116 -> V_113 ,
V_2 -> V_561 -> V_562 ) ;
}
if ( V_16 -> V_88 . type != V_89 ) {
T_1 V_563 = 0 ;
T_2 V_435 = V_2 -> V_413 [ V_414 ] . V_415 - 1 ;
while ( V_435 ) {
V_563 ++ ;
V_435 >>= 1 ;
}
F_51 ( V_16 , V_564 , V_563 * 0x11111111 ) ;
}
}
static int F_285 ( struct V_1 * V_2 , int V_565 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_34 * V_53 = V_2 -> V_35 ;
int V_369 , V_112 , V_566 , V_567 ;
T_1 V_568 , V_569 ;
V_112 = V_369 = V_53 -> V_290 + V_223 + V_492 + V_570 ;
#ifdef F_129
if ( ( V_53 -> V_173 & V_556 ) &&
( V_112 < V_496 ) &&
( V_565 == F_286 ( V_2 ) ) )
V_112 = V_496 ;
#endif
switch ( V_16 -> V_88 . type ) {
case V_92 :
V_568 = F_287 ( V_369 , V_112 ) ;
break;
default:
V_568 = F_288 ( V_369 , V_112 ) ;
break;
}
if ( V_2 -> V_117 & V_408 )
V_568 += F_289 ( V_112 ) ;
V_566 = F_290 ( V_568 ) ;
V_569 = F_17 ( V_16 , F_291 ( V_565 ) ) >> 10 ;
V_567 = V_569 - V_566 ;
if ( V_567 < 0 ) {
F_73 ( V_133 , L_78
L_79
L_80 , V_565 ) ;
V_567 = V_112 + 1 ;
}
return V_567 ;
}
static int F_292 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_34 * V_53 = V_2 -> V_35 ;
int V_112 ;
T_1 V_568 ;
V_112 = V_53 -> V_290 + V_223 + V_492 ;
switch ( V_16 -> V_88 . type ) {
case V_92 :
V_568 = F_293 ( V_112 ) ;
break;
default:
V_568 = F_294 ( V_112 ) ;
break;
}
return F_290 ( V_568 ) ;
}
static void F_295 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_571 = F_230 ( V_2 -> V_35 ) ;
int V_28 ;
if ( ! V_571 )
V_571 = 1 ;
V_16 -> V_103 . V_572 = F_292 ( V_2 ) ;
for ( V_28 = 0 ; V_28 < V_571 ; V_28 ++ ) {
V_16 -> V_103 . V_573 [ V_28 ] = F_285 ( V_2 , V_28 ) ;
if ( V_16 -> V_103 . V_572 > V_16 -> V_103 . V_573 [ V_28 ] )
V_16 -> V_103 . V_572 = 0 ;
}
}
static void F_296 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_574 ;
T_6 V_112 = F_230 ( V_2 -> V_35 ) ;
if ( V_2 -> V_117 & V_363 ||
V_2 -> V_117 & V_575 )
V_574 = 32 << V_2 -> V_576 ;
else
V_574 = 0 ;
V_16 -> V_88 . V_336 . V_577 ( V_16 , V_112 , V_574 , V_578 ) ;
F_295 ( V_2 ) ;
}
static void F_297 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_579 * V_580 ;
struct V_581 * V_582 ;
F_298 ( & V_2 -> V_583 ) ;
if ( ! F_299 ( & V_2 -> V_584 ) )
F_300 ( V_16 , & V_2 -> V_585 ) ;
F_301 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_302 ( V_16 ,
& V_582 -> V_582 ,
V_582 -> V_586 ,
( V_582 -> V_587 == V_588 ) ?
V_588 :
V_2 -> V_47 [ V_582 -> V_587 ] -> V_124 ) ;
}
F_303 ( & V_2 -> V_583 ) ;
}
static void F_304 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
F_296 ( V_2 ) ;
#ifdef F_305
F_279 ( V_2 ) ;
#endif
F_247 ( V_2 ) ;
F_268 ( V_2 -> V_35 ) ;
F_262 ( V_2 ) ;
switch ( V_16 -> V_88 . type ) {
case V_91 :
case V_92 :
V_16 -> V_88 . V_336 . V_589 ( V_16 ) ;
break;
default:
break;
}
if ( V_2 -> V_117 & V_363 ) {
F_306 ( & V_2 -> V_16 ,
V_2 -> V_576 ) ;
} else if ( V_2 -> V_117 & V_575 ) {
F_307 ( & V_2 -> V_16 ,
V_2 -> V_576 ) ;
F_297 ( V_2 ) ;
}
switch ( V_16 -> V_88 . type ) {
case V_91 :
case V_92 :
V_16 -> V_88 . V_336 . V_590 ( V_16 ) ;
break;
default:
break;
}
#ifdef F_129
F_308 ( V_2 ) ;
#endif
F_231 ( V_2 ) ;
F_255 ( V_2 ) ;
}
static inline bool F_309 ( struct V_15 * V_16 )
{
switch ( V_16 -> V_339 . type ) {
case V_591 :
case V_592 :
case V_593 :
case V_594 :
case V_595 :
case V_596 :
case V_597 :
case V_598 :
return true ;
case V_599 :
if ( V_16 -> V_88 . type == V_89 )
return true ;
default:
return false ;
}
}
static void F_310 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 . V_88 . type == V_89 )
V_2 -> V_131 |= V_600 ;
V_2 -> V_131 |= V_347 ;
}
static int F_311 ( struct V_15 * V_16 )
{
T_1 V_21 ;
bool V_601 , V_338 = false ;
T_1 V_130 = V_602 ;
if ( V_16 -> V_88 . V_336 . V_337 )
V_130 = V_16 -> V_88 . V_336 . V_337 ( V_16 , & V_21 , & V_338 , false ) ;
if ( V_130 )
goto V_603;
V_21 = V_16 -> V_339 . V_604 ;
if ( ( ! V_21 ) && ( V_16 -> V_88 . V_336 . V_605 ) )
V_130 = V_16 -> V_88 . V_336 . V_605 ( V_16 , & V_21 ,
& V_601 ) ;
if ( V_130 )
goto V_603;
if ( V_16 -> V_88 . V_336 . V_606 )
V_130 = V_16 -> V_88 . V_336 . V_606 ( V_16 , V_21 , V_338 ) ;
V_603:
return V_130 ;
}
static void F_312 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_607 = 0 ;
if ( V_2 -> V_117 & V_387 ) {
V_607 = V_608 | V_609 |
V_610 ;
V_607 |= V_611 ;
switch ( V_16 -> V_88 . type ) {
case V_89 :
F_51 ( V_16 , V_612 , V_613 ) ;
break;
case V_91 :
case V_92 :
default:
F_51 ( V_16 , F_313 ( 0 ) , 0xFFFFFFFF ) ;
F_51 ( V_16 , F_313 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_51 ( V_16 , V_612 , V_613 ) ;
}
if ( V_2 -> V_117 & V_408 ) {
V_607 &= ~ V_614 ;
switch ( V_2 -> V_413 [ V_481 ] . V_95 ) {
case V_482 :
V_607 |= V_615 ;
break;
case V_484 :
V_607 |= V_616 ;
break;
default:
V_607 |= V_617 ;
break;
}
}
if ( V_2 -> V_131 & V_330 ) {
switch ( V_2 -> V_16 . V_88 . type ) {
case V_91 :
V_607 |= V_618 ;
break;
case V_92 :
V_607 |= V_358 ;
break;
default:
break;
}
}
if ( V_2 -> V_117 & V_342 )
V_607 |= V_619 ;
if ( V_16 -> V_88 . type == V_91 ) {
V_607 |= V_619 ;
V_607 |= V_620 ;
}
F_51 ( V_16 , V_621 , V_607 ) ;
}
static void F_314 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_18 ;
T_1 V_80 ;
F_52 ( V_2 ) ;
F_312 ( V_2 ) ;
if ( V_2 -> V_117 & V_387 )
F_182 ( V_2 ) ;
else
F_222 ( V_2 ) ;
if ( V_16 -> V_88 . V_336 . V_622 )
V_16 -> V_88 . V_336 . V_622 ( V_16 ) ;
F_14 ( V_22 , & V_2 -> V_23 ) ;
F_271 ( V_2 ) ;
if ( F_309 ( V_16 ) ) {
F_310 ( V_2 ) ;
} else {
V_18 = F_311 ( V_16 ) ;
if ( V_18 )
F_83 ( V_149 , L_81 , V_18 ) ;
}
F_17 ( V_16 , V_344 ) ;
F_199 ( V_2 , true , true ) ;
if ( V_2 -> V_117 & V_342 ) {
T_1 V_623 = F_17 ( V_16 , V_624 ) ;
if ( V_623 & V_625 )
F_189 ( V_133 , L_60 ) ;
}
F_315 ( V_2 -> V_35 ) ;
V_2 -> V_117 |= V_350 ;
V_2 -> V_351 = V_148 ;
F_316 ( & V_2 -> V_626 , V_148 ) ;
V_80 = F_17 ( V_16 , V_81 ) ;
V_80 |= V_627 ;
F_51 ( V_16 , V_81 , V_80 ) ;
}
void F_317 ( struct V_1 * V_2 )
{
F_318 ( F_319 () ) ;
V_2 -> V_35 -> V_54 = V_148 ;
while ( F_9 ( V_628 , & V_2 -> V_23 ) )
F_228 ( 1000 , 2000 ) ;
F_320 ( V_2 ) ;
if ( V_2 -> V_117 & V_408 )
F_321 ( 2000 ) ;
F_322 ( V_2 ) ;
F_14 ( V_628 , & V_2 -> V_23 ) ;
}
void F_322 ( struct V_1 * V_2 )
{
F_304 ( V_2 ) ;
F_314 ( V_2 ) ;
}
void F_323 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_18 ;
while ( F_9 ( V_629 , & V_2 -> V_23 ) )
F_228 ( 1000 , 2000 ) ;
V_2 -> V_131 &= ~ ( V_600 |
V_347 ) ;
V_2 -> V_117 &= ~ V_348 ;
V_18 = V_16 -> V_88 . V_336 . V_630 ( V_16 ) ;
switch ( V_18 ) {
case 0 :
case V_631 :
case V_632 :
break;
case V_633 :
F_324 ( L_82 ) ;
break;
case V_634 :
F_325 ( L_83
L_84
L_85
L_86
L_87
L_88 ) ;
break;
default:
F_324 ( L_89 , V_18 ) ;
}
F_14 ( V_629 , & V_2 -> V_23 ) ;
V_16 -> V_88 . V_336 . V_532 ( V_16 , 0 , V_16 -> V_88 . V_533 , F_246 ( 0 ) , V_534 ) ;
if ( V_16 -> V_88 . V_635 )
V_16 -> V_88 . V_336 . V_636 ( V_16 , F_246 ( 0 ) ) ;
if ( V_2 -> V_131 & V_637 )
F_326 ( V_2 ) ;
}
static void F_327 ( struct V_37 * V_47 )
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
F_328 ( V_69 ) ;
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
static void F_329 ( struct V_37 * V_38 )
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
F_330 ( F_87 ( V_38 ) ) ;
V_274 = sizeof( struct V_39 ) * V_38 -> V_68 ;
memset ( V_38 -> V_58 , 0 , V_274 ) ;
memset ( V_38 -> V_67 , 0 , V_38 -> V_274 ) ;
V_38 -> V_60 = 0 ;
V_38 -> V_59 = 0 ;
}
static void F_331 ( struct V_1 * V_2 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ )
F_327 ( V_2 -> V_47 [ V_28 ] ) ;
}
static void F_332 ( struct V_1 * V_2 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ )
F_329 ( V_2 -> V_38 [ V_28 ] ) ;
}
static void F_333 ( struct V_1 * V_2 )
{
struct V_579 * V_580 ;
struct V_581 * V_582 ;
F_298 ( & V_2 -> V_583 ) ;
F_301 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_334 ( & V_582 -> V_638 ) ;
F_216 ( V_582 ) ;
}
V_2 -> V_639 = 0 ;
F_303 ( & V_2 -> V_583 ) ;
}
void F_320 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_159 ;
int V_28 ;
F_226 ( V_22 , & V_2 -> V_23 ) ;
V_159 = F_17 ( V_16 , V_513 ) ;
F_51 ( V_16 , V_513 , V_159 & ~ V_514 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ )
F_241 ( V_2 , V_2 -> V_47 [ V_28 ] ) ;
F_228 ( 10000 , 20000 ) ;
F_335 ( V_35 ) ;
F_336 ( V_35 ) ;
F_337 ( V_35 ) ;
F_220 ( V_2 ) ;
F_274 ( V_2 ) ;
V_2 -> V_131 &= ~ ( V_364 |
V_132 ) ;
V_2 -> V_117 &= ~ V_350 ;
F_338 ( & V_2 -> V_626 ) ;
if ( V_2 -> V_302 ) {
F_51 ( & V_2 -> V_16 , V_304 , 0 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_302 ; V_28 ++ )
V_2 -> V_489 [ V_28 ] . V_640 = false ;
F_339 ( V_2 ) ;
F_340 ( V_2 ) ;
}
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ ) {
T_6 V_124 = V_2 -> V_38 [ V_28 ] -> V_124 ;
F_51 ( V_16 , F_30 ( V_124 ) , V_641 ) ;
}
switch ( V_16 -> V_88 . type ) {
case V_91 :
case V_92 :
F_51 ( V_16 , V_424 ,
( F_17 ( V_16 , V_424 ) &
~ V_425 ) ) ;
break;
default:
break;
}
if ( ! F_341 ( V_2 -> V_10 ) )
F_323 ( V_2 ) ;
if ( V_16 -> V_88 . V_336 . V_642 )
V_16 -> V_88 . V_336 . V_642 ( V_16 ) ;
F_332 ( V_2 ) ;
F_331 ( V_2 ) ;
#ifdef F_207
F_103 ( V_2 ) ;
#endif
}
static void F_342 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
F_72 ( V_2 ) ;
}
static int F_343 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_6 * V_10 = V_2 -> V_10 ;
unsigned int V_178 , V_643 ;
T_1 V_644 ;
#ifdef F_305
int V_29 ;
struct V_645 * V_112 ;
#endif
V_16 -> V_646 = V_10 -> V_647 ;
V_16 -> V_332 = V_10 -> V_167 ;
V_16 -> V_648 = V_10 -> V_649 ;
V_16 -> V_650 = V_10 -> V_651 ;
V_16 -> V_652 = V_10 -> V_653 ;
V_178 = F_344 ( int , V_654 , F_345 () ) ;
V_2 -> V_413 [ V_414 ] . V_655 = V_178 ;
V_2 -> V_131 |= V_656 ;
V_2 -> V_131 |= V_503 ;
V_2 -> V_657 = V_658 ;
V_2 -> V_398 = 20 ;
V_643 = F_344 ( int , V_659 , F_345 () ) ;
V_2 -> V_413 [ V_660 ] . V_655 = V_643 ;
V_2 -> V_576 = V_661 ;
#ifdef F_207
V_2 -> V_117 |= V_169 ;
#endif
#ifdef F_129
V_2 -> V_117 |= V_662 ;
V_2 -> V_117 &= ~ V_495 ;
#ifdef F_305
V_2 -> V_663 . V_664 = V_665 ;
#endif
#endif
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_2 -> V_131 &= ~ V_656 ;
V_2 -> V_131 &= ~ V_503 ;
if ( V_16 -> V_332 == V_666 )
V_2 -> V_117 |= V_342 ;
V_2 -> V_657 = V_667 ;
V_2 -> V_413 [ V_660 ] . V_655 = 0 ;
V_2 -> V_398 = 0 ;
V_2 -> V_576 = 0 ;
#ifdef F_129
V_2 -> V_117 &= ~ V_662 ;
V_2 -> V_117 &= ~ V_495 ;
#ifdef F_305
V_2 -> V_663 . V_664 = 0 ;
#endif
#endif
break;
case V_91 :
if ( V_16 -> V_332 == V_333 )
V_2 -> V_131 |= V_330 ;
break;
case V_92 :
V_644 = F_17 ( V_16 , V_668 ) ;
if ( V_644 & V_669 )
V_2 -> V_131 |= V_330 ;
break;
default:
break;
}
#ifdef F_129
F_346 ( & V_2 -> V_663 . V_670 ) ;
#endif
F_346 ( & V_2 -> V_583 ) ;
#ifdef F_305
switch ( V_16 -> V_88 . type ) {
case V_92 :
V_2 -> V_114 . V_671 . V_672 = V_673 ;
V_2 -> V_114 . V_671 . V_674 = V_673 ;
break;
default:
V_2 -> V_114 . V_671 . V_672 = V_675 ;
V_2 -> V_114 . V_671 . V_674 = V_675 ;
break;
}
for ( V_29 = 0 ; V_29 < V_675 ; V_29 ++ ) {
V_112 = & V_2 -> V_114 . V_676 [ V_29 ] ;
V_112 -> V_677 [ V_559 ] . V_678 = 0 ;
V_112 -> V_677 [ V_559 ] . V_679 = 12 + ( V_29 & 1 ) ;
V_112 -> V_677 [ V_560 ] . V_678 = 0 ;
V_112 -> V_677 [ V_560 ] . V_679 = 12 + ( V_29 & 1 ) ;
V_112 -> V_680 = V_681 ;
}
V_112 = & V_2 -> V_114 . V_676 [ 0 ] ;
V_112 -> V_677 [ V_559 ] . V_682 = 0xFF ;
V_112 -> V_677 [ V_560 ] . V_682 = 0xFF ;
V_2 -> V_114 . V_683 [ V_559 ] [ 0 ] = 100 ;
V_2 -> V_114 . V_683 [ V_560 ] [ 0 ] = 100 ;
V_2 -> V_114 . V_115 = false ;
V_2 -> V_684 = 0x00 ;
V_2 -> V_557 = V_685 | V_558 ;
memcpy ( & V_2 -> V_686 , & V_2 -> V_114 ,
sizeof( V_2 -> V_686 ) ) ;
#endif
V_16 -> V_103 . V_687 = V_105 ;
V_16 -> V_103 . V_104 = V_105 ;
F_295 ( V_2 ) ;
V_16 -> V_103 . V_688 = V_689 ;
V_16 -> V_103 . V_690 = true ;
V_16 -> V_103 . V_691 =
( F_347 ( V_16 ) == 0 ) ? false : true ;
#ifdef F_348
if ( V_16 -> V_88 . type != V_89 )
V_2 -> V_302 = ( V_692 > 63 ) ? 0 : V_692 ;
#endif
V_2 -> V_378 = 1 ;
V_2 -> V_693 = 1 ;
V_2 -> V_694 = V_695 ;
V_2 -> V_696 = V_697 ;
V_2 -> V_698 = V_699 ;
if ( F_349 ( V_16 ) ) {
F_324 ( L_90 ) ;
return - V_700 ;
}
F_226 ( V_22 , & V_2 -> V_23 ) ;
return 0 ;
}
int F_350 ( struct V_37 * V_38 )
{
struct V_167 * V_53 = V_38 -> V_53 ;
int V_701 = F_351 ( V_53 ) ;
int V_702 = - 1 ;
int V_274 ;
V_274 = sizeof( struct V_39 ) * V_38 -> V_68 ;
if ( V_38 -> V_135 )
V_702 = V_38 -> V_135 -> V_702 ;
V_38 -> V_58 = F_352 ( V_274 , V_702 ) ;
if ( ! V_38 -> V_58 )
V_38 -> V_58 = F_353 ( V_274 ) ;
if ( ! V_38 -> V_58 )
goto V_18;
V_38 -> V_274 = V_38 -> V_68 * sizeof( union V_41 ) ;
V_38 -> V_274 = F_152 ( V_38 -> V_274 , 4096 ) ;
F_354 ( V_53 , V_702 ) ;
V_38 -> V_67 = F_355 ( V_53 ,
V_38 -> V_274 ,
& V_38 -> V_61 ,
V_703 ) ;
F_354 ( V_53 , V_701 ) ;
if ( ! V_38 -> V_67 )
V_38 -> V_67 = F_355 ( V_53 , V_38 -> V_274 ,
& V_38 -> V_61 , V_703 ) ;
if ( ! V_38 -> V_67 )
goto V_18;
V_38 -> V_60 = 0 ;
V_38 -> V_59 = 0 ;
return 0 ;
V_18:
F_356 ( V_38 -> V_58 ) ;
V_38 -> V_58 = NULL ;
F_357 ( V_53 , L_91 ) ;
return - V_529 ;
}
static int F_358 ( struct V_1 * V_2 )
{
int V_28 , V_18 = 0 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ ) {
V_18 = F_350 ( V_2 -> V_38 [ V_28 ] ) ;
if ( ! V_18 )
continue;
F_83 ( V_149 , L_92 , V_28 ) ;
goto V_704;
}
return 0 ;
V_704:
while ( V_28 -- )
F_359 ( V_2 -> V_38 [ V_28 ] ) ;
return V_18 ;
}
int F_360 ( struct V_37 * V_47 )
{
struct V_167 * V_53 = V_47 -> V_53 ;
int V_701 = F_351 ( V_53 ) ;
int V_702 = - 1 ;
int V_274 ;
V_274 = sizeof( struct V_50 ) * V_47 -> V_68 ;
if ( V_47 -> V_135 )
V_702 = V_47 -> V_135 -> V_702 ;
V_47 -> V_51 = F_352 ( V_274 , V_702 ) ;
if ( ! V_47 -> V_51 )
V_47 -> V_51 = F_353 ( V_274 ) ;
if ( ! V_47 -> V_51 )
goto V_18;
V_47 -> V_274 = V_47 -> V_68 * sizeof( union V_48 ) ;
V_47 -> V_274 = F_152 ( V_47 -> V_274 , 4096 ) ;
F_354 ( V_53 , V_702 ) ;
V_47 -> V_67 = F_355 ( V_53 ,
V_47 -> V_274 ,
& V_47 -> V_61 ,
V_703 ) ;
F_354 ( V_53 , V_701 ) ;
if ( ! V_47 -> V_67 )
V_47 -> V_67 = F_355 ( V_53 , V_47 -> V_274 ,
& V_47 -> V_61 , V_703 ) ;
if ( ! V_47 -> V_67 )
goto V_18;
V_47 -> V_59 = 0 ;
V_47 -> V_60 = 0 ;
return 0 ;
V_18:
F_356 ( V_47 -> V_51 ) ;
V_47 -> V_51 = NULL ;
F_357 ( V_53 , L_93 ) ;
return - V_529 ;
}
static int F_361 ( struct V_1 * V_2 )
{
int V_28 , V_18 = 0 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ ) {
V_18 = F_360 ( V_2 -> V_47 [ V_28 ] ) ;
if ( ! V_18 )
continue;
F_83 ( V_149 , L_94 , V_28 ) ;
goto V_705;
}
#ifdef F_129
V_18 = F_362 ( V_2 ) ;
if ( ! V_18 )
#endif
return 0 ;
V_705:
while ( V_28 -- )
F_363 ( V_2 -> V_47 [ V_28 ] ) ;
return V_18 ;
}
void F_359 ( struct V_37 * V_38 )
{
F_329 ( V_38 ) ;
F_356 ( V_38 -> V_58 ) ;
V_38 -> V_58 = NULL ;
if ( ! V_38 -> V_67 )
return;
F_364 ( V_38 -> V_53 , V_38 -> V_274 ,
V_38 -> V_67 , V_38 -> V_61 ) ;
V_38 -> V_67 = NULL ;
}
static void F_365 ( struct V_1 * V_2 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ )
if ( V_2 -> V_38 [ V_28 ] -> V_67 )
F_359 ( V_2 -> V_38 [ V_28 ] ) ;
}
void F_363 ( struct V_37 * V_47 )
{
F_327 ( V_47 ) ;
F_356 ( V_47 -> V_51 ) ;
V_47 -> V_51 = NULL ;
if ( ! V_47 -> V_67 )
return;
F_364 ( V_47 -> V_53 , V_47 -> V_274 ,
V_47 -> V_67 , V_47 -> V_61 ) ;
V_47 -> V_67 = NULL ;
}
static void F_366 ( struct V_1 * V_2 )
{
int V_28 ;
#ifdef F_129
F_367 ( V_2 ) ;
#endif
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ )
if ( V_2 -> V_47 [ V_28 ] -> V_67 )
F_363 ( V_2 -> V_47 [ V_28 ] ) ;
}
static int F_368 ( struct V_34 * V_35 , int V_706 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
int V_491 = V_706 + V_223 + V_492 ;
if ( ( V_706 < 68 ) || ( V_491 > V_707 ) )
return - V_708 ;
if ( ( V_2 -> V_117 & V_408 ) &&
( V_2 -> V_16 . V_88 . type == V_91 ) &&
( V_491 > ( V_497 + V_492 ) ) )
F_73 ( V_149 , L_95 ) ;
F_85 ( V_149 , L_96 , V_35 -> V_290 , V_706 ) ;
V_35 -> V_290 = V_706 ;
if ( F_37 ( V_35 ) )
F_317 ( V_2 ) ;
return 0 ;
}
static int F_369 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
int V_18 ;
if ( F_8 ( V_709 , & V_2 -> V_23 ) )
return - V_710 ;
F_336 ( V_35 ) ;
V_18 = F_358 ( V_2 ) ;
if ( V_18 )
goto V_704;
V_18 = F_361 ( V_2 ) ;
if ( V_18 )
goto V_705;
F_304 ( V_2 ) ;
V_18 = F_218 ( V_2 ) ;
if ( V_18 )
goto V_711;
V_18 = F_370 ( V_35 ,
V_2 -> V_468 > 1 ? 1 :
V_2 -> V_57 ) ;
if ( V_18 )
goto V_712;
V_18 = F_371 ( V_35 ,
V_2 -> V_468 > 1 ? 1 :
V_2 -> V_73 ) ;
if ( V_18 )
goto V_712;
F_372 ( V_2 ) ;
F_314 ( V_2 ) ;
return 0 ;
V_712:
F_219 ( V_2 ) ;
V_711:
F_366 ( V_2 ) ;
V_705:
F_365 ( V_2 ) ;
V_704:
F_323 ( V_2 ) ;
return V_18 ;
}
static int F_373 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
F_374 ( V_2 ) ;
F_320 ( V_2 ) ;
F_219 ( V_2 ) ;
F_333 ( V_2 ) ;
F_365 ( V_2 ) ;
F_366 ( V_2 ) ;
F_50 ( V_2 ) ;
return 0 ;
}
static int F_375 ( struct V_6 * V_10 )
{
struct V_1 * V_2 = F_376 ( V_10 ) ;
struct V_34 * V_35 = V_2 -> V_35 ;
T_1 V_18 ;
F_377 ( V_10 , V_713 ) ;
F_378 ( V_10 ) ;
F_379 ( V_10 ) ;
V_18 = F_380 ( V_10 ) ;
if ( V_18 ) {
F_324 ( L_97 ) ;
return V_18 ;
}
F_381 ( V_10 ) ;
F_382 ( V_10 , false ) ;
F_323 ( V_2 ) ;
F_51 ( & V_2 -> V_16 , V_714 , ~ 0 ) ;
F_383 () ;
V_18 = F_384 ( V_2 ) ;
if ( ! V_18 && F_37 ( V_35 ) )
V_18 = F_369 ( V_35 ) ;
F_385 () ;
if ( V_18 )
return V_18 ;
F_386 ( V_35 ) ;
return 0 ;
}
static int F_387 ( struct V_6 * V_10 , bool * V_715 )
{
struct V_1 * V_2 = F_376 ( V_10 ) ;
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_716 , V_536 ;
T_1 V_717 = V_2 -> V_718 ;
#ifdef F_388
int V_719 = 0 ;
#endif
F_389 ( V_35 ) ;
F_383 () ;
if ( F_37 ( V_35 ) ) {
F_320 ( V_2 ) ;
F_219 ( V_2 ) ;
F_365 ( V_2 ) ;
F_366 ( V_2 ) ;
}
F_385 () ;
F_390 ( V_2 ) ;
#ifdef F_388
V_719 = F_379 ( V_10 ) ;
if ( V_719 )
return V_719 ;
#endif
if ( V_717 ) {
F_268 ( V_35 ) ;
if ( V_16 -> V_88 . V_336 . V_622 )
V_16 -> V_88 . V_336 . V_622 ( V_16 ) ;
if ( V_717 & V_720 ) {
V_536 = F_17 ( V_16 , V_540 ) ;
V_536 |= V_546 ;
F_51 ( V_16 , V_540 , V_536 ) ;
}
V_716 = F_17 ( V_16 , V_721 ) ;
V_716 |= V_722 ;
F_51 ( V_16 , V_721 , V_716 ) ;
F_51 ( V_16 , V_723 , V_717 ) ;
} else {
F_51 ( V_16 , V_724 , 0 ) ;
F_51 ( V_16 , V_723 , 0 ) ;
}
switch ( V_16 -> V_88 . type ) {
case V_89 :
F_382 ( V_10 , false ) ;
break;
case V_91 :
case V_92 :
F_382 ( V_10 , ! ! V_717 ) ;
break;
default:
break;
}
* V_715 = ! ! V_717 ;
F_50 ( V_2 ) ;
F_391 ( V_10 ) ;
return 0 ;
}
static int F_392 ( struct V_6 * V_10 , T_12 V_23 )
{
int V_719 ;
bool V_725 ;
V_719 = F_387 ( V_10 , & V_725 ) ;
if ( V_719 )
return V_719 ;
if ( V_725 ) {
F_393 ( V_10 ) ;
} else {
F_382 ( V_10 , false ) ;
F_377 ( V_10 , V_726 ) ;
}
return 0 ;
}
static void F_394 ( struct V_6 * V_10 )
{
bool V_725 ;
F_387 ( V_10 , & V_725 ) ;
if ( V_727 == V_728 ) {
F_382 ( V_10 , V_725 ) ;
F_377 ( V_10 , V_726 ) ;
}
}
void F_395 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_100 * V_101 = & V_2 -> V_102 ;
T_4 V_729 = 0 ;
T_1 V_28 , V_730 = 0 , V_731 , V_732 , V_733 , V_734 , V_735 ;
T_4 V_258 = 0 , V_151 = 0 , V_736 = 0 ;
T_4 V_203 = 0 , V_283 = 0 ;
T_4 V_147 = 0 , V_122 = 0 , V_737 = 0 ;
if ( F_8 ( V_22 , & V_2 -> V_23 ) ||
F_8 ( V_628 , & V_2 -> V_23 ) )
return;
if ( V_2 -> V_131 & V_503 ) {
T_4 V_243 = 0 ;
T_4 V_244 = 0 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ ) {
V_243 += V_2 -> V_47 [ V_28 ] -> V_189 . V_243 ;
V_244 += V_2 -> V_47 [ V_28 ] -> V_189 . V_244 ;
}
V_2 -> V_738 = V_243 ;
V_2 -> V_739 = V_244 ;
}
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ ) {
struct V_37 * V_47 = V_2 -> V_47 [ V_28 ] ;
V_258 += V_47 -> V_189 . V_258 ;
V_203 += V_47 -> V_189 . V_203 ;
V_283 += V_47 -> V_189 . V_283 ;
V_737 += V_47 -> V_189 . V_190 ;
V_147 += V_47 -> V_102 . V_147 ;
V_122 += V_47 -> V_102 . V_122 ;
}
V_2 -> V_258 = V_258 ;
V_2 -> V_203 = V_203 ;
V_2 -> V_283 = V_283 ;
V_2 -> V_737 = V_737 ;
V_35 -> V_102 . V_740 = V_147 ;
V_35 -> V_102 . V_741 = V_122 ;
V_147 = 0 ;
V_122 = 0 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ ) {
struct V_37 * V_38 = V_2 -> V_38 [ V_28 ] ;
V_151 += V_38 -> V_128 . V_151 ;
V_736 += V_38 -> V_128 . V_736 ;
V_147 += V_38 -> V_102 . V_147 ;
V_122 += V_38 -> V_102 . V_122 ;
}
V_2 -> V_151 = V_151 ;
V_2 -> V_736 = V_736 ;
V_35 -> V_102 . V_742 = V_147 ;
V_35 -> V_102 . V_743 = V_122 ;
V_101 -> V_744 += F_17 ( V_16 , V_745 ) ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ ) {
V_731 = F_17 ( V_16 , F_396 ( V_28 ) ) ;
V_730 += V_731 ;
V_101 -> V_731 [ V_28 ] += V_731 ;
V_729 += V_101 -> V_731 [ V_28 ] ;
V_101 -> V_746 [ V_28 ] += F_17 ( V_16 , F_397 ( V_28 ) ) ;
V_101 -> V_747 [ V_28 ] += F_17 ( V_16 , F_398 ( V_28 ) ) ;
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_101 -> V_748 [ V_28 ] += F_17 ( V_16 , F_399 ( V_28 ) ) ;
V_101 -> V_749 [ V_28 ] += F_17 ( V_16 , F_400 ( V_28 ) ) ;
V_101 -> V_750 [ V_28 ] += F_17 ( V_16 , F_401 ( V_28 ) ) ;
V_101 -> V_751 [ V_28 ] +=
F_17 ( V_16 , F_402 ( V_28 ) ) ;
break;
case V_91 :
case V_92 :
V_101 -> V_751 [ V_28 ] +=
F_17 ( V_16 , F_403 ( V_28 ) ) ;
break;
default:
break;
}
}
for ( V_28 = 0 ; V_28 < 16 ; V_28 ++ ) {
V_101 -> V_752 [ V_28 ] += F_17 ( V_16 , F_404 ( V_28 ) ) ;
V_101 -> V_753 [ V_28 ] += F_17 ( V_16 , F_405 ( V_28 ) ) ;
if ( ( V_16 -> V_88 . type == V_91 ) ||
( V_16 -> V_88 . type == V_92 ) ) {
V_101 -> V_749 [ V_28 ] += F_17 ( V_16 , F_406 ( V_28 ) ) ;
F_17 ( V_16 , F_407 ( V_28 ) ) ;
V_101 -> V_750 [ V_28 ] += F_17 ( V_16 , F_408 ( V_28 ) ) ;
F_17 ( V_16 , F_409 ( V_28 ) ) ;
}
}
V_101 -> V_754 += F_17 ( V_16 , V_755 ) ;
V_101 -> V_754 -= V_730 ;
F_63 ( V_2 ) ;
switch ( V_16 -> V_88 . type ) {
case V_89 :
V_101 -> V_756 += F_17 ( V_16 , V_757 ) ;
V_101 -> V_758 += F_17 ( V_16 , V_759 ) ;
V_101 -> V_760 += F_17 ( V_16 , V_761 ) ;
V_101 -> V_762 += F_17 ( V_16 , V_763 ) ;
break;
case V_92 :
V_101 -> V_764 += F_17 ( V_16 , V_765 ) ;
V_101 -> V_766 += F_17 ( V_16 , V_767 ) ;
V_101 -> V_768 += F_17 ( V_16 , V_769 ) ;
V_101 -> V_770 += F_17 ( V_16 , V_771 ) ;
case V_91 :
for ( V_28 = 0 ; V_28 < 16 ; V_28 ++ )
V_2 -> V_772 +=
F_17 ( V_16 , F_410 ( V_28 ) ) ;
V_101 -> V_758 += F_17 ( V_16 , V_773 ) ;
F_17 ( V_16 , V_759 ) ;
V_101 -> V_760 += F_17 ( V_16 , V_774 ) ;
F_17 ( V_16 , V_761 ) ;
V_101 -> V_762 += F_17 ( V_16 , V_775 ) ;
F_17 ( V_16 , V_763 ) ;
V_101 -> V_756 += F_17 ( V_16 , V_776 ) ;
V_101 -> V_777 += F_17 ( V_16 , V_778 ) ;
V_101 -> V_779 += F_17 ( V_16 , V_780 ) ;
#ifdef F_129
V_101 -> V_781 += F_17 ( V_16 , V_782 ) ;
V_101 -> V_783 += F_17 ( V_16 , V_784 ) ;
V_101 -> V_785 += F_17 ( V_16 , V_786 ) ;
V_101 -> V_787 += F_17 ( V_16 , V_788 ) ;
V_101 -> V_789 += F_17 ( V_16 , V_790 ) ;
V_101 -> V_791 += F_17 ( V_16 , V_792 ) ;
if ( V_2 -> V_663 . V_793 ) {
struct V_794 * V_663 = & V_2 -> V_663 ;
struct V_795 * V_793 ;
unsigned int V_152 ;
T_4 V_796 = 0 , V_797 = 0 ;
F_411 (cpu) {
V_793 = F_412 ( V_663 -> V_793 , V_152 ) ;
V_796 += V_793 -> V_796 ;
V_797 += V_793 -> V_797 ;
}
V_101 -> V_798 = V_796 ;
V_101 -> V_799 = V_797 ;
}
#endif
break;
default:
break;
}
V_732 = F_17 ( V_16 , V_800 ) ;
V_101 -> V_732 += V_732 ;
V_101 -> V_801 += F_17 ( V_16 , V_802 ) ;
if ( V_16 -> V_88 . type == V_89 )
V_101 -> V_801 -= V_732 ;
V_101 -> V_803 += F_17 ( V_16 , V_804 ) ;
V_101 -> V_805 += F_17 ( V_16 , V_806 ) ;
V_101 -> V_807 += F_17 ( V_16 , V_808 ) ;
V_101 -> V_809 += F_17 ( V_16 , V_810 ) ;
V_101 -> V_811 += F_17 ( V_16 , V_812 ) ;
V_101 -> V_813 += F_17 ( V_16 , V_814 ) ;
V_101 -> V_815 += F_17 ( V_16 , V_816 ) ;
V_101 -> V_817 += F_17 ( V_16 , V_818 ) ;
V_733 = F_17 ( V_16 , V_819 ) ;
V_101 -> V_820 += V_733 ;
V_734 = F_17 ( V_16 , V_821 ) ;
V_101 -> V_822 += V_734 ;
V_101 -> V_823 += F_17 ( V_16 , V_824 ) ;
V_101 -> V_825 += F_17 ( V_16 , V_826 ) ;
V_735 = V_733 + V_734 ;
V_101 -> V_823 -= V_735 ;
V_101 -> V_825 -= V_735 ;
V_101 -> V_760 -= ( V_735 * ( V_827 + V_492 ) ) ;
V_101 -> V_828 += F_17 ( V_16 , V_829 ) ;
V_101 -> V_830 += F_17 ( V_16 , V_831 ) ;
V_101 -> V_832 += F_17 ( V_16 , V_833 ) ;
V_101 -> V_834 += F_17 ( V_16 , V_835 ) ;
V_101 -> V_836 += F_17 ( V_16 , V_837 ) ;
V_101 -> V_836 -= V_735 ;
V_101 -> V_838 += F_17 ( V_16 , V_839 ) ;
V_101 -> V_840 += F_17 ( V_16 , V_841 ) ;
V_101 -> V_842 += F_17 ( V_16 , V_843 ) ;
V_101 -> V_844 += F_17 ( V_16 , V_845 ) ;
V_101 -> V_846 += F_17 ( V_16 , V_847 ) ;
V_101 -> V_848 += F_17 ( V_16 , V_849 ) ;
V_35 -> V_102 . V_850 = V_101 -> V_801 ;
V_35 -> V_102 . V_851 = V_101 -> V_744 + V_101 -> V_817 ;
V_35 -> V_102 . V_852 = 0 ;
V_35 -> V_102 . V_853 = V_101 -> V_817 ;
V_35 -> V_102 . V_854 = V_101 -> V_744 ;
V_35 -> V_102 . V_855 = V_729 ;
}
static void F_413 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_28 ;
if ( ! ( V_2 -> V_131 & V_364 ) )
return;
V_2 -> V_131 &= ~ V_364 ;
if ( F_8 ( V_22 , & V_2 -> V_23 ) )
return;
if ( ! ( V_2 -> V_117 & V_363 ) )
return;
V_2 -> V_856 ++ ;
if ( F_414 ( V_16 ) == 0 ) {
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ )
F_226 ( V_372 ,
& ( V_2 -> V_38 [ V_28 ] -> V_23 ) ) ;
F_51 ( V_16 , V_354 , V_365 ) ;
} else {
F_83 ( V_149 , L_98
L_99 ) ;
}
}
static void F_415 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_4 V_857 = 0 ;
int V_28 ;
if ( F_8 ( V_22 , & V_2 -> V_23 ) ||
F_8 ( V_628 , & V_2 -> V_23 ) )
return;
if ( F_89 ( V_2 -> V_35 ) ) {
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ )
F_416 ( V_2 -> V_38 [ V_28 ] ) ;
}
if ( ! ( V_2 -> V_117 & V_387 ) ) {
F_51 ( V_16 , V_97 ,
( V_858 | V_859 ) ) ;
} else {
for ( V_28 = 0 ; V_28 < V_2 -> V_166 ; V_28 ++ ) {
struct V_134 * V_860 = V_2 -> V_135 [ V_28 ] ;
if ( V_860 -> V_294 . V_98 || V_860 -> V_139 . V_98 )
V_857 |= ( ( T_4 ) 1 << V_28 ) ;
}
}
F_55 ( V_2 , V_857 ) ;
}
static void F_417 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_861 = V_2 -> V_861 ;
bool V_338 = V_2 -> V_338 ;
bool V_113 = V_2 -> V_114 . V_115 ;
if ( ! ( V_2 -> V_117 & V_350 ) )
return;
if ( V_16 -> V_88 . V_336 . V_337 ) {
V_16 -> V_88 . V_336 . V_337 ( V_16 , & V_861 , & V_338 , false ) ;
} else {
V_861 = V_862 ;
V_338 = true ;
}
if ( V_2 -> V_116 )
V_113 |= ! ! ( V_2 -> V_116 -> V_113 ) ;
if ( V_338 && ! ( ( V_2 -> V_117 & V_118 ) && V_113 ) ) {
V_16 -> V_88 . V_336 . V_863 ( V_16 ) ;
F_418 ( V_2 ) ;
}
if ( V_338 ||
F_419 ( V_148 , ( V_2 -> V_351 +
V_864 ) ) ) {
V_2 -> V_117 &= ~ V_350 ;
F_51 ( V_16 , V_354 , V_353 ) ;
F_194 ( V_16 ) ;
}
V_2 -> V_338 = V_338 ;
V_2 -> V_861 = V_861 ;
}
static void F_420 ( struct V_1 * V_2 )
{
#ifdef F_305
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_865 V_866 = {
. V_867 = V_868 ,
. V_220 = 0 ,
} ;
T_6 V_664 = 0 ;
if ( V_2 -> V_557 & V_869 )
V_664 = F_421 ( V_35 , & V_866 ) ;
V_2 -> V_870 = ( V_664 > 1 ) ? ( F_422 ( V_664 ) - 1 ) : 0 ;
#endif
}
static void F_423 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_861 = V_2 -> V_861 ;
bool V_871 , V_872 ;
if ( F_89 ( V_35 ) )
return;
V_2 -> V_131 &= ~ V_600 ;
switch ( V_16 -> V_88 . type ) {
case V_89 : {
T_1 V_873 = F_17 ( V_16 , V_540 ) ;
T_1 V_874 = F_17 ( V_16 , V_875 ) ;
V_871 = ! ! ( V_873 & V_876 ) ;
V_872 = ! ! ( V_874 & V_877 ) ;
}
break;
case V_92 :
case V_91 : {
T_1 V_878 = F_17 ( V_16 , V_879 ) ;
T_1 V_880 = F_17 ( V_16 , V_881 ) ;
V_871 = ! ! ( V_878 & V_882 ) ;
V_872 = ! ! ( V_880 & V_883 ) ;
}
break;
default:
V_872 = false ;
V_871 = false ;
break;
}
V_2 -> V_884 = V_148 ;
if ( V_2 -> V_131 & V_637 )
F_424 ( V_2 ) ;
F_85 ( V_133 , L_100 ,
( V_861 == V_862 ?
L_101 :
( V_861 == V_885 ?
L_102 :
( V_861 == V_886 ?
L_103 :
L_104 ) ) ) ,
( ( V_871 && V_872 ) ? L_105 :
( V_871 ? L_106 :
( V_872 ? L_107 : L_108 ) ) ) ) ;
F_425 ( V_35 ) ;
F_426 ( V_2 ) ;
F_420 ( V_2 ) ;
F_339 ( V_2 ) ;
}
static void F_427 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
V_2 -> V_338 = false ;
V_2 -> V_861 = 0 ;
if ( ! F_89 ( V_35 ) )
return;
if ( F_309 ( V_16 ) && V_16 -> V_88 . type == V_89 )
V_2 -> V_131 |= V_600 ;
if ( V_2 -> V_131 & V_637 )
F_424 ( V_2 ) ;
F_85 ( V_133 , L_109 ) ;
F_336 ( V_35 ) ;
F_339 ( V_2 ) ;
}
static void F_428 ( struct V_1 * V_2 )
{
int V_28 ;
int V_887 = 0 ;
if ( ! F_89 ( V_2 -> V_35 ) ) {
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ ) {
struct V_37 * V_38 = V_2 -> V_38 [ V_28 ] ;
if ( V_38 -> V_60 != V_38 -> V_59 ) {
V_887 = 1 ;
break;
}
}
if ( V_887 ) {
F_73 ( V_133 , L_110 ) ;
V_2 -> V_131 |= V_132 ;
}
}
}
static void F_429 ( struct V_1 * V_2 )
{
T_1 V_888 ;
if ( V_2 -> V_16 . V_88 . type == V_89 ||
V_2 -> V_302 == 0 )
return;
V_888 = F_17 ( & V_2 -> V_16 , V_889 ) ;
if ( ! V_888 )
return;
F_73 ( V_133 , L_111 , V_888 ) ;
}
static void F_430 ( struct V_1 * V_2 )
{
if ( F_8 ( V_22 , & V_2 -> V_23 ) ||
F_8 ( V_628 , & V_2 -> V_23 ) )
return;
F_417 ( V_2 ) ;
if ( V_2 -> V_338 )
F_423 ( V_2 ) ;
else
F_427 ( V_2 ) ;
F_429 ( V_2 ) ;
F_395 ( V_2 ) ;
F_428 ( V_2 ) ;
}
static void F_431 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_3 V_18 ;
if ( ! ( V_2 -> V_131 & V_600 ) &&
! ( V_2 -> V_131 & V_347 ) )
return;
if ( F_8 ( V_890 , & V_2 -> V_23 ) )
return;
if ( F_9 ( V_629 , & V_2 -> V_23 ) )
return;
V_18 = V_16 -> V_339 . V_336 . V_891 ( V_16 ) ;
if ( V_18 == V_632 )
goto V_892;
if ( V_18 == V_631 ) {
V_2 -> V_131 |= V_347 ;
}
if ( V_18 )
goto V_892;
if ( ! ( V_2 -> V_131 & V_347 ) )
goto V_892;
V_2 -> V_131 &= ~ V_347 ;
if ( V_16 -> V_88 . type == V_89 )
V_18 = V_16 -> V_339 . V_336 . V_893 ( V_16 ) ;
else
V_18 = V_16 -> V_88 . V_336 . V_894 ( V_16 ) ;
if ( V_18 == V_632 )
goto V_892;
V_2 -> V_117 |= V_348 ;
F_85 ( V_149 , L_112 , V_16 -> V_339 . V_895 ) ;
V_892:
F_14 ( V_629 , & V_2 -> V_23 ) ;
if ( ( V_18 == V_632 ) &&
( V_2 -> V_35 -> V_896 == V_897 ) ) {
F_324 ( L_113
L_114 ) ;
F_324 ( L_115
L_116 ) ;
F_432 ( V_2 -> V_35 ) ;
}
}
static void F_433 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_21 ;
bool V_601 = false ;
if ( ! ( V_2 -> V_117 & V_348 ) )
return;
if ( F_9 ( V_629 , & V_2 -> V_23 ) )
return;
V_2 -> V_117 &= ~ V_348 ;
V_21 = V_16 -> V_339 . V_604 ;
if ( ( ! V_21 ) && ( V_16 -> V_88 . V_336 . V_605 ) )
V_16 -> V_88 . V_336 . V_605 ( V_16 , & V_21 , & V_601 ) ;
if ( V_16 -> V_88 . V_336 . V_606 )
V_16 -> V_88 . V_336 . V_606 ( V_16 , V_21 , true ) ;
V_2 -> V_117 |= V_350 ;
V_2 -> V_351 = V_148 ;
F_14 ( V_629 , & V_2 -> V_23 ) ;
}
static void F_434 ( struct V_1 * V_2 )
{
int V_898 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_34 * V_35 = V_2 -> V_35 ;
T_1 V_899 ;
T_1 V_900 , V_901 ;
V_899 = F_17 ( V_16 , V_902 ) ;
if ( V_899 )
return;
for ( V_898 = 0 ; V_898 < V_2 -> V_302 ; V_898 ++ ) {
V_900 = ( V_898 << 16 ) | 0x80000000 ;
V_900 |= V_903 ;
F_51 ( V_16 , V_904 , V_900 ) ;
V_901 = F_17 ( V_16 , V_905 ) ;
V_900 &= 0x7FFFFFFF ;
F_51 ( V_16 , V_904 , V_900 ) ;
V_901 >>= 16 ;
if ( V_901 & V_906 ) {
F_435 ( V_35 , L_117 , V_898 ) ;
V_900 = ( V_898 << 16 ) | 0x80000000 ;
V_900 |= 0xA8 ;
F_51 ( V_16 , V_904 , V_900 ) ;
V_901 = 0x00008000 ;
F_51 ( V_16 , V_905 , V_901 ) ;
V_900 &= 0x7FFFFFFF ;
F_51 ( V_16 , V_904 , V_900 ) ;
}
}
}
static void F_436 ( unsigned long V_72 )
{
struct V_1 * V_2 = (struct V_1 * ) V_72 ;
unsigned long V_907 ;
bool V_908 = true ;
if ( V_2 -> V_117 & V_350 )
V_907 = V_909 / 10 ;
else
V_907 = V_909 * 2 ;
#ifdef F_348
if ( ! V_2 -> V_302 ||
( V_2 -> V_117 & V_350 ) )
goto V_910;
F_434 ( V_2 ) ;
V_907 = V_909 / 50 ;
V_2 -> V_911 ++ ;
if ( V_2 -> V_911 >= 100 )
V_2 -> V_911 = 0 ;
else
V_908 = false ;
V_910:
#endif
F_316 ( & V_2 -> V_626 , V_907 + V_148 ) ;
if ( V_908 )
F_7 ( V_2 ) ;
}
static void F_437 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_131 & V_132 ) )
return;
V_2 -> V_131 &= ~ V_132 ;
if ( F_8 ( V_22 , & V_2 -> V_23 ) ||
F_8 ( V_628 , & V_2 -> V_23 ) )
return;
F_34 ( V_2 ) ;
F_435 ( V_2 -> V_35 , L_118 ) ;
V_2 -> V_150 ++ ;
F_317 ( V_2 ) ;
}
static void F_438 ( struct V_912 * V_913 )
{
struct V_1 * V_2 = F_178 ( V_913 ,
struct V_1 ,
V_25 ) ;
F_437 ( V_2 ) ;
F_431 ( V_2 ) ;
F_433 ( V_2 ) ;
F_188 ( V_2 ) ;
F_430 ( V_2 ) ;
F_413 ( V_2 ) ;
F_415 ( V_2 ) ;
if ( V_2 -> V_131 & V_637 ) {
F_439 ( V_2 ) ;
F_440 ( V_2 ) ;
}
F_11 ( V_2 ) ;
}
static int F_441 ( struct V_37 * V_38 ,
struct V_39 * V_914 ,
T_6 * V_238 )
{
struct V_172 * V_69 = V_914 -> V_69 ;
T_1 V_915 , V_916 ;
T_1 V_917 , V_918 ;
if ( V_69 -> V_195 != V_919 )
return 0 ;
if ( ! F_442 ( V_69 ) )
return 0 ;
if ( F_443 ( V_69 ) ) {
int V_18 = F_444 ( V_69 , 0 , 0 , V_200 ) ;
if ( V_18 )
return V_18 ;
}
V_916 = V_920 ;
if ( V_914 -> V_220 == F_127 ( V_228 ) ) {
struct V_215 * V_921 = F_445 ( V_69 ) ;
V_921 -> V_922 = 0 ;
V_921 -> V_923 = 0 ;
F_446 ( V_69 ) -> V_923 = ~ F_447 ( V_921 -> V_924 ,
V_921 -> V_925 , 0 ,
V_234 ,
0 ) ;
V_916 |= V_926 ;
V_914 -> V_927 |= V_928 |
V_929 |
V_930 ;
} else if ( F_448 ( V_69 ) ) {
F_449 ( V_69 ) -> V_931 = 0 ;
F_446 ( V_69 ) -> V_923 =
~ F_450 ( & F_449 ( V_69 ) -> V_924 ,
& F_449 ( V_69 ) -> V_925 ,
0 , V_234 , 0 ) ;
V_914 -> V_927 |= V_928 |
V_929 ;
}
V_918 = F_451 ( V_69 ) ;
* V_238 = F_452 ( V_69 ) + V_918 ;
V_914 -> V_145 = F_132 ( V_69 ) -> V_145 ;
V_914 -> V_144 += ( V_914 -> V_145 - 1 ) * * V_238 ;
V_917 = V_918 << V_932 ;
V_917 |= F_132 ( V_69 ) -> V_239 << V_933 ;
V_915 = F_453 ( V_69 ) ;
V_915 |= F_454 ( V_69 ) << V_934 ;
V_915 |= V_914 -> V_927 & V_935 ;
F_455 ( V_38 , V_915 , 0 , V_916 ,
V_917 ) ;
return 1 ;
}
static void F_456 ( struct V_37 * V_38 ,
struct V_39 * V_914 )
{
struct V_172 * V_69 = V_914 -> V_69 ;
T_1 V_915 = 0 ;
T_1 V_917 = 0 ;
T_1 V_916 = 0 ;
if ( V_69 -> V_195 != V_919 ) {
if ( ! ( V_914 -> V_927 & V_936 ) &&
! ( V_914 -> V_927 & V_937 ) )
return;
} else {
T_6 V_938 = 0 ;
switch ( V_914 -> V_220 ) {
case F_127 ( V_228 ) :
V_915 |= F_453 ( V_69 ) ;
V_916 |= V_926 ;
V_938 = F_445 ( V_69 ) -> V_220 ;
break;
case F_127 ( V_231 ) :
V_915 |= F_453 ( V_69 ) ;
V_938 = F_449 ( V_69 ) -> V_221 ;
break;
default:
if ( F_77 ( F_457 () ) ) {
F_458 ( V_38 -> V_53 ,
L_119 ,
V_914 -> V_220 ) ;
}
break;
}
switch ( V_938 ) {
case V_234 :
V_916 |= V_920 ;
V_917 = F_451 ( V_69 ) <<
V_932 ;
break;
case V_939 :
V_916 |= V_940 ;
V_917 = sizeof( struct V_941 ) <<
V_932 ;
break;
case V_236 :
V_917 = sizeof( struct V_237 ) <<
V_932 ;
break;
default:
if ( F_77 ( F_457 () ) ) {
F_458 ( V_38 -> V_53 ,
L_120 ,
V_938 ) ;
}
break;
}
V_914 -> V_927 |= V_929 ;
}
V_915 |= F_454 ( V_69 ) << V_934 ;
V_915 |= V_914 -> V_927 & V_935 ;
F_455 ( V_38 , V_915 , 0 ,
V_916 , V_917 ) ;
}
static T_1 F_459 ( struct V_172 * V_69 , T_1 V_927 )
{
T_1 V_942 = V_943 |
V_944 |
V_945 ;
V_942 |= F_460 ( V_927 , V_936 ,
V_946 ) ;
V_942 |= F_460 ( V_927 , V_928 ,
V_947 ) ;
V_942 |= F_460 ( V_927 , V_948 ,
V_949 ) ;
V_942 ^= F_460 ( V_69 -> V_950 , 1 , V_945 ) ;
return V_942 ;
}
static void F_461 ( union V_41 * V_42 ,
T_1 V_927 , unsigned int V_951 )
{
T_1 V_952 = V_951 << V_953 ;
V_952 |= F_460 ( V_927 ,
V_929 ,
V_954 ) ;
V_952 |= F_460 ( V_927 ,
V_930 ,
V_955 ) ;
V_952 |= F_460 ( V_927 ,
V_937 ,
V_956 ) ;
V_42 -> V_206 . V_952 = F_76 ( V_952 ) ;
}
static void F_462 ( struct V_37 * V_38 ,
struct V_39 * V_914 ,
const T_6 V_238 )
{
struct V_172 * V_69 = V_914 -> V_69 ;
struct V_39 * V_40 ;
union V_41 * V_42 ;
struct V_259 * V_260 ;
T_8 V_61 ;
unsigned int V_265 , V_274 ;
T_1 V_927 = V_914 -> V_927 ;
T_1 V_942 = F_459 ( V_69 , V_927 ) ;
T_2 V_28 = V_38 -> V_60 ;
V_42 = F_41 ( V_38 , V_28 ) ;
F_461 ( V_42 , V_927 , V_69 -> V_62 - V_238 ) ;
V_274 = F_131 ( V_69 ) ;
V_265 = V_69 -> V_265 ;
#ifdef F_129
if ( V_927 & V_957 ) {
if ( V_265 < sizeof( struct V_293 ) ) {
V_274 -= sizeof( struct V_293 ) - V_265 ;
V_265 = 0 ;
} else {
V_265 -= sizeof( struct V_293 ) ;
}
}
#endif
V_61 = F_463 ( V_38 -> V_53 , V_69 -> V_72 , V_274 , V_99 ) ;
V_40 = V_914 ;
for ( V_260 = & F_132 ( V_69 ) -> V_261 [ 0 ] ; ; V_260 ++ ) {
if ( F_122 ( V_38 -> V_53 , V_61 ) )
goto V_958;
F_61 ( V_40 , V_62 , V_274 ) ;
F_464 ( V_40 , V_61 , V_61 ) ;
V_42 -> V_206 . V_959 = F_125 ( V_61 ) ;
while ( F_77 ( V_274 > V_960 ) ) {
V_42 -> V_206 . V_961 =
F_76 ( V_942 ^ V_960 ) ;
V_28 ++ ;
V_42 ++ ;
if ( V_28 == V_38 -> V_68 ) {
V_42 = F_41 ( V_38 , 0 ) ;
V_28 = 0 ;
}
V_42 -> V_206 . V_952 = 0 ;
V_61 += V_960 ;
V_274 -= V_960 ;
V_42 -> V_206 . V_959 = F_125 ( V_61 ) ;
}
if ( F_79 ( ! V_265 ) )
break;
V_42 -> V_206 . V_961 = F_76 ( V_942 ^ V_274 ) ;
V_28 ++ ;
V_42 ++ ;
if ( V_28 == V_38 -> V_68 ) {
V_42 = F_41 ( V_38 , 0 ) ;
V_28 = 0 ;
}
V_42 -> V_206 . V_952 = 0 ;
#ifdef F_129
V_274 = F_344 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_274 = F_465 ( V_260 ) ;
#endif
V_265 -= V_274 ;
V_61 = F_466 ( V_38 -> V_53 , V_260 , 0 , V_274 ,
V_99 ) ;
V_40 = & V_38 -> V_58 [ V_28 ] ;
}
V_942 |= V_274 | V_962 ;
V_42 -> V_206 . V_961 = F_76 ( V_942 ) ;
F_467 ( F_87 ( V_38 ) , V_914 -> V_144 ) ;
V_914 -> V_64 = V_148 ;
F_115 () ;
V_914 -> V_63 = V_42 ;
V_28 ++ ;
if ( V_28 == V_38 -> V_68 )
V_28 = 0 ;
V_38 -> V_60 = V_28 ;
F_116 ( V_28 , V_38 -> V_125 ) ;
return;
V_958:
F_357 ( V_38 -> V_53 , L_121 ) ;
for (; ; ) {
V_40 = & V_38 -> V_58 [ V_28 ] ;
F_57 ( V_38 , V_40 ) ;
if ( V_40 == V_914 )
break;
if ( V_28 == 0 )
V_28 = V_38 -> V_68 ;
V_28 -- ;
}
V_38 -> V_60 = V_28 ;
}
static void F_468 ( struct V_37 * V_98 ,
struct V_39 * V_914 )
{
struct V_134 * V_135 = V_98 -> V_135 ;
union V_963 V_964 = { . V_965 = 0 } ;
union V_963 V_966 = { . V_965 = 0 } ;
union {
unsigned char * V_210 ;
struct V_215 * V_216 ;
struct V_217 * V_218 ;
} V_219 ;
struct V_235 * V_967 ;
T_9 V_968 ;
if ( ! V_135 )
return;
if ( ! V_98 -> V_398 )
return;
V_98 -> V_399 ++ ;
V_219 . V_210 = F_469 ( V_914 -> V_69 ) ;
if ( ( V_914 -> V_220 != F_127 ( V_231 ) ||
V_219 . V_218 -> V_221 != V_234 ) &&
( V_914 -> V_220 != F_127 ( V_228 ) ||
V_219 . V_216 -> V_220 != V_234 ) )
return;
V_967 = F_446 ( V_914 -> V_69 ) ;
if ( ! V_967 || V_967 -> V_969 )
return;
if ( ! V_967 -> V_970 && ( V_98 -> V_399 < V_98 -> V_398 ) )
return;
V_98 -> V_399 = 0 ;
V_968 = F_128 ( V_914 -> V_927 >> V_971 ) ;
V_964 . V_972 . V_968 = V_968 ;
if ( V_914 -> V_927 & ( V_973 | V_936 ) )
V_966 . V_974 . V_975 ^= V_967 -> V_976 ^ F_127 ( V_225 ) ;
else
V_966 . V_974 . V_975 ^= V_967 -> V_976 ^ V_914 -> V_220 ;
V_966 . V_974 . V_977 ^= V_967 -> V_978 ;
if ( V_914 -> V_220 == F_127 ( V_228 ) ) {
V_964 . V_972 . V_979 = V_980 ;
V_966 . V_981 ^= V_219 . V_216 -> V_924 ^ V_219 . V_216 -> V_925 ;
} else {
V_964 . V_972 . V_979 = V_982 ;
V_966 . V_981 ^= V_219 . V_218 -> V_924 . V_983 [ 0 ] ^
V_219 . V_218 -> V_924 . V_983 [ 1 ] ^
V_219 . V_218 -> V_924 . V_983 [ 2 ] ^
V_219 . V_218 -> V_924 . V_983 [ 3 ] ^
V_219 . V_218 -> V_925 . V_983 [ 0 ] ^
V_219 . V_218 -> V_925 . V_983 [ 1 ] ^
V_219 . V_218 -> V_925 . V_983 [ 2 ] ^
V_219 . V_218 -> V_925 . V_983 [ 3 ] ;
}
F_470 ( & V_135 -> V_2 -> V_16 ,
V_964 , V_966 , V_98 -> V_66 ) ;
}
static int F_471 ( struct V_37 * V_38 , T_2 V_274 )
{
F_84 ( V_38 -> V_35 , V_38 -> V_66 ) ;
F_91 () ;
if ( F_79 ( F_90 ( V_38 ) < V_274 ) )
return - V_710 ;
F_472 ( V_38 -> V_35 , V_38 -> V_66 ) ;
++ V_38 -> V_128 . V_151 ;
return 0 ;
}
static inline int F_473 ( struct V_37 * V_38 , T_2 V_274 )
{
if ( F_79 ( F_90 ( V_38 ) >= V_274 ) )
return 0 ;
return F_471 ( V_38 , V_274 ) ;
}
static T_2 F_474 ( struct V_34 * V_53 , struct V_172 * V_69 )
{
struct V_1 * V_2 ;
struct V_984 * V_985 ;
int V_986 ;
switch ( F_475 ( V_69 ) ) {
case F_127 ( V_232 ) :
case F_127 ( V_987 ) :
V_2 = F_69 ( V_53 ) ;
if ( V_2 -> V_117 & V_495 )
break;
default:
return F_476 ( V_53 , V_69 ) ;
}
V_985 = & V_2 -> V_413 [ V_988 ] ;
V_986 = F_477 ( V_69 ) ? F_478 ( V_69 ) :
F_479 () ;
while ( V_986 >= V_985 -> V_415 )
V_986 -= V_985 -> V_415 ;
return V_986 + V_985 -> V_989 ;
}
T_13 F_480 ( struct V_172 * V_69 ,
struct V_1 * V_2 ,
struct V_37 * V_38 )
{
struct V_39 * V_914 ;
int V_990 ;
T_1 V_927 = 0 ;
unsigned short V_985 ;
T_2 V_68 = F_481 ( F_131 ( V_69 ) ) ;
T_9 V_220 = V_69 -> V_220 ;
T_6 V_238 = 0 ;
for ( V_985 = 0 ; V_985 < F_132 ( V_69 ) -> V_280 ; V_985 ++ )
V_68 += F_481 ( F_132 ( V_69 ) -> V_261 [ V_985 ] . V_274 ) ;
if ( F_473 ( V_38 , V_68 + 3 ) ) {
V_38 -> V_128 . V_736 ++ ;
return V_991 ;
}
V_914 = & V_38 -> V_58 [ V_38 -> V_60 ] ;
V_914 -> V_69 = V_69 ;
V_914 -> V_144 = V_69 -> V_62 ;
V_914 -> V_145 = 1 ;
if ( F_482 ( V_69 ) ) {
V_927 |= F_483 ( V_69 ) << V_971 ;
V_927 |= V_936 ;
} else if ( V_220 == F_127 ( V_225 ) ) {
struct V_213 * V_992 , V_993 ;
V_992 = F_484 ( V_69 , V_223 , sizeof( V_993 ) , & V_993 ) ;
if ( ! V_992 )
goto V_994;
V_220 = V_992 -> V_227 ;
V_927 |= F_485 ( V_992 -> V_995 ) <<
V_971 ;
V_927 |= V_973 ;
}
F_486 ( V_69 ) ;
if ( F_77 ( F_132 ( V_69 ) -> V_927 & V_996 ) ) {
F_132 ( V_69 ) -> V_927 |= V_997 ;
V_927 |= V_948 ;
V_2 -> V_998 = F_487 ( V_69 ) ;
V_2 -> V_999 = V_148 ;
F_10 ( & V_2 -> V_1000 ) ;
}
#ifdef F_348
if ( V_2 -> V_117 & V_408 )
V_927 |= V_937 ;
#endif
if ( ( V_2 -> V_117 & V_118 ) &&
( ( V_927 & ( V_936 | V_973 ) ) ||
( V_69 -> V_1001 != V_1002 ) ) ) {
V_927 &= ~ V_1003 ;
V_927 |= ( V_69 -> V_1001 & 0x7 ) <<
V_1004 ;
if ( V_927 & V_973 ) {
struct V_1005 * V_992 ;
if ( F_443 ( V_69 ) &&
F_444 ( V_69 , 0 , 0 , V_200 ) )
goto V_994;
V_992 = (struct V_1005 * ) V_69 -> V_72 ;
V_992 -> V_995 = F_128 ( V_927 >>
V_971 ) ;
} else {
V_927 |= V_936 ;
}
}
V_914 -> V_927 = V_927 ;
V_914 -> V_220 = V_220 ;
#ifdef F_129
if ( ( V_220 == F_127 ( V_232 ) ) &&
( V_38 -> V_35 -> V_173 & ( V_1006 | V_1007 ) ) ) {
V_990 = F_488 ( V_38 , V_914 , & V_238 ) ;
if ( V_990 < 0 )
goto V_994;
goto V_1008;
}
#endif
V_990 = F_441 ( V_38 , V_914 , & V_238 ) ;
if ( V_990 < 0 )
goto V_994;
else if ( ! V_990 )
F_456 ( V_38 , V_914 ) ;
if ( F_8 ( V_372 , & V_38 -> V_23 ) )
F_468 ( V_38 , V_914 ) ;
#ifdef F_129
V_1008:
#endif
F_462 ( V_38 , V_914 , V_238 ) ;
F_473 ( V_38 , V_1009 ) ;
return V_1010 ;
V_994:
F_58 ( V_914 -> V_69 ) ;
V_914 -> V_69 = NULL ;
return V_1010 ;
}
static T_13 F_489 ( struct V_172 * V_69 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
struct V_37 * V_38 ;
if ( F_77 ( V_69 -> V_62 < 17 ) ) {
if ( F_158 ( V_69 , 17 - V_69 -> V_62 ) )
return V_1010 ;
V_69 -> V_62 = 17 ;
F_490 ( V_69 , 17 ) ;
}
V_38 = V_2 -> V_38 [ V_69 -> V_1011 ] ;
return F_480 ( V_69 , V_2 , V_38 ) ;
}
static int F_491 ( struct V_34 * V_35 , void * V_461 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_1012 * V_533 = V_461 ;
if ( ! F_492 ( V_533 -> V_1013 ) )
return - V_1014 ;
memcpy ( V_35 -> V_1015 , V_533 -> V_1013 , V_35 -> V_1016 ) ;
memcpy ( V_16 -> V_88 . V_533 , V_533 -> V_1013 , V_35 -> V_1016 ) ;
V_16 -> V_88 . V_336 . V_532 ( V_16 , 0 , V_16 -> V_88 . V_533 , F_246 ( 0 ) , V_534 ) ;
return 0 ;
}
static int
F_493 ( struct V_34 * V_35 , int V_1017 , int V_1018 , T_2 V_533 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
T_2 V_4 ;
int V_1019 ;
if ( V_1017 != V_16 -> V_339 . V_1020 . V_1017 )
return - V_708 ;
V_1019 = V_16 -> V_339 . V_336 . V_1021 ( V_16 , V_533 , V_1018 , & V_4 ) ;
if ( ! V_1019 )
V_1019 = V_4 ;
return V_1019 ;
}
static int F_494 ( struct V_34 * V_35 , int V_1017 , int V_1018 ,
T_2 V_533 , T_2 V_4 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
if ( V_1017 != V_16 -> V_339 . V_1020 . V_1017 )
return - V_708 ;
return V_16 -> V_339 . V_336 . V_1022 ( V_16 , V_533 , V_1018 , V_4 ) ;
}
static int F_495 ( struct V_34 * V_35 , struct V_1023 * V_1024 , int V_1025 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
switch ( V_1025 ) {
case V_1026 :
return F_496 ( V_2 , V_1024 , V_1025 ) ;
default:
return F_497 ( & V_2 -> V_16 . V_339 . V_1020 , F_498 ( V_1024 ) , V_1025 ) ;
}
}
static int F_499 ( struct V_34 * V_53 )
{
int V_18 = 0 ;
struct V_1 * V_2 = F_69 ( V_53 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
if ( F_492 ( V_16 -> V_88 . V_1027 ) ) {
F_383 () ;
V_18 = F_500 ( V_53 , V_16 -> V_88 . V_1027 , V_1028 ) ;
F_385 () ;
V_16 -> V_88 . V_336 . V_636 ( V_16 , F_246 ( 0 ) ) ;
}
return V_18 ;
}
static int F_501 ( struct V_34 * V_53 )
{
int V_18 = 0 ;
struct V_1 * V_2 = F_69 ( V_53 ) ;
struct V_1029 * V_88 = & V_2 -> V_16 . V_88 ;
if ( F_492 ( V_88 -> V_1027 ) ) {
F_383 () ;
V_18 = F_502 ( V_53 , V_88 -> V_1027 , V_1028 ) ;
F_385 () ;
}
return V_18 ;
}
static void F_503 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
int V_28 ;
if ( F_8 ( V_22 , & V_2 -> V_23 ) )
return;
V_2 -> V_117 |= V_248 ;
if ( V_2 -> V_117 & V_387 ) {
for ( V_28 = 0 ; V_28 < V_2 -> V_166 ; V_28 ++ )
F_204 ( 0 , V_2 -> V_135 [ V_28 ] ) ;
} else {
F_217 ( V_2 -> V_10 -> V_366 , V_35 ) ;
}
V_2 -> V_117 &= ~ V_248 ;
}
static struct V_1030 * F_504 ( struct V_34 * V_35 ,
struct V_1030 * V_102 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
int V_28 ;
F_505 () ;
for ( V_28 = 0 ; V_28 < V_2 -> V_73 ; V_28 ++ ) {
struct V_37 * V_98 = F_506 ( V_2 -> V_47 [ V_28 ] ) ;
T_4 V_147 , V_122 ;
unsigned int V_1031 ;
if ( V_98 ) {
do {
V_1031 = F_507 ( & V_98 -> V_146 ) ;
V_122 = V_98 -> V_102 . V_122 ;
V_147 = V_98 -> V_102 . V_147 ;
} while ( F_508 ( & V_98 -> V_146 , V_1031 ) );
V_102 -> V_741 += V_122 ;
V_102 -> V_740 += V_147 ;
}
}
for ( V_28 = 0 ; V_28 < V_2 -> V_57 ; V_28 ++ ) {
struct V_37 * V_98 = F_506 ( V_2 -> V_38 [ V_28 ] ) ;
T_4 V_147 , V_122 ;
unsigned int V_1031 ;
if ( V_98 ) {
do {
V_1031 = F_507 ( & V_98 -> V_146 ) ;
V_122 = V_98 -> V_102 . V_122 ;
V_147 = V_98 -> V_102 . V_147 ;
} while ( F_508 ( & V_98 -> V_146 , V_1031 ) );
V_102 -> V_743 += V_122 ;
V_102 -> V_742 += V_147 ;
}
}
F_509 () ;
V_102 -> V_850 = V_35 -> V_102 . V_850 ;
V_102 -> V_851 = V_35 -> V_102 . V_851 ;
V_102 -> V_853 = V_35 -> V_102 . V_853 ;
V_102 -> V_854 = V_35 -> V_102 . V_854 ;
V_102 -> V_855 = V_35 -> V_102 . V_855 ;
return V_102 ;
}
static void F_510 ( struct V_1 * V_2 , T_6 V_112 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_3 , V_1032 ;
int V_28 ;
if ( V_16 -> V_88 . type == V_89 )
return;
V_3 = F_17 ( V_16 , V_1033 ) ;
V_1032 = V_3 ;
for ( V_28 = 0 ; V_28 < V_675 ; V_28 ++ ) {
T_6 V_1034 = V_3 >> ( V_28 * V_1035 ) ;
if ( V_1034 > V_112 )
V_3 &= ~ ( 0x7 << V_1035 ) ;
}
if ( V_3 != V_1032 )
F_51 ( V_16 , V_1033 , V_3 ) ;
return;
}
static void F_511 ( struct V_1 * V_2 )
{
struct V_34 * V_53 = V_2 -> V_35 ;
struct V_1036 * V_114 = & V_2 -> V_114 ;
struct V_1037 * V_1038 = V_2 -> V_561 ;
T_6 V_1039 ;
for ( V_1039 = 0 ; V_1039 < V_1040 ; V_1039 ++ ) {
T_6 V_112 = 0 ;
if ( V_2 -> V_557 & V_558 )
V_112 = F_512 ( V_114 , 0 , V_1039 ) ;
else if ( V_1038 )
V_112 = V_1038 -> V_562 [ V_1039 ] ;
F_513 ( V_53 , V_1039 , V_112 ) ;
}
}
int F_514 ( struct V_34 * V_53 , T_6 V_112 )
{
struct V_1 * V_2 = F_69 ( V_53 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
if ( V_112 > V_2 -> V_114 . V_671 . V_672 ||
( V_16 -> V_88 . type == V_89 &&
V_112 < V_675 ) )
return - V_708 ;
if ( F_37 ( V_53 ) )
F_373 ( V_53 ) ;
F_390 ( V_2 ) ;
#ifdef F_305
if ( V_112 ) {
F_515 ( V_53 , V_112 ) ;
F_511 ( V_2 ) ;
V_2 -> V_117 |= V_118 ;
if ( V_2 -> V_16 . V_88 . type == V_89 ) {
V_2 -> V_1041 = V_2 -> V_16 . V_103 . V_687 ;
V_2 -> V_16 . V_103 . V_687 = V_1042 ;
}
} else {
F_516 ( V_53 ) ;
if ( V_2 -> V_16 . V_88 . type == V_89 )
V_2 -> V_16 . V_103 . V_687 = V_2 -> V_1041 ;
V_2 -> V_117 &= ~ V_118 ;
V_2 -> V_686 . V_115 = false ;
V_2 -> V_114 . V_115 = false ;
}
F_510 ( V_2 , V_112 ) ;
#endif
F_384 ( V_2 ) ;
if ( F_37 ( V_53 ) )
return F_369 ( V_53 ) ;
return 0 ;
}
void F_517 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
F_383 () ;
F_514 ( V_35 , F_230 ( V_35 ) ) ;
F_385 () ;
}
void F_518 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
if ( F_37 ( V_35 ) )
F_317 ( V_2 ) ;
else
F_323 ( V_2 ) ;
}
static T_14 F_519 ( struct V_34 * V_35 ,
T_14 V_173 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
if ( ! ( V_173 & V_186 ) )
V_173 &= ~ V_1043 ;
if ( ! ( V_2 -> V_131 & V_656 ) )
V_173 &= ~ V_1043 ;
return V_173 ;
}
static int F_520 ( struct V_34 * V_35 ,
T_14 V_173 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
T_14 V_1044 = V_35 -> V_173 ^ V_173 ;
bool V_1045 = false ;
if ( ! ( V_173 & V_1043 ) ) {
if ( V_2 -> V_131 & V_503 )
V_1045 = true ;
V_2 -> V_131 &= ~ V_503 ;
} else if ( ( V_2 -> V_131 & V_656 ) &&
! ( V_2 -> V_131 & V_503 ) ) {
if ( V_2 -> V_378 == 1 ||
V_2 -> V_378 > V_1046 ) {
V_2 -> V_131 |= V_503 ;
V_1045 = true ;
} else if ( ( V_1044 ^ V_173 ) & V_1043 ) {
F_85 ( V_149 , L_122
L_123 ) ;
}
}
switch ( V_173 & V_1047 ) {
case V_1047 :
if ( ! ( V_2 -> V_117 & V_575 ) )
V_1045 = true ;
V_2 -> V_117 &= ~ V_363 ;
V_2 -> V_117 |= V_575 ;
break;
default:
if ( V_2 -> V_117 & V_575 )
V_1045 = true ;
V_2 -> V_117 &= ~ V_575 ;
if ( V_2 -> V_117 & V_408 )
break;
if ( F_230 ( V_35 ) > 1 )
break;
if ( V_2 -> V_413 [ V_414 ] . V_655 <= 1 )
break;
if ( ! V_2 -> V_398 )
break;
V_2 -> V_117 |= V_363 ;
break;
}
if ( V_173 & V_245 )
F_261 ( V_2 ) ;
else
F_260 ( V_2 ) ;
if ( V_1044 & V_268 )
V_1045 = true ;
V_35 -> V_173 = V_173 ;
if ( V_1045 )
F_518 ( V_35 ) ;
return 0 ;
}
static int F_521 ( struct V_1048 * V_1049 , struct V_1050 * V_1051 [] ,
struct V_34 * V_53 ,
const unsigned char * V_533 ,
T_2 V_117 )
{
struct V_1 * V_2 = F_69 ( V_53 ) ;
int V_18 ;
if ( ! ( V_2 -> V_117 & V_408 ) )
return F_522 ( V_1049 , V_1051 , V_53 , V_533 , V_117 ) ;
if ( V_1049 -> V_1052 && ! ( V_1049 -> V_1052 & V_1053 ) ) {
F_31 ( L_124 ,
V_1054 ) ;
return - V_708 ;
}
if ( F_523 ( V_533 ) || F_524 ( V_533 ) ) {
T_1 V_1055 = V_528 ;
if ( F_265 ( V_53 ) < V_1055 )
V_18 = F_525 ( V_53 , V_533 ) ;
else
V_18 = - V_529 ;
} else if ( F_526 ( V_533 ) ) {
V_18 = F_527 ( V_53 , V_533 ) ;
} else {
V_18 = - V_708 ;
}
if ( V_18 == - V_1056 && ! ( V_117 & V_1057 ) )
V_18 = 0 ;
return V_18 ;
}
static int F_528 ( struct V_34 * V_53 ,
struct V_1058 * V_1059 )
{
struct V_1 * V_2 = F_69 ( V_53 ) ;
struct V_1050 * V_1060 , * V_1061 ;
int V_1062 ;
if ( ! ( V_2 -> V_117 & V_408 ) )
return - V_1063 ;
V_1061 = F_529 ( V_1059 , sizeof( struct V_1064 ) , V_1065 ) ;
F_530 (attr, br_spec, rem) {
T_15 V_1066 ;
T_1 V_3 = 0 ;
if ( F_531 ( V_1060 ) != V_1067 )
continue;
V_1066 = F_532 ( V_1060 ) ;
if ( V_1066 == V_1068 ) {
V_3 = 0 ;
V_2 -> V_131 &= ~ V_477 ;
} else if ( V_1066 == V_1069 ) {
V_3 = V_479 ;
V_2 -> V_131 |= V_477 ;
} else
return - V_708 ;
F_51 ( & V_2 -> V_16 , V_478 , V_3 ) ;
F_85 ( V_133 , L_125 ,
V_1066 == V_1068 ? L_126 : L_127 ) ;
}
return 0 ;
}
static int F_533 ( struct V_172 * V_69 , T_1 V_1070 , T_1 V_1071 ,
struct V_34 * V_53 ,
T_1 V_1072 )
{
struct V_1 * V_2 = F_69 ( V_53 ) ;
T_2 V_1066 ;
if ( ! ( V_2 -> V_117 & V_408 ) )
return 0 ;
if ( V_2 -> V_131 & V_477 )
V_1066 = V_1069 ;
else
V_1066 = V_1068 ;
return F_534 ( V_69 , V_1070 , V_1071 , V_53 , V_1066 ) ;
}
int F_535 ( struct V_1 * V_2 , T_2 V_332 ,
T_2 V_1073 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_2 V_1074 = V_2 -> V_1075 & V_1076 ;
int V_1077 = 0 ;
switch ( V_332 ) {
case V_1078 :
switch ( V_1073 ) {
case V_1079 :
if ( V_16 -> V_11 . V_1080 != 0 )
break;
case V_1081 :
case V_1082 :
case V_1083 :
case V_1084 :
case V_1085 :
V_1077 = 1 ;
break;
}
break;
case V_1086 :
switch ( V_1073 ) {
case V_1087 :
V_1077 = 1 ;
break;
}
break;
case V_1088 :
if ( V_1073 != V_1089 )
V_1077 = 1 ;
break;
case V_1090 :
V_1077 = 1 ;
break;
case V_1091 :
case V_1092 :
if ( ( V_1074 == V_1093 ) ||
( ( V_1074 == V_1094 ) &&
( V_16 -> V_11 . V_1080 == 0 ) ) ) {
V_1077 = 1 ;
}
break;
}
return V_1077 ;
}
static int F_536 ( struct V_6 * V_10 , const struct V_1095 * V_1096 )
{
struct V_34 * V_35 ;
struct V_1 * V_2 = NULL ;
struct V_15 * V_16 ;
const struct V_1097 * V_1098 = V_1099 [ V_1096 -> V_1100 ] ;
static int V_1101 ;
int V_28 , V_18 , V_1102 ;
unsigned int V_415 = V_1103 ;
T_6 V_1104 [ V_1105 ] ;
#ifdef F_129
T_2 V_1106 ;
#endif
T_1 V_1107 ;
if ( V_10 -> V_1108 ) {
F_537 ( 1 , V_1109 L_128 ,
F_538 ( V_10 ) , V_10 -> V_647 , V_10 -> V_167 ) ;
return - V_708 ;
}
V_18 = F_380 ( V_10 ) ;
if ( V_18 )
return V_18 ;
if ( ! F_539 ( & V_10 -> V_53 , F_224 ( 64 ) ) &&
! F_540 ( & V_10 -> V_53 , F_224 ( 64 ) ) ) {
V_1102 = 1 ;
} else {
V_18 = F_539 ( & V_10 -> V_53 , F_224 ( 32 ) ) ;
if ( V_18 ) {
V_18 = F_540 ( & V_10 -> V_53 ,
F_224 ( 32 ) ) ;
if ( V_18 ) {
F_357 ( & V_10 -> V_53 ,
L_129 ) ;
goto V_1110;
}
}
V_1102 = 0 ;
}
V_18 = F_541 ( V_10 , F_542 ( V_10 ,
V_1111 ) , V_1054 ) ;
if ( V_18 ) {
F_357 ( & V_10 -> V_53 ,
L_130 , V_18 ) ;
goto V_1112;
}
F_543 ( V_10 ) ;
F_381 ( V_10 ) ;
F_379 ( V_10 ) ;
if ( V_1098 -> V_88 == V_89 ) {
#ifdef F_305
V_415 = 4 * V_675 ;
#else
V_415 = V_654 ;
#endif
}
V_35 = F_544 ( sizeof( struct V_1 ) , V_415 ) ;
if ( ! V_35 ) {
V_18 = - V_529 ;
goto V_1113;
}
F_545 ( V_35 , & V_10 -> V_53 ) ;
V_2 = F_69 ( V_35 ) ;
F_546 ( V_10 , V_2 ) ;
V_2 -> V_35 = V_35 ;
V_2 -> V_10 = V_10 ;
V_16 = & V_2 -> V_16 ;
V_16 -> V_1114 = V_2 ;
V_2 -> V_1115 = F_547 ( V_1116 , V_1117 ) ;
V_16 -> V_396 = F_548 ( F_549 ( V_10 , 0 ) ,
F_550 ( V_10 , 0 ) ) ;
if ( ! V_16 -> V_396 ) {
V_18 = - V_700 ;
goto V_1118;
}
V_35 -> V_1119 = & V_1120 ;
F_551 ( V_35 ) ;
V_35 -> V_1121 = 5 * V_909 ;
strncpy ( V_35 -> V_33 , F_538 ( V_10 ) , sizeof( V_35 -> V_33 ) - 1 ) ;
V_2 -> V_1122 = V_1101 ;
memcpy ( & V_16 -> V_88 . V_336 , V_1098 -> V_1123 , sizeof( V_16 -> V_88 . V_336 ) ) ;
V_16 -> V_88 . type = V_1098 -> V_88 ;
memcpy ( & V_16 -> V_1124 . V_336 , V_1098 -> V_1125 , sizeof( V_16 -> V_1124 . V_336 ) ) ;
V_1107 = F_17 ( V_16 , V_1126 ) ;
if ( ! ( V_1107 & ( 1 << 8 ) ) )
V_16 -> V_1124 . V_336 . V_206 = & V_1127 ;
memcpy ( & V_16 -> V_339 . V_336 , V_1098 -> V_1128 , sizeof( V_16 -> V_339 . V_336 ) ) ;
V_16 -> V_339 . V_895 = V_1129 ;
V_16 -> V_339 . V_1020 . V_1017 = V_1130 ;
V_16 -> V_339 . V_1020 . V_1131 = 0 ;
V_16 -> V_339 . V_1020 . V_1132 = V_1133 | V_1134 ;
V_16 -> V_339 . V_1020 . V_53 = V_35 ;
V_16 -> V_339 . V_1020 . V_1135 = F_493 ;
V_16 -> V_339 . V_1020 . V_1136 = F_494 ;
V_1098 -> V_1137 ( V_16 ) ;
V_18 = F_343 ( V_2 ) ;
if ( V_18 )
goto V_1138;
if ( V_16 -> V_88 . V_336 . V_1139 )
V_16 -> V_1139 = V_16 -> V_88 . V_336 . V_1139 ( V_16 ) ;
switch ( V_2 -> V_16 . V_88 . type ) {
case V_91 :
case V_92 :
F_51 ( & V_2 -> V_16 , V_714 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_117 & V_342 ) {
T_1 V_623 = F_17 ( V_16 , V_624 ) ;
if ( V_623 & V_625 )
F_189 ( V_149 , L_60 ) ;
}
if ( V_1140 )
V_16 -> V_1140 = V_1140 ;
V_16 -> V_339 . V_1141 = true ;
V_18 = V_16 -> V_88 . V_336 . V_1142 ( V_16 ) ;
V_16 -> V_339 . V_1141 = false ;
if ( V_18 == V_631 &&
V_16 -> V_88 . type == V_89 ) {
V_18 = 0 ;
} else if ( V_18 == V_632 ) {
F_324 ( L_131
L_132 ) ;
F_324 ( L_133
L_134 ) ;
goto V_1138;
} else if ( V_18 ) {
F_324 ( L_135 , V_18 ) ;
goto V_1138;
}
#ifdef F_348
if ( V_2 -> V_16 . V_88 . type == V_89 )
goto V_1143;
F_552 ( V_16 ) ;
memcpy ( & V_16 -> V_1144 . V_336 , V_1098 -> V_1145 , sizeof( V_16 -> V_1144 . V_336 ) ) ;
F_553 ( V_2 ) ;
F_554 ( V_10 , 63 ) ;
V_1143:
#endif
V_35 -> V_173 = V_1146 |
V_1147 |
V_1148 |
V_1149 |
V_245 |
V_1150 |
V_1151 |
V_1152 |
V_174 |
V_186 ;
V_35 -> V_1153 = V_35 -> V_173 ;
switch ( V_2 -> V_16 . V_88 . type ) {
case V_91 :
case V_92 :
V_35 -> V_173 |= V_1154 ;
V_35 -> V_1153 |= V_1154 |
V_1047 ;
break;
default:
break;
}
V_35 -> V_1153 |= V_268 ;
V_35 -> V_1155 |= V_1151 ;
V_35 -> V_1155 |= V_1152 ;
V_35 -> V_1155 |= V_1147 ;
V_35 -> V_1155 |= V_1148 ;
V_35 -> V_1155 |= V_1146 ;
V_35 -> V_1156 |= V_1157 ;
V_35 -> V_1156 |= V_1158 ;
#ifdef F_305
V_35 -> V_1159 = & V_1159 ;
#endif
#ifdef F_129
if ( V_2 -> V_117 & V_662 ) {
unsigned int V_1160 ;
if ( V_16 -> V_88 . V_336 . V_1161 ) {
V_16 -> V_88 . V_336 . V_1161 ( V_16 , & V_1106 ) ;
if ( V_1106 & V_1162 )
V_2 -> V_117 &= ~ V_662 ;
}
V_1160 = F_344 ( int , V_1163 , F_345 () ) ;
V_2 -> V_413 [ V_988 ] . V_655 = V_1160 ;
V_35 -> V_173 |= V_1006 |
V_1007 ;
V_35 -> V_1155 |= V_1006 |
V_1007 |
V_556 ;
}
#endif
if ( V_1102 ) {
V_35 -> V_173 |= V_1164 ;
V_35 -> V_1155 |= V_1164 ;
}
if ( V_2 -> V_131 & V_656 )
V_35 -> V_1153 |= V_1043 ;
if ( V_2 -> V_131 & V_503 )
V_35 -> V_173 |= V_1043 ;
if ( V_16 -> V_1124 . V_336 . V_1165 ( V_16 , NULL ) < 0 ) {
F_324 ( L_136 ) ;
V_18 = - V_700 ;
goto V_1138;
}
memcpy ( V_35 -> V_1015 , V_16 -> V_88 . V_1166 , V_35 -> V_1016 ) ;
if ( ! F_492 ( V_35 -> V_1015 ) ) {
F_324 ( L_137 ) ;
V_18 = - V_700 ;
goto V_1138;
}
F_555 ( & V_2 -> V_626 , & F_436 ,
( unsigned long ) V_2 ) ;
F_556 ( & V_2 -> V_25 , F_438 ) ;
F_14 ( V_24 , & V_2 -> V_23 ) ;
V_18 = F_384 ( V_2 ) ;
if ( V_18 )
goto V_1138;
V_2 -> V_718 = 0 ;
V_16 -> V_1124 . V_336 . V_206 ( V_16 , 0x2c , & V_2 -> V_1075 ) ;
V_16 -> V_1167 = F_535 ( V_2 , V_10 -> V_167 ,
V_10 -> V_653 ) ;
if ( V_16 -> V_1167 )
V_2 -> V_718 = V_1168 ;
F_557 ( & V_2 -> V_10 -> V_53 , V_2 -> V_718 ) ;
V_16 -> V_1124 . V_336 . V_206 ( V_16 , 0x2e , & V_2 -> V_1169 ) ;
V_16 -> V_1124 . V_336 . V_206 ( V_16 , 0x2d , & V_2 -> V_1170 ) ;
V_16 -> V_88 . V_336 . V_1171 ( V_16 ) ;
if ( V_16 -> V_332 == V_1172 )
F_4 ( V_2 ) ;
F_558 ( L_138 ,
( V_16 -> V_11 . V_21 == V_1173 ? L_139 :
V_16 -> V_11 . V_21 == V_1174 ? L_140 :
V_16 -> V_11 . V_21 == V_1175 ? L_141 :
L_142 ) ,
( V_16 -> V_11 . V_20 == V_1176 ? L_143 :
V_16 -> V_11 . V_20 == V_1177 ? L_144 :
V_16 -> V_11 . V_20 == V_1178 ? L_145 :
L_142 ) ,
V_35 -> V_1015 ) ;
V_18 = F_559 ( V_16 , V_1104 , V_1105 ) ;
if ( V_18 )
strncpy ( V_1104 , L_142 , V_1105 ) ;
if ( F_309 ( V_16 ) && V_16 -> V_339 . V_895 != V_1179 )
F_558 ( L_146 ,
V_16 -> V_88 . type , V_16 -> V_339 . type , V_16 -> V_339 . V_895 ,
V_1104 ) ;
else
F_558 ( L_147 ,
V_16 -> V_88 . type , V_16 -> V_339 . type , V_1104 ) ;
if ( V_16 -> V_11 . V_20 <= V_1177 ) {
F_325 ( L_148
L_149 ) ;
F_325 ( L_150
L_151 ) ;
}
V_18 = V_16 -> V_88 . V_336 . V_1180 ( V_16 ) ;
if ( V_18 == V_634 ) {
F_325 ( L_83
L_152
L_153
L_154
L_87
L_88 ) ;
}
strcpy ( V_35 -> V_33 , L_155 ) ;
V_18 = F_560 ( V_35 ) ;
if ( V_18 )
goto V_1181;
if ( V_16 -> V_88 . V_336 . V_642 )
V_16 -> V_88 . V_336 . V_642 ( V_16 ) ;
F_336 ( V_35 ) ;
#ifdef F_207
if ( F_106 ( & V_10 -> V_53 ) == 0 ) {
V_2 -> V_117 |= V_164 ;
F_103 ( V_2 ) ;
}
#endif
if ( V_2 -> V_117 & V_408 ) {
F_85 ( V_149 , L_156 , V_2 -> V_302 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_302 ; V_28 ++ )
F_561 ( V_10 , ( V_28 | 0x10000000 ) ) ;
}
if ( V_16 -> V_88 . V_336 . V_1182 )
V_16 -> V_88 . V_336 . V_1182 ( V_16 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_499 ( V_35 ) ;
F_558 ( L_157 , V_1183 ) ;
V_1101 ++ ;
#ifdef F_562
if ( F_563 ( V_2 ) )
F_83 ( V_149 , L_158 ) ;
#endif
F_564 ( V_2 ) ;
if ( V_16 -> V_1139 && V_16 -> V_88 . V_336 . V_606 )
V_16 -> V_88 . V_336 . V_606 ( V_16 ,
V_862 | V_885 ,
true ) ;
return 0 ;
V_1181:
F_50 ( V_2 ) ;
F_390 ( V_2 ) ;
V_1138:
F_565 ( V_2 ) ;
V_2 -> V_131 &= ~ V_600 ;
F_566 ( V_16 -> V_396 ) ;
V_1118:
F_567 ( V_35 ) ;
V_1113:
F_568 ( V_10 ,
F_542 ( V_10 , V_1111 ) ) ;
V_1112:
V_1110:
F_391 ( V_10 ) ;
return V_18 ;
}
static void F_569 ( struct V_6 * V_10 )
{
struct V_1 * V_2 = F_376 ( V_10 ) ;
struct V_34 * V_35 = V_2 -> V_35 ;
F_570 ( V_2 ) ;
F_226 ( V_22 , & V_2 -> V_23 ) ;
F_571 ( & V_2 -> V_25 ) ;
#ifdef F_207
if ( V_2 -> V_117 & V_164 ) {
V_2 -> V_117 &= ~ V_164 ;
F_107 ( & V_10 -> V_53 ) ;
F_51 ( & V_2 -> V_16 , V_165 , 1 ) ;
}
#endif
#ifdef F_562
F_572 ( V_2 ) ;
#endif
F_501 ( V_35 ) ;
if ( V_35 -> V_896 == V_897 )
F_432 ( V_35 ) ;
#ifdef F_348
if ( V_692 )
F_565 ( V_2 ) ;
#endif
F_390 ( V_2 ) ;
F_50 ( V_2 ) ;
#ifdef F_573
F_216 ( V_2 -> V_116 ) ;
F_216 ( V_2 -> V_561 ) ;
#endif
F_566 ( V_2 -> V_16 . V_396 ) ;
F_568 ( V_10 , F_542 ( V_10 ,
V_1111 ) ) ;
F_558 ( L_159 ) ;
F_567 ( V_35 ) ;
F_574 ( V_10 ) ;
F_391 ( V_10 ) ;
}
static T_16 F_575 ( struct V_6 * V_10 ,
T_17 V_23 )
{
struct V_1 * V_2 = F_376 ( V_10 ) ;
struct V_34 * V_35 = V_2 -> V_35 ;
#ifdef F_348
struct V_6 * V_1184 , * V_1185 ;
T_1 V_1186 , V_1187 , V_1188 , V_1189 ;
int V_898 , V_5 ;
T_2 V_1190 , V_1191 ;
if ( V_2 -> V_16 . V_88 . type == V_89 ||
V_2 -> V_302 == 0 )
goto V_1192;
V_1184 = V_10 -> V_11 -> V_13 ;
while ( V_1184 && ( F_576 ( V_1184 ) != V_1193 ) )
V_1184 = V_1184 -> V_11 -> V_13 ;
if ( ! V_1184 )
goto V_1192;
V_5 = F_577 ( V_1184 , V_1194 ) ;
if ( ! V_5 )
goto V_1192;
F_578 ( V_1184 , V_5 + V_1195 , & V_1186 ) ;
F_578 ( V_1184 , V_5 + V_1195 + 4 , & V_1187 ) ;
F_578 ( V_1184 , V_5 + V_1195 + 8 , & V_1188 ) ;
F_578 ( V_1184 , V_5 + V_1195 + 12 , & V_1189 ) ;
V_1190 = V_1187 >> 16 ;
if ( ! ( V_1190 & 0x0080 ) )
goto V_1192;
V_1191 = V_1190 & 0x01 ;
if ( ( V_1191 & 1 ) == ( V_10 -> V_1196 & 1 ) ) {
unsigned int V_332 ;
V_898 = ( V_1190 & 0x7F ) >> 1 ;
F_324 ( L_160 , V_898 ) ;
F_324 ( L_161
L_162 ,
V_1186 , V_1187 , V_1188 , V_1189 ) ;
switch ( V_2 -> V_16 . V_88 . type ) {
case V_91 :
V_332 = V_1197 ;
break;
case V_92 :
V_332 = V_1198 ;
break;
default:
V_332 = 0 ;
break;
}
V_1185 = F_579 ( V_1199 , V_332 , NULL ) ;
while ( V_1185 ) {
if ( V_1185 -> V_1196 == ( V_1190 & 0xFF ) )
break;
V_1185 = F_579 ( V_1199 ,
V_332 , V_1185 ) ;
}
if ( V_1185 ) {
F_324 ( L_163 , V_898 ) ;
F_580 ( V_1185 , 0xA8 , 0x00008000 ) ;
F_581 ( V_1185 ) ;
}
F_582 ( V_10 ) ;
}
V_2 -> V_1200 ++ ;
return V_1201 ;
V_1192:
#endif
F_389 ( V_35 ) ;
if ( V_23 == V_1202 )
return V_1203 ;
if ( F_37 ( V_35 ) )
F_320 ( V_2 ) ;
F_391 ( V_10 ) ;
return V_1204 ;
}
static T_16 F_583 ( struct V_6 * V_10 )
{
struct V_1 * V_2 = F_376 ( V_10 ) ;
T_16 V_1205 ;
int V_18 ;
if ( F_380 ( V_10 ) ) {
F_83 ( V_149 , L_164 ) ;
V_1205 = V_1203 ;
} else {
F_381 ( V_10 ) ;
F_378 ( V_10 ) ;
F_379 ( V_10 ) ;
F_382 ( V_10 , false ) ;
F_323 ( V_2 ) ;
F_51 ( & V_2 -> V_16 , V_714 , ~ 0 ) ;
V_1205 = V_1201 ;
}
V_18 = F_582 ( V_10 ) ;
if ( V_18 ) {
F_324 ( L_165
L_166 , V_18 ) ;
}
return V_1205 ;
}
static void F_584 ( struct V_6 * V_10 )
{
struct V_1 * V_2 = F_376 ( V_10 ) ;
struct V_34 * V_35 = V_2 -> V_35 ;
#ifdef F_348
if ( V_2 -> V_1200 ) {
F_85 ( V_133 , L_167 ) ;
V_2 -> V_1200 -- ;
return;
}
#endif
if ( F_37 ( V_35 ) )
F_322 ( V_2 ) ;
F_386 ( V_35 ) ;
}
static int T_18 F_585 ( void )
{
int V_130 ;
F_31 ( L_168 , V_1206 , V_1207 ) ;
F_31 ( L_157 , V_1208 ) ;
F_586 () ;
V_130 = F_587 ( & V_1209 ) ;
if ( V_130 ) {
F_588 () ;
return V_130 ;
}
#ifdef F_207
F_589 ( & V_1210 ) ;
#endif
return 0 ;
}
static void T_19 F_590 ( void )
{
#ifdef F_207
F_591 ( & V_1210 ) ;
#endif
F_592 ( & V_1209 ) ;
F_588 () ;
F_593 () ;
}
static int F_594 ( struct V_1211 * V_1212 , unsigned long V_168 ,
void * V_461 )
{
int V_1213 ;
V_1213 = F_595 ( & V_1209 . V_1214 , NULL , & V_168 ,
F_104 ) ;
return V_1213 ? V_1215 : V_1216 ;
}
