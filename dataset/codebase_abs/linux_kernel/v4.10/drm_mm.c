static T_1 void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 [ V_4 ] ;
struct V_5 V_6 = {
. V_3 = V_3 ,
. V_7 = V_4 ,
. V_8 = 1
} ;
F_2 ( & V_6 ) ;
if ( V_6 . V_9 != 0 &&
V_6 . V_3 [ V_6 . V_9 - 1 ] == V_10 )
V_6 . V_9 -- ;
V_2 -> V_11 = F_3 ( & V_6 , V_12 ) ;
}
static void F_4 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
unsigned long V_3 [ V_4 ] ;
char * V_15 ;
V_15 = F_5 ( V_16 , V_17 ) ;
if ( ! V_15 )
return;
F_6 (node, &mm->head_node.node_list, node_list) {
struct V_5 V_6 = {
. V_3 = V_3 ,
. V_7 = V_4
} ;
if ( ! V_2 -> V_11 ) {
F_7 ( L_1 ,
V_2 -> V_18 , V_2 -> V_19 ) ;
continue;
}
F_8 ( V_2 -> V_11 , & V_6 ) ;
F_9 ( V_15 , V_16 , & V_6 , 0 ) ;
F_7 ( L_2 ,
V_2 -> V_18 , V_2 -> V_19 , V_15 ) ;
}
F_10 ( V_15 ) ;
}
static void F_1 ( struct V_1 * V_2 ) { }
static void F_4 ( struct V_13 * V_14 ) { }
struct V_1 *
F_11 ( struct V_13 * V_14 , T_2 V_18 , T_2 V_20 )
{
return F_12 ( & V_14 -> V_21 ,
V_18 , V_20 ) ;
}
static void F_13 ( struct V_1 * V_22 ,
struct V_1 * V_2 )
{
struct V_13 * V_14 = V_22 -> V_14 ;
struct V_23 * * V_24 , * V_25 ;
struct V_1 * V_26 ;
V_2 -> V_27 = F_14 ( V_2 ) ;
if ( V_22 -> V_28 ) {
V_25 = & V_22 -> V_25 ;
while ( V_25 ) {
V_26 = F_15 ( V_25 , struct V_1 , V_25 ) ;
if ( V_26 -> V_27 >= V_2 -> V_27 )
break;
V_26 -> V_27 = V_2 -> V_27 ;
V_25 = F_16 ( V_25 ) ;
}
V_25 = & V_22 -> V_25 ;
V_24 = & V_22 -> V_25 . V_29 ;
} else {
V_25 = NULL ;
V_24 = & V_14 -> V_21 . V_23 ;
}
while ( * V_24 ) {
V_25 = * V_24 ;
V_26 = F_15 ( V_25 , struct V_1 , V_25 ) ;
if ( V_26 -> V_27 < V_2 -> V_27 )
V_26 -> V_27 = V_2 -> V_27 ;
if ( V_2 -> V_18 < V_26 -> V_18 )
V_24 = & V_26 -> V_25 . V_30 ;
else
V_24 = & V_26 -> V_25 . V_29 ;
}
F_17 ( & V_2 -> V_25 , V_25 , V_24 ) ;
F_18 ( & V_2 -> V_25 ,
& V_14 -> V_21 ,
& V_31 ) ;
}
static void F_19 ( struct V_1 * V_22 ,
struct V_1 * V_2 ,
T_2 V_19 , unsigned V_32 ,
unsigned long V_33 ,
enum V_34 V_35 )
{
struct V_13 * V_14 = V_22 -> V_14 ;
T_2 V_36 = F_20 ( V_22 ) ;
T_2 V_37 = F_21 ( V_22 ) ;
T_2 V_38 = V_36 ;
T_2 V_39 = V_37 ;
F_22 ( V_2 -> V_28 ) ;
if ( V_14 -> V_40 )
V_14 -> V_40 ( V_22 , V_33 , & V_38 , & V_39 ) ;
if ( V_35 & V_41 )
V_38 = V_39 - V_19 ;
if ( V_32 ) {
T_2 V_42 = V_38 ;
unsigned V_43 ;
V_43 = F_23 ( V_42 , V_32 ) ;
if ( V_43 ) {
if ( V_35 & V_41 )
V_38 -= V_43 ;
else
V_38 += V_32 - V_43 ;
}
}
F_22 ( V_38 < V_36 ) ;
F_22 ( V_39 > V_37 ) ;
if ( V_38 == V_36 ) {
V_22 -> V_44 = 0 ;
F_24 ( & V_22 -> V_45 ) ;
}
V_2 -> V_18 = V_38 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_33 = V_33 ;
V_2 -> V_28 = 1 ;
F_25 ( & V_2 -> V_46 , & V_22 -> V_46 ) ;
F_13 ( V_22 , V_2 ) ;
F_22 ( V_2 -> V_18 + V_2 -> V_19 > V_39 ) ;
V_2 -> V_44 = 0 ;
if ( F_26 ( V_2 ) < V_37 ) {
F_25 ( & V_2 -> V_45 , & V_14 -> V_45 ) ;
V_2 -> V_44 = 1 ;
}
F_1 ( V_2 ) ;
}
int F_27 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
T_2 V_47 = V_2 -> V_18 + V_2 -> V_19 ;
struct V_1 * V_48 ;
T_2 V_36 , V_37 ;
T_2 V_38 , V_39 ;
if ( F_28 ( V_2 -> V_19 == 0 ) )
return - V_49 ;
V_47 = V_2 -> V_18 + V_2 -> V_19 ;
V_48 = F_12 ( & V_14 -> V_21 ,
V_2 -> V_18 , ~ ( T_2 ) 0 ) ;
if ( V_48 ) {
if ( V_48 -> V_18 < V_47 )
return - V_50 ;
} else {
V_48 = F_29 ( & V_14 -> V_51 . V_46 ,
F_30 ( * V_48 ) , V_46 ) ;
}
V_48 = F_31 ( & V_48 -> V_46 , F_30 ( * V_48 ) , V_46 ) ;
if ( ! V_48 -> V_44 )
return - V_50 ;
V_38 = V_36 = F_26 ( V_48 ) ;
V_39 = V_37 = F_32 ( V_48 ) ;
if ( V_14 -> V_40 )
V_14 -> V_40 ( V_48 , V_2 -> V_33 , & V_38 , & V_39 ) ;
if ( V_38 > V_2 -> V_18 || V_39 < V_47 )
return - V_50 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_28 = 1 ;
F_25 ( & V_2 -> V_46 , & V_48 -> V_46 ) ;
F_13 ( V_48 , V_2 ) ;
if ( V_2 -> V_18 == V_36 ) {
V_48 -> V_44 = 0 ;
F_24 ( & V_48 -> V_45 ) ;
}
V_2 -> V_44 = 0 ;
if ( V_47 != V_37 ) {
F_25 ( & V_2 -> V_45 , & V_14 -> V_45 ) ;
V_2 -> V_44 = 1 ;
}
F_1 ( V_2 ) ;
return 0 ;
}
int F_33 ( struct V_13 * V_14 , struct V_1 * V_2 ,
T_2 V_19 , unsigned V_32 ,
unsigned long V_33 ,
enum V_52 V_53 ,
enum V_34 V_54 )
{
struct V_1 * V_22 ;
if ( F_28 ( V_19 == 0 ) )
return - V_49 ;
V_22 = F_34 ( V_14 , V_19 , V_32 ,
V_33 , V_53 ) ;
if ( ! V_22 )
return - V_50 ;
F_19 ( V_22 , V_2 , V_19 , V_32 , V_33 , V_54 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_22 ,
struct V_1 * V_2 ,
T_2 V_19 , unsigned V_32 ,
unsigned long V_33 ,
T_2 V_18 , T_2 V_47 ,
enum V_34 V_35 )
{
struct V_13 * V_14 = V_22 -> V_14 ;
T_2 V_36 = F_20 ( V_22 ) ;
T_2 V_37 = F_21 ( V_22 ) ;
T_2 V_38 = V_36 ;
T_2 V_39 = V_37 ;
F_22 ( ! V_22 -> V_44 || V_2 -> V_28 ) ;
if ( V_38 < V_18 )
V_38 = V_18 ;
if ( V_39 > V_47 )
V_39 = V_47 ;
if ( V_14 -> V_40 )
V_14 -> V_40 ( V_22 , V_33 , & V_38 , & V_39 ) ;
if ( V_35 & V_41 )
V_38 = V_39 - V_19 ;
if ( V_32 ) {
T_2 V_42 = V_38 ;
unsigned V_43 ;
V_43 = F_23 ( V_42 , V_32 ) ;
if ( V_43 ) {
if ( V_35 & V_41 )
V_38 -= V_43 ;
else
V_38 += V_32 - V_43 ;
}
}
if ( V_38 == V_36 ) {
V_22 -> V_44 = 0 ;
F_24 ( & V_22 -> V_45 ) ;
}
V_2 -> V_18 = V_38 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_33 = V_33 ;
V_2 -> V_28 = 1 ;
F_25 ( & V_2 -> V_46 , & V_22 -> V_46 ) ;
F_13 ( V_22 , V_2 ) ;
F_22 ( V_2 -> V_18 < V_18 ) ;
F_22 ( V_2 -> V_18 < V_38 ) ;
F_22 ( V_2 -> V_18 + V_2 -> V_19 > V_39 ) ;
F_22 ( V_2 -> V_18 + V_2 -> V_19 > V_47 ) ;
V_2 -> V_44 = 0 ;
if ( F_26 ( V_2 ) < V_37 ) {
F_25 ( & V_2 -> V_45 , & V_14 -> V_45 ) ;
V_2 -> V_44 = 1 ;
}
F_1 ( V_2 ) ;
}
int F_36 ( struct V_13 * V_14 , struct V_1 * V_2 ,
T_2 V_19 , unsigned V_32 ,
unsigned long V_33 ,
T_2 V_18 , T_2 V_47 ,
enum V_52 V_53 ,
enum V_34 V_54 )
{
struct V_1 * V_22 ;
if ( F_28 ( V_19 == 0 ) )
return - V_49 ;
V_22 = F_37 ( V_14 ,
V_19 , V_32 , V_33 ,
V_18 , V_47 , V_53 ) ;
if ( ! V_22 )
return - V_50 ;
F_35 ( V_22 , V_2 ,
V_19 , V_32 , V_33 ,
V_18 , V_47 , V_54 ) ;
return 0 ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_1 * V_55 ;
if ( F_28 ( ! V_2 -> V_28 ) )
return;
F_22 ( V_2 -> V_56 || V_2 -> V_57
|| V_2 -> V_58 ) ;
V_55 =
F_29 ( V_2 -> V_46 . V_59 , struct V_1 , V_46 ) ;
if ( V_2 -> V_44 ) {
F_22 ( F_26 ( V_2 ) ==
F_32 ( V_2 ) ) ;
F_24 ( & V_2 -> V_45 ) ;
} else
F_22 ( F_26 ( V_2 ) !=
F_32 ( V_2 ) ) ;
if ( ! V_55 -> V_44 ) {
V_55 -> V_44 = 1 ;
F_25 ( & V_55 -> V_45 , & V_14 -> V_45 ) ;
} else
F_39 ( & V_55 -> V_45 , & V_14 -> V_45 ) ;
F_40 ( V_2 , & V_14 -> V_21 ) ;
F_24 ( & V_2 -> V_46 ) ;
V_2 -> V_28 = 0 ;
}
static int F_41 ( T_2 V_18 , T_2 V_47 , T_2 V_19 , unsigned V_32 )
{
if ( V_47 - V_18 < V_19 )
return 0 ;
if ( V_32 ) {
T_2 V_42 = V_18 ;
unsigned V_43 ;
V_43 = F_23 ( V_42 , V_32 ) ;
if ( V_43 )
V_18 += V_32 - V_43 ;
}
return V_47 >= V_18 + V_19 ;
}
static struct V_1 * F_34 ( const struct V_13 * V_14 ,
T_2 V_19 ,
unsigned V_32 ,
unsigned long V_33 ,
enum V_52 V_35 )
{
struct V_1 * V_60 ;
struct V_1 * V_61 ;
T_2 V_38 ;
T_2 V_39 ;
T_2 V_62 ;
F_22 ( V_14 -> V_63 ) ;
V_61 = NULL ;
V_62 = ~ 0UL ;
F_42 (entry, mm, adj_start, adj_end,
flags & DRM_MM_SEARCH_BELOW) {
T_2 V_64 = V_39 - V_38 ;
if ( V_14 -> V_40 ) {
V_14 -> V_40 ( V_60 , V_33 , & V_38 , & V_39 ) ;
if ( V_39 <= V_38 )
continue;
}
if ( ! F_41 ( V_38 , V_39 , V_19 , V_32 ) )
continue;
if ( ! ( V_35 & V_65 ) )
return V_60 ;
if ( V_64 < V_62 ) {
V_61 = V_60 ;
V_62 = V_64 ;
}
}
return V_61 ;
}
static struct V_1 * F_37 ( const struct V_13 * V_14 ,
T_2 V_19 ,
unsigned V_32 ,
unsigned long V_33 ,
T_2 V_18 ,
T_2 V_47 ,
enum V_52 V_35 )
{
struct V_1 * V_60 ;
struct V_1 * V_61 ;
T_2 V_38 ;
T_2 V_39 ;
T_2 V_62 ;
F_22 ( V_14 -> V_63 ) ;
V_61 = NULL ;
V_62 = ~ 0UL ;
F_42 (entry, mm, adj_start, adj_end,
flags & DRM_MM_SEARCH_BELOW) {
T_2 V_64 = V_39 - V_38 ;
if ( V_38 < V_18 )
V_38 = V_18 ;
if ( V_39 > V_47 )
V_39 = V_47 ;
if ( V_14 -> V_40 ) {
V_14 -> V_40 ( V_60 , V_33 , & V_38 , & V_39 ) ;
if ( V_39 <= V_38 )
continue;
}
if ( ! F_41 ( V_38 , V_39 , V_19 , V_32 ) )
continue;
if ( ! ( V_35 & V_65 ) )
return V_60 ;
if ( V_64 < V_62 ) {
V_61 = V_60 ;
V_62 = V_64 ;
}
}
return V_61 ;
}
void F_43 ( struct V_1 * V_66 , struct V_1 * V_67 )
{
F_44 ( & V_66 -> V_46 , & V_67 -> V_46 ) ;
F_44 ( & V_66 -> V_45 , & V_67 -> V_45 ) ;
F_45 ( & V_66 -> V_25 , & V_67 -> V_25 , & V_66 -> V_14 -> V_21 ) ;
V_67 -> V_44 = V_66 -> V_44 ;
V_67 -> V_14 = V_66 -> V_14 ;
V_67 -> V_18 = V_66 -> V_18 ;
V_67 -> V_19 = V_66 -> V_19 ;
V_67 -> V_33 = V_66 -> V_33 ;
V_67 -> V_27 = V_66 -> V_27 ;
V_66 -> V_28 = 0 ;
V_67 -> V_28 = 1 ;
}
void F_46 ( struct V_13 * V_14 ,
T_2 V_19 ,
unsigned V_32 ,
unsigned long V_33 )
{
V_14 -> V_68 = V_33 ;
V_14 -> V_69 = V_32 ;
V_14 -> V_70 = V_19 ;
V_14 -> V_63 = 0 ;
V_14 -> V_71 = 0 ;
V_14 -> V_72 = 0 ;
V_14 -> V_73 = 0 ;
V_14 -> V_74 = NULL ;
}
void F_47 ( struct V_13 * V_14 ,
T_2 V_19 ,
unsigned V_32 ,
unsigned long V_33 ,
T_2 V_18 ,
T_2 V_47 )
{
V_14 -> V_68 = V_33 ;
V_14 -> V_69 = V_32 ;
V_14 -> V_70 = V_19 ;
V_14 -> V_63 = 0 ;
V_14 -> V_71 = 0 ;
V_14 -> V_72 = 0 ;
V_14 -> V_75 = V_18 ;
V_14 -> V_76 = V_47 ;
V_14 -> V_73 = 1 ;
V_14 -> V_74 = NULL ;
}
bool F_48 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_1 * V_55 ;
T_2 V_36 , V_37 ;
T_2 V_38 , V_39 ;
V_14 -> V_63 ++ ;
F_22 ( V_2 -> V_56 ) ;
V_2 -> V_56 = 1 ;
V_55 = F_29 ( V_2 -> V_46 . V_59 , struct V_1 ,
V_46 ) ;
V_2 -> V_77 = V_55 -> V_44 ;
V_55 -> V_44 = 1 ;
F_24 ( & V_2 -> V_46 ) ;
V_2 -> V_46 . V_59 = & V_55 -> V_46 ;
V_2 -> V_46 . V_78 = & V_14 -> V_74 -> V_46 ;
V_14 -> V_74 = V_2 ;
V_38 = V_36 = F_20 ( V_55 ) ;
V_39 = V_37 = F_21 ( V_55 ) ;
if ( V_14 -> V_73 ) {
if ( V_38 < V_14 -> V_75 )
V_38 = V_14 -> V_75 ;
if ( V_39 > V_14 -> V_76 )
V_39 = V_14 -> V_76 ;
}
if ( V_14 -> V_40 )
V_14 -> V_40 ( V_55 , V_14 -> V_68 ,
& V_38 , & V_39 ) ;
if ( F_41 ( V_38 , V_39 ,
V_14 -> V_70 , V_14 -> V_69 ) ) {
V_14 -> V_71 = V_36 ;
V_14 -> V_72 = V_37 ;
return true ;
}
return false ;
}
bool F_49 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_1 * V_55 ;
V_14 -> V_63 -- ;
F_22 ( ! V_2 -> V_56 ) ;
V_2 -> V_56 = 0 ;
V_55 = F_29 ( V_2 -> V_46 . V_59 , struct V_1 ,
V_46 ) ;
V_55 -> V_44 = V_2 -> V_77 ;
F_25 ( & V_2 -> V_46 , & V_55 -> V_46 ) ;
return ( F_21 ( V_2 ) > V_14 -> V_71 &&
V_2 -> V_18 < V_14 -> V_72 ) ;
}
bool F_50 ( struct V_13 * V_14 )
{
struct V_79 * V_80 = & V_14 -> V_51 . V_46 ;
return ( V_80 -> V_78 -> V_78 == V_80 ) ;
}
void F_51 ( struct V_13 * V_14 , T_2 V_18 , T_2 V_19 )
{
F_52 ( & V_14 -> V_45 ) ;
V_14 -> V_63 = 0 ;
F_52 ( & V_14 -> V_51 . V_46 ) ;
V_14 -> V_51 . V_28 = 0 ;
V_14 -> V_51 . V_44 = 1 ;
V_14 -> V_51 . V_56 = 0 ;
V_14 -> V_51 . V_57 = 0 ;
V_14 -> V_51 . V_58 = 0 ;
V_14 -> V_51 . V_14 = V_14 ;
V_14 -> V_51 . V_18 = V_18 + V_19 ;
V_14 -> V_51 . V_19 = V_18 - V_14 -> V_51 . V_18 ;
F_53 ( & V_14 -> V_51 . V_45 , & V_14 -> V_45 ) ;
V_14 -> V_21 = V_81 ;
V_14 -> V_40 = NULL ;
}
void F_54 ( struct V_13 * V_14 )
{
if ( F_55 ( ! F_56 ( & V_14 -> V_51 . V_46 ) ,
L_3 ) )
F_4 ( V_14 ) ;
}
static T_2 F_57 ( struct V_1 * V_60 ,
const char * V_82 )
{
T_2 V_36 , V_37 , V_64 ;
if ( V_60 -> V_44 ) {
V_36 = F_20 ( V_60 ) ;
V_37 = F_21 ( V_60 ) ;
V_64 = V_37 - V_36 ;
F_58 ( L_4 , V_82 , V_36 ,
V_37 , V_64 ) ;
return V_64 ;
}
return 0 ;
}
void F_59 ( struct V_13 * V_14 , const char * V_82 )
{
struct V_1 * V_60 ;
T_2 V_83 = 0 , V_84 = 0 , V_85 = 0 ;
V_84 += F_57 ( & V_14 -> V_51 , V_82 ) ;
F_60 (entry, mm) {
F_58 ( L_5 , V_82 , V_60 -> V_18 ,
V_60 -> V_18 + V_60 -> V_19 , V_60 -> V_19 ) ;
V_83 += V_60 -> V_19 ;
V_84 += F_57 ( V_60 , V_82 ) ;
}
V_85 = V_84 + V_83 ;
F_58 ( L_6 , V_82 , V_85 ,
V_83 , V_84 ) ;
}
static T_2 F_61 ( struct V_86 * V_87 , struct V_1 * V_60 )
{
T_2 V_36 , V_37 , V_64 ;
if ( V_60 -> V_44 ) {
V_36 = F_20 ( V_60 ) ;
V_37 = F_21 ( V_60 ) ;
V_64 = V_37 - V_36 ;
F_62 ( V_87 , L_7 , V_36 ,
V_37 , V_64 ) ;
return V_64 ;
}
return 0 ;
}
int F_63 ( struct V_86 * V_87 , struct V_13 * V_14 )
{
struct V_1 * V_60 ;
T_2 V_83 = 0 , V_84 = 0 , V_85 = 0 ;
V_84 += F_61 ( V_87 , & V_14 -> V_51 ) ;
F_60 (entry, mm) {
F_62 ( V_87 , L_8 , V_60 -> V_18 ,
V_60 -> V_18 + V_60 -> V_19 , V_60 -> V_19 ) ;
V_83 += V_60 -> V_19 ;
V_84 += F_61 ( V_87 , V_60 ) ;
}
V_85 = V_84 + V_83 ;
F_62 ( V_87 , L_9 , V_85 ,
V_83 , V_84 ) ;
return 0 ;
}
