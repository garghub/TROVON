static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 ,
const char * V_7 , int V_8 )
{
struct V_2 * V_4 = V_6 -> V_2 ;
int V_9 ;
while ( V_4 ) {
struct V_1 * V_10 = F_1 ( V_4 ) ;
V_9 = strncmp ( V_7 , V_10 -> V_7 , V_8 ) ;
if ( V_9 > 0 )
V_4 = V_10 -> V_4 . V_11 ;
else if ( V_9 < 0 || V_8 < V_10 -> V_8 )
V_4 = V_10 -> V_4 . V_12 ;
else
return V_10 ;
}
return NULL ;
}
static struct V_1 * F_4 ( const char * V_7 , int V_8 ,
T_1 V_13 , unsigned int V_14 )
{
struct V_1 * V_10 ;
T_2 V_15 = F_5 ( struct V_1 , V_7 [ V_8 + 1 ] ) ;
V_10 = F_6 ( V_15 , V_16 ) ;
if ( V_10 ) {
memcpy ( V_10 -> V_7 , V_7 , V_8 ) ;
V_10 -> V_7 [ V_8 ] = '\0' ;
V_10 -> V_8 = V_8 ;
V_10 -> type = V_14 ;
V_10 -> V_13 = V_13 ;
V_10 -> V_17 = false ;
V_10 -> V_18 = false ;
}
return V_10 ;
}
static int F_7 ( struct V_19 * V_20 ,
const char * V_7 , int V_8 , T_1 V_13 ,
unsigned int V_14 )
{
struct V_2 * * V_21 = & V_20 -> V_6 . V_2 ;
struct V_2 * V_22 = NULL ;
struct V_1 * V_10 ;
while ( * V_21 ) {
int V_9 ;
struct V_1 * V_23 ;
V_22 = * V_21 ;
V_23 = F_1 ( * V_21 ) ;
V_9 = strncmp ( V_7 , V_23 -> V_7 , V_8 ) ;
if ( V_9 > 0 )
V_21 = & V_23 -> V_4 . V_11 ;
else if ( V_9 < 0 || V_8 < V_23 -> V_8 )
V_21 = & V_23 -> V_4 . V_12 ;
else
return 0 ;
}
V_10 = F_4 ( V_7 , V_8 , V_13 , V_14 ) ;
if ( V_10 == NULL )
return - V_24 ;
F_8 ( & V_10 -> V_25 , V_20 -> V_26 ) ;
F_9 ( & V_10 -> V_4 , V_22 , V_21 ) ;
F_10 ( & V_10 -> V_4 , & V_20 -> V_6 ) ;
return 0 ;
}
static int F_11 ( struct V_19 * V_20 ,
const char * V_7 , int V_27 ,
T_3 V_28 , T_1 V_13 , unsigned int V_14 )
{
struct V_1 * V_10 ;
V_10 = F_3 ( & V_20 -> V_6 , V_7 , V_27 ) ;
if ( V_10 ) {
F_12 ( & V_10 -> V_25 , & V_20 -> V_29 ) ;
} else {
V_10 = F_4 ( V_7 , V_27 , V_13 , V_14 ) ;
if ( V_10 == NULL )
V_20 -> V_30 = - V_24 ;
else
F_8 ( & V_10 -> V_25 , & V_20 -> V_29 ) ;
}
return V_20 -> V_30 ;
}
void F_13 ( struct V_31 * V_26 )
{
struct V_1 * V_10 ;
struct V_1 * V_3 ;
F_14 (p, n, list, l_node)
F_15 ( V_10 ) ;
F_16 ( V_26 ) ;
}
static void F_17 ( struct V_32 * V_33 , struct V_34 * V_34 )
{
struct V_35 * V_36 = V_33 -> V_36 ;
F_18 ( & V_33 -> V_37 . V_25 ) ;
F_19 ( V_36 -> V_38 <= 0 ) ;
V_36 -> V_38 -- ;
if ( ! V_36 -> V_38 ) {
if ( V_35 ( V_34 ) == V_36 )
F_20 ( V_34 , NULL ) ;
F_13 ( & V_36 -> V_39 ) ;
F_15 ( V_36 ) ;
}
}
static int F_21 ( struct V_40 * V_41 , const char * V_7 ,
int V_27 , T_3 V_28 , T_1 V_13 ,
unsigned int V_14 )
{
struct V_19 * V_20 =
F_2 ( V_41 , struct V_19 , V_41 ) ;
V_20 -> V_42 ++ ;
if ( ! V_20 -> V_43 )
return F_7 ( V_20 , V_7 , V_27 , V_13 , V_14 ) ;
else
return F_11 ( V_20 , V_7 , V_27 , V_28 , V_13 , V_14 ) ;
}
static inline int F_22 ( struct V_44 * V_45 ,
struct V_19 * V_20 )
{
struct V_46 * V_47 ;
int V_30 ;
V_47 = F_23 ( V_45 , V_48 | V_49 ) ;
if ( F_24 ( V_47 ) )
return F_25 ( V_47 ) ;
V_20 -> V_41 . V_50 = 0 ;
do {
V_20 -> V_42 = 0 ;
V_20 -> V_30 = 0 ;
V_30 = F_26 ( V_47 , & V_20 -> V_41 ) ;
if ( V_30 >= 0 )
V_30 = V_20 -> V_30 ;
} while ( ! V_30 && V_20 -> V_42 );
F_27 ( V_47 ) ;
return V_30 ;
}
static void F_28 ( struct V_46 * V_46 )
{
struct V_32 * V_33 = V_46 -> V_51 ;
struct V_35 * V_36 = V_33 -> V_36 ;
struct V_34 * V_34 = V_46 -> V_52 . V_34 ;
enum V_53 type = V_53 ( V_34 ) ;
if ( V_36 && F_29 ( V_34 ) != V_36 -> V_54 ) {
F_17 ( V_33 , V_34 ) ;
V_33 -> V_36 = NULL ;
}
F_19 ( ! V_33 -> V_55 && type != V_56 ) ;
if ( V_33 -> V_55 && type == V_56 )
V_33 -> V_55 = false ;
}
static int F_30 ( struct V_34 * V_57 ,
struct V_19 * V_20 )
{
struct V_1 * V_10 ;
struct V_34 * V_34 ;
const struct V_58 * V_59 ;
struct V_58 * V_60 ;
V_60 = F_31 () ;
if ( ! V_60 ) {
F_13 ( V_20 -> V_26 ) ;
return - V_24 ;
}
F_32 ( V_60 -> V_61 , V_62 ) ;
V_59 = F_33 ( V_60 ) ;
F_34 ( & V_57 -> V_63 -> V_64 ) ;
F_35 (p, rdd->list, l_node) {
if ( V_10 -> V_18 )
continue;
if ( V_10 -> type != V_65 )
continue;
V_34 = F_36 ( V_10 -> V_7 , V_57 , V_10 -> V_8 ) ;
if ( F_24 ( V_34 ) )
continue;
V_10 -> V_17 = F_37 ( V_34 ) ;
F_38 ( V_34 ) ;
}
F_39 ( & V_57 -> V_63 -> V_64 ) ;
F_40 ( V_59 ) ;
F_41 ( V_60 ) ;
return 0 ;
}
static int F_42 ( struct V_34 * V_34 , struct V_31 * V_26 )
{
int V_30 ;
struct V_44 V_66 ;
struct V_44 V_67 ;
struct V_19 V_20 = {
. V_41 . V_68 = F_21 ,
. V_26 = V_26 ,
. V_6 = V_69 ,
. V_43 = false ,
} ;
F_43 ( V_34 , & V_66 ) ;
F_44 ( V_34 , & V_67 ) ;
if ( V_67 . V_34 ) {
V_30 = F_22 ( & V_67 , & V_20 ) ;
if ( V_30 )
goto V_70;
if ( V_66 . V_34 ) {
V_30 = F_30 ( V_67 . V_34 , & V_20 ) ;
if ( V_30 )
goto V_70;
}
}
if ( V_66 . V_34 ) {
F_45 ( & V_20 . V_29 , V_20 . V_26 ) ;
V_20 . V_43 = true ;
V_30 = F_22 ( & V_66 , & V_20 ) ;
F_46 ( & V_20 . V_29 ) ;
}
V_70:
return V_30 ;
}
static void F_47 ( struct V_32 * V_33 , T_3 V_50 )
{
struct V_1 * V_10 ;
T_3 V_71 = 0 ;
F_35 (p, &od->cache->entries, l_node) {
if ( V_10 -> V_18 )
continue;
if ( V_71 >= V_50 )
break;
V_71 ++ ;
}
F_12 ( & V_33 -> V_37 . V_25 , & V_10 -> V_25 ) ;
}
static struct V_35 * F_48 ( struct V_34 * V_34 )
{
int V_72 ;
struct V_35 * V_36 ;
V_36 = V_35 ( V_34 ) ;
if ( V_36 && F_29 ( V_34 ) == V_36 -> V_54 ) {
V_36 -> V_38 ++ ;
return V_36 ;
}
F_20 ( V_34 , NULL ) ;
V_36 = F_49 ( sizeof( struct V_35 ) , V_16 ) ;
if ( ! V_36 )
return F_50 ( - V_24 ) ;
V_36 -> V_38 = 1 ;
F_16 ( & V_36 -> V_39 ) ;
V_72 = F_42 ( V_34 , & V_36 -> V_39 ) ;
if ( V_72 ) {
F_13 ( & V_36 -> V_39 ) ;
F_15 ( V_36 ) ;
return F_50 ( V_72 ) ;
}
V_36 -> V_54 = F_29 ( V_34 ) ;
F_20 ( V_34 , V_36 ) ;
return V_36 ;
}
static int F_51 ( struct V_46 * V_46 , struct V_40 * V_41 )
{
struct V_32 * V_33 = V_46 -> V_51 ;
struct V_34 * V_34 = V_46 -> V_52 . V_34 ;
if ( ! V_41 -> V_50 )
F_28 ( V_46 ) ;
if ( V_33 -> V_55 )
return F_26 ( V_33 -> V_47 , V_41 ) ;
if ( ! V_33 -> V_36 ) {
struct V_35 * V_36 ;
V_36 = F_48 ( V_34 ) ;
if ( F_24 ( V_36 ) )
return F_25 ( V_36 ) ;
V_33 -> V_36 = V_36 ;
F_47 ( V_33 , V_41 -> V_50 ) ;
}
while ( V_33 -> V_37 . V_25 . V_73 != & V_33 -> V_36 -> V_39 ) {
struct V_1 * V_10 ;
V_10 = F_52 ( V_33 -> V_37 . V_25 . V_73 , struct V_1 , V_25 ) ;
if ( ! V_10 -> V_18 ) {
if ( ! V_10 -> V_17 ) {
if ( ! F_53 ( V_41 , V_10 -> V_7 , V_10 -> V_8 , V_10 -> V_13 , V_10 -> type ) )
break;
}
V_41 -> V_50 ++ ;
}
F_54 ( & V_33 -> V_37 . V_25 , & V_10 -> V_25 ) ;
}
return 0 ;
}
static T_3 F_55 ( struct V_46 * V_46 , T_3 V_28 , int V_74 )
{
T_3 V_72 ;
struct V_32 * V_33 = V_46 -> V_51 ;
F_34 ( & F_56 ( V_46 ) -> V_64 ) ;
if ( ! V_46 -> V_75 )
F_28 ( V_46 ) ;
if ( V_33 -> V_55 ) {
V_72 = F_57 ( V_33 -> V_47 , V_28 , V_74 ) ;
V_46 -> V_75 = V_33 -> V_47 -> V_75 ;
} else {
V_72 = - V_76 ;
switch ( V_74 ) {
case V_77 :
V_28 += V_46 -> V_75 ;
break;
case V_78 :
break;
default:
goto V_79;
}
if ( V_28 < 0 )
goto V_79;
if ( V_28 != V_46 -> V_75 ) {
V_46 -> V_75 = V_28 ;
if ( V_33 -> V_36 )
F_47 ( V_33 , V_28 ) ;
}
V_72 = V_28 ;
}
V_79:
F_39 ( & F_56 ( V_46 ) -> V_64 ) ;
return V_72 ;
}
static int F_58 ( struct V_46 * V_46 , T_3 V_80 , T_3 V_81 ,
int V_82 )
{
struct V_32 * V_33 = V_46 -> V_51 ;
struct V_34 * V_34 = V_46 -> V_52 . V_34 ;
struct V_46 * V_47 = V_33 -> V_47 ;
if ( ! V_33 -> V_83 && V_53 ( V_34 ) != V_84 ) {
struct V_85 * V_85 = F_56 ( V_46 ) ;
V_47 = F_59 ( V_33 -> V_86 ) ;
if ( ! V_47 ) {
struct V_44 V_67 ;
F_44 ( V_34 , & V_67 ) ;
V_47 = F_23 ( & V_67 , V_48 ) ;
F_60 () ;
F_34 ( & V_85 -> V_64 ) ;
if ( ! V_33 -> V_86 ) {
if ( F_24 ( V_47 ) ) {
F_39 ( & V_85 -> V_64 ) ;
return F_25 ( V_47 ) ;
}
V_33 -> V_86 = V_47 ;
} else {
if ( ! F_24 ( V_47 ) )
F_27 ( V_47 ) ;
V_47 = V_33 -> V_86 ;
}
F_39 ( & V_85 -> V_64 ) ;
}
}
return F_61 ( V_47 , V_80 , V_81 , V_82 ) ;
}
static int F_62 ( struct V_85 * V_85 , struct V_46 * V_46 )
{
struct V_32 * V_33 = V_46 -> V_51 ;
if ( V_33 -> V_36 ) {
F_34 ( & V_85 -> V_64 ) ;
F_17 ( V_33 , V_46 -> V_52 . V_34 ) ;
F_39 ( & V_85 -> V_64 ) ;
}
F_27 ( V_33 -> V_47 ) ;
if ( V_33 -> V_86 )
F_27 ( V_33 -> V_86 ) ;
F_15 ( V_33 ) ;
return 0 ;
}
static int F_63 ( struct V_85 * V_85 , struct V_46 * V_46 )
{
struct V_44 V_45 ;
struct V_46 * V_47 ;
struct V_32 * V_33 ;
enum V_53 type ;
V_33 = F_49 ( sizeof( struct V_32 ) , V_16 ) ;
if ( ! V_33 )
return - V_24 ;
type = F_64 ( V_46 -> V_52 . V_34 , & V_45 ) ;
V_47 = F_23 ( & V_45 , V_46 -> V_87 ) ;
if ( F_24 ( V_47 ) ) {
F_15 ( V_33 ) ;
return F_25 ( V_47 ) ;
}
F_16 ( & V_33 -> V_37 . V_25 ) ;
V_33 -> V_47 = V_47 ;
V_33 -> V_55 = ( type != V_56 ) ;
V_33 -> V_83 = ( type != V_84 ) ;
V_33 -> V_37 . V_18 = true ;
V_46 -> V_51 = V_33 ;
return 0 ;
}
int F_65 ( struct V_34 * V_34 , struct V_31 * V_26 )
{
int V_30 ;
struct V_1 * V_10 ;
V_30 = F_42 ( V_34 , V_26 ) ;
if ( V_30 )
return V_30 ;
V_30 = 0 ;
F_35 (p, list, l_node) {
if ( V_10 -> V_17 )
continue;
if ( V_10 -> V_7 [ 0 ] == '.' ) {
if ( V_10 -> V_8 == 1 )
continue;
if ( V_10 -> V_8 == 2 && V_10 -> V_7 [ 1 ] == '.' )
continue;
}
V_30 = - V_88 ;
break;
}
return V_30 ;
}
void F_66 ( struct V_34 * V_89 , struct V_31 * V_26 )
{
struct V_1 * V_10 ;
F_67 ( & V_89 -> V_63 -> V_64 , V_90 ) ;
F_35 (p, list, l_node) {
struct V_34 * V_34 ;
if ( ! V_10 -> V_17 )
continue;
V_34 = F_36 ( V_10 -> V_7 , V_89 , V_10 -> V_8 ) ;
if ( F_24 ( V_34 ) ) {
F_68 ( L_1 ,
V_89 -> V_91 . V_7 , V_10 -> V_8 , V_10 -> V_7 ,
( int ) F_25 ( V_34 ) ) ;
continue;
}
F_69 ( V_89 -> V_63 , V_34 ) ;
F_38 ( V_34 ) ;
}
F_39 ( & V_89 -> V_63 -> V_64 ) ;
}
