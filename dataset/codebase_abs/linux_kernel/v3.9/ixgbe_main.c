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
F_67 ( V_117 , L_47 ) ;
F_1 ( V_2 ) ;
}
}
static bool F_68 ( struct V_118 * V_119 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = V_119 -> V_2 ;
struct V_22 * V_23 ;
union V_24 * V_25 ;
unsigned int V_120 = 0 , V_121 = 0 ;
unsigned int V_122 = V_119 -> V_123 . V_124 ;
unsigned int V_11 = V_21 -> V_43 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return true ;
V_23 = & V_21 -> V_42 [ V_11 ] ;
V_25 = F_35 ( V_21 , V_11 ) ;
V_11 -= V_21 -> V_52 ;
do {
union V_24 * V_125 = V_23 -> V_47 ;
if ( ! V_125 )
break;
F_69 () ;
if ( ! ( V_125 -> V_58 . V_126 & F_70 ( V_127 ) ) )
break;
V_23 -> V_47 = NULL ;
V_120 += V_23 -> V_128 ;
V_121 += V_23 -> V_129 ;
F_52 ( V_23 -> V_53 ) ;
F_53 ( V_21 -> V_37 ,
F_32 ( V_23 , V_45 ) ,
F_33 ( V_23 , V_46 ) ,
V_83 ) ;
V_23 -> V_53 = NULL ;
F_55 ( V_23 , V_46 , 0 ) ;
while ( V_25 != V_125 ) {
V_23 ++ ;
V_25 ++ ;
V_11 ++ ;
if ( F_71 ( ! V_11 ) ) {
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
if ( F_71 ( ! V_11 ) ) {
V_11 -= V_21 -> V_52 ;
V_23 = V_21 -> V_42 ;
V_25 = F_35 ( V_21 , 0 ) ;
}
F_72 ( V_25 ) ;
V_122 -- ;
} while ( F_73 ( V_122 ) );
V_11 += V_21 -> V_52 ;
V_21 -> V_43 = V_11 ;
F_74 ( & V_21 -> V_130 ) ;
V_21 -> V_86 . V_131 += V_120 ;
V_21 -> V_86 . V_106 += V_121 ;
F_75 ( & V_21 -> V_130 ) ;
V_119 -> V_123 . V_120 += V_120 ;
V_119 -> V_123 . V_121 += V_121 ;
if ( F_76 ( V_21 ) && F_64 ( V_21 ) ) {
struct V_7 * V_8 = & V_2 -> V_8 ;
F_77 ( V_117 , L_48
L_49
L_50
L_51
L_52
L_53
L_54
L_55 ,
V_21 -> V_50 ,
F_11 ( V_8 , F_22 ( V_21 -> V_108 ) ) ,
F_11 ( V_8 , F_23 ( V_21 -> V_108 ) ) ,
V_21 -> V_44 , V_11 ,
V_21 -> V_42 [ V_11 ] . V_48 , V_132 ) ;
F_78 ( V_21 -> V_18 , V_21 -> V_50 ) ;
F_79 ( V_133 ,
L_56 ,
V_2 -> V_134 + 1 , V_21 -> V_50 ) ;
F_66 ( V_2 ) ;
return true ;
}
F_80 ( F_81 ( V_21 ) ,
V_121 , V_120 ) ;
#define F_82 (DESC_NEEDED * 2)
if ( F_71 ( V_121 && F_83 ( V_21 -> V_18 ) &&
( F_84 ( V_21 ) >= F_82 ) ) ) {
F_85 () ;
if ( F_86 ( V_21 -> V_18 ,
V_21 -> V_50 )
&& ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_87 ( V_21 -> V_18 ,
V_21 -> V_50 ) ;
++ V_21 -> V_112 . V_135 ;
}
}
return ! ! V_122 ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
int V_136 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_137 = F_89 ( V_21 -> V_37 , V_136 ) ;
T_5 V_138 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_138 = F_90 ( V_21 -> V_108 ) ;
break;
case V_75 :
case V_76 :
V_138 = F_91 ( V_21 -> V_108 ) ;
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
T_4 V_108 = V_30 -> V_108 ;
switch ( V_8 -> V_72 . type ) {
case V_75 :
case V_76 :
V_143 <<= V_144 ;
break;
default:
break;
}
V_143 |= V_145 |
V_146 ;
F_45 ( V_8 , F_12 ( V_108 ) , V_143 ) ;
}
static void F_93 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = V_119 -> V_2 ;
struct V_20 * V_82 ;
int V_136 = F_94 () ;
if ( V_119 -> V_136 == V_136 )
goto V_147;
F_95 (ring, q_vector->tx)
F_88 ( V_2 , V_82 , V_136 ) ;
F_95 (ring, q_vector->rx)
F_92 ( V_2 , V_82 , V_136 ) ;
V_119 -> V_136 = V_136 ;
V_147:
F_96 () ;
}
static void F_97 ( struct V_1 * V_2 )
{
int V_11 ;
if ( ! ( V_2 -> V_101 & V_148 ) )
return;
F_45 ( & V_2 -> V_8 , V_149 , 2 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_150 ; V_11 ++ ) {
V_2 -> V_119 [ V_11 ] -> V_136 = - 1 ;
F_93 ( V_2 -> V_119 [ V_11 ] ) ;
}
}
static int F_98 ( struct V_151 * V_37 , void * V_56 )
{
struct V_1 * V_2 = F_99 ( V_37 ) ;
unsigned long V_152 = * ( unsigned long * ) V_56 ;
if ( ! ( V_2 -> V_101 & V_153 ) )
return 0 ;
switch ( V_152 ) {
case V_154 :
if ( V_2 -> V_101 & V_148 )
break;
if ( F_100 ( V_37 ) == 0 ) {
V_2 -> V_101 |= V_148 ;
F_97 ( V_2 ) ;
break;
}
case V_155 :
if ( V_2 -> V_101 & V_148 ) {
F_101 ( V_37 ) ;
V_2 -> V_101 &= ~ V_148 ;
F_45 ( & V_2 -> V_8 , V_149 , 1 ) ;
}
break;
}
return 0 ;
}
static inline void F_102 ( struct V_20 * V_82 ,
union V_31 * V_32 ,
struct V_156 * V_53 )
{
if ( V_82 -> V_18 -> V_157 & V_158 )
V_53 -> V_159 = F_41 ( V_32 -> V_58 . V_160 . V_161 . V_162 ) ;
}
static inline bool F_103 ( struct V_20 * V_82 ,
union V_31 * V_32 )
{
T_6 V_163 = V_32 -> V_58 . V_160 . V_164 . V_165 . V_163 ;
return F_2 ( V_166 , & V_82 -> V_4 ) &&
( ( V_163 & F_104 ( V_167 ) ) ==
( F_104 ( V_168 <<
V_169 ) ) ) ;
}
static inline void F_105 ( struct V_20 * V_82 ,
union V_31 * V_32 ,
struct V_156 * V_53 )
{
F_106 ( V_53 ) ;
if ( ! ( V_82 -> V_18 -> V_157 & V_170 ) )
return;
if ( F_107 ( V_32 , V_171 ) &&
F_107 ( V_32 , V_172 ) ) {
V_82 -> V_173 . V_174 ++ ;
return;
}
if ( ! F_107 ( V_32 , V_175 ) )
return;
if ( F_107 ( V_32 , V_176 ) ) {
T_6 V_163 = V_32 -> V_58 . V_160 . V_164 . V_165 . V_163 ;
if ( ( V_163 & F_104 ( V_177 ) ) &&
F_2 ( V_178 , & V_82 -> V_4 ) )
return;
V_82 -> V_173 . V_174 ++ ;
return;
}
V_53 -> V_179 = V_180 ;
}
static inline void F_108 ( struct V_20 * V_30 , T_1 V_181 )
{
V_30 -> V_44 = V_181 ;
V_30 -> V_182 = V_181 ;
F_109 () ;
F_110 ( V_181 , V_30 -> V_109 ) ;
}
static bool F_111 ( struct V_20 * V_30 ,
struct V_33 * V_183 )
{
struct V_62 * V_62 = V_183 -> V_62 ;
T_7 V_45 = V_183 -> V_45 ;
if ( F_73 ( V_45 ) )
return true ;
if ( F_73 ( ! V_62 ) ) {
V_62 = F_112 ( V_184 | V_185 | V_186 ,
V_183 -> V_53 , F_113 ( V_30 ) ) ;
if ( F_71 ( ! V_62 ) ) {
V_30 -> V_173 . V_187 ++ ;
return false ;
}
V_183 -> V_62 = V_62 ;
}
V_45 = F_114 ( V_30 -> V_37 , V_62 , 0 ,
F_115 ( V_30 ) , V_188 ) ;
if ( F_116 ( V_30 -> V_37 , V_45 ) ) {
F_117 ( V_62 , F_113 ( V_30 ) ) ;
V_183 -> V_62 = NULL ;
V_30 -> V_173 . V_187 ++ ;
return false ;
}
V_183 -> V_45 = V_45 ;
V_183 -> V_63 = 0 ;
return true ;
}
void F_118 ( struct V_20 * V_30 , T_5 V_189 )
{
union V_31 * V_32 ;
struct V_33 * V_183 ;
T_5 V_11 = V_30 -> V_44 ;
if ( ! V_189 )
return;
V_32 = F_40 ( V_30 , V_11 ) ;
V_183 = & V_30 -> V_34 [ V_11 ] ;
V_11 -= V_30 -> V_52 ;
do {
if ( ! F_111 ( V_30 , V_183 ) )
break;
V_32 -> V_190 . V_191 = F_119 ( V_183 -> V_45 + V_183 -> V_63 ) ;
V_32 ++ ;
V_183 ++ ;
V_11 ++ ;
if ( F_71 ( ! V_11 ) ) {
V_32 = F_40 ( V_30 , 0 ) ;
V_183 = V_30 -> V_34 ;
V_11 -= V_30 -> V_52 ;
}
V_32 -> V_190 . V_192 = 0 ;
V_189 -- ;
} while ( V_189 );
V_11 += V_30 -> V_52 ;
if ( V_30 -> V_44 != V_11 )
F_108 ( V_30 , V_11 ) ;
}
static unsigned int F_120 ( unsigned char * V_56 ,
unsigned int V_193 )
{
union {
unsigned char * V_194 ;
struct V_195 * V_196 ;
struct V_197 * V_198 ;
struct V_199 * V_200 ;
struct V_201 * V_202 ;
} V_203 ;
T_8 V_204 ;
T_4 V_205 = 0 ;
T_4 V_206 ;
if ( V_193 < V_207 )
return V_193 ;
V_203 . V_194 = V_56 ;
V_204 = V_203 . V_196 -> V_208 ;
V_203 . V_194 += V_207 ;
if ( V_204 == F_121 ( V_209 ) ) {
if ( ( V_203 . V_194 - V_56 ) > ( V_193 - V_210 ) )
return V_193 ;
V_204 = V_203 . V_198 -> V_211 ;
V_203 . V_194 += V_210 ;
}
if ( V_204 == F_121 ( V_212 ) ) {
if ( ( V_203 . V_194 - V_56 ) > ( V_193 - sizeof( struct V_199 ) ) )
return V_193 ;
V_206 = ( V_203 . V_194 [ 0 ] & 0x0F ) << 2 ;
if ( V_206 < sizeof( struct V_199 ) )
return V_203 . V_194 - V_56 ;
if ( ! V_203 . V_200 -> V_213 )
V_205 = V_203 . V_200 -> V_204 ;
} else if ( V_204 == F_121 ( V_214 ) ) {
if ( ( V_203 . V_194 - V_56 ) > ( V_193 - sizeof( struct V_201 ) ) )
return V_193 ;
V_205 = V_203 . V_202 -> V_205 ;
V_206 = sizeof( struct V_201 ) ;
#ifdef F_122
} else if ( V_204 == F_121 ( V_215 ) ) {
if ( ( V_203 . V_194 - V_56 ) > ( V_193 - V_216 ) )
return V_193 ;
V_206 = V_216 ;
#endif
} else {
return V_203 . V_194 - V_56 ;
}
V_203 . V_194 += V_206 ;
if ( V_205 == V_217 ) {
if ( ( V_203 . V_194 - V_56 ) > ( V_193 - sizeof( struct V_218 ) ) )
return V_193 ;
V_206 = ( V_203 . V_194 [ 12 ] & 0xF0 ) >> 2 ;
if ( V_206 < sizeof( struct V_218 ) )
return V_203 . V_194 - V_56 ;
V_203 . V_194 += V_206 ;
} else if ( V_205 == V_219 ) {
if ( ( V_203 . V_194 - V_56 ) > ( V_193 - sizeof( struct V_220 ) ) )
return V_193 ;
V_203 . V_194 += sizeof( struct V_220 ) ;
}
if ( ( V_203 . V_194 - V_56 ) < V_193 )
return V_203 . V_194 - V_56 ;
else
return V_193 ;
}
static void F_123 ( struct V_20 * V_82 ,
struct V_156 * V_53 )
{
T_5 V_221 = F_124 ( V_53 ) ;
F_125 ( V_53 ) -> V_222 = F_126 ( ( V_53 -> V_46 - V_221 ) ,
F_127 ( V_53 ) -> V_223 ) ;
F_125 ( V_53 ) -> V_224 = V_225 ;
}
static void F_128 ( struct V_20 * V_30 ,
struct V_156 * V_53 )
{
if ( ! F_127 ( V_53 ) -> V_223 )
return;
V_30 -> V_173 . V_226 += F_127 ( V_53 ) -> V_223 ;
V_30 -> V_173 . V_227 ++ ;
F_123 ( V_30 , V_53 ) ;
F_127 ( V_53 ) -> V_223 = 0 ;
}
static void F_129 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_156 * V_53 )
{
struct V_17 * V_37 = V_30 -> V_18 ;
F_128 ( V_30 , V_53 ) ;
F_102 ( V_30 , V_32 , V_53 ) ;
F_105 ( V_30 , V_32 , V_53 ) ;
F_130 ( V_30 , V_32 , V_53 ) ;
if ( ( V_37 -> V_157 & V_228 ) &&
F_107 ( V_32 , V_229 ) ) {
T_5 V_230 = F_131 ( V_32 -> V_58 . V_59 . V_198 ) ;
F_132 ( V_53 , V_230 ) ;
}
F_133 ( V_53 , V_30 -> V_50 ) ;
V_53 -> V_204 = F_134 ( V_53 , V_37 ) ;
}
static void F_135 ( struct V_118 * V_119 ,
struct V_156 * V_53 )
{
struct V_1 * V_2 = V_119 -> V_2 ;
if ( ! ( V_2 -> V_101 & V_231 ) )
F_136 ( & V_119 -> V_232 , V_53 ) ;
else
F_137 ( V_53 ) ;
}
static bool F_138 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_156 * V_53 )
{
T_1 V_233 = V_30 -> V_43 + 1 ;
V_233 = ( V_233 < V_30 -> V_52 ) ? V_233 : 0 ;
V_30 -> V_43 = V_233 ;
F_72 ( F_40 ( V_30 , V_233 ) ) ;
if ( F_139 ( V_30 ) ) {
T_9 V_234 = V_32 -> V_58 . V_160 . V_164 . V_56 &
F_70 ( V_235 ) ;
if ( F_71 ( V_234 ) ) {
T_1 V_236 = F_41 ( V_234 ) ;
V_236 >>= V_237 ;
F_127 ( V_53 ) -> V_223 += V_236 - 1 ;
V_233 = F_41 ( V_32 -> V_58 . V_59 . V_60 ) ;
V_233 &= V_238 ;
V_233 >>= V_239 ;
}
}
if ( F_73 ( F_107 ( V_32 , V_240 ) ) )
return false ;
V_30 -> V_34 [ V_233 ] . V_53 = V_53 ;
V_30 -> V_173 . V_241 ++ ;
return true ;
}
static void F_140 ( struct V_20 * V_30 ,
struct V_156 * V_53 )
{
struct V_242 * V_243 = & F_125 ( V_53 ) -> V_244 [ 0 ] ;
unsigned char * V_245 ;
unsigned int V_246 ;
V_245 = F_141 ( V_243 ) ;
V_246 = F_120 ( V_245 , V_247 ) ;
F_142 ( V_53 , V_245 , F_143 ( V_246 , sizeof( long ) ) ) ;
F_144 ( V_243 , V_246 ) ;
V_243 -> V_63 += V_246 ;
V_53 -> V_248 -= V_246 ;
V_53 -> V_109 += V_246 ;
}
static void F_145 ( struct V_20 * V_30 ,
struct V_156 * V_53 )
{
if ( F_71 ( F_127 ( V_53 ) -> V_249 ) ) {
F_54 ( V_30 -> V_37 , F_127 ( V_53 ) -> V_45 ,
F_115 ( V_30 ) , V_188 ) ;
F_127 ( V_53 ) -> V_249 = false ;
} else {
struct V_242 * V_243 = & F_125 ( V_53 ) -> V_244 [ 0 ] ;
F_146 ( V_30 -> V_37 ,
F_127 ( V_53 ) -> V_45 ,
V_243 -> V_63 ,
F_43 ( V_30 ) ,
V_188 ) ;
}
F_127 ( V_53 ) -> V_45 = 0 ;
}
static bool F_147 ( struct V_20 * V_30 ,
union V_31 * V_32 ,
struct V_156 * V_53 )
{
struct V_17 * V_18 = V_30 -> V_18 ;
if ( F_71 ( F_107 ( V_32 ,
V_250 ) &&
! ( V_18 -> V_157 & V_251 ) ) ) {
F_52 ( V_53 ) ;
return true ;
}
if ( F_148 ( V_53 ) )
F_140 ( V_30 , V_53 ) ;
#ifdef F_122
if ( F_103 ( V_30 , V_32 ) )
return false ;
#endif
if ( F_71 ( V_53 -> V_46 < 60 ) ) {
int V_252 = 60 - V_53 -> V_46 ;
if ( F_149 ( V_53 , V_252 ) )
return true ;
F_150 ( V_53 , V_252 ) ;
}
return false ;
}
static void F_151 ( struct V_20 * V_30 ,
struct V_33 * V_253 )
{
struct V_33 * V_254 ;
T_5 V_255 = V_30 -> V_182 ;
V_254 = & V_30 -> V_34 [ V_255 ] ;
V_255 ++ ;
V_30 -> V_182 = ( V_255 < V_30 -> V_52 ) ? V_255 : 0 ;
V_254 -> V_62 = V_253 -> V_62 ;
V_254 -> V_45 = V_253 -> V_45 ;
V_254 -> V_63 = V_253 -> V_63 ;
F_152 ( V_30 -> V_37 , V_254 -> V_45 ,
V_254 -> V_63 ,
F_43 ( V_30 ) ,
V_188 ) ;
}
static bool F_153 ( struct V_20 * V_30 ,
struct V_33 * V_256 ,
union V_31 * V_32 ,
struct V_156 * V_53 )
{
struct V_62 * V_62 = V_256 -> V_62 ;
unsigned int V_257 = F_131 ( V_32 -> V_58 . V_59 . V_258 ) ;
#if ( V_259 < 8192 )
unsigned int V_260 = F_43 ( V_30 ) ;
#else
unsigned int V_260 = F_143 ( V_257 , V_261 ) ;
unsigned int V_262 = F_115 ( V_30 ) -
F_43 ( V_30 ) ;
#endif
if ( ( V_257 <= V_247 ) && ! F_148 ( V_53 ) ) {
unsigned char * V_245 = F_42 ( V_62 ) + V_256 -> V_63 ;
memcpy ( F_150 ( V_53 , V_257 ) , V_245 , F_143 ( V_257 , sizeof( long ) ) ) ;
if ( F_73 ( F_154 ( V_62 ) == F_155 () ) )
return true ;
F_156 ( V_62 ) ;
return false ;
}
F_157 ( V_53 , F_125 ( V_53 ) -> V_263 , V_62 ,
V_256 -> V_63 , V_257 , V_260 ) ;
if ( F_71 ( F_154 ( V_62 ) != F_155 () ) )
return false ;
#if ( V_259 < 8192 )
if ( F_71 ( F_158 ( V_62 ) != 1 ) )
return false ;
V_256 -> V_63 ^= V_260 ;
F_159 ( & V_62 -> V_264 , 2 ) ;
#else
V_256 -> V_63 += V_260 ;
if ( V_256 -> V_63 > V_262 )
return false ;
F_160 ( V_62 ) ;
#endif
return true ;
}
static struct V_156 * F_161 ( struct V_20 * V_30 ,
union V_31 * V_32 )
{
struct V_33 * V_256 ;
struct V_156 * V_53 ;
struct V_62 * V_62 ;
V_256 = & V_30 -> V_34 [ V_30 -> V_43 ] ;
V_62 = V_256 -> V_62 ;
F_162 ( V_62 ) ;
V_53 = V_256 -> V_53 ;
if ( F_73 ( ! V_53 ) ) {
void * V_265 = F_42 ( V_62 ) +
V_256 -> V_63 ;
F_72 ( V_265 ) ;
#if V_261 < 128
F_72 ( V_265 + V_261 ) ;
#endif
V_53 = F_163 ( V_30 -> V_18 ,
V_247 ) ;
if ( F_71 ( ! V_53 ) ) {
V_30 -> V_173 . V_266 ++ ;
return NULL ;
}
F_162 ( V_53 -> V_56 ) ;
if ( F_73 ( F_107 ( V_32 , V_240 ) ) )
goto V_267;
F_127 ( V_53 ) -> V_45 = V_256 -> V_45 ;
} else {
if ( F_107 ( V_32 , V_240 ) )
F_145 ( V_30 , V_53 ) ;
V_267:
F_146 ( V_30 -> V_37 ,
V_256 -> V_45 ,
V_256 -> V_63 ,
F_43 ( V_30 ) ,
V_188 ) ;
}
if ( F_153 ( V_30 , V_256 , V_32 , V_53 ) ) {
F_151 ( V_30 , V_256 ) ;
} else if ( F_127 ( V_53 ) -> V_45 == V_256 -> V_45 ) {
F_127 ( V_53 ) -> V_249 = true ;
} else {
F_54 ( V_30 -> V_37 , V_256 -> V_45 ,
F_115 ( V_30 ) ,
V_188 ) ;
}
V_256 -> V_53 = NULL ;
V_256 -> V_45 = 0 ;
V_256 -> V_62 = NULL ;
return V_53 ;
}
static bool F_164 ( struct V_118 * V_119 ,
struct V_20 * V_30 ,
const int V_122 )
{
unsigned int V_268 = 0 , V_269 = 0 ;
#ifdef F_122
struct V_1 * V_2 = V_119 -> V_2 ;
int V_270 ;
unsigned int V_271 = 0 ;
#endif
T_5 V_189 = F_84 ( V_30 ) ;
do {
union V_31 * V_32 ;
struct V_156 * V_53 ;
if ( V_189 >= V_272 ) {
F_118 ( V_30 , V_189 ) ;
V_189 = 0 ;
}
V_32 = F_40 ( V_30 , V_30 -> V_43 ) ;
if ( ! F_107 ( V_32 , V_61 ) )
break;
F_165 () ;
V_53 = F_161 ( V_30 , V_32 ) ;
if ( ! V_53 )
break;
V_189 ++ ;
if ( F_138 ( V_30 , V_32 , V_53 ) )
continue;
if ( F_147 ( V_30 , V_32 , V_53 ) )
continue;
V_268 += V_53 -> V_46 ;
F_129 ( V_30 , V_32 , V_53 ) ;
#ifdef F_122
if ( F_103 ( V_30 , V_32 ) ) {
V_270 = F_166 ( V_2 , V_32 , V_53 ) ;
if ( V_270 > 0 ) {
if ( ! V_271 ) {
V_271 = V_30 -> V_18 -> V_273 -
sizeof( struct V_274 ) -
sizeof( struct V_275 ) -
sizeof( struct V_276 ) ;
if ( V_271 > 512 )
V_271 &= ~ 511 ;
}
V_268 += V_270 ;
V_269 += F_126 ( V_270 ,
V_271 ) ;
}
if ( ! V_270 ) {
F_52 ( V_53 ) ;
continue;
}
}
#endif
F_135 ( V_119 , V_53 ) ;
V_269 ++ ;
} while ( F_73 ( V_269 < V_122 ) );
F_74 ( & V_30 -> V_130 ) ;
V_30 -> V_86 . V_106 += V_269 ;
V_30 -> V_86 . V_131 += V_268 ;
F_75 ( & V_30 -> V_130 ) ;
V_119 -> V_277 . V_121 += V_269 ;
V_119 -> V_277 . V_120 += V_268 ;
if ( V_189 )
F_118 ( V_30 , V_189 ) ;
return ( V_269 < V_122 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_118 * V_119 ;
int V_278 ;
T_1 V_79 ;
if ( V_2 -> V_279 > 32 ) {
T_1 V_280 = ( 1 << ( V_2 -> V_279 - 32 ) ) - 1 ;
F_45 ( & V_2 -> V_8 , V_281 , V_280 ) ;
}
for ( V_278 = 0 ; V_278 < V_2 -> V_150 ; V_278 ++ ) {
struct V_20 * V_82 ;
V_119 = V_2 -> V_119 [ V_278 ] ;
F_95 (ring, q_vector->rx)
F_47 ( V_2 , 0 , V_82 -> V_108 , V_278 ) ;
F_95 (ring, q_vector->tx)
F_47 ( V_2 , 1 , V_82 -> V_108 , V_278 ) ;
F_168 ( V_119 ) ;
}
switch ( V_2 -> V_8 . V_72 . type ) {
case V_73 :
F_47 ( V_2 , - 1 , V_282 ,
V_278 ) ;
break;
case V_75 :
case V_76 :
F_47 ( V_2 , - 1 , 1 , V_278 ) ;
break;
default:
break;
}
F_45 ( & V_2 -> V_8 , F_169 ( V_278 ) , 1950 ) ;
V_79 = V_283 ;
V_79 &= ~ ( V_284 |
V_285 |
V_286 ) ;
F_45 ( & V_2 -> V_8 , V_287 , V_79 ) ;
}
static void F_170 ( struct V_118 * V_119 ,
struct V_288 * V_289 )
{
int V_131 = V_289 -> V_120 ;
int V_106 = V_289 -> V_121 ;
T_1 V_290 ;
T_2 V_291 ;
T_4 V_292 = V_289 -> V_293 ;
if ( V_106 == 0 )
return;
V_290 = V_119 -> V_293 >> 2 ;
V_291 = V_131 / V_290 ;
switch ( V_292 ) {
case V_294 :
if ( V_291 > 10 )
V_292 = V_295 ;
break;
case V_295 :
if ( V_291 > 20 )
V_292 = V_296 ;
else if ( V_291 <= 10 )
V_292 = V_294 ;
break;
case V_296 :
if ( V_291 <= 20 )
V_292 = V_295 ;
break;
}
V_289 -> V_120 = 0 ;
V_289 -> V_121 = 0 ;
V_289 -> V_293 = V_292 ;
}
void F_168 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = V_119 -> V_2 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_278 = V_119 -> V_278 ;
T_1 V_297 = V_119 -> V_293 & V_298 ;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_73 :
V_297 |= ( V_297 << 16 ) ;
break;
case V_75 :
case V_76 :
V_297 |= V_299 ;
break;
default:
break;
}
F_45 ( V_8 , F_169 ( V_278 ) , V_297 ) ;
}
static void F_171 ( struct V_118 * V_119 )
{
T_1 V_300 = V_119 -> V_293 ;
T_4 V_301 ;
F_170 ( V_119 , & V_119 -> V_123 ) ;
F_170 ( V_119 , & V_119 -> V_277 ) ;
V_301 = F_172 ( V_119 -> V_277 . V_293 , V_119 -> V_123 . V_293 ) ;
switch ( V_301 ) {
case V_294 :
V_300 = V_302 ;
break;
case V_295 :
V_300 = V_303 ;
break;
case V_296 :
V_300 = V_304 ;
break;
default:
break;
}
if ( V_300 != V_119 -> V_293 ) {
V_300 = ( 10 * V_300 * V_119 -> V_293 ) /
( ( 9 * V_300 ) + V_119 -> V_293 ) ;
V_119 -> V_293 = V_300 ;
F_168 ( V_119 ) ;
}
}
static void F_173 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_305 = V_2 -> V_306 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
if ( ! ( V_2 -> V_115 & V_307 ) &&
! ( V_2 -> V_115 & V_308 ) )
return;
V_2 -> V_115 &= ~ V_308 ;
switch ( V_8 -> V_309 ) {
case V_310 :
if ( ! ( V_305 & V_311 ) &&
! ( V_305 & V_312 ) )
return;
if ( ! ( V_305 & V_312 ) && V_8 -> V_72 . V_313 . V_314 ) {
T_1 V_315 ;
bool V_316 = false ;
V_8 -> V_72 . V_313 . V_314 ( V_8 , & V_315 , & V_316 , false ) ;
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
F_174 ( V_117 ,
L_57
L_58
L_59 ) ;
V_2 -> V_306 = 0 ;
}
static void F_175 ( struct V_1 * V_2 , T_1 V_305 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( ( V_2 -> V_101 & V_320 ) &&
( V_305 & V_321 ) ) {
F_174 ( V_133 , L_60 ) ;
F_45 ( V_8 , V_322 , V_321 ) ;
}
}
static void F_176 ( struct V_1 * V_2 , T_1 V_305 )
{
if ( ! ( V_2 -> V_115 & V_307 ) )
return;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
if ( ( ( V_305 & V_311 ) || ( V_305 & V_312 ) ) &&
( ! F_2 ( V_3 , & V_2 -> V_4 ) ) ) {
V_2 -> V_306 = V_305 ;
V_2 -> V_115 |= V_308 ;
F_1 ( V_2 ) ;
return;
}
return;
case V_76 :
if ( ! ( V_305 & V_323 ) )
return;
break;
default:
return;
}
F_174 ( V_117 ,
L_57
L_58
L_59 ) ;
}
static void F_177 ( struct V_1 * V_2 , T_1 V_305 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( V_305 & V_324 ) {
F_45 ( V_8 , V_322 , V_324 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_115 |= V_325 ;
F_1 ( V_2 ) ;
}
}
if ( V_305 & V_321 ) {
F_45 ( V_8 , V_322 , V_321 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_101 |= V_326 ;
F_1 ( V_2 ) ;
}
}
}
static void F_178 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
V_2 -> V_327 ++ ;
V_2 -> V_101 |= V_328 ;
V_2 -> V_329 = V_132 ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_45 ( V_8 , V_330 , V_331 ) ;
F_179 ( V_8 ) ;
F_1 ( V_2 ) ;
}
}
static inline void F_180 ( struct V_1 * V_2 ,
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
F_45 ( V_8 , F_181 ( 0 ) , V_79 ) ;
V_79 = ( V_78 >> 32 ) ;
if ( V_79 )
F_45 ( V_8 , F_181 ( 1 ) , V_79 ) ;
break;
default:
break;
}
}
static inline void F_182 ( struct V_1 * V_2 ,
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
F_45 ( V_8 , F_183 ( 0 ) , V_79 ) ;
V_79 = ( V_78 >> 32 ) ;
if ( V_79 )
F_45 ( V_8 , F_183 ( 1 ) , V_79 ) ;
break;
default:
break;
}
}
static inline void F_184 ( struct V_1 * V_2 , bool V_333 ,
bool V_334 )
{
T_1 V_79 = ( V_283 & ~ V_80 ) ;
if ( V_2 -> V_101 & V_328 )
V_79 &= ~ V_286 ;
if ( V_2 -> V_115 & V_307 )
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
V_79 |= V_335 ;
break;
case V_76 :
V_79 |= V_336 ;
break;
default:
break;
}
if ( V_2 -> V_101 & V_320 )
V_79 |= V_337 ;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
V_79 |= V_337 ;
V_79 |= V_338 ;
case V_76 :
V_79 |= V_339 ;
V_79 |= V_285 ;
break;
default:
break;
}
if ( V_2 -> V_8 . V_72 . type == V_76 )
V_79 |= V_340 ;
if ( ( V_2 -> V_101 & V_341 ) &&
! ( V_2 -> V_115 & V_342 ) )
V_79 |= V_343 ;
F_45 ( & V_2 -> V_8 , V_332 , V_79 ) ;
if ( V_333 )
F_180 ( V_2 , ~ 0 ) ;
if ( V_334 )
F_179 ( & V_2 -> V_8 ) ;
}
static T_10 F_185 ( int V_344 , void * V_56 )
{
struct V_1 * V_2 = V_56 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_305 ;
V_305 = F_11 ( V_8 , V_81 ) ;
F_45 ( V_8 , V_322 , V_305 ) ;
if ( V_305 & V_312 )
F_178 ( V_2 ) ;
if ( V_305 & V_345 )
F_186 ( V_2 ) ;
switch ( V_8 -> V_72 . type ) {
case V_75 :
case V_76 :
if ( V_305 & V_346 )
F_79 ( V_347 , L_61
L_62 ) ;
if ( V_305 & V_348 ) {
int V_349 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_82 = V_2 -> V_21 [ V_11 ] ;
if ( F_187 ( V_350 ,
& V_82 -> V_4 ) )
V_349 ++ ;
}
if ( V_349 ) {
F_45 ( V_8 , V_330 , V_351 ) ;
V_2 -> V_115 |= V_342 ;
F_1 ( V_2 ) ;
}
}
F_177 ( V_2 , V_305 ) ;
F_176 ( V_2 , V_305 ) ;
break;
default:
break;
}
F_175 ( V_2 , V_305 ) ;
if ( F_71 ( V_305 & V_352 ) )
F_188 ( V_2 , V_305 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_184 ( V_2 , false , false ) ;
return V_353 ;
}
static T_10 F_189 ( int V_344 , void * V_56 )
{
struct V_118 * V_119 = V_56 ;
if ( V_119 -> V_277 . V_82 || V_119 -> V_123 . V_82 )
F_190 ( & V_119 -> V_232 ) ;
return V_353 ;
}
int F_191 ( struct V_354 * V_232 , int V_122 )
{
struct V_118 * V_119 =
F_192 ( V_232 , struct V_118 , V_232 ) ;
struct V_1 * V_2 = V_119 -> V_2 ;
struct V_20 * V_82 ;
int V_355 ;
bool V_356 = true ;
#ifdef F_193
if ( V_2 -> V_101 & V_148 )
F_93 ( V_119 ) ;
#endif
F_95 (ring, q_vector->tx)
V_356 &= ! ! F_68 ( V_119 , V_82 ) ;
if ( V_119 -> V_277 . V_52 > 1 )
V_355 = F_172 ( V_122 / V_119 -> V_277 . V_52 , 1 ) ;
else
V_355 = V_122 ;
F_95 (ring, q_vector->rx)
V_356 &= F_164 ( V_119 , V_82 ,
V_355 ) ;
if ( ! V_356 )
return V_122 ;
F_194 ( V_232 ) ;
if ( V_2 -> V_357 & 1 )
F_171 ( V_119 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_180 ( V_2 , ( ( T_2 ) 1 << V_119 -> V_278 ) ) ;
return 0 ;
}
static int F_195 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
int V_358 , V_359 ;
int V_360 = 0 , V_361 = 0 ;
for ( V_358 = 0 ; V_358 < V_2 -> V_150 ; V_358 ++ ) {
struct V_118 * V_119 = V_2 -> V_119 [ V_358 ] ;
struct V_362 * V_363 = & V_2 -> V_364 [ V_358 ] ;
if ( V_119 -> V_123 . V_82 && V_119 -> V_277 . V_82 ) {
snprintf ( V_119 -> V_16 , sizeof( V_119 -> V_16 ) - 1 ,
L_63 , V_18 -> V_16 , L_64 , V_360 ++ ) ;
V_361 ++ ;
} else if ( V_119 -> V_277 . V_82 ) {
snprintf ( V_119 -> V_16 , sizeof( V_119 -> V_16 ) - 1 ,
L_63 , V_18 -> V_16 , L_65 , V_360 ++ ) ;
} else if ( V_119 -> V_123 . V_82 ) {
snprintf ( V_119 -> V_16 , sizeof( V_119 -> V_16 ) - 1 ,
L_63 , V_18 -> V_16 , L_66 , V_361 ++ ) ;
} else {
continue;
}
V_359 = F_196 ( V_363 -> V_358 , & F_189 , 0 ,
V_119 -> V_16 , V_119 ) ;
if ( V_359 ) {
F_77 ( V_133 , L_67
L_68 , V_359 ) ;
goto V_365;
}
if ( V_2 -> V_101 & V_341 ) {
F_197 ( V_363 -> V_358 ,
& V_119 -> V_366 ) ;
}
}
V_359 = F_196 ( V_2 -> V_364 [ V_358 ] . V_358 ,
F_185 , 0 , V_18 -> V_16 , V_2 ) ;
if ( V_359 ) {
F_77 ( V_133 , L_69 , V_359 ) ;
goto V_365;
}
return 0 ;
V_365:
while ( V_358 ) {
V_358 -- ;
F_197 ( V_2 -> V_364 [ V_358 ] . V_358 ,
NULL ) ;
F_198 ( V_2 -> V_364 [ V_358 ] . V_358 ,
V_2 -> V_119 [ V_358 ] ) ;
}
V_2 -> V_101 &= ~ V_367 ;
F_199 ( V_2 -> V_36 ) ;
F_200 ( V_2 -> V_364 ) ;
V_2 -> V_364 = NULL ;
return V_359 ;
}
static T_10 F_201 ( int V_344 , void * V_56 )
{
struct V_1 * V_2 = V_56 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_118 * V_119 = V_2 -> V_119 [ 0 ] ;
T_1 V_305 ;
F_45 ( V_8 , V_330 , V_368 ) ;
V_305 = F_11 ( V_8 , V_322 ) ;
if ( ! V_305 ) {
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_184 ( V_2 , true , true ) ;
return V_369 ;
}
if ( V_305 & V_312 )
F_178 ( V_2 ) ;
switch ( V_8 -> V_72 . type ) {
case V_75 :
F_177 ( V_2 , V_305 ) ;
case V_76 :
if ( V_305 & V_346 )
F_79 ( V_347 , L_70
L_62 ) ;
F_176 ( V_2 , V_305 ) ;
break;
default:
break;
}
F_175 ( V_2 , V_305 ) ;
if ( F_71 ( V_305 & V_352 ) )
F_188 ( V_2 , V_305 ) ;
F_190 ( & V_119 -> V_232 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
F_184 ( V_2 , false , false ) ;
return V_353 ;
}
static int F_202 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
int V_359 ;
if ( V_2 -> V_101 & V_367 )
V_359 = F_195 ( V_2 ) ;
else if ( V_2 -> V_101 & V_370 )
V_359 = F_196 ( V_2 -> V_36 -> V_344 , F_201 , 0 ,
V_18 -> V_16 , V_2 ) ;
else
V_359 = F_196 ( V_2 -> V_36 -> V_344 , F_201 , V_371 ,
V_18 -> V_16 , V_2 ) ;
if ( V_359 )
F_77 ( V_133 , L_71 , V_359 ) ;
return V_359 ;
}
static void F_203 ( struct V_1 * V_2 )
{
int V_358 ;
if ( ! ( V_2 -> V_101 & V_367 ) ) {
F_198 ( V_2 -> V_36 -> V_344 , V_2 ) ;
return;
}
for ( V_358 = 0 ; V_358 < V_2 -> V_150 ; V_358 ++ ) {
struct V_118 * V_119 = V_2 -> V_119 [ V_358 ] ;
struct V_362 * V_363 = & V_2 -> V_364 [ V_358 ] ;
if ( ! V_119 -> V_277 . V_82 && ! V_119 -> V_123 . V_82 )
continue;
F_197 ( V_363 -> V_358 , NULL ) ;
F_198 ( V_363 -> V_358 , V_119 ) ;
}
F_198 ( V_2 -> V_364 [ V_358 ++ ] . V_358 , V_2 ) ;
}
static inline void F_204 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 . V_72 . type ) {
case V_73 :
F_45 ( & V_2 -> V_8 , V_330 , ~ 0 ) ;
break;
case V_75 :
case V_76 :
F_45 ( & V_2 -> V_8 , V_330 , 0xFFFF0000 ) ;
F_45 ( & V_2 -> V_8 , F_183 ( 0 ) , ~ 0 ) ;
F_45 ( & V_2 -> V_8 , F_183 ( 1 ) , ~ 0 ) ;
break;
default:
break;
}
F_179 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_101 & V_367 ) {
int V_358 ;
for ( V_358 = 0 ; V_358 < V_2 -> V_150 ; V_358 ++ )
F_205 ( V_2 -> V_364 [ V_358 ] . V_358 ) ;
F_205 ( V_2 -> V_364 [ V_358 ++ ] . V_358 ) ;
} else {
F_205 ( V_2 -> V_36 -> V_344 ) ;
}
}
static void F_206 ( struct V_1 * V_2 )
{
struct V_118 * V_119 = V_2 -> V_119 [ 0 ] ;
F_168 ( V_119 ) ;
F_47 ( V_2 , 0 , 0 , 0 ) ;
F_47 ( V_2 , 1 , 0 , 0 ) ;
F_79 ( V_8 , L_72 ) ;
}
void F_207 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_372 = V_82 -> V_45 ;
int V_373 = 10 ;
T_1 V_374 = V_375 ;
T_4 V_108 = V_82 -> V_108 ;
F_45 ( V_8 , F_24 ( V_108 ) , 0 ) ;
F_179 ( V_8 ) ;
F_45 ( V_8 , F_19 ( V_108 ) ,
( V_372 & F_208 ( 32 ) ) ) ;
F_45 ( V_8 , F_20 ( V_108 ) , ( V_372 >> 32 ) ) ;
F_45 ( V_8 , F_21 ( V_108 ) ,
V_82 -> V_52 * sizeof( union V_24 ) ) ;
F_45 ( V_8 , F_22 ( V_108 ) , 0 ) ;
F_45 ( V_8 , F_23 ( V_108 ) , 0 ) ;
V_82 -> V_109 = V_8 -> V_376 + F_23 ( V_108 ) ;
#if F_209 ( V_377 )
if ( ! V_82 -> V_119 || ( V_82 -> V_119 -> V_293 < V_302 ) )
#else
if ( ! V_82 -> V_119 || ( V_82 -> V_119 -> V_293 < 8 ) )
#endif
V_374 |= ( 1 << 16 ) ;
else
V_374 |= ( 8 << 16 ) ;
V_374 |= ( 1 << 8 ) |
32 ;
if ( V_2 -> V_101 & V_341 ) {
V_82 -> V_378 = V_2 -> V_378 ;
V_82 -> V_379 = 0 ;
F_210 ( V_350 , & V_82 -> V_4 ) ;
} else {
V_82 -> V_378 = 0 ;
}
if ( ! F_3 ( V_380 , & V_82 -> V_4 ) ) {
struct V_118 * V_119 = V_82 -> V_119 ;
if ( V_119 )
F_211 ( V_2 -> V_18 ,
& V_119 -> V_366 ,
V_82 -> V_50 ) ;
}
F_8 ( V_94 , & V_82 -> V_4 ) ;
F_45 ( V_8 , F_24 ( V_108 ) , V_374 ) ;
if ( V_8 -> V_72 . type == V_73 &&
! ( F_11 ( V_8 , V_381 ) & V_382 ) )
return;
do {
F_212 ( 1000 , 2000 ) ;
V_374 = F_11 ( V_8 , F_24 ( V_108 ) ) ;
} while ( -- V_373 && ! ( V_374 & V_375 ) );
if ( ! V_373 )
F_77 ( V_117 , L_73 , V_108 ) ;
}
static void F_213 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_383 , V_384 ;
T_4 V_385 = F_214 ( V_2 -> V_18 ) ;
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
static void F_215 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_403 ;
T_1 V_11 ;
F_213 ( V_2 ) ;
if ( V_8 -> V_72 . type != V_73 ) {
V_403 = F_11 ( V_8 , V_404 ) ;
V_403 |= V_405 ;
F_45 ( V_8 , V_404 , V_403 ) ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_207 ( V_2 , V_2 -> V_21 [ V_11 ] ) ;
}
static void F_216 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_4 V_108 = V_82 -> V_108 ;
T_1 V_406 = F_11 ( V_8 , F_10 ( V_108 ) ) ;
V_406 |= V_407 ;
F_45 ( V_8 , F_10 ( V_108 ) , V_406 ) ;
}
static void F_217 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_4 V_108 = V_82 -> V_108 ;
T_1 V_406 = F_11 ( V_8 , F_10 ( V_108 ) ) ;
V_406 &= ~ V_407 ;
F_45 ( V_8 , F_10 ( V_108 ) , V_406 ) ;
}
static void F_218 ( struct V_1 * V_2 ,
struct V_20 * V_30 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_406 ;
T_4 V_108 = V_30 -> V_108 ;
if ( V_8 -> V_72 . type == V_73 ) {
T_5 V_79 = V_2 -> V_393 [ V_394 ] . V_79 ;
V_108 &= V_79 ;
}
V_406 = V_247 << V_408 ;
V_406 |= F_43 ( V_30 ) >> V_409 ;
V_406 |= V_410 ;
F_45 ( V_8 , F_10 ( V_108 ) , V_406 ) ;
}
static void F_219 ( struct V_1 * V_2 )
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
F_45 ( V_8 , F_220 ( V_11 ) , V_411 [ V_11 ] ) ;
for ( V_11 = 0 , V_12 = 0 ; V_11 < 128 ; V_11 ++ , V_12 ++ ) {
if ( V_12 == V_415 )
V_12 = 0 ;
V_413 = ( V_413 << 8 ) | ( V_12 * 0x11 ) ;
if ( ( V_11 & 3 ) == 3 )
F_45 ( V_8 , F_221 ( V_11 >> 2 ) , V_413 ) ;
}
V_414 = F_11 ( V_8 , V_416 ) ;
V_414 |= V_417 ;
F_45 ( V_8 , V_416 , V_414 ) ;
if ( V_2 -> V_8 . V_72 . type == V_73 ) {
if ( V_2 -> V_393 [ V_394 ] . V_79 )
V_412 = V_418 ;
} else {
T_4 V_385 = F_214 ( V_2 -> V_18 ) ;
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
static void F_222 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_434 ;
T_4 V_108 = V_82 -> V_108 ;
if ( ! F_139 ( V_82 ) )
return;
V_434 = F_11 ( V_8 , F_223 ( V_108 ) ) ;
V_434 |= V_435 ;
V_434 |= V_436 ;
F_45 ( V_8 , F_223 ( V_108 ) , V_434 ) ;
}
static void F_224 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_373 = V_437 ;
T_1 V_438 ;
T_4 V_108 = V_82 -> V_108 ;
if ( V_8 -> V_72 . type == V_73 &&
! ( F_11 ( V_8 , V_381 ) & V_382 ) )
return;
do {
F_212 ( 1000 , 2000 ) ;
V_438 = F_11 ( V_8 , F_16 ( V_108 ) ) ;
} while ( -- V_373 && ! ( V_438 & V_439 ) );
if ( ! V_373 ) {
F_77 ( V_117 , L_74
L_75 , V_108 ) ;
}
}
void F_225 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_373 = V_437 ;
T_1 V_438 ;
T_4 V_108 = V_82 -> V_108 ;
V_438 = F_11 ( V_8 , F_16 ( V_108 ) ) ;
V_438 &= ~ V_439 ;
F_45 ( V_8 , F_16 ( V_108 ) , V_438 ) ;
if ( V_8 -> V_72 . type == V_73 &&
! ( F_11 ( V_8 , V_381 ) & V_382 ) )
return;
do {
F_226 ( 10 ) ;
V_438 = F_11 ( V_8 , F_16 ( V_108 ) ) ;
} while ( -- V_373 && ( V_438 & V_439 ) );
if ( ! V_373 ) {
F_77 ( V_117 , L_76
L_75 , V_108 ) ;
}
}
void F_227 ( struct V_1 * V_2 ,
struct V_20 * V_82 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_440 = V_82 -> V_45 ;
T_1 V_438 ;
T_4 V_108 = V_82 -> V_108 ;
V_438 = F_11 ( V_8 , F_16 ( V_108 ) ) ;
F_225 ( V_2 , V_82 ) ;
F_45 ( V_8 , F_17 ( V_108 ) , ( V_440 & F_208 ( 32 ) ) ) ;
F_45 ( V_8 , F_18 ( V_108 ) , ( V_440 >> 32 ) ) ;
F_45 ( V_8 , F_13 ( V_108 ) ,
V_82 -> V_52 * sizeof( union V_31 ) ) ;
F_45 ( V_8 , F_14 ( V_108 ) , 0 ) ;
F_45 ( V_8 , F_15 ( V_108 ) , 0 ) ;
V_82 -> V_109 = V_8 -> V_376 + F_15 ( V_108 ) ;
F_218 ( V_2 , V_82 ) ;
F_222 ( V_2 , V_82 ) ;
if ( V_8 -> V_72 . type == V_73 ) {
V_438 &= ~ 0x3FFFFF ;
V_438 |= 0x080420 ;
}
V_438 |= V_439 ;
F_45 ( V_8 , F_16 ( V_108 ) , V_438 ) ;
F_224 ( V_2 , V_82 ) ;
F_118 ( V_82 , F_84 ( V_82 ) ) ;
}
static void F_228 ( struct V_1 * V_2 )
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
F_45 ( V_8 , F_229 ( F_230 ( V_441 ) ) ,
V_442 ) ;
}
static void F_231 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_138 , V_449 ;
T_1 V_450 , V_451 ;
int V_11 ;
if ( ! ( V_2 -> V_101 & V_388 ) )
return;
V_451 = F_11 ( V_8 , V_452 ) ;
V_451 |= V_453 ;
V_451 &= ~ V_454 ;
V_451 |= F_230 ( 0 ) << V_455 ;
V_451 |= V_456 ;
F_45 ( V_8 , V_452 , V_451 ) ;
V_449 = F_230 ( 0 ) % 32 ;
V_138 = ( F_230 ( 0 ) >= 32 ) ? 1 : 0 ;
F_45 ( V_8 , F_232 ( V_138 ) , ( ~ 0 ) << V_449 ) ;
F_45 ( V_8 , F_232 ( V_138 ^ 1 ) , V_138 - 1 ) ;
F_45 ( V_8 , F_233 ( V_138 ) , ( ~ 0 ) << V_449 ) ;
F_45 ( V_8 , F_233 ( V_138 ^ 1 ) , V_138 - 1 ) ;
if ( V_2 -> V_115 & V_457 )
F_45 ( V_8 , V_458 , V_459 ) ;
V_8 -> V_72 . V_313 . V_460 ( V_8 , 0 , F_230 ( 0 ) ) ;
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
V_8 -> V_72 . V_313 . V_468 ( V_8 , ( V_2 -> V_279 != 0 ) ,
V_2 -> V_279 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_279 ; V_11 ++ ) {
if ( ! V_2 -> V_469 [ V_11 ] . V_470 )
F_234 ( V_2 -> V_18 , V_11 , false ) ;
}
}
static void F_235 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_18 = V_2 -> V_18 ;
int V_471 = V_18 -> V_273 + V_207 + V_472 ;
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
F_236 ( V_30 ) ;
else
F_237 ( V_30 ) ;
}
}
static void F_238 ( struct V_1 * V_2 )
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
static void F_239 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_11 ;
T_1 V_143 ;
V_143 = F_11 ( V_8 , V_493 ) ;
F_45 ( V_8 , V_493 , V_143 & ~ V_494 ) ;
F_228 ( V_2 ) ;
F_238 ( V_2 ) ;
F_219 ( V_2 ) ;
F_235 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ )
F_227 ( V_2 , V_2 -> V_30 [ V_11 ] ) ;
if ( V_8 -> V_72 . type == V_73 )
V_143 |= V_495 ;
V_143 |= V_494 ;
V_8 -> V_72 . V_313 . V_496 ( V_8 , V_143 ) ;
}
static int F_240 ( struct V_17 * V_18 , T_5 V_230 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
V_8 -> V_72 . V_313 . V_497 ( & V_2 -> V_8 , V_230 , F_230 ( 0 ) , true ) ;
F_210 ( V_230 , V_2 -> V_498 ) ;
return 0 ;
}
static int F_241 ( struct V_17 * V_18 , T_5 V_230 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
V_8 -> V_72 . V_313 . V_497 ( & V_2 -> V_8 , V_230 , F_230 ( 0 ) , false ) ;
F_8 ( V_230 , V_2 -> V_498 ) ;
return 0 ;
}
static void F_242 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_499 ;
V_499 = F_11 ( V_8 , V_500 ) ;
V_499 &= ~ ( V_501 | V_502 ) ;
F_45 ( V_8 , V_500 , V_499 ) ;
}
static void F_243 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_499 ;
V_499 = F_11 ( V_8 , V_500 ) ;
V_499 |= V_501 ;
V_499 &= ~ V_502 ;
F_45 ( V_8 , V_500 , V_499 ) ;
}
static void F_244 ( struct V_1 * V_2 )
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
static void F_245 ( struct V_1 * V_2 )
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
static void F_246 ( struct V_1 * V_2 )
{
T_5 V_230 ;
F_240 ( V_2 -> V_18 , 0 ) ;
F_247 (vid, adapter->active_vlans, VLAN_N_VID)
F_240 ( V_2 -> V_18 , V_230 ) ;
}
static int F_248 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
unsigned int V_505 = V_8 -> V_72 . V_506 - 1 ;
int V_52 = 0 ;
if ( V_2 -> V_101 & V_388 )
V_505 = V_507 - 1 ;
if ( F_249 ( V_18 ) > V_505 )
return - V_508 ;
if ( ! F_250 ( V_18 ) ) {
struct V_509 * V_510 ;
if ( ! V_8 -> V_72 . V_313 . V_511 )
return - V_508 ;
F_251 (ha, netdev) {
if ( ! V_505 )
break;
V_8 -> V_72 . V_313 . V_511 ( V_8 , V_505 -- , V_510 -> V_512 ,
F_230 ( 0 ) , V_513 ) ;
V_52 ++ ;
}
}
for (; V_505 > 0 ; V_505 -- )
V_8 -> V_72 . V_313 . V_514 ( V_8 , V_505 ) ;
return V_52 ;
}
void F_252 ( struct V_17 * V_18 )
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
F_242 ( V_2 ) ;
} else {
if ( V_18 -> V_101 & V_531 ) {
V_515 |= V_525 ;
V_516 |= V_530 ;
} else {
V_8 -> V_72 . V_313 . V_532 ( V_8 , V_18 ) ;
V_516 |= V_533 ;
}
F_243 ( V_2 ) ;
V_8 -> V_527 . V_528 = false ;
}
V_52 = F_248 ( V_18 ) ;
if ( V_52 < 0 ) {
V_515 |= V_524 ;
V_516 |= V_529 ;
}
if ( V_2 -> V_279 )
F_253 ( V_2 ) ;
if ( V_8 -> V_72 . type != V_73 ) {
V_516 |= F_11 ( V_8 , F_254 ( F_230 ( 0 ) ) ) &
~ ( V_530 | V_533 |
V_529 ) ;
F_45 ( V_8 , F_254 ( F_230 ( 0 ) ) , V_516 ) ;
}
if ( V_2 -> V_18 -> V_157 & V_251 ) {
V_515 |= ( V_520 |
V_521 |
V_523 ) ;
V_515 &= ~ ( V_522 ) ;
}
F_45 ( V_8 , V_519 , V_515 ) ;
if ( V_18 -> V_157 & V_228 )
F_245 ( V_2 ) ;
else
F_244 ( V_2 ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
int V_534 ;
for ( V_534 = 0 ; V_534 < V_2 -> V_150 ; V_534 ++ )
F_256 ( & V_2 -> V_119 [ V_534 ] -> V_232 ) ;
}
static void F_257 ( struct V_1 * V_2 )
{
int V_534 ;
for ( V_534 = 0 ; V_534 < V_2 -> V_150 ; V_534 ++ )
F_258 ( & V_2 -> V_119 [ V_534 ] -> V_232 ) ;
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_471 = V_2 -> V_18 -> V_273 + V_207 + V_472 ;
if ( ! ( V_2 -> V_101 & V_102 ) ) {
if ( V_8 -> V_72 . type == V_73 )
F_260 ( V_2 -> V_18 , 65536 ) ;
return;
}
if ( V_8 -> V_72 . type == V_73 )
F_260 ( V_2 -> V_18 , 32768 ) ;
#ifdef F_122
if ( V_2 -> V_18 -> V_157 & V_535 )
V_471 = F_172 ( V_471 , V_476 ) ;
#endif
if ( V_2 -> V_536 & V_537 ) {
F_261 ( V_8 , & V_2 -> V_98 , V_471 ,
V_538 ) ;
F_261 ( V_8 , & V_2 -> V_98 , V_471 ,
V_539 ) ;
F_262 ( V_8 , & V_2 -> V_98 ) ;
} else if ( V_2 -> V_540 && V_2 -> V_100 ) {
F_263 ( & V_2 -> V_8 ,
V_2 -> V_540 ,
V_471 ) ;
F_264 ( & V_2 -> V_8 ,
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
static int F_265 ( struct V_1 * V_2 , int V_544 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_37 = V_2 -> V_18 ;
int V_347 , V_96 , V_545 , V_546 ;
T_1 V_547 , V_548 ;
V_96 = V_347 = V_37 -> V_273 + V_207 + V_472 + V_549 ;
#ifdef F_122
if ( ( V_37 -> V_157 & V_535 ) &&
( V_96 < V_476 ) &&
( V_544 == F_266 ( V_2 ) ) )
V_96 = V_476 ;
#endif
switch ( V_8 -> V_72 . type ) {
case V_76 :
V_547 = F_267 ( V_347 , V_96 ) ;
break;
default:
V_547 = F_268 ( V_347 , V_96 ) ;
break;
}
if ( V_2 -> V_101 & V_388 )
V_547 += F_269 ( V_96 ) ;
V_545 = F_270 ( V_547 ) ;
V_548 = F_11 ( V_8 , F_271 ( V_544 ) ) >> 10 ;
V_546 = V_548 - V_545 ;
if ( V_546 < 0 ) {
F_67 ( V_117 , L_77
L_78
L_79 , V_544 ) ;
V_546 = V_96 + 1 ;
}
return V_546 ;
}
static int F_272 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_37 = V_2 -> V_18 ;
int V_96 ;
T_1 V_547 ;
V_96 = V_37 -> V_273 + V_207 + V_472 ;
switch ( V_8 -> V_72 . type ) {
case V_76 :
V_547 = F_273 ( V_96 ) ;
break;
default:
V_547 = F_274 ( V_96 ) ;
break;
}
return F_270 ( V_547 ) ;
}
static void F_275 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_550 = F_214 ( V_2 -> V_18 ) ;
int V_11 ;
if ( ! V_550 )
V_550 = 1 ;
V_8 -> V_87 . V_551 = F_272 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_550 ; V_11 ++ ) {
V_8 -> V_87 . V_552 [ V_11 ] = F_265 ( V_2 , V_11 ) ;
if ( V_8 -> V_87 . V_551 > V_8 -> V_87 . V_552 [ V_11 ] )
V_8 -> V_87 . V_551 = 0 ;
}
}
static void F_276 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_553 ;
T_4 V_96 = F_214 ( V_2 -> V_18 ) ;
if ( V_2 -> V_101 & V_341 ||
V_2 -> V_101 & V_554 )
V_553 = 32 << V_2 -> V_555 ;
else
V_553 = 0 ;
V_8 -> V_72 . V_313 . V_556 ( V_8 , V_96 , V_553 , V_557 ) ;
F_275 ( V_2 ) ;
}
static void F_277 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_558 * V_559 ;
struct V_560 * V_561 ;
F_278 ( & V_2 -> V_562 ) ;
if ( ! F_279 ( & V_2 -> V_563 ) )
F_280 ( V_8 , & V_2 -> V_564 ) ;
F_281 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_282 ( V_8 ,
& V_561 -> V_561 ,
V_561 -> V_565 ,
( V_561 -> V_566 == V_567 ) ?
V_567 :
V_2 -> V_30 [ V_561 -> V_566 ] -> V_108 ) ;
}
F_283 ( & V_2 -> V_562 ) ;
}
static void F_284 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
F_276 ( V_2 ) ;
#ifdef F_285
F_259 ( V_2 ) ;
#endif
F_231 ( V_2 ) ;
F_252 ( V_2 -> V_18 ) ;
F_246 ( V_2 ) ;
switch ( V_8 -> V_72 . type ) {
case V_75 :
case V_76 :
V_8 -> V_72 . V_313 . V_568 ( V_8 ) ;
break;
default:
break;
}
if ( V_2 -> V_101 & V_341 ) {
F_286 ( & V_2 -> V_8 ,
V_2 -> V_555 ) ;
} else if ( V_2 -> V_101 & V_554 ) {
F_287 ( & V_2 -> V_8 ,
V_2 -> V_555 ) ;
F_277 ( V_2 ) ;
}
switch ( V_8 -> V_72 . type ) {
case V_75 :
case V_76 :
V_8 -> V_72 . V_313 . V_569 ( V_8 ) ;
break;
default:
break;
}
#ifdef F_122
F_288 ( V_2 ) ;
#endif
F_215 ( V_2 ) ;
F_239 ( V_2 ) ;
}
static inline bool F_289 ( struct V_7 * V_8 )
{
switch ( V_8 -> V_317 . type ) {
case V_570 :
case V_571 :
case V_572 :
case V_573 :
case V_574 :
case V_575 :
case V_576 :
case V_577 :
return true ;
case V_578 :
if ( V_8 -> V_72 . type == V_73 )
return true ;
default:
return false ;
}
}
static void F_290 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_72 . type == V_73 )
V_2 -> V_115 |= V_579 ;
V_2 -> V_115 |= V_325 ;
}
static int F_291 ( struct V_7 * V_8 )
{
T_1 V_315 ;
bool V_580 , V_316 = false ;
T_1 V_114 = V_581 ;
if ( V_8 -> V_72 . V_313 . V_314 )
V_114 = V_8 -> V_72 . V_313 . V_314 ( V_8 , & V_315 , & V_316 , false ) ;
if ( V_114 )
goto V_582;
V_315 = V_8 -> V_317 . V_583 ;
if ( ( ! V_315 ) && ( V_8 -> V_72 . V_313 . V_584 ) )
V_114 = V_8 -> V_72 . V_313 . V_584 ( V_8 , & V_315 ,
& V_580 ) ;
if ( V_114 )
goto V_582;
if ( V_8 -> V_72 . V_313 . V_585 )
V_114 = V_8 -> V_72 . V_313 . V_585 ( V_8 , V_315 , V_316 ) ;
V_582:
return V_114 ;
}
static void F_292 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_586 = 0 ;
if ( V_2 -> V_101 & V_367 ) {
V_586 = V_587 | V_588 |
V_589 ;
V_586 |= V_590 ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
F_45 ( V_8 , V_591 , V_592 ) ;
break;
case V_75 :
case V_76 :
default:
F_45 ( V_8 , F_293 ( 0 ) , 0xFFFFFFFF ) ;
F_45 ( V_8 , F_293 ( 1 ) , 0xFFFFFFFF ) ;
break;
}
} else {
F_45 ( V_8 , V_591 , V_592 ) ;
}
if ( V_2 -> V_101 & V_388 ) {
V_586 &= ~ V_593 ;
switch ( V_2 -> V_393 [ V_461 ] . V_79 ) {
case V_462 :
V_586 |= V_594 ;
break;
case V_464 :
V_586 |= V_595 ;
break;
default:
V_586 |= V_596 ;
break;
}
}
if ( V_2 -> V_115 & V_307 ) {
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
V_586 |= V_597 ;
break;
case V_76 :
V_586 |= V_336 ;
break;
default:
break;
}
}
if ( V_2 -> V_101 & V_320 )
V_586 |= V_598 ;
if ( V_8 -> V_72 . type == V_75 ) {
V_586 |= V_598 ;
V_586 |= V_599 ;
}
F_45 ( V_8 , V_600 , V_586 ) ;
}
static void F_294 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_359 ;
T_1 V_64 ;
F_46 ( V_2 ) ;
F_292 ( V_2 ) ;
if ( V_2 -> V_101 & V_367 )
F_167 ( V_2 ) ;
else
F_206 ( V_2 ) ;
if ( V_8 -> V_72 . V_313 . V_601 )
V_8 -> V_72 . V_313 . V_601 ( V_8 ) ;
F_8 ( V_3 , & V_2 -> V_4 ) ;
F_255 ( V_2 ) ;
if ( F_289 ( V_8 ) ) {
F_290 ( V_2 ) ;
} else {
V_359 = F_291 ( V_8 ) ;
if ( V_359 )
F_77 ( V_133 , L_80 , V_359 ) ;
}
F_11 ( V_8 , V_322 ) ;
F_184 ( V_2 , true , true ) ;
if ( V_2 -> V_101 & V_320 ) {
T_1 V_602 = F_11 ( V_8 , V_603 ) ;
if ( V_602 & V_604 )
F_174 ( V_117 , L_60 ) ;
}
F_295 ( V_2 -> V_18 ) ;
V_2 -> V_101 |= V_328 ;
V_2 -> V_329 = V_132 ;
F_296 ( & V_2 -> V_605 , V_132 ) ;
V_64 = F_11 ( V_8 , V_65 ) ;
V_64 |= V_606 ;
F_45 ( V_8 , V_65 , V_64 ) ;
}
void F_297 ( struct V_1 * V_2 )
{
F_298 ( F_299 () ) ;
V_2 -> V_18 -> V_38 = V_132 ;
while ( F_3 ( V_607 , & V_2 -> V_4 ) )
F_212 ( 1000 , 2000 ) ;
F_300 ( V_2 ) ;
if ( V_2 -> V_101 & V_388 )
F_301 ( 2000 ) ;
F_302 ( V_2 ) ;
F_8 ( V_607 , & V_2 -> V_4 ) ;
}
void F_302 ( struct V_1 * V_2 )
{
F_284 ( V_2 ) ;
F_294 ( V_2 ) ;
}
void F_303 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_359 ;
while ( F_3 ( V_608 , & V_2 -> V_4 ) )
F_212 ( 1000 , 2000 ) ;
V_2 -> V_115 &= ~ ( V_579 |
V_325 ) ;
V_2 -> V_101 &= ~ V_326 ;
V_359 = V_8 -> V_72 . V_313 . V_609 ( V_8 ) ;
switch ( V_359 ) {
case 0 :
case V_610 :
case V_611 :
break;
case V_612 :
F_304 ( L_81 ) ;
break;
case V_613 :
F_305 ( L_82
L_83
L_84
L_85
L_86
L_87 ) ;
break;
default:
F_304 ( L_88 , V_359 ) ;
}
F_8 ( V_608 , & V_2 -> V_4 ) ;
V_8 -> V_72 . V_313 . V_511 ( V_8 , 0 , V_8 -> V_72 . V_512 , F_230 ( 0 ) , V_513 ) ;
if ( V_8 -> V_72 . V_614 )
V_8 -> V_72 . V_313 . V_615 ( V_8 , F_230 ( 0 ) ) ;
if ( V_2 -> V_115 & V_616 )
F_306 ( V_2 ) ;
}
static void F_307 ( struct V_20 * V_30 )
{
struct V_151 * V_37 = V_30 -> V_37 ;
unsigned long V_257 ;
T_5 V_11 ;
if ( ! V_30 -> V_34 )
return;
for ( V_11 = 0 ; V_11 < V_30 -> V_52 ; V_11 ++ ) {
struct V_33 * V_256 ;
V_256 = & V_30 -> V_34 [ V_11 ] ;
if ( V_256 -> V_53 ) {
struct V_156 * V_53 = V_256 -> V_53 ;
if ( F_127 ( V_53 ) -> V_249 ) {
F_54 ( V_37 ,
F_127 ( V_53 ) -> V_45 ,
F_43 ( V_30 ) ,
V_188 ) ;
F_127 ( V_53 ) -> V_249 = false ;
}
F_308 ( V_53 ) ;
}
V_256 -> V_53 = NULL ;
if ( V_256 -> V_45 )
F_54 ( V_37 , V_256 -> V_45 ,
F_115 ( V_30 ) ,
V_188 ) ;
V_256 -> V_45 = 0 ;
if ( V_256 -> V_62 )
F_117 ( V_256 -> V_62 ,
F_113 ( V_30 ) ) ;
V_256 -> V_62 = NULL ;
}
V_257 = sizeof( struct V_33 ) * V_30 -> V_52 ;
memset ( V_30 -> V_34 , 0 , V_257 ) ;
memset ( V_30 -> V_51 , 0 , V_30 -> V_257 ) ;
V_30 -> V_182 = 0 ;
V_30 -> V_43 = 0 ;
V_30 -> V_44 = 0 ;
}
static void F_309 ( struct V_20 * V_21 )
{
struct V_22 * V_42 ;
unsigned long V_257 ;
T_5 V_11 ;
if ( ! V_21 -> V_42 )
return;
for ( V_11 = 0 ; V_11 < V_21 -> V_52 ; V_11 ++ ) {
V_42 = & V_21 -> V_42 [ V_11 ] ;
F_51 ( V_21 , V_42 ) ;
}
F_310 ( F_81 ( V_21 ) ) ;
V_257 = sizeof( struct V_22 ) * V_21 -> V_52 ;
memset ( V_21 -> V_42 , 0 , V_257 ) ;
memset ( V_21 -> V_51 , 0 , V_21 -> V_257 ) ;
V_21 -> V_44 = 0 ;
V_21 -> V_43 = 0 ;
}
static void F_311 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ )
F_307 ( V_2 -> V_30 [ V_11 ] ) ;
}
static void F_312 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_309 ( V_2 -> V_21 [ V_11 ] ) ;
}
static void F_313 ( struct V_1 * V_2 )
{
struct V_558 * V_559 ;
struct V_560 * V_561 ;
F_278 ( & V_2 -> V_562 ) ;
F_281 (filter, node2,
&adapter->fdir_filter_list, fdir_node) {
F_314 ( & V_561 -> V_617 ) ;
F_200 ( V_561 ) ;
}
V_2 -> V_618 = 0 ;
F_283 ( & V_2 -> V_562 ) ;
}
void F_300 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_143 ;
int V_11 ;
F_210 ( V_3 , & V_2 -> V_4 ) ;
V_143 = F_11 ( V_8 , V_493 ) ;
F_45 ( V_8 , V_493 , V_143 & ~ V_494 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ )
F_225 ( V_2 , V_2 -> V_30 [ V_11 ] ) ;
F_212 ( 10000 , 20000 ) ;
F_315 ( V_18 ) ;
F_316 ( V_18 ) ;
F_317 ( V_18 ) ;
F_204 ( V_2 ) ;
F_257 ( V_2 ) ;
V_2 -> V_115 &= ~ ( V_342 |
V_116 ) ;
V_2 -> V_101 &= ~ V_328 ;
F_318 ( & V_2 -> V_605 ) ;
if ( V_2 -> V_279 ) {
F_45 ( & V_2 -> V_8 , V_281 , 0 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_279 ; V_11 ++ )
V_2 -> V_469 [ V_11 ] . V_619 = false ;
F_319 ( V_2 ) ;
F_320 ( V_2 ) ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
T_4 V_108 = V_2 -> V_21 [ V_11 ] -> V_108 ;
F_45 ( V_8 , F_24 ( V_108 ) , V_620 ) ;
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
if ( ! F_321 ( V_2 -> V_36 ) )
F_303 ( V_2 ) ;
if ( V_8 -> V_72 . V_313 . V_621 )
V_8 -> V_72 . V_313 . V_621 ( V_8 ) ;
F_312 ( V_2 ) ;
F_311 ( V_2 ) ;
#ifdef F_193
F_97 ( V_2 ) ;
#endif
}
static void F_322 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
F_66 ( V_2 ) ;
}
static int F_323 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_622 * V_36 = V_2 -> V_36 ;
unsigned int V_162 , V_623 ;
T_1 V_624 ;
#ifdef F_285
int V_12 ;
struct V_625 * V_96 ;
#endif
V_8 -> V_626 = V_36 -> V_627 ;
V_8 -> V_309 = V_36 -> V_151 ;
V_8 -> V_628 = V_36 -> V_629 ;
V_8 -> V_630 = V_36 -> V_631 ;
V_8 -> V_632 = V_36 -> V_633 ;
V_162 = F_324 ( int , V_634 , F_325 () ) ;
V_2 -> V_393 [ V_394 ] . V_635 = V_162 ;
V_2 -> V_115 |= V_636 ;
V_2 -> V_115 |= V_483 ;
V_2 -> V_637 = V_638 ;
V_2 -> V_378 = 20 ;
V_623 = F_324 ( int , V_639 , F_325 () ) ;
V_2 -> V_393 [ V_640 ] . V_635 = V_623 ;
V_2 -> V_555 = V_641 ;
#ifdef F_193
V_2 -> V_101 |= V_153 ;
#endif
#ifdef F_122
V_2 -> V_101 |= V_642 ;
V_2 -> V_101 &= ~ V_475 ;
#ifdef F_285
V_2 -> V_643 . V_644 = V_645 ;
#endif
#endif
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_2 -> V_115 &= ~ V_636 ;
V_2 -> V_115 &= ~ V_483 ;
if ( V_8 -> V_309 == V_646 )
V_2 -> V_101 |= V_320 ;
V_2 -> V_637 = V_647 ;
V_2 -> V_393 [ V_640 ] . V_635 = 0 ;
V_2 -> V_378 = 0 ;
V_2 -> V_555 = 0 ;
#ifdef F_122
V_2 -> V_101 &= ~ V_642 ;
V_2 -> V_101 &= ~ V_475 ;
#ifdef F_285
V_2 -> V_643 . V_644 = 0 ;
#endif
#endif
break;
case V_75 :
if ( V_8 -> V_309 == V_310 )
V_2 -> V_115 |= V_307 ;
break;
case V_76 :
V_624 = F_11 ( V_8 , V_648 ) ;
if ( V_624 & V_649 )
V_2 -> V_115 |= V_307 ;
break;
default:
break;
}
#ifdef F_122
F_326 ( & V_2 -> V_643 . V_650 ) ;
#endif
F_326 ( & V_2 -> V_562 ) ;
#ifdef F_285
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
F_275 ( V_2 ) ;
V_8 -> V_87 . V_668 = V_669 ;
V_8 -> V_87 . V_670 = true ;
V_8 -> V_87 . V_671 =
( F_327 ( V_8 ) == 0 ) ? false : true ;
#ifdef F_328
if ( V_8 -> V_72 . type != V_73 )
V_2 -> V_279 = ( V_672 > 63 ) ? 0 : V_672 ;
#endif
V_2 -> V_357 = 1 ;
V_2 -> V_673 = 1 ;
V_2 -> V_674 = V_675 ;
V_2 -> V_676 = V_677 ;
V_2 -> V_678 = V_679 ;
if ( F_329 ( V_8 ) ) {
F_304 ( L_89 ) ;
return - V_680 ;
}
F_210 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
}
int F_330 ( struct V_20 * V_21 )
{
struct V_151 * V_37 = V_21 -> V_37 ;
int V_681 = F_331 ( V_37 ) ;
int V_682 = - 1 ;
int V_257 ;
V_257 = sizeof( struct V_22 ) * V_21 -> V_52 ;
if ( V_21 -> V_119 )
V_682 = V_21 -> V_119 -> V_682 ;
V_21 -> V_42 = F_332 ( V_257 , V_682 ) ;
if ( ! V_21 -> V_42 )
V_21 -> V_42 = F_333 ( V_257 ) ;
if ( ! V_21 -> V_42 )
goto V_359;
V_21 -> V_257 = V_21 -> V_52 * sizeof( union V_24 ) ;
V_21 -> V_257 = F_143 ( V_21 -> V_257 , 4096 ) ;
F_334 ( V_37 , V_682 ) ;
V_21 -> V_51 = F_335 ( V_37 ,
V_21 -> V_257 ,
& V_21 -> V_45 ,
V_683 ) ;
F_334 ( V_37 , V_681 ) ;
if ( ! V_21 -> V_51 )
V_21 -> V_51 = F_335 ( V_37 , V_21 -> V_257 ,
& V_21 -> V_45 , V_683 ) ;
if ( ! V_21 -> V_51 )
goto V_359;
V_21 -> V_44 = 0 ;
V_21 -> V_43 = 0 ;
return 0 ;
V_359:
F_336 ( V_21 -> V_42 ) ;
V_21 -> V_42 = NULL ;
F_337 ( V_37 , L_90 ) ;
return - V_508 ;
}
static int F_338 ( struct V_1 * V_2 )
{
int V_11 , V_359 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
V_359 = F_330 ( V_2 -> V_21 [ V_11 ] ) ;
if ( ! V_359 )
continue;
F_77 ( V_133 , L_91 , V_11 ) ;
goto V_684;
}
return 0 ;
V_684:
while ( V_11 -- )
F_339 ( V_2 -> V_21 [ V_11 ] ) ;
return V_359 ;
}
int F_340 ( struct V_20 * V_30 )
{
struct V_151 * V_37 = V_30 -> V_37 ;
int V_681 = F_331 ( V_37 ) ;
int V_682 = - 1 ;
int V_257 ;
V_257 = sizeof( struct V_33 ) * V_30 -> V_52 ;
if ( V_30 -> V_119 )
V_682 = V_30 -> V_119 -> V_682 ;
V_30 -> V_34 = F_332 ( V_257 , V_682 ) ;
if ( ! V_30 -> V_34 )
V_30 -> V_34 = F_333 ( V_257 ) ;
if ( ! V_30 -> V_34 )
goto V_359;
V_30 -> V_257 = V_30 -> V_52 * sizeof( union V_31 ) ;
V_30 -> V_257 = F_143 ( V_30 -> V_257 , 4096 ) ;
F_334 ( V_37 , V_682 ) ;
V_30 -> V_51 = F_335 ( V_37 ,
V_30 -> V_257 ,
& V_30 -> V_45 ,
V_683 ) ;
F_334 ( V_37 , V_681 ) ;
if ( ! V_30 -> V_51 )
V_30 -> V_51 = F_335 ( V_37 , V_30 -> V_257 ,
& V_30 -> V_45 , V_683 ) ;
if ( ! V_30 -> V_51 )
goto V_359;
V_30 -> V_43 = 0 ;
V_30 -> V_44 = 0 ;
return 0 ;
V_359:
F_336 ( V_30 -> V_34 ) ;
V_30 -> V_34 = NULL ;
F_337 ( V_37 , L_92 ) ;
return - V_508 ;
}
static int F_341 ( struct V_1 * V_2 )
{
int V_11 , V_359 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
V_359 = F_340 ( V_2 -> V_30 [ V_11 ] ) ;
if ( ! V_359 )
continue;
F_77 ( V_133 , L_93 , V_11 ) ;
goto V_685;
}
#ifdef F_122
V_359 = F_342 ( V_2 ) ;
if ( ! V_359 )
#endif
return 0 ;
V_685:
while ( V_11 -- )
F_343 ( V_2 -> V_30 [ V_11 ] ) ;
return V_359 ;
}
void F_339 ( struct V_20 * V_21 )
{
F_309 ( V_21 ) ;
F_336 ( V_21 -> V_42 ) ;
V_21 -> V_42 = NULL ;
if ( ! V_21 -> V_51 )
return;
F_344 ( V_21 -> V_37 , V_21 -> V_257 ,
V_21 -> V_51 , V_21 -> V_45 ) ;
V_21 -> V_51 = NULL ;
}
static void F_345 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
if ( V_2 -> V_21 [ V_11 ] -> V_51 )
F_339 ( V_2 -> V_21 [ V_11 ] ) ;
}
void F_343 ( struct V_20 * V_30 )
{
F_307 ( V_30 ) ;
F_336 ( V_30 -> V_34 ) ;
V_30 -> V_34 = NULL ;
if ( ! V_30 -> V_51 )
return;
F_344 ( V_30 -> V_37 , V_30 -> V_257 ,
V_30 -> V_51 , V_30 -> V_45 ) ;
V_30 -> V_51 = NULL ;
}
static void F_346 ( struct V_1 * V_2 )
{
int V_11 ;
#ifdef F_122
F_347 ( V_2 ) ;
#endif
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ )
if ( V_2 -> V_30 [ V_11 ] -> V_51 )
F_343 ( V_2 -> V_30 [ V_11 ] ) ;
}
static int F_348 ( struct V_17 * V_18 , int V_686 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
int V_471 = V_686 + V_207 + V_472 ;
if ( ( V_686 < 68 ) || ( V_471 > V_687 ) )
return - V_688 ;
if ( ( V_2 -> V_101 & V_388 ) &&
( V_2 -> V_8 . V_72 . type == V_75 ) &&
( V_471 > ( V_477 + V_472 ) ) )
F_67 ( V_133 , L_94 ) ;
F_79 ( V_133 , L_95 , V_18 -> V_273 , V_686 ) ;
V_18 -> V_273 = V_686 ;
if ( F_31 ( V_18 ) )
F_297 ( V_2 ) ;
return 0 ;
}
static int F_349 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
int V_359 ;
if ( F_2 ( V_689 , & V_2 -> V_4 ) )
return - V_690 ;
F_316 ( V_18 ) ;
V_359 = F_338 ( V_2 ) ;
if ( V_359 )
goto V_684;
V_359 = F_341 ( V_2 ) ;
if ( V_359 )
goto V_685;
F_284 ( V_2 ) ;
V_359 = F_202 ( V_2 ) ;
if ( V_359 )
goto V_691;
V_359 = F_350 ( V_18 ,
V_2 -> V_448 > 1 ? 1 :
V_2 -> V_41 ) ;
if ( V_359 )
goto V_692;
V_359 = F_351 ( V_18 ,
V_2 -> V_448 > 1 ? 1 :
V_2 -> V_57 ) ;
if ( V_359 )
goto V_692;
F_352 ( V_2 ) ;
F_294 ( V_2 ) ;
return 0 ;
V_692:
F_203 ( V_2 ) ;
V_691:
F_346 ( V_2 ) ;
V_685:
F_345 ( V_2 ) ;
V_684:
F_303 ( V_2 ) ;
return V_359 ;
}
static int F_353 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
F_354 ( V_2 ) ;
F_300 ( V_2 ) ;
F_203 ( V_2 ) ;
F_313 ( V_2 ) ;
F_345 ( V_2 ) ;
F_346 ( V_2 ) ;
F_44 ( V_2 ) ;
return 0 ;
}
static int F_355 ( struct V_622 * V_36 )
{
struct V_1 * V_2 = F_356 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_359 ;
F_357 ( V_36 , V_693 ) ;
F_358 ( V_36 ) ;
F_359 ( V_36 ) ;
V_359 = F_360 ( V_36 ) ;
if ( V_359 ) {
F_304 ( L_96 ) ;
return V_359 ;
}
F_361 ( V_36 ) ;
F_362 ( V_36 , false ) ;
F_303 ( V_2 ) ;
F_45 ( & V_2 -> V_8 , V_694 , ~ 0 ) ;
F_363 () ;
V_359 = F_364 ( V_2 ) ;
if ( ! V_359 && F_31 ( V_18 ) )
V_359 = F_349 ( V_18 ) ;
F_365 () ;
if ( V_359 )
return V_359 ;
F_366 ( V_18 ) ;
return 0 ;
}
static int F_367 ( struct V_622 * V_36 , bool * V_695 )
{
struct V_1 * V_2 = F_356 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_696 , V_515 ;
T_1 V_697 = V_2 -> V_698 ;
#ifdef F_368
int V_699 = 0 ;
#endif
F_369 ( V_18 ) ;
if ( F_31 ( V_18 ) ) {
F_363 () ;
F_300 ( V_2 ) ;
F_203 ( V_2 ) ;
F_345 ( V_2 ) ;
F_346 ( V_2 ) ;
F_365 () ;
}
F_370 ( V_2 ) ;
#ifdef F_368
V_699 = F_359 ( V_36 ) ;
if ( V_699 )
return V_699 ;
#endif
if ( V_697 ) {
F_252 ( V_18 ) ;
if ( V_8 -> V_72 . V_313 . V_601 )
V_8 -> V_72 . V_313 . V_601 ( V_8 ) ;
if ( V_697 & V_700 ) {
V_515 = F_11 ( V_8 , V_519 ) ;
V_515 |= V_525 ;
F_45 ( V_8 , V_519 , V_515 ) ;
}
V_696 = F_11 ( V_8 , V_701 ) ;
V_696 |= V_702 ;
F_45 ( V_8 , V_701 , V_696 ) ;
F_45 ( V_8 , V_703 , V_697 ) ;
} else {
F_45 ( V_8 , V_704 , 0 ) ;
F_45 ( V_8 , V_703 , 0 ) ;
}
switch ( V_8 -> V_72 . type ) {
case V_73 :
F_362 ( V_36 , false ) ;
break;
case V_75 :
case V_76 :
F_362 ( V_36 , ! ! V_697 ) ;
break;
default:
break;
}
* V_695 = ! ! V_697 ;
F_44 ( V_2 ) ;
F_371 ( V_36 ) ;
return 0 ;
}
static int F_372 ( struct V_622 * V_36 , T_11 V_4 )
{
int V_699 ;
bool V_705 ;
V_699 = F_367 ( V_36 , & V_705 ) ;
if ( V_699 )
return V_699 ;
if ( V_705 ) {
F_373 ( V_36 ) ;
} else {
F_362 ( V_36 , false ) ;
F_357 ( V_36 , V_706 ) ;
}
return 0 ;
}
static void F_374 ( struct V_622 * V_36 )
{
bool V_705 ;
F_367 ( V_36 , & V_705 ) ;
if ( V_707 == V_708 ) {
F_362 ( V_36 , V_705 ) ;
F_357 ( V_36 , V_706 ) ;
}
}
void F_375 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_84 * V_85 = & V_2 -> V_86 ;
T_2 V_709 = 0 ;
T_1 V_11 , V_710 = 0 , V_711 , V_712 , V_713 , V_714 , V_715 ;
T_2 V_241 = 0 , V_135 = 0 , V_716 = 0 ;
T_2 V_187 = 0 , V_266 = 0 ;
T_2 V_131 = 0 , V_106 = 0 , V_717 = 0 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_607 , & V_2 -> V_4 ) )
return;
if ( V_2 -> V_115 & V_483 ) {
T_2 V_226 = 0 ;
T_2 V_227 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
V_226 += V_2 -> V_30 [ V_11 ] -> V_173 . V_226 ;
V_227 += V_2 -> V_30 [ V_11 ] -> V_173 . V_227 ;
}
V_2 -> V_718 = V_226 ;
V_2 -> V_719 = V_227 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
struct V_20 * V_30 = V_2 -> V_30 [ V_11 ] ;
V_241 += V_30 -> V_173 . V_241 ;
V_187 += V_30 -> V_173 . V_187 ;
V_266 += V_30 -> V_173 . V_266 ;
V_717 += V_30 -> V_173 . V_174 ;
V_131 += V_30 -> V_86 . V_131 ;
V_106 += V_30 -> V_86 . V_106 ;
}
V_2 -> V_241 = V_241 ;
V_2 -> V_187 = V_187 ;
V_2 -> V_266 = V_266 ;
V_2 -> V_717 = V_717 ;
V_18 -> V_86 . V_720 = V_131 ;
V_18 -> V_86 . V_721 = V_106 ;
V_131 = 0 ;
V_106 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_21 = V_2 -> V_21 [ V_11 ] ;
V_135 += V_21 -> V_112 . V_135 ;
V_716 += V_21 -> V_112 . V_716 ;
V_131 += V_21 -> V_86 . V_131 ;
V_106 += V_21 -> V_86 . V_106 ;
}
V_2 -> V_135 = V_135 ;
V_2 -> V_716 = V_716 ;
V_18 -> V_86 . V_722 = V_131 ;
V_18 -> V_86 . V_723 = V_106 ;
V_85 -> V_724 += F_11 ( V_8 , V_725 ) ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_711 = F_11 ( V_8 , F_376 ( V_11 ) ) ;
V_710 += V_711 ;
V_85 -> V_711 [ V_11 ] += V_711 ;
V_709 += V_85 -> V_711 [ V_11 ] ;
V_85 -> V_726 [ V_11 ] += F_11 ( V_8 , F_377 ( V_11 ) ) ;
V_85 -> V_727 [ V_11 ] += F_11 ( V_8 , F_378 ( V_11 ) ) ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_85 -> V_728 [ V_11 ] += F_11 ( V_8 , F_379 ( V_11 ) ) ;
V_85 -> V_729 [ V_11 ] += F_11 ( V_8 , F_380 ( V_11 ) ) ;
V_85 -> V_730 [ V_11 ] += F_11 ( V_8 , F_381 ( V_11 ) ) ;
V_85 -> V_731 [ V_11 ] +=
F_11 ( V_8 , F_382 ( V_11 ) ) ;
break;
case V_75 :
case V_76 :
V_85 -> V_731 [ V_11 ] +=
F_11 ( V_8 , F_383 ( V_11 ) ) ;
break;
default:
break;
}
}
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ ) {
V_85 -> V_732 [ V_11 ] += F_11 ( V_8 , F_384 ( V_11 ) ) ;
V_85 -> V_733 [ V_11 ] += F_11 ( V_8 , F_385 ( V_11 ) ) ;
if ( ( V_8 -> V_72 . type == V_75 ) ||
( V_8 -> V_72 . type == V_76 ) ) {
V_85 -> V_729 [ V_11 ] += F_11 ( V_8 , F_386 ( V_11 ) ) ;
F_11 ( V_8 , F_387 ( V_11 ) ) ;
V_85 -> V_730 [ V_11 ] += F_11 ( V_8 , F_388 ( V_11 ) ) ;
F_11 ( V_8 , F_389 ( V_11 ) ) ;
}
}
V_85 -> V_734 += F_11 ( V_8 , V_735 ) ;
V_85 -> V_734 -= V_710 ;
F_57 ( V_2 ) ;
switch ( V_8 -> V_72 . type ) {
case V_73 :
V_85 -> V_736 += F_11 ( V_8 , V_737 ) ;
V_85 -> V_738 += F_11 ( V_8 , V_739 ) ;
V_85 -> V_740 += F_11 ( V_8 , V_741 ) ;
V_85 -> V_742 += F_11 ( V_8 , V_743 ) ;
break;
case V_76 :
V_85 -> V_744 += F_11 ( V_8 , V_745 ) ;
V_85 -> V_746 += F_11 ( V_8 , V_747 ) ;
V_85 -> V_748 += F_11 ( V_8 , V_749 ) ;
V_85 -> V_750 += F_11 ( V_8 , V_751 ) ;
case V_75 :
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
V_2 -> V_752 +=
F_11 ( V_8 , F_390 ( V_11 ) ) ;
V_85 -> V_738 += F_11 ( V_8 , V_753 ) ;
F_11 ( V_8 , V_739 ) ;
V_85 -> V_740 += F_11 ( V_8 , V_754 ) ;
F_11 ( V_8 , V_741 ) ;
V_85 -> V_742 += F_11 ( V_8 , V_755 ) ;
F_11 ( V_8 , V_743 ) ;
V_85 -> V_736 += F_11 ( V_8 , V_756 ) ;
V_85 -> V_757 += F_11 ( V_8 , V_758 ) ;
V_85 -> V_759 += F_11 ( V_8 , V_760 ) ;
#ifdef F_122
V_85 -> V_761 += F_11 ( V_8 , V_762 ) ;
V_85 -> V_763 += F_11 ( V_8 , V_764 ) ;
V_85 -> V_765 += F_11 ( V_8 , V_766 ) ;
V_85 -> V_767 += F_11 ( V_8 , V_768 ) ;
V_85 -> V_769 += F_11 ( V_8 , V_770 ) ;
V_85 -> V_771 += F_11 ( V_8 , V_772 ) ;
if ( V_2 -> V_643 . V_773 ) {
struct V_774 * V_643 = & V_2 -> V_643 ;
struct V_775 * V_773 ;
unsigned int V_136 ;
T_2 V_776 = 0 , V_777 = 0 ;
F_391 (cpu) {
V_773 = F_392 ( V_643 -> V_773 , V_136 ) ;
V_776 += V_773 -> V_776 ;
V_777 += V_773 -> V_777 ;
}
V_85 -> V_778 = V_776 ;
V_85 -> V_779 = V_777 ;
}
#endif
break;
default:
break;
}
V_712 = F_11 ( V_8 , V_780 ) ;
V_85 -> V_712 += V_712 ;
V_85 -> V_781 += F_11 ( V_8 , V_782 ) ;
if ( V_8 -> V_72 . type == V_73 )
V_85 -> V_781 -= V_712 ;
V_85 -> V_783 += F_11 ( V_8 , V_784 ) ;
V_85 -> V_785 += F_11 ( V_8 , V_786 ) ;
V_85 -> V_787 += F_11 ( V_8 , V_788 ) ;
V_85 -> V_789 += F_11 ( V_8 , V_790 ) ;
V_85 -> V_791 += F_11 ( V_8 , V_792 ) ;
V_85 -> V_793 += F_11 ( V_8 , V_794 ) ;
V_85 -> V_795 += F_11 ( V_8 , V_796 ) ;
V_85 -> V_797 += F_11 ( V_8 , V_798 ) ;
V_713 = F_11 ( V_8 , V_799 ) ;
V_85 -> V_800 += V_713 ;
V_714 = F_11 ( V_8 , V_801 ) ;
V_85 -> V_802 += V_714 ;
V_85 -> V_803 += F_11 ( V_8 , V_804 ) ;
V_85 -> V_805 += F_11 ( V_8 , V_806 ) ;
V_715 = V_713 + V_714 ;
V_85 -> V_803 -= V_715 ;
V_85 -> V_805 -= V_715 ;
V_85 -> V_740 -= ( V_715 * ( V_807 + V_472 ) ) ;
V_85 -> V_808 += F_11 ( V_8 , V_809 ) ;
V_85 -> V_810 += F_11 ( V_8 , V_811 ) ;
V_85 -> V_812 += F_11 ( V_8 , V_813 ) ;
V_85 -> V_814 += F_11 ( V_8 , V_815 ) ;
V_85 -> V_816 += F_11 ( V_8 , V_817 ) ;
V_85 -> V_816 -= V_715 ;
V_85 -> V_818 += F_11 ( V_8 , V_819 ) ;
V_85 -> V_820 += F_11 ( V_8 , V_821 ) ;
V_85 -> V_822 += F_11 ( V_8 , V_823 ) ;
V_85 -> V_824 += F_11 ( V_8 , V_825 ) ;
V_85 -> V_826 += F_11 ( V_8 , V_827 ) ;
V_85 -> V_828 += F_11 ( V_8 , V_829 ) ;
V_18 -> V_86 . V_830 = V_85 -> V_781 ;
V_18 -> V_86 . V_831 = V_85 -> V_724 + V_85 -> V_797 ;
V_18 -> V_86 . V_832 = 0 ;
V_18 -> V_86 . V_833 = V_85 -> V_797 ;
V_18 -> V_86 . V_834 = V_85 -> V_724 ;
V_18 -> V_86 . V_835 = V_709 ;
}
static void F_393 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_11 ;
if ( ! ( V_2 -> V_115 & V_342 ) )
return;
V_2 -> V_115 &= ~ V_342 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
if ( ! ( V_2 -> V_101 & V_341 ) )
return;
V_2 -> V_836 ++ ;
if ( F_394 ( V_8 ) == 0 ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_210 ( V_350 ,
& ( V_2 -> V_21 [ V_11 ] -> V_4 ) ) ;
F_45 ( V_8 , V_332 , V_343 ) ;
} else {
F_77 ( V_133 , L_97
L_98 ) ;
}
}
static void F_395 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_837 = 0 ;
int V_11 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_607 , & V_2 -> V_4 ) )
return;
if ( F_83 ( V_2 -> V_18 ) ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ )
F_396 ( V_2 -> V_21 [ V_11 ] ) ;
}
if ( ! ( V_2 -> V_101 & V_367 ) ) {
F_45 ( V_8 , V_81 ,
( V_838 | V_839 ) ) ;
} else {
for ( V_11 = 0 ; V_11 < V_2 -> V_150 ; V_11 ++ ) {
struct V_118 * V_840 = V_2 -> V_119 [ V_11 ] ;
if ( V_840 -> V_277 . V_82 || V_840 -> V_123 . V_82 )
V_837 |= ( ( T_2 ) 1 << V_11 ) ;
}
}
F_49 ( V_2 , V_837 ) ;
}
static void F_397 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_841 = V_2 -> V_841 ;
bool V_316 = V_2 -> V_316 ;
bool V_97 = V_2 -> V_98 . V_99 ;
if ( ! ( V_2 -> V_101 & V_328 ) )
return;
if ( V_8 -> V_72 . V_313 . V_314 ) {
V_8 -> V_72 . V_313 . V_314 ( V_8 , & V_841 , & V_316 , false ) ;
} else {
V_841 = V_842 ;
V_316 = true ;
}
if ( V_2 -> V_100 )
V_97 |= ! ! ( V_2 -> V_100 -> V_97 ) ;
if ( V_316 && ! ( ( V_2 -> V_101 & V_102 ) && V_97 ) ) {
V_8 -> V_72 . V_313 . V_843 ( V_8 ) ;
F_398 ( V_2 ) ;
}
if ( V_316 ||
F_399 ( V_132 , ( V_2 -> V_329 +
V_844 ) ) ) {
V_2 -> V_101 &= ~ V_328 ;
F_45 ( V_8 , V_332 , V_331 ) ;
F_179 ( V_8 ) ;
}
V_2 -> V_316 = V_316 ;
V_2 -> V_841 = V_841 ;
}
static void F_400 ( struct V_1 * V_2 )
{
#ifdef F_285
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_845 V_846 = {
. V_847 = V_848 ,
. V_204 = 0 ,
} ;
T_4 V_644 = 0 ;
if ( V_2 -> V_536 & V_849 )
V_644 = F_401 ( V_18 , & V_846 ) ;
V_2 -> V_850 = ( V_644 > 1 ) ? ( F_402 ( V_644 ) - 1 ) : 0 ;
#endif
}
static void F_403 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_841 = V_2 -> V_841 ;
bool V_851 , V_852 ;
if ( F_83 ( V_18 ) )
return;
V_2 -> V_115 &= ~ V_579 ;
switch ( V_8 -> V_72 . type ) {
case V_73 : {
T_1 V_853 = F_11 ( V_8 , V_519 ) ;
T_1 V_854 = F_11 ( V_8 , V_855 ) ;
V_851 = ! ! ( V_853 & V_856 ) ;
V_852 = ! ! ( V_854 & V_857 ) ;
}
break;
case V_76 :
case V_75 : {
T_1 V_858 = F_11 ( V_8 , V_859 ) ;
T_1 V_860 = F_11 ( V_8 , V_861 ) ;
V_851 = ! ! ( V_858 & V_862 ) ;
V_852 = ! ! ( V_860 & V_863 ) ;
}
break;
default:
V_852 = false ;
V_851 = false ;
break;
}
V_2 -> V_864 = V_132 ;
if ( V_2 -> V_115 & V_616 )
F_404 ( V_2 ) ;
F_79 ( V_117 , L_99 ,
( V_841 == V_842 ?
L_100 :
( V_841 == V_865 ?
L_101 :
( V_841 == V_866 ?
L_102 :
L_103 ) ) ) ,
( ( V_851 && V_852 ) ? L_104 :
( V_851 ? L_105 :
( V_852 ? L_106 : L_107 ) ) ) ) ;
F_405 ( V_18 ) ;
F_406 ( V_2 ) ;
F_400 ( V_2 ) ;
F_319 ( V_2 ) ;
}
static void F_407 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
V_2 -> V_316 = false ;
V_2 -> V_841 = 0 ;
if ( ! F_83 ( V_18 ) )
return;
if ( F_289 ( V_8 ) && V_8 -> V_72 . type == V_73 )
V_2 -> V_115 |= V_579 ;
if ( V_2 -> V_115 & V_616 )
F_404 ( V_2 ) ;
F_79 ( V_117 , L_108 ) ;
F_316 ( V_18 ) ;
F_319 ( V_2 ) ;
}
static void F_408 ( struct V_1 * V_2 )
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
F_67 ( V_117 , L_109 ) ;
V_2 -> V_115 |= V_116 ;
}
}
}
static void F_409 ( struct V_1 * V_2 )
{
T_1 V_868 ;
if ( V_2 -> V_8 . V_72 . type == V_73 ||
V_2 -> V_279 == 0 )
return;
V_868 = F_11 ( & V_2 -> V_8 , V_869 ) ;
if ( ! V_868 )
return;
F_67 ( V_117 , L_110 , V_868 ) ;
}
static void F_410 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_607 , & V_2 -> V_4 ) )
return;
F_397 ( V_2 ) ;
if ( V_2 -> V_316 )
F_403 ( V_2 ) ;
else
F_407 ( V_2 ) ;
F_409 ( V_2 ) ;
F_375 ( V_2 ) ;
F_408 ( V_2 ) ;
}
static void F_411 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_12 V_359 ;
if ( ! ( V_2 -> V_115 & V_579 ) &&
! ( V_2 -> V_115 & V_325 ) )
return;
if ( F_2 ( V_870 , & V_2 -> V_4 ) )
return;
if ( F_3 ( V_608 , & V_2 -> V_4 ) )
return;
V_359 = V_8 -> V_317 . V_313 . V_871 ( V_8 ) ;
if ( V_359 == V_611 )
goto V_872;
if ( V_359 == V_610 ) {
V_2 -> V_115 |= V_325 ;
}
if ( V_359 )
goto V_872;
if ( ! ( V_2 -> V_115 & V_325 ) )
goto V_872;
V_2 -> V_115 &= ~ V_325 ;
if ( V_8 -> V_72 . type == V_73 )
V_359 = V_8 -> V_317 . V_313 . V_873 ( V_8 ) ;
else
V_359 = V_8 -> V_72 . V_313 . V_874 ( V_8 ) ;
if ( V_359 == V_611 )
goto V_872;
V_2 -> V_101 |= V_326 ;
F_79 ( V_133 , L_111 , V_8 -> V_317 . V_875 ) ;
V_872:
F_8 ( V_608 , & V_2 -> V_4 ) ;
if ( ( V_359 == V_611 ) &&
( V_2 -> V_18 -> V_876 == V_877 ) ) {
F_304 ( L_112
L_113 ) ;
F_304 ( L_114
L_115 ) ;
F_412 ( V_2 -> V_18 ) ;
}
}
static void F_413 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_315 ;
bool V_580 = false ;
if ( ! ( V_2 -> V_101 & V_326 ) )
return;
if ( F_3 ( V_608 , & V_2 -> V_4 ) )
return;
V_2 -> V_101 &= ~ V_326 ;
V_315 = V_8 -> V_317 . V_583 ;
if ( ( ! V_315 ) && ( V_8 -> V_72 . V_313 . V_584 ) )
V_8 -> V_72 . V_313 . V_584 ( V_8 , & V_315 , & V_580 ) ;
if ( V_8 -> V_72 . V_313 . V_585 )
V_8 -> V_72 . V_313 . V_585 ( V_8 , V_315 , true ) ;
V_2 -> V_101 |= V_328 ;
V_2 -> V_329 = V_132 ;
F_8 ( V_608 , & V_2 -> V_4 ) ;
}
static void F_414 ( struct V_1 * V_2 )
{
int V_878 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_879 ;
T_1 V_880 , V_881 ;
V_879 = F_11 ( V_8 , V_882 ) ;
if ( V_879 )
return;
for ( V_878 = 0 ; V_878 < V_2 -> V_279 ; V_878 ++ ) {
V_880 = ( V_878 << 16 ) | 0x80000000 ;
V_880 |= V_883 ;
F_45 ( V_8 , V_884 , V_880 ) ;
V_881 = F_11 ( V_8 , V_885 ) ;
V_880 &= 0x7FFFFFFF ;
F_45 ( V_8 , V_884 , V_880 ) ;
V_881 >>= 16 ;
if ( V_881 & V_886 ) {
F_415 ( V_18 , L_116 , V_878 ) ;
V_880 = ( V_878 << 16 ) | 0x80000000 ;
V_880 |= 0xA8 ;
F_45 ( V_8 , V_884 , V_880 ) ;
V_881 = 0x00008000 ;
F_45 ( V_8 , V_885 , V_881 ) ;
V_880 &= 0x7FFFFFFF ;
F_45 ( V_8 , V_884 , V_880 ) ;
}
}
}
static void F_416 ( unsigned long V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
unsigned long V_887 ;
bool V_888 = true ;
if ( V_2 -> V_101 & V_328 )
V_887 = V_889 / 10 ;
else
V_887 = V_889 * 2 ;
#ifdef F_328
if ( ! V_2 -> V_279 ||
( V_2 -> V_101 & V_328 ) )
goto V_890;
F_414 ( V_2 ) ;
V_887 = V_889 / 50 ;
V_2 -> V_891 ++ ;
if ( V_2 -> V_891 >= 100 )
V_2 -> V_891 = 0 ;
else
V_888 = false ;
V_890:
#endif
F_296 ( & V_2 -> V_605 , V_887 + V_132 ) ;
if ( V_888 )
F_1 ( V_2 ) ;
}
static void F_417 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_115 & V_116 ) )
return;
V_2 -> V_115 &= ~ V_116 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_607 , & V_2 -> V_4 ) )
return;
F_28 ( V_2 ) ;
F_415 ( V_2 -> V_18 , L_117 ) ;
V_2 -> V_134 ++ ;
F_297 ( V_2 ) ;
}
static void F_418 ( struct V_892 * V_893 )
{
struct V_1 * V_2 = F_192 ( V_893 ,
struct V_1 ,
V_6 ) ;
F_417 ( V_2 ) ;
F_411 ( V_2 ) ;
F_413 ( V_2 ) ;
F_173 ( V_2 ) ;
F_410 ( V_2 ) ;
F_393 ( V_2 ) ;
F_395 ( V_2 ) ;
if ( V_2 -> V_115 & V_616 ) {
F_419 ( V_2 ) ;
F_420 ( V_2 ) ;
}
F_5 ( V_2 ) ;
}
static int F_421 ( struct V_20 * V_21 ,
struct V_22 * V_894 ,
T_4 * V_221 )
{
struct V_156 * V_53 = V_894 -> V_53 ;
T_1 V_895 , V_896 ;
T_1 V_897 , V_898 ;
if ( V_53 -> V_179 != V_899 )
return 0 ;
if ( ! F_422 ( V_53 ) )
return 0 ;
if ( F_423 ( V_53 ) ) {
int V_359 = F_424 ( V_53 , 0 , 0 , V_184 ) ;
if ( V_359 )
return V_359 ;
}
V_896 = V_900 ;
if ( V_894 -> V_204 == F_121 ( V_212 ) ) {
struct V_199 * V_901 = F_425 ( V_53 ) ;
V_901 -> V_902 = 0 ;
V_901 -> V_903 = 0 ;
F_426 ( V_53 ) -> V_903 = ~ F_427 ( V_901 -> V_904 ,
V_901 -> V_905 , 0 ,
V_217 ,
0 ) ;
V_896 |= V_906 ;
V_894 -> V_907 |= V_908 |
V_909 |
V_910 ;
} else if ( F_428 ( V_53 ) ) {
F_429 ( V_53 ) -> V_911 = 0 ;
F_426 ( V_53 ) -> V_903 =
~ F_430 ( & F_429 ( V_53 ) -> V_904 ,
& F_429 ( V_53 ) -> V_905 ,
0 , V_217 , 0 ) ;
V_894 -> V_907 |= V_908 |
V_909 ;
}
V_898 = F_431 ( V_53 ) ;
* V_221 = F_432 ( V_53 ) + V_898 ;
V_894 -> V_129 = F_125 ( V_53 ) -> V_129 ;
V_894 -> V_128 += ( V_894 -> V_129 - 1 ) * * V_221 ;
V_897 = V_898 << V_912 ;
V_897 |= F_125 ( V_53 ) -> V_222 << V_913 ;
V_895 = F_433 ( V_53 ) ;
V_895 |= F_434 ( V_53 ) << V_914 ;
V_895 |= V_894 -> V_907 & V_915 ;
F_435 ( V_21 , V_895 , 0 , V_896 ,
V_897 ) ;
return 1 ;
}
static void F_436 ( struct V_20 * V_21 ,
struct V_22 * V_894 )
{
struct V_156 * V_53 = V_894 -> V_53 ;
T_1 V_895 = 0 ;
T_1 V_897 = 0 ;
T_1 V_896 = 0 ;
if ( V_53 -> V_179 != V_899 ) {
if ( ! ( V_894 -> V_907 & V_916 ) &&
! ( V_894 -> V_907 & V_917 ) )
return;
} else {
T_4 V_918 = 0 ;
switch ( V_894 -> V_204 ) {
case F_121 ( V_212 ) :
V_895 |= F_433 ( V_53 ) ;
V_896 |= V_906 ;
V_918 = F_425 ( V_53 ) -> V_204 ;
break;
case F_121 ( V_214 ) :
V_895 |= F_433 ( V_53 ) ;
V_918 = F_429 ( V_53 ) -> V_205 ;
break;
default:
if ( F_71 ( F_437 () ) ) {
F_438 ( V_21 -> V_37 ,
L_118 ,
V_894 -> V_204 ) ;
}
break;
}
switch ( V_918 ) {
case V_217 :
V_896 |= V_900 ;
V_897 = F_431 ( V_53 ) <<
V_912 ;
break;
case V_919 :
V_896 |= V_920 ;
V_897 = sizeof( struct V_921 ) <<
V_912 ;
break;
case V_219 :
V_897 = sizeof( struct V_220 ) <<
V_912 ;
break;
default:
if ( F_71 ( F_437 () ) ) {
F_438 ( V_21 -> V_37 ,
L_119 ,
V_918 ) ;
}
break;
}
V_894 -> V_907 |= V_909 ;
}
V_895 |= F_434 ( V_53 ) << V_914 ;
V_895 |= V_894 -> V_907 & V_915 ;
F_435 ( V_21 , V_895 , 0 ,
V_896 , V_897 ) ;
}
static T_1 F_439 ( struct V_156 * V_53 , T_1 V_907 )
{
T_1 V_922 = V_923 |
V_924 |
V_925 ;
V_922 |= F_440 ( V_907 , V_916 ,
V_926 ) ;
V_922 |= F_440 ( V_907 , V_908 ,
V_927 ) ;
V_922 |= F_440 ( V_907 , V_928 ,
V_929 ) ;
V_922 ^= F_440 ( V_53 -> V_930 , 1 , V_925 ) ;
return V_922 ;
}
static void F_441 ( union V_24 * V_25 ,
T_1 V_907 , unsigned int V_931 )
{
T_1 V_932 = V_931 << V_933 ;
V_932 |= F_440 ( V_907 ,
V_909 ,
V_934 ) ;
V_932 |= F_440 ( V_907 ,
V_910 ,
V_935 ) ;
V_932 |= F_440 ( V_907 ,
V_917 ,
V_936 ) ;
V_25 -> V_190 . V_932 = F_70 ( V_932 ) ;
}
static void F_442 ( struct V_20 * V_21 ,
struct V_22 * V_894 ,
const T_4 V_221 )
{
struct V_156 * V_53 = V_894 -> V_53 ;
struct V_22 * V_23 ;
union V_24 * V_25 ;
struct V_242 * V_243 ;
T_7 V_45 ;
unsigned int V_248 , V_257 ;
T_1 V_907 = V_894 -> V_907 ;
T_1 V_922 = F_439 ( V_53 , V_907 ) ;
T_5 V_11 = V_21 -> V_44 ;
V_25 = F_35 ( V_21 , V_11 ) ;
F_441 ( V_25 , V_907 , V_53 -> V_46 - V_221 ) ;
V_257 = F_124 ( V_53 ) ;
V_248 = V_53 -> V_248 ;
#ifdef F_122
if ( V_907 & V_937 ) {
if ( V_248 < sizeof( struct V_276 ) ) {
V_257 -= sizeof( struct V_276 ) - V_248 ;
V_248 = 0 ;
} else {
V_248 -= sizeof( struct V_276 ) ;
}
}
#endif
V_45 = F_443 ( V_21 -> V_37 , V_53 -> V_56 , V_257 , V_83 ) ;
V_23 = V_894 ;
for ( V_243 = & F_125 ( V_53 ) -> V_244 [ 0 ] ; ; V_243 ++ ) {
if ( F_116 ( V_21 -> V_37 , V_45 ) )
goto V_938;
F_55 ( V_23 , V_46 , V_257 ) ;
F_444 ( V_23 , V_45 , V_45 ) ;
V_25 -> V_190 . V_939 = F_119 ( V_45 ) ;
while ( F_71 ( V_257 > V_940 ) ) {
V_25 -> V_190 . V_941 =
F_70 ( V_922 ^ V_940 ) ;
V_11 ++ ;
V_25 ++ ;
if ( V_11 == V_21 -> V_52 ) {
V_25 = F_35 ( V_21 , 0 ) ;
V_11 = 0 ;
}
V_25 -> V_190 . V_932 = 0 ;
V_45 += V_940 ;
V_257 -= V_940 ;
V_25 -> V_190 . V_939 = F_119 ( V_45 ) ;
}
if ( F_73 ( ! V_248 ) )
break;
V_25 -> V_190 . V_941 = F_70 ( V_922 ^ V_257 ) ;
V_11 ++ ;
V_25 ++ ;
if ( V_11 == V_21 -> V_52 ) {
V_25 = F_35 ( V_21 , 0 ) ;
V_11 = 0 ;
}
V_25 -> V_190 . V_932 = 0 ;
#ifdef F_122
V_257 = F_324 (unsigned int, data_len, skb_frag_size(frag)) ;
#else
V_257 = F_445 ( V_243 ) ;
#endif
V_248 -= V_257 ;
V_45 = F_446 ( V_21 -> V_37 , V_243 , 0 , V_257 ,
V_83 ) ;
V_23 = & V_21 -> V_42 [ V_11 ] ;
}
V_922 |= V_257 | V_942 ;
V_25 -> V_190 . V_941 = F_70 ( V_922 ) ;
F_447 ( F_81 ( V_21 ) , V_894 -> V_128 ) ;
V_894 -> V_48 = V_132 ;
F_109 () ;
V_894 -> V_47 = V_25 ;
V_11 ++ ;
if ( V_11 == V_21 -> V_52 )
V_11 = 0 ;
V_21 -> V_44 = V_11 ;
F_110 ( V_11 , V_21 -> V_109 ) ;
return;
V_938:
F_337 ( V_21 -> V_37 , L_120 ) ;
for (; ; ) {
V_23 = & V_21 -> V_42 [ V_11 ] ;
F_51 ( V_21 , V_23 ) ;
if ( V_23 == V_894 )
break;
if ( V_11 == 0 )
V_11 = V_21 -> V_52 ;
V_11 -- ;
}
V_21 -> V_44 = V_11 ;
}
static void F_448 ( struct V_20 * V_82 ,
struct V_22 * V_894 )
{
struct V_118 * V_119 = V_82 -> V_119 ;
union V_943 V_944 = { . V_945 = 0 } ;
union V_943 V_946 = { . V_945 = 0 } ;
union {
unsigned char * V_194 ;
struct V_199 * V_200 ;
struct V_201 * V_202 ;
} V_203 ;
struct V_218 * V_947 ;
T_8 V_948 ;
if ( ! V_119 )
return;
if ( ! V_82 -> V_378 )
return;
V_82 -> V_379 ++ ;
V_203 . V_194 = F_449 ( V_894 -> V_53 ) ;
if ( ( V_894 -> V_204 != F_121 ( V_214 ) ||
V_203 . V_202 -> V_205 != V_217 ) &&
( V_894 -> V_204 != F_121 ( V_212 ) ||
V_203 . V_200 -> V_204 != V_217 ) )
return;
V_947 = F_426 ( V_894 -> V_53 ) ;
if ( ! V_947 || V_947 -> V_949 )
return;
if ( ! V_947 -> V_950 && ( V_82 -> V_379 < V_82 -> V_378 ) )
return;
V_82 -> V_379 = 0 ;
V_948 = F_450 ( V_894 -> V_907 >> V_951 ) ;
V_944 . V_952 . V_948 = V_948 ;
if ( V_894 -> V_907 & ( V_953 | V_916 ) )
V_946 . V_954 . V_955 ^= V_947 -> V_956 ^ F_121 ( V_209 ) ;
else
V_946 . V_954 . V_955 ^= V_947 -> V_956 ^ V_894 -> V_204 ;
V_946 . V_954 . V_957 ^= V_947 -> V_958 ;
if ( V_894 -> V_204 == F_121 ( V_212 ) ) {
V_944 . V_952 . V_959 = V_960 ;
V_946 . V_961 ^= V_203 . V_200 -> V_904 ^ V_203 . V_200 -> V_905 ;
} else {
V_944 . V_952 . V_959 = V_962 ;
V_946 . V_961 ^= V_203 . V_202 -> V_904 . V_963 [ 0 ] ^
V_203 . V_202 -> V_904 . V_963 [ 1 ] ^
V_203 . V_202 -> V_904 . V_963 [ 2 ] ^
V_203 . V_202 -> V_904 . V_963 [ 3 ] ^
V_203 . V_202 -> V_905 . V_963 [ 0 ] ^
V_203 . V_202 -> V_905 . V_963 [ 1 ] ^
V_203 . V_202 -> V_905 . V_963 [ 2 ] ^
V_203 . V_202 -> V_905 . V_963 [ 3 ] ;
}
F_451 ( & V_119 -> V_2 -> V_8 ,
V_944 , V_946 , V_82 -> V_50 ) ;
}
static int F_452 ( struct V_20 * V_21 , T_5 V_257 )
{
F_78 ( V_21 -> V_18 , V_21 -> V_50 ) ;
F_85 () ;
if ( F_73 ( F_84 ( V_21 ) < V_257 ) )
return - V_690 ;
F_453 ( V_21 -> V_18 , V_21 -> V_50 ) ;
++ V_21 -> V_112 . V_135 ;
return 0 ;
}
static inline int F_454 ( struct V_20 * V_21 , T_5 V_257 )
{
if ( F_73 ( F_84 ( V_21 ) >= V_257 ) )
return 0 ;
return F_452 ( V_21 , V_257 ) ;
}
static T_5 F_455 ( struct V_17 * V_37 , struct V_156 * V_53 )
{
struct V_1 * V_2 ;
struct V_964 * V_965 ;
int V_966 ;
switch ( F_456 ( V_53 ) ) {
case F_121 ( V_215 ) :
case F_121 ( V_967 ) :
V_2 = F_63 ( V_37 ) ;
if ( V_2 -> V_101 & V_475 )
break;
default:
return F_457 ( V_37 , V_53 ) ;
}
V_965 = & V_2 -> V_393 [ V_968 ] ;
V_966 = F_458 ( V_53 ) ? F_459 ( V_53 ) :
F_460 () ;
while ( V_966 >= V_965 -> V_395 )
V_966 -= V_965 -> V_395 ;
return V_966 + V_965 -> V_969 ;
}
T_13 F_461 ( struct V_156 * V_53 ,
struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_22 * V_894 ;
int V_970 ;
T_1 V_907 = 0 ;
#if V_259 > V_940
unsigned short V_965 ;
#endif
T_5 V_52 = F_462 ( F_124 ( V_53 ) ) ;
T_8 V_204 = V_53 -> V_204 ;
T_4 V_221 = 0 ;
#if V_259 > V_940
for ( V_965 = 0 ; V_965 < F_125 ( V_53 ) -> V_263 ; V_965 ++ )
V_52 += F_462 ( F_125 ( V_53 ) -> V_244 [ V_965 ] . V_257 ) ;
#else
V_52 += F_125 ( V_53 ) -> V_263 ;
#endif
if ( F_454 ( V_21 , V_52 + 3 ) ) {
V_21 -> V_112 . V_716 ++ ;
return V_971 ;
}
V_894 = & V_21 -> V_42 [ V_21 -> V_44 ] ;
V_894 -> V_53 = V_53 ;
V_894 -> V_128 = V_53 -> V_46 ;
V_894 -> V_129 = 1 ;
if ( F_463 ( V_53 ) ) {
V_907 |= F_464 ( V_53 ) << V_951 ;
V_907 |= V_916 ;
} else if ( V_204 == F_121 ( V_209 ) ) {
struct V_197 * V_972 , V_973 ;
V_972 = F_465 ( V_53 , V_207 , sizeof( V_973 ) , & V_973 ) ;
if ( ! V_972 )
goto V_974;
V_204 = V_972 -> V_211 ;
V_907 |= F_466 ( V_972 -> V_975 ) <<
V_951 ;
V_907 |= V_953 ;
}
F_467 ( V_53 ) ;
if ( F_71 ( F_125 ( V_53 ) -> V_907 & V_976 ) ) {
F_125 ( V_53 ) -> V_907 |= V_977 ;
V_907 |= V_928 ;
V_2 -> V_978 = F_468 ( V_53 ) ;
V_2 -> V_979 = V_132 ;
F_4 ( & V_2 -> V_980 ) ;
}
#ifdef F_328
if ( V_2 -> V_101 & V_388 )
V_907 |= V_917 ;
#endif
if ( ( V_2 -> V_101 & V_102 ) &&
( ( V_907 & ( V_916 | V_953 ) ) ||
( V_53 -> V_981 != V_982 ) ) ) {
V_907 &= ~ V_983 ;
V_907 |= ( V_53 -> V_981 & 0x7 ) <<
V_984 ;
if ( V_907 & V_953 ) {
struct V_985 * V_972 ;
if ( F_423 ( V_53 ) &&
F_424 ( V_53 , 0 , 0 , V_184 ) )
goto V_974;
V_972 = (struct V_985 * ) V_53 -> V_56 ;
V_972 -> V_975 = F_450 ( V_907 >>
V_951 ) ;
} else {
V_907 |= V_916 ;
}
}
V_894 -> V_907 = V_907 ;
V_894 -> V_204 = V_204 ;
#ifdef F_122
if ( ( V_204 == F_121 ( V_215 ) ) &&
( V_21 -> V_18 -> V_157 & ( V_986 | V_987 ) ) ) {
V_970 = F_469 ( V_21 , V_894 , & V_221 ) ;
if ( V_970 < 0 )
goto V_974;
goto V_988;
}
#endif
V_970 = F_421 ( V_21 , V_894 , & V_221 ) ;
if ( V_970 < 0 )
goto V_974;
else if ( ! V_970 )
F_436 ( V_21 , V_894 ) ;
if ( F_2 ( V_350 , & V_21 -> V_4 ) )
F_448 ( V_21 , V_894 ) ;
#ifdef F_122
V_988:
#endif
F_442 ( V_21 , V_894 , V_221 ) ;
F_454 ( V_21 , V_989 ) ;
return V_990 ;
V_974:
F_52 ( V_894 -> V_53 ) ;
V_894 -> V_53 = NULL ;
return V_990 ;
}
static T_13 F_470 ( struct V_156 * V_53 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
struct V_20 * V_21 ;
if ( F_71 ( V_53 -> V_46 < 17 ) ) {
if ( F_149 ( V_53 , 17 - V_53 -> V_46 ) )
return V_990 ;
V_53 -> V_46 = 17 ;
F_471 ( V_53 , 17 ) ;
}
V_21 = V_2 -> V_21 [ V_53 -> V_991 ] ;
return F_461 ( V_53 , V_2 , V_21 ) ;
}
static int F_472 ( struct V_17 * V_18 , void * V_441 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_992 * V_512 = V_441 ;
if ( ! F_473 ( V_512 -> V_993 ) )
return - V_994 ;
memcpy ( V_18 -> V_995 , V_512 -> V_993 , V_18 -> V_996 ) ;
memcpy ( V_8 -> V_72 . V_512 , V_512 -> V_993 , V_18 -> V_996 ) ;
V_8 -> V_72 . V_313 . V_511 ( V_8 , 0 , V_8 -> V_72 . V_512 , F_230 ( 0 ) , V_513 ) ;
return 0 ;
}
static int
F_474 ( struct V_17 * V_18 , int V_997 , int V_998 , T_5 V_512 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
T_5 V_999 ;
int V_1000 ;
if ( V_997 != V_8 -> V_317 . V_1001 . V_997 )
return - V_688 ;
V_1000 = V_8 -> V_317 . V_313 . V_1002 ( V_8 , V_512 , V_998 , & V_999 ) ;
if ( ! V_1000 )
V_1000 = V_999 ;
return V_1000 ;
}
static int F_475 ( struct V_17 * V_18 , int V_997 , int V_998 ,
T_5 V_512 , T_5 V_999 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( V_997 != V_8 -> V_317 . V_1001 . V_997 )
return - V_688 ;
return V_8 -> V_317 . V_313 . V_1003 ( V_8 , V_512 , V_998 , V_999 ) ;
}
static int F_476 ( struct V_17 * V_18 , struct V_1004 * V_1005 , int V_1006 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
switch ( V_1006 ) {
case V_1007 :
return F_477 ( V_2 , V_1005 , V_1006 ) ;
default:
return F_478 ( & V_2 -> V_8 . V_317 . V_1001 , F_479 ( V_1005 ) , V_1006 ) ;
}
}
static int F_480 ( struct V_17 * V_37 )
{
int V_359 = 0 ;
struct V_1 * V_2 = F_63 ( V_37 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( F_473 ( V_8 -> V_72 . V_1008 ) ) {
F_363 () ;
V_359 = F_481 ( V_37 , V_8 -> V_72 . V_1008 , V_1009 ) ;
F_365 () ;
V_8 -> V_72 . V_313 . V_615 ( V_8 , F_230 ( 0 ) ) ;
}
return V_359 ;
}
static int F_482 ( struct V_17 * V_37 )
{
int V_359 = 0 ;
struct V_1 * V_2 = F_63 ( V_37 ) ;
struct V_1010 * V_72 = & V_2 -> V_8 . V_72 ;
if ( F_473 ( V_72 -> V_1008 ) ) {
F_363 () ;
V_359 = F_483 ( V_37 , V_72 -> V_1008 , V_1009 ) ;
F_365 () ;
}
return V_359 ;
}
static void F_484 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
int V_11 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
V_2 -> V_101 |= V_231 ;
if ( V_2 -> V_101 & V_367 ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_150 ; V_11 ++ )
F_189 ( 0 , V_2 -> V_119 [ V_11 ] ) ;
} else {
F_201 ( V_2 -> V_36 -> V_344 , V_18 ) ;
}
V_2 -> V_101 &= ~ V_231 ;
}
static struct V_1011 * F_485 ( struct V_17 * V_18 ,
struct V_1011 * V_86 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
int V_11 ;
F_486 () ;
for ( V_11 = 0 ; V_11 < V_2 -> V_57 ; V_11 ++ ) {
struct V_20 * V_82 = F_487 ( V_2 -> V_30 [ V_11 ] ) ;
T_2 V_131 , V_106 ;
unsigned int V_1012 ;
if ( V_82 ) {
do {
V_1012 = F_488 ( & V_82 -> V_130 ) ;
V_106 = V_82 -> V_86 . V_106 ;
V_131 = V_82 -> V_86 . V_131 ;
} while ( F_489 ( & V_82 -> V_130 , V_1012 ) );
V_86 -> V_721 += V_106 ;
V_86 -> V_720 += V_131 ;
}
}
for ( V_11 = 0 ; V_11 < V_2 -> V_41 ; V_11 ++ ) {
struct V_20 * V_82 = F_487 ( V_2 -> V_21 [ V_11 ] ) ;
T_2 V_131 , V_106 ;
unsigned int V_1012 ;
if ( V_82 ) {
do {
V_1012 = F_488 ( & V_82 -> V_130 ) ;
V_106 = V_82 -> V_86 . V_106 ;
V_131 = V_82 -> V_86 . V_131 ;
} while ( F_489 ( & V_82 -> V_130 , V_1012 ) );
V_86 -> V_723 += V_106 ;
V_86 -> V_722 += V_131 ;
}
}
F_490 () ;
V_86 -> V_830 = V_18 -> V_86 . V_830 ;
V_86 -> V_831 = V_18 -> V_86 . V_831 ;
V_86 -> V_833 = V_18 -> V_86 . V_833 ;
V_86 -> V_834 = V_18 -> V_86 . V_834 ;
V_86 -> V_835 = V_18 -> V_86 . V_835 ;
return V_86 ;
}
static void F_491 ( struct V_1 * V_2 , T_4 V_96 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_1013 , V_1014 ;
int V_11 ;
if ( V_8 -> V_72 . type == V_73 )
return;
V_1013 = F_11 ( V_8 , V_1015 ) ;
V_1014 = V_1013 ;
for ( V_11 = 0 ; V_11 < V_655 ; V_11 ++ ) {
T_4 V_1016 = V_1013 >> ( V_11 * V_1017 ) ;
if ( V_1016 > V_96 )
V_1013 &= ~ ( 0x7 << V_1017 ) ;
}
if ( V_1013 != V_1014 )
F_45 ( V_8 , V_1015 , V_1013 ) ;
return;
}
static void F_492 ( struct V_1 * V_2 )
{
struct V_17 * V_37 = V_2 -> V_18 ;
struct V_1018 * V_98 = & V_2 -> V_98 ;
struct V_1019 * V_1020 = V_2 -> V_540 ;
T_4 V_1021 ;
for ( V_1021 = 0 ; V_1021 < V_1022 ; V_1021 ++ ) {
T_4 V_96 = 0 ;
if ( V_2 -> V_536 & V_537 )
V_96 = F_493 ( V_98 , 0 , V_1021 ) ;
else if ( V_1020 )
V_96 = V_1020 -> V_541 [ V_1021 ] ;
F_494 ( V_37 , V_1021 , V_96 ) ;
}
}
int F_495 ( struct V_17 * V_37 , T_4 V_96 )
{
struct V_1 * V_2 = F_63 ( V_37 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( V_96 > V_2 -> V_98 . V_651 . V_652 ||
( V_8 -> V_72 . type == V_73 &&
V_96 < V_655 ) )
return - V_688 ;
if ( F_31 ( V_37 ) )
F_353 ( V_37 ) ;
F_370 ( V_2 ) ;
#ifdef F_285
if ( V_96 ) {
F_496 ( V_37 , V_96 ) ;
F_492 ( V_2 ) ;
V_2 -> V_101 |= V_102 ;
if ( V_2 -> V_8 . V_72 . type == V_73 ) {
V_2 -> V_1023 = V_2 -> V_8 . V_87 . V_667 ;
V_2 -> V_8 . V_87 . V_667 = V_1024 ;
}
} else {
F_497 ( V_37 ) ;
if ( V_2 -> V_8 . V_72 . type == V_73 )
V_2 -> V_8 . V_87 . V_667 = V_2 -> V_1023 ;
V_2 -> V_101 &= ~ V_102 ;
V_2 -> V_666 . V_99 = false ;
V_2 -> V_98 . V_99 = false ;
}
F_491 ( V_2 , V_96 ) ;
#endif
F_364 ( V_2 ) ;
if ( F_31 ( V_37 ) )
return F_349 ( V_37 ) ;
return 0 ;
}
void F_498 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
F_363 () ;
F_495 ( V_18 , F_214 ( V_18 ) ) ;
F_365 () ;
}
void F_499 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
if ( F_31 ( V_18 ) )
F_297 ( V_2 ) ;
else
F_303 ( V_2 ) ;
}
static T_14 F_500 ( struct V_17 * V_18 ,
T_14 V_157 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
if ( ! ( V_157 & V_170 ) )
V_157 &= ~ V_1025 ;
if ( ! ( V_2 -> V_115 & V_636 ) )
V_157 &= ~ V_1025 ;
return V_157 ;
}
static int F_501 ( struct V_17 * V_18 ,
T_14 V_157 )
{
struct V_1 * V_2 = F_63 ( V_18 ) ;
T_14 V_1026 = V_18 -> V_157 ^ V_157 ;
bool V_1027 = false ;
if ( ! ( V_157 & V_1025 ) ) {
if ( V_2 -> V_115 & V_483 )
V_1027 = true ;
V_2 -> V_115 &= ~ V_483 ;
} else if ( ( V_2 -> V_115 & V_636 ) &&
! ( V_2 -> V_115 & V_483 ) ) {
if ( V_2 -> V_357 == 1 ||
V_2 -> V_357 > V_1028 ) {
V_2 -> V_115 |= V_483 ;
V_1027 = true ;
} else if ( ( V_1026 ^ V_157 ) & V_1025 ) {
F_79 ( V_133 , L_121
L_122 ) ;
}
}
switch ( V_157 & V_1029 ) {
case V_1029 :
if ( ! ( V_2 -> V_101 & V_554 ) )
V_1027 = true ;
V_2 -> V_101 &= ~ V_341 ;
V_2 -> V_101 |= V_554 ;
break;
default:
if ( V_2 -> V_101 & V_554 )
V_1027 = true ;
V_2 -> V_101 &= ~ V_554 ;
if ( V_2 -> V_101 & V_388 )
break;
if ( F_214 ( V_18 ) > 1 )
break;
if ( V_2 -> V_393 [ V_394 ] . V_635 <= 1 )
break;
if ( ! V_2 -> V_378 )
break;
V_2 -> V_101 |= V_341 ;
break;
}
if ( V_157 & V_228 )
F_245 ( V_2 ) ;
else
F_244 ( V_2 ) ;
if ( V_1026 & V_251 )
V_1027 = true ;
V_18 -> V_157 = V_157 ;
if ( V_1027 )
F_499 ( V_18 ) ;
return 0 ;
}
static int F_502 ( struct V_1030 * V_1031 , struct V_1032 * V_1033 [] ,
struct V_17 * V_37 ,
const unsigned char * V_512 ,
T_5 V_101 )
{
struct V_1 * V_2 = F_63 ( V_37 ) ;
int V_359 ;
if ( ! ( V_2 -> V_101 & V_388 ) )
return - V_1034 ;
if ( V_1031 -> V_1035 && ! ( V_1031 -> V_1035 & V_1036 ) ) {
F_25 ( L_123 ,
V_1037 ) ;
return - V_688 ;
}
if ( F_503 ( V_512 ) || F_504 ( V_512 ) ) {
T_1 V_1038 = V_507 ;
if ( F_249 ( V_37 ) < V_1038 )
V_359 = F_505 ( V_37 , V_512 ) ;
else
V_359 = - V_508 ;
} else if ( F_506 ( V_512 ) ) {
V_359 = F_507 ( V_37 , V_512 ) ;
} else {
V_359 = - V_688 ;
}
if ( V_359 == - V_1039 && ! ( V_101 & V_1040 ) )
V_359 = 0 ;
return V_359 ;
}
static int F_508 ( struct V_1030 * V_1031 , struct V_1032 * V_1033 [] ,
struct V_17 * V_37 ,
const unsigned char * V_512 )
{
struct V_1 * V_2 = F_63 ( V_37 ) ;
int V_359 = - V_1034 ;
if ( V_1031 -> V_1035 & V_1036 ) {
F_25 ( L_123 ,
V_1037 ) ;
return - V_688 ;
}
if ( V_2 -> V_101 & V_388 ) {
if ( F_503 ( V_512 ) )
V_359 = F_509 ( V_37 , V_512 ) ;
else if ( F_506 ( V_512 ) )
V_359 = F_510 ( V_37 , V_512 ) ;
else
V_359 = - V_688 ;
}
return V_359 ;
}
static int F_511 ( struct V_156 * V_53 ,
struct V_1041 * V_1042 ,
struct V_17 * V_37 ,
int V_1043 )
{
struct V_1 * V_2 = F_63 ( V_37 ) ;
if ( V_2 -> V_101 & V_388 )
V_1043 = F_512 ( V_53 , V_1042 , V_37 , V_1043 ) ;
return V_1043 ;
}
static int F_513 ( struct V_17 * V_37 ,
struct V_1044 * V_1045 )
{
struct V_1 * V_2 = F_63 ( V_37 ) ;
struct V_1032 * V_1046 , * V_1047 ;
int V_1048 ;
if ( ! ( V_2 -> V_101 & V_388 ) )
return - V_1034 ;
V_1047 = F_514 ( V_1045 , sizeof( struct V_1049 ) , V_1050 ) ;
F_515 (attr, br_spec, rem) {
T_15 V_1051 ;
T_1 V_1013 = 0 ;
if ( F_516 ( V_1046 ) != V_1052 )
continue;
V_1051 = F_517 ( V_1046 ) ;
if ( V_1051 == V_1053 ) {
V_1013 = 0 ;
V_2 -> V_115 &= ~ V_457 ;
} else if ( V_1051 == V_1054 ) {
V_1013 = V_459 ;
V_2 -> V_115 |= V_457 ;
} else
return - V_688 ;
F_45 ( & V_2 -> V_8 , V_458 , V_1013 ) ;
F_79 ( V_117 , L_124 ,
V_1051 == V_1053 ? L_125 : L_126 ) ;
}
return 0 ;
}
static int F_518 ( struct V_156 * V_53 , T_1 V_1055 , T_1 V_1056 ,
struct V_17 * V_37 ,
T_1 V_1057 )
{
struct V_1 * V_2 = F_63 ( V_37 ) ;
T_5 V_1051 ;
if ( ! ( V_2 -> V_101 & V_388 ) )
return 0 ;
if ( V_2 -> V_115 & V_457 )
V_1051 = V_1054 ;
else
V_1051 = V_1053 ;
return F_519 ( V_53 , V_1055 , V_1056 , V_37 , V_1051 ) ;
}
int F_520 ( struct V_1 * V_2 , T_5 V_309 ,
T_5 V_1058 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_5 V_1059 = V_2 -> V_1060 & V_1061 ;
int V_1062 = 0 ;
switch ( V_309 ) {
case V_1063 :
switch ( V_1058 ) {
case V_1064 :
if ( V_8 -> V_1065 . V_1066 != 0 )
break;
case V_1067 :
case V_1068 :
case V_1069 :
V_1062 = 1 ;
break;
}
break;
case V_1070 :
if ( V_1058 != V_1071 )
V_1062 = 1 ;
break;
case V_1072 :
V_1062 = 1 ;
break;
case V_1073 :
case V_1074 :
if ( ( V_1059 == V_1075 ) ||
( ( V_1059 == V_1076 ) &&
( V_8 -> V_1065 . V_1066 == 0 ) ) ) {
V_1062 = 1 ;
}
break;
}
return V_1062 ;
}
static int F_521 ( struct V_622 * V_36 , const struct V_1077 * V_1078 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 = NULL ;
struct V_7 * V_8 ;
const struct V_1079 * V_1080 = V_1081 [ V_1078 -> V_1082 ] ;
static int V_1083 ;
int V_11 , V_359 , V_1084 ;
unsigned int V_395 = V_1085 ;
T_4 V_1086 [ V_1087 ] ;
#ifdef F_122
T_5 V_1088 ;
#endif
T_1 V_1089 ;
if ( V_36 -> V_1090 ) {
F_522 ( 1 , V_1091 L_127 ,
F_523 ( V_36 ) , V_36 -> V_627 , V_36 -> V_151 ) ;
return - V_688 ;
}
V_359 = F_360 ( V_36 ) ;
if ( V_359 )
return V_359 ;
if ( ! F_524 ( & V_36 -> V_37 , F_208 ( 64 ) ) &&
! F_525 ( & V_36 -> V_37 , F_208 ( 64 ) ) ) {
V_1084 = 1 ;
} else {
V_359 = F_524 ( & V_36 -> V_37 , F_208 ( 32 ) ) ;
if ( V_359 ) {
V_359 = F_525 ( & V_36 -> V_37 ,
F_208 ( 32 ) ) ;
if ( V_359 ) {
F_337 ( & V_36 -> V_37 ,
L_128 ) ;
goto V_1092;
}
}
V_1084 = 0 ;
}
V_359 = F_526 ( V_36 , F_527 ( V_36 ,
V_1093 ) , V_1037 ) ;
if ( V_359 ) {
F_337 ( & V_36 -> V_37 ,
L_129 , V_359 ) ;
goto V_1094;
}
F_528 ( V_36 ) ;
F_361 ( V_36 ) ;
F_359 ( V_36 ) ;
if ( V_1080 -> V_72 == V_73 ) {
#ifdef F_285
V_395 = 4 * V_655 ;
#else
V_395 = V_634 ;
#endif
}
V_18 = F_529 ( sizeof( struct V_1 ) , V_395 ) ;
if ( ! V_18 ) {
V_359 = - V_508 ;
goto V_1095;
}
F_530 ( V_18 , & V_36 -> V_37 ) ;
V_2 = F_63 ( V_18 ) ;
F_531 ( V_36 , V_2 ) ;
V_2 -> V_18 = V_18 ;
V_2 -> V_36 = V_36 ;
V_8 = & V_2 -> V_8 ;
V_8 -> V_1096 = V_2 ;
V_2 -> V_1097 = F_532 ( V_1098 , V_1099 ) ;
V_8 -> V_376 = F_533 ( F_534 ( V_36 , 0 ) ,
F_535 ( V_36 , 0 ) ) ;
if ( ! V_8 -> V_376 ) {
V_359 = - V_680 ;
goto V_1100;
}
V_18 -> V_1101 = & V_1102 ;
F_536 ( V_18 ) ;
V_18 -> V_1103 = 5 * V_889 ;
strncpy ( V_18 -> V_16 , F_523 ( V_36 ) , sizeof( V_18 -> V_16 ) - 1 ) ;
V_2 -> V_1104 = V_1083 ;
memcpy ( & V_8 -> V_72 . V_313 , V_1080 -> V_1105 , sizeof( V_8 -> V_72 . V_313 ) ) ;
V_8 -> V_72 . type = V_1080 -> V_72 ;
memcpy ( & V_8 -> V_1106 . V_313 , V_1080 -> V_1107 , sizeof( V_8 -> V_1106 . V_313 ) ) ;
V_1089 = F_11 ( V_8 , V_1108 ) ;
if ( ! ( V_1089 & ( 1 << 8 ) ) )
V_8 -> V_1106 . V_313 . V_190 = & V_1109 ;
memcpy ( & V_8 -> V_317 . V_313 , V_1080 -> V_1110 , sizeof( V_8 -> V_317 . V_313 ) ) ;
V_8 -> V_317 . V_875 = V_1111 ;
V_8 -> V_317 . V_1001 . V_997 = V_1112 ;
V_8 -> V_317 . V_1001 . V_1113 = 0 ;
V_8 -> V_317 . V_1001 . V_1114 = V_1115 | V_1116 ;
V_8 -> V_317 . V_1001 . V_37 = V_18 ;
V_8 -> V_317 . V_1001 . V_1117 = F_474 ;
V_8 -> V_317 . V_1001 . V_1118 = F_475 ;
V_1080 -> V_1119 ( V_8 ) ;
V_359 = F_323 ( V_2 ) ;
if ( V_359 )
goto V_1120;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
case V_76 :
F_45 ( & V_2 -> V_8 , V_694 , ~ 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_101 & V_320 ) {
T_1 V_602 = F_11 ( V_8 , V_603 ) ;
if ( V_602 & V_604 )
F_174 ( V_133 , L_60 ) ;
}
if ( V_1121 )
V_8 -> V_1121 = V_1121 ;
V_8 -> V_317 . V_1122 = true ;
V_359 = V_8 -> V_72 . V_313 . V_1123 ( V_8 ) ;
V_8 -> V_317 . V_1122 = false ;
if ( V_359 == V_610 &&
V_8 -> V_72 . type == V_73 ) {
V_359 = 0 ;
} else if ( V_359 == V_611 ) {
F_304 ( L_130
L_131 ) ;
F_304 ( L_132
L_133 ) ;
goto V_1120;
} else if ( V_359 ) {
F_304 ( L_134 , V_359 ) ;
goto V_1120;
}
#ifdef F_328
if ( V_2 -> V_8 . V_72 . type == V_73 )
goto V_1124;
F_537 ( V_8 ) ;
memcpy ( & V_8 -> V_1125 . V_313 , V_1080 -> V_1126 , sizeof( V_8 -> V_1125 . V_313 ) ) ;
F_538 ( V_2 ) ;
F_539 ( V_36 , 63 ) ;
V_1124:
#endif
V_18 -> V_157 = V_1127 |
V_1128 |
V_1129 |
V_1130 |
V_228 |
V_1131 |
V_1132 |
V_1133 |
V_158 |
V_170 ;
V_18 -> V_1134 = V_18 -> V_157 ;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
case V_76 :
V_18 -> V_157 |= V_1135 ;
V_18 -> V_1134 |= V_1135 |
V_1029 ;
break;
default:
break;
}
V_18 -> V_1134 |= V_251 ;
V_18 -> V_1136 |= V_1132 ;
V_18 -> V_1136 |= V_1133 ;
V_18 -> V_1136 |= V_1128 ;
V_18 -> V_1136 |= V_1129 ;
V_18 -> V_1136 |= V_1127 ;
V_18 -> V_1137 |= V_1138 ;
V_18 -> V_1137 |= V_1139 ;
#ifdef F_285
V_18 -> V_1140 = & V_1140 ;
#endif
#ifdef F_122
if ( V_2 -> V_101 & V_642 ) {
unsigned int V_1141 ;
if ( V_8 -> V_72 . V_313 . V_1142 ) {
V_8 -> V_72 . V_313 . V_1142 ( V_8 , & V_1088 ) ;
if ( V_1088 & V_1143 )
V_2 -> V_101 &= ~ V_642 ;
}
V_1141 = F_324 ( int , V_1144 , F_325 () ) ;
V_2 -> V_393 [ V_968 ] . V_635 = V_1141 ;
V_18 -> V_157 |= V_986 |
V_987 ;
V_18 -> V_1136 |= V_986 |
V_987 |
V_535 ;
}
#endif
if ( V_1084 ) {
V_18 -> V_157 |= V_1145 ;
V_18 -> V_1136 |= V_1145 ;
}
if ( V_2 -> V_115 & V_636 )
V_18 -> V_1134 |= V_1025 ;
if ( V_2 -> V_115 & V_483 )
V_18 -> V_157 |= V_1025 ;
if ( V_8 -> V_1106 . V_313 . V_1146 ( V_8 , NULL ) < 0 ) {
F_304 ( L_135 ) ;
V_359 = - V_680 ;
goto V_1120;
}
memcpy ( V_18 -> V_995 , V_8 -> V_72 . V_1147 , V_18 -> V_996 ) ;
if ( ! F_473 ( V_18 -> V_995 ) ) {
F_304 ( L_136 ) ;
V_359 = - V_680 ;
goto V_1120;
}
F_540 ( & V_2 -> V_605 , & F_416 ,
( unsigned long ) V_2 ) ;
F_541 ( & V_2 -> V_6 , F_418 ) ;
F_8 ( V_5 , & V_2 -> V_4 ) ;
V_359 = F_364 ( V_2 ) ;
if ( V_359 )
goto V_1120;
V_2 -> V_698 = 0 ;
V_8 -> V_1106 . V_313 . V_190 ( V_8 , 0x2c , & V_2 -> V_1060 ) ;
if ( F_520 ( V_2 , V_36 -> V_151 , V_36 -> V_633 ) )
V_2 -> V_698 = V_1148 ;
F_542 ( & V_2 -> V_36 -> V_37 , V_2 -> V_698 ) ;
V_8 -> V_1106 . V_313 . V_190 ( V_8 , 0x2e , & V_2 -> V_1149 ) ;
V_8 -> V_1106 . V_313 . V_190 ( V_8 , 0x2d , & V_2 -> V_1150 ) ;
V_8 -> V_72 . V_313 . V_1151 ( V_8 ) ;
F_543 ( L_137 ,
( V_8 -> V_1065 . V_315 == V_1152 ? L_138 :
V_8 -> V_1065 . V_315 == V_1153 ? L_139 :
L_140 ) ,
( V_8 -> V_1065 . V_1154 == V_1155 ? L_141 :
V_8 -> V_1065 . V_1154 == V_1156 ? L_142 :
V_8 -> V_1065 . V_1154 == V_1157 ? L_143 :
L_140 ) ,
V_18 -> V_995 ) ;
V_359 = F_544 ( V_8 , V_1086 , V_1087 ) ;
if ( V_359 )
strncpy ( V_1086 , L_140 , V_1087 ) ;
if ( F_289 ( V_8 ) && V_8 -> V_317 . V_875 != V_1158 )
F_543 ( L_144 ,
V_8 -> V_72 . type , V_8 -> V_317 . type , V_8 -> V_317 . V_875 ,
V_1086 ) ;
else
F_543 ( L_145 ,
V_8 -> V_72 . type , V_8 -> V_317 . type , V_1086 ) ;
if ( V_8 -> V_1065 . V_1154 <= V_1156 ) {
F_305 ( L_146
L_147 ) ;
F_305 ( L_148
L_149 ) ;
}
V_359 = V_8 -> V_72 . V_313 . V_1159 ( V_8 ) ;
if ( V_359 == V_613 ) {
F_305 ( L_82
L_150
L_151
L_152
L_86
L_87 ) ;
}
strcpy ( V_18 -> V_16 , L_153 ) ;
V_359 = F_545 ( V_18 ) ;
if ( V_359 )
goto V_1160;
if ( V_8 -> V_72 . V_313 . V_621 )
V_8 -> V_72 . V_313 . V_621 ( V_8 ) ;
F_316 ( V_18 ) ;
#ifdef F_193
if ( F_100 ( & V_36 -> V_37 ) == 0 ) {
V_2 -> V_101 |= V_148 ;
F_97 ( V_2 ) ;
}
#endif
if ( V_2 -> V_101 & V_388 ) {
F_79 ( V_133 , L_154 , V_2 -> V_279 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_279 ; V_11 ++ )
F_546 ( V_36 , ( V_11 | 0x10000000 ) ) ;
}
if ( V_8 -> V_72 . V_313 . V_1161 )
V_8 -> V_72 . V_313 . V_1161 ( V_8 , 0xFF , 0xFF , 0xFF ,
0xFF ) ;
F_480 ( V_18 ) ;
F_543 ( L_155 , V_1162 ) ;
V_1083 ++ ;
#ifdef F_547
if ( F_548 ( V_2 ) )
F_77 ( V_133 , L_156 ) ;
#endif
#ifdef F_549
F_550 ( V_2 ) ;
#endif
return 0 ;
V_1160:
F_44 ( V_2 ) ;
F_370 ( V_2 ) ;
V_1120:
F_551 ( V_2 ) ;
V_2 -> V_115 &= ~ V_579 ;
F_552 ( V_8 -> V_376 ) ;
V_1100:
F_553 ( V_18 ) ;
V_1095:
F_554 ( V_36 ,
F_527 ( V_36 , V_1093 ) ) ;
V_1094:
V_1092:
F_371 ( V_36 ) ;
return V_359 ;
}
static void F_555 ( struct V_622 * V_36 )
{
struct V_1 * V_2 = F_356 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
#ifdef F_549
F_556 ( V_2 ) ;
#endif
F_210 ( V_3 , & V_2 -> V_4 ) ;
F_557 ( & V_2 -> V_6 ) ;
#ifdef F_193
if ( V_2 -> V_101 & V_148 ) {
V_2 -> V_101 &= ~ V_148 ;
F_101 ( & V_36 -> V_37 ) ;
F_45 ( & V_2 -> V_8 , V_149 , 1 ) ;
}
#endif
#ifdef F_547
F_558 ( V_2 ) ;
#endif
F_482 ( V_18 ) ;
if ( V_18 -> V_876 == V_877 )
F_412 ( V_18 ) ;
#ifdef F_328
if ( V_672 )
F_551 ( V_2 ) ;
#endif
F_370 ( V_2 ) ;
F_44 ( V_2 ) ;
#ifdef F_559
F_200 ( V_2 -> V_100 ) ;
F_200 ( V_2 -> V_540 ) ;
#endif
F_552 ( V_2 -> V_8 . V_376 ) ;
F_554 ( V_36 , F_527 ( V_36 ,
V_1093 ) ) ;
F_543 ( L_157 ) ;
F_553 ( V_18 ) ;
F_560 ( V_36 ) ;
F_371 ( V_36 ) ;
}
static T_16 F_561 ( struct V_622 * V_36 ,
T_17 V_4 )
{
struct V_1 * V_2 = F_356 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
#ifdef F_328
struct V_622 * V_1163 , * V_1164 ;
T_1 V_1165 , V_1166 , V_1167 , V_1168 ;
int V_878 , V_1169 ;
T_5 V_1170 , V_1171 ;
if ( V_2 -> V_8 . V_72 . type == V_73 ||
V_2 -> V_279 == 0 )
goto V_1172;
V_1163 = V_36 -> V_1065 -> V_1173 ;
while ( V_1163 && ( F_562 ( V_1163 ) != V_1174 ) )
V_1163 = V_1163 -> V_1065 -> V_1173 ;
if ( ! V_1163 )
goto V_1172;
V_1169 = F_563 ( V_1163 , V_1175 ) ;
if ( ! V_1169 )
goto V_1172;
F_564 ( V_1163 , V_1169 + V_1176 , & V_1165 ) ;
F_564 ( V_1163 , V_1169 + V_1176 + 4 , & V_1166 ) ;
F_564 ( V_1163 , V_1169 + V_1176 + 8 , & V_1167 ) ;
F_564 ( V_1163 , V_1169 + V_1176 + 12 , & V_1168 ) ;
V_1170 = V_1166 >> 16 ;
if ( ! ( V_1170 & 0x0080 ) )
goto V_1172;
V_1171 = V_1170 & 0x01 ;
if ( ( V_1171 & 1 ) == ( V_36 -> V_1177 & 1 ) ) {
unsigned int V_309 ;
V_878 = ( V_1170 & 0x7F ) >> 1 ;
F_304 ( L_158 , V_878 ) ;
F_304 ( L_159
L_160 ,
V_1165 , V_1166 , V_1167 , V_1168 ) ;
switch ( V_2 -> V_8 . V_72 . type ) {
case V_75 :
V_309 = V_1178 ;
break;
case V_76 :
V_309 = V_1179 ;
break;
default:
V_309 = 0 ;
break;
}
V_1164 = F_565 ( V_1180 , V_309 , NULL ) ;
while ( V_1164 ) {
if ( V_1164 -> V_1177 == ( V_1170 & 0xFF ) )
break;
V_1164 = F_565 ( V_1180 ,
V_309 , V_1164 ) ;
}
if ( V_1164 ) {
F_304 ( L_161 , V_878 ) ;
F_566 ( V_1164 , 0xA8 , 0x00008000 ) ;
F_567 ( V_1164 ) ;
}
F_568 ( V_36 ) ;
}
V_2 -> V_1181 ++ ;
return V_1182 ;
V_1172:
#endif
F_369 ( V_18 ) ;
if ( V_4 == V_1183 )
return V_1184 ;
if ( F_31 ( V_18 ) )
F_300 ( V_2 ) ;
F_371 ( V_36 ) ;
return V_1185 ;
}
static T_16 F_569 ( struct V_622 * V_36 )
{
struct V_1 * V_2 = F_356 ( V_36 ) ;
T_16 V_1186 ;
int V_359 ;
if ( F_360 ( V_36 ) ) {
F_77 ( V_133 , L_162 ) ;
V_1186 = V_1184 ;
} else {
F_361 ( V_36 ) ;
F_358 ( V_36 ) ;
F_359 ( V_36 ) ;
F_362 ( V_36 , false ) ;
F_303 ( V_2 ) ;
F_45 ( & V_2 -> V_8 , V_694 , ~ 0 ) ;
V_1186 = V_1182 ;
}
V_359 = F_568 ( V_36 ) ;
if ( V_359 ) {
F_304 ( L_163
L_164 , V_359 ) ;
}
return V_1186 ;
}
static void F_570 ( struct V_622 * V_36 )
{
struct V_1 * V_2 = F_356 ( V_36 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
#ifdef F_328
if ( V_2 -> V_1181 ) {
F_79 ( V_117 , L_165 ) ;
V_2 -> V_1181 -- ;
return;
}
#endif
if ( F_31 ( V_18 ) )
F_302 ( V_2 ) ;
F_366 ( V_18 ) ;
}
static int T_18 F_571 ( void )
{
int V_114 ;
F_25 ( L_166 , V_1187 , V_1188 ) ;
F_25 ( L_155 , V_1189 ) ;
#ifdef F_549
F_572 () ;
#endif
V_114 = F_573 ( & V_1190 ) ;
if ( V_114 ) {
#ifdef F_549
F_574 () ;
#endif
return V_114 ;
}
#ifdef F_193
F_575 ( & V_1191 ) ;
#endif
return 0 ;
}
static void T_19 F_576 ( void )
{
#ifdef F_193
F_577 ( & V_1191 ) ;
#endif
F_578 ( & V_1190 ) ;
#ifdef F_549
F_574 () ;
#endif
F_579 () ;
}
static int F_580 ( struct V_1192 * V_1193 , unsigned long V_152 ,
void * V_441 )
{
int V_1194 ;
V_1194 = F_581 ( & V_1190 . V_1195 , NULL , & V_152 ,
F_98 ) ;
return V_1194 ? V_1196 : V_1197 ;
}
