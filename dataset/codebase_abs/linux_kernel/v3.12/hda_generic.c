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
V_2 -> V_34 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_15 ) ;
if ( V_20 >= 0 )
V_2 -> V_35 = ! V_20 ;
V_20 = F_12 ( V_19 , L_16 ) ;
if ( V_20 >= 0 )
V_2 -> V_36 = ! V_20 ;
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
V_20 = F_12 ( V_19 , L_22 ) ;
if ( V_20 >= 0 )
V_2 -> V_41 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_23 ) ;
if ( V_20 >= 0 )
V_2 -> V_41 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_24 ) ;
if ( V_20 >= 0 )
V_2 -> V_42 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_25 ) ;
if ( V_20 >= 0 )
V_2 -> V_43 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_26 ) ;
if ( V_20 >= 0 )
V_2 -> V_44 = ! V_20 ;
if ( ! F_13 ( V_19 , L_27 , & V_20 ) )
V_2 -> V_45 = V_20 ;
}
static inline void F_14 ( struct V_18 * V_19 , T_1 V_46 )
{
F_15 ( V_19 , V_46 , F_16 ( V_19 , V_46 ) ) ;
}
static void F_17 ( struct V_18 * V_19 , T_1 V_46 ,
unsigned int V_20 , bool V_47 )
{
if ( ! V_46 )
return;
V_20 = F_18 ( V_19 , V_46 , V_20 ) ;
F_19 ( V_19 , V_46 , V_20 ) ;
if ( V_47 )
F_15 ( V_19 , V_46 , V_20 ) ;
}
static void F_20 ( struct V_18 * V_19 , int V_48 ,
T_1 * V_49 , unsigned int V_20 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ )
F_17 ( V_19 , V_49 [ V_16 ] , V_20 , false ) ;
}
static int F_21 ( T_1 V_50 , const T_1 * V_14 , int V_51 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_51 ; V_16 ++ )
if ( V_14 [ V_16 ] == V_50 )
return V_16 ;
return - 1 ;
}
static bool F_22 ( struct V_6 * V_52 , T_1 V_50 )
{
return F_21 ( V_50 , V_52 -> V_52 , V_52 -> V_53 ) >= 0 ;
}
static struct V_6 * F_23 ( struct V_18 * V_19 ,
T_1 V_54 , T_1 V_55 ,
int V_56 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 . V_17 ; V_16 ++ ) {
struct V_6 * V_52 = F_24 ( & V_2 -> V_5 , V_16 ) ;
if ( V_52 -> V_53 <= 0 )
continue;
if ( ( ! V_54 || V_52 -> V_52 [ 0 ] == V_54 ) &&
( ! V_55 || V_52 -> V_52 [ V_52 -> V_53 - 1 ] == V_55 ) ) {
if ( ! V_56 ||
( V_56 > 0 && F_22 ( V_52 , V_56 ) ) ||
( V_56 < 0 && ! F_22 ( V_52 , V_56 ) ) )
return V_52 ;
}
}
return NULL ;
}
struct V_6 * F_25 ( struct V_18 * V_19 ,
T_1 V_54 , T_1 V_55 )
{
return F_23 ( V_19 , V_54 , V_55 , 0 ) ;
}
int F_26 ( struct V_18 * V_19 , struct V_6 * V_52 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_57 = V_2 -> V_5 . V_14 ;
T_2 V_58 ;
if ( ! V_2 -> V_5 . V_17 )
return 0 ;
V_58 = V_52 - V_57 ;
if ( V_58 < 0 || V_58 >= V_2 -> V_5 . V_17 )
return 0 ;
return V_58 + 1 ;
}
struct V_6 * F_27 ( struct V_18 * V_19 , int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_58 <= 0 || V_58 > V_2 -> V_5 . V_17 )
return NULL ;
return F_24 ( & V_2 -> V_5 , V_58 - 1 ) ;
}
static bool F_28 ( struct V_18 * V_19 , T_1 V_50 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 . V_17 ; V_16 ++ ) {
struct V_6 * V_52 = F_24 ( & V_2 -> V_5 , V_16 ) ;
if ( V_52 -> V_52 [ 0 ] == V_50 )
return true ;
}
return false ;
}
static bool F_29 ( struct V_18 * V_19 ,
T_1 V_54 , T_1 V_55 )
{
if ( ! V_54 || ! V_55 )
return false ;
return F_30 ( V_19 , V_55 , V_54 , true ) >= 0 ;
}
static bool F_31 ( struct V_18 * V_19 , unsigned int V_20 , int type )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
V_20 &= V_59 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 . V_17 ; V_16 ++ ) {
struct V_6 * V_52 = F_24 ( & V_2 -> V_5 , V_16 ) ;
if ( ( V_52 -> V_60 [ type ] & V_59 ) == V_20 )
return true ;
}
return false ;
}
static bool F_32 ( struct V_18 * V_19 , T_1 V_50 ,
int V_61 , int V_58 , int type )
{
unsigned int V_20 = F_33 ( V_50 , 3 , V_58 , V_61 ) ;
return F_31 ( V_19 , V_20 , type ) ;
}
static void F_34 ( const char * V_62 , struct V_6 * V_52 )
{
char V_63 [ 40 ] ;
int V_16 ;
V_63 [ 0 ] = 0 ;
for ( V_16 = 0 ; V_16 < V_52 -> V_53 ; V_16 ++ ) {
char V_64 [ 4 ] ;
sprintf ( V_64 , L_28 , V_52 -> V_52 [ V_16 ] ) ;
F_35 ( V_63 , V_64 , sizeof( V_63 ) ) ;
}
F_36 ( L_29 , V_62 , V_52 -> V_53 , V_63 ) ;
}
static bool F_37 ( struct V_18 * V_19 ,
T_1 V_54 , T_1 V_55 ,
int V_56 , struct V_6 * V_52 ,
int V_53 )
{
const T_1 * V_65 ;
int V_16 , V_51 ;
if ( V_55 == V_56 )
V_56 = 0 ;
else if ( V_55 == ( T_1 ) ( - V_56 ) )
return false ;
V_51 = F_38 ( V_19 , V_55 , & V_65 ) ;
for ( V_16 = 0 ; V_16 < V_51 ; V_16 ++ ) {
if ( V_65 [ V_16 ] != V_54 ) {
if ( V_54 ||
F_39 ( F_40 ( V_19 , V_65 [ V_16 ] ) ) != V_66 ||
F_28 ( V_19 , V_65 [ V_16 ] ) )
continue;
}
if ( V_56 <= 0 )
goto V_67;
}
if ( V_53 >= V_68 )
return false ;
for ( V_16 = 0 ; V_16 < V_51 ; V_16 ++ ) {
unsigned int type ;
type = F_39 ( F_40 ( V_19 , V_65 [ V_16 ] ) ) ;
if ( type == V_66 || type == V_69 ||
type == V_70 )
continue;
if ( F_37 ( V_19 , V_54 , V_65 [ V_16 ] ,
V_56 , V_52 , V_53 + 1 ) )
goto V_67;
}
return false ;
V_67:
V_52 -> V_52 [ V_52 -> V_53 ] = V_65 [ V_16 ] ;
V_52 -> V_58 [ V_52 -> V_53 + 1 ] = V_16 ;
if ( V_51 > 1 && F_39 ( F_40 ( V_19 , V_55 ) ) != V_71 )
V_52 -> V_72 [ V_52 -> V_53 + 1 ] = 1 ;
V_52 -> V_53 ++ ;
return true ;
}
bool F_41 ( struct V_18 * V_19 , T_1 V_54 ,
T_1 V_55 , int V_56 ,
struct V_6 * V_52 )
{
if ( F_37 ( V_19 , V_54 , V_55 , V_56 , V_52 , 1 ) ) {
V_52 -> V_52 [ V_52 -> V_53 ] = V_55 ;
V_52 -> V_53 ++ ;
return true ;
}
return false ;
}
struct V_6 *
F_42 ( struct V_18 * V_19 , T_1 V_54 ,
T_1 V_55 , int V_56 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_52 ;
if ( V_54 && V_55 && ! F_29 ( V_19 , V_54 , V_55 ) )
return NULL ;
V_52 = F_23 ( V_19 , V_54 , V_55 , V_56 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_5 ( & V_2 -> V_5 ) ;
if ( ! V_52 )
return NULL ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
if ( F_41 ( V_19 , V_54 , V_55 , V_56 , V_52 ) )
return V_52 ;
V_2 -> V_5 . V_17 -- ;
return NULL ;
}
static void F_43 ( struct V_18 * V_19 , int V_58 )
{
struct V_6 * V_52 = F_27 ( V_19 , V_58 ) ;
if ( ! V_52 )
return;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
}
static T_1 F_44 ( struct V_18 * V_19 , T_1 V_46 ,
bool V_73 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_74 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_75 ; V_16 ++ ) {
T_1 V_50 = V_2 -> V_76 [ V_16 ] ;
if ( ! V_50 || F_28 ( V_19 , V_50 ) )
continue;
V_74 = ! ! ( F_40 ( V_19 , V_50 ) & V_77 ) ;
if ( V_73 != V_74 )
continue;
if ( F_29 ( V_19 , V_50 , V_46 ) )
return V_50 ;
}
return 0 ;
}
static unsigned int F_45 ( unsigned int V_20 , unsigned int V_78 )
{
V_20 &= ~ ( 0x3U << 16 ) ;
V_20 |= V_78 << 16 ;
return V_20 ;
}
static bool F_46 ( struct V_18 * V_19 , T_1 V_50 ,
int V_61 , unsigned int V_79 )
{
if ( ! V_50 )
return false ;
if ( F_40 ( V_19 , V_50 ) & ( 1 << ( V_61 + 1 ) ) )
if ( F_47 ( V_19 , V_50 , V_61 ) & V_79 )
return true ;
return false ;
}
static bool F_48 ( struct V_18 * V_19 , T_1 V_80 ,
T_1 V_81 , int V_61 )
{
if ( ! ( F_40 ( V_19 , V_80 ) & ( 1 << ( V_61 + 1 ) ) ) )
return ! ( F_40 ( V_19 , V_81 ) & ( 1 << ( V_61 + 1 ) ) ) ;
return ( F_47 ( V_19 , V_80 , V_61 ) ==
F_47 ( V_19 , V_81 , V_61 ) ) ;
}
static T_1 F_49 ( struct V_18 * V_19 ,
struct V_6 * V_52 )
{
int V_16 ;
for ( V_16 = V_52 -> V_53 - 1 ; V_16 >= 0 ; V_16 -- ) {
if ( F_50 ( V_19 , V_52 -> V_52 [ V_16 ] , V_82 ) )
return V_52 -> V_52 [ V_16 ] ;
if ( V_16 != V_52 -> V_53 - 1 && V_16 != 0 &&
F_50 ( V_19 , V_52 -> V_52 [ V_16 ] , V_83 ) )
return V_52 -> V_52 [ V_16 ] ;
}
return 0 ;
}
static T_1 F_51 ( struct V_18 * V_19 ,
struct V_6 * V_52 )
{
int V_16 ;
for ( V_16 = V_52 -> V_53 - 1 ; V_16 >= 0 ; V_16 -- ) {
if ( F_52 ( V_19 , V_52 -> V_52 [ V_16 ] , V_82 ) )
return V_52 -> V_52 [ V_16 ] ;
}
return 0 ;
}
static bool F_53 ( struct V_18 * V_19 , struct V_6 * V_52 , int V_58 )
{
T_1 V_50 = V_52 -> V_52 [ V_58 ] ;
unsigned int V_84 = F_40 ( V_19 , V_50 ) ;
unsigned int type = F_39 ( V_84 ) ;
if ( ! ( V_84 & V_85 ) )
return false ;
if ( type == V_70 && V_58 > 0 )
return false ;
return true ;
}
static bool F_54 ( struct V_18 * V_19 , struct V_6 * V_52 , int V_58 )
{
T_1 V_50 = V_52 -> V_52 [ V_58 ] ;
unsigned int V_84 = F_40 ( V_19 , V_50 ) ;
unsigned int type = F_39 ( V_84 ) ;
if ( ! ( V_84 & V_86 ) )
return false ;
if ( type == V_70 && ! V_58 )
return false ;
return true ;
}
static bool F_55 ( struct V_18 * V_19 , T_1 V_50 ,
unsigned int V_61 , unsigned int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_87 ;
for ( V_87 = 0 ; V_87 < V_2 -> V_5 . V_17 ; V_87 ++ ) {
struct V_6 * V_52 = F_24 ( & V_2 -> V_5 , V_87 ) ;
if ( ! V_52 -> V_88 )
continue;
for ( V_16 = 0 ; V_16 < V_52 -> V_53 ; V_16 ++ ) {
if ( V_52 -> V_52 [ V_16 ] == V_50 ) {
if ( V_61 == V_82 || V_52 -> V_58 [ V_16 ] == V_58 )
return true ;
break;
}
}
}
return false ;
}
static int F_56 ( struct V_18 * V_19 , T_1 V_50 ,
int V_61 , unsigned int V_84 , bool V_89 )
{
unsigned int V_20 = 0 ;
if ( V_84 & V_90 ) {
if ( V_89 )
V_20 = ( V_84 & V_91 ) >> V_92 ;
}
if ( V_84 & ( V_93 | V_94 ) ) {
if ( ! V_89 )
V_20 |= V_95 ;
}
return V_20 ;
}
static void F_57 ( struct V_18 * V_19 , T_1 V_50 , int V_61 , int V_58 )
{
unsigned int V_84 = F_47 ( V_19 , V_50 , V_61 ) ;
int V_20 = F_56 ( V_19 , V_50 , V_61 , V_84 , false ) ;
F_58 ( V_19 , V_50 , V_61 , V_58 , 0xff , V_20 ) ;
}
static unsigned int F_59 ( struct V_18 * V_19 ,
T_1 V_50 , int V_61 , int V_58 ,
unsigned int V_84 )
{
unsigned int V_96 = 0xff ;
if ( V_84 & ( V_93 | V_94 ) ) {
if ( F_32 ( V_19 , V_50 , V_61 , V_58 , V_97 ) )
V_96 &= ~ 0x80 ;
}
if ( V_84 & V_90 ) {
if ( F_32 ( V_19 , V_50 , V_61 , V_58 , V_98 ) ||
F_32 ( V_19 , V_50 , V_61 , V_58 , V_99 ) )
V_96 &= ~ 0x7f ;
}
return V_96 ;
}
static void F_60 ( struct V_18 * V_19 , T_1 V_50 , int V_61 ,
int V_58 , int V_100 , bool V_89 )
{
unsigned int V_84 ;
unsigned int V_96 , V_20 ;
if ( ! V_89 && F_55 ( V_19 , V_50 , V_61 , V_100 ) )
return;
V_84 = F_47 ( V_19 , V_50 , V_61 ) ;
V_20 = F_56 ( V_19 , V_50 , V_61 , V_84 , V_89 ) ;
V_96 = F_59 ( V_19 , V_50 , V_61 , V_100 , V_84 ) ;
if ( ! V_96 )
return;
V_20 &= V_96 ;
F_61 ( V_19 , V_50 , V_61 , V_58 , V_96 , V_20 ) ;
}
static void F_62 ( struct V_18 * V_19 , struct V_6 * V_52 ,
int V_16 , bool V_89 )
{
T_1 V_50 = V_52 -> V_52 [ V_16 ] ;
F_57 ( V_19 , V_50 , V_82 , 0 ) ;
F_60 ( V_19 , V_50 , V_82 , 0 , 0 , V_89 ) ;
}
static void F_63 ( struct V_18 * V_19 , struct V_6 * V_52 ,
int V_16 , bool V_89 , bool V_101 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const T_1 * V_65 ;
int V_87 , V_51 , V_58 ;
int type ;
T_1 V_50 = V_52 -> V_52 [ V_16 ] ;
V_51 = F_38 ( V_19 , V_50 , & V_65 ) ;
type = F_39 ( F_40 ( V_19 , V_50 ) ) ;
if ( type == V_70 ||
( type == V_69 && V_19 -> V_29 ) ) {
V_51 = 1 ;
V_58 = 0 ;
} else
V_58 = V_52 -> V_58 [ V_16 ] ;
for ( V_87 = 0 ; V_87 < V_51 ; V_87 ++ )
F_57 ( V_19 , V_50 , V_83 , V_87 ) ;
for ( V_87 = 0 ; V_87 < V_51 ; V_87 ++ ) {
if ( V_87 != V_58 && ( ! V_101 || V_65 [ V_87 ] != V_2 -> V_102 ) )
continue;
F_60 ( V_19 , V_50 , V_83 , V_87 , V_58 , V_89 ) ;
}
}
void F_64 ( struct V_18 * V_19 , struct V_6 * V_52 ,
bool V_89 , bool V_101 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
if ( ! V_89 )
V_52 -> V_88 = false ;
for ( V_16 = V_52 -> V_53 - 1 ; V_16 >= 0 ; V_16 -- ) {
T_1 V_50 = V_52 -> V_52 [ V_16 ] ;
if ( V_89 && V_2 -> V_42 ) {
if ( ! F_65 ( V_19 , V_50 , V_103 ) )
F_66 ( V_19 , V_50 , 0 ,
V_104 ,
V_103 ) ;
}
if ( V_89 && V_52 -> V_72 [ V_16 ] )
F_67 ( V_19 , V_50 , 0 ,
V_105 ,
V_52 -> V_58 [ V_16 ] ) ;
if ( F_53 ( V_19 , V_52 , V_16 ) )
F_63 ( V_19 , V_52 , V_16 , V_89 , V_101 ) ;
if ( F_54 ( V_19 , V_52 , V_16 ) )
F_62 ( V_19 , V_52 , V_16 , V_89 ) ;
}
if ( V_89 )
V_52 -> V_88 = true ;
}
static void F_68 ( struct V_18 * V_19 , struct V_6 * V_52 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_106 = false ;
int V_16 ;
if ( ! V_2 -> V_42 || V_52 -> V_88 )
return;
for ( V_16 = 0 ; V_16 < V_52 -> V_53 ; V_16 ++ ) {
T_1 V_50 = V_52 -> V_52 [ V_16 ] ;
if ( ! F_65 ( V_19 , V_50 , V_107 ) &&
! F_69 ( V_19 , V_50 ) ) {
F_66 ( V_19 , V_50 , 0 ,
V_104 ,
V_107 ) ;
V_106 = true ;
}
}
if ( V_106 ) {
F_70 ( 10 ) ;
F_71 ( V_19 , V_52 -> V_52 [ 0 ] , 0 ,
V_108 , 0 ) ;
}
}
static void F_72 ( struct V_18 * V_19 , T_1 V_46 , bool V_89 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_109 ||
! ( F_73 ( V_19 , V_46 ) & V_110 ) )
return;
if ( V_19 -> V_24 )
V_89 = ! V_89 ;
if ( V_2 -> V_111 && ! V_89 )
return;
F_74 ( V_19 , V_46 , 0 ,
V_112 ,
V_89 ? 0x02 : 0x00 ) ;
}
static void F_75 ( struct V_18 * V_19 , int V_113 )
{
struct V_6 * V_52 = F_27 ( V_19 , V_113 ) ;
if ( V_52 )
F_64 ( V_19 , V_52 , V_52 -> V_88 , false ) ;
}
static struct V_4 *
F_76 ( struct V_1 * V_2 , int type , const char * V_10 ,
int V_114 , unsigned long V_20 )
{
struct V_4 * V_12 ;
V_12 = F_4 ( V_2 , V_10 , & V_115 [ type ] ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_116 = V_114 ;
if ( F_77 ( V_20 ) )
V_12 -> V_117 = V_118 ;
V_12 -> V_119 = V_20 ;
return V_12 ;
}
static int F_78 ( struct V_1 * V_2 , int type ,
const char * V_62 , const char * V_61 ,
const char * V_120 , int V_114 , unsigned long V_20 )
{
char V_10 [ V_121 ] ;
snprintf ( V_10 , sizeof( V_10 ) , L_30 , V_62 , V_61 , V_120 ) ;
if ( ! F_76 ( V_2 , type , V_10 , V_114 , V_20 ) )
return - V_122 ;
return 0 ;
}
static int F_79 ( struct V_18 * V_19 , const char * V_62 , int V_114 ,
unsigned int V_78 , struct V_6 * V_52 )
{
unsigned int V_20 ;
if ( ! V_52 )
return 0 ;
V_20 = V_52 -> V_60 [ V_98 ] ;
if ( ! V_20 )
return 0 ;
V_20 = F_45 ( V_20 , V_78 ) ;
return F_80 ( V_19 -> V_2 , V_123 , V_62 , V_114 , V_20 ) ;
}
static int F_81 ( struct V_18 * V_19 , struct V_6 * V_52 ,
int type )
{
int V_78 = 1 ;
if ( V_52 ) {
T_1 V_50 = F_77 ( V_52 -> V_60 [ type ] ) ;
if ( V_50 && ( F_40 ( V_19 , V_50 ) & V_124 ) )
V_78 = 3 ;
}
return V_78 ;
}
static int F_82 ( struct V_18 * V_19 , const char * V_62 , int V_114 ,
struct V_6 * V_52 )
{
int V_78 = F_81 ( V_19 , V_52 , V_98 ) ;
return F_79 ( V_19 , V_62 , V_114 , V_78 , V_52 ) ;
}
static int F_83 ( struct V_18 * V_19 , const char * V_62 , int V_114 ,
unsigned int V_78 , struct V_6 * V_52 )
{
unsigned int V_20 ;
int type = V_125 ;
if ( ! V_52 )
return 0 ;
V_20 = V_52 -> V_60 [ V_97 ] ;
if ( ! V_20 )
return 0 ;
V_20 = F_45 ( V_20 , V_78 ) ;
if ( F_84 ( V_20 ) == V_83 ) {
T_1 V_50 = F_77 ( V_20 ) ;
int V_51 = F_85 ( V_19 , V_50 ) ;
if ( V_51 > 1 ) {
type = V_126 ;
V_20 |= V_51 << 19 ;
}
}
return F_86 ( V_19 -> V_2 , type , V_62 , V_114 , V_20 ) ;
}
static int F_87 ( struct V_18 * V_19 , const char * V_62 ,
int V_114 , struct V_6 * V_52 )
{
int V_78 = F_81 ( V_19 , V_52 , V_97 ) ;
return F_83 ( V_19 , V_62 , V_114 , V_78 , V_52 ) ;
}
static void F_88 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_33 ) {
T_1 V_50 = F_90 ( V_128 ) ;
bool V_131 = ! ( ( V_2 -> V_132 >> V_50 ) & 1 ) ;
V_130 -> V_133 . integer . V_133 [ 0 ] &= V_131 ;
V_130 -> V_133 . integer . V_133 [ 1 ] &= V_131 ;
}
}
static int F_91 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
F_88 ( V_128 , V_130 ) ;
return F_92 ( V_128 , V_130 ) ;
}
static int F_93 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
F_88 ( V_128 , V_130 ) ;
return F_94 ( V_128 , V_130 ) ;
}
static bool F_95 ( struct V_18 * V_19 , int V_113 , int V_134 )
{
struct V_6 * V_52 = F_27 ( V_19 , V_113 ) ;
return V_52 && V_52 -> V_60 [ V_134 ] ;
}
static const char * F_96 ( struct V_18 * V_19 , int V_135 ,
int * V_116 , int V_134 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_136 * V_137 = & V_2 -> V_138 ;
* V_116 = 0 ;
if ( V_137 -> V_139 == 1 && ! V_2 -> V_140 &&
! V_137 -> V_141 && ! V_137 -> V_142 )
return V_2 -> V_143 . V_144 ? L_31 : L_32 ;
if ( V_2 -> V_145 . V_146 == 1 && ! V_2 -> V_45 &&
! V_2 -> V_145 . V_147 [ 0 ] && ! V_2 -> V_145 . V_148 [ 0 ] )
return V_2 -> V_143 . V_144 ? L_31 : L_32 ;
if ( V_135 >= V_137 -> V_139 )
return V_149 [ V_135 ] ;
switch ( V_137 -> V_150 ) {
case V_151 :
if ( ! V_135 && V_137 -> V_141 &&
! F_95 ( V_19 , V_2 -> V_152 [ 0 ] , V_134 ) )
break;
if ( V_137 -> V_139 == 1 )
return L_33 ;
if ( V_137 -> V_139 == 2 )
return V_135 ? L_34 : L_33 ;
break;
case V_153 :
if ( ! V_135 && V_137 -> V_142 &&
! F_95 ( V_19 , V_2 -> V_154 [ 0 ] , V_134 ) )
break;
if ( V_135 && V_2 -> V_140 )
break;
* V_116 = V_135 ;
return L_35 ;
}
if ( V_137 -> V_139 == 1 && ! V_2 -> V_140 )
return L_31 ;
if ( V_135 >= F_97 ( V_149 ) ) {
F_98 () ;
return L_31 ;
}
return V_149 [ V_135 ] ;
}
static int F_99 ( struct V_18 * V_19 , struct V_6 * V_52 )
{
T_1 V_50 ;
unsigned int V_20 ;
int V_155 = 0 ;
if ( ! V_52 )
return V_156 * 2 ;
if ( V_52 -> V_60 [ V_98 ] ||
V_52 -> V_60 [ V_97 ] )
return 0 ;
V_50 = F_51 ( V_19 , V_52 ) ;
if ( V_50 ) {
V_20 = F_33 ( V_50 , 3 , 0 , V_82 ) ;
if ( F_31 ( V_19 , V_20 , V_98 ) )
V_155 += V_156 ;
else
V_52 -> V_60 [ V_98 ] = V_20 ;
} else
V_155 += V_156 ;
V_50 = F_49 ( V_19 , V_52 ) ;
if ( V_50 ) {
unsigned int V_157 = F_39 ( F_40 ( V_19 , V_50 ) ) ;
if ( V_157 == V_70 || V_157 == V_66 ||
F_50 ( V_19 , V_50 , V_82 ) )
V_20 = F_33 ( V_50 , 3 , 0 , V_82 ) ;
else
V_20 = F_33 ( V_50 , 3 , 0 , V_83 ) ;
if ( F_31 ( V_19 , V_20 , V_97 ) )
V_155 += V_156 ;
else
V_52 -> V_60 [ V_97 ] = V_20 ;
} else
V_155 += V_156 ;
return V_155 ;
}
static T_1 F_100 ( struct V_18 * V_19 , int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_136 * V_137 = & V_2 -> V_138 ;
if ( V_137 -> V_139 > V_58 )
return V_2 -> V_158 [ V_58 ] ;
V_58 -= V_137 -> V_139 ;
if ( V_2 -> V_140 > V_58 )
return V_2 -> V_159 [ V_58 ] . V_160 ;
return 0 ;
}
static inline T_1 F_101 ( struct V_18 * V_19 ,
T_1 V_160 , T_1 V_46 )
{
return F_29 ( V_19 , V_160 , V_46 ) ? V_160 : 0 ;
}
static int F_102 ( struct V_18 * V_19 , int V_161 ,
const T_1 * V_49 , T_1 * V_162 ,
int * V_113 ,
const struct V_163 * V_164 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_165 ;
int V_155 = 0 ;
T_1 V_160 ;
if ( ! V_161 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_161 ; V_16 ++ ) {
struct V_6 * V_52 ;
T_1 V_46 = V_49 [ V_16 ] ;
V_52 = F_27 ( V_19 , V_113 [ V_16 ] ) ;
if ( V_52 ) {
V_155 += F_99 ( V_19 , V_52 ) ;
continue;
}
V_162 [ V_16 ] = F_44 ( V_19 , V_46 , false ) ;
if ( ! V_162 [ V_16 ] && ! V_16 ) {
for ( V_165 = 1 ; V_165 < V_161 ; V_165 ++ ) {
if ( F_29 ( V_19 , V_162 [ V_165 ] , V_46 ) ) {
V_162 [ 0 ] = V_162 [ V_165 ] ;
V_162 [ V_165 ] = 0 ;
F_43 ( V_19 , V_113 [ V_165 ] ) ;
V_113 [ V_165 ] = 0 ;
break;
}
}
}
V_160 = V_162 [ V_16 ] ;
if ( ! V_160 ) {
if ( V_161 > 2 )
V_160 = F_101 ( V_19 , F_100 ( V_19 , V_16 ) , V_46 ) ;
if ( ! V_160 )
V_160 = F_101 ( V_19 , V_162 [ 0 ] , V_46 ) ;
if ( ! V_160 )
V_160 = F_101 ( V_19 , F_100 ( V_19 , V_16 ) , V_46 ) ;
if ( V_160 ) {
if ( ! V_16 )
V_155 += V_164 -> V_166 ;
else if ( V_16 == 1 )
V_155 += V_164 -> V_167 ;
else
V_155 += V_164 -> V_168 ;
} else if ( F_29 ( V_19 , V_2 -> V_158 [ 0 ] , V_46 ) ) {
V_160 = V_2 -> V_158 [ 0 ] ;
V_155 += V_164 -> V_169 ;
} else if ( ! V_16 )
V_155 += V_164 -> V_170 ;
else
V_155 += V_164 -> V_171 ;
}
if ( ! V_160 )
continue;
V_52 = F_42 ( V_19 , V_160 , V_46 , - V_2 -> V_45 ) ;
if ( ! V_52 && ! V_16 && V_2 -> V_45 ) {
V_52 = F_42 ( V_19 , V_160 , V_46 , 0 ) ;
}
if ( ! V_52 ) {
V_160 = V_162 [ V_16 ] = 0 ;
V_155 += V_164 -> V_171 ;
} else {
V_52 -> V_88 = true ;
V_113 [ V_16 ] = F_26 ( V_19 , V_52 ) ;
V_155 += F_99 ( V_19 , V_52 ) ;
}
}
return V_155 ;
}
static T_1 F_103 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_172 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_75 ; V_16 ++ ) {
T_1 V_50 = V_2 -> V_76 [ V_16 ] ;
if ( ! V_50 || F_28 ( V_19 , V_50 ) )
continue;
if ( F_29 ( V_19 , V_50 , V_46 ) ) {
if ( V_172 )
return 0 ;
V_172 = V_50 ;
}
}
return V_172 ;
}
static bool F_104 ( struct V_18 * V_19 ,
unsigned int V_173 , T_1 V_50 )
{
unsigned int V_174 , V_84 ;
V_174 = F_105 ( V_19 , V_50 ) ;
if ( F_106 ( V_174 ) != V_175 )
return false ;
if ( V_173 && F_107 ( V_174 ) != V_173 )
return false ;
V_84 = F_73 ( V_19 , V_50 ) ;
if ( ! ( V_84 & V_176 ) )
return false ;
return true ;
}
static int F_108 ( struct V_18 * V_19 , T_1 V_177 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_136 * V_137 = & V_2 -> V_138 ;
unsigned int V_174 = F_105 ( V_19 , V_177 ) ;
unsigned int V_173 = F_107 ( V_174 ) ;
int type , V_16 ;
int V_48 = 0 ;
for ( type = V_178 ; type >= V_179 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_137 -> V_180 ; V_16 ++ ) {
if ( V_137 -> V_181 [ V_16 ] . type != type )
continue;
if ( F_104 ( V_19 , V_173 ,
V_137 -> V_181 [ V_16 ] . V_46 ) )
V_48 ++ ;
}
}
return V_48 ;
}
static int F_109 ( struct V_18 * V_19 ,
T_1 V_177 ,
bool V_182 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_136 * V_137 = & V_2 -> V_138 ;
int type , V_16 , V_165 , V_48 , V_183 ;
unsigned int V_174 = F_105 ( V_19 , V_177 ) ;
unsigned int V_173 = F_107 ( V_174 ) ;
int V_155 = 0 ;
struct V_6 * V_52 ;
V_183 = V_2 -> V_140 ;
if ( V_183 >= 2 )
goto V_184;
V_48 = F_108 ( V_19 , V_177 ) ;
if ( V_48 < 2 )
goto V_184;
for ( type = V_178 ; type >= V_179 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_137 -> V_180 ; V_16 ++ ) {
T_1 V_50 = V_137 -> V_181 [ V_16 ] . V_46 ;
T_1 V_160 = 0 ;
if ( V_137 -> V_181 [ V_16 ] . type != type )
continue;
if ( ! F_104 ( V_19 , V_173 , V_50 ) )
continue;
for ( V_165 = 0 ; V_165 < V_2 -> V_140 ; V_165 ++ ) {
if ( V_50 == V_2 -> V_159 [ V_165 ] . V_46 )
break;
}
if ( V_165 < V_2 -> V_140 )
continue;
if ( V_182 )
V_160 = F_103 ( V_19 , V_50 ) ;
else if ( ! V_160 )
V_160 = F_44 ( V_19 , V_50 , false ) ;
if ( ! V_160 ) {
V_155 ++ ;
continue;
}
V_52 = F_42 ( V_19 , V_160 , V_50 ,
- V_2 -> V_45 ) ;
if ( ! V_52 ) {
V_155 ++ ;
continue;
}
V_2 -> V_159 [ V_2 -> V_140 ] . V_46 = V_50 ;
V_2 -> V_159 [ V_2 -> V_140 ] . V_160 = V_160 ;
V_2 -> V_185 [ V_137 -> V_139 + V_2 -> V_140 ] =
F_26 ( V_19 , V_52 ) ;
V_2 -> V_140 ++ ;
if ( V_2 -> V_140 >= 2 )
break;
}
}
V_184:
if ( V_155 )
V_155 = V_186 ;
if ( V_183 == V_2 -> V_140 ) {
if ( V_182 )
return 1 ;
else
return V_155 ;
}
if ( ! V_182 && V_2 -> V_140 < 2 ) {
V_2 -> V_5 . V_17 -= V_2 -> V_140 - V_183 ;
V_2 -> V_140 = V_183 ;
return V_155 ;
}
for ( V_16 = V_183 ; V_16 < V_2 -> V_140 ; V_16 ++ ) {
V_52 = F_27 ( V_19 , V_2 -> V_185 [ V_137 -> V_139 + V_16 ] ) ;
V_155 += F_99 ( V_19 , V_52 ) ;
}
return V_155 ;
}
static bool F_110 ( struct V_18 * V_19 , int V_187 ,
const T_1 * V_49 , T_1 * V_162 , int * V_113 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
bool V_67 = false ;
for ( V_16 = 0 ; V_16 < V_187 ; V_16 ++ ) {
struct V_6 * V_52 ;
T_1 V_160 ;
if ( V_162 [ V_16 ] )
continue;
V_160 = F_103 ( V_19 , V_49 [ V_16 ] ) ;
if ( ! V_160 )
continue;
V_52 = F_42 ( V_19 , V_160 , V_49 [ V_16 ] ,
- V_2 -> V_45 ) ;
if ( ! V_52 && ! V_16 && V_2 -> V_45 )
V_52 = F_42 ( V_19 , V_160 , V_49 [ V_16 ] , 0 ) ;
if ( V_52 ) {
V_162 [ V_16 ] = V_160 ;
V_67 = true ;
V_52 -> V_88 = true ;
V_113 [ V_16 ] = F_26 ( V_19 , V_52 ) ;
}
}
return V_67 ;
}
static int F_111 ( struct V_18 * V_19 , int V_113 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_52 ;
T_1 V_188 , V_160 , V_46 ;
V_52 = F_27 ( V_19 , V_113 ) ;
if ( ! V_52 || ! V_52 -> V_53 ||
F_22 ( V_52 , V_2 -> V_45 ) )
return 0 ;
V_188 = V_52 -> V_52 [ 0 ] ;
V_160 = V_2 -> V_158 [ 0 ] ;
V_46 = V_52 -> V_52 [ V_52 -> V_53 - 1 ] ;
V_52 = F_42 ( V_19 , V_160 , V_46 , V_2 -> V_45 ) ;
if ( ! V_52 ) {
if ( V_160 != V_188 )
V_160 = V_188 ;
else if ( V_2 -> V_145 . V_147 [ 0 ] )
V_160 = V_2 -> V_145 . V_147 [ 0 ] ;
else if ( V_2 -> V_145 . V_148 [ 0 ] )
V_160 = V_2 -> V_145 . V_148 [ 0 ] ;
else
V_160 = 0 ;
if ( V_160 )
V_52 = F_42 ( V_19 , V_160 , V_46 ,
V_2 -> V_45 ) ;
}
if ( ! V_52 )
return 0 ;
V_52 -> V_88 = false ;
return F_26 ( V_19 , V_52 ) ;
}
static bool F_112 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_136 * V_137 = & V_2 -> V_138 ;
struct V_6 * V_52 ;
int V_16 , V_58 ;
if ( V_137 -> V_150 == V_153 )
V_58 = V_2 -> V_185 [ 0 ] ;
else
V_58 = V_2 -> V_152 [ 0 ] ;
V_52 = F_27 ( V_19 , V_58 ) ;
if ( ! V_52 )
return false ;
if ( ! V_2 -> V_45 || ! F_22 ( V_52 , V_2 -> V_45 ) )
return true ;
for ( V_16 = 0 ; V_16 < V_137 -> V_139 ; V_16 ++ ) {
if ( V_2 -> V_185 [ V_16 ] == V_58 )
break;
V_52 = F_27 ( V_19 , V_2 -> V_185 [ V_16 ] ) ;
if ( V_52 && F_22 ( V_52 , V_2 -> V_45 ) )
return false ;
}
for ( V_16 = 0 ; V_16 < V_137 -> V_142 ; V_16 ++ ) {
V_52 = F_27 ( V_19 , V_2 -> V_154 [ V_16 ] ) ;
if ( V_52 && F_22 ( V_52 , V_2 -> V_45 ) )
return false ;
}
return true ;
}
static void F_113 ( struct V_18 * V_19 , int V_161 ,
T_1 * V_162 , int * V_113 )
{
struct V_6 * V_52 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_161 ; V_16 ++ ) {
if ( V_162 [ V_16 ] )
continue;
V_52 = F_27 ( V_19 , V_113 [ V_16 ] ) ;
if ( ! V_52 )
continue;
V_162 [ V_16 ] = V_52 -> V_52 [ 0 ] ;
}
}
static int F_114 ( struct V_18 * V_19 ,
bool V_189 ,
bool V_190 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_136 * V_137 = & V_2 -> V_138 ;
int V_16 , V_191 , V_155 ;
V_2 -> V_145 . V_146 = V_137 -> V_139 ;
V_2 -> V_145 . V_192 = V_2 -> V_158 ;
memset ( V_2 -> V_158 , 0 , sizeof( V_2 -> V_158 ) ) ;
memset ( V_2 -> V_145 . V_147 , 0 , sizeof( V_2 -> V_145 . V_147 ) ) ;
memset ( V_2 -> V_145 . V_148 , 0 , sizeof( V_2 -> V_145 . V_148 ) ) ;
V_2 -> V_140 = 0 ;
F_9 ( & V_2 -> V_5 ) ;
memset ( V_2 -> V_185 , 0 , sizeof( V_2 -> V_185 ) ) ;
memset ( V_2 -> V_152 , 0 , sizeof( V_2 -> V_152 ) ) ;
memset ( V_2 -> V_154 , 0 , sizeof( V_2 -> V_154 ) ) ;
memset ( V_2 -> V_193 , 0 , sizeof( V_2 -> V_193 ) ) ;
memset ( V_2 -> V_194 , 0 , sizeof( V_2 -> V_194 ) ) ;
memset ( V_2 -> V_195 , 0 , sizeof( V_2 -> V_195 ) ) ;
memset ( V_2 -> V_196 , 0 , sizeof( V_2 -> V_196 ) ) ;
memset ( & V_2 -> V_197 , 0 , sizeof( V_2 -> V_197 ) ) ;
V_155 = 0 ;
if ( V_189 ) {
bool V_198 ;
do {
V_198 = F_110 ( V_19 , V_137 -> V_139 ,
V_137 -> V_199 ,
V_2 -> V_158 ,
V_2 -> V_185 ) ;
V_198 |= F_110 ( V_19 , V_137 -> V_141 ,
V_137 -> V_200 ,
V_2 -> V_145 . V_147 ,
V_2 -> V_152 ) ;
V_198 |= F_110 ( V_19 , V_137 -> V_142 ,
V_137 -> V_201 ,
V_2 -> V_145 . V_148 ,
V_2 -> V_154 ) ;
if ( ! V_2 -> V_36 &&
V_190 && V_137 -> V_139 == 1 &&
V_137 -> V_150 != V_151 ) {
V_191 = F_109 ( V_19 , V_137 -> V_199 [ 0 ] , true ) ;
if ( ! V_191 )
V_198 = true ;
}
} while ( V_198 );
}
V_155 += F_102 ( V_19 , V_137 -> V_139 , V_137 -> V_199 ,
V_2 -> V_158 , V_2 -> V_185 ,
V_2 -> V_202 ) ;
if ( ! V_2 -> V_36 && V_190 &&
V_137 -> V_139 == 1 && V_137 -> V_150 != V_151 ) {
V_191 = F_109 ( V_19 , V_137 -> V_199 [ 0 ] , false ) ;
if ( V_191 < 0 )
return V_191 ;
}
if ( V_137 -> V_150 != V_153 ) {
V_191 = F_102 ( V_19 , V_137 -> V_141 , V_137 -> V_200 ,
V_2 -> V_145 . V_147 ,
V_2 -> V_152 ,
V_2 -> V_203 ) ;
if ( V_191 < 0 )
return V_191 ;
V_155 += V_191 ;
}
if ( V_137 -> V_150 != V_151 ) {
V_191 = F_102 ( V_19 , V_137 -> V_142 ,
V_137 -> V_201 ,
V_2 -> V_145 . V_148 ,
V_2 -> V_154 ,
V_2 -> V_203 ) ;
if ( V_191 < 0 )
return V_191 ;
V_155 += V_191 ;
}
if ( ! V_2 -> V_36 &&
V_137 -> V_139 == 1 && V_137 -> V_150 != V_151 ) {
V_191 = F_109 ( V_19 , V_137 -> V_199 [ 0 ] , false ) ;
if ( V_191 < 0 )
return V_191 ;
V_155 += V_191 ;
}
if ( V_2 -> V_45 ) {
V_2 -> V_193 [ 0 ] =
F_111 ( V_19 , V_2 -> V_185 [ 0 ] ) ;
if ( V_137 -> V_150 != V_153 )
V_2 -> V_193 [ 1 ] =
F_111 ( V_19 , V_2 -> V_152 [ 0 ] ) ;
if ( V_137 -> V_150 != V_151 )
V_2 -> V_193 [ 2 ] =
F_111 ( V_19 , V_2 -> V_154 [ 0 ] ) ;
}
if ( ! V_2 -> V_36 &&
V_137 -> V_141 && V_137 -> V_150 == V_151 )
if ( F_108 ( V_19 , V_137 -> V_200 [ 0 ] ) >= 2 )
V_2 -> V_140 = 1 ;
V_2 -> V_145 . V_146 = 0 ;
for ( V_16 = 0 ; V_16 < V_137 -> V_139 ; V_16 ++ ) {
if ( V_2 -> V_158 [ V_16 ] )
V_2 -> V_145 . V_146 ++ ;
else {
memmove ( V_2 -> V_158 + V_16 ,
V_2 -> V_158 + V_16 + 1 ,
sizeof( T_1 ) * ( V_137 -> V_139 - V_16 - 1 ) ) ;
V_2 -> V_158 [ V_137 -> V_139 - 1 ] = 0 ;
}
}
V_2 -> V_204 = V_2 -> V_205 =
V_2 -> V_145 . V_146 * 2 ;
if ( V_2 -> V_140 == 2 ) {
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
V_2 -> V_158 [ V_2 -> V_145 . V_146 ++ ] =
V_2 -> V_159 [ V_16 ] . V_160 ;
} else if ( V_2 -> V_140 ) {
V_2 -> V_140 = 0 ;
V_155 += V_186 ;
}
if ( V_2 -> V_39 && ! F_112 ( V_19 ) )
V_155 += V_206 ;
if ( V_137 -> V_150 != V_153 )
F_113 ( V_19 , V_137 -> V_141 ,
V_2 -> V_145 . V_147 ,
V_2 -> V_152 ) ;
if ( V_137 -> V_150 != V_151 )
F_113 ( V_19 , V_137 -> V_142 ,
V_2 -> V_145 . V_148 ,
V_2 -> V_154 ) ;
return V_155 ;
}
static inline void F_115 ( struct V_18 * V_19 ,
const char * V_62 , int V_58 )
{
struct V_6 * V_52 ;
V_52 = F_27 ( V_19 , V_58 ) ;
if ( V_52 )
F_34 ( V_62 , V_52 ) ;
}
static void F_116 ( struct V_18 * V_19 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_207 [ 3 ] = { L_36 , L_37 , L_38 } ;
int V_16 ;
F_117 ( L_39 ,
V_137 -> V_199 [ 0 ] , V_137 -> V_199 [ 1 ] ,
V_137 -> V_199 [ 2 ] , V_137 -> V_199 [ 3 ] ,
V_2 -> V_145 . V_192 [ 0 ] ,
V_2 -> V_145 . V_192 [ 1 ] ,
V_2 -> V_145 . V_192 [ 2 ] ,
V_2 -> V_145 . V_192 [ 3 ] ,
V_207 [ V_137 -> V_150 ] ) ;
for ( V_16 = 0 ; V_16 < V_137 -> V_139 ; V_16 ++ )
F_115 ( V_19 , L_40 , V_2 -> V_185 [ V_16 ] ) ;
if ( V_2 -> V_140 > 0 )
F_117 ( L_41 ,
V_2 -> V_140 ,
V_2 -> V_159 [ 0 ] . V_46 , V_2 -> V_159 [ 1 ] . V_46 ,
V_2 -> V_159 [ 0 ] . V_160 , V_2 -> V_159 [ 1 ] . V_160 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_140 ; V_16 ++ )
F_115 ( V_19 , L_42 ,
V_2 -> V_185 [ V_137 -> V_139 + V_16 ] ) ;
if ( V_137 -> V_141 )
F_117 ( L_43 ,
V_137 -> V_200 [ 0 ] , V_137 -> V_200 [ 1 ] ,
V_137 -> V_200 [ 2 ] , V_137 -> V_200 [ 3 ] ,
V_2 -> V_145 . V_147 [ 0 ] ,
V_2 -> V_145 . V_147 [ 1 ] ,
V_2 -> V_145 . V_147 [ 2 ] ,
V_2 -> V_145 . V_147 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_137 -> V_141 ; V_16 ++ )
F_115 ( V_19 , L_44 , V_2 -> V_152 [ V_16 ] ) ;
if ( V_137 -> V_142 )
F_117 ( L_45 ,
V_137 -> V_201 [ 0 ] , V_137 -> V_201 [ 1 ] ,
V_137 -> V_201 [ 2 ] , V_137 -> V_201 [ 3 ] ,
V_2 -> V_145 . V_148 [ 0 ] ,
V_2 -> V_145 . V_148 [ 1 ] ,
V_2 -> V_145 . V_148 [ 2 ] ,
V_2 -> V_145 . V_148 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_137 -> V_142 ; V_16 ++ )
F_115 ( V_19 , L_46 , V_2 -> V_154 [ V_16 ] ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ )
F_115 ( V_19 , L_47 , V_2 -> V_193 [ V_16 ] ) ;
}
static void F_118 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_50 = V_19 -> V_208 ;
V_2 -> V_75 = 0 ;
memset ( V_2 -> V_76 , 0 , sizeof( V_2 -> V_76 ) ) ;
for ( V_16 = 0 ; V_16 < V_19 -> V_209 ; V_16 ++ , V_50 ++ ) {
if ( F_39 ( F_40 ( V_19 , V_50 ) ) != V_66 )
continue;
if ( V_2 -> V_75 >= F_97 ( V_2 -> V_76 ) ) {
F_119 ( V_210 L_48 ) ;
break;
}
V_2 -> V_76 [ V_2 -> V_75 ++ ] = V_50 ;
}
}
static int F_120 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_136 * V_137 = & V_2 -> V_138 ;
struct V_136 * V_211 ;
unsigned int V_20 ;
int V_212 = V_213 ;
int V_155 ;
bool V_189 = true , V_190 = true ;
bool V_214 = true , V_215 = true ;
bool V_216 = false ;
V_211 = F_121 ( sizeof( * V_211 ) , V_13 ) ;
if ( ! V_211 )
return - V_122 ;
* V_211 = * V_137 ;
for (; ; ) {
V_155 = F_114 ( V_19 , V_189 ,
V_190 ) ;
if ( V_155 < 0 ) {
F_8 ( V_211 ) ;
return V_155 ;
}
F_117 ( L_49 ,
V_137 -> V_150 , V_189 , V_190 ,
V_155 ) ;
F_116 ( V_19 , V_137 ) ;
if ( V_155 < V_212 ) {
V_212 = V_155 ;
* V_211 = * V_137 ;
V_214 = V_189 ;
V_215 = V_190 ;
}
if ( ! V_155 )
break;
V_190 = ! V_190 ;
if ( ! V_190 )
continue;
V_189 = ! V_189 ;
if ( ! V_189 )
continue;
if ( V_216 )
break;
V_216 = true ;
if ( V_137 -> V_142 > 0 &&
V_137 -> V_150 == V_153 ) {
V_137 -> V_141 = V_137 -> V_139 ;
memcpy ( V_137 -> V_200 , V_137 -> V_199 ,
sizeof( V_137 -> V_200 ) ) ;
V_137 -> V_139 = V_137 -> V_142 ;
memcpy ( V_137 -> V_199 , V_137 -> V_201 ,
sizeof( V_137 -> V_201 ) ) ;
V_137 -> V_142 = 0 ;
memset ( V_137 -> V_201 , 0 , sizeof( V_137 -> V_201 ) ) ;
V_137 -> V_150 = V_151 ;
V_189 = true ;
continue;
}
if ( V_137 -> V_141 > 0 &&
V_137 -> V_150 == V_151 ) {
V_137 -> V_142 = V_137 -> V_139 ;
memcpy ( V_137 -> V_201 , V_137 -> V_199 ,
sizeof( V_137 -> V_201 ) ) ;
V_137 -> V_139 = V_137 -> V_141 ;
memcpy ( V_137 -> V_199 , V_137 -> V_200 ,
sizeof( V_137 -> V_200 ) ) ;
V_137 -> V_141 = 0 ;
memset ( V_137 -> V_200 , 0 , sizeof( V_137 -> V_200 ) ) ;
V_137 -> V_150 = V_153 ;
V_189 = true ;
continue;
}
break;
}
if ( V_155 ) {
F_117 ( L_50 ) ;
* V_137 = * V_211 ;
F_114 ( V_19 , V_214 , V_215 ) ;
}
F_117 ( L_51 ,
V_137 -> V_150 , V_214 , V_215 ) ;
F_116 ( V_19 , V_137 ) ;
if ( V_137 -> V_199 [ 0 ] ) {
struct V_6 * V_52 ;
V_52 = F_27 ( V_19 , V_2 -> V_185 [ 0 ] ) ;
if ( V_52 )
V_2 -> V_217 = F_51 ( V_19 , V_52 ) ;
if ( V_2 -> V_217 )
F_122 ( V_19 , V_2 -> V_217 ,
V_82 , V_2 -> V_218 ) ;
}
if ( V_2 -> V_219 || V_137 -> V_150 == V_153 )
V_20 = V_220 ;
else
V_20 = V_221 ;
F_20 ( V_19 , V_137 -> V_139 , V_137 -> V_199 , V_20 ) ;
if ( V_137 -> V_150 != V_153 )
F_20 ( V_19 , V_137 -> V_141 , V_137 -> V_200 , V_220 ) ;
if ( V_137 -> V_150 != V_151 ) {
V_20 = V_2 -> V_219 ? V_220 : V_221 ;
F_20 ( V_19 , V_137 -> V_142 ,
V_137 -> V_201 , V_20 ) ;
}
if ( V_2 -> V_39 && ! F_112 ( V_19 ) )
V_2 -> V_39 = 0 ;
F_8 ( V_211 ) ;
return 0 ;
}
static int F_123 ( struct V_18 * V_19 ,
const struct V_136 * V_137 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_191 , V_222 ;
V_222 = V_137 -> V_139 ;
if ( V_2 -> V_140 > 0 && V_137 -> V_139 < 3 )
V_222 += V_2 -> V_140 ;
for ( V_16 = 0 ; V_16 < V_222 ; V_16 ++ ) {
const char * V_10 ;
int V_116 ;
struct V_6 * V_52 ;
V_52 = F_27 ( V_19 , V_2 -> V_185 [ V_16 ] ) ;
if ( ! V_52 )
continue;
V_10 = F_96 ( V_19 , V_16 , & V_116 , V_98 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_52 ) ) {
V_191 = F_79 ( V_19 , L_53 , 0 , 1 , V_52 ) ;
if ( V_191 < 0 )
return V_191 ;
V_191 = F_79 ( V_19 , L_54 , 0 , 2 , V_52 ) ;
if ( V_191 < 0 )
return V_191 ;
} else {
V_191 = F_82 ( V_19 , V_10 , V_116 , V_52 ) ;
if ( V_191 < 0 )
return V_191 ;
}
V_10 = F_96 ( V_19 , V_16 , & V_116 , V_97 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_52 ) ) {
V_191 = F_83 ( V_19 , L_53 , 0 , 1 , V_52 ) ;
if ( V_191 < 0 )
return V_191 ;
V_191 = F_83 ( V_19 , L_54 , 0 , 2 , V_52 ) ;
if ( V_191 < 0 )
return V_191 ;
} else {
V_191 = F_87 ( V_19 , V_10 , V_116 , V_52 ) ;
if ( V_191 < 0 )
return V_191 ;
}
}
return 0 ;
}
static int F_124 ( struct V_18 * V_19 , int V_113 ,
const char * V_62 , int V_114 )
{
struct V_6 * V_52 ;
int V_191 ;
V_52 = F_27 ( V_19 , V_113 ) ;
if ( ! V_52 )
return 0 ;
V_191 = F_82 ( V_19 , V_62 , V_114 , V_52 ) ;
if ( V_191 < 0 )
return V_191 ;
V_191 = F_87 ( V_19 , V_62 , V_114 , V_52 ) ;
if ( V_191 < 0 )
return V_191 ;
return 0 ;
}
static int F_125 ( struct V_18 * V_19 , int V_48 ,
const int * V_5 , const char * V_62 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
const char * V_10 ;
char V_64 [ V_121 ] ;
int V_191 , V_58 = 0 ;
if ( V_48 == 2 && V_16 == 1 && ! strcmp ( V_62 , L_33 ) )
V_10 = L_34 ;
else if ( V_48 >= 3 ) {
snprintf ( V_64 , sizeof( V_64 ) , L_55 ,
V_62 , V_149 [ V_16 ] ) ;
V_10 = V_64 ;
} else {
V_10 = V_62 ;
V_58 = V_16 ;
}
V_191 = F_124 ( V_19 , V_5 [ V_16 ] , V_10 , V_58 ) ;
if ( V_191 < 0 )
return V_191 ;
}
return 0 ;
}
static int F_126 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_125 ( V_19 , V_2 -> V_138 . V_141 ,
V_2 -> V_152 ,
L_35 ) ;
}
static int F_127 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_125 ( V_19 , V_2 -> V_138 . V_142 ,
V_2 -> V_154 ,
L_33 ) ;
}
static int F_128 ( struct V_127 * V_128 ,
struct V_223 * V_224 )
{
return F_129 ( V_128 , V_224 ) ;
}
static int F_130 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_130 -> V_133 . V_225 . V_226 [ 0 ] = V_2 -> V_227 ;
return 0 ;
}
static int F_131 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_228 = V_130 -> V_133 . V_225 . V_226 [ 0 ] ;
int V_229 = 0 ;
F_132 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_230 ) {
V_229 = - V_231 ;
goto V_232;
}
if ( V_2 -> V_227 != V_228 ) {
T_1 * V_233 ;
if ( V_2 -> V_138 . V_150 == V_153 )
V_233 = & V_2 -> V_158 [ 0 ] ;
else
V_233 = & V_2 -> V_145 . V_147 [ 0 ] ;
if ( V_2 -> V_234 ) {
if ( V_2 -> V_138 . V_150 == V_153 )
F_133 ( V_19 , V_2 -> V_235 ,
V_2 -> V_185 [ 0 ] ,
V_2 -> V_193 [ 0 ] ,
V_2 -> V_138 . V_150 ) ;
else
F_133 ( V_19 , V_2 -> V_235 ,
V_2 -> V_152 [ 0 ] ,
V_2 -> V_193 [ 1 ] ,
V_153 ) ;
}
V_2 -> V_227 = V_228 ;
if ( V_2 -> V_227 )
* V_233 = 0 ;
else
* V_233 = V_2 -> V_236 ;
F_134 ( V_19 , NULL ) ;
V_229 = 1 ;
}
V_232:
F_135 ( & V_2 -> V_9 ) ;
return V_229 ;
}
static int F_136 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_160 ;
if ( ! V_2 -> V_39 )
return 0 ;
if ( V_2 -> V_138 . V_150 == V_153 )
V_160 = V_2 -> V_145 . V_192 [ 0 ] ;
else
V_160 = V_2 -> V_145 . V_147 [ 0 ] ;
if ( ! V_160 ) {
V_2 -> V_39 = 0 ;
return 0 ;
}
V_2 -> V_227 = false ;
V_2 -> V_236 = V_160 ;
if ( ! F_4 ( V_2 , NULL , & V_237 ) )
return - V_122 ;
return 0 ;
}
static int F_137 ( struct V_127 * V_128 ,
struct V_223 * V_224 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_78 ;
V_224 -> type = V_238 ;
V_224 -> V_239 = 1 ;
V_224 -> V_133 . V_225 . V_240 = V_2 -> V_140 + 1 ;
if ( V_224 -> V_133 . V_225 . V_226 > V_2 -> V_140 )
V_224 -> V_133 . V_225 . V_226 = V_2 -> V_140 ;
V_78 = V_224 -> V_133 . V_225 . V_226 * 2 + V_2 -> V_205 ;
sprintf ( V_224 -> V_133 . V_225 . V_10 , L_56 , V_78 ) ;
return 0 ;
}
static int F_138 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_130 -> V_133 . V_225 . V_226 [ 0 ] =
( V_2 -> V_204 - V_2 -> V_205 ) / 2 ;
return 0 ;
}
static inline struct V_6 *
F_139 ( struct V_18 * V_19 , int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_27 ( V_19 ,
V_2 -> V_185 [ V_2 -> V_138 . V_139 + V_58 ] ) ;
}
static bool F_140 ( struct V_1 * V_2 )
{
return ! V_2 -> V_234 || V_2 -> V_235 ;
}
static int F_141 ( struct V_18 * V_19 , int V_58 , bool V_241 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_50 = V_2 -> V_159 [ V_58 ] . V_46 ;
struct V_6 * V_52 ;
V_52 = F_139 ( V_19 , V_58 ) ;
if ( ! V_52 )
return - V_242 ;
if ( V_52 -> V_88 == V_241 )
return 0 ;
if ( V_241 ) {
F_17 ( V_19 , V_50 , V_221 , true ) ;
F_64 ( V_19 , V_52 , true , F_140 ( V_2 ) ) ;
F_72 ( V_19 , V_50 , true ) ;
} else {
F_72 ( V_19 , V_50 , false ) ;
F_64 ( V_19 , V_52 , false , F_140 ( V_2 ) ) ;
F_17 ( V_19 , V_50 , V_2 -> V_159 [ V_58 ] . V_243 , true ) ;
F_68 ( V_19 , V_52 ) ;
}
F_142 ( V_19 ) ;
return 0 ;
}
static int F_143 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_135 ;
V_135 = V_130 -> V_133 . V_225 . V_226 [ 0 ] ;
if ( V_135 < 0 || V_135 > V_2 -> V_140 )
return - V_242 ;
if ( V_135 == ( V_2 -> V_204 - V_2 -> V_205 ) / 2 )
return 0 ;
V_2 -> V_204 = V_135 * 2 + V_2 -> V_205 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_140 ; V_16 ++ )
F_141 ( V_19 , V_16 , V_16 < V_135 ) ;
V_2 -> V_145 . V_244 = F_144 ( V_2 -> V_204 ,
V_2 -> V_245 ) ;
if ( V_2 -> V_34 )
V_2 -> V_145 . V_146 = V_2 -> V_145 . V_244 / 2 ;
return 1 ;
}
static int F_145 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_140 > 0 ) {
if ( ! F_4 ( V_2 , NULL , & V_246 ) )
return - V_122 ;
}
return 0 ;
}
static int F_146 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_130 -> V_133 . V_225 . V_226 [ 0 ] = V_2 -> V_235 ;
return 0 ;
}
static void F_133 ( struct V_18 * V_19 , bool V_247 ,
int V_248 , int V_249 ,
int V_250 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_251 , * V_252 ;
V_251 = F_27 ( V_19 , V_248 ) ;
V_252 = F_27 ( V_19 , V_249 ) ;
if ( ! V_251 || ! V_252 )
return;
if ( V_250 == V_153 && V_2 -> V_227 &&
V_252 -> V_52 [ 0 ] != V_2 -> V_236 )
V_247 = false ;
if ( V_247 ) {
F_64 ( V_19 , V_251 , false , true ) ;
F_64 ( V_19 , V_252 , true , true ) ;
F_68 ( V_19 , V_251 ) ;
} else {
F_64 ( V_19 , V_252 , false , false ) ;
F_64 ( V_19 , V_251 , true , false ) ;
F_68 ( V_19 , V_252 ) ;
}
}
static int F_147 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = V_130 -> V_133 . V_225 . V_226 [ 0 ] ;
if ( V_20 == V_2 -> V_235 )
return 0 ;
V_2 -> V_235 = V_20 ;
F_133 ( V_19 , V_20 , V_2 -> V_185 [ 0 ] ,
V_2 -> V_193 [ 0 ] ,
V_2 -> V_138 . V_150 ) ;
F_133 ( V_19 , V_20 , V_2 -> V_152 [ 0 ] ,
V_2 -> V_193 [ 1 ] ,
V_153 ) ;
F_133 ( V_19 , V_20 , V_2 -> V_154 [ 0 ] ,
V_2 -> V_193 [ 2 ] ,
V_151 ) ;
return 1 ;
}
static int F_148 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_45 )
return 0 ;
if ( ! ( V_2 -> V_193 [ 0 ] || V_2 -> V_193 [ 1 ] ||
V_2 -> V_193 [ 2 ] ) )
return 0 ;
if ( ! F_4 ( V_2 , NULL , & V_253 ) )
return - V_122 ;
V_2 -> V_234 = 1 ;
return 0 ;
}
static void F_149 ( struct V_18 * V_19 , int V_254 , bool V_255 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_256 ;
unsigned int V_20 ;
T_1 V_46 ;
V_46 = V_2 -> V_257 ;
V_256 = V_2 -> V_258 [ V_254 ] == V_2 -> V_259 ;
if ( ! V_255 ) {
V_20 = F_16 ( V_19 , V_46 ) ;
if ( V_256 ) {
if ( V_20 & V_260 )
return;
} else {
if ( V_20 & V_221 )
return;
}
}
V_20 = F_150 ( V_19 , V_46 ) ;
if ( V_20 == V_261 && V_2 -> V_262 ) {
const T_1 V_263 = V_2 -> V_262 ;
unsigned int V_264 = F_150 ( V_19 , V_263 ) ;
if ( V_264 != V_261 )
F_151 ( V_19 , V_263 ,
V_260 | ( V_256 ? V_264 : 0 ) ) ;
}
if ( ! V_2 -> V_265 ) {
if ( V_256 )
V_20 |= V_260 ;
else
V_20 = V_220 ;
F_17 ( V_19 , V_46 , V_20 , true ) ;
F_134 ( V_19 , NULL ) ;
}
}
static int F_152 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_136 * V_137 = & V_2 -> V_138 ;
unsigned int V_174 ;
T_1 V_50 ;
if ( ! V_2 -> V_43 ) {
if ( V_2 -> V_44 )
return 0 ;
if ( V_137 -> V_180 > 1 )
return 0 ;
else if ( V_137 -> V_180 == 1 ) {
V_174 = F_105 ( V_19 , V_137 -> V_181 [ 0 ] . V_46 ) ;
if ( F_153 ( V_174 ) != V_266 )
return 0 ;
}
}
V_2 -> V_43 = 0 ;
if ( V_137 -> V_180 >= V_267 )
return 0 ;
V_50 = 0 ;
if ( V_137 -> V_150 == V_153 && V_137 -> V_139 > 0 )
V_50 = V_137 -> V_199 [ 0 ] ;
else if ( V_137 -> V_141 > 0 )
V_50 = V_137 -> V_200 [ 0 ] ;
if ( ! V_50 )
return 0 ;
if ( ! ( F_73 ( V_19 , V_50 ) & V_268 ) )
return 0 ;
V_137 -> V_181 [ V_137 -> V_180 ] . V_46 = V_50 ;
V_137 -> V_181 [ V_137 -> V_180 ] . type = V_179 ;
V_137 -> V_181 [ V_137 -> V_180 ] . V_269 = 1 ;
V_137 -> V_180 ++ ;
V_2 -> V_43 = 1 ;
V_2 -> V_257 = V_50 ;
V_2 -> V_31 = 1 ;
F_36 ( L_57 , V_50 ) ;
return 0 ;
}
static int F_154 ( struct V_127 * V_128 ,
struct V_223 * V_224 )
{
return F_155 ( V_128 , V_224 , 2 , V_270 ) ;
}
static int F_156 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
T_1 V_50 = V_128 -> V_119 ;
if ( F_16 ( V_19 , V_50 ) == V_220 )
V_130 -> V_133 . V_225 . V_226 [ 0 ] = 1 ;
else
V_130 -> V_133 . V_225 . V_226 [ 0 ] = 0 ;
return 0 ;
}
static int F_157 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
T_1 V_50 = V_128 -> V_119 ;
unsigned int V_20 ;
V_20 = V_130 -> V_133 . V_225 . V_226 [ 0 ] ? V_220 : V_221 ;
if ( F_16 ( V_19 , V_50 ) == V_20 )
return 0 ;
F_151 ( V_19 , V_50 , V_20 ) ;
return 1 ;
}
static bool F_158 ( struct V_18 * V_19 , const char * V_10 , int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_3 . V_17 ; V_16 ++ ) {
struct V_4 * V_15 = F_24 ( & V_2 -> V_3 , V_16 ) ;
if ( ! strcmp ( V_15 -> V_10 , V_10 ) && V_15 -> V_116 == V_58 )
return true ;
}
return false ;
}
static void F_159 ( struct V_18 * V_19 , T_1 V_46 ,
char * V_10 , T_3 V_271 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_58 = 0 ;
F_160 ( V_19 , V_46 , & V_2 -> V_138 , V_10 , V_271 , & V_58 ) ;
F_35 ( V_10 , L_58 , V_271 ) ;
for (; F_158 ( V_19 , V_10 , V_58 ) ; V_58 ++ )
;
}
static int F_161 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_41 ) {
unsigned int V_272 = F_73 ( V_19 , V_46 ) ;
if ( ( V_272 & V_176 ) && ( V_272 & V_273 ) )
return 2 ;
}
return 1 ;
}
static int F_162 ( struct V_18 * V_19 , int V_48 ,
T_1 * V_49 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
T_1 V_46 = V_49 [ V_16 ] ;
if ( V_46 == V_2 -> V_257 ) {
int V_229 = F_163 ( V_19 , V_46 ) ;
if ( V_229 < 0 )
return V_229 ;
continue;
}
if ( F_161 ( V_19 , V_46 ) > 1 ) {
struct V_4 * V_12 ;
char V_10 [ V_121 ] ;
F_159 ( V_19 , V_46 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 ,
& V_274 ) ;
if ( ! V_12 )
return - V_122 ;
V_12 -> V_119 = V_46 ;
}
}
return 0 ;
}
static unsigned int F_164 ( struct V_18 * V_19 , T_1 V_46 )
{
unsigned int V_272 ;
V_272 = F_73 ( V_19 , V_46 ) ;
V_272 = ( V_272 & V_275 ) >> V_276 ;
V_272 &= ~ ( V_277 | V_278 ) ;
return V_272 ;
}
static int F_165 ( unsigned int V_279 , unsigned int V_280 )
{
unsigned int V_16 , V_87 = 0 ;
for ( V_16 = 0 ; V_16 < V_281 ; V_16 ++ ) {
if ( V_279 & ( 1 << V_16 ) ) {
if ( V_87 == V_280 )
return V_16 ;
V_87 ++ ;
}
}
return 0 ;
}
static int F_166 ( unsigned int V_279 , unsigned int V_58 )
{
unsigned int V_16 , V_87 = 0 ;
for ( V_16 = 0 ; V_16 < V_281 ; V_16 ++ ) {
if ( V_16 == V_58 )
return V_87 ;
if ( V_279 & ( 1 << V_16 ) )
V_87 ++ ;
}
return 0 ;
}
static int F_167 ( struct V_127 * V_128 ,
struct V_223 * V_224 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
T_1 V_50 = V_128 -> V_119 ;
unsigned int V_279 = F_164 ( V_19 , V_50 ) ;
F_155 ( V_128 , V_224 , F_168 ( V_279 ) ,
V_282 ) ;
strcpy ( V_224 -> V_133 . V_225 . V_10 ,
V_282 [ F_165 ( V_279 , V_224 -> V_133 . V_225 . V_226 ) ] ) ;
return 0 ;
}
static int F_169 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
T_1 V_50 = V_128 -> V_119 ;
unsigned int V_279 = F_164 ( V_19 , V_50 ) ;
unsigned int V_58 ;
V_58 = F_16 ( V_19 , V_50 ) & V_283 ;
V_130 -> V_133 . V_225 . V_226 [ 0 ] = F_166 ( V_279 , V_58 ) ;
return 0 ;
}
static int F_170 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
T_1 V_50 = V_128 -> V_119 ;
unsigned int V_279 = F_164 ( V_19 , V_50 ) ;
unsigned int V_20 , V_58 ;
V_20 = F_16 ( V_19 , V_50 ) ;
V_58 = F_166 ( V_279 , V_20 & V_283 ) ;
if ( V_58 == V_130 -> V_133 . V_225 . V_226 [ 0 ] )
return 0 ;
V_20 &= ~ V_283 ;
V_20 |= F_165 ( V_279 , V_130 -> V_133 . V_225 . V_226 [ 0 ] ) ;
F_151 ( V_19 , V_50 , V_20 ) ;
return 1 ;
}
static int F_171 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_284 = 0 ;
if ( V_2 -> V_41 )
V_284 = F_168 ( F_164 ( V_19 , V_46 ) ) ;
return V_284 ? V_284 : 1 ;
}
static int F_172 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
char V_10 [ V_121 ] ;
unsigned int V_174 ;
if ( V_46 == V_2 -> V_257 )
return 0 ;
V_174 = F_105 ( V_19 , V_46 ) ;
if ( F_153 ( V_174 ) == V_266 )
return 0 ;
if ( F_171 ( V_19 , V_46 ) <= 1 )
return 0 ;
F_159 ( V_19 , V_46 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 , & V_285 ) ;
if ( ! V_12 )
return - V_122 ;
V_12 -> V_119 = V_46 ;
return 0 ;
}
static int F_173 ( struct V_127 * V_128 ,
struct V_223 * V_224 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
T_1 V_50 = V_128 -> V_119 ;
int V_286 = F_161 ( V_19 , V_50 ) ;
int V_287 = F_171 ( V_19 , V_50 ) ;
const char * V_288 = NULL ;
int V_58 ;
V_224 -> type = V_238 ;
V_224 -> V_239 = 1 ;
V_224 -> V_133 . V_225 . V_240 = V_286 + V_287 ;
if ( V_224 -> V_133 . V_225 . V_226 >= V_224 -> V_133 . V_225 . V_240 )
V_224 -> V_133 . V_225 . V_226 = V_224 -> V_133 . V_225 . V_240 - 1 ;
V_58 = V_224 -> V_133 . V_225 . V_226 ;
if ( V_58 < V_286 ) {
if ( V_286 > 1 )
V_288 = V_270 [ V_58 ] ;
else
V_288 = L_59 ;
} else {
V_58 -= V_286 ;
if ( V_287 > 1 ) {
unsigned int V_279 = F_164 ( V_19 , V_50 ) ;
V_288 = V_282 [ F_165 ( V_279 , V_58 ) ] ;
} else
V_288 = L_60 ;
}
strcpy ( V_224 -> V_133 . V_225 . V_10 , V_288 ) ;
return 0 ;
}
static int F_174 ( struct V_18 * V_19 , T_1 V_50 )
{
int V_286 = F_161 ( V_19 , V_50 ) ;
int V_287 = F_171 ( V_19 , V_50 ) ;
unsigned int V_20 = F_16 ( V_19 , V_50 ) ;
int V_58 = 0 ;
if ( V_20 & V_221 ) {
if ( V_286 > 1 && V_20 == V_220 )
V_58 = 1 ;
} else if ( V_20 & V_260 ) {
V_58 = V_286 ;
if ( V_287 > 1 ) {
unsigned int V_279 = F_164 ( V_19 , V_50 ) ;
V_20 &= V_283 ;
V_58 += F_166 ( V_279 , V_20 ) ;
}
}
return V_58 ;
}
static int F_175 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
T_1 V_50 = V_128 -> V_119 ;
V_130 -> V_133 . V_225 . V_226 [ 0 ] =
F_174 ( V_19 , V_50 ) ;
return 0 ;
}
static int F_176 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
T_1 V_50 = V_128 -> V_119 ;
int V_286 = F_161 ( V_19 , V_50 ) ;
int V_287 = F_171 ( V_19 , V_50 ) ;
unsigned int V_20 , V_289 , V_58 ;
V_289 = F_174 ( V_19 , V_50 ) ;
V_58 = V_130 -> V_133 . V_225 . V_226 [ 0 ] ;
if ( V_289 == V_58 )
return 0 ;
if ( V_58 < V_286 ) {
if ( V_286 > 1 )
V_20 = V_58 ? V_220 : V_221 ;
else
V_20 = V_220 ;
} else {
V_58 -= V_286 ;
if ( V_287 > 1 ) {
unsigned int V_279 = F_164 ( V_19 , V_50 ) ;
V_20 = F_16 ( V_19 , V_50 ) ;
V_20 &= ~ ( V_283 | V_220 ) ;
V_20 |= F_165 ( V_279 , V_58 ) | V_260 ;
} else
V_20 = F_150 ( V_19 , V_50 ) ;
}
F_151 ( V_19 , V_50 , V_20 ) ;
F_134 ( V_19 , NULL ) ;
return 1 ;
}
static int F_163 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
if ( F_161 ( V_19 , V_46 ) <= 1 &&
F_171 ( V_19 , V_46 ) <= 1 )
return 0 ;
V_12 = F_4 ( V_2 , L_61 ,
& V_290 ) ;
if ( ! V_12 )
return - V_122 ;
V_12 -> V_119 = V_46 ;
V_2 -> V_265 = 1 ;
return 0 ;
}
static int F_177 ( struct V_1 * V_2 , T_1 V_291 , int V_58 )
{
struct V_8 * V_14 ;
V_14 = F_5 ( & V_2 -> V_7 ) ;
if ( ! V_14 )
return - V_122 ;
V_14 -> V_50 = V_291 ;
V_14 -> V_61 = V_83 ;
V_14 -> V_58 = V_58 ;
V_2 -> V_292 . V_293 = V_2 -> V_7 . V_14 ;
return 0 ;
}
static int F_178 ( struct V_18 * V_19 , int V_294 ,
T_1 V_46 , const char * V_295 , int V_296 ,
T_1 V_297 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_52 ;
unsigned int V_20 ;
int V_191 , V_58 ;
if ( ! F_52 ( V_19 , V_297 , V_83 ) &&
! F_50 ( V_19 , V_297 , V_83 ) )
return 0 ;
V_52 = F_42 ( V_19 , V_46 , V_297 , 0 ) ;
if ( ! V_52 )
return - V_242 ;
F_34 ( L_62 , V_52 ) ;
V_2 -> V_196 [ V_294 ] = F_26 ( V_19 , V_52 ) ;
V_58 = V_52 -> V_58 [ V_52 -> V_53 - 1 ] ;
if ( F_52 ( V_19 , V_297 , V_83 ) ) {
V_20 = F_33 ( V_297 , 3 , V_58 , V_83 ) ;
V_191 = F_80 ( V_2 , V_123 , V_295 , V_296 , V_20 ) ;
if ( V_191 < 0 )
return V_191 ;
V_52 -> V_60 [ V_98 ] = V_20 ;
}
if ( F_50 ( V_19 , V_297 , V_83 ) ) {
V_20 = F_33 ( V_297 , 3 , V_58 , V_83 ) ;
V_191 = F_86 ( V_2 , V_125 , V_295 , V_296 , V_20 ) ;
if ( V_191 < 0 )
return V_191 ;
V_52 -> V_60 [ V_97 ] = V_20 ;
}
V_52 -> V_88 = true ;
V_191 = F_177 ( V_2 , V_297 , V_58 ) ;
if ( V_191 < 0 )
return V_191 ;
if ( V_2 -> V_45 != V_2 -> V_102 &&
! V_2 -> V_298 ) {
V_52 = F_42 ( V_19 , V_2 -> V_45 ,
V_2 -> V_102 , 0 ) ;
if ( V_52 ) {
F_34 ( L_63 , V_52 ) ;
V_52 -> V_88 = true ;
V_2 -> V_298 =
F_26 ( V_19 , V_52 ) ;
}
}
return 0 ;
}
static int F_179 ( struct V_18 * V_19 , T_1 V_50 )
{
unsigned int V_272 = F_73 ( V_19 , V_50 ) ;
return ( V_272 & V_268 ) != 0 ;
}
static int F_180 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_50 ;
T_1 * V_299 = V_2 -> V_299 ;
int V_300 = F_97 ( V_2 -> V_299 ) ;
int V_16 , V_51 = 0 ;
V_50 = V_19 -> V_208 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_209 ; V_16 ++ , V_50 ++ ) {
unsigned int V_84 = F_40 ( V_19 , V_50 ) ;
int type = F_39 ( V_84 ) ;
if ( type != V_69 || ( V_84 & V_77 ) )
continue;
V_299 [ V_51 ] = V_50 ;
if ( ++ V_51 >= V_300 )
break;
}
V_2 -> V_301 = V_51 ;
V_2 -> V_302 = V_51 ;
memcpy ( V_2 -> V_303 , V_2 -> V_299 , V_51 * sizeof( T_1 ) ) ;
return V_51 ;
}
static int F_181 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_304 * V_305 = & V_2 -> V_306 ;
unsigned int V_307 ;
int V_16 , V_87 , V_51 ;
V_51 = 0 ;
V_307 = 0 ;
for ( V_87 = 0 ; V_87 < V_2 -> V_301 ; V_87 ++ ) {
for ( V_16 = 0 ; V_16 < V_305 -> V_308 ; V_16 ++ ) {
if ( ! V_2 -> V_195 [ V_16 ] [ V_87 ] )
break;
}
if ( V_16 >= V_305 -> V_308 ) {
V_307 |= ( 1 << V_87 ) ;
V_51 ++ ;
}
}
if ( ! V_307 ) {
for ( V_16 = 0 ; V_16 < V_305 -> V_308 ; V_16 ++ ) {
for ( V_87 = 0 ; V_87 < V_2 -> V_301 ; V_87 ++ ) {
if ( V_2 -> V_195 [ V_16 ] [ V_87 ] ) {
V_2 -> V_309 [ V_16 ] = V_87 ;
break;
}
}
}
F_36 ( L_64 ) ;
V_2 -> V_310 = 1 ;
} else if ( V_51 != V_2 -> V_301 ) {
V_51 = 0 ;
for ( V_87 = 0 ; V_87 < V_2 -> V_301 ; V_87 ++ ) {
if ( ! ( V_307 & ( 1 << V_87 ) ) )
continue;
if ( V_87 != V_51 ) {
V_2 -> V_299 [ V_51 ] = V_2 -> V_299 [ V_87 ] ;
for ( V_16 = 0 ; V_16 < V_305 -> V_308 ; V_16 ++ ) {
F_43 ( V_19 ,
V_2 -> V_195 [ V_16 ] [ V_51 ] ) ;
V_2 -> V_195 [ V_16 ] [ V_51 ] =
V_2 -> V_195 [ V_16 ] [ V_87 ] ;
}
}
V_51 ++ ;
}
V_2 -> V_301 = V_51 ;
}
if ( V_305 -> V_308 == 1 ||
( V_305 -> V_308 == 2 && V_2 -> V_43 ) ) {
F_36 ( L_65 ) ;
V_2 -> V_301 = 1 ;
}
if ( ! V_2 -> V_310 && V_2 -> V_37 )
V_2 -> V_301 = 1 ;
return 0 ;
}
static int F_182 ( struct V_18 * V_19 , T_1 V_46 ,
int V_311 , int V_312 ,
const char * V_313 , int V_314 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_304 * V_305 = & V_2 -> V_306 ;
int V_315 = V_305 -> V_308 ;
bool V_316 = false ;
int V_317 ;
for ( V_317 = 0 ; V_317 < V_312 ; V_317 ++ ) {
struct V_6 * V_52 ;
T_1 V_318 = V_2 -> V_299 [ V_317 ] ;
if ( ! F_29 ( V_19 , V_46 , V_318 ) )
continue;
V_52 = F_42 ( V_19 , V_46 , V_318 , V_314 ) ;
if ( ! V_52 )
continue;
F_34 ( L_66 , V_52 ) ;
V_2 -> V_195 [ V_315 ] [ V_317 ] =
F_26 ( V_19 , V_52 ) ;
if ( ! V_316 ) {
if ( V_2 -> V_257 == V_46 )
V_2 -> V_259 = V_305 -> V_308 ;
V_2 -> V_319 [ V_305 -> V_308 ] = V_46 ;
F_183 ( V_305 , V_313 , V_311 , NULL ) ;
V_316 = true ;
}
}
return 0 ;
}
static int F_184 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_136 * V_137 = & V_2 -> V_138 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_137 -> V_180 ; V_16 ++ ) {
T_1 V_46 = V_137 -> V_181 [ V_16 ] . V_46 ;
const char * V_313 ;
int V_165 , V_58 ;
if ( ! F_179 ( V_19 , V_46 ) )
continue;
V_313 = F_185 ( V_19 , V_137 , V_16 ) ;
V_58 = 0 ;
for ( V_165 = V_16 - 1 ; V_165 >= 0 ; V_165 -- ) {
if ( V_2 -> V_320 [ V_165 ] &&
! strcmp ( V_2 -> V_320 [ V_165 ] , V_313 ) ) {
V_58 = V_2 -> V_321 [ V_165 ] + 1 ;
break;
}
}
V_2 -> V_320 [ V_16 ] = V_313 ;
V_2 -> V_321 [ V_16 ] = V_58 ;
}
return 0 ;
}
static int F_186 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_136 * V_137 = & V_2 -> V_138 ;
T_1 V_322 = V_2 -> V_45 ;
int V_312 ;
int V_16 , V_191 ;
unsigned int V_20 ;
V_312 = F_180 ( V_19 ) ;
if ( V_312 < 0 )
return 0 ;
V_191 = F_184 ( V_19 ) ;
if ( V_191 < 0 )
return V_191 ;
for ( V_16 = 0 ; V_16 < V_137 -> V_180 ; V_16 ++ ) {
T_1 V_46 ;
V_46 = V_137 -> V_181 [ V_16 ] . V_46 ;
if ( ! F_179 ( V_19 , V_46 ) )
continue;
V_20 = V_260 ;
if ( V_137 -> V_181 [ V_16 ] . type == V_179 )
V_20 |= F_150 ( V_19 , V_46 ) ;
if ( V_46 != V_2 -> V_257 )
F_17 ( V_19 , V_46 , V_20 , false ) ;
if ( V_322 ) {
if ( F_29 ( V_19 , V_46 , V_322 ) ) {
V_191 = F_178 ( V_19 , V_16 , V_46 ,
V_2 -> V_320 [ V_16 ] ,
V_2 -> V_321 [ V_16 ] ,
V_322 ) ;
if ( V_191 < 0 )
return V_191 ;
}
}
V_191 = F_182 ( V_19 , V_46 , V_16 , V_312 ,
V_2 -> V_320 [ V_16 ] , - V_322 ) ;
if ( V_191 < 0 )
return V_191 ;
if ( V_2 -> V_41 ) {
V_191 = F_172 ( V_19 , V_46 ) ;
if ( V_191 < 0 )
return V_191 ;
}
}
if ( V_322 && V_2 -> V_40 ) {
V_191 = F_182 ( V_19 , V_322 , V_323 , V_312 ,
L_67 , 0 ) ;
if ( V_191 < 0 )
return V_191 ;
}
return 0 ;
}
static struct V_6 * F_187 ( struct V_18 * V_19 , int V_324 , int V_315 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_315 < 0 || V_315 >= V_325 ) {
F_98 () ;
return NULL ;
}
if ( V_2 -> V_310 )
V_324 = V_2 -> V_309 [ V_315 ] ;
if ( V_324 < 0 || V_324 >= V_267 ) {
F_98 () ;
return NULL ;
}
return F_27 ( V_19 , V_2 -> V_195 [ V_315 ] [ V_324 ] ) ;
}
static int F_188 ( struct V_127 * V_128 ,
struct V_223 * V_224 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
return F_189 ( & V_2 -> V_306 , V_224 ) ;
}
static int F_190 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_324 = F_191 ( V_128 , & V_130 -> V_326 ) ;
V_130 -> V_133 . V_225 . V_226 [ 0 ] = V_2 -> V_258 [ V_324 ] ;
return 0 ;
}
static int F_192 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
unsigned int V_324 = F_191 ( V_128 , & V_130 -> V_326 ) ;
return F_193 ( V_19 , V_324 ,
V_130 -> V_133 . V_225 . V_226 [ 0 ] ) ;
}
static int F_194 ( struct V_127 * V_128 ,
struct V_129 * V_130 ,
T_4 V_327 , int type )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_304 * V_305 ;
struct V_6 * V_52 ;
int V_16 , V_324 , V_191 = 0 ;
V_305 = & V_2 -> V_306 ;
V_324 = V_128 -> V_326 . V_116 ;
F_132 ( & V_19 -> V_328 ) ;
V_19 -> V_329 = 1 ;
for ( V_16 = 0 ; V_16 < V_305 -> V_308 ; V_16 ++ ) {
V_52 = F_187 ( V_19 , V_324 , V_16 ) ;
if ( ! V_52 || ! V_52 -> V_60 [ type ] )
continue;
V_128 -> V_119 = V_52 -> V_60 [ type ] ;
V_191 = V_327 ( V_128 , V_130 ) ;
if ( V_191 < 0 )
goto error;
}
error:
V_19 -> V_329 = 0 ;
F_135 ( & V_19 -> V_328 ) ;
F_195 ( V_19 ) ;
if ( V_191 >= 0 && V_2 -> V_330 )
V_2 -> V_330 ( V_19 , V_130 ) ;
return V_191 ;
}
static int F_196 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
return F_194 ( V_128 , V_130 ,
V_331 ,
V_98 ) ;
}
static int F_197 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
return F_194 ( V_128 , V_130 ,
F_92 ,
V_97 ) ;
}
static int F_198 ( struct V_18 * V_19 , struct V_6 * V_52 )
{
T_1 V_50 ;
int V_16 , V_53 ;
V_52 -> V_60 [ V_98 ] = V_52 -> V_60 [ V_97 ] = 0 ;
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
if ( V_53 >= V_52 -> V_53 )
return - V_242 ;
V_16 = V_52 -> V_53 - V_53 - 1 ;
V_50 = V_52 -> V_52 [ V_16 ] ;
if ( ! V_52 -> V_60 [ V_98 ] ) {
if ( F_52 ( V_19 , V_50 , V_82 ) )
V_52 -> V_60 [ V_98 ] =
F_33 ( V_50 , 3 , 0 , V_82 ) ;
else if ( F_52 ( V_19 , V_50 , V_83 ) ) {
int V_58 = V_52 -> V_58 [ V_16 ] ;
if ( ! V_53 && V_19 -> V_29 )
V_58 = 0 ;
V_52 -> V_60 [ V_98 ] =
F_33 ( V_50 , 3 , V_58 , V_83 ) ;
}
}
if ( ! V_52 -> V_60 [ V_97 ] ) {
if ( F_50 ( V_19 , V_50 , V_82 ) )
V_52 -> V_60 [ V_97 ] =
F_33 ( V_50 , 3 , 0 , V_82 ) ;
else if ( F_50 ( V_19 , V_50 , V_83 ) ) {
int V_58 = V_52 -> V_58 [ V_16 ] ;
if ( ! V_53 && V_19 -> V_29 )
V_58 = 0 ;
V_52 -> V_60 [ V_97 ] =
F_33 ( V_50 , 3 , V_58 , V_83 ) ;
}
}
}
return 0 ;
}
static bool F_199 ( struct V_18 * V_19 , T_1 V_50 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_136 * V_137 = & V_2 -> V_138 ;
unsigned int V_20 ;
int V_16 ;
if ( ! V_2 -> V_38 )
return false ;
for ( V_16 = 0 ; V_16 < V_137 -> V_180 ; V_16 ++ ) {
if ( V_137 -> V_181 [ V_16 ] . V_46 != V_50 )
continue;
if ( V_137 -> V_181 [ V_16 ] . type != V_179 )
return false ;
V_20 = F_105 ( V_19 , V_50 ) ;
return F_153 ( V_20 ) == V_266 ;
}
return false ;
}
static int F_200 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_229 ;
V_229 = F_92 ( V_128 , V_130 ) ;
if ( V_229 < 0 )
return V_229 ;
if ( V_2 -> V_330 )
V_2 -> V_330 ( V_19 , V_130 ) ;
return V_229 ;
}
static int F_201 ( struct V_18 * V_19 , const char * V_313 ,
int V_58 , bool V_332 , unsigned int V_333 ,
bool V_334 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
char V_335 [ V_121 ] ;
int type = V_332 ? V_125 : V_123 ;
const char * V_120 = V_332 ? L_68 : L_69 ;
unsigned int V_78 = V_334 ? 1 : 3 ;
struct V_4 * V_12 ;
if ( ! V_333 )
return 0 ;
if ( V_313 )
snprintf ( V_335 , sizeof( V_335 ) ,
L_70 , V_313 , V_120 ) ;
else
snprintf ( V_335 , sizeof( V_335 ) ,
L_71 , V_120 ) ;
V_12 = F_76 ( V_2 , type , V_335 , V_58 ,
F_45 ( V_333 , V_78 ) ) ;
if ( ! V_12 )
return - V_122 ;
if ( V_332 )
V_12 -> V_336 = F_200 ;
if ( ! V_334 )
return 0 ;
if ( V_313 )
snprintf ( V_335 , sizeof( V_335 ) ,
L_72 , V_313 , V_120 ) ;
else
snprintf ( V_335 , sizeof( V_335 ) ,
L_73 , V_120 ) ;
V_12 = F_76 ( V_2 , type , V_335 , V_58 ,
F_45 ( V_333 , 2 ) ) ;
if ( ! V_12 )
return - V_122 ;
if ( V_332 )
V_12 -> V_336 = F_200 ;
return 0 ;
}
static int F_202 ( struct V_18 * V_19 , int V_58 ,
unsigned int V_337 , unsigned int V_338 ,
bool V_334 )
{
int V_191 ;
V_191 = F_201 ( V_19 , NULL , V_58 , false , V_337 , V_334 ) ;
if ( V_191 < 0 )
return V_191 ;
V_191 = F_201 ( V_19 , NULL , V_58 , true , V_338 , V_334 ) ;
if ( V_191 < 0 )
return V_191 ;
return 0 ;
}
static int F_203 ( struct V_18 * V_19 , int V_58 ,
unsigned int V_337 , unsigned int V_338 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
if ( V_337 ) {
V_12 = F_4 ( V_2 , NULL , & V_339 ) ;
if ( ! V_12 )
return - V_122 ;
V_12 -> V_116 = V_58 ;
V_12 -> V_119 = V_337 ;
V_12 -> V_117 = V_118 ;
}
if ( V_338 ) {
V_12 = F_4 ( V_2 , NULL , & V_340 ) ;
if ( ! V_12 )
return - V_122 ;
V_12 -> V_116 = V_58 ;
V_12 -> V_119 = V_338 ;
V_12 -> V_117 = V_118 ;
}
return 0 ;
}
static unsigned int F_204 ( struct V_18 * V_19 , int V_58 , int type )
{
struct V_6 * V_52 ;
unsigned int V_333 ;
int V_16 ;
V_52 = F_187 ( V_19 , 0 , V_58 ) ;
if ( ! V_52 )
return 0 ;
V_333 = V_52 -> V_60 [ type ] ;
if ( ! V_333 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_58 - 1 ; V_16 ++ ) {
V_52 = F_187 ( V_19 , 0 , V_16 ) ;
if ( V_52 && V_52 -> V_60 [ type ] == V_333 )
return 0 ;
}
return V_333 ;
}
static int F_205 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_304 * V_305 = & V_2 -> V_306 ;
int V_16 , V_191 , type ;
for ( V_16 = 0 ; V_16 < V_305 -> V_308 ; V_16 ++ ) {
bool V_334 ;
int V_58 ;
V_58 = V_305 -> V_240 [ V_16 ] . V_116 ;
if ( V_58 >= V_2 -> V_138 . V_180 )
continue;
V_334 = F_199 ( V_19 , V_2 -> V_319 [ V_16 ] ) ;
for ( type = 0 ; type < 2 ; type ++ ) {
V_191 = F_201 ( V_19 ,
V_2 -> V_320 [ V_58 ] ,
V_2 -> V_321 [ V_58 ] ,
type ,
F_204 ( V_19 , V_16 , type ) ,
V_334 ) ;
if ( V_191 < 0 )
return V_191 ;
}
}
return 0 ;
}
static int F_206 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_304 * V_305 = & V_2 -> V_306 ;
int V_16 , V_87 , V_51 , V_191 ;
if ( V_2 -> V_310 )
V_51 = 1 ;
else
V_51 = V_2 -> V_301 ;
if ( ! V_2 -> V_341 && V_305 -> V_308 > 1 ) {
struct V_4 * V_12 ;
const char * V_10 ;
V_10 = V_51 > 1 ? L_74 : L_75 ;
V_12 = F_4 ( V_2 , V_10 , & V_342 ) ;
if ( ! V_12 )
return - V_122 ;
V_12 -> V_239 = V_51 ;
}
for ( V_87 = 0 ; V_87 < V_51 ; V_87 ++ ) {
bool V_72 = false ;
bool V_37 = V_2 -> V_37 ;
bool V_334 = false ;
int V_343 , V_344 ;
V_343 = V_344 = 0 ;
for ( V_16 = 0 ; V_16 < V_305 -> V_308 ; V_16 ++ ) {
struct V_6 * V_52 ;
V_52 = F_187 ( V_19 , V_87 , V_16 ) ;
if ( ! V_52 )
continue;
F_198 ( V_19 , V_52 ) ;
if ( ! V_343 )
V_343 = V_52 -> V_60 [ V_98 ] ;
else if ( V_343 != V_52 -> V_60 [ V_98 ] ) {
V_72 = true ;
if ( ! F_48 ( V_19 , V_343 ,
V_52 -> V_60 [ V_98 ] , V_83 ) )
V_37 = true ;
}
if ( ! V_344 )
V_344 = V_52 -> V_60 [ V_97 ] ;
else if ( V_344 != V_52 -> V_60 [ V_97 ] ) {
V_72 = true ;
if ( ! F_48 ( V_19 , V_344 ,
V_52 -> V_60 [ V_97 ] , V_83 ) )
V_37 = true ;
}
if ( F_199 ( V_19 , V_2 -> V_319 [ V_16 ] ) )
V_334 = true ;
}
if ( ! V_72 )
V_191 = F_202 ( V_19 , V_87 , V_343 , V_344 ,
V_334 ) ;
else if ( ! V_37 && ! V_334 )
V_191 = F_203 ( V_19 , V_87 , V_343 , V_344 ) ;
else
V_191 = F_205 ( V_19 ) ;
if ( V_191 < 0 )
return V_191 ;
}
return 0 ;
}
static bool F_207 ( struct V_18 * V_19 , T_1 V_50 ,
int V_61 , int V_58 )
{
unsigned int V_345 ;
if ( ! F_52 ( V_19 , V_50 , V_61 ) ||
F_32 ( V_19 , V_50 , V_61 , V_58 , V_98 ) ||
F_32 ( V_19 , V_50 , V_61 , V_58 , V_99 ) )
return false ;
V_345 = ( F_47 ( V_19 , V_50 , V_61 ) & V_346 )
>> V_347 ;
if ( V_345 < 0x20 )
return false ;
return true ;
}
static unsigned int F_208 ( struct V_18 * V_19 ,
struct V_6 * V_52 )
{
unsigned int V_20 = 0 ;
T_1 V_50 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
if ( V_53 >= V_52 -> V_53 - 1 )
break;
V_50 = V_52 -> V_52 [ V_53 ] ;
if ( V_53 && F_207 ( V_19 , V_50 , V_82 , 0 ) ) {
V_20 = F_33 ( V_50 , 3 , 0 , V_82 ) ;
break;
} else if ( F_207 ( V_19 , V_50 , V_83 ,
V_52 -> V_58 [ V_53 ] ) ) {
V_20 = F_33 ( V_50 , 3 , V_52 -> V_58 [ V_53 ] ,
V_83 ) ;
break;
}
}
return V_20 ;
}
static int F_209 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_136 * V_137 = & V_2 -> V_138 ;
struct V_304 * V_305 = & V_2 -> V_306 ;
int V_16 ;
if ( ! V_2 -> V_301 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_305 -> V_308 ; V_16 ++ ) {
struct V_6 * V_52 ;
unsigned int V_20 ;
int V_58 ;
char V_348 [ V_121 ] ;
V_58 = V_305 -> V_240 [ V_16 ] . V_116 ;
if ( V_58 >= V_305 -> V_308 )
continue;
if ( V_137 -> V_181 [ V_58 ] . type > V_178 )
continue;
V_52 = F_187 ( V_19 , 0 , V_16 ) ;
if ( ! V_52 )
continue;
V_20 = F_208 ( V_19 , V_52 ) ;
if ( ! V_20 )
continue;
snprintf ( V_348 , sizeof( V_348 ) ,
L_76 , V_2 -> V_320 [ V_58 ] ) ;
if ( ! F_76 ( V_2 , V_123 , V_348 ,
V_2 -> V_321 [ V_58 ] , V_20 ) )
return - V_122 ;
V_52 -> V_60 [ V_99 ] = V_20 ;
}
return 0 ;
}
static void F_210 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_52 ;
int V_16 , V_51 ;
T_1 V_349 , V_46 ;
V_51 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_138 . V_350 ; V_16 ++ ) {
V_46 = V_2 -> V_138 . V_351 [ V_16 ] ;
V_349 = F_44 ( V_19 , V_46 , true ) ;
if ( ! V_349 )
continue;
V_52 = F_42 ( V_19 , V_349 , V_46 , 0 ) ;
if ( ! V_52 )
continue;
F_34 ( L_77 , V_52 ) ;
V_52 -> V_88 = true ;
V_2 -> V_194 [ V_16 ] = F_26 ( V_19 , V_52 ) ;
F_17 ( V_19 , V_46 , V_221 , false ) ;
if ( ! V_51 ) {
V_2 -> V_145 . V_352 = V_349 ;
V_2 -> V_353 = V_2 -> V_138 . V_353 [ 0 ] ;
} else {
V_2 -> V_145 . V_354 = V_2 -> V_354 ;
if ( V_51 >= F_97 ( V_2 -> V_354 ) - 1 )
break;
V_2 -> V_354 [ V_51 - 1 ] = V_349 ;
}
V_51 ++ ;
}
if ( V_2 -> V_138 . V_355 ) {
V_46 = V_2 -> V_138 . V_355 ;
V_349 = V_19 -> V_208 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_209 ; V_16 ++ , V_349 ++ ) {
unsigned int V_356 = F_40 ( V_19 , V_349 ) ;
if ( F_39 ( V_356 ) != V_69 )
continue;
if ( ! ( V_356 & V_77 ) )
continue;
V_52 = F_42 ( V_19 , V_46 , V_349 , 0 ) ;
if ( V_52 ) {
F_34 ( L_78 , V_52 ) ;
V_52 -> V_88 = true ;
V_2 -> V_357 = V_349 ;
V_2 -> V_197 = F_26 ( V_19 , V_52 ) ;
F_17 ( V_19 , V_46 , V_260 , false ) ;
break;
}
}
}
}
static int F_193 ( struct V_18 * V_19 , unsigned int V_324 ,
unsigned int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_304 * V_305 ;
struct V_6 * V_358 , * V_52 ;
V_305 = & V_2 -> V_306 ;
if ( ! V_305 -> V_308 )
return 0 ;
if ( V_58 >= V_305 -> V_308 )
V_58 = V_305 -> V_308 - 1 ;
if ( V_2 -> V_258 [ V_324 ] == V_58 )
return 0 ;
V_358 = F_187 ( V_19 , V_324 , V_2 -> V_258 [ V_324 ] ) ;
if ( ! V_358 )
return 0 ;
if ( V_358 -> V_88 )
F_64 ( V_19 , V_358 , false , false ) ;
V_2 -> V_258 [ V_324 ] = V_58 ;
if ( V_2 -> V_43 )
F_149 ( V_19 , V_324 , false ) ;
if ( V_2 -> V_310 )
F_211 ( V_19 , V_58 ) ;
V_52 = F_187 ( V_19 , V_324 , V_58 ) ;
if ( ! V_52 )
return 0 ;
if ( V_52 -> V_88 )
return 0 ;
F_64 ( V_19 , V_52 , true , false ) ;
if ( V_2 -> V_330 )
V_2 -> V_330 ( V_19 , NULL ) ;
F_68 ( V_19 , V_358 ) ;
return 1 ;
}
static bool F_212 ( struct V_18 * V_19 , int V_48 , T_1 * V_49 )
{
int V_16 ;
bool V_359 = false ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
T_1 V_50 = V_49 [ V_16 ] ;
if ( ! V_50 )
break;
if ( F_16 ( V_19 , V_50 ) & V_360 )
continue;
if ( F_213 ( V_19 , V_50 ) == V_361 )
V_359 = true ;
}
return V_359 ;
}
static void F_214 ( struct V_18 * V_19 , int V_48 , T_1 * V_49 ,
int * V_5 , bool V_362 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
T_1 V_50 = V_49 [ V_16 ] ;
unsigned int V_20 , V_289 ;
if ( ! V_50 )
break;
if ( V_2 -> V_33 ) {
struct V_6 * V_52 ;
T_1 V_363 ;
V_52 = F_27 ( V_19 , V_5 [ V_16 ] ) ;
if ( ! V_52 )
continue;
V_363 = F_77 ( V_52 -> V_60 [ V_97 ] ) ;
if ( ! V_363 )
continue;
if ( V_362 )
V_2 -> V_132 |= ( 1ULL << V_363 ) ;
else
V_2 -> V_132 &= ~ ( 1ULL << V_363 ) ;
F_72 ( V_19 , V_50 , ! V_362 ) ;
continue;
}
V_289 = F_16 ( V_19 , V_50 ) ;
if ( V_289 & V_260 )
continue;
if ( V_2 -> V_364 )
V_20 = V_289 & ~ V_220 ;
else
V_20 = 0 ;
if ( ! V_362 )
V_20 |= V_289 ;
F_15 ( V_19 , V_50 , V_20 ) ;
F_72 ( V_19 , V_50 , ! V_362 ) ;
}
}
void F_215 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int * V_5 ;
int V_365 ;
if ( V_2 -> V_138 . V_150 == V_153 )
V_5 = V_2 -> V_185 ;
else
V_5 = V_2 -> V_152 ;
F_214 ( V_19 , F_97 ( V_2 -> V_138 . V_200 ) ,
V_2 -> V_138 . V_200 , V_5 , V_2 -> V_366 ) ;
if ( ! V_2 -> V_367 )
V_365 = 0 ;
else
V_365 = V_2 -> V_368 | V_2 -> V_369 ;
V_365 |= V_2 -> V_366 ;
V_2 -> V_370 = V_365 ;
if ( V_2 -> V_138 . V_150 == V_151 )
V_5 = V_2 -> V_185 ;
else
V_5 = V_2 -> V_154 ;
F_214 ( V_19 , F_97 ( V_2 -> V_138 . V_201 ) ,
V_2 -> V_138 . V_201 , V_5 , V_365 ) ;
if ( V_2 -> V_138 . V_199 [ 0 ] == V_2 -> V_138 . V_200 [ 0 ] ||
V_2 -> V_138 . V_199 [ 0 ] == V_2 -> V_138 . V_201 [ 0 ] )
return;
if ( ! V_2 -> V_371 )
V_365 = 0 ;
else
V_365 = V_2 -> V_368 ;
V_365 |= V_2 -> V_366 ;
V_2 -> V_372 = V_365 ;
V_5 = V_2 -> V_185 ;
F_214 ( V_19 , F_97 ( V_2 -> V_138 . V_199 ) ,
V_2 -> V_138 . V_199 , V_5 , V_365 ) ;
}
static void F_216 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_373 )
V_2 -> V_373 ( V_19 ) ;
else
F_215 ( V_19 ) ;
if ( V_2 -> V_33 && ! V_19 -> V_374 -> V_375 )
F_217 ( V_2 -> V_143 . V_376 , false ) ;
}
void F_218 ( struct V_18 * V_19 , struct V_377 * V_378 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 * V_49 = V_2 -> V_138 . V_200 ;
int V_48 = F_97 ( V_2 -> V_138 . V_200 ) ;
if ( V_2 -> V_227 ) {
V_49 ++ ;
V_48 -- ;
}
V_2 -> V_368 = F_212 ( V_19 , V_48 , V_49 ) ;
if ( ! V_2 -> V_379 || ( ! V_2 -> V_367 && ! V_2 -> V_371 ) )
return;
F_216 ( V_19 ) ;
}
void F_219 ( struct V_18 * V_19 , struct V_377 * V_378 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_138 . V_150 == V_151 )
return;
if ( V_2 -> V_138 . V_199 [ 0 ] == V_2 -> V_138 . V_200 [ 0 ] )
return;
V_2 -> V_369 =
F_212 ( V_19 , F_97 ( V_2 -> V_138 . V_199 ) ,
V_2 -> V_138 . V_199 ) ;
if ( ! V_2 -> V_367 || ! V_2 -> V_380 )
return;
F_216 ( V_19 ) ;
}
void F_220 ( struct V_18 * V_19 , struct V_377 * V_378 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
if ( ! V_2 -> V_341 )
return;
for ( V_16 = V_2 -> V_381 - 1 ; V_16 > 0 ; V_16 -- ) {
T_1 V_46 = V_2 -> V_382 [ V_16 ] . V_46 ;
if ( F_16 ( V_19 , V_46 ) & V_383 )
continue;
if ( F_213 ( V_19 , V_46 ) == V_361 ) {
F_193 ( V_19 , 0 , V_2 -> V_382 [ V_16 ] . V_58 ) ;
return;
}
}
F_193 ( V_19 , 0 , V_2 -> V_382 [ 0 ] . V_58 ) ;
}
static void F_134 ( struct V_18 * V_19 , struct V_377 * V_378 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_384 )
V_2 -> V_384 ( V_19 , V_378 ) ;
else
F_218 ( V_19 , V_378 ) ;
}
static void F_221 ( struct V_18 * V_19 ,
struct V_377 * V_378 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_385 )
V_2 -> V_385 ( V_19 , V_378 ) ;
else
F_219 ( V_19 , V_378 ) ;
}
static void F_222 ( struct V_18 * V_19 ,
struct V_377 * V_378 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_386 )
V_2 -> V_386 ( V_19 , V_378 ) ;
else
F_220 ( V_19 , V_378 ) ;
}
static void F_142 ( struct V_18 * V_19 )
{
F_134 ( V_19 , NULL ) ;
F_221 ( V_19 , NULL ) ;
F_222 ( V_19 , NULL ) ;
}
static int F_223 ( struct V_127 * V_128 ,
struct V_223 * V_224 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_387 [] = {
L_79 , L_80 , L_81
} ;
if ( V_2 -> V_388 && V_2 -> V_389 )
return F_155 ( V_128 , V_224 , 3 , V_387 ) ;
return F_129 ( V_128 , V_224 ) ;
}
static int F_224 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = 0 ;
if ( V_2 -> V_367 )
V_20 ++ ;
if ( V_2 -> V_371 )
V_20 ++ ;
V_130 -> V_133 . V_225 . V_226 [ 0 ] = V_20 ;
return 0 ;
}
static int F_225 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_18 * V_19 = F_89 ( V_128 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
switch ( V_130 -> V_133 . V_225 . V_226 [ 0 ] ) {
case 0 :
if ( ! V_2 -> V_367 && ! V_2 -> V_371 )
return 0 ;
V_2 -> V_367 = 0 ;
V_2 -> V_371 = 0 ;
break;
case 1 :
if ( V_2 -> V_388 ) {
if ( ! V_2 -> V_371 && V_2 -> V_367 )
return 0 ;
V_2 -> V_367 = 1 ;
V_2 -> V_371 = 0 ;
} else if ( V_2 -> V_389 ) {
if ( V_2 -> V_371 )
return 0 ;
V_2 -> V_371 = 1 ;
} else
return - V_242 ;
break;
case 2 :
if ( ! V_2 -> V_389 || ! V_2 -> V_388 )
return - V_242 ;
if ( V_2 -> V_367 && V_2 -> V_371 )
return 0 ;
V_2 -> V_367 = 1 ;
V_2 -> V_371 = 1 ;
break;
default:
return - V_242 ;
}
F_216 ( V_19 ) ;
return 1 ;
}
static int F_226 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! F_4 ( V_2 , NULL , & V_390 ) )
return - V_122 ;
return 0 ;
}
static int F_227 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_136 * V_137 = & V_2 -> V_138 ;
int V_359 = 0 ;
int V_16 , V_191 ;
if ( V_2 -> V_30 )
return 0 ;
if ( V_137 -> V_200 [ 0 ] )
V_359 ++ ;
if ( V_137 -> V_199 [ 0 ] )
V_359 ++ ;
if ( V_137 -> V_201 [ 0 ] )
V_359 ++ ;
if ( V_359 < 2 )
return 0 ;
if ( ! V_137 -> V_201 [ 0 ] &&
V_137 -> V_150 == V_151 ) {
memcpy ( V_137 -> V_201 , V_137 -> V_199 ,
sizeof( V_137 -> V_201 ) ) ;
V_137 -> V_142 = V_137 -> V_139 ;
}
if ( ! V_137 -> V_200 [ 0 ] &&
V_137 -> V_150 == V_153 ) {
memcpy ( V_137 -> V_200 , V_137 -> V_199 ,
sizeof( V_137 -> V_200 ) ) ;
V_137 -> V_141 = V_137 -> V_139 ;
}
for ( V_16 = 0 ; V_16 < V_137 -> V_141 ; V_16 ++ ) {
T_1 V_50 = V_137 -> V_200 [ V_16 ] ;
if ( ! F_228 ( V_19 , V_50 ) )
continue;
F_36 ( L_82 ,
V_50 ) ;
F_229 ( V_19 , V_50 , V_391 ,
F_134 ) ;
V_2 -> V_379 = 1 ;
}
if ( V_137 -> V_150 == V_392 && V_137 -> V_139 ) {
if ( V_137 -> V_142 )
for ( V_16 = 0 ; V_16 < V_137 -> V_139 ; V_16 ++ ) {
T_1 V_50 = V_137 -> V_199 [ V_16 ] ;
if ( ! F_228 ( V_19 , V_50 ) )
continue;
F_36 ( L_83 , V_50 ) ;
F_229 ( V_19 , V_50 ,
V_393 ,
F_221 ) ;
V_2 -> V_380 = 1 ;
}
V_2 -> V_389 = V_2 -> V_379 ;
}
V_2 -> V_388 = V_137 -> V_142 &&
( V_2 -> V_379 || V_2 -> V_380 ) ;
V_2 -> V_371 = V_2 -> V_389 ;
V_2 -> V_367 = V_2 -> V_388 ;
if ( V_2 -> V_388 || V_2 -> V_389 ) {
V_191 = F_226 ( V_19 ) ;
if ( V_191 < 0 )
return V_191 ;
}
return 0 ;
}
static bool F_230 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_304 * V_305 ;
int V_16 ;
V_305 = & V_2 -> V_306 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_381 ; V_16 ++ ) {
V_2 -> V_382 [ V_16 ] . V_58 =
F_21 ( V_2 -> V_382 [ V_16 ] . V_46 ,
V_2 -> V_319 , V_305 -> V_308 ) ;
if ( V_2 -> V_382 [ V_16 ] . V_58 < 0 )
return false ;
}
for ( V_16 = 1 ; V_16 < V_2 -> V_381 ; V_16 ++ )
F_229 ( V_19 ,
V_2 -> V_382 [ V_16 ] . V_46 ,
V_394 ,
F_222 ) ;
return true ;
}
static int F_231 ( const void * V_395 , const void * V_396 )
{
const struct V_397 * V_398 = V_395 ;
const struct V_397 * V_399 = V_396 ;
return ( int ) ( V_398 -> V_400 - V_399 -> V_400 ) ;
}
static int F_232 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_136 * V_137 = & V_2 -> V_138 ;
unsigned int V_401 ;
int V_16 , V_48 ;
if ( V_2 -> V_31 )
return 0 ;
V_401 = 0 ;
V_48 = 0 ;
for ( V_16 = 0 ; V_16 < V_137 -> V_180 ; V_16 ++ ) {
T_1 V_50 = V_137 -> V_181 [ V_16 ] . V_46 ;
unsigned int V_400 ;
V_400 = F_105 ( V_19 , V_50 ) ;
V_400 = F_153 ( V_400 ) ;
if ( V_401 & ( 1 << V_400 ) )
return 0 ;
switch ( V_400 ) {
case V_266 :
if ( V_137 -> V_181 [ V_16 ] . type != V_179 )
return 0 ;
break;
case V_402 :
return 0 ;
default:
if ( V_137 -> V_181 [ V_16 ] . type > V_178 )
return 0 ;
if ( ! V_2 -> V_32 &&
V_137 -> V_181 [ V_16 ] . type != V_179 )
return 0 ;
if ( ! F_228 ( V_19 , V_50 ) )
return 0 ;
break;
}
if ( V_48 >= V_403 )
return 0 ;
V_401 |= ( 1 << V_400 ) ;
V_2 -> V_382 [ V_48 ] . V_46 = V_50 ;
V_2 -> V_382 [ V_48 ] . V_400 = V_400 ;
V_48 ++ ;
}
if ( V_48 < 2 )
return 0 ;
V_2 -> V_381 = V_48 ;
F_233 ( V_2 -> V_382 , V_48 , sizeof( V_2 -> V_382 [ 0 ] ) ,
F_231 , NULL ) ;
if ( ! F_230 ( V_19 ) )
return 0 ;
V_2 -> V_341 = 1 ;
V_2 -> V_301 = 1 ;
V_2 -> V_258 [ 0 ] = V_2 -> V_382 [ 0 ] . V_58 ;
F_36 ( L_84 ,
V_2 -> V_382 [ 0 ] . V_46 ,
V_2 -> V_382 [ 1 ] . V_46 ,
V_2 -> V_382 [ 2 ] . V_46 ) ;
return 0 ;
}
static unsigned int F_234 ( struct V_18 * V_19 ,
T_1 V_50 ,
unsigned int V_404 )
{
if ( V_404 != V_103 )
return V_404 ;
if ( F_39 ( F_40 ( V_19 , V_50 ) ) >= V_405 )
return V_404 ;
if ( F_69 ( V_19 , V_50 ) )
return V_404 ;
return V_107 ;
}
int F_235 ( struct V_18 * V_19 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_191 ;
F_11 ( V_19 ) ;
if ( V_2 -> V_45 && ! V_2 -> V_102 )
V_2 -> V_102 = V_2 -> V_45 ;
if ( V_137 != & V_2 -> V_138 ) {
V_2 -> V_138 = * V_137 ;
V_137 = & V_2 -> V_138 ;
}
if ( ! V_2 -> V_202 )
V_2 -> V_202 = & V_406 ;
if ( ! V_2 -> V_203 )
V_2 -> V_203 = & V_407 ;
F_118 ( V_19 ) ;
if ( ! V_137 -> V_139 ) {
if ( V_137 -> V_350 || V_137 -> V_355 ) {
V_2 -> V_145 . V_244 = 2 ;
V_2 -> V_408 = 1 ;
goto V_409;
}
return 0 ;
}
if ( ! V_2 -> V_35 &&
V_137 -> V_150 == V_151 &&
V_137 -> V_139 <= V_137 -> V_141 ) {
V_137 -> V_142 = V_137 -> V_139 ;
memcpy ( V_137 -> V_201 , V_137 -> V_199 ,
sizeof( V_137 -> V_201 ) ) ;
V_137 -> V_139 = V_137 -> V_141 ;
memcpy ( V_137 -> V_199 , V_137 -> V_200 , sizeof( V_137 -> V_200 ) ) ;
V_137 -> V_141 = 0 ;
memset ( V_137 -> V_200 , 0 , sizeof( V_137 -> V_200 ) ) ;
V_137 -> V_150 = V_153 ;
}
V_191 = F_120 ( V_19 ) ;
if ( V_191 < 0 )
return V_191 ;
V_191 = F_145 ( V_19 ) ;
if ( V_191 < 0 )
return V_191 ;
V_191 = F_123 ( V_19 , V_137 ) ;
if ( V_191 < 0 )
return V_191 ;
V_191 = F_126 ( V_19 ) ;
if ( V_191 < 0 )
return V_191 ;
V_191 = F_127 ( V_19 ) ;
if ( V_191 < 0 )
return V_191 ;
V_191 = F_136 ( V_19 ) ;
if ( V_191 < 0 )
return V_191 ;
V_191 = F_148 ( V_19 ) ;
if ( V_191 < 0 )
return V_191 ;
V_191 = F_152 ( V_19 ) ;
if ( V_191 < 0 )
return V_191 ;
V_191 = F_186 ( V_19 ) ;
if ( V_191 < 0 )
return V_191 ;
V_2 -> V_245 = V_2 -> V_204 ;
if ( V_137 -> V_150 != V_151 )
V_2 -> V_245 = F_144 ( V_2 -> V_245 ,
V_137 -> V_142 * 2 ) ;
if ( V_137 -> V_150 != V_153 )
V_2 -> V_245 = F_144 ( V_2 -> V_245 ,
V_137 -> V_141 * 2 ) ;
V_2 -> V_145 . V_244 = F_144 ( V_2 -> V_204 ,
V_2 -> V_245 ) ;
V_191 = F_227 ( V_19 ) ;
if ( V_191 < 0 )
return V_191 ;
V_191 = F_181 ( V_19 ) ;
if ( V_191 < 0 )
return V_191 ;
V_191 = F_232 ( V_19 ) ;
if ( V_191 < 0 )
return V_191 ;
V_191 = F_206 ( V_19 ) ;
if ( V_191 < 0 )
return V_191 ;
V_191 = F_209 ( V_19 ) ;
if ( V_191 < 0 )
return V_191 ;
if ( V_2 -> V_41 ) {
if ( V_137 -> V_150 != V_151 ) {
V_191 = F_162 ( V_19 , V_137 -> V_139 ,
V_137 -> V_199 ) ;
if ( V_191 < 0 )
return V_191 ;
}
if ( V_137 -> V_150 != V_153 ) {
V_191 = F_162 ( V_19 , V_137 -> V_141 ,
V_137 -> V_200 ) ;
if ( V_191 < 0 )
return V_191 ;
}
}
V_409:
F_210 ( V_19 ) ;
if ( V_2 -> V_42 )
V_19 -> V_410 = F_234 ;
if ( ! V_2 -> V_408 && V_2 -> V_411 ) {
V_191 = F_236 ( V_19 , V_2 -> V_411 ) ;
if ( V_191 < 0 )
return V_191 ;
}
return 1 ;
}
int F_237 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_191 ;
if ( V_2 -> V_3 . V_17 ) {
V_191 = F_238 ( V_19 , V_2 -> V_3 . V_14 ) ;
if ( V_191 < 0 )
return V_191 ;
}
if ( V_2 -> V_145 . V_352 ) {
V_191 = F_239 ( V_19 ,
V_2 -> V_145 . V_352 ,
V_2 -> V_145 . V_352 ,
V_2 -> V_412 [ 1 ] . V_413 ) ;
if ( V_191 < 0 )
return V_191 ;
if ( ! V_2 -> V_408 ) {
V_191 = F_240 ( V_19 ,
& V_2 -> V_145 ) ;
if ( V_191 < 0 )
return V_191 ;
V_2 -> V_145 . V_414 = 1 ;
}
}
if ( V_2 -> V_357 ) {
V_191 = F_241 ( V_19 , V_2 -> V_357 ) ;
if ( V_191 < 0 )
return V_191 ;
}
if ( ! V_2 -> V_408 &&
! F_242 ( V_19 , L_85 ) ) {
V_191 = F_243 ( V_19 , L_85 ,
V_2 -> V_218 , V_415 ,
L_86 ) ;
if ( V_191 < 0 )
return V_191 ;
}
if ( ! V_2 -> V_408 &&
! F_242 ( V_19 , L_87 ) ) {
V_191 = F_244 ( V_19 , L_87 ,
NULL , V_415 ,
L_88 ,
true , & V_2 -> V_143 . V_376 ) ;
if ( V_191 < 0 )
return V_191 ;
if ( V_2 -> V_143 . V_144 ) {
F_245 ( V_19 , & V_2 -> V_143 ,
V_2 -> V_416 ) ;
F_246 ( & V_2 -> V_143 ) ;
}
}
F_7 ( V_2 ) ;
V_191 = F_247 ( V_19 , & V_2 -> V_138 ) ;
if ( V_191 < 0 )
return V_191 ;
return 0 ;
}
static void F_248 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
struct V_419 * V_420 ,
int V_421 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_422 )
V_2 -> V_422 ( V_418 , V_19 , V_420 , V_421 ) ;
}
static void F_249 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
struct V_419 * V_420 ,
int V_421 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_423 )
V_2 -> V_423 ( V_418 , V_19 , V_420 , V_421 ) ;
}
static int F_250 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
struct V_419 * V_420 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_191 ;
F_132 ( & V_2 -> V_9 ) ;
V_191 = F_251 ( V_19 ,
& V_2 -> V_145 , V_420 ,
V_418 ) ;
if ( ! V_191 ) {
V_2 -> V_230 |= 1 << V_424 ;
F_248 ( V_418 , V_19 , V_420 ,
V_425 ) ;
}
F_135 ( & V_2 -> V_9 ) ;
return V_191 ;
}
static int F_252 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
unsigned int V_426 ,
unsigned int V_427 ,
struct V_419 * V_420 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_191 ;
V_191 = F_253 ( V_19 , & V_2 -> V_145 ,
V_426 , V_427 , V_420 ) ;
if ( ! V_191 )
F_248 ( V_418 , V_19 , V_420 ,
V_428 ) ;
return V_191 ;
}
static int F_254 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
struct V_419 * V_420 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_191 ;
V_191 = F_255 ( V_19 , & V_2 -> V_145 ) ;
if ( ! V_191 )
F_248 ( V_418 , V_19 , V_420 ,
V_429 ) ;
return V_191 ;
}
static int F_256 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
struct V_419 * V_420 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_132 ( & V_2 -> V_9 ) ;
V_2 -> V_230 &= ~ ( 1 << V_424 ) ;
F_248 ( V_418 , V_19 , V_420 ,
V_430 ) ;
F_135 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_257 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
struct V_419 * V_420 )
{
F_249 ( V_418 , V_19 , V_420 , V_425 ) ;
return 0 ;
}
static int F_258 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
unsigned int V_426 ,
unsigned int V_427 ,
struct V_419 * V_420 )
{
F_259 ( V_19 , V_418 -> V_50 , V_426 , 0 , V_427 ) ;
F_249 ( V_418 , V_19 , V_420 ,
V_428 ) ;
return 0 ;
}
static int F_260 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
struct V_419 * V_420 )
{
F_261 ( V_19 , V_418 -> V_50 ) ;
F_249 ( V_418 , V_19 , V_420 ,
V_429 ) ;
return 0 ;
}
static int F_262 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
struct V_419 * V_420 )
{
F_249 ( V_418 , V_19 , V_420 , V_430 ) ;
return 0 ;
}
static int F_263 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
struct V_419 * V_420 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_191 = 0 ;
F_132 ( & V_2 -> V_9 ) ;
if ( ! V_2 -> V_227 )
V_191 = - V_231 ;
else
V_2 -> V_230 |= 1 << V_431 ;
F_248 ( V_418 , V_19 , V_420 ,
V_425 ) ;
F_135 ( & V_2 -> V_9 ) ;
return V_191 ;
}
static int F_264 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
struct V_419 * V_420 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_132 ( & V_2 -> V_9 ) ;
V_2 -> V_230 &= ~ ( 1 << V_431 ) ;
F_248 ( V_418 , V_19 , V_420 ,
V_430 ) ;
F_135 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_265 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
unsigned int V_426 ,
unsigned int V_427 ,
struct V_419 * V_420 )
{
F_259 ( V_19 , V_418 -> V_50 , V_426 , 0 , V_427 ) ;
F_248 ( V_418 , V_19 , V_420 ,
V_428 ) ;
return 0 ;
}
static int F_266 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
struct V_419 * V_420 )
{
F_261 ( V_19 , V_418 -> V_50 ) ;
F_248 ( V_418 , V_19 , V_420 ,
V_429 ) ;
return 0 ;
}
static int F_267 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
struct V_419 * V_420 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_268 ( V_19 , & V_2 -> V_145 ) ;
}
static int F_269 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
unsigned int V_426 ,
unsigned int V_427 ,
struct V_419 * V_420 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_270 ( V_19 , & V_2 -> V_145 ,
V_426 , V_427 , V_420 ) ;
}
static int F_271 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
struct V_419 * V_420 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_272 ( V_19 , & V_2 -> V_145 ) ;
}
static int F_273 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
struct V_419 * V_420 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_274 ( V_19 , & V_2 -> V_145 ) ;
}
static int F_275 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
unsigned int V_426 ,
unsigned int V_427 ,
struct V_419 * V_420 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_259 ( V_19 , V_2 -> V_299 [ V_420 -> V_432 + 1 ] ,
V_426 , 0 , V_427 ) ;
F_249 ( V_418 , V_19 , V_420 ,
V_428 ) ;
return 0 ;
}
static int F_276 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
struct V_419 * V_420 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_261 ( V_19 ,
V_2 -> V_299 [ V_420 -> V_432 + 1 ] ) ;
F_249 ( V_418 , V_19 , V_420 ,
V_429 ) ;
return 0 ;
}
static bool F_211 ( struct V_18 * V_19 , int V_433 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_434 = V_2 -> V_299 [ V_2 -> V_309 [ V_433 ] ] ;
if ( V_2 -> V_435 && V_2 -> V_435 != V_434 ) {
F_277 ( V_19 , V_2 -> V_435 , 1 ) ;
V_2 -> V_435 = V_434 ;
F_259 ( V_19 , V_434 ,
V_2 -> V_436 , 0 ,
V_2 -> V_437 ) ;
return true ;
}
return false ;
}
static int F_278 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
unsigned int V_426 ,
unsigned int V_427 ,
struct V_419 * V_420 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
V_2 -> V_435 = V_2 -> V_299 [ V_2 -> V_309 [ V_2 -> V_258 [ 0 ] ] ] ;
V_2 -> V_436 = V_426 ;
V_2 -> V_437 = V_427 ;
F_259 ( V_19 , V_2 -> V_435 , V_426 , 0 , V_427 ) ;
return 0 ;
}
static int F_279 ( struct V_417 * V_418 ,
struct V_18 * V_19 ,
struct V_419 * V_420 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_261 ( V_19 , V_2 -> V_435 ) ;
V_2 -> V_435 = 0 ;
return 0 ;
}
static void F_280 ( char * V_438 , T_3 V_439 , const char * V_120 ,
const char * V_440 )
{
char * V_441 ;
if ( * V_438 )
return;
F_281 ( V_438 , V_440 , V_439 ) ;
for ( V_441 = strchr ( V_438 , ' ' ) ; V_441 ; V_441 = strchr ( V_441 + 1 , ' ' ) ) {
if ( ! isalnum ( V_441 [ 1 ] ) ) {
* V_441 = 0 ;
break;
}
}
F_35 ( V_438 , V_120 , V_439 ) ;
}
int F_282 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_442 * V_443 = V_2 -> V_412 ;
const struct V_417 * V_441 ;
bool V_444 ;
V_19 -> V_445 = 1 ;
V_19 -> V_446 = V_443 ;
if ( V_2 -> V_408 )
goto V_447;
F_280 ( V_2 -> V_448 ,
sizeof( V_2 -> V_448 ) ,
L_89 , V_19 -> V_440 ) ;
V_443 -> V_10 = V_2 -> V_448 ;
if ( V_2 -> V_145 . V_146 > 0 ) {
V_441 = V_2 -> V_449 ;
if ( ! V_441 )
V_441 = & V_450 ;
V_443 -> V_451 [ V_452 ] = * V_441 ;
V_443 -> V_451 [ V_452 ] . V_50 = V_2 -> V_145 . V_192 [ 0 ] ;
V_443 -> V_451 [ V_452 ] . V_453 =
V_2 -> V_145 . V_244 ;
if ( V_2 -> V_138 . V_150 == V_151 &&
V_2 -> V_138 . V_139 == 2 )
V_443 -> V_451 [ V_452 ] . V_454 =
V_455 ;
}
if ( V_2 -> V_301 ) {
V_441 = V_2 -> V_456 ;
if ( ! V_441 ) {
if ( V_2 -> V_310 )
V_441 = & V_457 ;
else
V_441 = & V_458 ;
}
V_443 -> V_451 [ V_459 ] = * V_441 ;
V_443 -> V_451 [ V_459 ] . V_50 = V_2 -> V_299 [ 0 ] ;
}
V_447:
if ( V_2 -> V_145 . V_352 || V_2 -> V_357 ) {
F_280 ( V_2 -> V_460 ,
sizeof( V_2 -> V_460 ) ,
L_90 , V_19 -> V_440 ) ;
V_19 -> V_445 = 2 ;
V_19 -> V_354 = V_2 -> V_145 . V_354 ;
V_443 = V_2 -> V_412 + 1 ;
V_443 -> V_10 = V_2 -> V_460 ;
if ( V_2 -> V_353 )
V_443 -> V_413 = V_2 -> V_353 ;
else
V_443 -> V_413 = V_461 ;
if ( V_2 -> V_145 . V_352 ) {
V_441 = V_2 -> V_462 ;
if ( ! V_441 )
V_441 = & V_463 ;
V_443 -> V_451 [ V_452 ] = * V_441 ;
V_443 -> V_451 [ V_452 ] . V_50 = V_2 -> V_145 . V_352 ;
}
if ( V_2 -> V_357 ) {
V_441 = V_2 -> V_464 ;
if ( ! V_441 )
V_441 = & V_465 ;
V_443 -> V_451 [ V_459 ] = * V_441 ;
V_443 -> V_451 [ V_459 ] . V_50 = V_2 -> V_357 ;
}
}
if ( V_2 -> V_408 )
return 0 ;
V_444 = ( V_2 -> V_301 > 1 ) &&
! V_2 -> V_310 && ! V_2 -> V_341 ;
if ( V_2 -> V_236 || V_444 ) {
F_280 ( V_2 -> V_466 ,
sizeof( V_2 -> V_466 ) ,
L_91 , V_19 -> V_440 ) ;
V_19 -> V_445 = 3 ;
V_443 = V_2 -> V_412 + 2 ;
V_443 -> V_10 = V_2 -> V_466 ;
if ( V_2 -> V_236 ) {
V_441 = V_2 -> V_467 ;
if ( ! V_441 )
V_441 = & V_468 ;
V_443 -> V_451 [ V_452 ] = * V_441 ;
V_443 -> V_451 [ V_452 ] . V_50 =
V_2 -> V_236 ;
} else {
V_443 -> V_451 [ V_452 ] =
V_469 ;
V_443 -> V_451 [ V_452 ] . V_50 = 0 ;
}
if ( V_444 ) {
V_441 = V_2 -> V_470 ;
if ( ! V_441 )
V_441 = & V_471 ;
V_443 -> V_451 [ V_459 ] = * V_441 ;
V_443 -> V_451 [ V_459 ] . V_50 =
V_2 -> V_299 [ 1 ] ;
V_443 -> V_451 [ V_459 ] . V_472 =
V_2 -> V_301 - 1 ;
} else {
V_443 -> V_451 [ V_459 ] =
V_469 ;
V_443 -> V_451 [ V_459 ] . V_50 = 0 ;
}
}
return 0 ;
}
static void F_283 ( struct V_18 * V_19 , int V_113 )
{
struct V_6 * V_52 ;
T_1 V_46 ;
V_52 = F_27 ( V_19 , V_113 ) ;
if ( ! V_52 || ! V_52 -> V_53 )
return;
V_46 = V_52 -> V_52 [ V_52 -> V_53 - 1 ] ;
F_14 ( V_19 , V_46 ) ;
F_64 ( V_19 , V_52 , V_52 -> V_88 ,
F_140 ( V_19 -> V_2 ) ) ;
F_72 ( V_19 , V_46 , V_52 -> V_88 ) ;
}
static void F_284 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_138 . V_139 ; V_16 ++ )
F_283 ( V_19 , V_2 -> V_185 [ V_16 ] ) ;
}
static void F_285 ( struct V_18 * V_19 , int V_161 , int * V_5 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_161 ; V_16 ++ )
F_283 ( V_19 , V_5 [ V_16 ] ) ;
}
static void F_286 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_138 . V_150 != V_153 )
F_285 ( V_19 , V_2 -> V_138 . V_141 , V_2 -> V_152 ) ;
if ( V_2 -> V_138 . V_150 != V_151 )
F_285 ( V_19 , V_2 -> V_138 . V_142 ,
V_2 -> V_154 ) ;
}
static void F_287 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_140 ; V_16 ++ ) {
T_1 V_46 = V_2 -> V_159 [ V_16 ] . V_46 ;
struct V_6 * V_52 ;
V_52 = F_139 ( V_19 , V_16 ) ;
if ( ! V_52 )
continue;
if ( ! V_2 -> V_159 [ V_16 ] . V_243 )
V_2 -> V_159 [ V_16 ] . V_243 =
F_16 ( V_19 , V_46 ) ;
F_64 ( V_19 , V_52 , V_52 -> V_88 ,
F_140 ( V_2 ) ) ;
}
}
static void F_288 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_136 * V_137 = & V_2 -> V_138 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_137 -> V_180 ; V_16 ++ ) {
T_1 V_50 = V_137 -> V_181 [ V_16 ] . V_46 ;
if ( F_179 ( V_19 , V_50 ) )
F_14 ( V_19 , V_50 ) ;
if ( V_2 -> V_45 ) {
F_75 ( V_19 , V_2 -> V_196 [ V_16 ] ) ;
F_75 ( V_19 , V_2 -> V_298 ) ;
}
}
}
static void F_289 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_304 * V_305 = & V_2 -> V_306 ;
struct V_6 * V_52 ;
int V_16 , V_317 , V_51 ;
if ( V_2 -> V_310 )
V_51 = 1 ;
else
V_51 = V_2 -> V_301 ;
for ( V_317 = 0 ; V_317 < V_51 ; V_317 ++ ) {
for ( V_16 = 0 ; V_16 < V_305 -> V_308 ; V_16 ++ ) {
V_52 = F_187 ( V_19 , V_317 , V_16 ) ;
if ( V_52 ) {
bool V_88 = V_52 -> V_88 ;
if ( V_16 == V_2 -> V_258 [ V_317 ] )
V_88 = true ;
F_64 ( V_19 , V_52 , V_88 , false ) ;
}
}
if ( V_2 -> V_43 )
F_149 ( V_19 , V_317 , true ) ;
}
if ( V_2 -> V_330 )
V_2 -> V_330 ( V_19 , NULL ) ;
}
static void F_290 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_46 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_138 . V_350 ; V_16 ++ )
F_283 ( V_19 , V_2 -> V_194 [ V_16 ] ) ;
V_46 = V_2 -> V_138 . V_355 ;
if ( V_46 ) {
F_14 ( V_19 , V_46 ) ;
F_75 ( V_19 , V_2 -> V_197 ) ;
}
}
static void F_291 ( struct V_18 * V_19 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_473 . V_17 ; V_16 ++ ) {
struct V_474 * V_46 = F_24 ( & V_19 -> V_473 , V_16 ) ;
T_1 V_50 = V_46 -> V_50 ;
if ( F_228 ( V_19 , V_50 ) &&
! F_292 ( V_19 , V_50 ) )
F_74 ( V_19 , V_50 , 0 ,
V_475 , 0 ) ;
}
}
int F_293 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_476 )
V_2 -> V_476 ( V_19 ) ;
F_294 ( V_19 ) ;
V_19 -> V_329 = 1 ;
F_284 ( V_19 ) ;
F_286 ( V_19 ) ;
F_287 ( V_19 ) ;
F_288 ( V_19 ) ;
F_289 ( V_19 ) ;
F_290 ( V_19 ) ;
F_291 ( V_19 ) ;
F_142 ( V_19 ) ;
F_195 ( V_19 ) ;
if ( V_2 -> V_143 . V_376 && V_2 -> V_143 . V_144 )
F_246 ( & V_2 -> V_143 ) ;
F_295 ( V_19 , 0x01 ) ;
return 0 ;
}
void F_296 ( struct V_18 * V_19 )
{
F_297 ( V_19 ) ;
F_10 ( V_19 -> V_2 ) ;
F_8 ( V_19 -> V_2 ) ;
V_19 -> V_2 = NULL ;
}
int F_298 ( struct V_18 * V_19 , T_1 V_50 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_299 ( V_19 , & V_2 -> V_292 , V_50 ) ;
}
int F_300 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_191 ;
V_2 = F_301 ( sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 )
return - V_122 ;
F_1 ( V_2 ) ;
V_19 -> V_2 = V_2 ;
V_191 = F_302 ( V_19 , & V_2 -> V_138 , NULL , 0 ) ;
if ( V_191 < 0 )
return V_191 ;
V_191 = F_235 ( V_19 , & V_2 -> V_138 ) ;
if ( V_191 < 0 )
goto error;
V_19 -> V_477 = V_478 ;
return 0 ;
error:
F_296 ( V_19 ) ;
return V_191 ;
}
