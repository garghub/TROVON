static inline bool F_1 ( T_1 V_1 )
{
if ( V_1 >= F_2 ( V_2 ) )
return false ;
if ( V_2 [ V_1 ] . V_3 )
return true ;
return false ;
}
static inline bool F_3 ( T_1 V_1 , enum V_4 V_5 )
{
if ( V_1 >= F_2 ( V_2 ) )
return false ;
if ( V_5 < V_2 [ V_1 ] . V_6 )
return false ;
if ( V_2 [ V_1 ] . V_7 > 0 )
return true ;
return false ;
}
static inline int F_4 ( T_1 V_1 )
{
if ( V_1 >= F_2 ( V_2 ) )
return 0 ;
return V_2 [ V_1 ] . V_8 ;
}
static inline int F_5 ( T_1 V_1 , T_1 V_9 )
{
unsigned V_10 ;
if ( V_1 >= F_2 ( V_2 ) )
return 0 ;
V_10 = V_2 [ V_1 ] . V_7 ;
if ( V_10 == 0 )
return 0 ;
return ( V_9 + V_10 - 1 ) / V_10 ;
}
static inline int F_6 ( T_1 V_1 , T_1 V_11 )
{
unsigned V_12 ;
if ( V_1 >= F_2 ( V_2 ) )
return 0 ;
V_12 = V_2 [ V_1 ] . V_13 ;
if ( V_12 == 0 )
return 0 ;
return ( V_11 + V_12 - 1 ) / V_12 ;
}
static inline int F_7 ( T_1 * V_14 , T_1 V_1 )
{
unsigned V_15 ;
if ( V_1 >= F_2 ( V_2 ) )
goto V_16;
V_15 = V_2 [ V_1 ] . V_8 ;
if ( V_15 == 0 )
goto V_16;
* V_14 = V_15 ;
return 0 ;
V_16:
* V_14 = 16 ;
return - V_17 ;
}
static inline int F_8 ( struct V_18 * V_19 ,
T_1 * V_20 ,
T_1 * V_21 ,
T_1 * V_22 ,
T_2 * V_23 )
{
T_1 V_24 = 8 ;
T_1 V_25 = 8 ;
T_1 V_26 = V_19 -> V_27 ;
T_1 V_28 = V_19 -> V_29 ;
T_1 V_30 = V_24 * V_25 * V_19 -> V_8 * V_19 -> V_31 ;
T_1 V_32 = V_26 * V_28 * V_30 ;
switch ( V_19 -> V_33 ) {
case V_34 :
* V_20 = 1 ;
* V_21 = 1 ;
* V_22 = 1 ;
* V_23 = 1 ;
break;
case V_35 :
* V_20 = F_9 ( ( T_1 ) 64 , ( T_1 ) ( V_19 -> V_36 / V_19 -> V_8 ) ) ;
* V_21 = V_25 ;
* V_22 = 1 ;
* V_23 = V_19 -> V_36 ;
break;
case V_37 :
* V_20 = F_9 ( ( T_1 ) V_24 ,
( T_1 ) ( V_19 -> V_36 /
( V_25 * V_19 -> V_8 * V_19 -> V_31 ) ) ) ;
* V_21 = V_25 ;
* V_22 = 1 ;
* V_23 = V_19 -> V_36 ;
break;
case V_38 :
* V_20 = F_9 ( ( T_1 ) V_26 ,
( T_1 ) ( ( ( V_19 -> V_36 / V_25 ) /
( V_19 -> V_8 * V_19 -> V_31 ) ) *
V_19 -> V_27 ) ) * V_24 ;
* V_21 = V_28 * V_25 ;
* V_22 = 1 ;
* V_23 = F_9 ( V_32 ,
( * V_20 ) * V_19 -> V_8 * ( * V_21 ) * V_19 -> V_31 ) ;
break;
default:
return - V_17 ;
}
return 0 ;
}
static void F_10 ( struct V_39 * V_40 )
{
int V_41 ;
V_40 -> V_42 = V_43 ;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ ) {
V_40 -> V_44 [ V_41 ] = 0 ;
V_40 -> V_45 [ V_41 ] = 0 ;
V_40 -> V_46 [ V_41 ] = 0 ;
V_40 -> V_47 [ V_41 ] = 0 ;
V_40 -> V_48 [ V_41 ] = NULL ;
V_40 -> V_49 [ V_41 ] = 0xFFFFFFFF ;
V_40 -> V_50 [ V_41 ] = 0xFFFFFFFF ;
}
V_40 -> V_51 = 0xFFFFFFFF ;
V_40 -> V_52 = 0xFFFFFFFF ;
V_40 -> V_53 = NULL ;
V_40 -> V_54 = 0xFFFFFFFF ;
V_40 -> V_55 = 7 | ( 1 << 25 ) ;
V_40 -> V_56 = 0xFFFFC000 ;
V_40 -> V_57 = 0xFFFFFFFF ;
V_40 -> V_58 = 0 ;
V_40 -> V_59 = 0xFFFFFFFF ;
}
static inline int F_11 ( struct V_60 * V_61 , int V_41 )
{
struct V_39 * V_40 = V_61 -> V_40 ;
T_1 V_62 , V_63 , V_64 ;
T_1 V_65 , V_21 , V_66 , V_20 , V_22 ;
T_2 V_67 , V_23 ;
struct V_18 V_68 ;
volatile T_1 * V_69 = V_61 -> V_69 -> V_70 ;
unsigned V_33 ;
T_1 V_1 ;
if ( F_12 ( V_40 -> V_47 [ V_41 ] ) ) {
F_13 ( V_61 -> V_71 , L_1 ) ;
return - V_17 ;
}
V_63 = F_14 ( V_40 -> V_48 [ V_41 ] ) - V_40 -> V_49 [ V_41 ] ;
V_1 = F_15 ( V_40 -> V_47 [ V_41 ] ) ;
if ( ! F_1 ( V_1 ) ) {
F_13 ( V_61 -> V_71 , L_2 ,
V_72 , __LINE__ , V_1 ,
V_41 , V_40 -> V_47 [ V_41 ] ) ;
return - V_17 ;
}
V_66 = ( F_16 ( V_40 -> V_45 [ V_41 ] ) + 1 ) * 8 ;
V_62 = F_17 ( V_40 -> V_45 [ V_41 ] ) + 1 ;
V_62 *= 64 ;
V_65 = V_62 / V_66 ;
if ( V_65 > 8192 )
V_65 = 8192 ;
V_33 = F_18 ( V_40 -> V_47 [ V_41 ] ) ;
V_67 = V_40 -> V_50 [ V_41 ] + V_40 -> V_49 [ V_41 ] ;
V_68 . V_33 = V_33 ;
V_68 . V_36 = V_40 -> V_36 ;
V_68 . V_27 = V_40 -> V_27 ;
V_68 . V_29 = V_40 -> V_29 ;
V_68 . V_31 = V_40 -> V_31 ;
V_68 . V_8 = F_4 ( V_1 ) ;
if ( F_8 ( & V_68 ,
& V_20 , & V_21 , & V_22 , & V_23 ) ) {
F_13 ( V_61 -> V_71 , L_3 , V_72 ,
F_18 ( V_40 -> V_47 [ V_41 ] ) , V_41 ,
V_40 -> V_47 [ V_41 ] ) ;
return - V_17 ;
}
switch ( V_33 ) {
case V_73 :
break;
case V_74 :
break;
case V_75 :
if ( V_65 > 7 )
V_65 &= ~ 0x7 ;
break;
case V_76 :
break;
default:
F_13 ( V_61 -> V_71 , L_3 , V_72 ,
F_18 ( V_40 -> V_47 [ V_41 ] ) , V_41 ,
V_40 -> V_47 [ V_41 ] ) ;
return - V_17 ;
}
if ( ! F_19 ( V_66 , V_20 ) ) {
F_13 ( V_61 -> V_71 , L_4 ,
V_72 , __LINE__ , V_66 , V_20 , V_33 ) ;
return - V_17 ;
}
if ( ! F_19 ( V_65 , V_21 ) ) {
F_13 ( V_61 -> V_71 , L_5 ,
V_72 , __LINE__ , V_65 , V_21 , V_33 ) ;
return - V_17 ;
}
if ( ! F_19 ( V_67 , V_23 ) ) {
F_13 ( V_61 -> V_71 , L_6 , V_72 , V_41 ,
V_67 , V_23 , V_33 ) ;
return - V_17 ;
}
V_64 = F_6 ( V_1 , V_65 ) * F_5 ( V_1 , V_66 ) * F_4 ( V_1 ) ;
if ( ( V_64 + V_40 -> V_49 [ V_41 ] ) > F_14 ( V_40 -> V_48 [ V_41 ] ) ) {
if ( V_33 == V_73 ) {
} else {
F_13 ( V_61 -> V_71 , L_7 , V_72 , V_41 ,
V_33 ,
V_40 -> V_49 [ V_41 ] , V_64 ,
F_14 ( V_40 -> V_48 [ V_41 ] ) ) ;
return - V_17 ;
}
}
V_64 = ( V_65 * V_66 ) >> 6 ;
if ( V_64 < V_62 )
V_62 = V_64 ;
V_64 = F_20 ( ( V_66 / 8 ) - 1 ) |
F_21 ( V_62 - 1 ) ;
V_69 [ V_40 -> V_46 [ V_41 ] ] = V_64 ;
return 0 ;
}
static int F_22 ( struct V_60 * V_61 )
{
struct V_39 * V_40 = V_61 -> V_40 ;
T_1 V_64 ;
int V_77 , V_41 ;
volatile T_1 * V_69 = V_61 -> V_69 -> V_70 ;
if ( V_61 -> V_78 == NULL )
return 0 ;
if ( V_40 -> V_79 || V_40 -> V_80 ) {
F_13 ( V_61 -> V_71 , L_8 ) ;
return - V_17 ;
}
V_64 = V_40 -> V_51 ;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ ) {
if ( ( V_64 >> ( V_41 * 4 ) ) & 0xF ) {
if ( V_40 -> V_48 [ V_41 ] == NULL ) {
F_13 ( V_61 -> V_71 , L_9 ,
V_72 , __LINE__ , V_40 -> V_51 , V_40 -> V_52 , V_41 ) ;
return - V_17 ;
}
V_77 = F_11 ( V_61 , V_41 ) ;
if ( V_77 )
return V_77 ;
}
}
if ( F_23 ( V_40 -> V_59 ) ||
F_24 ( V_40 -> V_59 ) ) {
T_1 V_81 , V_14 , V_82 , V_63 , V_62 ;
T_1 V_65 , V_21 , V_66 , V_20 , V_22 ;
T_2 V_67 , V_23 ;
struct V_18 V_68 ;
int V_33 ;
if ( V_40 -> V_53 == NULL ) {
F_13 ( V_61 -> V_71 , L_10 ) ;
return - V_17 ;
}
if ( F_25 ( V_40 -> V_55 ) ) {
F_13 ( V_61 -> V_71 , L_11 ) ;
return - V_17 ;
}
switch ( F_26 ( V_40 -> V_55 ) ) {
case V_83 :
V_14 = 2 ;
break;
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
V_14 = 4 ;
break;
case V_89 :
V_14 = 8 ;
break;
default:
F_13 ( V_61 -> V_71 , L_12 , F_26 ( V_40 -> V_55 ) ) ;
return - V_17 ;
}
if ( ( V_40 -> V_57 & 0xFFFFFC00 ) == 0xFFFFFC00 ) {
if ( ! V_40 -> V_58 ) {
F_13 ( V_61 -> V_71 , L_13 ) ;
return - V_17 ;
}
V_64 = F_14 ( V_40 -> V_53 ) - V_40 -> V_90 ;
V_64 = ( V_64 / V_14 ) >> 6 ;
if ( ! V_64 ) {
F_13 ( V_61 -> V_71 , L_14 ,
V_40 -> V_57 , V_14 , V_40 -> V_90 ,
F_14 ( V_40 -> V_53 ) ) ;
return - V_17 ;
}
V_69 [ V_40 -> V_58 ] = F_27 ( V_64 - 1 ) | ( V_40 -> V_57 & 0x3FF ) ;
} else {
V_63 = F_14 ( V_40 -> V_53 ) ;
V_66 = ( F_28 ( V_40 -> V_57 ) + 1 ) * 8 ;
V_62 = F_29 ( V_40 -> V_57 ) + 1 ;
V_62 *= 64 ;
V_65 = V_62 / V_66 ;
if ( V_65 > 8192 )
V_65 = 8192 ;
V_67 = V_40 -> V_54 + V_40 -> V_90 ;
V_33 = F_30 ( V_40 -> V_55 ) ;
V_68 . V_33 = V_33 ;
V_68 . V_36 = V_40 -> V_36 ;
V_68 . V_27 = V_40 -> V_27 ;
V_68 . V_29 = V_40 -> V_29 ;
V_68 . V_31 = V_40 -> V_31 ;
V_68 . V_8 = V_14 ;
if ( F_8 ( & V_68 ,
& V_20 , & V_21 , & V_22 , & V_23 ) ) {
F_13 ( V_61 -> V_71 , L_15 , V_72 ,
F_30 ( V_40 -> V_55 ) ,
V_40 -> V_55 ) ;
return - V_17 ;
}
switch ( V_33 ) {
case V_91 :
V_65 &= ~ 0x7 ;
break;
case V_92 :
break;
default:
F_13 ( V_61 -> V_71 , L_15 , V_72 ,
F_30 ( V_40 -> V_55 ) ,
V_40 -> V_55 ) ;
return - V_17 ;
}
if ( ! F_19 ( V_66 , V_20 ) ) {
F_13 ( V_61 -> V_71 , L_16 ,
V_72 , __LINE__ , V_66 , V_20 , V_33 ) ;
return - V_17 ;
}
if ( ! F_19 ( V_65 , V_21 ) ) {
F_13 ( V_61 -> V_71 , L_17 ,
V_72 , __LINE__ , V_65 , V_21 , V_33 ) ;
return - V_17 ;
}
if ( ! F_19 ( V_67 , V_23 ) ) {
F_13 ( V_61 -> V_71 , L_18 , V_72 , V_41 ,
V_67 , V_23 , V_33 ) ;
return - V_17 ;
}
V_82 = F_29 ( V_40 -> V_57 ) + 1 ;
V_81 = F_31 ( V_40 -> V_56 ) + 1 ;
V_64 = V_82 * V_14 * 64 * V_81 ;
if ( ( V_64 + V_40 -> V_90 ) > F_14 ( V_40 -> V_53 ) ) {
F_13 ( V_61 -> V_71 , L_19 ,
V_33 ,
V_40 -> V_57 , V_82 , V_81 , V_14 , V_64 + V_40 -> V_90 ,
F_14 ( V_40 -> V_53 ) ) ;
return - V_17 ;
}
}
}
return 0 ;
}
int F_32 ( struct V_60 * V_61 ,
struct V_93 * V_94 ,
unsigned V_95 )
{
struct V_96 * V_97 = & V_61 -> V_98 [ V_61 -> V_99 ] ;
T_3 V_100 ;
if ( V_95 >= V_97 -> V_101 ) {
F_33 ( L_20 ,
V_95 , V_97 -> V_101 ) ;
return - V_17 ;
}
V_100 = F_34 ( V_61 , V_95 ) ;
V_94 -> V_95 = V_95 ;
V_94 -> type = F_35 ( V_100 ) ;
V_94 -> V_102 = F_36 ( V_100 ) ;
V_94 -> V_103 = 0 ;
switch ( V_94 -> type ) {
case V_104 :
V_94 -> V_105 = F_37 ( V_100 ) ;
break;
case V_106 :
V_94 -> V_107 = F_38 ( V_100 ) ;
break;
case V_108 :
V_94 -> V_102 = - 1 ;
break;
default:
F_33 ( L_21 , V_94 -> type , V_95 ) ;
return - V_17 ;
}
if ( ( V_94 -> V_102 + 1 + V_94 -> V_95 ) >= V_97 -> V_101 ) {
F_33 ( L_22 ,
V_94 -> V_95 , V_94 -> type , V_94 -> V_102 , V_97 -> V_101 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_39 ( struct V_60 * V_61 ,
struct V_109 * * V_110 )
{
struct V_96 * V_111 ;
struct V_93 V_112 ;
unsigned V_95 ;
int V_77 ;
if ( V_61 -> V_113 == - 1 ) {
F_33 ( L_23 ) ;
return - V_17 ;
}
* V_110 = NULL ;
V_111 = & V_61 -> V_98 [ V_61 -> V_113 ] ;
V_77 = F_32 ( V_61 , & V_112 , V_61 -> V_95 ) ;
if ( V_77 ) {
return V_77 ;
}
V_61 -> V_95 += V_112 . V_102 + 2 ;
if ( V_112 . type != V_106 || V_112 . V_107 != V_114 ) {
F_33 ( L_24 ,
V_112 . V_95 ) ;
return - V_17 ;
}
V_95 = F_34 ( V_61 , V_112 . V_95 + 1 ) ;
if ( V_95 >= V_111 -> V_101 ) {
F_33 ( L_25 ,
V_95 , V_111 -> V_101 ) ;
return - V_17 ;
}
* V_110 = V_61 -> V_115 [ ( V_95 / 4 ) ] ;
return 0 ;
}
static int F_40 ( struct V_60 * V_61 ,
struct V_109 * * V_110 )
{
struct V_96 * V_111 ;
struct V_93 V_112 ;
unsigned V_95 ;
int V_77 ;
if ( V_61 -> V_113 == - 1 ) {
F_33 ( L_23 ) ;
return - V_17 ;
}
* V_110 = NULL ;
V_111 = & V_61 -> V_98 [ V_61 -> V_113 ] ;
V_77 = F_32 ( V_61 , & V_112 , V_61 -> V_95 ) ;
if ( V_77 ) {
return V_77 ;
}
V_61 -> V_95 += V_112 . V_102 + 2 ;
if ( V_112 . type != V_106 || V_112 . V_107 != V_114 ) {
F_33 ( L_24 ,
V_112 . V_95 ) ;
return - V_17 ;
}
V_95 = F_34 ( V_61 , V_112 . V_95 + 1 ) ;
if ( V_95 >= V_111 -> V_101 ) {
F_33 ( L_25 ,
V_95 , V_111 -> V_101 ) ;
return - V_17 ;
}
* V_110 = V_61 -> V_116 ;
( * V_110 ) -> V_117 . V_118 = ( T_2 ) V_111 -> V_119 [ V_95 + 3 ] << 32 ;
( * V_110 ) -> V_117 . V_118 |= V_111 -> V_119 [ V_95 + 0 ] ;
return 0 ;
}
static inline int F_41 ( struct V_60 * V_61 )
{
struct V_93 V_112 ;
int V_77 ;
V_77 = F_32 ( V_61 , & V_112 , V_61 -> V_95 ) ;
if ( V_77 ) {
return 0 ;
}
if ( V_112 . type != V_106 || V_112 . V_107 != V_114 ) {
return 0 ;
}
return 1 ;
}
static int F_42 ( struct V_60 * V_61 )
{
struct V_120 * V_121 ;
struct V_122 * V_123 ;
struct V_124 * V_124 ;
struct V_93 V_112 , V_125 ;
int V_126 ;
int V_77 ;
T_3 V_100 , V_127 , V_105 , V_128 ;
volatile T_3 * V_69 ;
V_69 = V_61 -> V_69 -> V_70 ;
V_77 = F_32 ( V_61 , & V_125 , V_61 -> V_95 ) ;
if ( V_77 )
return V_77 ;
if ( V_125 . type != V_106 ||
V_125 . V_107 != V_129 ) {
F_33 ( L_26 ) ;
return - V_17 ;
}
V_128 = F_34 ( V_61 , V_125 . V_95 + 1 ) ;
if ( V_128 & 0x10 ) {
F_33 ( L_27 ) ;
return - V_17 ;
}
if ( ( V_128 & 0x7 ) != 0x3 ) {
F_33 ( L_28 ) ;
return - V_17 ;
}
if ( ( F_34 ( V_61 , V_125 . V_95 + 2 ) << 2 ) != V_130 ) {
F_33 ( L_29 ) ;
return - V_17 ;
}
if ( F_34 ( V_61 , V_125 . V_95 + 5 ) != V_131 ) {
F_33 ( L_30 ) ;
return - V_17 ;
}
V_77 = F_32 ( V_61 , & V_112 , V_61 -> V_95 + V_125 . V_102 + 2 ) ;
if ( V_77 )
return V_77 ;
V_127 = V_61 -> V_95 - 2 ;
V_61 -> V_95 += V_125 . V_102 + 2 ;
V_61 -> V_95 += V_112 . V_102 + 2 ;
V_100 = F_34 ( V_61 , V_127 ) ;
V_126 = F_34 ( V_61 , V_127 + 2 + 7 + 1 ) ;
V_105 = F_37 ( V_100 ) ;
V_121 = F_43 ( V_61 -> V_78 -> V_132 , V_126 , V_133 ) ;
if ( ! V_121 ) {
F_33 ( L_31 , V_126 ) ;
return - V_17 ;
}
V_123 = F_44 ( V_121 ) ;
V_124 = F_45 ( V_123 ) ;
V_126 = V_124 -> V_126 ;
if ( ! V_123 -> V_134 ) {
V_69 [ V_127 + 2 ] = F_46 ( 0 ) ;
V_69 [ V_127 + 3 ] = F_46 ( 0 ) ;
V_69 [ V_127 + 4 ] = F_46 ( 0 ) ;
V_69 [ V_127 + 5 ] = F_46 ( 0 ) ;
V_69 [ V_127 + 6 ] = F_46 ( 0 ) ;
V_69 [ V_127 + 7 ] = F_46 ( 0 ) ;
V_69 [ V_127 + 8 ] = F_46 ( 0 ) ;
} else if ( V_126 == 1 ) {
switch ( V_105 ) {
case V_135 :
V_100 &= ~ V_136 ;
V_100 |= V_137 >> 2 ;
break;
default:
F_33 ( L_32 ) ;
return - V_17 ;
}
V_69 [ V_127 ] = V_100 ;
V_69 [ V_127 + 4 ] = V_138 >> 2 ;
}
return 0 ;
}
static int F_47 ( struct V_60 * V_61 ,
struct V_93 * V_94 ,
unsigned V_95 , unsigned V_105 )
{
int V_77 ;
switch ( V_105 ) {
case V_135 :
V_77 = F_42 ( V_61 ) ;
if ( V_77 ) {
F_33 ( L_33 ,
V_95 , V_105 ) ;
return V_77 ;
}
break;
default:
F_48 ( V_139 L_34 ,
V_105 , V_95 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_49 ( struct V_60 * V_61 ,
struct V_93 * V_94 )
{
unsigned V_105 , V_41 ;
unsigned V_95 ;
int V_77 ;
V_95 = V_94 -> V_95 + 1 ;
V_105 = V_94 -> V_105 ;
for ( V_41 = 0 ; V_41 <= V_94 -> V_102 ; V_41 ++ , V_95 ++ , V_105 += 4 ) {
V_77 = F_47 ( V_61 , V_94 , V_95 , V_105 ) ;
if ( V_77 ) {
return V_77 ;
}
}
return 0 ;
}
static inline int F_50 ( struct V_60 * V_61 , T_1 V_105 , T_1 V_95 )
{
struct V_39 * V_40 = (struct V_39 * ) V_61 -> V_40 ;
struct V_109 * V_140 ;
T_1 V_141 , V_41 , V_64 , * V_69 ;
int V_77 ;
V_41 = ( V_105 >> 7 ) ;
if ( V_41 >= F_2 ( V_142 ) ) {
F_13 ( V_61 -> V_71 , L_35 , V_105 , V_95 ) ;
return - V_17 ;
}
V_141 = 1 << ( ( V_105 >> 2 ) & 31 ) ;
if ( ! ( V_142 [ V_41 ] & V_141 ) )
return 0 ;
V_69 = V_61 -> V_69 -> V_70 ;
switch ( V_105 ) {
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
case V_158 :
case V_159 :
V_64 = F_34 ( V_61 , V_95 ) ;
V_69 [ V_95 ] = 0 ;
break;
case V_160 :
V_40 -> V_42 = F_34 ( V_61 , V_95 ) ;
break;
case V_161 :
V_40 -> V_59 = F_34 ( V_61 , V_95 ) ;
break;
case V_162 :
if ( F_41 ( V_61 ) ) {
V_77 = F_51 ( V_61 , & V_140 ) ;
if ( V_77 ) {
F_13 ( V_61 -> V_71 , L_36
L_37 , V_105 ) ;
return - V_17 ;
}
V_40 -> V_55 = F_34 ( V_61 , V_95 ) ;
V_69 [ V_95 ] &= V_163 ;
V_40 -> V_55 &= V_163 ;
if ( V_140 -> V_117 . V_164 & V_165 ) {
V_69 [ V_95 ] |= F_52 ( V_92 ) ;
V_40 -> V_55 |= F_52 ( V_92 ) ;
} else {
V_69 [ V_95 ] |= F_52 ( V_91 ) ;
V_40 -> V_55 |= F_52 ( V_91 ) ;
}
} else
V_40 -> V_55 = F_34 ( V_61 , V_95 ) ;
break;
case V_166 :
V_40 -> V_56 = F_34 ( V_61 , V_95 ) ;
break;
case V_167 :
V_40 -> V_57 = F_34 ( V_61 , V_95 ) ;
V_40 -> V_58 = V_95 ;
break;
case V_168 :
V_40 -> V_79 = F_34 ( V_61 , V_95 ) ;
break;
case V_169 :
V_40 -> V_80 = F_34 ( V_61 , V_95 ) ;
break;
case V_170 :
V_40 -> V_51 = F_34 ( V_61 , V_95 ) ;
break;
case V_171 :
V_40 -> V_52 = F_34 ( V_61 , V_95 ) ;
break;
case V_172 :
V_64 = F_53 ( F_34 ( V_61 , V_95 ) ) ;
V_40 -> V_31 = 1 << V_64 ;
break;
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
if ( F_41 ( V_61 ) ) {
V_77 = F_51 ( V_61 , & V_140 ) ;
if ( V_77 ) {
F_54 ( V_61 -> V_71 , L_38 , V_105 ) ;
return - V_17 ;
}
V_64 = ( V_105 - V_173 ) / 4 ;
V_40 -> V_47 [ V_64 ] = F_34 ( V_61 , V_95 ) ;
if ( V_140 -> V_117 . V_164 & V_165 ) {
V_69 [ V_95 ] |= F_55 ( V_76 ) ;
V_40 -> V_47 [ V_64 ] |= F_55 ( V_76 ) ;
} else if ( V_140 -> V_117 . V_164 & V_181 ) {
V_69 [ V_95 ] |= F_55 ( V_75 ) ;
V_40 -> V_47 [ V_64 ] |= F_55 ( V_75 ) ;
}
} else {
V_64 = ( V_105 - V_173 ) / 4 ;
V_40 -> V_47 [ V_64 ] = F_34 ( V_61 , V_95 ) ;
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
V_64 = ( V_105 - V_182 ) / 4 ;
V_40 -> V_45 [ V_64 ] = F_34 ( V_61 , V_95 ) ;
V_40 -> V_46 [ V_64 ] = V_95 ;
break;
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
V_64 = ( V_105 - V_190 ) / 4 ;
if ( ! F_41 ( V_61 ) ) {
if ( ! V_40 -> V_44 [ V_64 ] ) {
F_54 ( V_61 -> V_71 , L_39 , V_105 ) ;
return - V_17 ;
}
V_69 [ V_95 ] = V_40 -> V_44 [ V_64 ] ;
V_40 -> V_198 [ V_64 ] = V_40 -> V_48 [ V_64 ] ;
} else {
V_77 = F_51 ( V_61 , & V_140 ) ;
if ( V_77 ) {
F_54 ( V_61 -> V_71 , L_38 , V_105 ) ;
return - V_17 ;
}
V_69 [ V_95 ] += ( T_1 ) ( ( V_140 -> V_117 . V_118 >> 8 ) & 0xffffffff ) ;
V_40 -> V_198 [ V_64 ] = V_140 -> V_199 ;
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
V_64 = ( V_105 - V_200 ) / 4 ;
if ( ! F_41 ( V_61 ) ) {
if ( ! V_40 -> V_44 [ V_64 ] ) {
F_54 ( V_61 -> V_71 , L_39 , V_105 ) ;
return - V_17 ;
}
V_69 [ V_95 ] = V_40 -> V_44 [ V_64 ] ;
V_40 -> V_208 [ V_64 ] = V_40 -> V_48 [ V_64 ] ;
} else {
V_77 = F_51 ( V_61 , & V_140 ) ;
if ( V_77 ) {
F_54 ( V_61 -> V_71 , L_38 , V_105 ) ;
return - V_17 ;
}
V_69 [ V_95 ] += ( T_1 ) ( ( V_140 -> V_117 . V_118 >> 8 ) & 0xffffffff ) ;
V_40 -> V_208 [ V_64 ] = V_140 -> V_199 ;
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
V_77 = F_51 ( V_61 , & V_140 ) ;
if ( V_77 ) {
F_13 ( V_61 -> V_71 , L_36
L_37 , V_105 ) ;
return - V_17 ;
}
V_64 = ( V_105 - V_209 ) / 4 ;
V_40 -> V_49 [ V_64 ] = F_34 ( V_61 , V_95 ) << 8 ;
V_69 [ V_95 ] += ( T_1 ) ( ( V_140 -> V_117 . V_118 >> 8 ) & 0xffffffff ) ;
V_40 -> V_44 [ V_64 ] = V_69 [ V_95 ] ;
V_40 -> V_48 [ V_64 ] = V_140 -> V_199 ;
V_40 -> V_50 [ V_64 ] = V_140 -> V_117 . V_118 ;
break;
case V_217 :
V_77 = F_51 ( V_61 , & V_140 ) ;
if ( V_77 ) {
F_13 ( V_61 -> V_71 , L_36
L_37 , V_105 ) ;
return - V_17 ;
}
V_40 -> V_90 = F_34 ( V_61 , V_95 ) << 8 ;
V_69 [ V_95 ] += ( T_1 ) ( ( V_140 -> V_117 . V_118 >> 8 ) & 0xffffffff ) ;
V_40 -> V_53 = V_140 -> V_199 ;
V_40 -> V_54 = V_140 -> V_117 . V_118 ;
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
V_77 = F_51 ( V_61 , & V_140 ) ;
if ( V_77 ) {
F_13 ( V_61 -> V_71 , L_36
L_37 , V_105 ) ;
return - V_17 ;
}
V_69 [ V_95 ] += ( T_1 ) ( ( V_140 -> V_117 . V_118 >> 8 ) & 0xffffffff ) ;
break;
case V_272 :
V_77 = F_51 ( V_61 , & V_140 ) ;
if ( V_77 ) {
F_13 ( V_61 -> V_71 , L_40
L_37 , V_105 ) ;
return - V_17 ;
}
V_69 [ V_95 ] += ( T_1 ) ( ( V_140 -> V_117 . V_118 >> 8 ) & 0xffffffff ) ;
break;
default:
F_13 ( V_61 -> V_71 , L_35 , V_105 , V_95 ) ;
return - V_17 ;
}
return 0 ;
}
static inline unsigned F_56 ( unsigned V_63 , unsigned V_273 )
{
unsigned V_274 ;
V_274 = F_9 ( 1U , V_63 >> V_273 ) ;
if ( V_273 > 0 )
V_274 = F_57 ( V_274 ) ;
return V_274 ;
}
static void F_58 ( unsigned V_275 , unsigned V_276 , unsigned V_277 ,
unsigned V_278 , unsigned V_279 , unsigned V_280 , unsigned V_1 ,
unsigned V_281 , unsigned V_21 , unsigned V_23 ,
unsigned * V_282 , unsigned * V_283 )
{
unsigned V_284 , V_41 , V_273 ;
unsigned V_285 , V_65 , V_286 , V_63 ;
unsigned V_8 ;
unsigned V_287 , V_288 ;
unsigned V_289 = V_277 - V_276 + 1 ;
* V_282 = - 1 ;
V_8 = F_4 ( V_1 ) ;
V_278 = F_56 ( V_278 , 0 ) ;
V_279 = F_56 ( V_279 , 0 ) ;
V_280 = F_56 ( V_280 , 0 ) ;
for( V_41 = 0 , V_284 = 0 , V_273 = V_276 ; V_41 < V_289 ; V_41 ++ , V_273 ++ ) {
V_285 = F_56 ( V_278 , V_41 ) ;
V_287 = F_5 ( V_1 , V_285 ) ;
V_287 = F_59 ( V_287 , V_281 ) ;
V_65 = F_56 ( V_279 , V_41 ) ;
V_288 = F_6 ( V_1 , V_65 ) ;
V_288 = F_59 ( V_288 , V_21 ) ;
V_286 = F_56 ( V_280 , V_41 ) ;
V_63 = V_287 * V_288 * V_8 ;
if ( V_275 )
V_63 *= V_275 ;
else
V_63 *= V_286 ;
if ( V_41 == 0 )
* V_282 = V_63 ;
if ( V_41 == 0 || V_41 == 1 )
V_284 = F_59 ( V_284 , V_23 ) ;
V_284 += V_63 ;
}
* V_283 = V_284 ;
if ( V_277 == 0 )
* V_283 = * V_282 ;
if ( ! V_276 )
* V_283 -= * V_282 ;
}
static inline int F_60 ( struct V_60 * V_61 , T_1 V_95 ,
struct V_290 * V_291 ,
struct V_290 * V_292 ,
T_2 V_67 ,
T_2 V_293 ,
T_1 V_164 )
{
struct V_39 * V_40 = V_61 -> V_40 ;
T_1 V_275 , V_277 , V_276 , V_278 , V_279 , V_280 ;
T_1 V_294 , V_295 , V_282 , V_283 , V_296 , V_297 ;
T_1 V_21 , V_66 , V_20 , V_22 ;
T_1 V_298 , V_299 , V_300 ;
T_2 V_23 ;
struct V_18 V_68 ;
T_1 V_1 ;
if ( V_61 -> V_78 == NULL )
return 0 ;
V_67 <<= 8 ;
V_293 <<= 8 ;
V_294 = F_34 ( V_61 , V_95 + 0 ) ;
if ( V_164 & V_165 )
V_294 |= F_61 ( V_301 ) ;
else if ( V_164 & V_181 )
V_294 |= F_61 ( V_302 ) ;
V_295 = F_34 ( V_61 , V_95 + 1 ) ;
V_278 = F_62 ( V_294 ) + 1 ;
V_279 = F_63 ( V_295 ) + 1 ;
V_280 = F_64 ( V_295 ) ;
V_275 = 1 ;
switch ( F_65 ( V_294 ) ) {
case V_303 :
case V_304 :
case V_305 :
break;
case V_306 :
if ( V_61 -> V_5 >= V_307 )
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
F_13 ( V_61 -> V_71 , L_41 , F_65 ( V_294 ) ) ;
return - V_17 ;
}
V_1 = F_66 ( V_295 ) ;
if ( ! F_3 ( V_1 , V_61 -> V_5 ) ) {
F_13 ( V_61 -> V_71 , L_42 ,
V_72 , __LINE__ , V_1 ) ;
return - V_17 ;
}
V_66 = ( F_67 ( V_294 ) + 1 ) * 8 ;
V_68 . V_33 = F_68 ( V_294 ) ;
V_68 . V_36 = V_40 -> V_36 ;
V_68 . V_27 = V_40 -> V_27 ;
V_68 . V_29 = V_40 -> V_29 ;
V_68 . V_31 = 1 ;
V_68 . V_8 = F_4 ( V_1 ) ;
if ( F_8 ( & V_68 ,
& V_20 , & V_21 , & V_22 , & V_23 ) ) {
F_13 ( V_61 -> V_71 , L_43 ,
V_72 , __LINE__ , F_68 ( V_294 ) ) ;
return - V_17 ;
}
if ( ! F_19 ( V_66 , V_20 ) ) {
F_13 ( V_61 -> V_71 , L_44 ,
V_72 , __LINE__ , V_66 , V_20 , F_68 ( V_294 ) ) ;
return - V_17 ;
}
if ( ! F_19 ( V_67 , V_23 ) ) {
F_13 ( V_61 -> V_71 , L_45 ,
V_72 , __LINE__ , V_67 , V_23 , F_68 ( V_294 ) ) ;
return - V_17 ;
}
if ( ! F_19 ( V_293 , V_23 ) ) {
F_13 ( V_61 -> V_71 , L_46 ,
V_72 , __LINE__ , V_293 , V_23 , F_68 ( V_294 ) ) ;
return - V_17 ;
}
V_296 = F_34 ( V_61 , V_95 + 2 ) << 8 ;
V_297 = F_34 ( V_61 , V_95 + 3 ) << 8 ;
V_294 = F_34 ( V_61 , V_95 + 4 ) ;
V_295 = F_34 ( V_61 , V_95 + 5 ) ;
V_276 = F_69 ( V_294 ) ;
V_277 = F_70 ( V_295 ) ;
if ( V_298 == 1 ) {
V_299 = F_71 ( V_295 ) ;
V_300 = F_72 ( V_295 ) ;
V_275 = V_300 - V_299 + 1 ;
}
F_58 ( V_275 , V_276 , V_277 , V_278 , V_279 , V_280 , V_1 ,
V_20 , V_21 , V_23 ,
& V_282 , & V_283 ) ;
if ( ( V_282 + V_296 ) > F_14 ( V_291 ) ) {
F_13 ( V_61 -> V_71 , L_47 ,
V_278 , V_279 , V_1 , V_296 , V_282 , F_14 ( V_291 ) ) ;
F_13 ( V_61 -> V_71 , L_48 , V_66 , V_20 , V_21 , V_23 ) ;
return - V_17 ;
}
V_297 = F_34 ( V_61 , V_95 + 3 ) << 8 ;
if ( ( V_283 + V_297 ) > F_14 ( V_292 ) ) {
}
return 0 ;
}
static int F_73 ( struct V_60 * V_61 ,
struct V_93 * V_94 )
{
struct V_109 * V_140 ;
struct V_39 * V_40 ;
volatile T_1 * V_69 ;
unsigned V_95 ;
unsigned V_41 ;
unsigned V_312 , V_313 , V_105 ;
int V_77 ;
T_1 V_314 ;
V_40 = (struct V_39 * ) V_61 -> V_40 ;
V_69 = V_61 -> V_69 -> V_70 ;
V_95 = V_94 -> V_95 + 1 ;
V_314 = F_34 ( V_61 , V_95 ) ;
switch ( V_94 -> V_107 ) {
case V_315 :
{
int V_316 ;
int V_64 ;
if ( V_94 -> V_102 != 1 ) {
F_33 ( L_49 ) ;
return - V_17 ;
}
V_64 = F_34 ( V_61 , V_95 + 1 ) ;
V_316 = ( V_64 >> 16 ) & 0x7 ;
if ( V_316 == 0 )
return 0 ;
if ( V_316 > 2 ) {
F_33 ( L_50 , V_316 ) ;
return - V_17 ;
}
V_77 = F_51 ( V_61 , & V_140 ) ;
if ( V_77 ) {
F_33 ( L_49 ) ;
return - V_17 ;
}
V_69 [ V_95 + 0 ] = V_314 + ( T_1 ) ( V_140 -> V_117 . V_118 & 0xffffffff ) ;
V_69 [ V_95 + 1 ] = V_64 + ( F_74 ( V_140 -> V_117 . V_118 ) & 0xff ) ;
}
break;
case V_317 :
if ( V_61 -> V_5 >= V_307 || V_94 -> V_102 ) {
F_33 ( L_51 ) ;
return - V_17 ;
}
break;
case V_318 :
if ( V_94 -> V_102 != 1 ) {
F_33 ( L_52 ) ;
return - V_17 ;
}
break;
case V_319 :
case V_320 :
if ( V_94 -> V_102 ) {
F_33 ( L_53 ) ;
return - V_17 ;
}
break;
case V_321 :
if ( V_94 -> V_102 != 3 ) {
F_33 ( L_54 ) ;
return - V_17 ;
}
V_77 = F_51 ( V_61 , & V_140 ) ;
if ( V_77 ) {
F_33 ( L_54 ) ;
return - V_17 ;
}
V_69 [ V_95 + 0 ] = V_314 + ( T_1 ) ( V_140 -> V_117 . V_118 & 0xffffffff ) ;
V_69 [ V_95 + 1 ] += F_74 ( V_140 -> V_117 . V_118 ) & 0xff ;
V_77 = F_22 ( V_61 ) ;
if ( V_77 ) {
F_13 ( V_61 -> V_71 , L_55 , V_72 , __LINE__ ) ;
return V_77 ;
}
break;
case V_322 :
if ( V_94 -> V_102 != 1 ) {
F_33 ( L_56 ) ;
return - V_17 ;
}
V_77 = F_22 ( V_61 ) ;
if ( V_77 ) {
F_13 ( V_61 -> V_71 , L_57 , V_72 , __LINE__ , V_95 ) ;
return V_77 ;
}
break;
case V_323 :
case V_324 :
if ( V_94 -> V_102 < 2 ) {
F_33 ( L_58 ) ;
return - V_17 ;
}
V_77 = F_22 ( V_61 ) ;
if ( V_77 ) {
F_13 ( V_61 -> V_71 , L_55 , V_72 , __LINE__ ) ;
return V_77 ;
}
break;
case V_129 :
if ( V_94 -> V_102 != 5 ) {
F_33 ( L_59 ) ;
return - V_17 ;
}
if ( V_314 & 0x10 ) {
V_77 = F_51 ( V_61 , & V_140 ) ;
if ( V_77 ) {
F_33 ( L_59 ) ;
return - V_17 ;
}
V_69 [ V_95 + 1 ] += ( T_1 ) ( V_140 -> V_117 . V_118 & 0xffffffff ) ;
V_69 [ V_95 + 2 ] += F_74 ( V_140 -> V_117 . V_118 ) & 0xff ;
}
break;
case V_325 :
if ( V_94 -> V_102 != 3 ) {
F_33 ( L_60 ) ;
return - V_17 ;
}
if ( F_34 ( V_61 , V_95 + 1 ) != 0xffffffff ||
F_34 ( V_61 , V_95 + 2 ) != 0 ) {
V_77 = F_51 ( V_61 , & V_140 ) ;
if ( V_77 ) {
F_33 ( L_60 ) ;
return - V_17 ;
}
V_69 [ V_95 + 2 ] += ( T_1 ) ( ( V_140 -> V_117 . V_118 >> 8 ) & 0xffffffff ) ;
}
break;
case V_326 :
if ( V_94 -> V_102 != 2 && V_94 -> V_102 != 0 ) {
F_33 ( L_61 ) ;
return - V_17 ;
}
if ( V_94 -> V_102 ) {
V_77 = F_51 ( V_61 , & V_140 ) ;
if ( V_77 ) {
F_33 ( L_61 ) ;
return - V_17 ;
}
V_69 [ V_95 + 1 ] += ( T_1 ) ( V_140 -> V_117 . V_118 & 0xffffffff ) ;
V_69 [ V_95 + 2 ] += F_74 ( V_140 -> V_117 . V_118 ) & 0xff ;
}
break;
case V_327 :
if ( V_94 -> V_102 != 4 ) {
F_33 ( L_62 ) ;
return - V_17 ;
}
V_77 = F_51 ( V_61 , & V_140 ) ;
if ( V_77 ) {
F_33 ( L_61 ) ;
return - V_17 ;
}
V_69 [ V_95 + 1 ] += ( T_1 ) ( V_140 -> V_117 . V_118 & 0xffffffff ) ;
V_69 [ V_95 + 2 ] += F_74 ( V_140 -> V_117 . V_118 ) & 0xff ;
break;
case V_328 :
V_312 = ( V_314 << 2 ) + V_329 ;
V_313 = 4 * V_94 -> V_102 + V_312 - 4 ;
if ( ( V_312 < V_329 ) ||
( V_312 >= V_330 ) ||
( V_313 >= V_330 ) ) {
F_33 ( L_63 ) ;
return - V_17 ;
}
for ( V_41 = 0 ; V_41 < V_94 -> V_102 ; V_41 ++ ) {
V_105 = V_312 + ( 4 * V_41 ) ;
V_77 = F_50 ( V_61 , V_105 , V_95 + 1 + V_41 ) ;
if ( V_77 )
return V_77 ;
}
break;
case V_331 :
V_312 = ( V_314 << 2 ) + V_332 ;
V_313 = 4 * V_94 -> V_102 + V_312 - 4 ;
if ( ( V_312 < V_332 ) ||
( V_312 >= V_333 ) ||
( V_313 >= V_333 ) ) {
F_33 ( L_64 ) ;
return - V_17 ;
}
for ( V_41 = 0 ; V_41 < V_94 -> V_102 ; V_41 ++ ) {
V_105 = V_312 + ( 4 * V_41 ) ;
V_77 = F_50 ( V_61 , V_105 , V_95 + 1 + V_41 ) ;
if ( V_77 )
return V_77 ;
}
break;
case V_334 :
if ( V_94 -> V_102 % 7 ) {
F_33 ( L_65 ) ;
return - V_17 ;
}
V_312 = ( V_314 << 2 ) + V_335 ;
V_313 = 4 * V_94 -> V_102 + V_312 - 4 ;
if ( ( V_312 < V_335 ) ||
( V_312 >= V_336 ) ||
( V_313 >= V_336 ) ) {
F_33 ( L_65 ) ;
return - V_17 ;
}
for ( V_41 = 0 ; V_41 < ( V_94 -> V_102 / 7 ) ; V_41 ++ ) {
struct V_290 * V_291 , * V_292 ;
T_1 V_63 , V_284 , V_67 , V_293 ;
switch ( F_75 ( F_34 ( V_61 , V_95 + ( V_41 * 7 ) + 6 + 1 ) ) ) {
case V_337 :
V_77 = F_51 ( V_61 , & V_140 ) ;
if ( V_77 ) {
F_33 ( L_65 ) ;
return - V_17 ;
}
V_67 = ( T_1 ) ( ( V_140 -> V_117 . V_118 >> 8 ) & 0xffffffff ) ;
if ( V_140 -> V_117 . V_164 & V_165 )
V_69 [ V_95 + 1 + ( V_41 * 7 ) + 0 ] |= F_61 ( V_301 ) ;
else if ( V_140 -> V_117 . V_164 & V_181 )
V_69 [ V_95 + 1 + ( V_41 * 7 ) + 0 ] |= F_61 ( V_302 ) ;
V_291 = V_140 -> V_199 ;
V_77 = F_51 ( V_61 , & V_140 ) ;
if ( V_77 ) {
F_33 ( L_65 ) ;
return - V_17 ;
}
V_293 = ( T_1 ) ( ( V_140 -> V_117 . V_118 >> 8 ) & 0xffffffff ) ;
V_292 = V_140 -> V_199 ;
V_77 = F_60 ( V_61 , V_95 + ( V_41 * 7 ) + 1 ,
V_291 , V_292 ,
V_67 + F_34 ( V_61 , V_95 + 1 + ( V_41 * 7 ) + 2 ) ,
V_293 + F_34 ( V_61 , V_95 + 1 + ( V_41 * 7 ) + 3 ) ,
V_140 -> V_117 . V_164 ) ;
if ( V_77 )
return V_77 ;
V_69 [ V_95 + 1 + ( V_41 * 7 ) + 2 ] += V_67 ;
V_69 [ V_95 + 1 + ( V_41 * 7 ) + 3 ] += V_293 ;
break;
case V_338 :
V_77 = F_51 ( V_61 , & V_140 ) ;
if ( V_77 ) {
F_33 ( L_65 ) ;
return - V_17 ;
}
V_284 = F_34 ( V_61 , V_95 + 1 + ( V_41 * 7 ) + 0 ) ;
V_63 = F_34 ( V_61 , V_95 + 1 + ( V_41 * 7 ) + 1 ) + 1 ;
if ( V_61 -> V_78 && ( V_63 + V_284 ) > F_14 ( V_140 -> V_199 ) ) {
F_13 ( V_61 -> V_71 , L_66 ,
V_63 + V_284 , F_14 ( V_140 -> V_199 ) ) ;
V_69 [ V_95 + 1 + ( V_41 * 7 ) + 1 ] = F_14 ( V_140 -> V_199 ) ;
}
V_69 [ V_95 + 1 + ( V_41 * 7 ) + 0 ] += ( T_1 ) ( ( V_140 -> V_117 . V_118 ) & 0xffffffff ) ;
V_69 [ V_95 + 1 + ( V_41 * 7 ) + 2 ] += F_74 ( V_140 -> V_117 . V_118 ) & 0xff ;
break;
case V_339 :
case V_340 :
default:
F_33 ( L_65 ) ;
return - V_17 ;
}
}
break;
case V_341 :
if ( V_40 -> V_42 & V_43 ) {
V_312 = ( V_314 << 2 ) + V_342 ;
V_313 = 4 * V_94 -> V_102 + V_312 - 4 ;
if ( ( V_312 < V_342 ) ||
( V_312 >= V_343 ) ||
( V_313 >= V_343 ) ) {
F_33 ( L_67 ) ;
return - V_17 ;
}
}
break;
case V_344 :
V_312 = ( V_314 << 2 ) + V_345 ;
V_313 = 4 * V_94 -> V_102 + V_312 - 4 ;
if ( ( V_312 < V_345 ) ||
( V_312 >= V_346 ) ||
( V_313 >= V_346 ) ) {
F_33 ( L_68 ) ;
return - V_17 ;
}
break;
case V_347 :
V_312 = ( V_314 << 2 ) + V_348 ;
V_313 = 4 * V_94 -> V_102 + V_312 - 4 ;
if ( ( V_312 < V_348 ) ||
( V_312 >= V_349 ) ||
( V_313 >= V_349 ) ) {
F_33 ( L_69 ) ;
return - V_17 ;
}
break;
case V_350 :
V_312 = ( V_314 << 2 ) + V_351 ;
V_313 = 4 * V_94 -> V_102 + V_312 - 4 ;
if ( ( V_312 < V_351 ) ||
( V_312 >= V_352 ) ||
( V_313 >= V_352 ) ) {
F_33 ( L_70 ) ;
return - V_17 ;
}
break;
case V_353 :
if ( V_94 -> V_102 % 3 ) {
F_33 ( L_71 ) ;
return - V_17 ;
}
V_312 = ( V_314 << 2 ) + V_354 ;
V_313 = 4 * V_94 -> V_102 + V_312 - 4 ;
if ( ( V_312 < V_354 ) ||
( V_312 >= V_355 ) ||
( V_313 >= V_355 ) ) {
F_33 ( L_71 ) ;
return - V_17 ;
}
break;
case V_356 :
if ( V_61 -> V_5 >= V_307 || V_61 -> V_5 == V_357 ) {
F_33 ( L_72 ) ;
return - V_17 ;
}
if ( V_94 -> V_102 ) {
F_33 ( L_72 ) ;
return - V_17 ;
}
break;
case V_114 :
break;
default:
F_33 ( L_73 , V_94 -> V_107 ) ;
return - V_17 ;
}
return 0 ;
}
int F_76 ( struct V_60 * V_61 )
{
struct V_93 V_94 ;
struct V_39 * V_40 ;
int V_77 ;
if ( V_61 -> V_40 == NULL ) {
V_40 = F_77 ( sizeof( * V_40 ) , V_358 ) ;
if ( V_40 == NULL )
return - V_359 ;
F_10 ( V_40 ) ;
if ( V_61 -> V_78 -> V_5 < V_307 ) {
V_40 -> V_29 = V_61 -> V_78 -> V_360 . V_361 . V_362 ;
V_40 -> V_27 = V_61 -> V_78 -> V_360 . V_361 . V_363 ;
V_40 -> V_36 = V_61 -> V_78 -> V_360 . V_361 . V_364 ;
} else if ( V_61 -> V_78 -> V_5 <= V_365 ) {
V_40 -> V_29 = V_61 -> V_78 -> V_360 . V_366 . V_362 ;
V_40 -> V_27 = V_61 -> V_78 -> V_360 . V_366 . V_363 ;
V_40 -> V_36 = V_61 -> V_78 -> V_360 . V_366 . V_364 ;
}
V_61 -> V_40 = V_40 ;
}
do {
V_77 = F_32 ( V_61 , & V_94 , V_61 -> V_95 ) ;
if ( V_77 ) {
F_78 ( V_61 -> V_40 ) ;
V_61 -> V_40 = NULL ;
return V_77 ;
}
V_61 -> V_95 += V_94 . V_102 + 2 ;
switch ( V_94 . type ) {
case V_104 :
V_77 = F_49 ( V_61 , & V_94 ) ;
break;
case V_108 :
break;
case V_106 :
V_77 = F_73 ( V_61 , & V_94 ) ;
break;
default:
F_33 ( L_74 , V_94 . type ) ;
F_78 ( V_61 -> V_40 ) ;
V_61 -> V_40 = NULL ;
return - V_17 ;
}
if ( V_77 ) {
F_78 ( V_61 -> V_40 ) ;
V_61 -> V_40 = NULL ;
return V_77 ;
}
} while ( V_61 -> V_95 < V_61 -> V_98 [ V_61 -> V_99 ] . V_101 );
#if 0
for (r = 0; r < p->ib->length_dw; r++) {
printk(KERN_INFO "%05d 0x%08X\n", r, p->ib->ptr[r]);
mdelay(1);
}
#endif
F_78 ( V_61 -> V_40 ) ;
V_61 -> V_40 = NULL ;
return 0 ;
}
static int F_79 ( struct V_60 * V_61 )
{
if ( V_61 -> V_113 == - 1 ) {
return 0 ;
}
V_61 -> V_116 = F_77 ( sizeof( struct V_109 ) , V_358 ) ;
if ( V_61 -> V_116 == NULL ) {
return - V_359 ;
}
return 0 ;
}
static void F_80 ( struct V_60 * V_367 , int error )
{
unsigned V_41 ;
F_78 ( V_367 -> V_116 ) ;
for ( V_41 = 0 ; V_41 < V_367 -> V_368 ; V_41 ++ ) {
F_78 ( V_367 -> V_98 [ V_41 ] . V_119 ) ;
F_78 ( V_367 -> V_98 [ V_41 ] . V_369 [ 0 ] ) ;
F_78 ( V_367 -> V_98 [ V_41 ] . V_369 [ 1 ] ) ;
}
F_78 ( V_367 -> V_98 ) ;
F_78 ( V_367 -> V_370 ) ;
}
int F_81 ( struct V_371 * V_71 , void * V_372 , struct V_373 * V_374 ,
unsigned V_5 , T_1 * V_69 , int * V_375 )
{
struct V_60 V_367 ;
struct V_96 * V_97 ;
struct V_376 V_377 ;
struct V_39 * V_40 ;
int V_77 ;
V_40 = F_77 ( sizeof( * V_40 ) , V_358 ) ;
if ( V_40 == NULL )
return - V_359 ;
F_10 ( V_40 ) ;
F_82 ( V_71 , & V_40 -> V_29 , & V_40 -> V_27 , & V_40 -> V_36 ) ;
memset ( & V_367 , 0 , sizeof( struct V_60 ) ) ;
V_367 . V_374 = V_374 ;
V_367 . V_71 = & V_71 -> V_378 -> V_71 ;
V_367 . V_78 = NULL ;
V_367 . V_5 = V_5 ;
V_367 . V_69 = & V_377 ;
V_367 . V_40 = V_40 ;
V_377 . V_70 = V_69 ;
V_77 = F_83 ( & V_367 , V_372 ) ;
if ( V_77 ) {
F_33 ( L_75 ) ;
F_80 ( & V_367 , V_77 ) ;
return V_77 ;
}
V_77 = F_79 ( & V_367 ) ;
if ( V_77 ) {
F_33 ( L_76 ) ;
F_80 ( & V_367 , V_77 ) ;
return V_77 ;
}
V_97 = & V_367 . V_98 [ V_367 . V_99 ] ;
V_367 . V_69 -> V_101 = V_97 -> V_101 ;
* V_375 = V_367 . V_69 -> V_101 ;
V_77 = F_76 ( & V_367 ) ;
if ( V_77 ) {
F_33 ( L_77 ) ;
F_80 ( & V_367 , V_77 ) ;
return V_77 ;
}
V_77 = F_84 ( & V_367 ) ;
if ( V_77 ) {
F_33 ( L_77 ) ;
F_80 ( & V_367 , V_77 ) ;
return V_77 ;
}
F_80 ( & V_367 , V_77 ) ;
return V_77 ;
}
void F_85 ( void )
{
F_51 = & F_40 ;
}
