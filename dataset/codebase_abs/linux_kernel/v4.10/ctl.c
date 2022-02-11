static T_1 F_1 ( struct V_1 V_2 )
{
return ( T_1 ) V_2 . V_3 << 32 | V_2 . V_4 ;
}
static struct V_1 F_2 ( T_1 V_5 )
{
struct V_1 V_2 = {
. V_3 = V_5 >> 32 ,
. V_4 = V_5 ,
} ;
F_3 ( F_1 ( V_2 ) != V_5 ) ;
return V_2 ;
}
static int F_4 ( struct V_6 * V_7 , T_2 V_8 , enum V_9 type ,
T_1 V_5 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
if ( F_5 ( V_8 != V_7 -> V_11 . V_12 ,
L_1 ,
V_8 , V_7 -> V_11 . V_12 ) )
return - V_13 ;
if ( F_5 ( type != V_7 -> V_11 . V_14 , L_2 ,
type , V_7 -> V_11 . V_14 ) )
return - V_13 ;
if ( F_5 ( V_7 -> V_11 . V_15 , L_3 ,
V_7 -> V_11 . V_15 ) )
return - V_13 ;
if ( F_5 ( V_2 -> V_16 != 1 << 9 ,
L_4 , V_2 -> V_16 ) )
return - V_13 ;
if ( F_5 ( V_5 != F_1 ( * V_2 ) ,
L_5 ,
V_5 , F_1 ( * V_2 ) ) )
return - V_13 ;
return 0 ;
}
static int F_6 ( struct V_17 V_18 ,
enum V_19 V_20 , T_2 V_21 ,
T_2 V_22 )
{
if ( F_5 ( V_18 . V_23 , L_6 , V_18 . V_23 ) )
return - V_13 ;
if ( F_5 ( V_20 != V_18 . V_20 , L_7 ,
V_20 , V_18 . V_20 ) )
return - V_13 ;
if ( F_5 ( V_21 != V_18 . V_21 , L_8 ,
V_21 , V_18 . V_21 ) )
return - V_13 ;
if ( F_5 ( V_22 != V_18 . V_22 , L_7 ,
V_22 , V_18 . V_22 ) )
return - V_13 ;
if ( F_5 ( V_18 . V_24 , L_9 , V_18 . V_24 ) )
return - V_13 ;
return 0 ;
}
static struct V_25 F_7 ( struct V_6 * V_26 )
{
struct V_27 * V_7 = V_26 -> V_10 ;
struct V_25 V_28 = { 0 } ;
V_28 . V_29 = F_1 ( V_7 -> V_2 ) ;
V_28 . V_30 = 0 ;
V_28 . V_31 = F_4 ( V_26 , sizeof( * V_7 ) , V_32 ,
F_1 ( V_7 -> V_2 ) ) ;
if ( V_28 . V_31 )
return V_28 ;
F_5 ( V_7 -> V_33 , L_10 , V_7 -> V_33 ) ;
F_5 ( V_7 -> V_34 , L_10 , V_7 -> V_33 ) ;
F_5 ( V_7 -> V_35 , L_10 , V_7 -> V_33 ) ;
V_28 . V_31 = 1 ;
V_28 . V_36 = V_7 -> error ;
V_28 . V_30 = V_7 -> V_37 ;
return V_28 ;
}
static struct V_25 F_8 ( struct V_6 * V_7 , T_2 V_8 ,
enum V_9 type , T_1 V_5 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
struct V_25 V_28 = { 0 } ;
if ( V_7 -> V_11 . V_14 == V_32 )
return F_7 ( V_7 ) ;
V_28 . V_30 = 0 ;
V_28 . V_29 = F_1 ( * V_2 ) ;
V_28 . V_31 = F_4 ( V_7 , V_8 , type , V_5 ) ;
return V_28 ;
}
static void F_9 ( struct V_38 * V_39 ,
const struct V_25 * V_28 )
{
F_3 ( V_28 -> V_31 != 1 ) ;
switch ( V_28 -> V_36 ) {
case V_40 :
return;
case V_41 :
F_10 ( V_39 ,
L_11 ,
V_28 -> V_29 , V_28 -> V_30 ) ;
return;
case V_42 :
F_10 ( V_39 , L_12 ,
V_28 -> V_29 , V_28 -> V_30 ) ;
return;
case V_43 :
F_10 ( V_39 , L_13 ,
V_28 -> V_29 , V_28 -> V_30 ) ;
return;
default:
F_10 ( V_39 , L_14 ,
V_28 -> V_29 , V_28 -> V_30 ) ;
return;
}
}
static void F_11 ( T_3 * V_44 , T_2 * V_45 , T_4 V_8 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_8 ; V_46 ++ )
V_44 [ V_46 ] = F_12 ( V_45 [ V_46 ] ) ;
}
static void F_13 ( T_2 * V_44 , T_3 * V_45 , T_4 V_8 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_8 ; V_46 ++ )
V_44 [ V_46 ] = F_14 ( V_45 [ V_46 ] ) ;
}
static T_3 F_15 ( void * V_47 , T_4 V_8 )
{
return F_12 ( ~ F_16 ( ~ 0 , V_47 , V_8 ) ) ;
}
static void F_17 ( struct V_6 * V_7 )
{
if ( V_7 ) {
F_18 ( V_7 -> V_39 -> V_48 ,
V_7 -> V_10 , V_7 -> V_11 . V_49 ) ;
F_19 ( V_7 ) ;
}
}
static struct V_6 * F_20 ( struct V_38 * V_39 )
{
struct V_6 * V_7 = F_21 ( sizeof( * V_7 ) , V_50 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_39 = V_39 ;
V_7 -> V_10 = F_22 ( V_39 -> V_48 , V_50 ,
& V_7 -> V_11 . V_49 ) ;
if ( ! V_7 -> V_10 ) {
F_19 ( V_7 ) ;
return NULL ;
}
return V_7 ;
}
static void F_23 ( struct V_51 * V_52 , struct V_53 * V_11 ,
bool V_54 )
{
struct V_6 * V_7 = F_24 ( V_11 , F_25 ( * V_7 ) , V_11 ) ;
F_17 ( V_7 ) ;
}
static int F_26 ( struct V_38 * V_39 , void * V_47 , T_4 V_8 ,
enum V_9 type )
{
int V_28 ;
struct V_6 * V_7 ;
if ( V_8 % 4 != 0 ) {
F_10 ( V_39 , L_15 , V_8 ) ;
return - V_55 ;
}
if ( V_8 > V_56 - 4 ) {
F_10 ( V_39 , L_16 ,
V_8 , V_56 - 4 ) ;
return - V_55 ;
}
V_7 = F_20 ( V_39 ) ;
if ( ! V_7 )
return - V_57 ;
V_7 -> V_11 . V_58 = F_23 ;
V_7 -> V_11 . V_12 = V_8 + 4 ;
V_7 -> V_11 . V_15 = type ;
V_7 -> V_11 . V_14 = type ;
F_11 ( V_7 -> V_10 , V_47 , V_8 / 4 ) ;
* ( T_3 * ) ( V_7 -> V_10 + V_8 ) = F_15 ( V_7 -> V_10 , V_8 ) ;
V_28 = F_27 ( V_39 -> V_59 , & V_7 -> V_11 ) ;
if ( V_28 )
F_17 ( V_7 ) ;
return V_28 ;
}
static void F_28 ( struct V_38 * V_39 ,
struct V_6 * V_26 )
{
struct V_60 * V_7 = V_26 -> V_10 ;
T_1 V_5 = F_1 ( V_7 -> V_2 ) ;
if ( F_4 ( V_26 , sizeof( * V_7 ) , V_61 , V_5 ) ) {
F_29 ( V_39 , L_17 ) ;
return;
}
if ( F_30 ( V_39 , V_5 , V_7 -> V_37 , V_62 ) )
F_29 ( V_39 , L_18 ,
V_5 , V_7 -> V_37 ) ;
F_5 ( V_7 -> V_23 , L_19 , V_7 -> V_23 ) ;
V_39 -> V_58 ( V_39 -> V_63 , V_5 , V_7 -> V_37 , V_7 -> V_64 ) ;
}
static void F_31 ( struct V_6 * V_7 )
{
F_32 ( V_7 -> V_39 -> V_65 , & V_7 -> V_11 ) ;
}
static void F_33 ( struct V_51 * V_52 , struct V_53 * V_11 ,
bool V_54 )
{
struct V_6 * V_7 = F_24 ( V_11 , F_25 ( * V_7 ) , V_11 ) ;
if ( V_54 )
return;
if ( V_11 -> V_12 < 4 || V_11 -> V_12 % 4 != 0 ) {
F_34 ( V_7 -> V_39 , L_20 ,
V_11 -> V_12 ) ;
goto V_65;
}
V_11 -> V_12 -= 4 ;
if ( * ( T_3 * ) ( V_7 -> V_10 + V_11 -> V_12 )
!= F_15 ( V_7 -> V_10 , V_11 -> V_12 ) ) {
F_34 ( V_7 -> V_39 ,
L_21 ) ;
goto V_65;
}
F_13 ( V_7 -> V_10 , V_7 -> V_10 , V_11 -> V_12 / 4 ) ;
if ( V_11 -> V_14 == V_61 ) {
F_28 ( V_7 -> V_39 , V_7 ) ;
goto V_65;
}
if ( ! F_35 ( & V_7 -> V_39 -> V_66 , V_7 ) ) {
F_34 ( V_7 -> V_39 , L_22 ) ;
goto V_65;
}
F_36 ( & V_7 -> V_39 -> V_67 ) ;
return;
V_65:
F_31 ( V_7 ) ;
}
static struct V_25 F_37 ( struct V_38 * V_39 , void * V_10 ,
T_4 V_22 , int V_68 ,
T_1 V_5 , enum V_9 type )
{
struct V_25 V_28 ;
struct V_6 * V_7 ;
if ( ! F_38 ( & V_39 -> V_67 ,
F_39 ( V_68 ) ) ) {
F_10 ( V_39 , L_23 ) ;
return (struct V_25 ) { . V_31 = - V_69 } ;
}
if ( ! F_40 ( & V_39 -> V_66 , & V_7 ) ) {
F_10 ( V_39 , L_24 ) ;
return (struct V_25 ) { . V_31 = - V_13 } ;
}
V_28 = F_8 ( V_7 , V_22 , type , V_5 ) ;
if ( ! V_28 . V_31 )
memcpy ( V_10 , V_7 -> V_10 , V_22 ) ;
F_31 ( V_7 ) ;
return V_28 ;
}
struct V_38 * F_41 ( struct V_70 * V_71 , T_5 V_72 , void * V_73 )
{
int V_46 ;
struct V_38 * V_39 = F_21 ( sizeof( * V_39 ) , V_50 ) ;
if ( ! V_39 )
return NULL ;
V_39 -> V_71 = V_71 ;
V_39 -> V_58 = V_72 ;
V_39 -> V_63 = V_73 ;
F_42 ( & V_39 -> V_67 ) ;
F_43 ( V_39 -> V_66 ) ;
V_39 -> V_48 = F_44 ( L_25 , & V_71 -> V_74 -> V_75 ,
V_56 , 4 , 0 ) ;
if ( ! V_39 -> V_48 )
goto V_31;
V_39 -> V_59 = F_45 ( V_71 , 0 , 10 ) ;
if ( ! V_39 -> V_59 )
goto V_31;
V_39 -> V_65 = F_46 ( V_71 , 0 , 10 ) ;
if ( ! V_39 -> V_65 )
goto V_31;
for ( V_46 = 0 ; V_46 < V_76 ; V_46 ++ ) {
V_39 -> V_77 [ V_46 ] = F_20 ( V_39 ) ;
if ( ! V_39 -> V_77 [ V_46 ] )
goto V_31;
V_39 -> V_77 [ V_46 ] -> V_11 . V_58 = F_33 ;
}
F_47 ( V_39 , L_26 ) ;
return V_39 ;
V_31:
F_48 ( V_39 ) ;
return NULL ;
}
void F_48 ( struct V_38 * V_39 )
{
int V_46 ;
if ( V_39 -> V_65 )
F_49 ( V_39 -> V_65 ) ;
if ( V_39 -> V_59 )
F_49 ( V_39 -> V_59 ) ;
for ( V_46 = 0 ; V_46 < V_76 ; V_46 ++ )
F_17 ( V_39 -> V_77 [ V_46 ] ) ;
if ( V_39 -> V_48 )
F_50 ( V_39 -> V_48 ) ;
F_19 ( V_39 ) ;
}
void F_51 ( struct V_38 * V_39 )
{
int V_46 ;
F_47 ( V_39 , L_27 ) ;
F_52 ( V_39 -> V_59 ) ;
F_52 ( V_39 -> V_65 ) ;
for ( V_46 = 0 ; V_46 < V_76 ; V_46 ++ )
F_31 ( V_39 -> V_77 [ V_46 ] ) ;
}
void F_53 ( struct V_38 * V_39 )
{
F_54 ( V_39 -> V_65 ) ;
F_54 ( V_39 -> V_59 ) ;
if ( ! F_55 ( & V_39 -> V_66 ) )
F_10 ( V_39 , L_28 ) ;
F_56 ( & V_39 -> V_66 ) ;
F_47 ( V_39 , L_29 ) ;
}
int F_30 ( struct V_38 * V_39 , T_1 V_5 , T_2 V_37 ,
enum F_30 error )
{
struct V_27 V_7 = {
. V_2 = F_2 ( V_5 ) ,
. V_37 = V_37 ,
. error = error ,
} ;
F_47 ( V_39 , L_30 , V_5 , V_37 ) ;
return F_26 ( V_39 , & V_7 , sizeof( V_7 ) , V_32 ) ;
}
struct V_25 F_57 ( struct V_38 * V_39 , T_1 V_5 ,
int V_68 )
{
int V_31 ;
struct V_78 V_79 = { . V_2 = F_2 (route) } ;
struct V_1 V_80 ;
V_31 = F_26 ( V_39 , & V_79 , sizeof( V_79 ) , V_81 ) ;
if ( V_31 )
return (struct V_25 ) { . V_31 = V_31 } ;
return F_37 ( V_39 , & V_80 , sizeof( V_80 ) , V_68 , V_5 ,
V_81 ) ;
}
struct V_25 F_58 ( struct V_38 * V_39 , void * V_10 ,
T_1 V_5 , T_2 V_37 , enum V_19 V_20 ,
T_2 V_21 , T_2 V_22 , int V_68 )
{
struct V_25 V_28 = { 0 } ;
struct V_82 V_79 = {
. V_2 = F_2 ( V_5 ) ,
. V_18 = {
. V_37 = V_37 ,
. V_20 = V_20 ,
. V_21 = V_21 ,
. V_22 = V_22 ,
} ,
} ;
struct V_83 V_80 ;
V_28 . V_31 = F_26 ( V_39 , & V_79 , sizeof( V_79 ) , V_84 ) ;
if ( V_28 . V_31 )
return V_28 ;
V_28 = F_37 ( V_39 , & V_80 , 12 + 4 * V_22 , V_68 , V_5 ,
V_84 ) ;
if ( V_28 . V_31 )
return V_28 ;
V_28 . V_30 = V_80 . V_18 . V_37 ;
V_28 . V_31 = F_6 ( V_80 . V_18 , V_20 , V_21 , V_22 ) ;
if ( ! V_28 . V_31 )
memcpy ( V_10 , & V_80 . V_47 , 4 * V_22 ) ;
return V_28 ;
}
struct V_25 F_59 ( struct V_38 * V_39 , void * V_10 ,
T_1 V_5 , T_2 V_37 , enum V_19 V_20 ,
T_2 V_21 , T_2 V_22 , int V_68 )
{
struct V_25 V_28 = { 0 } ;
struct V_83 V_79 = {
. V_2 = F_2 ( V_5 ) ,
. V_18 = {
. V_37 = V_37 ,
. V_20 = V_20 ,
. V_21 = V_21 ,
. V_22 = V_22 ,
} ,
} ;
struct V_82 V_80 ;
memcpy ( & V_79 . V_47 , V_10 , V_22 * 4 ) ;
V_28 . V_31 = F_26 ( V_39 , & V_79 , 12 + 4 * V_22 , V_85 ) ;
if ( V_28 . V_31 )
return V_28 ;
V_28 = F_37 ( V_39 , & V_80 , sizeof( V_80 ) , V_68 , V_5 ,
V_85 ) ;
if ( V_28 . V_31 )
return V_28 ;
V_28 . V_30 = V_80 . V_18 . V_37 ;
V_28 . V_31 = F_6 ( V_80 . V_18 , V_20 , V_21 , V_22 ) ;
return V_28 ;
}
int F_60 ( struct V_38 * V_39 , void * V_10 , T_1 V_5 , T_2 V_37 ,
enum V_19 V_20 , T_2 V_21 , T_2 V_22 )
{
struct V_25 V_28 = F_58 ( V_39 , V_10 , V_5 , V_37 ,
V_20 , V_21 , V_22 , V_86 ) ;
if ( V_28 . V_31 == 1 ) {
F_9 ( V_39 , & V_28 ) ;
return - V_13 ;
}
F_5 ( V_28 . V_31 , L_31 , V_28 . V_31 ) ;
return V_28 . V_31 ;
}
int F_61 ( struct V_38 * V_39 , void * V_10 , T_1 V_5 , T_2 V_37 ,
enum V_19 V_20 , T_2 V_21 , T_2 V_22 )
{
struct V_25 V_28 = F_59 ( V_39 , V_10 , V_5 , V_37 ,
V_20 , V_21 , V_22 , V_86 ) ;
if ( V_28 . V_31 == 1 ) {
F_9 ( V_39 , & V_28 ) ;
return - V_13 ;
}
F_5 ( V_28 . V_31 , L_32 , V_28 . V_31 ) ;
return V_28 . V_31 ;
}
int F_62 ( struct V_38 * V_39 , T_1 V_5 )
{
T_2 V_87 ;
struct V_25 V_28 = F_58 ( V_39 , & V_87 , V_5 , 0 ,
V_88 , 0 , 1 ,
V_86 ) ;
if ( V_28 . V_31 == 1 )
return - V_13 ;
if ( V_28 . V_31 )
return V_28 . V_31 ;
return V_28 . V_30 ;
}
