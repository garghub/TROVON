static void
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_3 = V_3 ;
V_2 -> V_4 . V_5 = F_2 (
( V_6 ) V_2 -> V_3 , 0 ) ;
}
static void
F_3 ( struct V_7 * V_8 )
{
F_4 ( V_8 ) ;
}
static void
F_5 ( struct V_7 * V_8 , enum V_9 V_10 )
{
switch ( V_10 ) {
case V_11 :
if ( V_8 -> V_12 & V_13 ) {
F_6 ( V_8 , V_14 ) ;
F_7 ( V_8 ) ;
} else
F_6 ( V_8 , V_15 ) ;
break;
case V_16 :
F_4 ( V_8 ) ;
break;
case V_17 :
break;
case V_18 :
F_8 ( V_8 ) ;
break;
case V_19 :
V_8 -> V_12 |= V_13 ;
F_9 ( V_8 ) ;
break;
case V_20 :
V_8 -> V_12 &= ~ V_13 ;
F_10 ( V_8 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_12 ( struct V_7 * V_8 )
{
F_9 ( V_8 ) ;
}
static void
V_14 ( struct V_7 * V_8 , enum V_9 V_10 )
{
switch ( V_10 ) {
case V_16 :
case V_17 :
F_6 ( V_8 , F_5 ) ;
break;
case V_18 :
F_8 ( V_8 ) ;
break;
case V_20 :
V_8 -> V_12 &= ~ V_13 ;
F_6 ( V_8 , V_15 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_13 ( struct V_7 * V_8 )
{
if ( ! F_14 ( V_8 ) ) {
F_6 ( V_8 , V_21 ) ;
}
}
static void
V_15 ( struct V_7 * V_8 , enum V_9 V_10 )
{
switch ( V_10 ) {
case V_16 :
F_6 ( V_8 , V_22 ) ;
break;
case V_17 :
F_15 ( V_8 ) ;
F_7 ( V_8 ) ;
F_8 ( V_8 ) ;
F_10 ( V_8 ) ;
F_6 ( V_8 , F_5 ) ;
break;
case V_18 :
break;
case V_19 :
V_8 -> V_12 |= V_13 ;
F_7 ( V_8 ) ;
F_6 ( V_8 , V_23 ) ;
break;
case V_24 :
if ( ! F_14 ( V_8 ) ) {
F_6 ( V_8 , V_21 ) ;
}
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_16 ( struct V_7 * V_8 )
{
F_7 ( V_8 ) ;
F_8 ( V_8 ) ;
F_10 ( V_8 ) ;
}
static void
V_21 ( struct V_7 * V_8 , enum V_9 V_10 )
{
switch ( V_10 ) {
case V_16 :
case V_17 :
F_15 ( V_8 ) ;
F_6 ( V_8 , F_5 ) ;
break;
case V_18 :
F_6 ( V_8 , V_15 ) ;
break;
case V_19 :
V_8 -> V_12 |= V_13 ;
if ( ! F_17 ( V_8 ) )
F_6 ( V_8 , V_14 ) ;
else
F_6 ( V_8 , V_23 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_18 ( struct V_7 * V_8 )
{
}
static void
V_23 ( struct V_7 * V_8 , enum V_9 V_10 )
{
switch ( V_10 ) {
case V_17 :
F_15 ( V_8 ) ;
F_9 ( V_8 ) ;
F_6 ( V_8 , F_5 ) ;
break;
case V_24 :
if ( ! F_17 ( V_8 ) ) {
F_6 ( V_8 , V_14 ) ;
}
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_19 ( struct V_7 * V_8 )
{
}
static void
V_22 ( struct V_7 * V_8 , enum V_9 V_10 )
{
switch ( V_10 ) {
case V_17 :
case V_24 :
F_15 ( V_8 ) ;
F_6 ( V_8 , F_5 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_20 ( struct V_7 * V_8 , struct V_25 * V_26 ,
enum V_27 V_28 )
{
struct V_29 * V_30 = & V_8 -> V_31 . V_32 ;
F_21 ( V_30 -> V_33 , V_34 , V_28 , 0 , V_8 -> V_35 -> V_36 ) ;
V_30 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_29 ) ) ) ;
memcpy ( & V_30 -> V_38 , & V_26 -> V_39 , sizeof( V_40 ) ) ;
F_24 ( & V_8 -> V_41 , NULL , NULL ,
sizeof( struct V_29 ) , & V_30 -> V_33 ) ;
F_25 ( & V_8 -> V_35 -> V_42 -> V_43 , & V_8 -> V_41 ) ;
}
static void
F_26 ( struct V_7 * V_8 , struct V_25 * V_26 )
{
struct V_44 * V_30 =
& V_8 -> V_31 . V_45 ;
F_21 ( V_30 -> V_33 , V_34 , V_46 ,
0 , V_8 -> V_35 -> V_36 ) ;
V_30 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_44 ) ) ) ;
memcpy ( & V_30 -> V_38 , & V_26 -> V_39 , sizeof( V_40 ) ) ;
F_24 ( & V_8 -> V_41 , NULL , NULL ,
sizeof( struct V_44 ) , & V_30 -> V_33 ) ;
F_25 ( & V_8 -> V_35 -> V_42 -> V_43 , & V_8 -> V_41 ) ;
}
static void
F_27 ( struct V_7 * V_8 , T_2 V_47 )
{
struct V_48 * V_30 =
& V_8 -> V_31 . V_49 ;
F_21 ( V_30 -> V_33 , V_34 , V_50 ,
0 , V_8 -> V_35 -> V_36 ) ;
V_30 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_48 ) ) ) ;
V_30 -> V_47 = F_22 ( V_47 ) ;
F_24 ( & V_8 -> V_41 , NULL , NULL ,
sizeof( struct V_48 ) , & V_30 -> V_33 ) ;
F_25 ( & V_8 -> V_35 -> V_42 -> V_43 , & V_8 -> V_41 ) ;
}
static void
F_28 ( struct V_7 * V_8 , enum V_51 V_52 )
{
struct V_53 * V_30 = & V_8 -> V_31 . V_30 ;
F_21 ( V_30 -> V_33 , V_34 ,
V_54 , 0 , V_8 -> V_35 -> V_36 ) ;
V_30 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_53 ) ) ) ;
V_30 -> V_55 = V_52 ;
F_24 ( & V_8 -> V_41 , NULL , NULL ,
sizeof( struct V_53 ) , & V_30 -> V_33 ) ;
F_25 ( & V_8 -> V_35 -> V_42 -> V_43 , & V_8 -> V_41 ) ;
}
static void
F_29 ( struct V_7 * V_8 , enum V_51 V_52 )
{
struct V_53 * V_30 = & V_8 -> V_31 . V_30 ;
F_21 ( V_30 -> V_33 , V_34 ,
V_56 , 0 , V_8 -> V_35 -> V_36 ) ;
V_30 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_53 ) ) ) ;
V_30 -> V_55 = V_52 ;
F_24 ( & V_8 -> V_41 , NULL , NULL ,
sizeof( struct V_53 ) , & V_30 -> V_33 ) ;
F_25 ( & V_8 -> V_35 -> V_42 -> V_43 , & V_8 -> V_41 ) ;
}
static void
F_30 ( struct V_7 * V_8 , T_1 V_57 )
{
struct V_58 * V_30 = & V_8 -> V_31 . V_59 ;
int V_60 ;
int V_61 ;
F_21 ( V_30 -> V_33 , V_34 ,
V_62 , 0 , V_8 -> V_35 -> V_36 ) ;
V_30 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_58 ) ) ) ;
V_30 -> V_57 = V_57 ;
for ( V_60 = 0 ; V_60 < ( V_63 / 32 ) ; V_60 ++ ) {
V_61 = ( V_57 * ( V_63 / 32 ) ) + V_60 ;
if ( V_8 -> V_64 == V_65 )
V_30 -> V_66 [ V_60 ] =
F_31 ( V_8 -> V_67 [ V_61 ] ) ;
else
V_30 -> V_66 [ V_60 ] = 0xFFFFFFFF ;
}
F_24 ( & V_8 -> V_41 , NULL , NULL ,
sizeof( struct V_58 ) , & V_30 -> V_33 ) ;
F_25 ( & V_8 -> V_35 -> V_42 -> V_43 , & V_8 -> V_41 ) ;
}
static void
F_32 ( struct V_7 * V_8 )
{
struct V_53 * V_30 = & V_8 -> V_31 . V_30 ;
F_21 ( V_30 -> V_33 , V_34 ,
V_68 , 0 , V_8 -> V_35 -> V_36 ) ;
V_30 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_53 ) ) ) ;
V_30 -> V_55 = V_8 -> V_69 ;
F_24 ( & V_8 -> V_41 , NULL , NULL ,
sizeof( struct V_53 ) , & V_30 -> V_33 ) ;
F_25 ( & V_8 -> V_35 -> V_42 -> V_43 , & V_8 -> V_41 ) ;
}
static void
F_33 ( struct V_7 * V_8 )
{
struct V_70 * V_30 = & V_8 -> V_31 . V_71 ;
F_21 ( V_30 -> V_33 , V_34 ,
V_72 , 0 , V_8 -> V_35 -> V_36 ) ;
V_30 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_70 ) ) ) ;
V_30 -> V_73 = F_22 ( V_8 -> V_74 ) ;
memcpy ( & V_30 -> V_75 [ 0 ] , V_8 -> V_76 , V_8 -> V_74 ) ;
F_24 ( & V_8 -> V_41 , NULL , NULL ,
sizeof( struct V_70 ) , & V_30 -> V_33 ) ;
F_25 ( & V_8 -> V_35 -> V_42 -> V_43 , & V_8 -> V_41 ) ;
}
static void
F_34 ( struct V_7 * V_8 )
{
struct V_77 * V_30 = & V_8 -> V_31 . V_78 ;
int V_60 ;
F_21 ( V_30 -> V_33 , V_34 ,
V_79 , 0 , V_8 -> V_35 -> V_36 ) ;
V_30 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_77 ) ) ) ;
V_30 -> V_80 . type = V_8 -> V_81 . V_82 ;
V_30 -> V_80 . V_83 = V_8 -> V_81 . V_84 ;
for ( V_60 = 0 ; V_60 < V_85 ; V_60 ++ )
V_30 -> V_80 . V_86 [ V_60 ] =
F_31 ( V_8 -> V_81 . V_87 [ V_60 ] ) ;
F_24 ( & V_8 -> V_41 , NULL , NULL ,
sizeof( struct V_77 ) , & V_30 -> V_33 ) ;
F_25 ( & V_8 -> V_35 -> V_42 -> V_43 , & V_8 -> V_41 ) ;
}
static void
F_35 ( struct V_7 * V_8 )
{
struct V_53 * V_30 = & V_8 -> V_31 . V_30 ;
F_21 ( V_30 -> V_33 , V_34 ,
V_88 , 0 , V_8 -> V_35 -> V_36 ) ;
V_30 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_53 ) ) ) ;
V_30 -> V_55 = V_8 -> V_89 ;
F_24 ( & V_8 -> V_41 , NULL , NULL ,
sizeof( struct V_53 ) , & V_30 -> V_33 ) ;
F_25 ( & V_8 -> V_35 -> V_42 -> V_43 , & V_8 -> V_41 ) ;
}
static struct V_25 *
F_36 ( struct V_7 * V_8 , T_1 * V_38 )
{
struct V_25 * V_26 ;
struct V_90 * V_91 ;
F_37 (qe, &rxf->mcast_active_q) {
V_26 = (struct V_25 * ) V_91 ;
if ( F_38 ( & V_26 -> V_39 , V_38 ) )
return V_26 ;
}
F_37 (qe, &rxf->mcast_pending_del_q) {
V_26 = (struct V_25 * ) V_91 ;
if ( F_38 ( & V_26 -> V_39 , V_38 ) )
return V_26 ;
}
return NULL ;
}
static struct V_92 *
F_39 ( struct V_7 * V_8 , int V_47 )
{
struct V_92 * V_93 ;
struct V_90 * V_91 ;
F_37 (qe, &rxf->mcast_handle_q) {
V_93 = (struct V_92 * ) V_91 ;
if ( V_93 -> V_47 == V_47 )
return V_93 ;
}
return NULL ;
}
static void
F_40 ( struct V_7 * V_8 , T_1 * V_38 , int V_47 )
{
struct V_25 * V_94 ;
struct V_92 * V_93 ;
V_94 = F_36 ( V_8 , V_38 ) ;
V_93 = F_39 ( V_8 , V_47 ) ;
if ( V_93 == NULL ) {
V_93 = F_41 ( & V_8 -> V_35 -> V_42 -> V_95 ) ;
V_93 -> V_47 = V_47 ;
V_93 -> V_96 = 0 ;
F_42 ( & V_93 -> V_91 , & V_8 -> V_97 ) ;
}
V_93 -> V_96 ++ ;
V_94 -> V_47 = V_93 ;
}
static int
F_43 ( struct V_7 * V_8 , struct V_25 * V_26 ,
enum V_98 V_99 )
{
struct V_92 * V_93 ;
int V_100 = 0 ;
V_93 = V_26 -> V_47 ;
if ( V_93 == NULL )
return V_100 ;
V_93 -> V_96 -- ;
if ( V_93 -> V_96 == 0 ) {
if ( V_99 == V_101 ) {
F_27 ( V_8 , V_93 -> V_47 ) ;
V_100 = 1 ;
}
F_44 ( & V_93 -> V_91 ) ;
F_45 ( & V_93 -> V_91 ) ;
F_46 ( & V_8 -> V_35 -> V_42 -> V_95 , V_93 ) ;
}
V_26 -> V_47 = NULL ;
return V_100 ;
}
static int
F_47 ( struct V_7 * V_8 )
{
struct V_25 * V_26 = NULL ;
struct V_90 * V_91 ;
int V_100 ;
while ( ! F_48 ( & V_8 -> V_102 ) ) {
F_49 ( & V_8 -> V_102 , & V_91 ) ;
F_45 ( V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
V_100 = F_43 ( V_8 , V_26 , V_101 ) ;
F_50 ( F_51 ( V_8 -> V_35 -> V_42 ) , V_26 ) ;
if ( V_100 )
return V_100 ;
}
if ( ! F_48 ( & V_8 -> V_103 ) ) {
F_49 ( & V_8 -> V_103 , & V_91 ) ;
F_45 ( V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_42 ( & V_26 -> V_91 , & V_8 -> V_104 ) ;
F_26 ( V_8 , V_26 ) ;
return 1 ;
}
return 0 ;
}
static int
F_52 ( struct V_7 * V_8 )
{
T_1 V_105 ;
int V_57 = 0 ;
if ( V_8 -> V_105 ) {
V_105 = V_8 -> V_105 ;
while ( ! ( V_105 & 0x1 ) ) {
V_57 ++ ;
V_105 >>= 1 ;
}
V_8 -> V_105 &= ~ ( 1 << V_57 ) ;
F_30 ( V_8 , V_57 ) ;
return 1 ;
}
return 0 ;
}
static int
F_53 ( struct V_7 * V_8 , enum V_98 V_99 )
{
struct V_90 * V_91 ;
struct V_25 * V_26 ;
int V_100 ;
while ( ! F_48 ( & V_8 -> V_102 ) ) {
F_49 ( & V_8 -> V_102 , & V_91 ) ;
F_45 ( V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
V_100 = F_43 ( V_8 , V_26 , V_99 ) ;
F_50 ( F_51 ( V_8 -> V_35 -> V_42 ) , V_26 ) ;
if ( V_100 )
return V_100 ;
}
while ( ! F_48 ( & V_8 -> V_104 ) ) {
F_49 ( & V_8 -> V_104 , & V_91 ) ;
F_45 ( V_91 ) ;
F_42 ( V_91 , & V_8 -> V_103 ) ;
V_26 = (struct V_25 * ) V_91 ;
if ( F_43 ( V_8 , V_26 , V_99 ) )
return 1 ;
}
return 0 ;
}
static int
F_54 ( struct V_7 * V_8 )
{
if ( V_8 -> V_106 ) {
if ( V_8 -> V_106 & V_107 ) {
V_8 -> V_106 &= ~ V_107 ;
F_33 ( V_8 ) ;
return 1 ;
}
if ( V_8 -> V_106 & V_108 ) {
V_8 -> V_106 &= ~ V_108 ;
F_34 ( V_8 ) ;
return 1 ;
}
if ( V_8 -> V_106 & V_109 ) {
V_8 -> V_106 &= ~ V_109 ;
F_35 ( V_8 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_14 ( struct V_7 * V_8 )
{
if ( F_55 ( V_8 ) )
return 1 ;
if ( F_47 ( V_8 ) )
return 1 ;
if ( F_56 ( V_8 ) )
return 1 ;
if ( F_57 ( V_8 ) )
return 1 ;
if ( F_52 ( V_8 ) )
return 1 ;
if ( F_58 ( V_8 ) )
return 1 ;
if ( F_54 ( V_8 ) )
return 1 ;
return 0 ;
}
static int
F_17 ( struct V_7 * V_8 )
{
if ( F_59 ( V_8 , V_101 ) )
return 1 ;
if ( F_53 ( V_8 , V_101 ) )
return 1 ;
if ( F_60 ( V_8 , V_101 ) )
return 1 ;
if ( F_61 ( V_8 , V_101 ) )
return 1 ;
return 0 ;
}
static void
F_15 ( struct V_7 * V_8 )
{
F_59 ( V_8 , V_110 ) ;
F_53 ( V_8 , V_110 ) ;
F_60 ( V_8 , V_110 ) ;
F_61 ( V_8 , V_110 ) ;
F_62 ( V_8 ) ;
F_63 ( V_8 ) ;
}
static void
F_64 ( struct V_7 * V_8 , int V_74 )
{
struct V_111 * V_35 = V_8 -> V_35 ;
struct V_112 * V_113 ;
struct V_90 * V_91 ;
int V_114 = 0 ;
V_8 -> V_74 = V_74 ;
F_37 (qe, &rx->rxp_q) {
V_113 = (struct V_112 * ) V_91 ;
V_8 -> V_76 [ V_114 ] = V_113 -> V_115 . V_116 -> V_117 ;
V_114 ++ ;
}
}
void
F_65 ( struct V_7 * V_8 , struct V_118 * V_119 )
{
F_66 ( V_8 , V_24 ) ;
}
void
F_67 ( struct V_7 * V_8 ,
struct V_118 * V_119 )
{
struct V_120 * V_121 =
F_68 ( V_119 , struct V_120 , V_33 ) ;
if ( V_121 -> error ) {
V_8 -> V_122 = 0 ;
}
F_66 ( V_8 , V_24 ) ;
}
void
F_69 ( struct V_7 * V_8 ,
struct V_118 * V_119 )
{
struct V_44 * V_30 =
& V_8 -> V_31 . V_45 ;
struct V_123 * V_121 =
F_68 ( V_119 , struct V_123 , V_33 ) ;
F_40 ( V_8 , ( T_1 * ) & V_30 -> V_38 ,
F_70 ( V_121 -> V_47 ) ) ;
F_66 ( V_8 , V_24 ) ;
}
static void
F_71 ( struct V_7 * V_8 ,
struct V_111 * V_35 ,
struct V_124 * V_125 ,
struct V_126 * V_127 )
{
V_8 -> V_35 = V_35 ;
F_72 ( & V_8 -> V_128 ) ;
F_72 ( & V_8 -> V_129 ) ;
V_8 -> V_130 = 0 ;
V_8 -> V_122 = 0 ;
F_72 ( & V_8 -> V_131 ) ;
V_8 -> V_132 = NULL ;
F_72 ( & V_8 -> V_103 ) ;
F_72 ( & V_8 -> V_102 ) ;
F_72 ( & V_8 -> V_104 ) ;
F_72 ( & V_8 -> V_97 ) ;
if ( V_125 -> V_133 )
V_8 -> V_12 |= V_13 ;
V_8 -> V_76 = ( T_1 * )
V_127 [ V_134 ] . V_135 . V_136 . V_137 [ 0 ] . V_138 ;
F_64 ( V_8 , V_125 -> V_139 ) ;
V_8 -> V_89 = V_125 -> V_89 ;
if ( V_8 -> V_89 == V_65 ) {
V_8 -> V_81 = V_125 -> V_140 ;
V_8 -> V_106 |= V_108 ;
V_8 -> V_106 |= V_107 ;
V_8 -> V_106 |= V_109 ;
}
V_8 -> V_64 = V_141 ;
memset ( V_8 -> V_67 , 0 ,
( sizeof( V_6 ) * ( V_142 / 32 ) ) ) ;
V_8 -> V_67 [ 0 ] |= 1 ;
V_8 -> V_105 = ( T_1 ) V_143 ;
V_8 -> V_69 = V_125 -> V_69 ;
F_6 ( V_8 , F_5 ) ;
}
static void
F_73 ( struct V_7 * V_8 )
{
struct V_25 * V_26 ;
V_8 -> V_130 = 0 ;
V_8 -> V_122 = 0 ;
while ( ! F_48 ( & V_8 -> V_128 ) ) {
F_49 ( & V_8 -> V_128 , & V_26 ) ;
F_45 ( & V_26 -> V_91 ) ;
F_50 ( F_74 ( V_8 -> V_35 -> V_42 ) , V_26 ) ;
}
if ( V_8 -> V_132 ) {
F_45 ( & V_8 -> V_132 -> V_91 ) ;
F_50 ( F_74 ( V_8 -> V_35 -> V_42 ) ,
V_8 -> V_132 ) ;
V_8 -> V_132 = NULL ;
}
while ( ! F_48 ( & V_8 -> V_103 ) ) {
F_49 ( & V_8 -> V_103 , & V_26 ) ;
F_45 ( & V_26 -> V_91 ) ;
F_50 ( F_75 ( V_8 -> V_35 -> V_42 ) , V_26 ) ;
}
V_8 -> V_144 = 0 ;
V_8 -> V_145 = 0 ;
if ( V_8 -> V_35 -> V_42 -> V_146 == V_8 -> V_35 -> V_36 )
V_8 -> V_35 -> V_42 -> V_146 = V_147 ;
if ( V_8 -> V_35 -> V_42 -> V_148 == V_8 -> V_35 -> V_36 )
V_8 -> V_35 -> V_42 -> V_148 = V_147 ;
V_8 -> V_106 = 0 ;
V_8 -> V_149 = false ;
V_8 -> V_12 = 0 ;
V_8 -> V_35 = NULL ;
}
static void
F_76 ( struct V_111 * V_35 )
{
F_66 ( V_35 , V_150 ) ;
}
static void
F_77 ( struct V_7 * V_8 )
{
V_8 -> V_151 = F_76 ;
V_8 -> V_152 = V_8 -> V_35 ;
F_66 ( V_8 , V_11 ) ;
}
static void
F_78 ( struct V_111 * V_35 )
{
F_66 ( V_35 , V_153 ) ;
}
static void
F_79 ( struct V_7 * V_8 )
{
V_8 -> V_154 = F_78 ;
V_8 -> V_155 = V_8 -> V_35 ;
F_66 ( V_8 , V_16 ) ;
}
static void
F_80 ( struct V_7 * V_8 )
{
F_66 ( V_8 , V_17 ) ;
}
enum V_156
F_81 ( struct V_111 * V_35 , T_1 * V_157 ,
void (* F_82)( struct V_158 * , struct V_111 * ) )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
if ( V_8 -> V_132 == NULL ) {
V_8 -> V_132 =
F_83 ( F_74 ( V_8 -> V_35 -> V_42 ) ) ;
if ( V_8 -> V_132 == NULL )
return V_159 ;
F_45 ( & V_8 -> V_132 -> V_91 ) ;
}
memcpy ( V_8 -> V_132 -> V_39 , V_157 , V_160 ) ;
V_8 -> V_130 = 1 ;
V_8 -> V_161 = F_82 ;
V_8 -> V_162 = V_35 -> V_42 -> V_158 ;
F_66 ( V_8 , V_18 ) ;
return V_163 ;
}
enum V_156
F_84 ( struct V_111 * V_35 , T_1 * V_39 ,
void (* F_82)( struct V_158 * , struct V_111 * ) )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
struct V_25 * V_26 ;
if ( F_85 ( & V_8 -> V_104 , V_39 ) ||
F_85 ( & V_8 -> V_103 , V_39 ) ) {
if ( F_82 )
F_82 ( V_35 -> V_42 -> V_158 , V_35 ) ;
return V_163 ;
}
V_26 = F_83 ( F_75 ( V_8 -> V_35 -> V_42 ) ) ;
if ( V_26 == NULL )
return V_164 ;
F_45 ( & V_26 -> V_91 ) ;
memcpy ( V_26 -> V_39 , V_39 , V_160 ) ;
F_42 ( & V_26 -> V_91 , & V_8 -> V_103 ) ;
V_8 -> V_161 = F_82 ;
V_8 -> V_162 = V_35 -> V_42 -> V_158 ;
F_66 ( V_8 , V_18 ) ;
return V_163 ;
}
enum V_156
F_86 ( struct V_111 * V_35 , int V_165 , T_1 * V_166 ,
void (* F_82)( struct V_158 * , struct V_111 * ) )
{
struct V_167 * V_168 = & V_35 -> V_42 -> V_168 ;
struct V_7 * V_8 = & V_35 -> V_8 ;
struct V_90 V_90 ;
struct V_90 * V_91 ;
T_1 * V_169 ;
struct V_25 * V_26 , * V_170 ;
int V_60 ;
while ( ! F_48 ( & V_8 -> V_128 ) ) {
F_49 ( & V_8 -> V_128 , & V_91 ) ;
F_45 ( V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_50 ( & V_168 -> V_171 , V_26 ) ;
}
while ( ! F_48 ( & V_8 -> V_131 ) ) {
F_49 ( & V_8 -> V_131 , & V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_45 ( & V_26 -> V_91 ) ;
V_170 = F_83 ( & V_168 -> V_172 ) ;
memcpy ( V_170 , V_26 , sizeof( * V_170 ) ) ;
F_42 ( & V_170 -> V_91 , & V_8 -> V_129 ) ;
F_50 ( & V_168 -> V_171 , V_26 ) ;
}
F_72 ( & V_90 ) ;
for ( V_60 = 0 , V_169 = V_166 ; V_60 < V_165 ; V_60 ++ ) {
V_26 = F_83 ( & V_168 -> V_171 ) ;
if ( V_26 == NULL )
goto V_173;
F_45 ( & V_26 -> V_91 ) ;
memcpy ( V_26 -> V_39 , V_169 , V_160 ) ;
F_42 ( & V_26 -> V_91 , & V_90 ) ;
V_169 += V_160 ;
}
while ( ! F_48 ( & V_90 ) ) {
F_49 ( & V_90 , & V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_45 ( & V_26 -> V_91 ) ;
F_42 ( & V_26 -> V_91 , & V_8 -> V_128 ) ;
}
V_8 -> V_161 = F_82 ;
V_8 -> V_162 = V_35 -> V_42 -> V_158 ;
F_66 ( V_8 , V_18 ) ;
return V_163 ;
V_173:
while ( ! F_48 ( & V_90 ) ) {
F_49 ( & V_90 , & V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_45 ( & V_26 -> V_91 ) ;
F_50 ( & V_168 -> V_171 , V_26 ) ;
}
return V_159 ;
}
enum V_156
F_87 ( struct V_111 * V_35 , int V_165 , T_1 * V_174 ,
void (* F_82)( struct V_158 * , struct V_111 * ) )
{
struct V_175 * V_95 = & V_35 -> V_42 -> V_95 ;
struct V_7 * V_8 = & V_35 -> V_8 ;
struct V_90 V_90 ;
struct V_90 * V_91 ;
T_1 * V_169 ;
struct V_25 * V_26 , * V_170 ;
int V_60 ;
while ( ! F_48 ( & V_8 -> V_103 ) ) {
F_49 ( & V_8 -> V_103 , & V_91 ) ;
F_45 ( V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_50 ( & V_95 -> V_171 , V_26 ) ;
}
while ( ! F_48 ( & V_8 -> V_104 ) ) {
F_49 ( & V_8 -> V_104 , & V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_45 ( & V_26 -> V_91 ) ;
V_170 = F_83 ( & V_95 -> V_172 ) ;
memcpy ( V_170 , V_26 , sizeof( * V_170 ) ) ;
F_42 ( & V_170 -> V_91 , & V_8 -> V_102 ) ;
V_26 -> V_47 = NULL ;
F_50 ( & V_95 -> V_171 , V_26 ) ;
}
F_72 ( & V_90 ) ;
for ( V_60 = 0 , V_169 = V_174 ; V_60 < V_165 ; V_60 ++ ) {
V_26 = F_83 ( & V_95 -> V_171 ) ;
if ( V_26 == NULL )
goto V_173;
F_45 ( & V_26 -> V_91 ) ;
memcpy ( V_26 -> V_39 , V_169 , V_160 ) ;
F_42 ( & V_26 -> V_91 , & V_90 ) ;
V_169 += V_160 ;
}
while ( ! F_48 ( & V_90 ) ) {
F_49 ( & V_90 , & V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_45 ( & V_26 -> V_91 ) ;
F_42 ( & V_26 -> V_91 , & V_8 -> V_103 ) ;
}
V_8 -> V_161 = F_82 ;
V_8 -> V_162 = V_35 -> V_42 -> V_158 ;
F_66 ( V_8 , V_18 ) ;
return V_163 ;
V_173:
while ( ! F_48 ( & V_90 ) ) {
F_49 ( & V_90 , & V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_45 ( & V_26 -> V_91 ) ;
F_50 ( & V_95 -> V_171 , V_26 ) ;
}
return V_164 ;
}
void
F_88 ( struct V_111 * V_35 ,
void (* F_82)( struct V_158 * , struct V_111 * ) )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
struct V_90 * V_91 ;
struct V_25 * V_26 , * V_170 ;
int V_176 = 0 ;
while ( ! F_48 ( & V_8 -> V_103 ) ) {
F_49 ( & V_8 -> V_103 , & V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_45 ( & V_26 -> V_91 ) ;
F_50 ( F_75 ( V_8 -> V_35 -> V_42 ) , V_26 ) ;
}
while ( ! F_48 ( & V_8 -> V_104 ) ) {
F_49 ( & V_8 -> V_104 , & V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_45 ( & V_26 -> V_91 ) ;
V_170 = F_83 ( F_51 ( V_8 -> V_35 -> V_42 ) ) ;
memcpy ( V_170 , V_26 , sizeof( * V_170 ) ) ;
F_42 ( & V_170 -> V_91 , & V_8 -> V_102 ) ;
V_26 -> V_47 = NULL ;
F_50 ( F_75 ( V_8 -> V_35 -> V_42 ) , V_26 ) ;
V_176 = 1 ;
}
if ( V_176 ) {
V_8 -> V_161 = F_82 ;
V_8 -> V_162 = V_35 -> V_42 -> V_158 ;
F_66 ( V_8 , V_18 ) ;
return;
}
if ( F_82 )
(* F_82)( V_35 -> V_42 -> V_158 , V_35 ) ;
}
void
F_89 ( struct V_111 * V_35 , int V_177 )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
int V_178 = ( V_177 >> V_179 ) ;
int V_180 = ( 1 << ( V_177 & V_181 ) ) ;
int V_182 = ( V_177 >> V_183 ) ;
V_8 -> V_67 [ V_178 ] |= V_180 ;
if ( V_8 -> V_64 == V_65 ) {
V_8 -> V_105 |= ( 1 << V_182 ) ;
F_66 ( V_8 , V_18 ) ;
}
}
void
F_90 ( struct V_111 * V_35 , int V_177 )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
int V_178 = ( V_177 >> V_179 ) ;
int V_180 = ( 1 << ( V_177 & V_181 ) ) ;
int V_182 = ( V_177 >> V_183 ) ;
V_8 -> V_67 [ V_178 ] &= ~ V_180 ;
if ( V_8 -> V_64 == V_65 ) {
V_8 -> V_105 |= ( 1 << V_182 ) ;
F_66 ( V_8 , V_18 ) ;
}
}
static int
F_55 ( struct V_7 * V_8 )
{
struct V_25 * V_26 = NULL ;
struct V_90 * V_91 ;
if ( ! F_48 ( & V_8 -> V_129 ) ) {
F_49 ( & V_8 -> V_129 , & V_91 ) ;
F_45 ( V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_20 ( V_8 , V_26 , V_184 ) ;
F_50 ( F_91 ( V_8 -> V_35 -> V_42 ) , V_26 ) ;
return 1 ;
}
if ( V_8 -> V_130 ) {
V_8 -> V_130 = 0 ;
memcpy ( V_8 -> V_185 . V_39 ,
V_8 -> V_132 -> V_39 , V_160 ) ;
V_8 -> V_122 = 1 ;
F_20 ( V_8 , & V_8 -> V_185 ,
V_186 ) ;
return 1 ;
}
if ( ! F_48 ( & V_8 -> V_128 ) ) {
F_49 ( & V_8 -> V_128 , & V_91 ) ;
F_45 ( V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_42 ( & V_26 -> V_91 , & V_8 -> V_131 ) ;
F_20 ( V_8 , V_26 , V_187 ) ;
return 1 ;
}
return 0 ;
}
static int
F_59 ( struct V_7 * V_8 , enum V_98 V_99 )
{
struct V_90 * V_91 ;
struct V_25 * V_26 ;
while ( ! F_48 ( & V_8 -> V_129 ) ) {
F_49 ( & V_8 -> V_129 , & V_91 ) ;
F_45 ( V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
if ( V_99 == V_110 )
F_50 ( F_91 ( V_8 -> V_35 -> V_42 ) ,
V_26 ) ;
else {
F_20 ( V_8 , V_26 ,
V_184 ) ;
F_50 ( F_91 ( V_8 -> V_35 -> V_42 ) ,
V_26 ) ;
return 1 ;
}
}
while ( ! F_48 ( & V_8 -> V_131 ) ) {
F_49 ( & V_8 -> V_131 , & V_91 ) ;
F_45 ( V_91 ) ;
F_42 ( V_91 , & V_8 -> V_128 ) ;
if ( V_99 == V_101 ) {
V_26 = (struct V_25 * ) V_91 ;
F_20 ( V_8 , V_26 ,
V_184 ) ;
return 1 ;
}
}
if ( V_8 -> V_122 ) {
V_8 -> V_130 = 1 ;
V_8 -> V_122 = 0 ;
if ( V_99 == V_101 ) {
F_20 ( V_8 , & V_8 -> V_185 ,
V_188 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_56 ( struct V_7 * V_8 )
{
struct V_42 * V_42 = V_8 -> V_35 -> V_42 ;
if ( F_92 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_93 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_8 -> V_189 |= V_190 ;
F_29 ( V_8 , V_65 ) ;
return 1 ;
} else if ( F_94 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_93 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_8 -> V_189 &= ~ V_190 ;
V_42 -> V_146 = V_147 ;
F_29 ( V_8 , V_141 ) ;
return 1 ;
}
return 0 ;
}
static int
F_60 ( struct V_7 * V_8 , enum V_98 V_99 )
{
struct V_42 * V_42 = V_8 -> V_35 -> V_42 ;
if ( F_94 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_93 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_8 -> V_189 &= ~ V_190 ;
V_42 -> V_146 = V_147 ;
if ( V_99 == V_101 ) {
F_29 ( V_8 , V_141 ) ;
return 1 ;
}
}
if ( V_8 -> V_189 & V_190 ) {
F_95 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_8 -> V_189 &= ~ V_190 ;
if ( V_99 == V_101 ) {
F_29 ( V_8 , V_141 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_57 ( struct V_7 * V_8 )
{
if ( F_96 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_97 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_8 -> V_189 |= V_191 ;
F_28 ( V_8 , V_141 ) ;
return 1 ;
} else if ( F_98 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_97 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_8 -> V_189 &= ~ V_191 ;
F_28 ( V_8 , V_65 ) ;
return 1 ;
}
return 0 ;
}
static int
F_61 ( struct V_7 * V_8 , enum V_98 V_99 )
{
if ( F_98 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_97 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_8 -> V_189 &= ~ V_191 ;
if ( V_99 == V_101 ) {
F_28 ( V_8 , V_65 ) ;
return 1 ;
}
}
if ( V_8 -> V_189 & V_191 ) {
F_99 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_8 -> V_189 &= ~ V_191 ;
if ( V_99 == V_101 ) {
F_28 ( V_8 , V_65 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_100 ( struct V_7 * V_8 )
{
struct V_42 * V_42 = V_8 -> V_35 -> V_42 ;
int V_100 = 0 ;
if ( F_92 ( V_8 -> V_144 ,
V_8 -> V_145 ) ||
( V_8 -> V_189 & V_190 ) ) {
} else if ( F_94 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_93 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
} else {
F_95 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_42 -> V_146 = V_8 -> V_35 -> V_36 ;
V_100 = 1 ;
}
return V_100 ;
}
static int
F_101 ( struct V_7 * V_8 )
{
struct V_42 * V_42 = V_8 -> V_35 -> V_42 ;
int V_100 = 0 ;
if ( F_94 ( V_8 -> V_144 ,
V_8 -> V_145 ) ||
( ! ( V_8 -> V_189 & V_190 ) ) ) {
} else if ( F_92 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_93 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_42 -> V_146 = V_147 ;
} else if ( V_8 -> V_189 & V_190 ) {
F_102 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_100 = 1 ;
}
return V_100 ;
}
static int
F_103 ( struct V_7 * V_8 )
{
int V_100 = 0 ;
if ( F_96 ( V_8 -> V_144 ,
V_8 -> V_145 ) ||
( V_8 -> V_189 & V_191 ) ) {
} else if ( F_98 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_97 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
} else {
F_99 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_100 = 1 ;
}
return V_100 ;
}
static int
F_104 ( struct V_7 * V_8 )
{
int V_100 = 0 ;
if ( F_98 ( V_8 -> V_144 ,
V_8 -> V_145 ) ||
( ! ( V_8 -> V_189 & V_191 ) ) ) {
} else if ( F_96 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_97 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
} else if ( V_8 -> V_189 & V_191 ) {
F_105 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_100 = 1 ;
}
return V_100 ;
}
static int
F_58 ( struct V_7 * V_8 )
{
if ( V_8 -> V_149 ) {
V_8 -> V_149 = false ;
F_32 ( V_8 ) ;
return 1 ;
}
return 0 ;
}
static void F_106 ( struct V_111 * V_35 )
{
F_107 ( V_35 ) ;
}
static void F_108 ( struct V_111 * V_35 ,
enum V_192 V_10 )
{
switch ( V_10 ) {
case V_193 :
F_6 ( V_35 , V_194 ) ;
break;
case V_195 :
F_107 ( V_35 ) ;
break;
case V_196 :
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void F_109 ( struct V_111 * V_35 )
{
F_110 ( V_35 ) ;
}
static void
F_111 ( struct V_111 * V_35 )
{
}
static void
F_112 ( struct V_111 * V_35 , enum V_192 V_10 )
{
switch ( V_10 ) {
case V_196 :
case V_197 :
F_6 ( V_35 , V_198 ) ;
V_35 -> V_199 ( V_35 -> V_42 -> V_158 , V_35 ) ;
break;
case V_200 :
F_113 ( V_35 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void V_194 ( struct V_111 * V_35 ,
enum V_192 V_10 )
{
switch ( V_10 ) {
case V_195 :
F_6 ( V_35 , V_201 ) ;
break;
case V_196 :
F_6 ( V_35 , F_108 ) ;
break;
case V_200 :
F_6 ( V_35 , V_202 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void F_114 ( struct V_111 * V_35 )
{
V_35 -> V_203 ( V_35 -> V_42 -> V_158 , V_35 ) ;
F_77 ( & V_35 -> V_8 ) ;
}
static void
F_115 ( struct V_111 * V_35 )
{
}
static void
F_116 ( struct V_111 * V_35 , enum V_192 V_10 )
{
switch ( V_10 ) {
case V_196 :
F_6 ( V_35 , V_198 ) ;
F_80 ( & V_35 -> V_8 ) ;
F_117 ( V_35 ) ;
V_35 -> V_199 ( V_35 -> V_42 -> V_158 , V_35 ) ;
break;
case V_150 :
F_79 ( & V_35 -> V_8 ) ;
break;
case V_153 :
F_6 ( V_35 , F_112 ) ;
F_117 ( V_35 ) ;
F_113 ( V_35 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void
F_118 ( struct V_111 * V_35 )
{
}
static void
V_201 ( struct V_111 * V_35 , enum V_192 V_10 )
{
switch ( V_10 ) {
case V_196 :
case V_197 :
F_6 ( V_35 , F_108 ) ;
break;
case V_200 :
F_113 ( V_35 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_119 ( struct V_111 * V_35 )
{
struct V_112 * V_113 ;
struct V_90 * V_204 ;
int V_205 = ( V_35 -> type == V_206 ) ;
F_37 (qe_rxp, &rx->rxp_q) {
V_113 = (struct V_112 * ) V_204 ;
F_120 ( V_35 -> V_42 , & V_113 -> V_115 . V_2 , V_205 ) ;
}
F_121 ( & V_35 -> V_42 -> V_207 ) ;
}
static void
F_122 ( struct V_111 * V_35 , enum V_192 V_10 )
{
switch ( V_10 ) {
case V_195 :
F_6 ( V_35 , F_116 ) ;
F_123 ( & V_35 -> V_42 -> V_207 ) ;
F_79 ( & V_35 -> V_8 ) ;
break;
case V_196 :
F_6 ( V_35 , V_208 ) ;
F_123 ( & V_35 -> V_42 -> V_207 ) ;
F_80 ( & V_35 -> V_8 ) ;
F_117 ( V_35 ) ;
V_35 -> V_199 ( V_35 -> V_42 -> V_158 , V_35 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void V_202 ( struct V_111 * V_35 ,
enum V_192 V_10 )
{
switch ( V_10 ) {
case V_195 :
F_6 ( V_35 , F_116 ) ;
break;
case V_196 :
F_6 ( V_35 , V_208 ) ;
F_80 ( & V_35 -> V_8 ) ;
F_117 ( V_35 ) ;
V_35 -> V_199 ( V_35 -> V_42 -> V_158 , V_35 ) ;
break;
case V_150 :
F_6 ( V_35 , F_122 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void
F_124 ( struct V_111 * V_35 )
{
}
static void
V_198 ( struct V_111 * V_35 , enum V_192 V_10 )
{
switch ( V_10 ) {
case V_196 :
case V_153 :
break;
case V_209 :
F_6 ( V_35 , F_108 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void
F_125 ( struct V_111 * V_35 )
{
}
static void
V_208 ( struct V_111 * V_35 , enum V_192 V_10 )
{
switch ( V_10 ) {
case V_193 :
F_6 ( V_35 , V_210 ) ;
break;
case V_195 :
F_6 ( V_35 , V_198 ) ;
break;
case V_196 :
case V_150 :
case V_153 :
break;
case V_209 :
F_6 ( V_35 , F_108 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
} }
static void
F_126 ( struct V_111 * V_35 )
{
}
static void
V_210 ( struct V_111 * V_35 , enum V_192 V_10 )
{
switch ( V_10 ) {
case V_195 :
F_6 ( V_35 , V_198 ) ;
break;
case V_196 :
F_6 ( V_35 , V_208 ) ;
break;
case V_209 :
F_6 ( V_35 , V_194 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void
F_110 ( struct V_111 * V_35 )
{
struct V_211 * V_212 = & V_35 -> V_31 . V_212 ;
struct V_112 * V_113 = NULL ;
struct V_213 * V_214 = NULL , * V_215 = NULL ;
struct V_90 * V_216 ;
int V_60 ;
F_21 ( V_212 -> V_33 , V_34 ,
V_217 , 0 , V_35 -> V_36 ) ;
V_212 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_211 ) ) ) ;
V_212 -> V_218 . V_219 = F_127 ( & V_35 -> V_42 -> V_220 ) ;
V_212 -> V_221 = V_35 -> V_139 ;
for ( V_60 = 0 , V_216 = F_128 ( & V_35 -> V_222 ) ;
V_60 < V_35 -> V_139 ;
V_60 ++ , V_216 = F_129 ( V_216 ) ) {
V_113 = (struct V_112 * ) V_216 ;
F_130 ( V_113 , V_214 , V_215 ) ;
switch ( V_113 -> type ) {
case V_223 :
case V_224 :
F_131 ( & V_212 -> V_225 [ V_60 ] . V_226 . V_227 ,
& V_215 -> V_228 ) ;
V_212 -> V_225 [ V_60 ] . V_226 . V_229 =
F_22 ( ( T_2 ) V_215 -> V_230 ) ;
case V_231 :
F_131 ( & V_212 -> V_225 [ V_60 ] . V_232 . V_227 ,
& V_214 -> V_228 ) ;
if ( V_214 -> V_233 )
V_212 -> V_218 . V_233 =
V_65 ;
else
V_214 -> V_230 =
F_127 ( & V_35 -> V_42 -> V_220 ) ;
V_212 -> V_225 [ V_60 ] . V_232 . V_229 =
F_22 ( ( T_2 ) V_214 -> V_230 ) ;
break;
default:
F_132 ( 1 ) ;
}
F_131 ( & V_212 -> V_225 [ V_60 ] . V_115 . V_227 ,
& V_113 -> V_115 . V_228 ) ;
V_212 -> V_225 [ V_60 ] . V_2 . V_234 . V_235 . V_236 =
V_113 -> V_115 . V_2 . V_237 . V_238 ;
V_212 -> V_225 [ V_60 ] . V_2 . V_234 . V_235 . V_239 =
V_113 -> V_115 . V_2 . V_237 . V_240 ;
V_212 -> V_225 [ V_60 ] . V_2 . V_241 . V_242 =
F_22 ( ( T_2 ) V_113 -> V_115 . V_2 . V_243 ) ;
}
V_212 -> V_244 . V_245 = V_141 ;
V_212 -> V_244 . V_246 = V_65 ;
V_212 -> V_244 . V_247 = V_141 ;
V_212 -> V_244 . V_248 = V_141 ;
V_212 -> V_244 . V_249 = ( V_113 -> V_115 . V_2 . V_250 == V_251 )
? V_65 :
V_141 ;
V_212 -> V_244 . V_252 =
F_31 ( ( V_6 ) V_113 -> V_115 . V_2 . V_3 ) ;
V_212 -> V_244 . V_253 =
F_31 ( ( V_6 ) V_113 -> V_115 . V_2 . V_254 ) ;
V_212 -> V_244 . V_255 = ( T_1 ) V_113 -> V_115 . V_2 . V_256 ;
switch ( V_113 -> type ) {
case V_223 :
V_212 -> V_218 . V_257 = V_258 ;
break;
case V_224 :
V_212 -> V_218 . V_257 = V_259 ;
V_212 -> V_218 . V_260 . type = V_35 -> V_261 . V_262 ;
V_212 -> V_218 . V_260 . V_263 = V_35 -> V_261 . V_264 ;
V_212 -> V_218 . V_260 . V_265 = V_35 -> V_261 . V_264 ;
break;
case V_231 :
V_212 -> V_218 . V_257 = V_266 ;
break;
default:
F_132 ( 1 ) ;
}
V_212 -> V_218 . V_267 = V_35 -> V_8 . V_69 ;
F_24 ( & V_35 -> V_41 , NULL , NULL ,
sizeof( struct V_211 ) , & V_212 -> V_33 ) ;
F_25 ( & V_35 -> V_42 -> V_43 , & V_35 -> V_41 ) ;
}
static void
F_133 ( struct V_111 * V_35 )
{
struct V_268 * V_30 = & V_35 -> V_31 . V_30 ;
F_21 ( V_30 -> V_33 , V_34 ,
V_269 , 0 , V_35 -> V_36 ) ;
V_30 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_268 ) ) ) ;
F_24 ( & V_35 -> V_41 , NULL , NULL , sizeof( struct V_268 ) ,
& V_30 -> V_33 ) ;
F_25 ( & V_35 -> V_42 -> V_43 , & V_35 -> V_41 ) ;
}
static void
F_113 ( struct V_111 * V_35 )
{
struct V_112 * V_113 ;
struct V_90 * V_204 ;
F_37 (qe_rxp, &rx->rxp_q) {
V_113 = (struct V_112 * ) V_204 ;
F_134 ( V_35 -> V_42 , & V_113 -> V_115 . V_2 ) ;
}
F_133 ( V_35 ) ;
}
static int
F_135 ( struct V_270 * V_271 , struct V_124 * V_218 )
{
if ( ( V_271 -> V_272 == 0 ) ||
( V_271 -> V_273 == 0 ) ||
( V_271 -> V_274 == 0 ) )
return 0 ;
if ( V_218 -> V_275 == V_231 ) {
if ( ( V_271 -> V_273 < V_218 -> V_139 ) ||
( V_271 -> V_274 < V_218 -> V_139 ) )
return 0 ;
} else {
if ( ( V_271 -> V_273 < V_218 -> V_139 ) ||
( V_271 -> V_274 < ( 2 * V_218 -> V_139 ) ) )
return 0 ;
}
return 1 ;
}
static struct V_213 *
F_136 ( struct V_270 * V_271 )
{
struct V_213 * V_276 = NULL ;
struct V_90 * V_91 = NULL ;
F_49 ( & V_271 -> V_277 , & V_91 ) ;
V_271 -> V_274 -- ;
V_276 = (struct V_213 * ) V_91 ;
F_45 ( & V_276 -> V_91 ) ;
return V_276 ;
}
static void
F_137 ( struct V_270 * V_271 , struct V_213 * V_276 )
{
F_45 ( & V_276 -> V_91 ) ;
F_42 ( & V_276 -> V_91 , & V_271 -> V_277 ) ;
V_271 -> V_274 ++ ;
}
static struct V_112 *
F_138 ( struct V_270 * V_271 )
{
struct V_90 * V_91 = NULL ;
struct V_112 * V_113 = NULL ;
F_49 ( & V_271 -> V_278 , & V_91 ) ;
V_271 -> V_273 -- ;
V_113 = (struct V_112 * ) V_91 ;
F_45 ( & V_113 -> V_91 ) ;
return V_113 ;
}
static void
F_139 ( struct V_270 * V_271 , struct V_112 * V_113 )
{
F_45 ( & V_113 -> V_91 ) ;
F_42 ( & V_113 -> V_91 , & V_271 -> V_278 ) ;
V_271 -> V_273 ++ ;
}
static struct V_111 *
F_140 ( struct V_270 * V_271 , enum V_279 type )
{
struct V_90 * V_91 = NULL ;
struct V_111 * V_35 = NULL ;
if ( type == V_206 ) {
F_49 ( & V_271 -> V_280 , & V_91 ) ;
} else
F_141 ( & V_271 -> V_280 , & V_91 ) ;
V_271 -> V_272 -- ;
V_35 = (struct V_111 * ) V_91 ;
F_45 ( & V_35 -> V_91 ) ;
F_42 ( & V_35 -> V_91 , & V_271 -> V_281 ) ;
V_35 -> type = type ;
return V_35 ;
}
static void
F_142 ( struct V_270 * V_271 , struct V_111 * V_35 )
{
struct V_90 * V_282 = NULL ;
struct V_90 * V_91 ;
F_45 ( & V_35 -> V_91 ) ;
F_37 (qe, &rx_mod->rx_free_q) {
if ( ( (struct V_111 * ) V_91 ) -> V_36 < V_35 -> V_36 )
V_282 = V_91 ;
else
break;
}
if ( V_282 == NULL ) {
F_143 ( & V_271 -> V_280 , & V_35 -> V_91 ) ;
} else if ( F_129 ( V_282 ) == & V_271 -> V_280 ) {
F_42 ( & V_35 -> V_91 , & V_271 -> V_280 ) ;
} else {
F_129 ( & V_35 -> V_91 ) = F_129 ( V_282 ) ;
F_144 ( & V_35 -> V_91 ) = V_282 ;
F_129 ( V_282 ) = & V_35 -> V_91 ;
F_144 ( F_129 ( & V_35 -> V_91 ) ) = & V_35 -> V_91 ;
}
V_271 -> V_272 ++ ;
}
static void
F_145 ( struct V_112 * V_113 , struct V_213 * V_214 ,
struct V_213 * V_215 )
{
switch ( V_113 -> type ) {
case V_231 :
V_113 -> V_276 . V_283 . V_284 = V_214 ;
V_113 -> V_276 . V_283 . V_285 = NULL ;
break;
case V_223 :
V_113 -> V_276 . V_286 . V_287 = V_214 ;
V_113 -> V_276 . V_286 . V_288 = V_215 ;
break;
case V_224 :
V_113 -> V_276 . V_260 . V_289 = V_214 ;
V_113 -> V_276 . V_260 . V_290 = V_215 ;
break;
default:
break;
}
}
static void
F_146 ( struct V_213 * V_276 ,
struct V_112 * V_113 ,
V_6 V_291 ,
V_6 V_292 ,
struct V_293 * V_294 ,
struct V_293 * V_295 ,
struct V_293 * V_296 )
{
T_1 * V_138 ;
T_3 V_297 ;
struct V_298 V_299 ;
int V_60 ;
V_276 -> V_228 . V_300 . V_238 = V_294 -> V_297 . V_238 ;
V_276 -> V_228 . V_300 . V_240 = V_294 -> V_297 . V_240 ;
V_276 -> V_228 . V_301 = V_294 -> V_138 ;
V_276 -> V_228 . V_291 = V_291 ;
V_276 -> V_228 . V_292 = V_292 ;
V_276 -> V_302 -> V_303 = ( void * * ) V_295 -> V_138 ;
V_276 -> V_302 -> V_304 = V_296 -> V_138 ;
V_138 = V_296 -> V_138 ;
F_147 ( & V_296 -> V_297 , V_297 ) ;
for ( V_60 = 0 ; V_60 < V_276 -> V_228 . V_291 ; V_60 ++ ) {
V_276 -> V_302 -> V_303 [ V_60 ] = V_138 ;
V_138 += V_305 ;
F_148 ( V_297 , & V_299 ) ;
( (struct V_298 * ) V_276 -> V_228 . V_301 ) [ V_60 ] . V_238 =
V_299 . V_238 ;
( (struct V_298 * ) V_276 -> V_228 . V_301 ) [ V_60 ] . V_240 =
V_299 . V_240 ;
V_297 += V_305 ;
}
}
static void
F_149 ( struct V_112 * V_113 ,
V_6 V_291 ,
V_6 V_292 ,
struct V_293 * V_294 ,
struct V_293 * V_295 ,
struct V_293 * V_296 )
{
T_1 * V_138 ;
T_3 V_297 ;
struct V_298 V_299 ;
int V_60 ;
V_113 -> V_115 . V_228 . V_300 . V_238 = V_294 -> V_297 . V_238 ;
V_113 -> V_115 . V_228 . V_300 . V_240 = V_294 -> V_297 . V_240 ;
V_113 -> V_115 . V_228 . V_301 = V_294 -> V_138 ;
V_113 -> V_115 . V_228 . V_291 = V_291 ;
V_113 -> V_115 . V_228 . V_292 = V_292 ;
V_113 -> V_115 . V_116 -> V_303 = ( void * * ) V_295 -> V_138 ;
V_113 -> V_115 . V_116 -> V_304 = V_296 -> V_138 ;
V_138 = V_296 -> V_138 ;
F_147 ( & V_296 -> V_297 , V_297 ) ;
for ( V_60 = 0 ; V_60 < V_113 -> V_115 . V_228 . V_291 ; V_60 ++ ) {
V_113 -> V_115 . V_116 -> V_303 [ V_60 ] = V_138 ;
V_138 += V_305 ;
F_148 ( V_297 , & V_299 ) ;
( (struct V_298 * ) V_113 -> V_115 . V_228 . V_301 ) [ V_60 ] . V_238 =
V_299 . V_238 ;
( (struct V_298 * ) V_113 -> V_115 . V_228 . V_301 ) [ V_60 ] . V_240 =
V_299 . V_240 ;
V_297 += V_305 ;
}
}
static void
F_150 ( void * V_306 , struct V_111 * V_35 )
{
struct V_270 * V_271 = (struct V_270 * ) V_306 ;
F_151 ( & V_271 -> V_307 ) ;
}
static void
F_152 ( void * V_306 )
{
struct V_270 * V_271 = (struct V_270 * ) V_306 ;
if ( V_271 -> V_154 )
V_271 -> V_154 ( & V_271 -> V_42 -> V_220 ) ;
V_271 -> V_154 = NULL ;
}
static void
F_153 ( struct V_111 * V_35 )
{
V_35 -> V_308 |= V_309 ;
if ( V_35 -> V_308 & V_310 )
F_66 ( V_35 , V_193 ) ;
}
static void
F_154 ( struct V_111 * V_35 )
{
V_35 -> V_308 &= ~ V_309 ;
if ( V_35 -> V_311 == ( V_312 ) F_108 )
F_150 ( & V_35 -> V_42 -> V_271 , V_35 ) ;
else {
V_35 -> V_154 = F_150 ;
V_35 -> V_155 = & V_35 -> V_42 -> V_271 ;
F_66 ( V_35 , V_195 ) ;
}
}
static void
F_155 ( struct V_111 * V_35 )
{
V_35 -> V_308 &= ~ V_309 ;
F_66 ( V_35 , V_196 ) ;
}
void
F_156 ( struct V_270 * V_271 , enum V_279 type )
{
struct V_111 * V_35 ;
struct V_90 * V_91 ;
V_271 -> V_12 |= V_313 ;
if ( type == V_314 )
V_271 -> V_12 |= V_315 ;
F_37 (qe, &rx_mod->rx_active_q) {
V_35 = (struct V_111 * ) V_91 ;
if ( V_35 -> type == type )
F_153 ( V_35 ) ;
}
}
void
F_157 ( struct V_270 * V_271 , enum V_279 type )
{
struct V_111 * V_35 ;
struct V_90 * V_91 ;
V_271 -> V_12 &= ~ V_313 ;
V_271 -> V_12 &= ~ V_315 ;
V_271 -> V_154 = V_316 ;
F_158 ( & V_271 -> V_307 , F_152 , V_271 ) ;
F_37 (qe, &rx_mod->rx_active_q) {
V_35 = (struct V_111 * ) V_91 ;
if ( V_35 -> type == type ) {
F_159 ( & V_271 -> V_307 ) ;
F_154 ( V_35 ) ;
}
}
F_160 ( & V_271 -> V_307 ) ;
}
void
F_161 ( struct V_270 * V_271 )
{
struct V_111 * V_35 ;
struct V_90 * V_91 ;
V_271 -> V_12 &= ~ V_313 ;
V_271 -> V_12 &= ~ V_315 ;
F_37 (qe, &rx_mod->rx_active_q) {
V_35 = (struct V_111 * ) V_91 ;
F_155 ( V_35 ) ;
}
}
void F_162 ( struct V_270 * V_271 , struct V_42 * V_42 ,
struct V_126 * V_127 )
{
int V_178 ;
struct V_111 * V_317 ;
struct V_112 * V_318 ;
struct V_213 * V_319 ;
V_271 -> V_42 = V_42 ;
V_271 -> V_12 = 0 ;
V_271 -> V_35 = (struct V_111 * )
V_127 [ V_320 ] . V_135 . V_136 . V_137 [ 0 ] . V_138 ;
V_271 -> V_113 = (struct V_112 * )
V_127 [ V_321 ] . V_135 . V_136 . V_137 [ 0 ] . V_138 ;
V_271 -> V_276 = (struct V_213 * )
V_127 [ V_322 ] . V_135 . V_136 . V_137 [ 0 ] . V_138 ;
F_72 ( & V_271 -> V_280 ) ;
V_271 -> V_272 = 0 ;
F_72 ( & V_271 -> V_277 ) ;
V_271 -> V_274 = 0 ;
F_72 ( & V_271 -> V_278 ) ;
V_271 -> V_273 = 0 ;
F_72 ( & V_271 -> V_281 ) ;
for ( V_178 = 0 ; V_178 < V_42 -> V_323 . V_324 . V_325 ; V_178 ++ ) {
V_317 = & V_271 -> V_35 [ V_178 ] ;
F_45 ( & V_317 -> V_91 ) ;
F_72 ( & V_317 -> V_222 ) ;
V_317 -> V_42 = NULL ;
V_317 -> V_36 = V_178 ;
V_317 -> V_154 = NULL ;
V_317 -> V_155 = NULL ;
F_42 ( & V_317 -> V_91 , & V_271 -> V_280 ) ;
V_271 -> V_272 ++ ;
}
for ( V_178 = 0 ; V_178 < V_42 -> V_323 . V_324 . V_325 ; V_178 ++ ) {
V_318 = & V_271 -> V_113 [ V_178 ] ;
F_45 ( & V_318 -> V_91 ) ;
F_42 ( & V_318 -> V_91 , & V_271 -> V_278 ) ;
V_271 -> V_273 ++ ;
}
for ( V_178 = 0 ; V_178 < ( V_42 -> V_323 . V_324 . V_325 * 2 ) ; V_178 ++ ) {
V_319 = & V_271 -> V_276 [ V_178 ] ;
F_45 ( & V_319 -> V_91 ) ;
F_42 ( & V_319 -> V_91 , & V_271 -> V_277 ) ;
V_271 -> V_274 ++ ;
}
}
void
F_163 ( struct V_270 * V_271 )
{
struct V_90 * V_91 ;
int V_60 ;
V_60 = 0 ;
F_37 (qe, &rx_mod->rx_free_q)
V_60 ++ ;
V_60 = 0 ;
F_37 (qe, &rx_mod->rxp_free_q)
V_60 ++ ;
V_60 = 0 ;
F_37 (qe, &rx_mod->rxq_free_q)
V_60 ++ ;
V_271 -> V_42 = NULL ;
}
void
F_164 ( struct V_111 * V_35 , struct V_118 * V_119 )
{
struct V_326 * V_327 = & V_35 -> V_31 . V_327 ;
struct V_112 * V_113 = NULL ;
struct V_213 * V_214 = NULL , * V_215 = NULL ;
struct V_90 * V_216 ;
int V_60 ;
F_165 ( & V_35 -> V_42 -> V_43 , ( T_1 * ) V_327 ,
sizeof( struct V_326 ) ) ;
V_35 -> V_328 = V_327 -> V_328 ;
for ( V_60 = 0 , V_216 = F_128 ( & V_35 -> V_222 ) ;
V_60 < V_35 -> V_139 ;
V_60 ++ , V_216 = F_129 ( V_216 ) ) {
V_113 = (struct V_112 * ) V_216 ;
F_130 ( V_113 , V_214 , V_215 ) ;
V_113 -> V_115 . V_116 -> V_329 -> V_330 =
V_35 -> V_42 -> V_331 . V_332
+ F_166 ( V_327 -> V_333 [ V_60 ] . V_329 ) ;
V_113 -> V_328 = V_327 -> V_333 [ V_60 ] . V_334 ;
V_214 -> V_302 -> V_335 =
V_35 -> V_42 -> V_331 . V_332
+ F_166 ( V_327 -> V_333 [ V_60 ] . V_336 ) ;
V_214 -> V_328 = V_327 -> V_333 [ V_60 ] . V_337 ;
if ( V_215 ) {
V_215 -> V_302 -> V_335 =
V_35 -> V_42 -> V_331 . V_332
+ F_166 ( V_327 -> V_333 [ V_60 ] . V_338 ) ;
V_215 -> V_328 = V_327 -> V_333 [ V_60 ] . V_339 ;
}
( * V_113 -> V_115 . V_116 -> V_340 ) = 0 ;
V_113 -> V_115 . V_116 -> V_341 = 0 ;
V_214 -> V_302 -> V_341 = V_214 -> V_302 -> V_342 = 0 ;
if ( V_215 )
V_215 -> V_302 -> V_341 = V_215 -> V_302 -> V_342 = 0 ;
}
F_66 ( V_35 , V_200 ) ;
}
void
F_167 ( struct V_111 * V_35 , struct V_118 * V_119 )
{
F_66 ( V_35 , V_197 ) ;
}
void
F_168 ( struct V_124 * V_225 , struct V_126 * V_127 )
{
V_6 V_343 , V_344 , V_345 ;
V_6 V_346 , V_347 , V_348 ;
struct V_349 * V_136 ;
V_6 V_350 ;
V_6 V_351 ;
V_6 V_352 ;
V_352 = V_225 -> V_353 ;
V_351 = ( ( V_225 -> V_275 == V_231 ) ? 0 : V_225 -> V_354 ) ;
V_350 = V_352 + V_351 ;
F_169 ( V_350 ) ;
V_343 = V_350 * V_355 ;
V_343 = F_170 ( V_343 , V_305 ) ;
V_346 = F_171 ( V_343 ) ;
F_169 ( V_352 ) ;
V_345 = V_352 * V_356 ;
V_345 = F_170 ( V_345 , V_305 ) ;
V_348 = F_171 ( V_345 ) ;
if ( V_231 != V_225 -> V_275 ) {
F_169 ( V_351 ) ;
V_344 = V_351 * V_356 ;
V_344 = F_170 ( V_344 , V_305 ) ;
V_347 = F_171 ( V_344 ) ;
} else
V_347 = 0 ;
V_127 [ V_357 ] . V_358 = V_359 ;
V_136 = & V_127 [ V_357 ] . V_135 . V_136 ;
V_136 -> V_360 = V_361 ;
V_136 -> V_362 = sizeof( struct V_363 ) ;
V_136 -> V_364 = V_225 -> V_139 ;
V_127 [ V_365 ] . V_358 = V_359 ;
V_136 = & V_127 [ V_365 ] . V_135 . V_136 ;
V_136 -> V_360 = V_361 ;
V_136 -> V_362 = sizeof( struct V_366 ) ;
V_136 -> V_364 = F_172 ( V_225 ) ;
V_127 [ V_367 ] . V_358 = V_359 ;
V_136 = & V_127 [ V_367 ] . V_135 . V_136 ;
V_136 -> V_360 = V_368 ;
V_136 -> V_362 = V_346 * sizeof( struct V_298 ) ;
V_136 -> V_364 = V_225 -> V_139 ;
V_127 [ V_369 ] . V_358 = V_359 ;
V_136 = & V_127 [ V_369 ] . V_135 . V_136 ;
V_136 -> V_360 = V_361 ;
V_136 -> V_362 = V_346 * sizeof( void * ) ;
V_136 -> V_364 = V_225 -> V_139 ;
V_127 [ V_370 ] . V_358 = V_359 ;
V_136 = & V_127 [ V_370 ] . V_135 . V_136 ;
V_136 -> V_360 = V_368 ;
V_136 -> V_362 = V_305 * V_346 ;
V_136 -> V_364 = V_225 -> V_139 ;
V_127 [ V_371 ] . V_358 = V_359 ;
V_136 = & V_127 [ V_371 ] . V_135 . V_136 ;
V_136 -> V_360 = V_368 ;
V_136 -> V_362 = V_348 * sizeof( struct V_298 ) ;
V_136 -> V_364 = V_225 -> V_139 ;
V_127 [ V_372 ] . V_358 = V_359 ;
V_136 = & V_127 [ V_372 ] . V_135 . V_136 ;
V_136 -> V_360 = V_361 ;
V_136 -> V_362 = V_348 * sizeof( void * ) ;
V_136 -> V_364 = V_225 -> V_139 ;
V_127 [ V_373 ] . V_358 = V_359 ;
V_136 = & V_127 [ V_373 ] . V_135 . V_136 ;
V_136 -> V_360 = V_368 ;
V_136 -> V_362 = V_305 * V_348 ;
V_136 -> V_364 = V_225 -> V_139 ;
V_127 [ V_374 ] . V_358 = V_359 ;
V_136 = & V_127 [ V_374 ] . V_135 . V_136 ;
V_136 -> V_360 = V_368 ;
V_136 -> V_362 = V_347 * sizeof( struct V_298 ) ;
V_136 -> V_364 = ( V_347 ? V_225 -> V_139 : 0 ) ;
V_127 [ V_375 ] . V_358 = V_359 ;
V_136 = & V_127 [ V_375 ] . V_135 . V_136 ;
V_136 -> V_360 = V_361 ;
V_136 -> V_362 = V_347 * sizeof( void * ) ;
V_136 -> V_364 = ( V_347 ? V_225 -> V_139 : 0 ) ;
V_127 [ V_376 ] . V_358 = V_359 ;
V_136 = & V_127 [ V_376 ] . V_135 . V_136 ;
V_136 -> V_360 = V_368 ;
V_136 -> V_362 = V_305 * V_347 ;
V_136 -> V_364 = ( V_347 ? V_225 -> V_139 : 0 ) ;
V_127 [ V_377 ] . V_358 = V_359 ;
V_136 = & V_127 [ V_377 ] . V_135 . V_136 ;
V_136 -> V_360 = V_368 ;
V_136 -> V_362 = V_378 ;
V_136 -> V_364 = V_225 -> V_139 ;
V_127 [ V_134 ] . V_358 = V_359 ;
V_136 = & V_127 [ V_134 ] . V_135 . V_136 ;
V_136 -> V_360 = V_361 ;
V_136 -> V_362 = V_379 ;
V_136 -> V_364 = 1 ;
V_127 [ V_380 ] . V_358 = V_381 ;
V_127 [ V_380 ] . V_135 . V_382 . V_250 = V_251 ;
V_127 [ V_380 ] . V_135 . V_382 . V_364 = V_225 -> V_139 ;
}
struct V_111 *
F_173 ( struct V_42 * V_42 , struct V_158 * V_158 ,
struct V_124 * V_218 ,
const struct V_383 * V_384 ,
struct V_126 * V_127 ,
void * V_385 )
{
struct V_270 * V_271 = & V_42 -> V_271 ;
struct V_111 * V_35 ;
struct V_112 * V_113 ;
struct V_213 * V_214 ;
struct V_213 * V_215 ;
struct V_386 * V_382 ;
struct V_293 * V_387 ;
struct V_293 * V_388 ;
struct V_293 * V_389 ;
struct V_293 * V_390 ;
struct V_293 * V_391 ;
struct V_293 * V_392 ;
struct V_293 * V_393 ;
struct V_293 * V_394 ;
struct V_293 * V_395 ;
struct V_293 * V_396 ;
struct V_293 * V_397 ;
struct V_293 * V_398 ;
struct V_293 * V_399 ;
V_6 V_348 , V_347 ;
V_6 V_400 , V_401 , V_402 ;
V_6 V_350 , V_60 ;
V_6 V_291 ;
if ( ! F_135 ( V_271 , V_218 ) )
return NULL ;
V_382 = & V_127 [ V_380 ] . V_135 . V_382 ;
V_389 = & V_127 [ V_357 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_390 = & V_127 [ V_365 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_388 = & V_127 [ V_403 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_387 = & V_127 [ V_404 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_391 = & V_127 [ V_367 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_392 = & V_127 [ V_369 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_393 = & V_127 [ V_370 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_394 = & V_127 [ V_374 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_395 = & V_127 [ V_371 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_396 = & V_127 [ V_375 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_397 = & V_127 [ V_372 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_398 = & V_127 [ V_376 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_399 = & V_127 [ V_373 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_291 = V_127 [ V_370 ] . V_135 . V_136 . V_362 /
V_305 ;
V_348 = V_127 [ V_373 ] . V_135 . V_136 . V_362 /
V_305 ;
V_347 = V_127 [ V_376 ] . V_135 . V_136 . V_362 /
V_305 ;
V_35 = F_140 ( V_271 , V_218 -> V_405 ) ;
V_35 -> V_42 = V_42 ;
V_35 -> V_308 = 0 ;
F_72 ( & V_35 -> V_222 ) ;
V_35 -> V_154 = NULL ;
V_35 -> V_155 = NULL ;
V_35 -> V_385 = V_385 ;
V_35 -> V_406 = V_384 -> V_406 ;
V_35 -> V_407 = V_384 -> V_407 ;
V_35 -> V_408 = V_384 -> V_408 ;
V_35 -> V_409 = V_384 -> V_409 ;
V_35 -> V_410 = V_384 -> V_410 ;
V_35 -> V_199 = V_384 -> V_199 ;
V_35 -> V_203 = V_384 -> V_203 ;
if ( V_35 -> V_42 -> V_271 . V_12 & V_313 ) {
switch ( V_35 -> type ) {
case V_206 :
if ( ! ( V_35 -> V_42 -> V_271 . V_12 &
V_315 ) )
V_35 -> V_308 |= V_309 ;
break;
case V_314 :
if ( V_35 -> V_42 -> V_271 . V_12 & V_315 )
V_35 -> V_308 |= V_309 ;
break;
}
}
V_35 -> V_139 = V_218 -> V_139 ;
for ( V_60 = 0 , V_400 = 0 , V_401 = 0 , V_402 = 0 ;
V_60 < V_35 -> V_139 ; V_60 ++ ) {
V_113 = F_138 ( V_271 ) ;
F_42 ( & V_113 -> V_91 , & V_35 -> V_222 ) ;
V_113 -> type = V_218 -> V_275 ;
V_113 -> V_35 = V_35 ;
V_113 -> V_115 . V_35 = V_35 ;
V_214 = F_136 ( V_271 ) ;
if ( V_231 == V_218 -> V_275 )
V_215 = NULL ;
else
V_215 = F_136 ( V_271 ) ;
if ( 1 == V_382 -> V_364 )
V_113 -> V_411 = V_382 -> V_412 [ 0 ] . V_411 ;
else
V_113 -> V_411 = V_382 -> V_412 [ V_60 ] . V_411 ;
V_113 -> V_115 . V_2 . V_237 . V_238 =
V_127 [ V_377 ] . V_135 . V_136 . V_137 [ V_60 ] . V_297 . V_238 ;
V_113 -> V_115 . V_2 . V_237 . V_240 =
V_127 [ V_377 ] . V_135 . V_136 . V_137 [ V_60 ] . V_297 . V_240 ;
V_113 -> V_115 . V_2 . V_413 =
V_127 [ V_377 ] . V_135 . V_136 . V_137 [ V_60 ] . V_138 ;
V_113 -> V_115 . V_2 . V_250 = V_382 -> V_250 ;
if ( V_382 -> V_250 == V_251 )
V_113 -> V_115 . V_2 . V_243 = V_113 -> V_411 ;
else
V_113 -> V_115 . V_2 . V_243 = ( 1 << V_113 -> V_411 ) ;
V_113 -> V_115 . V_2 . V_3 = V_218 -> V_3 ;
V_113 -> V_115 . V_2 . V_256 = V_414 ;
V_113 -> V_115 . V_2 . V_254 = V_415 ;
F_145 ( V_113 , V_214 , V_215 ) ;
V_214 -> V_35 = V_35 ;
V_214 -> V_113 = V_113 ;
V_214 -> V_302 = (struct V_366 * ) V_390 [ V_402 ] . V_138 ;
V_214 -> V_302 -> V_416 = ( void * ) V_388 [ V_401 ] . V_138 ;
V_402 ++ ; V_401 ++ ;
V_214 -> V_302 -> V_417 = V_218 -> V_353 ;
V_214 -> V_417 = V_218 -> V_353 ;
V_214 -> V_233 = V_218 -> V_418 ;
V_214 -> V_230 = V_218 -> V_419 ;
V_214 -> V_420 = V_218 -> V_421 ;
V_214 -> V_302 -> V_276 = V_214 ;
V_214 -> V_302 -> V_158 = V_42 -> V_158 ;
V_214 -> V_302 -> V_117 = 0 ;
V_214 -> V_422 = V_214 -> V_423 = 0 ;
V_214 -> V_424 = V_214 -> V_425 = 0 ;
F_146 ( V_214 , V_113 , V_348 , V_305 ,
& V_395 [ V_60 ] , & V_397 [ V_60 ] , & V_399 [ V_60 ] ) ;
if ( V_35 -> V_406 )
V_35 -> V_406 ( V_158 , V_214 -> V_302 ) ;
if ( V_215 ) {
V_215 -> V_35 = V_35 ;
V_215 -> V_113 = V_113 ;
V_215 -> V_302 = (struct V_366 * ) V_390 [ V_402 ] . V_138 ;
V_215 -> V_302 -> V_416 = ( void * ) V_387 [ V_400 ] . V_138 ;
V_402 ++ ; V_400 ++ ;
V_215 -> V_302 -> V_417 = V_218 -> V_354 ;
V_215 -> V_417 = V_218 -> V_354 ;
V_215 -> V_233 = V_141 ;
V_215 -> V_420 = 1 ;
V_215 -> V_302 -> V_276 = V_215 ;
V_215 -> V_302 -> V_158 = V_42 -> V_158 ;
V_215 -> V_302 -> V_117 = 1 ;
V_215 -> V_230 = ( V_218 -> V_275 == V_224 ) ?
V_218 -> V_426 . V_264
: V_218 -> V_427 ;
V_215 -> V_422 = V_215 -> V_423 = 0 ;
V_215 -> V_424 = V_215 -> V_425 = 0 ;
F_146 ( V_215 , V_113 , V_347 , V_305 ,
& V_394 [ V_60 ] , & V_396 [ V_60 ] ,
& V_398 [ V_60 ] ) ;
if ( V_35 -> V_406 )
V_35 -> V_406 ( V_158 , V_215 -> V_302 ) ;
}
V_113 -> V_115 . V_116 = (struct V_363 * ) V_389 [ V_60 ] . V_138 ;
V_350 = V_218 -> V_353 +
( ( V_218 -> V_275 == V_231 ) ?
0 : V_218 -> V_354 ) ;
F_169 ( V_350 ) ;
V_113 -> V_115 . V_116 -> V_417 = V_350 ;
V_113 -> V_115 . V_116 -> V_115 = & V_113 -> V_115 ;
V_113 -> V_115 . V_116 -> V_302 [ 0 ] = V_214 -> V_302 ;
V_214 -> V_302 -> V_116 = V_113 -> V_115 . V_116 ;
if ( V_215 ) {
V_113 -> V_115 . V_116 -> V_302 [ 1 ] = V_215 -> V_302 ;
V_215 -> V_302 -> V_116 = V_113 -> V_115 . V_116 ;
}
V_113 -> V_115 . V_116 -> V_340 =
( V_6 * ) V_113 -> V_115 . V_2 . V_413 ;
V_113 -> V_115 . V_116 -> V_329 = & V_113 -> V_115 . V_2 . V_4 ;
V_113 -> V_115 . V_116 -> V_250 = V_113 -> V_115 . V_2 . V_250 ;
V_113 -> V_115 . V_116 -> V_243 = V_113 -> V_115 . V_2 . V_243 ;
V_113 -> V_115 . V_116 -> V_428 =
V_113 -> V_115 . V_2 . V_3 ;
V_113 -> V_115 . V_116 -> V_429 . V_430 = 0 ;
V_113 -> V_115 . V_116 -> V_429 . V_431 = 0 ;
V_113 -> V_115 . V_116 -> V_158 = V_42 -> V_158 ;
V_113 -> V_115 . V_116 -> V_117 = V_60 ;
F_149 ( V_113 , V_291 , V_305 ,
& V_391 [ V_60 ] , & V_392 [ V_60 ] , & V_393 [ V_60 ] ) ;
if ( V_35 -> V_408 )
V_35 -> V_408 ( V_158 , V_113 -> V_115 . V_116 ) ;
}
V_35 -> V_261 = V_218 -> V_426 ;
F_71 ( & V_35 -> V_8 , V_35 , V_218 , V_127 ) ;
F_6 ( V_35 , F_108 ) ;
V_271 -> V_432 |= ( 1 << V_35 -> V_36 ) ;
return V_35 ;
}
void
F_174 ( struct V_111 * V_35 )
{
struct V_270 * V_271 = & V_35 -> V_42 -> V_271 ;
struct V_213 * V_214 = NULL ;
struct V_213 * V_215 = NULL ;
struct V_112 * V_113 ;
struct V_90 * V_91 ;
F_73 ( & V_35 -> V_8 ) ;
while ( ! F_48 ( & V_35 -> V_222 ) ) {
F_49 ( & V_35 -> V_222 , & V_113 ) ;
F_130 ( V_113 , V_214 , V_215 ) ;
if ( V_35 -> V_407 )
V_35 -> V_407 ( V_35 -> V_42 -> V_158 , V_214 -> V_302 ) ;
V_214 -> V_302 = NULL ;
V_214 -> V_113 = NULL ;
V_214 -> V_35 = NULL ;
F_137 ( V_271 , V_214 ) ;
if ( V_215 ) {
if ( V_35 -> V_407 )
V_35 -> V_407 ( V_35 -> V_42 -> V_158 , V_215 -> V_302 ) ;
V_215 -> V_302 = NULL ;
V_215 -> V_113 = NULL ;
V_215 -> V_35 = NULL ;
F_137 ( V_271 , V_215 ) ;
}
V_113 -> V_276 . V_286 . V_287 = NULL ;
V_113 -> V_276 . V_286 . V_288 = NULL ;
if ( V_35 -> V_409 )
V_35 -> V_409 ( V_35 -> V_42 -> V_158 , V_113 -> V_115 . V_116 ) ;
V_113 -> V_115 . V_116 = NULL ;
V_113 -> V_35 = NULL ;
F_139 ( V_271 , V_113 ) ;
}
F_37 (qe, &rx_mod->rx_active_q) {
if ( V_91 == & V_35 -> V_91 ) {
F_44 ( & V_35 -> V_91 ) ;
F_45 ( & V_35 -> V_91 ) ;
break;
}
}
V_271 -> V_432 &= ~ ( 1 << V_35 -> V_36 ) ;
V_35 -> V_42 = NULL ;
V_35 -> V_385 = NULL ;
F_142 ( V_271 , V_35 ) ;
}
void
F_175 ( struct V_111 * V_35 )
{
if ( V_35 -> V_311 != ( V_433 ) F_108 )
return;
V_35 -> V_308 |= V_310 ;
if ( V_35 -> V_308 & V_309 )
F_66 ( V_35 , V_193 ) ;
}
void
F_176 ( struct V_111 * V_35 , enum V_98 type ,
void (* F_82)( void * , struct V_111 * ) )
{
if ( type == V_110 ) {
(* F_82)( V_35 -> V_42 -> V_158 , V_35 ) ;
} else {
V_35 -> V_154 = F_82 ;
V_35 -> V_155 = V_35 -> V_42 -> V_158 ;
V_35 -> V_308 &= ~ V_310 ;
F_66 ( V_35 , V_195 ) ;
}
}
void
F_177 ( struct V_111 * V_35 )
{
F_66 ( V_35 , V_209 ) ;
}
void
F_178 ( struct V_111 * V_35 )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
if ( V_8 -> V_69 == V_141 ) {
V_8 -> V_69 = V_65 ;
V_8 -> V_149 = true ;
F_66 ( V_8 , V_18 ) ;
}
}
void
F_179 ( struct V_111 * V_35 )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
if ( V_8 -> V_69 != V_141 ) {
V_8 -> V_69 = V_141 ;
V_8 -> V_149 = true ;
F_66 ( V_8 , V_18 ) ;
}
}
enum V_156
F_180 ( struct V_111 * V_35 , enum V_434 V_435 ,
enum V_434 V_436 ,
void (* F_82)( struct V_158 * , struct V_111 * ) )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
int V_176 = 0 ;
if ( F_92 ( V_435 , V_436 ) ) {
if ( ( V_35 -> V_42 -> V_146 != V_147 ) &&
( V_35 -> V_42 -> V_146 != V_8 -> V_35 -> V_36 ) )
goto V_173;
if ( V_35 -> V_42 -> V_148 != V_147 )
goto V_173;
if ( F_181 ( V_435 , V_436 ) )
goto V_173;
}
if ( F_181 ( V_435 , V_436 ) ) {
if ( ( V_35 -> V_42 -> V_148 != V_147 ) &&
( V_35 -> V_42 -> V_148 != V_8 -> V_35 -> V_36 ) ) {
goto V_173;
}
if ( V_35 -> V_42 -> V_146 != V_147 )
goto V_173;
}
if ( F_92 ( V_435 , V_436 ) ) {
if ( F_100 ( V_8 ) )
V_176 = 1 ;
} else if ( F_94 ( V_435 , V_436 ) ) {
if ( F_101 ( V_8 ) )
V_176 = 1 ;
}
if ( F_96 ( V_435 , V_436 ) ) {
if ( F_103 ( V_8 ) )
V_176 = 1 ;
} else if ( F_98 ( V_435 , V_436 ) ) {
if ( F_104 ( V_8 ) )
V_176 = 1 ;
}
if ( V_176 ) {
V_8 -> V_161 = F_82 ;
V_8 -> V_162 = V_35 -> V_42 -> V_158 ;
F_66 ( V_8 , V_18 ) ;
} else if ( F_82 )
(* F_82)( V_35 -> V_42 -> V_158 , V_35 ) ;
return V_163 ;
V_173:
return V_437 ;
}
void
F_182 ( struct V_111 * V_35 )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
if ( V_8 -> V_64 == V_141 ) {
V_8 -> V_64 = V_65 ;
V_8 -> V_105 = ( T_1 ) V_143 ;
F_66 ( V_8 , V_18 ) ;
}
}
void
F_183 ( struct V_111 * V_35 , int V_3 )
{
struct V_112 * V_113 ;
struct V_90 * V_91 ;
F_37 (qe, &rx->rxp_q) {
V_113 = (struct V_112 * ) V_91 ;
V_113 -> V_115 . V_116 -> V_428 = V_3 ;
F_1 ( & V_113 -> V_115 . V_2 , V_3 ) ;
}
}
void
F_184 ( struct V_42 * V_42 , const V_6 V_411 [] [ V_438 ] )
{
int V_60 , V_61 ;
for ( V_60 = 0 ; V_60 < V_439 ; V_60 ++ )
for ( V_61 = 0 ; V_61 < V_438 ; V_61 ++ )
V_42 -> V_271 . V_440 [ V_60 ] [ V_61 ] = V_411 [ V_60 ] [ V_61 ] ;
}
void
F_185 ( struct V_363 * V_116 )
{
struct V_42 * V_42 = V_116 -> V_115 -> V_35 -> V_42 ;
V_6 V_441 , V_442 ;
V_6 V_443 , V_444 , V_445 ;
T_1 V_3 ;
if ( ( V_116 -> V_429 . V_430 == 0 ) &&
( V_116 -> V_429 . V_431 == 0 ) )
return;
V_444 = V_116 -> V_429 . V_430 ;
V_445 = V_116 -> V_429 . V_431 ;
V_443 = V_444 + V_445 ;
if ( V_443 < V_446 )
V_441 = V_447 ;
else if ( V_443 < V_448 )
V_441 = V_449 ;
else if ( V_443 < V_450 )
V_441 = V_451 ;
else if ( V_443 < V_452 )
V_441 = V_453 ;
else if ( V_443 < V_454 )
V_441 = V_455 ;
else if ( V_443 < V_456 )
V_441 = V_457 ;
else if ( V_443 < V_458 )
V_441 = V_459 ;
else
V_441 = V_460 ;
if ( V_444 > ( V_445 << 1 ) )
V_442 = 0 ;
else
V_442 = 1 ;
V_116 -> V_429 . V_430 = 0 ;
V_116 -> V_429 . V_431 = 0 ;
V_3 = V_42 -> V_271 . V_440 [ V_441 ] [ V_442 ] ;
V_116 -> V_428 = V_3 ;
F_1 ( & V_116 -> V_115 -> V_2 , V_3 ) ;
}
static void
F_186 ( struct V_461 * V_462 )
{
F_187 ( V_462 ) ;
}
static void
F_188 ( struct V_461 * V_462 , enum V_463 V_10 )
{
switch ( V_10 ) {
case V_464 :
F_6 ( V_462 , V_465 ) ;
break;
case V_466 :
F_187 ( V_462 ) ;
break;
case V_467 :
break;
case V_468 :
F_189 ( V_462 ) ;
break;
case V_469 :
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_190 ( struct V_461 * V_462 )
{
F_191 ( V_462 ) ;
}
static void
V_465 ( struct V_461 * V_462 , enum V_463 V_10 )
{
switch ( V_10 ) {
case V_466 :
V_462 -> V_12 &= ~ ( V_470 | V_471 ) ;
F_6 ( V_462 , V_472 ) ;
break;
case V_467 :
V_462 -> V_12 &= ~ ( V_470 | V_471 ) ;
F_6 ( V_462 , F_188 ) ;
break;
case V_473 :
if ( V_462 -> V_12 & ( V_470 | V_471 ) ) {
V_462 -> V_12 &= ~ ( V_470 |
V_471 ) ;
F_6 ( V_462 , V_474 ) ;
} else
F_6 ( V_462 , V_475 ) ;
break;
case V_468 :
V_462 -> V_12 |= V_470 ;
break;
case V_469 :
V_462 -> V_12 |= V_471 ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_192 ( struct V_461 * V_462 )
{
struct V_476 * V_477 ;
struct V_90 * V_91 ;
int V_205 = ( V_462 -> type == V_478 ) ;
F_37 (qe, &tx->txq_q) {
V_477 = (struct V_476 * ) V_91 ;
V_477 -> V_479 -> V_480 = V_477 -> V_480 ;
F_120 ( V_462 -> V_42 , & V_477 -> V_2 , V_205 ) ;
}
V_462 -> V_481 ( V_462 -> V_42 -> V_158 , V_462 ) ;
}
static void
V_475 ( struct V_461 * V_462 , enum V_463 V_10 )
{
switch ( V_10 ) {
case V_466 :
F_6 ( V_462 , V_472 ) ;
V_462 -> V_482 ( V_462 -> V_42 -> V_158 , V_462 ) ;
F_193 ( V_462 ) ;
break;
case V_467 :
F_6 ( V_462 , V_483 ) ;
V_462 -> V_482 ( V_462 -> V_42 -> V_158 , V_462 ) ;
V_462 -> V_484 ( V_462 -> V_42 -> V_158 , V_462 ) ;
break;
case V_468 :
case V_469 :
F_6 ( V_462 , V_474 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_194 ( struct V_461 * V_462 )
{
}
static void
V_472 ( struct V_461 * V_462 , enum V_463 V_10 )
{
switch ( V_10 ) {
case V_467 :
case V_485 :
F_6 ( V_462 , V_486 ) ;
V_462 -> V_484 ( V_462 -> V_42 -> V_158 , V_462 ) ;
break;
case V_473 :
F_193 ( V_462 ) ;
break;
case V_468 :
case V_469 :
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_195 ( struct V_461 * V_462 )
{
}
static void
V_486 ( struct V_461 * V_462 , enum V_463 V_10 )
{
switch ( V_10 ) {
case V_467 :
case V_468 :
case V_469 :
break;
case V_487 :
F_6 ( V_462 , F_188 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_196 ( struct V_461 * V_462 )
{
V_462 -> V_482 ( V_462 -> V_42 -> V_158 , V_462 ) ;
F_193 ( V_462 ) ;
}
static void
V_474 ( struct V_461 * V_462 , enum V_463 V_10 )
{
switch ( V_10 ) {
case V_466 :
F_6 ( V_462 , V_472 ) ;
break;
case V_467 :
F_6 ( V_462 , V_483 ) ;
F_189 ( V_462 ) ;
V_462 -> V_484 ( V_462 -> V_42 -> V_158 , V_462 ) ;
break;
case V_485 :
F_6 ( V_462 , V_488 ) ;
break;
case V_468 :
case V_469 :
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_197 ( struct V_461 * V_462 )
{
F_189 ( V_462 ) ;
V_462 -> V_484 ( V_462 -> V_42 -> V_158 , V_462 ) ;
}
static void
V_488 ( struct V_461 * V_462 , enum V_463 V_10 )
{
switch ( V_10 ) {
case V_466 :
F_6 ( V_462 , V_486 ) ;
break;
case V_467 :
F_6 ( V_462 , V_483 ) ;
break;
case V_468 :
case V_469 :
break;
case V_487 :
F_6 ( V_462 , V_465 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_198 ( struct V_461 * V_462 )
{
}
static void
V_483 ( struct V_461 * V_462 , enum V_463 V_10 )
{
switch ( V_10 ) {
case V_464 :
F_6 ( V_462 , V_489 ) ;
break;
case V_466 :
F_6 ( V_462 , V_486 ) ;
break;
case V_467 :
break;
case V_487 :
F_6 ( V_462 , F_188 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_199 ( struct V_461 * V_462 )
{
}
static void
V_489 ( struct V_461 * V_462 , enum V_463 V_10 )
{
switch ( V_10 ) {
case V_466 :
F_6 ( V_462 , V_486 ) ;
break;
case V_467 :
F_6 ( V_462 , V_483 ) ;
break;
case V_487 :
F_6 ( V_462 , V_465 ) ;
break;
case V_469 :
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_191 ( struct V_461 * V_462 )
{
struct V_490 * V_212 = & V_462 -> V_31 . V_212 ;
struct V_476 * V_477 = NULL ;
struct V_90 * V_91 ;
int V_60 ;
F_21 ( V_212 -> V_33 , V_34 ,
V_491 , 0 , V_462 -> V_36 ) ;
V_212 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_490 ) ) ) ;
V_212 -> V_492 = V_462 -> V_493 ;
for ( V_60 = 0 , V_91 = F_128 ( & V_462 -> V_494 ) ;
V_60 < V_462 -> V_493 ;
V_60 ++ , V_91 = F_129 ( V_91 ) ) {
V_477 = (struct V_476 * ) V_91 ;
F_131 ( & V_212 -> V_225 [ V_60 ] . V_227 . V_227 , & V_477 -> V_228 ) ;
V_212 -> V_225 [ V_60 ] . V_227 . V_480 = V_477 -> V_480 ;
V_212 -> V_225 [ V_60 ] . V_2 . V_234 . V_235 . V_236 =
V_477 -> V_2 . V_237 . V_238 ;
V_212 -> V_225 [ V_60 ] . V_2 . V_234 . V_235 . V_239 =
V_477 -> V_2 . V_237 . V_240 ;
V_212 -> V_225 [ V_60 ] . V_2 . V_241 . V_242 =
F_22 ( ( T_2 ) V_477 -> V_2 . V_243 ) ;
}
V_212 -> V_244 . V_245 = V_65 ;
V_212 -> V_244 . V_246 = V_65 ;
V_212 -> V_244 . V_247 = V_141 ;
V_212 -> V_244 . V_248 = V_65 ;
V_212 -> V_244 . V_249 = ( V_477 -> V_2 . V_250 == V_251 )
? V_65 : V_141 ;
V_212 -> V_244 . V_252 =
F_31 ( ( V_6 ) V_477 -> V_2 . V_3 ) ;
V_212 -> V_244 . V_253 =
F_31 ( ( V_6 ) V_477 -> V_2 . V_254 ) ;
V_212 -> V_244 . V_255 = ( T_1 ) V_477 -> V_2 . V_256 ;
V_212 -> V_495 . V_496 = V_497 ;
V_212 -> V_495 . V_177 = F_22 ( ( T_2 ) V_462 -> V_498 ) ;
V_212 -> V_495 . V_499 = V_65 ;
V_212 -> V_495 . V_500 = V_141 ;
F_24 ( & V_462 -> V_41 , NULL , NULL ,
sizeof( struct V_490 ) , & V_212 -> V_33 ) ;
F_25 ( & V_462 -> V_42 -> V_43 , & V_462 -> V_41 ) ;
}
static void
F_200 ( struct V_461 * V_462 )
{
struct V_268 * V_30 = & V_462 -> V_31 . V_30 ;
F_21 ( V_30 -> V_33 , V_34 ,
V_501 , 0 , V_462 -> V_36 ) ;
V_30 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_268 ) ) ) ;
F_24 ( & V_462 -> V_41 , NULL , NULL , sizeof( struct V_268 ) ,
& V_30 -> V_33 ) ;
F_25 ( & V_462 -> V_42 -> V_43 , & V_462 -> V_41 ) ;
}
static void
F_193 ( struct V_461 * V_462 )
{
struct V_476 * V_477 ;
struct V_90 * V_91 ;
F_37 (qe, &tx->txq_q) {
V_477 = (struct V_476 * ) V_91 ;
F_134 ( V_462 -> V_42 , & V_477 -> V_2 ) ;
}
F_200 ( V_462 ) ;
}
static void
F_201 ( struct V_476 * V_477 , int V_291 , int V_292 ,
struct V_293 * V_294 ,
struct V_293 * V_295 ,
struct V_293 * V_296 )
{
T_1 * V_138 ;
T_3 V_297 ;
struct V_298 V_299 ;
int V_60 ;
V_477 -> V_228 . V_300 . V_238 = V_294 -> V_297 . V_238 ;
V_477 -> V_228 . V_300 . V_240 = V_294 -> V_297 . V_240 ;
V_477 -> V_228 . V_301 = V_294 -> V_138 ;
V_477 -> V_228 . V_291 = V_291 ;
V_477 -> V_228 . V_292 = V_292 ;
V_477 -> V_479 -> V_303 = ( void * * ) V_295 -> V_138 ;
V_477 -> V_479 -> V_304 = V_296 -> V_138 ;
V_138 = V_296 -> V_138 ;
F_147 ( & V_296 -> V_297 , V_297 ) ;
for ( V_60 = 0 ; V_60 < V_291 ; V_60 ++ ) {
V_477 -> V_479 -> V_303 [ V_60 ] = V_138 ;
V_138 += V_305 ;
F_148 ( V_297 , & V_299 ) ;
( (struct V_298 * ) V_477 -> V_228 . V_301 ) [ V_60 ] . V_238 =
V_299 . V_238 ;
( (struct V_298 * ) V_477 -> V_228 . V_301 ) [ V_60 ] . V_240 =
V_299 . V_240 ;
V_297 += V_305 ;
}
}
static struct V_461 *
F_202 ( struct V_502 * V_503 , enum V_504 type )
{
struct V_90 * V_91 = NULL ;
struct V_461 * V_462 = NULL ;
if ( F_48 ( & V_503 -> V_505 ) )
return NULL ;
if ( type == V_478 ) {
F_49 ( & V_503 -> V_505 , & V_91 ) ;
} else {
F_141 ( & V_503 -> V_505 , & V_91 ) ;
}
V_462 = (struct V_461 * ) V_91 ;
F_45 ( & V_462 -> V_91 ) ;
V_462 -> type = type ;
return V_462 ;
}
static void
F_203 ( struct V_461 * V_462 )
{
struct V_502 * V_503 = & V_462 -> V_42 -> V_503 ;
struct V_476 * V_477 ;
struct V_90 * V_282 ;
struct V_90 * V_91 ;
while ( ! F_48 ( & V_462 -> V_494 ) ) {
F_49 ( & V_462 -> V_494 , & V_477 ) ;
F_45 ( & V_477 -> V_91 ) ;
V_477 -> V_479 = NULL ;
V_477 -> V_462 = NULL ;
F_42 ( & V_477 -> V_91 , & V_503 -> V_506 ) ;
}
F_37 (qe, &tx_mod->tx_active_q) {
if ( V_91 == & V_462 -> V_91 ) {
F_44 ( & V_462 -> V_91 ) ;
F_45 ( & V_462 -> V_91 ) ;
break;
}
}
V_462 -> V_42 = NULL ;
V_462 -> V_385 = NULL ;
V_282 = NULL ;
F_37 (qe, &tx_mod->tx_free_q) {
if ( ( (struct V_461 * ) V_91 ) -> V_36 < V_462 -> V_36 )
V_282 = V_91 ;
else {
break;
}
}
if ( V_282 == NULL ) {
F_143 ( & V_503 -> V_505 , & V_462 -> V_91 ) ;
} else if ( F_129 ( V_282 ) == & V_503 -> V_505 ) {
F_42 ( & V_462 -> V_91 , & V_503 -> V_505 ) ;
} else {
F_129 ( & V_462 -> V_91 ) = F_129 ( V_282 ) ;
F_144 ( & V_462 -> V_91 ) = V_282 ;
F_129 ( V_282 ) = & V_462 -> V_91 ;
F_144 ( F_129 ( & V_462 -> V_91 ) ) = & V_462 -> V_91 ;
}
}
static void
F_204 ( struct V_461 * V_462 )
{
V_462 -> V_12 |= V_507 ;
if ( V_462 -> V_12 & V_508 )
F_66 ( V_462 , V_464 ) ;
}
static void
F_205 ( struct V_461 * V_462 )
{
V_462 -> V_154 = V_509 ;
V_462 -> V_155 = & V_462 -> V_42 -> V_503 ;
V_462 -> V_12 &= ~ V_507 ;
F_66 ( V_462 , V_466 ) ;
}
static void
F_206 ( struct V_461 * V_462 )
{
V_462 -> V_12 &= ~ V_507 ;
F_66 ( V_462 , V_467 ) ;
}
void
F_207 ( struct V_461 * V_462 , struct V_118 * V_119 )
{
struct V_510 * V_327 = & V_462 -> V_31 . V_327 ;
struct V_476 * V_477 = NULL ;
struct V_90 * V_91 ;
int V_60 ;
F_165 ( & V_462 -> V_42 -> V_43 , ( T_1 * ) V_327 ,
sizeof( struct V_510 ) ) ;
V_462 -> V_328 = V_327 -> V_328 ;
for ( V_60 = 0 , V_91 = F_128 ( & V_462 -> V_494 ) ;
V_60 < V_462 -> V_493 ; V_60 ++ , V_91 = F_129 ( V_91 ) ) {
V_477 = (struct V_476 * ) V_91 ;
V_477 -> V_479 -> V_329 -> V_330 =
V_462 -> V_42 -> V_331 . V_332
+ F_166 ( V_327 -> V_333 [ V_60 ] . V_329 ) ;
V_477 -> V_479 -> V_335 =
V_462 -> V_42 -> V_331 . V_332
+ F_166 ( V_327 -> V_333 [ V_60 ] . V_335 ) ;
V_477 -> V_328 = V_327 -> V_333 [ V_60 ] . V_511 ;
( * V_477 -> V_479 -> V_512 ) = 0 ;
V_477 -> V_479 -> V_341 = V_477 -> V_479 -> V_342 = 0 ;
}
F_66 ( V_462 , V_473 ) ;
}
void
F_208 ( struct V_461 * V_462 , struct V_118 * V_119 )
{
F_66 ( V_462 , V_485 ) ;
}
void
F_209 ( struct V_502 * V_503 )
{
struct V_461 * V_462 ;
struct V_90 * V_91 ;
F_37 (qe, &tx_mod->tx_active_q) {
V_462 = (struct V_461 * ) V_91 ;
F_66 ( V_462 , V_469 ) ;
}
}
void
F_210 ( int V_493 , int V_513 , struct V_126 * V_127 )
{
V_6 V_514 ;
V_6 V_291 ;
struct V_349 * V_136 ;
V_127 [ V_515 ] . V_358 = V_359 ;
V_136 = & V_127 [ V_515 ] . V_135 . V_136 ;
V_136 -> V_360 = V_361 ;
V_136 -> V_362 = sizeof( struct V_516 ) ;
V_136 -> V_364 = V_493 ;
V_514 = V_513 * V_517 ;
V_514 = F_170 ( V_514 , V_305 ) ;
V_291 = V_514 >> V_518 ;
V_127 [ V_519 ] . V_358 = V_359 ;
V_136 = & V_127 [ V_519 ] . V_135 . V_136 ;
V_136 -> V_360 = V_368 ;
V_136 -> V_362 = V_291 * sizeof( struct V_298 ) ;
V_136 -> V_364 = V_493 ;
V_127 [ V_520 ] . V_358 = V_359 ;
V_136 = & V_127 [ V_520 ] . V_135 . V_136 ;
V_136 -> V_360 = V_361 ;
V_136 -> V_362 = V_291 * sizeof( void * ) ;
V_136 -> V_364 = V_493 ;
V_127 [ V_521 ] . V_358 = V_359 ;
V_136 = & V_127 [ V_521 ] . V_135 . V_136 ;
V_136 -> V_360 = V_368 ;
V_136 -> V_362 = V_305 * V_291 ;
V_136 -> V_364 = V_493 ;
V_127 [ V_522 ] . V_358 = V_359 ;
V_136 = & V_127 [ V_522 ] . V_135 . V_136 ;
V_136 -> V_360 = V_368 ;
V_136 -> V_362 = V_378 ;
V_136 -> V_364 = V_493 ;
V_127 [ V_523 ] . V_358 = V_381 ;
V_127 [ V_523 ] . V_135 . V_382 . V_250 =
V_251 ;
V_127 [ V_523 ] . V_135 . V_382 . V_364 = V_493 ;
}
struct V_461 *
F_211 ( struct V_42 * V_42 , struct V_158 * V_158 ,
struct V_524 * V_495 ,
const struct V_525 * V_526 ,
struct V_126 * V_127 , void * V_385 )
{
struct V_386 * V_382 ;
struct V_502 * V_503 = & V_42 -> V_503 ;
struct V_461 * V_462 ;
struct V_476 * V_477 ;
struct V_90 * V_91 ;
int V_291 ;
int V_60 ;
V_382 = & V_127 [ V_523 ] . V_135 . V_382 ;
V_291 = ( V_127 [ V_521 ] . V_135 . V_136 . V_362 ) /
V_305 ;
if ( ( V_382 -> V_364 != 1 ) && ( V_382 -> V_364 != V_495 -> V_493 ) )
return NULL ;
V_462 = F_202 ( V_503 , V_495 -> V_527 ) ;
if ( ! V_462 )
return NULL ;
V_462 -> V_42 = V_42 ;
V_462 -> V_385 = V_385 ;
F_72 ( & V_462 -> V_494 ) ;
for ( V_60 = 0 ; V_60 < V_495 -> V_493 ; V_60 ++ ) {
if ( F_48 ( & V_503 -> V_506 ) )
goto V_173;
F_49 ( & V_503 -> V_506 , & V_477 ) ;
F_45 ( & V_477 -> V_91 ) ;
F_42 ( & V_477 -> V_91 , & V_462 -> V_494 ) ;
V_477 -> V_462 = V_462 ;
}
V_462 -> V_528 = V_526 -> V_528 ;
V_462 -> V_529 = V_526 -> V_529 ;
V_462 -> V_482 = V_526 -> V_482 ;
V_462 -> V_481 = V_526 -> V_481 ;
V_462 -> V_484 = V_526 -> V_484 ;
F_42 ( & V_462 -> V_91 , & V_503 -> V_530 ) ;
V_462 -> V_493 = V_495 -> V_493 ;
V_462 -> V_12 = 0 ;
if ( V_462 -> V_42 -> V_503 . V_12 & V_531 ) {
switch ( V_462 -> type ) {
case V_478 :
if ( ! ( V_462 -> V_42 -> V_503 . V_12 &
V_532 ) )
V_462 -> V_12 |= V_507 ;
break;
case V_533 :
if ( V_462 -> V_42 -> V_503 . V_12 & V_532 )
V_462 -> V_12 |= V_507 ;
break;
}
}
V_60 = 0 ;
F_37 (qe, &tx->txq_q) {
V_477 = (struct V_476 * ) V_91 ;
V_477 -> V_479 = (struct V_516 * )
V_127 [ V_515 ] . V_135 . V_136 . V_137 [ V_60 ] . V_138 ;
V_477 -> V_534 = 0 ;
V_477 -> V_535 = 0 ;
V_477 -> V_2 . V_237 . V_238 =
V_127 [ V_522 ] . V_135 . V_136 . V_137 [ V_60 ] . V_297 . V_238 ;
V_477 -> V_2 . V_237 . V_240 =
V_127 [ V_522 ] . V_135 . V_136 . V_137 [ V_60 ] . V_297 . V_240 ;
V_477 -> V_2 . V_413 =
V_127 [ V_522 ] . V_135 . V_136 . V_137 [ V_60 ] . V_138 ;
V_477 -> V_2 . V_250 = V_382 -> V_250 ;
V_477 -> V_2 . V_243 = ( V_382 -> V_364 == 1 ) ?
V_382 -> V_412 [ 0 ] . V_411 :
V_382 -> V_412 [ V_60 ] . V_411 ;
if ( V_382 -> V_250 == V_536 )
V_477 -> V_2 . V_243 = ( 1 << V_477 -> V_2 . V_243 ) ;
V_477 -> V_2 . V_3 = V_495 -> V_3 ;
V_477 -> V_2 . V_254 = V_537 ;
V_477 -> V_2 . V_256 = V_538 ;
V_477 -> V_479 -> V_417 = V_495 -> V_513 ;
V_477 -> V_479 -> V_416 = ( void * )
V_127 [ V_539 ] . V_135 . V_136 . V_137 [ V_60 ] . V_138 ;
V_477 -> V_479 -> V_512 =
( V_6 * ) V_477 -> V_2 . V_413 ;
V_477 -> V_479 -> V_329 = & V_477 -> V_2 . V_4 ;
V_477 -> V_479 -> V_250 = V_477 -> V_2 . V_250 ;
V_477 -> V_479 -> V_243 = V_477 -> V_2 . V_243 ;
V_477 -> V_479 -> V_477 = V_477 ;
V_477 -> V_479 -> V_158 = V_158 ;
V_477 -> V_479 -> V_117 = V_60 ;
F_201 ( V_477 , V_291 , V_305 ,
& V_127 [ V_519 ] . V_135 . V_136 . V_137 [ V_60 ] ,
& V_127 [ V_520 ] . V_135 . V_136 . V_137 [ V_60 ] ,
& V_127 [ V_521 ] .
V_135 . V_136 . V_137 [ V_60 ] ) ;
if ( V_462 -> V_528 )
( V_462 -> V_528 ) ( V_42 -> V_158 , V_477 -> V_479 ) ;
if ( V_495 -> V_493 == V_540 )
V_477 -> V_480 = V_477 -> V_479 -> V_117 ;
else
V_477 -> V_480 = V_503 -> V_541 ;
V_60 ++ ;
}
V_462 -> V_498 = 0 ;
F_6 ( V_462 , F_188 ) ;
V_503 -> V_432 |= ( 1 << V_462 -> V_36 ) ;
return V_462 ;
V_173:
F_203 ( V_462 ) ;
return NULL ;
}
void
F_212 ( struct V_461 * V_462 )
{
struct V_476 * V_477 ;
struct V_90 * V_91 ;
F_37 (qe, &tx->txq_q) {
V_477 = (struct V_476 * ) V_91 ;
if ( V_462 -> V_529 )
( V_462 -> V_529 ) ( V_462 -> V_42 -> V_158 , V_477 -> V_479 ) ;
}
V_462 -> V_42 -> V_503 . V_432 &= ~ ( 1 << V_462 -> V_36 ) ;
F_203 ( V_462 ) ;
}
void
F_213 ( struct V_461 * V_462 )
{
if ( V_462 -> V_311 != ( V_433 ) F_188 )
return;
V_462 -> V_12 |= V_508 ;
if ( V_462 -> V_12 & V_507 )
F_66 ( V_462 , V_464 ) ;
}
void
F_214 ( struct V_461 * V_462 , enum V_98 type ,
void (* F_82)( void * , struct V_461 * ) )
{
if ( type == V_110 ) {
(* F_82)( V_462 -> V_42 -> V_158 , V_462 ) ;
return;
}
V_462 -> V_154 = F_82 ;
V_462 -> V_155 = V_462 -> V_42 -> V_158 ;
V_462 -> V_12 &= ~ V_508 ;
F_66 ( V_462 , V_466 ) ;
}
void
F_215 ( struct V_461 * V_462 )
{
F_66 ( V_462 , V_487 ) ;
}
static void
V_509 ( void * V_306 , struct V_461 * V_462 )
{
struct V_502 * V_503 = (struct V_502 * ) V_306 ;
F_151 ( & V_503 -> V_542 ) ;
}
static void
F_216 ( void * V_306 )
{
struct V_502 * V_503 = (struct V_502 * ) V_306 ;
if ( V_503 -> V_154 )
V_503 -> V_154 ( & V_503 -> V_42 -> V_220 ) ;
V_503 -> V_154 = NULL ;
}
void
F_217 ( struct V_502 * V_503 , struct V_42 * V_42 ,
struct V_126 * V_127 )
{
int V_60 ;
V_503 -> V_42 = V_42 ;
V_503 -> V_12 = 0 ;
V_503 -> V_462 = (struct V_461 * )
V_127 [ V_543 ] . V_135 . V_136 . V_137 [ 0 ] . V_138 ;
V_503 -> V_477 = (struct V_476 * )
V_127 [ V_544 ] . V_135 . V_136 . V_137 [ 0 ] . V_138 ;
F_72 ( & V_503 -> V_505 ) ;
F_72 ( & V_503 -> V_530 ) ;
F_72 ( & V_503 -> V_506 ) ;
for ( V_60 = 0 ; V_60 < V_42 -> V_323 . V_324 . V_493 ; V_60 ++ ) {
V_503 -> V_462 [ V_60 ] . V_36 = V_60 ;
F_45 ( & V_503 -> V_462 [ V_60 ] . V_91 ) ;
F_42 ( & V_503 -> V_462 [ V_60 ] . V_91 , & V_503 -> V_505 ) ;
F_45 ( & V_503 -> V_477 [ V_60 ] . V_91 ) ;
F_42 ( & V_503 -> V_477 [ V_60 ] . V_91 , & V_503 -> V_506 ) ;
}
V_503 -> V_545 = V_546 ;
V_503 -> V_541 = 0 ;
V_503 -> V_547 = V_141 ;
V_503 -> V_548 = - 1 ;
}
void
F_218 ( struct V_502 * V_503 )
{
struct V_90 * V_91 ;
int V_60 ;
V_60 = 0 ;
F_37 (qe, &tx_mod->tx_free_q)
V_60 ++ ;
V_60 = 0 ;
F_37 (qe, &tx_mod->txq_free_q)
V_60 ++ ;
V_503 -> V_42 = NULL ;
}
void
F_219 ( struct V_502 * V_503 , enum V_504 type )
{
struct V_461 * V_462 ;
struct V_90 * V_91 ;
V_503 -> V_12 |= V_531 ;
if ( type == V_533 )
V_503 -> V_12 |= V_532 ;
F_37 (qe, &tx_mod->tx_active_q) {
V_462 = (struct V_461 * ) V_91 ;
if ( V_462 -> type == type )
F_204 ( V_462 ) ;
}
}
void
F_220 ( struct V_502 * V_503 , enum V_504 type )
{
struct V_461 * V_462 ;
struct V_90 * V_91 ;
V_503 -> V_12 &= ~ V_531 ;
V_503 -> V_12 &= ~ V_532 ;
V_503 -> V_154 = V_549 ;
F_158 ( & V_503 -> V_542 , F_216 , V_503 ) ;
F_37 (qe, &tx_mod->tx_active_q) {
V_462 = (struct V_461 * ) V_91 ;
if ( V_462 -> type == type ) {
F_159 ( & V_503 -> V_542 ) ;
F_205 ( V_462 ) ;
}
}
F_160 ( & V_503 -> V_542 ) ;
}
void
F_221 ( struct V_502 * V_503 )
{
struct V_461 * V_462 ;
struct V_90 * V_91 ;
V_503 -> V_12 &= ~ V_531 ;
V_503 -> V_12 &= ~ V_532 ;
F_37 (qe, &tx_mod->tx_active_q) {
V_462 = (struct V_461 * ) V_91 ;
F_206 ( V_462 ) ;
}
}
void
F_222 ( struct V_461 * V_462 , int V_3 )
{
struct V_476 * V_477 ;
struct V_90 * V_91 ;
F_37 (qe, &tx->txq_q) {
V_477 = (struct V_476 * ) V_91 ;
F_1 ( & V_477 -> V_2 , V_3 ) ;
}
}
