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
F_10 (ex, orig, list) {
V_21 = F_11 ( V_19 , sizeof( * V_19 ) , V_22 ) ;
if ( ! V_21 )
goto V_23;
F_12 ( & V_21 -> V_24 , V_16 ) ;
}
return 0 ;
V_23:
F_13 (ex, tmp, dest, list) {
F_14 ( & V_19 -> V_24 ) ;
F_15 ( V_19 ) ;
}
return - V_25 ;
}
static int F_16 ( struct V_1 * V_1 ,
struct V_18 * V_19 )
{
struct V_18 * V_26 , * V_27 ;
V_26 = F_11 ( V_19 , sizeof( * V_19 ) , V_22 ) ;
if ( ! V_26 )
return - V_25 ;
F_10 (walk, &dev_cgroup->exceptions, list) {
if ( V_27 -> type != V_19 -> type )
continue;
if ( V_27 -> V_28 != V_19 -> V_28 )
continue;
if ( V_27 -> V_29 != V_19 -> V_29 )
continue;
V_27 -> V_30 |= V_19 -> V_30 ;
F_15 ( V_26 ) ;
V_26 = NULL ;
}
if ( V_26 != NULL )
F_17 ( & V_26 -> V_24 , & V_1 -> V_31 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_1 ,
struct V_18 * V_19 )
{
struct V_18 * V_27 , * V_20 ;
F_13 (walk, tmp, &dev_cgroup->exceptions, list) {
if ( V_27 -> type != V_19 -> type )
continue;
if ( V_27 -> V_28 != V_19 -> V_28 )
continue;
if ( V_27 -> V_29 != V_19 -> V_29 )
continue;
V_27 -> V_30 &= ~ V_19 -> V_30 ;
if ( ! V_27 -> V_30 ) {
F_19 ( & V_27 -> V_24 ) ;
F_20 ( V_27 , V_32 ) ;
}
}
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_18 * V_19 , * V_20 ;
F_13 (ex, tmp, &dev_cgroup->exceptions, list) {
F_19 ( & V_19 -> V_24 ) ;
F_20 ( V_19 , V_32 ) ;
}
}
static struct V_2 * F_22 ( struct V_5 * V_5 )
{
struct V_1 * V_1 , * V_33 ;
struct V_5 * V_34 ;
int V_35 ;
V_1 = F_23 ( sizeof( * V_1 ) , V_22 ) ;
if ( ! V_1 )
return F_24 ( - V_25 ) ;
F_25 ( & V_1 -> V_31 ) ;
V_34 = V_5 -> V_36 ;
if ( V_34 == NULL )
V_1 -> V_37 = V_38 ;
else {
V_33 = F_3 ( V_34 ) ;
F_26 ( & V_39 ) ;
V_35 = F_9 ( & V_1 -> V_31 ,
& V_33 -> V_31 ) ;
V_1 -> V_37 = V_33 -> V_37 ;
F_27 ( & V_39 ) ;
if ( V_35 ) {
F_15 ( V_1 ) ;
return F_24 ( V_35 ) ;
}
}
return & V_1 -> V_4 ;
}
static void F_28 ( struct V_5 * V_5 )
{
struct V_1 * V_1 ;
V_1 = F_3 ( V_5 ) ;
F_21 ( V_1 ) ;
F_15 ( V_1 ) ;
}
static void F_29 ( char * V_40 , short V_30 )
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
static char F_30 ( short type )
{
if ( type == V_46 )
return 'a' ;
if ( type == V_47 )
return 'c' ;
if ( type == V_48 )
return 'b' ;
return 'X' ;
}
static void F_31 ( char * V_49 , unsigned V_50 )
{
if ( V_50 == ~ 0 )
strcpy ( V_49 , L_1 ) ;
else
sprintf ( V_49 , L_2 , V_50 ) ;
}
static int F_32 ( struct V_5 * V_5 , struct V_51 * V_52 ,
struct V_53 * V_50 )
{
struct V_1 * V_54 = F_3 ( V_5 ) ;
struct V_18 * V_19 ;
char V_55 [ V_56 ] , V_57 [ V_56 ] , V_40 [ V_42 ] ;
F_33 () ;
if ( V_54 -> V_37 == V_38 ) {
F_29 ( V_40 , V_58 ) ;
F_31 ( V_55 , ~ 0 ) ;
F_31 ( V_57 , ~ 0 ) ;
F_34 ( V_50 , L_3 , F_30 ( V_46 ) ,
V_55 , V_57 , V_40 ) ;
} else {
F_35 (ex, &devcgroup->exceptions, list) {
F_29 ( V_40 , V_19 -> V_30 ) ;
F_31 ( V_55 , V_19 -> V_28 ) ;
F_31 ( V_57 , V_19 -> V_29 ) ;
F_34 ( V_50 , L_3 , F_30 ( V_19 -> type ) ,
V_55 , V_57 , V_40 ) ;
}
}
F_36 () ;
return 0 ;
}
static int F_37 ( struct V_1 * V_1 ,
struct V_18 * V_59 )
{
struct V_18 * V_19 ;
bool V_60 = false ;
F_35 (ex, &dev_cgroup->exceptions, list) {
if ( ( V_59 -> type & V_48 ) && ! ( V_19 -> type & V_48 ) )
continue;
if ( ( V_59 -> type & V_47 ) && ! ( V_19 -> type & V_47 ) )
continue;
if ( V_19 -> V_28 != ~ 0 && V_19 -> V_28 != V_59 -> V_28 )
continue;
if ( V_19 -> V_29 != ~ 0 && V_19 -> V_29 != V_59 -> V_29 )
continue;
if ( V_59 -> V_30 & ( ~ V_19 -> V_30 ) )
continue;
V_60 = true ;
break;
}
if ( ( V_1 -> V_37 == V_61 ) == V_60 )
return 1 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_62 ,
struct V_18 * V_19 )
{
struct V_5 * V_63 = V_62 -> V_4 . V_5 -> V_36 ;
struct V_1 * V_36 ;
if ( ! V_63 )
return 1 ;
V_36 = F_3 ( V_63 ) ;
return F_37 ( V_36 , V_19 ) ;
}
static inline int F_39 ( struct V_1 * V_36 )
{
if ( ! V_36 )
return 1 ;
return V_36 -> V_37 == V_38 ;
}
static int F_40 ( struct V_1 * V_54 ,
int V_64 , const char * V_65 )
{
const char * V_66 ;
char V_67 [ 12 ] ;
int V_68 , V_69 ;
struct V_18 V_19 ;
struct V_5 * V_70 = V_54 -> V_4 . V_5 ;
struct V_1 * V_36 = NULL ;
if ( ! F_8 ( V_13 ) )
return - V_14 ;
if ( V_70 -> V_36 )
V_36 = F_3 ( V_70 -> V_36 ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_66 = V_65 ;
switch ( * V_66 ) {
case 'a' :
switch ( V_64 ) {
case V_71 :
if ( ! F_39 ( V_36 ) )
return - V_14 ;
F_21 ( V_54 ) ;
V_54 -> V_37 = V_38 ;
if ( ! V_36 )
break;
V_69 = F_9 ( & V_54 -> V_31 ,
& V_36 -> V_31 ) ;
if ( V_69 )
return V_69 ;
break;
case V_72 :
F_21 ( V_54 ) ;
V_54 -> V_37 = V_61 ;
break;
default:
return - V_73 ;
}
return 0 ;
case 'b' :
V_19 . type = V_48 ;
break;
case 'c' :
V_19 . type = V_47 ;
break;
default:
return - V_73 ;
}
V_66 ++ ;
if ( ! isspace ( * V_66 ) )
return - V_73 ;
V_66 ++ ;
if ( * V_66 == '*' ) {
V_19 . V_28 = ~ 0 ;
V_66 ++ ;
} else if ( isdigit ( * V_66 ) ) {
memset ( V_67 , 0 , sizeof( V_67 ) ) ;
for ( V_68 = 0 ; V_68 < sizeof( V_67 ) - 1 ; V_68 ++ ) {
V_67 [ V_68 ] = * V_66 ;
V_66 ++ ;
if ( ! isdigit ( * V_66 ) )
break;
}
V_69 = F_41 ( V_67 , 10 , & V_19 . V_28 ) ;
if ( V_69 )
return - V_73 ;
} else {
return - V_73 ;
}
if ( * V_66 != ':' )
return - V_73 ;
V_66 ++ ;
if ( * V_66 == '*' ) {
V_19 . V_29 = ~ 0 ;
V_66 ++ ;
} else if ( isdigit ( * V_66 ) ) {
memset ( V_67 , 0 , sizeof( V_67 ) ) ;
for ( V_68 = 0 ; V_68 < sizeof( V_67 ) - 1 ; V_68 ++ ) {
V_67 [ V_68 ] = * V_66 ;
V_66 ++ ;
if ( ! isdigit ( * V_66 ) )
break;
}
V_69 = F_41 ( V_67 , 10 , & V_19 . V_29 ) ;
if ( V_69 )
return - V_73 ;
} else {
return - V_73 ;
}
if ( ! isspace ( * V_66 ) )
return - V_73 ;
for ( V_66 ++ , V_68 = 0 ; V_68 < 3 ; V_68 ++ , V_66 ++ ) {
switch ( * V_66 ) {
case 'r' :
V_19 . V_30 |= V_43 ;
break;
case 'w' :
V_19 . V_30 |= V_44 ;
break;
case 'm' :
V_19 . V_30 |= V_45 ;
break;
case '\n' :
case '\0' :
V_68 = 3 ;
break;
default:
return - V_73 ;
}
}
switch ( V_64 ) {
case V_71 :
if ( ! F_38 ( V_54 , & V_19 ) )
return - V_14 ;
if ( V_54 -> V_37 == V_38 ) {
F_18 ( V_54 , & V_19 ) ;
return 0 ;
}
return F_16 ( V_54 , & V_19 ) ;
case V_72 :
if ( V_54 -> V_37 == V_61 ) {
F_18 ( V_54 , & V_19 ) ;
return 0 ;
}
return F_16 ( V_54 , & V_19 ) ;
default:
return - V_73 ;
}
return 0 ;
}
static int F_42 ( struct V_5 * V_74 , struct V_51 * V_52 ,
const char * V_65 )
{
int V_75 ;
F_26 ( & V_39 ) ;
V_75 = F_40 ( F_3 ( V_74 ) ,
V_52 -> V_76 , V_65 ) ;
F_27 ( & V_39 ) ;
return V_75 ;
}
static int F_43 ( short type , T_1 V_28 , T_1 V_29 ,
short V_30 )
{
struct V_1 * V_1 ;
struct V_18 V_19 ;
int V_69 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . type = type ;
V_19 . V_28 = V_28 ;
V_19 . V_29 = V_29 ;
V_19 . V_30 = V_30 ;
F_33 () ;
V_1 = F_4 ( V_12 ) ;
V_69 = F_37 ( V_1 , & V_19 ) ;
F_36 () ;
if ( ! V_69 )
return - V_14 ;
return 0 ;
}
int F_44 ( struct V_77 * V_77 , int V_78 )
{
short type , V_30 = 0 ;
if ( F_45 ( V_77 -> V_79 ) )
type = V_48 ;
if ( F_46 ( V_77 -> V_79 ) )
type = V_47 ;
if ( V_78 & V_80 )
V_30 |= V_44 ;
if ( V_78 & V_81 )
V_30 |= V_43 ;
return F_43 ( type , F_47 ( V_77 ) , F_48 ( V_77 ) ,
V_30 ) ;
}
int F_49 ( int V_82 , T_2 V_83 )
{
short type ;
if ( ! F_45 ( V_82 ) && ! F_46 ( V_82 ) )
return 0 ;
if ( F_45 ( V_82 ) )
type = V_48 ;
else
type = V_47 ;
return F_43 ( type , F_50 ( V_83 ) , F_51 ( V_83 ) ,
V_45 ) ;
}
