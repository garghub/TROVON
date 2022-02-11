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
0 , V_47 ) ;
if ( F_23 ( V_22 ) )
return;
F_17 ( V_22 , (struct V_23 * ) V_40 -> V_42 . V_26 , V_2 ) ;
V_22 -> V_5 = V_2 -> V_5 ;
V_41 = F_24 ( V_22 , NULL ) ;
if ( V_41 )
F_25 ( V_22 ) ;
}
static struct V_21 * F_26 ( struct V_48 * V_7 ,
struct V_39 * V_40 )
{
struct V_21 * V_22 ;
struct V_49 * V_5 ;
int V_28 ;
V_5 = F_27 ( V_7 -> V_50 -> V_51 , V_40 -> V_44 ,
V_40 -> V_42 . V_52 , V_7 -> V_53 ) ;
if ( F_23 ( V_5 ) )
return ( void * ) V_5 ;
V_28 = F_21 ( V_40 -> V_42 . V_26 -> V_27 . V_43 ) ;
V_22 = F_22 ( V_7 , V_40 -> V_44 -> V_45 ,
V_40 -> V_44 -> V_46 , 1 ,
V_28 , 0 , V_47 ) ;
if ( F_23 ( V_22 ) )
F_6 ( V_5 ) ;
else {
V_22 -> V_5 = V_5 ;
V_22 -> V_54 [ 0 ] = V_5 ;
}
return V_22 ;
}
static void F_28 ( struct V_6 * V_7 ,
struct V_39 * V_40 )
{
struct V_21 * V_22 ;
struct V_23 * V_55 ;
int V_41 ;
V_22 = F_26 ( & V_7 -> V_7 , V_40 ) ;
if ( F_23 ( V_22 ) )
return;
V_55 = V_22 -> V_26 ;
memcpy ( V_55 , V_40 -> V_42 . V_26 , V_22 -> V_28 ) ;
V_55 -> V_27 . V_29 ^= V_30 ;
F_18 ( & V_55 -> V_31 , V_34 ) ;
V_55 -> V_31 . V_36 = 0 ;
V_55 -> V_31 . V_37 = F_19 ( 1 ) ;
V_41 = F_24 ( V_22 , NULL ) ;
if ( V_41 ) {
F_6 ( V_22 -> V_5 ) ;
F_25 ( V_22 ) ;
}
}
void F_29 ( struct V_56 * V_57 )
{
if ( V_57 -> V_58 -> V_54 [ 0 ] == V_57 -> V_58 -> V_5 )
F_6 ( V_57 -> V_58 -> V_5 ) ;
F_25 ( V_57 -> V_58 ) ;
}
static void F_30 ( struct V_6 * V_7 ,
struct V_39 * V_40 , T_1 V_59 )
{
struct V_21 * V_22 ;
struct V_23 * V_55 ;
int V_41 ;
V_22 = F_26 ( & V_7 -> V_7 , V_40 ) ;
if ( F_23 ( V_22 ) )
return;
V_55 = V_22 -> V_26 ;
memcpy ( V_55 , V_40 -> V_42 . V_26 , V_22 -> V_28 ) ;
V_55 -> V_27 . V_29 ^= V_30 ;
V_55 -> V_31 . V_60 = V_61 ;
V_55 -> V_31 . V_32 = V_62 ;
F_18 ( & V_55 -> V_31 , V_34 ) ;
V_55 -> V_31 . V_59 = V_59 ;
V_55 -> V_31 . V_36 = 0 ;
V_55 -> V_31 . V_37 = 0 ;
V_41 = F_24 ( V_22 , NULL ) ;
if ( V_41 ) {
F_6 ( V_22 -> V_5 ) ;
F_25 ( V_22 ) ;
}
}
static void F_31 ( struct V_63 * V_64 )
{
struct V_1 * V_2 =
F_32 ( V_64 , struct V_1 , V_15 . V_64 ) ;
struct V_39 * V_13 ;
unsigned long V_9 ;
F_9 ( & V_2 -> V_7 -> V_10 , V_9 ) ;
if ( V_2 -> V_11 != V_65 ) {
F_12 ( & V_2 -> V_7 -> V_10 , V_9 ) ;
return;
}
V_2 -> V_11 = V_66 ;
F_16 ( & V_2 -> V_20 ) ;
F_12 ( & V_2 -> V_7 -> V_10 , V_9 ) ;
V_13 = V_2 -> V_13 ;
F_30 ( V_2 -> V_7 , V_13 , V_67 ) ;
F_4 ( V_2 ) ;
F_11 ( V_13 ) ;
}
static void F_33 ( struct V_63 * V_64 )
{
struct V_1 * V_2 =
F_32 ( V_64 , struct V_1 , V_16 . V_64 ) ;
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
struct V_39 * V_68 )
{
struct V_1 * V_2 ;
struct V_69 * V_27 ;
V_2 = F_35 ( sizeof *V_2 , V_47 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_5 = F_27 ( V_7 -> V_7 . V_50 -> V_51 ,
V_68 -> V_44 ,
V_68 -> V_42 . V_52 ,
V_7 -> V_7 . V_53 ) ;
if ( F_23 ( V_2 -> V_5 ) )
goto error;
V_2 -> V_7 = V_7 ;
F_36 ( & V_2 -> V_4 ) ;
F_37 ( & V_2 -> V_15 , F_31 ) ;
F_37 ( & V_2 -> V_16 , F_33 ) ;
F_38 ( & V_2 -> V_10 ) ;
V_2 -> V_11 = V_65 ;
F_39 ( & V_2 -> V_3 , 1 ) ;
V_2 -> V_13 = V_68 ;
V_2 -> V_70 = & V_68 -> V_42 ;
V_2 -> V_38 = 1 ;
V_2 -> V_36 = 1 ;
V_2 -> V_35 = 0 ;
V_2 -> V_71 = 1 ;
V_27 = & V_68 -> V_42 . V_26 -> V_27 ;
V_2 -> V_72 = V_27 -> V_72 ;
V_2 -> V_45 = V_68 -> V_44 -> V_45 ;
V_2 -> V_73 = V_68 -> V_44 -> V_73 ;
V_2 -> V_43 = V_27 -> V_43 ;
V_2 -> V_74 = V_27 -> V_74 ;
V_2 -> V_29 = V_27 -> V_29 ;
return V_2 ;
error: F_7 ( V_2 ) ;
return NULL ;
}
static struct V_1 *
F_40 ( struct V_6 * V_7 ,
struct V_39 * V_68 )
{
struct V_1 * V_2 ;
struct V_69 * V_27 = & V_68 -> V_42 . V_26 -> V_27 ;
F_10 (rmpp_recv, &agent->rmpp_list, list) {
if ( V_2 -> V_72 == V_27 -> V_72 &&
V_2 -> V_45 == V_68 -> V_44 -> V_45 &&
V_2 -> V_73 == V_68 -> V_44 -> V_73 &&
V_2 -> V_43 == V_27 -> V_43 &&
V_2 -> V_74 == V_27 -> V_74 &&
V_2 -> V_29 == V_27 -> V_29 )
return V_2 ;
}
return NULL ;
}
static struct V_1 *
F_41 ( struct V_6 * V_7 ,
struct V_39 * V_68 )
{
struct V_1 * V_2 ;
unsigned long V_9 ;
F_9 ( & V_7 -> V_10 , V_9 ) ;
V_2 = F_40 ( V_7 , V_68 ) ;
if ( V_2 )
F_42 ( & V_2 -> V_3 ) ;
F_12 ( & V_7 -> V_10 , V_9 ) ;
return V_2 ;
}
static struct V_1 *
F_43 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
struct V_1 * V_75 ;
V_75 = F_40 ( V_7 , V_2 -> V_13 ) ;
if ( ! V_75 )
F_44 ( & V_2 -> V_20 , & V_7 -> V_76 ) ;
return V_75 ;
}
static inline int F_45 ( struct V_77 * V_78 )
{
struct V_23 * V_55 ;
V_55 = (struct V_23 * ) V_78 -> V_26 ;
return F_46 ( & V_55 -> V_31 ) & V_79 ;
}
static inline int F_47 ( struct V_77 * V_78 )
{
struct V_23 * V_55 ;
V_55 = (struct V_23 * ) V_78 -> V_26 ;
return F_48 ( V_55 -> V_31 . V_36 ) ;
}
static inline struct V_77 * F_49 ( struct V_80 * V_76 ,
struct V_77 * V_78 )
{
if ( V_78 -> V_20 . V_81 == V_76 )
return NULL ;
return F_32 ( V_78 -> V_20 . V_81 , struct V_77 , V_20 ) ;
}
static inline int F_50 ( struct V_6 * V_7 )
{
return F_51 ( V_7 -> V_17 -> V_82 . V_83 >> 3 , 1 ) ;
}
static struct V_77 * F_52 ( struct V_80 * V_76 ,
int V_36 )
{
struct V_77 * V_84 ;
int V_85 ;
F_53 (seg_buf, rmpp_list, list) {
V_85 = F_47 ( V_84 ) ;
if ( V_36 > V_85 )
return V_84 ;
if ( V_36 == V_85 )
break;
}
return NULL ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_77 * V_86 )
{
struct V_80 * V_76 = & V_2 -> V_13 -> V_76 ;
while ( V_86 && ( F_47 ( V_86 ) == V_2 -> V_36 + 1 ) ) {
V_2 -> V_70 = V_86 ;
V_2 -> V_36 ++ ;
V_86 = F_49 ( V_76 , V_86 ) ;
}
}
static inline int F_55 ( struct V_1 * V_2 )
{
struct V_23 * V_55 ;
int V_87 , V_88 , V_89 ;
V_55 = (struct V_23 * ) V_2 -> V_70 -> V_26 ;
V_87 = F_21 ( V_55 -> V_27 . V_43 ) ;
V_88 = sizeof( struct V_23 ) - V_87 ;
V_89 = V_90 - F_48 ( V_55 -> V_31 . V_37 ) ;
if ( V_89 > V_90 || V_89 < 0 )
V_89 = 0 ;
return V_87 + V_2 -> V_36 * V_88 - V_89 ;
}
static struct V_39 * F_56 ( struct V_1 * V_2 )
{
struct V_39 * V_13 ;
F_20 ( V_2 , V_2 -> V_13 ) ;
if ( V_2 -> V_36 > 1 )
F_13 ( & V_2 -> V_15 ) ;
V_13 = V_2 -> V_13 ;
V_13 -> V_91 = F_55 ( V_2 ) ;
F_57 ( V_2 -> V_7 -> V_17 -> V_18 -> V_19 ,
& V_2 -> V_16 , F_58 ( 10000 ) ) ;
return V_13 ;
}
static struct V_39 *
F_59 ( struct V_6 * V_7 ,
struct V_39 * V_68 )
{
struct V_1 * V_2 ;
struct V_77 * V_92 ;
struct V_39 * V_93 ;
int V_36 ;
unsigned long V_9 ;
V_2 = F_41 ( V_7 , V_68 ) ;
if ( ! V_2 )
goto V_94;
V_36 = F_47 ( & V_68 -> V_42 ) ;
F_9 ( & V_2 -> V_10 , V_9 ) ;
if ( ( V_2 -> V_11 == V_66 ) ||
( V_36 > V_2 -> V_38 ) )
goto V_95;
if ( ( V_36 <= V_2 -> V_35 ) ||
( V_2 -> V_11 == V_12 ) ) {
F_12 ( & V_2 -> V_10 , V_9 ) ;
F_20 ( V_2 , V_68 ) ;
goto V_96;
}
V_92 = F_52 ( & V_2 -> V_13 -> V_76 , V_36 ) ;
if ( ! V_92 )
goto V_95;
V_93 = NULL ;
F_60 ( & V_68 -> V_42 . V_20 , & V_92 -> V_20 ) ;
if ( V_2 -> V_70 == V_92 ) {
F_54 ( V_2 , & V_68 -> V_42 ) ;
if ( F_45 ( V_2 -> V_70 ) ) {
V_2 -> V_11 = V_12 ;
F_12 ( & V_2 -> V_10 , V_9 ) ;
V_93 = F_56 ( V_2 ) ;
goto V_97;
} else if ( V_2 -> V_36 == V_2 -> V_38 ) {
V_2 -> V_38 += F_50 ( V_7 ) ;
F_12 ( & V_2 -> V_10 , V_9 ) ;
F_20 ( V_2 , V_68 ) ;
goto V_97;
}
}
F_12 ( & V_2 -> V_10 , V_9 ) ;
V_97:
F_1 ( V_2 ) ;
return V_93 ;
V_95: F_12 ( & V_2 -> V_10 , V_9 ) ;
V_96: F_1 ( V_2 ) ;
V_94: F_11 ( V_68 ) ;
return NULL ;
}
static struct V_39 *
F_61 ( struct V_6 * V_7 ,
struct V_39 * V_68 )
{
struct V_1 * V_2 ;
unsigned long V_9 ;
V_2 = F_34 ( V_7 , V_68 ) ;
if ( ! V_2 ) {
F_11 ( V_68 ) ;
return NULL ;
}
F_9 ( & V_7 -> V_10 , V_9 ) ;
if ( F_43 ( V_7 , V_2 ) ) {
F_12 ( & V_7 -> V_10 , V_9 ) ;
F_4 ( V_2 ) ;
return F_59 ( V_7 , V_68 ) ;
}
F_42 ( & V_2 -> V_3 ) ;
if ( F_45 ( & V_68 -> V_42 ) ) {
V_2 -> V_11 = V_12 ;
F_12 ( & V_7 -> V_10 , V_9 ) ;
F_56 ( V_2 ) ;
} else {
F_12 ( & V_7 -> V_10 , V_9 ) ;
F_57 ( V_7 -> V_17 -> V_18 -> V_19 ,
& V_2 -> V_15 ,
F_58 ( 40000 ) ) ;
V_2 -> V_38 += F_50 ( V_7 ) ;
F_20 ( V_2 , V_68 ) ;
V_68 = NULL ;
}
F_1 ( V_2 ) ;
return V_68 ;
}
static int F_62 ( struct V_98 * V_99 )
{
struct V_23 * V_55 ;
int V_100 ;
T_2 V_101 = 0 ;
V_55 = V_99 -> V_58 . V_26 ;
F_18 ( & V_55 -> V_31 , V_34 ) ;
V_55 -> V_31 . V_36 = F_19 ( ++ V_99 -> V_36 ) ;
if ( V_99 -> V_36 == 1 ) {
V_55 -> V_31 . V_102 |= V_103 ;
V_101 = V_99 -> V_58 . V_104 * V_90 -
V_99 -> V_89 ;
}
if ( V_99 -> V_36 == V_99 -> V_58 . V_104 ) {
V_55 -> V_31 . V_102 |= V_79 ;
V_101 = V_90 - V_99 -> V_89 ;
}
V_55 -> V_31 . V_37 = F_19 ( V_101 ) ;
V_100 = V_99 -> V_58 . V_105 ;
if ( ! V_100 || V_100 > 2000 )
V_99 -> V_100 = F_58 ( 2000 ) ;
return F_63 ( V_99 ) ;
}
static void F_64 ( struct V_6 * V_7 ,
struct V_39 * V_68 , T_1 V_59 )
{
struct V_98 * V_99 ;
struct V_56 V_44 ;
unsigned long V_9 ;
F_9 ( & V_7 -> V_10 , V_9 ) ;
V_99 = F_65 ( V_7 , V_68 ) ;
if ( ! V_99 )
goto V_97;
if ( ( V_99 -> V_35 == V_99 -> V_58 . V_104 ) ||
( ! V_99 -> V_100 ) || ( V_99 -> V_106 != V_107 ) )
goto V_97;
F_66 ( V_99 ) ;
F_12 ( & V_7 -> V_10 , V_9 ) ;
V_44 . V_106 = V_108 ;
V_44 . V_109 = V_59 ;
V_44 . V_58 = & V_99 -> V_58 ;
F_67 ( V_99 , & V_44 ) ;
return;
V_97:
F_12 ( & V_7 -> V_10 , V_9 ) ;
}
static inline void F_68 ( struct V_98 * V_110 ,
int V_36 )
{
struct V_80 * V_20 ;
V_110 -> V_35 = V_36 ;
V_20 = & V_110 -> V_111 -> V_20 ;
F_10 (wr->last_ack_seg, list, list)
if ( V_110 -> V_111 -> V_112 == V_36 )
break;
}
static void F_69 ( struct V_6 * V_7 ,
struct V_39 * V_68 , int V_38 )
{
struct V_1 * V_2 ;
V_2 = F_40 ( V_7 , V_68 ) ;
if ( V_2 && V_2 -> V_11 == V_12 )
V_2 -> V_71 = V_38 ;
}
static void F_70 ( struct V_6 * V_7 ,
struct V_39 * V_68 )
{
struct V_98 * V_99 ;
struct V_23 * V_55 ;
unsigned long V_9 ;
int V_36 , V_38 , V_41 ;
V_55 = (struct V_23 * ) V_68 -> V_42 . V_26 ;
if ( V_55 -> V_31 . V_59 ) {
F_64 ( V_7 , V_68 , V_113 ) ;
F_30 ( V_7 , V_68 , V_113 ) ;
return;
}
V_36 = F_48 ( V_55 -> V_31 . V_36 ) ;
V_38 = F_48 ( V_55 -> V_31 . V_37 ) ;
if ( V_38 < V_36 ) {
F_64 ( V_7 , V_68 , V_114 ) ;
F_30 ( V_7 , V_68 , V_114 ) ;
return;
}
F_9 ( & V_7 -> V_10 , V_9 ) ;
V_99 = F_65 ( V_7 , V_68 ) ;
if ( ! V_99 ) {
if ( ! V_36 )
F_69 ( V_7 , V_68 , V_38 ) ;
goto V_97;
}
if ( ( V_99 -> V_35 == V_99 -> V_58 . V_104 ) &&
( V_99 -> V_100 ) ) {
F_12 ( & V_7 -> V_10 , V_9 ) ;
F_28 ( V_7 , V_68 ) ;
return;
}
if ( ( V_99 -> V_35 == V_99 -> V_58 . V_104 ) ||
( ! V_99 -> V_100 ) || ( V_99 -> V_106 != V_107 ) )
goto V_97;
if ( V_36 > V_99 -> V_58 . V_104 ||
V_36 > V_99 -> V_38 ) {
F_12 ( & V_7 -> V_10 , V_9 ) ;
F_64 ( V_7 , V_68 , V_115 ) ;
F_30 ( V_7 , V_68 , V_115 ) ;
return;
}
if ( V_38 < V_99 -> V_38 || V_36 < V_99 -> V_35 )
goto V_97;
if ( V_36 > V_99 -> V_35 ) {
F_68 ( V_99 , V_36 ) ;
V_99 -> V_116 = V_99 -> V_117 ;
}
V_99 -> V_38 = V_38 ;
if ( V_99 -> V_35 == V_99 -> V_58 . V_104 ) {
if ( ! V_99 -> V_58 . V_105 ) {
struct V_56 V_44 ;
F_66 ( V_99 ) ;
F_12 ( & V_7 -> V_10 , V_9 ) ;
V_44 . V_106 = V_107 ;
V_44 . V_109 = 0 ;
V_44 . V_58 = & V_99 -> V_58 ;
F_67 ( V_99 , & V_44 ) ;
return;
}
if ( V_99 -> V_3 == 1 )
F_71 ( V_99 ,
V_99 -> V_58 . V_105 ) ;
F_12 ( & V_7 -> V_10 , V_9 ) ;
F_28 ( V_7 , V_68 ) ;
return;
} else if ( V_99 -> V_3 == 1 &&
V_99 -> V_36 < V_99 -> V_38 &&
V_99 -> V_36 < V_99 -> V_58 . V_104 ) {
V_41 = F_62 ( V_99 ) ;
if ( V_41 )
goto V_97;
V_99 -> V_3 ++ ;
F_72 ( & V_99 -> V_118 ,
& V_99 -> V_119 -> V_120 ) ;
}
V_97:
F_12 ( & V_7 -> V_10 , V_9 ) ;
}
static struct V_39 *
F_73 ( struct V_6 * V_7 ,
struct V_39 * V_68 )
{
struct V_121 * V_31 ;
T_1 V_59 ;
V_31 = & ( (struct V_23 * ) V_68 -> V_42 . V_26 ) -> V_31 ;
if ( V_31 -> V_59 ) {
V_59 = V_113 ;
goto V_122;
}
if ( V_31 -> V_36 == F_19 ( 1 ) ) {
if ( ! ( F_46 ( V_31 ) & V_103 ) ) {
V_59 = V_123 ;
goto V_122;
}
return F_61 ( V_7 , V_68 ) ;
} else {
if ( F_46 ( V_31 ) & V_103 ) {
V_59 = V_123 ;
goto V_122;
}
return F_59 ( V_7 , V_68 ) ;
}
V_122:
F_30 ( V_7 , V_68 , V_59 ) ;
F_11 ( V_68 ) ;
return NULL ;
}
static void F_74 ( struct V_6 * V_7 ,
struct V_39 * V_68 )
{
struct V_23 * V_55 ;
V_55 = (struct V_23 * ) V_68 -> V_42 . V_26 ;
if ( V_55 -> V_31 . V_59 != V_124 ) {
F_64 ( V_7 , V_68 , V_113 ) ;
F_30 ( V_7 , V_68 , V_113 ) ;
} else
F_64 ( V_7 , V_68 , V_55 -> V_31 . V_59 ) ;
}
static void F_75 ( struct V_6 * V_7 ,
struct V_39 * V_68 )
{
struct V_23 * V_55 ;
V_55 = (struct V_23 * ) V_68 -> V_42 . V_26 ;
if ( V_55 -> V_31 . V_59 < V_125 ||
V_55 -> V_31 . V_59 > V_126 ) {
F_64 ( V_7 , V_68 , V_113 ) ;
F_30 ( V_7 , V_68 , V_113 ) ;
} else
F_64 ( V_7 , V_68 , V_55 -> V_31 . V_59 ) ;
}
struct V_39 *
F_76 ( struct V_6 * V_7 ,
struct V_39 * V_68 )
{
struct V_23 * V_55 ;
V_55 = (struct V_23 * ) V_68 -> V_42 . V_26 ;
if ( ! ( V_55 -> V_31 . V_102 & V_34 ) )
return V_68 ;
if ( V_55 -> V_31 . V_60 != V_61 ) {
F_64 ( V_7 , V_68 , V_127 ) ;
F_30 ( V_7 , V_68 , V_127 ) ;
goto V_97;
}
switch ( V_55 -> V_31 . V_32 ) {
case V_128 :
return F_73 ( V_7 , V_68 ) ;
case V_33 :
F_70 ( V_7 , V_68 ) ;
break;
case V_129 :
F_74 ( V_7 , V_68 ) ;
break;
case V_62 :
F_75 ( V_7 , V_68 ) ;
break;
default:
F_64 ( V_7 , V_68 , V_130 ) ;
F_30 ( V_7 , V_68 , V_130 ) ;
break;
}
V_97:
F_11 ( V_68 ) ;
return NULL ;
}
static int F_77 ( struct V_98 * V_99 )
{
struct V_6 * V_7 = V_99 -> V_119 ;
struct V_69 * V_27 = V_99 -> V_58 . V_26 ;
struct V_1 * V_2 ;
struct V_131 V_132 ;
unsigned long V_9 ;
int V_38 = 1 ;
if ( ! ( V_27 -> V_29 & V_30 ) )
goto V_97;
F_9 ( & V_7 -> V_10 , V_9 ) ;
F_10 (rmpp_recv, &agent->rmpp_list, list) {
if ( V_2 -> V_72 != V_27 -> V_72 ||
V_2 -> V_43 != V_27 -> V_43 ||
V_2 -> V_74 != V_27 -> V_74 ||
( V_2 -> V_29 & V_30 ) )
continue;
if ( F_78 ( V_99 -> V_58 . V_5 , & V_132 ) )
continue;
if ( V_2 -> V_73 == V_132 . V_133 ) {
V_38 = V_2 -> V_71 ;
break;
}
}
F_12 ( & V_7 -> V_10 , V_9 ) ;
V_97:
return V_38 ;
}
int F_79 ( struct V_98 * V_99 )
{
struct V_23 * V_55 ;
int V_41 ;
V_55 = V_99 -> V_58 . V_26 ;
if ( ! ( F_46 ( & V_55 -> V_31 ) &
V_34 ) )
return V_134 ;
if ( V_55 -> V_31 . V_32 != V_128 ) {
V_99 -> V_36 = 1 ;
return V_135 ;
}
V_99 -> V_38 = F_77 ( V_99 ) ;
V_99 -> V_3 += ( V_99 -> V_100 == 0 ) ;
V_41 = F_62 ( V_99 ) ;
if ( ! V_41 )
return V_136 ;
return V_41 ;
}
int F_80 ( struct V_98 * V_99 ,
struct V_56 * V_57 )
{
struct V_23 * V_55 ;
int V_41 ;
V_55 = V_99 -> V_58 . V_26 ;
if ( ! ( F_46 ( & V_55 -> V_31 ) &
V_34 ) )
return V_134 ;
if ( V_55 -> V_31 . V_32 != V_128 )
return V_135 ;
if ( V_57 -> V_106 != V_107 ||
V_99 -> V_106 != V_107 )
return V_137 ;
if ( ! V_99 -> V_100 )
return V_137 ;
if ( V_99 -> V_35 == V_99 -> V_58 . V_104 ) {
V_99 -> V_100 =
F_58 ( V_99 -> V_58 . V_105 ) ;
return V_137 ;
}
if ( V_99 -> V_36 == V_99 -> V_38 ||
V_99 -> V_36 == V_99 -> V_58 . V_104 )
return V_137 ;
V_41 = F_62 ( V_99 ) ;
if ( V_41 ) {
V_57 -> V_106 = V_138 ;
return V_137 ;
}
return V_136 ;
}
int F_81 ( struct V_98 * V_99 )
{
struct V_23 * V_55 ;
int V_41 ;
V_55 = V_99 -> V_58 . V_26 ;
if ( ! ( F_46 ( & V_55 -> V_31 ) &
V_34 ) )
return V_134 ;
if ( V_99 -> V_35 == V_99 -> V_58 . V_104 )
return V_137 ;
V_99 -> V_36 = V_99 -> V_35 ;
V_99 -> V_139 = V_99 -> V_111 ;
V_41 = F_62 ( V_99 ) ;
if ( V_41 )
return V_137 ;
return V_136 ;
}
