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
T_1 V_84 = 0 ;
T_1 V_85 [ 8 ] = { 0 } ;
int V_11 ;
if ( ( V_8 -> V_86 . V_87 == V_88 ) ||
( V_8 -> V_86 . V_87 == V_89 ) ) {
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_84 = F_11 ( V_8 , V_90 ) ;
break;
default:
V_84 = F_11 ( V_8 , V_91 ) ;
}
V_82 -> V_92 += V_84 ;
if ( ! V_84 )
return;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_8 ( V_93 ,
& V_2 -> V_21 [ V_11 ] -> V_4 ) ;
return;
} else if ( ! ( V_2 -> V_94 . V_95 ) )
return;
for ( V_11 = 0 ; V_11 < V_96 ; V_11 ++ ) {
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_85 [ V_11 ] = F_11 ( V_8 , F_57 ( V_11 ) ) ;
break;
default:
V_85 [ V_11 ] = F_11 ( V_8 , F_58 ( V_11 ) ) ;
}
V_82 -> V_97 [ V_11 ] += V_85 [ V_11 ] ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_21 = V_2 -> V_21 [ V_11 ] ;
T_4 V_98 = V_21 -> V_99 ;
if ( V_85 [ V_98 ] )
F_8 ( V_93 , & V_21 -> V_4 ) ;
}
}
static T_2 F_59 ( struct V_20 * V_79 )
{
return V_79 -> V_83 . V_100 ;
}
static T_2 F_60 ( struct V_20 * V_79 )
{
struct V_1 * V_2 = F_61 ( V_79 -> V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_101 = F_11 ( V_8 , F_22 ( V_79 -> V_102 ) ) ;
T_1 V_103 = F_11 ( V_8 , F_23 ( V_79 -> V_102 ) ) ;
if ( V_101 != V_103 )
return ( V_101 < V_103 ) ?
V_103 - V_101 : ( V_103 + V_79 -> V_52 - V_101 ) ;
return 0 ;
}
static inline bool F_62 ( struct V_20 * V_21 )
{
T_1 V_104 = F_59 ( V_21 ) ;
T_1 V_105 = V_21 -> V_106 . V_105 ;
T_1 V_107 = F_60 ( V_21 ) ;
bool V_108 = false ;
F_63 ( V_21 ) ;
if ( ( V_105 == V_104 ) && V_107 ) {
V_108 = F_3 ( V_93 ,
& V_21 -> V_4 ) ;
} else {
V_21 -> V_106 . V_105 = V_104 ;
F_8 ( V_93 , & V_21 -> V_4 ) ;
}
return V_108 ;
}
static void F_64 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_109 |= V_110 ;
F_1 ( V_2 ) ;
}
}
static bool F_65 ( struct V_111 * V_112 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
struct V_22 * V_23 ;
union V_24 * V_25 ;
unsigned int V_113 = 0 , V_114 = 0 ;
unsigned int V_115 = V_112 -> V_116 . V_117 ;
unsigned int V_11 = V_21 -> V_43 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return true ;
V_23 = & V_21 -> V_42 [ V_11 ] ;
V_25 = F_35 ( V_21 , V_11 ) ;
V_11 -= V_21 -> V_52 ;
do {
union V_24 * V_118 = V_23 -> V_47 ;
if ( ! V_118 )
break;
F_66 () ;
if ( ! ( V_118 -> V_57 . V_119 & F_67 ( V_120 ) ) )
break;
V_23 -> V_47 = NULL ;
V_113 += V_23 -> V_121 ;
V_114 += V_23 -> V_122 ;
F_52 ( V_23 -> V_53 ) ;
F_53 ( V_21 -> V_37 ,
F_32 ( V_23 , V_45 ) ,
F_33 ( V_23 , V_46 ) ,
V_80 ) ;
V_23 -> V_53 = NULL ;
F_55 ( V_23 , V_46 , 0 ) ;
while ( V_25 != V_118 ) {
V_23 ++ ;
V_25 ++ ;
V_11 ++ ;
if ( F_68 ( ! V_11 ) ) {
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
if ( F_68 ( ! V_11 ) ) {
V_11 -= V_21 -> V_52 ;
V_23 = V_21 -> V_42 ;
V_25 = F_35 ( V_21 , 0 ) ;
}
F_69 ( V_25 ) ;
V_115 -- ;
} while ( F_70 ( V_115 ) );
V_11 += V_21 -> V_52 ;
V_21 -> V_43 = V_11 ;
F_71 ( & V_21 -> V_123 ) ;
V_21 -> V_83 . V_124 += V_113 ;
V_21 -> V_83 . V_100 += V_114 ;
F_72 ( & V_21 -> V_123 ) ;
V_112 -> V_116 . V_113 += V_113 ;
V_112 -> V_116 . V_114 += V_114 ;
if ( F_73 ( V_21 ) && F_62 ( V_21 ) ) {
struct V_7 * V_8 = & V_2 -> V_8 ;
F_74 ( V_125 , L_42
L_43
L_44
L_45
L_46
L_47
L_48
L_49 ,
V_21 -> V_50 ,
F_11 ( V_8 , F_22 ( V_21 -> V_102 ) ) ,
F_11 ( V_8 , F_23 ( V_21 -> V_102 ) ) ,
V_21 -> V_44 , V_11 ,
V_21 -> V_42 [ V_11 ] . V_48 , V_126 ) ;
F_75 ( V_21 -> V_18 , V_21 -> V_50 ) ;
F_76 ( V_127 ,
L_50 ,
V_2 -> V_128 + 1 , V_21 -> V_50 ) ;
F_64 ( V_2 ) ;
return true ;
}
F_77 ( F_78 ( V_21 ) ,
V_114 , V_113 ) ;
#define F_79 (DESC_NEEDED * 2)
if ( F_68 ( V_114 && F_80 ( V_21 -> V_18 ) &&
( F_81 ( V_21 ) >= F_79 ) ) ) {
F_82 () ;
if ( F_83 ( V_21 -> V_18 ,
V_21 -> V_50 )
&& ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_84 ( V_21 -> V_18 ,
V_21 -> V_50 ) ;
++ V_21 -> V_106 . V_129 ;
}
}
return ! ! V_115 ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
int V_130 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_131 = F_86 ( V_21 -> V_37 , V_130 ) ;
T_5 V_132 ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_132 = F_87 ( V_21 -> V_102 ) ;
break;
case V_72 :
case V_73 :
V_132 = F_88 ( V_21 -> V_102 ) ;
V_131 <<= V_133 ;
break;
default:
return;
}
V_131 |= V_134 |
V_135 |
V_136 ;
F_45 ( V_8 , V_132 , V_131 ) ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_20 * V_30 ,
int V_130 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_137 = F_86 ( V_30 -> V_37 , V_130 ) ;
T_4 V_102 = V_30 -> V_102 ;
switch ( V_8 -> V_69 . type ) {
case V_72 :
case V_73 :
V_137 <<= V_138 ;
break;
default:
break;
}
V_137 |= V_139 |
V_140 |
V_141 ;
F_45 ( V_8 , F_12 ( V_102 ) , V_137 ) ;
}
static void F_90 ( struct V_111 * V_112 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
struct V_20 * V_79 ;
int V_130 = F_91 () ;
if ( V_112 -> V_130 == V_130 )
goto V_142;
F_92 (ring, q_vector->tx)
F_85 ( V_2 , V_79 , V_130 ) ;
F_92 (ring, q_vector->rx)
F_89 ( V_2 , V_79 , V_130 ) ;
V_112 -> V_130 = V_130 ;
V_142:
F_93 () ;
}
static void F_94 ( struct V_1 * V_2 )
{
int V_143 ;
int V_11 ;
if ( ! ( V_2 -> V_144 & V_145 ) )
return;
F_45 ( & V_2 -> V_8 , V_146 , 2 ) ;
if ( V_2 -> V_144 & V_147 )
V_143 = V_2 -> V_148 - V_149 ;
else
V_143 = 1 ;
for ( V_11 = 0 ; V_11 < V_143 ; V_11 ++ ) {
V_2 -> V_112 [ V_11 ] -> V_130 = - 1 ;
F_90 ( V_2 -> V_112 [ V_11 ] ) ;
}
}
static int F_95 ( struct V_150 * V_37 , void * V_84 )
{
struct V_1 * V_2 = F_96 ( V_37 ) ;
unsigned long V_151 = * ( unsigned long * ) V_84 ;
if ( ! ( V_2 -> V_144 & V_152 ) )
return 0 ;
switch ( V_151 ) {
case V_153 :
if ( V_2 -> V_144 & V_145 )
break;
if ( F_97 ( V_37 ) == 0 ) {
V_2 -> V_144 |= V_145 ;
F_94 ( V_2 ) ;
break;
}
case V_154 :
if ( V_2 -> V_144 & V_145 ) {
F_98 ( V_37 ) ;
V_2 -> V_144 &= ~ V_145 ;
F_45 ( & V_2 -> V_8 , V_146 , 1 ) ;
}
break;
}
return 0 ;
}
static inline void F_99 ( struct V_20 * V_79 ,
union V_31 * V_32 ,
struct V_155 * V_53 )
{
if ( V_79 -> V_18 -> V_156 & V_157 )
V_53 -> V_158 = F_42 ( V_32 -> V_57 . V_159 . V_160 . V_161 ) ;
}
static inline bool F_100 ( struct V_1 * V_2 ,
union V_31 * V_32 )
{
T_6 V_162 = V_32 -> V_57 . V_159 . V_163 . V_164 . V_162 ;
return ( V_2 -> V_144 & V_165 ) &&
( ( V_162 & F_101 ( V_166 ) ) ==
( F_101 ( V_167 <<
V_168 ) ) ) ;
}
static inline void F_102 ( struct V_20 * V_79 ,
union V_31 * V_32 ,
struct V_155 * V_53 )
{
F_103 ( V_53 ) ;
if ( ! ( V_79 -> V_18 -> V_156 & V_169 ) )
return;
if ( F_104 ( V_32 , V_170 ) &&
F_104 ( V_32 , V_171 ) ) {
V_79 -> V_172 . V_173 ++ ;
return;
}
if ( ! F_104 ( V_32 , V_174 ) )
return;
if ( F_104 ( V_32 , V_175 ) ) {
T_6 V_162 = V_32 -> V_57 . V_159 . V_163 . V_164 . V_162 ;
if ( ( V_162 & F_101 ( V_176 ) ) &&
F_2 ( V_177 , & V_79 -> V_4 ) )
return;
V_79 -> V_172 . V_173 ++ ;
return;
}
V_53 -> V_178 = V_179 ;
}
static inline void F_105 ( struct V_20 * V_30 , T_1 V_180 )
{
V_30 -> V_44 = V_180 ;
V_30 -> V_181 = V_180 ;
F_106 () ;
F_107 ( V_180 , V_30 -> V_103 ) ;
}
static bool F_108 ( struct V_20 * V_30 ,
struct V_33 * V_182 )
{
struct V_183 * V_183 = V_182 -> V_183 ;
T_7 V_45 = V_182 -> V_45 ;
if ( F_70 ( V_45 ) )
return true ;
if ( F_70 ( ! V_183 ) ) {
V_183 = F_109 ( V_184 | V_185 ,
F_110 ( V_30 ) ) ;
if ( F_68 ( ! V_183 ) ) {
V_30 -> V_172 . V_186 ++ ;
return false ;
}
V_182 -> V_183 = V_183 ;
}
V_45 = F_111 ( V_30 -> V_37 , V_183 , 0 ,
F_112 ( V_30 ) , V_187 ) ;
if ( F_113 ( V_30 -> V_37 , V_45 ) ) {
F_114 ( V_183 ) ;
V_182 -> V_183 = NULL ;
V_30 -> V_172 . V_186 ++ ;
return false ;
}
V_182 -> V_45 = V_45 ;
V_182 -> V_188 ^= F_43 ( V_30 ) ;
return true ;
}
void F_115 ( struct V_20 * V_30 , T_5 V_189 )
{
union V_31 * V_32 ;
struct V_33 * V_182 ;
T_5 V_11 = V_30 -> V_44 ;
if ( ! V_189 )
return;
V_32 = F_41 ( V_30 , V_11 ) ;
V_182 = & V_30 -> V_34 [ V_11 ] ;
V_11 -= V_30 -> V_52 ;
do {
if ( ! F_108 ( V_30 , V_182 ) )
break;
V_32 -> V_190 . V_191 = F_116 ( V_182 -> V_45 + V_182 -> V_188 ) ;
V_32 ++ ;
V_182 ++ ;
V_11 ++ ;
if ( F_68 ( ! V_11 ) ) {
V_32 = F_41 ( V_30 , 0 ) ;
V_182 = V_30 -> V_34 ;
V_11 -= V_30 -> V_52 ;
}
V_32 -> V_190 . V_192 = 0 ;
V_189 -- ;
} while ( V_189 );
V_11 += V_30 -> V_52 ;
if ( V_30 -> V_44 != V_11 )
F_105 ( V_30 , V_11 ) ;
}
static unsigned int F_117 ( unsigned char * V_84 ,
unsigned int V_193 )
{
union {
unsigned char * V_194 ;
struct V_195 * V_196 ;
struct V_197 * V_198 ;
struct V_199 * V_200 ;
} V_201 ;
T_8 V_202 ;
T_4 V_203 = 0 ;
T_4 V_204 ;
if ( V_193 < V_205 )
return V_193 ;
V_201 . V_194 = V_84 ;
V_202 = V_201 . V_196 -> V_206 ;
V_201 . V_194 += V_205 ;
if ( V_202 == F_118 ( V_207 ) ) {
if ( ( V_201 . V_194 - V_84 ) > ( V_193 - V_208 ) )
return V_193 ;
V_202 = V_201 . V_198 -> V_209 ;
V_201 . V_194 += V_208 ;
}
if ( V_202 == F_118 ( V_210 ) ) {
if ( ( V_201 . V_194 - V_84 ) > ( V_193 - sizeof( struct V_199 ) ) )
return V_193 ;
V_204 = ( V_201 . V_194 [ 0 ] & 0x0F ) << 2 ;
if ( V_204 < sizeof( struct V_199 ) )
return V_201 . V_194 - V_84 ;
V_203 = V_201 . V_200 -> V_202 ;
V_201 . V_194 += V_204 ;
#ifdef F_119
} else if ( V_202 == F_118 ( V_211 ) ) {
if ( ( V_201 . V_194 - V_84 ) > ( V_193 - V_212 ) )
return V_193 ;
V_201 . V_194 += V_212 ;
#endif
} else {
return V_201 . V_194 - V_84 ;
}
if ( V_203 == V_213 ) {
if ( ( V_201 . V_194 - V_84 ) > ( V_193 - sizeof( struct V_214 ) ) )
return V_193 ;
V_204 = ( V_201 . V_194 [ 12 ] & 0xF0 ) >> 2 ;
if ( V_204 < sizeof( struct V_214 ) )
return V_201 . V_194 - V_84 ;
V_201 . V_194 += V_204 ;
}
if ( ( V_201 . V_194 - V_84 ) < V_193 )
return V_201 . V_194 - V_84 ;
else
return V_193 ;
}
static void F_120 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_155 * V_53 )
{
T_9 V_215 ;
T_1 V_216 ;
if ( ! F_121 ( V_30 ) )
return;
V_215 = V_32 -> V_57 . V_159 . V_163 . V_84 &
F_67 ( V_217 ) ;
if ( ! V_215 )
return;
V_216 = F_42 ( V_215 ) ;
V_216 >>= V_218 ;
F_122 ( V_53 ) -> V_219 += V_216 - 1 ;
}
static void F_123 ( struct V_20 * V_79 ,
struct V_155 * V_53 )
{
T_5 V_220 = F_124 ( V_53 ) ;
F_125 ( V_53 ) -> V_221 = F_126 ( ( V_53 -> V_46 - V_220 ) ,
F_122 ( V_53 ) -> V_219 ) ;
}
static void F_127 ( struct V_20 * V_30 ,
struct V_155 * V_53 )
{
if ( ! F_122 ( V_53 ) -> V_219 )
return;
V_30 -> V_172 . V_222 += F_122 ( V_53 ) -> V_219 ;
V_30 -> V_172 . V_223 ++ ;
F_123 ( V_30 , V_53 ) ;
F_122 ( V_53 ) -> V_219 = 0 ;
}
static void F_128 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_155 * V_53 )
{
F_127 ( V_30 , V_53 ) ;
F_99 ( V_30 , V_32 , V_53 ) ;
F_102 ( V_30 , V_32 , V_53 ) ;
if ( F_104 ( V_32 , V_224 ) ) {
T_5 V_225 = F_129 ( V_32 -> V_57 . V_58 . V_198 ) ;
F_130 ( V_53 , V_225 ) ;
}
F_131 ( V_53 , V_30 -> V_50 ) ;
V_53 -> V_202 = F_132 ( V_53 , V_30 -> V_18 ) ;
}
static void F_133 ( struct V_111 * V_112 ,
struct V_155 * V_53 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
if ( ! ( V_2 -> V_144 & V_226 ) )
F_134 ( & V_112 -> V_227 , V_53 ) ;
else
F_135 ( V_53 ) ;
}
static bool F_136 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_155 * V_53 )
{
T_1 V_228 = V_30 -> V_43 + 1 ;
V_228 = ( V_228 < V_30 -> V_52 ) ? V_228 : 0 ;
V_30 -> V_43 = V_228 ;
F_69 ( F_41 ( V_30 , V_228 ) ) ;
if ( F_70 ( F_104 ( V_32 , V_229 ) ) )
return false ;
if ( F_122 ( V_53 ) -> V_219 ) {
V_228 = F_42 ( V_32 -> V_57 . V_58 . V_59 ) ;
V_228 &= V_230 ;
V_228 >>= V_231 ;
}
V_30 -> V_34 [ V_228 ] . V_53 = V_53 ;
V_30 -> V_172 . V_232 ++ ;
return true ;
}
static bool F_137 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_155 * V_53 )
{
struct V_233 * V_234 = & F_125 ( V_53 ) -> V_235 [ 0 ] ;
struct V_17 * V_18 = V_30 -> V_18 ;
unsigned char * V_236 ;
unsigned int V_237 ;
if ( F_68 ( F_122 ( V_53 ) -> V_238 ) ) {
F_54 ( V_30 -> V_37 , F_122 ( V_53 ) -> V_45 ,
F_112 ( V_30 ) , V_187 ) ;
F_122 ( V_53 ) -> V_238 = false ;
} else {
F_138 ( V_30 -> V_37 ,
F_122 ( V_53 ) -> V_45 ,
V_234 -> V_188 ,
F_43 ( V_30 ) ,
V_187 ) ;
}
F_122 ( V_53 ) -> V_45 = 0 ;
if ( F_68 ( F_104 ( V_32 ,
V_239 ) &&
! ( V_18 -> V_156 & V_240 ) ) ) {
F_52 ( V_53 ) ;
return true ;
}
V_236 = F_139 ( V_234 ) ;
V_237 = F_140 ( V_234 ) ;
if ( V_237 > 256 )
V_237 = F_117 ( V_236 , V_237 ) ;
F_141 ( V_53 , V_236 , F_142 ( V_237 , sizeof( long ) ) ) ;
F_143 ( V_234 , V_237 ) ;
V_234 -> V_188 += V_237 ;
V_53 -> V_241 -= V_237 ;
V_53 -> V_103 += V_237 ;
if ( F_140 ( V_234 ) == 0 ) {
F_6 ( F_125 ( V_53 ) -> V_242 != 1 ) ;
F_125 ( V_53 ) -> V_242 = 0 ;
F_144 ( V_234 ) ;
V_53 -> V_243 -= F_43 ( V_30 ) ;
}
if ( F_68 ( V_53 -> V_46 < 60 ) ) {
int V_244 = 60 - V_53 -> V_46 ;
if ( F_145 ( V_53 , V_244 ) )
return true ;
F_146 ( V_53 , V_244 ) ;
}
return false ;
}
static inline bool F_147 ( struct V_33 * V_245 )
{
struct V_183 * V_183 = V_245 -> V_183 ;
return F_70 ( F_148 ( V_183 ) == 1 ) &&
F_70 ( F_149 ( V_183 ) == F_150 () ) ;
}
static void F_151 ( struct V_20 * V_30 ,
struct V_33 * V_246 )
{
struct V_33 * V_247 ;
T_5 V_248 = V_30 -> V_181 ;
T_5 V_249 = F_43 ( V_30 ) ;
V_247 = & V_30 -> V_34 [ V_248 ] ;
V_248 ++ ;
V_30 -> V_181 = ( V_248 < V_30 -> V_52 ) ? V_248 : 0 ;
V_247 -> V_183 = V_246 -> V_183 ;
V_247 -> V_45 = V_246 -> V_45 ;
V_247 -> V_188 = V_246 -> V_188 ^ V_249 ;
F_152 ( V_30 -> V_37 , V_247 -> V_45 ,
V_247 -> V_188 , V_249 ,
V_187 ) ;
F_153 ( V_247 -> V_183 ) ;
}
static void F_154 ( struct V_20 * V_30 ,
struct V_33 * V_245 ,
struct V_155 * V_53 , int V_250 )
{
F_155 ( V_53 , F_125 ( V_53 ) -> V_242 ,
V_245 -> V_183 , V_245 -> V_188 ,
V_250 ) ;
V_53 -> V_46 += V_250 ;
V_53 -> V_241 += V_250 ;
V_53 -> V_243 += F_43 ( V_30 ) ;
}
static bool F_156 ( struct V_111 * V_112 ,
struct V_20 * V_30 ,
int V_115 )
{
unsigned int V_251 = 0 , V_252 = 0 ;
#ifdef F_119
struct V_1 * V_2 = V_112 -> V_2 ;
int V_253 = 0 ;
#endif
T_5 V_189 = F_81 ( V_30 ) ;
do {
struct V_33 * V_245 ;
union V_31 * V_32 ;
struct V_155 * V_53 ;
struct V_183 * V_183 ;
T_5 V_228 ;
if ( V_189 >= V_254 ) {
F_115 ( V_30 , V_189 ) ;
V_189 = 0 ;
}
V_228 = V_30 -> V_43 ;
V_32 = F_41 ( V_30 , V_228 ) ;
V_245 = & V_30 -> V_34 [ V_228 ] ;
if ( ! F_104 ( V_32 , V_60 ) )
break;
F_66 () ;
V_183 = V_245 -> V_183 ;
F_157 ( V_183 ) ;
V_53 = V_245 -> V_53 ;
if ( F_70 ( ! V_53 ) ) {
void * V_255 = F_158 ( V_183 ) +
V_245 -> V_188 ;
F_69 ( V_255 ) ;
#if V_256 < 128
F_69 ( V_255 + V_256 ) ;
#endif
V_53 = F_159 ( V_30 -> V_18 ,
V_257 ) ;
if ( F_68 ( ! V_53 ) ) {
V_30 -> V_172 . V_258 ++ ;
break;
}
F_157 ( V_53 -> V_84 ) ;
F_122 ( V_53 ) -> V_45 = V_245 -> V_45 ;
} else {
F_138 ( V_30 -> V_37 ,
V_245 -> V_45 ,
V_245 -> V_188 ,
F_43 ( V_30 ) ,
V_187 ) ;
}
F_154 ( V_30 , V_245 , V_53 ,
F_129 ( V_32 -> V_57 . V_58 . V_259 ) ) ;
if ( F_147 ( V_245 ) ) {
F_151 ( V_30 , V_245 ) ;
} else if ( F_122 ( V_53 ) -> V_45 == V_245 -> V_45 ) {
F_122 ( V_53 ) -> V_238 = true ;
} else {
F_54 ( V_30 -> V_37 , V_245 -> V_45 ,
F_112 ( V_30 ) ,
V_187 ) ;
}
V_245 -> V_53 = NULL ;
V_245 -> V_45 = 0 ;
V_245 -> V_183 = NULL ;
F_120 ( V_30 , V_32 , V_53 ) ;
V_189 ++ ;
if ( F_136 ( V_30 , V_32 , V_53 ) )
continue;
if ( F_137 ( V_30 , V_32 , V_53 ) )
continue;
V_251 += V_53 -> V_46 ;
V_252 ++ ;
F_128 ( V_30 , V_32 , V_53 ) ;
#ifdef F_119
if ( F_100 ( V_2 , V_32 ) ) {
V_253 = F_160 ( V_2 , V_32 , V_53 ) ;
if ( ! V_253 ) {
F_52 ( V_53 ) ;
continue;
}
}
#endif
F_133 ( V_112 , V_53 ) ;
V_115 -- ;
} while ( F_70 ( V_115 ) );
#ifdef F_119
if ( V_253 > 0 ) {
unsigned int V_260 ;
V_260 = V_30 -> V_18 -> V_261 - sizeof( struct V_262 ) -
sizeof( struct V_263 ) -
sizeof( struct V_264 ) ;
if ( V_260 > 512 )
V_260 &= ~ 511 ;
V_251 += V_253 ;
V_252 += F_126 ( V_253 , V_260 ) ;
}
#endif
F_71 ( & V_30 -> V_123 ) ;
V_30 -> V_83 . V_100 += V_252 ;
V_30 -> V_83 . V_124 += V_251 ;
F_72 ( & V_30 -> V_123 ) ;
V_112 -> V_265 . V_114 += V_252 ;
V_112 -> V_265 . V_113 += V_251 ;
if ( V_189 )
F_115 ( V_30 , V_189 ) ;
return ! ! V_115 ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_111 * V_112 ;
int V_266 , V_267 ;
T_1 V_76 ;
V_266 = V_2 -> V_148 - V_149 ;
if ( V_2 -> V_268 > 32 ) {
T_1 V_269 = ( 1 << ( V_2 -> V_268 - 32 ) ) - 1 ;
F_45 ( & V_2 -> V_8 , V_270 , V_269 ) ;
}
for ( V_267 = 0 ; V_267 < V_266 ; V_267 ++ ) {
struct V_20 * V_79 ;
V_112 = V_2 -> V_112 [ V_267 ] ;
F_92 (ring, q_vector->rx)
F_47 ( V_2 , 0 , V_79 -> V_102 , V_267 ) ;
F_92 (ring, q_vector->tx)
F_47 ( V_2 , 1 , V_79 -> V_102 , V_267 ) ;
if ( V_112 -> V_116 . V_79 && ! V_112 -> V_265 . V_79 ) {
if ( V_2 -> V_271 == 1 )
V_112 -> V_272 = V_273 ;
else
V_112 -> V_272 = V_2 -> V_271 ;
} else {
if ( V_2 -> V_274 == 1 )
V_112 -> V_272 = V_275 ;
else
V_112 -> V_272 = V_2 -> V_274 ;
}
F_162 ( V_112 ) ;
}
switch ( V_2 -> V_8 . V_69 . type ) {
case V_70 :
F_47 ( V_2 , - 1 , V_276 ,
V_267 ) ;
break;
case V_72 :
case V_73 :
F_47 ( V_2 , - 1 , 1 , V_267 ) ;
break;
default:
break;
}
F_45 ( & V_2 -> V_8 , F_163 ( V_267 ) , 1950 ) ;
V_76 = V_277 ;
V_76 &= ~ ( V_278 |
V_279 |
V_280 ) ;
F_45 ( & V_2 -> V_8 , V_281 , V_76 ) ;
}
static void F_164 ( struct V_111 * V_112 ,
struct V_282 * V_283 )
{
int V_124 = V_283 -> V_113 ;
int V_100 = V_283 -> V_114 ;
T_1 V_284 ;
T_2 V_285 ;
T_4 V_286 = V_283 -> V_272 ;
if ( V_100 == 0 )
return;
V_284 = V_112 -> V_272 >> 2 ;
V_285 = V_124 / V_284 ;
switch ( V_286 ) {
case V_287 :
if ( V_285 > 10 )
V_286 = V_288 ;
break;
case V_288 :
if ( V_285 > 20 )
V_286 = V_289 ;
else if ( V_285 <= 10 )
V_286 = V_287 ;
break;
case V_289 :
if ( V_285 <= 20 )
V_286 = V_288 ;
break;
}
V_283 -> V_113 = 0 ;
V_283 -> V_114 = 0 ;
V_283 -> V_272 = V_286 ;
}
void F_162 ( struct V_111 * V_112 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_267 = V_112 -> V_267 ;
T_1 V_290 = V_112 -> V_272 & V_291 ;
switch ( V_2 -> V_8 . V_69 . type ) {
case V_70 :
V_290 |= ( V_290 << 16 ) ;
break;
case V_72 :
case V_73 :
V_290 |= V_292 ;
break;
default:
break;
}
F_45 ( V_8 , F_163 ( V_267 ) , V_290 ) ;
}
static void F_165 ( struct V_111 * V_112 )
{
T_1 V_293 = V_112 -> V_272 ;
T_4 V_294 ;
F_164 ( V_112 , & V_112 -> V_116 ) ;
F_164 ( V_112 , & V_112 -> V_265 ) ;
V_294 = F_166 ( V_112 -> V_265 . V_272 , V_112 -> V_116 . V_272 ) ;
switch ( V_294 ) {
case V_287 :
V_293 = V_295 ;
break;
case V_288 :
V_293 = V_275 ;
break;
case V_289 :
V_293 = V_296 ;
break;
default:
break;
}
if ( V_293 != V_112 -> V_272 ) {
V_293 = ( 10 * V_293 * V_112 -> V_272 ) /
( ( 9 * V_293 ) + V_112 -> V_272 ) ;
V_112 -> V_272 = V_293 ;
F_162 ( V_112 ) ;
}
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_297 = V_2 -> V_298 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
if ( ! ( V_2 -> V_109 & V_299 ) &&
! ( V_2 -> V_109 & V_300 ) )
return;
V_2 -> V_109 &= ~ V_300 ;
switch ( V_8 -> V_301 ) {
case V_302 :
if ( ! ( V_297 & V_303 ) &&
! ( V_297 & V_304 ) )
return;
if ( ! ( V_297 & V_304 ) && V_8 -> V_69 . V_305 . V_306 ) {
T_1 V_307 ;
bool V_308 = false ;
V_8 -> V_69 . V_305 . V_306 ( V_8 , & V_307 , & V_308 , false ) ;
if ( V_308 )
return;
}
if ( V_8 -> V_309 . V_305 . V_310 ( V_8 ) != V_311 )
return;
break;
default:
if ( ! ( V_297 & V_303 ) )
return;
break;
}
F_168 ( V_125 ,
L_51
L_52
L_53 ) ;
V_2 -> V_298 = 0 ;
}
static void F_169 ( struct V_1 * V_2 , T_1 V_297 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( ( V_2 -> V_144 & V_312 ) &&
( V_297 & V_313 ) ) {
F_168 ( V_127 , L_54 ) ;
F_45 ( V_8 , V_314 , V_313 ) ;
}
}
static void F_170 ( struct V_1 * V_2 , T_1 V_297 )
{
if ( ! ( V_2 -> V_109 & V_299 ) )
return;
switch ( V_2 -> V_8 . V_69 . type ) {
case V_72 :
if ( ( ( V_297 & V_303 ) || ( V_297 & V_304 ) ) &&
( ! F_2 ( V_3 , & V_2 -> V_4 ) ) ) {
V_2 -> V_298 = V_297 ;
V_2 -> V_109 |= V_300 ;
F_1 ( V_2 ) ;
return;
}
return;
case V_73 :
if ( ! ( V_297 & V_315 ) )
return;
break;
default:
return;
}
F_168 ( V_125 ,
L_51
L_52
L_53 ) ;
}
static void F_171 ( struct V_1 * V_2 , T_1 V_297 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( V_297 & V_316 ) {
F_45 ( V_8 , V_314 , V_316 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_109 |= V_317 ;
F_1 ( V_2 ) ;
}
}
if ( V_297 & V_313 ) {
F_45 ( V_8 , V_314 , V_313 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_144 |= V_318 ;
F_1 ( V_2 ) ;
}
}
}
static void F_172 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
V_2 -> V_319 ++ ;
V_2 -> V_144 |= V_320 ;
V_2 -> V_321 = V_126 ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_45 ( V_8 , V_322 , V_323 ) ;
F_173 ( V_8 ) ;
F_1 ( V_2 ) ;
}
}
static inline void F_174 ( struct V_1 * V_2 ,
T_2 V_75 )
{
T_1 V_76 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_76 = ( V_77 & V_75 ) ;
F_45 ( V_8 , V_324 , V_76 ) ;
break;
case V_72 :
case V_73 :
V_76 = ( V_75 & 0xFFFFFFFF ) ;
if ( V_76 )
F_45 ( V_8 , F_175 ( 0 ) , V_76 ) ;
V_76 = ( V_75 >> 32 ) ;
if ( V_76 )
F_45 ( V_8 , F_175 ( 1 ) , V_76 ) ;
break;
default:
break;
}
}
static inline void F_176 ( struct V_1 * V_2 ,
T_2 V_75 )
{
T_1 V_76 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_76 = ( V_77 & V_75 ) ;
F_45 ( V_8 , V_322 , V_76 ) ;
break;
case V_72 :
case V_73 :
V_76 = ( V_75 & 0xFFFFFFFF ) ;
if ( V_76 )
F_45 ( V_8 , F_177 ( 0 ) , V_76 ) ;
V_76 = ( V_75 >> 32 ) ;
if ( V_76 )
F_45 ( V_8 , F_177 ( 1 ) , V_76 ) ;
break;
default:
break;
}
}
static inline void F_178 ( struct V_1 * V_2 , bool V_325 ,
bool V_326 )
{
T_1 V_76 = ( V_277 & ~ V_77 ) ;
if ( V_2 -> V_144 & V_320 )
V_76 &= ~ V_280 ;
if ( V_2 -> V_109 & V_299 )
switch ( V_2 -> V_8 . V_69 . type ) {
case V_72 :
V_76 |= V_327 ;
break;
case V_73 :
V_76 |= V_328 ;
break;
default:
break;
}
if ( V_2 -> V_144 & V_312 )
V_76 |= V_329 ;
switch ( V_2 -> V_8 . V_69 . type ) {
case V_72 :
V_76 |= V_329 ;
V_76 |= V_330 ;
case V_73 :
V_76 |= V_331 ;
V_76 |= V_279 ;
break;
default:
break;
}
if ( ( V_2 -> V_144 & V_332 ) &&
! ( V_2 -> V_109 & V_333 ) )
V_76 |= V_334 ;
F_45 ( & V_2 -> V_8 , V_324 , V_76 ) ;
if ( V_325 )
F_174 ( V_2 , ~ 0 ) ;
if ( V_326 )
F_173 ( & V_2 -> V_8 ) ;
}
static T_10 F_179 ( int V_335 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_297 ;
V_297 = F_11 ( V_8 , V_78 ) ;
F_45 ( V_8 , V_314 , V_297 ) ;
if ( V_297 & V_304 )
F_172 ( V_2 ) ;
if ( V_297 & V_336 )
F_180 ( V_2 ) ;
switch ( V_8 -> V_69 . type ) {
case V_72 :
case V_73 :
if ( V_297 & V_337 )
F_76 ( V_338 , L_55
L_56 ) ;
if ( V_297 & V_339 ) {
int V_340 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_79 = V_2 -> V_21 [ V_11 ] ;
if ( F_181 ( V_341 ,
& V_79 -> V_4 ) )
V_340 ++ ;
}
if ( V_340 ) {
F_45 ( V_8 , V_322 , V_342 ) ;
V_2 -> V_109 |= V_333 ;
F_1 ( V_2 ) ;
}
}
F_171 ( V_2 , V_297 ) ;
F_170 ( V_2 , V_297 ) ;
break;
default:
break;
}
F_169 ( V_2 , V_297 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_178 ( V_2 , false , false ) ;
return V_343 ;
}
static T_10 F_182 ( int V_335 , void * V_84 )
{
struct V_111 * V_112 = V_84 ;
if ( V_112 -> V_265 . V_79 || V_112 -> V_116 . V_79 )
F_183 ( & V_112 -> V_227 ) ;
return V_343 ;
}
int F_184 ( struct V_344 * V_227 , int V_115 )
{
struct V_111 * V_112 =
F_185 ( V_227 , struct V_111 , V_227 ) ;
struct V_1 * V_2 = V_112 -> V_2 ;
struct V_20 * V_79 ;
int V_345 ;
bool V_346 = true ;
#ifdef F_186
if ( V_2 -> V_144 & V_145 )
F_90 ( V_112 ) ;
#endif
F_92 (ring, q_vector->tx)
V_346 &= ! ! F_65 ( V_112 , V_79 ) ;
if ( V_112 -> V_265 . V_52 > 1 )
V_345 = F_166 ( V_115 / V_112 -> V_265 . V_52 , 1 ) ;
else
V_345 = V_115 ;
F_92 (ring, q_vector->rx)
V_346 &= F_156 ( V_112 , V_79 ,
V_345 ) ;
if ( ! V_346 )
return V_115 ;
F_187 ( V_227 ) ;
if ( V_2 -> V_274 & 1 )
F_165 ( V_112 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_174 ( V_2 , ( ( T_2 ) 1 << V_112 -> V_267 ) ) ;
return 0 ;
}
static int F_188 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
int V_266 = V_2 -> V_148 - V_149 ;
int V_347 , V_348 ;
int V_349 = 0 , V_350 = 0 ;
for ( V_347 = 0 ; V_347 < V_266 ; V_347 ++ ) {
struct V_111 * V_112 = V_2 -> V_112 [ V_347 ] ;
struct V_351 * V_352 = & V_2 -> V_353 [ V_347 ] ;
if ( V_112 -> V_116 . V_79 && V_112 -> V_265 . V_79 ) {
snprintf ( V_112 -> V_16 , sizeof( V_112 -> V_16 ) - 1 ,
L_57 , V_18 -> V_16 , L_58 , V_349 ++ ) ;
V_350 ++ ;
} else if ( V_112 -> V_265 . V_79 ) {
snprintf ( V_112 -> V_16 , sizeof( V_112 -> V_16 ) - 1 ,
L_57 , V_18 -> V_16 , L_59 , V_349 ++ ) ;
} else if ( V_112 -> V_116 . V_79 ) {
snprintf ( V_112 -> V_16 , sizeof( V_112 -> V_16 ) - 1 ,
L_57 , V_18 -> V_16 , L_60 , V_350 ++ ) ;
} else {
continue;
}
V_348 = F_189 ( V_352 -> V_347 , & F_182 , 0 ,
V_112 -> V_16 , V_112 ) ;
if ( V_348 ) {
F_74 ( V_127 , L_61
L_62 , V_348 ) ;
goto V_354;
}
if ( V_2 -> V_144 & V_332 ) {
F_190 ( V_352 -> V_347 ,
& V_112 -> V_355 ) ;
}
}
V_348 = F_189 ( V_2 -> V_353 [ V_347 ] . V_347 ,
F_179 , 0 , V_18 -> V_16 , V_2 ) ;
if ( V_348 ) {
F_74 ( V_127 , L_63 , V_348 ) ;
goto V_354;
}
return 0 ;
V_354:
while ( V_347 ) {
V_347 -- ;
F_190 ( V_2 -> V_353 [ V_347 ] . V_347 ,
NULL ) ;
F_191 ( V_2 -> V_353 [ V_347 ] . V_347 ,
V_2 -> V_112 [ V_347 ] ) ;
}
V_2 -> V_144 &= ~ V_147 ;
F_192 ( V_2 -> V_36 ) ;
F_193 ( V_2 -> V_353 ) ;
V_2 -> V_353 = NULL ;
return V_348 ;
}
static T_10 F_194 ( int V_335 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_111 * V_112 = V_2 -> V_112 [ 0 ] ;
T_1 V_297 ;
F_45 ( V_8 , V_322 , V_356 ) ;
V_297 = F_11 ( V_8 , V_314 ) ;
if ( ! V_297 ) {
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_178 ( V_2 , true , true ) ;
return V_357 ;
}
if ( V_297 & V_304 )
F_172 ( V_2 ) ;
switch ( V_8 -> V_69 . type ) {
case V_72 :
F_171 ( V_2 , V_297 ) ;
case V_73 :
if ( V_297 & V_337 )
F_76 ( V_338 , L_64
L_56 ) ;
F_170 ( V_2 , V_297 ) ;
break;
default:
break;
}
F_169 ( V_2 , V_297 ) ;
F_183 ( & V_112 -> V_227 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_178 ( V_2 , false , false ) ;
return V_343 ;
}
static int F_195 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
int V_348 ;
if ( V_2 -> V_144 & V_147 )
V_348 = F_188 ( V_2 ) ;
else if ( V_2 -> V_144 & V_358 )
V_348 = F_189 ( V_2 -> V_36 -> V_335 , F_194 , 0 ,
V_18 -> V_16 , V_2 ) ;
else
V_348 = F_189 ( V_2 -> V_36 -> V_335 , F_194 , V_359 ,
V_18 -> V_16 , V_2 ) ;
if ( V_348 )
F_74 ( V_127 , L_65 , V_348 ) ;
return V_348 ;
}
static void F_196 ( struct V_1 * V_2 )
{
if ( V_2 -> V_144 & V_147 ) {
int V_11 , V_266 ;
V_266 = V_2 -> V_148 ;
V_11 = V_266 - 1 ;
F_191 ( V_2 -> V_353 [ V_11 ] . V_347 , V_2 ) ;
V_11 -- ;
for (; V_11 >= 0 ; V_11 -- ) {
if ( ! V_2 -> V_112 [ V_11 ] -> V_265 . V_79 &&
! V_2 -> V_112 [ V_11 ] -> V_116 . V_79 )
continue;
F_190 ( V_2 -> V_353 [ V_11 ] . V_347 ,
NULL ) ;
F_191 ( V_2 -> V_353 [ V_11 ] . V_347 ,
V_2 -> V_112 [ V_11 ] ) ;
}
} else {
F_191 ( V_2 -> V_36 -> V_335 , V_2 ) ;
}
}
static inline void F_197 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 . V_69 . type ) {
case V_70 :
F_45 ( & V_2 -> V_8 , V_322 , ~ 0 ) ;
break;
case V_72 :
case V_73 :
F_45 ( & V_2 -> V_8 , V_322 , 0xFFFF0000 ) ;
F_45 ( & V_2 -> V_8 , F_177 ( 0 ) , ~ 0 ) ;
F_45 ( & V_2 -> V_8 , F_177 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_173 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_144 & V_147 ) {
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_148 ; V_11 ++ )
F_198 ( V_2 -> V_353 [ V_11 ] . V_347 ) ;
} else {
F_198 ( V_2 -> V_36 -> V_335 ) ;
}
}
static void F_199 ( struct V_1 * V_2 )
{
struct V_111 * V_112 = V_2 -> V_112 [ 0 ] ;
if ( V_2 -> V_274 == 1 )
V_112 -> V_272 = V_275 ;
else
V_112 -> V_272 = V_2 -> V_274 ;
F_162 ( V_112 ) ;
F_47 ( V_2 , 0 , 0 , 0 ) ;
F_47 ( V_2 , 1 , 0 , 0 ) ;
F_76 ( V_8 , L_66 ) ;
}
void F_200 ( struct V_1 * V_2 ,
struct V_20 * V_79 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_360 = V_79 -> V_45 ;
int V_361 = 10 ;
T_1 V_362 = V_363 ;
T_4 V_102 = V_79 -> V_102 ;
F_45 ( V_8 , F_24 ( V_102 ) , 0 ) ;
F_173 ( V_8 ) ;
F_45 ( V_8 , F_19 ( V_102 ) ,
( V_360 & F_201 ( 32 ) ) ) ;
F_45 ( V_8 , F_20 ( V_102 ) , ( V_360 >> 32 ) ) ;
F_45 ( V_8 , F_21 ( V_102 ) ,
V_79 -> V_52 * sizeof( union V_24 ) ) ;
F_45 ( V_8 , F_22 ( V_102 ) , 0 ) ;
F_45 ( V_8 , F_23 ( V_102 ) , 0 ) ;
V_79 -> V_103 = V_8 -> V_364 + F_23 ( V_102 ) ;
if ( ! V_79 -> V_112 || ( V_79 -> V_112 -> V_272 < 8 ) )
V_362 |= ( 1 << 16 ) ;
else
V_362 |= ( 8 << 16 ) ;
V_362 |= ( 1 << 8 ) |
32 ;
if ( ( V_2 -> V_144 & V_332 ) &&
V_2 -> V_365 ) {
V_79 -> V_365 = V_2 -> V_365 ;
V_79 -> V_366 = 0 ;
F_202 ( V_341 , & V_79 -> V_4 ) ;
} else {
V_79 -> V_365 = 0 ;
}
F_8 ( V_93 , & V_79 -> V_4 ) ;
F_45 ( V_8 , F_24 ( V_102 ) , V_362 ) ;
if ( V_8 -> V_69 . type == V_70 &&
! ( F_11 ( V_8 , V_367 ) & V_368 ) )
return;
do {
F_203 ( 1000 , 2000 ) ;
V_362 = F_11 ( V_8 , F_24 ( V_102 ) ) ;
} while ( -- V_361 && ! ( V_362 & V_363 ) );
if ( ! V_361 )
F_74 ( V_125 , L_67 , V_102 ) ;
}
static void F_204 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_369 ;
T_1 V_370 ;
T_4 V_371 = F_205 ( V_2 -> V_18 ) ;
if ( V_8 -> V_69 . type == V_70 )
return;
V_369 = F_11 ( V_8 , V_372 ) ;
V_369 |= V_373 ;
F_45 ( V_8 , V_372 , V_369 ) ;
switch ( V_2 -> V_144 & V_374 ) {
case ( V_374 ) :
F_45 ( V_8 , V_375 ,
( V_376 | V_377 ) ) ;
break;
default:
if ( ! V_371 )
V_370 = V_378 ;
else if ( V_371 <= 4 )
V_370 = V_379 | V_380 ;
else
V_370 = V_379 | V_381 ;
F_45 ( V_8 , V_375 , V_370 ) ;
if ( V_371 ) {
V_370 = F_11 ( V_8 , V_382 ) ;
V_370 |= V_383 ;
F_45 ( V_8 , V_382 , V_370 ) ;
}
break;
}
V_369 &= ~ V_373 ;
F_45 ( V_8 , V_372 , V_369 ) ;
}
static void F_206 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_384 ;
T_1 V_11 ;
F_204 ( V_2 ) ;
if ( V_8 -> V_69 . type != V_70 ) {
V_384 = F_11 ( V_8 , V_385 ) ;
V_384 |= V_386 ;
F_45 ( V_8 , V_385 , V_384 ) ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_200 ( V_2 , V_2 -> V_21 [ V_11 ] ) ;
}
static void F_207 ( struct V_1 * V_2 ,
struct V_20 * V_30 )
{
T_1 V_387 ;
T_4 V_102 = V_30 -> V_102 ;
switch ( V_2 -> V_8 . V_69 . type ) {
case V_70 : {
struct V_388 * V_389 = V_2 -> V_390 ;
const int V_76 = V_389 [ V_391 ] . V_76 ;
V_102 = V_102 & V_76 ;
}
break;
case V_72 :
case V_73 :
default:
break;
}
V_387 = F_11 ( & V_2 -> V_8 , F_10 ( V_102 ) ) ;
V_387 &= ~ V_392 ;
V_387 &= ~ V_393 ;
if ( V_2 -> V_268 )
V_387 |= V_394 ;
V_387 |= ( V_257 << V_395 ) &
V_392 ;
#if V_396 > V_397
V_387 |= V_397 >> V_398 ;
#else
V_387 |= F_43 ( V_30 ) >> V_398 ;
#endif
V_387 |= V_399 ;
F_45 ( & V_2 -> V_8 , F_10 ( V_102 ) , V_387 ) ;
}
static void F_208 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
static const T_1 V_400 [ 10 ] = { 0xE291D73D , 0x1805EC6C , 0x2A94B30D ,
0xA54F2BEC , 0xEA49AF7C , 0xE214AD3D , 0xB855AABE ,
0x6A3E67EA , 0x14364D17 , 0x3BED200D } ;
T_1 V_401 = 0 , V_402 = 0 ;
T_1 V_403 ;
int V_11 , V_12 ;
T_4 V_371 = F_205 ( V_2 -> V_18 ) ;
int V_404 = V_2 -> V_390 [ V_391 ] . V_405 ;
if ( V_371 )
V_404 = F_209 ( V_404 , V_2 -> V_41 / V_371 ) ;
for ( V_11 = 0 ; V_11 < 10 ; V_11 ++ )
F_45 ( V_8 , F_210 ( V_11 ) , V_400 [ V_11 ] ) ;
for ( V_11 = 0 , V_12 = 0 ; V_11 < 128 ; V_11 ++ , V_12 ++ ) {
if ( V_12 == V_404 )
V_12 = 0 ;
V_402 = ( V_402 << 8 ) | ( V_12 * 0x11 ) ;
if ( ( V_11 & 3 ) == 3 )
F_45 ( V_8 , F_211 ( V_11 >> 2 ) , V_402 ) ;
}
V_403 = F_11 ( V_8 , V_406 ) ;
V_403 |= V_407 ;
F_45 ( V_8 , V_406 , V_403 ) ;
if ( V_2 -> V_8 . V_69 . type == V_70 &&
( V_2 -> V_144 & V_408 ) ) {
V_401 = V_409 ;
} else {
int V_76 = V_2 -> V_144 & ( V_408
| V_374 ) ;
switch ( V_76 ) {
case ( V_408 ) :
if ( ! V_371 )
V_401 = V_409 ;
else if ( V_371 <= 4 )
V_401 = V_410 ;
else
V_401 = V_411 ;
break;
case ( V_374 ) :
V_401 = V_412 ;
break;
default:
break;
}
}
V_401 |= V_413
| V_414
| V_415
| V_416 ;
if ( V_2 -> V_109 & V_417 )
V_401 |= V_418 ;
if ( V_2 -> V_109 & V_419 )
V_401 |= V_420 ;
F_45 ( V_8 , V_421 , V_401 ) ;
}
static void F_212 ( struct V_1 * V_2 ,
struct V_20 * V_79 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_422 ;
T_4 V_102 = V_79 -> V_102 ;
if ( ! F_121 ( V_79 ) )
return;
V_422 = F_11 ( V_8 , F_213 ( V_102 ) ) ;
V_422 |= V_423 ;
#if ( V_396 <= 8192 )
V_422 |= V_424 ;
#elif ( V_396 <= 16384 )
V_422 |= V_425 ;
#else
V_422 |= V_426 ;
#endif
F_45 ( V_8 , F_213 ( V_102 ) , V_422 ) ;
}
static void F_214 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_11 ;
if ( V_8 -> V_69 . type < V_72 )
return;
if ( ! ( V_2 -> V_144 & V_374 ) )
return;
for ( V_11 = 0 ; V_11 < 128 ; V_11 ++ )
F_45 ( V_8 , F_215 ( V_11 ) , ~ 0 ) ;
}
static void F_216 ( struct V_1 * V_2 ,
struct V_20 * V_79 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_361 = V_427 ;
T_1 V_428 ;
T_4 V_102 = V_79 -> V_102 ;
if ( V_8 -> V_69 . type == V_70 &&
! ( F_11 ( V_8 , V_367 ) & V_368 ) )
return;
do {
F_203 ( 1000 , 2000 ) ;
V_428 = F_11 ( V_8 , F_16 ( V_102 ) ) ;
} while ( -- V_361 && ! ( V_428 & V_429 ) );
if ( ! V_361 ) {
F_74 ( V_125 , L_68
L_69 , V_102 ) ;
}
}
void F_217 ( struct V_1 * V_2 ,
struct V_20 * V_79 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_361 = V_427 ;
T_1 V_428 ;
T_4 V_102 = V_79 -> V_102 ;
V_428 = F_11 ( V_8 , F_16 ( V_102 ) ) ;
V_428 &= ~ V_429 ;
F_45 ( V_8 , F_16 ( V_102 ) , V_428 ) ;
if ( V_8 -> V_69 . type == V_70 &&
! ( F_11 ( V_8 , V_367 ) & V_368 ) )
return;
do {
F_218 ( 10 ) ;
V_428 = F_11 ( V_8 , F_16 ( V_102 ) ) ;
} while ( -- V_361 && ( V_428 & V_429 ) );
if ( ! V_361 ) {
F_74 ( V_125 , L_70
L_69 , V_102 ) ;
}
}
void F_219 ( struct V_1 * V_2 ,
struct V_20 * V_79 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_430 = V_79 -> V_45 ;
T_1 V_428 ;
T_4 V_102 = V_79 -> V_102 ;
V_428 = F_11 ( V_8 , F_16 ( V_102 ) ) ;
F_217 ( V_2 , V_79 ) ;
F_45 ( V_8 , F_17 ( V_102 ) , ( V_430 & F_201 ( 32 ) ) ) ;
F_45 ( V_8 , F_18 ( V_102 ) , ( V_430 >> 32 ) ) ;
F_45 ( V_8 , F_13 ( V_102 ) ,
V_79 -> V_52 * sizeof( union V_31 ) ) ;
F_45 ( V_8 , F_14 ( V_102 ) , 0 ) ;
F_45 ( V_8 , F_15 ( V_102 ) , 0 ) ;
V_79 -> V_103 = V_8 -> V_364 + F_15 ( V_102 ) ;
F_207 ( V_2 , V_79 ) ;
F_212 ( V_2 , V_79 ) ;
if ( ( V_2 -> V_144 & V_374 ) &&
V_8 -> V_69 . type == V_73 ) {
V_428 &= ~ V_431 ;
V_428 |= ( ( V_79 -> V_18 -> V_261 + V_205 +
V_432 + V_208 ) | V_433 ) ;
}
if ( V_8 -> V_69 . type == V_70 ) {
V_428 &= ~ 0x3FFFFF ;
V_428 |= 0x080420 ;
}
V_428 |= V_429 ;
F_45 ( V_8 , F_16 ( V_102 ) , V_428 ) ;
F_216 ( V_2 , V_79 ) ;
F_115 ( V_79 , F_81 ( V_79 ) ) ;
}
static void F_220 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_434 ;
T_1 V_435 = V_436 |
V_437 |
V_438 |
V_439 |
V_440 ;
if ( V_8 -> V_69 . type == V_70 )
return;
if ( V_2 -> V_144 & V_408 )
V_435 |= ( V_2 -> V_441 << 29 ) ;
for ( V_434 = 0 ; V_434 < V_2 -> V_442 ; V_434 ++ )
F_45 ( V_8 , F_221 ( V_2 -> V_268 + V_434 ) ,
V_435 ) ;
}
static void F_222 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_443 ;
T_1 V_444 ;
T_1 V_132 , V_445 ;
T_1 V_446 ;
int V_11 ;
if ( ! ( V_2 -> V_144 & V_374 ) )
return;
V_446 = F_11 ( V_8 , V_447 ) ;
V_444 = V_448 | V_449 ;
V_444 |= ( V_2 -> V_268 << V_450 ) ;
F_45 ( V_8 , V_447 , V_446 | V_444 ) ;
V_445 = V_2 -> V_268 % 32 ;
V_132 = ( V_2 -> V_268 >= 32 ) ? 1 : 0 ;
F_45 ( V_8 , F_223 ( V_132 ) , ( 1 << V_445 ) ) ;
F_45 ( V_8 , F_223 ( V_132 ^ 1 ) , 0 ) ;
F_45 ( V_8 , F_224 ( V_132 ) , ( 1 << V_445 ) ) ;
F_45 ( V_8 , F_224 ( V_132 ^ 1 ) , 0 ) ;
F_45 ( V_8 , V_451 , V_452 ) ;
V_8 -> V_69 . V_305 . V_453 ( V_8 , 0 , V_2 -> V_268 ) ;
V_443 = F_11 ( V_8 , V_454 ) ;
V_443 |= V_455 ;
V_443 |= V_456 ;
F_45 ( V_8 , V_454 , V_443 ) ;
F_45 ( V_8 , V_451 , V_452 ) ;
V_8 -> V_69 . V_305 . V_457 ( V_8 ,
( V_2 -> V_268 != 0 ) ,
V_2 -> V_268 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_268 ; V_11 ++ ) {
if ( ! V_2 -> V_458 [ V_11 ] . V_459 )
F_225 ( V_2 -> V_18 , V_11 , false ) ;
}
}
static void F_226 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_18 = V_2 -> V_18 ;
int V_460 = V_18 -> V_261 + V_205 + V_432 ;
struct V_20 * V_30 ;
int V_11 ;
T_1 V_461 , V_462 ;
#ifdef F_119
if ( ( V_2 -> V_144 & V_165 ) &&
( V_460 < V_463 ) )
V_460 = V_463 ;
#endif
V_461 = F_11 ( V_8 , V_464 ) ;
if ( V_460 != ( V_461 >> V_465 ) ) {
V_461 &= ~ V_466 ;
V_461 |= V_460 << V_465 ;
F_45 ( V_8 , V_464 , V_461 ) ;
}
V_460 += V_208 ;
V_462 = F_11 ( V_8 , V_467 ) ;
V_462 |= V_468 ;
F_45 ( V_8 , V_467 , V_462 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ ) {
V_30 = V_2 -> V_30 [ V_11 ] ;
if ( V_2 -> V_109 & V_469 )
F_227 ( V_30 ) ;
else
F_228 ( V_30 ) ;
}
}
static void F_229 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_470 = F_11 ( V_8 , V_471 ) ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_470 |= V_472 ;
break;
case V_72 :
case V_73 :
F_45 ( V_8 , V_473 ,
( V_474 | F_11 ( V_8 , V_473 ) ) ) ;
V_470 &= ~ V_475 ;
V_470 |= ( V_476 | V_477 ) ;
V_470 |= V_478 ;
break;
default:
return;
}
F_45 ( V_8 , V_471 , V_470 ) ;
}
static void F_230 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_11 ;
T_1 V_137 ;
V_137 = F_11 ( V_8 , V_479 ) ;
F_45 ( V_8 , V_479 , V_137 & ~ V_480 ) ;
F_220 ( V_2 ) ;
F_229 ( V_2 ) ;
F_208 ( V_2 ) ;
F_214 ( V_2 ) ;
F_226 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ )
F_219 ( V_2 , V_2 -> V_30 [ V_11 ] ) ;
if ( V_8 -> V_69 . type == V_70 )
V_137 |= V_481 ;
V_137 |= V_480 ;
V_8 -> V_69 . V_305 . V_482 ( V_8 , V_137 ) ;
}
static int F_231 ( struct V_17 * V_18 , T_5 V_225 )
{
struct V_1 * V_2 = F_61 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_483 = V_2 -> V_268 ;
V_8 -> V_69 . V_305 . V_484 ( & V_2 -> V_8 , V_225 , V_483 , true ) ;
F_202 ( V_225 , V_2 -> V_485 ) ;
return 0 ;
}
static int F_232 ( struct V_17 * V_18 , T_5 V_225 )
{
struct V_1 * V_2 = F_61 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_483 = V_2 -> V_268 ;
V_8 -> V_69 . V_305 . V_484 ( & V_2 -> V_8 , V_225 , V_483 , false ) ;
F_8 ( V_225 , V_2 -> V_485 ) ;
return 0 ;
}
static void F_233 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_486 ;
V_486 = F_11 ( V_8 , V_487 ) ;
V_486 &= ~ ( V_488 | V_489 ) ;
F_45 ( V_8 , V_487 , V_486 ) ;
}
static void F_234 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_486 ;
V_486 = F_11 ( V_8 , V_487 ) ;
V_486 |= V_488 ;
V_486 &= ~ V_489 ;
F_45 ( V_8 , V_487 , V_486 ) ;
}
static void F_235 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_486 ;
int V_11 , V_12 ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_486 = F_11 ( V_8 , V_487 ) ;
V_486 &= ~ V_490 ;
F_45 ( V_8 , V_487 , V_486 ) ;
break;
case V_72 :
case V_73 :
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ ) {
V_12 = V_2 -> V_30 [ V_11 ] -> V_102 ;
V_486 = F_11 ( V_8 , F_16 ( V_12 ) ) ;
V_486 &= ~ V_491 ;
F_45 ( V_8 , F_16 ( V_12 ) , V_486 ) ;
}
break;
default:
break;
}
}
static void F_236 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_486 ;
int V_11 , V_12 ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_486 = F_11 ( V_8 , V_487 ) ;
V_486 |= V_490 ;
F_45 ( V_8 , V_487 , V_486 ) ;
break;
case V_72 :
case V_73 :
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ ) {
V_12 = V_2 -> V_30 [ V_11 ] -> V_102 ;
V_486 = F_11 ( V_8 , F_16 ( V_12 ) ) ;
V_486 |= V_491 ;
F_45 ( V_8 , F_16 ( V_12 ) , V_486 ) ;
}
break;
default:
break;
}
}
static void F_237 ( struct V_1 * V_2 )
{
T_5 V_225 ;
F_231 ( V_2 -> V_18 , 0 ) ;
F_238 (vid, adapter->active_vlans, VLAN_N_VID)
F_231 ( V_2 -> V_18 , V_225 ) ;
}
static int F_239 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_61 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
unsigned int V_492 = V_2 -> V_268 ;
unsigned int V_493 = V_494 ;
int V_52 = 0 ;
if ( F_240 ( V_18 ) > V_493 )
return - V_495 ;
if ( ! F_241 ( V_18 ) && V_493 ) {
struct V_496 * V_497 ;
if ( ! V_8 -> V_69 . V_305 . V_498 )
return - V_495 ;
F_242 (ha, netdev) {
if ( ! V_493 )
break;
V_8 -> V_69 . V_305 . V_498 ( V_8 , V_493 -- , V_497 -> V_499 ,
V_492 , V_500 ) ;
V_52 ++ ;
}
}
for (; V_493 > 0 ; V_493 -- )
V_8 -> V_69 . V_305 . V_501 ( V_8 , V_493 ) ;
return V_52 ;
}
void F_243 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_61 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_502 , V_503 = V_504 | V_505 ;
int V_52 ;
V_502 = F_11 ( V_8 , V_506 ) ;
V_502 &= ~ V_507 ;
V_502 |= V_508 ;
V_502 |= V_509 ;
V_502 |= V_510 ;
V_502 &= ~ ( V_511 | V_512 ) ;
if ( V_18 -> V_144 & V_513 ) {
V_8 -> V_514 . V_515 = true ;
V_502 |= ( V_511 | V_512 ) ;
V_503 |= ( V_516 | V_517 ) ;
F_233 ( V_2 ) ;
} else {
if ( V_18 -> V_144 & V_518 ) {
V_502 |= V_512 ;
V_503 |= V_517 ;
} else {
V_8 -> V_69 . V_305 . V_519 ( V_8 , V_18 ) ;
V_503 |= V_520 ;
}
F_234 ( V_2 ) ;
V_8 -> V_514 . V_515 = false ;
V_52 = F_239 ( V_18 ) ;
if ( V_52 < 0 ) {
V_502 |= V_511 ;
V_503 |= V_516 ;
}
}
if ( V_2 -> V_268 ) {
F_244 ( V_2 ) ;
V_503 |= F_11 ( V_8 , F_245 ( V_2 -> V_268 ) ) &
~ ( V_517 | V_520 |
V_516 ) ;
F_45 ( V_8 , F_245 ( V_2 -> V_268 ) , V_503 ) ;
}
if ( V_2 -> V_18 -> V_156 & V_240 ) {
V_502 |= ( V_507 |
V_508 |
V_510 ) ;
V_502 &= ~ ( V_509 ) ;
}
F_45 ( V_8 , V_506 , V_502 ) ;
if ( V_18 -> V_156 & V_521 )
F_236 ( V_2 ) ;
else
F_235 ( V_2 ) ;
}
static void F_246 ( struct V_1 * V_2 )
{
int V_522 ;
struct V_111 * V_112 ;
int V_266 = V_2 -> V_148 - V_149 ;
if ( ! ( V_2 -> V_144 & V_147 ) )
V_266 = 1 ;
for ( V_522 = 0 ; V_522 < V_266 ; V_522 ++ ) {
V_112 = V_2 -> V_112 [ V_522 ] ;
F_247 ( & V_112 -> V_227 ) ;
}
}
static void F_248 ( struct V_1 * V_2 )
{
int V_522 ;
struct V_111 * V_112 ;
int V_266 = V_2 -> V_148 - V_149 ;
if ( ! ( V_2 -> V_144 & V_147 ) )
V_266 = 1 ;
for ( V_522 = 0 ; V_522 < V_266 ; V_522 ++ ) {
V_112 = V_2 -> V_112 [ V_522 ] ;
F_249 ( & V_112 -> V_227 ) ;
}
}
static void F_250 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_460 = V_2 -> V_18 -> V_261 + V_205 + V_432 ;
if ( ! ( V_2 -> V_144 & V_523 ) ) {
if ( V_8 -> V_69 . type == V_70 )
F_251 ( V_2 -> V_18 , 65536 ) ;
return;
}
if ( V_8 -> V_69 . type == V_70 )
F_251 ( V_2 -> V_18 , 32768 ) ;
V_2 -> V_18 -> V_156 |= V_521 ;
V_8 -> V_69 . V_305 . V_484 ( & V_2 -> V_8 , 0 , 0 , true ) ;
#ifdef F_119
if ( V_2 -> V_18 -> V_156 & V_524 )
V_460 = F_166 ( V_460 , V_463 ) ;
#endif
if ( V_2 -> V_525 & V_526 ) {
F_252 ( V_8 , & V_2 -> V_94 , V_460 ,
V_527 ) ;
F_252 ( V_8 , & V_2 -> V_94 , V_460 ,
V_528 ) ;
F_253 ( V_8 , & V_2 -> V_94 ) ;
} else if ( V_2 -> V_529 && V_2 -> V_530 ) {
F_254 ( & V_2 -> V_8 ,
V_2 -> V_529 ,
V_460 ) ;
F_255 ( & V_2 -> V_8 ,
V_2 -> V_530 -> V_531 ,
V_2 -> V_529 -> V_532 ) ;
}
if ( V_8 -> V_69 . type != V_70 ) {
int V_11 ;
T_1 V_370 = 0 ;
for ( V_11 = 0 ; V_11 < V_533 ; V_11 ++ ) {
T_4 V_534 = 0 ;
T_4 V_535 = V_2 -> V_18 -> V_536 [ V_11 ] . V_52 ;
while ( V_535 >>= 1 )
V_534 ++ ;
V_370 |= V_534 << F_256 ( V_11 ) ;
}
F_45 ( V_8 , V_537 , V_370 ) ;
}
}
static int F_257 ( struct V_1 * V_2 , int V_538 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_37 = V_2 -> V_18 ;
int V_338 , V_98 , V_539 , V_540 ;
T_1 V_541 , V_542 ;
V_98 = V_338 = V_37 -> V_261 + V_205 + V_432 + V_543 ;
#ifdef F_119
if ( V_37 -> V_156 & V_524 ) {
int V_544 = 0 ;
#ifdef F_258
V_544 = F_259 ( V_37 , V_2 -> V_545 . V_546 ) ;
#endif
if ( V_544 == V_538 && V_98 < V_463 )
V_98 = V_463 ;
}
#endif
switch ( V_8 -> V_69 . type ) {
case V_73 :
V_541 = F_260 ( V_338 , V_98 ) ;
break;
default:
V_541 = F_261 ( V_338 , V_98 ) ;
break;
}
if ( V_2 -> V_144 & V_374 )
V_541 += F_262 ( V_98 ) ;
V_539 = F_263 ( V_541 ) ;
V_542 = F_11 ( V_8 , F_264 ( V_538 ) ) >> 10 ;
V_540 = V_542 - V_539 ;
if ( V_540 < 0 ) {
F_265 ( V_125 , L_71
L_72
L_73 , V_538 ) ;
V_540 = V_98 + 1 ;
}
return V_540 ;
}
static int F_266 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_37 = V_2 -> V_18 ;
int V_98 ;
T_1 V_541 ;
V_98 = V_37 -> V_261 + V_205 + V_432 ;
switch ( V_8 -> V_69 . type ) {
case V_73 :
V_541 = F_267 ( V_98 ) ;
break;
default:
V_541 = F_268 ( V_98 ) ;
break;
}
return F_263 ( V_541 ) ;
}
static void F_269 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_547 = F_205 ( V_2 -> V_18 ) ;
int V_11 ;
if ( ! V_547 )
V_547 = 1 ;
V_8 -> V_86 . V_548 = F_266 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_547 ; V_11 ++ ) {
V_8 -> V_86 . V_549 [ V_11 ] = F_257 ( V_2 , V_11 ) ;
if ( V_8 -> V_86 . V_548 > V_8 -> V_86 . V_549 [ V_11 ] )
V_8 -> V_86 . V_548 = 0 ;
}
}
static void F_270 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_550 ;
T_4 V_98 = F_205 ( V_2 -> V_18 ) ;
if ( V_2 -> V_144 & V_332 ||
V_2 -> V_144 & V_551 )
V_550 = 32 << V_2 -> V_552 ;
else
V_550 = 0 ;
V_8 -> V_69 . V_305 . V_553 ( V_8 , V_98 , V_550 , V_554 ) ;
F_269 ( V_2 ) ;
}
static void F_271 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_555 * V_556 , * V_557 ;
struct V_558 * V_559 ;
F_272 ( & V_2 -> V_560 ) ;
if ( ! F_273 ( & V_2 -> V_561 ) )
F_274 ( V_8 , & V_2 -> V_562 ) ;
F_275 (filter, node, node2,
&adapter->fdir_filter_list, fdir_node) {
F_276 ( V_8 ,
& V_559 -> V_559 ,
V_559 -> V_563 ,
( V_559 -> V_564 == V_565 ) ?
V_565 :
V_2 -> V_30 [ V_559 -> V_564 ] -> V_102 ) ;
}
F_277 ( & V_2 -> V_560 ) ;
}
static void F_278 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
F_270 ( V_2 ) ;
#ifdef F_258
F_250 ( V_2 ) ;
#endif
F_243 ( V_2 -> V_18 ) ;
F_237 ( V_2 ) ;
#ifdef F_119
if ( V_2 -> V_144 & V_165 )
F_279 ( V_2 ) ;
#endif
switch ( V_8 -> V_69 . type ) {
case V_72 :
case V_73 :
V_8 -> V_69 . V_305 . V_566 ( V_8 ) ;
break;
default:
break;
}
if ( V_2 -> V_144 & V_332 ) {
F_280 ( & V_2 -> V_8 ,
V_2 -> V_552 ) ;
} else if ( V_2 -> V_144 & V_551 ) {
F_281 ( & V_2 -> V_8 ,
V_2 -> V_552 ) ;
F_271 ( V_2 ) ;
}
switch ( V_8 -> V_69 . type ) {
case V_72 :
case V_73 :
V_8 -> V_69 . V_305 . V_567 ( V_8 ) ;
break;
default:
break;
}
F_222 ( V_2 ) ;
F_206 ( V_2 ) ;
F_230 ( V_2 ) ;
}
static inline bool F_282 ( struct V_7 * V_8 )
{
switch ( V_8 -> V_309 . type ) {
case V_568 :
case V_569 :
case V_570 :
case V_571 :
case V_572 :
case V_573 :
case V_574 :
case V_575 :
return true ;
case V_576 :
if ( V_8 -> V_69 . type == V_70 )
return true ;
default:
return false ;
}
}
static void F_283 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_69 . type == V_70 )
V_2 -> V_109 |= V_577 ;
V_2 -> V_109 |= V_317 ;
}
static int F_284 ( struct V_7 * V_8 )
{
T_1 V_307 ;
bool V_578 , V_308 = false ;
T_1 V_108 = V_579 ;
if ( V_8 -> V_69 . V_305 . V_306 )
V_108 = V_8 -> V_69 . V_305 . V_306 ( V_8 , & V_307 , & V_308 , false ) ;
if ( V_108 )
goto V_580;
V_307 = V_8 -> V_309 . V_581 ;
if ( ( ! V_307 ) && ( V_8 -> V_69 . V_305 . V_582 ) )
V_108 = V_8 -> V_69 . V_305 . V_582 ( V_8 , & V_307 ,
& V_578 ) ;
if ( V_108 )
goto V_580;
if ( V_8 -> V_69 . V_305 . V_583 )
V_108 = V_8 -> V_69 . V_305 . V_583 ( V_8 , V_307 , V_578 , V_308 ) ;
V_580:
return V_108 ;
}
static void F_285 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_584 = 0 ;
if ( V_2 -> V_144 & V_147 ) {
V_584 = V_585 | V_586 |
V_587 ;
V_584 |= V_588 ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
F_45 ( V_8 , V_589 , V_590 ) ;
break;
case V_72 :
case V_73 :
default:
F_45 ( V_8 , F_286 ( 0 ) , 0xFFFFFFFF ) ;
F_45 ( V_8 , F_286 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_45 ( V_8 , V_589 , V_590 ) ;
}
if ( V_2 -> V_144 & V_374 ) {
V_584 &= ~ V_591 ;
V_584 |= V_592 ;
}
if ( V_2 -> V_109 & V_299 ) {
switch ( V_2 -> V_8 . V_69 . type ) {
case V_72 :
V_584 |= V_593 ;
break;
case V_73 :
V_584 |= V_328 ;
break;
default:
break;
}
}
if ( V_2 -> V_144 & V_312 )
V_584 |= V_594 ;
if ( V_8 -> V_69 . type == V_72 ) {
V_584 |= V_594 ;
V_584 |= V_595 ;
}
F_45 ( V_8 , V_596 , V_584 ) ;
}
static void F_287 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_348 ;
T_1 V_61 ;
F_46 ( V_2 ) ;
F_285 ( V_2 ) ;
if ( V_2 -> V_144 & V_147 )
F_161 ( V_2 ) ;
else
F_199 ( V_2 ) ;
if ( V_8 -> V_69 . V_305 . V_597 &&
( ( V_8 -> V_309 . V_598 ) ||
( ( V_8 -> V_69 . V_305 . V_599 ( V_8 ) == V_600 ) &&
( V_8 -> V_69 . type == V_72 ) ) ) )
V_8 -> V_69 . V_305 . V_597 ( V_8 ) ;
F_8 ( V_3 , & V_2 -> V_4 ) ;
F_246 ( V_2 ) ;
if ( F_282 ( V_8 ) ) {
F_283 ( V_2 ) ;
} else {
V_348 = F_284 ( V_8 ) ;
if ( V_348 )
F_74 ( V_127 , L_74 , V_348 ) ;
}
F_11 ( V_8 , V_314 ) ;
F_178 ( V_2 , true , true ) ;
if ( V_2 -> V_144 & V_312 ) {
T_1 V_601 = F_11 ( V_8 , V_602 ) ;
if ( V_601 & V_603 )
F_168 ( V_125 , L_54 ) ;
}
F_288 ( V_2 -> V_18 ) ;
V_2 -> V_144 |= V_320 ;
V_2 -> V_321 = V_126 ;
F_289 ( & V_2 -> V_604 , V_126 ) ;
V_61 = F_11 ( V_8 , V_62 ) ;
V_61 |= V_605 ;
F_45 ( V_8 , V_62 , V_61 ) ;
}
void F_290 ( struct V_1 * V_2 )
{
F_291 ( F_292 () ) ;
V_2 -> V_18 -> V_38 = V_126 ;
while ( F_3 ( V_606 , & V_2 -> V_4 ) )
F_203 ( 1000 , 2000 ) ;
F_293 ( V_2 ) ;
if ( V_2 -> V_144 & V_374 )
F_294 ( 2000 ) ;
F_295 ( V_2 ) ;
F_8 ( V_606 , & V_2 -> V_4 ) ;
}
void F_295 ( struct V_1 * V_2 )
{
F_278 ( V_2 ) ;
F_287 ( V_2 ) ;
}
void F_296 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_348 ;
while ( F_3 ( V_607 , & V_2 -> V_4 ) )
F_203 ( 1000 , 2000 ) ;
V_2 -> V_109 &= ~ ( V_577 |
V_317 ) ;
V_2 -> V_144 &= ~ V_318 ;
V_348 = V_8 -> V_69 . V_305 . V_608 ( V_8 ) ;
switch ( V_348 ) {
case 0 :
case V_609 :
case V_610 :
break;
case V_611 :
F_297 ( L_75 ) ;
break;
case V_612 :
F_298 ( L_76
L_77
L_78
L_79
L_80
L_81 ) ;
break;
default:
F_297 ( L_82 , V_348 ) ;
}
F_8 ( V_607 , & V_2 -> V_4 ) ;
V_8 -> V_69 . V_305 . V_498 ( V_8 , 0 , V_8 -> V_69 . V_499 , V_2 -> V_268 ,
V_500 ) ;
}
static void F_299 ( struct V_20 * V_30 )
{
struct V_33 * V_245 = V_30 -> V_34 ;
T_5 V_11 ;
for ( V_11 = 0 ; V_11 < V_30 -> V_52 ; V_11 += 2 ) {
V_245 [ 0 ] . V_188 = 0 ;
V_245 [ 1 ] . V_188 = F_43 ( V_30 ) ;
V_245 = & V_245 [ 2 ] ;
}
}
static void F_300 ( struct V_20 * V_30 )
{
struct V_150 * V_37 = V_30 -> V_37 ;
unsigned long V_250 ;
T_5 V_11 ;
if ( ! V_30 -> V_34 )
return;
for ( V_11 = 0 ; V_11 < V_30 -> V_52 ; V_11 ++ ) {
struct V_33 * V_245 ;
V_245 = & V_30 -> V_34 [ V_11 ] ;
if ( V_245 -> V_53 ) {
struct V_155 * V_53 = V_245 -> V_53 ;
if ( F_122 ( V_53 ) -> V_238 ) {
F_54 ( V_37 ,
F_122 ( V_53 ) -> V_45 ,
F_43 ( V_30 ) ,
V_187 ) ;
F_122 ( V_53 ) -> V_238 = false ;
}
F_301 ( V_53 ) ;
}
V_245 -> V_53 = NULL ;
if ( V_245 -> V_45 )
F_54 ( V_37 , V_245 -> V_45 ,
F_112 ( V_30 ) ,
V_187 ) ;
V_245 -> V_45 = 0 ;
if ( V_245 -> V_183 )
F_114 ( V_245 -> V_183 ) ;
V_245 -> V_183 = NULL ;
}
V_250 = sizeof( struct V_33 ) * V_30 -> V_52 ;
memset ( V_30 -> V_34 , 0 , V_250 ) ;
F_299 ( V_30 ) ;
memset ( V_30 -> V_51 , 0 , V_30 -> V_250 ) ;
V_30 -> V_181 = 0 ;
V_30 -> V_43 = 0 ;
V_30 -> V_44 = 0 ;
}
static void F_302 ( struct V_20 * V_21 )
{
struct V_22 * V_42 ;
unsigned long V_250 ;
T_5 V_11 ;
if ( ! V_21 -> V_42 )
return;
for ( V_11 = 0 ; V_11 < V_21 -> V_52 ; V_11 ++ ) {
V_42 = & V_21 -> V_42 [ V_11 ] ;
F_51 ( V_21 , V_42 ) ;
}
F_303 ( F_78 ( V_21 ) ) ;
V_250 = sizeof( struct V_22 ) * V_21 -> V_52 ;
memset ( V_21 -> V_42 , 0 , V_250 ) ;
memset ( V_21 -> V_51 , 0 , V_21 -> V_250 ) ;
V_21 -> V_44 = 0 ;
V_21 -> V_43 = 0 ;
}
static void F_304 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ )
F_300 ( V_2 -> V_30 [ V_11 ] ) ;
}
static void F_305 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_302 ( V_2 -> V_21 [ V_11 ] ) ;
}
static void F_306 ( struct V_1 * V_2 )
{
struct V_555 * V_556 , * V_557 ;
struct V_558 * V_559 ;
F_272 ( & V_2 -> V_560 ) ;
F_275 (filter, node, node2,
&adapter->fdir_filter_list, fdir_node) {
F_307 ( & V_559 -> V_613 ) ;
F_193 ( V_559 ) ;
}
V_2 -> V_614 = 0 ;
F_277 ( & V_2 -> V_560 ) ;
}
void F_293 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_137 ;
int V_11 ;
F_202 ( V_3 , & V_2 -> V_4 ) ;
V_137 = F_11 ( V_8 , V_479 ) ;
F_45 ( V_8 , V_479 , V_137 & ~ V_480 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ )
F_217 ( V_2 , V_2 -> V_30 [ V_11 ] ) ;
F_203 ( 10000 , 20000 ) ;
F_308 ( V_18 ) ;
F_309 ( V_18 ) ;
F_310 ( V_18 ) ;
F_197 ( V_2 ) ;
F_248 ( V_2 ) ;
V_2 -> V_109 &= ~ ( V_333 |
V_110 ) ;
V_2 -> V_144 &= ~ V_320 ;
F_311 ( & V_2 -> V_604 ) ;
if ( V_2 -> V_268 ) {
F_45 ( & V_2 -> V_8 , V_270 , 0 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_268 ; V_11 ++ )
V_2 -> V_458 [ V_11 ] . V_615 = false ;
F_312 ( V_2 ) ;
F_313 ( V_2 ) ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
T_4 V_102 = V_2 -> V_21 [ V_11 ] -> V_102 ;
F_45 ( V_8 , F_24 ( V_102 ) , V_616 ) ;
}
switch ( V_8 -> V_69 . type ) {
case V_72 :
case V_73 :
F_45 ( V_8 , V_385 ,
( F_11 ( V_8 , V_385 ) &
~ V_386 ) ) ;
break;
default:
break;
}
if ( ! F_314 ( V_2 -> V_36 ) )
F_296 ( V_2 ) ;
if ( V_8 -> V_69 . V_305 . V_617 &&
( ( V_8 -> V_309 . V_598 ) ||
( ( V_8 -> V_69 . V_305 . V_599 ( V_8 ) == V_600 ) &&
( V_8 -> V_69 . type == V_72 ) ) ) )
V_8 -> V_69 . V_305 . V_617 ( V_8 ) ;
F_305 ( V_2 ) ;
F_304 ( V_2 ) ;
#ifdef F_186
F_94 ( V_2 ) ;
#endif
}
static void F_315 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_61 ( V_18 ) ;
F_64 ( V_2 ) ;
}
static int T_11 F_316 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_618 * V_36 = V_2 -> V_36 ;
unsigned int V_161 ;
#ifdef F_258
int V_12 ;
struct V_619 * V_98 ;
#endif
V_8 -> V_620 = V_36 -> V_621 ;
V_8 -> V_301 = V_36 -> V_150 ;
V_8 -> V_622 = V_36 -> V_623 ;
V_8 -> V_624 = V_36 -> V_625 ;
V_8 -> V_626 = V_36 -> V_627 ;
V_161 = F_317 ( int , V_628 , F_318 () ) ;
V_2 -> V_390 [ V_391 ] . V_405 = V_161 ;
V_2 -> V_144 |= V_408 ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
if ( V_8 -> V_301 == V_629 )
V_2 -> V_144 |= V_312 ;
V_2 -> V_630 = V_631 ;
break;
case V_73 :
V_2 -> V_109 |= V_299 ;
case V_72 :
V_2 -> V_630 = V_632 ;
V_2 -> V_109 |= V_633 ;
V_2 -> V_109 |= V_469 ;
if ( V_8 -> V_301 == V_302 )
V_2 -> V_109 |= V_299 ;
V_2 -> V_144 |= V_332 ;
V_2 -> V_365 = 20 ;
V_2 -> V_390 [ V_634 ] . V_405 =
V_635 ;
V_2 -> V_552 = V_636 ;
#ifdef F_119
V_2 -> V_144 |= V_637 ;
V_2 -> V_144 &= ~ V_165 ;
V_2 -> V_390 [ V_638 ] . V_405 = 0 ;
#ifdef F_258
V_2 -> V_545 . V_546 = V_639 ;
#endif
#endif
break;
default:
break;
}
F_319 ( & V_2 -> V_560 ) ;
#ifdef F_258
switch ( V_8 -> V_69 . type ) {
case V_73 :
V_2 -> V_94 . V_640 . V_641 = V_642 ;
V_2 -> V_94 . V_640 . V_643 = V_642 ;
break;
default:
V_2 -> V_94 . V_640 . V_641 = V_533 ;
V_2 -> V_94 . V_640 . V_643 = V_533 ;
break;
}
for ( V_12 = 0 ; V_12 < V_533 ; V_12 ++ ) {
V_98 = & V_2 -> V_94 . V_644 [ V_12 ] ;
V_98 -> V_645 [ V_527 ] . V_646 = 0 ;
V_98 -> V_645 [ V_527 ] . V_647 = 12 + ( V_12 & 1 ) ;
V_98 -> V_645 [ V_528 ] . V_646 = 0 ;
V_98 -> V_645 [ V_528 ] . V_647 = 12 + ( V_12 & 1 ) ;
V_98 -> V_648 = V_649 ;
}
V_98 = & V_2 -> V_94 . V_644 [ 0 ] ;
V_98 -> V_645 [ V_527 ] . V_650 = 0xFF ;
V_98 -> V_645 [ V_528 ] . V_650 = 0xFF ;
V_2 -> V_94 . V_651 [ V_527 ] [ 0 ] = 100 ;
V_2 -> V_94 . V_651 [ V_528 ] [ 0 ] = 100 ;
V_2 -> V_94 . V_95 = false ;
V_2 -> V_652 = 0x00 ;
V_2 -> V_525 = V_653 | V_526 ;
memcpy ( & V_2 -> V_654 , & V_2 -> V_94 ,
sizeof( V_2 -> V_654 ) ) ;
#endif
V_8 -> V_86 . V_655 = V_88 ;
V_8 -> V_86 . V_87 = V_88 ;
#ifdef F_320
V_2 -> V_656 = V_8 -> V_86 . V_87 ;
#endif
F_269 ( V_2 ) ;
V_8 -> V_86 . V_657 = V_658 ;
V_8 -> V_86 . V_659 = true ;
V_8 -> V_86 . V_660 = false ;
V_2 -> V_274 = 1 ;
V_2 -> V_271 = 1 ;
V_2 -> V_661 = V_662 ;
V_2 -> V_663 = V_664 ;
V_2 -> V_665 = V_666 ;
if ( F_321 ( V_8 ) ) {
F_297 ( L_83 ) ;
return - V_667 ;
}
F_202 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
}
int F_322 ( struct V_20 * V_21 )
{
struct V_150 * V_37 = V_21 -> V_37 ;
int V_668 = F_323 ( V_37 ) ;
int V_669 = - 1 ;
int V_250 ;
V_250 = sizeof( struct V_22 ) * V_21 -> V_52 ;
if ( V_21 -> V_112 )
V_669 = V_21 -> V_112 -> V_669 ;
V_21 -> V_42 = F_324 ( V_250 , V_669 ) ;
if ( ! V_21 -> V_42 )
V_21 -> V_42 = F_325 ( V_250 ) ;
if ( ! V_21 -> V_42 )
goto V_348;
V_21 -> V_250 = V_21 -> V_52 * sizeof( union V_24 ) ;
V_21 -> V_250 = F_142 ( V_21 -> V_250 , 4096 ) ;
F_326 ( V_37 , V_669 ) ;
V_21 -> V_51 = F_327 ( V_37 ,
V_21 -> V_250 ,
& V_21 -> V_45 ,
V_670 ) ;
F_326 ( V_37 , V_668 ) ;
if ( ! V_21 -> V_51 )
V_21 -> V_51 = F_327 ( V_37 , V_21 -> V_250 ,
& V_21 -> V_45 , V_670 ) ;
if ( ! V_21 -> V_51 )
goto V_348;
V_21 -> V_44 = 0 ;
V_21 -> V_43 = 0 ;
return 0 ;
V_348:
F_328 ( V_21 -> V_42 ) ;
V_21 -> V_42 = NULL ;
F_329 ( V_37 , L_84 ) ;
return - V_495 ;
}
static int F_330 ( struct V_1 * V_2 )
{
int V_11 , V_348 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
V_348 = F_322 ( V_2 -> V_21 [ V_11 ] ) ;
if ( ! V_348 )
continue;
F_74 ( V_127 , L_85 , V_11 ) ;
break;
}
return V_348 ;
}
int F_331 ( struct V_20 * V_30 )
{
struct V_150 * V_37 = V_30 -> V_37 ;
int V_668 = F_323 ( V_37 ) ;
int V_669 = - 1 ;
int V_250 ;
V_250 = sizeof( struct V_33 ) * V_30 -> V_52 ;
if ( V_30 -> V_112 )
V_669 = V_30 -> V_112 -> V_669 ;
V_30 -> V_34 = F_324 ( V_250 , V_669 ) ;
if ( ! V_30 -> V_34 )
V_30 -> V_34 = F_325 ( V_250 ) ;
if ( ! V_30 -> V_34 )
goto V_348;
V_30 -> V_250 = V_30 -> V_52 * sizeof( union V_31 ) ;
V_30 -> V_250 = F_142 ( V_30 -> V_250 , 4096 ) ;
F_326 ( V_37 , V_669 ) ;
V_30 -> V_51 = F_327 ( V_37 ,
V_30 -> V_250 ,
& V_30 -> V_45 ,
V_670 ) ;
F_326 ( V_37 , V_668 ) ;
if ( ! V_30 -> V_51 )
V_30 -> V_51 = F_327 ( V_37 , V_30 -> V_250 ,
& V_30 -> V_45 , V_670 ) ;
if ( ! V_30 -> V_51 )
goto V_348;
V_30 -> V_43 = 0 ;
V_30 -> V_44 = 0 ;
F_299 ( V_30 ) ;
return 0 ;
V_348:
F_328 ( V_30 -> V_34 ) ;
V_30 -> V_34 = NULL ;
F_329 ( V_37 , L_86 ) ;
return - V_495 ;
}
static int F_332 ( struct V_1 * V_2 )
{
int V_11 , V_348 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ ) {
V_348 = F_331 ( V_2 -> V_30 [ V_11 ] ) ;
if ( ! V_348 )
continue;
F_74 ( V_127 , L_87 , V_11 ) ;
break;
}
return V_348 ;
}
void F_333 ( struct V_20 * V_21 )
{
F_302 ( V_21 ) ;
F_328 ( V_21 -> V_42 ) ;
V_21 -> V_42 = NULL ;
if ( ! V_21 -> V_51 )
return;
F_334 ( V_21 -> V_37 , V_21 -> V_250 ,
V_21 -> V_51 , V_21 -> V_45 ) ;
V_21 -> V_51 = NULL ;
}
static void F_335 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
if ( V_2 -> V_21 [ V_11 ] -> V_51 )
F_333 ( V_2 -> V_21 [ V_11 ] ) ;
}
void F_336 ( struct V_20 * V_30 )
{
F_300 ( V_30 ) ;
F_328 ( V_30 -> V_34 ) ;
V_30 -> V_34 = NULL ;
if ( ! V_30 -> V_51 )
return;
F_334 ( V_30 -> V_37 , V_30 -> V_250 ,
V_30 -> V_51 , V_30 -> V_45 ) ;
V_30 -> V_51 = NULL ;
}
static void F_337 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ )
if ( V_2 -> V_30 [ V_11 ] -> V_51 )
F_336 ( V_2 -> V_30 [ V_11 ] ) ;
}
static int F_338 ( struct V_17 * V_18 , int V_671 )
{
struct V_1 * V_2 = F_61 ( V_18 ) ;
int V_460 = V_671 + V_205 + V_432 ;
if ( ( V_671 < 68 ) || ( V_460 > V_672 ) )
return - V_673 ;
if ( ( V_2 -> V_144 & V_374 ) &&
( V_2 -> V_8 . V_69 . type == V_72 ) &&
( V_460 > V_674 ) )
return - V_673 ;
F_76 ( V_127 , L_88 , V_18 -> V_261 , V_671 ) ;
V_18 -> V_261 = V_671 ;
if ( F_31 ( V_18 ) )
F_290 ( V_2 ) ;
return 0 ;
}
static int F_339 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_61 ( V_18 ) ;
int V_348 ;
if ( F_2 ( V_675 , & V_2 -> V_4 ) )
return - V_676 ;
F_309 ( V_18 ) ;
V_348 = F_330 ( V_2 ) ;
if ( V_348 )
goto V_677;
V_348 = F_332 ( V_2 ) ;
if ( V_348 )
goto V_678;
F_278 ( V_2 ) ;
V_348 = F_195 ( V_2 ) ;
if ( V_348 )
goto V_679;
F_287 ( V_2 ) ;
return 0 ;
V_679:
V_678:
F_337 ( V_2 ) ;
V_677:
F_335 ( V_2 ) ;
F_296 ( V_2 ) ;
return V_348 ;
}
static int F_340 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_61 ( V_18 ) ;
F_293 ( V_2 ) ;
F_196 ( V_2 ) ;
F_306 ( V_2 ) ;
F_335 ( V_2 ) ;
F_337 ( V_2 ) ;
F_44 ( V_2 ) ;
return 0 ;
}
static int F_341 ( struct V_618 * V_36 )
{
struct V_1 * V_2 = F_342 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_348 ;
F_343 ( V_36 , V_680 ) ;
F_344 ( V_36 ) ;
F_345 ( V_36 ) ;
V_348 = F_346 ( V_36 ) ;
if ( V_348 ) {
F_297 ( L_89 ) ;
return V_348 ;
}
F_347 ( V_36 ) ;
F_348 ( V_36 , false ) ;
F_349 () ;
V_348 = F_350 ( V_2 ) ;
F_351 () ;
if ( V_348 ) {
F_297 ( L_90 ) ;
return V_348 ;
}
F_296 ( V_2 ) ;
F_45 ( & V_2 -> V_8 , V_681 , ~ 0 ) ;
if ( F_31 ( V_18 ) ) {
V_348 = F_339 ( V_18 ) ;
if ( V_348 )
return V_348 ;
}
F_352 ( V_18 ) ;
return 0 ;
}
static int F_353 ( struct V_618 * V_36 , bool * V_682 )
{
struct V_1 * V_2 = F_342 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_683 , V_502 ;
T_1 V_684 = V_2 -> V_685 ;
#ifdef F_354
int V_686 = 0 ;
#endif
F_355 ( V_18 ) ;
if ( F_31 ( V_18 ) ) {
F_349 () ;
F_293 ( V_2 ) ;
F_196 ( V_2 ) ;
F_335 ( V_2 ) ;
F_337 ( V_2 ) ;
F_351 () ;
}
F_356 ( V_2 ) ;
#ifdef F_354
V_686 = F_345 ( V_36 ) ;
if ( V_686 )
return V_686 ;
#endif
if ( V_684 ) {
F_243 ( V_18 ) ;
if ( V_8 -> V_69 . V_305 . V_597 &&
( V_8 -> V_309 . V_598 ||
( V_8 -> V_69 . V_305 . V_599 ( V_8 ) == V_600 &&
V_8 -> V_69 . type == V_72 ) ) )
V_8 -> V_69 . V_305 . V_597 ( V_8 ) ;
if ( V_684 & V_687 ) {
V_502 = F_11 ( V_8 , V_506 ) ;
V_502 |= V_512 ;
F_45 ( V_8 , V_506 , V_502 ) ;
}
V_683 = F_11 ( V_8 , V_688 ) ;
V_683 |= V_689 ;
F_45 ( V_8 , V_688 , V_683 ) ;
F_45 ( V_8 , V_690 , V_684 ) ;
} else {
F_45 ( V_8 , V_691 , 0 ) ;
F_45 ( V_8 , V_690 , 0 ) ;
}
switch ( V_8 -> V_69 . type ) {
case V_70 :
F_348 ( V_36 , false ) ;
break;
case V_72 :
case V_73 :
F_348 ( V_36 , ! ! V_684 ) ;
break;
default:
break;
}
* V_682 = ! ! V_684 ;
F_44 ( V_2 ) ;
F_357 ( V_36 ) ;
return 0 ;
}
static int F_358 ( struct V_618 * V_36 , T_12 V_4 )
{
int V_686 ;
bool V_692 ;
V_686 = F_353 ( V_36 , & V_692 ) ;
if ( V_686 )
return V_686 ;
if ( V_692 ) {
F_359 ( V_36 ) ;
} else {
F_348 ( V_36 , false ) ;
F_343 ( V_36 , V_693 ) ;
}
return 0 ;
}
static void F_360 ( struct V_618 * V_36 )
{
bool V_692 ;
F_353 ( V_36 , & V_692 ) ;
if ( V_694 == V_695 ) {
F_348 ( V_36 , V_692 ) ;
F_343 ( V_36 , V_693 ) ;
}
}
void F_361 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_81 * V_82 = & V_2 -> V_83 ;
T_2 V_696 = 0 ;
T_1 V_11 , V_697 = 0 , V_698 , V_699 , V_700 , V_701 , V_702 ;
T_2 V_232 = 0 , V_129 = 0 , V_703 = 0 ;
T_2 V_186 = 0 , V_258 = 0 ;
T_2 V_124 = 0 , V_100 = 0 , V_704 = 0 ;
#ifdef F_119
struct V_705 * V_545 = & V_2 -> V_545 ;
unsigned int V_130 ;
T_2 V_706 = 0 , V_707 = 0 ;
#endif
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_606 , & V_2 -> V_4 ) )
return;
if ( V_2 -> V_109 & V_469 ) {
T_2 V_222 = 0 ;
T_2 V_223 = 0 ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
V_2 -> V_708 +=
F_11 ( V_8 , F_362 ( V_11 ) ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ ) {
V_222 += V_2 -> V_30 [ V_11 ] -> V_172 . V_222 ;
V_223 += V_2 -> V_30 [ V_11 ] -> V_172 . V_223 ;
}
V_2 -> V_709 = V_222 ;
V_2 -> V_710 = V_223 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ ) {
struct V_20 * V_30 = V_2 -> V_30 [ V_11 ] ;
V_232 += V_30 -> V_172 . V_232 ;
V_186 += V_30 -> V_172 . V_186 ;
V_258 += V_30 -> V_172 . V_258 ;
V_704 += V_30 -> V_172 . V_173 ;
V_124 += V_30 -> V_83 . V_124 ;
V_100 += V_30 -> V_83 . V_100 ;
}
V_2 -> V_232 = V_232 ;
V_2 -> V_186 = V_186 ;
V_2 -> V_258 = V_258 ;
V_2 -> V_704 = V_704 ;
V_18 -> V_83 . V_711 = V_124 ;
V_18 -> V_83 . V_712 = V_100 ;
V_124 = 0 ;
V_100 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_21 = V_2 -> V_21 [ V_11 ] ;
V_129 += V_21 -> V_106 . V_129 ;
V_703 += V_21 -> V_106 . V_703 ;
V_124 += V_21 -> V_83 . V_124 ;
V_100 += V_21 -> V_83 . V_100 ;
}
V_2 -> V_129 = V_129 ;
V_2 -> V_703 = V_703 ;
V_18 -> V_83 . V_713 = V_124 ;
V_18 -> V_83 . V_714 = V_100 ;
V_82 -> V_715 += F_11 ( V_8 , V_716 ) ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_698 = F_11 ( V_8 , F_363 ( V_11 ) ) ;
V_697 += V_698 ;
V_82 -> V_698 [ V_11 ] += V_698 ;
V_696 += V_82 -> V_698 [ V_11 ] ;
V_82 -> V_717 [ V_11 ] += F_11 ( V_8 , F_364 ( V_11 ) ) ;
V_82 -> V_718 [ V_11 ] += F_11 ( V_8 , F_365 ( V_11 ) ) ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_82 -> V_719 [ V_11 ] += F_11 ( V_8 , F_366 ( V_11 ) ) ;
V_82 -> V_720 [ V_11 ] += F_11 ( V_8 , F_367 ( V_11 ) ) ;
V_82 -> V_721 [ V_11 ] += F_11 ( V_8 , F_368 ( V_11 ) ) ;
V_82 -> V_722 [ V_11 ] +=
F_11 ( V_8 , F_369 ( V_11 ) ) ;
break;
case V_72 :
case V_73 :
V_82 -> V_722 [ V_11 ] +=
F_11 ( V_8 , F_370 ( V_11 ) ) ;
break;
default:
break;
}
}
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ ) {
V_82 -> V_723 [ V_11 ] += F_11 ( V_8 , F_371 ( V_11 ) ) ;
V_82 -> V_724 [ V_11 ] += F_11 ( V_8 , F_372 ( V_11 ) ) ;
if ( ( V_8 -> V_69 . type == V_72 ) ||
( V_8 -> V_69 . type == V_73 ) ) {
V_82 -> V_720 [ V_11 ] += F_11 ( V_8 , F_373 ( V_11 ) ) ;
F_11 ( V_8 , F_374 ( V_11 ) ) ;
V_82 -> V_721 [ V_11 ] += F_11 ( V_8 , F_375 ( V_11 ) ) ;
F_11 ( V_8 , F_376 ( V_11 ) ) ;
}
}
V_82 -> V_725 += F_11 ( V_8 , V_726 ) ;
V_82 -> V_725 -= V_697 ;
F_56 ( V_2 ) ;
switch ( V_8 -> V_69 . type ) {
case V_70 :
V_82 -> V_727 += F_11 ( V_8 , V_728 ) ;
V_82 -> V_729 += F_11 ( V_8 , V_730 ) ;
V_82 -> V_731 += F_11 ( V_8 , V_732 ) ;
V_82 -> V_733 += F_11 ( V_8 , V_734 ) ;
break;
case V_73 :
V_82 -> V_735 += F_11 ( V_8 , V_736 ) ;
V_82 -> V_737 += F_11 ( V_8 , V_738 ) ;
V_82 -> V_739 += F_11 ( V_8 , V_740 ) ;
V_82 -> V_741 += F_11 ( V_8 , V_742 ) ;
case V_72 :
V_82 -> V_729 += F_11 ( V_8 , V_743 ) ;
F_11 ( V_8 , V_730 ) ;
V_82 -> V_731 += F_11 ( V_8 , V_744 ) ;
F_11 ( V_8 , V_732 ) ;
V_82 -> V_733 += F_11 ( V_8 , V_745 ) ;
F_11 ( V_8 , V_734 ) ;
V_82 -> V_727 += F_11 ( V_8 , V_746 ) ;
V_82 -> V_747 += F_11 ( V_8 , V_748 ) ;
V_82 -> V_749 += F_11 ( V_8 , V_750 ) ;
#ifdef F_119
V_82 -> V_751 += F_11 ( V_8 , V_752 ) ;
V_82 -> V_753 += F_11 ( V_8 , V_754 ) ;
V_82 -> V_755 += F_11 ( V_8 , V_756 ) ;
V_82 -> V_757 += F_11 ( V_8 , V_758 ) ;
V_82 -> V_759 += F_11 ( V_8 , V_760 ) ;
V_82 -> V_761 += F_11 ( V_8 , V_762 ) ;
if ( V_545 -> V_763 && V_545 -> V_764 ) {
F_377 (cpu) {
V_706 +=
* F_378 ( V_545 -> V_763 , V_130 ) ;
V_707 +=
* F_378 ( V_545 ->
V_764 , V_130 ) ;
}
}
V_82 -> V_765 = V_706 ;
V_82 -> V_766 = V_707 ;
#endif
break;
default:
break;
}
V_699 = F_11 ( V_8 , V_767 ) ;
V_82 -> V_699 += V_699 ;
V_82 -> V_768 += F_11 ( V_8 , V_769 ) ;
if ( V_8 -> V_69 . type == V_70 )
V_82 -> V_768 -= V_699 ;
V_82 -> V_770 += F_11 ( V_8 , V_771 ) ;
V_82 -> V_772 += F_11 ( V_8 , V_773 ) ;
V_82 -> V_774 += F_11 ( V_8 , V_775 ) ;
V_82 -> V_776 += F_11 ( V_8 , V_777 ) ;
V_82 -> V_778 += F_11 ( V_8 , V_779 ) ;
V_82 -> V_780 += F_11 ( V_8 , V_781 ) ;
V_82 -> V_782 += F_11 ( V_8 , V_783 ) ;
V_82 -> V_784 += F_11 ( V_8 , V_785 ) ;
V_700 = F_11 ( V_8 , V_786 ) ;
V_82 -> V_787 += V_700 ;
V_701 = F_11 ( V_8 , V_788 ) ;
V_82 -> V_789 += V_701 ;
V_82 -> V_790 += F_11 ( V_8 , V_791 ) ;
V_82 -> V_792 += F_11 ( V_8 , V_793 ) ;
V_702 = V_700 + V_701 ;
V_82 -> V_790 -= V_702 ;
V_82 -> V_792 -= V_702 ;
V_82 -> V_731 -= ( V_702 * ( V_794 + V_432 ) ) ;
V_82 -> V_795 += F_11 ( V_8 , V_796 ) ;
V_82 -> V_797 += F_11 ( V_8 , V_798 ) ;
V_82 -> V_799 += F_11 ( V_8 , V_800 ) ;
V_82 -> V_801 += F_11 ( V_8 , V_802 ) ;
V_82 -> V_803 += F_11 ( V_8 , V_804 ) ;
V_82 -> V_803 -= V_702 ;
V_82 -> V_805 += F_11 ( V_8 , V_806 ) ;
V_82 -> V_807 += F_11 ( V_8 , V_808 ) ;
V_82 -> V_809 += F_11 ( V_8 , V_810 ) ;
V_82 -> V_811 += F_11 ( V_8 , V_812 ) ;
V_82 -> V_813 += F_11 ( V_8 , V_814 ) ;
V_82 -> V_815 += F_11 ( V_8 , V_816 ) ;
V_18 -> V_83 . V_817 = V_82 -> V_768 ;
V_18 -> V_83 . V_818 = V_82 -> V_715 + V_82 -> V_784 ;
V_18 -> V_83 . V_819 = 0 ;
V_18 -> V_83 . V_820 = V_82 -> V_784 ;
V_18 -> V_83 . V_821 = V_82 -> V_715 ;
V_18 -> V_83 . V_822 = V_696 ;
}
static void F_379 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_11 ;
if ( ! ( V_2 -> V_109 & V_333 ) )
return;
V_2 -> V_109 &= ~ V_333 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
if ( ! ( V_2 -> V_144 & V_332 ) )
return;
V_2 -> V_823 ++ ;
if ( F_380 ( V_8 ) == 0 ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_202 ( V_341 ,
& ( V_2 -> V_21 [ V_11 ] -> V_4 ) ) ;
F_45 ( V_8 , V_324 , V_334 ) ;
} else {
F_74 ( V_127 , L_91
L_92 ) ;
}
}
static void F_381 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_824 = 0 ;
int V_11 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_606 , & V_2 -> V_4 ) )
return;
if ( F_80 ( V_2 -> V_18 ) ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_382 ( V_2 -> V_21 [ V_11 ] ) ;
}
if ( ! ( V_2 -> V_144 & V_147 ) ) {
F_45 ( V_8 , V_78 ,
( V_825 | V_826 ) ) ;
} else {
for ( V_11 = 0 ; V_11 < V_2 -> V_148 - V_149 ; V_11 ++ ) {
struct V_111 * V_827 = V_2 -> V_112 [ V_11 ] ;
if ( V_827 -> V_265 . V_79 || V_827 -> V_116 . V_79 )
V_824 |= ( ( T_2 ) 1 << V_11 ) ;
}
}
F_49 ( V_2 , V_824 ) ;
}
static void F_383 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_828 = V_2 -> V_828 ;
bool V_308 = V_2 -> V_308 ;
int V_11 ;
if ( ! ( V_2 -> V_144 & V_320 ) )
return;
if ( V_8 -> V_69 . V_305 . V_306 ) {
V_8 -> V_69 . V_305 . V_306 ( V_8 , & V_828 , & V_308 , false ) ;
} else {
V_828 = V_829 ;
V_308 = true ;
}
if ( V_308 ) {
if ( V_2 -> V_144 & V_523 ) {
for ( V_11 = 0 ; V_11 < V_533 ; V_11 ++ )
V_8 -> V_69 . V_305 . V_830 ( V_8 , V_11 ) ;
} else {
V_8 -> V_69 . V_305 . V_830 ( V_8 , 0 ) ;
}
}
if ( V_308 ||
F_384 ( V_126 , ( V_2 -> V_321 +
V_831 ) ) ) {
V_2 -> V_144 &= ~ V_320 ;
F_45 ( V_8 , V_324 , V_323 ) ;
F_173 ( V_8 ) ;
}
V_2 -> V_308 = V_308 ;
V_2 -> V_828 = V_828 ;
}
static void F_385 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_828 = V_2 -> V_828 ;
bool V_832 , V_833 ;
if ( F_80 ( V_18 ) )
return;
V_2 -> V_109 &= ~ V_577 ;
switch ( V_8 -> V_69 . type ) {
case V_70 : {
T_1 V_834 = F_11 ( V_8 , V_506 ) ;
T_1 V_835 = F_11 ( V_8 , V_836 ) ;
V_832 = ! ! ( V_834 & V_837 ) ;
V_833 = ! ! ( V_835 & V_838 ) ;
}
break;
case V_73 :
case V_72 : {
T_1 V_839 = F_11 ( V_8 , V_840 ) ;
T_1 V_841 = F_11 ( V_8 , V_842 ) ;
V_832 = ! ! ( V_839 & V_843 ) ;
V_833 = ! ! ( V_841 & V_844 ) ;
}
break;
default:
V_833 = false ;
V_832 = false ;
break;
}
F_76 ( V_125 , L_93 ,
( V_828 == V_829 ?
L_94 :
( V_828 == V_845 ?
L_95 :
( V_828 == V_846 ?
L_96 :
L_97 ) ) ) ,
( ( V_832 && V_833 ) ? L_98 :
( V_832 ? L_99 :
( V_833 ? L_100 : L_101 ) ) ) ) ;
F_386 ( V_18 ) ;
F_387 ( V_2 ) ;
}
static void F_388 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
V_2 -> V_308 = false ;
V_2 -> V_828 = 0 ;
if ( ! F_80 ( V_18 ) )
return;
if ( F_282 ( V_8 ) && V_8 -> V_69 . type == V_70 )
V_2 -> V_109 |= V_577 ;
F_76 ( V_125 , L_102 ) ;
F_309 ( V_18 ) ;
}
static void F_389 ( struct V_1 * V_2 )
{
int V_11 ;
int V_847 = 0 ;
if ( ! F_80 ( V_2 -> V_18 ) ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_21 = V_2 -> V_21 [ V_11 ] ;
if ( V_21 -> V_44 != V_21 -> V_43 ) {
V_847 = 1 ;
break;
}
}
if ( V_847 ) {
V_2 -> V_109 |= V_110 ;
}
}
}
static void F_390 ( struct V_1 * V_2 )
{
T_1 V_848 ;
if ( V_2 -> V_8 . V_69 . type == V_70 )
return;
V_848 = F_11 ( & V_2 -> V_8 , V_849 ) ;
if ( ! V_848 )
return;
F_265 ( V_125 , L_103 , V_848 ) ;
}
static void F_391 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_606 , & V_2 -> V_4 ) )
return;
F_383 ( V_2 ) ;
if ( V_2 -> V_308 )
F_385 ( V_2 ) ;
else
F_388 ( V_2 ) ;
F_390 ( V_2 ) ;
F_361 ( V_2 ) ;
F_389 ( V_2 ) ;
}
static void F_392 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_13 V_348 ;
if ( ! ( V_2 -> V_109 & V_577 ) &&
! ( V_2 -> V_109 & V_317 ) )
return;
if ( F_3 ( V_607 , & V_2 -> V_4 ) )
return;
V_348 = V_8 -> V_309 . V_305 . V_850 ( V_8 ) ;
if ( V_348 == V_610 )
goto V_851;
if ( V_348 == V_609 ) {
V_2 -> V_109 |= V_317 ;
}
if ( V_348 )
goto V_851;
if ( ! ( V_2 -> V_109 & V_317 ) )
goto V_851;
V_2 -> V_109 &= ~ V_317 ;
if ( V_8 -> V_69 . type == V_70 )
V_348 = V_8 -> V_309 . V_305 . V_852 ( V_8 ) ;
else
V_348 = V_8 -> V_69 . V_305 . V_853 ( V_8 ) ;
if ( V_348 == V_610 )
goto V_851;
V_2 -> V_144 |= V_318 ;
F_76 ( V_127 , L_104 , V_8 -> V_309 . V_854 ) ;
V_851:
F_8 ( V_607 , & V_2 -> V_4 ) ;
if ( ( V_348 == V_610 ) &&
( V_2 -> V_18 -> V_855 == V_856 ) ) {
F_297 ( L_105
L_106 ) ;
F_297 ( L_107
L_108 ) ;
F_393 ( V_2 -> V_18 ) ;
}
}
static void F_394 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_307 ;
bool V_578 ;
if ( ! ( V_2 -> V_144 & V_318 ) )
return;
if ( F_3 ( V_607 , & V_2 -> V_4 ) )
return;
V_2 -> V_144 &= ~ V_318 ;
V_307 = V_8 -> V_309 . V_581 ;
if ( ( ! V_307 ) && ( V_8 -> V_69 . V_305 . V_582 ) )
V_8 -> V_69 . V_305 . V_582 ( V_8 , & V_307 , & V_578 ) ;
if ( V_8 -> V_69 . V_305 . V_583 )
V_8 -> V_69 . V_305 . V_583 ( V_8 , V_307 , V_578 , true ) ;
V_2 -> V_144 |= V_320 ;
V_2 -> V_321 = V_126 ;
F_8 ( V_607 , & V_2 -> V_4 ) ;
}
static void F_395 ( struct V_1 * V_2 )
{
int V_857 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_858 ;
T_1 V_859 , V_860 ;
V_858 = F_11 ( V_8 , V_861 ) ;
if ( V_858 )
return;
for ( V_857 = 0 ; V_857 < V_2 -> V_268 ; V_857 ++ ) {
V_859 = ( V_857 << 16 ) | 0x80000000 ;
V_859 |= V_862 ;
F_45 ( V_8 , V_863 , V_859 ) ;
V_860 = F_11 ( V_8 , V_864 ) ;
V_859 &= 0x7FFFFFFF ;
F_45 ( V_8 , V_863 , V_859 ) ;
V_860 >>= 16 ;
if ( V_860 & V_865 ) {
F_396 ( V_18 , L_109 , V_857 ) ;
V_859 = ( V_857 << 16 ) | 0x80000000 ;
V_859 |= 0xA8 ;
F_45 ( V_8 , V_863 , V_859 ) ;
V_860 = 0x00008000 ;
F_45 ( V_8 , V_864 , V_860 ) ;
V_859 &= 0x7FFFFFFF ;
F_45 ( V_8 , V_863 , V_859 ) ;
}
}
}
static void F_397 ( unsigned long V_84 )
{
struct V_1 * V_2 = (struct V_1 * ) V_84 ;
unsigned long V_866 ;
bool V_867 = true ;
if ( V_2 -> V_144 & V_320 )
V_866 = V_868 / 10 ;
else
V_866 = V_868 * 2 ;
#ifdef F_398
if ( ! V_2 -> V_268 ||
( V_2 -> V_144 & V_320 ) )
goto V_869;
F_395 ( V_2 ) ;
V_866 = V_868 / 50 ;
V_2 -> V_870 ++ ;
if ( V_2 -> V_870 >= 100 )
V_2 -> V_870 = 0 ;
else
V_867 = false ;
V_869:
#endif
F_289 ( & V_2 -> V_604 , V_866 + V_126 ) ;
if ( V_867 )
F_1 ( V_2 ) ;
}
static void F_399 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_109 & V_110 ) )
return;
V_2 -> V_109 &= ~ V_110 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_606 , & V_2 -> V_4 ) )
return;
F_28 ( V_2 ) ;
F_396 ( V_2 -> V_18 , L_110 ) ;
V_2 -> V_128 ++ ;
F_290 ( V_2 ) ;
}
static void F_400 ( struct V_871 * V_872 )
{
struct V_1 * V_2 = F_185 ( V_872 ,
struct V_1 ,
V_6 ) ;
F_399 ( V_2 ) ;
F_392 ( V_2 ) ;
F_394 ( V_2 ) ;
F_167 ( V_2 ) ;
F_391 ( V_2 ) ;
F_379 ( V_2 ) ;
F_381 ( V_2 ) ;
F_5 ( V_2 ) ;
}
static int F_401 ( struct V_20 * V_21 ,
struct V_22 * V_873 ,
T_4 * V_220 )
{
struct V_155 * V_53 = V_873 -> V_53 ;
T_1 V_874 , V_875 ;
T_1 V_876 , V_877 ;
if ( ! F_402 ( V_53 ) )
return 0 ;
if ( F_403 ( V_53 ) ) {
int V_348 = F_404 ( V_53 , 0 , 0 , V_184 ) ;
if ( V_348 )
return V_348 ;
}
V_875 = V_878 ;
if ( V_873 -> V_202 == F_118 ( V_210 ) ) {
struct V_199 * V_879 = F_405 ( V_53 ) ;
V_879 -> V_880 = 0 ;
V_879 -> V_881 = 0 ;
F_406 ( V_53 ) -> V_881 = ~ F_407 ( V_879 -> V_882 ,
V_879 -> V_883 , 0 ,
V_213 ,
0 ) ;
V_875 |= V_884 ;
V_873 -> V_885 |= V_886 |
V_887 |
V_888 ;
} else if ( F_408 ( V_53 ) ) {
F_409 ( V_53 ) -> V_889 = 0 ;
F_406 ( V_53 ) -> V_881 =
~ F_410 ( & F_409 ( V_53 ) -> V_882 ,
& F_409 ( V_53 ) -> V_883 ,
0 , V_213 , 0 ) ;
V_873 -> V_885 |= V_886 |
V_887 ;
}
V_877 = F_411 ( V_53 ) ;
* V_220 = F_412 ( V_53 ) + V_877 ;
V_873 -> V_122 = F_125 ( V_53 ) -> V_122 ;
V_873 -> V_121 += ( V_873 -> V_122 - 1 ) * * V_220 ;
V_876 = V_877 << V_890 ;
V_876 |= F_125 ( V_53 ) -> V_221 << V_891 ;
V_876 |= 1 << V_892 ;
V_874 = F_413 ( V_53 ) ;
V_874 |= F_414 ( V_53 ) << V_893 ;
V_874 |= V_873 -> V_885 & V_894 ;
F_415 ( V_21 , V_874 , 0 , V_875 ,
V_876 ) ;
return 1 ;
}
static void F_416 ( struct V_20 * V_21 ,
struct V_22 * V_873 )
{
struct V_155 * V_53 = V_873 -> V_53 ;
T_1 V_874 = 0 ;
T_1 V_876 = 0 ;
T_1 V_875 = 0 ;
if ( V_53 -> V_178 != V_895 ) {
if ( ! ( V_873 -> V_885 & V_896 ) &&
! ( V_873 -> V_885 & V_897 ) )
return;
} else {
T_4 V_898 = 0 ;
switch ( V_873 -> V_202 ) {
case F_118 ( V_210 ) :
V_874 |= F_413 ( V_53 ) ;
V_875 |= V_884 ;
V_898 = F_405 ( V_53 ) -> V_202 ;
break;
case F_118 ( V_899 ) :
V_874 |= F_413 ( V_53 ) ;
V_898 = F_409 ( V_53 ) -> V_203 ;
break;
default:
if ( F_68 ( F_417 () ) ) {
F_418 ( V_21 -> V_37 ,
L_111 ,
V_873 -> V_202 ) ;
}
break;
}
switch ( V_898 ) {
case V_213 :
V_875 |= V_878 ;
V_876 = F_411 ( V_53 ) <<
V_890 ;
break;
case V_900 :
V_875 |= V_901 ;
V_876 = sizeof( struct V_902 ) <<
V_890 ;
break;
case V_903 :
V_876 = sizeof( struct V_904 ) <<
V_890 ;
break;
default:
if ( F_68 ( F_417 () ) ) {
F_418 ( V_21 -> V_37 ,
L_112 ,
V_898 ) ;
}
break;
}
V_873 -> V_885 |= V_887 ;
}
V_874 |= F_414 ( V_53 ) << V_893 ;
V_874 |= V_873 -> V_885 & V_894 ;
F_415 ( V_21 , V_874 , 0 ,
V_875 , V_876 ) ;
}
static T_9 F_419 ( T_1 V_885 )
{
T_9 V_905 = F_67 ( V_906 |
V_907 |
V_908 ) ;
if ( V_885 & V_896 )
V_905 |= F_67 ( V_909 ) ;
#ifdef F_119
if ( V_885 & ( V_886 | V_910 ) )
#else
if ( V_885 & V_886 )
#endif
V_905 |= F_67 ( V_911 ) ;
return V_905 ;
}
static void F_420 ( union V_24 * V_25 ,
T_1 V_885 , unsigned int V_912 )
{
T_9 V_913 = F_67 ( V_912 << V_914 ) ;
if ( V_885 & V_887 )
V_913 |= F_67 ( V_915 ) ;
if ( V_885 & V_888 )
V_913 |= F_67 ( V_916 ) ;
#ifdef F_119
if ( V_885 & ( V_886 | V_917 ) )
#else
if ( V_885 & V_886 )
#endif
V_913 |= F_67 ( 1 << V_892 ) ;
#ifdef F_119
if ( V_885 & ( V_897 | V_917 ) )
#else
if ( V_885 & V_897 )
#endif
V_913 |= F_67 ( V_918 ) ;
V_25 -> V_190 . V_913 = V_913 ;
}
static void F_421 ( struct V_20 * V_21 ,
struct V_22 * V_873 ,
const T_4 V_220 )
{
T_7 V_45 ;
struct V_155 * V_53 = V_873 -> V_53 ;
struct V_22 * V_23 ;
union V_24 * V_25 ;
struct V_233 * V_234 = & F_125 ( V_53 ) -> V_235 [ 0 ] ;
unsigned int V_241 = V_53 -> V_241 ;
unsigned int V_250 = F_124 ( V_53 ) ;
unsigned int V_912 = V_53 -> V_46 - V_220 ;
T_1 V_885 = V_873 -> V_885 ;
T_9 V_905 ;
T_5 V_11 = V_21 -> V_44 ;
V_25 = F_35 ( V_21 , V_11 ) ;
F_420 ( V_25 , V_885 , V_912 ) ;
V_905 = F_419 ( V_885 ) ;
#ifdef F_119
if ( V_885 & V_917 ) {
if ( V_241 < sizeof( struct V_264 ) ) {
V_250 -= sizeof( struct V_264 ) - V_241 ;
V_241 = 0 ;
} else {
V_241 -= sizeof( struct V_264 ) ;
}
}
#endif
V_45 = F_422 ( V_21 -> V_37 , V_53 -> V_84 , V_250 , V_80 ) ;
if ( F_113 ( V_21 -> V_37 , V_45 ) )
goto V_919;
F_55 ( V_873 , V_46 , V_250 ) ;
F_423 ( V_873 , V_45 , V_45 ) ;
V_25 -> V_190 . V_920 = F_116 ( V_45 ) ;
for (; ; ) {
while ( F_68 ( V_250 > V_921 ) ) {
V_25 -> V_190 . V_922 =
V_905 | F_67 ( V_921 ) ;
V_11 ++ ;
V_25 ++ ;
if ( V_11 == V_21 -> V_52 ) {
V_25 = F_35 ( V_21 , 0 ) ;
V_11 = 0 ;
}
V_45 += V_921 ;
V_250 -= V_921 ;
V_25 -> V_190 . V_920 = F_116 ( V_45 ) ;
V_25 -> V_190 . V_913 = 0 ;
}
if ( F_70 ( ! V_241 ) )
break;
if ( F_68 ( V_53 -> V_923 ) )
V_905 &= ~ ( F_67 ( V_907 ) ) ;
V_25 -> V_190 . V_922 = V_905 | F_67 ( V_250 ) ;
V_11 ++ ;
V_25 ++ ;
if ( V_11 == V_21 -> V_52 ) {
V_25 = F_35 ( V_21 , 0 ) ;
V_11 = 0 ;
}
#ifdef F_119
V_250 = F_317 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_250 = F_140 ( V_234 ) ;
#endif
V_241 -= V_250 ;
V_45 = F_424 ( V_21 -> V_37 , V_234 , 0 , V_250 ,
V_80 ) ;
if ( F_113 ( V_21 -> V_37 , V_45 ) )
goto V_919;
V_23 = & V_21 -> V_42 [ V_11 ] ;
F_55 ( V_23 , V_46 , V_250 ) ;
F_423 ( V_23 , V_45 , V_45 ) ;
V_25 -> V_190 . V_920 = F_116 ( V_45 ) ;
V_25 -> V_190 . V_913 = 0 ;
V_234 ++ ;
}
V_905 |= F_67 ( V_250 ) | F_67 ( V_924 ) ;
V_25 -> V_190 . V_922 = V_905 ;
F_425 ( F_78 ( V_21 ) , V_873 -> V_121 ) ;
V_873 -> V_48 = V_126 ;
F_106 () ;
V_873 -> V_47 = V_25 ;
V_11 ++ ;
if ( V_11 == V_21 -> V_52 )
V_11 = 0 ;
V_21 -> V_44 = V_11 ;
F_107 ( V_11 , V_21 -> V_103 ) ;
return;
V_919:
F_329 ( V_21 -> V_37 , L_113 ) ;
for (; ; ) {
V_23 = & V_21 -> V_42 [ V_11 ] ;
F_51 ( V_21 , V_23 ) ;
if ( V_23 == V_873 )
break;
if ( V_11 == 0 )
V_11 = V_21 -> V_52 ;
V_11 -- ;
}
V_21 -> V_44 = V_11 ;
}
static void F_426 ( struct V_20 * V_79 ,
struct V_22 * V_873 )
{
struct V_111 * V_112 = V_79 -> V_112 ;
union V_925 V_926 = { . V_927 = 0 } ;
union V_925 V_928 = { . V_927 = 0 } ;
union {
unsigned char * V_194 ;
struct V_199 * V_200 ;
struct V_929 * V_930 ;
} V_201 ;
struct V_214 * V_931 ;
T_8 V_932 ;
if ( ! V_112 )
return;
if ( ! V_79 -> V_365 )
return;
V_79 -> V_366 ++ ;
V_201 . V_194 = F_427 ( V_873 -> V_53 ) ;
if ( ( V_873 -> V_202 != F_118 ( V_899 ) ||
V_201 . V_930 -> V_203 != V_213 ) &&
( V_873 -> V_202 != F_118 ( V_210 ) ||
V_201 . V_200 -> V_202 != V_213 ) )
return;
V_931 = F_406 ( V_873 -> V_53 ) ;
if ( ! V_931 || V_931 -> V_933 )
return;
if ( ! V_931 -> V_934 && ( V_79 -> V_366 < V_79 -> V_365 ) )
return;
V_79 -> V_366 = 0 ;
V_932 = F_428 ( V_873 -> V_885 >> V_935 ) ;
V_926 . V_936 . V_932 = V_932 ;
if ( V_873 -> V_885 & ( V_937 | V_896 ) )
V_928 . V_938 . V_939 ^= V_931 -> V_940 ^ F_118 ( V_207 ) ;
else
V_928 . V_938 . V_939 ^= V_931 -> V_940 ^ V_873 -> V_202 ;
V_928 . V_938 . V_941 ^= V_931 -> V_942 ;
if ( V_873 -> V_202 == F_118 ( V_210 ) ) {
V_926 . V_936 . V_943 = V_944 ;
V_928 . V_945 ^= V_201 . V_200 -> V_882 ^ V_201 . V_200 -> V_883 ;
} else {
V_926 . V_936 . V_943 = V_946 ;
V_928 . V_945 ^= V_201 . V_930 -> V_882 . V_947 [ 0 ] ^
V_201 . V_930 -> V_882 . V_947 [ 1 ] ^
V_201 . V_930 -> V_882 . V_947 [ 2 ] ^
V_201 . V_930 -> V_882 . V_947 [ 3 ] ^
V_201 . V_930 -> V_883 . V_947 [ 0 ] ^
V_201 . V_930 -> V_883 . V_947 [ 1 ] ^
V_201 . V_930 -> V_883 . V_947 [ 2 ] ^
V_201 . V_930 -> V_883 . V_947 [ 3 ] ;
}
F_429 ( & V_112 -> V_2 -> V_8 ,
V_926 , V_928 , V_79 -> V_50 ) ;
}
static int F_430 ( struct V_20 * V_21 , T_5 V_250 )
{
F_75 ( V_21 -> V_18 , V_21 -> V_50 ) ;
F_82 () ;
if ( F_70 ( F_81 ( V_21 ) < V_250 ) )
return - V_676 ;
F_431 ( V_21 -> V_18 , V_21 -> V_50 ) ;
++ V_21 -> V_106 . V_129 ;
return 0 ;
}
static inline int F_432 ( struct V_20 * V_21 , T_5 V_250 )
{
if ( F_70 ( F_81 ( V_21 ) >= V_250 ) )
return 0 ;
return F_430 ( V_21 , V_250 ) ;
}
static T_5 F_433 ( struct V_17 * V_37 , struct V_155 * V_53 )
{
struct V_1 * V_2 = F_61 ( V_37 ) ;
int V_948 = F_434 ( V_53 ) ? F_435 ( V_53 ) :
F_436 () ;
#ifdef F_119
T_8 V_202 = F_437 ( V_53 ) ;
if ( ( ( V_202 == F_428 ( V_211 ) ) ||
( V_202 == F_428 ( V_949 ) ) ) &&
( V_2 -> V_144 & V_165 ) ) {
V_948 &= ( V_2 -> V_390 [ V_638 ] . V_405 - 1 ) ;
V_948 += V_2 -> V_390 [ V_638 ] . V_76 ;
return V_948 ;
}
#endif
if ( V_2 -> V_144 & V_332 ) {
while ( F_68 ( V_948 >= V_37 -> V_950 ) )
V_948 -= V_37 -> V_950 ;
return V_948 ;
}
return F_438 ( V_37 , V_53 ) ;
}
T_14 F_439 ( struct V_155 * V_53 ,
struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_22 * V_873 ;
int V_951 ;
T_1 V_885 = 0 ;
#if V_396 > V_921
unsigned short V_952 ;
#endif
T_5 V_52 = F_440 ( F_124 ( V_53 ) ) ;
T_8 V_202 = V_53 -> V_202 ;
T_4 V_220 = 0 ;
#if V_396 > V_921
for ( V_952 = 0 ; V_952 < F_125 ( V_53 ) -> V_242 ; V_952 ++ )
V_52 += F_440 ( F_125 ( V_53 ) -> V_235 [ V_952 ] . V_250 ) ;
#else
V_52 += F_125 ( V_53 ) -> V_242 ;
#endif
if ( F_432 ( V_21 , V_52 + 3 ) ) {
V_21 -> V_106 . V_703 ++ ;
return V_953 ;
}
V_873 = & V_21 -> V_42 [ V_21 -> V_44 ] ;
V_873 -> V_53 = V_53 ;
V_873 -> V_121 = V_53 -> V_46 ;
V_873 -> V_122 = 1 ;
if ( F_441 ( V_53 ) ) {
V_885 |= F_442 ( V_53 ) << V_935 ;
V_885 |= V_896 ;
} else if ( V_202 == F_118 ( V_207 ) ) {
struct V_197 * V_954 , V_955 ;
V_954 = F_443 ( V_53 , V_205 , sizeof( V_955 ) , & V_955 ) ;
if ( ! V_954 )
goto V_956;
V_202 = V_954 -> V_209 ;
V_885 |= F_444 ( V_954 -> V_957 ) <<
V_935 ;
V_885 |= V_937 ;
}
#ifdef F_398
if ( V_2 -> V_144 & V_374 )
V_885 |= V_897 ;
#endif
if ( ( V_2 -> V_144 & V_523 ) &&
( ( V_885 & ( V_896 | V_937 ) ) ||
( V_53 -> V_958 != V_959 ) ) ) {
V_885 &= ~ V_960 ;
V_885 |= ( V_53 -> V_958 & 0x7 ) <<
V_961 ;
if ( V_885 & V_937 ) {
struct V_962 * V_954 ;
if ( F_403 ( V_53 ) &&
F_404 ( V_53 , 0 , 0 , V_184 ) )
goto V_956;
V_954 = (struct V_962 * ) V_53 -> V_84 ;
V_954 -> V_957 = F_428 ( V_885 >>
V_935 ) ;
} else {
V_885 |= V_896 ;
}
}
V_873 -> V_885 = V_885 ;
V_873 -> V_202 = V_202 ;
#ifdef F_119
if ( ( V_202 == F_118 ( V_211 ) ) &&
( V_2 -> V_144 & V_165 ) ) {
V_951 = F_445 ( V_21 , V_873 , & V_220 ) ;
if ( V_951 < 0 )
goto V_956;
goto V_963;
}
#endif
V_951 = F_401 ( V_21 , V_873 , & V_220 ) ;
if ( V_951 < 0 )
goto V_956;
else if ( ! V_951 )
F_416 ( V_21 , V_873 ) ;
if ( F_2 ( V_341 , & V_21 -> V_4 ) )
F_426 ( V_21 , V_873 ) ;
#ifdef F_119
V_963:
#endif
F_421 ( V_21 , V_873 , V_220 ) ;
F_432 ( V_21 , V_964 ) ;
return V_965 ;
V_956:
F_52 ( V_873 -> V_53 ) ;
V_873 -> V_53 = NULL ;
return V_965 ;
}
static T_14 F_446 ( struct V_155 * V_53 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_61 ( V_18 ) ;
struct V_20 * V_21 ;
if ( V_53 -> V_46 <= 0 ) {
F_52 ( V_53 ) ;
return V_965 ;
}
if ( V_53 -> V_46 < 17 ) {
if ( F_447 ( V_53 , 17 ) )
return V_965 ;
V_53 -> V_46 = 17 ;
}
V_21 = V_2 -> V_21 [ V_53 -> V_966 ] ;
return F_439 ( V_53 , V_2 , V_21 ) ;
}
static int F_448 ( struct V_17 * V_18 , void * V_434 )
{
struct V_1 * V_2 = F_61 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_967 * V_499 = V_434 ;
if ( ! F_449 ( V_499 -> V_968 ) )
return - V_969 ;
memcpy ( V_18 -> V_970 , V_499 -> V_968 , V_18 -> V_971 ) ;
memcpy ( V_8 -> V_69 . V_499 , V_499 -> V_968 , V_18 -> V_971 ) ;
V_8 -> V_69 . V_305 . V_498 ( V_8 , 0 , V_8 -> V_69 . V_499 , V_2 -> V_268 ,
V_500 ) ;
return 0 ;
}
static int
F_450 ( struct V_17 * V_18 , int V_972 , int V_973 , T_5 V_499 )
{
struct V_1 * V_2 = F_61 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_5 V_974 ;
int V_975 ;
if ( V_972 != V_8 -> V_309 . V_976 . V_972 )
return - V_673 ;
V_975 = V_8 -> V_309 . V_305 . V_977 ( V_8 , V_499 , V_973 , & V_974 ) ;
if ( ! V_975 )
V_975 = V_974 ;
return V_975 ;
}
static int F_451 ( struct V_17 * V_18 , int V_972 , int V_973 ,
T_5 V_499 , T_5 V_974 )
{
struct V_1 * V_2 = F_61 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( V_972 != V_8 -> V_309 . V_976 . V_972 )
return - V_673 ;
return V_8 -> V_309 . V_305 . V_978 ( V_8 , V_499 , V_973 , V_974 ) ;
}
static int F_452 ( struct V_17 * V_18 , struct V_979 * V_980 , int V_981 )
{
struct V_1 * V_2 = F_61 ( V_18 ) ;
return F_453 ( & V_2 -> V_8 . V_309 . V_976 , F_454 ( V_980 ) , V_981 ) ;
}
static int F_455 ( struct V_17 * V_37 )
{
int V_348 = 0 ;
struct V_1 * V_2 = F_61 ( V_37 ) ;
struct V_982 * V_69 = & V_2 -> V_8 . V_69 ;
if ( F_449 ( V_69 -> V_983 ) ) {
F_349 () ;
V_348 = F_456 ( V_37 , V_69 -> V_983 , V_984 ) ;
F_351 () ;
}
return V_348 ;
}
static int F_457 ( struct V_17 * V_37 )
{
int V_348 = 0 ;
struct V_1 * V_2 = F_61 ( V_37 ) ;
struct V_982 * V_69 = & V_2 -> V_8 . V_69 ;
if ( F_449 ( V_69 -> V_983 ) ) {
F_349 () ;
V_348 = F_458 ( V_37 , V_69 -> V_983 , V_984 ) ;
F_351 () ;
}
return V_348 ;
}
static void F_459 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_61 ( V_18 ) ;
int V_11 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
V_2 -> V_144 |= V_226 ;
if ( V_2 -> V_144 & V_147 ) {
int V_143 = V_2 -> V_148 - V_149 ;
for ( V_11 = 0 ; V_11 < V_143 ; V_11 ++ ) {
struct V_111 * V_112 = V_2 -> V_112 [ V_11 ] ;
F_182 ( 0 , V_112 ) ;
}
} else {
F_194 ( V_2 -> V_36 -> V_335 , V_18 ) ;
}
V_2 -> V_144 &= ~ V_226 ;
}
static struct V_985 * F_460 ( struct V_17 * V_18 ,
struct V_985 * V_83 )
{
struct V_1 * V_2 = F_61 ( V_18 ) ;
int V_11 ;
F_461 () ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ ) {
struct V_20 * V_79 = F_462 ( V_2 -> V_30 [ V_11 ] ) ;
T_2 V_124 , V_100 ;
unsigned int V_986 ;
if ( V_79 ) {
do {
V_986 = F_463 ( & V_79 -> V_123 ) ;
V_100 = V_79 -> V_83 . V_100 ;
V_124 = V_79 -> V_83 . V_124 ;
} while ( F_464 ( & V_79 -> V_123 , V_986 ) );
V_83 -> V_712 += V_100 ;
V_83 -> V_711 += V_124 ;
}
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_79 = F_462 ( V_2 -> V_21 [ V_11 ] ) ;
T_2 V_124 , V_100 ;
unsigned int V_986 ;
if ( V_79 ) {
do {
V_986 = F_463 ( & V_79 -> V_123 ) ;
V_100 = V_79 -> V_83 . V_100 ;
V_124 = V_79 -> V_83 . V_124 ;
} while ( F_464 ( & V_79 -> V_123 , V_986 ) );
V_83 -> V_714 += V_100 ;
V_83 -> V_713 += V_124 ;
}
}
F_465 () ;
V_83 -> V_817 = V_18 -> V_83 . V_817 ;
V_83 -> V_818 = V_18 -> V_83 . V_818 ;
V_83 -> V_820 = V_18 -> V_83 . V_820 ;
V_83 -> V_821 = V_18 -> V_83 . V_821 ;
V_83 -> V_822 = V_18 -> V_83 . V_822 ;
return V_83 ;
}
static void F_466 ( struct V_1 * V_2 , T_4 V_98 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_370 , V_987 ;
int V_11 ;
if ( V_8 -> V_69 . type == V_70 )
return;
V_370 = F_11 ( V_8 , V_988 ) ;
V_987 = V_370 ;
for ( V_11 = 0 ; V_11 < V_533 ; V_11 ++ ) {
T_4 V_989 = V_370 >> ( V_11 * V_990 ) ;
if ( V_989 > V_98 )
V_370 &= ~ ( 0x7 << V_990 ) ;
}
if ( V_370 != V_987 )
F_45 ( V_8 , V_988 , V_370 ) ;
return;
}
int F_467 ( struct V_17 * V_37 , T_4 V_98 )
{
struct V_1 * V_2 = F_61 ( V_37 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( ! ( V_2 -> V_144 & V_147 ) ) {
F_74 ( V_125 , L_114 ) ;
return - V_673 ;
}
if ( V_98 > V_2 -> V_94 . V_640 . V_641 ||
( V_8 -> V_69 . type == V_70 &&
V_98 < V_533 ) )
return - V_673 ;
if ( F_31 ( V_37 ) )
F_340 ( V_37 ) ;
F_356 ( V_2 ) ;
if ( V_98 ) {
F_468 ( V_37 , V_98 ) ;
V_2 -> V_656 = V_2 -> V_8 . V_86 . V_87 ;
V_2 -> V_144 |= V_523 ;
V_2 -> V_144 &= ~ V_332 ;
if ( V_2 -> V_8 . V_69 . type == V_70 )
V_2 -> V_8 . V_86 . V_655 = V_991 ;
} else {
F_469 ( V_37 ) ;
V_2 -> V_8 . V_86 . V_655 = V_2 -> V_656 ;
V_2 -> V_144 &= ~ V_523 ;
V_2 -> V_144 |= V_332 ;
V_2 -> V_654 . V_95 = false ;
V_2 -> V_94 . V_95 = false ;
}
F_350 ( V_2 ) ;
F_466 ( V_2 , V_98 ) ;
if ( F_31 ( V_37 ) )
F_339 ( V_37 ) ;
return 0 ;
}
void F_470 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_61 ( V_18 ) ;
if ( F_31 ( V_18 ) )
F_290 ( V_2 ) ;
else
F_296 ( V_2 ) ;
}
static T_15 F_471 ( struct V_17 * V_18 ,
T_15 V_156 )
{
struct V_1 * V_2 = F_61 ( V_18 ) ;
#ifdef F_320
if ( V_2 -> V_144 & V_523 )
V_156 &= ~ V_521 ;
#endif
if ( ! ( V_2 -> V_144 & V_408 ) )
V_156 &= ~ V_157 ;
if ( ! ( V_156 & V_169 ) )
V_156 &= ~ V_992 ;
if ( ! ( V_2 -> V_109 & V_633 ) )
V_156 &= ~ V_992 ;
return V_156 ;
}
static int F_472 ( struct V_17 * V_18 ,
T_15 V_156 )
{
struct V_1 * V_2 = F_61 ( V_18 ) ;
T_15 V_993 = V_18 -> V_156 ^ V_156 ;
bool V_994 = false ;
if ( ! ( V_156 & V_992 ) ) {
if ( V_2 -> V_109 & V_469 )
V_994 = true ;
V_2 -> V_109 &= ~ V_469 ;
} else if ( ( V_2 -> V_109 & V_633 ) &&
! ( V_2 -> V_109 & V_469 ) ) {
if ( V_2 -> V_274 == 1 ||
V_2 -> V_274 > V_995 ) {
V_2 -> V_109 |= V_469 ;
V_994 = true ;
} else if ( ( V_993 ^ V_156 ) & V_992 ) {
F_76 ( V_127 , L_115
L_116 ) ;
}
}
if ( ! ( V_156 & V_996 ) ) {
if ( V_2 -> V_144 & V_551 ) {
if ( ( V_2 -> V_144 & V_408 ) &&
! ( V_2 -> V_144 & V_523 ) )
V_2 -> V_144 |= V_332 ;
V_994 = true ;
}
V_2 -> V_144 &= ~ V_551 ;
} else if ( ! ( V_2 -> V_144 & V_551 ) ) {
V_2 -> V_144 &= ~ V_332 ;
V_2 -> V_144 |= V_551 ;
V_994 = true ;
}
if ( V_993 & V_240 )
V_994 = true ;
V_18 -> V_156 = V_156 ;
if ( V_994 )
F_470 ( V_18 ) ;
return 0 ;
}
static void T_11 F_473 ( struct V_1 * V_2 ,
const struct V_997 * V_998 )
{
#ifdef F_398
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( V_8 -> V_69 . type == V_70 )
return;
V_2 -> V_268 = ( V_999 > 63 ) ? 63 : V_999 ;
F_474 ( V_2 , V_998 ) ;
#endif
}
static int T_11 F_475 ( struct V_618 * V_36 ,
const struct V_1000 * V_1001 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 = NULL ;
struct V_7 * V_8 ;
const struct V_997 * V_998 = V_1002 [ V_1001 -> V_1003 ] ;
static int V_1004 ;
int V_11 , V_348 , V_1005 ;
T_4 V_1006 [ V_1007 ] ;
unsigned int V_405 = F_476 () ;
#ifdef F_119
T_5 V_1008 ;
#endif
T_1 V_1009 ;
T_5 V_1010 ;
if ( V_36 -> V_1011 ) {
F_477 ( 1 , V_1012 L_117 ,
F_478 ( V_36 ) , V_36 -> V_621 , V_36 -> V_150 ) ;
return - V_673 ;
}
V_348 = F_346 ( V_36 ) ;
if ( V_348 )
return V_348 ;
if ( ! F_479 ( & V_36 -> V_37 , F_201 ( 64 ) ) &&
! F_480 ( & V_36 -> V_37 , F_201 ( 64 ) ) ) {
V_1005 = 1 ;
} else {
V_348 = F_479 ( & V_36 -> V_37 , F_201 ( 32 ) ) ;
if ( V_348 ) {
V_348 = F_480 ( & V_36 -> V_37 ,
F_201 ( 32 ) ) ;
if ( V_348 ) {
F_329 ( & V_36 -> V_37 ,
L_118 ) ;
goto V_1013;
}
}
V_1005 = 0 ;
}
V_348 = F_481 ( V_36 , F_482 ( V_36 ,
V_1014 ) , V_1015 ) ;
if ( V_348 ) {
F_329 ( & V_36 -> V_37 ,
L_119 , V_348 ) ;
goto V_1016;
}
F_483 ( V_36 ) ;
F_347 ( V_36 ) ;
F_345 ( V_36 ) ;
#ifdef F_258
V_405 *= V_533 ;
#endif
if ( V_998 -> V_69 == V_70 )
V_405 = F_317 (unsigned int, indices, IXGBE_MAX_RSS_INDICES) ;
else
V_405 = F_317 (unsigned int, indices, IXGBE_MAX_FDIR_INDICES) ;
#ifdef F_119
V_405 += F_317 (unsigned int, num_possible_cpus(),
IXGBE_MAX_FCOE_INDICES) ;
#endif
V_18 = F_484 ( sizeof( struct V_1 ) , V_405 ) ;
if ( ! V_18 ) {
V_348 = - V_495 ;
goto V_1017;
}
F_485 ( V_18 , & V_36 -> V_37 ) ;
V_2 = F_61 ( V_18 ) ;
F_486 ( V_36 , V_2 ) ;
V_2 -> V_18 = V_18 ;
V_2 -> V_36 = V_36 ;
V_8 = & V_2 -> V_8 ;
V_8 -> V_1018 = V_2 ;
V_2 -> V_1019 = F_487 ( V_1020 , V_1021 ) ;
V_8 -> V_364 = F_488 ( F_489 ( V_36 , 0 ) ,
F_490 ( V_36 , 0 ) ) ;
if ( ! V_8 -> V_364 ) {
V_348 = - V_667 ;
goto V_1022;
}
for ( V_11 = 1 ; V_11 <= 5 ; V_11 ++ ) {
if ( F_490 ( V_36 , V_11 ) == 0 )
continue;
}
V_18 -> V_1023 = & V_1024 ;
F_491 ( V_18 ) ;
V_18 -> V_1025 = 5 * V_868 ;
strncpy ( V_18 -> V_16 , F_478 ( V_36 ) , sizeof( V_18 -> V_16 ) - 1 ) ;
V_2 -> V_1026 = V_1004 ;
memcpy ( & V_8 -> V_69 . V_305 , V_998 -> V_1027 , sizeof( V_8 -> V_69 . V_305 ) ) ;
V_8 -> V_69 . type = V_998 -> V_69 ;
memcpy ( & V_8 -> V_1028 . V_305 , V_998 -> V_1029 , sizeof( V_8 -> V_1028 . V_305 ) ) ;
V_1009 = F_11 ( V_8 , V_1030 ) ;
if ( ! ( V_1009 & ( 1 << 8 ) ) )
V_8 -> V_1028 . V_305 . V_190 = & V_1031 ;
memcpy ( & V_8 -> V_309 . V_305 , V_998 -> V_1032 , sizeof( V_8 -> V_309 . V_305 ) ) ;
V_8 -> V_309 . V_854 = V_1033 ;
V_8 -> V_309 . V_976 . V_972 = V_1034 ;
V_8 -> V_309 . V_976 . V_1035 = 0 ;
V_8 -> V_309 . V_976 . V_1036 = V_1037 | V_1038 ;
V_8 -> V_309 . V_976 . V_37 = V_18 ;
V_8 -> V_309 . V_976 . V_1039 = F_450 ;
V_8 -> V_309 . V_976 . V_1040 = F_451 ;
V_998 -> V_1041 ( V_8 ) ;
V_348 = F_316 ( V_2 ) ;
if ( V_348 )
goto V_1042;
switch ( V_2 -> V_8 . V_69 . type ) {
case V_72 :
case V_73 :
F_45 ( & V_2 -> V_8 , V_681 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_144 & V_312 ) {
T_1 V_601 = F_11 ( V_8 , V_602 ) ;
if ( V_601 & V_603 )
F_168 ( V_127 , L_54 ) ;
}
if ( V_1043 )
V_8 -> V_1043 = V_1043 ;
V_8 -> V_309 . V_1044 = true ;
V_348 = V_8 -> V_69 . V_305 . V_1045 ( V_8 ) ;
V_8 -> V_309 . V_1044 = false ;
if ( V_348 == V_609 &&
V_8 -> V_69 . type == V_70 ) {
V_348 = 0 ;
} else if ( V_348 == V_610 ) {
F_297 ( L_120
L_121 ) ;
F_297 ( L_122
L_123 ) ;
goto V_1042;
} else if ( V_348 ) {
F_297 ( L_124 , V_348 ) ;
goto V_1042;
}
F_473 ( V_2 , V_998 ) ;
V_18 -> V_156 = V_1046 |
V_1047 |
V_1048 |
V_1049 |
V_521 |
V_1050 |
V_1051 |
V_1052 |
V_157 |
V_169 ;
V_18 -> V_1053 = V_18 -> V_156 ;
switch ( V_2 -> V_8 . V_69 . type ) {
case V_72 :
case V_73 :
V_18 -> V_156 |= V_1054 ;
V_18 -> V_1053 |= V_1054 |
V_996 ;
break;
default:
break;
}
V_18 -> V_1053 |= V_240 ;
V_18 -> V_1055 |= V_1051 ;
V_18 -> V_1055 |= V_1052 ;
V_18 -> V_1055 |= V_1047 ;
V_18 -> V_1055 |= V_1048 ;
V_18 -> V_1055 |= V_1046 ;
V_18 -> V_1056 |= V_1057 ;
V_18 -> V_1056 |= V_1058 ;
if ( V_2 -> V_144 & V_374 )
V_2 -> V_144 &= ~ ( V_408 |
V_523 ) ;
#ifdef F_258
V_18 -> V_1059 = & V_1059 ;
#endif
#ifdef F_119
if ( V_2 -> V_144 & V_637 ) {
if ( V_8 -> V_69 . V_305 . V_1060 ) {
V_8 -> V_69 . V_305 . V_1060 ( V_8 , & V_1008 ) ;
if ( V_1008 & V_1061 )
V_2 -> V_144 &= ~ V_637 ;
}
}
if ( V_2 -> V_144 & V_637 ) {
V_18 -> V_1055 |= V_1062 ;
V_18 -> V_1055 |= V_1063 ;
V_18 -> V_1055 |= V_524 ;
}
#endif
if ( V_1005 ) {
V_18 -> V_156 |= V_1064 ;
V_18 -> V_1055 |= V_1064 ;
}
if ( V_2 -> V_109 & V_633 )
V_18 -> V_1053 |= V_992 ;
if ( V_2 -> V_109 & V_469 )
V_18 -> V_156 |= V_992 ;
if ( V_8 -> V_1028 . V_305 . V_1065 ( V_8 , NULL ) < 0 ) {
F_297 ( L_125 ) ;
V_348 = - V_667 ;
goto V_1042;
}
memcpy ( V_18 -> V_970 , V_8 -> V_69 . V_1066 , V_18 -> V_971 ) ;
memcpy ( V_18 -> V_1066 , V_8 -> V_69 . V_1066 , V_18 -> V_971 ) ;
if ( F_492 ( V_18 -> V_1066 ) ) {
F_297 ( L_126 ) ;
V_348 = - V_667 ;
goto V_1042;
}
F_493 ( & V_2 -> V_604 , & F_397 ,
( unsigned long ) V_2 ) ;
F_494 ( & V_2 -> V_6 , F_400 ) ;
F_8 ( V_5 , & V_2 -> V_4 ) ;
V_348 = F_350 ( V_2 ) ;
if ( V_348 )
goto V_1042;
if ( ! ( V_2 -> V_144 & V_408 ) ) {
V_18 -> V_1053 &= ~ V_157 ;
V_18 -> V_156 &= ~ V_157 ;
}
V_2 -> V_685 = 0 ;
switch ( V_36 -> V_150 ) {
case V_1067 :
switch ( V_36 -> V_627 ) {
case V_1068 :
if ( V_8 -> V_1069 . V_1070 != 0 )
break;
case V_1071 :
V_2 -> V_685 = V_1072 ;
break;
}
break;
case V_1073 :
if ( V_36 -> V_627 != V_1074 )
V_2 -> V_685 = V_1072 ;
break;
case V_1075 :
V_2 -> V_685 = V_1072 ;
break;
case V_1076 :
V_8 -> V_1028 . V_305 . V_190 ( V_8 , 0x2c , & V_2 -> V_1077 ) ;
V_1010 = V_2 -> V_1077 & V_1078 ;
if ( ( V_1010 == V_1079 ) ||
( ( V_1010 == V_1080 ) &&
( V_8 -> V_1069 . V_1070 == 0 ) ) )
V_2 -> V_685 = V_1072 ;
break;
}
F_495 ( & V_2 -> V_36 -> V_37 , V_2 -> V_685 ) ;
V_8 -> V_1028 . V_305 . V_190 ( V_8 , 0x2e , & V_2 -> V_1081 ) ;
V_8 -> V_1028 . V_305 . V_190 ( V_8 , 0x2d , & V_2 -> V_1082 ) ;
V_8 -> V_69 . V_305 . V_1083 ( V_8 ) ;
F_496 ( L_127 ,
( V_8 -> V_1069 . V_1084 == V_1085 ? L_128 :
V_8 -> V_1069 . V_1084 == V_1086 ? L_129 :
L_130 ) ,
( V_8 -> V_1069 . V_1087 == V_1088 ? L_131 :
V_8 -> V_1069 . V_1087 == V_1089 ? L_132 :
V_8 -> V_1069 . V_1087 == V_1090 ? L_133 :
L_130 ) ,
V_18 -> V_970 ) ;
V_348 = F_497 ( V_8 , V_1006 , V_1007 ) ;
if ( V_348 )
strncpy ( V_1006 , L_130 , V_1007 ) ;
if ( F_282 ( V_8 ) && V_8 -> V_309 . V_854 != V_1091 )
F_496 ( L_134 ,
V_8 -> V_69 . type , V_8 -> V_309 . type , V_8 -> V_309 . V_854 ,
V_1006 ) ;
else
F_496 ( L_135 ,
V_8 -> V_69 . type , V_8 -> V_309 . type , V_1006 ) ;
if ( V_8 -> V_1069 . V_1087 <= V_1089 ) {
F_298 ( L_136
L_137 ) ;
F_298 ( L_138
L_139 ) ;
}
V_348 = V_8 -> V_69 . V_305 . V_1092 ( V_8 ) ;
if ( V_348 == V_612 ) {
F_298 ( L_76
L_140
L_141
L_142
L_80
L_81 ) ;
}
strcpy ( V_18 -> V_16 , L_143 ) ;
V_348 = F_498 ( V_18 ) ;
if ( V_348 )
goto V_1093;
if ( V_8 -> V_69 . V_305 . V_617 &&
( ( V_8 -> V_309 . V_598 ) ||
( ( V_8 -> V_69 . V_305 . V_599 ( V_8 ) == V_600 ) &&
( V_8 -> V_69 . type == V_72 ) ) ) )
V_8 -> V_69 . V_305 . V_617 ( V_8 ) ;
F_309 ( V_18 ) ;
#ifdef F_186
if ( F_97 ( & V_36 -> V_37 ) == 0 ) {
V_2 -> V_144 |= V_145 ;
F_94 ( V_2 ) ;
}
#endif
if ( V_2 -> V_144 & V_374 ) {
F_76 ( V_127 , L_144 , V_2 -> V_268 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_268 ; V_11 ++ )
F_499 ( V_36 , ( V_11 | 0x10000000 ) ) ;
}
if ( V_8 -> V_69 . V_305 . V_1094 )
V_8 -> V_69 . V_305 . V_1094 ( V_8 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_455 ( V_18 ) ;
F_496 ( L_145 , V_1095 ) ;
V_1004 ++ ;
return 0 ;
V_1093:
F_44 ( V_2 ) ;
F_356 ( V_2 ) ;
V_1042:
if ( V_2 -> V_144 & V_374 )
F_500 ( V_2 ) ;
V_2 -> V_109 &= ~ V_577 ;
F_501 ( V_8 -> V_364 ) ;
V_1022:
F_502 ( V_18 ) ;
V_1017:
F_503 ( V_36 ,
F_482 ( V_36 , V_1014 ) ) ;
V_1016:
V_1013:
F_357 ( V_36 ) ;
return V_348 ;
}
static void T_16 F_504 ( struct V_618 * V_36 )
{
struct V_1 * V_2 = F_342 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
F_202 ( V_3 , & V_2 -> V_4 ) ;
F_505 ( & V_2 -> V_6 ) ;
#ifdef F_186
if ( V_2 -> V_144 & V_145 ) {
V_2 -> V_144 &= ~ V_145 ;
F_98 ( & V_36 -> V_37 ) ;
F_45 ( & V_2 -> V_8 , V_146 , 1 ) ;
}
#endif
#ifdef F_119
if ( V_2 -> V_144 & V_165 )
F_506 ( V_2 ) ;
#endif
F_457 ( V_18 ) ;
if ( V_18 -> V_855 == V_856 )
F_393 ( V_18 ) ;
if ( V_2 -> V_144 & V_374 ) {
if ( ! ( F_507 ( V_2 ) ) )
F_500 ( V_2 ) ;
else
F_298 ( L_146
L_147 ) ;
}
F_356 ( V_2 ) ;
F_44 ( V_2 ) ;
#ifdef F_320
F_193 ( V_2 -> V_530 ) ;
F_193 ( V_2 -> V_529 ) ;
#endif
F_501 ( V_2 -> V_8 . V_364 ) ;
F_503 ( V_36 , F_482 ( V_36 ,
V_1014 ) ) ;
F_496 ( L_148 ) ;
F_502 ( V_18 ) ;
F_508 ( V_36 ) ;
F_357 ( V_36 ) ;
}
static T_17 F_509 ( struct V_618 * V_36 ,
T_18 V_4 )
{
struct V_1 * V_2 = F_342 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
#ifdef F_398
struct V_618 * V_1096 , * V_1097 ;
T_1 V_1098 , V_1099 , V_1100 , V_1101 ;
int V_857 , V_1102 ;
T_5 V_1103 , V_1104 ;
if ( V_2 -> V_8 . V_69 . type == V_70 ||
V_2 -> V_268 == 0 )
goto V_1105;
V_1096 = V_36 -> V_1069 -> V_1106 ;
while ( V_1096 && ( V_1096 -> V_1107 != V_1108 ) )
V_1096 = V_1096 -> V_1069 -> V_1106 ;
if ( ! V_1096 )
goto V_1105;
V_1102 = F_510 ( V_1096 , V_1109 ) ;
if ( ! V_1102 )
goto V_1105;
F_511 ( V_1096 , V_1102 + V_1110 , & V_1098 ) ;
F_511 ( V_1096 , V_1102 + V_1110 + 4 , & V_1099 ) ;
F_511 ( V_1096 , V_1102 + V_1110 + 8 , & V_1100 ) ;
F_511 ( V_1096 , V_1102 + V_1110 + 12 , & V_1101 ) ;
V_1103 = V_1099 >> 16 ;
if ( ! ( V_1103 & 0x0080 ) )
goto V_1105;
V_1104 = V_1103 & 0x01 ;
if ( ( V_1104 & 1 ) == ( V_36 -> V_1111 & 1 ) ) {
unsigned int V_301 ;
V_857 = ( V_1103 & 0x7F ) >> 1 ;
F_297 ( L_149 , V_857 ) ;
F_297 ( L_150
L_151 ,
V_1098 , V_1099 , V_1100 , V_1101 ) ;
switch ( V_2 -> V_8 . V_69 . type ) {
case V_72 :
V_301 = V_1112 ;
break;
case V_73 :
V_301 = V_1113 ;
break;
default:
V_301 = 0 ;
break;
}
V_1097 = F_512 ( V_1114 , V_301 , NULL ) ;
while ( V_1097 ) {
if ( V_1097 -> V_1111 == ( V_1103 & 0xFF ) )
break;
V_1097 = F_512 ( V_1114 ,
V_301 , V_1097 ) ;
}
if ( V_1097 ) {
F_297 ( L_152 , V_857 ) ;
F_513 ( V_1097 , 0xA8 , 0x00008000 ) ;
}
F_514 ( V_36 ) ;
}
V_2 -> V_1115 ++ ;
return V_1116 ;
V_1105:
#endif
F_355 ( V_18 ) ;
if ( V_4 == V_1117 )
return V_1118 ;
if ( F_31 ( V_18 ) )
F_293 ( V_2 ) ;
F_357 ( V_36 ) ;
return V_1119 ;
}
static T_17 F_515 ( struct V_618 * V_36 )
{
struct V_1 * V_2 = F_342 ( V_36 ) ;
T_17 V_1120 ;
int V_348 ;
if ( F_346 ( V_36 ) ) {
F_74 ( V_127 , L_153 ) ;
V_1120 = V_1118 ;
} else {
F_347 ( V_36 ) ;
F_344 ( V_36 ) ;
F_345 ( V_36 ) ;
F_348 ( V_36 , false ) ;
F_296 ( V_2 ) ;
F_45 ( & V_2 -> V_8 , V_681 , ~ 0 ) ;
V_1120 = V_1116 ;
}
V_348 = F_514 ( V_36 ) ;
if ( V_348 ) {
F_297 ( L_154
L_155 , V_348 ) ;
}
return V_1120 ;
}
static void F_516 ( struct V_618 * V_36 )
{
struct V_1 * V_2 = F_342 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
#ifdef F_398
if ( V_2 -> V_1115 ) {
F_76 ( V_125 , L_156 ) ;
V_2 -> V_1115 -- ;
return;
}
#endif
if ( F_31 ( V_18 ) )
F_295 ( V_2 ) ;
F_352 ( V_18 ) ;
}
static int T_19 F_517 ( void )
{
int V_108 ;
F_25 ( L_157 , V_1121 , V_1122 ) ;
F_25 ( L_145 , V_1123 ) ;
#ifdef F_186
F_518 ( & V_1124 ) ;
#endif
V_108 = F_519 ( & V_1125 ) ;
return V_108 ;
}
static void T_20 F_520 ( void )
{
#ifdef F_186
F_521 ( & V_1124 ) ;
#endif
F_522 ( & V_1125 ) ;
F_523 () ;
}
static int F_524 ( struct V_1126 * V_1127 , unsigned long V_151 ,
void * V_434 )
{
int V_1128 ;
V_1128 = F_525 ( & V_1125 . V_1129 , NULL , & V_151 ,
F_95 ) ;
return V_1128 ? V_1130 : V_1131 ;
}
