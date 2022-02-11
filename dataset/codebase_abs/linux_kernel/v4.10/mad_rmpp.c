static inline void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_3 ) )
F_3 ( & V_2 -> V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_5 ( & V_2 -> V_4 ) ;
F_6 ( V_2 -> V_5 ) ;
F_7 ( V_2 ) ;
}
void F_8 ( struct V_6 * V_7 )
{
struct V_1 * V_2 , * V_8 ;
unsigned long V_9 ;
F_9 ( & V_7 -> V_10 , V_9 ) ;
F_10 (rmpp_recv, &agent->rmpp_list, list) {
if ( V_2 -> V_11 != V_12 )
F_11 ( V_2 -> V_13 ) ;
V_2 -> V_11 = V_14 ;
}
F_12 ( & V_7 -> V_10 , V_9 ) ;
F_10 (rmpp_recv, &agent->rmpp_list, list) {
F_13 ( & V_2 -> V_15 ) ;
F_13 ( & V_2 -> V_16 ) ;
}
F_14 ( V_7 -> V_17 -> V_18 -> V_19 ) ;
F_15 (rmpp_recv, temp_rmpp_recv,
&agent->rmpp_list, list) {
F_16 ( & V_2 -> V_20 ) ;
F_4 ( V_2 ) ;
}
}
static void F_17 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_23 * V_25 = V_22 -> V_26 ;
unsigned long V_9 ;
memcpy ( V_25 , & V_24 -> V_27 , V_22 -> V_28 ) ;
V_25 -> V_27 . V_29 ^= V_30 ;
V_25 -> V_31 . V_32 = V_33 ;
F_18 ( & V_25 -> V_31 , V_34 ) ;
F_9 ( & V_2 -> V_10 , V_9 ) ;
V_2 -> V_35 = V_2 -> V_36 ;
V_25 -> V_31 . V_36 = F_19 ( V_2 -> V_36 ) ;
V_25 -> V_31 . V_37 = F_19 ( V_2 -> V_38 ) ;
F_12 ( & V_2 -> V_10 , V_9 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_21 * V_22 ;
int V_41 , V_28 ;
V_28 = F_21 ( V_40 -> V_42 . V_26 -> V_27 . V_43 ) ;
V_22 = F_22 ( & V_2 -> V_7 -> V_7 , V_40 -> V_44 -> V_45 ,
V_40 -> V_44 -> V_46 , 1 , V_28 ,
0 , V_47 ,
V_48 ) ;
if ( F_23 ( V_22 ) )
return;
F_17 ( V_22 , (struct V_23 * ) V_40 -> V_42 . V_26 , V_2 ) ;
V_22 -> V_5 = V_2 -> V_5 ;
V_41 = F_24 ( V_22 , NULL ) ;
if ( V_41 )
F_25 ( V_22 ) ;
}
static struct V_21 * F_26 ( struct V_49 * V_7 ,
struct V_39 * V_40 )
{
struct V_21 * V_22 ;
struct V_50 * V_5 ;
int V_28 ;
V_5 = F_27 ( V_7 -> V_51 -> V_52 , V_40 -> V_44 ,
V_40 -> V_42 . V_53 , V_7 -> V_54 ) ;
if ( F_23 ( V_5 ) )
return ( void * ) V_5 ;
V_28 = F_21 ( V_40 -> V_42 . V_26 -> V_27 . V_43 ) ;
V_22 = F_22 ( V_7 , V_40 -> V_44 -> V_45 ,
V_40 -> V_44 -> V_46 , 1 ,
V_28 , 0 , V_47 ,
V_48 ) ;
if ( F_23 ( V_22 ) )
F_6 ( V_5 ) ;
else {
V_22 -> V_5 = V_5 ;
V_22 -> V_55 [ 0 ] = V_5 ;
}
return V_22 ;
}
static void F_28 ( struct V_6 * V_7 ,
struct V_39 * V_40 )
{
struct V_21 * V_22 ;
struct V_23 * V_56 ;
int V_41 ;
V_22 = F_26 ( & V_7 -> V_7 , V_40 ) ;
if ( F_23 ( V_22 ) )
return;
V_56 = V_22 -> V_26 ;
memcpy ( V_56 , V_40 -> V_42 . V_26 , V_22 -> V_28 ) ;
V_56 -> V_27 . V_29 ^= V_30 ;
F_18 ( & V_56 -> V_31 , V_34 ) ;
V_56 -> V_31 . V_36 = 0 ;
V_56 -> V_31 . V_37 = F_19 ( 1 ) ;
V_41 = F_24 ( V_22 , NULL ) ;
if ( V_41 ) {
F_6 ( V_22 -> V_5 ) ;
F_25 ( V_22 ) ;
}
}
void F_29 ( struct V_57 * V_58 )
{
if ( V_58 -> V_59 -> V_55 [ 0 ] == V_58 -> V_59 -> V_5 )
F_6 ( V_58 -> V_59 -> V_5 ) ;
F_25 ( V_58 -> V_59 ) ;
}
static void F_30 ( struct V_6 * V_7 ,
struct V_39 * V_40 , T_1 V_60 )
{
struct V_21 * V_22 ;
struct V_23 * V_56 ;
int V_41 ;
V_22 = F_26 ( & V_7 -> V_7 , V_40 ) ;
if ( F_23 ( V_22 ) )
return;
V_56 = V_22 -> V_26 ;
memcpy ( V_56 , V_40 -> V_42 . V_26 , V_22 -> V_28 ) ;
V_56 -> V_27 . V_29 ^= V_30 ;
V_56 -> V_31 . V_61 = V_62 ;
V_56 -> V_31 . V_32 = V_63 ;
F_18 ( & V_56 -> V_31 , V_34 ) ;
V_56 -> V_31 . V_60 = V_60 ;
V_56 -> V_31 . V_36 = 0 ;
V_56 -> V_31 . V_37 = 0 ;
V_41 = F_24 ( V_22 , NULL ) ;
if ( V_41 ) {
F_6 ( V_22 -> V_5 ) ;
F_25 ( V_22 ) ;
}
}
static void F_31 ( struct V_64 * V_65 )
{
struct V_1 * V_2 =
F_32 ( V_65 , struct V_1 , V_15 . V_65 ) ;
struct V_39 * V_13 ;
unsigned long V_9 ;
F_9 ( & V_2 -> V_7 -> V_10 , V_9 ) ;
if ( V_2 -> V_11 != V_66 ) {
F_12 ( & V_2 -> V_7 -> V_10 , V_9 ) ;
return;
}
V_2 -> V_11 = V_67 ;
F_16 ( & V_2 -> V_20 ) ;
F_12 ( & V_2 -> V_7 -> V_10 , V_9 ) ;
V_13 = V_2 -> V_13 ;
F_30 ( V_2 -> V_7 , V_13 , V_68 ) ;
F_4 ( V_2 ) ;
F_11 ( V_13 ) ;
}
static void F_33 ( struct V_64 * V_65 )
{
struct V_1 * V_2 =
F_32 ( V_65 , struct V_1 , V_16 . V_65 ) ;
unsigned long V_9 ;
F_9 ( & V_2 -> V_7 -> V_10 , V_9 ) ;
if ( V_2 -> V_11 == V_14 ) {
F_12 ( & V_2 -> V_7 -> V_10 , V_9 ) ;
return;
}
F_16 ( & V_2 -> V_20 ) ;
F_12 ( & V_2 -> V_7 -> V_10 , V_9 ) ;
F_4 ( V_2 ) ;
}
static struct V_1 *
F_34 ( struct V_6 * V_7 ,
struct V_39 * V_69 )
{
struct V_1 * V_2 ;
struct V_70 * V_27 ;
V_2 = F_35 ( sizeof *V_2 , V_47 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_5 = F_27 ( V_7 -> V_7 . V_51 -> V_52 ,
V_69 -> V_44 ,
V_69 -> V_42 . V_53 ,
V_7 -> V_7 . V_54 ) ;
if ( F_23 ( V_2 -> V_5 ) )
goto error;
V_2 -> V_7 = V_7 ;
F_36 ( & V_2 -> V_4 ) ;
F_37 ( & V_2 -> V_15 , F_31 ) ;
F_37 ( & V_2 -> V_16 , F_33 ) ;
F_38 ( & V_2 -> V_10 ) ;
V_2 -> V_11 = V_66 ;
F_39 ( & V_2 -> V_3 , 1 ) ;
V_2 -> V_13 = V_69 ;
V_2 -> V_71 = & V_69 -> V_42 ;
V_2 -> V_38 = 1 ;
V_2 -> V_36 = 1 ;
V_2 -> V_35 = 0 ;
V_2 -> V_72 = 1 ;
V_27 = & V_69 -> V_42 . V_26 -> V_27 ;
V_2 -> V_73 = V_27 -> V_73 ;
V_2 -> V_45 = V_69 -> V_44 -> V_45 ;
V_2 -> V_74 = V_69 -> V_44 -> V_74 ;
V_2 -> V_43 = V_27 -> V_43 ;
V_2 -> V_75 = V_27 -> V_75 ;
V_2 -> V_29 = V_27 -> V_29 ;
V_2 -> V_76 = V_27 -> V_76 ;
return V_2 ;
error: F_7 ( V_2 ) ;
return NULL ;
}
static struct V_1 *
F_40 ( struct V_6 * V_7 ,
struct V_39 * V_69 )
{
struct V_1 * V_2 ;
struct V_70 * V_27 = & V_69 -> V_42 . V_26 -> V_27 ;
F_10 (rmpp_recv, &agent->rmpp_list, list) {
if ( V_2 -> V_73 == V_27 -> V_73 &&
V_2 -> V_45 == V_69 -> V_44 -> V_45 &&
V_2 -> V_74 == V_69 -> V_44 -> V_74 &&
V_2 -> V_43 == V_27 -> V_43 &&
V_2 -> V_75 == V_27 -> V_75 &&
V_2 -> V_29 == V_27 -> V_29 )
return V_2 ;
}
return NULL ;
}
static struct V_1 *
F_41 ( struct V_6 * V_7 ,
struct V_39 * V_69 )
{
struct V_1 * V_2 ;
unsigned long V_9 ;
F_9 ( & V_7 -> V_10 , V_9 ) ;
V_2 = F_40 ( V_7 , V_69 ) ;
if ( V_2 )
F_42 ( & V_2 -> V_3 ) ;
F_12 ( & V_7 -> V_10 , V_9 ) ;
return V_2 ;
}
static struct V_1 *
F_43 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
struct V_1 * V_77 ;
V_77 = F_40 ( V_7 , V_2 -> V_13 ) ;
if ( ! V_77 )
F_44 ( & V_2 -> V_20 , & V_7 -> V_78 ) ;
return V_77 ;
}
static inline int F_45 ( struct V_79 * V_80 )
{
struct V_23 * V_56 ;
V_56 = (struct V_23 * ) V_80 -> V_26 ;
return F_46 ( & V_56 -> V_31 ) & V_81 ;
}
static inline int F_47 ( struct V_79 * V_80 )
{
struct V_23 * V_56 ;
V_56 = (struct V_23 * ) V_80 -> V_26 ;
return F_48 ( V_56 -> V_31 . V_36 ) ;
}
static inline struct V_79 * F_49 ( struct V_82 * V_78 ,
struct V_79 * V_80 )
{
if ( V_80 -> V_20 . V_83 == V_78 )
return NULL ;
return F_32 ( V_80 -> V_20 . V_83 , struct V_79 , V_20 ) ;
}
static inline int F_50 ( struct V_6 * V_7 )
{
return F_51 ( V_7 -> V_17 -> V_84 . V_85 >> 3 , 1 ) ;
}
static struct V_79 * F_52 ( struct V_82 * V_78 ,
int V_36 )
{
struct V_79 * V_86 ;
int V_87 ;
F_53 (seg_buf, rmpp_list, list) {
V_87 = F_47 ( V_86 ) ;
if ( V_36 > V_87 )
return V_86 ;
if ( V_36 == V_87 )
break;
}
return NULL ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_79 * V_88 )
{
struct V_82 * V_78 = & V_2 -> V_13 -> V_78 ;
while ( V_88 && ( F_47 ( V_88 ) == V_2 -> V_36 + 1 ) ) {
V_2 -> V_71 = V_88 ;
V_2 -> V_36 ++ ;
V_88 = F_49 ( V_78 , V_88 ) ;
}
}
static inline int F_55 ( struct V_1 * V_2 )
{
struct V_23 * V_56 ;
int V_89 , V_90 , V_91 ;
bool V_92 = F_56 ( V_2 -> V_7 -> V_17 -> V_18 -> V_93 ,
V_2 -> V_7 -> V_17 -> V_18 -> V_54 ) ;
V_56 = (struct V_23 * ) V_2 -> V_71 -> V_26 ;
V_89 = F_21 ( V_56 -> V_27 . V_43 ) ;
if ( V_92 && V_2 -> V_76 == V_94 ) {
V_90 = sizeof( struct V_95 ) - V_89 ;
V_91 = V_96 - F_48 ( V_56 -> V_31 . V_37 ) ;
if ( V_91 > V_96 || V_91 < 0 )
V_91 = 0 ;
} else {
V_90 = sizeof( struct V_23 ) - V_89 ;
V_91 = V_97 - F_48 ( V_56 -> V_31 . V_37 ) ;
if ( V_91 > V_97 || V_91 < 0 )
V_91 = 0 ;
}
return V_89 + V_2 -> V_36 * V_90 - V_91 ;
}
static struct V_39 * F_57 ( struct V_1 * V_2 )
{
struct V_39 * V_13 ;
F_20 ( V_2 , V_2 -> V_13 ) ;
if ( V_2 -> V_36 > 1 )
F_13 ( & V_2 -> V_15 ) ;
V_13 = V_2 -> V_13 ;
V_13 -> V_98 = F_55 ( V_2 ) ;
F_58 ( V_2 -> V_7 -> V_17 -> V_18 -> V_19 ,
& V_2 -> V_16 , F_59 ( 10000 ) ) ;
return V_13 ;
}
static struct V_39 *
F_60 ( struct V_6 * V_7 ,
struct V_39 * V_69 )
{
struct V_1 * V_2 ;
struct V_79 * V_99 ;
struct V_39 * V_100 ;
int V_36 ;
unsigned long V_9 ;
V_2 = F_41 ( V_7 , V_69 ) ;
if ( ! V_2 )
goto V_101;
V_36 = F_47 ( & V_69 -> V_42 ) ;
F_9 ( & V_2 -> V_10 , V_9 ) ;
if ( ( V_2 -> V_11 == V_67 ) ||
( V_36 > V_2 -> V_38 ) )
goto V_102;
if ( ( V_36 <= V_2 -> V_35 ) ||
( V_2 -> V_11 == V_12 ) ) {
F_12 ( & V_2 -> V_10 , V_9 ) ;
F_20 ( V_2 , V_69 ) ;
goto V_103;
}
V_99 = F_52 ( & V_2 -> V_13 -> V_78 , V_36 ) ;
if ( ! V_99 )
goto V_102;
V_100 = NULL ;
F_61 ( & V_69 -> V_42 . V_20 , & V_99 -> V_20 ) ;
if ( V_2 -> V_71 == V_99 ) {
F_54 ( V_2 , & V_69 -> V_42 ) ;
if ( F_45 ( V_2 -> V_71 ) ) {
V_2 -> V_11 = V_12 ;
F_12 ( & V_2 -> V_10 , V_9 ) ;
V_100 = F_57 ( V_2 ) ;
goto V_104;
} else if ( V_2 -> V_36 == V_2 -> V_38 ) {
V_2 -> V_38 += F_50 ( V_7 ) ;
F_12 ( & V_2 -> V_10 , V_9 ) ;
F_20 ( V_2 , V_69 ) ;
goto V_104;
}
}
F_12 ( & V_2 -> V_10 , V_9 ) ;
V_104:
F_1 ( V_2 ) ;
return V_100 ;
V_102: F_12 ( & V_2 -> V_10 , V_9 ) ;
V_103: F_1 ( V_2 ) ;
V_101: F_11 ( V_69 ) ;
return NULL ;
}
static struct V_39 *
F_62 ( struct V_6 * V_7 ,
struct V_39 * V_69 )
{
struct V_1 * V_2 ;
unsigned long V_9 ;
V_2 = F_34 ( V_7 , V_69 ) ;
if ( ! V_2 ) {
F_11 ( V_69 ) ;
return NULL ;
}
F_9 ( & V_7 -> V_10 , V_9 ) ;
if ( F_43 ( V_7 , V_2 ) ) {
F_12 ( & V_7 -> V_10 , V_9 ) ;
F_4 ( V_2 ) ;
return F_60 ( V_7 , V_69 ) ;
}
F_42 ( & V_2 -> V_3 ) ;
if ( F_45 ( & V_69 -> V_42 ) ) {
V_2 -> V_11 = V_12 ;
F_12 ( & V_7 -> V_10 , V_9 ) ;
F_57 ( V_2 ) ;
} else {
F_12 ( & V_7 -> V_10 , V_9 ) ;
F_58 ( V_7 -> V_17 -> V_18 -> V_19 ,
& V_2 -> V_15 ,
F_59 ( 40000 ) ) ;
V_2 -> V_38 += F_50 ( V_7 ) ;
F_20 ( V_2 , V_69 ) ;
V_69 = NULL ;
}
F_1 ( V_2 ) ;
return V_69 ;
}
static int F_63 ( struct V_105 * V_106 )
{
struct V_23 * V_56 ;
int V_107 ;
T_2 V_108 = 0 ;
V_56 = V_106 -> V_59 . V_26 ;
F_18 ( & V_56 -> V_31 , V_34 ) ;
V_56 -> V_31 . V_36 = F_19 ( ++ V_106 -> V_36 ) ;
if ( V_106 -> V_36 == 1 ) {
V_56 -> V_31 . V_109 |= V_110 ;
V_108 = ( V_106 -> V_59 . V_111 *
V_106 -> V_59 . V_112 ) -
V_106 -> V_91 ;
}
if ( V_106 -> V_36 == V_106 -> V_59 . V_111 ) {
V_56 -> V_31 . V_109 |= V_81 ;
V_108 = V_106 -> V_59 . V_112 - V_106 -> V_91 ;
}
V_56 -> V_31 . V_37 = F_19 ( V_108 ) ;
V_107 = V_106 -> V_59 . V_113 ;
if ( ! V_107 || V_107 > 2000 )
V_106 -> V_107 = F_59 ( 2000 ) ;
return F_64 ( V_106 ) ;
}
static void F_65 ( struct V_6 * V_7 ,
struct V_39 * V_69 , T_1 V_60 )
{
struct V_105 * V_106 ;
struct V_57 V_44 ;
unsigned long V_9 ;
F_9 ( & V_7 -> V_10 , V_9 ) ;
V_106 = F_66 ( V_7 , V_69 ) ;
if ( ! V_106 )
goto V_104;
if ( ( V_106 -> V_35 == V_106 -> V_59 . V_111 ) ||
( ! V_106 -> V_107 ) || ( V_106 -> V_114 != V_115 ) )
goto V_104;
F_67 ( V_106 ) ;
F_12 ( & V_7 -> V_10 , V_9 ) ;
V_44 . V_114 = V_116 ;
V_44 . V_117 = V_60 ;
V_44 . V_59 = & V_106 -> V_59 ;
F_68 ( V_106 , & V_44 ) ;
return;
V_104:
F_12 ( & V_7 -> V_10 , V_9 ) ;
}
static inline void F_69 ( struct V_105 * V_118 ,
int V_36 )
{
struct V_82 * V_20 ;
V_118 -> V_35 = V_36 ;
V_20 = & V_118 -> V_119 -> V_20 ;
F_10 (wr->last_ack_seg, list, list)
if ( V_118 -> V_119 -> V_120 == V_36 )
break;
}
static void F_70 ( struct V_6 * V_7 ,
struct V_39 * V_69 , int V_38 )
{
struct V_1 * V_2 ;
V_2 = F_40 ( V_7 , V_69 ) ;
if ( V_2 && V_2 -> V_11 == V_12 )
V_2 -> V_72 = V_38 ;
}
static void F_71 ( struct V_6 * V_7 ,
struct V_39 * V_69 )
{
struct V_105 * V_106 ;
struct V_23 * V_56 ;
unsigned long V_9 ;
int V_36 , V_38 , V_41 ;
V_56 = (struct V_23 * ) V_69 -> V_42 . V_26 ;
if ( V_56 -> V_31 . V_60 ) {
F_65 ( V_7 , V_69 , V_121 ) ;
F_30 ( V_7 , V_69 , V_121 ) ;
return;
}
V_36 = F_48 ( V_56 -> V_31 . V_36 ) ;
V_38 = F_48 ( V_56 -> V_31 . V_37 ) ;
if ( V_38 < V_36 ) {
F_65 ( V_7 , V_69 , V_122 ) ;
F_30 ( V_7 , V_69 , V_122 ) ;
return;
}
F_9 ( & V_7 -> V_10 , V_9 ) ;
V_106 = F_66 ( V_7 , V_69 ) ;
if ( ! V_106 ) {
if ( ! V_36 )
F_70 ( V_7 , V_69 , V_38 ) ;
goto V_104;
}
if ( ( V_106 -> V_35 == V_106 -> V_59 . V_111 ) &&
( V_106 -> V_107 ) ) {
F_12 ( & V_7 -> V_10 , V_9 ) ;
F_28 ( V_7 , V_69 ) ;
return;
}
if ( ( V_106 -> V_35 == V_106 -> V_59 . V_111 ) ||
( ! V_106 -> V_107 ) || ( V_106 -> V_114 != V_115 ) )
goto V_104;
if ( V_36 > V_106 -> V_59 . V_111 ||
V_36 > V_106 -> V_38 ) {
F_12 ( & V_7 -> V_10 , V_9 ) ;
F_65 ( V_7 , V_69 , V_123 ) ;
F_30 ( V_7 , V_69 , V_123 ) ;
return;
}
if ( V_38 < V_106 -> V_38 || V_36 < V_106 -> V_35 )
goto V_104;
if ( V_36 > V_106 -> V_35 ) {
F_69 ( V_106 , V_36 ) ;
V_106 -> V_124 = V_106 -> V_125 ;
}
V_106 -> V_38 = V_38 ;
if ( V_106 -> V_35 == V_106 -> V_59 . V_111 ) {
if ( ! V_106 -> V_59 . V_113 ) {
struct V_57 V_44 ;
F_67 ( V_106 ) ;
F_12 ( & V_7 -> V_10 , V_9 ) ;
V_44 . V_114 = V_115 ;
V_44 . V_117 = 0 ;
V_44 . V_59 = & V_106 -> V_59 ;
F_68 ( V_106 , & V_44 ) ;
return;
}
if ( V_106 -> V_3 == 1 )
F_72 ( V_106 ,
V_106 -> V_59 . V_113 ) ;
F_12 ( & V_7 -> V_10 , V_9 ) ;
F_28 ( V_7 , V_69 ) ;
return;
} else if ( V_106 -> V_3 == 1 &&
V_106 -> V_36 < V_106 -> V_38 &&
V_106 -> V_36 < V_106 -> V_59 . V_111 ) {
V_41 = F_63 ( V_106 ) ;
if ( V_41 )
goto V_104;
V_106 -> V_3 ++ ;
F_73 ( & V_106 -> V_126 ,
& V_106 -> V_127 -> V_128 ) ;
}
V_104:
F_12 ( & V_7 -> V_10 , V_9 ) ;
}
static struct V_39 *
F_74 ( struct V_6 * V_7 ,
struct V_39 * V_69 )
{
struct V_129 * V_31 ;
T_1 V_60 ;
V_31 = & ( (struct V_23 * ) V_69 -> V_42 . V_26 ) -> V_31 ;
if ( V_31 -> V_60 ) {
V_60 = V_121 ;
goto V_130;
}
if ( V_31 -> V_36 == F_19 ( 1 ) ) {
if ( ! ( F_46 ( V_31 ) & V_110 ) ) {
V_60 = V_131 ;
goto V_130;
}
return F_62 ( V_7 , V_69 ) ;
} else {
if ( F_46 ( V_31 ) & V_110 ) {
V_60 = V_131 ;
goto V_130;
}
return F_60 ( V_7 , V_69 ) ;
}
V_130:
F_30 ( V_7 , V_69 , V_60 ) ;
F_11 ( V_69 ) ;
return NULL ;
}
static void F_75 ( struct V_6 * V_7 ,
struct V_39 * V_69 )
{
struct V_23 * V_56 ;
V_56 = (struct V_23 * ) V_69 -> V_42 . V_26 ;
if ( V_56 -> V_31 . V_60 != V_132 ) {
F_65 ( V_7 , V_69 , V_121 ) ;
F_30 ( V_7 , V_69 , V_121 ) ;
} else
F_65 ( V_7 , V_69 , V_56 -> V_31 . V_60 ) ;
}
static void F_76 ( struct V_6 * V_7 ,
struct V_39 * V_69 )
{
struct V_23 * V_56 ;
V_56 = (struct V_23 * ) V_69 -> V_42 . V_26 ;
if ( V_56 -> V_31 . V_60 < V_133 ||
V_56 -> V_31 . V_60 > V_134 ) {
F_65 ( V_7 , V_69 , V_121 ) ;
F_30 ( V_7 , V_69 , V_121 ) ;
} else
F_65 ( V_7 , V_69 , V_56 -> V_31 . V_60 ) ;
}
struct V_39 *
F_77 ( struct V_6 * V_7 ,
struct V_39 * V_69 )
{
struct V_23 * V_56 ;
V_56 = (struct V_23 * ) V_69 -> V_42 . V_26 ;
if ( ! ( V_56 -> V_31 . V_109 & V_34 ) )
return V_69 ;
if ( V_56 -> V_31 . V_61 != V_62 ) {
F_65 ( V_7 , V_69 , V_135 ) ;
F_30 ( V_7 , V_69 , V_135 ) ;
goto V_104;
}
switch ( V_56 -> V_31 . V_32 ) {
case V_136 :
return F_74 ( V_7 , V_69 ) ;
case V_33 :
F_71 ( V_7 , V_69 ) ;
break;
case V_137 :
F_75 ( V_7 , V_69 ) ;
break;
case V_63 :
F_76 ( V_7 , V_69 ) ;
break;
default:
F_65 ( V_7 , V_69 , V_138 ) ;
F_30 ( V_7 , V_69 , V_138 ) ;
break;
}
V_104:
F_11 ( V_69 ) ;
return NULL ;
}
static int F_78 ( struct V_105 * V_106 )
{
struct V_6 * V_7 = V_106 -> V_127 ;
struct V_70 * V_27 = V_106 -> V_59 . V_26 ;
struct V_1 * V_2 ;
struct V_139 V_140 ;
unsigned long V_9 ;
int V_38 = 1 ;
if ( ! ( V_27 -> V_29 & V_30 ) )
goto V_104;
F_9 ( & V_7 -> V_10 , V_9 ) ;
F_10 (rmpp_recv, &agent->rmpp_list, list) {
if ( V_2 -> V_73 != V_27 -> V_73 ||
V_2 -> V_43 != V_27 -> V_43 ||
V_2 -> V_75 != V_27 -> V_75 ||
( V_2 -> V_29 & V_30 ) )
continue;
if ( F_79 ( V_106 -> V_59 . V_5 , & V_140 ) )
continue;
if ( V_2 -> V_74 == V_140 . V_141 ) {
V_38 = V_2 -> V_72 ;
break;
}
}
F_12 ( & V_7 -> V_10 , V_9 ) ;
V_104:
return V_38 ;
}
int F_80 ( struct V_105 * V_106 )
{
struct V_23 * V_56 ;
int V_41 ;
V_56 = V_106 -> V_59 . V_26 ;
if ( ! ( F_46 ( & V_56 -> V_31 ) &
V_34 ) )
return V_142 ;
if ( V_56 -> V_31 . V_32 != V_136 ) {
V_106 -> V_36 = 1 ;
return V_143 ;
}
V_106 -> V_38 = F_78 ( V_106 ) ;
V_106 -> V_3 += ( V_106 -> V_107 == 0 ) ;
V_41 = F_63 ( V_106 ) ;
if ( ! V_41 )
return V_144 ;
return V_41 ;
}
int F_81 ( struct V_105 * V_106 ,
struct V_57 * V_58 )
{
struct V_23 * V_56 ;
int V_41 ;
V_56 = V_106 -> V_59 . V_26 ;
if ( ! ( F_46 ( & V_56 -> V_31 ) &
V_34 ) )
return V_142 ;
if ( V_56 -> V_31 . V_32 != V_136 )
return V_143 ;
if ( V_58 -> V_114 != V_115 ||
V_106 -> V_114 != V_115 )
return V_145 ;
if ( ! V_106 -> V_107 )
return V_145 ;
if ( V_106 -> V_35 == V_106 -> V_59 . V_111 ) {
V_106 -> V_107 =
F_59 ( V_106 -> V_59 . V_113 ) ;
return V_145 ;
}
if ( V_106 -> V_36 == V_106 -> V_38 ||
V_106 -> V_36 == V_106 -> V_59 . V_111 )
return V_145 ;
V_41 = F_63 ( V_106 ) ;
if ( V_41 ) {
V_58 -> V_114 = V_146 ;
return V_145 ;
}
return V_144 ;
}
int F_82 ( struct V_105 * V_106 )
{
struct V_23 * V_56 ;
int V_41 ;
V_56 = V_106 -> V_59 . V_26 ;
if ( ! ( F_46 ( & V_56 -> V_31 ) &
V_34 ) )
return V_142 ;
if ( V_106 -> V_35 == V_106 -> V_59 . V_111 )
return V_145 ;
V_106 -> V_36 = V_106 -> V_35 ;
V_106 -> V_147 = V_106 -> V_119 ;
V_41 = F_63 ( V_106 ) ;
if ( V_41 )
return V_145 ;
return V_144 ;
}
