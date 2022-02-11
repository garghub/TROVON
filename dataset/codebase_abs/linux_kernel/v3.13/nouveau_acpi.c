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
T_1 V_46 ;
int V_55 = 0 ;
V_46 = F_18 ( & V_49 -> V_56 ) ;
if ( ! V_46 )
return false ;
if ( ! F_19 ( V_46 , L_1 ) ) {
V_1 . V_57 = V_46 ;
return false ;
}
if ( F_8 ( V_46 , F_7 , V_42 ) )
V_55 |= V_58 ;
if ( F_8 ( V_46 , F_3 ,
V_59 ) )
V_55 |= V_60 ;
if ( V_55 & V_60 ) {
T_2 V_7 ;
F_3 ( V_46 , V_59 , 0 ,
& V_7 ) ;
F_20 ( & V_49 -> V_56 , L_3 ,
( V_7 & V_61 ) ? L_4 : L_5 ,
( V_7 & V_62 ) ? L_6 : L_7 ,
( V_7 & V_63 ) ? L_8 : L_7 ) ;
}
if ( V_55 )
V_1 . V_46 = V_46 ;
return V_55 ;
}
static bool F_21 ( void )
{
char V_64 [ 255 ] = { 0 } ;
struct V_8 V_22 = { sizeof( V_64 ) , V_64 } ;
struct V_48 * V_49 = NULL ;
int V_65 = 0 ;
int V_66 = 0 ;
int V_67 = 0 ;
bool V_68 ;
int V_55 ;
bool V_69 = false ;
V_68 = F_22 () ;
if ( V_68 )
F_5 ( L_9 ) ;
while ( ( V_49 = F_23 ( V_70 << 8 , V_49 ) ) != NULL ) {
V_67 ++ ;
V_55 = F_17 ( V_49 ) ;
if ( V_55 & V_58 )
V_65 |= 1 ;
if ( V_55 & V_60 )
V_66 = 1 ;
}
while ( ( V_49 = F_23 ( V_71 << 8 , V_49 ) ) != NULL ) {
V_67 ++ ;
V_55 = F_17 ( V_49 ) ;
if ( V_55 & V_58 )
V_65 |= 1 ;
if ( V_55 & V_60 )
V_66 = 1 ;
}
if ( V_66 == 1 ) {
F_24 ( V_1 . V_46 , V_72 ,
& V_22 ) ;
F_5 ( V_27 L_10 ,
V_64 ) ;
V_1 . V_2 = true ;
V_69 = true ;
} else if ( V_67 == 2 && V_65 && V_68 ) {
F_24 ( V_1 . V_46 , V_72 ,
& V_22 ) ;
F_5 ( V_27 L_11 ,
V_64 ) ;
V_1 . V_3 = true ;
F_25 ( V_1 . V_46 ) ;
F_25 ( V_1 . V_57 ) ;
V_69 = true ;
}
return V_69 ;
}
void F_26 ( void )
{
bool V_73 ;
V_73 = F_21 () ;
if ( ! V_73 )
return;
F_27 ( & V_74 ) ;
}
void F_28 ( void )
{
T_3 V_7 = 0 ;
if ( ! V_1 . V_2 )
return;
F_3 ( V_1 . V_46 , V_75 ,
0x3 , & V_7 ) ;
F_3 ( V_1 . V_46 , V_59 ,
V_76 , & V_7 ) ;
}
void F_29 ( void )
{
if ( V_1 . V_2 || V_1 . V_3 )
F_30 () ;
}
static int F_31 ( T_1 V_77 , T_4 * V_78 ,
int V_79 , int V_80 )
{
T_5 V_81 ;
union V_13 V_82 [ 2 ] , * V_15 ;
struct V_11 V_83 ;
struct V_8 V_22 = { V_10 , NULL } ;
V_83 . V_19 = 2 ;
V_83 . V_20 = & V_82 [ 0 ] ;
V_82 [ 0 ] . type = V_25 ;
V_82 [ 0 ] . integer . V_26 = V_79 ;
V_82 [ 1 ] . type = V_25 ;
V_82 [ 1 ] . integer . V_26 = V_80 ;
V_81 = F_4 ( V_77 , NULL , & V_83 , & V_22 ) ;
if ( F_32 ( V_81 ) ) {
F_5 ( V_27 L_12 , F_33 ( V_81 ) ) ;
return - V_28 ;
}
V_15 = (union V_13 * ) V_22 . V_20 ;
memcpy ( V_78 + V_79 , V_15 -> V_22 . V_20 , V_80 ) ;
F_6 ( V_22 . V_20 ) ;
return V_80 ;
}
bool F_34 ( struct V_48 * V_49 )
{
T_5 V_81 ;
T_1 V_46 , V_77 ;
if ( ! V_1 . V_3 && ! V_1 . V_2 )
return false ;
V_46 = F_18 ( & V_49 -> V_56 ) ;
if ( ! V_46 )
return false ;
V_81 = F_35 ( V_46 , L_13 , & V_77 ) ;
if ( F_32 ( V_81 ) )
return false ;
V_1 . V_77 = V_77 ;
return true ;
}
int F_36 ( T_4 * V_78 , int V_79 , int V_80 )
{
return F_31 ( V_1 . V_77 , V_78 , V_79 , V_80 ) ;
}
void *
F_37 ( struct V_84 * V_56 , struct V_85 * V_86 )
{
struct V_87 * V_88 ;
T_1 V_4 ;
int type , V_69 ;
void * V_89 ;
switch ( V_86 -> V_90 ) {
case V_91 :
case V_92 :
type = V_93 ;
break;
default:
return NULL ;
}
V_4 = F_18 ( & V_56 -> V_49 -> V_56 ) ;
if ( ! V_4 )
return NULL ;
V_69 = F_38 ( V_4 , & V_88 ) ;
if ( V_69 )
return NULL ;
V_69 = F_39 ( V_88 , type , - 1 , & V_89 ) ;
if ( V_69 < 0 )
return NULL ;
return F_40 ( V_89 , V_94 , V_95 ) ;
}
