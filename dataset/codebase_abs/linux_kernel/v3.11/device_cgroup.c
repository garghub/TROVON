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
static void F_34 ( char * V_41 , short V_31 )
{
int V_42 = 0 ;
memset ( V_41 , 0 , V_43 ) ;
if ( V_31 & V_44 )
V_41 [ V_42 ++ ] = 'r' ;
if ( V_31 & V_45 )
V_41 [ V_42 ++ ] = 'w' ;
if ( V_31 & V_46 )
V_41 [ V_42 ++ ] = 'm' ;
}
static char F_35 ( short type )
{
if ( type == V_47 )
return 'a' ;
if ( type == V_48 )
return 'c' ;
if ( type == V_49 )
return 'b' ;
return 'X' ;
}
static void F_36 ( char * V_50 , unsigned V_51 )
{
if ( V_51 == ~ 0 )
strcpy ( V_50 , L_1 ) ;
else
sprintf ( V_50 , L_2 , V_51 ) ;
}
static int F_37 ( struct V_5 * V_5 , struct V_52 * V_53 ,
struct V_54 * V_51 )
{
struct V_1 * V_55 = F_3 ( V_5 ) ;
struct V_18 * V_19 ;
char V_56 [ V_57 ] , V_58 [ V_57 ] , V_41 [ V_43 ] ;
F_38 () ;
if ( V_55 -> V_35 == V_40 ) {
F_34 ( V_41 , V_59 ) ;
F_36 ( V_56 , ~ 0 ) ;
F_36 ( V_58 , ~ 0 ) ;
F_39 ( V_51 , L_3 , F_35 ( V_47 ) ,
V_56 , V_58 , V_41 ) ;
} else {
F_40 (ex, &devcgroup->exceptions, list) {
F_34 ( V_41 , V_19 -> V_31 ) ;
F_36 ( V_56 , V_19 -> V_29 ) ;
F_36 ( V_58 , V_19 -> V_30 ) ;
F_39 ( V_51 , L_3 , F_35 ( V_19 -> type ) ,
V_56 , V_58 , V_41 ) ;
}
}
F_41 () ;
return 0 ;
}
static bool F_42 ( struct V_1 * V_1 ,
struct V_18 * V_60 ,
enum V_61 V_35 )
{
struct V_18 * V_19 ;
bool V_62 = false ;
F_43 ( F_44 () ||
F_45 ( & V_22 ) ,
L_4 ) ;
F_40 (ex, &dev_cgroup->exceptions, list) {
if ( ( V_60 -> type & V_49 ) && ! ( V_19 -> type & V_49 ) )
continue;
if ( ( V_60 -> type & V_48 ) && ! ( V_19 -> type & V_48 ) )
continue;
if ( V_19 -> V_29 != ~ 0 && V_19 -> V_29 != V_60 -> V_29 )
continue;
if ( V_19 -> V_30 != ~ 0 && V_19 -> V_30 != V_60 -> V_30 )
continue;
if ( V_60 -> V_31 & ( ~ V_19 -> V_31 ) )
continue;
V_62 = true ;
break;
}
if ( V_1 -> V_35 == V_40 ) {
if ( V_35 == V_40 ) {
return true ;
} else {
if ( V_62 )
return false ;
return true ;
}
} else {
if ( V_62 )
return true ;
else
return false ;
}
return false ;
}
static int F_46 ( struct V_1 * V_63 ,
struct V_18 * V_19 )
{
struct V_5 * V_64 = V_63 -> V_4 . V_5 -> V_39 ;
struct V_1 * V_39 ;
if ( ! V_64 )
return 1 ;
V_39 = F_3 ( V_64 ) ;
return F_42 ( V_39 , V_19 , V_63 -> V_35 ) ;
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
struct V_15 * V_65 , * V_20 ;
F_49 (this, tmp, &devcg->exceptions) {
V_19 = F_2 ( V_65 , struct V_18 , V_25 ) ;
if ( ! F_46 ( V_34 , V_19 ) )
F_19 ( V_34 , V_19 ) ;
}
}
static int F_50 ( struct V_1 * V_66 ,
struct V_18 * V_19 )
{
struct V_5 * V_67 = V_66 -> V_4 . V_5 , * V_68 ;
int V_69 = 0 ;
F_38 () ;
F_51 (pos, root) {
struct V_1 * V_34 = F_3 ( V_68 ) ;
if ( ! F_24 ( V_34 ) )
continue;
F_41 () ;
if ( V_66 -> V_35 == V_40 &&
V_34 -> V_35 == V_40 ) {
V_69 = F_17 ( V_34 , V_19 ) ;
if ( V_69 )
break;
} else {
F_19 ( V_34 , V_19 ) ;
}
F_48 ( V_34 ) ;
F_38 () ;
}
F_41 () ;
return V_69 ;
}
static inline bool F_52 ( struct V_1 * V_55 )
{
struct V_5 * V_70 = V_55 -> V_4 . V_5 ;
return ! F_53 ( & V_70 -> V_71 ) ;
}
static int F_54 ( struct V_1 * V_55 ,
int V_72 , const char * V_73 )
{
const char * V_74 ;
char V_75 [ 12 ] ;
int V_76 , V_69 = 0 ;
struct V_18 V_19 ;
struct V_5 * V_77 = V_55 -> V_4 . V_5 ;
struct V_1 * V_39 = NULL ;
if ( ! F_8 ( V_13 ) )
return - V_14 ;
if ( V_77 -> V_39 )
V_39 = F_3 ( V_77 -> V_39 ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_74 = V_73 ;
switch ( * V_74 ) {
case 'a' :
switch ( V_72 ) {
case V_78 :
if ( F_52 ( V_55 ) )
return - V_79 ;
if ( ! F_47 ( V_39 ) )
return - V_14 ;
F_23 ( V_55 ) ;
V_55 -> V_35 = V_40 ;
if ( ! V_39 )
break;
V_69 = F_9 ( & V_55 -> V_32 ,
& V_39 -> V_32 ) ;
if ( V_69 )
return V_69 ;
break;
case V_80 :
if ( F_52 ( V_55 ) )
return - V_79 ;
F_23 ( V_55 ) ;
V_55 -> V_35 = V_81 ;
break;
default:
return - V_79 ;
}
return 0 ;
case 'b' :
V_19 . type = V_49 ;
break;
case 'c' :
V_19 . type = V_48 ;
break;
default:
return - V_79 ;
}
V_74 ++ ;
if ( ! isspace ( * V_74 ) )
return - V_79 ;
V_74 ++ ;
if ( * V_74 == '*' ) {
V_19 . V_29 = ~ 0 ;
V_74 ++ ;
} else if ( isdigit ( * V_74 ) ) {
memset ( V_75 , 0 , sizeof( V_75 ) ) ;
for ( V_76 = 0 ; V_76 < sizeof( V_75 ) - 1 ; V_76 ++ ) {
V_75 [ V_76 ] = * V_74 ;
V_74 ++ ;
if ( ! isdigit ( * V_74 ) )
break;
}
V_69 = F_55 ( V_75 , 10 , & V_19 . V_29 ) ;
if ( V_69 )
return - V_79 ;
} else {
return - V_79 ;
}
if ( * V_74 != ':' )
return - V_79 ;
V_74 ++ ;
if ( * V_74 == '*' ) {
V_19 . V_30 = ~ 0 ;
V_74 ++ ;
} else if ( isdigit ( * V_74 ) ) {
memset ( V_75 , 0 , sizeof( V_75 ) ) ;
for ( V_76 = 0 ; V_76 < sizeof( V_75 ) - 1 ; V_76 ++ ) {
V_75 [ V_76 ] = * V_74 ;
V_74 ++ ;
if ( ! isdigit ( * V_74 ) )
break;
}
V_69 = F_55 ( V_75 , 10 , & V_19 . V_30 ) ;
if ( V_69 )
return - V_79 ;
} else {
return - V_79 ;
}
if ( ! isspace ( * V_74 ) )
return - V_79 ;
for ( V_74 ++ , V_76 = 0 ; V_76 < 3 ; V_76 ++ , V_74 ++ ) {
switch ( * V_74 ) {
case 'r' :
V_19 . V_31 |= V_44 ;
break;
case 'w' :
V_19 . V_31 |= V_45 ;
break;
case 'm' :
V_19 . V_31 |= V_46 ;
break;
case '\n' :
case '\0' :
V_76 = 3 ;
break;
default:
return - V_79 ;
}
}
switch ( V_72 ) {
case V_78 :
if ( ! F_46 ( V_55 , & V_19 ) )
return - V_14 ;
if ( V_55 -> V_35 == V_40 ) {
F_19 ( V_55 , & V_19 ) ;
return 0 ;
}
V_69 = F_17 ( V_55 , & V_19 ) ;
break;
case V_80 :
if ( V_55 -> V_35 == V_81 )
F_19 ( V_55 , & V_19 ) ;
else
V_69 = F_17 ( V_55 , & V_19 ) ;
if ( V_69 )
break;
V_69 = F_50 ( V_55 , & V_19 ) ;
break;
default:
V_69 = - V_79 ;
}
return V_69 ;
}
static int F_56 ( struct V_5 * V_70 , struct V_52 * V_53 ,
const char * V_73 )
{
int V_82 ;
F_26 ( & V_22 ) ;
V_82 = F_54 ( F_3 ( V_70 ) ,
V_53 -> V_83 , V_73 ) ;
F_27 ( & V_22 ) ;
return V_82 ;
}
static int F_57 ( short type , T_1 V_29 , T_1 V_30 ,
short V_31 )
{
struct V_1 * V_1 ;
struct V_18 V_19 ;
int V_69 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . type = type ;
V_19 . V_29 = V_29 ;
V_19 . V_30 = V_30 ;
V_19 . V_31 = V_31 ;
F_38 () ;
V_1 = F_4 ( V_12 ) ;
V_69 = F_42 ( V_1 , & V_19 , V_1 -> V_35 ) ;
F_41 () ;
if ( ! V_69 )
return - V_14 ;
return 0 ;
}
int F_58 ( struct V_84 * V_84 , int V_85 )
{
short type , V_31 = 0 ;
if ( F_59 ( V_84 -> V_86 ) )
type = V_49 ;
if ( F_60 ( V_84 -> V_86 ) )
type = V_48 ;
if ( V_85 & V_87 )
V_31 |= V_45 ;
if ( V_85 & V_88 )
V_31 |= V_44 ;
return F_57 ( type , F_61 ( V_84 ) , F_62 ( V_84 ) ,
V_31 ) ;
}
int F_63 ( int V_89 , T_2 V_90 )
{
short type ;
if ( ! F_59 ( V_89 ) && ! F_60 ( V_89 ) )
return 0 ;
if ( F_59 ( V_89 ) )
type = V_49 ;
else
type = V_48 ;
return F_57 ( type , F_64 ( V_90 ) , F_65 ( V_90 ) ,
V_46 ) ;
}
