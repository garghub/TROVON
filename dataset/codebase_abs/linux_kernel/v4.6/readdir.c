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
struct V_46 * V_48 ;
V_48 = F_22 () ;
if ( ! V_48 )
return - V_26 ;
F_23 ( V_48 -> V_49 , V_50 ) ;
V_47 = F_24 ( V_48 ) ;
V_32 = F_25 ( & V_45 -> V_51 -> V_52 ) ;
if ( ! V_32 ) {
while ( V_14 -> V_22 ) {
V_10 = V_14 -> V_22 ;
V_14 -> V_22 = V_10 -> V_21 ;
V_36 = F_26 ( V_10 -> V_7 , V_45 , V_10 -> V_8 ) ;
if ( ! F_27 ( V_36 ) ) {
V_10 -> V_19 = F_28 ( V_36 ) ;
F_29 ( V_36 ) ;
}
}
F_30 ( V_45 -> V_51 ) ;
}
F_31 ( V_47 ) ;
F_32 ( V_48 ) ;
return V_32 ;
}
static inline int F_33 ( struct V_53 * V_54 ,
struct V_13 * V_14 )
{
struct V_55 * V_56 ;
int V_32 ;
V_56 = F_34 ( V_54 , V_57 | V_58 ) ;
if ( F_27 ( V_56 ) )
return F_35 ( V_56 ) ;
V_14 -> V_22 = NULL ;
V_14 -> V_42 . V_59 = 0 ;
do {
V_14 -> V_43 = 0 ;
V_14 -> V_32 = 0 ;
V_32 = F_36 ( V_56 , & V_14 -> V_42 ) ;
if ( V_32 >= 0 )
V_32 = V_14 -> V_32 ;
} while ( ! V_32 && V_14 -> V_43 );
if ( ! V_32 && V_14 -> V_22 )
V_32 = F_21 ( V_54 -> V_36 , V_14 ) ;
F_37 ( V_56 ) ;
return V_32 ;
}
static void F_38 ( struct V_55 * V_55 )
{
struct V_34 * V_35 = V_55 -> V_60 ;
struct V_37 * V_38 = V_35 -> V_38 ;
struct V_36 * V_36 = V_55 -> V_61 . V_36 ;
enum V_62 type = V_62 ( V_36 ) ;
if ( V_38 && F_39 ( V_36 ) != V_38 -> V_63 ) {
F_17 ( V_35 , V_36 ) ;
V_35 -> V_38 = NULL ;
V_35 -> V_64 = NULL ;
}
F_18 ( ! V_35 -> V_65 && ! F_40 ( type ) ) ;
if ( V_35 -> V_65 && F_40 ( type ) )
V_35 -> V_65 = false ;
}
static int F_41 ( struct V_36 * V_36 , struct V_33 * V_28 )
{
int V_32 ;
struct V_53 V_54 ;
struct V_13 V_14 = {
. V_42 . V_66 = F_20 ,
. V_28 = V_28 ,
. V_6 = V_67 ,
. V_44 = false ,
} ;
int V_68 , V_69 ;
for ( V_68 = 0 ; V_68 != - 1 ; V_68 = V_69 ) {
V_69 = F_42 ( V_68 , V_36 , & V_54 ) ;
if ( V_69 != - 1 ) {
V_32 = F_33 ( & V_54 , & V_14 ) ;
if ( V_32 )
break;
} else {
F_43 ( & V_14 . V_31 , V_14 . V_28 ) ;
V_14 . V_44 = true ;
V_32 = F_33 ( & V_54 , & V_14 ) ;
F_44 ( & V_14 . V_31 ) ;
}
}
return V_32 ;
}
static void F_45 ( struct V_34 * V_35 , T_3 V_59 )
{
struct V_33 * V_10 ;
T_3 V_70 = 0 ;
F_46 (p, &od->cache->entries) {
if ( V_70 >= V_59 )
break;
V_70 ++ ;
}
V_35 -> V_64 = V_10 ;
}
static struct V_37 * F_47 ( struct V_36 * V_36 )
{
int V_71 ;
struct V_37 * V_38 ;
V_38 = V_37 ( V_36 ) ;
if ( V_38 && F_39 ( V_36 ) == V_38 -> V_63 ) {
V_38 -> V_39 ++ ;
return V_38 ;
}
F_19 ( V_36 , NULL ) ;
V_38 = F_48 ( sizeof( struct V_37 ) , V_18 ) ;
if ( ! V_38 )
return F_49 ( - V_26 ) ;
V_38 -> V_39 = 1 ;
F_16 ( & V_38 -> V_40 ) ;
V_71 = F_41 ( V_36 , & V_38 -> V_40 ) ;
if ( V_71 ) {
F_13 ( & V_38 -> V_40 ) ;
F_15 ( V_38 ) ;
return F_49 ( V_71 ) ;
}
V_38 -> V_63 = F_39 ( V_36 ) ;
F_19 ( V_36 , V_38 ) ;
return V_38 ;
}
static int F_50 ( struct V_55 * V_55 , struct V_41 * V_42 )
{
struct V_34 * V_35 = V_55 -> V_60 ;
struct V_36 * V_36 = V_55 -> V_61 . V_36 ;
struct V_1 * V_10 ;
if ( ! V_42 -> V_59 )
F_38 ( V_55 ) ;
if ( V_35 -> V_65 )
return F_36 ( V_35 -> V_56 , V_42 ) ;
if ( ! V_35 -> V_38 ) {
struct V_37 * V_38 ;
V_38 = F_47 ( V_36 ) ;
if ( F_27 ( V_38 ) )
return F_35 ( V_38 ) ;
V_35 -> V_38 = V_38 ;
F_45 ( V_35 , V_42 -> V_59 ) ;
}
while ( V_35 -> V_64 != & V_35 -> V_38 -> V_40 ) {
V_10 = F_51 ( V_35 -> V_64 , struct V_1 , V_27 ) ;
if ( ! V_10 -> V_19 )
if ( ! F_52 ( V_42 , V_10 -> V_7 , V_10 -> V_8 , V_10 -> V_15 , V_10 -> type ) )
break;
V_35 -> V_64 = V_10 -> V_27 . V_69 ;
V_42 -> V_59 ++ ;
}
return 0 ;
}
static T_3 F_53 ( struct V_55 * V_55 , T_3 V_30 , int V_72 )
{
T_3 V_71 ;
struct V_34 * V_35 = V_55 -> V_60 ;
F_54 ( F_55 ( V_55 ) ) ;
if ( ! V_55 -> V_73 )
F_38 ( V_55 ) ;
if ( V_35 -> V_65 ) {
V_71 = F_56 ( V_35 -> V_56 , V_30 , V_72 ) ;
V_55 -> V_73 = V_35 -> V_56 -> V_73 ;
} else {
V_71 = - V_74 ;
switch ( V_72 ) {
case V_75 :
V_30 += V_55 -> V_73 ;
break;
case V_76 :
break;
default:
goto V_77;
}
if ( V_30 < 0 )
goto V_77;
if ( V_30 != V_55 -> V_73 ) {
V_55 -> V_73 = V_30 ;
if ( V_35 -> V_38 )
F_45 ( V_35 , V_30 ) ;
}
V_71 = V_30 ;
}
V_77:
F_30 ( F_55 ( V_55 ) ) ;
return V_71 ;
}
static int F_57 ( struct V_55 * V_55 , T_3 V_78 , T_3 V_79 ,
int V_80 )
{
struct V_34 * V_35 = V_55 -> V_60 ;
struct V_36 * V_36 = V_55 -> V_61 . V_36 ;
struct V_55 * V_56 = V_35 -> V_56 ;
if ( ! V_35 -> V_81 && F_58 ( V_62 ( V_36 ) ) ) {
struct V_82 * V_82 = F_55 ( V_55 ) ;
V_56 = F_59 ( V_35 -> V_83 ) ;
if ( ! V_56 ) {
struct V_53 V_84 ;
F_60 ( V_36 , & V_84 ) ;
V_56 = F_34 ( & V_84 , V_57 ) ;
F_61 () ;
F_54 ( V_82 ) ;
if ( ! V_35 -> V_83 ) {
if ( F_27 ( V_56 ) ) {
F_30 ( V_82 ) ;
return F_35 ( V_56 ) ;
}
V_35 -> V_83 = V_56 ;
} else {
if ( ! F_27 ( V_56 ) )
F_37 ( V_56 ) ;
V_56 = V_35 -> V_83 ;
}
F_30 ( V_82 ) ;
}
}
return F_62 ( V_56 , V_78 , V_79 , V_80 ) ;
}
static int F_63 ( struct V_82 * V_82 , struct V_55 * V_55 )
{
struct V_34 * V_35 = V_55 -> V_60 ;
if ( V_35 -> V_38 ) {
F_54 ( V_82 ) ;
F_17 ( V_35 , V_55 -> V_61 . V_36 ) ;
F_30 ( V_82 ) ;
}
F_37 ( V_35 -> V_56 ) ;
if ( V_35 -> V_83 )
F_37 ( V_35 -> V_83 ) ;
F_15 ( V_35 ) ;
return 0 ;
}
static int F_64 ( struct V_82 * V_82 , struct V_55 * V_55 )
{
struct V_53 V_54 ;
struct V_55 * V_56 ;
struct V_34 * V_35 ;
enum V_62 type ;
V_35 = F_48 ( sizeof( struct V_34 ) , V_18 ) ;
if ( ! V_35 )
return - V_26 ;
type = F_65 ( V_55 -> V_61 . V_36 , & V_54 ) ;
V_56 = F_34 ( & V_54 , V_55 -> V_85 ) ;
if ( F_27 ( V_56 ) ) {
F_15 ( V_35 ) ;
return F_35 ( V_56 ) ;
}
V_35 -> V_56 = V_56 ;
V_35 -> V_65 = ! F_40 ( type ) ;
V_35 -> V_81 = F_58 ( type ) ;
V_55 -> V_60 = V_35 ;
return 0 ;
}
int F_66 ( struct V_36 * V_36 , struct V_33 * V_28 )
{
int V_32 ;
struct V_1 * V_10 ;
V_32 = F_41 ( V_36 , V_28 ) ;
if ( V_32 )
return V_32 ;
V_32 = 0 ;
F_67 (p, list, l_node) {
if ( V_10 -> V_19 )
continue;
if ( V_10 -> V_7 [ 0 ] == '.' ) {
if ( V_10 -> V_8 == 1 )
continue;
if ( V_10 -> V_8 == 2 && V_10 -> V_7 [ 1 ] == '.' )
continue;
}
V_32 = - V_86 ;
break;
}
return V_32 ;
}
void F_68 ( struct V_36 * V_87 , struct V_33 * V_28 )
{
struct V_1 * V_10 ;
F_69 ( V_87 -> V_51 , V_88 ) ;
F_67 (p, list, l_node) {
struct V_36 * V_36 ;
if ( ! V_10 -> V_19 )
continue;
V_36 = F_26 ( V_10 -> V_7 , V_87 , V_10 -> V_8 ) ;
if ( F_27 ( V_36 ) ) {
F_70 ( L_1 ,
V_87 -> V_89 . V_7 , V_10 -> V_8 , V_10 -> V_7 ,
( int ) F_35 ( V_36 ) ) ;
continue;
}
if ( V_36 -> V_51 )
F_71 ( V_87 -> V_51 , V_36 ) ;
F_29 ( V_36 ) ;
}
F_30 ( V_87 -> V_51 ) ;
}
static int F_72 ( struct V_41 * V_42 , const char * V_7 ,
int V_29 , T_3 V_30 , T_1 V_15 ,
unsigned int V_16 )
{
struct V_13 * V_14 =
F_2 ( V_42 , struct V_13 , V_42 ) ;
if ( ! strncmp ( V_7 , L_2 , V_29 ) || ! strncmp ( V_7 , L_3 , V_29 ) )
return 0 ;
if ( V_16 != V_90 )
V_14 -> V_91 = true ;
return 0 ;
}
int F_73 ( struct V_53 * V_54 )
{
int V_32 ;
struct V_13 V_14 = {
. V_42 . V_66 = F_72 ,
. V_91 = false ,
} ;
V_32 = F_33 ( V_54 , & V_14 ) ;
if ( V_32 )
return V_32 ;
return V_14 . V_91 ;
}
