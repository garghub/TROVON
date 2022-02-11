static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * * V_4 , * V_5 = NULL ;
T_1 V_6 = V_2 -> V_7 ;
V_4 = & V_2 -> V_8 -> V_9 . V_3 ;
while ( * V_4 ) {
struct V_1 * V_10 = F_2 ( * V_4 ,
struct V_1 , V_11 ) ;
V_5 = * V_4 ;
if ( V_10 -> V_7 > V_6 )
V_4 = & V_5 -> V_12 ;
else
V_4 = & V_5 -> V_13 ;
}
F_3 ( & V_2 -> V_11 , V_5 , V_4 ) ;
F_4 ( & V_2 -> V_11 , & V_2 -> V_8 -> V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_6 ( V_2 , struct V_14 , V_2 ) ;
static T_2 V_16 = F_7 ( 0 ) ;
F_8 ( & V_15 -> V_17 ) ;
while ( ! V_2 -> V_7 ) {
V_2 -> V_7 = F_9 ( & V_16 ) ;
if ( F_10 ( V_2 -> V_7 , V_2 -> V_8 ) )
V_2 -> V_7 = 0 ;
}
F_1 ( V_2 ) ;
V_2 -> V_8 -> V_18 ++ ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_6 ( V_2 , struct V_14 , V_2 ) ;
struct V_19 * V_8 = V_2 -> V_8 ;
F_12 ( & V_2 -> V_11 , & V_8 -> V_9 ) ;
V_8 -> V_18 -- ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = NULL ;
F_13 ( & V_15 -> V_17 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_19 * V_8 = V_2 -> V_8 ;
int V_20 = 0 ;
F_15 ( & V_8 -> V_21 ) ;
if ( V_2 -> V_7 ) {
V_20 = 1 ;
F_11 ( V_2 ) ;
}
F_16 ( & V_8 -> V_21 ) ;
if ( V_20 && ! V_8 -> V_18 )
F_17 ( & V_8 -> V_22 , V_23 ) ;
}
static void F_18 ( struct V_24 * V_25 )
{
struct V_19 * V_8 = F_6 ( F_19 ( V_25 ) ,
struct V_19 ,
V_22 ) ;
bool V_26 ;
F_20 ( & V_27 . V_28 ) ;
F_21 ( & V_8 -> V_21 ) ;
V_26 = F_22 ( & V_8 -> V_9 ) ;
F_23 ( & V_8 -> V_21 ) ;
if ( ! V_26 ) {
F_24 ( & V_27 . V_28 ) ;
return;
}
F_25 ( & V_8 -> V_29 ) ;
F_24 ( & V_27 . V_28 ) ;
F_26 ( V_8 ) ;
}
static int F_27 ( struct V_14 * V_15 , T_3 V_30 ,
struct V_31 * V_32 , T_4 V_33 ,
char * V_34 , unsigned short V_35 )
{
struct V_19 * V_8 ;
struct V_36 * V_37 ;
T_4 V_38 [ 3 ] ;
int V_39 = 0 ;
int V_40 ;
V_8 = F_28 ( sizeof( * V_8 ) , V_41 ) ;
if ( ! V_8 ) {
V_39 = - V_42 ;
goto V_43;
}
V_8 -> V_44 = V_15 -> V_45 ? V_46 : V_47 ;
V_8 -> V_48 = false ;
V_8 -> V_49 = V_30 ;
memcpy ( V_8 -> V_34 , V_34 , V_50 ) ;
V_8 -> V_35 = V_35 ;
F_29 ( & V_8 -> V_51 ) ;
F_29 ( & V_8 -> V_52 ) ;
for ( V_40 = 0 ; V_40 < V_53 ; V_40 ++ ) {
F_30 ( & V_8 -> V_54 [ V_40 ] ) ;
F_30 ( & V_8 -> V_55 [ V_40 ] ) ;
}
V_56 += V_57 ;
memcpy ( & V_8 -> V_58 , ( T_4 * ) & V_56 , V_59 ) ;
F_31 ( & V_8 -> V_22 , F_18 ) ;
V_8 -> V_9 = V_60 ;
V_37 = & V_8 -> V_37 [ V_61 ] ;
V_37 -> V_32 = V_32 ;
V_37 -> V_33 = V_33 ;
V_37 -> V_62 = V_32 -> V_63 [ V_33 - 1 ] . V_64 ;
if ( ! V_32 -> V_65 )
F_32 ( V_32 ) ;
F_33 ( V_38 , sizeof( V_38 ) ) ;
V_37 -> V_66 = V_38 [ 0 ] + ( V_38 [ 1 ] << 8 ) + ( V_38 [ 2 ] << 16 ) ;
V_39 = F_34 ( V_37 ) ;
if ( V_39 )
goto V_67;
F_35 ( & V_37 -> V_68 ) ;
V_39 = F_36 ( V_37 ) ;
if ( V_39 )
goto V_69;
V_39 = F_37 ( V_37 ) ;
if ( V_39 )
goto V_70;
V_39 = F_38 ( V_37 ) ;
if ( V_39 )
goto V_71;
F_39 ( & V_37 -> V_72 ) ;
F_39 ( & V_37 -> V_73 ) ;
V_15 -> V_2 . V_8 = V_8 ;
F_29 ( & V_8 -> V_21 ) ;
F_20 ( & V_27 . V_28 ) ;
F_40 ( & V_8 -> V_29 , & V_27 . V_29 ) ;
F_24 ( & V_27 . V_28 ) ;
return 0 ;
V_71:
F_41 ( V_37 ) ;
V_70:
F_42 ( V_37 ) ;
V_69:
F_43 ( V_37 ) ;
V_67:
F_44 ( V_8 ) ;
V_43:
return V_39 ;
}
static void F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_74 ) {
V_2 -> V_74 -> V_75 = 0 ;
V_2 -> V_76 = 0 ;
}
}
static void F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_77 ) {
V_2 -> V_77 -> V_75 = 0 ;
V_2 -> V_78 = 0 ;
}
}
void F_47 ( struct V_1 * V_2 )
{
struct V_19 * V_8 = V_2 -> V_8 ;
if ( ! V_8 )
return;
F_48 ( V_2 ) ;
F_14 ( V_2 ) ;
F_46 ( V_2 ) ;
F_45 ( V_2 ) ;
}
static void F_49 ( struct V_36 * V_37 )
{
V_37 -> V_79 = 0 ;
F_50 ( V_37 ) ;
F_51 ( V_37 ) ;
F_41 ( V_37 ) ;
F_42 ( V_37 ) ;
F_43 ( V_37 ) ;
}
static void F_52 ( struct V_19 * V_8 )
{
struct V_80 * V_74 , * V_81 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_53 ; V_40 ++ ) {
F_53 (sndbuf_desc, bf_desc, &lgr->sndbufs[i],
list) {
F_54 ( & V_74 -> V_29 ) ;
F_55 ( V_8 -> V_37 [ V_61 ] . V_32 ,
F_56 ( V_40 ) ,
V_74 , V_82 ) ;
F_44 ( V_74 -> V_83 ) ;
F_44 ( V_74 ) ;
}
}
}
static void F_57 ( struct V_19 * V_8 )
{
struct V_80 * V_77 , * V_81 ;
struct V_36 * V_37 = & V_8 -> V_37 [ V_61 ] ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_53 ; V_40 ++ ) {
F_53 (rmb_desc, bf_desc, &lgr->rmbs[i],
list) {
F_54 ( & V_77 -> V_29 ) ;
F_55 ( V_37 -> V_32 ,
F_56 ( V_40 ) ,
V_77 , V_84 ) ;
F_44 ( V_77 -> V_83 ) ;
F_44 ( V_77 ) ;
}
}
}
void F_26 ( struct V_19 * V_8 )
{
F_57 ( V_8 ) ;
F_52 ( V_8 ) ;
F_49 ( & V_8 -> V_37 [ V_61 ] ) ;
F_44 ( V_8 ) ;
}
void F_58 ( struct V_19 * V_8 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
struct V_3 * V_85 ;
F_20 ( & V_27 . V_28 ) ;
if ( F_59 ( & V_8 -> V_29 ) ) {
F_24 ( & V_27 . V_28 ) ;
return;
}
F_25 ( & V_8 -> V_29 ) ;
F_24 ( & V_27 . V_28 ) ;
F_15 ( & V_8 -> V_21 ) ;
V_85 = F_60 ( & V_8 -> V_9 ) ;
while ( V_85 ) {
V_2 = F_2 ( V_85 , struct V_1 , V_11 ) ;
V_15 = F_6 ( V_2 , struct V_14 , V_2 ) ;
F_8 ( & V_15 -> V_17 ) ;
F_11 ( V_2 ) ;
F_61 ( & V_2 -> V_86 ) ;
F_13 ( & V_15 -> V_17 ) ;
V_85 = F_60 ( & V_8 -> V_9 ) ;
}
F_16 ( & V_8 -> V_21 ) ;
}
static int F_62 ( struct V_87 * V_88 , unsigned short * V_35 )
{
struct V_89 * V_90 = F_63 ( V_88 -> V_17 ) ;
int V_39 = 0 ;
* V_35 = 0 ;
if ( ! V_90 ) {
V_39 = - V_91 ;
goto V_43;
}
if ( ! V_90 -> V_92 ) {
V_39 = - V_93 ;
goto V_94;
}
if ( F_64 ( V_90 -> V_92 ) )
* V_35 = F_65 ( V_90 -> V_92 ) ;
V_94:
F_66 ( V_90 ) ;
V_43:
return V_39 ;
}
static int F_67 ( struct V_19 * V_8 )
{
struct V_36 * V_37 = & V_8 -> V_37 [ V_61 ] ;
struct V_95 V_96 ;
union V_97 V_98 ;
int V_40 ;
if ( ! V_8 -> V_35 ) {
V_37 -> V_98 = V_37 -> V_32 -> V_98 [ V_37 -> V_33 - 1 ] ;
return 0 ;
}
for ( V_40 = 0 ; V_40 < V_37 -> V_32 -> V_63 [ V_37 -> V_33 - 1 ] . V_99 ;
V_40 ++ ) {
if ( F_68 ( V_37 -> V_32 -> V_100 , V_37 -> V_33 , V_40 , & V_98 ,
& V_96 ) )
continue;
if ( V_96 . V_101 &&
( F_65 ( V_96 . V_101 ) == V_8 -> V_35 ) ) {
V_37 -> V_98 = V_98 ;
return 0 ;
}
}
return - V_93 ;
}
int F_69 ( struct V_14 * V_15 , T_3 V_30 ,
struct V_31 * V_32 , T_4 V_33 ,
struct V_102 * V_103 , int V_104 )
{
struct V_1 * V_2 = & V_15 -> V_2 ;
struct V_19 * V_8 ;
unsigned short V_35 ;
enum V_105 V_44 ;
int V_106 = V_107 ;
int V_39 = 0 ;
V_44 = V_15 -> V_45 ? V_46 : V_47 ;
V_39 = F_62 ( V_15 -> V_88 , & V_35 ) ;
if ( V_39 )
return V_39 ;
if ( ( V_44 == V_47 ) && V_104 )
goto V_108;
F_20 ( & V_27 . V_28 ) ;
F_70 (lgr, &smc_lgr_list.list, list) {
F_15 ( & V_8 -> V_21 ) ;
if ( ! memcmp ( V_8 -> V_34 , V_103 -> V_109 ,
V_50 ) &&
! memcmp ( V_8 -> V_37 [ V_61 ] . V_110 , & V_103 -> V_98 ,
V_111 ) &&
! memcmp ( V_8 -> V_37 [ V_61 ] . V_112 , V_103 -> V_113 ,
sizeof( V_103 -> V_113 ) ) &&
! V_8 -> V_48 &&
( V_8 -> V_44 == V_44 ) &&
( V_8 -> V_35 == V_35 ) &&
( ( V_44 == V_47 ) ||
( V_8 -> V_18 < V_114 ) ) ) {
V_106 = V_115 ;
V_2 -> V_8 = V_8 ;
F_5 ( V_2 ) ;
F_16 ( & V_8 -> V_21 ) ;
break;
}
F_16 ( & V_8 -> V_21 ) ;
}
F_24 ( & V_27 . V_28 ) ;
if ( V_44 == V_47 && ! V_104 &&
( V_106 == V_107 ) ) {
return - V_116 ;
}
V_108:
if ( V_106 == V_107 ) {
V_39 = F_27 ( V_15 , V_30 , V_32 , V_33 ,
V_103 -> V_109 , V_35 ) ;
if ( V_39 )
goto V_43;
F_5 ( V_2 ) ;
V_39 = F_67 ( V_2 -> V_8 ) ;
}
V_2 -> V_117 . V_118 . type = V_119 ;
V_2 -> V_117 . V_120 = sizeof( struct V_121 ) ;
#ifndef F_71
F_72 ( & V_2 -> V_122 ) ;
#endif
V_43:
return V_39 ? V_39 : V_106 ;
}
static inline
struct V_80 * F_73 ( struct V_19 * V_8 ,
int V_123 )
{
struct V_80 * V_124 ;
F_21 ( & V_8 -> V_51 ) ;
F_70 (sndbuf_slot, &lgr->sndbufs[compressed_bufsize],
list) {
if ( F_74 ( & V_124 -> V_75 , 0 , 1 ) == 0 ) {
F_23 ( & V_8 -> V_51 ) ;
return V_124 ;
}
}
F_23 ( & V_8 -> V_51 ) ;
return NULL ;
}
static inline
struct V_80 * F_75 ( struct V_19 * V_8 ,
int V_123 )
{
struct V_80 * V_125 ;
F_21 ( & V_8 -> V_52 ) ;
F_70 (rmb_slot, &lgr->rmbs[compressed_bufsize],
list) {
if ( F_74 ( & V_125 -> V_75 , 0 , 1 ) == 0 ) {
F_23 ( & V_8 -> V_52 ) ;
return V_125 ;
}
}
F_23 ( & V_8 -> V_52 ) ;
return NULL ;
}
static inline int F_76 ( int V_78 )
{
return F_77 ( int , V_78 / 10 , V_126 / 2 ) ;
}
int F_78 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = & V_15 -> V_2 ;
struct V_19 * V_8 = V_2 -> V_8 ;
int V_127 , V_128 ;
struct V_80 * V_74 ;
int V_39 ;
for ( V_128 = F_79 ( V_15 -> V_17 . V_129 / 2 ) ;
V_128 >= 0 ; V_128 -- ) {
V_127 = F_56 ( V_128 ) ;
V_74 = F_73 ( V_8 , V_128 ) ;
if ( V_74 ) {
memset ( V_74 -> V_83 , 0 , V_127 ) ;
break;
}
V_74 = F_28 ( sizeof( * V_74 ) , V_41 ) ;
if ( ! V_74 )
break;
V_74 -> V_83 = F_28 ( V_127 ,
V_41 | V_130 |
V_131 |
V_132 ) ;
if ( ! V_74 -> V_83 ) {
F_44 ( V_74 ) ;
V_74 = NULL ;
continue;
}
V_39 = F_80 ( V_8 -> V_37 [ V_61 ] . V_32 ,
V_127 , V_74 ,
V_82 ) ;
if ( V_39 ) {
F_44 ( V_74 -> V_83 ) ;
F_44 ( V_74 ) ;
V_74 = NULL ;
continue;
}
V_74 -> V_75 = 1 ;
F_15 ( & V_8 -> V_51 ) ;
F_40 ( & V_74 -> V_29 ,
& V_8 -> V_54 [ V_128 ] ) ;
F_16 ( & V_8 -> V_51 ) ;
break;
}
if ( V_74 && V_74 -> V_83 ) {
V_2 -> V_74 = V_74 ;
V_2 -> V_76 = V_127 ;
V_15 -> V_17 . V_129 = V_127 * 2 ;
F_81 ( & V_2 -> V_133 , V_127 ) ;
return 0 ;
} else {
return - V_42 ;
}
}
int F_82 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = & V_15 -> V_2 ;
struct V_19 * V_8 = V_2 -> V_8 ;
int V_127 , V_128 ;
struct V_80 * V_77 ;
int V_39 ;
for ( V_128 = F_79 ( V_15 -> V_17 . V_134 / 2 ) ;
V_128 >= 0 ; V_128 -- ) {
V_127 = F_56 ( V_128 ) ;
V_77 = F_75 ( V_8 , V_128 ) ;
if ( V_77 ) {
memset ( V_77 -> V_83 , 0 , V_127 ) ;
break;
}
V_77 = F_28 ( sizeof( * V_77 ) , V_41 ) ;
if ( ! V_77 )
break;
V_77 -> V_83 = F_28 ( V_127 ,
V_41 | V_130 |
V_131 |
V_132 ) ;
if ( ! V_77 -> V_83 ) {
F_44 ( V_77 ) ;
V_77 = NULL ;
continue;
}
V_39 = F_80 ( V_8 -> V_37 [ V_61 ] . V_32 ,
V_127 , V_77 ,
V_84 ) ;
if ( V_39 ) {
F_44 ( V_77 -> V_83 ) ;
F_44 ( V_77 ) ;
V_77 = NULL ;
continue;
}
V_77 -> V_135 [ V_61 ] =
V_8 -> V_37 [ V_61 ] . V_136 -> V_137 ;
V_77 -> V_75 = 1 ;
F_15 ( & V_8 -> V_52 ) ;
F_40 ( & V_77 -> V_29 ,
& V_8 -> V_55 [ V_128 ] ) ;
F_16 ( & V_8 -> V_52 ) ;
break;
}
if ( V_77 && V_77 -> V_83 ) {
V_2 -> V_77 = V_77 ;
V_2 -> V_78 = V_127 ;
V_2 -> V_138 = V_128 ;
V_15 -> V_17 . V_134 = V_127 * 2 ;
F_81 ( & V_2 -> V_139 , 0 ) ;
V_2 -> V_140 = F_76 ( V_127 ) ;
return 0 ;
} else {
return - V_42 ;
}
}
static inline int F_83 ( struct V_19 * V_8 )
{
int V_40 ;
F_84 (i, lgr->rtokens_used_mask, SMC_RMBS_PER_LGR_MAX) {
if ( ! F_85 ( V_40 , V_8 -> V_141 ) )
return V_40 ;
}
return - V_142 ;
}
int F_86 ( struct V_1 * V_2 ,
struct V_143 * V_144 )
{
T_5 V_145 = F_87 ( V_144 -> V_146 ) ;
struct V_19 * V_8 = V_2 -> V_8 ;
T_1 V_135 = F_88 ( V_144 -> V_147 ) ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_114 ; V_40 ++ ) {
if ( ( V_8 -> V_148 [ V_40 ] [ V_61 ] . V_135 == V_135 ) &&
( V_8 -> V_148 [ V_40 ] [ V_61 ] . V_145 == V_145 ) &&
F_89 ( V_40 , V_8 -> V_141 ) ) {
V_2 -> V_149 = V_40 ;
return 0 ;
}
}
V_2 -> V_149 = F_83 ( V_8 ) ;
if ( V_2 -> V_149 < 0 )
return V_2 -> V_149 ;
V_8 -> V_148 [ V_2 -> V_149 ] [ V_61 ] . V_135 = V_135 ;
V_8 -> V_148 [ V_2 -> V_149 ] [ V_61 ] . V_145 = V_145 ;
return 0 ;
}
