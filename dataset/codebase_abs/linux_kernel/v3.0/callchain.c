bool F_1 ( struct V_1 * V_2 ,
const union V_3 * V_4 )
{
unsigned int V_5 = V_4 -> V_6 . V_7 ;
V_5 -= ( unsigned long ) & V_4 -> V_8 . V_9 - ( unsigned long ) V_4 ;
return V_2 -> V_10 * sizeof( V_11 ) <= V_5 ;
}
static void
F_2 ( struct V_12 * V_13 , struct V_14 * V_2 ,
enum V_15 V_16 )
{
struct V_17 * * V_18 = & V_13 -> V_17 ;
struct V_17 * V_19 = NULL ;
struct V_14 * V_20 ;
V_11 V_21 = F_3 ( V_2 ) ;
while ( * V_18 ) {
V_11 V_22 ;
V_19 = * V_18 ;
V_20 = F_4 ( V_19 , struct V_14 , V_17 ) ;
V_22 = F_3 ( V_20 ) ;
switch ( V_16 ) {
case V_23 :
if ( V_20 -> V_24 < V_2 -> V_24 )
V_18 = & ( * V_18 ) -> V_25 ;
else
V_18 = & ( * V_18 ) -> V_26 ;
break;
case V_27 :
case V_28 :
if ( V_22 < V_21 )
V_18 = & ( * V_18 ) -> V_25 ;
else
V_18 = & ( * V_18 ) -> V_26 ;
break;
case V_29 :
default:
break;
}
}
F_5 ( & V_2 -> V_17 , V_19 , V_18 ) ;
F_6 ( & V_2 -> V_17 , V_13 ) ;
}
static void
F_7 ( struct V_12 * V_12 , struct V_14 * V_30 ,
V_11 V_31 )
{
struct V_14 * V_32 ;
F_8 (child, node)
F_7 ( V_12 , V_32 , V_31 ) ;
if ( V_30 -> V_24 && V_30 -> V_24 >= V_31 )
F_2 ( V_12 , V_30 , V_23 ) ;
}
static void
F_9 ( struct V_12 * V_12 , struct V_33 * V_13 ,
V_11 V_31 , struct V_34 * T_1 V_35 )
{
F_7 ( V_12 , & V_13 -> V_30 , V_31 ) ;
}
static void F_10 ( struct V_14 * V_30 ,
V_11 V_31 )
{
struct V_14 * V_32 ;
V_30 -> V_12 = V_36 ;
F_8 (child, node) {
F_10 ( V_32 , V_31 ) ;
if ( F_3 ( V_32 ) >= V_31 )
F_2 ( & V_30 -> V_12 , V_32 ,
V_27 ) ;
}
}
static void
F_11 ( struct V_12 * V_12 , struct V_33 * V_37 ,
V_11 V_31 , struct V_34 * T_1 V_35 )
{
F_10 ( & V_37 -> V_30 , V_31 ) ;
V_12 -> V_17 = V_37 -> V_30 . V_12 . V_17 ;
}
static void F_12 ( struct V_14 * V_30 ,
double V_38 )
{
struct V_14 * V_32 ;
V_11 V_31 ;
V_30 -> V_12 = V_36 ;
V_31 = ceil ( V_30 -> V_39 * V_38 ) ;
F_8 (child, node) {
F_12 ( V_32 , V_38 ) ;
if ( F_3 ( V_32 ) >= V_31 )
F_2 ( & V_30 -> V_12 , V_32 ,
V_28 ) ;
}
}
static void
F_13 ( struct V_12 * V_12 , struct V_33 * V_37 ,
V_11 V_31 V_35 , struct V_34 * T_1 )
{
F_12 ( & V_37 -> V_30 , T_1 -> V_38 / 100.0 ) ;
V_12 -> V_17 = V_37 -> V_30 . V_12 . V_17 ;
}
int F_14 ( struct V_34 * T_1 )
{
switch ( T_1 -> V_16 ) {
case V_27 :
T_1 -> V_40 = F_11 ;
break;
case V_28 :
T_1 -> V_40 = F_13 ;
break;
case V_23 :
T_1 -> V_40 = F_9 ;
break;
case V_29 :
default:
return - 1 ;
}
return 0 ;
}
static struct V_14 *
F_15 ( struct V_14 * V_19 , bool V_41 )
{
struct V_14 * V_42 ;
V_42 = F_16 ( sizeof( * V_42 ) ) ;
if ( ! V_42 ) {
perror ( L_1 ) ;
return NULL ;
}
V_42 -> V_19 = V_19 ;
F_17 ( & V_42 -> V_43 ) ;
F_17 ( & V_42 -> V_44 ) ;
if ( V_41 ) {
struct V_14 * V_45 ;
F_18 ( & V_19 -> V_43 , & V_42 -> V_43 ) ;
F_17 ( & V_19 -> V_43 ) ;
F_8 (next, new)
V_45 -> V_19 = V_42 ;
}
F_19 ( & V_42 -> V_46 , & V_19 -> V_43 ) ;
return V_42 ;
}
static void
F_20 ( struct V_14 * V_30 , struct V_47 * V_48 )
{
struct V_49 * V_50 ;
V_30 -> V_51 = V_48 -> V_10 - V_48 -> V_52 ;
if ( ! V_30 -> V_51 )
F_21 ( L_2 ) ;
V_50 = F_22 ( V_48 ) ;
while ( V_50 ) {
struct V_53 * V_54 ;
V_54 = F_16 ( sizeof( * V_54 ) ) ;
if ( ! V_54 ) {
perror ( L_3 ) ;
return;
}
V_54 -> V_8 = V_50 -> V_8 ;
V_54 -> V_55 . V_56 = V_50 -> V_56 ;
V_54 -> V_55 . V_57 = V_50 -> V_57 ;
F_19 ( & V_54 -> V_58 , & V_30 -> V_44 ) ;
F_23 ( V_48 ) ;
V_50 = F_22 ( V_48 ) ;
}
}
static void
F_24 ( struct V_14 * V_19 ,
struct V_47 * V_48 ,
V_11 V_59 )
{
struct V_14 * V_42 ;
V_42 = F_15 ( V_19 , false ) ;
F_20 ( V_42 , V_48 ) ;
V_42 -> V_39 = 0 ;
V_42 -> V_24 = V_59 ;
}
static void
F_25 ( struct V_14 * V_19 ,
struct V_47 * V_48 ,
struct V_53 * V_60 ,
V_11 V_61 , V_11 V_62 , V_11 V_59 )
{
struct V_14 * V_42 ;
struct V_63 * V_64 ;
unsigned int V_65 = V_61 + V_62 ;
V_42 = F_15 ( V_19 , true ) ;
V_64 = V_19 -> V_44 . V_66 ;
F_26 ( & V_60 -> V_58 , V_64 ) ;
V_42 -> V_44 . V_45 = & V_60 -> V_58 ;
V_42 -> V_44 . V_66 = V_64 ;
V_60 -> V_58 . V_66 = & V_42 -> V_44 ;
V_64 -> V_45 = & V_42 -> V_44 ;
V_42 -> V_24 = V_19 -> V_24 ;
V_42 -> V_39 = V_19 -> V_39 ;
V_19 -> V_39 = F_3 ( V_42 ) ;
V_42 -> V_51 = V_19 -> V_51 - V_62 ;
V_19 -> V_51 = V_62 ;
if ( V_65 < V_48 -> V_10 ) {
V_19 -> V_24 = 0 ;
F_24 ( V_19 , V_48 , V_59 ) ;
V_19 -> V_39 += V_59 ;
} else {
V_19 -> V_24 = V_59 ;
}
}
static void
F_27 ( struct V_14 * V_13 ,
struct V_47 * V_48 ,
V_11 V_59 )
{
struct V_14 * V_20 ;
F_8 (rnode, root) {
unsigned int V_67 = F_28 ( V_20 , V_48 , V_59 ) ;
if ( ! V_67 )
goto V_68;
}
F_24 ( V_13 , V_48 , V_59 ) ;
V_68:
V_13 -> V_39 += V_59 ;
}
static int
F_28 ( struct V_14 * V_13 ,
struct V_47 * V_48 ,
V_11 V_59 )
{
struct V_49 * V_69 = V_48 -> V_70 ;
struct V_53 * V_71 ;
V_11 V_72 = V_48 -> V_52 ;
bool V_73 = false ;
V_11 V_74 ;
F_29 (cnode, &root->val, list) {
struct V_49 * V_30 ;
struct V_75 * V_56 ;
V_30 = F_22 ( V_48 ) ;
if ( ! V_30 )
break;
V_56 = V_30 -> V_56 ;
if ( V_71 -> V_55 . V_56 && V_56 ) {
if ( V_71 -> V_55 . V_56 -> V_72 != V_56 -> V_72 )
break;
} else if ( V_71 -> V_8 != V_30 -> V_8 )
break;
if ( ! V_73 )
V_73 = true ;
F_23 ( V_48 ) ;
}
if ( ! V_73 ) {
V_48 -> V_70 = V_69 ;
V_48 -> V_52 = V_72 ;
return - 1 ;
}
V_74 = V_48 -> V_52 - V_72 ;
if ( V_74 < V_13 -> V_51 ) {
F_25 ( V_13 , V_48 , V_71 , V_72 , V_74 , V_59 ) ;
return 0 ;
}
if ( V_74 == V_13 -> V_51 && V_48 -> V_52 == V_48 -> V_10 ) {
V_13 -> V_24 += V_59 ;
return 0 ;
}
F_27 ( V_13 , V_48 , V_59 ) ;
return 0 ;
}
int F_30 ( struct V_33 * V_13 ,
struct V_47 * V_48 ,
V_11 V_59 )
{
if ( ! V_48 -> V_10 )
return 0 ;
F_31 ( V_48 ) ;
F_27 ( & V_13 -> V_30 , V_48 , V_59 ) ;
if ( V_48 -> V_10 > V_13 -> V_76 )
V_13 -> V_76 = V_48 -> V_10 ;
return 0 ;
}
static int
F_32 ( struct V_47 * V_48 ,
struct V_14 * V_77 , struct V_14 * V_78 )
{
struct V_49 * * V_79 = V_48 -> V_80 ;
struct V_14 * V_32 , * V_81 ;
struct V_53 * V_58 , * V_82 ;
int V_83 = V_48 -> V_10 ;
int V_84 = 0 ;
F_33 (list, next_list, &src->val, list) {
F_34 ( V_48 , V_58 -> V_8 ,
V_58 -> V_55 . V_57 , V_58 -> V_55 . V_56 ) ;
F_35 ( & V_58 -> V_58 ) ;
free ( V_58 ) ;
}
if ( V_78 -> V_24 ) {
F_31 ( V_48 ) ;
F_27 ( V_77 , V_48 , V_78 -> V_24 ) ;
}
F_36 (child, next_child, src) {
V_84 = F_32 ( V_48 , V_77 , V_32 ) ;
if ( V_84 )
break;
F_35 ( & V_32 -> V_46 ) ;
free ( V_32 ) ;
}
V_48 -> V_10 = V_83 ;
V_48 -> V_80 = V_79 ;
return V_84 ;
}
int F_37 ( struct V_47 * V_48 ,
struct V_33 * V_77 , struct V_33 * V_78 )
{
return F_32 ( V_48 , & V_77 -> V_30 , & V_78 -> V_30 ) ;
}
int F_34 ( struct V_47 * V_48 ,
V_11 V_8 , struct V_57 * V_57 , struct V_75 * V_56 )
{
struct V_49 * V_30 = * V_48 -> V_80 ;
if ( ! V_30 ) {
V_30 = calloc ( sizeof( * V_30 ) , 1 ) ;
if ( ! V_30 )
return - V_85 ;
* V_48 -> V_80 = V_30 ;
}
V_30 -> V_8 = V_8 ;
V_30 -> V_57 = V_57 ;
V_30 -> V_56 = V_56 ;
V_48 -> V_10 ++ ;
V_48 -> V_80 = & V_30 -> V_45 ;
return 0 ;
}
