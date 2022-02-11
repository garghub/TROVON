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
F_13 ( V_27 L_1 , V_3 -> V_28 ) ;
return NULL ;
}
V_23 = F_14 ( sizeof( * V_23 ) , V_29 ) ;
if ( ! V_23 ) {
F_15 ( L_2 ) ;
return NULL ;
}
V_23 -> V_7 . V_3 = V_3 -> V_28 ;
V_23 -> V_7 . V_5 = - 1 ;
V_23 -> V_30 = V_31 ;
sprintf ( V_23 -> V_32 , L_3 , V_4 ) ;
F_16 ( & V_23 -> V_9 ) ;
F_7 ( & V_23 -> V_33 ) ;
F_7 ( & V_23 -> V_34 ) ;
V_4 = V_5 >= 0 ? V_5 : 0 ;
F_17 ( & V_3 -> V_35 ) ;
F_18 ( & V_3 -> V_6 , V_22 ) ;
F_3 (p, &client->ports_list_head, list) {
if ( V_24 -> V_7 . V_5 > V_4 )
break;
if ( V_5 < 0 )
V_4 = V_24 -> V_7 . V_5 + 1 ;
}
F_19 ( & V_23 -> V_36 , & V_24 -> V_36 ) ;
V_3 -> V_25 ++ ;
V_23 -> V_7 . V_5 = V_4 ;
F_20 ( & V_3 -> V_6 , V_22 ) ;
F_21 ( & V_3 -> V_35 ) ;
sprintf ( V_23 -> V_32 , L_3 , V_4 ) ;
return V_23 ;
}
static struct V_1 * F_22 ( struct V_37 * V_7 ,
struct V_2 * * V_38 )
{
struct V_1 * V_24 ;
* V_38 = F_23 ( V_7 -> V_3 ) ;
if ( * V_38 ) {
V_24 = F_1 ( * V_38 , V_7 -> V_5 ) ;
if ( ! V_24 ) {
F_24 ( * V_38 ) ;
* V_38 = NULL ;
}
return V_24 ;
}
return NULL ;
}
static void F_25 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
struct V_13 * V_14 ,
int V_39 )
{
struct V_15 * V_24 , * V_40 ;
F_26 (p, n, &grp->list_head) {
struct V_41 * V_42 ;
struct V_2 * V_43 ;
struct V_1 * V_44 ;
if ( V_39 == V_45 ) {
V_42 = F_27 ( V_24 , struct V_41 , V_46 ) ;
V_44 = F_22 ( & V_42 -> V_47 . V_48 , & V_43 ) ;
} else {
V_42 = F_27 ( V_24 , struct V_41 , V_49 ) ;
V_44 = F_22 ( & V_42 -> V_47 . V_50 , & V_43 ) ;
}
F_28 ( V_24 ) ;
F_29 ( V_3 , V_5 , V_14 , & V_42 -> V_47 , 0 ) ;
if ( ! V_44 ) {
if ( F_30 ( & V_42 -> V_51 ) )
F_31 ( V_42 ) ;
} else {
struct V_13 * V_52 ;
V_52 = ( V_39 == V_45 ) ? & V_44 -> V_34 : & V_44 -> V_33 ;
F_32 ( & V_52 -> V_19 ) ;
if ( V_39 == V_45 )
F_28 ( & V_42 -> V_49 ) ;
else
F_28 ( & V_42 -> V_46 ) ;
F_33 ( & V_52 -> V_19 ) ;
F_29 ( V_43 , V_44 , V_52 , & V_42 -> V_47 , 1 ) ;
F_31 ( V_42 ) ;
F_34 ( V_44 ) ;
F_24 ( V_43 ) ;
}
}
}
static int F_35 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
V_5 -> V_8 = 1 ;
F_36 ( & V_5 -> V_9 ) ;
F_25 ( V_3 , V_5 , & V_5 -> V_33 , V_45 ) ;
F_25 ( V_3 , V_5 , & V_5 -> V_34 , V_53 ) ;
if ( V_5 -> V_54 )
V_5 -> V_54 ( V_5 -> V_55 ) ;
F_12 ( V_5 -> V_33 . V_16 != 0 ) ;
F_12 ( V_5 -> V_34 . V_16 != 0 ) ;
F_31 ( V_5 ) ;
return 0 ;
}
int F_37 ( struct V_2 * V_3 , int V_5 )
{
unsigned long V_22 ;
struct V_1 * V_12 = NULL , * V_24 ;
F_17 ( & V_3 -> V_35 ) ;
F_18 ( & V_3 -> V_6 , V_22 ) ;
F_3 (p, &client->ports_list_head, list) {
if ( V_24 -> V_7 . V_5 == V_5 ) {
F_28 ( & V_24 -> V_36 ) ;
V_3 -> V_25 -- ;
V_12 = V_24 ;
break;
}
}
F_20 ( & V_3 -> V_6 , V_22 ) ;
F_21 ( & V_3 -> V_35 ) ;
if ( V_12 )
return F_35 ( V_3 , V_12 ) ;
else
return - V_56 ;
}
int F_38 ( struct V_2 * V_3 )
{
unsigned long V_22 ;
struct V_15 V_57 ;
struct V_1 * V_5 , * V_58 ;
F_17 ( & V_3 -> V_35 ) ;
F_18 ( & V_3 -> V_6 , V_22 ) ;
if ( ! F_39 ( & V_3 -> V_59 ) ) {
F_40 ( & V_57 , & V_3 -> V_59 ) ;
F_41 ( & V_3 -> V_59 ) ;
} else {
F_8 ( & V_57 ) ;
}
V_3 -> V_25 = 0 ;
F_20 ( & V_3 -> V_6 , V_22 ) ;
F_42 (port, tmp, &deleted_list, list) {
F_28 ( & V_5 -> V_36 ) ;
F_43 ( V_5 -> V_7 . V_3 , V_5 -> V_7 . V_5 ) ;
F_35 ( V_3 , V_5 ) ;
}
F_21 ( & V_3 -> V_35 ) ;
return 0 ;
}
int F_44 ( struct V_1 * V_5 ,
struct V_10 * V_47 )
{
if ( F_12 ( ! V_5 || ! V_47 ) )
return - V_60 ;
if ( V_47 -> V_32 [ 0 ] )
F_45 ( V_5 -> V_32 , V_47 -> V_32 , sizeof( V_5 -> V_32 ) ) ;
V_5 -> V_61 = V_47 -> V_61 ;
V_5 -> type = V_47 -> type ;
V_5 -> V_62 = V_47 -> V_62 ;
V_5 -> V_63 = V_47 -> V_63 ;
V_5 -> V_64 = V_47 -> V_64 ;
V_5 -> V_65 = ( V_47 -> V_22 & V_66 ) ? 1 : 0 ;
V_5 -> V_67 = ( V_47 -> V_22 & V_68 ) ? 1 : 0 ;
V_5 -> V_69 = V_47 -> V_69 ;
return 0 ;
}
int F_46 ( struct V_1 * V_5 ,
struct V_10 * V_47 )
{
if ( F_12 ( ! V_5 || ! V_47 ) )
return - V_60 ;
F_45 ( V_47 -> V_32 , V_5 -> V_32 , sizeof( V_47 -> V_32 ) ) ;
V_47 -> V_61 = V_5 -> V_61 ;
V_47 -> type = V_5 -> type ;
V_47 -> V_62 = V_5 -> V_62 ;
V_47 -> V_63 = V_5 -> V_63 ;
V_47 -> V_64 = V_5 -> V_64 ;
V_47 -> V_70 = V_5 -> V_33 . V_16 ;
V_47 -> V_71 = V_5 -> V_34 . V_16 ;
V_47 -> V_22 = 0 ;
if ( V_5 -> V_65 ) {
V_47 -> V_22 |= V_66 ;
if ( V_5 -> V_67 )
V_47 -> V_22 |= V_68 ;
V_47 -> V_69 = V_5 -> V_69 ;
}
return 0 ;
}
static int F_47 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
struct V_13 * V_14 ,
struct V_72 * V_47 ,
int V_73 )
{
int V_74 = 0 ;
if ( ! F_48 ( V_5 -> V_30 ) )
return - V_75 ;
V_14 -> V_16 ++ ;
if ( V_14 -> V_20 && ( V_5 -> V_76 || V_14 -> V_16 == 1 ) ) {
V_74 = V_14 -> V_20 ( V_5 -> V_55 , V_47 ) ;
if ( V_74 < 0 ) {
F_49 ( V_5 -> V_30 ) ;
V_14 -> V_16 -- ;
}
}
if ( V_74 >= 0 && V_73 && V_3 -> type == V_77 )
F_50 ( V_5 -> V_7 . V_3 , V_5 -> V_7 . V_5 ,
V_47 , V_78 ) ;
return V_74 ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
struct V_13 * V_14 ,
struct V_72 * V_47 ,
int V_73 )
{
int V_74 = 0 ;
if ( ! V_14 -> V_16 )
return - V_60 ;
V_14 -> V_16 -- ;
if ( V_14 -> V_21 && ( V_5 -> V_76 || V_14 -> V_16 == 0 ) )
V_74 = V_14 -> V_21 ( V_5 -> V_55 , V_47 ) ;
if ( V_73 && V_3 -> type == V_77 )
F_50 ( V_5 -> V_7 . V_3 , V_5 -> V_7 . V_5 ,
V_47 , V_79 ) ;
F_49 ( V_5 -> V_30 ) ;
return V_74 ;
}
static inline int F_51 ( struct V_37 * V_80 , struct V_37 * V_81 )
{
return ( V_80 -> V_3 == V_81 -> V_3 ) && ( V_80 -> V_5 == V_81 -> V_5 ) ;
}
static int F_52 ( struct V_72 * V_80 ,
struct V_72 * V_81 )
{
if ( F_51 ( & V_80 -> V_50 , & V_81 -> V_50 ) &&
F_51 ( & V_80 -> V_48 , & V_81 -> V_48 ) ) {
if ( V_80 -> V_22 && V_80 -> V_22 == V_81 -> V_22 )
return V_80 -> V_82 == V_81 -> V_82 ;
else if ( ! V_80 -> V_22 )
return 1 ;
}
return 0 ;
}
int F_53 ( struct V_2 * V_83 ,
struct V_2 * V_84 ,
struct V_1 * V_85 ,
struct V_2 * V_86 ,
struct V_1 * V_87 ,
struct V_72 * V_47 )
{
struct V_13 * V_88 = & V_85 -> V_33 ;
struct V_13 * V_48 = & V_87 -> V_34 ;
struct V_41 * V_42 , * V_81 ;
int V_74 , V_89 = 0 ;
unsigned long V_22 ;
int V_17 ;
V_42 = F_14 ( sizeof( * V_42 ) , V_29 ) ;
if ( ! V_42 )
return - V_90 ;
V_42 -> V_47 = * V_47 ;
F_54 ( & V_42 -> V_51 , 2 ) ;
F_32 ( & V_88 -> V_19 ) ;
F_55 ( & V_48 -> V_19 , V_91 ) ;
V_17 = V_47 -> V_22 & V_92 ? 1 : 0 ;
V_74 = - V_93 ;
if ( V_17 ) {
if ( ! F_39 ( & V_88 -> V_15 ) || ! F_39 ( & V_48 -> V_15 ) )
goto V_94;
} else {
if ( V_88 -> V_17 || V_48 -> V_17 )
goto V_94;
F_3 (s, &src->list_head, src_list) {
if ( F_52 ( V_47 , & V_81 -> V_47 ) )
goto V_94;
}
F_3 (s, &dest->list_head, dest_list) {
if ( F_52 ( V_47 , & V_81 -> V_47 ) )
goto V_94;
}
}
if ( ( V_74 = F_47 ( V_84 , V_85 , V_88 , V_47 ,
V_83 -> V_28 != V_84 -> V_28 ) ) < 0 )
goto V_94;
V_89 = 1 ;
if ( ( V_74 = F_47 ( V_86 , V_87 , V_48 , V_47 ,
V_83 -> V_28 != V_86 -> V_28 ) ) < 0 )
goto V_94;
F_18 ( & V_88 -> V_18 , V_22 ) ;
F_19 ( & V_42 -> V_46 , & V_88 -> V_15 ) ;
F_19 ( & V_42 -> V_49 , & V_48 -> V_15 ) ;
F_20 ( & V_88 -> V_18 , V_22 ) ;
V_88 -> V_17 = V_48 -> V_17 = V_17 ;
F_33 ( & V_48 -> V_19 ) ;
F_33 ( & V_88 -> V_19 ) ;
return 0 ;
V_94:
if ( V_89 )
F_29 ( V_84 , V_85 , V_88 , V_47 ,
V_83 -> V_28 != V_84 -> V_28 ) ;
F_31 ( V_42 ) ;
F_33 ( & V_48 -> V_19 ) ;
F_33 ( & V_88 -> V_19 ) ;
return V_74 ;
}
int F_56 ( struct V_2 * V_83 ,
struct V_2 * V_84 ,
struct V_1 * V_85 ,
struct V_2 * V_86 ,
struct V_1 * V_87 ,
struct V_72 * V_47 )
{
struct V_13 * V_88 = & V_85 -> V_33 ;
struct V_13 * V_48 = & V_87 -> V_34 ;
struct V_41 * V_42 ;
int V_74 = - V_56 ;
unsigned long V_22 ;
F_32 ( & V_88 -> V_19 ) ;
F_55 ( & V_48 -> V_19 , V_91 ) ;
F_3 (subs, &src->list_head, src_list) {
if ( F_52 ( V_47 , & V_42 -> V_47 ) ) {
F_18 ( & V_88 -> V_18 , V_22 ) ;
F_28 ( & V_42 -> V_46 ) ;
F_28 ( & V_42 -> V_49 ) ;
F_20 ( & V_88 -> V_18 , V_22 ) ;
V_88 -> V_17 = V_48 -> V_17 = 0 ;
F_29 ( V_84 , V_85 , V_88 , V_47 ,
V_83 -> V_28 != V_84 -> V_28 ) ;
F_29 ( V_86 , V_87 , V_48 , V_47 ,
V_83 -> V_28 != V_86 -> V_28 ) ;
F_31 ( V_42 ) ;
V_74 = 0 ;
break;
}
}
F_33 ( & V_48 -> V_19 ) ;
F_33 ( & V_88 -> V_19 ) ;
return V_74 ;
}
struct V_41 * F_57 ( struct V_13 * V_95 ,
struct V_37 * V_96 )
{
struct V_41 * V_81 , * V_12 = NULL ;
F_58 ( & V_95 -> V_19 ) ;
F_3 (s, &src_grp->list_head, src_list) {
if ( F_51 ( V_96 , & V_81 -> V_47 . V_48 ) ) {
V_12 = V_81 ;
break;
}
}
F_59 ( & V_95 -> V_19 ) ;
return V_12 ;
}
int F_60 ( int V_3 ,
struct V_97 * V_98 ,
int V_99 , int type , int V_62 ,
int V_63 , char * V_100 )
{
struct V_10 V_101 ;
int V_102 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_101 . V_7 . V_3 = V_3 ;
F_45 ( V_101 . V_32 , V_100 ? V_100 : L_4 ,
sizeof( V_101 . V_32 ) ) ;
V_101 . V_61 = V_99 ;
V_101 . type = type ;
V_101 . V_103 = V_98 ;
V_101 . V_62 = V_62 ;
V_101 . V_63 = V_63 ;
V_102 = F_61 ( V_3 ,
V_104 ,
& V_101 ) ;
if ( V_102 >= 0 )
V_102 = V_101 . V_7 . V_5 ;
return V_102 ;
}
int F_62 ( int V_3 , int V_5 )
{
struct V_10 V_101 ;
int V_74 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_101 . V_7 . V_3 = V_3 ;
V_101 . V_7 . V_5 = V_5 ;
V_74 = F_61 ( V_3 ,
V_105 ,
& V_101 ) ;
return V_74 ;
}
