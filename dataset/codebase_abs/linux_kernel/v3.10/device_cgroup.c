static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_1 * F_3 ( struct V_5 * V_5 )
{
return F_1 ( V_2 ( V_5 , V_6 ) ) ;
}
static inline struct V_1 * F_4 ( struct V_7 * V_8 )
{
return F_1 ( F_5 ( V_8 , V_6 ) ) ;
}
static int F_6 ( struct V_5 * V_9 ,
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_7 ( V_11 ) ;
if ( V_12 != V_8 && ! F_8 ( V_13 ) )
return - V_14 ;
return 0 ;
}
static int F_9 ( struct V_15 * V_16 , struct V_15 * V_17 )
{
struct V_18 * V_19 , * V_20 , * V_21 ;
F_10 ( & V_22 ) ;
F_11 (ex, orig, list) {
V_21 = F_12 ( V_19 , sizeof( * V_19 ) , V_23 ) ;
if ( ! V_21 )
goto V_24;
F_13 ( & V_21 -> V_25 , V_16 ) ;
}
return 0 ;
V_24:
F_14 (ex, tmp, dest, list) {
F_15 ( & V_19 -> V_25 ) ;
F_16 ( V_19 ) ;
}
return - V_26 ;
}
static int F_17 ( struct V_1 * V_1 ,
struct V_18 * V_19 )
{
struct V_18 * V_27 , * V_28 ;
F_10 ( & V_22 ) ;
V_27 = F_12 ( V_19 , sizeof( * V_19 ) , V_23 ) ;
if ( ! V_27 )
return - V_26 ;
F_11 (walk, &dev_cgroup->exceptions, list) {
if ( V_28 -> type != V_19 -> type )
continue;
if ( V_28 -> V_29 != V_19 -> V_29 )
continue;
if ( V_28 -> V_30 != V_19 -> V_30 )
continue;
V_28 -> V_31 |= V_19 -> V_31 ;
F_16 ( V_27 ) ;
V_27 = NULL ;
}
if ( V_27 != NULL )
F_18 ( & V_27 -> V_25 , & V_1 -> V_32 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_1 ,
struct V_18 * V_19 )
{
struct V_18 * V_28 , * V_20 ;
F_10 ( & V_22 ) ;
F_14 (walk, tmp, &dev_cgroup->exceptions, list) {
if ( V_28 -> type != V_19 -> type )
continue;
if ( V_28 -> V_29 != V_19 -> V_29 )
continue;
if ( V_28 -> V_30 != V_19 -> V_30 )
continue;
V_28 -> V_31 &= ~ V_19 -> V_31 ;
if ( ! V_28 -> V_31 ) {
F_20 ( & V_28 -> V_25 ) ;
F_21 ( V_28 , V_33 ) ;
}
}
}
static void F_22 ( struct V_1 * V_1 )
{
struct V_18 * V_19 , * V_20 ;
F_14 (ex, tmp, &dev_cgroup->exceptions, list) {
F_20 ( & V_19 -> V_25 ) ;
F_21 ( V_19 , V_33 ) ;
}
}
static void F_23 ( struct V_1 * V_1 )
{
F_10 ( & V_22 ) ;
F_22 ( V_1 ) ;
}
static inline bool F_24 ( const struct V_1 * V_34 )
{
return ( V_34 -> V_35 != V_36 ) ;
}
static int F_25 ( struct V_5 * V_5 )
{
struct V_1 * V_1 , * V_37 = NULL ;
int V_38 = 0 ;
F_26 ( & V_22 ) ;
V_1 = F_3 ( V_5 ) ;
if ( V_5 -> V_39 )
V_37 = F_3 ( V_5 -> V_39 ) ;
if ( V_37 == NULL )
V_1 -> V_35 = V_40 ;
else {
V_38 = F_9 ( & V_1 -> V_32 ,
& V_37 -> V_32 ) ;
if ( ! V_38 )
V_1 -> V_35 = V_37 -> V_35 ;
}
F_27 ( & V_22 ) ;
return V_38 ;
}
static void F_28 ( struct V_5 * V_5 )
{
struct V_1 * V_1 = F_3 ( V_5 ) ;
F_26 ( & V_22 ) ;
V_1 -> V_35 = V_36 ;
F_27 ( & V_22 ) ;
}
static struct V_2 * F_29 ( struct V_5 * V_5 )
{
struct V_1 * V_1 ;
V_1 = F_30 ( sizeof( * V_1 ) , V_23 ) ;
if ( ! V_1 )
return F_31 ( - V_26 ) ;
F_32 ( & V_1 -> V_32 ) ;
F_32 ( & V_1 -> V_41 ) ;
V_1 -> V_35 = V_36 ;
return & V_1 -> V_4 ;
}
static void F_33 ( struct V_5 * V_5 )
{
struct V_1 * V_1 ;
V_1 = F_3 ( V_5 ) ;
F_22 ( V_1 ) ;
F_16 ( V_1 ) ;
}
static void F_34 ( char * V_42 , short V_31 )
{
int V_43 = 0 ;
memset ( V_42 , 0 , V_44 ) ;
if ( V_31 & V_45 )
V_42 [ V_43 ++ ] = 'r' ;
if ( V_31 & V_46 )
V_42 [ V_43 ++ ] = 'w' ;
if ( V_31 & V_47 )
V_42 [ V_43 ++ ] = 'm' ;
}
static char F_35 ( short type )
{
if ( type == V_48 )
return 'a' ;
if ( type == V_49 )
return 'c' ;
if ( type == V_50 )
return 'b' ;
return 'X' ;
}
static void F_36 ( char * V_51 , unsigned V_52 )
{
if ( V_52 == ~ 0 )
strcpy ( V_51 , L_1 ) ;
else
sprintf ( V_51 , L_2 , V_52 ) ;
}
static int F_37 ( struct V_5 * V_5 , struct V_53 * V_54 ,
struct V_55 * V_52 )
{
struct V_1 * V_56 = F_3 ( V_5 ) ;
struct V_18 * V_19 ;
char V_57 [ V_58 ] , V_59 [ V_58 ] , V_42 [ V_44 ] ;
F_38 () ;
if ( V_56 -> V_35 == V_40 ) {
F_34 ( V_42 , V_60 ) ;
F_36 ( V_57 , ~ 0 ) ;
F_36 ( V_59 , ~ 0 ) ;
F_39 ( V_52 , L_3 , F_35 ( V_48 ) ,
V_57 , V_59 , V_42 ) ;
} else {
F_40 (ex, &devcgroup->exceptions, list) {
F_34 ( V_42 , V_19 -> V_31 ) ;
F_36 ( V_57 , V_19 -> V_29 ) ;
F_36 ( V_59 , V_19 -> V_30 ) ;
F_39 ( V_52 , L_3 , F_35 ( V_19 -> type ) ,
V_57 , V_59 , V_42 ) ;
}
}
F_41 () ;
return 0 ;
}
static bool F_42 ( struct V_1 * V_1 ,
struct V_18 * V_61 ,
enum V_62 V_35 )
{
struct V_18 * V_19 ;
bool V_63 = false ;
F_43 ( F_44 () ||
F_45 ( & V_22 ) ,
L_4 ) ;
F_40 (ex, &dev_cgroup->exceptions, list) {
if ( ( V_61 -> type & V_50 ) && ! ( V_19 -> type & V_50 ) )
continue;
if ( ( V_61 -> type & V_49 ) && ! ( V_19 -> type & V_49 ) )
continue;
if ( V_19 -> V_29 != ~ 0 && V_19 -> V_29 != V_61 -> V_29 )
continue;
if ( V_19 -> V_30 != ~ 0 && V_19 -> V_30 != V_61 -> V_30 )
continue;
if ( V_61 -> V_31 & ( ~ V_19 -> V_31 ) )
continue;
V_63 = true ;
break;
}
if ( V_1 -> V_35 == V_40 ) {
if ( V_35 == V_40 ) {
return true ;
} else {
if ( V_63 )
return false ;
return true ;
}
} else {
if ( V_63 )
return true ;
else
return false ;
}
return false ;
}
static int F_46 ( struct V_1 * V_64 ,
struct V_18 * V_19 )
{
struct V_5 * V_65 = V_64 -> V_4 . V_5 -> V_39 ;
struct V_1 * V_39 ;
if ( ! V_65 )
return 1 ;
V_39 = F_3 ( V_65 ) ;
return F_42 ( V_39 , V_19 , V_64 -> V_35 ) ;
}
static inline int F_47 ( struct V_1 * V_39 )
{
if ( ! V_39 )
return 1 ;
return V_39 -> V_35 == V_40 ;
}
static void F_48 ( struct V_1 * V_34 )
{
struct V_18 * V_19 ;
struct V_15 * V_66 , * V_20 ;
F_49 (this, tmp, &devcg->exceptions) {
V_19 = F_2 ( V_66 , struct V_18 , V_25 ) ;
if ( ! F_46 ( V_34 , V_19 ) )
F_19 ( V_34 , V_19 ) ;
}
}
static void F_50 ( struct V_5 * V_67 , struct V_15 * V_68 )
{
struct V_5 * V_69 ;
struct V_1 * V_34 ;
F_10 ( & V_22 ) ;
F_38 () ;
F_51 (pos, root) {
V_34 = F_3 ( V_69 ) ;
if ( F_24 ( V_34 ) )
F_13 ( & V_34 -> V_41 , V_68 ) ;
}
F_41 () ;
}
static int F_52 ( struct V_1 * V_70 ,
struct V_18 * V_19 )
{
struct V_5 * V_67 = V_70 -> V_4 . V_5 ;
struct V_1 * V_34 , * V_39 , * V_20 ;
int V_71 = 0 ;
F_53 ( V_72 ) ;
F_50 ( V_67 , & V_72 ) ;
F_14 (devcg, tmp, &pending, propagate_pending) {
V_39 = F_3 ( V_34 -> V_4 . V_5 -> V_39 ) ;
if ( V_70 -> V_35 == V_40 &&
V_34 -> V_35 == V_40 ) {
V_71 = F_17 ( V_34 , V_19 ) ;
if ( V_71 )
break;
} else {
F_19 ( V_34 , V_19 ) ;
}
F_48 ( V_34 ) ;
F_54 ( & V_34 -> V_41 ) ;
}
return V_71 ;
}
static inline bool F_55 ( struct V_1 * V_56 )
{
struct V_5 * V_73 = V_56 -> V_4 . V_5 ;
return ! F_56 ( & V_73 -> V_74 ) ;
}
static int F_57 ( struct V_1 * V_56 ,
int V_75 , const char * V_76 )
{
const char * V_77 ;
char V_78 [ 12 ] ;
int V_79 , V_71 = 0 ;
struct V_18 V_19 ;
struct V_5 * V_80 = V_56 -> V_4 . V_5 ;
struct V_1 * V_39 = NULL ;
if ( ! F_8 ( V_13 ) )
return - V_14 ;
if ( V_80 -> V_39 )
V_39 = F_3 ( V_80 -> V_39 ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_77 = V_76 ;
switch ( * V_77 ) {
case 'a' :
switch ( V_75 ) {
case V_81 :
if ( F_55 ( V_56 ) )
return - V_82 ;
if ( ! F_47 ( V_39 ) )
return - V_14 ;
F_23 ( V_56 ) ;
V_56 -> V_35 = V_40 ;
if ( ! V_39 )
break;
V_71 = F_9 ( & V_56 -> V_32 ,
& V_39 -> V_32 ) ;
if ( V_71 )
return V_71 ;
break;
case V_83 :
if ( F_55 ( V_56 ) )
return - V_82 ;
F_23 ( V_56 ) ;
V_56 -> V_35 = V_84 ;
break;
default:
return - V_82 ;
}
return 0 ;
case 'b' :
V_19 . type = V_50 ;
break;
case 'c' :
V_19 . type = V_49 ;
break;
default:
return - V_82 ;
}
V_77 ++ ;
if ( ! isspace ( * V_77 ) )
return - V_82 ;
V_77 ++ ;
if ( * V_77 == '*' ) {
V_19 . V_29 = ~ 0 ;
V_77 ++ ;
} else if ( isdigit ( * V_77 ) ) {
memset ( V_78 , 0 , sizeof( V_78 ) ) ;
for ( V_79 = 0 ; V_79 < sizeof( V_78 ) - 1 ; V_79 ++ ) {
V_78 [ V_79 ] = * V_77 ;
V_77 ++ ;
if ( ! isdigit ( * V_77 ) )
break;
}
V_71 = F_58 ( V_78 , 10 , & V_19 . V_29 ) ;
if ( V_71 )
return - V_82 ;
} else {
return - V_82 ;
}
if ( * V_77 != ':' )
return - V_82 ;
V_77 ++ ;
if ( * V_77 == '*' ) {
V_19 . V_30 = ~ 0 ;
V_77 ++ ;
} else if ( isdigit ( * V_77 ) ) {
memset ( V_78 , 0 , sizeof( V_78 ) ) ;
for ( V_79 = 0 ; V_79 < sizeof( V_78 ) - 1 ; V_79 ++ ) {
V_78 [ V_79 ] = * V_77 ;
V_77 ++ ;
if ( ! isdigit ( * V_77 ) )
break;
}
V_71 = F_58 ( V_78 , 10 , & V_19 . V_30 ) ;
if ( V_71 )
return - V_82 ;
} else {
return - V_82 ;
}
if ( ! isspace ( * V_77 ) )
return - V_82 ;
for ( V_77 ++ , V_79 = 0 ; V_79 < 3 ; V_79 ++ , V_77 ++ ) {
switch ( * V_77 ) {
case 'r' :
V_19 . V_31 |= V_45 ;
break;
case 'w' :
V_19 . V_31 |= V_46 ;
break;
case 'm' :
V_19 . V_31 |= V_47 ;
break;
case '\n' :
case '\0' :
V_79 = 3 ;
break;
default:
return - V_82 ;
}
}
switch ( V_75 ) {
case V_81 :
if ( ! F_46 ( V_56 , & V_19 ) )
return - V_14 ;
if ( V_56 -> V_35 == V_40 ) {
F_19 ( V_56 , & V_19 ) ;
return 0 ;
}
V_71 = F_17 ( V_56 , & V_19 ) ;
break;
case V_83 :
if ( V_56 -> V_35 == V_84 )
F_19 ( V_56 , & V_19 ) ;
else
V_71 = F_17 ( V_56 , & V_19 ) ;
if ( V_71 )
break;
V_71 = F_52 ( V_56 , & V_19 ) ;
break;
default:
V_71 = - V_82 ;
}
return V_71 ;
}
static int F_59 ( struct V_5 * V_73 , struct V_53 * V_54 ,
const char * V_76 )
{
int V_85 ;
F_26 ( & V_22 ) ;
V_85 = F_57 ( F_3 ( V_73 ) ,
V_54 -> V_86 , V_76 ) ;
F_27 ( & V_22 ) ;
return V_85 ;
}
static int F_60 ( short type , T_1 V_29 , T_1 V_30 ,
short V_31 )
{
struct V_1 * V_1 ;
struct V_18 V_19 ;
int V_71 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . type = type ;
V_19 . V_29 = V_29 ;
V_19 . V_30 = V_30 ;
V_19 . V_31 = V_31 ;
F_38 () ;
V_1 = F_4 ( V_12 ) ;
V_71 = F_42 ( V_1 , & V_19 , V_1 -> V_35 ) ;
F_41 () ;
if ( ! V_71 )
return - V_14 ;
return 0 ;
}
int F_61 ( struct V_87 * V_87 , int V_88 )
{
short type , V_31 = 0 ;
if ( F_62 ( V_87 -> V_89 ) )
type = V_50 ;
if ( F_63 ( V_87 -> V_89 ) )
type = V_49 ;
if ( V_88 & V_90 )
V_31 |= V_46 ;
if ( V_88 & V_91 )
V_31 |= V_45 ;
return F_60 ( type , F_64 ( V_87 ) , F_65 ( V_87 ) ,
V_31 ) ;
}
int F_66 ( int V_92 , T_2 V_93 )
{
short type ;
if ( ! F_62 ( V_92 ) && ! F_63 ( V_92 ) )
return 0 ;
if ( F_62 ( V_92 ) )
type = V_50 ;
else
type = V_49 ;
return F_60 ( type , F_67 ( V_93 ) , F_68 ( V_93 ) ,
V_47 ) ;
}
