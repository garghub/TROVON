int F_1 ( T_1 V_1 )
{
int V_2 = 0 ;
F_2 ( & V_3 ) ;
if ( F_3 ( & V_4 . V_5 ) == 0 ) {
V_6 = F_4 ( V_7 *
sizeof( struct V_8 ) , V_9 ) ;
if ( ! V_6 ) {
V_2 = - V_10 ;
goto V_11;
}
V_12 = F_4 ( V_13 *
sizeof( struct V_8 ) , V_9 ) ;
if ( ! V_12 ) {
F_5 ( V_6 ) ;
V_2 = - V_10 ;
goto V_11;
}
}
F_6 ( & V_4 . V_5 ) ;
V_11:
F_7 ( & V_3 ) ;
if ( ! V_2 ) {
F_8 ( V_1 , 1 ) ;
F_9 ( V_1 , V_14 ) ;
F_10 ( L_1 ,
V_15 ) ;
}
return V_2 ;
}
int F_11 ( T_1 V_1 )
{
if ( ! F_12 ( V_1 ) )
return - V_16 ;
F_2 ( & V_3 ) ;
if ( F_3 ( & V_4 . V_5 ) == 0 ) {
F_7 ( & V_3 ) ;
F_13 ( L_2 , V_15 ) ;
return - V_16 ;
}
if ( F_14 ( & V_4 . V_5 ) ) {
F_15 () ;
F_16 () ;
F_10 ( L_3 , V_15 ) ;
}
F_7 ( & V_3 ) ;
F_8 ( V_1 , 0 ) ;
F_9 ( V_1 , V_14 ) ;
return 0 ;
}
int F_17 ( struct V_17 * V_18 ,
struct V_17 * V_19 ,
T_1 V_1 )
{
struct V_8 * V_20 ;
struct V_21 * V_22 ;
unsigned long V_23 ;
int V_2 = - V_16 ;
if ( ! F_12 ( V_1 ) )
return V_2 ;
V_22 = F_4 ( sizeof( struct V_21 ) , V_9 ) ;
if ( ! V_22 )
return - V_10 ;
memcpy ( & V_22 -> V_18 , V_18 ,
sizeof( struct V_17 ) ) ;
memcpy ( & V_22 -> V_19 , V_19 ,
sizeof( struct V_17 ) ) ;
V_22 -> V_1 = V_1 ;
F_18 ( & V_24 , V_23 ) ;
if ( V_6 ) {
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
struct V_8 * V_20 ;
struct V_21 * V_22 = NULL ;
unsigned long V_23 ;
int V_2 = - V_16 ;
F_18 ( & V_24 , V_23 ) ;
if ( V_6 ) {
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
F_5 ( V_22 ) ;
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
for ( V_29 = 0 ; V_29 < V_7 ; V_29 ++ ) {
F_23 (map_info, tmp_hlist_node,
&iwpm_hash_bucket[i], hlist_node) {
F_25 ( & V_22 -> V_25 ) ;
F_5 ( V_22 ) ;
}
}
F_5 ( V_6 ) ;
V_6 = NULL ;
F_21 ( & V_24 , V_23 ) ;
}
static void F_16 ( void )
{
struct V_25 * V_27 ;
struct V_30 * V_31 ;
unsigned long V_23 ;
int V_29 ;
F_18 ( & V_32 , V_23 ) ;
for ( V_29 = 0 ; V_29 < V_13 ; V_29 ++ ) {
F_23 (rem_info, tmp_hlist_node,
&iwpm_reminfo_bucket[i], hlist_node) {
F_25 ( & V_31 -> V_25 ) ;
F_5 ( V_31 ) ;
}
}
F_5 ( V_12 ) ;
V_12 = NULL ;
F_21 ( & V_32 , V_23 ) ;
}
void F_26 ( struct V_30 * V_31 )
{
struct V_8 * V_20 ;
unsigned long V_23 ;
F_18 ( & V_32 , V_23 ) ;
if ( V_12 ) {
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
struct V_8 * V_20 ;
struct V_30 * V_31 = NULL ;
unsigned long V_23 ;
int V_2 = - V_16 ;
if ( ! F_12 ( V_1 ) ) {
F_29 ( L_4 , V_15 , V_1 ) ;
return V_2 ;
}
F_18 ( & V_32 , V_23 ) ;
if ( V_12 ) {
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
F_5 ( V_31 ) ;
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
V_43 = F_4 ( sizeof( struct V_40 ) , V_42 ) ;
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
F_10 ( L_6 ,
V_15 , V_43 -> V_41 ) ;
F_5 ( V_43 ) ;
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
V_2 = - V_16 ;
F_29 ( L_7 ,
V_15 , ( V_53 / V_54 ) , V_43 -> V_41 ) ;
} else {
V_2 = V_43 -> V_49 ;
}
F_44 ( & V_43 -> V_47 , F_37 ) ;
return V_2 ;
}
int F_45 ( void )
{
return F_46 ( & V_4 . V_41 ) ;
}
int F_12 ( T_1 V_1 )
{
return V_4 . V_55 [ V_1 ] ;
}
void F_8 ( T_1 V_1 , int V_56 )
{
V_4 . V_55 [ V_1 ] = V_56 ;
}
T_4 F_47 ( T_1 V_1 )
{
return V_4 . V_57 [ V_1 ] ;
}
void F_9 ( T_1 V_1 , T_4 V_58 )
{
V_4 . V_57 [ V_1 ] = V_58 ;
}
T_4 F_48 ( T_1 V_1 , T_4 V_58 )
{
return ( F_47 ( V_1 ) & V_58 ) ;
}
int F_24 ( struct V_17 * V_59 ,
struct V_17 * V_60 )
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
F_13 ( L_8 , V_15 ) ;
}
return 1 ;
}
struct V_76 * F_49 ( T_4 V_77 , struct V_78 * * V_79 ,
int V_1 )
{
struct V_76 * V_80 = NULL ;
V_80 = F_50 ( V_81 ) ;
if ( ! V_80 ) {
F_13 ( L_9 , V_15 ) ;
goto V_82;
}
if ( ! ( F_51 ( V_80 , V_79 , 0 , 0 , V_1 , V_77 ,
V_83 ) ) ) {
F_52 ( L_10 , V_15 ) ;
F_53 ( V_80 ) ;
V_80 = NULL ;
}
V_82:
return V_80 ;
}
int F_54 ( struct V_84 * V_85 , int V_86 ,
const struct V_87 * V_88 ,
struct V_89 * V_90 [] , const char * V_91 )
{
int V_92 = 0 ;
int V_2 ;
const char * V_93 = L_11 ;
V_2 = F_55 ( V_85 -> V_79 , V_92 , V_86 - 1 , V_88 ,
NULL ) ;
if ( V_2 ) {
V_93 = L_12 ;
goto V_94;
}
V_2 = F_56 ( V_85 -> V_79 , V_92 , V_90 , V_86 - 1 ,
V_88 , NULL ) ;
if ( V_2 ) {
V_93 = L_13 ;
goto V_94;
}
V_2 = F_57 ( V_90 , V_86 ) ;
if ( V_2 ) {
V_93 = L_14 ;
goto V_94;
}
return 0 ;
V_94:
F_52 ( L_15 ,
V_15 , V_93 , V_91 , V_2 ) ;
return V_2 ;
}
void F_30 ( struct V_17 * V_95 , char * V_96 )
{
struct V_70 * V_97 ;
struct V_63 * V_98 ;
switch ( V_95 -> V_61 ) {
case V_62 :
V_98 = (struct V_63 * ) V_95 ;
F_10 ( L_16 ,
V_96 , & V_98 -> V_66 ,
F_58 ( V_98 -> V_68 ) ,
F_58 ( V_98 -> V_68 ) ) ;
break;
case V_69 :
V_97 = (struct V_70 * ) V_95 ;
F_10 ( L_17 ,
V_96 , & V_97 -> V_73 ,
F_58 ( V_97 -> V_75 ) ,
F_58 ( V_97 -> V_75 ) ) ;
break;
default:
break;
}
}
static T_4 F_59 ( struct V_70 * V_99 )
{
T_4 V_100 = F_60 ( & V_99 -> V_73 , sizeof( struct V_74 ) , 0 ) ;
T_4 V_101 = F_61 ( V_100 , ( V_102 T_4 ) V_99 -> V_75 , 0 ) ;
return V_101 ;
}
static T_4 F_62 ( struct V_63 * V_103 )
{
T_4 V_104 = F_60 ( & V_103 -> V_66 , sizeof( struct V_67 ) , 0 ) ;
T_4 V_101 = F_61 ( V_104 , ( V_102 T_4 ) V_103 -> V_68 , 0 ) ;
return V_101 ;
}
static int F_63 ( struct V_17 * V_59 ,
struct V_17 * V_60 , T_4 * V_101 )
{
T_4 V_105 , V_106 ;
if ( V_59 -> V_61 == V_62 ) {
V_105 = F_62 ( (struct V_63 * ) V_59 ) ;
V_106 = F_62 ( (struct V_63 * ) V_60 ) ;
} else if ( V_59 -> V_61 == V_69 ) {
V_105 = F_59 ( (struct V_70 * ) V_59 ) ;
V_106 = F_59 ( (struct V_70 * ) V_60 ) ;
} else {
F_13 ( L_8 , V_15 ) ;
return - V_16 ;
}
if ( V_105 == V_106 )
* V_101 = V_105 ;
else
* V_101 = F_61 ( V_105 , V_106 , 0 ) ;
return 0 ;
}
static struct V_8 * F_19 ( struct V_17
* V_18 , struct V_17
* V_19 )
{
T_4 V_101 ;
int V_2 ;
V_2 = F_63 ( V_18 , V_19 , & V_101 ) ;
if ( V_2 )
return NULL ;
return & V_6 [ V_101 & V_107 ] ;
}
static struct V_8 * F_27 ( struct V_17
* V_33 , struct V_17
* V_34 )
{
T_4 V_101 ;
int V_2 ;
V_2 = F_63 ( V_33 , V_34 , & V_101 ) ;
if ( V_2 )
return NULL ;
return & V_12 [ V_101 & V_108 ] ;
}
static int F_64 ( T_4 V_109 , T_1 V_1 , int V_110 )
{
struct V_76 * V_80 = NULL ;
struct V_78 * V_79 ;
T_4 V_111 ;
const char * V_93 = L_11 ;
int V_2 = - V_16 ;
V_80 = F_49 ( V_112 , & V_79 , V_1 ) ;
if ( ! V_80 ) {
V_93 = L_18 ;
goto V_113;
}
V_79 -> V_41 = F_45 () ;
V_111 = 0 ;
V_93 = L_19 ;
V_2 = F_65 ( V_80 , V_79 , sizeof( T_4 ) , & V_111 , V_114 ) ;
if ( V_2 )
goto V_113;
V_2 = F_65 ( V_80 , V_79 , sizeof( T_4 ) ,
& V_109 , V_115 ) ;
if ( V_2 )
goto V_113;
F_66 ( V_80 , V_79 ) ;
V_2 = F_67 ( V_80 , V_110 ) ;
if ( V_2 ) {
V_80 = NULL ;
V_93 = L_20 ;
goto V_113;
}
F_10 ( L_21 , V_15 , V_109 ) ;
return 0 ;
V_113:
F_29 ( L_22 , V_15 , V_93 ) ;
if ( V_80 )
F_53 ( V_80 ) ;
return V_2 ;
}
static int F_68 ( struct V_76 * V_80 , T_1 V_1 , int V_110 )
{
struct V_78 * V_79 = NULL ;
int V_2 = 0 ;
if ( ! V_80 )
return V_2 ;
if ( ! ( F_51 ( V_80 , & V_79 , 0 , 0 , V_1 ,
V_116 , V_117 ) ) ) {
F_52 ( L_23 , V_15 ) ;
F_53 ( V_80 ) ;
return - V_10 ;
}
V_79 -> V_118 = V_119 ;
V_2 = F_67 ( V_80 , V_110 ) ;
if ( V_2 )
F_52 ( L_24 , V_15 ) ;
return V_2 ;
}
int F_69 ( T_1 V_1 , int V_110 )
{
struct V_21 * V_22 ;
struct V_76 * V_80 = NULL ;
struct V_78 * V_79 ;
int V_120 = 0 , V_109 = 0 ;
int V_29 = 0 , V_121 = 0 ;
unsigned long V_23 ;
const char * V_93 = L_11 ;
int V_2 ;
V_80 = F_50 ( V_122 ) ;
if ( ! V_80 ) {
V_2 = - V_10 ;
V_93 = L_25 ;
goto V_123;
}
V_120 ++ ;
F_18 ( & V_24 , V_23 ) ;
for ( V_29 = 0 ; V_29 < V_7 ; V_29 ++ ) {
F_70 (map_info, &iwpm_hash_bucket[i],
hlist_node) {
if ( V_22 -> V_1 != V_1 )
continue;
V_79 = NULL ;
if ( ! ( F_51 ( V_80 , & V_79 , 0 , 0 , V_1 ,
V_116 , V_117 ) ) ) {
V_2 = - V_10 ;
V_93 = L_26 ;
goto V_124;
}
V_93 = L_27 ;
V_2 = F_65 ( V_80 , V_79 ,
sizeof( struct V_17 ) ,
& V_22 -> V_18 ,
V_125 ) ;
if ( V_2 )
goto V_124;
V_2 = F_65 ( V_80 , V_79 ,
sizeof( struct V_17 ) ,
& V_22 -> V_19 ,
V_126 ) ;
if ( V_2 )
goto V_124;
F_66 ( V_80 , V_79 ) ;
F_30 ( & V_22 -> V_18 ,
L_28 ) ;
F_30 ( & V_22 -> V_19 ,
L_29 ) ;
V_109 ++ ;
V_121 += V_79 -> V_127 ;
if ( V_122 - V_121 < V_79 -> V_127 * 2 ) {
V_121 = 0 ;
V_120 ++ ;
F_21 ( & V_24 ,
V_23 ) ;
V_2 = F_68 ( V_80 , V_1 , V_110 ) ;
V_80 = NULL ;
if ( V_2 ) {
V_93 = L_30 ;
goto V_123;
}
if ( V_120 == V_128 ) {
V_2 = - V_10 ;
V_93 = L_31 ;
goto V_123;
}
V_80 = F_50 ( V_122 ) ;
if ( ! V_80 ) {
V_2 = - V_10 ;
V_93 = L_25 ;
goto V_123;
}
F_18 ( & V_24 , V_23 ) ;
}
}
}
V_124:
F_21 ( & V_24 , V_23 ) ;
V_123:
if ( V_2 ) {
F_52 ( L_32 , V_15 , V_93 , V_2 ) ;
if ( V_80 )
F_53 ( V_80 ) ;
return V_2 ;
}
F_68 ( V_80 , V_1 , V_110 ) ;
return F_64 ( V_109 , V_1 , V_110 ) ;
}
int F_71 ( void )
{
unsigned long V_23 ;
int V_129 = 0 , V_29 = 0 ;
F_18 ( & V_24 , V_23 ) ;
if ( V_6 ) {
for ( V_29 = 0 ; V_29 < V_7 ; V_29 ++ ) {
if ( ! F_72 ( & V_6 [ V_29 ] ) ) {
V_129 = 1 ;
break;
}
}
}
F_21 ( & V_24 , V_23 ) ;
return V_129 ;
}
