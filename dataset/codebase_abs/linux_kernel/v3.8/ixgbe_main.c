static void F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) &&
! F_3 ( V_5 , & V_2 -> V_4 ) )
F_4 ( & V_2 -> V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( ! F_2 ( V_5 , & V_2 -> V_4 ) ) ;
F_7 () ;
F_8 ( V_5 , & V_2 -> V_4 ) ;
}
static void F_9 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
int V_11 = 0 , V_12 = 0 ;
char V_13 [ 16 ] ;
T_1 V_14 [ 64 ] ;
switch ( V_10 -> V_15 ) {
case F_10 ( 0 ) :
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
V_14 [ V_11 ] = F_11 ( V_8 , F_10 ( V_11 ) ) ;
break;
case F_12 ( 0 ) :
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
V_14 [ V_11 ] = F_11 ( V_8 , F_12 ( V_11 ) ) ;
break;
case F_13 ( 0 ) :
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
V_14 [ V_11 ] = F_11 ( V_8 , F_13 ( V_11 ) ) ;
break;
case F_14 ( 0 ) :
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
V_14 [ V_11 ] = F_11 ( V_8 , F_14 ( V_11 ) ) ;
break;
case F_15 ( 0 ) :
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
V_14 [ V_11 ] = F_11 ( V_8 , F_15 ( V_11 ) ) ;
break;
case F_16 ( 0 ) :
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
V_14 [ V_11 ] = F_11 ( V_8 , F_16 ( V_11 ) ) ;
break;
case F_17 ( 0 ) :
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
V_14 [ V_11 ] = F_11 ( V_8 , F_17 ( V_11 ) ) ;
break;
case F_18 ( 0 ) :
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
V_14 [ V_11 ] = F_11 ( V_8 , F_18 ( V_11 ) ) ;
break;
case F_19 ( 0 ) :
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
V_14 [ V_11 ] = F_11 ( V_8 , F_19 ( V_11 ) ) ;
break;
case F_20 ( 0 ) :
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
V_14 [ V_11 ] = F_11 ( V_8 , F_20 ( V_11 ) ) ;
break;
case F_21 ( 0 ) :
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
V_14 [ V_11 ] = F_11 ( V_8 , F_21 ( V_11 ) ) ;
break;
case F_22 ( 0 ) :
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
V_14 [ V_11 ] = F_11 ( V_8 , F_22 ( V_11 ) ) ;
break;
case F_23 ( 0 ) :
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
V_14 [ V_11 ] = F_11 ( V_8 , F_23 ( V_11 ) ) ;
break;
case F_24 ( 0 ) :
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
V_14 [ V_11 ] = F_11 ( V_8 , F_24 ( V_11 ) ) ;
break;
default:
F_25 ( L_1 , V_10 -> V_16 ,
F_11 ( V_8 , V_10 -> V_15 ) ) ;
return;
}
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
snprintf ( V_13 , 16 , L_2 , V_10 -> V_16 , V_11 * 8 , V_11 * 8 + 7 ) ;
F_26 ( L_3 , V_13 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ )
F_27 ( L_4 , V_14 [ V_11 * 8 + V_12 ] ) ;
F_27 ( L_5 ) ;
}
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_9 * V_10 ;
int V_19 = 0 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
union V_24 * V_25 ;
struct V_26 { T_2 V_27 ; T_2 V_28 ; } * V_29 ;
struct V_20 * V_30 ;
union V_31 * V_32 ;
struct V_33 * V_34 ;
T_1 V_35 ;
int V_11 = 0 ;
if ( ! F_29 ( V_2 ) )
return;
if ( V_18 ) {
F_30 ( & V_2 -> V_36 -> V_37 , L_6 ) ;
F_25 ( L_7
L_8 ) ;
F_25 ( L_9 ,
V_18 -> V_16 ,
V_18 -> V_4 ,
V_18 -> V_38 ,
V_18 -> V_39 ) ;
}
F_30 ( & V_2 -> V_36 -> V_37 , L_10 ) ;
F_25 ( L_11 ) ;
for ( V_10 = (struct V_9 * ) V_40 ;
V_10 -> V_16 ; V_10 ++ ) {
F_9 ( V_8 , V_10 ) ;
}
if ( ! V_18 || ! F_31 ( V_18 ) )
goto exit;
F_30 ( & V_2 -> V_36 -> V_37 , L_12 ) ;
F_25 ( L_13 ,
L_14 ,
L_15 , L_16 , L_17 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_41 ; V_19 ++ ) {
V_21 = V_2 -> V_21 [ V_19 ] ;
V_23 = & V_21 -> V_42 [ V_21 -> V_43 ] ;
F_25 ( L_18 ,
V_19 , V_21 -> V_44 , V_21 -> V_43 ,
( T_2 ) F_32 ( V_23 , V_45 ) ,
F_33 ( V_23 , V_46 ) ,
V_23 -> V_47 ,
( T_2 ) V_23 -> V_48 ) ;
}
if ( ! F_34 ( V_2 ) )
goto V_49;
F_30 ( & V_2 -> V_36 -> V_37 , L_19 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_41 ; V_19 ++ ) {
V_21 = V_2 -> V_21 [ V_19 ] ;
F_25 ( L_20 ) ;
F_25 ( L_21 , V_21 -> V_50 ) ;
F_25 ( L_20 ) ;
F_25 ( L_22 ,
L_23 ,
L_24 ,
L_15 , L_16 , L_17 , L_25 ) ;
for ( V_11 = 0 ; V_21 -> V_51 && ( V_11 < V_21 -> V_52 ) ; V_11 ++ ) {
V_25 = F_35 ( V_21 , V_11 ) ;
V_23 = & V_21 -> V_42 [ V_11 ] ;
V_29 = (struct V_26 * ) V_25 ;
if ( F_33 ( V_23 , V_46 ) > 0 ) {
F_25 ( L_26 ,
V_11 ,
F_36 ( V_29 -> V_27 ) ,
F_36 ( V_29 -> V_28 ) ,
( T_2 ) F_32 ( V_23 , V_45 ) ,
F_33 ( V_23 , V_46 ) ,
V_23 -> V_47 ,
( T_2 ) V_23 -> V_48 ,
V_23 -> V_53 ) ;
if ( V_11 == V_21 -> V_44 &&
V_11 == V_21 -> V_43 )
F_27 ( L_27 ) ;
else if ( V_11 == V_21 -> V_44 )
F_27 ( L_28 ) ;
else if ( V_11 == V_21 -> V_43 )
F_27 ( L_29 ) ;
else
F_27 ( L_5 ) ;
if ( F_37 ( V_2 ) &&
V_23 -> V_53 )
F_38 ( V_54 , L_30 ,
V_55 , 16 , 1 ,
V_23 -> V_53 -> V_56 ,
F_33 ( V_23 , V_46 ) ,
true ) ;
}
}
}
V_49:
F_30 ( & V_2 -> V_36 -> V_37 , L_31 ) ;
F_25 ( L_32 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_57 ; V_19 ++ ) {
V_30 = V_2 -> V_30 [ V_19 ] ;
F_25 ( L_33 ,
V_19 , V_30 -> V_44 , V_30 -> V_43 ) ;
}
if ( ! F_39 ( V_2 ) )
goto exit;
F_30 ( & V_2 -> V_36 -> V_37 , L_34 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_57 ; V_19 ++ ) {
V_30 = V_2 -> V_30 [ V_19 ] ;
F_25 ( L_20 ) ;
F_25 ( L_35 , V_30 -> V_50 ) ;
F_25 ( L_20 ) ;
F_25 ( L_36 ,
L_37 ,
L_38 ,
L_39 ) ;
F_25 ( L_36 ,
L_40 ,
L_41 ,
L_42 ) ;
for ( V_11 = 0 ; V_11 < V_30 -> V_52 ; V_11 ++ ) {
V_34 = & V_30 -> V_34 [ V_11 ] ;
V_32 = F_40 ( V_30 , V_11 ) ;
V_29 = (struct V_26 * ) V_32 ;
V_35 = F_41 ( V_32 -> V_58 . V_59 . V_60 ) ;
if ( V_35 & V_61 ) {
F_25 ( L_43
L_44 , V_11 ,
F_36 ( V_29 -> V_27 ) ,
F_36 ( V_29 -> V_28 ) ,
V_34 -> V_53 ) ;
} else {
F_25 ( L_45
L_46 , V_11 ,
F_36 ( V_29 -> V_27 ) ,
F_36 ( V_29 -> V_28 ) ,
( T_2 ) V_34 -> V_45 ,
V_34 -> V_53 ) ;
if ( F_37 ( V_2 ) &&
V_34 -> V_45 ) {
F_38 ( V_54 , L_30 ,
V_55 , 16 , 1 ,
F_42 ( V_34 -> V_62 ) +
V_34 -> V_63 ,
F_43 ( V_30 ) , true ) ;
}
}
if ( V_11 == V_30 -> V_44 )
F_27 ( L_28 ) ;
else if ( V_11 == V_30 -> V_43 )
F_27 ( L_29 ) ;
else
F_27 ( L_5 ) ;
}
}
exit:
return;
}
static void F_44 ( struct V_1 * V_2 )
{
T_1 V_64 ;
V_64 = F_11 ( & V_2 -> V_8 , V_65 ) ;
F_45 ( & V_2 -> V_8 , V_65 ,
V_64 & ~ V_66 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
T_1 V_64 ;
V_64 = F_11 ( & V_2 -> V_8 , V_65 ) ;
F_45 ( & V_2 -> V_8 , V_65 ,
V_64 | V_66 ) ;
}
static void F_47 ( struct V_1 * V_2 , T_3 V_67 ,
T_4 V_68 , T_4 V_69 )
{
T_1 V_70 , V_71 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_69 |= V_74 ;
if ( V_67 == - 1 )
V_67 = 0 ;
V_71 = ( ( ( V_67 * 64 ) + V_68 ) >> 2 ) & 0x1F ;
V_70 = F_11 ( V_8 , F_48 ( V_71 ) ) ;
V_70 &= ~ ( 0xFF << ( 8 * ( V_68 & 0x3 ) ) ) ;
V_70 |= ( V_69 << ( 8 * ( V_68 & 0x3 ) ) ) ;
F_45 ( V_8 , F_48 ( V_71 ) , V_70 ) ;
break;
case V_75 :
case V_76 :
if ( V_67 == - 1 ) {
V_69 |= V_74 ;
V_71 = ( ( V_68 & 1 ) * 8 ) ;
V_70 = F_11 ( & V_2 -> V_8 , V_77 ) ;
V_70 &= ~ ( 0xFF << V_71 ) ;
V_70 |= ( V_69 << V_71 ) ;
F_45 ( & V_2 -> V_8 , V_77 , V_70 ) ;
break;
} else {
V_69 |= V_74 ;
V_71 = ( ( 16 * ( V_68 & 1 ) ) + ( 8 * V_67 ) ) ;
V_70 = F_11 ( V_8 , F_48 ( V_68 >> 1 ) ) ;
V_70 &= ~ ( 0xFF << V_71 ) ;
V_70 |= ( V_69 << V_71 ) ;
F_45 ( V_8 , F_48 ( V_68 >> 1 ) , V_70 ) ;
break;
}
default:
break;
}
}
static inline void F_49 ( struct V_1 * V_2 ,
T_2 V_78 )
{
T_1 V_79 ;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_73 :
V_79 = ( V_80 & V_78 ) ;
F_45 ( & V_2 -> V_8 , V_81 , V_79 ) ;
break;
case V_75 :
case V_76 :
V_79 = ( V_78 & 0xFFFFFFFF ) ;
F_45 ( & V_2 -> V_8 , F_50 ( 0 ) , V_79 ) ;
V_79 = ( V_78 >> 32 ) ;
F_45 ( & V_2 -> V_8 , F_50 ( 1 ) , V_79 ) ;
break;
default:
break;
}
}
void F_51 ( struct V_20 * V_82 ,
struct V_22 * V_23 )
{
if ( V_23 -> V_53 ) {
F_52 ( V_23 -> V_53 ) ;
if ( F_33 ( V_23 , V_46 ) )
F_53 ( V_82 -> V_37 ,
F_32 ( V_23 , V_45 ) ,
F_33 ( V_23 , V_46 ) ,
V_83 ) ;
} else if ( F_33 ( V_23 , V_46 ) ) {
F_54 ( V_82 -> V_37 ,
F_32 ( V_23 , V_45 ) ,
F_33 ( V_23 , V_46 ) ,
V_83 ) ;
}
V_23 -> V_47 = NULL ;
V_23 -> V_53 = NULL ;
F_55 ( V_23 , V_46 , 0 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_84 * V_85 = & V_2 -> V_86 ;
int V_11 ;
T_1 V_56 ;
if ( ( V_8 -> V_87 . V_88 != V_89 ) &&
( V_8 -> V_87 . V_88 != V_90 ) )
return;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_56 = F_11 ( V_8 , V_91 ) ;
break;
default:
V_56 = F_11 ( V_8 , V_92 ) ;
}
V_85 -> V_93 += V_56 ;
if ( ! V_56 )
return;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_8 ( V_94 ,
& V_2 -> V_21 [ V_11 ] -> V_4 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_84 * V_85 = & V_2 -> V_86 ;
T_1 V_95 [ 8 ] = { 0 } ;
T_4 V_96 ;
int V_11 ;
bool V_97 = V_2 -> V_98 . V_99 ;
if ( V_2 -> V_100 )
V_97 |= ! ! ( V_2 -> V_100 -> V_97 ) ;
if ( ! ( V_2 -> V_101 & V_102 ) || ! V_97 ) {
F_56 ( V_2 ) ;
return;
}
for ( V_11 = 0 ; V_11 < V_103 ; V_11 ++ ) {
T_1 V_104 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_104 = F_11 ( V_8 , F_58 ( V_11 ) ) ;
break;
default:
V_104 = F_11 ( V_8 , F_59 ( V_11 ) ) ;
}
V_85 -> V_104 [ V_11 ] += V_104 ;
V_96 = F_60 ( V_2 -> V_18 , V_11 ) ;
V_95 [ V_96 ] += V_104 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_21 = V_2 -> V_21 [ V_11 ] ;
V_96 = V_21 -> V_105 ;
if ( V_95 [ V_96 ] )
F_8 ( V_94 , & V_21 -> V_4 ) ;
}
}
static T_2 F_61 ( struct V_20 * V_82 )
{
return V_82 -> V_86 . V_106 ;
}
static T_2 F_62 ( struct V_20 * V_82 )
{
struct V_1 * V_2 = F_63 ( V_82 -> V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_107 = F_11 ( V_8 , F_22 ( V_82 -> V_108 ) ) ;
T_1 V_109 = F_11 ( V_8 , F_23 ( V_82 -> V_108 ) ) ;
if ( V_107 != V_109 )
return ( V_107 < V_109 ) ?
V_109 - V_107 : ( V_109 + V_82 -> V_52 - V_107 ) ;
return 0 ;
}
static inline bool F_64 ( struct V_20 * V_21 )
{
T_1 V_110 = F_61 ( V_21 ) ;
T_1 V_111 = V_21 -> V_112 . V_111 ;
T_1 V_113 = F_62 ( V_21 ) ;
bool V_114 = false ;
F_65 ( V_21 ) ;
if ( ( V_111 == V_110 ) && V_113 ) {
V_114 = F_3 ( V_94 ,
& V_21 -> V_4 ) ;
} else {
V_21 -> V_112 . V_111 = V_110 ;
F_8 ( V_94 , & V_21 -> V_4 ) ;
}
return V_114 ;
}
static void F_66 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_115 |= V_116 ;
F_1 ( V_2 ) ;
}
}
static bool F_67 ( struct V_117 * V_118 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
struct V_22 * V_23 ;
union V_24 * V_25 ;
unsigned int V_119 = 0 , V_120 = 0 ;
unsigned int V_121 = V_118 -> V_122 . V_123 ;
unsigned int V_11 = V_21 -> V_43 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return true ;
V_23 = & V_21 -> V_42 [ V_11 ] ;
V_25 = F_35 ( V_21 , V_11 ) ;
V_11 -= V_21 -> V_52 ;
do {
union V_24 * V_124 = V_23 -> V_47 ;
if ( ! V_124 )
break;
F_68 () ;
if ( ! ( V_124 -> V_58 . V_125 & F_69 ( V_126 ) ) )
break;
V_23 -> V_47 = NULL ;
V_119 += V_23 -> V_127 ;
V_120 += V_23 -> V_128 ;
if ( F_70 ( V_23 -> V_129 & V_130 ) )
F_71 ( V_118 , V_23 -> V_53 ) ;
F_52 ( V_23 -> V_53 ) ;
F_53 ( V_21 -> V_37 ,
F_32 ( V_23 , V_45 ) ,
F_33 ( V_23 , V_46 ) ,
V_83 ) ;
V_23 -> V_53 = NULL ;
F_55 ( V_23 , V_46 , 0 ) ;
while ( V_25 != V_124 ) {
V_23 ++ ;
V_25 ++ ;
V_11 ++ ;
if ( F_70 ( ! V_11 ) ) {
V_11 -= V_21 -> V_52 ;
V_23 = V_21 -> V_42 ;
V_25 = F_35 ( V_21 , 0 ) ;
}
if ( F_33 ( V_23 , V_46 ) ) {
F_54 ( V_21 -> V_37 ,
F_32 ( V_23 , V_45 ) ,
F_33 ( V_23 , V_46 ) ,
V_83 ) ;
F_55 ( V_23 , V_46 , 0 ) ;
}
}
V_23 ++ ;
V_25 ++ ;
V_11 ++ ;
if ( F_70 ( ! V_11 ) ) {
V_11 -= V_21 -> V_52 ;
V_23 = V_21 -> V_42 ;
V_25 = F_35 ( V_21 , 0 ) ;
}
F_72 ( V_25 ) ;
V_121 -- ;
} while ( F_73 ( V_121 ) );
V_11 += V_21 -> V_52 ;
V_21 -> V_43 = V_11 ;
F_74 ( & V_21 -> V_131 ) ;
V_21 -> V_86 . V_132 += V_119 ;
V_21 -> V_86 . V_106 += V_120 ;
F_75 ( & V_21 -> V_131 ) ;
V_118 -> V_122 . V_119 += V_119 ;
V_118 -> V_122 . V_120 += V_120 ;
if ( F_76 ( V_21 ) && F_64 ( V_21 ) ) {
struct V_7 * V_8 = & V_2 -> V_8 ;
F_77 ( V_133 , L_47
L_48
L_49
L_50
L_51
L_52
L_53
L_54 ,
V_21 -> V_50 ,
F_11 ( V_8 , F_22 ( V_21 -> V_108 ) ) ,
F_11 ( V_8 , F_23 ( V_21 -> V_108 ) ) ,
V_21 -> V_44 , V_11 ,
V_21 -> V_42 [ V_11 ] . V_48 , V_134 ) ;
F_78 ( V_21 -> V_18 , V_21 -> V_50 ) ;
F_79 ( V_135 ,
L_55 ,
V_2 -> V_136 + 1 , V_21 -> V_50 ) ;
F_66 ( V_2 ) ;
return true ;
}
F_80 ( F_81 ( V_21 ) ,
V_120 , V_119 ) ;
#define F_82 (DESC_NEEDED * 2)
if ( F_70 ( V_120 && F_83 ( V_21 -> V_18 ) &&
( F_84 ( V_21 ) >= F_82 ) ) ) {
F_85 () ;
if ( F_86 ( V_21 -> V_18 ,
V_21 -> V_50 )
&& ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_87 ( V_21 -> V_18 ,
V_21 -> V_50 ) ;
++ V_21 -> V_112 . V_137 ;
}
}
return ! ! V_121 ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
int V_138 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_139 = F_89 ( V_21 -> V_37 , V_138 ) ;
T_5 V_140 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_140 = F_90 ( V_21 -> V_108 ) ;
break;
case V_75 :
case V_76 :
V_140 = F_91 ( V_21 -> V_108 ) ;
V_139 <<= V_141 ;
break;
default:
return;
}
V_139 |= V_142 |
V_143 |
V_144 ;
F_45 ( V_8 , V_140 , V_139 ) ;
}
static void F_92 ( struct V_1 * V_2 ,
struct V_20 * V_30 ,
int V_138 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_145 = F_89 ( V_30 -> V_37 , V_138 ) ;
T_4 V_108 = V_30 -> V_108 ;
switch ( V_8 -> V_72 . type ) {
case V_75 :
case V_76 :
V_145 <<= V_146 ;
break;
default:
break;
}
V_145 |= V_147 |
V_148 ;
F_45 ( V_8 , F_12 ( V_108 ) , V_145 ) ;
}
static void F_93 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
struct V_20 * V_82 ;
int V_138 = F_94 () ;
if ( V_118 -> V_138 == V_138 )
goto V_149;
F_95 (ring, q_vector->tx)
F_88 ( V_2 , V_82 , V_138 ) ;
F_95 (ring, q_vector->rx)
F_92 ( V_2 , V_82 , V_138 ) ;
V_118 -> V_138 = V_138 ;
V_149:
F_96 () ;
}
static void F_97 ( struct V_1 * V_2 )
{
int V_11 ;
if ( ! ( V_2 -> V_101 & V_150 ) )
return;
F_45 ( & V_2 -> V_8 , V_151 , 2 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_152 ; V_11 ++ ) {
V_2 -> V_118 [ V_11 ] -> V_138 = - 1 ;
F_93 ( V_2 -> V_118 [ V_11 ] ) ;
}
}
static int F_98 ( struct V_153 * V_37 , void * V_56 )
{
struct V_1 * V_2 = F_99 ( V_37 ) ;
unsigned long V_154 = * ( unsigned long * ) V_56 ;
if ( ! ( V_2 -> V_101 & V_155 ) )
return 0 ;
switch ( V_154 ) {
case V_156 :
if ( V_2 -> V_101 & V_150 )
break;
if ( F_100 ( V_37 ) == 0 ) {
V_2 -> V_101 |= V_150 ;
F_97 ( V_2 ) ;
break;
}
case V_157 :
if ( V_2 -> V_101 & V_150 ) {
F_101 ( V_37 ) ;
V_2 -> V_101 &= ~ V_150 ;
F_45 ( & V_2 -> V_8 , V_151 , 1 ) ;
}
break;
}
return 0 ;
}
static inline void F_102 ( struct V_20 * V_82 ,
union V_31 * V_32 ,
struct V_158 * V_53 )
{
if ( V_82 -> V_18 -> V_159 & V_160 )
V_53 -> V_161 = F_41 ( V_32 -> V_58 . V_162 . V_163 . V_164 ) ;
}
static inline bool F_103 ( struct V_20 * V_82 ,
union V_31 * V_32 )
{
T_6 V_165 = V_32 -> V_58 . V_162 . V_166 . V_167 . V_165 ;
return F_2 ( V_168 , & V_82 -> V_4 ) &&
( ( V_165 & F_104 ( V_169 ) ) ==
( F_104 ( V_170 <<
V_171 ) ) ) ;
}
static inline void F_105 ( struct V_20 * V_82 ,
union V_31 * V_32 ,
struct V_158 * V_53 )
{
F_106 ( V_53 ) ;
if ( ! ( V_82 -> V_18 -> V_159 & V_172 ) )
return;
if ( F_107 ( V_32 , V_173 ) &&
F_107 ( V_32 , V_174 ) ) {
V_82 -> V_175 . V_176 ++ ;
return;
}
if ( ! F_107 ( V_32 , V_177 ) )
return;
if ( F_107 ( V_32 , V_178 ) ) {
T_6 V_165 = V_32 -> V_58 . V_162 . V_166 . V_167 . V_165 ;
if ( ( V_165 & F_104 ( V_179 ) ) &&
F_2 ( V_180 , & V_82 -> V_4 ) )
return;
V_82 -> V_175 . V_176 ++ ;
return;
}
V_53 -> V_181 = V_182 ;
}
static inline void F_108 ( struct V_20 * V_30 , T_1 V_183 )
{
V_30 -> V_44 = V_183 ;
V_30 -> V_184 = V_183 ;
F_109 () ;
F_110 ( V_183 , V_30 -> V_109 ) ;
}
static bool F_111 ( struct V_20 * V_30 ,
struct V_33 * V_185 )
{
struct V_62 * V_62 = V_185 -> V_62 ;
T_7 V_45 = V_185 -> V_45 ;
if ( F_73 ( V_45 ) )
return true ;
if ( F_73 ( ! V_62 ) ) {
V_62 = F_112 ( V_186 | V_187 | V_188 ,
V_185 -> V_53 , F_113 ( V_30 ) ) ;
if ( F_70 ( ! V_62 ) ) {
V_30 -> V_175 . V_189 ++ ;
return false ;
}
V_185 -> V_62 = V_62 ;
}
V_45 = F_114 ( V_30 -> V_37 , V_62 , 0 ,
F_115 ( V_30 ) , V_190 ) ;
if ( F_116 ( V_30 -> V_37 , V_45 ) ) {
F_117 ( V_62 , F_113 ( V_30 ) ) ;
V_185 -> V_62 = NULL ;
V_30 -> V_175 . V_189 ++ ;
return false ;
}
V_185 -> V_45 = V_45 ;
V_185 -> V_63 = 0 ;
return true ;
}
void F_118 ( struct V_20 * V_30 , T_5 V_191 )
{
union V_31 * V_32 ;
struct V_33 * V_185 ;
T_5 V_11 = V_30 -> V_44 ;
if ( ! V_191 )
return;
V_32 = F_40 ( V_30 , V_11 ) ;
V_185 = & V_30 -> V_34 [ V_11 ] ;
V_11 -= V_30 -> V_52 ;
do {
if ( ! F_111 ( V_30 , V_185 ) )
break;
V_32 -> V_192 . V_193 = F_119 ( V_185 -> V_45 + V_185 -> V_63 ) ;
V_32 ++ ;
V_185 ++ ;
V_11 ++ ;
if ( F_70 ( ! V_11 ) ) {
V_32 = F_40 ( V_30 , 0 ) ;
V_185 = V_30 -> V_34 ;
V_11 -= V_30 -> V_52 ;
}
V_32 -> V_192 . V_194 = 0 ;
V_191 -- ;
} while ( V_191 );
V_11 += V_30 -> V_52 ;
if ( V_30 -> V_44 != V_11 )
F_108 ( V_30 , V_11 ) ;
}
static unsigned int F_120 ( unsigned char * V_56 ,
unsigned int V_195 )
{
union {
unsigned char * V_196 ;
struct V_197 * V_198 ;
struct V_199 * V_200 ;
struct V_201 * V_202 ;
struct V_203 * V_204 ;
} V_205 ;
T_8 V_206 ;
T_4 V_207 = 0 ;
T_4 V_208 ;
if ( V_195 < V_209 )
return V_195 ;
V_205 . V_196 = V_56 ;
V_206 = V_205 . V_198 -> V_210 ;
V_205 . V_196 += V_209 ;
if ( V_206 == F_121 ( V_211 ) ) {
if ( ( V_205 . V_196 - V_56 ) > ( V_195 - V_212 ) )
return V_195 ;
V_206 = V_205 . V_200 -> V_213 ;
V_205 . V_196 += V_212 ;
}
if ( V_206 == F_121 ( V_214 ) ) {
if ( ( V_205 . V_196 - V_56 ) > ( V_195 - sizeof( struct V_201 ) ) )
return V_195 ;
V_208 = ( V_205 . V_196 [ 0 ] & 0x0F ) << 2 ;
if ( V_208 < sizeof( struct V_201 ) )
return V_205 . V_196 - V_56 ;
if ( ! V_205 . V_202 -> V_215 )
V_207 = V_205 . V_202 -> V_206 ;
} else if ( V_206 == F_121 ( V_216 ) ) {
if ( ( V_205 . V_196 - V_56 ) > ( V_195 - sizeof( struct V_203 ) ) )
return V_195 ;
V_207 = V_205 . V_204 -> V_207 ;
V_208 = sizeof( struct V_203 ) ;
#ifdef F_122
} else if ( V_206 == F_121 ( V_217 ) ) {
if ( ( V_205 . V_196 - V_56 ) > ( V_195 - V_218 ) )
return V_195 ;
V_208 = V_218 ;
#endif
} else {
return V_205 . V_196 - V_56 ;
}
V_205 . V_196 += V_208 ;
if ( V_207 == V_219 ) {
if ( ( V_205 . V_196 - V_56 ) > ( V_195 - sizeof( struct V_220 ) ) )
return V_195 ;
V_208 = ( V_205 . V_196 [ 12 ] & 0xF0 ) >> 2 ;
if ( V_208 < sizeof( struct V_220 ) )
return V_205 . V_196 - V_56 ;
V_205 . V_196 += V_208 ;
} else if ( V_207 == V_221 ) {
if ( ( V_205 . V_196 - V_56 ) > ( V_195 - sizeof( struct V_222 ) ) )
return V_195 ;
V_205 . V_196 += sizeof( struct V_222 ) ;
}
if ( ( V_205 . V_196 - V_56 ) < V_195 )
return V_205 . V_196 - V_56 ;
else
return V_195 ;
}
static void F_123 ( struct V_20 * V_82 ,
struct V_158 * V_53 )
{
T_5 V_223 = F_124 ( V_53 ) ;
F_125 ( V_53 ) -> V_224 = F_126 ( ( V_53 -> V_46 - V_223 ) ,
F_127 ( V_53 ) -> V_225 ) ;
F_125 ( V_53 ) -> V_226 = V_227 ;
}
static void F_128 ( struct V_20 * V_30 ,
struct V_158 * V_53 )
{
if ( ! F_127 ( V_53 ) -> V_225 )
return;
V_30 -> V_175 . V_228 += F_127 ( V_53 ) -> V_225 ;
V_30 -> V_175 . V_229 ++ ;
F_123 ( V_30 , V_53 ) ;
F_127 ( V_53 ) -> V_225 = 0 ;
}
static void F_129 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_158 * V_53 )
{
struct V_17 * V_37 = V_30 -> V_18 ;
F_128 ( V_30 , V_53 ) ;
F_102 ( V_30 , V_32 , V_53 ) ;
F_105 ( V_30 , V_32 , V_53 ) ;
F_130 ( V_30 -> V_118 , V_32 , V_53 ) ;
if ( ( V_37 -> V_159 & V_230 ) &&
F_107 ( V_32 , V_231 ) ) {
T_5 V_232 = F_131 ( V_32 -> V_58 . V_59 . V_200 ) ;
F_132 ( V_53 , V_232 ) ;
}
F_133 ( V_53 , V_30 -> V_50 ) ;
V_53 -> V_206 = F_134 ( V_53 , V_37 ) ;
}
static void F_135 ( struct V_117 * V_118 ,
struct V_158 * V_53 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
if ( ! ( V_2 -> V_101 & V_233 ) )
F_136 ( & V_118 -> V_234 , V_53 ) ;
else
F_137 ( V_53 ) ;
}
static bool F_138 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_158 * V_53 )
{
T_1 V_235 = V_30 -> V_43 + 1 ;
V_235 = ( V_235 < V_30 -> V_52 ) ? V_235 : 0 ;
V_30 -> V_43 = V_235 ;
F_72 ( F_40 ( V_30 , V_235 ) ) ;
if ( F_139 ( V_30 ) ) {
T_9 V_236 = V_32 -> V_58 . V_162 . V_166 . V_56 &
F_69 ( V_237 ) ;
if ( F_70 ( V_236 ) ) {
T_1 V_238 = F_41 ( V_236 ) ;
V_238 >>= V_239 ;
F_127 ( V_53 ) -> V_225 += V_238 - 1 ;
V_235 = F_41 ( V_32 -> V_58 . V_59 . V_60 ) ;
V_235 &= V_240 ;
V_235 >>= V_241 ;
}
}
if ( F_73 ( F_107 ( V_32 , V_242 ) ) )
return false ;
V_30 -> V_34 [ V_235 ] . V_53 = V_53 ;
V_30 -> V_175 . V_243 ++ ;
return true ;
}
static void F_140 ( struct V_20 * V_30 ,
struct V_158 * V_53 )
{
struct V_244 * V_245 = & F_125 ( V_53 ) -> V_246 [ 0 ] ;
unsigned char * V_247 ;
unsigned int V_248 ;
V_247 = F_141 ( V_245 ) ;
V_248 = F_120 ( V_247 , V_249 ) ;
F_142 ( V_53 , V_247 , F_143 ( V_248 , sizeof( long ) ) ) ;
F_144 ( V_245 , V_248 ) ;
V_245 -> V_63 += V_248 ;
V_53 -> V_250 -= V_248 ;
V_53 -> V_109 += V_248 ;
}
static void F_145 ( struct V_20 * V_30 ,
struct V_158 * V_53 )
{
if ( F_70 ( F_127 ( V_53 ) -> V_251 ) ) {
F_54 ( V_30 -> V_37 , F_127 ( V_53 ) -> V_45 ,
F_115 ( V_30 ) , V_190 ) ;
F_127 ( V_53 ) -> V_251 = false ;
} else {
struct V_244 * V_245 = & F_125 ( V_53 ) -> V_246 [ 0 ] ;
F_146 ( V_30 -> V_37 ,
F_127 ( V_53 ) -> V_45 ,
V_245 -> V_63 ,
F_43 ( V_30 ) ,
V_190 ) ;
}
F_127 ( V_53 ) -> V_45 = 0 ;
}
static bool F_147 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_158 * V_53 )
{
struct V_17 * V_18 = V_30 -> V_18 ;
if ( F_70 ( F_107 ( V_32 ,
V_252 ) &&
! ( V_18 -> V_159 & V_253 ) ) ) {
F_52 ( V_53 ) ;
return true ;
}
if ( F_148 ( V_53 ) )
F_140 ( V_30 , V_53 ) ;
#ifdef F_122
if ( F_103 ( V_30 , V_32 ) )
return false ;
#endif
if ( F_70 ( V_53 -> V_46 < 60 ) ) {
int V_254 = 60 - V_53 -> V_46 ;
if ( F_149 ( V_53 , V_254 ) )
return true ;
F_150 ( V_53 , V_254 ) ;
}
return false ;
}
static void F_151 ( struct V_20 * V_30 ,
struct V_33 * V_255 )
{
struct V_33 * V_256 ;
T_5 V_257 = V_30 -> V_184 ;
V_256 = & V_30 -> V_34 [ V_257 ] ;
V_257 ++ ;
V_30 -> V_184 = ( V_257 < V_30 -> V_52 ) ? V_257 : 0 ;
V_256 -> V_62 = V_255 -> V_62 ;
V_256 -> V_45 = V_255 -> V_45 ;
V_256 -> V_63 = V_255 -> V_63 ;
F_152 ( V_30 -> V_37 , V_256 -> V_45 ,
V_256 -> V_63 ,
F_43 ( V_30 ) ,
V_190 ) ;
}
static bool F_153 ( struct V_20 * V_30 ,
struct V_33 * V_258 ,
union V_31 * V_32 ,
struct V_158 * V_53 )
{
struct V_62 * V_62 = V_258 -> V_62 ;
unsigned int V_259 = F_131 ( V_32 -> V_58 . V_59 . V_260 ) ;
#if ( V_261 < 8192 )
unsigned int V_262 = F_43 ( V_30 ) ;
#else
unsigned int V_262 = F_143 ( V_259 , V_263 ) ;
unsigned int V_264 = F_115 ( V_30 ) -
F_43 ( V_30 ) ;
#endif
if ( ( V_259 <= V_249 ) && ! F_148 ( V_53 ) ) {
unsigned char * V_247 = F_42 ( V_62 ) + V_258 -> V_63 ;
memcpy ( F_150 ( V_53 , V_259 ) , V_247 , F_143 ( V_259 , sizeof( long ) ) ) ;
if ( F_73 ( F_154 ( V_62 ) == F_155 () ) )
return true ;
F_156 ( V_62 ) ;
return false ;
}
F_157 ( V_53 , F_125 ( V_53 ) -> V_265 , V_62 ,
V_258 -> V_63 , V_259 , V_262 ) ;
if ( F_70 ( F_154 ( V_62 ) != F_155 () ) )
return false ;
#if ( V_261 < 8192 )
if ( F_70 ( F_158 ( V_62 ) != 1 ) )
return false ;
V_258 -> V_63 ^= V_262 ;
F_159 ( & V_62 -> V_266 , 2 ) ;
#else
V_258 -> V_63 += V_262 ;
if ( V_258 -> V_63 > V_264 )
return false ;
F_160 ( V_62 ) ;
#endif
return true ;
}
static struct V_158 * F_161 ( struct V_20 * V_30 ,
union V_31 * V_32 )
{
struct V_33 * V_258 ;
struct V_158 * V_53 ;
struct V_62 * V_62 ;
V_258 = & V_30 -> V_34 [ V_30 -> V_43 ] ;
V_62 = V_258 -> V_62 ;
F_162 ( V_62 ) ;
V_53 = V_258 -> V_53 ;
if ( F_73 ( ! V_53 ) ) {
void * V_267 = F_42 ( V_62 ) +
V_258 -> V_63 ;
F_72 ( V_267 ) ;
#if V_263 < 128
F_72 ( V_267 + V_263 ) ;
#endif
V_53 = F_163 ( V_30 -> V_18 ,
V_249 ) ;
if ( F_70 ( ! V_53 ) ) {
V_30 -> V_175 . V_268 ++ ;
return NULL ;
}
F_162 ( V_53 -> V_56 ) ;
if ( F_73 ( F_107 ( V_32 , V_242 ) ) )
goto V_269;
F_127 ( V_53 ) -> V_45 = V_258 -> V_45 ;
} else {
if ( F_107 ( V_32 , V_242 ) )
F_145 ( V_30 , V_53 ) ;
V_269:
F_146 ( V_30 -> V_37 ,
V_258 -> V_45 ,
V_258 -> V_63 ,
F_43 ( V_30 ) ,
V_190 ) ;
}
if ( F_153 ( V_30 , V_258 , V_32 , V_53 ) ) {
F_151 ( V_30 , V_258 ) ;
} else if ( F_127 ( V_53 ) -> V_45 == V_258 -> V_45 ) {
F_127 ( V_53 ) -> V_251 = true ;
} else {
F_54 ( V_30 -> V_37 , V_258 -> V_45 ,
F_115 ( V_30 ) ,
V_190 ) ;
}
V_258 -> V_53 = NULL ;
V_258 -> V_45 = 0 ;
V_258 -> V_62 = NULL ;
return V_53 ;
}
static bool F_164 ( struct V_117 * V_118 ,
struct V_20 * V_30 ,
const int V_121 )
{
unsigned int V_270 = 0 , V_271 = 0 ;
#ifdef F_122
struct V_1 * V_2 = V_118 -> V_2 ;
int V_272 ;
unsigned int V_273 = 0 ;
#endif
T_5 V_191 = F_84 ( V_30 ) ;
do {
union V_31 * V_32 ;
struct V_158 * V_53 ;
if ( V_191 >= V_274 ) {
F_118 ( V_30 , V_191 ) ;
V_191 = 0 ;
}
V_32 = F_40 ( V_30 , V_30 -> V_43 ) ;
if ( ! F_107 ( V_32 , V_61 ) )
break;
F_68 () ;
V_53 = F_161 ( V_30 , V_32 ) ;
if ( ! V_53 )
break;
V_191 ++ ;
if ( F_138 ( V_30 , V_32 , V_53 ) )
continue;
if ( F_147 ( V_30 , V_32 , V_53 ) )
continue;
V_270 += V_53 -> V_46 ;
F_129 ( V_30 , V_32 , V_53 ) ;
#ifdef F_122
if ( F_103 ( V_30 , V_32 ) ) {
V_272 = F_165 ( V_2 , V_32 , V_53 ) ;
if ( V_272 > 0 ) {
if ( ! V_273 ) {
V_273 = V_30 -> V_18 -> V_275 -
sizeof( struct V_276 ) -
sizeof( struct V_277 ) -
sizeof( struct V_278 ) ;
if ( V_273 > 512 )
V_273 &= ~ 511 ;
}
V_270 += V_272 ;
V_271 += F_126 ( V_272 ,
V_273 ) ;
}
if ( ! V_272 ) {
F_52 ( V_53 ) ;
continue;
}
}
#endif
F_135 ( V_118 , V_53 ) ;
V_271 ++ ;
} while ( F_73 ( V_271 < V_121 ) );
F_74 ( & V_30 -> V_131 ) ;
V_30 -> V_86 . V_106 += V_271 ;
V_30 -> V_86 . V_132 += V_270 ;
F_75 ( & V_30 -> V_131 ) ;
V_118 -> V_279 . V_120 += V_271 ;
V_118 -> V_279 . V_119 += V_270 ;
if ( V_191 )
F_118 ( V_30 , V_191 ) ;
return ( V_271 < V_121 ) ;
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_117 * V_118 ;
int V_280 ;
T_1 V_79 ;
if ( V_2 -> V_281 > 32 ) {
T_1 V_282 = ( 1 << ( V_2 -> V_281 - 32 ) ) - 1 ;
F_45 ( & V_2 -> V_8 , V_283 , V_282 ) ;
}
for ( V_280 = 0 ; V_280 < V_2 -> V_152 ; V_280 ++ ) {
struct V_20 * V_82 ;
V_118 = V_2 -> V_118 [ V_280 ] ;
F_95 (ring, q_vector->rx)
F_47 ( V_2 , 0 , V_82 -> V_108 , V_280 ) ;
F_95 (ring, q_vector->tx)
F_47 ( V_2 , 1 , V_82 -> V_108 , V_280 ) ;
F_167 ( V_118 ) ;
}
switch ( V_2 -> V_8 . V_72 . type ) {
case V_73 :
F_47 ( V_2 , - 1 , V_284 ,
V_280 ) ;
break;
case V_75 :
case V_76 :
F_47 ( V_2 , - 1 , 1 , V_280 ) ;
break;
default:
break;
}
F_45 ( & V_2 -> V_8 , F_168 ( V_280 ) , 1950 ) ;
V_79 = V_285 ;
V_79 &= ~ ( V_286 |
V_287 |
V_288 ) ;
F_45 ( & V_2 -> V_8 , V_289 , V_79 ) ;
}
static void F_169 ( struct V_117 * V_118 ,
struct V_290 * V_291 )
{
int V_132 = V_291 -> V_119 ;
int V_106 = V_291 -> V_120 ;
T_1 V_292 ;
T_2 V_293 ;
T_4 V_294 = V_291 -> V_295 ;
if ( V_106 == 0 )
return;
V_292 = V_118 -> V_295 >> 2 ;
V_293 = V_132 / V_292 ;
switch ( V_294 ) {
case V_296 :
if ( V_293 > 10 )
V_294 = V_297 ;
break;
case V_297 :
if ( V_293 > 20 )
V_294 = V_298 ;
else if ( V_293 <= 10 )
V_294 = V_296 ;
break;
case V_298 :
if ( V_293 <= 20 )
V_294 = V_297 ;
break;
}
V_291 -> V_119 = 0 ;
V_291 -> V_120 = 0 ;
V_291 -> V_295 = V_294 ;
}
void F_167 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_280 = V_118 -> V_280 ;
T_1 V_299 = V_118 -> V_295 & V_300 ;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_73 :
V_299 |= ( V_299 << 16 ) ;
break;
case V_75 :
case V_76 :
V_299 |= V_301 ;
break;
default:
break;
}
F_45 ( V_8 , F_168 ( V_280 ) , V_299 ) ;
}
static void F_170 ( struct V_117 * V_118 )
{
T_1 V_302 = V_118 -> V_295 ;
T_4 V_303 ;
F_169 ( V_118 , & V_118 -> V_122 ) ;
F_169 ( V_118 , & V_118 -> V_279 ) ;
V_303 = F_171 ( V_118 -> V_279 . V_295 , V_118 -> V_122 . V_295 ) ;
switch ( V_303 ) {
case V_296 :
V_302 = V_304 ;
break;
case V_297 :
V_302 = V_305 ;
break;
case V_298 :
V_302 = V_306 ;
break;
default:
break;
}
if ( V_302 != V_118 -> V_295 ) {
V_302 = ( 10 * V_302 * V_118 -> V_295 ) /
( ( 9 * V_302 ) + V_118 -> V_295 ) ;
V_118 -> V_295 = V_302 ;
F_167 ( V_118 ) ;
}
}
static void F_172 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_307 = V_2 -> V_308 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
if ( ! ( V_2 -> V_115 & V_309 ) &&
! ( V_2 -> V_115 & V_310 ) )
return;
V_2 -> V_115 &= ~ V_310 ;
switch ( V_8 -> V_311 ) {
case V_312 :
if ( ! ( V_307 & V_313 ) &&
! ( V_307 & V_314 ) )
return;
if ( ! ( V_307 & V_314 ) && V_8 -> V_72 . V_315 . V_316 ) {
T_1 V_317 ;
bool V_318 = false ;
V_8 -> V_72 . V_315 . V_316 ( V_8 , & V_317 , & V_318 , false ) ;
if ( V_318 )
return;
}
if ( V_8 -> V_319 . V_315 . V_320 ( V_8 ) != V_321 )
return;
break;
default:
if ( ! ( V_307 & V_313 ) )
return;
break;
}
F_173 ( V_133 ,
L_56
L_57
L_58 ) ;
V_2 -> V_308 = 0 ;
}
static void F_174 ( struct V_1 * V_2 , T_1 V_307 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( ( V_2 -> V_101 & V_322 ) &&
( V_307 & V_323 ) ) {
F_173 ( V_135 , L_59 ) ;
F_45 ( V_8 , V_324 , V_323 ) ;
}
}
static void F_175 ( struct V_1 * V_2 , T_1 V_307 )
{
if ( ! ( V_2 -> V_115 & V_309 ) )
return;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
if ( ( ( V_307 & V_313 ) || ( V_307 & V_314 ) ) &&
( ! F_2 ( V_3 , & V_2 -> V_4 ) ) ) {
V_2 -> V_308 = V_307 ;
V_2 -> V_115 |= V_310 ;
F_1 ( V_2 ) ;
return;
}
return;
case V_76 :
if ( ! ( V_307 & V_325 ) )
return;
break;
default:
return;
}
F_173 ( V_133 ,
L_56
L_57
L_58 ) ;
}
static void F_176 ( struct V_1 * V_2 , T_1 V_307 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( V_307 & V_326 ) {
F_45 ( V_8 , V_324 , V_326 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_115 |= V_327 ;
F_1 ( V_2 ) ;
}
}
if ( V_307 & V_323 ) {
F_45 ( V_8 , V_324 , V_323 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_101 |= V_328 ;
F_1 ( V_2 ) ;
}
}
}
static void F_177 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
V_2 -> V_329 ++ ;
V_2 -> V_101 |= V_330 ;
V_2 -> V_331 = V_134 ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_45 ( V_8 , V_332 , V_333 ) ;
F_178 ( V_8 ) ;
F_1 ( V_2 ) ;
}
}
static inline void F_179 ( struct V_1 * V_2 ,
T_2 V_78 )
{
T_1 V_79 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_79 = ( V_80 & V_78 ) ;
F_45 ( V_8 , V_334 , V_79 ) ;
break;
case V_75 :
case V_76 :
V_79 = ( V_78 & 0xFFFFFFFF ) ;
if ( V_79 )
F_45 ( V_8 , F_180 ( 0 ) , V_79 ) ;
V_79 = ( V_78 >> 32 ) ;
if ( V_79 )
F_45 ( V_8 , F_180 ( 1 ) , V_79 ) ;
break;
default:
break;
}
}
static inline void F_181 ( struct V_1 * V_2 ,
T_2 V_78 )
{
T_1 V_79 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_79 = ( V_80 & V_78 ) ;
F_45 ( V_8 , V_332 , V_79 ) ;
break;
case V_75 :
case V_76 :
V_79 = ( V_78 & 0xFFFFFFFF ) ;
if ( V_79 )
F_45 ( V_8 , F_182 ( 0 ) , V_79 ) ;
V_79 = ( V_78 >> 32 ) ;
if ( V_79 )
F_45 ( V_8 , F_182 ( 1 ) , V_79 ) ;
break;
default:
break;
}
}
static inline void F_183 ( struct V_1 * V_2 , bool V_335 ,
bool V_336 )
{
T_1 V_79 = ( V_285 & ~ V_80 ) ;
if ( V_2 -> V_101 & V_330 )
V_79 &= ~ V_288 ;
if ( V_2 -> V_115 & V_309 )
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
V_79 |= V_337 ;
break;
case V_76 :
V_79 |= V_338 ;
break;
default:
break;
}
if ( V_2 -> V_101 & V_322 )
V_79 |= V_339 ;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
V_79 |= V_339 ;
V_79 |= V_340 ;
case V_76 :
V_79 |= V_341 ;
V_79 |= V_287 ;
break;
default:
break;
}
if ( V_2 -> V_8 . V_72 . type == V_76 )
V_79 |= V_342 ;
if ( ( V_2 -> V_101 & V_343 ) &&
! ( V_2 -> V_115 & V_344 ) )
V_79 |= V_345 ;
F_45 ( & V_2 -> V_8 , V_334 , V_79 ) ;
if ( V_335 )
F_179 ( V_2 , ~ 0 ) ;
if ( V_336 )
F_178 ( & V_2 -> V_8 ) ;
}
static T_10 F_184 ( int V_346 , void * V_56 )
{
struct V_1 * V_2 = V_56 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_307 ;
V_307 = F_11 ( V_8 , V_81 ) ;
F_45 ( V_8 , V_324 , V_307 ) ;
if ( V_307 & V_314 )
F_177 ( V_2 ) ;
if ( V_307 & V_347 )
F_185 ( V_2 ) ;
switch ( V_8 -> V_72 . type ) {
case V_75 :
case V_76 :
if ( V_307 & V_348 )
F_79 ( V_349 , L_60
L_61 ) ;
if ( V_307 & V_350 ) {
int V_351 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_82 = V_2 -> V_21 [ V_11 ] ;
if ( F_186 ( V_352 ,
& V_82 -> V_4 ) )
V_351 ++ ;
}
if ( V_351 ) {
F_45 ( V_8 , V_332 , V_353 ) ;
V_2 -> V_115 |= V_344 ;
F_1 ( V_2 ) ;
}
}
F_176 ( V_2 , V_307 ) ;
F_175 ( V_2 , V_307 ) ;
break;
default:
break;
}
F_174 ( V_2 , V_307 ) ;
if ( F_70 ( V_307 & V_354 ) )
F_187 ( V_2 , V_307 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_183 ( V_2 , false , false ) ;
return V_355 ;
}
static T_10 F_188 ( int V_346 , void * V_56 )
{
struct V_117 * V_118 = V_56 ;
if ( V_118 -> V_279 . V_82 || V_118 -> V_122 . V_82 )
F_189 ( & V_118 -> V_234 ) ;
return V_355 ;
}
int F_190 ( struct V_356 * V_234 , int V_121 )
{
struct V_117 * V_118 =
F_191 ( V_234 , struct V_117 , V_234 ) ;
struct V_1 * V_2 = V_118 -> V_2 ;
struct V_20 * V_82 ;
int V_357 ;
bool V_358 = true ;
#ifdef F_192
if ( V_2 -> V_101 & V_150 )
F_93 ( V_118 ) ;
#endif
F_95 (ring, q_vector->tx)
V_358 &= ! ! F_67 ( V_118 , V_82 ) ;
if ( V_118 -> V_279 . V_52 > 1 )
V_357 = F_171 ( V_121 / V_118 -> V_279 . V_52 , 1 ) ;
else
V_357 = V_121 ;
F_95 (ring, q_vector->rx)
V_358 &= F_164 ( V_118 , V_82 ,
V_357 ) ;
if ( ! V_358 )
return V_121 ;
F_193 ( V_234 ) ;
if ( V_2 -> V_359 & 1 )
F_170 ( V_118 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_179 ( V_2 , ( ( T_2 ) 1 << V_118 -> V_280 ) ) ;
return 0 ;
}
static int F_194 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
int V_360 , V_361 ;
int V_362 = 0 , V_363 = 0 ;
for ( V_360 = 0 ; V_360 < V_2 -> V_152 ; V_360 ++ ) {
struct V_117 * V_118 = V_2 -> V_118 [ V_360 ] ;
struct V_364 * V_365 = & V_2 -> V_366 [ V_360 ] ;
if ( V_118 -> V_122 . V_82 && V_118 -> V_279 . V_82 ) {
snprintf ( V_118 -> V_16 , sizeof( V_118 -> V_16 ) - 1 ,
L_62 , V_18 -> V_16 , L_63 , V_362 ++ ) ;
V_363 ++ ;
} else if ( V_118 -> V_279 . V_82 ) {
snprintf ( V_118 -> V_16 , sizeof( V_118 -> V_16 ) - 1 ,
L_62 , V_18 -> V_16 , L_64 , V_362 ++ ) ;
} else if ( V_118 -> V_122 . V_82 ) {
snprintf ( V_118 -> V_16 , sizeof( V_118 -> V_16 ) - 1 ,
L_62 , V_18 -> V_16 , L_65 , V_363 ++ ) ;
} else {
continue;
}
V_361 = F_195 ( V_365 -> V_360 , & F_188 , 0 ,
V_118 -> V_16 , V_118 ) ;
if ( V_361 ) {
F_77 ( V_135 , L_66
L_67 , V_361 ) ;
goto V_367;
}
if ( V_2 -> V_101 & V_343 ) {
F_196 ( V_365 -> V_360 ,
& V_118 -> V_368 ) ;
}
}
V_361 = F_195 ( V_2 -> V_366 [ V_360 ] . V_360 ,
F_184 , 0 , V_18 -> V_16 , V_2 ) ;
if ( V_361 ) {
F_77 ( V_135 , L_68 , V_361 ) ;
goto V_367;
}
return 0 ;
V_367:
while ( V_360 ) {
V_360 -- ;
F_196 ( V_2 -> V_366 [ V_360 ] . V_360 ,
NULL ) ;
F_197 ( V_2 -> V_366 [ V_360 ] . V_360 ,
V_2 -> V_118 [ V_360 ] ) ;
}
V_2 -> V_101 &= ~ V_369 ;
F_198 ( V_2 -> V_36 ) ;
F_199 ( V_2 -> V_366 ) ;
V_2 -> V_366 = NULL ;
return V_361 ;
}
static T_10 F_200 ( int V_346 , void * V_56 )
{
struct V_1 * V_2 = V_56 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_117 * V_118 = V_2 -> V_118 [ 0 ] ;
T_1 V_307 ;
F_45 ( V_8 , V_332 , V_370 ) ;
V_307 = F_11 ( V_8 , V_324 ) ;
if ( ! V_307 ) {
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_183 ( V_2 , true , true ) ;
return V_371 ;
}
if ( V_307 & V_314 )
F_177 ( V_2 ) ;
switch ( V_8 -> V_72 . type ) {
case V_75 :
F_176 ( V_2 , V_307 ) ;
case V_76 :
if ( V_307 & V_348 )
F_79 ( V_349 , L_69
L_61 ) ;
F_175 ( V_2 , V_307 ) ;
break;
default:
break;
}
F_174 ( V_2 , V_307 ) ;
if ( F_70 ( V_307 & V_354 ) )
F_187 ( V_2 , V_307 ) ;
F_189 ( & V_118 -> V_234 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_183 ( V_2 , false , false ) ;
return V_355 ;
}
static int F_201 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
int V_361 ;
if ( V_2 -> V_101 & V_369 )
V_361 = F_194 ( V_2 ) ;
else if ( V_2 -> V_101 & V_372 )
V_361 = F_195 ( V_2 -> V_36 -> V_346 , F_200 , 0 ,
V_18 -> V_16 , V_2 ) ;
else
V_361 = F_195 ( V_2 -> V_36 -> V_346 , F_200 , V_373 ,
V_18 -> V_16 , V_2 ) ;
if ( V_361 )
F_77 ( V_135 , L_70 , V_361 ) ;
return V_361 ;
}
static void F_202 ( struct V_1 * V_2 )
{
int V_360 ;
if ( ! ( V_2 -> V_101 & V_369 ) ) {
F_197 ( V_2 -> V_36 -> V_346 , V_2 ) ;
return;
}
for ( V_360 = 0 ; V_360 < V_2 -> V_152 ; V_360 ++ ) {
struct V_117 * V_118 = V_2 -> V_118 [ V_360 ] ;
struct V_364 * V_365 = & V_2 -> V_366 [ V_360 ] ;
if ( ! V_118 -> V_279 . V_82 && ! V_118 -> V_122 . V_82 )
continue;
F_196 ( V_365 -> V_360 , NULL ) ;
F_197 ( V_365 -> V_360 , V_118 ) ;
}
F_197 ( V_2 -> V_366 [ V_360 ++ ] . V_360 , V_2 ) ;
}
static inline void F_203 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 . V_72 . type ) {
case V_73 :
F_45 ( & V_2 -> V_8 , V_332 , ~ 0 ) ;
break;
case V_75 :
case V_76 :
F_45 ( & V_2 -> V_8 , V_332 , 0xFFFF0000 ) ;
F_45 ( & V_2 -> V_8 , F_182 ( 0 ) , ~ 0 ) ;
F_45 ( & V_2 -> V_8 , F_182 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_178 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_101 & V_369 ) {
int V_360 ;
for ( V_360 = 0 ; V_360 < V_2 -> V_152 ; V_360 ++ )
F_204 ( V_2 -> V_366 [ V_360 ] . V_360 ) ;
F_204 ( V_2 -> V_366 [ V_360 ++ ] . V_360 ) ;
} else {
F_204 ( V_2 -> V_36 -> V_346 ) ;
}
}
static void F_205 ( struct V_1 * V_2 )
{
struct V_117 * V_118 = V_2 -> V_118 [ 0 ] ;
F_167 ( V_118 ) ;
F_47 ( V_2 , 0 , 0 , 0 ) ;
F_47 ( V_2 , 1 , 0 , 0 ) ;
F_79 ( V_8 , L_71 ) ;
}
void F_206 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_374 = V_82 -> V_45 ;
int V_375 = 10 ;
T_1 V_376 = V_377 ;
T_4 V_108 = V_82 -> V_108 ;
F_45 ( V_8 , F_24 ( V_108 ) , 0 ) ;
F_178 ( V_8 ) ;
F_45 ( V_8 , F_19 ( V_108 ) ,
( V_374 & F_207 ( 32 ) ) ) ;
F_45 ( V_8 , F_20 ( V_108 ) , ( V_374 >> 32 ) ) ;
F_45 ( V_8 , F_21 ( V_108 ) ,
V_82 -> V_52 * sizeof( union V_24 ) ) ;
F_45 ( V_8 , F_22 ( V_108 ) , 0 ) ;
F_45 ( V_8 , F_23 ( V_108 ) , 0 ) ;
V_82 -> V_109 = V_8 -> V_378 + F_23 ( V_108 ) ;
if ( ! V_82 -> V_118 || ( V_82 -> V_118 -> V_295 < 8 ) )
V_376 |= ( 1 << 16 ) ;
else
V_376 |= ( 8 << 16 ) ;
V_376 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_101 & V_343 ) {
V_82 -> V_379 = V_2 -> V_379 ;
V_82 -> V_380 = 0 ;
F_208 ( V_352 , & V_82 -> V_4 ) ;
} else {
V_82 -> V_379 = 0 ;
}
F_8 ( V_94 , & V_82 -> V_4 ) ;
F_45 ( V_8 , F_24 ( V_108 ) , V_376 ) ;
if ( V_8 -> V_72 . type == V_73 &&
! ( F_11 ( V_8 , V_381 ) & V_382 ) )
return;
do {
F_209 ( 1000 , 2000 ) ;
V_376 = F_11 ( V_8 , F_24 ( V_108 ) ) ;
} while ( -- V_375 && ! ( V_376 & V_377 ) );
if ( ! V_375 )
F_77 ( V_133 , L_72 , V_108 ) ;
}
static void F_210 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_383 , V_384 ;
T_4 V_385 = F_211 ( V_2 -> V_18 ) ;
if ( V_8 -> V_72 . type == V_73 )
return;
V_383 = F_11 ( V_8 , V_386 ) ;
V_383 |= V_387 ;
F_45 ( V_8 , V_386 , V_383 ) ;
if ( V_2 -> V_101 & V_388 ) {
V_384 = V_389 ;
if ( V_385 > 4 )
V_384 |= V_390 | V_391 ;
else if ( V_385 > 1 )
V_384 |= V_390 | V_392 ;
else if ( V_2 -> V_393 [ V_394 ] . V_395 == 4 )
V_384 |= V_396 ;
else
V_384 |= V_397 ;
} else {
if ( V_385 > 4 )
V_384 = V_390 | V_391 ;
else if ( V_385 > 1 )
V_384 = V_390 | V_392 ;
else
V_384 = V_398 ;
}
F_45 ( V_8 , V_399 , V_384 ) ;
if ( V_385 ) {
T_1 V_400 = F_11 ( V_8 , V_401 ) ;
V_400 |= V_402 ;
F_45 ( V_8 , V_401 , V_400 ) ;
}
V_383 &= ~ V_387 ;
F_45 ( V_8 , V_386 , V_383 ) ;
}
static void F_212 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_403 ;
T_1 V_11 ;
F_210 ( V_2 ) ;
if ( V_8 -> V_72 . type != V_73 ) {
V_403 = F_11 ( V_8 , V_404 ) ;
V_403 |= V_405 ;
F_45 ( V_8 , V_404 , V_403 ) ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_206 ( V_2 , V_2 -> V_21 [ V_11 ] ) ;
}
static void F_213 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_4 V_108 = V_82 -> V_108 ;
T_1 V_406 = F_11 ( V_8 , F_10 ( V_108 ) ) ;
V_406 |= V_407 ;
F_45 ( V_8 , F_10 ( V_108 ) , V_406 ) ;
}
static void F_214 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_4 V_108 = V_82 -> V_108 ;
T_1 V_406 = F_11 ( V_8 , F_10 ( V_108 ) ) ;
V_406 &= ~ V_407 ;
F_45 ( V_8 , F_10 ( V_108 ) , V_406 ) ;
}
static void F_215 ( struct V_1 * V_2 ,
struct V_20 * V_30 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_406 ;
T_4 V_108 = V_30 -> V_108 ;
if ( V_8 -> V_72 . type == V_73 ) {
T_5 V_79 = V_2 -> V_393 [ V_394 ] . V_79 ;
V_108 &= V_79 ;
}
V_406 = V_249 << V_408 ;
V_406 |= F_43 ( V_30 ) >> V_409 ;
V_406 |= V_410 ;
F_45 ( V_8 , F_10 ( V_108 ) , V_406 ) ;
}
static void F_216 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
static const T_1 V_411 [ 10 ] = { 0xE291D73D , 0x1805EC6C , 0x2A94B30D ,
0xA54F2BEC , 0xEA49AF7C , 0xE214AD3D , 0xB855AABE ,
0x6A3E67EA , 0x14364D17 , 0x3BED200D } ;
T_1 V_412 = 0 , V_413 = 0 ;
T_1 V_414 ;
int V_11 , V_12 ;
T_5 V_415 = V_2 -> V_393 [ V_394 ] . V_395 ;
if ( ( V_2 -> V_101 & V_388 ) && ( V_415 < 2 ) )
V_415 = 2 ;
for ( V_11 = 0 ; V_11 < 10 ; V_11 ++ )
F_45 ( V_8 , F_217 ( V_11 ) , V_411 [ V_11 ] ) ;
for ( V_11 = 0 , V_12 = 0 ; V_11 < 128 ; V_11 ++ , V_12 ++ ) {
if ( V_12 == V_415 )
V_12 = 0 ;
V_413 = ( V_413 << 8 ) | ( V_12 * 0x11 ) ;
if ( ( V_11 & 3 ) == 3 )
F_45 ( V_8 , F_218 ( V_11 >> 2 ) , V_413 ) ;
}
V_414 = F_11 ( V_8 , V_416 ) ;
V_414 |= V_417 ;
F_45 ( V_8 , V_416 , V_414 ) ;
if ( V_2 -> V_8 . V_72 . type == V_73 ) {
if ( V_2 -> V_393 [ V_394 ] . V_79 )
V_412 = V_418 ;
} else {
T_4 V_385 = F_211 ( V_2 -> V_18 ) ;
if ( V_2 -> V_101 & V_388 ) {
if ( V_385 > 4 )
V_412 = V_419 ;
else if ( V_385 > 1 )
V_412 = V_420 ;
else if ( V_2 -> V_393 [ V_394 ] . V_395 == 4 )
V_412 = V_421 ;
else
V_412 = V_422 ;
} else {
if ( V_385 > 4 )
V_412 = V_423 ;
else if ( V_385 > 1 )
V_412 = V_424 ;
else
V_412 = V_418 ;
}
}
V_412 |= V_425 |
V_426 |
V_427 |
V_428 ;
if ( V_2 -> V_115 & V_429 )
V_412 |= V_430 ;
if ( V_2 -> V_115 & V_431 )
V_412 |= V_432 ;
F_45 ( V_8 , V_433 , V_412 ) ;
}
static void F_219 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_434 ;
T_4 V_108 = V_82 -> V_108 ;
if ( ! F_139 ( V_82 ) )
return;
V_434 = F_11 ( V_8 , F_220 ( V_108 ) ) ;
V_434 |= V_435 ;
V_434 |= V_436 ;
F_45 ( V_8 , F_220 ( V_108 ) , V_434 ) ;
}
static void F_221 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_375 = V_437 ;
T_1 V_438 ;
T_4 V_108 = V_82 -> V_108 ;
if ( V_8 -> V_72 . type == V_73 &&
! ( F_11 ( V_8 , V_381 ) & V_382 ) )
return;
do {
F_209 ( 1000 , 2000 ) ;
V_438 = F_11 ( V_8 , F_16 ( V_108 ) ) ;
} while ( -- V_375 && ! ( V_438 & V_439 ) );
if ( ! V_375 ) {
F_77 ( V_133 , L_73
L_74 , V_108 ) ;
}
}
void F_222 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_375 = V_437 ;
T_1 V_438 ;
T_4 V_108 = V_82 -> V_108 ;
V_438 = F_11 ( V_8 , F_16 ( V_108 ) ) ;
V_438 &= ~ V_439 ;
F_45 ( V_8 , F_16 ( V_108 ) , V_438 ) ;
if ( V_8 -> V_72 . type == V_73 &&
! ( F_11 ( V_8 , V_381 ) & V_382 ) )
return;
do {
F_223 ( 10 ) ;
V_438 = F_11 ( V_8 , F_16 ( V_108 ) ) ;
} while ( -- V_375 && ( V_438 & V_439 ) );
if ( ! V_375 ) {
F_77 ( V_133 , L_75
L_74 , V_108 ) ;
}
}
void F_224 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_440 = V_82 -> V_45 ;
T_1 V_438 ;
T_4 V_108 = V_82 -> V_108 ;
V_438 = F_11 ( V_8 , F_16 ( V_108 ) ) ;
F_222 ( V_2 , V_82 ) ;
F_45 ( V_8 , F_17 ( V_108 ) , ( V_440 & F_207 ( 32 ) ) ) ;
F_45 ( V_8 , F_18 ( V_108 ) , ( V_440 >> 32 ) ) ;
F_45 ( V_8 , F_13 ( V_108 ) ,
V_82 -> V_52 * sizeof( union V_31 ) ) ;
F_45 ( V_8 , F_14 ( V_108 ) , 0 ) ;
F_45 ( V_8 , F_15 ( V_108 ) , 0 ) ;
V_82 -> V_109 = V_8 -> V_378 + F_15 ( V_108 ) ;
F_215 ( V_2 , V_82 ) ;
F_219 ( V_2 , V_82 ) ;
if ( V_8 -> V_72 . type == V_73 ) {
V_438 &= ~ 0x3FFFFF ;
V_438 |= 0x080420 ;
}
V_438 |= V_439 ;
F_45 ( V_8 , F_16 ( V_108 ) , V_438 ) ;
F_221 ( V_2 , V_82 ) ;
F_118 ( V_82 , F_84 ( V_82 ) ) ;
}
static void F_225 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_415 = V_2 -> V_393 [ V_394 ] . V_395 ;
int V_441 ;
T_1 V_442 = V_443 |
V_444 |
V_445 |
V_446 |
V_447 ;
if ( V_8 -> V_72 . type == V_73 )
return;
if ( V_415 > 3 )
V_442 |= 2 << 29 ;
else if ( V_415 > 1 )
V_442 |= 1 << 29 ;
for ( V_441 = 0 ; V_441 < V_2 -> V_448 ; V_441 ++ )
F_45 ( V_8 , F_226 ( F_227 ( V_441 ) ) ,
V_442 ) ;
}
static void F_228 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_140 , V_449 ;
T_1 V_450 , V_451 ;
int V_11 ;
if ( ! ( V_2 -> V_101 & V_388 ) )
return;
V_451 = F_11 ( V_8 , V_452 ) ;
V_451 |= V_453 ;
V_451 &= ~ V_454 ;
V_451 |= F_227 ( 0 ) << V_455 ;
V_451 |= V_456 ;
F_45 ( V_8 , V_452 , V_451 ) ;
V_449 = F_227 ( 0 ) % 32 ;
V_140 = ( F_227 ( 0 ) >= 32 ) ? 1 : 0 ;
F_45 ( V_8 , F_229 ( V_140 ) , ( ~ 0 ) << V_449 ) ;
F_45 ( V_8 , F_229 ( V_140 ^ 1 ) , V_140 - 1 ) ;
F_45 ( V_8 , F_230 ( V_140 ) , ( ~ 0 ) << V_449 ) ;
F_45 ( V_8 , F_230 ( V_140 ^ 1 ) , V_140 - 1 ) ;
if ( V_2 -> V_115 & V_457 )
F_45 ( V_8 , V_458 , V_459 ) ;
V_8 -> V_72 . V_315 . V_460 ( V_8 , 0 , F_227 ( 0 ) ) ;
switch ( V_2 -> V_393 [ V_461 ] . V_79 ) {
case V_462 :
V_450 = V_463 ;
break;
case V_464 :
V_450 = V_465 ;
break;
default:
V_450 = V_466 ;
break;
}
F_45 ( V_8 , V_467 , V_450 ) ;
V_8 -> V_72 . V_315 . V_468 ( V_8 , ( V_2 -> V_281 != 0 ) ,
V_2 -> V_281 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_281 ; V_11 ++ ) {
if ( ! V_2 -> V_469 [ V_11 ] . V_470 )
F_231 ( V_2 -> V_18 , V_11 , false ) ;
}
}
static void F_232 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_18 = V_2 -> V_18 ;
int V_471 = V_18 -> V_275 + V_209 + V_472 ;
struct V_20 * V_30 ;
int V_11 ;
T_1 V_473 , V_474 ;
#ifdef F_122
if ( ( V_2 -> V_101 & V_475 ) &&
( V_471 < V_476 ) )
V_471 = V_476 ;
#endif
if ( V_471 < ( V_477 + V_472 ) )
V_471 = ( V_477 + V_472 ) ;
V_473 = F_11 ( V_8 , V_478 ) ;
if ( V_471 != ( V_473 >> V_479 ) ) {
V_473 &= ~ V_480 ;
V_473 |= V_471 << V_479 ;
F_45 ( V_8 , V_478 , V_473 ) ;
}
V_474 = F_11 ( V_8 , V_481 ) ;
V_474 |= V_482 ;
F_45 ( V_8 , V_481 , V_474 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
V_30 = V_2 -> V_30 [ V_11 ] ;
if ( V_2 -> V_115 & V_483 )
F_233 ( V_30 ) ;
else
F_234 ( V_30 ) ;
}
}
static void F_235 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_484 = F_11 ( V_8 , V_485 ) ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_484 |= V_486 ;
break;
case V_75 :
case V_76 :
F_45 ( V_8 , V_487 ,
( V_488 | F_11 ( V_8 , V_487 ) ) ) ;
V_484 &= ~ V_489 ;
V_484 |= ( V_490 | V_491 ) ;
V_484 |= V_492 ;
break;
default:
return;
}
F_45 ( V_8 , V_485 , V_484 ) ;
}
static void F_236 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_11 ;
T_1 V_145 ;
V_145 = F_11 ( V_8 , V_493 ) ;
F_45 ( V_8 , V_493 , V_145 & ~ V_494 ) ;
F_225 ( V_2 ) ;
F_235 ( V_2 ) ;
F_216 ( V_2 ) ;
F_232 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ )
F_224 ( V_2 , V_2 -> V_30 [ V_11 ] ) ;
if ( V_8 -> V_72 . type == V_73 )
V_145 |= V_495 ;
V_145 |= V_494 ;
V_8 -> V_72 . V_315 . V_496 ( V_8 , V_145 ) ;
}
static int F_237 ( struct V_17 * V_18 , T_5 V_232 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
V_8 -> V_72 . V_315 . V_497 ( & V_2 -> V_8 , V_232 , F_227 ( 0 ) , true ) ;
F_208 ( V_232 , V_2 -> V_498 ) ;
return 0 ;
}
static int F_238 ( struct V_17 * V_18 , T_5 V_232 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
V_8 -> V_72 . V_315 . V_497 ( & V_2 -> V_8 , V_232 , F_227 ( 0 ) , false ) ;
F_8 ( V_232 , V_2 -> V_498 ) ;
return 0 ;
}
static void F_239 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_499 ;
V_499 = F_11 ( V_8 , V_500 ) ;
V_499 &= ~ ( V_501 | V_502 ) ;
F_45 ( V_8 , V_500 , V_499 ) ;
}
static void F_240 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_499 ;
V_499 = F_11 ( V_8 , V_500 ) ;
V_499 |= V_501 ;
V_499 &= ~ V_502 ;
F_45 ( V_8 , V_500 , V_499 ) ;
}
static void F_241 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_499 ;
int V_11 , V_12 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_499 = F_11 ( V_8 , V_500 ) ;
V_499 &= ~ V_503 ;
F_45 ( V_8 , V_500 , V_499 ) ;
break;
case V_75 :
case V_76 :
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
V_12 = V_2 -> V_30 [ V_11 ] -> V_108 ;
V_499 = F_11 ( V_8 , F_16 ( V_12 ) ) ;
V_499 &= ~ V_504 ;
F_45 ( V_8 , F_16 ( V_12 ) , V_499 ) ;
}
break;
default:
break;
}
}
static void F_242 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_499 ;
int V_11 , V_12 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_499 = F_11 ( V_8 , V_500 ) ;
V_499 |= V_503 ;
F_45 ( V_8 , V_500 , V_499 ) ;
break;
case V_75 :
case V_76 :
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
V_12 = V_2 -> V_30 [ V_11 ] -> V_108 ;
V_499 = F_11 ( V_8 , F_16 ( V_12 ) ) ;
V_499 |= V_504 ;
F_45 ( V_8 , F_16 ( V_12 ) , V_499 ) ;
}
break;
default:
break;
}
}
static void F_243 ( struct V_1 * V_2 )
{
T_5 V_232 ;
F_237 ( V_2 -> V_18 , 0 ) ;
F_244 (vid, adapter->active_vlans, VLAN_N_VID)
F_237 ( V_2 -> V_18 , V_232 ) ;
}
static int F_245 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
unsigned int V_505 = V_8 -> V_72 . V_506 - 1 ;
int V_52 = 0 ;
if ( V_2 -> V_101 & V_388 )
V_505 = V_507 - 1 ;
if ( F_246 ( V_18 ) > V_505 )
return - V_508 ;
if ( ! F_247 ( V_18 ) ) {
struct V_509 * V_510 ;
if ( ! V_8 -> V_72 . V_315 . V_511 )
return - V_508 ;
F_248 (ha, netdev) {
if ( ! V_505 )
break;
V_8 -> V_72 . V_315 . V_511 ( V_8 , V_505 -- , V_510 -> V_512 ,
F_227 ( 0 ) , V_513 ) ;
V_52 ++ ;
}
}
for (; V_505 > 0 ; V_505 -- )
V_8 -> V_72 . V_315 . V_514 ( V_8 , V_505 ) ;
return V_52 ;
}
void F_249 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_515 , V_516 = V_517 | V_518 ;
int V_52 ;
V_515 = F_11 ( V_8 , V_519 ) ;
V_515 &= ~ V_520 ;
V_515 |= V_521 ;
V_515 |= V_522 ;
V_515 |= V_523 ;
V_515 &= ~ ( V_524 | V_525 ) ;
if ( V_18 -> V_101 & V_526 ) {
V_8 -> V_527 . V_528 = true ;
V_515 |= ( V_524 | V_525 ) ;
V_516 |= ( V_529 | V_530 ) ;
F_239 ( V_2 ) ;
} else {
if ( V_18 -> V_101 & V_531 ) {
V_515 |= V_525 ;
V_516 |= V_530 ;
} else {
V_8 -> V_72 . V_315 . V_532 ( V_8 , V_18 ) ;
V_516 |= V_533 ;
}
F_240 ( V_2 ) ;
V_8 -> V_527 . V_528 = false ;
}
V_52 = F_245 ( V_18 ) ;
if ( V_52 < 0 ) {
V_515 |= V_524 ;
V_516 |= V_529 ;
}
if ( V_2 -> V_281 )
F_250 ( V_2 ) ;
if ( V_8 -> V_72 . type != V_73 ) {
V_516 |= F_11 ( V_8 , F_251 ( F_227 ( 0 ) ) ) &
~ ( V_530 | V_533 |
V_529 ) ;
F_45 ( V_8 , F_251 ( F_227 ( 0 ) ) , V_516 ) ;
}
if ( V_2 -> V_18 -> V_159 & V_253 ) {
V_515 |= ( V_520 |
V_521 |
V_523 ) ;
V_515 &= ~ ( V_522 ) ;
}
F_45 ( V_8 , V_519 , V_515 ) ;
if ( V_18 -> V_159 & V_230 )
F_242 ( V_2 ) ;
else
F_241 ( V_2 ) ;
}
static void F_252 ( struct V_1 * V_2 )
{
int V_534 ;
for ( V_534 = 0 ; V_534 < V_2 -> V_152 ; V_534 ++ )
F_253 ( & V_2 -> V_118 [ V_534 ] -> V_234 ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
int V_534 ;
for ( V_534 = 0 ; V_534 < V_2 -> V_152 ; V_534 ++ )
F_255 ( & V_2 -> V_118 [ V_534 ] -> V_234 ) ;
}
static void F_256 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_471 = V_2 -> V_18 -> V_275 + V_209 + V_472 ;
if ( ! ( V_2 -> V_101 & V_102 ) ) {
if ( V_8 -> V_72 . type == V_73 )
F_257 ( V_2 -> V_18 , 65536 ) ;
return;
}
if ( V_8 -> V_72 . type == V_73 )
F_257 ( V_2 -> V_18 , 32768 ) ;
#ifdef F_122
if ( V_2 -> V_18 -> V_159 & V_535 )
V_471 = F_171 ( V_471 , V_476 ) ;
#endif
if ( V_2 -> V_536 & V_537 ) {
F_258 ( V_8 , & V_2 -> V_98 , V_471 ,
V_538 ) ;
F_258 ( V_8 , & V_2 -> V_98 , V_471 ,
V_539 ) ;
F_259 ( V_8 , & V_2 -> V_98 ) ;
} else if ( V_2 -> V_540 && V_2 -> V_100 ) {
F_260 ( & V_2 -> V_8 ,
V_2 -> V_540 ,
V_471 ) ;
F_261 ( & V_2 -> V_8 ,
V_2 -> V_100 -> V_97 ,
V_2 -> V_540 -> V_541 ) ;
}
if ( V_8 -> V_72 . type != V_73 ) {
T_1 V_542 = 0 ;
T_5 V_415 = V_2 -> V_393 [ V_394 ] . V_395 - 1 ;
while ( V_415 ) {
V_542 ++ ;
V_415 >>= 1 ;
}
F_45 ( V_8 , V_543 , V_542 * 0x11111111 ) ;
}
}
static int F_262 ( struct V_1 * V_2 , int V_544 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_37 = V_2 -> V_18 ;
int V_349 , V_96 , V_545 , V_546 ;
T_1 V_547 , V_548 ;
V_96 = V_349 = V_37 -> V_275 + V_209 + V_472 + V_549 ;
#ifdef F_122
if ( ( V_37 -> V_159 & V_535 ) &&
( V_96 < V_476 ) &&
( V_544 == F_263 ( V_2 ) ) )
V_96 = V_476 ;
#endif
switch ( V_8 -> V_72 . type ) {
case V_76 :
V_547 = F_264 ( V_349 , V_96 ) ;
break;
default:
V_547 = F_265 ( V_349 , V_96 ) ;
break;
}
if ( V_2 -> V_101 & V_388 )
V_547 += F_266 ( V_96 ) ;
V_545 = F_267 ( V_547 ) ;
V_548 = F_11 ( V_8 , F_268 ( V_544 ) ) >> 10 ;
V_546 = V_548 - V_545 ;
if ( V_546 < 0 ) {
F_269 ( V_133 , L_76
L_77
L_78 , V_544 ) ;
V_546 = V_96 + 1 ;
}
return V_546 ;
}
static int F_270 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_37 = V_2 -> V_18 ;
int V_96 ;
T_1 V_547 ;
V_96 = V_37 -> V_275 + V_209 + V_472 ;
switch ( V_8 -> V_72 . type ) {
case V_76 :
V_547 = F_271 ( V_96 ) ;
break;
default:
V_547 = F_272 ( V_96 ) ;
break;
}
return F_267 ( V_547 ) ;
}
static void F_273 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_550 = F_211 ( V_2 -> V_18 ) ;
int V_11 ;
if ( ! V_550 )
V_550 = 1 ;
V_8 -> V_87 . V_551 = F_270 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_550 ; V_11 ++ ) {
V_8 -> V_87 . V_552 [ V_11 ] = F_262 ( V_2 , V_11 ) ;
if ( V_8 -> V_87 . V_551 > V_8 -> V_87 . V_552 [ V_11 ] )
V_8 -> V_87 . V_551 = 0 ;
}
}
static void F_274 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_553 ;
T_4 V_96 = F_211 ( V_2 -> V_18 ) ;
if ( V_2 -> V_101 & V_343 ||
V_2 -> V_101 & V_554 )
V_553 = 32 << V_2 -> V_555 ;
else
V_553 = 0 ;
V_8 -> V_72 . V_315 . V_556 ( V_8 , V_96 , V_553 , V_557 ) ;
F_273 ( V_2 ) ;
}
static void F_275 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_558 * V_559 , * V_560 ;
struct V_561 * V_562 ;
F_276 ( & V_2 -> V_563 ) ;
if ( ! F_277 ( & V_2 -> V_564 ) )
F_278 ( V_8 , & V_2 -> V_565 ) ;
F_279 (filter, node, node2,
&adapter->fdir_filter_list, fdir_node) {
F_280 ( V_8 ,
& V_562 -> V_562 ,
V_562 -> V_566 ,
( V_562 -> V_567 == V_568 ) ?
V_568 :
V_2 -> V_30 [ V_562 -> V_567 ] -> V_108 ) ;
}
F_281 ( & V_2 -> V_563 ) ;
}
static void F_282 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
F_274 ( V_2 ) ;
#ifdef F_283
F_256 ( V_2 ) ;
#endif
F_228 ( V_2 ) ;
F_249 ( V_2 -> V_18 ) ;
F_243 ( V_2 ) ;
switch ( V_8 -> V_72 . type ) {
case V_75 :
case V_76 :
V_8 -> V_72 . V_315 . V_569 ( V_8 ) ;
break;
default:
break;
}
if ( V_2 -> V_101 & V_343 ) {
F_284 ( & V_2 -> V_8 ,
V_2 -> V_555 ) ;
} else if ( V_2 -> V_101 & V_554 ) {
F_285 ( & V_2 -> V_8 ,
V_2 -> V_555 ) ;
F_275 ( V_2 ) ;
}
switch ( V_8 -> V_72 . type ) {
case V_75 :
case V_76 :
V_8 -> V_72 . V_315 . V_570 ( V_8 ) ;
break;
default:
break;
}
#ifdef F_122
F_286 ( V_2 ) ;
#endif
F_212 ( V_2 ) ;
F_236 ( V_2 ) ;
}
static inline bool F_287 ( struct V_7 * V_8 )
{
switch ( V_8 -> V_319 . type ) {
case V_571 :
case V_572 :
case V_573 :
case V_574 :
case V_575 :
case V_576 :
case V_577 :
case V_578 :
return true ;
case V_579 :
if ( V_8 -> V_72 . type == V_73 )
return true ;
default:
return false ;
}
}
static void F_288 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_72 . type == V_73 )
V_2 -> V_115 |= V_580 ;
V_2 -> V_115 |= V_327 ;
}
static int F_289 ( struct V_7 * V_8 )
{
T_1 V_317 ;
bool V_581 , V_318 = false ;
T_1 V_114 = V_582 ;
if ( V_8 -> V_72 . V_315 . V_316 )
V_114 = V_8 -> V_72 . V_315 . V_316 ( V_8 , & V_317 , & V_318 , false ) ;
if ( V_114 )
goto V_583;
V_317 = V_8 -> V_319 . V_584 ;
if ( ( ! V_317 ) && ( V_8 -> V_72 . V_315 . V_585 ) )
V_114 = V_8 -> V_72 . V_315 . V_585 ( V_8 , & V_317 ,
& V_581 ) ;
if ( V_114 )
goto V_583;
if ( V_8 -> V_72 . V_315 . V_586 )
V_114 = V_8 -> V_72 . V_315 . V_586 ( V_8 , V_317 , V_581 , V_318 ) ;
V_583:
return V_114 ;
}
static void F_290 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_587 = 0 ;
if ( V_2 -> V_101 & V_369 ) {
V_587 = V_588 | V_589 |
V_590 ;
V_587 |= V_591 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
F_45 ( V_8 , V_592 , V_593 ) ;
break;
case V_75 :
case V_76 :
default:
F_45 ( V_8 , F_291 ( 0 ) , 0xFFFFFFFF ) ;
F_45 ( V_8 , F_291 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_45 ( V_8 , V_592 , V_593 ) ;
}
if ( V_2 -> V_101 & V_388 ) {
V_587 &= ~ V_594 ;
switch ( V_2 -> V_393 [ V_461 ] . V_79 ) {
case V_462 :
V_587 |= V_595 ;
break;
case V_464 :
V_587 |= V_596 ;
break;
default:
V_587 |= V_597 ;
break;
}
}
if ( V_2 -> V_115 & V_309 ) {
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
V_587 |= V_598 ;
break;
case V_76 :
V_587 |= V_338 ;
break;
default:
break;
}
}
if ( V_2 -> V_101 & V_322 )
V_587 |= V_599 ;
if ( V_8 -> V_72 . type == V_75 ) {
V_587 |= V_599 ;
V_587 |= V_600 ;
}
F_45 ( V_8 , V_601 , V_587 ) ;
}
static void F_292 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_361 ;
T_1 V_64 ;
F_46 ( V_2 ) ;
F_290 ( V_2 ) ;
if ( V_2 -> V_101 & V_369 )
F_166 ( V_2 ) ;
else
F_205 ( V_2 ) ;
if ( V_8 -> V_72 . V_315 . V_602 )
V_8 -> V_72 . V_315 . V_602 ( V_8 ) ;
F_8 ( V_3 , & V_2 -> V_4 ) ;
F_252 ( V_2 ) ;
if ( F_287 ( V_8 ) ) {
F_288 ( V_2 ) ;
} else {
V_361 = F_289 ( V_8 ) ;
if ( V_361 )
F_77 ( V_135 , L_79 , V_361 ) ;
}
F_11 ( V_8 , V_324 ) ;
F_183 ( V_2 , true , true ) ;
if ( V_2 -> V_101 & V_322 ) {
T_1 V_603 = F_11 ( V_8 , V_604 ) ;
if ( V_603 & V_605 )
F_173 ( V_133 , L_59 ) ;
}
F_293 ( V_2 -> V_18 ) ;
V_2 -> V_101 |= V_330 ;
V_2 -> V_331 = V_134 ;
F_294 ( & V_2 -> V_606 , V_134 ) ;
V_64 = F_11 ( V_8 , V_65 ) ;
V_64 |= V_607 ;
F_45 ( V_8 , V_65 , V_64 ) ;
}
void F_295 ( struct V_1 * V_2 )
{
F_296 ( F_297 () ) ;
V_2 -> V_18 -> V_38 = V_134 ;
while ( F_3 ( V_608 , & V_2 -> V_4 ) )
F_209 ( 1000 , 2000 ) ;
F_298 ( V_2 ) ;
if ( V_2 -> V_101 & V_388 )
F_299 ( 2000 ) ;
F_300 ( V_2 ) ;
F_8 ( V_608 , & V_2 -> V_4 ) ;
}
void F_300 ( struct V_1 * V_2 )
{
F_282 ( V_2 ) ;
F_292 ( V_2 ) ;
}
void F_301 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_361 ;
while ( F_3 ( V_609 , & V_2 -> V_4 ) )
F_209 ( 1000 , 2000 ) ;
V_2 -> V_115 &= ~ ( V_580 |
V_327 ) ;
V_2 -> V_101 &= ~ V_328 ;
V_361 = V_8 -> V_72 . V_315 . V_610 ( V_8 ) ;
switch ( V_361 ) {
case 0 :
case V_611 :
case V_612 :
break;
case V_613 :
F_302 ( L_80 ) ;
break;
case V_614 :
F_303 ( L_81
L_82
L_83
L_84
L_85
L_86 ) ;
break;
default:
F_302 ( L_87 , V_361 ) ;
}
F_8 ( V_609 , & V_2 -> V_4 ) ;
V_8 -> V_72 . V_315 . V_511 ( V_8 , 0 , V_8 -> V_72 . V_512 , F_227 ( 0 ) , V_513 ) ;
if ( V_8 -> V_72 . V_615 )
V_8 -> V_72 . V_315 . V_616 ( V_8 , F_227 ( 0 ) ) ;
if ( V_2 -> V_115 & V_617 )
F_304 ( V_2 ) ;
}
static void F_305 ( struct V_20 * V_30 )
{
struct V_153 * V_37 = V_30 -> V_37 ;
unsigned long V_259 ;
T_5 V_11 ;
if ( ! V_30 -> V_34 )
return;
for ( V_11 = 0 ; V_11 < V_30 -> V_52 ; V_11 ++ ) {
struct V_33 * V_258 ;
V_258 = & V_30 -> V_34 [ V_11 ] ;
if ( V_258 -> V_53 ) {
struct V_158 * V_53 = V_258 -> V_53 ;
if ( F_127 ( V_53 ) -> V_251 ) {
F_54 ( V_37 ,
F_127 ( V_53 ) -> V_45 ,
F_43 ( V_30 ) ,
V_190 ) ;
F_127 ( V_53 ) -> V_251 = false ;
}
F_306 ( V_53 ) ;
}
V_258 -> V_53 = NULL ;
if ( V_258 -> V_45 )
F_54 ( V_37 , V_258 -> V_45 ,
F_115 ( V_30 ) ,
V_190 ) ;
V_258 -> V_45 = 0 ;
if ( V_258 -> V_62 )
F_117 ( V_258 -> V_62 ,
F_113 ( V_30 ) ) ;
V_258 -> V_62 = NULL ;
}
V_259 = sizeof( struct V_33 ) * V_30 -> V_52 ;
memset ( V_30 -> V_34 , 0 , V_259 ) ;
memset ( V_30 -> V_51 , 0 , V_30 -> V_259 ) ;
V_30 -> V_184 = 0 ;
V_30 -> V_43 = 0 ;
V_30 -> V_44 = 0 ;
}
static void F_307 ( struct V_20 * V_21 )
{
struct V_22 * V_42 ;
unsigned long V_259 ;
T_5 V_11 ;
if ( ! V_21 -> V_42 )
return;
for ( V_11 = 0 ; V_11 < V_21 -> V_52 ; V_11 ++ ) {
V_42 = & V_21 -> V_42 [ V_11 ] ;
F_51 ( V_21 , V_42 ) ;
}
F_308 ( F_81 ( V_21 ) ) ;
V_259 = sizeof( struct V_22 ) * V_21 -> V_52 ;
memset ( V_21 -> V_42 , 0 , V_259 ) ;
memset ( V_21 -> V_51 , 0 , V_21 -> V_259 ) ;
V_21 -> V_44 = 0 ;
V_21 -> V_43 = 0 ;
}
static void F_309 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ )
F_305 ( V_2 -> V_30 [ V_11 ] ) ;
}
static void F_310 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_307 ( V_2 -> V_21 [ V_11 ] ) ;
}
static void F_311 ( struct V_1 * V_2 )
{
struct V_558 * V_559 , * V_560 ;
struct V_561 * V_562 ;
F_276 ( & V_2 -> V_563 ) ;
F_279 (filter, node, node2,
&adapter->fdir_filter_list, fdir_node) {
F_312 ( & V_562 -> V_618 ) ;
F_199 ( V_562 ) ;
}
V_2 -> V_619 = 0 ;
F_281 ( & V_2 -> V_563 ) ;
}
void F_298 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_145 ;
int V_11 ;
F_208 ( V_3 , & V_2 -> V_4 ) ;
V_145 = F_11 ( V_8 , V_493 ) ;
F_45 ( V_8 , V_493 , V_145 & ~ V_494 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ )
F_222 ( V_2 , V_2 -> V_30 [ V_11 ] ) ;
F_209 ( 10000 , 20000 ) ;
F_313 ( V_18 ) ;
F_314 ( V_18 ) ;
F_315 ( V_18 ) ;
F_203 ( V_2 ) ;
F_254 ( V_2 ) ;
V_2 -> V_115 &= ~ ( V_344 |
V_116 ) ;
V_2 -> V_101 &= ~ V_330 ;
F_316 ( & V_2 -> V_606 ) ;
if ( V_2 -> V_281 ) {
F_45 ( & V_2 -> V_8 , V_283 , 0 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_281 ; V_11 ++ )
V_2 -> V_469 [ V_11 ] . V_620 = false ;
F_317 ( V_2 ) ;
F_318 ( V_2 ) ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
T_4 V_108 = V_2 -> V_21 [ V_11 ] -> V_108 ;
F_45 ( V_8 , F_24 ( V_108 ) , V_621 ) ;
}
switch ( V_8 -> V_72 . type ) {
case V_75 :
case V_76 :
F_45 ( V_8 , V_404 ,
( F_11 ( V_8 , V_404 ) &
~ V_405 ) ) ;
break;
default:
break;
}
if ( ! F_319 ( V_2 -> V_36 ) )
F_301 ( V_2 ) ;
if ( V_8 -> V_72 . V_315 . V_622 )
V_8 -> V_72 . V_315 . V_622 ( V_8 ) ;
F_310 ( V_2 ) ;
F_309 ( V_2 ) ;
#ifdef F_192
F_97 ( V_2 ) ;
#endif
}
static void F_320 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
F_66 ( V_2 ) ;
}
static int F_321 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_623 * V_36 = V_2 -> V_36 ;
unsigned int V_164 ;
T_1 V_624 ;
#ifdef F_283
int V_12 ;
struct V_625 * V_96 ;
#endif
V_8 -> V_626 = V_36 -> V_627 ;
V_8 -> V_311 = V_36 -> V_153 ;
V_8 -> V_628 = V_36 -> V_629 ;
V_8 -> V_630 = V_36 -> V_631 ;
V_8 -> V_632 = V_36 -> V_633 ;
V_164 = F_322 ( int , V_634 , F_323 () ) ;
V_2 -> V_393 [ V_394 ] . V_635 = V_164 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
if ( V_8 -> V_311 == V_636 )
V_2 -> V_101 |= V_322 ;
V_2 -> V_637 = V_638 ;
break;
case V_76 :
V_624 = F_11 ( V_8 , V_639 ) ;
if ( V_624 & V_640 )
V_2 -> V_115 |= V_309 ;
case V_75 :
V_2 -> V_637 = V_641 ;
V_2 -> V_115 |= V_642 ;
V_2 -> V_115 |= V_483 ;
if ( V_8 -> V_311 == V_312 )
V_2 -> V_115 |= V_309 ;
V_2 -> V_379 = 20 ;
V_2 -> V_393 [ V_643 ] . V_635 =
V_644 ;
V_2 -> V_555 = V_645 ;
#ifdef F_122
V_2 -> V_101 |= V_646 ;
V_2 -> V_101 &= ~ V_475 ;
#ifdef F_283
V_2 -> V_647 . V_648 = V_649 ;
#endif
#endif
break;
default:
break;
}
#ifdef F_122
F_324 ( & V_2 -> V_647 . V_650 ) ;
#endif
F_324 ( & V_2 -> V_563 ) ;
#ifdef F_283
switch ( V_8 -> V_72 . type ) {
case V_76 :
V_2 -> V_98 . V_651 . V_652 = V_653 ;
V_2 -> V_98 . V_651 . V_654 = V_653 ;
break;
default:
V_2 -> V_98 . V_651 . V_652 = V_655 ;
V_2 -> V_98 . V_651 . V_654 = V_655 ;
break;
}
for ( V_12 = 0 ; V_12 < V_655 ; V_12 ++ ) {
V_96 = & V_2 -> V_98 . V_656 [ V_12 ] ;
V_96 -> V_657 [ V_538 ] . V_658 = 0 ;
V_96 -> V_657 [ V_538 ] . V_659 = 12 + ( V_12 & 1 ) ;
V_96 -> V_657 [ V_539 ] . V_658 = 0 ;
V_96 -> V_657 [ V_539 ] . V_659 = 12 + ( V_12 & 1 ) ;
V_96 -> V_660 = V_661 ;
}
V_96 = & V_2 -> V_98 . V_656 [ 0 ] ;
V_96 -> V_657 [ V_538 ] . V_662 = 0xFF ;
V_96 -> V_657 [ V_539 ] . V_662 = 0xFF ;
V_2 -> V_98 . V_663 [ V_538 ] [ 0 ] = 100 ;
V_2 -> V_98 . V_663 [ V_539 ] [ 0 ] = 100 ;
V_2 -> V_98 . V_99 = false ;
V_2 -> V_664 = 0x00 ;
V_2 -> V_536 = V_665 | V_537 ;
memcpy ( & V_2 -> V_666 , & V_2 -> V_98 ,
sizeof( V_2 -> V_666 ) ) ;
#endif
V_8 -> V_87 . V_667 = V_89 ;
V_8 -> V_87 . V_88 = V_89 ;
F_273 ( V_2 ) ;
V_8 -> V_87 . V_668 = V_669 ;
V_8 -> V_87 . V_670 = true ;
V_8 -> V_87 . V_671 =
( F_325 ( V_8 ) == 0 ) ? false : true ;
#ifdef F_326
if ( V_8 -> V_72 . type != V_73 )
V_2 -> V_281 = ( V_672 > 63 ) ? 0 : V_672 ;
#endif
V_2 -> V_359 = 1 ;
V_2 -> V_673 = 1 ;
V_2 -> V_674 = V_675 ;
V_2 -> V_676 = V_677 ;
V_2 -> V_678 = V_679 ;
if ( F_327 ( V_8 ) ) {
F_302 ( L_88 ) ;
return - V_680 ;
}
F_208 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
}
int F_328 ( struct V_20 * V_21 )
{
struct V_153 * V_37 = V_21 -> V_37 ;
int V_681 = F_329 ( V_37 ) ;
int V_682 = - 1 ;
int V_259 ;
V_259 = sizeof( struct V_22 ) * V_21 -> V_52 ;
if ( V_21 -> V_118 )
V_682 = V_21 -> V_118 -> V_682 ;
V_21 -> V_42 = F_330 ( V_259 , V_682 ) ;
if ( ! V_21 -> V_42 )
V_21 -> V_42 = F_331 ( V_259 ) ;
if ( ! V_21 -> V_42 )
goto V_361;
V_21 -> V_259 = V_21 -> V_52 * sizeof( union V_24 ) ;
V_21 -> V_259 = F_143 ( V_21 -> V_259 , 4096 ) ;
F_332 ( V_37 , V_682 ) ;
V_21 -> V_51 = F_333 ( V_37 ,
V_21 -> V_259 ,
& V_21 -> V_45 ,
V_683 ) ;
F_332 ( V_37 , V_681 ) ;
if ( ! V_21 -> V_51 )
V_21 -> V_51 = F_333 ( V_37 , V_21 -> V_259 ,
& V_21 -> V_45 , V_683 ) ;
if ( ! V_21 -> V_51 )
goto V_361;
V_21 -> V_44 = 0 ;
V_21 -> V_43 = 0 ;
return 0 ;
V_361:
F_334 ( V_21 -> V_42 ) ;
V_21 -> V_42 = NULL ;
F_335 ( V_37 , L_89 ) ;
return - V_508 ;
}
static int F_336 ( struct V_1 * V_2 )
{
int V_11 , V_361 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
V_361 = F_328 ( V_2 -> V_21 [ V_11 ] ) ;
if ( ! V_361 )
continue;
F_77 ( V_135 , L_90 , V_11 ) ;
goto V_684;
}
return 0 ;
V_684:
while ( V_11 -- )
F_337 ( V_2 -> V_21 [ V_11 ] ) ;
return V_361 ;
}
int F_338 ( struct V_20 * V_30 )
{
struct V_153 * V_37 = V_30 -> V_37 ;
int V_681 = F_329 ( V_37 ) ;
int V_682 = - 1 ;
int V_259 ;
V_259 = sizeof( struct V_33 ) * V_30 -> V_52 ;
if ( V_30 -> V_118 )
V_682 = V_30 -> V_118 -> V_682 ;
V_30 -> V_34 = F_330 ( V_259 , V_682 ) ;
if ( ! V_30 -> V_34 )
V_30 -> V_34 = F_331 ( V_259 ) ;
if ( ! V_30 -> V_34 )
goto V_361;
V_30 -> V_259 = V_30 -> V_52 * sizeof( union V_31 ) ;
V_30 -> V_259 = F_143 ( V_30 -> V_259 , 4096 ) ;
F_332 ( V_37 , V_682 ) ;
V_30 -> V_51 = F_333 ( V_37 ,
V_30 -> V_259 ,
& V_30 -> V_45 ,
V_683 ) ;
F_332 ( V_37 , V_681 ) ;
if ( ! V_30 -> V_51 )
V_30 -> V_51 = F_333 ( V_37 , V_30 -> V_259 ,
& V_30 -> V_45 , V_683 ) ;
if ( ! V_30 -> V_51 )
goto V_361;
V_30 -> V_43 = 0 ;
V_30 -> V_44 = 0 ;
return 0 ;
V_361:
F_334 ( V_30 -> V_34 ) ;
V_30 -> V_34 = NULL ;
F_335 ( V_37 , L_91 ) ;
return - V_508 ;
}
static int F_339 ( struct V_1 * V_2 )
{
int V_11 , V_361 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
V_361 = F_338 ( V_2 -> V_30 [ V_11 ] ) ;
if ( ! V_361 )
continue;
F_77 ( V_135 , L_92 , V_11 ) ;
goto V_685;
}
#ifdef F_122
V_361 = F_340 ( V_2 ) ;
if ( ! V_361 )
#endif
return 0 ;
V_685:
while ( V_11 -- )
F_341 ( V_2 -> V_30 [ V_11 ] ) ;
return V_361 ;
}
void F_337 ( struct V_20 * V_21 )
{
F_307 ( V_21 ) ;
F_334 ( V_21 -> V_42 ) ;
V_21 -> V_42 = NULL ;
if ( ! V_21 -> V_51 )
return;
F_342 ( V_21 -> V_37 , V_21 -> V_259 ,
V_21 -> V_51 , V_21 -> V_45 ) ;
V_21 -> V_51 = NULL ;
}
static void F_343 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
if ( V_2 -> V_21 [ V_11 ] -> V_51 )
F_337 ( V_2 -> V_21 [ V_11 ] ) ;
}
void F_341 ( struct V_20 * V_30 )
{
F_305 ( V_30 ) ;
F_334 ( V_30 -> V_34 ) ;
V_30 -> V_34 = NULL ;
if ( ! V_30 -> V_51 )
return;
F_342 ( V_30 -> V_37 , V_30 -> V_259 ,
V_30 -> V_51 , V_30 -> V_45 ) ;
V_30 -> V_51 = NULL ;
}
static void F_344 ( struct V_1 * V_2 )
{
int V_11 ;
#ifdef F_122
F_345 ( V_2 ) ;
#endif
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ )
if ( V_2 -> V_30 [ V_11 ] -> V_51 )
F_341 ( V_2 -> V_30 [ V_11 ] ) ;
}
static int F_346 ( struct V_17 * V_18 , int V_686 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
int V_471 = V_686 + V_209 + V_472 ;
if ( ( V_686 < 68 ) || ( V_471 > V_687 ) )
return - V_688 ;
if ( ( V_2 -> V_101 & V_388 ) &&
( V_2 -> V_8 . V_72 . type == V_75 ) &&
( V_471 > V_689 ) )
F_269 ( V_135 , L_93 ) ;
F_79 ( V_135 , L_94 , V_18 -> V_275 , V_686 ) ;
V_18 -> V_275 = V_686 ;
if ( F_31 ( V_18 ) )
F_295 ( V_2 ) ;
return 0 ;
}
static int F_347 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
int V_361 ;
if ( F_2 ( V_690 , & V_2 -> V_4 ) )
return - V_691 ;
F_314 ( V_18 ) ;
V_361 = F_336 ( V_2 ) ;
if ( V_361 )
goto V_684;
V_361 = F_339 ( V_2 ) ;
if ( V_361 )
goto V_685;
F_282 ( V_2 ) ;
V_361 = F_201 ( V_2 ) ;
if ( V_361 )
goto V_692;
V_361 = F_348 ( V_18 ,
V_2 -> V_448 > 1 ? 1 :
V_2 -> V_41 ) ;
if ( V_361 )
goto V_693;
V_361 = F_349 ( V_18 ,
V_2 -> V_448 > 1 ? 1 :
V_2 -> V_57 ) ;
if ( V_361 )
goto V_693;
F_350 ( V_2 ) ;
F_292 ( V_2 ) ;
return 0 ;
V_693:
F_202 ( V_2 ) ;
V_692:
F_344 ( V_2 ) ;
V_685:
F_343 ( V_2 ) ;
V_684:
F_301 ( V_2 ) ;
return V_361 ;
}
static int F_351 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
F_352 ( V_2 ) ;
F_298 ( V_2 ) ;
F_202 ( V_2 ) ;
F_311 ( V_2 ) ;
F_343 ( V_2 ) ;
F_344 ( V_2 ) ;
F_44 ( V_2 ) ;
return 0 ;
}
static int F_353 ( struct V_623 * V_36 )
{
struct V_1 * V_2 = F_354 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_361 ;
F_355 ( V_36 , V_694 ) ;
F_356 ( V_36 ) ;
F_357 ( V_36 ) ;
V_361 = F_358 ( V_36 ) ;
if ( V_361 ) {
F_302 ( L_95 ) ;
return V_361 ;
}
F_359 ( V_36 ) ;
F_360 ( V_36 , false ) ;
F_301 ( V_2 ) ;
F_45 ( & V_2 -> V_8 , V_695 , ~ 0 ) ;
F_361 () ;
V_361 = F_362 ( V_2 ) ;
if ( ! V_361 && F_31 ( V_18 ) )
V_361 = F_347 ( V_18 ) ;
F_363 () ;
if ( V_361 )
return V_361 ;
F_364 ( V_18 ) ;
return 0 ;
}
static int F_365 ( struct V_623 * V_36 , bool * V_696 )
{
struct V_1 * V_2 = F_354 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_697 , V_515 ;
T_1 V_698 = V_2 -> V_699 ;
#ifdef F_366
int V_700 = 0 ;
#endif
F_367 ( V_18 ) ;
if ( F_31 ( V_18 ) ) {
F_361 () ;
F_298 ( V_2 ) ;
F_202 ( V_2 ) ;
F_343 ( V_2 ) ;
F_344 ( V_2 ) ;
F_363 () ;
}
F_368 ( V_2 ) ;
#ifdef F_366
V_700 = F_357 ( V_36 ) ;
if ( V_700 )
return V_700 ;
#endif
if ( V_698 ) {
F_249 ( V_18 ) ;
if ( V_8 -> V_72 . V_315 . V_602 )
V_8 -> V_72 . V_315 . V_602 ( V_8 ) ;
if ( V_698 & V_701 ) {
V_515 = F_11 ( V_8 , V_519 ) ;
V_515 |= V_525 ;
F_45 ( V_8 , V_519 , V_515 ) ;
}
V_697 = F_11 ( V_8 , V_702 ) ;
V_697 |= V_703 ;
F_45 ( V_8 , V_702 , V_697 ) ;
F_45 ( V_8 , V_704 , V_698 ) ;
} else {
F_45 ( V_8 , V_705 , 0 ) ;
F_45 ( V_8 , V_704 , 0 ) ;
}
switch ( V_8 -> V_72 . type ) {
case V_73 :
F_360 ( V_36 , false ) ;
break;
case V_75 :
case V_76 :
F_360 ( V_36 , ! ! V_698 ) ;
break;
default:
break;
}
* V_696 = ! ! V_698 ;
F_44 ( V_2 ) ;
F_369 ( V_36 ) ;
return 0 ;
}
static int F_370 ( struct V_623 * V_36 , T_11 V_4 )
{
int V_700 ;
bool V_706 ;
V_700 = F_365 ( V_36 , & V_706 ) ;
if ( V_700 )
return V_700 ;
if ( V_706 ) {
F_371 ( V_36 ) ;
} else {
F_360 ( V_36 , false ) ;
F_355 ( V_36 , V_707 ) ;
}
return 0 ;
}
static void F_372 ( struct V_623 * V_36 )
{
bool V_706 ;
F_365 ( V_36 , & V_706 ) ;
if ( V_708 == V_709 ) {
F_360 ( V_36 , V_706 ) ;
F_355 ( V_36 , V_707 ) ;
}
}
void F_373 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_84 * V_85 = & V_2 -> V_86 ;
T_2 V_710 = 0 ;
T_1 V_11 , V_711 = 0 , V_712 , V_713 , V_714 , V_715 , V_716 ;
T_2 V_243 = 0 , V_137 = 0 , V_717 = 0 ;
T_2 V_189 = 0 , V_268 = 0 ;
T_2 V_132 = 0 , V_106 = 0 , V_718 = 0 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_608 , & V_2 -> V_4 ) )
return;
if ( V_2 -> V_115 & V_483 ) {
T_2 V_228 = 0 ;
T_2 V_229 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
V_228 += V_2 -> V_30 [ V_11 ] -> V_175 . V_228 ;
V_229 += V_2 -> V_30 [ V_11 ] -> V_175 . V_229 ;
}
V_2 -> V_719 = V_228 ;
V_2 -> V_720 = V_229 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
struct V_20 * V_30 = V_2 -> V_30 [ V_11 ] ;
V_243 += V_30 -> V_175 . V_243 ;
V_189 += V_30 -> V_175 . V_189 ;
V_268 += V_30 -> V_175 . V_268 ;
V_718 += V_30 -> V_175 . V_176 ;
V_132 += V_30 -> V_86 . V_132 ;
V_106 += V_30 -> V_86 . V_106 ;
}
V_2 -> V_243 = V_243 ;
V_2 -> V_189 = V_189 ;
V_2 -> V_268 = V_268 ;
V_2 -> V_718 = V_718 ;
V_18 -> V_86 . V_721 = V_132 ;
V_18 -> V_86 . V_722 = V_106 ;
V_132 = 0 ;
V_106 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_21 = V_2 -> V_21 [ V_11 ] ;
V_137 += V_21 -> V_112 . V_137 ;
V_717 += V_21 -> V_112 . V_717 ;
V_132 += V_21 -> V_86 . V_132 ;
V_106 += V_21 -> V_86 . V_106 ;
}
V_2 -> V_137 = V_137 ;
V_2 -> V_717 = V_717 ;
V_18 -> V_86 . V_723 = V_132 ;
V_18 -> V_86 . V_724 = V_106 ;
V_85 -> V_725 += F_11 ( V_8 , V_726 ) ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_712 = F_11 ( V_8 , F_374 ( V_11 ) ) ;
V_711 += V_712 ;
V_85 -> V_712 [ V_11 ] += V_712 ;
V_710 += V_85 -> V_712 [ V_11 ] ;
V_85 -> V_727 [ V_11 ] += F_11 ( V_8 , F_375 ( V_11 ) ) ;
V_85 -> V_728 [ V_11 ] += F_11 ( V_8 , F_376 ( V_11 ) ) ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_85 -> V_729 [ V_11 ] += F_11 ( V_8 , F_377 ( V_11 ) ) ;
V_85 -> V_730 [ V_11 ] += F_11 ( V_8 , F_378 ( V_11 ) ) ;
V_85 -> V_731 [ V_11 ] += F_11 ( V_8 , F_379 ( V_11 ) ) ;
V_85 -> V_732 [ V_11 ] +=
F_11 ( V_8 , F_380 ( V_11 ) ) ;
break;
case V_75 :
case V_76 :
V_85 -> V_732 [ V_11 ] +=
F_11 ( V_8 , F_381 ( V_11 ) ) ;
break;
default:
break;
}
}
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ ) {
V_85 -> V_733 [ V_11 ] += F_11 ( V_8 , F_382 ( V_11 ) ) ;
V_85 -> V_734 [ V_11 ] += F_11 ( V_8 , F_383 ( V_11 ) ) ;
if ( ( V_8 -> V_72 . type == V_75 ) ||
( V_8 -> V_72 . type == V_76 ) ) {
V_85 -> V_730 [ V_11 ] += F_11 ( V_8 , F_384 ( V_11 ) ) ;
F_11 ( V_8 , F_385 ( V_11 ) ) ;
V_85 -> V_731 [ V_11 ] += F_11 ( V_8 , F_386 ( V_11 ) ) ;
F_11 ( V_8 , F_387 ( V_11 ) ) ;
}
}
V_85 -> V_735 += F_11 ( V_8 , V_736 ) ;
V_85 -> V_735 -= V_711 ;
F_57 ( V_2 ) ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_85 -> V_737 += F_11 ( V_8 , V_738 ) ;
V_85 -> V_739 += F_11 ( V_8 , V_740 ) ;
V_85 -> V_741 += F_11 ( V_8 , V_742 ) ;
V_85 -> V_743 += F_11 ( V_8 , V_744 ) ;
break;
case V_76 :
V_85 -> V_745 += F_11 ( V_8 , V_746 ) ;
V_85 -> V_747 += F_11 ( V_8 , V_748 ) ;
V_85 -> V_749 += F_11 ( V_8 , V_750 ) ;
V_85 -> V_751 += F_11 ( V_8 , V_752 ) ;
case V_75 :
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
V_2 -> V_753 +=
F_11 ( V_8 , F_388 ( V_11 ) ) ;
V_85 -> V_739 += F_11 ( V_8 , V_754 ) ;
F_11 ( V_8 , V_740 ) ;
V_85 -> V_741 += F_11 ( V_8 , V_755 ) ;
F_11 ( V_8 , V_742 ) ;
V_85 -> V_743 += F_11 ( V_8 , V_756 ) ;
F_11 ( V_8 , V_744 ) ;
V_85 -> V_737 += F_11 ( V_8 , V_757 ) ;
V_85 -> V_758 += F_11 ( V_8 , V_759 ) ;
V_85 -> V_760 += F_11 ( V_8 , V_761 ) ;
#ifdef F_122
V_85 -> V_762 += F_11 ( V_8 , V_763 ) ;
V_85 -> V_764 += F_11 ( V_8 , V_765 ) ;
V_85 -> V_766 += F_11 ( V_8 , V_767 ) ;
V_85 -> V_768 += F_11 ( V_8 , V_769 ) ;
V_85 -> V_770 += F_11 ( V_8 , V_771 ) ;
V_85 -> V_772 += F_11 ( V_8 , V_773 ) ;
if ( V_2 -> V_647 . V_774 ) {
struct V_775 * V_647 = & V_2 -> V_647 ;
struct V_776 * V_774 ;
unsigned int V_138 ;
T_2 V_777 = 0 , V_778 = 0 ;
F_389 (cpu) {
V_774 = F_390 ( V_647 -> V_774 , V_138 ) ;
V_777 += V_774 -> V_777 ;
V_778 += V_774 -> V_778 ;
}
V_85 -> V_779 = V_777 ;
V_85 -> V_780 = V_778 ;
}
#endif
break;
default:
break;
}
V_713 = F_11 ( V_8 , V_781 ) ;
V_85 -> V_713 += V_713 ;
V_85 -> V_782 += F_11 ( V_8 , V_783 ) ;
if ( V_8 -> V_72 . type == V_73 )
V_85 -> V_782 -= V_713 ;
V_85 -> V_784 += F_11 ( V_8 , V_785 ) ;
V_85 -> V_786 += F_11 ( V_8 , V_787 ) ;
V_85 -> V_788 += F_11 ( V_8 , V_789 ) ;
V_85 -> V_790 += F_11 ( V_8 , V_791 ) ;
V_85 -> V_792 += F_11 ( V_8 , V_793 ) ;
V_85 -> V_794 += F_11 ( V_8 , V_795 ) ;
V_85 -> V_796 += F_11 ( V_8 , V_797 ) ;
V_85 -> V_798 += F_11 ( V_8 , V_799 ) ;
V_714 = F_11 ( V_8 , V_800 ) ;
V_85 -> V_801 += V_714 ;
V_715 = F_11 ( V_8 , V_802 ) ;
V_85 -> V_803 += V_715 ;
V_85 -> V_804 += F_11 ( V_8 , V_805 ) ;
V_85 -> V_806 += F_11 ( V_8 , V_807 ) ;
V_716 = V_714 + V_715 ;
V_85 -> V_804 -= V_716 ;
V_85 -> V_806 -= V_716 ;
V_85 -> V_741 -= ( V_716 * ( V_808 + V_472 ) ) ;
V_85 -> V_809 += F_11 ( V_8 , V_810 ) ;
V_85 -> V_811 += F_11 ( V_8 , V_812 ) ;
V_85 -> V_813 += F_11 ( V_8 , V_814 ) ;
V_85 -> V_815 += F_11 ( V_8 , V_816 ) ;
V_85 -> V_817 += F_11 ( V_8 , V_818 ) ;
V_85 -> V_817 -= V_716 ;
V_85 -> V_819 += F_11 ( V_8 , V_820 ) ;
V_85 -> V_821 += F_11 ( V_8 , V_822 ) ;
V_85 -> V_823 += F_11 ( V_8 , V_824 ) ;
V_85 -> V_825 += F_11 ( V_8 , V_826 ) ;
V_85 -> V_827 += F_11 ( V_8 , V_828 ) ;
V_85 -> V_829 += F_11 ( V_8 , V_830 ) ;
V_18 -> V_86 . V_831 = V_85 -> V_782 ;
V_18 -> V_86 . V_832 = V_85 -> V_725 + V_85 -> V_798 ;
V_18 -> V_86 . V_833 = 0 ;
V_18 -> V_86 . V_834 = V_85 -> V_798 ;
V_18 -> V_86 . V_835 = V_85 -> V_725 ;
V_18 -> V_86 . V_836 = V_710 ;
}
static void F_391 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_11 ;
if ( ! ( V_2 -> V_115 & V_344 ) )
return;
V_2 -> V_115 &= ~ V_344 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
if ( ! ( V_2 -> V_101 & V_343 ) )
return;
V_2 -> V_837 ++ ;
if ( F_392 ( V_8 ) == 0 ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_208 ( V_352 ,
& ( V_2 -> V_21 [ V_11 ] -> V_4 ) ) ;
F_45 ( V_8 , V_334 , V_345 ) ;
} else {
F_77 ( V_135 , L_96
L_97 ) ;
}
}
static void F_393 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_838 = 0 ;
int V_11 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_608 , & V_2 -> V_4 ) )
return;
if ( F_83 ( V_2 -> V_18 ) ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_394 ( V_2 -> V_21 [ V_11 ] ) ;
}
if ( ! ( V_2 -> V_101 & V_369 ) ) {
F_45 ( V_8 , V_81 ,
( V_839 | V_840 ) ) ;
} else {
for ( V_11 = 0 ; V_11 < V_2 -> V_152 ; V_11 ++ ) {
struct V_117 * V_841 = V_2 -> V_118 [ V_11 ] ;
if ( V_841 -> V_279 . V_82 || V_841 -> V_122 . V_82 )
V_838 |= ( ( T_2 ) 1 << V_11 ) ;
}
}
F_49 ( V_2 , V_838 ) ;
}
static void F_395 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_842 = V_2 -> V_842 ;
bool V_318 = V_2 -> V_318 ;
bool V_97 = V_2 -> V_98 . V_99 ;
if ( ! ( V_2 -> V_101 & V_330 ) )
return;
if ( V_8 -> V_72 . V_315 . V_316 ) {
V_8 -> V_72 . V_315 . V_316 ( V_8 , & V_842 , & V_318 , false ) ;
} else {
V_842 = V_843 ;
V_318 = true ;
}
if ( V_2 -> V_100 )
V_97 |= ! ! ( V_2 -> V_100 -> V_97 ) ;
if ( V_318 && ! ( ( V_2 -> V_101 & V_102 ) && V_97 ) ) {
V_8 -> V_72 . V_315 . V_844 ( V_8 ) ;
F_396 ( V_2 ) ;
}
if ( V_318 ||
F_397 ( V_134 , ( V_2 -> V_331 +
V_845 ) ) ) {
V_2 -> V_101 &= ~ V_330 ;
F_45 ( V_8 , V_334 , V_333 ) ;
F_178 ( V_8 ) ;
}
V_2 -> V_318 = V_318 ;
V_2 -> V_842 = V_842 ;
}
static void F_398 ( struct V_1 * V_2 )
{
#ifdef F_283
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_846 V_847 = {
. V_848 = V_849 ,
. V_206 = 0 ,
} ;
T_4 V_648 = 0 ;
if ( V_2 -> V_536 & V_850 )
V_648 = F_399 ( V_18 , & V_847 ) ;
V_2 -> V_851 = ( V_648 > 1 ) ? ( F_400 ( V_648 ) - 1 ) : 0 ;
#endif
}
static void F_401 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_842 = V_2 -> V_842 ;
bool V_852 , V_853 ;
if ( F_83 ( V_18 ) )
return;
V_2 -> V_115 &= ~ V_580 ;
switch ( V_8 -> V_72 . type ) {
case V_73 : {
T_1 V_854 = F_11 ( V_8 , V_519 ) ;
T_1 V_855 = F_11 ( V_8 , V_856 ) ;
V_852 = ! ! ( V_854 & V_857 ) ;
V_853 = ! ! ( V_855 & V_858 ) ;
}
break;
case V_76 :
case V_75 : {
T_1 V_859 = F_11 ( V_8 , V_860 ) ;
T_1 V_861 = F_11 ( V_8 , V_862 ) ;
V_852 = ! ! ( V_859 & V_863 ) ;
V_853 = ! ! ( V_861 & V_864 ) ;
}
break;
default:
V_853 = false ;
V_852 = false ;
break;
}
if ( V_2 -> V_115 & V_617 )
F_402 ( V_2 ) ;
F_79 ( V_133 , L_98 ,
( V_842 == V_843 ?
L_99 :
( V_842 == V_865 ?
L_100 :
( V_842 == V_866 ?
L_101 :
L_102 ) ) ) ,
( ( V_852 && V_853 ) ? L_103 :
( V_852 ? L_104 :
( V_853 ? L_105 : L_106 ) ) ) ) ;
F_403 ( V_18 ) ;
F_404 ( V_2 ) ;
F_398 ( V_2 ) ;
F_317 ( V_2 ) ;
}
static void F_405 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
V_2 -> V_318 = false ;
V_2 -> V_842 = 0 ;
if ( ! F_83 ( V_18 ) )
return;
if ( F_287 ( V_8 ) && V_8 -> V_72 . type == V_73 )
V_2 -> V_115 |= V_580 ;
if ( V_2 -> V_115 & V_617 )
F_402 ( V_2 ) ;
F_79 ( V_133 , L_107 ) ;
F_314 ( V_18 ) ;
F_317 ( V_2 ) ;
}
static void F_406 ( struct V_1 * V_2 )
{
int V_11 ;
int V_867 = 0 ;
if ( ! F_83 ( V_2 -> V_18 ) ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_21 = V_2 -> V_21 [ V_11 ] ;
if ( V_21 -> V_44 != V_21 -> V_43 ) {
V_867 = 1 ;
break;
}
}
if ( V_867 ) {
V_2 -> V_115 |= V_116 ;
}
}
}
static void F_407 ( struct V_1 * V_2 )
{
T_1 V_868 ;
if ( V_2 -> V_8 . V_72 . type == V_73 ||
V_2 -> V_281 == 0 )
return;
V_868 = F_11 ( & V_2 -> V_8 , V_869 ) ;
if ( ! V_868 )
return;
F_269 ( V_133 , L_108 , V_868 ) ;
}
static void F_408 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_608 , & V_2 -> V_4 ) )
return;
F_395 ( V_2 ) ;
if ( V_2 -> V_318 )
F_401 ( V_2 ) ;
else
F_405 ( V_2 ) ;
F_407 ( V_2 ) ;
F_373 ( V_2 ) ;
F_406 ( V_2 ) ;
}
static void F_409 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_12 V_361 ;
if ( ! ( V_2 -> V_115 & V_580 ) &&
! ( V_2 -> V_115 & V_327 ) )
return;
if ( F_3 ( V_609 , & V_2 -> V_4 ) )
return;
V_361 = V_8 -> V_319 . V_315 . V_870 ( V_8 ) ;
if ( V_361 == V_612 )
goto V_871;
if ( V_361 == V_611 ) {
V_2 -> V_115 |= V_327 ;
}
if ( V_361 )
goto V_871;
if ( ! ( V_2 -> V_115 & V_327 ) )
goto V_871;
V_2 -> V_115 &= ~ V_327 ;
if ( V_8 -> V_72 . type == V_73 )
V_361 = V_8 -> V_319 . V_315 . V_872 ( V_8 ) ;
else
V_361 = V_8 -> V_72 . V_315 . V_873 ( V_8 ) ;
if ( V_361 == V_612 )
goto V_871;
V_2 -> V_101 |= V_328 ;
F_79 ( V_135 , L_109 , V_8 -> V_319 . V_874 ) ;
V_871:
F_8 ( V_609 , & V_2 -> V_4 ) ;
if ( ( V_361 == V_612 ) &&
( V_2 -> V_18 -> V_875 == V_876 ) ) {
F_302 ( L_110
L_111 ) ;
F_302 ( L_112
L_113 ) ;
F_410 ( V_2 -> V_18 ) ;
}
}
static void F_411 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_317 ;
bool V_581 ;
if ( ! ( V_2 -> V_101 & V_328 ) )
return;
if ( F_3 ( V_609 , & V_2 -> V_4 ) )
return;
V_2 -> V_101 &= ~ V_328 ;
V_317 = V_8 -> V_319 . V_584 ;
if ( ( ! V_317 ) && ( V_8 -> V_72 . V_315 . V_585 ) )
V_8 -> V_72 . V_315 . V_585 ( V_8 , & V_317 , & V_581 ) ;
if ( V_8 -> V_72 . V_315 . V_586 )
V_8 -> V_72 . V_315 . V_586 ( V_8 , V_317 , V_581 , true ) ;
V_2 -> V_101 |= V_330 ;
V_2 -> V_331 = V_134 ;
F_8 ( V_609 , & V_2 -> V_4 ) ;
}
static void F_412 ( struct V_1 * V_2 )
{
int V_877 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_878 ;
T_1 V_879 , V_880 ;
V_878 = F_11 ( V_8 , V_881 ) ;
if ( V_878 )
return;
for ( V_877 = 0 ; V_877 < V_2 -> V_281 ; V_877 ++ ) {
V_879 = ( V_877 << 16 ) | 0x80000000 ;
V_879 |= V_882 ;
F_45 ( V_8 , V_883 , V_879 ) ;
V_880 = F_11 ( V_8 , V_884 ) ;
V_879 &= 0x7FFFFFFF ;
F_45 ( V_8 , V_883 , V_879 ) ;
V_880 >>= 16 ;
if ( V_880 & V_885 ) {
F_413 ( V_18 , L_114 , V_877 ) ;
V_879 = ( V_877 << 16 ) | 0x80000000 ;
V_879 |= 0xA8 ;
F_45 ( V_8 , V_883 , V_879 ) ;
V_880 = 0x00008000 ;
F_45 ( V_8 , V_884 , V_880 ) ;
V_879 &= 0x7FFFFFFF ;
F_45 ( V_8 , V_883 , V_879 ) ;
}
}
}
static void F_414 ( unsigned long V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
unsigned long V_886 ;
bool V_887 = true ;
if ( V_2 -> V_101 & V_330 )
V_886 = V_888 / 10 ;
else
V_886 = V_888 * 2 ;
#ifdef F_326
if ( ! V_2 -> V_281 ||
( V_2 -> V_101 & V_330 ) )
goto V_889;
F_412 ( V_2 ) ;
V_886 = V_888 / 50 ;
V_2 -> V_890 ++ ;
if ( V_2 -> V_890 >= 100 )
V_2 -> V_890 = 0 ;
else
V_887 = false ;
V_889:
#endif
F_294 ( & V_2 -> V_606 , V_886 + V_134 ) ;
if ( V_887 )
F_1 ( V_2 ) ;
}
static void F_415 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_115 & V_116 ) )
return;
V_2 -> V_115 &= ~ V_116 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_608 , & V_2 -> V_4 ) )
return;
F_28 ( V_2 ) ;
F_413 ( V_2 -> V_18 , L_115 ) ;
V_2 -> V_136 ++ ;
F_295 ( V_2 ) ;
}
static void F_416 ( struct V_891 * V_892 )
{
struct V_1 * V_2 = F_191 ( V_892 ,
struct V_1 ,
V_6 ) ;
F_415 ( V_2 ) ;
F_409 ( V_2 ) ;
F_411 ( V_2 ) ;
F_172 ( V_2 ) ;
F_408 ( V_2 ) ;
F_391 ( V_2 ) ;
F_393 ( V_2 ) ;
F_417 ( V_2 ) ;
F_5 ( V_2 ) ;
}
static int F_418 ( struct V_20 * V_21 ,
struct V_22 * V_893 ,
T_4 * V_223 )
{
struct V_158 * V_53 = V_893 -> V_53 ;
T_1 V_894 , V_895 ;
T_1 V_896 , V_897 ;
if ( ! F_419 ( V_53 ) )
return 0 ;
if ( F_420 ( V_53 ) ) {
int V_361 = F_421 ( V_53 , 0 , 0 , V_186 ) ;
if ( V_361 )
return V_361 ;
}
V_895 = V_898 ;
if ( V_893 -> V_206 == F_121 ( V_214 ) ) {
struct V_201 * V_899 = F_422 ( V_53 ) ;
V_899 -> V_900 = 0 ;
V_899 -> V_901 = 0 ;
F_423 ( V_53 ) -> V_901 = ~ F_424 ( V_899 -> V_902 ,
V_899 -> V_903 , 0 ,
V_219 ,
0 ) ;
V_895 |= V_904 ;
V_893 -> V_129 |= V_905 |
V_906 |
V_907 ;
} else if ( F_425 ( V_53 ) ) {
F_426 ( V_53 ) -> V_908 = 0 ;
F_423 ( V_53 ) -> V_901 =
~ F_427 ( & F_426 ( V_53 ) -> V_902 ,
& F_426 ( V_53 ) -> V_903 ,
0 , V_219 , 0 ) ;
V_893 -> V_129 |= V_905 |
V_906 ;
}
V_897 = F_428 ( V_53 ) ;
* V_223 = F_429 ( V_53 ) + V_897 ;
V_893 -> V_128 = F_125 ( V_53 ) -> V_128 ;
V_893 -> V_127 += ( V_893 -> V_128 - 1 ) * * V_223 ;
V_896 = V_897 << V_909 ;
V_896 |= F_125 ( V_53 ) -> V_224 << V_910 ;
V_896 |= 1 << V_911 ;
V_894 = F_430 ( V_53 ) ;
V_894 |= F_431 ( V_53 ) << V_912 ;
V_894 |= V_893 -> V_129 & V_913 ;
F_432 ( V_21 , V_894 , 0 , V_895 ,
V_896 ) ;
return 1 ;
}
static void F_433 ( struct V_20 * V_21 ,
struct V_22 * V_893 )
{
struct V_158 * V_53 = V_893 -> V_53 ;
T_1 V_894 = 0 ;
T_1 V_896 = 0 ;
T_1 V_895 = 0 ;
if ( V_53 -> V_181 != V_914 ) {
if ( ! ( V_893 -> V_129 & V_915 ) ) {
if ( F_70 ( V_53 -> V_916 ) )
V_893 -> V_129 |= V_917 ;
if ( ! ( V_893 -> V_129 & V_918 ) )
return;
}
} else {
T_4 V_919 = 0 ;
switch ( V_893 -> V_206 ) {
case F_121 ( V_214 ) :
V_894 |= F_430 ( V_53 ) ;
V_895 |= V_904 ;
V_919 = F_422 ( V_53 ) -> V_206 ;
break;
case F_121 ( V_216 ) :
V_894 |= F_430 ( V_53 ) ;
V_919 = F_426 ( V_53 ) -> V_207 ;
break;
default:
if ( F_70 ( F_434 () ) ) {
F_435 ( V_21 -> V_37 ,
L_116 ,
V_893 -> V_206 ) ;
}
break;
}
switch ( V_919 ) {
case V_219 :
V_895 |= V_898 ;
V_896 = F_428 ( V_53 ) <<
V_909 ;
break;
case V_920 :
V_895 |= V_921 ;
V_896 = sizeof( struct V_922 ) <<
V_909 ;
break;
case V_221 :
V_896 = sizeof( struct V_222 ) <<
V_909 ;
break;
default:
if ( F_70 ( F_434 () ) ) {
F_435 ( V_21 -> V_37 ,
L_117 ,
V_919 ) ;
}
break;
}
V_893 -> V_129 |= V_906 ;
}
V_894 |= F_431 ( V_53 ) << V_912 ;
V_894 |= V_893 -> V_129 & V_913 ;
F_432 ( V_21 , V_894 , 0 ,
V_895 , V_896 ) ;
}
static T_9 F_436 ( T_1 V_129 )
{
T_9 V_923 = F_69 ( V_924 |
V_925 ) ;
if ( V_129 & V_915 )
V_923 |= F_69 ( V_926 ) ;
if ( V_129 & V_130 )
V_923 |= F_69 ( V_927 ) ;
#ifdef F_122
if ( V_129 & ( V_905 | V_928 ) )
#else
if ( V_129 & V_905 )
#endif
V_923 |= F_69 ( V_929 ) ;
if ( ! ( V_129 & V_917 ) )
V_923 |= F_69 ( V_930 ) ;
return V_923 ;
}
static void F_437 ( union V_24 * V_25 ,
T_1 V_129 , unsigned int V_931 )
{
T_9 V_932 = F_69 ( V_931 << V_933 ) ;
if ( V_129 & V_906 )
V_932 |= F_69 ( V_934 ) ;
if ( V_129 & V_907 )
V_932 |= F_69 ( V_935 ) ;
#ifdef F_122
if ( V_129 & ( V_905 | V_936 ) )
#else
if ( V_129 & V_905 )
#endif
V_932 |= F_69 ( 1 << V_911 ) ;
#ifdef F_122
if ( V_129 & ( V_918 | V_936 ) )
#else
if ( V_129 & V_918 )
#endif
V_932 |= F_69 ( V_937 ) ;
V_25 -> V_192 . V_932 = V_932 ;
}
static void F_438 ( struct V_20 * V_21 ,
struct V_22 * V_893 ,
const T_4 V_223 )
{
T_7 V_45 ;
struct V_158 * V_53 = V_893 -> V_53 ;
struct V_22 * V_23 ;
union V_24 * V_25 ;
struct V_244 * V_245 = & F_125 ( V_53 ) -> V_246 [ 0 ] ;
unsigned int V_250 = V_53 -> V_250 ;
unsigned int V_259 = F_124 ( V_53 ) ;
unsigned int V_931 = V_53 -> V_46 - V_223 ;
T_1 V_129 = V_893 -> V_129 ;
T_9 V_923 ;
T_5 V_11 = V_21 -> V_44 ;
V_25 = F_35 ( V_21 , V_11 ) ;
F_437 ( V_25 , V_129 , V_931 ) ;
V_923 = F_436 ( V_129 ) ;
#ifdef F_122
if ( V_129 & V_936 ) {
if ( V_250 < sizeof( struct V_278 ) ) {
V_259 -= sizeof( struct V_278 ) - V_250 ;
V_250 = 0 ;
} else {
V_250 -= sizeof( struct V_278 ) ;
}
}
#endif
V_45 = F_439 ( V_21 -> V_37 , V_53 -> V_56 , V_259 , V_83 ) ;
if ( F_116 ( V_21 -> V_37 , V_45 ) )
goto V_938;
F_55 ( V_893 , V_46 , V_259 ) ;
F_440 ( V_893 , V_45 , V_45 ) ;
V_25 -> V_192 . V_939 = F_119 ( V_45 ) ;
for (; ; ) {
while ( F_70 ( V_259 > V_940 ) ) {
V_25 -> V_192 . V_941 =
V_923 | F_69 ( V_940 ) ;
V_11 ++ ;
V_25 ++ ;
if ( V_11 == V_21 -> V_52 ) {
V_25 = F_35 ( V_21 , 0 ) ;
V_11 = 0 ;
}
V_45 += V_940 ;
V_259 -= V_940 ;
V_25 -> V_192 . V_939 = F_119 ( V_45 ) ;
V_25 -> V_192 . V_932 = 0 ;
}
if ( F_73 ( ! V_250 ) )
break;
V_25 -> V_192 . V_941 = V_923 | F_69 ( V_259 ) ;
V_11 ++ ;
V_25 ++ ;
if ( V_11 == V_21 -> V_52 ) {
V_25 = F_35 ( V_21 , 0 ) ;
V_11 = 0 ;
}
#ifdef F_122
V_259 = F_322 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_259 = F_441 ( V_245 ) ;
#endif
V_250 -= V_259 ;
V_45 = F_442 ( V_21 -> V_37 , V_245 , 0 , V_259 ,
V_83 ) ;
if ( F_116 ( V_21 -> V_37 , V_45 ) )
goto V_938;
V_23 = & V_21 -> V_42 [ V_11 ] ;
F_55 ( V_23 , V_46 , V_259 ) ;
F_440 ( V_23 , V_45 , V_45 ) ;
V_25 -> V_192 . V_939 = F_119 ( V_45 ) ;
V_25 -> V_192 . V_932 = 0 ;
V_245 ++ ;
}
V_923 |= F_69 ( V_259 ) | F_69 ( V_942 ) ;
V_25 -> V_192 . V_941 = V_923 ;
F_443 ( F_81 ( V_21 ) , V_893 -> V_127 ) ;
V_893 -> V_48 = V_134 ;
F_109 () ;
V_893 -> V_47 = V_25 ;
V_11 ++ ;
if ( V_11 == V_21 -> V_52 )
V_11 = 0 ;
V_21 -> V_44 = V_11 ;
F_110 ( V_11 , V_21 -> V_109 ) ;
return;
V_938:
F_335 ( V_21 -> V_37 , L_118 ) ;
for (; ; ) {
V_23 = & V_21 -> V_42 [ V_11 ] ;
F_51 ( V_21 , V_23 ) ;
if ( V_23 == V_893 )
break;
if ( V_11 == 0 )
V_11 = V_21 -> V_52 ;
V_11 -- ;
}
V_21 -> V_44 = V_11 ;
}
static void F_444 ( struct V_20 * V_82 ,
struct V_22 * V_893 )
{
struct V_117 * V_118 = V_82 -> V_118 ;
union V_943 V_944 = { . V_945 = 0 } ;
union V_943 V_946 = { . V_945 = 0 } ;
union {
unsigned char * V_196 ;
struct V_201 * V_202 ;
struct V_203 * V_204 ;
} V_205 ;
struct V_220 * V_947 ;
T_8 V_948 ;
if ( ! V_118 )
return;
if ( ! V_82 -> V_379 )
return;
V_82 -> V_380 ++ ;
V_205 . V_196 = F_445 ( V_893 -> V_53 ) ;
if ( ( V_893 -> V_206 != F_121 ( V_216 ) ||
V_205 . V_204 -> V_207 != V_219 ) &&
( V_893 -> V_206 != F_121 ( V_214 ) ||
V_205 . V_202 -> V_206 != V_219 ) )
return;
V_947 = F_423 ( V_893 -> V_53 ) ;
if ( ! V_947 || V_947 -> V_949 )
return;
if ( ! V_947 -> V_950 && ( V_82 -> V_380 < V_82 -> V_379 ) )
return;
V_82 -> V_380 = 0 ;
V_948 = F_446 ( V_893 -> V_129 >> V_951 ) ;
V_944 . V_952 . V_948 = V_948 ;
if ( V_893 -> V_129 & ( V_953 | V_915 ) )
V_946 . V_954 . V_955 ^= V_947 -> V_956 ^ F_121 ( V_211 ) ;
else
V_946 . V_954 . V_955 ^= V_947 -> V_956 ^ V_893 -> V_206 ;
V_946 . V_954 . V_957 ^= V_947 -> V_958 ;
if ( V_893 -> V_206 == F_121 ( V_214 ) ) {
V_944 . V_952 . V_959 = V_960 ;
V_946 . V_961 ^= V_205 . V_202 -> V_902 ^ V_205 . V_202 -> V_903 ;
} else {
V_944 . V_952 . V_959 = V_962 ;
V_946 . V_961 ^= V_205 . V_204 -> V_902 . V_963 [ 0 ] ^
V_205 . V_204 -> V_902 . V_963 [ 1 ] ^
V_205 . V_204 -> V_902 . V_963 [ 2 ] ^
V_205 . V_204 -> V_902 . V_963 [ 3 ] ^
V_205 . V_204 -> V_903 . V_963 [ 0 ] ^
V_205 . V_204 -> V_903 . V_963 [ 1 ] ^
V_205 . V_204 -> V_903 . V_963 [ 2 ] ^
V_205 . V_204 -> V_903 . V_963 [ 3 ] ;
}
F_447 ( & V_118 -> V_2 -> V_8 ,
V_944 , V_946 , V_82 -> V_50 ) ;
}
static int F_448 ( struct V_20 * V_21 , T_5 V_259 )
{
F_78 ( V_21 -> V_18 , V_21 -> V_50 ) ;
F_85 () ;
if ( F_73 ( F_84 ( V_21 ) < V_259 ) )
return - V_691 ;
F_449 ( V_21 -> V_18 , V_21 -> V_50 ) ;
++ V_21 -> V_112 . V_137 ;
return 0 ;
}
static inline int F_450 ( struct V_20 * V_21 , T_5 V_259 )
{
if ( F_73 ( F_84 ( V_21 ) >= V_259 ) )
return 0 ;
return F_448 ( V_21 , V_259 ) ;
}
static T_5 F_451 ( struct V_17 * V_37 , struct V_158 * V_53 )
{
struct V_1 * V_2 = F_63 ( V_37 ) ;
int V_964 = F_452 ( V_53 ) ? F_453 ( V_53 ) :
F_454 () ;
#ifdef F_122
T_8 V_206 = F_455 ( V_53 ) ;
if ( ( ( V_206 == F_446 ( V_217 ) ) ||
( V_206 == F_446 ( V_965 ) ) ) &&
( V_2 -> V_101 & V_475 ) ) {
struct V_966 * V_967 ;
V_967 = & V_2 -> V_393 [ V_968 ] ;
while ( V_964 >= V_967 -> V_395 )
V_964 -= V_967 -> V_395 ;
V_964 += V_2 -> V_393 [ V_968 ] . V_969 ;
return V_964 ;
}
#endif
if ( V_2 -> V_101 & V_343 ) {
while ( F_70 ( V_964 >= V_37 -> V_970 ) )
V_964 -= V_37 -> V_970 ;
return V_964 ;
}
return F_456 ( V_37 , V_53 ) ;
}
T_13 F_457 ( struct V_158 * V_53 ,
struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_22 * V_893 ;
int V_971 ;
T_1 V_129 = 0 ;
#if V_261 > V_940
unsigned short V_967 ;
#endif
T_5 V_52 = F_458 ( F_124 ( V_53 ) ) ;
T_8 V_206 = V_53 -> V_206 ;
T_4 V_223 = 0 ;
#if V_261 > V_940
for ( V_967 = 0 ; V_967 < F_125 ( V_53 ) -> V_265 ; V_967 ++ )
V_52 += F_458 ( F_125 ( V_53 ) -> V_246 [ V_967 ] . V_259 ) ;
#else
V_52 += F_125 ( V_53 ) -> V_265 ;
#endif
if ( F_450 ( V_21 , V_52 + 3 ) ) {
V_21 -> V_112 . V_717 ++ ;
return V_972 ;
}
V_893 = & V_21 -> V_42 [ V_21 -> V_44 ] ;
V_893 -> V_53 = V_53 ;
V_893 -> V_127 = V_53 -> V_46 ;
V_893 -> V_128 = 1 ;
if ( F_459 ( V_53 ) ) {
V_129 |= F_460 ( V_53 ) << V_951 ;
V_129 |= V_915 ;
} else if ( V_206 == F_121 ( V_211 ) ) {
struct V_199 * V_973 , V_974 ;
V_973 = F_461 ( V_53 , V_209 , sizeof( V_974 ) , & V_974 ) ;
if ( ! V_973 )
goto V_975;
V_206 = V_973 -> V_213 ;
V_129 |= F_462 ( V_973 -> V_976 ) <<
V_951 ;
V_129 |= V_953 ;
}
F_463 ( V_53 ) ;
if ( F_70 ( F_125 ( V_53 ) -> V_129 & V_977 ) ) {
F_125 ( V_53 ) -> V_129 |= V_978 ;
V_129 |= V_130 ;
}
#ifdef F_326
if ( V_2 -> V_101 & V_388 )
V_129 |= V_918 ;
#endif
if ( ( V_2 -> V_101 & V_102 ) &&
( ( V_129 & ( V_915 | V_953 ) ) ||
( V_53 -> V_979 != V_980 ) ) ) {
V_129 &= ~ V_981 ;
V_129 |= ( V_53 -> V_979 & 0x7 ) <<
V_982 ;
if ( V_129 & V_953 ) {
struct V_983 * V_973 ;
if ( F_420 ( V_53 ) &&
F_421 ( V_53 , 0 , 0 , V_186 ) )
goto V_975;
V_973 = (struct V_983 * ) V_53 -> V_56 ;
V_973 -> V_976 = F_446 ( V_129 >>
V_951 ) ;
} else {
V_129 |= V_915 ;
}
}
V_893 -> V_129 = V_129 ;
V_893 -> V_206 = V_206 ;
#ifdef F_122
if ( ( V_206 == F_121 ( V_217 ) ) &&
( V_21 -> V_18 -> V_159 & ( V_984 | V_985 ) ) ) {
V_971 = F_464 ( V_21 , V_893 , & V_223 ) ;
if ( V_971 < 0 )
goto V_975;
goto V_986;
}
#endif
V_971 = F_418 ( V_21 , V_893 , & V_223 ) ;
if ( V_971 < 0 )
goto V_975;
else if ( ! V_971 )
F_433 ( V_21 , V_893 ) ;
if ( F_2 ( V_352 , & V_21 -> V_4 ) )
F_444 ( V_21 , V_893 ) ;
#ifdef F_122
V_986:
#endif
F_438 ( V_21 , V_893 , V_223 ) ;
F_450 ( V_21 , V_987 ) ;
return V_988 ;
V_975:
F_52 ( V_893 -> V_53 ) ;
V_893 -> V_53 = NULL ;
return V_988 ;
}
static T_13 F_465 ( struct V_158 * V_53 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
struct V_20 * V_21 ;
if ( F_70 ( V_53 -> V_46 < 17 ) ) {
if ( F_149 ( V_53 , 17 - V_53 -> V_46 ) )
return V_988 ;
V_53 -> V_46 = 17 ;
F_466 ( V_53 , 17 ) ;
}
V_21 = V_2 -> V_21 [ V_53 -> V_989 ] ;
return F_457 ( V_53 , V_2 , V_21 ) ;
}
static int F_467 ( struct V_17 * V_18 , void * V_441 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_990 * V_512 = V_441 ;
if ( ! F_468 ( V_512 -> V_991 ) )
return - V_992 ;
memcpy ( V_18 -> V_993 , V_512 -> V_991 , V_18 -> V_994 ) ;
memcpy ( V_8 -> V_72 . V_512 , V_512 -> V_991 , V_18 -> V_994 ) ;
V_8 -> V_72 . V_315 . V_511 ( V_8 , 0 , V_8 -> V_72 . V_512 , F_227 ( 0 ) , V_513 ) ;
return 0 ;
}
static int
F_469 ( struct V_17 * V_18 , int V_995 , int V_996 , T_5 V_512 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_5 V_997 ;
int V_998 ;
if ( V_995 != V_8 -> V_319 . V_999 . V_995 )
return - V_688 ;
V_998 = V_8 -> V_319 . V_315 . V_1000 ( V_8 , V_512 , V_996 , & V_997 ) ;
if ( ! V_998 )
V_998 = V_997 ;
return V_998 ;
}
static int F_470 ( struct V_17 * V_18 , int V_995 , int V_996 ,
T_5 V_512 , T_5 V_997 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( V_995 != V_8 -> V_319 . V_999 . V_995 )
return - V_688 ;
return V_8 -> V_319 . V_315 . V_1001 ( V_8 , V_512 , V_996 , V_997 ) ;
}
static int F_471 ( struct V_17 * V_18 , struct V_1002 * V_1003 , int V_1004 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
switch ( V_1004 ) {
case V_1005 :
return F_472 ( V_2 , V_1003 , V_1004 ) ;
default:
return F_473 ( & V_2 -> V_8 . V_319 . V_999 , F_474 ( V_1003 ) , V_1004 ) ;
}
}
static int F_475 ( struct V_17 * V_37 )
{
int V_361 = 0 ;
struct V_1 * V_2 = F_63 ( V_37 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( F_468 ( V_8 -> V_72 . V_1006 ) ) {
F_361 () ;
V_361 = F_476 ( V_37 , V_8 -> V_72 . V_1006 , V_1007 ) ;
F_363 () ;
V_8 -> V_72 . V_315 . V_616 ( V_8 , F_227 ( 0 ) ) ;
}
return V_361 ;
}
static int F_477 ( struct V_17 * V_37 )
{
int V_361 = 0 ;
struct V_1 * V_2 = F_63 ( V_37 ) ;
struct V_1008 * V_72 = & V_2 -> V_8 . V_72 ;
if ( F_468 ( V_72 -> V_1006 ) ) {
F_361 () ;
V_361 = F_478 ( V_37 , V_72 -> V_1006 , V_1007 ) ;
F_363 () ;
}
return V_361 ;
}
static void F_479 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
int V_11 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
V_2 -> V_101 |= V_233 ;
if ( V_2 -> V_101 & V_369 ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_152 ; V_11 ++ )
F_188 ( 0 , V_2 -> V_118 [ V_11 ] ) ;
} else {
F_200 ( V_2 -> V_36 -> V_346 , V_18 ) ;
}
V_2 -> V_101 &= ~ V_233 ;
}
static struct V_1009 * F_480 ( struct V_17 * V_18 ,
struct V_1009 * V_86 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
int V_11 ;
F_481 () ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
struct V_20 * V_82 = F_482 ( V_2 -> V_30 [ V_11 ] ) ;
T_2 V_132 , V_106 ;
unsigned int V_1010 ;
if ( V_82 ) {
do {
V_1010 = F_483 ( & V_82 -> V_131 ) ;
V_106 = V_82 -> V_86 . V_106 ;
V_132 = V_82 -> V_86 . V_132 ;
} while ( F_484 ( & V_82 -> V_131 , V_1010 ) );
V_86 -> V_722 += V_106 ;
V_86 -> V_721 += V_132 ;
}
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_82 = F_482 ( V_2 -> V_21 [ V_11 ] ) ;
T_2 V_132 , V_106 ;
unsigned int V_1010 ;
if ( V_82 ) {
do {
V_1010 = F_483 ( & V_82 -> V_131 ) ;
V_106 = V_82 -> V_86 . V_106 ;
V_132 = V_82 -> V_86 . V_132 ;
} while ( F_484 ( & V_82 -> V_131 , V_1010 ) );
V_86 -> V_724 += V_106 ;
V_86 -> V_723 += V_132 ;
}
}
F_485 () ;
V_86 -> V_831 = V_18 -> V_86 . V_831 ;
V_86 -> V_832 = V_18 -> V_86 . V_832 ;
V_86 -> V_834 = V_18 -> V_86 . V_834 ;
V_86 -> V_835 = V_18 -> V_86 . V_835 ;
V_86 -> V_836 = V_18 -> V_86 . V_836 ;
return V_86 ;
}
static void F_486 ( struct V_1 * V_2 , T_4 V_96 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_1011 , V_1012 ;
int V_11 ;
if ( V_8 -> V_72 . type == V_73 )
return;
V_1011 = F_11 ( V_8 , V_1013 ) ;
V_1012 = V_1011 ;
for ( V_11 = 0 ; V_11 < V_655 ; V_11 ++ ) {
T_4 V_1014 = V_1011 >> ( V_11 * V_1015 ) ;
if ( V_1014 > V_96 )
V_1011 &= ~ ( 0x7 << V_1015 ) ;
}
if ( V_1011 != V_1012 )
F_45 ( V_8 , V_1013 , V_1011 ) ;
return;
}
static void F_487 ( struct V_1 * V_2 )
{
struct V_17 * V_37 = V_2 -> V_18 ;
struct V_1016 * V_98 = & V_2 -> V_98 ;
struct V_1017 * V_1018 = V_2 -> V_540 ;
T_4 V_1019 ;
for ( V_1019 = 0 ; V_1019 < V_1020 ; V_1019 ++ ) {
T_4 V_96 = 0 ;
if ( V_2 -> V_536 & V_537 )
V_96 = F_488 ( V_98 , 0 , V_1019 ) ;
else if ( V_1018 )
V_96 = V_1018 -> V_541 [ V_1019 ] ;
F_489 ( V_37 , V_1019 , V_96 ) ;
}
}
int F_490 ( struct V_17 * V_37 , T_4 V_96 )
{
struct V_1 * V_2 = F_63 ( V_37 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( V_96 > V_2 -> V_98 . V_651 . V_652 ||
( V_8 -> V_72 . type == V_73 &&
V_96 < V_655 ) )
return - V_688 ;
if ( F_31 ( V_37 ) )
F_351 ( V_37 ) ;
F_368 ( V_2 ) ;
if ( V_96 ) {
F_491 ( V_37 , V_96 ) ;
F_487 ( V_2 ) ;
V_2 -> V_101 |= V_102 ;
if ( V_2 -> V_8 . V_72 . type == V_73 ) {
V_2 -> V_1021 = V_2 -> V_8 . V_87 . V_667 ;
V_2 -> V_8 . V_87 . V_667 = V_1022 ;
}
} else {
F_492 ( V_37 ) ;
if ( V_2 -> V_8 . V_72 . type == V_73 )
V_2 -> V_8 . V_87 . V_667 = V_2 -> V_1021 ;
V_2 -> V_101 &= ~ V_102 ;
V_2 -> V_666 . V_99 = false ;
V_2 -> V_98 . V_99 = false ;
}
F_362 ( V_2 ) ;
F_486 ( V_2 , V_96 ) ;
if ( F_31 ( V_37 ) )
F_347 ( V_37 ) ;
return 0 ;
}
void F_493 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
if ( F_31 ( V_18 ) )
F_295 ( V_2 ) ;
else
F_301 ( V_2 ) ;
}
static T_14 F_494 ( struct V_17 * V_18 ,
T_14 V_159 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
if ( ! ( V_159 & V_172 ) )
V_159 &= ~ V_1023 ;
if ( ! ( V_2 -> V_115 & V_642 ) )
V_159 &= ~ V_1023 ;
return V_159 ;
}
static int F_495 ( struct V_17 * V_18 ,
T_14 V_159 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
T_14 V_1024 = V_18 -> V_159 ^ V_159 ;
bool V_1025 = false ;
if ( ! ( V_159 & V_1023 ) ) {
if ( V_2 -> V_115 & V_483 )
V_1025 = true ;
V_2 -> V_115 &= ~ V_483 ;
} else if ( ( V_2 -> V_115 & V_642 ) &&
! ( V_2 -> V_115 & V_483 ) ) {
if ( V_2 -> V_359 == 1 ||
V_2 -> V_359 > V_1026 ) {
V_2 -> V_115 |= V_483 ;
V_1025 = true ;
} else if ( ( V_1024 ^ V_159 ) & V_1023 ) {
F_79 ( V_135 , L_119
L_120 ) ;
}
}
switch ( V_159 & V_1027 ) {
case V_1027 :
if ( ! ( V_2 -> V_101 & V_554 ) )
V_1025 = true ;
V_2 -> V_101 &= ~ V_343 ;
V_2 -> V_101 |= V_554 ;
break;
default:
if ( V_2 -> V_101 & V_554 )
V_1025 = true ;
V_2 -> V_101 &= ~ V_554 ;
if ( V_2 -> V_101 & V_388 )
break;
if ( F_211 ( V_18 ) > 1 )
break;
if ( V_2 -> V_393 [ V_394 ] . V_635 <= 1 )
break;
if ( ! V_2 -> V_379 )
break;
V_2 -> V_101 |= V_343 ;
break;
}
if ( V_159 & V_230 )
F_242 ( V_2 ) ;
else
F_241 ( V_2 ) ;
if ( V_1024 & V_253 )
V_1025 = true ;
V_18 -> V_159 = V_159 ;
if ( V_1025 )
F_493 ( V_18 ) ;
return 0 ;
}
static int F_496 ( struct V_1028 * V_1029 , struct V_1030 * V_1031 [] ,
struct V_17 * V_37 ,
const unsigned char * V_512 ,
T_5 V_101 )
{
struct V_1 * V_2 = F_63 ( V_37 ) ;
int V_361 ;
if ( ! ( V_2 -> V_101 & V_388 ) )
return - V_1032 ;
if ( V_1029 -> V_1033 && ! ( V_1029 -> V_1033 & V_1034 ) ) {
F_25 ( L_121 ,
V_1035 ) ;
return - V_688 ;
}
if ( F_497 ( V_512 ) || F_498 ( V_512 ) ) {
T_1 V_1036 = V_507 ;
if ( F_246 ( V_37 ) < V_1036 )
V_361 = F_499 ( V_37 , V_512 ) ;
else
V_361 = - V_508 ;
} else if ( F_500 ( V_512 ) ) {
V_361 = F_501 ( V_37 , V_512 ) ;
} else {
V_361 = - V_688 ;
}
if ( V_361 == - V_1037 && ! ( V_101 & V_1038 ) )
V_361 = 0 ;
return V_361 ;
}
static int F_502 ( struct V_1028 * V_1029 ,
struct V_17 * V_37 ,
const unsigned char * V_512 )
{
struct V_1 * V_2 = F_63 ( V_37 ) ;
int V_361 = - V_1032 ;
if ( V_1029 -> V_1033 & V_1034 ) {
F_25 ( L_121 ,
V_1035 ) ;
return - V_688 ;
}
if ( V_2 -> V_101 & V_388 ) {
if ( F_497 ( V_512 ) )
V_361 = F_503 ( V_37 , V_512 ) ;
else if ( F_500 ( V_512 ) )
V_361 = F_504 ( V_37 , V_512 ) ;
else
V_361 = - V_688 ;
}
return V_361 ;
}
static int F_505 ( struct V_158 * V_53 ,
struct V_1039 * V_1040 ,
struct V_17 * V_37 ,
int V_1041 )
{
struct V_1 * V_2 = F_63 ( V_37 ) ;
if ( V_2 -> V_101 & V_388 )
V_1041 = F_506 ( V_53 , V_1040 , V_37 , V_1041 ) ;
return V_1041 ;
}
static int F_507 ( struct V_17 * V_37 ,
struct V_1042 * V_1043 )
{
struct V_1 * V_2 = F_63 ( V_37 ) ;
struct V_1030 * V_1044 , * V_1045 ;
int V_1046 ;
if ( ! ( V_2 -> V_101 & V_388 ) )
return - V_1032 ;
V_1045 = F_508 ( V_1043 , sizeof( struct V_1047 ) , V_1048 ) ;
F_509 (attr, br_spec, rem) {
T_15 V_1049 ;
T_1 V_1011 = 0 ;
if ( F_510 ( V_1044 ) != V_1050 )
continue;
V_1049 = F_511 ( V_1044 ) ;
if ( V_1049 == V_1051 ) {
V_1011 = 0 ;
V_2 -> V_115 &= ~ V_457 ;
} else if ( V_1049 == V_1052 ) {
V_1011 = V_459 ;
V_2 -> V_115 |= V_457 ;
} else
return - V_688 ;
F_45 ( & V_2 -> V_8 , V_458 , V_1011 ) ;
F_79 ( V_133 , L_122 ,
V_1049 == V_1051 ? L_123 : L_124 ) ;
}
return 0 ;
}
static int F_512 ( struct V_158 * V_53 , T_1 V_1053 , T_1 V_1054 ,
struct V_17 * V_37 )
{
struct V_1 * V_2 = F_63 ( V_37 ) ;
T_5 V_1049 ;
if ( ! ( V_2 -> V_101 & V_388 ) )
return 0 ;
if ( V_2 -> V_115 & V_457 )
V_1049 = V_1052 ;
else
V_1049 = V_1051 ;
return F_513 ( V_53 , V_1053 , V_1054 , V_37 , V_1049 ) ;
}
int F_514 ( struct V_1 * V_2 , T_5 V_311 ,
T_5 V_1055 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_5 V_1056 = V_2 -> V_1057 & V_1058 ;
int V_1059 = 0 ;
switch ( V_311 ) {
case V_1060 :
switch ( V_1055 ) {
case V_1061 :
if ( V_8 -> V_1062 . V_1063 != 0 )
break;
case V_1064 :
case V_1065 :
case V_1066 :
V_1059 = 1 ;
break;
}
break;
case V_1067 :
if ( V_1055 != V_1068 )
V_1059 = 1 ;
break;
case V_1069 :
V_1059 = 1 ;
break;
case V_1070 :
case V_1071 :
if ( ( V_1056 == V_1072 ) ||
( ( V_1056 == V_1073 ) &&
( V_8 -> V_1062 . V_1063 == 0 ) ) ) {
V_1059 = 1 ;
}
break;
}
return V_1059 ;
}
static int F_515 ( struct V_623 * V_36 , const struct V_1074 * V_1075 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 = NULL ;
struct V_7 * V_8 ;
const struct V_1076 * V_1077 = V_1078 [ V_1075 -> V_1079 ] ;
static int V_1080 ;
int V_11 , V_361 , V_1081 ;
T_4 V_1082 [ V_1083 ] ;
unsigned int V_395 = F_516 () ;
unsigned int V_1084 = 0 ;
#ifdef F_122
T_5 V_1085 ;
#endif
T_1 V_1086 ;
if ( V_36 -> V_1087 ) {
F_517 ( 1 , V_1088 L_125 ,
F_518 ( V_36 ) , V_36 -> V_627 , V_36 -> V_153 ) ;
return - V_688 ;
}
V_361 = F_358 ( V_36 ) ;
if ( V_361 )
return V_361 ;
if ( ! F_519 ( & V_36 -> V_37 , F_207 ( 64 ) ) &&
! F_520 ( & V_36 -> V_37 , F_207 ( 64 ) ) ) {
V_1081 = 1 ;
} else {
V_361 = F_519 ( & V_36 -> V_37 , F_207 ( 32 ) ) ;
if ( V_361 ) {
V_361 = F_520 ( & V_36 -> V_37 ,
F_207 ( 32 ) ) ;
if ( V_361 ) {
F_335 ( & V_36 -> V_37 ,
L_126 ) ;
goto V_1089;
}
}
V_1081 = 0 ;
}
V_361 = F_521 ( V_36 , F_522 ( V_36 ,
V_1090 ) , V_1035 ) ;
if ( V_361 ) {
F_335 ( & V_36 -> V_37 ,
L_127 , V_361 ) ;
goto V_1091;
}
F_523 ( V_36 ) ;
F_359 ( V_36 ) ;
F_357 ( V_36 ) ;
#ifdef F_283
if ( V_1077 -> V_72 == V_73 )
V_1084 = F_322 (unsigned int, indices * MAX_TRAFFIC_CLASS,
IXGBE_MAX_RSS_INDICES) ;
else
V_1084 = F_322 (unsigned int, indices * MAX_TRAFFIC_CLASS,
IXGBE_MAX_FDIR_INDICES) ;
#endif
if ( V_1077 -> V_72 == V_73 )
V_395 = F_322 (unsigned int, indices, IXGBE_MAX_RSS_INDICES) ;
else
V_395 = F_322 (unsigned int, indices, IXGBE_MAX_FDIR_INDICES) ;
#ifdef F_122
V_395 += F_322 (unsigned int, num_possible_cpus(),
IXGBE_MAX_FCOE_INDICES) ;
#endif
V_395 = F_524 (unsigned int, dcb_max, indices) ;
V_18 = F_525 ( sizeof( struct V_1 ) , V_395 ) ;
if ( ! V_18 ) {
V_361 = - V_508 ;
goto V_1092;
}
F_526 ( V_18 , & V_36 -> V_37 ) ;
V_2 = F_63 ( V_18 ) ;
F_527 ( V_36 , V_2 ) ;
V_2 -> V_18 = V_18 ;
V_2 -> V_36 = V_36 ;
V_8 = & V_2 -> V_8 ;
V_8 -> V_1093 = V_2 ;
V_2 -> V_1094 = F_528 ( V_1095 , V_1096 ) ;
V_8 -> V_378 = F_529 ( F_530 ( V_36 , 0 ) ,
F_531 ( V_36 , 0 ) ) ;
if ( ! V_8 -> V_378 ) {
V_361 = - V_680 ;
goto V_1097;
}
V_18 -> V_1098 = & V_1099 ;
F_532 ( V_18 ) ;
V_18 -> V_1100 = 5 * V_888 ;
strncpy ( V_18 -> V_16 , F_518 ( V_36 ) , sizeof( V_18 -> V_16 ) - 1 ) ;
V_2 -> V_1101 = V_1080 ;
memcpy ( & V_8 -> V_72 . V_315 , V_1077 -> V_1102 , sizeof( V_8 -> V_72 . V_315 ) ) ;
V_8 -> V_72 . type = V_1077 -> V_72 ;
memcpy ( & V_8 -> V_1103 . V_315 , V_1077 -> V_1104 , sizeof( V_8 -> V_1103 . V_315 ) ) ;
V_1086 = F_11 ( V_8 , V_1105 ) ;
if ( ! ( V_1086 & ( 1 << 8 ) ) )
V_8 -> V_1103 . V_315 . V_192 = & V_1106 ;
memcpy ( & V_8 -> V_319 . V_315 , V_1077 -> V_1107 , sizeof( V_8 -> V_319 . V_315 ) ) ;
V_8 -> V_319 . V_874 = V_1108 ;
V_8 -> V_319 . V_999 . V_995 = V_1109 ;
V_8 -> V_319 . V_999 . V_1110 = 0 ;
V_8 -> V_319 . V_999 . V_1111 = V_1112 | V_1113 ;
V_8 -> V_319 . V_999 . V_37 = V_18 ;
V_8 -> V_319 . V_999 . V_1114 = F_469 ;
V_8 -> V_319 . V_999 . V_1115 = F_470 ;
V_1077 -> V_1116 ( V_8 ) ;
V_361 = F_321 ( V_2 ) ;
if ( V_361 )
goto V_1117;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
case V_76 :
F_45 ( & V_2 -> V_8 , V_695 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_101 & V_322 ) {
T_1 V_603 = F_11 ( V_8 , V_604 ) ;
if ( V_603 & V_605 )
F_173 ( V_135 , L_59 ) ;
}
if ( V_1118 )
V_8 -> V_1118 = V_1118 ;
V_8 -> V_319 . V_1119 = true ;
V_361 = V_8 -> V_72 . V_315 . V_1120 ( V_8 ) ;
V_8 -> V_319 . V_1119 = false ;
if ( V_361 == V_611 &&
V_8 -> V_72 . type == V_73 ) {
V_361 = 0 ;
} else if ( V_361 == V_612 ) {
F_302 ( L_128
L_129 ) ;
F_302 ( L_130
L_131 ) ;
goto V_1117;
} else if ( V_361 ) {
F_302 ( L_132 , V_361 ) ;
goto V_1117;
}
#ifdef F_326
F_533 ( V_2 , V_1077 ) ;
#endif
V_18 -> V_159 = V_1121 |
V_1122 |
V_1123 |
V_1124 |
V_230 |
V_1125 |
V_1126 |
V_1127 |
V_160 |
V_172 ;
V_18 -> V_1128 = V_18 -> V_159 ;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
case V_76 :
V_18 -> V_159 |= V_1129 ;
V_18 -> V_1128 |= V_1129 |
V_1027 ;
break;
default:
break;
}
V_18 -> V_1128 |= V_253 ;
V_18 -> V_1130 |= V_1126 ;
V_18 -> V_1130 |= V_1127 ;
V_18 -> V_1130 |= V_1122 ;
V_18 -> V_1130 |= V_1123 ;
V_18 -> V_1130 |= V_1121 ;
V_18 -> V_1131 |= V_1132 ;
V_18 -> V_1131 |= V_1133 ;
#ifdef F_283
V_18 -> V_1134 = & V_1134 ;
#endif
#ifdef F_122
if ( V_2 -> V_101 & V_646 ) {
if ( V_8 -> V_72 . V_315 . V_1135 ) {
V_8 -> V_72 . V_315 . V_1135 ( V_8 , & V_1085 ) ;
if ( V_1085 & V_1136 )
V_2 -> V_101 &= ~ V_646 ;
}
V_2 -> V_393 [ V_968 ] . V_635 = V_1137 ;
V_18 -> V_159 |= V_984 |
V_985 ;
V_18 -> V_1130 |= V_984 |
V_985 |
V_535 ;
}
#endif
if ( V_1081 ) {
V_18 -> V_159 |= V_1138 ;
V_18 -> V_1130 |= V_1138 ;
}
if ( V_2 -> V_115 & V_642 )
V_18 -> V_1128 |= V_1023 ;
if ( V_2 -> V_115 & V_483 )
V_18 -> V_159 |= V_1023 ;
if ( V_8 -> V_1103 . V_315 . V_1139 ( V_8 , NULL ) < 0 ) {
F_302 ( L_133 ) ;
V_361 = - V_680 ;
goto V_1117;
}
memcpy ( V_18 -> V_993 , V_8 -> V_72 . V_1140 , V_18 -> V_994 ) ;
memcpy ( V_18 -> V_1140 , V_8 -> V_72 . V_1140 , V_18 -> V_994 ) ;
if ( ! F_468 ( V_18 -> V_1140 ) ) {
F_302 ( L_134 ) ;
V_361 = - V_680 ;
goto V_1117;
}
F_534 ( & V_2 -> V_606 , & F_414 ,
( unsigned long ) V_2 ) ;
F_535 ( & V_2 -> V_6 , F_416 ) ;
F_8 ( V_5 , & V_2 -> V_4 ) ;
V_361 = F_362 ( V_2 ) ;
if ( V_361 )
goto V_1117;
V_2 -> V_699 = 0 ;
V_8 -> V_1103 . V_315 . V_192 ( V_8 , 0x2c , & V_2 -> V_1057 ) ;
if ( F_514 ( V_2 , V_36 -> V_153 , V_36 -> V_633 ) )
V_2 -> V_699 = V_1141 ;
F_536 ( & V_2 -> V_36 -> V_37 , V_2 -> V_699 ) ;
V_8 -> V_1103 . V_315 . V_192 ( V_8 , 0x2e , & V_2 -> V_1142 ) ;
V_8 -> V_1103 . V_315 . V_192 ( V_8 , 0x2d , & V_2 -> V_1143 ) ;
V_8 -> V_72 . V_315 . V_1144 ( V_8 ) ;
F_537 ( L_135 ,
( V_8 -> V_1062 . V_1145 == V_1146 ? L_136 :
V_8 -> V_1062 . V_1145 == V_1147 ? L_137 :
L_138 ) ,
( V_8 -> V_1062 . V_1148 == V_1149 ? L_139 :
V_8 -> V_1062 . V_1148 == V_1150 ? L_140 :
V_8 -> V_1062 . V_1148 == V_1151 ? L_141 :
L_138 ) ,
V_18 -> V_993 ) ;
V_361 = F_538 ( V_8 , V_1082 , V_1083 ) ;
if ( V_361 )
strncpy ( V_1082 , L_138 , V_1083 ) ;
if ( F_287 ( V_8 ) && V_8 -> V_319 . V_874 != V_1152 )
F_537 ( L_142 ,
V_8 -> V_72 . type , V_8 -> V_319 . type , V_8 -> V_319 . V_874 ,
V_1082 ) ;
else
F_537 ( L_143 ,
V_8 -> V_72 . type , V_8 -> V_319 . type , V_1082 ) ;
if ( V_8 -> V_1062 . V_1148 <= V_1150 ) {
F_303 ( L_144
L_145 ) ;
F_303 ( L_146
L_147 ) ;
}
V_361 = V_8 -> V_72 . V_315 . V_1153 ( V_8 ) ;
if ( V_361 == V_614 ) {
F_303 ( L_81
L_148
L_149
L_150
L_85
L_86 ) ;
}
strcpy ( V_18 -> V_16 , L_151 ) ;
V_361 = F_539 ( V_18 ) ;
if ( V_361 )
goto V_1154;
if ( V_8 -> V_72 . V_315 . V_622 )
V_8 -> V_72 . V_315 . V_622 ( V_8 ) ;
F_314 ( V_18 ) ;
#ifdef F_192
if ( F_100 ( & V_36 -> V_37 ) == 0 ) {
V_2 -> V_101 |= V_150 ;
F_97 ( V_2 ) ;
}
#endif
if ( V_2 -> V_101 & V_388 ) {
F_79 ( V_135 , L_152 , V_2 -> V_281 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_281 ; V_11 ++ )
F_540 ( V_36 , ( V_11 | 0x10000000 ) ) ;
}
if ( V_8 -> V_72 . V_315 . V_1155 )
V_8 -> V_72 . V_315 . V_1155 ( V_8 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_475 ( V_18 ) ;
F_537 ( L_153 , V_1156 ) ;
V_1080 ++ ;
#ifdef F_541
if ( F_542 ( V_2 ) )
F_77 ( V_135 , L_154 ) ;
#endif
#ifdef F_543
F_544 ( V_2 ) ;
#endif
return 0 ;
V_1154:
F_44 ( V_2 ) ;
F_368 ( V_2 ) ;
V_1117:
F_545 ( V_2 ) ;
V_2 -> V_115 &= ~ V_580 ;
F_546 ( V_8 -> V_378 ) ;
V_1097:
F_547 ( V_18 ) ;
V_1092:
F_548 ( V_36 ,
F_522 ( V_36 , V_1090 ) ) ;
V_1091:
V_1089:
F_369 ( V_36 ) ;
return V_361 ;
}
static void F_549 ( struct V_623 * V_36 )
{
struct V_1 * V_2 = F_354 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
#ifdef F_543
F_550 ( V_2 ) ;
#endif
F_208 ( V_3 , & V_2 -> V_4 ) ;
F_551 ( & V_2 -> V_6 ) ;
#ifdef F_192
if ( V_2 -> V_101 & V_150 ) {
V_2 -> V_101 &= ~ V_150 ;
F_101 ( & V_36 -> V_37 ) ;
F_45 ( & V_2 -> V_8 , V_151 , 1 ) ;
}
#endif
#ifdef F_541
F_552 ( V_2 ) ;
#endif
F_477 ( V_18 ) ;
if ( V_18 -> V_875 == V_876 )
F_410 ( V_18 ) ;
F_545 ( V_2 ) ;
F_368 ( V_2 ) ;
F_44 ( V_2 ) ;
#ifdef F_553
F_199 ( V_2 -> V_100 ) ;
F_199 ( V_2 -> V_540 ) ;
#endif
F_546 ( V_2 -> V_8 . V_378 ) ;
F_548 ( V_36 , F_522 ( V_36 ,
V_1090 ) ) ;
F_537 ( L_155 ) ;
F_547 ( V_18 ) ;
F_554 ( V_36 ) ;
F_369 ( V_36 ) ;
}
static T_16 F_555 ( struct V_623 * V_36 ,
T_17 V_4 )
{
struct V_1 * V_2 = F_354 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
#ifdef F_326
struct V_623 * V_1157 , * V_1158 ;
T_1 V_1159 , V_1160 , V_1161 , V_1162 ;
int V_877 , V_1163 ;
T_5 V_1164 , V_1165 ;
if ( V_2 -> V_8 . V_72 . type == V_73 ||
V_2 -> V_281 == 0 )
goto V_1166;
V_1157 = V_36 -> V_1062 -> V_1167 ;
while ( V_1157 && ( F_556 ( V_1157 ) != V_1168 ) )
V_1157 = V_1157 -> V_1062 -> V_1167 ;
if ( ! V_1157 )
goto V_1166;
V_1163 = F_557 ( V_1157 , V_1169 ) ;
if ( ! V_1163 )
goto V_1166;
F_558 ( V_1157 , V_1163 + V_1170 , & V_1159 ) ;
F_558 ( V_1157 , V_1163 + V_1170 + 4 , & V_1160 ) ;
F_558 ( V_1157 , V_1163 + V_1170 + 8 , & V_1161 ) ;
F_558 ( V_1157 , V_1163 + V_1170 + 12 , & V_1162 ) ;
V_1164 = V_1160 >> 16 ;
if ( ! ( V_1164 & 0x0080 ) )
goto V_1166;
V_1165 = V_1164 & 0x01 ;
if ( ( V_1165 & 1 ) == ( V_36 -> V_1171 & 1 ) ) {
unsigned int V_311 ;
V_877 = ( V_1164 & 0x7F ) >> 1 ;
F_302 ( L_156 , V_877 ) ;
F_302 ( L_157
L_158 ,
V_1159 , V_1160 , V_1161 , V_1162 ) ;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
V_311 = V_1172 ;
break;
case V_76 :
V_311 = V_1173 ;
break;
default:
V_311 = 0 ;
break;
}
V_1158 = F_559 ( V_1174 , V_311 , NULL ) ;
while ( V_1158 ) {
if ( V_1158 -> V_1171 == ( V_1164 & 0xFF ) )
break;
V_1158 = F_559 ( V_1174 ,
V_311 , V_1158 ) ;
}
if ( V_1158 ) {
F_302 ( L_159 , V_877 ) ;
F_560 ( V_1158 , 0xA8 , 0x00008000 ) ;
}
F_561 ( V_36 ) ;
}
V_2 -> V_1175 ++ ;
return V_1176 ;
V_1166:
#endif
F_367 ( V_18 ) ;
if ( V_4 == V_1177 )
return V_1178 ;
if ( F_31 ( V_18 ) )
F_298 ( V_2 ) ;
F_369 ( V_36 ) ;
return V_1179 ;
}
static T_16 F_562 ( struct V_623 * V_36 )
{
struct V_1 * V_2 = F_354 ( V_36 ) ;
T_16 V_1180 ;
int V_361 ;
if ( F_358 ( V_36 ) ) {
F_77 ( V_135 , L_160 ) ;
V_1180 = V_1178 ;
} else {
F_359 ( V_36 ) ;
F_356 ( V_36 ) ;
F_357 ( V_36 ) ;
F_360 ( V_36 , false ) ;
F_301 ( V_2 ) ;
F_45 ( & V_2 -> V_8 , V_695 , ~ 0 ) ;
V_1180 = V_1176 ;
}
V_361 = F_561 ( V_36 ) ;
if ( V_361 ) {
F_302 ( L_161
L_162 , V_361 ) ;
}
return V_1180 ;
}
static void F_563 ( struct V_623 * V_36 )
{
struct V_1 * V_2 = F_354 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
#ifdef F_326
if ( V_2 -> V_1175 ) {
F_79 ( V_133 , L_163 ) ;
V_2 -> V_1175 -- ;
return;
}
#endif
if ( F_31 ( V_18 ) )
F_300 ( V_2 ) ;
F_364 ( V_18 ) ;
}
static int T_18 F_564 ( void )
{
int V_114 ;
F_25 ( L_164 , V_1181 , V_1182 ) ;
F_25 ( L_153 , V_1183 ) ;
#ifdef F_543
F_565 () ;
#endif
#ifdef F_192
F_566 ( & V_1184 ) ;
#endif
V_114 = F_567 ( & V_1185 ) ;
return V_114 ;
}
static void T_19 F_568 ( void )
{
#ifdef F_192
F_569 ( & V_1184 ) ;
#endif
F_570 ( & V_1185 ) ;
#ifdef F_543
F_571 () ;
#endif
F_572 () ;
}
static int F_573 ( struct V_1186 * V_1187 , unsigned long V_154 ,
void * V_441 )
{
int V_1188 ;
V_1188 = F_574 ( & V_1185 . V_1189 , NULL , & V_154 ,
F_98 ) ;
return V_1188 ? V_1190 : V_1191 ;
}
