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
F_33 ( V_23 , V_46 ) != 0 )
F_38 ( V_54 , L_26 ,
V_55 , 16 , 1 ,
F_39 ( F_32 ( V_23 ,
V_45 ) ) ,
F_33 ( V_23 , V_46 ) ,
true ) ;
}
}
V_49:
F_30 ( & V_2 -> V_36 -> V_37 , L_27 ) ;
F_25 ( L_28 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_56 ; V_19 ++ ) {
V_30 = V_2 -> V_30 [ V_19 ] ;
F_25 ( L_29 ,
V_19 , V_30 -> V_44 , V_30 -> V_43 ) ;
}
if ( ! F_40 ( V_2 ) )
goto exit;
F_30 ( & V_2 -> V_36 -> V_37 , L_30 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_56 ; V_19 ++ ) {
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
V_32 = F_41 ( V_30 , V_11 ) ;
V_29 = (struct V_26 * ) V_32 ;
V_35 = F_42 ( V_32 -> V_57 . V_58 . V_59 ) ;
if ( V_35 & V_60 ) {
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
if ( F_37 ( V_2 ) ) {
F_38 ( V_54 , L_26 ,
V_55 , 16 , 1 ,
F_39 ( V_34 -> V_45 ) ,
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
T_1 V_61 ;
V_61 = F_11 ( & V_2 -> V_8 , V_62 ) ;
F_45 ( & V_2 -> V_8 , V_62 ,
V_61 & ~ V_63 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
T_1 V_61 ;
V_61 = F_11 ( & V_2 -> V_8 , V_62 ) ;
F_45 ( & V_2 -> V_8 , V_62 ,
V_61 | V_63 ) ;
}
static void F_47 ( struct V_1 * V_2 , T_3 V_64 ,
T_4 V_65 , T_4 V_66 )
{
T_1 V_67 , V_68 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_66 |= V_71 ;
if ( V_64 == - 1 )
V_64 = 0 ;
V_68 = ( ( ( V_64 * 64 ) + V_65 ) >> 2 ) & 0x1F ;
V_67 = F_11 ( V_8 , F_48 ( V_68 ) ) ;
V_67 &= ~ ( 0xFF << ( 8 * ( V_65 & 0x3 ) ) ) ;
V_67 |= ( V_66 << ( 8 * ( V_65 & 0x3 ) ) ) ;
F_45 ( V_8 , F_48 ( V_68 ) , V_67 ) ;
break;
case V_72 :
case V_73 :
if ( V_64 == - 1 ) {
V_66 |= V_71 ;
V_68 = ( ( V_65 & 1 ) * 8 ) ;
V_67 = F_11 ( & V_2 -> V_8 , V_74 ) ;
V_67 &= ~ ( 0xFF << V_68 ) ;
V_67 |= ( V_66 << V_68 ) ;
F_45 ( & V_2 -> V_8 , V_74 , V_67 ) ;
break;
} else {
V_66 |= V_71 ;
V_68 = ( ( 16 * ( V_65 & 1 ) ) + ( 8 * V_64 ) ) ;
V_67 = F_11 ( V_8 , F_48 ( V_65 >> 1 ) ) ;
V_67 &= ~ ( 0xFF << V_68 ) ;
V_67 |= ( V_66 << V_68 ) ;
F_45 ( V_8 , F_48 ( V_65 >> 1 ) , V_67 ) ;
break;
}
default:
break;
}
}
static inline void F_49 ( struct V_1 * V_2 ,
T_2 V_75 )
{
T_1 V_76 ;
switch ( V_2 -> V_8 . V_69 . type ) {
case V_70 :
V_76 = ( V_77 & V_75 ) ;
F_45 ( & V_2 -> V_8 , V_78 , V_76 ) ;
break;
case V_72 :
case V_73 :
V_76 = ( V_75 & 0xFFFFFFFF ) ;
F_45 ( & V_2 -> V_8 , F_50 ( 0 ) , V_76 ) ;
V_76 = ( V_75 >> 32 ) ;
F_45 ( & V_2 -> V_8 , F_50 ( 1 ) , V_76 ) ;
break;
default:
break;
}
}
void F_51 ( struct V_20 * V_79 ,
struct V_22 * V_23 )
{
if ( V_23 -> V_53 ) {
F_52 ( V_23 -> V_53 ) ;
if ( F_33 ( V_23 , V_46 ) )
F_53 ( V_79 -> V_37 ,
F_32 ( V_23 , V_45 ) ,
F_33 ( V_23 , V_46 ) ,
V_80 ) ;
} else if ( F_33 ( V_23 , V_46 ) ) {
F_54 ( V_79 -> V_37 ,
F_32 ( V_23 , V_45 ) ,
F_33 ( V_23 , V_46 ) ,
V_80 ) ;
}
V_23 -> V_47 = NULL ;
V_23 -> V_53 = NULL ;
F_55 ( V_23 , V_46 , 0 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_81 * V_82 = & V_2 -> V_83 ;
int V_11 ;
T_1 V_84 ;
if ( ( V_8 -> V_85 . V_86 != V_87 ) &&
( V_8 -> V_85 . V_86 != V_88 ) )
return;
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_84 = F_11 ( V_8 , V_89 ) ;
break;
default:
V_84 = F_11 ( V_8 , V_90 ) ;
}
V_82 -> V_91 += V_84 ;
if ( ! V_84 )
return;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_8 ( V_92 ,
& V_2 -> V_21 [ V_11 ] -> V_4 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_81 * V_82 = & V_2 -> V_83 ;
T_1 V_93 [ 8 ] = { 0 } ;
int V_11 ;
bool V_94 = V_2 -> V_95 . V_96 ;
if ( V_2 -> V_97 )
V_94 |= ! ! ( V_2 -> V_97 -> V_94 ) ;
if ( ! ( V_2 -> V_98 & V_99 ) || ! V_94 ) {
F_56 ( V_2 ) ;
return;
}
for ( V_11 = 0 ; V_11 < V_100 ; V_11 ++ ) {
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_93 [ V_11 ] = F_11 ( V_8 , F_58 ( V_11 ) ) ;
break;
default:
V_93 [ V_11 ] = F_11 ( V_8 , F_59 ( V_11 ) ) ;
}
V_82 -> V_101 [ V_11 ] += V_93 [ V_11 ] ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_21 = V_2 -> V_21 [ V_11 ] ;
T_4 V_102 = V_21 -> V_103 ;
if ( V_93 [ V_102 ] )
F_8 ( V_92 , & V_21 -> V_4 ) ;
}
}
static T_2 F_60 ( struct V_20 * V_79 )
{
return V_79 -> V_83 . V_104 ;
}
static T_2 F_61 ( struct V_20 * V_79 )
{
struct V_1 * V_2 = F_62 ( V_79 -> V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_105 = F_11 ( V_8 , F_22 ( V_79 -> V_106 ) ) ;
T_1 V_107 = F_11 ( V_8 , F_23 ( V_79 -> V_106 ) ) ;
if ( V_105 != V_107 )
return ( V_105 < V_107 ) ?
V_107 - V_105 : ( V_107 + V_79 -> V_52 - V_105 ) ;
return 0 ;
}
static inline bool F_63 ( struct V_20 * V_21 )
{
T_1 V_108 = F_60 ( V_21 ) ;
T_1 V_109 = V_21 -> V_110 . V_109 ;
T_1 V_111 = F_61 ( V_21 ) ;
bool V_112 = false ;
F_64 ( V_21 ) ;
if ( ( V_109 == V_108 ) && V_111 ) {
V_112 = F_3 ( V_92 ,
& V_21 -> V_4 ) ;
} else {
V_21 -> V_110 . V_109 = V_108 ;
F_8 ( V_92 , & V_21 -> V_4 ) ;
}
return V_112 ;
}
static void F_65 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_113 |= V_114 ;
F_1 ( V_2 ) ;
}
}
static bool F_66 ( struct V_115 * V_116 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = V_116 -> V_2 ;
struct V_22 * V_23 ;
union V_24 * V_25 ;
unsigned int V_117 = 0 , V_118 = 0 ;
unsigned int V_119 = V_116 -> V_120 . V_121 ;
unsigned int V_11 = V_21 -> V_43 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return true ;
V_23 = & V_21 -> V_42 [ V_11 ] ;
V_25 = F_35 ( V_21 , V_11 ) ;
V_11 -= V_21 -> V_52 ;
do {
union V_24 * V_122 = V_23 -> V_47 ;
if ( ! V_122 )
break;
F_67 () ;
if ( ! ( V_122 -> V_57 . V_123 & F_68 ( V_124 ) ) )
break;
V_23 -> V_47 = NULL ;
V_117 += V_23 -> V_125 ;
V_118 += V_23 -> V_126 ;
#ifdef F_69
if ( F_70 ( V_23 -> V_127 &
V_128 ) )
F_71 ( V_116 ,
V_23 -> V_53 ) ;
#endif
F_52 ( V_23 -> V_53 ) ;
F_53 ( V_21 -> V_37 ,
F_32 ( V_23 , V_45 ) ,
F_33 ( V_23 , V_46 ) ,
V_80 ) ;
V_23 -> V_53 = NULL ;
F_55 ( V_23 , V_46 , 0 ) ;
while ( V_25 != V_122 ) {
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
V_80 ) ;
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
V_119 -- ;
} while ( F_73 ( V_119 ) );
V_11 += V_21 -> V_52 ;
V_21 -> V_43 = V_11 ;
F_74 ( & V_21 -> V_129 ) ;
V_21 -> V_83 . V_130 += V_117 ;
V_21 -> V_83 . V_104 += V_118 ;
F_75 ( & V_21 -> V_129 ) ;
V_116 -> V_120 . V_117 += V_117 ;
V_116 -> V_120 . V_118 += V_118 ;
if ( F_76 ( V_21 ) && F_63 ( V_21 ) ) {
struct V_7 * V_8 = & V_2 -> V_8 ;
F_77 ( V_131 , L_42
L_43
L_44
L_45
L_46
L_47
L_48
L_49 ,
V_21 -> V_50 ,
F_11 ( V_8 , F_22 ( V_21 -> V_106 ) ) ,
F_11 ( V_8 , F_23 ( V_21 -> V_106 ) ) ,
V_21 -> V_44 , V_11 ,
V_21 -> V_42 [ V_11 ] . V_48 , V_132 ) ;
F_78 ( V_21 -> V_18 , V_21 -> V_50 ) ;
F_79 ( V_133 ,
L_50 ,
V_2 -> V_134 + 1 , V_21 -> V_50 ) ;
F_65 ( V_2 ) ;
return true ;
}
F_80 ( F_81 ( V_21 ) ,
V_118 , V_117 ) ;
#define F_82 (DESC_NEEDED * 2)
if ( F_70 ( V_118 && F_83 ( V_21 -> V_18 ) &&
( F_84 ( V_21 ) >= F_82 ) ) ) {
F_85 () ;
if ( F_86 ( V_21 -> V_18 ,
V_21 -> V_50 )
&& ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_87 ( V_21 -> V_18 ,
V_21 -> V_50 ) ;
++ V_21 -> V_110 . V_135 ;
}
}
return ! ! V_119 ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
int V_136 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_137 = F_89 ( V_21 -> V_37 , V_136 ) ;
T_5 V_138 ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_138 = F_90 ( V_21 -> V_106 ) ;
break;
case V_72 :
case V_73 :
V_138 = F_91 ( V_21 -> V_106 ) ;
V_137 <<= V_139 ;
break;
default:
return;
}
V_137 |= V_140 |
V_141 |
V_142 ;
F_45 ( V_8 , V_138 , V_137 ) ;
}
static void F_92 ( struct V_1 * V_2 ,
struct V_20 * V_30 ,
int V_136 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_143 = F_89 ( V_30 -> V_37 , V_136 ) ;
T_4 V_106 = V_30 -> V_106 ;
switch ( V_8 -> V_69 . type ) {
case V_72 :
case V_73 :
V_143 <<= V_144 ;
break;
default:
break;
}
V_143 |= V_145 |
V_146 |
V_147 ;
F_45 ( V_8 , F_12 ( V_106 ) , V_143 ) ;
}
static void F_93 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = V_116 -> V_2 ;
struct V_20 * V_79 ;
int V_136 = F_94 () ;
if ( V_116 -> V_136 == V_136 )
goto V_148;
F_95 (ring, q_vector->tx)
F_88 ( V_2 , V_79 , V_136 ) ;
F_95 (ring, q_vector->rx)
F_92 ( V_2 , V_79 , V_136 ) ;
V_116 -> V_136 = V_136 ;
V_148:
F_96 () ;
}
static void F_97 ( struct V_1 * V_2 )
{
int V_149 ;
int V_11 ;
if ( ! ( V_2 -> V_98 & V_150 ) )
return;
F_45 ( & V_2 -> V_8 , V_151 , 2 ) ;
if ( V_2 -> V_98 & V_152 )
V_149 = V_2 -> V_153 - V_154 ;
else
V_149 = 1 ;
for ( V_11 = 0 ; V_11 < V_149 ; V_11 ++ ) {
V_2 -> V_116 [ V_11 ] -> V_136 = - 1 ;
F_93 ( V_2 -> V_116 [ V_11 ] ) ;
}
}
static int F_98 ( struct V_155 * V_37 , void * V_84 )
{
struct V_1 * V_2 = F_99 ( V_37 ) ;
unsigned long V_156 = * ( unsigned long * ) V_84 ;
if ( ! ( V_2 -> V_98 & V_157 ) )
return 0 ;
switch ( V_156 ) {
case V_158 :
if ( V_2 -> V_98 & V_150 )
break;
if ( F_100 ( V_37 ) == 0 ) {
V_2 -> V_98 |= V_150 ;
F_97 ( V_2 ) ;
break;
}
case V_159 :
if ( V_2 -> V_98 & V_150 ) {
F_101 ( V_37 ) ;
V_2 -> V_98 &= ~ V_150 ;
F_45 ( & V_2 -> V_8 , V_151 , 1 ) ;
}
break;
}
return 0 ;
}
static inline void F_102 ( struct V_20 * V_79 ,
union V_31 * V_32 ,
struct V_160 * V_53 )
{
if ( V_79 -> V_18 -> V_161 & V_162 )
V_53 -> V_163 = F_42 ( V_32 -> V_57 . V_164 . V_165 . V_166 ) ;
}
static inline bool F_103 ( struct V_20 * V_79 ,
union V_31 * V_32 )
{
T_6 V_167 = V_32 -> V_57 . V_164 . V_168 . V_169 . V_167 ;
return F_2 ( V_170 , & V_79 -> V_4 ) &&
( ( V_167 & F_104 ( V_171 ) ) ==
( F_104 ( V_172 <<
V_173 ) ) ) ;
}
static inline void F_105 ( struct V_20 * V_79 ,
union V_31 * V_32 ,
struct V_160 * V_53 )
{
F_106 ( V_53 ) ;
if ( ! ( V_79 -> V_18 -> V_161 & V_174 ) )
return;
if ( F_107 ( V_32 , V_175 ) &&
F_107 ( V_32 , V_176 ) ) {
V_79 -> V_177 . V_178 ++ ;
return;
}
if ( ! F_107 ( V_32 , V_179 ) )
return;
if ( F_107 ( V_32 , V_180 ) ) {
T_6 V_167 = V_32 -> V_57 . V_164 . V_168 . V_169 . V_167 ;
if ( ( V_167 & F_104 ( V_181 ) ) &&
F_2 ( V_182 , & V_79 -> V_4 ) )
return;
V_79 -> V_177 . V_178 ++ ;
return;
}
V_53 -> V_183 = V_184 ;
}
static inline void F_108 ( struct V_20 * V_30 , T_1 V_185 )
{
V_30 -> V_44 = V_185 ;
V_30 -> V_186 = V_185 ;
F_109 () ;
F_110 ( V_185 , V_30 -> V_107 ) ;
}
static bool F_111 ( struct V_20 * V_30 ,
struct V_33 * V_187 )
{
struct V_188 * V_188 = V_187 -> V_188 ;
T_7 V_45 = V_187 -> V_45 ;
if ( F_73 ( V_45 ) )
return true ;
if ( F_73 ( ! V_188 ) ) {
V_188 = F_112 ( V_189 | V_190 | V_191 ,
F_113 ( V_30 ) ) ;
if ( F_70 ( ! V_188 ) ) {
V_30 -> V_177 . V_192 ++ ;
return false ;
}
V_187 -> V_188 = V_188 ;
}
V_45 = F_114 ( V_30 -> V_37 , V_188 , 0 ,
F_115 ( V_30 ) , V_193 ) ;
if ( F_116 ( V_30 -> V_37 , V_45 ) ) {
F_117 ( V_188 , F_113 ( V_30 ) ) ;
V_187 -> V_188 = NULL ;
V_30 -> V_177 . V_192 ++ ;
return false ;
}
V_187 -> V_45 = V_45 ;
V_187 -> V_194 ^= F_43 ( V_30 ) ;
return true ;
}
void F_118 ( struct V_20 * V_30 , T_5 V_195 )
{
union V_31 * V_32 ;
struct V_33 * V_187 ;
T_5 V_11 = V_30 -> V_44 ;
if ( ! V_195 )
return;
V_32 = F_41 ( V_30 , V_11 ) ;
V_187 = & V_30 -> V_34 [ V_11 ] ;
V_11 -= V_30 -> V_52 ;
do {
if ( ! F_111 ( V_30 , V_187 ) )
break;
V_32 -> V_196 . V_197 = F_119 ( V_187 -> V_45 + V_187 -> V_194 ) ;
V_32 ++ ;
V_187 ++ ;
V_11 ++ ;
if ( F_70 ( ! V_11 ) ) {
V_32 = F_41 ( V_30 , 0 ) ;
V_187 = V_30 -> V_34 ;
V_11 -= V_30 -> V_52 ;
}
V_32 -> V_196 . V_198 = 0 ;
V_195 -- ;
} while ( V_195 );
V_11 += V_30 -> V_52 ;
if ( V_30 -> V_44 != V_11 )
F_108 ( V_30 , V_11 ) ;
}
static unsigned int F_120 ( unsigned char * V_84 ,
unsigned int V_199 )
{
union {
unsigned char * V_200 ;
struct V_201 * V_202 ;
struct V_203 * V_204 ;
struct V_205 * V_206 ;
} V_207 ;
T_8 V_208 ;
T_4 V_209 = 0 ;
T_4 V_210 ;
if ( V_199 < V_211 )
return V_199 ;
V_207 . V_200 = V_84 ;
V_208 = V_207 . V_202 -> V_212 ;
V_207 . V_200 += V_211 ;
if ( V_208 == F_121 ( V_213 ) ) {
if ( ( V_207 . V_200 - V_84 ) > ( V_199 - V_214 ) )
return V_199 ;
V_208 = V_207 . V_204 -> V_215 ;
V_207 . V_200 += V_214 ;
}
if ( V_208 == F_121 ( V_216 ) ) {
if ( ( V_207 . V_200 - V_84 ) > ( V_199 - sizeof( struct V_205 ) ) )
return V_199 ;
V_210 = ( V_207 . V_200 [ 0 ] & 0x0F ) << 2 ;
if ( V_210 < sizeof( struct V_205 ) )
return V_207 . V_200 - V_84 ;
V_209 = V_207 . V_206 -> V_208 ;
V_207 . V_200 += V_210 ;
#ifdef F_122
} else if ( V_208 == F_121 ( V_217 ) ) {
if ( ( V_207 . V_200 - V_84 ) > ( V_199 - V_218 ) )
return V_199 ;
V_207 . V_200 += V_218 ;
#endif
} else {
return V_207 . V_200 - V_84 ;
}
if ( V_209 == V_219 ) {
if ( ( V_207 . V_200 - V_84 ) > ( V_199 - sizeof( struct V_220 ) ) )
return V_199 ;
V_210 = ( V_207 . V_200 [ 12 ] & 0xF0 ) >> 2 ;
if ( V_210 < sizeof( struct V_220 ) )
return V_207 . V_200 - V_84 ;
V_207 . V_200 += V_210 ;
}
if ( ( V_207 . V_200 - V_84 ) < V_199 )
return V_207 . V_200 - V_84 ;
else
return V_199 ;
}
static void F_123 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_160 * V_53 )
{
T_9 V_221 ;
T_1 V_222 ;
if ( ! F_124 ( V_30 ) )
return;
V_221 = V_32 -> V_57 . V_164 . V_168 . V_84 &
F_68 ( V_223 ) ;
if ( ! V_221 )
return;
V_222 = F_42 ( V_221 ) ;
V_222 >>= V_224 ;
F_125 ( V_53 ) -> V_225 += V_222 - 1 ;
}
static void F_126 ( struct V_20 * V_79 ,
struct V_160 * V_53 )
{
T_5 V_226 = F_127 ( V_53 ) ;
F_128 ( V_53 ) -> V_227 = F_129 ( ( V_53 -> V_46 - V_226 ) ,
F_125 ( V_53 ) -> V_225 ) ;
}
static void F_130 ( struct V_20 * V_30 ,
struct V_160 * V_53 )
{
if ( ! F_125 ( V_53 ) -> V_225 )
return;
V_30 -> V_177 . V_228 += F_125 ( V_53 ) -> V_225 ;
V_30 -> V_177 . V_229 ++ ;
F_126 ( V_30 , V_53 ) ;
F_125 ( V_53 ) -> V_225 = 0 ;
}
static void F_131 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_160 * V_53 )
{
struct V_17 * V_37 = V_30 -> V_18 ;
F_130 ( V_30 , V_53 ) ;
F_102 ( V_30 , V_32 , V_53 ) ;
F_105 ( V_30 , V_32 , V_53 ) ;
#ifdef F_69
if ( F_107 ( V_32 , V_230 ) )
F_132 ( V_30 -> V_116 , V_53 ) ;
#endif
if ( ( V_37 -> V_161 & V_231 ) &&
F_107 ( V_32 , V_232 ) ) {
T_5 V_233 = F_133 ( V_32 -> V_57 . V_58 . V_204 ) ;
F_134 ( V_53 , V_233 ) ;
}
F_135 ( V_53 , V_30 -> V_50 ) ;
V_53 -> V_208 = F_136 ( V_53 , V_37 ) ;
}
static void F_137 ( struct V_115 * V_116 ,
struct V_160 * V_53 )
{
struct V_1 * V_2 = V_116 -> V_2 ;
if ( ! ( V_2 -> V_98 & V_234 ) )
F_138 ( & V_116 -> V_235 , V_53 ) ;
else
F_139 ( V_53 ) ;
}
static bool F_140 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_160 * V_53 )
{
T_1 V_236 = V_30 -> V_43 + 1 ;
V_236 = ( V_236 < V_30 -> V_52 ) ? V_236 : 0 ;
V_30 -> V_43 = V_236 ;
F_72 ( F_41 ( V_30 , V_236 ) ) ;
if ( F_73 ( F_107 ( V_32 , V_237 ) ) )
return false ;
if ( F_125 ( V_53 ) -> V_225 ) {
V_236 = F_42 ( V_32 -> V_57 . V_58 . V_59 ) ;
V_236 &= V_238 ;
V_236 >>= V_239 ;
}
V_30 -> V_34 [ V_236 ] . V_53 = V_53 ;
V_30 -> V_177 . V_240 ++ ;
return true ;
}
static bool F_141 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_160 * V_53 )
{
struct V_241 * V_242 = & F_128 ( V_53 ) -> V_243 [ 0 ] ;
struct V_17 * V_18 = V_30 -> V_18 ;
unsigned char * V_244 ;
unsigned int V_245 ;
if ( F_70 ( F_125 ( V_53 ) -> V_246 ) ) {
F_54 ( V_30 -> V_37 , F_125 ( V_53 ) -> V_45 ,
F_115 ( V_30 ) , V_193 ) ;
F_125 ( V_53 ) -> V_246 = false ;
} else {
F_142 ( V_30 -> V_37 ,
F_125 ( V_53 ) -> V_45 ,
V_242 -> V_194 ,
F_43 ( V_30 ) ,
V_193 ) ;
}
F_125 ( V_53 ) -> V_45 = 0 ;
if ( F_70 ( F_107 ( V_32 ,
V_247 ) &&
! ( V_18 -> V_161 & V_248 ) ) ) {
F_52 ( V_53 ) ;
return true ;
}
V_244 = F_143 ( V_242 ) ;
V_245 = F_144 ( V_242 ) ;
if ( V_245 > 256 )
V_245 = F_120 ( V_244 , V_245 ) ;
F_145 ( V_53 , V_244 , F_146 ( V_245 , sizeof( long ) ) ) ;
F_147 ( V_242 , V_245 ) ;
V_242 -> V_194 += V_245 ;
V_53 -> V_249 -= V_245 ;
V_53 -> V_107 += V_245 ;
if ( F_144 ( V_242 ) == 0 ) {
F_6 ( F_128 ( V_53 ) -> V_250 != 1 ) ;
F_128 ( V_53 ) -> V_250 = 0 ;
F_148 ( V_242 ) ;
V_53 -> V_251 -= F_43 ( V_30 ) ;
}
#ifdef F_122
if ( F_103 ( V_30 , V_32 ) )
return false ;
#endif
if ( F_70 ( V_53 -> V_46 < 60 ) ) {
int V_252 = 60 - V_53 -> V_46 ;
if ( F_149 ( V_53 , V_252 ) )
return true ;
F_150 ( V_53 , V_252 ) ;
}
return false ;
}
static inline bool F_151 ( struct V_33 * V_253 )
{
struct V_188 * V_188 = V_253 -> V_188 ;
return F_73 ( F_152 ( V_188 ) == 1 ) &&
F_73 ( F_153 ( V_188 ) == F_154 () ) ;
}
static void F_155 ( struct V_20 * V_30 ,
struct V_33 * V_254 )
{
struct V_33 * V_255 ;
T_5 V_256 = V_30 -> V_186 ;
T_5 V_257 = F_43 ( V_30 ) ;
V_255 = & V_30 -> V_34 [ V_256 ] ;
V_256 ++ ;
V_30 -> V_186 = ( V_256 < V_30 -> V_52 ) ? V_256 : 0 ;
V_255 -> V_188 = V_254 -> V_188 ;
V_255 -> V_45 = V_254 -> V_45 ;
V_255 -> V_194 = V_254 -> V_194 ^ V_257 ;
F_156 ( V_30 -> V_37 , V_255 -> V_45 ,
V_255 -> V_194 , V_257 ,
V_193 ) ;
F_157 ( V_255 -> V_188 ) ;
}
static void F_158 ( struct V_20 * V_30 ,
struct V_33 * V_253 ,
struct V_160 * V_53 , int V_258 )
{
F_159 ( V_53 , F_128 ( V_53 ) -> V_250 ,
V_253 -> V_188 , V_253 -> V_194 ,
V_258 ) ;
V_53 -> V_46 += V_258 ;
V_53 -> V_249 += V_258 ;
V_53 -> V_251 += F_43 ( V_30 ) ;
}
static bool F_160 ( struct V_115 * V_116 ,
struct V_20 * V_30 ,
int V_119 )
{
unsigned int V_259 = 0 , V_260 = 0 ;
#ifdef F_122
struct V_1 * V_2 = V_116 -> V_2 ;
int V_261 = 0 ;
#endif
T_5 V_195 = F_84 ( V_30 ) ;
do {
struct V_33 * V_253 ;
union V_31 * V_32 ;
struct V_160 * V_53 ;
struct V_188 * V_188 ;
T_5 V_236 ;
if ( V_195 >= V_262 ) {
F_118 ( V_30 , V_195 ) ;
V_195 = 0 ;
}
V_236 = V_30 -> V_43 ;
V_32 = F_41 ( V_30 , V_236 ) ;
V_253 = & V_30 -> V_34 [ V_236 ] ;
if ( ! F_107 ( V_32 , V_60 ) )
break;
F_67 () ;
V_188 = V_253 -> V_188 ;
F_161 ( V_188 ) ;
V_53 = V_253 -> V_53 ;
if ( F_73 ( ! V_53 ) ) {
void * V_263 = F_162 ( V_188 ) +
V_253 -> V_194 ;
F_72 ( V_263 ) ;
#if V_264 < 128
F_72 ( V_263 + V_264 ) ;
#endif
V_53 = F_163 ( V_30 -> V_18 ,
V_265 ) ;
if ( F_70 ( ! V_53 ) ) {
V_30 -> V_177 . V_266 ++ ;
break;
}
F_161 ( V_53 -> V_84 ) ;
F_125 ( V_53 ) -> V_45 = V_253 -> V_45 ;
} else {
F_142 ( V_30 -> V_37 ,
V_253 -> V_45 ,
V_253 -> V_194 ,
F_43 ( V_30 ) ,
V_193 ) ;
}
F_158 ( V_30 , V_253 , V_53 ,
F_133 ( V_32 -> V_57 . V_58 . V_267 ) ) ;
if ( F_151 ( V_253 ) ) {
F_155 ( V_30 , V_253 ) ;
} else if ( F_125 ( V_53 ) -> V_45 == V_253 -> V_45 ) {
F_125 ( V_53 ) -> V_246 = true ;
} else {
F_54 ( V_30 -> V_37 , V_253 -> V_45 ,
F_115 ( V_30 ) ,
V_193 ) ;
}
V_253 -> V_53 = NULL ;
V_253 -> V_45 = 0 ;
V_253 -> V_188 = NULL ;
F_123 ( V_30 , V_32 , V_53 ) ;
V_195 ++ ;
if ( F_140 ( V_30 , V_32 , V_53 ) )
continue;
if ( F_141 ( V_30 , V_32 , V_53 ) )
continue;
V_259 += V_53 -> V_46 ;
V_260 ++ ;
F_131 ( V_30 , V_32 , V_53 ) ;
#ifdef F_122
if ( F_103 ( V_30 , V_32 ) ) {
V_261 = F_164 ( V_2 , V_32 , V_53 ) ;
if ( ! V_261 ) {
F_52 ( V_53 ) ;
continue;
}
}
#endif
F_137 ( V_116 , V_53 ) ;
V_119 -- ;
} while ( F_73 ( V_119 ) );
#ifdef F_122
if ( V_261 > 0 ) {
unsigned int V_268 ;
V_268 = V_30 -> V_18 -> V_269 - sizeof( struct V_270 ) -
sizeof( struct V_271 ) -
sizeof( struct V_272 ) ;
if ( V_268 > 512 )
V_268 &= ~ 511 ;
V_259 += V_261 ;
V_260 += F_129 ( V_261 , V_268 ) ;
}
#endif
F_74 ( & V_30 -> V_129 ) ;
V_30 -> V_83 . V_104 += V_260 ;
V_30 -> V_83 . V_130 += V_259 ;
F_75 ( & V_30 -> V_129 ) ;
V_116 -> V_273 . V_118 += V_260 ;
V_116 -> V_273 . V_117 += V_259 ;
if ( V_195 )
F_118 ( V_30 , V_195 ) ;
return ! ! V_119 ;
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_115 * V_116 ;
int V_274 , V_275 ;
T_1 V_76 ;
V_274 = V_2 -> V_153 - V_154 ;
if ( V_2 -> V_276 > 32 ) {
T_1 V_277 = ( 1 << ( V_2 -> V_276 - 32 ) ) - 1 ;
F_45 ( & V_2 -> V_8 , V_278 , V_277 ) ;
}
for ( V_275 = 0 ; V_275 < V_274 ; V_275 ++ ) {
struct V_20 * V_79 ;
V_116 = V_2 -> V_116 [ V_275 ] ;
F_95 (ring, q_vector->rx)
F_47 ( V_2 , 0 , V_79 -> V_106 , V_275 ) ;
F_95 (ring, q_vector->tx)
F_47 ( V_2 , 1 , V_79 -> V_106 , V_275 ) ;
if ( V_116 -> V_120 . V_79 && ! V_116 -> V_273 . V_79 ) {
if ( V_2 -> V_279 == 1 )
V_116 -> V_280 = V_281 ;
else
V_116 -> V_280 = V_2 -> V_279 ;
} else {
if ( V_2 -> V_282 == 1 )
V_116 -> V_280 = V_283 ;
else
V_116 -> V_280 = V_2 -> V_282 ;
}
F_166 ( V_116 ) ;
}
switch ( V_2 -> V_8 . V_69 . type ) {
case V_70 :
F_47 ( V_2 , - 1 , V_284 ,
V_275 ) ;
break;
case V_72 :
case V_73 :
F_47 ( V_2 , - 1 , 1 , V_275 ) ;
break;
default:
break;
}
F_45 ( & V_2 -> V_8 , F_167 ( V_275 ) , 1950 ) ;
V_76 = V_285 ;
V_76 &= ~ ( V_286 |
V_287 |
V_288 ) ;
F_45 ( & V_2 -> V_8 , V_289 , V_76 ) ;
}
static void F_168 ( struct V_115 * V_116 ,
struct V_290 * V_291 )
{
int V_130 = V_291 -> V_117 ;
int V_104 = V_291 -> V_118 ;
T_1 V_292 ;
T_2 V_293 ;
T_4 V_294 = V_291 -> V_280 ;
if ( V_104 == 0 )
return;
V_292 = V_116 -> V_280 >> 2 ;
V_293 = V_130 / V_292 ;
switch ( V_294 ) {
case V_295 :
if ( V_293 > 10 )
V_294 = V_296 ;
break;
case V_296 :
if ( V_293 > 20 )
V_294 = V_297 ;
else if ( V_293 <= 10 )
V_294 = V_295 ;
break;
case V_297 :
if ( V_293 <= 20 )
V_294 = V_296 ;
break;
}
V_291 -> V_117 = 0 ;
V_291 -> V_118 = 0 ;
V_291 -> V_280 = V_294 ;
}
void F_166 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = V_116 -> V_2 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_275 = V_116 -> V_275 ;
T_1 V_298 = V_116 -> V_280 & V_299 ;
switch ( V_2 -> V_8 . V_69 . type ) {
case V_70 :
V_298 |= ( V_298 << 16 ) ;
break;
case V_72 :
case V_73 :
V_298 |= V_300 ;
break;
default:
break;
}
F_45 ( V_8 , F_167 ( V_275 ) , V_298 ) ;
}
static void F_169 ( struct V_115 * V_116 )
{
T_1 V_301 = V_116 -> V_280 ;
T_4 V_302 ;
F_168 ( V_116 , & V_116 -> V_120 ) ;
F_168 ( V_116 , & V_116 -> V_273 ) ;
V_302 = F_170 ( V_116 -> V_273 . V_280 , V_116 -> V_120 . V_280 ) ;
switch ( V_302 ) {
case V_295 :
V_301 = V_303 ;
break;
case V_296 :
V_301 = V_283 ;
break;
case V_297 :
V_301 = V_304 ;
break;
default:
break;
}
if ( V_301 != V_116 -> V_280 ) {
V_301 = ( 10 * V_301 * V_116 -> V_280 ) /
( ( 9 * V_301 ) + V_116 -> V_280 ) ;
V_116 -> V_280 = V_301 ;
F_166 ( V_116 ) ;
}
}
static void F_171 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_305 = V_2 -> V_306 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
if ( ! ( V_2 -> V_113 & V_307 ) &&
! ( V_2 -> V_113 & V_308 ) )
return;
V_2 -> V_113 &= ~ V_308 ;
switch ( V_8 -> V_309 ) {
case V_310 :
if ( ! ( V_305 & V_311 ) &&
! ( V_305 & V_312 ) )
return;
if ( ! ( V_305 & V_312 ) && V_8 -> V_69 . V_313 . V_314 ) {
T_1 V_315 ;
bool V_316 = false ;
V_8 -> V_69 . V_313 . V_314 ( V_8 , & V_315 , & V_316 , false ) ;
if ( V_316 )
return;
}
if ( V_8 -> V_317 . V_313 . V_318 ( V_8 ) != V_319 )
return;
break;
default:
if ( ! ( V_305 & V_311 ) )
return;
break;
}
F_172 ( V_131 ,
L_51
L_52
L_53 ) ;
V_2 -> V_306 = 0 ;
}
static void F_173 ( struct V_1 * V_2 , T_1 V_305 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( ( V_2 -> V_98 & V_320 ) &&
( V_305 & V_321 ) ) {
F_172 ( V_133 , L_54 ) ;
F_45 ( V_8 , V_322 , V_321 ) ;
}
}
static void F_174 ( struct V_1 * V_2 , T_1 V_305 )
{
if ( ! ( V_2 -> V_113 & V_307 ) )
return;
switch ( V_2 -> V_8 . V_69 . type ) {
case V_72 :
if ( ( ( V_305 & V_311 ) || ( V_305 & V_312 ) ) &&
( ! F_2 ( V_3 , & V_2 -> V_4 ) ) ) {
V_2 -> V_306 = V_305 ;
V_2 -> V_113 |= V_308 ;
F_1 ( V_2 ) ;
return;
}
return;
case V_73 :
if ( ! ( V_305 & V_323 ) )
return;
break;
default:
return;
}
F_172 ( V_131 ,
L_51
L_52
L_53 ) ;
}
static void F_175 ( struct V_1 * V_2 , T_1 V_305 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( V_305 & V_324 ) {
F_45 ( V_8 , V_322 , V_324 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_113 |= V_325 ;
F_1 ( V_2 ) ;
}
}
if ( V_305 & V_321 ) {
F_45 ( V_8 , V_322 , V_321 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_98 |= V_326 ;
F_1 ( V_2 ) ;
}
}
}
static void F_176 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
V_2 -> V_327 ++ ;
V_2 -> V_98 |= V_328 ;
V_2 -> V_329 = V_132 ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_45 ( V_8 , V_330 , V_331 ) ;
F_177 ( V_8 ) ;
F_1 ( V_2 ) ;
}
}
static inline void F_178 ( struct V_1 * V_2 ,
T_2 V_75 )
{
T_1 V_76 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_76 = ( V_77 & V_75 ) ;
F_45 ( V_8 , V_332 , V_76 ) ;
break;
case V_72 :
case V_73 :
V_76 = ( V_75 & 0xFFFFFFFF ) ;
if ( V_76 )
F_45 ( V_8 , F_179 ( 0 ) , V_76 ) ;
V_76 = ( V_75 >> 32 ) ;
if ( V_76 )
F_45 ( V_8 , F_179 ( 1 ) , V_76 ) ;
break;
default:
break;
}
}
static inline void F_180 ( struct V_1 * V_2 ,
T_2 V_75 )
{
T_1 V_76 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_76 = ( V_77 & V_75 ) ;
F_45 ( V_8 , V_330 , V_76 ) ;
break;
case V_72 :
case V_73 :
V_76 = ( V_75 & 0xFFFFFFFF ) ;
if ( V_76 )
F_45 ( V_8 , F_181 ( 0 ) , V_76 ) ;
V_76 = ( V_75 >> 32 ) ;
if ( V_76 )
F_45 ( V_8 , F_181 ( 1 ) , V_76 ) ;
break;
default:
break;
}
}
static inline void F_182 ( struct V_1 * V_2 , bool V_333 ,
bool V_334 )
{
T_1 V_76 = ( V_285 & ~ V_77 ) ;
if ( V_2 -> V_98 & V_328 )
V_76 &= ~ V_288 ;
if ( V_2 -> V_113 & V_307 )
switch ( V_2 -> V_8 . V_69 . type ) {
case V_72 :
V_76 |= V_335 ;
break;
case V_73 :
V_76 |= V_336 ;
break;
default:
break;
}
if ( V_2 -> V_98 & V_320 )
V_76 |= V_337 ;
switch ( V_2 -> V_8 . V_69 . type ) {
case V_72 :
V_76 |= V_337 ;
V_76 |= V_338 ;
case V_73 :
V_76 |= V_339 ;
V_76 |= V_287 ;
break;
default:
break;
}
if ( ( V_2 -> V_98 & V_340 ) &&
! ( V_2 -> V_113 & V_341 ) )
V_76 |= V_342 ;
F_45 ( & V_2 -> V_8 , V_332 , V_76 ) ;
if ( V_333 )
F_178 ( V_2 , ~ 0 ) ;
if ( V_334 )
F_177 ( & V_2 -> V_8 ) ;
}
static T_10 F_183 ( int V_343 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_305 ;
V_305 = F_11 ( V_8 , V_78 ) ;
F_45 ( V_8 , V_322 , V_305 ) ;
if ( V_305 & V_312 )
F_176 ( V_2 ) ;
if ( V_305 & V_344 )
F_184 ( V_2 ) ;
switch ( V_8 -> V_69 . type ) {
case V_72 :
case V_73 :
if ( V_305 & V_345 )
F_79 ( V_346 , L_55
L_56 ) ;
if ( V_305 & V_347 ) {
int V_348 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_79 = V_2 -> V_21 [ V_11 ] ;
if ( F_185 ( V_349 ,
& V_79 -> V_4 ) )
V_348 ++ ;
}
if ( V_348 ) {
F_45 ( V_8 , V_330 , V_350 ) ;
V_2 -> V_113 |= V_341 ;
F_1 ( V_2 ) ;
}
}
F_175 ( V_2 , V_305 ) ;
F_174 ( V_2 , V_305 ) ;
break;
default:
break;
}
F_173 ( V_2 , V_305 ) ;
#ifdef F_69
F_186 ( V_2 , V_305 ) ;
#endif
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_182 ( V_2 , false , false ) ;
return V_351 ;
}
static T_10 F_187 ( int V_343 , void * V_84 )
{
struct V_115 * V_116 = V_84 ;
if ( V_116 -> V_273 . V_79 || V_116 -> V_120 . V_79 )
F_188 ( & V_116 -> V_235 ) ;
return V_351 ;
}
int F_189 ( struct V_352 * V_235 , int V_119 )
{
struct V_115 * V_116 =
F_190 ( V_235 , struct V_115 , V_235 ) ;
struct V_1 * V_2 = V_116 -> V_2 ;
struct V_20 * V_79 ;
int V_353 ;
bool V_354 = true ;
#ifdef F_191
if ( V_2 -> V_98 & V_150 )
F_93 ( V_116 ) ;
#endif
F_95 (ring, q_vector->tx)
V_354 &= ! ! F_66 ( V_116 , V_79 ) ;
if ( V_116 -> V_273 . V_52 > 1 )
V_353 = F_170 ( V_119 / V_116 -> V_273 . V_52 , 1 ) ;
else
V_353 = V_119 ;
F_95 (ring, q_vector->rx)
V_354 &= F_160 ( V_116 , V_79 ,
V_353 ) ;
if ( ! V_354 )
return V_119 ;
F_192 ( V_235 ) ;
if ( V_2 -> V_282 & 1 )
F_169 ( V_116 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_178 ( V_2 , ( ( T_2 ) 1 << V_116 -> V_275 ) ) ;
return 0 ;
}
static int F_193 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
int V_274 = V_2 -> V_153 - V_154 ;
int V_355 , V_356 ;
int V_357 = 0 , V_358 = 0 ;
for ( V_355 = 0 ; V_355 < V_274 ; V_355 ++ ) {
struct V_115 * V_116 = V_2 -> V_116 [ V_355 ] ;
struct V_359 * V_360 = & V_2 -> V_361 [ V_355 ] ;
if ( V_116 -> V_120 . V_79 && V_116 -> V_273 . V_79 ) {
snprintf ( V_116 -> V_16 , sizeof( V_116 -> V_16 ) - 1 ,
L_57 , V_18 -> V_16 , L_58 , V_357 ++ ) ;
V_358 ++ ;
} else if ( V_116 -> V_273 . V_79 ) {
snprintf ( V_116 -> V_16 , sizeof( V_116 -> V_16 ) - 1 ,
L_57 , V_18 -> V_16 , L_59 , V_357 ++ ) ;
} else if ( V_116 -> V_120 . V_79 ) {
snprintf ( V_116 -> V_16 , sizeof( V_116 -> V_16 ) - 1 ,
L_57 , V_18 -> V_16 , L_60 , V_358 ++ ) ;
} else {
continue;
}
V_356 = F_194 ( V_360 -> V_355 , & F_187 , 0 ,
V_116 -> V_16 , V_116 ) ;
if ( V_356 ) {
F_77 ( V_133 , L_61
L_62 , V_356 ) ;
goto V_362;
}
if ( V_2 -> V_98 & V_340 ) {
F_195 ( V_360 -> V_355 ,
& V_116 -> V_363 ) ;
}
}
V_356 = F_194 ( V_2 -> V_361 [ V_355 ] . V_355 ,
F_183 , 0 , V_18 -> V_16 , V_2 ) ;
if ( V_356 ) {
F_77 ( V_133 , L_63 , V_356 ) ;
goto V_362;
}
return 0 ;
V_362:
while ( V_355 ) {
V_355 -- ;
F_195 ( V_2 -> V_361 [ V_355 ] . V_355 ,
NULL ) ;
F_196 ( V_2 -> V_361 [ V_355 ] . V_355 ,
V_2 -> V_116 [ V_355 ] ) ;
}
V_2 -> V_98 &= ~ V_152 ;
F_197 ( V_2 -> V_36 ) ;
F_198 ( V_2 -> V_361 ) ;
V_2 -> V_361 = NULL ;
return V_356 ;
}
static T_10 F_199 ( int V_343 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_115 * V_116 = V_2 -> V_116 [ 0 ] ;
T_1 V_305 ;
F_45 ( V_8 , V_330 , V_364 ) ;
V_305 = F_11 ( V_8 , V_322 ) ;
if ( ! V_305 ) {
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_182 ( V_2 , true , true ) ;
return V_365 ;
}
if ( V_305 & V_312 )
F_176 ( V_2 ) ;
switch ( V_8 -> V_69 . type ) {
case V_72 :
F_175 ( V_2 , V_305 ) ;
case V_73 :
if ( V_305 & V_345 )
F_79 ( V_346 , L_64
L_56 ) ;
F_174 ( V_2 , V_305 ) ;
break;
default:
break;
}
F_173 ( V_2 , V_305 ) ;
#ifdef F_69
F_186 ( V_2 , V_305 ) ;
#endif
F_188 ( & V_116 -> V_235 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_182 ( V_2 , false , false ) ;
return V_351 ;
}
static int F_200 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
int V_356 ;
if ( V_2 -> V_98 & V_152 )
V_356 = F_193 ( V_2 ) ;
else if ( V_2 -> V_98 & V_366 )
V_356 = F_194 ( V_2 -> V_36 -> V_343 , F_199 , 0 ,
V_18 -> V_16 , V_2 ) ;
else
V_356 = F_194 ( V_2 -> V_36 -> V_343 , F_199 , V_367 ,
V_18 -> V_16 , V_2 ) ;
if ( V_356 )
F_77 ( V_133 , L_65 , V_356 ) ;
return V_356 ;
}
static void F_201 ( struct V_1 * V_2 )
{
if ( V_2 -> V_98 & V_152 ) {
int V_11 , V_274 ;
V_274 = V_2 -> V_153 ;
V_11 = V_274 - 1 ;
F_196 ( V_2 -> V_361 [ V_11 ] . V_355 , V_2 ) ;
V_11 -- ;
for (; V_11 >= 0 ; V_11 -- ) {
if ( ! V_2 -> V_116 [ V_11 ] -> V_273 . V_79 &&
! V_2 -> V_116 [ V_11 ] -> V_120 . V_79 )
continue;
F_195 ( V_2 -> V_361 [ V_11 ] . V_355 ,
NULL ) ;
F_196 ( V_2 -> V_361 [ V_11 ] . V_355 ,
V_2 -> V_116 [ V_11 ] ) ;
}
} else {
F_196 ( V_2 -> V_36 -> V_343 , V_2 ) ;
}
}
static inline void F_202 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 . V_69 . type ) {
case V_70 :
F_45 ( & V_2 -> V_8 , V_330 , ~ 0 ) ;
break;
case V_72 :
case V_73 :
F_45 ( & V_2 -> V_8 , V_330 , 0xFFFF0000 ) ;
F_45 ( & V_2 -> V_8 , F_181 ( 0 ) , ~ 0 ) ;
F_45 ( & V_2 -> V_8 , F_181 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_177 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_98 & V_152 ) {
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_153 ; V_11 ++ )
F_203 ( V_2 -> V_361 [ V_11 ] . V_355 ) ;
} else {
F_203 ( V_2 -> V_36 -> V_343 ) ;
}
}
static void F_204 ( struct V_1 * V_2 )
{
struct V_115 * V_116 = V_2 -> V_116 [ 0 ] ;
if ( V_2 -> V_282 == 1 )
V_116 -> V_280 = V_283 ;
else
V_116 -> V_280 = V_2 -> V_282 ;
F_166 ( V_116 ) ;
F_47 ( V_2 , 0 , 0 , 0 ) ;
F_47 ( V_2 , 1 , 0 , 0 ) ;
F_79 ( V_8 , L_66 ) ;
}
void F_205 ( struct V_1 * V_2 ,
struct V_20 * V_79 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_368 = V_79 -> V_45 ;
int V_369 = 10 ;
T_1 V_370 = V_371 ;
T_4 V_106 = V_79 -> V_106 ;
F_45 ( V_8 , F_24 ( V_106 ) , 0 ) ;
F_177 ( V_8 ) ;
F_45 ( V_8 , F_19 ( V_106 ) ,
( V_368 & F_206 ( 32 ) ) ) ;
F_45 ( V_8 , F_20 ( V_106 ) , ( V_368 >> 32 ) ) ;
F_45 ( V_8 , F_21 ( V_106 ) ,
V_79 -> V_52 * sizeof( union V_24 ) ) ;
F_45 ( V_8 , F_22 ( V_106 ) , 0 ) ;
F_45 ( V_8 , F_23 ( V_106 ) , 0 ) ;
V_79 -> V_107 = V_8 -> V_372 + F_23 ( V_106 ) ;
if ( ! V_79 -> V_116 || ( V_79 -> V_116 -> V_280 < 8 ) )
V_370 |= ( 1 << 16 ) ;
else
V_370 |= ( 8 << 16 ) ;
V_370 |= ( 1 << 8 ) |
32 ;
if ( ( V_2 -> V_98 & V_340 ) &&
V_2 -> V_373 ) {
V_79 -> V_373 = V_2 -> V_373 ;
V_79 -> V_374 = 0 ;
F_207 ( V_349 , & V_79 -> V_4 ) ;
} else {
V_79 -> V_373 = 0 ;
}
F_8 ( V_92 , & V_79 -> V_4 ) ;
F_45 ( V_8 , F_24 ( V_106 ) , V_370 ) ;
if ( V_8 -> V_69 . type == V_70 &&
! ( F_11 ( V_8 , V_375 ) & V_376 ) )
return;
do {
F_208 ( 1000 , 2000 ) ;
V_370 = F_11 ( V_8 , F_24 ( V_106 ) ) ;
} while ( -- V_369 && ! ( V_370 & V_371 ) );
if ( ! V_369 )
F_77 ( V_131 , L_67 , V_106 ) ;
}
static void F_209 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_377 ;
T_1 V_378 ;
T_4 V_379 = F_210 ( V_2 -> V_18 ) ;
if ( V_8 -> V_69 . type == V_70 )
return;
V_377 = F_11 ( V_8 , V_380 ) ;
V_377 |= V_381 ;
F_45 ( V_8 , V_380 , V_377 ) ;
switch ( V_2 -> V_98 & V_382 ) {
case ( V_382 ) :
F_45 ( V_8 , V_383 ,
( V_384 | V_385 ) ) ;
break;
default:
if ( ! V_379 )
V_378 = V_386 ;
else if ( V_379 <= 4 )
V_378 = V_387 | V_388 ;
else
V_378 = V_387 | V_389 ;
F_45 ( V_8 , V_383 , V_378 ) ;
if ( V_379 ) {
V_378 = F_11 ( V_8 , V_390 ) ;
V_378 |= V_391 ;
F_45 ( V_8 , V_390 , V_378 ) ;
}
break;
}
V_377 &= ~ V_381 ;
F_45 ( V_8 , V_380 , V_377 ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_392 ;
T_1 V_11 ;
F_209 ( V_2 ) ;
if ( V_8 -> V_69 . type != V_70 ) {
V_392 = F_11 ( V_8 , V_393 ) ;
V_392 |= V_394 ;
F_45 ( V_8 , V_393 , V_392 ) ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_205 ( V_2 , V_2 -> V_21 [ V_11 ] ) ;
}
static void F_212 ( struct V_1 * V_2 ,
struct V_20 * V_79 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_4 V_106 = V_79 -> V_106 ;
T_1 V_395 = F_11 ( V_8 , F_10 ( V_106 ) ) ;
V_395 |= V_396 ;
F_45 ( V_8 , F_10 ( V_106 ) , V_395 ) ;
}
static void F_213 ( struct V_1 * V_2 ,
struct V_20 * V_79 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_4 V_106 = V_79 -> V_106 ;
T_1 V_395 = F_11 ( V_8 , F_10 ( V_106 ) ) ;
V_395 &= ~ V_396 ;
F_45 ( V_8 , F_10 ( V_106 ) , V_395 ) ;
}
static void F_214 ( struct V_1 * V_2 ,
struct V_20 * V_30 )
{
T_1 V_395 ;
T_4 V_106 = V_30 -> V_106 ;
switch ( V_2 -> V_8 . V_69 . type ) {
case V_70 : {
struct V_397 * V_398 = V_2 -> V_399 ;
const int V_76 = V_398 [ V_400 ] . V_76 ;
V_106 = V_106 & V_76 ;
}
break;
case V_72 :
case V_73 :
default:
break;
}
V_395 = F_11 ( & V_2 -> V_8 , F_10 ( V_106 ) ) ;
V_395 &= ~ V_401 ;
V_395 &= ~ V_402 ;
if ( V_2 -> V_276 )
V_395 |= V_396 ;
V_395 |= ( V_265 << V_403 ) &
V_401 ;
#if V_404 > V_405
V_395 |= V_405 >> V_406 ;
#else
V_395 |= F_43 ( V_30 ) >> V_406 ;
#endif
V_395 |= V_407 ;
F_45 ( & V_2 -> V_8 , F_10 ( V_106 ) , V_395 ) ;
}
static void F_215 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
static const T_1 V_408 [ 10 ] = { 0xE291D73D , 0x1805EC6C , 0x2A94B30D ,
0xA54F2BEC , 0xEA49AF7C , 0xE214AD3D , 0xB855AABE ,
0x6A3E67EA , 0x14364D17 , 0x3BED200D } ;
T_1 V_409 = 0 , V_410 = 0 ;
T_1 V_411 ;
int V_11 , V_12 ;
T_4 V_379 = F_210 ( V_2 -> V_18 ) ;
int V_412 = V_2 -> V_399 [ V_400 ] . V_413 ;
if ( V_379 )
V_412 = F_216 ( V_412 , V_2 -> V_41 / V_379 ) ;
for ( V_11 = 0 ; V_11 < 10 ; V_11 ++ )
F_45 ( V_8 , F_217 ( V_11 ) , V_408 [ V_11 ] ) ;
for ( V_11 = 0 , V_12 = 0 ; V_11 < 128 ; V_11 ++ , V_12 ++ ) {
if ( V_12 == V_412 )
V_12 = 0 ;
V_410 = ( V_410 << 8 ) | ( V_12 * 0x11 ) ;
if ( ( V_11 & 3 ) == 3 )
F_45 ( V_8 , F_218 ( V_11 >> 2 ) , V_410 ) ;
}
V_411 = F_11 ( V_8 , V_414 ) ;
V_411 |= V_415 ;
F_45 ( V_8 , V_414 , V_411 ) ;
if ( V_2 -> V_8 . V_69 . type == V_70 &&
( V_2 -> V_98 & V_416 ) ) {
V_409 = V_417 ;
} else {
int V_76 = V_2 -> V_98 & ( V_416
| V_382 ) ;
switch ( V_76 ) {
case ( V_416 ) :
if ( ! V_379 )
V_409 = V_417 ;
else if ( V_379 <= 4 )
V_409 = V_418 ;
else
V_409 = V_419 ;
break;
case ( V_382 ) :
V_409 = V_420 ;
break;
default:
break;
}
}
V_409 |= V_421
| V_422
| V_423
| V_424 ;
if ( V_2 -> V_113 & V_425 )
V_409 |= V_426 ;
if ( V_2 -> V_113 & V_427 )
V_409 |= V_428 ;
F_45 ( V_8 , V_429 , V_409 ) ;
}
static void F_219 ( struct V_1 * V_2 ,
struct V_20 * V_79 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_430 ;
T_4 V_106 = V_79 -> V_106 ;
if ( ! F_124 ( V_79 ) )
return;
V_430 = F_11 ( V_8 , F_220 ( V_106 ) ) ;
V_430 |= V_431 ;
#if ( V_404 <= 8192 )
V_430 |= V_432 ;
#elif ( V_404 <= 16384 )
V_430 |= V_433 ;
#else
V_430 |= V_434 ;
#endif
F_45 ( V_8 , F_220 ( V_106 ) , V_430 ) ;
}
static void F_221 ( struct V_1 * V_2 ,
struct V_20 * V_79 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_369 = V_435 ;
T_1 V_436 ;
T_4 V_106 = V_79 -> V_106 ;
if ( V_8 -> V_69 . type == V_70 &&
! ( F_11 ( V_8 , V_375 ) & V_376 ) )
return;
do {
F_208 ( 1000 , 2000 ) ;
V_436 = F_11 ( V_8 , F_16 ( V_106 ) ) ;
} while ( -- V_369 && ! ( V_436 & V_437 ) );
if ( ! V_369 ) {
F_77 ( V_131 , L_68
L_69 , V_106 ) ;
}
}
void F_222 ( struct V_1 * V_2 ,
struct V_20 * V_79 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_369 = V_435 ;
T_1 V_436 ;
T_4 V_106 = V_79 -> V_106 ;
V_436 = F_11 ( V_8 , F_16 ( V_106 ) ) ;
V_436 &= ~ V_437 ;
F_45 ( V_8 , F_16 ( V_106 ) , V_436 ) ;
if ( V_8 -> V_69 . type == V_70 &&
! ( F_11 ( V_8 , V_375 ) & V_376 ) )
return;
do {
F_223 ( 10 ) ;
V_436 = F_11 ( V_8 , F_16 ( V_106 ) ) ;
} while ( -- V_369 && ( V_436 & V_437 ) );
if ( ! V_369 ) {
F_77 ( V_131 , L_70
L_69 , V_106 ) ;
}
}
void F_224 ( struct V_1 * V_2 ,
struct V_20 * V_79 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_438 = V_79 -> V_45 ;
T_1 V_436 ;
T_4 V_106 = V_79 -> V_106 ;
V_436 = F_11 ( V_8 , F_16 ( V_106 ) ) ;
F_222 ( V_2 , V_79 ) ;
F_45 ( V_8 , F_17 ( V_106 ) , ( V_438 & F_206 ( 32 ) ) ) ;
F_45 ( V_8 , F_18 ( V_106 ) , ( V_438 >> 32 ) ) ;
F_45 ( V_8 , F_13 ( V_106 ) ,
V_79 -> V_52 * sizeof( union V_31 ) ) ;
F_45 ( V_8 , F_14 ( V_106 ) , 0 ) ;
F_45 ( V_8 , F_15 ( V_106 ) , 0 ) ;
V_79 -> V_107 = V_8 -> V_372 + F_15 ( V_106 ) ;
F_214 ( V_2 , V_79 ) ;
F_219 ( V_2 , V_79 ) ;
if ( ( V_2 -> V_98 & V_382 ) &&
V_8 -> V_69 . type == V_73 ) {
V_436 &= ~ V_439 ;
V_436 |= ( ( V_79 -> V_18 -> V_269 + V_211 +
V_440 + V_214 ) | V_441 ) ;
}
if ( V_8 -> V_69 . type == V_70 ) {
V_436 &= ~ 0x3FFFFF ;
V_436 |= 0x080420 ;
}
V_436 |= V_437 ;
F_45 ( V_8 , F_16 ( V_106 ) , V_436 ) ;
F_221 ( V_2 , V_79 ) ;
F_118 ( V_79 , F_84 ( V_79 ) ) ;
}
static void F_225 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_442 ;
T_1 V_443 = V_444 |
V_445 |
V_446 |
V_447 |
V_448 ;
if ( V_8 -> V_69 . type == V_70 )
return;
if ( V_2 -> V_98 & V_416 )
V_443 |= ( V_2 -> V_449 << 29 ) ;
for ( V_442 = 0 ; V_442 < V_2 -> V_450 ; V_442 ++ )
F_45 ( V_8 , F_226 ( V_2 -> V_276 + V_442 ) ,
V_443 ) ;
}
static void F_227 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_451 ;
T_1 V_452 ;
T_1 V_138 , V_453 ;
T_1 V_454 ;
int V_11 ;
if ( ! ( V_2 -> V_98 & V_382 ) )
return;
V_454 = F_11 ( V_8 , V_455 ) ;
V_452 = V_456 | V_457 ;
V_452 |= ( V_2 -> V_276 << V_458 ) ;
F_45 ( V_8 , V_455 , V_454 | V_452 ) ;
V_453 = V_2 -> V_276 % 32 ;
V_138 = ( V_2 -> V_276 >= 32 ) ? 1 : 0 ;
F_45 ( V_8 , F_228 ( V_138 ) , ( 1 << V_453 ) ) ;
F_45 ( V_8 , F_228 ( V_138 ^ 1 ) , 0 ) ;
F_45 ( V_8 , F_229 ( V_138 ) , ( 1 << V_453 ) ) ;
F_45 ( V_8 , F_229 ( V_138 ^ 1 ) , 0 ) ;
F_45 ( V_8 , V_459 , V_460 ) ;
V_8 -> V_69 . V_313 . V_461 ( V_8 , 0 , V_2 -> V_276 ) ;
V_451 = F_11 ( V_8 , V_462 ) ;
V_451 |= V_463 ;
V_451 |= V_464 ;
F_45 ( V_8 , V_462 , V_451 ) ;
F_45 ( V_8 , V_459 , V_460 ) ;
V_8 -> V_69 . V_313 . V_465 ( V_8 ,
( V_2 -> V_276 != 0 ) ,
V_2 -> V_276 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_276 ; V_11 ++ ) {
if ( ! V_2 -> V_466 [ V_11 ] . V_467 )
F_230 ( V_2 -> V_18 , V_11 , false ) ;
}
}
static void F_231 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_18 = V_2 -> V_18 ;
int V_468 = V_18 -> V_269 + V_211 + V_440 ;
struct V_20 * V_30 ;
int V_11 ;
T_1 V_469 , V_470 ;
#ifdef F_122
if ( ( V_2 -> V_98 & V_471 ) &&
( V_468 < V_472 ) )
V_468 = V_472 ;
#endif
V_469 = F_11 ( V_8 , V_473 ) ;
if ( V_468 != ( V_469 >> V_474 ) ) {
V_469 &= ~ V_475 ;
V_469 |= V_468 << V_474 ;
F_45 ( V_8 , V_473 , V_469 ) ;
}
V_468 += V_214 ;
V_470 = F_11 ( V_8 , V_476 ) ;
V_470 |= V_477 ;
F_45 ( V_8 , V_476 , V_470 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ ) {
V_30 = V_2 -> V_30 [ V_11 ] ;
if ( V_2 -> V_113 & V_478 )
F_232 ( V_30 ) ;
else
F_233 ( V_30 ) ;
}
}
static void F_234 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_479 = F_11 ( V_8 , V_480 ) ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_479 |= V_481 ;
break;
case V_72 :
case V_73 :
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
static void F_235 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_11 ;
T_1 V_143 ;
V_143 = F_11 ( V_8 , V_488 ) ;
F_45 ( V_8 , V_488 , V_143 & ~ V_489 ) ;
F_225 ( V_2 ) ;
F_234 ( V_2 ) ;
F_215 ( V_2 ) ;
F_231 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ )
F_224 ( V_2 , V_2 -> V_30 [ V_11 ] ) ;
if ( V_8 -> V_69 . type == V_70 )
V_143 |= V_490 ;
V_143 |= V_489 ;
V_8 -> V_69 . V_313 . V_491 ( V_8 , V_143 ) ;
}
static int F_236 ( struct V_17 * V_18 , T_5 V_233 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_492 = V_2 -> V_276 ;
V_8 -> V_69 . V_313 . V_493 ( & V_2 -> V_8 , V_233 , V_492 , true ) ;
F_207 ( V_233 , V_2 -> V_494 ) ;
return 0 ;
}
static int F_237 ( struct V_17 * V_18 , T_5 V_233 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_492 = V_2 -> V_276 ;
V_8 -> V_69 . V_313 . V_493 ( & V_2 -> V_8 , V_233 , V_492 , false ) ;
F_8 ( V_233 , V_2 -> V_494 ) ;
return 0 ;
}
static void F_238 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_495 ;
V_495 = F_11 ( V_8 , V_496 ) ;
V_495 &= ~ ( V_497 | V_498 ) ;
F_45 ( V_8 , V_496 , V_495 ) ;
}
static void F_239 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_495 ;
V_495 = F_11 ( V_8 , V_496 ) ;
V_495 |= V_497 ;
V_495 &= ~ V_498 ;
F_45 ( V_8 , V_496 , V_495 ) ;
}
static void F_240 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_495 ;
int V_11 , V_12 ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_495 = F_11 ( V_8 , V_496 ) ;
V_495 &= ~ V_499 ;
F_45 ( V_8 , V_496 , V_495 ) ;
break;
case V_72 :
case V_73 :
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ ) {
V_12 = V_2 -> V_30 [ V_11 ] -> V_106 ;
V_495 = F_11 ( V_8 , F_16 ( V_12 ) ) ;
V_495 &= ~ V_500 ;
F_45 ( V_8 , F_16 ( V_12 ) , V_495 ) ;
}
break;
default:
break;
}
}
static void F_241 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_495 ;
int V_11 , V_12 ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_495 = F_11 ( V_8 , V_496 ) ;
V_495 |= V_499 ;
F_45 ( V_8 , V_496 , V_495 ) ;
break;
case V_72 :
case V_73 :
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ ) {
V_12 = V_2 -> V_30 [ V_11 ] -> V_106 ;
V_495 = F_11 ( V_8 , F_16 ( V_12 ) ) ;
V_495 |= V_500 ;
F_45 ( V_8 , F_16 ( V_12 ) , V_495 ) ;
}
break;
default:
break;
}
}
static void F_242 ( struct V_1 * V_2 )
{
T_5 V_233 ;
F_236 ( V_2 -> V_18 , 0 ) ;
F_243 (vid, adapter->active_vlans, VLAN_N_VID)
F_236 ( V_2 -> V_18 , V_233 ) ;
}
static int F_244 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
unsigned int V_501 = V_2 -> V_276 ;
unsigned int V_502 = V_503 ;
int V_52 = 0 ;
if ( F_245 ( V_18 ) > V_502 )
return - V_504 ;
if ( ! F_246 ( V_18 ) && V_502 ) {
struct V_505 * V_506 ;
if ( ! V_8 -> V_69 . V_313 . V_507 )
return - V_504 ;
F_247 (ha, netdev) {
if ( ! V_502 )
break;
V_8 -> V_69 . V_313 . V_507 ( V_8 , V_502 -- , V_506 -> V_508 ,
V_501 , V_509 ) ;
V_52 ++ ;
}
}
for (; V_502 > 0 ; V_502 -- )
V_8 -> V_69 . V_313 . V_510 ( V_8 , V_502 ) ;
return V_52 ;
}
void F_248 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_511 , V_512 = V_513 | V_514 ;
int V_52 ;
V_511 = F_11 ( V_8 , V_515 ) ;
V_511 &= ~ V_516 ;
V_511 |= V_517 ;
V_511 |= V_518 ;
V_511 |= V_519 ;
V_511 &= ~ ( V_520 | V_521 ) ;
if ( V_18 -> V_98 & V_522 ) {
V_8 -> V_523 . V_524 = true ;
V_511 |= ( V_520 | V_521 ) ;
V_512 |= ( V_525 | V_526 ) ;
F_238 ( V_2 ) ;
} else {
if ( V_18 -> V_98 & V_527 ) {
V_511 |= V_521 ;
V_512 |= V_526 ;
} else {
V_8 -> V_69 . V_313 . V_528 ( V_8 , V_18 ) ;
V_512 |= V_529 ;
}
F_239 ( V_2 ) ;
V_8 -> V_523 . V_524 = false ;
}
V_52 = F_244 ( V_18 ) ;
if ( V_52 < 0 ) {
V_511 |= V_520 ;
V_512 |= V_525 ;
}
if ( V_2 -> V_276 ) {
F_249 ( V_2 ) ;
V_512 |= F_11 ( V_8 , F_250 ( V_2 -> V_276 ) ) &
~ ( V_526 | V_529 |
V_525 ) ;
F_45 ( V_8 , F_250 ( V_2 -> V_276 ) , V_512 ) ;
}
if ( V_2 -> V_18 -> V_161 & V_248 ) {
V_511 |= ( V_516 |
V_517 |
V_519 ) ;
V_511 &= ~ ( V_518 ) ;
}
F_45 ( V_8 , V_515 , V_511 ) ;
if ( V_18 -> V_161 & V_231 )
F_241 ( V_2 ) ;
else
F_240 ( V_2 ) ;
}
static void F_251 ( struct V_1 * V_2 )
{
int V_530 ;
struct V_115 * V_116 ;
int V_274 = V_2 -> V_153 - V_154 ;
if ( ! ( V_2 -> V_98 & V_152 ) )
V_274 = 1 ;
for ( V_530 = 0 ; V_530 < V_274 ; V_530 ++ ) {
V_116 = V_2 -> V_116 [ V_530 ] ;
F_252 ( & V_116 -> V_235 ) ;
}
}
static void F_253 ( struct V_1 * V_2 )
{
int V_530 ;
struct V_115 * V_116 ;
int V_274 = V_2 -> V_153 - V_154 ;
if ( ! ( V_2 -> V_98 & V_152 ) )
V_274 = 1 ;
for ( V_530 = 0 ; V_530 < V_274 ; V_530 ++ ) {
V_116 = V_2 -> V_116 [ V_530 ] ;
F_254 ( & V_116 -> V_235 ) ;
}
}
static void F_255 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_468 = V_2 -> V_18 -> V_269 + V_211 + V_440 ;
if ( ! ( V_2 -> V_98 & V_99 ) ) {
if ( V_8 -> V_69 . type == V_70 )
F_256 ( V_2 -> V_18 , 65536 ) ;
return;
}
if ( V_8 -> V_69 . type == V_70 )
F_256 ( V_2 -> V_18 , 32768 ) ;
V_8 -> V_69 . V_313 . V_493 ( & V_2 -> V_8 , 0 , 0 , true ) ;
#ifdef F_122
if ( V_2 -> V_18 -> V_161 & V_531 )
V_468 = F_170 ( V_468 , V_472 ) ;
#endif
if ( V_2 -> V_532 & V_533 ) {
F_257 ( V_8 , & V_2 -> V_95 , V_468 ,
V_534 ) ;
F_257 ( V_8 , & V_2 -> V_95 , V_468 ,
V_535 ) ;
F_258 ( V_8 , & V_2 -> V_95 ) ;
} else if ( V_2 -> V_536 && V_2 -> V_97 ) {
F_259 ( & V_2 -> V_8 ,
V_2 -> V_536 ,
V_468 ) ;
F_260 ( & V_2 -> V_8 ,
V_2 -> V_97 -> V_94 ,
V_2 -> V_536 -> V_537 ) ;
}
if ( V_8 -> V_69 . type != V_70 ) {
int V_11 ;
T_1 V_378 = 0 ;
for ( V_11 = 0 ; V_11 < V_538 ; V_11 ++ ) {
T_4 V_539 = 0 ;
T_4 V_540 = V_2 -> V_18 -> V_541 [ V_11 ] . V_52 ;
while ( V_540 >>= 1 )
V_539 ++ ;
V_378 |= V_539 << F_261 ( V_11 ) ;
}
F_45 ( V_8 , V_542 , V_378 ) ;
}
}
static int F_262 ( struct V_1 * V_2 , int V_543 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_37 = V_2 -> V_18 ;
int V_346 , V_102 , V_544 , V_545 ;
T_1 V_546 , V_547 ;
V_102 = V_346 = V_37 -> V_269 + V_211 + V_440 + V_548 ;
#ifdef F_122
if ( V_37 -> V_161 & V_531 ) {
int V_549 = 0 ;
#ifdef F_263
V_549 = F_264 ( V_37 , V_2 -> V_550 . V_551 ) ;
#endif
if ( V_549 == V_543 && V_102 < V_472 )
V_102 = V_472 ;
}
#endif
switch ( V_8 -> V_69 . type ) {
case V_73 :
V_546 = F_265 ( V_346 , V_102 ) ;
break;
default:
V_546 = F_266 ( V_346 , V_102 ) ;
break;
}
if ( V_2 -> V_98 & V_382 )
V_546 += F_267 ( V_102 ) ;
V_544 = F_268 ( V_546 ) ;
V_547 = F_11 ( V_8 , F_269 ( V_543 ) ) >> 10 ;
V_545 = V_547 - V_544 ;
if ( V_545 < 0 ) {
F_270 ( V_131 , L_71
L_72
L_73 , V_543 ) ;
V_545 = V_102 + 1 ;
}
return V_545 ;
}
static int F_271 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_37 = V_2 -> V_18 ;
int V_102 ;
T_1 V_546 ;
V_102 = V_37 -> V_269 + V_211 + V_440 ;
switch ( V_8 -> V_69 . type ) {
case V_73 :
V_546 = F_272 ( V_102 ) ;
break;
default:
V_546 = F_273 ( V_102 ) ;
break;
}
return F_268 ( V_546 ) ;
}
static void F_274 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_552 = F_210 ( V_2 -> V_18 ) ;
int V_11 ;
if ( ! V_552 )
V_552 = 1 ;
V_8 -> V_85 . V_553 = F_271 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_552 ; V_11 ++ ) {
V_8 -> V_85 . V_554 [ V_11 ] = F_262 ( V_2 , V_11 ) ;
if ( V_8 -> V_85 . V_553 > V_8 -> V_85 . V_554 [ V_11 ] )
V_8 -> V_85 . V_553 = 0 ;
}
}
static void F_275 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_555 ;
T_4 V_102 = F_210 ( V_2 -> V_18 ) ;
if ( V_2 -> V_98 & V_340 ||
V_2 -> V_98 & V_556 )
V_555 = 32 << V_2 -> V_557 ;
else
V_555 = 0 ;
V_8 -> V_69 . V_313 . V_558 ( V_8 , V_102 , V_555 , V_559 ) ;
F_274 ( V_2 ) ;
}
static void F_276 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_560 * V_561 , * V_562 ;
struct V_563 * V_564 ;
F_277 ( & V_2 -> V_565 ) ;
if ( ! F_278 ( & V_2 -> V_566 ) )
F_279 ( V_8 , & V_2 -> V_567 ) ;
F_280 (filter, node, node2,
&adapter->fdir_filter_list, fdir_node) {
F_281 ( V_8 ,
& V_564 -> V_564 ,
V_564 -> V_568 ,
( V_564 -> V_569 == V_570 ) ?
V_570 :
V_2 -> V_30 [ V_564 -> V_569 ] -> V_106 ) ;
}
F_282 ( & V_2 -> V_565 ) ;
}
static void F_283 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
F_275 ( V_2 ) ;
#ifdef F_263
F_255 ( V_2 ) ;
#endif
F_248 ( V_2 -> V_18 ) ;
F_242 ( V_2 ) ;
#ifdef F_122
if ( V_2 -> V_98 & V_471 )
F_284 ( V_2 ) ;
#endif
switch ( V_8 -> V_69 . type ) {
case V_72 :
case V_73 :
V_8 -> V_69 . V_313 . V_571 ( V_8 ) ;
break;
default:
break;
}
if ( V_2 -> V_98 & V_340 ) {
F_285 ( & V_2 -> V_8 ,
V_2 -> V_557 ) ;
} else if ( V_2 -> V_98 & V_556 ) {
F_286 ( & V_2 -> V_8 ,
V_2 -> V_557 ) ;
F_276 ( V_2 ) ;
}
switch ( V_8 -> V_69 . type ) {
case V_72 :
case V_73 :
V_8 -> V_69 . V_313 . V_572 ( V_8 ) ;
break;
default:
break;
}
F_227 ( V_2 ) ;
F_211 ( V_2 ) ;
F_235 ( V_2 ) ;
}
static inline bool F_287 ( struct V_7 * V_8 )
{
switch ( V_8 -> V_317 . type ) {
case V_573 :
case V_574 :
case V_575 :
case V_576 :
case V_577 :
case V_578 :
case V_579 :
case V_580 :
return true ;
case V_581 :
if ( V_8 -> V_69 . type == V_70 )
return true ;
default:
return false ;
}
}
static void F_288 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_69 . type == V_70 )
V_2 -> V_113 |= V_582 ;
V_2 -> V_113 |= V_325 ;
}
static int F_289 ( struct V_7 * V_8 )
{
T_1 V_315 ;
bool V_583 , V_316 = false ;
T_1 V_112 = V_584 ;
if ( V_8 -> V_69 . V_313 . V_314 )
V_112 = V_8 -> V_69 . V_313 . V_314 ( V_8 , & V_315 , & V_316 , false ) ;
if ( V_112 )
goto V_585;
V_315 = V_8 -> V_317 . V_586 ;
if ( ( ! V_315 ) && ( V_8 -> V_69 . V_313 . V_587 ) )
V_112 = V_8 -> V_69 . V_313 . V_587 ( V_8 , & V_315 ,
& V_583 ) ;
if ( V_112 )
goto V_585;
if ( V_8 -> V_69 . V_313 . V_588 )
V_112 = V_8 -> V_69 . V_313 . V_588 ( V_8 , V_315 , V_583 , V_316 ) ;
V_585:
return V_112 ;
}
static void F_290 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_589 = 0 ;
if ( V_2 -> V_98 & V_152 ) {
V_589 = V_590 | V_591 |
V_592 ;
V_589 |= V_593 ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
F_45 ( V_8 , V_594 , V_595 ) ;
break;
case V_72 :
case V_73 :
default:
F_45 ( V_8 , F_291 ( 0 ) , 0xFFFFFFFF ) ;
F_45 ( V_8 , F_291 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_45 ( V_8 , V_594 , V_595 ) ;
}
if ( V_2 -> V_98 & V_382 ) {
V_589 &= ~ V_596 ;
V_589 |= V_597 ;
}
if ( V_2 -> V_113 & V_307 ) {
switch ( V_2 -> V_8 . V_69 . type ) {
case V_72 :
V_589 |= V_598 ;
break;
case V_73 :
V_589 |= V_336 ;
break;
default:
break;
}
}
if ( V_2 -> V_98 & V_320 )
V_589 |= V_599 ;
if ( V_8 -> V_69 . type == V_72 ) {
V_589 |= V_599 ;
V_589 |= V_600 ;
}
F_45 ( V_8 , V_601 , V_589 ) ;
}
static void F_292 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_356 ;
T_1 V_61 ;
F_46 ( V_2 ) ;
F_290 ( V_2 ) ;
if ( V_2 -> V_98 & V_152 )
F_165 ( V_2 ) ;
else
F_204 ( V_2 ) ;
if ( V_8 -> V_69 . V_313 . V_602 &&
( ( V_8 -> V_317 . V_603 ) ||
( ( V_8 -> V_69 . V_313 . V_604 ( V_8 ) == V_605 ) &&
( V_8 -> V_69 . type == V_72 ) ) ) )
V_8 -> V_69 . V_313 . V_602 ( V_8 ) ;
F_8 ( V_3 , & V_2 -> V_4 ) ;
F_251 ( V_2 ) ;
if ( F_287 ( V_8 ) ) {
F_288 ( V_2 ) ;
} else {
V_356 = F_289 ( V_8 ) ;
if ( V_356 )
F_77 ( V_133 , L_74 , V_356 ) ;
}
F_11 ( V_8 , V_322 ) ;
F_182 ( V_2 , true , true ) ;
if ( V_2 -> V_98 & V_320 ) {
T_1 V_606 = F_11 ( V_8 , V_607 ) ;
if ( V_606 & V_608 )
F_172 ( V_131 , L_54 ) ;
}
F_293 ( V_2 -> V_18 ) ;
V_2 -> V_98 |= V_328 ;
V_2 -> V_329 = V_132 ;
F_294 ( & V_2 -> V_609 , V_132 ) ;
V_61 = F_11 ( V_8 , V_62 ) ;
V_61 |= V_610 ;
F_45 ( V_8 , V_62 , V_61 ) ;
}
void F_295 ( struct V_1 * V_2 )
{
F_296 ( F_297 () ) ;
V_2 -> V_18 -> V_38 = V_132 ;
while ( F_3 ( V_611 , & V_2 -> V_4 ) )
F_208 ( 1000 , 2000 ) ;
F_298 ( V_2 ) ;
if ( V_2 -> V_98 & V_382 )
F_299 ( 2000 ) ;
F_300 ( V_2 ) ;
F_8 ( V_611 , & V_2 -> V_4 ) ;
}
void F_300 ( struct V_1 * V_2 )
{
F_283 ( V_2 ) ;
F_292 ( V_2 ) ;
}
void F_301 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_356 ;
while ( F_3 ( V_612 , & V_2 -> V_4 ) )
F_208 ( 1000 , 2000 ) ;
V_2 -> V_113 &= ~ ( V_582 |
V_325 ) ;
V_2 -> V_98 &= ~ V_326 ;
V_356 = V_8 -> V_69 . V_313 . V_613 ( V_8 ) ;
switch ( V_356 ) {
case 0 :
case V_614 :
case V_615 :
break;
case V_616 :
F_302 ( L_75 ) ;
break;
case V_617 :
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
F_8 ( V_612 , & V_2 -> V_4 ) ;
V_8 -> V_69 . V_313 . V_507 ( V_8 , 0 , V_8 -> V_69 . V_508 , V_2 -> V_276 ,
V_509 ) ;
}
static void F_304 ( struct V_20 * V_30 )
{
struct V_33 * V_253 = V_30 -> V_34 ;
T_5 V_11 ;
for ( V_11 = 0 ; V_11 < V_30 -> V_52 ; V_11 += 2 ) {
V_253 [ 0 ] . V_194 = 0 ;
V_253 [ 1 ] . V_194 = F_43 ( V_30 ) ;
V_253 = & V_253 [ 2 ] ;
}
}
static void F_305 ( struct V_20 * V_30 )
{
struct V_155 * V_37 = V_30 -> V_37 ;
unsigned long V_258 ;
T_5 V_11 ;
if ( ! V_30 -> V_34 )
return;
for ( V_11 = 0 ; V_11 < V_30 -> V_52 ; V_11 ++ ) {
struct V_33 * V_253 ;
V_253 = & V_30 -> V_34 [ V_11 ] ;
if ( V_253 -> V_53 ) {
struct V_160 * V_53 = V_253 -> V_53 ;
if ( F_125 ( V_53 ) -> V_246 ) {
F_54 ( V_37 ,
F_125 ( V_53 ) -> V_45 ,
F_43 ( V_30 ) ,
V_193 ) ;
F_125 ( V_53 ) -> V_246 = false ;
}
F_306 ( V_53 ) ;
}
V_253 -> V_53 = NULL ;
if ( V_253 -> V_45 )
F_54 ( V_37 , V_253 -> V_45 ,
F_115 ( V_30 ) ,
V_193 ) ;
V_253 -> V_45 = 0 ;
if ( V_253 -> V_188 )
F_117 ( V_253 -> V_188 ,
F_113 ( V_30 ) ) ;
V_253 -> V_188 = NULL ;
}
V_258 = sizeof( struct V_33 ) * V_30 -> V_52 ;
memset ( V_30 -> V_34 , 0 , V_258 ) ;
F_304 ( V_30 ) ;
memset ( V_30 -> V_51 , 0 , V_30 -> V_258 ) ;
V_30 -> V_186 = 0 ;
V_30 -> V_43 = 0 ;
V_30 -> V_44 = 0 ;
}
static void F_307 ( struct V_20 * V_21 )
{
struct V_22 * V_42 ;
unsigned long V_258 ;
T_5 V_11 ;
if ( ! V_21 -> V_42 )
return;
for ( V_11 = 0 ; V_11 < V_21 -> V_52 ; V_11 ++ ) {
V_42 = & V_21 -> V_42 [ V_11 ] ;
F_51 ( V_21 , V_42 ) ;
}
F_308 ( F_81 ( V_21 ) ) ;
V_258 = sizeof( struct V_22 ) * V_21 -> V_52 ;
memset ( V_21 -> V_42 , 0 , V_258 ) ;
memset ( V_21 -> V_51 , 0 , V_21 -> V_258 ) ;
V_21 -> V_44 = 0 ;
V_21 -> V_43 = 0 ;
}
static void F_309 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ )
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
struct V_560 * V_561 , * V_562 ;
struct V_563 * V_564 ;
F_277 ( & V_2 -> V_565 ) ;
F_280 (filter, node, node2,
&adapter->fdir_filter_list, fdir_node) {
F_312 ( & V_564 -> V_618 ) ;
F_198 ( V_564 ) ;
}
V_2 -> V_619 = 0 ;
F_282 ( & V_2 -> V_565 ) ;
}
void F_298 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_143 ;
int V_11 ;
F_207 ( V_3 , & V_2 -> V_4 ) ;
V_143 = F_11 ( V_8 , V_488 ) ;
F_45 ( V_8 , V_488 , V_143 & ~ V_489 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ )
F_222 ( V_2 , V_2 -> V_30 [ V_11 ] ) ;
F_208 ( 10000 , 20000 ) ;
F_313 ( V_18 ) ;
F_314 ( V_18 ) ;
F_315 ( V_18 ) ;
F_202 ( V_2 ) ;
F_253 ( V_2 ) ;
V_2 -> V_113 &= ~ ( V_341 |
V_114 ) ;
V_2 -> V_98 &= ~ V_328 ;
F_316 ( & V_2 -> V_609 ) ;
if ( V_2 -> V_276 ) {
F_45 ( & V_2 -> V_8 , V_278 , 0 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_276 ; V_11 ++ )
V_2 -> V_466 [ V_11 ] . V_620 = false ;
F_317 ( V_2 ) ;
F_318 ( V_2 ) ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
T_4 V_106 = V_2 -> V_21 [ V_11 ] -> V_106 ;
F_45 ( V_8 , F_24 ( V_106 ) , V_621 ) ;
}
switch ( V_8 -> V_69 . type ) {
case V_72 :
case V_73 :
F_45 ( V_8 , V_393 ,
( F_11 ( V_8 , V_393 ) &
~ V_394 ) ) ;
break;
default:
break;
}
if ( ! F_319 ( V_2 -> V_36 ) )
F_301 ( V_2 ) ;
if ( V_8 -> V_69 . V_313 . V_622 &&
( ( V_8 -> V_317 . V_603 ) ||
( ( V_8 -> V_69 . V_313 . V_604 ( V_8 ) == V_605 ) &&
( V_8 -> V_69 . type == V_72 ) ) ) )
V_8 -> V_69 . V_313 . V_622 ( V_8 ) ;
F_310 ( V_2 ) ;
F_309 ( V_2 ) ;
#ifdef F_191
F_97 ( V_2 ) ;
#endif
}
static void F_320 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
F_65 ( V_2 ) ;
}
static int T_11 F_321 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_623 * V_36 = V_2 -> V_36 ;
unsigned int V_166 ;
#ifdef F_263
int V_12 ;
struct V_624 * V_102 ;
#endif
V_8 -> V_625 = V_36 -> V_626 ;
V_8 -> V_309 = V_36 -> V_155 ;
V_8 -> V_627 = V_36 -> V_628 ;
V_8 -> V_629 = V_36 -> V_630 ;
V_8 -> V_631 = V_36 -> V_632 ;
V_166 = F_322 ( int , V_633 , F_323 () ) ;
V_2 -> V_399 [ V_400 ] . V_413 = V_166 ;
V_2 -> V_98 |= V_416 ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
if ( V_8 -> V_309 == V_634 )
V_2 -> V_98 |= V_320 ;
V_2 -> V_635 = V_636 ;
break;
case V_73 :
V_2 -> V_113 |= V_307 ;
case V_72 :
V_2 -> V_635 = V_637 ;
V_2 -> V_113 |= V_638 ;
V_2 -> V_113 |= V_478 ;
if ( V_8 -> V_309 == V_310 )
V_2 -> V_113 |= V_307 ;
V_2 -> V_98 |= V_340 ;
V_2 -> V_373 = 20 ;
V_2 -> V_399 [ V_639 ] . V_413 =
V_640 ;
V_2 -> V_557 = V_641 ;
#ifdef F_122
V_2 -> V_98 |= V_642 ;
V_2 -> V_98 &= ~ V_471 ;
V_2 -> V_399 [ V_643 ] . V_413 = 0 ;
#ifdef F_263
V_2 -> V_550 . V_551 = V_644 ;
#endif
#endif
break;
default:
break;
}
F_324 ( & V_2 -> V_565 ) ;
#ifdef F_263
switch ( V_8 -> V_69 . type ) {
case V_73 :
V_2 -> V_95 . V_645 . V_646 = V_647 ;
V_2 -> V_95 . V_645 . V_648 = V_647 ;
break;
default:
V_2 -> V_95 . V_645 . V_646 = V_538 ;
V_2 -> V_95 . V_645 . V_648 = V_538 ;
break;
}
for ( V_12 = 0 ; V_12 < V_538 ; V_12 ++ ) {
V_102 = & V_2 -> V_95 . V_649 [ V_12 ] ;
V_102 -> V_650 [ V_534 ] . V_651 = 0 ;
V_102 -> V_650 [ V_534 ] . V_652 = 12 + ( V_12 & 1 ) ;
V_102 -> V_650 [ V_535 ] . V_651 = 0 ;
V_102 -> V_650 [ V_535 ] . V_652 = 12 + ( V_12 & 1 ) ;
V_102 -> V_653 = V_654 ;
}
V_102 = & V_2 -> V_95 . V_649 [ 0 ] ;
V_102 -> V_650 [ V_534 ] . V_655 = 0xFF ;
V_102 -> V_650 [ V_535 ] . V_655 = 0xFF ;
V_2 -> V_95 . V_656 [ V_534 ] [ 0 ] = 100 ;
V_2 -> V_95 . V_656 [ V_535 ] [ 0 ] = 100 ;
V_2 -> V_95 . V_96 = false ;
V_2 -> V_657 = 0x00 ;
V_2 -> V_532 = V_658 | V_533 ;
memcpy ( & V_2 -> V_659 , & V_2 -> V_95 ,
sizeof( V_2 -> V_659 ) ) ;
#endif
V_8 -> V_85 . V_660 = V_87 ;
V_8 -> V_85 . V_86 = V_87 ;
F_274 ( V_2 ) ;
V_8 -> V_85 . V_661 = V_662 ;
V_8 -> V_85 . V_663 = true ;
V_8 -> V_85 . V_664 = false ;
V_2 -> V_282 = 1 ;
V_2 -> V_279 = 1 ;
V_2 -> V_665 = V_666 ;
V_2 -> V_667 = V_668 ;
V_2 -> V_669 = V_670 ;
if ( F_325 ( V_8 ) ) {
F_302 ( L_83 ) ;
return - V_671 ;
}
F_207 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
}
int F_326 ( struct V_20 * V_21 )
{
struct V_155 * V_37 = V_21 -> V_37 ;
int V_672 = F_327 ( V_37 ) ;
int V_673 = - 1 ;
int V_258 ;
V_258 = sizeof( struct V_22 ) * V_21 -> V_52 ;
if ( V_21 -> V_116 )
V_673 = V_21 -> V_116 -> V_673 ;
V_21 -> V_42 = F_328 ( V_258 , V_673 ) ;
if ( ! V_21 -> V_42 )
V_21 -> V_42 = F_329 ( V_258 ) ;
if ( ! V_21 -> V_42 )
goto V_356;
V_21 -> V_258 = V_21 -> V_52 * sizeof( union V_24 ) ;
V_21 -> V_258 = F_146 ( V_21 -> V_258 , 4096 ) ;
F_330 ( V_37 , V_673 ) ;
V_21 -> V_51 = F_331 ( V_37 ,
V_21 -> V_258 ,
& V_21 -> V_45 ,
V_674 ) ;
F_330 ( V_37 , V_672 ) ;
if ( ! V_21 -> V_51 )
V_21 -> V_51 = F_331 ( V_37 , V_21 -> V_258 ,
& V_21 -> V_45 , V_674 ) ;
if ( ! V_21 -> V_51 )
goto V_356;
V_21 -> V_44 = 0 ;
V_21 -> V_43 = 0 ;
return 0 ;
V_356:
F_332 ( V_21 -> V_42 ) ;
V_21 -> V_42 = NULL ;
F_333 ( V_37 , L_84 ) ;
return - V_504 ;
}
static int F_334 ( struct V_1 * V_2 )
{
int V_11 , V_356 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
V_356 = F_326 ( V_2 -> V_21 [ V_11 ] ) ;
if ( ! V_356 )
continue;
F_77 ( V_133 , L_85 , V_11 ) ;
break;
}
return V_356 ;
}
int F_335 ( struct V_20 * V_30 )
{
struct V_155 * V_37 = V_30 -> V_37 ;
int V_672 = F_327 ( V_37 ) ;
int V_673 = - 1 ;
int V_258 ;
V_258 = sizeof( struct V_33 ) * V_30 -> V_52 ;
if ( V_30 -> V_116 )
V_673 = V_30 -> V_116 -> V_673 ;
V_30 -> V_34 = F_328 ( V_258 , V_673 ) ;
if ( ! V_30 -> V_34 )
V_30 -> V_34 = F_329 ( V_258 ) ;
if ( ! V_30 -> V_34 )
goto V_356;
V_30 -> V_258 = V_30 -> V_52 * sizeof( union V_31 ) ;
V_30 -> V_258 = F_146 ( V_30 -> V_258 , 4096 ) ;
F_330 ( V_37 , V_673 ) ;
V_30 -> V_51 = F_331 ( V_37 ,
V_30 -> V_258 ,
& V_30 -> V_45 ,
V_674 ) ;
F_330 ( V_37 , V_672 ) ;
if ( ! V_30 -> V_51 )
V_30 -> V_51 = F_331 ( V_37 , V_30 -> V_258 ,
& V_30 -> V_45 , V_674 ) ;
if ( ! V_30 -> V_51 )
goto V_356;
V_30 -> V_43 = 0 ;
V_30 -> V_44 = 0 ;
F_304 ( V_30 ) ;
return 0 ;
V_356:
F_332 ( V_30 -> V_34 ) ;
V_30 -> V_34 = NULL ;
F_333 ( V_37 , L_86 ) ;
return - V_504 ;
}
static int F_336 ( struct V_1 * V_2 )
{
int V_11 , V_356 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ ) {
V_356 = F_335 ( V_2 -> V_30 [ V_11 ] ) ;
if ( ! V_356 )
continue;
F_77 ( V_133 , L_87 , V_11 ) ;
break;
}
return V_356 ;
}
void F_337 ( struct V_20 * V_21 )
{
F_307 ( V_21 ) ;
F_332 ( V_21 -> V_42 ) ;
V_21 -> V_42 = NULL ;
if ( ! V_21 -> V_51 )
return;
F_338 ( V_21 -> V_37 , V_21 -> V_258 ,
V_21 -> V_51 , V_21 -> V_45 ) ;
V_21 -> V_51 = NULL ;
}
static void F_339 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
if ( V_2 -> V_21 [ V_11 ] -> V_51 )
F_337 ( V_2 -> V_21 [ V_11 ] ) ;
}
void F_340 ( struct V_20 * V_30 )
{
F_305 ( V_30 ) ;
F_332 ( V_30 -> V_34 ) ;
V_30 -> V_34 = NULL ;
if ( ! V_30 -> V_51 )
return;
F_338 ( V_30 -> V_37 , V_30 -> V_258 ,
V_30 -> V_51 , V_30 -> V_45 ) ;
V_30 -> V_51 = NULL ;
}
static void F_341 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ )
if ( V_2 -> V_30 [ V_11 ] -> V_51 )
F_340 ( V_2 -> V_30 [ V_11 ] ) ;
}
static int F_342 ( struct V_17 * V_18 , int V_675 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
int V_468 = V_675 + V_211 + V_440 ;
if ( ( V_675 < 68 ) || ( V_468 > V_676 ) )
return - V_677 ;
if ( ( V_2 -> V_98 & V_382 ) &&
( V_2 -> V_8 . V_69 . type == V_72 ) &&
( V_468 > V_678 ) )
return - V_677 ;
F_79 ( V_133 , L_88 , V_18 -> V_269 , V_675 ) ;
V_18 -> V_269 = V_675 ;
if ( F_31 ( V_18 ) )
F_295 ( V_2 ) ;
return 0 ;
}
static int F_343 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
int V_356 ;
if ( F_2 ( V_679 , & V_2 -> V_4 ) )
return - V_680 ;
F_314 ( V_18 ) ;
V_356 = F_334 ( V_2 ) ;
if ( V_356 )
goto V_681;
V_356 = F_336 ( V_2 ) ;
if ( V_356 )
goto V_682;
F_283 ( V_2 ) ;
V_356 = F_200 ( V_2 ) ;
if ( V_356 )
goto V_683;
F_292 ( V_2 ) ;
return 0 ;
V_683:
V_682:
F_341 ( V_2 ) ;
V_681:
F_339 ( V_2 ) ;
F_301 ( V_2 ) ;
return V_356 ;
}
static int F_344 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
F_298 ( V_2 ) ;
F_201 ( V_2 ) ;
F_311 ( V_2 ) ;
F_339 ( V_2 ) ;
F_341 ( V_2 ) ;
F_44 ( V_2 ) ;
return 0 ;
}
static int F_345 ( struct V_623 * V_36 )
{
struct V_1 * V_2 = F_346 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_356 ;
F_347 ( V_36 , V_684 ) ;
F_348 ( V_36 ) ;
F_349 ( V_36 ) ;
V_356 = F_350 ( V_36 ) ;
if ( V_356 ) {
F_302 ( L_89 ) ;
return V_356 ;
}
F_351 ( V_36 ) ;
F_352 ( V_36 , false ) ;
F_353 () ;
V_356 = F_354 ( V_2 ) ;
F_355 () ;
if ( V_356 ) {
F_302 ( L_90 ) ;
return V_356 ;
}
F_301 ( V_2 ) ;
F_45 ( & V_2 -> V_8 , V_685 , ~ 0 ) ;
if ( F_31 ( V_18 ) ) {
V_356 = F_343 ( V_18 ) ;
if ( V_356 )
return V_356 ;
}
F_356 ( V_18 ) ;
return 0 ;
}
static int F_357 ( struct V_623 * V_36 , bool * V_686 )
{
struct V_1 * V_2 = F_346 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_687 , V_511 ;
T_1 V_688 = V_2 -> V_689 ;
#ifdef F_358
int V_690 = 0 ;
#endif
F_359 ( V_18 ) ;
if ( F_31 ( V_18 ) ) {
F_353 () ;
F_298 ( V_2 ) ;
F_201 ( V_2 ) ;
F_339 ( V_2 ) ;
F_341 ( V_2 ) ;
F_355 () ;
}
F_360 ( V_2 ) ;
#ifdef F_358
V_690 = F_349 ( V_36 ) ;
if ( V_690 )
return V_690 ;
#endif
if ( V_688 ) {
F_248 ( V_18 ) ;
if ( V_8 -> V_69 . V_313 . V_602 &&
( V_8 -> V_317 . V_603 ||
( V_8 -> V_69 . V_313 . V_604 ( V_8 ) == V_605 &&
V_8 -> V_69 . type == V_72 ) ) )
V_8 -> V_69 . V_313 . V_602 ( V_8 ) ;
if ( V_688 & V_691 ) {
V_511 = F_11 ( V_8 , V_515 ) ;
V_511 |= V_521 ;
F_45 ( V_8 , V_515 , V_511 ) ;
}
V_687 = F_11 ( V_8 , V_692 ) ;
V_687 |= V_693 ;
F_45 ( V_8 , V_692 , V_687 ) ;
F_45 ( V_8 , V_694 , V_688 ) ;
} else {
F_45 ( V_8 , V_695 , 0 ) ;
F_45 ( V_8 , V_694 , 0 ) ;
}
switch ( V_8 -> V_69 . type ) {
case V_70 :
F_352 ( V_36 , false ) ;
break;
case V_72 :
case V_73 :
F_352 ( V_36 , ! ! V_688 ) ;
break;
default:
break;
}
* V_686 = ! ! V_688 ;
F_44 ( V_2 ) ;
F_361 ( V_36 ) ;
return 0 ;
}
static int F_362 ( struct V_623 * V_36 , T_12 V_4 )
{
int V_690 ;
bool V_696 ;
V_690 = F_357 ( V_36 , & V_696 ) ;
if ( V_690 )
return V_690 ;
if ( V_696 ) {
F_363 ( V_36 ) ;
} else {
F_352 ( V_36 , false ) ;
F_347 ( V_36 , V_697 ) ;
}
return 0 ;
}
static void F_364 ( struct V_623 * V_36 )
{
bool V_696 ;
F_357 ( V_36 , & V_696 ) ;
if ( V_698 == V_699 ) {
F_352 ( V_36 , V_696 ) ;
F_347 ( V_36 , V_697 ) ;
}
}
void F_365 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_81 * V_82 = & V_2 -> V_83 ;
T_2 V_700 = 0 ;
T_1 V_11 , V_701 = 0 , V_702 , V_703 , V_704 , V_705 , V_706 ;
T_2 V_240 = 0 , V_135 = 0 , V_707 = 0 ;
T_2 V_192 = 0 , V_266 = 0 ;
T_2 V_130 = 0 , V_104 = 0 , V_708 = 0 ;
#ifdef F_122
struct V_709 * V_550 = & V_2 -> V_550 ;
unsigned int V_136 ;
T_2 V_710 = 0 , V_711 = 0 ;
#endif
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_611 , & V_2 -> V_4 ) )
return;
if ( V_2 -> V_113 & V_478 ) {
T_2 V_228 = 0 ;
T_2 V_229 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ ) {
V_228 += V_2 -> V_30 [ V_11 ] -> V_177 . V_228 ;
V_229 += V_2 -> V_30 [ V_11 ] -> V_177 . V_229 ;
}
V_2 -> V_712 = V_228 ;
V_2 -> V_713 = V_229 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ ) {
struct V_20 * V_30 = V_2 -> V_30 [ V_11 ] ;
V_240 += V_30 -> V_177 . V_240 ;
V_192 += V_30 -> V_177 . V_192 ;
V_266 += V_30 -> V_177 . V_266 ;
V_708 += V_30 -> V_177 . V_178 ;
V_130 += V_30 -> V_83 . V_130 ;
V_104 += V_30 -> V_83 . V_104 ;
}
V_2 -> V_240 = V_240 ;
V_2 -> V_192 = V_192 ;
V_2 -> V_266 = V_266 ;
V_2 -> V_708 = V_708 ;
V_18 -> V_83 . V_714 = V_130 ;
V_18 -> V_83 . V_715 = V_104 ;
V_130 = 0 ;
V_104 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_21 = V_2 -> V_21 [ V_11 ] ;
V_135 += V_21 -> V_110 . V_135 ;
V_707 += V_21 -> V_110 . V_707 ;
V_130 += V_21 -> V_83 . V_130 ;
V_104 += V_21 -> V_83 . V_104 ;
}
V_2 -> V_135 = V_135 ;
V_2 -> V_707 = V_707 ;
V_18 -> V_83 . V_716 = V_130 ;
V_18 -> V_83 . V_717 = V_104 ;
V_82 -> V_718 += F_11 ( V_8 , V_719 ) ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_702 = F_11 ( V_8 , F_366 ( V_11 ) ) ;
V_701 += V_702 ;
V_82 -> V_702 [ V_11 ] += V_702 ;
V_700 += V_82 -> V_702 [ V_11 ] ;
V_82 -> V_720 [ V_11 ] += F_11 ( V_8 , F_367 ( V_11 ) ) ;
V_82 -> V_721 [ V_11 ] += F_11 ( V_8 , F_368 ( V_11 ) ) ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_82 -> V_722 [ V_11 ] += F_11 ( V_8 , F_369 ( V_11 ) ) ;
V_82 -> V_723 [ V_11 ] += F_11 ( V_8 , F_370 ( V_11 ) ) ;
V_82 -> V_724 [ V_11 ] += F_11 ( V_8 , F_371 ( V_11 ) ) ;
V_82 -> V_725 [ V_11 ] +=
F_11 ( V_8 , F_372 ( V_11 ) ) ;
break;
case V_72 :
case V_73 :
V_82 -> V_725 [ V_11 ] +=
F_11 ( V_8 , F_373 ( V_11 ) ) ;
break;
default:
break;
}
}
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ ) {
V_82 -> V_726 [ V_11 ] += F_11 ( V_8 , F_374 ( V_11 ) ) ;
V_82 -> V_727 [ V_11 ] += F_11 ( V_8 , F_375 ( V_11 ) ) ;
if ( ( V_8 -> V_69 . type == V_72 ) ||
( V_8 -> V_69 . type == V_73 ) ) {
V_82 -> V_723 [ V_11 ] += F_11 ( V_8 , F_376 ( V_11 ) ) ;
F_11 ( V_8 , F_377 ( V_11 ) ) ;
V_82 -> V_724 [ V_11 ] += F_11 ( V_8 , F_378 ( V_11 ) ) ;
F_11 ( V_8 , F_379 ( V_11 ) ) ;
}
}
V_82 -> V_728 += F_11 ( V_8 , V_729 ) ;
V_82 -> V_728 -= V_701 ;
F_57 ( V_2 ) ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_82 -> V_730 += F_11 ( V_8 , V_731 ) ;
V_82 -> V_732 += F_11 ( V_8 , V_733 ) ;
V_82 -> V_734 += F_11 ( V_8 , V_735 ) ;
V_82 -> V_736 += F_11 ( V_8 , V_737 ) ;
break;
case V_73 :
V_82 -> V_738 += F_11 ( V_8 , V_739 ) ;
V_82 -> V_740 += F_11 ( V_8 , V_741 ) ;
V_82 -> V_742 += F_11 ( V_8 , V_743 ) ;
V_82 -> V_744 += F_11 ( V_8 , V_745 ) ;
case V_72 :
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
V_2 -> V_746 +=
F_11 ( V_8 , F_380 ( V_11 ) ) ;
V_82 -> V_732 += F_11 ( V_8 , V_747 ) ;
F_11 ( V_8 , V_733 ) ;
V_82 -> V_734 += F_11 ( V_8 , V_748 ) ;
F_11 ( V_8 , V_735 ) ;
V_82 -> V_736 += F_11 ( V_8 , V_749 ) ;
F_11 ( V_8 , V_737 ) ;
V_82 -> V_730 += F_11 ( V_8 , V_750 ) ;
V_82 -> V_751 += F_11 ( V_8 , V_752 ) ;
V_82 -> V_753 += F_11 ( V_8 , V_754 ) ;
#ifdef F_122
V_82 -> V_755 += F_11 ( V_8 , V_756 ) ;
V_82 -> V_757 += F_11 ( V_8 , V_758 ) ;
V_82 -> V_759 += F_11 ( V_8 , V_760 ) ;
V_82 -> V_761 += F_11 ( V_8 , V_762 ) ;
V_82 -> V_763 += F_11 ( V_8 , V_764 ) ;
V_82 -> V_765 += F_11 ( V_8 , V_766 ) ;
if ( V_550 -> V_767 && V_550 -> V_768 ) {
F_381 (cpu) {
V_710 +=
* F_382 ( V_550 -> V_767 , V_136 ) ;
V_711 +=
* F_382 ( V_550 ->
V_768 , V_136 ) ;
}
}
V_82 -> V_769 = V_710 ;
V_82 -> V_770 = V_711 ;
#endif
break;
default:
break;
}
V_703 = F_11 ( V_8 , V_771 ) ;
V_82 -> V_703 += V_703 ;
V_82 -> V_772 += F_11 ( V_8 , V_773 ) ;
if ( V_8 -> V_69 . type == V_70 )
V_82 -> V_772 -= V_703 ;
V_82 -> V_774 += F_11 ( V_8 , V_775 ) ;
V_82 -> V_776 += F_11 ( V_8 , V_777 ) ;
V_82 -> V_778 += F_11 ( V_8 , V_779 ) ;
V_82 -> V_780 += F_11 ( V_8 , V_781 ) ;
V_82 -> V_782 += F_11 ( V_8 , V_783 ) ;
V_82 -> V_784 += F_11 ( V_8 , V_785 ) ;
V_82 -> V_786 += F_11 ( V_8 , V_787 ) ;
V_82 -> V_788 += F_11 ( V_8 , V_789 ) ;
V_704 = F_11 ( V_8 , V_790 ) ;
V_82 -> V_791 += V_704 ;
V_705 = F_11 ( V_8 , V_792 ) ;
V_82 -> V_793 += V_705 ;
V_82 -> V_794 += F_11 ( V_8 , V_795 ) ;
V_82 -> V_796 += F_11 ( V_8 , V_797 ) ;
V_706 = V_704 + V_705 ;
V_82 -> V_794 -= V_706 ;
V_82 -> V_796 -= V_706 ;
V_82 -> V_734 -= ( V_706 * ( V_798 + V_440 ) ) ;
V_82 -> V_799 += F_11 ( V_8 , V_800 ) ;
V_82 -> V_801 += F_11 ( V_8 , V_802 ) ;
V_82 -> V_803 += F_11 ( V_8 , V_804 ) ;
V_82 -> V_805 += F_11 ( V_8 , V_806 ) ;
V_82 -> V_807 += F_11 ( V_8 , V_808 ) ;
V_82 -> V_807 -= V_706 ;
V_82 -> V_809 += F_11 ( V_8 , V_810 ) ;
V_82 -> V_811 += F_11 ( V_8 , V_812 ) ;
V_82 -> V_813 += F_11 ( V_8 , V_814 ) ;
V_82 -> V_815 += F_11 ( V_8 , V_816 ) ;
V_82 -> V_817 += F_11 ( V_8 , V_818 ) ;
V_82 -> V_819 += F_11 ( V_8 , V_820 ) ;
V_18 -> V_83 . V_821 = V_82 -> V_772 ;
V_18 -> V_83 . V_822 = V_82 -> V_718 + V_82 -> V_788 ;
V_18 -> V_83 . V_823 = 0 ;
V_18 -> V_83 . V_824 = V_82 -> V_788 ;
V_18 -> V_83 . V_825 = V_82 -> V_718 ;
V_18 -> V_83 . V_826 = V_700 ;
}
static void F_383 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_11 ;
if ( ! ( V_2 -> V_113 & V_341 ) )
return;
V_2 -> V_113 &= ~ V_341 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
if ( ! ( V_2 -> V_98 & V_340 ) )
return;
V_2 -> V_827 ++ ;
if ( F_384 ( V_8 ) == 0 ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_207 ( V_349 ,
& ( V_2 -> V_21 [ V_11 ] -> V_4 ) ) ;
F_45 ( V_8 , V_332 , V_342 ) ;
} else {
F_77 ( V_133 , L_91
L_92 ) ;
}
}
static void F_385 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_828 = 0 ;
int V_11 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_611 , & V_2 -> V_4 ) )
return;
if ( F_83 ( V_2 -> V_18 ) ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_386 ( V_2 -> V_21 [ V_11 ] ) ;
}
if ( ! ( V_2 -> V_98 & V_152 ) ) {
F_45 ( V_8 , V_78 ,
( V_829 | V_830 ) ) ;
} else {
for ( V_11 = 0 ; V_11 < V_2 -> V_153 - V_154 ; V_11 ++ ) {
struct V_115 * V_831 = V_2 -> V_116 [ V_11 ] ;
if ( V_831 -> V_273 . V_79 || V_831 -> V_120 . V_79 )
V_828 |= ( ( T_2 ) 1 << V_11 ) ;
}
}
F_49 ( V_2 , V_828 ) ;
}
static void F_387 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_832 = V_2 -> V_832 ;
bool V_316 = V_2 -> V_316 ;
bool V_94 = V_2 -> V_95 . V_96 ;
if ( ! ( V_2 -> V_98 & V_328 ) )
return;
if ( V_8 -> V_69 . V_313 . V_314 ) {
V_8 -> V_69 . V_313 . V_314 ( V_8 , & V_832 , & V_316 , false ) ;
} else {
V_832 = V_833 ;
V_316 = true ;
}
if ( V_2 -> V_97 )
V_94 |= ! ! ( V_2 -> V_97 -> V_94 ) ;
if ( V_316 && ! ( ( V_2 -> V_98 & V_99 ) && V_94 ) ) {
V_8 -> V_69 . V_313 . V_834 ( V_8 ) ;
F_388 ( V_2 ) ;
}
if ( V_316 ||
F_389 ( V_132 , ( V_2 -> V_329 +
V_835 ) ) ) {
V_2 -> V_98 &= ~ V_328 ;
F_45 ( V_8 , V_332 , V_331 ) ;
F_177 ( V_8 ) ;
}
V_2 -> V_316 = V_316 ;
V_2 -> V_832 = V_832 ;
}
static void F_390 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_832 = V_2 -> V_832 ;
bool V_836 , V_837 ;
if ( F_83 ( V_18 ) )
return;
V_2 -> V_113 &= ~ V_582 ;
switch ( V_8 -> V_69 . type ) {
case V_70 : {
T_1 V_838 = F_11 ( V_8 , V_515 ) ;
T_1 V_839 = F_11 ( V_8 , V_840 ) ;
V_836 = ! ! ( V_838 & V_841 ) ;
V_837 = ! ! ( V_839 & V_842 ) ;
}
break;
case V_73 :
case V_72 : {
T_1 V_843 = F_11 ( V_8 , V_844 ) ;
T_1 V_845 = F_11 ( V_8 , V_846 ) ;
V_836 = ! ! ( V_843 & V_847 ) ;
V_837 = ! ! ( V_845 & V_848 ) ;
}
break;
default:
V_837 = false ;
V_836 = false ;
break;
}
#ifdef F_69
F_391 ( V_2 ) ;
#endif
F_79 ( V_131 , L_93 ,
( V_832 == V_833 ?
L_94 :
( V_832 == V_849 ?
L_95 :
( V_832 == V_850 ?
L_96 :
L_97 ) ) ) ,
( ( V_836 && V_837 ) ? L_98 :
( V_836 ? L_99 :
( V_837 ? L_100 : L_101 ) ) ) ) ;
F_392 ( V_18 ) ;
F_393 ( V_2 ) ;
}
static void F_394 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
V_2 -> V_316 = false ;
V_2 -> V_832 = 0 ;
if ( ! F_83 ( V_18 ) )
return;
if ( F_287 ( V_8 ) && V_8 -> V_69 . type == V_70 )
V_2 -> V_113 |= V_582 ;
#ifdef F_69
F_391 ( V_2 ) ;
#endif
F_79 ( V_131 , L_102 ) ;
F_314 ( V_18 ) ;
}
static void F_395 ( struct V_1 * V_2 )
{
int V_11 ;
int V_851 = 0 ;
if ( ! F_83 ( V_2 -> V_18 ) ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_21 = V_2 -> V_21 [ V_11 ] ;
if ( V_21 -> V_44 != V_21 -> V_43 ) {
V_851 = 1 ;
break;
}
}
if ( V_851 ) {
V_2 -> V_113 |= V_114 ;
}
}
}
static void F_396 ( struct V_1 * V_2 )
{
T_1 V_852 ;
if ( V_2 -> V_8 . V_69 . type == V_70 )
return;
V_852 = F_11 ( & V_2 -> V_8 , V_853 ) ;
if ( ! V_852 )
return;
F_270 ( V_131 , L_103 , V_852 ) ;
}
static void F_397 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_611 , & V_2 -> V_4 ) )
return;
F_387 ( V_2 ) ;
if ( V_2 -> V_316 )
F_390 ( V_2 ) ;
else
F_394 ( V_2 ) ;
F_396 ( V_2 ) ;
F_365 ( V_2 ) ;
F_395 ( V_2 ) ;
}
static void F_398 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_13 V_356 ;
if ( ! ( V_2 -> V_113 & V_582 ) &&
! ( V_2 -> V_113 & V_325 ) )
return;
if ( F_3 ( V_612 , & V_2 -> V_4 ) )
return;
V_356 = V_8 -> V_317 . V_313 . V_854 ( V_8 ) ;
if ( V_356 == V_615 )
goto V_855;
if ( V_356 == V_614 ) {
V_2 -> V_113 |= V_325 ;
}
if ( V_356 )
goto V_855;
if ( ! ( V_2 -> V_113 & V_325 ) )
goto V_855;
V_2 -> V_113 &= ~ V_325 ;
if ( V_8 -> V_69 . type == V_70 )
V_356 = V_8 -> V_317 . V_313 . V_856 ( V_8 ) ;
else
V_356 = V_8 -> V_69 . V_313 . V_857 ( V_8 ) ;
if ( V_356 == V_615 )
goto V_855;
V_2 -> V_98 |= V_326 ;
F_79 ( V_133 , L_104 , V_8 -> V_317 . V_858 ) ;
V_855:
F_8 ( V_612 , & V_2 -> V_4 ) ;
if ( ( V_356 == V_615 ) &&
( V_2 -> V_18 -> V_859 == V_860 ) ) {
F_302 ( L_105
L_106 ) ;
F_302 ( L_107
L_108 ) ;
F_399 ( V_2 -> V_18 ) ;
}
}
static void F_400 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_315 ;
bool V_583 ;
if ( ! ( V_2 -> V_98 & V_326 ) )
return;
if ( F_3 ( V_612 , & V_2 -> V_4 ) )
return;
V_2 -> V_98 &= ~ V_326 ;
V_315 = V_8 -> V_317 . V_586 ;
if ( ( ! V_315 ) && ( V_8 -> V_69 . V_313 . V_587 ) )
V_8 -> V_69 . V_313 . V_587 ( V_8 , & V_315 , & V_583 ) ;
if ( V_8 -> V_69 . V_313 . V_588 )
V_8 -> V_69 . V_313 . V_588 ( V_8 , V_315 , V_583 , true ) ;
V_2 -> V_98 |= V_328 ;
V_2 -> V_329 = V_132 ;
F_8 ( V_612 , & V_2 -> V_4 ) ;
}
static void F_401 ( struct V_1 * V_2 )
{
int V_861 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_862 ;
T_1 V_863 , V_864 ;
V_862 = F_11 ( V_8 , V_865 ) ;
if ( V_862 )
return;
for ( V_861 = 0 ; V_861 < V_2 -> V_276 ; V_861 ++ ) {
V_863 = ( V_861 << 16 ) | 0x80000000 ;
V_863 |= V_866 ;
F_45 ( V_8 , V_867 , V_863 ) ;
V_864 = F_11 ( V_8 , V_868 ) ;
V_863 &= 0x7FFFFFFF ;
F_45 ( V_8 , V_867 , V_863 ) ;
V_864 >>= 16 ;
if ( V_864 & V_869 ) {
F_402 ( V_18 , L_109 , V_861 ) ;
V_863 = ( V_861 << 16 ) | 0x80000000 ;
V_863 |= 0xA8 ;
F_45 ( V_8 , V_867 , V_863 ) ;
V_864 = 0x00008000 ;
F_45 ( V_8 , V_868 , V_864 ) ;
V_863 &= 0x7FFFFFFF ;
F_45 ( V_8 , V_867 , V_863 ) ;
}
}
}
static void F_403 ( unsigned long V_84 )
{
struct V_1 * V_2 = (struct V_1 * ) V_84 ;
unsigned long V_870 ;
bool V_871 = true ;
if ( V_2 -> V_98 & V_328 )
V_870 = V_872 / 10 ;
else
V_870 = V_872 * 2 ;
#ifdef F_404
if ( ! V_2 -> V_276 ||
( V_2 -> V_98 & V_328 ) )
goto V_873;
F_401 ( V_2 ) ;
V_870 = V_872 / 50 ;
V_2 -> V_874 ++ ;
if ( V_2 -> V_874 >= 100 )
V_2 -> V_874 = 0 ;
else
V_871 = false ;
V_873:
#endif
F_294 ( & V_2 -> V_609 , V_870 + V_132 ) ;
if ( V_871 )
F_1 ( V_2 ) ;
}
static void F_405 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_113 & V_114 ) )
return;
V_2 -> V_113 &= ~ V_114 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_611 , & V_2 -> V_4 ) )
return;
F_28 ( V_2 ) ;
F_402 ( V_2 -> V_18 , L_110 ) ;
V_2 -> V_134 ++ ;
F_295 ( V_2 ) ;
}
static void F_406 ( struct V_875 * V_876 )
{
struct V_1 * V_2 = F_190 ( V_876 ,
struct V_1 ,
V_6 ) ;
F_405 ( V_2 ) ;
F_398 ( V_2 ) ;
F_400 ( V_2 ) ;
F_171 ( V_2 ) ;
F_397 ( V_2 ) ;
F_383 ( V_2 ) ;
F_385 ( V_2 ) ;
#ifdef F_69
F_407 ( V_2 ) ;
#endif
F_5 ( V_2 ) ;
}
static int F_408 ( struct V_20 * V_21 ,
struct V_22 * V_877 ,
T_4 * V_226 )
{
struct V_160 * V_53 = V_877 -> V_53 ;
T_1 V_878 , V_879 ;
T_1 V_880 , V_881 ;
if ( ! F_409 ( V_53 ) )
return 0 ;
if ( F_410 ( V_53 ) ) {
int V_356 = F_411 ( V_53 , 0 , 0 , V_189 ) ;
if ( V_356 )
return V_356 ;
}
V_879 = V_882 ;
if ( V_877 -> V_208 == F_121 ( V_216 ) ) {
struct V_205 * V_883 = F_412 ( V_53 ) ;
V_883 -> V_884 = 0 ;
V_883 -> V_885 = 0 ;
F_413 ( V_53 ) -> V_885 = ~ F_414 ( V_883 -> V_886 ,
V_883 -> V_887 , 0 ,
V_219 ,
0 ) ;
V_879 |= V_888 ;
V_877 -> V_127 |= V_889 |
V_890 |
V_891 ;
} else if ( F_415 ( V_53 ) ) {
F_416 ( V_53 ) -> V_892 = 0 ;
F_413 ( V_53 ) -> V_885 =
~ F_417 ( & F_416 ( V_53 ) -> V_886 ,
& F_416 ( V_53 ) -> V_887 ,
0 , V_219 , 0 ) ;
V_877 -> V_127 |= V_889 |
V_890 ;
}
V_881 = F_418 ( V_53 ) ;
* V_226 = F_419 ( V_53 ) + V_881 ;
V_877 -> V_126 = F_128 ( V_53 ) -> V_126 ;
V_877 -> V_125 += ( V_877 -> V_126 - 1 ) * * V_226 ;
V_880 = V_881 << V_893 ;
V_880 |= F_128 ( V_53 ) -> V_227 << V_894 ;
V_880 |= 1 << V_895 ;
V_878 = F_420 ( V_53 ) ;
V_878 |= F_421 ( V_53 ) << V_896 ;
V_878 |= V_877 -> V_127 & V_897 ;
F_422 ( V_21 , V_878 , 0 , V_879 ,
V_880 ) ;
return 1 ;
}
static void F_423 ( struct V_20 * V_21 ,
struct V_22 * V_877 )
{
struct V_160 * V_53 = V_877 -> V_53 ;
T_1 V_878 = 0 ;
T_1 V_880 = 0 ;
T_1 V_879 = 0 ;
if ( V_53 -> V_183 != V_898 ) {
if ( ! ( V_877 -> V_127 & V_899 ) &&
! ( V_877 -> V_127 & V_900 ) )
return;
} else {
T_4 V_901 = 0 ;
switch ( V_877 -> V_208 ) {
case F_121 ( V_216 ) :
V_878 |= F_420 ( V_53 ) ;
V_879 |= V_888 ;
V_901 = F_412 ( V_53 ) -> V_208 ;
break;
case F_121 ( V_902 ) :
V_878 |= F_420 ( V_53 ) ;
V_901 = F_416 ( V_53 ) -> V_209 ;
break;
default:
if ( F_70 ( F_424 () ) ) {
F_425 ( V_21 -> V_37 ,
L_111 ,
V_877 -> V_208 ) ;
}
break;
}
switch ( V_901 ) {
case V_219 :
V_879 |= V_882 ;
V_880 = F_418 ( V_53 ) <<
V_893 ;
break;
case V_903 :
V_879 |= V_904 ;
V_880 = sizeof( struct V_905 ) <<
V_893 ;
break;
case V_906 :
V_880 = sizeof( struct V_907 ) <<
V_893 ;
break;
default:
if ( F_70 ( F_424 () ) ) {
F_425 ( V_21 -> V_37 ,
L_112 ,
V_901 ) ;
}
break;
}
V_877 -> V_127 |= V_890 ;
}
V_878 |= F_421 ( V_53 ) << V_896 ;
V_878 |= V_877 -> V_127 & V_897 ;
F_422 ( V_21 , V_878 , 0 ,
V_879 , V_880 ) ;
}
static T_9 F_426 ( T_1 V_127 )
{
T_9 V_908 = F_68 ( V_909 |
V_910 |
V_911 ) ;
if ( V_127 & V_899 )
V_908 |= F_68 ( V_912 ) ;
#ifdef F_69
if ( V_127 & V_128 )
V_908 |= F_68 ( V_913 ) ;
#endif
#ifdef F_122
if ( V_127 & ( V_889 | V_914 ) )
#else
if ( V_127 & V_889 )
#endif
V_908 |= F_68 ( V_915 ) ;
return V_908 ;
}
static void F_427 ( union V_24 * V_25 ,
T_1 V_127 , unsigned int V_916 )
{
T_9 V_917 = F_68 ( V_916 << V_918 ) ;
if ( V_127 & V_890 )
V_917 |= F_68 ( V_919 ) ;
if ( V_127 & V_891 )
V_917 |= F_68 ( V_920 ) ;
#ifdef F_122
if ( V_127 & ( V_889 | V_921 ) )
#else
if ( V_127 & V_889 )
#endif
V_917 |= F_68 ( 1 << V_895 ) ;
#ifdef F_122
if ( V_127 & ( V_900 | V_921 ) )
#else
if ( V_127 & V_900 )
#endif
V_917 |= F_68 ( V_922 ) ;
V_25 -> V_196 . V_917 = V_917 ;
}
static void F_428 ( struct V_20 * V_21 ,
struct V_22 * V_877 ,
const T_4 V_226 )
{
T_7 V_45 ;
struct V_160 * V_53 = V_877 -> V_53 ;
struct V_22 * V_23 ;
union V_24 * V_25 ;
struct V_241 * V_242 = & F_128 ( V_53 ) -> V_243 [ 0 ] ;
unsigned int V_249 = V_53 -> V_249 ;
unsigned int V_258 = F_127 ( V_53 ) ;
unsigned int V_916 = V_53 -> V_46 - V_226 ;
T_1 V_127 = V_877 -> V_127 ;
T_9 V_908 ;
T_5 V_11 = V_21 -> V_44 ;
V_25 = F_35 ( V_21 , V_11 ) ;
F_427 ( V_25 , V_127 , V_916 ) ;
V_908 = F_426 ( V_127 ) ;
#ifdef F_122
if ( V_127 & V_921 ) {
if ( V_249 < sizeof( struct V_272 ) ) {
V_258 -= sizeof( struct V_272 ) - V_249 ;
V_249 = 0 ;
} else {
V_249 -= sizeof( struct V_272 ) ;
}
}
#endif
V_45 = F_429 ( V_21 -> V_37 , V_53 -> V_84 , V_258 , V_80 ) ;
if ( F_116 ( V_21 -> V_37 , V_45 ) )
goto V_923;
F_55 ( V_877 , V_46 , V_258 ) ;
F_430 ( V_877 , V_45 , V_45 ) ;
V_25 -> V_196 . V_924 = F_119 ( V_45 ) ;
for (; ; ) {
while ( F_70 ( V_258 > V_925 ) ) {
V_25 -> V_196 . V_926 =
V_908 | F_68 ( V_925 ) ;
V_11 ++ ;
V_25 ++ ;
if ( V_11 == V_21 -> V_52 ) {
V_25 = F_35 ( V_21 , 0 ) ;
V_11 = 0 ;
}
V_45 += V_925 ;
V_258 -= V_925 ;
V_25 -> V_196 . V_924 = F_119 ( V_45 ) ;
V_25 -> V_196 . V_917 = 0 ;
}
if ( F_73 ( ! V_249 ) )
break;
if ( F_70 ( V_53 -> V_927 ) )
V_908 &= ~ ( F_68 ( V_910 ) ) ;
V_25 -> V_196 . V_926 = V_908 | F_68 ( V_258 ) ;
V_11 ++ ;
V_25 ++ ;
if ( V_11 == V_21 -> V_52 ) {
V_25 = F_35 ( V_21 , 0 ) ;
V_11 = 0 ;
}
#ifdef F_122
V_258 = F_322 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_258 = F_144 ( V_242 ) ;
#endif
V_249 -= V_258 ;
V_45 = F_431 ( V_21 -> V_37 , V_242 , 0 , V_258 ,
V_80 ) ;
if ( F_116 ( V_21 -> V_37 , V_45 ) )
goto V_923;
V_23 = & V_21 -> V_42 [ V_11 ] ;
F_55 ( V_23 , V_46 , V_258 ) ;
F_430 ( V_23 , V_45 , V_45 ) ;
V_25 -> V_196 . V_924 = F_119 ( V_45 ) ;
V_25 -> V_196 . V_917 = 0 ;
V_242 ++ ;
}
V_908 |= F_68 ( V_258 ) | F_68 ( V_928 ) ;
V_25 -> V_196 . V_926 = V_908 ;
F_432 ( F_81 ( V_21 ) , V_877 -> V_125 ) ;
V_877 -> V_48 = V_132 ;
F_109 () ;
V_877 -> V_47 = V_25 ;
V_11 ++ ;
if ( V_11 == V_21 -> V_52 )
V_11 = 0 ;
V_21 -> V_44 = V_11 ;
F_110 ( V_11 , V_21 -> V_107 ) ;
return;
V_923:
F_333 ( V_21 -> V_37 , L_113 ) ;
for (; ; ) {
V_23 = & V_21 -> V_42 [ V_11 ] ;
F_51 ( V_21 , V_23 ) ;
if ( V_23 == V_877 )
break;
if ( V_11 == 0 )
V_11 = V_21 -> V_52 ;
V_11 -- ;
}
V_21 -> V_44 = V_11 ;
}
static void F_433 ( struct V_20 * V_79 ,
struct V_22 * V_877 )
{
struct V_115 * V_116 = V_79 -> V_116 ;
union V_929 V_930 = { . V_931 = 0 } ;
union V_929 V_932 = { . V_931 = 0 } ;
union {
unsigned char * V_200 ;
struct V_205 * V_206 ;
struct V_933 * V_934 ;
} V_207 ;
struct V_220 * V_935 ;
T_8 V_936 ;
if ( ! V_116 )
return;
if ( ! V_79 -> V_373 )
return;
V_79 -> V_374 ++ ;
V_207 . V_200 = F_434 ( V_877 -> V_53 ) ;
if ( ( V_877 -> V_208 != F_121 ( V_902 ) ||
V_207 . V_934 -> V_209 != V_219 ) &&
( V_877 -> V_208 != F_121 ( V_216 ) ||
V_207 . V_206 -> V_208 != V_219 ) )
return;
V_935 = F_413 ( V_877 -> V_53 ) ;
if ( ! V_935 || V_935 -> V_937 )
return;
if ( ! V_935 -> V_938 && ( V_79 -> V_374 < V_79 -> V_373 ) )
return;
V_79 -> V_374 = 0 ;
V_936 = F_435 ( V_877 -> V_127 >> V_939 ) ;
V_930 . V_940 . V_936 = V_936 ;
if ( V_877 -> V_127 & ( V_941 | V_899 ) )
V_932 . V_942 . V_943 ^= V_935 -> V_944 ^ F_121 ( V_213 ) ;
else
V_932 . V_942 . V_943 ^= V_935 -> V_944 ^ V_877 -> V_208 ;
V_932 . V_942 . V_945 ^= V_935 -> V_946 ;
if ( V_877 -> V_208 == F_121 ( V_216 ) ) {
V_930 . V_940 . V_947 = V_948 ;
V_932 . V_949 ^= V_207 . V_206 -> V_886 ^ V_207 . V_206 -> V_887 ;
} else {
V_930 . V_940 . V_947 = V_950 ;
V_932 . V_949 ^= V_207 . V_934 -> V_886 . V_951 [ 0 ] ^
V_207 . V_934 -> V_886 . V_951 [ 1 ] ^
V_207 . V_934 -> V_886 . V_951 [ 2 ] ^
V_207 . V_934 -> V_886 . V_951 [ 3 ] ^
V_207 . V_934 -> V_887 . V_951 [ 0 ] ^
V_207 . V_934 -> V_887 . V_951 [ 1 ] ^
V_207 . V_934 -> V_887 . V_951 [ 2 ] ^
V_207 . V_934 -> V_887 . V_951 [ 3 ] ;
}
F_436 ( & V_116 -> V_2 -> V_8 ,
V_930 , V_932 , V_79 -> V_50 ) ;
}
static int F_437 ( struct V_20 * V_21 , T_5 V_258 )
{
F_78 ( V_21 -> V_18 , V_21 -> V_50 ) ;
F_85 () ;
if ( F_73 ( F_84 ( V_21 ) < V_258 ) )
return - V_680 ;
F_438 ( V_21 -> V_18 , V_21 -> V_50 ) ;
++ V_21 -> V_110 . V_135 ;
return 0 ;
}
static inline int F_439 ( struct V_20 * V_21 , T_5 V_258 )
{
if ( F_73 ( F_84 ( V_21 ) >= V_258 ) )
return 0 ;
return F_437 ( V_21 , V_258 ) ;
}
static T_5 F_440 ( struct V_17 * V_37 , struct V_160 * V_53 )
{
struct V_1 * V_2 = F_62 ( V_37 ) ;
int V_952 = F_441 ( V_53 ) ? F_442 ( V_53 ) :
F_443 () ;
#ifdef F_122
T_8 V_208 = F_444 ( V_53 ) ;
if ( ( ( V_208 == F_435 ( V_217 ) ) ||
( V_208 == F_435 ( V_953 ) ) ) &&
( V_2 -> V_98 & V_471 ) ) {
V_952 &= ( V_2 -> V_399 [ V_643 ] . V_413 - 1 ) ;
V_952 += V_2 -> V_399 [ V_643 ] . V_76 ;
return V_952 ;
}
#endif
if ( V_2 -> V_98 & V_340 ) {
while ( F_70 ( V_952 >= V_37 -> V_954 ) )
V_952 -= V_37 -> V_954 ;
return V_952 ;
}
return F_445 ( V_37 , V_53 ) ;
}
T_14 F_446 ( struct V_160 * V_53 ,
struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_22 * V_877 ;
int V_955 ;
T_1 V_127 = 0 ;
#if V_404 > V_925
unsigned short V_956 ;
#endif
T_5 V_52 = F_447 ( F_127 ( V_53 ) ) ;
T_8 V_208 = V_53 -> V_208 ;
T_4 V_226 = 0 ;
#if V_404 > V_925
for ( V_956 = 0 ; V_956 < F_128 ( V_53 ) -> V_250 ; V_956 ++ )
V_52 += F_447 ( F_128 ( V_53 ) -> V_243 [ V_956 ] . V_258 ) ;
#else
V_52 += F_128 ( V_53 ) -> V_250 ;
#endif
if ( F_439 ( V_21 , V_52 + 3 ) ) {
V_21 -> V_110 . V_707 ++ ;
return V_957 ;
}
V_877 = & V_21 -> V_42 [ V_21 -> V_44 ] ;
V_877 -> V_53 = V_53 ;
V_877 -> V_125 = V_53 -> V_46 ;
V_877 -> V_126 = 1 ;
if ( F_448 ( V_53 ) ) {
V_127 |= F_449 ( V_53 ) << V_939 ;
V_127 |= V_899 ;
} else if ( V_208 == F_121 ( V_213 ) ) {
struct V_203 * V_958 , V_959 ;
V_958 = F_450 ( V_53 , V_211 , sizeof( V_959 ) , & V_959 ) ;
if ( ! V_958 )
goto V_960;
V_208 = V_958 -> V_215 ;
V_127 |= F_451 ( V_958 -> V_961 ) <<
V_939 ;
V_127 |= V_941 ;
}
F_452 ( V_53 ) ;
#ifdef F_69
if ( F_70 ( F_128 ( V_53 ) -> V_127 & V_962 ) ) {
F_128 ( V_53 ) -> V_127 |= V_963 ;
V_127 |= V_128 ;
}
#endif
#ifdef F_404
if ( V_2 -> V_98 & V_382 )
V_127 |= V_900 ;
#endif
if ( ( V_2 -> V_98 & V_99 ) &&
( ( V_127 & ( V_899 | V_941 ) ) ||
( V_53 -> V_964 != V_965 ) ) ) {
V_127 &= ~ V_966 ;
V_127 |= ( V_53 -> V_964 & 0x7 ) <<
V_967 ;
if ( V_127 & V_941 ) {
struct V_968 * V_958 ;
if ( F_410 ( V_53 ) &&
F_411 ( V_53 , 0 , 0 , V_189 ) )
goto V_960;
V_958 = (struct V_968 * ) V_53 -> V_84 ;
V_958 -> V_961 = F_435 ( V_127 >>
V_939 ) ;
} else {
V_127 |= V_899 ;
}
}
V_877 -> V_127 = V_127 ;
V_877 -> V_208 = V_208 ;
#ifdef F_122
if ( ( V_208 == F_121 ( V_217 ) ) &&
( V_2 -> V_98 & V_471 ) ) {
V_955 = F_453 ( V_21 , V_877 , & V_226 ) ;
if ( V_955 < 0 )
goto V_960;
goto V_969;
}
#endif
V_955 = F_408 ( V_21 , V_877 , & V_226 ) ;
if ( V_955 < 0 )
goto V_960;
else if ( ! V_955 )
F_423 ( V_21 , V_877 ) ;
if ( F_2 ( V_349 , & V_21 -> V_4 ) )
F_433 ( V_21 , V_877 ) ;
#ifdef F_122
V_969:
#endif
F_428 ( V_21 , V_877 , V_226 ) ;
F_439 ( V_21 , V_970 ) ;
return V_971 ;
V_960:
F_52 ( V_877 -> V_53 ) ;
V_877 -> V_53 = NULL ;
return V_971 ;
}
static T_14 F_454 ( struct V_160 * V_53 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_20 * V_21 ;
if ( V_53 -> V_46 <= 0 ) {
F_52 ( V_53 ) ;
return V_971 ;
}
if ( V_53 -> V_46 < 17 ) {
if ( F_455 ( V_53 , 17 ) )
return V_971 ;
V_53 -> V_46 = 17 ;
}
V_21 = V_2 -> V_21 [ V_53 -> V_972 ] ;
return F_446 ( V_53 , V_2 , V_21 ) ;
}
static int F_456 ( struct V_17 * V_18 , void * V_442 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_973 * V_508 = V_442 ;
if ( ! F_457 ( V_508 -> V_974 ) )
return - V_975 ;
memcpy ( V_18 -> V_976 , V_508 -> V_974 , V_18 -> V_977 ) ;
memcpy ( V_8 -> V_69 . V_508 , V_508 -> V_974 , V_18 -> V_977 ) ;
V_8 -> V_69 . V_313 . V_507 ( V_8 , 0 , V_8 -> V_69 . V_508 , V_2 -> V_276 ,
V_509 ) ;
return 0 ;
}
static int
F_458 ( struct V_17 * V_18 , int V_978 , int V_979 , T_5 V_508 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_5 V_980 ;
int V_981 ;
if ( V_978 != V_8 -> V_317 . V_982 . V_978 )
return - V_677 ;
V_981 = V_8 -> V_317 . V_313 . V_983 ( V_8 , V_508 , V_979 , & V_980 ) ;
if ( ! V_981 )
V_981 = V_980 ;
return V_981 ;
}
static int F_459 ( struct V_17 * V_18 , int V_978 , int V_979 ,
T_5 V_508 , T_5 V_980 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( V_978 != V_8 -> V_317 . V_982 . V_978 )
return - V_677 ;
return V_8 -> V_317 . V_313 . V_984 ( V_8 , V_508 , V_979 , V_980 ) ;
}
static int F_460 ( struct V_17 * V_18 , struct V_985 * V_986 , int V_987 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
switch ( V_987 ) {
#ifdef F_69
case V_988 :
return F_461 ( V_2 , V_986 , V_987 ) ;
#endif
default:
return F_462 ( & V_2 -> V_8 . V_317 . V_982 , F_463 ( V_986 ) , V_987 ) ;
}
}
static int F_464 ( struct V_17 * V_37 )
{
int V_356 = 0 ;
struct V_1 * V_2 = F_62 ( V_37 ) ;
struct V_989 * V_69 = & V_2 -> V_8 . V_69 ;
if ( F_457 ( V_69 -> V_990 ) ) {
F_353 () ;
V_356 = F_465 ( V_37 , V_69 -> V_990 , V_991 ) ;
F_355 () ;
}
return V_356 ;
}
static int F_466 ( struct V_17 * V_37 )
{
int V_356 = 0 ;
struct V_1 * V_2 = F_62 ( V_37 ) ;
struct V_989 * V_69 = & V_2 -> V_8 . V_69 ;
if ( F_457 ( V_69 -> V_990 ) ) {
F_353 () ;
V_356 = F_467 ( V_37 , V_69 -> V_990 , V_991 ) ;
F_355 () ;
}
return V_356 ;
}
static void F_468 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
int V_11 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
V_2 -> V_98 |= V_234 ;
if ( V_2 -> V_98 & V_152 ) {
int V_149 = V_2 -> V_153 - V_154 ;
for ( V_11 = 0 ; V_11 < V_149 ; V_11 ++ ) {
struct V_115 * V_116 = V_2 -> V_116 [ V_11 ] ;
F_187 ( 0 , V_116 ) ;
}
} else {
F_199 ( V_2 -> V_36 -> V_343 , V_18 ) ;
}
V_2 -> V_98 &= ~ V_234 ;
}
static struct V_992 * F_469 ( struct V_17 * V_18 ,
struct V_992 * V_83 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
int V_11 ;
F_470 () ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ ) {
struct V_20 * V_79 = F_471 ( V_2 -> V_30 [ V_11 ] ) ;
T_2 V_130 , V_104 ;
unsigned int V_993 ;
if ( V_79 ) {
do {
V_993 = F_472 ( & V_79 -> V_129 ) ;
V_104 = V_79 -> V_83 . V_104 ;
V_130 = V_79 -> V_83 . V_130 ;
} while ( F_473 ( & V_79 -> V_129 , V_993 ) );
V_83 -> V_715 += V_104 ;
V_83 -> V_714 += V_130 ;
}
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_79 = F_471 ( V_2 -> V_21 [ V_11 ] ) ;
T_2 V_130 , V_104 ;
unsigned int V_993 ;
if ( V_79 ) {
do {
V_993 = F_472 ( & V_79 -> V_129 ) ;
V_104 = V_79 -> V_83 . V_104 ;
V_130 = V_79 -> V_83 . V_130 ;
} while ( F_473 ( & V_79 -> V_129 , V_993 ) );
V_83 -> V_717 += V_104 ;
V_83 -> V_716 += V_130 ;
}
}
F_474 () ;
V_83 -> V_821 = V_18 -> V_83 . V_821 ;
V_83 -> V_822 = V_18 -> V_83 . V_822 ;
V_83 -> V_824 = V_18 -> V_83 . V_824 ;
V_83 -> V_825 = V_18 -> V_83 . V_825 ;
V_83 -> V_826 = V_18 -> V_83 . V_826 ;
return V_83 ;
}
static void F_475 ( struct V_1 * V_2 , T_4 V_102 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_378 , V_994 ;
int V_11 ;
if ( V_8 -> V_69 . type == V_70 )
return;
V_378 = F_11 ( V_8 , V_995 ) ;
V_994 = V_378 ;
for ( V_11 = 0 ; V_11 < V_538 ; V_11 ++ ) {
T_4 V_996 = V_378 >> ( V_11 * V_997 ) ;
if ( V_996 > V_102 )
V_378 &= ~ ( 0x7 << V_997 ) ;
}
if ( V_378 != V_994 )
F_45 ( V_8 , V_995 , V_378 ) ;
return;
}
int F_476 ( struct V_17 * V_37 , T_4 V_102 )
{
struct V_1 * V_2 = F_62 ( V_37 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( ! ( V_2 -> V_98 & V_152 ) ) {
F_77 ( V_131 , L_114 ) ;
return - V_677 ;
}
if ( V_2 -> V_98 & V_382 ) {
F_77 ( V_131 , L_115 ) ;
return - V_677 ;
}
if ( V_102 > V_2 -> V_95 . V_645 . V_646 ||
( V_8 -> V_69 . type == V_70 &&
V_102 < V_538 ) )
return - V_677 ;
if ( F_31 ( V_37 ) )
F_344 ( V_37 ) ;
F_360 ( V_2 ) ;
if ( V_102 ) {
F_477 ( V_37 , V_102 ) ;
V_2 -> V_98 |= V_99 ;
V_2 -> V_98 &= ~ V_340 ;
if ( V_2 -> V_8 . V_69 . type == V_70 ) {
V_2 -> V_998 = V_2 -> V_8 . V_85 . V_660 ;
V_2 -> V_8 . V_85 . V_660 = V_999 ;
}
} else {
F_478 ( V_37 ) ;
if ( V_2 -> V_8 . V_69 . type == V_70 )
V_2 -> V_8 . V_85 . V_660 = V_2 -> V_998 ;
V_2 -> V_98 &= ~ V_99 ;
V_2 -> V_98 |= V_340 ;
V_2 -> V_659 . V_96 = false ;
V_2 -> V_95 . V_96 = false ;
}
F_354 ( V_2 ) ;
F_475 ( V_2 , V_102 ) ;
if ( F_31 ( V_37 ) )
F_343 ( V_37 ) ;
return 0 ;
}
void F_479 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
if ( F_31 ( V_18 ) )
F_295 ( V_2 ) ;
else
F_301 ( V_2 ) ;
}
static T_15 F_480 ( struct V_17 * V_18 ,
T_15 V_161 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
if ( ! ( V_2 -> V_98 & V_416 ) )
V_161 &= ~ V_162 ;
if ( ! ( V_161 & V_174 ) )
V_161 &= ~ V_1000 ;
if ( ! ( V_2 -> V_113 & V_638 ) )
V_161 &= ~ V_1000 ;
return V_161 ;
}
static int F_481 ( struct V_17 * V_18 ,
T_15 V_161 )
{
struct V_1 * V_2 = F_62 ( V_18 ) ;
T_15 V_1001 = V_18 -> V_161 ^ V_161 ;
bool V_1002 = false ;
if ( ! ( V_161 & V_1000 ) ) {
if ( V_2 -> V_113 & V_478 )
V_1002 = true ;
V_2 -> V_113 &= ~ V_478 ;
} else if ( ( V_2 -> V_113 & V_638 ) &&
! ( V_2 -> V_113 & V_478 ) ) {
if ( V_2 -> V_282 == 1 ||
V_2 -> V_282 > V_1003 ) {
V_2 -> V_113 |= V_478 ;
V_1002 = true ;
} else if ( ( V_1001 ^ V_161 ) & V_1000 ) {
F_79 ( V_133 , L_116
L_117 ) ;
}
}
if ( ! ( V_161 & V_1004 ) ) {
if ( V_2 -> V_98 & V_556 ) {
if ( ( V_2 -> V_98 & V_416 ) &&
! ( V_2 -> V_98 & V_99 ) )
V_2 -> V_98 |= V_340 ;
V_1002 = true ;
}
V_2 -> V_98 &= ~ V_556 ;
} else if ( ! ( V_2 -> V_98 & V_556 ) ) {
V_2 -> V_98 &= ~ V_340 ;
V_2 -> V_98 |= V_556 ;
V_1002 = true ;
}
if ( V_161 & V_231 )
F_241 ( V_2 ) ;
else
F_240 ( V_2 ) ;
if ( V_1001 & V_248 )
V_1002 = true ;
V_18 -> V_161 = V_161 ;
if ( V_1002 )
F_479 ( V_18 ) ;
return 0 ;
}
static int F_482 ( struct V_1005 * V_1006 ,
struct V_17 * V_37 ,
unsigned char * V_508 ,
T_5 V_98 )
{
struct V_1 * V_2 = F_62 ( V_37 ) ;
int V_356 = - V_1007 ;
if ( V_1006 -> V_1008 & V_1009 ) {
F_25 ( L_118 ,
V_1010 ) ;
return - V_677 ;
}
if ( V_2 -> V_98 & V_382 ) {
if ( F_483 ( V_508 ) )
V_356 = F_484 ( V_37 , V_508 ) ;
else if ( F_485 ( V_508 ) )
V_356 = F_486 ( V_37 , V_508 ) ;
else
V_356 = - V_677 ;
}
if ( V_356 == - V_1011 && ! ( V_98 & V_1012 ) )
V_356 = 0 ;
return V_356 ;
}
static int F_487 ( struct V_1005 * V_1006 ,
struct V_17 * V_37 ,
unsigned char * V_508 )
{
struct V_1 * V_2 = F_62 ( V_37 ) ;
int V_356 = - V_1007 ;
if ( V_1006 -> V_1008 & V_1009 ) {
F_25 ( L_118 ,
V_1010 ) ;
return - V_677 ;
}
if ( V_2 -> V_98 & V_382 ) {
if ( F_483 ( V_508 ) )
V_356 = F_488 ( V_37 , V_508 ) ;
else if ( F_485 ( V_508 ) )
V_356 = F_489 ( V_37 , V_508 ) ;
else
V_356 = - V_677 ;
}
return V_356 ;
}
static int F_490 ( struct V_160 * V_53 ,
struct V_1013 * V_1014 ,
struct V_17 * V_37 ,
int V_1015 )
{
struct V_1 * V_2 = F_62 ( V_37 ) ;
if ( V_2 -> V_98 & V_382 )
V_1015 = F_491 ( V_53 , V_1014 , V_37 , V_1015 ) ;
return V_1015 ;
}
static void T_11 F_492 ( struct V_1 * V_2 ,
const struct V_1016 * V_1017 )
{
#ifdef F_404
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( V_8 -> V_69 . type == V_70 )
return;
V_2 -> V_276 = ( V_1018 > 63 ) ? 0 : V_1018 ;
F_493 ( V_2 , V_1017 ) ;
#endif
}
int F_494 ( struct V_1 * V_2 , T_5 V_309 ,
T_5 V_1019 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_5 V_1020 = V_2 -> V_1021 & V_1022 ;
int V_1023 = 0 ;
switch ( V_309 ) {
case V_1024 :
switch ( V_1019 ) {
case V_1025 :
if ( V_8 -> V_1026 . V_1027 != 0 )
break;
case V_1028 :
V_1023 = 1 ;
break;
}
break;
case V_1029 :
if ( V_1019 != V_1030 )
V_1023 = 1 ;
break;
case V_1031 :
V_1023 = 1 ;
break;
case V_1032 :
if ( ( V_1020 == V_1033 ) ||
( ( V_1020 == V_1034 ) &&
( V_8 -> V_1026 . V_1027 == 0 ) ) ) {
V_1023 = 1 ;
}
break;
}
return V_1023 ;
}
static int T_11 F_495 ( struct V_623 * V_36 ,
const struct V_1035 * V_1036 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 = NULL ;
struct V_7 * V_8 ;
const struct V_1016 * V_1017 = V_1037 [ V_1036 -> V_1038 ] ;
static int V_1039 ;
int V_11 , V_356 , V_1040 ;
T_4 V_1041 [ V_1042 ] ;
unsigned int V_413 = F_496 () ;
#ifdef F_122
T_5 V_1043 ;
#endif
T_1 V_1044 ;
if ( V_36 -> V_1045 ) {
F_497 ( 1 , V_1046 L_119 ,
F_498 ( V_36 ) , V_36 -> V_626 , V_36 -> V_155 ) ;
return - V_677 ;
}
V_356 = F_350 ( V_36 ) ;
if ( V_356 )
return V_356 ;
if ( ! F_499 ( & V_36 -> V_37 , F_206 ( 64 ) ) &&
! F_500 ( & V_36 -> V_37 , F_206 ( 64 ) ) ) {
V_1040 = 1 ;
} else {
V_356 = F_499 ( & V_36 -> V_37 , F_206 ( 32 ) ) ;
if ( V_356 ) {
V_356 = F_500 ( & V_36 -> V_37 ,
F_206 ( 32 ) ) ;
if ( V_356 ) {
F_333 ( & V_36 -> V_37 ,
L_120 ) ;
goto V_1047;
}
}
V_1040 = 0 ;
}
V_356 = F_501 ( V_36 , F_502 ( V_36 ,
V_1048 ) , V_1010 ) ;
if ( V_356 ) {
F_333 ( & V_36 -> V_37 ,
L_121 , V_356 ) ;
goto V_1049;
}
F_503 ( V_36 ) ;
F_351 ( V_36 ) ;
F_349 ( V_36 ) ;
#ifdef F_263
V_413 *= V_538 ;
#endif
if ( V_1017 -> V_69 == V_70 )
V_413 = F_322 (unsigned int, indices, IXGBE_MAX_RSS_INDICES) ;
else
V_413 = F_322 (unsigned int, indices, IXGBE_MAX_FDIR_INDICES) ;
#ifdef F_122
V_413 += F_322 (unsigned int, num_possible_cpus(),
IXGBE_MAX_FCOE_INDICES) ;
#endif
V_18 = F_504 ( sizeof( struct V_1 ) , V_413 ) ;
if ( ! V_18 ) {
V_356 = - V_504 ;
goto V_1050;
}
F_505 ( V_18 , & V_36 -> V_37 ) ;
V_2 = F_62 ( V_18 ) ;
F_506 ( V_36 , V_2 ) ;
V_2 -> V_18 = V_18 ;
V_2 -> V_36 = V_36 ;
V_8 = & V_2 -> V_8 ;
V_8 -> V_1051 = V_2 ;
V_2 -> V_1052 = F_507 ( V_1053 , V_1054 ) ;
V_8 -> V_372 = F_508 ( F_509 ( V_36 , 0 ) ,
F_510 ( V_36 , 0 ) ) ;
if ( ! V_8 -> V_372 ) {
V_356 = - V_671 ;
goto V_1055;
}
for ( V_11 = 1 ; V_11 <= 5 ; V_11 ++ ) {
if ( F_510 ( V_36 , V_11 ) == 0 )
continue;
}
V_18 -> V_1056 = & V_1057 ;
F_511 ( V_18 ) ;
V_18 -> V_1058 = 5 * V_872 ;
strncpy ( V_18 -> V_16 , F_498 ( V_36 ) , sizeof( V_18 -> V_16 ) - 1 ) ;
V_2 -> V_1059 = V_1039 ;
memcpy ( & V_8 -> V_69 . V_313 , V_1017 -> V_1060 , sizeof( V_8 -> V_69 . V_313 ) ) ;
V_8 -> V_69 . type = V_1017 -> V_69 ;
memcpy ( & V_8 -> V_1061 . V_313 , V_1017 -> V_1062 , sizeof( V_8 -> V_1061 . V_313 ) ) ;
V_1044 = F_11 ( V_8 , V_1063 ) ;
if ( ! ( V_1044 & ( 1 << 8 ) ) )
V_8 -> V_1061 . V_313 . V_196 = & V_1064 ;
memcpy ( & V_8 -> V_317 . V_313 , V_1017 -> V_1065 , sizeof( V_8 -> V_317 . V_313 ) ) ;
V_8 -> V_317 . V_858 = V_1066 ;
V_8 -> V_317 . V_982 . V_978 = V_1067 ;
V_8 -> V_317 . V_982 . V_1068 = 0 ;
V_8 -> V_317 . V_982 . V_1069 = V_1070 | V_1071 ;
V_8 -> V_317 . V_982 . V_37 = V_18 ;
V_8 -> V_317 . V_982 . V_1072 = F_458 ;
V_8 -> V_317 . V_982 . V_1073 = F_459 ;
V_1017 -> V_1074 ( V_8 ) ;
V_356 = F_321 ( V_2 ) ;
if ( V_356 )
goto V_1075;
switch ( V_2 -> V_8 . V_69 . type ) {
case V_72 :
case V_73 :
F_45 ( & V_2 -> V_8 , V_685 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_98 & V_320 ) {
T_1 V_606 = F_11 ( V_8 , V_607 ) ;
if ( V_606 & V_608 )
F_172 ( V_133 , L_54 ) ;
}
if ( V_1076 )
V_8 -> V_1076 = V_1076 ;
V_8 -> V_317 . V_1077 = true ;
V_356 = V_8 -> V_69 . V_313 . V_1078 ( V_8 ) ;
V_8 -> V_317 . V_1077 = false ;
if ( V_356 == V_614 &&
V_8 -> V_69 . type == V_70 ) {
V_356 = 0 ;
} else if ( V_356 == V_615 ) {
F_302 ( L_122
L_123 ) ;
F_302 ( L_124
L_125 ) ;
goto V_1075;
} else if ( V_356 ) {
F_302 ( L_126 , V_356 ) ;
goto V_1075;
}
F_492 ( V_2 , V_1017 ) ;
V_18 -> V_161 = V_1079 |
V_1080 |
V_1081 |
V_1082 |
V_231 |
V_1083 |
V_1084 |
V_1085 |
V_162 |
V_174 ;
V_18 -> V_1086 = V_18 -> V_161 ;
switch ( V_2 -> V_8 . V_69 . type ) {
case V_72 :
case V_73 :
V_18 -> V_161 |= V_1087 ;
V_18 -> V_1086 |= V_1087 |
V_1004 ;
break;
default:
break;
}
V_18 -> V_1086 |= V_248 ;
V_18 -> V_1088 |= V_1084 ;
V_18 -> V_1088 |= V_1085 ;
V_18 -> V_1088 |= V_1080 ;
V_18 -> V_1088 |= V_1081 ;
V_18 -> V_1088 |= V_1079 ;
V_18 -> V_1089 |= V_1090 ;
V_18 -> V_1089 |= V_1091 ;
if ( V_2 -> V_98 & V_382 )
V_2 -> V_98 &= ~ ( V_416 |
V_99 ) ;
#ifdef F_263
V_18 -> V_1092 = & V_1092 ;
#endif
#ifdef F_122
if ( V_2 -> V_98 & V_642 ) {
if ( V_8 -> V_69 . V_313 . V_1093 ) {
V_8 -> V_69 . V_313 . V_1093 ( V_8 , & V_1043 ) ;
if ( V_1043 & V_1094 )
V_2 -> V_98 &= ~ V_642 ;
}
}
if ( V_2 -> V_98 & V_642 ) {
V_18 -> V_1088 |= V_1095 ;
V_18 -> V_1088 |= V_1096 ;
V_18 -> V_1088 |= V_531 ;
}
#endif
if ( V_1040 ) {
V_18 -> V_161 |= V_1097 ;
V_18 -> V_1088 |= V_1097 ;
}
if ( V_2 -> V_113 & V_638 )
V_18 -> V_1086 |= V_1000 ;
if ( V_2 -> V_113 & V_478 )
V_18 -> V_161 |= V_1000 ;
if ( V_8 -> V_1061 . V_313 . V_1098 ( V_8 , NULL ) < 0 ) {
F_302 ( L_127 ) ;
V_356 = - V_671 ;
goto V_1075;
}
memcpy ( V_18 -> V_976 , V_8 -> V_69 . V_1099 , V_18 -> V_977 ) ;
memcpy ( V_18 -> V_1099 , V_8 -> V_69 . V_1099 , V_18 -> V_977 ) ;
if ( F_512 ( V_18 -> V_1099 ) ) {
F_302 ( L_128 ) ;
V_356 = - V_671 ;
goto V_1075;
}
F_513 ( & V_2 -> V_609 , & F_403 ,
( unsigned long ) V_2 ) ;
F_514 ( & V_2 -> V_6 , F_406 ) ;
F_8 ( V_5 , & V_2 -> V_4 ) ;
V_356 = F_354 ( V_2 ) ;
if ( V_356 )
goto V_1075;
if ( ! ( V_2 -> V_98 & V_416 ) ) {
V_18 -> V_1086 &= ~ V_162 ;
V_18 -> V_161 &= ~ V_162 ;
}
V_2 -> V_689 = 0 ;
V_8 -> V_1061 . V_313 . V_196 ( V_8 , 0x2c , & V_2 -> V_1021 ) ;
if ( F_494 ( V_2 , V_36 -> V_155 , V_36 -> V_632 ) )
V_2 -> V_689 = V_1100 ;
F_515 ( & V_2 -> V_36 -> V_37 , V_2 -> V_689 ) ;
#ifdef F_69
F_516 ( V_2 ) ;
#endif
V_8 -> V_1061 . V_313 . V_196 ( V_8 , 0x2e , & V_2 -> V_1101 ) ;
V_8 -> V_1061 . V_313 . V_196 ( V_8 , 0x2d , & V_2 -> V_1102 ) ;
V_8 -> V_69 . V_313 . V_1103 ( V_8 ) ;
F_517 ( L_129 ,
( V_8 -> V_1026 . V_1104 == V_1105 ? L_130 :
V_8 -> V_1026 . V_1104 == V_1106 ? L_131 :
L_132 ) ,
( V_8 -> V_1026 . V_1107 == V_1108 ? L_133 :
V_8 -> V_1026 . V_1107 == V_1109 ? L_134 :
V_8 -> V_1026 . V_1107 == V_1110 ? L_135 :
L_132 ) ,
V_18 -> V_976 ) ;
V_356 = F_518 ( V_8 , V_1041 , V_1042 ) ;
if ( V_356 )
strncpy ( V_1041 , L_132 , V_1042 ) ;
if ( F_287 ( V_8 ) && V_8 -> V_317 . V_858 != V_1111 )
F_517 ( L_136 ,
V_8 -> V_69 . type , V_8 -> V_317 . type , V_8 -> V_317 . V_858 ,
V_1041 ) ;
else
F_517 ( L_137 ,
V_8 -> V_69 . type , V_8 -> V_317 . type , V_1041 ) ;
if ( V_8 -> V_1026 . V_1107 <= V_1109 ) {
F_303 ( L_138
L_139 ) ;
F_303 ( L_140
L_141 ) ;
}
V_356 = V_8 -> V_69 . V_313 . V_1112 ( V_8 ) ;
if ( V_356 == V_617 ) {
F_303 ( L_76
L_142
L_143
L_144
L_80
L_81 ) ;
}
strcpy ( V_18 -> V_16 , L_145 ) ;
V_356 = F_519 ( V_18 ) ;
if ( V_356 )
goto V_1113;
if ( V_8 -> V_69 . V_313 . V_622 &&
( ( V_8 -> V_317 . V_603 ) ||
( ( V_8 -> V_69 . V_313 . V_604 ( V_8 ) == V_605 ) &&
( V_8 -> V_69 . type == V_72 ) ) ) )
V_8 -> V_69 . V_313 . V_622 ( V_8 ) ;
F_314 ( V_18 ) ;
#ifdef F_191
if ( F_100 ( & V_36 -> V_37 ) == 0 ) {
V_2 -> V_98 |= V_150 ;
F_97 ( V_2 ) ;
}
#endif
if ( V_2 -> V_98 & V_382 ) {
F_79 ( V_133 , L_146 , V_2 -> V_276 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_276 ; V_11 ++ )
F_520 ( V_36 , ( V_11 | 0x10000000 ) ) ;
}
if ( V_8 -> V_69 . V_313 . V_1114 )
V_8 -> V_69 . V_313 . V_1114 ( V_8 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_464 ( V_18 ) ;
F_517 ( L_147 , V_1115 ) ;
V_1039 ++ ;
#ifdef F_521
if ( F_522 ( V_2 ) )
F_77 ( V_133 , L_148 ) ;
#endif
return 0 ;
V_1113:
F_44 ( V_2 ) ;
F_360 ( V_2 ) ;
V_1075:
if ( V_2 -> V_98 & V_382 )
F_523 ( V_2 ) ;
V_2 -> V_113 &= ~ V_582 ;
F_524 ( V_8 -> V_372 ) ;
V_1055:
F_525 ( V_18 ) ;
V_1050:
F_526 ( V_36 ,
F_502 ( V_36 , V_1048 ) ) ;
V_1049:
V_1047:
F_361 ( V_36 ) ;
return V_356 ;
}
static void T_16 F_527 ( struct V_623 * V_36 )
{
struct V_1 * V_2 = F_346 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
F_207 ( V_3 , & V_2 -> V_4 ) ;
F_528 ( & V_2 -> V_6 ) ;
#ifdef F_69
F_529 ( V_2 ) ;
#endif
#ifdef F_191
if ( V_2 -> V_98 & V_150 ) {
V_2 -> V_98 &= ~ V_150 ;
F_101 ( & V_36 -> V_37 ) ;
F_45 ( & V_2 -> V_8 , V_151 , 1 ) ;
}
#endif
#ifdef F_521
F_530 ( V_2 ) ;
#endif
#ifdef F_122
if ( V_2 -> V_98 & V_471 )
F_531 ( V_2 ) ;
#endif
F_466 ( V_18 ) ;
if ( V_18 -> V_859 == V_860 )
F_399 ( V_18 ) ;
if ( V_2 -> V_98 & V_382 ) {
if ( ! ( F_532 ( V_2 ) ) )
F_523 ( V_2 ) ;
else
F_303 ( L_149
L_150 ) ;
}
F_360 ( V_2 ) ;
F_44 ( V_2 ) ;
#ifdef F_533
F_198 ( V_2 -> V_97 ) ;
F_198 ( V_2 -> V_536 ) ;
#endif
F_524 ( V_2 -> V_8 . V_372 ) ;
F_526 ( V_36 , F_502 ( V_36 ,
V_1048 ) ) ;
F_517 ( L_151 ) ;
F_525 ( V_18 ) ;
F_534 ( V_36 ) ;
F_361 ( V_36 ) ;
}
static T_17 F_535 ( struct V_623 * V_36 ,
T_18 V_4 )
{
struct V_1 * V_2 = F_346 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
#ifdef F_404
struct V_623 * V_1116 , * V_1117 ;
T_1 V_1118 , V_1119 , V_1120 , V_1121 ;
int V_861 , V_1122 ;
T_5 V_1123 , V_1124 ;
if ( V_2 -> V_8 . V_69 . type == V_70 ||
V_2 -> V_276 == 0 )
goto V_1125;
V_1116 = V_36 -> V_1026 -> V_1126 ;
while ( V_1116 && ( V_1116 -> V_1127 != V_1128 ) )
V_1116 = V_1116 -> V_1026 -> V_1126 ;
if ( ! V_1116 )
goto V_1125;
V_1122 = F_536 ( V_1116 , V_1129 ) ;
if ( ! V_1122 )
goto V_1125;
F_537 ( V_1116 , V_1122 + V_1130 , & V_1118 ) ;
F_537 ( V_1116 , V_1122 + V_1130 + 4 , & V_1119 ) ;
F_537 ( V_1116 , V_1122 + V_1130 + 8 , & V_1120 ) ;
F_537 ( V_1116 , V_1122 + V_1130 + 12 , & V_1121 ) ;
V_1123 = V_1119 >> 16 ;
if ( ! ( V_1123 & 0x0080 ) )
goto V_1125;
V_1124 = V_1123 & 0x01 ;
if ( ( V_1124 & 1 ) == ( V_36 -> V_1131 & 1 ) ) {
unsigned int V_309 ;
V_861 = ( V_1123 & 0x7F ) >> 1 ;
F_302 ( L_152 , V_861 ) ;
F_302 ( L_153
L_154 ,
V_1118 , V_1119 , V_1120 , V_1121 ) ;
switch ( V_2 -> V_8 . V_69 . type ) {
case V_72 :
V_309 = V_1132 ;
break;
case V_73 :
V_309 = V_1133 ;
break;
default:
V_309 = 0 ;
break;
}
V_1117 = F_538 ( V_1134 , V_309 , NULL ) ;
while ( V_1117 ) {
if ( V_1117 -> V_1131 == ( V_1123 & 0xFF ) )
break;
V_1117 = F_538 ( V_1134 ,
V_309 , V_1117 ) ;
}
if ( V_1117 ) {
F_302 ( L_155 , V_861 ) ;
F_539 ( V_1117 , 0xA8 , 0x00008000 ) ;
}
F_540 ( V_36 ) ;
}
V_2 -> V_1135 ++ ;
return V_1136 ;
V_1125:
#endif
F_359 ( V_18 ) ;
if ( V_4 == V_1137 )
return V_1138 ;
if ( F_31 ( V_18 ) )
F_298 ( V_2 ) ;
F_361 ( V_36 ) ;
return V_1139 ;
}
static T_17 F_541 ( struct V_623 * V_36 )
{
struct V_1 * V_2 = F_346 ( V_36 ) ;
T_17 V_1140 ;
int V_356 ;
if ( F_350 ( V_36 ) ) {
F_77 ( V_133 , L_156 ) ;
V_1140 = V_1138 ;
} else {
F_351 ( V_36 ) ;
F_348 ( V_36 ) ;
F_349 ( V_36 ) ;
F_352 ( V_36 , false ) ;
F_301 ( V_2 ) ;
F_45 ( & V_2 -> V_8 , V_685 , ~ 0 ) ;
V_1140 = V_1136 ;
}
V_356 = F_540 ( V_36 ) ;
if ( V_356 ) {
F_302 ( L_157
L_158 , V_356 ) ;
}
return V_1140 ;
}
static void F_542 ( struct V_623 * V_36 )
{
struct V_1 * V_2 = F_346 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
#ifdef F_404
if ( V_2 -> V_1135 ) {
F_79 ( V_131 , L_159 ) ;
V_2 -> V_1135 -- ;
return;
}
#endif
if ( F_31 ( V_18 ) )
F_300 ( V_2 ) ;
F_356 ( V_18 ) ;
}
static int T_19 F_543 ( void )
{
int V_112 ;
F_25 ( L_160 , V_1141 , V_1142 ) ;
F_25 ( L_147 , V_1143 ) ;
#ifdef F_191
F_544 ( & V_1144 ) ;
#endif
V_112 = F_545 ( & V_1145 ) ;
return V_112 ;
}
static void T_20 F_546 ( void )
{
#ifdef F_191
F_547 ( & V_1144 ) ;
#endif
F_548 ( & V_1145 ) ;
F_549 () ;
}
static int F_550 ( struct V_1146 * V_1147 , unsigned long V_156 ,
void * V_442 )
{
int V_1148 ;
V_1148 = F_551 ( & V_1145 . V_1149 , NULL , & V_156 ,
F_98 ) ;
return V_1148 ? V_1150 : V_1151 ;
}
