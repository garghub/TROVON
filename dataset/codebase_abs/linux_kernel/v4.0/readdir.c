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
static struct V_1 * F_4 ( struct V_13 * V_14 ,
const char * V_7 , int V_8 ,
T_1 V_15 , unsigned int V_16 )
{
struct V_1 * V_10 ;
T_2 V_17 = F_5 ( struct V_1 , V_7 [ V_8 + 1 ] ) ;
V_10 = F_6 ( V_17 , V_18 ) ;
if ( ! V_10 )
return NULL ;
memcpy ( V_10 -> V_7 , V_7 , V_8 ) ;
V_10 -> V_7 [ V_8 ] = '\0' ;
V_10 -> V_8 = V_8 ;
V_10 -> type = V_16 ;
V_10 -> V_15 = V_15 ;
V_10 -> V_19 = false ;
if ( V_16 == V_20 ) {
struct V_13 * V_13 ;
const struct V_21 * V_22 ;
struct V_21 * V_23 ;
V_23 = F_7 () ;
if ( ! V_23 ) {
F_8 ( V_10 ) ;
return NULL ;
}
F_9 ( V_23 -> V_24 , V_25 ) ;
V_22 = F_10 ( V_23 ) ;
V_13 = F_11 ( V_7 , V_14 , V_8 ) ;
if ( ! F_12 ( V_13 ) ) {
V_10 -> V_19 = F_13 ( V_13 ) ;
F_14 ( V_13 ) ;
}
F_15 ( V_22 ) ;
F_16 ( V_23 ) ;
}
return V_10 ;
}
static int F_17 ( struct V_26 * V_27 ,
const char * V_7 , int V_8 , T_1 V_15 ,
unsigned int V_16 )
{
struct V_2 * * V_28 = & V_27 -> V_6 . V_2 ;
struct V_2 * V_29 = NULL ;
struct V_1 * V_10 ;
while ( * V_28 ) {
int V_9 ;
struct V_1 * V_30 ;
V_29 = * V_28 ;
V_30 = F_1 ( * V_28 ) ;
V_9 = strncmp ( V_7 , V_30 -> V_7 , V_8 ) ;
if ( V_9 > 0 )
V_28 = & V_30 -> V_4 . V_11 ;
else if ( V_9 < 0 || V_8 < V_30 -> V_8 )
V_28 = & V_30 -> V_4 . V_12 ;
else
return 0 ;
}
V_10 = F_4 ( V_27 -> V_14 , V_7 , V_8 , V_15 , V_16 ) ;
if ( V_10 == NULL )
return - V_31 ;
F_18 ( & V_10 -> V_32 , V_27 -> V_33 ) ;
F_19 ( & V_10 -> V_4 , V_29 , V_28 ) ;
F_20 ( & V_10 -> V_4 , & V_27 -> V_6 ) ;
return 0 ;
}
static int F_21 ( struct V_26 * V_27 ,
const char * V_7 , int V_34 ,
T_3 V_35 , T_1 V_15 , unsigned int V_16 )
{
struct V_1 * V_10 ;
V_10 = F_3 ( & V_27 -> V_6 , V_7 , V_34 ) ;
if ( V_10 ) {
F_22 ( & V_10 -> V_32 , & V_27 -> V_36 ) ;
} else {
V_10 = F_4 ( V_27 -> V_14 , V_7 , V_34 , V_15 , V_16 ) ;
if ( V_10 == NULL )
V_27 -> V_37 = - V_31 ;
else
F_18 ( & V_10 -> V_32 , & V_27 -> V_36 ) ;
}
return V_27 -> V_37 ;
}
void F_23 ( struct V_38 * V_33 )
{
struct V_1 * V_10 ;
struct V_1 * V_3 ;
F_24 (p, n, list, l_node)
F_8 ( V_10 ) ;
F_25 ( V_33 ) ;
}
static void F_26 ( struct V_39 * V_40 , struct V_13 * V_13 )
{
struct V_41 * V_42 = V_40 -> V_42 ;
F_27 ( V_42 -> V_43 <= 0 ) ;
V_42 -> V_43 -- ;
if ( ! V_42 -> V_43 ) {
if ( V_41 ( V_13 ) == V_42 )
F_28 ( V_13 , NULL ) ;
F_23 ( & V_42 -> V_44 ) ;
F_8 ( V_42 ) ;
}
}
static int F_29 ( struct V_45 * V_46 , const char * V_7 ,
int V_34 , T_3 V_35 , T_1 V_15 ,
unsigned int V_16 )
{
struct V_26 * V_27 =
F_2 ( V_46 , struct V_26 , V_46 ) ;
V_27 -> V_47 ++ ;
if ( ! V_27 -> V_48 )
return F_17 ( V_27 , V_7 , V_34 , V_15 , V_16 ) ;
else
return F_21 ( V_27 , V_7 , V_34 , V_35 , V_15 , V_16 ) ;
}
static inline int F_30 ( struct V_49 * V_50 ,
struct V_26 * V_27 )
{
struct V_51 * V_52 ;
int V_37 ;
V_52 = F_31 ( V_50 , V_53 | V_54 ) ;
if ( F_12 ( V_52 ) )
return F_32 ( V_52 ) ;
V_27 -> V_14 = V_50 -> V_13 ;
V_27 -> V_46 . V_55 = 0 ;
do {
V_27 -> V_47 = 0 ;
V_27 -> V_37 = 0 ;
V_37 = F_33 ( V_52 , & V_27 -> V_46 ) ;
if ( V_37 >= 0 )
V_37 = V_27 -> V_37 ;
} while ( ! V_37 && V_27 -> V_47 );
F_34 ( V_52 ) ;
return V_37 ;
}
static void F_35 ( struct V_51 * V_51 )
{
struct V_39 * V_40 = V_51 -> V_56 ;
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_13 * V_13 = V_51 -> V_57 . V_13 ;
enum V_58 type = V_58 ( V_13 ) ;
if ( V_42 && F_36 ( V_13 ) != V_42 -> V_59 ) {
F_26 ( V_40 , V_13 ) ;
V_40 -> V_42 = NULL ;
V_40 -> V_60 = NULL ;
}
F_27 ( ! V_40 -> V_61 && ! F_37 ( type ) ) ;
if ( V_40 -> V_61 && F_37 ( type ) )
V_40 -> V_61 = false ;
}
static int F_38 ( struct V_13 * V_13 , struct V_38 * V_33 )
{
int V_37 ;
struct V_49 V_50 ;
struct V_26 V_27 = {
. V_46 . V_62 = F_29 ,
. V_33 = V_33 ,
. V_6 = V_63 ,
. V_48 = false ,
} ;
int V_64 , V_65 ;
for ( V_64 = 0 ; V_64 != - 1 ; V_64 = V_65 ) {
V_65 = F_39 ( V_64 , V_13 , & V_50 ) ;
if ( V_65 != - 1 ) {
V_37 = F_30 ( & V_50 , & V_27 ) ;
if ( V_37 )
break;
} else {
F_40 ( & V_27 . V_36 , V_27 . V_33 ) ;
V_27 . V_48 = true ;
V_37 = F_30 ( & V_50 , & V_27 ) ;
F_41 ( & V_27 . V_36 ) ;
}
}
return V_37 ;
}
static void F_42 ( struct V_39 * V_40 , T_3 V_55 )
{
struct V_38 * V_10 ;
T_3 V_66 = 0 ;
F_43 (p, &od->cache->entries) {
if ( V_66 >= V_55 )
break;
V_66 ++ ;
}
V_40 -> V_60 = V_10 ;
}
static struct V_41 * F_44 ( struct V_13 * V_13 )
{
int V_67 ;
struct V_41 * V_42 ;
V_42 = V_41 ( V_13 ) ;
if ( V_42 && F_36 ( V_13 ) == V_42 -> V_59 ) {
V_42 -> V_43 ++ ;
return V_42 ;
}
F_28 ( V_13 , NULL ) ;
V_42 = F_45 ( sizeof( struct V_41 ) , V_18 ) ;
if ( ! V_42 )
return F_46 ( - V_31 ) ;
V_42 -> V_43 = 1 ;
F_25 ( & V_42 -> V_44 ) ;
V_67 = F_38 ( V_13 , & V_42 -> V_44 ) ;
if ( V_67 ) {
F_23 ( & V_42 -> V_44 ) ;
F_8 ( V_42 ) ;
return F_46 ( V_67 ) ;
}
V_42 -> V_59 = F_36 ( V_13 ) ;
F_28 ( V_13 , V_42 ) ;
return V_42 ;
}
static int F_47 ( struct V_51 * V_51 , struct V_45 * V_46 )
{
struct V_39 * V_40 = V_51 -> V_56 ;
struct V_13 * V_13 = V_51 -> V_57 . V_13 ;
struct V_1 * V_10 ;
if ( ! V_46 -> V_55 )
F_35 ( V_51 ) ;
if ( V_40 -> V_61 )
return F_33 ( V_40 -> V_52 , V_46 ) ;
if ( ! V_40 -> V_42 ) {
struct V_41 * V_42 ;
V_42 = F_44 ( V_13 ) ;
if ( F_12 ( V_42 ) )
return F_32 ( V_42 ) ;
V_40 -> V_42 = V_42 ;
F_42 ( V_40 , V_46 -> V_55 ) ;
}
while ( V_40 -> V_60 != & V_40 -> V_42 -> V_44 ) {
V_10 = F_48 ( V_40 -> V_60 , struct V_1 , V_32 ) ;
if ( ! V_10 -> V_19 )
if ( ! F_49 ( V_46 , V_10 -> V_7 , V_10 -> V_8 , V_10 -> V_15 , V_10 -> type ) )
break;
V_40 -> V_60 = V_10 -> V_32 . V_65 ;
V_46 -> V_55 ++ ;
}
return 0 ;
}
static T_3 F_50 ( struct V_51 * V_51 , T_3 V_35 , int V_68 )
{
T_3 V_67 ;
struct V_39 * V_40 = V_51 -> V_56 ;
F_51 ( & F_52 ( V_51 ) -> V_69 ) ;
if ( ! V_51 -> V_70 )
F_35 ( V_51 ) ;
if ( V_40 -> V_61 ) {
V_67 = F_53 ( V_40 -> V_52 , V_35 , V_68 ) ;
V_51 -> V_70 = V_40 -> V_52 -> V_70 ;
} else {
V_67 = - V_71 ;
switch ( V_68 ) {
case V_72 :
V_35 += V_51 -> V_70 ;
break;
case V_73 :
break;
default:
goto V_74;
}
if ( V_35 < 0 )
goto V_74;
if ( V_35 != V_51 -> V_70 ) {
V_51 -> V_70 = V_35 ;
if ( V_40 -> V_42 )
F_42 ( V_40 , V_35 ) ;
}
V_67 = V_35 ;
}
V_74:
F_54 ( & F_52 ( V_51 ) -> V_69 ) ;
return V_67 ;
}
static int F_55 ( struct V_51 * V_51 , T_3 V_75 , T_3 V_76 ,
int V_77 )
{
struct V_39 * V_40 = V_51 -> V_56 ;
struct V_13 * V_13 = V_51 -> V_57 . V_13 ;
struct V_51 * V_52 = V_40 -> V_52 ;
if ( ! V_40 -> V_78 && F_56 ( V_58 ( V_13 ) ) ) {
struct V_79 * V_79 = F_52 ( V_51 ) ;
V_52 = F_57 ( V_40 -> V_80 ) ;
if ( ! V_52 ) {
struct V_49 V_81 ;
F_58 ( V_13 , & V_81 ) ;
V_52 = F_31 ( & V_81 , V_53 ) ;
F_59 () ;
F_51 ( & V_79 -> V_69 ) ;
if ( ! V_40 -> V_80 ) {
if ( F_12 ( V_52 ) ) {
F_54 ( & V_79 -> V_69 ) ;
return F_32 ( V_52 ) ;
}
V_40 -> V_80 = V_52 ;
} else {
if ( ! F_12 ( V_52 ) )
F_34 ( V_52 ) ;
V_52 = V_40 -> V_80 ;
}
F_54 ( & V_79 -> V_69 ) ;
}
}
return F_60 ( V_52 , V_75 , V_76 , V_77 ) ;
}
static int F_61 ( struct V_79 * V_79 , struct V_51 * V_51 )
{
struct V_39 * V_40 = V_51 -> V_56 ;
if ( V_40 -> V_42 ) {
F_51 ( & V_79 -> V_69 ) ;
F_26 ( V_40 , V_51 -> V_57 . V_13 ) ;
F_54 ( & V_79 -> V_69 ) ;
}
F_34 ( V_40 -> V_52 ) ;
if ( V_40 -> V_80 )
F_34 ( V_40 -> V_80 ) ;
F_8 ( V_40 ) ;
return 0 ;
}
static int F_62 ( struct V_79 * V_79 , struct V_51 * V_51 )
{
struct V_49 V_50 ;
struct V_51 * V_52 ;
struct V_39 * V_40 ;
enum V_58 type ;
V_40 = F_45 ( sizeof( struct V_39 ) , V_18 ) ;
if ( ! V_40 )
return - V_31 ;
type = F_63 ( V_51 -> V_57 . V_13 , & V_50 ) ;
V_52 = F_31 ( & V_50 , V_51 -> V_82 ) ;
if ( F_12 ( V_52 ) ) {
F_8 ( V_40 ) ;
return F_32 ( V_52 ) ;
}
V_40 -> V_52 = V_52 ;
V_40 -> V_61 = ! F_37 ( type ) ;
V_40 -> V_78 = F_56 ( type ) ;
V_51 -> V_56 = V_40 ;
return 0 ;
}
int F_64 ( struct V_13 * V_13 , struct V_38 * V_33 )
{
int V_37 ;
struct V_1 * V_10 ;
V_37 = F_38 ( V_13 , V_33 ) ;
if ( V_37 )
return V_37 ;
V_37 = 0 ;
F_65 (p, list, l_node) {
if ( V_10 -> V_19 )
continue;
if ( V_10 -> V_7 [ 0 ] == '.' ) {
if ( V_10 -> V_8 == 1 )
continue;
if ( V_10 -> V_8 == 2 && V_10 -> V_7 [ 1 ] == '.' )
continue;
}
V_37 = - V_83 ;
break;
}
return V_37 ;
}
void F_66 ( struct V_13 * V_84 , struct V_38 * V_33 )
{
struct V_1 * V_10 ;
F_67 ( & V_84 -> V_85 -> V_69 , V_86 ) ;
F_65 (p, list, l_node) {
struct V_13 * V_13 ;
if ( ! V_10 -> V_19 )
continue;
V_13 = F_11 ( V_10 -> V_7 , V_84 , V_10 -> V_8 ) ;
if ( F_12 ( V_13 ) ) {
F_68 ( L_1 ,
V_84 -> V_87 . V_7 , V_10 -> V_8 , V_10 -> V_7 ,
( int ) F_32 ( V_13 ) ) ;
continue;
}
F_69 ( V_84 -> V_85 , V_13 ) ;
F_14 ( V_13 ) ;
}
F_54 ( & V_84 -> V_85 -> V_69 ) ;
}
