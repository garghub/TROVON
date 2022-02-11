static bool F_1 ( const union V_1 * V_2 ,
T_1 V_3 ,
const union V_1 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 ;
bool V_11 ;
V_10 = F_2 ( sizeof( * V_10 ) , V_12 ) ;
if ( ! V_10 )
return false ;
V_10 -> V_13 = V_4 -> V_14 . V_15 [ 0 ] . string . V_16 ;
V_10 -> V_17 . type = V_18 ;
V_10 -> V_8 = V_8 ;
F_3 ( & V_10 -> V_19 . V_20 ) ;
V_11 = F_4 ( V_2 , & V_10 -> V_19 ) ;
if ( V_3 ) {
T_1 V_21 ;
T_2 V_22 ;
V_22 = F_5 ( V_3 , & V_21 ) ;
if ( F_6 ( V_22 )
&& F_7 ( V_21 , V_2 , & V_10 -> V_19 ,
& V_10 -> V_17 ) )
V_11 = true ;
} else if ( F_7 ( NULL , V_2 , & V_10 -> V_19 ,
& V_10 -> V_17 ) ) {
V_11 = true ;
}
if ( V_11 ) {
V_10 -> V_3 = V_3 ;
V_10 -> V_19 . V_16 = V_2 ;
F_8 ( & V_10 -> V_23 , V_6 ) ;
return true ;
}
F_9 ( V_10 ) ;
F_10 ( V_3 , L_1 ) ;
return false ;
}
static bool F_11 ( T_1 V_3 ,
const union V_1 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_24 V_25 = { V_26 } ;
T_2 V_22 ;
V_22 = F_12 ( V_3 , NULL , NULL , & V_25 ,
V_27 ) ;
if ( F_13 ( V_22 ) )
return false ;
if ( F_1 ( V_25 . V_16 , V_3 , V_4 , V_6 ,
V_8 ) )
return true ;
F_14 ( V_25 . V_16 ) ;
return false ;
}
static bool F_15 ( T_1 V_21 ,
const union V_1 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
T_1 V_3 ;
T_2 V_22 ;
if ( ! V_21 )
return false ;
V_22 = F_16 ( V_21 , V_4 -> V_14 . V_15 [ 1 ] . string . V_16 ,
& V_3 ) ;
if ( F_13 ( V_22 ) )
return false ;
return F_11 ( V_3 , V_4 , V_6 , V_8 ) ;
}
static int F_17 ( T_1 V_21 ,
const union V_1 * V_28 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
bool V_29 = false ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_28 -> V_14 . V_31 ; V_30 ++ ) {
const union V_1 * V_4 , * V_2 ;
T_1 V_3 ;
bool V_11 ;
V_4 = & V_28 -> V_14 . V_15 [ V_30 ] ;
if ( V_4 -> V_14 . V_31 != 2 )
continue;
if ( V_4 -> V_14 . V_15 [ 0 ] . type != V_32 )
continue;
switch ( V_4 -> V_14 . V_15 [ 1 ] . type ) {
case V_32 :
V_11 = F_15 ( V_21 , V_4 , V_6 ,
V_8 ) ;
break;
case V_33 :
V_3 = V_4 -> V_14 . V_15 [ 1 ] . V_34 . V_3 ;
V_11 = F_11 ( V_3 , V_4 , V_6 ,
V_8 ) ;
break;
case V_27 :
V_2 = & V_4 -> V_14 . V_15 [ 1 ] ;
V_11 = F_1 ( V_2 , NULL , V_4 ,
V_6 , V_8 ) ;
break;
default:
V_11 = false ;
break;
}
V_29 = V_29 || V_11 ;
}
return V_29 ;
}
static bool F_7 ( T_1 V_21 ,
const union V_1 * V_2 ,
struct V_35 * V_19 ,
struct V_7 * V_8 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_14 . V_31 ; V_30 += 2 ) {
const union V_1 * V_36 , * V_28 ;
V_36 = & V_2 -> V_14 . V_15 [ V_30 ] ;
V_28 = & V_2 -> V_14 . V_15 [ V_30 + 1 ] ;
if ( V_36 -> type != V_37 || V_36 -> V_38 . V_39 != 16
|| V_28 -> type != V_27 )
break;
if ( memcmp ( V_36 -> V_38 . V_16 , V_40 , sizeof( V_40 ) ) )
continue;
return F_17 ( V_21 , V_28 , & V_19 -> V_20 ,
V_8 ) ;
}
return false ;
}
static bool F_18 ( const union V_1 * V_41 )
{
int V_42 ;
switch ( V_41 -> type ) {
case V_43 :
case V_32 :
case V_33 :
return true ;
case V_27 :
for ( V_42 = 0 ; V_42 < V_41 -> V_14 . V_31 ; V_42 ++ )
switch ( V_41 -> V_14 . V_15 [ V_42 ] . type ) {
case V_43 :
case V_32 :
case V_33 :
continue;
default:
return false ;
}
return true ;
}
return false ;
}
static bool F_19 ( const union V_1 * V_44 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_44 -> V_14 . V_31 ; V_30 ++ ) {
const union V_1 * V_45 ;
V_45 = & V_44 -> V_14 . V_15 [ V_30 ] ;
if ( V_45 -> V_14 . V_31 != 2
|| V_45 -> V_14 . V_15 [ 0 ] . type != V_32
|| ! F_18 ( & V_45 -> V_14 . V_15 [ 1 ] ) )
return false ;
}
return true ;
}
static void F_20 ( struct V_46 * V_47 )
{
const union V_1 * V_48 ;
int V_29 ;
V_29 = F_21 ( & V_47 -> V_19 , L_2 ,
V_32 , & V_48 ) ;
if ( V_29 ) {
V_29 = F_22 ( V_47 , L_2 ,
V_32 , & V_48 ) ;
if ( V_29 ) {
if ( V_47 -> V_8
&& V_47 -> V_8 -> V_49 . V_50 )
goto V_51;
return;
}
}
V_47 -> V_19 . V_48 = V_48 ;
V_51:
V_47 -> V_49 . V_50 = 1 ;
}
static bool F_4 ( const union V_1 * V_2 ,
struct V_35 * V_19 )
{
int V_30 ;
if ( V_2 -> V_14 . V_31 % 2 )
return false ;
for ( V_30 = 0 ; V_30 < V_2 -> V_14 . V_31 ; V_30 += 2 ) {
const union V_1 * V_36 , * V_44 ;
V_36 = & V_2 -> V_14 . V_15 [ V_30 ] ;
V_44 = & V_2 -> V_14 . V_15 [ V_30 + 1 ] ;
if ( V_36 -> type != V_37 || V_36 -> V_38 . V_39 != 16
|| V_44 -> type != V_27 )
break;
if ( memcmp ( V_36 -> V_38 . V_16 , V_52 , sizeof( V_52 ) ) )
continue;
if ( ! F_19 ( V_44 ) )
break;
V_19 -> V_44 = V_44 ;
return true ;
}
return false ;
}
void F_23 ( struct V_46 * V_47 )
{
struct V_24 V_25 = { V_26 } ;
struct V_53 * V_54 ;
T_2 V_22 ;
bool V_55 = false ;
F_3 ( & V_47 -> V_19 . V_20 ) ;
F_24 (hwid, &adev->pnp.ids, list) {
if ( ! strcmp ( V_54 -> V_56 , V_57 ) ) {
V_55 = true ;
break;
}
}
V_22 = F_12 ( V_47 -> V_3 , L_3 , NULL , & V_25 ,
V_27 ) ;
if ( F_13 ( V_22 ) )
goto V_51;
if ( F_4 ( V_25 . V_16 , & V_47 -> V_19 ) ) {
V_47 -> V_19 . V_16 = V_25 . V_16 ;
if ( V_55 )
F_20 ( V_47 ) ;
}
if ( F_7 ( V_47 -> V_3 , V_25 . V_16 ,
& V_47 -> V_19 , F_25 ( V_47 ) ) )
V_47 -> V_19 . V_16 = V_25 . V_16 ;
if ( ! V_47 -> V_19 . V_16 ) {
F_10 ( V_47 -> V_3 , L_4 ) ;
F_14 ( V_25 . V_16 ) ;
}
V_51:
if ( V_55 && ! V_47 -> V_49 . V_50 )
F_26 ( V_47 -> V_3 ,
V_57 L_5 ) ;
}
static void F_27 ( struct V_5 * V_6 )
{
struct V_9 * V_10 , * V_58 ;
if ( F_28 ( V_6 ) )
return;
F_29 (dn, next, list, sibling) {
F_27 ( & V_10 -> V_19 . V_20 ) ;
F_30 ( & V_10 -> V_59 ) ;
F_31 ( & V_10 -> V_23 ) ;
F_14 ( ( void * ) V_10 -> V_19 . V_16 ) ;
F_9 ( V_10 ) ;
}
}
void F_32 ( struct V_46 * V_47 )
{
F_27 ( & V_47 -> V_19 . V_20 ) ;
F_14 ( ( void * ) V_47 -> V_19 . V_16 ) ;
V_47 -> V_19 . V_48 = NULL ;
V_47 -> V_19 . V_16 = NULL ;
V_47 -> V_19 . V_44 = NULL ;
}
static int F_33 ( struct V_35 * V_19 ,
const char * V_13 , T_3 type ,
const union V_1 * * V_60 )
{
const union V_1 * V_44 ;
int V_30 ;
if ( ! V_19 || ! V_13 )
return - V_61 ;
if ( ! V_19 -> V_16 || ! V_19 -> V_44 )
return - V_61 ;
V_44 = V_19 -> V_44 ;
for ( V_30 = 0 ; V_30 < V_44 -> V_14 . V_31 ; V_30 ++ ) {
const union V_1 * V_62 , * V_63 ;
const union V_1 * V_45 ;
V_45 = & V_44 -> V_14 . V_15 [ V_30 ] ;
V_62 = & V_45 -> V_14 . V_15 [ 0 ] ;
V_63 = & V_45 -> V_14 . V_15 [ 1 ] ;
if ( ! strcmp ( V_13 , V_62 -> string . V_16 ) ) {
if ( type != V_64 && V_63 -> type != type )
return - V_65 ;
if ( V_60 )
* V_60 = V_63 ;
return 0 ;
}
}
return - V_61 ;
}
int F_22 ( struct V_46 * V_47 , const char * V_13 ,
T_3 type , const union V_1 * * V_60 )
{
return V_47 ? F_33 ( & V_47 -> V_19 , V_13 , type , V_60 ) : - V_61 ;
}
static struct V_35 * F_34 ( struct V_7 * V_17 )
{
if ( V_17 -> type == V_66 ) {
struct V_46 * V_47 = F_35 ( V_17 ) ;
return & V_47 -> V_19 ;
} else if ( V_17 -> type == V_18 ) {
struct V_9 * V_10 = F_36 ( V_17 ) ;
return & V_10 -> V_19 ;
}
return NULL ;
}
int F_37 ( struct V_7 * V_17 , const char * V_62 ,
void * * V_67 )
{
return F_33 ( F_34 ( V_17 ) ,
V_62 , V_64 ,
( const union V_1 * * ) V_67 ) ;
}
static int F_21 ( struct V_35 * V_19 ,
const char * V_13 ,
T_3 type ,
const union V_1 * * V_60 )
{
const union V_1 * V_68 ;
int V_29 , V_30 ;
V_29 = F_33 ( V_19 , V_13 , V_27 , & V_68 ) ;
if ( V_29 )
return V_29 ;
if ( type != V_64 ) {
for ( V_30 = 0 ; V_30 < V_68 -> V_14 . V_31 ; V_30 ++ )
if ( V_68 -> V_14 . V_15 [ V_30 ] . type != type )
return - V_65 ;
}
if ( V_60 )
* V_60 = V_68 ;
return 0 ;
}
int F_38 ( struct V_7 * V_17 ,
const char * V_62 , T_4 V_69 , T_4 V_70 ,
struct V_71 * args )
{
const union V_1 * V_72 , * V_73 ;
const union V_1 * V_60 ;
struct V_35 * V_19 ;
struct V_46 * V_74 ;
int V_29 , V_75 = 0 ;
V_19 = F_34 ( V_17 ) ;
if ( ! V_19 )
return - V_61 ;
V_29 = F_33 ( V_19 , V_62 , V_64 , & V_60 ) ;
if ( V_29 )
return V_29 ;
if ( V_60 -> type == V_33 ) {
if ( V_69 )
return - V_61 ;
V_29 = F_39 ( V_60 -> V_34 . V_3 , & V_74 ) ;
if ( V_29 )
return V_29 ;
args -> V_47 = V_74 ;
args -> V_76 = 0 ;
return 0 ;
}
if ( V_60 -> type != V_27 || V_69 >= V_60 -> V_14 . V_31 )
return - V_65 ;
V_72 = V_60 -> V_14 . V_15 ;
V_73 = V_72 + V_60 -> V_14 . V_31 ;
while ( V_72 < V_73 ) {
T_5 V_76 , V_30 ;
if ( V_72 -> type == V_33 ) {
V_29 = F_39 ( V_72 -> V_34 . V_3 ,
& V_74 ) ;
if ( V_29 )
return - V_77 ;
V_76 = 0 ;
V_72 ++ ;
for ( V_30 = 0 ; V_72 + V_30 < V_73 && V_30 < V_70 ; V_30 ++ ) {
int type = V_72 [ V_30 ] . type ;
if ( type == V_43 )
V_76 ++ ;
else if ( type == V_33 )
break;
else
return - V_65 ;
}
if ( V_76 > V_78 )
return - V_65 ;
if ( V_75 == V_69 ) {
args -> V_47 = V_74 ;
args -> V_76 = V_76 ;
for ( V_30 = 0 ; V_30 < V_76 ; V_30 ++ )
args -> args [ V_30 ] = V_72 [ V_30 ] . integer . V_41 ;
return 0 ;
}
V_72 += V_76 ;
} else if ( V_72 -> type == V_43 ) {
if ( V_75 == V_69 )
return - V_79 ;
V_72 ++ ;
} else {
return - V_65 ;
}
V_75 ++ ;
}
return - V_80 ;
}
static int F_40 ( struct V_35 * V_19 ,
const char * V_62 ,
enum V_81 V_82 , void * V_83 )
{
const union V_1 * V_60 ;
int V_29 ;
if ( ! V_83 )
return - V_61 ;
if ( V_82 >= V_84 && V_82 <= V_85 ) {
V_29 = F_33 ( V_19 , V_62 , V_43 , & V_60 ) ;
if ( V_29 )
return V_29 ;
switch ( V_82 ) {
case V_84 :
if ( V_60 -> integer . V_41 > V_86 )
return - V_87 ;
* ( V_88 * ) V_83 = V_60 -> integer . V_41 ;
break;
case V_89 :
if ( V_60 -> integer . V_41 > V_90 )
return - V_87 ;
* ( V_91 * ) V_83 = V_60 -> integer . V_41 ;
break;
case V_92 :
if ( V_60 -> integer . V_41 > V_93 )
return - V_87 ;
* ( T_5 * ) V_83 = V_60 -> integer . V_41 ;
break;
default:
* ( V_94 * ) V_83 = V_60 -> integer . V_41 ;
break;
}
} else if ( V_82 == V_95 ) {
V_29 = F_33 ( V_19 , V_62 , V_32 , & V_60 ) ;
if ( V_29 )
return V_29 ;
* ( char * * ) V_83 = V_60 -> string . V_16 ;
return 1 ;
} else {
V_29 = - V_61 ;
}
return V_29 ;
}
int F_41 ( struct V_46 * V_47 , const char * V_62 ,
enum V_81 V_82 , void * V_83 )
{
int V_29 ;
if ( ! V_47 )
return - V_61 ;
V_29 = F_40 ( & V_47 -> V_19 , V_62 , V_82 , V_83 ) ;
if ( V_29 < 0 || V_82 != V_32 )
return V_29 ;
return 0 ;
}
static int F_42 ( const union V_1 * V_96 , V_88 * V_83 ,
T_4 V_97 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_97 ; V_30 ++ ) {
if ( V_96 [ V_30 ] . type != V_43 )
return - V_65 ;
if ( V_96 [ V_30 ] . integer . V_41 > V_86 )
return - V_87 ;
V_83 [ V_30 ] = V_96 [ V_30 ] . integer . V_41 ;
}
return 0 ;
}
static int F_43 ( const union V_1 * V_96 ,
V_91 * V_83 , T_4 V_97 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_97 ; V_30 ++ ) {
if ( V_96 [ V_30 ] . type != V_43 )
return - V_65 ;
if ( V_96 [ V_30 ] . integer . V_41 > V_90 )
return - V_87 ;
V_83 [ V_30 ] = V_96 [ V_30 ] . integer . V_41 ;
}
return 0 ;
}
static int F_44 ( const union V_1 * V_96 ,
T_5 * V_83 , T_4 V_97 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_97 ; V_30 ++ ) {
if ( V_96 [ V_30 ] . type != V_43 )
return - V_65 ;
if ( V_96 [ V_30 ] . integer . V_41 > V_93 )
return - V_87 ;
V_83 [ V_30 ] = V_96 [ V_30 ] . integer . V_41 ;
}
return 0 ;
}
static int F_45 ( const union V_1 * V_96 ,
V_94 * V_83 , T_4 V_97 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_97 ; V_30 ++ ) {
if ( V_96 [ V_30 ] . type != V_43 )
return - V_65 ;
V_83 [ V_30 ] = V_96 [ V_30 ] . integer . V_41 ;
}
return 0 ;
}
static int F_46 ( const union V_1 * V_96 ,
char * * V_83 , T_4 V_97 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_97 ; V_30 ++ ) {
if ( V_96 [ V_30 ] . type != V_32 )
return - V_65 ;
V_83 [ V_30 ] = V_96 [ V_30 ] . string . V_16 ;
}
return V_97 ;
}
static int F_47 ( struct V_35 * V_19 ,
const char * V_62 ,
enum V_81 V_82 ,
void * V_83 , T_4 V_97 )
{
const union V_1 * V_60 ;
const union V_1 * V_96 ;
int V_29 ;
if ( V_83 && V_97 == 1 ) {
V_29 = F_40 ( V_19 , V_62 , V_82 , V_83 ) ;
if ( V_29 >= 0 )
return V_29 ;
}
V_29 = F_21 ( V_19 , V_62 , V_64 , & V_60 ) ;
if ( V_29 )
return V_29 ;
if ( ! V_83 )
return V_60 -> V_14 . V_31 ;
if ( V_82 != V_95 && V_97 > V_60 -> V_14 . V_31 )
return - V_87 ;
else if ( V_97 <= 0 )
return - V_61 ;
V_96 = V_60 -> V_14 . V_15 ;
switch ( V_82 ) {
case V_84 :
V_29 = F_42 ( V_96 , ( V_88 * ) V_83 , V_97 ) ;
break;
case V_89 :
V_29 = F_43 ( V_96 , ( V_91 * ) V_83 , V_97 ) ;
break;
case V_92 :
V_29 = F_44 ( V_96 , ( T_5 * ) V_83 , V_97 ) ;
break;
case V_85 :
V_29 = F_45 ( V_96 , ( V_94 * ) V_83 , V_97 ) ;
break;
case V_95 :
V_29 = F_46 (
V_96 , ( char * * ) V_83 ,
F_48 ( T_5 , V_97 , V_60 -> V_14 . V_31 ) ) ;
break;
default:
V_29 = - V_61 ;
break;
}
return V_29 ;
}
int F_49 ( struct V_46 * V_47 , const char * V_62 ,
enum V_81 V_82 , void * V_83 , T_4 V_97 )
{
return V_47 ? F_47 ( & V_47 -> V_19 , V_62 , V_82 , V_83 , V_97 ) : - V_61 ;
}
int F_50 ( struct V_7 * V_17 , const char * V_62 ,
enum V_81 V_82 , void * V_83 , T_4 V_97 )
{
return F_47 ( F_34 ( V_17 ) ,
V_62 , V_82 , V_83 , V_97 ) ;
}
struct V_7 * F_51 ( struct V_7 * V_17 ,
struct V_7 * V_98 )
{
struct V_46 * V_47 = F_35 ( V_17 ) ;
struct V_5 * V_99 , * V_58 ;
if ( ! V_98 || V_98 -> type == V_66 ) {
if ( V_47 )
V_99 = & V_47 -> V_100 ;
else
goto V_101;
if ( F_28 ( V_99 ) )
goto V_101;
if ( V_98 ) {
V_47 = F_35 ( V_98 ) ;
V_58 = V_47 -> V_102 . V_58 ;
if ( V_58 == V_99 ) {
V_98 = NULL ;
goto V_101;
}
V_47 = F_52 ( V_58 , struct V_46 , V_102 ) ;
} else {
V_47 = F_53 ( V_99 , struct V_46 , V_102 ) ;
}
return F_25 ( V_47 ) ;
}
V_101:
if ( ! V_98 || V_98 -> type == V_18 ) {
struct V_9 * V_19 = F_36 ( V_17 ) ;
struct V_9 * V_10 ;
if ( V_47 )
V_99 = & V_47 -> V_19 . V_20 ;
else if ( V_19 )
V_99 = & V_19 -> V_19 . V_20 ;
else
return NULL ;
if ( F_28 ( V_99 ) )
return NULL ;
if ( V_98 ) {
V_10 = F_36 ( V_98 ) ;
V_58 = V_10 -> V_23 . V_58 ;
if ( V_58 == V_99 )
return NULL ;
V_10 = F_52 ( V_58 , struct V_9 , V_23 ) ;
} else {
V_10 = F_53 ( V_99 , struct V_9 , V_23 ) ;
}
return & V_10 -> V_17 ;
}
return NULL ;
}
struct V_7 * F_54 ( struct V_7 * V_17 )
{
if ( F_55 ( V_17 ) ) {
return F_36 ( V_17 ) -> V_8 ;
} else if ( F_56 ( V_17 ) ) {
T_1 V_3 , V_103 ;
V_3 = F_35 ( V_17 ) -> V_3 ;
if ( F_6 ( F_5 ( V_3 , & V_103 ) ) ) {
struct V_46 * V_47 ;
if ( ! F_39 ( V_103 , & V_47 ) )
return F_25 ( V_47 ) ;
}
}
return NULL ;
}
struct V_7 * F_57 ( struct V_7 * V_17 ,
struct V_7 * V_104 )
{
struct V_7 * V_105 = NULL ;
struct V_7 * V_106 ;
if ( ! V_104 ) {
do {
V_105 = F_58 ( V_17 , V_105 ) ;
if ( F_59 ( V_105 , L_6 ) )
break;
} while ( V_105 );
} else {
V_105 = F_60 ( V_104 ) ;
}
if ( ! V_105 )
return NULL ;
V_106 = F_58 ( V_105 , V_104 ) ;
while ( ! V_106 ) {
V_105 = F_58 ( V_17 , V_105 ) ;
if ( ! V_105 )
break;
if ( F_59 ( V_105 , L_6 ) )
V_106 = F_58 ( V_105 , NULL ) ;
}
if ( V_106 ) {
if ( ! F_59 ( V_106 , L_7 ) )
return F_61 ( - V_65 ) ;
}
return V_106 ;
}
static struct V_7 * F_62 (
struct V_7 * V_17 , const char * V_107 , unsigned int V_83 )
{
struct V_7 * V_98 ;
F_63 (fwnode, child) {
T_5 V_108 ;
if ( ! F_64 ( V_17 , V_107 , & V_108 ) )
continue;
if ( V_83 == V_108 )
return V_98 ;
}
return NULL ;
}
int F_65 ( struct V_7 * V_17 ,
struct V_7 * * V_8 ,
struct V_7 * * V_105 ,
struct V_7 * * V_106 )
{
unsigned int V_109 , V_110 ;
struct V_71 args ;
int V_29 ;
memset ( & args , 0 , sizeof( args ) ) ;
V_29 = F_66 ( V_17 , L_8 , 0 ,
& args ) ;
if ( V_29 )
return V_29 ;
if ( args . V_76 != 2 )
return - V_65 ;
V_17 = F_25 ( args . V_47 ) ;
V_109 = args . args [ 0 ] ;
V_110 = args . args [ 1 ] ;
if ( V_8 )
* V_8 = V_17 ;
if ( ! V_105 && ! V_106 )
return 0 ;
V_17 = F_62 ( V_17 , L_6 , V_109 ) ;
if ( ! V_17 )
return - V_65 ;
if ( V_105 )
* V_105 = V_17 ;
if ( ! V_106 )
return 0 ;
V_17 = F_62 ( V_17 , L_7 ,
V_110 ) ;
if ( ! V_17 )
return - V_65 ;
* V_106 = V_17 ;
return 0 ;
}
