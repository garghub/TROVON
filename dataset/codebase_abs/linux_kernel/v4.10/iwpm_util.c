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
goto V_12;
}
V_13 = F_5 ( V_14 *
sizeof( struct V_9 ) , V_10 ) ;
if ( ! V_13 ) {
F_6 ( V_7 ) ;
V_2 = - V_11 ;
goto V_12;
}
}
F_7 ( & V_5 . V_6 ) ;
V_12:
F_8 ( & V_4 ) ;
if ( ! V_2 ) {
F_9 ( V_1 , 1 ) ;
F_10 ( V_1 , V_15 ) ;
F_11 ( L_1 ,
V_16 ) ;
}
return V_2 ;
}
int F_12 ( T_1 V_1 )
{
if ( ! F_2 ( V_1 ) )
return - V_3 ;
F_3 ( & V_4 ) ;
if ( F_4 ( & V_5 . V_6 ) == 0 ) {
F_8 ( & V_4 ) ;
F_13 ( L_2 , V_16 ) ;
return - V_3 ;
}
if ( F_14 ( & V_5 . V_6 ) ) {
F_15 () ;
F_16 () ;
F_11 ( L_3 , V_16 ) ;
}
F_8 ( & V_4 ) ;
F_9 ( V_1 , 0 ) ;
F_10 ( V_1 , V_15 ) ;
return 0 ;
}
int F_17 ( struct V_17 * V_18 ,
struct V_17 * V_19 ,
T_1 V_1 )
{
struct V_9 * V_20 ;
struct V_21 * V_22 ;
unsigned long V_23 ;
int V_2 = - V_3 ;
if ( ! F_2 ( V_1 ) )
return V_2 ;
V_22 = F_5 ( sizeof( struct V_21 ) , V_10 ) ;
if ( ! V_22 )
return - V_11 ;
memcpy ( & V_22 -> V_18 , V_18 ,
sizeof( struct V_17 ) ) ;
memcpy ( & V_22 -> V_19 , V_19 ,
sizeof( struct V_17 ) ) ;
V_22 -> V_1 = V_1 ;
F_18 ( & V_24 , V_23 ) ;
if ( V_7 ) {
V_20 = F_19 (
& V_22 -> V_18 ,
& V_22 -> V_19 ) ;
if ( V_20 ) {
F_20 ( & V_22 -> V_25 , V_20 ) ;
V_2 = 0 ;
}
}
F_21 ( & V_24 , V_23 ) ;
return V_2 ;
}
int F_22 ( struct V_17 * V_18 ,
struct V_17 * V_26 )
{
struct V_25 * V_27 ;
struct V_9 * V_20 ;
struct V_21 * V_22 = NULL ;
unsigned long V_23 ;
int V_2 = - V_3 ;
F_18 ( & V_24 , V_23 ) ;
if ( V_7 ) {
V_20 = F_19 (
V_18 ,
V_26 ) ;
if ( ! V_20 )
goto V_28;
F_23 (map_info, tmp_hlist_node,
hash_bucket_head, hlist_node) {
if ( ! F_24 ( & V_22 -> V_19 ,
V_26 ) ) {
F_25 ( & V_22 -> V_25 ) ;
F_6 ( V_22 ) ;
V_2 = 0 ;
break;
}
}
}
V_28:
F_21 ( & V_24 , V_23 ) ;
return V_2 ;
}
static void F_15 ( void )
{
struct V_25 * V_27 ;
struct V_21 * V_22 ;
unsigned long V_23 ;
int V_29 ;
F_18 ( & V_24 , V_23 ) ;
for ( V_29 = 0 ; V_29 < V_8 ; V_29 ++ ) {
F_23 (map_info, tmp_hlist_node,
&iwpm_hash_bucket[i], hlist_node) {
F_25 ( & V_22 -> V_25 ) ;
F_6 ( V_22 ) ;
}
}
F_6 ( V_7 ) ;
V_7 = NULL ;
F_21 ( & V_24 , V_23 ) ;
}
static void F_16 ( void )
{
struct V_25 * V_27 ;
struct V_30 * V_31 ;
unsigned long V_23 ;
int V_29 ;
F_18 ( & V_32 , V_23 ) ;
for ( V_29 = 0 ; V_29 < V_14 ; V_29 ++ ) {
F_23 (rem_info, tmp_hlist_node,
&iwpm_reminfo_bucket[i], hlist_node) {
F_25 ( & V_31 -> V_25 ) ;
F_6 ( V_31 ) ;
}
}
F_6 ( V_13 ) ;
V_13 = NULL ;
F_21 ( & V_32 , V_23 ) ;
}
void F_26 ( struct V_30 * V_31 )
{
struct V_9 * V_20 ;
unsigned long V_23 ;
F_18 ( & V_32 , V_23 ) ;
if ( V_13 ) {
V_20 = F_27 (
& V_31 -> V_33 ,
& V_31 -> V_34 ) ;
if ( V_20 )
F_20 ( & V_31 -> V_25 , V_20 ) ;
}
F_21 ( & V_32 , V_23 ) ;
}
int F_28 ( struct V_17 * V_35 ,
struct V_17 * V_36 ,
struct V_17 * V_37 ,
T_1 V_1 )
{
struct V_25 * V_27 ;
struct V_9 * V_20 ;
struct V_30 * V_31 = NULL ;
unsigned long V_23 ;
int V_2 = - V_3 ;
if ( ! F_2 ( V_1 ) ) {
F_29 ( L_4 , V_16 , V_1 ) ;
return V_2 ;
}
F_18 ( & V_32 , V_23 ) ;
if ( V_13 ) {
V_20 = F_27 (
V_35 ,
V_36 ) ;
if ( ! V_20 )
goto V_38;
F_23 (rem_info, tmp_hlist_node,
hash_bucket_head, hlist_node) {
if ( ! F_24 ( & V_31 -> V_33 ,
V_35 ) &&
! F_24 ( & V_31 -> V_34 ,
V_36 ) ) {
memcpy ( V_37 , & V_31 -> V_39 ,
sizeof( struct V_17 ) ) ;
F_30 ( V_37 ,
L_5 ) ;
F_25 ( & V_31 -> V_25 ) ;
F_6 ( V_31 ) ;
V_2 = 0 ;
break;
}
}
}
V_38:
F_21 ( & V_32 , V_23 ) ;
return V_2 ;
}
struct V_40 * F_31 ( T_2 V_41 ,
T_1 V_1 , T_3 V_42 )
{
struct V_40 * V_43 = NULL ;
unsigned long V_23 ;
V_43 = F_5 ( sizeof( struct V_40 ) , V_42 ) ;
if ( ! V_43 )
return NULL ;
F_18 ( & V_44 , V_23 ) ;
F_32 ( & V_43 -> V_45 , & V_46 ) ;
F_21 ( & V_44 , V_23 ) ;
F_33 ( & V_43 -> V_47 ) ;
F_34 ( & V_43 -> V_47 ) ;
V_43 -> V_41 = V_41 ;
V_43 -> V_1 = V_1 ;
V_43 -> V_48 = 0 ;
V_43 -> V_49 = 0 ;
F_35 ( & V_43 -> V_50 , 1 ) ;
F_36 ( & V_43 -> V_50 ) ;
return V_43 ;
}
void F_37 ( struct V_47 * V_47 )
{
struct V_40 * V_43 ;
unsigned long V_23 ;
V_43 = F_38 ( V_47 , struct V_40 , V_47 ) ;
F_18 ( & V_44 , V_23 ) ;
F_39 ( & V_43 -> V_45 ) ;
F_21 ( & V_44 , V_23 ) ;
if ( ! V_43 -> V_48 )
F_11 ( L_6 ,
V_16 , V_43 -> V_41 ) ;
F_6 ( V_43 ) ;
}
struct V_40 * F_40 ( T_2 V_51 )
{
struct V_40 * V_43 ;
struct V_40 * V_52 = NULL ;
unsigned long V_23 ;
F_18 ( & V_44 , V_23 ) ;
F_41 (nlmsg_request, &iwpm_nlmsg_req_list,
inprocess_list) {
if ( V_43 -> V_41 == V_51 ) {
V_52 = V_43 ;
F_34 ( & V_43 -> V_47 ) ;
break;
}
}
F_21 ( & V_44 , V_23 ) ;
return V_52 ;
}
int F_42 ( struct V_40 * V_43 )
{
int V_2 ;
V_2 = F_43 ( & V_43 -> V_50 , V_53 ) ;
if ( V_2 ) {
V_2 = - V_3 ;
F_29 ( L_7 ,
V_16 , ( V_53 / V_54 ) , V_43 -> V_41 ) ;
} else {
V_2 = V_43 -> V_49 ;
}
F_44 ( & V_43 -> V_47 , F_37 ) ;
return V_2 ;
}
int F_45 ( void )
{
return F_46 ( & V_5 . V_41 ) ;
}
int F_2 ( T_1 V_1 )
{
if ( V_1 >= V_55 )
return 0 ;
return V_5 . V_56 [ V_1 ] ;
}
void F_9 ( T_1 V_1 , int V_57 )
{
if ( V_1 >= V_55 )
return;
V_5 . V_56 [ V_1 ] = V_57 ;
}
T_4 F_47 ( T_1 V_1 )
{
return V_5 . V_58 [ V_1 ] ;
}
void F_10 ( T_1 V_1 , T_4 V_59 )
{
V_5 . V_58 [ V_1 ] = V_59 ;
}
T_4 F_48 ( T_1 V_1 , T_4 V_59 )
{
return ( F_47 ( V_1 ) & V_59 ) ;
}
int F_24 ( struct V_17 * V_60 ,
struct V_17 * V_61 )
{
if ( V_60 -> V_62 != V_61 -> V_62 )
return 1 ;
if ( V_60 -> V_62 == V_63 ) {
struct V_64 * V_65 =
(struct V_64 * ) V_60 ;
struct V_64 * V_66 =
(struct V_64 * ) V_61 ;
if ( ! memcmp ( & V_65 -> V_67 ,
& V_66 -> V_67 , sizeof( struct V_68 ) )
&& V_65 -> V_69 == V_66 -> V_69 )
return 0 ;
} else if ( V_60 -> V_62 == V_70 ) {
struct V_71 * V_72 =
(struct V_71 * ) V_60 ;
struct V_71 * V_73 =
(struct V_71 * ) V_61 ;
if ( ! memcmp ( & V_72 -> V_74 ,
& V_73 -> V_74 , sizeof( struct V_75 ) )
&& V_72 -> V_76 == V_73 -> V_76 )
return 0 ;
} else {
F_13 ( L_8 , V_16 ) ;
}
return 1 ;
}
struct V_77 * F_49 ( T_4 V_78 , struct V_79 * * V_80 ,
int V_1 )
{
struct V_77 * V_81 = NULL ;
V_81 = F_50 ( V_82 ) ;
if ( ! V_81 ) {
F_13 ( L_9 , V_16 ) ;
goto V_83;
}
if ( ! ( F_51 ( V_81 , V_80 , 0 , 0 , V_1 , V_78 ,
V_84 ) ) ) {
F_52 ( L_10 , V_16 ) ;
F_53 ( V_81 ) ;
V_81 = NULL ;
}
V_83:
return V_81 ;
}
int F_54 ( struct V_85 * V_86 , int V_87 ,
const struct V_88 * V_89 ,
struct V_90 * V_91 [] , const char * V_92 )
{
int V_93 = 0 ;
int V_2 ;
const char * V_94 = L_11 ;
V_2 = F_55 ( V_86 -> V_80 , V_93 , V_87 - 1 , V_89 ) ;
if ( V_2 ) {
V_94 = L_12 ;
goto V_95;
}
V_2 = F_56 ( V_86 -> V_80 , V_93 , V_91 , V_87 - 1 , V_89 ) ;
if ( V_2 ) {
V_94 = L_13 ;
goto V_95;
}
V_2 = F_57 ( V_91 , V_87 ) ;
if ( V_2 ) {
V_94 = L_14 ;
goto V_95;
}
return 0 ;
V_95:
F_52 ( L_15 ,
V_16 , V_94 , V_92 , V_2 ) ;
return V_2 ;
}
void F_30 ( struct V_17 * V_96 , char * V_97 )
{
struct V_71 * V_98 ;
struct V_64 * V_99 ;
switch ( V_96 -> V_62 ) {
case V_63 :
V_99 = (struct V_64 * ) V_96 ;
F_11 ( L_16 ,
V_97 , & V_99 -> V_67 ,
F_58 ( V_99 -> V_69 ) ,
F_58 ( V_99 -> V_69 ) ) ;
break;
case V_70 :
V_98 = (struct V_71 * ) V_96 ;
F_11 ( L_17 ,
V_97 , & V_98 -> V_74 ,
F_58 ( V_98 -> V_76 ) ,
F_58 ( V_98 -> V_76 ) ) ;
break;
default:
break;
}
}
static T_4 F_59 ( struct V_71 * V_100 )
{
T_4 V_101 = F_60 ( & V_100 -> V_74 , sizeof( struct V_75 ) , 0 ) ;
T_4 V_102 = F_61 ( V_101 , ( V_103 T_4 ) V_100 -> V_76 , 0 ) ;
return V_102 ;
}
static T_4 F_62 ( struct V_64 * V_104 )
{
T_4 V_105 = F_60 ( & V_104 -> V_67 , sizeof( struct V_68 ) , 0 ) ;
T_4 V_102 = F_61 ( V_105 , ( V_103 T_4 ) V_104 -> V_69 , 0 ) ;
return V_102 ;
}
static int F_63 ( struct V_17 * V_60 ,
struct V_17 * V_61 , T_4 * V_102 )
{
T_4 V_106 , V_107 ;
if ( V_60 -> V_62 == V_63 ) {
V_106 = F_62 ( (struct V_64 * ) V_60 ) ;
V_107 = F_62 ( (struct V_64 * ) V_61 ) ;
} else if ( V_60 -> V_62 == V_70 ) {
V_106 = F_59 ( (struct V_71 * ) V_60 ) ;
V_107 = F_59 ( (struct V_71 * ) V_61 ) ;
} else {
F_13 ( L_8 , V_16 ) ;
return - V_3 ;
}
if ( V_106 == V_107 )
* V_102 = V_106 ;
else
* V_102 = F_61 ( V_106 , V_107 , 0 ) ;
return 0 ;
}
static struct V_9 * F_19 ( struct V_17
* V_18 , struct V_17
* V_19 )
{
T_4 V_102 ;
int V_2 ;
V_2 = F_63 ( V_18 , V_19 , & V_102 ) ;
if ( V_2 )
return NULL ;
return & V_7 [ V_102 & V_108 ] ;
}
static struct V_9 * F_27 ( struct V_17
* V_33 , struct V_17
* V_34 )
{
T_4 V_102 ;
int V_2 ;
V_2 = F_63 ( V_33 , V_34 , & V_102 ) ;
if ( V_2 )
return NULL ;
return & V_13 [ V_102 & V_109 ] ;
}
static int F_64 ( T_4 V_110 , T_1 V_1 , int V_111 )
{
struct V_77 * V_81 = NULL ;
struct V_79 * V_80 ;
T_4 V_112 ;
const char * V_94 = L_11 ;
int V_2 = - V_3 ;
V_81 = F_49 ( V_113 , & V_80 , V_1 ) ;
if ( ! V_81 ) {
V_94 = L_18 ;
goto V_114;
}
V_80 -> V_41 = F_45 () ;
V_112 = 0 ;
V_94 = L_19 ;
V_2 = F_65 ( V_81 , V_80 , sizeof( T_4 ) , & V_112 , V_115 ) ;
if ( V_2 )
goto V_114;
V_2 = F_65 ( V_81 , V_80 , sizeof( T_4 ) ,
& V_110 , V_116 ) ;
if ( V_2 )
goto V_114;
V_2 = F_66 ( V_81 , V_80 , V_111 ) ;
if ( V_2 ) {
V_81 = NULL ;
V_94 = L_20 ;
goto V_114;
}
F_11 ( L_21 , V_16 , V_110 ) ;
return 0 ;
V_114:
F_29 ( L_22 , V_16 , V_94 ) ;
if ( V_81 )
F_53 ( V_81 ) ;
return V_2 ;
}
static int F_67 ( struct V_77 * V_81 , T_1 V_1 , int V_111 )
{
struct V_79 * V_80 = NULL ;
int V_2 = 0 ;
if ( ! V_81 )
return V_2 ;
if ( ! ( F_51 ( V_81 , & V_80 , 0 , 0 , V_1 ,
V_117 , V_118 ) ) ) {
F_52 ( L_23 , V_16 ) ;
F_53 ( V_81 ) ;
return - V_11 ;
}
V_80 -> V_119 = V_120 ;
V_2 = F_66 ( V_81 , (struct V_79 * ) V_81 -> V_121 , V_111 ) ;
if ( V_2 )
F_52 ( L_24 , V_16 ) ;
return V_2 ;
}
int F_68 ( T_1 V_1 , int V_111 )
{
struct V_21 * V_22 ;
struct V_77 * V_81 = NULL ;
struct V_79 * V_80 ;
int V_122 = 0 , V_110 = 0 ;
int V_29 = 0 , V_123 = 0 ;
unsigned long V_23 ;
const char * V_94 = L_11 ;
int V_2 ;
V_81 = F_50 ( V_124 ) ;
if ( ! V_81 ) {
V_2 = - V_11 ;
V_94 = L_25 ;
goto V_125;
}
V_122 ++ ;
F_18 ( & V_24 , V_23 ) ;
for ( V_29 = 0 ; V_29 < V_8 ; V_29 ++ ) {
F_69 (map_info, &iwpm_hash_bucket[i],
hlist_node) {
if ( V_22 -> V_1 != V_1 )
continue;
V_80 = NULL ;
if ( ! ( F_51 ( V_81 , & V_80 , 0 , 0 , V_1 ,
V_117 , V_118 ) ) ) {
V_2 = - V_11 ;
V_94 = L_26 ;
goto V_126;
}
V_94 = L_27 ;
V_2 = F_65 ( V_81 , V_80 ,
sizeof( struct V_17 ) ,
& V_22 -> V_18 ,
V_127 ) ;
if ( V_2 )
goto V_126;
V_2 = F_65 ( V_81 , V_80 ,
sizeof( struct V_17 ) ,
& V_22 -> V_19 ,
V_128 ) ;
if ( V_2 )
goto V_126;
F_30 ( & V_22 -> V_18 ,
L_28 ) ;
F_30 ( & V_22 -> V_19 ,
L_29 ) ;
V_110 ++ ;
V_123 += V_80 -> V_129 ;
if ( V_124 - V_123 < V_80 -> V_129 * 2 ) {
V_123 = 0 ;
V_122 ++ ;
F_21 ( & V_24 ,
V_23 ) ;
V_2 = F_67 ( V_81 , V_1 , V_111 ) ;
V_81 = NULL ;
if ( V_2 ) {
V_94 = L_30 ;
goto V_125;
}
if ( V_122 == V_130 ) {
V_2 = - V_11 ;
V_94 = L_31 ;
goto V_125;
}
V_81 = F_50 ( V_124 ) ;
if ( ! V_81 ) {
V_2 = - V_11 ;
V_94 = L_25 ;
goto V_125;
}
F_18 ( & V_24 , V_23 ) ;
}
}
}
V_126:
F_21 ( & V_24 , V_23 ) ;
V_125:
if ( V_2 ) {
F_52 ( L_32 , V_16 , V_94 , V_2 ) ;
if ( V_81 )
F_53 ( V_81 ) ;
return V_2 ;
}
F_67 ( V_81 , V_1 , V_111 ) ;
return F_64 ( V_110 , V_1 , V_111 ) ;
}
int F_70 ( void )
{
unsigned long V_23 ;
int V_131 = 0 , V_29 = 0 ;
F_18 ( & V_24 , V_23 ) ;
if ( V_7 ) {
for ( V_29 = 0 ; V_29 < V_8 ; V_29 ++ ) {
if ( ! F_71 ( & V_7 [ V_29 ] ) ) {
V_131 = 1 ;
break;
}
}
}
F_21 ( & V_24 , V_23 ) ;
return V_131 ;
}
