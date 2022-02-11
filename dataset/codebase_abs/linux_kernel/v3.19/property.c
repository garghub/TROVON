static bool F_1 ( const union V_1 * V_2 )
{
int V_3 ;
switch ( V_2 -> type ) {
case V_4 :
case V_5 :
case V_6 :
return true ;
case V_7 :
for ( V_3 = 0 ; V_3 < V_2 -> V_8 . V_9 ; V_3 ++ )
switch ( V_2 -> V_8 . V_10 [ V_3 ] . type ) {
case V_4 :
case V_5 :
case V_6 :
continue;
default:
return false ;
}
return true ;
}
return false ;
}
static bool F_2 ( const union V_1 * V_11 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_11 -> V_8 . V_9 ; V_12 ++ ) {
const union V_1 * V_13 ;
V_13 = & V_11 -> V_8 . V_10 [ V_12 ] ;
if ( V_13 -> V_8 . V_9 != 2
|| V_13 -> V_8 . V_10 [ 0 ] . type != V_5
|| ! F_1 ( & V_13 -> V_8 . V_10 [ 1 ] ) )
return false ;
}
return true ;
}
static void F_3 ( struct V_14 * V_15 )
{
const union V_1 * V_16 ;
struct V_17 * V_18 ;
bool V_19 = false ;
int V_20 ;
F_4 (hwid, &adev->pnp.ids, list) {
if ( ! strcmp ( V_18 -> V_21 , L_1 ) ) {
V_19 = true ;
break;
}
}
if ( ! V_19 )
return;
V_20 = F_5 ( V_15 , L_2 , V_5 ,
& V_16 ) ;
if ( V_20 ) {
V_20 = F_6 ( V_15 , L_2 ,
V_5 , & V_16 ) ;
if ( V_20 ) {
F_7 ( V_15 -> V_22 ,
L_3 ) ;
return;
}
}
V_15 -> V_23 . V_16 = V_16 ;
}
void F_8 ( struct V_14 * V_15 )
{
struct V_24 V_25 = { V_26 } ;
const union V_1 * V_27 ;
T_1 V_28 ;
int V_12 ;
V_28 = F_9 ( V_15 -> V_22 , L_4 , NULL , & V_25 ,
V_7 ) ;
if ( F_10 ( V_28 ) )
return;
V_27 = V_25 . V_29 ;
if ( V_27 -> V_8 . V_9 % 2 )
goto V_30;
for ( V_12 = 0 ; V_12 < V_27 -> V_8 . V_9 ; V_12 += 2 ) {
const union V_1 * V_31 , * V_11 ;
V_31 = & V_27 -> V_8 . V_10 [ V_12 ] ;
V_11 = & V_27 -> V_8 . V_10 [ V_12 + 1 ] ;
if ( V_31 -> type != V_32 || V_31 -> V_33 . V_34 != 16
|| V_11 -> type != V_7 )
break;
if ( memcmp ( V_31 -> V_33 . V_29 , V_35 , sizeof( V_35 ) ) )
continue;
if ( ! F_2 ( V_11 ) )
break;
V_15 -> V_23 . V_29 = V_25 . V_29 ;
V_15 -> V_23 . V_11 = V_11 ;
F_3 ( V_15 ) ;
return;
}
V_30:
F_11 ( & V_15 -> V_36 , L_5 ) ;
F_12 ( V_25 . V_29 ) ;
}
void F_13 ( struct V_14 * V_15 )
{
F_12 ( ( void * ) V_15 -> V_23 . V_29 ) ;
V_15 -> V_23 . V_16 = NULL ;
V_15 -> V_23 . V_29 = NULL ;
V_15 -> V_23 . V_11 = NULL ;
}
int F_6 ( struct V_14 * V_15 , const char * V_37 ,
T_2 type , const union V_1 * * V_38 )
{
const union V_1 * V_11 ;
int V_12 ;
if ( ! V_15 || ! V_37 )
return - V_39 ;
if ( ! V_15 -> V_23 . V_29 || ! V_15 -> V_23 . V_11 )
return - V_40 ;
V_11 = V_15 -> V_23 . V_11 ;
for ( V_12 = 0 ; V_12 < V_11 -> V_8 . V_9 ; V_12 ++ ) {
const union V_1 * V_41 , * V_42 ;
const union V_1 * V_13 ;
V_13 = & V_11 -> V_8 . V_10 [ V_12 ] ;
V_41 = & V_13 -> V_8 . V_10 [ 0 ] ;
V_42 = & V_13 -> V_8 . V_10 [ 1 ] ;
if ( ! strcmp ( V_37 , V_41 -> string . V_29 ) ) {
if ( type != V_43 && V_42 -> type != type )
return - V_44 ;
else if ( V_38 )
* V_38 = V_42 ;
return 0 ;
}
}
return - V_40 ;
}
int F_5 ( struct V_14 * V_15 , const char * V_37 ,
T_2 type ,
const union V_1 * * V_38 )
{
const union V_1 * V_45 ;
int V_20 , V_12 ;
V_20 = F_6 ( V_15 , V_37 , V_7 , & V_45 ) ;
if ( V_20 )
return V_20 ;
if ( type != V_43 ) {
for ( V_12 = 0 ; V_12 < V_45 -> V_8 . V_9 ; V_12 ++ )
if ( V_45 -> V_8 . V_10 [ V_12 ] . type != type )
return - V_44 ;
}
if ( V_38 )
* V_38 = V_45 ;
return 0 ;
}
int F_14 ( struct V_14 * V_15 ,
const char * V_37 , T_3 V_46 ,
struct V_47 * args )
{
const union V_1 * V_48 , * V_49 ;
const union V_1 * V_38 ;
struct V_14 * V_50 ;
int V_20 , V_51 = 0 ;
V_20 = F_6 ( V_15 , V_37 , V_43 , & V_38 ) ;
if ( V_20 )
return V_20 ;
if ( V_38 -> type == V_6 ) {
if ( V_46 )
return - V_39 ;
V_20 = F_15 ( V_38 -> V_52 . V_22 , & V_50 ) ;
if ( V_20 )
return V_20 ;
args -> V_15 = V_50 ;
args -> V_53 = 0 ;
return 0 ;
}
if ( V_38 -> type != V_7 || V_46 >= V_38 -> V_8 . V_9 )
return - V_44 ;
V_48 = V_38 -> V_8 . V_10 ;
V_49 = V_48 + V_38 -> V_8 . V_9 ;
while ( V_48 < V_49 ) {
T_4 V_53 , V_12 ;
if ( V_48 -> type != V_6 )
return - V_44 ;
V_20 = F_15 ( V_48 -> V_52 . V_22 , & V_50 ) ;
if ( V_20 )
return - V_54 ;
V_48 ++ ;
V_53 = 0 ;
for ( V_12 = 0 ; V_48 + V_12 < V_49 ; V_12 ++ ) {
int type = V_48 [ V_12 ] . type ;
if ( type == V_4 )
V_53 ++ ;
else if ( type == V_6 )
break;
else
return - V_44 ;
}
if ( V_51 ++ == V_46 ) {
args -> V_15 = V_50 ;
args -> V_53 = V_53 ;
for ( V_12 = 0 ; V_12 < V_53 ; V_12 ++ )
args -> args [ V_12 ] = V_48 [ V_12 ] . integer . V_2 ;
return 0 ;
}
V_48 += V_53 ;
}
return - V_44 ;
}
int F_16 ( struct V_14 * V_15 , const char * V_41 ,
void * * V_55 )
{
return F_6 ( V_15 , V_41 , V_43 ,
( const union V_1 * * ) V_55 ) ;
}
int F_17 ( struct V_14 * V_15 , const char * V_41 ,
enum V_56 V_57 , void * V_58 )
{
const union V_1 * V_38 ;
int V_20 ;
if ( ! V_58 )
return - V_39 ;
if ( V_57 >= V_59 && V_57 <= V_60 ) {
V_20 = F_6 ( V_15 , V_41 , V_4 , & V_38 ) ;
if ( V_20 )
return V_20 ;
switch ( V_57 ) {
case V_59 :
if ( V_38 -> integer . V_2 > V_61 )
return - V_62 ;
* ( V_63 * ) V_58 = V_38 -> integer . V_2 ;
break;
case V_64 :
if ( V_38 -> integer . V_2 > V_65 )
return - V_62 ;
* ( V_66 * ) V_58 = V_38 -> integer . V_2 ;
break;
case V_67 :
if ( V_38 -> integer . V_2 > V_68 )
return - V_62 ;
* ( T_4 * ) V_58 = V_38 -> integer . V_2 ;
break;
default:
* ( V_69 * ) V_58 = V_38 -> integer . V_2 ;
break;
}
} else if ( V_57 == V_70 ) {
V_20 = F_6 ( V_15 , V_41 , V_5 , & V_38 ) ;
if ( V_20 )
return V_20 ;
* ( char * * ) V_58 = V_38 -> string . V_29 ;
} else {
V_20 = - V_39 ;
}
return V_20 ;
}
static int F_18 ( const union V_1 * V_71 , V_63 * V_58 ,
T_3 V_72 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_72 ; V_12 ++ ) {
if ( V_71 [ V_12 ] . type != V_4 )
return - V_44 ;
if ( V_71 [ V_12 ] . integer . V_2 > V_61 )
return - V_62 ;
V_58 [ V_12 ] = V_71 [ V_12 ] . integer . V_2 ;
}
return 0 ;
}
static int F_19 ( const union V_1 * V_71 ,
V_66 * V_58 , T_3 V_72 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_72 ; V_12 ++ ) {
if ( V_71 [ V_12 ] . type != V_4 )
return - V_44 ;
if ( V_71 [ V_12 ] . integer . V_2 > V_65 )
return - V_62 ;
V_58 [ V_12 ] = V_71 [ V_12 ] . integer . V_2 ;
}
return 0 ;
}
static int F_20 ( const union V_1 * V_71 ,
T_4 * V_58 , T_3 V_72 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_72 ; V_12 ++ ) {
if ( V_71 [ V_12 ] . type != V_4 )
return - V_44 ;
if ( V_71 [ V_12 ] . integer . V_2 > V_68 )
return - V_62 ;
V_58 [ V_12 ] = V_71 [ V_12 ] . integer . V_2 ;
}
return 0 ;
}
static int F_21 ( const union V_1 * V_71 ,
V_69 * V_58 , T_3 V_72 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_72 ; V_12 ++ ) {
if ( V_71 [ V_12 ] . type != V_4 )
return - V_44 ;
V_58 [ V_12 ] = V_71 [ V_12 ] . integer . V_2 ;
}
return 0 ;
}
static int F_22 ( const union V_1 * V_71 ,
char * * V_58 , T_3 V_72 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_72 ; V_12 ++ ) {
if ( V_71 [ V_12 ] . type != V_5 )
return - V_44 ;
V_58 [ V_12 ] = V_71 [ V_12 ] . string . V_29 ;
}
return 0 ;
}
int F_23 ( struct V_14 * V_15 , const char * V_41 ,
enum V_56 V_57 , void * V_58 , T_3 V_72 )
{
const union V_1 * V_38 ;
const union V_1 * V_71 ;
int V_20 ;
if ( V_58 && V_72 == 1 ) {
V_20 = F_17 ( V_15 , V_41 , V_57 , V_58 ) ;
if ( ! V_20 )
return V_20 ;
}
V_20 = F_5 ( V_15 , V_41 , V_43 , & V_38 ) ;
if ( V_20 )
return V_20 ;
if ( ! V_58 )
return V_38 -> V_8 . V_9 ;
else if ( V_72 <= 0 )
return - V_39 ;
if ( V_72 > V_38 -> V_8 . V_9 )
return - V_62 ;
V_71 = V_38 -> V_8 . V_10 ;
switch ( V_57 ) {
case V_59 :
V_20 = F_18 ( V_71 , ( V_63 * ) V_58 , V_72 ) ;
break;
case V_64 :
V_20 = F_19 ( V_71 , ( V_66 * ) V_58 , V_72 ) ;
break;
case V_67 :
V_20 = F_20 ( V_71 , ( T_4 * ) V_58 , V_72 ) ;
break;
case V_60 :
V_20 = F_21 ( V_71 , ( V_69 * ) V_58 , V_72 ) ;
break;
case V_70 :
V_20 = F_22 ( V_71 , ( char * * ) V_58 , V_72 ) ;
break;
default:
V_20 = - V_39 ;
break;
}
return V_20 ;
}
