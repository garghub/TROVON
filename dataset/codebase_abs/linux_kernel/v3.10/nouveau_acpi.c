bool F_1 ( void ) {
return V_1 . V_2 ;
}
bool F_2 ( void ) {
return V_1 . V_3 ;
}
static int F_3 ( T_1 V_4 , int V_5 , int V_6 , T_2 * V_7 )
{
struct V_8 V_9 = { V_10 , NULL } ;
struct V_11 V_12 ;
union V_13 V_14 [ 4 ] ;
union V_13 * V_15 ;
int V_16 , V_17 ;
char V_18 [ 4 ] ;
V_12 . V_19 = 4 ;
V_12 . V_20 = V_14 ;
V_14 [ 0 ] . type = V_21 ;
V_14 [ 0 ] . V_22 . V_23 = sizeof( V_24 ) ;
V_14 [ 0 ] . V_22 . V_20 = ( char * ) V_24 ;
V_14 [ 1 ] . type = V_25 ;
V_14 [ 1 ] . integer . V_26 = 0x00000100 ;
V_14 [ 2 ] . type = V_25 ;
V_14 [ 2 ] . integer . V_26 = V_5 ;
V_14 [ 3 ] . type = V_21 ;
V_14 [ 3 ] . V_22 . V_23 = 4 ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ )
V_18 [ V_16 ] = ( V_6 >> V_16 * 8 ) & 0xFF ;
V_14 [ 3 ] . V_22 . V_20 = V_18 ;
V_17 = F_4 ( V_4 , L_1 , & V_12 , & V_9 ) ;
if ( V_17 ) {
F_5 ( V_27 L_2 , V_17 ) ;
return V_17 ;
}
V_15 = (union V_13 * ) V_9 . V_20 ;
if ( V_15 -> type == V_25 )
if ( V_15 -> integer . V_26 == 0x80000002 ) {
return - V_28 ;
}
if ( V_15 -> type == V_21 ) {
if ( V_15 -> V_22 . V_23 == 4 && V_7 ) {
* V_7 = 0 ;
* V_7 |= V_15 -> V_22 . V_20 [ 0 ] ;
* V_7 |= ( V_15 -> V_22 . V_20 [ 1 ] << 8 ) ;
* V_7 |= ( V_15 -> V_22 . V_20 [ 2 ] << 16 ) ;
* V_7 |= ( V_15 -> V_22 . V_20 [ 3 ] << 24 ) ;
}
}
F_6 ( V_9 . V_20 ) ;
return 0 ;
}
static int F_7 ( T_1 V_4 , int V_5 , int V_6 , T_2 * V_7 )
{
struct V_8 V_9 = { V_10 , NULL } ;
struct V_11 V_12 ;
union V_13 V_14 [ 4 ] ;
union V_13 * V_15 ;
int V_17 ;
V_12 . V_19 = 4 ;
V_12 . V_20 = V_14 ;
V_14 [ 0 ] . type = V_21 ;
V_14 [ 0 ] . V_22 . V_23 = sizeof( V_29 ) ;
V_14 [ 0 ] . V_22 . V_20 = ( char * ) V_29 ;
V_14 [ 1 ] . type = V_25 ;
V_14 [ 1 ] . integer . V_26 = 0x00000102 ;
V_14 [ 2 ] . type = V_25 ;
V_14 [ 2 ] . integer . V_26 = V_5 ;
V_14 [ 3 ] . type = V_25 ;
V_14 [ 3 ] . integer . V_26 = V_6 ;
V_17 = F_4 ( V_4 , L_1 , & V_12 , & V_9 ) ;
if ( V_17 ) {
F_5 ( V_27 L_2 , V_17 ) ;
return V_17 ;
}
V_15 = (union V_13 * ) V_9 . V_20 ;
if ( V_15 -> type == V_25 )
if ( V_15 -> integer . V_26 == 0x80000002 )
return - V_28 ;
if ( V_15 -> type == V_21 ) {
if ( V_15 -> V_22 . V_23 == 4 && V_7 ) {
* V_7 = 0 ;
* V_7 |= V_15 -> V_22 . V_20 [ 0 ] ;
* V_7 |= ( V_15 -> V_22 . V_20 [ 1 ] << 8 ) ;
* V_7 |= ( V_15 -> V_22 . V_20 [ 2 ] << 16 ) ;
* V_7 |= ( V_15 -> V_22 . V_20 [ 3 ] << 24 ) ;
}
}
F_6 ( V_9 . V_20 ) ;
return 0 ;
}
static int F_8 ( T_1 V_30 ,
int (* F_9)( T_1 , int , int , T_2 * ) ,
int V_31 )
{
T_3 V_7 = 0 ;
if ( F_9 ( V_30 , 0 , 0 , & V_7 ) )
return 0 ;
return V_7 & 1 && V_7 & ( 1 << V_31 ) ;
}
static int F_10 ( T_1 V_4 , int V_32 )
{
F_11 ( V_32 == V_33 ? V_34 : V_35 ) ;
F_12 ( V_32 == V_33 ? V_34 : V_35 ) ;
return F_7 ( V_4 , V_36 , V_32 , NULL ) ;
}
static int F_13 ( T_1 V_4 , enum V_37 V_38 )
{
int V_6 ;
if ( V_38 == V_39 )
V_6 = V_40 ;
else
V_6 = V_41 ;
F_7 ( V_4 , V_42 , V_6 , NULL ) ;
return 0 ;
}
static int F_14 ( enum V_43 V_44 )
{
if ( ! V_1 . V_3 )
return 0 ;
if ( V_44 == V_45 )
return F_10 ( V_1 . V_46 , V_33 ) ;
else
return F_10 ( V_1 . V_46 , V_47 ) ;
}
static int F_15 ( enum V_43 V_44 ,
enum V_37 V_38 )
{
if ( V_44 == V_45 )
return 0 ;
if ( ! V_1 . V_3 )
return 0 ;
return F_13 ( V_1 . V_46 , V_38 ) ;
}
static int F_16 ( struct V_48 * V_49 )
{
if ( V_49 -> V_50 == V_51 )
return V_45 ;
if ( V_49 -> V_52 -> V_53 == 0 )
return V_45 ;
return V_54 ;
}
static int F_17 ( struct V_48 * V_49 )
{
T_1 V_46 , V_55 ;
T_4 V_56 ;
int V_57 = 0 ;
V_46 = F_18 ( & V_49 -> V_58 ) ;
if ( ! V_46 )
return false ;
V_56 = F_19 ( V_46 , L_1 , & V_55 ) ;
if ( F_20 ( V_56 ) ) {
return false ;
}
if ( F_8 ( V_46 , F_7 , V_42 ) )
V_57 |= V_59 ;
if ( F_8 ( V_46 , F_3 ,
V_60 ) )
V_57 |= V_61 ;
if ( V_57 )
V_1 . V_46 = V_46 ;
return V_57 ;
}
static bool F_21 ( void )
{
char V_62 [ 255 ] = { 0 } ;
struct V_8 V_22 = { sizeof( V_62 ) , V_62 } ;
struct V_48 * V_49 = NULL ;
int V_63 = 0 ;
int V_64 = 0 ;
int V_65 = 0 ;
bool V_66 ;
int V_57 ;
bool V_67 = false ;
V_66 = F_22 () ;
if ( V_66 )
F_5 ( L_3 ) ;
while ( ( V_49 = F_23 ( V_68 << 8 , V_49 ) ) != NULL ) {
V_65 ++ ;
V_57 = F_17 ( V_49 ) ;
if ( V_57 & V_59 )
V_63 |= 1 ;
if ( V_57 & V_61 )
V_64 = 1 ;
}
if ( V_64 == 1 ) {
F_24 ( V_1 . V_46 , V_69 ,
& V_22 ) ;
F_5 ( V_27 L_4 ,
V_62 ) ;
V_1 . V_2 = true ;
V_67 = true ;
} else if ( V_65 == 2 && V_63 && V_66 ) {
F_24 ( V_1 . V_46 , V_69 ,
& V_22 ) ;
F_5 ( V_27 L_5 ,
V_62 ) ;
V_1 . V_3 = true ;
V_67 = true ;
}
return V_67 ;
}
void F_25 ( void )
{
bool V_70 ;
V_70 = F_21 () ;
if ( ! V_70 )
return;
F_26 ( & V_71 ) ;
}
void F_27 ( void )
{
T_3 V_7 = 0 ;
if ( ! V_1 . V_2 )
return;
F_3 ( V_1 . V_46 , V_60 ,
V_72 , & V_7 ) ;
}
void F_28 ( void )
{
if ( V_1 . V_2 || V_1 . V_3 )
F_29 () ;
}
static int F_30 ( T_1 V_73 , T_5 * V_74 ,
int V_75 , int V_76 )
{
T_4 V_56 ;
union V_13 V_77 [ 2 ] , * V_15 ;
struct V_11 V_78 ;
struct V_8 V_22 = { V_10 , NULL } ;
V_78 . V_19 = 2 ;
V_78 . V_20 = & V_77 [ 0 ] ;
V_77 [ 0 ] . type = V_25 ;
V_77 [ 0 ] . integer . V_26 = V_75 ;
V_77 [ 1 ] . type = V_25 ;
V_77 [ 1 ] . integer . V_26 = V_76 ;
V_56 = F_4 ( V_73 , NULL , & V_78 , & V_22 ) ;
if ( F_20 ( V_56 ) ) {
F_5 ( V_27 L_6 , F_31 ( V_56 ) ) ;
return - V_28 ;
}
V_15 = (union V_13 * ) V_22 . V_20 ;
memcpy ( V_74 + V_75 , V_15 -> V_22 . V_20 , V_76 ) ;
F_6 ( V_22 . V_20 ) ;
return V_76 ;
}
bool F_32 ( struct V_48 * V_49 )
{
T_4 V_56 ;
T_1 V_46 , V_73 ;
if ( ! V_1 . V_3 && ! V_1 . V_2 )
return false ;
V_46 = F_18 ( & V_49 -> V_58 ) ;
if ( ! V_46 )
return false ;
V_56 = F_19 ( V_46 , L_7 , & V_73 ) ;
if ( F_20 ( V_56 ) )
return false ;
V_1 . V_73 = V_73 ;
return true ;
}
int F_33 ( T_5 * V_74 , int V_75 , int V_76 )
{
return F_30 ( V_1 . V_73 , V_74 , V_75 , V_76 ) ;
}
void *
F_34 ( struct V_79 * V_58 , struct V_80 * V_81 )
{
struct V_82 * V_83 ;
T_1 V_4 ;
int type , V_67 ;
void * V_84 ;
switch ( V_81 -> V_85 ) {
case V_86 :
case V_87 :
type = V_88 ;
break;
default:
return NULL ;
}
V_4 = F_18 ( & V_58 -> V_49 -> V_58 ) ;
if ( ! V_4 )
return NULL ;
V_67 = F_35 ( V_4 , & V_83 ) ;
if ( V_67 )
return NULL ;
V_67 = F_36 ( V_83 , type , - 1 , & V_84 ) ;
if ( V_67 < 0 )
return NULL ;
return F_37 ( V_84 , V_89 , V_90 ) ;
}
