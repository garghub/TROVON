static inline void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 . V_5 & V_6 ) {
F_2 ( V_2 -> V_7 , sizeof( struct V_8 ) ) ;
V_2 -> V_3 . V_4 . V_5 &= ~ V_6 ;
}
}
static void F_3 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 ;
if ( F_4 ( V_12 ) ) {
return;
}
if ( V_10 -> V_13 . V_14 != NULL ) {
F_5 ( V_15 ,
L_1 ,
V_16 , V_10 -> V_17 ,
F_6 ( V_12 ) ) ;
V_10 -> V_13 . V_14 ( V_10 -> V_18 , V_12 ) ;
F_7 ( V_12 ) ;
} else {
do {
V_2 = F_8 ( V_12 ,
struct V_1 , V_19 ) ;
F_9 ( & V_2 -> V_19 ) ;
F_5 ( V_15 ,
L_2 ,
V_16 , V_10 -> V_17 , V_2 ) ;
V_10 -> V_13 . V_20 ( V_10 -> V_18 , V_2 ) ;
} while ( ! F_4 ( V_12 ) );
}
}
static void F_10 ( struct V_21 * V_18 ,
struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_18 -> V_22 [ V_2 -> V_22 ] ;
struct V_11 V_23 ;
F_1 ( V_2 ) ;
F_7 ( & V_23 ) ;
F_11 ( & V_2 -> V_19 , & V_23 ) ;
F_3 ( V_10 , & V_23 ) ;
}
static void F_12 ( struct V_21 * V_18 ,
struct V_9 * V_10 ,
struct V_11 * V_24 )
{
int V_25 ;
int V_26 ;
T_1 V_27 ;
struct V_1 * V_2 ;
unsigned int V_28 ;
while ( true ) {
V_27 = 0 ;
if ( F_4 ( & V_10 -> V_29 ) )
break;
V_2 = F_8 ( & V_10 -> V_29 , struct V_1 , V_19 ) ;
F_5 ( V_15 ,
L_3 ,
V_16 , V_2 , F_6 ( & V_10 -> V_29 ) ) ;
V_28 = V_2 -> V_30 + V_31 ;
if ( V_28 <= V_18 -> V_32 ) {
V_25 = 1 ;
} else {
V_25 = V_28 / V_18 -> V_32 ;
V_26 = V_28 % V_18 -> V_32 ;
if ( V_26 )
V_25 ++ ;
}
F_5 ( V_15 , L_4 ,
V_16 , V_25 , V_10 -> V_33 . V_34 ) ;
if ( V_10 -> V_17 == V_35 ) {
V_25 = 0 ;
} else {
if ( V_10 -> V_33 . V_34 < V_25 )
break;
V_10 -> V_33 . V_34 -= V_25 ;
V_10 -> V_36 . V_37 += V_25 ;
if ( V_10 -> V_33 . V_34 <
V_10 -> V_33 . V_38 ) {
V_27 |= V_39 ;
V_10 -> V_36 . V_40 += 1 ;
F_5 ( V_15 ,
L_5 ,
V_16 ) ;
}
}
V_2 = F_8 ( & V_10 -> V_29 , struct V_1 , V_19 ) ;
F_9 ( & V_2 -> V_19 ) ;
V_2 -> V_3 . V_4 . V_41 = V_25 ;
V_2 -> V_3 . V_4 . V_5 = V_27 ;
V_2 -> V_3 . V_4 . V_42 = V_10 -> V_42 ;
V_10 -> V_42 ++ ;
F_11 ( & V_2 -> V_19 , V_24 ) ;
}
}
static void F_13 ( struct V_21 * V_18 ,
struct V_9 * V_10 ,
struct V_11 * V_24 , int V_43 )
{
struct V_1 * V_2 ;
while ( V_43 ) {
if ( F_4 ( & V_10 -> V_29 ) )
break;
V_2 = F_8 ( & V_10 -> V_29 , struct V_1 , V_19 ) ;
F_9 ( & V_2 -> V_19 ) ;
F_5 ( V_15 ,
L_6 ,
V_16 , V_2 , F_6 ( & V_10 -> V_29 ) ) ;
V_2 -> V_3 . V_4 . V_42 = V_10 -> V_42 ;
V_2 -> V_3 . V_4 . V_5 = 0 ;
V_2 -> V_3 . V_4 . V_41 = 0 ;
V_10 -> V_42 ++ ;
F_11 ( & V_2 -> V_19 , V_24 ) ;
V_43 -- ;
}
}
static int F_14 ( struct V_21 * V_18 ,
struct V_9 * V_10 ,
struct V_11 * V_44 )
{
int V_45 = 0 ;
T_2 V_46 ;
struct V_47 * V_7 ;
struct V_8 * V_48 ;
struct V_1 * V_2 ;
F_5 ( V_15 ,
L_7 , V_16 ,
V_44 , F_6 ( V_44 ) ) ;
while ( ! F_4 ( V_44 ) ) {
V_2 = F_8 ( V_44 , struct V_1 , V_19 ) ;
F_9 ( & V_2 -> V_19 ) ;
V_7 = V_2 -> V_7 ;
if ( ! V_7 ) {
F_15 ( 1 ) ;
V_45 = - V_49 ;
break;
}
V_46 = V_2 -> V_30 ;
V_48 = (struct V_8 * ) F_16 ( V_7 ,
sizeof( * V_48 ) ) ;
if ( ! V_48 ) {
F_15 ( 1 ) ;
V_45 = - V_49 ;
break;
}
V_2 -> V_3 . V_4 . V_5 |= V_6 ;
F_17 ( ( T_2 ) V_46 , & V_48 -> V_50 ) ;
V_48 -> V_5 = V_2 -> V_3 . V_4 . V_5 ;
V_48 -> V_17 = ( T_1 ) V_2 -> V_22 ;
V_48 -> V_51 [ 0 ] = 0 ;
V_48 -> V_51 [ 1 ] = ( T_1 ) V_2 -> V_3 . V_4 . V_42 ;
F_18 ( & V_18 -> V_52 ) ;
F_11 ( & V_2 -> V_19 , & V_10 -> V_53 . V_54 ) ;
V_10 -> V_36 . V_55 += 1 ;
F_19 ( & V_18 -> V_52 ) ;
V_45 = F_20 ( V_18 -> V_56 -> V_57 ,
V_10 -> V_53 . V_58 , NULL , V_7 ) ;
if ( V_45 != 0 ) {
if ( V_45 != - V_59 ) {
F_5 ( V_15 ,
L_8 ,
V_16 , V_45 ) ;
}
F_18 ( & V_18 -> V_52 ) ;
F_9 ( & V_2 -> V_19 ) ;
V_10 -> V_33 . V_34 += V_2 -> V_3 . V_4 . V_41 ;
F_19 ( & V_18 -> V_52 ) ;
F_21 ( & V_2 -> V_19 , V_44 ) ;
break;
}
}
if ( V_45 != 0 ) {
while ( ! F_4 ( V_44 ) ) {
if ( V_45 != - V_59 ) {
F_5 ( V_15 ,
L_9 ,
V_16 , V_2 , V_45 ) ;
}
V_2 = F_8 ( V_44 ,
struct V_1 , V_19 ) ;
F_9 ( & V_2 -> V_19 ) ;
V_2 -> V_45 = V_45 ;
F_10 ( V_18 , V_2 ) ;
}
}
return V_45 ;
}
static enum V_60 F_22 ( struct V_21 * V_18 ,
struct V_9 * V_10 ,
struct V_11 * V_29 )
{
struct V_11 V_61 ;
struct V_1 * V_2 , * V_62 ;
struct V_63 * V_57 = V_18 -> V_56 -> V_57 ;
enum V_64 V_65 ;
int V_66 , V_67 , V_68 , V_69 , V_70 ;
T_1 V_71 ;
F_5 ( V_15 , L_10 ,
V_16 , V_29 ,
( V_29 == NULL ) ? 0 : F_6 ( V_29 ) ) ;
F_7 ( & V_61 ) ;
if ( V_29 != NULL ) {
if ( F_4 ( V_29 ) ) {
return V_72 ;
}
F_18 ( & V_18 -> V_52 ) ;
V_68 = F_6 ( & V_10 -> V_29 ) ;
F_19 ( & V_18 -> V_52 ) ;
if ( V_68 >= V_10 -> V_73 ) {
V_67 = F_6 ( V_29 ) ;
} else {
V_67 = V_68 ;
V_67 += F_6 ( V_29 ) ;
V_67 -= V_10 -> V_73 ;
}
if ( V_67 > 0 ) {
F_5 ( V_15 ,
L_11 ,
V_16 , V_10 -> V_17 , V_67 , V_68 ,
V_10 -> V_73 ) ;
}
if ( ( V_67 <= 0 ) ||
( V_10 -> V_13 . V_74 == NULL ) ) {
F_23 ( V_29 , & V_61 ) ;
} else {
V_70 = F_6 ( V_29 ) - V_67 ;
if ( V_70 < 0 ) {
F_15 ( 1 ) ;
return V_72 ;
}
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
V_2 = F_8 ( V_29 ,
struct V_1 ,
V_19 ) ;
F_24 ( & V_2 -> V_19 , & V_61 ) ;
}
F_25 (packet, tmp_pkt,
txq, list) {
F_5 ( V_15 ,
L_12 ,
V_16 , V_2 ) ;
V_65 = V_10 -> V_13 . V_74 ( V_10 -> V_18 , V_2 ) ;
if ( V_65 == V_75 ) {
V_10 -> V_36 . V_76 += 1 ;
} else {
F_24 ( & V_2 -> V_19 ,
& V_61 ) ;
}
}
if ( F_4 ( & V_61 ) ) {
return V_72 ;
}
}
}
if ( ! V_10 -> V_53 . V_77 ) {
V_66 =
F_26 ( V_57 ,
V_10 -> V_53 . V_58 ) ;
} else {
V_66 = 0 ;
}
F_18 ( & V_18 -> V_52 ) ;
if ( ! F_4 ( & V_61 ) ) {
F_23 ( & V_61 , & V_10 -> V_29 ) ;
if ( ! F_4 ( & V_61 ) ) {
F_15 ( 1 ) ;
F_19 ( & V_18 -> V_52 ) ;
return V_72 ;
}
F_7 ( & V_61 ) ;
}
V_10 -> V_78 ++ ;
if ( V_10 -> V_78 > 1 ) {
V_10 -> V_78 -- ;
F_19 ( & V_18 -> V_52 ) ;
return V_79 ;
}
while ( true ) {
if ( F_6 ( & V_10 -> V_29 ) == 0 )
break;
if ( V_10 -> V_53 . V_77 ) {
F_12 ( V_18 , V_10 , & V_61 ) ;
} else {
F_13 ( V_18 , V_10 , & V_61 , V_66 ) ;
}
if ( F_6 ( & V_61 ) == 0 ) {
break;
}
F_19 ( & V_18 -> V_52 ) ;
F_14 ( V_18 , V_10 , & V_61 ) ;
if ( ! V_10 -> V_53 . V_77 ) {
V_71 = V_10 -> V_53 . V_58 ;
V_66 =
F_26 ( V_57 , V_71 ) ;
}
F_18 ( & V_18 -> V_52 ) ;
}
V_10 -> V_78 = 0 ;
F_19 ( & V_18 -> V_52 ) ;
return V_79 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_47 * V_7 ;
V_7 = V_2 -> V_7 ;
F_28 ( V_7 ) ;
F_29 ( V_2 ) ;
}
static struct V_1 * F_30 ( void )
{
struct V_1 * V_2 = NULL ;
struct V_47 * V_7 ;
V_2 = F_31 ( sizeof( struct V_1 ) , V_80 ) ;
if ( V_2 == NULL )
return NULL ;
V_7 = F_32 ( V_81 , V_80 ) ;
if ( V_7 == NULL ) {
F_29 ( V_2 ) ;
return NULL ;
}
V_2 -> V_7 = V_7 ;
return V_2 ;
}
static void F_33 ( struct V_21 * V_18 ,
struct V_1 * V_2 )
{
F_27 ( V_2 ) ;
}
static struct V_1 * F_34 ( struct V_21 * V_18 )
{
return F_30 () ;
}
static void F_35 ( struct V_21 * V_18 ,
struct V_1 * V_2 )
{
F_33 ( V_18 , V_2 ) ;
}
static int F_36 ( struct V_21 * V_18 )
{
int V_45 , V_34 , V_82 , V_69 ;
struct V_83 * V_84 ;
unsigned int V_85 = 0 ;
V_82 = V_86 / V_18 -> V_32 ;
if ( V_86 % V_18 -> V_32 )
V_82 ++ ;
V_34 = V_18 -> V_87 ;
V_84 = & V_18 -> V_53 . V_88 [ 0 ] ;
V_45 = - V_59 ;
if ( V_85 ) {
F_5 ( V_15 ,
L_13 ,
V_16 , V_34 ) ;
V_84 ++ ;
V_84 ++ ;
V_84 -> V_89 = V_90 ;
V_84 -> V_91 = ( V_34 - 6 ) ;
if ( V_84 -> V_91 == 0 )
V_84 -> V_91 ++ ;
V_34 -= ( int ) V_84 -> V_91 ;
if ( V_34 <= 0 )
return V_45 ;
V_84 ++ ;
V_84 -> V_89 = V_92 ;
V_84 -> V_91 = V_82 ;
V_34 -= ( int ) V_84 -> V_91 ;
if ( V_34 <= 0 )
return V_45 ;
V_84 ++ ;
V_84 ++ ;
V_84 -> V_89 = V_93 ;
V_84 -> V_91 = ( T_1 ) V_34 ;
V_45 = 0 ;
} else {
V_84 ++ ;
V_84 -> V_89 = V_94 ;
V_84 -> V_91 = V_34 / 4 ;
if ( V_84 -> V_91 == 0 )
V_84 -> V_91 ++ ;
V_34 -= ( int ) V_84 -> V_91 ;
if ( V_34 <= 0 )
return V_45 ;
V_84 ++ ;
V_84 -> V_89 = V_90 ;
V_84 -> V_91 = V_34 / 4 ;
if ( V_84 -> V_91 == 0 )
V_84 -> V_91 ++ ;
V_34 -= ( int ) V_84 -> V_91 ;
if ( V_34 <= 0 )
return V_45 ;
V_84 ++ ;
V_84 -> V_89 = V_92 ;
V_84 -> V_91 = V_82 ;
V_34 -= ( int ) V_84 -> V_91 ;
if ( V_34 <= 0 )
return V_45 ;
V_84 ++ ;
V_84 -> V_89 = V_95 ;
V_84 -> V_91 = V_82 ;
V_34 -= ( int ) V_84 -> V_91 ;
if ( V_34 <= 0 )
return V_45 ;
V_84 ++ ;
V_84 -> V_89 = V_93 ;
V_84 -> V_91 = ( T_1 ) V_34 ;
V_45 = 0 ;
}
if ( V_45 == 0 ) {
for ( V_69 = 0 ; V_69 < V_96 ; V_69 ++ ) {
if ( V_18 -> V_53 . V_88 [ V_69 ] . V_89 != 0 ) {
F_5 ( V_15 ,
L_14 ,
V_69 ,
V_18 -> V_53 . V_88 [ V_69 ] .
V_89 ,
V_18 -> V_53 . V_88 [ V_69 ] .
V_91 ) ;
}
}
}
return V_45 ;
}
static void F_37 ( struct V_21 * V_18 ,
struct V_97 * V_98 ,
int V_99 ,
enum V_100 V_101 )
{
int V_102 = 0 , V_69 ;
struct V_9 * V_10 ;
F_18 ( & V_18 -> V_52 ) ;
for ( V_69 = 0 ; V_69 < V_99 ; V_69 ++ , V_98 ++ ) {
if ( V_98 -> V_17 >= V_96 ) {
F_15 ( 1 ) ;
F_19 ( & V_18 -> V_52 ) ;
return;
}
V_10 = & V_18 -> V_22 [ V_98 -> V_17 ] ;
V_10 -> V_33 . V_34 += V_98 -> V_34 ;
if ( V_10 -> V_33 . V_34 && F_6 ( & V_10 -> V_29 ) ) {
F_19 ( & V_18 -> V_52 ) ;
F_22 ( V_18 , V_10 , NULL ) ;
F_18 ( & V_18 -> V_52 ) ;
}
V_102 += V_98 -> V_34 ;
}
F_5 ( V_15 ,
L_15 ,
V_102 ) ;
F_19 ( & V_18 -> V_52 ) ;
}
static void F_38 ( struct V_21 * V_18 ,
struct V_9 * V_10 , T_2 V_103 )
{
struct V_1 * V_2 ;
F_18 ( & V_18 -> V_52 ) ;
while ( F_6 ( & V_10 -> V_29 ) ) {
V_2 = F_8 ( & V_10 -> V_29 , struct V_1 , V_19 ) ;
F_9 ( & V_2 -> V_19 ) ;
V_2 -> V_45 = 0 ;
F_10 ( V_18 , V_2 ) ;
}
F_19 ( & V_18 -> V_52 ) ;
}
static struct V_1 * F_39 ( struct V_21 * V_18 ,
struct V_9 * V_10 ,
struct V_47 * V_7 )
{
struct V_1 * V_2 , * V_62 , * V_104 = NULL ;
F_18 ( & V_18 -> V_52 ) ;
F_25 (packet, tmp_pkt, &ep->pipe.tx_lookup_queue,
list) {
if ( V_7 == V_2 -> V_7 ) {
F_9 ( & V_2 -> V_19 ) ;
V_104 = V_2 ;
break;
}
}
F_19 ( & V_18 -> V_52 ) ;
return V_104 ;
}
static int F_40 ( struct V_63 * V_57 , struct V_47 * V_7 )
{
struct V_21 * V_18 = V_57 -> V_21 ;
struct V_8 * V_48 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
T_1 V_105 , * V_106 ;
T_3 V_107 ;
V_106 = V_7 -> V_108 ;
V_107 = V_7 -> V_109 ;
V_48 = (struct V_8 * ) V_106 ;
V_105 = V_48 -> V_17 ;
V_10 = & V_18 -> V_22 [ V_105 ] ;
V_2 = F_39 ( V_18 , V_10 , V_7 ) ;
if ( V_2 == NULL ) {
F_41 ( L_16 ) ;
} else {
V_2 -> V_45 = 0 ;
F_10 ( V_18 , V_2 ) ;
}
V_7 = NULL ;
if ( ! V_10 -> V_53 . V_77 ) {
F_22 ( V_18 , V_10 , NULL ) ;
}
return 0 ;
}
static int F_42 ( struct V_21 * V_18 ,
struct V_11 * V_44 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 , * V_62 ;
if ( F_4 ( V_44 ) )
return - V_49 ;
V_2 = F_8 ( V_44 , struct V_1 , V_19 ) ;
if ( V_2 -> V_22 >= V_96 ) {
F_15 ( 1 ) ;
return - V_49 ;
}
V_10 = & V_18 -> V_22 [ V_2 -> V_22 ] ;
F_22 ( V_18 , V_10 , V_44 ) ;
if ( ! F_4 ( V_44 ) ) {
F_25 (packet, tmp_pkt, pkt_queue, list) {
V_2 -> V_45 = - V_59 ;
}
F_3 ( V_10 , V_44 ) ;
}
return 0 ;
}
static struct V_1 * F_43 ( struct V_21 * V_18 )
{
struct V_1 * V_2 ;
F_18 ( & V_18 -> V_110 ) ;
if ( V_18 -> V_53 . V_111 == NULL ) {
F_19 ( & V_18 -> V_110 ) ;
return NULL ;
}
V_2 = V_18 -> V_53 . V_111 ;
V_18 -> V_53 . V_111 = (struct V_1 * ) V_2 -> V_19 . V_112 ;
F_19 ( & V_18 -> V_110 ) ;
V_2 -> V_19 . V_112 = NULL ;
return V_2 ;
}
static void F_44 ( struct V_21 * V_18 ,
struct V_1 * V_2 )
{
struct V_11 * V_113 ;
F_18 ( & V_18 -> V_110 ) ;
if ( V_18 -> V_53 . V_111 == NULL ) {
V_18 -> V_53 . V_111 = V_2 ;
V_2 -> V_19 . V_112 = NULL ;
} else {
V_113 = (struct V_11 * ) V_18 -> V_53 . V_111 ;
V_2 -> V_19 . V_112 = V_113 ;
V_18 -> V_53 . V_111 = V_2 ;
}
F_19 ( & V_18 -> V_110 ) ;
}
static int F_45 ( struct V_21 * V_18 , T_1 * V_114 ,
int V_109 , enum V_100 V_101 )
{
struct V_97 * V_115 ;
struct V_116 * V_117 ;
T_1 * V_118 , * V_119 ;
int V_120 , V_45 ;
V_119 = V_114 ;
V_120 = V_109 ;
V_45 = 0 ;
while ( V_109 > 0 ) {
if ( V_109 < sizeof( struct V_116 ) ) {
V_45 = - V_49 ;
break;
}
V_117 = (struct V_116 * ) V_114 ;
V_109 -= sizeof( struct V_116 ) ;
V_114 += sizeof( struct V_116 ) ;
if ( V_117 -> V_109 > V_109 ) {
F_5 ( V_15 ,
L_17 ,
V_117 -> V_109 , V_117 -> V_121 , V_109 ) ;
V_45 = - V_49 ;
break;
}
V_118 = V_114 ;
switch ( V_117 -> V_121 ) {
case V_122 :
if ( V_117 -> V_109 < sizeof( struct V_97 ) ) {
F_15 ( 1 ) ;
return - V_49 ;
}
V_115 = (struct V_97 * ) V_118 ;
F_37 ( V_18 , V_115 ,
V_117 -> V_109 / sizeof( * V_115 ) ,
V_101 ) ;
break;
default:
F_5 ( V_15 ,
L_18 ,
V_117 -> V_121 , V_117 -> V_109 ) ;
break;
}
if ( V_45 != 0 )
break;
V_114 += V_117 -> V_109 ;
V_109 -= V_117 -> V_109 ;
}
return V_45 ;
}
static void F_46 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 ;
if ( F_4 ( V_12 ) ) {
return;
}
while ( ! F_4 ( V_12 ) ) {
V_2 = F_8 ( V_12 ,
struct V_1 , V_19 ) ;
F_9 ( & V_2 -> V_19 ) ;
V_10 -> V_13 . V_123 ( V_10 -> V_18 , V_2 ) ;
}
return;
}
static void F_47 ( struct V_21 * V_18 ,
struct V_9 * V_10 ,
struct V_1 * V_2 )
{
struct V_11 V_23 ;
F_7 ( & V_23 ) ;
F_11 ( & V_2 -> V_19 , & V_23 ) ;
F_46 ( V_10 , & V_23 ) ;
}
static int F_48 ( struct V_63 * V_57 , struct V_47 * V_7 ,
T_1 V_71 )
{
struct V_21 * V_18 = V_57 -> V_21 ;
T_1 * V_106 , * V_124 , V_125 ;
struct V_8 * V_48 ;
T_3 V_107 , V_126 = 0 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_2 V_46 ;
int V_45 = 0 ;
if ( F_15 ( ! V_18 ) ) {
F_41 ( L_19 ) ;
V_45 = - V_49 ;
goto V_127;
}
V_106 = V_7 -> V_108 ;
V_107 = V_7 -> V_109 ;
V_48 = (struct V_8 * ) V_106 ;
if ( V_48 -> V_17 >= V_96 ) {
F_5 ( V_15 ,
L_20 ,
V_48 -> V_17 ) ;
V_45 = - V_49 ;
goto V_127;
}
V_10 = & V_18 -> V_22 [ V_48 -> V_17 ] ;
V_46 = F_49 ( F_50 ( & V_48 -> V_50 ) ) ;
if ( V_107 < ( V_46 + V_31 ) ) {
F_5 ( V_15 ,
L_21 ,
V_107 , V_46 + V_31 ) ;
V_45 = - V_49 ;
goto V_127;
}
V_125 = V_48 -> V_5 ;
if ( V_125 & V_128 ) {
V_125 = V_48 -> V_51 [ 0 ] ;
if ( ( V_125 < sizeof( struct V_116 ) ) ||
( V_125 > V_46 ) ) {
F_5 ( V_15 ,
L_22 ,
V_46 , V_125 ) ;
V_45 = - V_49 ;
goto V_127;
}
V_126 = V_125 ;
V_124 = ( T_1 * ) V_48 + V_31 +
V_46 - V_125 ;
V_45 = F_45 ( V_18 , V_124 , V_125 ,
V_48 -> V_17 ) ;
if ( V_45 != 0 )
goto V_127;
}
if ( ( ( int ) V_46 - ( int ) V_126 ) <= 0 ) {
goto V_127;
}
if ( V_48 -> V_17 == V_35 ) {
if ( V_18 -> V_129 & V_130 ) {
F_5 ( V_15 ,
L_23 ) ;
V_45 = - V_49 ;
goto V_127;
}
F_2 ( V_7 , V_31 ) ;
V_106 = V_7 -> V_108 ;
V_107 = V_7 -> V_109 ;
F_18 ( & V_18 -> V_110 ) ;
V_18 -> V_53 . V_131 = true ;
V_18 -> V_53 . V_132 = F_51 ( int , V_107 ,
V_133 ) ;
memcpy ( V_18 -> V_53 . V_134 , V_106 ,
V_18 -> V_53 . V_132 ) ;
F_19 ( & V_18 -> V_110 ) ;
F_28 ( V_7 ) ;
V_7 = NULL ;
goto V_127;
}
V_2 = F_43 ( V_18 ) ;
if ( V_2 == NULL ) {
V_45 = - V_59 ;
goto V_127;
}
V_2 -> V_45 = 0 ;
V_2 -> V_22 = V_48 -> V_17 ;
V_2 -> V_135 = V_7 ;
V_2 -> V_136 = F_16 ( V_7 , 0 ) + V_31 ;
V_2 -> V_30 = V_107 - V_31 - V_126 ;
F_52 ( V_7 , 0 ) ;
F_47 ( V_18 , V_10 , V_2 ) ;
F_44 ( V_18 , V_2 ) ;
V_7 = NULL ;
V_127:
F_28 ( V_7 ) ;
return V_45 ;
}
static void F_53 ( struct V_21 * V_18 ,
struct V_9 * V_10 )
{
struct V_11 V_23 ;
struct V_1 * V_2 ;
F_18 ( & V_18 -> V_110 ) ;
while ( 1 ) {
if ( F_4 ( & V_10 -> V_137 ) )
break;
V_2 = F_8 ( & V_10 -> V_137 ,
struct V_1 , V_19 ) ;
F_9 ( & V_2 -> V_19 ) ;
F_19 ( & V_18 -> V_110 ) ;
V_2 -> V_45 = - V_138 ;
V_2 -> V_30 = 0 ;
F_5 ( V_15 ,
L_24 ,
V_2 , V_2 -> V_139 ,
V_2 -> V_22 ) ;
F_7 ( & V_23 ) ;
F_11 ( & V_2 -> V_19 , & V_23 ) ;
F_46 ( V_10 , & V_23 ) ;
F_18 ( & V_18 -> V_110 ) ;
}
F_19 ( & V_18 -> V_110 ) ;
}
static int F_54 ( struct V_21 * V_18 )
{
int V_140 = V_141 ;
while ( V_140 > 0 ) {
F_18 ( & V_18 -> V_110 ) ;
if ( V_18 -> V_53 . V_131 ) {
V_18 -> V_53 . V_131 = false ;
F_19 ( & V_18 -> V_110 ) ;
break;
}
F_19 ( & V_18 -> V_110 ) ;
V_140 -- ;
F_55 ( V_142 ) ;
}
if ( V_140 <= 0 ) {
F_56 ( L_25 ) ;
return - V_143 ;
}
return 0 ;
}
static void F_57 ( struct V_21 * V_144 ,
struct V_1 * V_2 )
{
F_5 ( V_15 , L_26 , V_16 ) ;
}
static void F_58 ( struct V_21 * V_18 )
{
struct V_9 * V_10 ;
int V_69 ;
for ( V_69 = V_35 ; V_69 < V_96 ; V_69 ++ ) {
V_10 = & V_18 -> V_22 [ V_69 ] ;
V_10 -> V_145 = 0 ;
V_10 -> V_146 = 0 ;
V_10 -> V_73 = 0 ;
V_10 -> V_17 = V_69 ;
F_7 ( & V_10 -> V_29 ) ;
F_7 ( & V_10 -> V_53 . V_54 ) ;
F_7 ( & V_10 -> V_137 ) ;
V_10 -> V_18 = V_18 ;
V_10 -> V_53 . V_77 = true ;
}
}
static int F_59 ( struct V_21 * V_18 )
{
return 0 ;
}
static T_1 F_60 ( struct V_21 * V_18 , T_2 V_89 )
{
T_1 V_147 = 0 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_96 ; V_69 ++ ) {
if ( V_18 -> V_53 . V_88 [ V_69 ] . V_89 == V_89 )
V_147 =
V_18 -> V_53 . V_88 [ V_69 ] . V_91 ;
}
if ( V_147 == 0 ) {
F_5 ( V_15 ,
L_27 ,
V_89 ) ;
}
return V_147 ;
}
static int F_61 ( struct V_21 * V_18 ,
struct V_148 * V_149 ,
struct V_150 * V_151 )
{
struct V_63 * V_57 = V_18 -> V_56 -> V_57 ;
struct V_1 * V_2 = NULL ;
struct V_152 * V_153 ;
struct V_154 * V_155 ;
enum V_100 V_156 = V_96 ;
bool V_157 = false ;
unsigned int V_158 = 0 ;
struct V_9 * V_10 ;
int V_159 , V_45 = 0 ;
struct V_47 * V_7 ;
T_1 V_160 ;
T_2 V_5 ;
if ( V_149 -> V_145 == 0 ) {
F_15 ( 1 ) ;
V_45 = - V_49 ;
goto V_161;
}
if ( V_149 -> V_145 == V_162 ) {
V_156 = V_35 ;
V_158 = V_133 ;
V_160 = 0 ;
} else {
V_160 = F_60 ( V_18 , V_149 -> V_145 ) ;
if ( V_160 == 0 ) {
V_45 = - V_59 ;
goto V_161;
}
V_2 = F_34 ( V_18 ) ;
if ( V_2 == NULL ) {
F_15 ( 1 ) ;
V_45 = - V_59 ;
goto V_161;
}
V_7 = V_2 -> V_7 ;
V_159 = sizeof( struct V_154 ) ;
V_155 = (struct V_154 * ) F_62 ( V_7 ,
V_159 ) ;
if ( V_155 == NULL ) {
F_15 ( 1 ) ;
V_45 = - V_49 ;
goto V_161;
}
memset ( V_155 , 0 ,
sizeof( struct V_154 ) ) ;
V_155 -> V_163 = F_63 ( V_164 ) ;
V_155 -> V_145 = F_63 ( V_149 -> V_145 ) ;
V_155 -> V_165 = F_63 ( V_149 -> V_165 &
~ V_166 ) ;
V_5 = V_160 << V_167 ;
V_155 -> V_165 |= F_63 ( V_5 ) ;
if ( V_149 -> V_165 &
V_168 ) {
V_157 = true ;
}
F_64 ( V_2 , NULL , ( T_1 * ) V_155 ,
V_159 ,
V_35 , V_169 ) ;
V_45 = F_65 ( V_18 , V_2 ) ;
V_2 = NULL ;
if ( V_45 != 0 )
goto V_161;
V_45 = F_54 ( V_18 ) ;
if ( V_45 != 0 )
goto V_161;
V_153 = (struct V_152 * )
V_18 -> V_53 . V_134 ;
if ( V_153 -> V_163 != F_63 ( V_170 ) ||
( V_18 -> V_53 . V_132 < sizeof( * V_153 ) ) ) {
F_15 ( 1 ) ;
V_45 = - V_49 ;
goto V_161;
}
F_5 ( V_171 ,
L_28 ,
V_16 , V_153 -> V_145 , V_153 -> V_45 ,
V_153 -> V_17 ) ;
V_151 -> V_172 = V_153 -> V_45 ;
if ( V_153 -> V_45 != V_173 ) {
F_5 ( V_15 ,
L_29 ,
V_153 -> V_145 , V_153 -> V_45 ) ;
V_45 = - V_49 ;
goto V_161;
}
V_156 = (enum V_100 ) V_153 -> V_17 ;
V_158 = F_49 ( V_153 -> V_174 ) ;
}
V_45 = - V_49 ;
if ( V_156 >= V_96 ) {
F_15 ( 1 ) ;
goto V_161;
}
if ( V_158 == 0 ) {
F_15 ( 1 ) ;
goto V_161;
}
V_10 = & V_18 -> V_22 [ V_156 ] ;
V_10 -> V_17 = V_156 ;
if ( V_10 -> V_145 != 0 ) {
F_15 ( 1 ) ;
goto V_161;
}
V_151 -> V_22 = V_156 ;
V_151 -> V_146 = V_158 ;
V_10 -> V_145 = V_149 -> V_145 ;
V_10 -> V_73 = V_149 -> V_73 ;
V_10 -> V_146 = V_158 ;
V_10 -> V_33 . V_34 = V_160 ;
V_10 -> V_33 . V_175 = V_18 -> V_32 ;
V_10 -> V_33 . V_38 = V_158 / V_18 -> V_32 ;
if ( V_158 % V_18 -> V_32 )
V_10 -> V_33 . V_38 ++ ;
V_10 -> V_13 = V_149 -> V_13 ;
V_10 -> V_176 = V_177 ;
V_45 = F_66 ( V_57 , V_10 -> V_145 ,
& V_10 -> V_53 . V_58 ,
& V_10 -> V_53 . V_178 ) ;
if ( V_45 != 0 )
goto V_161;
F_5 ( V_15 ,
L_30 ,
V_10 -> V_145 , V_10 -> V_53 . V_58 ,
V_10 -> V_53 . V_178 , V_10 -> V_17 ) ;
if ( V_157 && V_10 -> V_53 . V_77 ) {
V_10 -> V_53 . V_77 = false ;
F_5 ( V_15 ,
L_31 ,
V_10 -> V_145 , V_156 ) ;
}
V_161:
if ( V_2 != NULL )
F_33 ( V_18 , V_2 ) ;
return V_45 ;
}
static void * F_67 ( struct V_63 * V_57 )
{
int V_45 = 0 ;
struct V_9 * V_10 = NULL ;
struct V_21 * V_18 = NULL ;
struct V_1 * V_2 ;
int V_69 ;
V_18 = F_31 ( sizeof( struct V_21 ) , V_80 ) ;
if ( V_18 == NULL ) {
F_41 ( L_32 ) ;
V_45 = - V_59 ;
goto V_179;
}
F_68 ( & V_18 -> V_180 ) ;
F_68 ( & V_18 -> V_110 ) ;
F_68 ( & V_18 -> V_52 ) ;
F_58 ( V_18 ) ;
for ( V_69 = 0 ; V_69 < V_181 ; V_69 ++ ) {
V_2 = F_31 ( sizeof( struct V_1 ) , V_80 ) ;
if ( V_2 != NULL )
F_44 ( V_18 , V_2 ) ;
}
V_18 -> V_56 = F_31 ( sizeof( * V_18 -> V_56 ) , V_80 ) ;
if ( ! V_18 -> V_56 ) {
F_41 ( L_33 ) ;
V_45 = - V_59 ;
goto V_179;
}
V_18 -> V_56 -> V_57 = V_57 ;
V_18 -> V_56 -> V_182 = V_18 ;
V_10 = & V_18 -> V_22 [ V_35 ] ;
F_69 ( V_57 , & V_10 -> V_53 . V_58 ,
& V_10 -> V_53 . V_178 ) ;
return V_18 ;
V_179:
if ( V_45 != 0 ) {
if ( V_18 != NULL )
F_70 ( V_18 ) ;
V_18 = NULL ;
}
return V_18 ;
}
static void F_70 ( struct V_21 * V_18 )
{
struct V_1 * V_2 ;
while ( true ) {
V_2 = F_43 ( V_18 ) ;
if ( V_2 == NULL )
break;
F_29 ( V_2 ) ;
}
F_29 ( V_18 -> V_56 ) ;
F_29 ( V_18 ) ;
}
static int F_71 ( struct V_21 * V_18 )
{
struct V_47 * V_7 ;
struct V_183 * V_184 ;
struct V_1 * V_2 ;
F_59 ( V_18 ) ;
V_2 = F_34 ( V_18 ) ;
if ( V_2 == NULL ) {
F_15 ( 1 ) ;
return - V_59 ;
}
V_7 = V_2 -> V_7 ;
V_184 = (struct V_183 * ) F_62 ( V_7 ,
sizeof( * V_184 ) ) ;
memset ( V_184 , 0 , sizeof( struct V_183 ) ) ;
V_184 -> V_163 = F_63 ( V_185 ) ;
F_5 ( V_15 , L_34 ) ;
F_64 ( V_2 , NULL , ( T_1 * ) V_184 ,
sizeof( struct V_183 ) ,
V_35 , V_169 ) ;
V_18 -> V_129 |= V_130 ;
return F_65 ( V_18 , V_2 ) ;
}
static void F_72 ( struct V_21 * V_18 )
{
int V_69 ;
struct V_9 * V_10 ;
for ( V_69 = 0 ; V_69 < V_96 ; V_69 ++ ) {
V_10 = & V_18 -> V_22 [ V_69 ] ;
F_53 ( V_18 , V_10 ) ;
F_38 ( V_18 , V_10 , V_186 ) ;
}
F_58 ( V_18 ) ;
V_18 -> V_129 &= ~ V_130 ;
}
static int F_73 ( struct V_21 * V_18 ,
enum V_100 V_22 )
{
int V_187 ;
F_18 ( & V_18 -> V_110 ) ;
V_187 = F_6 ( & ( V_18 -> V_22 [ V_22 ] . V_137 ) ) ;
F_19 ( & V_18 -> V_110 ) ;
return V_187 ;
}
static int F_65 ( struct V_21 * V_18 ,
struct V_1 * V_2 )
{
struct V_11 V_24 ;
F_5 ( V_15 ,
L_35 ,
V_16 , V_2 -> V_22 , V_2 -> V_136 ,
V_2 -> V_30 ) ;
F_7 ( & V_24 ) ;
F_11 ( & V_2 -> V_19 , & V_24 ) ;
return F_42 ( V_18 , & V_24 ) ;
}
static int F_74 ( struct V_21 * V_18 )
{
struct V_188 * V_189 ;
struct V_148 V_190 ;
struct V_150 V_191 ;
int V_45 = 0 ;
V_45 = F_54 ( V_18 ) ;
if ( V_45 != 0 )
return V_45 ;
if ( V_18 -> V_53 . V_132 < sizeof( * V_189 ) ) {
F_56 ( L_36 ,
V_18 -> V_53 . V_132 ) ;
return - V_192 ;
}
V_189 = (struct V_188 * ) V_18 -> V_53 . V_134 ;
if ( V_189 -> V_193 . V_163 != F_63 ( V_194 ) ) {
F_56 ( L_37 ,
V_189 -> V_193 . V_163 ) ;
return - V_192 ;
}
F_5 ( V_15 ,
L_38 ,
V_189 -> V_193 . V_195 ,
V_189 -> V_193 . V_175 ) ;
V_18 -> V_87 = F_49 ( V_189 -> V_193 . V_195 ) ;
V_18 -> V_32 = F_49 ( V_189 -> V_193 . V_175 ) ;
if ( ( V_18 -> V_87 == 0 ) || ( V_18 -> V_32 == 0 ) )
return - V_192 ;
F_36 ( V_18 ) ;
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
memset ( & V_191 , 0 , sizeof( V_191 ) ) ;
V_190 . V_13 . V_20 = F_35 ;
V_190 . V_13 . V_123 = F_57 ;
V_190 . V_73 = V_196 ;
V_190 . V_145 = V_162 ;
V_45 = F_61 ( V_18 , & V_190 , & V_191 ) ;
return V_45 ;
}
static void F_75 ( struct V_21 * V_18 ,
enum V_100 V_22 , T_2 V_103 )
{
struct V_9 * V_10 = & V_18 -> V_22 [ V_22 ] ;
if ( V_10 -> V_145 == 0 ) {
F_15 ( 1 ) ;
return;
}
F_38 ( V_18 , V_10 , V_103 ) ;
}
static int F_76 ( struct V_21 * V_18 ,
struct V_11 * V_44 )
{
struct V_1 * V_2 , * V_62 , * V_197 ;
struct V_9 * V_10 ;
int V_45 = 0 ;
if ( F_4 ( V_44 ) )
return - V_49 ;
V_197 = F_8 ( V_44 , struct V_1 , V_19 ) ;
if ( V_197 -> V_22 >= V_96 ) {
F_15 ( 1 ) ;
return - V_49 ;
}
F_5 ( V_15 , L_39 ,
V_16 , V_197 -> V_22 , F_6 ( V_44 ) ,
V_197 -> V_139 ) ;
V_10 = & V_18 -> V_22 [ V_197 -> V_22 ] ;
F_18 ( & V_18 -> V_110 ) ;
F_23 ( V_44 , & V_10 -> V_137 ) ;
F_19 ( & V_18 -> V_110 ) ;
if ( V_45 != 0 ) {
F_25 (packet, tmp_pkt, pkt_queue, list) {
V_2 -> V_45 = - V_138 ;
}
F_46 ( V_10 , V_44 ) ;
}
return V_45 ;
}
static void F_77 ( struct V_21 * V_18 ,
enum V_100 V_10 ,
bool V_198 )
{
}
static void F_78 ( struct V_21 * V_18 )
{
}
static int F_79 ( struct V_21 * V_18 ,
struct V_199 * V_3 )
{
return 0 ;
}
void F_80 ( struct V_63 * V_57 )
{
V_57 -> V_200 = & V_201 ;
}
