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
F_10 (wh, orig, list) {
V_21 = F_11 ( V_19 , sizeof( * V_19 ) , V_22 ) ;
if ( ! V_21 )
goto V_23;
F_12 ( & V_21 -> V_24 , V_16 ) ;
}
return 0 ;
V_23:
F_13 (wh, tmp, dest, list) {
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
F_10 (walk, &dev_cgroup->whitelist, list) {
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
F_13 (walk, tmp, &dev_cgroup->whitelist, list) {
if ( V_27 -> type == V_32 )
goto remove;
if ( V_27 -> type != V_19 -> type )
continue;
if ( V_27 -> V_28 != ~ 0 && V_27 -> V_28 != V_19 -> V_28 )
continue;
if ( V_27 -> V_29 != ~ 0 && V_27 -> V_29 != V_19 -> V_29 )
continue;
remove:
V_27 -> V_30 &= ~ V_19 -> V_30 ;
if ( ! V_27 -> V_30 ) {
F_19 ( & V_27 -> V_24 ) ;
F_20 ( V_27 , V_33 ) ;
}
}
}
static struct V_2 * F_21 ( struct V_5 * V_5 )
{
struct V_1 * V_1 , * V_34 ;
struct V_5 * V_35 ;
int V_36 ;
V_1 = F_22 ( sizeof( * V_1 ) , V_22 ) ;
if ( ! V_1 )
return F_23 ( - V_25 ) ;
F_24 ( & V_1 -> V_31 ) ;
V_35 = V_5 -> V_37 ;
if ( V_35 == NULL ) {
struct V_18 * V_19 ;
V_19 = F_25 ( sizeof( * V_19 ) , V_22 ) ;
if ( ! V_19 ) {
F_15 ( V_1 ) ;
return F_23 ( - V_25 ) ;
}
V_19 -> V_29 = V_19 -> V_28 = ~ 0 ;
V_19 -> type = V_32 ;
V_19 -> V_30 = V_38 ;
F_26 ( & V_19 -> V_24 , & V_1 -> V_31 ) ;
} else {
V_34 = F_3 ( V_35 ) ;
F_27 ( & V_39 ) ;
V_36 = F_9 ( & V_1 -> V_31 ,
& V_34 -> V_31 ) ;
F_28 ( & V_39 ) ;
if ( V_36 ) {
F_15 ( V_1 ) ;
return F_23 ( V_36 ) ;
}
}
return & V_1 -> V_4 ;
}
static void F_29 ( struct V_5 * V_5 )
{
struct V_1 * V_1 ;
struct V_18 * V_19 , * V_20 ;
V_1 = F_3 ( V_5 ) ;
F_13 (wh, tmp, &dev_cgroup->whitelist, list) {
F_14 ( & V_19 -> V_24 ) ;
F_15 ( V_19 ) ;
}
F_15 ( V_1 ) ;
}
static void F_30 ( char * V_40 , short V_30 )
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
static char F_31 ( short type )
{
if ( type == V_32 )
return 'a' ;
if ( type == V_46 )
return 'c' ;
if ( type == V_47 )
return 'b' ;
return 'X' ;
}
static void F_32 ( char * V_48 , unsigned V_49 )
{
if ( V_49 == ~ 0 )
strcpy ( V_48 , L_1 ) ;
else
sprintf ( V_48 , L_2 , V_49 ) ;
}
static int F_33 ( struct V_5 * V_5 , struct V_50 * V_51 ,
struct V_52 * V_49 )
{
struct V_1 * V_53 = F_3 ( V_5 ) ;
struct V_18 * V_19 ;
char V_54 [ V_55 ] , V_56 [ V_55 ] , V_40 [ V_42 ] ;
F_34 () ;
F_35 (wh, &devcgroup->whitelist, list) {
F_30 ( V_40 , V_19 -> V_30 ) ;
F_32 ( V_54 , V_19 -> V_28 ) ;
F_32 ( V_56 , V_19 -> V_29 ) ;
F_36 ( V_49 , L_3 , F_31 ( V_19 -> type ) ,
V_54 , V_56 , V_40 ) ;
}
F_37 () ;
return 0 ;
}
static int F_38 ( struct V_1 * V_57 ,
struct V_18 * V_58 )
{
struct V_18 * V_59 ;
F_10 (whitem, &c->whitelist, list) {
if ( V_59 -> type & V_32 )
return 1 ;
if ( ( V_58 -> type & V_47 ) && ! ( V_59 -> type & V_47 ) )
continue;
if ( ( V_58 -> type & V_46 ) && ! ( V_59 -> type & V_46 ) )
continue;
if ( V_59 -> V_28 != ~ 0 && V_59 -> V_28 != V_58 -> V_28 )
continue;
if ( V_59 -> V_29 != ~ 0 && V_59 -> V_29 != V_58 -> V_29 )
continue;
if ( V_58 -> V_30 & ( ~ V_59 -> V_30 ) )
continue;
return 1 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_60 ,
struct V_18 * V_19 )
{
struct V_5 * V_61 = V_60 -> V_4 . V_5 -> V_37 ;
struct V_1 * V_37 ;
if ( ! V_61 )
return 1 ;
V_37 = F_3 ( V_61 ) ;
return F_38 ( V_37 , V_19 ) ;
}
static int F_40 ( struct V_1 * V_53 ,
int V_62 , const char * V_63 )
{
const char * V_64 ;
char * V_65 ;
int V_66 ;
struct V_18 V_19 ;
if ( ! F_8 ( V_13 ) )
return - V_14 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_64 = V_63 ;
switch ( * V_64 ) {
case 'a' :
V_19 . type = V_32 ;
V_19 . V_30 = V_38 ;
V_19 . V_28 = ~ 0 ;
V_19 . V_29 = ~ 0 ;
goto V_67;
case 'b' :
V_19 . type = V_47 ;
break;
case 'c' :
V_19 . type = V_46 ;
break;
default:
return - V_68 ;
}
V_64 ++ ;
if ( ! isspace ( * V_64 ) )
return - V_68 ;
V_64 ++ ;
if ( * V_64 == '*' ) {
V_19 . V_28 = ~ 0 ;
V_64 ++ ;
} else if ( isdigit ( * V_64 ) ) {
V_19 . V_28 = F_41 ( V_64 , & V_65 , 10 ) ;
V_64 = V_65 ;
} else {
return - V_68 ;
}
if ( * V_64 != ':' )
return - V_68 ;
V_64 ++ ;
if ( * V_64 == '*' ) {
V_19 . V_29 = ~ 0 ;
V_64 ++ ;
} else if ( isdigit ( * V_64 ) ) {
V_19 . V_29 = F_41 ( V_64 , & V_65 , 10 ) ;
V_64 = V_65 ;
} else {
return - V_68 ;
}
if ( ! isspace ( * V_64 ) )
return - V_68 ;
for ( V_64 ++ , V_66 = 0 ; V_66 < 3 ; V_66 ++ , V_64 ++ ) {
switch ( * V_64 ) {
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
V_66 = 3 ;
break;
default:
return - V_68 ;
}
}
V_67:
switch ( V_62 ) {
case V_69 :
if ( ! F_39 ( V_53 , & V_19 ) )
return - V_14 ;
return F_16 ( V_53 , & V_19 ) ;
case V_70 :
F_18 ( V_53 , & V_19 ) ;
break;
default:
return - V_68 ;
}
return 0 ;
}
static int F_42 ( struct V_5 * V_71 , struct V_50 * V_51 ,
const char * V_63 )
{
int V_72 ;
F_27 ( & V_39 ) ;
V_72 = F_40 ( F_3 ( V_71 ) ,
V_51 -> V_73 , V_63 ) ;
F_28 ( & V_39 ) ;
return V_72 ;
}
static int F_43 ( struct V_74 * V_75 ,
struct V_5 * V_5 )
{
return F_44 ( V_5 , V_75 , V_76 ,
F_45 ( V_76 ) ) ;
}
int F_46 ( struct V_77 * V_77 , int V_78 )
{
struct V_1 * V_1 ;
struct V_18 * V_19 ;
F_34 () ;
V_1 = F_4 ( V_12 ) ;
F_35 (wh, &dev_cgroup->whitelist, list) {
if ( V_19 -> type & V_32 )
goto V_79;
if ( ( V_19 -> type & V_47 ) && ! F_47 ( V_77 -> V_80 ) )
continue;
if ( ( V_19 -> type & V_46 ) && ! F_48 ( V_77 -> V_80 ) )
continue;
if ( V_19 -> V_28 != ~ 0 && V_19 -> V_28 != F_49 ( V_77 ) )
continue;
if ( V_19 -> V_29 != ~ 0 && V_19 -> V_29 != F_50 ( V_77 ) )
continue;
if ( ( V_78 & V_81 ) && ! ( V_19 -> V_30 & V_44 ) )
continue;
if ( ( V_78 & V_82 ) && ! ( V_19 -> V_30 & V_43 ) )
continue;
V_79:
F_37 () ;
return 0 ;
}
F_37 () ;
return - V_14 ;
}
int F_51 ( int V_83 , T_1 V_84 )
{
struct V_1 * V_1 ;
struct V_18 * V_19 ;
if ( ! F_47 ( V_83 ) && ! F_48 ( V_83 ) )
return 0 ;
F_34 () ;
V_1 = F_4 ( V_12 ) ;
F_35 (wh, &dev_cgroup->whitelist, list) {
if ( V_19 -> type & V_32 )
goto V_79;
if ( ( V_19 -> type & V_47 ) && ! F_47 ( V_83 ) )
continue;
if ( ( V_19 -> type & V_46 ) && ! F_48 ( V_83 ) )
continue;
if ( V_19 -> V_28 != ~ 0 && V_19 -> V_28 != F_52 ( V_84 ) )
continue;
if ( V_19 -> V_29 != ~ 0 && V_19 -> V_29 != F_53 ( V_84 ) )
continue;
if ( ! ( V_19 -> V_30 & V_45 ) )
continue;
V_79:
F_37 () ;
return 0 ;
}
F_37 () ;
return - V_14 ;
}
