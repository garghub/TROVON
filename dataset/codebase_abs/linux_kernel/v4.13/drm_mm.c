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
V_2 -> V_29 = F_14 ( V_2 ) ;
if ( V_24 -> V_30 ) {
V_27 = & V_24 -> V_27 ;
while ( V_27 ) {
V_28 = F_15 ( V_27 , struct V_1 , V_27 ) ;
if ( V_28 -> V_29 >= V_2 -> V_29 )
break;
V_28 -> V_29 = V_2 -> V_29 ;
V_27 = F_16 ( V_27 ) ;
}
V_27 = & V_24 -> V_27 ;
V_26 = & V_24 -> V_27 . V_31 ;
} else {
V_27 = NULL ;
V_26 = & V_14 -> V_22 . V_25 ;
}
while ( * V_26 ) {
V_27 = * V_26 ;
V_28 = F_15 ( V_27 , struct V_1 , V_27 ) ;
if ( V_28 -> V_29 < V_2 -> V_29 )
V_28 -> V_29 = V_2 -> V_29 ;
if ( V_2 -> V_18 < V_28 -> V_18 )
V_26 = & V_28 -> V_27 . V_32 ;
else
V_26 = & V_28 -> V_27 . V_31 ;
}
F_17 ( & V_2 -> V_27 , V_27 , V_26 ) ;
F_18 ( & V_2 -> V_27 ,
& V_14 -> V_22 ,
& V_33 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_2 -> V_34 =
F_20 ( V_2 ) - F_21 ( V_2 ) ;
F_22 ( ! F_23 ( V_2 ) ) ;
F_24 ( V_14 -> V_35 , V_36 , V_37 ) ;
F_24 ( V_14 -> V_38 , V_39 , V_40 ) ;
F_25 ( & V_2 -> V_41 , & V_14 -> V_41 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_22 ( ! F_23 ( V_2 ) ) ;
F_27 ( & V_2 -> V_41 ) ;
F_28 ( & V_2 -> V_36 , & V_2 -> V_14 -> V_35 ) ;
F_28 ( & V_2 -> V_39 , & V_2 -> V_14 -> V_38 ) ;
V_2 -> V_34 = 0 ;
F_22 ( F_23 ( V_2 ) ) ;
}
static inline struct V_1 * F_29 ( struct V_25 * V_27 )
{
return F_30 ( V_27 , struct V_1 , V_36 ) ;
}
static inline struct V_1 * F_31 ( struct V_25 * V_27 )
{
return F_30 ( V_27 , struct V_1 , V_39 ) ;
}
static inline T_2 V_36 ( struct V_25 * V_27 )
{
return F_15 ( V_27 , struct V_1 , V_36 ) -> V_34 ;
}
static struct V_1 * F_32 ( struct V_13 * V_14 , T_2 V_19 )
{
struct V_25 * V_42 = NULL ;
struct V_25 * * V_26 = & V_14 -> V_35 . V_25 ;
while ( * V_26 ) {
struct V_25 * V_27 = * V_26 ;
if ( V_19 <= V_36 ( V_27 ) ) {
V_26 = & V_27 -> V_32 ;
V_42 = V_27 ;
} else {
V_26 = & V_27 -> V_31 ;
}
}
return F_29 ( V_42 ) ;
}
static struct V_1 * F_33 ( struct V_13 * V_14 , T_2 V_43 )
{
struct V_1 * V_2 = NULL ;
struct V_25 * * V_26 = & V_14 -> V_38 . V_25 ;
while ( * V_26 ) {
T_2 V_44 ;
V_2 = F_31 ( * V_26 ) ;
V_44 = F_21 ( V_2 ) ;
if ( V_43 < V_44 )
V_26 = & V_2 -> V_39 . V_32 ;
else if ( V_43 > V_44 + V_2 -> V_34 )
V_26 = & V_2 -> V_39 . V_31 ;
else
break;
}
return V_2 ;
}
static struct V_1 *
F_34 ( struct V_13 * V_14 ,
T_2 V_18 , T_2 V_45 , T_2 V_19 ,
enum V_46 V_47 )
{
if ( F_35 ( & V_14 -> V_35 ) )
return NULL ;
switch ( V_47 ) {
default:
case V_48 :
return F_32 ( V_14 , V_19 ) ;
case V_49 :
return F_33 ( V_14 , V_18 ) ;
case V_50 :
return F_33 ( V_14 , V_45 ) ;
case V_51 :
return F_36 ( & V_14 -> V_41 ,
struct V_1 ,
V_41 ) ;
}
}
static struct V_1 *
F_37 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
enum V_46 V_47 )
{
switch ( V_47 ) {
default:
case V_48 :
return F_29 ( F_38 ( & V_2 -> V_36 ) ) ;
case V_49 :
return F_31 ( F_38 ( & V_2 -> V_39 ) ) ;
case V_50 :
return F_31 ( F_39 ( & V_2 -> V_39 ) ) ;
case V_51 :
V_2 = F_40 ( V_2 , V_41 ) ;
return & V_2 -> V_41 == & V_14 -> V_41 ? NULL : V_2 ;
}
}
int F_41 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
T_2 V_45 = V_2 -> V_18 + V_2 -> V_19 ;
struct V_1 * V_52 ;
T_2 V_44 , V_53 ;
T_2 V_54 , V_55 ;
V_45 = V_2 -> V_18 + V_2 -> V_19 ;
if ( F_42 ( V_45 <= V_2 -> V_18 ) )
return - V_56 ;
V_52 = F_33 ( V_14 , V_2 -> V_18 ) ;
if ( ! V_52 )
return - V_56 ;
V_54 = V_44 = F_21 ( V_52 ) ;
V_55 = V_53 = V_44 + V_52 -> V_34 ;
if ( V_14 -> V_57 )
V_14 -> V_57 ( V_52 , V_2 -> V_58 , & V_54 , & V_55 ) ;
if ( V_54 > V_2 -> V_18 || V_55 < V_45 )
return - V_56 ;
V_2 -> V_14 = V_14 ;
F_25 ( & V_2 -> V_59 , & V_52 -> V_59 ) ;
F_13 ( V_52 , V_2 ) ;
V_2 -> V_30 = true ;
V_2 -> V_34 = 0 ;
F_26 ( V_52 ) ;
if ( V_2 -> V_18 > V_44 )
F_19 ( V_52 ) ;
if ( V_45 < V_53 )
F_19 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
int F_43 ( struct V_13 * const V_14 ,
struct V_1 * const V_2 ,
T_2 V_19 , T_2 V_60 ,
unsigned long V_58 ,
T_2 V_61 , T_2 V_62 ,
enum V_46 V_47 )
{
struct V_1 * V_52 ;
T_2 V_63 ;
F_22 ( V_61 >= V_62 ) ;
if ( F_42 ( V_19 == 0 || V_62 - V_61 < V_19 ) )
return - V_56 ;
if ( V_60 <= 1 )
V_60 = 0 ;
V_63 = F_44 ( V_60 ) ? V_60 - 1 : 0 ;
for ( V_52 = F_34 ( V_14 , V_61 , V_62 , V_19 , V_47 ) ; V_52 ;
V_52 = F_37 ( V_14 , V_52 , V_47 ) ) {
T_2 V_44 = F_21 ( V_52 ) ;
T_2 V_53 = V_44 + V_52 -> V_34 ;
T_2 V_54 , V_55 ;
T_2 V_64 , V_65 ;
if ( V_47 == V_49 && V_44 >= V_62 )
break;
if ( V_47 == V_50 && V_53 <= V_61 )
break;
V_64 = V_44 ;
V_65 = V_53 ;
if ( V_14 -> V_57 )
V_14 -> V_57 ( V_52 , V_58 , & V_64 , & V_65 ) ;
V_54 = F_45 ( V_64 , V_61 ) ;
V_55 = F_46 ( V_65 , V_62 ) ;
if ( V_55 <= V_54 || V_55 - V_54 < V_19 )
continue;
if ( V_47 == V_50 )
V_54 = V_55 - V_19 ;
if ( V_60 ) {
T_2 V_66 ;
if ( F_47 ( V_63 ) )
V_66 = V_54 & V_63 ;
else
F_48 ( V_54 , V_60 , & V_66 ) ;
if ( V_66 ) {
V_54 -= V_66 ;
if ( V_47 != V_50 )
V_54 += V_60 ;
if ( V_54 < F_45 ( V_64 , V_61 ) ||
F_46 ( V_65 , V_62 ) - V_54 < V_19 )
continue;
if ( V_55 <= V_54 ||
V_55 - V_54 < V_19 )
continue;
}
}
V_2 -> V_14 = V_14 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_18 = V_54 ;
V_2 -> V_58 = V_58 ;
V_2 -> V_34 = 0 ;
F_25 ( & V_2 -> V_59 , & V_52 -> V_59 ) ;
F_13 ( V_52 , V_2 ) ;
V_2 -> V_30 = true ;
F_26 ( V_52 ) ;
if ( V_54 > V_44 )
F_19 ( V_52 ) ;
if ( V_54 + V_19 < V_53 )
F_19 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
return - V_56 ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_1 * V_67 ;
F_22 ( ! V_2 -> V_30 ) ;
F_22 ( V_2 -> V_68 ) ;
V_67 = F_50 ( V_2 , V_59 ) ;
if ( F_23 ( V_2 ) )
F_26 ( V_2 ) ;
F_51 ( V_2 , & V_14 -> V_22 ) ;
F_27 ( & V_2 -> V_59 ) ;
V_2 -> V_30 = false ;
if ( F_23 ( V_67 ) )
F_26 ( V_67 ) ;
F_19 ( V_67 ) ;
}
void F_52 ( struct V_1 * V_69 , struct V_1 * V_70 )
{
F_22 ( ! V_69 -> V_30 ) ;
* V_70 = * V_69 ;
F_53 ( & V_69 -> V_59 , & V_70 -> V_59 ) ;
F_54 ( & V_69 -> V_27 , & V_70 -> V_27 , & V_69 -> V_14 -> V_22 ) ;
if ( F_23 ( V_69 ) ) {
F_53 ( & V_69 -> V_41 , & V_70 -> V_41 ) ;
F_54 ( & V_69 -> V_36 ,
& V_70 -> V_36 ,
& V_69 -> V_14 -> V_35 ) ;
F_54 ( & V_69 -> V_39 ,
& V_70 -> V_39 ,
& V_69 -> V_14 -> V_38 ) ;
}
V_69 -> V_30 = false ;
V_70 -> V_30 = true ;
}
void F_55 ( struct V_71 * V_72 ,
struct V_13 * V_14 ,
T_2 V_19 ,
T_2 V_60 ,
unsigned long V_58 ,
T_2 V_18 ,
T_2 V_45 ,
enum V_46 V_47 )
{
F_22 ( V_18 >= V_45 ) ;
F_22 ( ! V_19 || V_19 > V_45 - V_18 ) ;
F_22 ( V_14 -> V_73 ) ;
V_72 -> V_14 = V_14 ;
if ( V_60 <= 1 )
V_60 = 0 ;
V_72 -> V_58 = V_58 ;
V_72 -> V_60 = V_60 ;
V_72 -> V_63 = F_44 ( V_60 ) ? V_60 - 1 : 0 ;
V_72 -> V_19 = V_19 ;
V_72 -> V_47 = V_47 ;
F_22 ( V_45 <= V_18 ) ;
V_72 -> V_61 = V_18 ;
V_72 -> V_62 = V_45 ;
V_72 -> V_74 = V_75 ;
V_72 -> V_76 = 0 ;
}
bool F_56 ( struct V_71 * V_72 ,
struct V_1 * V_2 )
{
struct V_13 * V_14 = V_72 -> V_14 ;
struct V_1 * V_52 ;
T_2 V_44 , V_53 ;
T_2 V_64 , V_65 ;
T_2 V_54 , V_55 ;
F_22 ( V_2 -> V_14 != V_14 ) ;
F_22 ( ! V_2 -> V_30 ) ;
F_22 ( V_2 -> V_68 ) ;
V_2 -> V_68 = true ;
V_14 -> V_73 ++ ;
V_52 = F_50 ( V_2 , V_59 ) ;
F_22 ( F_40 ( V_52 , V_59 ) != V_2 ) ;
F_57 ( & V_2 -> V_59 ) ;
V_44 = F_21 ( V_52 ) ;
V_53 = F_20 ( V_52 ) ;
V_64 = V_44 ;
V_65 = V_53 ;
if ( V_14 -> V_57 )
V_14 -> V_57 ( V_52 , V_72 -> V_58 , & V_64 , & V_65 ) ;
V_54 = F_45 ( V_64 , V_72 -> V_61 ) ;
V_55 = F_46 ( V_65 , V_72 -> V_62 ) ;
if ( V_55 <= V_54 || V_55 - V_54 < V_72 -> V_19 )
return false ;
if ( V_72 -> V_47 == V_50 )
V_54 = V_55 - V_72 -> V_19 ;
if ( V_72 -> V_60 ) {
T_2 V_66 ;
if ( F_47 ( V_72 -> V_63 ) )
V_66 = V_54 & V_72 -> V_63 ;
else
F_48 ( V_54 , V_72 -> V_60 , & V_66 ) ;
if ( V_66 ) {
V_54 -= V_66 ;
if ( V_72 -> V_47 != V_50 )
V_54 += V_72 -> V_60 ;
if ( V_54 < F_45 ( V_64 , V_72 -> V_61 ) ||
F_46 ( V_65 , V_72 -> V_62 ) - V_54 < V_72 -> V_19 )
return false ;
if ( V_55 <= V_54 ||
V_55 - V_54 < V_72 -> V_19 )
return false ;
}
}
V_72 -> V_74 = V_54 ;
V_72 -> V_76 = V_54 + V_72 -> V_19 ;
F_22 ( V_72 -> V_74 >= V_72 -> V_76 ) ;
F_22 ( V_72 -> V_74 < V_44 ) ;
F_22 ( V_72 -> V_76 > V_53 ) ;
return true ;
}
bool F_58 ( struct V_71 * V_72 ,
struct V_1 * V_2 )
{
struct V_1 * V_67 ;
F_22 ( V_2 -> V_14 != V_72 -> V_14 ) ;
F_22 ( ! V_2 -> V_68 ) ;
V_2 -> V_68 = false ;
F_22 ( ! V_2 -> V_14 -> V_73 ) ;
V_2 -> V_14 -> V_73 -- ;
V_67 = F_50 ( V_2 , V_59 ) ;
F_22 ( F_40 ( V_67 , V_59 ) !=
F_40 ( V_2 , V_59 ) ) ;
F_25 ( & V_2 -> V_59 , & V_67 -> V_59 ) ;
return ( V_2 -> V_18 + V_2 -> V_19 > V_72 -> V_74 &&
V_2 -> V_18 < V_72 -> V_76 ) ;
}
struct V_1 * F_59 ( struct V_71 * V_72 )
{
struct V_13 * V_14 = V_72 -> V_14 ;
struct V_1 * V_52 ;
T_2 V_44 , V_53 ;
F_22 ( F_60 ( & V_14 -> V_41 ) ) ;
if ( ! V_14 -> V_57 )
return NULL ;
V_52 = F_61 ( & V_14 -> V_41 , F_62 ( * V_52 ) , V_41 ) ;
V_44 = F_21 ( V_52 ) ;
V_53 = V_44 + V_52 -> V_34 ;
F_22 ( V_44 > V_72 -> V_74 ) ;
F_22 ( V_53 < V_72 -> V_76 ) ;
V_14 -> V_57 ( V_52 , V_72 -> V_58 , & V_44 , & V_53 ) ;
if ( V_44 > V_72 -> V_74 )
return V_52 ;
if ( V_53 < V_72 -> V_76 )
return F_40 ( V_52 , V_59 ) ;
return NULL ;
}
void F_63 ( struct V_13 * V_14 , T_2 V_18 , T_2 V_19 )
{
F_22 ( V_18 + V_19 <= V_18 ) ;
V_14 -> V_57 = NULL ;
F_64 ( & V_14 -> V_41 ) ;
V_14 -> V_22 = V_77 ;
V_14 -> V_35 = V_77 ;
V_14 -> V_38 = V_77 ;
F_64 ( & V_14 -> V_23 . V_59 ) ;
V_14 -> V_23 . V_30 = false ;
V_14 -> V_23 . V_14 = V_14 ;
V_14 -> V_23 . V_18 = V_18 + V_19 ;
V_14 -> V_23 . V_19 = - V_19 ;
F_19 ( & V_14 -> V_23 ) ;
V_14 -> V_73 = 0 ;
}
void F_65 ( struct V_13 * V_14 )
{
if ( F_66 ( ! F_67 ( V_14 ) ,
L_3 ) )
F_4 ( V_14 ) ;
}
static T_2 F_68 ( struct V_78 * V_79 , const struct V_1 * V_80 )
{
T_2 V_18 , V_19 ;
V_19 = V_80 -> V_34 ;
if ( V_19 ) {
V_18 = F_69 ( V_80 ) ;
F_70 ( V_79 , L_4 ,
V_18 , V_18 + V_19 , V_19 ) ;
}
return V_19 ;
}
void F_71 ( const struct V_13 * V_14 , struct V_78 * V_79 )
{
const struct V_1 * V_80 ;
T_2 V_81 = 0 , V_82 = 0 , V_83 = 0 ;
V_82 += F_68 ( V_79 , & V_14 -> V_23 ) ;
F_72 (entry, mm) {
F_70 ( V_79 , L_5 , V_80 -> V_18 ,
V_80 -> V_18 + V_80 -> V_19 , V_80 -> V_19 ) ;
V_81 += V_80 -> V_19 ;
V_82 += F_68 ( V_79 , V_80 ) ;
}
V_83 = V_82 + V_81 ;
F_70 ( V_79 , L_6 , V_83 ,
V_81 , V_82 ) ;
}
