int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , sizeof( struct V_4 ) , 32 ) ;
F_2 ( & V_2 -> V_5 , sizeof( struct V_6 ) , 8 ) ;
F_2 ( & V_2 -> V_7 , sizeof( struct V_8 ) , 8 ) ;
F_3 ( & V_2 -> V_9 ) ;
return 0 ;
}
struct V_4 *
F_4 ( struct V_1 * V_2 , const char * V_10 ,
const struct V_4 * V_11 )
{
struct V_4 * V_12 = F_5 ( & V_2 -> V_3 ) ;
if ( ! V_12 )
return NULL ;
* V_12 = * V_11 ;
if ( V_10 )
V_12 -> V_10 = F_6 ( V_10 , V_13 ) ;
else if ( V_12 -> V_10 )
V_12 -> V_10 = F_6 ( V_12 -> V_10 , V_13 ) ;
if ( ! V_12 -> V_10 )
return NULL ;
return V_12 ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_14 ) {
struct V_4 * V_15 = V_2 -> V_3 . V_14 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_3 . V_17 ; V_16 ++ )
F_8 ( V_15 [ V_16 ] . V_10 ) ;
}
F_9 ( & V_2 -> V_3 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_7 ( V_2 ) ;
F_9 ( & V_2 -> V_5 ) ;
F_9 ( & V_2 -> V_7 ) ;
}
static void F_11 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_20 ;
V_20 = F_12 ( V_19 , L_1 ) ;
if ( V_20 >= 0 )
V_19 -> V_21 = ! V_20 ;
V_20 = F_12 ( V_19 , L_2 ) ;
if ( V_20 >= 0 )
V_19 -> V_22 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_3 ) ;
if ( V_20 >= 0 )
V_19 -> V_23 = ! V_20 ;
V_20 = F_12 ( V_19 , L_4 ) ;
if ( V_20 >= 0 )
V_19 -> V_24 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_5 ) ;
if ( V_20 >= 0 )
V_19 -> V_25 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_6 ) ;
if ( V_20 >= 0 )
V_19 -> V_26 = ! V_20 ;
V_20 = F_12 ( V_19 , L_7 ) ;
if ( V_20 >= 0 )
V_19 -> V_27 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_8 ) ;
if ( V_20 >= 0 )
V_19 -> V_28 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_9 ) ;
if ( V_20 >= 0 )
V_19 -> V_29 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_10 ) ;
if ( V_20 >= 0 )
V_2 -> V_30 = ! V_20 ;
V_20 = F_12 ( V_19 , L_11 ) ;
if ( V_20 >= 0 )
V_2 -> V_31 = ! V_20 ;
V_20 = F_12 ( V_19 , L_12 ) ;
if ( V_20 >= 0 )
V_2 -> V_32 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_13 ) ;
if ( V_20 >= 0 )
V_2 -> V_33 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_14 ) ;
if ( V_20 >= 0 )
V_2 -> V_34 = ! V_20 ;
V_20 = F_12 ( V_19 , L_15 ) ;
if ( V_20 >= 0 )
V_2 -> V_35 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_16 ) ;
if ( V_20 >= 0 )
V_2 -> V_36 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_17 ) ;
if ( V_20 >= 0 )
V_2 -> V_37 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_18 ) ;
if ( V_20 >= 0 )
V_2 -> V_38 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_19 ) ;
if ( V_20 >= 0 )
V_2 -> V_39 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_20 ) ;
if ( V_20 >= 0 )
V_2 -> V_40 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_21 ) ;
if ( V_20 >= 0 )
V_2 -> V_41 = ! ! V_20 ;
if ( ! F_13 ( V_19 , L_22 , & V_20 ) )
V_2 -> V_42 = V_20 ;
}
static inline void F_14 ( struct V_18 * V_19 , T_1 V_43 )
{
F_15 ( V_19 , V_43 , F_16 ( V_19 , V_43 ) ) ;
}
static void F_17 ( struct V_18 * V_19 , T_1 V_43 ,
unsigned int V_20 , bool V_44 )
{
if ( ! V_43 )
return;
V_20 = F_18 ( V_19 , V_43 , V_20 ) ;
F_19 ( V_19 , V_43 , V_20 ) ;
if ( V_44 )
F_15 ( V_19 , V_43 , V_20 ) ;
}
static void F_20 ( struct V_18 * V_19 , int V_45 ,
T_1 * V_46 , unsigned int V_20 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_45 ; V_16 ++ )
F_17 ( V_19 , V_46 [ V_16 ] , V_20 , false ) ;
}
static int F_21 ( T_1 V_47 , const T_1 * V_14 , int V_48 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ )
if ( V_14 [ V_16 ] == V_47 )
return V_16 ;
return - 1 ;
}
static bool F_22 ( struct V_6 * V_49 , T_1 V_47 )
{
return F_21 ( V_47 , V_49 -> V_49 , V_49 -> V_50 ) >= 0 ;
}
static struct V_6 * F_23 ( struct V_18 * V_19 ,
T_1 V_51 , T_1 V_52 ,
int V_53 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 . V_17 ; V_16 ++ ) {
struct V_6 * V_49 = F_24 ( & V_2 -> V_5 , V_16 ) ;
if ( V_49 -> V_50 <= 0 )
continue;
if ( ( ! V_51 || V_49 -> V_49 [ 0 ] == V_51 ) &&
( ! V_52 || V_49 -> V_49 [ V_49 -> V_50 - 1 ] == V_52 ) ) {
if ( ! V_53 ||
( V_53 > 0 && F_22 ( V_49 , V_53 ) ) ||
( V_53 < 0 && ! F_22 ( V_49 , V_53 ) ) )
return V_49 ;
}
}
return NULL ;
}
struct V_6 * F_25 ( struct V_18 * V_19 ,
T_1 V_51 , T_1 V_52 )
{
return F_23 ( V_19 , V_51 , V_52 , 0 ) ;
}
int F_26 ( struct V_18 * V_19 , struct V_6 * V_49 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_54 = V_2 -> V_5 . V_14 ;
T_2 V_55 ;
if ( ! V_2 -> V_5 . V_17 )
return 0 ;
V_55 = V_49 - V_54 ;
if ( V_55 < 0 || V_55 >= V_2 -> V_5 . V_17 )
return 0 ;
return V_55 + 1 ;
}
struct V_6 * F_27 ( struct V_18 * V_19 , int V_55 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_55 <= 0 || V_55 > V_2 -> V_5 . V_17 )
return NULL ;
return F_24 ( & V_2 -> V_5 , V_55 - 1 ) ;
}
static bool F_28 ( struct V_18 * V_19 , T_1 V_47 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 . V_17 ; V_16 ++ ) {
struct V_6 * V_49 = F_24 ( & V_2 -> V_5 , V_16 ) ;
if ( V_49 -> V_49 [ 0 ] == V_47 )
return true ;
}
return false ;
}
static bool F_29 ( struct V_18 * V_19 ,
T_1 V_51 , T_1 V_52 )
{
if ( ! V_51 || ! V_52 )
return false ;
return F_30 ( V_19 , V_52 , V_51 , true ) >= 0 ;
}
static bool F_31 ( struct V_18 * V_19 , unsigned int V_20 , int type )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
V_20 &= V_56 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 . V_17 ; V_16 ++ ) {
struct V_6 * V_49 = F_24 ( & V_2 -> V_5 , V_16 ) ;
if ( ( V_49 -> V_57 [ type ] & V_56 ) == V_20 )
return true ;
}
return false ;
}
static bool F_32 ( struct V_18 * V_19 , T_1 V_47 ,
int V_58 , int V_55 , int type )
{
unsigned int V_20 = F_33 ( V_47 , 3 , V_55 , V_58 ) ;
return F_31 ( V_19 , V_20 , type ) ;
}
static void F_34 ( const char * V_59 , struct V_6 * V_49 )
{
char V_60 [ 40 ] ;
int V_16 ;
V_60 [ 0 ] = 0 ;
for ( V_16 = 0 ; V_16 < V_49 -> V_50 ; V_16 ++ ) {
char V_61 [ 4 ] ;
sprintf ( V_61 , L_23 , V_49 -> V_49 [ V_16 ] ) ;
F_35 ( V_60 , V_61 , sizeof( V_60 ) ) ;
}
F_36 ( L_24 , V_59 , V_49 -> V_50 , V_60 ) ;
}
static bool F_37 ( struct V_18 * V_19 ,
T_1 V_51 , T_1 V_52 ,
int V_53 , struct V_6 * V_49 ,
int V_50 )
{
const T_1 * V_62 ;
int V_16 , V_48 ;
if ( V_52 == V_53 )
V_53 = 0 ;
else if ( V_52 == ( T_1 ) ( - V_53 ) )
return false ;
V_48 = F_38 ( V_19 , V_52 , & V_62 ) ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
if ( V_62 [ V_16 ] != V_51 ) {
if ( V_51 ||
F_39 ( F_40 ( V_19 , V_62 [ V_16 ] ) ) != V_63 ||
F_28 ( V_19 , V_62 [ V_16 ] ) )
continue;
}
if ( V_53 <= 0 )
goto V_64;
}
if ( V_50 >= V_65 )
return false ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
unsigned int type ;
type = F_39 ( F_40 ( V_19 , V_62 [ V_16 ] ) ) ;
if ( type == V_63 || type == V_66 ||
type == V_67 )
continue;
if ( F_37 ( V_19 , V_51 , V_62 [ V_16 ] ,
V_53 , V_49 , V_50 + 1 ) )
goto V_64;
}
return false ;
V_64:
V_49 -> V_49 [ V_49 -> V_50 ] = V_62 [ V_16 ] ;
V_49 -> V_55 [ V_49 -> V_50 + 1 ] = V_16 ;
if ( V_48 > 1 && F_39 ( F_40 ( V_19 , V_52 ) ) != V_68 )
V_49 -> V_69 [ V_49 -> V_50 + 1 ] = 1 ;
V_49 -> V_50 ++ ;
return true ;
}
bool F_41 ( struct V_18 * V_19 , T_1 V_51 ,
T_1 V_52 , int V_53 ,
struct V_6 * V_49 )
{
if ( F_37 ( V_19 , V_51 , V_52 , V_53 , V_49 , 1 ) ) {
V_49 -> V_49 [ V_49 -> V_50 ] = V_52 ;
V_49 -> V_50 ++ ;
return true ;
}
return false ;
}
struct V_6 *
F_42 ( struct V_18 * V_19 , T_1 V_51 ,
T_1 V_52 , int V_53 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_49 ;
if ( V_51 && V_52 && ! F_29 ( V_19 , V_51 , V_52 ) )
return NULL ;
V_49 = F_23 ( V_19 , V_51 , V_52 , V_53 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_5 ( & V_2 -> V_5 ) ;
if ( ! V_49 )
return NULL ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
if ( F_41 ( V_19 , V_51 , V_52 , V_53 , V_49 ) )
return V_49 ;
V_2 -> V_5 . V_17 -- ;
return NULL ;
}
static void F_43 ( struct V_18 * V_19 , int V_55 )
{
struct V_6 * V_49 = F_27 ( V_19 , V_55 ) ;
if ( ! V_49 )
return;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
}
static T_1 F_44 ( struct V_18 * V_19 , T_1 V_43 ,
bool V_70 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_71 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_72 ; V_16 ++ ) {
T_1 V_47 = V_2 -> V_73 [ V_16 ] ;
if ( ! V_47 || F_28 ( V_19 , V_47 ) )
continue;
V_71 = ! ! ( F_40 ( V_19 , V_47 ) & V_74 ) ;
if ( V_70 != V_71 )
continue;
if ( F_29 ( V_19 , V_47 , V_43 ) )
return V_47 ;
}
return 0 ;
}
static unsigned int F_45 ( unsigned int V_20 , unsigned int V_75 )
{
V_20 &= ~ ( 0x3U << 16 ) ;
V_20 |= V_75 << 16 ;
return V_20 ;
}
static bool F_46 ( struct V_18 * V_19 , T_1 V_47 ,
int V_58 , unsigned int V_76 )
{
if ( ! V_47 )
return false ;
if ( F_40 ( V_19 , V_47 ) & ( 1 << ( V_58 + 1 ) ) )
if ( F_47 ( V_19 , V_47 , V_58 ) & V_76 )
return true ;
return false ;
}
static bool F_48 ( struct V_18 * V_19 , T_1 V_77 ,
T_1 V_78 , int V_58 )
{
if ( ! ( F_40 ( V_19 , V_77 ) & ( 1 << ( V_58 + 1 ) ) ) )
return ! ( F_40 ( V_19 , V_78 ) & ( 1 << ( V_58 + 1 ) ) ) ;
return ( F_47 ( V_19 , V_77 , V_58 ) ==
F_47 ( V_19 , V_78 , V_58 ) ) ;
}
static T_1 F_49 ( struct V_18 * V_19 ,
struct V_6 * V_49 )
{
int V_16 ;
for ( V_16 = V_49 -> V_50 - 1 ; V_16 >= 0 ; V_16 -- ) {
if ( F_50 ( V_19 , V_49 -> V_49 [ V_16 ] , V_79 ) )
return V_49 -> V_49 [ V_16 ] ;
if ( V_16 != V_49 -> V_50 - 1 && V_16 != 0 &&
F_50 ( V_19 , V_49 -> V_49 [ V_16 ] , V_80 ) )
return V_49 -> V_49 [ V_16 ] ;
}
return 0 ;
}
static T_1 F_51 ( struct V_18 * V_19 ,
struct V_6 * V_49 )
{
int V_16 ;
for ( V_16 = V_49 -> V_50 - 1 ; V_16 >= 0 ; V_16 -- ) {
if ( F_52 ( V_19 , V_49 -> V_49 [ V_16 ] , V_79 ) )
return V_49 -> V_49 [ V_16 ] ;
}
return 0 ;
}
static bool F_53 ( struct V_18 * V_19 , struct V_6 * V_49 , int V_55 )
{
T_1 V_47 = V_49 -> V_49 [ V_55 ] ;
unsigned int V_81 = F_40 ( V_19 , V_47 ) ;
unsigned int type = F_39 ( V_81 ) ;
if ( ! ( V_81 & V_82 ) )
return false ;
if ( type == V_67 && V_55 > 0 )
return false ;
return true ;
}
static bool F_54 ( struct V_18 * V_19 , struct V_6 * V_49 , int V_55 )
{
T_1 V_47 = V_49 -> V_49 [ V_55 ] ;
unsigned int V_81 = F_40 ( V_19 , V_47 ) ;
unsigned int type = F_39 ( V_81 ) ;
if ( ! ( V_81 & V_83 ) )
return false ;
if ( type == V_67 && ! V_55 )
return false ;
return true ;
}
static bool F_55 ( struct V_18 * V_19 , T_1 V_47 ,
unsigned int V_58 , unsigned int V_55 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_84 ;
for ( V_84 = 0 ; V_84 < V_2 -> V_5 . V_17 ; V_84 ++ ) {
struct V_6 * V_49 = F_24 ( & V_2 -> V_5 , V_84 ) ;
if ( ! V_49 -> V_85 )
continue;
for ( V_16 = 0 ; V_16 < V_49 -> V_50 ; V_16 ++ ) {
if ( V_49 -> V_49 [ V_16 ] == V_47 ) {
if ( V_58 == V_79 || V_49 -> V_55 [ V_16 ] == V_55 )
return true ;
break;
}
}
}
return false ;
}
static int F_56 ( struct V_18 * V_19 , T_1 V_47 ,
int V_58 , unsigned int V_81 , bool V_86 )
{
unsigned int V_20 = 0 ;
if ( V_81 & V_87 ) {
if ( V_86 )
V_20 = ( V_81 & V_88 ) >> V_89 ;
}
if ( V_81 & V_90 ) {
if ( ! V_86 )
V_20 |= V_91 ;
}
return V_20 ;
}
static void F_57 ( struct V_18 * V_19 , T_1 V_47 , int V_58 , int V_55 )
{
unsigned int V_81 = F_47 ( V_19 , V_47 , V_58 ) ;
int V_20 = F_56 ( V_19 , V_47 , V_58 , V_81 , false ) ;
F_58 ( V_19 , V_47 , V_58 , V_55 , 0xff , V_20 ) ;
}
static unsigned int F_59 ( struct V_18 * V_19 ,
T_1 V_47 , int V_58 , int V_55 ,
unsigned int V_81 )
{
unsigned int V_92 = 0xff ;
if ( V_81 & V_90 ) {
if ( F_32 ( V_19 , V_47 , V_58 , V_55 , V_93 ) )
V_92 &= ~ 0x80 ;
}
if ( V_81 & V_87 ) {
if ( F_32 ( V_19 , V_47 , V_58 , V_55 , V_94 ) ||
F_32 ( V_19 , V_47 , V_58 , V_55 , V_95 ) )
V_92 &= ~ 0x7f ;
}
return V_92 ;
}
static void F_60 ( struct V_18 * V_19 , T_1 V_47 , int V_58 ,
int V_55 , int V_96 , bool V_86 )
{
unsigned int V_81 ;
unsigned int V_92 , V_20 ;
if ( ! V_86 && F_55 ( V_19 , V_47 , V_58 , V_96 ) )
return;
V_81 = F_47 ( V_19 , V_47 , V_58 ) ;
V_20 = F_56 ( V_19 , V_47 , V_58 , V_81 , V_86 ) ;
V_92 = F_59 ( V_19 , V_47 , V_58 , V_96 , V_81 ) ;
if ( ! V_92 )
return;
V_20 &= V_92 ;
F_61 ( V_19 , V_47 , V_58 , V_55 , V_92 , V_20 ) ;
}
static void F_62 ( struct V_18 * V_19 , struct V_6 * V_49 ,
int V_16 , bool V_86 )
{
T_1 V_47 = V_49 -> V_49 [ V_16 ] ;
F_57 ( V_19 , V_47 , V_79 , 0 ) ;
F_60 ( V_19 , V_47 , V_79 , 0 , 0 , V_86 ) ;
}
static void F_63 ( struct V_18 * V_19 , struct V_6 * V_49 ,
int V_16 , bool V_86 , bool V_97 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const T_1 * V_62 ;
int V_84 , V_48 , V_55 ;
int type ;
T_1 V_47 = V_49 -> V_49 [ V_16 ] ;
V_48 = F_38 ( V_19 , V_47 , & V_62 ) ;
type = F_39 ( F_40 ( V_19 , V_47 ) ) ;
if ( type == V_67 ||
( type == V_66 && V_19 -> V_29 ) ) {
V_48 = 1 ;
V_55 = 0 ;
} else
V_55 = V_49 -> V_55 [ V_16 ] ;
for ( V_84 = 0 ; V_84 < V_48 ; V_84 ++ )
F_57 ( V_19 , V_47 , V_80 , V_84 ) ;
for ( V_84 = 0 ; V_84 < V_48 ; V_84 ++ ) {
if ( V_84 != V_55 && ( ! V_97 || V_62 [ V_84 ] != V_2 -> V_98 ) )
continue;
F_60 ( V_19 , V_47 , V_80 , V_84 , V_55 , V_86 ) ;
}
}
void F_64 ( struct V_18 * V_19 , struct V_6 * V_49 ,
bool V_86 , bool V_97 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
if ( ! V_86 )
V_49 -> V_85 = false ;
for ( V_16 = V_49 -> V_50 - 1 ; V_16 >= 0 ; V_16 -- ) {
T_1 V_47 = V_49 -> V_49 [ V_16 ] ;
if ( V_86 && V_2 -> V_41 ) {
if ( ! F_65 ( V_19 , V_47 , V_99 ) )
F_66 ( V_19 , V_47 , 0 ,
V_100 ,
V_99 ) ;
}
if ( V_86 && V_49 -> V_69 [ V_16 ] )
F_67 ( V_19 , V_47 , 0 ,
V_101 ,
V_49 -> V_55 [ V_16 ] ) ;
if ( F_53 ( V_19 , V_49 , V_16 ) )
F_63 ( V_19 , V_49 , V_16 , V_86 , V_97 ) ;
if ( F_54 ( V_19 , V_49 , V_16 ) )
F_62 ( V_19 , V_49 , V_16 , V_86 ) ;
}
if ( V_86 )
V_49 -> V_85 = true ;
}
static void F_68 ( struct V_18 * V_19 , struct V_6 * V_49 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_102 = false ;
int V_16 ;
if ( ! V_2 -> V_41 || V_49 -> V_85 )
return;
for ( V_16 = 0 ; V_16 < V_49 -> V_50 ; V_16 ++ ) {
T_1 V_47 = V_49 -> V_49 [ V_16 ] ;
if ( ! F_65 ( V_19 , V_47 , V_103 ) ) {
F_66 ( V_19 , V_47 , 0 ,
V_100 ,
V_103 ) ;
V_102 = true ;
}
}
if ( V_102 ) {
F_69 ( 10 ) ;
F_70 ( V_19 , V_49 -> V_49 [ 0 ] , 0 ,
V_104 , 0 ) ;
}
}
static void F_71 ( struct V_18 * V_19 , T_1 V_43 , bool V_86 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_105 ||
! ( F_72 ( V_19 , V_43 ) & V_106 ) )
return;
if ( V_19 -> V_24 )
V_86 = ! V_86 ;
F_73 ( V_19 , V_43 , 0 ,
V_107 ,
V_86 ? 0x02 : 0x00 ) ;
}
static void F_74 ( struct V_18 * V_19 , int V_108 )
{
struct V_6 * V_49 = F_27 ( V_19 , V_108 ) ;
if ( V_49 )
F_64 ( V_19 , V_49 , V_49 -> V_85 , false ) ;
}
static struct V_4 *
F_75 ( struct V_1 * V_2 , int type , const char * V_10 ,
int V_109 , unsigned long V_20 )
{
struct V_4 * V_12 ;
V_12 = F_4 ( V_2 , V_10 , & V_110 [ type ] ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_111 = V_109 ;
if ( F_76 ( V_20 ) )
V_12 -> V_112 = V_113 ;
V_12 -> V_114 = V_20 ;
return V_12 ;
}
static int F_77 ( struct V_1 * V_2 , int type ,
const char * V_59 , const char * V_58 ,
const char * V_115 , int V_109 , unsigned long V_20 )
{
char V_10 [ 32 ] ;
snprintf ( V_10 , sizeof( V_10 ) , L_25 , V_59 , V_58 , V_115 ) ;
if ( ! F_75 ( V_2 , type , V_10 , V_109 , V_20 ) )
return - V_116 ;
return 0 ;
}
static int F_78 ( struct V_18 * V_19 , const char * V_59 , int V_109 ,
unsigned int V_75 , struct V_6 * V_49 )
{
unsigned int V_20 ;
if ( ! V_49 )
return 0 ;
V_20 = V_49 -> V_57 [ V_94 ] ;
if ( ! V_20 )
return 0 ;
V_20 = F_45 ( V_20 , V_75 ) ;
return F_79 ( V_19 -> V_2 , V_117 , V_59 , V_109 , V_20 ) ;
}
static int F_80 ( struct V_18 * V_19 , struct V_6 * V_49 ,
int type )
{
int V_75 = 1 ;
if ( V_49 ) {
T_1 V_47 = F_76 ( V_49 -> V_57 [ type ] ) ;
if ( V_47 && ( F_40 ( V_19 , V_47 ) & V_118 ) )
V_75 = 3 ;
}
return V_75 ;
}
static int F_81 ( struct V_18 * V_19 , const char * V_59 , int V_109 ,
struct V_6 * V_49 )
{
int V_75 = F_80 ( V_19 , V_49 , V_94 ) ;
return F_78 ( V_19 , V_59 , V_109 , V_75 , V_49 ) ;
}
static int F_82 ( struct V_18 * V_19 , const char * V_59 , int V_109 ,
unsigned int V_75 , struct V_6 * V_49 )
{
unsigned int V_20 ;
int type = V_119 ;
if ( ! V_49 )
return 0 ;
V_20 = V_49 -> V_57 [ V_93 ] ;
if ( ! V_20 )
return 0 ;
V_20 = F_45 ( V_20 , V_75 ) ;
if ( F_83 ( V_20 ) == V_80 ) {
T_1 V_47 = F_76 ( V_20 ) ;
int V_48 = F_84 ( V_19 , V_47 ) ;
if ( V_48 > 1 ) {
type = V_120 ;
V_20 |= V_48 << 19 ;
}
}
return F_85 ( V_19 -> V_2 , type , V_59 , V_109 , V_20 ) ;
}
static int F_86 ( struct V_18 * V_19 , const char * V_59 ,
int V_109 , struct V_6 * V_49 )
{
int V_75 = F_80 ( V_19 , V_49 , V_93 ) ;
return F_82 ( V_19 , V_59 , V_109 , V_75 , V_49 ) ;
}
static bool F_87 ( struct V_18 * V_19 , int V_108 , int V_121 )
{
struct V_6 * V_49 = F_27 ( V_19 , V_108 ) ;
return V_49 && V_49 -> V_57 [ V_121 ] ;
}
static const char * F_88 ( struct V_18 * V_19 , int V_122 ,
int * V_111 , int V_121 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_123 * V_124 = & V_2 -> V_125 ;
* V_111 = 0 ;
if ( V_124 -> V_126 == 1 && ! V_2 -> V_127 &&
! V_124 -> V_128 && ! V_124 -> V_129 )
return V_2 -> V_130 . V_131 ? L_26 : L_27 ;
if ( V_2 -> V_132 . V_133 == 1 && ! V_2 -> V_42 &&
! V_2 -> V_132 . V_134 [ 0 ] && ! V_2 -> V_132 . V_135 [ 0 ] )
return V_2 -> V_130 . V_131 ? L_26 : L_27 ;
if ( V_122 >= V_124 -> V_126 )
return V_136 [ V_122 ] ;
switch ( V_124 -> V_137 ) {
case V_138 :
if ( ! V_122 && V_124 -> V_128 &&
! F_87 ( V_19 , V_2 -> V_139 [ 0 ] , V_121 ) )
break;
if ( V_124 -> V_126 == 1 )
return L_28 ;
if ( V_124 -> V_126 == 2 )
return V_122 ? L_29 : L_28 ;
break;
case V_140 :
if ( ! V_122 && V_124 -> V_129 &&
! F_87 ( V_19 , V_2 -> V_141 [ 0 ] , V_121 ) )
break;
if ( V_122 && V_2 -> V_127 )
break;
* V_111 = V_122 ;
return L_30 ;
}
if ( V_124 -> V_126 == 1 && ! V_2 -> V_127 )
return L_26 ;
if ( V_122 >= F_89 ( V_136 ) ) {
F_90 () ;
return L_26 ;
}
return V_136 [ V_122 ] ;
}
static int F_91 ( struct V_18 * V_19 , struct V_6 * V_49 )
{
T_1 V_47 ;
unsigned int V_20 ;
int V_142 = 0 ;
if ( ! V_49 )
return V_143 * 2 ;
if ( V_49 -> V_57 [ V_94 ] ||
V_49 -> V_57 [ V_93 ] )
return 0 ;
V_47 = F_51 ( V_19 , V_49 ) ;
if ( V_47 ) {
V_20 = F_33 ( V_47 , 3 , 0 , V_79 ) ;
if ( F_31 ( V_19 , V_20 , V_94 ) )
V_142 += V_143 ;
else
V_49 -> V_57 [ V_94 ] = V_20 ;
} else
V_142 += V_143 ;
V_47 = F_49 ( V_19 , V_49 ) ;
if ( V_47 ) {
unsigned int V_144 = F_39 ( F_40 ( V_19 , V_47 ) ) ;
if ( V_144 == V_67 || V_144 == V_63 ||
F_50 ( V_19 , V_47 , V_79 ) )
V_20 = F_33 ( V_47 , 3 , 0 , V_79 ) ;
else
V_20 = F_33 ( V_47 , 3 , 0 , V_80 ) ;
if ( F_31 ( V_19 , V_20 , V_93 ) )
V_142 += V_143 ;
else
V_49 -> V_57 [ V_93 ] = V_20 ;
} else
V_142 += V_143 ;
return V_142 ;
}
static T_1 F_92 ( struct V_18 * V_19 , int V_55 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_123 * V_124 = & V_2 -> V_125 ;
if ( V_124 -> V_126 > V_55 )
return V_2 -> V_145 [ V_55 ] ;
V_55 -= V_124 -> V_126 ;
if ( V_2 -> V_127 > V_55 )
return V_2 -> V_146 [ V_55 ] . V_147 ;
return 0 ;
}
static inline T_1 F_93 ( struct V_18 * V_19 ,
T_1 V_147 , T_1 V_43 )
{
return F_29 ( V_19 , V_147 , V_43 ) ? V_147 : 0 ;
}
static int F_94 ( struct V_18 * V_19 , int V_148 ,
const T_1 * V_46 , T_1 * V_149 ,
int * V_108 ,
const struct V_150 * V_151 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_152 ;
int V_142 = 0 ;
T_1 V_147 ;
if ( ! V_148 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_148 ; V_16 ++ ) {
struct V_6 * V_49 ;
T_1 V_43 = V_46 [ V_16 ] ;
V_49 = F_27 ( V_19 , V_108 [ V_16 ] ) ;
if ( V_49 ) {
V_142 += F_91 ( V_19 , V_49 ) ;
continue;
}
V_149 [ V_16 ] = F_44 ( V_19 , V_43 , false ) ;
if ( ! V_149 [ V_16 ] && ! V_16 ) {
for ( V_152 = 1 ; V_152 < V_148 ; V_152 ++ ) {
if ( F_29 ( V_19 , V_149 [ V_152 ] , V_43 ) ) {
V_149 [ 0 ] = V_149 [ V_152 ] ;
V_149 [ V_152 ] = 0 ;
F_43 ( V_19 , V_108 [ V_152 ] ) ;
V_108 [ V_152 ] = 0 ;
break;
}
}
}
V_147 = V_149 [ V_16 ] ;
if ( ! V_147 ) {
if ( V_148 > 2 )
V_147 = F_93 ( V_19 , F_92 ( V_19 , V_16 ) , V_43 ) ;
if ( ! V_147 )
V_147 = F_93 ( V_19 , V_149 [ 0 ] , V_43 ) ;
if ( ! V_147 )
V_147 = F_93 ( V_19 , F_92 ( V_19 , V_16 ) , V_43 ) ;
if ( V_147 ) {
if ( ! V_16 )
V_142 += V_151 -> V_153 ;
else if ( V_16 == 1 )
V_142 += V_151 -> V_154 ;
else
V_142 += V_151 -> V_155 ;
} else if ( F_29 ( V_19 , V_2 -> V_145 [ 0 ] , V_43 ) ) {
V_147 = V_2 -> V_145 [ 0 ] ;
V_142 += V_151 -> V_156 ;
} else if ( ! V_16 )
V_142 += V_151 -> V_157 ;
else
V_142 += V_151 -> V_158 ;
}
if ( ! V_147 )
continue;
V_49 = F_42 ( V_19 , V_147 , V_43 , - V_2 -> V_42 ) ;
if ( ! V_49 && ! V_16 && V_2 -> V_42 ) {
V_49 = F_42 ( V_19 , V_147 , V_43 , 0 ) ;
}
if ( ! V_49 ) {
V_147 = V_149 [ V_16 ] = 0 ;
V_142 += V_151 -> V_158 ;
} else {
V_49 -> V_85 = true ;
V_108 [ V_16 ] = F_26 ( V_19 , V_49 ) ;
V_142 += F_91 ( V_19 , V_49 ) ;
}
}
return V_142 ;
}
static T_1 F_95 ( struct V_18 * V_19 , T_1 V_43 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_159 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_72 ; V_16 ++ ) {
T_1 V_47 = V_2 -> V_73 [ V_16 ] ;
if ( ! V_47 || F_28 ( V_19 , V_47 ) )
continue;
if ( F_29 ( V_19 , V_47 , V_43 ) ) {
if ( V_159 )
return 0 ;
V_159 = V_47 ;
}
}
return V_159 ;
}
static bool F_96 ( struct V_18 * V_19 ,
unsigned int V_160 , T_1 V_47 )
{
unsigned int V_161 , V_81 ;
V_161 = F_97 ( V_19 , V_47 ) ;
if ( F_98 ( V_161 ) != V_162 )
return false ;
if ( V_160 && F_99 ( V_161 ) != V_160 )
return false ;
V_81 = F_72 ( V_19 , V_47 ) ;
if ( ! ( V_81 & V_163 ) )
return false ;
return true ;
}
static int F_100 ( struct V_18 * V_19 , T_1 V_164 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_123 * V_124 = & V_2 -> V_125 ;
unsigned int V_161 = F_97 ( V_19 , V_164 ) ;
unsigned int V_160 = F_99 ( V_161 ) ;
int type , V_16 ;
int V_45 = 0 ;
for ( type = V_165 ; type >= V_166 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_124 -> V_167 ; V_16 ++ ) {
if ( V_124 -> V_168 [ V_16 ] . type != type )
continue;
if ( F_96 ( V_19 , V_160 ,
V_124 -> V_168 [ V_16 ] . V_43 ) )
V_45 ++ ;
}
}
return V_45 ;
}
static int F_101 ( struct V_18 * V_19 ,
T_1 V_164 ,
bool V_169 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_123 * V_124 = & V_2 -> V_125 ;
int type , V_16 , V_152 , V_45 , V_170 ;
unsigned int V_161 = F_97 ( V_19 , V_164 ) ;
unsigned int V_160 = F_99 ( V_161 ) ;
int V_142 = 0 ;
struct V_6 * V_49 ;
V_170 = V_2 -> V_127 ;
if ( V_170 >= 2 )
goto V_171;
V_45 = F_100 ( V_19 , V_164 ) ;
if ( V_45 < 2 )
goto V_171;
for ( type = V_165 ; type >= V_166 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_124 -> V_167 ; V_16 ++ ) {
T_1 V_47 = V_124 -> V_168 [ V_16 ] . V_43 ;
T_1 V_147 = 0 ;
if ( V_124 -> V_168 [ V_16 ] . type != type )
continue;
if ( ! F_96 ( V_19 , V_160 , V_47 ) )
continue;
for ( V_152 = 0 ; V_152 < V_2 -> V_127 ; V_152 ++ ) {
if ( V_47 == V_2 -> V_146 [ V_152 ] . V_43 )
break;
}
if ( V_152 < V_2 -> V_127 )
continue;
if ( V_169 )
V_147 = F_95 ( V_19 , V_47 ) ;
else if ( ! V_147 )
V_147 = F_44 ( V_19 , V_47 , false ) ;
if ( ! V_147 ) {
V_142 ++ ;
continue;
}
V_49 = F_42 ( V_19 , V_147 , V_47 ,
- V_2 -> V_42 ) ;
if ( ! V_49 ) {
V_142 ++ ;
continue;
}
V_2 -> V_146 [ V_2 -> V_127 ] . V_43 = V_47 ;
V_2 -> V_146 [ V_2 -> V_127 ] . V_147 = V_147 ;
V_2 -> V_172 [ V_124 -> V_126 + V_2 -> V_127 ] =
F_26 ( V_19 , V_49 ) ;
V_2 -> V_127 ++ ;
if ( V_2 -> V_127 >= 2 )
break;
}
}
V_171:
if ( V_142 )
V_142 = V_173 ;
if ( V_170 == V_2 -> V_127 ) {
if ( V_169 )
return 1 ;
else
return V_142 ;
}
if ( ! V_169 && V_2 -> V_127 < 2 ) {
V_2 -> V_5 . V_17 -= V_2 -> V_127 - V_170 ;
V_2 -> V_127 = V_170 ;
return V_142 ;
}
for ( V_16 = V_170 ; V_16 < V_2 -> V_127 ; V_16 ++ ) {
V_49 = F_27 ( V_19 , V_2 -> V_172 [ V_124 -> V_126 + V_16 ] ) ;
V_142 += F_91 ( V_19 , V_49 ) ;
}
return V_142 ;
}
static bool F_102 ( struct V_18 * V_19 , int V_174 ,
const T_1 * V_46 , T_1 * V_149 , int * V_108 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
bool V_64 = false ;
for ( V_16 = 0 ; V_16 < V_174 ; V_16 ++ ) {
struct V_6 * V_49 ;
T_1 V_147 ;
if ( V_149 [ V_16 ] )
continue;
V_147 = F_95 ( V_19 , V_46 [ V_16 ] ) ;
if ( ! V_147 )
continue;
V_49 = F_42 ( V_19 , V_147 , V_46 [ V_16 ] ,
- V_2 -> V_42 ) ;
if ( ! V_49 && ! V_16 && V_2 -> V_42 )
V_49 = F_42 ( V_19 , V_147 , V_46 [ V_16 ] , 0 ) ;
if ( V_49 ) {
V_149 [ V_16 ] = V_147 ;
V_64 = true ;
V_49 -> V_85 = true ;
V_108 [ V_16 ] = F_26 ( V_19 , V_49 ) ;
}
}
return V_64 ;
}
static int F_103 ( struct V_18 * V_19 , int V_108 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_49 ;
T_1 V_147 , V_43 ;
V_49 = F_27 ( V_19 , V_108 ) ;
if ( ! V_49 || ! V_49 -> V_50 ||
F_22 ( V_49 , V_2 -> V_42 ) )
return 0 ;
V_147 = V_49 -> V_49 [ 0 ] ;
V_43 = V_49 -> V_49 [ V_49 -> V_50 - 1 ] ;
V_49 = F_42 ( V_19 , V_147 , V_43 , V_2 -> V_42 ) ;
if ( ! V_49 ) {
if ( V_147 != V_2 -> V_132 . V_175 [ 0 ] )
V_147 = V_2 -> V_132 . V_175 [ 0 ] ;
else if ( V_2 -> V_132 . V_134 [ 0 ] )
V_147 = V_2 -> V_132 . V_134 [ 0 ] ;
else if ( V_2 -> V_132 . V_135 [ 0 ] )
V_147 = V_2 -> V_132 . V_135 [ 0 ] ;
if ( V_147 )
V_49 = F_42 ( V_19 , V_147 , V_43 ,
V_2 -> V_42 ) ;
}
if ( ! V_49 )
return 0 ;
V_49 -> V_85 = false ;
return F_26 ( V_19 , V_49 ) ;
}
static bool F_104 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_123 * V_124 = & V_2 -> V_125 ;
struct V_6 * V_49 ;
int V_16 , V_55 ;
if ( V_124 -> V_137 == V_140 )
V_55 = V_2 -> V_172 [ 0 ] ;
else
V_55 = V_2 -> V_139 [ 0 ] ;
V_49 = F_27 ( V_19 , V_55 ) ;
if ( ! V_49 )
return false ;
if ( ! V_2 -> V_42 || ! F_22 ( V_49 , V_2 -> V_42 ) )
return true ;
for ( V_16 = 0 ; V_16 < V_124 -> V_126 ; V_16 ++ ) {
if ( V_2 -> V_172 [ V_16 ] == V_55 )
break;
V_49 = F_27 ( V_19 , V_2 -> V_172 [ V_16 ] ) ;
if ( V_49 && F_22 ( V_49 , V_2 -> V_42 ) )
return false ;
}
for ( V_16 = 0 ; V_16 < V_124 -> V_129 ; V_16 ++ ) {
V_49 = F_27 ( V_19 , V_2 -> V_141 [ V_16 ] ) ;
if ( V_49 && F_22 ( V_49 , V_2 -> V_42 ) )
return false ;
}
return true ;
}
static void F_105 ( struct V_18 * V_19 , int V_148 ,
T_1 * V_149 , int * V_108 )
{
struct V_6 * V_49 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_148 ; V_16 ++ ) {
if ( V_149 [ V_16 ] )
continue;
V_49 = F_27 ( V_19 , V_108 [ V_16 ] ) ;
if ( ! V_49 )
continue;
V_149 [ V_16 ] = V_49 -> V_49 [ 0 ] ;
}
}
static int F_106 ( struct V_18 * V_19 ,
bool V_176 ,
bool V_177 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_123 * V_124 = & V_2 -> V_125 ;
int V_16 , V_178 , V_142 ;
V_2 -> V_132 . V_133 = V_124 -> V_126 ;
V_2 -> V_132 . V_175 = V_2 -> V_145 ;
memset ( V_2 -> V_145 , 0 , sizeof( V_2 -> V_145 ) ) ;
memset ( V_2 -> V_132 . V_134 , 0 , sizeof( V_2 -> V_132 . V_134 ) ) ;
memset ( V_2 -> V_132 . V_135 , 0 , sizeof( V_2 -> V_132 . V_135 ) ) ;
V_2 -> V_127 = 0 ;
F_9 ( & V_2 -> V_5 ) ;
memset ( V_2 -> V_172 , 0 , sizeof( V_2 -> V_172 ) ) ;
memset ( V_2 -> V_139 , 0 , sizeof( V_2 -> V_139 ) ) ;
memset ( V_2 -> V_141 , 0 , sizeof( V_2 -> V_141 ) ) ;
memset ( V_2 -> V_179 , 0 , sizeof( V_2 -> V_179 ) ) ;
memset ( V_2 -> V_180 , 0 , sizeof( V_2 -> V_180 ) ) ;
memset ( V_2 -> V_181 , 0 , sizeof( V_2 -> V_181 ) ) ;
memset ( V_2 -> V_182 , 0 , sizeof( V_2 -> V_182 ) ) ;
memset ( & V_2 -> V_183 , 0 , sizeof( V_2 -> V_183 ) ) ;
V_142 = 0 ;
if ( V_176 ) {
bool V_184 ;
do {
V_184 = F_102 ( V_19 , V_124 -> V_126 ,
V_124 -> V_185 ,
V_2 -> V_145 ,
V_2 -> V_172 ) ;
V_184 |= F_102 ( V_19 , V_124 -> V_128 ,
V_124 -> V_186 ,
V_2 -> V_132 . V_134 ,
V_2 -> V_139 ) ;
V_184 |= F_102 ( V_19 , V_124 -> V_129 ,
V_124 -> V_187 ,
V_2 -> V_132 . V_135 ,
V_2 -> V_141 ) ;
if ( V_177 && V_124 -> V_126 == 1 &&
V_124 -> V_137 != V_138 ) {
V_178 = F_101 ( V_19 , V_124 -> V_185 [ 0 ] , true ) ;
if ( ! V_178 )
V_184 = true ;
}
} while ( V_184 );
}
V_142 += F_94 ( V_19 , V_124 -> V_126 , V_124 -> V_185 ,
V_2 -> V_145 , V_2 -> V_172 ,
& V_188 ) ;
if ( V_177 &&
V_124 -> V_126 == 1 && V_124 -> V_137 != V_138 ) {
V_178 = F_101 ( V_19 , V_124 -> V_185 [ 0 ] , false ) ;
if ( V_178 < 0 )
return V_178 ;
}
if ( V_124 -> V_137 != V_140 ) {
V_178 = F_94 ( V_19 , V_124 -> V_128 , V_124 -> V_186 ,
V_2 -> V_132 . V_134 ,
V_2 -> V_139 ,
& V_189 ) ;
if ( V_178 < 0 )
return V_178 ;
V_142 += V_178 ;
}
if ( V_124 -> V_137 != V_138 ) {
V_178 = F_94 ( V_19 , V_124 -> V_129 ,
V_124 -> V_187 ,
V_2 -> V_132 . V_135 ,
V_2 -> V_141 ,
& V_189 ) ;
if ( V_178 < 0 )
return V_178 ;
V_142 += V_178 ;
}
if ( V_124 -> V_126 == 1 && V_124 -> V_137 != V_138 ) {
V_178 = F_101 ( V_19 , V_124 -> V_185 [ 0 ] , false ) ;
if ( V_178 < 0 )
return V_178 ;
V_142 += V_178 ;
}
if ( V_2 -> V_42 ) {
V_2 -> V_179 [ 0 ] =
F_103 ( V_19 , V_2 -> V_172 [ 0 ] ) ;
if ( V_124 -> V_137 != V_140 )
V_2 -> V_179 [ 1 ] =
F_103 ( V_19 , V_2 -> V_139 [ 0 ] ) ;
if ( V_124 -> V_137 != V_138 )
V_2 -> V_179 [ 2 ] =
F_103 ( V_19 , V_2 -> V_141 [ 0 ] ) ;
}
if ( V_124 -> V_128 && V_124 -> V_137 == V_138 )
if ( F_100 ( V_19 , V_124 -> V_186 [ 0 ] ) >= 2 )
V_2 -> V_127 = 1 ;
V_2 -> V_132 . V_133 = 0 ;
for ( V_16 = 0 ; V_16 < V_124 -> V_126 ; V_16 ++ ) {
if ( V_2 -> V_145 [ V_16 ] )
V_2 -> V_132 . V_133 ++ ;
else {
memmove ( V_2 -> V_145 + V_16 ,
V_2 -> V_145 + V_16 + 1 ,
sizeof( T_1 ) * ( V_124 -> V_126 - V_16 - 1 ) ) ;
V_2 -> V_145 [ V_124 -> V_126 - 1 ] = 0 ;
}
}
V_2 -> V_190 = V_2 -> V_191 =
V_2 -> V_132 . V_133 * 2 ;
if ( V_2 -> V_127 == 2 ) {
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
V_2 -> V_145 [ V_2 -> V_132 . V_133 ++ ] =
V_2 -> V_146 [ V_16 ] . V_147 ;
} else if ( V_2 -> V_127 ) {
V_2 -> V_127 = 0 ;
V_142 += V_173 ;
}
if ( V_2 -> V_37 && ! F_104 ( V_19 ) )
V_142 += V_192 ;
if ( V_124 -> V_137 != V_140 )
F_105 ( V_19 , V_124 -> V_128 ,
V_2 -> V_132 . V_134 ,
V_2 -> V_139 ) ;
if ( V_124 -> V_137 != V_138 )
F_105 ( V_19 , V_124 -> V_129 ,
V_2 -> V_132 . V_135 ,
V_2 -> V_141 ) ;
return V_142 ;
}
static inline void F_107 ( struct V_18 * V_19 ,
const char * V_59 , int V_55 )
{
struct V_6 * V_49 ;
V_49 = F_27 ( V_19 , V_55 ) ;
if ( V_49 )
F_34 ( V_59 , V_49 ) ;
}
static void F_108 ( struct V_18 * V_19 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_193 [ 3 ] = { L_31 , L_32 , L_33 } ;
int V_16 ;
F_109 ( L_34 ,
V_124 -> V_185 [ 0 ] , V_124 -> V_185 [ 1 ] ,
V_124 -> V_185 [ 2 ] , V_124 -> V_185 [ 3 ] ,
V_2 -> V_132 . V_175 [ 0 ] ,
V_2 -> V_132 . V_175 [ 1 ] ,
V_2 -> V_132 . V_175 [ 2 ] ,
V_2 -> V_132 . V_175 [ 3 ] ,
V_193 [ V_124 -> V_137 ] ) ;
for ( V_16 = 0 ; V_16 < V_124 -> V_126 ; V_16 ++ )
F_107 ( V_19 , L_35 , V_2 -> V_172 [ V_16 ] ) ;
if ( V_2 -> V_127 > 0 )
F_109 ( L_36 ,
V_2 -> V_127 ,
V_2 -> V_146 [ 0 ] . V_43 , V_2 -> V_146 [ 1 ] . V_43 ,
V_2 -> V_146 [ 0 ] . V_147 , V_2 -> V_146 [ 1 ] . V_147 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_127 ; V_16 ++ )
F_107 ( V_19 , L_37 ,
V_2 -> V_172 [ V_124 -> V_126 + V_16 ] ) ;
if ( V_124 -> V_128 )
F_109 ( L_38 ,
V_124 -> V_186 [ 0 ] , V_124 -> V_186 [ 1 ] ,
V_124 -> V_186 [ 2 ] , V_124 -> V_186 [ 3 ] ,
V_2 -> V_132 . V_134 [ 0 ] ,
V_2 -> V_132 . V_134 [ 1 ] ,
V_2 -> V_132 . V_134 [ 2 ] ,
V_2 -> V_132 . V_134 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_124 -> V_128 ; V_16 ++ )
F_107 ( V_19 , L_39 , V_2 -> V_139 [ V_16 ] ) ;
if ( V_124 -> V_129 )
F_109 ( L_40 ,
V_124 -> V_187 [ 0 ] , V_124 -> V_187 [ 1 ] ,
V_124 -> V_187 [ 2 ] , V_124 -> V_187 [ 3 ] ,
V_2 -> V_132 . V_135 [ 0 ] ,
V_2 -> V_132 . V_135 [ 1 ] ,
V_2 -> V_132 . V_135 [ 2 ] ,
V_2 -> V_132 . V_135 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_124 -> V_129 ; V_16 ++ )
F_107 ( V_19 , L_41 , V_2 -> V_141 [ V_16 ] ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ )
F_107 ( V_19 , L_42 , V_2 -> V_179 [ V_16 ] ) ;
}
static void F_110 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_47 = V_19 -> V_194 ;
V_2 -> V_72 = 0 ;
memset ( V_2 -> V_73 , 0 , sizeof( V_2 -> V_73 ) ) ;
for ( V_16 = 0 ; V_16 < V_19 -> V_195 ; V_16 ++ , V_47 ++ ) {
if ( F_39 ( F_40 ( V_19 , V_47 ) ) != V_63 )
continue;
if ( V_2 -> V_72 >= F_89 ( V_2 -> V_73 ) ) {
F_111 ( V_196 L_43 ) ;
break;
}
V_2 -> V_73 [ V_2 -> V_72 ++ ] = V_47 ;
}
}
static int F_112 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_123 * V_124 = & V_2 -> V_125 ;
struct V_123 * V_197 ;
unsigned int V_20 ;
int V_198 = V_199 ;
int V_142 ;
bool V_176 = true , V_177 = true ;
bool V_200 = true , V_201 = true ;
bool V_202 = false ;
V_197 = F_113 ( sizeof( * V_197 ) , V_13 ) ;
if ( ! V_197 )
return - V_116 ;
* V_197 = * V_124 ;
for (; ; ) {
V_142 = F_106 ( V_19 , V_176 ,
V_177 ) ;
if ( V_142 < 0 ) {
F_8 ( V_197 ) ;
return V_142 ;
}
F_109 ( L_44 ,
V_124 -> V_137 , V_176 , V_177 ,
V_142 ) ;
F_108 ( V_19 , V_124 ) ;
if ( V_142 < V_198 ) {
V_198 = V_142 ;
* V_197 = * V_124 ;
V_200 = V_176 ;
V_201 = V_177 ;
}
if ( ! V_142 )
break;
V_177 = ! V_177 ;
if ( ! V_177 )
continue;
V_176 = ! V_176 ;
if ( ! V_176 )
continue;
if ( V_202 )
break;
V_202 = true ;
if ( V_124 -> V_129 > 0 &&
V_124 -> V_137 == V_140 ) {
V_124 -> V_128 = V_124 -> V_126 ;
memcpy ( V_124 -> V_186 , V_124 -> V_185 ,
sizeof( V_124 -> V_186 ) ) ;
V_124 -> V_126 = V_124 -> V_129 ;
memcpy ( V_124 -> V_185 , V_124 -> V_187 ,
sizeof( V_124 -> V_187 ) ) ;
V_124 -> V_129 = 0 ;
memset ( V_124 -> V_187 , 0 , sizeof( V_124 -> V_187 ) ) ;
V_124 -> V_137 = V_138 ;
V_176 = true ;
continue;
}
if ( V_124 -> V_128 > 0 &&
V_124 -> V_137 == V_138 ) {
V_124 -> V_129 = V_124 -> V_126 ;
memcpy ( V_124 -> V_187 , V_124 -> V_185 ,
sizeof( V_124 -> V_187 ) ) ;
V_124 -> V_126 = V_124 -> V_128 ;
memcpy ( V_124 -> V_185 , V_124 -> V_186 ,
sizeof( V_124 -> V_186 ) ) ;
V_124 -> V_128 = 0 ;
memset ( V_124 -> V_186 , 0 , sizeof( V_124 -> V_186 ) ) ;
V_124 -> V_137 = V_140 ;
V_176 = true ;
continue;
}
break;
}
if ( V_142 ) {
F_109 ( L_45 ) ;
* V_124 = * V_197 ;
F_106 ( V_19 , V_200 , V_201 ) ;
}
F_109 ( L_46 ,
V_124 -> V_137 , V_200 , V_201 ) ;
F_108 ( V_19 , V_124 ) ;
if ( V_124 -> V_185 [ 0 ] ) {
struct V_6 * V_49 ;
V_49 = F_27 ( V_19 , V_2 -> V_172 [ 0 ] ) ;
if ( V_49 )
V_2 -> V_203 = F_51 ( V_19 , V_49 ) ;
if ( V_2 -> V_203 )
F_114 ( V_19 , V_2 -> V_203 ,
V_79 , V_2 -> V_204 ) ;
}
if ( V_2 -> V_205 || V_124 -> V_137 == V_140 )
V_20 = V_206 ;
else
V_20 = V_207 ;
F_20 ( V_19 , V_124 -> V_126 , V_124 -> V_185 , V_20 ) ;
if ( V_124 -> V_137 != V_140 )
F_20 ( V_19 , V_124 -> V_128 , V_124 -> V_186 , V_206 ) ;
if ( V_124 -> V_137 != V_138 ) {
V_20 = V_2 -> V_205 ? V_206 : V_207 ;
F_20 ( V_19 , V_124 -> V_129 ,
V_124 -> V_187 , V_20 ) ;
}
if ( V_2 -> V_37 && ! F_104 ( V_19 ) )
V_2 -> V_37 = 0 ;
F_8 ( V_197 ) ;
return 0 ;
}
static int F_115 ( struct V_18 * V_19 ,
const struct V_123 * V_124 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_178 , V_208 ;
V_208 = V_124 -> V_126 ;
if ( V_2 -> V_127 > 0 && V_124 -> V_126 < 3 )
V_208 += V_2 -> V_127 ;
for ( V_16 = 0 ; V_16 < V_208 ; V_16 ++ ) {
const char * V_10 ;
int V_111 ;
struct V_6 * V_49 ;
V_49 = F_27 ( V_19 , V_2 -> V_172 [ V_16 ] ) ;
if ( ! V_49 )
continue;
V_10 = F_88 ( V_19 , V_16 , & V_111 , V_94 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_47 ) ) {
V_178 = F_78 ( V_19 , L_48 , 0 , 1 , V_49 ) ;
if ( V_178 < 0 )
return V_178 ;
V_178 = F_78 ( V_19 , L_49 , 0 , 2 , V_49 ) ;
if ( V_178 < 0 )
return V_178 ;
} else {
V_178 = F_81 ( V_19 , V_10 , V_111 , V_49 ) ;
if ( V_178 < 0 )
return V_178 ;
}
V_10 = F_88 ( V_19 , V_16 , & V_111 , V_93 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_47 ) ) {
V_178 = F_82 ( V_19 , L_48 , 0 , 1 , V_49 ) ;
if ( V_178 < 0 )
return V_178 ;
V_178 = F_82 ( V_19 , L_49 , 0 , 2 , V_49 ) ;
if ( V_178 < 0 )
return V_178 ;
} else {
V_178 = F_86 ( V_19 , V_10 , V_111 , V_49 ) ;
if ( V_178 < 0 )
return V_178 ;
}
}
return 0 ;
}
static int F_116 ( struct V_18 * V_19 , int V_108 ,
const char * V_59 , int V_109 )
{
struct V_6 * V_49 ;
int V_178 ;
V_49 = F_27 ( V_19 , V_108 ) ;
if ( ! V_49 )
return 0 ;
V_178 = F_81 ( V_19 , V_59 , V_109 , V_49 ) ;
if ( V_178 < 0 )
return V_178 ;
V_178 = F_86 ( V_19 , V_59 , V_109 , V_49 ) ;
if ( V_178 < 0 )
return V_178 ;
return 0 ;
}
static int F_117 ( struct V_18 * V_19 , int V_45 ,
const int * V_5 , const char * V_59 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_45 ; V_16 ++ ) {
const char * V_10 ;
char V_61 [ 44 ] ;
int V_178 , V_55 = 0 ;
if ( V_45 == 2 && V_16 == 1 && ! strcmp ( V_59 , L_28 ) )
V_10 = L_29 ;
else if ( V_45 >= 3 ) {
snprintf ( V_61 , sizeof( V_61 ) , L_50 ,
V_59 , V_136 [ V_16 ] ) ;
V_10 = V_61 ;
} else {
V_10 = V_59 ;
V_55 = V_16 ;
}
V_178 = F_116 ( V_19 , V_5 [ V_16 ] , V_10 , V_55 ) ;
if ( V_178 < 0 )
return V_178 ;
}
return 0 ;
}
static int F_118 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_117 ( V_19 , V_2 -> V_125 . V_128 ,
V_2 -> V_139 ,
L_30 ) ;
}
static int F_119 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_117 ( V_19 , V_2 -> V_125 . V_129 ,
V_2 -> V_141 ,
L_28 ) ;
}
static int F_120 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
return F_121 ( V_210 , V_212 ) ;
}
static int F_122 ( struct V_209 * V_210 ,
struct V_213 * V_214 )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_214 -> V_215 . V_216 . V_217 [ 0 ] = V_2 -> V_218 ;
return 0 ;
}
static int F_124 ( struct V_209 * V_210 ,
struct V_213 * V_214 )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_219 = V_214 -> V_215 . V_216 . V_217 [ 0 ] ;
int V_220 = 0 ;
F_125 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_221 ) {
V_220 = - V_222 ;
goto V_223;
}
if ( V_2 -> V_218 != V_219 ) {
T_1 * V_224 ;
if ( V_2 -> V_125 . V_137 == V_140 )
V_224 = & V_2 -> V_145 [ 0 ] ;
else
V_224 = & V_2 -> V_132 . V_134 [ 0 ] ;
if ( V_2 -> V_225 ) {
if ( V_2 -> V_125 . V_137 == V_140 )
F_126 ( V_19 , V_2 -> V_226 ,
V_2 -> V_172 [ 0 ] ,
V_2 -> V_179 [ 0 ] ,
V_2 -> V_125 . V_137 ) ;
else
F_126 ( V_19 , V_2 -> V_226 ,
V_2 -> V_139 [ 0 ] ,
V_2 -> V_179 [ 1 ] ,
V_140 ) ;
}
V_2 -> V_218 = V_219 ;
if ( V_2 -> V_218 )
* V_224 = 0 ;
else
* V_224 = V_2 -> V_227 ;
if ( V_2 -> V_228 )
V_2 -> V_228 ( V_19 , NULL ) ;
else
F_127 ( V_19 , NULL ) ;
V_220 = 1 ;
}
V_223:
F_128 ( & V_2 -> V_9 ) ;
return V_220 ;
}
static int F_129 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_147 ;
if ( ! V_2 -> V_37 )
return 0 ;
if ( V_2 -> V_125 . V_137 == V_140 )
V_147 = V_2 -> V_132 . V_175 [ 0 ] ;
else
V_147 = V_2 -> V_132 . V_134 [ 0 ] ;
if ( ! V_147 ) {
V_2 -> V_37 = 0 ;
return 0 ;
}
V_2 -> V_218 = false ;
V_2 -> V_227 = V_147 ;
if ( ! F_4 ( V_2 , NULL , & V_229 ) )
return - V_116 ;
return 0 ;
}
static int F_130 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_75 ;
V_212 -> type = V_230 ;
V_212 -> V_231 = 1 ;
V_212 -> V_215 . V_216 . V_232 = V_2 -> V_127 + 1 ;
if ( V_212 -> V_215 . V_216 . V_217 > V_2 -> V_127 )
V_212 -> V_215 . V_216 . V_217 = V_2 -> V_127 ;
V_75 = V_212 -> V_215 . V_216 . V_217 * 2 + V_2 -> V_191 ;
sprintf ( V_212 -> V_215 . V_216 . V_10 , L_51 , V_75 ) ;
return 0 ;
}
static int F_131 ( struct V_209 * V_210 ,
struct V_213 * V_214 )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_214 -> V_215 . V_216 . V_217 [ 0 ] =
( V_2 -> V_190 - V_2 -> V_191 ) / 2 ;
return 0 ;
}
static inline struct V_6 *
F_132 ( struct V_18 * V_19 , int V_55 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_27 ( V_19 ,
V_2 -> V_172 [ V_2 -> V_125 . V_126 + V_55 ] ) ;
}
static int F_133 ( struct V_18 * V_19 , int V_55 , bool V_233 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_47 = V_2 -> V_146 [ V_55 ] . V_43 ;
struct V_6 * V_49 ;
V_49 = F_132 ( V_19 , V_55 ) ;
if ( ! V_49 )
return - V_234 ;
if ( V_49 -> V_85 == V_233 )
return 0 ;
if ( V_233 ) {
F_17 ( V_19 , V_47 , V_207 , true ) ;
F_64 ( V_19 , V_49 , true , true ) ;
F_71 ( V_19 , V_47 , true ) ;
} else {
F_71 ( V_19 , V_47 , false ) ;
F_64 ( V_19 , V_49 , false , true ) ;
F_17 ( V_19 , V_47 , V_2 -> V_146 [ V_55 ] . V_235 , true ) ;
F_68 ( V_19 , V_49 ) ;
}
F_134 ( V_19 ) ;
return 0 ;
}
static int F_135 ( struct V_209 * V_210 ,
struct V_213 * V_214 )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_122 ;
V_122 = V_214 -> V_215 . V_216 . V_217 [ 0 ] ;
if ( V_122 < 0 || V_122 > V_2 -> V_127 )
return - V_234 ;
if ( V_122 == ( V_2 -> V_190 - V_2 -> V_191 ) / 2 )
return 0 ;
V_2 -> V_190 = V_122 * 2 + V_2 -> V_191 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_127 ; V_16 ++ )
F_133 ( V_19 , V_16 , V_16 < V_122 ) ;
V_2 -> V_132 . V_236 = F_136 ( V_2 -> V_190 ,
V_2 -> V_237 ) ;
if ( V_2 -> V_33 )
V_2 -> V_132 . V_133 = V_2 -> V_132 . V_236 / 2 ;
return 1 ;
}
static int F_137 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_127 > 0 ) {
if ( ! F_4 ( V_2 , NULL , & V_238 ) )
return - V_116 ;
}
return 0 ;
}
static int F_138 ( struct V_209 * V_210 ,
struct V_213 * V_214 )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_214 -> V_215 . V_216 . V_217 [ 0 ] = V_2 -> V_226 ;
return 0 ;
}
static void F_126 ( struct V_18 * V_19 , bool V_239 ,
int V_240 , int V_241 ,
int V_242 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_243 , * V_244 ;
V_243 = F_27 ( V_19 , V_240 ) ;
V_244 = F_27 ( V_19 , V_241 ) ;
if ( ! V_243 || ! V_244 )
return;
if ( V_242 == V_140 && V_2 -> V_218 &&
V_244 -> V_49 [ 0 ] != V_2 -> V_227 )
V_239 = false ;
if ( V_239 ) {
F_64 ( V_19 , V_243 , false , true ) ;
F_64 ( V_19 , V_244 , true , true ) ;
F_68 ( V_19 , V_243 ) ;
} else {
F_64 ( V_19 , V_244 , false , true ) ;
F_64 ( V_19 , V_243 , true , true ) ;
F_68 ( V_19 , V_244 ) ;
}
}
static int F_139 ( struct V_209 * V_210 ,
struct V_213 * V_214 )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = V_214 -> V_215 . V_216 . V_217 [ 0 ] ;
if ( V_20 == V_2 -> V_226 )
return 0 ;
V_2 -> V_226 = V_20 ;
F_126 ( V_19 , V_20 , V_2 -> V_172 [ 0 ] ,
V_2 -> V_179 [ 0 ] ,
V_2 -> V_125 . V_137 ) ;
F_126 ( V_19 , V_20 , V_2 -> V_139 [ 0 ] ,
V_2 -> V_179 [ 1 ] ,
V_140 ) ;
F_126 ( V_19 , V_20 , V_2 -> V_141 [ 0 ] ,
V_2 -> V_179 [ 2 ] ,
V_138 ) ;
return 1 ;
}
static int F_140 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_42 )
return 0 ;
if ( ! ( V_2 -> V_179 [ 0 ] || V_2 -> V_179 [ 1 ] ||
V_2 -> V_179 [ 2 ] ) )
return 0 ;
if ( ! F_4 ( V_2 , NULL , & V_245 ) )
return - V_116 ;
V_2 -> V_225 = 1 ;
return 0 ;
}
static void F_141 ( struct V_18 * V_19 , bool V_246 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 ;
T_1 V_43 = V_2 -> V_125 . V_168 [ 1 ] . V_43 ;
V_20 = F_142 ( V_19 , V_43 ) ;
if ( V_20 == V_247 && V_2 -> V_248 ) {
const T_1 V_249 = V_2 -> V_248 ;
unsigned int V_250 = F_142 ( V_19 , V_249 ) ;
if ( V_250 != V_247 )
F_143 ( V_19 , V_249 ,
V_251 | ( V_246 ? V_250 : 0 ) ) ;
}
V_20 = V_246 ? V_20 | V_251 : V_206 ;
F_17 ( V_19 , V_43 , V_20 , true ) ;
V_2 -> V_252 = ! V_246 ;
F_144 ( V_19 ) ;
}
static int F_145 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_123 * V_124 = & V_2 -> V_125 ;
unsigned int V_161 ;
T_1 V_47 ;
if ( V_124 -> V_167 != 1 )
return 0 ;
V_161 = F_97 ( V_19 , V_124 -> V_168 [ 0 ] . V_43 ) ;
if ( F_146 ( V_161 ) != V_253 )
return 0 ;
if ( V_124 -> V_128 == 1 && V_124 -> V_137 == V_138 )
V_47 = V_124 -> V_186 [ 0 ] ;
else if ( V_124 -> V_126 == 1 && V_124 -> V_137 == V_140 )
V_47 = V_124 -> V_185 [ 0 ] ;
else
return 0 ;
if ( ! ( F_72 ( V_19 , V_47 ) & V_254 ) )
return 0 ;
V_124 -> V_168 [ 1 ] . V_43 = V_47 ;
V_124 -> V_168 [ 1 ] . type = V_166 ;
V_124 -> V_167 = 2 ;
V_2 -> V_255 = 1 ;
F_36 ( L_52 , V_47 ) ;
return 0 ;
}
static int F_147 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
static const char * const V_256 [] = {
L_53 , L_54 ,
} ;
return F_148 ( V_210 , V_212 , 2 , V_256 ) ;
}
static int F_149 ( struct V_209 * V_210 ,
struct V_213 * V_214 )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
T_1 V_47 = V_210 -> V_114 ;
if ( F_16 ( V_19 , V_47 ) == V_206 )
V_214 -> V_215 . V_216 . V_217 [ 0 ] = 1 ;
else
V_214 -> V_215 . V_216 . V_217 [ 0 ] = 0 ;
return 0 ;
}
static int F_150 ( struct V_209 * V_210 ,
struct V_213 * V_214 )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
T_1 V_47 = V_210 -> V_114 ;
unsigned int V_20 ;
V_20 = V_214 -> V_215 . V_216 . V_217 [ 0 ] ? V_206 : V_207 ;
if ( F_16 ( V_19 , V_47 ) == V_20 )
return 0 ;
F_143 ( V_19 , V_47 , V_20 ) ;
return 1 ;
}
static bool F_151 ( struct V_18 * V_19 , const char * V_10 , int V_55 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_3 . V_17 ; V_16 ++ ) {
struct V_4 * V_15 = F_24 ( & V_2 -> V_3 , V_16 ) ;
if ( ! strcmp ( V_15 -> V_10 , V_10 ) && V_15 -> V_111 == V_55 )
return true ;
}
return false ;
}
static void F_152 ( struct V_18 * V_19 , T_1 V_43 ,
char * V_10 , T_3 V_257 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_55 = 0 ;
F_153 ( V_19 , V_43 , & V_2 -> V_125 , V_10 , V_257 , & V_55 ) ;
F_35 ( V_10 , L_55 , V_257 ) ;
for (; F_151 ( V_19 , V_10 , V_55 ) ; V_55 ++ )
;
}
static int F_154 ( struct V_18 * V_19 , int V_45 ,
T_1 * V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_45 ; V_16 ++ ) {
T_1 V_43 = V_46 [ V_16 ] ;
unsigned int V_258 = F_72 ( V_19 , V_43 ) ;
if ( ( V_258 & V_163 ) && ( V_258 & V_259 ) ) {
struct V_4 * V_12 ;
char V_10 [ 44 ] ;
F_152 ( V_19 , V_43 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 ,
& V_260 ) ;
if ( ! V_12 )
return - V_116 ;
V_12 -> V_114 = V_43 ;
}
}
return 0 ;
}
static unsigned int F_155 ( struct V_18 * V_19 , T_1 V_43 )
{
unsigned int V_258 ;
V_258 = F_72 ( V_19 , V_43 ) ;
V_258 = ( V_258 & V_261 ) >> V_262 ;
V_258 &= ~ ( V_263 | V_264 ) ;
return V_258 ;
}
static int F_156 ( unsigned int V_265 , unsigned int V_266 )
{
unsigned int V_16 , V_84 = 0 ;
for ( V_16 = 0 ; V_16 < V_267 ; V_16 ++ ) {
if ( V_265 & ( 1 << V_16 ) ) {
if ( V_84 == V_266 )
return V_16 ;
V_84 ++ ;
}
}
return 0 ;
}
static int F_157 ( unsigned int V_265 , unsigned int V_55 )
{
unsigned int V_16 , V_84 = 0 ;
for ( V_16 = 0 ; V_16 < V_267 ; V_16 ++ ) {
if ( V_16 == V_55 )
return V_84 ;
if ( V_265 & ( 1 << V_16 ) )
V_84 ++ ;
}
return 0 ;
}
static int F_158 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
T_1 V_47 = V_210 -> V_114 ;
unsigned int V_265 = F_155 ( V_19 , V_47 ) ;
F_148 ( V_210 , V_212 , F_159 ( V_265 ) ,
V_268 ) ;
strcpy ( V_212 -> V_215 . V_216 . V_10 ,
V_268 [ F_156 ( V_265 , V_212 -> V_215 . V_216 . V_217 ) ] ) ;
return 0 ;
}
static int F_160 ( struct V_209 * V_210 ,
struct V_213 * V_214 )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
T_1 V_47 = V_210 -> V_114 ;
unsigned int V_265 = F_155 ( V_19 , V_47 ) ;
unsigned int V_55 ;
V_55 = F_16 ( V_19 , V_47 ) & V_269 ;
V_214 -> V_215 . V_216 . V_217 [ 0 ] = F_157 ( V_265 , V_55 ) ;
return 0 ;
}
static int F_161 ( struct V_209 * V_210 ,
struct V_213 * V_214 )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
T_1 V_47 = V_210 -> V_114 ;
unsigned int V_265 = F_155 ( V_19 , V_47 ) ;
unsigned int V_20 , V_55 ;
V_20 = F_16 ( V_19 , V_47 ) ;
V_55 = F_157 ( V_265 , V_20 & V_269 ) ;
if ( V_55 == V_214 -> V_215 . V_216 . V_217 [ 0 ] )
return 0 ;
V_20 &= ~ V_269 ;
V_20 |= F_156 ( V_265 , V_214 -> V_215 . V_216 . V_217 [ 0 ] ) ;
F_143 ( V_19 , V_47 , V_20 ) ;
return 1 ;
}
static int F_162 ( struct V_18 * V_19 , T_1 V_43 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_161 ;
struct V_4 * V_12 ;
char V_10 [ 44 ] ;
V_161 = F_97 ( V_19 , V_43 ) ;
if ( F_146 ( V_161 ) == V_253 )
return 0 ;
if ( F_159 ( F_155 ( V_19 , V_43 ) ) <= 1 )
return 0 ;
F_152 ( V_19 , V_43 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 , & V_270 ) ;
if ( ! V_12 )
return - V_116 ;
V_12 -> V_114 = V_43 ;
return 0 ;
}
static int F_163 ( struct V_1 * V_2 , T_1 V_271 , int V_55 )
{
struct V_8 * V_14 ;
V_14 = F_5 ( & V_2 -> V_7 ) ;
if ( ! V_14 )
return - V_116 ;
V_14 -> V_47 = V_271 ;
V_14 -> V_58 = V_80 ;
V_14 -> V_55 = V_55 ;
V_2 -> V_272 . V_273 = V_2 -> V_7 . V_14 ;
return 0 ;
}
static int F_164 ( struct V_18 * V_19 , int V_274 ,
T_1 V_43 , const char * V_275 , int V_276 ,
T_1 V_277 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_49 ;
unsigned int V_20 ;
int V_178 , V_55 ;
if ( ! F_52 ( V_19 , V_277 , V_80 ) &&
! F_50 ( V_19 , V_277 , V_80 ) )
return 0 ;
V_49 = F_42 ( V_19 , V_43 , V_277 , 0 ) ;
if ( ! V_49 )
return - V_234 ;
F_34 ( L_56 , V_49 ) ;
V_2 -> V_182 [ V_274 ] = F_26 ( V_19 , V_49 ) ;
V_55 = V_49 -> V_55 [ V_49 -> V_50 - 1 ] ;
if ( F_52 ( V_19 , V_277 , V_80 ) ) {
V_20 = F_33 ( V_277 , 3 , V_55 , V_80 ) ;
V_178 = F_79 ( V_2 , V_117 , V_275 , V_276 , V_20 ) ;
if ( V_178 < 0 )
return V_178 ;
V_49 -> V_57 [ V_94 ] = V_20 ;
}
if ( F_50 ( V_19 , V_277 , V_80 ) ) {
V_20 = F_33 ( V_277 , 3 , V_55 , V_80 ) ;
V_178 = F_85 ( V_2 , V_119 , V_275 , V_276 , V_20 ) ;
if ( V_178 < 0 )
return V_178 ;
V_49 -> V_57 [ V_93 ] = V_20 ;
}
V_49 -> V_85 = true ;
V_178 = F_163 ( V_2 , V_277 , V_55 ) ;
if ( V_178 < 0 )
return V_178 ;
if ( V_2 -> V_42 != V_2 -> V_98 &&
! V_2 -> V_278 ) {
V_49 = F_42 ( V_19 , V_2 -> V_42 ,
V_2 -> V_98 , 0 ) ;
if ( V_49 ) {
F_34 ( L_57 , V_49 ) ;
V_49 -> V_85 = true ;
V_2 -> V_278 =
F_26 ( V_19 , V_49 ) ;
}
}
return 0 ;
}
static int F_165 ( struct V_18 * V_19 , T_1 V_47 )
{
unsigned int V_258 = F_72 ( V_19 , V_47 ) ;
return ( V_258 & V_254 ) != 0 ;
}
static int F_166 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_47 ;
T_1 * V_279 = V_2 -> V_279 ;
int V_280 = F_89 ( V_2 -> V_279 ) ;
int V_16 , V_48 = 0 ;
V_47 = V_19 -> V_194 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_195 ; V_16 ++ , V_47 ++ ) {
unsigned int V_81 = F_40 ( V_19 , V_47 ) ;
int type = F_39 ( V_81 ) ;
if ( type != V_66 || ( V_81 & V_74 ) )
continue;
V_279 [ V_48 ] = V_47 ;
if ( ++ V_48 >= V_280 )
break;
}
V_2 -> V_281 = V_48 ;
V_2 -> V_282 = V_48 ;
memcpy ( V_2 -> V_283 , V_2 -> V_279 , V_48 * sizeof( T_1 ) ) ;
return V_48 ;
}
static int F_167 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_284 * V_285 = & V_2 -> V_286 ;
unsigned int V_287 ;
int V_16 , V_84 , V_48 ;
V_288:
V_48 = 0 ;
V_287 = 0 ;
for ( V_84 = 0 ; V_84 < V_2 -> V_281 ; V_84 ++ ) {
for ( V_16 = 0 ; V_16 < V_285 -> V_289 ; V_16 ++ ) {
if ( ! V_2 -> V_181 [ V_16 ] [ V_84 ] )
break;
}
if ( V_16 >= V_285 -> V_289 ) {
V_287 |= ( 1 << V_84 ) ;
V_48 ++ ;
}
}
if ( ! V_287 ) {
if ( V_2 -> V_255 ) {
V_2 -> V_255 = 0 ;
V_285 -> V_289 = 1 ;
goto V_288;
}
for ( V_16 = 0 ; V_16 < V_285 -> V_289 ; V_16 ++ ) {
for ( V_84 = 0 ; V_84 < V_2 -> V_281 ; V_84 ++ ) {
if ( V_2 -> V_181 [ V_16 ] [ V_84 ] ) {
V_2 -> V_290 [ V_16 ] = V_84 ;
break;
}
}
}
F_36 ( L_58 ) ;
V_2 -> V_291 = 1 ;
} else if ( V_48 != V_2 -> V_281 ) {
V_48 = 0 ;
for ( V_84 = 0 ; V_84 < V_2 -> V_281 ; V_84 ++ ) {
if ( ! ( V_287 & ( 1 << V_84 ) ) )
continue;
if ( V_84 != V_48 ) {
V_2 -> V_279 [ V_48 ] = V_2 -> V_279 [ V_84 ] ;
for ( V_16 = 0 ; V_16 < V_285 -> V_289 ; V_16 ++ ) {
F_43 ( V_19 ,
V_2 -> V_181 [ V_16 ] [ V_48 ] ) ;
V_2 -> V_181 [ V_16 ] [ V_48 ] =
V_2 -> V_181 [ V_16 ] [ V_84 ] ;
}
}
V_48 ++ ;
}
V_2 -> V_281 = V_48 ;
}
if ( V_285 -> V_289 == 1 || V_2 -> V_255 ) {
F_36 ( L_59 ) ;
V_2 -> V_281 = 1 ;
}
if ( ! V_2 -> V_291 && V_2 -> V_35 )
V_2 -> V_281 = 1 ;
return 0 ;
}
static int F_168 ( struct V_18 * V_19 , T_1 V_43 ,
int V_292 , int V_293 ,
const char * V_294 , int V_295 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_284 * V_285 = & V_2 -> V_286 ;
int V_296 = V_285 -> V_289 ;
bool V_297 = false ;
int V_298 ;
for ( V_298 = 0 ; V_298 < V_293 ; V_298 ++ ) {
struct V_6 * V_49 ;
T_1 V_299 = V_2 -> V_279 [ V_298 ] ;
if ( ! F_29 ( V_19 , V_43 , V_299 ) )
continue;
V_49 = F_42 ( V_19 , V_43 , V_299 , V_295 ) ;
if ( ! V_49 )
continue;
F_34 ( L_60 , V_49 ) ;
V_2 -> V_181 [ V_296 ] [ V_298 ] =
F_26 ( V_19 , V_49 ) ;
if ( ! V_297 ) {
V_2 -> V_300 [ V_285 -> V_289 ] = V_43 ;
F_169 ( V_285 , V_294 , V_292 , NULL ) ;
V_297 = true ;
}
}
return 0 ;
}
static int F_170 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_123 * V_124 = & V_2 -> V_125 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_124 -> V_167 ; V_16 ++ ) {
T_1 V_43 = V_124 -> V_168 [ V_16 ] . V_43 ;
const char * V_294 ;
int V_152 , V_55 ;
if ( ! F_165 ( V_19 , V_43 ) )
continue;
V_294 = F_171 ( V_19 , V_124 , V_16 ) ;
V_55 = 0 ;
for ( V_152 = V_16 - 1 ; V_152 >= 0 ; V_152 -- ) {
if ( V_2 -> V_301 [ V_152 ] &&
! strcmp ( V_2 -> V_301 [ V_152 ] , V_294 ) ) {
V_55 = V_2 -> V_302 [ V_152 ] + 1 ;
break;
}
}
V_2 -> V_301 [ V_16 ] = V_294 ;
V_2 -> V_302 [ V_16 ] = V_55 ;
}
return 0 ;
}
static int F_172 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_123 * V_124 = & V_2 -> V_125 ;
T_1 V_303 = V_2 -> V_42 ;
int V_293 ;
int V_16 , V_178 ;
unsigned int V_20 ;
V_293 = F_166 ( V_19 ) ;
if ( V_293 < 0 )
return 0 ;
V_178 = F_170 ( V_19 ) ;
if ( V_178 < 0 )
return V_178 ;
for ( V_16 = 0 ; V_16 < V_124 -> V_167 ; V_16 ++ ) {
T_1 V_43 ;
V_43 = V_124 -> V_168 [ V_16 ] . V_43 ;
if ( ! F_165 ( V_19 , V_43 ) )
continue;
V_20 = V_251 ;
if ( V_124 -> V_168 [ V_16 ] . type == V_166 )
V_20 |= F_142 ( V_19 , V_43 ) ;
F_17 ( V_19 , V_43 , V_20 , false ) ;
if ( V_303 ) {
if ( F_29 ( V_19 , V_43 , V_303 ) ) {
V_178 = F_164 ( V_19 , V_16 , V_43 ,
V_2 -> V_301 [ V_16 ] ,
V_2 -> V_302 [ V_16 ] ,
V_303 ) ;
if ( V_178 < 0 )
return V_178 ;
}
}
V_178 = F_168 ( V_19 , V_43 , V_16 , V_293 ,
V_2 -> V_301 [ V_16 ] , - V_303 ) ;
if ( V_178 < 0 )
return V_178 ;
if ( V_2 -> V_40 ) {
V_178 = F_162 ( V_19 , V_43 ) ;
if ( V_178 < 0 )
return V_178 ;
}
}
if ( V_303 && V_2 -> V_38 ) {
V_178 = F_168 ( V_19 , V_303 , V_304 , V_293 ,
L_61 , 0 ) ;
if ( V_178 < 0 )
return V_178 ;
}
return 0 ;
}
static struct V_6 * F_173 ( struct V_18 * V_19 , int V_305 , int V_296 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_296 < 0 || V_296 >= V_306 ) {
F_90 () ;
return NULL ;
}
if ( V_2 -> V_291 )
V_305 = V_2 -> V_290 [ V_296 ] ;
if ( V_305 < 0 || V_305 >= V_307 ) {
F_90 () ;
return NULL ;
}
return F_27 ( V_19 , V_2 -> V_181 [ V_296 ] [ V_305 ] ) ;
}
static int F_174 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
return F_175 ( & V_2 -> V_286 , V_212 ) ;
}
static int F_176 ( struct V_209 * V_210 ,
struct V_213 * V_214 )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_305 = F_177 ( V_210 , & V_214 -> V_308 ) ;
V_214 -> V_215 . V_216 . V_217 [ 0 ] = V_2 -> V_309 [ V_305 ] ;
return 0 ;
}
static int F_178 ( struct V_209 * V_210 ,
struct V_213 * V_214 )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
unsigned int V_305 = F_177 ( V_210 , & V_214 -> V_308 ) ;
return F_179 ( V_19 , V_305 ,
V_214 -> V_215 . V_216 . V_217 [ 0 ] ) ;
}
static int F_180 ( struct V_209 * V_210 ,
struct V_213 * V_214 ,
T_4 V_310 , int type )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_284 * V_285 ;
struct V_6 * V_49 ;
int V_16 , V_305 , V_178 = 0 ;
V_285 = & V_2 -> V_286 ;
V_305 = V_210 -> V_308 . V_111 ;
F_125 ( & V_19 -> V_311 ) ;
V_19 -> V_312 = 1 ;
for ( V_16 = 0 ; V_16 < V_285 -> V_289 ; V_16 ++ ) {
V_49 = F_173 ( V_19 , V_305 , V_16 ) ;
if ( ! V_49 || ! V_49 -> V_57 [ type ] )
continue;
V_210 -> V_114 = V_49 -> V_57 [ type ] ;
V_178 = V_310 ( V_210 , V_214 ) ;
if ( V_178 < 0 )
goto error;
}
error:
V_19 -> V_312 = 0 ;
F_128 ( & V_19 -> V_311 ) ;
F_181 ( V_19 ) ;
if ( V_178 >= 0 && V_2 -> V_313 )
V_2 -> V_313 ( V_19 , V_214 ) ;
return V_178 ;
}
static int F_182 ( struct V_209 * V_210 ,
struct V_213 * V_214 )
{
return F_180 ( V_210 , V_214 ,
V_314 ,
V_94 ) ;
}
static int F_183 ( struct V_209 * V_210 ,
struct V_213 * V_214 )
{
return F_180 ( V_210 , V_214 ,
V_315 ,
V_93 ) ;
}
static int F_184 ( struct V_18 * V_19 , struct V_6 * V_49 )
{
T_1 V_47 ;
int V_16 , V_50 ;
V_49 -> V_57 [ V_94 ] = V_49 -> V_57 [ V_93 ] = 0 ;
for ( V_50 = 0 ; V_50 < 3 ; V_50 ++ ) {
if ( V_50 >= V_49 -> V_50 )
return - V_234 ;
V_16 = V_49 -> V_50 - V_50 - 1 ;
V_47 = V_49 -> V_49 [ V_16 ] ;
if ( ! V_49 -> V_57 [ V_94 ] ) {
if ( F_52 ( V_19 , V_47 , V_79 ) )
V_49 -> V_57 [ V_94 ] =
F_33 ( V_47 , 3 , 0 , V_79 ) ;
else if ( F_52 ( V_19 , V_47 , V_80 ) ) {
int V_55 = V_49 -> V_55 [ V_16 ] ;
if ( ! V_50 && V_19 -> V_29 )
V_55 = 0 ;
V_49 -> V_57 [ V_94 ] =
F_33 ( V_47 , 3 , V_55 , V_80 ) ;
}
}
if ( ! V_49 -> V_57 [ V_93 ] ) {
if ( F_50 ( V_19 , V_47 , V_79 ) )
V_49 -> V_57 [ V_93 ] =
F_33 ( V_47 , 3 , 0 , V_79 ) ;
else if ( F_50 ( V_19 , V_47 , V_80 ) ) {
int V_55 = V_49 -> V_55 [ V_16 ] ;
if ( ! V_50 && V_19 -> V_29 )
V_55 = 0 ;
V_49 -> V_57 [ V_93 ] =
F_33 ( V_47 , 3 , V_55 , V_80 ) ;
}
}
}
return 0 ;
}
static bool F_185 ( struct V_18 * V_19 , T_1 V_47 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_123 * V_124 = & V_2 -> V_125 ;
unsigned int V_20 ;
int V_16 ;
if ( ! V_2 -> V_36 )
return false ;
for ( V_16 = 0 ; V_16 < V_124 -> V_167 ; V_16 ++ ) {
if ( V_124 -> V_168 [ V_16 ] . V_43 != V_47 )
continue;
if ( V_124 -> V_168 [ V_16 ] . type != V_166 )
return false ;
V_20 = F_97 ( V_19 , V_47 ) ;
return F_146 ( V_20 ) == V_253 ;
}
return false ;
}
static int F_186 ( struct V_209 * V_210 ,
struct V_213 * V_214 )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_220 ;
V_220 = V_315 ( V_210 , V_214 ) ;
if ( V_220 < 0 )
return V_220 ;
if ( V_2 -> V_313 )
V_2 -> V_313 ( V_19 , V_214 ) ;
return V_220 ;
}
static int F_187 ( struct V_18 * V_19 , const char * V_294 ,
int V_55 , bool V_316 , unsigned int V_317 ,
bool V_318 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
char V_319 [ 44 ] ;
int type = V_316 ? V_119 : V_117 ;
const char * V_115 = V_316 ? L_62 : L_63 ;
unsigned int V_75 = V_318 ? 1 : 3 ;
struct V_4 * V_12 ;
if ( ! V_317 )
return 0 ;
if ( V_294 )
snprintf ( V_319 , sizeof( V_319 ) ,
L_64 , V_294 , V_115 ) ;
else
snprintf ( V_319 , sizeof( V_319 ) ,
L_65 , V_115 ) ;
V_12 = F_75 ( V_2 , type , V_319 , V_55 ,
F_45 ( V_317 , V_75 ) ) ;
if ( ! V_12 )
return - V_116 ;
if ( V_316 )
V_12 -> V_320 = F_186 ;
if ( ! V_318 )
return 0 ;
if ( V_294 )
snprintf ( V_319 , sizeof( V_319 ) ,
L_66 , V_294 , V_115 ) ;
else
snprintf ( V_319 , sizeof( V_319 ) ,
L_67 , V_115 ) ;
V_12 = F_75 ( V_2 , type , V_319 , V_55 ,
F_45 ( V_317 , 2 ) ) ;
if ( ! V_12 )
return - V_116 ;
if ( V_316 )
V_12 -> V_320 = F_186 ;
return 0 ;
}
static int F_188 ( struct V_18 * V_19 , int V_55 ,
unsigned int V_321 , unsigned int V_322 ,
bool V_318 )
{
int V_178 ;
V_178 = F_187 ( V_19 , NULL , V_55 , false , V_321 , V_318 ) ;
if ( V_178 < 0 )
return V_178 ;
V_178 = F_187 ( V_19 , NULL , V_55 , true , V_322 , V_318 ) ;
if ( V_178 < 0 )
return V_178 ;
return 0 ;
}
static int F_189 ( struct V_18 * V_19 , int V_55 ,
unsigned int V_321 , unsigned int V_322 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
if ( V_321 ) {
V_12 = F_4 ( V_2 , NULL , & V_323 ) ;
if ( ! V_12 )
return - V_116 ;
V_12 -> V_111 = V_55 ;
V_12 -> V_114 = V_321 ;
V_12 -> V_112 = V_113 ;
}
if ( V_322 ) {
V_12 = F_4 ( V_2 , NULL , & V_324 ) ;
if ( ! V_12 )
return - V_116 ;
V_12 -> V_111 = V_55 ;
V_12 -> V_114 = V_322 ;
V_12 -> V_112 = V_113 ;
}
return 0 ;
}
static unsigned int F_190 ( struct V_18 * V_19 , int V_55 , int type )
{
struct V_6 * V_49 ;
unsigned int V_317 ;
int V_16 ;
V_49 = F_173 ( V_19 , 0 , V_55 ) ;
if ( ! V_49 )
return 0 ;
V_317 = V_49 -> V_57 [ type ] ;
if ( ! V_317 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_55 - 1 ; V_16 ++ ) {
V_49 = F_173 ( V_19 , 0 , V_16 ) ;
if ( V_49 && V_49 -> V_57 [ type ] == V_317 )
return 0 ;
}
return V_317 ;
}
static int F_191 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_284 * V_285 = & V_2 -> V_286 ;
int V_16 , V_178 , type ;
for ( V_16 = 0 ; V_16 < V_285 -> V_289 ; V_16 ++ ) {
bool V_318 ;
int V_55 ;
V_55 = V_285 -> V_232 [ V_16 ] . V_111 ;
if ( V_55 >= V_2 -> V_125 . V_167 )
continue;
V_318 = F_185 ( V_19 , V_2 -> V_300 [ V_16 ] ) ;
for ( type = 0 ; type < 2 ; type ++ ) {
V_178 = F_187 ( V_19 ,
V_2 -> V_301 [ V_55 ] ,
V_2 -> V_302 [ V_55 ] ,
type ,
F_190 ( V_19 , V_16 , type ) ,
V_318 ) ;
if ( V_178 < 0 )
return V_178 ;
}
}
return 0 ;
}
static int F_192 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_284 * V_285 = & V_2 -> V_286 ;
int V_16 , V_84 , V_48 , V_178 ;
if ( V_2 -> V_291 )
V_48 = 1 ;
else
V_48 = V_2 -> V_281 ;
if ( ! V_2 -> V_325 && V_285 -> V_289 > 1 ) {
struct V_4 * V_12 ;
const char * V_10 ;
V_10 = V_48 > 1 ? L_68 : L_69 ;
V_12 = F_4 ( V_2 , V_10 , & V_326 ) ;
if ( ! V_12 )
return - V_116 ;
V_12 -> V_231 = V_48 ;
}
for ( V_84 = 0 ; V_84 < V_48 ; V_84 ++ ) {
bool V_69 = false ;
bool V_35 = V_2 -> V_35 ;
bool V_318 = false ;
int V_327 , V_328 ;
V_327 = V_328 = 0 ;
for ( V_16 = 0 ; V_16 < V_285 -> V_289 ; V_16 ++ ) {
struct V_6 * V_49 ;
V_49 = F_173 ( V_19 , V_84 , V_16 ) ;
if ( ! V_49 )
continue;
F_184 ( V_19 , V_49 ) ;
if ( ! V_327 )
V_327 = V_49 -> V_57 [ V_94 ] ;
else if ( V_327 != V_49 -> V_57 [ V_94 ] ) {
V_69 = true ;
if ( ! F_48 ( V_19 , V_327 ,
V_49 -> V_57 [ V_94 ] , V_80 ) )
V_35 = true ;
}
if ( ! V_328 )
V_328 = V_49 -> V_57 [ V_93 ] ;
else if ( V_328 != V_49 -> V_57 [ V_93 ] ) {
V_69 = true ;
if ( ! F_48 ( V_19 , V_328 ,
V_49 -> V_57 [ V_93 ] , V_80 ) )
V_35 = true ;
}
if ( F_185 ( V_19 , V_2 -> V_300 [ V_16 ] ) )
V_318 = true ;
}
if ( ! V_69 )
V_178 = F_188 ( V_19 , V_84 , V_327 , V_328 ,
V_318 ) ;
else if ( ! V_35 )
V_178 = F_189 ( V_19 , V_84 , V_327 , V_328 ) ;
else
V_178 = F_191 ( V_19 ) ;
if ( V_178 < 0 )
return V_178 ;
}
return 0 ;
}
static bool F_193 ( struct V_18 * V_19 , T_1 V_47 ,
int V_58 , int V_55 )
{
unsigned int V_329 ;
if ( ! F_52 ( V_19 , V_47 , V_58 ) ||
F_32 ( V_19 , V_47 , V_58 , V_55 , V_94 ) ||
F_32 ( V_19 , V_47 , V_58 , V_55 , V_95 ) )
return false ;
V_329 = ( F_47 ( V_19 , V_47 , V_58 ) & V_330 )
>> V_331 ;
if ( V_329 < 0x20 )
return false ;
return true ;
}
static unsigned int F_194 ( struct V_18 * V_19 ,
struct V_6 * V_49 )
{
unsigned int V_20 = 0 ;
T_1 V_47 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < 3 ; V_50 ++ ) {
if ( V_50 >= V_49 -> V_50 - 1 )
break;
V_47 = V_49 -> V_49 [ V_50 ] ;
if ( V_50 && F_193 ( V_19 , V_47 , V_79 , 0 ) ) {
V_20 = F_33 ( V_47 , 3 , 0 , V_79 ) ;
break;
} else if ( F_193 ( V_19 , V_47 , V_80 ,
V_49 -> V_55 [ V_50 ] ) ) {
V_20 = F_33 ( V_47 , 3 , V_49 -> V_55 [ V_50 ] ,
V_80 ) ;
break;
}
}
return V_20 ;
}
static int F_195 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_123 * V_124 = & V_2 -> V_125 ;
struct V_284 * V_285 = & V_2 -> V_286 ;
int V_16 ;
if ( ! V_2 -> V_281 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_285 -> V_289 ; V_16 ++ ) {
struct V_6 * V_49 ;
unsigned int V_20 ;
int V_55 ;
char V_332 [ 44 ] ;
V_55 = V_285 -> V_232 [ V_16 ] . V_111 ;
if ( V_55 >= V_285 -> V_289 )
continue;
if ( V_124 -> V_168 [ V_55 ] . type > V_165 )
continue;
V_49 = F_173 ( V_19 , 0 , V_16 ) ;
if ( ! V_49 )
continue;
V_20 = F_194 ( V_19 , V_49 ) ;
if ( ! V_20 )
continue;
snprintf ( V_332 , sizeof( V_332 ) ,
L_70 , V_2 -> V_301 [ V_55 ] ) ;
if ( ! F_75 ( V_2 , V_117 , V_332 ,
V_2 -> V_302 [ V_55 ] , V_20 ) )
return - V_116 ;
V_49 -> V_57 [ V_95 ] = V_20 ;
}
return 0 ;
}
static void F_196 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_49 ;
int V_16 , V_48 ;
T_1 V_333 , V_43 ;
V_48 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_125 . V_334 ; V_16 ++ ) {
V_43 = V_2 -> V_125 . V_335 [ V_16 ] ;
V_333 = F_44 ( V_19 , V_43 , true ) ;
if ( ! V_333 )
continue;
V_49 = F_42 ( V_19 , V_333 , V_43 , 0 ) ;
if ( ! V_49 )
continue;
F_34 ( L_71 , V_49 ) ;
V_49 -> V_85 = true ;
V_2 -> V_180 [ V_16 ] = F_26 ( V_19 , V_49 ) ;
F_17 ( V_19 , V_43 , V_207 , false ) ;
if ( ! V_48 ) {
V_2 -> V_132 . V_336 = V_333 ;
V_2 -> V_337 = V_2 -> V_125 . V_337 [ 0 ] ;
} else {
V_2 -> V_132 . V_338 = V_2 -> V_338 ;
if ( V_48 >= F_89 ( V_2 -> V_338 ) - 1 )
break;
V_2 -> V_338 [ V_48 - 1 ] = V_333 ;
}
V_48 ++ ;
}
if ( V_2 -> V_125 . V_339 ) {
V_43 = V_2 -> V_125 . V_339 ;
V_333 = V_19 -> V_194 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_195 ; V_16 ++ , V_333 ++ ) {
unsigned int V_340 = F_40 ( V_19 , V_333 ) ;
if ( F_39 ( V_340 ) != V_66 )
continue;
if ( ! ( V_340 & V_74 ) )
continue;
V_49 = F_42 ( V_19 , V_43 , V_333 , 0 ) ;
if ( V_49 ) {
F_34 ( L_72 , V_49 ) ;
V_49 -> V_85 = true ;
V_2 -> V_341 = V_333 ;
V_2 -> V_183 = F_26 ( V_19 , V_49 ) ;
F_17 ( V_19 , V_43 , V_251 , false ) ;
break;
}
}
}
}
static int F_179 ( struct V_18 * V_19 , unsigned int V_305 ,
unsigned int V_55 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_284 * V_285 ;
struct V_6 * V_342 , * V_49 ;
V_285 = & V_2 -> V_286 ;
if ( ! V_285 -> V_289 )
return 0 ;
if ( V_55 >= V_285 -> V_289 )
V_55 = V_285 -> V_289 - 1 ;
if ( V_2 -> V_309 [ V_305 ] == V_55 )
return 0 ;
V_342 = F_173 ( V_19 , V_305 , V_2 -> V_309 [ V_305 ] ) ;
if ( ! V_342 )
return 0 ;
if ( V_342 -> V_85 )
F_64 ( V_19 , V_342 , false , false ) ;
V_2 -> V_309 [ V_305 ] = V_55 ;
if ( V_2 -> V_255 )
F_141 ( V_19 , V_2 -> V_309 [ V_305 ] ) ;
if ( V_2 -> V_291 )
F_197 ( V_19 , V_55 ) ;
V_49 = F_173 ( V_19 , V_305 , V_55 ) ;
if ( ! V_49 )
return 0 ;
if ( V_49 -> V_85 )
return 0 ;
F_64 ( V_19 , V_49 , true , false ) ;
if ( V_2 -> V_313 )
V_2 -> V_313 ( V_19 , NULL ) ;
F_68 ( V_19 , V_342 ) ;
return 1 ;
}
static bool F_198 ( struct V_18 * V_19 , int V_45 , T_1 * V_46 )
{
int V_16 , V_343 = 0 ;
for ( V_16 = 0 ; V_16 < V_45 ; V_16 ++ ) {
T_1 V_47 = V_46 [ V_16 ] ;
if ( ! V_47 )
break;
if ( F_16 ( V_19 , V_47 ) & V_344 )
continue;
V_343 |= F_199 ( V_19 , V_47 ) ;
}
return V_343 ;
}
static void F_200 ( struct V_18 * V_19 , int V_45 , T_1 * V_46 ,
bool V_345 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_45 ; V_16 ++ ) {
T_1 V_47 = V_46 [ V_16 ] ;
unsigned int V_20 ;
if ( ! V_47 )
break;
if ( V_2 -> V_346 )
V_20 = F_16 ( V_19 , V_47 ) & ~ V_206 ;
else
V_20 = 0 ;
if ( ! V_345 )
V_20 |= F_16 ( V_19 , V_47 ) ;
F_15 ( V_19 , V_47 , V_20 ) ;
F_71 ( V_19 , V_47 , ! V_345 ) ;
}
}
void F_201 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_347 ;
if ( ! V_2 -> V_255 )
F_200 ( V_19 , F_89 ( V_2 -> V_125 . V_186 ) ,
V_2 -> V_125 . V_186 , V_2 -> V_348 ) ;
if ( ! V_2 -> V_252 )
V_347 = 0 ;
else
V_347 = V_2 -> V_349 | V_2 -> V_350 ;
V_347 |= V_2 -> V_348 ;
V_2 -> V_351 = V_347 ;
F_200 ( V_19 , F_89 ( V_2 -> V_125 . V_187 ) ,
V_2 -> V_125 . V_187 , V_347 ) ;
if ( V_2 -> V_125 . V_185 [ 0 ] == V_2 -> V_125 . V_186 [ 0 ] ||
V_2 -> V_125 . V_185 [ 0 ] == V_2 -> V_125 . V_187 [ 0 ] )
return;
if ( ! V_2 -> V_352 )
V_347 = 0 ;
else
V_347 = V_2 -> V_349 ;
V_347 |= V_2 -> V_348 ;
V_2 -> V_353 = V_347 ;
F_200 ( V_19 , F_89 ( V_2 -> V_125 . V_185 ) ,
V_2 -> V_125 . V_185 , V_347 ) ;
}
static void F_144 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_354 )
V_2 -> V_354 ( V_19 ) ;
else
F_201 ( V_19 ) ;
}
void F_127 ( struct V_18 * V_19 , struct V_355 * V_356 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 * V_46 = V_2 -> V_125 . V_186 ;
int V_45 = F_89 ( V_2 -> V_125 . V_186 ) ;
if ( V_2 -> V_218 ) {
V_46 ++ ;
V_45 -- ;
}
V_2 -> V_349 = F_198 ( V_19 , V_45 , V_46 ) ;
if ( ! V_2 -> V_357 || ( ! V_2 -> V_252 && ! V_2 -> V_352 ) )
return;
F_144 ( V_19 ) ;
}
void F_202 ( struct V_18 * V_19 , struct V_355 * V_356 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_125 . V_137 == V_138 )
return;
if ( V_2 -> V_125 . V_185 [ 0 ] == V_2 -> V_125 . V_186 [ 0 ] )
return;
V_2 -> V_350 =
F_198 ( V_19 , F_89 ( V_2 -> V_125 . V_185 ) ,
V_2 -> V_125 . V_185 ) ;
if ( ! V_2 -> V_252 || ! V_2 -> V_358 )
return;
F_144 ( V_19 ) ;
}
void F_203 ( struct V_18 * V_19 , struct V_355 * V_356 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
if ( ! V_2 -> V_325 )
return;
for ( V_16 = V_2 -> V_359 - 1 ; V_16 > 0 ; V_16 -- ) {
T_1 V_43 = V_2 -> V_360 [ V_16 ] . V_43 ;
if ( F_16 ( V_19 , V_43 ) & V_361 )
continue;
if ( F_199 ( V_19 , V_43 ) ) {
F_179 ( V_19 , 0 , V_2 -> V_360 [ V_16 ] . V_55 ) ;
return;
}
}
F_179 ( V_19 , 0 , V_2 -> V_360 [ 0 ] . V_55 ) ;
}
static void F_134 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_228 )
V_2 -> V_228 ( V_19 , NULL ) ;
else
F_127 ( V_19 , NULL ) ;
if ( V_2 -> V_362 )
V_2 -> V_362 ( V_19 , NULL ) ;
else
F_202 ( V_19 , NULL ) ;
if ( V_2 -> V_363 )
V_2 -> V_363 ( V_19 , NULL ) ;
else
F_203 ( V_19 , NULL ) ;
}
static int F_204 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_364 [] = {
L_73 , L_74 , L_75
} ;
if ( V_2 -> V_365 && V_2 -> V_366 )
return F_148 ( V_210 , V_212 , 3 , V_364 ) ;
return F_121 ( V_210 , V_212 ) ;
}
static int F_205 ( struct V_209 * V_210 ,
struct V_213 * V_214 )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = 0 ;
if ( V_2 -> V_252 )
V_20 ++ ;
if ( V_2 -> V_352 )
V_20 ++ ;
V_214 -> V_215 . V_216 . V_217 [ 0 ] = V_20 ;
return 0 ;
}
static int F_206 ( struct V_209 * V_210 ,
struct V_213 * V_214 )
{
struct V_18 * V_19 = F_123 ( V_210 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
switch ( V_214 -> V_215 . V_216 . V_217 [ 0 ] ) {
case 0 :
if ( ! V_2 -> V_252 && ! V_2 -> V_352 )
return 0 ;
V_2 -> V_252 = 0 ;
V_2 -> V_352 = 0 ;
break;
case 1 :
if ( V_2 -> V_365 ) {
if ( ! V_2 -> V_352 && V_2 -> V_252 )
return 0 ;
V_2 -> V_252 = 1 ;
V_2 -> V_352 = 0 ;
} else if ( V_2 -> V_366 ) {
if ( V_2 -> V_352 )
return 0 ;
V_2 -> V_352 = 1 ;
} else
return - V_234 ;
break;
case 2 :
if ( ! V_2 -> V_366 || ! V_2 -> V_365 )
return - V_234 ;
if ( V_2 -> V_252 && V_2 -> V_352 )
return 0 ;
V_2 -> V_252 = 1 ;
V_2 -> V_352 = 1 ;
break;
default:
return - V_234 ;
}
F_144 ( V_19 ) ;
return 1 ;
}
static int F_207 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! F_4 ( V_2 , NULL , & V_367 ) )
return - V_116 ;
return 0 ;
}
static int F_208 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_123 * V_124 = & V_2 -> V_125 ;
int V_343 = 0 ;
int V_16 , V_178 ;
if ( V_2 -> V_30 )
return 0 ;
if ( V_124 -> V_186 [ 0 ] )
V_343 ++ ;
if ( V_124 -> V_185 [ 0 ] )
V_343 ++ ;
if ( V_124 -> V_187 [ 0 ] )
V_343 ++ ;
if ( V_343 < 2 )
return 0 ;
if ( ! V_124 -> V_187 [ 0 ] &&
V_124 -> V_137 == V_138 ) {
memcpy ( V_124 -> V_187 , V_124 -> V_185 ,
sizeof( V_124 -> V_187 ) ) ;
V_124 -> V_129 = V_124 -> V_126 ;
}
if ( ! V_124 -> V_186 [ 0 ] &&
V_124 -> V_137 == V_140 ) {
memcpy ( V_124 -> V_186 , V_124 -> V_185 ,
sizeof( V_124 -> V_186 ) ) ;
V_124 -> V_128 = V_124 -> V_126 ;
}
for ( V_16 = 0 ; V_16 < V_124 -> V_128 ; V_16 ++ ) {
T_1 V_47 = V_124 -> V_186 [ V_16 ] ;
if ( ! F_209 ( V_19 , V_47 ) )
continue;
F_36 ( L_76 ,
V_47 ) ;
F_210 ( V_19 , V_47 , V_368 ,
V_2 -> V_228 ?
V_2 -> V_228 :
F_127 ) ;
V_2 -> V_357 = 1 ;
}
if ( V_124 -> V_137 == V_369 && V_124 -> V_126 ) {
if ( V_124 -> V_129 )
for ( V_16 = 0 ; V_16 < V_124 -> V_126 ; V_16 ++ ) {
T_1 V_47 = V_124 -> V_185 [ V_16 ] ;
if ( ! F_209 ( V_19 , V_47 ) )
continue;
F_36 ( L_77 , V_47 ) ;
F_210 ( V_19 , V_47 ,
V_370 ,
V_2 -> V_362 ?
V_2 -> V_362 :
F_202 ) ;
V_2 -> V_358 = 1 ;
}
V_2 -> V_366 = V_2 -> V_357 ;
}
V_2 -> V_365 = V_124 -> V_129 &&
( V_2 -> V_357 || V_2 -> V_358 ) ;
V_2 -> V_352 = V_2 -> V_366 ;
V_2 -> V_252 = V_2 -> V_365 ;
if ( V_2 -> V_365 || V_2 -> V_366 ) {
V_178 = F_207 ( V_19 ) ;
if ( V_178 < 0 )
return V_178 ;
}
return 0 ;
}
static bool F_211 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_284 * V_285 ;
int V_16 ;
V_285 = & V_2 -> V_286 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_359 ; V_16 ++ ) {
V_2 -> V_360 [ V_16 ] . V_55 =
F_21 ( V_2 -> V_360 [ V_16 ] . V_43 ,
V_2 -> V_300 , V_285 -> V_289 ) ;
if ( V_2 -> V_360 [ V_16 ] . V_55 < 0 )
return false ;
}
for ( V_16 = 1 ; V_16 < V_2 -> V_359 ; V_16 ++ )
F_210 ( V_19 ,
V_2 -> V_360 [ V_16 ] . V_43 ,
V_371 ,
V_2 -> V_363 ?
V_2 -> V_363 :
F_203 ) ;
return true ;
}
static int F_212 ( const void * V_372 , const void * V_373 )
{
const struct V_374 * V_375 = V_372 ;
const struct V_374 * V_376 = V_373 ;
return ( int ) ( V_375 -> V_377 - V_376 -> V_377 ) ;
}
static int F_213 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_123 * V_124 = & V_2 -> V_125 ;
unsigned int V_378 ;
int V_16 , V_45 ;
if ( V_2 -> V_31 )
return 0 ;
V_378 = 0 ;
V_45 = 0 ;
for ( V_16 = 0 ; V_16 < V_124 -> V_167 ; V_16 ++ ) {
T_1 V_47 = V_124 -> V_168 [ V_16 ] . V_43 ;
unsigned int V_377 ;
V_377 = F_97 ( V_19 , V_47 ) ;
V_377 = F_146 ( V_377 ) ;
if ( V_378 & ( 1 << V_377 ) )
return 0 ;
switch ( V_377 ) {
case V_253 :
if ( V_124 -> V_168 [ V_16 ] . type != V_166 )
return 0 ;
break;
case V_379 :
return 0 ;
default:
if ( V_124 -> V_168 [ V_16 ] . type > V_165 )
return 0 ;
if ( ! V_2 -> V_32 &&
V_124 -> V_168 [ V_16 ] . type != V_166 )
return 0 ;
if ( ! F_209 ( V_19 , V_47 ) )
return 0 ;
break;
}
if ( V_45 >= V_380 )
return 0 ;
V_378 |= ( 1 << V_377 ) ;
V_2 -> V_360 [ V_45 ] . V_43 = V_47 ;
V_2 -> V_360 [ V_45 ] . V_377 = V_377 ;
V_45 ++ ;
}
if ( V_45 < 2 )
return 0 ;
V_2 -> V_359 = V_45 ;
F_214 ( V_2 -> V_360 , V_45 , sizeof( V_2 -> V_360 [ 0 ] ) ,
F_212 , NULL ) ;
if ( ! F_211 ( V_19 ) )
return 0 ;
V_2 -> V_325 = 1 ;
V_2 -> V_281 = 1 ;
V_2 -> V_309 [ 0 ] = V_2 -> V_360 [ 0 ] . V_55 ;
F_36 ( L_78 ,
V_2 -> V_360 [ 0 ] . V_43 ,
V_2 -> V_360 [ 1 ] . V_43 ,
V_2 -> V_360 [ 2 ] . V_43 ) ;
return 0 ;
}
static unsigned int F_215 ( struct V_18 * V_19 ,
T_1 V_47 ,
unsigned int V_381 )
{
if ( V_381 != V_99 )
return V_381 ;
if ( F_39 ( F_40 ( V_19 , V_47 ) ) >= V_382 )
return V_381 ;
if ( F_55 ( V_19 , V_47 , V_79 , 0 ) )
return V_381 ;
return V_103 ;
}
int F_216 ( struct V_18 * V_19 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_178 ;
F_11 ( V_19 ) ;
if ( V_2 -> V_42 && ! V_2 -> V_98 )
V_2 -> V_98 = V_2 -> V_42 ;
if ( V_124 != & V_2 -> V_125 ) {
V_2 -> V_125 = * V_124 ;
V_124 = & V_2 -> V_125 ;
}
F_110 ( V_19 ) ;
if ( ! V_124 -> V_126 ) {
if ( V_124 -> V_334 || V_124 -> V_339 ) {
V_2 -> V_132 . V_236 = 2 ;
V_2 -> V_383 = 1 ;
goto V_384;
}
return 0 ;
}
if ( ! V_2 -> V_34 &&
V_124 -> V_137 == V_138 &&
V_124 -> V_126 <= V_124 -> V_128 ) {
V_124 -> V_129 = V_124 -> V_126 ;
memcpy ( V_124 -> V_187 , V_124 -> V_185 ,
sizeof( V_124 -> V_187 ) ) ;
V_124 -> V_126 = V_124 -> V_128 ;
memcpy ( V_124 -> V_185 , V_124 -> V_186 , sizeof( V_124 -> V_186 ) ) ;
V_124 -> V_128 = 0 ;
memset ( V_124 -> V_186 , 0 , sizeof( V_124 -> V_186 ) ) ;
V_124 -> V_137 = V_140 ;
}
V_178 = F_112 ( V_19 ) ;
if ( V_178 < 0 )
return V_178 ;
V_178 = F_137 ( V_19 ) ;
if ( V_178 < 0 )
return V_178 ;
V_178 = F_115 ( V_19 , V_124 ) ;
if ( V_178 < 0 )
return V_178 ;
V_178 = F_118 ( V_19 ) ;
if ( V_178 < 0 )
return V_178 ;
V_178 = F_119 ( V_19 ) ;
if ( V_178 < 0 )
return V_178 ;
V_178 = F_129 ( V_19 ) ;
if ( V_178 < 0 )
return V_178 ;
V_178 = F_140 ( V_19 ) ;
if ( V_178 < 0 )
return V_178 ;
V_178 = F_145 ( V_19 ) ;
if ( V_178 < 0 )
return V_178 ;
V_178 = F_172 ( V_19 ) ;
if ( V_178 < 0 )
return V_178 ;
V_2 -> V_237 = V_2 -> V_190 ;
if ( V_124 -> V_137 != V_138 )
V_2 -> V_237 = F_136 ( V_2 -> V_237 ,
V_124 -> V_129 * 2 ) ;
if ( V_124 -> V_137 != V_140 )
V_2 -> V_237 = F_136 ( V_2 -> V_237 ,
V_124 -> V_128 * 2 ) ;
V_2 -> V_132 . V_236 = F_136 ( V_2 -> V_190 ,
V_2 -> V_237 ) ;
V_178 = F_208 ( V_19 ) ;
if ( V_178 < 0 )
return V_178 ;
V_178 = F_167 ( V_19 ) ;
if ( V_178 < 0 )
return V_178 ;
if ( ! V_2 -> V_255 ) {
V_178 = F_213 ( V_19 ) ;
if ( V_178 < 0 )
return V_178 ;
}
V_178 = F_192 ( V_19 ) ;
if ( V_178 < 0 )
return V_178 ;
V_178 = F_195 ( V_19 ) ;
if ( V_178 < 0 )
return V_178 ;
if ( V_2 -> V_39 ) {
if ( V_124 -> V_137 != V_138 ) {
V_178 = F_154 ( V_19 , V_124 -> V_126 ,
V_124 -> V_185 ) ;
if ( V_178 < 0 )
return V_178 ;
}
if ( V_124 -> V_137 != V_140 ) {
V_178 = F_154 ( V_19 , V_124 -> V_128 ,
V_124 -> V_186 ) ;
if ( V_178 < 0 )
return V_178 ;
}
}
V_384:
F_196 ( V_19 ) ;
if ( V_2 -> V_41 )
V_19 -> V_385 = F_215 ;
return 1 ;
}
int F_217 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_178 ;
if ( V_2 -> V_3 . V_17 ) {
V_178 = F_218 ( V_19 , V_2 -> V_3 . V_14 ) ;
if ( V_178 < 0 )
return V_178 ;
}
if ( V_2 -> V_132 . V_336 ) {
V_178 = F_219 ( V_19 ,
V_2 -> V_132 . V_336 ,
V_2 -> V_132 . V_336 ,
V_2 -> V_386 [ 1 ] . V_387 ) ;
if ( V_178 < 0 )
return V_178 ;
if ( ! V_2 -> V_383 ) {
V_178 = F_220 ( V_19 ,
& V_2 -> V_132 ) ;
if ( V_178 < 0 )
return V_178 ;
V_2 -> V_132 . V_388 = 1 ;
}
}
if ( V_2 -> V_341 ) {
V_178 = F_221 ( V_19 , V_2 -> V_341 ) ;
if ( V_178 < 0 )
return V_178 ;
}
if ( ! V_2 -> V_383 &&
! F_222 ( V_19 , L_79 ) ) {
V_178 = F_223 ( V_19 , L_79 ,
V_2 -> V_204 , V_389 ,
L_80 ) ;
if ( V_178 < 0 )
return V_178 ;
}
if ( ! V_2 -> V_383 &&
! F_222 ( V_19 , L_81 ) ) {
V_178 = F_224 ( V_19 , L_81 ,
NULL , V_389 ,
L_82 ,
true , & V_2 -> V_130 . V_390 ) ;
if ( V_178 < 0 )
return V_178 ;
if ( V_2 -> V_130 . V_131 )
F_225 ( V_19 , & V_2 -> V_130 ,
V_2 -> V_391 ) ;
}
F_7 ( V_2 ) ;
if ( V_2 -> V_255 ) {
int V_178 ;
int V_47 = V_2 -> V_125 . V_168 [ 1 ] . V_43 ;
V_178 = F_226 ( V_19 , V_47 , L_83 , 0 ) ;
if ( V_178 < 0 )
return V_178 ;
V_178 = F_227 ( V_19 , V_47 , 0 ) ;
if ( V_178 < 0 )
return V_178 ;
}
V_178 = F_228 ( V_19 , & V_2 -> V_125 ) ;
if ( V_178 < 0 )
return V_178 ;
return 0 ;
}
static void F_229 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
struct V_394 * V_395 ,
int V_396 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_397 )
V_2 -> V_397 ( V_393 , V_19 , V_395 , V_396 ) ;
}
static void F_230 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
struct V_394 * V_395 ,
int V_396 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_398 )
V_2 -> V_398 ( V_393 , V_19 , V_395 , V_396 ) ;
}
static int F_231 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
struct V_394 * V_395 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_178 ;
F_125 ( & V_2 -> V_9 ) ;
V_178 = F_232 ( V_19 ,
& V_2 -> V_132 , V_395 ,
V_393 ) ;
if ( ! V_178 ) {
V_2 -> V_221 |= 1 << V_399 ;
F_229 ( V_393 , V_19 , V_395 ,
V_400 ) ;
}
F_128 ( & V_2 -> V_9 ) ;
return V_178 ;
}
static int F_233 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
unsigned int V_401 ,
unsigned int V_402 ,
struct V_394 * V_395 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_178 ;
V_178 = F_234 ( V_19 , & V_2 -> V_132 ,
V_401 , V_402 , V_395 ) ;
if ( ! V_178 )
F_229 ( V_393 , V_19 , V_395 ,
V_403 ) ;
return V_178 ;
}
static int F_235 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
struct V_394 * V_395 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_178 ;
V_178 = F_236 ( V_19 , & V_2 -> V_132 ) ;
if ( ! V_178 )
F_229 ( V_393 , V_19 , V_395 ,
V_404 ) ;
return V_178 ;
}
static int F_237 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
struct V_394 * V_395 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_125 ( & V_2 -> V_9 ) ;
V_2 -> V_221 &= ~ ( 1 << V_399 ) ;
F_229 ( V_393 , V_19 , V_395 ,
V_405 ) ;
F_128 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_238 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
struct V_394 * V_395 )
{
F_230 ( V_393 , V_19 , V_395 , V_400 ) ;
return 0 ;
}
static int F_239 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
unsigned int V_401 ,
unsigned int V_402 ,
struct V_394 * V_395 )
{
F_240 ( V_19 , V_393 -> V_47 , V_401 , 0 , V_402 ) ;
F_230 ( V_393 , V_19 , V_395 ,
V_403 ) ;
return 0 ;
}
static int F_241 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
struct V_394 * V_395 )
{
F_242 ( V_19 , V_393 -> V_47 ) ;
F_230 ( V_393 , V_19 , V_395 ,
V_404 ) ;
return 0 ;
}
static int F_243 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
struct V_394 * V_395 )
{
F_230 ( V_393 , V_19 , V_395 , V_405 ) ;
return 0 ;
}
static int F_244 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
struct V_394 * V_395 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_178 = 0 ;
F_125 ( & V_2 -> V_9 ) ;
if ( ! V_2 -> V_218 )
V_178 = - V_222 ;
else
V_2 -> V_221 |= 1 << V_406 ;
F_229 ( V_393 , V_19 , V_395 ,
V_400 ) ;
F_128 ( & V_2 -> V_9 ) ;
return V_178 ;
}
static int F_245 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
struct V_394 * V_395 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_125 ( & V_2 -> V_9 ) ;
V_2 -> V_221 &= ~ ( 1 << V_406 ) ;
F_229 ( V_393 , V_19 , V_395 ,
V_405 ) ;
F_128 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_246 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
unsigned int V_401 ,
unsigned int V_402 ,
struct V_394 * V_395 )
{
F_240 ( V_19 , V_393 -> V_47 , V_401 , 0 , V_402 ) ;
F_229 ( V_393 , V_19 , V_395 ,
V_403 ) ;
return 0 ;
}
static int F_247 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
struct V_394 * V_395 )
{
F_242 ( V_19 , V_393 -> V_47 ) ;
F_229 ( V_393 , V_19 , V_395 ,
V_404 ) ;
return 0 ;
}
static int F_248 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
struct V_394 * V_395 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_249 ( V_19 , & V_2 -> V_132 ) ;
}
static int F_250 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
unsigned int V_401 ,
unsigned int V_402 ,
struct V_394 * V_395 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_251 ( V_19 , & V_2 -> V_132 ,
V_401 , V_402 , V_395 ) ;
}
static int F_252 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
struct V_394 * V_395 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_253 ( V_19 , & V_2 -> V_132 ) ;
}
static int F_254 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
struct V_394 * V_395 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_255 ( V_19 , & V_2 -> V_132 ) ;
}
static int F_256 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
unsigned int V_401 ,
unsigned int V_402 ,
struct V_394 * V_395 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_240 ( V_19 , V_2 -> V_279 [ V_395 -> V_407 + 1 ] ,
V_401 , 0 , V_402 ) ;
F_230 ( V_393 , V_19 , V_395 ,
V_403 ) ;
return 0 ;
}
static int F_257 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
struct V_394 * V_395 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_242 ( V_19 ,
V_2 -> V_279 [ V_395 -> V_407 + 1 ] ) ;
F_230 ( V_393 , V_19 , V_395 ,
V_404 ) ;
return 0 ;
}
static bool F_197 ( struct V_18 * V_19 , int V_408 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_409 = V_2 -> V_279 [ V_2 -> V_290 [ V_408 ] ] ;
if ( V_2 -> V_410 && V_2 -> V_410 != V_409 ) {
F_258 ( V_19 , V_2 -> V_410 , 1 ) ;
V_2 -> V_410 = V_409 ;
F_240 ( V_19 , V_409 ,
V_2 -> V_411 , 0 ,
V_2 -> V_412 ) ;
return true ;
}
return false ;
}
static int F_259 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
unsigned int V_401 ,
unsigned int V_402 ,
struct V_394 * V_395 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
V_2 -> V_410 = V_2 -> V_279 [ V_2 -> V_290 [ V_2 -> V_309 [ 0 ] ] ] ;
V_2 -> V_411 = V_401 ;
V_2 -> V_412 = V_402 ;
F_240 ( V_19 , V_2 -> V_410 , V_401 , 0 , V_402 ) ;
return 0 ;
}
static int F_260 ( struct V_392 * V_393 ,
struct V_18 * V_19 ,
struct V_394 * V_395 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_242 ( V_19 , V_2 -> V_410 ) ;
V_2 -> V_410 = 0 ;
return 0 ;
}
static void F_261 ( char * V_413 , T_3 V_414 , const char * V_115 ,
const char * V_415 )
{
char * V_416 ;
if ( * V_413 )
return;
F_262 ( V_413 , V_415 , V_414 ) ;
for ( V_416 = strchr ( V_413 , ' ' ) ; V_416 ; V_416 = strchr ( V_416 + 1 , ' ' ) ) {
if ( ! isalnum ( V_416 [ 1 ] ) ) {
* V_416 = 0 ;
break;
}
}
F_35 ( V_413 , V_115 , V_414 ) ;
}
int F_263 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_417 * V_418 = V_2 -> V_386 ;
const struct V_392 * V_416 ;
bool V_419 ;
V_19 -> V_420 = 1 ;
V_19 -> V_421 = V_418 ;
if ( V_2 -> V_383 )
goto V_422;
F_261 ( V_2 -> V_423 ,
sizeof( V_2 -> V_423 ) ,
L_84 , V_19 -> V_415 ) ;
V_418 -> V_10 = V_2 -> V_423 ;
if ( V_2 -> V_132 . V_133 > 0 ) {
V_416 = V_2 -> V_424 ;
if ( ! V_416 )
V_416 = & V_425 ;
V_418 -> V_426 [ V_427 ] = * V_416 ;
V_418 -> V_426 [ V_427 ] . V_47 = V_2 -> V_132 . V_175 [ 0 ] ;
V_418 -> V_426 [ V_427 ] . V_428 =
V_2 -> V_132 . V_236 ;
if ( V_2 -> V_125 . V_137 == V_138 &&
V_2 -> V_125 . V_126 == 2 )
V_418 -> V_426 [ V_427 ] . V_429 =
V_430 ;
}
if ( V_2 -> V_281 ) {
V_416 = V_2 -> V_431 ;
if ( ! V_416 ) {
if ( V_2 -> V_291 )
V_416 = & V_432 ;
else
V_416 = & V_433 ;
}
V_418 -> V_426 [ V_434 ] = * V_416 ;
V_418 -> V_426 [ V_434 ] . V_47 = V_2 -> V_279 [ 0 ] ;
}
V_422:
if ( V_2 -> V_132 . V_336 || V_2 -> V_341 ) {
F_261 ( V_2 -> V_435 ,
sizeof( V_2 -> V_435 ) ,
L_85 , V_19 -> V_415 ) ;
V_19 -> V_420 = 2 ;
V_19 -> V_338 = V_2 -> V_132 . V_338 ;
V_418 = V_2 -> V_386 + 1 ;
V_418 -> V_10 = V_2 -> V_435 ;
if ( V_2 -> V_337 )
V_418 -> V_387 = V_2 -> V_337 ;
else
V_418 -> V_387 = V_436 ;
if ( V_2 -> V_132 . V_336 ) {
V_416 = V_2 -> V_437 ;
if ( ! V_416 )
V_416 = & V_438 ;
V_418 -> V_426 [ V_427 ] = * V_416 ;
V_418 -> V_426 [ V_427 ] . V_47 = V_2 -> V_132 . V_336 ;
}
if ( V_2 -> V_341 ) {
V_416 = V_2 -> V_439 ;
if ( ! V_416 )
V_416 = & V_440 ;
V_418 -> V_426 [ V_434 ] = * V_416 ;
V_418 -> V_426 [ V_434 ] . V_47 = V_2 -> V_341 ;
}
}
if ( V_2 -> V_383 )
return 0 ;
V_419 = ( V_2 -> V_281 > 1 ) &&
! V_2 -> V_291 && ! V_2 -> V_325 ;
if ( V_2 -> V_227 || V_419 ) {
F_261 ( V_2 -> V_441 ,
sizeof( V_2 -> V_441 ) ,
L_86 , V_19 -> V_415 ) ;
V_19 -> V_420 = 3 ;
V_418 = V_2 -> V_386 + 2 ;
V_418 -> V_10 = V_2 -> V_441 ;
if ( V_2 -> V_227 ) {
V_416 = V_2 -> V_442 ;
if ( ! V_416 )
V_416 = & V_443 ;
V_418 -> V_426 [ V_427 ] = * V_416 ;
V_418 -> V_426 [ V_427 ] . V_47 =
V_2 -> V_227 ;
} else {
V_418 -> V_426 [ V_427 ] =
V_444 ;
V_418 -> V_426 [ V_427 ] . V_47 = 0 ;
}
if ( V_419 ) {
V_416 = V_2 -> V_445 ;
if ( ! V_416 )
V_416 = & V_446 ;
V_418 -> V_426 [ V_434 ] = * V_416 ;
V_418 -> V_426 [ V_434 ] . V_47 =
V_2 -> V_279 [ 1 ] ;
V_418 -> V_426 [ V_434 ] . V_447 =
V_2 -> V_281 - 1 ;
} else {
V_418 -> V_426 [ V_434 ] =
V_444 ;
V_418 -> V_426 [ V_434 ] . V_47 = 0 ;
}
}
return 0 ;
}
static void F_264 ( struct V_18 * V_19 , int V_108 )
{
struct V_6 * V_49 ;
T_1 V_43 ;
V_49 = F_27 ( V_19 , V_108 ) ;
if ( ! V_49 || ! V_49 -> V_50 )
return;
V_43 = V_49 -> V_49 [ V_49 -> V_50 - 1 ] ;
F_14 ( V_19 , V_43 ) ;
F_64 ( V_19 , V_49 , V_49 -> V_85 , true ) ;
F_71 ( V_19 , V_43 , V_49 -> V_85 ) ;
}
static void F_265 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_125 . V_126 ; V_16 ++ )
F_264 ( V_19 , V_2 -> V_172 [ V_16 ] ) ;
}
static void F_266 ( struct V_18 * V_19 , int V_148 , int * V_5 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_148 ; V_16 ++ )
F_264 ( V_19 , V_5 [ V_16 ] ) ;
}
static void F_267 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_125 . V_137 != V_140 )
F_266 ( V_19 , V_2 -> V_125 . V_128 , V_2 -> V_139 ) ;
if ( V_2 -> V_125 . V_137 != V_138 )
F_266 ( V_19 , V_2 -> V_125 . V_129 ,
V_2 -> V_141 ) ;
}
static void F_268 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_127 ; V_16 ++ ) {
T_1 V_43 = V_2 -> V_146 [ V_16 ] . V_43 ;
struct V_6 * V_49 ;
V_49 = F_132 ( V_19 , V_16 ) ;
if ( ! V_49 )
continue;
if ( ! V_2 -> V_146 [ V_16 ] . V_235 )
V_2 -> V_146 [ V_16 ] . V_235 =
F_16 ( V_19 , V_43 ) ;
F_64 ( V_19 , V_49 , V_49 -> V_85 , true ) ;
}
}
static void F_269 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_123 * V_124 = & V_2 -> V_125 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_124 -> V_167 ; V_16 ++ ) {
T_1 V_47 = V_124 -> V_168 [ V_16 ] . V_43 ;
if ( F_165 ( V_19 , V_47 ) )
F_14 ( V_19 , V_47 ) ;
if ( V_2 -> V_42 ) {
F_74 ( V_19 , V_2 -> V_182 [ V_16 ] ) ;
F_74 ( V_19 , V_2 -> V_278 ) ;
}
}
}
static void F_270 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_284 * V_285 = & V_2 -> V_286 ;
struct V_6 * V_49 ;
int V_16 , V_298 , V_48 ;
if ( V_2 -> V_291 )
V_48 = 1 ;
else
V_48 = V_2 -> V_281 ;
for ( V_298 = 0 ; V_298 < V_48 ; V_298 ++ ) {
for ( V_16 = 0 ; V_16 < V_285 -> V_289 ; V_16 ++ ) {
V_49 = F_173 ( V_19 , V_298 , V_16 ) ;
if ( V_49 ) {
bool V_85 = V_49 -> V_85 ;
if ( V_16 == V_2 -> V_309 [ V_298 ] )
V_85 = true ;
F_64 ( V_19 , V_49 , V_85 , false ) ;
}
}
}
if ( V_2 -> V_255 )
F_141 ( V_19 , V_2 -> V_309 [ 0 ] ) ;
if ( V_2 -> V_313 )
V_2 -> V_313 ( V_19 , NULL ) ;
}
static void F_271 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_43 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_125 . V_334 ; V_16 ++ )
F_264 ( V_19 , V_2 -> V_180 [ V_16 ] ) ;
V_43 = V_2 -> V_125 . V_339 ;
if ( V_43 ) {
F_14 ( V_19 , V_43 ) ;
F_74 ( V_19 , V_2 -> V_183 ) ;
}
}
static void F_272 ( struct V_18 * V_19 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_448 . V_17 ; V_16 ++ ) {
struct V_449 * V_43 = F_24 ( & V_19 -> V_448 , V_16 ) ;
T_1 V_47 = V_43 -> V_47 ;
if ( F_209 ( V_19 , V_47 ) &&
! F_273 ( V_19 , V_47 ) )
F_73 ( V_19 , V_47 , 0 ,
V_450 , 0 ) ;
}
}
int F_274 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_451 )
V_2 -> V_451 ( V_19 ) ;
F_275 ( V_19 ) ;
V_19 -> V_312 = 1 ;
F_265 ( V_19 ) ;
F_267 ( V_19 ) ;
F_268 ( V_19 ) ;
F_269 ( V_19 ) ;
F_270 ( V_19 ) ;
F_271 ( V_19 ) ;
F_272 ( V_19 ) ;
F_134 ( V_19 ) ;
F_181 ( V_19 ) ;
if ( V_2 -> V_130 . V_390 && V_2 -> V_130 . V_131 )
F_276 ( & V_2 -> V_130 ) ;
F_277 ( V_19 , 0x01 ) ;
return 0 ;
}
void F_278 ( struct V_18 * V_19 )
{
F_10 ( V_19 -> V_2 ) ;
F_8 ( V_19 -> V_2 ) ;
V_19 -> V_2 = NULL ;
}
int F_279 ( struct V_18 * V_19 , T_1 V_47 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_280 ( V_19 , & V_2 -> V_272 , V_47 ) ;
}
int F_281 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_178 ;
V_2 = F_282 ( sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 )
return - V_116 ;
F_1 ( V_2 ) ;
V_19 -> V_2 = V_2 ;
V_178 = F_283 ( V_19 , & V_2 -> V_125 , NULL , 0 ) ;
if ( V_178 < 0 )
return V_178 ;
V_178 = F_216 ( V_19 , & V_2 -> V_125 ) ;
if ( V_178 < 0 )
goto error;
V_19 -> V_452 = V_453 ;
return 0 ;
error:
F_278 ( V_19 ) ;
return V_178 ;
}
