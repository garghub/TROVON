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
F_25 ( L_13 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_41 ; V_19 ++ ) {
V_21 = V_2 -> V_21 [ V_19 ] ;
V_23 = & V_21 -> V_42 [ V_21 -> V_43 ] ;
F_25 ( L_14 ,
V_19 , V_21 -> V_44 , V_21 -> V_43 ,
( T_2 ) F_32 ( V_23 , V_45 ) ,
F_33 ( V_23 , V_46 ) ,
V_23 -> V_47 ,
( T_2 ) V_23 -> V_48 ) ;
}
if ( ! F_34 ( V_2 ) )
goto V_49;
F_30 ( & V_2 -> V_36 -> V_37 , L_15 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_41 ; V_19 ++ ) {
V_21 = V_2 -> V_21 [ V_19 ] ;
F_25 ( L_16 ) ;
F_25 ( L_17 , V_21 -> V_50 ) ;
F_25 ( L_16 ) ;
F_25 ( L_18
L_19
L_20 ) ;
for ( V_11 = 0 ; V_21 -> V_51 && ( V_11 < V_21 -> V_52 ) ; V_11 ++ ) {
V_25 = F_35 ( V_21 , V_11 ) ;
V_23 = & V_21 -> V_42 [ V_11 ] ;
V_29 = (struct V_26 * ) V_25 ;
F_25 ( L_21
L_22 , V_11 ,
F_36 ( V_29 -> V_27 ) ,
F_36 ( V_29 -> V_28 ) ,
( T_2 ) F_32 ( V_23 , V_45 ) ,
F_33 ( V_23 , V_46 ) ,
V_23 -> V_47 ,
( T_2 ) V_23 -> V_48 ,
V_23 -> V_53 ) ;
if ( V_11 == V_21 -> V_44 &&
V_11 == V_21 -> V_43 )
F_27 ( L_23 ) ;
else if ( V_11 == V_21 -> V_44 )
F_27 ( L_24 ) ;
else if ( V_11 == V_21 -> V_43 )
F_27 ( L_25 ) ;
else
F_27 ( L_5 ) ;
if ( F_37 ( V_2 ) &&
V_23 -> V_53 )
F_38 ( V_54 , L_26 ,
V_55 , 16 , 1 ,
V_23 -> V_53 -> V_56 ,
F_33 ( V_23 , V_46 ) ,
true ) ;
}
}
V_49:
F_30 ( & V_2 -> V_36 -> V_37 , L_27 ) ;
F_25 ( L_28 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_57 ; V_19 ++ ) {
V_30 = V_2 -> V_30 [ V_19 ] ;
F_25 ( L_29 ,
V_19 , V_30 -> V_44 , V_30 -> V_43 ) ;
}
if ( ! F_39 ( V_2 ) )
goto exit;
F_30 ( & V_2 -> V_36 -> V_37 , L_30 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_57 ; V_19 ++ ) {
V_30 = V_2 -> V_30 [ V_19 ] ;
F_25 ( L_16 ) ;
F_25 ( L_31 , V_30 -> V_50 ) ;
F_25 ( L_16 ) ;
F_25 ( L_32
L_33
L_34 ) ;
F_25 ( L_35
L_36
L_37 ) ;
for ( V_11 = 0 ; V_11 < V_30 -> V_52 ; V_11 ++ ) {
V_34 = & V_30 -> V_34 [ V_11 ] ;
V_32 = F_40 ( V_30 , V_11 ) ;
V_29 = (struct V_26 * ) V_32 ;
V_35 = F_41 ( V_32 -> V_58 . V_59 . V_60 ) ;
if ( V_35 & V_61 ) {
F_25 ( L_38
L_39 , V_11 ,
F_36 ( V_29 -> V_27 ) ,
F_36 ( V_29 -> V_28 ) ,
V_34 -> V_53 ) ;
} else {
F_25 ( L_40
L_41 , V_11 ,
F_36 ( V_29 -> V_27 ) ,
F_36 ( V_29 -> V_28 ) ,
( T_2 ) V_34 -> V_45 ,
V_34 -> V_53 ) ;
if ( F_37 ( V_2 ) &&
V_34 -> V_45 ) {
F_38 ( V_54 , L_26 ,
V_55 , 16 , 1 ,
F_42 ( V_34 -> V_62 ) +
V_34 -> V_63 ,
F_43 ( V_30 ) , true ) ;
}
}
if ( V_11 == V_30 -> V_44 )
F_27 ( L_24 ) ;
else if ( V_11 == V_30 -> V_43 )
F_27 ( L_25 ) ;
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
int V_11 ;
bool V_96 = V_2 -> V_97 . V_98 ;
if ( V_2 -> V_99 )
V_96 |= ! ! ( V_2 -> V_99 -> V_96 ) ;
if ( ! ( V_2 -> V_100 & V_101 ) || ! V_96 ) {
F_56 ( V_2 ) ;
return;
}
for ( V_11 = 0 ; V_11 < V_102 ; V_11 ++ ) {
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_95 [ V_11 ] = F_11 ( V_8 , F_58 ( V_11 ) ) ;
break;
default:
V_95 [ V_11 ] = F_11 ( V_8 , F_59 ( V_11 ) ) ;
}
V_85 -> V_103 [ V_11 ] += V_95 [ V_11 ] ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_21 = V_2 -> V_21 [ V_11 ] ;
T_4 V_104 = V_21 -> V_105 ;
if ( V_95 [ V_104 ] )
F_8 ( V_94 , & V_21 -> V_4 ) ;
}
}
static T_2 F_60 ( struct V_20 * V_82 )
{
return V_82 -> V_86 . V_106 ;
}
static T_2 F_61 ( struct V_20 * V_82 )
{
struct V_1 * V_2 = F_62 ( V_82 -> V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_107 = F_11 ( V_8 , F_22 ( V_82 -> V_108 ) ) ;
T_1 V_109 = F_11 ( V_8 , F_23 ( V_82 -> V_108 ) ) ;
if ( V_107 != V_109 )
return ( V_107 < V_109 ) ?
V_109 - V_107 : ( V_109 + V_82 -> V_52 - V_107 ) ;
return 0 ;
}
static inline bool F_63 ( struct V_20 * V_21 )
{
T_1 V_110 = F_60 ( V_21 ) ;
T_1 V_111 = V_21 -> V_112 . V_111 ;
T_1 V_113 = F_61 ( V_21 ) ;
bool V_114 = false ;
F_64 ( V_21 ) ;
if ( ( V_111 == V_110 ) && V_113 ) {
V_114 = F_3 ( V_94 ,
& V_21 -> V_4 ) ;
} else {
V_21 -> V_112 . V_111 = V_110 ;
F_8 ( V_94 , & V_21 -> V_4 ) ;
}
return V_114 ;
}
static void F_65 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_115 |= V_116 ;
F_1 ( V_2 ) ;
}
}
static bool F_66 ( struct V_117 * V_118 ,
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
F_67 () ;
if ( ! ( V_124 -> V_58 . V_125 & F_68 ( V_126 ) ) )
break;
V_23 -> V_47 = NULL ;
V_119 += V_23 -> V_127 ;
V_120 += V_23 -> V_128 ;
#ifdef F_69
if ( F_70 ( V_23 -> V_129 & V_130 ) )
F_71 ( V_118 , V_23 -> V_53 ) ;
#endif
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
if ( F_76 ( V_21 ) && F_63 ( V_21 ) ) {
struct V_7 * V_8 = & V_2 -> V_8 ;
F_77 ( V_133 , L_42
L_43
L_44
L_45
L_46
L_47
L_48
L_49 ,
V_21 -> V_50 ,
F_11 ( V_8 , F_22 ( V_21 -> V_108 ) ) ,
F_11 ( V_8 , F_23 ( V_21 -> V_108 ) ) ,
V_21 -> V_44 , V_11 ,
V_21 -> V_42 [ V_11 ] . V_48 , V_134 ) ;
F_78 ( V_21 -> V_18 , V_21 -> V_50 ) ;
F_79 ( V_135 ,
L_50 ,
V_2 -> V_136 + 1 , V_21 -> V_50 ) ;
F_65 ( V_2 ) ;
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
V_148 |
V_149 ;
F_45 ( V_8 , F_12 ( V_108 ) , V_145 ) ;
}
static void F_93 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
struct V_20 * V_82 ;
int V_138 = F_94 () ;
if ( V_118 -> V_138 == V_138 )
goto V_150;
F_95 (ring, q_vector->tx)
F_88 ( V_2 , V_82 , V_138 ) ;
F_95 (ring, q_vector->rx)
F_92 ( V_2 , V_82 , V_138 ) ;
V_118 -> V_138 = V_138 ;
V_150:
F_96 () ;
}
static void F_97 ( struct V_1 * V_2 )
{
int V_11 ;
if ( ! ( V_2 -> V_100 & V_151 ) )
return;
F_45 ( & V_2 -> V_8 , V_152 , 2 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_153 ; V_11 ++ ) {
V_2 -> V_118 [ V_11 ] -> V_138 = - 1 ;
F_93 ( V_2 -> V_118 [ V_11 ] ) ;
}
}
static int F_98 ( struct V_154 * V_37 , void * V_56 )
{
struct V_1 * V_2 = F_99 ( V_37 ) ;
unsigned long V_155 = * ( unsigned long * ) V_56 ;
if ( ! ( V_2 -> V_100 & V_156 ) )
return 0 ;
switch ( V_155 ) {
case V_157 :
if ( V_2 -> V_100 & V_151 )
break;
if ( F_100 ( V_37 ) == 0 ) {
V_2 -> V_100 |= V_151 ;
F_97 ( V_2 ) ;
break;
}
case V_158 :
if ( V_2 -> V_100 & V_151 ) {
F_101 ( V_37 ) ;
V_2 -> V_100 &= ~ V_151 ;
F_45 ( & V_2 -> V_8 , V_152 , 1 ) ;
}
break;
}
return 0 ;
}
static inline void F_102 ( struct V_20 * V_82 ,
union V_31 * V_32 ,
struct V_159 * V_53 )
{
if ( V_82 -> V_18 -> V_160 & V_161 )
V_53 -> V_162 = F_41 ( V_32 -> V_58 . V_163 . V_164 . V_165 ) ;
}
static inline bool F_103 ( struct V_20 * V_82 ,
union V_31 * V_32 )
{
T_6 V_166 = V_32 -> V_58 . V_163 . V_167 . V_168 . V_166 ;
return F_2 ( V_169 , & V_82 -> V_4 ) &&
( ( V_166 & F_104 ( V_170 ) ) ==
( F_104 ( V_171 <<
V_172 ) ) ) ;
}
static inline void F_105 ( struct V_20 * V_82 ,
union V_31 * V_32 ,
struct V_159 * V_53 )
{
F_106 ( V_53 ) ;
if ( ! ( V_82 -> V_18 -> V_160 & V_173 ) )
return;
if ( F_107 ( V_32 , V_174 ) &&
F_107 ( V_32 , V_175 ) ) {
V_82 -> V_176 . V_177 ++ ;
return;
}
if ( ! F_107 ( V_32 , V_178 ) )
return;
if ( F_107 ( V_32 , V_179 ) ) {
T_6 V_166 = V_32 -> V_58 . V_163 . V_167 . V_168 . V_166 ;
if ( ( V_166 & F_104 ( V_180 ) ) &&
F_2 ( V_181 , & V_82 -> V_4 ) )
return;
V_82 -> V_176 . V_177 ++ ;
return;
}
V_53 -> V_182 = V_183 ;
}
static inline void F_108 ( struct V_20 * V_30 , T_1 V_184 )
{
V_30 -> V_44 = V_184 ;
V_30 -> V_185 = V_184 ;
F_109 () ;
F_110 ( V_184 , V_30 -> V_109 ) ;
}
static bool F_111 ( struct V_20 * V_30 ,
struct V_33 * V_186 )
{
struct V_62 * V_62 = V_186 -> V_62 ;
T_7 V_45 = V_186 -> V_45 ;
if ( F_73 ( V_45 ) )
return true ;
if ( F_73 ( ! V_62 ) ) {
V_62 = F_112 ( V_187 | V_188 | V_189 ,
V_186 -> V_53 , F_113 ( V_30 ) ) ;
if ( F_70 ( ! V_62 ) ) {
V_30 -> V_176 . V_190 ++ ;
return false ;
}
V_186 -> V_62 = V_62 ;
}
V_45 = F_114 ( V_30 -> V_37 , V_62 , 0 ,
F_115 ( V_30 ) , V_191 ) ;
if ( F_116 ( V_30 -> V_37 , V_45 ) ) {
F_117 ( V_62 , F_113 ( V_30 ) ) ;
V_186 -> V_62 = NULL ;
V_30 -> V_176 . V_190 ++ ;
return false ;
}
V_186 -> V_45 = V_45 ;
V_186 -> V_63 ^= F_43 ( V_30 ) ;
return true ;
}
void F_118 ( struct V_20 * V_30 , T_5 V_192 )
{
union V_31 * V_32 ;
struct V_33 * V_186 ;
T_5 V_11 = V_30 -> V_44 ;
if ( ! V_192 )
return;
V_32 = F_40 ( V_30 , V_11 ) ;
V_186 = & V_30 -> V_34 [ V_11 ] ;
V_11 -= V_30 -> V_52 ;
do {
if ( ! F_111 ( V_30 , V_186 ) )
break;
V_32 -> V_193 . V_194 = F_119 ( V_186 -> V_45 + V_186 -> V_63 ) ;
V_32 ++ ;
V_186 ++ ;
V_11 ++ ;
if ( F_70 ( ! V_11 ) ) {
V_32 = F_40 ( V_30 , 0 ) ;
V_186 = V_30 -> V_34 ;
V_11 -= V_30 -> V_52 ;
}
V_32 -> V_193 . V_195 = 0 ;
V_192 -- ;
} while ( V_192 );
V_11 += V_30 -> V_52 ;
if ( V_30 -> V_44 != V_11 )
F_108 ( V_30 , V_11 ) ;
}
static unsigned int F_120 ( unsigned char * V_56 ,
unsigned int V_196 )
{
union {
unsigned char * V_197 ;
struct V_198 * V_199 ;
struct V_200 * V_201 ;
struct V_202 * V_203 ;
} V_204 ;
T_8 V_205 ;
T_4 V_206 = 0 ;
T_4 V_207 ;
if ( V_196 < V_208 )
return V_196 ;
V_204 . V_197 = V_56 ;
V_205 = V_204 . V_199 -> V_209 ;
V_204 . V_197 += V_208 ;
if ( V_205 == F_121 ( V_210 ) ) {
if ( ( V_204 . V_197 - V_56 ) > ( V_196 - V_211 ) )
return V_196 ;
V_205 = V_204 . V_201 -> V_212 ;
V_204 . V_197 += V_211 ;
}
if ( V_205 == F_121 ( V_213 ) ) {
if ( ( V_204 . V_197 - V_56 ) > ( V_196 - sizeof( struct V_202 ) ) )
return V_196 ;
V_207 = ( V_204 . V_197 [ 0 ] & 0x0F ) << 2 ;
if ( V_207 < sizeof( struct V_202 ) )
return V_204 . V_197 - V_56 ;
V_206 = V_204 . V_203 -> V_205 ;
V_204 . V_197 += V_207 ;
#ifdef F_122
} else if ( V_205 == F_121 ( V_214 ) ) {
if ( ( V_204 . V_197 - V_56 ) > ( V_196 - V_215 ) )
return V_196 ;
V_204 . V_197 += V_215 ;
#endif
} else {
return V_204 . V_197 - V_56 ;
}
if ( V_206 == V_216 ) {
if ( ( V_204 . V_197 - V_56 ) > ( V_196 - sizeof( struct V_217 ) ) )
return V_196 ;
V_207 = ( V_204 . V_197 [ 12 ] & 0xF0 ) >> 2 ;
if ( V_207 < sizeof( struct V_217 ) )
return V_204 . V_197 - V_56 ;
V_204 . V_197 += V_207 ;
}
if ( ( V_204 . V_197 - V_56 ) < V_196 )
return V_204 . V_197 - V_56 ;
else
return V_196 ;
}
static void F_123 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_159 * V_53 )
{
T_9 V_218 ;
T_1 V_219 ;
if ( ! F_124 ( V_30 ) )
return;
V_218 = V_32 -> V_58 . V_163 . V_167 . V_56 &
F_68 ( V_220 ) ;
if ( ! V_218 )
return;
V_219 = F_41 ( V_218 ) ;
V_219 >>= V_221 ;
F_125 ( V_53 ) -> V_222 += V_219 - 1 ;
}
static void F_126 ( struct V_20 * V_82 ,
struct V_159 * V_53 )
{
T_5 V_223 = F_127 ( V_53 ) ;
F_128 ( V_53 ) -> V_224 = F_129 ( ( V_53 -> V_46 - V_223 ) ,
F_125 ( V_53 ) -> V_222 ) ;
}
static void F_130 ( struct V_20 * V_30 ,
struct V_159 * V_53 )
{
if ( ! F_125 ( V_53 ) -> V_222 )
return;
V_30 -> V_176 . V_225 += F_125 ( V_53 ) -> V_222 ;
V_30 -> V_176 . V_226 ++ ;
F_126 ( V_30 , V_53 ) ;
F_125 ( V_53 ) -> V_222 = 0 ;
}
static void F_131 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_159 * V_53 )
{
struct V_17 * V_37 = V_30 -> V_18 ;
F_130 ( V_30 , V_53 ) ;
F_102 ( V_30 , V_32 , V_53 ) ;
F_105 ( V_30 , V_32 , V_53 ) ;
#ifdef F_69
F_132 ( V_30 -> V_118 , V_32 , V_53 ) ;
#endif
if ( ( V_37 -> V_160 & V_227 ) &&
F_107 ( V_32 , V_228 ) ) {
T_5 V_229 = F_133 ( V_32 -> V_58 . V_59 . V_201 ) ;
F_134 ( V_53 , V_229 ) ;
}
F_135 ( V_53 , V_30 -> V_50 ) ;
V_53 -> V_205 = F_136 ( V_53 , V_37 ) ;
}
static void F_137 ( struct V_117 * V_118 ,
struct V_159 * V_53 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
if ( ! ( V_2 -> V_100 & V_230 ) )
F_138 ( & V_118 -> V_231 , V_53 ) ;
else
F_139 ( V_53 ) ;
}
static bool F_140 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_159 * V_53 )
{
T_1 V_232 = V_30 -> V_43 + 1 ;
V_232 = ( V_232 < V_30 -> V_52 ) ? V_232 : 0 ;
V_30 -> V_43 = V_232 ;
F_72 ( F_40 ( V_30 , V_232 ) ) ;
if ( F_73 ( F_107 ( V_32 , V_233 ) ) )
return false ;
if ( F_125 ( V_53 ) -> V_222 ) {
V_232 = F_41 ( V_32 -> V_58 . V_59 . V_60 ) ;
V_232 &= V_234 ;
V_232 >>= V_235 ;
}
V_30 -> V_34 [ V_232 ] . V_53 = V_53 ;
V_30 -> V_176 . V_236 ++ ;
return true ;
}
static bool F_141 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_159 * V_53 )
{
struct V_237 * V_238 = & F_128 ( V_53 ) -> V_239 [ 0 ] ;
struct V_17 * V_18 = V_30 -> V_18 ;
unsigned char * V_240 ;
unsigned int V_241 ;
if ( F_70 ( F_125 ( V_53 ) -> V_242 ) ) {
F_54 ( V_30 -> V_37 , F_125 ( V_53 ) -> V_45 ,
F_115 ( V_30 ) , V_191 ) ;
F_125 ( V_53 ) -> V_242 = false ;
} else {
F_142 ( V_30 -> V_37 ,
F_125 ( V_53 ) -> V_45 ,
V_238 -> V_63 ,
F_43 ( V_30 ) ,
V_191 ) ;
}
F_125 ( V_53 ) -> V_45 = 0 ;
if ( F_70 ( F_107 ( V_32 ,
V_243 ) &&
! ( V_18 -> V_160 & V_244 ) ) ) {
F_52 ( V_53 ) ;
return true ;
}
V_240 = F_143 ( V_238 ) ;
V_241 = F_144 ( V_238 ) ;
if ( V_241 > V_245 )
V_241 = F_120 ( V_240 , V_245 ) ;
F_145 ( V_53 , V_240 , F_146 ( V_241 , sizeof( long ) ) ) ;
F_147 ( V_238 , V_241 ) ;
V_238 -> V_63 += V_241 ;
V_53 -> V_246 -= V_241 ;
V_53 -> V_109 += V_241 ;
if ( F_144 ( V_238 ) == 0 ) {
F_6 ( F_128 ( V_53 ) -> V_247 != 1 ) ;
F_128 ( V_53 ) -> V_247 = 0 ;
F_148 ( V_238 ) ;
V_53 -> V_248 -= F_43 ( V_30 ) ;
}
#ifdef F_122
if ( F_103 ( V_30 , V_32 ) )
return false ;
#endif
if ( F_70 ( V_53 -> V_46 < 60 ) ) {
int V_249 = 60 - V_53 -> V_46 ;
if ( F_149 ( V_53 , V_249 ) )
return true ;
F_150 ( V_53 , V_249 ) ;
}
return false ;
}
static inline bool F_151 ( struct V_33 * V_250 )
{
struct V_62 * V_62 = V_250 -> V_62 ;
return F_73 ( F_152 ( V_62 ) == 1 ) &&
F_73 ( F_153 ( V_62 ) == F_154 () ) ;
}
static void F_155 ( struct V_20 * V_30 ,
struct V_33 * V_251 )
{
struct V_33 * V_252 ;
T_5 V_253 = V_30 -> V_185 ;
T_5 V_254 = F_43 ( V_30 ) ;
V_252 = & V_30 -> V_34 [ V_253 ] ;
V_253 ++ ;
V_30 -> V_185 = ( V_253 < V_30 -> V_52 ) ? V_253 : 0 ;
V_252 -> V_62 = V_251 -> V_62 ;
V_252 -> V_45 = V_251 -> V_45 ;
V_252 -> V_63 = V_251 -> V_63 ^ V_254 ;
F_156 ( V_30 -> V_37 , V_252 -> V_45 ,
V_252 -> V_63 , V_254 ,
V_191 ) ;
F_157 ( V_252 -> V_62 ) ;
}
static void F_158 ( struct V_20 * V_30 ,
struct V_33 * V_250 ,
struct V_159 * V_53 , int V_255 )
{
F_159 ( V_53 , F_128 ( V_53 ) -> V_247 ,
V_250 -> V_62 , V_250 -> V_63 ,
V_255 ) ;
V_53 -> V_46 += V_255 ;
V_53 -> V_246 += V_255 ;
V_53 -> V_248 += F_43 ( V_30 ) ;
}
static bool F_160 ( struct V_117 * V_118 ,
struct V_20 * V_30 ,
int V_121 )
{
unsigned int V_256 = 0 , V_257 = 0 ;
#ifdef F_122
struct V_1 * V_2 = V_118 -> V_2 ;
int V_258 = 0 ;
#endif
T_5 V_192 = F_84 ( V_30 ) ;
do {
struct V_33 * V_250 ;
union V_31 * V_32 ;
struct V_159 * V_53 ;
struct V_62 * V_62 ;
T_5 V_232 ;
if ( V_192 >= V_259 ) {
F_118 ( V_30 , V_192 ) ;
V_192 = 0 ;
}
V_232 = V_30 -> V_43 ;
V_32 = F_40 ( V_30 , V_232 ) ;
V_250 = & V_30 -> V_34 [ V_232 ] ;
if ( ! F_107 ( V_32 , V_61 ) )
break;
F_67 () ;
V_62 = V_250 -> V_62 ;
F_161 ( V_62 ) ;
V_53 = V_250 -> V_53 ;
if ( F_73 ( ! V_53 ) ) {
void * V_260 = F_42 ( V_62 ) +
V_250 -> V_63 ;
F_72 ( V_260 ) ;
#if V_261 < 128
F_72 ( V_260 + V_261 ) ;
#endif
V_53 = F_162 ( V_30 -> V_18 ,
V_245 ) ;
if ( F_70 ( ! V_53 ) ) {
V_30 -> V_176 . V_262 ++ ;
break;
}
F_161 ( V_53 -> V_56 ) ;
F_125 ( V_53 ) -> V_45 = V_250 -> V_45 ;
} else {
F_142 ( V_30 -> V_37 ,
V_250 -> V_45 ,
V_250 -> V_63 ,
F_43 ( V_30 ) ,
V_191 ) ;
}
F_158 ( V_30 , V_250 , V_53 ,
F_133 ( V_32 -> V_58 . V_59 . V_263 ) ) ;
if ( F_151 ( V_250 ) ) {
F_155 ( V_30 , V_250 ) ;
} else if ( F_125 ( V_53 ) -> V_45 == V_250 -> V_45 ) {
F_125 ( V_53 ) -> V_242 = true ;
} else {
F_54 ( V_30 -> V_37 , V_250 -> V_45 ,
F_115 ( V_30 ) ,
V_191 ) ;
}
V_250 -> V_53 = NULL ;
V_250 -> V_45 = 0 ;
V_250 -> V_62 = NULL ;
F_123 ( V_30 , V_32 , V_53 ) ;
V_192 ++ ;
if ( F_140 ( V_30 , V_32 , V_53 ) )
continue;
if ( F_141 ( V_30 , V_32 , V_53 ) )
continue;
V_256 += V_53 -> V_46 ;
V_257 ++ ;
F_131 ( V_30 , V_32 , V_53 ) ;
#ifdef F_122
if ( F_103 ( V_30 , V_32 ) ) {
V_258 = F_163 ( V_2 , V_32 , V_53 ) ;
if ( ! V_258 ) {
F_52 ( V_53 ) ;
continue;
}
}
#endif
F_137 ( V_118 , V_53 ) ;
V_121 -- ;
} while ( F_73 ( V_121 ) );
#ifdef F_122
if ( V_258 > 0 ) {
unsigned int V_264 ;
V_264 = V_30 -> V_18 -> V_265 - sizeof( struct V_266 ) -
sizeof( struct V_267 ) -
sizeof( struct V_268 ) ;
if ( V_264 > 512 )
V_264 &= ~ 511 ;
V_256 += V_258 ;
V_257 += F_129 ( V_258 , V_264 ) ;
}
#endif
F_74 ( & V_30 -> V_131 ) ;
V_30 -> V_86 . V_106 += V_257 ;
V_30 -> V_86 . V_132 += V_256 ;
F_75 ( & V_30 -> V_131 ) ;
V_118 -> V_269 . V_120 += V_257 ;
V_118 -> V_269 . V_119 += V_256 ;
if ( V_192 )
F_118 ( V_30 , V_192 ) ;
return ! ! V_121 ;
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_117 * V_118 ;
int V_270 ;
T_1 V_79 ;
if ( V_2 -> V_271 > 32 ) {
T_1 V_272 = ( 1 << ( V_2 -> V_271 - 32 ) ) - 1 ;
F_45 ( & V_2 -> V_8 , V_273 , V_272 ) ;
}
for ( V_270 = 0 ; V_270 < V_2 -> V_153 ; V_270 ++ ) {
struct V_20 * V_82 ;
V_118 = V_2 -> V_118 [ V_270 ] ;
F_95 (ring, q_vector->rx)
F_47 ( V_2 , 0 , V_82 -> V_108 , V_270 ) ;
F_95 (ring, q_vector->tx)
F_47 ( V_2 , 1 , V_82 -> V_108 , V_270 ) ;
if ( V_118 -> V_122 . V_82 && ! V_118 -> V_269 . V_82 ) {
if ( V_2 -> V_274 == 1 )
V_118 -> V_275 = V_276 ;
else
V_118 -> V_275 = V_2 -> V_274 ;
} else {
if ( V_2 -> V_277 == 1 )
V_118 -> V_275 = V_278 ;
else
V_118 -> V_275 = V_2 -> V_277 ;
}
F_165 ( V_118 ) ;
}
switch ( V_2 -> V_8 . V_72 . type ) {
case V_73 :
F_47 ( V_2 , - 1 , V_279 ,
V_270 ) ;
break;
case V_75 :
case V_76 :
F_47 ( V_2 , - 1 , 1 , V_270 ) ;
break;
default:
break;
}
F_45 ( & V_2 -> V_8 , F_166 ( V_270 ) , 1950 ) ;
V_79 = V_280 ;
V_79 &= ~ ( V_281 |
V_282 |
V_283 ) ;
F_45 ( & V_2 -> V_8 , V_284 , V_79 ) ;
}
static void F_167 ( struct V_117 * V_118 ,
struct V_285 * V_286 )
{
int V_132 = V_286 -> V_119 ;
int V_106 = V_286 -> V_120 ;
T_1 V_287 ;
T_2 V_288 ;
T_4 V_289 = V_286 -> V_275 ;
if ( V_106 == 0 )
return;
V_287 = V_118 -> V_275 >> 2 ;
V_288 = V_132 / V_287 ;
switch ( V_289 ) {
case V_290 :
if ( V_288 > 10 )
V_289 = V_291 ;
break;
case V_291 :
if ( V_288 > 20 )
V_289 = V_292 ;
else if ( V_288 <= 10 )
V_289 = V_290 ;
break;
case V_292 :
if ( V_288 <= 20 )
V_289 = V_291 ;
break;
}
V_286 -> V_119 = 0 ;
V_286 -> V_120 = 0 ;
V_286 -> V_275 = V_289 ;
}
void F_165 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_270 = V_118 -> V_270 ;
T_1 V_293 = V_118 -> V_275 & V_294 ;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_73 :
V_293 |= ( V_293 << 16 ) ;
break;
case V_75 :
case V_76 :
V_293 |= V_295 ;
break;
default:
break;
}
F_45 ( V_8 , F_166 ( V_270 ) , V_293 ) ;
}
static void F_168 ( struct V_117 * V_118 )
{
T_1 V_296 = V_118 -> V_275 ;
T_4 V_297 ;
F_167 ( V_118 , & V_118 -> V_122 ) ;
F_167 ( V_118 , & V_118 -> V_269 ) ;
V_297 = F_169 ( V_118 -> V_269 . V_275 , V_118 -> V_122 . V_275 ) ;
switch ( V_297 ) {
case V_290 :
V_296 = V_298 ;
break;
case V_291 :
V_296 = V_278 ;
break;
case V_292 :
V_296 = V_299 ;
break;
default:
break;
}
if ( V_296 != V_118 -> V_275 ) {
V_296 = ( 10 * V_296 * V_118 -> V_275 ) /
( ( 9 * V_296 ) + V_118 -> V_275 ) ;
V_118 -> V_275 = V_296 ;
F_165 ( V_118 ) ;
}
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_300 = V_2 -> V_301 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
if ( ! ( V_2 -> V_115 & V_302 ) &&
! ( V_2 -> V_115 & V_303 ) )
return;
V_2 -> V_115 &= ~ V_303 ;
switch ( V_8 -> V_304 ) {
case V_305 :
if ( ! ( V_300 & V_306 ) &&
! ( V_300 & V_307 ) )
return;
if ( ! ( V_300 & V_307 ) && V_8 -> V_72 . V_308 . V_309 ) {
T_1 V_310 ;
bool V_311 = false ;
V_8 -> V_72 . V_308 . V_309 ( V_8 , & V_310 , & V_311 , false ) ;
if ( V_311 )
return;
}
if ( V_8 -> V_312 . V_308 . V_313 ( V_8 ) != V_314 )
return;
break;
default:
if ( ! ( V_300 & V_306 ) )
return;
break;
}
F_171 ( V_133 ,
L_51
L_52
L_53 ) ;
V_2 -> V_301 = 0 ;
}
static void F_172 ( struct V_1 * V_2 , T_1 V_300 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( ( V_2 -> V_100 & V_315 ) &&
( V_300 & V_316 ) ) {
F_171 ( V_135 , L_54 ) ;
F_45 ( V_8 , V_317 , V_316 ) ;
}
}
static void F_173 ( struct V_1 * V_2 , T_1 V_300 )
{
if ( ! ( V_2 -> V_115 & V_302 ) )
return;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
if ( ( ( V_300 & V_306 ) || ( V_300 & V_307 ) ) &&
( ! F_2 ( V_3 , & V_2 -> V_4 ) ) ) {
V_2 -> V_301 = V_300 ;
V_2 -> V_115 |= V_303 ;
F_1 ( V_2 ) ;
return;
}
return;
case V_76 :
if ( ! ( V_300 & V_318 ) )
return;
break;
default:
return;
}
F_171 ( V_133 ,
L_51
L_52
L_53 ) ;
}
static void F_174 ( struct V_1 * V_2 , T_1 V_300 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( V_300 & V_319 ) {
F_45 ( V_8 , V_317 , V_319 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_115 |= V_320 ;
F_1 ( V_2 ) ;
}
}
if ( V_300 & V_316 ) {
F_45 ( V_8 , V_317 , V_316 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_100 |= V_321 ;
F_1 ( V_2 ) ;
}
}
}
static void F_175 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
V_2 -> V_322 ++ ;
V_2 -> V_100 |= V_323 ;
V_2 -> V_324 = V_134 ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_45 ( V_8 , V_325 , V_326 ) ;
F_176 ( V_8 ) ;
F_1 ( V_2 ) ;
}
}
static inline void F_177 ( struct V_1 * V_2 ,
T_2 V_78 )
{
T_1 V_79 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_79 = ( V_80 & V_78 ) ;
F_45 ( V_8 , V_327 , V_79 ) ;
break;
case V_75 :
case V_76 :
V_79 = ( V_78 & 0xFFFFFFFF ) ;
if ( V_79 )
F_45 ( V_8 , F_178 ( 0 ) , V_79 ) ;
V_79 = ( V_78 >> 32 ) ;
if ( V_79 )
F_45 ( V_8 , F_178 ( 1 ) , V_79 ) ;
break;
default:
break;
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
F_45 ( V_8 , V_325 , V_79 ) ;
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
static inline void F_181 ( struct V_1 * V_2 , bool V_328 ,
bool V_329 )
{
T_1 V_79 = ( V_280 & ~ V_80 ) ;
if ( V_2 -> V_100 & V_323 )
V_79 &= ~ V_283 ;
if ( V_2 -> V_115 & V_302 )
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
V_79 |= V_330 ;
break;
case V_76 :
V_79 |= V_331 ;
break;
default:
break;
}
if ( V_2 -> V_100 & V_315 )
V_79 |= V_332 ;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
V_79 |= V_332 ;
V_79 |= V_333 ;
case V_76 :
V_79 |= V_334 ;
V_79 |= V_282 ;
break;
default:
break;
}
if ( ( V_2 -> V_100 & V_335 ) &&
! ( V_2 -> V_115 & V_336 ) )
V_79 |= V_337 ;
F_45 ( & V_2 -> V_8 , V_327 , V_79 ) ;
if ( V_328 )
F_177 ( V_2 , ~ 0 ) ;
if ( V_329 )
F_176 ( & V_2 -> V_8 ) ;
}
static T_10 F_182 ( int V_338 , void * V_56 )
{
struct V_1 * V_2 = V_56 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_300 ;
V_300 = F_11 ( V_8 , V_81 ) ;
F_45 ( V_8 , V_317 , V_300 ) ;
if ( V_300 & V_307 )
F_175 ( V_2 ) ;
if ( V_300 & V_339 )
F_183 ( V_2 ) ;
switch ( V_8 -> V_72 . type ) {
case V_75 :
case V_76 :
if ( V_300 & V_340 )
F_79 ( V_341 , L_55
L_56 ) ;
if ( V_300 & V_342 ) {
int V_343 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_82 = V_2 -> V_21 [ V_11 ] ;
if ( F_184 ( V_344 ,
& V_82 -> V_4 ) )
V_343 ++ ;
}
if ( V_343 ) {
F_45 ( V_8 , V_325 , V_345 ) ;
V_2 -> V_115 |= V_336 ;
F_1 ( V_2 ) ;
}
}
F_174 ( V_2 , V_300 ) ;
F_173 ( V_2 , V_300 ) ;
break;
default:
break;
}
F_172 ( V_2 , V_300 ) ;
#ifdef F_69
F_185 ( V_2 , V_300 ) ;
#endif
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_181 ( V_2 , false , false ) ;
return V_346 ;
}
static T_10 F_186 ( int V_338 , void * V_56 )
{
struct V_117 * V_118 = V_56 ;
if ( V_118 -> V_269 . V_82 || V_118 -> V_122 . V_82 )
F_187 ( & V_118 -> V_231 ) ;
return V_346 ;
}
int F_188 ( struct V_347 * V_231 , int V_121 )
{
struct V_117 * V_118 =
F_189 ( V_231 , struct V_117 , V_231 ) ;
struct V_1 * V_2 = V_118 -> V_2 ;
struct V_20 * V_82 ;
int V_348 ;
bool V_349 = true ;
#ifdef F_190
if ( V_2 -> V_100 & V_151 )
F_93 ( V_118 ) ;
#endif
F_95 (ring, q_vector->tx)
V_349 &= ! ! F_66 ( V_118 , V_82 ) ;
if ( V_118 -> V_269 . V_52 > 1 )
V_348 = F_169 ( V_121 / V_118 -> V_269 . V_52 , 1 ) ;
else
V_348 = V_121 ;
F_95 (ring, q_vector->rx)
V_349 &= F_160 ( V_118 , V_82 ,
V_348 ) ;
if ( ! V_349 )
return V_121 ;
F_191 ( V_231 ) ;
if ( V_2 -> V_277 & 1 )
F_168 ( V_118 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_177 ( V_2 , ( ( T_2 ) 1 << V_118 -> V_270 ) ) ;
return 0 ;
}
static int F_192 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
int V_350 , V_351 ;
int V_352 = 0 , V_353 = 0 ;
for ( V_350 = 0 ; V_350 < V_2 -> V_153 ; V_350 ++ ) {
struct V_117 * V_118 = V_2 -> V_118 [ V_350 ] ;
struct V_354 * V_355 = & V_2 -> V_356 [ V_350 ] ;
if ( V_118 -> V_122 . V_82 && V_118 -> V_269 . V_82 ) {
snprintf ( V_118 -> V_16 , sizeof( V_118 -> V_16 ) - 1 ,
L_57 , V_18 -> V_16 , L_58 , V_352 ++ ) ;
V_353 ++ ;
} else if ( V_118 -> V_269 . V_82 ) {
snprintf ( V_118 -> V_16 , sizeof( V_118 -> V_16 ) - 1 ,
L_57 , V_18 -> V_16 , L_59 , V_352 ++ ) ;
} else if ( V_118 -> V_122 . V_82 ) {
snprintf ( V_118 -> V_16 , sizeof( V_118 -> V_16 ) - 1 ,
L_57 , V_18 -> V_16 , L_60 , V_353 ++ ) ;
} else {
continue;
}
V_351 = F_193 ( V_355 -> V_350 , & F_186 , 0 ,
V_118 -> V_16 , V_118 ) ;
if ( V_351 ) {
F_77 ( V_135 , L_61
L_62 , V_351 ) ;
goto V_357;
}
if ( V_2 -> V_100 & V_335 ) {
F_194 ( V_355 -> V_350 ,
& V_118 -> V_358 ) ;
}
}
V_351 = F_193 ( V_2 -> V_356 [ V_350 ] . V_350 ,
F_182 , 0 , V_18 -> V_16 , V_2 ) ;
if ( V_351 ) {
F_77 ( V_135 , L_63 , V_351 ) ;
goto V_357;
}
return 0 ;
V_357:
while ( V_350 ) {
V_350 -- ;
F_194 ( V_2 -> V_356 [ V_350 ] . V_350 ,
NULL ) ;
F_195 ( V_2 -> V_356 [ V_350 ] . V_350 ,
V_2 -> V_118 [ V_350 ] ) ;
}
V_2 -> V_100 &= ~ V_359 ;
F_196 ( V_2 -> V_36 ) ;
F_197 ( V_2 -> V_356 ) ;
V_2 -> V_356 = NULL ;
return V_351 ;
}
static T_10 F_198 ( int V_338 , void * V_56 )
{
struct V_1 * V_2 = V_56 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_117 * V_118 = V_2 -> V_118 [ 0 ] ;
T_1 V_300 ;
F_45 ( V_8 , V_325 , V_360 ) ;
V_300 = F_11 ( V_8 , V_317 ) ;
if ( ! V_300 ) {
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_181 ( V_2 , true , true ) ;
return V_361 ;
}
if ( V_300 & V_307 )
F_175 ( V_2 ) ;
switch ( V_8 -> V_72 . type ) {
case V_75 :
F_174 ( V_2 , V_300 ) ;
case V_76 :
if ( V_300 & V_340 )
F_79 ( V_341 , L_64
L_56 ) ;
F_173 ( V_2 , V_300 ) ;
break;
default:
break;
}
F_172 ( V_2 , V_300 ) ;
#ifdef F_69
F_185 ( V_2 , V_300 ) ;
#endif
F_187 ( & V_118 -> V_231 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_181 ( V_2 , false , false ) ;
return V_346 ;
}
static int F_199 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
int V_351 ;
if ( V_2 -> V_100 & V_359 )
V_351 = F_192 ( V_2 ) ;
else if ( V_2 -> V_100 & V_362 )
V_351 = F_193 ( V_2 -> V_36 -> V_338 , F_198 , 0 ,
V_18 -> V_16 , V_2 ) ;
else
V_351 = F_193 ( V_2 -> V_36 -> V_338 , F_198 , V_363 ,
V_18 -> V_16 , V_2 ) ;
if ( V_351 )
F_77 ( V_135 , L_65 , V_351 ) ;
return V_351 ;
}
static void F_200 ( struct V_1 * V_2 )
{
int V_350 ;
if ( ! ( V_2 -> V_100 & V_359 ) ) {
F_195 ( V_2 -> V_36 -> V_338 , V_2 ) ;
return;
}
for ( V_350 = 0 ; V_350 < V_2 -> V_153 ; V_350 ++ ) {
struct V_117 * V_118 = V_2 -> V_118 [ V_350 ] ;
struct V_354 * V_355 = & V_2 -> V_356 [ V_350 ] ;
if ( ! V_118 -> V_269 . V_82 && ! V_118 -> V_122 . V_82 )
continue;
F_194 ( V_355 -> V_350 , NULL ) ;
F_195 ( V_355 -> V_350 , V_118 ) ;
}
F_195 ( V_2 -> V_356 [ V_350 ++ ] . V_350 , V_2 ) ;
}
static inline void F_201 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 . V_72 . type ) {
case V_73 :
F_45 ( & V_2 -> V_8 , V_325 , ~ 0 ) ;
break;
case V_75 :
case V_76 :
F_45 ( & V_2 -> V_8 , V_325 , 0xFFFF0000 ) ;
F_45 ( & V_2 -> V_8 , F_180 ( 0 ) , ~ 0 ) ;
F_45 ( & V_2 -> V_8 , F_180 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_176 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_100 & V_359 ) {
int V_350 ;
for ( V_350 = 0 ; V_350 < V_2 -> V_153 ; V_350 ++ )
F_202 ( V_2 -> V_356 [ V_350 ] . V_350 ) ;
F_202 ( V_2 -> V_356 [ V_350 ++ ] . V_350 ) ;
} else {
F_202 ( V_2 -> V_36 -> V_338 ) ;
}
}
static void F_203 ( struct V_1 * V_2 )
{
struct V_117 * V_118 = V_2 -> V_118 [ 0 ] ;
if ( V_2 -> V_277 == 1 )
V_118 -> V_275 = V_278 ;
else
V_118 -> V_275 = V_2 -> V_277 ;
F_165 ( V_118 ) ;
F_47 ( V_2 , 0 , 0 , 0 ) ;
F_47 ( V_2 , 1 , 0 , 0 ) ;
F_79 ( V_8 , L_66 ) ;
}
void F_204 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_364 = V_82 -> V_45 ;
int V_365 = 10 ;
T_1 V_366 = V_367 ;
T_4 V_108 = V_82 -> V_108 ;
F_45 ( V_8 , F_24 ( V_108 ) , 0 ) ;
F_176 ( V_8 ) ;
F_45 ( V_8 , F_19 ( V_108 ) ,
( V_364 & F_205 ( 32 ) ) ) ;
F_45 ( V_8 , F_20 ( V_108 ) , ( V_364 >> 32 ) ) ;
F_45 ( V_8 , F_21 ( V_108 ) ,
V_82 -> V_52 * sizeof( union V_24 ) ) ;
F_45 ( V_8 , F_22 ( V_108 ) , 0 ) ;
F_45 ( V_8 , F_23 ( V_108 ) , 0 ) ;
V_82 -> V_109 = V_8 -> V_368 + F_23 ( V_108 ) ;
if ( ! V_82 -> V_118 || ( V_82 -> V_118 -> V_275 < 8 ) )
V_366 |= ( 1 << 16 ) ;
else
V_366 |= ( 8 << 16 ) ;
V_366 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_100 & V_335 ) {
V_82 -> V_369 = V_2 -> V_369 ;
V_82 -> V_370 = 0 ;
F_206 ( V_344 , & V_82 -> V_4 ) ;
} else {
V_82 -> V_369 = 0 ;
}
F_8 ( V_94 , & V_82 -> V_4 ) ;
F_45 ( V_8 , F_24 ( V_108 ) , V_366 ) ;
if ( V_8 -> V_72 . type == V_73 &&
! ( F_11 ( V_8 , V_371 ) & V_372 ) )
return;
do {
F_207 ( 1000 , 2000 ) ;
V_366 = F_11 ( V_8 , F_24 ( V_108 ) ) ;
} while ( -- V_365 && ! ( V_366 & V_367 ) );
if ( ! V_365 )
F_77 ( V_133 , L_67 , V_108 ) ;
}
static void F_208 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_373 , V_374 ;
T_4 V_375 = F_209 ( V_2 -> V_18 ) ;
if ( V_8 -> V_72 . type == V_73 )
return;
V_373 = F_11 ( V_8 , V_376 ) ;
V_373 |= V_377 ;
F_45 ( V_8 , V_376 , V_373 ) ;
if ( V_2 -> V_100 & V_378 ) {
V_374 = V_379 ;
if ( V_375 > 4 )
V_374 |= V_380 | V_381 ;
else if ( V_375 > 1 )
V_374 |= V_380 | V_382 ;
else if ( V_2 -> V_383 [ V_384 ] . V_385 == 4 )
V_374 |= V_386 ;
else
V_374 |= V_387 ;
} else {
if ( V_375 > 4 )
V_374 = V_380 | V_381 ;
else if ( V_375 > 1 )
V_374 = V_380 | V_382 ;
else
V_374 = V_388 ;
}
F_45 ( V_8 , V_389 , V_374 ) ;
if ( V_375 ) {
T_1 V_390 = F_11 ( V_8 , V_391 ) ;
V_390 |= V_392 ;
F_45 ( V_8 , V_391 , V_390 ) ;
}
V_373 &= ~ V_377 ;
F_45 ( V_8 , V_376 , V_373 ) ;
}
static void F_210 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_393 ;
T_1 V_11 ;
F_208 ( V_2 ) ;
if ( V_8 -> V_72 . type != V_73 ) {
V_393 = F_11 ( V_8 , V_394 ) ;
V_393 |= V_395 ;
F_45 ( V_8 , V_394 , V_393 ) ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_204 ( V_2 , V_2 -> V_21 [ V_11 ] ) ;
}
static void F_211 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_4 V_108 = V_82 -> V_108 ;
T_1 V_396 = F_11 ( V_8 , F_10 ( V_108 ) ) ;
V_396 |= V_397 ;
F_45 ( V_8 , F_10 ( V_108 ) , V_396 ) ;
}
static void F_212 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_4 V_108 = V_82 -> V_108 ;
T_1 V_396 = F_11 ( V_8 , F_10 ( V_108 ) ) ;
V_396 &= ~ V_397 ;
F_45 ( V_8 , F_10 ( V_108 ) , V_396 ) ;
}
static void F_213 ( struct V_1 * V_2 ,
struct V_20 * V_30 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_396 ;
T_4 V_108 = V_30 -> V_108 ;
if ( V_8 -> V_72 . type == V_73 ) {
T_5 V_79 = V_2 -> V_383 [ V_384 ] . V_79 ;
V_108 &= V_79 ;
}
V_396 = V_245 << V_398 ;
#if V_399 > V_400
V_396 |= V_400 >> V_401 ;
#else
V_396 |= F_43 ( V_30 ) >> V_401 ;
#endif
V_396 |= V_402 ;
F_45 ( V_8 , F_10 ( V_108 ) , V_396 ) ;
}
static void F_214 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
static const T_1 V_403 [ 10 ] = { 0xE291D73D , 0x1805EC6C , 0x2A94B30D ,
0xA54F2BEC , 0xEA49AF7C , 0xE214AD3D , 0xB855AABE ,
0x6A3E67EA , 0x14364D17 , 0x3BED200D } ;
T_1 V_404 = 0 , V_405 = 0 ;
T_1 V_406 ;
int V_11 , V_12 ;
T_5 V_407 = V_2 -> V_383 [ V_384 ] . V_385 ;
if ( ( V_2 -> V_100 & V_378 ) && ( V_407 < 2 ) )
V_407 = 2 ;
for ( V_11 = 0 ; V_11 < 10 ; V_11 ++ )
F_45 ( V_8 , F_215 ( V_11 ) , V_403 [ V_11 ] ) ;
for ( V_11 = 0 , V_12 = 0 ; V_11 < 128 ; V_11 ++ , V_12 ++ ) {
if ( V_12 == V_407 )
V_12 = 0 ;
V_405 = ( V_405 << 8 ) | ( V_12 * 0x11 ) ;
if ( ( V_11 & 3 ) == 3 )
F_45 ( V_8 , F_216 ( V_11 >> 2 ) , V_405 ) ;
}
V_406 = F_11 ( V_8 , V_408 ) ;
V_406 |= V_409 ;
F_45 ( V_8 , V_408 , V_406 ) ;
if ( V_2 -> V_8 . V_72 . type == V_73 ) {
if ( V_2 -> V_383 [ V_384 ] . V_79 )
V_404 = V_410 ;
} else {
T_4 V_375 = F_209 ( V_2 -> V_18 ) ;
if ( V_2 -> V_100 & V_378 ) {
if ( V_375 > 4 )
V_404 = V_411 ;
else if ( V_375 > 1 )
V_404 = V_412 ;
else if ( V_2 -> V_383 [ V_384 ] . V_385 == 4 )
V_404 = V_413 ;
else
V_404 = V_414 ;
} else {
if ( V_375 > 4 )
V_404 = V_415 ;
else if ( V_375 > 1 )
V_404 = V_416 ;
else
V_404 = V_410 ;
}
}
V_404 |= V_417 |
V_418 |
V_419 |
V_420 ;
if ( V_2 -> V_115 & V_421 )
V_404 |= V_422 ;
if ( V_2 -> V_115 & V_423 )
V_404 |= V_424 ;
F_45 ( V_8 , V_425 , V_404 ) ;
}
static void F_217 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_426 ;
T_4 V_108 = V_82 -> V_108 ;
if ( ! F_124 ( V_82 ) )
return;
V_426 = F_11 ( V_8 , F_218 ( V_108 ) ) ;
V_426 |= V_427 ;
#if ( V_399 <= 8192 )
V_426 |= V_428 ;
#elif ( V_399 <= 16384 )
V_426 |= V_429 ;
#else
V_426 |= V_430 ;
#endif
F_45 ( V_8 , F_218 ( V_108 ) , V_426 ) ;
}
static void F_219 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_365 = V_431 ;
T_1 V_432 ;
T_4 V_108 = V_82 -> V_108 ;
if ( V_8 -> V_72 . type == V_73 &&
! ( F_11 ( V_8 , V_371 ) & V_372 ) )
return;
do {
F_207 ( 1000 , 2000 ) ;
V_432 = F_11 ( V_8 , F_16 ( V_108 ) ) ;
} while ( -- V_365 && ! ( V_432 & V_433 ) );
if ( ! V_365 ) {
F_77 ( V_133 , L_68
L_69 , V_108 ) ;
}
}
void F_220 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_365 = V_431 ;
T_1 V_432 ;
T_4 V_108 = V_82 -> V_108 ;
V_432 = F_11 ( V_8 , F_16 ( V_108 ) ) ;
V_432 &= ~ V_433 ;
F_45 ( V_8 , F_16 ( V_108 ) , V_432 ) ;
if ( V_8 -> V_72 . type == V_73 &&
! ( F_11 ( V_8 , V_371 ) & V_372 ) )
return;
do {
F_221 ( 10 ) ;
V_432 = F_11 ( V_8 , F_16 ( V_108 ) ) ;
} while ( -- V_365 && ( V_432 & V_433 ) );
if ( ! V_365 ) {
F_77 ( V_133 , L_70
L_69 , V_108 ) ;
}
}
void F_222 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_434 = V_82 -> V_45 ;
T_1 V_432 ;
T_4 V_108 = V_82 -> V_108 ;
V_432 = F_11 ( V_8 , F_16 ( V_108 ) ) ;
F_220 ( V_2 , V_82 ) ;
F_45 ( V_8 , F_17 ( V_108 ) , ( V_434 & F_205 ( 32 ) ) ) ;
F_45 ( V_8 , F_18 ( V_108 ) , ( V_434 >> 32 ) ) ;
F_45 ( V_8 , F_13 ( V_108 ) ,
V_82 -> V_52 * sizeof( union V_31 ) ) ;
F_45 ( V_8 , F_14 ( V_108 ) , 0 ) ;
F_45 ( V_8 , F_15 ( V_108 ) , 0 ) ;
V_82 -> V_109 = V_8 -> V_368 + F_15 ( V_108 ) ;
F_213 ( V_2 , V_82 ) ;
F_217 ( V_2 , V_82 ) ;
if ( ( V_2 -> V_100 & V_378 ) &&
V_8 -> V_72 . type == V_76 ) {
V_432 &= ~ V_435 ;
V_432 |= ( ( V_82 -> V_18 -> V_265 + V_208 +
V_436 + V_211 ) | V_437 ) ;
}
if ( V_8 -> V_72 . type == V_73 ) {
V_432 &= ~ 0x3FFFFF ;
V_432 |= 0x080420 ;
}
V_432 |= V_433 ;
F_45 ( V_8 , F_16 ( V_108 ) , V_432 ) ;
F_219 ( V_2 , V_82 ) ;
F_118 ( V_82 , F_84 ( V_82 ) ) ;
}
static void F_223 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_407 = V_2 -> V_383 [ V_384 ] . V_385 ;
int V_438 ;
T_1 V_439 = V_440 |
V_441 |
V_442 |
V_443 |
V_444 ;
if ( V_8 -> V_72 . type == V_73 )
return;
if ( V_407 > 3 )
V_439 |= 2 << 29 ;
else if ( V_407 > 1 )
V_439 |= 1 << 29 ;
for ( V_438 = 0 ; V_438 < V_2 -> V_445 ; V_438 ++ )
F_45 ( V_8 , F_224 ( F_225 ( V_438 ) ) ,
V_439 ) ;
}
static void F_226 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_140 , V_446 ;
T_1 V_447 , V_448 ;
int V_11 ;
if ( ! ( V_2 -> V_100 & V_378 ) )
return;
V_448 = F_11 ( V_8 , V_449 ) ;
V_448 |= V_450 ;
V_448 &= ~ V_451 ;
V_448 |= F_225 ( 0 ) << V_452 ;
V_448 |= V_453 ;
F_45 ( V_8 , V_449 , V_448 ) ;
V_446 = F_225 ( 0 ) % 32 ;
V_140 = ( F_225 ( 0 ) >= 32 ) ? 1 : 0 ;
F_45 ( V_8 , F_227 ( V_140 ) , ( ~ 0 ) << V_446 ) ;
F_45 ( V_8 , F_227 ( V_140 ^ 1 ) , V_140 - 1 ) ;
F_45 ( V_8 , F_228 ( V_140 ) , ( ~ 0 ) << V_446 ) ;
F_45 ( V_8 , F_228 ( V_140 ^ 1 ) , V_140 - 1 ) ;
F_45 ( V_8 , V_454 , V_455 ) ;
V_8 -> V_72 . V_308 . V_456 ( V_8 , 0 , F_225 ( 0 ) ) ;
switch ( V_2 -> V_383 [ V_457 ] . V_79 ) {
case V_458 :
V_447 = V_459 ;
break;
case V_460 :
V_447 = V_461 ;
break;
default:
V_447 = V_462 ;
break;
}
F_45 ( V_8 , V_463 , V_447 ) ;
F_45 ( V_8 , V_454 , V_455 ) ;
V_8 -> V_72 . V_308 . V_464 ( V_8 , ( V_2 -> V_271 != 0 ) ,
V_2 -> V_271 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_271 ; V_11 ++ ) {
if ( ! V_2 -> V_465 [ V_11 ] . V_466 )
F_229 ( V_2 -> V_18 , V_11 , false ) ;
}
}
static void F_230 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_18 = V_2 -> V_18 ;
int V_467 = V_18 -> V_265 + V_208 + V_436 ;
struct V_20 * V_30 ;
int V_11 ;
T_1 V_468 , V_469 ;
#ifdef F_122
if ( ( V_2 -> V_100 & V_470 ) &&
( V_467 < V_471 ) )
V_467 = V_471 ;
#endif
V_468 = F_11 ( V_8 , V_472 ) ;
if ( V_467 != ( V_468 >> V_473 ) ) {
V_468 &= ~ V_474 ;
V_468 |= V_467 << V_473 ;
F_45 ( V_8 , V_472 , V_468 ) ;
}
V_467 += V_211 ;
V_469 = F_11 ( V_8 , V_475 ) ;
V_469 |= V_476 ;
F_45 ( V_8 , V_475 , V_469 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
V_30 = V_2 -> V_30 [ V_11 ] ;
if ( V_2 -> V_115 & V_477 )
F_231 ( V_30 ) ;
else
F_232 ( V_30 ) ;
}
}
static void F_233 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_478 = F_11 ( V_8 , V_479 ) ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_478 |= V_480 ;
break;
case V_75 :
case V_76 :
F_45 ( V_8 , V_481 ,
( V_482 | F_11 ( V_8 , V_481 ) ) ) ;
V_478 &= ~ V_483 ;
V_478 |= ( V_484 | V_485 ) ;
V_478 |= V_486 ;
break;
default:
return;
}
F_45 ( V_8 , V_479 , V_478 ) ;
}
static void F_234 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_11 ;
T_1 V_145 ;
V_145 = F_11 ( V_8 , V_487 ) ;
F_45 ( V_8 , V_487 , V_145 & ~ V_488 ) ;
F_223 ( V_2 ) ;
F_233 ( V_2 ) ;
F_214 ( V_2 ) ;
F_230 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ )
F_222 ( V_2 , V_2 -> V_30 [ V_11 ] ) ;
if ( V_8 -> V_72 . type == V_73 )
V_145 |= V_489 ;
V_145 |= V_488 ;
V_8 -> V_72 . V_308 . V_490 ( V_8 , V_145 ) ;
}
static int F_235 ( struct V_17 * V_18 , T_5 V_229 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
V_8 -> V_72 . V_308 . V_491 ( & V_2 -> V_8 , V_229 , F_225 ( 0 ) , true ) ;
F_206 ( V_229 , V_2 -> V_492 ) ;
return 0 ;
}
static int F_236 ( struct V_17 * V_18 , T_5 V_229 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
V_8 -> V_72 . V_308 . V_491 ( & V_2 -> V_8 , V_229 , F_225 ( 0 ) , false ) ;
F_8 ( V_229 , V_2 -> V_492 ) ;
return 0 ;
}
static void F_237 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_493 ;
V_493 = F_11 ( V_8 , V_494 ) ;
V_493 &= ~ ( V_495 | V_496 ) ;
F_45 ( V_8 , V_494 , V_493 ) ;
}
static void F_238 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_493 ;
V_493 = F_11 ( V_8 , V_494 ) ;
V_493 |= V_495 ;
V_493 &= ~ V_496 ;
F_45 ( V_8 , V_494 , V_493 ) ;
}
static void F_239 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_493 ;
int V_11 , V_12 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_493 = F_11 ( V_8 , V_494 ) ;
V_493 &= ~ V_497 ;
F_45 ( V_8 , V_494 , V_493 ) ;
break;
case V_75 :
case V_76 :
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
V_12 = V_2 -> V_30 [ V_11 ] -> V_108 ;
V_493 = F_11 ( V_8 , F_16 ( V_12 ) ) ;
V_493 &= ~ V_498 ;
F_45 ( V_8 , F_16 ( V_12 ) , V_493 ) ;
}
break;
default:
break;
}
}
static void F_240 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_493 ;
int V_11 , V_12 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_493 = F_11 ( V_8 , V_494 ) ;
V_493 |= V_497 ;
F_45 ( V_8 , V_494 , V_493 ) ;
break;
case V_75 :
case V_76 :
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
V_12 = V_2 -> V_30 [ V_11 ] -> V_108 ;
V_493 = F_11 ( V_8 , F_16 ( V_12 ) ) ;
V_493 |= V_498 ;
F_45 ( V_8 , F_16 ( V_12 ) , V_493 ) ;
}
break;
default:
break;
}
}
static void F_241 ( struct V_1 * V_2 )
{
T_5 V_229 ;
F_235 ( V_2 -> V_18 , 0 ) ;
F_242 (vid, adapter->active_vlans, VLAN_N_VID)
F_235 ( V_2 -> V_18 , V_229 ) ;
}
static int F_243 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
unsigned int V_499 = V_8 -> V_72 . V_500 - 1 ;
int V_52 = 0 ;
if ( V_2 -> V_100 & V_378 )
V_499 = V_501 - 1 ;
if ( F_244 ( V_18 ) > V_499 )
return - V_502 ;
if ( ! F_245 ( V_18 ) ) {
struct V_503 * V_504 ;
if ( ! V_8 -> V_72 . V_308 . V_505 )
return - V_502 ;
F_246 (ha, netdev) {
if ( ! V_499 )
break;
V_8 -> V_72 . V_308 . V_505 ( V_8 , V_499 -- , V_504 -> V_506 ,
F_225 ( 0 ) , V_507 ) ;
V_52 ++ ;
}
}
for (; V_499 > 0 ; V_499 -- )
V_8 -> V_72 . V_308 . V_508 ( V_8 , V_499 ) ;
return V_52 ;
}
void F_247 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_509 , V_510 = V_511 | V_512 ;
int V_52 ;
V_509 = F_11 ( V_8 , V_513 ) ;
V_509 &= ~ V_514 ;
V_509 |= V_515 ;
V_509 |= V_516 ;
V_509 |= V_517 ;
V_509 &= ~ ( V_518 | V_519 ) ;
if ( V_18 -> V_100 & V_520 ) {
V_8 -> V_521 . V_522 = true ;
V_509 |= ( V_518 | V_519 ) ;
V_510 |= ( V_523 | V_524 ) ;
F_237 ( V_2 ) ;
} else {
if ( V_18 -> V_100 & V_525 ) {
V_509 |= V_519 ;
V_510 |= V_524 ;
} else {
V_8 -> V_72 . V_308 . V_526 ( V_8 , V_18 ) ;
V_510 |= V_527 ;
}
F_238 ( V_2 ) ;
V_8 -> V_521 . V_522 = false ;
}
V_52 = F_243 ( V_18 ) ;
if ( V_52 < 0 ) {
V_509 |= V_518 ;
V_510 |= V_523 ;
}
if ( V_2 -> V_271 )
F_248 ( V_2 ) ;
if ( V_8 -> V_72 . type != V_73 ) {
V_510 |= F_11 ( V_8 , F_249 ( F_225 ( 0 ) ) ) &
~ ( V_524 | V_527 |
V_523 ) ;
F_45 ( V_8 , F_249 ( F_225 ( 0 ) ) , V_510 ) ;
}
if ( V_2 -> V_18 -> V_160 & V_244 ) {
V_509 |= ( V_514 |
V_515 |
V_517 ) ;
V_509 &= ~ ( V_516 ) ;
}
F_45 ( V_8 , V_513 , V_509 ) ;
if ( V_18 -> V_160 & V_227 )
F_240 ( V_2 ) ;
else
F_239 ( V_2 ) ;
}
static void F_250 ( struct V_1 * V_2 )
{
int V_528 ;
for ( V_528 = 0 ; V_528 < V_2 -> V_153 ; V_528 ++ )
F_251 ( & V_2 -> V_118 [ V_528 ] -> V_231 ) ;
}
static void F_252 ( struct V_1 * V_2 )
{
int V_528 ;
for ( V_528 = 0 ; V_528 < V_2 -> V_153 ; V_528 ++ )
F_253 ( & V_2 -> V_118 [ V_528 ] -> V_231 ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_467 = V_2 -> V_18 -> V_265 + V_208 + V_436 ;
if ( ! ( V_2 -> V_100 & V_101 ) ) {
if ( V_8 -> V_72 . type == V_73 )
F_255 ( V_2 -> V_18 , 65536 ) ;
return;
}
if ( V_8 -> V_72 . type == V_73 )
F_255 ( V_2 -> V_18 , 32768 ) ;
V_8 -> V_72 . V_308 . V_491 ( & V_2 -> V_8 , 0 , 0 , true ) ;
#ifdef F_122
if ( V_2 -> V_18 -> V_160 & V_529 )
V_467 = F_169 ( V_467 , V_471 ) ;
#endif
if ( V_2 -> V_530 & V_531 ) {
F_256 ( V_8 , & V_2 -> V_97 , V_467 ,
V_532 ) ;
F_256 ( V_8 , & V_2 -> V_97 , V_467 ,
V_533 ) ;
F_257 ( V_8 , & V_2 -> V_97 ) ;
} else if ( V_2 -> V_534 && V_2 -> V_99 ) {
F_258 ( & V_2 -> V_8 ,
V_2 -> V_534 ,
V_467 ) ;
F_259 ( & V_2 -> V_8 ,
V_2 -> V_99 -> V_96 ,
V_2 -> V_534 -> V_535 ) ;
}
if ( V_8 -> V_72 . type != V_73 ) {
T_1 V_536 = 0 ;
T_5 V_407 = V_2 -> V_383 [ V_384 ] . V_385 - 1 ;
while ( V_407 ) {
V_536 ++ ;
V_407 >>= 1 ;
}
F_45 ( V_8 , V_537 , V_536 * 0x11111111 ) ;
}
}
static int F_260 ( struct V_1 * V_2 , int V_538 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_37 = V_2 -> V_18 ;
int V_341 , V_104 , V_539 , V_540 ;
T_1 V_541 , V_542 ;
V_104 = V_341 = V_37 -> V_265 + V_208 + V_436 + V_543 ;
#ifdef F_122
if ( ( V_37 -> V_160 & V_529 ) &&
( V_104 < V_471 ) &&
( V_538 == F_261 ( V_2 ) ) )
V_104 = V_471 ;
#endif
switch ( V_8 -> V_72 . type ) {
case V_76 :
V_541 = F_262 ( V_341 , V_104 ) ;
break;
default:
V_541 = F_263 ( V_341 , V_104 ) ;
break;
}
if ( V_2 -> V_100 & V_378 )
V_541 += F_264 ( V_104 ) ;
V_539 = F_265 ( V_541 ) ;
V_542 = F_11 ( V_8 , F_266 ( V_538 ) ) >> 10 ;
V_540 = V_542 - V_539 ;
if ( V_540 < 0 ) {
F_267 ( V_133 , L_71
L_72
L_73 , V_538 ) ;
V_540 = V_104 + 1 ;
}
return V_540 ;
}
static int F_268 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_37 = V_2 -> V_18 ;
int V_104 ;
T_1 V_541 ;
V_104 = V_37 -> V_265 + V_208 + V_436 ;
switch ( V_8 -> V_72 . type ) {
case V_76 :
V_541 = F_269 ( V_104 ) ;
break;
default:
V_541 = F_270 ( V_104 ) ;
break;
}
return F_265 ( V_541 ) ;
}
static void F_271 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_544 = F_209 ( V_2 -> V_18 ) ;
int V_11 ;
if ( ! V_544 )
V_544 = 1 ;
V_8 -> V_87 . V_545 = F_268 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_544 ; V_11 ++ ) {
V_8 -> V_87 . V_546 [ V_11 ] = F_260 ( V_2 , V_11 ) ;
if ( V_8 -> V_87 . V_545 > V_8 -> V_87 . V_546 [ V_11 ] )
V_8 -> V_87 . V_545 = 0 ;
}
}
static void F_272 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_547 ;
T_4 V_104 = F_209 ( V_2 -> V_18 ) ;
if ( V_2 -> V_100 & V_335 ||
V_2 -> V_100 & V_548 )
V_547 = 32 << V_2 -> V_549 ;
else
V_547 = 0 ;
V_8 -> V_72 . V_308 . V_550 ( V_8 , V_104 , V_547 , V_551 ) ;
F_271 ( V_2 ) ;
}
static void F_273 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_552 * V_553 , * V_554 ;
struct V_555 * V_556 ;
F_274 ( & V_2 -> V_557 ) ;
if ( ! F_275 ( & V_2 -> V_558 ) )
F_276 ( V_8 , & V_2 -> V_559 ) ;
F_277 (filter, node, node2,
&adapter->fdir_filter_list, fdir_node) {
F_278 ( V_8 ,
& V_556 -> V_556 ,
V_556 -> V_560 ,
( V_556 -> V_561 == V_562 ) ?
V_562 :
V_2 -> V_30 [ V_556 -> V_561 ] -> V_108 ) ;
}
F_279 ( & V_2 -> V_557 ) ;
}
static void F_280 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
F_272 ( V_2 ) ;
#ifdef F_281
F_254 ( V_2 ) ;
#endif
F_247 ( V_2 -> V_18 ) ;
F_241 ( V_2 ) ;
switch ( V_8 -> V_72 . type ) {
case V_75 :
case V_76 :
V_8 -> V_72 . V_308 . V_563 ( V_8 ) ;
break;
default:
break;
}
if ( V_2 -> V_100 & V_335 ) {
F_282 ( & V_2 -> V_8 ,
V_2 -> V_549 ) ;
} else if ( V_2 -> V_100 & V_548 ) {
F_283 ( & V_2 -> V_8 ,
V_2 -> V_549 ) ;
F_273 ( V_2 ) ;
}
switch ( V_8 -> V_72 . type ) {
case V_75 :
case V_76 :
V_8 -> V_72 . V_308 . V_564 ( V_8 ) ;
break;
default:
break;
}
F_226 ( V_2 ) ;
#ifdef F_122
F_284 ( V_2 ) ;
#endif
F_210 ( V_2 ) ;
F_234 ( V_2 ) ;
}
static inline bool F_285 ( struct V_7 * V_8 )
{
switch ( V_8 -> V_312 . type ) {
case V_565 :
case V_566 :
case V_567 :
case V_568 :
case V_569 :
case V_570 :
case V_571 :
case V_572 :
return true ;
case V_573 :
if ( V_8 -> V_72 . type == V_73 )
return true ;
default:
return false ;
}
}
static void F_286 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_72 . type == V_73 )
V_2 -> V_115 |= V_574 ;
V_2 -> V_115 |= V_320 ;
}
static int F_287 ( struct V_7 * V_8 )
{
T_1 V_310 ;
bool V_575 , V_311 = false ;
T_1 V_114 = V_576 ;
if ( V_8 -> V_72 . V_308 . V_309 )
V_114 = V_8 -> V_72 . V_308 . V_309 ( V_8 , & V_310 , & V_311 , false ) ;
if ( V_114 )
goto V_577;
V_310 = V_8 -> V_312 . V_578 ;
if ( ( ! V_310 ) && ( V_8 -> V_72 . V_308 . V_579 ) )
V_114 = V_8 -> V_72 . V_308 . V_579 ( V_8 , & V_310 ,
& V_575 ) ;
if ( V_114 )
goto V_577;
if ( V_8 -> V_72 . V_308 . V_580 )
V_114 = V_8 -> V_72 . V_308 . V_580 ( V_8 , V_310 , V_575 , V_311 ) ;
V_577:
return V_114 ;
}
static void F_288 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_581 = 0 ;
if ( V_2 -> V_100 & V_359 ) {
V_581 = V_582 | V_583 |
V_584 ;
V_581 |= V_585 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
F_45 ( V_8 , V_586 , V_587 ) ;
break;
case V_75 :
case V_76 :
default:
F_45 ( V_8 , F_289 ( 0 ) , 0xFFFFFFFF ) ;
F_45 ( V_8 , F_289 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_45 ( V_8 , V_586 , V_587 ) ;
}
if ( V_2 -> V_100 & V_378 ) {
V_581 &= ~ V_588 ;
switch ( V_2 -> V_383 [ V_457 ] . V_79 ) {
case V_458 :
V_581 |= V_589 ;
break;
case V_460 :
V_581 |= V_590 ;
break;
default:
V_581 |= V_591 ;
break;
}
}
if ( V_2 -> V_115 & V_302 ) {
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
V_581 |= V_592 ;
break;
case V_76 :
V_581 |= V_331 ;
break;
default:
break;
}
}
if ( V_2 -> V_100 & V_315 )
V_581 |= V_593 ;
if ( V_8 -> V_72 . type == V_75 ) {
V_581 |= V_593 ;
V_581 |= V_594 ;
}
F_45 ( V_8 , V_595 , V_581 ) ;
}
static void F_290 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_351 ;
T_1 V_64 ;
F_46 ( V_2 ) ;
F_288 ( V_2 ) ;
if ( V_2 -> V_100 & V_359 )
F_164 ( V_2 ) ;
else
F_203 ( V_2 ) ;
if ( V_8 -> V_72 . V_308 . V_596 &&
( ( V_8 -> V_312 . V_597 ) ||
( ( V_8 -> V_72 . V_308 . V_598 ( V_8 ) == V_599 ) &&
( V_8 -> V_72 . type == V_75 ) ) ) )
V_8 -> V_72 . V_308 . V_596 ( V_8 ) ;
F_8 ( V_3 , & V_2 -> V_4 ) ;
F_250 ( V_2 ) ;
if ( F_285 ( V_8 ) ) {
F_286 ( V_2 ) ;
} else {
V_351 = F_287 ( V_8 ) ;
if ( V_351 )
F_77 ( V_135 , L_74 , V_351 ) ;
}
F_11 ( V_8 , V_317 ) ;
F_181 ( V_2 , true , true ) ;
if ( V_2 -> V_100 & V_315 ) {
T_1 V_600 = F_11 ( V_8 , V_601 ) ;
if ( V_600 & V_602 )
F_171 ( V_133 , L_54 ) ;
}
F_291 ( V_2 -> V_18 ) ;
V_2 -> V_100 |= V_323 ;
V_2 -> V_324 = V_134 ;
F_292 ( & V_2 -> V_603 , V_134 ) ;
V_64 = F_11 ( V_8 , V_65 ) ;
V_64 |= V_604 ;
F_45 ( V_8 , V_65 , V_64 ) ;
}
void F_293 ( struct V_1 * V_2 )
{
F_294 ( F_295 () ) ;
V_2 -> V_18 -> V_38 = V_134 ;
while ( F_3 ( V_605 , & V_2 -> V_4 ) )
F_207 ( 1000 , 2000 ) ;
F_296 ( V_2 ) ;
if ( V_2 -> V_100 & V_378 )
F_297 ( 2000 ) ;
F_298 ( V_2 ) ;
F_8 ( V_605 , & V_2 -> V_4 ) ;
}
void F_298 ( struct V_1 * V_2 )
{
F_280 ( V_2 ) ;
F_290 ( V_2 ) ;
}
void F_299 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_351 ;
while ( F_3 ( V_606 , & V_2 -> V_4 ) )
F_207 ( 1000 , 2000 ) ;
V_2 -> V_115 &= ~ ( V_574 |
V_320 ) ;
V_2 -> V_100 &= ~ V_321 ;
V_351 = V_8 -> V_72 . V_308 . V_607 ( V_8 ) ;
switch ( V_351 ) {
case 0 :
case V_608 :
case V_609 :
break;
case V_610 :
F_300 ( L_75 ) ;
break;
case V_611 :
F_301 ( L_76
L_77
L_78
L_79
L_80
L_81 ) ;
break;
default:
F_300 ( L_82 , V_351 ) ;
}
F_8 ( V_606 , & V_2 -> V_4 ) ;
V_8 -> V_72 . V_308 . V_505 ( V_8 , 0 , V_8 -> V_72 . V_506 , F_225 ( 0 ) , V_507 ) ;
if ( V_8 -> V_72 . V_612 )
V_8 -> V_72 . V_308 . V_613 ( V_8 , F_225 ( 0 ) ) ;
}
static void F_302 ( struct V_20 * V_30 )
{
struct V_33 * V_250 = V_30 -> V_34 ;
T_5 V_11 ;
for ( V_11 = 0 ; V_11 < V_30 -> V_52 ; V_11 += 2 ) {
V_250 [ 0 ] . V_63 = 0 ;
V_250 [ 1 ] . V_63 = F_43 ( V_30 ) ;
V_250 = & V_250 [ 2 ] ;
}
}
static void F_303 ( struct V_20 * V_30 )
{
struct V_154 * V_37 = V_30 -> V_37 ;
unsigned long V_255 ;
T_5 V_11 ;
if ( ! V_30 -> V_34 )
return;
for ( V_11 = 0 ; V_11 < V_30 -> V_52 ; V_11 ++ ) {
struct V_33 * V_250 ;
V_250 = & V_30 -> V_34 [ V_11 ] ;
if ( V_250 -> V_53 ) {
struct V_159 * V_53 = V_250 -> V_53 ;
if ( F_125 ( V_53 ) -> V_242 ) {
F_54 ( V_37 ,
F_125 ( V_53 ) -> V_45 ,
F_43 ( V_30 ) ,
V_191 ) ;
F_125 ( V_53 ) -> V_242 = false ;
}
F_304 ( V_53 ) ;
}
V_250 -> V_53 = NULL ;
if ( V_250 -> V_45 )
F_54 ( V_37 , V_250 -> V_45 ,
F_115 ( V_30 ) ,
V_191 ) ;
V_250 -> V_45 = 0 ;
if ( V_250 -> V_62 )
F_117 ( V_250 -> V_62 ,
F_113 ( V_30 ) ) ;
V_250 -> V_62 = NULL ;
}
V_255 = sizeof( struct V_33 ) * V_30 -> V_52 ;
memset ( V_30 -> V_34 , 0 , V_255 ) ;
F_302 ( V_30 ) ;
memset ( V_30 -> V_51 , 0 , V_30 -> V_255 ) ;
V_30 -> V_185 = 0 ;
V_30 -> V_43 = 0 ;
V_30 -> V_44 = 0 ;
}
static void F_305 ( struct V_20 * V_21 )
{
struct V_22 * V_42 ;
unsigned long V_255 ;
T_5 V_11 ;
if ( ! V_21 -> V_42 )
return;
for ( V_11 = 0 ; V_11 < V_21 -> V_52 ; V_11 ++ ) {
V_42 = & V_21 -> V_42 [ V_11 ] ;
F_51 ( V_21 , V_42 ) ;
}
F_306 ( F_81 ( V_21 ) ) ;
V_255 = sizeof( struct V_22 ) * V_21 -> V_52 ;
memset ( V_21 -> V_42 , 0 , V_255 ) ;
memset ( V_21 -> V_51 , 0 , V_21 -> V_255 ) ;
V_21 -> V_44 = 0 ;
V_21 -> V_43 = 0 ;
}
static void F_307 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ )
F_303 ( V_2 -> V_30 [ V_11 ] ) ;
}
static void F_308 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_305 ( V_2 -> V_21 [ V_11 ] ) ;
}
static void F_309 ( struct V_1 * V_2 )
{
struct V_552 * V_553 , * V_554 ;
struct V_555 * V_556 ;
F_274 ( & V_2 -> V_557 ) ;
F_277 (filter, node, node2,
&adapter->fdir_filter_list, fdir_node) {
F_310 ( & V_556 -> V_614 ) ;
F_197 ( V_556 ) ;
}
V_2 -> V_615 = 0 ;
F_279 ( & V_2 -> V_557 ) ;
}
void F_296 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_145 ;
int V_11 ;
F_206 ( V_3 , & V_2 -> V_4 ) ;
V_145 = F_11 ( V_8 , V_487 ) ;
F_45 ( V_8 , V_487 , V_145 & ~ V_488 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ )
F_220 ( V_2 , V_2 -> V_30 [ V_11 ] ) ;
F_207 ( 10000 , 20000 ) ;
F_311 ( V_18 ) ;
F_312 ( V_18 ) ;
F_313 ( V_18 ) ;
F_201 ( V_2 ) ;
F_252 ( V_2 ) ;
V_2 -> V_115 &= ~ ( V_336 |
V_116 ) ;
V_2 -> V_100 &= ~ V_323 ;
F_314 ( & V_2 -> V_603 ) ;
if ( V_2 -> V_271 ) {
F_45 ( & V_2 -> V_8 , V_273 , 0 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_271 ; V_11 ++ )
V_2 -> V_465 [ V_11 ] . V_616 = false ;
F_315 ( V_2 ) ;
F_316 ( V_2 ) ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
T_4 V_108 = V_2 -> V_21 [ V_11 ] -> V_108 ;
F_45 ( V_8 , F_24 ( V_108 ) , V_617 ) ;
}
switch ( V_8 -> V_72 . type ) {
case V_75 :
case V_76 :
F_45 ( V_8 , V_394 ,
( F_11 ( V_8 , V_394 ) &
~ V_395 ) ) ;
break;
default:
break;
}
if ( ! F_317 ( V_2 -> V_36 ) )
F_299 ( V_2 ) ;
if ( V_8 -> V_72 . V_308 . V_618 &&
( ( V_8 -> V_312 . V_597 ) ||
( ( V_8 -> V_72 . V_308 . V_598 ( V_8 ) == V_599 ) &&
( V_8 -> V_72 . type == V_75 ) ) ) )
V_8 -> V_72 . V_308 . V_618 ( V_8 ) ;
F_308 ( V_2 ) ;
F_307 ( V_2 ) ;
#ifdef F_190
F_97 ( V_2 ) ;
#endif
}
static void F_318 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
F_65 ( V_2 ) ;
}
static int T_11 F_319 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_619 * V_36 = V_2 -> V_36 ;
unsigned int V_165 ;
#ifdef F_281
int V_12 ;
struct V_620 * V_104 ;
#endif
V_8 -> V_621 = V_36 -> V_622 ;
V_8 -> V_304 = V_36 -> V_154 ;
V_8 -> V_623 = V_36 -> V_624 ;
V_8 -> V_625 = V_36 -> V_626 ;
V_8 -> V_627 = V_36 -> V_628 ;
V_165 = F_320 ( int , V_629 , F_321 () ) ;
V_2 -> V_383 [ V_384 ] . V_630 = V_165 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
if ( V_8 -> V_304 == V_631 )
V_2 -> V_100 |= V_315 ;
V_2 -> V_632 = V_633 ;
break;
case V_76 :
V_2 -> V_115 |= V_302 ;
case V_75 :
V_2 -> V_632 = V_634 ;
V_2 -> V_115 |= V_635 ;
V_2 -> V_115 |= V_477 ;
if ( V_8 -> V_304 == V_305 )
V_2 -> V_115 |= V_302 ;
V_2 -> V_369 = 20 ;
V_2 -> V_383 [ V_636 ] . V_630 =
V_637 ;
V_2 -> V_549 = V_638 ;
#ifdef F_122
V_2 -> V_100 |= V_639 ;
V_2 -> V_100 &= ~ V_470 ;
#ifdef F_281
V_2 -> V_640 . V_641 = V_642 ;
#endif
#endif
break;
default:
break;
}
#ifdef F_122
F_322 ( & V_2 -> V_640 . V_643 ) ;
#endif
F_322 ( & V_2 -> V_557 ) ;
#ifdef F_281
switch ( V_8 -> V_72 . type ) {
case V_76 :
V_2 -> V_97 . V_644 . V_645 = V_646 ;
V_2 -> V_97 . V_644 . V_647 = V_646 ;
break;
default:
V_2 -> V_97 . V_644 . V_645 = V_648 ;
V_2 -> V_97 . V_644 . V_647 = V_648 ;
break;
}
for ( V_12 = 0 ; V_12 < V_648 ; V_12 ++ ) {
V_104 = & V_2 -> V_97 . V_649 [ V_12 ] ;
V_104 -> V_650 [ V_532 ] . V_651 = 0 ;
V_104 -> V_650 [ V_532 ] . V_652 = 12 + ( V_12 & 1 ) ;
V_104 -> V_650 [ V_533 ] . V_651 = 0 ;
V_104 -> V_650 [ V_533 ] . V_652 = 12 + ( V_12 & 1 ) ;
V_104 -> V_653 = V_654 ;
}
V_104 = & V_2 -> V_97 . V_649 [ 0 ] ;
V_104 -> V_650 [ V_532 ] . V_655 = 0xFF ;
V_104 -> V_650 [ V_533 ] . V_655 = 0xFF ;
V_2 -> V_97 . V_656 [ V_532 ] [ 0 ] = 100 ;
V_2 -> V_97 . V_656 [ V_533 ] [ 0 ] = 100 ;
V_2 -> V_97 . V_98 = false ;
V_2 -> V_657 = 0x00 ;
V_2 -> V_530 = V_658 | V_531 ;
memcpy ( & V_2 -> V_659 , & V_2 -> V_97 ,
sizeof( V_2 -> V_659 ) ) ;
#endif
V_8 -> V_87 . V_660 = V_89 ;
V_8 -> V_87 . V_88 = V_89 ;
F_271 ( V_2 ) ;
V_8 -> V_87 . V_661 = V_662 ;
V_8 -> V_87 . V_663 = true ;
V_8 -> V_87 . V_664 = false ;
#ifdef F_323
if ( V_8 -> V_72 . type != V_73 )
V_2 -> V_271 = ( V_665 > 63 ) ? 0 : V_665 ;
#endif
V_2 -> V_277 = 1 ;
V_2 -> V_274 = 1 ;
V_2 -> V_666 = V_667 ;
V_2 -> V_668 = V_669 ;
V_2 -> V_670 = V_671 ;
if ( F_324 ( V_8 ) ) {
F_300 ( L_83 ) ;
return - V_672 ;
}
F_206 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
}
int F_325 ( struct V_20 * V_21 )
{
struct V_154 * V_37 = V_21 -> V_37 ;
int V_673 = F_326 ( V_37 ) ;
int V_674 = - 1 ;
int V_255 ;
V_255 = sizeof( struct V_22 ) * V_21 -> V_52 ;
if ( V_21 -> V_118 )
V_674 = V_21 -> V_118 -> V_674 ;
V_21 -> V_42 = F_327 ( V_255 , V_674 ) ;
if ( ! V_21 -> V_42 )
V_21 -> V_42 = F_328 ( V_255 ) ;
if ( ! V_21 -> V_42 )
goto V_351;
V_21 -> V_255 = V_21 -> V_52 * sizeof( union V_24 ) ;
V_21 -> V_255 = F_146 ( V_21 -> V_255 , 4096 ) ;
F_329 ( V_37 , V_674 ) ;
V_21 -> V_51 = F_330 ( V_37 ,
V_21 -> V_255 ,
& V_21 -> V_45 ,
V_675 ) ;
F_329 ( V_37 , V_673 ) ;
if ( ! V_21 -> V_51 )
V_21 -> V_51 = F_330 ( V_37 , V_21 -> V_255 ,
& V_21 -> V_45 , V_675 ) ;
if ( ! V_21 -> V_51 )
goto V_351;
V_21 -> V_44 = 0 ;
V_21 -> V_43 = 0 ;
return 0 ;
V_351:
F_331 ( V_21 -> V_42 ) ;
V_21 -> V_42 = NULL ;
F_332 ( V_37 , L_84 ) ;
return - V_502 ;
}
static int F_333 ( struct V_1 * V_2 )
{
int V_11 , V_351 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
V_351 = F_325 ( V_2 -> V_21 [ V_11 ] ) ;
if ( ! V_351 )
continue;
F_77 ( V_135 , L_85 , V_11 ) ;
goto V_676;
}
return 0 ;
V_676:
while ( V_11 -- )
F_334 ( V_2 -> V_21 [ V_11 ] ) ;
return V_351 ;
}
int F_335 ( struct V_20 * V_30 )
{
struct V_154 * V_37 = V_30 -> V_37 ;
int V_673 = F_326 ( V_37 ) ;
int V_674 = - 1 ;
int V_255 ;
V_255 = sizeof( struct V_33 ) * V_30 -> V_52 ;
if ( V_30 -> V_118 )
V_674 = V_30 -> V_118 -> V_674 ;
V_30 -> V_34 = F_327 ( V_255 , V_674 ) ;
if ( ! V_30 -> V_34 )
V_30 -> V_34 = F_328 ( V_255 ) ;
if ( ! V_30 -> V_34 )
goto V_351;
V_30 -> V_255 = V_30 -> V_52 * sizeof( union V_31 ) ;
V_30 -> V_255 = F_146 ( V_30 -> V_255 , 4096 ) ;
F_329 ( V_37 , V_674 ) ;
V_30 -> V_51 = F_330 ( V_37 ,
V_30 -> V_255 ,
& V_30 -> V_45 ,
V_675 ) ;
F_329 ( V_37 , V_673 ) ;
if ( ! V_30 -> V_51 )
V_30 -> V_51 = F_330 ( V_37 , V_30 -> V_255 ,
& V_30 -> V_45 , V_675 ) ;
if ( ! V_30 -> V_51 )
goto V_351;
V_30 -> V_43 = 0 ;
V_30 -> V_44 = 0 ;
F_302 ( V_30 ) ;
return 0 ;
V_351:
F_331 ( V_30 -> V_34 ) ;
V_30 -> V_34 = NULL ;
F_332 ( V_37 , L_86 ) ;
return - V_502 ;
}
static int F_336 ( struct V_1 * V_2 )
{
int V_11 , V_351 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
V_351 = F_335 ( V_2 -> V_30 [ V_11 ] ) ;
if ( ! V_351 )
continue;
F_77 ( V_135 , L_87 , V_11 ) ;
goto V_677;
}
#ifdef F_122
V_351 = F_337 ( V_2 ) ;
if ( ! V_351 )
#endif
return 0 ;
V_677:
while ( V_11 -- )
F_338 ( V_2 -> V_30 [ V_11 ] ) ;
return V_351 ;
}
void F_334 ( struct V_20 * V_21 )
{
F_305 ( V_21 ) ;
F_331 ( V_21 -> V_42 ) ;
V_21 -> V_42 = NULL ;
if ( ! V_21 -> V_51 )
return;
F_339 ( V_21 -> V_37 , V_21 -> V_255 ,
V_21 -> V_51 , V_21 -> V_45 ) ;
V_21 -> V_51 = NULL ;
}
static void F_340 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
if ( V_2 -> V_21 [ V_11 ] -> V_51 )
F_334 ( V_2 -> V_21 [ V_11 ] ) ;
}
void F_338 ( struct V_20 * V_30 )
{
F_303 ( V_30 ) ;
F_331 ( V_30 -> V_34 ) ;
V_30 -> V_34 = NULL ;
if ( ! V_30 -> V_51 )
return;
F_339 ( V_30 -> V_37 , V_30 -> V_255 ,
V_30 -> V_51 , V_30 -> V_45 ) ;
V_30 -> V_51 = NULL ;
}
static void F_341 ( struct V_1 * V_2 )
{
int V_11 ;
#ifdef F_122
F_342 ( V_2 ) ;
#endif
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ )
if ( V_2 -> V_30 [ V_11 ] -> V_51 )
F_338 ( V_2 -> V_30 [ V_11 ] ) ;
}
static int F_343 ( struct V_17 * V_18 , int V_678 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
int V_467 = V_678 + V_208 + V_436 ;
if ( ( V_678 < 68 ) || ( V_467 > V_679 ) )
return - V_680 ;
if ( ( V_2 -> V_100 & V_378 ) &&
( V_2 -> V_8 . V_72 . type == V_75 ) &&
( V_467 > V_681 ) )
return - V_680 ;
F_79 ( V_135 , L_88 , V_18 -> V_265 , V_678 ) ;
V_18 -> V_265 = V_678 ;
if ( F_31 ( V_18 ) )
F_293 ( V_2 ) ;
return 0 ;
}
static int F_344 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
int V_351 ;
if ( F_2 ( V_682 , & V_2 -> V_4 ) )
return - V_683 ;
F_312 ( V_18 ) ;
V_351 = F_333 ( V_2 ) ;
if ( V_351 )
goto V_676;
V_351 = F_336 ( V_2 ) ;
if ( V_351 )
goto V_677;
F_280 ( V_2 ) ;
V_351 = F_199 ( V_2 ) ;
if ( V_351 )
goto V_684;
V_351 = F_345 ( V_18 ,
V_2 -> V_445 > 1 ? 1 :
V_2 -> V_41 ) ;
if ( V_351 )
goto V_685;
V_351 = F_346 ( V_18 ,
V_2 -> V_445 > 1 ? 1 :
V_2 -> V_57 ) ;
if ( V_351 )
goto V_685;
F_290 ( V_2 ) ;
return 0 ;
V_685:
F_200 ( V_2 ) ;
V_684:
F_341 ( V_2 ) ;
V_677:
F_340 ( V_2 ) ;
V_676:
F_299 ( V_2 ) ;
return V_351 ;
}
static int F_347 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
F_296 ( V_2 ) ;
F_200 ( V_2 ) ;
F_309 ( V_2 ) ;
F_340 ( V_2 ) ;
F_341 ( V_2 ) ;
F_44 ( V_2 ) ;
return 0 ;
}
static int F_348 ( struct V_619 * V_36 )
{
struct V_1 * V_2 = F_349 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_351 ;
F_350 ( V_36 , V_686 ) ;
F_351 ( V_36 ) ;
F_352 ( V_36 ) ;
V_351 = F_353 ( V_36 ) ;
if ( V_351 ) {
F_300 ( L_89 ) ;
return V_351 ;
}
F_354 ( V_36 ) ;
F_355 ( V_36 , false ) ;
F_299 ( V_2 ) ;
F_45 ( & V_2 -> V_8 , V_687 , ~ 0 ) ;
F_356 () ;
V_351 = F_357 ( V_2 ) ;
if ( ! V_351 && F_31 ( V_18 ) )
V_351 = F_344 ( V_18 ) ;
F_358 () ;
if ( V_351 )
return V_351 ;
F_359 ( V_18 ) ;
return 0 ;
}
static int F_360 ( struct V_619 * V_36 , bool * V_688 )
{
struct V_1 * V_2 = F_349 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_689 , V_509 ;
T_1 V_690 = V_2 -> V_691 ;
#ifdef F_361
int V_692 = 0 ;
#endif
F_362 ( V_18 ) ;
if ( F_31 ( V_18 ) ) {
F_356 () ;
F_296 ( V_2 ) ;
F_200 ( V_2 ) ;
F_340 ( V_2 ) ;
F_341 ( V_2 ) ;
F_358 () ;
}
F_363 ( V_2 ) ;
#ifdef F_361
V_692 = F_352 ( V_36 ) ;
if ( V_692 )
return V_692 ;
#endif
if ( V_690 ) {
F_247 ( V_18 ) ;
if ( V_8 -> V_72 . V_308 . V_596 &&
( V_8 -> V_312 . V_597 ||
( V_8 -> V_72 . V_308 . V_598 ( V_8 ) == V_599 &&
V_8 -> V_72 . type == V_75 ) ) )
V_8 -> V_72 . V_308 . V_596 ( V_8 ) ;
if ( V_690 & V_693 ) {
V_509 = F_11 ( V_8 , V_513 ) ;
V_509 |= V_519 ;
F_45 ( V_8 , V_513 , V_509 ) ;
}
V_689 = F_11 ( V_8 , V_694 ) ;
V_689 |= V_695 ;
F_45 ( V_8 , V_694 , V_689 ) ;
F_45 ( V_8 , V_696 , V_690 ) ;
} else {
F_45 ( V_8 , V_697 , 0 ) ;
F_45 ( V_8 , V_696 , 0 ) ;
}
switch ( V_8 -> V_72 . type ) {
case V_73 :
F_355 ( V_36 , false ) ;
break;
case V_75 :
case V_76 :
F_355 ( V_36 , ! ! V_690 ) ;
break;
default:
break;
}
* V_688 = ! ! V_690 ;
F_44 ( V_2 ) ;
F_364 ( V_36 ) ;
return 0 ;
}
static int F_365 ( struct V_619 * V_36 , T_12 V_4 )
{
int V_692 ;
bool V_698 ;
V_692 = F_360 ( V_36 , & V_698 ) ;
if ( V_692 )
return V_692 ;
if ( V_698 ) {
F_366 ( V_36 ) ;
} else {
F_355 ( V_36 , false ) ;
F_350 ( V_36 , V_699 ) ;
}
return 0 ;
}
static void F_367 ( struct V_619 * V_36 )
{
bool V_698 ;
F_360 ( V_36 , & V_698 ) ;
if ( V_700 == V_701 ) {
F_355 ( V_36 , V_698 ) ;
F_350 ( V_36 , V_699 ) ;
}
}
void F_368 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_84 * V_85 = & V_2 -> V_86 ;
T_2 V_702 = 0 ;
T_1 V_11 , V_703 = 0 , V_704 , V_705 , V_706 , V_707 , V_708 ;
T_2 V_236 = 0 , V_137 = 0 , V_709 = 0 ;
T_2 V_190 = 0 , V_262 = 0 ;
T_2 V_132 = 0 , V_106 = 0 , V_710 = 0 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_605 , & V_2 -> V_4 ) )
return;
if ( V_2 -> V_115 & V_477 ) {
T_2 V_225 = 0 ;
T_2 V_226 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
V_225 += V_2 -> V_30 [ V_11 ] -> V_176 . V_225 ;
V_226 += V_2 -> V_30 [ V_11 ] -> V_176 . V_226 ;
}
V_2 -> V_711 = V_225 ;
V_2 -> V_712 = V_226 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
struct V_20 * V_30 = V_2 -> V_30 [ V_11 ] ;
V_236 += V_30 -> V_176 . V_236 ;
V_190 += V_30 -> V_176 . V_190 ;
V_262 += V_30 -> V_176 . V_262 ;
V_710 += V_30 -> V_176 . V_177 ;
V_132 += V_30 -> V_86 . V_132 ;
V_106 += V_30 -> V_86 . V_106 ;
}
V_2 -> V_236 = V_236 ;
V_2 -> V_190 = V_190 ;
V_2 -> V_262 = V_262 ;
V_2 -> V_710 = V_710 ;
V_18 -> V_86 . V_713 = V_132 ;
V_18 -> V_86 . V_714 = V_106 ;
V_132 = 0 ;
V_106 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_21 = V_2 -> V_21 [ V_11 ] ;
V_137 += V_21 -> V_112 . V_137 ;
V_709 += V_21 -> V_112 . V_709 ;
V_132 += V_21 -> V_86 . V_132 ;
V_106 += V_21 -> V_86 . V_106 ;
}
V_2 -> V_137 = V_137 ;
V_2 -> V_709 = V_709 ;
V_18 -> V_86 . V_715 = V_132 ;
V_18 -> V_86 . V_716 = V_106 ;
V_85 -> V_717 += F_11 ( V_8 , V_718 ) ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_704 = F_11 ( V_8 , F_369 ( V_11 ) ) ;
V_703 += V_704 ;
V_85 -> V_704 [ V_11 ] += V_704 ;
V_702 += V_85 -> V_704 [ V_11 ] ;
V_85 -> V_719 [ V_11 ] += F_11 ( V_8 , F_370 ( V_11 ) ) ;
V_85 -> V_720 [ V_11 ] += F_11 ( V_8 , F_371 ( V_11 ) ) ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_85 -> V_721 [ V_11 ] += F_11 ( V_8 , F_372 ( V_11 ) ) ;
V_85 -> V_722 [ V_11 ] += F_11 ( V_8 , F_373 ( V_11 ) ) ;
V_85 -> V_723 [ V_11 ] += F_11 ( V_8 , F_374 ( V_11 ) ) ;
V_85 -> V_724 [ V_11 ] +=
F_11 ( V_8 , F_375 ( V_11 ) ) ;
break;
case V_75 :
case V_76 :
V_85 -> V_724 [ V_11 ] +=
F_11 ( V_8 , F_376 ( V_11 ) ) ;
break;
default:
break;
}
}
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ ) {
V_85 -> V_725 [ V_11 ] += F_11 ( V_8 , F_377 ( V_11 ) ) ;
V_85 -> V_726 [ V_11 ] += F_11 ( V_8 , F_378 ( V_11 ) ) ;
if ( ( V_8 -> V_72 . type == V_75 ) ||
( V_8 -> V_72 . type == V_76 ) ) {
V_85 -> V_722 [ V_11 ] += F_11 ( V_8 , F_379 ( V_11 ) ) ;
F_11 ( V_8 , F_380 ( V_11 ) ) ;
V_85 -> V_723 [ V_11 ] += F_11 ( V_8 , F_381 ( V_11 ) ) ;
F_11 ( V_8 , F_382 ( V_11 ) ) ;
}
}
V_85 -> V_727 += F_11 ( V_8 , V_728 ) ;
V_85 -> V_727 -= V_703 ;
F_57 ( V_2 ) ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_85 -> V_729 += F_11 ( V_8 , V_730 ) ;
V_85 -> V_731 += F_11 ( V_8 , V_732 ) ;
V_85 -> V_733 += F_11 ( V_8 , V_734 ) ;
V_85 -> V_735 += F_11 ( V_8 , V_736 ) ;
break;
case V_76 :
V_85 -> V_737 += F_11 ( V_8 , V_738 ) ;
V_85 -> V_739 += F_11 ( V_8 , V_740 ) ;
V_85 -> V_741 += F_11 ( V_8 , V_742 ) ;
V_85 -> V_743 += F_11 ( V_8 , V_744 ) ;
case V_75 :
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
V_2 -> V_745 +=
F_11 ( V_8 , F_383 ( V_11 ) ) ;
V_85 -> V_731 += F_11 ( V_8 , V_746 ) ;
F_11 ( V_8 , V_732 ) ;
V_85 -> V_733 += F_11 ( V_8 , V_747 ) ;
F_11 ( V_8 , V_734 ) ;
V_85 -> V_735 += F_11 ( V_8 , V_748 ) ;
F_11 ( V_8 , V_736 ) ;
V_85 -> V_729 += F_11 ( V_8 , V_749 ) ;
V_85 -> V_750 += F_11 ( V_8 , V_751 ) ;
V_85 -> V_752 += F_11 ( V_8 , V_753 ) ;
#ifdef F_122
V_85 -> V_754 += F_11 ( V_8 , V_755 ) ;
V_85 -> V_756 += F_11 ( V_8 , V_757 ) ;
V_85 -> V_758 += F_11 ( V_8 , V_759 ) ;
V_85 -> V_760 += F_11 ( V_8 , V_761 ) ;
V_85 -> V_762 += F_11 ( V_8 , V_763 ) ;
V_85 -> V_764 += F_11 ( V_8 , V_765 ) ;
if ( V_2 -> V_640 . V_766 ) {
struct V_767 * V_640 = & V_2 -> V_640 ;
struct V_768 * V_766 ;
unsigned int V_138 ;
T_2 V_769 = 0 , V_770 = 0 ;
F_384 (cpu) {
V_766 = F_385 ( V_640 -> V_766 , V_138 ) ;
V_769 += V_766 -> V_769 ;
V_770 += V_766 -> V_770 ;
}
V_85 -> V_771 = V_769 ;
V_85 -> V_772 = V_770 ;
}
#endif
break;
default:
break;
}
V_705 = F_11 ( V_8 , V_773 ) ;
V_85 -> V_705 += V_705 ;
V_85 -> V_774 += F_11 ( V_8 , V_775 ) ;
if ( V_8 -> V_72 . type == V_73 )
V_85 -> V_774 -= V_705 ;
V_85 -> V_776 += F_11 ( V_8 , V_777 ) ;
V_85 -> V_778 += F_11 ( V_8 , V_779 ) ;
V_85 -> V_780 += F_11 ( V_8 , V_781 ) ;
V_85 -> V_782 += F_11 ( V_8 , V_783 ) ;
V_85 -> V_784 += F_11 ( V_8 , V_785 ) ;
V_85 -> V_786 += F_11 ( V_8 , V_787 ) ;
V_85 -> V_788 += F_11 ( V_8 , V_789 ) ;
V_85 -> V_790 += F_11 ( V_8 , V_791 ) ;
V_706 = F_11 ( V_8 , V_792 ) ;
V_85 -> V_793 += V_706 ;
V_707 = F_11 ( V_8 , V_794 ) ;
V_85 -> V_795 += V_707 ;
V_85 -> V_796 += F_11 ( V_8 , V_797 ) ;
V_85 -> V_798 += F_11 ( V_8 , V_799 ) ;
V_708 = V_706 + V_707 ;
V_85 -> V_796 -= V_708 ;
V_85 -> V_798 -= V_708 ;
V_85 -> V_733 -= ( V_708 * ( V_800 + V_436 ) ) ;
V_85 -> V_801 += F_11 ( V_8 , V_802 ) ;
V_85 -> V_803 += F_11 ( V_8 , V_804 ) ;
V_85 -> V_805 += F_11 ( V_8 , V_806 ) ;
V_85 -> V_807 += F_11 ( V_8 , V_808 ) ;
V_85 -> V_809 += F_11 ( V_8 , V_810 ) ;
V_85 -> V_809 -= V_708 ;
V_85 -> V_811 += F_11 ( V_8 , V_812 ) ;
V_85 -> V_813 += F_11 ( V_8 , V_814 ) ;
V_85 -> V_815 += F_11 ( V_8 , V_816 ) ;
V_85 -> V_817 += F_11 ( V_8 , V_818 ) ;
V_85 -> V_819 += F_11 ( V_8 , V_820 ) ;
V_85 -> V_821 += F_11 ( V_8 , V_822 ) ;
V_18 -> V_86 . V_823 = V_85 -> V_774 ;
V_18 -> V_86 . V_824 = V_85 -> V_717 + V_85 -> V_790 ;
V_18 -> V_86 . V_825 = 0 ;
V_18 -> V_86 . V_826 = V_85 -> V_790 ;
V_18 -> V_86 . V_827 = V_85 -> V_717 ;
V_18 -> V_86 . V_828 = V_702 ;
}
static void F_386 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_11 ;
if ( ! ( V_2 -> V_115 & V_336 ) )
return;
V_2 -> V_115 &= ~ V_336 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
if ( ! ( V_2 -> V_100 & V_335 ) )
return;
V_2 -> V_829 ++ ;
if ( F_387 ( V_8 ) == 0 ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_206 ( V_344 ,
& ( V_2 -> V_21 [ V_11 ] -> V_4 ) ) ;
F_45 ( V_8 , V_327 , V_337 ) ;
} else {
F_77 ( V_135 , L_90
L_91 ) ;
}
}
static void F_388 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_830 = 0 ;
int V_11 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_605 , & V_2 -> V_4 ) )
return;
if ( F_83 ( V_2 -> V_18 ) ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_389 ( V_2 -> V_21 [ V_11 ] ) ;
}
if ( ! ( V_2 -> V_100 & V_359 ) ) {
F_45 ( V_8 , V_81 ,
( V_831 | V_832 ) ) ;
} else {
for ( V_11 = 0 ; V_11 < V_2 -> V_153 ; V_11 ++ ) {
struct V_117 * V_833 = V_2 -> V_118 [ V_11 ] ;
if ( V_833 -> V_269 . V_82 || V_833 -> V_122 . V_82 )
V_830 |= ( ( T_2 ) 1 << V_11 ) ;
}
}
F_49 ( V_2 , V_830 ) ;
}
static void F_390 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_834 = V_2 -> V_834 ;
bool V_311 = V_2 -> V_311 ;
bool V_96 = V_2 -> V_97 . V_98 ;
if ( ! ( V_2 -> V_100 & V_323 ) )
return;
if ( V_8 -> V_72 . V_308 . V_309 ) {
V_8 -> V_72 . V_308 . V_309 ( V_8 , & V_834 , & V_311 , false ) ;
} else {
V_834 = V_835 ;
V_311 = true ;
}
if ( V_2 -> V_99 )
V_96 |= ! ! ( V_2 -> V_99 -> V_96 ) ;
if ( V_311 && ! ( ( V_2 -> V_100 & V_101 ) && V_96 ) ) {
V_8 -> V_72 . V_308 . V_836 ( V_8 ) ;
F_391 ( V_2 ) ;
}
if ( V_311 ||
F_392 ( V_134 , ( V_2 -> V_324 +
V_837 ) ) ) {
V_2 -> V_100 &= ~ V_323 ;
F_45 ( V_8 , V_327 , V_326 ) ;
F_176 ( V_8 ) ;
}
V_2 -> V_311 = V_311 ;
V_2 -> V_834 = V_834 ;
}
static void F_393 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_834 = V_2 -> V_834 ;
bool V_838 , V_839 ;
if ( F_83 ( V_18 ) )
return;
V_2 -> V_115 &= ~ V_574 ;
switch ( V_8 -> V_72 . type ) {
case V_73 : {
T_1 V_840 = F_11 ( V_8 , V_513 ) ;
T_1 V_841 = F_11 ( V_8 , V_842 ) ;
V_838 = ! ! ( V_840 & V_843 ) ;
V_839 = ! ! ( V_841 & V_844 ) ;
}
break;
case V_76 :
case V_75 : {
T_1 V_845 = F_11 ( V_8 , V_846 ) ;
T_1 V_847 = F_11 ( V_8 , V_848 ) ;
V_838 = ! ! ( V_845 & V_849 ) ;
V_839 = ! ! ( V_847 & V_850 ) ;
}
break;
default:
V_839 = false ;
V_838 = false ;
break;
}
#ifdef F_69
F_394 ( V_2 ) ;
#endif
F_79 ( V_133 , L_92 ,
( V_834 == V_835 ?
L_93 :
( V_834 == V_851 ?
L_94 :
( V_834 == V_852 ?
L_95 :
L_96 ) ) ) ,
( ( V_838 && V_839 ) ? L_97 :
( V_838 ? L_98 :
( V_839 ? L_99 : L_100 ) ) ) ) ;
F_395 ( V_18 ) ;
F_396 ( V_2 ) ;
F_315 ( V_2 ) ;
}
static void F_397 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
V_2 -> V_311 = false ;
V_2 -> V_834 = 0 ;
if ( ! F_83 ( V_18 ) )
return;
if ( F_285 ( V_8 ) && V_8 -> V_72 . type == V_73 )
V_2 -> V_115 |= V_574 ;
#ifdef F_69
F_394 ( V_2 ) ;
#endif
F_79 ( V_133 , L_101 ) ;
F_312 ( V_18 ) ;
F_315 ( V_2 ) ;
}
static void F_398 ( struct V_1 * V_2 )
{
int V_11 ;
int V_853 = 0 ;
if ( ! F_83 ( V_2 -> V_18 ) ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_21 = V_2 -> V_21 [ V_11 ] ;
if ( V_21 -> V_44 != V_21 -> V_43 ) {
V_853 = 1 ;
break;
}
}
if ( V_853 ) {
V_2 -> V_115 |= V_116 ;
}
}
}
static void F_399 ( struct V_1 * V_2 )
{
T_1 V_854 ;
if ( V_2 -> V_8 . V_72 . type == V_73 )
return;
V_854 = F_11 ( & V_2 -> V_8 , V_855 ) ;
if ( ! V_854 )
return;
F_267 ( V_133 , L_102 , V_854 ) ;
}
static void F_400 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_605 , & V_2 -> V_4 ) )
return;
F_390 ( V_2 ) ;
if ( V_2 -> V_311 )
F_393 ( V_2 ) ;
else
F_397 ( V_2 ) ;
F_399 ( V_2 ) ;
F_368 ( V_2 ) ;
F_398 ( V_2 ) ;
}
static void F_401 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_13 V_351 ;
if ( ! ( V_2 -> V_115 & V_574 ) &&
! ( V_2 -> V_115 & V_320 ) )
return;
if ( F_3 ( V_606 , & V_2 -> V_4 ) )
return;
V_351 = V_8 -> V_312 . V_308 . V_856 ( V_8 ) ;
if ( V_351 == V_609 )
goto V_857;
if ( V_351 == V_608 ) {
V_2 -> V_115 |= V_320 ;
}
if ( V_351 )
goto V_857;
if ( ! ( V_2 -> V_115 & V_320 ) )
goto V_857;
V_2 -> V_115 &= ~ V_320 ;
if ( V_8 -> V_72 . type == V_73 )
V_351 = V_8 -> V_312 . V_308 . V_858 ( V_8 ) ;
else
V_351 = V_8 -> V_72 . V_308 . V_859 ( V_8 ) ;
if ( V_351 == V_609 )
goto V_857;
V_2 -> V_100 |= V_321 ;
F_79 ( V_135 , L_103 , V_8 -> V_312 . V_860 ) ;
V_857:
F_8 ( V_606 , & V_2 -> V_4 ) ;
if ( ( V_351 == V_609 ) &&
( V_2 -> V_18 -> V_861 == V_862 ) ) {
F_300 ( L_104
L_105 ) ;
F_300 ( L_106
L_107 ) ;
F_402 ( V_2 -> V_18 ) ;
}
}
static void F_403 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_310 ;
bool V_575 ;
if ( ! ( V_2 -> V_100 & V_321 ) )
return;
if ( F_3 ( V_606 , & V_2 -> V_4 ) )
return;
V_2 -> V_100 &= ~ V_321 ;
V_310 = V_8 -> V_312 . V_578 ;
if ( ( ! V_310 ) && ( V_8 -> V_72 . V_308 . V_579 ) )
V_8 -> V_72 . V_308 . V_579 ( V_8 , & V_310 , & V_575 ) ;
if ( V_8 -> V_72 . V_308 . V_580 )
V_8 -> V_72 . V_308 . V_580 ( V_8 , V_310 , V_575 , true ) ;
V_2 -> V_100 |= V_323 ;
V_2 -> V_324 = V_134 ;
F_8 ( V_606 , & V_2 -> V_4 ) ;
}
static void F_404 ( struct V_1 * V_2 )
{
int V_863 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_864 ;
T_1 V_865 , V_866 ;
V_864 = F_11 ( V_8 , V_867 ) ;
if ( V_864 )
return;
for ( V_863 = 0 ; V_863 < V_2 -> V_271 ; V_863 ++ ) {
V_865 = ( V_863 << 16 ) | 0x80000000 ;
V_865 |= V_868 ;
F_45 ( V_8 , V_869 , V_865 ) ;
V_866 = F_11 ( V_8 , V_870 ) ;
V_865 &= 0x7FFFFFFF ;
F_45 ( V_8 , V_869 , V_865 ) ;
V_866 >>= 16 ;
if ( V_866 & V_871 ) {
F_405 ( V_18 , L_108 , V_863 ) ;
V_865 = ( V_863 << 16 ) | 0x80000000 ;
V_865 |= 0xA8 ;
F_45 ( V_8 , V_869 , V_865 ) ;
V_866 = 0x00008000 ;
F_45 ( V_8 , V_870 , V_866 ) ;
V_865 &= 0x7FFFFFFF ;
F_45 ( V_8 , V_869 , V_865 ) ;
}
}
}
static void F_406 ( unsigned long V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
unsigned long V_872 ;
bool V_873 = true ;
if ( V_2 -> V_100 & V_323 )
V_872 = V_874 / 10 ;
else
V_872 = V_874 * 2 ;
#ifdef F_323
if ( ! V_2 -> V_271 ||
( V_2 -> V_100 & V_323 ) )
goto V_875;
F_404 ( V_2 ) ;
V_872 = V_874 / 50 ;
V_2 -> V_876 ++ ;
if ( V_2 -> V_876 >= 100 )
V_2 -> V_876 = 0 ;
else
V_873 = false ;
V_875:
#endif
F_292 ( & V_2 -> V_603 , V_872 + V_134 ) ;
if ( V_873 )
F_1 ( V_2 ) ;
}
static void F_407 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_115 & V_116 ) )
return;
V_2 -> V_115 &= ~ V_116 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_605 , & V_2 -> V_4 ) )
return;
F_28 ( V_2 ) ;
F_405 ( V_2 -> V_18 , L_109 ) ;
V_2 -> V_136 ++ ;
F_293 ( V_2 ) ;
}
static void F_408 ( struct V_877 * V_878 )
{
struct V_1 * V_2 = F_189 ( V_878 ,
struct V_1 ,
V_6 ) ;
F_407 ( V_2 ) ;
F_401 ( V_2 ) ;
F_403 ( V_2 ) ;
F_170 ( V_2 ) ;
F_400 ( V_2 ) ;
F_386 ( V_2 ) ;
F_388 ( V_2 ) ;
#ifdef F_69
F_409 ( V_2 ) ;
#endif
F_5 ( V_2 ) ;
}
static int F_410 ( struct V_20 * V_21 ,
struct V_22 * V_879 ,
T_4 * V_223 )
{
struct V_159 * V_53 = V_879 -> V_53 ;
T_1 V_880 , V_881 ;
T_1 V_882 , V_883 ;
if ( ! F_411 ( V_53 ) )
return 0 ;
if ( F_412 ( V_53 ) ) {
int V_351 = F_413 ( V_53 , 0 , 0 , V_187 ) ;
if ( V_351 )
return V_351 ;
}
V_881 = V_884 ;
if ( V_879 -> V_205 == F_121 ( V_213 ) ) {
struct V_202 * V_885 = F_414 ( V_53 ) ;
V_885 -> V_886 = 0 ;
V_885 -> V_887 = 0 ;
F_415 ( V_53 ) -> V_887 = ~ F_416 ( V_885 -> V_888 ,
V_885 -> V_889 , 0 ,
V_216 ,
0 ) ;
V_881 |= V_890 ;
V_879 -> V_129 |= V_891 |
V_892 |
V_893 ;
} else if ( F_417 ( V_53 ) ) {
F_418 ( V_53 ) -> V_894 = 0 ;
F_415 ( V_53 ) -> V_887 =
~ F_419 ( & F_418 ( V_53 ) -> V_888 ,
& F_418 ( V_53 ) -> V_889 ,
0 , V_216 , 0 ) ;
V_879 -> V_129 |= V_891 |
V_892 ;
}
V_883 = F_420 ( V_53 ) ;
* V_223 = F_421 ( V_53 ) + V_883 ;
V_879 -> V_128 = F_128 ( V_53 ) -> V_128 ;
V_879 -> V_127 += ( V_879 -> V_128 - 1 ) * * V_223 ;
V_882 = V_883 << V_895 ;
V_882 |= F_128 ( V_53 ) -> V_224 << V_896 ;
V_882 |= 1 << V_897 ;
V_880 = F_422 ( V_53 ) ;
V_880 |= F_423 ( V_53 ) << V_898 ;
V_880 |= V_879 -> V_129 & V_899 ;
F_424 ( V_21 , V_880 , 0 , V_881 ,
V_882 ) ;
return 1 ;
}
static void F_425 ( struct V_20 * V_21 ,
struct V_22 * V_879 )
{
struct V_159 * V_53 = V_879 -> V_53 ;
T_1 V_880 = 0 ;
T_1 V_882 = 0 ;
T_1 V_881 = 0 ;
if ( V_53 -> V_182 != V_900 ) {
if ( ! ( V_879 -> V_129 & V_901 ) &&
! ( V_879 -> V_129 & V_902 ) )
return;
} else {
T_4 V_903 = 0 ;
switch ( V_879 -> V_205 ) {
case F_121 ( V_213 ) :
V_880 |= F_422 ( V_53 ) ;
V_881 |= V_890 ;
V_903 = F_414 ( V_53 ) -> V_205 ;
break;
case F_121 ( V_904 ) :
V_880 |= F_422 ( V_53 ) ;
V_903 = F_418 ( V_53 ) -> V_206 ;
break;
default:
if ( F_70 ( F_426 () ) ) {
F_427 ( V_21 -> V_37 ,
L_110 ,
V_879 -> V_205 ) ;
}
break;
}
switch ( V_903 ) {
case V_216 :
V_881 |= V_884 ;
V_882 = F_420 ( V_53 ) <<
V_895 ;
break;
case V_905 :
V_881 |= V_906 ;
V_882 = sizeof( struct V_907 ) <<
V_895 ;
break;
case V_908 :
V_882 = sizeof( struct V_909 ) <<
V_895 ;
break;
default:
if ( F_70 ( F_426 () ) ) {
F_427 ( V_21 -> V_37 ,
L_111 ,
V_903 ) ;
}
break;
}
V_879 -> V_129 |= V_892 ;
}
V_880 |= F_423 ( V_53 ) << V_898 ;
V_880 |= V_879 -> V_129 & V_899 ;
F_424 ( V_21 , V_880 , 0 ,
V_881 , V_882 ) ;
}
static T_9 F_428 ( T_1 V_129 )
{
T_9 V_910 = F_68 ( V_911 |
V_912 |
V_913 ) ;
if ( V_129 & V_901 )
V_910 |= F_68 ( V_914 ) ;
#ifdef F_69
if ( V_129 & V_130 )
V_910 |= F_68 ( V_915 ) ;
#endif
#ifdef F_122
if ( V_129 & ( V_891 | V_916 ) )
#else
if ( V_129 & V_891 )
#endif
V_910 |= F_68 ( V_917 ) ;
return V_910 ;
}
static void F_429 ( union V_24 * V_25 ,
T_1 V_129 , unsigned int V_918 )
{
T_9 V_919 = F_68 ( V_918 << V_920 ) ;
if ( V_129 & V_892 )
V_919 |= F_68 ( V_921 ) ;
if ( V_129 & V_893 )
V_919 |= F_68 ( V_922 ) ;
#ifdef F_122
if ( V_129 & ( V_891 | V_923 ) )
#else
if ( V_129 & V_891 )
#endif
V_919 |= F_68 ( 1 << V_897 ) ;
#ifdef F_122
if ( V_129 & ( V_902 | V_923 ) )
#else
if ( V_129 & V_902 )
#endif
V_919 |= F_68 ( V_924 ) ;
V_25 -> V_193 . V_919 = V_919 ;
}
static void F_430 ( struct V_20 * V_21 ,
struct V_22 * V_879 ,
const T_4 V_223 )
{
T_7 V_45 ;
struct V_159 * V_53 = V_879 -> V_53 ;
struct V_22 * V_23 ;
union V_24 * V_25 ;
struct V_237 * V_238 = & F_128 ( V_53 ) -> V_239 [ 0 ] ;
unsigned int V_246 = V_53 -> V_246 ;
unsigned int V_255 = F_127 ( V_53 ) ;
unsigned int V_918 = V_53 -> V_46 - V_223 ;
T_1 V_129 = V_879 -> V_129 ;
T_9 V_910 ;
T_5 V_11 = V_21 -> V_44 ;
V_25 = F_35 ( V_21 , V_11 ) ;
F_429 ( V_25 , V_129 , V_918 ) ;
V_910 = F_428 ( V_129 ) ;
#ifdef F_122
if ( V_129 & V_923 ) {
if ( V_246 < sizeof( struct V_268 ) ) {
V_255 -= sizeof( struct V_268 ) - V_246 ;
V_246 = 0 ;
} else {
V_246 -= sizeof( struct V_268 ) ;
}
}
#endif
V_45 = F_431 ( V_21 -> V_37 , V_53 -> V_56 , V_255 , V_83 ) ;
if ( F_116 ( V_21 -> V_37 , V_45 ) )
goto V_925;
F_55 ( V_879 , V_46 , V_255 ) ;
F_432 ( V_879 , V_45 , V_45 ) ;
V_25 -> V_193 . V_926 = F_119 ( V_45 ) ;
for (; ; ) {
while ( F_70 ( V_255 > V_927 ) ) {
V_25 -> V_193 . V_928 =
V_910 | F_68 ( V_927 ) ;
V_11 ++ ;
V_25 ++ ;
if ( V_11 == V_21 -> V_52 ) {
V_25 = F_35 ( V_21 , 0 ) ;
V_11 = 0 ;
}
V_45 += V_927 ;
V_255 -= V_927 ;
V_25 -> V_193 . V_926 = F_119 ( V_45 ) ;
V_25 -> V_193 . V_919 = 0 ;
}
if ( F_73 ( ! V_246 ) )
break;
if ( F_70 ( V_53 -> V_929 ) )
V_910 &= ~ ( F_68 ( V_912 ) ) ;
V_25 -> V_193 . V_928 = V_910 | F_68 ( V_255 ) ;
V_11 ++ ;
V_25 ++ ;
if ( V_11 == V_21 -> V_52 ) {
V_25 = F_35 ( V_21 , 0 ) ;
V_11 = 0 ;
}
#ifdef F_122
V_255 = F_320 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_255 = F_144 ( V_238 ) ;
#endif
V_246 -= V_255 ;
V_45 = F_433 ( V_21 -> V_37 , V_238 , 0 , V_255 ,
V_83 ) ;
if ( F_116 ( V_21 -> V_37 , V_45 ) )
goto V_925;
V_23 = & V_21 -> V_42 [ V_11 ] ;
F_55 ( V_23 , V_46 , V_255 ) ;
F_432 ( V_23 , V_45 , V_45 ) ;
V_25 -> V_193 . V_926 = F_119 ( V_45 ) ;
V_25 -> V_193 . V_919 = 0 ;
V_238 ++ ;
}
V_910 |= F_68 ( V_255 ) | F_68 ( V_930 ) ;
V_25 -> V_193 . V_928 = V_910 ;
F_434 ( F_81 ( V_21 ) , V_879 -> V_127 ) ;
V_879 -> V_48 = V_134 ;
F_109 () ;
V_879 -> V_47 = V_25 ;
V_11 ++ ;
if ( V_11 == V_21 -> V_52 )
V_11 = 0 ;
V_21 -> V_44 = V_11 ;
F_110 ( V_11 , V_21 -> V_109 ) ;
return;
V_925:
F_332 ( V_21 -> V_37 , L_112 ) ;
for (; ; ) {
V_23 = & V_21 -> V_42 [ V_11 ] ;
F_51 ( V_21 , V_23 ) ;
if ( V_23 == V_879 )
break;
if ( V_11 == 0 )
V_11 = V_21 -> V_52 ;
V_11 -- ;
}
V_21 -> V_44 = V_11 ;
}
static void F_435 ( struct V_20 * V_82 ,
struct V_22 * V_879 )
{
struct V_117 * V_118 = V_82 -> V_118 ;
union V_931 V_932 = { . V_933 = 0 } ;
union V_931 V_934 = { . V_933 = 0 } ;
union {
unsigned char * V_197 ;
struct V_202 * V_203 ;
struct V_935 * V_936 ;
} V_204 ;
struct V_217 * V_937 ;
T_8 V_938 ;
if ( ! V_118 )
return;
if ( ! V_82 -> V_369 )
return;
V_82 -> V_370 ++ ;
V_204 . V_197 = F_436 ( V_879 -> V_53 ) ;
if ( ( V_879 -> V_205 != F_121 ( V_904 ) ||
V_204 . V_936 -> V_206 != V_216 ) &&
( V_879 -> V_205 != F_121 ( V_213 ) ||
V_204 . V_203 -> V_205 != V_216 ) )
return;
V_937 = F_415 ( V_879 -> V_53 ) ;
if ( ! V_937 || V_937 -> V_939 )
return;
if ( ! V_937 -> V_940 && ( V_82 -> V_370 < V_82 -> V_369 ) )
return;
V_82 -> V_370 = 0 ;
V_938 = F_437 ( V_879 -> V_129 >> V_941 ) ;
V_932 . V_942 . V_938 = V_938 ;
if ( V_879 -> V_129 & ( V_943 | V_901 ) )
V_934 . V_944 . V_945 ^= V_937 -> V_946 ^ F_121 ( V_210 ) ;
else
V_934 . V_944 . V_945 ^= V_937 -> V_946 ^ V_879 -> V_205 ;
V_934 . V_944 . V_947 ^= V_937 -> V_948 ;
if ( V_879 -> V_205 == F_121 ( V_213 ) ) {
V_932 . V_942 . V_949 = V_950 ;
V_934 . V_951 ^= V_204 . V_203 -> V_888 ^ V_204 . V_203 -> V_889 ;
} else {
V_932 . V_942 . V_949 = V_952 ;
V_934 . V_951 ^= V_204 . V_936 -> V_888 . V_953 [ 0 ] ^
V_204 . V_936 -> V_888 . V_953 [ 1 ] ^
V_204 . V_936 -> V_888 . V_953 [ 2 ] ^
V_204 . V_936 -> V_888 . V_953 [ 3 ] ^
V_204 . V_936 -> V_889 . V_953 [ 0 ] ^
V_204 . V_936 -> V_889 . V_953 [ 1 ] ^
V_204 . V_936 -> V_889 . V_953 [ 2 ] ^
V_204 . V_936 -> V_889 . V_953 [ 3 ] ;
}
F_438 ( & V_118 -> V_2 -> V_8 ,
V_932 , V_934 , V_82 -> V_50 ) ;
}
static int F_439 ( struct V_20 * V_21 , T_5 V_255 )
{
F_78 ( V_21 -> V_18 , V_21 -> V_50 ) ;
F_85 () ;
if ( F_73 ( F_84 ( V_21 ) < V_255 ) )
return - V_683 ;
F_440 ( V_21 -> V_18 , V_21 -> V_50 ) ;
++ V_21 -> V_112 . V_137 ;
return 0 ;
}
static inline int F_441 ( struct V_20 * V_21 , T_5 V_255 )
{
if ( F_73 ( F_84 ( V_21 ) >= V_255 ) )
return 0 ;
return F_439 ( V_21 , V_255 ) ;
}
static T_5 F_442 ( struct V_17 * V_37 , struct V_159 * V_53 )
{
struct V_1 * V_2 = F_62 ( V_37 ) ;
int V_954 = F_443 ( V_53 ) ? F_444 ( V_53 ) :
F_445 () ;
#ifdef F_122
T_8 V_205 = F_446 ( V_53 ) ;
if ( ( ( V_205 == F_437 ( V_214 ) ) ||
( V_205 == F_437 ( V_955 ) ) ) &&
( V_2 -> V_100 & V_470 ) ) {
struct V_956 * V_957 ;
V_957 = & V_2 -> V_383 [ V_958 ] ;
while ( V_954 >= V_957 -> V_385 )
V_954 -= V_957 -> V_385 ;
V_954 += V_2 -> V_383 [ V_958 ] . V_959 ;
return V_954 ;
}
#endif
if ( V_2 -> V_100 & V_335 ) {
while ( F_70 ( V_954 >= V_37 -> V_960 ) )
V_954 -= V_37 -> V_960 ;
return V_954 ;
}
return F_447 ( V_37 , V_53 ) ;
}
T_14 F_448 ( struct V_159 * V_53 ,
struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_22 * V_879 ;
int V_961 ;
T_1 V_129 = 0 ;
#if V_399 > V_927
unsigned short V_957 ;
#endif
T_5 V_52 = F_449 ( F_127 ( V_53 ) ) ;
T_8 V_205 = V_53 -> V_205 ;
T_4 V_223 = 0 ;
#if V_399 > V_927
for ( V_957 = 0 ; V_957 < F_128 ( V_53 ) -> V_247 ; V_957 ++ )
V_52 += F_449 ( F_128 ( V_53 ) -> V_239 [ V_957 ] . V_255 ) ;
#else
V_52 += F_128 ( V_53 ) -> V_247 ;
#endif
if ( F_441 ( V_21 , V_52 + 3 ) ) {
V_21 -> V_112 . V_709 ++ ;
return V_962 ;
}
V_879 = & V_21 -> V_42 [ V_21 -> V_44 ] ;
V_879 -> V_53 = V_53 ;
V_879 -> V_127 = V_53 -> V_46 ;
V_879 -> V_128 = 1 ;
if ( F_450 ( V_53 ) ) {
V_129 |= F_451 ( V_53 ) << V_941 ;
V_129 |= V_901 ;
} else if ( V_205 == F_121 ( V_210 ) ) {
struct V_200 * V_963 , V_964 ;
V_963 = F_452 ( V_53 , V_208 , sizeof( V_964 ) , & V_964 ) ;
if ( ! V_963 )
goto V_965;
V_205 = V_963 -> V_212 ;
V_129 |= F_453 ( V_963 -> V_966 ) <<
V_941 ;
V_129 |= V_943 ;
}
F_454 ( V_53 ) ;
#ifdef F_69
if ( F_70 ( F_128 ( V_53 ) -> V_129 & V_967 ) ) {
F_128 ( V_53 ) -> V_129 |= V_968 ;
V_129 |= V_130 ;
}
#endif
#ifdef F_323
if ( V_2 -> V_100 & V_378 )
V_129 |= V_902 ;
#endif
if ( ( V_2 -> V_100 & V_101 ) &&
( ( V_129 & ( V_901 | V_943 ) ) ||
( V_53 -> V_969 != V_970 ) ) ) {
V_129 &= ~ V_971 ;
V_129 |= ( V_53 -> V_969 & 0x7 ) <<
V_972 ;
if ( V_129 & V_943 ) {
struct V_973 * V_963 ;
if ( F_412 ( V_53 ) &&
F_413 ( V_53 , 0 , 0 , V_187 ) )
goto V_965;
V_963 = (struct V_973 * ) V_53 -> V_56 ;
V_963 -> V_966 = F_437 ( V_129 >>
V_941 ) ;
} else {
V_129 |= V_901 ;
}
}
V_879 -> V_129 = V_129 ;
V_879 -> V_205 = V_205 ;
#ifdef F_122
if ( ( V_205 == F_121 ( V_214 ) ) &&
( V_21 -> V_18 -> V_160 & ( V_974 | V_975 ) ) ) {
V_961 = F_455 ( V_21 , V_879 , & V_223 ) ;
if ( V_961 < 0 )
goto V_965;
goto V_976;
}
#endif
V_961 = F_410 ( V_21 , V_879 , & V_223 ) ;
if ( V_961 < 0 )
goto V_965;
else if ( ! V_961 )
F_425 ( V_21 , V_879 ) ;
if ( F_2 ( V_344 , & V_21 -> V_4 ) )
F_435 ( V_21 , V_879 ) ;
#ifdef F_122
V_976:
#endif
F_430 ( V_21 , V_879 , V_223 ) ;
F_441 ( V_21 , V_977 ) ;
return V_978 ;
V_965:
F_52 ( V_879 -> V_53 ) ;
V_879 -> V_53 = NULL ;
return V_978 ;
}
static T_14 F_456 ( struct V_159 * V_53 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_20 * V_21 ;
if ( F_70 ( V_53 -> V_46 < 17 ) ) {
if ( F_149 ( V_53 , 17 - V_53 -> V_46 ) )
return V_978 ;
V_53 -> V_46 = 17 ;
}
V_21 = V_2 -> V_21 [ V_53 -> V_979 ] ;
return F_448 ( V_53 , V_2 , V_21 ) ;
}
static int F_457 ( struct V_17 * V_18 , void * V_438 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_980 * V_506 = V_438 ;
if ( ! F_458 ( V_506 -> V_981 ) )
return - V_982 ;
memcpy ( V_18 -> V_983 , V_506 -> V_981 , V_18 -> V_984 ) ;
memcpy ( V_8 -> V_72 . V_506 , V_506 -> V_981 , V_18 -> V_984 ) ;
V_8 -> V_72 . V_308 . V_505 ( V_8 , 0 , V_8 -> V_72 . V_506 , F_225 ( 0 ) , V_507 ) ;
return 0 ;
}
static int
F_459 ( struct V_17 * V_18 , int V_985 , int V_986 , T_5 V_506 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_5 V_987 ;
int V_988 ;
if ( V_985 != V_8 -> V_312 . V_989 . V_985 )
return - V_680 ;
V_988 = V_8 -> V_312 . V_308 . V_990 ( V_8 , V_506 , V_986 , & V_987 ) ;
if ( ! V_988 )
V_988 = V_987 ;
return V_988 ;
}
static int F_460 ( struct V_17 * V_18 , int V_985 , int V_986 ,
T_5 V_506 , T_5 V_987 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( V_985 != V_8 -> V_312 . V_989 . V_985 )
return - V_680 ;
return V_8 -> V_312 . V_308 . V_991 ( V_8 , V_506 , V_986 , V_987 ) ;
}
static int F_461 ( struct V_17 * V_18 , struct V_992 * V_993 , int V_994 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
switch ( V_994 ) {
#ifdef F_69
case V_995 :
return F_462 ( V_2 , V_993 , V_994 ) ;
#endif
default:
return F_463 ( & V_2 -> V_8 . V_312 . V_989 , F_464 ( V_993 ) , V_994 ) ;
}
}
static int F_465 ( struct V_17 * V_37 )
{
int V_351 = 0 ;
struct V_1 * V_2 = F_62 ( V_37 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( F_458 ( V_8 -> V_72 . V_996 ) ) {
F_356 () ;
V_351 = F_466 ( V_37 , V_8 -> V_72 . V_996 , V_997 ) ;
F_358 () ;
V_8 -> V_72 . V_308 . V_613 ( V_8 , F_225 ( 0 ) ) ;
}
return V_351 ;
}
static int F_467 ( struct V_17 * V_37 )
{
int V_351 = 0 ;
struct V_1 * V_2 = F_62 ( V_37 ) ;
struct V_998 * V_72 = & V_2 -> V_8 . V_72 ;
if ( F_458 ( V_72 -> V_996 ) ) {
F_356 () ;
V_351 = F_468 ( V_37 , V_72 -> V_996 , V_997 ) ;
F_358 () ;
}
return V_351 ;
}
static void F_469 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
int V_11 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
V_2 -> V_100 |= V_230 ;
if ( V_2 -> V_100 & V_359 ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_153 ; V_11 ++ )
F_186 ( 0 , V_2 -> V_118 [ V_11 ] ) ;
} else {
F_198 ( V_2 -> V_36 -> V_338 , V_18 ) ;
}
V_2 -> V_100 &= ~ V_230 ;
}
static struct V_999 * F_470 ( struct V_17 * V_18 ,
struct V_999 * V_86 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
int V_11 ;
F_471 () ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
struct V_20 * V_82 = F_472 ( V_2 -> V_30 [ V_11 ] ) ;
T_2 V_132 , V_106 ;
unsigned int V_1000 ;
if ( V_82 ) {
do {
V_1000 = F_473 ( & V_82 -> V_131 ) ;
V_106 = V_82 -> V_86 . V_106 ;
V_132 = V_82 -> V_86 . V_132 ;
} while ( F_474 ( & V_82 -> V_131 , V_1000 ) );
V_86 -> V_714 += V_106 ;
V_86 -> V_713 += V_132 ;
}
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_82 = F_472 ( V_2 -> V_21 [ V_11 ] ) ;
T_2 V_132 , V_106 ;
unsigned int V_1000 ;
if ( V_82 ) {
do {
V_1000 = F_473 ( & V_82 -> V_131 ) ;
V_106 = V_82 -> V_86 . V_106 ;
V_132 = V_82 -> V_86 . V_132 ;
} while ( F_474 ( & V_82 -> V_131 , V_1000 ) );
V_86 -> V_716 += V_106 ;
V_86 -> V_715 += V_132 ;
}
}
F_475 () ;
V_86 -> V_823 = V_18 -> V_86 . V_823 ;
V_86 -> V_824 = V_18 -> V_86 . V_824 ;
V_86 -> V_826 = V_18 -> V_86 . V_826 ;
V_86 -> V_827 = V_18 -> V_86 . V_827 ;
V_86 -> V_828 = V_18 -> V_86 . V_828 ;
return V_86 ;
}
static void F_476 ( struct V_1 * V_2 , T_4 V_104 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_1001 , V_1002 ;
int V_11 ;
if ( V_8 -> V_72 . type == V_73 )
return;
V_1001 = F_11 ( V_8 , V_1003 ) ;
V_1002 = V_1001 ;
for ( V_11 = 0 ; V_11 < V_648 ; V_11 ++ ) {
T_4 V_1004 = V_1001 >> ( V_11 * V_1005 ) ;
if ( V_1004 > V_104 )
V_1001 &= ~ ( 0x7 << V_1005 ) ;
}
if ( V_1001 != V_1002 )
F_45 ( V_8 , V_1003 , V_1001 ) ;
return;
}
static void F_477 ( struct V_1 * V_2 )
{
struct V_17 * V_37 = V_2 -> V_18 ;
struct V_1006 * V_97 = & V_2 -> V_97 ;
struct V_1007 * V_1008 = V_2 -> V_534 ;
T_4 V_1009 ;
for ( V_1009 = 0 ; V_1009 < V_1010 ; V_1009 ++ ) {
T_4 V_104 = 0 ;
if ( V_2 -> V_530 & V_531 )
V_104 = F_478 ( V_97 , 0 , V_1009 ) ;
else if ( V_1008 )
V_104 = V_1008 -> V_535 [ V_1009 ] ;
F_479 ( V_37 , V_1009 , V_104 ) ;
}
}
int F_480 ( struct V_17 * V_37 , T_4 V_104 )
{
struct V_1 * V_2 = F_62 ( V_37 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( V_104 > V_2 -> V_97 . V_644 . V_645 ||
( V_8 -> V_72 . type == V_73 &&
V_104 < V_648 ) )
return - V_680 ;
if ( F_31 ( V_37 ) )
F_347 ( V_37 ) ;
F_363 ( V_2 ) ;
if ( V_104 ) {
F_481 ( V_37 , V_104 ) ;
F_477 ( V_2 ) ;
V_2 -> V_100 |= V_101 ;
if ( V_2 -> V_8 . V_72 . type == V_73 ) {
V_2 -> V_1011 = V_2 -> V_8 . V_87 . V_660 ;
V_2 -> V_8 . V_87 . V_660 = V_1012 ;
}
} else {
F_482 ( V_37 ) ;
if ( V_2 -> V_8 . V_72 . type == V_73 )
V_2 -> V_8 . V_87 . V_660 = V_2 -> V_1011 ;
V_2 -> V_100 &= ~ V_101 ;
V_2 -> V_659 . V_98 = false ;
V_2 -> V_97 . V_98 = false ;
}
F_357 ( V_2 ) ;
F_476 ( V_2 , V_104 ) ;
if ( F_31 ( V_37 ) )
F_344 ( V_37 ) ;
return 0 ;
}
void F_483 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
if ( F_31 ( V_18 ) )
F_293 ( V_2 ) ;
else
F_299 ( V_2 ) ;
}
static T_15 F_484 ( struct V_17 * V_18 ,
T_15 V_160 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
if ( ! ( V_160 & V_173 ) )
V_160 &= ~ V_1013 ;
if ( ! ( V_2 -> V_115 & V_635 ) )
V_160 &= ~ V_1013 ;
return V_160 ;
}
static int F_485 ( struct V_17 * V_18 ,
T_15 V_160 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
T_15 V_1014 = V_18 -> V_160 ^ V_160 ;
bool V_1015 = false ;
if ( ! ( V_160 & V_1013 ) ) {
if ( V_2 -> V_115 & V_477 )
V_1015 = true ;
V_2 -> V_115 &= ~ V_477 ;
} else if ( ( V_2 -> V_115 & V_635 ) &&
! ( V_2 -> V_115 & V_477 ) ) {
if ( V_2 -> V_277 == 1 ||
V_2 -> V_277 > V_1016 ) {
V_2 -> V_115 |= V_477 ;
V_1015 = true ;
} else if ( ( V_1014 ^ V_160 ) & V_1013 ) {
F_79 ( V_135 , L_113
L_114 ) ;
}
}
switch ( V_160 & V_1017 ) {
case V_1017 :
if ( ! ( V_2 -> V_100 & V_548 ) )
V_1015 = true ;
V_2 -> V_100 &= ~ V_335 ;
V_2 -> V_100 |= V_548 ;
break;
default:
if ( V_2 -> V_100 & V_548 )
V_1015 = true ;
V_2 -> V_100 &= ~ V_548 ;
if ( V_2 -> V_100 & V_378 )
break;
if ( F_209 ( V_18 ) > 1 )
break;
if ( V_2 -> V_383 [ V_384 ] . V_630 <= 1 )
break;
if ( ! V_2 -> V_369 )
break;
V_2 -> V_100 |= V_335 ;
break;
}
if ( V_160 & V_227 )
F_240 ( V_2 ) ;
else
F_239 ( V_2 ) ;
if ( V_1014 & V_244 )
V_1015 = true ;
V_18 -> V_160 = V_160 ;
if ( V_1015 )
F_483 ( V_18 ) ;
return 0 ;
}
static int F_486 ( struct V_1018 * V_1019 ,
struct V_17 * V_37 ,
unsigned char * V_506 ,
T_5 V_100 )
{
struct V_1 * V_2 = F_62 ( V_37 ) ;
int V_351 ;
if ( ! ( V_2 -> V_100 & V_378 ) )
return - V_1020 ;
if ( V_1019 -> V_1021 & V_1022 ) {
F_25 ( L_115 ,
V_1023 ) ;
return - V_680 ;
}
if ( F_487 ( V_506 ) ) {
T_1 V_1024 = V_501 ;
if ( F_244 ( V_37 ) < V_1024 )
V_351 = F_488 ( V_37 , V_506 ) ;
else
V_351 = - V_502 ;
} else if ( F_489 ( V_506 ) ) {
V_351 = F_490 ( V_37 , V_506 ) ;
} else {
V_351 = - V_680 ;
}
if ( V_351 == - V_1025 && ! ( V_100 & V_1026 ) )
V_351 = 0 ;
return V_351 ;
}
static int F_491 ( struct V_1018 * V_1019 ,
struct V_17 * V_37 ,
unsigned char * V_506 )
{
struct V_1 * V_2 = F_62 ( V_37 ) ;
int V_351 = - V_1020 ;
if ( V_1019 -> V_1021 & V_1022 ) {
F_25 ( L_115 ,
V_1023 ) ;
return - V_680 ;
}
if ( V_2 -> V_100 & V_378 ) {
if ( F_487 ( V_506 ) )
V_351 = F_492 ( V_37 , V_506 ) ;
else if ( F_489 ( V_506 ) )
V_351 = F_493 ( V_37 , V_506 ) ;
else
V_351 = - V_680 ;
}
return V_351 ;
}
static int F_494 ( struct V_159 * V_53 ,
struct V_1027 * V_1028 ,
struct V_17 * V_37 ,
int V_1029 )
{
struct V_1 * V_2 = F_62 ( V_37 ) ;
if ( V_2 -> V_100 & V_378 )
V_1029 = F_495 ( V_53 , V_1028 , V_37 , V_1029 ) ;
return V_1029 ;
}
int F_496 ( struct V_1 * V_2 , T_5 V_304 ,
T_5 V_1030 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_5 V_1031 = V_2 -> V_1032 & V_1033 ;
int V_1034 = 0 ;
switch ( V_304 ) {
case V_1035 :
switch ( V_1030 ) {
case V_1036 :
if ( V_8 -> V_1037 . V_1038 != 0 )
break;
case V_1039 :
case V_1040 :
V_1034 = 1 ;
break;
}
break;
case V_1041 :
if ( V_1030 != V_1042 )
V_1034 = 1 ;
break;
case V_1043 :
V_1034 = 1 ;
break;
case V_1044 :
if ( ( V_1031 == V_1045 ) ||
( ( V_1031 == V_1046 ) &&
( V_8 -> V_1037 . V_1038 == 0 ) ) ) {
V_1034 = 1 ;
}
break;
}
return V_1034 ;
}
static int T_11 F_497 ( struct V_619 * V_36 ,
const struct V_1047 * V_1048 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 = NULL ;
struct V_7 * V_8 ;
const struct V_1049 * V_1050 = V_1051 [ V_1048 -> V_1052 ] ;
static int V_1053 ;
int V_11 , V_351 , V_1054 ;
T_4 V_1055 [ V_1056 ] ;
unsigned int V_385 = F_498 () ;
unsigned int V_1057 = 0 ;
#ifdef F_122
T_5 V_1058 ;
#endif
T_1 V_1059 ;
if ( V_36 -> V_1060 ) {
F_499 ( 1 , V_1061 L_116 ,
F_500 ( V_36 ) , V_36 -> V_622 , V_36 -> V_154 ) ;
return - V_680 ;
}
V_351 = F_353 ( V_36 ) ;
if ( V_351 )
return V_351 ;
if ( ! F_501 ( & V_36 -> V_37 , F_205 ( 64 ) ) &&
! F_502 ( & V_36 -> V_37 , F_205 ( 64 ) ) ) {
V_1054 = 1 ;
} else {
V_351 = F_501 ( & V_36 -> V_37 , F_205 ( 32 ) ) ;
if ( V_351 ) {
V_351 = F_502 ( & V_36 -> V_37 ,
F_205 ( 32 ) ) ;
if ( V_351 ) {
F_332 ( & V_36 -> V_37 ,
L_117 ) ;
goto V_1062;
}
}
V_1054 = 0 ;
}
V_351 = F_503 ( V_36 , F_504 ( V_36 ,
V_1063 ) , V_1023 ) ;
if ( V_351 ) {
F_332 ( & V_36 -> V_37 ,
L_118 , V_351 ) ;
goto V_1064;
}
F_505 ( V_36 ) ;
F_354 ( V_36 ) ;
F_352 ( V_36 ) ;
#ifdef F_281
if ( V_1050 -> V_72 == V_73 )
V_1057 = F_320 (unsigned int, indices * MAX_TRAFFIC_CLASS,
IXGBE_MAX_RSS_INDICES) ;
else
V_1057 = F_320 (unsigned int, indices * MAX_TRAFFIC_CLASS,
IXGBE_MAX_FDIR_INDICES) ;
#endif
if ( V_1050 -> V_72 == V_73 )
V_385 = F_320 (unsigned int, indices, IXGBE_MAX_RSS_INDICES) ;
else
V_385 = F_320 (unsigned int, indices, IXGBE_MAX_FDIR_INDICES) ;
#ifdef F_122
V_385 += F_320 (unsigned int, num_possible_cpus(),
IXGBE_MAX_FCOE_INDICES) ;
#endif
V_385 = F_506 (unsigned int, dcb_max, indices) ;
V_18 = F_507 ( sizeof( struct V_1 ) , V_385 ) ;
if ( ! V_18 ) {
V_351 = - V_502 ;
goto V_1065;
}
F_508 ( V_18 , & V_36 -> V_37 ) ;
V_2 = F_62 ( V_18 ) ;
F_509 ( V_36 , V_2 ) ;
V_2 -> V_18 = V_18 ;
V_2 -> V_36 = V_36 ;
V_8 = & V_2 -> V_8 ;
V_8 -> V_1066 = V_2 ;
V_2 -> V_1067 = F_510 ( V_1068 , V_1069 ) ;
V_8 -> V_368 = F_511 ( F_512 ( V_36 , 0 ) ,
F_513 ( V_36 , 0 ) ) ;
if ( ! V_8 -> V_368 ) {
V_351 = - V_672 ;
goto V_1070;
}
for ( V_11 = 1 ; V_11 <= 5 ; V_11 ++ ) {
if ( F_513 ( V_36 , V_11 ) == 0 )
continue;
}
V_18 -> V_1071 = & V_1072 ;
F_514 ( V_18 ) ;
V_18 -> V_1073 = 5 * V_874 ;
strncpy ( V_18 -> V_16 , F_500 ( V_36 ) , sizeof( V_18 -> V_16 ) - 1 ) ;
V_2 -> V_1074 = V_1053 ;
memcpy ( & V_8 -> V_72 . V_308 , V_1050 -> V_1075 , sizeof( V_8 -> V_72 . V_308 ) ) ;
V_8 -> V_72 . type = V_1050 -> V_72 ;
memcpy ( & V_8 -> V_1076 . V_308 , V_1050 -> V_1077 , sizeof( V_8 -> V_1076 . V_308 ) ) ;
V_1059 = F_11 ( V_8 , V_1078 ) ;
if ( ! ( V_1059 & ( 1 << 8 ) ) )
V_8 -> V_1076 . V_308 . V_193 = & V_1079 ;
memcpy ( & V_8 -> V_312 . V_308 , V_1050 -> V_1080 , sizeof( V_8 -> V_312 . V_308 ) ) ;
V_8 -> V_312 . V_860 = V_1081 ;
V_8 -> V_312 . V_989 . V_985 = V_1082 ;
V_8 -> V_312 . V_989 . V_1083 = 0 ;
V_8 -> V_312 . V_989 . V_1084 = V_1085 | V_1086 ;
V_8 -> V_312 . V_989 . V_37 = V_18 ;
V_8 -> V_312 . V_989 . V_1087 = F_459 ;
V_8 -> V_312 . V_989 . V_1088 = F_460 ;
V_1050 -> V_1089 ( V_8 ) ;
V_351 = F_319 ( V_2 ) ;
if ( V_351 )
goto V_1090;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
case V_76 :
F_45 ( & V_2 -> V_8 , V_687 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_100 & V_315 ) {
T_1 V_600 = F_11 ( V_8 , V_601 ) ;
if ( V_600 & V_602 )
F_171 ( V_135 , L_54 ) ;
}
if ( V_1091 )
V_8 -> V_1091 = V_1091 ;
V_8 -> V_312 . V_1092 = true ;
V_351 = V_8 -> V_72 . V_308 . V_1093 ( V_8 ) ;
V_8 -> V_312 . V_1092 = false ;
if ( V_351 == V_608 &&
V_8 -> V_72 . type == V_73 ) {
V_351 = 0 ;
} else if ( V_351 == V_609 ) {
F_300 ( L_119
L_120 ) ;
F_300 ( L_121
L_122 ) ;
goto V_1090;
} else if ( V_351 ) {
F_300 ( L_123 , V_351 ) ;
goto V_1090;
}
#ifdef F_323
F_515 ( V_2 , V_1050 ) ;
#endif
V_18 -> V_160 = V_1094 |
V_1095 |
V_1096 |
V_1097 |
V_227 |
V_1098 |
V_1099 |
V_1100 |
V_161 |
V_173 ;
V_18 -> V_1101 = V_18 -> V_160 ;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
case V_76 :
V_18 -> V_160 |= V_1102 ;
V_18 -> V_1101 |= V_1102 |
V_1017 ;
break;
default:
break;
}
V_18 -> V_1101 |= V_244 ;
V_18 -> V_1103 |= V_1099 ;
V_18 -> V_1103 |= V_1100 ;
V_18 -> V_1103 |= V_1095 ;
V_18 -> V_1103 |= V_1096 ;
V_18 -> V_1103 |= V_1094 ;
V_18 -> V_1104 |= V_1105 ;
V_18 -> V_1104 |= V_1106 ;
#ifdef F_281
V_18 -> V_1107 = & V_1107 ;
#endif
#ifdef F_122
if ( V_2 -> V_100 & V_639 ) {
if ( V_8 -> V_72 . V_308 . V_1108 ) {
V_8 -> V_72 . V_308 . V_1108 ( V_8 , & V_1058 ) ;
if ( V_1058 & V_1109 )
V_2 -> V_100 &= ~ V_639 ;
}
V_2 -> V_383 [ V_958 ] . V_630 = V_1110 ;
V_18 -> V_160 |= V_974 |
V_975 ;
V_18 -> V_1103 |= V_974 |
V_975 |
V_529 ;
}
#endif
if ( V_1054 ) {
V_18 -> V_160 |= V_1111 ;
V_18 -> V_1103 |= V_1111 ;
}
if ( V_2 -> V_115 & V_635 )
V_18 -> V_1101 |= V_1013 ;
if ( V_2 -> V_115 & V_477 )
V_18 -> V_160 |= V_1013 ;
if ( V_8 -> V_1076 . V_308 . V_1112 ( V_8 , NULL ) < 0 ) {
F_300 ( L_124 ) ;
V_351 = - V_672 ;
goto V_1090;
}
memcpy ( V_18 -> V_983 , V_8 -> V_72 . V_1113 , V_18 -> V_984 ) ;
memcpy ( V_18 -> V_1113 , V_8 -> V_72 . V_1113 , V_18 -> V_984 ) ;
if ( F_516 ( V_18 -> V_1113 ) ) {
F_300 ( L_125 ) ;
V_351 = - V_672 ;
goto V_1090;
}
F_517 ( & V_2 -> V_603 , & F_406 ,
( unsigned long ) V_2 ) ;
F_518 ( & V_2 -> V_6 , F_408 ) ;
F_8 ( V_5 , & V_2 -> V_4 ) ;
V_351 = F_357 ( V_2 ) ;
if ( V_351 )
goto V_1090;
V_2 -> V_691 = 0 ;
V_8 -> V_1076 . V_308 . V_193 ( V_8 , 0x2c , & V_2 -> V_1032 ) ;
if ( F_496 ( V_2 , V_36 -> V_154 , V_36 -> V_628 ) )
V_2 -> V_691 = V_1114 ;
F_519 ( & V_2 -> V_36 -> V_37 , V_2 -> V_691 ) ;
#ifdef F_69
F_520 ( V_2 ) ;
#endif
V_8 -> V_1076 . V_308 . V_193 ( V_8 , 0x2e , & V_2 -> V_1115 ) ;
V_8 -> V_1076 . V_308 . V_193 ( V_8 , 0x2d , & V_2 -> V_1116 ) ;
V_8 -> V_72 . V_308 . V_1117 ( V_8 ) ;
F_521 ( L_126 ,
( V_8 -> V_1037 . V_1118 == V_1119 ? L_127 :
V_8 -> V_1037 . V_1118 == V_1120 ? L_128 :
L_129 ) ,
( V_8 -> V_1037 . V_1121 == V_1122 ? L_130 :
V_8 -> V_1037 . V_1121 == V_1123 ? L_131 :
V_8 -> V_1037 . V_1121 == V_1124 ? L_132 :
L_129 ) ,
V_18 -> V_983 ) ;
V_351 = F_522 ( V_8 , V_1055 , V_1056 ) ;
if ( V_351 )
strncpy ( V_1055 , L_129 , V_1056 ) ;
if ( F_285 ( V_8 ) && V_8 -> V_312 . V_860 != V_1125 )
F_521 ( L_133 ,
V_8 -> V_72 . type , V_8 -> V_312 . type , V_8 -> V_312 . V_860 ,
V_1055 ) ;
else
F_521 ( L_134 ,
V_8 -> V_72 . type , V_8 -> V_312 . type , V_1055 ) ;
if ( V_8 -> V_1037 . V_1121 <= V_1123 ) {
F_301 ( L_135
L_136 ) ;
F_301 ( L_137
L_138 ) ;
}
V_351 = V_8 -> V_72 . V_308 . V_1126 ( V_8 ) ;
if ( V_351 == V_611 ) {
F_301 ( L_76
L_139
L_140
L_141
L_80
L_81 ) ;
}
strcpy ( V_18 -> V_16 , L_142 ) ;
V_351 = F_523 ( V_18 ) ;
if ( V_351 )
goto V_1127;
if ( V_8 -> V_72 . V_308 . V_618 &&
( ( V_8 -> V_312 . V_597 ) ||
( ( V_8 -> V_72 . V_308 . V_598 ( V_8 ) == V_599 ) &&
( V_8 -> V_72 . type == V_75 ) ) ) )
V_8 -> V_72 . V_308 . V_618 ( V_8 ) ;
F_312 ( V_18 ) ;
#ifdef F_190
if ( F_100 ( & V_36 -> V_37 ) == 0 ) {
V_2 -> V_100 |= V_151 ;
F_97 ( V_2 ) ;
}
#endif
if ( V_2 -> V_100 & V_378 ) {
F_79 ( V_135 , L_143 , V_2 -> V_271 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_271 ; V_11 ++ )
F_524 ( V_36 , ( V_11 | 0x10000000 ) ) ;
}
if ( V_8 -> V_72 . V_308 . V_1128 )
V_8 -> V_72 . V_308 . V_1128 ( V_8 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_465 ( V_18 ) ;
F_521 ( L_144 , V_1129 ) ;
V_1053 ++ ;
#ifdef F_525
if ( F_526 ( V_2 ) )
F_77 ( V_135 , L_145 ) ;
#endif
return 0 ;
V_1127:
F_44 ( V_2 ) ;
F_363 ( V_2 ) ;
V_1090:
F_527 ( V_2 ) ;
V_2 -> V_115 &= ~ V_574 ;
F_528 ( V_8 -> V_368 ) ;
V_1070:
F_529 ( V_18 ) ;
V_1065:
F_530 ( V_36 ,
F_504 ( V_36 , V_1063 ) ) ;
V_1064:
V_1062:
F_364 ( V_36 ) ;
return V_351 ;
}
static void T_16 F_531 ( struct V_619 * V_36 )
{
struct V_1 * V_2 = F_349 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
F_206 ( V_3 , & V_2 -> V_4 ) ;
F_532 ( & V_2 -> V_6 ) ;
#ifdef F_69
F_533 ( V_2 ) ;
#endif
#ifdef F_190
if ( V_2 -> V_100 & V_151 ) {
V_2 -> V_100 &= ~ V_151 ;
F_101 ( & V_36 -> V_37 ) ;
F_45 ( & V_2 -> V_8 , V_152 , 1 ) ;
}
#endif
#ifdef F_525
F_534 ( V_2 ) ;
#endif
F_467 ( V_18 ) ;
if ( V_18 -> V_861 == V_862 )
F_402 ( V_18 ) ;
F_527 ( V_2 ) ;
F_363 ( V_2 ) ;
F_44 ( V_2 ) ;
#ifdef F_535
F_197 ( V_2 -> V_99 ) ;
F_197 ( V_2 -> V_534 ) ;
#endif
F_528 ( V_2 -> V_8 . V_368 ) ;
F_530 ( V_36 , F_504 ( V_36 ,
V_1063 ) ) ;
F_521 ( L_146 ) ;
F_529 ( V_18 ) ;
F_536 ( V_36 ) ;
F_364 ( V_36 ) ;
}
static T_17 F_537 ( struct V_619 * V_36 ,
T_18 V_4 )
{
struct V_1 * V_2 = F_349 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
#ifdef F_323
struct V_619 * V_1130 , * V_1131 ;
T_1 V_1132 , V_1133 , V_1134 , V_1135 ;
int V_863 , V_1136 ;
T_5 V_1137 , V_1138 ;
if ( V_2 -> V_8 . V_72 . type == V_73 ||
V_2 -> V_271 == 0 )
goto V_1139;
V_1130 = V_36 -> V_1037 -> V_1140 ;
while ( V_1130 && ( V_1130 -> V_1141 != V_1142 ) )
V_1130 = V_1130 -> V_1037 -> V_1140 ;
if ( ! V_1130 )
goto V_1139;
V_1136 = F_538 ( V_1130 , V_1143 ) ;
if ( ! V_1136 )
goto V_1139;
F_539 ( V_1130 , V_1136 + V_1144 , & V_1132 ) ;
F_539 ( V_1130 , V_1136 + V_1144 + 4 , & V_1133 ) ;
F_539 ( V_1130 , V_1136 + V_1144 + 8 , & V_1134 ) ;
F_539 ( V_1130 , V_1136 + V_1144 + 12 , & V_1135 ) ;
V_1137 = V_1133 >> 16 ;
if ( ! ( V_1137 & 0x0080 ) )
goto V_1139;
V_1138 = V_1137 & 0x01 ;
if ( ( V_1138 & 1 ) == ( V_36 -> V_1145 & 1 ) ) {
unsigned int V_304 ;
V_863 = ( V_1137 & 0x7F ) >> 1 ;
F_300 ( L_147 , V_863 ) ;
F_300 ( L_148
L_149 ,
V_1132 , V_1133 , V_1134 , V_1135 ) ;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
V_304 = V_1146 ;
break;
case V_76 :
V_304 = V_1147 ;
break;
default:
V_304 = 0 ;
break;
}
V_1131 = F_540 ( V_1148 , V_304 , NULL ) ;
while ( V_1131 ) {
if ( V_1131 -> V_1145 == ( V_1137 & 0xFF ) )
break;
V_1131 = F_540 ( V_1148 ,
V_304 , V_1131 ) ;
}
if ( V_1131 ) {
F_300 ( L_150 , V_863 ) ;
F_541 ( V_1131 , 0xA8 , 0x00008000 ) ;
}
F_542 ( V_36 ) ;
}
V_2 -> V_1149 ++ ;
return V_1150 ;
V_1139:
#endif
F_362 ( V_18 ) ;
if ( V_4 == V_1151 )
return V_1152 ;
if ( F_31 ( V_18 ) )
F_296 ( V_2 ) ;
F_364 ( V_36 ) ;
return V_1153 ;
}
static T_17 F_543 ( struct V_619 * V_36 )
{
struct V_1 * V_2 = F_349 ( V_36 ) ;
T_17 V_1154 ;
int V_351 ;
if ( F_353 ( V_36 ) ) {
F_77 ( V_135 , L_151 ) ;
V_1154 = V_1152 ;
} else {
F_354 ( V_36 ) ;
F_351 ( V_36 ) ;
F_352 ( V_36 ) ;
F_355 ( V_36 , false ) ;
F_299 ( V_2 ) ;
F_45 ( & V_2 -> V_8 , V_687 , ~ 0 ) ;
V_1154 = V_1150 ;
}
V_351 = F_542 ( V_36 ) ;
if ( V_351 ) {
F_300 ( L_152
L_153 , V_351 ) ;
}
return V_1154 ;
}
static void F_544 ( struct V_619 * V_36 )
{
struct V_1 * V_2 = F_349 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
#ifdef F_323
if ( V_2 -> V_1149 ) {
F_79 ( V_133 , L_154 ) ;
V_2 -> V_1149 -- ;
return;
}
#endif
if ( F_31 ( V_18 ) )
F_298 ( V_2 ) ;
F_359 ( V_18 ) ;
}
static int T_19 F_545 ( void )
{
int V_114 ;
F_25 ( L_155 , V_1155 , V_1156 ) ;
F_25 ( L_144 , V_1157 ) ;
#ifdef F_190
F_546 ( & V_1158 ) ;
#endif
V_114 = F_547 ( & V_1159 ) ;
return V_114 ;
}
static void T_20 F_548 ( void )
{
#ifdef F_190
F_549 ( & V_1158 ) ;
#endif
F_550 ( & V_1159 ) ;
F_551 () ;
}
static int F_552 ( struct V_1160 * V_1161 , unsigned long V_155 ,
void * V_438 )
{
int V_1162 ;
V_1162 = F_553 ( & V_1159 . V_1163 , NULL , & V_155 ,
F_98 ) ;
return V_1162 ? V_1164 : V_1165 ;
}
