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
int V_17 ;
V_17 = F_4 ( V_15 , L_1 , V_5 ,
& V_16 ) ;
if ( V_17 ) {
V_17 = F_5 ( V_15 , L_1 ,
V_5 , & V_16 ) ;
if ( V_17 ) {
if ( V_15 -> V_18
&& V_15 -> V_18 -> V_19 . V_20 )
goto V_21;
return;
}
}
V_15 -> V_22 . V_16 = V_16 ;
V_21:
V_15 -> V_19 . V_20 = 1 ;
}
void F_6 ( struct V_14 * V_15 )
{
struct V_23 V_24 = { V_25 } ;
bool V_26 = false ;
struct V_27 * V_28 ;
const union V_1 * V_29 ;
T_1 V_30 ;
int V_12 ;
F_7 (hwid, &adev->pnp.ids, list) {
if ( ! strcmp ( V_28 -> V_31 , V_32 ) ) {
V_26 = true ;
break;
}
}
V_30 = F_8 ( V_15 -> V_33 , L_2 , NULL , & V_24 ,
V_7 ) ;
if ( F_9 ( V_30 ) )
goto V_21;
V_29 = V_24 . V_34 ;
if ( V_29 -> V_8 . V_9 % 2 )
goto V_35;
for ( V_12 = 0 ; V_12 < V_29 -> V_8 . V_9 ; V_12 += 2 ) {
const union V_1 * V_36 , * V_11 ;
V_36 = & V_29 -> V_8 . V_10 [ V_12 ] ;
V_11 = & V_29 -> V_8 . V_10 [ V_12 + 1 ] ;
if ( V_36 -> type != V_37 || V_36 -> V_38 . V_39 != 16
|| V_11 -> type != V_7 )
break;
if ( memcmp ( V_36 -> V_38 . V_34 , V_40 , sizeof( V_40 ) ) )
continue;
if ( ! F_2 ( V_11 ) )
break;
V_15 -> V_22 . V_34 = V_24 . V_34 ;
V_15 -> V_22 . V_11 = V_11 ;
if ( V_26 )
F_3 ( V_15 ) ;
goto V_21;
}
V_35:
F_10 ( & V_15 -> V_41 , L_3 ) ;
F_11 ( V_24 . V_34 ) ;
V_21:
if ( V_26 && ! V_15 -> V_19 . V_20 )
F_12 ( V_15 -> V_33 ,
V_32 L_4 ) ;
}
void F_13 ( struct V_14 * V_15 )
{
F_11 ( ( void * ) V_15 -> V_22 . V_34 ) ;
V_15 -> V_22 . V_16 = NULL ;
V_15 -> V_22 . V_34 = NULL ;
V_15 -> V_22 . V_11 = NULL ;
}
int F_5 ( struct V_14 * V_15 , const char * V_42 ,
T_2 type , const union V_1 * * V_43 )
{
const union V_1 * V_11 ;
int V_12 ;
if ( ! V_15 || ! V_42 )
return - V_44 ;
if ( ! V_15 -> V_22 . V_34 || ! V_15 -> V_22 . V_11 )
return - V_45 ;
V_11 = V_15 -> V_22 . V_11 ;
for ( V_12 = 0 ; V_12 < V_11 -> V_8 . V_9 ; V_12 ++ ) {
const union V_1 * V_46 , * V_47 ;
const union V_1 * V_13 ;
V_13 = & V_11 -> V_8 . V_10 [ V_12 ] ;
V_46 = & V_13 -> V_8 . V_10 [ 0 ] ;
V_47 = & V_13 -> V_8 . V_10 [ 1 ] ;
if ( ! strcmp ( V_42 , V_46 -> string . V_34 ) ) {
if ( type != V_48 && V_47 -> type != type )
return - V_49 ;
else if ( V_43 )
* V_43 = V_47 ;
return 0 ;
}
}
return - V_45 ;
}
int F_4 ( struct V_14 * V_15 , const char * V_42 ,
T_2 type ,
const union V_1 * * V_43 )
{
const union V_1 * V_50 ;
int V_17 , V_12 ;
V_17 = F_5 ( V_15 , V_42 , V_7 , & V_50 ) ;
if ( V_17 )
return V_17 ;
if ( type != V_48 ) {
for ( V_12 = 0 ; V_12 < V_50 -> V_8 . V_9 ; V_12 ++ )
if ( V_50 -> V_8 . V_10 [ V_12 ] . type != type )
return - V_49 ;
}
if ( V_43 )
* V_43 = V_50 ;
return 0 ;
}
int F_14 ( struct V_14 * V_15 ,
const char * V_42 , T_3 V_51 ,
struct V_52 * args )
{
const union V_1 * V_53 , * V_54 ;
const union V_1 * V_43 ;
struct V_14 * V_55 ;
int V_17 , V_56 = 0 ;
V_17 = F_5 ( V_15 , V_42 , V_48 , & V_43 ) ;
if ( V_17 )
return V_17 ;
if ( V_43 -> type == V_6 ) {
if ( V_51 )
return - V_44 ;
V_17 = F_15 ( V_43 -> V_57 . V_33 , & V_55 ) ;
if ( V_17 )
return V_17 ;
args -> V_15 = V_55 ;
args -> V_58 = 0 ;
return 0 ;
}
if ( V_43 -> type != V_7 || V_51 >= V_43 -> V_8 . V_9 )
return - V_49 ;
V_53 = V_43 -> V_8 . V_10 ;
V_54 = V_53 + V_43 -> V_8 . V_9 ;
while ( V_53 < V_54 ) {
T_4 V_58 , V_12 ;
if ( V_53 -> type != V_6 )
return - V_49 ;
V_17 = F_15 ( V_53 -> V_57 . V_33 , & V_55 ) ;
if ( V_17 )
return - V_59 ;
V_53 ++ ;
V_58 = 0 ;
for ( V_12 = 0 ; V_53 + V_12 < V_54 ; V_12 ++ ) {
int type = V_53 [ V_12 ] . type ;
if ( type == V_4 )
V_58 ++ ;
else if ( type == V_6 )
break;
else
return - V_49 ;
}
if ( V_56 ++ == V_51 ) {
args -> V_15 = V_55 ;
args -> V_58 = V_58 ;
for ( V_12 = 0 ; V_12 < V_58 ; V_12 ++ )
args -> args [ V_12 ] = V_53 [ V_12 ] . integer . V_2 ;
return 0 ;
}
V_53 += V_58 ;
}
return - V_49 ;
}
int F_16 ( struct V_14 * V_15 , const char * V_46 ,
void * * V_60 )
{
return F_5 ( V_15 , V_46 , V_48 ,
( const union V_1 * * ) V_60 ) ;
}
int F_17 ( struct V_14 * V_15 , const char * V_46 ,
enum V_61 V_62 , void * V_63 )
{
const union V_1 * V_43 ;
int V_17 ;
if ( ! V_63 )
return - V_44 ;
if ( V_62 >= V_64 && V_62 <= V_65 ) {
V_17 = F_5 ( V_15 , V_46 , V_4 , & V_43 ) ;
if ( V_17 )
return V_17 ;
switch ( V_62 ) {
case V_64 :
if ( V_43 -> integer . V_2 > V_66 )
return - V_67 ;
* ( V_68 * ) V_63 = V_43 -> integer . V_2 ;
break;
case V_69 :
if ( V_43 -> integer . V_2 > V_70 )
return - V_67 ;
* ( V_71 * ) V_63 = V_43 -> integer . V_2 ;
break;
case V_72 :
if ( V_43 -> integer . V_2 > V_73 )
return - V_67 ;
* ( T_4 * ) V_63 = V_43 -> integer . V_2 ;
break;
default:
* ( V_74 * ) V_63 = V_43 -> integer . V_2 ;
break;
}
} else if ( V_62 == V_75 ) {
V_17 = F_5 ( V_15 , V_46 , V_5 , & V_43 ) ;
if ( V_17 )
return V_17 ;
* ( char * * ) V_63 = V_43 -> string . V_34 ;
} else {
V_17 = - V_44 ;
}
return V_17 ;
}
static int F_18 ( const union V_1 * V_76 , V_68 * V_63 ,
T_3 V_77 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_77 ; V_12 ++ ) {
if ( V_76 [ V_12 ] . type != V_4 )
return - V_49 ;
if ( V_76 [ V_12 ] . integer . V_2 > V_66 )
return - V_67 ;
V_63 [ V_12 ] = V_76 [ V_12 ] . integer . V_2 ;
}
return 0 ;
}
static int F_19 ( const union V_1 * V_76 ,
V_71 * V_63 , T_3 V_77 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_77 ; V_12 ++ ) {
if ( V_76 [ V_12 ] . type != V_4 )
return - V_49 ;
if ( V_76 [ V_12 ] . integer . V_2 > V_70 )
return - V_67 ;
V_63 [ V_12 ] = V_76 [ V_12 ] . integer . V_2 ;
}
return 0 ;
}
static int F_20 ( const union V_1 * V_76 ,
T_4 * V_63 , T_3 V_77 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_77 ; V_12 ++ ) {
if ( V_76 [ V_12 ] . type != V_4 )
return - V_49 ;
if ( V_76 [ V_12 ] . integer . V_2 > V_73 )
return - V_67 ;
V_63 [ V_12 ] = V_76 [ V_12 ] . integer . V_2 ;
}
return 0 ;
}
static int F_21 ( const union V_1 * V_76 ,
V_74 * V_63 , T_3 V_77 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_77 ; V_12 ++ ) {
if ( V_76 [ V_12 ] . type != V_4 )
return - V_49 ;
V_63 [ V_12 ] = V_76 [ V_12 ] . integer . V_2 ;
}
return 0 ;
}
static int F_22 ( const union V_1 * V_76 ,
char * * V_63 , T_3 V_77 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_77 ; V_12 ++ ) {
if ( V_76 [ V_12 ] . type != V_5 )
return - V_49 ;
V_63 [ V_12 ] = V_76 [ V_12 ] . string . V_34 ;
}
return 0 ;
}
int F_23 ( struct V_14 * V_15 , const char * V_46 ,
enum V_61 V_62 , void * V_63 , T_3 V_77 )
{
const union V_1 * V_43 ;
const union V_1 * V_76 ;
int V_17 ;
if ( V_63 && V_77 == 1 ) {
V_17 = F_17 ( V_15 , V_46 , V_62 , V_63 ) ;
if ( ! V_17 )
return V_17 ;
}
V_17 = F_4 ( V_15 , V_46 , V_48 , & V_43 ) ;
if ( V_17 )
return V_17 ;
if ( ! V_63 )
return V_43 -> V_8 . V_9 ;
else if ( V_77 <= 0 )
return - V_44 ;
if ( V_77 > V_43 -> V_8 . V_9 )
return - V_67 ;
V_76 = V_43 -> V_8 . V_10 ;
switch ( V_62 ) {
case V_64 :
V_17 = F_18 ( V_76 , ( V_68 * ) V_63 , V_77 ) ;
break;
case V_69 :
V_17 = F_19 ( V_76 , ( V_71 * ) V_63 , V_77 ) ;
break;
case V_72 :
V_17 = F_20 ( V_76 , ( T_4 * ) V_63 , V_77 ) ;
break;
case V_65 :
V_17 = F_21 ( V_76 , ( V_74 * ) V_63 , V_77 ) ;
break;
case V_75 :
V_17 = F_22 ( V_76 , ( char * * ) V_63 , V_77 ) ;
break;
default:
V_17 = - V_44 ;
break;
}
return V_17 ;
}
