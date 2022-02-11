static bool F_1 ( T_1 V_1 )
{
if ( V_1 >= F_2 ( V_2 ) )
return false ;
if ( V_2 [ V_1 ] . V_3 )
return true ;
return false ;
}
static bool F_3 ( T_1 V_1 , enum V_4 V_5 )
{
if ( V_1 >= F_2 ( V_2 ) )
return false ;
if ( V_5 < V_2 [ V_1 ] . V_6 )
return false ;
if ( V_2 [ V_1 ] . V_7 > 0 )
return true ;
return false ;
}
static int F_4 ( T_1 V_1 )
{
if ( V_1 >= F_2 ( V_2 ) )
return 0 ;
return V_2 [ V_1 ] . V_8 ;
}
static int F_5 ( T_1 V_1 , T_1 V_9 )
{
unsigned V_10 ;
if ( V_1 >= F_2 ( V_2 ) )
return 0 ;
V_10 = V_2 [ V_1 ] . V_7 ;
if ( V_10 == 0 )
return 0 ;
return ( V_9 + V_10 - 1 ) / V_10 ;
}
static int F_6 ( T_1 V_1 , T_1 V_11 )
{
unsigned V_12 ;
if ( V_1 >= F_2 ( V_2 ) )
return 0 ;
V_12 = V_2 [ V_1 ] . V_13 ;
if ( V_12 == 0 )
return 0 ;
return ( V_11 + V_12 - 1 ) / V_12 ;
}
static int F_7 ( struct V_14 * V_15 ,
T_1 * V_16 ,
T_1 * V_17 ,
T_1 * V_18 ,
T_2 * V_19 )
{
T_1 V_20 = 8 ;
T_1 V_21 = 8 ;
T_1 V_22 = V_15 -> V_23 ;
T_1 V_24 = V_15 -> V_25 ;
T_1 V_26 = V_20 * V_21 * V_15 -> V_8 * V_15 -> V_27 ;
T_1 V_28 = V_22 * V_24 * V_26 ;
switch ( V_15 -> V_29 ) {
case V_30 :
* V_16 = 1 ;
* V_17 = 1 ;
* V_18 = 1 ;
* V_19 = 1 ;
break;
case V_31 :
* V_16 = F_8 ( ( T_1 ) 64 , ( T_1 ) ( V_15 -> V_32 / V_15 -> V_8 ) ) ;
* V_17 = V_21 ;
* V_18 = 1 ;
* V_19 = V_15 -> V_32 ;
break;
case V_33 :
* V_16 = F_8 ( ( T_1 ) V_20 ,
( T_1 ) ( V_15 -> V_32 /
( V_21 * V_15 -> V_8 * V_15 -> V_27 ) ) ) ;
* V_17 = V_21 ;
* V_18 = 1 ;
* V_19 = V_15 -> V_32 ;
break;
case V_34 :
* V_16 = F_8 ( ( T_1 ) V_22 ,
( T_1 ) ( ( ( V_15 -> V_32 / V_21 ) /
( V_15 -> V_8 * V_15 -> V_27 ) ) *
V_15 -> V_23 ) ) * V_20 ;
* V_17 = V_24 * V_21 ;
* V_18 = 1 ;
* V_19 = F_8 ( V_28 ,
( * V_16 ) * V_15 -> V_8 * ( * V_17 ) * V_15 -> V_27 ) ;
break;
default:
return - V_35 ;
}
return 0 ;
}
static void F_9 ( struct V_36 * V_37 )
{
int V_38 ;
V_37 -> V_39 = V_40 ;
for ( V_38 = 0 ; V_38 < 8 ; V_38 ++ ) {
V_37 -> V_41 [ V_38 ] = 0 ;
V_37 -> V_42 [ V_38 ] = 0 ;
V_37 -> V_43 [ V_38 ] = 0 ;
V_37 -> V_44 [ V_38 ] = 0 ;
V_37 -> V_45 [ V_38 ] = NULL ;
V_37 -> V_46 [ V_38 ] = 0xFFFFFFFF ;
V_37 -> V_47 [ V_38 ] = 0xFFFFFFFF ;
}
V_37 -> V_48 = 0xFFFFFFFF ;
V_37 -> V_49 = 0xFFFFFFFF ;
V_37 -> V_50 = NULL ;
V_37 -> V_51 = 0xFFFFFFFF ;
V_37 -> V_52 = 7 | ( 1 << 25 ) ;
V_37 -> V_53 = 0xFFFFC000 ;
V_37 -> V_54 = 0xFFFFFFFF ;
V_37 -> V_55 = 0 ;
V_37 -> V_56 = 0xFFFFFFFF ;
}
static int F_10 ( struct V_57 * V_58 , int V_38 )
{
struct V_36 * V_37 = V_58 -> V_37 ;
T_1 V_59 , V_60 , V_61 ;
T_1 V_62 , V_17 , V_63 , V_16 , V_18 ;
T_2 V_64 , V_19 ;
struct V_14 V_65 ;
volatile T_1 * V_66 = V_58 -> V_66 -> V_67 ;
unsigned V_29 ;
T_1 V_1 ;
if ( F_11 ( V_37 -> V_44 [ V_38 ] ) ) {
F_12 ( V_58 -> V_68 , L_1 ) ;
return - V_35 ;
}
V_60 = F_13 ( V_37 -> V_45 [ V_38 ] ) - V_37 -> V_46 [ V_38 ] ;
V_1 = F_14 ( V_37 -> V_44 [ V_38 ] ) ;
if ( ! F_1 ( V_1 ) ) {
F_12 ( V_58 -> V_68 , L_2 ,
V_69 , __LINE__ , V_1 ,
V_38 , V_37 -> V_44 [ V_38 ] ) ;
return - V_35 ;
}
V_63 = ( F_15 ( V_37 -> V_42 [ V_38 ] ) + 1 ) * 8 ;
V_59 = F_16 ( V_37 -> V_42 [ V_38 ] ) + 1 ;
V_59 *= 64 ;
V_62 = V_59 / V_63 ;
if ( V_62 > 8192 )
V_62 = 8192 ;
V_29 = F_17 ( V_37 -> V_44 [ V_38 ] ) ;
V_64 = V_37 -> V_47 [ V_38 ] + V_37 -> V_46 [ V_38 ] ;
V_65 . V_29 = V_29 ;
V_65 . V_32 = V_37 -> V_32 ;
V_65 . V_23 = V_37 -> V_23 ;
V_65 . V_25 = V_37 -> V_25 ;
V_65 . V_27 = V_37 -> V_27 ;
V_65 . V_8 = F_4 ( V_1 ) ;
if ( F_7 ( & V_65 ,
& V_16 , & V_17 , & V_18 , & V_19 ) ) {
F_12 ( V_58 -> V_68 , L_3 , V_69 ,
F_17 ( V_37 -> V_44 [ V_38 ] ) , V_38 ,
V_37 -> V_44 [ V_38 ] ) ;
return - V_35 ;
}
switch ( V_29 ) {
case V_70 :
break;
case V_71 :
break;
case V_72 :
if ( V_62 > 7 )
V_62 &= ~ 0x7 ;
break;
case V_73 :
break;
default:
F_12 ( V_58 -> V_68 , L_3 , V_69 ,
F_17 ( V_37 -> V_44 [ V_38 ] ) , V_38 ,
V_37 -> V_44 [ V_38 ] ) ;
return - V_35 ;
}
if ( ! F_18 ( V_63 , V_16 ) ) {
F_12 ( V_58 -> V_68 , L_4 ,
V_69 , __LINE__ , V_63 , V_16 , V_29 ) ;
return - V_35 ;
}
if ( ! F_18 ( V_62 , V_17 ) ) {
F_12 ( V_58 -> V_68 , L_5 ,
V_69 , __LINE__ , V_62 , V_17 , V_29 ) ;
return - V_35 ;
}
if ( ! F_18 ( V_64 , V_19 ) ) {
F_12 ( V_58 -> V_68 , L_6 , V_69 , V_38 ,
V_64 , V_19 , V_29 ) ;
return - V_35 ;
}
V_61 = F_6 ( V_1 , V_62 ) * F_5 ( V_1 , V_63 ) * F_4 ( V_1 ) ;
if ( ( V_61 + V_37 -> V_46 [ V_38 ] ) > F_13 ( V_37 -> V_45 [ V_38 ] ) ) {
if ( V_29 == V_70 ) {
} else {
F_12 ( V_58 -> V_68 , L_7 , V_69 , V_38 ,
V_29 ,
V_37 -> V_46 [ V_38 ] , V_61 ,
F_13 ( V_37 -> V_45 [ V_38 ] ) ) ;
return - V_35 ;
}
}
V_61 = ( V_62 * V_63 ) >> 6 ;
if ( V_61 < V_59 )
V_59 = V_61 ;
V_61 = F_19 ( ( V_63 / 8 ) - 1 ) |
F_20 ( V_59 - 1 ) ;
V_66 [ V_37 -> V_43 [ V_38 ] ] = V_61 ;
return 0 ;
}
static int F_21 ( struct V_57 * V_58 )
{
struct V_36 * V_37 = V_58 -> V_37 ;
T_1 V_61 ;
int V_74 , V_38 ;
volatile T_1 * V_66 = V_58 -> V_66 -> V_67 ;
if ( V_58 -> V_75 == NULL )
return 0 ;
if ( V_37 -> V_76 || V_37 -> V_77 ) {
F_12 ( V_58 -> V_68 , L_8 ) ;
return - V_35 ;
}
V_61 = V_37 -> V_48 ;
for ( V_38 = 0 ; V_38 < 8 ; V_38 ++ ) {
if ( ( V_61 >> ( V_38 * 4 ) ) & 0xF ) {
if ( V_37 -> V_45 [ V_38 ] == NULL ) {
F_12 ( V_58 -> V_68 , L_9 ,
V_69 , __LINE__ , V_37 -> V_48 , V_37 -> V_49 , V_38 ) ;
return - V_35 ;
}
V_74 = F_10 ( V_58 , V_38 ) ;
if ( V_74 )
return V_74 ;
}
}
if ( F_22 ( V_37 -> V_56 ) ||
F_23 ( V_37 -> V_56 ) ) {
T_1 V_78 , V_79 , V_80 , V_60 , V_59 ;
T_1 V_62 , V_17 , V_63 , V_16 , V_18 ;
T_2 V_64 , V_19 ;
struct V_14 V_65 ;
int V_29 ;
if ( V_37 -> V_50 == NULL ) {
F_12 ( V_58 -> V_68 , L_10 ) ;
return - V_35 ;
}
if ( F_24 ( V_37 -> V_52 ) ) {
F_12 ( V_58 -> V_68 , L_11 ) ;
return - V_35 ;
}
switch ( F_25 ( V_37 -> V_52 ) ) {
case V_81 :
V_79 = 2 ;
break;
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
V_79 = 4 ;
break;
case V_87 :
V_79 = 8 ;
break;
default:
F_12 ( V_58 -> V_68 , L_12 , F_25 ( V_37 -> V_52 ) ) ;
return - V_35 ;
}
if ( ( V_37 -> V_54 & 0xFFFFFC00 ) == 0xFFFFFC00 ) {
if ( ! V_37 -> V_55 ) {
F_12 ( V_58 -> V_68 , L_13 ) ;
return - V_35 ;
}
V_61 = F_13 ( V_37 -> V_50 ) - V_37 -> V_88 ;
V_61 = ( V_61 / V_79 ) >> 6 ;
if ( ! V_61 ) {
F_12 ( V_58 -> V_68 , L_14 ,
V_37 -> V_54 , V_79 , V_37 -> V_88 ,
F_13 ( V_37 -> V_50 ) ) ;
return - V_35 ;
}
V_66 [ V_37 -> V_55 ] = F_26 ( V_61 - 1 ) | ( V_37 -> V_54 & 0x3FF ) ;
} else {
V_60 = F_13 ( V_37 -> V_50 ) ;
V_63 = ( F_27 ( V_37 -> V_54 ) + 1 ) * 8 ;
V_59 = F_28 ( V_37 -> V_54 ) + 1 ;
V_59 *= 64 ;
V_62 = V_59 / V_63 ;
if ( V_62 > 8192 )
V_62 = 8192 ;
V_64 = V_37 -> V_51 + V_37 -> V_88 ;
V_29 = F_29 ( V_37 -> V_52 ) ;
V_65 . V_29 = V_29 ;
V_65 . V_32 = V_37 -> V_32 ;
V_65 . V_23 = V_37 -> V_23 ;
V_65 . V_25 = V_37 -> V_25 ;
V_65 . V_27 = V_37 -> V_27 ;
V_65 . V_8 = V_79 ;
if ( F_7 ( & V_65 ,
& V_16 , & V_17 , & V_18 , & V_19 ) ) {
F_12 ( V_58 -> V_68 , L_15 , V_69 ,
F_29 ( V_37 -> V_52 ) ,
V_37 -> V_52 ) ;
return - V_35 ;
}
switch ( V_29 ) {
case V_89 :
V_62 &= ~ 0x7 ;
break;
case V_90 :
break;
default:
F_12 ( V_58 -> V_68 , L_15 , V_69 ,
F_29 ( V_37 -> V_52 ) ,
V_37 -> V_52 ) ;
return - V_35 ;
}
if ( ! F_18 ( V_63 , V_16 ) ) {
F_12 ( V_58 -> V_68 , L_16 ,
V_69 , __LINE__ , V_63 , V_16 , V_29 ) ;
return - V_35 ;
}
if ( ! F_18 ( V_62 , V_17 ) ) {
F_12 ( V_58 -> V_68 , L_17 ,
V_69 , __LINE__ , V_62 , V_17 , V_29 ) ;
return - V_35 ;
}
if ( ! F_18 ( V_64 , V_19 ) ) {
F_12 ( V_58 -> V_68 , L_18 , V_69 , V_38 ,
V_64 , V_19 , V_29 ) ;
return - V_35 ;
}
V_80 = F_28 ( V_37 -> V_54 ) + 1 ;
V_78 = F_30 ( V_37 -> V_53 ) + 1 ;
V_61 = V_80 * V_79 * 64 * V_78 ;
if ( ( V_61 + V_37 -> V_88 ) > F_13 ( V_37 -> V_50 ) ) {
F_12 ( V_58 -> V_68 , L_19 ,
V_29 ,
V_37 -> V_54 , V_80 , V_78 , V_79 , V_61 + V_37 -> V_88 ,
F_13 ( V_37 -> V_50 ) ) ;
return - V_35 ;
}
}
}
return 0 ;
}
int F_31 ( struct V_57 * V_58 ,
struct V_91 * V_92 ,
unsigned V_93 )
{
struct V_94 * V_95 = & V_58 -> V_96 [ V_58 -> V_97 ] ;
T_3 V_98 ;
if ( V_93 >= V_95 -> V_99 ) {
F_32 ( L_20 ,
V_93 , V_95 -> V_99 ) ;
return - V_35 ;
}
V_98 = F_33 ( V_58 , V_93 ) ;
V_92 -> V_93 = V_93 ;
V_92 -> type = F_34 ( V_98 ) ;
V_92 -> V_100 = F_35 ( V_98 ) ;
V_92 -> V_101 = 0 ;
switch ( V_92 -> type ) {
case V_102 :
V_92 -> V_103 = F_36 ( V_98 ) ;
break;
case V_104 :
V_92 -> V_105 = F_37 ( V_98 ) ;
break;
case V_106 :
V_92 -> V_100 = - 1 ;
break;
default:
F_32 ( L_21 , V_92 -> type , V_93 ) ;
return - V_35 ;
}
if ( ( V_92 -> V_100 + 1 + V_92 -> V_93 ) >= V_95 -> V_99 ) {
F_32 ( L_22 ,
V_92 -> V_93 , V_92 -> type , V_92 -> V_100 , V_95 -> V_99 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_38 ( struct V_57 * V_58 ,
struct V_107 * * V_108 )
{
struct V_94 * V_109 ;
struct V_91 V_110 ;
unsigned V_93 ;
int V_74 ;
if ( V_58 -> V_111 == - 1 ) {
F_32 ( L_23 ) ;
return - V_35 ;
}
* V_108 = NULL ;
V_109 = & V_58 -> V_96 [ V_58 -> V_111 ] ;
V_74 = F_31 ( V_58 , & V_110 , V_58 -> V_93 ) ;
if ( V_74 ) {
return V_74 ;
}
V_58 -> V_93 += V_110 . V_100 + 2 ;
if ( V_110 . type != V_104 || V_110 . V_105 != V_112 ) {
F_32 ( L_24 ,
V_110 . V_93 ) ;
return - V_35 ;
}
V_93 = F_33 ( V_58 , V_110 . V_93 + 1 ) ;
if ( V_93 >= V_109 -> V_99 ) {
F_32 ( L_25 ,
V_93 , V_109 -> V_99 ) ;
return - V_35 ;
}
* V_108 = V_58 -> V_113 [ ( V_93 / 4 ) ] ;
return 0 ;
}
static int F_39 ( struct V_57 * V_58 ,
struct V_107 * * V_108 )
{
struct V_94 * V_109 ;
struct V_91 V_110 ;
unsigned V_93 ;
int V_74 ;
if ( V_58 -> V_111 == - 1 ) {
F_32 ( L_23 ) ;
return - V_35 ;
}
* V_108 = NULL ;
V_109 = & V_58 -> V_96 [ V_58 -> V_111 ] ;
V_74 = F_31 ( V_58 , & V_110 , V_58 -> V_93 ) ;
if ( V_74 ) {
return V_74 ;
}
V_58 -> V_93 += V_110 . V_100 + 2 ;
if ( V_110 . type != V_104 || V_110 . V_105 != V_112 ) {
F_32 ( L_24 ,
V_110 . V_93 ) ;
return - V_35 ;
}
V_93 = F_33 ( V_58 , V_110 . V_93 + 1 ) ;
if ( V_93 >= V_109 -> V_99 ) {
F_32 ( L_25 ,
V_93 , V_109 -> V_99 ) ;
return - V_35 ;
}
* V_108 = V_58 -> V_114 ;
( * V_108 ) -> V_115 . V_116 = ( T_2 ) V_109 -> V_117 [ V_93 + 3 ] << 32 ;
( * V_108 ) -> V_115 . V_116 |= V_109 -> V_117 [ V_93 + 0 ] ;
return 0 ;
}
static int F_40 ( struct V_57 * V_58 )
{
struct V_91 V_110 ;
int V_74 ;
V_74 = F_31 ( V_58 , & V_110 , V_58 -> V_93 ) ;
if ( V_74 ) {
return 0 ;
}
if ( V_110 . type != V_104 || V_110 . V_105 != V_112 ) {
return 0 ;
}
return 1 ;
}
static int F_41 ( struct V_57 * V_58 )
{
struct V_118 * V_119 ;
struct V_120 * V_121 ;
struct V_122 * V_122 ;
struct V_91 V_110 , V_123 ;
int V_124 ;
int V_74 ;
T_3 V_98 , V_125 , V_103 , V_126 ;
volatile T_3 * V_66 ;
V_66 = V_58 -> V_66 -> V_67 ;
V_74 = F_31 ( V_58 , & V_123 , V_58 -> V_93 ) ;
if ( V_74 )
return V_74 ;
if ( V_123 . type != V_104 ||
V_123 . V_105 != V_127 ) {
F_32 ( L_26 ) ;
return - V_35 ;
}
V_126 = F_33 ( V_58 , V_123 . V_93 + 1 ) ;
if ( V_126 & 0x10 ) {
F_32 ( L_27 ) ;
return - V_35 ;
}
if ( ( V_126 & 0x7 ) != 0x3 ) {
F_32 ( L_28 ) ;
return - V_35 ;
}
if ( ( F_33 ( V_58 , V_123 . V_93 + 2 ) << 2 ) != V_128 ) {
F_32 ( L_29 ) ;
return - V_35 ;
}
if ( F_33 ( V_58 , V_123 . V_93 + 5 ) != V_129 ) {
F_32 ( L_30 ) ;
return - V_35 ;
}
V_74 = F_31 ( V_58 , & V_110 , V_58 -> V_93 + V_123 . V_100 + 2 ) ;
if ( V_74 )
return V_74 ;
V_125 = V_58 -> V_93 - 2 ;
V_58 -> V_93 += V_123 . V_100 + 2 ;
V_58 -> V_93 += V_110 . V_100 + 2 ;
V_98 = F_33 ( V_58 , V_125 ) ;
V_124 = F_33 ( V_58 , V_125 + 2 + 7 + 1 ) ;
V_103 = F_36 ( V_98 ) ;
V_119 = F_42 ( V_58 -> V_75 -> V_130 , V_124 , V_131 ) ;
if ( ! V_119 ) {
F_32 ( L_31 , V_124 ) ;
return - V_35 ;
}
V_121 = F_43 ( V_119 ) ;
V_122 = F_44 ( V_121 ) ;
V_124 = V_122 -> V_124 ;
if ( ! V_121 -> V_132 ) {
V_66 [ V_125 + 2 ] = F_45 ( 0 ) ;
V_66 [ V_125 + 3 ] = F_45 ( 0 ) ;
V_66 [ V_125 + 4 ] = F_45 ( 0 ) ;
V_66 [ V_125 + 5 ] = F_45 ( 0 ) ;
V_66 [ V_125 + 6 ] = F_45 ( 0 ) ;
V_66 [ V_125 + 7 ] = F_45 ( 0 ) ;
V_66 [ V_125 + 8 ] = F_45 ( 0 ) ;
} else if ( V_124 == 1 ) {
switch ( V_103 ) {
case V_133 :
V_98 &= ~ V_134 ;
V_98 |= V_135 >> 2 ;
break;
default:
F_32 ( L_32 ) ;
return - V_35 ;
}
V_66 [ V_125 ] = V_98 ;
V_66 [ V_125 + 4 ] = V_136 >> 2 ;
}
return 0 ;
}
static int F_46 ( struct V_57 * V_58 ,
struct V_91 * V_92 ,
unsigned V_93 , unsigned V_103 )
{
int V_74 ;
switch ( V_103 ) {
case V_133 :
V_74 = F_41 ( V_58 ) ;
if ( V_74 ) {
F_32 ( L_33 ,
V_93 , V_103 ) ;
return V_74 ;
}
break;
default:
F_47 ( V_137 L_34 ,
V_103 , V_93 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_48 ( struct V_57 * V_58 ,
struct V_91 * V_92 )
{
unsigned V_103 , V_38 ;
unsigned V_93 ;
int V_74 ;
V_93 = V_92 -> V_93 + 1 ;
V_103 = V_92 -> V_103 ;
for ( V_38 = 0 ; V_38 <= V_92 -> V_100 ; V_38 ++ , V_93 ++ , V_103 += 4 ) {
V_74 = F_46 ( V_58 , V_92 , V_93 , V_103 ) ;
if ( V_74 ) {
return V_74 ;
}
}
return 0 ;
}
static int F_49 ( struct V_57 * V_58 , T_1 V_103 , T_1 V_93 )
{
struct V_36 * V_37 = (struct V_36 * ) V_58 -> V_37 ;
struct V_107 * V_138 ;
T_1 V_139 , V_38 , V_61 , * V_66 ;
int V_74 ;
V_38 = ( V_103 >> 7 ) ;
if ( V_38 >= F_2 ( V_140 ) ) {
F_12 ( V_58 -> V_68 , L_35 , V_103 , V_93 ) ;
return - V_35 ;
}
V_139 = 1 << ( ( V_103 >> 2 ) & 31 ) ;
if ( ! ( V_140 [ V_38 ] & V_139 ) )
return 0 ;
V_66 = V_58 -> V_66 -> V_67 ;
switch ( V_103 ) {
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
V_61 = F_33 ( V_58 , V_93 ) ;
V_66 [ V_93 ] = 0 ;
break;
case V_158 :
V_37 -> V_39 = F_33 ( V_58 , V_93 ) ;
break;
case V_159 :
V_37 -> V_56 = F_33 ( V_58 , V_93 ) ;
break;
case V_160 :
if ( ! ( V_58 -> V_161 & V_162 ) &&
F_40 ( V_58 ) ) {
V_74 = F_50 ( V_58 , & V_138 ) ;
if ( V_74 ) {
F_12 ( V_58 -> V_68 , L_36
L_37 , V_103 ) ;
return - V_35 ;
}
V_37 -> V_52 = F_33 ( V_58 , V_93 ) ;
V_66 [ V_93 ] &= V_163 ;
V_37 -> V_52 &= V_163 ;
if ( V_138 -> V_115 . V_164 & V_165 ) {
V_66 [ V_93 ] |= F_51 ( V_90 ) ;
V_37 -> V_52 |= F_51 ( V_90 ) ;
} else {
V_66 [ V_93 ] |= F_51 ( V_89 ) ;
V_37 -> V_52 |= F_51 ( V_89 ) ;
}
} else
V_37 -> V_52 = F_33 ( V_58 , V_93 ) ;
break;
case V_166 :
V_37 -> V_53 = F_33 ( V_58 , V_93 ) ;
break;
case V_167 :
V_37 -> V_54 = F_33 ( V_58 , V_93 ) ;
V_37 -> V_55 = V_93 ;
break;
case V_168 :
V_37 -> V_76 = F_33 ( V_58 , V_93 ) ;
break;
case V_169 :
V_37 -> V_77 = F_33 ( V_58 , V_93 ) ;
break;
case V_170 :
V_37 -> V_48 = F_33 ( V_58 , V_93 ) ;
break;
case V_171 :
V_37 -> V_49 = F_33 ( V_58 , V_93 ) ;
break;
case V_172 :
V_61 = F_52 ( F_33 ( V_58 , V_93 ) ) ;
V_37 -> V_27 = 1 << V_61 ;
break;
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
if ( ! ( V_58 -> V_161 & V_162 ) &&
F_40 ( V_58 ) ) {
V_74 = F_50 ( V_58 , & V_138 ) ;
if ( V_74 ) {
F_53 ( V_58 -> V_68 , L_38 , V_103 ) ;
return - V_35 ;
}
V_61 = ( V_103 - V_173 ) / 4 ;
V_37 -> V_44 [ V_61 ] = F_33 ( V_58 , V_93 ) ;
if ( V_138 -> V_115 . V_164 & V_165 ) {
V_66 [ V_93 ] |= F_54 ( V_73 ) ;
V_37 -> V_44 [ V_61 ] |= F_54 ( V_73 ) ;
} else if ( V_138 -> V_115 . V_164 & V_181 ) {
V_66 [ V_93 ] |= F_54 ( V_72 ) ;
V_37 -> V_44 [ V_61 ] |= F_54 ( V_72 ) ;
}
} else {
V_61 = ( V_103 - V_173 ) / 4 ;
V_37 -> V_44 [ V_61 ] = F_33 ( V_58 , V_93 ) ;
}
break;
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
V_61 = ( V_103 - V_182 ) / 4 ;
V_37 -> V_42 [ V_61 ] = F_33 ( V_58 , V_93 ) ;
V_37 -> V_43 [ V_61 ] = V_93 ;
break;
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
V_61 = ( V_103 - V_190 ) / 4 ;
if ( ! F_40 ( V_58 ) ) {
if ( ! V_37 -> V_41 [ V_61 ] ) {
F_53 ( V_58 -> V_68 , L_39 , V_103 ) ;
return - V_35 ;
}
V_66 [ V_93 ] = V_37 -> V_41 [ V_61 ] ;
V_37 -> V_198 [ V_61 ] = V_37 -> V_45 [ V_61 ] ;
} else {
V_74 = F_50 ( V_58 , & V_138 ) ;
if ( V_74 ) {
F_53 ( V_58 -> V_68 , L_38 , V_103 ) ;
return - V_35 ;
}
V_66 [ V_93 ] += ( T_1 ) ( ( V_138 -> V_115 . V_116 >> 8 ) & 0xffffffff ) ;
V_37 -> V_198 [ V_61 ] = V_138 -> V_199 ;
}
break;
case V_200 :
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
V_61 = ( V_103 - V_200 ) / 4 ;
if ( ! F_40 ( V_58 ) ) {
if ( ! V_37 -> V_41 [ V_61 ] ) {
F_53 ( V_58 -> V_68 , L_39 , V_103 ) ;
return - V_35 ;
}
V_66 [ V_93 ] = V_37 -> V_41 [ V_61 ] ;
V_37 -> V_208 [ V_61 ] = V_37 -> V_45 [ V_61 ] ;
} else {
V_74 = F_50 ( V_58 , & V_138 ) ;
if ( V_74 ) {
F_53 ( V_58 -> V_68 , L_38 , V_103 ) ;
return - V_35 ;
}
V_66 [ V_93 ] += ( T_1 ) ( ( V_138 -> V_115 . V_116 >> 8 ) & 0xffffffff ) ;
V_37 -> V_208 [ V_61 ] = V_138 -> V_199 ;
}
break;
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
V_74 = F_50 ( V_58 , & V_138 ) ;
if ( V_74 ) {
F_12 ( V_58 -> V_68 , L_36
L_37 , V_103 ) ;
return - V_35 ;
}
V_61 = ( V_103 - V_209 ) / 4 ;
V_37 -> V_46 [ V_61 ] = F_33 ( V_58 , V_93 ) << 8 ;
V_66 [ V_93 ] += ( T_1 ) ( ( V_138 -> V_115 . V_116 >> 8 ) & 0xffffffff ) ;
V_37 -> V_41 [ V_61 ] = V_66 [ V_93 ] ;
V_37 -> V_45 [ V_61 ] = V_138 -> V_199 ;
V_37 -> V_47 [ V_61 ] = V_138 -> V_115 . V_116 ;
break;
case V_217 :
V_74 = F_50 ( V_58 , & V_138 ) ;
if ( V_74 ) {
F_12 ( V_58 -> V_68 , L_36
L_37 , V_103 ) ;
return - V_35 ;
}
V_37 -> V_88 = F_33 ( V_58 , V_93 ) << 8 ;
V_66 [ V_93 ] += ( T_1 ) ( ( V_138 -> V_115 . V_116 >> 8 ) & 0xffffffff ) ;
V_37 -> V_50 = V_138 -> V_199 ;
V_37 -> V_51 = V_138 -> V_115 . V_116 ;
break;
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
case V_271 :
V_74 = F_50 ( V_58 , & V_138 ) ;
if ( V_74 ) {
F_12 ( V_58 -> V_68 , L_36
L_37 , V_103 ) ;
return - V_35 ;
}
V_66 [ V_93 ] += ( T_1 ) ( ( V_138 -> V_115 . V_116 >> 8 ) & 0xffffffff ) ;
break;
case V_272 :
V_74 = F_50 ( V_58 , & V_138 ) ;
if ( V_74 ) {
F_12 ( V_58 -> V_68 , L_40
L_37 , V_103 ) ;
return - V_35 ;
}
V_66 [ V_93 ] += ( T_1 ) ( ( V_138 -> V_115 . V_116 >> 8 ) & 0xffffffff ) ;
break;
default:
F_12 ( V_58 -> V_68 , L_35 , V_103 , V_93 ) ;
return - V_35 ;
}
return 0 ;
}
static unsigned F_55 ( unsigned V_60 , unsigned V_273 )
{
unsigned V_274 ;
V_274 = F_8 ( 1U , V_60 >> V_273 ) ;
if ( V_273 > 0 )
V_274 = F_56 ( V_274 ) ;
return V_274 ;
}
static void F_57 ( unsigned V_275 , unsigned V_276 , unsigned V_277 ,
unsigned V_278 , unsigned V_279 , unsigned V_280 , unsigned V_1 ,
unsigned V_281 , unsigned V_17 , unsigned V_19 ,
unsigned * V_282 , unsigned * V_283 )
{
unsigned V_284 , V_38 , V_273 ;
unsigned V_285 , V_62 , V_286 , V_60 ;
unsigned V_8 ;
unsigned V_287 , V_288 ;
unsigned V_289 = V_277 - V_276 + 1 ;
* V_282 = - 1 ;
V_8 = F_4 ( V_1 ) ;
V_278 = F_55 ( V_278 , 0 ) ;
V_279 = F_55 ( V_279 , 0 ) ;
V_280 = F_55 ( V_280 , 0 ) ;
for( V_38 = 0 , V_284 = 0 , V_273 = V_276 ; V_38 < V_289 ; V_38 ++ , V_273 ++ ) {
V_285 = F_55 ( V_278 , V_38 ) ;
V_287 = F_5 ( V_1 , V_285 ) ;
V_287 = F_58 ( V_287 , V_281 ) ;
V_62 = F_55 ( V_279 , V_38 ) ;
V_288 = F_6 ( V_1 , V_62 ) ;
V_288 = F_58 ( V_288 , V_17 ) ;
V_286 = F_55 ( V_280 , V_38 ) ;
V_60 = V_287 * V_288 * V_8 ;
if ( V_275 )
V_60 *= V_275 ;
else
V_60 *= V_286 ;
if ( V_38 == 0 )
* V_282 = V_60 ;
if ( V_38 == 0 || V_38 == 1 )
V_284 = F_58 ( V_284 , V_19 ) ;
V_284 += V_60 ;
}
* V_283 = V_284 ;
if ( V_277 == 0 )
* V_283 = * V_282 ;
if ( ! V_276 )
* V_283 -= * V_282 ;
}
static int F_59 ( struct V_57 * V_58 , T_1 V_93 ,
struct V_290 * V_291 ,
struct V_290 * V_292 ,
T_2 V_64 ,
T_2 V_293 ,
T_1 V_164 )
{
struct V_36 * V_37 = V_58 -> V_37 ;
T_1 V_275 , V_277 , V_276 , V_278 , V_279 , V_280 ;
T_1 V_294 , V_295 , V_282 , V_283 , V_296 , V_297 ;
T_1 V_17 , V_63 , V_16 , V_18 ;
T_1 V_298 , V_299 , V_300 ;
T_2 V_19 ;
struct V_14 V_65 ;
T_1 V_1 ;
if ( V_58 -> V_75 == NULL )
return 0 ;
V_64 <<= 8 ;
V_293 <<= 8 ;
V_294 = F_33 ( V_58 , V_93 + 0 ) ;
if ( ! ( V_58 -> V_161 & V_162 ) ) {
if ( V_164 & V_165 )
V_294 |= F_60 ( V_301 ) ;
else if ( V_164 & V_181 )
V_294 |= F_60 ( V_302 ) ;
}
V_295 = F_33 ( V_58 , V_93 + 1 ) ;
V_278 = F_61 ( V_294 ) + 1 ;
V_279 = F_62 ( V_295 ) + 1 ;
V_280 = F_63 ( V_295 ) ;
V_275 = 1 ;
V_298 = 0 ;
switch ( F_64 ( V_294 ) ) {
case V_303 :
case V_304 :
case V_305 :
break;
case V_306 :
if ( V_58 -> V_5 >= V_307 )
V_275 = 8 ;
else
V_275 = 6 ;
break;
case V_308 :
case V_309 :
V_298 = 1 ;
break;
case V_310 :
case V_311 :
default:
F_12 ( V_58 -> V_68 , L_41 , F_64 ( V_294 ) ) ;
return - V_35 ;
}
V_1 = F_65 ( V_295 ) ;
if ( ! F_3 ( V_1 , V_58 -> V_5 ) ) {
F_12 ( V_58 -> V_68 , L_42 ,
V_69 , __LINE__ , V_1 ) ;
return - V_35 ;
}
V_63 = ( F_66 ( V_294 ) + 1 ) * 8 ;
V_65 . V_29 = F_67 ( V_294 ) ;
V_65 . V_32 = V_37 -> V_32 ;
V_65 . V_23 = V_37 -> V_23 ;
V_65 . V_25 = V_37 -> V_25 ;
V_65 . V_27 = 1 ;
V_65 . V_8 = F_4 ( V_1 ) ;
if ( F_7 ( & V_65 ,
& V_16 , & V_17 , & V_18 , & V_19 ) ) {
F_12 ( V_58 -> V_68 , L_43 ,
V_69 , __LINE__ , F_67 ( V_294 ) ) ;
return - V_35 ;
}
if ( ! F_18 ( V_63 , V_16 ) ) {
F_12 ( V_58 -> V_68 , L_44 ,
V_69 , __LINE__ , V_63 , V_16 , F_67 ( V_294 ) ) ;
return - V_35 ;
}
if ( ! F_18 ( V_64 , V_19 ) ) {
F_12 ( V_58 -> V_68 , L_45 ,
V_69 , __LINE__ , V_64 , V_19 , F_67 ( V_294 ) ) ;
return - V_35 ;
}
if ( ! F_18 ( V_293 , V_19 ) ) {
F_12 ( V_58 -> V_68 , L_46 ,
V_69 , __LINE__ , V_293 , V_19 , F_67 ( V_294 ) ) ;
return - V_35 ;
}
V_296 = F_33 ( V_58 , V_93 + 2 ) << 8 ;
V_297 = F_33 ( V_58 , V_93 + 3 ) << 8 ;
V_294 = F_33 ( V_58 , V_93 + 4 ) ;
V_295 = F_33 ( V_58 , V_93 + 5 ) ;
V_276 = F_68 ( V_294 ) ;
V_277 = F_69 ( V_295 ) ;
if ( V_298 == 1 ) {
V_299 = F_70 ( V_295 ) ;
V_300 = F_71 ( V_295 ) ;
V_275 = V_300 - V_299 + 1 ;
}
F_57 ( V_275 , V_276 , V_277 , V_278 , V_279 , V_280 , V_1 ,
V_16 , V_17 , V_19 ,
& V_282 , & V_283 ) ;
if ( ( V_282 + V_296 ) > F_13 ( V_291 ) ) {
F_12 ( V_58 -> V_68 , L_47 ,
V_278 , V_279 , V_1 , V_296 , V_282 , F_13 ( V_291 ) ) ;
F_12 ( V_58 -> V_68 , L_48 , V_63 , V_16 , V_17 , V_19 ) ;
return - V_35 ;
}
V_297 = F_33 ( V_58 , V_93 + 3 ) << 8 ;
if ( ( V_283 + V_297 ) > F_13 ( V_292 ) ) {
}
return 0 ;
}
static int F_72 ( struct V_57 * V_58 ,
struct V_91 * V_92 )
{
struct V_107 * V_138 ;
struct V_36 * V_37 ;
volatile T_1 * V_66 ;
unsigned V_93 ;
unsigned V_38 ;
unsigned V_312 , V_313 , V_103 ;
int V_74 ;
T_1 V_314 ;
V_37 = (struct V_36 * ) V_58 -> V_37 ;
V_66 = V_58 -> V_66 -> V_67 ;
V_93 = V_92 -> V_93 + 1 ;
V_314 = F_33 ( V_58 , V_93 ) ;
switch ( V_92 -> V_105 ) {
case V_315 :
{
int V_316 ;
int V_61 ;
if ( V_92 -> V_100 != 1 ) {
F_32 ( L_49 ) ;
return - V_35 ;
}
V_61 = F_33 ( V_58 , V_93 + 1 ) ;
V_316 = ( V_61 >> 16 ) & 0x7 ;
if ( V_316 == 0 )
return 0 ;
if ( V_316 > 2 ) {
F_32 ( L_50 , V_316 ) ;
return - V_35 ;
}
V_74 = F_50 ( V_58 , & V_138 ) ;
if ( V_74 ) {
F_32 ( L_49 ) ;
return - V_35 ;
}
V_66 [ V_93 + 0 ] = V_314 + ( T_1 ) ( V_138 -> V_115 . V_116 & 0xffffffff ) ;
V_66 [ V_93 + 1 ] = V_61 + ( F_73 ( V_138 -> V_115 . V_116 ) & 0xff ) ;
}
break;
case V_317 :
if ( V_58 -> V_5 >= V_307 || V_92 -> V_100 ) {
F_32 ( L_51 ) ;
return - V_35 ;
}
break;
case V_318 :
if ( V_92 -> V_100 != 1 ) {
F_32 ( L_52 ) ;
return - V_35 ;
}
break;
case V_319 :
case V_320 :
if ( V_92 -> V_100 ) {
F_32 ( L_53 ) ;
return - V_35 ;
}
break;
case V_321 :
if ( V_92 -> V_100 != 3 ) {
F_32 ( L_54 ) ;
return - V_35 ;
}
V_74 = F_50 ( V_58 , & V_138 ) ;
if ( V_74 ) {
F_32 ( L_54 ) ;
return - V_35 ;
}
V_66 [ V_93 + 0 ] = V_314 + ( T_1 ) ( V_138 -> V_115 . V_116 & 0xffffffff ) ;
V_66 [ V_93 + 1 ] += F_73 ( V_138 -> V_115 . V_116 ) & 0xff ;
V_74 = F_21 ( V_58 ) ;
if ( V_74 ) {
F_12 ( V_58 -> V_68 , L_55 , V_69 , __LINE__ ) ;
return V_74 ;
}
break;
case V_322 :
if ( V_92 -> V_100 != 1 ) {
F_32 ( L_56 ) ;
return - V_35 ;
}
V_74 = F_21 ( V_58 ) ;
if ( V_74 ) {
F_12 ( V_58 -> V_68 , L_57 , V_69 , __LINE__ , V_93 ) ;
return V_74 ;
}
break;
case V_323 :
case V_324 :
if ( V_92 -> V_100 < 2 ) {
F_32 ( L_58 ) ;
return - V_35 ;
}
V_74 = F_21 ( V_58 ) ;
if ( V_74 ) {
F_12 ( V_58 -> V_68 , L_55 , V_69 , __LINE__ ) ;
return V_74 ;
}
break;
case V_127 :
if ( V_92 -> V_100 != 5 ) {
F_32 ( L_59 ) ;
return - V_35 ;
}
if ( V_314 & 0x10 ) {
V_74 = F_50 ( V_58 , & V_138 ) ;
if ( V_74 ) {
F_32 ( L_59 ) ;
return - V_35 ;
}
V_66 [ V_93 + 1 ] += ( T_1 ) ( V_138 -> V_115 . V_116 & 0xffffffff ) ;
V_66 [ V_93 + 2 ] += F_73 ( V_138 -> V_115 . V_116 ) & 0xff ;
}
break;
case V_325 :
if ( V_92 -> V_100 != 3 ) {
F_32 ( L_60 ) ;
return - V_35 ;
}
if ( F_33 ( V_58 , V_93 + 1 ) != 0xffffffff ||
F_33 ( V_58 , V_93 + 2 ) != 0 ) {
V_74 = F_50 ( V_58 , & V_138 ) ;
if ( V_74 ) {
F_32 ( L_60 ) ;
return - V_35 ;
}
V_66 [ V_93 + 2 ] += ( T_1 ) ( ( V_138 -> V_115 . V_116 >> 8 ) & 0xffffffff ) ;
}
break;
case V_326 :
if ( V_92 -> V_100 != 2 && V_92 -> V_100 != 0 ) {
F_32 ( L_61 ) ;
return - V_35 ;
}
if ( V_92 -> V_100 ) {
V_74 = F_50 ( V_58 , & V_138 ) ;
if ( V_74 ) {
F_32 ( L_61 ) ;
return - V_35 ;
}
V_66 [ V_93 + 1 ] += ( T_1 ) ( V_138 -> V_115 . V_116 & 0xffffffff ) ;
V_66 [ V_93 + 2 ] += F_73 ( V_138 -> V_115 . V_116 ) & 0xff ;
}
break;
case V_327 :
if ( V_92 -> V_100 != 4 ) {
F_32 ( L_62 ) ;
return - V_35 ;
}
V_74 = F_50 ( V_58 , & V_138 ) ;
if ( V_74 ) {
F_32 ( L_61 ) ;
return - V_35 ;
}
V_66 [ V_93 + 1 ] += ( T_1 ) ( V_138 -> V_115 . V_116 & 0xffffffff ) ;
V_66 [ V_93 + 2 ] += F_73 ( V_138 -> V_115 . V_116 ) & 0xff ;
break;
case V_328 :
V_312 = ( V_314 << 2 ) + V_329 ;
V_313 = 4 * V_92 -> V_100 + V_312 - 4 ;
if ( ( V_312 < V_329 ) ||
( V_312 >= V_330 ) ||
( V_313 >= V_330 ) ) {
F_32 ( L_63 ) ;
return - V_35 ;
}
for ( V_38 = 0 ; V_38 < V_92 -> V_100 ; V_38 ++ ) {
V_103 = V_312 + ( 4 * V_38 ) ;
V_74 = F_49 ( V_58 , V_103 , V_93 + 1 + V_38 ) ;
if ( V_74 )
return V_74 ;
}
break;
case V_331 :
V_312 = ( V_314 << 2 ) + V_332 ;
V_313 = 4 * V_92 -> V_100 + V_312 - 4 ;
if ( ( V_312 < V_332 ) ||
( V_312 >= V_333 ) ||
( V_313 >= V_333 ) ) {
F_32 ( L_64 ) ;
return - V_35 ;
}
for ( V_38 = 0 ; V_38 < V_92 -> V_100 ; V_38 ++ ) {
V_103 = V_312 + ( 4 * V_38 ) ;
V_74 = F_49 ( V_58 , V_103 , V_93 + 1 + V_38 ) ;
if ( V_74 )
return V_74 ;
}
break;
case V_334 :
if ( V_92 -> V_100 % 7 ) {
F_32 ( L_65 ) ;
return - V_35 ;
}
V_312 = ( V_314 << 2 ) + V_335 ;
V_313 = 4 * V_92 -> V_100 + V_312 - 4 ;
if ( ( V_312 < V_335 ) ||
( V_312 >= V_336 ) ||
( V_313 >= V_336 ) ) {
F_32 ( L_65 ) ;
return - V_35 ;
}
for ( V_38 = 0 ; V_38 < ( V_92 -> V_100 / 7 ) ; V_38 ++ ) {
struct V_290 * V_291 , * V_292 ;
T_1 V_60 , V_284 , V_64 , V_293 ;
switch ( F_74 ( F_33 ( V_58 , V_93 + ( V_38 * 7 ) + 6 + 1 ) ) ) {
case V_337 :
V_74 = F_50 ( V_58 , & V_138 ) ;
if ( V_74 ) {
F_32 ( L_65 ) ;
return - V_35 ;
}
V_64 = ( T_1 ) ( ( V_138 -> V_115 . V_116 >> 8 ) & 0xffffffff ) ;
if ( ! ( V_58 -> V_161 & V_162 ) ) {
if ( V_138 -> V_115 . V_164 & V_165 )
V_66 [ V_93 + 1 + ( V_38 * 7 ) + 0 ] |= F_60 ( V_301 ) ;
else if ( V_138 -> V_115 . V_164 & V_181 )
V_66 [ V_93 + 1 + ( V_38 * 7 ) + 0 ] |= F_60 ( V_302 ) ;
}
V_291 = V_138 -> V_199 ;
V_74 = F_50 ( V_58 , & V_138 ) ;
if ( V_74 ) {
F_32 ( L_65 ) ;
return - V_35 ;
}
V_293 = ( T_1 ) ( ( V_138 -> V_115 . V_116 >> 8 ) & 0xffffffff ) ;
V_292 = V_138 -> V_199 ;
V_74 = F_59 ( V_58 , V_93 + ( V_38 * 7 ) + 1 ,
V_291 , V_292 ,
V_64 + F_33 ( V_58 , V_93 + 1 + ( V_38 * 7 ) + 2 ) ,
V_293 + F_33 ( V_58 , V_93 + 1 + ( V_38 * 7 ) + 3 ) ,
V_138 -> V_115 . V_164 ) ;
if ( V_74 )
return V_74 ;
V_66 [ V_93 + 1 + ( V_38 * 7 ) + 2 ] += V_64 ;
V_66 [ V_93 + 1 + ( V_38 * 7 ) + 3 ] += V_293 ;
break;
case V_338 :
V_74 = F_50 ( V_58 , & V_138 ) ;
if ( V_74 ) {
F_32 ( L_65 ) ;
return - V_35 ;
}
V_284 = F_33 ( V_58 , V_93 + 1 + ( V_38 * 7 ) + 0 ) ;
V_60 = F_33 ( V_58 , V_93 + 1 + ( V_38 * 7 ) + 1 ) + 1 ;
if ( V_58 -> V_75 && ( V_60 + V_284 ) > F_13 ( V_138 -> V_199 ) ) {
F_12 ( V_58 -> V_68 , L_66 ,
V_60 + V_284 , F_13 ( V_138 -> V_199 ) ) ;
V_66 [ V_93 + 1 + ( V_38 * 7 ) + 1 ] = F_13 ( V_138 -> V_199 ) ;
}
V_66 [ V_93 + 1 + ( V_38 * 7 ) + 0 ] += ( T_1 ) ( ( V_138 -> V_115 . V_116 ) & 0xffffffff ) ;
V_66 [ V_93 + 1 + ( V_38 * 7 ) + 2 ] += F_73 ( V_138 -> V_115 . V_116 ) & 0xff ;
break;
case V_339 :
case V_340 :
default:
F_32 ( L_65 ) ;
return - V_35 ;
}
}
break;
case V_341 :
if ( V_37 -> V_39 & V_40 ) {
V_312 = ( V_314 << 2 ) + V_342 ;
V_313 = 4 * V_92 -> V_100 + V_312 - 4 ;
if ( ( V_312 < V_342 ) ||
( V_312 >= V_343 ) ||
( V_313 >= V_343 ) ) {
F_32 ( L_67 ) ;
return - V_35 ;
}
}
break;
case V_344 :
V_312 = ( V_314 << 2 ) + V_345 ;
V_313 = 4 * V_92 -> V_100 + V_312 - 4 ;
if ( ( V_312 < V_345 ) ||
( V_312 >= V_346 ) ||
( V_313 >= V_346 ) ) {
F_32 ( L_68 ) ;
return - V_35 ;
}
break;
case V_347 :
V_312 = ( V_314 << 2 ) + V_348 ;
V_313 = 4 * V_92 -> V_100 + V_312 - 4 ;
if ( ( V_312 < V_348 ) ||
( V_312 >= V_349 ) ||
( V_313 >= V_349 ) ) {
F_32 ( L_69 ) ;
return - V_35 ;
}
break;
case V_350 :
V_312 = ( V_314 << 2 ) + V_351 ;
V_313 = 4 * V_92 -> V_100 + V_312 - 4 ;
if ( ( V_312 < V_351 ) ||
( V_312 >= V_352 ) ||
( V_313 >= V_352 ) ) {
F_32 ( L_70 ) ;
return - V_35 ;
}
break;
case V_353 :
if ( V_92 -> V_100 % 3 ) {
F_32 ( L_71 ) ;
return - V_35 ;
}
V_312 = ( V_314 << 2 ) + V_354 ;
V_313 = 4 * V_92 -> V_100 + V_312 - 4 ;
if ( ( V_312 < V_354 ) ||
( V_312 >= V_355 ) ||
( V_313 >= V_355 ) ) {
F_32 ( L_71 ) ;
return - V_35 ;
}
break;
case V_356 :
if ( V_58 -> V_5 >= V_307 || V_58 -> V_5 == V_357 ) {
F_32 ( L_72 ) ;
return - V_35 ;
}
if ( V_92 -> V_100 ) {
F_32 ( L_72 ) ;
return - V_35 ;
}
break;
case V_112 :
break;
default:
F_32 ( L_73 , V_92 -> V_105 ) ;
return - V_35 ;
}
return 0 ;
}
int F_75 ( struct V_57 * V_58 )
{
struct V_91 V_92 ;
struct V_36 * V_37 ;
int V_74 ;
if ( V_58 -> V_37 == NULL ) {
V_37 = F_76 ( sizeof( * V_37 ) , V_358 ) ;
if ( V_37 == NULL )
return - V_359 ;
F_9 ( V_37 ) ;
if ( V_58 -> V_75 -> V_5 < V_307 ) {
V_37 -> V_25 = V_58 -> V_75 -> V_360 . V_361 . V_362 ;
V_37 -> V_23 = V_58 -> V_75 -> V_360 . V_361 . V_363 ;
V_37 -> V_32 = V_58 -> V_75 -> V_360 . V_361 . V_364 ;
} else if ( V_58 -> V_75 -> V_5 <= V_365 ) {
V_37 -> V_25 = V_58 -> V_75 -> V_360 . V_366 . V_362 ;
V_37 -> V_23 = V_58 -> V_75 -> V_360 . V_366 . V_363 ;
V_37 -> V_32 = V_58 -> V_75 -> V_360 . V_366 . V_364 ;
}
V_58 -> V_37 = V_37 ;
}
do {
V_74 = F_31 ( V_58 , & V_92 , V_58 -> V_93 ) ;
if ( V_74 ) {
F_77 ( V_58 -> V_37 ) ;
V_58 -> V_37 = NULL ;
return V_74 ;
}
V_58 -> V_93 += V_92 . V_100 + 2 ;
switch ( V_92 . type ) {
case V_102 :
V_74 = F_48 ( V_58 , & V_92 ) ;
break;
case V_106 :
break;
case V_104 :
V_74 = F_72 ( V_58 , & V_92 ) ;
break;
default:
F_32 ( L_74 , V_92 . type ) ;
F_77 ( V_58 -> V_37 ) ;
V_58 -> V_37 = NULL ;
return - V_35 ;
}
if ( V_74 ) {
F_77 ( V_58 -> V_37 ) ;
V_58 -> V_37 = NULL ;
return V_74 ;
}
} while ( V_58 -> V_93 < V_58 -> V_96 [ V_58 -> V_97 ] . V_99 );
#if 0
for (r = 0; r < p->ib->length_dw; r++) {
printk(KERN_INFO "%05d 0x%08X\n", r, p->ib->ptr[r]);
mdelay(1);
}
#endif
F_77 ( V_58 -> V_37 ) ;
V_58 -> V_37 = NULL ;
return 0 ;
}
static int F_78 ( struct V_57 * V_58 )
{
if ( V_58 -> V_111 == - 1 ) {
return 0 ;
}
V_58 -> V_114 = F_76 ( sizeof( struct V_107 ) , V_358 ) ;
if ( V_58 -> V_114 == NULL ) {
return - V_359 ;
}
return 0 ;
}
static void F_79 ( struct V_57 * V_367 , int error )
{
unsigned V_38 ;
F_77 ( V_367 -> V_114 ) ;
for ( V_38 = 0 ; V_38 < V_367 -> V_368 ; V_38 ++ ) {
F_77 ( V_367 -> V_96 [ V_38 ] . V_117 ) ;
F_77 ( V_367 -> V_96 [ V_38 ] . V_369 [ 0 ] ) ;
F_77 ( V_367 -> V_96 [ V_38 ] . V_369 [ 1 ] ) ;
}
F_77 ( V_367 -> V_96 ) ;
F_77 ( V_367 -> V_370 ) ;
}
int F_80 ( struct V_371 * V_68 , void * V_372 , struct V_373 * V_374 ,
unsigned V_5 , T_1 * V_66 , int * V_375 )
{
struct V_57 V_367 ;
struct V_94 * V_95 ;
struct V_376 V_377 ;
struct V_36 * V_37 ;
int V_74 ;
V_37 = F_76 ( sizeof( * V_37 ) , V_358 ) ;
if ( V_37 == NULL )
return - V_359 ;
F_9 ( V_37 ) ;
F_81 ( V_68 , & V_37 -> V_25 , & V_37 -> V_23 , & V_37 -> V_32 ) ;
memset ( & V_367 , 0 , sizeof( struct V_57 ) ) ;
V_367 . V_374 = V_374 ;
V_367 . V_68 = & V_68 -> V_378 -> V_68 ;
V_367 . V_75 = NULL ;
V_367 . V_5 = V_5 ;
V_367 . V_66 = & V_377 ;
V_367 . V_37 = V_37 ;
V_377 . V_67 = V_66 ;
V_74 = F_82 ( & V_367 , V_372 ) ;
if ( V_74 ) {
F_32 ( L_75 ) ;
F_79 ( & V_367 , V_74 ) ;
return V_74 ;
}
V_74 = F_78 ( & V_367 ) ;
if ( V_74 ) {
F_32 ( L_76 ) ;
F_79 ( & V_367 , V_74 ) ;
return V_74 ;
}
V_95 = & V_367 . V_96 [ V_367 . V_97 ] ;
V_367 . V_66 -> V_99 = V_95 -> V_99 ;
* V_375 = V_367 . V_66 -> V_99 ;
V_74 = F_75 ( & V_367 ) ;
if ( V_74 ) {
F_32 ( L_77 ) ;
F_79 ( & V_367 , V_74 ) ;
return V_74 ;
}
V_74 = F_83 ( & V_367 ) ;
if ( V_74 ) {
F_32 ( L_77 ) ;
F_79 ( & V_367 , V_74 ) ;
return V_74 ;
}
F_79 ( & V_367 , V_74 ) ;
return V_74 ;
}
void F_84 ( void )
{
F_50 = & F_39 ;
}
