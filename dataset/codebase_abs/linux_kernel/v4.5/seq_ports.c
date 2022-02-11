struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 )
{
struct V_1 * V_5 ;
if ( V_3 == NULL )
return NULL ;
F_2 ( & V_3 -> V_6 ) ;
F_3 (port, &client->ports_list_head, list) {
if ( V_5 -> V_7 . V_5 == V_4 ) {
if ( V_5 -> V_8 )
break;
F_4 ( & V_5 -> V_9 ) ;
F_5 ( & V_3 -> V_6 ) ;
return V_5 ;
}
}
F_5 ( & V_3 -> V_6 ) ;
return NULL ;
}
struct V_1 * F_6 ( struct V_2 * V_3 ,
struct V_10 * V_11 )
{
int V_4 ;
struct V_1 * V_5 , * V_12 ;
V_4 = V_11 -> V_7 . V_5 ;
V_12 = NULL ;
F_2 ( & V_3 -> V_6 ) ;
F_3 (port, &client->ports_list_head, list) {
if ( V_5 -> V_7 . V_5 < V_4 )
continue;
if ( V_5 -> V_7 . V_5 == V_4 ) {
V_12 = V_5 ;
break;
}
if ( V_12 == NULL || V_5 -> V_7 . V_5 < V_12 -> V_7 . V_5 )
V_12 = V_5 ;
}
if ( V_12 ) {
if ( V_12 -> V_8 )
V_12 = NULL ;
else
F_4 ( & V_12 -> V_9 ) ;
}
F_5 ( & V_3 -> V_6 ) ;
return V_12 ;
}
static void F_7 ( struct V_13 * V_14 )
{
F_8 ( & V_14 -> V_15 ) ;
V_14 -> V_16 = 0 ;
V_14 -> V_17 = 0 ;
F_9 ( & V_14 -> V_18 ) ;
F_10 ( & V_14 -> V_19 ) ;
V_14 -> V_20 = NULL ;
V_14 -> V_21 = NULL ;
}
struct V_1 * F_11 ( struct V_2 * V_3 ,
int V_5 )
{
unsigned long V_22 ;
struct V_1 * V_23 , * V_24 ;
int V_4 = - 1 ;
if ( F_12 ( ! V_3 ) )
return NULL ;
if ( V_3 -> V_25 >= V_26 ) {
F_13 ( L_1 , V_3 -> V_27 ) ;
return NULL ;
}
V_23 = F_14 ( sizeof( * V_23 ) , V_28 ) ;
if ( ! V_23 )
return NULL ;
V_23 -> V_7 . V_3 = V_3 -> V_27 ;
V_23 -> V_7 . V_5 = - 1 ;
V_23 -> V_29 = V_30 ;
sprintf ( V_23 -> V_31 , L_2 , V_4 ) ;
F_15 ( & V_23 -> V_9 ) ;
F_7 ( & V_23 -> V_32 ) ;
F_7 ( & V_23 -> V_33 ) ;
V_4 = V_5 >= 0 ? V_5 : 0 ;
F_16 ( & V_3 -> V_34 ) ;
F_17 ( & V_3 -> V_6 , V_22 ) ;
F_3 (p, &client->ports_list_head, list) {
if ( V_24 -> V_7 . V_5 > V_4 )
break;
if ( V_5 < 0 )
V_4 = V_24 -> V_7 . V_5 + 1 ;
}
F_18 ( & V_23 -> V_35 , & V_24 -> V_35 ) ;
V_3 -> V_25 ++ ;
V_23 -> V_7 . V_5 = V_4 ;
F_19 ( & V_3 -> V_6 , V_22 ) ;
F_20 ( & V_3 -> V_34 ) ;
sprintf ( V_23 -> V_31 , L_2 , V_4 ) ;
return V_23 ;
}
static struct V_1 * F_21 ( struct V_36 * V_7 ,
struct V_2 * * V_37 )
{
struct V_1 * V_24 ;
* V_37 = F_22 ( V_7 -> V_3 ) ;
if ( * V_37 ) {
V_24 = F_1 ( * V_37 , V_7 -> V_5 ) ;
if ( ! V_24 ) {
F_23 ( * V_37 ) ;
* V_37 = NULL ;
}
return V_24 ;
}
return NULL ;
}
static inline struct V_38 *
F_24 ( struct V_15 * V_24 , bool V_39 )
{
if ( V_39 )
return F_25 ( V_24 , struct V_38 , V_40 ) ;
else
return F_25 ( V_24 , struct V_38 , V_41 ) ;
}
static void F_26 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
struct V_13 * V_14 ,
int V_39 )
{
struct V_15 * V_24 , * V_42 ;
F_27 (p, n, &grp->list_head) {
struct V_38 * V_43 ;
struct V_2 * V_44 ;
struct V_1 * V_45 ;
V_43 = F_24 ( V_24 , V_39 ) ;
if ( V_39 )
V_45 = F_21 ( & V_43 -> V_46 . V_47 , & V_44 ) ;
else
V_45 = F_21 ( & V_43 -> V_46 . V_48 , & V_44 ) ;
F_28 ( V_3 , V_5 , V_43 , V_39 , false ) ;
if ( ! V_45 ) {
if ( F_29 ( & V_43 -> V_49 ) )
F_30 ( V_43 ) ;
continue;
}
F_28 ( V_44 , V_45 , V_43 , ! V_39 , true ) ;
F_30 ( V_43 ) ;
F_31 ( V_45 ) ;
F_23 ( V_44 ) ;
}
}
static int F_32 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
V_5 -> V_8 = 1 ;
F_33 ( & V_5 -> V_9 ) ;
F_26 ( V_3 , V_5 , & V_5 -> V_32 , true ) ;
F_26 ( V_3 , V_5 , & V_5 -> V_33 , false ) ;
if ( V_5 -> V_50 )
V_5 -> V_50 ( V_5 -> V_51 ) ;
F_12 ( V_5 -> V_32 . V_16 != 0 ) ;
F_12 ( V_5 -> V_33 . V_16 != 0 ) ;
F_30 ( V_5 ) ;
return 0 ;
}
int F_34 ( struct V_2 * V_3 , int V_5 )
{
unsigned long V_22 ;
struct V_1 * V_12 = NULL , * V_24 ;
F_16 ( & V_3 -> V_34 ) ;
F_17 ( & V_3 -> V_6 , V_22 ) ;
F_3 (p, &client->ports_list_head, list) {
if ( V_24 -> V_7 . V_5 == V_5 ) {
F_35 ( & V_24 -> V_35 ) ;
V_3 -> V_25 -- ;
V_12 = V_24 ;
break;
}
}
F_19 ( & V_3 -> V_6 , V_22 ) ;
F_20 ( & V_3 -> V_34 ) ;
if ( V_12 )
return F_32 ( V_3 , V_12 ) ;
else
return - V_52 ;
}
int F_36 ( struct V_2 * V_3 )
{
unsigned long V_22 ;
struct V_15 V_53 ;
struct V_1 * V_5 , * V_54 ;
F_16 ( & V_3 -> V_34 ) ;
F_17 ( & V_3 -> V_6 , V_22 ) ;
if ( ! F_37 ( & V_3 -> V_55 ) ) {
F_38 ( & V_53 , & V_3 -> V_55 ) ;
F_39 ( & V_3 -> V_55 ) ;
} else {
F_8 ( & V_53 ) ;
}
V_3 -> V_25 = 0 ;
F_19 ( & V_3 -> V_6 , V_22 ) ;
F_40 (port, tmp, &deleted_list, list) {
F_35 ( & V_5 -> V_35 ) ;
F_41 ( V_5 -> V_7 . V_3 , V_5 -> V_7 . V_5 ) ;
F_32 ( V_3 , V_5 ) ;
}
F_20 ( & V_3 -> V_34 ) ;
return 0 ;
}
int F_42 ( struct V_1 * V_5 ,
struct V_10 * V_46 )
{
if ( F_12 ( ! V_5 || ! V_46 ) )
return - V_56 ;
if ( V_46 -> V_31 [ 0 ] )
F_43 ( V_5 -> V_31 , V_46 -> V_31 , sizeof( V_5 -> V_31 ) ) ;
V_5 -> V_57 = V_46 -> V_57 ;
V_5 -> type = V_46 -> type ;
V_5 -> V_58 = V_46 -> V_58 ;
V_5 -> V_59 = V_46 -> V_59 ;
V_5 -> V_60 = V_46 -> V_60 ;
V_5 -> V_61 = ( V_46 -> V_22 & V_62 ) ? 1 : 0 ;
V_5 -> V_63 = ( V_46 -> V_22 & V_64 ) ? 1 : 0 ;
V_5 -> V_65 = V_46 -> V_65 ;
return 0 ;
}
int F_44 ( struct V_1 * V_5 ,
struct V_10 * V_46 )
{
if ( F_12 ( ! V_5 || ! V_46 ) )
return - V_56 ;
F_43 ( V_46 -> V_31 , V_5 -> V_31 , sizeof( V_46 -> V_31 ) ) ;
V_46 -> V_57 = V_5 -> V_57 ;
V_46 -> type = V_5 -> type ;
V_46 -> V_58 = V_5 -> V_58 ;
V_46 -> V_59 = V_5 -> V_59 ;
V_46 -> V_60 = V_5 -> V_60 ;
V_46 -> V_66 = V_5 -> V_32 . V_16 ;
V_46 -> V_67 = V_5 -> V_33 . V_16 ;
V_46 -> V_22 = 0 ;
if ( V_5 -> V_61 ) {
V_46 -> V_22 |= V_62 ;
if ( V_5 -> V_63 )
V_46 -> V_22 |= V_64 ;
V_46 -> V_65 = V_5 -> V_65 ;
}
return 0 ;
}
static int F_45 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
struct V_13 * V_14 ,
struct V_68 * V_46 ,
int V_69 )
{
int V_70 = 0 ;
if ( ! F_46 ( V_5 -> V_29 ) )
return - V_71 ;
V_14 -> V_16 ++ ;
if ( V_14 -> V_20 && V_14 -> V_16 == 1 ) {
V_70 = V_14 -> V_20 ( V_5 -> V_51 , V_46 ) ;
if ( V_70 < 0 ) {
F_47 ( V_5 -> V_29 ) ;
V_14 -> V_16 -- ;
}
}
if ( V_70 >= 0 && V_69 && V_3 -> type == V_72 )
F_48 ( V_5 -> V_7 . V_3 , V_5 -> V_7 . V_5 ,
V_46 , V_73 ) ;
return V_70 ;
}
static int F_49 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
struct V_13 * V_14 ,
struct V_68 * V_46 ,
int V_69 )
{
int V_70 = 0 ;
if ( ! V_14 -> V_16 )
return - V_56 ;
V_14 -> V_16 -- ;
if ( V_14 -> V_21 && V_14 -> V_16 == 0 )
V_70 = V_14 -> V_21 ( V_5 -> V_51 , V_46 ) ;
if ( V_69 && V_3 -> type == V_72 )
F_48 ( V_5 -> V_7 . V_3 , V_5 -> V_7 . V_5 ,
V_46 , V_74 ) ;
F_47 ( V_5 -> V_29 ) ;
return V_70 ;
}
static inline int F_50 ( struct V_36 * V_75 , struct V_36 * V_76 )
{
return ( V_75 -> V_3 == V_76 -> V_3 ) && ( V_75 -> V_5 == V_76 -> V_5 ) ;
}
static int F_51 ( struct V_68 * V_75 ,
struct V_68 * V_76 )
{
if ( F_50 ( & V_75 -> V_48 , & V_76 -> V_48 ) &&
F_50 ( & V_75 -> V_47 , & V_76 -> V_47 ) ) {
if ( V_75 -> V_22 && V_75 -> V_22 == V_76 -> V_22 )
return V_75 -> V_77 == V_76 -> V_77 ;
else if ( ! V_75 -> V_22 )
return 1 ;
}
return 0 ;
}
static int F_52 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
struct V_38 * V_43 ,
bool V_39 , bool V_17 , bool V_78 )
{
struct V_13 * V_14 ;
struct V_15 * V_24 ;
struct V_38 * V_76 ;
int V_70 ;
V_14 = V_39 ? & V_5 -> V_32 : & V_5 -> V_33 ;
V_70 = - V_79 ;
F_53 ( & V_14 -> V_19 ) ;
if ( V_17 ) {
if ( ! F_37 ( & V_14 -> V_15 ) )
goto V_80;
} else {
if ( V_14 -> V_17 )
goto V_80;
F_54 (p, &grp->list_head) {
V_76 = F_24 ( V_24 , V_39 ) ;
if ( F_51 ( & V_43 -> V_46 , & V_76 -> V_46 ) )
goto V_80;
}
}
V_70 = F_45 ( V_3 , V_5 , V_14 , & V_43 -> V_46 , V_78 ) ;
if ( V_70 < 0 ) {
V_14 -> V_17 = 0 ;
goto V_80;
}
F_55 ( & V_14 -> V_18 ) ;
if ( V_39 )
F_18 ( & V_43 -> V_40 , & V_14 -> V_15 ) ;
else
F_18 ( & V_43 -> V_41 , & V_14 -> V_15 ) ;
V_14 -> V_17 = V_17 ;
F_56 ( & V_43 -> V_49 ) ;
F_57 ( & V_14 -> V_18 ) ;
V_70 = 0 ;
V_80:
F_58 ( & V_14 -> V_19 ) ;
return V_70 ;
}
static void F_28 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
struct V_38 * V_43 ,
bool V_39 , bool V_78 )
{
struct V_13 * V_14 ;
struct V_15 * V_35 ;
bool V_81 ;
V_14 = V_39 ? & V_5 -> V_32 : & V_5 -> V_33 ;
V_35 = V_39 ? & V_43 -> V_40 : & V_43 -> V_41 ;
F_53 ( & V_14 -> V_19 ) ;
F_55 ( & V_14 -> V_18 ) ;
V_81 = F_37 ( V_35 ) ;
if ( ! V_81 )
F_39 ( V_35 ) ;
V_14 -> V_17 = 0 ;
F_57 ( & V_14 -> V_18 ) ;
F_58 ( & V_14 -> V_19 ) ;
if ( ! V_81 )
F_49 ( V_3 , V_5 , V_14 , & V_43 -> V_46 , V_78 ) ;
}
int F_59 ( struct V_2 * V_82 ,
struct V_2 * V_83 ,
struct V_1 * V_84 ,
struct V_2 * V_85 ,
struct V_1 * V_86 ,
struct V_68 * V_46 )
{
struct V_38 * V_43 ;
bool V_17 ;
int V_70 ;
V_43 = F_14 ( sizeof( * V_43 ) , V_28 ) ;
if ( ! V_43 )
return - V_87 ;
V_43 -> V_46 = * V_46 ;
F_60 ( & V_43 -> V_49 , 0 ) ;
F_8 ( & V_43 -> V_40 ) ;
F_8 ( & V_43 -> V_41 ) ;
V_17 = ! ! ( V_46 -> V_22 & V_88 ) ;
V_70 = F_52 ( V_83 , V_84 , V_43 , true ,
V_17 ,
V_82 -> V_27 != V_83 -> V_27 ) ;
if ( V_70 < 0 )
goto error;
V_70 = F_52 ( V_85 , V_86 , V_43 , false ,
V_17 ,
V_82 -> V_27 != V_85 -> V_27 ) ;
if ( V_70 < 0 )
goto V_89;
return 0 ;
V_89:
F_28 ( V_83 , V_84 , V_43 , true ,
V_82 -> V_27 != V_83 -> V_27 ) ;
error:
F_30 ( V_43 ) ;
return V_70 ;
}
int F_61 ( struct V_2 * V_82 ,
struct V_2 * V_83 ,
struct V_1 * V_84 ,
struct V_2 * V_85 ,
struct V_1 * V_86 ,
struct V_68 * V_46 )
{
struct V_13 * V_90 = & V_84 -> V_32 ;
struct V_38 * V_43 ;
int V_70 = - V_52 ;
F_53 ( & V_90 -> V_19 ) ;
F_3 (subs, &src->list_head, src_list) {
if ( F_51 ( V_46 , & V_43 -> V_46 ) ) {
F_62 ( & V_43 -> V_49 ) ;
V_70 = 0 ;
break;
}
}
F_58 ( & V_90 -> V_19 ) ;
if ( V_70 < 0 )
return V_70 ;
F_28 ( V_83 , V_84 , V_43 , true ,
V_82 -> V_27 != V_83 -> V_27 ) ;
F_28 ( V_85 , V_86 , V_43 , false ,
V_82 -> V_27 != V_85 -> V_27 ) ;
F_30 ( V_43 ) ;
return 0 ;
}
struct V_38 * F_63 ( struct V_13 * V_91 ,
struct V_36 * V_92 )
{
struct V_38 * V_76 , * V_12 = NULL ;
F_64 ( & V_91 -> V_19 ) ;
F_3 (s, &src_grp->list_head, src_list) {
if ( F_50 ( V_92 , & V_76 -> V_46 . V_47 ) ) {
V_12 = V_76 ;
break;
}
}
F_65 ( & V_91 -> V_19 ) ;
return V_12 ;
}
int F_66 ( int V_3 ,
struct V_93 * V_94 ,
int V_95 , int type , int V_58 ,
int V_59 , char * V_96 )
{
struct V_10 V_97 ;
int V_98 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_7 . V_3 = V_3 ;
F_43 ( V_97 . V_31 , V_96 ? V_96 : L_3 ,
sizeof( V_97 . V_31 ) ) ;
V_97 . V_57 = V_95 ;
V_97 . type = type ;
V_97 . V_99 = V_94 ;
V_97 . V_58 = V_58 ;
V_97 . V_59 = V_59 ;
V_98 = F_67 ( V_3 ,
V_100 ,
& V_97 ) ;
if ( V_98 >= 0 )
V_98 = V_97 . V_7 . V_5 ;
return V_98 ;
}
int F_68 ( int V_3 , int V_5 )
{
struct V_10 V_97 ;
int V_70 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_7 . V_3 = V_3 ;
V_97 . V_7 . V_5 = V_5 ;
V_70 = F_67 ( V_3 ,
V_101 ,
& V_97 ) ;
return V_70 ;
}
