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
V_10 -> V_21 = V_14 -> V_22 ;
V_14 -> V_22 = V_10 ;
}
return V_10 ;
}
static int F_7 ( struct V_13 * V_14 ,
const char * V_7 , int V_8 , T_1 V_15 ,
unsigned int V_16 )
{
struct V_2 * * V_23 = & V_14 -> V_6 . V_2 ;
struct V_2 * V_24 = NULL ;
struct V_1 * V_10 ;
while ( * V_23 ) {
int V_9 ;
struct V_1 * V_25 ;
V_24 = * V_23 ;
V_25 = F_1 ( * V_23 ) ;
V_9 = strncmp ( V_7 , V_25 -> V_7 , V_8 ) ;
if ( V_9 > 0 )
V_23 = & V_25 -> V_4 . V_11 ;
else if ( V_9 < 0 || V_8 < V_25 -> V_8 )
V_23 = & V_25 -> V_4 . V_12 ;
else
return 0 ;
}
V_10 = F_4 ( V_14 , V_7 , V_8 , V_15 , V_16 ) ;
if ( V_10 == NULL )
return - V_26 ;
F_8 ( & V_10 -> V_27 , V_14 -> V_28 ) ;
F_9 ( & V_10 -> V_4 , V_24 , V_23 ) ;
F_10 ( & V_10 -> V_4 , & V_14 -> V_6 ) ;
return 0 ;
}
static int F_11 ( struct V_13 * V_14 ,
const char * V_7 , int V_29 ,
T_3 V_30 , T_1 V_15 , unsigned int V_16 )
{
struct V_1 * V_10 ;
V_10 = F_3 ( & V_14 -> V_6 , V_7 , V_29 ) ;
if ( V_10 ) {
F_12 ( & V_10 -> V_27 , & V_14 -> V_31 ) ;
} else {
V_10 = F_4 ( V_14 , V_7 , V_29 , V_15 , V_16 ) ;
if ( V_10 == NULL )
V_14 -> V_32 = - V_26 ;
else
F_8 ( & V_10 -> V_27 , & V_14 -> V_31 ) ;
}
return V_14 -> V_32 ;
}
void F_13 ( struct V_33 * V_28 )
{
struct V_1 * V_10 ;
struct V_1 * V_3 ;
F_14 (p, n, list, l_node)
F_15 ( V_10 ) ;
F_16 ( V_28 ) ;
}
static void F_17 ( struct V_34 * V_35 , struct V_36 * V_36 )
{
struct V_37 * V_38 = V_35 -> V_38 ;
F_18 ( V_38 -> V_39 <= 0 ) ;
V_38 -> V_39 -- ;
if ( ! V_38 -> V_39 ) {
if ( V_37 ( V_36 ) == V_38 )
F_19 ( V_36 , NULL ) ;
F_13 ( & V_38 -> V_40 ) ;
F_15 ( V_38 ) ;
}
}
static int F_20 ( struct V_41 * V_42 , const char * V_7 ,
int V_29 , T_3 V_30 , T_1 V_15 ,
unsigned int V_16 )
{
struct V_13 * V_14 =
F_2 ( V_42 , struct V_13 , V_42 ) ;
V_14 -> V_43 ++ ;
if ( ! V_14 -> V_44 )
return F_7 ( V_14 , V_7 , V_29 , V_15 , V_16 ) ;
else
return F_11 ( V_14 , V_7 , V_29 , V_30 , V_15 , V_16 ) ;
}
static int F_21 ( struct V_36 * V_45 , struct V_13 * V_14 )
{
int V_32 ;
struct V_1 * V_10 ;
struct V_36 * V_36 ;
const struct V_46 * V_47 ;
V_47 = F_22 ( V_14 -> V_36 -> V_48 ) ;
V_32 = F_23 ( & V_45 -> V_49 -> V_50 ) ;
if ( ! V_32 ) {
while ( V_14 -> V_22 ) {
V_10 = V_14 -> V_22 ;
V_14 -> V_22 = V_10 -> V_21 ;
V_36 = F_24 ( V_10 -> V_7 , V_45 , V_10 -> V_8 ) ;
if ( ! F_25 ( V_36 ) ) {
V_10 -> V_19 = F_26 ( V_36 ) ;
F_27 ( V_36 ) ;
}
}
F_28 ( V_45 -> V_49 ) ;
}
F_29 ( V_47 ) ;
return V_32 ;
}
static inline int F_30 ( struct V_51 * V_52 ,
struct V_13 * V_14 )
{
struct V_53 * V_54 ;
int V_32 ;
V_54 = F_31 ( V_52 , V_55 | V_56 ) ;
if ( F_25 ( V_54 ) )
return F_32 ( V_54 ) ;
V_14 -> V_22 = NULL ;
V_14 -> V_42 . V_57 = 0 ;
do {
V_14 -> V_43 = 0 ;
V_14 -> V_32 = 0 ;
V_32 = F_33 ( V_54 , & V_14 -> V_42 ) ;
if ( V_32 >= 0 )
V_32 = V_14 -> V_32 ;
} while ( ! V_32 && V_14 -> V_43 );
if ( ! V_32 && V_14 -> V_22 )
V_32 = F_21 ( V_52 -> V_36 , V_14 ) ;
F_34 ( V_54 ) ;
return V_32 ;
}
static void F_35 ( struct V_53 * V_53 )
{
struct V_34 * V_35 = V_53 -> V_58 ;
struct V_37 * V_38 = V_35 -> V_38 ;
struct V_36 * V_36 = V_53 -> V_59 . V_36 ;
enum V_60 type = V_60 ( V_36 ) ;
if ( V_38 && F_36 ( V_36 ) != V_38 -> V_61 ) {
F_17 ( V_35 , V_36 ) ;
V_35 -> V_38 = NULL ;
V_35 -> V_62 = NULL ;
}
F_18 ( ! V_35 -> V_63 && ! F_37 ( type ) ) ;
if ( V_35 -> V_63 && F_37 ( type ) )
V_35 -> V_63 = false ;
}
static int F_38 ( struct V_36 * V_36 , struct V_33 * V_28 )
{
int V_32 ;
struct V_51 V_52 ;
struct V_13 V_14 = {
. V_42 . V_64 = F_20 ,
. V_36 = V_36 ,
. V_28 = V_28 ,
. V_6 = V_65 ,
. V_44 = false ,
} ;
int V_66 , V_67 ;
for ( V_66 = 0 ; V_66 != - 1 ; V_66 = V_67 ) {
V_67 = F_39 ( V_66 , V_36 , & V_52 ) ;
if ( V_67 != - 1 ) {
V_32 = F_30 ( & V_52 , & V_14 ) ;
if ( V_32 )
break;
} else {
F_40 ( & V_14 . V_31 , V_14 . V_28 ) ;
V_14 . V_44 = true ;
V_32 = F_30 ( & V_52 , & V_14 ) ;
F_41 ( & V_14 . V_31 ) ;
}
}
return V_32 ;
}
static void F_42 ( struct V_34 * V_35 , T_3 V_57 )
{
struct V_33 * V_10 ;
T_3 V_68 = 0 ;
F_43 (p, &od->cache->entries) {
if ( V_68 >= V_57 )
break;
V_68 ++ ;
}
V_35 -> V_62 = V_10 ;
}
static struct V_37 * F_44 ( struct V_36 * V_36 )
{
int V_69 ;
struct V_37 * V_38 ;
V_38 = V_37 ( V_36 ) ;
if ( V_38 && F_36 ( V_36 ) == V_38 -> V_61 ) {
V_38 -> V_39 ++ ;
return V_38 ;
}
F_19 ( V_36 , NULL ) ;
V_38 = F_45 ( sizeof( struct V_37 ) , V_18 ) ;
if ( ! V_38 )
return F_46 ( - V_26 ) ;
V_38 -> V_39 = 1 ;
F_16 ( & V_38 -> V_40 ) ;
V_69 = F_38 ( V_36 , & V_38 -> V_40 ) ;
if ( V_69 ) {
F_13 ( & V_38 -> V_40 ) ;
F_15 ( V_38 ) ;
return F_46 ( V_69 ) ;
}
V_38 -> V_61 = F_36 ( V_36 ) ;
F_19 ( V_36 , V_38 ) ;
return V_38 ;
}
static int F_47 ( struct V_53 * V_53 , struct V_41 * V_42 )
{
struct V_34 * V_35 = V_53 -> V_58 ;
struct V_36 * V_36 = V_53 -> V_59 . V_36 ;
struct V_1 * V_10 ;
if ( ! V_42 -> V_57 )
F_35 ( V_53 ) ;
if ( V_35 -> V_63 )
return F_33 ( V_35 -> V_54 , V_42 ) ;
if ( ! V_35 -> V_38 ) {
struct V_37 * V_38 ;
V_38 = F_44 ( V_36 ) ;
if ( F_25 ( V_38 ) )
return F_32 ( V_38 ) ;
V_35 -> V_38 = V_38 ;
F_42 ( V_35 , V_42 -> V_57 ) ;
}
while ( V_35 -> V_62 != & V_35 -> V_38 -> V_40 ) {
V_10 = F_48 ( V_35 -> V_62 , struct V_1 , V_27 ) ;
if ( ! V_10 -> V_19 )
if ( ! F_49 ( V_42 , V_10 -> V_7 , V_10 -> V_8 , V_10 -> V_15 , V_10 -> type ) )
break;
V_35 -> V_62 = V_10 -> V_27 . V_67 ;
V_42 -> V_57 ++ ;
}
return 0 ;
}
static T_3 F_50 ( struct V_53 * V_53 , T_3 V_30 , int V_70 )
{
T_3 V_69 ;
struct V_34 * V_35 = V_53 -> V_58 ;
F_51 ( F_52 ( V_53 ) ) ;
if ( ! V_53 -> V_71 )
F_35 ( V_53 ) ;
if ( V_35 -> V_63 ) {
V_69 = F_53 ( V_35 -> V_54 , V_30 , V_70 ) ;
V_53 -> V_71 = V_35 -> V_54 -> V_71 ;
} else {
V_69 = - V_72 ;
switch ( V_70 ) {
case V_73 :
V_30 += V_53 -> V_71 ;
break;
case V_74 :
break;
default:
goto V_75;
}
if ( V_30 < 0 )
goto V_75;
if ( V_30 != V_53 -> V_71 ) {
V_53 -> V_71 = V_30 ;
if ( V_35 -> V_38 )
F_42 ( V_35 , V_30 ) ;
}
V_69 = V_30 ;
}
V_75:
F_28 ( F_52 ( V_53 ) ) ;
return V_69 ;
}
static int F_54 ( struct V_53 * V_53 , T_3 V_76 , T_3 V_77 ,
int V_78 )
{
struct V_34 * V_35 = V_53 -> V_58 ;
struct V_36 * V_36 = V_53 -> V_59 . V_36 ;
struct V_53 * V_54 = V_35 -> V_54 ;
if ( ! V_35 -> V_79 && F_55 ( V_60 ( V_36 ) ) ) {
struct V_80 * V_80 = F_52 ( V_53 ) ;
V_54 = F_56 ( V_35 -> V_81 ) ;
if ( ! V_54 ) {
struct V_51 V_82 ;
F_57 ( V_36 , & V_82 ) ;
V_54 = F_31 ( & V_82 , V_55 ) ;
F_58 () ;
F_51 ( V_80 ) ;
if ( ! V_35 -> V_81 ) {
if ( F_25 ( V_54 ) ) {
F_28 ( V_80 ) ;
return F_32 ( V_54 ) ;
}
V_35 -> V_81 = V_54 ;
} else {
if ( ! F_25 ( V_54 ) )
F_34 ( V_54 ) ;
V_54 = V_35 -> V_81 ;
}
F_28 ( V_80 ) ;
}
}
return F_59 ( V_54 , V_76 , V_77 , V_78 ) ;
}
static int F_60 ( struct V_80 * V_80 , struct V_53 * V_53 )
{
struct V_34 * V_35 = V_53 -> V_58 ;
if ( V_35 -> V_38 ) {
F_51 ( V_80 ) ;
F_17 ( V_35 , V_53 -> V_59 . V_36 ) ;
F_28 ( V_80 ) ;
}
F_34 ( V_35 -> V_54 ) ;
if ( V_35 -> V_81 )
F_34 ( V_35 -> V_81 ) ;
F_15 ( V_35 ) ;
return 0 ;
}
static int F_61 ( struct V_80 * V_80 , struct V_53 * V_53 )
{
struct V_51 V_52 ;
struct V_53 * V_54 ;
struct V_34 * V_35 ;
enum V_60 type ;
V_35 = F_45 ( sizeof( struct V_34 ) , V_18 ) ;
if ( ! V_35 )
return - V_26 ;
type = F_62 ( V_53 -> V_59 . V_36 , & V_52 ) ;
V_54 = F_31 ( & V_52 , V_53 -> V_83 ) ;
if ( F_25 ( V_54 ) ) {
F_15 ( V_35 ) ;
return F_32 ( V_54 ) ;
}
V_35 -> V_54 = V_54 ;
V_35 -> V_63 = ! F_37 ( type ) ;
V_35 -> V_79 = F_55 ( type ) ;
V_53 -> V_58 = V_35 ;
return 0 ;
}
int F_63 ( struct V_36 * V_36 , struct V_33 * V_28 )
{
int V_32 ;
struct V_1 * V_10 ;
V_32 = F_38 ( V_36 , V_28 ) ;
if ( V_32 )
return V_32 ;
V_32 = 0 ;
F_64 (p, list, l_node) {
if ( V_10 -> V_19 )
continue;
if ( V_10 -> V_7 [ 0 ] == '.' ) {
if ( V_10 -> V_8 == 1 )
continue;
if ( V_10 -> V_8 == 2 && V_10 -> V_7 [ 1 ] == '.' )
continue;
}
V_32 = - V_84 ;
break;
}
return V_32 ;
}
void F_65 ( struct V_36 * V_85 , struct V_33 * V_28 )
{
struct V_1 * V_10 ;
F_66 ( V_85 -> V_49 , V_86 ) ;
F_64 (p, list, l_node) {
struct V_36 * V_36 ;
if ( ! V_10 -> V_19 )
continue;
V_36 = F_24 ( V_10 -> V_7 , V_85 , V_10 -> V_8 ) ;
if ( F_25 ( V_36 ) ) {
F_67 ( L_1 ,
V_85 -> V_87 . V_7 , V_10 -> V_8 , V_10 -> V_7 ,
( int ) F_32 ( V_36 ) ) ;
continue;
}
if ( V_36 -> V_49 )
F_68 ( V_85 -> V_49 , V_36 ) ;
F_27 ( V_36 ) ;
}
F_28 ( V_85 -> V_49 ) ;
}
static int F_69 ( struct V_41 * V_42 , const char * V_7 ,
int V_29 , T_3 V_30 , T_1 V_15 ,
unsigned int V_16 )
{
struct V_13 * V_14 =
F_2 ( V_42 , struct V_13 , V_42 ) ;
if ( ! strncmp ( V_7 , L_2 , V_29 ) || ! strncmp ( V_7 , L_3 , V_29 ) )
return 0 ;
if ( V_16 != V_88 )
V_14 -> V_89 = true ;
return 0 ;
}
int F_70 ( struct V_51 * V_52 )
{
int V_32 ;
struct V_13 V_14 = {
. V_42 . V_64 = F_69 ,
. V_89 = false ,
} ;
V_32 = F_30 ( V_52 , & V_14 ) ;
if ( V_32 )
return V_32 ;
return V_14 . V_89 ;
}
