static void F_1 ( T_1 * * V_1 , unsigned long V_2 )
{
T_1 * V_3 ;
if ( ! F_2 ( ( unsigned long ) * V_1 , 4 ) ) {
V_3 = F_3 ( * V_1 - 4 , 4 ) ;
memmove ( V_3 , * V_1 , V_2 ) ;
* V_1 = V_3 ;
}
}
static void F_4 ( struct V_4 * V_5 , T_1 V_6 ,
int V_7 , int V_8 )
{
struct V_9 * V_10 ;
V_5 -> V_1 -= V_11 ;
V_10 = (struct V_9 * ) V_5 -> V_1 ;
F_5 ( ( V_12 ) V_5 -> V_13 , & V_10 -> V_14 ) ;
V_10 -> V_6 = V_6 ;
V_10 -> V_15 = V_5 -> V_16 ;
V_10 -> V_17 [ 0 ] = V_7 ;
V_10 -> V_17 [ 1 ] = V_8 ;
}
static void F_6 ( struct V_18 * V_19 ,
struct V_4 * V_20 )
{
F_7 ( & V_19 -> V_21 ) ;
F_8 ( & V_20 -> V_22 , & V_19 -> V_23 ) ;
F_9 ( & V_19 -> V_21 ) ;
}
static struct V_4 * F_10 ( struct V_18 * V_19 ,
bool V_24 )
{
struct V_4 * V_5 = NULL ;
struct V_25 * V_26 ;
V_26 = V_24 ? & V_19 -> V_23 : & V_19 -> V_27 ;
F_7 ( & V_19 -> V_21 ) ;
if ( F_11 ( V_26 ) ) {
F_9 ( & V_19 -> V_21 ) ;
return NULL ;
}
V_5 = F_12 ( V_26 , struct V_4 , V_22 ) ;
F_13 ( & V_5 -> V_22 ) ;
F_9 ( & V_19 -> V_21 ) ;
if ( V_24 )
V_5 -> V_1 = V_5 -> V_28 + V_11 ;
return V_5 ;
}
static void F_14 ( struct V_18 * V_19 ,
struct V_29 * V_16 ,
struct V_4 * V_5 )
{
V_5 -> V_30 = NULL ;
V_5 -> V_1 += V_11 ;
if ( ! V_5 -> V_31 )
return;
F_15 ( L_1 ,
V_5 -> V_31 , V_5 -> V_16 , V_5 -> V_13 ,
V_5 -> V_32 . V_24 . V_33 ) ;
F_7 ( & V_19 -> V_34 ) ;
V_16 -> V_35 . V_36 +=
V_5 -> V_32 . V_24 . V_33 ;
V_16 -> V_35 . V_37 = F_16 ( & V_16 -> V_38 ) ;
F_17 ( V_39 , L_2 ,
V_19 -> V_40 , & V_19 -> V_41 ) ;
F_18 ( V_19 -> V_40 ,
& V_19 -> V_41 ,
V_42 ) ;
F_9 ( & V_19 -> V_34 ) ;
}
static void F_19 ( struct V_29 * V_16 ,
struct V_25 * V_38 )
{
if ( F_11 ( V_38 ) )
return;
F_17 ( V_39 ,
L_3 ,
V_16 -> V_15 , F_16 ( V_38 ) ) ;
F_20 ( V_16 -> V_19 -> V_43 -> V_44 , V_38 ) ;
}
static void F_21 ( struct V_18 * V_19 ,
struct V_4 * V_5 )
{
struct V_29 * V_16 = & V_19 -> V_16 [ V_5 -> V_16 ] ;
struct V_25 V_45 ;
F_14 ( V_19 , V_16 , V_5 ) ;
F_22 ( & V_45 ) ;
F_8 ( & V_5 -> V_22 , & V_45 ) ;
F_19 ( V_16 , & V_45 ) ;
}
static void F_23 ( struct V_18 * V_19 ,
struct V_46 * V_47 )
{
struct V_29 * V_16 ;
struct V_4 * V_5 ;
struct V_25 V_48 ;
int V_49 ;
F_22 ( & V_48 ) ;
F_17 ( V_39 ,
L_4 ,
V_47 -> V_2 , V_47 -> V_50 ) ;
if ( V_47 -> V_31 )
F_15 ( L_5 , V_47 -> V_31 ) ;
V_5 = V_47 -> V_51 [ 0 ] . V_5 ;
V_16 = & V_19 -> V_16 [ V_5 -> V_16 ] ;
for ( V_49 = 0 ; V_49 < V_47 -> V_50 ; V_49 ++ ) {
V_5 = V_47 -> V_51 [ V_49 ] . V_5 ;
if ( ! V_5 ) {
F_24 ( 1 ) ;
return;
}
V_5 -> V_31 = V_47 -> V_31 ;
F_14 ( V_19 , V_16 , V_5 ) ;
F_8 ( & V_5 -> V_22 , & V_48 ) ;
}
F_25 ( V_19 -> V_43 -> V_44 , V_47 ) ;
F_19 ( V_16 , & V_48 ) ;
}
static int F_26 ( struct V_18 * V_19 ,
struct V_4 * V_5 )
{
int V_31 ;
bool V_52 = false ;
T_2 V_53 , V_54 ;
if ( ! V_5 -> V_30 )
V_52 = true ;
V_54 = V_5 -> V_13 + V_11 ;
F_17 ( V_39 , L_6 ,
V_55 , V_54 , V_52 ? L_7 : L_8 ) ;
V_53 = F_27 ( V_19 , V_54 ) ;
F_17 ( V_39 ,
L_9 ,
V_53 ,
V_19 -> V_43 -> V_44 -> V_56 . V_57 ,
V_52 ? L_7 : L_8 ) ;
if ( V_52 ) {
V_31 = F_28 ( V_19 -> V_43 -> V_44 ,
V_19 -> V_43 -> V_44 -> V_56 . V_57 ,
V_5 -> V_1 , V_53 ,
V_58 ) ;
V_5 -> V_31 = V_31 ;
V_5 -> V_1 += V_11 ;
} else
V_31 = F_29 ( V_19 -> V_43 -> V_44 ,
V_19 -> V_43 -> V_44 -> V_56 . V_57 ,
V_5 -> V_1 , V_53 ,
V_59 , V_5 ) ;
return V_31 ;
}
static int F_30 ( struct V_18 * V_19 ,
struct V_29 * V_60 , T_1 * V_6 ,
enum V_61 V_15 , unsigned int V_2 ,
int * V_62 )
{
* V_62 = ( V_2 > V_19 -> V_63 ) ?
F_31 ( V_2 , V_19 -> V_63 ) : 1 ;
F_17 ( V_39 , L_10 ,
* V_62 , V_60 -> V_35 . V_64 ) ;
if ( V_60 -> V_35 . V_64 < * V_62 ) {
if ( V_15 == V_65 )
return - V_66 ;
V_60 -> V_35 . V_67 = * V_62 - V_60 -> V_35 . V_64 ;
F_17 ( V_39 , L_2 ,
V_19 -> V_40 , & V_60 -> V_35 ) ;
F_32 ( V_19 -> V_40 , & V_60 -> V_35 ) ;
V_60 -> V_35 . V_67 = 0 ;
if ( V_60 -> V_35 . V_64 < * V_62 ) {
F_17 ( V_39 ,
L_11 ,
V_15 ) ;
return - V_66 ;
}
}
V_60 -> V_35 . V_64 -= * V_62 ;
V_60 -> V_68 . V_69 += * V_62 ;
if ( V_60 -> V_35 . V_64 < V_60 -> V_35 . V_70 ) {
V_60 -> V_35 . V_67 =
V_60 -> V_35 . V_70 - V_60 -> V_35 . V_64 ;
F_17 ( V_39 , L_2 ,
V_19 -> V_40 , & V_60 -> V_35 ) ;
F_32 ( V_19 -> V_40 , & V_60 -> V_35 ) ;
if ( V_60 -> V_35 . V_64 < V_60 -> V_35 . V_70 ) {
* V_6 |= V_71 ;
V_60 -> V_68 . V_72 += 1 ;
F_17 ( V_39 , L_12 ) ;
}
}
return 0 ;
}
static void F_33 ( struct V_18 * V_19 ,
struct V_29 * V_16 ,
struct V_25 * V_73 )
{
int V_62 ;
T_1 V_6 ;
struct V_4 * V_5 ;
unsigned int V_2 ;
while ( true ) {
V_6 = 0 ;
if ( F_11 ( & V_16 -> V_38 ) )
break;
V_5 = F_12 ( & V_16 -> V_38 , struct V_4 ,
V_22 ) ;
F_17 ( V_39 ,
L_13 ,
V_5 , F_16 ( & V_16 -> V_38 ) ) ;
V_2 = F_27 ( V_19 ,
V_5 -> V_13 + V_11 ) ;
if ( F_30 ( V_19 , V_16 , & V_6 ,
V_5 -> V_16 , V_2 , & V_62 ) )
break;
V_5 = F_12 ( & V_16 -> V_38 , struct V_4 ,
V_22 ) ;
F_34 ( & V_5 -> V_22 , V_73 ) ;
V_5 -> V_32 . V_24 . V_33 = V_62 ;
V_5 -> V_30 = F_21 ;
V_5 -> V_74 = V_19 ;
V_16 -> V_68 . V_75 += 1 ;
V_5 -> V_32 . V_24 . V_6 = V_6 ;
V_5 -> V_32 . V_24 . V_76 = V_16 -> V_76 ;
V_16 -> V_76 ++ ;
}
}
static int F_35 ( unsigned int V_77 , int * V_2 ,
struct V_29 * V_60 )
{
int V_78 , V_79 ;
V_78 = * V_2 % V_77 ;
if ( ! V_78 )
return 0 ;
if ( ! ( V_60 -> V_80 & V_81 ) )
return - 1 ;
V_79 = * V_2 < V_77 ? ( V_77 - * V_2 ) : V_78 ;
if ( ( V_79 > 0 ) && ( V_79 <= 255 ) )
* V_2 += V_79 ;
else
return - 1 ;
return V_79 ;
}
static int F_36 ( struct V_18 * V_19 ,
struct V_29 * V_16 ,
struct V_46 * V_47 ,
int V_82 ,
struct V_25 * V_73 )
{
struct V_4 * V_5 ;
int V_49 , V_2 , V_83 , V_79 ;
int V_31 = 0 ;
V_83 = V_19 -> V_84 ;
for ( V_49 = 0 ; V_49 < V_82 ; V_49 ++ ) {
V_47 -> V_51 [ V_49 ] . V_5 = NULL ;
if ( F_11 ( V_73 ) )
break;
V_5 = F_12 ( V_73 , struct V_4 , V_22 ) ;
V_2 = F_27 ( V_19 ,
V_5 -> V_13 + V_11 ) ;
V_79 = F_35 ( V_19 -> V_63 ,
& V_2 , V_16 ) ;
if ( V_79 < 0 || V_83 < V_2 ) {
V_31 = - V_85 ;
break;
}
V_83 -= V_2 ;
F_13 ( & V_5 -> V_22 ) ;
V_47 -> V_51 [ V_49 ] . V_5 = V_5 ;
F_4 ( V_5 ,
V_5 -> V_32 . V_24 . V_6 | V_86 ,
V_79 , V_5 -> V_32 . V_24 . V_76 ) ;
F_1 ( & V_5 -> V_1 ,
V_5 -> V_13 + V_11 ) ;
V_47 -> V_51 [ V_49 ] . V_1 = V_5 -> V_1 ;
V_47 -> V_51 [ V_49 ] . V_2 = V_2 ;
V_47 -> V_2 += V_2 ;
V_47 -> V_50 ++ ;
F_17 ( V_39 ,
L_14 ,
V_49 , V_5 , V_2 , V_83 ) ;
}
if ( V_47 -> V_50 < V_87 ) {
for ( V_49 = V_47 -> V_50 - 1 ; V_49 >= 0 ; V_49 -- ) {
V_5 = V_47 -> V_51 [ V_49 ] . V_5 ;
if ( V_5 ) {
V_5 -> V_1 += V_11 ;
F_37 ( & V_5 -> V_22 , V_73 ) ;
}
}
return - V_88 ;
}
return V_31 ;
}
static void F_38 ( struct V_29 * V_16 ,
struct V_25 * V_73 ,
int * V_89 , int * V_90 )
{
struct V_18 * V_19 = V_16 -> V_19 ;
struct V_46 * V_47 = NULL ;
int V_82 , V_91 = 0 , V_92 = 0 ;
int V_31 ;
while ( true ) {
V_31 = 0 ;
V_82 = F_16 ( V_73 ) ;
V_82 = F_39 ( V_82 , V_19 -> V_93 ) ;
if ( V_82 < V_87 )
break;
V_47 = F_40 ( V_19 -> V_43 -> V_44 ) ;
if ( ! V_47 ) {
F_17 ( V_39 ,
L_15 ) ;
break;
}
F_17 ( V_39 , L_16 ,
V_82 ) ;
V_47 -> V_2 = 0 ;
V_47 -> V_50 = 0 ;
V_31 = F_36 ( V_19 , V_16 ,
V_47 , V_82 ,
V_73 ) ;
if ( V_31 == - V_88 ) {
F_25 ( V_19 -> V_43 -> V_44 , V_47 ) ;
break;
}
V_47 -> V_94 = F_23 ;
V_91 ++ ;
V_92 += V_47 -> V_50 ;
F_17 ( V_39 ,
L_17 ,
V_47 -> V_2 , V_47 -> V_50 ) ;
F_41 ( V_19 -> V_43 , V_47 , false ) ;
if ( V_31 )
break;
}
* V_89 = V_91 ;
* V_90 = V_92 ;
F_17 ( V_39 , L_18 ,
V_55 , V_91 ) ;
return;
}
static void F_42 ( struct V_18 * V_19 ,
struct V_29 * V_16 )
{
struct V_25 V_38 ;
struct V_4 * V_5 ;
int V_95 ;
int V_96 ;
F_7 ( & V_19 -> V_34 ) ;
V_16 -> V_97 ++ ;
if ( V_16 -> V_97 > 1 ) {
V_16 -> V_97 -- ;
F_9 ( & V_19 -> V_34 ) ;
F_17 ( V_39 , L_19 ) ;
return;
}
F_22 ( & V_38 ) ;
while ( true ) {
if ( F_11 ( & V_16 -> V_38 ) )
break;
F_33 ( V_19 , V_16 , & V_38 ) ;
if ( F_11 ( & V_38 ) )
break;
F_9 ( & V_19 -> V_34 ) ;
V_95 = 0 ;
V_96 = 0 ;
while ( true ) {
if ( ( V_19 -> V_98 ) &&
( F_16 ( & V_38 ) >=
V_87 ) ) {
int V_99 = 0 , V_100 = 0 ;
F_38 ( V_16 , & V_38 ,
& V_99 , & V_100 ) ;
V_95 += V_99 ;
V_96 += V_100 ;
}
if ( F_11 ( & V_38 ) )
break;
V_5 = F_12 ( & V_38 , struct V_4 ,
V_22 ) ;
F_13 ( & V_5 -> V_22 ) ;
F_4 ( V_5 , V_5 -> V_32 . V_24 . V_6 ,
0 , V_5 -> V_32 . V_24 . V_76 ) ;
F_26 ( V_19 , V_5 ) ;
}
F_7 ( & V_19 -> V_34 ) ;
V_16 -> V_68 . V_101 += V_95 ;
V_16 -> V_68 . V_102 += V_96 ;
}
V_16 -> V_97 = 0 ;
F_9 ( & V_19 -> V_34 ) ;
}
static bool F_43 ( struct V_18 * V_19 ,
struct V_29 * V_16 ,
struct V_4 * V_103 )
{
struct V_104 V_105 ;
int V_37 ;
bool V_106 = false ;
V_105 = V_16 -> V_105 ;
F_7 ( & V_19 -> V_34 ) ;
V_37 = F_16 ( & V_16 -> V_38 ) ;
F_9 ( & V_19 -> V_34 ) ;
if ( V_37 >= V_16 -> V_107 )
V_106 = true ;
if ( V_106 )
F_17 ( V_39 ,
L_20 ,
V_16 -> V_15 , V_106 , V_37 ,
V_16 -> V_107 ) ;
if ( V_106 && V_105 . V_108 ) {
F_17 ( V_39 ,
L_21 , V_103 ) ;
if ( V_105 . V_108 ( V_16 -> V_19 , V_103 ) ==
V_109 ) {
V_16 -> V_68 . V_110 += 1 ;
return false ;
}
}
F_7 ( & V_19 -> V_34 ) ;
F_8 ( & V_103 -> V_22 , & V_16 -> V_38 ) ;
F_9 ( & V_19 -> V_34 ) ;
F_42 ( V_19 , V_16 ) ;
return true ;
}
static void F_44 ( struct V_18 * V_19 )
{
struct V_29 * V_16 ;
struct V_111 * V_35 ;
F_45 (cred_dist, &target->cred_dist_list, list) {
V_16 = (struct V_29 * ) V_35 -> V_112 ;
F_7 ( & V_19 -> V_34 ) ;
if ( ! F_11 ( & V_16 -> V_38 ) ) {
F_17 ( V_39 ,
L_22 ,
V_35 -> V_16 ,
V_16 -> V_35 . V_64 ,
F_16 ( & V_16 -> V_38 ) ) ;
F_9 ( & V_19 -> V_34 ) ;
F_42 ( V_19 , V_16 ) ;
F_7 ( & V_19 -> V_34 ) ;
}
F_9 ( & V_19 -> V_34 ) ;
}
}
static int F_46 ( struct V_18 * V_19 )
{
struct V_4 * V_113 = NULL ;
int V_31 ;
V_113 = F_10 ( V_19 , true ) ;
if ( ! V_113 )
return - V_114 ;
if ( V_19 -> V_115 >= V_116 ) {
struct V_117 * V_118 ;
T_2 V_6 = 0 ;
V_118 =
(struct V_117 * ) V_113 -> V_1 ;
memset ( V_118 , 0 , sizeof( * V_118 ) ) ;
V_118 -> V_119 =
F_47 ( V_120 ) ;
if ( V_19 -> V_93 > 0 ) {
V_6 |= V_121 ;
V_118 -> V_122 =
V_19 -> V_93 ;
}
memcpy ( & V_118 -> V_6 , & V_6 ,
sizeof( V_118 -> V_6 ) ) ;
F_48 ( V_113 , NULL , ( T_1 * ) V_118 ,
sizeof( struct V_117 ) ,
V_65 , V_123 ) ;
} else {
struct V_124 * V_125 ;
V_125 = (struct V_124 * ) V_113 -> V_1 ;
memset ( V_125 , 0 , sizeof( struct V_124 ) ) ;
V_125 -> V_119 = F_47 ( V_126 ) ;
F_48 ( V_113 , NULL , ( T_1 * ) V_125 ,
sizeof( struct V_124 ) ,
V_65 , V_123 ) ;
}
V_113 -> V_30 = NULL ;
F_4 ( V_113 , 0 , 0 , 0 ) ;
V_31 = F_26 ( V_19 , V_113 ) ;
if ( V_113 != NULL )
F_6 ( V_19 , V_113 ) ;
return V_31 ;
}
void F_49 ( struct V_18 * V_19 ,
struct V_127 * V_40 ,
V_12 V_128 [] , int V_129 )
{
struct V_29 * V_16 ;
int V_49 , V_60 ;
V_19 -> V_40 = V_40 ;
F_8 ( & V_19 -> V_16 [ V_65 ] . V_35 . V_22 ,
& V_19 -> V_41 ) ;
for ( V_49 = 0 ; V_49 < V_129 ; V_49 ++ ) {
for ( V_60 = V_130 ; V_60 < V_131 ; V_60 ++ ) {
V_16 = & V_19 -> V_16 [ V_60 ] ;
if ( V_16 -> V_132 == V_128 [ V_49 ] ) {
F_8 ( & V_16 -> V_35 . V_22 ,
& V_19 -> V_41 ) ;
break;
}
}
if ( V_60 >= V_131 ) {
F_24 ( 1 ) ;
return;
}
}
}
int F_50 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
struct V_29 * V_16 ;
struct V_25 V_73 ;
F_17 ( V_39 ,
L_23 ,
V_5 -> V_16 , V_5 -> V_1 , V_5 -> V_13 ) ;
if ( V_5 -> V_16 >= V_131 ) {
F_24 ( 1 ) ;
return - V_66 ;
}
V_16 = & V_19 -> V_16 [ V_5 -> V_16 ] ;
if ( ! F_43 ( V_19 , V_16 , V_5 ) ) {
V_5 -> V_31 = ( V_19 -> V_133 & V_134 ) ?
- V_135 : - V_85 ;
F_22 ( & V_73 ) ;
F_37 ( & V_5 -> V_22 , & V_73 ) ;
F_19 ( V_16 , & V_73 ) ;
}
return 0 ;
}
void F_51 ( struct V_18 * V_19 ,
enum V_61 V_15 , V_12 V_136 )
{
struct V_4 * V_5 , * V_137 ;
struct V_25 V_138 , V_45 ;
struct V_29 * V_16 = & V_19 -> V_16 [ V_15 ] ;
if ( ! V_16 -> V_132 ) {
F_24 ( 1 ) ;
return;
}
F_22 ( & V_138 ) ;
F_7 ( & V_19 -> V_34 ) ;
F_52 (packet, tmp_pkt, &endpoint->txq, list) {
if ( ( V_136 == V_139 ) ||
( V_136 == V_5 -> V_32 . V_24 . V_136 ) )
F_34 ( & V_5 -> V_22 , & V_138 ) ;
}
F_9 ( & V_19 -> V_34 ) ;
F_52 (packet, tmp_pkt, &discard_q, list) {
V_5 -> V_31 = - V_135 ;
F_13 ( & V_5 -> V_22 ) ;
F_17 ( V_140 ,
L_24 ,
V_5 , V_5 -> V_13 ,
V_5 -> V_16 , V_5 -> V_32 . V_24 . V_136 ) ;
F_22 ( & V_45 ) ;
F_8 ( & V_5 -> V_22 , & V_45 ) ;
F_19 ( V_16 , & V_45 ) ;
}
}
static void F_53 ( struct V_18 * V_19 )
{
struct V_29 * V_16 ;
int V_49 ;
F_54 ( V_19 ) ;
for ( V_49 = V_65 ; V_49 < V_131 ; V_49 ++ ) {
V_16 = & V_19 -> V_16 [ V_49 ] ;
if ( V_16 -> V_132 == 0 )
continue;
F_51 ( V_19 , V_49 , V_139 ) ;
}
}
void F_55 ( struct V_18 * V_19 ,
enum V_61 V_15 , bool V_141 )
{
struct V_29 * V_16 = & V_19 -> V_16 [ V_15 ] ;
bool V_142 = false ;
if ( V_16 -> V_132 == 0 ) {
F_24 ( 1 ) ;
return;
}
F_7 ( & V_19 -> V_34 ) ;
if ( V_141 ) {
if ( ! ( V_16 -> V_35 . V_143 & V_144 ) ) {
V_16 -> V_35 . V_143 |= V_144 ;
V_142 = true ;
}
} else {
if ( V_16 -> V_35 . V_143 & V_144 ) {
V_16 -> V_35 . V_143 &= ~ V_144 ;
V_142 = true ;
}
}
if ( V_142 ) {
V_16 -> V_35 . V_37 =
F_16 ( & V_16 -> V_38 ) ;
F_17 ( V_39 , L_2 ,
V_19 -> V_40 , & V_19 -> V_41 ) ;
F_18 ( V_19 -> V_40 ,
& V_19 -> V_41 ,
V_145 ) ;
}
F_9 ( & V_19 -> V_34 ) ;
if ( V_142 && ! V_141 )
F_44 ( V_19 ) ;
}
static inline void F_56 ( struct V_29 * V_16 ,
int V_146 )
{
V_16 -> V_68 . V_147 ++ ;
if ( V_146 == 1 )
V_16 -> V_68 . V_148 ++ ;
else if ( V_146 > 1 )
V_16 -> V_68 . V_149 ++ ;
}
static inline bool F_57 ( struct V_18 * V_19 ,
enum V_61 V_15 , int V_2 )
{
return ( V_15 == V_19 -> V_43 -> V_44 -> V_150 ) ?
V_2 <= V_151 : V_2 <= V_152 ;
}
static int F_58 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
struct V_25 V_73 ;
F_22 ( & V_73 ) ;
F_8 ( & V_5 -> V_22 , & V_73 ) ;
return F_59 ( V_19 , & V_73 ) ;
}
static void F_60 ( struct V_18 * V_19 ,
struct V_4 * V_5 ,
struct V_29 * V_60 )
{
if ( V_5 -> V_32 . V_153 . V_154 & V_155 ) {
F_61 ( V_5 ) ;
V_5 -> V_31 = - V_135 ;
V_60 -> V_105 . V_153 ( V_60 -> V_19 , V_5 ) ;
} else {
F_61 ( V_5 ) ;
F_58 ( ( void * ) ( V_19 ) , V_5 ) ;
}
}
static void F_62 ( struct V_18 * V_19 ,
struct V_4 * V_5 )
{
F_7 ( & V_19 -> V_21 ) ;
F_8 ( & V_5 -> V_22 , & V_19 -> V_27 ) ;
F_9 ( & V_19 -> V_21 ) ;
}
static int F_63 ( struct V_18 * V_19 ,
struct V_4 * V_5 ,
T_2 V_156 )
{
struct V_157 * V_43 = V_19 -> V_43 ;
T_2 V_53 ;
int V_31 ;
V_53 = F_27 ( V_19 , V_156 ) ;
if ( V_53 > V_5 -> V_158 ) {
F_15 ( L_25 ,
V_53 , V_156 , V_5 -> V_158 ) ;
return - V_114 ;
}
F_17 ( V_159 ,
L_26 ,
V_5 , V_5 -> V_32 . V_153 . V_160 ,
V_53 , V_43 -> V_44 -> V_56 . V_57 , L_7 ) ;
V_31 = F_28 ( V_43 -> V_44 ,
V_43 -> V_44 -> V_56 . V_57 ,
V_5 -> V_1 , V_53 ,
V_161 ) ;
V_5 -> V_31 = V_31 ;
return V_31 ;
}
static void F_64 ( T_2 V_162 ,
struct V_29 * V_16 ,
struct V_4 * V_5 )
{
struct V_9 * V_163 = (struct V_9 * ) & V_162 ;
if ( V_163 -> V_15 == V_5 -> V_16 ) {
if ( ! F_11 ( & V_16 -> V_164 ) )
V_5 -> V_32 . V_153 . V_165 |=
V_166 ;
}
}
static void F_65 ( struct V_29 * V_16 )
{
struct V_104 V_105 = V_16 -> V_105 ;
if ( V_105 . V_167 > 0 ) {
F_7 ( & V_16 -> V_19 -> V_168 ) ;
if ( F_16 ( & V_16 -> V_164 )
< V_105 . V_167 ) {
F_9 ( & V_16 -> V_19 -> V_168 ) ;
V_105 . V_169 ( V_16 -> V_19 , V_16 -> V_15 ) ;
return;
}
F_9 ( & V_16 -> V_19 -> V_168 ) ;
}
}
static int F_66 ( struct V_18 * V_19 ,
struct V_29 * V_60 ,
T_2 * V_170 , struct V_25 * V_73 , int V_171 )
{
struct V_4 * V_5 ;
struct V_9 * V_163 = (struct V_9 * ) V_170 ;
struct V_104 V_105 ;
int V_31 = 0 , V_172 , V_173 ;
bool V_174 ;
V_173 = F_27 ( V_19 ,
F_67 ( V_163 -> V_14 ) +
sizeof( * V_163 ) ) ;
if ( ! F_57 ( V_19 , V_60 -> V_15 , V_173 ) ) {
F_68 ( L_27 ) ;
return - V_66 ;
}
V_105 = V_60 -> V_105 ;
for ( V_172 = 0 ; V_172 < V_171 ; V_172 ++ ) {
V_174 = false ;
if ( V_105 . V_175 &&
( V_173 > V_105 . V_176 ) ) {
V_60 -> V_68 . V_177 += 1 ;
V_60 -> V_68 . V_178 +=
F_67 ( V_163 -> V_14 ) ;
F_9 ( & V_19 -> V_168 ) ;
V_174 = true ;
V_5 = V_105 . V_175 ( V_60 -> V_19 , V_60 -> V_15 ,
V_173 ) ;
F_7 ( & V_19 -> V_168 ) ;
} else {
if ( F_11 ( & V_60 -> V_164 ) ) {
if ( V_105 . V_169 ) {
F_9 ( & V_19 -> V_168 ) ;
V_105 . V_169 ( V_60 -> V_19 , V_60 -> V_15 ) ;
F_7 ( & V_19 -> V_168 ) ;
}
}
if ( F_11 ( & V_60 -> V_164 ) )
V_5 = NULL ;
else {
V_5 = F_12 ( & V_60 -> V_164 ,
struct V_4 , V_22 ) ;
F_13 ( & V_5 -> V_22 ) ;
}
}
if ( ! V_5 ) {
V_19 -> V_179 |= V_180 ;
V_19 -> V_181 = V_60 -> V_15 ;
return - V_85 ;
}
V_5 -> V_32 . V_153 . V_154 = 0 ;
V_5 -> V_32 . V_153 . V_165 = 0 ;
V_5 -> V_31 = 0 ;
if ( V_174 )
V_5 -> V_32 . V_153 . V_154 |= V_155 ;
F_8 ( & V_5 -> V_22 , V_73 ) ;
if ( V_19 -> V_133 & V_134 ) {
V_31 = - V_135 ;
break;
}
if ( V_172 ) {
V_5 -> V_32 . V_153 . V_154 |= V_182 ;
V_5 -> V_32 . V_153 . V_160 = 0xFFFFFFFF ;
} else
V_5 -> V_32 . V_153 . V_160 = * V_170 ;
V_5 -> V_13 = F_67 ( V_163 -> V_14 ) +
V_11 ;
}
return V_31 ;
}
static int F_69 ( struct V_18 * V_19 ,
T_2 V_170 [] , int V_183 ,
struct V_29 * V_16 ,
struct V_25 * V_73 )
{
int V_31 = 0 ;
struct V_4 * V_5 , * V_137 ;
struct V_9 * V_163 ;
int V_49 , V_171 ;
F_7 ( & V_19 -> V_168 ) ;
for ( V_49 = 0 ; V_49 < V_183 ; V_49 ++ ) {
V_163 = (struct V_9 * ) & V_170 [ V_49 ] ;
if ( V_163 -> V_15 >= V_131 ) {
F_15 ( L_28 ,
V_163 -> V_15 ) ;
V_31 = - V_114 ;
break;
}
if ( V_163 -> V_15 != V_16 -> V_15 ) {
F_15 ( L_29 ,
V_163 -> V_15 , V_16 -> V_15 , V_49 ) ;
V_31 = - V_114 ;
break;
}
if ( F_67 ( V_163 -> V_14 ) > V_184 ) {
F_15 ( L_30 ,
V_163 -> V_14 ,
( T_2 ) V_184 ) ;
V_31 = - V_114 ;
break;
}
if ( V_16 -> V_132 == 0 ) {
F_15 ( L_31 , V_163 -> V_15 ) ;
V_31 = - V_114 ;
break;
}
if ( V_163 -> V_6 & V_185 ) {
V_171 = ( V_163 -> V_6 & V_185 ) >>
V_186 ;
V_171 ++ ;
if ( V_171 > V_19 -> V_93 ) {
V_31 = - V_114 ;
break;
}
V_16 -> V_68 . V_187 += 1 ;
F_17 ( V_159 ,
L_32 ,
V_171 ) ;
} else
V_171 = 1 ;
V_31 = F_66 ( V_19 , V_16 , & V_170 [ V_49 ] ,
V_73 , V_171 ) ;
if ( V_31 == - V_85 ) {
F_9 ( & V_19 -> V_168 ) ;
return 0 ;
}
if ( V_31 )
break;
}
F_9 ( & V_19 -> V_168 ) ;
if ( V_31 ) {
F_52 (packet, tmp_pkt, queue, list) {
F_13 ( & V_5 -> V_22 ) ;
F_60 ( V_19 , V_5 ,
& V_19 -> V_16 [ V_5 -> V_16 ] ) ;
}
}
return V_31 ;
}
static void F_70 ( struct V_18 * V_74 , struct V_4 * V_188 )
{
if ( V_188 -> V_16 != V_65 ) {
F_24 ( 1 ) ;
return;
}
if ( V_188 -> V_31 == - V_135 ) {
F_62 ( V_74 , V_188 ) ;
return;
}
if ( V_188 -> V_13 > 0 ) {
F_15 ( L_33 ,
V_188 -> V_13 + V_11 ) ;
F_71 ( V_189 ,
L_34 , L_35 ,
V_188 -> V_1 - V_11 ,
V_188 -> V_13 + V_11 ) ;
}
F_60 ( V_74 , V_188 , & V_74 -> V_16 [ 0 ] ) ;
}
static void F_72 ( struct V_18 * V_19 ,
struct V_190 * V_191 ,
int V_192 ,
enum V_61 V_193 )
{
struct V_29 * V_16 ;
int V_194 = 0 , V_49 ;
bool V_142 = false ;
F_17 ( V_39 ,
L_36 , V_192 ) ;
F_7 ( & V_19 -> V_34 ) ;
for ( V_49 = 0 ; V_49 < V_192 ; V_49 ++ , V_191 ++ ) {
if ( V_191 -> V_15 >= V_131 ) {
F_24 ( 1 ) ;
F_9 ( & V_19 -> V_34 ) ;
return;
}
V_16 = & V_19 -> V_16 [ V_191 -> V_15 ] ;
F_17 ( V_39 , L_37 ,
V_191 -> V_15 , V_191 -> V_64 ) ;
V_16 -> V_68 . V_195 += 1 ;
V_16 -> V_68 . V_196 += V_191 -> V_64 ;
if ( V_193 == V_191 -> V_15 ) {
V_16 -> V_68 . V_197 += V_191 -> V_64 ;
V_16 -> V_68 . V_198 += 1 ;
} else if ( V_193 == V_65 ) {
V_16 -> V_68 . V_199 += V_191 -> V_64 ;
V_16 -> V_68 . V_200 += 1 ;
} else {
V_16 -> V_68 . V_201 += V_191 -> V_64 ;
V_16 -> V_68 . V_202 += 1 ;
}
if ( V_191 -> V_15 == V_65 )
V_16 -> V_35 . V_64 += V_191 -> V_64 ;
else {
V_16 -> V_35 . V_36 += V_191 -> V_64 ;
V_142 = true ;
}
V_16 -> V_35 . V_37 =
F_16 ( & V_16 -> V_38 ) ;
V_194 += V_191 -> V_64 ;
}
F_17 ( V_39 ,
L_38 ,
V_194 ) ;
if ( V_142 ) {
F_17 ( V_39 , L_2 ,
V_19 -> V_40 , & V_19 -> V_41 ) ;
F_18 ( V_19 -> V_40 ,
& V_19 -> V_41 ,
V_42 ) ;
}
F_9 ( & V_19 -> V_34 ) ;
if ( V_194 )
F_44 ( V_19 ) ;
}
static int F_73 ( struct V_18 * V_19 ,
struct V_203 * V_204 ,
T_1 * V_205 , T_2 * V_206 ,
enum V_61 V_16 ,
int * V_207 )
{
struct V_208 * V_209 ;
struct V_210 * V_162 ;
int V_2 ;
switch ( V_204 -> V_211 ) {
case V_212 :
V_2 = V_204 -> V_2 / sizeof( struct V_190 ) ;
if ( ! V_2 ) {
F_24 ( 1 ) ;
return - V_66 ;
}
F_72 ( V_19 ,
(struct V_190 * ) V_205 ,
V_2 , V_16 ) ;
break;
case V_213 :
V_2 = V_204 -> V_2 / sizeof( * V_162 ) ;
if ( ! V_2 ) {
F_24 ( 1 ) ;
return - V_66 ;
}
V_162 = (struct V_210 * ) V_205 ;
if ( ( V_162 -> V_214 == ( ( ~ V_162 -> V_215 ) & 0xFF ) )
&& V_206 ) {
F_17 ( V_159 ,
L_39 ,
V_162 -> V_214 , V_162 -> V_215 ) ;
memcpy ( ( T_1 * ) & V_206 [ 0 ] , V_162 -> V_162 , 4 ) ;
F_71 ( V_189 , L_40 ,
L_35 , V_206 , 4 ) ;
* V_207 = 1 ;
}
break;
case V_216 :
V_2 = V_204 -> V_2 / sizeof( * V_209 ) ;
if ( ! V_2 || ( V_2 > V_217 ) ) {
F_24 ( 1 ) ;
return - V_66 ;
}
if ( V_206 ) {
int V_49 ;
V_209 =
(struct V_208 * ) V_205 ;
F_71 ( V_189 , L_41 ,
L_35 , V_205 , V_204 -> V_2 ) ;
for ( V_49 = 0 ; V_49 < V_2 ; V_49 ++ ) {
memcpy ( ( T_1 * ) & V_206 [ V_49 ] ,
V_209 -> V_162 , 4 ) ;
V_209 ++ ;
}
* V_207 = V_49 ;
}
break;
default:
F_15 ( L_42 ,
V_204 -> V_211 , V_204 -> V_2 ) ;
break;
}
return 0 ;
}
static int F_74 ( struct V_18 * V_19 ,
T_1 * V_1 , int V_2 , T_2 * V_206 ,
int * V_207 , enum V_61 V_16 )
{
struct V_203 * V_204 ;
int V_218 ;
int V_31 ;
T_1 * V_205 ;
T_1 * V_219 ;
F_17 ( V_159 , L_43 , V_2 ) ;
F_71 ( V_189 , L_44 , L_35 ,
V_1 , V_2 ) ;
V_219 = V_1 ;
V_218 = V_2 ;
V_31 = 0 ;
while ( V_2 > 0 ) {
if ( V_2 < sizeof( struct V_203 ) ) {
V_31 = - V_114 ;
break;
}
V_204 = (struct V_203 * ) V_1 ;
V_2 -= sizeof( struct V_203 ) ;
V_1 += sizeof( struct V_203 ) ;
if ( V_204 -> V_2 > V_2 ) {
F_15 ( L_45 ,
V_204 -> V_2 , V_204 -> V_211 , V_2 ) ;
V_31 = - V_114 ;
break;
}
V_205 = V_1 ;
V_31 = F_73 ( V_19 , V_204 , V_205 ,
V_206 , V_16 , V_207 ) ;
if ( V_31 )
break;
V_1 += V_204 -> V_2 ;
V_2 -= V_204 -> V_2 ;
}
if ( V_31 )
F_71 ( V_189 , L_46 ,
L_35 , V_219 , V_218 ) ;
return V_31 ;
}
static int F_75 ( struct V_18 * V_19 ,
struct V_4 * V_5 ,
T_2 * V_220 , int * V_221 )
{
int V_31 = 0 ;
V_12 V_222 ;
T_2 V_162 ;
struct V_9 * V_163 = (struct V_9 * ) V_5 -> V_1 ;
if ( V_221 != NULL )
* V_221 = 0 ;
F_71 ( V_189 , L_47 , L_48 ,
V_5 -> V_1 , V_5 -> V_13 ) ;
V_222 = F_67 ( F_76 ( & V_163 -> V_14 ) ) ;
memcpy ( ( T_1 * ) & V_162 , V_5 -> V_1 , sizeof( V_162 ) ) ;
if ( V_5 -> V_32 . V_153 . V_154 & V_182 ) {
V_5 -> V_32 . V_153 . V_160 = V_162 ;
V_5 -> V_13 = V_222 + V_11 ;
if ( V_5 -> V_13 > V_5 -> V_158 ) {
F_15 ( L_49 ,
V_222 , V_162 ) ;
V_5 -> V_13 = F_39 ( V_5 -> V_13 , V_5 -> V_158 ) ;
V_31 = - V_114 ;
goto V_223;
}
if ( V_5 -> V_16 != V_163 -> V_15 ) {
F_15 ( L_50 ,
V_163 -> V_15 , V_5 -> V_16 ) ;
V_31 = - V_114 ;
goto V_223;
}
}
if ( V_162 != V_5 -> V_32 . V_153 . V_160 ) {
F_15 ( L_51 ,
V_55 , V_5 , V_5 -> V_32 . V_153 . V_154 ) ;
F_71 ( V_189 , L_52 ,
L_35 , & V_5 -> V_32 . V_153 . V_160 , 4 ) ;
F_71 ( V_189 , L_53 ,
L_35 , ( T_1 * ) & V_162 , sizeof( V_162 ) ) ;
V_31 = - V_114 ;
goto V_223;
}
if ( V_163 -> V_6 & V_224 ) {
if ( V_163 -> V_17 [ 0 ] < sizeof( struct V_203 ) ||
V_163 -> V_17 [ 0 ] > V_222 ) {
F_15 ( L_54 ,
V_55 , V_222 , V_163 -> V_17 [ 0 ] ) ;
V_31 = - V_114 ;
goto V_223;
}
if ( V_5 -> V_32 . V_153 . V_154 & V_225 ) {
V_220 = NULL ;
V_221 = NULL ;
}
V_31 = F_74 ( V_19 , V_5 -> V_1 + V_11
+ V_222 - V_163 -> V_17 [ 0 ] ,
V_163 -> V_17 [ 0 ] , V_220 ,
V_221 , V_5 -> V_16 ) ;
if ( V_31 )
goto V_223;
V_5 -> V_13 -= V_163 -> V_17 [ 0 ] ;
}
V_5 -> V_1 += V_11 ;
V_5 -> V_13 -= V_11 ;
V_223:
if ( V_31 )
F_71 ( V_189 , L_55 ,
L_35 , V_5 -> V_1 ,
V_5 -> V_13 < 256 ? V_5 -> V_13 : 256 ) ;
else {
if ( V_5 -> V_13 > 0 )
F_71 ( V_189 ,
L_56 , L_35 ,
V_5 -> V_1 , V_5 -> V_13 ) ;
}
return V_31 ;
}
static void F_77 ( struct V_29 * V_16 ,
struct V_4 * V_5 )
{
F_17 ( V_159 ,
L_57 ,
V_16 -> V_15 , V_5 ) ;
V_16 -> V_105 . V_153 ( V_16 -> V_19 , V_5 ) ;
}
static int F_78 ( struct V_18 * V_19 ,
struct V_25 * V_226 ,
struct V_25 * V_227 ,
int * V_228 , bool V_229 )
{
struct V_46 * V_47 ;
struct V_4 * V_5 ;
int V_230 = V_19 -> V_231 ;
int V_232 , V_31 = 0 , V_49 , V_2 ;
V_232 = F_16 ( V_226 ) ;
V_232 = F_39 ( V_232 , V_19 -> V_93 ) ;
if ( ( F_16 ( V_226 ) - V_232 ) > 0 ) {
V_229 = true ;
F_68 ( L_58 ,
V_55 , F_16 ( V_226 ) , V_232 ) ;
}
V_2 = 0 ;
F_17 ( V_159 ,
L_59 ,
V_55 , F_16 ( V_226 ) , V_232 ) ;
V_47 = F_40 ( V_19 -> V_43 -> V_44 ) ;
if ( V_47 == NULL )
goto V_233;
for ( V_49 = 0 ; V_49 < V_232 ; V_49 ++ ) {
int V_234 ;
V_5 = F_12 ( V_226 , struct V_4 , V_22 ) ;
F_13 ( & V_5 -> V_22 ) ;
V_234 = F_27 ( V_19 ,
V_5 -> V_13 ) ;
if ( ( V_230 - V_234 ) < 0 ) {
F_37 ( & V_5 -> V_22 , V_226 ) ;
break;
}
V_230 -= V_234 ;
if ( V_229 || ( V_49 < ( V_232 - 1 ) ) )
V_5 -> V_32 . V_153 . V_154 |=
V_225 ;
V_47 -> V_51 [ V_49 ] . V_1 = V_5 -> V_1 ;
V_47 -> V_51 [ V_49 ] . V_2 = V_234 ;
V_5 -> V_32 . V_153 . V_154 |= V_235 ;
F_8 ( & V_5 -> V_22 , V_227 ) ;
F_24 ( ! V_47 -> V_51 [ V_49 ] . V_2 ) ;
V_2 += V_47 -> V_51 [ V_49 ] . V_2 ;
}
V_47 -> V_2 = V_2 ;
V_47 -> V_50 = V_49 ;
V_31 = F_41 ( V_19 -> V_43 , V_47 , true ) ;
if ( ! V_31 )
* V_228 = V_49 ;
F_25 ( V_19 -> V_43 -> V_44 , V_47 ) ;
V_233:
return V_31 ;
}
static int F_79 ( struct V_18 * V_19 ,
struct V_25 * V_236 ,
T_2 V_170 [] ,
int * V_237 )
{
struct V_4 * V_5 , * V_137 ;
struct V_29 * V_60 ;
int V_31 = 0 ;
F_52 (packet, tmp_pkt, comp_pktq, list) {
F_13 ( & V_5 -> V_22 ) ;
V_60 = & V_19 -> V_16 [ V_5 -> V_16 ] ;
V_31 = F_75 ( V_19 , V_5 , V_170 ,
V_237 ) ;
if ( V_31 )
return V_31 ;
if ( F_11 ( V_236 ) ) {
if ( * V_237 > 0 )
F_64 ( V_170 [ 0 ] ,
V_60 , V_5 ) ;
} else
V_5 -> V_32 . V_153 . V_165 |=
V_166 ;
F_56 ( V_60 , * V_237 ) ;
if ( V_5 -> V_32 . V_153 . V_154 & V_235 )
V_60 -> V_68 . V_238 += 1 ;
F_77 ( V_60 , V_5 ) ;
}
return V_31 ;
}
static int F_80 ( struct V_18 * V_19 ,
struct V_25 * V_239 ,
struct V_25 * V_236 )
{
int V_240 ;
bool V_229 = false ;
int V_31 = 0 ;
while ( ! F_11 ( V_239 ) ) {
V_240 = 0 ;
if ( V_19 -> V_241 && ( F_16 ( V_239 ) > 1 ) ) {
V_31 = F_78 ( V_19 , V_239 ,
V_236 ,
& V_240 ,
V_229 ) ;
if ( V_31 )
return V_31 ;
if ( ! F_11 ( V_239 ) )
V_229 = true ;
}
if ( ! V_240 ) {
struct V_4 * V_5 ;
V_5 = F_12 ( V_239 , struct V_4 ,
V_22 ) ;
F_13 ( & V_5 -> V_22 ) ;
V_5 -> V_30 = NULL ;
if ( ! F_11 ( V_239 ) )
V_5 -> V_32 . V_153 . V_154 |=
V_225 ;
V_31 = F_63 ( V_19 , V_5 ,
V_5 -> V_13 ) ;
if ( V_31 )
return V_31 ;
F_8 ( & V_5 -> V_22 , V_236 ) ;
}
}
return V_31 ;
}
int F_81 ( struct V_18 * V_19 ,
T_2 V_242 [] , int * V_243 )
{
struct V_4 * V_188 , * V_137 ;
struct V_29 * V_16 ;
struct V_25 V_239 , V_236 ;
int V_31 = 0 ;
T_2 V_244 [ V_217 ] ;
int V_245 = 1 ;
enum V_61 V_246 ;
int V_247 = 0 ;
* V_243 = 0 ;
memcpy ( V_244 , V_242 , sizeof( V_244 ) ) ;
while ( true ) {
V_246 = ( (struct V_9 * ) & V_244 [ 0 ] ) -> V_15 ;
V_16 = & V_19 -> V_16 [ V_246 ] ;
if ( V_246 >= V_131 ) {
F_15 ( L_60 ,
V_246 ) ;
V_31 = - V_114 ;
break;
}
F_22 ( & V_239 ) ;
F_22 ( & V_236 ) ;
V_31 = F_69 ( V_19 , V_244 ,
V_245 , V_16 ,
& V_239 ) ;
if ( V_31 )
break;
if ( F_16 ( & V_239 ) >= 2 )
V_19 -> V_248 = 1 ;
V_247 += F_16 ( & V_239 ) ;
V_245 = 0 ;
V_31 = F_80 ( V_19 , & V_239 , & V_236 ) ;
if ( ! V_31 )
F_65 ( V_16 ) ;
V_31 = F_79 ( V_19 , & V_236 ,
V_244 ,
& V_245 ) ;
if ( ! V_245 || V_31 )
break;
V_19 -> V_248 = 1 ;
}
if ( V_31 ) {
F_15 ( L_61 ,
V_31 ) ;
F_52 (packets, tmp_pkt, &rx_pktq, list) {
F_13 ( & V_188 -> V_22 ) ;
F_60 ( V_19 , V_188 ,
& V_19 -> V_16 [ V_188 -> V_16 ] ) ;
}
F_52 (packets, tmp_pkt, &comp_pktq, list) {
F_13 ( & V_188 -> V_22 ) ;
F_60 ( V_19 , V_188 ,
& V_19 -> V_16 [ V_188 -> V_16 ] ) ;
}
if ( V_19 -> V_133 & V_134 ) {
F_68 ( L_62 ) ;
F_82 ( V_19 -> V_43 , false ) ;
}
}
if ( V_19 -> V_179 & V_180 ) {
F_68 ( L_63 ) ;
F_82 ( V_19 -> V_43 , false ) ;
}
* V_243 = V_247 ;
return V_31 ;
}
static struct V_4 * F_83 ( struct V_18 * V_19 )
{
struct V_4 * V_5 = NULL ;
struct V_9 * V_163 ;
T_2 V_249 ;
if ( F_84 ( V_19 -> V_43 , & V_249 ,
V_250 ) )
return NULL ;
F_17 ( V_159 ,
L_64 , V_249 ) ;
V_163 = (struct V_9 * ) & V_249 ;
if ( V_163 -> V_15 != V_65 )
return NULL ;
V_5 = F_10 ( V_19 , false ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_32 . V_153 . V_154 = 0 ;
V_5 -> V_32 . V_153 . V_160 = V_249 ;
V_5 -> V_13 = F_67 ( V_163 -> V_14 ) + V_11 ;
if ( V_5 -> V_13 > V_5 -> V_158 )
goto V_251;
V_5 -> V_30 = NULL ;
if ( F_63 ( V_19 , V_5 , V_5 -> V_13 ) )
goto V_251;
V_5 -> V_31 = F_75 ( V_19 , V_5 , NULL , NULL ) ;
if ( V_5 -> V_31 ) {
F_15 ( L_65 ,
V_5 -> V_31 ) ;
goto V_251;
}
return V_5 ;
V_251:
if ( V_5 != NULL ) {
F_61 ( V_5 ) ;
F_62 ( V_19 , V_5 ) ;
}
return NULL ;
}
int F_59 ( struct V_18 * V_19 ,
struct V_25 * V_252 )
{
struct V_29 * V_16 ;
struct V_4 * V_253 ;
bool V_254 = false ;
int V_31 = 0 , V_255 ;
if ( F_11 ( V_252 ) )
return - V_114 ;
V_253 = F_12 ( V_252 , struct V_4 , V_22 ) ;
if ( V_253 -> V_16 >= V_131 )
return V_31 ;
V_255 = F_16 ( V_252 ) ;
F_17 ( V_159 ,
L_66 ,
V_253 -> V_16 , V_255 , V_253 -> V_158 ) ;
V_16 = & V_19 -> V_16 [ V_253 -> V_16 ] ;
if ( V_19 -> V_133 & V_134 ) {
struct V_4 * V_5 , * V_137 ;
F_52 (packet, tmp_pkt, pkt_queue, list) {
V_5 -> V_31 = - V_135 ;
F_13 ( & V_5 -> V_22 ) ;
F_77 ( V_16 , V_5 ) ;
}
return V_31 ;
}
F_7 ( & V_19 -> V_168 ) ;
F_85 ( V_252 , & V_16 -> V_164 ) ;
if ( V_19 -> V_179 & V_180 ) {
if ( V_19 -> V_181 == V_253 -> V_16 ) {
F_17 ( V_159 ,
L_67 ,
V_19 -> V_181 ) ;
V_19 -> V_179 &= ~ V_180 ;
V_19 -> V_181 = V_131 ;
V_254 = true ;
}
}
F_9 ( & V_19 -> V_168 ) ;
if ( V_254 && ! ( V_19 -> V_133 & V_134 ) )
F_82 ( V_19 -> V_43 , true ) ;
return V_31 ;
}
void F_86 ( struct V_18 * V_19 )
{
struct V_29 * V_16 ;
struct V_4 * V_5 , * V_137 ;
int V_49 ;
for ( V_49 = V_65 ; V_49 < V_131 ; V_49 ++ ) {
V_16 = & V_19 -> V_16 [ V_49 ] ;
if ( ! V_16 -> V_132 )
continue;
F_7 ( & V_19 -> V_168 ) ;
F_52 (packet, tmp_pkt,
&endpoint->rx_bufq, list) {
F_13 ( & V_5 -> V_22 ) ;
F_9 ( & V_19 -> V_168 ) ;
F_17 ( V_159 ,
L_68 ,
V_5 , V_5 -> V_158 ,
V_5 -> V_16 ) ;
F_87 ( V_5 -> V_256 ) ;
F_7 ( & V_19 -> V_168 ) ;
}
F_9 ( & V_19 -> V_168 ) ;
}
}
int F_88 ( struct V_18 * V_19 ,
struct V_257 * V_258 ,
struct V_259 * V_260 )
{
struct V_4 * V_261 = NULL ;
struct V_4 * V_103 = NULL ;
struct V_262 * V_263 ;
struct V_264 * V_265 ;
struct V_29 * V_16 ;
enum V_61 V_266 = V_131 ;
unsigned int V_267 = 0 ;
int V_31 = 0 ;
F_17 ( V_140 ,
L_69 ,
V_19 , V_258 -> V_132 ) ;
if ( V_258 -> V_132 == V_268 ) {
V_266 = V_65 ;
V_267 = V_269 ;
} else {
V_103 = F_10 ( V_19 , true ) ;
if ( ! V_103 )
return - V_114 ;
V_265 = (struct V_264 * ) V_103 -> V_1 ;
memset ( V_265 , 0 , sizeof( * V_265 ) ) ;
V_265 -> V_119 = F_47 ( V_270 ) ;
V_265 -> V_132 = F_47 ( V_258 -> V_132 ) ;
V_265 -> V_80 = F_47 ( V_258 -> V_80 ) ;
F_48 ( V_103 , NULL , ( T_1 * ) V_265 ,
sizeof( * V_265 ) + V_265 -> V_271 ,
V_65 , V_123 ) ;
V_103 -> V_30 = NULL ;
F_4 ( V_103 , 0 , 0 , 0 ) ;
V_31 = F_26 ( V_19 , V_103 ) ;
if ( V_31 )
goto V_272;
V_261 = F_83 ( V_19 ) ;
if ( ! V_261 ) {
V_31 = - V_114 ;
goto V_272;
}
V_263 = (struct V_262 * ) V_261 -> V_1 ;
if ( ( F_67 ( V_263 -> V_119 ) != V_273 )
|| ( V_261 -> V_13 < sizeof( * V_263 ) ) ) {
V_31 = - V_114 ;
goto V_272;
}
V_260 -> V_274 = V_263 -> V_31 ;
if ( V_263 -> V_31 != V_275 ) {
F_15 ( L_70 ,
V_263 -> V_132 , V_263 -> V_31 ) ;
V_31 = - V_114 ;
goto V_272;
}
V_266 = (enum V_61 ) V_263 -> V_15 ;
V_267 = F_67 ( V_263 -> V_267 ) ;
}
if ( V_266 >= V_131 || ! V_267 ) {
V_31 = - V_114 ;
goto V_272;
}
V_16 = & V_19 -> V_16 [ V_266 ] ;
V_16 -> V_15 = V_266 ;
if ( V_16 -> V_132 ) {
V_31 = - V_114 ;
goto V_272;
}
V_260 -> V_16 = V_266 ;
V_260 -> V_276 = V_267 ;
V_16 -> V_132 = V_258 -> V_132 ;
V_16 -> V_107 = V_258 -> V_107 ;
V_16 -> V_276 = V_267 ;
V_16 -> V_105 = V_258 -> V_105 ;
V_16 -> V_35 . V_132 = V_258 -> V_132 ;
V_16 -> V_35 . V_112 = V_16 ;
V_16 -> V_35 . V_16 = V_266 ;
V_16 -> V_35 . V_77 = V_19 -> V_63 ;
if ( V_258 -> V_277 ) {
if ( V_258 -> V_277 > V_267 ) {
V_31 = - V_114 ;
goto V_272;
}
V_16 -> V_35 . V_70 =
V_258 -> V_277 / V_19 -> V_63 ;
} else
V_16 -> V_35 . V_70 =
V_267 / V_19 -> V_63 ;
if ( ! V_16 -> V_35 . V_70 )
V_16 -> V_35 . V_70 = 1 ;
V_16 -> V_80 = V_258 -> V_6 ;
V_272:
if ( V_103 )
F_6 ( V_19 , V_103 ) ;
if ( V_261 ) {
F_61 ( V_261 ) ;
F_62 ( V_19 , V_261 ) ;
}
return V_31 ;
}
static void F_89 ( struct V_18 * V_19 )
{
struct V_29 * V_16 ;
int V_49 ;
for ( V_49 = V_65 ; V_49 < V_131 ; V_49 ++ ) {
V_16 = & V_19 -> V_16 [ V_49 ] ;
memset ( & V_16 -> V_35 , 0 , sizeof( V_16 -> V_35 ) ) ;
V_16 -> V_132 = 0 ;
V_16 -> V_276 = 0 ;
V_16 -> V_107 = 0 ;
memset ( & V_16 -> V_68 , 0 ,
sizeof( V_16 -> V_68 ) ) ;
F_22 ( & V_16 -> V_164 ) ;
F_22 ( & V_16 -> V_38 ) ;
V_16 -> V_19 = V_19 ;
}
F_22 ( & V_19 -> V_41 ) ;
}
int F_90 ( struct V_18 * V_19 ,
enum V_61 V_16 )
{
int V_278 ;
F_7 ( & V_19 -> V_168 ) ;
V_278 = F_16 ( & ( V_19 -> V_16 [ V_16 ] . V_164 ) ) ;
F_9 ( & V_19 -> V_168 ) ;
return V_278 ;
}
static void F_91 ( struct V_18 * V_19 )
{
V_19 -> V_93 = F_39 ( V_217 ,
V_19 -> V_93 ) ;
if ( F_92 ( V_19 -> V_43 -> V_44 ) ) {
V_19 -> V_93 = 0 ;
return;
}
V_19 -> V_93 = F_39 ( V_19 -> V_279 ,
V_19 -> V_93 ) ;
F_17 ( V_140 ,
L_71 ,
V_19 -> V_93 ) ;
V_19 -> V_231 = V_19 -> V_280 ;
V_19 -> V_84 = F_39 ( V_281 ,
V_19 -> V_280 ) ;
F_17 ( V_282 , L_72 ,
V_19 -> V_231 , V_19 -> V_84 ) ;
if ( V_19 -> V_84 )
V_19 -> V_98 = true ;
if ( V_19 -> V_231 )
V_19 -> V_241 = true ;
if ( ( V_19 -> V_63 % V_19 -> V_283 ) != 0 ) {
F_68 ( L_73 ,
V_19 -> V_63 ) ;
V_19 -> V_98 = false ;
}
}
int F_93 ( struct V_18 * V_19 )
{
struct V_4 * V_5 = NULL ;
struct V_284 * V_285 ;
struct V_257 V_286 ;
struct V_259 V_287 ;
int V_31 ;
V_5 = F_83 ( V_19 ) ;
if ( ! V_5 )
return - V_114 ;
V_285 = (struct V_284 * ) V_5 -> V_1 ;
if ( ( F_67 ( V_285 -> V_288 . V_119 ) != V_289 ) ||
( V_5 -> V_13 < sizeof( struct V_290 ) ) ) {
V_31 = - V_114 ;
goto V_291;
}
if ( ! V_285 -> V_288 . V_292 || ! V_285 -> V_288 . V_77 ) {
V_31 = - V_114 ;
goto V_291;
}
V_19 -> V_293 = F_67 ( V_285 -> V_288 . V_292 ) ;
V_19 -> V_63 = F_67 ( V_285 -> V_288 . V_77 ) ;
F_17 ( V_159 ,
L_74 ,
V_19 -> V_293 , V_19 -> V_63 ) ;
if ( V_5 -> V_13 >= sizeof( struct V_284 ) ) {
V_19 -> V_115 = V_285 -> V_294 ;
V_19 -> V_93 = V_285 -> V_295 ;
} else {
V_19 -> V_115 = V_296 ;
V_19 -> V_93 = 0 ;
}
F_17 ( V_140 , L_75 ,
( V_19 -> V_115 == V_296 ) ? L_76 : L_77 ,
V_19 -> V_115 ) ;
if ( V_19 -> V_93 > 0 )
F_91 ( V_19 ) ;
memset ( & V_286 , 0 , sizeof( V_286 ) ) ;
memset ( & V_287 , 0 , sizeof( V_287 ) ) ;
V_286 . V_105 . V_153 = F_70 ;
V_286 . V_105 . V_169 = NULL ;
V_286 . V_105 . V_108 = NULL ;
V_286 . V_107 = V_297 ;
V_286 . V_132 = V_268 ;
V_31 = F_88 ( ( void * ) V_19 , & V_286 , & V_287 ) ;
if ( V_31 )
F_94 ( V_19 -> V_43 -> V_44 ) ;
V_291:
if ( V_5 ) {
F_61 ( V_5 ) ;
F_62 ( V_19 , V_5 ) ;
}
return V_31 ;
}
int F_95 ( struct V_18 * V_19 )
{
struct V_4 * V_5 ;
int V_31 ;
F_96 ( V_19 -> V_43 ) ;
V_19 -> V_133 = 0 ;
V_19 -> V_179 = 0 ;
while ( ( V_5 = F_10 ( V_19 , false ) ) != NULL ) {
V_31 = F_58 ( V_19 , V_5 ) ;
if ( V_31 )
return V_31 ;
}
F_97 ( V_19 -> V_40 , & V_19 -> V_41 ,
V_19 -> V_293 ) ;
F_54 ( V_19 ) ;
V_31 = F_46 ( V_19 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_98 ( V_19 -> V_43 ) ;
if ( V_31 )
F_99 ( V_19 ) ;
return V_31 ;
}
void F_99 ( struct V_18 * V_19 )
{
F_7 ( & V_19 -> V_21 ) ;
V_19 -> V_133 |= V_134 ;
F_9 ( & V_19 -> V_21 ) ;
F_100 ( V_19 -> V_43 ) ;
F_53 ( V_19 ) ;
F_86 ( V_19 ) ;
F_89 ( V_19 ) ;
}
void * F_101 ( struct V_298 * V_44 )
{
struct V_18 * V_19 = NULL ;
struct V_4 * V_5 ;
int V_31 = 0 , V_49 = 0 ;
T_2 V_299 , V_300 ;
V_19 = F_102 ( sizeof( * V_19 ) , V_301 ) ;
if ( ! V_19 ) {
F_15 ( L_78 ) ;
return NULL ;
}
V_19 -> V_43 = F_102 ( sizeof( * V_19 -> V_43 ) , V_301 ) ;
if ( ! V_19 -> V_43 ) {
F_15 ( L_78 ) ;
V_31 = - V_114 ;
goto V_302;
}
F_103 ( & V_19 -> V_21 ) ;
F_103 ( & V_19 -> V_168 ) ;
F_103 ( & V_19 -> V_34 ) ;
F_22 ( & V_19 -> V_23 ) ;
F_22 ( & V_19 -> V_27 ) ;
F_22 ( & V_19 -> V_41 ) ;
V_19 -> V_43 -> V_44 = V_44 ;
V_19 -> V_43 -> V_303 = V_19 ;
V_19 -> V_181 = V_131 ;
F_89 ( V_19 ) ;
V_31 = F_104 ( V_19 -> V_43 ) ;
if ( V_31 )
goto V_302;
V_299 = V_44 -> V_56 . V_299 ;
V_300 = ( V_299 > V_269 ) ?
( V_299 + V_11 ) :
( V_269 + V_11 ) ;
for ( V_49 = 0 ; V_49 < V_297 ; V_49 ++ ) {
V_5 = F_102 ( sizeof( * V_5 ) , V_301 ) ;
if ( ! V_5 )
break;
V_5 -> V_28 = F_102 ( V_300 , V_301 ) ;
if ( ! V_5 -> V_28 ) {
F_105 ( V_5 ) ;
break;
}
V_5 -> V_158 = V_300 ;
if ( V_49 < V_304 ) {
V_5 -> V_13 = 0 ;
V_5 -> V_1 = V_5 -> V_28 ;
V_5 -> V_16 = V_65 ;
F_8 ( & V_5 -> V_22 , & V_19 -> V_27 ) ;
} else
F_8 ( & V_5 -> V_22 , & V_19 -> V_23 ) ;
}
V_302:
if ( V_49 != V_297 || V_31 ) {
if ( V_19 ) {
F_106 ( V_19 ) ;
V_19 = NULL ;
}
}
return V_19 ;
}
void F_106 ( struct V_18 * V_19 )
{
struct V_4 * V_5 , * V_305 ;
F_94 ( V_19 -> V_43 -> V_44 ) ;
F_52 (packet, tmp_packet,
&target->free_ctrl_txbuf, list) {
F_13 ( & V_5 -> V_22 ) ;
F_105 ( V_5 -> V_28 ) ;
F_105 ( V_5 ) ;
}
F_52 (packet, tmp_packet,
&target->free_ctrl_rxbuf, list) {
F_13 ( & V_5 -> V_22 ) ;
F_105 ( V_5 -> V_28 ) ;
F_105 ( V_5 ) ;
}
F_105 ( V_19 -> V_43 ) ;
F_105 ( V_19 ) ;
}
