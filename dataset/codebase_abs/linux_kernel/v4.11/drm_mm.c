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
V_18 , V_20 ) ;
}
static void F_13 ( struct V_1 * V_23 ,
struct V_1 * V_2 )
{
struct V_13 * V_14 = V_23 -> V_14 ;
struct V_24 * * V_25 , * V_26 ;
struct V_1 * V_27 ;
V_2 -> V_28 = F_14 ( V_2 ) ;
if ( V_23 -> V_29 ) {
V_26 = & V_23 -> V_26 ;
while ( V_26 ) {
V_27 = F_15 ( V_26 , struct V_1 , V_26 ) ;
if ( V_27 -> V_28 >= V_2 -> V_28 )
break;
V_27 -> V_28 = V_2 -> V_28 ;
V_26 = F_16 ( V_26 ) ;
}
V_26 = & V_23 -> V_26 ;
V_25 = & V_23 -> V_26 . V_30 ;
} else {
V_26 = NULL ;
V_25 = & V_14 -> V_22 . V_24 ;
}
while ( * V_25 ) {
V_26 = * V_25 ;
V_27 = F_15 ( V_26 , struct V_1 , V_26 ) ;
if ( V_27 -> V_28 < V_2 -> V_28 )
V_27 -> V_28 = V_2 -> V_28 ;
if ( V_2 -> V_18 < V_27 -> V_18 )
V_25 = & V_27 -> V_26 . V_31 ;
else
V_25 = & V_27 -> V_26 . V_30 ;
}
F_17 ( & V_2 -> V_26 , V_26 , V_25 ) ;
F_18 ( & V_2 -> V_26 ,
& V_14 -> V_22 ,
& V_32 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_2 -> V_33 =
F_20 ( V_2 ) - F_21 ( V_2 ) ;
F_22 ( ! F_23 ( V_2 ) ) ;
F_24 ( V_14 -> V_34 , V_35 , V_36 ) ;
F_24 ( V_14 -> V_37 , V_38 , V_39 ) ;
F_25 ( & V_2 -> V_40 , & V_14 -> V_40 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_22 ( ! F_23 ( V_2 ) ) ;
F_27 ( & V_2 -> V_40 ) ;
F_28 ( & V_2 -> V_35 , & V_2 -> V_14 -> V_34 ) ;
F_28 ( & V_2 -> V_38 , & V_2 -> V_14 -> V_37 ) ;
V_2 -> V_33 = 0 ;
F_22 ( F_23 ( V_2 ) ) ;
}
static inline struct V_1 * F_29 ( struct V_24 * V_26 )
{
return F_30 ( V_26 , struct V_1 , V_35 ) ;
}
static inline struct V_1 * F_31 ( struct V_24 * V_26 )
{
return F_30 ( V_26 , struct V_1 , V_38 ) ;
}
static inline T_2 V_35 ( struct V_24 * V_26 )
{
return F_15 ( V_26 , struct V_1 , V_35 ) -> V_33 ;
}
static struct V_1 * F_32 ( struct V_13 * V_14 , T_2 V_19 )
{
struct V_24 * V_41 = NULL ;
struct V_24 * * V_25 = & V_14 -> V_34 . V_24 ;
while ( * V_25 ) {
struct V_24 * V_26 = * V_25 ;
if ( V_19 <= V_35 ( V_26 ) ) {
V_25 = & V_26 -> V_31 ;
V_41 = V_26 ;
} else {
V_25 = & V_26 -> V_30 ;
}
}
return F_29 ( V_41 ) ;
}
static struct V_1 * F_33 ( struct V_13 * V_14 , T_2 V_42 )
{
struct V_1 * V_2 = NULL ;
struct V_24 * * V_25 = & V_14 -> V_37 . V_24 ;
while ( * V_25 ) {
T_2 V_43 ;
V_2 = F_31 ( * V_25 ) ;
V_43 = F_21 ( V_2 ) ;
if ( V_42 < V_43 )
V_25 = & V_2 -> V_38 . V_31 ;
else if ( V_42 > V_43 + V_2 -> V_33 )
V_25 = & V_2 -> V_38 . V_30 ;
else
break;
}
return V_2 ;
}
static struct V_1 *
F_34 ( struct V_13 * V_14 ,
T_2 V_18 , T_2 V_44 , T_2 V_19 ,
enum V_45 V_46 )
{
if ( F_35 ( & V_14 -> V_34 ) )
return NULL ;
switch ( V_46 ) {
default:
case V_47 :
return F_32 ( V_14 , V_19 ) ;
case V_48 :
return F_33 ( V_14 , V_18 ) ;
case V_49 :
return F_33 ( V_14 , V_44 ) ;
case V_50 :
return F_36 ( & V_14 -> V_40 ,
struct V_1 ,
V_40 ) ;
}
}
static struct V_1 *
F_37 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
enum V_45 V_46 )
{
switch ( V_46 ) {
default:
case V_47 :
return F_29 ( F_38 ( & V_2 -> V_35 ) ) ;
case V_48 :
return F_31 ( F_38 ( & V_2 -> V_38 ) ) ;
case V_49 :
return F_31 ( F_39 ( & V_2 -> V_38 ) ) ;
case V_50 :
V_2 = F_40 ( V_2 , V_40 ) ;
return & V_2 -> V_40 == & V_14 -> V_40 ? NULL : V_2 ;
}
}
int F_41 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
T_2 V_44 = V_2 -> V_18 + V_2 -> V_19 ;
struct V_1 * V_51 ;
T_2 V_43 , V_52 ;
T_2 V_53 , V_54 ;
V_44 = V_2 -> V_18 + V_2 -> V_19 ;
if ( F_42 ( V_44 <= V_2 -> V_18 ) )
return - V_55 ;
V_51 = F_33 ( V_14 , V_2 -> V_18 ) ;
if ( ! V_51 )
return - V_55 ;
V_53 = V_43 = F_21 ( V_51 ) ;
V_54 = V_52 = V_43 + V_51 -> V_33 ;
if ( V_14 -> V_56 )
V_14 -> V_56 ( V_51 , V_2 -> V_57 , & V_53 , & V_54 ) ;
if ( V_53 > V_2 -> V_18 || V_54 < V_44 )
return - V_55 ;
V_2 -> V_14 = V_14 ;
F_25 ( & V_2 -> V_58 , & V_51 -> V_58 ) ;
F_13 ( V_51 , V_2 ) ;
V_2 -> V_29 = true ;
V_2 -> V_33 = 0 ;
F_26 ( V_51 ) ;
if ( V_2 -> V_18 > V_43 )
F_19 ( V_51 ) ;
if ( V_44 < V_52 )
F_19 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
int F_43 ( struct V_13 * const V_14 ,
struct V_1 * const V_2 ,
T_2 V_19 , T_2 V_59 ,
unsigned long V_57 ,
T_2 V_60 , T_2 V_61 ,
enum V_45 V_46 )
{
struct V_1 * V_51 ;
T_2 V_62 ;
F_22 ( V_60 >= V_61 ) ;
if ( F_42 ( V_19 == 0 || V_61 - V_60 < V_19 ) )
return - V_55 ;
if ( V_59 <= 1 )
V_59 = 0 ;
V_62 = F_44 ( V_59 ) ? V_59 - 1 : 0 ;
for ( V_51 = F_34 ( V_14 , V_60 , V_61 , V_19 , V_46 ) ; V_51 ;
V_51 = F_37 ( V_14 , V_51 , V_46 ) ) {
T_2 V_43 = F_21 ( V_51 ) ;
T_2 V_52 = V_43 + V_51 -> V_33 ;
T_2 V_53 , V_54 ;
T_2 V_63 , V_64 ;
if ( V_46 == V_48 && V_43 >= V_61 )
break;
if ( V_46 == V_49 && V_52 <= V_60 )
break;
V_63 = V_43 ;
V_64 = V_52 ;
if ( V_14 -> V_56 )
V_14 -> V_56 ( V_51 , V_57 , & V_63 , & V_64 ) ;
V_53 = F_45 ( V_63 , V_60 ) ;
V_54 = F_46 ( V_64 , V_61 ) ;
if ( V_54 <= V_53 || V_54 - V_53 < V_19 )
continue;
if ( V_46 == V_49 )
V_53 = V_54 - V_19 ;
if ( V_59 ) {
T_2 V_65 ;
if ( F_47 ( V_62 ) )
V_65 = V_53 & V_62 ;
else
F_48 ( V_53 , V_59 , & V_65 ) ;
if ( V_65 ) {
V_53 -= V_65 ;
if ( V_46 != V_49 )
V_53 += V_59 ;
if ( V_53 < F_45 ( V_63 , V_60 ) ||
F_46 ( V_64 , V_61 ) - V_53 < V_19 )
continue;
if ( V_54 <= V_53 ||
V_54 - V_53 < V_19 )
continue;
}
}
V_2 -> V_14 = V_14 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_18 = V_53 ;
V_2 -> V_57 = V_57 ;
V_2 -> V_33 = 0 ;
F_25 ( & V_2 -> V_58 , & V_51 -> V_58 ) ;
F_13 ( V_51 , V_2 ) ;
V_2 -> V_29 = true ;
F_26 ( V_51 ) ;
if ( V_53 > V_43 )
F_19 ( V_51 ) ;
if ( V_53 + V_19 < V_52 )
F_19 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
return - V_55 ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_1 * V_66 ;
F_22 ( ! V_2 -> V_29 ) ;
F_22 ( V_2 -> V_67 ) ;
V_66 = F_50 ( V_2 , V_58 ) ;
if ( F_23 ( V_2 ) )
F_26 ( V_2 ) ;
F_51 ( V_2 , & V_14 -> V_22 ) ;
F_27 ( & V_2 -> V_58 ) ;
V_2 -> V_29 = false ;
if ( F_23 ( V_66 ) )
F_26 ( V_66 ) ;
F_19 ( V_66 ) ;
}
void F_52 ( struct V_1 * V_68 , struct V_1 * V_69 )
{
F_22 ( ! V_68 -> V_29 ) ;
* V_69 = * V_68 ;
F_53 ( & V_68 -> V_58 , & V_69 -> V_58 ) ;
F_54 ( & V_68 -> V_26 , & V_69 -> V_26 , & V_68 -> V_14 -> V_22 ) ;
if ( F_23 ( V_68 ) ) {
F_53 ( & V_68 -> V_40 , & V_69 -> V_40 ) ;
F_54 ( & V_68 -> V_35 ,
& V_69 -> V_35 ,
& V_68 -> V_14 -> V_34 ) ;
F_54 ( & V_68 -> V_38 ,
& V_69 -> V_38 ,
& V_68 -> V_14 -> V_37 ) ;
}
V_68 -> V_29 = false ;
V_69 -> V_29 = true ;
}
void F_55 ( struct V_70 * V_71 ,
struct V_13 * V_14 ,
T_2 V_19 ,
T_2 V_59 ,
unsigned long V_57 ,
T_2 V_18 ,
T_2 V_44 ,
enum V_45 V_46 )
{
F_22 ( V_18 >= V_44 ) ;
F_22 ( ! V_19 || V_19 > V_44 - V_18 ) ;
F_22 ( V_14 -> V_72 ) ;
V_71 -> V_14 = V_14 ;
if ( V_59 <= 1 )
V_59 = 0 ;
V_71 -> V_57 = V_57 ;
V_71 -> V_59 = V_59 ;
V_71 -> V_62 = F_44 ( V_59 ) ? V_59 - 1 : 0 ;
V_71 -> V_19 = V_19 ;
V_71 -> V_46 = V_46 ;
F_22 ( V_44 <= V_18 ) ;
V_71 -> V_60 = V_18 ;
V_71 -> V_61 = V_44 ;
V_71 -> V_73 = V_74 ;
V_71 -> V_75 = 0 ;
}
bool F_56 ( struct V_70 * V_71 ,
struct V_1 * V_2 )
{
struct V_13 * V_14 = V_71 -> V_14 ;
struct V_1 * V_51 ;
T_2 V_43 , V_52 ;
T_2 V_63 , V_64 ;
T_2 V_53 , V_54 ;
F_22 ( V_2 -> V_14 != V_14 ) ;
F_22 ( ! V_2 -> V_29 ) ;
F_22 ( V_2 -> V_67 ) ;
V_2 -> V_67 = true ;
V_14 -> V_72 ++ ;
V_51 = F_50 ( V_2 , V_58 ) ;
F_22 ( F_40 ( V_51 , V_58 ) != V_2 ) ;
F_57 ( & V_2 -> V_58 ) ;
V_43 = F_21 ( V_51 ) ;
V_52 = F_20 ( V_51 ) ;
V_63 = V_43 ;
V_64 = V_52 ;
if ( V_14 -> V_56 )
V_14 -> V_56 ( V_51 , V_71 -> V_57 , & V_63 , & V_64 ) ;
V_53 = F_45 ( V_63 , V_71 -> V_60 ) ;
V_54 = F_46 ( V_64 , V_71 -> V_61 ) ;
if ( V_54 <= V_53 || V_54 - V_53 < V_71 -> V_19 )
return false ;
if ( V_71 -> V_46 == V_49 )
V_53 = V_54 - V_71 -> V_19 ;
if ( V_71 -> V_59 ) {
T_2 V_65 ;
if ( F_47 ( V_71 -> V_62 ) )
V_65 = V_53 & V_71 -> V_62 ;
else
F_48 ( V_53 , V_71 -> V_59 , & V_65 ) ;
if ( V_65 ) {
V_53 -= V_65 ;
if ( V_71 -> V_46 != V_49 )
V_53 += V_71 -> V_59 ;
if ( V_53 < F_45 ( V_63 , V_71 -> V_60 ) ||
F_46 ( V_64 , V_71 -> V_61 ) - V_53 < V_71 -> V_19 )
return false ;
if ( V_54 <= V_53 ||
V_54 - V_53 < V_71 -> V_19 )
return false ;
}
}
V_71 -> V_73 = V_53 ;
V_71 -> V_75 = V_53 + V_71 -> V_19 ;
F_22 ( V_71 -> V_73 >= V_71 -> V_75 ) ;
F_22 ( V_71 -> V_73 < V_43 ) ;
F_22 ( V_71 -> V_75 > V_52 ) ;
return true ;
}
bool F_58 ( struct V_70 * V_71 ,
struct V_1 * V_2 )
{
struct V_1 * V_66 ;
F_22 ( V_2 -> V_14 != V_71 -> V_14 ) ;
F_22 ( ! V_2 -> V_67 ) ;
V_2 -> V_67 = false ;
F_22 ( ! V_2 -> V_14 -> V_72 ) ;
V_2 -> V_14 -> V_72 -- ;
V_66 = F_50 ( V_2 , V_58 ) ;
F_22 ( F_40 ( V_66 , V_58 ) !=
F_40 ( V_2 , V_58 ) ) ;
F_25 ( & V_2 -> V_58 , & V_66 -> V_58 ) ;
return ( V_2 -> V_18 + V_2 -> V_19 > V_71 -> V_73 &&
V_2 -> V_18 < V_71 -> V_75 ) ;
}
struct V_1 * F_59 ( struct V_70 * V_71 )
{
struct V_13 * V_14 = V_71 -> V_14 ;
struct V_1 * V_51 ;
T_2 V_43 , V_52 ;
F_22 ( F_60 ( & V_14 -> V_40 ) ) ;
if ( ! V_14 -> V_56 )
return NULL ;
V_51 = F_61 ( & V_14 -> V_40 , F_62 ( * V_51 ) , V_40 ) ;
V_43 = F_21 ( V_51 ) ;
V_52 = V_43 + V_51 -> V_33 ;
F_22 ( V_43 > V_71 -> V_73 ) ;
F_22 ( V_52 < V_71 -> V_75 ) ;
V_14 -> V_56 ( V_51 , V_71 -> V_57 , & V_43 , & V_52 ) ;
if ( V_43 > V_71 -> V_73 )
return V_51 ;
if ( V_52 < V_71 -> V_75 )
return F_40 ( V_51 , V_58 ) ;
return NULL ;
}
void F_63 ( struct V_13 * V_14 , T_2 V_18 , T_2 V_19 )
{
F_22 ( V_18 + V_19 <= V_18 ) ;
V_14 -> V_56 = NULL ;
F_64 ( & V_14 -> V_40 ) ;
V_14 -> V_22 = V_76 ;
V_14 -> V_34 = V_76 ;
V_14 -> V_37 = V_76 ;
F_64 ( & V_14 -> V_77 . V_58 ) ;
V_14 -> V_77 . V_29 = false ;
V_14 -> V_77 . V_14 = V_14 ;
V_14 -> V_77 . V_18 = V_18 + V_19 ;
V_14 -> V_77 . V_19 = - V_19 ;
F_19 ( & V_14 -> V_77 ) ;
V_14 -> V_72 = 0 ;
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
V_19 = V_80 -> V_33 ;
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
V_82 += F_68 ( V_79 , & V_14 -> V_77 ) ;
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
