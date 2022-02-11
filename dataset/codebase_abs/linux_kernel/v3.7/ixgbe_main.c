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
V_186 -> V_63 = 0 ;
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
static void F_123 ( struct V_20 * V_82 ,
struct V_159 * V_53 )
{
T_5 V_218 = F_124 ( V_53 ) ;
F_125 ( V_53 ) -> V_219 = F_126 ( ( V_53 -> V_46 - V_218 ) ,
F_127 ( V_53 ) -> V_220 ) ;
}
static void F_128 ( struct V_20 * V_30 ,
struct V_159 * V_53 )
{
if ( ! F_127 ( V_53 ) -> V_220 )
return;
V_30 -> V_176 . V_221 += F_127 ( V_53 ) -> V_220 ;
V_30 -> V_176 . V_222 ++ ;
F_123 ( V_30 , V_53 ) ;
F_127 ( V_53 ) -> V_220 = 0 ;
}
static void F_129 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_159 * V_53 )
{
struct V_17 * V_37 = V_30 -> V_18 ;
F_128 ( V_30 , V_53 ) ;
F_102 ( V_30 , V_32 , V_53 ) ;
F_105 ( V_30 , V_32 , V_53 ) ;
#ifdef F_69
F_130 ( V_30 -> V_118 , V_32 , V_53 ) ;
#endif
if ( ( V_37 -> V_160 & V_223 ) &&
F_107 ( V_32 , V_224 ) ) {
T_5 V_225 = F_131 ( V_32 -> V_58 . V_59 . V_201 ) ;
F_132 ( V_53 , V_225 ) ;
}
F_133 ( V_53 , V_30 -> V_50 ) ;
V_53 -> V_205 = F_134 ( V_53 , V_37 ) ;
}
static void F_135 ( struct V_117 * V_118 ,
struct V_159 * V_53 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
if ( ! ( V_2 -> V_100 & V_226 ) )
F_136 ( & V_118 -> V_227 , V_53 ) ;
else
F_137 ( V_53 ) ;
}
static bool F_138 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_159 * V_53 )
{
T_1 V_228 = V_30 -> V_43 + 1 ;
V_228 = ( V_228 < V_30 -> V_52 ) ? V_228 : 0 ;
V_30 -> V_43 = V_228 ;
F_72 ( F_40 ( V_30 , V_228 ) ) ;
if ( F_139 ( V_30 ) ) {
T_9 V_229 = V_32 -> V_58 . V_163 . V_167 . V_56 &
F_68 ( V_230 ) ;
if ( F_70 ( V_229 ) ) {
T_1 V_231 = F_41 ( V_229 ) ;
V_231 >>= V_232 ;
F_127 ( V_53 ) -> V_220 += V_231 - 1 ;
V_228 = F_41 ( V_32 -> V_58 . V_59 . V_60 ) ;
V_228 &= V_233 ;
V_228 >>= V_234 ;
}
}
if ( F_73 ( F_107 ( V_32 , V_235 ) ) )
return false ;
V_30 -> V_34 [ V_228 ] . V_53 = V_53 ;
V_30 -> V_176 . V_236 ++ ;
return true ;
}
static void F_140 ( struct V_20 * V_30 ,
struct V_159 * V_53 )
{
struct V_237 * V_238 = & F_125 ( V_53 ) -> V_239 [ 0 ] ;
unsigned char * V_240 ;
unsigned int V_241 ;
V_240 = F_141 ( V_238 ) ;
V_241 = F_120 ( V_240 , V_242 ) ;
F_142 ( V_53 , V_240 , F_143 ( V_241 , sizeof( long ) ) ) ;
F_144 ( V_238 , V_241 ) ;
V_238 -> V_63 += V_241 ;
V_53 -> V_243 -= V_241 ;
V_53 -> V_109 += V_241 ;
}
static void F_145 ( struct V_20 * V_30 ,
struct V_159 * V_53 )
{
if ( F_70 ( F_127 ( V_53 ) -> V_244 ) ) {
F_54 ( V_30 -> V_37 , F_127 ( V_53 ) -> V_45 ,
F_115 ( V_30 ) , V_191 ) ;
F_127 ( V_53 ) -> V_244 = false ;
} else {
struct V_237 * V_238 = & F_125 ( V_53 ) -> V_239 [ 0 ] ;
F_146 ( V_30 -> V_37 ,
F_127 ( V_53 ) -> V_45 ,
V_238 -> V_63 ,
F_43 ( V_30 ) ,
V_191 ) ;
}
F_127 ( V_53 ) -> V_45 = 0 ;
}
static bool F_147 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_159 * V_53 )
{
struct V_17 * V_18 = V_30 -> V_18 ;
if ( F_70 ( F_107 ( V_32 ,
V_245 ) &&
! ( V_18 -> V_160 & V_246 ) ) ) {
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
int V_247 = 60 - V_53 -> V_46 ;
if ( F_149 ( V_53 , V_247 ) )
return true ;
F_150 ( V_53 , V_247 ) ;
}
return false ;
}
static void F_151 ( struct V_20 * V_30 ,
struct V_33 * V_248 )
{
struct V_33 * V_249 ;
T_5 V_250 = V_30 -> V_185 ;
V_249 = & V_30 -> V_34 [ V_250 ] ;
V_250 ++ ;
V_30 -> V_185 = ( V_250 < V_30 -> V_52 ) ? V_250 : 0 ;
V_249 -> V_62 = V_248 -> V_62 ;
V_249 -> V_45 = V_248 -> V_45 ;
V_249 -> V_63 = V_248 -> V_63 ;
F_152 ( V_30 -> V_37 , V_249 -> V_45 ,
V_249 -> V_63 ,
F_43 ( V_30 ) ,
V_191 ) ;
}
static bool F_153 ( struct V_20 * V_30 ,
struct V_33 * V_251 ,
union V_31 * V_32 ,
struct V_159 * V_53 )
{
struct V_62 * V_62 = V_251 -> V_62 ;
unsigned int V_252 = F_131 ( V_32 -> V_58 . V_59 . V_253 ) ;
#if ( V_254 < 8192 )
unsigned int V_255 = F_43 ( V_30 ) ;
#else
unsigned int V_255 = F_143 ( V_252 , V_256 ) ;
unsigned int V_257 = F_115 ( V_30 ) -
F_43 ( V_30 ) ;
#endif
if ( ( V_252 <= V_242 ) && ! F_148 ( V_53 ) ) {
unsigned char * V_240 = F_42 ( V_62 ) + V_251 -> V_63 ;
memcpy ( F_150 ( V_53 , V_252 ) , V_240 , F_143 ( V_252 , sizeof( long ) ) ) ;
if ( F_73 ( F_154 ( V_62 ) == F_155 () ) )
return true ;
F_156 ( V_62 ) ;
return false ;
}
F_157 ( V_53 , F_125 ( V_53 ) -> V_258 , V_62 ,
V_251 -> V_63 , V_252 , V_255 ) ;
if ( F_70 ( F_154 ( V_62 ) != F_155 () ) )
return false ;
#if ( V_254 < 8192 )
if ( F_70 ( F_158 ( V_62 ) != 1 ) )
return false ;
V_251 -> V_63 ^= V_255 ;
F_159 ( & V_62 -> V_259 , 2 ) ;
#else
V_251 -> V_63 += V_255 ;
if ( V_251 -> V_63 > V_257 )
return false ;
F_160 ( V_62 ) ;
#endif
return true ;
}
static struct V_159 * F_161 ( struct V_20 * V_30 ,
union V_31 * V_32 )
{
struct V_33 * V_251 ;
struct V_159 * V_53 ;
struct V_62 * V_62 ;
V_251 = & V_30 -> V_34 [ V_30 -> V_43 ] ;
V_62 = V_251 -> V_62 ;
F_162 ( V_62 ) ;
V_53 = V_251 -> V_53 ;
if ( F_73 ( ! V_53 ) ) {
void * V_260 = F_42 ( V_62 ) +
V_251 -> V_63 ;
F_72 ( V_260 ) ;
#if V_256 < 128
F_72 ( V_260 + V_256 ) ;
#endif
V_53 = F_163 ( V_30 -> V_18 ,
V_242 ) ;
if ( F_70 ( ! V_53 ) ) {
V_30 -> V_176 . V_261 ++ ;
return NULL ;
}
F_162 ( V_53 -> V_56 ) ;
if ( F_73 ( F_107 ( V_32 , V_235 ) ) )
goto V_262;
F_127 ( V_53 ) -> V_45 = V_251 -> V_45 ;
} else {
if ( F_107 ( V_32 , V_235 ) )
F_145 ( V_30 , V_53 ) ;
V_262:
F_146 ( V_30 -> V_37 ,
V_251 -> V_45 ,
V_251 -> V_63 ,
F_43 ( V_30 ) ,
V_191 ) ;
}
if ( F_153 ( V_30 , V_251 , V_32 , V_53 ) ) {
F_151 ( V_30 , V_251 ) ;
} else if ( F_127 ( V_53 ) -> V_45 == V_251 -> V_45 ) {
F_127 ( V_53 ) -> V_244 = true ;
} else {
F_54 ( V_30 -> V_37 , V_251 -> V_45 ,
F_115 ( V_30 ) ,
V_191 ) ;
}
V_251 -> V_53 = NULL ;
V_251 -> V_45 = 0 ;
V_251 -> V_62 = NULL ;
return V_53 ;
}
static bool F_164 ( struct V_117 * V_118 ,
struct V_20 * V_30 ,
int V_121 )
{
unsigned int V_263 = 0 , V_264 = 0 ;
#ifdef F_122
struct V_1 * V_2 = V_118 -> V_2 ;
int V_265 ;
unsigned int V_266 = 0 ;
#endif
T_5 V_192 = F_84 ( V_30 ) ;
do {
union V_31 * V_32 ;
struct V_159 * V_53 ;
if ( V_192 >= V_267 ) {
F_118 ( V_30 , V_192 ) ;
V_192 = 0 ;
}
V_32 = F_40 ( V_30 , V_30 -> V_43 ) ;
if ( ! F_107 ( V_32 , V_61 ) )
break;
F_67 () ;
V_53 = F_161 ( V_30 , V_32 ) ;
if ( ! V_53 )
break;
V_192 ++ ;
if ( F_138 ( V_30 , V_32 , V_53 ) )
continue;
if ( F_147 ( V_30 , V_32 , V_53 ) )
continue;
V_263 += V_53 -> V_46 ;
V_264 ++ ;
F_129 ( V_30 , V_32 , V_53 ) ;
#ifdef F_122
if ( F_103 ( V_30 , V_32 ) ) {
V_265 = F_165 ( V_2 , V_32 , V_53 ) ;
if ( V_265 > 0 ) {
if ( ! V_266 ) {
V_266 = V_30 -> V_18 -> V_268 -
sizeof( struct V_269 ) -
sizeof( struct V_270 ) -
sizeof( struct V_271 ) ;
if ( V_266 > 512 )
V_266 &= ~ 511 ;
}
V_263 += V_265 ;
V_264 += F_126 ( V_265 ,
V_266 ) ;
}
if ( ! V_265 ) {
F_52 ( V_53 ) ;
continue;
}
}
#endif
F_135 ( V_118 , V_53 ) ;
V_121 -- ;
} while ( F_73 ( V_121 ) );
F_74 ( & V_30 -> V_131 ) ;
V_30 -> V_86 . V_106 += V_264 ;
V_30 -> V_86 . V_132 += V_263 ;
F_75 ( & V_30 -> V_131 ) ;
V_118 -> V_272 . V_120 += V_264 ;
V_118 -> V_272 . V_119 += V_263 ;
if ( V_192 )
F_118 ( V_30 , V_192 ) ;
return ! ! V_121 ;
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_117 * V_118 ;
int V_273 ;
T_1 V_79 ;
if ( V_2 -> V_274 > 32 ) {
T_1 V_275 = ( 1 << ( V_2 -> V_274 - 32 ) ) - 1 ;
F_45 ( & V_2 -> V_8 , V_276 , V_275 ) ;
}
for ( V_273 = 0 ; V_273 < V_2 -> V_153 ; V_273 ++ ) {
struct V_20 * V_82 ;
V_118 = V_2 -> V_118 [ V_273 ] ;
F_95 (ring, q_vector->rx)
F_47 ( V_2 , 0 , V_82 -> V_108 , V_273 ) ;
F_95 (ring, q_vector->tx)
F_47 ( V_2 , 1 , V_82 -> V_108 , V_273 ) ;
if ( V_118 -> V_122 . V_82 && ! V_118 -> V_272 . V_82 ) {
if ( V_2 -> V_277 == 1 )
V_118 -> V_278 = V_279 ;
else
V_118 -> V_278 = V_2 -> V_277 ;
} else {
if ( V_2 -> V_280 == 1 )
V_118 -> V_278 = V_281 ;
else
V_118 -> V_278 = V_2 -> V_280 ;
}
F_167 ( V_118 ) ;
}
switch ( V_2 -> V_8 . V_72 . type ) {
case V_73 :
F_47 ( V_2 , - 1 , V_282 ,
V_273 ) ;
break;
case V_75 :
case V_76 :
F_47 ( V_2 , - 1 , 1 , V_273 ) ;
break;
default:
break;
}
F_45 ( & V_2 -> V_8 , F_168 ( V_273 ) , 1950 ) ;
V_79 = V_283 ;
V_79 &= ~ ( V_284 |
V_285 |
V_286 ) ;
F_45 ( & V_2 -> V_8 , V_287 , V_79 ) ;
}
static void F_169 ( struct V_117 * V_118 ,
struct V_288 * V_289 )
{
int V_132 = V_289 -> V_119 ;
int V_106 = V_289 -> V_120 ;
T_1 V_290 ;
T_2 V_291 ;
T_4 V_292 = V_289 -> V_278 ;
if ( V_106 == 0 )
return;
V_290 = V_118 -> V_278 >> 2 ;
V_291 = V_132 / V_290 ;
switch ( V_292 ) {
case V_293 :
if ( V_291 > 10 )
V_292 = V_294 ;
break;
case V_294 :
if ( V_291 > 20 )
V_292 = V_295 ;
else if ( V_291 <= 10 )
V_292 = V_293 ;
break;
case V_295 :
if ( V_291 <= 20 )
V_292 = V_294 ;
break;
}
V_289 -> V_119 = 0 ;
V_289 -> V_120 = 0 ;
V_289 -> V_278 = V_292 ;
}
void F_167 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_273 = V_118 -> V_273 ;
T_1 V_296 = V_118 -> V_278 & V_297 ;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_73 :
V_296 |= ( V_296 << 16 ) ;
break;
case V_75 :
case V_76 :
V_296 |= V_298 ;
break;
default:
break;
}
F_45 ( V_8 , F_168 ( V_273 ) , V_296 ) ;
}
static void F_170 ( struct V_117 * V_118 )
{
T_1 V_299 = V_118 -> V_278 ;
T_4 V_300 ;
F_169 ( V_118 , & V_118 -> V_122 ) ;
F_169 ( V_118 , & V_118 -> V_272 ) ;
V_300 = F_171 ( V_118 -> V_272 . V_278 , V_118 -> V_122 . V_278 ) ;
switch ( V_300 ) {
case V_293 :
V_299 = V_301 ;
break;
case V_294 :
V_299 = V_281 ;
break;
case V_295 :
V_299 = V_302 ;
break;
default:
break;
}
if ( V_299 != V_118 -> V_278 ) {
V_299 = ( 10 * V_299 * V_118 -> V_278 ) /
( ( 9 * V_299 ) + V_118 -> V_278 ) ;
V_118 -> V_278 = V_299 ;
F_167 ( V_118 ) ;
}
}
static void F_172 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_303 = V_2 -> V_304 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
if ( ! ( V_2 -> V_115 & V_305 ) &&
! ( V_2 -> V_115 & V_306 ) )
return;
V_2 -> V_115 &= ~ V_306 ;
switch ( V_8 -> V_307 ) {
case V_308 :
if ( ! ( V_303 & V_309 ) &&
! ( V_303 & V_310 ) )
return;
if ( ! ( V_303 & V_310 ) && V_8 -> V_72 . V_311 . V_312 ) {
T_1 V_313 ;
bool V_314 = false ;
V_8 -> V_72 . V_311 . V_312 ( V_8 , & V_313 , & V_314 , false ) ;
if ( V_314 )
return;
}
if ( V_8 -> V_315 . V_311 . V_316 ( V_8 ) != V_317 )
return;
break;
default:
if ( ! ( V_303 & V_309 ) )
return;
break;
}
F_173 ( V_133 ,
L_51
L_52
L_53 ) ;
V_2 -> V_304 = 0 ;
}
static void F_174 ( struct V_1 * V_2 , T_1 V_303 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( ( V_2 -> V_100 & V_318 ) &&
( V_303 & V_319 ) ) {
F_173 ( V_135 , L_54 ) ;
F_45 ( V_8 , V_320 , V_319 ) ;
}
}
static void F_175 ( struct V_1 * V_2 , T_1 V_303 )
{
if ( ! ( V_2 -> V_115 & V_305 ) )
return;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
if ( ( ( V_303 & V_309 ) || ( V_303 & V_310 ) ) &&
( ! F_2 ( V_3 , & V_2 -> V_4 ) ) ) {
V_2 -> V_304 = V_303 ;
V_2 -> V_115 |= V_306 ;
F_1 ( V_2 ) ;
return;
}
return;
case V_76 :
if ( ! ( V_303 & V_321 ) )
return;
break;
default:
return;
}
F_173 ( V_133 ,
L_51
L_52
L_53 ) ;
}
static void F_176 ( struct V_1 * V_2 , T_1 V_303 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( V_303 & V_322 ) {
F_45 ( V_8 , V_320 , V_322 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_115 |= V_323 ;
F_1 ( V_2 ) ;
}
}
if ( V_303 & V_319 ) {
F_45 ( V_8 , V_320 , V_319 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_100 |= V_324 ;
F_1 ( V_2 ) ;
}
}
}
static void F_177 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
V_2 -> V_325 ++ ;
V_2 -> V_100 |= V_326 ;
V_2 -> V_327 = V_134 ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_45 ( V_8 , V_328 , V_329 ) ;
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
F_45 ( V_8 , V_330 , V_79 ) ;
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
F_45 ( V_8 , V_328 , V_79 ) ;
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
static inline void F_183 ( struct V_1 * V_2 , bool V_331 ,
bool V_332 )
{
T_1 V_79 = ( V_283 & ~ V_80 ) ;
if ( V_2 -> V_100 & V_326 )
V_79 &= ~ V_286 ;
if ( V_2 -> V_115 & V_305 )
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
V_79 |= V_333 ;
break;
case V_76 :
V_79 |= V_334 ;
break;
default:
break;
}
if ( V_2 -> V_100 & V_318 )
V_79 |= V_335 ;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
V_79 |= V_335 ;
V_79 |= V_336 ;
case V_76 :
V_79 |= V_337 ;
V_79 |= V_285 ;
break;
default:
break;
}
#ifdef F_69
if ( V_2 -> V_8 . V_72 . type == V_76 )
V_79 |= V_338 ;
#endif
if ( ( V_2 -> V_100 & V_339 ) &&
! ( V_2 -> V_115 & V_340 ) )
V_79 |= V_341 ;
F_45 ( & V_2 -> V_8 , V_330 , V_79 ) ;
if ( V_331 )
F_179 ( V_2 , ~ 0 ) ;
if ( V_332 )
F_178 ( & V_2 -> V_8 ) ;
}
static T_10 F_184 ( int V_342 , void * V_56 )
{
struct V_1 * V_2 = V_56 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_303 ;
V_303 = F_11 ( V_8 , V_81 ) ;
F_45 ( V_8 , V_320 , V_303 ) ;
if ( V_303 & V_310 )
F_177 ( V_2 ) ;
if ( V_303 & V_343 )
F_185 ( V_2 ) ;
switch ( V_8 -> V_72 . type ) {
case V_75 :
case V_76 :
if ( V_303 & V_344 )
F_79 ( V_345 , L_55
L_56 ) ;
if ( V_303 & V_346 ) {
int V_347 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_82 = V_2 -> V_21 [ V_11 ] ;
if ( F_186 ( V_348 ,
& V_82 -> V_4 ) )
V_347 ++ ;
}
if ( V_347 ) {
F_45 ( V_8 , V_328 , V_349 ) ;
V_2 -> V_115 |= V_340 ;
F_1 ( V_2 ) ;
}
}
F_176 ( V_2 , V_303 ) ;
F_175 ( V_2 , V_303 ) ;
break;
default:
break;
}
F_174 ( V_2 , V_303 ) ;
#ifdef F_69
if ( F_70 ( V_303 & V_350 ) )
F_187 ( V_2 , V_303 ) ;
#endif
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_183 ( V_2 , false , false ) ;
return V_351 ;
}
static T_10 F_188 ( int V_342 , void * V_56 )
{
struct V_117 * V_118 = V_56 ;
if ( V_118 -> V_272 . V_82 || V_118 -> V_122 . V_82 )
F_189 ( & V_118 -> V_227 ) ;
return V_351 ;
}
int F_190 ( struct V_352 * V_227 , int V_121 )
{
struct V_117 * V_118 =
F_191 ( V_227 , struct V_117 , V_227 ) ;
struct V_1 * V_2 = V_118 -> V_2 ;
struct V_20 * V_82 ;
int V_353 ;
bool V_354 = true ;
#ifdef F_192
if ( V_2 -> V_100 & V_151 )
F_93 ( V_118 ) ;
#endif
F_95 (ring, q_vector->tx)
V_354 &= ! ! F_66 ( V_118 , V_82 ) ;
if ( V_118 -> V_272 . V_52 > 1 )
V_353 = F_171 ( V_121 / V_118 -> V_272 . V_52 , 1 ) ;
else
V_353 = V_121 ;
F_95 (ring, q_vector->rx)
V_354 &= F_164 ( V_118 , V_82 ,
V_353 ) ;
if ( ! V_354 )
return V_121 ;
F_193 ( V_227 ) ;
if ( V_2 -> V_280 & 1 )
F_170 ( V_118 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_179 ( V_2 , ( ( T_2 ) 1 << V_118 -> V_273 ) ) ;
return 0 ;
}
static int F_194 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
int V_355 , V_356 ;
int V_357 = 0 , V_358 = 0 ;
for ( V_355 = 0 ; V_355 < V_2 -> V_153 ; V_355 ++ ) {
struct V_117 * V_118 = V_2 -> V_118 [ V_355 ] ;
struct V_359 * V_360 = & V_2 -> V_361 [ V_355 ] ;
if ( V_118 -> V_122 . V_82 && V_118 -> V_272 . V_82 ) {
snprintf ( V_118 -> V_16 , sizeof( V_118 -> V_16 ) - 1 ,
L_57 , V_18 -> V_16 , L_58 , V_357 ++ ) ;
V_358 ++ ;
} else if ( V_118 -> V_272 . V_82 ) {
snprintf ( V_118 -> V_16 , sizeof( V_118 -> V_16 ) - 1 ,
L_57 , V_18 -> V_16 , L_59 , V_357 ++ ) ;
} else if ( V_118 -> V_122 . V_82 ) {
snprintf ( V_118 -> V_16 , sizeof( V_118 -> V_16 ) - 1 ,
L_57 , V_18 -> V_16 , L_60 , V_358 ++ ) ;
} else {
continue;
}
V_356 = F_195 ( V_360 -> V_355 , & F_188 , 0 ,
V_118 -> V_16 , V_118 ) ;
if ( V_356 ) {
F_77 ( V_135 , L_61
L_62 , V_356 ) ;
goto V_362;
}
if ( V_2 -> V_100 & V_339 ) {
F_196 ( V_360 -> V_355 ,
& V_118 -> V_363 ) ;
}
}
V_356 = F_195 ( V_2 -> V_361 [ V_355 ] . V_355 ,
F_184 , 0 , V_18 -> V_16 , V_2 ) ;
if ( V_356 ) {
F_77 ( V_135 , L_63 , V_356 ) ;
goto V_362;
}
return 0 ;
V_362:
while ( V_355 ) {
V_355 -- ;
F_196 ( V_2 -> V_361 [ V_355 ] . V_355 ,
NULL ) ;
F_197 ( V_2 -> V_361 [ V_355 ] . V_355 ,
V_2 -> V_118 [ V_355 ] ) ;
}
V_2 -> V_100 &= ~ V_364 ;
F_198 ( V_2 -> V_36 ) ;
F_199 ( V_2 -> V_361 ) ;
V_2 -> V_361 = NULL ;
return V_356 ;
}
static T_10 F_200 ( int V_342 , void * V_56 )
{
struct V_1 * V_2 = V_56 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_117 * V_118 = V_2 -> V_118 [ 0 ] ;
T_1 V_303 ;
F_45 ( V_8 , V_328 , V_365 ) ;
V_303 = F_11 ( V_8 , V_320 ) ;
if ( ! V_303 ) {
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_183 ( V_2 , true , true ) ;
return V_366 ;
}
if ( V_303 & V_310 )
F_177 ( V_2 ) ;
switch ( V_8 -> V_72 . type ) {
case V_75 :
F_176 ( V_2 , V_303 ) ;
case V_76 :
if ( V_303 & V_344 )
F_79 ( V_345 , L_64
L_56 ) ;
F_175 ( V_2 , V_303 ) ;
break;
default:
break;
}
F_174 ( V_2 , V_303 ) ;
#ifdef F_69
if ( F_70 ( V_303 & V_350 ) )
F_187 ( V_2 , V_303 ) ;
#endif
F_189 ( & V_118 -> V_227 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_183 ( V_2 , false , false ) ;
return V_351 ;
}
static int F_201 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
int V_356 ;
if ( V_2 -> V_100 & V_364 )
V_356 = F_194 ( V_2 ) ;
else if ( V_2 -> V_100 & V_367 )
V_356 = F_195 ( V_2 -> V_36 -> V_342 , F_200 , 0 ,
V_18 -> V_16 , V_2 ) ;
else
V_356 = F_195 ( V_2 -> V_36 -> V_342 , F_200 , V_368 ,
V_18 -> V_16 , V_2 ) ;
if ( V_356 )
F_77 ( V_135 , L_65 , V_356 ) ;
return V_356 ;
}
static void F_202 ( struct V_1 * V_2 )
{
int V_355 ;
if ( ! ( V_2 -> V_100 & V_364 ) ) {
F_197 ( V_2 -> V_36 -> V_342 , V_2 ) ;
return;
}
for ( V_355 = 0 ; V_355 < V_2 -> V_153 ; V_355 ++ ) {
struct V_117 * V_118 = V_2 -> V_118 [ V_355 ] ;
struct V_359 * V_360 = & V_2 -> V_361 [ V_355 ] ;
if ( ! V_118 -> V_272 . V_82 && ! V_118 -> V_122 . V_82 )
continue;
F_196 ( V_360 -> V_355 , NULL ) ;
F_197 ( V_360 -> V_355 , V_118 ) ;
}
F_197 ( V_2 -> V_361 [ V_355 ++ ] . V_355 , V_2 ) ;
}
static inline void F_203 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 . V_72 . type ) {
case V_73 :
F_45 ( & V_2 -> V_8 , V_328 , ~ 0 ) ;
break;
case V_75 :
case V_76 :
F_45 ( & V_2 -> V_8 , V_328 , 0xFFFF0000 ) ;
F_45 ( & V_2 -> V_8 , F_182 ( 0 ) , ~ 0 ) ;
F_45 ( & V_2 -> V_8 , F_182 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_178 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_100 & V_364 ) {
int V_355 ;
for ( V_355 = 0 ; V_355 < V_2 -> V_153 ; V_355 ++ )
F_204 ( V_2 -> V_361 [ V_355 ] . V_355 ) ;
F_204 ( V_2 -> V_361 [ V_355 ++ ] . V_355 ) ;
} else {
F_204 ( V_2 -> V_36 -> V_342 ) ;
}
}
static void F_205 ( struct V_1 * V_2 )
{
struct V_117 * V_118 = V_2 -> V_118 [ 0 ] ;
if ( V_2 -> V_280 == 1 )
V_118 -> V_278 = V_281 ;
else
V_118 -> V_278 = V_2 -> V_280 ;
F_167 ( V_118 ) ;
F_47 ( V_2 , 0 , 0 , 0 ) ;
F_47 ( V_2 , 1 , 0 , 0 ) ;
F_79 ( V_8 , L_66 ) ;
}
void F_206 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_369 = V_82 -> V_45 ;
int V_370 = 10 ;
T_1 V_371 = V_372 ;
T_4 V_108 = V_82 -> V_108 ;
F_45 ( V_8 , F_24 ( V_108 ) , 0 ) ;
F_178 ( V_8 ) ;
F_45 ( V_8 , F_19 ( V_108 ) ,
( V_369 & F_207 ( 32 ) ) ) ;
F_45 ( V_8 , F_20 ( V_108 ) , ( V_369 >> 32 ) ) ;
F_45 ( V_8 , F_21 ( V_108 ) ,
V_82 -> V_52 * sizeof( union V_24 ) ) ;
F_45 ( V_8 , F_22 ( V_108 ) , 0 ) ;
F_45 ( V_8 , F_23 ( V_108 ) , 0 ) ;
V_82 -> V_109 = V_8 -> V_373 + F_23 ( V_108 ) ;
if ( ! V_82 -> V_118 || ( V_82 -> V_118 -> V_278 < 8 ) )
V_371 |= ( 1 << 16 ) ;
else
V_371 |= ( 8 << 16 ) ;
V_371 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_100 & V_339 ) {
V_82 -> V_374 = V_2 -> V_374 ;
V_82 -> V_375 = 0 ;
F_208 ( V_348 , & V_82 -> V_4 ) ;
} else {
V_82 -> V_374 = 0 ;
}
F_8 ( V_94 , & V_82 -> V_4 ) ;
F_45 ( V_8 , F_24 ( V_108 ) , V_371 ) ;
if ( V_8 -> V_72 . type == V_73 &&
! ( F_11 ( V_8 , V_376 ) & V_377 ) )
return;
do {
F_209 ( 1000 , 2000 ) ;
V_371 = F_11 ( V_8 , F_24 ( V_108 ) ) ;
} while ( -- V_370 && ! ( V_371 & V_372 ) );
if ( ! V_370 )
F_77 ( V_133 , L_67 , V_108 ) ;
}
static void F_210 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_378 , V_379 ;
T_4 V_380 = F_211 ( V_2 -> V_18 ) ;
if ( V_8 -> V_72 . type == V_73 )
return;
V_378 = F_11 ( V_8 , V_381 ) ;
V_378 |= V_382 ;
F_45 ( V_8 , V_381 , V_378 ) ;
if ( V_2 -> V_100 & V_383 ) {
V_379 = V_384 ;
if ( V_380 > 4 )
V_379 |= V_385 | V_386 ;
else if ( V_380 > 1 )
V_379 |= V_385 | V_387 ;
else if ( V_2 -> V_388 [ V_389 ] . V_390 == 4 )
V_379 |= V_391 ;
else
V_379 |= V_392 ;
} else {
if ( V_380 > 4 )
V_379 = V_385 | V_386 ;
else if ( V_380 > 1 )
V_379 = V_385 | V_387 ;
else
V_379 = V_393 ;
}
F_45 ( V_8 , V_394 , V_379 ) ;
if ( V_380 ) {
T_1 V_395 = F_11 ( V_8 , V_396 ) ;
V_395 |= V_397 ;
F_45 ( V_8 , V_396 , V_395 ) ;
}
V_378 &= ~ V_382 ;
F_45 ( V_8 , V_381 , V_378 ) ;
}
static void F_212 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_398 ;
T_1 V_11 ;
F_210 ( V_2 ) ;
if ( V_8 -> V_72 . type != V_73 ) {
V_398 = F_11 ( V_8 , V_399 ) ;
V_398 |= V_400 ;
F_45 ( V_8 , V_399 , V_398 ) ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_206 ( V_2 , V_2 -> V_21 [ V_11 ] ) ;
}
static void F_213 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_4 V_108 = V_82 -> V_108 ;
T_1 V_401 = F_11 ( V_8 , F_10 ( V_108 ) ) ;
V_401 |= V_402 ;
F_45 ( V_8 , F_10 ( V_108 ) , V_401 ) ;
}
static void F_214 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_4 V_108 = V_82 -> V_108 ;
T_1 V_401 = F_11 ( V_8 , F_10 ( V_108 ) ) ;
V_401 &= ~ V_402 ;
F_45 ( V_8 , F_10 ( V_108 ) , V_401 ) ;
}
static void F_215 ( struct V_1 * V_2 ,
struct V_20 * V_30 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_401 ;
T_4 V_108 = V_30 -> V_108 ;
if ( V_8 -> V_72 . type == V_73 ) {
T_5 V_79 = V_2 -> V_388 [ V_389 ] . V_79 ;
V_108 &= V_79 ;
}
V_401 = V_242 << V_403 ;
V_401 |= F_43 ( V_30 ) >> V_404 ;
V_401 |= V_405 ;
F_45 ( V_8 , F_10 ( V_108 ) , V_401 ) ;
}
static void F_216 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
static const T_1 V_406 [ 10 ] = { 0xE291D73D , 0x1805EC6C , 0x2A94B30D ,
0xA54F2BEC , 0xEA49AF7C , 0xE214AD3D , 0xB855AABE ,
0x6A3E67EA , 0x14364D17 , 0x3BED200D } ;
T_1 V_407 = 0 , V_408 = 0 ;
T_1 V_409 ;
int V_11 , V_12 ;
T_5 V_410 = V_2 -> V_388 [ V_389 ] . V_390 ;
if ( ( V_2 -> V_100 & V_383 ) && ( V_410 < 2 ) )
V_410 = 2 ;
for ( V_11 = 0 ; V_11 < 10 ; V_11 ++ )
F_45 ( V_8 , F_217 ( V_11 ) , V_406 [ V_11 ] ) ;
for ( V_11 = 0 , V_12 = 0 ; V_11 < 128 ; V_11 ++ , V_12 ++ ) {
if ( V_12 == V_410 )
V_12 = 0 ;
V_408 = ( V_408 << 8 ) | ( V_12 * 0x11 ) ;
if ( ( V_11 & 3 ) == 3 )
F_45 ( V_8 , F_218 ( V_11 >> 2 ) , V_408 ) ;
}
V_409 = F_11 ( V_8 , V_411 ) ;
V_409 |= V_412 ;
F_45 ( V_8 , V_411 , V_409 ) ;
if ( V_2 -> V_8 . V_72 . type == V_73 ) {
if ( V_2 -> V_388 [ V_389 ] . V_79 )
V_407 = V_413 ;
} else {
T_4 V_380 = F_211 ( V_2 -> V_18 ) ;
if ( V_2 -> V_100 & V_383 ) {
if ( V_380 > 4 )
V_407 = V_414 ;
else if ( V_380 > 1 )
V_407 = V_415 ;
else if ( V_2 -> V_388 [ V_389 ] . V_390 == 4 )
V_407 = V_416 ;
else
V_407 = V_417 ;
} else {
if ( V_380 > 4 )
V_407 = V_418 ;
else if ( V_380 > 1 )
V_407 = V_419 ;
else
V_407 = V_413 ;
}
}
V_407 |= V_420 |
V_421 |
V_422 |
V_423 ;
if ( V_2 -> V_115 & V_424 )
V_407 |= V_425 ;
if ( V_2 -> V_115 & V_426 )
V_407 |= V_427 ;
F_45 ( V_8 , V_428 , V_407 ) ;
}
static void F_219 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_429 ;
T_4 V_108 = V_82 -> V_108 ;
if ( ! F_139 ( V_82 ) )
return;
V_429 = F_11 ( V_8 , F_220 ( V_108 ) ) ;
V_429 |= V_430 ;
V_429 |= V_431 ;
F_45 ( V_8 , F_220 ( V_108 ) , V_429 ) ;
}
static void F_221 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_370 = V_432 ;
T_1 V_433 ;
T_4 V_108 = V_82 -> V_108 ;
if ( V_8 -> V_72 . type == V_73 &&
! ( F_11 ( V_8 , V_376 ) & V_377 ) )
return;
do {
F_209 ( 1000 , 2000 ) ;
V_433 = F_11 ( V_8 , F_16 ( V_108 ) ) ;
} while ( -- V_370 && ! ( V_433 & V_434 ) );
if ( ! V_370 ) {
F_77 ( V_133 , L_68
L_69 , V_108 ) ;
}
}
void F_222 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_370 = V_432 ;
T_1 V_433 ;
T_4 V_108 = V_82 -> V_108 ;
V_433 = F_11 ( V_8 , F_16 ( V_108 ) ) ;
V_433 &= ~ V_434 ;
F_45 ( V_8 , F_16 ( V_108 ) , V_433 ) ;
if ( V_8 -> V_72 . type == V_73 &&
! ( F_11 ( V_8 , V_376 ) & V_377 ) )
return;
do {
F_223 ( 10 ) ;
V_433 = F_11 ( V_8 , F_16 ( V_108 ) ) ;
} while ( -- V_370 && ( V_433 & V_434 ) );
if ( ! V_370 ) {
F_77 ( V_133 , L_70
L_69 , V_108 ) ;
}
}
void F_224 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_435 = V_82 -> V_45 ;
T_1 V_433 ;
T_4 V_108 = V_82 -> V_108 ;
V_433 = F_11 ( V_8 , F_16 ( V_108 ) ) ;
F_222 ( V_2 , V_82 ) ;
F_45 ( V_8 , F_17 ( V_108 ) , ( V_435 & F_207 ( 32 ) ) ) ;
F_45 ( V_8 , F_18 ( V_108 ) , ( V_435 >> 32 ) ) ;
F_45 ( V_8 , F_13 ( V_108 ) ,
V_82 -> V_52 * sizeof( union V_31 ) ) ;
F_45 ( V_8 , F_14 ( V_108 ) , 0 ) ;
F_45 ( V_8 , F_15 ( V_108 ) , 0 ) ;
V_82 -> V_109 = V_8 -> V_373 + F_15 ( V_108 ) ;
F_215 ( V_2 , V_82 ) ;
F_219 ( V_2 , V_82 ) ;
if ( ( V_2 -> V_100 & V_383 ) &&
V_8 -> V_72 . type == V_76 ) {
V_433 &= ~ V_436 ;
V_433 |= ( ( V_82 -> V_18 -> V_268 + V_208 +
V_437 + V_211 ) | V_438 ) ;
}
if ( V_8 -> V_72 . type == V_73 ) {
V_433 &= ~ 0x3FFFFF ;
V_433 |= 0x080420 ;
}
V_433 |= V_434 ;
F_45 ( V_8 , F_16 ( V_108 ) , V_433 ) ;
F_221 ( V_2 , V_82 ) ;
F_118 ( V_82 , F_84 ( V_82 ) ) ;
}
static void F_225 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_410 = V_2 -> V_388 [ V_389 ] . V_390 ;
int V_439 ;
T_1 V_440 = V_441 |
V_442 |
V_443 |
V_444 |
V_445 ;
if ( V_8 -> V_72 . type == V_73 )
return;
if ( V_410 > 3 )
V_440 |= 2 << 29 ;
else if ( V_410 > 1 )
V_440 |= 1 << 29 ;
for ( V_439 = 0 ; V_439 < V_2 -> V_446 ; V_439 ++ )
F_45 ( V_8 , F_226 ( F_227 ( V_439 ) ) ,
V_440 ) ;
}
static void F_228 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_140 , V_447 ;
T_1 V_448 , V_449 ;
int V_11 ;
if ( ! ( V_2 -> V_100 & V_383 ) )
return;
V_449 = F_11 ( V_8 , V_450 ) ;
V_449 |= V_451 ;
V_449 &= ~ V_452 ;
V_449 |= F_227 ( 0 ) << V_453 ;
V_449 |= V_454 ;
F_45 ( V_8 , V_450 , V_449 ) ;
V_447 = F_227 ( 0 ) % 32 ;
V_140 = ( F_227 ( 0 ) >= 32 ) ? 1 : 0 ;
F_45 ( V_8 , F_229 ( V_140 ) , ( ~ 0 ) << V_447 ) ;
F_45 ( V_8 , F_229 ( V_140 ^ 1 ) , V_140 - 1 ) ;
F_45 ( V_8 , F_230 ( V_140 ) , ( ~ 0 ) << V_447 ) ;
F_45 ( V_8 , F_230 ( V_140 ^ 1 ) , V_140 - 1 ) ;
F_45 ( V_8 , V_455 , V_456 ) ;
V_8 -> V_72 . V_311 . V_457 ( V_8 , 0 , F_227 ( 0 ) ) ;
switch ( V_2 -> V_388 [ V_458 ] . V_79 ) {
case V_459 :
V_448 = V_460 ;
break;
case V_461 :
V_448 = V_462 ;
break;
default:
V_448 = V_463 ;
break;
}
F_45 ( V_8 , V_464 , V_448 ) ;
F_45 ( V_8 , V_455 , V_456 ) ;
V_8 -> V_72 . V_311 . V_465 ( V_8 , ( V_2 -> V_274 != 0 ) ,
V_2 -> V_274 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_274 ; V_11 ++ ) {
if ( ! V_2 -> V_466 [ V_11 ] . V_467 )
F_231 ( V_2 -> V_18 , V_11 , false ) ;
}
}
static void F_232 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_18 = V_2 -> V_18 ;
int V_468 = V_18 -> V_268 + V_208 + V_437 ;
struct V_20 * V_30 ;
int V_11 ;
T_1 V_469 , V_470 ;
#ifdef F_122
if ( ( V_2 -> V_100 & V_471 ) &&
( V_468 < V_472 ) )
V_468 = V_472 ;
#endif
V_469 = F_11 ( V_8 , V_473 ) ;
if ( V_468 != ( V_469 >> V_474 ) ) {
V_469 &= ~ V_475 ;
V_469 |= V_468 << V_474 ;
F_45 ( V_8 , V_473 , V_469 ) ;
}
V_468 += V_211 ;
V_470 = F_11 ( V_8 , V_476 ) ;
V_470 |= V_477 ;
F_45 ( V_8 , V_476 , V_470 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
V_30 = V_2 -> V_30 [ V_11 ] ;
if ( V_2 -> V_115 & V_478 )
F_233 ( V_30 ) ;
else
F_234 ( V_30 ) ;
}
}
static void F_235 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_479 = F_11 ( V_8 , V_480 ) ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_479 |= V_481 ;
break;
case V_75 :
case V_76 :
F_45 ( V_8 , V_482 ,
( V_483 | F_11 ( V_8 , V_482 ) ) ) ;
V_479 &= ~ V_484 ;
V_479 |= ( V_485 | V_486 ) ;
V_479 |= V_487 ;
break;
default:
return;
}
F_45 ( V_8 , V_480 , V_479 ) ;
}
static void F_236 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_11 ;
T_1 V_145 ;
V_145 = F_11 ( V_8 , V_488 ) ;
F_45 ( V_8 , V_488 , V_145 & ~ V_489 ) ;
F_225 ( V_2 ) ;
F_235 ( V_2 ) ;
F_216 ( V_2 ) ;
F_232 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ )
F_224 ( V_2 , V_2 -> V_30 [ V_11 ] ) ;
if ( V_8 -> V_72 . type == V_73 )
V_145 |= V_490 ;
V_145 |= V_489 ;
V_8 -> V_72 . V_311 . V_491 ( V_8 , V_145 ) ;
}
static int F_237 ( struct V_17 * V_18 , T_5 V_225 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
V_8 -> V_72 . V_311 . V_492 ( & V_2 -> V_8 , V_225 , F_227 ( 0 ) , true ) ;
F_208 ( V_225 , V_2 -> V_493 ) ;
return 0 ;
}
static int F_238 ( struct V_17 * V_18 , T_5 V_225 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
V_8 -> V_72 . V_311 . V_492 ( & V_2 -> V_8 , V_225 , F_227 ( 0 ) , false ) ;
F_8 ( V_225 , V_2 -> V_493 ) ;
return 0 ;
}
static void F_239 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_494 ;
V_494 = F_11 ( V_8 , V_495 ) ;
V_494 &= ~ ( V_496 | V_497 ) ;
F_45 ( V_8 , V_495 , V_494 ) ;
}
static void F_240 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_494 ;
V_494 = F_11 ( V_8 , V_495 ) ;
V_494 |= V_496 ;
V_494 &= ~ V_497 ;
F_45 ( V_8 , V_495 , V_494 ) ;
}
static void F_241 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_494 ;
int V_11 , V_12 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_494 = F_11 ( V_8 , V_495 ) ;
V_494 &= ~ V_498 ;
F_45 ( V_8 , V_495 , V_494 ) ;
break;
case V_75 :
case V_76 :
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
V_12 = V_2 -> V_30 [ V_11 ] -> V_108 ;
V_494 = F_11 ( V_8 , F_16 ( V_12 ) ) ;
V_494 &= ~ V_499 ;
F_45 ( V_8 , F_16 ( V_12 ) , V_494 ) ;
}
break;
default:
break;
}
}
static void F_242 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_494 ;
int V_11 , V_12 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_494 = F_11 ( V_8 , V_495 ) ;
V_494 |= V_498 ;
F_45 ( V_8 , V_495 , V_494 ) ;
break;
case V_75 :
case V_76 :
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
V_12 = V_2 -> V_30 [ V_11 ] -> V_108 ;
V_494 = F_11 ( V_8 , F_16 ( V_12 ) ) ;
V_494 |= V_499 ;
F_45 ( V_8 , F_16 ( V_12 ) , V_494 ) ;
}
break;
default:
break;
}
}
static void F_243 ( struct V_1 * V_2 )
{
T_5 V_225 ;
F_237 ( V_2 -> V_18 , 0 ) ;
F_244 (vid, adapter->active_vlans, VLAN_N_VID)
F_237 ( V_2 -> V_18 , V_225 ) ;
}
static int F_245 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
unsigned int V_500 = V_8 -> V_72 . V_501 - 1 ;
int V_52 = 0 ;
if ( V_2 -> V_100 & V_383 )
V_500 = V_502 - 1 ;
if ( F_246 ( V_18 ) > V_500 )
return - V_503 ;
if ( ! F_247 ( V_18 ) ) {
struct V_504 * V_505 ;
if ( ! V_8 -> V_72 . V_311 . V_506 )
return - V_503 ;
F_248 (ha, netdev) {
if ( ! V_500 )
break;
V_8 -> V_72 . V_311 . V_506 ( V_8 , V_500 -- , V_505 -> V_507 ,
F_227 ( 0 ) , V_508 ) ;
V_52 ++ ;
}
}
for (; V_500 > 0 ; V_500 -- )
V_8 -> V_72 . V_311 . V_509 ( V_8 , V_500 ) ;
return V_52 ;
}
void F_249 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_510 , V_511 = V_512 | V_513 ;
int V_52 ;
V_510 = F_11 ( V_8 , V_514 ) ;
V_510 &= ~ V_515 ;
V_510 |= V_516 ;
V_510 |= V_517 ;
V_510 |= V_518 ;
V_510 &= ~ ( V_519 | V_520 ) ;
if ( V_18 -> V_100 & V_521 ) {
V_8 -> V_522 . V_523 = true ;
V_510 |= ( V_519 | V_520 ) ;
V_511 |= ( V_524 | V_525 ) ;
F_239 ( V_2 ) ;
} else {
if ( V_18 -> V_100 & V_526 ) {
V_510 |= V_520 ;
V_511 |= V_525 ;
} else {
V_8 -> V_72 . V_311 . V_527 ( V_8 , V_18 ) ;
V_511 |= V_528 ;
}
F_240 ( V_2 ) ;
V_8 -> V_522 . V_523 = false ;
}
V_52 = F_245 ( V_18 ) ;
if ( V_52 < 0 ) {
V_510 |= V_519 ;
V_511 |= V_524 ;
}
if ( V_2 -> V_274 )
F_250 ( V_2 ) ;
if ( V_8 -> V_72 . type != V_73 ) {
V_511 |= F_11 ( V_8 , F_251 ( F_227 ( 0 ) ) ) &
~ ( V_525 | V_528 |
V_524 ) ;
F_45 ( V_8 , F_251 ( F_227 ( 0 ) ) , V_511 ) ;
}
if ( V_2 -> V_18 -> V_160 & V_246 ) {
V_510 |= ( V_515 |
V_516 |
V_518 ) ;
V_510 &= ~ ( V_517 ) ;
}
F_45 ( V_8 , V_514 , V_510 ) ;
if ( V_18 -> V_160 & V_223 )
F_242 ( V_2 ) ;
else
F_241 ( V_2 ) ;
}
static void F_252 ( struct V_1 * V_2 )
{
int V_529 ;
for ( V_529 = 0 ; V_529 < V_2 -> V_153 ; V_529 ++ )
F_253 ( & V_2 -> V_118 [ V_529 ] -> V_227 ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
int V_529 ;
for ( V_529 = 0 ; V_529 < V_2 -> V_153 ; V_529 ++ )
F_255 ( & V_2 -> V_118 [ V_529 ] -> V_227 ) ;
}
static void F_256 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_468 = V_2 -> V_18 -> V_268 + V_208 + V_437 ;
if ( ! ( V_2 -> V_100 & V_101 ) ) {
if ( V_8 -> V_72 . type == V_73 )
F_257 ( V_2 -> V_18 , 65536 ) ;
return;
}
if ( V_8 -> V_72 . type == V_73 )
F_257 ( V_2 -> V_18 , 32768 ) ;
#ifdef F_122
if ( V_2 -> V_18 -> V_160 & V_530 )
V_468 = F_171 ( V_468 , V_472 ) ;
#endif
if ( V_2 -> V_531 & V_532 ) {
F_258 ( V_8 , & V_2 -> V_97 , V_468 ,
V_533 ) ;
F_258 ( V_8 , & V_2 -> V_97 , V_468 ,
V_534 ) ;
F_259 ( V_8 , & V_2 -> V_97 ) ;
} else if ( V_2 -> V_535 && V_2 -> V_99 ) {
F_260 ( & V_2 -> V_8 ,
V_2 -> V_535 ,
V_468 ) ;
F_261 ( & V_2 -> V_8 ,
V_2 -> V_99 -> V_96 ,
V_2 -> V_535 -> V_536 ) ;
}
if ( V_8 -> V_72 . type != V_73 ) {
T_1 V_537 = 0 ;
T_5 V_410 = V_2 -> V_388 [ V_389 ] . V_390 - 1 ;
while ( V_410 ) {
V_537 ++ ;
V_410 >>= 1 ;
}
F_45 ( V_8 , V_538 , V_537 * 0x11111111 ) ;
}
}
static int F_262 ( struct V_1 * V_2 , int V_539 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_37 = V_2 -> V_18 ;
int V_345 , V_104 , V_540 , V_541 ;
T_1 V_542 , V_543 ;
V_104 = V_345 = V_37 -> V_268 + V_208 + V_437 + V_544 ;
#ifdef F_122
if ( ( V_37 -> V_160 & V_530 ) &&
( V_104 < V_472 ) &&
( V_539 == F_263 ( V_2 ) ) )
V_104 = V_472 ;
#endif
switch ( V_8 -> V_72 . type ) {
case V_76 :
V_542 = F_264 ( V_345 , V_104 ) ;
break;
default:
V_542 = F_265 ( V_345 , V_104 ) ;
break;
}
if ( V_2 -> V_100 & V_383 )
V_542 += F_266 ( V_104 ) ;
V_540 = F_267 ( V_542 ) ;
V_543 = F_11 ( V_8 , F_268 ( V_539 ) ) >> 10 ;
V_541 = V_543 - V_540 ;
if ( V_541 < 0 ) {
F_269 ( V_133 , L_71
L_72
L_73 , V_539 ) ;
V_541 = V_104 + 1 ;
}
return V_541 ;
}
static int F_270 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_37 = V_2 -> V_18 ;
int V_104 ;
T_1 V_542 ;
V_104 = V_37 -> V_268 + V_208 + V_437 ;
switch ( V_8 -> V_72 . type ) {
case V_76 :
V_542 = F_271 ( V_104 ) ;
break;
default:
V_542 = F_272 ( V_104 ) ;
break;
}
return F_267 ( V_542 ) ;
}
static void F_273 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_545 = F_211 ( V_2 -> V_18 ) ;
int V_11 ;
if ( ! V_545 )
V_545 = 1 ;
V_8 -> V_87 . V_546 = F_270 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_545 ; V_11 ++ ) {
V_8 -> V_87 . V_547 [ V_11 ] = F_262 ( V_2 , V_11 ) ;
if ( V_8 -> V_87 . V_546 > V_8 -> V_87 . V_547 [ V_11 ] )
V_8 -> V_87 . V_546 = 0 ;
}
}
static void F_274 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_548 ;
T_4 V_104 = F_211 ( V_2 -> V_18 ) ;
if ( V_2 -> V_100 & V_339 ||
V_2 -> V_100 & V_549 )
V_548 = 32 << V_2 -> V_550 ;
else
V_548 = 0 ;
V_8 -> V_72 . V_311 . V_551 ( V_8 , V_104 , V_548 , V_552 ) ;
F_273 ( V_2 ) ;
}
static void F_275 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_553 * V_554 , * V_555 ;
struct V_556 * V_557 ;
F_276 ( & V_2 -> V_558 ) ;
if ( ! F_277 ( & V_2 -> V_559 ) )
F_278 ( V_8 , & V_2 -> V_560 ) ;
F_279 (filter, node, node2,
&adapter->fdir_filter_list, fdir_node) {
F_280 ( V_8 ,
& V_557 -> V_557 ,
V_557 -> V_561 ,
( V_557 -> V_562 == V_563 ) ?
V_563 :
V_2 -> V_30 [ V_557 -> V_562 ] -> V_108 ) ;
}
F_281 ( & V_2 -> V_558 ) ;
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
V_8 -> V_72 . V_311 . V_564 ( V_8 ) ;
break;
default:
break;
}
if ( V_2 -> V_100 & V_339 ) {
F_284 ( & V_2 -> V_8 ,
V_2 -> V_550 ) ;
} else if ( V_2 -> V_100 & V_549 ) {
F_285 ( & V_2 -> V_8 ,
V_2 -> V_550 ) ;
F_275 ( V_2 ) ;
}
switch ( V_8 -> V_72 . type ) {
case V_75 :
case V_76 :
V_8 -> V_72 . V_311 . V_565 ( V_8 ) ;
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
switch ( V_8 -> V_315 . type ) {
case V_566 :
case V_567 :
case V_568 :
case V_569 :
case V_570 :
case V_571 :
case V_572 :
case V_573 :
return true ;
case V_574 :
if ( V_8 -> V_72 . type == V_73 )
return true ;
default:
return false ;
}
}
static void F_288 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_72 . type == V_73 )
V_2 -> V_115 |= V_575 ;
V_2 -> V_115 |= V_323 ;
}
static int F_289 ( struct V_7 * V_8 )
{
T_1 V_313 ;
bool V_576 , V_314 = false ;
T_1 V_114 = V_577 ;
if ( V_8 -> V_72 . V_311 . V_312 )
V_114 = V_8 -> V_72 . V_311 . V_312 ( V_8 , & V_313 , & V_314 , false ) ;
if ( V_114 )
goto V_578;
V_313 = V_8 -> V_315 . V_579 ;
if ( ( ! V_313 ) && ( V_8 -> V_72 . V_311 . V_580 ) )
V_114 = V_8 -> V_72 . V_311 . V_580 ( V_8 , & V_313 ,
& V_576 ) ;
if ( V_114 )
goto V_578;
if ( V_8 -> V_72 . V_311 . V_581 )
V_114 = V_8 -> V_72 . V_311 . V_581 ( V_8 , V_313 , V_576 , V_314 ) ;
V_578:
return V_114 ;
}
static void F_290 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_582 = 0 ;
if ( V_2 -> V_100 & V_364 ) {
V_582 = V_583 | V_584 |
V_585 ;
V_582 |= V_586 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
F_45 ( V_8 , V_587 , V_588 ) ;
break;
case V_75 :
case V_76 :
default:
F_45 ( V_8 , F_291 ( 0 ) , 0xFFFFFFFF ) ;
F_45 ( V_8 , F_291 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_45 ( V_8 , V_587 , V_588 ) ;
}
if ( V_2 -> V_100 & V_383 ) {
V_582 &= ~ V_589 ;
switch ( V_2 -> V_388 [ V_458 ] . V_79 ) {
case V_459 :
V_582 |= V_590 ;
break;
case V_461 :
V_582 |= V_591 ;
break;
default:
V_582 |= V_592 ;
break;
}
}
if ( V_2 -> V_115 & V_305 ) {
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
V_582 |= V_593 ;
break;
case V_76 :
V_582 |= V_334 ;
break;
default:
break;
}
}
if ( V_2 -> V_100 & V_318 )
V_582 |= V_594 ;
if ( V_8 -> V_72 . type == V_75 ) {
V_582 |= V_594 ;
V_582 |= V_595 ;
}
F_45 ( V_8 , V_596 , V_582 ) ;
}
static void F_292 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_356 ;
T_1 V_64 ;
F_46 ( V_2 ) ;
F_290 ( V_2 ) ;
if ( V_2 -> V_100 & V_364 )
F_166 ( V_2 ) ;
else
F_205 ( V_2 ) ;
if ( V_8 -> V_72 . V_311 . V_597 &&
( ( V_8 -> V_315 . V_598 ) ||
( ( V_8 -> V_72 . V_311 . V_599 ( V_8 ) == V_600 ) &&
( V_8 -> V_72 . type == V_75 ) ) ) )
V_8 -> V_72 . V_311 . V_597 ( V_8 ) ;
F_8 ( V_3 , & V_2 -> V_4 ) ;
F_252 ( V_2 ) ;
if ( F_287 ( V_8 ) ) {
F_288 ( V_2 ) ;
} else {
V_356 = F_289 ( V_8 ) ;
if ( V_356 )
F_77 ( V_135 , L_74 , V_356 ) ;
}
F_11 ( V_8 , V_320 ) ;
F_183 ( V_2 , true , true ) ;
if ( V_2 -> V_100 & V_318 ) {
T_1 V_601 = F_11 ( V_8 , V_602 ) ;
if ( V_601 & V_603 )
F_173 ( V_133 , L_54 ) ;
}
F_293 ( V_2 -> V_18 ) ;
V_2 -> V_100 |= V_326 ;
V_2 -> V_327 = V_134 ;
F_294 ( & V_2 -> V_604 , V_134 ) ;
V_64 = F_11 ( V_8 , V_65 ) ;
V_64 |= V_605 ;
F_45 ( V_8 , V_65 , V_64 ) ;
}
void F_295 ( struct V_1 * V_2 )
{
F_296 ( F_297 () ) ;
V_2 -> V_18 -> V_38 = V_134 ;
while ( F_3 ( V_606 , & V_2 -> V_4 ) )
F_209 ( 1000 , 2000 ) ;
F_298 ( V_2 ) ;
if ( V_2 -> V_100 & V_383 )
F_299 ( 2000 ) ;
F_300 ( V_2 ) ;
F_8 ( V_606 , & V_2 -> V_4 ) ;
}
void F_300 ( struct V_1 * V_2 )
{
F_282 ( V_2 ) ;
F_292 ( V_2 ) ;
}
void F_301 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_356 ;
while ( F_3 ( V_607 , & V_2 -> V_4 ) )
F_209 ( 1000 , 2000 ) ;
V_2 -> V_115 &= ~ ( V_575 |
V_323 ) ;
V_2 -> V_100 &= ~ V_324 ;
V_356 = V_8 -> V_72 . V_311 . V_608 ( V_8 ) ;
switch ( V_356 ) {
case 0 :
case V_609 :
case V_610 :
break;
case V_611 :
F_302 ( L_75 ) ;
break;
case V_612 :
F_303 ( L_76
L_77
L_78
L_79
L_80
L_81 ) ;
break;
default:
F_302 ( L_82 , V_356 ) ;
}
F_8 ( V_607 , & V_2 -> V_4 ) ;
V_8 -> V_72 . V_311 . V_506 ( V_8 , 0 , V_8 -> V_72 . V_507 , F_227 ( 0 ) , V_508 ) ;
if ( V_8 -> V_72 . V_613 )
V_8 -> V_72 . V_311 . V_614 ( V_8 , F_227 ( 0 ) ) ;
}
static void F_304 ( struct V_20 * V_30 )
{
struct V_154 * V_37 = V_30 -> V_37 ;
unsigned long V_252 ;
T_5 V_11 ;
if ( ! V_30 -> V_34 )
return;
for ( V_11 = 0 ; V_11 < V_30 -> V_52 ; V_11 ++ ) {
struct V_33 * V_251 ;
V_251 = & V_30 -> V_34 [ V_11 ] ;
if ( V_251 -> V_53 ) {
struct V_159 * V_53 = V_251 -> V_53 ;
if ( F_127 ( V_53 ) -> V_244 ) {
F_54 ( V_37 ,
F_127 ( V_53 ) -> V_45 ,
F_43 ( V_30 ) ,
V_191 ) ;
F_127 ( V_53 ) -> V_244 = false ;
}
F_305 ( V_53 ) ;
}
V_251 -> V_53 = NULL ;
if ( V_251 -> V_45 )
F_54 ( V_37 , V_251 -> V_45 ,
F_115 ( V_30 ) ,
V_191 ) ;
V_251 -> V_45 = 0 ;
if ( V_251 -> V_62 )
F_117 ( V_251 -> V_62 ,
F_113 ( V_30 ) ) ;
V_251 -> V_62 = NULL ;
}
V_252 = sizeof( struct V_33 ) * V_30 -> V_52 ;
memset ( V_30 -> V_34 , 0 , V_252 ) ;
memset ( V_30 -> V_51 , 0 , V_30 -> V_252 ) ;
V_30 -> V_185 = 0 ;
V_30 -> V_43 = 0 ;
V_30 -> V_44 = 0 ;
}
static void F_306 ( struct V_20 * V_21 )
{
struct V_22 * V_42 ;
unsigned long V_252 ;
T_5 V_11 ;
if ( ! V_21 -> V_42 )
return;
for ( V_11 = 0 ; V_11 < V_21 -> V_52 ; V_11 ++ ) {
V_42 = & V_21 -> V_42 [ V_11 ] ;
F_51 ( V_21 , V_42 ) ;
}
F_307 ( F_81 ( V_21 ) ) ;
V_252 = sizeof( struct V_22 ) * V_21 -> V_52 ;
memset ( V_21 -> V_42 , 0 , V_252 ) ;
memset ( V_21 -> V_51 , 0 , V_21 -> V_252 ) ;
V_21 -> V_44 = 0 ;
V_21 -> V_43 = 0 ;
}
static void F_308 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ )
F_304 ( V_2 -> V_30 [ V_11 ] ) ;
}
static void F_309 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_306 ( V_2 -> V_21 [ V_11 ] ) ;
}
static void F_310 ( struct V_1 * V_2 )
{
struct V_553 * V_554 , * V_555 ;
struct V_556 * V_557 ;
F_276 ( & V_2 -> V_558 ) ;
F_279 (filter, node, node2,
&adapter->fdir_filter_list, fdir_node) {
F_311 ( & V_557 -> V_615 ) ;
F_199 ( V_557 ) ;
}
V_2 -> V_616 = 0 ;
F_281 ( & V_2 -> V_558 ) ;
}
void F_298 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_145 ;
int V_11 ;
F_208 ( V_3 , & V_2 -> V_4 ) ;
V_145 = F_11 ( V_8 , V_488 ) ;
F_45 ( V_8 , V_488 , V_145 & ~ V_489 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ )
F_222 ( V_2 , V_2 -> V_30 [ V_11 ] ) ;
F_209 ( 10000 , 20000 ) ;
F_312 ( V_18 ) ;
F_313 ( V_18 ) ;
F_314 ( V_18 ) ;
F_203 ( V_2 ) ;
F_254 ( V_2 ) ;
V_2 -> V_115 &= ~ ( V_340 |
V_116 ) ;
V_2 -> V_100 &= ~ V_326 ;
F_315 ( & V_2 -> V_604 ) ;
if ( V_2 -> V_274 ) {
F_45 ( & V_2 -> V_8 , V_276 , 0 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_274 ; V_11 ++ )
V_2 -> V_466 [ V_11 ] . V_617 = false ;
F_316 ( V_2 ) ;
F_317 ( V_2 ) ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
T_4 V_108 = V_2 -> V_21 [ V_11 ] -> V_108 ;
F_45 ( V_8 , F_24 ( V_108 ) , V_618 ) ;
}
switch ( V_8 -> V_72 . type ) {
case V_75 :
case V_76 :
F_45 ( V_8 , V_399 ,
( F_11 ( V_8 , V_399 ) &
~ V_400 ) ) ;
break;
default:
break;
}
if ( ! F_318 ( V_2 -> V_36 ) )
F_301 ( V_2 ) ;
if ( V_8 -> V_72 . V_311 . V_619 &&
( ( V_8 -> V_315 . V_598 ) ||
( ( V_8 -> V_72 . V_311 . V_599 ( V_8 ) == V_600 ) &&
( V_8 -> V_72 . type == V_75 ) ) ) )
V_8 -> V_72 . V_311 . V_619 ( V_8 ) ;
F_309 ( V_2 ) ;
F_308 ( V_2 ) ;
#ifdef F_192
F_97 ( V_2 ) ;
#endif
}
static void F_319 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
F_65 ( V_2 ) ;
}
static int T_11 F_320 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_620 * V_36 = V_2 -> V_36 ;
unsigned int V_165 ;
#ifdef F_283
int V_12 ;
struct V_621 * V_104 ;
#endif
V_8 -> V_622 = V_36 -> V_623 ;
V_8 -> V_307 = V_36 -> V_154 ;
V_8 -> V_624 = V_36 -> V_625 ;
V_8 -> V_626 = V_36 -> V_627 ;
V_8 -> V_628 = V_36 -> V_629 ;
V_165 = F_321 ( int , V_630 , F_322 () ) ;
V_2 -> V_388 [ V_389 ] . V_631 = V_165 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
if ( V_8 -> V_307 == V_632 )
V_2 -> V_100 |= V_318 ;
V_2 -> V_633 = V_634 ;
break;
case V_76 :
V_2 -> V_115 |= V_305 ;
case V_75 :
V_2 -> V_633 = V_635 ;
V_2 -> V_115 |= V_636 ;
V_2 -> V_115 |= V_478 ;
if ( V_8 -> V_307 == V_308 )
V_2 -> V_115 |= V_305 ;
V_2 -> V_374 = 20 ;
V_2 -> V_388 [ V_637 ] . V_631 =
V_638 ;
V_2 -> V_550 = V_639 ;
#ifdef F_122
V_2 -> V_100 |= V_640 ;
V_2 -> V_100 &= ~ V_471 ;
#ifdef F_283
V_2 -> V_641 . V_642 = V_643 ;
#endif
#endif
break;
default:
break;
}
#ifdef F_122
F_323 ( & V_2 -> V_641 . V_644 ) ;
#endif
F_323 ( & V_2 -> V_558 ) ;
#ifdef F_283
switch ( V_8 -> V_72 . type ) {
case V_76 :
V_2 -> V_97 . V_645 . V_646 = V_647 ;
V_2 -> V_97 . V_645 . V_648 = V_647 ;
break;
default:
V_2 -> V_97 . V_645 . V_646 = V_649 ;
V_2 -> V_97 . V_645 . V_648 = V_649 ;
break;
}
for ( V_12 = 0 ; V_12 < V_649 ; V_12 ++ ) {
V_104 = & V_2 -> V_97 . V_650 [ V_12 ] ;
V_104 -> V_651 [ V_533 ] . V_652 = 0 ;
V_104 -> V_651 [ V_533 ] . V_653 = 12 + ( V_12 & 1 ) ;
V_104 -> V_651 [ V_534 ] . V_652 = 0 ;
V_104 -> V_651 [ V_534 ] . V_653 = 12 + ( V_12 & 1 ) ;
V_104 -> V_654 = V_655 ;
}
V_104 = & V_2 -> V_97 . V_650 [ 0 ] ;
V_104 -> V_651 [ V_533 ] . V_656 = 0xFF ;
V_104 -> V_651 [ V_534 ] . V_656 = 0xFF ;
V_2 -> V_97 . V_657 [ V_533 ] [ 0 ] = 100 ;
V_2 -> V_97 . V_657 [ V_534 ] [ 0 ] = 100 ;
V_2 -> V_97 . V_98 = false ;
V_2 -> V_658 = 0x00 ;
V_2 -> V_531 = V_659 | V_532 ;
memcpy ( & V_2 -> V_660 , & V_2 -> V_97 ,
sizeof( V_2 -> V_660 ) ) ;
#endif
V_8 -> V_87 . V_661 = V_89 ;
V_8 -> V_87 . V_88 = V_89 ;
F_273 ( V_2 ) ;
V_8 -> V_87 . V_662 = V_663 ;
V_8 -> V_87 . V_664 = true ;
V_8 -> V_87 . V_665 = false ;
#ifdef F_324
if ( V_8 -> V_72 . type != V_73 )
V_2 -> V_274 = ( V_666 > 63 ) ? 0 : V_666 ;
#endif
V_2 -> V_280 = 1 ;
V_2 -> V_277 = 1 ;
V_2 -> V_667 = V_668 ;
V_2 -> V_669 = V_670 ;
V_2 -> V_671 = V_672 ;
if ( F_325 ( V_8 ) ) {
F_302 ( L_83 ) ;
return - V_673 ;
}
F_208 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
}
int F_326 ( struct V_20 * V_21 )
{
struct V_154 * V_37 = V_21 -> V_37 ;
int V_674 = F_327 ( V_37 ) ;
int V_675 = - 1 ;
int V_252 ;
V_252 = sizeof( struct V_22 ) * V_21 -> V_52 ;
if ( V_21 -> V_118 )
V_675 = V_21 -> V_118 -> V_675 ;
V_21 -> V_42 = F_328 ( V_252 , V_675 ) ;
if ( ! V_21 -> V_42 )
V_21 -> V_42 = F_329 ( V_252 ) ;
if ( ! V_21 -> V_42 )
goto V_356;
V_21 -> V_252 = V_21 -> V_52 * sizeof( union V_24 ) ;
V_21 -> V_252 = F_143 ( V_21 -> V_252 , 4096 ) ;
F_330 ( V_37 , V_675 ) ;
V_21 -> V_51 = F_331 ( V_37 ,
V_21 -> V_252 ,
& V_21 -> V_45 ,
V_676 ) ;
F_330 ( V_37 , V_674 ) ;
if ( ! V_21 -> V_51 )
V_21 -> V_51 = F_331 ( V_37 , V_21 -> V_252 ,
& V_21 -> V_45 , V_676 ) ;
if ( ! V_21 -> V_51 )
goto V_356;
V_21 -> V_44 = 0 ;
V_21 -> V_43 = 0 ;
return 0 ;
V_356:
F_332 ( V_21 -> V_42 ) ;
V_21 -> V_42 = NULL ;
F_333 ( V_37 , L_84 ) ;
return - V_503 ;
}
static int F_334 ( struct V_1 * V_2 )
{
int V_11 , V_356 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
V_356 = F_326 ( V_2 -> V_21 [ V_11 ] ) ;
if ( ! V_356 )
continue;
F_77 ( V_135 , L_85 , V_11 ) ;
goto V_677;
}
return 0 ;
V_677:
while ( V_11 -- )
F_335 ( V_2 -> V_21 [ V_11 ] ) ;
return V_356 ;
}
int F_336 ( struct V_20 * V_30 )
{
struct V_154 * V_37 = V_30 -> V_37 ;
int V_674 = F_327 ( V_37 ) ;
int V_675 = - 1 ;
int V_252 ;
V_252 = sizeof( struct V_33 ) * V_30 -> V_52 ;
if ( V_30 -> V_118 )
V_675 = V_30 -> V_118 -> V_675 ;
V_30 -> V_34 = F_328 ( V_252 , V_675 ) ;
if ( ! V_30 -> V_34 )
V_30 -> V_34 = F_329 ( V_252 ) ;
if ( ! V_30 -> V_34 )
goto V_356;
V_30 -> V_252 = V_30 -> V_52 * sizeof( union V_31 ) ;
V_30 -> V_252 = F_143 ( V_30 -> V_252 , 4096 ) ;
F_330 ( V_37 , V_675 ) ;
V_30 -> V_51 = F_331 ( V_37 ,
V_30 -> V_252 ,
& V_30 -> V_45 ,
V_676 ) ;
F_330 ( V_37 , V_674 ) ;
if ( ! V_30 -> V_51 )
V_30 -> V_51 = F_331 ( V_37 , V_30 -> V_252 ,
& V_30 -> V_45 , V_676 ) ;
if ( ! V_30 -> V_51 )
goto V_356;
V_30 -> V_43 = 0 ;
V_30 -> V_44 = 0 ;
return 0 ;
V_356:
F_332 ( V_30 -> V_34 ) ;
V_30 -> V_34 = NULL ;
F_333 ( V_37 , L_86 ) ;
return - V_503 ;
}
static int F_337 ( struct V_1 * V_2 )
{
int V_11 , V_356 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
V_356 = F_336 ( V_2 -> V_30 [ V_11 ] ) ;
if ( ! V_356 )
continue;
F_77 ( V_135 , L_87 , V_11 ) ;
goto V_678;
}
#ifdef F_122
V_356 = F_338 ( V_2 ) ;
if ( ! V_356 )
#endif
return 0 ;
V_678:
while ( V_11 -- )
F_339 ( V_2 -> V_30 [ V_11 ] ) ;
return V_356 ;
}
void F_335 ( struct V_20 * V_21 )
{
F_306 ( V_21 ) ;
F_332 ( V_21 -> V_42 ) ;
V_21 -> V_42 = NULL ;
if ( ! V_21 -> V_51 )
return;
F_340 ( V_21 -> V_37 , V_21 -> V_252 ,
V_21 -> V_51 , V_21 -> V_45 ) ;
V_21 -> V_51 = NULL ;
}
static void F_341 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
if ( V_2 -> V_21 [ V_11 ] -> V_51 )
F_335 ( V_2 -> V_21 [ V_11 ] ) ;
}
void F_339 ( struct V_20 * V_30 )
{
F_304 ( V_30 ) ;
F_332 ( V_30 -> V_34 ) ;
V_30 -> V_34 = NULL ;
if ( ! V_30 -> V_51 )
return;
F_340 ( V_30 -> V_37 , V_30 -> V_252 ,
V_30 -> V_51 , V_30 -> V_45 ) ;
V_30 -> V_51 = NULL ;
}
static void F_342 ( struct V_1 * V_2 )
{
int V_11 ;
#ifdef F_122
F_343 ( V_2 ) ;
#endif
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ )
if ( V_2 -> V_30 [ V_11 ] -> V_51 )
F_339 ( V_2 -> V_30 [ V_11 ] ) ;
}
static int F_344 ( struct V_17 * V_18 , int V_679 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
int V_468 = V_679 + V_208 + V_437 ;
if ( ( V_679 < 68 ) || ( V_468 > V_680 ) )
return - V_681 ;
if ( ( V_2 -> V_100 & V_383 ) &&
( V_2 -> V_8 . V_72 . type == V_75 ) &&
( V_468 > V_682 ) )
return - V_681 ;
F_79 ( V_135 , L_88 , V_18 -> V_268 , V_679 ) ;
V_18 -> V_268 = V_679 ;
if ( F_31 ( V_18 ) )
F_295 ( V_2 ) ;
return 0 ;
}
static int F_345 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
int V_356 ;
if ( F_2 ( V_683 , & V_2 -> V_4 ) )
return - V_684 ;
F_313 ( V_18 ) ;
V_356 = F_334 ( V_2 ) ;
if ( V_356 )
goto V_677;
V_356 = F_337 ( V_2 ) ;
if ( V_356 )
goto V_678;
F_282 ( V_2 ) ;
V_356 = F_201 ( V_2 ) ;
if ( V_356 )
goto V_685;
V_356 = F_346 ( V_18 ,
V_2 -> V_446 > 1 ? 1 :
V_2 -> V_41 ) ;
if ( V_356 )
goto V_686;
V_356 = F_347 ( V_18 ,
V_2 -> V_446 > 1 ? 1 :
V_2 -> V_57 ) ;
if ( V_356 )
goto V_686;
F_292 ( V_2 ) ;
return 0 ;
V_686:
F_202 ( V_2 ) ;
V_685:
F_342 ( V_2 ) ;
V_678:
F_341 ( V_2 ) ;
V_677:
F_301 ( V_2 ) ;
return V_356 ;
}
static int F_348 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
F_298 ( V_2 ) ;
F_202 ( V_2 ) ;
F_310 ( V_2 ) ;
F_341 ( V_2 ) ;
F_342 ( V_2 ) ;
F_44 ( V_2 ) ;
return 0 ;
}
static int F_349 ( struct V_620 * V_36 )
{
struct V_1 * V_2 = F_350 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_356 ;
F_351 ( V_36 , V_687 ) ;
F_352 ( V_36 ) ;
F_353 ( V_36 ) ;
V_356 = F_354 ( V_36 ) ;
if ( V_356 ) {
F_302 ( L_89 ) ;
return V_356 ;
}
F_355 ( V_36 ) ;
F_356 ( V_36 , false ) ;
F_301 ( V_2 ) ;
F_45 ( & V_2 -> V_8 , V_688 , ~ 0 ) ;
F_357 () ;
V_356 = F_358 ( V_2 ) ;
if ( ! V_356 && F_31 ( V_18 ) )
V_356 = F_345 ( V_18 ) ;
F_359 () ;
if ( V_356 )
return V_356 ;
F_360 ( V_18 ) ;
return 0 ;
}
static int F_361 ( struct V_620 * V_36 , bool * V_689 )
{
struct V_1 * V_2 = F_350 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_690 , V_510 ;
T_1 V_691 = V_2 -> V_692 ;
#ifdef F_362
int V_693 = 0 ;
#endif
F_363 ( V_18 ) ;
if ( F_31 ( V_18 ) ) {
F_357 () ;
F_298 ( V_2 ) ;
F_202 ( V_2 ) ;
F_341 ( V_2 ) ;
F_342 ( V_2 ) ;
F_359 () ;
}
F_364 ( V_2 ) ;
#ifdef F_362
V_693 = F_353 ( V_36 ) ;
if ( V_693 )
return V_693 ;
#endif
if ( V_691 ) {
F_249 ( V_18 ) ;
if ( V_8 -> V_72 . V_311 . V_597 &&
( V_8 -> V_315 . V_598 ||
( V_8 -> V_72 . V_311 . V_599 ( V_8 ) == V_600 &&
V_8 -> V_72 . type == V_75 ) ) )
V_8 -> V_72 . V_311 . V_597 ( V_8 ) ;
if ( V_691 & V_694 ) {
V_510 = F_11 ( V_8 , V_514 ) ;
V_510 |= V_520 ;
F_45 ( V_8 , V_514 , V_510 ) ;
}
V_690 = F_11 ( V_8 , V_695 ) ;
V_690 |= V_696 ;
F_45 ( V_8 , V_695 , V_690 ) ;
F_45 ( V_8 , V_697 , V_691 ) ;
} else {
F_45 ( V_8 , V_698 , 0 ) ;
F_45 ( V_8 , V_697 , 0 ) ;
}
switch ( V_8 -> V_72 . type ) {
case V_73 :
F_356 ( V_36 , false ) ;
break;
case V_75 :
case V_76 :
F_356 ( V_36 , ! ! V_691 ) ;
break;
default:
break;
}
* V_689 = ! ! V_691 ;
F_44 ( V_2 ) ;
F_365 ( V_36 ) ;
return 0 ;
}
static int F_366 ( struct V_620 * V_36 , T_12 V_4 )
{
int V_693 ;
bool V_699 ;
V_693 = F_361 ( V_36 , & V_699 ) ;
if ( V_693 )
return V_693 ;
if ( V_699 ) {
F_367 ( V_36 ) ;
} else {
F_356 ( V_36 , false ) ;
F_351 ( V_36 , V_700 ) ;
}
return 0 ;
}
static void F_368 ( struct V_620 * V_36 )
{
bool V_699 ;
F_361 ( V_36 , & V_699 ) ;
if ( V_701 == V_702 ) {
F_356 ( V_36 , V_699 ) ;
F_351 ( V_36 , V_700 ) ;
}
}
void F_369 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_84 * V_85 = & V_2 -> V_86 ;
T_2 V_703 = 0 ;
T_1 V_11 , V_704 = 0 , V_705 , V_706 , V_707 , V_708 , V_709 ;
T_2 V_236 = 0 , V_137 = 0 , V_710 = 0 ;
T_2 V_190 = 0 , V_261 = 0 ;
T_2 V_132 = 0 , V_106 = 0 , V_711 = 0 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_606 , & V_2 -> V_4 ) )
return;
if ( V_2 -> V_115 & V_478 ) {
T_2 V_221 = 0 ;
T_2 V_222 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
V_221 += V_2 -> V_30 [ V_11 ] -> V_176 . V_221 ;
V_222 += V_2 -> V_30 [ V_11 ] -> V_176 . V_222 ;
}
V_2 -> V_712 = V_221 ;
V_2 -> V_713 = V_222 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
struct V_20 * V_30 = V_2 -> V_30 [ V_11 ] ;
V_236 += V_30 -> V_176 . V_236 ;
V_190 += V_30 -> V_176 . V_190 ;
V_261 += V_30 -> V_176 . V_261 ;
V_711 += V_30 -> V_176 . V_177 ;
V_132 += V_30 -> V_86 . V_132 ;
V_106 += V_30 -> V_86 . V_106 ;
}
V_2 -> V_236 = V_236 ;
V_2 -> V_190 = V_190 ;
V_2 -> V_261 = V_261 ;
V_2 -> V_711 = V_711 ;
V_18 -> V_86 . V_714 = V_132 ;
V_18 -> V_86 . V_715 = V_106 ;
V_132 = 0 ;
V_106 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_21 = V_2 -> V_21 [ V_11 ] ;
V_137 += V_21 -> V_112 . V_137 ;
V_710 += V_21 -> V_112 . V_710 ;
V_132 += V_21 -> V_86 . V_132 ;
V_106 += V_21 -> V_86 . V_106 ;
}
V_2 -> V_137 = V_137 ;
V_2 -> V_710 = V_710 ;
V_18 -> V_86 . V_716 = V_132 ;
V_18 -> V_86 . V_717 = V_106 ;
V_85 -> V_718 += F_11 ( V_8 , V_719 ) ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_705 = F_11 ( V_8 , F_370 ( V_11 ) ) ;
V_704 += V_705 ;
V_85 -> V_705 [ V_11 ] += V_705 ;
V_703 += V_85 -> V_705 [ V_11 ] ;
V_85 -> V_720 [ V_11 ] += F_11 ( V_8 , F_371 ( V_11 ) ) ;
V_85 -> V_721 [ V_11 ] += F_11 ( V_8 , F_372 ( V_11 ) ) ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_85 -> V_722 [ V_11 ] += F_11 ( V_8 , F_373 ( V_11 ) ) ;
V_85 -> V_723 [ V_11 ] += F_11 ( V_8 , F_374 ( V_11 ) ) ;
V_85 -> V_724 [ V_11 ] += F_11 ( V_8 , F_375 ( V_11 ) ) ;
V_85 -> V_725 [ V_11 ] +=
F_11 ( V_8 , F_376 ( V_11 ) ) ;
break;
case V_75 :
case V_76 :
V_85 -> V_725 [ V_11 ] +=
F_11 ( V_8 , F_377 ( V_11 ) ) ;
break;
default:
break;
}
}
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ ) {
V_85 -> V_726 [ V_11 ] += F_11 ( V_8 , F_378 ( V_11 ) ) ;
V_85 -> V_727 [ V_11 ] += F_11 ( V_8 , F_379 ( V_11 ) ) ;
if ( ( V_8 -> V_72 . type == V_75 ) ||
( V_8 -> V_72 . type == V_76 ) ) {
V_85 -> V_723 [ V_11 ] += F_11 ( V_8 , F_380 ( V_11 ) ) ;
F_11 ( V_8 , F_381 ( V_11 ) ) ;
V_85 -> V_724 [ V_11 ] += F_11 ( V_8 , F_382 ( V_11 ) ) ;
F_11 ( V_8 , F_383 ( V_11 ) ) ;
}
}
V_85 -> V_728 += F_11 ( V_8 , V_729 ) ;
V_85 -> V_728 -= V_704 ;
F_57 ( V_2 ) ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_85 -> V_730 += F_11 ( V_8 , V_731 ) ;
V_85 -> V_732 += F_11 ( V_8 , V_733 ) ;
V_85 -> V_734 += F_11 ( V_8 , V_735 ) ;
V_85 -> V_736 += F_11 ( V_8 , V_737 ) ;
break;
case V_76 :
V_85 -> V_738 += F_11 ( V_8 , V_739 ) ;
V_85 -> V_740 += F_11 ( V_8 , V_741 ) ;
V_85 -> V_742 += F_11 ( V_8 , V_743 ) ;
V_85 -> V_744 += F_11 ( V_8 , V_745 ) ;
case V_75 :
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
V_2 -> V_746 +=
F_11 ( V_8 , F_384 ( V_11 ) ) ;
V_85 -> V_732 += F_11 ( V_8 , V_747 ) ;
F_11 ( V_8 , V_733 ) ;
V_85 -> V_734 += F_11 ( V_8 , V_748 ) ;
F_11 ( V_8 , V_735 ) ;
V_85 -> V_736 += F_11 ( V_8 , V_749 ) ;
F_11 ( V_8 , V_737 ) ;
V_85 -> V_730 += F_11 ( V_8 , V_750 ) ;
V_85 -> V_751 += F_11 ( V_8 , V_752 ) ;
V_85 -> V_753 += F_11 ( V_8 , V_754 ) ;
#ifdef F_122
V_85 -> V_755 += F_11 ( V_8 , V_756 ) ;
V_85 -> V_757 += F_11 ( V_8 , V_758 ) ;
V_85 -> V_759 += F_11 ( V_8 , V_760 ) ;
V_85 -> V_761 += F_11 ( V_8 , V_762 ) ;
V_85 -> V_763 += F_11 ( V_8 , V_764 ) ;
V_85 -> V_765 += F_11 ( V_8 , V_766 ) ;
if ( V_2 -> V_641 . V_767 ) {
struct V_768 * V_641 = & V_2 -> V_641 ;
struct V_769 * V_767 ;
unsigned int V_138 ;
T_2 V_770 = 0 , V_771 = 0 ;
F_385 (cpu) {
V_767 = F_386 ( V_641 -> V_767 , V_138 ) ;
V_770 += V_767 -> V_770 ;
V_771 += V_767 -> V_771 ;
}
V_85 -> V_772 = V_770 ;
V_85 -> V_773 = V_771 ;
}
#endif
break;
default:
break;
}
V_706 = F_11 ( V_8 , V_774 ) ;
V_85 -> V_706 += V_706 ;
V_85 -> V_775 += F_11 ( V_8 , V_776 ) ;
if ( V_8 -> V_72 . type == V_73 )
V_85 -> V_775 -= V_706 ;
V_85 -> V_777 += F_11 ( V_8 , V_778 ) ;
V_85 -> V_779 += F_11 ( V_8 , V_780 ) ;
V_85 -> V_781 += F_11 ( V_8 , V_782 ) ;
V_85 -> V_783 += F_11 ( V_8 , V_784 ) ;
V_85 -> V_785 += F_11 ( V_8 , V_786 ) ;
V_85 -> V_787 += F_11 ( V_8 , V_788 ) ;
V_85 -> V_789 += F_11 ( V_8 , V_790 ) ;
V_85 -> V_791 += F_11 ( V_8 , V_792 ) ;
V_707 = F_11 ( V_8 , V_793 ) ;
V_85 -> V_794 += V_707 ;
V_708 = F_11 ( V_8 , V_795 ) ;
V_85 -> V_796 += V_708 ;
V_85 -> V_797 += F_11 ( V_8 , V_798 ) ;
V_85 -> V_799 += F_11 ( V_8 , V_800 ) ;
V_709 = V_707 + V_708 ;
V_85 -> V_797 -= V_709 ;
V_85 -> V_799 -= V_709 ;
V_85 -> V_734 -= ( V_709 * ( V_801 + V_437 ) ) ;
V_85 -> V_802 += F_11 ( V_8 , V_803 ) ;
V_85 -> V_804 += F_11 ( V_8 , V_805 ) ;
V_85 -> V_806 += F_11 ( V_8 , V_807 ) ;
V_85 -> V_808 += F_11 ( V_8 , V_809 ) ;
V_85 -> V_810 += F_11 ( V_8 , V_811 ) ;
V_85 -> V_810 -= V_709 ;
V_85 -> V_812 += F_11 ( V_8 , V_813 ) ;
V_85 -> V_814 += F_11 ( V_8 , V_815 ) ;
V_85 -> V_816 += F_11 ( V_8 , V_817 ) ;
V_85 -> V_818 += F_11 ( V_8 , V_819 ) ;
V_85 -> V_820 += F_11 ( V_8 , V_821 ) ;
V_85 -> V_822 += F_11 ( V_8 , V_823 ) ;
V_18 -> V_86 . V_824 = V_85 -> V_775 ;
V_18 -> V_86 . V_825 = V_85 -> V_718 + V_85 -> V_791 ;
V_18 -> V_86 . V_826 = 0 ;
V_18 -> V_86 . V_827 = V_85 -> V_791 ;
V_18 -> V_86 . V_828 = V_85 -> V_718 ;
V_18 -> V_86 . V_829 = V_703 ;
}
static void F_387 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_11 ;
if ( ! ( V_2 -> V_115 & V_340 ) )
return;
V_2 -> V_115 &= ~ V_340 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
if ( ! ( V_2 -> V_100 & V_339 ) )
return;
V_2 -> V_830 ++ ;
if ( F_388 ( V_8 ) == 0 ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_208 ( V_348 ,
& ( V_2 -> V_21 [ V_11 ] -> V_4 ) ) ;
F_45 ( V_8 , V_330 , V_341 ) ;
} else {
F_77 ( V_135 , L_90
L_91 ) ;
}
}
static void F_389 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_831 = 0 ;
int V_11 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_606 , & V_2 -> V_4 ) )
return;
if ( F_83 ( V_2 -> V_18 ) ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_390 ( V_2 -> V_21 [ V_11 ] ) ;
}
if ( ! ( V_2 -> V_100 & V_364 ) ) {
F_45 ( V_8 , V_81 ,
( V_832 | V_833 ) ) ;
} else {
for ( V_11 = 0 ; V_11 < V_2 -> V_153 ; V_11 ++ ) {
struct V_117 * V_834 = V_2 -> V_118 [ V_11 ] ;
if ( V_834 -> V_272 . V_82 || V_834 -> V_122 . V_82 )
V_831 |= ( ( T_2 ) 1 << V_11 ) ;
}
}
F_49 ( V_2 , V_831 ) ;
}
static void F_391 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_835 = V_2 -> V_835 ;
bool V_314 = V_2 -> V_314 ;
bool V_96 = V_2 -> V_97 . V_98 ;
if ( ! ( V_2 -> V_100 & V_326 ) )
return;
if ( V_8 -> V_72 . V_311 . V_312 ) {
V_8 -> V_72 . V_311 . V_312 ( V_8 , & V_835 , & V_314 , false ) ;
} else {
V_835 = V_836 ;
V_314 = true ;
}
if ( V_2 -> V_99 )
V_96 |= ! ! ( V_2 -> V_99 -> V_96 ) ;
if ( V_314 && ! ( ( V_2 -> V_100 & V_101 ) && V_96 ) ) {
V_8 -> V_72 . V_311 . V_837 ( V_8 ) ;
F_392 ( V_2 ) ;
}
if ( V_314 ||
F_393 ( V_134 , ( V_2 -> V_327 +
V_838 ) ) ) {
V_2 -> V_100 &= ~ V_326 ;
F_45 ( V_8 , V_330 , V_329 ) ;
F_178 ( V_8 ) ;
}
V_2 -> V_314 = V_314 ;
V_2 -> V_835 = V_835 ;
}
static void F_394 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_835 = V_2 -> V_835 ;
bool V_839 , V_840 ;
if ( F_83 ( V_18 ) )
return;
V_2 -> V_115 &= ~ V_575 ;
switch ( V_8 -> V_72 . type ) {
case V_73 : {
T_1 V_841 = F_11 ( V_8 , V_514 ) ;
T_1 V_842 = F_11 ( V_8 , V_843 ) ;
V_839 = ! ! ( V_841 & V_844 ) ;
V_840 = ! ! ( V_842 & V_845 ) ;
}
break;
case V_76 :
case V_75 : {
T_1 V_846 = F_11 ( V_8 , V_847 ) ;
T_1 V_848 = F_11 ( V_8 , V_849 ) ;
V_839 = ! ! ( V_846 & V_850 ) ;
V_840 = ! ! ( V_848 & V_851 ) ;
}
break;
default:
V_840 = false ;
V_839 = false ;
break;
}
#ifdef F_69
F_395 ( V_2 ) ;
#endif
F_79 ( V_133 , L_92 ,
( V_835 == V_836 ?
L_93 :
( V_835 == V_852 ?
L_94 :
( V_835 == V_853 ?
L_95 :
L_96 ) ) ) ,
( ( V_839 && V_840 ) ? L_97 :
( V_839 ? L_98 :
( V_840 ? L_99 : L_100 ) ) ) ) ;
F_396 ( V_18 ) ;
F_397 ( V_2 ) ;
F_316 ( V_2 ) ;
}
static void F_398 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
V_2 -> V_314 = false ;
V_2 -> V_835 = 0 ;
if ( ! F_83 ( V_18 ) )
return;
if ( F_287 ( V_8 ) && V_8 -> V_72 . type == V_73 )
V_2 -> V_115 |= V_575 ;
#ifdef F_69
F_395 ( V_2 ) ;
#endif
F_79 ( V_133 , L_101 ) ;
F_313 ( V_18 ) ;
F_316 ( V_2 ) ;
}
static void F_399 ( struct V_1 * V_2 )
{
int V_11 ;
int V_854 = 0 ;
if ( ! F_83 ( V_2 -> V_18 ) ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_21 = V_2 -> V_21 [ V_11 ] ;
if ( V_21 -> V_44 != V_21 -> V_43 ) {
V_854 = 1 ;
break;
}
}
if ( V_854 ) {
V_2 -> V_115 |= V_116 ;
}
}
}
static void F_400 ( struct V_1 * V_2 )
{
T_1 V_855 ;
if ( V_2 -> V_8 . V_72 . type == V_73 ||
V_2 -> V_274 == 0 )
return;
V_855 = F_11 ( & V_2 -> V_8 , V_856 ) ;
if ( ! V_855 )
return;
F_269 ( V_133 , L_102 , V_855 ) ;
}
static void F_401 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_606 , & V_2 -> V_4 ) )
return;
F_391 ( V_2 ) ;
if ( V_2 -> V_314 )
F_394 ( V_2 ) ;
else
F_398 ( V_2 ) ;
F_400 ( V_2 ) ;
F_369 ( V_2 ) ;
F_399 ( V_2 ) ;
}
static void F_402 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_13 V_356 ;
if ( ! ( V_2 -> V_115 & V_575 ) &&
! ( V_2 -> V_115 & V_323 ) )
return;
if ( F_3 ( V_607 , & V_2 -> V_4 ) )
return;
V_356 = V_8 -> V_315 . V_311 . V_857 ( V_8 ) ;
if ( V_356 == V_610 )
goto V_858;
if ( V_356 == V_609 ) {
V_2 -> V_115 |= V_323 ;
}
if ( V_356 )
goto V_858;
if ( ! ( V_2 -> V_115 & V_323 ) )
goto V_858;
V_2 -> V_115 &= ~ V_323 ;
if ( V_8 -> V_72 . type == V_73 )
V_356 = V_8 -> V_315 . V_311 . V_859 ( V_8 ) ;
else
V_356 = V_8 -> V_72 . V_311 . V_860 ( V_8 ) ;
if ( V_356 == V_610 )
goto V_858;
V_2 -> V_100 |= V_324 ;
F_79 ( V_135 , L_103 , V_8 -> V_315 . V_861 ) ;
V_858:
F_8 ( V_607 , & V_2 -> V_4 ) ;
if ( ( V_356 == V_610 ) &&
( V_2 -> V_18 -> V_862 == V_863 ) ) {
F_302 ( L_104
L_105 ) ;
F_302 ( L_106
L_107 ) ;
F_403 ( V_2 -> V_18 ) ;
}
}
static void F_404 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_313 ;
bool V_576 ;
if ( ! ( V_2 -> V_100 & V_324 ) )
return;
if ( F_3 ( V_607 , & V_2 -> V_4 ) )
return;
V_2 -> V_100 &= ~ V_324 ;
V_313 = V_8 -> V_315 . V_579 ;
if ( ( ! V_313 ) && ( V_8 -> V_72 . V_311 . V_580 ) )
V_8 -> V_72 . V_311 . V_580 ( V_8 , & V_313 , & V_576 ) ;
if ( V_8 -> V_72 . V_311 . V_581 )
V_8 -> V_72 . V_311 . V_581 ( V_8 , V_313 , V_576 , true ) ;
V_2 -> V_100 |= V_326 ;
V_2 -> V_327 = V_134 ;
F_8 ( V_607 , & V_2 -> V_4 ) ;
}
static void F_405 ( struct V_1 * V_2 )
{
int V_864 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_865 ;
T_1 V_866 , V_867 ;
V_865 = F_11 ( V_8 , V_868 ) ;
if ( V_865 )
return;
for ( V_864 = 0 ; V_864 < V_2 -> V_274 ; V_864 ++ ) {
V_866 = ( V_864 << 16 ) | 0x80000000 ;
V_866 |= V_869 ;
F_45 ( V_8 , V_870 , V_866 ) ;
V_867 = F_11 ( V_8 , V_871 ) ;
V_866 &= 0x7FFFFFFF ;
F_45 ( V_8 , V_870 , V_866 ) ;
V_867 >>= 16 ;
if ( V_867 & V_872 ) {
F_406 ( V_18 , L_108 , V_864 ) ;
V_866 = ( V_864 << 16 ) | 0x80000000 ;
V_866 |= 0xA8 ;
F_45 ( V_8 , V_870 , V_866 ) ;
V_867 = 0x00008000 ;
F_45 ( V_8 , V_871 , V_867 ) ;
V_866 &= 0x7FFFFFFF ;
F_45 ( V_8 , V_870 , V_866 ) ;
}
}
}
static void F_407 ( unsigned long V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
unsigned long V_873 ;
bool V_874 = true ;
if ( V_2 -> V_100 & V_326 )
V_873 = V_875 / 10 ;
else
V_873 = V_875 * 2 ;
#ifdef F_324
if ( ! V_2 -> V_274 ||
( V_2 -> V_100 & V_326 ) )
goto V_876;
F_405 ( V_2 ) ;
V_873 = V_875 / 50 ;
V_2 -> V_877 ++ ;
if ( V_2 -> V_877 >= 100 )
V_2 -> V_877 = 0 ;
else
V_874 = false ;
V_876:
#endif
F_294 ( & V_2 -> V_604 , V_873 + V_134 ) ;
if ( V_874 )
F_1 ( V_2 ) ;
}
static void F_408 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_115 & V_116 ) )
return;
V_2 -> V_115 &= ~ V_116 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_606 , & V_2 -> V_4 ) )
return;
F_28 ( V_2 ) ;
F_406 ( V_2 -> V_18 , L_109 ) ;
V_2 -> V_136 ++ ;
F_295 ( V_2 ) ;
}
static void F_409 ( struct V_878 * V_879 )
{
struct V_1 * V_2 = F_191 ( V_879 ,
struct V_1 ,
V_6 ) ;
F_408 ( V_2 ) ;
F_402 ( V_2 ) ;
F_404 ( V_2 ) ;
F_172 ( V_2 ) ;
F_401 ( V_2 ) ;
F_387 ( V_2 ) ;
F_389 ( V_2 ) ;
#ifdef F_69
F_410 ( V_2 ) ;
#endif
F_5 ( V_2 ) ;
}
static int F_411 ( struct V_20 * V_21 ,
struct V_22 * V_880 ,
T_4 * V_218 )
{
struct V_159 * V_53 = V_880 -> V_53 ;
T_1 V_881 , V_882 ;
T_1 V_883 , V_884 ;
if ( ! F_412 ( V_53 ) )
return 0 ;
if ( F_413 ( V_53 ) ) {
int V_356 = F_414 ( V_53 , 0 , 0 , V_187 ) ;
if ( V_356 )
return V_356 ;
}
V_882 = V_885 ;
if ( V_880 -> V_205 == F_121 ( V_213 ) ) {
struct V_202 * V_886 = F_415 ( V_53 ) ;
V_886 -> V_887 = 0 ;
V_886 -> V_888 = 0 ;
F_416 ( V_53 ) -> V_888 = ~ F_417 ( V_886 -> V_889 ,
V_886 -> V_890 , 0 ,
V_216 ,
0 ) ;
V_882 |= V_891 ;
V_880 -> V_129 |= V_892 |
V_893 |
V_894 ;
} else if ( F_418 ( V_53 ) ) {
F_419 ( V_53 ) -> V_895 = 0 ;
F_416 ( V_53 ) -> V_888 =
~ F_420 ( & F_419 ( V_53 ) -> V_889 ,
& F_419 ( V_53 ) -> V_890 ,
0 , V_216 , 0 ) ;
V_880 -> V_129 |= V_892 |
V_893 ;
}
V_884 = F_421 ( V_53 ) ;
* V_218 = F_422 ( V_53 ) + V_884 ;
V_880 -> V_128 = F_125 ( V_53 ) -> V_128 ;
V_880 -> V_127 += ( V_880 -> V_128 - 1 ) * * V_218 ;
V_883 = V_884 << V_896 ;
V_883 |= F_125 ( V_53 ) -> V_219 << V_897 ;
V_883 |= 1 << V_898 ;
V_881 = F_423 ( V_53 ) ;
V_881 |= F_424 ( V_53 ) << V_899 ;
V_881 |= V_880 -> V_129 & V_900 ;
F_425 ( V_21 , V_881 , 0 , V_882 ,
V_883 ) ;
return 1 ;
}
static void F_426 ( struct V_20 * V_21 ,
struct V_22 * V_880 )
{
struct V_159 * V_53 = V_880 -> V_53 ;
T_1 V_881 = 0 ;
T_1 V_883 = 0 ;
T_1 V_882 = 0 ;
if ( V_53 -> V_182 != V_901 ) {
if ( ! ( V_880 -> V_129 & V_902 ) ) {
if ( F_70 ( V_53 -> V_903 ) )
V_880 -> V_129 |= V_904 ;
if ( ! ( V_880 -> V_129 & V_905 ) )
return;
}
} else {
T_4 V_906 = 0 ;
switch ( V_880 -> V_205 ) {
case F_121 ( V_213 ) :
V_881 |= F_423 ( V_53 ) ;
V_882 |= V_891 ;
V_906 = F_415 ( V_53 ) -> V_205 ;
break;
case F_121 ( V_907 ) :
V_881 |= F_423 ( V_53 ) ;
V_906 = F_419 ( V_53 ) -> V_206 ;
break;
default:
if ( F_70 ( F_427 () ) ) {
F_428 ( V_21 -> V_37 ,
L_110 ,
V_880 -> V_205 ) ;
}
break;
}
switch ( V_906 ) {
case V_216 :
V_882 |= V_885 ;
V_883 = F_421 ( V_53 ) <<
V_896 ;
break;
case V_908 :
V_882 |= V_909 ;
V_883 = sizeof( struct V_910 ) <<
V_896 ;
break;
case V_911 :
V_883 = sizeof( struct V_912 ) <<
V_896 ;
break;
default:
if ( F_70 ( F_427 () ) ) {
F_428 ( V_21 -> V_37 ,
L_111 ,
V_906 ) ;
}
break;
}
V_880 -> V_129 |= V_893 ;
}
V_881 |= F_424 ( V_53 ) << V_899 ;
V_881 |= V_880 -> V_129 & V_900 ;
F_425 ( V_21 , V_881 , 0 ,
V_882 , V_883 ) ;
}
static T_9 F_429 ( T_1 V_129 )
{
T_9 V_913 = F_68 ( V_914 |
V_915 ) ;
if ( V_129 & V_902 )
V_913 |= F_68 ( V_916 ) ;
#ifdef F_69
if ( V_129 & V_130 )
V_913 |= F_68 ( V_917 ) ;
#endif
#ifdef F_122
if ( V_129 & ( V_892 | V_918 ) )
#else
if ( V_129 & V_892 )
#endif
V_913 |= F_68 ( V_919 ) ;
if ( ! ( V_129 & V_904 ) )
V_913 |= F_68 ( V_920 ) ;
return V_913 ;
}
static void F_430 ( union V_24 * V_25 ,
T_1 V_129 , unsigned int V_921 )
{
T_9 V_922 = F_68 ( V_921 << V_923 ) ;
if ( V_129 & V_893 )
V_922 |= F_68 ( V_924 ) ;
if ( V_129 & V_894 )
V_922 |= F_68 ( V_925 ) ;
#ifdef F_122
if ( V_129 & ( V_892 | V_926 ) )
#else
if ( V_129 & V_892 )
#endif
V_922 |= F_68 ( 1 << V_898 ) ;
#ifdef F_122
if ( V_129 & ( V_905 | V_926 ) )
#else
if ( V_129 & V_905 )
#endif
V_922 |= F_68 ( V_927 ) ;
V_25 -> V_193 . V_922 = V_922 ;
}
static void F_431 ( struct V_20 * V_21 ,
struct V_22 * V_880 ,
const T_4 V_218 )
{
T_7 V_45 ;
struct V_159 * V_53 = V_880 -> V_53 ;
struct V_22 * V_23 ;
union V_24 * V_25 ;
struct V_237 * V_238 = & F_125 ( V_53 ) -> V_239 [ 0 ] ;
unsigned int V_243 = V_53 -> V_243 ;
unsigned int V_252 = F_124 ( V_53 ) ;
unsigned int V_921 = V_53 -> V_46 - V_218 ;
T_1 V_129 = V_880 -> V_129 ;
T_9 V_913 ;
T_5 V_11 = V_21 -> V_44 ;
V_25 = F_35 ( V_21 , V_11 ) ;
F_430 ( V_25 , V_129 , V_921 ) ;
V_913 = F_429 ( V_129 ) ;
#ifdef F_122
if ( V_129 & V_926 ) {
if ( V_243 < sizeof( struct V_271 ) ) {
V_252 -= sizeof( struct V_271 ) - V_243 ;
V_243 = 0 ;
} else {
V_243 -= sizeof( struct V_271 ) ;
}
}
#endif
V_45 = F_432 ( V_21 -> V_37 , V_53 -> V_56 , V_252 , V_83 ) ;
if ( F_116 ( V_21 -> V_37 , V_45 ) )
goto V_928;
F_55 ( V_880 , V_46 , V_252 ) ;
F_433 ( V_880 , V_45 , V_45 ) ;
V_25 -> V_193 . V_929 = F_119 ( V_45 ) ;
for (; ; ) {
while ( F_70 ( V_252 > V_930 ) ) {
V_25 -> V_193 . V_931 =
V_913 | F_68 ( V_930 ) ;
V_11 ++ ;
V_25 ++ ;
if ( V_11 == V_21 -> V_52 ) {
V_25 = F_35 ( V_21 , 0 ) ;
V_11 = 0 ;
}
V_45 += V_930 ;
V_252 -= V_930 ;
V_25 -> V_193 . V_929 = F_119 ( V_45 ) ;
V_25 -> V_193 . V_922 = 0 ;
}
if ( F_73 ( ! V_243 ) )
break;
V_25 -> V_193 . V_931 = V_913 | F_68 ( V_252 ) ;
V_11 ++ ;
V_25 ++ ;
if ( V_11 == V_21 -> V_52 ) {
V_25 = F_35 ( V_21 , 0 ) ;
V_11 = 0 ;
}
#ifdef F_122
V_252 = F_321 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_252 = F_434 ( V_238 ) ;
#endif
V_243 -= V_252 ;
V_45 = F_435 ( V_21 -> V_37 , V_238 , 0 , V_252 ,
V_83 ) ;
if ( F_116 ( V_21 -> V_37 , V_45 ) )
goto V_928;
V_23 = & V_21 -> V_42 [ V_11 ] ;
F_55 ( V_23 , V_46 , V_252 ) ;
F_433 ( V_23 , V_45 , V_45 ) ;
V_25 -> V_193 . V_929 = F_119 ( V_45 ) ;
V_25 -> V_193 . V_922 = 0 ;
V_238 ++ ;
}
V_913 |= F_68 ( V_252 ) | F_68 ( V_932 ) ;
V_25 -> V_193 . V_931 = V_913 ;
F_436 ( F_81 ( V_21 ) , V_880 -> V_127 ) ;
V_880 -> V_48 = V_134 ;
F_109 () ;
V_880 -> V_47 = V_25 ;
V_11 ++ ;
if ( V_11 == V_21 -> V_52 )
V_11 = 0 ;
V_21 -> V_44 = V_11 ;
F_110 ( V_11 , V_21 -> V_109 ) ;
return;
V_928:
F_333 ( V_21 -> V_37 , L_112 ) ;
for (; ; ) {
V_23 = & V_21 -> V_42 [ V_11 ] ;
F_51 ( V_21 , V_23 ) ;
if ( V_23 == V_880 )
break;
if ( V_11 == 0 )
V_11 = V_21 -> V_52 ;
V_11 -- ;
}
V_21 -> V_44 = V_11 ;
}
static void F_437 ( struct V_20 * V_82 ,
struct V_22 * V_880 )
{
struct V_117 * V_118 = V_82 -> V_118 ;
union V_933 V_934 = { . V_935 = 0 } ;
union V_933 V_936 = { . V_935 = 0 } ;
union {
unsigned char * V_197 ;
struct V_202 * V_203 ;
struct V_937 * V_938 ;
} V_204 ;
struct V_217 * V_939 ;
T_8 V_940 ;
if ( ! V_118 )
return;
if ( ! V_82 -> V_374 )
return;
V_82 -> V_375 ++ ;
V_204 . V_197 = F_438 ( V_880 -> V_53 ) ;
if ( ( V_880 -> V_205 != F_121 ( V_907 ) ||
V_204 . V_938 -> V_206 != V_216 ) &&
( V_880 -> V_205 != F_121 ( V_213 ) ||
V_204 . V_203 -> V_205 != V_216 ) )
return;
V_939 = F_416 ( V_880 -> V_53 ) ;
if ( ! V_939 || V_939 -> V_941 )
return;
if ( ! V_939 -> V_942 && ( V_82 -> V_375 < V_82 -> V_374 ) )
return;
V_82 -> V_375 = 0 ;
V_940 = F_439 ( V_880 -> V_129 >> V_943 ) ;
V_934 . V_944 . V_940 = V_940 ;
if ( V_880 -> V_129 & ( V_945 | V_902 ) )
V_936 . V_946 . V_947 ^= V_939 -> V_948 ^ F_121 ( V_210 ) ;
else
V_936 . V_946 . V_947 ^= V_939 -> V_948 ^ V_880 -> V_205 ;
V_936 . V_946 . V_949 ^= V_939 -> V_950 ;
if ( V_880 -> V_205 == F_121 ( V_213 ) ) {
V_934 . V_944 . V_951 = V_952 ;
V_936 . V_953 ^= V_204 . V_203 -> V_889 ^ V_204 . V_203 -> V_890 ;
} else {
V_934 . V_944 . V_951 = V_954 ;
V_936 . V_953 ^= V_204 . V_938 -> V_889 . V_955 [ 0 ] ^
V_204 . V_938 -> V_889 . V_955 [ 1 ] ^
V_204 . V_938 -> V_889 . V_955 [ 2 ] ^
V_204 . V_938 -> V_889 . V_955 [ 3 ] ^
V_204 . V_938 -> V_890 . V_955 [ 0 ] ^
V_204 . V_938 -> V_890 . V_955 [ 1 ] ^
V_204 . V_938 -> V_890 . V_955 [ 2 ] ^
V_204 . V_938 -> V_890 . V_955 [ 3 ] ;
}
F_440 ( & V_118 -> V_2 -> V_8 ,
V_934 , V_936 , V_82 -> V_50 ) ;
}
static int F_441 ( struct V_20 * V_21 , T_5 V_252 )
{
F_78 ( V_21 -> V_18 , V_21 -> V_50 ) ;
F_85 () ;
if ( F_73 ( F_84 ( V_21 ) < V_252 ) )
return - V_684 ;
F_442 ( V_21 -> V_18 , V_21 -> V_50 ) ;
++ V_21 -> V_112 . V_137 ;
return 0 ;
}
static inline int F_443 ( struct V_20 * V_21 , T_5 V_252 )
{
if ( F_73 ( F_84 ( V_21 ) >= V_252 ) )
return 0 ;
return F_441 ( V_21 , V_252 ) ;
}
static T_5 F_444 ( struct V_17 * V_37 , struct V_159 * V_53 )
{
struct V_1 * V_2 = F_62 ( V_37 ) ;
int V_956 = F_445 ( V_53 ) ? F_446 ( V_53 ) :
F_447 () ;
#ifdef F_122
T_8 V_205 = F_448 ( V_53 ) ;
if ( ( ( V_205 == F_439 ( V_214 ) ) ||
( V_205 == F_439 ( V_957 ) ) ) &&
( V_2 -> V_100 & V_471 ) ) {
struct V_958 * V_959 ;
V_959 = & V_2 -> V_388 [ V_960 ] ;
while ( V_956 >= V_959 -> V_390 )
V_956 -= V_959 -> V_390 ;
V_956 += V_2 -> V_388 [ V_960 ] . V_961 ;
return V_956 ;
}
#endif
if ( V_2 -> V_100 & V_339 ) {
while ( F_70 ( V_956 >= V_37 -> V_962 ) )
V_956 -= V_37 -> V_962 ;
return V_956 ;
}
return F_449 ( V_37 , V_53 ) ;
}
T_14 F_450 ( struct V_159 * V_53 ,
struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_22 * V_880 ;
int V_963 ;
T_1 V_129 = 0 ;
#if V_254 > V_930
unsigned short V_959 ;
#endif
T_5 V_52 = F_451 ( F_124 ( V_53 ) ) ;
T_8 V_205 = V_53 -> V_205 ;
T_4 V_218 = 0 ;
#if V_254 > V_930
for ( V_959 = 0 ; V_959 < F_125 ( V_53 ) -> V_258 ; V_959 ++ )
V_52 += F_451 ( F_125 ( V_53 ) -> V_239 [ V_959 ] . V_252 ) ;
#else
V_52 += F_125 ( V_53 ) -> V_258 ;
#endif
if ( F_443 ( V_21 , V_52 + 3 ) ) {
V_21 -> V_112 . V_710 ++ ;
return V_964 ;
}
V_880 = & V_21 -> V_42 [ V_21 -> V_44 ] ;
V_880 -> V_53 = V_53 ;
V_880 -> V_127 = V_53 -> V_46 ;
V_880 -> V_128 = 1 ;
if ( F_452 ( V_53 ) ) {
V_129 |= F_453 ( V_53 ) << V_943 ;
V_129 |= V_902 ;
} else if ( V_205 == F_121 ( V_210 ) ) {
struct V_200 * V_965 , V_966 ;
V_965 = F_454 ( V_53 , V_208 , sizeof( V_966 ) , & V_966 ) ;
if ( ! V_965 )
goto V_967;
V_205 = V_965 -> V_212 ;
V_129 |= F_455 ( V_965 -> V_968 ) <<
V_943 ;
V_129 |= V_945 ;
}
F_456 ( V_53 ) ;
#ifdef F_69
if ( F_70 ( F_125 ( V_53 ) -> V_129 & V_969 ) ) {
F_125 ( V_53 ) -> V_129 |= V_970 ;
V_129 |= V_130 ;
}
#endif
#ifdef F_324
if ( V_2 -> V_100 & V_383 )
V_129 |= V_905 ;
#endif
if ( ( V_2 -> V_100 & V_101 ) &&
( ( V_129 & ( V_902 | V_945 ) ) ||
( V_53 -> V_971 != V_972 ) ) ) {
V_129 &= ~ V_973 ;
V_129 |= ( V_53 -> V_971 & 0x7 ) <<
V_974 ;
if ( V_129 & V_945 ) {
struct V_975 * V_965 ;
if ( F_413 ( V_53 ) &&
F_414 ( V_53 , 0 , 0 , V_187 ) )
goto V_967;
V_965 = (struct V_975 * ) V_53 -> V_56 ;
V_965 -> V_968 = F_439 ( V_129 >>
V_943 ) ;
} else {
V_129 |= V_902 ;
}
}
V_880 -> V_129 = V_129 ;
V_880 -> V_205 = V_205 ;
#ifdef F_122
if ( ( V_205 == F_121 ( V_214 ) ) &&
( V_21 -> V_18 -> V_160 & ( V_976 | V_977 ) ) ) {
V_963 = F_457 ( V_21 , V_880 , & V_218 ) ;
if ( V_963 < 0 )
goto V_967;
goto V_978;
}
#endif
V_963 = F_411 ( V_21 , V_880 , & V_218 ) ;
if ( V_963 < 0 )
goto V_967;
else if ( ! V_963 )
F_426 ( V_21 , V_880 ) ;
if ( F_2 ( V_348 , & V_21 -> V_4 ) )
F_437 ( V_21 , V_880 ) ;
#ifdef F_122
V_978:
#endif
F_431 ( V_21 , V_880 , V_218 ) ;
F_443 ( V_21 , V_979 ) ;
return V_980 ;
V_967:
F_52 ( V_880 -> V_53 ) ;
V_880 -> V_53 = NULL ;
return V_980 ;
}
static T_14 F_458 ( struct V_159 * V_53 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_20 * V_21 ;
if ( F_70 ( V_53 -> V_46 < 17 ) ) {
if ( F_149 ( V_53 , 17 - V_53 -> V_46 ) )
return V_980 ;
V_53 -> V_46 = 17 ;
}
V_21 = V_2 -> V_21 [ V_53 -> V_981 ] ;
return F_450 ( V_53 , V_2 , V_21 ) ;
}
static int F_459 ( struct V_17 * V_18 , void * V_439 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_982 * V_507 = V_439 ;
if ( ! F_460 ( V_507 -> V_983 ) )
return - V_984 ;
memcpy ( V_18 -> V_985 , V_507 -> V_983 , V_18 -> V_986 ) ;
memcpy ( V_8 -> V_72 . V_507 , V_507 -> V_983 , V_18 -> V_986 ) ;
V_8 -> V_72 . V_311 . V_506 ( V_8 , 0 , V_8 -> V_72 . V_507 , F_227 ( 0 ) , V_508 ) ;
return 0 ;
}
static int
F_461 ( struct V_17 * V_18 , int V_987 , int V_988 , T_5 V_507 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_5 V_989 ;
int V_990 ;
if ( V_987 != V_8 -> V_315 . V_991 . V_987 )
return - V_681 ;
V_990 = V_8 -> V_315 . V_311 . V_992 ( V_8 , V_507 , V_988 , & V_989 ) ;
if ( ! V_990 )
V_990 = V_989 ;
return V_990 ;
}
static int F_462 ( struct V_17 * V_18 , int V_987 , int V_988 ,
T_5 V_507 , T_5 V_989 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( V_987 != V_8 -> V_315 . V_991 . V_987 )
return - V_681 ;
return V_8 -> V_315 . V_311 . V_993 ( V_8 , V_507 , V_988 , V_989 ) ;
}
static int F_463 ( struct V_17 * V_18 , struct V_994 * V_995 , int V_996 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
switch ( V_996 ) {
#ifdef F_69
case V_997 :
return F_464 ( V_2 , V_995 , V_996 ) ;
#endif
default:
return F_465 ( & V_2 -> V_8 . V_315 . V_991 , F_466 ( V_995 ) , V_996 ) ;
}
}
static int F_467 ( struct V_17 * V_37 )
{
int V_356 = 0 ;
struct V_1 * V_2 = F_62 ( V_37 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( F_460 ( V_8 -> V_72 . V_998 ) ) {
F_357 () ;
V_356 = F_468 ( V_37 , V_8 -> V_72 . V_998 , V_999 ) ;
F_359 () ;
V_8 -> V_72 . V_311 . V_614 ( V_8 , F_227 ( 0 ) ) ;
}
return V_356 ;
}
static int F_469 ( struct V_17 * V_37 )
{
int V_356 = 0 ;
struct V_1 * V_2 = F_62 ( V_37 ) ;
struct V_1000 * V_72 = & V_2 -> V_8 . V_72 ;
if ( F_460 ( V_72 -> V_998 ) ) {
F_357 () ;
V_356 = F_470 ( V_37 , V_72 -> V_998 , V_999 ) ;
F_359 () ;
}
return V_356 ;
}
static void F_471 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
int V_11 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
V_2 -> V_100 |= V_226 ;
if ( V_2 -> V_100 & V_364 ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_153 ; V_11 ++ )
F_188 ( 0 , V_2 -> V_118 [ V_11 ] ) ;
} else {
F_200 ( V_2 -> V_36 -> V_342 , V_18 ) ;
}
V_2 -> V_100 &= ~ V_226 ;
}
static struct V_1001 * F_472 ( struct V_17 * V_18 ,
struct V_1001 * V_86 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
int V_11 ;
F_473 () ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
struct V_20 * V_82 = F_474 ( V_2 -> V_30 [ V_11 ] ) ;
T_2 V_132 , V_106 ;
unsigned int V_1002 ;
if ( V_82 ) {
do {
V_1002 = F_475 ( & V_82 -> V_131 ) ;
V_106 = V_82 -> V_86 . V_106 ;
V_132 = V_82 -> V_86 . V_132 ;
} while ( F_476 ( & V_82 -> V_131 , V_1002 ) );
V_86 -> V_715 += V_106 ;
V_86 -> V_714 += V_132 ;
}
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_82 = F_474 ( V_2 -> V_21 [ V_11 ] ) ;
T_2 V_132 , V_106 ;
unsigned int V_1002 ;
if ( V_82 ) {
do {
V_1002 = F_475 ( & V_82 -> V_131 ) ;
V_106 = V_82 -> V_86 . V_106 ;
V_132 = V_82 -> V_86 . V_132 ;
} while ( F_476 ( & V_82 -> V_131 , V_1002 ) );
V_86 -> V_717 += V_106 ;
V_86 -> V_716 += V_132 ;
}
}
F_477 () ;
V_86 -> V_824 = V_18 -> V_86 . V_824 ;
V_86 -> V_825 = V_18 -> V_86 . V_825 ;
V_86 -> V_827 = V_18 -> V_86 . V_827 ;
V_86 -> V_828 = V_18 -> V_86 . V_828 ;
V_86 -> V_829 = V_18 -> V_86 . V_829 ;
return V_86 ;
}
static void F_478 ( struct V_1 * V_2 , T_4 V_104 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_1003 , V_1004 ;
int V_11 ;
if ( V_8 -> V_72 . type == V_73 )
return;
V_1003 = F_11 ( V_8 , V_1005 ) ;
V_1004 = V_1003 ;
for ( V_11 = 0 ; V_11 < V_649 ; V_11 ++ ) {
T_4 V_1006 = V_1003 >> ( V_11 * V_1007 ) ;
if ( V_1006 > V_104 )
V_1003 &= ~ ( 0x7 << V_1007 ) ;
}
if ( V_1003 != V_1004 )
F_45 ( V_8 , V_1005 , V_1003 ) ;
return;
}
static void F_479 ( struct V_1 * V_2 )
{
struct V_17 * V_37 = V_2 -> V_18 ;
struct V_1008 * V_97 = & V_2 -> V_97 ;
struct V_1009 * V_1010 = V_2 -> V_535 ;
T_4 V_1011 ;
for ( V_1011 = 0 ; V_1011 < V_1012 ; V_1011 ++ ) {
T_4 V_104 = 0 ;
if ( V_2 -> V_531 & V_532 )
V_104 = F_480 ( V_97 , 0 , V_1011 ) ;
else if ( V_1010 )
V_104 = V_1010 -> V_536 [ V_1011 ] ;
F_481 ( V_37 , V_1011 , V_104 ) ;
}
}
int F_482 ( struct V_17 * V_37 , T_4 V_104 )
{
struct V_1 * V_2 = F_62 ( V_37 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( V_104 > V_2 -> V_97 . V_645 . V_646 ||
( V_8 -> V_72 . type == V_73 &&
V_104 < V_649 ) )
return - V_681 ;
if ( F_31 ( V_37 ) )
F_348 ( V_37 ) ;
F_364 ( V_2 ) ;
if ( V_104 ) {
F_483 ( V_37 , V_104 ) ;
F_479 ( V_2 ) ;
V_2 -> V_100 |= V_101 ;
if ( V_2 -> V_8 . V_72 . type == V_73 ) {
V_2 -> V_1013 = V_2 -> V_8 . V_87 . V_661 ;
V_2 -> V_8 . V_87 . V_661 = V_1014 ;
}
} else {
F_484 ( V_37 ) ;
if ( V_2 -> V_8 . V_72 . type == V_73 )
V_2 -> V_8 . V_87 . V_661 = V_2 -> V_1013 ;
V_2 -> V_100 &= ~ V_101 ;
V_2 -> V_660 . V_98 = false ;
V_2 -> V_97 . V_98 = false ;
}
F_358 ( V_2 ) ;
F_478 ( V_2 , V_104 ) ;
if ( F_31 ( V_37 ) )
F_345 ( V_37 ) ;
return 0 ;
}
void F_485 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
if ( F_31 ( V_18 ) )
F_295 ( V_2 ) ;
else
F_301 ( V_2 ) ;
}
static T_15 F_486 ( struct V_17 * V_18 ,
T_15 V_160 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
if ( ! ( V_160 & V_173 ) )
V_160 &= ~ V_1015 ;
if ( ! ( V_2 -> V_115 & V_636 ) )
V_160 &= ~ V_1015 ;
return V_160 ;
}
static int F_487 ( struct V_17 * V_18 ,
T_15 V_160 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
T_15 V_1016 = V_18 -> V_160 ^ V_160 ;
bool V_1017 = false ;
if ( ! ( V_160 & V_1015 ) ) {
if ( V_2 -> V_115 & V_478 )
V_1017 = true ;
V_2 -> V_115 &= ~ V_478 ;
} else if ( ( V_2 -> V_115 & V_636 ) &&
! ( V_2 -> V_115 & V_478 ) ) {
if ( V_2 -> V_280 == 1 ||
V_2 -> V_280 > V_1018 ) {
V_2 -> V_115 |= V_478 ;
V_1017 = true ;
} else if ( ( V_1016 ^ V_160 ) & V_1015 ) {
F_79 ( V_135 , L_113
L_114 ) ;
}
}
switch ( V_160 & V_1019 ) {
case V_1019 :
if ( ! ( V_2 -> V_100 & V_549 ) )
V_1017 = true ;
V_2 -> V_100 &= ~ V_339 ;
V_2 -> V_100 |= V_549 ;
break;
default:
if ( V_2 -> V_100 & V_549 )
V_1017 = true ;
V_2 -> V_100 &= ~ V_549 ;
if ( V_2 -> V_100 & V_383 )
break;
if ( F_211 ( V_18 ) > 1 )
break;
if ( V_2 -> V_388 [ V_389 ] . V_631 <= 1 )
break;
if ( ! V_2 -> V_374 )
break;
V_2 -> V_100 |= V_339 ;
break;
}
if ( V_160 & V_223 )
F_242 ( V_2 ) ;
else
F_241 ( V_2 ) ;
if ( V_1016 & V_246 )
V_1017 = true ;
V_18 -> V_160 = V_160 ;
if ( V_1017 )
F_485 ( V_18 ) ;
return 0 ;
}
static int F_488 ( struct V_1020 * V_1021 , struct V_1022 * V_1023 [] ,
struct V_17 * V_37 ,
const unsigned char * V_507 ,
T_5 V_100 )
{
struct V_1 * V_2 = F_62 ( V_37 ) ;
int V_356 ;
if ( ! ( V_2 -> V_100 & V_383 ) )
return - V_1024 ;
if ( V_1021 -> V_1025 & V_1026 ) {
F_25 ( L_115 ,
V_1027 ) ;
return - V_681 ;
}
if ( F_489 ( V_507 ) ) {
T_1 V_1028 = V_502 ;
if ( F_246 ( V_37 ) < V_1028 )
V_356 = F_490 ( V_37 , V_507 ) ;
else
V_356 = - V_503 ;
} else if ( F_491 ( V_507 ) ) {
V_356 = F_492 ( V_37 , V_507 ) ;
} else {
V_356 = - V_681 ;
}
if ( V_356 == - V_1029 && ! ( V_100 & V_1030 ) )
V_356 = 0 ;
return V_356 ;
}
static int F_493 ( struct V_1020 * V_1021 ,
struct V_17 * V_37 ,
const unsigned char * V_507 )
{
struct V_1 * V_2 = F_62 ( V_37 ) ;
int V_356 = - V_1024 ;
if ( V_1021 -> V_1025 & V_1026 ) {
F_25 ( L_115 ,
V_1027 ) ;
return - V_681 ;
}
if ( V_2 -> V_100 & V_383 ) {
if ( F_489 ( V_507 ) )
V_356 = F_494 ( V_37 , V_507 ) ;
else if ( F_491 ( V_507 ) )
V_356 = F_495 ( V_37 , V_507 ) ;
else
V_356 = - V_681 ;
}
return V_356 ;
}
static int F_496 ( struct V_159 * V_53 ,
struct V_1031 * V_1032 ,
struct V_17 * V_37 ,
int V_1033 )
{
struct V_1 * V_2 = F_62 ( V_37 ) ;
if ( V_2 -> V_100 & V_383 )
V_1033 = F_497 ( V_53 , V_1032 , V_37 , V_1033 ) ;
return V_1033 ;
}
int F_498 ( struct V_1 * V_2 , T_5 V_307 ,
T_5 V_1034 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_5 V_1035 = V_2 -> V_1036 & V_1037 ;
int V_1038 = 0 ;
switch ( V_307 ) {
case V_1039 :
switch ( V_1034 ) {
case V_1040 :
if ( V_8 -> V_1041 . V_1042 != 0 )
break;
case V_1043 :
case V_1044 :
V_1038 = 1 ;
break;
}
break;
case V_1045 :
if ( V_1034 != V_1046 )
V_1038 = 1 ;
break;
case V_1047 :
V_1038 = 1 ;
break;
case V_1048 :
case V_1049 :
if ( ( V_1035 == V_1050 ) ||
( ( V_1035 == V_1051 ) &&
( V_8 -> V_1041 . V_1042 == 0 ) ) ) {
V_1038 = 1 ;
}
break;
}
return V_1038 ;
}
static int T_11 F_499 ( struct V_620 * V_36 ,
const struct V_1052 * V_1053 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 = NULL ;
struct V_7 * V_8 ;
const struct V_1054 * V_1055 = V_1056 [ V_1053 -> V_1057 ] ;
static int V_1058 ;
int V_11 , V_356 , V_1059 ;
T_4 V_1060 [ V_1061 ] ;
unsigned int V_390 = F_500 () ;
unsigned int V_1062 = 0 ;
#ifdef F_122
T_5 V_1063 ;
#endif
T_1 V_1064 ;
if ( V_36 -> V_1065 ) {
F_501 ( 1 , V_1066 L_116 ,
F_502 ( V_36 ) , V_36 -> V_623 , V_36 -> V_154 ) ;
return - V_681 ;
}
V_356 = F_354 ( V_36 ) ;
if ( V_356 )
return V_356 ;
if ( ! F_503 ( & V_36 -> V_37 , F_207 ( 64 ) ) &&
! F_504 ( & V_36 -> V_37 , F_207 ( 64 ) ) ) {
V_1059 = 1 ;
} else {
V_356 = F_503 ( & V_36 -> V_37 , F_207 ( 32 ) ) ;
if ( V_356 ) {
V_356 = F_504 ( & V_36 -> V_37 ,
F_207 ( 32 ) ) ;
if ( V_356 ) {
F_333 ( & V_36 -> V_37 ,
L_117 ) ;
goto V_1067;
}
}
V_1059 = 0 ;
}
V_356 = F_505 ( V_36 , F_506 ( V_36 ,
V_1068 ) , V_1027 ) ;
if ( V_356 ) {
F_333 ( & V_36 -> V_37 ,
L_118 , V_356 ) ;
goto V_1069;
}
F_507 ( V_36 ) ;
F_355 ( V_36 ) ;
F_353 ( V_36 ) ;
#ifdef F_283
if ( V_1055 -> V_72 == V_73 )
V_1062 = F_321 (unsigned int, indices * MAX_TRAFFIC_CLASS,
IXGBE_MAX_RSS_INDICES) ;
else
V_1062 = F_321 (unsigned int, indices * MAX_TRAFFIC_CLASS,
IXGBE_MAX_FDIR_INDICES) ;
#endif
if ( V_1055 -> V_72 == V_73 )
V_390 = F_321 (unsigned int, indices, IXGBE_MAX_RSS_INDICES) ;
else
V_390 = F_321 (unsigned int, indices, IXGBE_MAX_FDIR_INDICES) ;
#ifdef F_122
V_390 += F_321 (unsigned int, num_possible_cpus(),
IXGBE_MAX_FCOE_INDICES) ;
#endif
V_390 = F_508 (unsigned int, dcb_max, indices) ;
V_18 = F_509 ( sizeof( struct V_1 ) , V_390 ) ;
if ( ! V_18 ) {
V_356 = - V_503 ;
goto V_1070;
}
F_510 ( V_18 , & V_36 -> V_37 ) ;
V_2 = F_62 ( V_18 ) ;
F_511 ( V_36 , V_2 ) ;
V_2 -> V_18 = V_18 ;
V_2 -> V_36 = V_36 ;
V_8 = & V_2 -> V_8 ;
V_8 -> V_1071 = V_2 ;
V_2 -> V_1072 = F_512 ( V_1073 , V_1074 ) ;
V_8 -> V_373 = F_513 ( F_514 ( V_36 , 0 ) ,
F_515 ( V_36 , 0 ) ) ;
if ( ! V_8 -> V_373 ) {
V_356 = - V_673 ;
goto V_1075;
}
V_18 -> V_1076 = & V_1077 ;
F_516 ( V_18 ) ;
V_18 -> V_1078 = 5 * V_875 ;
strncpy ( V_18 -> V_16 , F_502 ( V_36 ) , sizeof( V_18 -> V_16 ) - 1 ) ;
V_2 -> V_1079 = V_1058 ;
memcpy ( & V_8 -> V_72 . V_311 , V_1055 -> V_1080 , sizeof( V_8 -> V_72 . V_311 ) ) ;
V_8 -> V_72 . type = V_1055 -> V_72 ;
memcpy ( & V_8 -> V_1081 . V_311 , V_1055 -> V_1082 , sizeof( V_8 -> V_1081 . V_311 ) ) ;
V_1064 = F_11 ( V_8 , V_1083 ) ;
if ( ! ( V_1064 & ( 1 << 8 ) ) )
V_8 -> V_1081 . V_311 . V_193 = & V_1084 ;
memcpy ( & V_8 -> V_315 . V_311 , V_1055 -> V_1085 , sizeof( V_8 -> V_315 . V_311 ) ) ;
V_8 -> V_315 . V_861 = V_1086 ;
V_8 -> V_315 . V_991 . V_987 = V_1087 ;
V_8 -> V_315 . V_991 . V_1088 = 0 ;
V_8 -> V_315 . V_991 . V_1089 = V_1090 | V_1091 ;
V_8 -> V_315 . V_991 . V_37 = V_18 ;
V_8 -> V_315 . V_991 . V_1092 = F_461 ;
V_8 -> V_315 . V_991 . V_1093 = F_462 ;
V_1055 -> V_1094 ( V_8 ) ;
V_356 = F_320 ( V_2 ) ;
if ( V_356 )
goto V_1095;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
case V_76 :
F_45 ( & V_2 -> V_8 , V_688 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_100 & V_318 ) {
T_1 V_601 = F_11 ( V_8 , V_602 ) ;
if ( V_601 & V_603 )
F_173 ( V_135 , L_54 ) ;
}
if ( V_1096 )
V_8 -> V_1096 = V_1096 ;
V_8 -> V_315 . V_1097 = true ;
V_356 = V_8 -> V_72 . V_311 . V_1098 ( V_8 ) ;
V_8 -> V_315 . V_1097 = false ;
if ( V_356 == V_609 &&
V_8 -> V_72 . type == V_73 ) {
V_356 = 0 ;
} else if ( V_356 == V_610 ) {
F_302 ( L_119
L_120 ) ;
F_302 ( L_121
L_122 ) ;
goto V_1095;
} else if ( V_356 ) {
F_302 ( L_123 , V_356 ) ;
goto V_1095;
}
#ifdef F_324
F_517 ( V_2 , V_1055 ) ;
#endif
V_18 -> V_160 = V_1099 |
V_1100 |
V_1101 |
V_1102 |
V_223 |
V_1103 |
V_1104 |
V_1105 |
V_161 |
V_173 ;
V_18 -> V_1106 = V_18 -> V_160 ;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
case V_76 :
V_18 -> V_160 |= V_1107 ;
V_18 -> V_1106 |= V_1107 |
V_1019 ;
break;
default:
break;
}
V_18 -> V_1106 |= V_246 ;
V_18 -> V_1108 |= V_1104 ;
V_18 -> V_1108 |= V_1105 ;
V_18 -> V_1108 |= V_1100 ;
V_18 -> V_1108 |= V_1101 ;
V_18 -> V_1108 |= V_1099 ;
V_18 -> V_1109 |= V_1110 ;
V_18 -> V_1109 |= V_1111 ;
#ifdef F_283
V_18 -> V_1112 = & V_1112 ;
#endif
#ifdef F_122
if ( V_2 -> V_100 & V_640 ) {
if ( V_8 -> V_72 . V_311 . V_1113 ) {
V_8 -> V_72 . V_311 . V_1113 ( V_8 , & V_1063 ) ;
if ( V_1063 & V_1114 )
V_2 -> V_100 &= ~ V_640 ;
}
V_2 -> V_388 [ V_960 ] . V_631 = V_1115 ;
V_18 -> V_160 |= V_976 |
V_977 ;
V_18 -> V_1108 |= V_976 |
V_977 |
V_530 ;
}
#endif
if ( V_1059 ) {
V_18 -> V_160 |= V_1116 ;
V_18 -> V_1108 |= V_1116 ;
}
if ( V_2 -> V_115 & V_636 )
V_18 -> V_1106 |= V_1015 ;
if ( V_2 -> V_115 & V_478 )
V_18 -> V_160 |= V_1015 ;
if ( V_8 -> V_1081 . V_311 . V_1117 ( V_8 , NULL ) < 0 ) {
F_302 ( L_124 ) ;
V_356 = - V_673 ;
goto V_1095;
}
memcpy ( V_18 -> V_985 , V_8 -> V_72 . V_1118 , V_18 -> V_986 ) ;
memcpy ( V_18 -> V_1118 , V_8 -> V_72 . V_1118 , V_18 -> V_986 ) ;
if ( F_518 ( V_18 -> V_1118 ) ) {
F_302 ( L_125 ) ;
V_356 = - V_673 ;
goto V_1095;
}
F_519 ( & V_2 -> V_604 , & F_407 ,
( unsigned long ) V_2 ) ;
F_520 ( & V_2 -> V_6 , F_409 ) ;
F_8 ( V_5 , & V_2 -> V_4 ) ;
V_356 = F_358 ( V_2 ) ;
if ( V_356 )
goto V_1095;
V_2 -> V_692 = 0 ;
V_8 -> V_1081 . V_311 . V_193 ( V_8 , 0x2c , & V_2 -> V_1036 ) ;
if ( F_498 ( V_2 , V_36 -> V_154 , V_36 -> V_629 ) )
V_2 -> V_692 = V_1119 ;
F_521 ( & V_2 -> V_36 -> V_37 , V_2 -> V_692 ) ;
#ifdef F_69
F_522 ( V_2 ) ;
#endif
V_8 -> V_1081 . V_311 . V_193 ( V_8 , 0x2e , & V_2 -> V_1120 ) ;
V_8 -> V_1081 . V_311 . V_193 ( V_8 , 0x2d , & V_2 -> V_1121 ) ;
V_8 -> V_72 . V_311 . V_1122 ( V_8 ) ;
F_523 ( L_126 ,
( V_8 -> V_1041 . V_1123 == V_1124 ? L_127 :
V_8 -> V_1041 . V_1123 == V_1125 ? L_128 :
L_129 ) ,
( V_8 -> V_1041 . V_1126 == V_1127 ? L_130 :
V_8 -> V_1041 . V_1126 == V_1128 ? L_131 :
V_8 -> V_1041 . V_1126 == V_1129 ? L_132 :
L_129 ) ,
V_18 -> V_985 ) ;
V_356 = F_524 ( V_8 , V_1060 , V_1061 ) ;
if ( V_356 )
strncpy ( V_1060 , L_129 , V_1061 ) ;
if ( F_287 ( V_8 ) && V_8 -> V_315 . V_861 != V_1130 )
F_523 ( L_133 ,
V_8 -> V_72 . type , V_8 -> V_315 . type , V_8 -> V_315 . V_861 ,
V_1060 ) ;
else
F_523 ( L_134 ,
V_8 -> V_72 . type , V_8 -> V_315 . type , V_1060 ) ;
if ( V_8 -> V_1041 . V_1126 <= V_1128 ) {
F_303 ( L_135
L_136 ) ;
F_303 ( L_137
L_138 ) ;
}
V_356 = V_8 -> V_72 . V_311 . V_1131 ( V_8 ) ;
if ( V_356 == V_612 ) {
F_303 ( L_76
L_139
L_140
L_141
L_80
L_81 ) ;
}
strcpy ( V_18 -> V_16 , L_142 ) ;
V_356 = F_525 ( V_18 ) ;
if ( V_356 )
goto V_1132;
if ( V_8 -> V_72 . V_311 . V_619 &&
( ( V_8 -> V_315 . V_598 ) ||
( ( V_8 -> V_72 . V_311 . V_599 ( V_8 ) == V_600 ) &&
( V_8 -> V_72 . type == V_75 ) ) ) )
V_8 -> V_72 . V_311 . V_619 ( V_8 ) ;
F_313 ( V_18 ) ;
#ifdef F_192
if ( F_100 ( & V_36 -> V_37 ) == 0 ) {
V_2 -> V_100 |= V_151 ;
F_97 ( V_2 ) ;
}
#endif
if ( V_2 -> V_100 & V_383 ) {
F_79 ( V_135 , L_143 , V_2 -> V_274 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_274 ; V_11 ++ )
F_526 ( V_36 , ( V_11 | 0x10000000 ) ) ;
}
if ( V_8 -> V_72 . V_311 . V_1133 )
V_8 -> V_72 . V_311 . V_1133 ( V_8 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_467 ( V_18 ) ;
F_523 ( L_144 , V_1134 ) ;
V_1058 ++ ;
#ifdef F_527
if ( F_528 ( V_2 ) )
F_77 ( V_135 , L_145 ) ;
#endif
#ifdef F_529
F_530 ( V_2 ) ;
#endif
return 0 ;
V_1132:
F_44 ( V_2 ) ;
F_364 ( V_2 ) ;
V_1095:
F_531 ( V_2 ) ;
V_2 -> V_115 &= ~ V_575 ;
F_532 ( V_8 -> V_373 ) ;
V_1075:
F_533 ( V_18 ) ;
V_1070:
F_534 ( V_36 ,
F_506 ( V_36 , V_1068 ) ) ;
V_1069:
V_1067:
F_365 ( V_36 ) ;
return V_356 ;
}
static void T_16 F_535 ( struct V_620 * V_36 )
{
struct V_1 * V_2 = F_350 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
#ifdef F_529
F_536 ( V_2 ) ;
#endif
F_208 ( V_3 , & V_2 -> V_4 ) ;
F_537 ( & V_2 -> V_6 ) ;
#ifdef F_69
F_538 ( V_2 ) ;
#endif
#ifdef F_192
if ( V_2 -> V_100 & V_151 ) {
V_2 -> V_100 &= ~ V_151 ;
F_101 ( & V_36 -> V_37 ) ;
F_45 ( & V_2 -> V_8 , V_152 , 1 ) ;
}
#endif
#ifdef F_527
F_539 ( V_2 ) ;
#endif
F_469 ( V_18 ) ;
if ( V_18 -> V_862 == V_863 )
F_403 ( V_18 ) ;
F_531 ( V_2 ) ;
F_364 ( V_2 ) ;
F_44 ( V_2 ) ;
#ifdef F_540
F_199 ( V_2 -> V_99 ) ;
F_199 ( V_2 -> V_535 ) ;
#endif
F_532 ( V_2 -> V_8 . V_373 ) ;
F_534 ( V_36 , F_506 ( V_36 ,
V_1068 ) ) ;
F_523 ( L_146 ) ;
F_533 ( V_18 ) ;
F_541 ( V_36 ) ;
F_365 ( V_36 ) ;
}
static T_17 F_542 ( struct V_620 * V_36 ,
T_18 V_4 )
{
struct V_1 * V_2 = F_350 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
#ifdef F_324
struct V_620 * V_1135 , * V_1136 ;
T_1 V_1137 , V_1138 , V_1139 , V_1140 ;
int V_864 , V_1141 ;
T_5 V_1142 , V_1143 ;
if ( V_2 -> V_8 . V_72 . type == V_73 ||
V_2 -> V_274 == 0 )
goto V_1144;
V_1135 = V_36 -> V_1041 -> V_1145 ;
while ( V_1135 && ( F_543 ( V_1135 ) != V_1146 ) )
V_1135 = V_1135 -> V_1041 -> V_1145 ;
if ( ! V_1135 )
goto V_1144;
V_1141 = F_544 ( V_1135 , V_1147 ) ;
if ( ! V_1141 )
goto V_1144;
F_545 ( V_1135 , V_1141 + V_1148 , & V_1137 ) ;
F_545 ( V_1135 , V_1141 + V_1148 + 4 , & V_1138 ) ;
F_545 ( V_1135 , V_1141 + V_1148 + 8 , & V_1139 ) ;
F_545 ( V_1135 , V_1141 + V_1148 + 12 , & V_1140 ) ;
V_1142 = V_1138 >> 16 ;
if ( ! ( V_1142 & 0x0080 ) )
goto V_1144;
V_1143 = V_1142 & 0x01 ;
if ( ( V_1143 & 1 ) == ( V_36 -> V_1149 & 1 ) ) {
unsigned int V_307 ;
V_864 = ( V_1142 & 0x7F ) >> 1 ;
F_302 ( L_147 , V_864 ) ;
F_302 ( L_148
L_149 ,
V_1137 , V_1138 , V_1139 , V_1140 ) ;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
V_307 = V_1150 ;
break;
case V_76 :
V_307 = V_1151 ;
break;
default:
V_307 = 0 ;
break;
}
V_1136 = F_546 ( V_1152 , V_307 , NULL ) ;
while ( V_1136 ) {
if ( V_1136 -> V_1149 == ( V_1142 & 0xFF ) )
break;
V_1136 = F_546 ( V_1152 ,
V_307 , V_1136 ) ;
}
if ( V_1136 ) {
F_302 ( L_150 , V_864 ) ;
F_547 ( V_1136 , 0xA8 , 0x00008000 ) ;
}
F_548 ( V_36 ) ;
}
V_2 -> V_1153 ++ ;
return V_1154 ;
V_1144:
#endif
F_363 ( V_18 ) ;
if ( V_4 == V_1155 )
return V_1156 ;
if ( F_31 ( V_18 ) )
F_298 ( V_2 ) ;
F_365 ( V_36 ) ;
return V_1157 ;
}
static T_17 F_549 ( struct V_620 * V_36 )
{
struct V_1 * V_2 = F_350 ( V_36 ) ;
T_17 V_1158 ;
int V_356 ;
if ( F_354 ( V_36 ) ) {
F_77 ( V_135 , L_151 ) ;
V_1158 = V_1156 ;
} else {
F_355 ( V_36 ) ;
F_352 ( V_36 ) ;
F_353 ( V_36 ) ;
F_356 ( V_36 , false ) ;
F_301 ( V_2 ) ;
F_45 ( & V_2 -> V_8 , V_688 , ~ 0 ) ;
V_1158 = V_1154 ;
}
V_356 = F_548 ( V_36 ) ;
if ( V_356 ) {
F_302 ( L_152
L_153 , V_356 ) ;
}
return V_1158 ;
}
static void F_550 ( struct V_620 * V_36 )
{
struct V_1 * V_2 = F_350 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
#ifdef F_324
if ( V_2 -> V_1153 ) {
F_79 ( V_133 , L_154 ) ;
V_2 -> V_1153 -- ;
return;
}
#endif
if ( F_31 ( V_18 ) )
F_300 ( V_2 ) ;
F_360 ( V_18 ) ;
}
static int T_19 F_551 ( void )
{
int V_114 ;
F_25 ( L_155 , V_1159 , V_1160 ) ;
F_25 ( L_144 , V_1161 ) ;
#ifdef F_529
F_552 () ;
#endif
#ifdef F_192
F_553 ( & V_1162 ) ;
#endif
V_114 = F_554 ( & V_1163 ) ;
return V_114 ;
}
static void T_20 F_555 ( void )
{
#ifdef F_192
F_556 ( & V_1162 ) ;
#endif
F_557 ( & V_1163 ) ;
#ifdef F_529
F_558 () ;
#endif
F_559 () ;
}
static int F_560 ( struct V_1164 * V_1165 , unsigned long V_155 ,
void * V_439 )
{
int V_1166 ;
V_1166 = F_561 ( & V_1163 . V_1167 , NULL , & V_155 ,
F_98 ) ;
return V_1166 ? V_1168 : V_1169 ;
}
