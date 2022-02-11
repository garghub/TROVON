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
V_2 -> V_39 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_21 ) ;
if ( V_20 >= 0 )
V_2 -> V_39 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_22 ) ;
if ( V_20 >= 0 )
V_2 -> V_40 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_23 ) ;
if ( V_20 >= 0 )
V_2 -> V_41 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_24 ) ;
if ( V_20 >= 0 )
V_2 -> V_42 = ! V_20 ;
if ( ! F_13 ( V_19 , L_25 , & V_20 ) )
V_2 -> V_43 = V_20 ;
}
static inline void F_14 ( struct V_18 * V_19 , T_1 V_44 )
{
F_15 ( V_19 , V_44 , F_16 ( V_19 , V_44 ) ) ;
}
static void F_17 ( struct V_18 * V_19 , T_1 V_44 ,
unsigned int V_20 , bool V_45 )
{
if ( ! V_44 )
return;
V_20 = F_18 ( V_19 , V_44 , V_20 ) ;
F_19 ( V_19 , V_44 , V_20 ) ;
if ( V_45 )
F_15 ( V_19 , V_44 , V_20 ) ;
}
static void F_20 ( struct V_18 * V_19 , int V_46 ,
T_1 * V_47 , unsigned int V_20 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_46 ; V_16 ++ )
F_17 ( V_19 , V_47 [ V_16 ] , V_20 , false ) ;
}
static int F_21 ( T_1 V_48 , const T_1 * V_14 , int V_49 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_49 ; V_16 ++ )
if ( V_14 [ V_16 ] == V_48 )
return V_16 ;
return - 1 ;
}
static bool F_22 ( struct V_6 * V_50 , T_1 V_48 )
{
return F_21 ( V_48 , V_50 -> V_50 , V_50 -> V_51 ) >= 0 ;
}
static struct V_6 * F_23 ( struct V_18 * V_19 ,
T_1 V_52 , T_1 V_53 ,
int V_54 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 . V_17 ; V_16 ++ ) {
struct V_6 * V_50 = F_24 ( & V_2 -> V_5 , V_16 ) ;
if ( V_50 -> V_51 <= 0 )
continue;
if ( ( ! V_52 || V_50 -> V_50 [ 0 ] == V_52 ) &&
( ! V_53 || V_50 -> V_50 [ V_50 -> V_51 - 1 ] == V_53 ) ) {
if ( ! V_54 ||
( V_54 > 0 && F_22 ( V_50 , V_54 ) ) ||
( V_54 < 0 && ! F_22 ( V_50 , V_54 ) ) )
return V_50 ;
}
}
return NULL ;
}
struct V_6 * F_25 ( struct V_18 * V_19 ,
T_1 V_52 , T_1 V_53 )
{
return F_23 ( V_19 , V_52 , V_53 , 0 ) ;
}
int F_26 ( struct V_18 * V_19 , struct V_6 * V_50 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_55 = V_2 -> V_5 . V_14 ;
T_2 V_56 ;
if ( ! V_2 -> V_5 . V_17 )
return 0 ;
V_56 = V_50 - V_55 ;
if ( V_56 < 0 || V_56 >= V_2 -> V_5 . V_17 )
return 0 ;
return V_56 + 1 ;
}
struct V_6 * F_27 ( struct V_18 * V_19 , int V_56 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_56 <= 0 || V_56 > V_2 -> V_5 . V_17 )
return NULL ;
return F_24 ( & V_2 -> V_5 , V_56 - 1 ) ;
}
static bool F_28 ( struct V_18 * V_19 , T_1 V_48 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 . V_17 ; V_16 ++ ) {
struct V_6 * V_50 = F_24 ( & V_2 -> V_5 , V_16 ) ;
if ( V_50 -> V_50 [ 0 ] == V_48 )
return true ;
}
return false ;
}
static bool F_29 ( struct V_18 * V_19 ,
T_1 V_52 , T_1 V_53 )
{
if ( ! V_52 || ! V_53 )
return false ;
return F_30 ( V_19 , V_53 , V_52 , true ) >= 0 ;
}
static bool F_31 ( struct V_18 * V_19 , unsigned int V_20 , int type )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
V_20 &= V_57 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 . V_17 ; V_16 ++ ) {
struct V_6 * V_50 = F_24 ( & V_2 -> V_5 , V_16 ) ;
if ( ( V_50 -> V_58 [ type ] & V_57 ) == V_20 )
return true ;
}
return false ;
}
static bool F_32 ( struct V_18 * V_19 , T_1 V_48 ,
int V_59 , int V_56 , int type )
{
unsigned int V_20 = F_33 ( V_48 , 3 , V_56 , V_59 ) ;
return F_31 ( V_19 , V_20 , type ) ;
}
static void F_34 ( const char * V_60 , struct V_6 * V_50 )
{
char V_61 [ 40 ] ;
int V_16 ;
V_61 [ 0 ] = 0 ;
for ( V_16 = 0 ; V_16 < V_50 -> V_51 ; V_16 ++ ) {
char V_62 [ 4 ] ;
sprintf ( V_62 , L_26 , V_50 -> V_50 [ V_16 ] ) ;
F_35 ( V_61 , V_62 , sizeof( V_61 ) ) ;
}
F_36 ( L_27 , V_60 , V_50 -> V_51 , V_61 ) ;
}
static bool F_37 ( struct V_18 * V_19 ,
T_1 V_52 , T_1 V_53 ,
int V_54 , struct V_6 * V_50 ,
int V_51 )
{
const T_1 * V_63 ;
int V_16 , V_49 ;
if ( V_53 == V_54 )
V_54 = 0 ;
else if ( V_53 == ( T_1 ) ( - V_54 ) )
return false ;
V_49 = F_38 ( V_19 , V_53 , & V_63 ) ;
for ( V_16 = 0 ; V_16 < V_49 ; V_16 ++ ) {
if ( V_63 [ V_16 ] != V_52 ) {
if ( V_52 ||
F_39 ( F_40 ( V_19 , V_63 [ V_16 ] ) ) != V_64 ||
F_28 ( V_19 , V_63 [ V_16 ] ) )
continue;
}
if ( V_54 <= 0 )
goto V_65;
}
if ( V_51 >= V_66 )
return false ;
for ( V_16 = 0 ; V_16 < V_49 ; V_16 ++ ) {
unsigned int type ;
type = F_39 ( F_40 ( V_19 , V_63 [ V_16 ] ) ) ;
if ( type == V_64 || type == V_67 ||
type == V_68 )
continue;
if ( F_37 ( V_19 , V_52 , V_63 [ V_16 ] ,
V_54 , V_50 , V_51 + 1 ) )
goto V_65;
}
return false ;
V_65:
V_50 -> V_50 [ V_50 -> V_51 ] = V_63 [ V_16 ] ;
V_50 -> V_56 [ V_50 -> V_51 + 1 ] = V_16 ;
if ( V_49 > 1 && F_39 ( F_40 ( V_19 , V_53 ) ) != V_69 )
V_50 -> V_70 [ V_50 -> V_51 + 1 ] = 1 ;
V_50 -> V_51 ++ ;
return true ;
}
bool F_41 ( struct V_18 * V_19 , T_1 V_52 ,
T_1 V_53 , int V_54 ,
struct V_6 * V_50 )
{
if ( F_37 ( V_19 , V_52 , V_53 , V_54 , V_50 , 1 ) ) {
V_50 -> V_50 [ V_50 -> V_51 ] = V_53 ;
V_50 -> V_51 ++ ;
return true ;
}
return false ;
}
struct V_6 *
F_42 ( struct V_18 * V_19 , T_1 V_52 ,
T_1 V_53 , int V_54 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_50 ;
if ( V_52 && V_53 && ! F_29 ( V_19 , V_52 , V_53 ) )
return NULL ;
V_50 = F_23 ( V_19 , V_52 , V_53 , V_54 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_5 ( & V_2 -> V_5 ) ;
if ( ! V_50 )
return NULL ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
if ( F_41 ( V_19 , V_52 , V_53 , V_54 , V_50 ) )
return V_50 ;
V_2 -> V_5 . V_17 -- ;
return NULL ;
}
static void F_43 ( struct V_18 * V_19 , int V_56 )
{
struct V_6 * V_50 = F_27 ( V_19 , V_56 ) ;
if ( ! V_50 )
return;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
}
static T_1 F_44 ( struct V_18 * V_19 , T_1 V_44 ,
bool V_71 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_72 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_73 ; V_16 ++ ) {
T_1 V_48 = V_2 -> V_74 [ V_16 ] ;
if ( ! V_48 || F_28 ( V_19 , V_48 ) )
continue;
V_72 = ! ! ( F_40 ( V_19 , V_48 ) & V_75 ) ;
if ( V_71 != V_72 )
continue;
if ( F_29 ( V_19 , V_48 , V_44 ) )
return V_48 ;
}
return 0 ;
}
static unsigned int F_45 ( unsigned int V_20 , unsigned int V_76 )
{
V_20 &= ~ ( 0x3U << 16 ) ;
V_20 |= V_76 << 16 ;
return V_20 ;
}
static bool F_46 ( struct V_18 * V_19 , T_1 V_48 ,
int V_59 , unsigned int V_77 )
{
if ( ! V_48 )
return false ;
if ( F_40 ( V_19 , V_48 ) & ( 1 << ( V_59 + 1 ) ) )
if ( F_47 ( V_19 , V_48 , V_59 ) & V_77 )
return true ;
return false ;
}
static bool F_48 ( struct V_18 * V_19 , T_1 V_78 ,
T_1 V_79 , int V_59 )
{
if ( ! ( F_40 ( V_19 , V_78 ) & ( 1 << ( V_59 + 1 ) ) ) )
return ! ( F_40 ( V_19 , V_79 ) & ( 1 << ( V_59 + 1 ) ) ) ;
return ( F_47 ( V_19 , V_78 , V_59 ) ==
F_47 ( V_19 , V_79 , V_59 ) ) ;
}
static T_1 F_49 ( struct V_18 * V_19 ,
struct V_6 * V_50 )
{
int V_16 ;
for ( V_16 = V_50 -> V_51 - 1 ; V_16 >= 0 ; V_16 -- ) {
if ( F_50 ( V_19 , V_50 -> V_50 [ V_16 ] , V_80 ) )
return V_50 -> V_50 [ V_16 ] ;
if ( V_16 != V_50 -> V_51 - 1 && V_16 != 0 &&
F_50 ( V_19 , V_50 -> V_50 [ V_16 ] , V_81 ) )
return V_50 -> V_50 [ V_16 ] ;
}
return 0 ;
}
static T_1 F_51 ( struct V_18 * V_19 ,
struct V_6 * V_50 )
{
int V_16 ;
for ( V_16 = V_50 -> V_51 - 1 ; V_16 >= 0 ; V_16 -- ) {
if ( F_52 ( V_19 , V_50 -> V_50 [ V_16 ] , V_80 ) )
return V_50 -> V_50 [ V_16 ] ;
}
return 0 ;
}
static bool F_53 ( struct V_18 * V_19 , struct V_6 * V_50 , int V_56 )
{
T_1 V_48 = V_50 -> V_50 [ V_56 ] ;
unsigned int V_82 = F_40 ( V_19 , V_48 ) ;
unsigned int type = F_39 ( V_82 ) ;
if ( ! ( V_82 & V_83 ) )
return false ;
if ( type == V_68 && V_56 > 0 )
return false ;
return true ;
}
static bool F_54 ( struct V_18 * V_19 , struct V_6 * V_50 , int V_56 )
{
T_1 V_48 = V_50 -> V_50 [ V_56 ] ;
unsigned int V_82 = F_40 ( V_19 , V_48 ) ;
unsigned int type = F_39 ( V_82 ) ;
if ( ! ( V_82 & V_84 ) )
return false ;
if ( type == V_68 && ! V_56 )
return false ;
return true ;
}
static bool F_55 ( struct V_18 * V_19 , T_1 V_48 ,
unsigned int V_59 , unsigned int V_56 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_85 ;
for ( V_85 = 0 ; V_85 < V_2 -> V_5 . V_17 ; V_85 ++ ) {
struct V_6 * V_50 = F_24 ( & V_2 -> V_5 , V_85 ) ;
if ( ! V_50 -> V_86 )
continue;
for ( V_16 = 0 ; V_16 < V_50 -> V_51 ; V_16 ++ ) {
if ( V_50 -> V_50 [ V_16 ] == V_48 ) {
if ( V_59 == V_80 || V_50 -> V_56 [ V_16 ] == V_56 )
return true ;
break;
}
}
}
return false ;
}
static int F_56 ( struct V_18 * V_19 , T_1 V_48 ,
int V_59 , unsigned int V_82 , bool V_87 )
{
unsigned int V_20 = 0 ;
if ( V_82 & V_88 ) {
if ( V_87 )
V_20 = ( V_82 & V_89 ) >> V_90 ;
}
if ( V_82 & V_91 ) {
if ( ! V_87 )
V_20 |= V_92 ;
}
return V_20 ;
}
static void F_57 ( struct V_18 * V_19 , T_1 V_48 , int V_59 , int V_56 )
{
unsigned int V_82 = F_47 ( V_19 , V_48 , V_59 ) ;
int V_20 = F_56 ( V_19 , V_48 , V_59 , V_82 , false ) ;
F_58 ( V_19 , V_48 , V_59 , V_56 , 0xff , V_20 ) ;
}
static unsigned int F_59 ( struct V_18 * V_19 ,
T_1 V_48 , int V_59 , int V_56 ,
unsigned int V_82 )
{
unsigned int V_93 = 0xff ;
if ( V_82 & V_91 ) {
if ( F_32 ( V_19 , V_48 , V_59 , V_56 , V_94 ) )
V_93 &= ~ 0x80 ;
}
if ( V_82 & V_88 ) {
if ( F_32 ( V_19 , V_48 , V_59 , V_56 , V_95 ) ||
F_32 ( V_19 , V_48 , V_59 , V_56 , V_96 ) )
V_93 &= ~ 0x7f ;
}
return V_93 ;
}
static void F_60 ( struct V_18 * V_19 , T_1 V_48 , int V_59 ,
int V_56 , int V_97 , bool V_87 )
{
unsigned int V_82 ;
unsigned int V_93 , V_20 ;
if ( ! V_87 && F_55 ( V_19 , V_48 , V_59 , V_97 ) )
return;
V_82 = F_47 ( V_19 , V_48 , V_59 ) ;
V_20 = F_56 ( V_19 , V_48 , V_59 , V_82 , V_87 ) ;
V_93 = F_59 ( V_19 , V_48 , V_59 , V_97 , V_82 ) ;
if ( ! V_93 )
return;
V_20 &= V_93 ;
F_61 ( V_19 , V_48 , V_59 , V_56 , V_93 , V_20 ) ;
}
static void F_62 ( struct V_18 * V_19 , struct V_6 * V_50 ,
int V_16 , bool V_87 )
{
T_1 V_48 = V_50 -> V_50 [ V_16 ] ;
F_57 ( V_19 , V_48 , V_80 , 0 ) ;
F_60 ( V_19 , V_48 , V_80 , 0 , 0 , V_87 ) ;
}
static void F_63 ( struct V_18 * V_19 , struct V_6 * V_50 ,
int V_16 , bool V_87 , bool V_98 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const T_1 * V_63 ;
int V_85 , V_49 , V_56 ;
int type ;
T_1 V_48 = V_50 -> V_50 [ V_16 ] ;
V_49 = F_38 ( V_19 , V_48 , & V_63 ) ;
type = F_39 ( F_40 ( V_19 , V_48 ) ) ;
if ( type == V_68 ||
( type == V_67 && V_19 -> V_29 ) ) {
V_49 = 1 ;
V_56 = 0 ;
} else
V_56 = V_50 -> V_56 [ V_16 ] ;
for ( V_85 = 0 ; V_85 < V_49 ; V_85 ++ )
F_57 ( V_19 , V_48 , V_81 , V_85 ) ;
for ( V_85 = 0 ; V_85 < V_49 ; V_85 ++ ) {
if ( V_85 != V_56 && ( ! V_98 || V_63 [ V_85 ] != V_2 -> V_99 ) )
continue;
F_60 ( V_19 , V_48 , V_81 , V_85 , V_56 , V_87 ) ;
}
}
void F_64 ( struct V_18 * V_19 , struct V_6 * V_50 ,
bool V_87 , bool V_98 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
if ( ! V_87 )
V_50 -> V_86 = false ;
for ( V_16 = V_50 -> V_51 - 1 ; V_16 >= 0 ; V_16 -- ) {
T_1 V_48 = V_50 -> V_50 [ V_16 ] ;
if ( V_87 && V_2 -> V_40 ) {
if ( ! F_65 ( V_19 , V_48 , V_100 ) )
F_66 ( V_19 , V_48 , 0 ,
V_101 ,
V_100 ) ;
}
if ( V_87 && V_50 -> V_70 [ V_16 ] )
F_67 ( V_19 , V_48 , 0 ,
V_102 ,
V_50 -> V_56 [ V_16 ] ) ;
if ( F_53 ( V_19 , V_50 , V_16 ) )
F_63 ( V_19 , V_50 , V_16 , V_87 , V_98 ) ;
if ( F_54 ( V_19 , V_50 , V_16 ) )
F_62 ( V_19 , V_50 , V_16 , V_87 ) ;
}
if ( V_87 )
V_50 -> V_86 = true ;
}
static void F_68 ( struct V_18 * V_19 , struct V_6 * V_50 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_103 = false ;
int V_16 ;
if ( ! V_2 -> V_40 || V_50 -> V_86 )
return;
for ( V_16 = 0 ; V_16 < V_50 -> V_51 ; V_16 ++ ) {
T_1 V_48 = V_50 -> V_50 [ V_16 ] ;
if ( ! F_65 ( V_19 , V_48 , V_104 ) &&
! F_69 ( V_19 , V_48 ) ) {
F_66 ( V_19 , V_48 , 0 ,
V_101 ,
V_104 ) ;
V_103 = true ;
}
}
if ( V_103 ) {
F_70 ( 10 ) ;
F_71 ( V_19 , V_50 -> V_50 [ 0 ] , 0 ,
V_105 , 0 ) ;
}
}
static void F_72 ( struct V_18 * V_19 , T_1 V_44 , bool V_87 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_106 ||
! ( F_73 ( V_19 , V_44 ) & V_107 ) )
return;
if ( V_19 -> V_24 )
V_87 = ! V_87 ;
if ( V_2 -> V_108 && ! V_87 )
return;
F_74 ( V_19 , V_44 , 0 ,
V_109 ,
V_87 ? 0x02 : 0x00 ) ;
}
static void F_75 ( struct V_18 * V_19 , int V_110 )
{
struct V_6 * V_50 = F_27 ( V_19 , V_110 ) ;
if ( V_50 )
F_64 ( V_19 , V_50 , V_50 -> V_86 , false ) ;
}
static struct V_4 *
F_76 ( struct V_1 * V_2 , int type , const char * V_10 ,
int V_111 , unsigned long V_20 )
{
struct V_4 * V_12 ;
V_12 = F_4 ( V_2 , V_10 , & V_112 [ type ] ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_113 = V_111 ;
if ( F_77 ( V_20 ) )
V_12 -> V_114 = V_115 ;
V_12 -> V_116 = V_20 ;
return V_12 ;
}
static int F_78 ( struct V_1 * V_2 , int type ,
const char * V_60 , const char * V_59 ,
const char * V_117 , int V_111 , unsigned long V_20 )
{
char V_10 [ 32 ] ;
snprintf ( V_10 , sizeof( V_10 ) , L_28 , V_60 , V_59 , V_117 ) ;
if ( ! F_76 ( V_2 , type , V_10 , V_111 , V_20 ) )
return - V_118 ;
return 0 ;
}
static int F_79 ( struct V_18 * V_19 , const char * V_60 , int V_111 ,
unsigned int V_76 , struct V_6 * V_50 )
{
unsigned int V_20 ;
if ( ! V_50 )
return 0 ;
V_20 = V_50 -> V_58 [ V_95 ] ;
if ( ! V_20 )
return 0 ;
V_20 = F_45 ( V_20 , V_76 ) ;
return F_80 ( V_19 -> V_2 , V_119 , V_60 , V_111 , V_20 ) ;
}
static int F_81 ( struct V_18 * V_19 , struct V_6 * V_50 ,
int type )
{
int V_76 = 1 ;
if ( V_50 ) {
T_1 V_48 = F_77 ( V_50 -> V_58 [ type ] ) ;
if ( V_48 && ( F_40 ( V_19 , V_48 ) & V_120 ) )
V_76 = 3 ;
}
return V_76 ;
}
static int F_82 ( struct V_18 * V_19 , const char * V_60 , int V_111 ,
struct V_6 * V_50 )
{
int V_76 = F_81 ( V_19 , V_50 , V_95 ) ;
return F_79 ( V_19 , V_60 , V_111 , V_76 , V_50 ) ;
}
static int F_83 ( struct V_18 * V_19 , const char * V_60 , int V_111 ,
unsigned int V_76 , struct V_6 * V_50 )
{
unsigned int V_20 ;
int type = V_121 ;
if ( ! V_50 )
return 0 ;
V_20 = V_50 -> V_58 [ V_94 ] ;
if ( ! V_20 )
return 0 ;
V_20 = F_45 ( V_20 , V_76 ) ;
if ( F_84 ( V_20 ) == V_81 ) {
T_1 V_48 = F_77 ( V_20 ) ;
int V_49 = F_85 ( V_19 , V_48 ) ;
if ( V_49 > 1 ) {
type = V_122 ;
V_20 |= V_49 << 19 ;
}
}
return F_86 ( V_19 -> V_2 , type , V_60 , V_111 , V_20 ) ;
}
static int F_87 ( struct V_18 * V_19 , const char * V_60 ,
int V_111 , struct V_6 * V_50 )
{
int V_76 = F_81 ( V_19 , V_50 , V_94 ) ;
return F_83 ( V_19 , V_60 , V_111 , V_76 , V_50 ) ;
}
static bool F_88 ( struct V_18 * V_19 , int V_110 , int V_123 )
{
struct V_6 * V_50 = F_27 ( V_19 , V_110 ) ;
return V_50 && V_50 -> V_58 [ V_123 ] ;
}
static const char * F_89 ( struct V_18 * V_19 , int V_124 ,
int * V_113 , int V_123 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_125 * V_126 = & V_2 -> V_127 ;
* V_113 = 0 ;
if ( V_126 -> V_128 == 1 && ! V_2 -> V_129 &&
! V_126 -> V_130 && ! V_126 -> V_131 )
return V_2 -> V_132 . V_133 ? L_29 : L_30 ;
if ( V_2 -> V_134 . V_135 == 1 && ! V_2 -> V_43 &&
! V_2 -> V_134 . V_136 [ 0 ] && ! V_2 -> V_134 . V_137 [ 0 ] )
return V_2 -> V_132 . V_133 ? L_29 : L_30 ;
if ( V_124 >= V_126 -> V_128 )
return V_138 [ V_124 ] ;
switch ( V_126 -> V_139 ) {
case V_140 :
if ( ! V_124 && V_126 -> V_130 &&
! F_88 ( V_19 , V_2 -> V_141 [ 0 ] , V_123 ) )
break;
if ( V_126 -> V_128 == 1 )
return L_31 ;
if ( V_126 -> V_128 == 2 )
return V_124 ? L_32 : L_31 ;
break;
case V_142 :
if ( ! V_124 && V_126 -> V_131 &&
! F_88 ( V_19 , V_2 -> V_143 [ 0 ] , V_123 ) )
break;
if ( V_124 && V_2 -> V_129 )
break;
* V_113 = V_124 ;
return L_33 ;
}
if ( V_126 -> V_128 == 1 && ! V_2 -> V_129 )
return L_29 ;
if ( V_124 >= F_90 ( V_138 ) ) {
F_91 () ;
return L_29 ;
}
return V_138 [ V_124 ] ;
}
static int F_92 ( struct V_18 * V_19 , struct V_6 * V_50 )
{
T_1 V_48 ;
unsigned int V_20 ;
int V_144 = 0 ;
if ( ! V_50 )
return V_145 * 2 ;
if ( V_50 -> V_58 [ V_95 ] ||
V_50 -> V_58 [ V_94 ] )
return 0 ;
V_48 = F_51 ( V_19 , V_50 ) ;
if ( V_48 ) {
V_20 = F_33 ( V_48 , 3 , 0 , V_80 ) ;
if ( F_31 ( V_19 , V_20 , V_95 ) )
V_144 += V_145 ;
else
V_50 -> V_58 [ V_95 ] = V_20 ;
} else
V_144 += V_145 ;
V_48 = F_49 ( V_19 , V_50 ) ;
if ( V_48 ) {
unsigned int V_146 = F_39 ( F_40 ( V_19 , V_48 ) ) ;
if ( V_146 == V_68 || V_146 == V_64 ||
F_50 ( V_19 , V_48 , V_80 ) )
V_20 = F_33 ( V_48 , 3 , 0 , V_80 ) ;
else
V_20 = F_33 ( V_48 , 3 , 0 , V_81 ) ;
if ( F_31 ( V_19 , V_20 , V_94 ) )
V_144 += V_145 ;
else
V_50 -> V_58 [ V_94 ] = V_20 ;
} else
V_144 += V_145 ;
return V_144 ;
}
static T_1 F_93 ( struct V_18 * V_19 , int V_56 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_125 * V_126 = & V_2 -> V_127 ;
if ( V_126 -> V_128 > V_56 )
return V_2 -> V_147 [ V_56 ] ;
V_56 -= V_126 -> V_128 ;
if ( V_2 -> V_129 > V_56 )
return V_2 -> V_148 [ V_56 ] . V_149 ;
return 0 ;
}
static inline T_1 F_94 ( struct V_18 * V_19 ,
T_1 V_149 , T_1 V_44 )
{
return F_29 ( V_19 , V_149 , V_44 ) ? V_149 : 0 ;
}
static int F_95 ( struct V_18 * V_19 , int V_150 ,
const T_1 * V_47 , T_1 * V_151 ,
int * V_110 ,
const struct V_152 * V_153 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_154 ;
int V_144 = 0 ;
T_1 V_149 ;
if ( ! V_150 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_150 ; V_16 ++ ) {
struct V_6 * V_50 ;
T_1 V_44 = V_47 [ V_16 ] ;
V_50 = F_27 ( V_19 , V_110 [ V_16 ] ) ;
if ( V_50 ) {
V_144 += F_92 ( V_19 , V_50 ) ;
continue;
}
V_151 [ V_16 ] = F_44 ( V_19 , V_44 , false ) ;
if ( ! V_151 [ V_16 ] && ! V_16 ) {
for ( V_154 = 1 ; V_154 < V_150 ; V_154 ++ ) {
if ( F_29 ( V_19 , V_151 [ V_154 ] , V_44 ) ) {
V_151 [ 0 ] = V_151 [ V_154 ] ;
V_151 [ V_154 ] = 0 ;
F_43 ( V_19 , V_110 [ V_154 ] ) ;
V_110 [ V_154 ] = 0 ;
break;
}
}
}
V_149 = V_151 [ V_16 ] ;
if ( ! V_149 ) {
if ( V_150 > 2 )
V_149 = F_94 ( V_19 , F_93 ( V_19 , V_16 ) , V_44 ) ;
if ( ! V_149 )
V_149 = F_94 ( V_19 , V_151 [ 0 ] , V_44 ) ;
if ( ! V_149 )
V_149 = F_94 ( V_19 , F_93 ( V_19 , V_16 ) , V_44 ) ;
if ( V_149 ) {
if ( ! V_16 )
V_144 += V_153 -> V_155 ;
else if ( V_16 == 1 )
V_144 += V_153 -> V_156 ;
else
V_144 += V_153 -> V_157 ;
} else if ( F_29 ( V_19 , V_2 -> V_147 [ 0 ] , V_44 ) ) {
V_149 = V_2 -> V_147 [ 0 ] ;
V_144 += V_153 -> V_158 ;
} else if ( ! V_16 )
V_144 += V_153 -> V_159 ;
else
V_144 += V_153 -> V_160 ;
}
if ( ! V_149 )
continue;
V_50 = F_42 ( V_19 , V_149 , V_44 , - V_2 -> V_43 ) ;
if ( ! V_50 && ! V_16 && V_2 -> V_43 ) {
V_50 = F_42 ( V_19 , V_149 , V_44 , 0 ) ;
}
if ( ! V_50 ) {
V_149 = V_151 [ V_16 ] = 0 ;
V_144 += V_153 -> V_160 ;
} else {
V_50 -> V_86 = true ;
V_110 [ V_16 ] = F_26 ( V_19 , V_50 ) ;
V_144 += F_92 ( V_19 , V_50 ) ;
}
}
return V_144 ;
}
static T_1 F_96 ( struct V_18 * V_19 , T_1 V_44 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_161 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_73 ; V_16 ++ ) {
T_1 V_48 = V_2 -> V_74 [ V_16 ] ;
if ( ! V_48 || F_28 ( V_19 , V_48 ) )
continue;
if ( F_29 ( V_19 , V_48 , V_44 ) ) {
if ( V_161 )
return 0 ;
V_161 = V_48 ;
}
}
return V_161 ;
}
static bool F_97 ( struct V_18 * V_19 ,
unsigned int V_162 , T_1 V_48 )
{
unsigned int V_163 , V_82 ;
V_163 = F_98 ( V_19 , V_48 ) ;
if ( F_99 ( V_163 ) != V_164 )
return false ;
if ( V_162 && F_100 ( V_163 ) != V_162 )
return false ;
V_82 = F_73 ( V_19 , V_48 ) ;
if ( ! ( V_82 & V_165 ) )
return false ;
return true ;
}
static int F_101 ( struct V_18 * V_19 , T_1 V_166 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_125 * V_126 = & V_2 -> V_127 ;
unsigned int V_163 = F_98 ( V_19 , V_166 ) ;
unsigned int V_162 = F_100 ( V_163 ) ;
int type , V_16 ;
int V_46 = 0 ;
for ( type = V_167 ; type >= V_168 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_126 -> V_169 ; V_16 ++ ) {
if ( V_126 -> V_170 [ V_16 ] . type != type )
continue;
if ( F_97 ( V_19 , V_162 ,
V_126 -> V_170 [ V_16 ] . V_44 ) )
V_46 ++ ;
}
}
return V_46 ;
}
static int F_102 ( struct V_18 * V_19 ,
T_1 V_166 ,
bool V_171 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_125 * V_126 = & V_2 -> V_127 ;
int type , V_16 , V_154 , V_46 , V_172 ;
unsigned int V_163 = F_98 ( V_19 , V_166 ) ;
unsigned int V_162 = F_100 ( V_163 ) ;
int V_144 = 0 ;
struct V_6 * V_50 ;
V_172 = V_2 -> V_129 ;
if ( V_172 >= 2 )
goto V_173;
V_46 = F_101 ( V_19 , V_166 ) ;
if ( V_46 < 2 )
goto V_173;
for ( type = V_167 ; type >= V_168 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_126 -> V_169 ; V_16 ++ ) {
T_1 V_48 = V_126 -> V_170 [ V_16 ] . V_44 ;
T_1 V_149 = 0 ;
if ( V_126 -> V_170 [ V_16 ] . type != type )
continue;
if ( ! F_97 ( V_19 , V_162 , V_48 ) )
continue;
for ( V_154 = 0 ; V_154 < V_2 -> V_129 ; V_154 ++ ) {
if ( V_48 == V_2 -> V_148 [ V_154 ] . V_44 )
break;
}
if ( V_154 < V_2 -> V_129 )
continue;
if ( V_171 )
V_149 = F_96 ( V_19 , V_48 ) ;
else if ( ! V_149 )
V_149 = F_44 ( V_19 , V_48 , false ) ;
if ( ! V_149 ) {
V_144 ++ ;
continue;
}
V_50 = F_42 ( V_19 , V_149 , V_48 ,
- V_2 -> V_43 ) ;
if ( ! V_50 ) {
V_144 ++ ;
continue;
}
V_2 -> V_148 [ V_2 -> V_129 ] . V_44 = V_48 ;
V_2 -> V_148 [ V_2 -> V_129 ] . V_149 = V_149 ;
V_2 -> V_174 [ V_126 -> V_128 + V_2 -> V_129 ] =
F_26 ( V_19 , V_50 ) ;
V_2 -> V_129 ++ ;
if ( V_2 -> V_129 >= 2 )
break;
}
}
V_173:
if ( V_144 )
V_144 = V_175 ;
if ( V_172 == V_2 -> V_129 ) {
if ( V_171 )
return 1 ;
else
return V_144 ;
}
if ( ! V_171 && V_2 -> V_129 < 2 ) {
V_2 -> V_5 . V_17 -= V_2 -> V_129 - V_172 ;
V_2 -> V_129 = V_172 ;
return V_144 ;
}
for ( V_16 = V_172 ; V_16 < V_2 -> V_129 ; V_16 ++ ) {
V_50 = F_27 ( V_19 , V_2 -> V_174 [ V_126 -> V_128 + V_16 ] ) ;
V_144 += F_92 ( V_19 , V_50 ) ;
}
return V_144 ;
}
static bool F_103 ( struct V_18 * V_19 , int V_176 ,
const T_1 * V_47 , T_1 * V_151 , int * V_110 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
bool V_65 = false ;
for ( V_16 = 0 ; V_16 < V_176 ; V_16 ++ ) {
struct V_6 * V_50 ;
T_1 V_149 ;
if ( V_151 [ V_16 ] )
continue;
V_149 = F_96 ( V_19 , V_47 [ V_16 ] ) ;
if ( ! V_149 )
continue;
V_50 = F_42 ( V_19 , V_149 , V_47 [ V_16 ] ,
- V_2 -> V_43 ) ;
if ( ! V_50 && ! V_16 && V_2 -> V_43 )
V_50 = F_42 ( V_19 , V_149 , V_47 [ V_16 ] , 0 ) ;
if ( V_50 ) {
V_151 [ V_16 ] = V_149 ;
V_65 = true ;
V_50 -> V_86 = true ;
V_110 [ V_16 ] = F_26 ( V_19 , V_50 ) ;
}
}
return V_65 ;
}
static int F_104 ( struct V_18 * V_19 , int V_110 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_50 ;
T_1 V_177 , V_149 , V_44 ;
V_50 = F_27 ( V_19 , V_110 ) ;
if ( ! V_50 || ! V_50 -> V_51 ||
F_22 ( V_50 , V_2 -> V_43 ) )
return 0 ;
V_177 = V_50 -> V_50 [ 0 ] ;
V_149 = V_2 -> V_147 [ 0 ] ;
V_44 = V_50 -> V_50 [ V_50 -> V_51 - 1 ] ;
V_50 = F_42 ( V_19 , V_149 , V_44 , V_2 -> V_43 ) ;
if ( ! V_50 ) {
if ( V_149 != V_177 )
V_149 = V_177 ;
else if ( V_2 -> V_134 . V_136 [ 0 ] )
V_149 = V_2 -> V_134 . V_136 [ 0 ] ;
else if ( V_2 -> V_134 . V_137 [ 0 ] )
V_149 = V_2 -> V_134 . V_137 [ 0 ] ;
else
V_149 = 0 ;
if ( V_149 )
V_50 = F_42 ( V_19 , V_149 , V_44 ,
V_2 -> V_43 ) ;
}
if ( ! V_50 )
return 0 ;
V_50 -> V_86 = false ;
return F_26 ( V_19 , V_50 ) ;
}
static bool F_105 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_125 * V_126 = & V_2 -> V_127 ;
struct V_6 * V_50 ;
int V_16 , V_56 ;
if ( V_126 -> V_139 == V_142 )
V_56 = V_2 -> V_174 [ 0 ] ;
else
V_56 = V_2 -> V_141 [ 0 ] ;
V_50 = F_27 ( V_19 , V_56 ) ;
if ( ! V_50 )
return false ;
if ( ! V_2 -> V_43 || ! F_22 ( V_50 , V_2 -> V_43 ) )
return true ;
for ( V_16 = 0 ; V_16 < V_126 -> V_128 ; V_16 ++ ) {
if ( V_2 -> V_174 [ V_16 ] == V_56 )
break;
V_50 = F_27 ( V_19 , V_2 -> V_174 [ V_16 ] ) ;
if ( V_50 && F_22 ( V_50 , V_2 -> V_43 ) )
return false ;
}
for ( V_16 = 0 ; V_16 < V_126 -> V_131 ; V_16 ++ ) {
V_50 = F_27 ( V_19 , V_2 -> V_143 [ V_16 ] ) ;
if ( V_50 && F_22 ( V_50 , V_2 -> V_43 ) )
return false ;
}
return true ;
}
static void F_106 ( struct V_18 * V_19 , int V_150 ,
T_1 * V_151 , int * V_110 )
{
struct V_6 * V_50 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_150 ; V_16 ++ ) {
if ( V_151 [ V_16 ] )
continue;
V_50 = F_27 ( V_19 , V_110 [ V_16 ] ) ;
if ( ! V_50 )
continue;
V_151 [ V_16 ] = V_50 -> V_50 [ 0 ] ;
}
}
static int F_107 ( struct V_18 * V_19 ,
bool V_178 ,
bool V_179 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_125 * V_126 = & V_2 -> V_127 ;
int V_16 , V_180 , V_144 ;
V_2 -> V_134 . V_135 = V_126 -> V_128 ;
V_2 -> V_134 . V_181 = V_2 -> V_147 ;
memset ( V_2 -> V_147 , 0 , sizeof( V_2 -> V_147 ) ) ;
memset ( V_2 -> V_134 . V_136 , 0 , sizeof( V_2 -> V_134 . V_136 ) ) ;
memset ( V_2 -> V_134 . V_137 , 0 , sizeof( V_2 -> V_134 . V_137 ) ) ;
V_2 -> V_129 = 0 ;
F_9 ( & V_2 -> V_5 ) ;
memset ( V_2 -> V_174 , 0 , sizeof( V_2 -> V_174 ) ) ;
memset ( V_2 -> V_141 , 0 , sizeof( V_2 -> V_141 ) ) ;
memset ( V_2 -> V_143 , 0 , sizeof( V_2 -> V_143 ) ) ;
memset ( V_2 -> V_182 , 0 , sizeof( V_2 -> V_182 ) ) ;
memset ( V_2 -> V_183 , 0 , sizeof( V_2 -> V_183 ) ) ;
memset ( V_2 -> V_184 , 0 , sizeof( V_2 -> V_184 ) ) ;
memset ( V_2 -> V_185 , 0 , sizeof( V_2 -> V_185 ) ) ;
memset ( & V_2 -> V_186 , 0 , sizeof( V_2 -> V_186 ) ) ;
V_144 = 0 ;
if ( V_178 ) {
bool V_187 ;
do {
V_187 = F_103 ( V_19 , V_126 -> V_128 ,
V_126 -> V_188 ,
V_2 -> V_147 ,
V_2 -> V_174 ) ;
V_187 |= F_103 ( V_19 , V_126 -> V_130 ,
V_126 -> V_189 ,
V_2 -> V_134 . V_136 ,
V_2 -> V_141 ) ;
V_187 |= F_103 ( V_19 , V_126 -> V_131 ,
V_126 -> V_190 ,
V_2 -> V_134 . V_137 ,
V_2 -> V_143 ) ;
if ( V_179 && V_126 -> V_128 == 1 &&
V_126 -> V_139 != V_140 ) {
V_180 = F_102 ( V_19 , V_126 -> V_188 [ 0 ] , true ) ;
if ( ! V_180 )
V_187 = true ;
}
} while ( V_187 );
}
V_144 += F_95 ( V_19 , V_126 -> V_128 , V_126 -> V_188 ,
V_2 -> V_147 , V_2 -> V_174 ,
V_2 -> V_191 ) ;
if ( V_179 &&
V_126 -> V_128 == 1 && V_126 -> V_139 != V_140 ) {
V_180 = F_102 ( V_19 , V_126 -> V_188 [ 0 ] , false ) ;
if ( V_180 < 0 )
return V_180 ;
}
if ( V_126 -> V_139 != V_142 ) {
V_180 = F_95 ( V_19 , V_126 -> V_130 , V_126 -> V_189 ,
V_2 -> V_134 . V_136 ,
V_2 -> V_141 ,
V_2 -> V_192 ) ;
if ( V_180 < 0 )
return V_180 ;
V_144 += V_180 ;
}
if ( V_126 -> V_139 != V_140 ) {
V_180 = F_95 ( V_19 , V_126 -> V_131 ,
V_126 -> V_190 ,
V_2 -> V_134 . V_137 ,
V_2 -> V_143 ,
V_2 -> V_192 ) ;
if ( V_180 < 0 )
return V_180 ;
V_144 += V_180 ;
}
if ( V_126 -> V_128 == 1 && V_126 -> V_139 != V_140 ) {
V_180 = F_102 ( V_19 , V_126 -> V_188 [ 0 ] , false ) ;
if ( V_180 < 0 )
return V_180 ;
V_144 += V_180 ;
}
if ( V_2 -> V_43 ) {
V_2 -> V_182 [ 0 ] =
F_104 ( V_19 , V_2 -> V_174 [ 0 ] ) ;
if ( V_126 -> V_139 != V_142 )
V_2 -> V_182 [ 1 ] =
F_104 ( V_19 , V_2 -> V_141 [ 0 ] ) ;
if ( V_126 -> V_139 != V_140 )
V_2 -> V_182 [ 2 ] =
F_104 ( V_19 , V_2 -> V_143 [ 0 ] ) ;
}
if ( V_126 -> V_130 && V_126 -> V_139 == V_140 )
if ( F_101 ( V_19 , V_126 -> V_189 [ 0 ] ) >= 2 )
V_2 -> V_129 = 1 ;
V_2 -> V_134 . V_135 = 0 ;
for ( V_16 = 0 ; V_16 < V_126 -> V_128 ; V_16 ++ ) {
if ( V_2 -> V_147 [ V_16 ] )
V_2 -> V_134 . V_135 ++ ;
else {
memmove ( V_2 -> V_147 + V_16 ,
V_2 -> V_147 + V_16 + 1 ,
sizeof( T_1 ) * ( V_126 -> V_128 - V_16 - 1 ) ) ;
V_2 -> V_147 [ V_126 -> V_128 - 1 ] = 0 ;
}
}
V_2 -> V_193 = V_2 -> V_194 =
V_2 -> V_134 . V_135 * 2 ;
if ( V_2 -> V_129 == 2 ) {
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
V_2 -> V_147 [ V_2 -> V_134 . V_135 ++ ] =
V_2 -> V_148 [ V_16 ] . V_149 ;
} else if ( V_2 -> V_129 ) {
V_2 -> V_129 = 0 ;
V_144 += V_175 ;
}
if ( V_2 -> V_37 && ! F_105 ( V_19 ) )
V_144 += V_195 ;
if ( V_126 -> V_139 != V_142 )
F_106 ( V_19 , V_126 -> V_130 ,
V_2 -> V_134 . V_136 ,
V_2 -> V_141 ) ;
if ( V_126 -> V_139 != V_140 )
F_106 ( V_19 , V_126 -> V_131 ,
V_2 -> V_134 . V_137 ,
V_2 -> V_143 ) ;
return V_144 ;
}
static inline void F_108 ( struct V_18 * V_19 ,
const char * V_60 , int V_56 )
{
struct V_6 * V_50 ;
V_50 = F_27 ( V_19 , V_56 ) ;
if ( V_50 )
F_34 ( V_60 , V_50 ) ;
}
static void F_109 ( struct V_18 * V_19 ,
struct V_125 * V_126 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_196 [ 3 ] = { L_34 , L_35 , L_36 } ;
int V_16 ;
F_110 ( L_37 ,
V_126 -> V_188 [ 0 ] , V_126 -> V_188 [ 1 ] ,
V_126 -> V_188 [ 2 ] , V_126 -> V_188 [ 3 ] ,
V_2 -> V_134 . V_181 [ 0 ] ,
V_2 -> V_134 . V_181 [ 1 ] ,
V_2 -> V_134 . V_181 [ 2 ] ,
V_2 -> V_134 . V_181 [ 3 ] ,
V_196 [ V_126 -> V_139 ] ) ;
for ( V_16 = 0 ; V_16 < V_126 -> V_128 ; V_16 ++ )
F_108 ( V_19 , L_38 , V_2 -> V_174 [ V_16 ] ) ;
if ( V_2 -> V_129 > 0 )
F_110 ( L_39 ,
V_2 -> V_129 ,
V_2 -> V_148 [ 0 ] . V_44 , V_2 -> V_148 [ 1 ] . V_44 ,
V_2 -> V_148 [ 0 ] . V_149 , V_2 -> V_148 [ 1 ] . V_149 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_129 ; V_16 ++ )
F_108 ( V_19 , L_40 ,
V_2 -> V_174 [ V_126 -> V_128 + V_16 ] ) ;
if ( V_126 -> V_130 )
F_110 ( L_41 ,
V_126 -> V_189 [ 0 ] , V_126 -> V_189 [ 1 ] ,
V_126 -> V_189 [ 2 ] , V_126 -> V_189 [ 3 ] ,
V_2 -> V_134 . V_136 [ 0 ] ,
V_2 -> V_134 . V_136 [ 1 ] ,
V_2 -> V_134 . V_136 [ 2 ] ,
V_2 -> V_134 . V_136 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_126 -> V_130 ; V_16 ++ )
F_108 ( V_19 , L_42 , V_2 -> V_141 [ V_16 ] ) ;
if ( V_126 -> V_131 )
F_110 ( L_43 ,
V_126 -> V_190 [ 0 ] , V_126 -> V_190 [ 1 ] ,
V_126 -> V_190 [ 2 ] , V_126 -> V_190 [ 3 ] ,
V_2 -> V_134 . V_137 [ 0 ] ,
V_2 -> V_134 . V_137 [ 1 ] ,
V_2 -> V_134 . V_137 [ 2 ] ,
V_2 -> V_134 . V_137 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_126 -> V_131 ; V_16 ++ )
F_108 ( V_19 , L_44 , V_2 -> V_143 [ V_16 ] ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ )
F_108 ( V_19 , L_45 , V_2 -> V_182 [ V_16 ] ) ;
}
static void F_111 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_48 = V_19 -> V_197 ;
V_2 -> V_73 = 0 ;
memset ( V_2 -> V_74 , 0 , sizeof( V_2 -> V_74 ) ) ;
for ( V_16 = 0 ; V_16 < V_19 -> V_198 ; V_16 ++ , V_48 ++ ) {
if ( F_39 ( F_40 ( V_19 , V_48 ) ) != V_64 )
continue;
if ( V_2 -> V_73 >= F_90 ( V_2 -> V_74 ) ) {
F_112 ( V_199 L_46 ) ;
break;
}
V_2 -> V_74 [ V_2 -> V_73 ++ ] = V_48 ;
}
}
static int F_113 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_125 * V_126 = & V_2 -> V_127 ;
struct V_125 * V_200 ;
unsigned int V_20 ;
int V_201 = V_202 ;
int V_144 ;
bool V_178 = true , V_179 = true ;
bool V_203 = true , V_204 = true ;
bool V_205 = false ;
V_200 = F_114 ( sizeof( * V_200 ) , V_13 ) ;
if ( ! V_200 )
return - V_118 ;
* V_200 = * V_126 ;
for (; ; ) {
V_144 = F_107 ( V_19 , V_178 ,
V_179 ) ;
if ( V_144 < 0 ) {
F_8 ( V_200 ) ;
return V_144 ;
}
F_110 ( L_47 ,
V_126 -> V_139 , V_178 , V_179 ,
V_144 ) ;
F_109 ( V_19 , V_126 ) ;
if ( V_144 < V_201 ) {
V_201 = V_144 ;
* V_200 = * V_126 ;
V_203 = V_178 ;
V_204 = V_179 ;
}
if ( ! V_144 )
break;
V_179 = ! V_179 ;
if ( ! V_179 )
continue;
V_178 = ! V_178 ;
if ( ! V_178 )
continue;
if ( V_205 )
break;
V_205 = true ;
if ( V_126 -> V_131 > 0 &&
V_126 -> V_139 == V_142 ) {
V_126 -> V_130 = V_126 -> V_128 ;
memcpy ( V_126 -> V_189 , V_126 -> V_188 ,
sizeof( V_126 -> V_189 ) ) ;
V_126 -> V_128 = V_126 -> V_131 ;
memcpy ( V_126 -> V_188 , V_126 -> V_190 ,
sizeof( V_126 -> V_190 ) ) ;
V_126 -> V_131 = 0 ;
memset ( V_126 -> V_190 , 0 , sizeof( V_126 -> V_190 ) ) ;
V_126 -> V_139 = V_140 ;
V_178 = true ;
continue;
}
if ( V_126 -> V_130 > 0 &&
V_126 -> V_139 == V_140 ) {
V_126 -> V_131 = V_126 -> V_128 ;
memcpy ( V_126 -> V_190 , V_126 -> V_188 ,
sizeof( V_126 -> V_190 ) ) ;
V_126 -> V_128 = V_126 -> V_130 ;
memcpy ( V_126 -> V_188 , V_126 -> V_189 ,
sizeof( V_126 -> V_189 ) ) ;
V_126 -> V_130 = 0 ;
memset ( V_126 -> V_189 , 0 , sizeof( V_126 -> V_189 ) ) ;
V_126 -> V_139 = V_142 ;
V_178 = true ;
continue;
}
break;
}
if ( V_144 ) {
F_110 ( L_48 ) ;
* V_126 = * V_200 ;
F_107 ( V_19 , V_203 , V_204 ) ;
}
F_110 ( L_49 ,
V_126 -> V_139 , V_203 , V_204 ) ;
F_109 ( V_19 , V_126 ) ;
if ( V_126 -> V_188 [ 0 ] ) {
struct V_6 * V_50 ;
V_50 = F_27 ( V_19 , V_2 -> V_174 [ 0 ] ) ;
if ( V_50 )
V_2 -> V_206 = F_51 ( V_19 , V_50 ) ;
if ( V_2 -> V_206 )
F_115 ( V_19 , V_2 -> V_206 ,
V_80 , V_2 -> V_207 ) ;
}
if ( V_2 -> V_208 || V_126 -> V_139 == V_142 )
V_20 = V_209 ;
else
V_20 = V_210 ;
F_20 ( V_19 , V_126 -> V_128 , V_126 -> V_188 , V_20 ) ;
if ( V_126 -> V_139 != V_142 )
F_20 ( V_19 , V_126 -> V_130 , V_126 -> V_189 , V_209 ) ;
if ( V_126 -> V_139 != V_140 ) {
V_20 = V_2 -> V_208 ? V_209 : V_210 ;
F_20 ( V_19 , V_126 -> V_131 ,
V_126 -> V_190 , V_20 ) ;
}
if ( V_2 -> V_37 && ! F_105 ( V_19 ) )
V_2 -> V_37 = 0 ;
F_8 ( V_200 ) ;
return 0 ;
}
static int F_116 ( struct V_18 * V_19 ,
const struct V_125 * V_126 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_180 , V_211 ;
V_211 = V_126 -> V_128 ;
if ( V_2 -> V_129 > 0 && V_126 -> V_128 < 3 )
V_211 += V_2 -> V_129 ;
for ( V_16 = 0 ; V_16 < V_211 ; V_16 ++ ) {
const char * V_10 ;
int V_113 ;
struct V_6 * V_50 ;
V_50 = F_27 ( V_19 , V_2 -> V_174 [ V_16 ] ) ;
if ( ! V_50 )
continue;
V_10 = F_89 ( V_19 , V_16 , & V_113 , V_95 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_50 ) ) {
V_180 = F_79 ( V_19 , L_51 , 0 , 1 , V_50 ) ;
if ( V_180 < 0 )
return V_180 ;
V_180 = F_79 ( V_19 , L_52 , 0 , 2 , V_50 ) ;
if ( V_180 < 0 )
return V_180 ;
} else {
V_180 = F_82 ( V_19 , V_10 , V_113 , V_50 ) ;
if ( V_180 < 0 )
return V_180 ;
}
V_10 = F_89 ( V_19 , V_16 , & V_113 , V_94 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_50 ) ) {
V_180 = F_83 ( V_19 , L_51 , 0 , 1 , V_50 ) ;
if ( V_180 < 0 )
return V_180 ;
V_180 = F_83 ( V_19 , L_52 , 0 , 2 , V_50 ) ;
if ( V_180 < 0 )
return V_180 ;
} else {
V_180 = F_87 ( V_19 , V_10 , V_113 , V_50 ) ;
if ( V_180 < 0 )
return V_180 ;
}
}
return 0 ;
}
static int F_117 ( struct V_18 * V_19 , int V_110 ,
const char * V_60 , int V_111 )
{
struct V_6 * V_50 ;
int V_180 ;
V_50 = F_27 ( V_19 , V_110 ) ;
if ( ! V_50 )
return 0 ;
V_180 = F_82 ( V_19 , V_60 , V_111 , V_50 ) ;
if ( V_180 < 0 )
return V_180 ;
V_180 = F_87 ( V_19 , V_60 , V_111 , V_50 ) ;
if ( V_180 < 0 )
return V_180 ;
return 0 ;
}
static int F_118 ( struct V_18 * V_19 , int V_46 ,
const int * V_5 , const char * V_60 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_46 ; V_16 ++ ) {
const char * V_10 ;
char V_62 [ 44 ] ;
int V_180 , V_56 = 0 ;
if ( V_46 == 2 && V_16 == 1 && ! strcmp ( V_60 , L_31 ) )
V_10 = L_32 ;
else if ( V_46 >= 3 ) {
snprintf ( V_62 , sizeof( V_62 ) , L_53 ,
V_60 , V_138 [ V_16 ] ) ;
V_10 = V_62 ;
} else {
V_10 = V_60 ;
V_56 = V_16 ;
}
V_180 = F_117 ( V_19 , V_5 [ V_16 ] , V_10 , V_56 ) ;
if ( V_180 < 0 )
return V_180 ;
}
return 0 ;
}
static int F_119 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_118 ( V_19 , V_2 -> V_127 . V_130 ,
V_2 -> V_141 ,
L_33 ) ;
}
static int F_120 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_118 ( V_19 , V_2 -> V_127 . V_131 ,
V_2 -> V_143 ,
L_31 ) ;
}
static int F_121 ( struct V_212 * V_213 ,
struct V_214 * V_215 )
{
return F_122 ( V_213 , V_215 ) ;
}
static int F_123 ( struct V_212 * V_213 ,
struct V_216 * V_217 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_217 -> V_218 . V_219 . V_220 [ 0 ] = V_2 -> V_221 ;
return 0 ;
}
static int F_125 ( struct V_212 * V_213 ,
struct V_216 * V_217 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_222 = V_217 -> V_218 . V_219 . V_220 [ 0 ] ;
int V_223 = 0 ;
F_126 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_224 ) {
V_223 = - V_225 ;
goto V_226;
}
if ( V_2 -> V_221 != V_222 ) {
T_1 * V_227 ;
if ( V_2 -> V_127 . V_139 == V_142 )
V_227 = & V_2 -> V_147 [ 0 ] ;
else
V_227 = & V_2 -> V_134 . V_136 [ 0 ] ;
if ( V_2 -> V_228 ) {
if ( V_2 -> V_127 . V_139 == V_142 )
F_127 ( V_19 , V_2 -> V_229 ,
V_2 -> V_174 [ 0 ] ,
V_2 -> V_182 [ 0 ] ,
V_2 -> V_127 . V_139 ) ;
else
F_127 ( V_19 , V_2 -> V_229 ,
V_2 -> V_141 [ 0 ] ,
V_2 -> V_182 [ 1 ] ,
V_142 ) ;
}
V_2 -> V_221 = V_222 ;
if ( V_2 -> V_221 )
* V_227 = 0 ;
else
* V_227 = V_2 -> V_230 ;
F_128 ( V_19 , NULL ) ;
V_223 = 1 ;
}
V_226:
F_129 ( & V_2 -> V_9 ) ;
return V_223 ;
}
static int F_130 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_149 ;
if ( ! V_2 -> V_37 )
return 0 ;
if ( V_2 -> V_127 . V_139 == V_142 )
V_149 = V_2 -> V_134 . V_181 [ 0 ] ;
else
V_149 = V_2 -> V_134 . V_136 [ 0 ] ;
if ( ! V_149 ) {
V_2 -> V_37 = 0 ;
return 0 ;
}
V_2 -> V_221 = false ;
V_2 -> V_230 = V_149 ;
if ( ! F_4 ( V_2 , NULL , & V_231 ) )
return - V_118 ;
return 0 ;
}
static int F_131 ( struct V_212 * V_213 ,
struct V_214 * V_215 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_76 ;
V_215 -> type = V_232 ;
V_215 -> V_233 = 1 ;
V_215 -> V_218 . V_219 . V_234 = V_2 -> V_129 + 1 ;
if ( V_215 -> V_218 . V_219 . V_220 > V_2 -> V_129 )
V_215 -> V_218 . V_219 . V_220 = V_2 -> V_129 ;
V_76 = V_215 -> V_218 . V_219 . V_220 * 2 + V_2 -> V_194 ;
sprintf ( V_215 -> V_218 . V_219 . V_10 , L_54 , V_76 ) ;
return 0 ;
}
static int F_132 ( struct V_212 * V_213 ,
struct V_216 * V_217 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_217 -> V_218 . V_219 . V_220 [ 0 ] =
( V_2 -> V_193 - V_2 -> V_194 ) / 2 ;
return 0 ;
}
static inline struct V_6 *
F_133 ( struct V_18 * V_19 , int V_56 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_27 ( V_19 ,
V_2 -> V_174 [ V_2 -> V_127 . V_128 + V_56 ] ) ;
}
static bool F_134 ( struct V_1 * V_2 )
{
return ! V_2 -> V_228 || V_2 -> V_229 ;
}
static int F_135 ( struct V_18 * V_19 , int V_56 , bool V_235 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_48 = V_2 -> V_148 [ V_56 ] . V_44 ;
struct V_6 * V_50 ;
V_50 = F_133 ( V_19 , V_56 ) ;
if ( ! V_50 )
return - V_236 ;
if ( V_50 -> V_86 == V_235 )
return 0 ;
if ( V_235 ) {
F_17 ( V_19 , V_48 , V_210 , true ) ;
F_64 ( V_19 , V_50 , true , F_134 ( V_2 ) ) ;
F_72 ( V_19 , V_48 , true ) ;
} else {
F_72 ( V_19 , V_48 , false ) ;
F_64 ( V_19 , V_50 , false , F_134 ( V_2 ) ) ;
F_17 ( V_19 , V_48 , V_2 -> V_148 [ V_56 ] . V_237 , true ) ;
F_68 ( V_19 , V_50 ) ;
}
F_136 ( V_19 ) ;
return 0 ;
}
static int F_137 ( struct V_212 * V_213 ,
struct V_216 * V_217 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_124 ;
V_124 = V_217 -> V_218 . V_219 . V_220 [ 0 ] ;
if ( V_124 < 0 || V_124 > V_2 -> V_129 )
return - V_236 ;
if ( V_124 == ( V_2 -> V_193 - V_2 -> V_194 ) / 2 )
return 0 ;
V_2 -> V_193 = V_124 * 2 + V_2 -> V_194 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_129 ; V_16 ++ )
F_135 ( V_19 , V_16 , V_16 < V_124 ) ;
V_2 -> V_134 . V_238 = F_138 ( V_2 -> V_193 ,
V_2 -> V_239 ) ;
if ( V_2 -> V_33 )
V_2 -> V_134 . V_135 = V_2 -> V_134 . V_238 / 2 ;
return 1 ;
}
static int F_139 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_129 > 0 ) {
if ( ! F_4 ( V_2 , NULL , & V_240 ) )
return - V_118 ;
}
return 0 ;
}
static int F_140 ( struct V_212 * V_213 ,
struct V_216 * V_217 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_217 -> V_218 . V_219 . V_220 [ 0 ] = V_2 -> V_229 ;
return 0 ;
}
static void F_127 ( struct V_18 * V_19 , bool V_241 ,
int V_242 , int V_243 ,
int V_244 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_245 , * V_246 ;
V_245 = F_27 ( V_19 , V_242 ) ;
V_246 = F_27 ( V_19 , V_243 ) ;
if ( ! V_245 || ! V_246 )
return;
if ( V_244 == V_142 && V_2 -> V_221 &&
V_246 -> V_50 [ 0 ] != V_2 -> V_230 )
V_241 = false ;
if ( V_241 ) {
F_64 ( V_19 , V_245 , false , true ) ;
F_64 ( V_19 , V_246 , true , true ) ;
F_68 ( V_19 , V_245 ) ;
} else {
F_64 ( V_19 , V_246 , false , false ) ;
F_64 ( V_19 , V_245 , true , false ) ;
F_68 ( V_19 , V_246 ) ;
}
}
static int F_141 ( struct V_212 * V_213 ,
struct V_216 * V_217 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = V_217 -> V_218 . V_219 . V_220 [ 0 ] ;
if ( V_20 == V_2 -> V_229 )
return 0 ;
V_2 -> V_229 = V_20 ;
F_127 ( V_19 , V_20 , V_2 -> V_174 [ 0 ] ,
V_2 -> V_182 [ 0 ] ,
V_2 -> V_127 . V_139 ) ;
F_127 ( V_19 , V_20 , V_2 -> V_141 [ 0 ] ,
V_2 -> V_182 [ 1 ] ,
V_142 ) ;
F_127 ( V_19 , V_20 , V_2 -> V_143 [ 0 ] ,
V_2 -> V_182 [ 2 ] ,
V_140 ) ;
return 1 ;
}
static int F_142 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_43 )
return 0 ;
if ( ! ( V_2 -> V_182 [ 0 ] || V_2 -> V_182 [ 1 ] ||
V_2 -> V_182 [ 2 ] ) )
return 0 ;
if ( ! F_4 ( V_2 , NULL , & V_247 ) )
return - V_118 ;
V_2 -> V_228 = 1 ;
return 0 ;
}
static void F_143 ( struct V_18 * V_19 , int V_248 , bool V_249 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_250 ;
unsigned int V_20 ;
T_1 V_44 ;
V_44 = V_2 -> V_251 ;
V_250 = V_2 -> V_252 [ V_248 ] == V_2 -> V_253 ;
if ( ! V_249 ) {
V_20 = F_16 ( V_19 , V_44 ) ;
if ( V_250 ) {
if ( V_20 & V_254 )
return;
} else {
if ( V_20 & V_210 )
return;
}
}
V_20 = F_144 ( V_19 , V_44 ) ;
if ( V_20 == V_255 && V_2 -> V_256 ) {
const T_1 V_257 = V_2 -> V_256 ;
unsigned int V_258 = F_144 ( V_19 , V_257 ) ;
if ( V_258 != V_255 )
F_145 ( V_19 , V_257 ,
V_254 | ( V_250 ? V_258 : 0 ) ) ;
}
if ( ! V_2 -> V_259 ) {
if ( V_250 )
V_20 |= V_254 ;
else
V_20 = V_209 ;
F_17 ( V_19 , V_44 , V_20 , true ) ;
F_128 ( V_19 , NULL ) ;
}
}
static int F_146 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_125 * V_126 = & V_2 -> V_127 ;
unsigned int V_163 ;
T_1 V_48 ;
if ( ! V_2 -> V_41 ) {
if ( V_2 -> V_42 )
return 0 ;
if ( V_126 -> V_169 > 1 )
return 0 ;
else if ( V_126 -> V_169 == 1 ) {
V_163 = F_98 ( V_19 , V_126 -> V_170 [ 0 ] . V_44 ) ;
if ( F_147 ( V_163 ) != V_260 )
return 0 ;
}
}
V_2 -> V_41 = 0 ;
if ( V_126 -> V_169 >= V_261 )
return 0 ;
V_48 = 0 ;
if ( V_126 -> V_139 == V_142 && V_126 -> V_128 > 0 )
V_48 = V_126 -> V_188 [ 0 ] ;
else if ( V_126 -> V_130 > 0 )
V_48 = V_126 -> V_189 [ 0 ] ;
if ( ! V_48 )
return 0 ;
if ( ! ( F_73 ( V_19 , V_48 ) & V_262 ) )
return 0 ;
V_126 -> V_170 [ V_126 -> V_169 ] . V_44 = V_48 ;
V_126 -> V_170 [ V_126 -> V_169 ] . type = V_168 ;
V_126 -> V_170 [ V_126 -> V_169 ] . V_263 = 1 ;
V_126 -> V_169 ++ ;
V_2 -> V_41 = 1 ;
V_2 -> V_251 = V_48 ;
V_2 -> V_31 = 1 ;
F_36 ( L_55 , V_48 ) ;
return 0 ;
}
static int F_148 ( struct V_212 * V_213 ,
struct V_214 * V_215 )
{
return F_149 ( V_213 , V_215 , 2 , V_264 ) ;
}
static int F_150 ( struct V_212 * V_213 ,
struct V_216 * V_217 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
T_1 V_48 = V_213 -> V_116 ;
if ( F_16 ( V_19 , V_48 ) == V_209 )
V_217 -> V_218 . V_219 . V_220 [ 0 ] = 1 ;
else
V_217 -> V_218 . V_219 . V_220 [ 0 ] = 0 ;
return 0 ;
}
static int F_151 ( struct V_212 * V_213 ,
struct V_216 * V_217 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
T_1 V_48 = V_213 -> V_116 ;
unsigned int V_20 ;
V_20 = V_217 -> V_218 . V_219 . V_220 [ 0 ] ? V_209 : V_210 ;
if ( F_16 ( V_19 , V_48 ) == V_20 )
return 0 ;
F_145 ( V_19 , V_48 , V_20 ) ;
return 1 ;
}
static bool F_152 ( struct V_18 * V_19 , const char * V_10 , int V_56 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_3 . V_17 ; V_16 ++ ) {
struct V_4 * V_15 = F_24 ( & V_2 -> V_3 , V_16 ) ;
if ( ! strcmp ( V_15 -> V_10 , V_10 ) && V_15 -> V_113 == V_56 )
return true ;
}
return false ;
}
static void F_153 ( struct V_18 * V_19 , T_1 V_44 ,
char * V_10 , T_3 V_265 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_56 = 0 ;
F_154 ( V_19 , V_44 , & V_2 -> V_127 , V_10 , V_265 , & V_56 ) ;
F_35 ( V_10 , L_56 , V_265 ) ;
for (; F_152 ( V_19 , V_10 , V_56 ) ; V_56 ++ )
;
}
static int F_155 ( struct V_18 * V_19 , T_1 V_44 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_39 ) {
unsigned int V_266 = F_73 ( V_19 , V_44 ) ;
if ( ( V_266 & V_165 ) && ( V_266 & V_267 ) )
return 2 ;
}
return 1 ;
}
static int F_156 ( struct V_18 * V_19 , int V_46 ,
T_1 * V_47 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_46 ; V_16 ++ ) {
T_1 V_44 = V_47 [ V_16 ] ;
if ( V_44 == V_2 -> V_251 ) {
int V_223 = F_157 ( V_19 , V_44 ) ;
if ( V_223 < 0 )
return V_223 ;
continue;
}
if ( F_155 ( V_19 , V_44 ) > 1 ) {
struct V_4 * V_12 ;
char V_10 [ 44 ] ;
F_153 ( V_19 , V_44 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 ,
& V_268 ) ;
if ( ! V_12 )
return - V_118 ;
V_12 -> V_116 = V_44 ;
}
}
return 0 ;
}
static unsigned int F_158 ( struct V_18 * V_19 , T_1 V_44 )
{
unsigned int V_266 ;
V_266 = F_73 ( V_19 , V_44 ) ;
V_266 = ( V_266 & V_269 ) >> V_270 ;
V_266 &= ~ ( V_271 | V_272 ) ;
return V_266 ;
}
static int F_159 ( unsigned int V_273 , unsigned int V_274 )
{
unsigned int V_16 , V_85 = 0 ;
for ( V_16 = 0 ; V_16 < V_275 ; V_16 ++ ) {
if ( V_273 & ( 1 << V_16 ) ) {
if ( V_85 == V_274 )
return V_16 ;
V_85 ++ ;
}
}
return 0 ;
}
static int F_160 ( unsigned int V_273 , unsigned int V_56 )
{
unsigned int V_16 , V_85 = 0 ;
for ( V_16 = 0 ; V_16 < V_275 ; V_16 ++ ) {
if ( V_16 == V_56 )
return V_85 ;
if ( V_273 & ( 1 << V_16 ) )
V_85 ++ ;
}
return 0 ;
}
static int F_161 ( struct V_212 * V_213 ,
struct V_214 * V_215 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
T_1 V_48 = V_213 -> V_116 ;
unsigned int V_273 = F_158 ( V_19 , V_48 ) ;
F_149 ( V_213 , V_215 , F_162 ( V_273 ) ,
V_276 ) ;
strcpy ( V_215 -> V_218 . V_219 . V_10 ,
V_276 [ F_159 ( V_273 , V_215 -> V_218 . V_219 . V_220 ) ] ) ;
return 0 ;
}
static int F_163 ( struct V_212 * V_213 ,
struct V_216 * V_217 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
T_1 V_48 = V_213 -> V_116 ;
unsigned int V_273 = F_158 ( V_19 , V_48 ) ;
unsigned int V_56 ;
V_56 = F_16 ( V_19 , V_48 ) & V_277 ;
V_217 -> V_218 . V_219 . V_220 [ 0 ] = F_160 ( V_273 , V_56 ) ;
return 0 ;
}
static int F_164 ( struct V_212 * V_213 ,
struct V_216 * V_217 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
T_1 V_48 = V_213 -> V_116 ;
unsigned int V_273 = F_158 ( V_19 , V_48 ) ;
unsigned int V_20 , V_56 ;
V_20 = F_16 ( V_19 , V_48 ) ;
V_56 = F_160 ( V_273 , V_20 & V_277 ) ;
if ( V_56 == V_217 -> V_218 . V_219 . V_220 [ 0 ] )
return 0 ;
V_20 &= ~ V_277 ;
V_20 |= F_159 ( V_273 , V_217 -> V_218 . V_219 . V_220 [ 0 ] ) ;
F_145 ( V_19 , V_48 , V_20 ) ;
return 1 ;
}
static int F_165 ( struct V_18 * V_19 , T_1 V_44 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_278 = 0 ;
if ( V_2 -> V_39 )
V_278 = F_162 ( F_158 ( V_19 , V_44 ) ) ;
return V_278 ? V_278 : 1 ;
}
static int F_166 ( struct V_18 * V_19 , T_1 V_44 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
char V_10 [ 44 ] ;
unsigned int V_163 ;
if ( V_44 == V_2 -> V_251 )
return 0 ;
V_163 = F_98 ( V_19 , V_44 ) ;
if ( F_147 ( V_163 ) == V_260 )
return 0 ;
if ( F_165 ( V_19 , V_44 ) <= 1 )
return 0 ;
F_153 ( V_19 , V_44 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 , & V_279 ) ;
if ( ! V_12 )
return - V_118 ;
V_12 -> V_116 = V_44 ;
return 0 ;
}
static int F_167 ( struct V_212 * V_213 ,
struct V_214 * V_215 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
T_1 V_48 = V_213 -> V_116 ;
int V_280 = F_155 ( V_19 , V_48 ) ;
int V_281 = F_165 ( V_19 , V_48 ) ;
const char * V_282 = NULL ;
int V_56 ;
V_215 -> type = V_232 ;
V_215 -> V_233 = 1 ;
V_215 -> V_218 . V_219 . V_234 = V_280 + V_281 ;
if ( V_215 -> V_218 . V_219 . V_220 >= V_215 -> V_218 . V_219 . V_234 )
V_215 -> V_218 . V_219 . V_220 = V_215 -> V_218 . V_219 . V_234 - 1 ;
V_56 = V_215 -> V_218 . V_219 . V_220 ;
if ( V_56 < V_280 ) {
if ( V_280 > 1 )
V_282 = V_264 [ V_56 ] ;
else
V_282 = L_57 ;
} else {
V_56 -= V_280 ;
if ( V_281 > 1 ) {
unsigned int V_273 = F_158 ( V_19 , V_48 ) ;
V_282 = V_276 [ F_159 ( V_273 , V_56 ) ] ;
} else
V_282 = L_58 ;
}
strcpy ( V_215 -> V_218 . V_219 . V_10 , V_282 ) ;
return 0 ;
}
static int F_168 ( struct V_18 * V_19 , T_1 V_48 )
{
int V_280 = F_155 ( V_19 , V_48 ) ;
int V_281 = F_165 ( V_19 , V_48 ) ;
unsigned int V_20 = F_16 ( V_19 , V_48 ) ;
int V_56 = 0 ;
if ( V_20 & V_210 ) {
if ( V_280 > 1 && V_20 == V_209 )
V_56 = 1 ;
} else if ( V_20 & V_254 ) {
V_56 = V_280 ;
if ( V_281 > 1 ) {
unsigned int V_273 = F_158 ( V_19 , V_48 ) ;
V_20 &= V_277 ;
V_56 += F_160 ( V_273 , V_20 ) ;
}
}
return V_56 ;
}
static int F_169 ( struct V_212 * V_213 ,
struct V_216 * V_217 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
T_1 V_48 = V_213 -> V_116 ;
V_217 -> V_218 . V_219 . V_220 [ 0 ] =
F_168 ( V_19 , V_48 ) ;
return 0 ;
}
static int F_170 ( struct V_212 * V_213 ,
struct V_216 * V_217 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
T_1 V_48 = V_213 -> V_116 ;
int V_280 = F_155 ( V_19 , V_48 ) ;
int V_281 = F_165 ( V_19 , V_48 ) ;
unsigned int V_20 , V_283 , V_56 ;
V_283 = F_168 ( V_19 , V_48 ) ;
V_56 = V_217 -> V_218 . V_219 . V_220 [ 0 ] ;
if ( V_283 == V_56 )
return 0 ;
if ( V_56 < V_280 ) {
if ( V_280 > 1 )
V_20 = V_56 ? V_209 : V_210 ;
else
V_20 = V_209 ;
} else {
V_56 -= V_280 ;
if ( V_281 > 1 ) {
unsigned int V_273 = F_158 ( V_19 , V_48 ) ;
V_20 = F_16 ( V_19 , V_48 ) ;
V_20 &= ~ ( V_277 | V_209 ) ;
V_20 |= F_159 ( V_273 , V_56 ) | V_254 ;
} else
V_20 = F_144 ( V_19 , V_48 ) ;
}
F_145 ( V_19 , V_48 , V_20 ) ;
F_128 ( V_19 , NULL ) ;
return 1 ;
}
static int F_157 ( struct V_18 * V_19 , T_1 V_44 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
if ( F_155 ( V_19 , V_44 ) <= 1 &&
F_165 ( V_19 , V_44 ) <= 1 )
return 0 ;
V_12 = F_4 ( V_2 , L_59 ,
& V_284 ) ;
if ( ! V_12 )
return - V_118 ;
V_12 -> V_116 = V_44 ;
V_2 -> V_259 = 1 ;
return 0 ;
}
static int F_171 ( struct V_1 * V_2 , T_1 V_285 , int V_56 )
{
struct V_8 * V_14 ;
V_14 = F_5 ( & V_2 -> V_7 ) ;
if ( ! V_14 )
return - V_118 ;
V_14 -> V_48 = V_285 ;
V_14 -> V_59 = V_81 ;
V_14 -> V_56 = V_56 ;
V_2 -> V_286 . V_287 = V_2 -> V_7 . V_14 ;
return 0 ;
}
static int F_172 ( struct V_18 * V_19 , int V_288 ,
T_1 V_44 , const char * V_289 , int V_290 ,
T_1 V_291 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_50 ;
unsigned int V_20 ;
int V_180 , V_56 ;
if ( ! F_52 ( V_19 , V_291 , V_81 ) &&
! F_50 ( V_19 , V_291 , V_81 ) )
return 0 ;
V_50 = F_42 ( V_19 , V_44 , V_291 , 0 ) ;
if ( ! V_50 )
return - V_236 ;
F_34 ( L_60 , V_50 ) ;
V_2 -> V_185 [ V_288 ] = F_26 ( V_19 , V_50 ) ;
V_56 = V_50 -> V_56 [ V_50 -> V_51 - 1 ] ;
if ( F_52 ( V_19 , V_291 , V_81 ) ) {
V_20 = F_33 ( V_291 , 3 , V_56 , V_81 ) ;
V_180 = F_80 ( V_2 , V_119 , V_289 , V_290 , V_20 ) ;
if ( V_180 < 0 )
return V_180 ;
V_50 -> V_58 [ V_95 ] = V_20 ;
}
if ( F_50 ( V_19 , V_291 , V_81 ) ) {
V_20 = F_33 ( V_291 , 3 , V_56 , V_81 ) ;
V_180 = F_86 ( V_2 , V_121 , V_289 , V_290 , V_20 ) ;
if ( V_180 < 0 )
return V_180 ;
V_50 -> V_58 [ V_94 ] = V_20 ;
}
V_50 -> V_86 = true ;
V_180 = F_171 ( V_2 , V_291 , V_56 ) ;
if ( V_180 < 0 )
return V_180 ;
if ( V_2 -> V_43 != V_2 -> V_99 &&
! V_2 -> V_292 ) {
V_50 = F_42 ( V_19 , V_2 -> V_43 ,
V_2 -> V_99 , 0 ) ;
if ( V_50 ) {
F_34 ( L_61 , V_50 ) ;
V_50 -> V_86 = true ;
V_2 -> V_292 =
F_26 ( V_19 , V_50 ) ;
}
}
return 0 ;
}
static int F_173 ( struct V_18 * V_19 , T_1 V_48 )
{
unsigned int V_266 = F_73 ( V_19 , V_48 ) ;
return ( V_266 & V_262 ) != 0 ;
}
static int F_174 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_48 ;
T_1 * V_293 = V_2 -> V_293 ;
int V_294 = F_90 ( V_2 -> V_293 ) ;
int V_16 , V_49 = 0 ;
V_48 = V_19 -> V_197 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_198 ; V_16 ++ , V_48 ++ ) {
unsigned int V_82 = F_40 ( V_19 , V_48 ) ;
int type = F_39 ( V_82 ) ;
if ( type != V_67 || ( V_82 & V_75 ) )
continue;
V_293 [ V_49 ] = V_48 ;
if ( ++ V_49 >= V_294 )
break;
}
V_2 -> V_295 = V_49 ;
V_2 -> V_296 = V_49 ;
memcpy ( V_2 -> V_297 , V_2 -> V_293 , V_49 * sizeof( T_1 ) ) ;
return V_49 ;
}
static int F_175 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_298 * V_299 = & V_2 -> V_300 ;
unsigned int V_301 ;
int V_16 , V_85 , V_49 ;
V_49 = 0 ;
V_301 = 0 ;
for ( V_85 = 0 ; V_85 < V_2 -> V_295 ; V_85 ++ ) {
for ( V_16 = 0 ; V_16 < V_299 -> V_302 ; V_16 ++ ) {
if ( ! V_2 -> V_184 [ V_16 ] [ V_85 ] )
break;
}
if ( V_16 >= V_299 -> V_302 ) {
V_301 |= ( 1 << V_85 ) ;
V_49 ++ ;
}
}
if ( ! V_301 ) {
for ( V_16 = 0 ; V_16 < V_299 -> V_302 ; V_16 ++ ) {
for ( V_85 = 0 ; V_85 < V_2 -> V_295 ; V_85 ++ ) {
if ( V_2 -> V_184 [ V_16 ] [ V_85 ] ) {
V_2 -> V_303 [ V_16 ] = V_85 ;
break;
}
}
}
F_36 ( L_62 ) ;
V_2 -> V_304 = 1 ;
} else if ( V_49 != V_2 -> V_295 ) {
V_49 = 0 ;
for ( V_85 = 0 ; V_85 < V_2 -> V_295 ; V_85 ++ ) {
if ( ! ( V_301 & ( 1 << V_85 ) ) )
continue;
if ( V_85 != V_49 ) {
V_2 -> V_293 [ V_49 ] = V_2 -> V_293 [ V_85 ] ;
for ( V_16 = 0 ; V_16 < V_299 -> V_302 ; V_16 ++ ) {
F_43 ( V_19 ,
V_2 -> V_184 [ V_16 ] [ V_49 ] ) ;
V_2 -> V_184 [ V_16 ] [ V_49 ] =
V_2 -> V_184 [ V_16 ] [ V_85 ] ;
}
}
V_49 ++ ;
}
V_2 -> V_295 = V_49 ;
}
if ( V_299 -> V_302 == 1 ||
( V_299 -> V_302 == 2 && V_2 -> V_41 ) ) {
F_36 ( L_63 ) ;
V_2 -> V_295 = 1 ;
}
if ( ! V_2 -> V_304 && V_2 -> V_35 )
V_2 -> V_295 = 1 ;
return 0 ;
}
static int F_176 ( struct V_18 * V_19 , T_1 V_44 ,
int V_305 , int V_306 ,
const char * V_307 , int V_308 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_298 * V_299 = & V_2 -> V_300 ;
int V_309 = V_299 -> V_302 ;
bool V_310 = false ;
int V_311 ;
for ( V_311 = 0 ; V_311 < V_306 ; V_311 ++ ) {
struct V_6 * V_50 ;
T_1 V_312 = V_2 -> V_293 [ V_311 ] ;
if ( ! F_29 ( V_19 , V_44 , V_312 ) )
continue;
V_50 = F_42 ( V_19 , V_44 , V_312 , V_308 ) ;
if ( ! V_50 )
continue;
F_34 ( L_64 , V_50 ) ;
V_2 -> V_184 [ V_309 ] [ V_311 ] =
F_26 ( V_19 , V_50 ) ;
if ( ! V_310 ) {
if ( V_2 -> V_251 == V_44 )
V_2 -> V_253 = V_299 -> V_302 ;
V_2 -> V_313 [ V_299 -> V_302 ] = V_44 ;
F_177 ( V_299 , V_307 , V_305 , NULL ) ;
V_310 = true ;
}
}
return 0 ;
}
static int F_178 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_125 * V_126 = & V_2 -> V_127 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_126 -> V_169 ; V_16 ++ ) {
T_1 V_44 = V_126 -> V_170 [ V_16 ] . V_44 ;
const char * V_307 ;
int V_154 , V_56 ;
if ( ! F_173 ( V_19 , V_44 ) )
continue;
V_307 = F_179 ( V_19 , V_126 , V_16 ) ;
V_56 = 0 ;
for ( V_154 = V_16 - 1 ; V_154 >= 0 ; V_154 -- ) {
if ( V_2 -> V_314 [ V_154 ] &&
! strcmp ( V_2 -> V_314 [ V_154 ] , V_307 ) ) {
V_56 = V_2 -> V_315 [ V_154 ] + 1 ;
break;
}
}
V_2 -> V_314 [ V_16 ] = V_307 ;
V_2 -> V_315 [ V_16 ] = V_56 ;
}
return 0 ;
}
static int F_180 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_125 * V_126 = & V_2 -> V_127 ;
T_1 V_316 = V_2 -> V_43 ;
int V_306 ;
int V_16 , V_180 ;
unsigned int V_20 ;
V_306 = F_174 ( V_19 ) ;
if ( V_306 < 0 )
return 0 ;
V_180 = F_178 ( V_19 ) ;
if ( V_180 < 0 )
return V_180 ;
for ( V_16 = 0 ; V_16 < V_126 -> V_169 ; V_16 ++ ) {
T_1 V_44 ;
V_44 = V_126 -> V_170 [ V_16 ] . V_44 ;
if ( ! F_173 ( V_19 , V_44 ) )
continue;
V_20 = V_254 ;
if ( V_126 -> V_170 [ V_16 ] . type == V_168 )
V_20 |= F_144 ( V_19 , V_44 ) ;
if ( V_44 != V_2 -> V_251 )
F_17 ( V_19 , V_44 , V_20 , false ) ;
if ( V_316 ) {
if ( F_29 ( V_19 , V_44 , V_316 ) ) {
V_180 = F_172 ( V_19 , V_16 , V_44 ,
V_2 -> V_314 [ V_16 ] ,
V_2 -> V_315 [ V_16 ] ,
V_316 ) ;
if ( V_180 < 0 )
return V_180 ;
}
}
V_180 = F_176 ( V_19 , V_44 , V_16 , V_306 ,
V_2 -> V_314 [ V_16 ] , - V_316 ) ;
if ( V_180 < 0 )
return V_180 ;
if ( V_2 -> V_39 ) {
V_180 = F_166 ( V_19 , V_44 ) ;
if ( V_180 < 0 )
return V_180 ;
}
}
if ( V_316 && V_2 -> V_38 ) {
V_180 = F_176 ( V_19 , V_316 , V_317 , V_306 ,
L_65 , 0 ) ;
if ( V_180 < 0 )
return V_180 ;
}
return 0 ;
}
static struct V_6 * F_181 ( struct V_18 * V_19 , int V_318 , int V_309 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_309 < 0 || V_309 >= V_319 ) {
F_91 () ;
return NULL ;
}
if ( V_2 -> V_304 )
V_318 = V_2 -> V_303 [ V_309 ] ;
if ( V_318 < 0 || V_318 >= V_261 ) {
F_91 () ;
return NULL ;
}
return F_27 ( V_19 , V_2 -> V_184 [ V_309 ] [ V_318 ] ) ;
}
static int F_182 ( struct V_212 * V_213 ,
struct V_214 * V_215 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
return F_183 ( & V_2 -> V_300 , V_215 ) ;
}
static int F_184 ( struct V_212 * V_213 ,
struct V_216 * V_217 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_318 = F_185 ( V_213 , & V_217 -> V_320 ) ;
V_217 -> V_218 . V_219 . V_220 [ 0 ] = V_2 -> V_252 [ V_318 ] ;
return 0 ;
}
static int F_186 ( struct V_212 * V_213 ,
struct V_216 * V_217 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
unsigned int V_318 = F_185 ( V_213 , & V_217 -> V_320 ) ;
return F_187 ( V_19 , V_318 ,
V_217 -> V_218 . V_219 . V_220 [ 0 ] ) ;
}
static int F_188 ( struct V_212 * V_213 ,
struct V_216 * V_217 ,
T_4 V_321 , int type )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_298 * V_299 ;
struct V_6 * V_50 ;
int V_16 , V_318 , V_180 = 0 ;
V_299 = & V_2 -> V_300 ;
V_318 = V_213 -> V_320 . V_113 ;
F_126 ( & V_19 -> V_322 ) ;
V_19 -> V_323 = 1 ;
for ( V_16 = 0 ; V_16 < V_299 -> V_302 ; V_16 ++ ) {
V_50 = F_181 ( V_19 , V_318 , V_16 ) ;
if ( ! V_50 || ! V_50 -> V_58 [ type ] )
continue;
V_213 -> V_116 = V_50 -> V_58 [ type ] ;
V_180 = V_321 ( V_213 , V_217 ) ;
if ( V_180 < 0 )
goto error;
}
error:
V_19 -> V_323 = 0 ;
F_129 ( & V_19 -> V_322 ) ;
F_189 ( V_19 ) ;
if ( V_180 >= 0 && V_2 -> V_324 )
V_2 -> V_324 ( V_19 , V_217 ) ;
return V_180 ;
}
static int F_190 ( struct V_212 * V_213 ,
struct V_216 * V_217 )
{
return F_188 ( V_213 , V_217 ,
V_325 ,
V_95 ) ;
}
static int F_191 ( struct V_212 * V_213 ,
struct V_216 * V_217 )
{
return F_188 ( V_213 , V_217 ,
V_326 ,
V_94 ) ;
}
static int F_192 ( struct V_18 * V_19 , struct V_6 * V_50 )
{
T_1 V_48 ;
int V_16 , V_51 ;
V_50 -> V_58 [ V_95 ] = V_50 -> V_58 [ V_94 ] = 0 ;
for ( V_51 = 0 ; V_51 < 3 ; V_51 ++ ) {
if ( V_51 >= V_50 -> V_51 )
return - V_236 ;
V_16 = V_50 -> V_51 - V_51 - 1 ;
V_48 = V_50 -> V_50 [ V_16 ] ;
if ( ! V_50 -> V_58 [ V_95 ] ) {
if ( F_52 ( V_19 , V_48 , V_80 ) )
V_50 -> V_58 [ V_95 ] =
F_33 ( V_48 , 3 , 0 , V_80 ) ;
else if ( F_52 ( V_19 , V_48 , V_81 ) ) {
int V_56 = V_50 -> V_56 [ V_16 ] ;
if ( ! V_51 && V_19 -> V_29 )
V_56 = 0 ;
V_50 -> V_58 [ V_95 ] =
F_33 ( V_48 , 3 , V_56 , V_81 ) ;
}
}
if ( ! V_50 -> V_58 [ V_94 ] ) {
if ( F_50 ( V_19 , V_48 , V_80 ) )
V_50 -> V_58 [ V_94 ] =
F_33 ( V_48 , 3 , 0 , V_80 ) ;
else if ( F_50 ( V_19 , V_48 , V_81 ) ) {
int V_56 = V_50 -> V_56 [ V_16 ] ;
if ( ! V_51 && V_19 -> V_29 )
V_56 = 0 ;
V_50 -> V_58 [ V_94 ] =
F_33 ( V_48 , 3 , V_56 , V_81 ) ;
}
}
}
return 0 ;
}
static bool F_193 ( struct V_18 * V_19 , T_1 V_48 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_125 * V_126 = & V_2 -> V_127 ;
unsigned int V_20 ;
int V_16 ;
if ( ! V_2 -> V_36 )
return false ;
for ( V_16 = 0 ; V_16 < V_126 -> V_169 ; V_16 ++ ) {
if ( V_126 -> V_170 [ V_16 ] . V_44 != V_48 )
continue;
if ( V_126 -> V_170 [ V_16 ] . type != V_168 )
return false ;
V_20 = F_98 ( V_19 , V_48 ) ;
return F_147 ( V_20 ) == V_260 ;
}
return false ;
}
static int F_194 ( struct V_212 * V_213 ,
struct V_216 * V_217 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_223 ;
V_223 = V_326 ( V_213 , V_217 ) ;
if ( V_223 < 0 )
return V_223 ;
if ( V_2 -> V_324 )
V_2 -> V_324 ( V_19 , V_217 ) ;
return V_223 ;
}
static int F_195 ( struct V_18 * V_19 , const char * V_307 ,
int V_56 , bool V_327 , unsigned int V_328 ,
bool V_329 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
char V_330 [ 44 ] ;
int type = V_327 ? V_121 : V_119 ;
const char * V_117 = V_327 ? L_66 : L_67 ;
unsigned int V_76 = V_329 ? 1 : 3 ;
struct V_4 * V_12 ;
if ( ! V_328 )
return 0 ;
if ( V_307 )
snprintf ( V_330 , sizeof( V_330 ) ,
L_68 , V_307 , V_117 ) ;
else
snprintf ( V_330 , sizeof( V_330 ) ,
L_69 , V_117 ) ;
V_12 = F_76 ( V_2 , type , V_330 , V_56 ,
F_45 ( V_328 , V_76 ) ) ;
if ( ! V_12 )
return - V_118 ;
if ( V_327 )
V_12 -> V_331 = F_194 ;
if ( ! V_329 )
return 0 ;
if ( V_307 )
snprintf ( V_330 , sizeof( V_330 ) ,
L_70 , V_307 , V_117 ) ;
else
snprintf ( V_330 , sizeof( V_330 ) ,
L_71 , V_117 ) ;
V_12 = F_76 ( V_2 , type , V_330 , V_56 ,
F_45 ( V_328 , 2 ) ) ;
if ( ! V_12 )
return - V_118 ;
if ( V_327 )
V_12 -> V_331 = F_194 ;
return 0 ;
}
static int F_196 ( struct V_18 * V_19 , int V_56 ,
unsigned int V_332 , unsigned int V_333 ,
bool V_329 )
{
int V_180 ;
V_180 = F_195 ( V_19 , NULL , V_56 , false , V_332 , V_329 ) ;
if ( V_180 < 0 )
return V_180 ;
V_180 = F_195 ( V_19 , NULL , V_56 , true , V_333 , V_329 ) ;
if ( V_180 < 0 )
return V_180 ;
return 0 ;
}
static int F_197 ( struct V_18 * V_19 , int V_56 ,
unsigned int V_332 , unsigned int V_333 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
if ( V_332 ) {
V_12 = F_4 ( V_2 , NULL , & V_334 ) ;
if ( ! V_12 )
return - V_118 ;
V_12 -> V_113 = V_56 ;
V_12 -> V_116 = V_332 ;
V_12 -> V_114 = V_115 ;
}
if ( V_333 ) {
V_12 = F_4 ( V_2 , NULL , & V_335 ) ;
if ( ! V_12 )
return - V_118 ;
V_12 -> V_113 = V_56 ;
V_12 -> V_116 = V_333 ;
V_12 -> V_114 = V_115 ;
}
return 0 ;
}
static unsigned int F_198 ( struct V_18 * V_19 , int V_56 , int type )
{
struct V_6 * V_50 ;
unsigned int V_328 ;
int V_16 ;
V_50 = F_181 ( V_19 , 0 , V_56 ) ;
if ( ! V_50 )
return 0 ;
V_328 = V_50 -> V_58 [ type ] ;
if ( ! V_328 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_56 - 1 ; V_16 ++ ) {
V_50 = F_181 ( V_19 , 0 , V_16 ) ;
if ( V_50 && V_50 -> V_58 [ type ] == V_328 )
return 0 ;
}
return V_328 ;
}
static int F_199 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_298 * V_299 = & V_2 -> V_300 ;
int V_16 , V_180 , type ;
for ( V_16 = 0 ; V_16 < V_299 -> V_302 ; V_16 ++ ) {
bool V_329 ;
int V_56 ;
V_56 = V_299 -> V_234 [ V_16 ] . V_113 ;
if ( V_56 >= V_2 -> V_127 . V_169 )
continue;
V_329 = F_193 ( V_19 , V_2 -> V_313 [ V_16 ] ) ;
for ( type = 0 ; type < 2 ; type ++ ) {
V_180 = F_195 ( V_19 ,
V_2 -> V_314 [ V_56 ] ,
V_2 -> V_315 [ V_56 ] ,
type ,
F_198 ( V_19 , V_16 , type ) ,
V_329 ) ;
if ( V_180 < 0 )
return V_180 ;
}
}
return 0 ;
}
static int F_200 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_298 * V_299 = & V_2 -> V_300 ;
int V_16 , V_85 , V_49 , V_180 ;
if ( V_2 -> V_304 )
V_49 = 1 ;
else
V_49 = V_2 -> V_295 ;
if ( ! V_2 -> V_336 && V_299 -> V_302 > 1 ) {
struct V_4 * V_12 ;
const char * V_10 ;
V_10 = V_49 > 1 ? L_72 : L_73 ;
V_12 = F_4 ( V_2 , V_10 , & V_337 ) ;
if ( ! V_12 )
return - V_118 ;
V_12 -> V_233 = V_49 ;
}
for ( V_85 = 0 ; V_85 < V_49 ; V_85 ++ ) {
bool V_70 = false ;
bool V_35 = V_2 -> V_35 ;
bool V_329 = false ;
int V_338 , V_339 ;
V_338 = V_339 = 0 ;
for ( V_16 = 0 ; V_16 < V_299 -> V_302 ; V_16 ++ ) {
struct V_6 * V_50 ;
V_50 = F_181 ( V_19 , V_85 , V_16 ) ;
if ( ! V_50 )
continue;
F_192 ( V_19 , V_50 ) ;
if ( ! V_338 )
V_338 = V_50 -> V_58 [ V_95 ] ;
else if ( V_338 != V_50 -> V_58 [ V_95 ] ) {
V_70 = true ;
if ( ! F_48 ( V_19 , V_338 ,
V_50 -> V_58 [ V_95 ] , V_81 ) )
V_35 = true ;
}
if ( ! V_339 )
V_339 = V_50 -> V_58 [ V_94 ] ;
else if ( V_339 != V_50 -> V_58 [ V_94 ] ) {
V_70 = true ;
if ( ! F_48 ( V_19 , V_339 ,
V_50 -> V_58 [ V_94 ] , V_81 ) )
V_35 = true ;
}
if ( F_193 ( V_19 , V_2 -> V_313 [ V_16 ] ) )
V_329 = true ;
}
if ( ! V_70 )
V_180 = F_196 ( V_19 , V_85 , V_338 , V_339 ,
V_329 ) ;
else if ( ! V_35 )
V_180 = F_197 ( V_19 , V_85 , V_338 , V_339 ) ;
else
V_180 = F_199 ( V_19 ) ;
if ( V_180 < 0 )
return V_180 ;
}
return 0 ;
}
static bool F_201 ( struct V_18 * V_19 , T_1 V_48 ,
int V_59 , int V_56 )
{
unsigned int V_340 ;
if ( ! F_52 ( V_19 , V_48 , V_59 ) ||
F_32 ( V_19 , V_48 , V_59 , V_56 , V_95 ) ||
F_32 ( V_19 , V_48 , V_59 , V_56 , V_96 ) )
return false ;
V_340 = ( F_47 ( V_19 , V_48 , V_59 ) & V_341 )
>> V_342 ;
if ( V_340 < 0x20 )
return false ;
return true ;
}
static unsigned int F_202 ( struct V_18 * V_19 ,
struct V_6 * V_50 )
{
unsigned int V_20 = 0 ;
T_1 V_48 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < 3 ; V_51 ++ ) {
if ( V_51 >= V_50 -> V_51 - 1 )
break;
V_48 = V_50 -> V_50 [ V_51 ] ;
if ( V_51 && F_201 ( V_19 , V_48 , V_80 , 0 ) ) {
V_20 = F_33 ( V_48 , 3 , 0 , V_80 ) ;
break;
} else if ( F_201 ( V_19 , V_48 , V_81 ,
V_50 -> V_56 [ V_51 ] ) ) {
V_20 = F_33 ( V_48 , 3 , V_50 -> V_56 [ V_51 ] ,
V_81 ) ;
break;
}
}
return V_20 ;
}
static int F_203 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_125 * V_126 = & V_2 -> V_127 ;
struct V_298 * V_299 = & V_2 -> V_300 ;
int V_16 ;
if ( ! V_2 -> V_295 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_299 -> V_302 ; V_16 ++ ) {
struct V_6 * V_50 ;
unsigned int V_20 ;
int V_56 ;
char V_343 [ 44 ] ;
V_56 = V_299 -> V_234 [ V_16 ] . V_113 ;
if ( V_56 >= V_299 -> V_302 )
continue;
if ( V_126 -> V_170 [ V_56 ] . type > V_167 )
continue;
V_50 = F_181 ( V_19 , 0 , V_16 ) ;
if ( ! V_50 )
continue;
V_20 = F_202 ( V_19 , V_50 ) ;
if ( ! V_20 )
continue;
snprintf ( V_343 , sizeof( V_343 ) ,
L_74 , V_2 -> V_314 [ V_56 ] ) ;
if ( ! F_76 ( V_2 , V_119 , V_343 ,
V_2 -> V_315 [ V_56 ] , V_20 ) )
return - V_118 ;
V_50 -> V_58 [ V_96 ] = V_20 ;
}
return 0 ;
}
static void F_204 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_50 ;
int V_16 , V_49 ;
T_1 V_344 , V_44 ;
V_49 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_127 . V_345 ; V_16 ++ ) {
V_44 = V_2 -> V_127 . V_346 [ V_16 ] ;
V_344 = F_44 ( V_19 , V_44 , true ) ;
if ( ! V_344 )
continue;
V_50 = F_42 ( V_19 , V_344 , V_44 , 0 ) ;
if ( ! V_50 )
continue;
F_34 ( L_75 , V_50 ) ;
V_50 -> V_86 = true ;
V_2 -> V_183 [ V_16 ] = F_26 ( V_19 , V_50 ) ;
F_17 ( V_19 , V_44 , V_210 , false ) ;
if ( ! V_49 ) {
V_2 -> V_134 . V_347 = V_344 ;
V_2 -> V_348 = V_2 -> V_127 . V_348 [ 0 ] ;
} else {
V_2 -> V_134 . V_349 = V_2 -> V_349 ;
if ( V_49 >= F_90 ( V_2 -> V_349 ) - 1 )
break;
V_2 -> V_349 [ V_49 - 1 ] = V_344 ;
}
V_49 ++ ;
}
if ( V_2 -> V_127 . V_350 ) {
V_44 = V_2 -> V_127 . V_350 ;
V_344 = V_19 -> V_197 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_198 ; V_16 ++ , V_344 ++ ) {
unsigned int V_351 = F_40 ( V_19 , V_344 ) ;
if ( F_39 ( V_351 ) != V_67 )
continue;
if ( ! ( V_351 & V_75 ) )
continue;
V_50 = F_42 ( V_19 , V_44 , V_344 , 0 ) ;
if ( V_50 ) {
F_34 ( L_76 , V_50 ) ;
V_50 -> V_86 = true ;
V_2 -> V_352 = V_344 ;
V_2 -> V_186 = F_26 ( V_19 , V_50 ) ;
F_17 ( V_19 , V_44 , V_254 , false ) ;
break;
}
}
}
}
static int F_187 ( struct V_18 * V_19 , unsigned int V_318 ,
unsigned int V_56 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_298 * V_299 ;
struct V_6 * V_353 , * V_50 ;
V_299 = & V_2 -> V_300 ;
if ( ! V_299 -> V_302 )
return 0 ;
if ( V_56 >= V_299 -> V_302 )
V_56 = V_299 -> V_302 - 1 ;
if ( V_2 -> V_252 [ V_318 ] == V_56 )
return 0 ;
V_353 = F_181 ( V_19 , V_318 , V_2 -> V_252 [ V_318 ] ) ;
if ( ! V_353 )
return 0 ;
if ( V_353 -> V_86 )
F_64 ( V_19 , V_353 , false , false ) ;
V_2 -> V_252 [ V_318 ] = V_56 ;
if ( V_2 -> V_41 )
F_143 ( V_19 , V_318 , false ) ;
if ( V_2 -> V_304 )
F_205 ( V_19 , V_56 ) ;
V_50 = F_181 ( V_19 , V_318 , V_56 ) ;
if ( ! V_50 )
return 0 ;
if ( V_50 -> V_86 )
return 0 ;
F_64 ( V_19 , V_50 , true , false ) ;
if ( V_2 -> V_324 )
V_2 -> V_324 ( V_19 , NULL ) ;
F_68 ( V_19 , V_353 ) ;
return 1 ;
}
static bool F_206 ( struct V_18 * V_19 , int V_46 , T_1 * V_47 )
{
int V_16 , V_354 = 0 ;
for ( V_16 = 0 ; V_16 < V_46 ; V_16 ++ ) {
T_1 V_48 = V_47 [ V_16 ] ;
if ( ! V_48 )
break;
if ( F_16 ( V_19 , V_48 ) & V_355 )
continue;
V_354 |= F_207 ( V_19 , V_48 ) ;
}
return V_354 ;
}
static void F_208 ( struct V_18 * V_19 , int V_46 , T_1 * V_47 ,
bool V_356 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_46 ; V_16 ++ ) {
T_1 V_48 = V_47 [ V_16 ] ;
unsigned int V_20 , V_283 ;
if ( ! V_48 )
break;
V_283 = F_16 ( V_19 , V_48 ) ;
if ( V_283 & V_254 )
continue;
if ( V_2 -> V_357 )
V_20 = V_283 & ~ V_209 ;
else
V_20 = 0 ;
if ( ! V_356 )
V_20 |= V_283 ;
F_15 ( V_19 , V_48 , V_20 ) ;
F_72 ( V_19 , V_48 , ! V_356 ) ;
}
}
void F_209 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_358 ;
F_208 ( V_19 , F_90 ( V_2 -> V_127 . V_189 ) ,
V_2 -> V_127 . V_189 , V_2 -> V_359 ) ;
if ( ! V_2 -> V_360 )
V_358 = 0 ;
else
V_358 = V_2 -> V_361 | V_2 -> V_362 ;
V_358 |= V_2 -> V_359 ;
V_2 -> V_363 = V_358 ;
F_208 ( V_19 , F_90 ( V_2 -> V_127 . V_190 ) ,
V_2 -> V_127 . V_190 , V_358 ) ;
if ( V_2 -> V_127 . V_188 [ 0 ] == V_2 -> V_127 . V_189 [ 0 ] ||
V_2 -> V_127 . V_188 [ 0 ] == V_2 -> V_127 . V_190 [ 0 ] )
return;
if ( ! V_2 -> V_364 )
V_358 = 0 ;
else
V_358 = V_2 -> V_361 ;
V_358 |= V_2 -> V_359 ;
V_2 -> V_365 = V_358 ;
F_208 ( V_19 , F_90 ( V_2 -> V_127 . V_188 ) ,
V_2 -> V_127 . V_188 , V_358 ) ;
}
static void F_210 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_366 )
V_2 -> V_366 ( V_19 ) ;
else
F_209 ( V_19 ) ;
}
void F_211 ( struct V_18 * V_19 , struct V_367 * V_368 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 * V_47 = V_2 -> V_127 . V_189 ;
int V_46 = F_90 ( V_2 -> V_127 . V_189 ) ;
if ( V_2 -> V_221 ) {
V_47 ++ ;
V_46 -- ;
}
V_2 -> V_361 = F_206 ( V_19 , V_46 , V_47 ) ;
if ( ! V_2 -> V_369 || ( ! V_2 -> V_360 && ! V_2 -> V_364 ) )
return;
F_210 ( V_19 ) ;
}
void F_212 ( struct V_18 * V_19 , struct V_367 * V_368 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_127 . V_139 == V_140 )
return;
if ( V_2 -> V_127 . V_188 [ 0 ] == V_2 -> V_127 . V_189 [ 0 ] )
return;
V_2 -> V_362 =
F_206 ( V_19 , F_90 ( V_2 -> V_127 . V_188 ) ,
V_2 -> V_127 . V_188 ) ;
if ( ! V_2 -> V_360 || ! V_2 -> V_370 )
return;
F_210 ( V_19 ) ;
}
void F_213 ( struct V_18 * V_19 , struct V_367 * V_368 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
if ( ! V_2 -> V_336 )
return;
for ( V_16 = V_2 -> V_371 - 1 ; V_16 > 0 ; V_16 -- ) {
T_1 V_44 = V_2 -> V_372 [ V_16 ] . V_44 ;
if ( F_16 ( V_19 , V_44 ) & V_373 )
continue;
if ( F_207 ( V_19 , V_44 ) ) {
F_187 ( V_19 , 0 , V_2 -> V_372 [ V_16 ] . V_56 ) ;
return;
}
}
F_187 ( V_19 , 0 , V_2 -> V_372 [ 0 ] . V_56 ) ;
}
static void F_128 ( struct V_18 * V_19 , struct V_367 * V_368 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_374 )
V_2 -> V_374 ( V_19 , V_368 ) ;
else
F_211 ( V_19 , V_368 ) ;
}
static void F_214 ( struct V_18 * V_19 ,
struct V_367 * V_368 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_375 )
V_2 -> V_375 ( V_19 , V_368 ) ;
else
F_212 ( V_19 , V_368 ) ;
}
static void F_215 ( struct V_18 * V_19 ,
struct V_367 * V_368 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_376 )
V_2 -> V_376 ( V_19 , V_368 ) ;
else
F_213 ( V_19 , V_368 ) ;
}
static void F_136 ( struct V_18 * V_19 )
{
F_128 ( V_19 , NULL ) ;
F_214 ( V_19 , NULL ) ;
F_215 ( V_19 , NULL ) ;
}
static int F_216 ( struct V_212 * V_213 ,
struct V_214 * V_215 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_377 [] = {
L_77 , L_78 , L_79
} ;
if ( V_2 -> V_378 && V_2 -> V_379 )
return F_149 ( V_213 , V_215 , 3 , V_377 ) ;
return F_122 ( V_213 , V_215 ) ;
}
static int F_217 ( struct V_212 * V_213 ,
struct V_216 * V_217 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = 0 ;
if ( V_2 -> V_360 )
V_20 ++ ;
if ( V_2 -> V_364 )
V_20 ++ ;
V_217 -> V_218 . V_219 . V_220 [ 0 ] = V_20 ;
return 0 ;
}
static int F_218 ( struct V_212 * V_213 ,
struct V_216 * V_217 )
{
struct V_18 * V_19 = F_124 ( V_213 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
switch ( V_217 -> V_218 . V_219 . V_220 [ 0 ] ) {
case 0 :
if ( ! V_2 -> V_360 && ! V_2 -> V_364 )
return 0 ;
V_2 -> V_360 = 0 ;
V_2 -> V_364 = 0 ;
break;
case 1 :
if ( V_2 -> V_378 ) {
if ( ! V_2 -> V_364 && V_2 -> V_360 )
return 0 ;
V_2 -> V_360 = 1 ;
V_2 -> V_364 = 0 ;
} else if ( V_2 -> V_379 ) {
if ( V_2 -> V_364 )
return 0 ;
V_2 -> V_364 = 1 ;
} else
return - V_236 ;
break;
case 2 :
if ( ! V_2 -> V_379 || ! V_2 -> V_378 )
return - V_236 ;
if ( V_2 -> V_360 && V_2 -> V_364 )
return 0 ;
V_2 -> V_360 = 1 ;
V_2 -> V_364 = 1 ;
break;
default:
return - V_236 ;
}
F_210 ( V_19 ) ;
return 1 ;
}
static int F_219 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! F_4 ( V_2 , NULL , & V_380 ) )
return - V_118 ;
return 0 ;
}
static int F_220 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_125 * V_126 = & V_2 -> V_127 ;
int V_354 = 0 ;
int V_16 , V_180 ;
if ( V_2 -> V_30 )
return 0 ;
if ( V_126 -> V_189 [ 0 ] )
V_354 ++ ;
if ( V_126 -> V_188 [ 0 ] )
V_354 ++ ;
if ( V_126 -> V_190 [ 0 ] )
V_354 ++ ;
if ( V_354 < 2 )
return 0 ;
if ( ! V_126 -> V_190 [ 0 ] &&
V_126 -> V_139 == V_140 ) {
memcpy ( V_126 -> V_190 , V_126 -> V_188 ,
sizeof( V_126 -> V_190 ) ) ;
V_126 -> V_131 = V_126 -> V_128 ;
}
if ( ! V_126 -> V_189 [ 0 ] &&
V_126 -> V_139 == V_142 ) {
memcpy ( V_126 -> V_189 , V_126 -> V_188 ,
sizeof( V_126 -> V_189 ) ) ;
V_126 -> V_130 = V_126 -> V_128 ;
}
for ( V_16 = 0 ; V_16 < V_126 -> V_130 ; V_16 ++ ) {
T_1 V_48 = V_126 -> V_189 [ V_16 ] ;
if ( ! F_221 ( V_19 , V_48 ) )
continue;
F_36 ( L_80 ,
V_48 ) ;
F_222 ( V_19 , V_48 , V_381 ,
F_128 ) ;
V_2 -> V_369 = 1 ;
}
if ( V_126 -> V_139 == V_382 && V_126 -> V_128 ) {
if ( V_126 -> V_131 )
for ( V_16 = 0 ; V_16 < V_126 -> V_128 ; V_16 ++ ) {
T_1 V_48 = V_126 -> V_188 [ V_16 ] ;
if ( ! F_221 ( V_19 , V_48 ) )
continue;
F_36 ( L_81 , V_48 ) ;
F_222 ( V_19 , V_48 ,
V_383 ,
F_214 ) ;
V_2 -> V_370 = 1 ;
}
V_2 -> V_379 = V_2 -> V_369 ;
}
V_2 -> V_378 = V_126 -> V_131 &&
( V_2 -> V_369 || V_2 -> V_370 ) ;
V_2 -> V_364 = V_2 -> V_379 ;
V_2 -> V_360 = V_2 -> V_378 ;
if ( V_2 -> V_378 || V_2 -> V_379 ) {
V_180 = F_219 ( V_19 ) ;
if ( V_180 < 0 )
return V_180 ;
}
return 0 ;
}
static bool F_223 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_298 * V_299 ;
int V_16 ;
V_299 = & V_2 -> V_300 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_371 ; V_16 ++ ) {
V_2 -> V_372 [ V_16 ] . V_56 =
F_21 ( V_2 -> V_372 [ V_16 ] . V_44 ,
V_2 -> V_313 , V_299 -> V_302 ) ;
if ( V_2 -> V_372 [ V_16 ] . V_56 < 0 )
return false ;
}
for ( V_16 = 1 ; V_16 < V_2 -> V_371 ; V_16 ++ )
F_222 ( V_19 ,
V_2 -> V_372 [ V_16 ] . V_44 ,
V_384 ,
F_215 ) ;
return true ;
}
static int F_224 ( const void * V_385 , const void * V_386 )
{
const struct V_387 * V_388 = V_385 ;
const struct V_387 * V_389 = V_386 ;
return ( int ) ( V_388 -> V_390 - V_389 -> V_390 ) ;
}
static int F_225 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_125 * V_126 = & V_2 -> V_127 ;
unsigned int V_391 ;
int V_16 , V_46 ;
if ( V_2 -> V_31 )
return 0 ;
V_391 = 0 ;
V_46 = 0 ;
for ( V_16 = 0 ; V_16 < V_126 -> V_169 ; V_16 ++ ) {
T_1 V_48 = V_126 -> V_170 [ V_16 ] . V_44 ;
unsigned int V_390 ;
V_390 = F_98 ( V_19 , V_48 ) ;
V_390 = F_147 ( V_390 ) ;
if ( V_391 & ( 1 << V_390 ) )
return 0 ;
switch ( V_390 ) {
case V_260 :
if ( V_126 -> V_170 [ V_16 ] . type != V_168 )
return 0 ;
break;
case V_392 :
return 0 ;
default:
if ( V_126 -> V_170 [ V_16 ] . type > V_167 )
return 0 ;
if ( ! V_2 -> V_32 &&
V_126 -> V_170 [ V_16 ] . type != V_168 )
return 0 ;
if ( ! F_221 ( V_19 , V_48 ) )
return 0 ;
break;
}
if ( V_46 >= V_393 )
return 0 ;
V_391 |= ( 1 << V_390 ) ;
V_2 -> V_372 [ V_46 ] . V_44 = V_48 ;
V_2 -> V_372 [ V_46 ] . V_390 = V_390 ;
V_46 ++ ;
}
if ( V_46 < 2 )
return 0 ;
V_2 -> V_371 = V_46 ;
F_226 ( V_2 -> V_372 , V_46 , sizeof( V_2 -> V_372 [ 0 ] ) ,
F_224 , NULL ) ;
if ( ! F_223 ( V_19 ) )
return 0 ;
V_2 -> V_336 = 1 ;
V_2 -> V_295 = 1 ;
V_2 -> V_252 [ 0 ] = V_2 -> V_372 [ 0 ] . V_56 ;
F_36 ( L_82 ,
V_2 -> V_372 [ 0 ] . V_44 ,
V_2 -> V_372 [ 1 ] . V_44 ,
V_2 -> V_372 [ 2 ] . V_44 ) ;
return 0 ;
}
static unsigned int F_227 ( struct V_18 * V_19 ,
T_1 V_48 ,
unsigned int V_394 )
{
if ( V_394 != V_100 )
return V_394 ;
if ( F_39 ( F_40 ( V_19 , V_48 ) ) >= V_395 )
return V_394 ;
if ( F_69 ( V_19 , V_48 ) )
return V_394 ;
return V_104 ;
}
int F_228 ( struct V_18 * V_19 ,
struct V_125 * V_126 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_180 ;
F_11 ( V_19 ) ;
if ( V_2 -> V_43 && ! V_2 -> V_99 )
V_2 -> V_99 = V_2 -> V_43 ;
if ( V_126 != & V_2 -> V_127 ) {
V_2 -> V_127 = * V_126 ;
V_126 = & V_2 -> V_127 ;
}
if ( ! V_2 -> V_191 )
V_2 -> V_191 = & V_396 ;
if ( ! V_2 -> V_192 )
V_2 -> V_192 = & V_397 ;
F_111 ( V_19 ) ;
if ( ! V_126 -> V_128 ) {
if ( V_126 -> V_345 || V_126 -> V_350 ) {
V_2 -> V_134 . V_238 = 2 ;
V_2 -> V_398 = 1 ;
goto V_399;
}
return 0 ;
}
if ( ! V_2 -> V_34 &&
V_126 -> V_139 == V_140 &&
V_126 -> V_128 <= V_126 -> V_130 ) {
V_126 -> V_131 = V_126 -> V_128 ;
memcpy ( V_126 -> V_190 , V_126 -> V_188 ,
sizeof( V_126 -> V_190 ) ) ;
V_126 -> V_128 = V_126 -> V_130 ;
memcpy ( V_126 -> V_188 , V_126 -> V_189 , sizeof( V_126 -> V_189 ) ) ;
V_126 -> V_130 = 0 ;
memset ( V_126 -> V_189 , 0 , sizeof( V_126 -> V_189 ) ) ;
V_126 -> V_139 = V_142 ;
}
V_180 = F_113 ( V_19 ) ;
if ( V_180 < 0 )
return V_180 ;
V_180 = F_139 ( V_19 ) ;
if ( V_180 < 0 )
return V_180 ;
V_180 = F_116 ( V_19 , V_126 ) ;
if ( V_180 < 0 )
return V_180 ;
V_180 = F_119 ( V_19 ) ;
if ( V_180 < 0 )
return V_180 ;
V_180 = F_120 ( V_19 ) ;
if ( V_180 < 0 )
return V_180 ;
V_180 = F_130 ( V_19 ) ;
if ( V_180 < 0 )
return V_180 ;
V_180 = F_142 ( V_19 ) ;
if ( V_180 < 0 )
return V_180 ;
V_180 = F_146 ( V_19 ) ;
if ( V_180 < 0 )
return V_180 ;
V_180 = F_180 ( V_19 ) ;
if ( V_180 < 0 )
return V_180 ;
V_2 -> V_239 = V_2 -> V_193 ;
if ( V_126 -> V_139 != V_140 )
V_2 -> V_239 = F_138 ( V_2 -> V_239 ,
V_126 -> V_131 * 2 ) ;
if ( V_126 -> V_139 != V_142 )
V_2 -> V_239 = F_138 ( V_2 -> V_239 ,
V_126 -> V_130 * 2 ) ;
V_2 -> V_134 . V_238 = F_138 ( V_2 -> V_193 ,
V_2 -> V_239 ) ;
V_180 = F_220 ( V_19 ) ;
if ( V_180 < 0 )
return V_180 ;
V_180 = F_175 ( V_19 ) ;
if ( V_180 < 0 )
return V_180 ;
V_180 = F_225 ( V_19 ) ;
if ( V_180 < 0 )
return V_180 ;
V_180 = F_200 ( V_19 ) ;
if ( V_180 < 0 )
return V_180 ;
V_180 = F_203 ( V_19 ) ;
if ( V_180 < 0 )
return V_180 ;
if ( V_2 -> V_39 ) {
if ( V_126 -> V_139 != V_140 ) {
V_180 = F_156 ( V_19 , V_126 -> V_128 ,
V_126 -> V_188 ) ;
if ( V_180 < 0 )
return V_180 ;
}
if ( V_126 -> V_139 != V_142 ) {
V_180 = F_156 ( V_19 , V_126 -> V_130 ,
V_126 -> V_189 ) ;
if ( V_180 < 0 )
return V_180 ;
}
}
V_399:
F_204 ( V_19 ) ;
if ( V_2 -> V_40 )
V_19 -> V_400 = F_227 ;
if ( ! V_2 -> V_398 && V_2 -> V_401 ) {
V_180 = F_229 ( V_19 , V_2 -> V_401 ) ;
if ( V_180 < 0 )
return V_180 ;
}
return 1 ;
}
int F_230 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_180 ;
if ( V_2 -> V_3 . V_17 ) {
V_180 = F_231 ( V_19 , V_2 -> V_3 . V_14 ) ;
if ( V_180 < 0 )
return V_180 ;
}
if ( V_2 -> V_134 . V_347 ) {
V_180 = F_232 ( V_19 ,
V_2 -> V_134 . V_347 ,
V_2 -> V_134 . V_347 ,
V_2 -> V_402 [ 1 ] . V_403 ) ;
if ( V_180 < 0 )
return V_180 ;
if ( ! V_2 -> V_398 ) {
V_180 = F_233 ( V_19 ,
& V_2 -> V_134 ) ;
if ( V_180 < 0 )
return V_180 ;
V_2 -> V_134 . V_404 = 1 ;
}
}
if ( V_2 -> V_352 ) {
V_180 = F_234 ( V_19 , V_2 -> V_352 ) ;
if ( V_180 < 0 )
return V_180 ;
}
if ( ! V_2 -> V_398 &&
! F_235 ( V_19 , L_83 ) ) {
V_180 = F_236 ( V_19 , L_83 ,
V_2 -> V_207 , V_405 ,
L_84 ) ;
if ( V_180 < 0 )
return V_180 ;
}
if ( ! V_2 -> V_398 &&
! F_235 ( V_19 , L_85 ) ) {
V_180 = F_237 ( V_19 , L_85 ,
NULL , V_405 ,
L_86 ,
true , & V_2 -> V_132 . V_406 ) ;
if ( V_180 < 0 )
return V_180 ;
if ( V_2 -> V_132 . V_133 )
F_238 ( V_19 , & V_2 -> V_132 ,
V_2 -> V_407 ) ;
}
F_7 ( V_2 ) ;
V_180 = F_239 ( V_19 , & V_2 -> V_127 ) ;
if ( V_180 < 0 )
return V_180 ;
return 0 ;
}
static void F_240 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
struct V_410 * V_411 ,
int V_412 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_413 )
V_2 -> V_413 ( V_409 , V_19 , V_411 , V_412 ) ;
}
static void F_241 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
struct V_410 * V_411 ,
int V_412 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_414 )
V_2 -> V_414 ( V_409 , V_19 , V_411 , V_412 ) ;
}
static int F_242 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
struct V_410 * V_411 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_180 ;
F_126 ( & V_2 -> V_9 ) ;
V_180 = F_243 ( V_19 ,
& V_2 -> V_134 , V_411 ,
V_409 ) ;
if ( ! V_180 ) {
V_2 -> V_224 |= 1 << V_415 ;
F_240 ( V_409 , V_19 , V_411 ,
V_416 ) ;
}
F_129 ( & V_2 -> V_9 ) ;
return V_180 ;
}
static int F_244 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
unsigned int V_417 ,
unsigned int V_418 ,
struct V_410 * V_411 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_180 ;
V_180 = F_245 ( V_19 , & V_2 -> V_134 ,
V_417 , V_418 , V_411 ) ;
if ( ! V_180 )
F_240 ( V_409 , V_19 , V_411 ,
V_419 ) ;
return V_180 ;
}
static int F_246 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
struct V_410 * V_411 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_180 ;
V_180 = F_247 ( V_19 , & V_2 -> V_134 ) ;
if ( ! V_180 )
F_240 ( V_409 , V_19 , V_411 ,
V_420 ) ;
return V_180 ;
}
static int F_248 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
struct V_410 * V_411 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_126 ( & V_2 -> V_9 ) ;
V_2 -> V_224 &= ~ ( 1 << V_415 ) ;
F_240 ( V_409 , V_19 , V_411 ,
V_421 ) ;
F_129 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_249 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
struct V_410 * V_411 )
{
F_241 ( V_409 , V_19 , V_411 , V_416 ) ;
return 0 ;
}
static int F_250 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
unsigned int V_417 ,
unsigned int V_418 ,
struct V_410 * V_411 )
{
F_251 ( V_19 , V_409 -> V_48 , V_417 , 0 , V_418 ) ;
F_241 ( V_409 , V_19 , V_411 ,
V_419 ) ;
return 0 ;
}
static int F_252 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
struct V_410 * V_411 )
{
F_253 ( V_19 , V_409 -> V_48 ) ;
F_241 ( V_409 , V_19 , V_411 ,
V_420 ) ;
return 0 ;
}
static int F_254 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
struct V_410 * V_411 )
{
F_241 ( V_409 , V_19 , V_411 , V_421 ) ;
return 0 ;
}
static int F_255 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
struct V_410 * V_411 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_180 = 0 ;
F_126 ( & V_2 -> V_9 ) ;
if ( ! V_2 -> V_221 )
V_180 = - V_225 ;
else
V_2 -> V_224 |= 1 << V_422 ;
F_240 ( V_409 , V_19 , V_411 ,
V_416 ) ;
F_129 ( & V_2 -> V_9 ) ;
return V_180 ;
}
static int F_256 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
struct V_410 * V_411 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_126 ( & V_2 -> V_9 ) ;
V_2 -> V_224 &= ~ ( 1 << V_422 ) ;
F_240 ( V_409 , V_19 , V_411 ,
V_421 ) ;
F_129 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_257 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
unsigned int V_417 ,
unsigned int V_418 ,
struct V_410 * V_411 )
{
F_251 ( V_19 , V_409 -> V_48 , V_417 , 0 , V_418 ) ;
F_240 ( V_409 , V_19 , V_411 ,
V_419 ) ;
return 0 ;
}
static int F_258 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
struct V_410 * V_411 )
{
F_253 ( V_19 , V_409 -> V_48 ) ;
F_240 ( V_409 , V_19 , V_411 ,
V_420 ) ;
return 0 ;
}
static int F_259 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
struct V_410 * V_411 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_260 ( V_19 , & V_2 -> V_134 ) ;
}
static int F_261 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
unsigned int V_417 ,
unsigned int V_418 ,
struct V_410 * V_411 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_262 ( V_19 , & V_2 -> V_134 ,
V_417 , V_418 , V_411 ) ;
}
static int F_263 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
struct V_410 * V_411 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_264 ( V_19 , & V_2 -> V_134 ) ;
}
static int F_265 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
struct V_410 * V_411 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_266 ( V_19 , & V_2 -> V_134 ) ;
}
static int F_267 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
unsigned int V_417 ,
unsigned int V_418 ,
struct V_410 * V_411 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_251 ( V_19 , V_2 -> V_293 [ V_411 -> V_423 + 1 ] ,
V_417 , 0 , V_418 ) ;
F_241 ( V_409 , V_19 , V_411 ,
V_419 ) ;
return 0 ;
}
static int F_268 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
struct V_410 * V_411 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_253 ( V_19 ,
V_2 -> V_293 [ V_411 -> V_423 + 1 ] ) ;
F_241 ( V_409 , V_19 , V_411 ,
V_420 ) ;
return 0 ;
}
static bool F_205 ( struct V_18 * V_19 , int V_424 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_425 = V_2 -> V_293 [ V_2 -> V_303 [ V_424 ] ] ;
if ( V_2 -> V_426 && V_2 -> V_426 != V_425 ) {
F_269 ( V_19 , V_2 -> V_426 , 1 ) ;
V_2 -> V_426 = V_425 ;
F_251 ( V_19 , V_425 ,
V_2 -> V_427 , 0 ,
V_2 -> V_428 ) ;
return true ;
}
return false ;
}
static int F_270 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
unsigned int V_417 ,
unsigned int V_418 ,
struct V_410 * V_411 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
V_2 -> V_426 = V_2 -> V_293 [ V_2 -> V_303 [ V_2 -> V_252 [ 0 ] ] ] ;
V_2 -> V_427 = V_417 ;
V_2 -> V_428 = V_418 ;
F_251 ( V_19 , V_2 -> V_426 , V_417 , 0 , V_418 ) ;
return 0 ;
}
static int F_271 ( struct V_408 * V_409 ,
struct V_18 * V_19 ,
struct V_410 * V_411 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_253 ( V_19 , V_2 -> V_426 ) ;
V_2 -> V_426 = 0 ;
return 0 ;
}
static void F_272 ( char * V_429 , T_3 V_430 , const char * V_117 ,
const char * V_431 )
{
char * V_432 ;
if ( * V_429 )
return;
F_273 ( V_429 , V_431 , V_430 ) ;
for ( V_432 = strchr ( V_429 , ' ' ) ; V_432 ; V_432 = strchr ( V_432 + 1 , ' ' ) ) {
if ( ! isalnum ( V_432 [ 1 ] ) ) {
* V_432 = 0 ;
break;
}
}
F_35 ( V_429 , V_117 , V_430 ) ;
}
int F_274 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_433 * V_434 = V_2 -> V_402 ;
const struct V_408 * V_432 ;
bool V_435 ;
V_19 -> V_436 = 1 ;
V_19 -> V_437 = V_434 ;
if ( V_2 -> V_398 )
goto V_438;
F_272 ( V_2 -> V_439 ,
sizeof( V_2 -> V_439 ) ,
L_87 , V_19 -> V_431 ) ;
V_434 -> V_10 = V_2 -> V_439 ;
if ( V_2 -> V_134 . V_135 > 0 ) {
V_432 = V_2 -> V_440 ;
if ( ! V_432 )
V_432 = & V_441 ;
V_434 -> V_442 [ V_443 ] = * V_432 ;
V_434 -> V_442 [ V_443 ] . V_48 = V_2 -> V_134 . V_181 [ 0 ] ;
V_434 -> V_442 [ V_443 ] . V_444 =
V_2 -> V_134 . V_238 ;
if ( V_2 -> V_127 . V_139 == V_140 &&
V_2 -> V_127 . V_128 == 2 )
V_434 -> V_442 [ V_443 ] . V_445 =
V_446 ;
}
if ( V_2 -> V_295 ) {
V_432 = V_2 -> V_447 ;
if ( ! V_432 ) {
if ( V_2 -> V_304 )
V_432 = & V_448 ;
else
V_432 = & V_449 ;
}
V_434 -> V_442 [ V_450 ] = * V_432 ;
V_434 -> V_442 [ V_450 ] . V_48 = V_2 -> V_293 [ 0 ] ;
}
V_438:
if ( V_2 -> V_134 . V_347 || V_2 -> V_352 ) {
F_272 ( V_2 -> V_451 ,
sizeof( V_2 -> V_451 ) ,
L_88 , V_19 -> V_431 ) ;
V_19 -> V_436 = 2 ;
V_19 -> V_349 = V_2 -> V_134 . V_349 ;
V_434 = V_2 -> V_402 + 1 ;
V_434 -> V_10 = V_2 -> V_451 ;
if ( V_2 -> V_348 )
V_434 -> V_403 = V_2 -> V_348 ;
else
V_434 -> V_403 = V_452 ;
if ( V_2 -> V_134 . V_347 ) {
V_432 = V_2 -> V_453 ;
if ( ! V_432 )
V_432 = & V_454 ;
V_434 -> V_442 [ V_443 ] = * V_432 ;
V_434 -> V_442 [ V_443 ] . V_48 = V_2 -> V_134 . V_347 ;
}
if ( V_2 -> V_352 ) {
V_432 = V_2 -> V_455 ;
if ( ! V_432 )
V_432 = & V_456 ;
V_434 -> V_442 [ V_450 ] = * V_432 ;
V_434 -> V_442 [ V_450 ] . V_48 = V_2 -> V_352 ;
}
}
if ( V_2 -> V_398 )
return 0 ;
V_435 = ( V_2 -> V_295 > 1 ) &&
! V_2 -> V_304 && ! V_2 -> V_336 ;
if ( V_2 -> V_230 || V_435 ) {
F_272 ( V_2 -> V_457 ,
sizeof( V_2 -> V_457 ) ,
L_89 , V_19 -> V_431 ) ;
V_19 -> V_436 = 3 ;
V_434 = V_2 -> V_402 + 2 ;
V_434 -> V_10 = V_2 -> V_457 ;
if ( V_2 -> V_230 ) {
V_432 = V_2 -> V_458 ;
if ( ! V_432 )
V_432 = & V_459 ;
V_434 -> V_442 [ V_443 ] = * V_432 ;
V_434 -> V_442 [ V_443 ] . V_48 =
V_2 -> V_230 ;
} else {
V_434 -> V_442 [ V_443 ] =
V_460 ;
V_434 -> V_442 [ V_443 ] . V_48 = 0 ;
}
if ( V_435 ) {
V_432 = V_2 -> V_461 ;
if ( ! V_432 )
V_432 = & V_462 ;
V_434 -> V_442 [ V_450 ] = * V_432 ;
V_434 -> V_442 [ V_450 ] . V_48 =
V_2 -> V_293 [ 1 ] ;
V_434 -> V_442 [ V_450 ] . V_463 =
V_2 -> V_295 - 1 ;
} else {
V_434 -> V_442 [ V_450 ] =
V_460 ;
V_434 -> V_442 [ V_450 ] . V_48 = 0 ;
}
}
return 0 ;
}
static void F_275 ( struct V_18 * V_19 , int V_110 )
{
struct V_6 * V_50 ;
T_1 V_44 ;
V_50 = F_27 ( V_19 , V_110 ) ;
if ( ! V_50 || ! V_50 -> V_51 )
return;
V_44 = V_50 -> V_50 [ V_50 -> V_51 - 1 ] ;
F_14 ( V_19 , V_44 ) ;
F_64 ( V_19 , V_50 , V_50 -> V_86 ,
F_134 ( V_19 -> V_2 ) ) ;
F_72 ( V_19 , V_44 , V_50 -> V_86 ) ;
}
static void F_276 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_127 . V_128 ; V_16 ++ )
F_275 ( V_19 , V_2 -> V_174 [ V_16 ] ) ;
}
static void F_277 ( struct V_18 * V_19 , int V_150 , int * V_5 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_150 ; V_16 ++ )
F_275 ( V_19 , V_5 [ V_16 ] ) ;
}
static void F_278 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_127 . V_139 != V_142 )
F_277 ( V_19 , V_2 -> V_127 . V_130 , V_2 -> V_141 ) ;
if ( V_2 -> V_127 . V_139 != V_140 )
F_277 ( V_19 , V_2 -> V_127 . V_131 ,
V_2 -> V_143 ) ;
}
static void F_279 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_129 ; V_16 ++ ) {
T_1 V_44 = V_2 -> V_148 [ V_16 ] . V_44 ;
struct V_6 * V_50 ;
V_50 = F_133 ( V_19 , V_16 ) ;
if ( ! V_50 )
continue;
if ( ! V_2 -> V_148 [ V_16 ] . V_237 )
V_2 -> V_148 [ V_16 ] . V_237 =
F_16 ( V_19 , V_44 ) ;
F_64 ( V_19 , V_50 , V_50 -> V_86 ,
F_134 ( V_2 ) ) ;
}
}
static void F_280 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_125 * V_126 = & V_2 -> V_127 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_126 -> V_169 ; V_16 ++ ) {
T_1 V_48 = V_126 -> V_170 [ V_16 ] . V_44 ;
if ( F_173 ( V_19 , V_48 ) )
F_14 ( V_19 , V_48 ) ;
if ( V_2 -> V_43 ) {
F_75 ( V_19 , V_2 -> V_185 [ V_16 ] ) ;
F_75 ( V_19 , V_2 -> V_292 ) ;
}
}
}
static void F_281 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_298 * V_299 = & V_2 -> V_300 ;
struct V_6 * V_50 ;
int V_16 , V_311 , V_49 ;
if ( V_2 -> V_304 )
V_49 = 1 ;
else
V_49 = V_2 -> V_295 ;
for ( V_311 = 0 ; V_311 < V_49 ; V_311 ++ ) {
for ( V_16 = 0 ; V_16 < V_299 -> V_302 ; V_16 ++ ) {
V_50 = F_181 ( V_19 , V_311 , V_16 ) ;
if ( V_50 ) {
bool V_86 = V_50 -> V_86 ;
if ( V_16 == V_2 -> V_252 [ V_311 ] )
V_86 = true ;
F_64 ( V_19 , V_50 , V_86 , false ) ;
}
}
if ( V_2 -> V_41 )
F_143 ( V_19 , V_311 , true ) ;
}
if ( V_2 -> V_324 )
V_2 -> V_324 ( V_19 , NULL ) ;
}
static void F_282 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_44 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_127 . V_345 ; V_16 ++ )
F_275 ( V_19 , V_2 -> V_183 [ V_16 ] ) ;
V_44 = V_2 -> V_127 . V_350 ;
if ( V_44 ) {
F_14 ( V_19 , V_44 ) ;
F_75 ( V_19 , V_2 -> V_186 ) ;
}
}
static void F_283 ( struct V_18 * V_19 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_464 . V_17 ; V_16 ++ ) {
struct V_465 * V_44 = F_24 ( & V_19 -> V_464 , V_16 ) ;
T_1 V_48 = V_44 -> V_48 ;
if ( F_221 ( V_19 , V_48 ) &&
! F_284 ( V_19 , V_48 ) )
F_74 ( V_19 , V_48 , 0 ,
V_466 , 0 ) ;
}
}
int F_285 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_467 )
V_2 -> V_467 ( V_19 ) ;
F_286 ( V_19 ) ;
V_19 -> V_323 = 1 ;
F_276 ( V_19 ) ;
F_278 ( V_19 ) ;
F_279 ( V_19 ) ;
F_280 ( V_19 ) ;
F_281 ( V_19 ) ;
F_282 ( V_19 ) ;
F_283 ( V_19 ) ;
F_136 ( V_19 ) ;
F_189 ( V_19 ) ;
if ( V_2 -> V_132 . V_406 && V_2 -> V_132 . V_133 )
F_287 ( & V_2 -> V_132 ) ;
F_288 ( V_19 , 0x01 ) ;
return 0 ;
}
void F_289 ( struct V_18 * V_19 )
{
F_290 ( V_19 ) ;
F_10 ( V_19 -> V_2 ) ;
F_8 ( V_19 -> V_2 ) ;
V_19 -> V_2 = NULL ;
}
int F_291 ( struct V_18 * V_19 , T_1 V_48 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_292 ( V_19 , & V_2 -> V_286 , V_48 ) ;
}
int F_293 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_180 ;
V_2 = F_294 ( sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 )
return - V_118 ;
F_1 ( V_2 ) ;
V_19 -> V_2 = V_2 ;
V_180 = F_295 ( V_19 , & V_2 -> V_127 , NULL , 0 ) ;
if ( V_180 < 0 )
return V_180 ;
V_180 = F_228 ( V_19 , & V_2 -> V_127 ) ;
if ( V_180 < 0 )
goto error;
V_19 -> V_468 = V_469 ;
return 0 ;
error:
F_289 ( V_19 ) ;
return V_180 ;
}
