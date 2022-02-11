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
if ( V_3 -> V_25 >= V_26 - 1 ) {
F_13 ( L_1 , V_3 -> V_27 ) ;
return NULL ;
}
V_23 = F_14 ( sizeof( * V_23 ) , V_28 ) ;
if ( ! V_23 ) {
F_15 ( L_2 ) ;
return NULL ;
}
V_23 -> V_7 . V_3 = V_3 -> V_27 ;
V_23 -> V_7 . V_5 = - 1 ;
V_23 -> V_29 = V_30 ;
sprintf ( V_23 -> V_31 , L_3 , V_4 ) ;
F_16 ( & V_23 -> V_9 ) ;
F_7 ( & V_23 -> V_32 ) ;
F_7 ( & V_23 -> V_33 ) ;
V_4 = V_5 >= 0 ? V_5 : 0 ;
F_17 ( & V_3 -> V_34 ) ;
F_18 ( & V_3 -> V_6 , V_22 ) ;
F_3 (p, &client->ports_list_head, list) {
if ( V_24 -> V_7 . V_5 > V_4 )
break;
if ( V_5 < 0 )
V_4 = V_24 -> V_7 . V_5 + 1 ;
}
F_19 ( & V_23 -> V_35 , & V_24 -> V_35 ) ;
V_3 -> V_25 ++ ;
V_23 -> V_7 . V_5 = V_4 ;
F_20 ( & V_3 -> V_6 , V_22 ) ;
F_21 ( & V_3 -> V_34 ) ;
sprintf ( V_23 -> V_31 , L_3 , V_4 ) ;
return V_23 ;
}
static struct V_1 * F_22 ( struct V_36 * V_7 ,
struct V_2 * * V_37 )
{
struct V_1 * V_24 ;
* V_37 = F_23 ( V_7 -> V_3 ) ;
if ( * V_37 ) {
V_24 = F_1 ( * V_37 , V_7 -> V_5 ) ;
if ( ! V_24 ) {
F_24 ( * V_37 ) ;
* V_37 = NULL ;
}
return V_24 ;
}
return NULL ;
}
static void F_25 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
struct V_13 * V_14 ,
int V_38 )
{
struct V_15 * V_24 , * V_39 ;
F_26 (p, n, &grp->list_head) {
struct V_40 * V_41 ;
struct V_2 * V_42 ;
struct V_1 * V_43 ;
if ( V_38 == V_44 ) {
V_41 = F_27 ( V_24 , struct V_40 , V_45 ) ;
V_43 = F_22 ( & V_41 -> V_46 . V_47 , & V_42 ) ;
} else {
V_41 = F_27 ( V_24 , struct V_40 , V_48 ) ;
V_43 = F_22 ( & V_41 -> V_46 . V_49 , & V_42 ) ;
}
F_28 ( V_24 ) ;
F_29 ( V_3 , V_5 , V_14 , & V_41 -> V_46 , 0 ) ;
if ( ! V_43 ) {
if ( F_30 ( & V_41 -> V_50 ) )
F_31 ( V_41 ) ;
} else {
struct V_13 * V_51 ;
V_51 = ( V_38 == V_44 ) ? & V_43 -> V_33 : & V_43 -> V_32 ;
F_32 ( & V_51 -> V_19 ) ;
if ( V_38 == V_44 )
F_28 ( & V_41 -> V_48 ) ;
else
F_28 ( & V_41 -> V_45 ) ;
F_33 ( & V_51 -> V_19 ) ;
F_29 ( V_42 , V_43 , V_51 , & V_41 -> V_46 , 1 ) ;
F_31 ( V_41 ) ;
F_34 ( V_43 ) ;
F_24 ( V_42 ) ;
}
}
}
static int F_35 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
V_5 -> V_8 = 1 ;
F_36 ( & V_5 -> V_9 ) ;
F_25 ( V_3 , V_5 , & V_5 -> V_32 , V_44 ) ;
F_25 ( V_3 , V_5 , & V_5 -> V_33 , V_52 ) ;
if ( V_5 -> V_53 )
V_5 -> V_53 ( V_5 -> V_54 ) ;
F_12 ( V_5 -> V_32 . V_16 != 0 ) ;
F_12 ( V_5 -> V_33 . V_16 != 0 ) ;
F_31 ( V_5 ) ;
return 0 ;
}
int F_37 ( struct V_2 * V_3 , int V_5 )
{
unsigned long V_22 ;
struct V_1 * V_12 = NULL , * V_24 ;
F_17 ( & V_3 -> V_34 ) ;
F_18 ( & V_3 -> V_6 , V_22 ) ;
F_3 (p, &client->ports_list_head, list) {
if ( V_24 -> V_7 . V_5 == V_5 ) {
F_28 ( & V_24 -> V_35 ) ;
V_3 -> V_25 -- ;
V_12 = V_24 ;
break;
}
}
F_20 ( & V_3 -> V_6 , V_22 ) ;
F_21 ( & V_3 -> V_34 ) ;
if ( V_12 )
return F_35 ( V_3 , V_12 ) ;
else
return - V_55 ;
}
int F_38 ( struct V_2 * V_3 )
{
unsigned long V_22 ;
struct V_15 V_56 ;
struct V_1 * V_5 , * V_57 ;
F_17 ( & V_3 -> V_34 ) ;
F_18 ( & V_3 -> V_6 , V_22 ) ;
if ( ! F_39 ( & V_3 -> V_58 ) ) {
F_40 ( & V_56 , & V_3 -> V_58 ) ;
F_41 ( & V_3 -> V_58 ) ;
} else {
F_8 ( & V_56 ) ;
}
V_3 -> V_25 = 0 ;
F_20 ( & V_3 -> V_6 , V_22 ) ;
F_42 (port, tmp, &deleted_list, list) {
F_28 ( & V_5 -> V_35 ) ;
F_43 ( V_5 -> V_7 . V_3 , V_5 -> V_7 . V_5 ) ;
F_35 ( V_3 , V_5 ) ;
}
F_21 ( & V_3 -> V_34 ) ;
return 0 ;
}
int F_44 ( struct V_1 * V_5 ,
struct V_10 * V_46 )
{
if ( F_12 ( ! V_5 || ! V_46 ) )
return - V_59 ;
if ( V_46 -> V_31 [ 0 ] )
F_45 ( V_5 -> V_31 , V_46 -> V_31 , sizeof( V_5 -> V_31 ) ) ;
V_5 -> V_60 = V_46 -> V_60 ;
V_5 -> type = V_46 -> type ;
V_5 -> V_61 = V_46 -> V_61 ;
V_5 -> V_62 = V_46 -> V_62 ;
V_5 -> V_63 = V_46 -> V_63 ;
V_5 -> V_64 = ( V_46 -> V_22 & V_65 ) ? 1 : 0 ;
V_5 -> V_66 = ( V_46 -> V_22 & V_67 ) ? 1 : 0 ;
V_5 -> V_68 = V_46 -> V_68 ;
return 0 ;
}
int F_46 ( struct V_1 * V_5 ,
struct V_10 * V_46 )
{
if ( F_12 ( ! V_5 || ! V_46 ) )
return - V_59 ;
F_45 ( V_46 -> V_31 , V_5 -> V_31 , sizeof( V_46 -> V_31 ) ) ;
V_46 -> V_60 = V_5 -> V_60 ;
V_46 -> type = V_5 -> type ;
V_46 -> V_61 = V_5 -> V_61 ;
V_46 -> V_62 = V_5 -> V_62 ;
V_46 -> V_63 = V_5 -> V_63 ;
V_46 -> V_69 = V_5 -> V_32 . V_16 ;
V_46 -> V_70 = V_5 -> V_33 . V_16 ;
V_46 -> V_22 = 0 ;
if ( V_5 -> V_64 ) {
V_46 -> V_22 |= V_65 ;
if ( V_5 -> V_66 )
V_46 -> V_22 |= V_67 ;
V_46 -> V_68 = V_5 -> V_68 ;
}
return 0 ;
}
static int F_47 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
struct V_13 * V_14 ,
struct V_71 * V_46 ,
int V_72 )
{
int V_73 = 0 ;
if ( ! F_48 ( V_5 -> V_29 ) )
return - V_74 ;
V_14 -> V_16 ++ ;
if ( V_14 -> V_20 && ( V_5 -> V_75 || V_14 -> V_16 == 1 ) ) {
V_73 = V_14 -> V_20 ( V_5 -> V_54 , V_46 ) ;
if ( V_73 < 0 ) {
F_49 ( V_5 -> V_29 ) ;
V_14 -> V_16 -- ;
}
}
if ( V_73 >= 0 && V_72 && V_3 -> type == V_76 )
F_50 ( V_5 -> V_7 . V_3 , V_5 -> V_7 . V_5 ,
V_46 , V_77 ) ;
return V_73 ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
struct V_13 * V_14 ,
struct V_71 * V_46 ,
int V_72 )
{
int V_73 = 0 ;
if ( ! V_14 -> V_16 )
return - V_59 ;
V_14 -> V_16 -- ;
if ( V_14 -> V_21 && ( V_5 -> V_75 || V_14 -> V_16 == 0 ) )
V_73 = V_14 -> V_21 ( V_5 -> V_54 , V_46 ) ;
if ( V_72 && V_3 -> type == V_76 )
F_50 ( V_5 -> V_7 . V_3 , V_5 -> V_7 . V_5 ,
V_46 , V_78 ) ;
F_49 ( V_5 -> V_29 ) ;
return V_73 ;
}
static inline int F_51 ( struct V_36 * V_79 , struct V_36 * V_80 )
{
return ( V_79 -> V_3 == V_80 -> V_3 ) && ( V_79 -> V_5 == V_80 -> V_5 ) ;
}
static int F_52 ( struct V_71 * V_79 ,
struct V_71 * V_80 )
{
if ( F_51 ( & V_79 -> V_49 , & V_80 -> V_49 ) &&
F_51 ( & V_79 -> V_47 , & V_80 -> V_47 ) ) {
if ( V_79 -> V_22 && V_79 -> V_22 == V_80 -> V_22 )
return V_79 -> V_81 == V_80 -> V_81 ;
else if ( ! V_79 -> V_22 )
return 1 ;
}
return 0 ;
}
int F_53 ( struct V_2 * V_82 ,
struct V_2 * V_83 ,
struct V_1 * V_84 ,
struct V_2 * V_85 ,
struct V_1 * V_86 ,
struct V_71 * V_46 )
{
struct V_13 * V_87 = & V_84 -> V_32 ;
struct V_13 * V_47 = & V_86 -> V_33 ;
struct V_40 * V_41 , * V_80 ;
int V_73 , V_88 = 0 ;
unsigned long V_22 ;
int V_17 ;
V_41 = F_14 ( sizeof( * V_41 ) , V_28 ) ;
if ( ! V_41 )
return - V_89 ;
V_41 -> V_46 = * V_46 ;
F_54 ( & V_41 -> V_50 , 2 ) ;
F_32 ( & V_87 -> V_19 ) ;
F_55 ( & V_47 -> V_19 , V_90 ) ;
V_17 = V_46 -> V_22 & V_91 ? 1 : 0 ;
V_73 = - V_92 ;
if ( V_17 ) {
if ( ! F_39 ( & V_87 -> V_15 ) || ! F_39 ( & V_47 -> V_15 ) )
goto V_93;
} else {
if ( V_87 -> V_17 || V_47 -> V_17 )
goto V_93;
F_3 (s, &src->list_head, src_list) {
if ( F_52 ( V_46 , & V_80 -> V_46 ) )
goto V_93;
}
F_3 (s, &dest->list_head, dest_list) {
if ( F_52 ( V_46 , & V_80 -> V_46 ) )
goto V_93;
}
}
if ( ( V_73 = F_47 ( V_83 , V_84 , V_87 , V_46 ,
V_82 -> V_27 != V_83 -> V_27 ) ) < 0 )
goto V_93;
V_88 = 1 ;
if ( ( V_73 = F_47 ( V_85 , V_86 , V_47 , V_46 ,
V_82 -> V_27 != V_85 -> V_27 ) ) < 0 )
goto V_93;
F_18 ( & V_87 -> V_18 , V_22 ) ;
F_19 ( & V_41 -> V_45 , & V_87 -> V_15 ) ;
F_19 ( & V_41 -> V_48 , & V_47 -> V_15 ) ;
F_20 ( & V_87 -> V_18 , V_22 ) ;
V_87 -> V_17 = V_47 -> V_17 = V_17 ;
F_33 ( & V_47 -> V_19 ) ;
F_33 ( & V_87 -> V_19 ) ;
return 0 ;
V_93:
if ( V_88 )
F_29 ( V_83 , V_84 , V_87 , V_46 ,
V_82 -> V_27 != V_83 -> V_27 ) ;
F_31 ( V_41 ) ;
F_33 ( & V_47 -> V_19 ) ;
F_33 ( & V_87 -> V_19 ) ;
return V_73 ;
}
int F_56 ( struct V_2 * V_82 ,
struct V_2 * V_83 ,
struct V_1 * V_84 ,
struct V_2 * V_85 ,
struct V_1 * V_86 ,
struct V_71 * V_46 )
{
struct V_13 * V_87 = & V_84 -> V_32 ;
struct V_13 * V_47 = & V_86 -> V_33 ;
struct V_40 * V_41 ;
int V_73 = - V_55 ;
unsigned long V_22 ;
F_32 ( & V_87 -> V_19 ) ;
F_55 ( & V_47 -> V_19 , V_90 ) ;
F_3 (subs, &src->list_head, src_list) {
if ( F_52 ( V_46 , & V_41 -> V_46 ) ) {
F_18 ( & V_87 -> V_18 , V_22 ) ;
F_28 ( & V_41 -> V_45 ) ;
F_28 ( & V_41 -> V_48 ) ;
F_20 ( & V_87 -> V_18 , V_22 ) ;
V_87 -> V_17 = V_47 -> V_17 = 0 ;
F_29 ( V_83 , V_84 , V_87 , V_46 ,
V_82 -> V_27 != V_83 -> V_27 ) ;
F_29 ( V_85 , V_86 , V_47 , V_46 ,
V_82 -> V_27 != V_85 -> V_27 ) ;
F_31 ( V_41 ) ;
V_73 = 0 ;
break;
}
}
F_33 ( & V_47 -> V_19 ) ;
F_33 ( & V_87 -> V_19 ) ;
return V_73 ;
}
struct V_40 * F_57 ( struct V_13 * V_94 ,
struct V_36 * V_95 )
{
struct V_40 * V_80 , * V_12 = NULL ;
F_58 ( & V_94 -> V_19 ) ;
F_3 (s, &src_grp->list_head, src_list) {
if ( F_51 ( V_95 , & V_80 -> V_46 . V_47 ) ) {
V_12 = V_80 ;
break;
}
}
F_59 ( & V_94 -> V_19 ) ;
return V_12 ;
}
int F_60 ( int V_3 ,
struct V_96 * V_97 ,
int V_98 , int type , int V_61 ,
int V_62 , char * V_99 )
{
struct V_10 V_100 ;
int V_101 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_7 . V_3 = V_3 ;
F_45 ( V_100 . V_31 , V_99 ? V_99 : L_4 ,
sizeof( V_100 . V_31 ) ) ;
V_100 . V_60 = V_98 ;
V_100 . type = type ;
V_100 . V_102 = V_97 ;
V_100 . V_61 = V_61 ;
V_100 . V_62 = V_62 ;
V_101 = F_61 ( V_3 ,
V_103 ,
& V_100 ) ;
if ( V_101 >= 0 )
V_101 = V_100 . V_7 . V_5 ;
return V_101 ;
}
int F_62 ( int V_3 , int V_5 )
{
struct V_10 V_100 ;
int V_73 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_7 . V_3 = V_3 ;
V_100 . V_7 . V_5 = V_5 ;
V_73 = F_61 ( V_3 ,
V_104 ,
& V_100 ) ;
return V_73 ;
}
