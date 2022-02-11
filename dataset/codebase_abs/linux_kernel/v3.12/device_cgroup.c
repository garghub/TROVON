static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( V_3 , struct V_1 , V_4 ) : NULL ;
}
static inline struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_1 ( F_4 ( V_6 , V_7 ) ) ;
}
static int F_5 ( struct V_2 * V_8 ,
struct V_9 * V_10 )
{
struct V_5 * V_6 = F_6 ( V_10 ) ;
if ( V_11 != V_6 && ! F_7 ( V_12 ) )
return - V_13 ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 , struct V_14 * V_16 )
{
struct V_17 * V_18 , * V_19 , * V_20 ;
F_9 ( & V_21 ) ;
F_10 (ex, orig, list) {
V_20 = F_11 ( V_18 , sizeof( * V_18 ) , V_22 ) ;
if ( ! V_20 )
goto V_23;
F_12 ( & V_20 -> V_24 , V_15 ) ;
}
return 0 ;
V_23:
F_13 (ex, tmp, dest, list) {
F_14 ( & V_18 -> V_24 ) ;
F_15 ( V_18 ) ;
}
return - V_25 ;
}
static int F_16 ( struct V_1 * V_1 ,
struct V_17 * V_18 )
{
struct V_17 * V_26 , * V_27 ;
F_9 ( & V_21 ) ;
V_26 = F_11 ( V_18 , sizeof( * V_18 ) , V_22 ) ;
if ( ! V_26 )
return - V_25 ;
F_10 (walk, &dev_cgroup->exceptions, list) {
if ( V_27 -> type != V_18 -> type )
continue;
if ( V_27 -> V_28 != V_18 -> V_28 )
continue;
if ( V_27 -> V_29 != V_18 -> V_29 )
continue;
V_27 -> V_30 |= V_18 -> V_30 ;
F_15 ( V_26 ) ;
V_26 = NULL ;
}
if ( V_26 != NULL )
F_17 ( & V_26 -> V_24 , & V_1 -> V_31 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_1 ,
struct V_17 * V_18 )
{
struct V_17 * V_27 , * V_19 ;
F_9 ( & V_21 ) ;
F_13 (walk, tmp, &dev_cgroup->exceptions, list) {
if ( V_27 -> type != V_18 -> type )
continue;
if ( V_27 -> V_28 != V_18 -> V_28 )
continue;
if ( V_27 -> V_29 != V_18 -> V_29 )
continue;
V_27 -> V_30 &= ~ V_18 -> V_30 ;
if ( ! V_27 -> V_30 ) {
F_19 ( & V_27 -> V_24 ) ;
F_20 ( V_27 , V_32 ) ;
}
}
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_17 * V_18 , * V_19 ;
F_13 (ex, tmp, &dev_cgroup->exceptions, list) {
F_19 ( & V_18 -> V_24 ) ;
F_20 ( V_18 , V_32 ) ;
}
}
static void F_22 ( struct V_1 * V_1 )
{
F_9 ( & V_21 ) ;
F_21 ( V_1 ) ;
}
static inline bool F_23 ( const struct V_1 * V_33 )
{
return ( V_33 -> V_34 != V_35 ) ;
}
static int F_24 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_1 * V_36 = F_1 ( F_25 ( V_4 ) ) ;
int V_37 = 0 ;
F_26 ( & V_21 ) ;
if ( V_36 == NULL )
V_1 -> V_34 = V_38 ;
else {
V_37 = F_8 ( & V_1 -> V_31 ,
& V_36 -> V_31 ) ;
if ( ! V_37 )
V_1 -> V_34 = V_36 -> V_34 ;
}
F_27 ( & V_21 ) ;
return V_37 ;
}
static void F_28 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_26 ( & V_21 ) ;
V_1 -> V_34 = V_35 ;
F_27 ( & V_21 ) ;
}
static struct V_2 *
F_29 ( struct V_2 * V_39 )
{
struct V_1 * V_1 ;
V_1 = F_30 ( sizeof( * V_1 ) , V_22 ) ;
if ( ! V_1 )
return F_31 ( - V_25 ) ;
F_32 ( & V_1 -> V_31 ) ;
V_1 -> V_34 = V_35 ;
return & V_1 -> V_4 ;
}
static void F_33 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_21 ( V_1 ) ;
F_15 ( V_1 ) ;
}
static void F_34 ( char * V_40 , short V_30 )
{
int V_41 = 0 ;
memset ( V_40 , 0 , V_42 ) ;
if ( V_30 & V_43 )
V_40 [ V_41 ++ ] = 'r' ;
if ( V_30 & V_44 )
V_40 [ V_41 ++ ] = 'w' ;
if ( V_30 & V_45 )
V_40 [ V_41 ++ ] = 'm' ;
}
static char F_35 ( short type )
{
if ( type == V_46 )
return 'a' ;
if ( type == V_47 )
return 'c' ;
if ( type == V_48 )
return 'b' ;
return 'X' ;
}
static void F_36 ( char * V_49 , unsigned V_50 )
{
if ( V_50 == ~ 0 )
strcpy ( V_49 , L_1 ) ;
else
sprintf ( V_49 , L_2 , V_50 ) ;
}
static int F_37 ( struct V_2 * V_4 ,
struct V_51 * V_52 , struct V_53 * V_50 )
{
struct V_1 * V_54 = F_1 ( V_4 ) ;
struct V_17 * V_18 ;
char V_55 [ V_56 ] , V_57 [ V_56 ] , V_40 [ V_42 ] ;
F_38 () ;
if ( V_54 -> V_34 == V_38 ) {
F_34 ( V_40 , V_58 ) ;
F_36 ( V_55 , ~ 0 ) ;
F_36 ( V_57 , ~ 0 ) ;
F_39 ( V_50 , L_3 , F_35 ( V_46 ) ,
V_55 , V_57 , V_40 ) ;
} else {
F_40 (ex, &devcgroup->exceptions, list) {
F_34 ( V_40 , V_18 -> V_30 ) ;
F_36 ( V_55 , V_18 -> V_28 ) ;
F_36 ( V_57 , V_18 -> V_29 ) ;
F_39 ( V_50 , L_3 , F_35 ( V_18 -> type ) ,
V_55 , V_57 , V_40 ) ;
}
}
F_41 () ;
return 0 ;
}
static bool F_42 ( struct V_1 * V_1 ,
struct V_17 * V_59 ,
enum V_60 V_34 )
{
struct V_17 * V_18 ;
bool V_61 = false ;
F_43 ( F_44 () ||
F_45 ( & V_21 ) ,
L_4 ) ;
F_40 (ex, &dev_cgroup->exceptions, list) {
if ( ( V_59 -> type & V_48 ) && ! ( V_18 -> type & V_48 ) )
continue;
if ( ( V_59 -> type & V_47 ) && ! ( V_18 -> type & V_47 ) )
continue;
if ( V_18 -> V_28 != ~ 0 && V_18 -> V_28 != V_59 -> V_28 )
continue;
if ( V_18 -> V_29 != ~ 0 && V_18 -> V_29 != V_59 -> V_29 )
continue;
if ( V_59 -> V_30 & ( ~ V_18 -> V_30 ) )
continue;
V_61 = true ;
break;
}
if ( V_1 -> V_34 == V_38 ) {
if ( V_34 == V_38 ) {
return true ;
} else {
if ( V_61 )
return false ;
return true ;
}
} else {
if ( V_61 )
return true ;
else
return false ;
}
return false ;
}
static int F_46 ( struct V_1 * V_62 ,
struct V_17 * V_18 )
{
struct V_1 * V_63 = F_1 ( F_25 ( & V_62 -> V_4 ) ) ;
if ( ! V_63 )
return 1 ;
return F_42 ( V_63 , V_18 , V_62 -> V_34 ) ;
}
static inline int F_47 ( struct V_1 * V_63 )
{
if ( ! V_63 )
return 1 ;
return V_63 -> V_34 == V_38 ;
}
static void F_48 ( struct V_1 * V_33 )
{
struct V_17 * V_18 ;
struct V_14 * V_64 , * V_19 ;
F_49 (this, tmp, &devcg->exceptions) {
V_18 = F_2 ( V_64 , struct V_17 , V_24 ) ;
if ( ! F_46 ( V_33 , V_18 ) )
F_18 ( V_33 , V_18 ) ;
}
}
static int F_50 ( struct V_1 * V_65 ,
struct V_17 * V_18 )
{
struct V_2 * V_66 ;
int V_67 = 0 ;
F_38 () ;
F_51 (pos, &devcg_root->css) {
struct V_1 * V_33 = F_1 ( V_66 ) ;
if ( V_66 == & V_65 -> V_4 || ! F_23 ( V_33 ) )
continue;
F_41 () ;
if ( V_65 -> V_34 == V_38 &&
V_33 -> V_34 == V_38 ) {
V_67 = F_16 ( V_33 , V_18 ) ;
if ( V_67 )
break;
} else {
F_18 ( V_33 , V_18 ) ;
}
F_48 ( V_33 ) ;
F_38 () ;
}
F_41 () ;
return V_67 ;
}
static inline bool F_52 ( struct V_1 * V_54 )
{
struct V_68 * V_69 = V_54 -> V_4 . V_68 ;
return ! F_53 ( & V_69 -> V_70 ) ;
}
static int F_54 ( struct V_1 * V_54 ,
int V_71 , const char * V_72 )
{
const char * V_73 ;
char V_74 [ 12 ] ;
int V_75 , V_67 = 0 ;
struct V_17 V_18 ;
struct V_1 * V_63 = F_1 ( F_25 ( & V_54 -> V_4 ) ) ;
if ( ! F_7 ( V_12 ) )
return - V_13 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_73 = V_72 ;
switch ( * V_73 ) {
case 'a' :
switch ( V_71 ) {
case V_76 :
if ( F_52 ( V_54 ) )
return - V_77 ;
if ( ! F_47 ( V_63 ) )
return - V_13 ;
F_22 ( V_54 ) ;
V_54 -> V_34 = V_38 ;
if ( ! V_63 )
break;
V_67 = F_8 ( & V_54 -> V_31 ,
& V_63 -> V_31 ) ;
if ( V_67 )
return V_67 ;
break;
case V_78 :
if ( F_52 ( V_54 ) )
return - V_77 ;
F_22 ( V_54 ) ;
V_54 -> V_34 = V_79 ;
break;
default:
return - V_77 ;
}
return 0 ;
case 'b' :
V_18 . type = V_48 ;
break;
case 'c' :
V_18 . type = V_47 ;
break;
default:
return - V_77 ;
}
V_73 ++ ;
if ( ! isspace ( * V_73 ) )
return - V_77 ;
V_73 ++ ;
if ( * V_73 == '*' ) {
V_18 . V_28 = ~ 0 ;
V_73 ++ ;
} else if ( isdigit ( * V_73 ) ) {
memset ( V_74 , 0 , sizeof( V_74 ) ) ;
for ( V_75 = 0 ; V_75 < sizeof( V_74 ) - 1 ; V_75 ++ ) {
V_74 [ V_75 ] = * V_73 ;
V_73 ++ ;
if ( ! isdigit ( * V_73 ) )
break;
}
V_67 = F_55 ( V_74 , 10 , & V_18 . V_28 ) ;
if ( V_67 )
return - V_77 ;
} else {
return - V_77 ;
}
if ( * V_73 != ':' )
return - V_77 ;
V_73 ++ ;
if ( * V_73 == '*' ) {
V_18 . V_29 = ~ 0 ;
V_73 ++ ;
} else if ( isdigit ( * V_73 ) ) {
memset ( V_74 , 0 , sizeof( V_74 ) ) ;
for ( V_75 = 0 ; V_75 < sizeof( V_74 ) - 1 ; V_75 ++ ) {
V_74 [ V_75 ] = * V_73 ;
V_73 ++ ;
if ( ! isdigit ( * V_73 ) )
break;
}
V_67 = F_55 ( V_74 , 10 , & V_18 . V_29 ) ;
if ( V_67 )
return - V_77 ;
} else {
return - V_77 ;
}
if ( ! isspace ( * V_73 ) )
return - V_77 ;
for ( V_73 ++ , V_75 = 0 ; V_75 < 3 ; V_75 ++ , V_73 ++ ) {
switch ( * V_73 ) {
case 'r' :
V_18 . V_30 |= V_43 ;
break;
case 'w' :
V_18 . V_30 |= V_44 ;
break;
case 'm' :
V_18 . V_30 |= V_45 ;
break;
case '\n' :
case '\0' :
V_75 = 3 ;
break;
default:
return - V_77 ;
}
}
switch ( V_71 ) {
case V_76 :
if ( ! F_46 ( V_54 , & V_18 ) )
return - V_13 ;
if ( V_54 -> V_34 == V_38 ) {
F_18 ( V_54 , & V_18 ) ;
return 0 ;
}
V_67 = F_16 ( V_54 , & V_18 ) ;
break;
case V_78 :
if ( V_54 -> V_34 == V_79 )
F_18 ( V_54 , & V_18 ) ;
else
V_67 = F_16 ( V_54 , & V_18 ) ;
if ( V_67 )
break;
V_67 = F_50 ( V_54 , & V_18 ) ;
break;
default:
V_67 = - V_77 ;
}
return V_67 ;
}
static int F_56 ( struct V_2 * V_4 ,
struct V_51 * V_52 , const char * V_72 )
{
int V_80 ;
F_26 ( & V_21 ) ;
V_80 = F_54 ( F_1 ( V_4 ) ,
V_52 -> V_81 , V_72 ) ;
F_27 ( & V_21 ) ;
return V_80 ;
}
static int F_57 ( short type , T_1 V_28 , T_1 V_29 ,
short V_30 )
{
struct V_1 * V_1 ;
struct V_17 V_18 ;
int V_67 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . type = type ;
V_18 . V_28 = V_28 ;
V_18 . V_29 = V_29 ;
V_18 . V_30 = V_30 ;
F_38 () ;
V_1 = F_3 ( V_11 ) ;
V_67 = F_42 ( V_1 , & V_18 , V_1 -> V_34 ) ;
F_41 () ;
if ( ! V_67 )
return - V_13 ;
return 0 ;
}
int F_58 ( struct V_82 * V_82 , int V_83 )
{
short type , V_30 = 0 ;
if ( F_59 ( V_82 -> V_84 ) )
type = V_48 ;
if ( F_60 ( V_82 -> V_84 ) )
type = V_47 ;
if ( V_83 & V_85 )
V_30 |= V_44 ;
if ( V_83 & V_86 )
V_30 |= V_43 ;
return F_57 ( type , F_61 ( V_82 ) , F_62 ( V_82 ) ,
V_30 ) ;
}
int F_63 ( int V_87 , T_2 V_88 )
{
short type ;
if ( ! F_59 ( V_87 ) && ! F_60 ( V_87 ) )
return 0 ;
if ( F_59 ( V_87 ) )
type = V_48 ;
else
type = V_47 ;
return F_57 ( type , F_64 ( V_88 ) , F_65 ( V_88 ) ,
V_45 ) ;
}
