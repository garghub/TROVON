static bool F_1 ( T_1 V_1 ,
const union V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 V_7 = { V_8 } ;
struct V_9 * V_10 ;
T_1 V_11 ;
T_2 V_12 ;
V_10 = F_2 ( sizeof( * V_10 ) , V_13 ) ;
if ( ! V_10 )
return false ;
V_10 -> V_14 = V_3 -> V_15 . V_16 [ 0 ] . string . V_17 ;
V_10 -> V_18 . type = V_19 ;
F_3 ( & V_10 -> V_20 . V_21 ) ;
V_12 = F_4 ( V_1 , V_3 -> V_15 . V_16 [ 1 ] . string . V_17 ,
& V_11 ) ;
if ( F_5 ( V_12 ) )
goto V_22;
V_12 = F_6 ( V_11 , NULL , NULL , & V_7 ,
V_23 ) ;
if ( F_5 ( V_12 ) )
goto V_22;
if ( F_7 ( V_7 . V_17 , & V_10 -> V_20 ) )
V_10 -> V_11 = V_11 ;
V_12 = F_8 ( V_11 , & V_1 ) ;
if ( F_9 ( V_12 )
&& F_10 ( V_1 , V_7 . V_17 , & V_10 -> V_20 ) )
V_10 -> V_11 = V_11 ;
if ( V_10 -> V_11 ) {
V_10 -> V_20 . V_17 = V_7 . V_17 ;
F_11 ( & V_10 -> V_24 , V_5 ) ;
return true ;
}
F_12 ( V_11 , L_1 ) ;
V_22:
F_13 ( V_7 . V_17 ) ;
F_14 ( V_10 ) ;
return false ;
}
static int F_15 ( T_1 V_1 ,
const union V_2 * V_25 ,
struct V_4 * V_5 )
{
bool V_26 = false ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_25 -> V_15 . V_28 ; V_27 ++ ) {
const union V_2 * V_3 ;
V_3 = & V_25 -> V_15 . V_16 [ V_27 ] ;
if ( V_3 -> V_15 . V_28 == 2
&& V_3 -> V_15 . V_16 [ 0 ] . type == V_29
&& V_3 -> V_15 . V_16 [ 1 ] . type == V_29
&& F_1 ( V_1 , V_3 , V_5 ) )
V_26 = true ;
}
return V_26 ;
}
static bool F_10 ( T_1 V_1 ,
const union V_2 * V_30 ,
struct V_31 * V_20 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_30 -> V_15 . V_28 ; V_27 += 2 ) {
const union V_2 * V_32 , * V_25 ;
V_32 = & V_30 -> V_15 . V_16 [ V_27 ] ;
V_25 = & V_30 -> V_15 . V_16 [ V_27 + 1 ] ;
if ( V_32 -> type != V_33 || V_32 -> V_34 . V_35 != 16
|| V_25 -> type != V_23 )
break;
if ( memcmp ( V_32 -> V_34 . V_17 , V_36 , sizeof( V_36 ) ) )
continue;
return F_15 ( V_1 , V_25 , & V_20 -> V_21 ) ;
}
return false ;
}
static bool F_16 ( const union V_2 * V_37 )
{
int V_38 ;
switch ( V_37 -> type ) {
case V_39 :
case V_29 :
case V_40 :
return true ;
case V_23 :
for ( V_38 = 0 ; V_38 < V_37 -> V_15 . V_28 ; V_38 ++ )
switch ( V_37 -> V_15 . V_16 [ V_38 ] . type ) {
case V_39 :
case V_29 :
case V_40 :
continue;
default:
return false ;
}
return true ;
}
return false ;
}
static bool F_17 ( const union V_2 * V_41 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_41 -> V_15 . V_28 ; V_27 ++ ) {
const union V_2 * V_42 ;
V_42 = & V_41 -> V_15 . V_16 [ V_27 ] ;
if ( V_42 -> V_15 . V_28 != 2
|| V_42 -> V_15 . V_16 [ 0 ] . type != V_29
|| ! F_16 ( & V_42 -> V_15 . V_16 [ 1 ] ) )
return false ;
}
return true ;
}
static void F_18 ( struct V_43 * V_44 )
{
const union V_2 * V_45 ;
int V_26 ;
V_26 = F_19 ( & V_44 -> V_20 , L_2 ,
V_29 , & V_45 ) ;
if ( V_26 ) {
V_26 = F_20 ( V_44 , L_2 ,
V_29 , & V_45 ) ;
if ( V_26 ) {
if ( V_44 -> V_46
&& V_44 -> V_46 -> V_47 . V_48 )
goto V_49;
return;
}
}
V_44 -> V_20 . V_45 = V_45 ;
V_49:
V_44 -> V_47 . V_48 = 1 ;
}
static bool F_7 ( const union V_2 * V_30 ,
struct V_31 * V_20 )
{
int V_27 ;
if ( V_30 -> V_15 . V_28 % 2 )
return false ;
for ( V_27 = 0 ; V_27 < V_30 -> V_15 . V_28 ; V_27 += 2 ) {
const union V_2 * V_32 , * V_41 ;
V_32 = & V_30 -> V_15 . V_16 [ V_27 ] ;
V_41 = & V_30 -> V_15 . V_16 [ V_27 + 1 ] ;
if ( V_32 -> type != V_33 || V_32 -> V_34 . V_35 != 16
|| V_41 -> type != V_23 )
break;
if ( memcmp ( V_32 -> V_34 . V_17 , V_50 , sizeof( V_50 ) ) )
continue;
if ( ! F_17 ( V_41 ) )
break;
V_20 -> V_41 = V_41 ;
return true ;
}
return false ;
}
void F_21 ( struct V_43 * V_44 )
{
struct V_6 V_7 = { V_8 } ;
struct V_51 * V_52 ;
T_2 V_12 ;
bool V_53 = false ;
F_3 ( & V_44 -> V_20 . V_21 ) ;
F_22 (hwid, &adev->pnp.ids, list) {
if ( ! strcmp ( V_52 -> V_54 , V_55 ) ) {
V_53 = true ;
break;
}
}
V_12 = F_6 ( V_44 -> V_11 , L_3 , NULL , & V_7 ,
V_23 ) ;
if ( F_5 ( V_12 ) )
goto V_49;
if ( F_7 ( V_7 . V_17 , & V_44 -> V_20 ) ) {
V_44 -> V_20 . V_17 = V_7 . V_17 ;
if ( V_53 )
F_18 ( V_44 ) ;
}
if ( F_10 ( V_44 -> V_11 , V_7 . V_17 , & V_44 -> V_20 ) )
V_44 -> V_20 . V_17 = V_7 . V_17 ;
if ( ! V_44 -> V_20 . V_17 ) {
F_12 ( V_44 -> V_11 , L_4 ) ;
F_13 ( V_7 . V_17 ) ;
}
V_49:
if ( V_53 && ! V_44 -> V_47 . V_48 )
F_23 ( V_44 -> V_11 ,
V_55 L_5 ) ;
}
static void F_24 ( struct V_4 * V_5 )
{
struct V_9 * V_10 , * V_56 ;
if ( F_25 ( V_5 ) )
return;
F_26 (dn, next, list, sibling) {
F_24 ( & V_10 -> V_20 . V_21 ) ;
F_27 ( & V_10 -> V_57 ) ;
F_28 ( & V_10 -> V_24 ) ;
F_13 ( ( void * ) V_10 -> V_20 . V_17 ) ;
F_14 ( V_10 ) ;
}
}
void F_29 ( struct V_43 * V_44 )
{
F_24 ( & V_44 -> V_20 . V_21 ) ;
F_13 ( ( void * ) V_44 -> V_20 . V_17 ) ;
V_44 -> V_20 . V_45 = NULL ;
V_44 -> V_20 . V_17 = NULL ;
V_44 -> V_20 . V_41 = NULL ;
}
static int F_30 ( struct V_31 * V_20 ,
const char * V_14 , T_3 type ,
const union V_2 * * V_58 )
{
const union V_2 * V_41 ;
int V_27 ;
if ( ! V_20 || ! V_14 )
return - V_59 ;
if ( ! V_20 -> V_17 || ! V_20 -> V_41 )
return - V_59 ;
V_41 = V_20 -> V_41 ;
for ( V_27 = 0 ; V_27 < V_41 -> V_15 . V_28 ; V_27 ++ ) {
const union V_2 * V_60 , * V_61 ;
const union V_2 * V_42 ;
V_42 = & V_41 -> V_15 . V_16 [ V_27 ] ;
V_60 = & V_42 -> V_15 . V_16 [ 0 ] ;
V_61 = & V_42 -> V_15 . V_16 [ 1 ] ;
if ( ! strcmp ( V_14 , V_60 -> string . V_17 ) ) {
if ( type != V_62 && V_61 -> type != type )
return - V_63 ;
if ( V_58 )
* V_58 = V_61 ;
return 0 ;
}
}
return - V_59 ;
}
int F_20 ( struct V_43 * V_44 , const char * V_14 ,
T_3 type , const union V_2 * * V_58 )
{
return V_44 ? F_30 ( & V_44 -> V_20 , V_14 , type , V_58 ) : - V_59 ;
}
static struct V_31 * F_31 ( struct V_64 * V_18 )
{
if ( V_18 -> type == V_65 ) {
struct V_43 * V_44 = F_32 ( V_18 ) ;
return & V_44 -> V_20 ;
} else if ( V_18 -> type == V_19 ) {
struct V_9 * V_10 = F_33 ( V_18 ) ;
return & V_10 -> V_20 ;
}
return NULL ;
}
int F_34 ( struct V_64 * V_18 , const char * V_60 ,
void * * V_66 )
{
return F_30 ( F_31 ( V_18 ) ,
V_60 , V_62 ,
( const union V_2 * * ) V_66 ) ;
}
static int F_19 ( struct V_31 * V_20 ,
const char * V_14 ,
T_3 type ,
const union V_2 * * V_58 )
{
const union V_2 * V_67 ;
int V_26 , V_27 ;
V_26 = F_30 ( V_20 , V_14 , V_23 , & V_67 ) ;
if ( V_26 )
return V_26 ;
if ( type != V_62 ) {
for ( V_27 = 0 ; V_27 < V_67 -> V_15 . V_28 ; V_27 ++ )
if ( V_67 -> V_15 . V_16 [ V_27 ] . type != type )
return - V_63 ;
}
if ( V_58 )
* V_58 = V_67 ;
return 0 ;
}
static int F_35 ( struct V_31 * V_20 ,
const char * V_60 , T_4 V_68 ,
struct V_69 * args )
{
const union V_2 * V_70 , * V_71 ;
const union V_2 * V_58 ;
struct V_43 * V_72 ;
int V_26 , V_73 = 0 ;
V_26 = F_30 ( V_20 , V_60 , V_62 , & V_58 ) ;
if ( V_26 )
return V_26 ;
if ( V_58 -> type == V_40 ) {
if ( V_68 )
return - V_59 ;
V_26 = F_36 ( V_58 -> V_74 . V_11 , & V_72 ) ;
if ( V_26 )
return V_26 ;
args -> V_44 = V_72 ;
args -> V_75 = 0 ;
return 0 ;
}
if ( V_58 -> type != V_23 || V_68 >= V_58 -> V_15 . V_28 )
return - V_63 ;
V_70 = V_58 -> V_15 . V_16 ;
V_71 = V_70 + V_58 -> V_15 . V_28 ;
while ( V_70 < V_71 ) {
T_5 V_75 , V_27 ;
if ( V_70 -> type != V_40 )
return - V_63 ;
V_26 = F_36 ( V_70 -> V_74 . V_11 , & V_72 ) ;
if ( V_26 )
return - V_76 ;
V_70 ++ ;
V_75 = 0 ;
for ( V_27 = 0 ; V_70 + V_27 < V_71 ; V_27 ++ ) {
int type = V_70 [ V_27 ] . type ;
if ( type == V_39 )
V_75 ++ ;
else if ( type == V_40 )
break;
else
return - V_63 ;
}
if ( V_73 ++ == V_68 ) {
args -> V_44 = V_72 ;
args -> V_75 = V_75 ;
for ( V_27 = 0 ; V_27 < V_75 ; V_27 ++ )
args -> args [ V_27 ] = V_70 [ V_27 ] . integer . V_37 ;
return 0 ;
}
V_70 += V_75 ;
}
return - V_63 ;
}
int F_37 ( struct V_64 * V_18 ,
const char * V_14 , T_4 V_68 ,
struct V_69 * args )
{
struct V_31 * V_20 = F_31 ( V_18 ) ;
return V_20 ? F_35 ( V_20 , V_14 , V_68 , args ) : - V_59 ;
}
static int F_38 ( struct V_31 * V_20 ,
const char * V_60 ,
enum V_77 V_78 , void * V_79 )
{
const union V_2 * V_58 ;
int V_26 ;
if ( ! V_79 )
return - V_59 ;
if ( V_78 >= V_80 && V_78 <= V_81 ) {
V_26 = F_30 ( V_20 , V_60 , V_39 , & V_58 ) ;
if ( V_26 )
return V_26 ;
switch ( V_78 ) {
case V_80 :
if ( V_58 -> integer . V_37 > V_82 )
return - V_83 ;
* ( V_84 * ) V_79 = V_58 -> integer . V_37 ;
break;
case V_85 :
if ( V_58 -> integer . V_37 > V_86 )
return - V_83 ;
* ( V_87 * ) V_79 = V_58 -> integer . V_37 ;
break;
case V_88 :
if ( V_58 -> integer . V_37 > V_89 )
return - V_83 ;
* ( T_5 * ) V_79 = V_58 -> integer . V_37 ;
break;
default:
* ( V_90 * ) V_79 = V_58 -> integer . V_37 ;
break;
}
} else if ( V_78 == V_91 ) {
V_26 = F_30 ( V_20 , V_60 , V_29 , & V_58 ) ;
if ( V_26 )
return V_26 ;
* ( char * * ) V_79 = V_58 -> string . V_17 ;
} else {
V_26 = - V_59 ;
}
return V_26 ;
}
int F_39 ( struct V_43 * V_44 , const char * V_60 ,
enum V_77 V_78 , void * V_79 )
{
return V_44 ? F_38 ( & V_44 -> V_20 , V_60 , V_78 , V_79 ) : - V_59 ;
}
static int F_40 ( const union V_2 * V_92 , V_84 * V_79 ,
T_4 V_93 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_93 ; V_27 ++ ) {
if ( V_92 [ V_27 ] . type != V_39 )
return - V_63 ;
if ( V_92 [ V_27 ] . integer . V_37 > V_82 )
return - V_83 ;
V_79 [ V_27 ] = V_92 [ V_27 ] . integer . V_37 ;
}
return 0 ;
}
static int F_41 ( const union V_2 * V_92 ,
V_87 * V_79 , T_4 V_93 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_93 ; V_27 ++ ) {
if ( V_92 [ V_27 ] . type != V_39 )
return - V_63 ;
if ( V_92 [ V_27 ] . integer . V_37 > V_86 )
return - V_83 ;
V_79 [ V_27 ] = V_92 [ V_27 ] . integer . V_37 ;
}
return 0 ;
}
static int F_42 ( const union V_2 * V_92 ,
T_5 * V_79 , T_4 V_93 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_93 ; V_27 ++ ) {
if ( V_92 [ V_27 ] . type != V_39 )
return - V_63 ;
if ( V_92 [ V_27 ] . integer . V_37 > V_89 )
return - V_83 ;
V_79 [ V_27 ] = V_92 [ V_27 ] . integer . V_37 ;
}
return 0 ;
}
static int F_43 ( const union V_2 * V_92 ,
V_90 * V_79 , T_4 V_93 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_93 ; V_27 ++ ) {
if ( V_92 [ V_27 ] . type != V_39 )
return - V_63 ;
V_79 [ V_27 ] = V_92 [ V_27 ] . integer . V_37 ;
}
return 0 ;
}
static int F_44 ( const union V_2 * V_92 ,
char * * V_79 , T_4 V_93 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_93 ; V_27 ++ ) {
if ( V_92 [ V_27 ] . type != V_29 )
return - V_63 ;
V_79 [ V_27 ] = V_92 [ V_27 ] . string . V_17 ;
}
return 0 ;
}
static int F_45 ( struct V_31 * V_20 ,
const char * V_60 ,
enum V_77 V_78 ,
void * V_79 , T_4 V_93 )
{
const union V_2 * V_58 ;
const union V_2 * V_92 ;
int V_26 ;
if ( V_79 && V_93 == 1 ) {
V_26 = F_38 ( V_20 , V_60 , V_78 , V_79 ) ;
if ( ! V_26 )
return V_26 ;
}
V_26 = F_19 ( V_20 , V_60 , V_62 , & V_58 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_79 )
return V_58 -> V_15 . V_28 ;
if ( V_93 > V_58 -> V_15 . V_28 )
return - V_83 ;
else if ( V_93 <= 0 )
return - V_59 ;
V_92 = V_58 -> V_15 . V_16 ;
switch ( V_78 ) {
case V_80 :
V_26 = F_40 ( V_92 , ( V_84 * ) V_79 , V_93 ) ;
break;
case V_85 :
V_26 = F_41 ( V_92 , ( V_87 * ) V_79 , V_93 ) ;
break;
case V_88 :
V_26 = F_42 ( V_92 , ( T_5 * ) V_79 , V_93 ) ;
break;
case V_81 :
V_26 = F_43 ( V_92 , ( V_90 * ) V_79 , V_93 ) ;
break;
case V_91 :
V_26 = F_44 ( V_92 , ( char * * ) V_79 , V_93 ) ;
break;
default:
V_26 = - V_59 ;
break;
}
return V_26 ;
}
int F_46 ( struct V_43 * V_44 , const char * V_60 ,
enum V_77 V_78 , void * V_79 , T_4 V_93 )
{
return V_44 ? F_45 ( & V_44 -> V_20 , V_60 , V_78 , V_79 , V_93 ) : - V_59 ;
}
int F_47 ( struct V_64 * V_18 , const char * V_60 ,
enum V_77 V_78 , void * V_79 , T_4 V_93 )
{
return F_45 ( F_31 ( V_18 ) ,
V_60 , V_78 , V_79 , V_93 ) ;
}
struct V_64 * F_48 ( struct V_72 * V_94 ,
struct V_64 * V_95 )
{
struct V_43 * V_44 = F_49 ( V_94 ) ;
struct V_4 * V_96 , * V_56 ;
if ( ! V_44 )
return NULL ;
if ( ! V_95 || V_95 -> type == V_65 ) {
V_96 = & V_44 -> V_97 ;
if ( F_25 ( V_96 ) )
goto V_98;
if ( V_95 ) {
V_44 = F_32 ( V_95 ) ;
V_56 = V_44 -> V_99 . V_56 ;
if ( V_56 == V_96 ) {
V_95 = NULL ;
V_44 = F_49 ( V_94 ) ;
goto V_98;
}
V_44 = F_50 ( V_56 , struct V_43 , V_99 ) ;
} else {
V_44 = F_51 ( V_96 , struct V_43 , V_99 ) ;
}
return F_52 ( V_44 ) ;
}
V_98:
if ( ! V_95 || V_95 -> type == V_19 ) {
struct V_9 * V_10 ;
V_96 = & V_44 -> V_20 . V_21 ;
if ( F_25 ( V_96 ) )
return NULL ;
if ( V_95 ) {
V_10 = F_33 ( V_95 ) ;
V_56 = V_10 -> V_24 . V_56 ;
if ( V_56 == V_96 )
return NULL ;
V_10 = F_50 ( V_56 , struct V_9 , V_24 ) ;
} else {
V_10 = F_51 ( V_96 , struct V_9 , V_24 ) ;
}
return & V_10 -> V_18 ;
}
return NULL ;
}
