static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
F_2 (b, dev->me_clients_map, MEI_CLIENTS_MAX)
V_2 -> V_6 ++ ;
if ( V_2 -> V_6 <= 0 )
return;
F_3 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
F_4 ( & V_2 -> V_8 -> V_2 , L_1 ,
V_2 -> V_6 * sizeof( struct V_3 ) ) ;
V_4 = F_5 ( V_2 -> V_6 ,
sizeof( struct V_3 ) , V_9 ) ;
if ( ! V_4 ) {
F_6 ( & V_2 -> V_8 -> V_2 , L_2 ) ;
V_2 -> V_10 = V_11 ;
F_7 ( V_2 , 1 ) ;
return;
}
V_2 -> V_7 = V_4 ;
return;
}
static inline
void F_8 ( struct V_12 * V_13 , T_1 V_14 , void * V_15 , T_2 V_16 )
{
struct V_17 * V_18 = V_15 ;
memset ( V_18 , 0 , V_16 ) ;
V_18 -> V_14 = V_14 ;
V_18 -> V_19 = V_13 -> V_20 ;
V_18 -> V_21 = V_13 -> V_22 ;
}
static inline
bool F_9 ( struct V_12 * V_13 , void * V_15 )
{
struct V_17 * V_18 = V_15 ;
return V_13 -> V_20 == V_18 -> V_19 &&
V_13 -> V_22 == V_18 -> V_21 ;
}
static bool F_10 ( struct V_12 * V_13 ,
struct V_23 * V_24 )
{
if ( F_9 ( V_13 , V_24 ) ) {
if ( ! V_24 -> V_25 ) {
V_13 -> V_26 = V_27 ;
V_13 -> V_25 = 0 ;
} else {
V_13 -> V_26 = V_28 ;
V_13 -> V_25 = - V_29 ;
}
V_13 -> V_30 = 0 ;
return true ;
}
return false ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_33 . V_34 ;
struct V_35 * V_36 ;
const T_2 V_16 = sizeof( struct V_35 ) ;
F_12 ( V_32 , V_16 ) ;
V_36 = (struct V_35 * ) V_2 -> V_33 . V_37 ;
memset ( V_36 , 0 , V_16 ) ;
V_36 -> V_14 = V_38 ;
V_36 -> V_39 . V_40 = V_41 ;
V_36 -> V_39 . V_42 = V_43 ;
V_2 -> V_44 = false ;
if ( F_13 ( V_2 , V_32 , V_2 -> V_33 . V_37 ) ) {
F_4 ( & V_2 -> V_8 -> V_2 , L_3 ) ;
V_2 -> V_10 = V_11 ;
F_7 ( V_2 , 1 ) ;
}
V_2 -> V_45 = V_46 ;
V_2 -> V_47 = V_48 ;
return ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_33 . V_34 ;
struct V_49 * V_50 ;
const T_2 V_16 = sizeof( struct V_49 ) ;
F_12 ( V_32 , V_16 ) ;
V_50 = (struct V_49 * ) V_2 -> V_33 . V_37 ;
memset ( V_50 , 0 , V_16 ) ;
V_50 -> V_14 = V_51 ;
if ( F_13 ( V_2 , V_32 , V_2 -> V_33 . V_37 ) ) {
V_2 -> V_10 = V_11 ;
F_4 ( & V_2 -> V_8 -> V_2 , L_4 ) ;
F_7 ( V_2 , 1 ) ;
}
V_2 -> V_45 = V_52 ;
V_2 -> V_47 = V_48 ;
return;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_33 . V_34 ;
struct V_53 * V_54 ;
const T_2 V_16 = sizeof( struct V_53 ) ;
unsigned long V_55 ;
T_1 V_56 ;
V_56 = V_2 -> V_57 ;
V_55 = F_16 ( V_2 -> V_58 , V_59 ,
V_2 -> V_60 ) ;
if ( V_55 == V_59 ) {
F_17 ( & V_2 -> V_61 ) ;
return 0 ;
}
V_2 -> V_7 [ V_56 ] . V_62 = V_55 ;
V_2 -> V_7 [ V_56 ] . V_63 = 0 ;
F_12 ( V_32 , V_16 ) ;
V_54 = (struct V_53 * ) V_2 -> V_33 . V_37 ;
memset ( V_54 , 0 , sizeof( struct V_53 ) ) ;
V_54 -> V_14 = V_64 ;
V_54 -> V_65 = V_55 ;
if ( F_13 ( V_2 , V_32 , V_2 -> V_33 . V_37 ) ) {
V_2 -> V_10 = V_11 ;
F_6 ( & V_2 -> V_8 -> V_2 , L_5 ) ;
F_7 ( V_2 , 1 ) ;
return - V_66 ;
}
V_2 -> V_47 = V_48 ;
V_2 -> V_60 = V_55 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_31 * V_32 , unsigned char * V_37 )
{
struct V_67 * V_68 =
(struct V_67 * ) V_37 ;
const T_2 V_16 = sizeof( struct V_67 ) ;
F_12 ( V_32 , V_16 ) ;
memset ( V_68 , 0 , V_16 ) ;
V_68 -> V_14 = V_69 ;
V_68 -> V_70 = V_71 ;
}
int F_19 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_31 * V_32 = & V_2 -> V_33 . V_34 ;
const T_2 V_16 = sizeof( struct V_72 ) ;
F_12 ( V_32 , V_16 ) ;
F_8 ( V_13 , V_73 , V_2 -> V_33 . V_37 , V_16 ) ;
F_4 ( & V_2 -> V_8 -> V_2 , L_6 ,
V_13 -> V_20 , V_13 -> V_22 ) ;
return F_13 ( V_2 , V_32 , V_2 -> V_33 . V_37 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_72 * V_74 )
{
struct V_3 * V_75 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_2 -> V_6 ; V_76 ++ ) {
V_75 = & V_2 -> V_7 [ V_76 ] ;
if ( V_75 && V_74 -> V_21 == V_75 -> V_62 ) {
if ( V_75 -> V_77 . V_78 ) {
V_75 -> V_63 ++ ;
F_4 ( & V_2 -> V_8 -> V_2 , L_7 ,
V_74 -> V_21 ) ;
F_4 ( & V_2 -> V_8 -> V_2 , L_8 ,
V_75 -> V_63 ) ;
} else {
F_21 () ;
}
}
}
}
static void F_22 ( struct V_1 * V_2 ,
struct V_72 * V_79 )
{
struct V_12 * V_13 = NULL ;
struct V_12 * V_80 = NULL ;
if ( ! V_79 -> V_19 ) {
F_20 ( V_2 , V_79 ) ;
return;
}
F_23 (cl, next, &dev->file_list, link) {
if ( F_9 ( V_13 , V_79 ) ) {
V_13 -> V_63 ++ ;
F_4 ( & V_2 -> V_8 -> V_2 , L_9 ,
V_79 -> V_19 , V_79 -> V_21 ) ;
F_4 ( & V_2 -> V_8 -> V_2 , L_10 ,
V_13 -> V_63 ) ;
break;
}
}
}
int F_24 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_31 * V_32 = & V_2 -> V_33 . V_34 ;
const T_2 V_16 = sizeof( struct V_81 ) ;
F_12 ( V_32 , V_16 ) ;
F_8 ( V_13 , V_82 , V_2 -> V_33 . V_37 , V_16 ) ;
return F_13 ( V_2 , V_32 , V_2 -> V_33 . V_37 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_12 * V_13 ;
struct V_83 * V_84 = NULL , * V_80 = NULL ;
F_4 ( & V_2 -> V_8 -> V_2 ,
L_11
L_12
L_13
L_14 ,
V_24 -> V_21 ,
V_24 -> V_19 ,
V_24 -> V_25 ) ;
F_23 (pos, next, &dev->ctrl_rd_list.list, list) {
V_13 = V_84 -> V_13 ;
if ( ! V_13 ) {
F_26 ( & V_84 -> V_85 ) ;
return;
}
F_4 ( & V_2 -> V_8 -> V_2 , L_15 ) ;
if ( F_9 ( V_13 , V_24 ) ) {
F_26 ( & V_84 -> V_85 ) ;
if ( ! V_24 -> V_25 )
V_13 -> V_26 = V_28 ;
V_13 -> V_25 = 0 ;
V_13 -> V_30 = 0 ;
break;
}
}
}
int F_27 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_31 * V_32 = & V_2 -> V_33 . V_34 ;
const T_2 V_16 = sizeof( struct V_81 ) ;
F_12 ( V_32 , V_16 ) ;
F_8 ( V_13 , V_86 , V_2 -> V_33 . V_37 , V_16 ) ;
return F_13 ( V_2 , V_32 , V_2 -> V_33 . V_37 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_12 * V_13 ;
struct V_83 * V_84 = NULL , * V_80 = NULL ;
F_4 ( & V_2 -> V_8 -> V_2 ,
L_16
L_12
L_13
L_14 ,
V_24 -> V_21 ,
V_24 -> V_19 ,
V_24 -> V_25 ) ;
if ( F_10 ( & V_2 -> V_87 , V_24 ) ) {
F_4 ( & V_2 -> V_8 -> V_2 , L_17 ) ;
F_29 ( V_2 ) ;
return;
}
if ( F_10 ( & V_2 -> V_88 , V_24 ) ) {
V_2 -> V_89 = V_90 ;
return;
}
F_23 (pos, next, &dev->ctrl_rd_list.list, list) {
V_13 = V_84 -> V_13 ;
if ( ! V_13 ) {
F_26 ( & V_84 -> V_85 ) ;
return;
}
if ( V_84 -> V_91 == V_92 ) {
if ( F_10 ( V_13 , V_24 ) ) {
F_26 ( & V_84 -> V_85 ) ;
V_13 -> V_25 = 0 ;
V_13 -> V_30 = 0 ;
break;
}
}
}
}
static void F_30 ( struct V_1 * V_2 ,
struct V_81 * V_93 )
{
struct V_12 * V_13 , * V_80 ;
const T_2 V_16 = sizeof( struct V_23 ) ;
F_23 (cl, next, &dev->file_list, link) {
if ( F_9 ( V_13 , V_93 ) ) {
F_4 ( & V_2 -> V_8 -> V_2 , L_18 ,
V_93 -> V_19 ,
V_93 -> V_21 ) ;
V_13 -> V_26 = V_28 ;
V_13 -> V_30 = 0 ;
if ( V_13 == & V_2 -> V_87 )
V_2 -> V_94 = false ;
else if ( V_13 == & V_2 -> V_88 )
V_2 -> V_95 = 0 ;
F_12 ( & V_2 -> V_96 . V_34 , V_16 ) ;
F_8 ( V_13 , V_97 ,
V_2 -> V_96 . V_37 , V_16 ) ;
break;
}
}
}
void F_31 ( struct V_1 * V_2 , struct V_31 * V_34 )
{
struct V_98 * V_99 ;
struct V_3 * V_100 ;
struct V_101 * V_102 ;
struct V_23 * V_103 ;
struct V_23 * V_104 ;
struct V_81 * V_93 ;
struct V_72 * V_79 ;
struct V_105 * V_106 ;
struct V_107 * V_108 ;
F_32 ( V_34 -> V_109 >= sizeof( V_2 -> V_110 ) ) ;
F_33 ( V_2 , V_2 -> V_110 , V_34 -> V_109 ) ;
V_99 = (struct V_98 * ) V_2 -> V_110 ;
switch ( V_99 -> V_14 ) {
case V_111 :
V_102 = (struct V_101 * ) V_99 ;
if ( ! V_102 -> V_112 ) {
V_2 -> V_113 = V_102 -> V_114 ;
F_4 ( & V_2 -> V_8 -> V_2 , L_19 ) ;
F_18 ( V_2 , & V_2 -> V_33 . V_34 ,
V_2 -> V_33 . V_37 ) ;
F_13 ( V_2 , & V_2 -> V_33 . V_34 ,
V_2 -> V_33 . V_37 ) ;
return;
}
V_2 -> V_113 . V_40 = V_41 ;
V_2 -> V_113 . V_42 = V_43 ;
if ( V_2 -> V_10 == V_115 &&
V_2 -> V_45 == V_46 ) {
V_2 -> V_47 = 0 ;
F_14 ( V_2 ) ;
} else {
V_2 -> V_44 = false ;
F_4 ( & V_2 -> V_8 -> V_2 , L_20 ) ;
F_7 ( V_2 , 1 ) ;
return;
}
V_2 -> V_44 = true ;
F_4 ( & V_2 -> V_8 -> V_2 , L_21 ) ;
break;
case V_116 :
V_103 = (struct V_23 * ) V_99 ;
F_28 ( V_2 , V_103 ) ;
F_4 ( & V_2 -> V_8 -> V_2 , L_22 ) ;
F_34 ( & V_2 -> V_117 ) ;
break;
case V_97 :
V_104 = (struct V_23 * ) V_99 ;
F_25 ( V_2 , V_104 ) ;
F_4 ( & V_2 -> V_8 -> V_2 , L_23 ) ;
F_34 ( & V_2 -> V_117 ) ;
break;
case V_73 :
V_79 = (struct V_72 * ) V_99 ;
F_22 ( V_2 , V_79 ) ;
F_4 ( & V_2 -> V_8 -> V_2 , L_24 ) ;
break;
case V_118 :
V_106 = (struct V_105 * ) V_99 ;
V_100 = & V_2 -> V_7 [ V_2 -> V_57 ] ;
if ( V_106 -> V_25 || ! V_2 -> V_7 ) {
F_4 ( & V_2 -> V_8 -> V_2 , L_25 ) ;
F_7 ( V_2 , 1 ) ;
return;
}
if ( V_100 -> V_62 != V_106 -> V_65 ) {
F_6 ( & V_2 -> V_8 -> V_2 ,
L_26 ) ;
F_7 ( V_2 , 1 ) ;
return;
}
if ( V_2 -> V_10 != V_115 ||
V_2 -> V_45 != V_119 ) {
F_6 ( & V_2 -> V_8 -> V_2 ,
L_27 ) ;
F_7 ( V_2 , 1 ) ;
return;
}
V_100 -> V_77 = V_106 -> V_120 ;
V_2 -> V_60 ++ ;
V_2 -> V_57 ++ ;
F_15 ( V_2 ) ;
break;
case V_121 :
V_108 = (struct V_107 * ) V_99 ;
memcpy ( V_2 -> V_58 , V_108 -> V_122 , 32 ) ;
if ( V_2 -> V_10 == V_115 &&
V_2 -> V_45 == V_52 ) {
V_2 -> V_47 = 0 ;
V_2 -> V_57 = 0 ;
V_2 -> V_60 = 0 ;
F_1 ( V_2 ) ;
V_2 -> V_45 =
V_119 ;
F_15 ( V_2 ) ;
} else {
F_4 ( & V_2 -> V_8 -> V_2 , L_28 ) ;
F_7 ( V_2 , 1 ) ;
return;
}
break;
case V_123 :
V_2 -> V_10 = V_124 ;
F_4 ( & V_2 -> V_8 -> V_2 , L_29 ) ;
F_7 ( V_2 , 1 ) ;
break;
case V_82 :
V_93 = (struct V_81 * ) V_99 ;
F_30 ( V_2 , V_93 ) ;
break;
case V_125 :
F_18 ( V_2 , & V_2 -> V_96 . V_34 ,
V_2 -> V_96 . V_37 ) ;
break;
default:
F_21 () ;
break;
}
}
