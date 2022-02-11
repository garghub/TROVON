static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_4 = F_2 ( V_5 ) ;
if ( V_3 == true )
V_4 |= V_6 ;
else
V_4 &= ~ V_6 ;
F_3 ( V_4 , V_5 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
T_1 V_4 = F_2 ( V_7 ) ;
V_4 &= V_8 ;
return V_4 ;
}
static enum V_9 F_5 ( struct V_1 * V_2 )
{
T_1 V_4 = F_2 ( V_10 ) ;
V_4 = F_6 ( V_4 ) ;
if ( V_4 == V_11 )
return V_12 ;
return V_13 ;
}
static T_2 F_7 ( int V_14 , void * V_15 )
{
struct V_1 * V_2 = V_15 ;
struct V_16 * V_17 = & V_2 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_21 = V_19 -> V_21 ;
enum V_9 V_22 ;
T_1 V_4 ;
V_22 = F_5 ( V_2 ) ;
V_4 = F_2 ( V_10 ) ;
V_4 |= F_8 ( ( T_1 ) V_22 ) ;
F_3 ( V_4 , V_10 ) ;
if ( V_22 == V_12 ) {
V_21 -> V_17 = V_17 ;
V_21 -> V_23 [ V_24 ] =
V_2 -> V_25 [ V_24 ] ;
F_9 ( V_17 -> V_26 ,
(struct V_27 * ) V_21 ) ;
} else
F_10 ( L_1 ) ;
return V_28 ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_29 , T_1 * V_30 ,
T_1 * V_31 )
{
struct V_32 * V_33 = V_2 -> V_33 ;
struct V_34 * V_35 ;
T_1 V_36 , V_4 ;
if ( V_29 == V_37 )
V_35 = & V_33 -> V_38 ;
else
V_35 = & V_33 -> V_39 ;
V_36 = ~ ( ( 1 << V_35 -> V_40 ) - 1 ) ;
V_4 = F_12 ( * V_30 , V_35 -> V_40 , V_36 ) ;
if ( V_4 < V_35 -> V_41 )
* V_30 = F_13 ( V_35 -> V_41 , V_36 ) ;
else if ( V_4 > V_35 -> V_42 )
* V_30 = F_14 ( V_35 -> V_42 , V_36 ) ;
else
* V_30 = V_4 ;
V_4 = F_12 ( * V_31 , V_35 -> V_40 , V_36 ) ;
if ( V_4 < V_35 -> V_43 )
* V_31 = F_13 ( V_35 -> V_43 , V_36 ) ;
else if ( V_4 > V_35 -> V_44 )
* V_31 = F_14 ( V_35 -> V_44 , V_36 ) ;
else
* V_31 = V_4 ;
}
static int F_15 ( struct V_45 * V_46 , T_1 V_29 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
T_1 V_4 ;
V_4 = F_2 ( V_7 ) ;
V_4 &= ~ V_8 ;
switch ( V_29 ) {
case V_47 :
V_4 |= V_48 ;
break;
case V_49 :
V_4 |= V_37 ;
break;
default:
F_10 ( L_2 ) ;
return - V_50 ;
}
F_3 ( V_4 , V_7 ) ;
return 0 ;
}
static inline bool F_17 ( T_1 V_29 )
{
if ( ( V_29 == V_48 ) ||
( V_29 == V_37 ) )
return true ;
return false ;
}
static int F_18 ( struct V_45 * V_46 , int V_51 ,
struct V_52 * V_53 ,
struct V_54 * V_55 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
T_1 V_29 , V_30 , V_31 ;
T_1 V_4 ;
V_29 = F_4 ( V_2 ) ;
if ( ! F_17 ( V_29 ) ) {
F_10 ( L_3 , V_56 ) ;
return - V_50 ;
}
V_30 = V_55 -> V_30 ;
V_31 = V_55 -> V_31 ;
F_11 ( V_2 , V_29 , & V_30 , & V_31 ) ;
V_4 = F_19 ( V_31 ) | F_20 ( V_30 ) ;
F_3 ( V_4 , V_57 ) ;
V_4 = F_21 ( V_53 -> V_58 ) | F_22 ( V_53 -> V_59 ) ;
F_3 ( V_4 , V_60 ) ;
V_4 = F_23 ( V_53 -> V_61 ) | F_24 ( V_53 -> V_62 ) ;
F_3 ( V_4 , V_63 ) ;
return 0 ;
}
static int F_25 ( struct V_45 * V_46 ,
struct V_64 * V_65 ,
T_1 V_23 , enum V_66 V_67 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
T_3 V_68 [ V_69 ] ;
T_1 V_4 , V_29 , V_30 , V_31 ;
int V_70 ;
V_2 -> V_25 [ V_71 ] = V_23 ;
switch ( V_67 ) {
case V_72 :
F_26 (i)
V_68 [ V_70 ] = V_65 -> V_73 [ V_70 ] ;
V_29 = F_4 ( V_2 ) ;
if ( ! F_17 ( V_29 ) ) {
F_10 ( L_3 , V_56 ) ;
return - V_50 ;
}
if ( ( V_29 == V_48 ) &&
! V_68 [ V_74 ] ) {
V_4 = F_2 ( V_57 ) ;
V_30 = F_27 ( V_4 ) ;
V_31 = F_28 ( V_4 ) ;
V_68 [ V_74 ] =
V_68 [ V_75 ] + V_30 * V_31 ;
}
F_26 (i)
F_3 ( V_68 [ V_70 ] , F_29 ( V_70 ) ) ;
break;
case V_76 :
F_26 (i)
F_3 ( 0x0 , F_29 ( V_70 ) ) ;
break;
default:
break;
}
return 0 ;
}
static int F_30 ( struct V_45 * V_46 ,
enum V_77 V_78 ,
enum V_79 V_80 , bool * V_51 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
T_1 V_4 ;
V_4 = F_2 ( V_7 ) ;
V_4 &= ~ V_81 ;
switch ( V_80 ) {
case V_82 :
V_4 |= V_83 ;
break;
case V_84 :
V_4 |= V_85 ;
break;
default:
break;
}
V_4 &= ~ V_86 ;
switch ( V_78 ) {
case V_87 :
V_4 |= V_88 ;
break;
case V_89 :
V_4 |= V_90 ;
break;
case V_91 :
V_4 |= V_92 ;
break;
default:
break;
}
F_3 ( V_4 , V_7 ) ;
if ( ( V_78 == V_87 ) ||
( V_78 == V_91 ) )
* V_51 = true ;
else
* V_51 = false ;
return 0 ;
}
static int F_31 ( struct V_45 * V_46 , int V_51 ,
struct V_52 * V_53 ,
struct V_54 * V_55 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
T_1 V_4 , V_29 , V_30 , V_31 ;
V_29 = F_4 ( V_2 ) ;
if ( ! F_17 ( V_29 ) ) {
F_10 ( L_3 , V_56 ) ;
return - V_50 ;
}
V_30 = V_55 -> V_30 ;
V_31 = V_55 -> V_31 ;
F_11 ( V_2 , V_29 , & V_30 , & V_31 ) ;
V_4 = F_19 ( V_31 ) | F_20 ( V_30 ) ;
F_3 ( V_4 , V_93 ) ;
V_4 = F_21 ( V_53 -> V_58 ) | F_22 ( V_53 -> V_59 ) ;
F_3 ( V_4 , V_94 ) ;
return 0 ;
}
static int F_32 ( struct V_45 * V_46 ,
struct V_64 * V_65 ,
T_1 V_23 , enum V_66 V_67 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
T_3 V_68 [ V_69 ] ;
T_1 V_4 , V_29 , V_30 , V_31 ;
int V_70 ;
V_2 -> V_25 [ V_24 ] = V_23 ;
switch ( V_67 ) {
case V_72 :
F_26 (i)
V_68 [ V_70 ] = V_65 -> V_73 [ V_70 ] ;
V_29 = F_4 ( V_2 ) ;
if ( ! F_17 ( V_29 ) ) {
F_10 ( L_3 , V_56 ) ;
return - V_50 ;
}
if ( ( V_29 == V_48 ) &&
! V_68 [ V_74 ] ) {
V_4 = F_2 ( V_93 ) ;
V_30 = F_27 ( V_4 ) ;
V_31 = F_28 ( V_4 ) ;
V_68 [ V_74 ] =
V_68 [ V_75 ] + V_30 * V_31 ;
}
F_26 (i)
F_3 ( V_68 [ V_70 ] , F_33 ( V_70 ) ) ;
break;
case V_76 :
F_26 (i)
F_3 ( 0x0 , F_33 ( V_70 ) ) ;
break;
default:
break;
}
return 0 ;
}
static int F_34 ( struct V_16 * V_17 )
{
struct V_95 * V_96 ;
F_35 ( L_4 , V_56 ) ;
V_96 = F_36 ( V_17 -> V_46 , sizeof( * V_96 ) , V_97 ) ;
if ( ! V_96 ) {
F_10 ( L_5 ) ;
return - V_98 ;
}
V_96 -> V_99 = 1 ;
V_96 -> V_80 = ( 1 << V_82 ) |
( 1 << V_84 ) ;
V_96 -> V_78 = ( 1 << V_100 ) |
( 1 << V_87 ) |
( 1 << V_89 ) |
( 1 << V_91 ) ;
V_96 -> V_101 = 0 ;
V_96 -> V_102 = 0 ;
V_96 -> V_103 = 0 ;
V_17 -> V_96 = V_96 ;
return 0 ;
}
static inline bool F_37 ( T_1 V_29 )
{
switch ( V_29 ) {
case V_49 :
case V_47 :
return true ;
default:
F_35 ( L_6 , V_56 ) ;
return false ;
}
}
static inline bool F_38 ( enum V_79 V_80 )
{
switch ( V_80 ) {
case V_104 :
case V_82 :
case V_84 :
case V_105 :
return true ;
default:
F_35 ( L_7 , V_56 ) ;
return false ;
}
}
static int F_39 ( struct V_45 * V_46 ,
struct V_106 * V_107 )
{
struct V_108 * V_109 =
& V_107 -> V_110 [ V_71 ] ;
struct V_108 * V_111 =
& V_107 -> V_110 [ V_24 ] ;
struct V_52 * V_112 = & V_109 -> V_53 ;
struct V_52 * V_113 = & V_111 -> V_53 ;
struct V_54 * V_114 = & V_109 -> V_55 ;
struct V_54 * V_115 = & V_111 -> V_55 ;
bool V_51 = false ;
if ( V_109 -> V_29 != V_111 -> V_29 ) {
F_35 ( L_8 , V_56 ) ;
return - V_50 ;
}
if ( ! F_37 ( V_111 -> V_29 ) ) {
F_35 ( L_9 , V_56 ) ;
return - V_50 ;
}
if ( V_109 -> V_78 != V_100 ) {
F_35 ( L_10 ,
V_56 ) ;
return - V_50 ;
}
switch ( V_111 -> V_78 ) {
case V_87 :
case V_91 :
V_51 = true ;
case V_100 :
case V_89 :
break;
default:
F_35 ( L_11 , V_56 ) ;
return - V_50 ;
}
if ( V_109 -> V_80 != V_104 ) {
F_35 ( L_12 , V_56 ) ;
return - V_50 ;
}
if ( ! F_38 ( V_111 -> V_80 ) ) {
F_35 ( L_7 , V_56 ) ;
return - V_50 ;
}
if ( ( V_112 -> V_59 + V_112 -> V_62 > V_114 -> V_30 ) ||
( V_112 -> V_58 + V_112 -> V_61 > V_114 -> V_31 ) ) {
F_35 ( L_13 , V_56 ) ;
return - V_50 ;
}
if ( V_51 ) {
if ( ( V_113 -> V_59 + V_113 -> V_61 > V_115 -> V_31 ) ||
( V_113 -> V_58 + V_113 -> V_62 > V_115 -> V_30 ) ) {
F_35 ( L_14 ,
V_56 ) ;
return - V_50 ;
}
if ( ( V_112 -> V_62 != V_113 -> V_61 ) || ( V_112 -> V_61 != V_113 -> V_62 ) ) {
F_35 ( L_15 ,
V_56 ) ;
return - V_50 ;
}
} else {
if ( ( V_113 -> V_59 + V_113 -> V_62 > V_115 -> V_30 ) ||
( V_113 -> V_58 + V_113 -> V_61 > V_115 -> V_31 ) ) {
F_35 ( L_14 ,
V_56 ) ;
return - V_50 ;
}
if ( ( V_112 -> V_62 != V_113 -> V_62 ) || ( V_112 -> V_61 != V_113 -> V_61 ) ) {
F_35 ( L_15 ,
V_56 ) ;
return - V_50 ;
}
}
return 0 ;
}
static int F_40 ( struct V_45 * V_46 , enum V_116 V_117 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
T_1 V_4 ;
if ( V_2 -> V_118 ) {
F_10 ( L_16 ) ;
return - V_119 ;
}
if ( V_117 != V_120 ) {
F_10 ( L_17 , V_117 ) ;
return - V_50 ;
}
F_1 ( V_2 , true ) ;
V_4 = F_2 ( V_7 ) ;
V_4 |= V_121 ;
F_3 ( V_4 , V_7 ) ;
return 0 ;
}
static int F_41 ( struct V_122 * V_123 )
{
struct V_45 * V_46 = & V_123 -> V_46 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
int V_124 ;
V_2 = F_36 ( V_46 , sizeof( * V_2 ) , V_97 ) ;
if ( ! V_2 ) {
F_42 ( V_46 , L_18 ) ;
return - V_98 ;
}
V_2 -> V_33 = (struct V_32 * )
F_43 ( V_123 ) -> V_125 ;
V_2 -> V_126 = F_44 ( V_123 , V_127 , 0 ) ;
V_2 -> V_128 = F_45 ( V_46 , V_2 -> V_126 ) ;
if ( ! V_2 -> V_128 ) {
F_42 ( V_46 , L_19 ) ;
return - V_129 ;
}
V_2 -> V_14 = F_46 ( V_123 , 0 ) ;
if ( V_2 -> V_14 < 0 ) {
F_42 ( V_46 , L_20 ) ;
return V_2 -> V_14 ;
}
V_124 = F_47 ( V_2 -> V_14 , NULL , F_7 ,
V_130 , L_21 , V_2 ) ;
if ( V_124 < 0 ) {
F_42 ( V_46 , L_22 ) ;
return V_124 ;
}
V_2 -> clock = F_48 ( V_46 , L_23 ) ;
if ( F_49 ( V_2 -> clock ) ) {
F_42 ( V_46 , L_24 ) ;
V_124 = F_50 ( V_2 -> clock ) ;
goto V_131;
}
F_51 ( V_46 ) ;
V_17 = & V_2 -> V_17 ;
V_17 -> V_46 = V_46 ;
V_17 -> V_132 [ V_71 ] = & V_133 ;
V_17 -> V_132 [ V_24 ] = & V_134 ;
V_17 -> V_135 = F_39 ;
V_17 -> V_136 = F_40 ;
V_124 = F_34 ( V_17 ) ;
if ( V_124 < 0 ) {
F_42 ( V_46 , L_25 ) ;
goto V_137;
}
F_35 ( L_26 , V_56 , ( int ) V_17 ) ;
F_52 ( V_123 , V_2 ) ;
V_124 = F_53 ( V_17 ) ;
if ( V_124 < 0 ) {
F_42 ( V_46 , L_27 ) ;
goto V_137;
}
F_54 ( V_46 , L_28 ) ;
return 0 ;
V_137:
F_55 ( V_46 , V_17 -> V_96 ) ;
F_56 ( V_46 ) ;
V_131:
F_57 ( V_2 -> V_14 , V_2 ) ;
return V_124 ;
}
static int F_58 ( struct V_122 * V_123 )
{
struct V_45 * V_46 = & V_123 -> V_46 ;
struct V_1 * V_2 = F_16 ( V_46 ) ;
struct V_16 * V_17 = & V_2 -> V_17 ;
F_55 ( V_46 , V_17 -> V_96 ) ;
F_59 ( V_17 ) ;
F_56 ( V_46 ) ;
F_57 ( V_2 -> V_14 , V_2 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , bool V_3 )
{
F_35 ( L_4 , V_56 ) ;
if ( V_3 ) {
F_61 ( V_2 -> clock ) ;
V_2 -> V_118 = false ;
} else {
F_62 ( V_2 -> clock ) ;
V_2 -> V_118 = true ;
}
return 0 ;
}
static int F_63 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
F_35 ( L_4 , V_56 ) ;
if ( F_64 ( V_46 ) )
return 0 ;
return F_60 ( V_2 , false ) ;
}
static int F_65 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
F_35 ( L_4 , V_56 ) ;
if ( ! F_64 ( V_46 ) )
return F_60 ( V_2 , true ) ;
return 0 ;
}
static int F_66 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
F_35 ( L_4 , V_56 ) ;
return F_60 ( V_2 , false ) ;
}
static int F_67 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
F_35 ( L_4 , V_56 ) ;
return F_60 ( V_2 , true ) ;
}
