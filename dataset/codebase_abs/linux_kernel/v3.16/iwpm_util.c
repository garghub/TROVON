int F_1 ( T_1 V_1 )
{
if ( F_2 ( V_1 ) )
return - V_2 ;
F_3 ( & V_3 ) ;
if ( F_4 ( & V_4 . V_5 ) == 0 ) {
V_6 = F_5 ( V_7 *
sizeof( struct V_8 ) , V_9 ) ;
if ( ! V_6 ) {
F_6 ( & V_3 ) ;
F_7 ( L_1 , V_10 ) ;
return - V_11 ;
}
}
F_8 ( & V_4 . V_5 ) ;
F_6 ( & V_3 ) ;
F_9 ( V_1 , 1 ) ;
return 0 ;
}
int F_10 ( T_1 V_1 )
{
if ( ! F_2 ( V_1 ) )
return - V_2 ;
F_3 ( & V_3 ) ;
if ( F_4 ( & V_4 . V_5 ) == 0 ) {
F_6 ( & V_3 ) ;
F_7 ( L_2 , V_10 ) ;
return - V_2 ;
}
if ( F_11 ( & V_4 . V_5 ) ) {
F_12 () ;
F_13 ( L_3 , V_10 ) ;
}
F_6 ( & V_3 ) ;
F_9 ( V_1 , 0 ) ;
return 0 ;
}
int F_14 ( struct V_12 * V_13 ,
struct V_12 * V_14 ,
T_1 V_1 )
{
struct V_8 * V_15 ;
struct V_16 * V_17 ;
unsigned long V_18 ;
if ( ! F_2 ( V_1 ) )
return - V_2 ;
V_17 = F_5 ( sizeof( struct V_16 ) , V_9 ) ;
if ( ! V_17 ) {
F_7 ( L_4 , V_10 ) ;
return - V_11 ;
}
memcpy ( & V_17 -> V_13 , V_13 ,
sizeof( struct V_12 ) ) ;
memcpy ( & V_17 -> V_14 , V_14 ,
sizeof( struct V_12 ) ) ;
V_17 -> V_1 = V_1 ;
F_15 ( & V_19 , V_18 ) ;
if ( V_6 ) {
V_15 = F_16 (
& V_17 -> V_13 ,
& V_17 -> V_14 ) ;
F_17 ( & V_17 -> V_20 , V_15 ) ;
}
F_18 ( & V_19 , V_18 ) ;
return 0 ;
}
int F_19 ( struct V_12 * V_13 ,
struct V_12 * V_21 )
{
struct V_20 * V_22 ;
struct V_8 * V_15 ;
struct V_16 * V_17 = NULL ;
unsigned long V_18 ;
int V_23 = - V_2 ;
F_15 ( & V_19 , V_18 ) ;
if ( V_6 ) {
V_15 = F_16 (
V_13 ,
V_21 ) ;
F_20 (map_info, tmp_hlist_node,
hash_bucket_head, hlist_node) {
if ( ! F_21 ( & V_17 -> V_14 ,
V_21 ) ) {
F_22 ( & V_17 -> V_20 ) ;
F_23 ( V_17 ) ;
V_23 = 0 ;
break;
}
}
}
F_18 ( & V_19 , V_18 ) ;
return V_23 ;
}
static void F_12 ( void )
{
struct V_20 * V_22 ;
struct V_16 * V_17 ;
unsigned long V_18 ;
int V_24 ;
F_15 ( & V_19 , V_18 ) ;
for ( V_24 = 0 ; V_24 < V_7 ; V_24 ++ ) {
F_20 (map_info, tmp_hlist_node,
&iwpm_hash_bucket[i], hlist_node) {
F_22 ( & V_17 -> V_20 ) ;
F_23 ( V_17 ) ;
}
}
F_23 ( V_6 ) ;
V_6 = NULL ;
F_18 ( & V_19 , V_18 ) ;
}
struct V_25 * F_24 ( T_2 V_26 ,
T_1 V_1 , T_3 V_27 )
{
struct V_25 * V_28 = NULL ;
unsigned long V_18 ;
V_28 = F_5 ( sizeof( struct V_25 ) , V_27 ) ;
if ( ! V_28 ) {
F_7 ( L_5 , V_10 ) ;
return NULL ;
}
F_15 ( & V_29 , V_18 ) ;
F_25 ( & V_28 -> V_30 , & V_31 ) ;
F_18 ( & V_29 , V_18 ) ;
F_26 ( & V_28 -> V_32 ) ;
F_27 ( & V_28 -> V_32 ) ;
V_28 -> V_26 = V_26 ;
V_28 -> V_1 = V_1 ;
V_28 -> V_33 = 0 ;
V_28 -> V_34 = 0 ;
return V_28 ;
}
void F_28 ( struct V_32 * V_32 )
{
struct V_25 * V_28 ;
unsigned long V_18 ;
V_28 = F_29 ( V_32 , struct V_25 , V_32 ) ;
F_15 ( & V_29 , V_18 ) ;
F_30 ( & V_28 -> V_30 ) ;
F_18 ( & V_29 , V_18 ) ;
if ( ! V_28 -> V_33 )
F_13 ( L_6 ,
V_10 , V_28 -> V_26 ) ;
F_23 ( V_28 ) ;
}
struct V_25 * F_31 ( T_2 V_35 )
{
struct V_25 * V_28 ;
struct V_25 * V_36 = NULL ;
unsigned long V_18 ;
F_15 ( & V_29 , V_18 ) ;
F_32 (nlmsg_request, &iwpm_nlmsg_req_list,
inprocess_list) {
if ( V_28 -> V_26 == V_35 ) {
V_36 = V_28 ;
F_27 ( & V_28 -> V_32 ) ;
break;
}
}
F_18 ( & V_29 , V_18 ) ;
return V_36 ;
}
int F_33 ( struct V_25 * V_28 )
{
int V_23 ;
F_34 ( & V_28 -> V_37 ) ;
V_23 = F_35 ( V_28 -> V_37 ,
( V_28 -> V_33 != 0 ) , V_38 ) ;
if ( ! V_23 ) {
V_23 = - V_2 ;
F_36 ( L_7 ,
V_10 , ( V_38 / V_39 ) , V_28 -> V_26 ) ;
} else {
V_23 = V_28 -> V_34 ;
}
F_37 ( & V_28 -> V_32 , F_28 ) ;
return V_23 ;
}
int F_38 ( void )
{
return F_39 ( & V_4 . V_26 ) ;
}
int F_2 ( T_1 V_1 )
{
if ( V_1 >= V_40 )
return 0 ;
return V_4 . V_41 [ V_1 ] ;
}
void F_9 ( T_1 V_1 , int V_42 )
{
if ( V_1 >= V_40 )
return;
V_4 . V_41 [ V_1 ] = V_42 ;
}
int F_40 ( T_1 V_1 )
{
return V_4 . V_43 [ V_1 ] ;
}
void F_41 ( T_1 V_1 , int V_44 )
{
V_4 . V_43 [ V_1 ] = V_44 ;
}
int F_21 ( struct V_12 * V_45 ,
struct V_12 * V_46 )
{
if ( V_45 -> V_47 != V_46 -> V_47 )
return 1 ;
if ( V_45 -> V_47 == V_48 ) {
struct V_49 * V_50 =
(struct V_49 * ) V_45 ;
struct V_49 * V_51 =
(struct V_49 * ) V_46 ;
if ( ! memcmp ( & V_50 -> V_52 ,
& V_51 -> V_52 , sizeof( struct V_53 ) )
&& V_50 -> V_54 == V_51 -> V_54 )
return 0 ;
} else if ( V_45 -> V_47 == V_55 ) {
struct V_56 * V_57 =
(struct V_56 * ) V_45 ;
struct V_56 * V_58 =
(struct V_56 * ) V_46 ;
if ( ! memcmp ( & V_57 -> V_59 ,
& V_58 -> V_59 , sizeof( struct V_60 ) )
&& V_57 -> V_61 == V_58 -> V_61 )
return 0 ;
} else {
F_7 ( L_8 , V_10 ) ;
}
return 1 ;
}
struct V_62 * F_42 ( T_4 V_63 , struct V_64 * * V_65 ,
int V_1 )
{
struct V_62 * V_66 = NULL ;
V_66 = F_43 ( V_67 ) ;
if ( ! V_66 ) {
F_7 ( L_9 , V_10 ) ;
goto V_68;
}
if ( ! ( F_44 ( V_66 , V_65 , 0 , 0 , V_1 , V_63 ,
V_69 ) ) ) {
F_45 ( L_10 , V_10 ) ;
F_46 ( V_66 ) ;
V_66 = NULL ;
}
V_68:
return V_66 ;
}
int F_47 ( struct V_70 * V_71 , int V_72 ,
const struct V_73 * V_74 ,
struct V_75 * V_76 [] , const char * V_77 )
{
int V_78 = 0 ;
int V_23 ;
const char * V_79 = L_11 ;
V_23 = F_48 ( V_71 -> V_65 , V_78 , V_72 - 1 , V_74 ) ;
if ( V_23 ) {
V_79 = L_12 ;
goto V_80;
}
V_23 = F_49 ( V_71 -> V_65 , V_78 , V_76 , V_72 - 1 , V_74 ) ;
if ( V_23 ) {
V_79 = L_13 ;
goto V_80;
}
V_23 = F_50 ( V_76 , V_72 ) ;
if ( V_23 ) {
V_79 = L_14 ;
goto V_80;
}
return 0 ;
V_80:
F_45 ( L_15 ,
V_10 , V_79 , V_77 , V_23 ) ;
return V_23 ;
}
void F_51 ( struct V_12 * V_81 , char * V_82 )
{
struct V_56 * V_83 ;
struct V_49 * V_84 ;
switch ( V_81 -> V_47 ) {
case V_48 :
V_84 = (struct V_49 * ) V_81 ;
F_13 ( L_16 ,
V_82 , & V_84 -> V_52 ,
F_52 ( V_84 -> V_54 ) ,
F_52 ( V_84 -> V_54 ) ) ;
break;
case V_55 :
V_83 = (struct V_56 * ) V_81 ;
F_13 ( L_17 ,
V_82 , & V_83 -> V_59 ,
F_52 ( V_83 -> V_61 ) ,
F_52 ( V_83 -> V_61 ) ) ;
break;
default:
break;
}
}
static T_4 F_53 ( struct V_56 * V_85 )
{
T_4 V_86 = F_54 ( & V_85 -> V_59 , sizeof( struct V_60 ) , 0 ) ;
T_4 V_87 = F_55 ( V_86 , ( V_88 T_4 ) V_85 -> V_61 , 0 ) ;
return V_87 ;
}
static T_4 F_56 ( struct V_49 * V_89 )
{
T_4 V_90 = F_54 ( & V_89 -> V_52 , sizeof( struct V_53 ) , 0 ) ;
T_4 V_87 = F_55 ( V_90 , ( V_88 T_4 ) V_89 -> V_54 , 0 ) ;
return V_87 ;
}
static struct V_8 * F_16 ( struct V_12
* V_13 ,
struct V_12
* V_14 )
{
T_4 V_91 , V_92 , V_87 ;
if ( V_13 -> V_47 == V_48 ) {
V_91 = F_56 ( (struct V_49 * ) V_13 ) ;
V_92 = F_56 ( (struct V_49 * ) V_14 ) ;
} else if ( V_13 -> V_47 == V_55 ) {
V_91 = F_53 ( (struct V_56 * ) V_13 ) ;
V_92 = F_53 ( (struct V_56 * ) V_14 ) ;
} else {
F_7 ( L_8 , V_10 ) ;
return NULL ;
}
if ( V_91 == V_92 )
V_87 = V_91 ;
else
V_87 = F_55 ( V_91 , V_92 , 0 ) ;
return & V_6 [ V_87 & V_93 ] ;
}
static int F_57 ( T_4 V_94 , T_1 V_1 , int V_95 )
{
struct V_62 * V_66 = NULL ;
struct V_64 * V_65 ;
T_4 V_96 ;
const char * V_79 = L_11 ;
int V_23 = - V_2 ;
V_66 = F_42 ( V_97 , & V_65 , V_1 ) ;
if ( ! V_66 ) {
V_79 = L_18 ;
goto V_98;
}
V_65 -> V_26 = F_38 () ;
V_96 = 0 ;
V_79 = L_19 ;
V_23 = F_58 ( V_66 , V_65 , sizeof( T_4 ) , & V_96 , V_99 ) ;
if ( V_23 )
goto V_98;
V_23 = F_58 ( V_66 , V_65 , sizeof( T_4 ) ,
& V_94 , V_100 ) ;
if ( V_23 )
goto V_98;
V_23 = F_59 ( V_66 , V_65 , V_95 ) ;
if ( V_23 ) {
V_66 = NULL ;
V_79 = L_20 ;
goto V_98;
}
F_13 ( L_21 , V_10 , V_94 ) ;
return 0 ;
V_98:
F_36 ( L_22 , V_10 , V_79 ) ;
if ( V_66 )
F_46 ( V_66 ) ;
return V_23 ;
}
static int F_60 ( struct V_62 * V_66 , T_1 V_1 , int V_95 )
{
struct V_64 * V_65 = NULL ;
int V_23 = 0 ;
if ( ! V_66 )
return V_23 ;
if ( ! ( F_44 ( V_66 , & V_65 , 0 , 0 , V_1 ,
V_101 , V_102 ) ) ) {
F_45 ( L_23 , V_10 ) ;
return - V_11 ;
}
V_65 -> V_103 = V_104 ;
V_23 = F_59 ( V_66 , (struct V_64 * ) V_66 -> V_105 , V_95 ) ;
if ( V_23 )
F_45 ( L_24 , V_10 ) ;
return V_23 ;
}
int F_61 ( T_1 V_1 , int V_95 )
{
struct V_16 * V_17 ;
struct V_62 * V_66 = NULL ;
struct V_64 * V_65 ;
int V_106 = 0 , V_94 = 0 ;
int V_24 = 0 , V_107 = 0 ;
unsigned long V_18 ;
const char * V_79 = L_11 ;
int V_23 ;
V_66 = F_43 ( V_67 ) ;
if ( ! V_66 ) {
V_23 = - V_11 ;
V_79 = L_25 ;
goto V_108;
}
V_106 ++ ;
F_15 ( & V_19 , V_18 ) ;
for ( V_24 = 0 ; V_24 < V_7 ; V_24 ++ ) {
F_62 (map_info, &iwpm_hash_bucket[i],
hlist_node) {
if ( V_17 -> V_1 != V_1 )
continue;
V_65 = NULL ;
if ( ! ( F_44 ( V_66 , & V_65 , 0 , 0 , V_1 ,
V_101 , V_102 ) ) ) {
V_23 = - V_11 ;
V_79 = L_26 ;
goto V_109;
}
V_79 = L_27 ;
V_23 = F_58 ( V_66 , V_65 ,
sizeof( struct V_12 ) ,
& V_17 -> V_13 ,
V_110 ) ;
if ( V_23 )
goto V_109;
V_23 = F_58 ( V_66 , V_65 ,
sizeof( struct V_12 ) ,
& V_17 -> V_14 ,
V_111 ) ;
if ( V_23 )
goto V_109;
F_51 ( & V_17 -> V_13 ,
L_28 ) ;
F_51 ( & V_17 -> V_14 ,
L_29 ) ;
V_94 ++ ;
V_107 += V_65 -> V_112 ;
if ( V_67 - V_107 < V_65 -> V_112 * 2 ) {
V_107 = 0 ;
V_106 ++ ;
F_18 ( & V_19 ,
V_18 ) ;
V_23 = F_60 ( V_66 , V_1 , V_95 ) ;
V_66 = NULL ;
if ( V_23 ) {
V_79 = L_30 ;
goto V_108;
}
if ( V_106 == V_113 ) {
V_23 = - V_11 ;
V_79 = L_31 ;
goto V_108;
}
V_66 = F_43 ( V_67 ) ;
if ( ! V_66 ) {
V_23 = - V_11 ;
V_79 = L_25 ;
goto V_108;
}
F_15 ( & V_19 , V_18 ) ;
}
}
}
V_109:
F_18 ( & V_19 , V_18 ) ;
V_108:
if ( V_23 ) {
F_45 ( L_32 , V_10 , V_79 , V_23 ) ;
if ( V_66 )
F_46 ( V_66 ) ;
return V_23 ;
}
F_60 ( V_66 , V_1 , V_95 ) ;
return F_57 ( V_94 , V_1 , V_95 ) ;
}
int F_63 ( void )
{
unsigned long V_18 ;
int V_114 = 0 , V_24 = 0 ;
F_15 ( & V_19 , V_18 ) ;
if ( V_6 ) {
for ( V_24 = 0 ; V_24 < V_7 ; V_24 ++ ) {
if ( ! F_64 ( & V_6 [ V_24 ] ) ) {
V_114 = 1 ;
break;
}
}
}
F_18 ( & V_19 , V_18 ) ;
return V_114 ;
}
