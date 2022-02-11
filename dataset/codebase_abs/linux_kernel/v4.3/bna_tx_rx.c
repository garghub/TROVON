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
F_6 ( V_8 , V_12 ) ;
break;
case V_13 :
F_4 ( V_8 ) ;
break;
case V_14 :
break;
case V_15 :
F_7 ( V_8 ) ;
break;
default:
F_8 ( V_10 ) ;
}
}
static void
F_9 ( struct V_7 * V_8 )
{
if ( ! F_10 ( V_8 ) ) {
F_6 ( V_8 , V_16 ) ;
}
}
static void
V_12 ( struct V_7 * V_8 , enum V_9 V_10 )
{
switch ( V_10 ) {
case V_13 :
F_6 ( V_8 , V_17 ) ;
break;
case V_14 :
F_11 ( V_8 ) ;
F_12 ( V_8 ) ;
F_7 ( V_8 ) ;
F_6 ( V_8 , F_5 ) ;
break;
case V_15 :
break;
case V_18 :
if ( ! F_10 ( V_8 ) ) {
F_6 ( V_8 , V_16 ) ;
}
break;
default:
F_8 ( V_10 ) ;
}
}
static void
F_13 ( struct V_7 * V_8 )
{
F_12 ( V_8 ) ;
F_7 ( V_8 ) ;
}
static void
V_16 ( struct V_7 * V_8 , enum V_9 V_10 )
{
switch ( V_10 ) {
case V_13 :
case V_14 :
F_11 ( V_8 ) ;
F_6 ( V_8 , F_5 ) ;
break;
case V_15 :
F_6 ( V_8 , V_12 ) ;
break;
default:
F_8 ( V_10 ) ;
}
}
static void
F_14 ( struct V_7 * V_8 )
{
}
static void
V_17 ( struct V_7 * V_8 , enum V_9 V_10 )
{
switch ( V_10 ) {
case V_14 :
case V_18 :
F_11 ( V_8 ) ;
F_6 ( V_8 , F_5 ) ;
break;
default:
F_8 ( V_10 ) ;
}
}
static void
F_15 ( struct V_7 * V_8 , struct V_19 * V_20 ,
enum V_21 V_22 )
{
struct V_23 * V_24 = & V_8 -> V_25 . V_26 ;
F_16 ( V_24 -> V_27 , V_28 , V_22 , 0 , V_8 -> V_29 -> V_30 ) ;
V_24 -> V_27 . V_31 = F_17 (
F_18 ( sizeof( struct V_23 ) ) ) ;
F_19 ( V_24 -> V_32 , V_20 -> V_33 ) ;
F_20 ( & V_8 -> V_34 , NULL , NULL ,
sizeof( struct V_23 ) , & V_24 -> V_27 ) ;
F_21 ( & V_8 -> V_29 -> V_35 -> V_36 , & V_8 -> V_34 ) ;
}
static void
F_22 ( struct V_7 * V_8 , struct V_19 * V_20 )
{
struct V_37 * V_24 =
& V_8 -> V_25 . V_38 ;
F_16 ( V_24 -> V_27 , V_28 , V_39 ,
0 , V_8 -> V_29 -> V_30 ) ;
V_24 -> V_27 . V_31 = F_17 (
F_18 ( sizeof( struct V_37 ) ) ) ;
F_19 ( V_24 -> V_32 , V_20 -> V_33 ) ;
F_20 ( & V_8 -> V_34 , NULL , NULL ,
sizeof( struct V_37 ) , & V_24 -> V_27 ) ;
F_21 ( & V_8 -> V_29 -> V_35 -> V_36 , & V_8 -> V_34 ) ;
}
static void
F_23 ( struct V_7 * V_8 , T_2 V_40 )
{
struct V_41 * V_24 =
& V_8 -> V_25 . V_42 ;
F_16 ( V_24 -> V_27 , V_28 , V_43 ,
0 , V_8 -> V_29 -> V_30 ) ;
V_24 -> V_27 . V_31 = F_17 (
F_18 ( sizeof( struct V_41 ) ) ) ;
V_24 -> V_40 = F_17 ( V_40 ) ;
F_20 ( & V_8 -> V_34 , NULL , NULL ,
sizeof( struct V_41 ) , & V_24 -> V_27 ) ;
F_21 ( & V_8 -> V_29 -> V_35 -> V_36 , & V_8 -> V_34 ) ;
}
static void
F_24 ( struct V_7 * V_8 , enum V_44 V_45 )
{
struct V_46 * V_24 = & V_8 -> V_25 . V_24 ;
F_16 ( V_24 -> V_27 , V_28 ,
V_47 , 0 , V_8 -> V_29 -> V_30 ) ;
V_24 -> V_27 . V_31 = F_17 (
F_18 ( sizeof( struct V_46 ) ) ) ;
V_24 -> V_48 = V_45 ;
F_20 ( & V_8 -> V_34 , NULL , NULL ,
sizeof( struct V_46 ) , & V_24 -> V_27 ) ;
F_21 ( & V_8 -> V_29 -> V_35 -> V_36 , & V_8 -> V_34 ) ;
}
static void
F_25 ( struct V_7 * V_8 , enum V_44 V_45 )
{
struct V_46 * V_24 = & V_8 -> V_25 . V_24 ;
F_16 ( V_24 -> V_27 , V_28 ,
V_49 , 0 , V_8 -> V_29 -> V_30 ) ;
V_24 -> V_27 . V_31 = F_17 (
F_18 ( sizeof( struct V_46 ) ) ) ;
V_24 -> V_48 = V_45 ;
F_20 ( & V_8 -> V_34 , NULL , NULL ,
sizeof( struct V_46 ) , & V_24 -> V_27 ) ;
F_21 ( & V_8 -> V_29 -> V_35 -> V_36 , & V_8 -> V_34 ) ;
}
static void
F_26 ( struct V_7 * V_8 , T_1 V_50 )
{
struct V_51 * V_24 = & V_8 -> V_25 . V_52 ;
int V_53 ;
int V_54 ;
F_16 ( V_24 -> V_27 , V_28 ,
V_55 , 0 , V_8 -> V_29 -> V_30 ) ;
V_24 -> V_27 . V_31 = F_17 (
F_18 ( sizeof( struct V_51 ) ) ) ;
V_24 -> V_50 = V_50 ;
for ( V_53 = 0 ; V_53 < ( V_56 / 32 ) ; V_53 ++ ) {
V_54 = ( V_50 * ( V_56 / 32 ) ) + V_53 ;
if ( V_8 -> V_57 == V_58 )
V_24 -> V_59 [ V_53 ] =
F_27 ( V_8 -> V_60 [ V_54 ] ) ;
else
V_24 -> V_59 [ V_53 ] = 0xFFFFFFFF ;
}
F_20 ( & V_8 -> V_34 , NULL , NULL ,
sizeof( struct V_51 ) , & V_24 -> V_27 ) ;
F_21 ( & V_8 -> V_29 -> V_35 -> V_36 , & V_8 -> V_34 ) ;
}
static void
F_28 ( struct V_7 * V_8 )
{
struct V_46 * V_24 = & V_8 -> V_25 . V_24 ;
F_16 ( V_24 -> V_27 , V_28 ,
V_61 , 0 , V_8 -> V_29 -> V_30 ) ;
V_24 -> V_27 . V_31 = F_17 (
F_18 ( sizeof( struct V_46 ) ) ) ;
V_24 -> V_48 = V_8 -> V_62 ;
F_20 ( & V_8 -> V_34 , NULL , NULL ,
sizeof( struct V_46 ) , & V_24 -> V_27 ) ;
F_21 ( & V_8 -> V_29 -> V_35 -> V_36 , & V_8 -> V_34 ) ;
}
static void
F_29 ( struct V_7 * V_8 )
{
struct V_63 * V_24 = & V_8 -> V_25 . V_64 ;
F_16 ( V_24 -> V_27 , V_28 ,
V_65 , 0 , V_8 -> V_29 -> V_30 ) ;
V_24 -> V_27 . V_31 = F_17 (
F_18 ( sizeof( struct V_63 ) ) ) ;
V_24 -> V_66 = F_17 ( V_8 -> V_67 ) ;
memcpy ( & V_24 -> V_68 [ 0 ] , V_8 -> V_69 , V_8 -> V_67 ) ;
F_20 ( & V_8 -> V_34 , NULL , NULL ,
sizeof( struct V_63 ) , & V_24 -> V_27 ) ;
F_21 ( & V_8 -> V_29 -> V_35 -> V_36 , & V_8 -> V_34 ) ;
}
static void
F_30 ( struct V_7 * V_8 )
{
struct V_70 * V_24 = & V_8 -> V_25 . V_71 ;
int V_53 ;
F_16 ( V_24 -> V_27 , V_28 ,
V_72 , 0 , V_8 -> V_29 -> V_30 ) ;
V_24 -> V_27 . V_31 = F_17 (
F_18 ( sizeof( struct V_70 ) ) ) ;
V_24 -> V_73 . type = V_8 -> V_74 . V_75 ;
V_24 -> V_73 . V_76 = V_8 -> V_74 . V_77 ;
for ( V_53 = 0 ; V_53 < V_78 ; V_53 ++ )
V_24 -> V_73 . V_79 [ V_53 ] =
F_27 ( V_8 -> V_74 . V_80 [ V_53 ] ) ;
F_20 ( & V_8 -> V_34 , NULL , NULL ,
sizeof( struct V_70 ) , & V_24 -> V_27 ) ;
F_21 ( & V_8 -> V_29 -> V_35 -> V_36 , & V_8 -> V_34 ) ;
}
static void
F_31 ( struct V_7 * V_8 )
{
struct V_46 * V_24 = & V_8 -> V_25 . V_24 ;
F_16 ( V_24 -> V_27 , V_28 ,
V_81 , 0 , V_8 -> V_29 -> V_30 ) ;
V_24 -> V_27 . V_31 = F_17 (
F_18 ( sizeof( struct V_46 ) ) ) ;
V_24 -> V_48 = V_8 -> V_82 ;
F_20 ( & V_8 -> V_34 , NULL , NULL ,
sizeof( struct V_46 ) , & V_24 -> V_27 ) ;
F_21 ( & V_8 -> V_29 -> V_35 -> V_36 , & V_8 -> V_34 ) ;
}
static struct V_19 *
F_32 ( struct V_7 * V_8 , const T_1 * V_32 )
{
struct V_19 * V_20 ;
F_33 (mac, &rxf->mcast_active_q, qe)
if ( F_34 ( V_20 -> V_33 , V_32 ) )
return V_20 ;
F_33 (mac, &rxf->mcast_pending_del_q, qe)
if ( F_34 ( V_20 -> V_33 , V_32 ) )
return V_20 ;
return NULL ;
}
static struct V_83 *
F_35 ( struct V_7 * V_8 , int V_40 )
{
struct V_83 * V_84 ;
F_33 (mchandle, &rxf->mcast_handle_q, qe)
if ( V_84 -> V_40 == V_40 )
return V_84 ;
return NULL ;
}
static void
F_36 ( struct V_7 * V_8 , T_1 * V_32 , int V_40 )
{
struct V_19 * V_85 ;
struct V_83 * V_84 ;
V_85 = F_32 ( V_8 , V_32 ) ;
V_84 = F_35 ( V_8 , V_40 ) ;
if ( V_84 == NULL ) {
V_84 = F_37 ( & V_8 -> V_29 -> V_35 -> V_86 ) ;
V_84 -> V_40 = V_40 ;
V_84 -> V_87 = 0 ;
F_38 ( & V_84 -> V_88 , & V_8 -> V_89 ) ;
}
V_84 -> V_87 ++ ;
V_85 -> V_40 = V_84 ;
}
static int
F_39 ( struct V_7 * V_8 , struct V_19 * V_20 ,
enum V_90 V_91 )
{
struct V_83 * V_84 ;
int V_92 = 0 ;
V_84 = V_20 -> V_40 ;
if ( V_84 == NULL )
return V_92 ;
V_84 -> V_87 -- ;
if ( V_84 -> V_87 == 0 ) {
if ( V_91 == V_93 ) {
F_23 ( V_8 , V_84 -> V_40 ) ;
V_92 = 1 ;
}
F_40 ( & V_84 -> V_88 ) ;
F_41 ( & V_8 -> V_29 -> V_35 -> V_86 , V_84 ) ;
}
V_20 -> V_40 = NULL ;
return V_92 ;
}
static int
F_42 ( struct V_7 * V_8 )
{
struct V_19 * V_20 = NULL ;
int V_92 ;
while ( ! F_43 ( & V_8 -> V_94 ) ) {
V_20 = F_44 ( & V_8 -> V_94 ,
struct V_19 , V_88 ) ;
V_92 = F_39 ( V_8 , V_20 , V_93 ) ;
F_45 ( & V_20 -> V_88 , F_46 ( V_8 -> V_29 -> V_35 ) ) ;
if ( V_92 )
return V_92 ;
}
if ( ! F_43 ( & V_8 -> V_95 ) ) {
V_20 = F_44 ( & V_8 -> V_95 ,
struct V_19 , V_88 ) ;
F_45 ( & V_20 -> V_88 , & V_8 -> V_96 ) ;
F_22 ( V_8 , V_20 ) ;
return 1 ;
}
return 0 ;
}
static int
F_47 ( struct V_7 * V_8 )
{
T_1 V_97 ;
int V_50 = 0 ;
if ( V_8 -> V_97 ) {
V_97 = V_8 -> V_97 ;
while ( ! ( V_97 & 0x1 ) ) {
V_50 ++ ;
V_97 >>= 1 ;
}
V_8 -> V_97 &= ~ F_48 ( V_50 ) ;
F_26 ( V_8 , V_50 ) ;
return 1 ;
}
return 0 ;
}
static int
F_49 ( struct V_7 * V_8 , enum V_90 V_91 )
{
struct V_19 * V_20 ;
int V_92 ;
while ( ! F_43 ( & V_8 -> V_94 ) ) {
V_20 = F_44 ( & V_8 -> V_94 ,
struct V_19 , V_88 ) ;
V_92 = F_39 ( V_8 , V_20 , V_91 ) ;
F_45 ( & V_20 -> V_88 , F_46 ( V_8 -> V_29 -> V_35 ) ) ;
if ( V_92 )
return V_92 ;
}
while ( ! F_43 ( & V_8 -> V_96 ) ) {
V_20 = F_44 ( & V_8 -> V_96 ,
struct V_19 , V_88 ) ;
F_45 ( & V_20 -> V_88 , & V_8 -> V_95 ) ;
if ( F_39 ( V_8 , V_20 , V_91 ) )
return 1 ;
}
return 0 ;
}
static int
F_50 ( struct V_7 * V_8 )
{
if ( V_8 -> V_98 ) {
if ( V_8 -> V_98 & V_99 ) {
V_8 -> V_98 &= ~ V_99 ;
F_29 ( V_8 ) ;
return 1 ;
}
if ( V_8 -> V_98 & V_100 ) {
V_8 -> V_98 &= ~ V_100 ;
F_30 ( V_8 ) ;
return 1 ;
}
if ( V_8 -> V_98 & V_101 ) {
V_8 -> V_98 &= ~ V_101 ;
F_31 ( V_8 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_10 ( struct V_7 * V_8 )
{
if ( F_51 ( V_8 ) )
return 1 ;
if ( F_42 ( V_8 ) )
return 1 ;
if ( F_52 ( V_8 ) )
return 1 ;
if ( F_53 ( V_8 ) )
return 1 ;
if ( F_47 ( V_8 ) )
return 1 ;
if ( F_54 ( V_8 ) )
return 1 ;
if ( F_50 ( V_8 ) )
return 1 ;
return 0 ;
}
static void
F_11 ( struct V_7 * V_8 )
{
F_55 ( V_8 , V_102 ) ;
F_49 ( V_8 , V_102 ) ;
F_56 ( V_8 , V_102 ) ;
F_57 ( V_8 , V_102 ) ;
F_58 ( V_8 ) ;
F_59 ( V_8 ) ;
}
static void
F_60 ( struct V_7 * V_8 , int V_67 )
{
struct V_103 * V_29 = V_8 -> V_29 ;
struct V_104 * V_105 ;
int V_106 = 0 ;
V_8 -> V_67 = V_67 ;
F_33 (rxp, &rx->rxp_q, qe) {
V_8 -> V_69 [ V_106 ] = V_105 -> V_107 . V_108 -> V_109 ;
V_106 ++ ;
}
}
void
F_61 ( struct V_7 * V_8 , struct V_110 * V_111 )
{
F_62 ( V_8 , V_18 ) ;
}
void
F_63 ( struct V_7 * V_8 ,
struct V_110 * V_111 )
{
struct V_112 * V_113 =
F_64 ( V_111 , struct V_112 , V_27 ) ;
if ( V_113 -> error ) {
V_8 -> V_114 = 0 ;
}
F_62 ( V_8 , V_18 ) ;
}
void
F_65 ( struct V_7 * V_8 ,
struct V_110 * V_111 )
{
struct V_37 * V_24 =
& V_8 -> V_25 . V_38 ;
struct V_115 * V_113 =
F_64 ( V_111 , struct V_115 , V_27 ) ;
F_36 ( V_8 , ( T_1 * ) & V_24 -> V_32 ,
F_66 ( V_113 -> V_40 ) ) ;
F_62 ( V_8 , V_18 ) ;
}
static void
F_67 ( struct V_7 * V_8 ,
struct V_103 * V_29 ,
struct V_116 * V_117 ,
struct V_118 * V_119 )
{
V_8 -> V_29 = V_29 ;
F_68 ( & V_8 -> V_120 ) ;
F_68 ( & V_8 -> V_121 ) ;
V_8 -> V_122 = 0 ;
V_8 -> V_114 = 0 ;
F_68 ( & V_8 -> V_123 ) ;
V_8 -> V_124 = NULL ;
F_68 ( & V_8 -> V_95 ) ;
F_68 ( & V_8 -> V_94 ) ;
F_68 ( & V_8 -> V_96 ) ;
F_68 ( & V_8 -> V_89 ) ;
V_8 -> V_69 = ( T_1 * )
V_119 [ V_125 ] . V_126 . V_127 . V_128 [ 0 ] . V_129 ;
F_60 ( V_8 , V_117 -> V_130 ) ;
V_8 -> V_82 = V_117 -> V_82 ;
if ( V_8 -> V_82 == V_58 ) {
V_8 -> V_74 = V_117 -> V_131 ;
V_8 -> V_98 |= V_100 ;
V_8 -> V_98 |= V_99 ;
V_8 -> V_98 |= V_101 ;
}
V_8 -> V_57 = V_132 ;
memset ( V_8 -> V_60 , 0 ,
( sizeof( V_6 ) * ( V_133 / 32 ) ) ) ;
V_8 -> V_60 [ 0 ] |= 1 ;
V_8 -> V_97 = ( T_1 ) V_134 ;
V_8 -> V_62 = V_117 -> V_62 ;
F_6 ( V_8 , F_5 ) ;
}
static void
F_69 ( struct V_7 * V_8 )
{
struct V_19 * V_20 ;
V_8 -> V_122 = 0 ;
V_8 -> V_114 = 0 ;
while ( ! F_43 ( & V_8 -> V_120 ) ) {
V_20 = F_44 ( & V_8 -> V_120 ,
struct V_19 , V_88 ) ;
F_45 ( & V_20 -> V_88 , F_70 ( V_8 -> V_29 -> V_35 ) ) ;
}
if ( V_8 -> V_124 ) {
F_38 ( & V_8 -> V_124 -> V_88 ,
F_70 ( V_8 -> V_29 -> V_35 ) ) ;
V_8 -> V_124 = NULL ;
}
while ( ! F_43 ( & V_8 -> V_95 ) ) {
V_20 = F_44 ( & V_8 -> V_95 ,
struct V_19 , V_88 ) ;
F_45 ( & V_20 -> V_88 , F_71 ( V_8 -> V_29 -> V_35 ) ) ;
}
V_8 -> V_135 = 0 ;
V_8 -> V_136 = 0 ;
if ( V_8 -> V_29 -> V_35 -> V_137 == V_8 -> V_29 -> V_30 )
V_8 -> V_29 -> V_35 -> V_137 = V_138 ;
if ( V_8 -> V_29 -> V_35 -> V_139 == V_8 -> V_29 -> V_30 )
V_8 -> V_29 -> V_35 -> V_139 = V_138 ;
V_8 -> V_98 = 0 ;
V_8 -> V_140 = false ;
V_8 -> V_29 = NULL ;
}
static void
F_72 ( struct V_103 * V_29 )
{
F_62 ( V_29 , V_141 ) ;
}
static void
F_73 ( struct V_7 * V_8 )
{
V_8 -> V_142 = F_72 ;
V_8 -> V_143 = V_8 -> V_29 ;
F_62 ( V_8 , V_11 ) ;
}
static void
F_74 ( struct V_103 * V_29 )
{
F_62 ( V_29 , V_144 ) ;
}
static void
F_75 ( struct V_7 * V_8 )
{
V_8 -> V_145 = F_74 ;
V_8 -> V_146 = V_8 -> V_29 ;
F_62 ( V_8 , V_13 ) ;
}
static void
F_76 ( struct V_7 * V_8 )
{
F_62 ( V_8 , V_14 ) ;
}
enum V_147
F_77 ( struct V_103 * V_29 , const T_1 * V_148 )
{
struct V_7 * V_8 = & V_29 -> V_8 ;
if ( V_8 -> V_124 == NULL ) {
V_8 -> V_124 =
F_78 ( F_70 ( V_8 -> V_29 -> V_35 ) ) ;
if ( V_8 -> V_124 == NULL )
return V_149 ;
}
F_19 ( V_8 -> V_124 -> V_33 , V_148 ) ;
V_8 -> V_122 = 1 ;
V_8 -> V_150 = NULL ;
V_8 -> V_151 = V_29 -> V_35 -> V_152 ;
F_62 ( V_8 , V_15 ) ;
return V_153 ;
}
enum V_147
F_79 ( struct V_103 * V_29 , const T_1 * V_33 ,
void (* F_80)( struct V_152 * , struct V_103 * ) )
{
struct V_7 * V_8 = & V_29 -> V_8 ;
struct V_19 * V_20 ;
if ( F_81 ( & V_8 -> V_96 , V_33 ) ||
F_81 ( & V_8 -> V_95 , V_33 ) ) {
if ( F_80 )
F_80 ( V_29 -> V_35 -> V_152 , V_29 ) ;
return V_153 ;
}
V_20 = F_78 ( F_71 ( V_8 -> V_29 -> V_35 ) ) ;
if ( V_20 == NULL )
return V_154 ;
F_19 ( V_20 -> V_33 , V_33 ) ;
F_38 ( & V_20 -> V_88 , & V_8 -> V_95 ) ;
V_8 -> V_150 = F_80 ;
V_8 -> V_151 = V_29 -> V_35 -> V_152 ;
F_62 ( V_8 , V_15 ) ;
return V_153 ;
}
enum V_147
F_82 ( struct V_103 * V_29 , int V_155 , const T_1 * V_156 )
{
struct V_157 * V_158 = & V_29 -> V_35 -> V_158 ;
struct V_7 * V_8 = & V_29 -> V_8 ;
struct V_159 V_159 ;
const T_1 * V_160 ;
struct V_19 * V_20 , * V_161 ;
int V_53 ;
while ( ! F_43 ( & V_8 -> V_120 ) ) {
V_20 = F_44 ( & V_8 -> V_120 ,
struct V_19 , V_88 ) ;
F_45 ( & V_20 -> V_88 , & V_158 -> V_162 ) ;
}
while ( ! F_43 ( & V_8 -> V_123 ) ) {
V_20 = F_44 ( & V_8 -> V_123 ,
struct V_19 , V_88 ) ;
V_161 = F_78 ( & V_158 -> V_163 ) ;
F_19 ( V_161 -> V_33 , V_20 -> V_33 ) ;
V_161 -> V_40 = V_20 -> V_40 ;
F_38 ( & V_161 -> V_88 , & V_8 -> V_121 ) ;
F_45 ( & V_20 -> V_88 , & V_158 -> V_162 ) ;
}
F_68 ( & V_159 ) ;
for ( V_53 = 0 , V_160 = V_156 ; V_53 < V_155 ; V_53 ++ ) {
V_20 = F_78 ( & V_158 -> V_162 ) ;
if ( V_20 == NULL )
goto V_164;
F_19 ( V_20 -> V_33 , V_160 ) ;
F_38 ( & V_20 -> V_88 , & V_159 ) ;
V_160 += V_165 ;
}
while ( ! F_43 ( & V_159 ) ) {
V_20 = F_44 ( & V_159 , struct V_19 , V_88 ) ;
F_45 ( & V_20 -> V_88 , & V_8 -> V_120 ) ;
}
F_62 ( V_8 , V_15 ) ;
return V_153 ;
V_164:
while ( ! F_43 ( & V_159 ) ) {
V_20 = F_44 ( & V_159 , struct V_19 , V_88 ) ;
F_45 ( & V_20 -> V_88 , & V_158 -> V_162 ) ;
}
return V_149 ;
}
enum V_147
F_83 ( struct V_103 * V_29 , int V_155 , const T_1 * V_166 )
{
struct V_167 * V_86 = & V_29 -> V_35 -> V_86 ;
struct V_7 * V_8 = & V_29 -> V_8 ;
struct V_159 V_159 ;
const T_1 * V_160 ;
struct V_19 * V_20 , * V_161 ;
int V_53 ;
while ( ! F_43 ( & V_8 -> V_95 ) ) {
V_20 = F_44 ( & V_8 -> V_95 ,
struct V_19 , V_88 ) ;
F_45 ( & V_20 -> V_88 , & V_86 -> V_162 ) ;
}
while ( ! F_43 ( & V_8 -> V_96 ) ) {
V_20 = F_44 ( & V_8 -> V_96 ,
struct V_19 , V_88 ) ;
V_161 = F_78 ( & V_86 -> V_163 ) ;
F_19 ( V_161 -> V_33 , V_20 -> V_33 ) ;
V_161 -> V_40 = V_20 -> V_40 ;
F_38 ( & V_161 -> V_88 , & V_8 -> V_94 ) ;
V_20 -> V_40 = NULL ;
F_45 ( & V_20 -> V_88 , & V_86 -> V_162 ) ;
}
F_68 ( & V_159 ) ;
for ( V_53 = 0 , V_160 = V_166 ; V_53 < V_155 ; V_53 ++ ) {
V_20 = F_78 ( & V_86 -> V_162 ) ;
if ( V_20 == NULL )
goto V_164;
F_19 ( V_20 -> V_33 , V_160 ) ;
F_38 ( & V_20 -> V_88 , & V_159 ) ;
V_160 += V_165 ;
}
while ( ! F_43 ( & V_159 ) ) {
V_20 = F_44 ( & V_159 , struct V_19 , V_88 ) ;
F_45 ( & V_20 -> V_88 , & V_8 -> V_95 ) ;
}
F_62 ( V_8 , V_15 ) ;
return V_153 ;
V_164:
while ( ! F_43 ( & V_159 ) ) {
V_20 = F_44 ( & V_159 , struct V_19 , V_88 ) ;
F_45 ( & V_20 -> V_88 , & V_86 -> V_162 ) ;
}
return V_154 ;
}
void
F_84 ( struct V_103 * V_29 )
{
struct V_7 * V_8 = & V_29 -> V_8 ;
struct V_19 * V_20 , * V_161 ;
int V_168 = 0 ;
while ( ! F_43 ( & V_8 -> V_95 ) ) {
V_20 = F_44 ( & V_8 -> V_95 ,
struct V_19 , V_88 ) ;
F_45 ( & V_20 -> V_88 , F_71 ( V_8 -> V_29 -> V_35 ) ) ;
}
while ( ! F_43 ( & V_8 -> V_96 ) ) {
V_20 = F_44 ( & V_8 -> V_96 ,
struct V_19 , V_88 ) ;
F_40 ( & V_20 -> V_88 ) ;
V_161 = F_78 ( F_46 ( V_8 -> V_29 -> V_35 ) ) ;
memcpy ( V_161 , V_20 , sizeof( * V_161 ) ) ;
F_38 ( & V_161 -> V_88 , & V_8 -> V_94 ) ;
V_20 -> V_40 = NULL ;
F_38 ( & V_20 -> V_88 , F_71 ( V_8 -> V_29 -> V_35 ) ) ;
V_168 = 1 ;
}
if ( V_168 )
F_62 ( V_8 , V_15 ) ;
}
void
F_85 ( struct V_103 * V_29 , int V_169 )
{
struct V_7 * V_8 = & V_29 -> V_8 ;
int V_170 = ( V_169 >> V_171 ) ;
int V_172 = F_48 ( V_169 & V_173 ) ;
int V_174 = ( V_169 >> V_175 ) ;
V_8 -> V_60 [ V_170 ] |= V_172 ;
if ( V_8 -> V_57 == V_58 ) {
V_8 -> V_97 |= F_48 ( V_174 ) ;
F_62 ( V_8 , V_15 ) ;
}
}
void
F_86 ( struct V_103 * V_29 , int V_169 )
{
struct V_7 * V_8 = & V_29 -> V_8 ;
int V_170 = ( V_169 >> V_171 ) ;
int V_172 = F_48 ( V_169 & V_173 ) ;
int V_174 = ( V_169 >> V_175 ) ;
V_8 -> V_60 [ V_170 ] &= ~ V_172 ;
if ( V_8 -> V_57 == V_58 ) {
V_8 -> V_97 |= F_48 ( V_174 ) ;
F_62 ( V_8 , V_15 ) ;
}
}
static int
F_51 ( struct V_7 * V_8 )
{
struct V_19 * V_20 = NULL ;
if ( ! F_43 ( & V_8 -> V_121 ) ) {
V_20 = F_44 ( & V_8 -> V_121 ,
struct V_19 , V_88 ) ;
F_15 ( V_8 , V_20 , V_176 ) ;
F_45 ( & V_20 -> V_88 , F_87 ( V_8 -> V_29 -> V_35 ) ) ;
return 1 ;
}
if ( V_8 -> V_122 ) {
V_8 -> V_122 = 0 ;
F_19 ( V_8 -> V_177 . V_33 ,
V_8 -> V_124 -> V_33 ) ;
V_8 -> V_114 = 1 ;
F_15 ( V_8 , & V_8 -> V_177 ,
V_178 ) ;
return 1 ;
}
if ( ! F_43 ( & V_8 -> V_120 ) ) {
V_20 = F_44 ( & V_8 -> V_120 ,
struct V_19 , V_88 ) ;
F_38 ( & V_20 -> V_88 , & V_8 -> V_123 ) ;
F_15 ( V_8 , V_20 , V_179 ) ;
return 1 ;
}
return 0 ;
}
static int
F_55 ( struct V_7 * V_8 , enum V_90 V_91 )
{
struct V_19 * V_20 ;
while ( ! F_43 ( & V_8 -> V_121 ) ) {
V_20 = F_44 ( & V_8 -> V_121 ,
struct V_19 , V_88 ) ;
if ( V_91 == V_102 )
F_45 ( & V_20 -> V_88 ,
F_87 ( V_8 -> V_29 -> V_35 ) ) ;
else {
F_15 ( V_8 , V_20 ,
V_176 ) ;
F_45 ( & V_20 -> V_88 ,
F_87 ( V_8 -> V_29 -> V_35 ) ) ;
return 1 ;
}
}
while ( ! F_43 ( & V_8 -> V_123 ) ) {
V_20 = F_44 ( & V_8 -> V_123 ,
struct V_19 , V_88 ) ;
F_45 ( & V_20 -> V_88 , & V_8 -> V_120 ) ;
if ( V_91 == V_93 ) {
F_15 ( V_8 , V_20 ,
V_176 ) ;
return 1 ;
}
}
if ( V_8 -> V_114 ) {
V_8 -> V_122 = 1 ;
V_8 -> V_114 = 0 ;
if ( V_91 == V_93 ) {
F_15 ( V_8 , & V_8 -> V_177 ,
V_180 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_52 ( struct V_7 * V_8 )
{
struct V_35 * V_35 = V_8 -> V_29 -> V_35 ;
if ( F_88 ( V_8 -> V_135 ,
V_8 -> V_136 ) ) {
F_89 ( V_8 -> V_135 ,
V_8 -> V_136 ) ;
V_8 -> V_181 |= V_182 ;
F_25 ( V_8 , V_58 ) ;
return 1 ;
} else if ( F_90 ( V_8 -> V_135 ,
V_8 -> V_136 ) ) {
F_89 ( V_8 -> V_135 ,
V_8 -> V_136 ) ;
V_8 -> V_181 &= ~ V_182 ;
V_35 -> V_137 = V_138 ;
F_25 ( V_8 , V_132 ) ;
return 1 ;
}
return 0 ;
}
static int
F_56 ( struct V_7 * V_8 , enum V_90 V_91 )
{
struct V_35 * V_35 = V_8 -> V_29 -> V_35 ;
if ( F_90 ( V_8 -> V_135 ,
V_8 -> V_136 ) ) {
F_89 ( V_8 -> V_135 ,
V_8 -> V_136 ) ;
V_8 -> V_181 &= ~ V_182 ;
V_35 -> V_137 = V_138 ;
if ( V_91 == V_93 ) {
F_25 ( V_8 , V_132 ) ;
return 1 ;
}
}
if ( V_8 -> V_181 & V_182 ) {
F_91 ( V_8 -> V_135 ,
V_8 -> V_136 ) ;
V_8 -> V_181 &= ~ V_182 ;
if ( V_91 == V_93 ) {
F_25 ( V_8 , V_132 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_53 ( struct V_7 * V_8 )
{
if ( F_92 ( V_8 -> V_135 ,
V_8 -> V_136 ) ) {
F_93 ( V_8 -> V_135 ,
V_8 -> V_136 ) ;
V_8 -> V_181 |= V_183 ;
F_24 ( V_8 , V_132 ) ;
return 1 ;
} else if ( F_94 ( V_8 -> V_135 ,
V_8 -> V_136 ) ) {
F_93 ( V_8 -> V_135 ,
V_8 -> V_136 ) ;
V_8 -> V_181 &= ~ V_183 ;
F_24 ( V_8 , V_58 ) ;
return 1 ;
}
return 0 ;
}
static int
F_57 ( struct V_7 * V_8 , enum V_90 V_91 )
{
if ( F_94 ( V_8 -> V_135 ,
V_8 -> V_136 ) ) {
F_93 ( V_8 -> V_135 ,
V_8 -> V_136 ) ;
V_8 -> V_181 &= ~ V_183 ;
if ( V_91 == V_93 ) {
F_24 ( V_8 , V_58 ) ;
return 1 ;
}
}
if ( V_8 -> V_181 & V_183 ) {
F_95 ( V_8 -> V_135 ,
V_8 -> V_136 ) ;
V_8 -> V_181 &= ~ V_183 ;
if ( V_91 == V_93 ) {
F_24 ( V_8 , V_58 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_96 ( struct V_7 * V_8 )
{
struct V_35 * V_35 = V_8 -> V_29 -> V_35 ;
int V_92 = 0 ;
if ( F_88 ( V_8 -> V_135 ,
V_8 -> V_136 ) ||
( V_8 -> V_181 & V_182 ) ) {
} else if ( F_90 ( V_8 -> V_135 ,
V_8 -> V_136 ) ) {
F_89 ( V_8 -> V_135 ,
V_8 -> V_136 ) ;
} else {
F_91 ( V_8 -> V_135 ,
V_8 -> V_136 ) ;
V_35 -> V_137 = V_8 -> V_29 -> V_30 ;
V_92 = 1 ;
}
return V_92 ;
}
static int
F_97 ( struct V_7 * V_8 )
{
struct V_35 * V_35 = V_8 -> V_29 -> V_35 ;
int V_92 = 0 ;
if ( F_90 ( V_8 -> V_135 ,
V_8 -> V_136 ) ||
( ! ( V_8 -> V_181 & V_182 ) ) ) {
} else if ( F_88 ( V_8 -> V_135 ,
V_8 -> V_136 ) ) {
F_89 ( V_8 -> V_135 ,
V_8 -> V_136 ) ;
V_35 -> V_137 = V_138 ;
} else if ( V_8 -> V_181 & V_182 ) {
F_98 ( V_8 -> V_135 ,
V_8 -> V_136 ) ;
V_92 = 1 ;
}
return V_92 ;
}
static int
F_99 ( struct V_7 * V_8 )
{
int V_92 = 0 ;
if ( F_92 ( V_8 -> V_135 ,
V_8 -> V_136 ) ||
( V_8 -> V_181 & V_183 ) ) {
} else if ( F_94 ( V_8 -> V_135 ,
V_8 -> V_136 ) ) {
F_93 ( V_8 -> V_135 ,
V_8 -> V_136 ) ;
} else {
F_95 ( V_8 -> V_135 ,
V_8 -> V_136 ) ;
V_92 = 1 ;
}
return V_92 ;
}
static int
F_100 ( struct V_7 * V_8 )
{
int V_92 = 0 ;
if ( F_94 ( V_8 -> V_135 ,
V_8 -> V_136 ) ||
( ! ( V_8 -> V_181 & V_183 ) ) ) {
} else if ( F_92 ( V_8 -> V_135 ,
V_8 -> V_136 ) ) {
F_93 ( V_8 -> V_135 ,
V_8 -> V_136 ) ;
} else if ( V_8 -> V_181 & V_183 ) {
F_101 ( V_8 -> V_135 ,
V_8 -> V_136 ) ;
V_92 = 1 ;
}
return V_92 ;
}
static int
F_54 ( struct V_7 * V_8 )
{
if ( V_8 -> V_140 ) {
V_8 -> V_140 = false ;
F_28 ( V_8 ) ;
return 1 ;
}
return 0 ;
}
static void F_102 ( struct V_103 * V_29 )
{
F_103 ( V_29 ) ;
}
static void F_104 ( struct V_103 * V_29 ,
enum V_184 V_10 )
{
switch ( V_10 ) {
case V_185 :
F_6 ( V_29 , V_186 ) ;
break;
case V_187 :
F_103 ( V_29 ) ;
break;
case V_188 :
break;
default:
F_8 ( V_10 ) ;
break;
}
}
static void F_105 ( struct V_103 * V_29 )
{
F_106 ( V_29 ) ;
}
static void
F_107 ( struct V_103 * V_29 )
{
}
static void
F_108 ( struct V_103 * V_29 , enum V_184 V_10 )
{
switch ( V_10 ) {
case V_188 :
case V_189 :
F_6 ( V_29 , V_190 ) ;
V_29 -> V_191 ( V_29 -> V_35 -> V_152 , V_29 ) ;
break;
case V_192 :
F_109 ( V_29 ) ;
break;
default:
F_8 ( V_10 ) ;
break;
}
}
static void V_186 ( struct V_103 * V_29 ,
enum V_184 V_10 )
{
switch ( V_10 ) {
case V_187 :
F_6 ( V_29 , V_193 ) ;
break;
case V_188 :
F_6 ( V_29 , F_104 ) ;
break;
case V_192 :
F_6 ( V_29 , V_194 ) ;
break;
default:
F_8 ( V_10 ) ;
break;
}
}
static void F_110 ( struct V_103 * V_29 )
{
V_29 -> V_195 ( V_29 -> V_35 -> V_152 , V_29 ) ;
F_73 ( & V_29 -> V_8 ) ;
}
static void
F_111 ( struct V_103 * V_29 )
{
}
static void
F_112 ( struct V_103 * V_29 , enum V_184 V_10 )
{
switch ( V_10 ) {
case V_188 :
F_6 ( V_29 , V_190 ) ;
F_76 ( & V_29 -> V_8 ) ;
F_113 ( V_29 ) ;
V_29 -> V_191 ( V_29 -> V_35 -> V_152 , V_29 ) ;
break;
case V_141 :
F_75 ( & V_29 -> V_8 ) ;
break;
case V_144 :
F_6 ( V_29 , F_108 ) ;
F_113 ( V_29 ) ;
F_109 ( V_29 ) ;
break;
default:
F_8 ( V_10 ) ;
break;
}
}
static void
F_114 ( struct V_103 * V_29 )
{
}
static void
V_193 ( struct V_103 * V_29 , enum V_184 V_10 )
{
switch ( V_10 ) {
case V_188 :
case V_189 :
F_6 ( V_29 , F_104 ) ;
break;
case V_192 :
F_109 ( V_29 ) ;
break;
default:
F_8 ( V_10 ) ;
}
}
static void
F_115 ( struct V_103 * V_29 )
{
struct V_104 * V_105 ;
int V_196 = ( V_29 -> type == V_197 ) ;
F_33 (rxp, &rx->rxp_q, qe)
F_116 ( V_29 -> V_35 , & V_105 -> V_107 . V_2 , V_196 ) ;
F_117 ( & V_29 -> V_35 -> V_198 ) ;
}
static void
F_118 ( struct V_103 * V_29 , enum V_184 V_10 )
{
switch ( V_10 ) {
case V_187 :
F_6 ( V_29 , F_112 ) ;
F_119 ( & V_29 -> V_35 -> V_198 ) ;
F_75 ( & V_29 -> V_8 ) ;
break;
case V_188 :
F_6 ( V_29 , V_199 ) ;
F_119 ( & V_29 -> V_35 -> V_198 ) ;
F_76 ( & V_29 -> V_8 ) ;
F_113 ( V_29 ) ;
V_29 -> V_191 ( V_29 -> V_35 -> V_152 , V_29 ) ;
break;
default:
F_8 ( V_10 ) ;
break;
}
}
static void V_194 ( struct V_103 * V_29 ,
enum V_184 V_10 )
{
switch ( V_10 ) {
case V_187 :
F_6 ( V_29 , F_112 ) ;
break;
case V_188 :
F_6 ( V_29 , V_199 ) ;
F_76 ( & V_29 -> V_8 ) ;
F_113 ( V_29 ) ;
V_29 -> V_191 ( V_29 -> V_35 -> V_152 , V_29 ) ;
break;
case V_141 :
F_6 ( V_29 , F_118 ) ;
break;
default:
F_8 ( V_10 ) ;
break;
}
}
static void
F_120 ( struct V_103 * V_29 )
{
}
static void
V_190 ( struct V_103 * V_29 , enum V_184 V_10 )
{
switch ( V_10 ) {
case V_188 :
case V_144 :
break;
case V_200 :
F_6 ( V_29 , F_104 ) ;
break;
default:
F_8 ( V_10 ) ;
break;
}
}
static void
F_121 ( struct V_103 * V_29 )
{
}
static void
V_199 ( struct V_103 * V_29 , enum V_184 V_10 )
{
switch ( V_10 ) {
case V_185 :
F_6 ( V_29 , V_201 ) ;
break;
case V_187 :
F_6 ( V_29 , V_190 ) ;
break;
case V_188 :
case V_141 :
case V_144 :
break;
case V_200 :
F_6 ( V_29 , F_104 ) ;
break;
default:
F_8 ( V_10 ) ;
break;
} }
static void
F_122 ( struct V_103 * V_29 )
{
}
static void
V_201 ( struct V_103 * V_29 , enum V_184 V_10 )
{
switch ( V_10 ) {
case V_187 :
F_6 ( V_29 , V_190 ) ;
break;
case V_188 :
F_6 ( V_29 , V_199 ) ;
break;
case V_200 :
F_6 ( V_29 , V_186 ) ;
break;
default:
F_8 ( V_10 ) ;
break;
}
}
static void
F_106 ( struct V_103 * V_29 )
{
struct V_202 * V_203 = & V_29 -> V_25 . V_203 ;
struct V_104 * V_105 = NULL ;
struct V_204 * V_205 = NULL , * V_206 = NULL ;
int V_53 ;
F_16 ( V_203 -> V_27 , V_28 ,
V_207 , 0 , V_29 -> V_30 ) ;
V_203 -> V_27 . V_31 = F_17 (
F_18 ( sizeof( struct V_202 ) ) ) ;
V_203 -> V_208 . V_209 = F_123 ( & V_29 -> V_35 -> V_210 ) ;
V_203 -> V_211 = V_29 -> V_130 ;
for ( V_53 = 0 ; V_53 < V_29 -> V_130 ; V_53 ++ ) {
V_105 = V_105 ? F_124 ( V_105 , V_88 )
: F_44 ( & V_29 -> V_212 , struct V_104 , V_88 ) ;
F_125 ( V_105 , V_205 , V_206 ) ;
switch ( V_105 -> type ) {
case V_213 :
case V_214 :
F_126 ( & V_203 -> V_215 [ V_53 ] . V_216 . V_217 ,
& V_206 -> V_218 ) ;
V_203 -> V_215 [ V_53 ] . V_216 . V_219 =
F_17 ( ( T_2 ) V_206 -> V_220 ) ;
case V_221 :
F_126 ( & V_203 -> V_215 [ V_53 ] . V_222 . V_217 ,
& V_205 -> V_218 ) ;
if ( V_205 -> V_223 )
V_203 -> V_208 . V_223 =
V_58 ;
else
V_205 -> V_220 =
F_123 ( & V_29 -> V_35 -> V_210 ) ;
V_203 -> V_215 [ V_53 ] . V_222 . V_219 =
F_17 ( ( T_2 ) V_205 -> V_220 ) ;
break;
default:
F_127 ( 1 ) ;
}
F_126 ( & V_203 -> V_215 [ V_53 ] . V_107 . V_217 ,
& V_105 -> V_107 . V_218 ) ;
V_203 -> V_215 [ V_53 ] . V_2 . V_224 . V_225 . V_226 =
V_105 -> V_107 . V_2 . V_227 . V_228 ;
V_203 -> V_215 [ V_53 ] . V_2 . V_224 . V_225 . V_229 =
V_105 -> V_107 . V_2 . V_227 . V_230 ;
V_203 -> V_215 [ V_53 ] . V_2 . V_231 . V_232 =
F_17 ( ( T_2 ) V_105 -> V_107 . V_2 . V_233 ) ;
}
V_203 -> V_234 . V_235 = V_132 ;
V_203 -> V_234 . V_236 = V_58 ;
V_203 -> V_234 . V_237 = V_132 ;
V_203 -> V_234 . V_238 = V_132 ;
V_203 -> V_234 . V_239 = ( V_105 -> V_107 . V_2 . V_240 == V_241 )
? V_58 :
V_132 ;
V_203 -> V_234 . V_242 =
F_27 ( ( V_6 ) V_105 -> V_107 . V_2 . V_3 ) ;
V_203 -> V_234 . V_243 =
F_27 ( ( V_6 ) V_105 -> V_107 . V_2 . V_244 ) ;
V_203 -> V_234 . V_245 = ( T_1 ) V_105 -> V_107 . V_2 . V_246 ;
switch ( V_105 -> type ) {
case V_213 :
V_203 -> V_208 . V_247 = V_248 ;
break;
case V_214 :
V_203 -> V_208 . V_247 = V_249 ;
V_203 -> V_208 . V_250 . type = V_29 -> V_251 . V_252 ;
V_203 -> V_208 . V_250 . V_253 = V_29 -> V_251 . V_254 ;
V_203 -> V_208 . V_250 . V_255 = V_29 -> V_251 . V_254 ;
break;
case V_221 :
V_203 -> V_208 . V_247 = V_256 ;
break;
default:
F_127 ( 1 ) ;
}
V_203 -> V_208 . V_257 = V_29 -> V_8 . V_62 ;
F_20 ( & V_29 -> V_34 , NULL , NULL ,
sizeof( struct V_202 ) , & V_203 -> V_27 ) ;
F_21 ( & V_29 -> V_35 -> V_36 , & V_29 -> V_34 ) ;
}
static void
F_128 ( struct V_103 * V_29 )
{
struct V_258 * V_24 = & V_29 -> V_25 . V_24 ;
F_16 ( V_24 -> V_27 , V_28 ,
V_259 , 0 , V_29 -> V_30 ) ;
V_24 -> V_27 . V_31 = F_17 (
F_18 ( sizeof( struct V_258 ) ) ) ;
F_20 ( & V_29 -> V_34 , NULL , NULL , sizeof( struct V_258 ) ,
& V_24 -> V_27 ) ;
F_21 ( & V_29 -> V_35 -> V_36 , & V_29 -> V_34 ) ;
}
static void
F_109 ( struct V_103 * V_29 )
{
struct V_104 * V_105 ;
F_33 (rxp, &rx->rxp_q, qe)
F_129 ( V_29 -> V_35 , & V_105 -> V_107 . V_2 ) ;
F_128 ( V_29 ) ;
}
static int
F_130 ( struct V_260 * V_261 , struct V_116 * V_208 )
{
if ( ( V_261 -> V_262 == 0 ) ||
( V_261 -> V_263 == 0 ) ||
( V_261 -> V_264 == 0 ) )
return 0 ;
if ( V_208 -> V_265 == V_221 ) {
if ( ( V_261 -> V_263 < V_208 -> V_130 ) ||
( V_261 -> V_264 < V_208 -> V_130 ) )
return 0 ;
} else {
if ( ( V_261 -> V_263 < V_208 -> V_130 ) ||
( V_261 -> V_264 < ( 2 * V_208 -> V_130 ) ) )
return 0 ;
}
return 1 ;
}
static struct V_204 *
F_131 ( struct V_260 * V_261 )
{
struct V_204 * V_266 = NULL ;
V_266 = F_44 ( & V_261 -> V_267 , struct V_204 , V_88 ) ;
F_40 ( & V_266 -> V_88 ) ;
V_261 -> V_264 -- ;
return V_266 ;
}
static void
F_132 ( struct V_260 * V_261 , struct V_204 * V_266 )
{
F_38 ( & V_266 -> V_88 , & V_261 -> V_267 ) ;
V_261 -> V_264 ++ ;
}
static struct V_104 *
F_133 ( struct V_260 * V_261 )
{
struct V_104 * V_105 = NULL ;
V_105 = F_44 ( & V_261 -> V_268 , struct V_104 , V_88 ) ;
F_40 ( & V_105 -> V_88 ) ;
V_261 -> V_263 -- ;
return V_105 ;
}
static void
F_134 ( struct V_260 * V_261 , struct V_104 * V_105 )
{
F_38 ( & V_105 -> V_88 , & V_261 -> V_268 ) ;
V_261 -> V_263 ++ ;
}
static struct V_103 *
F_135 ( struct V_260 * V_261 , enum V_269 type )
{
struct V_103 * V_29 = NULL ;
F_127 ( F_43 ( & V_261 -> V_270 ) ) ;
if ( type == V_197 )
V_29 = F_44 ( & V_261 -> V_270 , struct V_103 , V_88 ) ;
else
V_29 = F_136 ( & V_261 -> V_270 , struct V_103 , V_88 ) ;
V_261 -> V_262 -- ;
F_45 ( & V_29 -> V_88 , & V_261 -> V_271 ) ;
V_29 -> type = type ;
return V_29 ;
}
static void
F_137 ( struct V_260 * V_261 , struct V_103 * V_29 )
{
struct V_159 * V_88 ;
F_138 (qe, &rx_mod->rx_free_q)
if ( ( (struct V_103 * ) V_88 ) -> V_30 < V_29 -> V_30 )
break;
F_139 ( & V_29 -> V_88 , V_88 ) ;
V_261 -> V_262 ++ ;
}
static void
F_140 ( struct V_104 * V_105 , struct V_204 * V_205 ,
struct V_204 * V_206 )
{
switch ( V_105 -> type ) {
case V_221 :
V_105 -> V_266 . V_272 . V_273 = V_205 ;
V_105 -> V_266 . V_272 . V_274 = NULL ;
break;
case V_213 :
V_105 -> V_266 . V_275 . V_276 = V_205 ;
V_105 -> V_266 . V_275 . V_277 = V_206 ;
break;
case V_214 :
V_105 -> V_266 . V_250 . V_278 = V_205 ;
V_105 -> V_266 . V_250 . V_279 = V_206 ;
break;
default:
break;
}
}
static void
F_141 ( struct V_204 * V_266 ,
struct V_104 * V_105 ,
V_6 V_280 ,
V_6 V_281 ,
struct V_282 * V_283 ,
struct V_282 * V_284 ,
struct V_282 * V_285 )
{
T_1 * V_129 ;
T_3 V_286 ;
struct V_287 V_288 ;
int V_53 ;
V_266 -> V_218 . V_289 . V_228 = V_283 -> V_286 . V_228 ;
V_266 -> V_218 . V_289 . V_230 = V_283 -> V_286 . V_230 ;
V_266 -> V_218 . V_290 = V_283 -> V_129 ;
V_266 -> V_218 . V_280 = V_280 ;
V_266 -> V_218 . V_281 = V_281 ;
V_266 -> V_291 -> V_292 = ( void * * ) V_284 -> V_129 ;
V_266 -> V_291 -> V_293 = V_285 -> V_129 ;
V_129 = V_285 -> V_129 ;
F_142 ( & V_285 -> V_286 , V_286 ) ;
for ( V_53 = 0 ; V_53 < V_266 -> V_218 . V_280 ; V_53 ++ ) {
V_266 -> V_291 -> V_292 [ V_53 ] = V_129 ;
V_129 += V_294 ;
F_143 ( V_286 , & V_288 ) ;
( (struct V_287 * ) V_266 -> V_218 . V_290 ) [ V_53 ] . V_228 =
V_288 . V_228 ;
( (struct V_287 * ) V_266 -> V_218 . V_290 ) [ V_53 ] . V_230 =
V_288 . V_230 ;
V_286 += V_294 ;
}
}
static void
F_144 ( struct V_104 * V_105 ,
V_6 V_280 ,
V_6 V_281 ,
struct V_282 * V_283 ,
struct V_282 * V_284 ,
struct V_282 * V_285 )
{
T_1 * V_129 ;
T_3 V_286 ;
struct V_287 V_288 ;
int V_53 ;
V_105 -> V_107 . V_218 . V_289 . V_228 = V_283 -> V_286 . V_228 ;
V_105 -> V_107 . V_218 . V_289 . V_230 = V_283 -> V_286 . V_230 ;
V_105 -> V_107 . V_218 . V_290 = V_283 -> V_129 ;
V_105 -> V_107 . V_218 . V_280 = V_280 ;
V_105 -> V_107 . V_218 . V_281 = V_281 ;
V_105 -> V_107 . V_108 -> V_292 = ( void * * ) V_284 -> V_129 ;
V_105 -> V_107 . V_108 -> V_293 = V_285 -> V_129 ;
V_129 = V_285 -> V_129 ;
F_142 ( & V_285 -> V_286 , V_286 ) ;
for ( V_53 = 0 ; V_53 < V_105 -> V_107 . V_218 . V_280 ; V_53 ++ ) {
V_105 -> V_107 . V_108 -> V_292 [ V_53 ] = V_129 ;
V_129 += V_294 ;
F_143 ( V_286 , & V_288 ) ;
( (struct V_287 * ) V_105 -> V_107 . V_218 . V_290 ) [ V_53 ] . V_228 =
V_288 . V_228 ;
( (struct V_287 * ) V_105 -> V_107 . V_218 . V_290 ) [ V_53 ] . V_230 =
V_288 . V_230 ;
V_286 += V_294 ;
}
}
static void
F_145 ( void * V_295 , struct V_103 * V_29 )
{
struct V_260 * V_261 = (struct V_260 * ) V_295 ;
F_146 ( & V_261 -> V_296 ) ;
}
static void
F_147 ( void * V_295 )
{
struct V_260 * V_261 = (struct V_260 * ) V_295 ;
if ( V_261 -> V_145 )
V_261 -> V_145 ( & V_261 -> V_35 -> V_210 ) ;
V_261 -> V_145 = NULL ;
}
static void
F_148 ( struct V_103 * V_29 )
{
V_29 -> V_297 |= V_298 ;
if ( V_29 -> V_297 & V_299 )
F_62 ( V_29 , V_185 ) ;
}
static void
F_149 ( struct V_103 * V_29 )
{
V_29 -> V_297 &= ~ V_298 ;
if ( V_29 -> V_300 == ( V_301 ) F_104 )
F_145 ( & V_29 -> V_35 -> V_261 , V_29 ) ;
else {
V_29 -> V_145 = F_145 ;
V_29 -> V_146 = & V_29 -> V_35 -> V_261 ;
F_62 ( V_29 , V_187 ) ;
}
}
static void
F_150 ( struct V_103 * V_29 )
{
V_29 -> V_297 &= ~ V_298 ;
F_62 ( V_29 , V_188 ) ;
}
void
F_151 ( struct V_260 * V_261 , enum V_269 type )
{
struct V_103 * V_29 ;
V_261 -> V_302 |= V_303 ;
if ( type == V_304 )
V_261 -> V_302 |= V_305 ;
F_33 (rx, &rx_mod->rx_active_q, qe)
if ( V_29 -> type == type )
F_148 ( V_29 ) ;
}
void
F_152 ( struct V_260 * V_261 , enum V_269 type )
{
struct V_103 * V_29 ;
V_261 -> V_302 &= ~ V_303 ;
V_261 -> V_302 &= ~ V_305 ;
V_261 -> V_145 = V_306 ;
F_153 ( & V_261 -> V_296 , F_147 , V_261 ) ;
F_33 (rx, &rx_mod->rx_active_q, qe)
if ( V_29 -> type == type ) {
F_154 ( & V_261 -> V_296 ) ;
F_149 ( V_29 ) ;
}
F_155 ( & V_261 -> V_296 ) ;
}
void
F_156 ( struct V_260 * V_261 )
{
struct V_103 * V_29 ;
V_261 -> V_302 &= ~ V_303 ;
V_261 -> V_302 &= ~ V_305 ;
F_33 (rx, &rx_mod->rx_active_q, qe)
F_150 ( V_29 ) ;
}
void F_157 ( struct V_260 * V_261 , struct V_35 * V_35 ,
struct V_118 * V_119 )
{
int V_170 ;
struct V_103 * V_307 ;
struct V_104 * V_308 ;
struct V_204 * V_309 ;
V_261 -> V_35 = V_35 ;
V_261 -> V_302 = 0 ;
V_261 -> V_29 = (struct V_103 * )
V_119 [ V_310 ] . V_126 . V_127 . V_128 [ 0 ] . V_129 ;
V_261 -> V_105 = (struct V_104 * )
V_119 [ V_311 ] . V_126 . V_127 . V_128 [ 0 ] . V_129 ;
V_261 -> V_266 = (struct V_204 * )
V_119 [ V_312 ] . V_126 . V_127 . V_128 [ 0 ] . V_129 ;
F_68 ( & V_261 -> V_270 ) ;
V_261 -> V_262 = 0 ;
F_68 ( & V_261 -> V_267 ) ;
V_261 -> V_264 = 0 ;
F_68 ( & V_261 -> V_268 ) ;
V_261 -> V_263 = 0 ;
F_68 ( & V_261 -> V_271 ) ;
for ( V_170 = 0 ; V_170 < V_35 -> V_313 . V_314 . V_315 ; V_170 ++ ) {
V_307 = & V_261 -> V_29 [ V_170 ] ;
F_68 ( & V_307 -> V_212 ) ;
V_307 -> V_35 = NULL ;
V_307 -> V_30 = V_170 ;
V_307 -> V_145 = NULL ;
V_307 -> V_146 = NULL ;
F_38 ( & V_307 -> V_88 , & V_261 -> V_270 ) ;
V_261 -> V_262 ++ ;
}
for ( V_170 = 0 ; V_170 < V_35 -> V_313 . V_314 . V_315 ; V_170 ++ ) {
V_308 = & V_261 -> V_105 [ V_170 ] ;
F_38 ( & V_308 -> V_88 , & V_261 -> V_268 ) ;
V_261 -> V_263 ++ ;
}
for ( V_170 = 0 ; V_170 < ( V_35 -> V_313 . V_314 . V_315 * 2 ) ; V_170 ++ ) {
V_309 = & V_261 -> V_266 [ V_170 ] ;
F_38 ( & V_309 -> V_88 , & V_261 -> V_267 ) ;
V_261 -> V_264 ++ ;
}
}
void
F_158 ( struct V_260 * V_261 )
{
V_261 -> V_35 = NULL ;
}
void
F_159 ( struct V_103 * V_29 , struct V_110 * V_111 )
{
struct V_316 * V_317 = & V_29 -> V_25 . V_317 ;
struct V_104 * V_105 = NULL ;
struct V_204 * V_205 = NULL , * V_206 = NULL ;
int V_53 ;
F_160 ( & V_29 -> V_35 -> V_36 , ( T_1 * ) V_317 ,
sizeof( struct V_316 ) ) ;
V_29 -> V_318 = V_317 -> V_318 ;
for ( V_53 = 0 , V_105 = F_44 ( & V_29 -> V_212 , struct V_104 , V_88 ) ;
V_53 < V_29 -> V_130 ; V_53 ++ , V_105 = F_124 ( V_105 , V_88 ) ) {
F_125 ( V_105 , V_205 , V_206 ) ;
V_105 -> V_107 . V_108 -> V_319 -> V_320 =
V_29 -> V_35 -> V_321 . V_322
+ F_161 ( V_317 -> V_323 [ V_53 ] . V_319 ) ;
V_105 -> V_318 = V_317 -> V_323 [ V_53 ] . V_324 ;
V_205 -> V_291 -> V_325 =
V_29 -> V_35 -> V_321 . V_322
+ F_161 ( V_317 -> V_323 [ V_53 ] . V_326 ) ;
V_205 -> V_318 = V_317 -> V_323 [ V_53 ] . V_327 ;
if ( V_206 ) {
V_206 -> V_291 -> V_325 =
V_29 -> V_35 -> V_321 . V_322
+ F_161 ( V_317 -> V_323 [ V_53 ] . V_328 ) ;
V_206 -> V_318 = V_317 -> V_323 [ V_53 ] . V_329 ;
}
( * V_105 -> V_107 . V_108 -> V_330 ) = 0 ;
V_105 -> V_107 . V_108 -> V_331 = 0 ;
V_205 -> V_291 -> V_331 = V_205 -> V_291 -> V_332 = 0 ;
if ( V_206 )
V_206 -> V_291 -> V_331 = V_206 -> V_291 -> V_332 = 0 ;
}
F_62 ( V_29 , V_192 ) ;
}
void
F_162 ( struct V_103 * V_29 , struct V_110 * V_111 )
{
F_62 ( V_29 , V_189 ) ;
}
void
F_163 ( struct V_116 * V_215 , struct V_118 * V_119 )
{
V_6 V_333 , V_334 , V_335 ;
V_6 V_336 , V_337 , V_338 ;
struct V_339 * V_127 ;
V_6 V_340 ;
V_6 V_341 ;
V_6 V_342 ;
V_342 = V_215 -> V_343 ;
V_341 = ( ( V_215 -> V_265 == V_221 ) ? 0 : V_215 -> V_344 ) ;
V_340 = F_164 ( V_342 + V_341 ) ;
V_333 = V_340 * V_345 ;
V_333 = F_165 ( V_333 , V_294 ) ;
V_336 = F_166 ( V_333 ) ;
V_342 = F_164 ( V_342 ) ;
V_335 = V_342 * V_346 ;
V_335 = F_165 ( V_335 , V_294 ) ;
V_338 = F_166 ( V_335 ) ;
if ( V_221 != V_215 -> V_265 ) {
V_341 = F_164 ( V_341 ) ;
V_334 = V_341 * V_346 ;
V_334 = F_165 ( V_334 , V_294 ) ;
V_337 = F_166 ( V_334 ) ;
} else
V_337 = 0 ;
V_119 [ V_347 ] . V_348 = V_349 ;
V_127 = & V_119 [ V_347 ] . V_126 . V_127 ;
V_127 -> V_350 = V_351 ;
V_127 -> V_352 = sizeof( struct V_353 ) ;
V_127 -> V_354 = V_215 -> V_130 ;
V_119 [ V_355 ] . V_348 = V_349 ;
V_127 = & V_119 [ V_355 ] . V_126 . V_127 ;
V_127 -> V_350 = V_351 ;
V_127 -> V_352 = sizeof( struct V_356 ) ;
V_127 -> V_354 = F_167 ( V_215 ) ;
V_119 [ V_357 ] . V_348 = V_349 ;
V_127 = & V_119 [ V_357 ] . V_126 . V_127 ;
V_127 -> V_350 = V_358 ;
V_127 -> V_352 = V_336 * sizeof( struct V_287 ) ;
V_127 -> V_354 = V_215 -> V_130 ;
V_119 [ V_359 ] . V_348 = V_349 ;
V_127 = & V_119 [ V_359 ] . V_126 . V_127 ;
V_127 -> V_350 = V_351 ;
V_127 -> V_352 = V_336 * sizeof( void * ) ;
V_127 -> V_354 = V_215 -> V_130 ;
V_119 [ V_360 ] . V_348 = V_349 ;
V_127 = & V_119 [ V_360 ] . V_126 . V_127 ;
V_127 -> V_350 = V_358 ;
V_127 -> V_352 = V_294 * V_336 ;
V_127 -> V_354 = V_215 -> V_130 ;
V_119 [ V_361 ] . V_348 = V_349 ;
V_127 = & V_119 [ V_361 ] . V_126 . V_127 ;
V_127 -> V_350 = V_358 ;
V_127 -> V_352 = V_338 * sizeof( struct V_287 ) ;
V_127 -> V_354 = V_215 -> V_130 ;
V_119 [ V_362 ] . V_348 = V_349 ;
V_127 = & V_119 [ V_362 ] . V_126 . V_127 ;
V_127 -> V_350 = V_351 ;
V_127 -> V_352 = V_338 * sizeof( void * ) ;
V_127 -> V_354 = V_215 -> V_130 ;
V_119 [ V_363 ] . V_348 = V_349 ;
V_127 = & V_119 [ V_363 ] . V_126 . V_127 ;
V_127 -> V_350 = V_358 ;
V_127 -> V_352 = V_294 * V_338 ;
V_127 -> V_354 = V_215 -> V_130 ;
V_119 [ V_364 ] . V_348 = V_349 ;
V_127 = & V_119 [ V_364 ] . V_126 . V_127 ;
V_127 -> V_350 = V_358 ;
V_127 -> V_352 = V_337 * sizeof( struct V_287 ) ;
V_127 -> V_354 = ( V_337 ? V_215 -> V_130 : 0 ) ;
V_119 [ V_365 ] . V_348 = V_349 ;
V_127 = & V_119 [ V_365 ] . V_126 . V_127 ;
V_127 -> V_350 = V_351 ;
V_127 -> V_352 = V_337 * sizeof( void * ) ;
V_127 -> V_354 = ( V_337 ? V_215 -> V_130 : 0 ) ;
V_119 [ V_366 ] . V_348 = V_349 ;
V_127 = & V_119 [ V_366 ] . V_126 . V_127 ;
V_127 -> V_350 = V_358 ;
V_127 -> V_352 = V_294 * V_337 ;
V_127 -> V_354 = ( V_337 ? V_215 -> V_130 : 0 ) ;
V_119 [ V_367 ] . V_348 = V_349 ;
V_127 = & V_119 [ V_367 ] . V_126 . V_127 ;
V_127 -> V_350 = V_358 ;
V_127 -> V_352 = V_368 ;
V_127 -> V_354 = V_215 -> V_130 ;
V_119 [ V_125 ] . V_348 = V_349 ;
V_127 = & V_119 [ V_125 ] . V_126 . V_127 ;
V_127 -> V_350 = V_351 ;
V_127 -> V_352 = V_369 ;
V_127 -> V_354 = 1 ;
V_119 [ V_370 ] . V_348 = V_371 ;
V_119 [ V_370 ] . V_126 . V_372 . V_240 = V_241 ;
V_119 [ V_370 ] . V_126 . V_372 . V_354 = V_215 -> V_130 ;
}
struct V_103 *
F_168 ( struct V_35 * V_35 , struct V_152 * V_152 ,
struct V_116 * V_208 ,
const struct V_373 * V_374 ,
struct V_118 * V_119 ,
void * V_375 )
{
struct V_260 * V_261 = & V_35 -> V_261 ;
struct V_103 * V_29 ;
struct V_104 * V_105 ;
struct V_204 * V_205 ;
struct V_204 * V_206 ;
struct V_376 * V_372 ;
struct V_282 * V_377 ;
struct V_282 * V_378 ;
struct V_282 * V_379 ;
struct V_282 * V_380 ;
struct V_282 * V_381 ;
struct V_282 * V_382 ;
struct V_282 * V_383 ;
struct V_282 * V_384 ;
struct V_282 * V_385 ;
struct V_282 * V_386 ;
struct V_282 * V_387 ;
struct V_282 * V_388 ;
struct V_282 * V_389 ;
V_6 V_338 , V_337 ;
V_6 V_390 , V_391 , V_392 ;
V_6 V_340 , V_53 ;
V_6 V_280 ;
if ( ! F_130 ( V_261 , V_208 ) )
return NULL ;
V_372 = & V_119 [ V_370 ] . V_126 . V_372 ;
V_379 = & V_119 [ V_347 ] . V_126 . V_127 . V_128 [ 0 ] ;
V_380 = & V_119 [ V_355 ] . V_126 . V_127 . V_128 [ 0 ] ;
V_378 = & V_119 [ V_393 ] . V_126 . V_127 . V_128 [ 0 ] ;
V_377 = & V_119 [ V_394 ] . V_126 . V_127 . V_128 [ 0 ] ;
V_381 = & V_119 [ V_357 ] . V_126 . V_127 . V_128 [ 0 ] ;
V_382 = & V_119 [ V_359 ] . V_126 . V_127 . V_128 [ 0 ] ;
V_383 = & V_119 [ V_360 ] . V_126 . V_127 . V_128 [ 0 ] ;
V_384 = & V_119 [ V_364 ] . V_126 . V_127 . V_128 [ 0 ] ;
V_385 = & V_119 [ V_361 ] . V_126 . V_127 . V_128 [ 0 ] ;
V_386 = & V_119 [ V_365 ] . V_126 . V_127 . V_128 [ 0 ] ;
V_387 = & V_119 [ V_362 ] . V_126 . V_127 . V_128 [ 0 ] ;
V_388 = & V_119 [ V_366 ] . V_126 . V_127 . V_128 [ 0 ] ;
V_389 = & V_119 [ V_363 ] . V_126 . V_127 . V_128 [ 0 ] ;
V_280 = V_119 [ V_360 ] . V_126 . V_127 . V_352 /
V_294 ;
V_338 = V_119 [ V_363 ] . V_126 . V_127 . V_352 /
V_294 ;
V_337 = V_119 [ V_366 ] . V_126 . V_127 . V_352 /
V_294 ;
V_29 = F_135 ( V_261 , V_208 -> V_395 ) ;
V_29 -> V_35 = V_35 ;
V_29 -> V_297 = 0 ;
F_68 ( & V_29 -> V_212 ) ;
V_29 -> V_145 = NULL ;
V_29 -> V_146 = NULL ;
V_29 -> V_375 = V_375 ;
V_29 -> V_396 = V_374 -> V_396 ;
V_29 -> V_397 = V_374 -> V_397 ;
V_29 -> V_398 = V_374 -> V_398 ;
V_29 -> V_399 = V_374 -> V_399 ;
V_29 -> V_400 = V_374 -> V_400 ;
V_29 -> V_191 = V_374 -> V_191 ;
V_29 -> V_195 = V_374 -> V_195 ;
if ( V_29 -> V_35 -> V_261 . V_302 & V_303 ) {
switch ( V_29 -> type ) {
case V_197 :
if ( ! ( V_29 -> V_35 -> V_261 . V_302 &
V_305 ) )
V_29 -> V_297 |= V_298 ;
break;
case V_304 :
if ( V_29 -> V_35 -> V_261 . V_302 & V_305 )
V_29 -> V_297 |= V_298 ;
break;
}
}
V_29 -> V_130 = V_208 -> V_130 ;
for ( V_53 = 0 , V_390 = 0 , V_391 = 0 , V_392 = 0 ;
V_53 < V_29 -> V_130 ; V_53 ++ ) {
V_105 = F_133 ( V_261 ) ;
F_38 ( & V_105 -> V_88 , & V_29 -> V_212 ) ;
V_105 -> type = V_208 -> V_265 ;
V_105 -> V_29 = V_29 ;
V_105 -> V_107 . V_29 = V_29 ;
V_205 = F_131 ( V_261 ) ;
if ( V_221 == V_208 -> V_265 )
V_206 = NULL ;
else
V_206 = F_131 ( V_261 ) ;
if ( 1 == V_372 -> V_354 )
V_105 -> V_401 = V_372 -> V_402 [ 0 ] . V_401 ;
else
V_105 -> V_401 = V_372 -> V_402 [ V_53 ] . V_401 ;
V_105 -> V_107 . V_2 . V_227 . V_228 =
V_119 [ V_367 ] . V_126 . V_127 . V_128 [ V_53 ] . V_286 . V_228 ;
V_105 -> V_107 . V_2 . V_227 . V_230 =
V_119 [ V_367 ] . V_126 . V_127 . V_128 [ V_53 ] . V_286 . V_230 ;
V_105 -> V_107 . V_2 . V_403 =
V_119 [ V_367 ] . V_126 . V_127 . V_128 [ V_53 ] . V_129 ;
V_105 -> V_107 . V_2 . V_240 = V_372 -> V_240 ;
if ( V_372 -> V_240 == V_241 )
V_105 -> V_107 . V_2 . V_233 = V_105 -> V_401 ;
else
V_105 -> V_107 . V_2 . V_233 = F_48 ( V_105 -> V_401 ) ;
V_105 -> V_107 . V_2 . V_3 = V_208 -> V_3 ;
V_105 -> V_107 . V_2 . V_246 = V_404 ;
V_105 -> V_107 . V_2 . V_244 = V_405 ;
F_140 ( V_105 , V_205 , V_206 ) ;
V_205 -> V_29 = V_29 ;
V_205 -> V_105 = V_105 ;
V_205 -> V_291 = (struct V_356 * ) V_380 [ V_392 ] . V_129 ;
V_205 -> V_291 -> V_406 = ( void * ) V_378 [ V_391 ] . V_129 ;
V_392 ++ ; V_391 ++ ;
V_205 -> V_291 -> V_407 = V_208 -> V_343 ;
V_205 -> V_407 = V_208 -> V_343 ;
V_205 -> V_223 = V_208 -> V_408 ;
V_205 -> V_220 = V_208 -> V_409 ;
V_205 -> V_410 = V_208 -> V_411 ;
V_205 -> V_291 -> V_266 = V_205 ;
V_205 -> V_291 -> V_152 = V_35 -> V_152 ;
V_205 -> V_291 -> V_109 = 0 ;
V_205 -> V_412 = V_205 -> V_413 = 0 ;
V_205 -> V_414 = V_205 -> V_415 = 0 ;
V_205 -> V_416 = 0 ;
F_141 ( V_205 , V_105 , V_338 , V_294 ,
& V_385 [ V_53 ] , & V_387 [ V_53 ] , & V_389 [ V_53 ] ) ;
if ( V_29 -> V_396 )
V_29 -> V_396 ( V_152 , V_205 -> V_291 ) ;
if ( V_206 ) {
V_206 -> V_29 = V_29 ;
V_206 -> V_105 = V_105 ;
V_206 -> V_291 = (struct V_356 * ) V_380 [ V_392 ] . V_129 ;
V_206 -> V_291 -> V_406 = ( void * ) V_377 [ V_390 ] . V_129 ;
V_392 ++ ; V_390 ++ ;
V_206 -> V_291 -> V_407 = V_208 -> V_344 ;
V_206 -> V_407 = V_208 -> V_344 ;
V_206 -> V_223 = V_132 ;
V_206 -> V_410 = 1 ;
V_206 -> V_291 -> V_266 = V_206 ;
V_206 -> V_291 -> V_152 = V_35 -> V_152 ;
V_206 -> V_291 -> V_109 = 1 ;
V_206 -> V_220 = ( V_208 -> V_265 == V_214 ) ?
V_208 -> V_417 . V_254
: V_208 -> V_418 ;
V_206 -> V_412 = V_206 -> V_413 = 0 ;
V_206 -> V_414 = V_206 -> V_415 = 0 ;
V_206 -> V_416 = 0 ;
F_141 ( V_206 , V_105 , V_337 , V_294 ,
& V_384 [ V_53 ] , & V_386 [ V_53 ] ,
& V_388 [ V_53 ] ) ;
if ( V_29 -> V_396 )
V_29 -> V_396 ( V_152 , V_206 -> V_291 ) ;
}
V_105 -> V_107 . V_108 = (struct V_353 * ) V_379 [ V_53 ] . V_129 ;
V_340 = V_208 -> V_343 +
( ( V_208 -> V_265 == V_221 ) ?
0 : V_208 -> V_344 ) ;
V_340 = F_164 ( V_340 ) ;
V_105 -> V_107 . V_108 -> V_407 = V_340 ;
V_105 -> V_107 . V_108 -> V_107 = & V_105 -> V_107 ;
V_105 -> V_107 . V_108 -> V_291 [ 0 ] = V_205 -> V_291 ;
V_205 -> V_291 -> V_108 = V_105 -> V_107 . V_108 ;
if ( V_206 ) {
V_105 -> V_107 . V_108 -> V_291 [ 1 ] = V_206 -> V_291 ;
V_206 -> V_291 -> V_108 = V_105 -> V_107 . V_108 ;
}
V_105 -> V_107 . V_108 -> V_330 =
( V_6 * ) V_105 -> V_107 . V_2 . V_403 ;
V_105 -> V_107 . V_108 -> V_319 = & V_105 -> V_107 . V_2 . V_4 ;
V_105 -> V_107 . V_108 -> V_240 = V_105 -> V_107 . V_2 . V_240 ;
V_105 -> V_107 . V_108 -> V_233 = V_105 -> V_107 . V_2 . V_233 ;
V_105 -> V_107 . V_108 -> V_419 =
V_105 -> V_107 . V_2 . V_3 ;
V_105 -> V_107 . V_108 -> V_420 . V_421 = 0 ;
V_105 -> V_107 . V_108 -> V_420 . V_422 = 0 ;
V_105 -> V_107 . V_108 -> V_152 = V_35 -> V_152 ;
V_105 -> V_107 . V_108 -> V_109 = V_53 ;
F_144 ( V_105 , V_280 , V_294 ,
& V_381 [ V_53 ] , & V_382 [ V_53 ] , & V_383 [ V_53 ] ) ;
if ( V_29 -> V_398 )
V_29 -> V_398 ( V_152 , V_105 -> V_107 . V_108 ) ;
}
V_29 -> V_251 = V_208 -> V_417 ;
F_67 ( & V_29 -> V_8 , V_29 , V_208 , V_119 ) ;
F_6 ( V_29 , F_104 ) ;
V_261 -> V_423 |= F_48 ( V_29 -> V_30 ) ;
return V_29 ;
}
void
F_169 ( struct V_103 * V_29 )
{
struct V_260 * V_261 = & V_29 -> V_35 -> V_261 ;
struct V_204 * V_205 = NULL ;
struct V_204 * V_206 = NULL ;
struct V_104 * V_105 ;
struct V_159 * V_88 ;
F_69 ( & V_29 -> V_8 ) ;
while ( ! F_43 ( & V_29 -> V_212 ) ) {
V_105 = F_44 ( & V_29 -> V_212 , struct V_104 , V_88 ) ;
F_40 ( & V_105 -> V_88 ) ;
F_125 ( V_105 , V_205 , V_206 ) ;
if ( V_29 -> V_397 )
V_29 -> V_397 ( V_29 -> V_35 -> V_152 , V_205 -> V_291 ) ;
V_205 -> V_291 = NULL ;
V_205 -> V_105 = NULL ;
V_205 -> V_29 = NULL ;
F_132 ( V_261 , V_205 ) ;
if ( V_206 ) {
if ( V_29 -> V_397 )
V_29 -> V_397 ( V_29 -> V_35 -> V_152 , V_206 -> V_291 ) ;
V_206 -> V_291 = NULL ;
V_206 -> V_105 = NULL ;
V_206 -> V_29 = NULL ;
F_132 ( V_261 , V_206 ) ;
}
V_105 -> V_266 . V_275 . V_276 = NULL ;
V_105 -> V_266 . V_275 . V_277 = NULL ;
if ( V_29 -> V_399 )
V_29 -> V_399 ( V_29 -> V_35 -> V_152 , V_105 -> V_107 . V_108 ) ;
V_105 -> V_107 . V_108 = NULL ;
V_105 -> V_29 = NULL ;
F_134 ( V_261 , V_105 ) ;
}
F_170 (qe, &rx_mod->rx_active_q)
if ( V_88 == & V_29 -> V_88 ) {
F_40 ( & V_29 -> V_88 ) ;
break;
}
V_261 -> V_423 &= ~ F_48 ( V_29 -> V_30 ) ;
V_29 -> V_35 = NULL ;
V_29 -> V_375 = NULL ;
F_137 ( V_261 , V_29 ) ;
}
void
F_171 ( struct V_103 * V_29 )
{
if ( V_29 -> V_300 != ( V_424 ) F_104 )
return;
V_29 -> V_297 |= V_299 ;
if ( V_29 -> V_297 & V_298 )
F_62 ( V_29 , V_185 ) ;
}
void
F_172 ( struct V_103 * V_29 , enum V_90 type ,
void (* F_80)( void * , struct V_103 * ) )
{
if ( type == V_102 ) {
(* F_80)( V_29 -> V_35 -> V_152 , V_29 ) ;
} else {
V_29 -> V_145 = F_80 ;
V_29 -> V_146 = V_29 -> V_35 -> V_152 ;
V_29 -> V_297 &= ~ V_299 ;
F_62 ( V_29 , V_187 ) ;
}
}
void
F_173 ( struct V_103 * V_29 )
{
F_62 ( V_29 , V_200 ) ;
}
void
F_174 ( struct V_103 * V_29 )
{
struct V_7 * V_8 = & V_29 -> V_8 ;
if ( V_8 -> V_62 == V_132 ) {
V_8 -> V_62 = V_58 ;
V_8 -> V_140 = true ;
F_62 ( V_8 , V_15 ) ;
}
}
void
F_175 ( struct V_103 * V_29 )
{
struct V_7 * V_8 = & V_29 -> V_8 ;
if ( V_8 -> V_62 != V_132 ) {
V_8 -> V_62 = V_132 ;
V_8 -> V_140 = true ;
F_62 ( V_8 , V_15 ) ;
}
}
enum V_147
F_176 ( struct V_103 * V_29 , enum V_425 V_426 ,
enum V_425 V_427 )
{
struct V_7 * V_8 = & V_29 -> V_8 ;
int V_168 = 0 ;
if ( F_88 ( V_426 , V_427 ) ) {
if ( ( V_29 -> V_35 -> V_137 != V_138 ) &&
( V_29 -> V_35 -> V_137 != V_8 -> V_29 -> V_30 ) )
goto V_164;
if ( V_29 -> V_35 -> V_139 != V_138 )
goto V_164;
if ( F_177 ( V_426 , V_427 ) )
goto V_164;
}
if ( F_177 ( V_426 , V_427 ) ) {
if ( ( V_29 -> V_35 -> V_139 != V_138 ) &&
( V_29 -> V_35 -> V_139 != V_8 -> V_29 -> V_30 ) ) {
goto V_164;
}
if ( V_29 -> V_35 -> V_137 != V_138 )
goto V_164;
}
if ( F_88 ( V_426 , V_427 ) ) {
if ( F_96 ( V_8 ) )
V_168 = 1 ;
} else if ( F_90 ( V_426 , V_427 ) ) {
if ( F_97 ( V_8 ) )
V_168 = 1 ;
}
if ( F_92 ( V_426 , V_427 ) ) {
if ( F_99 ( V_8 ) )
V_168 = 1 ;
} else if ( F_94 ( V_426 , V_427 ) ) {
if ( F_100 ( V_8 ) )
V_168 = 1 ;
}
if ( V_168 ) {
V_8 -> V_150 = NULL ;
V_8 -> V_151 = V_29 -> V_35 -> V_152 ;
F_62 ( V_8 , V_15 ) ;
}
return V_153 ;
V_164:
return V_428 ;
}
void
F_178 ( struct V_103 * V_29 )
{
struct V_7 * V_8 = & V_29 -> V_8 ;
if ( V_8 -> V_57 == V_132 ) {
V_8 -> V_57 = V_58 ;
V_8 -> V_97 = ( T_1 ) V_134 ;
F_62 ( V_8 , V_15 ) ;
}
}
void
F_179 ( struct V_103 * V_29 , int V_3 )
{
struct V_104 * V_105 ;
F_33 (rxp, &rx->rxp_q, qe) {
V_105 -> V_107 . V_108 -> V_419 = V_3 ;
F_1 ( & V_105 -> V_107 . V_2 , V_3 ) ;
}
}
void
F_180 ( struct V_35 * V_35 , const V_6 V_401 [] [ V_429 ] )
{
int V_53 , V_54 ;
for ( V_53 = 0 ; V_53 < V_430 ; V_53 ++ )
for ( V_54 = 0 ; V_54 < V_429 ; V_54 ++ )
V_35 -> V_261 . V_431 [ V_53 ] [ V_54 ] = V_401 [ V_53 ] [ V_54 ] ;
}
void
F_181 ( struct V_353 * V_108 )
{
struct V_35 * V_35 = V_108 -> V_107 -> V_29 -> V_35 ;
V_6 V_432 , V_433 ;
V_6 V_434 , V_435 , V_436 ;
T_1 V_3 ;
if ( ( V_108 -> V_420 . V_421 == 0 ) &&
( V_108 -> V_420 . V_422 == 0 ) )
return;
V_435 = V_108 -> V_420 . V_421 ;
V_436 = V_108 -> V_420 . V_422 ;
V_434 = V_435 + V_436 ;
if ( V_434 < V_437 )
V_432 = V_438 ;
else if ( V_434 < V_439 )
V_432 = V_440 ;
else if ( V_434 < V_441 )
V_432 = V_442 ;
else if ( V_434 < V_443 )
V_432 = V_444 ;
else if ( V_434 < V_445 )
V_432 = V_446 ;
else if ( V_434 < V_447 )
V_432 = V_448 ;
else if ( V_434 < V_449 )
V_432 = V_450 ;
else
V_432 = V_451 ;
if ( V_435 > ( V_436 << 1 ) )
V_433 = 0 ;
else
V_433 = 1 ;
V_108 -> V_420 . V_421 = 0 ;
V_108 -> V_420 . V_422 = 0 ;
V_3 = V_35 -> V_261 . V_431 [ V_432 ] [ V_433 ] ;
V_108 -> V_419 = V_3 ;
F_1 ( & V_108 -> V_107 -> V_2 , V_3 ) ;
}
static void
F_182 ( struct V_452 * V_453 )
{
F_183 ( V_453 ) ;
}
static void
F_184 ( struct V_452 * V_453 , enum V_454 V_10 )
{
switch ( V_10 ) {
case V_455 :
F_6 ( V_453 , V_456 ) ;
break;
case V_457 :
F_183 ( V_453 ) ;
break;
case V_458 :
break;
case V_459 :
break;
default:
F_8 ( V_10 ) ;
}
}
static void
F_185 ( struct V_452 * V_453 )
{
F_186 ( V_453 ) ;
}
static void
V_456 ( struct V_452 * V_453 , enum V_454 V_10 )
{
switch ( V_10 ) {
case V_457 :
V_453 -> V_302 &= ~ V_460 ;
F_6 ( V_453 , V_461 ) ;
break;
case V_458 :
V_453 -> V_302 &= ~ V_460 ;
F_6 ( V_453 , F_184 ) ;
break;
case V_462 :
if ( V_453 -> V_302 & V_460 ) {
V_453 -> V_302 &= ~ V_460 ;
F_6 ( V_453 , V_463 ) ;
} else
F_6 ( V_453 , V_464 ) ;
break;
case V_459 :
V_453 -> V_302 |= V_460 ;
break;
default:
F_8 ( V_10 ) ;
}
}
static void
F_187 ( struct V_452 * V_453 )
{
struct V_465 * V_466 ;
int V_196 = ( V_453 -> type == V_467 ) ;
F_33 (txq, &tx->txq_q, qe) {
V_466 -> V_468 -> V_469 = V_466 -> V_469 ;
F_116 ( V_453 -> V_35 , & V_466 -> V_2 , V_196 ) ;
}
V_453 -> V_470 ( V_453 -> V_35 -> V_152 , V_453 ) ;
}
static void
V_464 ( struct V_452 * V_453 , enum V_454 V_10 )
{
switch ( V_10 ) {
case V_457 :
F_6 ( V_453 , V_461 ) ;
V_453 -> V_471 ( V_453 -> V_35 -> V_152 , V_453 ) ;
F_188 ( V_453 ) ;
break;
case V_458 :
F_6 ( V_453 , V_472 ) ;
V_453 -> V_471 ( V_453 -> V_35 -> V_152 , V_453 ) ;
V_453 -> V_473 ( V_453 -> V_35 -> V_152 , V_453 ) ;
break;
case V_459 :
F_6 ( V_453 , V_463 ) ;
break;
default:
F_8 ( V_10 ) ;
}
}
static void
F_189 ( struct V_452 * V_453 )
{
}
static void
V_461 ( struct V_452 * V_453 , enum V_454 V_10 )
{
switch ( V_10 ) {
case V_458 :
case V_474 :
F_6 ( V_453 , V_475 ) ;
V_453 -> V_473 ( V_453 -> V_35 -> V_152 , V_453 ) ;
break;
case V_462 :
F_188 ( V_453 ) ;
break;
case V_459 :
break;
default:
F_8 ( V_10 ) ;
}
}
static void
F_190 ( struct V_452 * V_453 )
{
}
static void
V_475 ( struct V_452 * V_453 , enum V_454 V_10 )
{
switch ( V_10 ) {
case V_458 :
case V_459 :
break;
case V_476 :
F_6 ( V_453 , F_184 ) ;
break;
default:
F_8 ( V_10 ) ;
}
}
static void
F_191 ( struct V_452 * V_453 )
{
V_453 -> V_471 ( V_453 -> V_35 -> V_152 , V_453 ) ;
F_188 ( V_453 ) ;
}
static void
V_463 ( struct V_452 * V_453 , enum V_454 V_10 )
{
switch ( V_10 ) {
case V_457 :
F_6 ( V_453 , V_461 ) ;
break;
case V_458 :
F_6 ( V_453 , V_472 ) ;
V_453 -> V_473 ( V_453 -> V_35 -> V_152 , V_453 ) ;
break;
case V_474 :
F_6 ( V_453 , V_477 ) ;
break;
case V_459 :
break;
default:
F_8 ( V_10 ) ;
}
}
static void
F_192 ( struct V_452 * V_453 )
{
V_453 -> V_473 ( V_453 -> V_35 -> V_152 , V_453 ) ;
}
static void
V_477 ( struct V_452 * V_453 , enum V_454 V_10 )
{
switch ( V_10 ) {
case V_457 :
F_6 ( V_453 , V_475 ) ;
break;
case V_458 :
F_6 ( V_453 , V_472 ) ;
break;
case V_459 :
break;
case V_476 :
F_6 ( V_453 , V_456 ) ;
break;
default:
F_8 ( V_10 ) ;
}
}
static void
F_193 ( struct V_452 * V_453 )
{
}
static void
V_472 ( struct V_452 * V_453 , enum V_454 V_10 )
{
switch ( V_10 ) {
case V_455 :
F_6 ( V_453 , V_478 ) ;
break;
case V_457 :
F_6 ( V_453 , V_475 ) ;
break;
case V_458 :
break;
case V_476 :
F_6 ( V_453 , F_184 ) ;
break;
default:
F_8 ( V_10 ) ;
}
}
static void
F_194 ( struct V_452 * V_453 )
{
}
static void
V_478 ( struct V_452 * V_453 , enum V_454 V_10 )
{
switch ( V_10 ) {
case V_457 :
F_6 ( V_453 , V_475 ) ;
break;
case V_458 :
F_6 ( V_453 , V_472 ) ;
break;
case V_476 :
F_6 ( V_453 , V_456 ) ;
break;
case V_459 :
break;
default:
F_8 ( V_10 ) ;
}
}
static void
F_186 ( struct V_452 * V_453 )
{
struct V_479 * V_203 = & V_453 -> V_25 . V_203 ;
struct V_465 * V_466 = NULL ;
int V_53 ;
F_16 ( V_203 -> V_27 , V_28 ,
V_480 , 0 , V_453 -> V_30 ) ;
V_203 -> V_27 . V_31 = F_17 (
F_18 ( sizeof( struct V_479 ) ) ) ;
V_203 -> V_481 = V_453 -> V_482 ;
for ( V_53 = 0 ; V_53 < V_453 -> V_482 ; V_53 ++ ) {
V_466 = V_466 ? F_124 ( V_466 , V_88 )
: F_44 ( & V_453 -> V_483 , struct V_465 , V_88 ) ;
F_126 ( & V_203 -> V_215 [ V_53 ] . V_217 . V_217 , & V_466 -> V_218 ) ;
V_203 -> V_215 [ V_53 ] . V_217 . V_469 = V_466 -> V_469 ;
V_203 -> V_215 [ V_53 ] . V_2 . V_224 . V_225 . V_226 =
V_466 -> V_2 . V_227 . V_228 ;
V_203 -> V_215 [ V_53 ] . V_2 . V_224 . V_225 . V_229 =
V_466 -> V_2 . V_227 . V_230 ;
V_203 -> V_215 [ V_53 ] . V_2 . V_231 . V_232 =
F_17 ( ( T_2 ) V_466 -> V_2 . V_233 ) ;
}
V_203 -> V_234 . V_235 = V_58 ;
V_203 -> V_234 . V_236 = V_58 ;
V_203 -> V_234 . V_237 = V_132 ;
V_203 -> V_234 . V_238 = V_58 ;
V_203 -> V_234 . V_239 = ( V_466 -> V_2 . V_240 == V_241 )
? V_58 : V_132 ;
V_203 -> V_234 . V_242 =
F_27 ( ( V_6 ) V_466 -> V_2 . V_3 ) ;
V_203 -> V_234 . V_243 =
F_27 ( ( V_6 ) V_466 -> V_2 . V_244 ) ;
V_203 -> V_234 . V_245 = ( T_1 ) V_466 -> V_2 . V_246 ;
V_203 -> V_484 . V_485 = V_486 ;
V_203 -> V_484 . V_169 = F_17 ( ( T_2 ) V_453 -> V_487 ) ;
V_203 -> V_484 . V_488 = V_58 ;
V_203 -> V_484 . V_489 = V_132 ;
F_20 ( & V_453 -> V_34 , NULL , NULL ,
sizeof( struct V_479 ) , & V_203 -> V_27 ) ;
F_21 ( & V_453 -> V_35 -> V_36 , & V_453 -> V_34 ) ;
}
static void
F_195 ( struct V_452 * V_453 )
{
struct V_258 * V_24 = & V_453 -> V_25 . V_24 ;
F_16 ( V_24 -> V_27 , V_28 ,
V_490 , 0 , V_453 -> V_30 ) ;
V_24 -> V_27 . V_31 = F_17 (
F_18 ( sizeof( struct V_258 ) ) ) ;
F_20 ( & V_453 -> V_34 , NULL , NULL , sizeof( struct V_258 ) ,
& V_24 -> V_27 ) ;
F_21 ( & V_453 -> V_35 -> V_36 , & V_453 -> V_34 ) ;
}
static void
F_188 ( struct V_452 * V_453 )
{
struct V_465 * V_466 ;
F_33 (txq, &tx->txq_q, qe)
F_129 ( V_453 -> V_35 , & V_466 -> V_2 ) ;
F_195 ( V_453 ) ;
}
static void
F_196 ( struct V_465 * V_466 , int V_280 , int V_281 ,
struct V_282 * V_283 ,
struct V_282 * V_284 ,
struct V_282 * V_285 )
{
T_1 * V_129 ;
T_3 V_286 ;
struct V_287 V_288 ;
int V_53 ;
V_466 -> V_218 . V_289 . V_228 = V_283 -> V_286 . V_228 ;
V_466 -> V_218 . V_289 . V_230 = V_283 -> V_286 . V_230 ;
V_466 -> V_218 . V_290 = V_283 -> V_129 ;
V_466 -> V_218 . V_280 = V_280 ;
V_466 -> V_218 . V_281 = V_281 ;
V_466 -> V_468 -> V_292 = ( void * * ) V_284 -> V_129 ;
V_466 -> V_468 -> V_293 = V_285 -> V_129 ;
V_129 = V_285 -> V_129 ;
F_142 ( & V_285 -> V_286 , V_286 ) ;
for ( V_53 = 0 ; V_53 < V_280 ; V_53 ++ ) {
V_466 -> V_468 -> V_292 [ V_53 ] = V_129 ;
V_129 += V_294 ;
F_143 ( V_286 , & V_288 ) ;
( (struct V_287 * ) V_466 -> V_218 . V_290 ) [ V_53 ] . V_228 =
V_288 . V_228 ;
( (struct V_287 * ) V_466 -> V_218 . V_290 ) [ V_53 ] . V_230 =
V_288 . V_230 ;
V_286 += V_294 ;
}
}
static struct V_452 *
F_197 ( struct V_491 * V_492 , enum V_493 type )
{
struct V_452 * V_453 = NULL ;
if ( F_43 ( & V_492 -> V_494 ) )
return NULL ;
if ( type == V_467 )
V_453 = F_44 ( & V_492 -> V_494 , struct V_452 , V_88 ) ;
else
V_453 = F_136 ( & V_492 -> V_494 , struct V_452 , V_88 ) ;
F_40 ( & V_453 -> V_88 ) ;
V_453 -> type = type ;
return V_453 ;
}
static void
F_198 ( struct V_452 * V_453 )
{
struct V_491 * V_492 = & V_453 -> V_35 -> V_492 ;
struct V_465 * V_466 ;
struct V_159 * V_88 ;
while ( ! F_43 ( & V_453 -> V_483 ) ) {
V_466 = F_44 ( & V_453 -> V_483 , struct V_465 , V_88 ) ;
V_466 -> V_468 = NULL ;
V_466 -> V_453 = NULL ;
F_45 ( & V_466 -> V_88 , & V_492 -> V_495 ) ;
}
F_170 (qe, &tx_mod->tx_active_q) {
if ( V_88 == & V_453 -> V_88 ) {
F_40 ( & V_453 -> V_88 ) ;
break;
}
}
V_453 -> V_35 = NULL ;
V_453 -> V_375 = NULL ;
F_138 (qe, &tx_mod->tx_free_q)
if ( ( (struct V_452 * ) V_88 ) -> V_30 < V_453 -> V_30 )
break;
F_139 ( & V_453 -> V_88 , V_88 ) ;
}
static void
F_199 ( struct V_452 * V_453 )
{
V_453 -> V_302 |= V_496 ;
if ( V_453 -> V_302 & V_497 )
F_62 ( V_453 , V_455 ) ;
}
static void
F_200 ( struct V_452 * V_453 )
{
V_453 -> V_145 = V_498 ;
V_453 -> V_146 = & V_453 -> V_35 -> V_492 ;
V_453 -> V_302 &= ~ V_496 ;
F_62 ( V_453 , V_457 ) ;
}
static void
F_201 ( struct V_452 * V_453 )
{
V_453 -> V_302 &= ~ V_496 ;
F_62 ( V_453 , V_458 ) ;
}
void
F_202 ( struct V_452 * V_453 , struct V_110 * V_111 )
{
struct V_499 * V_317 = & V_453 -> V_25 . V_317 ;
struct V_465 * V_466 = NULL ;
int V_53 ;
F_160 ( & V_453 -> V_35 -> V_36 , ( T_1 * ) V_317 ,
sizeof( struct V_499 ) ) ;
V_453 -> V_318 = V_317 -> V_318 ;
for ( V_53 = 0 , V_466 = F_44 ( & V_453 -> V_483 , struct V_465 , V_88 ) ;
V_53 < V_453 -> V_482 ; V_53 ++ , V_466 = F_124 ( V_466 , V_88 ) ) {
V_466 -> V_468 -> V_319 -> V_320 =
V_453 -> V_35 -> V_321 . V_322
+ F_161 ( V_317 -> V_323 [ V_53 ] . V_319 ) ;
V_466 -> V_468 -> V_325 =
V_453 -> V_35 -> V_321 . V_322
+ F_161 ( V_317 -> V_323 [ V_53 ] . V_325 ) ;
V_466 -> V_318 = V_317 -> V_323 [ V_53 ] . V_500 ;
( * V_466 -> V_468 -> V_501 ) = 0 ;
V_466 -> V_468 -> V_331 = V_466 -> V_468 -> V_332 = 0 ;
}
F_62 ( V_453 , V_462 ) ;
}
void
F_203 ( struct V_452 * V_453 , struct V_110 * V_111 )
{
F_62 ( V_453 , V_474 ) ;
}
void
F_204 ( struct V_491 * V_492 )
{
struct V_452 * V_453 ;
F_33 (tx, &tx_mod->tx_active_q, qe)
F_62 ( V_453 , V_459 ) ;
}
void
F_205 ( int V_482 , int V_502 , struct V_118 * V_119 )
{
V_6 V_503 ;
V_6 V_280 ;
struct V_339 * V_127 ;
V_119 [ V_504 ] . V_348 = V_349 ;
V_127 = & V_119 [ V_504 ] . V_126 . V_127 ;
V_127 -> V_350 = V_351 ;
V_127 -> V_352 = sizeof( struct V_505 ) ;
V_127 -> V_354 = V_482 ;
V_503 = V_502 * V_506 ;
V_503 = F_165 ( V_503 , V_294 ) ;
V_280 = V_503 >> V_507 ;
V_119 [ V_508 ] . V_348 = V_349 ;
V_127 = & V_119 [ V_508 ] . V_126 . V_127 ;
V_127 -> V_350 = V_358 ;
V_127 -> V_352 = V_280 * sizeof( struct V_287 ) ;
V_127 -> V_354 = V_482 ;
V_119 [ V_509 ] . V_348 = V_349 ;
V_127 = & V_119 [ V_509 ] . V_126 . V_127 ;
V_127 -> V_350 = V_351 ;
V_127 -> V_352 = V_280 * sizeof( void * ) ;
V_127 -> V_354 = V_482 ;
V_119 [ V_510 ] . V_348 = V_349 ;
V_127 = & V_119 [ V_510 ] . V_126 . V_127 ;
V_127 -> V_350 = V_358 ;
V_127 -> V_352 = V_294 * V_280 ;
V_127 -> V_354 = V_482 ;
V_119 [ V_511 ] . V_348 = V_349 ;
V_127 = & V_119 [ V_511 ] . V_126 . V_127 ;
V_127 -> V_350 = V_358 ;
V_127 -> V_352 = V_368 ;
V_127 -> V_354 = V_482 ;
V_119 [ V_512 ] . V_348 = V_371 ;
V_119 [ V_512 ] . V_126 . V_372 . V_240 =
V_241 ;
V_119 [ V_512 ] . V_126 . V_372 . V_354 = V_482 ;
}
struct V_452 *
F_206 ( struct V_35 * V_35 , struct V_152 * V_152 ,
struct V_513 * V_484 ,
const struct V_514 * V_515 ,
struct V_118 * V_119 , void * V_375 )
{
struct V_376 * V_372 ;
struct V_491 * V_492 = & V_35 -> V_492 ;
struct V_452 * V_453 ;
struct V_465 * V_466 ;
int V_280 ;
int V_53 ;
V_372 = & V_119 [ V_512 ] . V_126 . V_372 ;
V_280 = ( V_119 [ V_510 ] . V_126 . V_127 . V_352 ) /
V_294 ;
if ( ( V_372 -> V_354 != 1 ) && ( V_372 -> V_354 != V_484 -> V_482 ) )
return NULL ;
V_453 = F_197 ( V_492 , V_484 -> V_516 ) ;
if ( ! V_453 )
return NULL ;
V_453 -> V_35 = V_35 ;
V_453 -> V_375 = V_375 ;
F_68 ( & V_453 -> V_483 ) ;
for ( V_53 = 0 ; V_53 < V_484 -> V_482 ; V_53 ++ ) {
if ( F_43 ( & V_492 -> V_495 ) )
goto V_164;
V_466 = F_44 ( & V_492 -> V_495 , struct V_465 , V_88 ) ;
F_45 ( & V_466 -> V_88 , & V_453 -> V_483 ) ;
V_466 -> V_453 = V_453 ;
}
V_453 -> V_517 = V_515 -> V_517 ;
V_453 -> V_518 = V_515 -> V_518 ;
V_453 -> V_471 = V_515 -> V_471 ;
V_453 -> V_470 = V_515 -> V_470 ;
V_453 -> V_473 = V_515 -> V_473 ;
F_38 ( & V_453 -> V_88 , & V_492 -> V_519 ) ;
V_453 -> V_482 = V_484 -> V_482 ;
V_453 -> V_302 = 0 ;
if ( V_453 -> V_35 -> V_492 . V_302 & V_520 ) {
switch ( V_453 -> type ) {
case V_467 :
if ( ! ( V_453 -> V_35 -> V_492 . V_302 &
V_521 ) )
V_453 -> V_302 |= V_496 ;
break;
case V_522 :
if ( V_453 -> V_35 -> V_492 . V_302 & V_521 )
V_453 -> V_302 |= V_496 ;
break;
}
}
V_53 = 0 ;
F_33 (txq, &tx->txq_q, qe) {
V_466 -> V_468 = (struct V_505 * )
V_119 [ V_504 ] . V_126 . V_127 . V_128 [ V_53 ] . V_129 ;
V_466 -> V_523 = 0 ;
V_466 -> V_524 = 0 ;
V_466 -> V_2 . V_227 . V_228 =
V_119 [ V_511 ] . V_126 . V_127 . V_128 [ V_53 ] . V_286 . V_228 ;
V_466 -> V_2 . V_227 . V_230 =
V_119 [ V_511 ] . V_126 . V_127 . V_128 [ V_53 ] . V_286 . V_230 ;
V_466 -> V_2 . V_403 =
V_119 [ V_511 ] . V_126 . V_127 . V_128 [ V_53 ] . V_129 ;
V_466 -> V_2 . V_240 = V_372 -> V_240 ;
V_466 -> V_2 . V_233 = ( V_372 -> V_354 == 1 ) ?
V_372 -> V_402 [ 0 ] . V_401 :
V_372 -> V_402 [ V_53 ] . V_401 ;
if ( V_372 -> V_240 == V_525 )
V_466 -> V_2 . V_233 = F_48 ( V_466 -> V_2 . V_233 ) ;
V_466 -> V_2 . V_3 = V_484 -> V_3 ;
V_466 -> V_2 . V_244 = V_526 ;
V_466 -> V_2 . V_246 = V_527 ;
V_466 -> V_468 -> V_407 = V_484 -> V_502 ;
V_466 -> V_468 -> V_406 = ( void * )
V_119 [ V_528 ] . V_126 . V_127 . V_128 [ V_53 ] . V_129 ;
V_466 -> V_468 -> V_501 =
( V_6 * ) V_466 -> V_2 . V_403 ;
V_466 -> V_468 -> V_319 = & V_466 -> V_2 . V_4 ;
V_466 -> V_468 -> V_240 = V_466 -> V_2 . V_240 ;
V_466 -> V_468 -> V_233 = V_466 -> V_2 . V_233 ;
V_466 -> V_468 -> V_466 = V_466 ;
V_466 -> V_468 -> V_152 = V_152 ;
V_466 -> V_468 -> V_109 = V_53 ;
F_196 ( V_466 , V_280 , V_294 ,
& V_119 [ V_508 ] . V_126 . V_127 . V_128 [ V_53 ] ,
& V_119 [ V_509 ] . V_126 . V_127 . V_128 [ V_53 ] ,
& V_119 [ V_510 ] .
V_126 . V_127 . V_128 [ V_53 ] ) ;
if ( V_453 -> V_517 )
( V_453 -> V_517 ) ( V_35 -> V_152 , V_466 -> V_468 ) ;
if ( V_484 -> V_482 == V_529 )
V_466 -> V_469 = V_466 -> V_468 -> V_109 ;
else
V_466 -> V_469 = V_492 -> V_530 ;
V_53 ++ ;
}
V_453 -> V_487 = 0 ;
F_6 ( V_453 , F_184 ) ;
V_492 -> V_423 |= F_48 ( V_453 -> V_30 ) ;
return V_453 ;
V_164:
F_198 ( V_453 ) ;
return NULL ;
}
void
F_207 ( struct V_452 * V_453 )
{
struct V_465 * V_466 ;
F_33 (txq, &tx->txq_q, qe)
if ( V_453 -> V_518 )
( V_453 -> V_518 ) ( V_453 -> V_35 -> V_152 , V_466 -> V_468 ) ;
V_453 -> V_35 -> V_492 . V_423 &= ~ F_48 ( V_453 -> V_30 ) ;
F_198 ( V_453 ) ;
}
void
F_208 ( struct V_452 * V_453 )
{
if ( V_453 -> V_300 != ( V_424 ) F_184 )
return;
V_453 -> V_302 |= V_497 ;
if ( V_453 -> V_302 & V_496 )
F_62 ( V_453 , V_455 ) ;
}
void
F_209 ( struct V_452 * V_453 , enum V_90 type ,
void (* F_80)( void * , struct V_452 * ) )
{
if ( type == V_102 ) {
(* F_80)( V_453 -> V_35 -> V_152 , V_453 ) ;
return;
}
V_453 -> V_145 = F_80 ;
V_453 -> V_146 = V_453 -> V_35 -> V_152 ;
V_453 -> V_302 &= ~ V_497 ;
F_62 ( V_453 , V_457 ) ;
}
void
F_210 ( struct V_452 * V_453 )
{
F_62 ( V_453 , V_476 ) ;
}
static void
V_498 ( void * V_295 , struct V_452 * V_453 )
{
struct V_491 * V_492 = (struct V_491 * ) V_295 ;
F_146 ( & V_492 -> V_531 ) ;
}
static void
F_211 ( void * V_295 )
{
struct V_491 * V_492 = (struct V_491 * ) V_295 ;
if ( V_492 -> V_145 )
V_492 -> V_145 ( & V_492 -> V_35 -> V_210 ) ;
V_492 -> V_145 = NULL ;
}
void
F_212 ( struct V_491 * V_492 , struct V_35 * V_35 ,
struct V_118 * V_119 )
{
int V_53 ;
V_492 -> V_35 = V_35 ;
V_492 -> V_302 = 0 ;
V_492 -> V_453 = (struct V_452 * )
V_119 [ V_532 ] . V_126 . V_127 . V_128 [ 0 ] . V_129 ;
V_492 -> V_466 = (struct V_465 * )
V_119 [ V_533 ] . V_126 . V_127 . V_128 [ 0 ] . V_129 ;
F_68 ( & V_492 -> V_494 ) ;
F_68 ( & V_492 -> V_519 ) ;
F_68 ( & V_492 -> V_495 ) ;
for ( V_53 = 0 ; V_53 < V_35 -> V_313 . V_314 . V_482 ; V_53 ++ ) {
V_492 -> V_453 [ V_53 ] . V_30 = V_53 ;
F_38 ( & V_492 -> V_453 [ V_53 ] . V_88 , & V_492 -> V_494 ) ;
F_38 ( & V_492 -> V_466 [ V_53 ] . V_88 , & V_492 -> V_495 ) ;
}
V_492 -> V_534 = V_535 ;
V_492 -> V_530 = 0 ;
V_492 -> V_536 = V_132 ;
V_492 -> V_537 = - 1 ;
}
void
F_213 ( struct V_491 * V_492 )
{
V_492 -> V_35 = NULL ;
}
void
F_214 ( struct V_491 * V_492 , enum V_493 type )
{
struct V_452 * V_453 ;
V_492 -> V_302 |= V_520 ;
if ( type == V_522 )
V_492 -> V_302 |= V_521 ;
F_33 (tx, &tx_mod->tx_active_q, qe)
if ( V_453 -> type == type )
F_199 ( V_453 ) ;
}
void
F_215 ( struct V_491 * V_492 , enum V_493 type )
{
struct V_452 * V_453 ;
V_492 -> V_302 &= ~ V_520 ;
V_492 -> V_302 &= ~ V_521 ;
V_492 -> V_145 = V_538 ;
F_153 ( & V_492 -> V_531 , F_211 , V_492 ) ;
F_33 (tx, &tx_mod->tx_active_q, qe)
if ( V_453 -> type == type ) {
F_154 ( & V_492 -> V_531 ) ;
F_200 ( V_453 ) ;
}
F_155 ( & V_492 -> V_531 ) ;
}
void
F_216 ( struct V_491 * V_492 )
{
struct V_452 * V_453 ;
V_492 -> V_302 &= ~ V_520 ;
V_492 -> V_302 &= ~ V_521 ;
F_33 (tx, &tx_mod->tx_active_q, qe)
F_201 ( V_453 ) ;
}
void
F_217 ( struct V_452 * V_453 , int V_3 )
{
struct V_465 * V_466 ;
F_33 (txq, &tx->txq_q, qe)
F_1 ( & V_466 -> V_2 , V_3 ) ;
}
