bool F_1 ( void ) {
return V_1 . V_2 ;
}
bool F_2 ( void ) {
return V_1 . V_3 ;
}
static int F_3 ( T_1 V_4 , int V_5 , int V_6 , T_2 * V_7 )
{
int V_8 ;
union V_9 * V_10 ;
char V_11 [ 4 ] ;
union V_9 V_12 = {
. V_13 . type = V_14 ,
. V_13 . V_15 = 4 ,
. V_13 . V_16 = V_11
} ;
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ )
V_11 [ V_8 ] = ( V_6 >> V_8 * 8 ) & 0xFF ;
* V_7 = 0 ;
V_10 = F_4 ( V_4 , V_17 , 0x00000100 ,
V_5 , & V_12 , V_14 ) ;
if ( ! V_10 ) {
F_5 ( V_4 , L_1 ) ;
return V_18 ;
} else {
if ( V_10 -> V_13 . V_15 == 4 ) {
* V_7 |= V_10 -> V_13 . V_16 [ 0 ] ;
* V_7 |= ( V_10 -> V_13 . V_16 [ 1 ] << 8 ) ;
* V_7 |= ( V_10 -> V_13 . V_16 [ 2 ] << 16 ) ;
* V_7 |= ( V_10 -> V_13 . V_16 [ 3 ] << 24 ) ;
}
F_6 ( V_10 ) ;
}
return 0 ;
}
static int F_7 ( T_1 V_4 )
{
int V_7 ;
if ( F_3 ( V_4 , 0 , 0 , & V_7 ) )
return 0 ;
return V_7 & 1 && V_7 & ( 1 << V_19 ) ;
}
static int F_8 ( T_1 V_4 , int V_5 , int V_6 )
{
int V_20 = 0 ;
union V_9 * V_10 ;
union V_9 V_12 = {
. integer . type = V_21 ,
. integer . V_22 = V_6 ,
} ;
V_10 = F_4 ( V_4 , V_23 , 0x00000102 ,
V_5 , & V_12 , V_21 ) ;
if ( ! V_10 ) {
F_5 ( V_4 , L_1 ) ;
return V_18 ;
} else {
if ( V_10 -> integer . V_22 == 0x80000002 )
V_20 = - V_24 ;
F_6 ( V_10 ) ;
}
return V_20 ;
}
static int F_9 ( T_1 V_4 , int V_25 )
{
F_10 ( V_25 == V_26 ? V_27 : V_28 ) ;
F_11 ( V_25 == V_26 ? V_27 : V_28 ) ;
return F_8 ( V_4 , V_29 , V_25 ) ;
}
static int F_12 ( T_1 V_4 , enum V_30 V_31 )
{
int V_6 ;
if ( V_31 == V_32 )
V_6 = V_33 ;
else
V_6 = V_34 ;
F_8 ( V_4 , V_35 , V_6 ) ;
return 0 ;
}
static int F_13 ( enum V_36 V_37 )
{
if ( ! V_1 . V_3 )
return 0 ;
if ( V_37 == V_38 )
return F_9 ( V_1 . V_39 , V_26 ) ;
else
return F_9 ( V_1 . V_39 , V_40 ) ;
}
static int F_14 ( enum V_36 V_37 ,
enum V_30 V_31 )
{
if ( V_37 == V_38 )
return 0 ;
if ( ! V_1 . V_3 )
return 0 ;
return F_12 ( V_1 . V_39 , V_31 ) ;
}
static int F_15 ( struct V_41 * V_42 )
{
if ( V_42 -> V_43 == V_44 )
return V_38 ;
if ( V_42 -> V_45 -> V_46 == 0 )
return V_38 ;
return V_47 ;
}
static int F_16 ( struct V_41 * V_42 )
{
T_1 V_39 ;
int V_48 = 0 ;
V_39 = F_17 ( & V_42 -> V_49 ) ;
if ( ! V_39 )
return false ;
if ( ! F_18 ( V_39 , L_2 ) )
return false ;
if ( F_19 ( V_39 , V_23 , 0x00000102 ,
1 << V_35 ) )
V_48 |= V_50 ;
if ( F_7 ( V_39 ) )
V_48 |= V_51 ;
if ( V_48 & V_51 ) {
T_2 V_7 ;
F_3 ( V_39 , V_19 , 0 ,
& V_7 ) ;
F_20 ( & V_42 -> V_49 , L_3 ,
( V_7 & V_52 ) ? L_4 : L_5 ,
( V_7 & V_53 ) ? L_6 : L_7 ,
( V_7 & V_54 ) ? L_8 : L_7 ) ;
}
if ( V_48 )
V_1 . V_39 = V_39 ;
return V_48 ;
}
static bool F_21 ( void )
{
char V_55 [ 255 ] = { 0 } ;
struct V_56 V_13 = { sizeof( V_55 ) , V_55 } ;
struct V_41 * V_42 = NULL ;
int V_57 = 0 ;
int V_58 = 0 ;
int V_59 = 0 ;
bool V_60 ;
int V_48 ;
bool V_20 = false ;
V_60 = F_22 () ;
if ( V_60 )
F_23 ( L_9 ) ;
while ( ( V_42 = F_24 ( V_61 << 8 , V_42 ) ) != NULL ) {
V_59 ++ ;
V_48 = F_16 ( V_42 ) ;
if ( V_48 & V_50 )
V_57 |= 1 ;
if ( V_48 & V_51 )
V_58 = 1 ;
}
while ( ( V_42 = F_24 ( V_62 << 8 , V_42 ) ) != NULL ) {
V_59 ++ ;
V_48 = F_16 ( V_42 ) ;
if ( V_48 & V_50 )
V_57 |= 1 ;
if ( V_48 & V_51 )
V_58 = 1 ;
}
if ( V_58 == 1 ) {
F_25 ( V_1 . V_39 , V_63 ,
& V_13 ) ;
F_23 ( V_64 L_10 ,
V_55 ) ;
V_1 . V_2 = true ;
V_20 = true ;
} else if ( V_59 == 2 && V_57 && V_60 ) {
F_25 ( V_1 . V_39 , V_63 ,
& V_13 ) ;
F_23 ( V_64 L_11 ,
V_55 ) ;
V_1 . V_3 = true ;
V_20 = true ;
}
return V_20 ;
}
void F_26 ( void )
{
bool V_65 ;
V_65 = F_21 () ;
if ( ! V_65 )
return;
F_27 ( & V_66 , 0 ) ;
}
void F_28 ( void )
{
T_3 V_7 = 0 ;
if ( ! V_1 . V_2 )
return;
F_3 ( V_1 . V_39 , V_67 ,
0x3 , & V_7 ) ;
F_3 ( V_1 . V_39 , V_19 ,
V_68 , & V_7 ) ;
}
void F_29 ( void )
{
if ( V_1 . V_2 || V_1 . V_3 )
F_30 () ;
}
void F_26 ( void ) {}
void F_29 ( void ) {}
void F_28 ( void ) {}
static int F_31 ( T_1 V_69 , T_4 * V_70 ,
int V_71 , int V_72 )
{
T_5 V_73 ;
union V_9 V_74 [ 2 ] , * V_10 ;
struct V_75 V_76 ;
struct V_56 V_13 = { V_77 , NULL } ;
V_76 . V_78 = 2 ;
V_76 . V_16 = & V_74 [ 0 ] ;
V_74 [ 0 ] . type = V_21 ;
V_74 [ 0 ] . integer . V_22 = V_71 ;
V_74 [ 1 ] . type = V_21 ;
V_74 [ 1 ] . integer . V_22 = V_72 ;
V_73 = F_32 ( V_69 , NULL , & V_76 , & V_13 ) ;
if ( F_33 ( V_73 ) ) {
F_23 ( V_64 L_12 , F_34 ( V_73 ) ) ;
return - V_24 ;
}
V_10 = (union V_9 * ) V_13 . V_16 ;
V_72 = F_35 ( V_72 , ( int ) V_10 -> V_13 . V_15 ) ;
memcpy ( V_70 + V_71 , V_10 -> V_13 . V_16 , V_72 ) ;
F_36 ( V_13 . V_16 ) ;
return V_72 ;
}
bool F_37 ( struct V_79 * V_49 )
{
T_5 V_73 ;
T_1 V_39 , V_69 ;
V_39 = F_17 ( V_49 ) ;
if ( ! V_39 )
return false ;
V_73 = F_38 ( V_39 , L_13 , & V_69 ) ;
if ( F_33 ( V_73 ) )
return false ;
V_1 . V_69 = V_69 ;
return true ;
}
int F_39 ( T_4 * V_70 , int V_71 , int V_72 )
{
return F_31 ( V_1 . V_69 , V_70 , V_71 , V_72 ) ;
}
void *
F_40 ( struct V_80 * V_49 , struct V_81 * V_82 )
{
struct V_83 * V_84 ;
T_1 V_4 ;
int type , V_20 ;
void * V_85 ;
switch ( V_82 -> V_86 ) {
case V_87 :
case V_88 :
type = V_89 ;
break;
default:
return NULL ;
}
V_4 = F_17 ( & V_49 -> V_42 -> V_49 ) ;
if ( ! V_4 )
return NULL ;
V_20 = F_41 ( V_4 , & V_84 ) ;
if ( V_20 )
return NULL ;
V_20 = F_42 ( V_84 , type , - 1 , & V_85 ) ;
if ( V_20 < 0 )
return NULL ;
return F_43 ( V_85 , V_90 , V_91 ) ;
}
