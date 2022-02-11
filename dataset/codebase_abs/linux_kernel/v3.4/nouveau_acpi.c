static int F_1 ( T_1 V_1 , int V_2 , int V_3 , T_2 * V_4 )
{
struct V_5 V_6 = { V_7 , NULL } ;
struct V_8 V_9 ;
union V_10 V_11 [ 4 ] ;
union V_10 * V_12 ;
int V_13 , V_14 ;
char V_15 [ 4 ] ;
V_9 . V_16 = 4 ;
V_9 . V_17 = V_11 ;
V_11 [ 0 ] . type = V_18 ;
V_11 [ 0 ] . V_19 . V_20 = sizeof( V_21 ) ;
V_11 [ 0 ] . V_19 . V_17 = ( char * ) V_21 ;
V_11 [ 1 ] . type = V_22 ;
V_11 [ 1 ] . integer . V_23 = 0x00000100 ;
V_11 [ 2 ] . type = V_22 ;
V_11 [ 2 ] . integer . V_23 = V_2 ;
V_11 [ 3 ] . type = V_18 ;
V_11 [ 3 ] . V_19 . V_20 = 4 ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ )
V_15 [ V_13 ] = ( V_3 >> V_13 * 8 ) & 0xFF ;
V_11 [ 3 ] . V_19 . V_17 = V_15 ;
V_14 = F_2 ( V_1 , L_1 , & V_9 , & V_6 ) ;
if ( V_14 ) {
F_3 ( V_24 L_2 , V_14 ) ;
return V_14 ;
}
V_12 = (union V_10 * ) V_6 . V_17 ;
if ( V_12 -> type == V_22 )
if ( V_12 -> integer . V_23 == 0x80000002 ) {
return - V_25 ;
}
if ( V_12 -> type == V_18 ) {
if ( V_12 -> V_19 . V_20 == 4 && V_4 ) {
* V_4 = 0 ;
* V_4 |= V_12 -> V_19 . V_17 [ 0 ] ;
* V_4 |= ( V_12 -> V_19 . V_17 [ 1 ] << 8 ) ;
* V_4 |= ( V_12 -> V_19 . V_17 [ 2 ] << 16 ) ;
* V_4 |= ( V_12 -> V_19 . V_17 [ 3 ] << 24 ) ;
}
}
F_4 ( V_6 . V_17 ) ;
return 0 ;
}
static int F_5 ( T_1 V_1 , int V_2 , int V_3 , T_2 * V_4 )
{
struct V_5 V_6 = { V_7 , NULL } ;
struct V_8 V_9 ;
union V_10 V_11 [ 4 ] ;
union V_10 * V_12 ;
int V_14 ;
V_9 . V_16 = 4 ;
V_9 . V_17 = V_11 ;
V_11 [ 0 ] . type = V_18 ;
V_11 [ 0 ] . V_19 . V_20 = sizeof( V_26 ) ;
V_11 [ 0 ] . V_19 . V_17 = ( char * ) V_26 ;
V_11 [ 1 ] . type = V_22 ;
V_11 [ 1 ] . integer . V_23 = 0x00000102 ;
V_11 [ 2 ] . type = V_22 ;
V_11 [ 2 ] . integer . V_23 = V_2 ;
V_11 [ 3 ] . type = V_22 ;
V_11 [ 3 ] . integer . V_23 = V_3 ;
V_14 = F_2 ( V_1 , L_1 , & V_9 , & V_6 ) ;
if ( V_14 ) {
F_3 ( V_24 L_2 , V_14 ) ;
return V_14 ;
}
V_12 = (union V_10 * ) V_6 . V_17 ;
if ( V_12 -> type == V_22 )
if ( V_12 -> integer . V_23 == 0x80000002 )
return - V_25 ;
if ( V_12 -> type == V_18 ) {
if ( V_12 -> V_19 . V_20 == 4 && V_4 ) {
* V_4 = 0 ;
* V_4 |= V_12 -> V_19 . V_17 [ 0 ] ;
* V_4 |= ( V_12 -> V_19 . V_17 [ 1 ] << 8 ) ;
* V_4 |= ( V_12 -> V_19 . V_17 [ 2 ] << 16 ) ;
* V_4 |= ( V_12 -> V_19 . V_17 [ 3 ] << 24 ) ;
}
}
F_4 ( V_6 . V_17 ) ;
return 0 ;
}
static int F_6 ( T_1 V_27 ,
int (* F_7)( T_1 , int , int , T_2 * ) ,
int V_28 )
{
T_3 V_4 = 0 ;
if ( F_7 ( V_27 , 0 , 0 , & V_4 ) )
return 0 ;
return V_4 & 1 && V_4 & ( 1 << V_28 ) ;
}
static int F_8 ( T_1 V_1 , int V_29 )
{
F_9 ( V_29 == V_30 ? V_31 : V_32 ) ;
F_10 ( V_29 == V_30 ? V_31 : V_32 ) ;
return F_5 ( V_1 , V_33 , V_29 , NULL ) ;
}
static int F_11 ( T_1 V_1 , enum V_34 V_35 )
{
int V_3 ;
if ( V_35 == V_36 )
V_3 = V_37 ;
else
V_3 = V_38 ;
F_5 ( V_1 , V_39 , V_3 , NULL ) ;
return 0 ;
}
static int F_12 ( enum V_40 V_41 )
{
if ( ! V_42 . V_43 && V_42 . V_44 )
return 0 ;
if ( V_41 == V_45 )
return F_8 ( V_42 . V_46 , V_30 ) ;
else
return F_8 ( V_42 . V_46 , V_47 ) ;
}
static int F_13 ( enum V_40 V_41 ,
enum V_34 V_35 )
{
if ( V_41 == V_45 )
return 0 ;
if ( ! V_42 . V_43 && V_42 . V_44 )
return 0 ;
return F_11 ( V_42 . V_46 , V_35 ) ;
}
static int F_14 ( void )
{
return 0 ;
}
static int F_15 ( struct V_48 * V_49 )
{
if ( V_49 -> V_50 == V_51 )
return V_45 ;
if ( V_49 -> V_52 -> V_53 == 0 )
return V_45 ;
return V_54 ;
}
static int F_16 ( struct V_48 * V_49 )
{
T_1 V_46 , V_55 ;
T_4 V_56 ;
int V_57 = 0 ;
V_46 = F_17 ( & V_49 -> V_58 ) ;
if ( ! V_46 )
return false ;
V_56 = F_18 ( V_46 , L_1 , & V_55 ) ;
if ( F_19 ( V_56 ) ) {
return false ;
}
if ( F_6 ( V_46 , F_5 , V_39 ) )
V_57 |= V_59 ;
if ( F_6 ( V_46 , F_1 ,
V_60 ) )
V_57 |= V_61 ;
if ( V_57 )
V_42 . V_46 = V_46 ;
return V_57 ;
}
static bool F_20 ( void )
{
char V_62 [ 255 ] = { 0 } ;
struct V_5 V_19 = { sizeof( V_62 ) , V_62 } ;
struct V_48 * V_49 = NULL ;
int V_63 = 0 ;
int V_64 = 0 ;
int V_65 = 0 ;
bool V_66 ;
int V_57 ;
bool V_67 = false ;
V_66 = F_21 () ;
if ( V_66 )
F_3 ( L_3 ) ;
while ( ( V_49 = F_22 ( V_68 << 8 , V_49 ) ) != NULL ) {
V_65 ++ ;
V_57 = F_16 ( V_49 ) ;
if ( V_57 & V_59 )
V_63 |= 1 ;
if ( V_57 & V_61 )
V_64 = 1 ;
}
if ( V_65 == 2 && V_63 && V_66 ) {
F_23 ( V_42 . V_46 , V_69 ,
& V_19 ) ;
F_3 ( V_24 L_4 ,
V_62 ) ;
V_42 . V_43 = true ;
V_67 = true ;
}
if ( V_64 == 1 ) {
F_23 ( V_42 . V_46 , V_69 ,
& V_19 ) ;
F_3 ( V_24 L_5 ,
V_62 ) ;
V_42 . V_44 = true ;
V_67 = true ;
}
return V_67 ;
}
void F_24 ( void )
{
bool V_70 ;
V_70 = F_20 () ;
if ( ! V_70 )
return;
F_25 ( & V_71 ) ;
}
void F_26 ( void )
{
T_3 V_4 = 0 ;
if ( ! V_42 . V_44 )
return;
F_1 ( V_42 . V_46 , V_60 ,
V_72 , & V_4 ) ;
}
void F_27 ( void )
{
F_28 () ;
}
static int F_29 ( T_1 V_73 , T_5 * V_74 ,
int V_75 , int V_76 )
{
T_4 V_56 ;
union V_10 V_77 [ 2 ] , * V_12 ;
struct V_8 V_78 ;
struct V_5 V_19 = { V_7 , NULL } ;
V_78 . V_16 = 2 ;
V_78 . V_17 = & V_77 [ 0 ] ;
V_77 [ 0 ] . type = V_22 ;
V_77 [ 0 ] . integer . V_23 = V_75 ;
V_77 [ 1 ] . type = V_22 ;
V_77 [ 1 ] . integer . V_23 = V_76 ;
V_56 = F_2 ( V_73 , NULL , & V_78 , & V_19 ) ;
if ( F_19 ( V_56 ) ) {
F_3 ( V_24 L_6 , F_30 ( V_56 ) ) ;
return - V_25 ;
}
V_12 = (union V_10 * ) V_19 . V_17 ;
memcpy ( V_74 + V_75 , V_12 -> V_19 . V_17 , V_76 ) ;
F_4 ( V_19 . V_17 ) ;
return V_76 ;
}
bool F_31 ( struct V_48 * V_49 )
{
T_4 V_56 ;
T_1 V_46 , V_73 ;
if ( ! V_42 . V_43 && ! V_42 . V_44 )
return false ;
V_46 = F_17 ( & V_49 -> V_58 ) ;
if ( ! V_46 )
return false ;
V_56 = F_18 ( V_46 , L_7 , & V_73 ) ;
if ( F_19 ( V_56 ) )
return false ;
V_42 . V_73 = V_73 ;
return true ;
}
int F_32 ( T_5 * V_74 , int V_75 , int V_76 )
{
return F_29 ( V_42 . V_73 , V_74 , V_75 , V_76 ) ;
}
int
F_33 ( struct V_79 * V_58 , struct V_80 * V_81 )
{
struct V_82 * V_83 = V_82 ( V_81 ) ;
struct V_84 * V_85 ;
T_1 V_1 ;
int type , V_67 ;
void * V_86 ;
switch ( V_81 -> V_87 ) {
case V_88 :
case V_89 :
type = V_90 ;
break;
default:
return - V_91 ;
}
V_1 = F_17 ( & V_58 -> V_49 -> V_58 ) ;
if ( ! V_1 )
return - V_25 ;
V_67 = F_34 ( V_1 , & V_85 ) ;
if ( V_67 )
return - V_25 ;
V_67 = F_35 ( V_85 , type , - 1 , & V_86 ) ;
if ( V_67 < 0 )
return V_67 ;
V_83 -> V_86 = F_36 ( V_86 , V_92 , V_93 ) ;
return 0 ;
}
