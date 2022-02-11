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
struct V_44 * V_30 =
& V_8 -> V_31 . V_45 ;
struct V_120 * V_121 =
(struct V_120 * ) V_119 ;
F_40 ( V_8 , ( T_1 * ) & V_30 -> V_38 ,
F_67 ( V_121 -> V_47 ) ) ;
F_65 ( V_8 , V_24 ) ;
}
static void
F_68 ( struct V_7 * V_8 ,
struct V_111 * V_35 ,
struct V_122 * V_123 ,
struct V_124 * V_125 )
{
V_8 -> V_35 = V_35 ;
F_69 ( & V_8 -> V_126 ) ;
F_69 ( & V_8 -> V_127 ) ;
V_8 -> V_128 = 0 ;
V_8 -> V_129 = 0 ;
F_69 ( & V_8 -> V_130 ) ;
V_8 -> V_131 = NULL ;
F_69 ( & V_8 -> V_103 ) ;
F_69 ( & V_8 -> V_102 ) ;
F_69 ( & V_8 -> V_104 ) ;
F_69 ( & V_8 -> V_97 ) ;
if ( V_123 -> V_132 )
V_8 -> V_12 |= V_13 ;
V_8 -> V_76 = ( T_1 * )
V_125 [ V_133 ] . V_134 . V_135 . V_136 [ 0 ] . V_137 ;
F_63 ( V_8 , V_123 -> V_138 ) ;
V_8 -> V_89 = V_123 -> V_89 ;
if ( V_8 -> V_89 == V_65 ) {
V_8 -> V_81 = V_123 -> V_139 ;
V_8 -> V_106 |= V_108 ;
V_8 -> V_106 |= V_107 ;
V_8 -> V_106 |= V_109 ;
}
V_8 -> V_64 = V_140 ;
memset ( V_8 -> V_67 , 0 ,
( sizeof( V_6 ) * ( V_141 / 32 ) ) ) ;
V_8 -> V_67 [ 0 ] |= 1 ;
V_8 -> V_105 = ( T_1 ) V_142 ;
V_8 -> V_69 = V_123 -> V_69 ;
F_6 ( V_8 , F_5 ) ;
}
static void
F_70 ( struct V_7 * V_8 )
{
struct V_25 * V_26 ;
V_8 -> V_128 = 0 ;
V_8 -> V_129 = 0 ;
while ( ! F_48 ( & V_8 -> V_126 ) ) {
F_49 ( & V_8 -> V_126 , & V_26 ) ;
F_45 ( & V_26 -> V_91 ) ;
F_71 ( & V_8 -> V_35 -> V_42 -> V_143 , V_26 ) ;
}
if ( V_8 -> V_131 ) {
F_45 ( & V_8 -> V_131 -> V_91 ) ;
F_71 ( & V_8 -> V_35 -> V_42 -> V_143 ,
V_8 -> V_131 ) ;
V_8 -> V_131 = NULL ;
}
while ( ! F_48 ( & V_8 -> V_103 ) ) {
F_49 ( & V_8 -> V_103 , & V_26 ) ;
F_45 ( & V_26 -> V_91 ) ;
F_50 ( & V_8 -> V_35 -> V_42 -> V_95 , V_26 ) ;
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
F_72 ( struct V_111 * V_35 )
{
F_65 ( V_35 , V_150 ) ;
}
static void
F_73 ( struct V_7 * V_8 )
{
V_8 -> V_151 = F_72 ;
V_8 -> V_152 = V_8 -> V_35 ;
F_65 ( V_8 , V_11 ) ;
}
static void
F_74 ( struct V_111 * V_35 )
{
F_65 ( V_35 , V_153 ) ;
}
static void
F_75 ( struct V_7 * V_8 )
{
V_8 -> V_154 = F_74 ;
V_8 -> V_155 = V_8 -> V_35 ;
F_65 ( V_8 , V_16 ) ;
}
static void
F_76 ( struct V_7 * V_8 )
{
F_65 ( V_8 , V_17 ) ;
}
enum V_156
F_77 ( struct V_111 * V_35 , T_1 * V_157 ,
void (* F_78)( struct V_158 * , struct V_111 * ) )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
if ( V_8 -> V_131 == NULL ) {
V_8 -> V_131 =
F_79 ( & V_8 -> V_35 -> V_42 -> V_143 ) ;
if ( V_8 -> V_131 == NULL )
return V_159 ;
F_45 ( & V_8 -> V_131 -> V_91 ) ;
}
memcpy ( V_8 -> V_131 -> V_39 , V_157 , V_160 ) ;
V_8 -> V_128 = 1 ;
V_8 -> V_161 = F_78 ;
V_8 -> V_162 = V_35 -> V_42 -> V_158 ;
F_65 ( V_8 , V_18 ) ;
return V_163 ;
}
enum V_156
F_80 ( struct V_111 * V_35 , T_1 * V_39 ,
void (* F_78)( struct V_158 * , struct V_111 * ) )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
struct V_25 * V_26 ;
if ( F_81 ( & V_8 -> V_104 , V_39 ) ||
F_81 ( & V_8 -> V_103 , V_39 ) ) {
if ( F_78 )
F_78 ( V_35 -> V_42 -> V_158 , V_35 ) ;
return V_163 ;
}
V_26 = F_82 ( & V_8 -> V_35 -> V_42 -> V_95 ) ;
if ( V_26 == NULL )
return V_164 ;
F_45 ( & V_26 -> V_91 ) ;
memcpy ( V_26 -> V_39 , V_39 , V_160 ) ;
F_42 ( & V_26 -> V_91 , & V_8 -> V_103 ) ;
V_8 -> V_161 = F_78 ;
V_8 -> V_162 = V_35 -> V_42 -> V_158 ;
F_65 ( V_8 , V_18 ) ;
return V_163 ;
}
enum V_156
F_83 ( struct V_111 * V_35 , int V_165 , T_1 * V_166 ,
void (* F_78)( struct V_158 * , struct V_111 * ) )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
struct V_90 V_90 ;
struct V_90 * V_91 ;
T_1 * V_167 ;
struct V_25 * V_26 ;
int V_60 ;
F_69 ( & V_90 ) ;
for ( V_60 = 0 , V_167 = V_166 ; V_60 < V_165 ; V_60 ++ ) {
V_26 = F_82 ( & V_8 -> V_35 -> V_42 -> V_95 ) ;
if ( V_26 == NULL )
goto V_168;
F_45 ( & V_26 -> V_91 ) ;
memcpy ( V_26 -> V_39 , V_167 , V_160 ) ;
F_42 ( & V_26 -> V_91 , & V_90 ) ;
V_167 += V_160 ;
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
V_8 -> V_161 = F_78 ;
V_8 -> V_162 = V_35 -> V_42 -> V_158 ;
F_65 ( V_8 , V_18 ) ;
return V_163 ;
V_168:
while ( ! F_48 ( & V_90 ) ) {
F_49 ( & V_90 , & V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_45 ( & V_26 -> V_91 ) ;
F_50 ( & V_8 -> V_35 -> V_42 -> V_95 , V_26 ) ;
}
return V_164 ;
}
void
F_84 ( struct V_111 * V_35 , int V_169 )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
int V_170 = ( V_169 >> V_171 ) ;
int V_172 = ( 1 << ( V_169 & V_173 ) ) ;
int V_174 = ( V_169 >> V_175 ) ;
V_8 -> V_67 [ V_170 ] |= V_172 ;
if ( V_8 -> V_64 == V_65 ) {
V_8 -> V_105 |= ( 1 << V_174 ) ;
F_65 ( V_8 , V_18 ) ;
}
}
void
F_85 ( struct V_111 * V_35 , int V_169 )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
int V_170 = ( V_169 >> V_171 ) ;
int V_172 = ( 1 << ( V_169 & V_173 ) ) ;
int V_174 = ( V_169 >> V_175 ) ;
V_8 -> V_67 [ V_170 ] &= ~ V_172 ;
if ( V_8 -> V_64 == V_65 ) {
V_8 -> V_105 |= ( 1 << V_174 ) ;
F_65 ( V_8 , V_18 ) ;
}
}
static int
F_54 ( struct V_7 * V_8 )
{
struct V_25 * V_26 = NULL ;
struct V_90 * V_91 ;
if ( ! F_48 ( & V_8 -> V_127 ) ) {
F_49 ( & V_8 -> V_127 , & V_91 ) ;
F_45 ( V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_20 ( V_8 , V_26 , V_176 ) ;
F_71 ( & V_8 -> V_35 -> V_42 -> V_143 , V_26 ) ;
return 1 ;
}
if ( V_8 -> V_128 ) {
V_8 -> V_128 = 0 ;
memcpy ( V_8 -> V_177 . V_39 ,
V_8 -> V_131 -> V_39 , V_160 ) ;
V_8 -> V_129 = 1 ;
F_20 ( V_8 , & V_8 -> V_177 ,
V_178 ) ;
return 1 ;
}
if ( ! F_48 ( & V_8 -> V_126 ) ) {
F_49 ( & V_8 -> V_126 , & V_91 ) ;
F_45 ( V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
F_42 ( & V_26 -> V_91 , & V_8 -> V_130 ) ;
F_20 ( V_8 , V_26 , V_179 ) ;
return 1 ;
}
return 0 ;
}
static int
F_58 ( struct V_7 * V_8 , enum V_98 V_99 )
{
struct V_90 * V_91 ;
struct V_25 * V_26 ;
while ( ! F_48 ( & V_8 -> V_127 ) ) {
F_49 ( & V_8 -> V_127 , & V_91 ) ;
F_45 ( V_91 ) ;
V_26 = (struct V_25 * ) V_91 ;
if ( V_99 == V_110 )
F_71 ( & V_8 -> V_35 -> V_42 -> V_143 , V_26 ) ;
else {
F_20 ( V_8 , V_26 ,
V_176 ) ;
F_71 ( & V_8 -> V_35 -> V_42 -> V_143 , V_26 ) ;
return 1 ;
}
}
while ( ! F_48 ( & V_8 -> V_130 ) ) {
F_49 ( & V_8 -> V_130 , & V_91 ) ;
F_45 ( V_91 ) ;
F_42 ( V_91 , & V_8 -> V_126 ) ;
if ( V_99 == V_101 ) {
V_26 = (struct V_25 * ) V_91 ;
F_20 ( V_8 , V_26 ,
V_176 ) ;
return 1 ;
}
}
if ( V_8 -> V_129 ) {
V_8 -> V_128 = 1 ;
V_8 -> V_129 = 0 ;
if ( V_99 == V_101 ) {
F_20 ( V_8 , & V_8 -> V_177 ,
V_180 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_55 ( struct V_7 * V_8 )
{
struct V_42 * V_42 = V_8 -> V_35 -> V_42 ;
if ( F_86 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_87 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_8 -> V_181 |= V_182 ;
F_29 ( V_8 , V_65 ) ;
return 1 ;
} else if ( F_88 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_87 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_8 -> V_181 &= ~ V_182 ;
V_42 -> V_146 = V_147 ;
F_29 ( V_8 , V_140 ) ;
return 1 ;
}
return 0 ;
}
static int
F_59 ( struct V_7 * V_8 , enum V_98 V_99 )
{
struct V_42 * V_42 = V_8 -> V_35 -> V_42 ;
if ( F_88 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_87 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_8 -> V_181 &= ~ V_182 ;
V_42 -> V_146 = V_147 ;
if ( V_99 == V_101 ) {
F_29 ( V_8 , V_140 ) ;
return 1 ;
}
}
if ( V_8 -> V_181 & V_182 ) {
F_89 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_8 -> V_181 &= ~ V_182 ;
if ( V_99 == V_101 ) {
F_29 ( V_8 , V_140 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_56 ( struct V_7 * V_8 )
{
if ( F_90 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_91 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_8 -> V_181 |= V_183 ;
F_28 ( V_8 , V_140 ) ;
return 1 ;
} else if ( F_92 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_91 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_8 -> V_181 &= ~ V_183 ;
F_28 ( V_8 , V_65 ) ;
return 1 ;
}
return 0 ;
}
static int
F_60 ( struct V_7 * V_8 , enum V_98 V_99 )
{
if ( F_92 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_91 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_8 -> V_181 &= ~ V_183 ;
if ( V_99 == V_101 ) {
F_28 ( V_8 , V_65 ) ;
return 1 ;
}
}
if ( V_8 -> V_181 & V_183 ) {
F_93 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_8 -> V_181 &= ~ V_183 ;
if ( V_99 == V_101 ) {
F_28 ( V_8 , V_65 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_94 ( struct V_7 * V_8 )
{
struct V_42 * V_42 = V_8 -> V_35 -> V_42 ;
int V_100 = 0 ;
if ( F_86 ( V_8 -> V_144 ,
V_8 -> V_145 ) ||
( V_8 -> V_181 & V_182 ) ) {
} else if ( F_88 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_87 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
} else {
F_89 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_42 -> V_146 = V_8 -> V_35 -> V_36 ;
V_100 = 1 ;
}
return V_100 ;
}
static int
F_95 ( struct V_7 * V_8 )
{
struct V_42 * V_42 = V_8 -> V_35 -> V_42 ;
int V_100 = 0 ;
if ( F_88 ( V_8 -> V_144 ,
V_8 -> V_145 ) ||
( ! ( V_8 -> V_181 & V_182 ) ) ) {
} else if ( F_86 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_87 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_42 -> V_146 = V_147 ;
} else if ( V_8 -> V_181 & V_182 ) {
F_96 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_100 = 1 ;
}
return V_100 ;
}
static int
F_97 ( struct V_7 * V_8 )
{
int V_100 = 0 ;
if ( F_90 ( V_8 -> V_144 ,
V_8 -> V_145 ) ||
( V_8 -> V_181 & V_183 ) ) {
} else if ( F_92 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_91 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
} else {
F_93 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_100 = 1 ;
}
return V_100 ;
}
static int
F_98 ( struct V_7 * V_8 )
{
int V_100 = 0 ;
if ( F_92 ( V_8 -> V_144 ,
V_8 -> V_145 ) ||
( ! ( V_8 -> V_181 & V_183 ) ) ) {
} else if ( F_90 ( V_8 -> V_144 ,
V_8 -> V_145 ) ) {
F_91 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
} else if ( V_8 -> V_181 & V_183 ) {
F_99 ( V_8 -> V_144 ,
V_8 -> V_145 ) ;
V_100 = 1 ;
}
return V_100 ;
}
static int
F_57 ( struct V_7 * V_8 )
{
if ( V_8 -> V_149 ) {
V_8 -> V_149 = false ;
F_32 ( V_8 ) ;
return 1 ;
}
return 0 ;
}
static void F_100 ( struct V_111 * V_35 )
{
F_101 ( V_35 ) ;
}
static void F_102 ( struct V_111 * V_35 ,
enum V_184 V_10 )
{
switch ( V_10 ) {
case V_185 :
F_6 ( V_35 , V_186 ) ;
break;
case V_187 :
F_101 ( V_35 ) ;
break;
case V_188 :
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void F_103 ( struct V_111 * V_35 )
{
F_104 ( V_35 ) ;
}
void
F_105 ( struct V_111 * V_35 )
{
}
static void
F_106 ( struct V_111 * V_35 , enum V_184 V_10 )
{
switch ( V_10 ) {
case V_188 :
case V_189 :
F_6 ( V_35 , V_190 ) ;
V_35 -> V_191 ( V_35 -> V_42 -> V_158 , V_35 ) ;
break;
case V_192 :
F_107 ( V_35 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void V_186 ( struct V_111 * V_35 ,
enum V_184 V_10 )
{
switch ( V_10 ) {
case V_187 :
F_6 ( V_35 , F_106 ) ;
break;
case V_188 :
F_6 ( V_35 , F_102 ) ;
break;
case V_192 :
F_6 ( V_35 , V_193 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void F_108 ( struct V_111 * V_35 )
{
V_35 -> V_194 ( V_35 -> V_42 -> V_158 , V_35 ) ;
F_73 ( & V_35 -> V_8 ) ;
}
void
F_109 ( struct V_111 * V_35 )
{
}
static void
F_110 ( struct V_111 * V_35 , enum V_184 V_10 )
{
switch ( V_10 ) {
case V_188 :
F_6 ( V_35 , V_190 ) ;
F_76 ( & V_35 -> V_8 ) ;
F_111 ( V_35 ) ;
V_35 -> V_191 ( V_35 -> V_42 -> V_158 , V_35 ) ;
break;
case V_150 :
F_75 ( & V_35 -> V_8 ) ;
break;
case V_153 :
F_6 ( V_35 , F_106 ) ;
F_111 ( V_35 ) ;
F_107 ( V_35 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
void
F_112 ( struct V_111 * V_35 )
{
struct V_112 * V_113 ;
struct V_90 * V_195 ;
int V_196 = ( V_35 -> type == V_197 ) ;
F_37 (qe_rxp, &rx->rxp_q) {
V_113 = (struct V_112 * ) V_195 ;
F_113 ( V_35 -> V_42 , & V_113 -> V_115 . V_2 , V_196 ) ;
}
F_114 ( & V_35 -> V_42 -> V_198 ) ;
}
static void
F_115 ( struct V_111 * V_35 , enum V_184 V_10 )
{
switch ( V_10 ) {
case V_187 :
F_6 ( V_35 , F_110 ) ;
F_116 ( & V_35 -> V_42 -> V_198 ) ;
F_75 ( & V_35 -> V_8 ) ;
break;
case V_188 :
F_6 ( V_35 , V_199 ) ;
F_116 ( & V_35 -> V_42 -> V_198 ) ;
F_76 ( & V_35 -> V_8 ) ;
F_111 ( V_35 ) ;
V_35 -> V_191 ( V_35 -> V_42 -> V_158 , V_35 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void V_193 ( struct V_111 * V_35 ,
enum V_184 V_10 )
{
switch ( V_10 ) {
case V_187 :
F_6 ( V_35 , F_110 ) ;
break;
case V_188 :
F_6 ( V_35 , V_199 ) ;
F_76 ( & V_35 -> V_8 ) ;
F_111 ( V_35 ) ;
V_35 -> V_191 ( V_35 -> V_42 -> V_158 , V_35 ) ;
break;
case V_150 :
F_6 ( V_35 , F_115 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
void
F_117 ( struct V_111 * V_35 )
{
}
void
V_190 ( struct V_111 * V_35 , enum V_184 V_10 )
{
switch ( V_10 ) {
case V_188 :
case V_153 :
break;
case V_200 :
F_6 ( V_35 , F_102 ) ;
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
V_199 ( struct V_111 * V_35 , enum V_184 V_10 )
{
switch ( V_10 ) {
case V_185 :
F_6 ( V_35 , V_201 ) ;
break;
case V_187 :
F_6 ( V_35 , V_190 ) ;
break;
case V_188 :
case V_150 :
case V_153 :
break;
case V_200 :
F_6 ( V_35 , F_102 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
} }
static void
F_119 ( struct V_111 * V_35 )
{
}
static void
V_201 ( struct V_111 * V_35 , enum V_184 V_10 )
{
switch ( V_10 ) {
case V_187 :
F_6 ( V_35 , V_190 ) ;
break;
case V_188 :
F_6 ( V_35 , V_199 ) ;
break;
case V_200 :
F_6 ( V_35 , V_186 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void
F_104 ( struct V_111 * V_35 )
{
struct V_202 * V_203 = & V_35 -> V_31 . V_203 ;
struct V_112 * V_113 = NULL ;
struct V_204 * V_205 = NULL , * V_206 = NULL ;
struct V_90 * V_207 ;
int V_60 ;
F_21 ( V_203 -> V_33 , V_34 ,
V_208 , 0 , V_35 -> V_36 ) ;
V_203 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_202 ) ) ) ;
V_203 -> V_209 = V_35 -> V_138 ;
for ( V_60 = 0 , V_207 = F_120 ( & V_35 -> V_210 ) ;
V_60 < V_35 -> V_138 ;
V_60 ++ , V_207 = F_121 ( V_207 ) ) {
V_113 = (struct V_112 * ) V_207 ;
F_122 ( V_113 , V_205 , V_206 ) ;
switch ( V_113 -> type ) {
case V_211 :
case V_212 :
F_123 ( & V_203 -> V_213 [ V_60 ] . V_214 . V_215 ,
& V_206 -> V_216 ) ;
V_203 -> V_213 [ V_60 ] . V_214 . V_217 =
F_22 ( ( T_2 ) V_206 -> V_218 ) ;
case V_219 :
F_123 ( & V_203 -> V_213 [ V_60 ] . V_220 . V_215 ,
& V_205 -> V_216 ) ;
V_205 -> V_218 =
F_124 ( & V_35 -> V_42 -> V_221 ) ;
V_203 -> V_213 [ V_60 ] . V_220 . V_217 =
F_22 ( ( T_2 ) V_205 -> V_218 ) ;
break;
default:
F_125 ( 1 ) ;
}
F_123 ( & V_203 -> V_213 [ V_60 ] . V_115 . V_215 ,
& V_113 -> V_115 . V_216 ) ;
V_203 -> V_213 [ V_60 ] . V_2 . V_222 . V_223 . V_224 =
V_113 -> V_115 . V_2 . V_225 . V_226 ;
V_203 -> V_213 [ V_60 ] . V_2 . V_222 . V_223 . V_227 =
V_113 -> V_115 . V_2 . V_225 . V_228 ;
V_203 -> V_213 [ V_60 ] . V_2 . V_229 . V_230 =
F_22 ( ( T_2 ) V_113 -> V_115 . V_2 . V_231 ) ;
}
V_203 -> V_232 . V_233 = V_140 ;
V_203 -> V_232 . V_234 = V_65 ;
V_203 -> V_232 . V_235 = V_140 ;
V_203 -> V_232 . V_236 = V_140 ;
V_203 -> V_232 . V_237 = ( V_113 -> V_115 . V_2 . V_238 == V_239 )
? V_65 :
V_140 ;
V_203 -> V_232 . V_240 =
F_31 ( ( V_6 ) V_113 -> V_115 . V_2 . V_3 ) ;
V_203 -> V_232 . V_241 =
F_31 ( ( V_6 ) V_113 -> V_115 . V_2 . V_242 ) ;
V_203 -> V_232 . V_243 = ( T_1 ) V_113 -> V_115 . V_2 . V_244 ;
switch ( V_113 -> type ) {
case V_211 :
V_203 -> V_245 . V_246 = V_247 ;
break;
case V_212 :
V_203 -> V_245 . V_246 = V_248 ;
V_203 -> V_245 . V_249 . type = V_35 -> V_250 . V_251 ;
V_203 -> V_245 . V_249 . V_252 = V_35 -> V_250 . V_253 ;
V_203 -> V_245 . V_249 . V_254 = V_35 -> V_250 . V_253 ;
break;
case V_219 :
V_203 -> V_245 . V_246 = V_255 ;
break;
default:
F_125 ( 1 ) ;
}
V_203 -> V_245 . V_256 = V_35 -> V_8 . V_69 ;
F_24 ( & V_35 -> V_41 , NULL , NULL ,
sizeof( struct V_202 ) , & V_203 -> V_33 ) ;
F_25 ( & V_35 -> V_42 -> V_43 , & V_35 -> V_41 ) ;
}
static void
F_126 ( struct V_111 * V_35 )
{
struct V_257 * V_30 = & V_35 -> V_31 . V_30 ;
F_21 ( V_30 -> V_33 , V_34 ,
V_258 , 0 , V_35 -> V_36 ) ;
V_30 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_257 ) ) ) ;
F_24 ( & V_35 -> V_41 , NULL , NULL , sizeof( struct V_257 ) ,
& V_30 -> V_33 ) ;
F_25 ( & V_35 -> V_42 -> V_43 , & V_35 -> V_41 ) ;
}
static void
F_107 ( struct V_111 * V_35 )
{
struct V_112 * V_113 ;
struct V_90 * V_195 ;
F_37 (qe_rxp, &rx->rxp_q) {
V_113 = (struct V_112 * ) V_195 ;
F_127 ( V_35 -> V_42 , & V_113 -> V_115 . V_2 ) ;
}
F_126 ( V_35 ) ;
}
static int
F_128 ( struct V_259 * V_260 , struct V_122 * V_245 )
{
if ( ( V_260 -> V_261 == 0 ) ||
( V_260 -> V_262 == 0 ) ||
( V_260 -> V_263 == 0 ) )
return 0 ;
if ( V_245 -> V_264 == V_219 ) {
if ( ( V_260 -> V_262 < V_245 -> V_138 ) ||
( V_260 -> V_263 < V_245 -> V_138 ) )
return 0 ;
} else {
if ( ( V_260 -> V_262 < V_245 -> V_138 ) ||
( V_260 -> V_263 < ( 2 * V_245 -> V_138 ) ) )
return 0 ;
}
return 1 ;
}
static struct V_204 *
F_129 ( struct V_259 * V_260 )
{
struct V_204 * V_265 = NULL ;
struct V_90 * V_91 = NULL ;
F_49 ( & V_260 -> V_266 , & V_91 ) ;
V_260 -> V_263 -- ;
V_265 = (struct V_204 * ) V_91 ;
F_45 ( & V_265 -> V_91 ) ;
return V_265 ;
}
static void
F_130 ( struct V_259 * V_260 , struct V_204 * V_265 )
{
F_45 ( & V_265 -> V_91 ) ;
F_42 ( & V_265 -> V_91 , & V_260 -> V_266 ) ;
V_260 -> V_263 ++ ;
}
static struct V_112 *
F_131 ( struct V_259 * V_260 )
{
struct V_90 * V_91 = NULL ;
struct V_112 * V_113 = NULL ;
F_49 ( & V_260 -> V_267 , & V_91 ) ;
V_260 -> V_262 -- ;
V_113 = (struct V_112 * ) V_91 ;
F_45 ( & V_113 -> V_91 ) ;
return V_113 ;
}
static void
F_132 ( struct V_259 * V_260 , struct V_112 * V_113 )
{
F_45 ( & V_113 -> V_91 ) ;
F_42 ( & V_113 -> V_91 , & V_260 -> V_267 ) ;
V_260 -> V_262 ++ ;
}
static struct V_111 *
F_133 ( struct V_259 * V_260 , enum V_268 type )
{
struct V_90 * V_91 = NULL ;
struct V_111 * V_35 = NULL ;
if ( type == V_197 ) {
F_49 ( & V_260 -> V_269 , & V_91 ) ;
} else
F_134 ( & V_260 -> V_269 , & V_91 ) ;
V_260 -> V_261 -- ;
V_35 = (struct V_111 * ) V_91 ;
F_45 ( & V_35 -> V_91 ) ;
F_42 ( & V_35 -> V_91 , & V_260 -> V_270 ) ;
V_35 -> type = type ;
return V_35 ;
}
static void
F_135 ( struct V_259 * V_260 , struct V_111 * V_35 )
{
struct V_90 * V_271 = NULL ;
struct V_90 * V_91 ;
F_45 ( & V_35 -> V_91 ) ;
F_37 (qe, &rx_mod->rx_free_q) {
if ( ( (struct V_111 * ) V_91 ) -> V_36 < V_35 -> V_36 )
V_271 = V_91 ;
else
break;
}
if ( V_271 == NULL ) {
F_136 ( & V_260 -> V_269 , & V_35 -> V_91 ) ;
} else if ( F_121 ( V_271 ) == & V_260 -> V_269 ) {
F_42 ( & V_35 -> V_91 , & V_260 -> V_269 ) ;
} else {
F_121 ( & V_35 -> V_91 ) = F_121 ( V_271 ) ;
F_137 ( & V_35 -> V_91 ) = V_271 ;
F_121 ( V_271 ) = & V_35 -> V_91 ;
F_137 ( F_121 ( & V_35 -> V_91 ) ) = & V_35 -> V_91 ;
}
V_260 -> V_261 ++ ;
}
static void
F_138 ( struct V_112 * V_113 , struct V_204 * V_205 ,
struct V_204 * V_206 )
{
switch ( V_113 -> type ) {
case V_219 :
V_113 -> V_265 . V_272 . V_273 = V_205 ;
V_113 -> V_265 . V_272 . V_274 = NULL ;
break;
case V_211 :
V_113 -> V_265 . V_275 . V_276 = V_205 ;
V_113 -> V_265 . V_275 . V_277 = V_206 ;
break;
case V_212 :
V_113 -> V_265 . V_249 . V_278 = V_205 ;
V_113 -> V_265 . V_249 . V_279 = V_206 ;
break;
default:
break;
}
}
static void
F_139 ( struct V_204 * V_265 ,
struct V_112 * V_113 ,
V_6 V_280 ,
V_6 V_281 ,
struct V_282 * V_283 ,
struct V_282 * V_284 ,
struct V_282 * V_285 )
{
int V_60 ;
V_265 -> V_216 . V_286 . V_226 = V_283 -> V_287 . V_226 ;
V_265 -> V_216 . V_286 . V_228 = V_283 -> V_287 . V_228 ;
V_265 -> V_216 . V_288 = V_283 -> V_137 ;
V_265 -> V_216 . V_280 = V_280 ;
V_265 -> V_216 . V_281 = V_281 ;
V_265 -> V_289 -> V_290 = ( void * * ) V_284 -> V_137 ;
for ( V_60 = 0 ; V_60 < V_265 -> V_216 . V_280 ; V_60 ++ ) {
V_265 -> V_289 -> V_290 [ V_60 ] = V_285 [ V_60 ] . V_137 ;
( (struct V_291 * ) V_265 -> V_216 . V_288 ) [ V_60 ] . V_226 =
V_285 [ V_60 ] . V_287 . V_226 ;
( (struct V_291 * ) V_265 -> V_216 . V_288 ) [ V_60 ] . V_228 =
V_285 [ V_60 ] . V_287 . V_228 ;
}
}
static void
F_140 ( struct V_112 * V_113 ,
V_6 V_280 ,
V_6 V_281 ,
struct V_282 * V_283 ,
struct V_282 * V_284 ,
struct V_282 * V_285 )
{
int V_60 ;
V_113 -> V_115 . V_216 . V_286 . V_226 = V_283 -> V_287 . V_226 ;
V_113 -> V_115 . V_216 . V_286 . V_228 = V_283 -> V_287 . V_228 ;
V_113 -> V_115 . V_216 . V_288 = V_283 -> V_137 ;
V_113 -> V_115 . V_216 . V_280 = V_280 ;
V_113 -> V_115 . V_216 . V_281 = V_281 ;
V_113 -> V_115 . V_116 -> V_290 = ( void * * ) V_284 -> V_137 ;
for ( V_60 = 0 ; V_60 < V_113 -> V_115 . V_216 . V_280 ; V_60 ++ ) {
V_113 -> V_115 . V_116 -> V_290 [ V_60 ] = V_285 [ V_60 ] . V_137 ;
( (struct V_291 * ) V_113 -> V_115 . V_216 . V_288 ) [ V_60 ] . V_226 =
V_285 [ V_60 ] . V_287 . V_226 ;
( (struct V_291 * ) V_113 -> V_115 . V_216 . V_288 ) [ V_60 ] . V_228 =
V_285 [ V_60 ] . V_287 . V_228 ;
}
}
static void
F_141 ( void * V_292 , struct V_111 * V_35 )
{
struct V_259 * V_260 = (struct V_259 * ) V_292 ;
F_142 ( & V_260 -> V_293 ) ;
}
static void
F_143 ( void * V_292 )
{
struct V_259 * V_260 = (struct V_259 * ) V_292 ;
if ( V_260 -> V_154 )
V_260 -> V_154 ( & V_260 -> V_42 -> V_221 ) ;
V_260 -> V_154 = NULL ;
}
static void
F_144 ( struct V_111 * V_35 )
{
V_35 -> V_294 |= V_295 ;
if ( V_35 -> V_294 & V_296 )
F_65 ( V_35 , V_185 ) ;
}
static void
F_145 ( struct V_111 * V_35 )
{
V_35 -> V_294 &= ~ V_295 ;
if ( V_35 -> V_297 == ( V_298 ) F_102 )
F_141 ( & V_35 -> V_42 -> V_260 , V_35 ) ;
else {
V_35 -> V_154 = F_141 ;
V_35 -> V_155 = & V_35 -> V_42 -> V_260 ;
F_65 ( V_35 , V_187 ) ;
}
}
static void
F_146 ( struct V_111 * V_35 )
{
V_35 -> V_294 &= ~ V_295 ;
F_65 ( V_35 , V_188 ) ;
}
void
F_147 ( struct V_259 * V_260 , enum V_268 type )
{
struct V_111 * V_35 ;
struct V_90 * V_91 ;
V_260 -> V_12 |= V_299 ;
if ( type == V_300 )
V_260 -> V_12 |= V_301 ;
F_37 (qe, &rx_mod->rx_active_q) {
V_35 = (struct V_111 * ) V_91 ;
if ( V_35 -> type == type )
F_144 ( V_35 ) ;
}
}
void
F_148 ( struct V_259 * V_260 , enum V_268 type )
{
struct V_111 * V_35 ;
struct V_90 * V_91 ;
V_260 -> V_12 &= ~ V_299 ;
V_260 -> V_12 &= ~ V_301 ;
V_260 -> V_154 = V_302 ;
F_149 ( & V_260 -> V_293 , F_143 , V_260 ) ;
F_37 (qe, &rx_mod->rx_active_q) {
V_35 = (struct V_111 * ) V_91 ;
if ( V_35 -> type == type ) {
F_150 ( & V_260 -> V_293 ) ;
F_145 ( V_35 ) ;
}
}
F_151 ( & V_260 -> V_293 ) ;
}
void
F_152 ( struct V_259 * V_260 )
{
struct V_111 * V_35 ;
struct V_90 * V_91 ;
V_260 -> V_12 &= ~ V_299 ;
V_260 -> V_12 &= ~ V_301 ;
F_37 (qe, &rx_mod->rx_active_q) {
V_35 = (struct V_111 * ) V_91 ;
F_146 ( V_35 ) ;
}
}
void F_153 ( struct V_259 * V_260 , struct V_42 * V_42 ,
struct V_124 * V_125 )
{
int V_170 ;
struct V_111 * V_303 ;
struct V_112 * V_304 ;
struct V_204 * V_305 ;
V_260 -> V_42 = V_42 ;
V_260 -> V_12 = 0 ;
V_260 -> V_35 = (struct V_111 * )
V_125 [ V_306 ] . V_134 . V_135 . V_136 [ 0 ] . V_137 ;
V_260 -> V_113 = (struct V_112 * )
V_125 [ V_307 ] . V_134 . V_135 . V_136 [ 0 ] . V_137 ;
V_260 -> V_265 = (struct V_204 * )
V_125 [ V_308 ] . V_134 . V_135 . V_136 [ 0 ] . V_137 ;
F_69 ( & V_260 -> V_269 ) ;
V_260 -> V_261 = 0 ;
F_69 ( & V_260 -> V_266 ) ;
V_260 -> V_263 = 0 ;
F_69 ( & V_260 -> V_267 ) ;
V_260 -> V_262 = 0 ;
F_69 ( & V_260 -> V_270 ) ;
for ( V_170 = 0 ; V_170 < V_42 -> V_309 . V_310 . V_311 ; V_170 ++ ) {
V_303 = & V_260 -> V_35 [ V_170 ] ;
F_45 ( & V_303 -> V_91 ) ;
F_69 ( & V_303 -> V_210 ) ;
V_303 -> V_42 = NULL ;
V_303 -> V_36 = V_170 ;
V_303 -> V_154 = NULL ;
V_303 -> V_155 = NULL ;
F_42 ( & V_303 -> V_91 , & V_260 -> V_269 ) ;
V_260 -> V_261 ++ ;
}
for ( V_170 = 0 ; V_170 < V_42 -> V_309 . V_310 . V_311 ; V_170 ++ ) {
V_304 = & V_260 -> V_113 [ V_170 ] ;
F_45 ( & V_304 -> V_91 ) ;
F_42 ( & V_304 -> V_91 , & V_260 -> V_267 ) ;
V_260 -> V_262 ++ ;
}
for ( V_170 = 0 ; V_170 < ( V_42 -> V_309 . V_310 . V_311 * 2 ) ; V_170 ++ ) {
V_305 = & V_260 -> V_265 [ V_170 ] ;
F_45 ( & V_305 -> V_91 ) ;
F_42 ( & V_305 -> V_91 , & V_260 -> V_266 ) ;
V_260 -> V_263 ++ ;
}
}
void
F_154 ( struct V_259 * V_260 )
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
V_260 -> V_42 = NULL ;
}
void
F_155 ( struct V_111 * V_35 , struct V_118 * V_119 )
{
struct V_312 * V_313 = & V_35 -> V_31 . V_313 ;
struct V_112 * V_113 = NULL ;
struct V_204 * V_205 = NULL , * V_206 = NULL ;
struct V_90 * V_207 ;
int V_60 ;
F_156 ( & V_35 -> V_42 -> V_43 , ( T_1 * ) V_313 ,
sizeof( struct V_312 ) ) ;
V_35 -> V_314 = V_313 -> V_314 ;
for ( V_60 = 0 , V_207 = F_120 ( & V_35 -> V_210 ) ;
V_60 < V_35 -> V_138 ;
V_60 ++ , V_207 = F_121 ( V_207 ) ) {
V_113 = (struct V_112 * ) V_207 ;
F_122 ( V_113 , V_205 , V_206 ) ;
V_113 -> V_115 . V_116 -> V_315 -> V_316 =
V_35 -> V_42 -> V_317 . V_318
+ F_157 ( V_313 -> V_319 [ V_60 ] . V_315 ) ;
V_113 -> V_314 = V_313 -> V_319 [ V_60 ] . V_320 ;
V_205 -> V_289 -> V_321 =
V_35 -> V_42 -> V_317 . V_318
+ F_157 ( V_313 -> V_319 [ V_60 ] . V_322 ) ;
V_205 -> V_314 = V_313 -> V_319 [ V_60 ] . V_323 ;
if ( V_206 ) {
V_206 -> V_289 -> V_321 =
V_35 -> V_42 -> V_317 . V_318
+ F_157 ( V_313 -> V_319 [ V_60 ] . V_324 ) ;
V_206 -> V_314 = V_313 -> V_319 [ V_60 ] . V_325 ;
}
( * V_113 -> V_115 . V_116 -> V_326 ) = 0 ;
V_113 -> V_115 . V_116 -> V_327 = 0 ;
V_205 -> V_289 -> V_327 = V_205 -> V_289 -> V_328 = 0 ;
if ( V_206 )
V_206 -> V_289 -> V_327 = V_206 -> V_289 -> V_328 = 0 ;
}
F_65 ( V_35 , V_192 ) ;
}
void
F_158 ( struct V_111 * V_35 , struct V_118 * V_119 )
{
F_65 ( V_35 , V_189 ) ;
}
void
F_159 ( struct V_122 * V_213 , struct V_124 * V_125 )
{
V_6 V_329 , V_330 , V_331 ;
V_6 V_332 , V_333 , V_334 ;
struct V_335 * V_135 ;
V_6 V_336 ;
V_6 V_337 ;
V_6 V_338 ;
V_338 = V_213 -> V_339 ;
V_337 = ( ( V_213 -> V_264 == V_219 ) ? 0 : V_213 -> V_339 ) ;
V_336 = V_338 + V_337 ;
F_160 ( V_336 ) ;
V_329 = V_336 * V_340 ;
V_329 = F_161 ( V_329 , V_341 ) ;
V_332 = F_162 ( V_329 ) ;
F_160 ( V_338 ) ;
V_331 = V_338 * V_342 ;
V_331 = F_161 ( V_331 , V_341 ) ;
V_334 = F_162 ( V_331 ) ;
if ( V_219 != V_213 -> V_264 ) {
F_160 ( V_337 ) ;
V_330 = V_337 * V_342 ;
V_330 = F_161 ( V_330 , V_341 ) ;
V_333 = F_162 ( V_330 ) ;
} else
V_333 = 0 ;
V_125 [ V_343 ] . V_344 = V_345 ;
V_135 = & V_125 [ V_343 ] . V_134 . V_135 ;
V_135 -> V_346 = V_347 ;
V_135 -> V_348 = sizeof( struct V_349 ) ;
V_135 -> V_350 = V_213 -> V_138 ;
V_125 [ V_351 ] . V_344 = V_345 ;
V_135 = & V_125 [ V_351 ] . V_134 . V_135 ;
V_135 -> V_346 = V_347 ;
V_135 -> V_348 = sizeof( struct V_352 ) ;
V_135 -> V_350 = F_163 ( V_213 ) ;
V_125 [ V_353 ] . V_344 = V_345 ;
V_135 = & V_125 [ V_353 ] . V_134 . V_135 ;
V_135 -> V_346 = V_354 ;
V_135 -> V_348 = V_332 * sizeof( struct V_291 ) ;
V_135 -> V_350 = V_213 -> V_138 ;
V_125 [ V_355 ] . V_344 = V_345 ;
V_135 = & V_125 [ V_355 ] . V_134 . V_135 ;
V_135 -> V_346 = V_347 ;
V_135 -> V_348 = V_332 * sizeof( void * ) ;
V_135 -> V_350 = V_213 -> V_138 ;
V_125 [ V_356 ] . V_344 = V_345 ;
V_135 = & V_125 [ V_356 ] . V_134 . V_135 ;
V_135 -> V_346 = V_354 ;
V_135 -> V_348 = V_341 ;
V_135 -> V_350 = V_332 * V_213 -> V_138 ;
V_125 [ V_357 ] . V_344 = V_345 ;
V_135 = & V_125 [ V_357 ] . V_134 . V_135 ;
V_135 -> V_346 = V_354 ;
V_135 -> V_348 = V_334 * sizeof( struct V_291 ) ;
V_135 -> V_350 = V_213 -> V_138 ;
V_125 [ V_358 ] . V_344 = V_345 ;
V_135 = & V_125 [ V_358 ] . V_134 . V_135 ;
V_135 -> V_346 = V_347 ;
V_135 -> V_348 = V_334 * sizeof( void * ) ;
V_135 -> V_350 = V_213 -> V_138 ;
V_125 [ V_359 ] . V_344 = V_345 ;
V_135 = & V_125 [ V_359 ] . V_134 . V_135 ;
V_135 -> V_346 = V_354 ;
V_135 -> V_348 = V_341 ;
V_135 -> V_350 = V_334 * V_213 -> V_138 ;
V_125 [ V_360 ] . V_344 = V_345 ;
V_135 = & V_125 [ V_360 ] . V_134 . V_135 ;
V_135 -> V_346 = V_354 ;
V_135 -> V_348 = V_333 * sizeof( struct V_291 ) ;
V_135 -> V_350 = ( V_333 ? V_213 -> V_138 : 0 ) ;
V_125 [ V_361 ] . V_344 = V_345 ;
V_135 = & V_125 [ V_361 ] . V_134 . V_135 ;
V_135 -> V_346 = V_347 ;
V_135 -> V_348 = V_333 * sizeof( void * ) ;
V_135 -> V_350 = ( V_333 ? V_213 -> V_138 : 0 ) ;
V_125 [ V_362 ] . V_344 = V_345 ;
V_135 = & V_125 [ V_362 ] . V_134 . V_135 ;
V_135 -> V_346 = V_354 ;
V_135 -> V_348 = ( V_333 ? V_341 : 0 ) ;
V_135 -> V_350 = ( V_333 ? ( V_333 * V_213 -> V_138 ) : 0 ) ;
V_125 [ V_363 ] . V_344 = V_345 ;
V_135 = & V_125 [ V_363 ] . V_134 . V_135 ;
V_135 -> V_346 = V_354 ;
V_135 -> V_348 = V_364 ;
V_135 -> V_350 = V_213 -> V_138 ;
V_125 [ V_133 ] . V_344 = V_345 ;
V_135 = & V_125 [ V_133 ] . V_134 . V_135 ;
V_135 -> V_346 = V_347 ;
V_135 -> V_348 = V_365 ;
V_135 -> V_350 = 1 ;
V_125 [ V_366 ] . V_344 = V_367 ;
V_125 [ V_366 ] . V_134 . V_368 . V_238 = V_239 ;
V_125 [ V_366 ] . V_134 . V_368 . V_350 = V_213 -> V_138 ;
}
struct V_111 *
F_164 ( struct V_42 * V_42 , struct V_158 * V_158 ,
struct V_122 * V_245 ,
const struct V_369 * V_370 ,
struct V_124 * V_125 ,
void * V_371 )
{
struct V_259 * V_260 = & V_42 -> V_260 ;
struct V_111 * V_35 ;
struct V_112 * V_113 ;
struct V_204 * V_205 ;
struct V_204 * V_206 ;
struct V_372 * V_368 ;
V_6 V_280 ;
struct V_282 * V_373 ;
struct V_282 * V_374 ;
struct V_282 * V_375 ;
struct V_282 * V_376 ;
struct V_282 * V_377 ;
struct V_282 * V_378 ;
struct V_282 * V_379 ;
struct V_282 * V_380 ;
struct V_282 * V_381 ;
struct V_282 * V_382 ;
struct V_282 * V_383 ;
struct V_282 * V_384 ;
int V_60 , V_385 = 0 , V_386 = 0 , V_387 = 0 ;
int V_334 , V_333 , V_388 ;
if ( ! F_128 ( V_260 , V_245 ) )
return NULL ;
V_368 = & V_125 [ V_366 ] . V_134 . V_368 ;
V_373 = & V_125 [ V_343 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_374 = & V_125 [ V_351 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_375 = & V_125 [ V_389 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_376 = & V_125 [ V_353 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_377 = & V_125 [ V_355 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_378 = & V_125 [ V_356 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_379 = & V_125 [ V_360 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_380 = & V_125 [ V_357 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_381 = & V_125 [ V_361 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_382 = & V_125 [ V_358 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_383 = & V_125 [ V_362 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_384 = & V_125 [ V_359 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_280 = V_125 [ V_356 ] . V_134 . V_135 . V_350 /
V_245 -> V_138 ;
V_334 = V_125 [ V_359 ] . V_134 . V_135 . V_350 /
V_245 -> V_138 ;
V_333 = V_125 [ V_362 ] . V_134 . V_135 . V_350 /
V_245 -> V_138 ;
V_35 = F_133 ( V_260 , V_245 -> V_390 ) ;
V_35 -> V_42 = V_42 ;
V_35 -> V_294 = 0 ;
F_69 ( & V_35 -> V_210 ) ;
V_35 -> V_154 = NULL ;
V_35 -> V_155 = NULL ;
V_35 -> V_371 = V_371 ;
V_35 -> V_391 = V_370 -> V_391 ;
V_35 -> V_392 = V_370 -> V_392 ;
V_35 -> V_393 = V_370 -> V_393 ;
V_35 -> V_394 = V_370 -> V_394 ;
V_35 -> V_395 = V_370 -> V_395 ;
V_35 -> V_191 = V_370 -> V_191 ;
V_35 -> V_194 = V_370 -> V_194 ;
if ( V_35 -> V_42 -> V_260 . V_12 & V_299 ) {
switch ( V_35 -> type ) {
case V_197 :
if ( ! ( V_35 -> V_42 -> V_260 . V_12 &
V_301 ) )
V_35 -> V_294 |= V_295 ;
break;
case V_300 :
if ( V_35 -> V_42 -> V_260 . V_12 & V_301 )
V_35 -> V_294 |= V_295 ;
break;
}
}
V_35 -> V_138 = V_245 -> V_138 ;
for ( V_60 = 0 , V_388 = 0 ; V_60 < V_35 -> V_138 ; V_60 ++ ) {
V_113 = F_131 ( V_260 ) ;
F_42 ( & V_113 -> V_91 , & V_35 -> V_210 ) ;
V_113 -> type = V_245 -> V_264 ;
V_113 -> V_35 = V_35 ;
V_113 -> V_115 . V_35 = V_35 ;
V_205 = F_129 ( V_260 ) ;
if ( V_219 == V_245 -> V_264 )
V_206 = NULL ;
else
V_206 = F_129 ( V_260 ) ;
if ( 1 == V_368 -> V_350 )
V_113 -> V_396 = V_368 -> V_397 [ 0 ] . V_396 ;
else
V_113 -> V_396 = V_368 -> V_397 [ V_60 ] . V_396 ;
V_113 -> V_115 . V_2 . V_225 . V_226 =
V_125 [ V_363 ] . V_134 . V_135 . V_136 [ V_60 ] . V_287 . V_226 ;
V_113 -> V_115 . V_2 . V_225 . V_228 =
V_125 [ V_363 ] . V_134 . V_135 . V_136 [ V_60 ] . V_287 . V_228 ;
V_113 -> V_115 . V_2 . V_398 =
V_125 [ V_363 ] . V_134 . V_135 . V_136 [ V_60 ] . V_137 ;
V_113 -> V_115 . V_2 . V_238 = V_368 -> V_238 ;
if ( V_368 -> V_238 == V_239 )
V_113 -> V_115 . V_2 . V_231 = V_113 -> V_396 ;
else
V_113 -> V_115 . V_2 . V_231 = ( 1 << V_113 -> V_396 ) ;
V_113 -> V_115 . V_2 . V_3 = V_245 -> V_3 ;
V_113 -> V_115 . V_2 . V_244 = V_399 ;
V_113 -> V_115 . V_2 . V_242 = V_400 ;
F_138 ( V_113 , V_205 , V_206 ) ;
V_205 -> V_35 = V_35 ;
V_205 -> V_113 = V_113 ;
V_205 -> V_289 = (struct V_352 * ) V_374 [ V_388 ] . V_137 ;
V_205 -> V_289 -> V_401 = ( void * ) V_375 [ V_388 ] . V_137 ;
V_388 ++ ;
V_205 -> V_289 -> V_339 = V_245 -> V_339 ;
V_205 -> V_289 -> V_265 = V_205 ;
V_205 -> V_289 -> V_158 = V_42 -> V_158 ;
V_205 -> V_289 -> V_117 = 0 ;
V_205 -> V_402 = V_205 -> V_403 = 0 ;
V_205 -> V_404 = V_205 -> V_405 = 0 ;
F_139 ( V_205 , V_113 , V_334 , V_341 ,
& V_380 [ V_60 ] , & V_382 [ V_60 ] , & V_384 [ V_386 ] ) ;
V_205 -> V_289 -> V_406 = V_386 ;
V_205 -> V_289 -> V_280 = V_334 ;
V_386 += V_334 ;
if ( V_35 -> V_391 )
V_35 -> V_391 ( V_158 , V_205 -> V_289 ) ;
if ( V_206 ) {
V_206 -> V_35 = V_35 ;
V_206 -> V_113 = V_113 ;
V_206 -> V_289 = (struct V_352 * ) V_374 [ V_388 ] . V_137 ;
V_206 -> V_289 -> V_401 = ( void * ) V_375 [ V_388 ] . V_137 ;
V_388 ++ ;
V_206 -> V_289 -> V_339 = V_245 -> V_339 ;
V_206 -> V_289 -> V_265 = V_206 ;
V_206 -> V_289 -> V_158 = V_42 -> V_158 ;
V_206 -> V_289 -> V_117 = 1 ;
V_206 -> V_218 = ( V_245 -> V_264 == V_212 ) ?
V_245 -> V_407 . V_253
: V_245 -> V_408 ;
V_206 -> V_402 = V_206 -> V_403 = 0 ;
V_206 -> V_404 = V_206 -> V_405 = 0 ;
F_139 ( V_206 , V_113 , V_333 , V_341 ,
& V_379 [ V_60 ] , & V_381 [ V_60 ] ,
& V_383 [ V_387 ] ) ;
V_206 -> V_289 -> V_406 = V_387 ;
V_206 -> V_289 -> V_280 = V_333 ;
V_387 += V_333 ;
if ( V_35 -> V_391 )
V_35 -> V_391 ( V_158 , V_206 -> V_289 ) ;
}
V_113 -> V_115 . V_116 = (struct V_349 * ) V_373 [ V_60 ] . V_137 ;
V_113 -> V_115 . V_116 -> V_339 = V_245 -> V_339 +
( ( V_245 -> V_264 == V_219 ) ?
0 : V_245 -> V_339 ) ;
V_113 -> V_115 . V_116 -> V_115 = & V_113 -> V_115 ;
V_113 -> V_115 . V_116 -> V_289 [ 0 ] = V_205 -> V_289 ;
V_205 -> V_289 -> V_116 = V_113 -> V_115 . V_116 ;
if ( V_206 ) {
V_113 -> V_115 . V_116 -> V_289 [ 1 ] = V_206 -> V_289 ;
V_206 -> V_289 -> V_116 = V_113 -> V_115 . V_116 ;
}
V_113 -> V_115 . V_116 -> V_326 =
( V_6 * ) V_113 -> V_115 . V_2 . V_398 ;
V_113 -> V_115 . V_116 -> V_315 = & V_113 -> V_115 . V_2 . V_4 ;
V_113 -> V_115 . V_116 -> V_238 = V_113 -> V_115 . V_2 . V_238 ;
V_113 -> V_115 . V_116 -> V_231 = V_113 -> V_115 . V_2 . V_231 ;
V_113 -> V_115 . V_116 -> V_409 =
V_113 -> V_115 . V_2 . V_3 ;
V_113 -> V_115 . V_116 -> V_410 . V_411 = 0 ;
V_113 -> V_115 . V_116 -> V_410 . V_412 = 0 ;
V_113 -> V_115 . V_116 -> V_158 = V_42 -> V_158 ;
V_113 -> V_115 . V_116 -> V_117 = V_60 ;
F_140 ( V_113 , V_280 , V_341 ,
& V_376 [ V_60 ] , & V_377 [ V_60 ] , & V_378 [ V_385 ] ) ;
V_113 -> V_115 . V_116 -> V_406 = V_385 ;
V_113 -> V_115 . V_116 -> V_280 = V_280 ;
V_385 += V_280 ;
if ( V_35 -> V_393 )
V_35 -> V_393 ( V_158 , V_113 -> V_115 . V_116 ) ;
}
V_35 -> V_250 = V_245 -> V_407 ;
F_68 ( & V_35 -> V_8 , V_35 , V_245 , V_125 ) ;
F_6 ( V_35 , F_102 ) ;
V_260 -> V_413 |= ( 1 << V_35 -> V_36 ) ;
return V_35 ;
}
void
F_165 ( struct V_111 * V_35 )
{
struct V_259 * V_260 = & V_35 -> V_42 -> V_260 ;
struct V_204 * V_205 = NULL ;
struct V_204 * V_206 = NULL ;
struct V_112 * V_113 ;
struct V_90 * V_91 ;
F_70 ( & V_35 -> V_8 ) ;
while ( ! F_48 ( & V_35 -> V_210 ) ) {
F_49 ( & V_35 -> V_210 , & V_113 ) ;
F_122 ( V_113 , V_205 , V_206 ) ;
if ( V_35 -> V_392 )
V_35 -> V_392 ( V_35 -> V_42 -> V_158 , V_205 -> V_289 ) ;
V_205 -> V_289 = NULL ;
V_205 -> V_113 = NULL ;
V_205 -> V_35 = NULL ;
F_130 ( V_260 , V_205 ) ;
if ( V_206 ) {
if ( V_35 -> V_392 )
V_35 -> V_392 ( V_35 -> V_42 -> V_158 , V_206 -> V_289 ) ;
V_206 -> V_289 = NULL ;
V_206 -> V_113 = NULL ;
V_206 -> V_35 = NULL ;
F_130 ( V_260 , V_206 ) ;
}
V_113 -> V_265 . V_275 . V_276 = NULL ;
V_113 -> V_265 . V_275 . V_277 = NULL ;
if ( V_35 -> V_394 )
V_35 -> V_394 ( V_35 -> V_42 -> V_158 , V_113 -> V_115 . V_116 ) ;
V_113 -> V_115 . V_116 = NULL ;
V_113 -> V_35 = NULL ;
F_132 ( V_260 , V_113 ) ;
}
F_37 (qe, &rx_mod->rx_active_q) {
if ( V_91 == & V_35 -> V_91 ) {
F_44 ( & V_35 -> V_91 ) ;
F_45 ( & V_35 -> V_91 ) ;
break;
}
}
V_260 -> V_413 &= ~ ( 1 << V_35 -> V_36 ) ;
V_35 -> V_42 = NULL ;
V_35 -> V_371 = NULL ;
F_135 ( V_260 , V_35 ) ;
}
void
F_166 ( struct V_111 * V_35 )
{
if ( V_35 -> V_297 != ( V_414 ) F_102 )
return;
V_35 -> V_294 |= V_296 ;
if ( V_35 -> V_294 & V_295 )
F_65 ( V_35 , V_185 ) ;
}
void
F_167 ( struct V_111 * V_35 , enum V_98 type ,
void (* F_78)( void * , struct V_111 * ) )
{
if ( type == V_110 ) {
(* F_78)( V_35 -> V_42 -> V_158 , V_35 ) ;
} else {
V_35 -> V_154 = F_78 ;
V_35 -> V_155 = V_35 -> V_42 -> V_158 ;
V_35 -> V_294 &= ~ V_296 ;
F_65 ( V_35 , V_187 ) ;
}
}
void
F_168 ( struct V_111 * V_35 )
{
F_65 ( V_35 , V_200 ) ;
}
enum V_156
F_169 ( struct V_111 * V_35 , enum V_415 V_416 ,
enum V_415 V_417 ,
void (* F_78)( struct V_158 * , struct V_111 * ) )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
int V_418 = 0 ;
if ( F_86 ( V_416 , V_417 ) ) {
if ( ( V_35 -> V_42 -> V_146 != V_147 ) &&
( V_35 -> V_42 -> V_146 != V_8 -> V_35 -> V_36 ) )
goto V_168;
if ( V_35 -> V_42 -> V_148 != V_147 )
goto V_168;
if ( F_170 ( V_416 , V_417 ) )
goto V_168;
}
if ( F_170 ( V_416 , V_417 ) ) {
if ( ( V_35 -> V_42 -> V_148 != V_147 ) &&
( V_35 -> V_42 -> V_148 != V_8 -> V_35 -> V_36 ) ) {
goto V_168;
}
if ( V_35 -> V_42 -> V_146 != V_147 )
goto V_168;
}
if ( F_86 ( V_416 , V_417 ) ) {
if ( F_94 ( V_8 ) )
V_418 = 1 ;
} else if ( F_88 ( V_416 , V_417 ) ) {
if ( F_95 ( V_8 ) )
V_418 = 1 ;
}
if ( F_90 ( V_416 , V_417 ) ) {
if ( F_97 ( V_8 ) )
V_418 = 1 ;
} else if ( F_92 ( V_416 , V_417 ) ) {
if ( F_98 ( V_8 ) )
V_418 = 1 ;
}
if ( V_418 ) {
V_8 -> V_161 = F_78 ;
V_8 -> V_162 = V_35 -> V_42 -> V_158 ;
F_65 ( V_8 , V_18 ) ;
} else if ( F_78 )
(* F_78)( V_35 -> V_42 -> V_158 , V_35 ) ;
return V_163 ;
V_168:
return V_419 ;
}
void
F_171 ( struct V_111 * V_35 )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
if ( V_8 -> V_64 == V_140 ) {
V_8 -> V_64 = V_65 ;
V_8 -> V_105 = ( T_1 ) V_142 ;
F_65 ( V_8 , V_18 ) ;
}
}
void
F_172 ( struct V_111 * V_35 , int V_3 )
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
F_173 ( struct V_42 * V_42 , const V_6 V_396 [] [ V_420 ] )
{
int V_60 , V_61 ;
for ( V_60 = 0 ; V_60 < V_421 ; V_60 ++ )
for ( V_61 = 0 ; V_61 < V_420 ; V_61 ++ )
V_42 -> V_260 . V_422 [ V_60 ] [ V_61 ] = V_396 [ V_60 ] [ V_61 ] ;
}
void
F_174 ( struct V_349 * V_116 )
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
V_3 = V_42 -> V_260 . V_422 [ V_423 ] [ V_424 ] ;
V_116 -> V_409 = V_3 ;
F_1 ( & V_116 -> V_115 -> V_2 , V_3 ) ;
}
static void
F_175 ( struct V_443 * V_444 )
{
F_176 ( V_444 ) ;
}
static void
F_177 ( struct V_443 * V_444 , enum V_445 V_10 )
{
switch ( V_10 ) {
case V_446 :
F_6 ( V_444 , V_447 ) ;
break;
case V_448 :
F_176 ( V_444 ) ;
break;
case V_449 :
break;
case V_450 :
F_178 ( V_444 ) ;
break;
case V_451 :
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_179 ( struct V_443 * V_444 )
{
F_180 ( V_444 ) ;
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
F_6 ( V_444 , F_177 ) ;
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
F_181 ( struct V_443 * V_444 )
{
struct V_458 * V_459 ;
struct V_90 * V_91 ;
int V_196 = ( V_444 -> type == V_460 ) ;
F_37 (qe, &tx->txq_q) {
V_459 = (struct V_458 * ) V_91 ;
V_459 -> V_461 -> V_462 = V_459 -> V_462 ;
F_113 ( V_444 -> V_42 , & V_459 -> V_2 , V_196 ) ;
}
V_444 -> V_463 ( V_444 -> V_42 -> V_158 , V_444 ) ;
}
static void
V_457 ( struct V_443 * V_444 , enum V_445 V_10 )
{
switch ( V_10 ) {
case V_448 :
F_6 ( V_444 , V_454 ) ;
V_444 -> V_464 ( V_444 -> V_42 -> V_158 , V_444 ) ;
F_182 ( V_444 ) ;
break;
case V_449 :
F_6 ( V_444 , V_465 ) ;
V_444 -> V_464 ( V_444 -> V_42 -> V_158 , V_444 ) ;
V_444 -> V_466 ( V_444 -> V_42 -> V_158 , V_444 ) ;
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
F_183 ( struct V_443 * V_444 )
{
}
static void
V_454 ( struct V_443 * V_444 , enum V_445 V_10 )
{
switch ( V_10 ) {
case V_449 :
case V_467 :
F_6 ( V_444 , V_468 ) ;
V_444 -> V_466 ( V_444 -> V_42 -> V_158 , V_444 ) ;
break;
case V_455 :
F_182 ( V_444 ) ;
break;
case V_450 :
case V_451 :
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_184 ( struct V_443 * V_444 )
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
F_6 ( V_444 , F_177 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_185 ( struct V_443 * V_444 )
{
V_444 -> V_464 ( V_444 -> V_42 -> V_158 , V_444 ) ;
F_182 ( V_444 ) ;
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
F_178 ( V_444 ) ;
V_444 -> V_466 ( V_444 -> V_42 -> V_158 , V_444 ) ;
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
F_186 ( struct V_443 * V_444 )
{
F_178 ( V_444 ) ;
V_444 -> V_466 ( V_444 -> V_42 -> V_158 , V_444 ) ;
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
F_187 ( struct V_443 * V_444 )
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
F_6 ( V_444 , F_177 ) ;
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
F_180 ( struct V_443 * V_444 )
{
struct V_472 * V_203 = & V_444 -> V_31 . V_203 ;
struct V_458 * V_459 = NULL ;
struct V_90 * V_91 ;
int V_60 ;
F_21 ( V_203 -> V_33 , V_34 ,
V_473 , 0 , V_444 -> V_36 ) ;
V_203 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_472 ) ) ) ;
V_203 -> V_474 = V_444 -> V_475 ;
for ( V_60 = 0 , V_91 = F_120 ( & V_444 -> V_476 ) ;
V_60 < V_444 -> V_475 ;
V_60 ++ , V_91 = F_121 ( V_91 ) ) {
V_459 = (struct V_458 * ) V_91 ;
F_123 ( & V_203 -> V_213 [ V_60 ] . V_215 . V_215 , & V_459 -> V_216 ) ;
V_203 -> V_213 [ V_60 ] . V_215 . V_462 = V_459 -> V_462 ;
V_203 -> V_213 [ V_60 ] . V_2 . V_222 . V_223 . V_224 =
V_459 -> V_2 . V_225 . V_226 ;
V_203 -> V_213 [ V_60 ] . V_2 . V_222 . V_223 . V_227 =
V_459 -> V_2 . V_225 . V_228 ;
V_203 -> V_213 [ V_60 ] . V_2 . V_229 . V_230 =
F_22 ( ( T_2 ) V_459 -> V_2 . V_231 ) ;
}
V_203 -> V_232 . V_233 = V_65 ;
V_203 -> V_232 . V_234 = V_65 ;
V_203 -> V_232 . V_235 = V_140 ;
V_203 -> V_232 . V_236 = V_65 ;
V_203 -> V_232 . V_237 = ( V_459 -> V_2 . V_238 == V_239 )
? V_65 : V_140 ;
V_203 -> V_232 . V_240 =
F_31 ( ( V_6 ) V_459 -> V_2 . V_3 ) ;
V_203 -> V_232 . V_241 =
F_31 ( ( V_6 ) V_459 -> V_2 . V_242 ) ;
V_203 -> V_232 . V_243 = ( T_1 ) V_459 -> V_2 . V_244 ;
V_203 -> V_477 . V_478 = V_479 ;
V_203 -> V_477 . V_169 = F_22 ( ( T_2 ) V_444 -> V_480 ) ;
V_203 -> V_477 . V_481 = V_140 ;
V_203 -> V_477 . V_482 = V_140 ;
F_24 ( & V_444 -> V_41 , NULL , NULL ,
sizeof( struct V_472 ) , & V_203 -> V_33 ) ;
F_25 ( & V_444 -> V_42 -> V_43 , & V_444 -> V_41 ) ;
}
static void
F_189 ( struct V_443 * V_444 )
{
struct V_257 * V_30 = & V_444 -> V_31 . V_30 ;
F_21 ( V_30 -> V_33 , V_34 ,
V_483 , 0 , V_444 -> V_36 ) ;
V_30 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_257 ) ) ) ;
F_24 ( & V_444 -> V_41 , NULL , NULL , sizeof( struct V_257 ) ,
& V_30 -> V_33 ) ;
F_25 ( & V_444 -> V_42 -> V_43 , & V_444 -> V_41 ) ;
}
static void
F_182 ( struct V_443 * V_444 )
{
struct V_458 * V_459 ;
struct V_90 * V_91 ;
F_37 (qe, &tx->txq_q) {
V_459 = (struct V_458 * ) V_91 ;
F_127 ( V_444 -> V_42 , & V_459 -> V_2 ) ;
}
F_189 ( V_444 ) ;
}
static void
F_190 ( struct V_458 * V_459 , int V_280 , int V_281 ,
struct V_282 * V_283 ,
struct V_282 * V_284 ,
struct V_282 * V_285 )
{
int V_60 ;
V_459 -> V_216 . V_286 . V_226 = V_283 -> V_287 . V_226 ;
V_459 -> V_216 . V_286 . V_228 = V_283 -> V_287 . V_228 ;
V_459 -> V_216 . V_288 = V_283 -> V_137 ;
V_459 -> V_216 . V_280 = V_280 ;
V_459 -> V_216 . V_281 = V_281 ;
V_459 -> V_461 -> V_290 = ( void * * ) V_284 -> V_137 ;
for ( V_60 = 0 ; V_60 < V_280 ; V_60 ++ ) {
V_459 -> V_461 -> V_290 [ V_60 ] = V_285 [ V_60 ] . V_137 ;
( (struct V_291 * ) V_459 -> V_216 . V_288 ) [ V_60 ] . V_226 =
V_285 [ V_60 ] . V_287 . V_226 ;
( (struct V_291 * ) V_459 -> V_216 . V_288 ) [ V_60 ] . V_228 =
V_285 [ V_60 ] . V_287 . V_228 ;
}
}
static struct V_443 *
F_191 ( struct V_484 * V_485 , enum V_486 type )
{
struct V_90 * V_91 = NULL ;
struct V_443 * V_444 = NULL ;
if ( F_48 ( & V_485 -> V_487 ) )
return NULL ;
if ( type == V_460 ) {
F_49 ( & V_485 -> V_487 , & V_91 ) ;
} else {
F_134 ( & V_485 -> V_487 , & V_91 ) ;
}
V_444 = (struct V_443 * ) V_91 ;
F_45 ( & V_444 -> V_91 ) ;
V_444 -> type = type ;
return V_444 ;
}
static void
F_192 ( struct V_443 * V_444 )
{
struct V_484 * V_485 = & V_444 -> V_42 -> V_485 ;
struct V_458 * V_459 ;
struct V_90 * V_271 ;
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
V_444 -> V_371 = NULL ;
V_271 = NULL ;
F_37 (qe, &tx_mod->tx_free_q) {
if ( ( (struct V_443 * ) V_91 ) -> V_36 < V_444 -> V_36 )
V_271 = V_91 ;
else {
break;
}
}
if ( V_271 == NULL ) {
F_136 ( & V_485 -> V_487 , & V_444 -> V_91 ) ;
} else if ( F_121 ( V_271 ) == & V_485 -> V_487 ) {
F_42 ( & V_444 -> V_91 , & V_485 -> V_487 ) ;
} else {
F_121 ( & V_444 -> V_91 ) = F_121 ( V_271 ) ;
F_137 ( & V_444 -> V_91 ) = V_271 ;
F_121 ( V_271 ) = & V_444 -> V_91 ;
F_137 ( F_121 ( & V_444 -> V_91 ) ) = & V_444 -> V_91 ;
}
}
static void
F_193 ( struct V_443 * V_444 )
{
V_444 -> V_12 |= V_489 ;
if ( V_444 -> V_12 & V_490 )
F_65 ( V_444 , V_446 ) ;
}
static void
F_194 ( struct V_443 * V_444 )
{
V_444 -> V_154 = V_491 ;
V_444 -> V_155 = & V_444 -> V_42 -> V_485 ;
V_444 -> V_12 &= ~ V_489 ;
F_65 ( V_444 , V_448 ) ;
}
static void
F_195 ( struct V_443 * V_444 )
{
V_444 -> V_12 &= ~ V_489 ;
F_65 ( V_444 , V_449 ) ;
}
void
F_196 ( struct V_443 * V_444 , struct V_118 * V_119 )
{
struct V_492 * V_313 = & V_444 -> V_31 . V_313 ;
struct V_458 * V_459 = NULL ;
struct V_90 * V_91 ;
int V_60 ;
F_156 ( & V_444 -> V_42 -> V_43 , ( T_1 * ) V_313 ,
sizeof( struct V_492 ) ) ;
V_444 -> V_314 = V_313 -> V_314 ;
for ( V_60 = 0 , V_91 = F_120 ( & V_444 -> V_476 ) ;
V_60 < V_444 -> V_475 ; V_60 ++ , V_91 = F_121 ( V_91 ) ) {
V_459 = (struct V_458 * ) V_91 ;
V_459 -> V_461 -> V_315 -> V_316 =
V_444 -> V_42 -> V_317 . V_318
+ F_157 ( V_313 -> V_319 [ V_60 ] . V_315 ) ;
V_459 -> V_461 -> V_321 =
V_444 -> V_42 -> V_317 . V_318
+ F_157 ( V_313 -> V_319 [ V_60 ] . V_321 ) ;
V_459 -> V_314 = V_313 -> V_319 [ V_60 ] . V_493 ;
( * V_459 -> V_461 -> V_494 ) = 0 ;
V_459 -> V_461 -> V_327 = V_459 -> V_461 -> V_328 = 0 ;
}
F_65 ( V_444 , V_455 ) ;
}
void
F_197 ( struct V_443 * V_444 , struct V_118 * V_119 )
{
F_65 ( V_444 , V_467 ) ;
}
void
F_198 ( struct V_484 * V_485 )
{
struct V_443 * V_444 ;
struct V_90 * V_91 ;
F_37 (qe, &tx_mod->tx_active_q) {
V_444 = (struct V_443 * ) V_91 ;
F_65 ( V_444 , V_451 ) ;
}
}
void
F_199 ( int V_475 , int V_495 , struct V_124 * V_125 )
{
V_6 V_496 ;
V_6 V_280 ;
struct V_335 * V_135 ;
V_125 [ V_497 ] . V_344 = V_345 ;
V_135 = & V_125 [ V_497 ] . V_134 . V_135 ;
V_135 -> V_346 = V_347 ;
V_135 -> V_348 = sizeof( struct V_498 ) ;
V_135 -> V_350 = V_475 ;
V_496 = V_495 * V_499 ;
V_496 = F_161 ( V_496 , V_341 ) ;
V_280 = V_496 >> V_500 ;
V_125 [ V_501 ] . V_344 = V_345 ;
V_135 = & V_125 [ V_501 ] . V_134 . V_135 ;
V_135 -> V_346 = V_354 ;
V_135 -> V_348 = V_280 * sizeof( struct V_291 ) ;
V_135 -> V_350 = V_475 ;
V_125 [ V_502 ] . V_344 = V_345 ;
V_135 = & V_125 [ V_502 ] . V_134 . V_135 ;
V_135 -> V_346 = V_347 ;
V_135 -> V_348 = V_280 * sizeof( void * ) ;
V_135 -> V_350 = V_475 ;
V_125 [ V_503 ] . V_344 = V_345 ;
V_135 = & V_125 [ V_503 ] . V_134 . V_135 ;
V_135 -> V_346 = V_354 ;
V_135 -> V_348 = V_341 ;
V_135 -> V_350 = V_475 * V_280 ;
V_125 [ V_504 ] . V_344 = V_345 ;
V_135 = & V_125 [ V_504 ] . V_134 . V_135 ;
V_135 -> V_346 = V_354 ;
V_135 -> V_348 = V_364 ;
V_135 -> V_350 = V_475 ;
V_125 [ V_505 ] . V_344 = V_367 ;
V_125 [ V_505 ] . V_134 . V_368 . V_238 =
V_239 ;
V_125 [ V_505 ] . V_134 . V_368 . V_350 = V_475 ;
}
struct V_443 *
F_200 ( struct V_42 * V_42 , struct V_158 * V_158 ,
struct V_506 * V_477 ,
const struct V_507 * V_508 ,
struct V_124 * V_125 , void * V_371 )
{
struct V_372 * V_368 ;
struct V_484 * V_485 = & V_42 -> V_485 ;
struct V_443 * V_444 ;
struct V_458 * V_459 ;
struct V_90 * V_91 ;
int V_280 ;
int V_281 ;
int V_406 ;
int V_60 ;
V_368 = & V_125 [ V_505 ] . V_134 . V_368 ;
V_280 = ( V_125 [ V_503 ] . V_134 . V_135 . V_350 ) /
V_477 -> V_475 ;
V_281 = V_125 [ V_503 ] . V_134 . V_135 . V_348 ;
if ( ( V_368 -> V_350 != 1 ) && ( V_368 -> V_350 != V_477 -> V_475 ) )
return NULL ;
V_444 = F_191 ( V_485 , V_477 -> V_509 ) ;
if ( ! V_444 )
return NULL ;
V_444 -> V_42 = V_42 ;
V_444 -> V_371 = V_371 ;
F_69 ( & V_444 -> V_476 ) ;
for ( V_60 = 0 ; V_60 < V_477 -> V_475 ; V_60 ++ ) {
if ( F_48 ( & V_485 -> V_488 ) )
goto V_168;
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
V_406 = 0 ;
F_37 (qe, &tx->txq_q) {
V_459 = (struct V_458 * ) V_91 ;
V_459 -> V_461 = (struct V_498 * )
V_125 [ V_497 ] . V_134 . V_135 . V_136 [ V_60 ] . V_137 ;
V_459 -> V_516 = 0 ;
V_459 -> V_517 = 0 ;
V_459 -> V_2 . V_225 . V_226 =
V_125 [ V_504 ] . V_134 . V_135 . V_136 [ V_60 ] . V_287 . V_226 ;
V_459 -> V_2 . V_225 . V_228 =
V_125 [ V_504 ] . V_134 . V_135 . V_136 [ V_60 ] . V_287 . V_228 ;
V_459 -> V_2 . V_398 =
V_125 [ V_504 ] . V_134 . V_135 . V_136 [ V_60 ] . V_137 ;
V_459 -> V_2 . V_238 = V_368 -> V_238 ;
V_459 -> V_2 . V_231 = ( V_368 -> V_350 == 1 ) ?
V_368 -> V_397 [ 0 ] . V_396 :
V_368 -> V_397 [ V_60 ] . V_396 ;
if ( V_368 -> V_238 == V_518 )
V_459 -> V_2 . V_231 = ( 1 << V_459 -> V_2 . V_231 ) ;
V_459 -> V_2 . V_3 = V_477 -> V_3 ;
V_459 -> V_2 . V_242 = 0 ;
V_459 -> V_2 . V_244 = V_519 ;
V_459 -> V_461 -> V_339 = V_477 -> V_495 ;
V_459 -> V_461 -> V_401 = ( void * )
V_125 [ V_520 ] . V_134 . V_135 . V_136 [ V_60 ] . V_137 ;
V_459 -> V_461 -> V_494 =
( V_6 * ) V_459 -> V_2 . V_398 ;
V_459 -> V_461 -> V_315 = & V_459 -> V_2 . V_4 ;
V_459 -> V_461 -> V_238 = V_459 -> V_2 . V_238 ;
V_459 -> V_461 -> V_231 = V_459 -> V_2 . V_231 ;
V_459 -> V_461 -> V_459 = V_459 ;
V_459 -> V_461 -> V_158 = V_158 ;
V_459 -> V_461 -> V_117 = V_60 ;
F_190 ( V_459 , V_280 , V_281 ,
& V_125 [ V_501 ] . V_134 . V_135 . V_136 [ V_60 ] ,
& V_125 [ V_502 ] . V_134 . V_135 . V_136 [ V_60 ] ,
& V_125 [ V_503 ] .
V_134 . V_135 . V_136 [ V_406 ] ) ;
V_459 -> V_461 -> V_406 = V_406 ;
V_459 -> V_461 -> V_280 = V_280 ;
V_406 += V_280 ;
if ( V_444 -> V_510 )
( V_444 -> V_510 ) ( V_42 -> V_158 , V_459 -> V_461 ) ;
if ( V_477 -> V_475 == V_521 )
V_459 -> V_462 = V_459 -> V_461 -> V_117 ;
else
V_459 -> V_462 = V_485 -> V_522 ;
V_60 ++ ;
}
V_444 -> V_480 = 0 ;
F_6 ( V_444 , F_177 ) ;
V_485 -> V_413 |= ( 1 << V_444 -> V_36 ) ;
return V_444 ;
V_168:
F_192 ( V_444 ) ;
return NULL ;
}
void
F_201 ( struct V_443 * V_444 )
{
struct V_458 * V_459 ;
struct V_90 * V_91 ;
F_37 (qe, &tx->txq_q) {
V_459 = (struct V_458 * ) V_91 ;
if ( V_444 -> V_511 )
( V_444 -> V_511 ) ( V_444 -> V_42 -> V_158 , V_459 -> V_461 ) ;
}
V_444 -> V_42 -> V_485 . V_413 &= ~ ( 1 << V_444 -> V_36 ) ;
F_192 ( V_444 ) ;
}
void
F_202 ( struct V_443 * V_444 )
{
if ( V_444 -> V_297 != ( V_414 ) F_177 )
return;
V_444 -> V_12 |= V_490 ;
if ( V_444 -> V_12 & V_489 )
F_65 ( V_444 , V_446 ) ;
}
void
F_203 ( struct V_443 * V_444 , enum V_98 type ,
void (* F_78)( void * , struct V_443 * ) )
{
if ( type == V_110 ) {
(* F_78)( V_444 -> V_42 -> V_158 , V_444 ) ;
return;
}
V_444 -> V_154 = F_78 ;
V_444 -> V_155 = V_444 -> V_42 -> V_158 ;
V_444 -> V_12 &= ~ V_490 ;
F_65 ( V_444 , V_448 ) ;
}
void
F_204 ( struct V_443 * V_444 )
{
F_65 ( V_444 , V_469 ) ;
}
static void
V_491 ( void * V_292 , struct V_443 * V_444 )
{
struct V_484 * V_485 = (struct V_484 * ) V_292 ;
F_142 ( & V_485 -> V_523 ) ;
}
static void
F_205 ( void * V_292 )
{
struct V_484 * V_485 = (struct V_484 * ) V_292 ;
if ( V_485 -> V_154 )
V_485 -> V_154 ( & V_485 -> V_42 -> V_221 ) ;
V_485 -> V_154 = NULL ;
}
void
F_206 ( struct V_484 * V_485 , struct V_42 * V_42 ,
struct V_124 * V_125 )
{
int V_60 ;
V_485 -> V_42 = V_42 ;
V_485 -> V_12 = 0 ;
V_485 -> V_444 = (struct V_443 * )
V_125 [ V_524 ] . V_134 . V_135 . V_136 [ 0 ] . V_137 ;
V_485 -> V_459 = (struct V_458 * )
V_125 [ V_525 ] . V_134 . V_135 . V_136 [ 0 ] . V_137 ;
F_69 ( & V_485 -> V_487 ) ;
F_69 ( & V_485 -> V_512 ) ;
F_69 ( & V_485 -> V_488 ) ;
for ( V_60 = 0 ; V_60 < V_42 -> V_309 . V_310 . V_475 ; V_60 ++ ) {
V_485 -> V_444 [ V_60 ] . V_36 = V_60 ;
F_45 ( & V_485 -> V_444 [ V_60 ] . V_91 ) ;
F_42 ( & V_485 -> V_444 [ V_60 ] . V_91 , & V_485 -> V_487 ) ;
F_45 ( & V_485 -> V_459 [ V_60 ] . V_91 ) ;
F_42 ( & V_485 -> V_459 [ V_60 ] . V_91 , & V_485 -> V_488 ) ;
}
V_485 -> V_526 = V_527 ;
V_485 -> V_522 = 0 ;
V_485 -> V_528 = V_140 ;
V_485 -> V_529 = - 1 ;
}
void
F_207 ( struct V_484 * V_485 )
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
F_208 ( struct V_484 * V_485 , enum V_486 type )
{
struct V_443 * V_444 ;
struct V_90 * V_91 ;
V_485 -> V_12 |= V_513 ;
if ( type == V_515 )
V_485 -> V_12 |= V_514 ;
F_37 (qe, &tx_mod->tx_active_q) {
V_444 = (struct V_443 * ) V_91 ;
if ( V_444 -> type == type )
F_193 ( V_444 ) ;
}
}
void
F_209 ( struct V_484 * V_485 , enum V_486 type )
{
struct V_443 * V_444 ;
struct V_90 * V_91 ;
V_485 -> V_12 &= ~ V_513 ;
V_485 -> V_12 &= ~ V_514 ;
V_485 -> V_154 = V_530 ;
F_149 ( & V_485 -> V_523 , F_205 , V_485 ) ;
F_37 (qe, &tx_mod->tx_active_q) {
V_444 = (struct V_443 * ) V_91 ;
if ( V_444 -> type == type ) {
F_150 ( & V_485 -> V_523 ) ;
F_194 ( V_444 ) ;
}
}
F_151 ( & V_485 -> V_523 ) ;
}
void
F_210 ( struct V_484 * V_485 )
{
struct V_443 * V_444 ;
struct V_90 * V_91 ;
V_485 -> V_12 &= ~ V_513 ;
V_485 -> V_12 &= ~ V_514 ;
F_37 (qe, &tx_mod->tx_active_q) {
V_444 = (struct V_443 * ) V_91 ;
F_195 ( V_444 ) ;
}
}
void
F_211 ( struct V_443 * V_444 , int V_3 )
{
struct V_458 * V_459 ;
struct V_90 * V_91 ;
F_37 (qe, &tx->txq_q) {
V_459 = (struct V_458 * ) V_91 ;
F_1 ( & V_459 -> V_2 , V_3 ) ;
}
}
