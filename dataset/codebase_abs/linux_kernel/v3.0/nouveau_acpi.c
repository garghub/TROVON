static int F_1 ( T_1 V_1 , int V_2 , int V_3 , T_2 * V_4 )
{
struct V_5 V_6 = { V_7 , NULL } ;
struct V_8 V_9 ;
union V_10 V_11 [ 4 ] ;
union V_10 * V_12 ;
int V_13 ;
V_9 . V_14 = 4 ;
V_9 . V_15 = V_11 ;
V_11 [ 0 ] . type = V_16 ;
V_11 [ 0 ] . V_17 . V_18 = sizeof( V_19 ) ;
V_11 [ 0 ] . V_17 . V_15 = ( char * ) V_19 ;
V_11 [ 1 ] . type = V_20 ;
V_11 [ 1 ] . integer . V_21 = 0x00000100 ;
V_11 [ 2 ] . type = V_20 ;
V_11 [ 2 ] . integer . V_21 = V_2 ;
V_11 [ 3 ] . type = V_16 ;
V_11 [ 3 ] . V_17 . V_18 = 0 ;
V_13 = F_2 ( V_1 , L_1 , & V_9 , & V_6 ) ;
if ( V_13 ) {
F_3 ( V_22 L_2 , V_13 ) ;
return V_13 ;
}
V_12 = (union V_10 * ) V_6 . V_15 ;
if ( V_12 -> type == V_20 )
if ( V_12 -> integer . V_21 == 0x80000002 ) {
return - V_23 ;
}
if ( V_12 -> type == V_16 ) {
if ( V_12 -> V_17 . V_18 == 4 && V_4 ) {
* V_4 = 0 ;
* V_4 |= V_12 -> V_17 . V_15 [ 0 ] ;
* V_4 |= ( V_12 -> V_17 . V_15 [ 1 ] << 8 ) ;
* V_4 |= ( V_12 -> V_17 . V_15 [ 2 ] << 16 ) ;
* V_4 |= ( V_12 -> V_17 . V_15 [ 3 ] << 24 ) ;
}
}
F_4 ( V_6 . V_15 ) ;
return 0 ;
}
static int F_5 ( T_1 V_1 , int V_2 , int V_3 , T_2 * V_4 )
{
struct V_5 V_6 = { V_7 , NULL } ;
struct V_8 V_9 ;
union V_10 V_11 [ 4 ] ;
union V_10 * V_12 ;
int V_13 ;
V_9 . V_14 = 4 ;
V_9 . V_15 = V_11 ;
V_11 [ 0 ] . type = V_16 ;
V_11 [ 0 ] . V_17 . V_18 = sizeof( V_24 ) ;
V_11 [ 0 ] . V_17 . V_15 = ( char * ) V_24 ;
V_11 [ 1 ] . type = V_20 ;
V_11 [ 1 ] . integer . V_21 = 0x00000102 ;
V_11 [ 2 ] . type = V_20 ;
V_11 [ 2 ] . integer . V_21 = V_2 ;
V_11 [ 3 ] . type = V_20 ;
V_11 [ 3 ] . integer . V_21 = V_3 ;
V_13 = F_2 ( V_1 , L_1 , & V_9 , & V_6 ) ;
if ( V_13 ) {
F_3 ( V_22 L_2 , V_13 ) ;
return V_13 ;
}
V_12 = (union V_10 * ) V_6 . V_15 ;
if ( V_12 -> type == V_20 )
if ( V_12 -> integer . V_21 == 0x80000002 )
return - V_23 ;
if ( V_12 -> type == V_16 ) {
if ( V_12 -> V_17 . V_18 == 4 && V_4 ) {
* V_4 = 0 ;
* V_4 |= V_12 -> V_17 . V_15 [ 0 ] ;
* V_4 |= ( V_12 -> V_17 . V_15 [ 1 ] << 8 ) ;
* V_4 |= ( V_12 -> V_17 . V_15 [ 2 ] << 16 ) ;
* V_4 |= ( V_12 -> V_17 . V_15 [ 3 ] << 24 ) ;
}
}
F_4 ( V_6 . V_15 ) ;
return 0 ;
}
static int F_6 ( T_1 V_1 , int V_25 )
{
F_7 ( V_25 == V_26 ? V_27 : V_28 ) ;
F_8 ( V_25 == V_26 ? V_27 : V_28 ) ;
return F_5 ( V_1 , V_29 , V_25 , NULL ) ;
}
static int F_9 ( T_1 V_1 , enum V_30 V_31 )
{
int V_3 ;
if ( V_31 == V_32 )
V_3 = V_33 ;
else
V_3 = V_34 ;
F_5 ( V_1 , V_35 , V_3 , NULL ) ;
return 0 ;
}
static int F_10 ( enum V_36 V_37 )
{
if ( V_37 == V_38 )
return F_6 ( V_39 . V_40 , V_26 ) ;
else
return F_6 ( V_39 . V_40 , V_41 ) ;
}
static int F_11 ( enum V_36 V_37 ,
enum V_30 V_31 )
{
if ( V_37 == V_38 )
return 0 ;
return F_9 ( V_39 . V_40 , V_31 ) ;
}
static int F_12 ( void )
{
return 0 ;
}
static int F_13 ( struct V_42 * V_43 )
{
if ( V_43 -> V_44 == V_45 )
return V_38 ;
if ( V_43 -> V_46 -> V_47 == 0 )
return V_38 ;
return V_48 ;
}
static int F_14 ( struct V_42 * V_43 )
{
T_1 V_40 , V_49 ;
T_3 V_50 ;
int V_51 , V_52 = 0 ;
T_2 V_4 ;
V_40 = F_15 ( & V_43 -> V_53 ) ;
if ( ! V_40 )
return false ;
V_50 = F_16 ( V_40 , L_1 , & V_49 ) ;
if ( F_17 ( V_50 ) ) {
return false ;
}
V_51 = F_5 ( V_40 , V_54 ,
V_55 , & V_4 ) ;
if ( V_51 == 0 )
V_52 |= V_56 ;
V_51 = F_1 ( V_40 , 0 , 0 , & V_4 ) ;
if ( V_51 == 0 )
V_52 |= V_57 ;
if ( V_52 )
V_39 . V_40 = V_40 ;
return V_52 ;
}
static bool F_18 ( void )
{
char V_58 [ 255 ] = { 0 } ;
struct V_5 V_17 = { sizeof( V_58 ) , V_58 } ;
struct V_42 * V_43 = NULL ;
int V_59 = 0 ;
int V_60 ;
int V_61 = 0 ;
bool V_62 ;
int V_52 ;
bool V_51 = false ;
V_62 = F_19 () ;
if ( V_62 )
F_3 ( L_3 ) ;
while ( ( V_43 = F_20 ( V_63 << 8 , V_43 ) ) != NULL ) {
V_61 ++ ;
V_52 = F_14 ( V_43 ) ;
if ( V_52 & V_56 )
V_59 |= 1 ;
if ( V_52 & V_57 )
V_60 = 1 ;
}
if ( V_61 == 2 && V_59 && V_62 ) {
F_21 ( V_39 . V_40 , V_64 , & V_17 ) ;
F_3 ( V_22 L_4 ,
V_58 ) ;
V_39 . V_65 = true ;
V_51 = true ;
}
if ( V_60 == 1 )
V_39 . V_66 = true ;
return V_51 ;
}
void F_22 ( void )
{
bool V_67 ;
V_67 = F_18 () ;
if ( ! V_67 )
return;
F_23 ( & V_68 ) ;
}
void F_24 ( void )
{
F_25 () ;
}
static int F_26 ( T_1 V_69 , T_4 * V_70 ,
int V_71 , int V_72 )
{
T_3 V_50 ;
union V_10 V_73 [ 2 ] , * V_12 ;
struct V_8 V_74 ;
struct V_5 V_17 = { V_7 , NULL } ;
V_74 . V_14 = 2 ;
V_74 . V_15 = & V_73 [ 0 ] ;
V_73 [ 0 ] . type = V_20 ;
V_73 [ 0 ] . integer . V_21 = V_71 ;
V_73 [ 1 ] . type = V_20 ;
V_73 [ 1 ] . integer . V_21 = V_72 ;
V_50 = F_2 ( V_69 , NULL , & V_74 , & V_17 ) ;
if ( F_17 ( V_50 ) ) {
F_3 ( V_22 L_5 , F_27 ( V_50 ) ) ;
return - V_23 ;
}
V_12 = (union V_10 * ) V_17 . V_15 ;
memcpy ( V_70 + V_71 , V_12 -> V_17 . V_15 , V_72 ) ;
F_4 ( V_17 . V_15 ) ;
return V_72 ;
}
bool F_28 ( struct V_42 * V_43 )
{
T_3 V_50 ;
T_1 V_40 , V_69 ;
if ( ! V_39 . V_65 && ! V_39 . V_66 )
return false ;
V_40 = F_15 ( & V_43 -> V_53 ) ;
if ( ! V_40 )
return false ;
V_50 = F_16 ( V_40 , L_6 , & V_69 ) ;
if ( F_17 ( V_50 ) )
return false ;
V_39 . V_69 = V_69 ;
return true ;
}
int F_29 ( T_4 * V_70 , int V_71 , int V_72 )
{
return F_26 ( V_39 . V_69 , V_70 , V_71 , V_72 ) ;
}
int
F_30 ( struct V_75 * V_53 , struct V_76 * V_77 )
{
struct V_78 * V_79 = V_78 ( V_77 ) ;
struct V_80 * V_81 ;
T_1 V_1 ;
int type , V_51 ;
void * V_82 ;
switch ( V_77 -> V_83 ) {
case V_84 :
case V_85 :
type = V_86 ;
break;
default:
return - V_87 ;
}
V_1 = F_15 ( & V_53 -> V_43 -> V_53 ) ;
if ( ! V_1 )
return - V_23 ;
V_51 = F_31 ( V_1 , & V_81 ) ;
if ( V_51 )
return - V_23 ;
V_51 = F_32 ( V_81 , type , - 1 , & V_82 ) ;
if ( V_51 < 0 )
return V_51 ;
V_79 -> V_82 = F_33 ( V_82 , V_88 , V_89 ) ;
return 0 ;
}
