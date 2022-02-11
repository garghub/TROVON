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
return V_50 -> V_53 . V_54 . V_55 &&
F_20 ( V_50 -> V_4 , L_2 ) ;
}
static void F_21 ( struct V_41 * V_42 , T_1 * V_56 ,
bool * V_57 , bool * V_58 ,
bool * V_59 , bool * V_60 )
{
T_1 V_39 ;
bool V_61 ;
int V_62 ;
V_39 = F_22 ( & V_42 -> V_52 ) ;
if ( ! V_39 )
return;
if ( ! F_20 ( V_39 , L_3 ) )
return;
V_61 = F_23 ( V_39 , V_23 , 0x00000102 ,
1 << V_35 ) ;
V_62 = F_7 ( V_39 ) ;
if ( ! V_61 && ! V_62 )
return;
* V_56 = V_39 ;
* V_57 = V_61 ;
* V_58 = ! ! V_62 ;
* V_59 = V_62 & ( 1 << V_63 ) ;
* V_60 = false ;
if ( V_62 ) {
T_2 V_7 ;
F_3 ( V_39 , V_19 , 0 ,
& V_7 ) ;
F_24 ( & V_42 -> V_52 , L_4 ,
( V_7 & V_64 ) ? L_5 : L_6 ,
( V_7 & V_65 ) ? L_7 : L_8 ,
( V_7 & V_66 ) ? L_9 : L_8 ) ;
* V_60 = F_16 ( V_42 ) ;
}
}
static bool F_25 ( void )
{
char V_67 [ 255 ] = { 0 } ;
struct V_68 V_13 = { sizeof( V_67 ) , V_67 } ;
struct V_41 * V_42 = NULL ;
T_1 V_39 = NULL ;
bool V_57 = false ;
bool V_69 = false ;
bool V_70 = false ;
bool V_71 = false ;
int V_72 = 0 ;
bool V_73 ;
bool V_20 = false ;
V_73 = F_26 () ;
if ( V_73 )
F_27 ( L_10 ) ;
while ( ( V_42 = F_28 ( V_74 << 8 , V_42 ) ) != NULL ) {
V_72 ++ ;
F_21 ( V_42 , & V_39 , & V_57 , & V_69 ,
& V_70 , & V_71 ) ;
}
while ( ( V_42 = F_28 ( V_75 << 8 , V_42 ) ) != NULL ) {
V_72 ++ ;
F_21 ( V_42 , & V_39 , & V_57 , & V_69 ,
& V_70 , & V_71 ) ;
}
if ( V_69 ) {
V_1 . V_39 = V_39 ;
F_29 ( V_1 . V_39 , V_76 ,
& V_13 ) ;
F_27 ( V_77 L_11 ,
V_67 ) ;
if ( V_71 )
F_30 ( L_12 ) ;
V_1 . V_2 = true ;
V_1 . V_78 = V_70 ;
V_1 . V_79 = V_71 ;
V_20 = true ;
} else if ( V_72 == 2 && V_57 && V_73 ) {
V_1 . V_39 = V_39 ;
F_29 ( V_1 . V_39 , V_76 ,
& V_13 ) ;
F_27 ( V_77 L_13 ,
V_67 ) ;
V_1 . V_3 = true ;
V_20 = true ;
}
return V_20 ;
}
void F_31 ( void )
{
bool V_80 ;
V_80 = F_25 () ;
if ( ! V_80 )
return;
F_32 ( & V_81 , 0 ) ;
}
void F_33 ( void )
{
T_3 V_7 = 0 ;
if ( ! V_1 . V_2 || V_1 . V_79 )
return;
if ( V_1 . V_78 )
F_3 ( V_1 . V_39 , V_63 ,
0x3 , & V_7 ) ;
F_3 ( V_1 . V_39 , V_19 ,
V_82 , & V_7 ) ;
}
void F_34 ( void )
{
if ( V_1 . V_2 || V_1 . V_3 )
F_35 () ;
}
void F_31 ( void ) {}
void F_34 ( void ) {}
void F_33 ( void ) {}
static int F_36 ( T_1 V_83 , T_4 * V_84 ,
int V_85 , int V_86 )
{
T_5 V_87 ;
union V_9 V_88 [ 2 ] , * V_10 ;
struct V_89 V_90 ;
struct V_68 V_13 = { V_91 , NULL } ;
V_90 . V_92 = 2 ;
V_90 . V_16 = & V_88 [ 0 ] ;
V_88 [ 0 ] . type = V_21 ;
V_88 [ 0 ] . integer . V_22 = V_85 ;
V_88 [ 1 ] . type = V_21 ;
V_88 [ 1 ] . integer . V_22 = V_86 ;
V_87 = F_37 ( V_83 , NULL , & V_90 , & V_13 ) ;
if ( F_38 ( V_87 ) ) {
F_27 ( V_77 L_14 , F_39 ( V_87 ) ) ;
return - V_24 ;
}
V_10 = (union V_9 * ) V_13 . V_16 ;
V_86 = F_40 ( V_86 , ( int ) V_10 -> V_13 . V_15 ) ;
memcpy ( V_84 + V_85 , V_10 -> V_13 . V_16 , V_86 ) ;
F_41 ( V_13 . V_16 ) ;
return V_86 ;
}
bool F_42 ( struct V_93 * V_52 )
{
T_5 V_87 ;
T_1 V_39 , V_83 ;
V_39 = F_22 ( V_52 ) ;
if ( ! V_39 )
return false ;
V_87 = F_43 ( V_39 , L_15 , & V_83 ) ;
if ( F_38 ( V_87 ) )
return false ;
V_1 . V_83 = V_83 ;
return true ;
}
int F_44 ( T_4 * V_84 , int V_85 , int V_86 )
{
return F_36 ( V_1 . V_83 , V_84 , V_85 , V_86 ) ;
}
void *
F_45 ( struct V_94 * V_52 , struct V_95 * V_96 )
{
struct V_49 * V_97 ;
T_1 V_4 ;
int type , V_20 ;
void * V_98 ;
switch ( V_96 -> V_99 ) {
case V_100 :
case V_101 :
type = V_102 ;
break;
default:
return NULL ;
}
V_4 = F_22 ( & V_52 -> V_42 -> V_52 ) ;
if ( ! V_4 )
return NULL ;
V_20 = F_46 ( V_4 , & V_97 ) ;
if ( V_20 )
return NULL ;
V_20 = F_47 ( V_97 , type , - 1 , & V_98 ) ;
if ( V_20 < 0 )
return NULL ;
return F_48 ( V_98 , V_103 , V_104 ) ;
}
