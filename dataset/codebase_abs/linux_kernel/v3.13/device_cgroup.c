static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( V_3 , struct V_1 , V_4 ) : NULL ;
}
static inline struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_1 ( F_4 ( V_6 , V_7 ) ) ;
}
static int F_5 ( struct V_8 * V_9 , struct V_8 * V_10 )
{
struct V_11 * V_12 , * V_13 , * V_14 ;
F_6 ( & V_15 ) ;
F_7 (ex, orig, list) {
V_14 = F_8 ( V_12 , sizeof( * V_12 ) , V_16 ) ;
if ( ! V_14 )
goto V_17;
F_9 ( & V_14 -> V_18 , V_9 ) ;
}
return 0 ;
V_17:
F_10 (ex, tmp, dest, list) {
F_11 ( & V_12 -> V_18 ) ;
F_12 ( V_12 ) ;
}
return - V_19 ;
}
static int F_13 ( struct V_1 * V_1 ,
struct V_11 * V_12 )
{
struct V_11 * V_20 , * V_21 ;
F_6 ( & V_15 ) ;
V_20 = F_8 ( V_12 , sizeof( * V_12 ) , V_16 ) ;
if ( ! V_20 )
return - V_19 ;
F_7 (walk, &dev_cgroup->exceptions, list) {
if ( V_21 -> type != V_12 -> type )
continue;
if ( V_21 -> V_22 != V_12 -> V_22 )
continue;
if ( V_21 -> V_23 != V_12 -> V_23 )
continue;
V_21 -> V_24 |= V_12 -> V_24 ;
F_12 ( V_20 ) ;
V_20 = NULL ;
}
if ( V_20 != NULL )
F_14 ( & V_20 -> V_18 , & V_1 -> V_25 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_1 ,
struct V_11 * V_12 )
{
struct V_11 * V_21 , * V_13 ;
F_6 ( & V_15 ) ;
F_10 (walk, tmp, &dev_cgroup->exceptions, list) {
if ( V_21 -> type != V_12 -> type )
continue;
if ( V_21 -> V_22 != V_12 -> V_22 )
continue;
if ( V_21 -> V_23 != V_12 -> V_23 )
continue;
V_21 -> V_24 &= ~ V_12 -> V_24 ;
if ( ! V_21 -> V_24 ) {
F_16 ( & V_21 -> V_18 ) ;
F_17 ( V_21 , V_26 ) ;
}
}
}
static void F_18 ( struct V_1 * V_1 )
{
struct V_11 * V_12 , * V_13 ;
F_10 (ex, tmp, &dev_cgroup->exceptions, list) {
F_16 ( & V_12 -> V_18 ) ;
F_17 ( V_12 , V_26 ) ;
}
}
static void F_19 ( struct V_1 * V_1 )
{
F_6 ( & V_15 ) ;
F_18 ( V_1 ) ;
}
static inline bool F_20 ( const struct V_1 * V_27 )
{
return ( V_27 -> V_28 != V_29 ) ;
}
static int F_21 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_1 * V_30 = F_1 ( F_22 ( V_4 ) ) ;
int V_31 = 0 ;
F_23 ( & V_15 ) ;
if ( V_30 == NULL )
V_1 -> V_28 = V_32 ;
else {
V_31 = F_5 ( & V_1 -> V_25 ,
& V_30 -> V_25 ) ;
if ( ! V_31 )
V_1 -> V_28 = V_30 -> V_28 ;
}
F_24 ( & V_15 ) ;
return V_31 ;
}
static void F_25 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_23 ( & V_15 ) ;
V_1 -> V_28 = V_29 ;
F_24 ( & V_15 ) ;
}
static struct V_2 *
F_26 ( struct V_2 * V_33 )
{
struct V_1 * V_1 ;
V_1 = F_27 ( sizeof( * V_1 ) , V_16 ) ;
if ( ! V_1 )
return F_28 ( - V_19 ) ;
F_29 ( & V_1 -> V_25 ) ;
V_1 -> V_28 = V_29 ;
return & V_1 -> V_4 ;
}
static void F_30 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_18 ( V_1 ) ;
F_12 ( V_1 ) ;
}
static void F_31 ( char * V_34 , short V_24 )
{
int V_35 = 0 ;
memset ( V_34 , 0 , V_36 ) ;
if ( V_24 & V_37 )
V_34 [ V_35 ++ ] = 'r' ;
if ( V_24 & V_38 )
V_34 [ V_35 ++ ] = 'w' ;
if ( V_24 & V_39 )
V_34 [ V_35 ++ ] = 'm' ;
}
static char F_32 ( short type )
{
if ( type == V_40 )
return 'a' ;
if ( type == V_41 )
return 'c' ;
if ( type == V_42 )
return 'b' ;
return 'X' ;
}
static void F_33 ( char * V_43 , unsigned V_44 )
{
if ( V_44 == ~ 0 )
strcpy ( V_43 , L_1 ) ;
else
sprintf ( V_43 , L_2 , V_44 ) ;
}
static int F_34 ( struct V_2 * V_4 ,
struct V_45 * V_46 , struct V_47 * V_44 )
{
struct V_1 * V_48 = F_1 ( V_4 ) ;
struct V_11 * V_12 ;
char V_49 [ V_50 ] , V_51 [ V_50 ] , V_34 [ V_36 ] ;
F_35 () ;
if ( V_48 -> V_28 == V_32 ) {
F_31 ( V_34 , V_52 ) ;
F_33 ( V_49 , ~ 0 ) ;
F_33 ( V_51 , ~ 0 ) ;
F_36 ( V_44 , L_3 , F_32 ( V_40 ) ,
V_49 , V_51 , V_34 ) ;
} else {
F_37 (ex, &devcgroup->exceptions, list) {
F_31 ( V_34 , V_12 -> V_24 ) ;
F_33 ( V_49 , V_12 -> V_22 ) ;
F_33 ( V_51 , V_12 -> V_23 ) ;
F_36 ( V_44 , L_3 , F_32 ( V_12 -> type ) ,
V_49 , V_51 , V_34 ) ;
}
}
F_38 () ;
return 0 ;
}
static bool F_39 ( struct V_1 * V_1 ,
struct V_11 * V_53 ,
enum V_54 V_28 )
{
struct V_11 * V_12 ;
bool V_55 = false ;
F_40 ( F_41 () ||
F_42 ( & V_15 ) ,
L_4 ) ;
F_37 (ex, &dev_cgroup->exceptions, list) {
if ( ( V_53 -> type & V_42 ) && ! ( V_12 -> type & V_42 ) )
continue;
if ( ( V_53 -> type & V_41 ) && ! ( V_12 -> type & V_41 ) )
continue;
if ( V_12 -> V_22 != ~ 0 && V_12 -> V_22 != V_53 -> V_22 )
continue;
if ( V_12 -> V_23 != ~ 0 && V_12 -> V_23 != V_53 -> V_23 )
continue;
if ( V_53 -> V_24 & ( ~ V_12 -> V_24 ) )
continue;
V_55 = true ;
break;
}
if ( V_1 -> V_28 == V_32 ) {
if ( V_28 == V_32 ) {
return true ;
} else {
if ( V_55 )
return false ;
return true ;
}
} else {
if ( V_55 )
return true ;
else
return false ;
}
return false ;
}
static int F_43 ( struct V_1 * V_56 ,
struct V_11 * V_12 )
{
struct V_1 * V_57 = F_1 ( F_22 ( & V_56 -> V_4 ) ) ;
if ( ! V_57 )
return 1 ;
return F_39 ( V_57 , V_12 , V_56 -> V_28 ) ;
}
static inline int F_44 ( struct V_1 * V_57 )
{
if ( ! V_57 )
return 1 ;
return V_57 -> V_28 == V_32 ;
}
static void F_45 ( struct V_1 * V_27 )
{
struct V_11 * V_12 ;
struct V_8 * V_58 , * V_13 ;
F_46 (this, tmp, &devcg->exceptions) {
V_12 = F_2 ( V_58 , struct V_11 , V_18 ) ;
if ( ! F_43 ( V_27 , V_12 ) )
F_15 ( V_27 , V_12 ) ;
}
}
static int F_47 ( struct V_1 * V_59 ,
struct V_11 * V_12 )
{
struct V_2 * V_60 ;
int V_61 = 0 ;
F_35 () ;
F_48 (pos, &devcg_root->css) {
struct V_1 * V_27 = F_1 ( V_60 ) ;
if ( V_60 == & V_59 -> V_4 || ! F_20 ( V_27 ) )
continue;
F_38 () ;
if ( V_59 -> V_28 == V_32 &&
V_27 -> V_28 == V_32 ) {
V_61 = F_13 ( V_27 , V_12 ) ;
if ( V_61 )
break;
} else {
F_15 ( V_27 , V_12 ) ;
}
F_45 ( V_27 ) ;
F_35 () ;
}
F_38 () ;
return V_61 ;
}
static inline bool F_49 ( struct V_1 * V_48 )
{
struct V_62 * V_63 = V_48 -> V_4 . V_62 ;
return ! F_50 ( & V_63 -> V_64 ) ;
}
static int F_51 ( struct V_1 * V_48 ,
int V_65 , const char * V_66 )
{
const char * V_67 ;
char V_68 [ 12 ] ;
int V_69 , V_61 = 0 ;
struct V_11 V_12 ;
struct V_1 * V_57 = F_1 ( F_22 ( & V_48 -> V_4 ) ) ;
if ( ! F_52 ( V_70 ) )
return - V_71 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_67 = V_66 ;
switch ( * V_67 ) {
case 'a' :
switch ( V_65 ) {
case V_72 :
if ( F_49 ( V_48 ) )
return - V_73 ;
if ( ! F_44 ( V_57 ) )
return - V_71 ;
F_19 ( V_48 ) ;
V_48 -> V_28 = V_32 ;
if ( ! V_57 )
break;
V_61 = F_5 ( & V_48 -> V_25 ,
& V_57 -> V_25 ) ;
if ( V_61 )
return V_61 ;
break;
case V_74 :
if ( F_49 ( V_48 ) )
return - V_73 ;
F_19 ( V_48 ) ;
V_48 -> V_28 = V_75 ;
break;
default:
return - V_73 ;
}
return 0 ;
case 'b' :
V_12 . type = V_42 ;
break;
case 'c' :
V_12 . type = V_41 ;
break;
default:
return - V_73 ;
}
V_67 ++ ;
if ( ! isspace ( * V_67 ) )
return - V_73 ;
V_67 ++ ;
if ( * V_67 == '*' ) {
V_12 . V_22 = ~ 0 ;
V_67 ++ ;
} else if ( isdigit ( * V_67 ) ) {
memset ( V_68 , 0 , sizeof( V_68 ) ) ;
for ( V_69 = 0 ; V_69 < sizeof( V_68 ) - 1 ; V_69 ++ ) {
V_68 [ V_69 ] = * V_67 ;
V_67 ++ ;
if ( ! isdigit ( * V_67 ) )
break;
}
V_61 = F_53 ( V_68 , 10 , & V_12 . V_22 ) ;
if ( V_61 )
return - V_73 ;
} else {
return - V_73 ;
}
if ( * V_67 != ':' )
return - V_73 ;
V_67 ++ ;
if ( * V_67 == '*' ) {
V_12 . V_23 = ~ 0 ;
V_67 ++ ;
} else if ( isdigit ( * V_67 ) ) {
memset ( V_68 , 0 , sizeof( V_68 ) ) ;
for ( V_69 = 0 ; V_69 < sizeof( V_68 ) - 1 ; V_69 ++ ) {
V_68 [ V_69 ] = * V_67 ;
V_67 ++ ;
if ( ! isdigit ( * V_67 ) )
break;
}
V_61 = F_53 ( V_68 , 10 , & V_12 . V_23 ) ;
if ( V_61 )
return - V_73 ;
} else {
return - V_73 ;
}
if ( ! isspace ( * V_67 ) )
return - V_73 ;
for ( V_67 ++ , V_69 = 0 ; V_69 < 3 ; V_69 ++ , V_67 ++ ) {
switch ( * V_67 ) {
case 'r' :
V_12 . V_24 |= V_37 ;
break;
case 'w' :
V_12 . V_24 |= V_38 ;
break;
case 'm' :
V_12 . V_24 |= V_39 ;
break;
case '\n' :
case '\0' :
V_69 = 3 ;
break;
default:
return - V_73 ;
}
}
switch ( V_65 ) {
case V_72 :
if ( ! F_43 ( V_48 , & V_12 ) )
return - V_71 ;
if ( V_48 -> V_28 == V_32 ) {
F_15 ( V_48 , & V_12 ) ;
return 0 ;
}
V_61 = F_13 ( V_48 , & V_12 ) ;
break;
case V_74 :
if ( V_48 -> V_28 == V_75 )
F_15 ( V_48 , & V_12 ) ;
else
V_61 = F_13 ( V_48 , & V_12 ) ;
if ( V_61 )
break;
V_61 = F_47 ( V_48 , & V_12 ) ;
break;
default:
V_61 = - V_73 ;
}
return V_61 ;
}
static int F_54 ( struct V_2 * V_4 ,
struct V_45 * V_46 , const char * V_66 )
{
int V_76 ;
F_23 ( & V_15 ) ;
V_76 = F_51 ( F_1 ( V_4 ) ,
V_46 -> V_77 , V_66 ) ;
F_24 ( & V_15 ) ;
return V_76 ;
}
static int F_55 ( short type , T_1 V_22 , T_1 V_23 ,
short V_24 )
{
struct V_1 * V_1 ;
struct V_11 V_12 ;
int V_61 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . type = type ;
V_12 . V_22 = V_22 ;
V_12 . V_23 = V_23 ;
V_12 . V_24 = V_24 ;
F_35 () ;
V_1 = F_3 ( V_78 ) ;
V_61 = F_39 ( V_1 , & V_12 , V_1 -> V_28 ) ;
F_38 () ;
if ( ! V_61 )
return - V_71 ;
return 0 ;
}
int F_56 ( struct V_79 * V_79 , int V_80 )
{
short type , V_24 = 0 ;
if ( F_57 ( V_79 -> V_81 ) )
type = V_42 ;
if ( F_58 ( V_79 -> V_81 ) )
type = V_41 ;
if ( V_80 & V_82 )
V_24 |= V_38 ;
if ( V_80 & V_83 )
V_24 |= V_37 ;
return F_55 ( type , F_59 ( V_79 ) , F_60 ( V_79 ) ,
V_24 ) ;
}
int F_61 ( int V_84 , T_2 V_85 )
{
short type ;
if ( ! F_57 ( V_84 ) && ! F_58 ( V_84 ) )
return 0 ;
if ( F_57 ( V_84 ) )
type = V_42 ;
else
type = V_41 ;
return F_55 ( type , F_62 ( V_85 ) , F_63 ( V_85 ) ,
V_39 ) ;
}
