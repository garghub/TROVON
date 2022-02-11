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
F_6 (node, drm_mm_nodes(mm), node_list) {
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
F_11 ( const struct V_13 * V_14 , T_2 V_18 , T_2 V_20 )
{
return F_12 ( (struct V_21 * ) & V_14 -> V_22 ,
V_18 , V_20 ) ? : (struct V_1 * ) & V_14 -> V_23 ;
}
static void F_13 ( struct V_1 * V_24 ,
struct V_1 * V_2 )
{
struct V_13 * V_14 = V_24 -> V_14 ;
struct V_25 * * V_26 , * V_27 ;
struct V_1 * V_28 ;
bool V_29 = true ;
V_2 -> V_30 = F_14 ( V_2 ) ;
if ( V_24 -> V_31 ) {
V_27 = & V_24 -> V_27 ;
while ( V_27 ) {
V_28 = F_15 ( V_27 , struct V_1 , V_27 ) ;
if ( V_28 -> V_30 >= V_2 -> V_30 )
break;
V_28 -> V_30 = V_2 -> V_30 ;
V_27 = F_16 ( V_27 ) ;
}
V_27 = & V_24 -> V_27 ;
V_26 = & V_24 -> V_27 . V_32 ;
V_29 = false ;
} else {
V_27 = NULL ;
V_26 = & V_14 -> V_22 . V_33 . V_25 ;
}
while ( * V_26 ) {
V_27 = * V_26 ;
V_28 = F_15 ( V_27 , struct V_1 , V_27 ) ;
if ( V_28 -> V_30 < V_2 -> V_30 )
V_28 -> V_30 = V_2 -> V_30 ;
if ( V_2 -> V_18 < V_28 -> V_18 )
V_26 = & V_28 -> V_27 . V_34 ;
else {
V_26 = & V_28 -> V_27 . V_32 ;
V_29 = true ;
}
}
F_17 ( & V_2 -> V_27 , V_27 , V_26 ) ;
F_18 ( & V_2 -> V_27 , & V_14 -> V_22 , V_29 ,
& V_35 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_2 -> V_36 =
F_20 ( V_2 ) - F_21 ( V_2 ) ;
F_22 ( ! F_23 ( V_2 ) ) ;
F_24 ( V_14 -> V_37 , V_38 , V_39 ) ;
F_24 ( V_14 -> V_40 , V_41 , V_42 ) ;
F_25 ( & V_2 -> V_43 , & V_14 -> V_43 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_22 ( ! F_23 ( V_2 ) ) ;
F_27 ( & V_2 -> V_43 ) ;
F_28 ( & V_2 -> V_38 , & V_2 -> V_14 -> V_37 ) ;
F_28 ( & V_2 -> V_41 , & V_2 -> V_14 -> V_40 ) ;
V_2 -> V_36 = 0 ;
F_22 ( F_23 ( V_2 ) ) ;
}
static inline struct V_1 * F_29 ( struct V_25 * V_27 )
{
return F_30 ( V_27 , struct V_1 , V_38 ) ;
}
static inline struct V_1 * F_31 ( struct V_25 * V_27 )
{
return F_30 ( V_27 , struct V_1 , V_41 ) ;
}
static inline T_2 V_38 ( struct V_25 * V_27 )
{
return F_15 ( V_27 , struct V_1 , V_38 ) -> V_36 ;
}
static struct V_1 * F_32 ( struct V_13 * V_14 , T_2 V_19 )
{
struct V_25 * V_44 = NULL ;
struct V_25 * * V_26 = & V_14 -> V_37 . V_25 ;
while ( * V_26 ) {
struct V_25 * V_27 = * V_26 ;
if ( V_19 <= V_38 ( V_27 ) ) {
V_26 = & V_27 -> V_34 ;
V_44 = V_27 ;
} else {
V_26 = & V_27 -> V_32 ;
}
}
return F_29 ( V_44 ) ;
}
static struct V_1 * F_33 ( struct V_13 * V_14 , T_2 V_45 )
{
struct V_1 * V_2 = NULL ;
struct V_25 * * V_26 = & V_14 -> V_40 . V_25 ;
while ( * V_26 ) {
T_2 V_46 ;
V_2 = F_31 ( * V_26 ) ;
V_46 = F_21 ( V_2 ) ;
if ( V_45 < V_46 )
V_26 = & V_2 -> V_41 . V_34 ;
else if ( V_45 > V_46 + V_2 -> V_36 )
V_26 = & V_2 -> V_41 . V_32 ;
else
break;
}
return V_2 ;
}
static struct V_1 *
F_34 ( struct V_13 * V_14 ,
T_2 V_18 , T_2 V_47 , T_2 V_19 ,
enum V_48 V_49 )
{
if ( F_35 ( & V_14 -> V_37 ) )
return NULL ;
switch ( V_49 ) {
default:
case V_50 :
return F_32 ( V_14 , V_19 ) ;
case V_51 :
return F_33 ( V_14 , V_18 ) ;
case V_52 :
return F_33 ( V_14 , V_47 ) ;
case V_53 :
return F_36 ( & V_14 -> V_43 ,
struct V_1 ,
V_43 ) ;
}
}
static struct V_1 *
F_37 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
enum V_48 V_49 )
{
switch ( V_49 ) {
default:
case V_50 :
return F_29 ( F_38 ( & V_2 -> V_38 ) ) ;
case V_51 :
return F_31 ( F_38 ( & V_2 -> V_41 ) ) ;
case V_52 :
return F_31 ( F_39 ( & V_2 -> V_41 ) ) ;
case V_53 :
V_2 = F_40 ( V_2 , V_43 ) ;
return & V_2 -> V_43 == & V_14 -> V_43 ? NULL : V_2 ;
}
}
int F_41 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
T_2 V_47 = V_2 -> V_18 + V_2 -> V_19 ;
struct V_1 * V_54 ;
T_2 V_46 , V_55 ;
T_2 V_56 , V_57 ;
V_47 = V_2 -> V_18 + V_2 -> V_19 ;
if ( F_42 ( V_47 <= V_2 -> V_18 ) )
return - V_58 ;
V_54 = F_33 ( V_14 , V_2 -> V_18 ) ;
if ( ! V_54 )
return - V_58 ;
V_56 = V_46 = F_21 ( V_54 ) ;
V_57 = V_55 = V_46 + V_54 -> V_36 ;
if ( V_14 -> V_59 )
V_14 -> V_59 ( V_54 , V_2 -> V_60 , & V_56 , & V_57 ) ;
if ( V_56 > V_2 -> V_18 || V_57 < V_47 )
return - V_58 ;
V_2 -> V_14 = V_14 ;
F_25 ( & V_2 -> V_61 , & V_54 -> V_61 ) ;
F_13 ( V_54 , V_2 ) ;
V_2 -> V_31 = true ;
V_2 -> V_36 = 0 ;
F_26 ( V_54 ) ;
if ( V_2 -> V_18 > V_46 )
F_19 ( V_54 ) ;
if ( V_47 < V_55 )
F_19 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
int F_43 ( struct V_13 * const V_14 ,
struct V_1 * const V_2 ,
T_2 V_19 , T_2 V_62 ,
unsigned long V_60 ,
T_2 V_63 , T_2 V_64 ,
enum V_48 V_49 )
{
struct V_1 * V_54 ;
T_2 V_65 ;
F_22 ( V_63 >= V_64 ) ;
if ( F_42 ( V_19 == 0 || V_64 - V_63 < V_19 ) )
return - V_58 ;
if ( V_62 <= 1 )
V_62 = 0 ;
V_65 = F_44 ( V_62 ) ? V_62 - 1 : 0 ;
for ( V_54 = F_34 ( V_14 , V_63 , V_64 , V_19 , V_49 ) ; V_54 ;
V_54 = F_37 ( V_14 , V_54 , V_49 ) ) {
T_2 V_46 = F_21 ( V_54 ) ;
T_2 V_55 = V_46 + V_54 -> V_36 ;
T_2 V_56 , V_57 ;
T_2 V_66 , V_67 ;
if ( V_49 == V_51 && V_46 >= V_64 )
break;
if ( V_49 == V_52 && V_55 <= V_63 )
break;
V_66 = V_46 ;
V_67 = V_55 ;
if ( V_14 -> V_59 )
V_14 -> V_59 ( V_54 , V_60 , & V_66 , & V_67 ) ;
V_56 = F_45 ( V_66 , V_63 ) ;
V_57 = F_46 ( V_67 , V_64 ) ;
if ( V_57 <= V_56 || V_57 - V_56 < V_19 )
continue;
if ( V_49 == V_52 )
V_56 = V_57 - V_19 ;
if ( V_62 ) {
T_2 V_68 ;
if ( F_47 ( V_65 ) )
V_68 = V_56 & V_65 ;
else
F_48 ( V_56 , V_62 , & V_68 ) ;
if ( V_68 ) {
V_56 -= V_68 ;
if ( V_49 != V_52 )
V_56 += V_62 ;
if ( V_56 < F_45 ( V_66 , V_63 ) ||
F_46 ( V_67 , V_64 ) - V_56 < V_19 )
continue;
if ( V_57 <= V_56 ||
V_57 - V_56 < V_19 )
continue;
}
}
V_2 -> V_14 = V_14 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_18 = V_56 ;
V_2 -> V_60 = V_60 ;
V_2 -> V_36 = 0 ;
F_25 ( & V_2 -> V_61 , & V_54 -> V_61 ) ;
F_13 ( V_54 , V_2 ) ;
V_2 -> V_31 = true ;
F_26 ( V_54 ) ;
if ( V_56 > V_46 )
F_19 ( V_54 ) ;
if ( V_56 + V_19 < V_55 )
F_19 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
return - V_58 ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_1 * V_69 ;
F_22 ( ! V_2 -> V_31 ) ;
F_22 ( V_2 -> V_70 ) ;
V_69 = F_50 ( V_2 , V_61 ) ;
if ( F_23 ( V_2 ) )
F_26 ( V_2 ) ;
F_51 ( V_2 , & V_14 -> V_22 ) ;
F_27 ( & V_2 -> V_61 ) ;
V_2 -> V_31 = false ;
if ( F_23 ( V_69 ) )
F_26 ( V_69 ) ;
F_19 ( V_69 ) ;
}
void F_52 ( struct V_1 * V_71 , struct V_1 * V_72 )
{
F_22 ( ! V_71 -> V_31 ) ;
* V_72 = * V_71 ;
F_53 ( & V_71 -> V_61 , & V_72 -> V_61 ) ;
F_54 ( & V_71 -> V_27 , & V_72 -> V_27 , & V_71 -> V_14 -> V_22 . V_33 ) ;
if ( F_23 ( V_71 ) ) {
F_53 ( & V_71 -> V_43 , & V_72 -> V_43 ) ;
F_54 ( & V_71 -> V_38 ,
& V_72 -> V_38 ,
& V_71 -> V_14 -> V_37 ) ;
F_54 ( & V_71 -> V_41 ,
& V_72 -> V_41 ,
& V_71 -> V_14 -> V_40 ) ;
}
V_71 -> V_31 = false ;
V_72 -> V_31 = true ;
}
void F_55 ( struct V_73 * V_74 ,
struct V_13 * V_14 ,
T_2 V_19 ,
T_2 V_62 ,
unsigned long V_60 ,
T_2 V_18 ,
T_2 V_47 ,
enum V_48 V_49 )
{
F_22 ( V_18 >= V_47 ) ;
F_22 ( ! V_19 || V_19 > V_47 - V_18 ) ;
F_22 ( V_14 -> V_75 ) ;
V_74 -> V_14 = V_14 ;
if ( V_62 <= 1 )
V_62 = 0 ;
V_74 -> V_60 = V_60 ;
V_74 -> V_62 = V_62 ;
V_74 -> V_65 = F_44 ( V_62 ) ? V_62 - 1 : 0 ;
V_74 -> V_19 = V_19 ;
V_74 -> V_49 = V_49 ;
F_22 ( V_47 <= V_18 ) ;
V_74 -> V_63 = V_18 ;
V_74 -> V_64 = V_47 ;
V_74 -> V_76 = V_77 ;
V_74 -> V_78 = 0 ;
}
bool F_56 ( struct V_73 * V_74 ,
struct V_1 * V_2 )
{
struct V_13 * V_14 = V_74 -> V_14 ;
struct V_1 * V_54 ;
T_2 V_46 , V_55 ;
T_2 V_66 , V_67 ;
T_2 V_56 , V_57 ;
F_22 ( V_2 -> V_14 != V_14 ) ;
F_22 ( ! V_2 -> V_31 ) ;
F_22 ( V_2 -> V_70 ) ;
V_2 -> V_70 = true ;
V_14 -> V_75 ++ ;
V_54 = F_50 ( V_2 , V_61 ) ;
F_22 ( F_40 ( V_54 , V_61 ) != V_2 ) ;
F_57 ( & V_2 -> V_61 ) ;
V_46 = F_21 ( V_54 ) ;
V_55 = F_20 ( V_54 ) ;
V_66 = V_46 ;
V_67 = V_55 ;
if ( V_14 -> V_59 )
V_14 -> V_59 ( V_54 , V_74 -> V_60 , & V_66 , & V_67 ) ;
V_56 = F_45 ( V_66 , V_74 -> V_63 ) ;
V_57 = F_46 ( V_67 , V_74 -> V_64 ) ;
if ( V_57 <= V_56 || V_57 - V_56 < V_74 -> V_19 )
return false ;
if ( V_74 -> V_49 == V_52 )
V_56 = V_57 - V_74 -> V_19 ;
if ( V_74 -> V_62 ) {
T_2 V_68 ;
if ( F_47 ( V_74 -> V_65 ) )
V_68 = V_56 & V_74 -> V_65 ;
else
F_48 ( V_56 , V_74 -> V_62 , & V_68 ) ;
if ( V_68 ) {
V_56 -= V_68 ;
if ( V_74 -> V_49 != V_52 )
V_56 += V_74 -> V_62 ;
if ( V_56 < F_45 ( V_66 , V_74 -> V_63 ) ||
F_46 ( V_67 , V_74 -> V_64 ) - V_56 < V_74 -> V_19 )
return false ;
if ( V_57 <= V_56 ||
V_57 - V_56 < V_74 -> V_19 )
return false ;
}
}
V_74 -> V_76 = V_56 ;
V_74 -> V_78 = V_56 + V_74 -> V_19 ;
F_22 ( V_74 -> V_76 >= V_74 -> V_78 ) ;
F_22 ( V_74 -> V_76 < V_46 ) ;
F_22 ( V_74 -> V_78 > V_55 ) ;
return true ;
}
bool F_58 ( struct V_73 * V_74 ,
struct V_1 * V_2 )
{
struct V_1 * V_69 ;
F_22 ( V_2 -> V_14 != V_74 -> V_14 ) ;
F_22 ( ! V_2 -> V_70 ) ;
V_2 -> V_70 = false ;
F_22 ( ! V_2 -> V_14 -> V_75 ) ;
V_2 -> V_14 -> V_75 -- ;
V_69 = F_50 ( V_2 , V_61 ) ;
F_22 ( F_40 ( V_69 , V_61 ) !=
F_40 ( V_2 , V_61 ) ) ;
F_25 ( & V_2 -> V_61 , & V_69 -> V_61 ) ;
return ( V_2 -> V_18 + V_2 -> V_19 > V_74 -> V_76 &&
V_2 -> V_18 < V_74 -> V_78 ) ;
}
struct V_1 * F_59 ( struct V_73 * V_74 )
{
struct V_13 * V_14 = V_74 -> V_14 ;
struct V_1 * V_54 ;
T_2 V_46 , V_55 ;
F_22 ( F_60 ( & V_14 -> V_43 ) ) ;
if ( ! V_14 -> V_59 )
return NULL ;
V_54 = F_61 ( & V_14 -> V_43 , F_62 ( * V_54 ) , V_43 ) ;
V_46 = F_21 ( V_54 ) ;
V_55 = V_46 + V_54 -> V_36 ;
F_22 ( V_46 > V_74 -> V_76 ) ;
F_22 ( V_55 < V_74 -> V_78 ) ;
V_14 -> V_59 ( V_54 , V_74 -> V_60 , & V_46 , & V_55 ) ;
if ( V_46 > V_74 -> V_76 )
return V_54 ;
if ( V_55 < V_74 -> V_78 )
return F_40 ( V_54 , V_61 ) ;
return NULL ;
}
void F_63 ( struct V_13 * V_14 , T_2 V_18 , T_2 V_19 )
{
F_22 ( V_18 + V_19 <= V_18 ) ;
V_14 -> V_59 = NULL ;
F_64 ( & V_14 -> V_43 ) ;
V_14 -> V_22 = V_79 ;
V_14 -> V_37 = V_80 ;
V_14 -> V_40 = V_80 ;
F_64 ( & V_14 -> V_23 . V_61 ) ;
V_14 -> V_23 . V_31 = false ;
V_14 -> V_23 . V_14 = V_14 ;
V_14 -> V_23 . V_18 = V_18 + V_19 ;
V_14 -> V_23 . V_19 = - V_19 ;
F_19 ( & V_14 -> V_23 ) ;
V_14 -> V_75 = 0 ;
}
void F_65 ( struct V_13 * V_14 )
{
if ( F_66 ( ! F_67 ( V_14 ) ,
L_3 ) )
F_4 ( V_14 ) ;
}
static T_2 F_68 ( struct V_81 * V_82 , const struct V_1 * V_83 )
{
T_2 V_18 , V_19 ;
V_19 = V_83 -> V_36 ;
if ( V_19 ) {
V_18 = F_69 ( V_83 ) ;
F_70 ( V_82 , L_4 ,
V_18 , V_18 + V_19 , V_19 ) ;
}
return V_19 ;
}
void F_71 ( const struct V_13 * V_14 , struct V_81 * V_82 )
{
const struct V_1 * V_83 ;
T_2 V_84 = 0 , V_85 = 0 , V_86 = 0 ;
V_85 += F_68 ( V_82 , & V_14 -> V_23 ) ;
F_72 (entry, mm) {
F_70 ( V_82 , L_5 , V_83 -> V_18 ,
V_83 -> V_18 + V_83 -> V_19 , V_83 -> V_19 ) ;
V_84 += V_83 -> V_19 ;
V_85 += F_68 ( V_82 , V_83 ) ;
}
V_86 = V_85 + V_84 ;
F_70 ( V_82 , L_6 , V_86 ,
V_84 , V_85 ) ;
}
