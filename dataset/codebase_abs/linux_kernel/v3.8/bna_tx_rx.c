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
F_6 ( V_35 , V_193 ) ;
break;
case V_188 :
F_6 ( V_35 , F_102 ) ;
break;
case V_192 :
F_6 ( V_35 , V_194 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void F_108 ( struct V_111 * V_35 )
{
V_35 -> V_195 ( V_35 -> V_42 -> V_158 , V_35 ) ;
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
static void
F_112 ( struct V_111 * V_35 )
{
}
static void
V_193 ( struct V_111 * V_35 , enum V_184 V_10 )
{
switch ( V_10 ) {
case V_188 :
case V_189 :
F_6 ( V_35 , F_102 ) ;
break;
case V_192 :
F_107 ( V_35 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
void
F_113 ( struct V_111 * V_35 )
{
struct V_112 * V_113 ;
struct V_90 * V_196 ;
int V_197 = ( V_35 -> type == V_198 ) ;
F_37 (qe_rxp, &rx->rxp_q) {
V_113 = (struct V_112 * ) V_196 ;
F_114 ( V_35 -> V_42 , & V_113 -> V_115 . V_2 , V_197 ) ;
}
F_115 ( & V_35 -> V_42 -> V_199 ) ;
}
static void
F_116 ( struct V_111 * V_35 , enum V_184 V_10 )
{
switch ( V_10 ) {
case V_187 :
F_6 ( V_35 , F_110 ) ;
F_117 ( & V_35 -> V_42 -> V_199 ) ;
F_75 ( & V_35 -> V_8 ) ;
break;
case V_188 :
F_6 ( V_35 , V_200 ) ;
F_117 ( & V_35 -> V_42 -> V_199 ) ;
F_76 ( & V_35 -> V_8 ) ;
F_111 ( V_35 ) ;
V_35 -> V_191 ( V_35 -> V_42 -> V_158 , V_35 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
static void V_194 ( struct V_111 * V_35 ,
enum V_184 V_10 )
{
switch ( V_10 ) {
case V_187 :
F_6 ( V_35 , F_110 ) ;
break;
case V_188 :
F_6 ( V_35 , V_200 ) ;
F_76 ( & V_35 -> V_8 ) ;
F_111 ( V_35 ) ;
V_35 -> V_191 ( V_35 -> V_42 -> V_158 , V_35 ) ;
break;
case V_150 :
F_6 ( V_35 , F_116 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
}
}
void
F_118 ( struct V_111 * V_35 )
{
}
void
V_190 ( struct V_111 * V_35 , enum V_184 V_10 )
{
switch ( V_10 ) {
case V_188 :
case V_153 :
break;
case V_201 :
F_6 ( V_35 , F_102 ) ;
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
V_200 ( struct V_111 * V_35 , enum V_184 V_10 )
{
switch ( V_10 ) {
case V_185 :
F_6 ( V_35 , V_202 ) ;
break;
case V_187 :
F_6 ( V_35 , V_190 ) ;
break;
case V_188 :
case V_150 :
case V_153 :
break;
case V_201 :
F_6 ( V_35 , F_102 ) ;
break;
default:
F_11 ( V_10 ) ;
break;
} }
static void
F_120 ( struct V_111 * V_35 )
{
}
static void
V_202 ( struct V_111 * V_35 , enum V_184 V_10 )
{
switch ( V_10 ) {
case V_187 :
F_6 ( V_35 , V_190 ) ;
break;
case V_188 :
F_6 ( V_35 , V_200 ) ;
break;
case V_201 :
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
struct V_203 * V_204 = & V_35 -> V_31 . V_204 ;
struct V_112 * V_113 = NULL ;
struct V_205 * V_206 = NULL , * V_207 = NULL ;
struct V_90 * V_208 ;
int V_60 ;
F_21 ( V_204 -> V_33 , V_34 ,
V_209 , 0 , V_35 -> V_36 ) ;
V_204 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_203 ) ) ) ;
V_204 -> V_210 = V_35 -> V_138 ;
for ( V_60 = 0 , V_208 = F_121 ( & V_35 -> V_211 ) ;
V_60 < V_35 -> V_138 ;
V_60 ++ , V_208 = F_122 ( V_208 ) ) {
V_113 = (struct V_112 * ) V_208 ;
F_123 ( V_113 , V_206 , V_207 ) ;
switch ( V_113 -> type ) {
case V_212 :
case V_213 :
F_124 ( & V_204 -> V_214 [ V_60 ] . V_215 . V_216 ,
& V_207 -> V_217 ) ;
V_204 -> V_214 [ V_60 ] . V_215 . V_218 =
F_22 ( ( T_2 ) V_207 -> V_219 ) ;
case V_220 :
F_124 ( & V_204 -> V_214 [ V_60 ] . V_221 . V_216 ,
& V_206 -> V_217 ) ;
V_206 -> V_219 =
F_125 ( & V_35 -> V_42 -> V_222 ) ;
V_204 -> V_214 [ V_60 ] . V_221 . V_218 =
F_22 ( ( T_2 ) V_206 -> V_219 ) ;
break;
default:
F_126 ( 1 ) ;
}
F_124 ( & V_204 -> V_214 [ V_60 ] . V_115 . V_216 ,
& V_113 -> V_115 . V_217 ) ;
V_204 -> V_214 [ V_60 ] . V_2 . V_223 . V_224 . V_225 =
V_113 -> V_115 . V_2 . V_226 . V_227 ;
V_204 -> V_214 [ V_60 ] . V_2 . V_223 . V_224 . V_228 =
V_113 -> V_115 . V_2 . V_226 . V_229 ;
V_204 -> V_214 [ V_60 ] . V_2 . V_230 . V_231 =
F_22 ( ( T_2 ) V_113 -> V_115 . V_2 . V_232 ) ;
}
V_204 -> V_233 . V_234 = V_140 ;
V_204 -> V_233 . V_235 = V_65 ;
V_204 -> V_233 . V_236 = V_140 ;
V_204 -> V_233 . V_237 = V_140 ;
V_204 -> V_233 . V_238 = ( V_113 -> V_115 . V_2 . V_239 == V_240 )
? V_65 :
V_140 ;
V_204 -> V_233 . V_241 =
F_31 ( ( V_6 ) V_113 -> V_115 . V_2 . V_3 ) ;
V_204 -> V_233 . V_242 =
F_31 ( ( V_6 ) V_113 -> V_115 . V_2 . V_243 ) ;
V_204 -> V_233 . V_244 = ( T_1 ) V_113 -> V_115 . V_2 . V_245 ;
switch ( V_113 -> type ) {
case V_212 :
V_204 -> V_246 . V_247 = V_248 ;
break;
case V_213 :
V_204 -> V_246 . V_247 = V_249 ;
V_204 -> V_246 . V_250 . type = V_35 -> V_251 . V_252 ;
V_204 -> V_246 . V_250 . V_253 = V_35 -> V_251 . V_254 ;
V_204 -> V_246 . V_250 . V_255 = V_35 -> V_251 . V_254 ;
break;
case V_220 :
V_204 -> V_246 . V_247 = V_256 ;
break;
default:
F_126 ( 1 ) ;
}
V_204 -> V_246 . V_257 = V_35 -> V_8 . V_69 ;
F_24 ( & V_35 -> V_41 , NULL , NULL ,
sizeof( struct V_203 ) , & V_204 -> V_33 ) ;
F_25 ( & V_35 -> V_42 -> V_43 , & V_35 -> V_41 ) ;
}
static void
F_127 ( struct V_111 * V_35 )
{
struct V_258 * V_30 = & V_35 -> V_31 . V_30 ;
F_21 ( V_30 -> V_33 , V_34 ,
V_259 , 0 , V_35 -> V_36 ) ;
V_30 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_258 ) ) ) ;
F_24 ( & V_35 -> V_41 , NULL , NULL , sizeof( struct V_258 ) ,
& V_30 -> V_33 ) ;
F_25 ( & V_35 -> V_42 -> V_43 , & V_35 -> V_41 ) ;
}
static void
F_107 ( struct V_111 * V_35 )
{
struct V_112 * V_113 ;
struct V_90 * V_196 ;
F_37 (qe_rxp, &rx->rxp_q) {
V_113 = (struct V_112 * ) V_196 ;
F_128 ( V_35 -> V_42 , & V_113 -> V_115 . V_2 ) ;
}
F_127 ( V_35 ) ;
}
static int
F_129 ( struct V_260 * V_261 , struct V_122 * V_246 )
{
if ( ( V_261 -> V_262 == 0 ) ||
( V_261 -> V_263 == 0 ) ||
( V_261 -> V_264 == 0 ) )
return 0 ;
if ( V_246 -> V_265 == V_220 ) {
if ( ( V_261 -> V_263 < V_246 -> V_138 ) ||
( V_261 -> V_264 < V_246 -> V_138 ) )
return 0 ;
} else {
if ( ( V_261 -> V_263 < V_246 -> V_138 ) ||
( V_261 -> V_264 < ( 2 * V_246 -> V_138 ) ) )
return 0 ;
}
return 1 ;
}
static struct V_205 *
F_130 ( struct V_260 * V_261 )
{
struct V_205 * V_266 = NULL ;
struct V_90 * V_91 = NULL ;
F_49 ( & V_261 -> V_267 , & V_91 ) ;
V_261 -> V_264 -- ;
V_266 = (struct V_205 * ) V_91 ;
F_45 ( & V_266 -> V_91 ) ;
return V_266 ;
}
static void
F_131 ( struct V_260 * V_261 , struct V_205 * V_266 )
{
F_45 ( & V_266 -> V_91 ) ;
F_42 ( & V_266 -> V_91 , & V_261 -> V_267 ) ;
V_261 -> V_264 ++ ;
}
static struct V_112 *
F_132 ( struct V_260 * V_261 )
{
struct V_90 * V_91 = NULL ;
struct V_112 * V_113 = NULL ;
F_49 ( & V_261 -> V_268 , & V_91 ) ;
V_261 -> V_263 -- ;
V_113 = (struct V_112 * ) V_91 ;
F_45 ( & V_113 -> V_91 ) ;
return V_113 ;
}
static void
F_133 ( struct V_260 * V_261 , struct V_112 * V_113 )
{
F_45 ( & V_113 -> V_91 ) ;
F_42 ( & V_113 -> V_91 , & V_261 -> V_268 ) ;
V_261 -> V_263 ++ ;
}
static struct V_111 *
F_134 ( struct V_260 * V_261 , enum V_269 type )
{
struct V_90 * V_91 = NULL ;
struct V_111 * V_35 = NULL ;
if ( type == V_198 ) {
F_49 ( & V_261 -> V_270 , & V_91 ) ;
} else
F_135 ( & V_261 -> V_270 , & V_91 ) ;
V_261 -> V_262 -- ;
V_35 = (struct V_111 * ) V_91 ;
F_45 ( & V_35 -> V_91 ) ;
F_42 ( & V_35 -> V_91 , & V_261 -> V_271 ) ;
V_35 -> type = type ;
return V_35 ;
}
static void
F_136 ( struct V_260 * V_261 , struct V_111 * V_35 )
{
struct V_90 * V_272 = NULL ;
struct V_90 * V_91 ;
F_45 ( & V_35 -> V_91 ) ;
F_37 (qe, &rx_mod->rx_free_q) {
if ( ( (struct V_111 * ) V_91 ) -> V_36 < V_35 -> V_36 )
V_272 = V_91 ;
else
break;
}
if ( V_272 == NULL ) {
F_137 ( & V_261 -> V_270 , & V_35 -> V_91 ) ;
} else if ( F_122 ( V_272 ) == & V_261 -> V_270 ) {
F_42 ( & V_35 -> V_91 , & V_261 -> V_270 ) ;
} else {
F_122 ( & V_35 -> V_91 ) = F_122 ( V_272 ) ;
F_138 ( & V_35 -> V_91 ) = V_272 ;
F_122 ( V_272 ) = & V_35 -> V_91 ;
F_138 ( F_122 ( & V_35 -> V_91 ) ) = & V_35 -> V_91 ;
}
V_261 -> V_262 ++ ;
}
static void
F_139 ( struct V_112 * V_113 , struct V_205 * V_206 ,
struct V_205 * V_207 )
{
switch ( V_113 -> type ) {
case V_220 :
V_113 -> V_266 . V_273 . V_274 = V_206 ;
V_113 -> V_266 . V_273 . V_275 = NULL ;
break;
case V_212 :
V_113 -> V_266 . V_276 . V_277 = V_206 ;
V_113 -> V_266 . V_276 . V_278 = V_207 ;
break;
case V_213 :
V_113 -> V_266 . V_250 . V_279 = V_206 ;
V_113 -> V_266 . V_250 . V_280 = V_207 ;
break;
default:
break;
}
}
static void
F_140 ( struct V_205 * V_266 ,
struct V_112 * V_113 ,
V_6 V_281 ,
V_6 V_282 ,
struct V_283 * V_284 ,
struct V_283 * V_285 ,
struct V_283 * V_286 )
{
T_1 * V_137 ;
T_3 V_287 ;
struct V_288 V_289 ;
int V_60 ;
V_266 -> V_217 . V_290 . V_227 = V_284 -> V_287 . V_227 ;
V_266 -> V_217 . V_290 . V_229 = V_284 -> V_287 . V_229 ;
V_266 -> V_217 . V_291 = V_284 -> V_137 ;
V_266 -> V_217 . V_281 = V_281 ;
V_266 -> V_217 . V_282 = V_282 ;
V_266 -> V_292 -> V_293 = ( void * * ) V_285 -> V_137 ;
V_266 -> V_292 -> V_294 = V_286 -> V_137 ;
V_137 = V_286 -> V_137 ;
F_141 ( & V_286 -> V_287 , V_287 ) ;
for ( V_60 = 0 ; V_60 < V_266 -> V_217 . V_281 ; V_60 ++ ) {
V_266 -> V_292 -> V_293 [ V_60 ] = V_137 ;
V_137 += V_295 ;
F_142 ( V_287 , & V_289 ) ;
( (struct V_288 * ) V_266 -> V_217 . V_291 ) [ V_60 ] . V_227 =
V_289 . V_227 ;
( (struct V_288 * ) V_266 -> V_217 . V_291 ) [ V_60 ] . V_229 =
V_289 . V_229 ;
V_287 += V_295 ;
}
}
static void
F_143 ( struct V_112 * V_113 ,
V_6 V_281 ,
V_6 V_282 ,
struct V_283 * V_284 ,
struct V_283 * V_285 ,
struct V_283 * V_286 )
{
T_1 * V_137 ;
T_3 V_287 ;
struct V_288 V_289 ;
int V_60 ;
V_113 -> V_115 . V_217 . V_290 . V_227 = V_284 -> V_287 . V_227 ;
V_113 -> V_115 . V_217 . V_290 . V_229 = V_284 -> V_287 . V_229 ;
V_113 -> V_115 . V_217 . V_291 = V_284 -> V_137 ;
V_113 -> V_115 . V_217 . V_281 = V_281 ;
V_113 -> V_115 . V_217 . V_282 = V_282 ;
V_113 -> V_115 . V_116 -> V_293 = ( void * * ) V_285 -> V_137 ;
V_113 -> V_115 . V_116 -> V_294 = V_286 -> V_137 ;
V_137 = V_286 -> V_137 ;
F_141 ( & V_286 -> V_287 , V_287 ) ;
for ( V_60 = 0 ; V_60 < V_113 -> V_115 . V_217 . V_281 ; V_60 ++ ) {
V_113 -> V_115 . V_116 -> V_293 [ V_60 ] = V_137 ;
V_137 += V_295 ;
F_142 ( V_287 , & V_289 ) ;
( (struct V_288 * ) V_113 -> V_115 . V_217 . V_291 ) [ V_60 ] . V_227 =
V_289 . V_227 ;
( (struct V_288 * ) V_113 -> V_115 . V_217 . V_291 ) [ V_60 ] . V_229 =
V_289 . V_229 ;
V_287 += V_295 ;
}
}
static void
F_144 ( void * V_296 , struct V_111 * V_35 )
{
struct V_260 * V_261 = (struct V_260 * ) V_296 ;
F_145 ( & V_261 -> V_297 ) ;
}
static void
F_146 ( void * V_296 )
{
struct V_260 * V_261 = (struct V_260 * ) V_296 ;
if ( V_261 -> V_154 )
V_261 -> V_154 ( & V_261 -> V_42 -> V_222 ) ;
V_261 -> V_154 = NULL ;
}
static void
F_147 ( struct V_111 * V_35 )
{
V_35 -> V_298 |= V_299 ;
if ( V_35 -> V_298 & V_300 )
F_65 ( V_35 , V_185 ) ;
}
static void
F_148 ( struct V_111 * V_35 )
{
V_35 -> V_298 &= ~ V_299 ;
if ( V_35 -> V_301 == ( V_302 ) F_102 )
F_144 ( & V_35 -> V_42 -> V_261 , V_35 ) ;
else {
V_35 -> V_154 = F_144 ;
V_35 -> V_155 = & V_35 -> V_42 -> V_261 ;
F_65 ( V_35 , V_187 ) ;
}
}
static void
F_149 ( struct V_111 * V_35 )
{
V_35 -> V_298 &= ~ V_299 ;
F_65 ( V_35 , V_188 ) ;
}
void
F_150 ( struct V_260 * V_261 , enum V_269 type )
{
struct V_111 * V_35 ;
struct V_90 * V_91 ;
V_261 -> V_12 |= V_303 ;
if ( type == V_304 )
V_261 -> V_12 |= V_305 ;
F_37 (qe, &rx_mod->rx_active_q) {
V_35 = (struct V_111 * ) V_91 ;
if ( V_35 -> type == type )
F_147 ( V_35 ) ;
}
}
void
F_151 ( struct V_260 * V_261 , enum V_269 type )
{
struct V_111 * V_35 ;
struct V_90 * V_91 ;
V_261 -> V_12 &= ~ V_303 ;
V_261 -> V_12 &= ~ V_305 ;
V_261 -> V_154 = V_306 ;
F_152 ( & V_261 -> V_297 , F_146 , V_261 ) ;
F_37 (qe, &rx_mod->rx_active_q) {
V_35 = (struct V_111 * ) V_91 ;
if ( V_35 -> type == type ) {
F_153 ( & V_261 -> V_297 ) ;
F_148 ( V_35 ) ;
}
}
F_154 ( & V_261 -> V_297 ) ;
}
void
F_155 ( struct V_260 * V_261 )
{
struct V_111 * V_35 ;
struct V_90 * V_91 ;
V_261 -> V_12 &= ~ V_303 ;
V_261 -> V_12 &= ~ V_305 ;
F_37 (qe, &rx_mod->rx_active_q) {
V_35 = (struct V_111 * ) V_91 ;
F_149 ( V_35 ) ;
}
}
void F_156 ( struct V_260 * V_261 , struct V_42 * V_42 ,
struct V_124 * V_125 )
{
int V_170 ;
struct V_111 * V_307 ;
struct V_112 * V_308 ;
struct V_205 * V_309 ;
V_261 -> V_42 = V_42 ;
V_261 -> V_12 = 0 ;
V_261 -> V_35 = (struct V_111 * )
V_125 [ V_310 ] . V_134 . V_135 . V_136 [ 0 ] . V_137 ;
V_261 -> V_113 = (struct V_112 * )
V_125 [ V_311 ] . V_134 . V_135 . V_136 [ 0 ] . V_137 ;
V_261 -> V_266 = (struct V_205 * )
V_125 [ V_312 ] . V_134 . V_135 . V_136 [ 0 ] . V_137 ;
F_69 ( & V_261 -> V_270 ) ;
V_261 -> V_262 = 0 ;
F_69 ( & V_261 -> V_267 ) ;
V_261 -> V_264 = 0 ;
F_69 ( & V_261 -> V_268 ) ;
V_261 -> V_263 = 0 ;
F_69 ( & V_261 -> V_271 ) ;
for ( V_170 = 0 ; V_170 < V_42 -> V_313 . V_314 . V_315 ; V_170 ++ ) {
V_307 = & V_261 -> V_35 [ V_170 ] ;
F_45 ( & V_307 -> V_91 ) ;
F_69 ( & V_307 -> V_211 ) ;
V_307 -> V_42 = NULL ;
V_307 -> V_36 = V_170 ;
V_307 -> V_154 = NULL ;
V_307 -> V_155 = NULL ;
F_42 ( & V_307 -> V_91 , & V_261 -> V_270 ) ;
V_261 -> V_262 ++ ;
}
for ( V_170 = 0 ; V_170 < V_42 -> V_313 . V_314 . V_315 ; V_170 ++ ) {
V_308 = & V_261 -> V_113 [ V_170 ] ;
F_45 ( & V_308 -> V_91 ) ;
F_42 ( & V_308 -> V_91 , & V_261 -> V_268 ) ;
V_261 -> V_263 ++ ;
}
for ( V_170 = 0 ; V_170 < ( V_42 -> V_313 . V_314 . V_315 * 2 ) ; V_170 ++ ) {
V_309 = & V_261 -> V_266 [ V_170 ] ;
F_45 ( & V_309 -> V_91 ) ;
F_42 ( & V_309 -> V_91 , & V_261 -> V_267 ) ;
V_261 -> V_264 ++ ;
}
}
void
F_157 ( struct V_260 * V_261 )
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
V_261 -> V_42 = NULL ;
}
void
F_158 ( struct V_111 * V_35 , struct V_118 * V_119 )
{
struct V_316 * V_317 = & V_35 -> V_31 . V_317 ;
struct V_112 * V_113 = NULL ;
struct V_205 * V_206 = NULL , * V_207 = NULL ;
struct V_90 * V_208 ;
int V_60 ;
F_159 ( & V_35 -> V_42 -> V_43 , ( T_1 * ) V_317 ,
sizeof( struct V_316 ) ) ;
V_35 -> V_318 = V_317 -> V_318 ;
for ( V_60 = 0 , V_208 = F_121 ( & V_35 -> V_211 ) ;
V_60 < V_35 -> V_138 ;
V_60 ++ , V_208 = F_122 ( V_208 ) ) {
V_113 = (struct V_112 * ) V_208 ;
F_123 ( V_113 , V_206 , V_207 ) ;
V_113 -> V_115 . V_116 -> V_319 -> V_320 =
V_35 -> V_42 -> V_321 . V_322
+ F_160 ( V_317 -> V_323 [ V_60 ] . V_319 ) ;
V_113 -> V_318 = V_317 -> V_323 [ V_60 ] . V_324 ;
V_206 -> V_292 -> V_325 =
V_35 -> V_42 -> V_321 . V_322
+ F_160 ( V_317 -> V_323 [ V_60 ] . V_326 ) ;
V_206 -> V_318 = V_317 -> V_323 [ V_60 ] . V_327 ;
if ( V_207 ) {
V_207 -> V_292 -> V_325 =
V_35 -> V_42 -> V_321 . V_322
+ F_160 ( V_317 -> V_323 [ V_60 ] . V_328 ) ;
V_207 -> V_318 = V_317 -> V_323 [ V_60 ] . V_329 ;
}
( * V_113 -> V_115 . V_116 -> V_330 ) = 0 ;
V_113 -> V_115 . V_116 -> V_331 = 0 ;
V_206 -> V_292 -> V_331 = V_206 -> V_292 -> V_332 = 0 ;
if ( V_207 )
V_207 -> V_292 -> V_331 = V_207 -> V_292 -> V_332 = 0 ;
}
F_65 ( V_35 , V_192 ) ;
}
void
F_161 ( struct V_111 * V_35 , struct V_118 * V_119 )
{
F_65 ( V_35 , V_189 ) ;
}
void
F_162 ( struct V_122 * V_214 , struct V_124 * V_125 )
{
V_6 V_333 , V_334 , V_335 ;
V_6 V_336 , V_337 , V_338 ;
struct V_339 * V_135 ;
V_6 V_340 ;
V_6 V_341 ;
V_6 V_342 ;
V_342 = V_214 -> V_343 ;
V_341 = ( ( V_214 -> V_265 == V_220 ) ? 0 : V_214 -> V_343 ) ;
V_340 = V_342 + V_341 ;
F_163 ( V_340 ) ;
V_333 = V_340 * V_344 ;
V_333 = F_164 ( V_333 , V_295 ) ;
V_336 = F_165 ( V_333 ) ;
F_163 ( V_342 ) ;
V_335 = V_342 * V_345 ;
V_335 = F_164 ( V_335 , V_295 ) ;
V_338 = F_165 ( V_335 ) ;
if ( V_220 != V_214 -> V_265 ) {
F_163 ( V_341 ) ;
V_334 = V_341 * V_345 ;
V_334 = F_164 ( V_334 , V_295 ) ;
V_337 = F_165 ( V_334 ) ;
} else
V_337 = 0 ;
V_125 [ V_346 ] . V_347 = V_348 ;
V_135 = & V_125 [ V_346 ] . V_134 . V_135 ;
V_135 -> V_349 = V_350 ;
V_135 -> V_351 = sizeof( struct V_352 ) ;
V_135 -> V_353 = V_214 -> V_138 ;
V_125 [ V_354 ] . V_347 = V_348 ;
V_135 = & V_125 [ V_354 ] . V_134 . V_135 ;
V_135 -> V_349 = V_350 ;
V_135 -> V_351 = sizeof( struct V_355 ) ;
V_135 -> V_353 = F_166 ( V_214 ) ;
V_125 [ V_356 ] . V_347 = V_348 ;
V_135 = & V_125 [ V_356 ] . V_134 . V_135 ;
V_135 -> V_349 = V_357 ;
V_135 -> V_351 = V_336 * sizeof( struct V_288 ) ;
V_135 -> V_353 = V_214 -> V_138 ;
V_125 [ V_358 ] . V_347 = V_348 ;
V_135 = & V_125 [ V_358 ] . V_134 . V_135 ;
V_135 -> V_349 = V_350 ;
V_135 -> V_351 = V_336 * sizeof( void * ) ;
V_135 -> V_353 = V_214 -> V_138 ;
V_125 [ V_359 ] . V_347 = V_348 ;
V_135 = & V_125 [ V_359 ] . V_134 . V_135 ;
V_135 -> V_349 = V_357 ;
V_135 -> V_351 = V_295 * V_336 ;
V_135 -> V_353 = V_214 -> V_138 ;
V_125 [ V_360 ] . V_347 = V_348 ;
V_135 = & V_125 [ V_360 ] . V_134 . V_135 ;
V_135 -> V_349 = V_357 ;
V_135 -> V_351 = V_338 * sizeof( struct V_288 ) ;
V_135 -> V_353 = V_214 -> V_138 ;
V_125 [ V_361 ] . V_347 = V_348 ;
V_135 = & V_125 [ V_361 ] . V_134 . V_135 ;
V_135 -> V_349 = V_350 ;
V_135 -> V_351 = V_338 * sizeof( void * ) ;
V_135 -> V_353 = V_214 -> V_138 ;
V_125 [ V_362 ] . V_347 = V_348 ;
V_135 = & V_125 [ V_362 ] . V_134 . V_135 ;
V_135 -> V_349 = V_357 ;
V_135 -> V_351 = V_295 * V_338 ;
V_135 -> V_353 = V_214 -> V_138 ;
V_125 [ V_363 ] . V_347 = V_348 ;
V_135 = & V_125 [ V_363 ] . V_134 . V_135 ;
V_135 -> V_349 = V_357 ;
V_135 -> V_351 = V_337 * sizeof( struct V_288 ) ;
V_135 -> V_353 = ( V_337 ? V_214 -> V_138 : 0 ) ;
V_125 [ V_364 ] . V_347 = V_348 ;
V_135 = & V_125 [ V_364 ] . V_134 . V_135 ;
V_135 -> V_349 = V_350 ;
V_135 -> V_351 = V_337 * sizeof( void * ) ;
V_135 -> V_353 = ( V_337 ? V_214 -> V_138 : 0 ) ;
V_125 [ V_365 ] . V_347 = V_348 ;
V_135 = & V_125 [ V_365 ] . V_134 . V_135 ;
V_135 -> V_349 = V_357 ;
V_135 -> V_351 = V_295 * V_337 ;
V_135 -> V_353 = ( V_337 ? V_214 -> V_138 : 0 ) ;
V_125 [ V_366 ] . V_347 = V_348 ;
V_135 = & V_125 [ V_366 ] . V_134 . V_135 ;
V_135 -> V_349 = V_357 ;
V_135 -> V_351 = V_367 ;
V_135 -> V_353 = V_214 -> V_138 ;
V_125 [ V_133 ] . V_347 = V_348 ;
V_135 = & V_125 [ V_133 ] . V_134 . V_135 ;
V_135 -> V_349 = V_350 ;
V_135 -> V_351 = V_368 ;
V_135 -> V_353 = 1 ;
V_125 [ V_369 ] . V_347 = V_370 ;
V_125 [ V_369 ] . V_134 . V_371 . V_239 = V_240 ;
V_125 [ V_369 ] . V_134 . V_371 . V_353 = V_214 -> V_138 ;
}
struct V_111 *
F_167 ( struct V_42 * V_42 , struct V_158 * V_158 ,
struct V_122 * V_246 ,
const struct V_372 * V_373 ,
struct V_124 * V_125 ,
void * V_374 )
{
struct V_260 * V_261 = & V_42 -> V_261 ;
struct V_111 * V_35 ;
struct V_112 * V_113 ;
struct V_205 * V_206 ;
struct V_205 * V_207 ;
struct V_375 * V_371 ;
V_6 V_281 ;
struct V_283 * V_376 ;
struct V_283 * V_377 ;
struct V_283 * V_378 ;
struct V_283 * V_379 ;
struct V_283 * V_380 ;
struct V_283 * V_381 ;
struct V_283 * V_382 ;
struct V_283 * V_383 ;
struct V_283 * V_384 ;
struct V_283 * V_385 ;
struct V_283 * V_386 ;
struct V_283 * V_387 ;
int V_60 ;
int V_338 , V_337 , V_388 ;
if ( ! F_129 ( V_261 , V_246 ) )
return NULL ;
V_371 = & V_125 [ V_369 ] . V_134 . V_371 ;
V_376 = & V_125 [ V_346 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_377 = & V_125 [ V_354 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_378 = & V_125 [ V_389 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_379 = & V_125 [ V_356 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_380 = & V_125 [ V_358 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_381 = & V_125 [ V_359 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_382 = & V_125 [ V_363 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_383 = & V_125 [ V_360 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_384 = & V_125 [ V_364 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_385 = & V_125 [ V_361 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_386 = & V_125 [ V_365 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_387 = & V_125 [ V_362 ] . V_134 . V_135 . V_136 [ 0 ] ;
V_281 = V_125 [ V_359 ] . V_134 . V_135 . V_351 /
V_295 ;
V_338 = V_125 [ V_362 ] . V_134 . V_135 . V_351 /
V_295 ;
V_337 = V_125 [ V_365 ] . V_134 . V_135 . V_351 /
V_295 ;
V_35 = F_134 ( V_261 , V_246 -> V_390 ) ;
V_35 -> V_42 = V_42 ;
V_35 -> V_298 = 0 ;
F_69 ( & V_35 -> V_211 ) ;
V_35 -> V_154 = NULL ;
V_35 -> V_155 = NULL ;
V_35 -> V_374 = V_374 ;
V_35 -> V_391 = V_373 -> V_391 ;
V_35 -> V_392 = V_373 -> V_392 ;
V_35 -> V_393 = V_373 -> V_393 ;
V_35 -> V_394 = V_373 -> V_394 ;
V_35 -> V_395 = V_373 -> V_395 ;
V_35 -> V_191 = V_373 -> V_191 ;
V_35 -> V_195 = V_373 -> V_195 ;
if ( V_35 -> V_42 -> V_261 . V_12 & V_303 ) {
switch ( V_35 -> type ) {
case V_198 :
if ( ! ( V_35 -> V_42 -> V_261 . V_12 &
V_305 ) )
V_35 -> V_298 |= V_299 ;
break;
case V_304 :
if ( V_35 -> V_42 -> V_261 . V_12 & V_305 )
V_35 -> V_298 |= V_299 ;
break;
}
}
V_35 -> V_138 = V_246 -> V_138 ;
for ( V_60 = 0 , V_388 = 0 ; V_60 < V_35 -> V_138 ; V_60 ++ ) {
V_113 = F_132 ( V_261 ) ;
F_42 ( & V_113 -> V_91 , & V_35 -> V_211 ) ;
V_113 -> type = V_246 -> V_265 ;
V_113 -> V_35 = V_35 ;
V_113 -> V_115 . V_35 = V_35 ;
V_206 = F_130 ( V_261 ) ;
if ( V_220 == V_246 -> V_265 )
V_207 = NULL ;
else
V_207 = F_130 ( V_261 ) ;
if ( 1 == V_371 -> V_353 )
V_113 -> V_396 = V_371 -> V_397 [ 0 ] . V_396 ;
else
V_113 -> V_396 = V_371 -> V_397 [ V_60 ] . V_396 ;
V_113 -> V_115 . V_2 . V_226 . V_227 =
V_125 [ V_366 ] . V_134 . V_135 . V_136 [ V_60 ] . V_287 . V_227 ;
V_113 -> V_115 . V_2 . V_226 . V_229 =
V_125 [ V_366 ] . V_134 . V_135 . V_136 [ V_60 ] . V_287 . V_229 ;
V_113 -> V_115 . V_2 . V_398 =
V_125 [ V_366 ] . V_134 . V_135 . V_136 [ V_60 ] . V_137 ;
V_113 -> V_115 . V_2 . V_239 = V_371 -> V_239 ;
if ( V_371 -> V_239 == V_240 )
V_113 -> V_115 . V_2 . V_232 = V_113 -> V_396 ;
else
V_113 -> V_115 . V_2 . V_232 = ( 1 << V_113 -> V_396 ) ;
V_113 -> V_115 . V_2 . V_3 = V_246 -> V_3 ;
V_113 -> V_115 . V_2 . V_245 = V_399 ;
V_113 -> V_115 . V_2 . V_243 = V_400 ;
F_139 ( V_113 , V_206 , V_207 ) ;
V_206 -> V_35 = V_35 ;
V_206 -> V_113 = V_113 ;
V_206 -> V_292 = (struct V_355 * ) V_377 [ V_388 ] . V_137 ;
V_206 -> V_292 -> V_401 = ( void * ) V_378 [ V_388 ] . V_137 ;
V_388 ++ ;
V_206 -> V_292 -> V_343 = V_246 -> V_343 ;
V_206 -> V_292 -> V_266 = V_206 ;
V_206 -> V_292 -> V_158 = V_42 -> V_158 ;
V_206 -> V_292 -> V_117 = 0 ;
V_206 -> V_402 = V_206 -> V_403 = 0 ;
V_206 -> V_404 = V_206 -> V_405 = 0 ;
F_140 ( V_206 , V_113 , V_338 , V_295 ,
& V_383 [ V_60 ] , & V_385 [ V_60 ] , & V_387 [ V_60 ] ) ;
if ( V_35 -> V_391 )
V_35 -> V_391 ( V_158 , V_206 -> V_292 ) ;
if ( V_207 ) {
V_207 -> V_35 = V_35 ;
V_207 -> V_113 = V_113 ;
V_207 -> V_292 = (struct V_355 * ) V_377 [ V_388 ] . V_137 ;
V_207 -> V_292 -> V_401 = ( void * ) V_378 [ V_388 ] . V_137 ;
V_388 ++ ;
V_207 -> V_292 -> V_343 = V_246 -> V_343 ;
V_207 -> V_292 -> V_266 = V_207 ;
V_207 -> V_292 -> V_158 = V_42 -> V_158 ;
V_207 -> V_292 -> V_117 = 1 ;
V_207 -> V_219 = ( V_246 -> V_265 == V_213 ) ?
V_246 -> V_406 . V_254
: V_246 -> V_407 ;
V_207 -> V_402 = V_207 -> V_403 = 0 ;
V_207 -> V_404 = V_207 -> V_405 = 0 ;
F_140 ( V_207 , V_113 , V_337 , V_295 ,
& V_382 [ V_60 ] , & V_384 [ V_60 ] ,
& V_386 [ V_60 ] ) ;
if ( V_35 -> V_391 )
V_35 -> V_391 ( V_158 , V_207 -> V_292 ) ;
}
V_113 -> V_115 . V_116 = (struct V_352 * ) V_376 [ V_60 ] . V_137 ;
V_113 -> V_115 . V_116 -> V_343 = V_246 -> V_343 +
( ( V_246 -> V_265 == V_220 ) ?
0 : V_246 -> V_343 ) ;
V_113 -> V_115 . V_116 -> V_115 = & V_113 -> V_115 ;
V_113 -> V_115 . V_116 -> V_292 [ 0 ] = V_206 -> V_292 ;
V_206 -> V_292 -> V_116 = V_113 -> V_115 . V_116 ;
if ( V_207 ) {
V_113 -> V_115 . V_116 -> V_292 [ 1 ] = V_207 -> V_292 ;
V_207 -> V_292 -> V_116 = V_113 -> V_115 . V_116 ;
}
V_113 -> V_115 . V_116 -> V_330 =
( V_6 * ) V_113 -> V_115 . V_2 . V_398 ;
V_113 -> V_115 . V_116 -> V_319 = & V_113 -> V_115 . V_2 . V_4 ;
V_113 -> V_115 . V_116 -> V_239 = V_113 -> V_115 . V_2 . V_239 ;
V_113 -> V_115 . V_116 -> V_232 = V_113 -> V_115 . V_2 . V_232 ;
V_113 -> V_115 . V_116 -> V_408 =
V_113 -> V_115 . V_2 . V_3 ;
V_113 -> V_115 . V_116 -> V_409 . V_410 = 0 ;
V_113 -> V_115 . V_116 -> V_409 . V_411 = 0 ;
V_113 -> V_115 . V_116 -> V_158 = V_42 -> V_158 ;
V_113 -> V_115 . V_116 -> V_117 = V_60 ;
F_143 ( V_113 , V_281 , V_295 ,
& V_379 [ V_60 ] , & V_380 [ V_60 ] , & V_381 [ V_60 ] ) ;
if ( V_35 -> V_393 )
V_35 -> V_393 ( V_158 , V_113 -> V_115 . V_116 ) ;
}
V_35 -> V_251 = V_246 -> V_406 ;
F_68 ( & V_35 -> V_8 , V_35 , V_246 , V_125 ) ;
F_6 ( V_35 , F_102 ) ;
V_261 -> V_412 |= ( 1 << V_35 -> V_36 ) ;
return V_35 ;
}
void
F_168 ( struct V_111 * V_35 )
{
struct V_260 * V_261 = & V_35 -> V_42 -> V_261 ;
struct V_205 * V_206 = NULL ;
struct V_205 * V_207 = NULL ;
struct V_112 * V_113 ;
struct V_90 * V_91 ;
F_70 ( & V_35 -> V_8 ) ;
while ( ! F_48 ( & V_35 -> V_211 ) ) {
F_49 ( & V_35 -> V_211 , & V_113 ) ;
F_123 ( V_113 , V_206 , V_207 ) ;
if ( V_35 -> V_392 )
V_35 -> V_392 ( V_35 -> V_42 -> V_158 , V_206 -> V_292 ) ;
V_206 -> V_292 = NULL ;
V_206 -> V_113 = NULL ;
V_206 -> V_35 = NULL ;
F_131 ( V_261 , V_206 ) ;
if ( V_207 ) {
if ( V_35 -> V_392 )
V_35 -> V_392 ( V_35 -> V_42 -> V_158 , V_207 -> V_292 ) ;
V_207 -> V_292 = NULL ;
V_207 -> V_113 = NULL ;
V_207 -> V_35 = NULL ;
F_131 ( V_261 , V_207 ) ;
}
V_113 -> V_266 . V_276 . V_277 = NULL ;
V_113 -> V_266 . V_276 . V_278 = NULL ;
if ( V_35 -> V_394 )
V_35 -> V_394 ( V_35 -> V_42 -> V_158 , V_113 -> V_115 . V_116 ) ;
V_113 -> V_115 . V_116 = NULL ;
V_113 -> V_35 = NULL ;
F_133 ( V_261 , V_113 ) ;
}
F_37 (qe, &rx_mod->rx_active_q) {
if ( V_91 == & V_35 -> V_91 ) {
F_44 ( & V_35 -> V_91 ) ;
F_45 ( & V_35 -> V_91 ) ;
break;
}
}
V_261 -> V_412 &= ~ ( 1 << V_35 -> V_36 ) ;
V_35 -> V_42 = NULL ;
V_35 -> V_374 = NULL ;
F_136 ( V_261 , V_35 ) ;
}
void
F_169 ( struct V_111 * V_35 )
{
if ( V_35 -> V_301 != ( V_413 ) F_102 )
return;
V_35 -> V_298 |= V_300 ;
if ( V_35 -> V_298 & V_299 )
F_65 ( V_35 , V_185 ) ;
}
void
F_170 ( struct V_111 * V_35 , enum V_98 type ,
void (* F_78)( void * , struct V_111 * ) )
{
if ( type == V_110 ) {
(* F_78)( V_35 -> V_42 -> V_158 , V_35 ) ;
} else {
V_35 -> V_154 = F_78 ;
V_35 -> V_155 = V_35 -> V_42 -> V_158 ;
V_35 -> V_298 &= ~ V_300 ;
F_65 ( V_35 , V_187 ) ;
}
}
void
F_171 ( struct V_111 * V_35 )
{
F_65 ( V_35 , V_201 ) ;
}
enum V_156
F_172 ( struct V_111 * V_35 , enum V_414 V_415 ,
enum V_414 V_416 ,
void (* F_78)( struct V_158 * , struct V_111 * ) )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
int V_417 = 0 ;
if ( F_86 ( V_415 , V_416 ) ) {
if ( ( V_35 -> V_42 -> V_146 != V_147 ) &&
( V_35 -> V_42 -> V_146 != V_8 -> V_35 -> V_36 ) )
goto V_168;
if ( V_35 -> V_42 -> V_148 != V_147 )
goto V_168;
if ( F_173 ( V_415 , V_416 ) )
goto V_168;
}
if ( F_173 ( V_415 , V_416 ) ) {
if ( ( V_35 -> V_42 -> V_148 != V_147 ) &&
( V_35 -> V_42 -> V_148 != V_8 -> V_35 -> V_36 ) ) {
goto V_168;
}
if ( V_35 -> V_42 -> V_146 != V_147 )
goto V_168;
}
if ( F_86 ( V_415 , V_416 ) ) {
if ( F_94 ( V_8 ) )
V_417 = 1 ;
} else if ( F_88 ( V_415 , V_416 ) ) {
if ( F_95 ( V_8 ) )
V_417 = 1 ;
}
if ( F_90 ( V_415 , V_416 ) ) {
if ( F_97 ( V_8 ) )
V_417 = 1 ;
} else if ( F_92 ( V_415 , V_416 ) ) {
if ( F_98 ( V_8 ) )
V_417 = 1 ;
}
if ( V_417 ) {
V_8 -> V_161 = F_78 ;
V_8 -> V_162 = V_35 -> V_42 -> V_158 ;
F_65 ( V_8 , V_18 ) ;
} else if ( F_78 )
(* F_78)( V_35 -> V_42 -> V_158 , V_35 ) ;
return V_163 ;
V_168:
return V_418 ;
}
void
F_174 ( struct V_111 * V_35 )
{
struct V_7 * V_8 = & V_35 -> V_8 ;
if ( V_8 -> V_64 == V_140 ) {
V_8 -> V_64 = V_65 ;
V_8 -> V_105 = ( T_1 ) V_142 ;
F_65 ( V_8 , V_18 ) ;
}
}
void
F_175 ( struct V_111 * V_35 , int V_3 )
{
struct V_112 * V_113 ;
struct V_90 * V_91 ;
F_37 (qe, &rx->rxp_q) {
V_113 = (struct V_112 * ) V_91 ;
V_113 -> V_115 . V_116 -> V_408 = V_3 ;
F_1 ( & V_113 -> V_115 . V_2 , V_3 ) ;
}
}
void
F_176 ( struct V_42 * V_42 , const V_6 V_396 [] [ V_419 ] )
{
int V_60 , V_61 ;
for ( V_60 = 0 ; V_60 < V_420 ; V_60 ++ )
for ( V_61 = 0 ; V_61 < V_419 ; V_61 ++ )
V_42 -> V_261 . V_421 [ V_60 ] [ V_61 ] = V_396 [ V_60 ] [ V_61 ] ;
}
void
F_177 ( struct V_352 * V_116 )
{
struct V_42 * V_42 = V_116 -> V_115 -> V_35 -> V_42 ;
V_6 V_422 , V_423 ;
V_6 V_424 , V_425 , V_426 ;
T_1 V_3 ;
if ( ( V_116 -> V_409 . V_410 == 0 ) &&
( V_116 -> V_409 . V_411 == 0 ) )
return;
V_425 = V_116 -> V_409 . V_410 ;
V_426 = V_116 -> V_409 . V_411 ;
V_424 = V_425 + V_426 ;
if ( V_424 < V_427 )
V_422 = V_428 ;
else if ( V_424 < V_429 )
V_422 = V_430 ;
else if ( V_424 < V_431 )
V_422 = V_432 ;
else if ( V_424 < V_433 )
V_422 = V_434 ;
else if ( V_424 < V_435 )
V_422 = V_436 ;
else if ( V_424 < V_437 )
V_422 = V_438 ;
else if ( V_424 < V_439 )
V_422 = V_440 ;
else
V_422 = V_441 ;
if ( V_425 > ( V_426 << 1 ) )
V_423 = 0 ;
else
V_423 = 1 ;
V_116 -> V_409 . V_410 = 0 ;
V_116 -> V_409 . V_411 = 0 ;
V_3 = V_42 -> V_261 . V_421 [ V_422 ] [ V_423 ] ;
V_116 -> V_408 = V_3 ;
F_1 ( & V_116 -> V_115 -> V_2 , V_3 ) ;
}
static void
F_178 ( struct V_442 * V_443 )
{
F_179 ( V_443 ) ;
}
static void
F_180 ( struct V_442 * V_443 , enum V_444 V_10 )
{
switch ( V_10 ) {
case V_445 :
F_6 ( V_443 , V_446 ) ;
break;
case V_447 :
F_179 ( V_443 ) ;
break;
case V_448 :
break;
case V_449 :
F_181 ( V_443 ) ;
break;
case V_450 :
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_182 ( struct V_442 * V_443 )
{
F_183 ( V_443 ) ;
}
static void
V_446 ( struct V_442 * V_443 , enum V_444 V_10 )
{
switch ( V_10 ) {
case V_447 :
V_443 -> V_12 &= ~ ( V_451 | V_452 ) ;
F_6 ( V_443 , V_453 ) ;
break;
case V_448 :
V_443 -> V_12 &= ~ ( V_451 | V_452 ) ;
F_6 ( V_443 , F_180 ) ;
break;
case V_454 :
if ( V_443 -> V_12 & ( V_451 | V_452 ) ) {
V_443 -> V_12 &= ~ ( V_451 |
V_452 ) ;
F_6 ( V_443 , V_455 ) ;
} else
F_6 ( V_443 , V_456 ) ;
break;
case V_449 :
V_443 -> V_12 |= V_451 ;
break;
case V_450 :
V_443 -> V_12 |= V_452 ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_184 ( struct V_442 * V_443 )
{
struct V_457 * V_458 ;
struct V_90 * V_91 ;
int V_197 = ( V_443 -> type == V_459 ) ;
F_37 (qe, &tx->txq_q) {
V_458 = (struct V_457 * ) V_91 ;
V_458 -> V_460 -> V_461 = V_458 -> V_461 ;
F_114 ( V_443 -> V_42 , & V_458 -> V_2 , V_197 ) ;
}
V_443 -> V_462 ( V_443 -> V_42 -> V_158 , V_443 ) ;
}
static void
V_456 ( struct V_442 * V_443 , enum V_444 V_10 )
{
switch ( V_10 ) {
case V_447 :
F_6 ( V_443 , V_453 ) ;
V_443 -> V_463 ( V_443 -> V_42 -> V_158 , V_443 ) ;
F_185 ( V_443 ) ;
break;
case V_448 :
F_6 ( V_443 , V_464 ) ;
V_443 -> V_463 ( V_443 -> V_42 -> V_158 , V_443 ) ;
V_443 -> V_465 ( V_443 -> V_42 -> V_158 , V_443 ) ;
break;
case V_449 :
case V_450 :
F_6 ( V_443 , V_455 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_186 ( struct V_442 * V_443 )
{
}
static void
V_453 ( struct V_442 * V_443 , enum V_444 V_10 )
{
switch ( V_10 ) {
case V_448 :
case V_466 :
F_6 ( V_443 , V_467 ) ;
V_443 -> V_465 ( V_443 -> V_42 -> V_158 , V_443 ) ;
break;
case V_454 :
F_185 ( V_443 ) ;
break;
case V_449 :
case V_450 :
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_187 ( struct V_442 * V_443 )
{
}
static void
V_467 ( struct V_442 * V_443 , enum V_444 V_10 )
{
switch ( V_10 ) {
case V_448 :
case V_449 :
case V_450 :
break;
case V_468 :
F_6 ( V_443 , F_180 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_188 ( struct V_442 * V_443 )
{
V_443 -> V_463 ( V_443 -> V_42 -> V_158 , V_443 ) ;
F_185 ( V_443 ) ;
}
static void
V_455 ( struct V_442 * V_443 , enum V_444 V_10 )
{
switch ( V_10 ) {
case V_447 :
F_6 ( V_443 , V_453 ) ;
break;
case V_448 :
F_6 ( V_443 , V_464 ) ;
F_181 ( V_443 ) ;
V_443 -> V_465 ( V_443 -> V_42 -> V_158 , V_443 ) ;
break;
case V_466 :
F_6 ( V_443 , V_469 ) ;
break;
case V_449 :
case V_450 :
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_189 ( struct V_442 * V_443 )
{
F_181 ( V_443 ) ;
V_443 -> V_465 ( V_443 -> V_42 -> V_158 , V_443 ) ;
}
static void
V_469 ( struct V_442 * V_443 , enum V_444 V_10 )
{
switch ( V_10 ) {
case V_447 :
F_6 ( V_443 , V_467 ) ;
break;
case V_448 :
F_6 ( V_443 , V_464 ) ;
break;
case V_449 :
case V_450 :
break;
case V_468 :
F_6 ( V_443 , V_446 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_190 ( struct V_442 * V_443 )
{
}
static void
V_464 ( struct V_442 * V_443 , enum V_444 V_10 )
{
switch ( V_10 ) {
case V_445 :
F_6 ( V_443 , V_470 ) ;
break;
case V_447 :
F_6 ( V_443 , V_467 ) ;
break;
case V_448 :
break;
case V_468 :
F_6 ( V_443 , F_180 ) ;
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_191 ( struct V_442 * V_443 )
{
}
static void
V_470 ( struct V_442 * V_443 , enum V_444 V_10 )
{
switch ( V_10 ) {
case V_447 :
F_6 ( V_443 , V_467 ) ;
break;
case V_448 :
F_6 ( V_443 , V_464 ) ;
break;
case V_468 :
F_6 ( V_443 , V_446 ) ;
break;
case V_450 :
break;
default:
F_11 ( V_10 ) ;
}
}
static void
F_183 ( struct V_442 * V_443 )
{
struct V_471 * V_204 = & V_443 -> V_31 . V_204 ;
struct V_457 * V_458 = NULL ;
struct V_90 * V_91 ;
int V_60 ;
F_21 ( V_204 -> V_33 , V_34 ,
V_472 , 0 , V_443 -> V_36 ) ;
V_204 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_471 ) ) ) ;
V_204 -> V_473 = V_443 -> V_474 ;
for ( V_60 = 0 , V_91 = F_121 ( & V_443 -> V_475 ) ;
V_60 < V_443 -> V_474 ;
V_60 ++ , V_91 = F_122 ( V_91 ) ) {
V_458 = (struct V_457 * ) V_91 ;
F_124 ( & V_204 -> V_214 [ V_60 ] . V_216 . V_216 , & V_458 -> V_217 ) ;
V_204 -> V_214 [ V_60 ] . V_216 . V_461 = V_458 -> V_461 ;
V_204 -> V_214 [ V_60 ] . V_2 . V_223 . V_224 . V_225 =
V_458 -> V_2 . V_226 . V_227 ;
V_204 -> V_214 [ V_60 ] . V_2 . V_223 . V_224 . V_228 =
V_458 -> V_2 . V_226 . V_229 ;
V_204 -> V_214 [ V_60 ] . V_2 . V_230 . V_231 =
F_22 ( ( T_2 ) V_458 -> V_2 . V_232 ) ;
}
V_204 -> V_233 . V_234 = V_65 ;
V_204 -> V_233 . V_235 = V_65 ;
V_204 -> V_233 . V_236 = V_140 ;
V_204 -> V_233 . V_237 = V_65 ;
V_204 -> V_233 . V_238 = ( V_458 -> V_2 . V_239 == V_240 )
? V_65 : V_140 ;
V_204 -> V_233 . V_241 =
F_31 ( ( V_6 ) V_458 -> V_2 . V_3 ) ;
V_204 -> V_233 . V_242 =
F_31 ( ( V_6 ) V_458 -> V_2 . V_243 ) ;
V_204 -> V_233 . V_244 = ( T_1 ) V_458 -> V_2 . V_245 ;
V_204 -> V_476 . V_477 = V_478 ;
V_204 -> V_476 . V_169 = F_22 ( ( T_2 ) V_443 -> V_479 ) ;
V_204 -> V_476 . V_480 = V_140 ;
V_204 -> V_476 . V_481 = V_140 ;
F_24 ( & V_443 -> V_41 , NULL , NULL ,
sizeof( struct V_471 ) , & V_204 -> V_33 ) ;
F_25 ( & V_443 -> V_42 -> V_43 , & V_443 -> V_41 ) ;
}
static void
F_192 ( struct V_442 * V_443 )
{
struct V_258 * V_30 = & V_443 -> V_31 . V_30 ;
F_21 ( V_30 -> V_33 , V_34 ,
V_482 , 0 , V_443 -> V_36 ) ;
V_30 -> V_33 . V_37 = F_22 (
F_23 ( sizeof( struct V_258 ) ) ) ;
F_24 ( & V_443 -> V_41 , NULL , NULL , sizeof( struct V_258 ) ,
& V_30 -> V_33 ) ;
F_25 ( & V_443 -> V_42 -> V_43 , & V_443 -> V_41 ) ;
}
static void
F_185 ( struct V_442 * V_443 )
{
struct V_457 * V_458 ;
struct V_90 * V_91 ;
F_37 (qe, &tx->txq_q) {
V_458 = (struct V_457 * ) V_91 ;
F_128 ( V_443 -> V_42 , & V_458 -> V_2 ) ;
}
F_192 ( V_443 ) ;
}
static void
F_193 ( struct V_457 * V_458 , int V_281 , int V_282 ,
struct V_283 * V_284 ,
struct V_283 * V_285 ,
struct V_283 * V_286 )
{
T_1 * V_137 ;
T_3 V_287 ;
struct V_288 V_289 ;
int V_60 ;
V_458 -> V_217 . V_290 . V_227 = V_284 -> V_287 . V_227 ;
V_458 -> V_217 . V_290 . V_229 = V_284 -> V_287 . V_229 ;
V_458 -> V_217 . V_291 = V_284 -> V_137 ;
V_458 -> V_217 . V_281 = V_281 ;
V_458 -> V_217 . V_282 = V_282 ;
V_458 -> V_460 -> V_293 = ( void * * ) V_285 -> V_137 ;
V_458 -> V_460 -> V_294 = V_286 -> V_137 ;
V_137 = V_286 -> V_137 ;
F_141 ( & V_286 -> V_287 , V_287 ) ;
for ( V_60 = 0 ; V_60 < V_281 ; V_60 ++ ) {
V_458 -> V_460 -> V_293 [ V_60 ] = V_137 ;
V_137 += V_295 ;
F_142 ( V_287 , & V_289 ) ;
( (struct V_288 * ) V_458 -> V_217 . V_291 ) [ V_60 ] . V_227 =
V_289 . V_227 ;
( (struct V_288 * ) V_458 -> V_217 . V_291 ) [ V_60 ] . V_229 =
V_289 . V_229 ;
V_287 += V_295 ;
}
}
static struct V_442 *
F_194 ( struct V_483 * V_484 , enum V_485 type )
{
struct V_90 * V_91 = NULL ;
struct V_442 * V_443 = NULL ;
if ( F_48 ( & V_484 -> V_486 ) )
return NULL ;
if ( type == V_459 ) {
F_49 ( & V_484 -> V_486 , & V_91 ) ;
} else {
F_135 ( & V_484 -> V_486 , & V_91 ) ;
}
V_443 = (struct V_442 * ) V_91 ;
F_45 ( & V_443 -> V_91 ) ;
V_443 -> type = type ;
return V_443 ;
}
static void
F_195 ( struct V_442 * V_443 )
{
struct V_483 * V_484 = & V_443 -> V_42 -> V_484 ;
struct V_457 * V_458 ;
struct V_90 * V_272 ;
struct V_90 * V_91 ;
while ( ! F_48 ( & V_443 -> V_475 ) ) {
F_49 ( & V_443 -> V_475 , & V_458 ) ;
F_45 ( & V_458 -> V_91 ) ;
V_458 -> V_460 = NULL ;
V_458 -> V_443 = NULL ;
F_42 ( & V_458 -> V_91 , & V_484 -> V_487 ) ;
}
F_37 (qe, &tx_mod->tx_active_q) {
if ( V_91 == & V_443 -> V_91 ) {
F_44 ( & V_443 -> V_91 ) ;
F_45 ( & V_443 -> V_91 ) ;
break;
}
}
V_443 -> V_42 = NULL ;
V_443 -> V_374 = NULL ;
V_272 = NULL ;
F_37 (qe, &tx_mod->tx_free_q) {
if ( ( (struct V_442 * ) V_91 ) -> V_36 < V_443 -> V_36 )
V_272 = V_91 ;
else {
break;
}
}
if ( V_272 == NULL ) {
F_137 ( & V_484 -> V_486 , & V_443 -> V_91 ) ;
} else if ( F_122 ( V_272 ) == & V_484 -> V_486 ) {
F_42 ( & V_443 -> V_91 , & V_484 -> V_486 ) ;
} else {
F_122 ( & V_443 -> V_91 ) = F_122 ( V_272 ) ;
F_138 ( & V_443 -> V_91 ) = V_272 ;
F_122 ( V_272 ) = & V_443 -> V_91 ;
F_138 ( F_122 ( & V_443 -> V_91 ) ) = & V_443 -> V_91 ;
}
}
static void
F_196 ( struct V_442 * V_443 )
{
V_443 -> V_12 |= V_488 ;
if ( V_443 -> V_12 & V_489 )
F_65 ( V_443 , V_445 ) ;
}
static void
F_197 ( struct V_442 * V_443 )
{
V_443 -> V_154 = V_490 ;
V_443 -> V_155 = & V_443 -> V_42 -> V_484 ;
V_443 -> V_12 &= ~ V_488 ;
F_65 ( V_443 , V_447 ) ;
}
static void
F_198 ( struct V_442 * V_443 )
{
V_443 -> V_12 &= ~ V_488 ;
F_65 ( V_443 , V_448 ) ;
}
void
F_199 ( struct V_442 * V_443 , struct V_118 * V_119 )
{
struct V_491 * V_317 = & V_443 -> V_31 . V_317 ;
struct V_457 * V_458 = NULL ;
struct V_90 * V_91 ;
int V_60 ;
F_159 ( & V_443 -> V_42 -> V_43 , ( T_1 * ) V_317 ,
sizeof( struct V_491 ) ) ;
V_443 -> V_318 = V_317 -> V_318 ;
for ( V_60 = 0 , V_91 = F_121 ( & V_443 -> V_475 ) ;
V_60 < V_443 -> V_474 ; V_60 ++ , V_91 = F_122 ( V_91 ) ) {
V_458 = (struct V_457 * ) V_91 ;
V_458 -> V_460 -> V_319 -> V_320 =
V_443 -> V_42 -> V_321 . V_322
+ F_160 ( V_317 -> V_323 [ V_60 ] . V_319 ) ;
V_458 -> V_460 -> V_325 =
V_443 -> V_42 -> V_321 . V_322
+ F_160 ( V_317 -> V_323 [ V_60 ] . V_325 ) ;
V_458 -> V_318 = V_317 -> V_323 [ V_60 ] . V_492 ;
( * V_458 -> V_460 -> V_493 ) = 0 ;
V_458 -> V_460 -> V_331 = V_458 -> V_460 -> V_332 = 0 ;
}
F_65 ( V_443 , V_454 ) ;
}
void
F_200 ( struct V_442 * V_443 , struct V_118 * V_119 )
{
F_65 ( V_443 , V_466 ) ;
}
void
F_201 ( struct V_483 * V_484 )
{
struct V_442 * V_443 ;
struct V_90 * V_91 ;
F_37 (qe, &tx_mod->tx_active_q) {
V_443 = (struct V_442 * ) V_91 ;
F_65 ( V_443 , V_450 ) ;
}
}
void
F_202 ( int V_474 , int V_494 , struct V_124 * V_125 )
{
V_6 V_495 ;
V_6 V_281 ;
struct V_339 * V_135 ;
V_125 [ V_496 ] . V_347 = V_348 ;
V_135 = & V_125 [ V_496 ] . V_134 . V_135 ;
V_135 -> V_349 = V_350 ;
V_135 -> V_351 = sizeof( struct V_497 ) ;
V_135 -> V_353 = V_474 ;
V_495 = V_494 * V_498 ;
V_495 = F_164 ( V_495 , V_295 ) ;
V_281 = V_495 >> V_499 ;
V_125 [ V_500 ] . V_347 = V_348 ;
V_135 = & V_125 [ V_500 ] . V_134 . V_135 ;
V_135 -> V_349 = V_357 ;
V_135 -> V_351 = V_281 * sizeof( struct V_288 ) ;
V_135 -> V_353 = V_474 ;
V_125 [ V_501 ] . V_347 = V_348 ;
V_135 = & V_125 [ V_501 ] . V_134 . V_135 ;
V_135 -> V_349 = V_350 ;
V_135 -> V_351 = V_281 * sizeof( void * ) ;
V_135 -> V_353 = V_474 ;
V_125 [ V_502 ] . V_347 = V_348 ;
V_135 = & V_125 [ V_502 ] . V_134 . V_135 ;
V_135 -> V_349 = V_357 ;
V_135 -> V_351 = V_295 * V_281 ;
V_135 -> V_353 = V_474 ;
V_125 [ V_503 ] . V_347 = V_348 ;
V_135 = & V_125 [ V_503 ] . V_134 . V_135 ;
V_135 -> V_349 = V_357 ;
V_135 -> V_351 = V_367 ;
V_135 -> V_353 = V_474 ;
V_125 [ V_504 ] . V_347 = V_370 ;
V_125 [ V_504 ] . V_134 . V_371 . V_239 =
V_240 ;
V_125 [ V_504 ] . V_134 . V_371 . V_353 = V_474 ;
}
struct V_442 *
F_203 ( struct V_42 * V_42 , struct V_158 * V_158 ,
struct V_505 * V_476 ,
const struct V_506 * V_507 ,
struct V_124 * V_125 , void * V_374 )
{
struct V_375 * V_371 ;
struct V_483 * V_484 = & V_42 -> V_484 ;
struct V_442 * V_443 ;
struct V_457 * V_458 ;
struct V_90 * V_91 ;
int V_281 ;
int V_60 ;
V_371 = & V_125 [ V_504 ] . V_134 . V_371 ;
V_281 = ( V_125 [ V_502 ] . V_134 . V_135 . V_351 ) /
V_295 ;
if ( ( V_371 -> V_353 != 1 ) && ( V_371 -> V_353 != V_476 -> V_474 ) )
return NULL ;
V_443 = F_194 ( V_484 , V_476 -> V_508 ) ;
if ( ! V_443 )
return NULL ;
V_443 -> V_42 = V_42 ;
V_443 -> V_374 = V_374 ;
F_69 ( & V_443 -> V_475 ) ;
for ( V_60 = 0 ; V_60 < V_476 -> V_474 ; V_60 ++ ) {
if ( F_48 ( & V_484 -> V_487 ) )
goto V_168;
F_49 ( & V_484 -> V_487 , & V_458 ) ;
F_45 ( & V_458 -> V_91 ) ;
F_42 ( & V_458 -> V_91 , & V_443 -> V_475 ) ;
V_458 -> V_443 = V_443 ;
}
V_443 -> V_509 = V_507 -> V_509 ;
V_443 -> V_510 = V_507 -> V_510 ;
V_443 -> V_463 = V_507 -> V_463 ;
V_443 -> V_462 = V_507 -> V_462 ;
V_443 -> V_465 = V_507 -> V_465 ;
F_42 ( & V_443 -> V_91 , & V_484 -> V_511 ) ;
V_443 -> V_474 = V_476 -> V_474 ;
V_443 -> V_12 = 0 ;
if ( V_443 -> V_42 -> V_484 . V_12 & V_512 ) {
switch ( V_443 -> type ) {
case V_459 :
if ( ! ( V_443 -> V_42 -> V_484 . V_12 &
V_513 ) )
V_443 -> V_12 |= V_488 ;
break;
case V_514 :
if ( V_443 -> V_42 -> V_484 . V_12 & V_513 )
V_443 -> V_12 |= V_488 ;
break;
}
}
V_60 = 0 ;
F_37 (qe, &tx->txq_q) {
V_458 = (struct V_457 * ) V_91 ;
V_458 -> V_460 = (struct V_497 * )
V_125 [ V_496 ] . V_134 . V_135 . V_136 [ V_60 ] . V_137 ;
V_458 -> V_515 = 0 ;
V_458 -> V_516 = 0 ;
V_458 -> V_2 . V_226 . V_227 =
V_125 [ V_503 ] . V_134 . V_135 . V_136 [ V_60 ] . V_287 . V_227 ;
V_458 -> V_2 . V_226 . V_229 =
V_125 [ V_503 ] . V_134 . V_135 . V_136 [ V_60 ] . V_287 . V_229 ;
V_458 -> V_2 . V_398 =
V_125 [ V_503 ] . V_134 . V_135 . V_136 [ V_60 ] . V_137 ;
V_458 -> V_2 . V_239 = V_371 -> V_239 ;
V_458 -> V_2 . V_232 = ( V_371 -> V_353 == 1 ) ?
V_371 -> V_397 [ 0 ] . V_396 :
V_371 -> V_397 [ V_60 ] . V_396 ;
if ( V_371 -> V_239 == V_517 )
V_458 -> V_2 . V_232 = ( 1 << V_458 -> V_2 . V_232 ) ;
V_458 -> V_2 . V_3 = V_476 -> V_3 ;
V_458 -> V_2 . V_243 = V_518 ;
V_458 -> V_2 . V_245 = V_519 ;
V_458 -> V_460 -> V_343 = V_476 -> V_494 ;
V_458 -> V_460 -> V_401 = ( void * )
V_125 [ V_520 ] . V_134 . V_135 . V_136 [ V_60 ] . V_137 ;
V_458 -> V_460 -> V_493 =
( V_6 * ) V_458 -> V_2 . V_398 ;
V_458 -> V_460 -> V_319 = & V_458 -> V_2 . V_4 ;
V_458 -> V_460 -> V_239 = V_458 -> V_2 . V_239 ;
V_458 -> V_460 -> V_232 = V_458 -> V_2 . V_232 ;
V_458 -> V_460 -> V_458 = V_458 ;
V_458 -> V_460 -> V_158 = V_158 ;
V_458 -> V_460 -> V_117 = V_60 ;
F_193 ( V_458 , V_281 , V_295 ,
& V_125 [ V_500 ] . V_134 . V_135 . V_136 [ V_60 ] ,
& V_125 [ V_501 ] . V_134 . V_135 . V_136 [ V_60 ] ,
& V_125 [ V_502 ] .
V_134 . V_135 . V_136 [ V_60 ] ) ;
if ( V_443 -> V_509 )
( V_443 -> V_509 ) ( V_42 -> V_158 , V_458 -> V_460 ) ;
if ( V_476 -> V_474 == V_521 )
V_458 -> V_461 = V_458 -> V_460 -> V_117 ;
else
V_458 -> V_461 = V_484 -> V_522 ;
V_60 ++ ;
}
V_443 -> V_479 = 0 ;
F_6 ( V_443 , F_180 ) ;
V_484 -> V_412 |= ( 1 << V_443 -> V_36 ) ;
return V_443 ;
V_168:
F_195 ( V_443 ) ;
return NULL ;
}
void
F_204 ( struct V_442 * V_443 )
{
struct V_457 * V_458 ;
struct V_90 * V_91 ;
F_37 (qe, &tx->txq_q) {
V_458 = (struct V_457 * ) V_91 ;
if ( V_443 -> V_510 )
( V_443 -> V_510 ) ( V_443 -> V_42 -> V_158 , V_458 -> V_460 ) ;
}
V_443 -> V_42 -> V_484 . V_412 &= ~ ( 1 << V_443 -> V_36 ) ;
F_195 ( V_443 ) ;
}
void
F_205 ( struct V_442 * V_443 )
{
if ( V_443 -> V_301 != ( V_413 ) F_180 )
return;
V_443 -> V_12 |= V_489 ;
if ( V_443 -> V_12 & V_488 )
F_65 ( V_443 , V_445 ) ;
}
void
F_206 ( struct V_442 * V_443 , enum V_98 type ,
void (* F_78)( void * , struct V_442 * ) )
{
if ( type == V_110 ) {
(* F_78)( V_443 -> V_42 -> V_158 , V_443 ) ;
return;
}
V_443 -> V_154 = F_78 ;
V_443 -> V_155 = V_443 -> V_42 -> V_158 ;
V_443 -> V_12 &= ~ V_489 ;
F_65 ( V_443 , V_447 ) ;
}
void
F_207 ( struct V_442 * V_443 )
{
F_65 ( V_443 , V_468 ) ;
}
static void
V_490 ( void * V_296 , struct V_442 * V_443 )
{
struct V_483 * V_484 = (struct V_483 * ) V_296 ;
F_145 ( & V_484 -> V_523 ) ;
}
static void
F_208 ( void * V_296 )
{
struct V_483 * V_484 = (struct V_483 * ) V_296 ;
if ( V_484 -> V_154 )
V_484 -> V_154 ( & V_484 -> V_42 -> V_222 ) ;
V_484 -> V_154 = NULL ;
}
void
F_209 ( struct V_483 * V_484 , struct V_42 * V_42 ,
struct V_124 * V_125 )
{
int V_60 ;
V_484 -> V_42 = V_42 ;
V_484 -> V_12 = 0 ;
V_484 -> V_443 = (struct V_442 * )
V_125 [ V_524 ] . V_134 . V_135 . V_136 [ 0 ] . V_137 ;
V_484 -> V_458 = (struct V_457 * )
V_125 [ V_525 ] . V_134 . V_135 . V_136 [ 0 ] . V_137 ;
F_69 ( & V_484 -> V_486 ) ;
F_69 ( & V_484 -> V_511 ) ;
F_69 ( & V_484 -> V_487 ) ;
for ( V_60 = 0 ; V_60 < V_42 -> V_313 . V_314 . V_474 ; V_60 ++ ) {
V_484 -> V_443 [ V_60 ] . V_36 = V_60 ;
F_45 ( & V_484 -> V_443 [ V_60 ] . V_91 ) ;
F_42 ( & V_484 -> V_443 [ V_60 ] . V_91 , & V_484 -> V_486 ) ;
F_45 ( & V_484 -> V_458 [ V_60 ] . V_91 ) ;
F_42 ( & V_484 -> V_458 [ V_60 ] . V_91 , & V_484 -> V_487 ) ;
}
V_484 -> V_526 = V_527 ;
V_484 -> V_522 = 0 ;
V_484 -> V_528 = V_140 ;
V_484 -> V_529 = - 1 ;
}
void
F_210 ( struct V_483 * V_484 )
{
struct V_90 * V_91 ;
int V_60 ;
V_60 = 0 ;
F_37 (qe, &tx_mod->tx_free_q)
V_60 ++ ;
V_60 = 0 ;
F_37 (qe, &tx_mod->txq_free_q)
V_60 ++ ;
V_484 -> V_42 = NULL ;
}
void
F_211 ( struct V_483 * V_484 , enum V_485 type )
{
struct V_442 * V_443 ;
struct V_90 * V_91 ;
V_484 -> V_12 |= V_512 ;
if ( type == V_514 )
V_484 -> V_12 |= V_513 ;
F_37 (qe, &tx_mod->tx_active_q) {
V_443 = (struct V_442 * ) V_91 ;
if ( V_443 -> type == type )
F_196 ( V_443 ) ;
}
}
void
F_212 ( struct V_483 * V_484 , enum V_485 type )
{
struct V_442 * V_443 ;
struct V_90 * V_91 ;
V_484 -> V_12 &= ~ V_512 ;
V_484 -> V_12 &= ~ V_513 ;
V_484 -> V_154 = V_530 ;
F_152 ( & V_484 -> V_523 , F_208 , V_484 ) ;
F_37 (qe, &tx_mod->tx_active_q) {
V_443 = (struct V_442 * ) V_91 ;
if ( V_443 -> type == type ) {
F_153 ( & V_484 -> V_523 ) ;
F_197 ( V_443 ) ;
}
}
F_154 ( & V_484 -> V_523 ) ;
}
void
F_213 ( struct V_483 * V_484 )
{
struct V_442 * V_443 ;
struct V_90 * V_91 ;
V_484 -> V_12 &= ~ V_512 ;
V_484 -> V_12 &= ~ V_513 ;
F_37 (qe, &tx_mod->tx_active_q) {
V_443 = (struct V_442 * ) V_91 ;
F_198 ( V_443 ) ;
}
}
void
F_214 ( struct V_442 * V_443 , int V_3 )
{
struct V_457 * V_458 ;
struct V_90 * V_91 ;
F_37 (qe, &tx->txq_q) {
V_458 = (struct V_457 * ) V_91 ;
F_1 ( & V_458 -> V_2 , V_3 ) ;
}
}
