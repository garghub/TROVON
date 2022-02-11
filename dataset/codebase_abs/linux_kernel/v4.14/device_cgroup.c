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
struct V_1 * V_30 = F_1 ( V_4 -> V_31 ) ;
int V_32 = 0 ;
F_22 ( & V_15 ) ;
if ( V_30 == NULL )
V_1 -> V_28 = V_33 ;
else {
V_32 = F_5 ( & V_1 -> V_25 ,
& V_30 -> V_25 ) ;
if ( ! V_32 )
V_1 -> V_28 = V_30 -> V_28 ;
}
F_23 ( & V_15 ) ;
return V_32 ;
}
static void F_24 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_22 ( & V_15 ) ;
V_1 -> V_28 = V_29 ;
F_23 ( & V_15 ) ;
}
static struct V_2 *
F_25 ( struct V_2 * V_34 )
{
struct V_1 * V_1 ;
V_1 = F_26 ( sizeof( * V_1 ) , V_16 ) ;
if ( ! V_1 )
return F_27 ( - V_19 ) ;
F_28 ( & V_1 -> V_25 ) ;
V_1 -> V_28 = V_29 ;
return & V_1 -> V_4 ;
}
static void F_29 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_18 ( V_1 ) ;
F_12 ( V_1 ) ;
}
static void F_30 ( char * V_35 , short V_24 )
{
int V_36 = 0 ;
memset ( V_35 , 0 , V_37 ) ;
if ( V_24 & V_38 )
V_35 [ V_36 ++ ] = 'r' ;
if ( V_24 & V_39 )
V_35 [ V_36 ++ ] = 'w' ;
if ( V_24 & V_40 )
V_35 [ V_36 ++ ] = 'm' ;
}
static char F_31 ( short type )
{
if ( type == V_41 )
return 'a' ;
if ( type == V_42 )
return 'c' ;
if ( type == V_43 )
return 'b' ;
return 'X' ;
}
static void F_32 ( char * V_44 , unsigned V_45 )
{
if ( V_45 == ~ 0 )
strcpy ( V_44 , L_1 ) ;
else
sprintf ( V_44 , L_2 , V_45 ) ;
}
static int F_33 ( struct V_46 * V_45 , void * V_47 )
{
struct V_1 * V_48 = F_1 ( F_34 ( V_45 ) ) ;
struct V_11 * V_12 ;
char V_49 [ V_50 ] , V_51 [ V_50 ] , V_35 [ V_37 ] ;
F_35 () ;
if ( V_48 -> V_28 == V_33 ) {
F_30 ( V_35 , V_52 ) ;
F_32 ( V_49 , ~ 0 ) ;
F_32 ( V_51 , ~ 0 ) ;
F_36 ( V_45 , L_3 , F_31 ( V_41 ) ,
V_49 , V_51 , V_35 ) ;
} else {
F_37 (ex, &devcgroup->exceptions, list) {
F_30 ( V_35 , V_12 -> V_24 ) ;
F_32 ( V_49 , V_12 -> V_22 ) ;
F_32 ( V_51 , V_12 -> V_23 ) ;
F_36 ( V_45 , L_3 , F_31 ( V_12 -> type ) ,
V_49 , V_51 , V_35 ) ;
}
}
F_38 () ;
return 0 ;
}
static bool F_39 ( struct V_8 * V_25 , short type ,
T_1 V_22 , T_1 V_23 , short V_24 )
{
struct V_11 * V_12 ;
F_37 (ex, exceptions, list) {
if ( ( type & V_43 ) && ! ( V_12 -> type & V_43 ) )
continue;
if ( ( type & V_42 ) && ! ( V_12 -> type & V_42 ) )
continue;
if ( V_12 -> V_22 != ~ 0 && V_12 -> V_22 != V_22 )
continue;
if ( V_12 -> V_23 != ~ 0 && V_12 -> V_23 != V_23 )
continue;
if ( V_24 & ( ~ V_12 -> V_24 ) )
continue;
return true ;
}
return false ;
}
static bool F_40 ( struct V_8 * V_25 , short type ,
T_1 V_22 , T_1 V_23 , short V_24 )
{
struct V_11 * V_12 ;
F_37 (ex, exceptions, list) {
if ( ( type & V_43 ) && ! ( V_12 -> type & V_43 ) )
continue;
if ( ( type & V_42 ) && ! ( V_12 -> type & V_42 ) )
continue;
if ( V_12 -> V_22 != ~ 0 && V_22 != ~ 0 && V_12 -> V_22 != V_22 )
continue;
if ( V_12 -> V_23 != ~ 0 && V_23 != ~ 0 && V_12 -> V_23 != V_23 )
continue;
if ( ! ( V_24 & V_12 -> V_24 ) )
continue;
return true ;
}
return false ;
}
static bool F_41 ( struct V_1 * V_1 ,
struct V_11 * V_53 ,
enum V_54 V_28 )
{
bool V_55 = false ;
F_42 ( ! F_43 () &&
! F_44 ( & V_15 ) ,
L_4 ) ;
if ( V_1 -> V_28 == V_33 ) {
if ( V_28 == V_33 ) {
return true ;
} else {
V_55 = F_40 ( & V_1 -> V_25 ,
V_53 -> type ,
V_53 -> V_22 ,
V_53 -> V_23 ,
V_53 -> V_24 ) ;
if ( V_55 )
return false ;
return true ;
}
} else {
V_55 = F_39 ( & V_1 -> V_25 , V_53 -> type ,
V_53 -> V_22 , V_53 -> V_23 ,
V_53 -> V_24 ) ;
if ( V_55 )
return true ;
else
return false ;
}
return false ;
}
static int F_45 ( struct V_1 * V_56 ,
struct V_11 * V_12 )
{
struct V_1 * V_31 = F_1 ( V_56 -> V_4 . V_31 ) ;
if ( ! V_31 )
return 1 ;
return F_41 ( V_31 , V_12 , V_56 -> V_28 ) ;
}
static bool F_46 ( struct V_1 * V_56 ,
struct V_11 * V_12 )
{
struct V_1 * V_31 = F_1 ( V_56 -> V_4 . V_31 ) ;
if ( ! V_31 )
return true ;
if ( V_56 -> V_28 == V_57 )
return true ;
return ! F_40 ( & V_31 -> V_25 , V_12 -> type ,
V_12 -> V_22 , V_12 -> V_23 , V_12 -> V_24 ) ;
}
static inline int F_47 ( struct V_1 * V_31 )
{
if ( ! V_31 )
return 1 ;
return V_31 -> V_28 == V_33 ;
}
static void F_48 ( struct V_1 * V_27 )
{
struct V_11 * V_12 ;
struct V_8 * V_58 , * V_13 ;
F_49 (this, tmp, &devcg->exceptions) {
V_12 = F_2 ( V_58 , struct V_11 , V_18 ) ;
if ( ! F_45 ( V_27 , V_12 ) )
F_15 ( V_27 , V_12 ) ;
}
}
static int F_50 ( struct V_1 * V_59 ,
struct V_11 * V_12 )
{
struct V_2 * V_60 ;
int V_61 = 0 ;
F_35 () ;
F_51 (pos, &devcg_root->css) {
struct V_1 * V_27 = F_1 ( V_60 ) ;
if ( V_60 == & V_59 -> V_4 || ! F_20 ( V_27 ) )
continue;
F_38 () ;
if ( V_59 -> V_28 == V_33 &&
V_27 -> V_28 == V_33 ) {
V_61 = F_13 ( V_27 , V_12 ) ;
if ( V_61 )
break;
} else {
F_15 ( V_27 , V_12 ) ;
}
F_48 ( V_27 ) ;
F_35 () ;
}
F_38 () ;
return V_61 ;
}
static int F_52 ( struct V_1 * V_48 ,
int V_62 , char * V_63 )
{
const char * V_64 ;
char V_65 [ 12 ] ;
int V_66 , V_61 = 0 ;
struct V_11 V_12 ;
struct V_1 * V_31 = F_1 ( V_48 -> V_4 . V_31 ) ;
if ( ! F_53 ( V_67 ) )
return - V_68 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_64 = V_63 ;
switch ( * V_64 ) {
case 'a' :
switch ( V_62 ) {
case V_69 :
if ( F_54 ( & V_48 -> V_4 ) )
return - V_70 ;
if ( ! F_47 ( V_31 ) )
return - V_68 ;
F_19 ( V_48 ) ;
V_48 -> V_28 = V_33 ;
if ( ! V_31 )
break;
V_61 = F_5 ( & V_48 -> V_25 ,
& V_31 -> V_25 ) ;
if ( V_61 )
return V_61 ;
break;
case V_71 :
if ( F_54 ( & V_48 -> V_4 ) )
return - V_70 ;
F_19 ( V_48 ) ;
V_48 -> V_28 = V_57 ;
break;
default:
return - V_70 ;
}
return 0 ;
case 'b' :
V_12 . type = V_43 ;
break;
case 'c' :
V_12 . type = V_42 ;
break;
default:
return - V_70 ;
}
V_64 ++ ;
if ( ! isspace ( * V_64 ) )
return - V_70 ;
V_64 ++ ;
if ( * V_64 == '*' ) {
V_12 . V_22 = ~ 0 ;
V_64 ++ ;
} else if ( isdigit ( * V_64 ) ) {
memset ( V_65 , 0 , sizeof( V_65 ) ) ;
for ( V_66 = 0 ; V_66 < sizeof( V_65 ) - 1 ; V_66 ++ ) {
V_65 [ V_66 ] = * V_64 ;
V_64 ++ ;
if ( ! isdigit ( * V_64 ) )
break;
}
V_61 = F_55 ( V_65 , 10 , & V_12 . V_22 ) ;
if ( V_61 )
return - V_70 ;
} else {
return - V_70 ;
}
if ( * V_64 != ':' )
return - V_70 ;
V_64 ++ ;
if ( * V_64 == '*' ) {
V_12 . V_23 = ~ 0 ;
V_64 ++ ;
} else if ( isdigit ( * V_64 ) ) {
memset ( V_65 , 0 , sizeof( V_65 ) ) ;
for ( V_66 = 0 ; V_66 < sizeof( V_65 ) - 1 ; V_66 ++ ) {
V_65 [ V_66 ] = * V_64 ;
V_64 ++ ;
if ( ! isdigit ( * V_64 ) )
break;
}
V_61 = F_55 ( V_65 , 10 , & V_12 . V_23 ) ;
if ( V_61 )
return - V_70 ;
} else {
return - V_70 ;
}
if ( ! isspace ( * V_64 ) )
return - V_70 ;
for ( V_64 ++ , V_66 = 0 ; V_66 < 3 ; V_66 ++ , V_64 ++ ) {
switch ( * V_64 ) {
case 'r' :
V_12 . V_24 |= V_38 ;
break;
case 'w' :
V_12 . V_24 |= V_39 ;
break;
case 'm' :
V_12 . V_24 |= V_40 ;
break;
case '\n' :
case '\0' :
V_66 = 3 ;
break;
default:
return - V_70 ;
}
}
switch ( V_62 ) {
case V_69 :
if ( V_48 -> V_28 == V_33 ) {
if ( ! F_46 ( V_48 , & V_12 ) )
return - V_68 ;
F_15 ( V_48 , & V_12 ) ;
break;
}
if ( ! F_45 ( V_48 , & V_12 ) )
return - V_68 ;
V_61 = F_13 ( V_48 , & V_12 ) ;
break;
case V_71 :
if ( V_48 -> V_28 == V_57 )
F_15 ( V_48 , & V_12 ) ;
else
V_61 = F_13 ( V_48 , & V_12 ) ;
if ( V_61 )
break;
V_61 = F_50 ( V_48 , & V_12 ) ;
break;
default:
V_61 = - V_70 ;
}
return V_61 ;
}
static T_2 F_56 ( struct V_72 * V_73 ,
char * V_74 , T_3 V_75 , T_4 V_76 )
{
int V_77 ;
F_22 ( & V_15 ) ;
V_77 = F_52 ( F_1 ( F_57 ( V_73 ) ) ,
F_58 ( V_73 ) -> V_78 , F_59 ( V_74 ) ) ;
F_23 ( & V_15 ) ;
return V_77 ? : V_75 ;
}
static int F_60 ( short type , T_1 V_22 , T_1 V_23 ,
short V_24 )
{
struct V_1 * V_1 ;
bool V_61 ;
F_35 () ;
V_1 = F_3 ( V_79 ) ;
if ( V_1 -> V_28 == V_33 )
V_61 = ! F_40 ( & V_1 -> V_25 ,
type , V_22 , V_23 , V_24 ) ;
else
V_61 = F_39 ( & V_1 -> V_25 , type , V_22 ,
V_23 , V_24 ) ;
F_38 () ;
if ( ! V_61 )
return - V_68 ;
return 0 ;
}
int F_61 ( struct V_80 * V_80 , int V_81 )
{
short type , V_24 = 0 ;
if ( F_62 ( V_80 -> V_82 ) )
type = V_43 ;
if ( F_63 ( V_80 -> V_82 ) )
type = V_42 ;
if ( V_81 & V_83 )
V_24 |= V_39 ;
if ( V_81 & V_84 )
V_24 |= V_38 ;
return F_60 ( type , F_64 ( V_80 ) , F_65 ( V_80 ) ,
V_24 ) ;
}
int F_66 ( int V_85 , T_5 V_86 )
{
short type ;
if ( ! F_62 ( V_85 ) && ! F_63 ( V_85 ) )
return 0 ;
if ( F_62 ( V_85 ) )
type = V_43 ;
else
type = V_42 ;
return F_60 ( type , F_67 ( V_86 ) , F_68 ( V_86 ) ,
V_40 ) ;
}
