static struct V_1 *
F_1 ( T_1 * V_2 , T_2 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
struct V_1 * V_8 ;
for ( V_7 = 0 ; V_7 < V_5 -> V_9 ; V_7 ++ ) {
F_2 ( V_7 < V_10 ) ;
V_8 = & V_5 -> V_11 [ V_7 ] ;
if ( V_8 -> V_12 == V_3 )
return V_8 ;
}
return NULL ;
}
static struct V_13 *
F_3 ( T_2 V_14 , int V_15 )
{
struct V_13 * V_16 ;
F_4 ( V_16 , sizeof( * V_16 ) ) ;
if ( ! V_16 )
return NULL ;
F_5 ( & V_16 -> V_17 , 1 ) ;
V_16 -> V_18 = NULL ;
V_16 -> V_19 = 0 ;
V_16 -> V_20 = V_14 ;
V_16 -> V_21 = V_15 ;
V_16 -> V_22 = 0 ;
V_16 -> V_23 = 0 ;
V_16 -> V_24 = 0 ;
V_16 -> V_25 = 0 ;
V_16 -> V_26 = 0 ;
V_16 -> V_27 = 0 ;
return V_16 ;
}
void
F_6 ( struct V_13 * V_16 )
{
F_2 ( ! F_7 ( & V_16 -> V_17 ) ) ;
if ( V_16 -> V_18 )
F_8 ( V_16 -> V_18 ) ;
F_9 ( V_16 , sizeof( * V_16 ) ) ;
}
static int
F_10 ( struct V_28 * * V_29 , T_1 * V_2 ,
T_3 V_30 )
{
int V_31 = F_11 ( V_30 . V_32 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_28 * V_33 ;
F_2 ( V_30 . V_32 != V_34 ) ;
F_2 ( V_30 . V_35 != V_36 ) ;
F_2 ( ! F_12 () ) ;
F_13 ( V_33 , F_14 () , V_31 , sizeof( * V_33 ) ) ;
if ( ! V_33 )
return - V_37 ;
V_33 -> V_38 = V_2 ;
V_33 -> V_39 = V_30 ;
F_5 ( & V_33 -> V_40 , 1 ) ;
V_33 -> V_41 = 0 ;
V_33 -> V_42 = 0 ;
V_33 -> V_43 = NULL ;
V_33 -> V_44 = 0 ;
V_33 -> V_45 = V_46 + 1 ;
F_15 ( & V_33 -> V_47 ) ;
F_15 ( & V_33 -> V_48 ) ;
F_15 ( & V_33 -> V_49 ) ;
F_15 ( & V_33 -> V_50 ) ;
F_16 ( & V_33 -> V_51 ) ;
F_17 ( & V_5 -> V_52 ) ;
if ( V_5 -> V_53 ) {
F_18 ( & V_5 -> V_52 ) ;
F_9 ( V_33 , sizeof( * V_33 ) ) ;
F_19 ( L_1 ) ;
return - V_54 ;
}
V_5 -> V_55 ++ ;
F_18 ( & V_5 -> V_52 ) ;
* V_29 = V_33 ;
return 0 ;
}
void
F_20 ( struct V_28 * V_33 )
{
struct V_4 * V_5 = V_33 -> V_38 -> V_6 ;
F_21 ( V_56 , L_2 ,
F_22 ( V_33 -> V_39 ) , V_33 ) ;
F_2 ( ! F_7 ( & V_33 -> V_40 ) ) ;
F_2 ( ! V_33 -> V_42 ) ;
F_2 ( F_23 ( & V_33 -> V_47 ) ) ;
F_2 ( F_23 ( & V_33 -> V_48 ) ) ;
F_2 ( F_23 ( & V_33 -> V_49 ) ) ;
F_2 ( F_23 ( & V_33 -> V_50 ) ) ;
F_9 ( V_33 , sizeof( * V_33 ) ) ;
F_17 ( & V_5 -> V_52 ) ;
V_5 -> V_55 -- ;
F_18 ( & V_5 -> V_52 ) ;
}
struct V_28 *
F_24 ( T_1 * V_2 , T_3 V_30 )
{
struct V_57 * V_58 = F_25 ( V_30 . V_32 ) ;
struct V_57 * V_59 ;
struct V_28 * V_33 ;
F_26 (tmp, peer_list) {
V_33 = F_27 ( V_59 , struct V_28 , V_60 ) ;
F_2 ( ! V_33 -> V_41 ) ;
if ( V_33 -> V_38 != V_2 )
continue;
if ( V_33 -> V_39 . V_32 != V_30 . V_32 ||
V_33 -> V_39 . V_35 != V_30 . V_35 )
continue;
F_21 ( V_56 , L_3 ,
V_33 , F_22 ( V_30 ) ,
F_7 ( & V_33 -> V_40 ) ) ;
return V_33 ;
}
return NULL ;
}
struct V_28 *
F_28 ( T_1 * V_2 , T_3 V_30 )
{
struct V_28 * V_33 ;
F_29 ( & V_61 . V_62 ) ;
V_33 = F_24 ( V_2 , V_30 ) ;
if ( V_33 )
F_30 ( V_33 ) ;
F_31 ( & V_61 . V_62 ) ;
return V_33 ;
}
static void
F_32 ( struct V_28 * V_33 )
{
int V_7 ;
T_2 V_3 ;
struct V_1 * V_8 ;
for ( V_7 = 0 ; V_7 < V_33 -> V_63 ; V_7 ++ ) {
F_2 ( V_7 < V_10 ) ;
V_3 = V_33 -> V_64 [ V_7 ] ;
V_8 = F_1 ( V_33 -> V_38 , V_3 ) ;
F_2 ( V_8 ) ;
F_21 ( V_56 , L_4 ,
V_33 , V_8 , V_8 -> V_65 ) ;
V_8 -> V_66 -- ;
}
F_2 ( F_23 ( & V_33 -> V_47 ) ) ;
F_2 ( F_23 ( & V_33 -> V_48 ) ) ;
F_2 ( ! V_33 -> V_41 ) ;
V_33 -> V_41 = 1 ;
F_33 ( & V_33 -> V_60 ) ;
F_8 ( V_33 ) ;
}
static int
F_34 ( T_1 * V_2 , int V_67 ,
T_3 * V_30 , T_2 * V_68 , T_2 * V_69 ,
int * V_15 , int * V_70 , int * V_71 )
{
struct V_28 * V_33 ;
struct V_57 * V_72 ;
struct V_13 * V_16 ;
struct V_57 * V_73 ;
int V_7 ;
int V_74 ;
int V_75 = - V_76 ;
F_29 ( & V_61 . V_62 ) ;
for ( V_7 = 0 ; V_7 < V_61 . V_77 ; V_7 ++ ) {
F_26 (ptmp, &ksocknal_data.ksnd_peers[i]) {
V_33 = F_27 ( V_72 , struct V_28 , V_60 ) ;
if ( V_33 -> V_38 != V_2 )
continue;
if ( ! V_33 -> V_63 &&
F_23 ( & V_33 -> V_48 ) ) {
if ( V_67 -- > 0 )
continue;
* V_30 = V_33 -> V_39 ;
* V_68 = 0 ;
* V_69 = 0 ;
* V_15 = 0 ;
* V_70 = 0 ;
* V_71 = 0 ;
V_75 = 0 ;
goto V_78;
}
for ( V_74 = 0 ; V_74 < V_33 -> V_63 ; V_74 ++ ) {
if ( V_67 -- > 0 )
continue;
* V_30 = V_33 -> V_39 ;
* V_68 = V_33 -> V_64 [ V_74 ] ;
* V_69 = 0 ;
* V_15 = 0 ;
* V_70 = 0 ;
* V_71 = 0 ;
V_75 = 0 ;
goto V_78;
}
F_26 (rtmp, &peer->ksnp_routes) {
if ( V_67 -- > 0 )
continue;
V_16 = F_27 ( V_73 , struct V_13 ,
V_79 ) ;
* V_30 = V_33 -> V_39 ;
* V_68 = V_16 -> V_80 ;
* V_69 = V_16 -> V_20 ;
* V_15 = V_16 -> V_21 ;
* V_70 = V_16 -> V_26 ;
* V_71 = V_16 -> V_27 ;
V_75 = 0 ;
goto V_78;
}
}
}
V_78:
F_31 ( & V_61 . V_62 ) ;
return V_75 ;
}
static void
F_35 ( struct V_13 * V_16 ,
struct V_81 * V_82 )
{
struct V_28 * V_33 = V_16 -> V_18 ;
int type = V_82 -> V_83 ;
struct V_1 * V_8 ;
V_82 -> V_84 = V_16 ;
F_36 ( V_16 ) ;
if ( V_16 -> V_80 != V_82 -> V_85 ) {
if ( ! V_16 -> V_80 ) {
F_21 ( V_56 , L_5 ,
F_22 ( V_33 -> V_39 ) ,
& V_16 -> V_20 ,
& V_82 -> V_85 ) ;
} else {
F_21 ( V_56 , L_6 ,
F_22 ( V_33 -> V_39 ) ,
& V_16 -> V_20 ,
& V_16 -> V_80 ,
& V_82 -> V_85 ) ;
V_8 = F_1 ( V_16 -> V_18 -> V_38 ,
V_16 -> V_80 ) ;
if ( V_8 )
V_8 -> V_65 -- ;
}
V_16 -> V_80 = V_82 -> V_85 ;
V_8 = F_1 ( V_16 -> V_18 -> V_38 ,
V_16 -> V_80 ) ;
if ( V_8 )
V_8 -> V_65 ++ ;
}
V_16 -> V_24 |= ( 1 << type ) ;
V_16 -> V_26 ++ ;
V_16 -> V_19 = 0 ;
}
static void
F_37 ( struct V_28 * V_33 , struct V_13 * V_16 )
{
struct V_57 * V_59 ;
struct V_81 * V_82 ;
struct V_13 * V_86 ;
F_2 ( ! V_33 -> V_41 ) ;
F_2 ( ! V_16 -> V_18 ) ;
F_2 ( ! V_16 -> V_22 ) ;
F_2 ( ! V_16 -> V_23 ) ;
F_2 ( ! V_16 -> V_24 ) ;
F_26 (tmp, &peer->ksnp_routes) {
V_86 = F_27 ( V_59 , struct V_13 , V_79 ) ;
if ( V_86 -> V_20 == V_16 -> V_20 ) {
F_19 ( L_7 ,
F_22 ( V_33 -> V_39 ) ,
& V_16 -> V_20 ) ;
F_38 () ;
}
}
V_16 -> V_18 = V_33 ;
F_30 ( V_33 ) ;
F_39 ( & V_16 -> V_79 , & V_33 -> V_48 ) ;
F_26 (tmp, &peer->ksnp_conns) {
V_82 = F_27 ( V_59 , struct V_81 , V_87 ) ;
if ( V_82 -> V_88 != V_16 -> V_20 )
continue;
F_35 ( V_16 , V_82 ) ;
}
}
static void
F_40 ( struct V_13 * V_16 )
{
struct V_28 * V_33 = V_16 -> V_18 ;
struct V_1 * V_8 ;
struct V_81 * V_82 ;
struct V_57 * V_89 ;
struct V_57 * V_90 ;
F_2 ( ! V_16 -> V_25 ) ;
F_41 (ctmp, cnxt, &peer->ksnp_conns) {
V_82 = F_27 ( V_89 , struct V_81 , V_87 ) ;
if ( V_82 -> V_84 != V_16 )
continue;
F_42 ( V_82 , 0 ) ;
}
if ( V_16 -> V_80 ) {
V_8 = F_1 ( V_16 -> V_18 -> V_38 ,
V_16 -> V_80 ) ;
if ( V_8 )
V_8 -> V_65 -- ;
}
V_16 -> V_25 = 1 ;
F_33 ( & V_16 -> V_79 ) ;
F_43 ( V_16 ) ;
if ( F_23 ( & V_33 -> V_48 ) &&
F_23 ( & V_33 -> V_47 ) ) {
F_32 ( V_33 ) ;
}
}
int
F_44 ( T_1 * V_2 , T_3 V_30 , T_2 V_14 , int V_15 )
{
struct V_57 * V_59 ;
struct V_28 * V_33 ;
struct V_28 * V_91 ;
struct V_13 * V_16 ;
struct V_13 * V_86 ;
int V_75 ;
if ( V_30 . V_32 == V_34 ||
V_30 . V_35 == V_36 )
return - V_92 ;
V_75 = F_10 ( & V_33 , V_2 , V_30 ) ;
if ( V_75 )
return V_75 ;
V_16 = F_3 ( V_14 , V_15 ) ;
if ( ! V_16 ) {
F_8 ( V_33 ) ;
return - V_37 ;
}
F_45 ( & V_61 . V_62 ) ;
F_2 ( ! ( (struct V_4 * ) V_2 -> V_6 ) -> V_53 ) ;
V_91 = F_24 ( V_2 , V_30 ) ;
if ( V_91 ) {
F_8 ( V_33 ) ;
V_33 = V_91 ;
} else {
F_39 ( & V_33 -> V_60 ,
F_25 ( V_30 . V_32 ) ) ;
}
V_86 = NULL ;
F_26 (tmp, &peer->ksnp_routes) {
V_86 = F_27 ( V_59 , struct V_13 , V_79 ) ;
if ( V_86 -> V_20 == V_14 )
break;
V_86 = NULL ;
}
if ( ! V_86 ) {
F_37 ( V_33 , V_16 ) ;
V_16 -> V_27 ++ ;
} else {
F_43 ( V_16 ) ;
V_86 -> V_27 ++ ;
}
F_46 ( & V_61 . V_62 ) ;
return 0 ;
}
static void
F_47 ( struct V_28 * V_33 , T_2 V_3 )
{
struct V_81 * V_82 ;
struct V_13 * V_16 ;
struct V_57 * V_59 ;
struct V_57 * V_93 ;
int V_94 ;
F_2 ( ! V_33 -> V_41 ) ;
F_30 ( V_33 ) ;
F_41 (tmp, nxt, &peer->ksnp_routes) {
V_16 = F_27 ( V_59 , struct V_13 , V_79 ) ;
if ( ! ( ! V_3 || V_16 -> V_20 == V_3 ) )
continue;
V_16 -> V_27 = 0 ;
F_40 ( V_16 ) ;
}
V_94 = 0 ;
F_41 (tmp, nxt, &peer->ksnp_routes) {
V_16 = F_27 ( V_59 , struct V_13 , V_79 ) ;
V_94 += V_16 -> V_27 ;
}
if ( ! V_94 ) {
F_41 (tmp, nxt, &peer->ksnp_routes) {
V_16 = F_27 ( V_59 , struct V_13 , V_79 ) ;
F_2 ( ! V_16 -> V_27 ) ;
F_40 ( V_16 ) ;
}
F_41 (tmp, nxt, &peer->ksnp_conns) {
V_82 = F_27 ( V_59 , struct V_81 , V_87 ) ;
F_42 ( V_82 , 0 ) ;
}
}
F_8 ( V_33 ) ;
}
static int
F_48 ( T_1 * V_2 , T_3 V_30 , T_2 V_3 )
{
F_49 ( V_95 ) ;
struct V_57 * V_72 ;
struct V_57 * V_96 ;
struct V_28 * V_33 ;
int V_97 ;
int V_98 ;
int V_7 ;
int V_75 = - V_76 ;
F_45 ( & V_61 . V_62 ) ;
if ( V_30 . V_32 != V_34 ) {
V_97 = ( int ) ( F_25 ( V_30 . V_32 ) - V_61 . V_99 ) ;
V_98 = ( int ) ( F_25 ( V_30 . V_32 ) - V_61 . V_99 ) ;
} else {
V_97 = 0 ;
V_98 = V_61 . V_77 - 1 ;
}
for ( V_7 = V_97 ; V_7 <= V_98 ; V_7 ++ ) {
F_41 (ptmp, pnxt, &ksocknal_data.ksnd_peers[i]) {
V_33 = F_27 ( V_72 , struct V_28 , V_60 ) ;
if ( V_33 -> V_38 != V_2 )
continue;
if ( ! ( ( V_30 . V_32 == V_34 || V_33 -> V_39 . V_32 == V_30 . V_32 ) &&
( V_30 . V_35 == V_36 || V_33 -> V_39 . V_35 == V_30 . V_35 ) ) )
continue;
F_30 ( V_33 ) ;
F_47 ( V_33 , V_3 ) ;
if ( V_33 -> V_41 &&
! F_23 ( & V_33 -> V_49 ) ) {
F_2 ( F_23 ( & V_33 -> V_47 ) ) ;
F_2 ( F_23 ( & V_33 -> V_48 ) ) ;
F_50 ( & V_33 -> V_49 ,
& V_95 ) ;
}
F_8 ( V_33 ) ;
V_75 = 0 ;
}
}
F_46 ( & V_61 . V_62 ) ;
F_51 ( V_2 , & V_95 , 1 ) ;
return V_75 ;
}
static struct V_81 *
F_52 ( T_1 * V_2 , int V_67 )
{
struct V_28 * V_33 ;
struct V_57 * V_72 ;
struct V_81 * V_82 ;
struct V_57 * V_89 ;
int V_7 ;
F_29 ( & V_61 . V_62 ) ;
for ( V_7 = 0 ; V_7 < V_61 . V_77 ; V_7 ++ ) {
F_26 (ptmp, &ksocknal_data.ksnd_peers[i]) {
V_33 = F_27 ( V_72 , struct V_28 , V_60 ) ;
F_2 ( ! V_33 -> V_41 ) ;
if ( V_33 -> V_38 != V_2 )
continue;
F_26 (ctmp, &peer->ksnp_conns) {
if ( V_67 -- > 0 )
continue;
V_82 = F_27 ( V_89 , struct V_81 ,
V_87 ) ;
F_53 ( V_82 ) ;
F_31 ( & V_61 . V_62 ) ;
return V_82 ;
}
}
}
F_31 ( & V_61 . V_62 ) ;
return NULL ;
}
static struct V_100 *
F_54 ( unsigned int V_31 )
{
struct V_101 * V_102 = V_61 . V_103 [ V_31 ] ;
struct V_100 * V_104 ;
int V_7 ;
F_2 ( V_102 -> V_105 > 0 ) ;
V_104 = & V_102 -> V_106 [ 0 ] ;
for ( V_7 = 1 ; V_7 < V_102 -> V_105 ; V_7 ++ ) {
if ( V_104 -> V_107 > V_102 -> V_106 [ V_7 ] . V_107 )
V_104 = & V_102 -> V_106 [ V_7 ] ;
}
return V_104 ;
}
static int
F_55 ( T_1 * V_2 , T_2 * V_108 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
int V_109 ;
F_29 ( & V_61 . V_62 ) ;
V_109 = V_5 -> V_9 ;
F_2 ( V_109 <= V_10 ) ;
if ( V_109 < 2 ) {
F_31 ( & V_61 . V_62 ) ;
return 0 ;
}
for ( V_7 = 0 ; V_7 < V_109 ; V_7 ++ ) {
V_108 [ V_7 ] = V_5 -> V_11 [ V_7 ] . V_12 ;
F_2 ( V_108 [ V_7 ] ) ;
}
F_31 ( & V_61 . V_62 ) ;
return V_109 ;
}
static int
F_56 ( struct V_1 * V_8 , T_2 * V_110 , int V_111 )
{
int V_112 = 0 ;
int V_113 = 0 ;
int V_114 = - 1 ;
int V_115 ;
int V_116 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_111 ; V_7 ++ ) {
if ( ! V_110 [ V_7 ] )
continue;
V_115 = V_110 [ V_7 ] ^ V_8 -> V_12 ;
V_116 = ! ( V_115 & V_8 -> V_117 ) ? 1 : 0 ;
if ( ! ( V_114 < 0 ||
V_112 < V_116 ||
( V_112 == V_116 &&
V_113 > V_115 ) ) )
continue;
V_114 = V_7 ;
V_112 = V_116 ;
V_113 = V_115 ;
}
F_2 ( V_114 >= 0 ) ;
return V_114 ;
}
static int
F_57 ( struct V_28 * V_33 , T_2 * V_118 , int V_119 )
{
T_4 * V_120 = & V_61 . V_62 ;
struct V_4 * V_5 = V_33 -> V_38 -> V_6 ;
struct V_1 * V_8 ;
struct V_1 * V_121 ;
int V_122 ;
int V_7 ;
int V_74 ;
int V_123 ;
T_2 V_3 ;
T_2 V_124 ;
int V_116 ;
int V_112 ;
int V_125 ;
F_45 ( V_120 ) ;
F_2 ( V_119 <= V_10 ) ;
F_2 ( V_5 -> V_9 <= V_10 ) ;
V_122 = ( V_5 -> V_9 < 2 ) ? 0 :
F_58 ( V_119 , V_5 -> V_9 ) ;
for ( V_7 = 0 ; V_33 -> V_63 < V_122 ; V_7 ++ ) {
if ( V_7 < V_33 -> V_63 ) {
V_3 = V_33 -> V_64 [ V_7 ] ;
V_121 = F_1 ( V_33 -> V_38 , V_3 ) ;
F_2 ( V_121 ) ;
} else {
F_2 ( V_7 == V_33 -> V_63 ) ;
V_121 = NULL ;
V_112 = 0 ;
V_125 = 0 ;
for ( V_74 = 0 ; V_74 < V_5 -> V_9 ; V_74 ++ ) {
V_8 = & V_5 -> V_11 [ V_74 ] ;
V_3 = V_8 -> V_12 ;
for ( V_123 = 0 ; V_123 < V_33 -> V_63 ; V_123 ++ )
if ( V_33 -> V_64 [ V_123 ] == V_3 )
break;
if ( V_123 < V_33 -> V_63 )
continue;
V_123 = F_56 ( V_8 , V_118 ,
V_119 ) ;
V_124 = V_3 ^ V_118 [ V_123 ] ;
V_116 = ! ( V_124 & V_8 -> V_117 ) ? 1 : 0 ;
if ( ! ( ! V_121 ||
V_112 < V_116 ||
( V_112 == V_116 &&
V_125 > V_8 -> V_66 ) ) )
continue;
V_121 = V_8 ;
V_112 = V_116 ;
V_125 = V_8 -> V_66 ;
}
F_2 ( V_121 ) ;
V_121 -> V_66 ++ ;
V_3 = V_121 -> V_12 ;
V_33 -> V_64 [ V_7 ] = V_3 ;
V_33 -> V_63 = V_7 + 1 ;
}
V_74 = F_56 ( V_121 , V_118 , V_119 ) ;
V_118 [ V_74 ] = 0 ;
}
memcpy ( V_118 , V_33 -> V_64 , V_122 * sizeof( * V_118 ) ) ;
F_46 ( V_120 ) ;
return V_122 ;
}
static void
F_59 ( struct V_28 * V_33 , int V_15 ,
T_2 * V_126 , int V_127 )
{
struct V_13 * V_128 = NULL ;
T_4 * V_120 = & V_61 . V_62 ;
T_1 * V_2 = V_33 -> V_38 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_57 * V_73 ;
struct V_13 * V_16 ;
struct V_1 * V_8 ;
struct V_1 * V_121 ;
int V_112 ;
int V_116 ;
int V_129 ;
int V_7 ;
int V_74 ;
F_45 ( V_120 ) ;
if ( V_5 -> V_9 < 2 ) {
F_46 ( V_120 ) ;
return;
}
F_2 ( V_127 <= V_10 ) ;
for ( V_7 = 0 ; V_7 < V_127 ; V_7 ++ ) {
if ( V_128 ) {
V_128 -> V_20 = V_126 [ V_7 ] ;
} else {
F_46 ( V_120 ) ;
V_128 = F_3 ( V_126 [ V_7 ] , V_15 ) ;
if ( ! V_128 )
return;
F_45 ( V_120 ) ;
}
if ( V_33 -> V_41 ) {
break;
}
V_16 = NULL ;
F_26 (rtmp, &peer->ksnp_routes) {
V_16 = F_27 ( V_73 , struct V_13 , V_79 ) ;
if ( V_16 -> V_20 == V_128 -> V_20 )
break;
V_16 = NULL ;
}
if ( V_16 )
continue;
V_121 = NULL ;
V_129 = 0 ;
V_112 = 0 ;
F_2 ( V_5 -> V_9 <= V_10 ) ;
for ( V_74 = 0 ; V_74 < V_5 -> V_9 ; V_74 ++ ) {
V_8 = & V_5 -> V_11 [ V_74 ] ;
F_26 (rtmp, &peer->ksnp_routes) {
V_16 = F_27 ( V_73 , struct V_13 ,
V_79 ) ;
if ( V_16 -> V_80 == V_8 -> V_12 )
break;
V_16 = NULL ;
}
if ( V_16 )
continue;
V_116 = ( ! ( ( V_8 -> V_12 ^
V_128 -> V_20 ) &
V_8 -> V_117 ) ) ? 1 : 0 ;
if ( ! ( ! V_121 ||
V_112 < V_116 ||
( V_112 == V_116 &&
V_129 > V_8 -> V_65 ) ) )
continue;
V_121 = V_8 ;
V_112 = V_116 ;
V_129 = V_8 -> V_65 ;
}
if ( ! V_121 )
continue;
V_128 -> V_80 = V_121 -> V_12 ;
V_121 -> V_65 ++ ;
F_37 ( V_33 , V_128 ) ;
V_128 = NULL ;
}
F_46 ( V_120 ) ;
if ( V_128 )
F_43 ( V_128 ) ;
}
int
F_60 ( T_1 * V_2 , struct V_130 * V_131 )
{
struct V_132 * V_133 ;
int V_75 ;
T_2 V_69 ;
int V_134 ;
V_75 = F_61 ( V_131 , 1 , & V_69 , & V_134 ) ;
F_2 ( ! V_75 ) ;
F_4 ( V_133 , sizeof( * V_133 ) ) ;
if ( ! V_133 ) {
F_62 ( 0x12f , L_8 ,
& V_69 ) ;
return - V_37 ;
}
F_63 ( V_2 ) ;
V_133 -> V_135 = V_2 ;
V_133 -> V_136 = V_131 ;
F_17 ( & V_61 . V_137 ) ;
F_39 ( & V_133 -> V_138 , & V_61 . V_139 ) ;
F_64 ( & V_61 . V_140 ) ;
F_18 ( & V_61 . V_137 ) ;
return 0 ;
}
static int
F_65 ( struct V_28 * V_33 , T_2 V_14 )
{
struct V_13 * V_16 ;
F_66 (route, &peer->ksnp_routes, ksnr_list) {
if ( V_16 -> V_20 == V_14 )
return V_16 -> V_23 ;
}
return 0 ;
}
int
F_67 ( T_1 * V_2 , struct V_13 * V_16 ,
struct V_130 * V_131 , int type )
{
T_4 * V_120 = & V_61 . V_62 ;
F_49 ( V_95 ) ;
T_3 V_141 ;
struct V_57 * V_59 ;
T_5 V_142 ;
struct V_81 * V_82 ;
struct V_81 * V_143 ;
struct V_28 * V_33 = NULL ;
struct V_28 * V_91 ;
struct V_100 * V_104 ;
T_6 * V_144 ;
int V_31 ;
struct V_145 * V_146 ;
struct V_145 * V_147 ;
int V_75 ;
int V_148 ;
char * V_149 = NULL ;
V_148 = ! ! V_16 ;
F_2 ( V_148 == ( type != V_150 ) ) ;
F_4 ( V_82 , sizeof( * V_82 ) ) ;
if ( ! V_82 ) {
V_75 = - V_37 ;
goto V_151;
}
V_82 -> V_152 = NULL ;
V_82 -> V_84 = NULL ;
V_82 -> V_153 = V_131 ;
F_5 ( & V_82 -> V_154 , 2 ) ;
V_82 -> V_83 = type ;
F_68 ( V_131 , V_82 ) ;
F_5 ( & V_82 -> V_155 , 1 ) ;
V_82 -> V_156 = 0 ;
V_82 -> V_157 = 0 ;
F_15 ( & V_82 -> V_158 ) ;
V_82 -> V_159 = 0 ;
V_82 -> V_160 = 0 ;
V_82 -> V_161 = NULL ;
F_5 ( & V_82 -> V_162 , 0 ) ;
F_4 ( V_144 , F_69 ( T_6 ,
V_163 [ V_10 ] ) ) ;
if ( ! V_144 ) {
V_75 = - V_37 ;
goto V_164;
}
V_75 = F_70 ( V_82 ) ;
if ( V_75 )
goto V_164;
if ( V_148 ) {
V_33 = V_16 -> V_18 ;
F_2 ( V_2 == V_33 -> V_38 ) ;
V_144 -> V_165 = F_55 ( V_2 , V_144 -> V_163 ) ;
V_141 = V_33 -> V_39 ;
F_45 ( V_120 ) ;
V_82 -> V_166 = V_33 -> V_43 ;
F_46 ( V_120 ) ;
if ( ! V_82 -> V_166 ) {
V_82 -> V_166 = & V_167 ;
#if V_168
if ( * V_169 . V_170 == 2 )
V_82 -> V_166 = & V_171 ;
else if ( * V_169 . V_170 == 1 )
V_82 -> V_166 = & V_172 ;
#endif
}
V_75 = F_71 ( V_2 , V_82 , V_141 . V_32 , V_144 ) ;
if ( V_75 )
goto V_164;
} else {
V_141 . V_32 = V_34 ;
V_141 . V_35 = V_36 ;
V_82 -> V_166 = NULL ;
}
V_75 = F_72 ( V_2 , V_82 , V_144 , & V_141 , & V_142 ) ;
if ( V_75 < 0 )
goto V_164;
F_2 ( ! V_75 || V_148 ) ;
F_2 ( V_82 -> V_166 ) ;
F_2 ( V_141 . V_32 != V_34 ) ;
V_31 = F_11 ( V_141 . V_32 ) ;
if ( V_148 ) {
F_30 ( V_33 ) ;
F_45 ( V_120 ) ;
} else {
V_75 = F_10 ( & V_33 , V_2 , V_141 ) ;
if ( V_75 )
goto V_164;
F_45 ( V_120 ) ;
F_2 ( ! ( (struct V_4 * ) V_2 -> V_6 ) -> V_53 ) ;
V_91 = F_24 ( V_2 , V_141 ) ;
if ( ! V_91 ) {
F_39 ( & V_33 -> V_60 ,
F_25 ( V_141 . V_32 ) ) ;
} else {
F_8 ( V_33 ) ;
V_33 = V_91 ;
}
F_30 ( V_33 ) ;
V_33 -> V_42 ++ ;
if ( V_141 . V_32 < V_2 -> V_173 &&
F_65 ( V_33 , V_82 -> V_88 ) ) {
V_75 = V_174 ;
V_149 = L_9 ;
goto V_175;
}
}
if ( V_33 -> V_41 ||
( V_148 && V_16 -> V_25 ) ) {
V_75 = - V_176 ;
V_149 = L_10 ;
goto V_175;
}
if ( ! V_33 -> V_43 ) {
F_2 ( F_23 ( & V_33 -> V_47 ) ) ;
V_33 -> V_43 = V_82 -> V_166 ;
V_33 -> V_177 = V_142 ;
}
if ( V_33 -> V_43 != V_82 -> V_166 ||
V_33 -> V_177 != V_142 ) {
F_73 ( V_33 , 0 , 0 ) ;
V_33 -> V_43 = NULL ;
V_75 = V_176 ;
V_149 = V_33 -> V_177 != V_142 ?
L_11 :
L_12 ;
goto V_175;
}
switch ( V_75 ) {
default:
F_38 () ;
case 0 :
break;
case V_174 :
V_149 = L_13 ;
goto V_175;
case V_178 :
V_149 = L_14 ;
goto V_175;
}
if ( V_82 -> V_88 != V_82 -> V_85 ) {
F_26 (tmp, &peer->ksnp_conns) {
V_143 = F_27 ( V_59 , struct V_81 , V_87 ) ;
if ( V_143 -> V_88 != V_82 -> V_88 ||
V_143 -> V_85 != V_82 -> V_85 ||
V_143 -> V_83 != V_82 -> V_83 )
continue;
F_2 ( ! V_75 ) ;
if ( ! V_148 )
V_75 = V_174 ;
V_149 = L_15 ;
goto V_175;
}
}
if ( V_148 &&
V_16 -> V_20 != V_82 -> V_88 ) {
F_19 ( L_16 ,
F_22 ( V_33 -> V_39 ) ,
& V_16 -> V_20 ,
& V_82 -> V_88 ) ;
}
F_26 (tmp, &peer->ksnp_routes) {
V_16 = F_27 ( V_59 , struct V_13 , V_79 ) ;
if ( V_16 -> V_20 != V_82 -> V_88 )
continue;
F_35 ( V_16 , V_82 ) ;
break;
}
V_82 -> V_152 = V_33 ;
V_33 -> V_44 = F_74 () ;
V_33 -> V_179 = 0 ;
V_33 -> V_180 = 0 ;
V_104 = F_54 ( V_31 ) ;
V_104 -> V_107 ++ ;
V_82 -> V_181 = V_104 ;
V_82 -> V_182 = F_74 () ;
V_82 -> V_183 = V_131 -> V_184 -> V_185 ;
V_82 -> V_186 = F_75 ( * V_169 . V_187 ) ;
F_76 () ;
F_77 ( & V_82 -> V_87 , & V_33 -> V_47 ) ;
F_53 ( V_82 ) ;
F_78 ( V_82 , 0 ) ;
V_82 -> V_188 = F_79 ( V_82 ) ;
F_80 (tx, txtmp, &peer->ksnp_tx_queue, tx_list) {
int V_189 = V_82 -> V_166 -> V_190 ( V_82 , V_146 ,
V_146 -> V_191 ) ;
if ( V_189 == V_192 )
continue;
F_33 ( & V_146 -> V_193 ) ;
F_81 ( V_146 , V_82 ) ;
}
F_46 ( V_120 ) ;
F_21 ( V_56 , L_17 ,
F_22 ( V_141 ) , V_82 -> V_166 -> V_194 ,
& V_82 -> V_85 , & V_82 -> V_88 ,
V_82 -> V_195 , V_142 , V_31 ,
( int ) ( V_104 - & V_104 -> V_196 -> V_106 [ 0 ] ) ) ;
if ( V_148 ) {
F_59 ( V_33 , V_82 -> V_195 ,
V_144 -> V_163 , V_144 -> V_165 ) ;
} else {
V_144 -> V_165 = F_57 ( V_33 , V_144 -> V_163 ,
V_144 -> V_165 ) ;
V_75 = F_71 ( V_2 , V_82 , V_141 . V_32 , V_144 ) ;
}
F_9 ( V_144 , F_69 ( T_6 ,
V_163 [ V_10 ] ) ) ;
if ( ! V_75 )
V_75 = F_82 ( V_131 ) ;
F_45 ( V_120 ) ;
F_83 ( V_131 , V_82 ) ;
if ( ! V_148 )
V_33 -> V_42 -- ;
F_46 ( V_120 ) ;
if ( V_75 ) {
F_45 ( V_120 ) ;
if ( ! V_82 -> V_197 ) {
F_42 ( V_82 , V_75 ) ;
}
F_46 ( V_120 ) ;
} else if ( ! F_84 ( V_82 ) ) {
F_85 ( V_82 ) ;
F_86 ( V_82 ) ;
F_87 ( V_82 ) ;
}
F_87 ( V_82 ) ;
F_88 ( V_82 ) ;
return V_75 ;
V_175:
if ( ! V_33 -> V_41 &&
F_23 ( & V_33 -> V_47 ) &&
F_23 ( & V_33 -> V_48 ) ) {
F_77 ( & V_95 , & V_33 -> V_49 ) ;
F_89 ( & V_33 -> V_49 ) ;
F_32 ( V_33 ) ;
}
F_46 ( V_120 ) ;
if ( V_149 ) {
if ( V_75 < 0 )
F_19 ( L_18 ,
F_22 ( V_141 ) , V_82 -> V_83 , V_149 ) ;
else
F_21 ( V_56 , L_18 ,
F_22 ( V_141 ) , V_82 -> V_83 , V_149 ) ;
}
if ( ! V_148 ) {
if ( V_75 > 0 ) {
V_82 -> V_83 = V_150 ;
V_144 -> V_165 = 0 ;
F_71 ( V_2 , V_82 , V_141 . V_32 , V_144 ) ;
}
F_45 ( V_120 ) ;
V_33 -> V_42 -- ;
F_46 ( V_120 ) ;
}
F_51 ( V_2 , & V_95 , 1 ) ;
F_8 ( V_33 ) ;
V_164:
if ( V_144 )
F_9 ( V_144 , F_69 ( T_6 ,
V_163 [ V_10 ] ) ) ;
F_9 ( V_82 , sizeof( * V_82 ) ) ;
V_151:
F_90 ( V_131 ) ;
return V_75 ;
}
void
F_42 ( struct V_81 * V_82 , int error )
{
struct V_28 * V_33 = V_82 -> V_152 ;
struct V_13 * V_16 ;
struct V_81 * V_143 ;
struct V_57 * V_59 ;
F_2 ( ! V_33 -> V_180 ) ;
F_2 ( ! V_82 -> V_197 ) ;
V_82 -> V_197 = 1 ;
F_33 ( & V_82 -> V_87 ) ;
V_16 = V_82 -> V_84 ;
if ( V_16 ) {
F_2 ( ! V_16 -> V_25 ) ;
F_2 ( V_16 -> V_24 & ( 1 << V_82 -> V_83 ) ) ;
V_143 = NULL ;
F_26 (tmp, &peer->ksnp_conns) {
V_143 = F_27 ( V_59 , struct V_81 , V_87 ) ;
if ( V_143 -> V_84 == V_16 &&
V_143 -> V_83 == V_82 -> V_83 )
break;
V_143 = NULL ;
}
if ( ! V_143 )
V_16 -> V_24 &= ~ ( 1 << V_82 -> V_83 ) ;
V_82 -> V_84 = NULL ;
F_43 ( V_16 ) ;
}
if ( F_23 ( & V_33 -> V_47 ) ) {
if ( ! F_23 ( & V_33 -> V_49 ) ) {
struct V_145 * V_146 ;
F_2 ( V_82 -> V_166 == & V_167 ) ;
F_66 (tx, &peer->ksnp_tx_queue,
tx_list)
F_91 ( V_82 , V_146 ) ;
F_17 ( & V_82 -> V_181 -> V_198 ) ;
F_50 ( & V_33 -> V_49 ,
& V_82 -> V_158 ) ;
F_18 ( & V_82 -> V_181 -> V_198 ) ;
}
V_33 -> V_43 = NULL ;
V_33 -> V_180 = error ;
if ( F_23 ( & V_33 -> V_48 ) ) {
F_32 ( V_33 ) ;
}
}
F_17 ( & V_61 . V_199 ) ;
F_39 ( & V_82 -> V_87 ,
& V_61 . V_200 ) ;
F_64 ( & V_61 . V_201 ) ;
F_18 ( & V_61 . V_199 ) ;
}
void
F_92 ( struct V_28 * V_33 )
{
int V_202 = 0 ;
unsigned long V_203 = 0 ;
F_29 ( & V_61 . V_62 ) ;
if ( ! ( V_33 -> V_39 . V_35 & V_204 ) &&
F_23 ( & V_33 -> V_47 ) &&
! V_33 -> V_42 &&
! F_93 ( V_33 ) ) {
V_202 = 1 ;
V_203 = V_33 -> V_44 ;
}
F_31 ( & V_61 . V_62 ) ;
if ( V_202 )
F_94 ( V_33 -> V_38 , V_33 -> V_39 . V_32 , 0 ,
V_203 ) ;
}
void
F_95 ( struct V_81 * V_82 )
{
struct V_28 * V_33 = V_82 -> V_152 ;
struct V_145 * V_146 ;
struct V_145 * V_205 ;
struct V_145 * V_59 ;
F_49 ( V_206 ) ;
F_2 ( ! V_82 -> V_153 ) ;
F_96 ( & V_33 -> V_51 ) ;
F_80 (tx, tmp, &peer->ksnp_zc_req_list, tx_zc_list) {
if ( V_146 -> V_207 != V_82 )
continue;
F_2 ( V_146 -> V_208 . V_209 [ 0 ] ) ;
V_146 -> V_208 . V_209 [ 0 ] = 0 ;
V_146 -> V_210 = 1 ;
F_33 ( & V_146 -> V_211 ) ;
F_77 ( & V_146 -> V_211 , & V_206 ) ;
}
F_97 ( & V_33 -> V_51 ) ;
F_80 (tx, temp, &zlist, tx_zc_list) {
F_33 ( & V_146 -> V_211 ) ;
F_98 ( V_146 ) ;
}
}
void
F_99 ( struct V_81 * V_82 )
{
struct V_28 * V_33 = V_82 -> V_152 ;
struct V_100 * V_104 = V_82 -> V_181 ;
int V_212 = 0 ;
F_2 ( V_82 -> V_197 ) ;
F_17 ( & V_104 -> V_198 ) ;
V_82 -> V_159 = 1 ;
if ( ! V_82 -> V_160 &&
! F_23 ( & V_82 -> V_158 ) ) {
F_39 ( & V_82 -> V_213 ,
& V_104 -> V_214 ) ;
V_82 -> V_160 = 1 ;
F_53 ( V_82 ) ;
F_64 ( & V_104 -> V_215 ) ;
}
F_18 ( & V_104 -> V_198 ) ;
F_45 ( & V_61 . V_62 ) ;
F_100 ( V_82 -> V_153 , V_82 ) ;
V_82 -> V_181 -> V_107 -- ;
if ( V_33 -> V_180 ) {
F_2 ( F_23 ( & V_33 -> V_47 ) ) ;
V_212 = 1 ;
V_33 -> V_180 = 0 ;
}
F_46 ( & V_61 . V_62 ) ;
if ( V_212 )
F_92 ( V_33 ) ;
F_87 ( V_82 ) ;
}
void
F_101 ( struct V_81 * V_82 )
{
F_2 ( ! F_7 ( & V_82 -> V_155 ) ) ;
F_17 ( & V_61 . V_199 ) ;
F_39 ( & V_82 -> V_87 , & V_61 . V_216 ) ;
F_64 ( & V_61 . V_201 ) ;
F_18 ( & V_61 . V_199 ) ;
}
void
F_102 ( struct V_81 * V_82 )
{
unsigned long V_217 ;
F_21 ( V_56 , L_19 , V_82 ) ;
F_2 ( ! F_7 ( & V_82 -> V_155 ) ) ;
F_2 ( ! F_7 ( & V_82 -> V_154 ) ) ;
F_2 ( ! V_82 -> V_153 ) ;
F_2 ( ! V_82 -> V_84 ) ;
F_2 ( ! V_82 -> V_160 ) ;
F_2 ( ! V_82 -> V_157 ) ;
F_2 ( F_23 ( & V_82 -> V_158 ) ) ;
switch ( V_82 -> V_218 ) {
case V_219 :
V_217 = V_82 -> V_220 -
F_103 ( * V_169 . V_187 ) ;
F_19 ( L_20 ,
F_22 ( V_82 -> V_152 -> V_39 ) , V_82 -> V_83 ,
& V_82 -> V_88 , V_82 -> V_195 ,
V_82 -> V_221 , V_82 -> V_222 ,
F_104 ( F_105 ( F_74 () ,
V_217 ) ) ) ;
F_106 ( V_82 -> V_152 -> V_38 ,
V_82 -> V_223 , - V_224 ) ;
break;
case V_225 :
if ( V_82 -> V_226 )
F_19 ( L_21 ,
F_22 ( V_82 -> V_152 -> V_39 ) ,
& V_82 -> V_88 , V_82 -> V_195 ,
V_82 -> V_166 -> V_194 ) ;
break;
case V_227 :
if ( V_82 -> V_226 )
F_19 ( L_22 ,
F_22 ( V_82 -> V_152 -> V_39 ) ,
& V_82 -> V_88 , V_82 -> V_195 ,
V_82 -> V_166 -> V_194 ) ;
break;
case V_228 :
if ( V_82 -> V_226 )
F_19 ( L_23 ,
F_22 ( V_82 -> V_152 -> V_39 ) ,
& V_82 -> V_88 , V_82 -> V_195 ) ;
break;
default:
F_38 () ;
break;
}
F_8 ( V_82 -> V_152 ) ;
F_9 ( V_82 , sizeof( * V_82 ) ) ;
}
int
F_73 ( struct V_28 * V_33 , T_2 V_14 , int V_229 )
{
struct V_81 * V_82 ;
struct V_57 * V_89 ;
struct V_57 * V_90 ;
int V_230 = 0 ;
F_41 (ctmp, cnxt, &peer->ksnp_conns) {
V_82 = F_27 ( V_89 , struct V_81 , V_87 ) ;
if ( ! V_14 || V_82 -> V_88 == V_14 ) {
V_230 ++ ;
F_42 ( V_82 , V_229 ) ;
}
}
return V_230 ;
}
int
F_107 ( struct V_81 * V_82 , int V_229 )
{
struct V_28 * V_33 = V_82 -> V_152 ;
T_2 V_14 = V_82 -> V_88 ;
int V_230 ;
F_45 ( & V_61 . V_62 ) ;
V_230 = F_73 ( V_33 , V_14 , V_229 ) ;
F_46 ( & V_61 . V_62 ) ;
return V_230 ;
}
int
F_108 ( T_3 V_30 , T_2 V_14 )
{
struct V_28 * V_33 ;
struct V_57 * V_72 ;
struct V_57 * V_96 ;
int V_97 ;
int V_98 ;
int V_7 ;
int V_230 = 0 ;
F_45 ( & V_61 . V_62 ) ;
if ( V_30 . V_32 != V_34 ) {
V_97 = ( int ) ( F_25 ( V_30 . V_32 ) - V_61 . V_99 ) ;
V_98 = ( int ) ( F_25 ( V_30 . V_32 ) - V_61 . V_99 ) ;
} else {
V_97 = 0 ;
V_98 = V_61 . V_77 - 1 ;
}
for ( V_7 = V_97 ; V_7 <= V_98 ; V_7 ++ ) {
F_41 (ptmp, pnxt,
&ksocknal_data.ksnd_peers[i]) {
V_33 = F_27 ( V_72 , struct V_28 , V_60 ) ;
if ( ! ( ( V_30 . V_32 == V_34 || V_30 . V_32 == V_33 -> V_39 . V_32 ) &&
( V_30 . V_35 == V_36 || V_30 . V_35 == V_33 -> V_39 . V_35 ) ) )
continue;
V_230 += F_73 ( V_33 , V_14 ,
0 ) ;
}
}
F_46 ( & V_61 . V_62 ) ;
if ( V_30 . V_32 == V_34 || V_30 . V_35 == V_36 || ! V_14 )
return 0 ;
if ( ! V_230 )
return - V_76 ;
else
return 0 ;
}
void
F_109 ( T_1 * V_2 , T_7 V_231 , int V_232 )
{
T_3 V_30 = { 0 } ;
V_30 . V_32 = V_231 ;
V_30 . V_35 = V_36 ;
F_21 ( V_56 , L_24 , F_110 ( V_231 ) ,
V_232 ? L_25 : L_26 ) ;
if ( ! V_232 ) {
F_108 ( V_30 , 0 ) ;
return;
}
}
void
F_111 ( T_1 * V_2 , T_7 V_32 , unsigned long * V_233 )
{
int V_234 = 1 ;
unsigned long V_203 = 0 ;
unsigned long V_235 = F_74 () ;
struct V_28 * V_33 = NULL ;
T_4 * V_236 = & V_61 . V_62 ;
T_3 V_30 = {
. V_32 = V_32 ,
. V_35 = V_237 ,
} ;
F_29 ( V_236 ) ;
V_33 = F_24 ( V_2 , V_30 ) ;
if ( V_33 ) {
struct V_57 * V_59 ;
struct V_81 * V_82 ;
int V_238 ;
F_26 (tmp, &peer->ksnp_conns) {
V_82 = F_27 ( V_59 , struct V_81 , V_87 ) ;
V_238 = V_82 -> V_153 -> V_184 -> V_185 ;
if ( V_238 < V_82 -> V_183 ) {
V_82 -> V_186 =
F_75 ( * V_169 . V_187 ) ;
V_33 -> V_44 = V_235 ;
V_82 -> V_183 = V_238 ;
}
}
V_203 = V_33 -> V_44 ;
if ( ! F_112 ( V_33 ) )
V_234 = 0 ;
}
F_31 ( V_236 ) ;
if ( V_203 )
* V_233 = V_203 ;
F_21 ( V_56 , L_27 ,
F_110 ( V_32 ) , V_33 ,
V_203 ? F_104 ( V_235 - V_203 ) : - 1 ,
V_234 ) ;
if ( ! V_234 )
return;
F_44 ( V_2 , V_30 , F_113 ( V_32 ) , F_114 () ) ;
F_45 ( V_236 ) ;
V_33 = F_24 ( V_2 , V_30 ) ;
if ( V_33 )
F_115 ( V_33 ) ;
F_46 ( V_236 ) ;
}
static void
F_116 ( struct V_28 * V_33 )
{
int V_67 ;
int V_7 ;
struct V_57 * V_59 ;
struct V_81 * V_82 ;
for ( V_67 = 0 ; ; V_67 ++ ) {
F_29 ( & V_61 . V_62 ) ;
V_7 = 0 ;
V_82 = NULL ;
F_26 (tmp, &peer->ksnp_conns) {
if ( V_7 ++ == V_67 ) {
V_82 = F_27 ( V_59 , struct V_81 ,
V_87 ) ;
F_53 ( V_82 ) ;
break;
}
}
F_31 ( & V_61 . V_62 ) ;
if ( ! V_82 )
break;
F_117 ( V_82 ) ;
F_88 ( V_82 ) ;
}
}
static int F_118 ( T_1 * V_2 , T_3 V_30 )
{
struct V_57 * V_239 ;
struct V_57 * V_240 ;
struct V_57 * V_59 ;
int V_75 = - V_76 ;
unsigned int V_241 = V_61 . V_77 ;
if ( V_30 . V_32 == V_34 ) {
V_239 = & V_61 . V_99 [ 0 ] ;
V_240 = & V_61 . V_99 [ V_241 - 1 ] ;
} else {
V_239 = F_25 ( V_30 . V_32 ) ;
V_240 = F_25 ( V_30 . V_32 ) ;
}
for ( V_59 = V_239 ; V_59 <= V_240 ; V_59 ++ ) {
int V_242 ;
for ( V_242 = 0 ; ; V_242 ++ ) {
struct V_28 * V_33 ;
int V_7 = 0 ;
F_29 ( & V_61 . V_62 ) ;
F_66 (peer, tmp, ksnp_list) {
if ( ! ( ( V_30 . V_32 == V_34 ||
V_30 . V_32 == V_33 -> V_39 . V_32 ) &&
( V_30 . V_35 == V_36 ||
V_30 . V_35 == V_33 -> V_39 . V_35 ) ) )
continue;
if ( V_7 ++ == V_242 ) {
F_30 ( V_33 ) ;
break;
}
}
F_31 ( & V_61 . V_62 ) ;
if ( ! V_7 )
break;
V_75 = 0 ;
F_116 ( V_33 ) ;
F_8 ( V_33 ) ;
}
}
return V_75 ;
}
static int
F_119 ( T_1 * V_2 , T_2 V_243 , T_2 V_244 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_1 * V_8 ;
int V_75 ;
int V_7 ;
int V_74 ;
struct V_57 * V_72 ;
struct V_28 * V_33 ;
struct V_57 * V_73 ;
struct V_13 * V_16 ;
if ( ! V_243 || ! V_244 )
return - V_92 ;
F_45 ( & V_61 . V_62 ) ;
V_8 = F_1 ( V_2 , V_243 ) ;
if ( V_8 ) {
V_75 = 0 ;
} else if ( V_5 -> V_9 == V_10 ) {
V_75 = - V_245 ;
} else {
V_8 = & V_5 -> V_11 [ V_5 -> V_9 ++ ] ;
V_8 -> V_12 = V_243 ;
V_8 -> V_117 = V_244 ;
V_8 -> V_65 = 0 ;
V_8 -> V_66 = 0 ;
for ( V_7 = 0 ; V_7 < V_61 . V_77 ; V_7 ++ ) {
F_26 (ptmp, &ksocknal_data.ksnd_peers[i]) {
V_33 = F_27 ( V_72 , struct V_28 ,
V_60 ) ;
for ( V_74 = 0 ; V_74 < V_33 -> V_63 ; V_74 ++ )
if ( V_33 -> V_64 [ V_74 ] == V_243 )
V_8 -> V_66 ++ ;
F_26 (rtmp, &peer->ksnp_routes) {
V_16 = F_27 ( V_73 , struct V_13 ,
V_79 ) ;
if ( V_16 -> V_80 == V_243 )
V_8 -> V_65 ++ ;
}
}
}
V_75 = 0 ;
}
F_46 ( & V_61 . V_62 ) ;
return V_75 ;
}
static void
F_120 ( struct V_28 * V_33 , T_2 V_14 )
{
struct V_57 * V_59 ;
struct V_57 * V_93 ;
struct V_13 * V_16 ;
struct V_81 * V_82 ;
int V_7 ;
int V_74 ;
for ( V_7 = 0 ; V_7 < V_33 -> V_63 ; V_7 ++ )
if ( V_33 -> V_64 [ V_7 ] == V_14 ) {
for ( V_74 = V_7 + 1 ; V_74 < V_33 -> V_63 ; V_74 ++ )
V_33 -> V_64 [ V_74 - 1 ] =
V_33 -> V_64 [ V_74 ] ;
V_33 -> V_63 -- ;
break;
}
F_41 (tmp, nxt, &peer->ksnp_routes) {
V_16 = F_27 ( V_59 , struct V_13 , V_79 ) ;
if ( V_16 -> V_80 != V_14 )
continue;
if ( V_16 -> V_27 ) {
V_16 -> V_80 = 0 ;
} else {
F_40 ( V_16 ) ;
}
}
F_41 (tmp, nxt, &peer->ksnp_conns) {
V_82 = F_27 ( V_59 , struct V_81 , V_87 ) ;
if ( V_82 -> V_85 == V_14 )
F_42 ( V_82 , 0 ) ;
}
}
static int
F_121 ( T_1 * V_2 , T_2 V_243 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_75 = - V_76 ;
struct V_57 * V_59 ;
struct V_57 * V_93 ;
struct V_28 * V_33 ;
T_2 V_246 ;
int V_7 ;
int V_74 ;
F_45 ( & V_61 . V_62 ) ;
for ( V_7 = 0 ; V_7 < V_5 -> V_9 ; V_7 ++ ) {
V_246 = V_5 -> V_11 [ V_7 ] . V_12 ;
if ( ! ( ! V_243 || V_243 == V_246 ) )
continue;
V_75 = 0 ;
for ( V_74 = V_7 + 1 ; V_74 < V_5 -> V_9 ; V_74 ++ )
V_5 -> V_11 [ V_74 - 1 ] =
V_5 -> V_11 [ V_74 ] ;
V_5 -> V_9 -- ;
for ( V_74 = 0 ; V_74 < V_61 . V_77 ; V_74 ++ ) {
F_41 (tmp, nxt,
&ksocknal_data.ksnd_peers[j]) {
V_33 = F_27 ( V_59 , struct V_28 , V_60 ) ;
if ( V_33 -> V_38 != V_2 )
continue;
F_120 ( V_33 , V_246 ) ;
}
}
}
F_46 ( & V_61 . V_62 ) ;
return V_75 ;
}
int
F_122 ( T_1 * V_2 , unsigned int V_247 , void * V_248 )
{
T_3 V_30 = { 0 } ;
struct V_249 * V_250 = V_248 ;
int V_75 ;
switch ( V_247 ) {
case V_251 : {
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_1 * V_8 ;
F_29 ( & V_61 . V_62 ) ;
if ( V_250 -> V_252 >= ( T_2 ) V_5 -> V_9 ) {
V_75 = - V_76 ;
} else {
V_75 = 0 ;
V_8 = & V_5 -> V_11 [ V_250 -> V_252 ] ;
V_250 -> V_253 [ 0 ] = V_8 -> V_12 ;
V_250 -> V_253 [ 1 ] = V_8 -> V_117 ;
V_250 -> V_253 [ 2 ] = V_8 -> V_66 ;
V_250 -> V_253 [ 3 ] = V_8 -> V_65 ;
}
F_31 ( & V_61 . V_62 ) ;
return V_75 ;
}
case V_254 :
return F_119 ( V_2 ,
V_250 -> V_253 [ 0 ] ,
V_250 -> V_253 [ 1 ] ) ;
case V_255 :
return F_121 ( V_2 ,
V_250 -> V_253 [ 0 ] ) ;
case V_256 : {
T_2 V_68 = 0 ;
T_2 V_3 = 0 ;
int V_15 = 0 ;
int V_70 = 0 ;
int V_71 = 0 ;
V_75 = F_34 ( V_2 , V_250 -> V_252 ,
& V_30 , & V_68 , & V_3 , & V_15 ,
& V_70 , & V_71 ) ;
if ( V_75 )
return V_75 ;
V_250 -> V_257 = V_30 . V_32 ;
V_250 -> V_252 = V_71 ;
V_250 -> V_253 [ 0 ] = V_3 ;
V_250 -> V_253 [ 1 ] = V_15 ;
V_250 -> V_253 [ 2 ] = V_68 ;
V_250 -> V_253 [ 3 ] = V_70 ;
V_250 -> V_253 [ 4 ] = V_30 . V_35 ;
return 0 ;
}
case V_258 :
V_30 . V_32 = V_250 -> V_257 ;
V_30 . V_35 = V_237 ;
return F_44 ( V_2 , V_30 ,
V_250 -> V_253 [ 0 ] ,
V_250 -> V_253 [ 1 ] ) ;
case V_259 :
V_30 . V_32 = V_250 -> V_257 ;
V_30 . V_35 = V_36 ;
return F_48 ( V_2 , V_30 ,
V_250 -> V_253 [ 0 ] ) ;
case V_260 : {
int V_261 ;
int V_262 ;
int V_263 ;
struct V_81 * V_82 ;
V_82 = F_52 ( V_2 , V_250 -> V_252 ) ;
if ( ! V_82 )
return - V_76 ;
F_123 ( V_82 , & V_261 , & V_262 , & V_263 ) ;
V_250 -> V_252 = V_261 ;
V_250 -> V_257 = V_82 -> V_152 -> V_39 . V_32 ;
V_250 -> V_264 = V_263 ;
V_250 -> V_253 [ 0 ] = V_82 -> V_88 ;
V_250 -> V_253 [ 1 ] = V_82 -> V_195 ;
V_250 -> V_253 [ 2 ] = V_82 -> V_85 ;
V_250 -> V_253 [ 3 ] = V_82 -> V_83 ;
V_250 -> V_253 [ 4 ] = V_82 -> V_181 -> V_196 -> V_265 ;
V_250 -> V_253 [ 5 ] = V_262 ;
V_250 -> V_253 [ 6 ] = V_82 -> V_152 -> V_39 . V_35 ;
F_88 ( V_82 ) ;
return 0 ;
}
case V_266 :
V_30 . V_32 = V_250 -> V_257 ;
V_30 . V_35 = V_36 ;
return F_108 ( V_30 ,
V_250 -> V_253 [ 0 ] ) ;
case V_267 :
if ( V_250 -> V_257 == V_2 -> V_173 )
return 0 ;
F_19 ( L_28 ,
F_110 ( V_250 -> V_257 ) ,
F_110 ( V_2 -> V_173 ) ) ;
return - V_92 ;
case V_268 :
V_30 . V_32 = V_250 -> V_257 ;
V_30 . V_35 = V_36 ;
return F_118 ( V_2 , V_30 ) ;
default:
return - V_92 ;
}
}
static void
F_124 ( void )
{
F_2 ( ! F_7 ( & V_61 . V_269 ) ) ;
if ( V_61 . V_103 ) {
struct V_101 * V_102 ;
int V_7 ;
F_125 (info, i, ksocknal_data.ksnd_sched_info) {
if ( V_102 -> V_106 ) {
F_9 ( V_102 -> V_106 ,
V_102 -> V_270 *
sizeof( V_102 -> V_106 [ 0 ] ) ) ;
}
}
F_126 ( V_61 . V_103 ) ;
}
F_9 ( V_61 . V_99 ,
sizeof( struct V_57 ) *
V_61 . V_77 ) ;
F_96 ( & V_61 . V_271 ) ;
if ( ! F_23 ( & V_61 . V_272 ) ) {
struct V_57 V_206 ;
struct V_145 * V_146 ;
struct V_145 * V_205 ;
F_77 ( & V_206 , & V_61 . V_272 ) ;
F_89 ( & V_61 . V_272 ) ;
F_97 ( & V_61 . V_271 ) ;
F_80 (tx, temp, &zlist, tx_list) {
F_33 ( & V_146 -> V_193 ) ;
F_9 ( V_146 , V_146 -> V_273 ) ;
}
} else {
F_97 ( & V_61 . V_271 ) ;
}
}
static void
F_127 ( void )
{
struct V_101 * V_102 ;
struct V_100 * V_104 ;
int V_7 ;
int V_74 ;
F_2 ( ! V_61 . V_274 ) ;
switch ( V_61 . V_275 ) {
default:
F_2 ( 0 ) ;
case V_276 :
case V_277 :
F_2 ( V_61 . V_99 ) ;
for ( V_7 = 0 ; V_7 < V_61 . V_77 ; V_7 ++ )
F_2 ( F_23 ( & V_61 . V_99 [ V_7 ] ) ) ;
F_2 ( F_23 ( & V_61 . V_278 ) ) ;
F_2 ( F_23 ( & V_61 . V_279 ) ) ;
F_2 ( F_23 ( & V_61 . V_216 ) ) ;
F_2 ( F_23 ( & V_61 . V_139 ) ) ;
F_2 ( F_23 ( & V_61 . V_280 ) ) ;
if ( V_61 . V_103 ) {
F_125 (info, i,
ksocknal_data.ksnd_sched_info) {
if ( ! V_102 -> V_106 )
continue;
for ( V_74 = 0 ; V_74 < V_102 -> V_270 ; V_74 ++ ) {
V_104 = & V_102 -> V_106 [ V_74 ] ;
F_2 ( F_23 (
& V_104 -> V_214 ) ) ;
F_2 ( F_23 (
& V_104 -> V_281 ) ) ;
F_2 ( F_23 (
& V_104 -> V_282 ) ) ;
F_2 ( ! V_104 -> V_107 ) ;
}
}
}
V_61 . V_283 = 1 ;
F_128 ( & V_61 . V_140 ) ;
F_128 ( & V_61 . V_201 ) ;
if ( V_61 . V_103 ) {
F_125 (info, i,
ksocknal_data.ksnd_sched_info) {
if ( ! V_102 -> V_106 )
continue;
for ( V_74 = 0 ; V_74 < V_102 -> V_270 ; V_74 ++ ) {
V_104 = & V_102 -> V_106 [ V_74 ] ;
F_128 ( & V_104 -> V_215 ) ;
}
}
}
V_7 = 4 ;
F_29 ( & V_61 . V_62 ) ;
while ( V_61 . V_284 ) {
V_7 ++ ;
F_21 ( ( ( V_7 & ( - V_7 ) ) == V_7 ) ? V_285 : V_56 ,
L_29 ,
V_61 . V_284 ) ;
F_31 ( & V_61 . V_62 ) ;
F_129 ( V_286 ) ;
F_130 ( F_103 ( 1 ) ) ;
F_29 ( & V_61 . V_62 ) ;
}
F_31 ( & V_61 . V_62 ) ;
F_124 () ;
V_61 . V_275 = V_287 ;
break;
}
F_131 ( V_288 ) ;
}
static T_5
F_132 ( void )
{
return F_133 () ;
}
static int
F_134 ( void )
{
struct V_101 * V_102 ;
int V_75 ;
int V_7 ;
F_2 ( V_61 . V_275 == V_287 ) ;
F_2 ( ! V_61 . V_274 ) ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_77 = V_289 ;
F_4 ( V_61 . V_99 ,
sizeof( struct V_57 ) *
V_61 . V_77 ) ;
if ( ! V_61 . V_99 )
return - V_37 ;
for ( V_7 = 0 ; V_7 < V_61 . V_77 ; V_7 ++ )
F_15 ( & V_61 . V_99 [ V_7 ] ) ;
F_135 ( & V_61 . V_62 ) ;
F_15 ( & V_61 . V_278 ) ;
F_16 ( & V_61 . V_199 ) ;
F_15 ( & V_61 . V_279 ) ;
F_15 ( & V_61 . V_216 ) ;
F_15 ( & V_61 . V_200 ) ;
F_136 ( & V_61 . V_201 ) ;
F_16 ( & V_61 . V_137 ) ;
F_15 ( & V_61 . V_139 ) ;
F_15 ( & V_61 . V_280 ) ;
F_136 ( & V_61 . V_140 ) ;
F_16 ( & V_61 . V_271 ) ;
F_15 ( & V_61 . V_272 ) ;
V_61 . V_275 = V_277 ;
F_137 ( V_288 ) ;
V_61 . V_103 = F_138 ( F_14 () ,
sizeof( * V_102 ) ) ;
if ( ! V_61 . V_103 )
goto V_212;
F_125 (info, i, ksocknal_data.ksnd_sched_info) {
struct V_100 * V_104 ;
int V_290 ;
V_290 = F_139 ( F_14 () , V_7 ) ;
if ( * V_169 . V_291 > 0 ) {
V_290 = F_58 ( V_290 , * V_169 . V_291 ) ;
} else {
V_290 = F_58 ( F_140 ( V_292 , V_290 >> 1 ) , V_290 ) ;
}
V_102 -> V_270 = V_290 ;
V_102 -> V_265 = V_7 ;
F_13 ( V_102 -> V_106 , F_14 () , V_7 ,
V_102 -> V_270 * sizeof( * V_104 ) ) ;
if ( ! V_102 -> V_106 )
goto V_212;
for (; V_290 > 0 ; V_290 -- ) {
V_104 = & V_102 -> V_106 [ V_290 - 1 ] ;
V_104 -> V_196 = V_102 ;
F_16 ( & V_104 -> V_198 ) ;
F_15 ( & V_104 -> V_281 ) ;
F_15 ( & V_104 -> V_214 ) ;
F_15 ( & V_104 -> V_282 ) ;
F_136 ( & V_104 -> V_215 ) ;
}
}
V_61 . V_293 = 0 ;
V_61 . V_294 = 0 ;
V_61 . V_295 = F_141 () ;
if ( * V_169 . V_296 < V_297 + 1 )
* V_169 . V_296 = V_297 + 1 ;
if ( * V_169 . V_298 <
* V_169 . V_296 ) {
V_169 . V_298 =
V_169 . V_296 ;
}
for ( V_7 = 0 ; V_7 < * V_169 . V_296 ; V_7 ++ ) {
char V_299 [ 16 ] ;
F_17 ( & V_61 . V_137 ) ;
V_61 . V_293 ++ ;
F_18 ( & V_61 . V_137 ) ;
snprintf ( V_299 , sizeof( V_299 ) , L_30 , V_7 ) ;
V_75 = F_142 ( V_300 ,
( void * ) ( ( V_301 ) V_7 ) , V_299 ) ;
if ( V_75 ) {
F_17 ( & V_61 . V_137 ) ;
V_61 . V_293 -- ;
F_18 ( & V_61 . V_137 ) ;
F_19 ( L_31 , V_75 ) ;
goto V_212;
}
}
V_75 = F_142 ( V_302 , NULL , L_32 ) ;
if ( V_75 ) {
F_19 ( L_33 , V_75 ) ;
goto V_212;
}
V_61 . V_275 = V_276 ;
return 0 ;
V_212:
F_127 () ;
return - V_303 ;
}
static void
F_143 ( T_1 * V_2 )
{
struct V_28 * V_33 = NULL ;
struct V_57 * V_59 ;
int V_7 ;
F_29 ( & V_61 . V_62 ) ;
for ( V_7 = 0 ; V_7 < V_61 . V_77 ; V_7 ++ ) {
F_26 (tmp, &ksocknal_data.ksnd_peers[i]) {
V_33 = F_27 ( V_59 , struct V_28 , V_60 ) ;
if ( V_33 -> V_38 == V_2 )
break;
V_33 = NULL ;
}
}
if ( V_33 ) {
struct V_13 * V_16 ;
struct V_81 * V_82 ;
F_144 ( L_34 ,
F_22 ( V_33 -> V_39 ) ,
F_7 ( & V_33 -> V_40 ) ,
V_33 -> V_304 , V_33 -> V_41 ,
V_33 -> V_42 , V_33 -> V_180 ,
V_33 -> V_45 ,
! F_23 ( & V_33 -> V_49 ) ,
! F_23 ( & V_33 -> V_50 ) ) ;
F_26 (tmp, &peer->ksnp_routes) {
V_16 = F_27 ( V_59 , struct V_13 , V_79 ) ;
F_144 ( L_35 ,
F_7 ( & V_16 -> V_17 ) ,
V_16 -> V_22 , V_16 -> V_23 ,
V_16 -> V_24 , V_16 -> V_25 ) ;
}
F_26 (tmp, &peer->ksnp_conns) {
V_82 = F_27 ( V_59 , struct V_81 , V_87 ) ;
F_144 ( L_36 ,
F_7 ( & V_82 -> V_155 ) ,
F_7 ( & V_82 -> V_154 ) ,
V_82 -> V_83 , V_82 -> V_197 ) ;
}
}
F_31 ( & V_61 . V_62 ) ;
}
void
F_145 ( T_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
T_3 V_305 = { 0 } ;
V_305 . V_32 = V_34 ;
V_305 . V_35 = V_36 ;
F_2 ( V_61 . V_275 == V_276 ) ;
F_2 ( V_61 . V_274 > 0 ) ;
F_17 ( & V_5 -> V_52 ) ;
V_5 -> V_53 = 1 ;
F_18 ( & V_5 -> V_52 ) ;
F_48 ( V_2 , V_305 , 0 ) ;
V_7 = 2 ;
F_17 ( & V_5 -> V_52 ) ;
while ( V_5 -> V_55 ) {
F_18 ( & V_5 -> V_52 ) ;
V_7 ++ ;
F_21 ( ( ( V_7 & ( - V_7 ) ) == V_7 ) ? V_285 : V_56 ,
L_37 ,
V_5 -> V_55 ) ;
F_129 ( V_286 ) ;
F_130 ( F_103 ( 1 ) ) ;
F_143 ( V_2 ) ;
F_17 ( & V_5 -> V_52 ) ;
}
F_18 ( & V_5 -> V_52 ) ;
for ( V_7 = 0 ; V_7 < V_5 -> V_9 ; V_7 ++ ) {
F_2 ( ! V_5 -> V_11 [ V_7 ] . V_66 ) ;
F_2 ( ! V_5 -> V_11 [ V_7 ] . V_65 ) ;
}
F_33 ( & V_5 -> V_306 ) ;
F_9 ( V_5 , sizeof( * V_5 ) ) ;
V_61 . V_274 -- ;
if ( ! V_61 . V_274 )
F_127 () ;
}
static int
F_146 ( struct V_4 * V_5 )
{
char * * V_307 ;
int V_7 ;
int V_74 ;
int V_75 ;
int V_308 ;
V_308 = F_147 ( & V_307 ) ;
if ( V_308 <= 0 ) {
F_19 ( L_38 , V_308 ) ;
return V_308 ;
}
for ( V_7 = V_74 = 0 ; V_7 < V_308 ; V_7 ++ ) {
int V_309 ;
T_2 V_3 ;
T_2 V_310 ;
if ( ! strcmp ( V_307 [ V_7 ] , L_39 ) )
continue;
V_75 = F_148 ( V_307 [ V_7 ] , & V_309 , & V_3 , & V_310 ) ;
if ( V_75 ) {
F_144 ( L_40 ,
V_307 [ V_7 ] , V_75 ) ;
continue;
}
if ( ! V_309 ) {
F_144 ( L_41 ,
V_307 [ V_7 ] ) ;
continue;
}
if ( V_74 == V_10 ) {
F_144 ( L_42 ,
V_307 [ V_7 ] ) ;
continue;
}
V_5 -> V_11 [ V_74 ] . V_12 = V_3 ;
V_5 -> V_11 [ V_74 ] . V_117 = V_310 ;
F_149 ( V_5 -> V_11 [ V_74 ] . V_311 ,
V_307 [ V_7 ] , sizeof( V_5 -> V_11 [ V_74 ] . V_311 ) ) ;
V_74 ++ ;
}
F_150 ( V_307 , V_308 ) ;
if ( ! V_74 )
F_19 ( L_43 ) ;
return V_74 ;
}
static int
F_151 ( struct V_4 * V_5 )
{
int V_312 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_5 -> V_9 ; V_7 ++ ) {
char * V_313 = & V_5 -> V_11 [ V_7 ] . V_311 [ 0 ] ;
char * V_314 = strchr ( V_313 , ':' ) ;
int V_315 = 0 ;
struct V_4 * V_59 ;
int V_74 ;
if ( V_314 )
* V_314 = 0 ;
F_66 (tmp, &ksocknal_data.ksnd_nets, ksnn_list) {
for ( V_74 = 0 ; ! V_315 && V_74 < V_59 -> V_9 ; V_74 ++ ) {
char * V_316 =
& V_59 -> V_11 [ V_74 ] . V_311 [ 0 ] ;
char * V_317 = strchr ( V_316 , ':' ) ;
if ( V_317 )
* V_317 = 0 ;
V_315 = ! strcmp ( V_313 , V_316 ) ;
if ( V_317 )
* V_317 = ':' ;
}
if ( V_315 )
break;
}
V_312 += ! V_315 ;
if ( V_314 )
* V_314 = ':' ;
}
return V_312 ;
}
static int
F_152 ( struct V_101 * V_102 )
{
int V_290 ;
int V_75 = 0 ;
int V_7 ;
if ( ! V_102 -> V_105 ) {
if ( * V_169 . V_291 > 0 ) {
V_290 = V_102 -> V_270 ;
} else {
V_290 = F_139 ( F_14 () ,
V_102 -> V_265 ) ;
V_290 = F_58 ( F_140 ( V_292 , V_290 >> 1 ) , V_290 ) ;
V_290 = F_58 ( V_318 , V_290 ) ;
}
V_290 = F_58 ( V_290 , V_102 -> V_270 ) ;
} else {
F_2 ( V_102 -> V_105 <= V_102 -> V_270 ) ;
V_290 = F_58 ( 2 , V_102 -> V_270 - V_102 -> V_105 ) ;
}
for ( V_7 = 0 ; V_7 < V_290 ; V_7 ++ ) {
long V_30 ;
char V_299 [ 20 ] ;
struct V_100 * V_104 ;
V_30 = F_153 ( V_102 -> V_265 , V_102 -> V_105 + V_7 ) ;
V_104 = & V_102 -> V_106 [ F_154 ( V_30 ) ] ;
snprintf ( V_299 , sizeof( V_299 ) , L_44 ,
V_102 -> V_265 , ( int ) ( V_104 - & V_102 -> V_106 [ 0 ] ) ) ;
V_75 = F_142 ( V_319 ,
( void * ) V_30 , V_299 ) ;
if ( ! V_75 )
continue;
F_19 ( L_45 ,
V_102 -> V_265 , V_102 -> V_105 + V_7 , V_75 ) ;
break;
}
V_102 -> V_105 += V_7 ;
return V_75 ;
}
static int
F_155 ( struct V_4 * V_5 , T_2 * V_320 , int V_321 )
{
int V_322 = F_151 ( V_5 ) ;
int V_75 ;
int V_7 ;
F_2 ( V_321 > 0 && V_321 <= F_156 ( F_14 () ) ) ;
for ( V_7 = 0 ; V_7 < V_321 ; V_7 ++ ) {
struct V_101 * V_102 ;
int V_31 = ! V_320 ? V_7 : V_320 [ V_7 ] ;
F_2 ( V_31 < F_156 ( F_14 () ) ) ;
V_102 = V_61 . V_103 [ V_31 ] ;
if ( ! V_322 && V_102 -> V_105 > 0 )
continue;
V_75 = F_152 ( V_102 ) ;
if ( V_75 )
return V_75 ;
}
return 0 ;
}
int
F_157 ( T_1 * V_2 )
{
struct V_4 * V_5 ;
int V_75 ;
int V_7 ;
F_2 ( V_2 -> V_323 == & V_324 ) ;
if ( V_61 . V_275 == V_287 ) {
V_75 = F_134 () ;
if ( V_75 )
return V_75 ;
}
F_4 ( V_5 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
goto V_325;
F_16 ( & V_5 -> V_52 ) ;
V_5 -> V_326 = F_132 () ;
V_2 -> V_6 = V_5 ;
V_2 -> V_327 = * V_169 . V_328 ;
V_2 -> V_329 = * V_169 . V_330 ;
V_2 -> V_331 = * V_169 . V_332 ;
V_2 -> V_333 = * V_169 . V_334 ;
if ( ! V_2 -> V_335 [ 0 ] ) {
V_75 = F_146 ( V_5 ) ;
if ( V_75 <= 0 )
goto V_336;
V_5 -> V_9 = 1 ;
} else {
for ( V_7 = 0 ; V_7 < V_10 ; V_7 ++ ) {
int V_309 ;
if ( ! V_2 -> V_335 [ V_7 ] )
break;
V_75 = F_148 ( V_2 -> V_335 [ V_7 ] , & V_309 ,
& V_5 -> V_11 [ V_7 ] . V_12 ,
& V_5 -> V_11 [ V_7 ] . V_117 ) ;
if ( V_75 ) {
F_19 ( L_40 ,
V_2 -> V_335 [ V_7 ] , V_75 ) ;
goto V_336;
}
if ( ! V_309 ) {
F_19 ( L_46 ,
V_2 -> V_335 [ V_7 ] ) ;
goto V_336;
}
F_149 ( V_5 -> V_11 [ V_7 ] . V_311 ,
V_2 -> V_335 [ V_7 ] ,
sizeof( V_5 -> V_11 [ V_7 ] . V_311 ) ) ;
}
V_5 -> V_9 = V_7 ;
}
V_75 = F_155 ( V_5 , V_2 -> V_337 , V_2 -> V_338 ) ;
if ( V_75 )
goto V_336;
V_2 -> V_173 = F_158 ( F_159 ( V_2 -> V_173 ) ,
V_5 -> V_11 [ 0 ] . V_12 ) ;
F_77 ( & V_5 -> V_306 , & V_61 . V_278 ) ;
V_61 . V_274 ++ ;
return 0 ;
V_336:
F_9 ( V_5 , sizeof( * V_5 ) ) ;
V_325:
if ( ! V_61 . V_274 )
F_127 () ;
return - V_303 ;
}
static void T_8 F_160 ( void )
{
F_161 ( & V_324 ) ;
}
static int T_9 F_162 ( void )
{
int V_75 ;
F_163 ( V_339 <= 4 ) ;
F_163 ( V_340 == V_341 ) ;
V_324 . V_342 = V_343 ;
V_324 . V_344 = F_157 ;
V_324 . V_345 = F_145 ;
V_324 . V_346 = F_122 ;
V_324 . V_347 = V_348 ;
V_324 . V_349 = V_350 ;
V_324 . V_351 = F_109 ;
V_324 . V_352 = F_111 ;
V_324 . V_353 = F_60 ;
V_75 = F_164 () ;
if ( V_75 )
return V_75 ;
F_165 ( & V_324 ) ;
return 0 ;
}
