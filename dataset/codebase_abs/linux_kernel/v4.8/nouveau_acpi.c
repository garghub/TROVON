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
if ( V_7 & 1 && V_7 & ( 1 << V_19 ) )
return V_7 ;
return 0 ;
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
static bool F_16 ( struct V_41 * V_42 )
{
struct V_41 * V_48 = F_17 ( V_42 ) ;
struct V_49 * V_50 ;
if ( ! V_48 )
return false ;
if ( ! V_48 -> V_51 ) {
F_18 ( V_42 ) ;
return false ;
}
V_50 = F_19 ( & V_48 -> V_52 ) ;
if ( ! V_50 )
return false ;
return F_20 ( V_50 -> V_4 , L_2 ) ;
}
static void F_21 ( struct V_41 * V_42 , T_1 * V_53 ,
bool * V_54 , bool * V_55 ,
bool * V_56 , bool * V_57 )
{
T_1 V_39 ;
bool V_58 ;
int V_59 ;
V_39 = F_22 ( & V_42 -> V_52 ) ;
if ( ! V_39 )
return;
if ( ! F_20 ( V_39 , L_3 ) )
return;
V_58 = F_23 ( V_39 , V_23 , 0x00000102 ,
1 << V_35 ) ;
V_59 = F_7 ( V_39 ) ;
if ( ! V_58 && ! V_59 )
return;
* V_53 = V_39 ;
* V_54 = V_58 ;
* V_55 = ! ! V_59 ;
* V_56 = V_59 & ( 1 << V_60 ) ;
* V_57 = false ;
if ( V_59 ) {
T_2 V_7 ;
F_3 ( V_39 , V_19 , 0 ,
& V_7 ) ;
F_24 ( & V_42 -> V_52 , L_4 ,
( V_7 & V_61 ) ? L_5 : L_6 ,
( V_7 & V_62 ) ? L_7 : L_8 ,
( V_7 & V_63 ) ? L_9 : L_8 ) ;
* V_57 = F_16 ( V_42 ) ;
}
}
static bool F_25 ( void )
{
char V_64 [ 255 ] = { 0 } ;
struct V_65 V_13 = { sizeof( V_64 ) , V_64 } ;
struct V_41 * V_42 = NULL ;
T_1 V_39 = NULL ;
bool V_54 = false ;
bool V_66 = false ;
bool V_67 = false ;
bool V_68 = false ;
int V_69 = 0 ;
bool V_70 ;
bool V_20 = false ;
V_70 = F_26 () ;
if ( V_70 )
F_27 ( L_10 ) ;
while ( ( V_42 = F_28 ( V_71 << 8 , V_42 ) ) != NULL ) {
V_69 ++ ;
F_21 ( V_42 , & V_39 , & V_54 , & V_66 ,
& V_67 , & V_68 ) ;
}
while ( ( V_42 = F_28 ( V_72 << 8 , V_42 ) ) != NULL ) {
V_69 ++ ;
F_21 ( V_42 , & V_39 , & V_54 , & V_66 ,
& V_67 , & V_68 ) ;
}
if ( V_66 ) {
V_1 . V_39 = V_39 ;
F_29 ( V_1 . V_39 , V_73 ,
& V_13 ) ;
F_27 ( V_74 L_11 ,
V_64 ) ;
if ( V_68 )
F_30 ( L_12 ) ;
V_1 . V_2 = true ;
V_1 . V_75 = V_67 ;
V_1 . V_76 = V_68 ;
V_20 = true ;
} else if ( V_69 == 2 && V_54 && V_70 ) {
V_1 . V_39 = V_39 ;
F_29 ( V_1 . V_39 , V_73 ,
& V_13 ) ;
F_27 ( V_74 L_13 ,
V_64 ) ;
V_1 . V_3 = true ;
V_20 = true ;
}
return V_20 ;
}
void F_31 ( void )
{
bool V_77 ;
V_77 = F_25 () ;
if ( ! V_77 )
return;
F_32 ( & V_78 , 0 ) ;
}
void F_33 ( void )
{
T_3 V_7 = 0 ;
if ( ! V_1 . V_2 || V_1 . V_76 )
return;
if ( V_1 . V_75 )
F_3 ( V_1 . V_39 , V_60 ,
0x3 , & V_7 ) ;
F_3 ( V_1 . V_39 , V_19 ,
V_79 , & V_7 ) ;
}
void F_34 ( void )
{
if ( V_1 . V_2 || V_1 . V_3 )
F_35 () ;
}
void F_31 ( void ) {}
void F_34 ( void ) {}
void F_33 ( void ) {}
static int F_36 ( T_1 V_80 , T_4 * V_81 ,
int V_82 , int V_83 )
{
T_5 V_84 ;
union V_9 V_85 [ 2 ] , * V_10 ;
struct V_86 V_87 ;
struct V_65 V_13 = { V_88 , NULL } ;
V_87 . V_89 = 2 ;
V_87 . V_16 = & V_85 [ 0 ] ;
V_85 [ 0 ] . type = V_21 ;
V_85 [ 0 ] . integer . V_22 = V_82 ;
V_85 [ 1 ] . type = V_21 ;
V_85 [ 1 ] . integer . V_22 = V_83 ;
V_84 = F_37 ( V_80 , NULL , & V_87 , & V_13 ) ;
if ( F_38 ( V_84 ) ) {
F_27 ( V_74 L_14 , F_39 ( V_84 ) ) ;
return - V_24 ;
}
V_10 = (union V_9 * ) V_13 . V_16 ;
V_83 = F_40 ( V_83 , ( int ) V_10 -> V_13 . V_15 ) ;
memcpy ( V_81 + V_82 , V_10 -> V_13 . V_16 , V_83 ) ;
F_41 ( V_13 . V_16 ) ;
return V_83 ;
}
bool F_42 ( struct V_90 * V_52 )
{
T_5 V_84 ;
T_1 V_39 , V_80 ;
V_39 = F_22 ( V_52 ) ;
if ( ! V_39 )
return false ;
V_84 = F_43 ( V_39 , L_15 , & V_80 ) ;
if ( F_38 ( V_84 ) )
return false ;
V_1 . V_80 = V_80 ;
return true ;
}
int F_44 ( T_4 * V_81 , int V_82 , int V_83 )
{
return F_36 ( V_1 . V_80 , V_81 , V_82 , V_83 ) ;
}
void *
F_45 ( struct V_91 * V_52 , struct V_92 * V_93 )
{
struct V_49 * V_94 ;
T_1 V_4 ;
int type , V_20 ;
void * V_95 ;
switch ( V_93 -> V_96 ) {
case V_97 :
case V_98 :
type = V_99 ;
break;
default:
return NULL ;
}
V_4 = F_22 ( & V_52 -> V_42 -> V_52 ) ;
if ( ! V_4 )
return NULL ;
V_20 = F_46 ( V_4 , & V_94 ) ;
if ( V_20 )
return NULL ;
V_20 = F_47 ( V_94 , type , - 1 , & V_95 ) ;
if ( V_20 < 0 )
return NULL ;
return F_48 ( V_95 , V_100 , V_101 ) ;
}
