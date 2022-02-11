int F_1 ( T_1 V_1 )
{
int V_2 = 0 ;
if ( F_2 ( V_1 ) )
return - V_3 ;
F_3 ( & V_4 ) ;
if ( F_4 ( & V_5 . V_6 ) == 0 ) {
V_7 = F_5 ( V_8 *
sizeof( struct V_9 ) , V_10 ) ;
if ( ! V_7 ) {
V_2 = - V_11 ;
F_6 ( L_1 , V_12 ) ;
goto V_13;
}
V_14 = F_5 ( V_15 *
sizeof( struct V_9 ) , V_10 ) ;
if ( ! V_14 ) {
F_7 ( V_7 ) ;
V_2 = - V_11 ;
F_6 ( L_2 , V_12 ) ;
goto V_13;
}
}
F_8 ( & V_5 . V_6 ) ;
V_13:
F_9 ( & V_4 ) ;
if ( ! V_2 ) {
F_10 ( V_1 , 1 ) ;
F_11 ( L_3 ,
V_12 ) ;
}
return V_2 ;
}
int F_12 ( T_1 V_1 )
{
if ( ! F_2 ( V_1 ) )
return - V_3 ;
F_3 ( & V_4 ) ;
if ( F_4 ( & V_5 . V_6 ) == 0 ) {
F_9 ( & V_4 ) ;
F_6 ( L_4 , V_12 ) ;
return - V_3 ;
}
if ( F_13 ( & V_5 . V_6 ) ) {
F_14 () ;
F_15 () ;
F_11 ( L_5 , V_12 ) ;
}
F_9 ( & V_4 ) ;
F_10 ( V_1 , 0 ) ;
return 0 ;
}
int F_16 ( struct V_16 * V_17 ,
struct V_16 * V_18 ,
T_1 V_1 )
{
struct V_9 * V_19 ;
struct V_20 * V_21 ;
unsigned long V_22 ;
int V_2 = - V_3 ;
if ( ! F_2 ( V_1 ) )
return V_2 ;
V_21 = F_5 ( sizeof( struct V_20 ) , V_10 ) ;
if ( ! V_21 ) {
F_6 ( L_6 , V_12 ) ;
return - V_11 ;
}
memcpy ( & V_21 -> V_17 , V_17 ,
sizeof( struct V_16 ) ) ;
memcpy ( & V_21 -> V_18 , V_18 ,
sizeof( struct V_16 ) ) ;
V_21 -> V_1 = V_1 ;
F_17 ( & V_23 , V_22 ) ;
if ( V_7 ) {
V_19 = F_18 (
& V_21 -> V_17 ,
& V_21 -> V_18 ) ;
if ( V_19 ) {
F_19 ( & V_21 -> V_24 , V_19 ) ;
V_2 = 0 ;
}
}
F_20 ( & V_23 , V_22 ) ;
return V_2 ;
}
int F_21 ( struct V_16 * V_17 ,
struct V_16 * V_25 )
{
struct V_24 * V_26 ;
struct V_9 * V_19 ;
struct V_20 * V_21 = NULL ;
unsigned long V_22 ;
int V_2 = - V_3 ;
F_17 ( & V_23 , V_22 ) ;
if ( V_7 ) {
V_19 = F_18 (
V_17 ,
V_25 ) ;
if ( ! V_19 )
goto V_27;
F_22 (map_info, tmp_hlist_node,
hash_bucket_head, hlist_node) {
if ( ! F_23 ( & V_21 -> V_18 ,
V_25 ) ) {
F_24 ( & V_21 -> V_24 ) ;
F_7 ( V_21 ) ;
V_2 = 0 ;
break;
}
}
}
V_27:
F_20 ( & V_23 , V_22 ) ;
return V_2 ;
}
static void F_14 ( void )
{
struct V_24 * V_26 ;
struct V_20 * V_21 ;
unsigned long V_22 ;
int V_28 ;
F_17 ( & V_23 , V_22 ) ;
for ( V_28 = 0 ; V_28 < V_8 ; V_28 ++ ) {
F_22 (map_info, tmp_hlist_node,
&iwpm_hash_bucket[i], hlist_node) {
F_24 ( & V_21 -> V_24 ) ;
F_7 ( V_21 ) ;
}
}
F_7 ( V_7 ) ;
V_7 = NULL ;
F_20 ( & V_23 , V_22 ) ;
}
static void F_15 ( void )
{
struct V_24 * V_26 ;
struct V_29 * V_30 ;
unsigned long V_22 ;
int V_28 ;
F_17 ( & V_31 , V_22 ) ;
for ( V_28 = 0 ; V_28 < V_15 ; V_28 ++ ) {
F_22 (rem_info, tmp_hlist_node,
&iwpm_reminfo_bucket[i], hlist_node) {
F_24 ( & V_30 -> V_24 ) ;
F_7 ( V_30 ) ;
}
}
F_7 ( V_14 ) ;
V_14 = NULL ;
F_20 ( & V_31 , V_22 ) ;
}
void F_25 ( struct V_29 * V_30 )
{
struct V_9 * V_19 ;
unsigned long V_22 ;
F_17 ( & V_31 , V_22 ) ;
if ( V_14 ) {
V_19 = F_26 (
& V_30 -> V_32 ,
& V_30 -> V_33 ) ;
if ( V_19 )
F_19 ( & V_30 -> V_24 , V_19 ) ;
}
F_20 ( & V_31 , V_22 ) ;
}
int F_27 ( struct V_16 * V_34 ,
struct V_16 * V_35 ,
struct V_16 * V_36 ,
T_1 V_1 )
{
struct V_24 * V_26 ;
struct V_9 * V_19 ;
struct V_29 * V_30 = NULL ;
unsigned long V_22 ;
int V_2 = - V_3 ;
if ( ! F_2 ( V_1 ) ) {
F_28 ( L_7 , V_12 , V_1 ) ;
return V_2 ;
}
F_17 ( & V_31 , V_22 ) ;
if ( V_14 ) {
V_19 = F_26 (
V_34 ,
V_35 ) ;
if ( ! V_19 )
goto V_37;
F_22 (rem_info, tmp_hlist_node,
hash_bucket_head, hlist_node) {
if ( ! F_23 ( & V_30 -> V_32 ,
V_34 ) &&
! F_23 ( & V_30 -> V_33 ,
V_35 ) ) {
memcpy ( V_36 , & V_30 -> V_38 ,
sizeof( struct V_16 ) ) ;
F_29 ( V_36 ,
L_8 ) ;
F_24 ( & V_30 -> V_24 ) ;
F_7 ( V_30 ) ;
V_2 = 0 ;
break;
}
}
}
V_37:
F_20 ( & V_31 , V_22 ) ;
return V_2 ;
}
struct V_39 * F_30 ( T_2 V_40 ,
T_1 V_1 , T_3 V_41 )
{
struct V_39 * V_42 = NULL ;
unsigned long V_22 ;
V_42 = F_5 ( sizeof( struct V_39 ) , V_41 ) ;
if ( ! V_42 ) {
F_6 ( L_9 , V_12 ) ;
return NULL ;
}
F_17 ( & V_43 , V_22 ) ;
F_31 ( & V_42 -> V_44 , & V_45 ) ;
F_20 ( & V_43 , V_22 ) ;
F_32 ( & V_42 -> V_46 ) ;
F_33 ( & V_42 -> V_46 ) ;
V_42 -> V_40 = V_40 ;
V_42 -> V_1 = V_1 ;
V_42 -> V_47 = 0 ;
V_42 -> V_48 = 0 ;
return V_42 ;
}
void F_34 ( struct V_46 * V_46 )
{
struct V_39 * V_42 ;
unsigned long V_22 ;
V_42 = F_35 ( V_46 , struct V_39 , V_46 ) ;
F_17 ( & V_43 , V_22 ) ;
F_36 ( & V_42 -> V_44 ) ;
F_20 ( & V_43 , V_22 ) ;
if ( ! V_42 -> V_47 )
F_11 ( L_10 ,
V_12 , V_42 -> V_40 ) ;
F_7 ( V_42 ) ;
}
struct V_39 * F_37 ( T_2 V_49 )
{
struct V_39 * V_42 ;
struct V_39 * V_50 = NULL ;
unsigned long V_22 ;
F_17 ( & V_43 , V_22 ) ;
F_38 (nlmsg_request, &iwpm_nlmsg_req_list,
inprocess_list) {
if ( V_42 -> V_40 == V_49 ) {
V_50 = V_42 ;
F_33 ( & V_42 -> V_46 ) ;
break;
}
}
F_20 ( & V_43 , V_22 ) ;
return V_50 ;
}
int F_39 ( struct V_39 * V_42 )
{
int V_2 ;
F_40 ( & V_42 -> V_51 ) ;
V_2 = F_41 ( V_42 -> V_51 ,
( V_42 -> V_47 != 0 ) , V_52 ) ;
if ( ! V_2 ) {
V_2 = - V_3 ;
F_28 ( L_11 ,
V_12 , ( V_52 / V_53 ) , V_42 -> V_40 ) ;
} else {
V_2 = V_42 -> V_48 ;
}
F_42 ( & V_42 -> V_46 , F_34 ) ;
return V_2 ;
}
int F_43 ( void )
{
return F_44 ( & V_5 . V_40 ) ;
}
int F_2 ( T_1 V_1 )
{
if ( V_1 >= V_54 )
return 0 ;
return V_5 . V_55 [ V_1 ] ;
}
void F_10 ( T_1 V_1 , int V_56 )
{
if ( V_1 >= V_54 )
return;
V_5 . V_55 [ V_1 ] = V_56 ;
}
int F_45 ( T_1 V_1 )
{
return V_5 . V_57 [ V_1 ] ;
}
void F_46 ( T_1 V_1 , int V_58 )
{
V_5 . V_57 [ V_1 ] = V_58 ;
}
int F_23 ( struct V_16 * V_59 ,
struct V_16 * V_60 )
{
if ( V_59 -> V_61 != V_60 -> V_61 )
return 1 ;
if ( V_59 -> V_61 == V_62 ) {
struct V_63 * V_64 =
(struct V_63 * ) V_59 ;
struct V_63 * V_65 =
(struct V_63 * ) V_60 ;
if ( ! memcmp ( & V_64 -> V_66 ,
& V_65 -> V_66 , sizeof( struct V_67 ) )
&& V_64 -> V_68 == V_65 -> V_68 )
return 0 ;
} else if ( V_59 -> V_61 == V_69 ) {
struct V_70 * V_71 =
(struct V_70 * ) V_59 ;
struct V_70 * V_72 =
(struct V_70 * ) V_60 ;
if ( ! memcmp ( & V_71 -> V_73 ,
& V_72 -> V_73 , sizeof( struct V_74 ) )
&& V_71 -> V_75 == V_72 -> V_75 )
return 0 ;
} else {
F_6 ( L_12 , V_12 ) ;
}
return 1 ;
}
struct V_76 * F_47 ( T_4 V_77 , struct V_78 * * V_79 ,
int V_1 )
{
struct V_76 * V_80 = NULL ;
V_80 = F_48 ( V_81 ) ;
if ( ! V_80 ) {
F_6 ( L_13 , V_12 ) ;
goto V_82;
}
if ( ! ( F_49 ( V_80 , V_79 , 0 , 0 , V_1 , V_77 ,
V_83 ) ) ) {
F_50 ( L_14 , V_12 ) ;
F_51 ( V_80 ) ;
V_80 = NULL ;
}
V_82:
return V_80 ;
}
int F_52 ( struct V_84 * V_85 , int V_86 ,
const struct V_87 * V_88 ,
struct V_89 * V_90 [] , const char * V_91 )
{
int V_92 = 0 ;
int V_2 ;
const char * V_93 = L_15 ;
V_2 = F_53 ( V_85 -> V_79 , V_92 , V_86 - 1 , V_88 ) ;
if ( V_2 ) {
V_93 = L_16 ;
goto V_94;
}
V_2 = F_54 ( V_85 -> V_79 , V_92 , V_90 , V_86 - 1 , V_88 ) ;
if ( V_2 ) {
V_93 = L_17 ;
goto V_94;
}
V_2 = F_55 ( V_90 , V_86 ) ;
if ( V_2 ) {
V_93 = L_18 ;
goto V_94;
}
return 0 ;
V_94:
F_50 ( L_19 ,
V_12 , V_93 , V_91 , V_2 ) ;
return V_2 ;
}
void F_29 ( struct V_16 * V_95 , char * V_96 )
{
struct V_70 * V_97 ;
struct V_63 * V_98 ;
switch ( V_95 -> V_61 ) {
case V_62 :
V_98 = (struct V_63 * ) V_95 ;
F_11 ( L_20 ,
V_96 , & V_98 -> V_66 ,
F_56 ( V_98 -> V_68 ) ,
F_56 ( V_98 -> V_68 ) ) ;
break;
case V_69 :
V_97 = (struct V_70 * ) V_95 ;
F_11 ( L_21 ,
V_96 , & V_97 -> V_73 ,
F_56 ( V_97 -> V_75 ) ,
F_56 ( V_97 -> V_75 ) ) ;
break;
default:
break;
}
}
static T_4 F_57 ( struct V_70 * V_99 )
{
T_4 V_100 = F_58 ( & V_99 -> V_73 , sizeof( struct V_74 ) , 0 ) ;
T_4 V_101 = F_59 ( V_100 , ( V_102 T_4 ) V_99 -> V_75 , 0 ) ;
return V_101 ;
}
static T_4 F_60 ( struct V_63 * V_103 )
{
T_4 V_104 = F_58 ( & V_103 -> V_66 , sizeof( struct V_67 ) , 0 ) ;
T_4 V_101 = F_59 ( V_104 , ( V_102 T_4 ) V_103 -> V_68 , 0 ) ;
return V_101 ;
}
static int F_61 ( struct V_16 * V_59 ,
struct V_16 * V_60 , T_4 * V_101 )
{
T_4 V_105 , V_106 ;
if ( V_59 -> V_61 == V_62 ) {
V_105 = F_60 ( (struct V_63 * ) V_59 ) ;
V_106 = F_60 ( (struct V_63 * ) V_60 ) ;
} else if ( V_59 -> V_61 == V_69 ) {
V_105 = F_57 ( (struct V_70 * ) V_59 ) ;
V_106 = F_57 ( (struct V_70 * ) V_60 ) ;
} else {
F_6 ( L_12 , V_12 ) ;
return - V_3 ;
}
if ( V_105 == V_106 )
* V_101 = V_105 ;
else
* V_101 = F_59 ( V_105 , V_106 , 0 ) ;
return 0 ;
}
static struct V_9 * F_18 ( struct V_16
* V_17 , struct V_16
* V_18 )
{
T_4 V_101 ;
int V_2 ;
V_2 = F_61 ( V_17 , V_18 , & V_101 ) ;
if ( V_2 )
return NULL ;
return & V_7 [ V_101 & V_107 ] ;
}
static struct V_9 * F_26 ( struct V_16
* V_32 , struct V_16
* V_33 )
{
T_4 V_101 ;
int V_2 ;
V_2 = F_61 ( V_32 , V_33 , & V_101 ) ;
if ( V_2 )
return NULL ;
return & V_14 [ V_101 & V_108 ] ;
}
static int F_62 ( T_4 V_109 , T_1 V_1 , int V_110 )
{
struct V_76 * V_80 = NULL ;
struct V_78 * V_79 ;
T_4 V_111 ;
const char * V_93 = L_15 ;
int V_2 = - V_3 ;
V_80 = F_47 ( V_112 , & V_79 , V_1 ) ;
if ( ! V_80 ) {
V_93 = L_22 ;
goto V_113;
}
V_79 -> V_40 = F_43 () ;
V_111 = 0 ;
V_93 = L_23 ;
V_2 = F_63 ( V_80 , V_79 , sizeof( T_4 ) , & V_111 , V_114 ) ;
if ( V_2 )
goto V_113;
V_2 = F_63 ( V_80 , V_79 , sizeof( T_4 ) ,
& V_109 , V_115 ) ;
if ( V_2 )
goto V_113;
V_2 = F_64 ( V_80 , V_79 , V_110 ) ;
if ( V_2 ) {
V_80 = NULL ;
V_93 = L_24 ;
goto V_113;
}
F_11 ( L_25 , V_12 , V_109 ) ;
return 0 ;
V_113:
F_28 ( L_26 , V_12 , V_93 ) ;
if ( V_80 )
F_51 ( V_80 ) ;
return V_2 ;
}
static int F_65 ( struct V_76 * V_80 , T_1 V_1 , int V_110 )
{
struct V_78 * V_79 = NULL ;
int V_2 = 0 ;
if ( ! V_80 )
return V_2 ;
if ( ! ( F_49 ( V_80 , & V_79 , 0 , 0 , V_1 ,
V_116 , V_117 ) ) ) {
F_50 ( L_27 , V_12 ) ;
return - V_11 ;
}
V_79 -> V_118 = V_119 ;
V_2 = F_64 ( V_80 , (struct V_78 * ) V_80 -> V_120 , V_110 ) ;
if ( V_2 )
F_50 ( L_28 , V_12 ) ;
return V_2 ;
}
int F_66 ( T_1 V_1 , int V_110 )
{
struct V_20 * V_21 ;
struct V_76 * V_80 = NULL ;
struct V_78 * V_79 ;
int V_121 = 0 , V_109 = 0 ;
int V_28 = 0 , V_122 = 0 ;
unsigned long V_22 ;
const char * V_93 = L_15 ;
int V_2 ;
V_80 = F_48 ( V_81 ) ;
if ( ! V_80 ) {
V_2 = - V_11 ;
V_93 = L_29 ;
goto V_123;
}
V_121 ++ ;
F_17 ( & V_23 , V_22 ) ;
for ( V_28 = 0 ; V_28 < V_8 ; V_28 ++ ) {
F_67 (map_info, &iwpm_hash_bucket[i],
hlist_node) {
if ( V_21 -> V_1 != V_1 )
continue;
V_79 = NULL ;
if ( ! ( F_49 ( V_80 , & V_79 , 0 , 0 , V_1 ,
V_116 , V_117 ) ) ) {
V_2 = - V_11 ;
V_93 = L_30 ;
goto V_124;
}
V_93 = L_31 ;
V_2 = F_63 ( V_80 , V_79 ,
sizeof( struct V_16 ) ,
& V_21 -> V_17 ,
V_125 ) ;
if ( V_2 )
goto V_124;
V_2 = F_63 ( V_80 , V_79 ,
sizeof( struct V_16 ) ,
& V_21 -> V_18 ,
V_126 ) ;
if ( V_2 )
goto V_124;
F_29 ( & V_21 -> V_17 ,
L_32 ) ;
F_29 ( & V_21 -> V_18 ,
L_33 ) ;
V_109 ++ ;
V_122 += V_79 -> V_127 ;
if ( V_81 - V_122 < V_79 -> V_127 * 2 ) {
V_122 = 0 ;
V_121 ++ ;
F_20 ( & V_23 ,
V_22 ) ;
V_2 = F_65 ( V_80 , V_1 , V_110 ) ;
V_80 = NULL ;
if ( V_2 ) {
V_93 = L_34 ;
goto V_123;
}
if ( V_121 == V_128 ) {
V_2 = - V_11 ;
V_93 = L_35 ;
goto V_123;
}
V_80 = F_48 ( V_81 ) ;
if ( ! V_80 ) {
V_2 = - V_11 ;
V_93 = L_29 ;
goto V_123;
}
F_17 ( & V_23 , V_22 ) ;
}
}
}
V_124:
F_20 ( & V_23 , V_22 ) ;
V_123:
if ( V_2 ) {
F_50 ( L_36 , V_12 , V_93 , V_2 ) ;
if ( V_80 )
F_51 ( V_80 ) ;
return V_2 ;
}
F_65 ( V_80 , V_1 , V_110 ) ;
return F_62 ( V_109 , V_1 , V_110 ) ;
}
int F_68 ( void )
{
unsigned long V_22 ;
int V_129 = 0 , V_28 = 0 ;
F_17 ( & V_23 , V_22 ) ;
if ( V_7 ) {
for ( V_28 = 0 ; V_28 < V_8 ; V_28 ++ ) {
if ( ! F_69 ( & V_7 [ V_28 ] ) ) {
V_129 = 1 ;
break;
}
}
}
F_20 ( & V_23 , V_22 ) ;
return V_129 ;
}
