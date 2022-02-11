static T_1 F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_3 ) {
case V_7 :
* V_4 = true ;
break;
case V_8 :
* V_4 = V_6 -> V_9 ;
break;
case V_10 :
* V_4 = 1 << F_3 ( V_6 -> V_11 -> V_2 ) ;
break;
default:
* V_4 = false ;
break;
}
return 0 ;
}
static T_1 F_4 ( struct V_1 * V_12 )
{
struct V_5 * V_6 = F_2 ( V_12 ) ;
return V_6 -> V_13 . V_14 ;
}
static void F_5 ( struct V_1 * V_12 , T_1 V_15 )
{
struct V_5 * V_6 = F_2 ( V_12 ) ;
V_6 -> V_13 . V_14 = V_15 ;
}
static void F_6 ( struct V_1 * V_12 , int V_16 ,
T_1 * V_17 )
{
struct V_5 * V_6 = F_2 ( V_12 ) ;
* V_17 = V_6 -> V_13 . V_18 [ V_16 ] ;
}
static void F_7 ( struct V_1 * V_12 , int V_16 ,
T_1 V_17 )
{
struct V_5 * V_6 = F_2 ( V_12 ) ;
V_6 -> V_13 . V_18 [ V_16 ] = V_17 ;
V_6 -> V_13 . V_14 = true ;
}
static int F_8 ( struct V_1 * V_12 , int V_19 , T_1 * V_20 )
{
struct V_5 * V_6 = F_2 ( V_12 ) ;
if ( ! ( V_6 -> V_21 & V_22 ) )
return - V_23 ;
if ( V_19 == V_24 )
* V_20 = F_3 ( V_6 -> V_11 -> V_2 ) ;
else
* V_20 = 0 ;
return 0 ;
}
static T_1 F_9 ( struct V_1 * V_12 )
{
struct V_5 * V_6 = F_2 ( V_12 ) ;
struct V_25 * V_11 = V_6 -> V_11 ;
if ( ! ( V_6 -> V_9 & V_26 ) )
return 1 ;
if ( V_6 -> V_13 . V_14 ) {
int V_27 ;
V_6 -> V_28 -> V_29 = 0 ;
V_6 -> V_28 -> V_30 = 0 ;
for ( V_27 = 0 ; V_27 < V_31 ; V_27 ++ ) {
T_1 V_32 = 1 << V_27 ;
switch ( V_6 -> V_13 . V_18 [ V_27 ] ) {
case V_33 :
V_6 -> V_28 -> V_34 &= ~ V_32 ;
V_6 -> V_28 -> V_35 &= ~ V_32 ;
break;
case V_36 :
V_6 -> V_28 -> V_34 |= V_32 ;
V_6 -> V_28 -> V_35 |= V_32 ;
break;
case V_37 :
V_6 -> V_28 -> V_34 |= V_32 ;
V_6 -> V_28 -> V_35 &= ~ V_32 ;
break;
case V_38 :
V_6 -> V_28 -> V_34 &= ~ V_32 ;
V_6 -> V_28 -> V_35 |= V_32 ;
break;
default:
break;
}
}
F_10 ( V_39 , V_6 , L_1 ) ;
} else {
V_6 -> V_28 -> V_29 = 1 ;
V_6 -> V_28 -> V_30 = 1 ;
F_10 ( V_39 , V_6 , L_2 ) ;
}
if ( F_11 ( V_11 -> V_2 , V_6 -> V_40 ,
V_6 -> V_41 + V_42 ,
V_6 -> V_28 -> V_30 ,
V_6 -> V_28 -> V_34 ,
V_6 -> V_28 -> V_29 ,
V_6 -> V_28 -> V_35 ) ) {
F_12 ( V_6 , L_3 ) ;
return 1 ;
}
return 0 ;
}
static T_1 F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_21 & V_22 )
return V_43 ;
return V_44 ;
}
static T_1 F_14 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_45 = 0 ;
if ( ! ( V_6 -> V_9 & V_26 ) )
return 1 ;
if ( ! ! ( V_15 ) == ! ! ( V_6 -> V_21 & V_22 ) )
return 0 ;
if ( V_15 ) {
V_6 -> V_21 |= V_22 ;
V_45 = V_46 ;
} else {
V_6 -> V_21 &= ~ V_22 ;
}
if ( F_15 ( V_2 , V_45 ) )
return 1 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_12 , T_1 V_47 , T_2 V_48 )
{
struct V_5 * V_6 = F_2 ( V_12 ) ;
struct V_49 V_50 = {
. V_51 = V_47 ,
. V_52 = V_48 ,
} ;
if ( ! ( V_6 -> V_9 & V_26 ) )
return 0 ;
return F_17 ( V_12 , & V_50 ) ;
}
static int F_18 ( struct V_1 * V_12 , T_1 V_47 ,
T_2 V_48 , T_1 V_53 )
{
struct V_5 * V_6 = F_2 ( V_12 ) ;
struct V_49 V_50 ;
if ( ! ( V_6 -> V_9 & V_26 ) )
return - V_23 ;
memset ( & V_50 , 0 , sizeof( struct V_49 ) ) ;
V_50 . V_51 = V_47 ;
V_50 . V_52 = V_48 ;
V_50 . V_16 = V_53 ;
return F_19 ( V_12 , & V_50 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_54 * V_56 = & V_6 -> V_55 ;
if ( ! V_56 )
return - V_23 ;
V_55 -> V_57 = V_46 ;
V_55 -> V_58 = V_56 -> V_58 ;
memcpy ( V_55 -> V_59 , V_56 -> V_59 , sizeof( V_55 -> V_59 ) ) ;
memcpy ( V_55 -> V_60 , V_56 -> V_60 , sizeof( V_55 -> V_60 ) ) ;
memcpy ( V_55 -> V_61 , V_56 -> V_61 , sizeof( V_55 -> V_61 ) ) ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 , struct V_54 * V_55 )
{
int V_62 ;
int V_63 = 0 ;
int V_64 = 0 ;
for ( V_62 = 0 ; V_62 < V_46 ; V_62 ++ ) {
if ( V_55 -> V_61 [ V_62 ] >= V_65 ) {
F_12 ( V_6 , L_4 ,
V_62 , V_55 -> V_61 [ V_62 ] ) ;
return - V_23 ;
}
switch ( V_55 -> V_60 [ V_62 ] ) {
case V_66 :
break;
case V_67 :
V_64 = 1 ;
V_63 += V_55 -> V_59 [ V_62 ] ;
break;
default:
F_12 ( V_6 , L_5 ,
V_62 , V_55 -> V_60 [ V_62 ] ) ;
return - V_68 ;
}
}
if ( V_64 && V_63 != V_69 ) {
F_12 ( V_6 , L_6 ,
V_63 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_22 ( struct V_5 * V_6 ,
struct V_54 * V_55 , T_2 * V_70 )
{
struct V_25 * V_11 = V_6 -> V_11 ;
int V_71 = 0 ;
int V_62 ;
T_3 V_59 [ V_46 ] = { 0 } ;
T_3 V_72 [ V_46 ] = { 0 } ;
V_55 = V_55 ? : & V_6 -> V_55 ;
V_70 = V_70 ? : V_6 -> V_73 ;
for ( V_62 = V_46 - 1 ; V_62 >= 0 ; V_62 -- ) {
switch ( V_55 -> V_60 [ V_62 ] ) {
case V_66 :
V_72 [ V_62 ] = V_71 ++ ;
V_59 [ V_62 ] = V_69 ;
break;
case V_67 :
V_72 [ V_62 ] = V_74 ;
V_59 [ V_62 ] = V_55 -> V_59 [ V_62 ] ? : V_75 ;
break;
}
}
return F_23 ( V_11 -> V_2 , V_6 -> V_40 , V_59 , V_72 ,
V_70 ) ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_25 * V_11 = V_6 -> V_11 ;
int V_76 ;
V_76 = F_21 ( V_6 , V_55 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_25 ( V_11 -> V_2 , V_6 -> V_40 , V_55 -> V_61 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_22 ( V_6 , V_55 , NULL ) ;
if ( V_76 )
return V_76 ;
memcpy ( & V_6 -> V_55 , V_55 , sizeof( V_6 -> V_55 ) ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_78 -> V_79 = V_46 ;
V_78 -> V_80 = V_6 -> V_28 -> V_34 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_81 * V_28 = V_6 -> V_28 ;
struct V_25 * V_11 = V_6 -> V_11 ;
int V_76 ;
F_10 ( V_39 , V_6 , L_7 ,
V_78 -> V_79 ,
V_78 -> V_80 ,
V_78 -> V_82 ,
V_78 -> V_83 ) ;
V_28 -> V_29 = ! V_78 -> V_80 ;
V_28 -> V_30 = ! V_78 -> V_80 ;
V_28 -> V_35 = V_78 -> V_80 ;
V_28 -> V_34 = V_78 -> V_80 ;
V_76 = F_11 ( V_11 -> V_2 , V_6 -> V_40 ,
V_6 -> V_41 + V_42 ,
V_28 -> V_30 ,
V_28 -> V_34 ,
V_28 -> V_29 ,
V_28 -> V_35 ) ;
if ( V_76 )
F_12 ( V_6 , L_3 ) ;
else
F_28 ( V_11 -> V_2 , & V_6 -> V_84 ,
V_28 -> V_35 , V_28 -> V_29 ,
V_28 -> V_34 , V_28 -> V_30 ) ;
return V_76 ;
}
static T_1 F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_9 ;
}
static T_1 F_30 ( struct V_1 * V_2 , T_1 V_85 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_54 V_55 = { 0 } ;
struct V_77 V_78 = { 0 } ;
if ( V_85 == V_6 -> V_9 )
return 0 ;
if ( ( V_85 & V_86 ) ||
( ( V_85 & V_87 ) &&
( V_85 & V_26 ) ) ||
! ( V_85 & V_88 ) )
goto V_76;
V_6 -> V_9 = V_85 ;
V_55 . V_57 = V_46 ;
V_78 . V_79 = V_46 ;
if ( V_85 & V_87 ) {
if ( F_24 ( V_2 , & V_55 ) )
goto V_76;
if ( F_27 ( V_2 , & V_78 ) )
goto V_76;
} else if ( V_85 & V_26 ) {
if ( F_9 ( V_2 ) )
goto V_76;
} else {
if ( F_24 ( V_2 , & V_55 ) )
goto V_76;
if ( F_27 ( V_2 , & V_78 ) )
goto V_76;
if ( F_15 ( V_2 , 0 ) )
goto V_76;
}
return 0 ;
V_76:
return 1 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_89 * V_73 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_46 ; V_62 ++ )
V_73 -> V_90 [ V_62 ] =
V_6 -> V_73 [ V_62 ] * V_91 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_89 * V_73 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_92 [ V_46 ] ;
int V_62 , V_76 ;
for ( V_62 = 0 ; V_62 < V_46 ; V_62 ++ ) {
V_92 [ V_62 ] = F_33 ( V_73 -> V_90 [ V_62 ] +
V_91 - 1 ,
V_91 ) ;
}
V_76 = F_22 ( V_6 , NULL , V_92 ) ;
if ( V_76 )
return V_76 ;
memcpy ( V_6 -> V_73 , V_92 , sizeof( V_6 -> V_73 ) ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_95 * V_96 ;
struct V_97 * V_98 = NULL ;
T_4 V_99 = 0 ;
T_5 V_100 = 0 ;
int V_62 , V_76 ;
if ( ! ( V_6 -> V_11 -> V_2 -> V_101 . V_102 & V_103 ) )
return - V_68 ;
V_98 = F_35 ( V_6 -> V_11 -> V_2 ) ;
if ( F_36 ( V_98 ) )
return - V_104 ;
V_96 =
(struct V_95 * )
V_98 -> V_105 ;
for ( V_62 = 0 ; V_62 < V_46 ; V_62 ++ ) {
V_100 = V_6 -> V_40 | ( ( 1 << V_62 ) << 8 ) |
( V_106 << 16 ) ;
V_76 = F_37 ( V_6 -> V_11 -> V_2 , V_99 ,
V_98 -> V_107 ,
V_100 , V_108 ,
V_109 ,
V_110 ,
V_111 ) ;
if ( V_76 ) {
F_38 ( V_6 -> V_11 -> V_2 , V_98 ) ;
return V_76 ;
}
V_94 -> V_112 [ V_62 ] =
F_39 ( V_96 -> V_113 ) >> V_114 ;
V_94 -> V_115 [ V_62 ] =
F_39 ( V_96 -> V_115 ) ;
V_94 -> V_116 [ V_62 ] =
F_39 ( V_96 -> V_116 ) ;
V_94 -> V_117 [ V_62 ] =
F_39 ( V_96 -> V_117 ) ;
V_94 -> V_118 [ V_62 ] =
F_39 ( V_96 -> V_118 ) ;
V_94 -> V_119 [ V_62 ] =
F_39 ( V_96 -> V_119 ) ;
V_94 -> V_120 [ V_62 ] =
F_39 ( V_96 -> V_120 ) ;
V_94 -> V_121 [ V_62 ] =
F_39 ( V_96 -> V_121 ) ;
V_94 -> V_122 [ V_62 ] =
F_39 ( V_96 -> V_122 ) ;
V_94 -> V_123 [ V_62 ] =
F_39 ( V_96 -> V_123 ) ;
V_94 -> V_124 [ V_62 ] =
F_39 ( V_96 -> V_124 ) ;
V_94 -> V_125 [ V_62 ] =
V_6 -> V_126 [ V_62 ] ;
}
F_38 ( V_6 -> V_11 -> V_2 , V_98 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_95 * V_96 ;
struct V_97 * V_127 = NULL ;
T_4 V_99 = 0 ;
T_5 V_100 = 0 ;
int V_62 , V_76 ;
#define F_41 0xc0000000
#define F_42 0xffc00000
if ( ! ( V_6 -> V_11 -> V_2 -> V_101 . V_102 & V_103 ) )
return - V_68 ;
V_127 = F_35 ( V_6 -> V_11 -> V_2 ) ;
if ( F_36 ( V_127 ) )
return - V_104 ;
V_99 = V_127 -> V_107 ;
V_96 =
(struct V_95 * ) V_127 -> V_105 ;
for ( V_62 = 0 ; V_62 < V_46 ; V_62 ++ ) {
V_100 = V_6 -> V_40 | ( ( 1 << V_62 ) << 8 ) |
( V_106 << 16 ) ;
V_96 -> V_128 = F_43 (
F_41 ) ;
V_96 -> V_129 = F_43 ( F_42 ) ;
V_96 -> V_113 = F_43 ( V_94 -> V_112 [ V_62 ] << V_114 ) ;
V_96 -> V_115 = F_43 ( V_94 -> V_115 [ V_62 ] ) ;
V_96 -> V_116 = F_43 ( V_94 -> V_116 [ V_62 ] ) ;
V_96 -> V_117 = F_43 ( V_94 -> V_117 [ V_62 ] ) ;
V_96 -> V_118 = F_43 ( V_94 -> V_118 [ V_62 ] ) ;
V_96 -> V_119 = F_43 ( V_94 -> V_119 [ V_62 ] ) ;
V_96 -> V_120 = F_43 ( V_94 -> V_120 [ V_62 ] ) ;
V_96 -> V_121 = F_43 ( V_94 -> V_121 [ V_62 ] ) ;
V_96 -> V_122 = F_43 ( V_94 -> V_122 [ V_62 ] ) ;
V_96 -> V_123 = F_43 ( V_94 -> V_123 [ V_62 ] ) ;
V_96 -> V_124 = F_43 ( V_94 -> V_124 [ V_62 ] ) ;
V_6 -> V_126 [ V_62 ] = V_94 -> V_125 [ V_62 ] ;
if ( V_94 -> V_125 [ V_62 ] == V_130 )
V_96 -> V_113 |= F_43 ( 1 << V_131 ) ;
V_76 = F_44 ( V_6 -> V_11 -> V_2 , V_99 , V_100 ,
V_132 ,
V_109 ,
V_110 ,
V_111 ) ;
if ( V_76 ) {
F_38 ( V_6 -> V_11 -> V_2 , V_127 ) ;
return V_76 ;
}
}
F_38 ( V_6 -> V_11 -> V_2 , V_127 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_133 * V_134 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_135 * V_136 ;
struct V_97 * V_98 = NULL ;
T_4 V_99 = 0 ;
T_5 V_100 = 0 ;
int V_62 , V_76 ;
if ( ! ( V_6 -> V_11 -> V_2 -> V_101 . V_102 & V_103 ) )
return - V_68 ;
V_98 = F_35 ( V_6 -> V_11 -> V_2 ) ;
if ( F_36 ( V_98 ) )
return - V_104 ;
V_136 =
(struct V_135 * )
V_98 -> V_105 ;
for ( V_62 = 0 ; V_62 < V_46 ; V_62 ++ ) {
V_100 = V_6 -> V_40 | ( ( 1 << V_62 ) << 8 ) |
( V_106 << 16 ) ;
V_76 = F_37 ( V_6 -> V_11 -> V_2 , V_99 ,
V_98 -> V_107 , V_100 ,
V_137 ,
V_109 ,
V_110 ,
V_111 ) ;
if ( V_76 ) {
F_38 ( V_6 -> V_11 -> V_2 , V_98 ) ;
return V_76 ;
}
V_134 -> V_138 [ V_62 ] =
F_46 ( V_136 -> V_138 ) ;
V_134 -> V_139 [ V_62 ] =
F_39 ( V_136 -> V_139 ) ;
}
F_38 ( V_6 -> V_11 -> V_2 , V_98 ) ;
return 0 ;
}
