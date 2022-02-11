struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_5 )
{
return F_2 ( & V_3 -> V_6 ,
V_4 , V_5 ) ;
}
struct V_1 *
F_3 ( struct V_1 * V_7 , T_1 V_4 , T_1 V_5 )
{
return F_4 ( V_7 , V_4 , V_5 ) ;
}
static void F_5 ( struct V_1 * V_8 ,
struct V_1 * V_7 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_9 * * V_10 , * V_11 ;
struct V_1 * V_12 ;
V_7 -> V_13 = F_6 ( V_7 ) ;
if ( V_8 -> V_14 ) {
V_11 = & V_8 -> V_11 ;
while ( V_11 ) {
V_12 = F_7 ( V_11 , struct V_1 , V_11 ) ;
if ( V_12 -> V_13 >= V_7 -> V_13 )
break;
V_12 -> V_13 = V_7 -> V_13 ;
V_11 = F_8 ( V_11 ) ;
}
V_11 = & V_8 -> V_11 ;
V_10 = & V_8 -> V_11 . V_15 ;
} else {
V_11 = NULL ;
V_10 = & V_3 -> V_6 . V_9 ;
}
while ( * V_10 ) {
V_11 = * V_10 ;
V_12 = F_7 ( V_11 , struct V_1 , V_11 ) ;
if ( V_12 -> V_13 < V_7 -> V_13 )
V_12 -> V_13 = V_7 -> V_13 ;
if ( V_7 -> V_4 < V_12 -> V_4 )
V_10 = & V_12 -> V_11 . V_16 ;
else
V_10 = & V_12 -> V_11 . V_15 ;
}
F_9 ( & V_7 -> V_11 , V_11 , V_10 ) ;
F_10 ( & V_7 -> V_11 ,
& V_3 -> V_6 ,
& V_17 ) ;
}
static void F_11 ( struct V_1 * V_8 ,
struct V_1 * V_7 ,
T_1 V_18 , unsigned V_19 ,
unsigned long V_20 ,
enum V_21 V_22 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
T_1 V_23 = F_12 ( V_8 ) ;
T_1 V_24 = F_13 ( V_8 ) ;
T_1 V_25 = V_23 ;
T_1 V_26 = V_24 ;
F_14 ( V_7 -> V_14 ) ;
if ( V_3 -> V_27 )
V_3 -> V_27 ( V_8 , V_20 , & V_25 , & V_26 ) ;
if ( V_22 & V_28 )
V_25 = V_26 - V_18 ;
if ( V_19 ) {
T_1 V_29 = V_25 ;
unsigned V_30 ;
V_30 = F_15 ( V_29 , V_19 ) ;
if ( V_30 ) {
if ( V_22 & V_28 )
V_25 -= V_30 ;
else
V_25 += V_19 - V_30 ;
}
}
F_14 ( V_25 < V_23 ) ;
F_14 ( V_26 > V_24 ) ;
if ( V_25 == V_23 ) {
V_8 -> V_31 = 0 ;
F_16 ( & V_8 -> V_32 ) ;
}
V_7 -> V_4 = V_25 ;
V_7 -> V_18 = V_18 ;
V_7 -> V_3 = V_3 ;
V_7 -> V_20 = V_20 ;
V_7 -> V_14 = 1 ;
F_17 ( & V_7 -> V_33 , & V_8 -> V_33 ) ;
F_5 ( V_8 , V_7 ) ;
F_14 ( V_7 -> V_4 + V_7 -> V_18 > V_26 ) ;
V_7 -> V_31 = 0 ;
if ( F_18 ( V_7 ) < V_24 ) {
F_17 ( & V_7 -> V_32 , & V_3 -> V_32 ) ;
V_7 -> V_31 = 1 ;
}
}
int F_19 ( struct V_2 * V_3 , struct V_1 * V_7 )
{
T_1 V_34 = V_7 -> V_4 + V_7 -> V_18 ;
struct V_1 * V_35 ;
T_1 V_23 , V_24 ;
if ( F_20 ( V_7 -> V_18 == 0 ) )
return - V_36 ;
V_34 = V_7 -> V_4 + V_7 -> V_18 ;
V_35 = F_2 ( & V_3 -> V_6 ,
V_7 -> V_4 , ~ ( T_1 ) 0 ) ;
if ( V_35 ) {
if ( V_35 -> V_4 < V_34 )
return - V_37 ;
} else {
V_35 = F_21 ( & V_3 -> V_38 . V_33 ,
F_22 ( * V_35 ) , V_33 ) ;
}
V_35 = F_23 ( & V_35 -> V_33 , F_22 ( * V_35 ) , V_33 ) ;
if ( ! V_35 -> V_31 )
return - V_37 ;
V_23 = F_18 ( V_35 ) ;
V_24 = F_24 ( V_35 ) ;
if ( V_23 > V_7 -> V_4 || V_24 < V_34 )
return - V_37 ;
V_7 -> V_3 = V_3 ;
V_7 -> V_14 = 1 ;
F_17 ( & V_7 -> V_33 , & V_35 -> V_33 ) ;
F_5 ( V_35 , V_7 ) ;
if ( V_7 -> V_4 == V_23 ) {
V_35 -> V_31 = 0 ;
F_16 ( & V_35 -> V_32 ) ;
}
V_7 -> V_31 = 0 ;
if ( V_34 != V_24 ) {
F_17 ( & V_7 -> V_32 , & V_3 -> V_32 ) ;
V_7 -> V_31 = 1 ;
}
return 0 ;
}
int F_25 ( struct V_2 * V_3 , struct V_1 * V_7 ,
T_1 V_18 , unsigned V_19 ,
unsigned long V_20 ,
enum V_39 V_40 ,
enum V_21 V_41 )
{
struct V_1 * V_8 ;
if ( F_20 ( V_18 == 0 ) )
return - V_36 ;
V_8 = F_26 ( V_3 , V_18 , V_19 ,
V_20 , V_40 ) ;
if ( ! V_8 )
return - V_37 ;
F_11 ( V_8 , V_7 , V_18 , V_19 , V_20 , V_41 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_8 ,
struct V_1 * V_7 ,
T_1 V_18 , unsigned V_19 ,
unsigned long V_20 ,
T_1 V_4 , T_1 V_34 ,
enum V_21 V_22 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
T_1 V_23 = F_12 ( V_8 ) ;
T_1 V_24 = F_13 ( V_8 ) ;
T_1 V_25 = V_23 ;
T_1 V_26 = V_24 ;
F_14 ( ! V_8 -> V_31 || V_7 -> V_14 ) ;
if ( V_25 < V_4 )
V_25 = V_4 ;
if ( V_26 > V_34 )
V_26 = V_34 ;
if ( V_3 -> V_27 )
V_3 -> V_27 ( V_8 , V_20 , & V_25 , & V_26 ) ;
if ( V_22 & V_28 )
V_25 = V_26 - V_18 ;
if ( V_19 ) {
T_1 V_29 = V_25 ;
unsigned V_30 ;
V_30 = F_15 ( V_29 , V_19 ) ;
if ( V_30 ) {
if ( V_22 & V_28 )
V_25 -= V_30 ;
else
V_25 += V_19 - V_30 ;
}
}
if ( V_25 == V_23 ) {
V_8 -> V_31 = 0 ;
F_16 ( & V_8 -> V_32 ) ;
}
V_7 -> V_4 = V_25 ;
V_7 -> V_18 = V_18 ;
V_7 -> V_3 = V_3 ;
V_7 -> V_20 = V_20 ;
V_7 -> V_14 = 1 ;
F_17 ( & V_7 -> V_33 , & V_8 -> V_33 ) ;
F_5 ( V_8 , V_7 ) ;
F_14 ( V_7 -> V_4 < V_4 ) ;
F_14 ( V_7 -> V_4 < V_25 ) ;
F_14 ( V_7 -> V_4 + V_7 -> V_18 > V_26 ) ;
F_14 ( V_7 -> V_4 + V_7 -> V_18 > V_34 ) ;
V_7 -> V_31 = 0 ;
if ( F_18 ( V_7 ) < V_24 ) {
F_17 ( & V_7 -> V_32 , & V_3 -> V_32 ) ;
V_7 -> V_31 = 1 ;
}
}
int F_28 ( struct V_2 * V_3 , struct V_1 * V_7 ,
T_1 V_18 , unsigned V_19 ,
unsigned long V_20 ,
T_1 V_4 , T_1 V_34 ,
enum V_39 V_40 ,
enum V_21 V_41 )
{
struct V_1 * V_8 ;
if ( F_20 ( V_18 == 0 ) )
return - V_36 ;
V_8 = F_29 ( V_3 ,
V_18 , V_19 , V_20 ,
V_4 , V_34 , V_40 ) ;
if ( ! V_8 )
return - V_37 ;
F_27 ( V_8 , V_7 ,
V_18 , V_19 , V_20 ,
V_4 , V_34 , V_41 ) ;
return 0 ;
}
void F_30 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
struct V_1 * V_42 ;
if ( F_20 ( ! V_7 -> V_14 ) )
return;
F_14 ( V_7 -> V_43 || V_7 -> V_44
|| V_7 -> V_45 ) ;
V_42 =
F_21 ( V_7 -> V_33 . V_46 , struct V_1 , V_33 ) ;
if ( V_7 -> V_31 ) {
F_14 ( F_18 ( V_7 ) ==
F_24 ( V_7 ) ) ;
F_16 ( & V_7 -> V_32 ) ;
} else
F_14 ( F_18 ( V_7 ) !=
F_24 ( V_7 ) ) ;
if ( ! V_42 -> V_31 ) {
V_42 -> V_31 = 1 ;
F_17 ( & V_42 -> V_32 , & V_3 -> V_32 ) ;
} else
F_31 ( & V_42 -> V_32 , & V_3 -> V_32 ) ;
F_32 ( V_7 , & V_3 -> V_6 ) ;
F_16 ( & V_7 -> V_33 ) ;
V_7 -> V_14 = 0 ;
}
static int F_33 ( T_1 V_4 , T_1 V_34 , T_1 V_18 , unsigned V_19 )
{
if ( V_34 - V_4 < V_18 )
return 0 ;
if ( V_19 ) {
T_1 V_29 = V_4 ;
unsigned V_30 ;
V_30 = F_15 ( V_29 , V_19 ) ;
if ( V_30 )
V_4 += V_19 - V_30 ;
}
return V_34 >= V_4 + V_18 ;
}
static struct V_1 * F_26 ( const struct V_2 * V_3 ,
T_1 V_18 ,
unsigned V_19 ,
unsigned long V_20 ,
enum V_39 V_22 )
{
struct V_1 * V_47 ;
struct V_1 * V_48 ;
T_1 V_25 ;
T_1 V_26 ;
T_1 V_49 ;
F_14 ( V_3 -> V_50 ) ;
V_48 = NULL ;
V_49 = ~ 0UL ;
F_34 (entry, mm, adj_start, adj_end,
flags & DRM_MM_SEARCH_BELOW) {
T_1 V_51 = V_26 - V_25 ;
if ( V_3 -> V_27 ) {
V_3 -> V_27 ( V_47 , V_20 , & V_25 , & V_26 ) ;
if ( V_26 <= V_25 )
continue;
}
if ( ! F_33 ( V_25 , V_26 , V_18 , V_19 ) )
continue;
if ( ! ( V_22 & V_52 ) )
return V_47 ;
if ( V_51 < V_49 ) {
V_48 = V_47 ;
V_49 = V_51 ;
}
}
return V_48 ;
}
static struct V_1 * F_29 ( const struct V_2 * V_3 ,
T_1 V_18 ,
unsigned V_19 ,
unsigned long V_20 ,
T_1 V_4 ,
T_1 V_34 ,
enum V_39 V_22 )
{
struct V_1 * V_47 ;
struct V_1 * V_48 ;
T_1 V_25 ;
T_1 V_26 ;
T_1 V_49 ;
F_14 ( V_3 -> V_50 ) ;
V_48 = NULL ;
V_49 = ~ 0UL ;
F_34 (entry, mm, adj_start, adj_end,
flags & DRM_MM_SEARCH_BELOW) {
T_1 V_51 = V_26 - V_25 ;
if ( V_25 < V_4 )
V_25 = V_4 ;
if ( V_26 > V_34 )
V_26 = V_34 ;
if ( V_3 -> V_27 ) {
V_3 -> V_27 ( V_47 , V_20 , & V_25 , & V_26 ) ;
if ( V_26 <= V_25 )
continue;
}
if ( ! F_33 ( V_25 , V_26 , V_18 , V_19 ) )
continue;
if ( ! ( V_22 & V_52 ) )
return V_47 ;
if ( V_51 < V_49 ) {
V_48 = V_47 ;
V_49 = V_51 ;
}
}
return V_48 ;
}
void F_35 ( struct V_1 * V_53 , struct V_1 * V_54 )
{
F_36 ( & V_53 -> V_33 , & V_54 -> V_33 ) ;
F_36 ( & V_53 -> V_32 , & V_54 -> V_32 ) ;
F_37 ( & V_53 -> V_11 , & V_54 -> V_11 , & V_53 -> V_3 -> V_6 ) ;
V_54 -> V_31 = V_53 -> V_31 ;
V_54 -> V_3 = V_53 -> V_3 ;
V_54 -> V_4 = V_53 -> V_4 ;
V_54 -> V_18 = V_53 -> V_18 ;
V_54 -> V_20 = V_53 -> V_20 ;
V_54 -> V_13 = V_53 -> V_13 ;
V_53 -> V_14 = 0 ;
V_54 -> V_14 = 1 ;
}
void F_38 ( struct V_2 * V_3 ,
T_1 V_18 ,
unsigned V_19 ,
unsigned long V_20 )
{
V_3 -> V_55 = V_20 ;
V_3 -> V_56 = V_19 ;
V_3 -> V_57 = V_18 ;
V_3 -> V_50 = 0 ;
V_3 -> V_58 = 0 ;
V_3 -> V_59 = 0 ;
V_3 -> V_60 = 0 ;
V_3 -> V_61 = NULL ;
}
void F_39 ( struct V_2 * V_3 ,
T_1 V_18 ,
unsigned V_19 ,
unsigned long V_20 ,
T_1 V_4 ,
T_1 V_34 )
{
V_3 -> V_55 = V_20 ;
V_3 -> V_56 = V_19 ;
V_3 -> V_57 = V_18 ;
V_3 -> V_50 = 0 ;
V_3 -> V_58 = 0 ;
V_3 -> V_59 = 0 ;
V_3 -> V_62 = V_4 ;
V_3 -> V_63 = V_34 ;
V_3 -> V_60 = 1 ;
V_3 -> V_61 = NULL ;
}
bool F_40 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
struct V_1 * V_42 ;
T_1 V_23 , V_24 ;
T_1 V_25 , V_26 ;
V_3 -> V_50 ++ ;
F_14 ( V_7 -> V_43 ) ;
V_7 -> V_43 = 1 ;
V_42 = F_21 ( V_7 -> V_33 . V_46 , struct V_1 ,
V_33 ) ;
V_7 -> V_64 = V_42 -> V_31 ;
V_42 -> V_31 = 1 ;
F_16 ( & V_7 -> V_33 ) ;
V_7 -> V_33 . V_46 = & V_42 -> V_33 ;
V_7 -> V_33 . V_65 = & V_3 -> V_61 -> V_33 ;
V_3 -> V_61 = V_7 ;
V_25 = V_23 = F_12 ( V_42 ) ;
V_26 = V_24 = F_13 ( V_42 ) ;
if ( V_3 -> V_60 ) {
if ( V_25 < V_3 -> V_62 )
V_25 = V_3 -> V_62 ;
if ( V_26 > V_3 -> V_63 )
V_26 = V_3 -> V_63 ;
}
if ( V_3 -> V_27 )
V_3 -> V_27 ( V_42 , V_3 -> V_55 ,
& V_25 , & V_26 ) ;
if ( F_33 ( V_25 , V_26 ,
V_3 -> V_57 , V_3 -> V_56 ) ) {
V_3 -> V_58 = V_23 ;
V_3 -> V_59 = V_24 ;
return true ;
}
return false ;
}
bool F_41 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
struct V_1 * V_42 ;
V_3 -> V_50 -- ;
F_14 ( ! V_7 -> V_43 ) ;
V_7 -> V_43 = 0 ;
V_42 = F_21 ( V_7 -> V_33 . V_46 , struct V_1 ,
V_33 ) ;
V_42 -> V_31 = V_7 -> V_64 ;
F_17 ( & V_7 -> V_33 , & V_42 -> V_33 ) ;
return ( F_13 ( V_7 ) > V_3 -> V_58 &&
V_7 -> V_4 < V_3 -> V_59 ) ;
}
bool F_42 ( struct V_2 * V_3 )
{
struct V_66 * V_67 = & V_3 -> V_38 . V_33 ;
return ( V_67 -> V_65 -> V_65 == V_67 ) ;
}
void F_43 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_18 )
{
F_44 ( & V_3 -> V_32 ) ;
V_3 -> V_50 = 0 ;
F_44 ( & V_3 -> V_38 . V_33 ) ;
V_3 -> V_38 . V_31 = 1 ;
V_3 -> V_38 . V_43 = 0 ;
V_3 -> V_38 . V_44 = 0 ;
V_3 -> V_38 . V_45 = 0 ;
V_3 -> V_38 . V_3 = V_3 ;
V_3 -> V_38 . V_4 = V_4 + V_18 ;
V_3 -> V_38 . V_18 = V_4 - V_3 -> V_38 . V_4 ;
F_45 ( & V_3 -> V_38 . V_32 , & V_3 -> V_32 ) ;
V_3 -> V_6 = V_68 ;
V_3 -> V_27 = NULL ;
}
void F_46 ( struct V_2 * V_3 )
{
F_47 ( ! F_48 ( & V_3 -> V_38 . V_33 ) ,
L_1 ) ;
}
static T_1 F_49 ( struct V_1 * V_47 ,
const char * V_69 )
{
T_1 V_23 , V_24 , V_51 ;
if ( V_47 -> V_31 ) {
V_23 = F_12 ( V_47 ) ;
V_24 = F_13 ( V_47 ) ;
V_51 = V_24 - V_23 ;
F_50 ( L_2 , V_69 , V_23 ,
V_24 , V_51 ) ;
return V_51 ;
}
return 0 ;
}
void F_51 ( struct V_2 * V_3 , const char * V_69 )
{
struct V_1 * V_47 ;
T_1 V_70 = 0 , V_71 = 0 , V_72 = 0 ;
V_71 += F_49 ( & V_3 -> V_38 , V_69 ) ;
F_52 (entry, mm) {
F_50 ( L_3 , V_69 , V_47 -> V_4 ,
V_47 -> V_4 + V_47 -> V_18 , V_47 -> V_18 ) ;
V_70 += V_47 -> V_18 ;
V_71 += F_49 ( V_47 , V_69 ) ;
}
V_72 = V_71 + V_70 ;
F_50 ( L_4 , V_69 , V_72 ,
V_70 , V_71 ) ;
}
static T_1 F_53 ( struct V_73 * V_74 , struct V_1 * V_47 )
{
T_1 V_23 , V_24 , V_51 ;
if ( V_47 -> V_31 ) {
V_23 = F_12 ( V_47 ) ;
V_24 = F_13 ( V_47 ) ;
V_51 = V_24 - V_23 ;
F_54 ( V_74 , L_5 , V_23 ,
V_24 , V_51 ) ;
return V_51 ;
}
return 0 ;
}
int F_55 ( struct V_73 * V_74 , struct V_2 * V_3 )
{
struct V_1 * V_47 ;
T_1 V_70 = 0 , V_71 = 0 , V_72 = 0 ;
V_71 += F_53 ( V_74 , & V_3 -> V_38 ) ;
F_52 (entry, mm) {
F_54 ( V_74 , L_6 , V_47 -> V_4 ,
V_47 -> V_4 + V_47 -> V_18 , V_47 -> V_18 ) ;
V_70 += V_47 -> V_18 ;
V_71 += F_53 ( V_74 , V_47 ) ;
}
V_72 = V_71 + V_70 ;
F_54 ( V_74 , L_7 , V_72 ,
V_70 , V_71 ) ;
return 0 ;
}
