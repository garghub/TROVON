static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_10 ;
int V_11 = 0 ;
for ( V_10 = 0 ; V_10 < V_12 ; V_10 ++ ) {
if ( V_9 -> V_13 & ( 1 << V_10 ) )
if ( V_14 - V_11 > 0 )
V_11 += snprintf ( & V_5 [ V_11 ] ,
V_14 - V_11 ,
L_1 ,
V_15 [ V_10 ] ) ;
}
return V_11 ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_16 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_13 & ( 1 << V_9 -> V_17 ) )
return sprintf ( V_5 , L_1 ,
V_15 [ V_9 -> V_17 ] ) ;
else
return sprintf ( V_5 , L_2 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_12 ; ++ V_10 ) {
if ( ( V_9 -> V_13 & ( 1 << V_10 ) ) &&
! ( strncmp ( V_5 , V_15 [ V_10 ] ,
sizeof( V_15 [ V_10 ] ) - 1 ) ) ) {
V_9 -> V_17 = V_10 ;
return V_18 ;
}
}
return - V_19 ;
}
static int F_6 ( struct V_8 * V_9 )
{
struct V_20 V_5 = { V_21 , NULL } ;
union V_22 * V_23 , * V_24 ;
int V_10 , V_25 ;
int V_26 = 0 ;
T_3 V_27 ;
V_27 = F_7 ( V_9 -> V_28 -> V_29 , L_3 , NULL , & V_5 ) ;
if ( F_8 ( V_27 ) )
return - V_30 ;
V_23 = (union V_22 * ) V_5 . V_31 ;
if ( V_23 -> type != V_32 ) {
V_26 = - V_19 ;
goto V_33;
}
for ( V_10 = 0 ; V_10 < V_23 -> V_34 . V_18 ; V_10 ++ ) {
V_24 = & V_23 -> V_34 . V_35 [ V_10 ] ;
if ( V_24 -> type != V_36 ) {
V_26 = - V_19 ;
goto V_33;
}
if ( V_24 -> V_37 . V_11 != 16 ) {
V_26 = - V_19 ;
goto V_33;
}
for ( V_25 = 0 ; V_25 < V_12 ; V_25 ++ ) {
T_4 V_38 ;
F_9 ( V_15 [ V_25 ] , & V_38 ) ;
if ( F_10 ( ( T_4 * ) V_24 -> V_37 . V_31 , & V_38 ) ) {
V_9 -> V_13 |= ( 1 << V_25 ) ;
break;
}
}
}
V_33:
F_11 ( V_5 . V_31 ) ;
return V_26 ;
}
static int F_12 ( T_5 V_29 ,
enum V_39 V_40 , bool V_41 )
{
T_6 V_42 , V_5 [ 2 ] ;
T_3 V_27 ;
int V_26 = 0 ;
struct V_43 V_44 = {
. V_45 = V_15 [ V_40 ] ,
. V_46 = 1 ,
. V_47 . V_11 = 8 ,
} ;
V_5 [ V_48 ] = 0 ;
V_5 [ V_49 ] = V_41 ;
V_44 . V_47 . V_31 = V_5 ;
V_27 = F_13 ( V_29 , & V_44 ) ;
if ( F_14 ( V_27 ) ) {
V_42 = * ( ( T_6 * ) ( V_44 . V_42 . V_31 + 4 ) ) ;
if ( V_42 != V_41 )
V_26 = - V_50 ;
} else
V_26 = - V_50 ;
F_11 ( V_44 . V_42 . V_31 ) ;
return V_26 ;
}
static void F_15 ( T_5 V_29 ,
T_6 V_51 ,
void * V_52 )
{
struct V_8 * V_9 = V_52 ;
char * V_53 [ 5 ] ;
if ( ! V_9 )
return;
switch ( V_51 ) {
case V_54 :
V_53 [ 0 ] = F_16 ( V_55 , L_4 ,
V_9 -> V_56 -> type ) ;
V_53 [ 1 ] = F_16 ( V_55 , L_5 ,
V_9 -> V_56 -> V_57 ) ;
V_53 [ 2 ] = F_16 ( V_55 , L_6 ) ;
V_53 [ 3 ] = F_16 ( V_55 , L_7 ,
V_58 ) ;
V_53 [ 4 ] = NULL ;
F_17 ( & V_9 -> V_56 -> V_1 . V_59 , V_60 ,
V_53 ) ;
break;
default:
F_18 ( & V_9 -> V_28 -> V_2 , L_8 , V_51 ) ;
break;
}
}
static int F_19 ( struct V_61 * V_56 ,
int * V_62 )
{
* V_62 = 20 * 1000 ;
return 0 ;
}
static int F_20 ( struct V_61 * V_56 ,
enum V_63 * V_64 )
{
struct V_8 * V_9 = V_56 -> V_65 ;
if ( ! V_9 )
return - V_19 ;
* V_64 = V_9 -> V_64 ;
return 0 ;
}
static int F_21 ( struct V_61 * V_56 ,
enum V_63 V_64 )
{
struct V_8 * V_9 = V_56 -> V_65 ;
bool V_41 ;
int V_26 = 0 ;
if ( ! V_9 )
return - V_19 ;
if ( V_64 == V_66 )
V_41 = true ;
else if ( V_64 == V_67 )
V_41 = false ;
else
return - V_19 ;
if ( V_41 != V_9 -> V_64 ) {
V_9 -> V_64 = V_41 ;
V_26 = F_12 ( V_9 -> V_28 -> V_29 ,
V_9 -> V_17 ,
V_41 ) ;
}
return V_26 ;
}
static int F_22 ( struct V_6 * V_7 )
{
struct V_68 * V_28 = F_23 ( & V_7 -> V_2 ) ;
struct V_8 * V_9 ;
int V_26 ;
if ( ! V_28 )
return - V_30 ;
V_9 = F_24 ( sizeof( struct V_8 ) , V_55 ) ;
if ( ! V_9 )
return - V_69 ;
V_9 -> V_28 = V_28 ;
V_26 = F_6 ( V_9 ) ;
if ( V_26 )
goto V_70;
V_26 = F_25 ( V_9 -> V_28 -> V_29 , & V_9 -> V_71 ,
& V_9 -> V_72 , true ) ;
if ( V_26 )
F_26 ( & V_7 -> V_2 , L_9 ) ;
V_26 = F_27 ( V_9 -> V_28 -> V_29 , & V_9 -> V_73 ,
& V_9 -> V_74 , true ) ;
if ( V_26 )
F_26 ( & V_7 -> V_2 , L_10 ) ;
F_28 ( V_7 , V_9 ) ;
if ( V_9 -> V_13 & 1 << V_75 ) {
V_76 . V_77 = F_20 ;
V_76 . V_78 = F_21 ;
}
V_9 -> V_56 = F_29 ( L_11 , 0 , 0 ,
V_9 , & V_76 ,
& V_79 , 0 , 0 ) ;
if ( F_30 ( V_9 -> V_56 ) ) {
V_26 = F_31 ( V_9 -> V_56 ) ;
goto V_80;
}
V_9 -> V_81 = F_32 (
V_9 -> V_28 -> V_29 ) ;
V_26 = F_33 ( & V_7 -> V_2 . V_59 , & V_82 ) ;
if ( V_26 )
goto V_83;
V_26 = F_34 (
V_9 -> V_28 -> V_29 , V_84 , F_15 ,
( void * ) V_9 ) ;
if ( V_26 )
goto V_83;
return 0 ;
V_83:
F_35 ( V_9 -> V_56 ) ;
V_80:
F_11 ( V_9 -> V_74 ) ;
F_11 ( V_9 -> V_72 ) ;
V_70:
F_11 ( V_9 ) ;
return V_26 ;
}
static int F_36 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_37 (
V_9 -> V_28 -> V_29 , V_84 ,
F_15 ) ;
if ( ! V_9 -> V_81 )
F_38 ( V_9 -> V_28 -> V_29 ) ;
F_39 ( & V_7 -> V_2 . V_59 , & V_82 ) ;
F_35 ( V_9 -> V_56 ) ;
F_11 ( V_9 -> V_74 ) ;
F_11 ( V_9 -> V_72 ) ;
F_11 ( V_9 ) ;
return 0 ;
}
