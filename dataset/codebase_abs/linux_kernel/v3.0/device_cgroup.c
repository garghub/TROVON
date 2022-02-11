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
static int F_6 ( struct V_9 * V_10 ,
struct V_5 * V_11 , struct V_7 * V_8 )
{
if ( V_12 != V_8 && ! F_7 ( V_13 ) )
return - V_14 ;
return 0 ;
}
static int F_8 ( struct V_15 * V_16 , struct V_15 * V_17 )
{
struct V_18 * V_19 , * V_20 , * V_21 ;
F_9 (wh, orig, list) {
V_21 = F_10 ( V_19 , sizeof( * V_19 ) , V_22 ) ;
if ( ! V_21 )
goto V_23;
F_11 ( & V_21 -> V_24 , V_16 ) ;
}
return 0 ;
V_23:
F_12 (wh, tmp, dest, list) {
F_13 ( & V_19 -> V_24 ) ;
F_14 ( V_19 ) ;
}
return - V_25 ;
}
static int F_15 ( struct V_1 * V_1 ,
struct V_18 * V_19 )
{
struct V_18 * V_26 , * V_27 ;
V_26 = F_10 ( V_19 , sizeof( * V_19 ) , V_22 ) ;
if ( ! V_26 )
return - V_25 ;
F_9 (walk, &dev_cgroup->whitelist, list) {
if ( V_27 -> type != V_19 -> type )
continue;
if ( V_27 -> V_28 != V_19 -> V_28 )
continue;
if ( V_27 -> V_29 != V_19 -> V_29 )
continue;
V_27 -> V_30 |= V_19 -> V_30 ;
F_14 ( V_26 ) ;
V_26 = NULL ;
}
if ( V_26 != NULL )
F_16 ( & V_26 -> V_24 , & V_1 -> V_31 ) ;
return 0 ;
}
static void F_17 ( struct V_32 * V_33 )
{
struct V_18 * V_34 ;
V_34 = F_2 ( V_33 , struct V_18 , V_33 ) ;
F_14 ( V_34 ) ;
}
static void F_18 ( struct V_1 * V_1 ,
struct V_18 * V_19 )
{
struct V_18 * V_27 , * V_20 ;
F_12 (walk, tmp, &dev_cgroup->whitelist, list) {
if ( V_27 -> type == V_35 )
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
F_20 ( & V_27 -> V_33 , F_17 ) ;
}
}
}
static struct V_2 * F_21 ( struct V_9 * V_10 ,
struct V_5 * V_5 )
{
struct V_1 * V_1 , * V_36 ;
struct V_5 * V_37 ;
int V_38 ;
V_1 = F_22 ( sizeof( * V_1 ) , V_22 ) ;
if ( ! V_1 )
return F_23 ( - V_25 ) ;
F_24 ( & V_1 -> V_31 ) ;
V_37 = V_5 -> V_39 ;
if ( V_37 == NULL ) {
struct V_18 * V_19 ;
V_19 = F_25 ( sizeof( * V_19 ) , V_22 ) ;
if ( ! V_19 ) {
F_14 ( V_1 ) ;
return F_23 ( - V_25 ) ;
}
V_19 -> V_29 = V_19 -> V_28 = ~ 0 ;
V_19 -> type = V_35 ;
V_19 -> V_30 = V_40 ;
F_26 ( & V_19 -> V_24 , & V_1 -> V_31 ) ;
} else {
V_36 = F_3 ( V_37 ) ;
F_27 ( & V_41 ) ;
V_38 = F_8 ( & V_1 -> V_31 ,
& V_36 -> V_31 ) ;
F_28 ( & V_41 ) ;
if ( V_38 ) {
F_14 ( V_1 ) ;
return F_23 ( V_38 ) ;
}
}
return & V_1 -> V_4 ;
}
static void F_29 ( struct V_9 * V_10 ,
struct V_5 * V_5 )
{
struct V_1 * V_1 ;
struct V_18 * V_19 , * V_20 ;
V_1 = F_3 ( V_5 ) ;
F_12 (wh, tmp, &dev_cgroup->whitelist, list) {
F_13 ( & V_19 -> V_24 ) ;
F_14 ( V_19 ) ;
}
F_14 ( V_1 ) ;
}
static void F_30 ( char * V_42 , short V_30 )
{
int V_43 = 0 ;
memset ( V_42 , 0 , V_44 ) ;
if ( V_30 & V_45 )
V_42 [ V_43 ++ ] = 'r' ;
if ( V_30 & V_46 )
V_42 [ V_43 ++ ] = 'w' ;
if ( V_30 & V_47 )
V_42 [ V_43 ++ ] = 'm' ;
}
static char F_31 ( short type )
{
if ( type == V_35 )
return 'a' ;
if ( type == V_48 )
return 'c' ;
if ( type == V_49 )
return 'b' ;
return 'X' ;
}
static void F_32 ( char * V_50 , unsigned V_51 )
{
if ( V_51 == ~ 0 )
strcpy ( V_50 , L_1 ) ;
else
sprintf ( V_50 , L_2 , V_51 ) ;
}
static int F_33 ( struct V_5 * V_5 , struct V_52 * V_53 ,
struct V_54 * V_51 )
{
struct V_1 * V_55 = F_3 ( V_5 ) ;
struct V_18 * V_19 ;
char V_56 [ V_57 ] , V_58 [ V_57 ] , V_42 [ V_44 ] ;
F_34 () ;
F_35 (wh, &devcgroup->whitelist, list) {
F_30 ( V_42 , V_19 -> V_30 ) ;
F_32 ( V_56 , V_19 -> V_28 ) ;
F_32 ( V_58 , V_19 -> V_29 ) ;
F_36 ( V_51 , L_3 , F_31 ( V_19 -> type ) ,
V_56 , V_58 , V_42 ) ;
}
F_37 () ;
return 0 ;
}
static int F_38 ( struct V_1 * V_59 ,
struct V_18 * V_60 )
{
struct V_18 * V_61 ;
F_9 (whitem, &c->whitelist, list) {
if ( V_61 -> type & V_35 )
return 1 ;
if ( ( V_60 -> type & V_49 ) && ! ( V_61 -> type & V_49 ) )
continue;
if ( ( V_60 -> type & V_48 ) && ! ( V_61 -> type & V_48 ) )
continue;
if ( V_61 -> V_28 != ~ 0 && V_61 -> V_28 != V_60 -> V_28 )
continue;
if ( V_61 -> V_29 != ~ 0 && V_61 -> V_29 != V_60 -> V_29 )
continue;
if ( V_60 -> V_30 & ( ~ V_61 -> V_30 ) )
continue;
return 1 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_62 ,
struct V_18 * V_19 )
{
struct V_5 * V_63 = V_62 -> V_4 . V_5 -> V_39 ;
struct V_1 * V_39 ;
if ( ! V_63 )
return 1 ;
V_39 = F_3 ( V_63 ) ;
return F_38 ( V_39 , V_19 ) ;
}
static int F_40 ( struct V_1 * V_55 ,
int V_64 , const char * V_65 )
{
const char * V_66 ;
char * V_67 ;
int V_68 ;
struct V_18 V_19 ;
if ( ! F_7 ( V_13 ) )
return - V_14 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_66 = V_65 ;
switch ( * V_66 ) {
case 'a' :
V_19 . type = V_35 ;
V_19 . V_30 = V_40 ;
V_19 . V_28 = ~ 0 ;
V_19 . V_29 = ~ 0 ;
goto V_69;
case 'b' :
V_19 . type = V_49 ;
break;
case 'c' :
V_19 . type = V_48 ;
break;
default:
return - V_70 ;
}
V_66 ++ ;
if ( ! isspace ( * V_66 ) )
return - V_70 ;
V_66 ++ ;
if ( * V_66 == '*' ) {
V_19 . V_28 = ~ 0 ;
V_66 ++ ;
} else if ( isdigit ( * V_66 ) ) {
V_19 . V_28 = F_41 ( V_66 , & V_67 , 10 ) ;
V_66 = V_67 ;
} else {
return - V_70 ;
}
if ( * V_66 != ':' )
return - V_70 ;
V_66 ++ ;
if ( * V_66 == '*' ) {
V_19 . V_29 = ~ 0 ;
V_66 ++ ;
} else if ( isdigit ( * V_66 ) ) {
V_19 . V_29 = F_41 ( V_66 , & V_67 , 10 ) ;
V_66 = V_67 ;
} else {
return - V_70 ;
}
if ( ! isspace ( * V_66 ) )
return - V_70 ;
for ( V_66 ++ , V_68 = 0 ; V_68 < 3 ; V_68 ++ , V_66 ++ ) {
switch ( * V_66 ) {
case 'r' :
V_19 . V_30 |= V_45 ;
break;
case 'w' :
V_19 . V_30 |= V_46 ;
break;
case 'm' :
V_19 . V_30 |= V_47 ;
break;
case '\n' :
case '\0' :
V_68 = 3 ;
break;
default:
return - V_70 ;
}
}
V_69:
switch ( V_64 ) {
case V_71 :
if ( ! F_39 ( V_55 , & V_19 ) )
return - V_14 ;
return F_15 ( V_55 , & V_19 ) ;
case V_72 :
F_18 ( V_55 , & V_19 ) ;
break;
default:
return - V_70 ;
}
return 0 ;
}
static int F_42 ( struct V_5 * V_73 , struct V_52 * V_53 ,
const char * V_65 )
{
int V_74 ;
F_27 ( & V_41 ) ;
V_74 = F_40 ( F_3 ( V_73 ) ,
V_53 -> V_75 , V_65 ) ;
F_28 ( & V_41 ) ;
return V_74 ;
}
static int F_43 ( struct V_9 * V_10 ,
struct V_5 * V_5 )
{
return F_44 ( V_5 , V_10 , V_76 ,
F_45 ( V_76 ) ) ;
}
int F_46 ( struct V_77 * V_77 , int V_78 )
{
struct V_1 * V_1 ;
struct V_18 * V_19 ;
F_34 () ;
V_1 = F_4 ( V_12 ) ;
F_35 (wh, &dev_cgroup->whitelist, list) {
if ( V_19 -> type & V_35 )
goto V_79;
if ( ( V_19 -> type & V_49 ) && ! F_47 ( V_77 -> V_80 ) )
continue;
if ( ( V_19 -> type & V_48 ) && ! F_48 ( V_77 -> V_80 ) )
continue;
if ( V_19 -> V_28 != ~ 0 && V_19 -> V_28 != F_49 ( V_77 ) )
continue;
if ( V_19 -> V_29 != ~ 0 && V_19 -> V_29 != F_50 ( V_77 ) )
continue;
if ( ( V_78 & V_81 ) && ! ( V_19 -> V_30 & V_46 ) )
continue;
if ( ( V_78 & V_82 ) && ! ( V_19 -> V_30 & V_45 ) )
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
if ( V_19 -> type & V_35 )
goto V_79;
if ( ( V_19 -> type & V_49 ) && ! F_47 ( V_83 ) )
continue;
if ( ( V_19 -> type & V_48 ) && ! F_48 ( V_83 ) )
continue;
if ( V_19 -> V_28 != ~ 0 && V_19 -> V_28 != F_52 ( V_84 ) )
continue;
if ( V_19 -> V_29 != ~ 0 && V_19 -> V_29 != F_53 ( V_84 ) )
continue;
if ( ! ( V_19 -> V_30 & V_47 ) )
continue;
V_79:
F_37 () ;
return 0 ;
}
F_37 () ;
return - V_14 ;
}
