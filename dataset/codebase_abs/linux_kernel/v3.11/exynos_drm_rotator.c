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
F_10 ( L_3 ) ;
return - V_50 ;
}
V_30 = V_55 -> V_30 ;
V_31 = V_55 -> V_31 ;
F_11 ( V_2 , V_29 , & V_30 , & V_31 ) ;
V_4 = F_19 ( V_31 ) | F_20 ( V_30 ) ;
F_3 ( V_4 , V_56 ) ;
V_4 = F_21 ( V_53 -> V_57 ) | F_22 ( V_53 -> V_58 ) ;
F_3 ( V_4 , V_59 ) ;
V_4 = F_23 ( V_53 -> V_60 ) | F_24 ( V_53 -> V_61 ) ;
F_3 ( V_4 , V_62 ) ;
return 0 ;
}
static int F_25 ( struct V_45 * V_46 ,
struct V_63 * V_64 ,
T_1 V_23 , enum V_65 V_66 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
T_3 V_67 [ V_68 ] ;
T_1 V_4 , V_29 , V_30 , V_31 ;
int V_69 ;
V_2 -> V_25 [ V_70 ] = V_23 ;
switch ( V_66 ) {
case V_71 :
F_26 (i)
V_67 [ V_69 ] = V_64 -> V_72 [ V_69 ] ;
V_29 = F_4 ( V_2 ) ;
if ( ! F_17 ( V_29 ) ) {
F_10 ( L_3 ) ;
return - V_50 ;
}
if ( ( V_29 == V_48 ) &&
! V_67 [ V_73 ] ) {
V_4 = F_2 ( V_56 ) ;
V_30 = F_27 ( V_4 ) ;
V_31 = F_28 ( V_4 ) ;
V_67 [ V_73 ] =
V_67 [ V_74 ] + V_30 * V_31 ;
}
F_26 (i)
F_3 ( V_67 [ V_69 ] , F_29 ( V_69 ) ) ;
break;
case V_75 :
F_26 (i)
F_3 ( 0x0 , F_29 ( V_69 ) ) ;
break;
default:
break;
}
return 0 ;
}
static int F_30 ( struct V_45 * V_46 ,
enum V_76 V_77 ,
enum V_78 V_79 , bool * V_51 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
T_1 V_4 ;
V_4 = F_2 ( V_7 ) ;
V_4 &= ~ V_80 ;
switch ( V_79 ) {
case V_81 :
V_4 |= V_82 ;
break;
case V_83 :
V_4 |= V_84 ;
break;
default:
break;
}
V_4 &= ~ V_85 ;
switch ( V_77 ) {
case V_86 :
V_4 |= V_87 ;
break;
case V_88 :
V_4 |= V_89 ;
break;
case V_90 :
V_4 |= V_91 ;
break;
default:
break;
}
F_3 ( V_4 , V_7 ) ;
if ( ( V_77 == V_86 ) ||
( V_77 == V_90 ) )
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
F_10 ( L_3 ) ;
return - V_50 ;
}
V_30 = V_55 -> V_30 ;
V_31 = V_55 -> V_31 ;
F_11 ( V_2 , V_29 , & V_30 , & V_31 ) ;
V_4 = F_19 ( V_31 ) | F_20 ( V_30 ) ;
F_3 ( V_4 , V_92 ) ;
V_4 = F_21 ( V_53 -> V_57 ) | F_22 ( V_53 -> V_58 ) ;
F_3 ( V_4 , V_93 ) ;
return 0 ;
}
static int F_32 ( struct V_45 * V_46 ,
struct V_63 * V_64 ,
T_1 V_23 , enum V_65 V_66 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
T_3 V_67 [ V_68 ] ;
T_1 V_4 , V_29 , V_30 , V_31 ;
int V_69 ;
V_2 -> V_25 [ V_24 ] = V_23 ;
switch ( V_66 ) {
case V_71 :
F_26 (i)
V_67 [ V_69 ] = V_64 -> V_72 [ V_69 ] ;
V_29 = F_4 ( V_2 ) ;
if ( ! F_17 ( V_29 ) ) {
F_10 ( L_3 ) ;
return - V_50 ;
}
if ( ( V_29 == V_48 ) &&
! V_67 [ V_73 ] ) {
V_4 = F_2 ( V_92 ) ;
V_30 = F_27 ( V_4 ) ;
V_31 = F_28 ( V_4 ) ;
V_67 [ V_73 ] =
V_67 [ V_74 ] + V_30 * V_31 ;
}
F_26 (i)
F_3 ( V_67 [ V_69 ] , F_33 ( V_69 ) ) ;
break;
case V_75 :
F_26 (i)
F_3 ( 0x0 , F_33 ( V_69 ) ) ;
break;
default:
break;
}
return 0 ;
}
static int F_34 ( struct V_16 * V_17 )
{
struct V_94 * V_95 ;
V_95 = F_35 ( V_17 -> V_46 , sizeof( * V_95 ) , V_96 ) ;
if ( ! V_95 ) {
F_10 ( L_4 ) ;
return - V_97 ;
}
V_95 -> V_98 = 1 ;
V_95 -> V_79 = ( 1 << V_81 ) |
( 1 << V_83 ) ;
V_95 -> V_77 = ( 1 << V_99 ) |
( 1 << V_86 ) |
( 1 << V_88 ) |
( 1 << V_90 ) ;
V_95 -> V_100 = 0 ;
V_95 -> V_101 = 0 ;
V_95 -> V_102 = 0 ;
V_17 -> V_95 = V_95 ;
return 0 ;
}
static inline bool F_36 ( T_1 V_29 )
{
switch ( V_29 ) {
case V_49 :
case V_47 :
return true ;
default:
F_37 ( L_5 ) ;
return false ;
}
}
static inline bool F_38 ( enum V_78 V_79 )
{
switch ( V_79 ) {
case V_103 :
case V_81 :
case V_83 :
case V_104 :
return true ;
default:
F_37 ( L_6 ) ;
return false ;
}
}
static int F_39 ( struct V_45 * V_46 ,
struct V_105 * V_106 )
{
struct V_107 * V_108 =
& V_106 -> V_109 [ V_70 ] ;
struct V_107 * V_110 =
& V_106 -> V_109 [ V_24 ] ;
struct V_52 * V_111 = & V_108 -> V_53 ;
struct V_52 * V_112 = & V_110 -> V_53 ;
struct V_54 * V_113 = & V_108 -> V_55 ;
struct V_54 * V_114 = & V_110 -> V_55 ;
bool V_51 = false ;
if ( V_108 -> V_29 != V_110 -> V_29 ) {
F_37 ( L_7 ) ;
return - V_50 ;
}
if ( ! F_36 ( V_110 -> V_29 ) ) {
F_37 ( L_8 ) ;
return - V_50 ;
}
if ( V_108 -> V_77 != V_99 ) {
F_37 ( L_9 ) ;
return - V_50 ;
}
switch ( V_110 -> V_77 ) {
case V_86 :
case V_90 :
V_51 = true ;
case V_99 :
case V_88 :
break;
default:
F_37 ( L_10 ) ;
return - V_50 ;
}
if ( V_108 -> V_79 != V_103 ) {
F_37 ( L_11 ) ;
return - V_50 ;
}
if ( ! F_38 ( V_110 -> V_79 ) ) {
F_37 ( L_6 ) ;
return - V_50 ;
}
if ( ( V_111 -> V_58 + V_111 -> V_61 > V_113 -> V_30 ) ||
( V_111 -> V_57 + V_111 -> V_60 > V_113 -> V_31 ) ) {
F_37 ( L_12 ) ;
return - V_50 ;
}
if ( V_51 ) {
if ( ( V_112 -> V_58 + V_112 -> V_60 > V_114 -> V_31 ) ||
( V_112 -> V_57 + V_112 -> V_61 > V_114 -> V_30 ) ) {
F_37 ( L_13 ) ;
return - V_50 ;
}
if ( ( V_111 -> V_61 != V_112 -> V_60 ) || ( V_111 -> V_60 != V_112 -> V_61 ) ) {
F_37 ( L_14 ) ;
return - V_50 ;
}
} else {
if ( ( V_112 -> V_58 + V_112 -> V_61 > V_114 -> V_30 ) ||
( V_112 -> V_57 + V_112 -> V_60 > V_114 -> V_31 ) ) {
F_37 ( L_13 ) ;
return - V_50 ;
}
if ( ( V_111 -> V_61 != V_112 -> V_61 ) || ( V_111 -> V_60 != V_112 -> V_60 ) ) {
F_37 ( L_14 ) ;
return - V_50 ;
}
}
return 0 ;
}
static int F_40 ( struct V_45 * V_46 , enum V_115 V_116 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
T_1 V_4 ;
if ( V_2 -> V_117 ) {
F_10 ( L_15 ) ;
return - V_118 ;
}
if ( V_116 != V_119 ) {
F_10 ( L_16 , V_116 ) ;
return - V_50 ;
}
F_1 ( V_2 , true ) ;
V_4 = F_2 ( V_7 ) ;
V_4 |= V_120 ;
F_3 ( V_4 , V_7 ) ;
return 0 ;
}
static int F_41 ( struct V_121 * V_122 )
{
struct V_45 * V_46 = & V_122 -> V_46 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
int V_123 ;
V_2 = F_35 ( V_46 , sizeof( * V_2 ) , V_96 ) ;
if ( ! V_2 ) {
F_42 ( V_46 , L_17 ) ;
return - V_97 ;
}
V_2 -> V_33 = (struct V_32 * )
F_43 ( V_122 ) -> V_124 ;
V_2 -> V_125 = F_44 ( V_122 , V_126 , 0 ) ;
V_2 -> V_127 = F_45 ( V_46 , V_2 -> V_125 ) ;
if ( F_46 ( V_2 -> V_127 ) )
return F_47 ( V_2 -> V_127 ) ;
V_2 -> V_14 = F_48 ( V_122 , 0 ) ;
if ( V_2 -> V_14 < 0 ) {
F_42 ( V_46 , L_18 ) ;
return V_2 -> V_14 ;
}
V_123 = F_49 ( V_46 , V_2 -> V_14 , NULL ,
F_7 , V_128 , L_19 , V_2 ) ;
if ( V_123 < 0 ) {
F_42 ( V_46 , L_20 ) ;
return V_123 ;
}
V_2 -> clock = F_50 ( V_46 , L_21 ) ;
if ( F_46 ( V_2 -> clock ) ) {
F_42 ( V_46 , L_22 ) ;
return F_47 ( V_2 -> clock ) ;
}
F_51 ( V_46 ) ;
V_17 = & V_2 -> V_17 ;
V_17 -> V_46 = V_46 ;
V_17 -> V_129 [ V_70 ] = & V_130 ;
V_17 -> V_129 [ V_24 ] = & V_131 ;
V_17 -> V_132 = F_39 ;
V_17 -> V_133 = F_40 ;
V_123 = F_34 ( V_17 ) ;
if ( V_123 < 0 ) {
F_42 ( V_46 , L_23 ) ;
goto V_134;
}
F_37 ( L_24 , ( int ) V_17 ) ;
F_52 ( V_122 , V_2 ) ;
V_123 = F_53 ( V_17 ) ;
if ( V_123 < 0 ) {
F_42 ( V_46 , L_25 ) ;
goto V_134;
}
F_54 ( V_46 , L_26 ) ;
return 0 ;
V_134:
F_55 ( V_46 ) ;
return V_123 ;
}
static int F_56 ( struct V_121 * V_122 )
{
struct V_45 * V_46 = & V_122 -> V_46 ;
struct V_1 * V_2 = F_16 ( V_46 ) ;
struct V_16 * V_17 = & V_2 -> V_17 ;
F_57 ( V_17 ) ;
F_55 ( V_46 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , bool V_3 )
{
if ( V_3 ) {
F_59 ( V_2 -> clock ) ;
V_2 -> V_117 = false ;
} else {
F_60 ( V_2 -> clock ) ;
V_2 -> V_117 = true ;
}
return 0 ;
}
static int F_61 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
if ( F_62 ( V_46 ) )
return 0 ;
return F_58 ( V_2 , false ) ;
}
static int F_63 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
if ( ! F_62 ( V_46 ) )
return F_58 ( V_2 , true ) ;
return 0 ;
}
static int F_64 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
return F_58 ( V_2 , false ) ;
}
static int F_65 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
return F_58 ( V_2 , true ) ;
}
