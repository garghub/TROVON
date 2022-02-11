static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 0 ;
F_2 (b, dev->me_clients_map, MEI_CLIENTS_MAX)
V_2 -> V_6 ++ ;
if ( V_2 -> V_6 == 0 )
return;
F_3 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
F_4 ( & V_2 -> V_10 -> V_2 , L_1 ,
V_2 -> V_6 * sizeof( struct V_3 ) ) ;
V_4 = F_5 ( V_2 -> V_6 ,
sizeof( struct V_3 ) , V_11 ) ;
if ( ! V_4 ) {
F_6 ( & V_2 -> V_10 -> V_2 , L_2 ) ;
V_2 -> V_12 = V_13 ;
F_7 ( V_2 , 1 ) ;
return;
}
V_2 -> V_9 = V_4 ;
return;
}
static inline
void F_8 ( struct V_14 * V_15 , T_1 V_16 , void * V_17 , T_2 V_18 )
{
struct V_19 * V_20 = V_17 ;
memset ( V_20 , 0 , V_18 ) ;
V_20 -> V_16 = V_16 ;
V_20 -> V_21 = V_15 -> V_22 ;
V_20 -> V_23 = V_15 -> V_24 ;
}
static inline
bool F_9 ( struct V_14 * V_15 , void * V_17 )
{
struct V_19 * V_20 = V_17 ;
return V_15 -> V_22 == V_20 -> V_21 &&
V_15 -> V_24 == V_20 -> V_23 ;
}
static bool F_10 ( struct V_14 * V_15 ,
struct V_25 * V_26 )
{
if ( F_9 ( V_15 , V_26 ) ) {
if ( ! V_26 -> V_27 ) {
V_15 -> V_28 = V_29 ;
V_15 -> V_27 = 0 ;
} else {
V_15 -> V_28 = V_30 ;
V_15 -> V_27 = - V_31 ;
}
V_15 -> V_32 = 0 ;
return true ;
}
return false ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_33 ;
if ( V_2 -> V_34 > V_35 )
return 0 ;
F_12 ( & V_2 -> V_36 ) ;
V_33 = F_13 ( V_2 -> V_37 ,
V_2 -> V_34 == V_38 ||
V_2 -> V_34 > V_35 ,
F_14 ( V_39 ) ) ;
F_15 ( & V_2 -> V_36 ) ;
if ( V_33 <= 0 && ( V_2 -> V_34 <= V_35 ) ) {
V_2 -> V_34 = V_38 ;
F_6 ( & V_2 -> V_10 -> V_2 , L_3 ) ;
return - V_40 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = & V_2 -> V_43 . V_44 ;
struct V_45 * V_46 ;
const T_2 V_18 = sizeof( struct V_45 ) ;
F_17 ( V_42 , V_18 ) ;
V_46 = (struct V_45 * ) V_2 -> V_43 . V_47 ;
memset ( V_46 , 0 , V_18 ) ;
V_46 -> V_16 = V_48 ;
V_46 -> V_49 . V_50 = V_51 ;
V_46 -> V_49 . V_52 = V_53 ;
V_2 -> V_34 = V_38 ;
if ( F_18 ( V_2 , V_42 , V_2 -> V_43 . V_47 ) ) {
F_6 ( & V_2 -> V_10 -> V_2 , L_4 ) ;
V_2 -> V_12 = V_13 ;
F_7 ( V_2 , 1 ) ;
return - V_54 ;
}
V_2 -> V_34 = V_35 ;
V_2 -> V_55 = V_56 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = & V_2 -> V_43 . V_44 ;
struct V_57 * V_58 ;
const T_2 V_18 = sizeof( struct V_57 ) ;
F_17 ( V_42 , V_18 ) ;
V_58 = (struct V_57 * ) V_2 -> V_43 . V_47 ;
memset ( V_58 , 0 , V_18 ) ;
V_58 -> V_16 = V_59 ;
if ( F_18 ( V_2 , V_42 , V_2 -> V_43 . V_47 ) ) {
V_2 -> V_12 = V_13 ;
F_6 ( & V_2 -> V_10 -> V_2 , L_5 ) ;
F_7 ( V_2 , 1 ) ;
}
V_2 -> V_34 = V_60 ;
V_2 -> V_55 = V_56 ;
return;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = & V_2 -> V_43 . V_44 ;
struct V_61 * V_62 ;
const T_2 V_18 = sizeof( struct V_61 ) ;
unsigned long V_63 ;
unsigned long V_64 ;
V_64 = V_2 -> V_7 ;
V_63 = F_21 ( V_2 -> V_65 , V_66 ,
V_2 -> V_8 ) ;
if ( V_63 == V_66 ) {
V_2 -> V_34 = V_67 ;
F_22 ( & V_2 -> V_68 ) ;
return 0 ;
}
V_2 -> V_9 [ V_64 ] . V_69 = V_63 ;
V_2 -> V_9 [ V_64 ] . V_70 = 0 ;
F_17 ( V_42 , V_18 ) ;
V_62 = (struct V_61 * ) V_2 -> V_43 . V_47 ;
memset ( V_62 , 0 , sizeof( struct V_61 ) ) ;
V_62 -> V_16 = V_71 ;
V_62 -> V_72 = V_63 ;
if ( F_18 ( V_2 , V_42 , V_2 -> V_43 . V_47 ) ) {
V_2 -> V_12 = V_13 ;
F_6 ( & V_2 -> V_10 -> V_2 , L_6 ) ;
F_7 ( V_2 , 1 ) ;
return - V_54 ;
}
V_2 -> V_55 = V_56 ;
V_2 -> V_8 = V_63 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_41 * V_42 , unsigned char * V_47 )
{
struct V_73 * V_74 =
(struct V_73 * ) V_47 ;
const T_2 V_18 = sizeof( struct V_73 ) ;
F_17 ( V_42 , V_18 ) ;
memset ( V_74 , 0 , V_18 ) ;
V_74 -> V_16 = V_75 ;
V_74 -> V_76 = V_77 ;
}
int F_24 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_41 * V_42 = & V_2 -> V_43 . V_44 ;
const T_2 V_18 = sizeof( struct V_78 ) ;
F_17 ( V_42 , V_18 ) ;
F_8 ( V_15 , V_79 , V_2 -> V_43 . V_47 , V_18 ) ;
F_4 ( & V_2 -> V_10 -> V_2 , L_7 ,
V_15 -> V_22 , V_15 -> V_24 ) ;
return F_18 ( V_2 , V_42 , V_2 -> V_43 . V_47 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_78 * V_80 )
{
struct V_3 * V_81 ;
int V_82 ;
for ( V_82 = 0 ; V_82 < V_2 -> V_6 ; V_82 ++ ) {
V_81 = & V_2 -> V_9 [ V_82 ] ;
if ( V_81 && V_80 -> V_23 == V_81 -> V_69 ) {
if ( V_81 -> V_83 . V_84 ) {
V_81 -> V_70 ++ ;
F_4 ( & V_2 -> V_10 -> V_2 , L_8 ,
V_80 -> V_23 ) ;
F_4 ( & V_2 -> V_10 -> V_2 , L_9 ,
V_81 -> V_70 ) ;
} else {
F_26 () ;
}
}
}
}
static void F_27 ( struct V_1 * V_2 ,
struct V_78 * V_85 )
{
struct V_14 * V_15 = NULL ;
struct V_14 * V_86 = NULL ;
if ( ! V_85 -> V_21 ) {
F_25 ( V_2 , V_85 ) ;
return;
}
F_28 (cl, next, &dev->file_list, link) {
if ( F_9 ( V_15 , V_85 ) ) {
V_15 -> V_70 ++ ;
F_4 ( & V_2 -> V_10 -> V_2 , L_10 ,
V_85 -> V_21 , V_85 -> V_23 ) ;
F_4 ( & V_2 -> V_10 -> V_2 , L_11 ,
V_15 -> V_70 ) ;
break;
}
}
}
int F_29 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_41 * V_42 = & V_2 -> V_43 . V_44 ;
const T_2 V_18 = sizeof( struct V_87 ) ;
F_17 ( V_42 , V_18 ) ;
F_8 ( V_15 , V_88 , V_2 -> V_43 . V_47 , V_18 ) ;
return F_18 ( V_2 , V_42 , V_2 -> V_43 . V_47 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_14 * V_15 ;
struct V_89 * V_90 = NULL , * V_86 = NULL ;
F_4 ( & V_2 -> V_10 -> V_2 ,
L_12
L_13
L_14
L_15 ,
V_26 -> V_23 ,
V_26 -> V_21 ,
V_26 -> V_27 ) ;
F_28 (pos, next, &dev->ctrl_rd_list.list, list) {
V_15 = V_90 -> V_15 ;
if ( ! V_15 ) {
F_31 ( & V_90 -> V_91 ) ;
return;
}
F_4 ( & V_2 -> V_10 -> V_2 , L_16 ) ;
if ( F_9 ( V_15 , V_26 ) ) {
F_31 ( & V_90 -> V_91 ) ;
if ( ! V_26 -> V_27 )
V_15 -> V_28 = V_30 ;
V_15 -> V_27 = 0 ;
V_15 -> V_32 = 0 ;
break;
}
}
}
int F_32 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_41 * V_42 = & V_2 -> V_43 . V_44 ;
const T_2 V_18 = sizeof( struct V_87 ) ;
F_17 ( V_42 , V_18 ) ;
F_8 ( V_15 , V_92 , V_2 -> V_43 . V_47 , V_18 ) ;
return F_18 ( V_2 , V_42 , V_2 -> V_43 . V_47 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_14 * V_15 ;
struct V_89 * V_90 = NULL , * V_86 = NULL ;
F_4 ( & V_2 -> V_10 -> V_2 ,
L_17
L_13
L_14
L_15 ,
V_26 -> V_23 ,
V_26 -> V_21 ,
V_26 -> V_27 ) ;
if ( F_10 ( & V_2 -> V_93 , V_26 ) ) {
F_4 ( & V_2 -> V_10 -> V_2 , L_18 ) ;
F_34 ( V_2 ) ;
return;
}
if ( F_10 ( & V_2 -> V_94 , V_26 ) ) {
V_2 -> V_95 = V_96 ;
return;
}
F_28 (pos, next, &dev->ctrl_rd_list.list, list) {
V_15 = V_90 -> V_15 ;
if ( ! V_15 ) {
F_31 ( & V_90 -> V_91 ) ;
return;
}
if ( V_90 -> V_97 == V_98 ) {
if ( F_10 ( V_15 , V_26 ) ) {
F_31 ( & V_90 -> V_91 ) ;
V_15 -> V_27 = 0 ;
V_15 -> V_32 = 0 ;
break;
}
}
}
}
static void F_35 ( struct V_1 * V_2 ,
struct V_87 * V_99 )
{
struct V_14 * V_15 , * V_86 ;
const T_2 V_18 = sizeof( struct V_25 ) ;
F_28 (cl, next, &dev->file_list, link) {
if ( F_9 ( V_15 , V_99 ) ) {
F_4 ( & V_2 -> V_10 -> V_2 , L_19 ,
V_99 -> V_21 ,
V_99 -> V_23 ) ;
V_15 -> V_28 = V_30 ;
V_15 -> V_32 = 0 ;
if ( V_15 == & V_2 -> V_93 )
V_2 -> V_100 = false ;
else if ( V_15 == & V_2 -> V_94 )
V_2 -> V_101 = 0 ;
F_17 ( & V_2 -> V_102 . V_44 , V_18 ) ;
F_8 ( V_15 , V_103 ,
V_2 -> V_102 . V_47 , V_18 ) ;
break;
}
}
}
bool F_36 ( struct V_1 * V_2 )
{
return ( V_2 -> V_104 . V_50 < V_51 ) ||
( V_2 -> V_104 . V_50 == V_51 &&
V_2 -> V_104 . V_52 <= V_53 ) ;
}
void F_37 ( struct V_1 * V_2 , struct V_41 * V_44 )
{
struct V_105 * V_106 ;
struct V_3 * V_107 ;
struct V_108 * V_109 ;
struct V_25 * V_110 ;
struct V_25 * V_111 ;
struct V_87 * V_99 ;
struct V_78 * V_85 ;
struct V_112 * V_113 ;
struct V_114 * V_115 ;
F_38 ( V_44 -> V_116 >= sizeof( V_2 -> V_117 ) ) ;
F_39 ( V_2 , V_2 -> V_117 , V_44 -> V_116 ) ;
V_106 = (struct V_105 * ) V_2 -> V_117 ;
switch ( V_106 -> V_16 ) {
case V_118 :
V_109 = (struct V_108 * ) V_106 ;
F_4 ( & V_2 -> V_10 -> V_2 , L_20 ,
V_51 , V_53 ,
V_109 -> V_119 . V_50 ,
V_109 -> V_119 . V_52 ) ;
if ( V_109 -> V_120 ) {
V_2 -> V_104 . V_50 = V_51 ;
V_2 -> V_104 . V_52 = V_53 ;
} else {
V_2 -> V_104 . V_50 =
V_109 -> V_119 . V_50 ;
V_2 -> V_104 . V_52 =
V_109 -> V_119 . V_52 ;
}
if ( ! F_36 ( V_2 ) ) {
F_40 ( & V_2 -> V_10 -> V_2 , L_21 ) ;
V_2 -> V_34 = V_121 ;
F_23 ( V_2 , & V_2 -> V_43 . V_44 ,
V_2 -> V_43 . V_47 ) ;
F_18 ( V_2 , & V_2 -> V_43 . V_44 ,
V_2 -> V_43 . V_47 ) ;
return;
}
if ( V_2 -> V_12 == V_122 &&
V_2 -> V_34 == V_35 ) {
V_2 -> V_55 = 0 ;
F_19 ( V_2 ) ;
} else {
F_6 ( & V_2 -> V_10 -> V_2 , L_22 ) ;
F_7 ( V_2 , 1 ) ;
return;
}
F_41 ( & V_2 -> V_37 ) ;
F_4 ( & V_2 -> V_10 -> V_2 , L_23 ) ;
break;
case V_123 :
V_110 = (struct V_25 * ) V_106 ;
F_33 ( V_2 , V_110 ) ;
F_4 ( & V_2 -> V_10 -> V_2 , L_24 ) ;
F_42 ( & V_2 -> V_37 ) ;
break;
case V_103 :
V_111 = (struct V_25 * ) V_106 ;
F_30 ( V_2 , V_111 ) ;
F_4 ( & V_2 -> V_10 -> V_2 , L_25 ) ;
F_42 ( & V_2 -> V_37 ) ;
break;
case V_79 :
V_85 = (struct V_78 * ) V_106 ;
F_27 ( V_2 , V_85 ) ;
F_4 ( & V_2 -> V_10 -> V_2 , L_26 ) ;
break;
case V_124 :
V_113 = (struct V_112 * ) V_106 ;
V_107 = & V_2 -> V_9 [ V_2 -> V_7 ] ;
if ( V_113 -> V_27 || ! V_2 -> V_9 ) {
F_6 ( & V_2 -> V_10 -> V_2 , L_27 ) ;
F_7 ( V_2 , 1 ) ;
return;
}
if ( V_107 -> V_69 != V_113 -> V_72 ) {
F_6 ( & V_2 -> V_10 -> V_2 , L_28 ) ;
F_7 ( V_2 , 1 ) ;
return;
}
if ( V_2 -> V_12 != V_122 ||
V_2 -> V_34 != V_125 ) {
F_6 ( & V_2 -> V_10 -> V_2 , L_29 ) ;
F_7 ( V_2 , 1 ) ;
return;
}
V_107 -> V_83 = V_113 -> V_126 ;
V_2 -> V_8 ++ ;
V_2 -> V_7 ++ ;
F_20 ( V_2 ) ;
break;
case V_127 :
V_115 = (struct V_114 * ) V_106 ;
F_43 ( sizeof( V_2 -> V_65 )
< sizeof( V_115 -> V_128 ) ) ;
memcpy ( V_2 -> V_65 , V_115 -> V_128 ,
sizeof( V_115 -> V_128 ) ) ;
if ( V_2 -> V_12 == V_122 &&
V_2 -> V_34 == V_60 ) {
V_2 -> V_55 = 0 ;
F_1 ( V_2 ) ;
V_2 -> V_34 = V_125 ;
F_20 ( V_2 ) ;
} else {
F_6 ( & V_2 -> V_10 -> V_2 , L_30 ) ;
F_7 ( V_2 , 1 ) ;
return;
}
break;
case V_129 :
if ( V_2 -> V_34 != V_121 )
F_6 ( & V_2 -> V_10 -> V_2 , L_31 ) ;
V_2 -> V_12 = V_130 ;
F_44 ( & V_2 -> V_10 -> V_2 , L_32 ) ;
F_7 ( V_2 , 1 ) ;
break;
case V_88 :
V_99 = (struct V_87 * ) V_106 ;
F_35 ( V_2 , V_99 ) ;
break;
case V_131 :
V_2 -> V_34 = V_121 ;
F_23 ( V_2 , & V_2 -> V_102 . V_44 ,
V_2 -> V_102 . V_47 ) ;
break;
default:
F_26 () ;
break;
}
}
