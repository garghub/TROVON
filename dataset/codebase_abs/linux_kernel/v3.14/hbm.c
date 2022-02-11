static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 0 ;
F_2 (b, dev->me_clients_map, MEI_CLIENTS_MAX)
V_2 -> V_6 ++ ;
if ( V_2 -> V_6 == 0 )
return 0 ;
F_3 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
F_4 ( & V_2 -> V_10 -> V_2 , L_1 ,
V_2 -> V_6 * sizeof( struct V_3 ) ) ;
V_4 = F_5 ( V_2 -> V_6 ,
sizeof( struct V_3 ) , V_11 ) ;
if ( ! V_4 ) {
F_6 ( & V_2 -> V_10 -> V_2 , L_2 ) ;
return - V_12 ;
}
V_2 -> V_9 = V_4 ;
return 0 ;
}
static inline
void F_7 ( struct V_13 * V_14 , T_1 V_15 , void * V_16 , T_2 V_17 )
{
struct V_18 * V_19 = V_16 ;
memset ( V_19 , 0 , V_17 ) ;
V_19 -> V_15 = V_15 ;
V_19 -> V_20 = V_14 -> V_21 ;
V_19 -> V_22 = V_14 -> V_23 ;
}
static inline
bool F_8 ( struct V_13 * V_14 , void * V_16 )
{
struct V_18 * V_19 = V_16 ;
return V_14 -> V_21 == V_19 -> V_20 &&
V_14 -> V_23 == V_19 -> V_22 ;
}
static bool F_9 ( struct V_13 * V_14 ,
struct V_24 * V_25 )
{
if ( F_8 ( V_14 , V_25 ) ) {
if ( ! V_25 -> V_26 ) {
V_14 -> V_27 = V_28 ;
V_14 -> V_26 = 0 ;
} else {
V_14 -> V_27 = V_29 ;
V_14 -> V_26 = - V_30 ;
}
V_14 -> V_31 = 0 ;
return true ;
}
return false ;
}
void F_10 ( struct V_1 * V_2 )
{
V_2 -> V_32 = 0 ;
V_2 -> V_33 = V_34 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_35 ;
if ( V_2 -> V_33 > V_36 )
return 0 ;
F_12 ( & V_2 -> V_37 ) ;
V_35 = F_13 ( V_2 -> V_38 ,
V_2 -> V_33 == V_34 ||
V_2 -> V_33 >= V_39 ,
F_14 ( V_40 ) ) ;
F_15 ( & V_2 -> V_37 ) ;
if ( V_35 <= 0 && ( V_2 -> V_33 <= V_36 ) ) {
V_2 -> V_33 = V_34 ;
F_6 ( & V_2 -> V_10 -> V_2 , L_3 ) ;
return - V_41 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = & V_2 -> V_44 . V_45 ;
struct V_46 * V_47 ;
const T_2 V_17 = sizeof( struct V_46 ) ;
int V_35 ;
F_17 ( V_43 , V_17 ) ;
V_47 = (struct V_46 * ) V_2 -> V_44 . V_48 ;
memset ( V_47 , 0 , V_17 ) ;
V_47 -> V_15 = V_49 ;
V_47 -> V_50 . V_51 = V_52 ;
V_47 -> V_50 . V_53 = V_54 ;
V_2 -> V_33 = V_34 ;
V_35 = F_18 ( V_2 , V_43 , V_2 -> V_44 . V_48 ) ;
if ( V_35 ) {
F_6 ( & V_2 -> V_10 -> V_2 , L_4 ,
V_35 ) ;
return V_35 ;
}
V_2 -> V_33 = V_36 ;
V_2 -> V_32 = V_55 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = & V_2 -> V_44 . V_45 ;
struct V_56 * V_57 ;
const T_2 V_17 = sizeof( struct V_56 ) ;
int V_35 ;
F_17 ( V_43 , V_17 ) ;
V_57 = (struct V_56 * ) V_2 -> V_44 . V_48 ;
memset ( V_57 , 0 , V_17 ) ;
V_57 -> V_15 = V_58 ;
V_35 = F_18 ( V_2 , V_43 , V_2 -> V_44 . V_48 ) ;
if ( V_35 ) {
F_6 ( & V_2 -> V_10 -> V_2 , L_5 ,
V_35 ) ;
return V_35 ;
}
V_2 -> V_33 = V_59 ;
V_2 -> V_32 = V_55 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = & V_2 -> V_44 . V_45 ;
struct V_60 * V_61 ;
const T_2 V_17 = sizeof( struct V_60 ) ;
unsigned long V_62 ;
unsigned long V_63 ;
int V_35 ;
V_63 = V_2 -> V_7 ;
V_62 = F_21 ( V_2 -> V_64 , V_65 ,
V_2 -> V_8 ) ;
if ( V_62 == V_65 ) {
V_2 -> V_33 = V_39 ;
F_22 ( & V_2 -> V_66 ) ;
return 0 ;
}
V_2 -> V_9 [ V_63 ] . V_67 = V_62 ;
V_2 -> V_9 [ V_63 ] . V_68 = 0 ;
F_17 ( V_43 , V_17 ) ;
V_61 = (struct V_60 * ) V_2 -> V_44 . V_48 ;
memset ( V_61 , 0 , sizeof( struct V_60 ) ) ;
V_61 -> V_15 = V_69 ;
V_61 -> V_70 = V_62 ;
V_35 = F_18 ( V_2 , V_43 , V_2 -> V_44 . V_48 ) ;
if ( V_35 ) {
F_6 ( & V_2 -> V_10 -> V_2 , L_6 ,
V_35 ) ;
return V_35 ;
}
V_2 -> V_32 = V_55 ;
V_2 -> V_8 = V_62 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_42 * V_43 , unsigned char * V_48 )
{
struct V_71 * V_72 =
(struct V_71 * ) V_48 ;
const T_2 V_17 = sizeof( struct V_71 ) ;
F_17 ( V_43 , V_17 ) ;
memset ( V_72 , 0 , V_17 ) ;
V_72 -> V_15 = V_73 ;
V_72 -> V_74 = V_75 ;
}
int F_24 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_42 * V_43 = & V_2 -> V_44 . V_45 ;
const T_2 V_17 = sizeof( struct V_76 ) ;
F_17 ( V_43 , V_17 ) ;
F_7 ( V_14 , V_77 , V_2 -> V_44 . V_48 , V_17 ) ;
F_4 ( & V_2 -> V_10 -> V_2 , L_7 ,
V_14 -> V_21 , V_14 -> V_23 ) ;
return F_18 ( V_2 , V_43 , V_2 -> V_44 . V_48 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_76 * V_78 )
{
struct V_3 * V_79 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_2 -> V_6 ; V_80 ++ ) {
V_79 = & V_2 -> V_9 [ V_80 ] ;
if ( V_79 && V_78 -> V_22 == V_79 -> V_67 ) {
if ( V_79 -> V_81 . V_82 ) {
V_79 -> V_68 ++ ;
F_4 ( & V_2 -> V_10 -> V_2 , L_8 ,
V_78 -> V_22 ) ;
F_4 ( & V_2 -> V_10 -> V_2 , L_9 ,
V_79 -> V_68 ) ;
} else {
F_26 () ;
}
}
}
}
static void F_27 ( struct V_1 * V_2 ,
struct V_76 * V_83 )
{
struct V_13 * V_14 = NULL ;
struct V_13 * V_84 = NULL ;
if ( ! V_83 -> V_20 ) {
F_25 ( V_2 , V_83 ) ;
return;
}
F_28 (cl, next, &dev->file_list, link) {
if ( F_8 ( V_14 , V_83 ) ) {
V_14 -> V_68 ++ ;
F_4 ( & V_2 -> V_10 -> V_2 , L_10 ,
V_83 -> V_20 , V_83 -> V_22 ) ;
F_4 ( & V_2 -> V_10 -> V_2 , L_11 ,
V_14 -> V_68 ) ;
break;
}
}
}
int F_29 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_42 * V_43 = & V_2 -> V_44 . V_45 ;
const T_2 V_17 = sizeof( struct V_85 ) ;
F_17 ( V_43 , V_17 ) ;
F_7 ( V_14 , V_86 , V_2 -> V_44 . V_48 , V_17 ) ;
return F_18 ( V_2 , V_43 , V_2 -> V_44 . V_48 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_87 * V_88 = NULL , * V_84 = NULL ;
F_4 ( & V_2 -> V_10 -> V_2 ,
L_12
L_13
L_14
L_15 ,
V_25 -> V_22 ,
V_25 -> V_20 ,
V_25 -> V_26 ) ;
F_28 (pos, next, &dev->ctrl_rd_list.list, list) {
V_14 = V_88 -> V_14 ;
if ( ! V_14 ) {
F_31 ( & V_88 -> V_89 ) ;
return;
}
F_4 ( & V_2 -> V_10 -> V_2 , L_16 ) ;
if ( F_8 ( V_14 , V_25 ) ) {
F_31 ( & V_88 -> V_89 ) ;
if ( ! V_25 -> V_26 )
V_14 -> V_27 = V_29 ;
V_14 -> V_26 = 0 ;
V_14 -> V_31 = 0 ;
break;
}
}
}
int F_32 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_42 * V_43 = & V_2 -> V_44 . V_45 ;
const T_2 V_17 = sizeof( struct V_85 ) ;
F_17 ( V_43 , V_17 ) ;
F_7 ( V_14 , V_90 , V_2 -> V_44 . V_48 , V_17 ) ;
return F_18 ( V_2 , V_43 , V_2 -> V_44 . V_48 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_87 * V_88 = NULL , * V_84 = NULL ;
F_4 ( & V_2 -> V_10 -> V_2 ,
L_17
L_13
L_14
L_15 ,
V_25 -> V_22 ,
V_25 -> V_20 ,
V_25 -> V_26 ) ;
if ( F_9 ( & V_2 -> V_91 , V_25 ) ) {
F_4 ( & V_2 -> V_10 -> V_2 , L_18 ) ;
F_34 ( V_2 ) ;
return;
}
if ( F_9 ( & V_2 -> V_92 , V_25 ) ) {
V_2 -> V_93 = V_94 ;
return;
}
F_28 (pos, next, &dev->ctrl_rd_list.list, list) {
V_14 = V_88 -> V_14 ;
if ( ! V_14 ) {
F_31 ( & V_88 -> V_89 ) ;
return;
}
if ( V_88 -> V_95 == V_96 ) {
if ( F_9 ( V_14 , V_25 ) ) {
F_31 ( & V_88 -> V_89 ) ;
V_14 -> V_26 = 0 ;
V_14 -> V_31 = 0 ;
break;
}
}
}
}
static void F_35 ( struct V_1 * V_2 ,
struct V_85 * V_97 )
{
struct V_13 * V_14 , * V_84 ;
const T_2 V_17 = sizeof( struct V_24 ) ;
F_28 (cl, next, &dev->file_list, link) {
if ( F_8 ( V_14 , V_97 ) ) {
F_4 ( & V_2 -> V_10 -> V_2 , L_19 ,
V_97 -> V_20 ,
V_97 -> V_22 ) ;
V_14 -> V_27 = V_29 ;
V_14 -> V_31 = 0 ;
if ( V_14 == & V_2 -> V_91 )
V_2 -> V_98 = false ;
else if ( V_14 == & V_2 -> V_92 )
V_2 -> V_99 = 0 ;
F_17 ( & V_2 -> V_100 . V_45 , V_17 ) ;
F_7 ( V_14 , V_101 ,
V_2 -> V_100 . V_48 , V_17 ) ;
break;
}
}
}
bool F_36 ( struct V_1 * V_2 )
{
return ( V_2 -> V_102 . V_51 < V_52 ) ||
( V_2 -> V_102 . V_51 == V_52 &&
V_2 -> V_102 . V_53 <= V_54 ) ;
}
int F_37 ( struct V_1 * V_2 , struct V_42 * V_45 )
{
struct V_103 * V_104 ;
struct V_3 * V_105 ;
struct V_106 * V_107 ;
struct V_24 * V_108 ;
struct V_24 * V_109 ;
struct V_85 * V_97 ;
struct V_76 * V_83 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
F_38 ( V_45 -> V_114 >= sizeof( V_2 -> V_115 ) ) ;
F_39 ( V_2 , V_2 -> V_115 , V_45 -> V_114 ) ;
V_104 = (struct V_103 * ) V_2 -> V_115 ;
if ( V_2 -> V_33 == V_34 ) {
F_4 ( & V_2 -> V_10 -> V_2 , L_20 ) ;
return 0 ;
}
switch ( V_104 -> V_15 ) {
case V_116 :
F_4 ( & V_2 -> V_10 -> V_2 , L_21 ) ;
V_2 -> V_32 = 0 ;
V_107 = (struct V_106 * ) V_104 ;
F_4 ( & V_2 -> V_10 -> V_2 , L_22 ,
V_52 , V_54 ,
V_107 -> V_117 . V_51 ,
V_107 -> V_117 . V_53 ) ;
if ( V_107 -> V_118 ) {
V_2 -> V_102 . V_51 = V_52 ;
V_2 -> V_102 . V_53 = V_54 ;
} else {
V_2 -> V_102 . V_51 =
V_107 -> V_117 . V_51 ;
V_2 -> V_102 . V_53 =
V_107 -> V_117 . V_53 ;
}
if ( ! F_36 ( V_2 ) ) {
F_40 ( & V_2 -> V_10 -> V_2 , L_23 ) ;
V_2 -> V_33 = V_119 ;
F_23 ( V_2 , & V_2 -> V_44 . V_45 ,
V_2 -> V_44 . V_48 ) ;
if ( F_18 ( V_2 , & V_2 -> V_44 . V_45 ,
V_2 -> V_44 . V_48 ) ) {
F_6 ( & V_2 -> V_10 -> V_2 , L_24 ) ;
return - V_120 ;
}
break;
}
if ( V_2 -> V_121 != V_122 ||
V_2 -> V_33 != V_36 ) {
F_6 ( & V_2 -> V_10 -> V_2 , L_25 ,
V_2 -> V_121 , V_2 -> V_33 ) ;
return - V_123 ;
}
V_2 -> V_33 = V_39 ;
if ( F_19 ( V_2 ) ) {
F_6 ( & V_2 -> V_10 -> V_2 , L_26 ) ;
return - V_120 ;
}
F_41 ( & V_2 -> V_38 ) ;
break;
case V_124 :
F_4 ( & V_2 -> V_10 -> V_2 , L_27 ) ;
V_108 = (struct V_24 * ) V_104 ;
F_33 ( V_2 , V_108 ) ;
F_42 ( & V_2 -> V_38 ) ;
break;
case V_101 :
F_4 ( & V_2 -> V_10 -> V_2 , L_28 ) ;
V_109 = (struct V_24 * ) V_104 ;
F_30 ( V_2 , V_109 ) ;
F_42 ( & V_2 -> V_38 ) ;
break;
case V_77 :
F_4 ( & V_2 -> V_10 -> V_2 , L_29 ) ;
V_83 = (struct V_76 * ) V_104 ;
F_27 ( V_2 , V_83 ) ;
break;
case V_125 :
F_4 ( & V_2 -> V_10 -> V_2 , L_30 ) ;
V_2 -> V_32 = 0 ;
if ( V_2 -> V_9 == NULL ) {
F_6 ( & V_2 -> V_10 -> V_2 , L_31 ) ;
return - V_123 ;
}
V_111 = (struct V_110 * ) V_104 ;
V_105 = & V_2 -> V_9 [ V_2 -> V_7 ] ;
if ( V_111 -> V_26 ) {
F_6 ( & V_2 -> V_10 -> V_2 , L_32 ,
V_111 -> V_26 ) ;
return - V_123 ;
}
if ( V_105 -> V_67 != V_111 -> V_70 ) {
F_6 ( & V_2 -> V_10 -> V_2 , L_33 ,
V_105 -> V_67 , V_111 -> V_70 ) ;
return - V_123 ;
}
if ( V_2 -> V_121 != V_122 ||
V_2 -> V_33 != V_126 ) {
F_6 ( & V_2 -> V_10 -> V_2 , L_34 ,
V_2 -> V_121 , V_2 -> V_33 ) ;
return - V_123 ;
}
V_105 -> V_81 = V_111 -> V_127 ;
V_2 -> V_8 ++ ;
V_2 -> V_7 ++ ;
if ( F_20 ( V_2 ) )
return - V_120 ;
break;
case V_128 :
F_4 ( & V_2 -> V_10 -> V_2 , L_35 ) ;
V_2 -> V_32 = 0 ;
V_113 = (struct V_112 * ) V_104 ;
F_43 ( sizeof( V_2 -> V_64 )
< sizeof( V_113 -> V_129 ) ) ;
memcpy ( V_2 -> V_64 , V_113 -> V_129 ,
sizeof( V_113 -> V_129 ) ) ;
if ( V_2 -> V_121 != V_122 ||
V_2 -> V_33 != V_59 ) {
F_6 ( & V_2 -> V_10 -> V_2 , L_36 ,
V_2 -> V_121 , V_2 -> V_33 ) ;
return - V_123 ;
}
if ( F_1 ( V_2 ) ) {
F_6 ( & V_2 -> V_10 -> V_2 , L_37 ) ;
return - V_12 ;
}
V_2 -> V_33 = V_126 ;
if ( F_20 ( V_2 ) )
return - V_120 ;
break;
case V_130 :
F_4 ( & V_2 -> V_10 -> V_2 , L_38 ) ;
V_2 -> V_32 = 0 ;
if ( V_2 -> V_33 != V_119 ) {
F_6 ( & V_2 -> V_10 -> V_2 , L_39 ,
V_2 -> V_121 , V_2 -> V_33 ) ;
return - V_123 ;
}
V_2 -> V_121 = V_131 ;
F_44 ( & V_2 -> V_10 -> V_2 , L_40 ) ;
return - V_123 ;
break;
case V_86 :
F_4 ( & V_2 -> V_10 -> V_2 , L_41 ) ;
V_97 = (struct V_85 * ) V_104 ;
F_35 ( V_2 , V_97 ) ;
break;
case V_132 :
F_4 ( & V_2 -> V_10 -> V_2 , L_42 ) ;
V_2 -> V_33 = V_119 ;
F_23 ( V_2 , & V_2 -> V_100 . V_45 ,
V_2 -> V_100 . V_48 ) ;
break;
default:
F_26 () ;
break;
}
return 0 ;
}
