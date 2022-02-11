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
F_50 ( & V_8 -> V_35 -> V_42 -> V_95 , V_26 ) ;
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
F_51 ( struct V_7 * V_8 )
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
F_52 ( struct V_7 * V_8 , enum V_98 V_99 )
{
struct V_90 * V_91 ;
struct V_25 * V_26 ;
int V_100 ;
while ( ! F_48 ( & V_8 -> V_102 ) ) {
F_49 ( & V_8 -> V_102 , & V_91 ) ;
F_45 ( V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
V_100 = F_43 ( V_8 , V_26 , V_99 ) ;
F_50 ( & V_8 -> V_35 -> V_42 -> V_95 , V_26 ) ;
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
F_53 ( struct V_7 * V_8 )
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
if ( F_54 ( V_8 ) )
return 1 ;
if ( F_47 ( V_8 ) )
return 1 ;
if ( F_55 ( V_8 ) )
return 1 ;
if ( F_56 ( V_8 ) )
return 1 ;
if ( F_51 ( V_8 ) )
return 1 ;
if ( F_57 ( V_8 ) )
return 1 ;
if ( F_53 ( V_8 ) )
return 1 ;
return 0 ;
}
static int
F_17 ( struct V_7 * V_8 )
{
if ( F_58 ( V_8 , V_101 ) )
return 1 ;
if ( F_52 ( V_8 , V_101 ) )
return 1 ;
if ( F_59 ( V_8 , V_101 ) )
return 1 ;
if ( F_60 ( V_8 , V_101 ) )
return 1 ;
return 0 ;
}
static void
F_15 ( struct V_7 * V_8 )
{
F_58 ( V_8 , V_110 ) ;
F_52 ( V_8 , V_110 ) ;
F_59 ( V_8 , V_110 ) ;
F_60 ( V_8 , V_110 ) ;
F_61 ( V_8 ) ;
F_62 ( V_8 ) ;
}
static void
F_63 ( struct V_7 * V_8 , int V_74 )
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
F_64 ( struct V_7 * V_8 , struct V_118 * V_119 )
{
F_65 ( V_8 , V_24 ) ;
}
void
F_66 ( struct V_7 * V_8 ,
struct V_118 * V_119 )
{
struct V_120 * V_121 =
(struct V_120 * ) V_119 ;
if ( V_121 -> error ) {
V_8 -> V_122 = 0 ;
}
F_65 ( V_8 , V_24 ) ;
}
void
F_67 ( struct V_7 * V_8 ,
struct V_118 * V_119 )
{
struct V_44 * V_30 =
& V_8 -> V_31 . V_45 ;
struct V_123 * V_121 =
(struct V_123 * ) V_119 ;
F_40 ( V_8 , ( T_1 * ) & V_30 -> V_38 ,
F_68 ( V_121 -> V_47 ) ) ;
F_65 ( V_8 , V_24 ) ;
}
static void
F_69 ( struct V_7 * V_8 ,
struct V_111 * V_35 ,
struct V_124 * V_125 ,
struct V_126 * V_127 )
{
V_8 -> V_35 = V_35 ;
F_70 ( & V_8 -> V_128 ) ;
F_70 ( & V_8 -> V_129 ) ;
V_8 -> V_130 = 0 ;
V_8 -> V_122 = 0 ;
F_70 ( & V_8 -> V_131 ) ;
V_8 -> V_132 = NULL ;
F_70 ( & V_8 -> V_103 ) ;
F_70 ( & V_8 -> V_102 ) ;
F_70 ( & V_8 -> V_104 ) ;
F_70 ( & V_8 -> V_97 ) ;
if ( V_125 -> V_133 )
V_8 -> V_12 |= V_13 ;
V_8 -> V_76 = ( T_1 * )
V_127 [ V_134 ] . V_135 . V_136 . V_137 [ 0 ] . V_138 ;
F_63 ( V_8 , V_125 -> V_139 ) ;
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
F_71 ( struct V_7 * V_8 )
{
struct V_25 * V_26 ;
V_8 -> V_130 = 0 ;
V_8 -> V_122 = 0 ;
while ( ! F_48 ( & V_8 -> V_128 ) ) {
F_49 ( & V_8 -> V_128 , & V_26 ) ;
F_45 ( & V_26 -> V_91 ) ;
F_72 ( & V_8 -> V_35 -> V_42 -> V_144 , V_26 ) ;
}
if ( V_8 -> V_132 ) {
F_45 ( & V_8 -> V_132 -> V_91 ) ;
F_72 ( & V_8 -> V_35 -> V_42 -> V_144 ,
V_8 -> V_132 ) ;
V_8 -> V_132 = NULL ;
}
while ( ! F_48 ( & V_8 -> V_103 ) ) {
F_49 ( & V_8 -> V_103 , & V_26 ) ;
F_45 ( & V_26 -> V_91 ) ;
F_50 ( & V_8 -> V_35 -> V_42 -> V_95 , V_26 ) ;
}
V_8 -> V_145 = 0 ;
V_8 -> V_146 = 0 ;
if ( V_8 -> V_35 -> V_42 -> V_147 == V_8 -> V_35 -> V_36 )
V_8 -> V_35 -> V_42 -> V_147 = V_148 ;
if ( V_8 -> V_35 -> V_42 -> V_149 == V_8 -> V_35 -> V_36 )
V_8 -> V_35 -> V_42 -> V_149 = V_148 ;
V_8 -> V_106 = 0 ;
V_8 -> V_150 = false ;
V_8 -> V_12 = 0 ;
V_8 -> V_35 = NULL ;
}
static void
F_73 ( struct V_111 * V_35 )
{
F_65 ( V_35 , V_151 ) ;
}
static void
F_74 ( struct V_7 * V_8 )
{
V_8 -> V_152 = F_73 ;
V_8 -> V_153 = V_8 -> V_35 ;
F_65 ( V_8 , V_11 ) ;
}
static void
F_75 ( struct V_111 * V_35 )
{
F_65 ( V_35 , V_154 ) ;
}
static void
F_76 ( struct V_7 * V_8 )
{
V_8 -> V_155 = F_75 ;
V_8 -> V_156 = V_8 -> V_35 ;
F_65 ( V_8 , V_16 ) ;
}
static void
F_77 ( struct V_7 * V_8 )
{
F_65 ( V_8 , V_17 ) ;
}
enum V_157
F_78 ( struct V_111 * V_35 , T_1 * V_158 ,
void (* F_79)( struct V_159 * , struct V_111 * ) )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
if ( V_8 -> V_132 == NULL ) {
V_8 -> V_132 =
F_80 ( & V_8 -> V_35 -> V_42 -> V_144 ) ;
if ( V_8 -> V_132 == NULL )
return V_160 ;
F_45 ( & V_8 -> V_132 -> V_91 ) ;
}
memcpy ( V_8 -> V_132 -> V_39 , V_158 , V_161 ) ;
V_8 -> V_130 = 1 ;
V_8 -> V_162 = F_79 ;
V_8 -> V_163 = V_35 -> V_42 -> V_159 ;
F_65 ( V_8 , V_18 ) ;
return V_164 ;
}
enum V_157
F_81 ( struct V_111 * V_35 , T_1 * V_39 ,
void (* F_79)( struct V_159 * , struct V_111 * ) )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
struct V_25 * V_26 ;
if ( F_82 ( & V_8 -> V_104 , V_39 ) ||
F_82 ( & V_8 -> V_103 , V_39 ) ) {
if ( F_79 )
F_79 ( V_35 -> V_42 -> V_159 , V_35 ) ;
return V_164 ;
}
V_26 = F_83 ( & V_8 -> V_35 -> V_42 -> V_95 ) ;
if ( V_26 == NULL )
return V_165 ;
F_45 ( & V_26 -> V_91 ) ;
memcpy ( V_26 -> V_39 , V_39 , V_161 ) ;
F_42 ( & V_26 -> V_91 , & V_8 -> V_103 ) ;
V_8 -> V_162 = F_79 ;
V_8 -> V_163 = V_35 -> V_42 -> V_159 ;
F_65 ( V_8 , V_18 ) ;
return V_164 ;
}
enum V_157
F_84 ( struct V_111 * V_35 , int V_166 , T_1 * V_167 ,
void (* F_79)( struct V_159 * , struct V_111 * ) )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
struct V_90 V_90 ;
struct V_90 * V_91 ;
T_1 * V_168 ;
struct V_25 * V_26 ;
int V_60 ;
F_70 ( & V_90 ) ;
for ( V_60 = 0 , V_168 = V_167 ; V_60 < V_166 ; V_60 ++ ) {
V_26 = F_83 ( & V_8 -> V_35 -> V_42 -> V_95 ) ;
if ( V_26 == NULL )
goto V_169;
F_45 ( & V_26 -> V_91 ) ;
memcpy ( V_26 -> V_39 , V_168 , V_161 ) ;
F_42 ( & V_26 -> V_91 , & V_90 ) ;
V_168 += V_161 ;
}
while ( ! F_48 ( & V_8 -> V_103 ) ) {
F_49 ( & V_8 -> V_103 , & V_91 ) ;
F_45 ( V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_50 ( & V_8 -> V_35 -> V_42 -> V_95 , V_26 ) ;
}
while ( ! F_48 ( & V_8 -> V_104 ) ) {
F_49 ( & V_8 -> V_104 , & V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_45 ( & V_26 -> V_91 ) ;
F_42 ( & V_26 -> V_91 , & V_8 -> V_102 ) ;
}
while ( ! F_48 ( & V_90 ) ) {
F_49 ( & V_90 , & V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_45 ( & V_26 -> V_91 ) ;
F_42 ( & V_26 -> V_91 , & V_8 -> V_103 ) ;
}
V_8 -> V_162 = F_79 ;
V_8 -> V_163 = V_35 -> V_42 -> V_159 ;
F_65 ( V_8 , V_18 ) ;
return V_164 ;
V_169:
while ( ! F_48 ( & V_90 ) ) {
F_49 ( & V_90 , & V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_45 ( & V_26 -> V_91 ) ;
F_50 ( & V_8 -> V_35 -> V_42 -> V_95 , V_26 ) ;
}
return V_165 ;
}
void
F_85 ( struct V_111 * V_35 , int V_170 )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
int V_171 = ( V_170 >> V_172 ) ;
int V_173 = ( 1 << ( V_170 & V_174 ) ) ;
int V_175 = ( V_170 >> V_176 ) ;
V_8 -> V_67 [ V_171 ] |= V_173 ;
if ( V_8 -> V_64 == V_65 ) {
V_8 -> V_105 |= ( 1 << V_175 ) ;
F_65 ( V_8 , V_18 ) ;
}
}
void
F_86 ( struct V_111 * V_35 , int V_170 )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
int V_171 = ( V_170 >> V_172 ) ;
int V_173 = ( 1 << ( V_170 & V_174 ) ) ;
int V_175 = ( V_170 >> V_176 ) ;
V_8 -> V_67 [ V_171 ] &= ~ V_173 ;
if ( V_8 -> V_64 == V_65 ) {
V_8 -> V_105 |= ( 1 << V_175 ) ;
F_65 ( V_8 , V_18 ) ;
}
}
static int
F_54 ( struct V_7 * V_8 )
{
struct V_25 * V_26 = NULL ;
struct V_90 * V_91 ;
if ( ! F_48 ( & V_8 -> V_129 ) ) {
F_49 ( & V_8 -> V_129 , & V_91 ) ;
F_45 ( V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_20 ( V_8 , V_26 , V_177 ) ;
F_72 ( & V_8 -> V_35 -> V_42 -> V_144 , V_26 ) ;
return 1 ;
}
if ( V_8 -> V_130 ) {
V_8 -> V_130 = 0 ;
memcpy ( V_8 -> V_178 . V_39 ,
V_8 -> V_132 -> V_39 , V_161 ) ;
V_8 -> V_122 = 1 ;
F_20 ( V_8 , & V_8 -> V_178 ,
V_179 ) ;
return 1 ;
}
if ( ! F_48 ( & V_8 -> V_128 ) ) {
F_49 ( & V_8 -> V_128 , & V_91 ) ;
F_45 ( V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_42 ( & V_26 -> V_91 , & V_8 -> V_131 ) ;
F_20 ( V_8 , V_26 , V_180 ) ;
return 1 ;
}
return 0 ;
}
static int
F_58 ( struct V_7 * V_8 , enum V_98 V_99 )
{
struct V_90 * V_91 ;
struct V_25 * V_26 ;
while ( ! F_48 ( & V_8 -> V_129 ) ) {
F_49 ( & V_8 -> V_129 , & V_91 ) ;
F_45 ( V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
if ( V_99 == V_110 )
F_72 ( & V_8 -> V_35 -> V_42 -> V_144 , V_26 ) ;
else {
F_20 ( V_8 , V_26 ,
V_177 ) ;
F_72 ( & V_8 -> V_35 -> V_42 -> V_144 , V_26 ) ;
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
V_177 ) ;
return 1 ;
}
}
if ( V_8 -> V_122 ) {
V_8 -> V_130 = 1 ;
V_8 -> V_122 = 0 ;
if ( V_99 == V_101 ) {
F_20 ( V_8 , & V_8 -> V_178 ,
V_181 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_55 ( struct V_7 * V_8 )
{
struct V_42 * V_42 = V_8 -> V_35 -> V_42 ;
if ( F_87 ( V_8 -> V_145 ,
V_8 -> V_146 ) ) {
F_88 ( V_8 -> V_145 ,
V_8 -> V_146 ) ;
V_8 -> V_182 |= V_183 ;
F_29 ( V_8 , V_65 ) ;
return 1 ;
} else if ( F_89 ( V_8 -> V_145 ,
V_8 -> V_146 ) ) {
F_88 ( V_8 -> V_145 ,
V_8 -> V_146 ) ;
V_8 -> V_182 &= ~ V_183 ;
V_42 -> V_147 = V_148 ;
F_29 ( V_8 , V_141 ) ;
return 1 ;
}
return 0 ;
}
static int
F_59 ( struct V_7 * V_8 , enum V_98 V_99 )
{
struct V_42 * V_42 = V_8 -> V_35 -> V_42 ;
if ( F_89 ( V_8 -> V_145 ,
V_8 -> V_146 ) ) {
F_88 ( V_8 -> V_145 ,
V_8 -> V_146 ) ;
V_8 -> V_182 &= ~ V_183 ;
V_42 -> V_147 = V_148 ;
if ( V_99 == V_101 ) {
F_29 ( V_8 , V_141 ) ;
return 1 ;
}
}
if ( V_8 -> V_182 & V_183 ) {
F_90 ( V_8 -> V_145 ,
V_8 -> V_146 ) ;
V_8 -> V_182 &= ~ V_183 ;
if ( V_99 == V_101 ) {
F_29 ( V_8 , V_141 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_56 ( struct V_7 * V_8 )
{
if ( F_91 ( V_8 -> V_145 ,
V_8 -> V_146 ) ) {
F_92 ( V_8 -> V_145 ,
V_8 -> V_146 ) ;
V_8 -> V_182 |= V_184 ;
F_28 ( V_8 , V_141 ) ;
return 1 ;
} else if ( F_93 ( V_8 -> V_145 ,
V_8 -> V_146 ) ) {
F_92 ( V_8 -> V_145 ,
V_8 -> V_146 ) ;
V_8 -> V_182 &= ~ V_184 ;
F_28 ( V_8 , V_65 ) ;
return 1 ;
}
return 0 ;
}
static int
F_60 ( struct V_7 * V_8 , enum V_98 V_99 )
{
if ( F_93 ( V_8 -> V_145 ,
V_8 -> V_146 ) ) {
F_92 ( V_8 -> V_145 ,
V_8 -> V_146 ) ;
V_8 -> V_182 &= ~ V_184 ;
if ( V_99 == V_101 ) {
F_28 ( V_8 , V_65 ) ;
return 1 ;
}
}
if ( V_8 -> V_182 & V_184 ) {
F_94 ( V_8 -> V_145 ,
V_8 -> V_146 ) ;
V_8 -> V_182 &= ~ V_184 ;
if ( V_99 == V_101 ) {
F_28 ( V_8 , V_65 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_95 ( struct V_7 * V_8 )
{
struct V_42 * V_42 = V_8 -> V_35 -> V_42 ;
int V_100 = 0 ;
if ( F_87 ( V_8 -> V_145 ,
V_8 -> V_146 ) ||
( V_8 -> V_182 & V_183 ) ) {
} else if ( F_89 ( V_8 -> V_145 ,
V_8 -> V_146 ) ) {
F_88 ( V_8 -> V_145 ,
V_8 -> V_146 ) ;
} else {
F_90 ( V_8 -> V_145 ,
V_8 -> V_146 ) ;
V_42 -> V_147 = V_8 -> V_35 -> V_36 ;
V_100 = 1 ;
}
return V_100 ;
}
static int
F_96 ( struct V_7 * V_8 )
{
struct V_42 * V_42 = V_8 -> V_35 -> V_42 ;
int V_100 = 0 ;
if ( F_89 ( V_8 -> V_145 ,
V_8 -> V_146 ) ||
( ! ( V_8 -> V_182 & V_183 ) ) ) {
} else if ( F_87 ( V_8 -> V_145 ,
V_8 -> V_146 ) ) {
F_88 ( V_8 -> V_145 ,
V_8 -> V_146 ) ;
V_42 -> V_147 = V_148 ;
} else if ( V_8 -> V_182 & V_183 ) {
F_97 ( V_8 -> V_145 ,
V_8 -> V_146 ) ;
V_100 = 1 ;
}
return V_100 ;
}
static int
F_98 ( struct V_7 * V_8 )
{
int V_100 = 0 ;
if ( F_91 ( V_8 -> V_145 ,
V_8 -> V_146 ) ||
( V_8 -> V_182 & V_184 ) ) {
} else if ( F_93 ( V_8 -> V_145 ,
V_8 -> V_146 ) ) {
F_92 ( V_8 -> V_145 ,
V_8 -> V_146 ) ;
} else {
F_94 ( V_8 -> V_145 ,
V_8 -> V_146 ) ;
V_100 = 1 ;
}
return V_100 ;
}
static int
F_99 ( struct V_7 * V_8 )
{
int V_100 = 0 ;
if ( F_93 ( V_8 -> V_145 ,
V_8 -> V_146 ) ||
( ! ( V_8 -> V_182 & V_184 ) ) ) {
} else if ( F_91 ( V_8 -> V_145 ,
V_8 -> V_146 ) ) {
F_92 ( V_8 -> V_145 ,
V_8 -> V_146 ) ;
} else if ( V_8 -> V_182 & V_184 ) {
F_100 ( V_8 -> V_145 ,
V_8 -> V_146 ) ;
V_100 = 1 ;
}
return V_100 ;
}
static int
F_57 ( struct V_7 * V_8 )
{
if ( V_8 -> V_150 ) {
V_8 -> V_150 = false ;
F_32 ( V_8 ) ;
return 1 ;
}
return 0 ;
}
static void F_101 ( struct V_111 * V_35 )
{
F_102 ( V_35 ) ;
}
static void F_103 ( struct V_111 * V_35 ,
enum V_185 V_10 )
{
switch ( V_10 ) {
case V_186 :
F_6 ( V_35 , V_187 ) ;
break;
case V_188 :
F_102 ( V_35 ) ;
break;
case V_189 :
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void F_104 ( struct V_111 * V_35 )
{
F_105 ( V_35 ) ;
}
static void
F_106 ( struct V_111 * V_35 )
{
}
static void
F_107 ( struct V_111 * V_35 , enum V_185 V_10 )
{
switch ( V_10 ) {
case V_189 :
case V_190 :
F_6 ( V_35 , V_191 ) ;
V_35 -> V_192 ( V_35 -> V_42 -> V_159 , V_35 ) ;
break;
case V_193 :
F_108 ( V_35 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void V_187 ( struct V_111 * V_35 ,
enum V_185 V_10 )
{
switch ( V_10 ) {
case V_188 :
F_6 ( V_35 , V_194 ) ;
break;
case V_189 :
F_6 ( V_35 , F_103 ) ;
break;
case V_193 :
F_6 ( V_35 , V_195 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void F_109 ( struct V_111 * V_35 )
{
V_35 -> V_196 ( V_35 -> V_42 -> V_159 , V_35 ) ;
F_74 ( & V_35 -> V_8 ) ;
}
static void
F_110 ( struct V_111 * V_35 )
{
}
static void
F_111 ( struct V_111 * V_35 , enum V_185 V_10 )
{
switch ( V_10 ) {
case V_189 :
F_6 ( V_35 , V_191 ) ;
F_77 ( & V_35 -> V_8 ) ;
F_112 ( V_35 ) ;
V_35 -> V_192 ( V_35 -> V_42 -> V_159 , V_35 ) ;
break;
case V_151 :
F_76 ( & V_35 -> V_8 ) ;
break;
case V_154 :
F_6 ( V_35 , F_107 ) ;
F_112 ( V_35 ) ;
F_108 ( V_35 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void
F_113 ( struct V_111 * V_35 )
{
}
static void
V_194 ( struct V_111 * V_35 , enum V_185 V_10 )
{
switch ( V_10 ) {
case V_189 :
case V_190 :
F_6 ( V_35 , F_103 ) ;
break;
case V_193 :
F_108 ( V_35 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_114 ( struct V_111 * V_35 )
{
struct V_112 * V_113 ;
struct V_90 * V_197 ;
int V_198 = ( V_35 -> type == V_199 ) ;
F_37 (qe_rxp, &rx->rxp_q) {
V_113 = (struct V_112 * ) V_197 ;
F_115 ( V_35 -> V_42 , & V_113 -> V_115 . V_2 , V_198 ) ;
}
F_116 ( & V_35 -> V_42 -> V_200 ) ;
}
static void
F_117 ( struct V_111 * V_35 , enum V_185 V_10 )
{
switch ( V_10 ) {
case V_188 :
F_6 ( V_35 , F_111 ) ;
F_118 ( & V_35 -> V_42 -> V_200 ) ;
F_76 ( & V_35 -> V_8 ) ;
break;
case V_189 :
F_6 ( V_35 , V_201 ) ;
F_118 ( & V_35 -> V_42 -> V_200 ) ;
F_77 ( & V_35 -> V_8 ) ;
F_112 ( V_35 ) ;
V_35 -> V_192 ( V_35 -> V_42 -> V_159 , V_35 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void V_195 ( struct V_111 * V_35 ,
enum V_185 V_10 )
{
switch ( V_10 ) {
case V_188 :
F_6 ( V_35 , F_111 ) ;
break;
case V_189 :
F_6 ( V_35 , V_201 ) ;
F_77 ( & V_35 -> V_8 ) ;
F_112 ( V_35 ) ;
V_35 -> V_192 ( V_35 -> V_42 -> V_159 , V_35 ) ;
break;
case V_151 :
F_6 ( V_35 , F_117 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void
F_119 ( struct V_111 * V_35 )
{
}
static void
V_191 ( struct V_111 * V_35 , enum V_185 V_10 )
{
switch ( V_10 ) {
case V_189 :
case V_154 :
break;
case V_202 :
F_6 ( V_35 , F_103 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void
F_120 ( struct V_111 * V_35 )
{
}
static void
V_201 ( struct V_111 * V_35 , enum V_185 V_10 )
{
switch ( V_10 ) {
case V_186 :
F_6 ( V_35 , V_203 ) ;
break;
case V_188 :
F_6 ( V_35 , V_191 ) ;
break;
case V_189 :
case V_151 :
case V_154 :
break;
case V_202 :
F_6 ( V_35 , F_103 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
} }
static void
F_121 ( struct V_111 * V_35 )
{
}
static void
V_203 ( struct V_111 * V_35 , enum V_185 V_10 )
{
switch ( V_10 ) {
case V_188 :
F_6 ( V_35 , V_191 ) ;
break;
case V_189 :
F_6 ( V_35 , V_201 ) ;
break;
case V_202 :
F_6 ( V_35 , V_187 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void
F_105 ( struct V_111 * V_35 )
{
struct V_204 * V_205 = & V_35 -> V_31 . V_205 ;
struct V_112 * V_113 = NULL ;
struct V_206 * V_207 = NULL , * V_208 = NULL ;
struct V_90 * V_209 ;
int V_60 ;
F_21 ( V_205 -> V_33 , V_34 ,
V_210 , 0 , V_35 -> V_36 ) ;
V_205 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_204 ) ) ) ;
V_205 -> V_211 = V_35 -> V_139 ;
for ( V_60 = 0 , V_209 = F_122 ( & V_35 -> V_212 ) ;
V_60 < V_35 -> V_139 ;
V_60 ++ , V_209 = F_123 ( V_209 ) ) {
V_113 = (struct V_112 * ) V_209 ;
F_124 ( V_113 , V_207 , V_208 ) ;
switch ( V_113 -> type ) {
case V_213 :
case V_214 :
F_125 ( & V_205 -> V_215 [ V_60 ] . V_216 . V_217 ,
& V_208 -> V_218 ) ;
V_205 -> V_215 [ V_60 ] . V_216 . V_219 =
F_22 ( ( T_2 ) V_208 -> V_220 ) ;
case V_221 :
F_125 ( & V_205 -> V_215 [ V_60 ] . V_222 . V_217 ,
& V_207 -> V_218 ) ;
V_207 -> V_220 =
F_126 ( & V_35 -> V_42 -> V_223 ) ;
V_205 -> V_215 [ V_60 ] . V_222 . V_219 =
F_22 ( ( T_2 ) V_207 -> V_220 ) ;
break;
default:
F_127 ( 1 ) ;
}
F_125 ( & V_205 -> V_215 [ V_60 ] . V_115 . V_217 ,
& V_113 -> V_115 . V_218 ) ;
V_205 -> V_215 [ V_60 ] . V_2 . V_224 . V_225 . V_226 =
V_113 -> V_115 . V_2 . V_227 . V_228 ;
V_205 -> V_215 [ V_60 ] . V_2 . V_224 . V_225 . V_229 =
V_113 -> V_115 . V_2 . V_227 . V_230 ;
V_205 -> V_215 [ V_60 ] . V_2 . V_231 . V_232 =
F_22 ( ( T_2 ) V_113 -> V_115 . V_2 . V_233 ) ;
}
V_205 -> V_234 . V_235 = V_141 ;
V_205 -> V_234 . V_236 = V_65 ;
V_205 -> V_234 . V_237 = V_141 ;
V_205 -> V_234 . V_238 = V_141 ;
V_205 -> V_234 . V_239 = ( V_113 -> V_115 . V_2 . V_240 == V_241 )
? V_65 :
V_141 ;
V_205 -> V_234 . V_242 =
F_31 ( ( V_6 ) V_113 -> V_115 . V_2 . V_3 ) ;
V_205 -> V_234 . V_243 =
F_31 ( ( V_6 ) V_113 -> V_115 . V_2 . V_244 ) ;
V_205 -> V_234 . V_245 = ( T_1 ) V_113 -> V_115 . V_2 . V_246 ;
switch ( V_113 -> type ) {
case V_213 :
V_205 -> V_247 . V_248 = V_249 ;
break;
case V_214 :
V_205 -> V_247 . V_248 = V_250 ;
V_205 -> V_247 . V_251 . type = V_35 -> V_252 . V_253 ;
V_205 -> V_247 . V_251 . V_254 = V_35 -> V_252 . V_255 ;
V_205 -> V_247 . V_251 . V_256 = V_35 -> V_252 . V_255 ;
break;
case V_221 :
V_205 -> V_247 . V_248 = V_257 ;
break;
default:
F_127 ( 1 ) ;
}
V_205 -> V_247 . V_258 = V_35 -> V_8 . V_69 ;
F_24 ( & V_35 -> V_41 , NULL , NULL ,
sizeof( struct V_204 ) , & V_205 -> V_33 ) ;
F_25 ( & V_35 -> V_42 -> V_43 , & V_35 -> V_41 ) ;
}
static void
F_128 ( struct V_111 * V_35 )
{
struct V_259 * V_30 = & V_35 -> V_31 . V_30 ;
F_21 ( V_30 -> V_33 , V_34 ,
V_260 , 0 , V_35 -> V_36 ) ;
V_30 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_259 ) ) ) ;
F_24 ( & V_35 -> V_41 , NULL , NULL , sizeof( struct V_259 ) ,
& V_30 -> V_33 ) ;
F_25 ( & V_35 -> V_42 -> V_43 , & V_35 -> V_41 ) ;
}
static void
F_108 ( struct V_111 * V_35 )
{
struct V_112 * V_113 ;
struct V_90 * V_197 ;
F_37 (qe_rxp, &rx->rxp_q) {
V_113 = (struct V_112 * ) V_197 ;
F_129 ( V_35 -> V_42 , & V_113 -> V_115 . V_2 ) ;
}
F_128 ( V_35 ) ;
}
static int
F_130 ( struct V_261 * V_262 , struct V_124 * V_247 )
{
if ( ( V_262 -> V_263 == 0 ) ||
( V_262 -> V_264 == 0 ) ||
( V_262 -> V_265 == 0 ) )
return 0 ;
if ( V_247 -> V_266 == V_221 ) {
if ( ( V_262 -> V_264 < V_247 -> V_139 ) ||
( V_262 -> V_265 < V_247 -> V_139 ) )
return 0 ;
} else {
if ( ( V_262 -> V_264 < V_247 -> V_139 ) ||
( V_262 -> V_265 < ( 2 * V_247 -> V_139 ) ) )
return 0 ;
}
return 1 ;
}
static struct V_206 *
F_131 ( struct V_261 * V_262 )
{
struct V_206 * V_267 = NULL ;
struct V_90 * V_91 = NULL ;
F_49 ( & V_262 -> V_268 , & V_91 ) ;
V_262 -> V_265 -- ;
V_267 = (struct V_206 * ) V_91 ;
F_45 ( & V_267 -> V_91 ) ;
return V_267 ;
}
static void
F_132 ( struct V_261 * V_262 , struct V_206 * V_267 )
{
F_45 ( & V_267 -> V_91 ) ;
F_42 ( & V_267 -> V_91 , & V_262 -> V_268 ) ;
V_262 -> V_265 ++ ;
}
static struct V_112 *
F_133 ( struct V_261 * V_262 )
{
struct V_90 * V_91 = NULL ;
struct V_112 * V_113 = NULL ;
F_49 ( & V_262 -> V_269 , & V_91 ) ;
V_262 -> V_264 -- ;
V_113 = (struct V_112 * ) V_91 ;
F_45 ( & V_113 -> V_91 ) ;
return V_113 ;
}
static void
F_134 ( struct V_261 * V_262 , struct V_112 * V_113 )
{
F_45 ( & V_113 -> V_91 ) ;
F_42 ( & V_113 -> V_91 , & V_262 -> V_269 ) ;
V_262 -> V_264 ++ ;
}
static struct V_111 *
F_135 ( struct V_261 * V_262 , enum V_270 type )
{
struct V_90 * V_91 = NULL ;
struct V_111 * V_35 = NULL ;
if ( type == V_199 ) {
F_49 ( & V_262 -> V_271 , & V_91 ) ;
} else
F_136 ( & V_262 -> V_271 , & V_91 ) ;
V_262 -> V_263 -- ;
V_35 = (struct V_111 * ) V_91 ;
F_45 ( & V_35 -> V_91 ) ;
F_42 ( & V_35 -> V_91 , & V_262 -> V_272 ) ;
V_35 -> type = type ;
return V_35 ;
}
static void
F_137 ( struct V_261 * V_262 , struct V_111 * V_35 )
{
struct V_90 * V_273 = NULL ;
struct V_90 * V_91 ;
F_45 ( & V_35 -> V_91 ) ;
F_37 (qe, &rx_mod->rx_free_q) {
if ( ( (struct V_111 * ) V_91 ) -> V_36 < V_35 -> V_36 )
V_273 = V_91 ;
else
break;
}
if ( V_273 == NULL ) {
F_138 ( & V_262 -> V_271 , & V_35 -> V_91 ) ;
} else if ( F_123 ( V_273 ) == & V_262 -> V_271 ) {
F_42 ( & V_35 -> V_91 , & V_262 -> V_271 ) ;
} else {
F_123 ( & V_35 -> V_91 ) = F_123 ( V_273 ) ;
F_139 ( & V_35 -> V_91 ) = V_273 ;
F_123 ( V_273 ) = & V_35 -> V_91 ;
F_139 ( F_123 ( & V_35 -> V_91 ) ) = & V_35 -> V_91 ;
}
V_262 -> V_263 ++ ;
}
static void
F_140 ( struct V_112 * V_113 , struct V_206 * V_207 ,
struct V_206 * V_208 )
{
switch ( V_113 -> type ) {
case V_221 :
V_113 -> V_267 . V_274 . V_275 = V_207 ;
V_113 -> V_267 . V_274 . V_276 = NULL ;
break;
case V_213 :
V_113 -> V_267 . V_277 . V_278 = V_207 ;
V_113 -> V_267 . V_277 . V_279 = V_208 ;
break;
case V_214 :
V_113 -> V_267 . V_251 . V_280 = V_207 ;
V_113 -> V_267 . V_251 . V_281 = V_208 ;
break;
default:
break;
}
}
static void
F_141 ( struct V_206 * V_267 ,
struct V_112 * V_113 ,
V_6 V_282 ,
V_6 V_283 ,
struct V_284 * V_285 ,
struct V_284 * V_286 ,
struct V_284 * V_287 )
{
T_1 * V_138 ;
T_3 V_288 ;
struct V_289 V_290 ;
int V_60 ;
V_267 -> V_218 . V_291 . V_228 = V_285 -> V_288 . V_228 ;
V_267 -> V_218 . V_291 . V_230 = V_285 -> V_288 . V_230 ;
V_267 -> V_218 . V_292 = V_285 -> V_138 ;
V_267 -> V_218 . V_282 = V_282 ;
V_267 -> V_218 . V_283 = V_283 ;
V_267 -> V_293 -> V_294 = ( void * * ) V_286 -> V_138 ;
V_267 -> V_293 -> V_295 = V_287 -> V_138 ;
V_138 = V_287 -> V_138 ;
F_142 ( & V_287 -> V_288 , V_288 ) ;
for ( V_60 = 0 ; V_60 < V_267 -> V_218 . V_282 ; V_60 ++ ) {
V_267 -> V_293 -> V_294 [ V_60 ] = V_138 ;
V_138 += V_296 ;
F_143 ( V_288 , & V_290 ) ;
( (struct V_289 * ) V_267 -> V_218 . V_292 ) [ V_60 ] . V_228 =
V_290 . V_228 ;
( (struct V_289 * ) V_267 -> V_218 . V_292 ) [ V_60 ] . V_230 =
V_290 . V_230 ;
V_288 += V_296 ;
}
}
static void
F_144 ( struct V_112 * V_113 ,
V_6 V_282 ,
V_6 V_283 ,
struct V_284 * V_285 ,
struct V_284 * V_286 ,
struct V_284 * V_287 )
{
T_1 * V_138 ;
T_3 V_288 ;
struct V_289 V_290 ;
int V_60 ;
V_113 -> V_115 . V_218 . V_291 . V_228 = V_285 -> V_288 . V_228 ;
V_113 -> V_115 . V_218 . V_291 . V_230 = V_285 -> V_288 . V_230 ;
V_113 -> V_115 . V_218 . V_292 = V_285 -> V_138 ;
V_113 -> V_115 . V_218 . V_282 = V_282 ;
V_113 -> V_115 . V_218 . V_283 = V_283 ;
V_113 -> V_115 . V_116 -> V_294 = ( void * * ) V_286 -> V_138 ;
V_113 -> V_115 . V_116 -> V_295 = V_287 -> V_138 ;
V_138 = V_287 -> V_138 ;
F_142 ( & V_287 -> V_288 , V_288 ) ;
for ( V_60 = 0 ; V_60 < V_113 -> V_115 . V_218 . V_282 ; V_60 ++ ) {
V_113 -> V_115 . V_116 -> V_294 [ V_60 ] = V_138 ;
V_138 += V_296 ;
F_143 ( V_288 , & V_290 ) ;
( (struct V_289 * ) V_113 -> V_115 . V_218 . V_292 ) [ V_60 ] . V_228 =
V_290 . V_228 ;
( (struct V_289 * ) V_113 -> V_115 . V_218 . V_292 ) [ V_60 ] . V_230 =
V_290 . V_230 ;
V_288 += V_296 ;
}
}
static void
F_145 ( void * V_297 , struct V_111 * V_35 )
{
struct V_261 * V_262 = (struct V_261 * ) V_297 ;
F_146 ( & V_262 -> V_298 ) ;
}
static void
F_147 ( void * V_297 )
{
struct V_261 * V_262 = (struct V_261 * ) V_297 ;
if ( V_262 -> V_155 )
V_262 -> V_155 ( & V_262 -> V_42 -> V_223 ) ;
V_262 -> V_155 = NULL ;
}
static void
F_148 ( struct V_111 * V_35 )
{
V_35 -> V_299 |= V_300 ;
if ( V_35 -> V_299 & V_301 )
F_65 ( V_35 , V_186 ) ;
}
static void
F_149 ( struct V_111 * V_35 )
{
V_35 -> V_299 &= ~ V_300 ;
if ( V_35 -> V_302 == ( V_303 ) F_103 )
F_145 ( & V_35 -> V_42 -> V_262 , V_35 ) ;
else {
V_35 -> V_155 = F_145 ;
V_35 -> V_156 = & V_35 -> V_42 -> V_262 ;
F_65 ( V_35 , V_188 ) ;
}
}
static void
F_150 ( struct V_111 * V_35 )
{
V_35 -> V_299 &= ~ V_300 ;
F_65 ( V_35 , V_189 ) ;
}
void
F_151 ( struct V_261 * V_262 , enum V_270 type )
{
struct V_111 * V_35 ;
struct V_90 * V_91 ;
V_262 -> V_12 |= V_304 ;
if ( type == V_305 )
V_262 -> V_12 |= V_306 ;
F_37 (qe, &rx_mod->rx_active_q) {
V_35 = (struct V_111 * ) V_91 ;
if ( V_35 -> type == type )
F_148 ( V_35 ) ;
}
}
void
F_152 ( struct V_261 * V_262 , enum V_270 type )
{
struct V_111 * V_35 ;
struct V_90 * V_91 ;
V_262 -> V_12 &= ~ V_304 ;
V_262 -> V_12 &= ~ V_306 ;
V_262 -> V_155 = V_307 ;
F_153 ( & V_262 -> V_298 , F_147 , V_262 ) ;
F_37 (qe, &rx_mod->rx_active_q) {
V_35 = (struct V_111 * ) V_91 ;
if ( V_35 -> type == type ) {
F_154 ( & V_262 -> V_298 ) ;
F_149 ( V_35 ) ;
}
}
F_155 ( & V_262 -> V_298 ) ;
}
void
F_156 ( struct V_261 * V_262 )
{
struct V_111 * V_35 ;
struct V_90 * V_91 ;
V_262 -> V_12 &= ~ V_304 ;
V_262 -> V_12 &= ~ V_306 ;
F_37 (qe, &rx_mod->rx_active_q) {
V_35 = (struct V_111 * ) V_91 ;
F_150 ( V_35 ) ;
}
}
void F_157 ( struct V_261 * V_262 , struct V_42 * V_42 ,
struct V_126 * V_127 )
{
int V_171 ;
struct V_111 * V_308 ;
struct V_112 * V_309 ;
struct V_206 * V_310 ;
V_262 -> V_42 = V_42 ;
V_262 -> V_12 = 0 ;
V_262 -> V_35 = (struct V_111 * )
V_127 [ V_311 ] . V_135 . V_136 . V_137 [ 0 ] . V_138 ;
V_262 -> V_113 = (struct V_112 * )
V_127 [ V_312 ] . V_135 . V_136 . V_137 [ 0 ] . V_138 ;
V_262 -> V_267 = (struct V_206 * )
V_127 [ V_313 ] . V_135 . V_136 . V_137 [ 0 ] . V_138 ;
F_70 ( & V_262 -> V_271 ) ;
V_262 -> V_263 = 0 ;
F_70 ( & V_262 -> V_268 ) ;
V_262 -> V_265 = 0 ;
F_70 ( & V_262 -> V_269 ) ;
V_262 -> V_264 = 0 ;
F_70 ( & V_262 -> V_272 ) ;
for ( V_171 = 0 ; V_171 < V_42 -> V_314 . V_315 . V_316 ; V_171 ++ ) {
V_308 = & V_262 -> V_35 [ V_171 ] ;
F_45 ( & V_308 -> V_91 ) ;
F_70 ( & V_308 -> V_212 ) ;
V_308 -> V_42 = NULL ;
V_308 -> V_36 = V_171 ;
V_308 -> V_155 = NULL ;
V_308 -> V_156 = NULL ;
F_42 ( & V_308 -> V_91 , & V_262 -> V_271 ) ;
V_262 -> V_263 ++ ;
}
for ( V_171 = 0 ; V_171 < V_42 -> V_314 . V_315 . V_316 ; V_171 ++ ) {
V_309 = & V_262 -> V_113 [ V_171 ] ;
F_45 ( & V_309 -> V_91 ) ;
F_42 ( & V_309 -> V_91 , & V_262 -> V_269 ) ;
V_262 -> V_264 ++ ;
}
for ( V_171 = 0 ; V_171 < ( V_42 -> V_314 . V_315 . V_316 * 2 ) ; V_171 ++ ) {
V_310 = & V_262 -> V_267 [ V_171 ] ;
F_45 ( & V_310 -> V_91 ) ;
F_42 ( & V_310 -> V_91 , & V_262 -> V_268 ) ;
V_262 -> V_265 ++ ;
}
}
void
F_158 ( struct V_261 * V_262 )
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
V_262 -> V_42 = NULL ;
}
void
F_159 ( struct V_111 * V_35 , struct V_118 * V_119 )
{
struct V_317 * V_318 = & V_35 -> V_31 . V_318 ;
struct V_112 * V_113 = NULL ;
struct V_206 * V_207 = NULL , * V_208 = NULL ;
struct V_90 * V_209 ;
int V_60 ;
F_160 ( & V_35 -> V_42 -> V_43 , ( T_1 * ) V_318 ,
sizeof( struct V_317 ) ) ;
V_35 -> V_319 = V_318 -> V_319 ;
for ( V_60 = 0 , V_209 = F_122 ( & V_35 -> V_212 ) ;
V_60 < V_35 -> V_139 ;
V_60 ++ , V_209 = F_123 ( V_209 ) ) {
V_113 = (struct V_112 * ) V_209 ;
F_124 ( V_113 , V_207 , V_208 ) ;
V_113 -> V_115 . V_116 -> V_320 -> V_321 =
V_35 -> V_42 -> V_322 . V_323
+ F_161 ( V_318 -> V_324 [ V_60 ] . V_320 ) ;
V_113 -> V_319 = V_318 -> V_324 [ V_60 ] . V_325 ;
V_207 -> V_293 -> V_326 =
V_35 -> V_42 -> V_322 . V_323
+ F_161 ( V_318 -> V_324 [ V_60 ] . V_327 ) ;
V_207 -> V_319 = V_318 -> V_324 [ V_60 ] . V_328 ;
if ( V_208 ) {
V_208 -> V_293 -> V_326 =
V_35 -> V_42 -> V_322 . V_323
+ F_161 ( V_318 -> V_324 [ V_60 ] . V_329 ) ;
V_208 -> V_319 = V_318 -> V_324 [ V_60 ] . V_330 ;
}
( * V_113 -> V_115 . V_116 -> V_331 ) = 0 ;
V_113 -> V_115 . V_116 -> V_332 = 0 ;
V_207 -> V_293 -> V_332 = V_207 -> V_293 -> V_333 = 0 ;
if ( V_208 )
V_208 -> V_293 -> V_332 = V_208 -> V_293 -> V_333 = 0 ;
}
F_65 ( V_35 , V_193 ) ;
}
void
F_162 ( struct V_111 * V_35 , struct V_118 * V_119 )
{
F_65 ( V_35 , V_190 ) ;
}
void
F_163 ( struct V_124 * V_215 , struct V_126 * V_127 )
{
V_6 V_334 , V_335 , V_336 ;
V_6 V_337 , V_338 , V_339 ;
struct V_340 * V_136 ;
V_6 V_341 ;
V_6 V_342 ;
V_6 V_343 ;
V_343 = V_215 -> V_344 ;
V_342 = ( ( V_215 -> V_266 == V_221 ) ? 0 : V_215 -> V_344 ) ;
V_341 = V_343 + V_342 ;
F_164 ( V_341 ) ;
V_334 = V_341 * V_345 ;
V_334 = F_165 ( V_334 , V_296 ) ;
V_337 = F_166 ( V_334 ) ;
F_164 ( V_343 ) ;
V_336 = V_343 * V_346 ;
V_336 = F_165 ( V_336 , V_296 ) ;
V_339 = F_166 ( V_336 ) ;
if ( V_221 != V_215 -> V_266 ) {
F_164 ( V_342 ) ;
V_335 = V_342 * V_346 ;
V_335 = F_165 ( V_335 , V_296 ) ;
V_338 = F_166 ( V_335 ) ;
} else
V_338 = 0 ;
V_127 [ V_347 ] . V_348 = V_349 ;
V_136 = & V_127 [ V_347 ] . V_135 . V_136 ;
V_136 -> V_350 = V_351 ;
V_136 -> V_352 = sizeof( struct V_353 ) ;
V_136 -> V_354 = V_215 -> V_139 ;
V_127 [ V_355 ] . V_348 = V_349 ;
V_136 = & V_127 [ V_355 ] . V_135 . V_136 ;
V_136 -> V_350 = V_351 ;
V_136 -> V_352 = sizeof( struct V_356 ) ;
V_136 -> V_354 = F_167 ( V_215 ) ;
V_127 [ V_357 ] . V_348 = V_349 ;
V_136 = & V_127 [ V_357 ] . V_135 . V_136 ;
V_136 -> V_350 = V_358 ;
V_136 -> V_352 = V_337 * sizeof( struct V_289 ) ;
V_136 -> V_354 = V_215 -> V_139 ;
V_127 [ V_359 ] . V_348 = V_349 ;
V_136 = & V_127 [ V_359 ] . V_135 . V_136 ;
V_136 -> V_350 = V_351 ;
V_136 -> V_352 = V_337 * sizeof( void * ) ;
V_136 -> V_354 = V_215 -> V_139 ;
V_127 [ V_360 ] . V_348 = V_349 ;
V_136 = & V_127 [ V_360 ] . V_135 . V_136 ;
V_136 -> V_350 = V_358 ;
V_136 -> V_352 = V_296 * V_337 ;
V_136 -> V_354 = V_215 -> V_139 ;
V_127 [ V_361 ] . V_348 = V_349 ;
V_136 = & V_127 [ V_361 ] . V_135 . V_136 ;
V_136 -> V_350 = V_358 ;
V_136 -> V_352 = V_339 * sizeof( struct V_289 ) ;
V_136 -> V_354 = V_215 -> V_139 ;
V_127 [ V_362 ] . V_348 = V_349 ;
V_136 = & V_127 [ V_362 ] . V_135 . V_136 ;
V_136 -> V_350 = V_351 ;
V_136 -> V_352 = V_339 * sizeof( void * ) ;
V_136 -> V_354 = V_215 -> V_139 ;
V_127 [ V_363 ] . V_348 = V_349 ;
V_136 = & V_127 [ V_363 ] . V_135 . V_136 ;
V_136 -> V_350 = V_358 ;
V_136 -> V_352 = V_296 * V_339 ;
V_136 -> V_354 = V_215 -> V_139 ;
V_127 [ V_364 ] . V_348 = V_349 ;
V_136 = & V_127 [ V_364 ] . V_135 . V_136 ;
V_136 -> V_350 = V_358 ;
V_136 -> V_352 = V_338 * sizeof( struct V_289 ) ;
V_136 -> V_354 = ( V_338 ? V_215 -> V_139 : 0 ) ;
V_127 [ V_365 ] . V_348 = V_349 ;
V_136 = & V_127 [ V_365 ] . V_135 . V_136 ;
V_136 -> V_350 = V_351 ;
V_136 -> V_352 = V_338 * sizeof( void * ) ;
V_136 -> V_354 = ( V_338 ? V_215 -> V_139 : 0 ) ;
V_127 [ V_366 ] . V_348 = V_349 ;
V_136 = & V_127 [ V_366 ] . V_135 . V_136 ;
V_136 -> V_350 = V_358 ;
V_136 -> V_352 = V_296 * V_338 ;
V_136 -> V_354 = ( V_338 ? V_215 -> V_139 : 0 ) ;
V_127 [ V_367 ] . V_348 = V_349 ;
V_136 = & V_127 [ V_367 ] . V_135 . V_136 ;
V_136 -> V_350 = V_358 ;
V_136 -> V_352 = V_368 ;
V_136 -> V_354 = V_215 -> V_139 ;
V_127 [ V_134 ] . V_348 = V_349 ;
V_136 = & V_127 [ V_134 ] . V_135 . V_136 ;
V_136 -> V_350 = V_351 ;
V_136 -> V_352 = V_369 ;
V_136 -> V_354 = 1 ;
V_127 [ V_370 ] . V_348 = V_371 ;
V_127 [ V_370 ] . V_135 . V_372 . V_240 = V_241 ;
V_127 [ V_370 ] . V_135 . V_372 . V_354 = V_215 -> V_139 ;
}
struct V_111 *
F_168 ( struct V_42 * V_42 , struct V_159 * V_159 ,
struct V_124 * V_247 ,
const struct V_373 * V_374 ,
struct V_126 * V_127 ,
void * V_375 )
{
struct V_261 * V_262 = & V_42 -> V_262 ;
struct V_111 * V_35 ;
struct V_112 * V_113 ;
struct V_206 * V_207 ;
struct V_206 * V_208 ;
struct V_376 * V_372 ;
V_6 V_282 ;
struct V_284 * V_377 ;
struct V_284 * V_378 ;
struct V_284 * V_379 ;
struct V_284 * V_380 ;
struct V_284 * V_381 ;
struct V_284 * V_382 ;
struct V_284 * V_383 ;
struct V_284 * V_384 ;
struct V_284 * V_385 ;
struct V_284 * V_386 ;
struct V_284 * V_387 ;
struct V_284 * V_388 ;
int V_60 ;
int V_339 , V_338 , V_389 ;
if ( ! F_130 ( V_262 , V_247 ) )
return NULL ;
V_372 = & V_127 [ V_370 ] . V_135 . V_372 ;
V_377 = & V_127 [ V_347 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_378 = & V_127 [ V_355 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_379 = & V_127 [ V_390 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_380 = & V_127 [ V_357 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_381 = & V_127 [ V_359 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_382 = & V_127 [ V_360 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_383 = & V_127 [ V_364 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_384 = & V_127 [ V_361 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_385 = & V_127 [ V_365 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_386 = & V_127 [ V_362 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_387 = & V_127 [ V_366 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_388 = & V_127 [ V_363 ] . V_135 . V_136 . V_137 [ 0 ] ;
V_282 = V_127 [ V_360 ] . V_135 . V_136 . V_352 /
V_296 ;
V_339 = V_127 [ V_363 ] . V_135 . V_136 . V_352 /
V_296 ;
V_338 = V_127 [ V_366 ] . V_135 . V_136 . V_352 /
V_296 ;
V_35 = F_135 ( V_262 , V_247 -> V_391 ) ;
V_35 -> V_42 = V_42 ;
V_35 -> V_299 = 0 ;
F_70 ( & V_35 -> V_212 ) ;
V_35 -> V_155 = NULL ;
V_35 -> V_156 = NULL ;
V_35 -> V_375 = V_375 ;
V_35 -> V_392 = V_374 -> V_392 ;
V_35 -> V_393 = V_374 -> V_393 ;
V_35 -> V_394 = V_374 -> V_394 ;
V_35 -> V_395 = V_374 -> V_395 ;
V_35 -> V_396 = V_374 -> V_396 ;
V_35 -> V_192 = V_374 -> V_192 ;
V_35 -> V_196 = V_374 -> V_196 ;
if ( V_35 -> V_42 -> V_262 . V_12 & V_304 ) {
switch ( V_35 -> type ) {
case V_199 :
if ( ! ( V_35 -> V_42 -> V_262 . V_12 &
V_306 ) )
V_35 -> V_299 |= V_300 ;
break;
case V_305 :
if ( V_35 -> V_42 -> V_262 . V_12 & V_306 )
V_35 -> V_299 |= V_300 ;
break;
}
}
V_35 -> V_139 = V_247 -> V_139 ;
for ( V_60 = 0 , V_389 = 0 ; V_60 < V_35 -> V_139 ; V_60 ++ ) {
V_113 = F_133 ( V_262 ) ;
F_42 ( & V_113 -> V_91 , & V_35 -> V_212 ) ;
V_113 -> type = V_247 -> V_266 ;
V_113 -> V_35 = V_35 ;
V_113 -> V_115 . V_35 = V_35 ;
V_207 = F_131 ( V_262 ) ;
if ( V_221 == V_247 -> V_266 )
V_208 = NULL ;
else
V_208 = F_131 ( V_262 ) ;
if ( 1 == V_372 -> V_354 )
V_113 -> V_397 = V_372 -> V_398 [ 0 ] . V_397 ;
else
V_113 -> V_397 = V_372 -> V_398 [ V_60 ] . V_397 ;
V_113 -> V_115 . V_2 . V_227 . V_228 =
V_127 [ V_367 ] . V_135 . V_136 . V_137 [ V_60 ] . V_288 . V_228 ;
V_113 -> V_115 . V_2 . V_227 . V_230 =
V_127 [ V_367 ] . V_135 . V_136 . V_137 [ V_60 ] . V_288 . V_230 ;
V_113 -> V_115 . V_2 . V_399 =
V_127 [ V_367 ] . V_135 . V_136 . V_137 [ V_60 ] . V_138 ;
V_113 -> V_115 . V_2 . V_240 = V_372 -> V_240 ;
if ( V_372 -> V_240 == V_241 )
V_113 -> V_115 . V_2 . V_233 = V_113 -> V_397 ;
else
V_113 -> V_115 . V_2 . V_233 = ( 1 << V_113 -> V_397 ) ;
V_113 -> V_115 . V_2 . V_3 = V_247 -> V_3 ;
V_113 -> V_115 . V_2 . V_246 = V_400 ;
V_113 -> V_115 . V_2 . V_244 = V_401 ;
F_140 ( V_113 , V_207 , V_208 ) ;
V_207 -> V_35 = V_35 ;
V_207 -> V_113 = V_113 ;
V_207 -> V_293 = (struct V_356 * ) V_378 [ V_389 ] . V_138 ;
V_207 -> V_293 -> V_402 = ( void * ) V_379 [ V_389 ] . V_138 ;
V_389 ++ ;
V_207 -> V_293 -> V_344 = V_247 -> V_344 ;
V_207 -> V_293 -> V_267 = V_207 ;
V_207 -> V_293 -> V_159 = V_42 -> V_159 ;
V_207 -> V_293 -> V_117 = 0 ;
V_207 -> V_403 = V_207 -> V_404 = 0 ;
V_207 -> V_405 = V_207 -> V_406 = 0 ;
F_141 ( V_207 , V_113 , V_339 , V_296 ,
& V_384 [ V_60 ] , & V_386 [ V_60 ] , & V_388 [ V_60 ] ) ;
if ( V_35 -> V_392 )
V_35 -> V_392 ( V_159 , V_207 -> V_293 ) ;
if ( V_208 ) {
V_208 -> V_35 = V_35 ;
V_208 -> V_113 = V_113 ;
V_208 -> V_293 = (struct V_356 * ) V_378 [ V_389 ] . V_138 ;
V_208 -> V_293 -> V_402 = ( void * ) V_379 [ V_389 ] . V_138 ;
V_389 ++ ;
V_208 -> V_293 -> V_344 = V_247 -> V_344 ;
V_208 -> V_293 -> V_267 = V_208 ;
V_208 -> V_293 -> V_159 = V_42 -> V_159 ;
V_208 -> V_293 -> V_117 = 1 ;
V_208 -> V_220 = ( V_247 -> V_266 == V_214 ) ?
V_247 -> V_407 . V_255
: V_247 -> V_408 ;
V_208 -> V_403 = V_208 -> V_404 = 0 ;
V_208 -> V_405 = V_208 -> V_406 = 0 ;
F_141 ( V_208 , V_113 , V_338 , V_296 ,
& V_383 [ V_60 ] , & V_385 [ V_60 ] ,
& V_387 [ V_60 ] ) ;
if ( V_35 -> V_392 )
V_35 -> V_392 ( V_159 , V_208 -> V_293 ) ;
}
V_113 -> V_115 . V_116 = (struct V_353 * ) V_377 [ V_60 ] . V_138 ;
V_113 -> V_115 . V_116 -> V_344 = V_247 -> V_344 +
( ( V_247 -> V_266 == V_221 ) ?
0 : V_247 -> V_344 ) ;
V_113 -> V_115 . V_116 -> V_115 = & V_113 -> V_115 ;
V_113 -> V_115 . V_116 -> V_293 [ 0 ] = V_207 -> V_293 ;
V_207 -> V_293 -> V_116 = V_113 -> V_115 . V_116 ;
if ( V_208 ) {
V_113 -> V_115 . V_116 -> V_293 [ 1 ] = V_208 -> V_293 ;
V_208 -> V_293 -> V_116 = V_113 -> V_115 . V_116 ;
}
V_113 -> V_115 . V_116 -> V_331 =
( V_6 * ) V_113 -> V_115 . V_2 . V_399 ;
V_113 -> V_115 . V_116 -> V_320 = & V_113 -> V_115 . V_2 . V_4 ;
V_113 -> V_115 . V_116 -> V_240 = V_113 -> V_115 . V_2 . V_240 ;
V_113 -> V_115 . V_116 -> V_233 = V_113 -> V_115 . V_2 . V_233 ;
V_113 -> V_115 . V_116 -> V_409 =
V_113 -> V_115 . V_2 . V_3 ;
V_113 -> V_115 . V_116 -> V_410 . V_411 = 0 ;
V_113 -> V_115 . V_116 -> V_410 . V_412 = 0 ;
V_113 -> V_115 . V_116 -> V_159 = V_42 -> V_159 ;
V_113 -> V_115 . V_116 -> V_117 = V_60 ;
F_144 ( V_113 , V_282 , V_296 ,
& V_380 [ V_60 ] , & V_381 [ V_60 ] , & V_382 [ V_60 ] ) ;
if ( V_35 -> V_394 )
V_35 -> V_394 ( V_159 , V_113 -> V_115 . V_116 ) ;
}
V_35 -> V_252 = V_247 -> V_407 ;
F_69 ( & V_35 -> V_8 , V_35 , V_247 , V_127 ) ;
F_6 ( V_35 , F_103 ) ;
V_262 -> V_413 |= ( 1 << V_35 -> V_36 ) ;
return V_35 ;
}
void
F_169 ( struct V_111 * V_35 )
{
struct V_261 * V_262 = & V_35 -> V_42 -> V_262 ;
struct V_206 * V_207 = NULL ;
struct V_206 * V_208 = NULL ;
struct V_112 * V_113 ;
struct V_90 * V_91 ;
F_71 ( & V_35 -> V_8 ) ;
while ( ! F_48 ( & V_35 -> V_212 ) ) {
F_49 ( & V_35 -> V_212 , & V_113 ) ;
F_124 ( V_113 , V_207 , V_208 ) ;
if ( V_35 -> V_393 )
V_35 -> V_393 ( V_35 -> V_42 -> V_159 , V_207 -> V_293 ) ;
V_207 -> V_293 = NULL ;
V_207 -> V_113 = NULL ;
V_207 -> V_35 = NULL ;
F_132 ( V_262 , V_207 ) ;
if ( V_208 ) {
if ( V_35 -> V_393 )
V_35 -> V_393 ( V_35 -> V_42 -> V_159 , V_208 -> V_293 ) ;
V_208 -> V_293 = NULL ;
V_208 -> V_113 = NULL ;
V_208 -> V_35 = NULL ;
F_132 ( V_262 , V_208 ) ;
}
V_113 -> V_267 . V_277 . V_278 = NULL ;
V_113 -> V_267 . V_277 . V_279 = NULL ;
if ( V_35 -> V_395 )
V_35 -> V_395 ( V_35 -> V_42 -> V_159 , V_113 -> V_115 . V_116 ) ;
V_113 -> V_115 . V_116 = NULL ;
V_113 -> V_35 = NULL ;
F_134 ( V_262 , V_113 ) ;
}
F_37 (qe, &rx_mod->rx_active_q) {
if ( V_91 == & V_35 -> V_91 ) {
F_44 ( & V_35 -> V_91 ) ;
F_45 ( & V_35 -> V_91 ) ;
break;
}
}
V_262 -> V_413 &= ~ ( 1 << V_35 -> V_36 ) ;
V_35 -> V_42 = NULL ;
V_35 -> V_375 = NULL ;
F_137 ( V_262 , V_35 ) ;
}
void
F_170 ( struct V_111 * V_35 )
{
if ( V_35 -> V_302 != ( V_414 ) F_103 )
return;
V_35 -> V_299 |= V_301 ;
if ( V_35 -> V_299 & V_300 )
F_65 ( V_35 , V_186 ) ;
}
void
F_171 ( struct V_111 * V_35 , enum V_98 type ,
void (* F_79)( void * , struct V_111 * ) )
{
if ( type == V_110 ) {
(* F_79)( V_35 -> V_42 -> V_159 , V_35 ) ;
} else {
V_35 -> V_155 = F_79 ;
V_35 -> V_156 = V_35 -> V_42 -> V_159 ;
V_35 -> V_299 &= ~ V_301 ;
F_65 ( V_35 , V_188 ) ;
}
}
void
F_172 ( struct V_111 * V_35 )
{
F_65 ( V_35 , V_202 ) ;
}
enum V_157
F_173 ( struct V_111 * V_35 , enum V_415 V_416 ,
enum V_415 V_417 ,
void (* F_79)( struct V_159 * , struct V_111 * ) )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
int V_418 = 0 ;
if ( F_87 ( V_416 , V_417 ) ) {
if ( ( V_35 -> V_42 -> V_147 != V_148 ) &&
( V_35 -> V_42 -> V_147 != V_8 -> V_35 -> V_36 ) )
goto V_169;
if ( V_35 -> V_42 -> V_149 != V_148 )
goto V_169;
if ( F_174 ( V_416 , V_417 ) )
goto V_169;
}
if ( F_174 ( V_416 , V_417 ) ) {
if ( ( V_35 -> V_42 -> V_149 != V_148 ) &&
( V_35 -> V_42 -> V_149 != V_8 -> V_35 -> V_36 ) ) {
goto V_169;
}
if ( V_35 -> V_42 -> V_147 != V_148 )
goto V_169;
}
if ( F_87 ( V_416 , V_417 ) ) {
if ( F_95 ( V_8 ) )
V_418 = 1 ;
} else if ( F_89 ( V_416 , V_417 ) ) {
if ( F_96 ( V_8 ) )
V_418 = 1 ;
}
if ( F_91 ( V_416 , V_417 ) ) {
if ( F_98 ( V_8 ) )
V_418 = 1 ;
} else if ( F_93 ( V_416 , V_417 ) ) {
if ( F_99 ( V_8 ) )
V_418 = 1 ;
}
if ( V_418 ) {
V_8 -> V_162 = F_79 ;
V_8 -> V_163 = V_35 -> V_42 -> V_159 ;
F_65 ( V_8 , V_18 ) ;
} else if ( F_79 )
(* F_79)( V_35 -> V_42 -> V_159 , V_35 ) ;
return V_164 ;
V_169:
return V_419 ;
}
void
F_175 ( struct V_111 * V_35 )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
if ( V_8 -> V_64 == V_141 ) {
V_8 -> V_64 = V_65 ;
V_8 -> V_105 = ( T_1 ) V_143 ;
F_65 ( V_8 , V_18 ) ;
}
}
void
F_176 ( struct V_111 * V_35 , int V_3 )
{
struct V_112 * V_113 ;
struct V_90 * V_91 ;
F_37 (qe, &rx->rxp_q) {
V_113 = (struct V_112 * ) V_91 ;
V_113 -> V_115 . V_116 -> V_409 = V_3 ;
F_1 ( & V_113 -> V_115 . V_2 , V_3 ) ;
}
}
void
F_177 ( struct V_42 * V_42 , const V_6 V_397 [] [ V_420 ] )
{
int V_60 , V_61 ;
for ( V_60 = 0 ; V_60 < V_421 ; V_60 ++ )
for ( V_61 = 0 ; V_61 < V_420 ; V_61 ++ )
V_42 -> V_262 . V_422 [ V_60 ] [ V_61 ] = V_397 [ V_60 ] [ V_61 ] ;
}
void
F_178 ( struct V_353 * V_116 )
{
struct V_42 * V_42 = V_116 -> V_115 -> V_35 -> V_42 ;
V_6 V_423 , V_424 ;
V_6 V_425 , V_426 , V_427 ;
T_1 V_3 ;
if ( ( V_116 -> V_410 . V_411 == 0 ) &&
( V_116 -> V_410 . V_412 == 0 ) )
return;
V_426 = V_116 -> V_410 . V_411 ;
V_427 = V_116 -> V_410 . V_412 ;
V_425 = V_426 + V_427 ;
if ( V_425 < V_428 )
V_423 = V_429 ;
else if ( V_425 < V_430 )
V_423 = V_431 ;
else if ( V_425 < V_432 )
V_423 = V_433 ;
else if ( V_425 < V_434 )
V_423 = V_435 ;
else if ( V_425 < V_436 )
V_423 = V_437 ;
else if ( V_425 < V_438 )
V_423 = V_439 ;
else if ( V_425 < V_440 )
V_423 = V_441 ;
else
V_423 = V_442 ;
if ( V_426 > ( V_427 << 1 ) )
V_424 = 0 ;
else
V_424 = 1 ;
V_116 -> V_410 . V_411 = 0 ;
V_116 -> V_410 . V_412 = 0 ;
V_3 = V_42 -> V_262 . V_422 [ V_423 ] [ V_424 ] ;
V_116 -> V_409 = V_3 ;
F_1 ( & V_116 -> V_115 -> V_2 , V_3 ) ;
}
static void
F_179 ( struct V_443 * V_444 )
{
F_180 ( V_444 ) ;
}
static void
F_181 ( struct V_443 * V_444 , enum V_445 V_10 )
{
switch ( V_10 ) {
case V_446 :
F_6 ( V_444 , V_447 ) ;
break;
case V_448 :
F_180 ( V_444 ) ;
break;
case V_449 :
break;
case V_450 :
F_182 ( V_444 ) ;
break;
case V_451 :
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_183 ( struct V_443 * V_444 )
{
F_184 ( V_444 ) ;
}
static void
V_447 ( struct V_443 * V_444 , enum V_445 V_10 )
{
switch ( V_10 ) {
case V_448 :
V_444 -> V_12 &= ~ ( V_452 | V_453 ) ;
F_6 ( V_444 , V_454 ) ;
break;
case V_449 :
V_444 -> V_12 &= ~ ( V_452 | V_453 ) ;
F_6 ( V_444 , F_181 ) ;
break;
case V_455 :
if ( V_444 -> V_12 & ( V_452 | V_453 ) ) {
V_444 -> V_12 &= ~ ( V_452 |
V_453 ) ;
F_6 ( V_444 , V_456 ) ;
} else
F_6 ( V_444 , V_457 ) ;
break;
case V_450 :
V_444 -> V_12 |= V_452 ;
break;
case V_451 :
V_444 -> V_12 |= V_453 ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_185 ( struct V_443 * V_444 )
{
struct V_458 * V_459 ;
struct V_90 * V_91 ;
int V_198 = ( V_444 -> type == V_460 ) ;
F_37 (qe, &tx->txq_q) {
V_459 = (struct V_458 * ) V_91 ;
V_459 -> V_461 -> V_462 = V_459 -> V_462 ;
F_115 ( V_444 -> V_42 , & V_459 -> V_2 , V_198 ) ;
}
V_444 -> V_463 ( V_444 -> V_42 -> V_159 , V_444 ) ;
}
static void
V_457 ( struct V_443 * V_444 , enum V_445 V_10 )
{
switch ( V_10 ) {
case V_448 :
F_6 ( V_444 , V_454 ) ;
V_444 -> V_464 ( V_444 -> V_42 -> V_159 , V_444 ) ;
F_186 ( V_444 ) ;
break;
case V_449 :
F_6 ( V_444 , V_465 ) ;
V_444 -> V_464 ( V_444 -> V_42 -> V_159 , V_444 ) ;
V_444 -> V_466 ( V_444 -> V_42 -> V_159 , V_444 ) ;
break;
case V_450 :
case V_451 :
F_6 ( V_444 , V_456 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_187 ( struct V_443 * V_444 )
{
}
static void
V_454 ( struct V_443 * V_444 , enum V_445 V_10 )
{
switch ( V_10 ) {
case V_449 :
case V_467 :
F_6 ( V_444 , V_468 ) ;
V_444 -> V_466 ( V_444 -> V_42 -> V_159 , V_444 ) ;
break;
case V_455 :
F_186 ( V_444 ) ;
break;
case V_450 :
case V_451 :
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_188 ( struct V_443 * V_444 )
{
}
static void
V_468 ( struct V_443 * V_444 , enum V_445 V_10 )
{
switch ( V_10 ) {
case V_449 :
case V_450 :
case V_451 :
break;
case V_469 :
F_6 ( V_444 , F_181 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_189 ( struct V_443 * V_444 )
{
V_444 -> V_464 ( V_444 -> V_42 -> V_159 , V_444 ) ;
F_186 ( V_444 ) ;
}
static void
V_456 ( struct V_443 * V_444 , enum V_445 V_10 )
{
switch ( V_10 ) {
case V_448 :
F_6 ( V_444 , V_454 ) ;
break;
case V_449 :
F_6 ( V_444 , V_465 ) ;
F_182 ( V_444 ) ;
V_444 -> V_466 ( V_444 -> V_42 -> V_159 , V_444 ) ;
break;
case V_467 :
F_6 ( V_444 , V_470 ) ;
break;
case V_450 :
case V_451 :
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_190 ( struct V_443 * V_444 )
{
F_182 ( V_444 ) ;
V_444 -> V_466 ( V_444 -> V_42 -> V_159 , V_444 ) ;
}
static void
V_470 ( struct V_443 * V_444 , enum V_445 V_10 )
{
switch ( V_10 ) {
case V_448 :
F_6 ( V_444 , V_468 ) ;
break;
case V_449 :
F_6 ( V_444 , V_465 ) ;
break;
case V_450 :
case V_451 :
break;
case V_469 :
F_6 ( V_444 , V_447 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_191 ( struct V_443 * V_444 )
{
}
static void
V_465 ( struct V_443 * V_444 , enum V_445 V_10 )
{
switch ( V_10 ) {
case V_446 :
F_6 ( V_444 , V_471 ) ;
break;
case V_448 :
F_6 ( V_444 , V_468 ) ;
break;
case V_449 :
break;
case V_469 :
F_6 ( V_444 , F_181 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_192 ( struct V_443 * V_444 )
{
}
static void
V_471 ( struct V_443 * V_444 , enum V_445 V_10 )
{
switch ( V_10 ) {
case V_448 :
F_6 ( V_444 , V_468 ) ;
break;
case V_449 :
F_6 ( V_444 , V_465 ) ;
break;
case V_469 :
F_6 ( V_444 , V_447 ) ;
break;
case V_451 :
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_184 ( struct V_443 * V_444 )
{
struct V_472 * V_205 = & V_444 -> V_31 . V_205 ;
struct V_458 * V_459 = NULL ;
struct V_90 * V_91 ;
int V_60 ;
F_21 ( V_205 -> V_33 , V_34 ,
V_473 , 0 , V_444 -> V_36 ) ;
V_205 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_472 ) ) ) ;
V_205 -> V_474 = V_444 -> V_475 ;
for ( V_60 = 0 , V_91 = F_122 ( & V_444 -> V_476 ) ;
V_60 < V_444 -> V_475 ;
V_60 ++ , V_91 = F_123 ( V_91 ) ) {
V_459 = (struct V_458 * ) V_91 ;
F_125 ( & V_205 -> V_215 [ V_60 ] . V_217 . V_217 , & V_459 -> V_218 ) ;
V_205 -> V_215 [ V_60 ] . V_217 . V_462 = V_459 -> V_462 ;
V_205 -> V_215 [ V_60 ] . V_2 . V_224 . V_225 . V_226 =
V_459 -> V_2 . V_227 . V_228 ;
V_205 -> V_215 [ V_60 ] . V_2 . V_224 . V_225 . V_229 =
V_459 -> V_2 . V_227 . V_230 ;
V_205 -> V_215 [ V_60 ] . V_2 . V_231 . V_232 =
F_22 ( ( T_2 ) V_459 -> V_2 . V_233 ) ;
}
V_205 -> V_234 . V_235 = V_65 ;
V_205 -> V_234 . V_236 = V_65 ;
V_205 -> V_234 . V_237 = V_141 ;
V_205 -> V_234 . V_238 = V_65 ;
V_205 -> V_234 . V_239 = ( V_459 -> V_2 . V_240 == V_241 )
? V_65 : V_141 ;
V_205 -> V_234 . V_242 =
F_31 ( ( V_6 ) V_459 -> V_2 . V_3 ) ;
V_205 -> V_234 . V_243 =
F_31 ( ( V_6 ) V_459 -> V_2 . V_244 ) ;
V_205 -> V_234 . V_245 = ( T_1 ) V_459 -> V_2 . V_246 ;
V_205 -> V_477 . V_478 = V_479 ;
V_205 -> V_477 . V_170 = F_22 ( ( T_2 ) V_444 -> V_480 ) ;
V_205 -> V_477 . V_481 = V_141 ;
V_205 -> V_477 . V_482 = V_141 ;
F_24 ( & V_444 -> V_41 , NULL , NULL ,
sizeof( struct V_472 ) , & V_205 -> V_33 ) ;
F_25 ( & V_444 -> V_42 -> V_43 , & V_444 -> V_41 ) ;
}
static void
F_193 ( struct V_443 * V_444 )
{
struct V_259 * V_30 = & V_444 -> V_31 . V_30 ;
F_21 ( V_30 -> V_33 , V_34 ,
V_483 , 0 , V_444 -> V_36 ) ;
V_30 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_259 ) ) ) ;
F_24 ( & V_444 -> V_41 , NULL , NULL , sizeof( struct V_259 ) ,
& V_30 -> V_33 ) ;
F_25 ( & V_444 -> V_42 -> V_43 , & V_444 -> V_41 ) ;
}
static void
F_186 ( struct V_443 * V_444 )
{
struct V_458 * V_459 ;
struct V_90 * V_91 ;
F_37 (qe, &tx->txq_q) {
V_459 = (struct V_458 * ) V_91 ;
F_129 ( V_444 -> V_42 , & V_459 -> V_2 ) ;
}
F_193 ( V_444 ) ;
}
static void
F_194 ( struct V_458 * V_459 , int V_282 , int V_283 ,
struct V_284 * V_285 ,
struct V_284 * V_286 ,
struct V_284 * V_287 )
{
T_1 * V_138 ;
T_3 V_288 ;
struct V_289 V_290 ;
int V_60 ;
V_459 -> V_218 . V_291 . V_228 = V_285 -> V_288 . V_228 ;
V_459 -> V_218 . V_291 . V_230 = V_285 -> V_288 . V_230 ;
V_459 -> V_218 . V_292 = V_285 -> V_138 ;
V_459 -> V_218 . V_282 = V_282 ;
V_459 -> V_218 . V_283 = V_283 ;
V_459 -> V_461 -> V_294 = ( void * * ) V_286 -> V_138 ;
V_459 -> V_461 -> V_295 = V_287 -> V_138 ;
V_138 = V_287 -> V_138 ;
F_142 ( & V_287 -> V_288 , V_288 ) ;
for ( V_60 = 0 ; V_60 < V_282 ; V_60 ++ ) {
V_459 -> V_461 -> V_294 [ V_60 ] = V_138 ;
V_138 += V_296 ;
F_143 ( V_288 , & V_290 ) ;
( (struct V_289 * ) V_459 -> V_218 . V_292 ) [ V_60 ] . V_228 =
V_290 . V_228 ;
( (struct V_289 * ) V_459 -> V_218 . V_292 ) [ V_60 ] . V_230 =
V_290 . V_230 ;
V_288 += V_296 ;
}
}
static struct V_443 *
F_195 ( struct V_484 * V_485 , enum V_486 type )
{
struct V_90 * V_91 = NULL ;
struct V_443 * V_444 = NULL ;
if ( F_48 ( & V_485 -> V_487 ) )
return NULL ;
if ( type == V_460 ) {
F_49 ( & V_485 -> V_487 , & V_91 ) ;
} else {
F_136 ( & V_485 -> V_487 , & V_91 ) ;
}
V_444 = (struct V_443 * ) V_91 ;
F_45 ( & V_444 -> V_91 ) ;
V_444 -> type = type ;
return V_444 ;
}
static void
F_196 ( struct V_443 * V_444 )
{
struct V_484 * V_485 = & V_444 -> V_42 -> V_485 ;
struct V_458 * V_459 ;
struct V_90 * V_273 ;
struct V_90 * V_91 ;
while ( ! F_48 ( & V_444 -> V_476 ) ) {
F_49 ( & V_444 -> V_476 , & V_459 ) ;
F_45 ( & V_459 -> V_91 ) ;
V_459 -> V_461 = NULL ;
V_459 -> V_444 = NULL ;
F_42 ( & V_459 -> V_91 , & V_485 -> V_488 ) ;
}
F_37 (qe, &tx_mod->tx_active_q) {
if ( V_91 == & V_444 -> V_91 ) {
F_44 ( & V_444 -> V_91 ) ;
F_45 ( & V_444 -> V_91 ) ;
break;
}
}
V_444 -> V_42 = NULL ;
V_444 -> V_375 = NULL ;
V_273 = NULL ;
F_37 (qe, &tx_mod->tx_free_q) {
if ( ( (struct V_443 * ) V_91 ) -> V_36 < V_444 -> V_36 )
V_273 = V_91 ;
else {
break;
}
}
if ( V_273 == NULL ) {
F_138 ( & V_485 -> V_487 , & V_444 -> V_91 ) ;
} else if ( F_123 ( V_273 ) == & V_485 -> V_487 ) {
F_42 ( & V_444 -> V_91 , & V_485 -> V_487 ) ;
} else {
F_123 ( & V_444 -> V_91 ) = F_123 ( V_273 ) ;
F_139 ( & V_444 -> V_91 ) = V_273 ;
F_123 ( V_273 ) = & V_444 -> V_91 ;
F_139 ( F_123 ( & V_444 -> V_91 ) ) = & V_444 -> V_91 ;
}
}
static void
F_197 ( struct V_443 * V_444 )
{
V_444 -> V_12 |= V_489 ;
if ( V_444 -> V_12 & V_490 )
F_65 ( V_444 , V_446 ) ;
}
static void
F_198 ( struct V_443 * V_444 )
{
V_444 -> V_155 = V_491 ;
V_444 -> V_156 = & V_444 -> V_42 -> V_485 ;
V_444 -> V_12 &= ~ V_489 ;
F_65 ( V_444 , V_448 ) ;
}
static void
F_199 ( struct V_443 * V_444 )
{
V_444 -> V_12 &= ~ V_489 ;
F_65 ( V_444 , V_449 ) ;
}
void
F_200 ( struct V_443 * V_444 , struct V_118 * V_119 )
{
struct V_492 * V_318 = & V_444 -> V_31 . V_318 ;
struct V_458 * V_459 = NULL ;
struct V_90 * V_91 ;
int V_60 ;
F_160 ( & V_444 -> V_42 -> V_43 , ( T_1 * ) V_318 ,
sizeof( struct V_492 ) ) ;
V_444 -> V_319 = V_318 -> V_319 ;
for ( V_60 = 0 , V_91 = F_122 ( & V_444 -> V_476 ) ;
V_60 < V_444 -> V_475 ; V_60 ++ , V_91 = F_123 ( V_91 ) ) {
V_459 = (struct V_458 * ) V_91 ;
V_459 -> V_461 -> V_320 -> V_321 =
V_444 -> V_42 -> V_322 . V_323
+ F_161 ( V_318 -> V_324 [ V_60 ] . V_320 ) ;
V_459 -> V_461 -> V_326 =
V_444 -> V_42 -> V_322 . V_323
+ F_161 ( V_318 -> V_324 [ V_60 ] . V_326 ) ;
V_459 -> V_319 = V_318 -> V_324 [ V_60 ] . V_493 ;
( * V_459 -> V_461 -> V_494 ) = 0 ;
V_459 -> V_461 -> V_332 = V_459 -> V_461 -> V_333 = 0 ;
}
F_65 ( V_444 , V_455 ) ;
}
void
F_201 ( struct V_443 * V_444 , struct V_118 * V_119 )
{
F_65 ( V_444 , V_467 ) ;
}
void
F_202 ( struct V_484 * V_485 )
{
struct V_443 * V_444 ;
struct V_90 * V_91 ;
F_37 (qe, &tx_mod->tx_active_q) {
V_444 = (struct V_443 * ) V_91 ;
F_65 ( V_444 , V_451 ) ;
}
}
void
F_203 ( int V_475 , int V_495 , struct V_126 * V_127 )
{
V_6 V_496 ;
V_6 V_282 ;
struct V_340 * V_136 ;
V_127 [ V_497 ] . V_348 = V_349 ;
V_136 = & V_127 [ V_497 ] . V_135 . V_136 ;
V_136 -> V_350 = V_351 ;
V_136 -> V_352 = sizeof( struct V_498 ) ;
V_136 -> V_354 = V_475 ;
V_496 = V_495 * V_499 ;
V_496 = F_165 ( V_496 , V_296 ) ;
V_282 = V_496 >> V_500 ;
V_127 [ V_501 ] . V_348 = V_349 ;
V_136 = & V_127 [ V_501 ] . V_135 . V_136 ;
V_136 -> V_350 = V_358 ;
V_136 -> V_352 = V_282 * sizeof( struct V_289 ) ;
V_136 -> V_354 = V_475 ;
V_127 [ V_502 ] . V_348 = V_349 ;
V_136 = & V_127 [ V_502 ] . V_135 . V_136 ;
V_136 -> V_350 = V_351 ;
V_136 -> V_352 = V_282 * sizeof( void * ) ;
V_136 -> V_354 = V_475 ;
V_127 [ V_503 ] . V_348 = V_349 ;
V_136 = & V_127 [ V_503 ] . V_135 . V_136 ;
V_136 -> V_350 = V_358 ;
V_136 -> V_352 = V_296 * V_282 ;
V_136 -> V_354 = V_475 ;
V_127 [ V_504 ] . V_348 = V_349 ;
V_136 = & V_127 [ V_504 ] . V_135 . V_136 ;
V_136 -> V_350 = V_358 ;
V_136 -> V_352 = V_368 ;
V_136 -> V_354 = V_475 ;
V_127 [ V_505 ] . V_348 = V_371 ;
V_127 [ V_505 ] . V_135 . V_372 . V_240 =
V_241 ;
V_127 [ V_505 ] . V_135 . V_372 . V_354 = V_475 ;
}
struct V_443 *
F_204 ( struct V_42 * V_42 , struct V_159 * V_159 ,
struct V_506 * V_477 ,
const struct V_507 * V_508 ,
struct V_126 * V_127 , void * V_375 )
{
struct V_376 * V_372 ;
struct V_484 * V_485 = & V_42 -> V_485 ;
struct V_443 * V_444 ;
struct V_458 * V_459 ;
struct V_90 * V_91 ;
int V_282 ;
int V_60 ;
V_372 = & V_127 [ V_505 ] . V_135 . V_372 ;
V_282 = ( V_127 [ V_503 ] . V_135 . V_136 . V_352 ) /
V_296 ;
if ( ( V_372 -> V_354 != 1 ) && ( V_372 -> V_354 != V_477 -> V_475 ) )
return NULL ;
V_444 = F_195 ( V_485 , V_477 -> V_509 ) ;
if ( ! V_444 )
return NULL ;
V_444 -> V_42 = V_42 ;
V_444 -> V_375 = V_375 ;
F_70 ( & V_444 -> V_476 ) ;
for ( V_60 = 0 ; V_60 < V_477 -> V_475 ; V_60 ++ ) {
if ( F_48 ( & V_485 -> V_488 ) )
goto V_169;
F_49 ( & V_485 -> V_488 , & V_459 ) ;
F_45 ( & V_459 -> V_91 ) ;
F_42 ( & V_459 -> V_91 , & V_444 -> V_476 ) ;
V_459 -> V_444 = V_444 ;
}
V_444 -> V_510 = V_508 -> V_510 ;
V_444 -> V_511 = V_508 -> V_511 ;
V_444 -> V_464 = V_508 -> V_464 ;
V_444 -> V_463 = V_508 -> V_463 ;
V_444 -> V_466 = V_508 -> V_466 ;
F_42 ( & V_444 -> V_91 , & V_485 -> V_512 ) ;
V_444 -> V_475 = V_477 -> V_475 ;
V_444 -> V_12 = 0 ;
if ( V_444 -> V_42 -> V_485 . V_12 & V_513 ) {
switch ( V_444 -> type ) {
case V_460 :
if ( ! ( V_444 -> V_42 -> V_485 . V_12 &
V_514 ) )
V_444 -> V_12 |= V_489 ;
break;
case V_515 :
if ( V_444 -> V_42 -> V_485 . V_12 & V_514 )
V_444 -> V_12 |= V_489 ;
break;
}
}
V_60 = 0 ;
F_37 (qe, &tx->txq_q) {
V_459 = (struct V_458 * ) V_91 ;
V_459 -> V_461 = (struct V_498 * )
V_127 [ V_497 ] . V_135 . V_136 . V_137 [ V_60 ] . V_138 ;
V_459 -> V_516 = 0 ;
V_459 -> V_517 = 0 ;
V_459 -> V_2 . V_227 . V_228 =
V_127 [ V_504 ] . V_135 . V_136 . V_137 [ V_60 ] . V_288 . V_228 ;
V_459 -> V_2 . V_227 . V_230 =
V_127 [ V_504 ] . V_135 . V_136 . V_137 [ V_60 ] . V_288 . V_230 ;
V_459 -> V_2 . V_399 =
V_127 [ V_504 ] . V_135 . V_136 . V_137 [ V_60 ] . V_138 ;
V_459 -> V_2 . V_240 = V_372 -> V_240 ;
V_459 -> V_2 . V_233 = ( V_372 -> V_354 == 1 ) ?
V_372 -> V_398 [ 0 ] . V_397 :
V_372 -> V_398 [ V_60 ] . V_397 ;
if ( V_372 -> V_240 == V_518 )
V_459 -> V_2 . V_233 = ( 1 << V_459 -> V_2 . V_233 ) ;
V_459 -> V_2 . V_3 = V_477 -> V_3 ;
V_459 -> V_2 . V_244 = V_519 ;
V_459 -> V_2 . V_246 = V_520 ;
V_459 -> V_461 -> V_344 = V_477 -> V_495 ;
V_459 -> V_461 -> V_402 = ( void * )
V_127 [ V_521 ] . V_135 . V_136 . V_137 [ V_60 ] . V_138 ;
V_459 -> V_461 -> V_494 =
( V_6 * ) V_459 -> V_2 . V_399 ;
V_459 -> V_461 -> V_320 = & V_459 -> V_2 . V_4 ;
V_459 -> V_461 -> V_240 = V_459 -> V_2 . V_240 ;
V_459 -> V_461 -> V_233 = V_459 -> V_2 . V_233 ;
V_459 -> V_461 -> V_459 = V_459 ;
V_459 -> V_461 -> V_159 = V_159 ;
V_459 -> V_461 -> V_117 = V_60 ;
F_194 ( V_459 , V_282 , V_296 ,
& V_127 [ V_501 ] . V_135 . V_136 . V_137 [ V_60 ] ,
& V_127 [ V_502 ] . V_135 . V_136 . V_137 [ V_60 ] ,
& V_127 [ V_503 ] .
V_135 . V_136 . V_137 [ V_60 ] ) ;
if ( V_444 -> V_510 )
( V_444 -> V_510 ) ( V_42 -> V_159 , V_459 -> V_461 ) ;
if ( V_477 -> V_475 == V_522 )
V_459 -> V_462 = V_459 -> V_461 -> V_117 ;
else
V_459 -> V_462 = V_485 -> V_523 ;
V_60 ++ ;
}
V_444 -> V_480 = 0 ;
F_6 ( V_444 , F_181 ) ;
V_485 -> V_413 |= ( 1 << V_444 -> V_36 ) ;
return V_444 ;
V_169:
F_196 ( V_444 ) ;
return NULL ;
}
void
F_205 ( struct V_443 * V_444 )
{
struct V_458 * V_459 ;
struct V_90 * V_91 ;
F_37 (qe, &tx->txq_q) {
V_459 = (struct V_458 * ) V_91 ;
if ( V_444 -> V_511 )
( V_444 -> V_511 ) ( V_444 -> V_42 -> V_159 , V_459 -> V_461 ) ;
}
V_444 -> V_42 -> V_485 . V_413 &= ~ ( 1 << V_444 -> V_36 ) ;
F_196 ( V_444 ) ;
}
void
F_206 ( struct V_443 * V_444 )
{
if ( V_444 -> V_302 != ( V_414 ) F_181 )
return;
V_444 -> V_12 |= V_490 ;
if ( V_444 -> V_12 & V_489 )
F_65 ( V_444 , V_446 ) ;
}
void
F_207 ( struct V_443 * V_444 , enum V_98 type ,
void (* F_79)( void * , struct V_443 * ) )
{
if ( type == V_110 ) {
(* F_79)( V_444 -> V_42 -> V_159 , V_444 ) ;
return;
}
V_444 -> V_155 = F_79 ;
V_444 -> V_156 = V_444 -> V_42 -> V_159 ;
V_444 -> V_12 &= ~ V_490 ;
F_65 ( V_444 , V_448 ) ;
}
void
F_208 ( struct V_443 * V_444 )
{
F_65 ( V_444 , V_469 ) ;
}
static void
V_491 ( void * V_297 , struct V_443 * V_444 )
{
struct V_484 * V_485 = (struct V_484 * ) V_297 ;
F_146 ( & V_485 -> V_524 ) ;
}
static void
F_209 ( void * V_297 )
{
struct V_484 * V_485 = (struct V_484 * ) V_297 ;
if ( V_485 -> V_155 )
V_485 -> V_155 ( & V_485 -> V_42 -> V_223 ) ;
V_485 -> V_155 = NULL ;
}
void
F_210 ( struct V_484 * V_485 , struct V_42 * V_42 ,
struct V_126 * V_127 )
{
int V_60 ;
V_485 -> V_42 = V_42 ;
V_485 -> V_12 = 0 ;
V_485 -> V_444 = (struct V_443 * )
V_127 [ V_525 ] . V_135 . V_136 . V_137 [ 0 ] . V_138 ;
V_485 -> V_459 = (struct V_458 * )
V_127 [ V_526 ] . V_135 . V_136 . V_137 [ 0 ] . V_138 ;
F_70 ( & V_485 -> V_487 ) ;
F_70 ( & V_485 -> V_512 ) ;
F_70 ( & V_485 -> V_488 ) ;
for ( V_60 = 0 ; V_60 < V_42 -> V_314 . V_315 . V_475 ; V_60 ++ ) {
V_485 -> V_444 [ V_60 ] . V_36 = V_60 ;
F_45 ( & V_485 -> V_444 [ V_60 ] . V_91 ) ;
F_42 ( & V_485 -> V_444 [ V_60 ] . V_91 , & V_485 -> V_487 ) ;
F_45 ( & V_485 -> V_459 [ V_60 ] . V_91 ) ;
F_42 ( & V_485 -> V_459 [ V_60 ] . V_91 , & V_485 -> V_488 ) ;
}
V_485 -> V_527 = V_528 ;
V_485 -> V_523 = 0 ;
V_485 -> V_529 = V_141 ;
V_485 -> V_530 = - 1 ;
}
void
F_211 ( struct V_484 * V_485 )
{
struct V_90 * V_91 ;
int V_60 ;
V_60 = 0 ;
F_37 (qe, &tx_mod->tx_free_q)
V_60 ++ ;
V_60 = 0 ;
F_37 (qe, &tx_mod->txq_free_q)
V_60 ++ ;
V_485 -> V_42 = NULL ;
}
void
F_212 ( struct V_484 * V_485 , enum V_486 type )
{
struct V_443 * V_444 ;
struct V_90 * V_91 ;
V_485 -> V_12 |= V_513 ;
if ( type == V_515 )
V_485 -> V_12 |= V_514 ;
F_37 (qe, &tx_mod->tx_active_q) {
V_444 = (struct V_443 * ) V_91 ;
if ( V_444 -> type == type )
F_197 ( V_444 ) ;
}
}
void
F_213 ( struct V_484 * V_485 , enum V_486 type )
{
struct V_443 * V_444 ;
struct V_90 * V_91 ;
V_485 -> V_12 &= ~ V_513 ;
V_485 -> V_12 &= ~ V_514 ;
V_485 -> V_155 = V_531 ;
F_153 ( & V_485 -> V_524 , F_209 , V_485 ) ;
F_37 (qe, &tx_mod->tx_active_q) {
V_444 = (struct V_443 * ) V_91 ;
if ( V_444 -> type == type ) {
F_154 ( & V_485 -> V_524 ) ;
F_198 ( V_444 ) ;
}
}
F_155 ( & V_485 -> V_524 ) ;
}
void
F_214 ( struct V_484 * V_485 )
{
struct V_443 * V_444 ;
struct V_90 * V_91 ;
V_485 -> V_12 &= ~ V_513 ;
V_485 -> V_12 &= ~ V_514 ;
F_37 (qe, &tx_mod->tx_active_q) {
V_444 = (struct V_443 * ) V_91 ;
F_199 ( V_444 ) ;
}
}
void
F_215 ( struct V_443 * V_444 , int V_3 )
{
struct V_458 * V_459 ;
struct V_90 * V_91 ;
F_37 (qe, &tx->txq_q) {
V_459 = (struct V_458 * ) V_91 ;
F_1 ( & V_459 -> V_2 , V_3 ) ;
}
}
