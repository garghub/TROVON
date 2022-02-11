static struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
int V_8 ;
struct V_1 * V_9 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_10 ; V_8 ++ ) {
F_2 ( V_8 < V_11 ) ;
V_9 = & V_6 -> V_12 [ V_8 ] ;
if ( V_9 -> V_13 == V_4 )
return V_9 ;
}
return NULL ;
}
static struct V_14 *
F_3 ( T_1 V_15 , int V_16 )
{
struct V_14 * V_17 ;
F_4 ( V_17 , sizeof( * V_17 ) ) ;
if ( ! V_17 )
return NULL ;
F_5 ( & V_17 -> V_18 , 1 ) ;
V_17 -> V_19 = NULL ;
V_17 -> V_20 = 0 ;
V_17 -> V_21 = V_15 ;
V_17 -> V_22 = V_16 ;
V_17 -> V_23 = 0 ;
V_17 -> V_24 = 0 ;
V_17 -> V_25 = 0 ;
V_17 -> V_26 = 0 ;
V_17 -> V_27 = 0 ;
V_17 -> V_28 = 0 ;
return V_17 ;
}
void
F_6 ( struct V_14 * V_17 )
{
F_2 ( ! F_7 ( & V_17 -> V_18 ) ) ;
if ( V_17 -> V_19 )
F_8 ( V_17 -> V_19 ) ;
F_9 ( V_17 , sizeof( * V_17 ) ) ;
}
static int
F_10 ( struct V_29 * * V_30 , struct V_2 * V_3 ,
struct V_31 V_32 )
{
int V_33 = F_11 ( V_32 . V_34 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_29 * V_35 ;
F_2 ( V_32 . V_34 != V_36 ) ;
F_2 ( V_32 . V_37 != V_38 ) ;
F_2 ( ! F_12 () ) ;
F_13 ( V_35 , F_14 () , V_33 , sizeof( * V_35 ) ) ;
if ( ! V_35 )
return - V_39 ;
V_35 -> V_40 = V_3 ;
V_35 -> V_41 = V_32 ;
F_5 ( & V_35 -> V_42 , 1 ) ;
V_35 -> V_43 = 0 ;
V_35 -> V_44 = 0 ;
V_35 -> V_45 = NULL ;
V_35 -> V_46 = 0 ;
V_35 -> V_47 = V_48 + 1 ;
F_15 ( & V_35 -> V_49 ) ;
F_15 ( & V_35 -> V_50 ) ;
F_15 ( & V_35 -> V_51 ) ;
F_15 ( & V_35 -> V_52 ) ;
F_16 ( & V_35 -> V_53 ) ;
F_17 ( & V_6 -> V_54 ) ;
if ( V_6 -> V_55 ) {
F_18 ( & V_6 -> V_54 ) ;
F_9 ( V_35 , sizeof( * V_35 ) ) ;
F_19 ( L_1 ) ;
return - V_56 ;
}
V_6 -> V_57 ++ ;
F_18 ( & V_6 -> V_54 ) ;
* V_30 = V_35 ;
return 0 ;
}
void
F_20 ( struct V_29 * V_35 )
{
struct V_5 * V_6 = V_35 -> V_40 -> V_7 ;
F_21 ( V_58 , L_2 ,
F_22 ( V_35 -> V_41 ) , V_35 ) ;
F_2 ( ! F_7 ( & V_35 -> V_42 ) ) ;
F_2 ( ! V_35 -> V_44 ) ;
F_2 ( F_23 ( & V_35 -> V_49 ) ) ;
F_2 ( F_23 ( & V_35 -> V_50 ) ) ;
F_2 ( F_23 ( & V_35 -> V_51 ) ) ;
F_2 ( F_23 ( & V_35 -> V_52 ) ) ;
F_9 ( V_35 , sizeof( * V_35 ) ) ;
F_17 ( & V_6 -> V_54 ) ;
V_6 -> V_57 -- ;
F_18 ( & V_6 -> V_54 ) ;
}
struct V_29 *
F_24 ( struct V_2 * V_3 , struct V_31 V_32 )
{
struct V_59 * V_60 = F_25 ( V_32 . V_34 ) ;
struct V_59 * V_61 ;
struct V_29 * V_35 ;
F_26 (tmp, peer_list) {
V_35 = F_27 ( V_61 , struct V_29 , V_62 ) ;
F_2 ( ! V_35 -> V_43 ) ;
if ( V_35 -> V_40 != V_3 )
continue;
if ( V_35 -> V_41 . V_34 != V_32 . V_34 ||
V_35 -> V_41 . V_37 != V_32 . V_37 )
continue;
F_21 ( V_58 , L_3 ,
V_35 , F_22 ( V_32 ) ,
F_7 ( & V_35 -> V_42 ) ) ;
return V_35 ;
}
return NULL ;
}
struct V_29 *
F_28 ( struct V_2 * V_3 , struct V_31 V_32 )
{
struct V_29 * V_35 ;
F_29 ( & V_63 . V_64 ) ;
V_35 = F_24 ( V_3 , V_32 ) ;
if ( V_35 )
F_30 ( V_35 ) ;
F_31 ( & V_63 . V_64 ) ;
return V_35 ;
}
static void
F_32 ( struct V_29 * V_35 )
{
int V_8 ;
T_1 V_4 ;
struct V_1 * V_9 ;
for ( V_8 = 0 ; V_8 < V_35 -> V_65 ; V_8 ++ ) {
F_2 ( V_8 < V_11 ) ;
V_4 = V_35 -> V_66 [ V_8 ] ;
V_9 = F_1 ( V_35 -> V_40 , V_4 ) ;
F_2 ( V_9 ) ;
F_21 ( V_58 , L_4 ,
V_35 , V_9 , V_9 -> V_67 ) ;
V_9 -> V_68 -- ;
}
F_2 ( F_23 ( & V_35 -> V_49 ) ) ;
F_2 ( F_23 ( & V_35 -> V_50 ) ) ;
F_2 ( ! V_35 -> V_43 ) ;
V_35 -> V_43 = 1 ;
F_33 ( & V_35 -> V_62 ) ;
F_8 ( V_35 ) ;
}
static int
F_34 ( struct V_2 * V_3 , int V_69 ,
struct V_31 * V_32 , T_1 * V_70 , T_1 * V_71 ,
int * V_16 , int * V_72 , int * V_73 )
{
struct V_29 * V_35 ;
struct V_59 * V_74 ;
struct V_14 * V_17 ;
struct V_59 * V_75 ;
int V_8 ;
int V_76 ;
int V_77 = - V_78 ;
F_29 ( & V_63 . V_64 ) ;
for ( V_8 = 0 ; V_8 < V_63 . V_79 ; V_8 ++ ) {
F_26 (ptmp, &ksocknal_data.ksnd_peers[i]) {
V_35 = F_27 ( V_74 , struct V_29 , V_62 ) ;
if ( V_35 -> V_40 != V_3 )
continue;
if ( ! V_35 -> V_65 &&
F_23 ( & V_35 -> V_50 ) ) {
if ( V_69 -- > 0 )
continue;
* V_32 = V_35 -> V_41 ;
* V_70 = 0 ;
* V_71 = 0 ;
* V_16 = 0 ;
* V_72 = 0 ;
* V_73 = 0 ;
V_77 = 0 ;
goto V_80;
}
for ( V_76 = 0 ; V_76 < V_35 -> V_65 ; V_76 ++ ) {
if ( V_69 -- > 0 )
continue;
* V_32 = V_35 -> V_41 ;
* V_70 = V_35 -> V_66 [ V_76 ] ;
* V_71 = 0 ;
* V_16 = 0 ;
* V_72 = 0 ;
* V_73 = 0 ;
V_77 = 0 ;
goto V_80;
}
F_26 (rtmp, &peer->ksnp_routes) {
if ( V_69 -- > 0 )
continue;
V_17 = F_27 ( V_75 , struct V_14 ,
V_81 ) ;
* V_32 = V_35 -> V_41 ;
* V_70 = V_17 -> V_82 ;
* V_71 = V_17 -> V_21 ;
* V_16 = V_17 -> V_22 ;
* V_72 = V_17 -> V_27 ;
* V_73 = V_17 -> V_28 ;
V_77 = 0 ;
goto V_80;
}
}
}
V_80:
F_31 ( & V_63 . V_64 ) ;
return V_77 ;
}
static void
F_35 ( struct V_14 * V_17 ,
struct V_83 * V_84 )
{
struct V_29 * V_35 = V_17 -> V_19 ;
int type = V_84 -> V_85 ;
struct V_1 * V_9 ;
V_84 -> V_86 = V_17 ;
F_36 ( V_17 ) ;
if ( V_17 -> V_82 != V_84 -> V_87 ) {
if ( ! V_17 -> V_82 ) {
F_21 ( V_58 , L_5 ,
F_22 ( V_35 -> V_41 ) ,
& V_17 -> V_21 ,
& V_84 -> V_87 ) ;
} else {
F_21 ( V_58 , L_6 ,
F_22 ( V_35 -> V_41 ) ,
& V_17 -> V_21 ,
& V_17 -> V_82 ,
& V_84 -> V_87 ) ;
V_9 = F_1 ( V_17 -> V_19 -> V_40 ,
V_17 -> V_82 ) ;
if ( V_9 )
V_9 -> V_67 -- ;
}
V_17 -> V_82 = V_84 -> V_87 ;
V_9 = F_1 ( V_17 -> V_19 -> V_40 ,
V_17 -> V_82 ) ;
if ( V_9 )
V_9 -> V_67 ++ ;
}
V_17 -> V_25 |= ( 1 << type ) ;
V_17 -> V_27 ++ ;
V_17 -> V_20 = 0 ;
}
static void
F_37 ( struct V_29 * V_35 , struct V_14 * V_17 )
{
struct V_59 * V_61 ;
struct V_83 * V_84 ;
struct V_14 * V_88 ;
F_2 ( ! V_35 -> V_43 ) ;
F_2 ( ! V_17 -> V_19 ) ;
F_2 ( ! V_17 -> V_23 ) ;
F_2 ( ! V_17 -> V_24 ) ;
F_2 ( ! V_17 -> V_25 ) ;
F_26 (tmp, &peer->ksnp_routes) {
V_88 = F_27 ( V_61 , struct V_14 , V_81 ) ;
if ( V_88 -> V_21 == V_17 -> V_21 ) {
F_19 ( L_7 ,
F_22 ( V_35 -> V_41 ) ,
& V_17 -> V_21 ) ;
F_38 () ;
}
}
V_17 -> V_19 = V_35 ;
F_30 ( V_35 ) ;
F_39 ( & V_17 -> V_81 , & V_35 -> V_50 ) ;
F_26 (tmp, &peer->ksnp_conns) {
V_84 = F_27 ( V_61 , struct V_83 , V_89 ) ;
if ( V_84 -> V_90 != V_17 -> V_21 )
continue;
F_35 ( V_17 , V_84 ) ;
}
}
static void
F_40 ( struct V_14 * V_17 )
{
struct V_29 * V_35 = V_17 -> V_19 ;
struct V_1 * V_9 ;
struct V_83 * V_84 ;
struct V_59 * V_91 ;
struct V_59 * V_92 ;
F_2 ( ! V_17 -> V_26 ) ;
F_41 (ctmp, cnxt, &peer->ksnp_conns) {
V_84 = F_27 ( V_91 , struct V_83 , V_89 ) ;
if ( V_84 -> V_86 != V_17 )
continue;
F_42 ( V_84 , 0 ) ;
}
if ( V_17 -> V_82 ) {
V_9 = F_1 ( V_17 -> V_19 -> V_40 ,
V_17 -> V_82 ) ;
if ( V_9 )
V_9 -> V_67 -- ;
}
V_17 -> V_26 = 1 ;
F_33 ( & V_17 -> V_81 ) ;
F_43 ( V_17 ) ;
if ( F_23 ( & V_35 -> V_50 ) &&
F_23 ( & V_35 -> V_49 ) ) {
F_32 ( V_35 ) ;
}
}
int
F_44 ( struct V_2 * V_3 , struct V_31 V_32 , T_1 V_15 ,
int V_16 )
{
struct V_59 * V_61 ;
struct V_29 * V_35 ;
struct V_29 * V_93 ;
struct V_14 * V_17 ;
struct V_14 * V_88 ;
int V_77 ;
if ( V_32 . V_34 == V_36 ||
V_32 . V_37 == V_38 )
return - V_94 ;
V_77 = F_10 ( & V_35 , V_3 , V_32 ) ;
if ( V_77 )
return V_77 ;
V_17 = F_3 ( V_15 , V_16 ) ;
if ( ! V_17 ) {
F_8 ( V_35 ) ;
return - V_39 ;
}
F_45 ( & V_63 . V_64 ) ;
F_2 ( ! ( (struct V_5 * ) V_3 -> V_7 ) -> V_55 ) ;
V_93 = F_24 ( V_3 , V_32 ) ;
if ( V_93 ) {
F_8 ( V_35 ) ;
V_35 = V_93 ;
} else {
F_39 ( & V_35 -> V_62 ,
F_25 ( V_32 . V_34 ) ) ;
}
V_88 = NULL ;
F_26 (tmp, &peer->ksnp_routes) {
V_88 = F_27 ( V_61 , struct V_14 , V_81 ) ;
if ( V_88 -> V_21 == V_15 )
break;
V_88 = NULL ;
}
if ( ! V_88 ) {
F_37 ( V_35 , V_17 ) ;
V_17 -> V_28 ++ ;
} else {
F_43 ( V_17 ) ;
V_88 -> V_28 ++ ;
}
F_46 ( & V_63 . V_64 ) ;
return 0 ;
}
static void
F_47 ( struct V_29 * V_35 , T_1 V_4 )
{
struct V_83 * V_84 ;
struct V_14 * V_17 ;
struct V_59 * V_61 ;
struct V_59 * V_95 ;
int V_96 ;
F_2 ( ! V_35 -> V_43 ) ;
F_30 ( V_35 ) ;
F_41 (tmp, nxt, &peer->ksnp_routes) {
V_17 = F_27 ( V_61 , struct V_14 , V_81 ) ;
if ( ! ( ! V_4 || V_17 -> V_21 == V_4 ) )
continue;
V_17 -> V_28 = 0 ;
F_40 ( V_17 ) ;
}
V_96 = 0 ;
F_41 (tmp, nxt, &peer->ksnp_routes) {
V_17 = F_27 ( V_61 , struct V_14 , V_81 ) ;
V_96 += V_17 -> V_28 ;
}
if ( ! V_96 ) {
F_41 (tmp, nxt, &peer->ksnp_routes) {
V_17 = F_27 ( V_61 , struct V_14 , V_81 ) ;
F_2 ( ! V_17 -> V_28 ) ;
F_40 ( V_17 ) ;
}
F_41 (tmp, nxt, &peer->ksnp_conns) {
V_84 = F_27 ( V_61 , struct V_83 , V_89 ) ;
F_42 ( V_84 , 0 ) ;
}
}
F_8 ( V_35 ) ;
}
static int
F_48 ( struct V_2 * V_3 , struct V_31 V_32 , T_1 V_4 )
{
F_49 ( V_97 ) ;
struct V_59 * V_74 ;
struct V_59 * V_98 ;
struct V_29 * V_35 ;
int V_99 ;
int V_100 ;
int V_8 ;
int V_77 = - V_78 ;
F_45 ( & V_63 . V_64 ) ;
if ( V_32 . V_34 != V_36 ) {
V_99 = ( int ) ( F_25 ( V_32 . V_34 ) - V_63 . V_101 ) ;
V_100 = ( int ) ( F_25 ( V_32 . V_34 ) - V_63 . V_101 ) ;
} else {
V_99 = 0 ;
V_100 = V_63 . V_79 - 1 ;
}
for ( V_8 = V_99 ; V_8 <= V_100 ; V_8 ++ ) {
F_41 (ptmp, pnxt, &ksocknal_data.ksnd_peers[i]) {
V_35 = F_27 ( V_74 , struct V_29 , V_62 ) ;
if ( V_35 -> V_40 != V_3 )
continue;
if ( ! ( ( V_32 . V_34 == V_36 || V_35 -> V_41 . V_34 == V_32 . V_34 ) &&
( V_32 . V_37 == V_38 || V_35 -> V_41 . V_37 == V_32 . V_37 ) ) )
continue;
F_30 ( V_35 ) ;
F_47 ( V_35 , V_4 ) ;
if ( V_35 -> V_43 &&
! F_23 ( & V_35 -> V_51 ) ) {
F_2 ( F_23 ( & V_35 -> V_49 ) ) ;
F_2 ( F_23 ( & V_35 -> V_50 ) ) ;
F_50 ( & V_35 -> V_51 ,
& V_97 ) ;
}
F_8 ( V_35 ) ;
V_77 = 0 ;
}
}
F_46 ( & V_63 . V_64 ) ;
F_51 ( V_3 , & V_97 , 1 ) ;
return V_77 ;
}
static struct V_83 *
F_52 ( struct V_2 * V_3 , int V_69 )
{
struct V_29 * V_35 ;
struct V_59 * V_74 ;
struct V_83 * V_84 ;
struct V_59 * V_91 ;
int V_8 ;
F_29 ( & V_63 . V_64 ) ;
for ( V_8 = 0 ; V_8 < V_63 . V_79 ; V_8 ++ ) {
F_26 (ptmp, &ksocknal_data.ksnd_peers[i]) {
V_35 = F_27 ( V_74 , struct V_29 , V_62 ) ;
F_2 ( ! V_35 -> V_43 ) ;
if ( V_35 -> V_40 != V_3 )
continue;
F_26 (ctmp, &peer->ksnp_conns) {
if ( V_69 -- > 0 )
continue;
V_84 = F_27 ( V_91 , struct V_83 ,
V_89 ) ;
F_53 ( V_84 ) ;
F_31 ( & V_63 . V_64 ) ;
return V_84 ;
}
}
}
F_31 ( & V_63 . V_64 ) ;
return NULL ;
}
static struct V_102 *
F_54 ( unsigned int V_33 )
{
struct V_103 * V_104 = V_63 . V_105 [ V_33 ] ;
struct V_102 * V_106 ;
int V_8 ;
F_2 ( V_104 -> V_107 > 0 ) ;
V_106 = & V_104 -> V_108 [ 0 ] ;
for ( V_8 = 1 ; V_8 < V_104 -> V_107 ; V_8 ++ ) {
if ( V_106 -> V_109 > V_104 -> V_108 [ V_8 ] . V_109 )
V_106 = & V_104 -> V_108 [ V_8 ] ;
}
return V_106 ;
}
static int
F_55 ( struct V_2 * V_3 , T_1 * V_110 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
int V_8 ;
int V_111 ;
F_29 ( & V_63 . V_64 ) ;
V_111 = V_6 -> V_10 ;
F_2 ( V_111 <= V_11 ) ;
if ( V_111 < 2 ) {
F_31 ( & V_63 . V_64 ) ;
return 0 ;
}
for ( V_8 = 0 ; V_8 < V_111 ; V_8 ++ ) {
V_110 [ V_8 ] = V_6 -> V_12 [ V_8 ] . V_13 ;
F_2 ( V_110 [ V_8 ] ) ;
}
F_31 ( & V_63 . V_64 ) ;
return V_111 ;
}
static int
F_56 ( struct V_1 * V_9 , T_1 * V_112 , int V_113 )
{
int V_114 = 0 ;
int V_115 = 0 ;
int V_116 = - 1 ;
int V_117 ;
int V_118 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_113 ; V_8 ++ ) {
if ( ! V_112 [ V_8 ] )
continue;
V_117 = V_112 [ V_8 ] ^ V_9 -> V_13 ;
V_118 = ! ( V_117 & V_9 -> V_119 ) ? 1 : 0 ;
if ( ! ( V_116 < 0 ||
V_114 < V_118 ||
( V_114 == V_118 &&
V_115 > V_117 ) ) )
continue;
V_116 = V_8 ;
V_114 = V_118 ;
V_115 = V_117 ;
}
F_2 ( V_116 >= 0 ) ;
return V_116 ;
}
static int
F_57 ( struct V_29 * V_35 , T_1 * V_120 , int V_121 )
{
T_2 * V_122 = & V_63 . V_64 ;
struct V_5 * V_6 = V_35 -> V_40 -> V_7 ;
struct V_1 * V_9 ;
struct V_1 * V_123 ;
int V_124 ;
int V_8 ;
int V_76 ;
int V_125 ;
T_1 V_4 ;
T_1 V_126 ;
int V_118 ;
int V_114 ;
int V_127 ;
F_45 ( V_122 ) ;
F_2 ( V_121 <= V_11 ) ;
F_2 ( V_6 -> V_10 <= V_11 ) ;
V_124 = ( V_6 -> V_10 < 2 ) ? 0 :
F_58 ( V_121 , V_6 -> V_10 ) ;
for ( V_8 = 0 ; V_35 -> V_65 < V_124 ; V_8 ++ ) {
if ( V_8 < V_35 -> V_65 ) {
V_4 = V_35 -> V_66 [ V_8 ] ;
V_123 = F_1 ( V_35 -> V_40 , V_4 ) ;
F_2 ( V_123 ) ;
} else {
F_2 ( V_8 == V_35 -> V_65 ) ;
V_123 = NULL ;
V_114 = 0 ;
V_127 = 0 ;
for ( V_76 = 0 ; V_76 < V_6 -> V_10 ; V_76 ++ ) {
V_9 = & V_6 -> V_12 [ V_76 ] ;
V_4 = V_9 -> V_13 ;
for ( V_125 = 0 ; V_125 < V_35 -> V_65 ; V_125 ++ )
if ( V_35 -> V_66 [ V_125 ] == V_4 )
break;
if ( V_125 < V_35 -> V_65 )
continue;
V_125 = F_56 ( V_9 , V_120 ,
V_121 ) ;
V_126 = V_4 ^ V_120 [ V_125 ] ;
V_118 = ! ( V_126 & V_9 -> V_119 ) ? 1 : 0 ;
if ( ! ( ! V_123 ||
V_114 < V_118 ||
( V_114 == V_118 &&
V_127 > V_9 -> V_68 ) ) )
continue;
V_123 = V_9 ;
V_114 = V_118 ;
V_127 = V_9 -> V_68 ;
}
F_2 ( V_123 ) ;
V_123 -> V_68 ++ ;
V_4 = V_123 -> V_13 ;
V_35 -> V_66 [ V_8 ] = V_4 ;
V_35 -> V_65 = V_8 + 1 ;
}
V_76 = F_56 ( V_123 , V_120 , V_121 ) ;
V_120 [ V_76 ] = 0 ;
}
memcpy ( V_120 , V_35 -> V_66 , V_124 * sizeof( * V_120 ) ) ;
F_46 ( V_122 ) ;
return V_124 ;
}
static void
F_59 ( struct V_29 * V_35 , int V_16 ,
T_1 * V_128 , int V_129 )
{
struct V_14 * V_130 = NULL ;
T_2 * V_122 = & V_63 . V_64 ;
struct V_2 * V_3 = V_35 -> V_40 ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_59 * V_75 ;
struct V_14 * V_17 ;
struct V_1 * V_9 ;
struct V_1 * V_123 ;
int V_114 ;
int V_118 ;
int V_131 ;
int V_8 ;
int V_76 ;
F_45 ( V_122 ) ;
if ( V_6 -> V_10 < 2 ) {
F_46 ( V_122 ) ;
return;
}
F_2 ( V_129 <= V_11 ) ;
for ( V_8 = 0 ; V_8 < V_129 ; V_8 ++ ) {
if ( V_130 ) {
V_130 -> V_21 = V_128 [ V_8 ] ;
} else {
F_46 ( V_122 ) ;
V_130 = F_3 ( V_128 [ V_8 ] , V_16 ) ;
if ( ! V_130 )
return;
F_45 ( V_122 ) ;
}
if ( V_35 -> V_43 ) {
break;
}
V_17 = NULL ;
F_26 (rtmp, &peer->ksnp_routes) {
V_17 = F_27 ( V_75 , struct V_14 , V_81 ) ;
if ( V_17 -> V_21 == V_130 -> V_21 )
break;
V_17 = NULL ;
}
if ( V_17 )
continue;
V_123 = NULL ;
V_131 = 0 ;
V_114 = 0 ;
F_2 ( V_6 -> V_10 <= V_11 ) ;
for ( V_76 = 0 ; V_76 < V_6 -> V_10 ; V_76 ++ ) {
V_9 = & V_6 -> V_12 [ V_76 ] ;
F_26 (rtmp, &peer->ksnp_routes) {
V_17 = F_27 ( V_75 , struct V_14 ,
V_81 ) ;
if ( V_17 -> V_82 == V_9 -> V_13 )
break;
V_17 = NULL ;
}
if ( V_17 )
continue;
V_118 = ( ! ( ( V_9 -> V_13 ^
V_130 -> V_21 ) &
V_9 -> V_119 ) ) ? 1 : 0 ;
if ( ! ( ! V_123 ||
V_114 < V_118 ||
( V_114 == V_118 &&
V_131 > V_9 -> V_67 ) ) )
continue;
V_123 = V_9 ;
V_114 = V_118 ;
V_131 = V_9 -> V_67 ;
}
if ( ! V_123 )
continue;
V_130 -> V_82 = V_123 -> V_13 ;
V_123 -> V_67 ++ ;
F_37 ( V_35 , V_130 ) ;
V_130 = NULL ;
}
F_46 ( V_122 ) ;
if ( V_130 )
F_43 ( V_130 ) ;
}
int
F_60 ( struct V_2 * V_3 , struct V_132 * V_133 )
{
struct V_134 * V_135 ;
int V_77 ;
T_1 V_71 ;
int V_136 ;
V_77 = F_61 ( V_133 , 1 , & V_71 , & V_136 ) ;
F_2 ( ! V_77 ) ;
F_4 ( V_135 , sizeof( * V_135 ) ) ;
if ( ! V_135 ) {
F_62 ( 0x12f , L_8 ,
& V_71 ) ;
return - V_39 ;
}
F_63 ( V_3 ) ;
V_135 -> V_137 = V_3 ;
V_135 -> V_138 = V_133 ;
F_17 ( & V_63 . V_139 ) ;
F_39 ( & V_135 -> V_140 , & V_63 . V_141 ) ;
F_64 ( & V_63 . V_142 ) ;
F_18 ( & V_63 . V_139 ) ;
return 0 ;
}
static int
F_65 ( struct V_29 * V_35 , T_1 V_15 )
{
struct V_14 * V_17 ;
F_66 (route, &peer->ksnp_routes, ksnr_list) {
if ( V_17 -> V_21 == V_15 )
return V_17 -> V_24 ;
}
return 0 ;
}
int
F_67 ( struct V_2 * V_3 , struct V_14 * V_17 ,
struct V_132 * V_133 , int type )
{
T_2 * V_122 = & V_63 . V_64 ;
F_49 ( V_97 ) ;
struct V_31 V_143 ;
struct V_59 * V_61 ;
T_3 V_144 ;
struct V_83 * V_84 ;
struct V_83 * V_145 ;
struct V_29 * V_35 = NULL ;
struct V_29 * V_93 ;
struct V_102 * V_106 ;
struct V_146 * V_147 ;
int V_33 ;
struct V_148 * V_149 ;
struct V_148 * V_150 ;
int V_77 ;
int V_151 ;
char * V_152 = NULL ;
V_151 = ! ! V_17 ;
F_2 ( V_151 == ( type != V_153 ) ) ;
F_4 ( V_84 , sizeof( * V_84 ) ) ;
if ( ! V_84 ) {
V_77 = - V_39 ;
goto V_154;
}
V_84 -> V_155 = NULL ;
V_84 -> V_86 = NULL ;
V_84 -> V_156 = V_133 ;
F_5 ( & V_84 -> V_157 , 2 ) ;
V_84 -> V_85 = type ;
F_68 ( V_133 , V_84 ) ;
F_5 ( & V_84 -> V_158 , 1 ) ;
V_84 -> V_159 = 0 ;
V_84 -> V_160 = 0 ;
F_15 ( & V_84 -> V_161 ) ;
V_84 -> V_162 = 0 ;
V_84 -> V_163 = 0 ;
V_84 -> V_164 = NULL ;
F_5 ( & V_84 -> V_165 , 0 ) ;
F_4 ( V_147 , F_69 ( struct V_146 ,
V_166 [ V_11 ] ) ) ;
if ( ! V_147 ) {
V_77 = - V_39 ;
goto V_167;
}
V_77 = F_70 ( V_84 ) ;
if ( V_77 )
goto V_167;
if ( V_151 ) {
V_35 = V_17 -> V_19 ;
F_2 ( V_3 == V_35 -> V_40 ) ;
V_147 -> V_168 = F_55 ( V_3 , V_147 -> V_166 ) ;
V_143 = V_35 -> V_41 ;
F_45 ( V_122 ) ;
V_84 -> V_169 = V_35 -> V_45 ;
F_46 ( V_122 ) ;
if ( ! V_84 -> V_169 ) {
V_84 -> V_169 = & V_170 ;
#if V_171
if ( * V_172 . V_173 == 2 )
V_84 -> V_169 = & V_174 ;
else if ( * V_172 . V_173 == 1 )
V_84 -> V_169 = & V_175 ;
#endif
}
V_77 = F_71 ( V_3 , V_84 , V_143 . V_34 , V_147 ) ;
if ( V_77 )
goto V_167;
} else {
V_143 . V_34 = V_36 ;
V_143 . V_37 = V_38 ;
V_84 -> V_169 = NULL ;
}
V_77 = F_72 ( V_3 , V_84 , V_147 , & V_143 , & V_144 ) ;
if ( V_77 < 0 )
goto V_167;
F_2 ( ! V_77 || V_151 ) ;
F_2 ( V_84 -> V_169 ) ;
F_2 ( V_143 . V_34 != V_36 ) ;
V_33 = F_11 ( V_143 . V_34 ) ;
if ( V_151 ) {
F_30 ( V_35 ) ;
F_45 ( V_122 ) ;
} else {
V_77 = F_10 ( & V_35 , V_3 , V_143 ) ;
if ( V_77 )
goto V_167;
F_45 ( V_122 ) ;
F_2 ( ! ( (struct V_5 * ) V_3 -> V_7 ) -> V_55 ) ;
V_93 = F_24 ( V_3 , V_143 ) ;
if ( ! V_93 ) {
F_39 ( & V_35 -> V_62 ,
F_25 ( V_143 . V_34 ) ) ;
} else {
F_8 ( V_35 ) ;
V_35 = V_93 ;
}
F_30 ( V_35 ) ;
V_35 -> V_44 ++ ;
if ( V_143 . V_34 < V_3 -> V_176 &&
F_65 ( V_35 , V_84 -> V_90 ) ) {
V_77 = V_177 ;
V_152 = L_9 ;
goto V_178;
}
}
if ( V_35 -> V_43 ||
( V_151 && V_17 -> V_26 ) ) {
V_77 = - V_179 ;
V_152 = L_10 ;
goto V_178;
}
if ( ! V_35 -> V_45 ) {
F_2 ( F_23 ( & V_35 -> V_49 ) ) ;
V_35 -> V_45 = V_84 -> V_169 ;
V_35 -> V_180 = V_144 ;
}
if ( V_35 -> V_45 != V_84 -> V_169 ||
V_35 -> V_180 != V_144 ) {
F_73 ( V_35 , 0 , 0 ) ;
V_35 -> V_45 = NULL ;
V_77 = V_179 ;
V_152 = V_35 -> V_180 != V_144 ?
L_11 :
L_12 ;
goto V_178;
}
switch ( V_77 ) {
default:
F_38 () ;
case 0 :
break;
case V_177 :
V_152 = L_13 ;
goto V_178;
case V_181 :
V_152 = L_14 ;
goto V_178;
}
if ( V_84 -> V_90 != V_84 -> V_87 ) {
F_26 (tmp, &peer->ksnp_conns) {
V_145 = F_27 ( V_61 , struct V_83 , V_89 ) ;
if ( V_145 -> V_90 != V_84 -> V_90 ||
V_145 -> V_87 != V_84 -> V_87 ||
V_145 -> V_85 != V_84 -> V_85 )
continue;
F_2 ( ! V_77 ) ;
if ( ! V_151 )
V_77 = V_177 ;
V_152 = L_15 ;
goto V_178;
}
}
if ( V_151 &&
V_17 -> V_21 != V_84 -> V_90 ) {
F_19 ( L_16 ,
F_22 ( V_35 -> V_41 ) ,
& V_17 -> V_21 ,
& V_84 -> V_90 ) ;
}
F_26 (tmp, &peer->ksnp_routes) {
V_17 = F_27 ( V_61 , struct V_14 , V_81 ) ;
if ( V_17 -> V_21 != V_84 -> V_90 )
continue;
F_35 ( V_17 , V_84 ) ;
break;
}
V_84 -> V_155 = V_35 ;
V_35 -> V_46 = F_74 () ;
V_35 -> V_182 = 0 ;
V_35 -> V_183 = 0 ;
V_106 = F_54 ( V_33 ) ;
V_106 -> V_109 ++ ;
V_84 -> V_184 = V_106 ;
V_84 -> V_185 = F_74 () ;
V_84 -> V_186 = V_133 -> V_187 -> V_188 ;
V_84 -> V_189 = F_75 ( * V_172 . V_190 ) ;
F_76 () ;
F_77 ( & V_84 -> V_89 , & V_35 -> V_49 ) ;
F_53 ( V_84 ) ;
F_78 ( V_84 , 0 ) ;
V_84 -> V_191 = F_79 ( V_84 ) ;
F_80 (tx, txtmp, &peer->ksnp_tx_queue, tx_list) {
int V_192 = V_84 -> V_169 -> V_193 ( V_84 , V_149 ,
V_149 -> V_194 ) ;
if ( V_192 == V_195 )
continue;
F_33 ( & V_149 -> V_196 ) ;
F_81 ( V_149 , V_84 ) ;
}
F_46 ( V_122 ) ;
F_21 ( V_58 , L_17 ,
F_22 ( V_143 ) , V_84 -> V_169 -> V_197 ,
& V_84 -> V_87 , & V_84 -> V_90 ,
V_84 -> V_198 , V_144 , V_33 ,
( int ) ( V_106 - & V_106 -> V_199 -> V_108 [ 0 ] ) ) ;
if ( V_151 ) {
F_59 ( V_35 , V_84 -> V_198 ,
V_147 -> V_166 , V_147 -> V_168 ) ;
} else {
V_147 -> V_168 = F_57 ( V_35 , V_147 -> V_166 ,
V_147 -> V_168 ) ;
V_77 = F_71 ( V_3 , V_84 , V_143 . V_34 , V_147 ) ;
}
F_9 ( V_147 , F_69 ( struct V_146 ,
V_166 [ V_11 ] ) ) ;
if ( ! V_77 )
V_77 = F_82 ( V_133 ) ;
F_45 ( V_122 ) ;
F_83 ( V_133 , V_84 ) ;
if ( ! V_151 )
V_35 -> V_44 -- ;
F_46 ( V_122 ) ;
if ( V_77 ) {
F_45 ( V_122 ) ;
if ( ! V_84 -> V_200 ) {
F_42 ( V_84 , V_77 ) ;
}
F_46 ( V_122 ) ;
} else if ( ! F_84 ( V_84 ) ) {
F_85 ( V_84 ) ;
F_86 ( V_84 ) ;
F_87 ( V_84 ) ;
}
F_87 ( V_84 ) ;
F_88 ( V_84 ) ;
return V_77 ;
V_178:
if ( ! V_35 -> V_43 &&
F_23 ( & V_35 -> V_49 ) &&
F_23 ( & V_35 -> V_50 ) ) {
F_77 ( & V_97 , & V_35 -> V_51 ) ;
F_89 ( & V_35 -> V_51 ) ;
F_32 ( V_35 ) ;
}
F_46 ( V_122 ) ;
if ( V_152 ) {
if ( V_77 < 0 )
F_19 ( L_18 ,
F_22 ( V_143 ) , V_84 -> V_85 , V_152 ) ;
else
F_21 ( V_58 , L_18 ,
F_22 ( V_143 ) , V_84 -> V_85 , V_152 ) ;
}
if ( ! V_151 ) {
if ( V_77 > 0 ) {
V_84 -> V_85 = V_153 ;
V_147 -> V_168 = 0 ;
F_71 ( V_3 , V_84 , V_143 . V_34 , V_147 ) ;
}
F_45 ( V_122 ) ;
V_35 -> V_44 -- ;
F_46 ( V_122 ) ;
}
F_51 ( V_3 , & V_97 , 1 ) ;
F_8 ( V_35 ) ;
V_167:
if ( V_147 )
F_9 ( V_147 , F_69 ( struct V_146 ,
V_166 [ V_11 ] ) ) ;
F_9 ( V_84 , sizeof( * V_84 ) ) ;
V_154:
F_90 ( V_133 ) ;
return V_77 ;
}
void
F_42 ( struct V_83 * V_84 , int error )
{
struct V_29 * V_35 = V_84 -> V_155 ;
struct V_14 * V_17 ;
struct V_83 * V_145 ;
struct V_59 * V_61 ;
F_2 ( ! V_35 -> V_183 ) ;
F_2 ( ! V_84 -> V_200 ) ;
V_84 -> V_200 = 1 ;
F_33 ( & V_84 -> V_89 ) ;
V_17 = V_84 -> V_86 ;
if ( V_17 ) {
F_2 ( ! V_17 -> V_26 ) ;
F_2 ( V_17 -> V_25 & ( 1 << V_84 -> V_85 ) ) ;
V_145 = NULL ;
F_26 (tmp, &peer->ksnp_conns) {
V_145 = F_27 ( V_61 , struct V_83 , V_89 ) ;
if ( V_145 -> V_86 == V_17 &&
V_145 -> V_85 == V_84 -> V_85 )
break;
V_145 = NULL ;
}
if ( ! V_145 )
V_17 -> V_25 &= ~ ( 1 << V_84 -> V_85 ) ;
V_84 -> V_86 = NULL ;
F_43 ( V_17 ) ;
}
if ( F_23 ( & V_35 -> V_49 ) ) {
if ( ! F_23 ( & V_35 -> V_51 ) ) {
struct V_148 * V_149 ;
F_2 ( V_84 -> V_169 == & V_170 ) ;
F_66 (tx, &peer->ksnp_tx_queue,
tx_list)
F_91 ( V_84 , V_149 ) ;
F_17 ( & V_84 -> V_184 -> V_201 ) ;
F_50 ( & V_35 -> V_51 ,
& V_84 -> V_161 ) ;
F_18 ( & V_84 -> V_184 -> V_201 ) ;
}
V_35 -> V_45 = NULL ;
V_35 -> V_183 = error ;
if ( F_23 ( & V_35 -> V_50 ) ) {
F_32 ( V_35 ) ;
}
}
F_17 ( & V_63 . V_202 ) ;
F_39 ( & V_84 -> V_89 ,
& V_63 . V_203 ) ;
F_64 ( & V_63 . V_204 ) ;
F_18 ( & V_63 . V_202 ) ;
}
void
F_92 ( struct V_29 * V_35 )
{
int V_205 = 0 ;
unsigned long V_206 = 0 ;
F_29 ( & V_63 . V_64 ) ;
if ( ! ( V_35 -> V_41 . V_37 & V_207 ) &&
F_23 ( & V_35 -> V_49 ) &&
! V_35 -> V_44 &&
! F_93 ( V_35 ) ) {
V_205 = 1 ;
V_206 = V_35 -> V_46 ;
}
F_31 ( & V_63 . V_64 ) ;
if ( V_205 )
F_94 ( V_35 -> V_40 , V_35 -> V_41 . V_34 , 0 ,
V_206 ) ;
}
void
F_95 ( struct V_83 * V_84 )
{
struct V_29 * V_35 = V_84 -> V_155 ;
struct V_148 * V_149 ;
struct V_148 * V_208 ;
struct V_148 * V_61 ;
F_49 ( V_209 ) ;
F_2 ( ! V_84 -> V_156 ) ;
F_96 ( & V_35 -> V_53 ) ;
F_80 (tx, tmp, &peer->ksnp_zc_req_list, tx_zc_list) {
if ( V_149 -> V_210 != V_84 )
continue;
F_2 ( V_149 -> V_211 . V_212 [ 0 ] ) ;
V_149 -> V_211 . V_212 [ 0 ] = 0 ;
V_149 -> V_213 = 1 ;
F_33 ( & V_149 -> V_214 ) ;
F_77 ( & V_149 -> V_214 , & V_209 ) ;
}
F_97 ( & V_35 -> V_53 ) ;
F_80 (tx, temp, &zlist, tx_zc_list) {
F_33 ( & V_149 -> V_214 ) ;
F_98 ( V_149 ) ;
}
}
void
F_99 ( struct V_83 * V_84 )
{
struct V_29 * V_35 = V_84 -> V_155 ;
struct V_102 * V_106 = V_84 -> V_184 ;
int V_215 = 0 ;
F_2 ( V_84 -> V_200 ) ;
F_17 ( & V_106 -> V_201 ) ;
V_84 -> V_162 = 1 ;
if ( ! V_84 -> V_163 &&
! F_23 ( & V_84 -> V_161 ) ) {
F_39 ( & V_84 -> V_216 ,
& V_106 -> V_217 ) ;
V_84 -> V_163 = 1 ;
F_53 ( V_84 ) ;
F_64 ( & V_106 -> V_218 ) ;
}
F_18 ( & V_106 -> V_201 ) ;
F_45 ( & V_63 . V_64 ) ;
F_100 ( V_84 -> V_156 , V_84 ) ;
V_84 -> V_184 -> V_109 -- ;
if ( V_35 -> V_183 ) {
F_2 ( F_23 ( & V_35 -> V_49 ) ) ;
V_215 = 1 ;
V_35 -> V_183 = 0 ;
}
F_46 ( & V_63 . V_64 ) ;
if ( V_215 )
F_92 ( V_35 ) ;
F_87 ( V_84 ) ;
}
void
F_101 ( struct V_83 * V_84 )
{
F_2 ( ! F_7 ( & V_84 -> V_158 ) ) ;
F_17 ( & V_63 . V_202 ) ;
F_39 ( & V_84 -> V_89 , & V_63 . V_219 ) ;
F_64 ( & V_63 . V_204 ) ;
F_18 ( & V_63 . V_202 ) ;
}
void
F_102 ( struct V_83 * V_84 )
{
unsigned long V_220 ;
F_21 ( V_58 , L_19 , V_84 ) ;
F_2 ( ! F_7 ( & V_84 -> V_158 ) ) ;
F_2 ( ! F_7 ( & V_84 -> V_157 ) ) ;
F_2 ( ! V_84 -> V_156 ) ;
F_2 ( ! V_84 -> V_86 ) ;
F_2 ( ! V_84 -> V_163 ) ;
F_2 ( ! V_84 -> V_160 ) ;
F_2 ( F_23 ( & V_84 -> V_161 ) ) ;
switch ( V_84 -> V_221 ) {
case V_222 :
V_220 = V_84 -> V_223 -
F_103 ( * V_172 . V_190 ) ;
F_19 ( L_20 ,
F_22 ( V_84 -> V_155 -> V_41 ) , V_84 -> V_85 ,
& V_84 -> V_90 , V_84 -> V_198 ,
V_84 -> V_224 , V_84 -> V_225 ,
F_104 ( F_105 ( F_74 () ,
V_220 ) ) ) ;
F_106 ( V_84 -> V_155 -> V_40 ,
V_84 -> V_226 , - V_227 ) ;
break;
case V_228 :
if ( V_84 -> V_229 )
F_19 ( L_21 ,
F_22 ( V_84 -> V_155 -> V_41 ) ,
& V_84 -> V_90 , V_84 -> V_198 ,
V_84 -> V_169 -> V_197 ) ;
break;
case V_230 :
if ( V_84 -> V_229 )
F_19 ( L_22 ,
F_22 ( V_84 -> V_155 -> V_41 ) ,
& V_84 -> V_90 , V_84 -> V_198 ,
V_84 -> V_169 -> V_197 ) ;
break;
case V_231 :
if ( V_84 -> V_229 )
F_19 ( L_23 ,
F_22 ( V_84 -> V_155 -> V_41 ) ,
& V_84 -> V_90 , V_84 -> V_198 ) ;
break;
default:
F_38 () ;
break;
}
F_8 ( V_84 -> V_155 ) ;
F_9 ( V_84 , sizeof( * V_84 ) ) ;
}
int
F_73 ( struct V_29 * V_35 , T_1 V_15 , int V_232 )
{
struct V_83 * V_84 ;
struct V_59 * V_91 ;
struct V_59 * V_92 ;
int V_233 = 0 ;
F_41 (ctmp, cnxt, &peer->ksnp_conns) {
V_84 = F_27 ( V_91 , struct V_83 , V_89 ) ;
if ( ! V_15 || V_84 -> V_90 == V_15 ) {
V_233 ++ ;
F_42 ( V_84 , V_232 ) ;
}
}
return V_233 ;
}
int
F_107 ( struct V_83 * V_84 , int V_232 )
{
struct V_29 * V_35 = V_84 -> V_155 ;
T_1 V_15 = V_84 -> V_90 ;
int V_233 ;
F_45 ( & V_63 . V_64 ) ;
V_233 = F_73 ( V_35 , V_15 , V_232 ) ;
F_46 ( & V_63 . V_64 ) ;
return V_233 ;
}
int
F_108 ( struct V_31 V_32 , T_1 V_15 )
{
struct V_29 * V_35 ;
struct V_59 * V_74 ;
struct V_59 * V_98 ;
int V_99 ;
int V_100 ;
int V_8 ;
int V_233 = 0 ;
F_45 ( & V_63 . V_64 ) ;
if ( V_32 . V_34 != V_36 ) {
V_99 = ( int ) ( F_25 ( V_32 . V_34 ) - V_63 . V_101 ) ;
V_100 = ( int ) ( F_25 ( V_32 . V_34 ) - V_63 . V_101 ) ;
} else {
V_99 = 0 ;
V_100 = V_63 . V_79 - 1 ;
}
for ( V_8 = V_99 ; V_8 <= V_100 ; V_8 ++ ) {
F_41 (ptmp, pnxt,
&ksocknal_data.ksnd_peers[i]) {
V_35 = F_27 ( V_74 , struct V_29 , V_62 ) ;
if ( ! ( ( V_32 . V_34 == V_36 || V_32 . V_34 == V_35 -> V_41 . V_34 ) &&
( V_32 . V_37 == V_38 || V_32 . V_37 == V_35 -> V_41 . V_37 ) ) )
continue;
V_233 += F_73 ( V_35 , V_15 ,
0 ) ;
}
}
F_46 ( & V_63 . V_64 ) ;
if ( V_32 . V_34 == V_36 || V_32 . V_37 == V_38 || ! V_15 )
return 0 ;
if ( ! V_233 )
return - V_78 ;
else
return 0 ;
}
void
F_109 ( struct V_2 * V_3 , T_4 V_234 , int V_235 )
{
struct V_31 V_32 = { 0 } ;
V_32 . V_34 = V_234 ;
V_32 . V_37 = V_38 ;
F_21 ( V_58 , L_24 , F_110 ( V_234 ) ,
V_235 ? L_25 : L_26 ) ;
if ( ! V_235 ) {
F_108 ( V_32 , 0 ) ;
return;
}
}
void
F_111 ( struct V_2 * V_3 , T_4 V_34 , unsigned long * V_236 )
{
int V_237 = 1 ;
unsigned long V_206 = 0 ;
unsigned long V_238 = F_74 () ;
struct V_29 * V_35 = NULL ;
T_2 * V_239 = & V_63 . V_64 ;
struct V_31 V_32 = {
. V_34 = V_34 ,
. V_37 = V_240 ,
} ;
F_29 ( V_239 ) ;
V_35 = F_24 ( V_3 , V_32 ) ;
if ( V_35 ) {
struct V_59 * V_61 ;
struct V_83 * V_84 ;
int V_241 ;
F_26 (tmp, &peer->ksnp_conns) {
V_84 = F_27 ( V_61 , struct V_83 , V_89 ) ;
V_241 = V_84 -> V_156 -> V_187 -> V_188 ;
if ( V_241 < V_84 -> V_186 ) {
V_84 -> V_189 =
F_75 ( * V_172 . V_190 ) ;
V_35 -> V_46 = V_238 ;
V_84 -> V_186 = V_241 ;
}
}
V_206 = V_35 -> V_46 ;
if ( ! F_112 ( V_35 ) )
V_237 = 0 ;
}
F_31 ( V_239 ) ;
if ( V_206 )
* V_236 = V_206 ;
F_21 ( V_58 , L_27 ,
F_110 ( V_34 ) , V_35 ,
V_206 ? F_104 ( V_238 - V_206 ) : - 1 ,
V_237 ) ;
if ( ! V_237 )
return;
F_44 ( V_3 , V_32 , F_113 ( V_34 ) , F_114 () ) ;
F_45 ( V_239 ) ;
V_35 = F_24 ( V_3 , V_32 ) ;
if ( V_35 )
F_115 ( V_35 ) ;
F_46 ( V_239 ) ;
}
static void
F_116 ( struct V_29 * V_35 )
{
int V_69 ;
int V_8 ;
struct V_59 * V_61 ;
struct V_83 * V_84 ;
for ( V_69 = 0 ; ; V_69 ++ ) {
F_29 ( & V_63 . V_64 ) ;
V_8 = 0 ;
V_84 = NULL ;
F_26 (tmp, &peer->ksnp_conns) {
if ( V_8 ++ == V_69 ) {
V_84 = F_27 ( V_61 , struct V_83 ,
V_89 ) ;
F_53 ( V_84 ) ;
break;
}
}
F_31 ( & V_63 . V_64 ) ;
if ( ! V_84 )
break;
F_117 ( V_84 ) ;
F_88 ( V_84 ) ;
}
}
static int F_118 ( struct V_2 * V_3 , struct V_31 V_32 )
{
struct V_59 * V_242 ;
struct V_59 * V_243 ;
struct V_59 * V_61 ;
int V_77 = - V_78 ;
unsigned int V_244 = V_63 . V_79 ;
if ( V_32 . V_34 == V_36 ) {
V_242 = & V_63 . V_101 [ 0 ] ;
V_243 = & V_63 . V_101 [ V_244 - 1 ] ;
} else {
V_242 = F_25 ( V_32 . V_34 ) ;
V_243 = F_25 ( V_32 . V_34 ) ;
}
for ( V_61 = V_242 ; V_61 <= V_243 ; V_61 ++ ) {
int V_245 ;
for ( V_245 = 0 ; ; V_245 ++ ) {
struct V_29 * V_35 ;
int V_8 = 0 ;
F_29 ( & V_63 . V_64 ) ;
F_66 (peer, tmp, ksnp_list) {
if ( ! ( ( V_32 . V_34 == V_36 ||
V_32 . V_34 == V_35 -> V_41 . V_34 ) &&
( V_32 . V_37 == V_38 ||
V_32 . V_37 == V_35 -> V_41 . V_37 ) ) )
continue;
if ( V_8 ++ == V_245 ) {
F_30 ( V_35 ) ;
break;
}
}
F_31 ( & V_63 . V_64 ) ;
if ( ! V_8 )
break;
V_77 = 0 ;
F_116 ( V_35 ) ;
F_8 ( V_35 ) ;
}
}
return V_77 ;
}
static int
F_119 ( struct V_2 * V_3 , T_1 V_246 , T_1 V_247 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_1 * V_9 ;
int V_77 ;
int V_8 ;
int V_76 ;
struct V_59 * V_74 ;
struct V_29 * V_35 ;
struct V_59 * V_75 ;
struct V_14 * V_17 ;
if ( ! V_246 || ! V_247 )
return - V_94 ;
F_45 ( & V_63 . V_64 ) ;
V_9 = F_1 ( V_3 , V_246 ) ;
if ( V_9 ) {
V_77 = 0 ;
} else if ( V_6 -> V_10 == V_11 ) {
V_77 = - V_248 ;
} else {
V_9 = & V_6 -> V_12 [ V_6 -> V_10 ++ ] ;
V_9 -> V_13 = V_246 ;
V_9 -> V_119 = V_247 ;
V_9 -> V_67 = 0 ;
V_9 -> V_68 = 0 ;
for ( V_8 = 0 ; V_8 < V_63 . V_79 ; V_8 ++ ) {
F_26 (ptmp, &ksocknal_data.ksnd_peers[i]) {
V_35 = F_27 ( V_74 , struct V_29 ,
V_62 ) ;
for ( V_76 = 0 ; V_76 < V_35 -> V_65 ; V_76 ++ )
if ( V_35 -> V_66 [ V_76 ] == V_246 )
V_9 -> V_68 ++ ;
F_26 (rtmp, &peer->ksnp_routes) {
V_17 = F_27 ( V_75 , struct V_14 ,
V_81 ) ;
if ( V_17 -> V_82 == V_246 )
V_9 -> V_67 ++ ;
}
}
}
V_77 = 0 ;
}
F_46 ( & V_63 . V_64 ) ;
return V_77 ;
}
static void
F_120 ( struct V_29 * V_35 , T_1 V_15 )
{
struct V_59 * V_61 ;
struct V_59 * V_95 ;
struct V_14 * V_17 ;
struct V_83 * V_84 ;
int V_8 ;
int V_76 ;
for ( V_8 = 0 ; V_8 < V_35 -> V_65 ; V_8 ++ )
if ( V_35 -> V_66 [ V_8 ] == V_15 ) {
for ( V_76 = V_8 + 1 ; V_76 < V_35 -> V_65 ; V_76 ++ )
V_35 -> V_66 [ V_76 - 1 ] =
V_35 -> V_66 [ V_76 ] ;
V_35 -> V_65 -- ;
break;
}
F_41 (tmp, nxt, &peer->ksnp_routes) {
V_17 = F_27 ( V_61 , struct V_14 , V_81 ) ;
if ( V_17 -> V_82 != V_15 )
continue;
if ( V_17 -> V_28 ) {
V_17 -> V_82 = 0 ;
} else {
F_40 ( V_17 ) ;
}
}
F_41 (tmp, nxt, &peer->ksnp_conns) {
V_84 = F_27 ( V_61 , struct V_83 , V_89 ) ;
if ( V_84 -> V_87 == V_15 )
F_42 ( V_84 , 0 ) ;
}
}
static int
F_121 ( struct V_2 * V_3 , T_1 V_246 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
int V_77 = - V_78 ;
struct V_59 * V_61 ;
struct V_59 * V_95 ;
struct V_29 * V_35 ;
T_1 V_249 ;
int V_8 ;
int V_76 ;
F_45 ( & V_63 . V_64 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_10 ; V_8 ++ ) {
V_249 = V_6 -> V_12 [ V_8 ] . V_13 ;
if ( ! ( ! V_246 || V_246 == V_249 ) )
continue;
V_77 = 0 ;
for ( V_76 = V_8 + 1 ; V_76 < V_6 -> V_10 ; V_76 ++ )
V_6 -> V_12 [ V_76 - 1 ] =
V_6 -> V_12 [ V_76 ] ;
V_6 -> V_10 -- ;
for ( V_76 = 0 ; V_76 < V_63 . V_79 ; V_76 ++ ) {
F_41 (tmp, nxt,
&ksocknal_data.ksnd_peers[j]) {
V_35 = F_27 ( V_61 , struct V_29 , V_62 ) ;
if ( V_35 -> V_40 != V_3 )
continue;
F_120 ( V_35 , V_249 ) ;
}
}
}
F_46 ( & V_63 . V_64 ) ;
return V_77 ;
}
int
F_122 ( struct V_2 * V_3 , unsigned int V_250 , void * V_251 )
{
struct V_31 V_32 = { 0 } ;
struct V_252 * V_253 = V_251 ;
int V_77 ;
switch ( V_250 ) {
case V_254 : {
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_1 * V_9 ;
F_29 ( & V_63 . V_64 ) ;
if ( V_253 -> V_255 >= ( T_1 ) V_6 -> V_10 ) {
V_77 = - V_78 ;
} else {
V_77 = 0 ;
V_9 = & V_6 -> V_12 [ V_253 -> V_255 ] ;
V_253 -> V_256 [ 0 ] = V_9 -> V_13 ;
V_253 -> V_256 [ 1 ] = V_9 -> V_119 ;
V_253 -> V_256 [ 2 ] = V_9 -> V_68 ;
V_253 -> V_256 [ 3 ] = V_9 -> V_67 ;
}
F_31 ( & V_63 . V_64 ) ;
return V_77 ;
}
case V_257 :
return F_119 ( V_3 ,
V_253 -> V_256 [ 0 ] ,
V_253 -> V_256 [ 1 ] ) ;
case V_258 :
return F_121 ( V_3 ,
V_253 -> V_256 [ 0 ] ) ;
case V_259 : {
T_1 V_70 = 0 ;
T_1 V_4 = 0 ;
int V_16 = 0 ;
int V_72 = 0 ;
int V_73 = 0 ;
V_77 = F_34 ( V_3 , V_253 -> V_255 ,
& V_32 , & V_70 , & V_4 , & V_16 ,
& V_72 , & V_73 ) ;
if ( V_77 )
return V_77 ;
V_253 -> V_260 = V_32 . V_34 ;
V_253 -> V_255 = V_73 ;
V_253 -> V_256 [ 0 ] = V_4 ;
V_253 -> V_256 [ 1 ] = V_16 ;
V_253 -> V_256 [ 2 ] = V_70 ;
V_253 -> V_256 [ 3 ] = V_72 ;
V_253 -> V_256 [ 4 ] = V_32 . V_37 ;
return 0 ;
}
case V_261 :
V_32 . V_34 = V_253 -> V_260 ;
V_32 . V_37 = V_240 ;
return F_44 ( V_3 , V_32 ,
V_253 -> V_256 [ 0 ] ,
V_253 -> V_256 [ 1 ] ) ;
case V_262 :
V_32 . V_34 = V_253 -> V_260 ;
V_32 . V_37 = V_38 ;
return F_48 ( V_3 , V_32 ,
V_253 -> V_256 [ 0 ] ) ;
case V_263 : {
int V_264 ;
int V_265 ;
int V_266 ;
struct V_83 * V_84 ;
V_84 = F_52 ( V_3 , V_253 -> V_255 ) ;
if ( ! V_84 )
return - V_78 ;
F_123 ( V_84 , & V_264 , & V_265 , & V_266 ) ;
V_253 -> V_255 = V_264 ;
V_253 -> V_260 = V_84 -> V_155 -> V_41 . V_34 ;
V_253 -> V_267 = V_266 ;
V_253 -> V_256 [ 0 ] = V_84 -> V_90 ;
V_253 -> V_256 [ 1 ] = V_84 -> V_198 ;
V_253 -> V_256 [ 2 ] = V_84 -> V_87 ;
V_253 -> V_256 [ 3 ] = V_84 -> V_85 ;
V_253 -> V_256 [ 4 ] = V_84 -> V_184 -> V_199 -> V_268 ;
V_253 -> V_256 [ 5 ] = V_265 ;
V_253 -> V_256 [ 6 ] = V_84 -> V_155 -> V_41 . V_37 ;
F_88 ( V_84 ) ;
return 0 ;
}
case V_269 :
V_32 . V_34 = V_253 -> V_260 ;
V_32 . V_37 = V_38 ;
return F_108 ( V_32 ,
V_253 -> V_256 [ 0 ] ) ;
case V_270 :
if ( V_253 -> V_260 == V_3 -> V_176 )
return 0 ;
F_19 ( L_28 ,
F_110 ( V_253 -> V_260 ) ,
F_110 ( V_3 -> V_176 ) ) ;
return - V_94 ;
case V_271 :
V_32 . V_34 = V_253 -> V_260 ;
V_32 . V_37 = V_38 ;
return F_118 ( V_3 , V_32 ) ;
default:
return - V_94 ;
}
}
static void
F_124 ( void )
{
F_2 ( ! F_7 ( & V_63 . V_272 ) ) ;
if ( V_63 . V_105 ) {
struct V_103 * V_104 ;
int V_8 ;
F_125 (info, i, ksocknal_data.ksnd_sched_info) {
if ( V_104 -> V_108 ) {
F_9 ( V_104 -> V_108 ,
V_104 -> V_273 *
sizeof( V_104 -> V_108 [ 0 ] ) ) ;
}
}
F_126 ( V_63 . V_105 ) ;
}
F_9 ( V_63 . V_101 ,
sizeof( struct V_59 ) *
V_63 . V_79 ) ;
F_96 ( & V_63 . V_274 ) ;
if ( ! F_23 ( & V_63 . V_275 ) ) {
struct V_59 V_209 ;
struct V_148 * V_149 ;
struct V_148 * V_208 ;
F_77 ( & V_209 , & V_63 . V_275 ) ;
F_89 ( & V_63 . V_275 ) ;
F_97 ( & V_63 . V_274 ) ;
F_80 (tx, temp, &zlist, tx_list) {
F_33 ( & V_149 -> V_196 ) ;
F_9 ( V_149 , V_149 -> V_276 ) ;
}
} else {
F_97 ( & V_63 . V_274 ) ;
}
}
static void
F_127 ( void )
{
struct V_103 * V_104 ;
struct V_102 * V_106 ;
int V_8 ;
int V_76 ;
F_2 ( ! V_63 . V_277 ) ;
switch ( V_63 . V_278 ) {
default:
F_2 ( 0 ) ;
case V_279 :
case V_280 :
F_2 ( V_63 . V_101 ) ;
for ( V_8 = 0 ; V_8 < V_63 . V_79 ; V_8 ++ )
F_2 ( F_23 ( & V_63 . V_101 [ V_8 ] ) ) ;
F_2 ( F_23 ( & V_63 . V_281 ) ) ;
F_2 ( F_23 ( & V_63 . V_282 ) ) ;
F_2 ( F_23 ( & V_63 . V_219 ) ) ;
F_2 ( F_23 ( & V_63 . V_141 ) ) ;
F_2 ( F_23 ( & V_63 . V_283 ) ) ;
if ( V_63 . V_105 ) {
F_125 (info, i,
ksocknal_data.ksnd_sched_info) {
if ( ! V_104 -> V_108 )
continue;
for ( V_76 = 0 ; V_76 < V_104 -> V_273 ; V_76 ++ ) {
V_106 = & V_104 -> V_108 [ V_76 ] ;
F_2 ( F_23 (
& V_106 -> V_217 ) ) ;
F_2 ( F_23 (
& V_106 -> V_284 ) ) ;
F_2 ( F_23 (
& V_106 -> V_285 ) ) ;
F_2 ( ! V_106 -> V_109 ) ;
}
}
}
V_63 . V_286 = 1 ;
F_128 ( & V_63 . V_142 ) ;
F_128 ( & V_63 . V_204 ) ;
if ( V_63 . V_105 ) {
F_125 (info, i,
ksocknal_data.ksnd_sched_info) {
if ( ! V_104 -> V_108 )
continue;
for ( V_76 = 0 ; V_76 < V_104 -> V_273 ; V_76 ++ ) {
V_106 = & V_104 -> V_108 [ V_76 ] ;
F_128 ( & V_106 -> V_218 ) ;
}
}
}
V_8 = 4 ;
F_29 ( & V_63 . V_64 ) ;
while ( V_63 . V_287 ) {
V_8 ++ ;
F_21 ( ( ( V_8 & ( - V_8 ) ) == V_8 ) ? V_288 : V_58 ,
L_29 ,
V_63 . V_287 ) ;
F_31 ( & V_63 . V_64 ) ;
F_129 ( V_289 ) ;
F_130 ( F_103 ( 1 ) ) ;
F_29 ( & V_63 . V_64 ) ;
}
F_31 ( & V_63 . V_64 ) ;
F_124 () ;
V_63 . V_278 = V_290 ;
break;
}
F_131 ( V_291 ) ;
}
static T_3
F_132 ( void )
{
return F_133 () ;
}
static int
F_134 ( void )
{
struct V_103 * V_104 ;
int V_77 ;
int V_8 ;
F_2 ( V_63 . V_278 == V_290 ) ;
F_2 ( ! V_63 . V_277 ) ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_63 . V_79 = V_292 ;
F_4 ( V_63 . V_101 ,
sizeof( struct V_59 ) *
V_63 . V_79 ) ;
if ( ! V_63 . V_101 )
return - V_39 ;
for ( V_8 = 0 ; V_8 < V_63 . V_79 ; V_8 ++ )
F_15 ( & V_63 . V_101 [ V_8 ] ) ;
F_135 ( & V_63 . V_64 ) ;
F_15 ( & V_63 . V_281 ) ;
F_16 ( & V_63 . V_202 ) ;
F_15 ( & V_63 . V_282 ) ;
F_15 ( & V_63 . V_219 ) ;
F_15 ( & V_63 . V_203 ) ;
F_136 ( & V_63 . V_204 ) ;
F_16 ( & V_63 . V_139 ) ;
F_15 ( & V_63 . V_141 ) ;
F_15 ( & V_63 . V_283 ) ;
F_136 ( & V_63 . V_142 ) ;
F_16 ( & V_63 . V_274 ) ;
F_15 ( & V_63 . V_275 ) ;
V_63 . V_278 = V_280 ;
F_137 ( V_291 ) ;
V_63 . V_105 = F_138 ( F_14 () ,
sizeof( * V_104 ) ) ;
if ( ! V_63 . V_105 )
goto V_215;
F_125 (info, i, ksocknal_data.ksnd_sched_info) {
struct V_102 * V_106 ;
int V_293 ;
V_293 = F_139 ( F_14 () , V_8 ) ;
if ( * V_172 . V_294 > 0 ) {
V_293 = F_58 ( V_293 , * V_172 . V_294 ) ;
} else {
V_293 = F_58 ( F_140 ( V_295 , V_293 >> 1 ) , V_293 ) ;
}
V_104 -> V_273 = V_293 ;
V_104 -> V_268 = V_8 ;
F_13 ( V_104 -> V_108 , F_14 () , V_8 ,
V_104 -> V_273 * sizeof( * V_106 ) ) ;
if ( ! V_104 -> V_108 )
goto V_215;
for (; V_293 > 0 ; V_293 -- ) {
V_106 = & V_104 -> V_108 [ V_293 - 1 ] ;
V_106 -> V_199 = V_104 ;
F_16 ( & V_106 -> V_201 ) ;
F_15 ( & V_106 -> V_284 ) ;
F_15 ( & V_106 -> V_217 ) ;
F_15 ( & V_106 -> V_285 ) ;
F_136 ( & V_106 -> V_218 ) ;
}
}
V_63 . V_296 = 0 ;
V_63 . V_297 = 0 ;
V_63 . V_298 = F_141 () ;
if ( * V_172 . V_299 < V_300 + 1 )
* V_172 . V_299 = V_300 + 1 ;
if ( * V_172 . V_301 <
* V_172 . V_299 ) {
V_172 . V_301 =
V_172 . V_299 ;
}
for ( V_8 = 0 ; V_8 < * V_172 . V_299 ; V_8 ++ ) {
char V_302 [ 16 ] ;
F_17 ( & V_63 . V_139 ) ;
V_63 . V_296 ++ ;
F_18 ( & V_63 . V_139 ) ;
snprintf ( V_302 , sizeof( V_302 ) , L_30 , V_8 ) ;
V_77 = F_142 ( V_303 ,
( void * ) ( ( V_304 ) V_8 ) , V_302 ) ;
if ( V_77 ) {
F_17 ( & V_63 . V_139 ) ;
V_63 . V_296 -- ;
F_18 ( & V_63 . V_139 ) ;
F_19 ( L_31 , V_77 ) ;
goto V_215;
}
}
V_77 = F_142 ( V_305 , NULL , L_32 ) ;
if ( V_77 ) {
F_19 ( L_33 , V_77 ) ;
goto V_215;
}
V_63 . V_278 = V_279 ;
return 0 ;
V_215:
F_127 () ;
return - V_306 ;
}
static void
F_143 ( struct V_2 * V_3 )
{
struct V_29 * V_35 = NULL ;
struct V_59 * V_61 ;
int V_8 ;
F_29 ( & V_63 . V_64 ) ;
for ( V_8 = 0 ; V_8 < V_63 . V_79 ; V_8 ++ ) {
F_26 (tmp, &ksocknal_data.ksnd_peers[i]) {
V_35 = F_27 ( V_61 , struct V_29 , V_62 ) ;
if ( V_35 -> V_40 == V_3 )
break;
V_35 = NULL ;
}
}
if ( V_35 ) {
struct V_14 * V_17 ;
struct V_83 * V_84 ;
F_144 ( L_34 ,
F_22 ( V_35 -> V_41 ) ,
F_7 ( & V_35 -> V_42 ) ,
V_35 -> V_307 , V_35 -> V_43 ,
V_35 -> V_44 , V_35 -> V_183 ,
V_35 -> V_47 ,
! F_23 ( & V_35 -> V_51 ) ,
! F_23 ( & V_35 -> V_52 ) ) ;
F_26 (tmp, &peer->ksnp_routes) {
V_17 = F_27 ( V_61 , struct V_14 , V_81 ) ;
F_144 ( L_35 ,
F_7 ( & V_17 -> V_18 ) ,
V_17 -> V_23 , V_17 -> V_24 ,
V_17 -> V_25 , V_17 -> V_26 ) ;
}
F_26 (tmp, &peer->ksnp_conns) {
V_84 = F_27 ( V_61 , struct V_83 , V_89 ) ;
F_144 ( L_36 ,
F_7 ( & V_84 -> V_158 ) ,
F_7 ( & V_84 -> V_157 ) ,
V_84 -> V_85 , V_84 -> V_200 ) ;
}
}
F_31 ( & V_63 . V_64 ) ;
}
void
F_145 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
int V_8 ;
struct V_31 V_308 = { 0 } ;
V_308 . V_34 = V_36 ;
V_308 . V_37 = V_38 ;
F_2 ( V_63 . V_278 == V_279 ) ;
F_2 ( V_63 . V_277 > 0 ) ;
F_17 ( & V_6 -> V_54 ) ;
V_6 -> V_55 = 1 ;
F_18 ( & V_6 -> V_54 ) ;
F_48 ( V_3 , V_308 , 0 ) ;
V_8 = 2 ;
F_17 ( & V_6 -> V_54 ) ;
while ( V_6 -> V_57 ) {
F_18 ( & V_6 -> V_54 ) ;
V_8 ++ ;
F_21 ( ( ( V_8 & ( - V_8 ) ) == V_8 ) ? V_288 : V_58 ,
L_37 ,
V_6 -> V_57 ) ;
F_129 ( V_289 ) ;
F_130 ( F_103 ( 1 ) ) ;
F_143 ( V_3 ) ;
F_17 ( & V_6 -> V_54 ) ;
}
F_18 ( & V_6 -> V_54 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_10 ; V_8 ++ ) {
F_2 ( ! V_6 -> V_12 [ V_8 ] . V_68 ) ;
F_2 ( ! V_6 -> V_12 [ V_8 ] . V_67 ) ;
}
F_33 ( & V_6 -> V_309 ) ;
F_9 ( V_6 , sizeof( * V_6 ) ) ;
V_63 . V_277 -- ;
if ( ! V_63 . V_277 )
F_127 () ;
}
static int
F_146 ( struct V_5 * V_6 )
{
char * * V_310 ;
int V_8 ;
int V_76 ;
int V_77 ;
int V_311 ;
V_311 = F_147 ( & V_310 ) ;
if ( V_311 <= 0 ) {
F_19 ( L_38 , V_311 ) ;
return V_311 ;
}
for ( V_8 = V_76 = 0 ; V_8 < V_311 ; V_8 ++ ) {
int V_312 ;
T_1 V_4 ;
T_1 V_313 ;
if ( ! strcmp ( V_310 [ V_8 ] , L_39 ) )
continue;
V_77 = F_148 ( V_310 [ V_8 ] , & V_312 , & V_4 , & V_313 ) ;
if ( V_77 ) {
F_144 ( L_40 ,
V_310 [ V_8 ] , V_77 ) ;
continue;
}
if ( ! V_312 ) {
F_144 ( L_41 ,
V_310 [ V_8 ] ) ;
continue;
}
if ( V_76 == V_11 ) {
F_144 ( L_42 ,
V_310 [ V_8 ] ) ;
continue;
}
V_6 -> V_12 [ V_76 ] . V_13 = V_4 ;
V_6 -> V_12 [ V_76 ] . V_119 = V_313 ;
F_149 ( V_6 -> V_12 [ V_76 ] . V_314 ,
V_310 [ V_8 ] , sizeof( V_6 -> V_12 [ V_76 ] . V_314 ) ) ;
V_76 ++ ;
}
F_150 ( V_310 , V_311 ) ;
if ( ! V_76 )
F_19 ( L_43 ) ;
return V_76 ;
}
static int
F_151 ( struct V_5 * V_6 )
{
int V_315 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_10 ; V_8 ++ ) {
char * V_316 = & V_6 -> V_12 [ V_8 ] . V_314 [ 0 ] ;
char * V_317 = strchr ( V_316 , ':' ) ;
int V_318 = 0 ;
struct V_5 * V_61 ;
int V_76 ;
if ( V_317 )
* V_317 = 0 ;
F_66 (tmp, &ksocknal_data.ksnd_nets, ksnn_list) {
for ( V_76 = 0 ; ! V_318 && V_76 < V_61 -> V_10 ; V_76 ++ ) {
char * V_319 =
& V_61 -> V_12 [ V_76 ] . V_314 [ 0 ] ;
char * V_320 = strchr ( V_319 , ':' ) ;
if ( V_320 )
* V_320 = 0 ;
V_318 = ! strcmp ( V_316 , V_319 ) ;
if ( V_320 )
* V_320 = ':' ;
}
if ( V_318 )
break;
}
V_315 += ! V_318 ;
if ( V_317 )
* V_317 = ':' ;
}
return V_315 ;
}
static int
F_152 ( struct V_103 * V_104 )
{
int V_293 ;
int V_77 = 0 ;
int V_8 ;
if ( ! V_104 -> V_107 ) {
if ( * V_172 . V_294 > 0 ) {
V_293 = V_104 -> V_273 ;
} else {
V_293 = F_139 ( F_14 () ,
V_104 -> V_268 ) ;
V_293 = F_58 ( F_140 ( V_295 , V_293 >> 1 ) , V_293 ) ;
V_293 = F_58 ( V_321 , V_293 ) ;
}
V_293 = F_58 ( V_293 , V_104 -> V_273 ) ;
} else {
F_2 ( V_104 -> V_107 <= V_104 -> V_273 ) ;
V_293 = F_58 ( 2 , V_104 -> V_273 - V_104 -> V_107 ) ;
}
for ( V_8 = 0 ; V_8 < V_293 ; V_8 ++ ) {
long V_32 ;
char V_302 [ 20 ] ;
struct V_102 * V_106 ;
V_32 = F_153 ( V_104 -> V_268 , V_104 -> V_107 + V_8 ) ;
V_106 = & V_104 -> V_108 [ F_154 ( V_32 ) ] ;
snprintf ( V_302 , sizeof( V_302 ) , L_44 ,
V_104 -> V_268 , ( int ) ( V_106 - & V_104 -> V_108 [ 0 ] ) ) ;
V_77 = F_142 ( V_322 ,
( void * ) V_32 , V_302 ) ;
if ( ! V_77 )
continue;
F_19 ( L_45 ,
V_104 -> V_268 , V_104 -> V_107 + V_8 , V_77 ) ;
break;
}
V_104 -> V_107 += V_8 ;
return V_77 ;
}
static int
F_155 ( struct V_5 * V_6 , T_1 * V_323 , int V_324 )
{
int V_325 = F_151 ( V_6 ) ;
int V_77 ;
int V_8 ;
F_2 ( V_324 > 0 && V_324 <= F_156 ( F_14 () ) ) ;
for ( V_8 = 0 ; V_8 < V_324 ; V_8 ++ ) {
struct V_103 * V_104 ;
int V_33 = ! V_323 ? V_8 : V_323 [ V_8 ] ;
F_2 ( V_33 < F_156 ( F_14 () ) ) ;
V_104 = V_63 . V_105 [ V_33 ] ;
if ( ! V_325 && V_104 -> V_107 > 0 )
continue;
V_77 = F_152 ( V_104 ) ;
if ( V_77 )
return V_77 ;
}
return 0 ;
}
int
F_157 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
int V_77 ;
int V_8 ;
F_2 ( V_3 -> V_326 == & V_327 ) ;
if ( V_63 . V_278 == V_290 ) {
V_77 = F_134 () ;
if ( V_77 )
return V_77 ;
}
F_4 ( V_6 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
goto V_328;
F_16 ( & V_6 -> V_54 ) ;
V_6 -> V_329 = F_132 () ;
V_3 -> V_7 = V_6 ;
V_3 -> V_330 = * V_172 . V_331 ;
V_3 -> V_332 = * V_172 . V_333 ;
V_3 -> V_334 = * V_172 . V_335 ;
V_3 -> V_336 = * V_172 . V_337 ;
if ( ! V_3 -> V_338 [ 0 ] ) {
V_77 = F_146 ( V_6 ) ;
if ( V_77 <= 0 )
goto V_339;
V_6 -> V_10 = 1 ;
} else {
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ ) {
int V_312 ;
if ( ! V_3 -> V_338 [ V_8 ] )
break;
V_77 = F_148 ( V_3 -> V_338 [ V_8 ] , & V_312 ,
& V_6 -> V_12 [ V_8 ] . V_13 ,
& V_6 -> V_12 [ V_8 ] . V_119 ) ;
if ( V_77 ) {
F_19 ( L_40 ,
V_3 -> V_338 [ V_8 ] , V_77 ) ;
goto V_339;
}
if ( ! V_312 ) {
F_19 ( L_46 ,
V_3 -> V_338 [ V_8 ] ) ;
goto V_339;
}
F_149 ( V_6 -> V_12 [ V_8 ] . V_314 ,
V_3 -> V_338 [ V_8 ] ,
sizeof( V_6 -> V_12 [ V_8 ] . V_314 ) ) ;
}
V_6 -> V_10 = V_8 ;
}
V_77 = F_155 ( V_6 , V_3 -> V_340 , V_3 -> V_341 ) ;
if ( V_77 )
goto V_339;
V_3 -> V_176 = F_158 ( F_159 ( V_3 -> V_176 ) ,
V_6 -> V_12 [ 0 ] . V_13 ) ;
F_77 ( & V_6 -> V_309 , & V_63 . V_281 ) ;
V_63 . V_277 ++ ;
return 0 ;
V_339:
F_9 ( V_6 , sizeof( * V_6 ) ) ;
V_328:
if ( ! V_63 . V_277 )
F_127 () ;
return - V_306 ;
}
static void T_5 F_160 ( void )
{
F_161 ( & V_327 ) ;
}
static int T_6 F_162 ( void )
{
int V_77 ;
F_163 ( V_342 > 4 ) ;
F_163 ( V_343 != V_344 ) ;
V_327 . V_345 = V_346 ;
V_327 . V_347 = F_157 ;
V_327 . V_348 = F_145 ;
V_327 . V_349 = F_122 ;
V_327 . V_350 = V_351 ;
V_327 . V_352 = V_353 ;
V_327 . V_354 = F_109 ;
V_327 . V_355 = F_111 ;
V_327 . V_356 = F_60 ;
V_77 = F_164 () ;
if ( V_77 )
return V_77 ;
F_165 ( & V_327 ) ;
return 0 ;
}
