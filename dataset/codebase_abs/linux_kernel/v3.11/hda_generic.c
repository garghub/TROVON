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
V_2 -> V_40 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_22 ) ;
if ( V_20 >= 0 )
V_2 -> V_40 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_23 ) ;
if ( V_20 >= 0 )
V_2 -> V_41 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_24 ) ;
if ( V_20 >= 0 )
V_2 -> V_42 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_25 ) ;
if ( V_20 >= 0 )
V_2 -> V_43 = ! V_20 ;
if ( ! F_13 ( V_19 , L_26 , & V_20 ) )
V_2 -> V_44 = V_20 ;
}
static inline void F_14 ( struct V_18 * V_19 , T_1 V_45 )
{
F_15 ( V_19 , V_45 , F_16 ( V_19 , V_45 ) ) ;
}
static void F_17 ( struct V_18 * V_19 , T_1 V_45 ,
unsigned int V_20 , bool V_46 )
{
if ( ! V_45 )
return;
V_20 = F_18 ( V_19 , V_45 , V_20 ) ;
F_19 ( V_19 , V_45 , V_20 ) ;
if ( V_46 )
F_15 ( V_19 , V_45 , V_20 ) ;
}
static void F_20 ( struct V_18 * V_19 , int V_47 ,
T_1 * V_48 , unsigned int V_20 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_47 ; V_16 ++ )
F_17 ( V_19 , V_48 [ V_16 ] , V_20 , false ) ;
}
static int F_21 ( T_1 V_49 , const T_1 * V_14 , int V_50 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_50 ; V_16 ++ )
if ( V_14 [ V_16 ] == V_49 )
return V_16 ;
return - 1 ;
}
static bool F_22 ( struct V_6 * V_51 , T_1 V_49 )
{
return F_21 ( V_49 , V_51 -> V_51 , V_51 -> V_52 ) >= 0 ;
}
static struct V_6 * F_23 ( struct V_18 * V_19 ,
T_1 V_53 , T_1 V_54 ,
int V_55 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 . V_17 ; V_16 ++ ) {
struct V_6 * V_51 = F_24 ( & V_2 -> V_5 , V_16 ) ;
if ( V_51 -> V_52 <= 0 )
continue;
if ( ( ! V_53 || V_51 -> V_51 [ 0 ] == V_53 ) &&
( ! V_54 || V_51 -> V_51 [ V_51 -> V_52 - 1 ] == V_54 ) ) {
if ( ! V_55 ||
( V_55 > 0 && F_22 ( V_51 , V_55 ) ) ||
( V_55 < 0 && ! F_22 ( V_51 , V_55 ) ) )
return V_51 ;
}
}
return NULL ;
}
struct V_6 * F_25 ( struct V_18 * V_19 ,
T_1 V_53 , T_1 V_54 )
{
return F_23 ( V_19 , V_53 , V_54 , 0 ) ;
}
int F_26 ( struct V_18 * V_19 , struct V_6 * V_51 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_56 = V_2 -> V_5 . V_14 ;
T_2 V_57 ;
if ( ! V_2 -> V_5 . V_17 )
return 0 ;
V_57 = V_51 - V_56 ;
if ( V_57 < 0 || V_57 >= V_2 -> V_5 . V_17 )
return 0 ;
return V_57 + 1 ;
}
struct V_6 * F_27 ( struct V_18 * V_19 , int V_57 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_57 <= 0 || V_57 > V_2 -> V_5 . V_17 )
return NULL ;
return F_24 ( & V_2 -> V_5 , V_57 - 1 ) ;
}
static bool F_28 ( struct V_18 * V_19 , T_1 V_49 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 . V_17 ; V_16 ++ ) {
struct V_6 * V_51 = F_24 ( & V_2 -> V_5 , V_16 ) ;
if ( V_51 -> V_51 [ 0 ] == V_49 )
return true ;
}
return false ;
}
static bool F_29 ( struct V_18 * V_19 ,
T_1 V_53 , T_1 V_54 )
{
if ( ! V_53 || ! V_54 )
return false ;
return F_30 ( V_19 , V_54 , V_53 , true ) >= 0 ;
}
static bool F_31 ( struct V_18 * V_19 , unsigned int V_20 , int type )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
V_20 &= V_58 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 . V_17 ; V_16 ++ ) {
struct V_6 * V_51 = F_24 ( & V_2 -> V_5 , V_16 ) ;
if ( ( V_51 -> V_59 [ type ] & V_58 ) == V_20 )
return true ;
}
return false ;
}
static bool F_32 ( struct V_18 * V_19 , T_1 V_49 ,
int V_60 , int V_57 , int type )
{
unsigned int V_20 = F_33 ( V_49 , 3 , V_57 , V_60 ) ;
return F_31 ( V_19 , V_20 , type ) ;
}
static void F_34 ( const char * V_61 , struct V_6 * V_51 )
{
char V_62 [ 40 ] ;
int V_16 ;
V_62 [ 0 ] = 0 ;
for ( V_16 = 0 ; V_16 < V_51 -> V_52 ; V_16 ++ ) {
char V_63 [ 4 ] ;
sprintf ( V_63 , L_27 , V_51 -> V_51 [ V_16 ] ) ;
F_35 ( V_62 , V_63 , sizeof( V_62 ) ) ;
}
F_36 ( L_28 , V_61 , V_51 -> V_52 , V_62 ) ;
}
static bool F_37 ( struct V_18 * V_19 ,
T_1 V_53 , T_1 V_54 ,
int V_55 , struct V_6 * V_51 ,
int V_52 )
{
const T_1 * V_64 ;
int V_16 , V_50 ;
if ( V_54 == V_55 )
V_55 = 0 ;
else if ( V_54 == ( T_1 ) ( - V_55 ) )
return false ;
V_50 = F_38 ( V_19 , V_54 , & V_64 ) ;
for ( V_16 = 0 ; V_16 < V_50 ; V_16 ++ ) {
if ( V_64 [ V_16 ] != V_53 ) {
if ( V_53 ||
F_39 ( F_40 ( V_19 , V_64 [ V_16 ] ) ) != V_65 ||
F_28 ( V_19 , V_64 [ V_16 ] ) )
continue;
}
if ( V_55 <= 0 )
goto V_66;
}
if ( V_52 >= V_67 )
return false ;
for ( V_16 = 0 ; V_16 < V_50 ; V_16 ++ ) {
unsigned int type ;
type = F_39 ( F_40 ( V_19 , V_64 [ V_16 ] ) ) ;
if ( type == V_65 || type == V_68 ||
type == V_69 )
continue;
if ( F_37 ( V_19 , V_53 , V_64 [ V_16 ] ,
V_55 , V_51 , V_52 + 1 ) )
goto V_66;
}
return false ;
V_66:
V_51 -> V_51 [ V_51 -> V_52 ] = V_64 [ V_16 ] ;
V_51 -> V_57 [ V_51 -> V_52 + 1 ] = V_16 ;
if ( V_50 > 1 && F_39 ( F_40 ( V_19 , V_54 ) ) != V_70 )
V_51 -> V_71 [ V_51 -> V_52 + 1 ] = 1 ;
V_51 -> V_52 ++ ;
return true ;
}
bool F_41 ( struct V_18 * V_19 , T_1 V_53 ,
T_1 V_54 , int V_55 ,
struct V_6 * V_51 )
{
if ( F_37 ( V_19 , V_53 , V_54 , V_55 , V_51 , 1 ) ) {
V_51 -> V_51 [ V_51 -> V_52 ] = V_54 ;
V_51 -> V_52 ++ ;
return true ;
}
return false ;
}
struct V_6 *
F_42 ( struct V_18 * V_19 , T_1 V_53 ,
T_1 V_54 , int V_55 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_51 ;
if ( V_53 && V_54 && ! F_29 ( V_19 , V_53 , V_54 ) )
return NULL ;
V_51 = F_23 ( V_19 , V_53 , V_54 , V_55 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_5 ( & V_2 -> V_5 ) ;
if ( ! V_51 )
return NULL ;
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
if ( F_41 ( V_19 , V_53 , V_54 , V_55 , V_51 ) )
return V_51 ;
V_2 -> V_5 . V_17 -- ;
return NULL ;
}
static void F_43 ( struct V_18 * V_19 , int V_57 )
{
struct V_6 * V_51 = F_27 ( V_19 , V_57 ) ;
if ( ! V_51 )
return;
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
}
static T_1 F_44 ( struct V_18 * V_19 , T_1 V_45 ,
bool V_72 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_73 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_74 ; V_16 ++ ) {
T_1 V_49 = V_2 -> V_75 [ V_16 ] ;
if ( ! V_49 || F_28 ( V_19 , V_49 ) )
continue;
V_73 = ! ! ( F_40 ( V_19 , V_49 ) & V_76 ) ;
if ( V_72 != V_73 )
continue;
if ( F_29 ( V_19 , V_49 , V_45 ) )
return V_49 ;
}
return 0 ;
}
static unsigned int F_45 ( unsigned int V_20 , unsigned int V_77 )
{
V_20 &= ~ ( 0x3U << 16 ) ;
V_20 |= V_77 << 16 ;
return V_20 ;
}
static bool F_46 ( struct V_18 * V_19 , T_1 V_49 ,
int V_60 , unsigned int V_78 )
{
if ( ! V_49 )
return false ;
if ( F_40 ( V_19 , V_49 ) & ( 1 << ( V_60 + 1 ) ) )
if ( F_47 ( V_19 , V_49 , V_60 ) & V_78 )
return true ;
return false ;
}
static bool F_48 ( struct V_18 * V_19 , T_1 V_79 ,
T_1 V_80 , int V_60 )
{
if ( ! ( F_40 ( V_19 , V_79 ) & ( 1 << ( V_60 + 1 ) ) ) )
return ! ( F_40 ( V_19 , V_80 ) & ( 1 << ( V_60 + 1 ) ) ) ;
return ( F_47 ( V_19 , V_79 , V_60 ) ==
F_47 ( V_19 , V_80 , V_60 ) ) ;
}
static T_1 F_49 ( struct V_18 * V_19 ,
struct V_6 * V_51 )
{
int V_16 ;
for ( V_16 = V_51 -> V_52 - 1 ; V_16 >= 0 ; V_16 -- ) {
if ( F_50 ( V_19 , V_51 -> V_51 [ V_16 ] , V_81 ) )
return V_51 -> V_51 [ V_16 ] ;
if ( V_16 != V_51 -> V_52 - 1 && V_16 != 0 &&
F_50 ( V_19 , V_51 -> V_51 [ V_16 ] , V_82 ) )
return V_51 -> V_51 [ V_16 ] ;
}
return 0 ;
}
static T_1 F_51 ( struct V_18 * V_19 ,
struct V_6 * V_51 )
{
int V_16 ;
for ( V_16 = V_51 -> V_52 - 1 ; V_16 >= 0 ; V_16 -- ) {
if ( F_52 ( V_19 , V_51 -> V_51 [ V_16 ] , V_81 ) )
return V_51 -> V_51 [ V_16 ] ;
}
return 0 ;
}
static bool F_53 ( struct V_18 * V_19 , struct V_6 * V_51 , int V_57 )
{
T_1 V_49 = V_51 -> V_51 [ V_57 ] ;
unsigned int V_83 = F_40 ( V_19 , V_49 ) ;
unsigned int type = F_39 ( V_83 ) ;
if ( ! ( V_83 & V_84 ) )
return false ;
if ( type == V_69 && V_57 > 0 )
return false ;
return true ;
}
static bool F_54 ( struct V_18 * V_19 , struct V_6 * V_51 , int V_57 )
{
T_1 V_49 = V_51 -> V_51 [ V_57 ] ;
unsigned int V_83 = F_40 ( V_19 , V_49 ) ;
unsigned int type = F_39 ( V_83 ) ;
if ( ! ( V_83 & V_85 ) )
return false ;
if ( type == V_69 && ! V_57 )
return false ;
return true ;
}
static bool F_55 ( struct V_18 * V_19 , T_1 V_49 ,
unsigned int V_60 , unsigned int V_57 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_86 ;
for ( V_86 = 0 ; V_86 < V_2 -> V_5 . V_17 ; V_86 ++ ) {
struct V_6 * V_51 = F_24 ( & V_2 -> V_5 , V_86 ) ;
if ( ! V_51 -> V_87 )
continue;
for ( V_16 = 0 ; V_16 < V_51 -> V_52 ; V_16 ++ ) {
if ( V_51 -> V_51 [ V_16 ] == V_49 ) {
if ( V_60 == V_81 || V_51 -> V_57 [ V_16 ] == V_57 )
return true ;
break;
}
}
}
return false ;
}
static int F_56 ( struct V_18 * V_19 , T_1 V_49 ,
int V_60 , unsigned int V_83 , bool V_88 )
{
unsigned int V_20 = 0 ;
if ( V_83 & V_89 ) {
if ( V_88 )
V_20 = ( V_83 & V_90 ) >> V_91 ;
}
if ( V_83 & ( V_92 | V_93 ) ) {
if ( ! V_88 )
V_20 |= V_94 ;
}
return V_20 ;
}
static void F_57 ( struct V_18 * V_19 , T_1 V_49 , int V_60 , int V_57 )
{
unsigned int V_83 = F_47 ( V_19 , V_49 , V_60 ) ;
int V_20 = F_56 ( V_19 , V_49 , V_60 , V_83 , false ) ;
F_58 ( V_19 , V_49 , V_60 , V_57 , 0xff , V_20 ) ;
}
static unsigned int F_59 ( struct V_18 * V_19 ,
T_1 V_49 , int V_60 , int V_57 ,
unsigned int V_83 )
{
unsigned int V_95 = 0xff ;
if ( V_83 & ( V_92 | V_93 ) ) {
if ( F_32 ( V_19 , V_49 , V_60 , V_57 , V_96 ) )
V_95 &= ~ 0x80 ;
}
if ( V_83 & V_89 ) {
if ( F_32 ( V_19 , V_49 , V_60 , V_57 , V_97 ) ||
F_32 ( V_19 , V_49 , V_60 , V_57 , V_98 ) )
V_95 &= ~ 0x7f ;
}
return V_95 ;
}
static void F_60 ( struct V_18 * V_19 , T_1 V_49 , int V_60 ,
int V_57 , int V_99 , bool V_88 )
{
unsigned int V_83 ;
unsigned int V_95 , V_20 ;
if ( ! V_88 && F_55 ( V_19 , V_49 , V_60 , V_99 ) )
return;
V_83 = F_47 ( V_19 , V_49 , V_60 ) ;
V_20 = F_56 ( V_19 , V_49 , V_60 , V_83 , V_88 ) ;
V_95 = F_59 ( V_19 , V_49 , V_60 , V_99 , V_83 ) ;
if ( ! V_95 )
return;
V_20 &= V_95 ;
F_61 ( V_19 , V_49 , V_60 , V_57 , V_95 , V_20 ) ;
}
static void F_62 ( struct V_18 * V_19 , struct V_6 * V_51 ,
int V_16 , bool V_88 )
{
T_1 V_49 = V_51 -> V_51 [ V_16 ] ;
F_57 ( V_19 , V_49 , V_81 , 0 ) ;
F_60 ( V_19 , V_49 , V_81 , 0 , 0 , V_88 ) ;
}
static void F_63 ( struct V_18 * V_19 , struct V_6 * V_51 ,
int V_16 , bool V_88 , bool V_100 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const T_1 * V_64 ;
int V_86 , V_50 , V_57 ;
int type ;
T_1 V_49 = V_51 -> V_51 [ V_16 ] ;
V_50 = F_38 ( V_19 , V_49 , & V_64 ) ;
type = F_39 ( F_40 ( V_19 , V_49 ) ) ;
if ( type == V_69 ||
( type == V_68 && V_19 -> V_29 ) ) {
V_50 = 1 ;
V_57 = 0 ;
} else
V_57 = V_51 -> V_57 [ V_16 ] ;
for ( V_86 = 0 ; V_86 < V_50 ; V_86 ++ )
F_57 ( V_19 , V_49 , V_82 , V_86 ) ;
for ( V_86 = 0 ; V_86 < V_50 ; V_86 ++ ) {
if ( V_86 != V_57 && ( ! V_100 || V_64 [ V_86 ] != V_2 -> V_101 ) )
continue;
F_60 ( V_19 , V_49 , V_82 , V_86 , V_57 , V_88 ) ;
}
}
void F_64 ( struct V_18 * V_19 , struct V_6 * V_51 ,
bool V_88 , bool V_100 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
if ( ! V_88 )
V_51 -> V_87 = false ;
for ( V_16 = V_51 -> V_52 - 1 ; V_16 >= 0 ; V_16 -- ) {
T_1 V_49 = V_51 -> V_51 [ V_16 ] ;
if ( V_88 && V_2 -> V_41 ) {
if ( ! F_65 ( V_19 , V_49 , V_102 ) )
F_66 ( V_19 , V_49 , 0 ,
V_103 ,
V_102 ) ;
}
if ( V_88 && V_51 -> V_71 [ V_16 ] )
F_67 ( V_19 , V_49 , 0 ,
V_104 ,
V_51 -> V_57 [ V_16 ] ) ;
if ( F_53 ( V_19 , V_51 , V_16 ) )
F_63 ( V_19 , V_51 , V_16 , V_88 , V_100 ) ;
if ( F_54 ( V_19 , V_51 , V_16 ) )
F_62 ( V_19 , V_51 , V_16 , V_88 ) ;
}
if ( V_88 )
V_51 -> V_87 = true ;
}
static void F_68 ( struct V_18 * V_19 , struct V_6 * V_51 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_105 = false ;
int V_16 ;
if ( ! V_2 -> V_41 || V_51 -> V_87 )
return;
for ( V_16 = 0 ; V_16 < V_51 -> V_52 ; V_16 ++ ) {
T_1 V_49 = V_51 -> V_51 [ V_16 ] ;
if ( ! F_65 ( V_19 , V_49 , V_106 ) &&
! F_69 ( V_19 , V_49 ) ) {
F_66 ( V_19 , V_49 , 0 ,
V_103 ,
V_106 ) ;
V_105 = true ;
}
}
if ( V_105 ) {
F_70 ( 10 ) ;
F_71 ( V_19 , V_51 -> V_51 [ 0 ] , 0 ,
V_107 , 0 ) ;
}
}
static void F_72 ( struct V_18 * V_19 , T_1 V_45 , bool V_88 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_108 ||
! ( F_73 ( V_19 , V_45 ) & V_109 ) )
return;
if ( V_19 -> V_24 )
V_88 = ! V_88 ;
if ( V_2 -> V_110 && ! V_88 )
return;
F_74 ( V_19 , V_45 , 0 ,
V_111 ,
V_88 ? 0x02 : 0x00 ) ;
}
static void F_75 ( struct V_18 * V_19 , int V_112 )
{
struct V_6 * V_51 = F_27 ( V_19 , V_112 ) ;
if ( V_51 )
F_64 ( V_19 , V_51 , V_51 -> V_87 , false ) ;
}
static struct V_4 *
F_76 ( struct V_1 * V_2 , int type , const char * V_10 ,
int V_113 , unsigned long V_20 )
{
struct V_4 * V_12 ;
V_12 = F_4 ( V_2 , V_10 , & V_114 [ type ] ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_115 = V_113 ;
if ( F_77 ( V_20 ) )
V_12 -> V_116 = V_117 ;
V_12 -> V_118 = V_20 ;
return V_12 ;
}
static int F_78 ( struct V_1 * V_2 , int type ,
const char * V_61 , const char * V_60 ,
const char * V_119 , int V_113 , unsigned long V_20 )
{
char V_10 [ V_120 ] ;
snprintf ( V_10 , sizeof( V_10 ) , L_29 , V_61 , V_60 , V_119 ) ;
if ( ! F_76 ( V_2 , type , V_10 , V_113 , V_20 ) )
return - V_121 ;
return 0 ;
}
static int F_79 ( struct V_18 * V_19 , const char * V_61 , int V_113 ,
unsigned int V_77 , struct V_6 * V_51 )
{
unsigned int V_20 ;
if ( ! V_51 )
return 0 ;
V_20 = V_51 -> V_59 [ V_97 ] ;
if ( ! V_20 )
return 0 ;
V_20 = F_45 ( V_20 , V_77 ) ;
return F_80 ( V_19 -> V_2 , V_122 , V_61 , V_113 , V_20 ) ;
}
static int F_81 ( struct V_18 * V_19 , struct V_6 * V_51 ,
int type )
{
int V_77 = 1 ;
if ( V_51 ) {
T_1 V_49 = F_77 ( V_51 -> V_59 [ type ] ) ;
if ( V_49 && ( F_40 ( V_19 , V_49 ) & V_123 ) )
V_77 = 3 ;
}
return V_77 ;
}
static int F_82 ( struct V_18 * V_19 , const char * V_61 , int V_113 ,
struct V_6 * V_51 )
{
int V_77 = F_81 ( V_19 , V_51 , V_97 ) ;
return F_79 ( V_19 , V_61 , V_113 , V_77 , V_51 ) ;
}
static int F_83 ( struct V_18 * V_19 , const char * V_61 , int V_113 ,
unsigned int V_77 , struct V_6 * V_51 )
{
unsigned int V_20 ;
int type = V_124 ;
if ( ! V_51 )
return 0 ;
V_20 = V_51 -> V_59 [ V_96 ] ;
if ( ! V_20 )
return 0 ;
V_20 = F_45 ( V_20 , V_77 ) ;
if ( F_84 ( V_20 ) == V_82 ) {
T_1 V_49 = F_77 ( V_20 ) ;
int V_50 = F_85 ( V_19 , V_49 ) ;
if ( V_50 > 1 ) {
type = V_125 ;
V_20 |= V_50 << 19 ;
}
}
return F_86 ( V_19 -> V_2 , type , V_61 , V_113 , V_20 ) ;
}
static int F_87 ( struct V_18 * V_19 , const char * V_61 ,
int V_113 , struct V_6 * V_51 )
{
int V_77 = F_81 ( V_19 , V_51 , V_96 ) ;
return F_83 ( V_19 , V_61 , V_113 , V_77 , V_51 ) ;
}
static int F_88 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_33 ) {
T_1 V_49 = F_90 ( V_127 ) ;
bool V_130 = ! ( ( V_2 -> V_131 >> V_49 ) & 1 ) ;
V_129 -> V_132 . integer . V_132 [ 0 ] &= V_130 ;
V_129 -> V_132 . integer . V_132 [ 1 ] &= V_130 ;
}
return F_91 ( V_127 , V_129 ) ;
}
static bool F_92 ( struct V_18 * V_19 , int V_112 , int V_133 )
{
struct V_6 * V_51 = F_27 ( V_19 , V_112 ) ;
return V_51 && V_51 -> V_59 [ V_133 ] ;
}
static const char * F_93 ( struct V_18 * V_19 , int V_134 ,
int * V_115 , int V_133 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_135 * V_136 = & V_2 -> V_137 ;
* V_115 = 0 ;
if ( V_136 -> V_138 == 1 && ! V_2 -> V_139 &&
! V_136 -> V_140 && ! V_136 -> V_141 )
return V_2 -> V_142 . V_143 ? L_30 : L_31 ;
if ( V_2 -> V_144 . V_145 == 1 && ! V_2 -> V_44 &&
! V_2 -> V_144 . V_146 [ 0 ] && ! V_2 -> V_144 . V_147 [ 0 ] )
return V_2 -> V_142 . V_143 ? L_30 : L_31 ;
if ( V_134 >= V_136 -> V_138 )
return V_148 [ V_134 ] ;
switch ( V_136 -> V_149 ) {
case V_150 :
if ( ! V_134 && V_136 -> V_140 &&
! F_92 ( V_19 , V_2 -> V_151 [ 0 ] , V_133 ) )
break;
if ( V_136 -> V_138 == 1 )
return L_32 ;
if ( V_136 -> V_138 == 2 )
return V_134 ? L_33 : L_32 ;
break;
case V_152 :
if ( ! V_134 && V_136 -> V_141 &&
! F_92 ( V_19 , V_2 -> V_153 [ 0 ] , V_133 ) )
break;
if ( V_134 && V_2 -> V_139 )
break;
* V_115 = V_134 ;
return L_34 ;
}
if ( V_136 -> V_138 == 1 && ! V_2 -> V_139 )
return L_30 ;
if ( V_134 >= F_94 ( V_148 ) ) {
F_95 () ;
return L_30 ;
}
return V_148 [ V_134 ] ;
}
static int F_96 ( struct V_18 * V_19 , struct V_6 * V_51 )
{
T_1 V_49 ;
unsigned int V_20 ;
int V_154 = 0 ;
if ( ! V_51 )
return V_155 * 2 ;
if ( V_51 -> V_59 [ V_97 ] ||
V_51 -> V_59 [ V_96 ] )
return 0 ;
V_49 = F_51 ( V_19 , V_51 ) ;
if ( V_49 ) {
V_20 = F_33 ( V_49 , 3 , 0 , V_81 ) ;
if ( F_31 ( V_19 , V_20 , V_97 ) )
V_154 += V_155 ;
else
V_51 -> V_59 [ V_97 ] = V_20 ;
} else
V_154 += V_155 ;
V_49 = F_49 ( V_19 , V_51 ) ;
if ( V_49 ) {
unsigned int V_156 = F_39 ( F_40 ( V_19 , V_49 ) ) ;
if ( V_156 == V_69 || V_156 == V_65 ||
F_50 ( V_19 , V_49 , V_81 ) )
V_20 = F_33 ( V_49 , 3 , 0 , V_81 ) ;
else
V_20 = F_33 ( V_49 , 3 , 0 , V_82 ) ;
if ( F_31 ( V_19 , V_20 , V_96 ) )
V_154 += V_155 ;
else
V_51 -> V_59 [ V_96 ] = V_20 ;
} else
V_154 += V_155 ;
return V_154 ;
}
static T_1 F_97 ( struct V_18 * V_19 , int V_57 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_135 * V_136 = & V_2 -> V_137 ;
if ( V_136 -> V_138 > V_57 )
return V_2 -> V_157 [ V_57 ] ;
V_57 -= V_136 -> V_138 ;
if ( V_2 -> V_139 > V_57 )
return V_2 -> V_158 [ V_57 ] . V_159 ;
return 0 ;
}
static inline T_1 F_98 ( struct V_18 * V_19 ,
T_1 V_159 , T_1 V_45 )
{
return F_29 ( V_19 , V_159 , V_45 ) ? V_159 : 0 ;
}
static int F_99 ( struct V_18 * V_19 , int V_160 ,
const T_1 * V_48 , T_1 * V_161 ,
int * V_112 ,
const struct V_162 * V_163 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_164 ;
int V_154 = 0 ;
T_1 V_159 ;
if ( ! V_160 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_160 ; V_16 ++ ) {
struct V_6 * V_51 ;
T_1 V_45 = V_48 [ V_16 ] ;
V_51 = F_27 ( V_19 , V_112 [ V_16 ] ) ;
if ( V_51 ) {
V_154 += F_96 ( V_19 , V_51 ) ;
continue;
}
V_161 [ V_16 ] = F_44 ( V_19 , V_45 , false ) ;
if ( ! V_161 [ V_16 ] && ! V_16 ) {
for ( V_164 = 1 ; V_164 < V_160 ; V_164 ++ ) {
if ( F_29 ( V_19 , V_161 [ V_164 ] , V_45 ) ) {
V_161 [ 0 ] = V_161 [ V_164 ] ;
V_161 [ V_164 ] = 0 ;
F_43 ( V_19 , V_112 [ V_164 ] ) ;
V_112 [ V_164 ] = 0 ;
break;
}
}
}
V_159 = V_161 [ V_16 ] ;
if ( ! V_159 ) {
if ( V_160 > 2 )
V_159 = F_98 ( V_19 , F_97 ( V_19 , V_16 ) , V_45 ) ;
if ( ! V_159 )
V_159 = F_98 ( V_19 , V_161 [ 0 ] , V_45 ) ;
if ( ! V_159 )
V_159 = F_98 ( V_19 , F_97 ( V_19 , V_16 ) , V_45 ) ;
if ( V_159 ) {
if ( ! V_16 )
V_154 += V_163 -> V_165 ;
else if ( V_16 == 1 )
V_154 += V_163 -> V_166 ;
else
V_154 += V_163 -> V_167 ;
} else if ( F_29 ( V_19 , V_2 -> V_157 [ 0 ] , V_45 ) ) {
V_159 = V_2 -> V_157 [ 0 ] ;
V_154 += V_163 -> V_168 ;
} else if ( ! V_16 )
V_154 += V_163 -> V_169 ;
else
V_154 += V_163 -> V_170 ;
}
if ( ! V_159 )
continue;
V_51 = F_42 ( V_19 , V_159 , V_45 , - V_2 -> V_44 ) ;
if ( ! V_51 && ! V_16 && V_2 -> V_44 ) {
V_51 = F_42 ( V_19 , V_159 , V_45 , 0 ) ;
}
if ( ! V_51 ) {
V_159 = V_161 [ V_16 ] = 0 ;
V_154 += V_163 -> V_170 ;
} else {
V_51 -> V_87 = true ;
V_112 [ V_16 ] = F_26 ( V_19 , V_51 ) ;
V_154 += F_96 ( V_19 , V_51 ) ;
}
}
return V_154 ;
}
static T_1 F_100 ( struct V_18 * V_19 , T_1 V_45 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_171 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_74 ; V_16 ++ ) {
T_1 V_49 = V_2 -> V_75 [ V_16 ] ;
if ( ! V_49 || F_28 ( V_19 , V_49 ) )
continue;
if ( F_29 ( V_19 , V_49 , V_45 ) ) {
if ( V_171 )
return 0 ;
V_171 = V_49 ;
}
}
return V_171 ;
}
static bool F_101 ( struct V_18 * V_19 ,
unsigned int V_172 , T_1 V_49 )
{
unsigned int V_173 , V_83 ;
V_173 = F_102 ( V_19 , V_49 ) ;
if ( F_103 ( V_173 ) != V_174 )
return false ;
if ( V_172 && F_104 ( V_173 ) != V_172 )
return false ;
V_83 = F_73 ( V_19 , V_49 ) ;
if ( ! ( V_83 & V_175 ) )
return false ;
return true ;
}
static int F_105 ( struct V_18 * V_19 , T_1 V_176 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_135 * V_136 = & V_2 -> V_137 ;
unsigned int V_173 = F_102 ( V_19 , V_176 ) ;
unsigned int V_172 = F_104 ( V_173 ) ;
int type , V_16 ;
int V_47 = 0 ;
for ( type = V_177 ; type >= V_178 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_136 -> V_179 ; V_16 ++ ) {
if ( V_136 -> V_180 [ V_16 ] . type != type )
continue;
if ( F_101 ( V_19 , V_172 ,
V_136 -> V_180 [ V_16 ] . V_45 ) )
V_47 ++ ;
}
}
return V_47 ;
}
static int F_106 ( struct V_18 * V_19 ,
T_1 V_176 ,
bool V_181 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_135 * V_136 = & V_2 -> V_137 ;
int type , V_16 , V_164 , V_47 , V_182 ;
unsigned int V_173 = F_102 ( V_19 , V_176 ) ;
unsigned int V_172 = F_104 ( V_173 ) ;
int V_154 = 0 ;
struct V_6 * V_51 ;
V_182 = V_2 -> V_139 ;
if ( V_182 >= 2 )
goto V_183;
V_47 = F_105 ( V_19 , V_176 ) ;
if ( V_47 < 2 )
goto V_183;
for ( type = V_177 ; type >= V_178 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_136 -> V_179 ; V_16 ++ ) {
T_1 V_49 = V_136 -> V_180 [ V_16 ] . V_45 ;
T_1 V_159 = 0 ;
if ( V_136 -> V_180 [ V_16 ] . type != type )
continue;
if ( ! F_101 ( V_19 , V_172 , V_49 ) )
continue;
for ( V_164 = 0 ; V_164 < V_2 -> V_139 ; V_164 ++ ) {
if ( V_49 == V_2 -> V_158 [ V_164 ] . V_45 )
break;
}
if ( V_164 < V_2 -> V_139 )
continue;
if ( V_181 )
V_159 = F_100 ( V_19 , V_49 ) ;
else if ( ! V_159 )
V_159 = F_44 ( V_19 , V_49 , false ) ;
if ( ! V_159 ) {
V_154 ++ ;
continue;
}
V_51 = F_42 ( V_19 , V_159 , V_49 ,
- V_2 -> V_44 ) ;
if ( ! V_51 ) {
V_154 ++ ;
continue;
}
V_2 -> V_158 [ V_2 -> V_139 ] . V_45 = V_49 ;
V_2 -> V_158 [ V_2 -> V_139 ] . V_159 = V_159 ;
V_2 -> V_184 [ V_136 -> V_138 + V_2 -> V_139 ] =
F_26 ( V_19 , V_51 ) ;
V_2 -> V_139 ++ ;
if ( V_2 -> V_139 >= 2 )
break;
}
}
V_183:
if ( V_154 )
V_154 = V_185 ;
if ( V_182 == V_2 -> V_139 ) {
if ( V_181 )
return 1 ;
else
return V_154 ;
}
if ( ! V_181 && V_2 -> V_139 < 2 ) {
V_2 -> V_5 . V_17 -= V_2 -> V_139 - V_182 ;
V_2 -> V_139 = V_182 ;
return V_154 ;
}
for ( V_16 = V_182 ; V_16 < V_2 -> V_139 ; V_16 ++ ) {
V_51 = F_27 ( V_19 , V_2 -> V_184 [ V_136 -> V_138 + V_16 ] ) ;
V_154 += F_96 ( V_19 , V_51 ) ;
}
return V_154 ;
}
static bool F_107 ( struct V_18 * V_19 , int V_186 ,
const T_1 * V_48 , T_1 * V_161 , int * V_112 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
bool V_66 = false ;
for ( V_16 = 0 ; V_16 < V_186 ; V_16 ++ ) {
struct V_6 * V_51 ;
T_1 V_159 ;
if ( V_161 [ V_16 ] )
continue;
V_159 = F_100 ( V_19 , V_48 [ V_16 ] ) ;
if ( ! V_159 )
continue;
V_51 = F_42 ( V_19 , V_159 , V_48 [ V_16 ] ,
- V_2 -> V_44 ) ;
if ( ! V_51 && ! V_16 && V_2 -> V_44 )
V_51 = F_42 ( V_19 , V_159 , V_48 [ V_16 ] , 0 ) ;
if ( V_51 ) {
V_161 [ V_16 ] = V_159 ;
V_66 = true ;
V_51 -> V_87 = true ;
V_112 [ V_16 ] = F_26 ( V_19 , V_51 ) ;
}
}
return V_66 ;
}
static int F_108 ( struct V_18 * V_19 , int V_112 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_51 ;
T_1 V_187 , V_159 , V_45 ;
V_51 = F_27 ( V_19 , V_112 ) ;
if ( ! V_51 || ! V_51 -> V_52 ||
F_22 ( V_51 , V_2 -> V_44 ) )
return 0 ;
V_187 = V_51 -> V_51 [ 0 ] ;
V_159 = V_2 -> V_157 [ 0 ] ;
V_45 = V_51 -> V_51 [ V_51 -> V_52 - 1 ] ;
V_51 = F_42 ( V_19 , V_159 , V_45 , V_2 -> V_44 ) ;
if ( ! V_51 ) {
if ( V_159 != V_187 )
V_159 = V_187 ;
else if ( V_2 -> V_144 . V_146 [ 0 ] )
V_159 = V_2 -> V_144 . V_146 [ 0 ] ;
else if ( V_2 -> V_144 . V_147 [ 0 ] )
V_159 = V_2 -> V_144 . V_147 [ 0 ] ;
else
V_159 = 0 ;
if ( V_159 )
V_51 = F_42 ( V_19 , V_159 , V_45 ,
V_2 -> V_44 ) ;
}
if ( ! V_51 )
return 0 ;
V_51 -> V_87 = false ;
return F_26 ( V_19 , V_51 ) ;
}
static bool F_109 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_135 * V_136 = & V_2 -> V_137 ;
struct V_6 * V_51 ;
int V_16 , V_57 ;
if ( V_136 -> V_149 == V_152 )
V_57 = V_2 -> V_184 [ 0 ] ;
else
V_57 = V_2 -> V_151 [ 0 ] ;
V_51 = F_27 ( V_19 , V_57 ) ;
if ( ! V_51 )
return false ;
if ( ! V_2 -> V_44 || ! F_22 ( V_51 , V_2 -> V_44 ) )
return true ;
for ( V_16 = 0 ; V_16 < V_136 -> V_138 ; V_16 ++ ) {
if ( V_2 -> V_184 [ V_16 ] == V_57 )
break;
V_51 = F_27 ( V_19 , V_2 -> V_184 [ V_16 ] ) ;
if ( V_51 && F_22 ( V_51 , V_2 -> V_44 ) )
return false ;
}
for ( V_16 = 0 ; V_16 < V_136 -> V_141 ; V_16 ++ ) {
V_51 = F_27 ( V_19 , V_2 -> V_153 [ V_16 ] ) ;
if ( V_51 && F_22 ( V_51 , V_2 -> V_44 ) )
return false ;
}
return true ;
}
static void F_110 ( struct V_18 * V_19 , int V_160 ,
T_1 * V_161 , int * V_112 )
{
struct V_6 * V_51 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_160 ; V_16 ++ ) {
if ( V_161 [ V_16 ] )
continue;
V_51 = F_27 ( V_19 , V_112 [ V_16 ] ) ;
if ( ! V_51 )
continue;
V_161 [ V_16 ] = V_51 -> V_51 [ 0 ] ;
}
}
static int F_111 ( struct V_18 * V_19 ,
bool V_188 ,
bool V_189 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_135 * V_136 = & V_2 -> V_137 ;
int V_16 , V_190 , V_154 ;
V_2 -> V_144 . V_145 = V_136 -> V_138 ;
V_2 -> V_144 . V_191 = V_2 -> V_157 ;
memset ( V_2 -> V_157 , 0 , sizeof( V_2 -> V_157 ) ) ;
memset ( V_2 -> V_144 . V_146 , 0 , sizeof( V_2 -> V_144 . V_146 ) ) ;
memset ( V_2 -> V_144 . V_147 , 0 , sizeof( V_2 -> V_144 . V_147 ) ) ;
V_2 -> V_139 = 0 ;
F_9 ( & V_2 -> V_5 ) ;
memset ( V_2 -> V_184 , 0 , sizeof( V_2 -> V_184 ) ) ;
memset ( V_2 -> V_151 , 0 , sizeof( V_2 -> V_151 ) ) ;
memset ( V_2 -> V_153 , 0 , sizeof( V_2 -> V_153 ) ) ;
memset ( V_2 -> V_192 , 0 , sizeof( V_2 -> V_192 ) ) ;
memset ( V_2 -> V_193 , 0 , sizeof( V_2 -> V_193 ) ) ;
memset ( V_2 -> V_194 , 0 , sizeof( V_2 -> V_194 ) ) ;
memset ( V_2 -> V_195 , 0 , sizeof( V_2 -> V_195 ) ) ;
memset ( & V_2 -> V_196 , 0 , sizeof( V_2 -> V_196 ) ) ;
V_154 = 0 ;
if ( V_188 ) {
bool V_197 ;
do {
V_197 = F_107 ( V_19 , V_136 -> V_138 ,
V_136 -> V_198 ,
V_2 -> V_157 ,
V_2 -> V_184 ) ;
V_197 |= F_107 ( V_19 , V_136 -> V_140 ,
V_136 -> V_199 ,
V_2 -> V_144 . V_146 ,
V_2 -> V_151 ) ;
V_197 |= F_107 ( V_19 , V_136 -> V_141 ,
V_136 -> V_200 ,
V_2 -> V_144 . V_147 ,
V_2 -> V_153 ) ;
if ( V_189 && V_136 -> V_138 == 1 &&
V_136 -> V_149 != V_150 ) {
V_190 = F_106 ( V_19 , V_136 -> V_198 [ 0 ] , true ) ;
if ( ! V_190 )
V_197 = true ;
}
} while ( V_197 );
}
V_154 += F_99 ( V_19 , V_136 -> V_138 , V_136 -> V_198 ,
V_2 -> V_157 , V_2 -> V_184 ,
V_2 -> V_201 ) ;
if ( V_189 &&
V_136 -> V_138 == 1 && V_136 -> V_149 != V_150 ) {
V_190 = F_106 ( V_19 , V_136 -> V_198 [ 0 ] , false ) ;
if ( V_190 < 0 )
return V_190 ;
}
if ( V_136 -> V_149 != V_152 ) {
V_190 = F_99 ( V_19 , V_136 -> V_140 , V_136 -> V_199 ,
V_2 -> V_144 . V_146 ,
V_2 -> V_151 ,
V_2 -> V_202 ) ;
if ( V_190 < 0 )
return V_190 ;
V_154 += V_190 ;
}
if ( V_136 -> V_149 != V_150 ) {
V_190 = F_99 ( V_19 , V_136 -> V_141 ,
V_136 -> V_200 ,
V_2 -> V_144 . V_147 ,
V_2 -> V_153 ,
V_2 -> V_202 ) ;
if ( V_190 < 0 )
return V_190 ;
V_154 += V_190 ;
}
if ( V_136 -> V_138 == 1 && V_136 -> V_149 != V_150 ) {
V_190 = F_106 ( V_19 , V_136 -> V_198 [ 0 ] , false ) ;
if ( V_190 < 0 )
return V_190 ;
V_154 += V_190 ;
}
if ( V_2 -> V_44 ) {
V_2 -> V_192 [ 0 ] =
F_108 ( V_19 , V_2 -> V_184 [ 0 ] ) ;
if ( V_136 -> V_149 != V_152 )
V_2 -> V_192 [ 1 ] =
F_108 ( V_19 , V_2 -> V_151 [ 0 ] ) ;
if ( V_136 -> V_149 != V_150 )
V_2 -> V_192 [ 2 ] =
F_108 ( V_19 , V_2 -> V_153 [ 0 ] ) ;
}
if ( V_136 -> V_140 && V_136 -> V_149 == V_150 )
if ( F_105 ( V_19 , V_136 -> V_199 [ 0 ] ) >= 2 )
V_2 -> V_139 = 1 ;
V_2 -> V_144 . V_145 = 0 ;
for ( V_16 = 0 ; V_16 < V_136 -> V_138 ; V_16 ++ ) {
if ( V_2 -> V_157 [ V_16 ] )
V_2 -> V_144 . V_145 ++ ;
else {
memmove ( V_2 -> V_157 + V_16 ,
V_2 -> V_157 + V_16 + 1 ,
sizeof( T_1 ) * ( V_136 -> V_138 - V_16 - 1 ) ) ;
V_2 -> V_157 [ V_136 -> V_138 - 1 ] = 0 ;
}
}
V_2 -> V_203 = V_2 -> V_204 =
V_2 -> V_144 . V_145 * 2 ;
if ( V_2 -> V_139 == 2 ) {
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
V_2 -> V_157 [ V_2 -> V_144 . V_145 ++ ] =
V_2 -> V_158 [ V_16 ] . V_159 ;
} else if ( V_2 -> V_139 ) {
V_2 -> V_139 = 0 ;
V_154 += V_185 ;
}
if ( V_2 -> V_38 && ! F_109 ( V_19 ) )
V_154 += V_205 ;
if ( V_136 -> V_149 != V_152 )
F_110 ( V_19 , V_136 -> V_140 ,
V_2 -> V_144 . V_146 ,
V_2 -> V_151 ) ;
if ( V_136 -> V_149 != V_150 )
F_110 ( V_19 , V_136 -> V_141 ,
V_2 -> V_144 . V_147 ,
V_2 -> V_153 ) ;
return V_154 ;
}
static inline void F_112 ( struct V_18 * V_19 ,
const char * V_61 , int V_57 )
{
struct V_6 * V_51 ;
V_51 = F_27 ( V_19 , V_57 ) ;
if ( V_51 )
F_34 ( V_61 , V_51 ) ;
}
static void F_113 ( struct V_18 * V_19 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_206 [ 3 ] = { L_35 , L_36 , L_37 } ;
int V_16 ;
F_114 ( L_38 ,
V_136 -> V_198 [ 0 ] , V_136 -> V_198 [ 1 ] ,
V_136 -> V_198 [ 2 ] , V_136 -> V_198 [ 3 ] ,
V_2 -> V_144 . V_191 [ 0 ] ,
V_2 -> V_144 . V_191 [ 1 ] ,
V_2 -> V_144 . V_191 [ 2 ] ,
V_2 -> V_144 . V_191 [ 3 ] ,
V_206 [ V_136 -> V_149 ] ) ;
for ( V_16 = 0 ; V_16 < V_136 -> V_138 ; V_16 ++ )
F_112 ( V_19 , L_39 , V_2 -> V_184 [ V_16 ] ) ;
if ( V_2 -> V_139 > 0 )
F_114 ( L_40 ,
V_2 -> V_139 ,
V_2 -> V_158 [ 0 ] . V_45 , V_2 -> V_158 [ 1 ] . V_45 ,
V_2 -> V_158 [ 0 ] . V_159 , V_2 -> V_158 [ 1 ] . V_159 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_139 ; V_16 ++ )
F_112 ( V_19 , L_41 ,
V_2 -> V_184 [ V_136 -> V_138 + V_16 ] ) ;
if ( V_136 -> V_140 )
F_114 ( L_42 ,
V_136 -> V_199 [ 0 ] , V_136 -> V_199 [ 1 ] ,
V_136 -> V_199 [ 2 ] , V_136 -> V_199 [ 3 ] ,
V_2 -> V_144 . V_146 [ 0 ] ,
V_2 -> V_144 . V_146 [ 1 ] ,
V_2 -> V_144 . V_146 [ 2 ] ,
V_2 -> V_144 . V_146 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_136 -> V_140 ; V_16 ++ )
F_112 ( V_19 , L_43 , V_2 -> V_151 [ V_16 ] ) ;
if ( V_136 -> V_141 )
F_114 ( L_44 ,
V_136 -> V_200 [ 0 ] , V_136 -> V_200 [ 1 ] ,
V_136 -> V_200 [ 2 ] , V_136 -> V_200 [ 3 ] ,
V_2 -> V_144 . V_147 [ 0 ] ,
V_2 -> V_144 . V_147 [ 1 ] ,
V_2 -> V_144 . V_147 [ 2 ] ,
V_2 -> V_144 . V_147 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_136 -> V_141 ; V_16 ++ )
F_112 ( V_19 , L_45 , V_2 -> V_153 [ V_16 ] ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ )
F_112 ( V_19 , L_46 , V_2 -> V_192 [ V_16 ] ) ;
}
static void F_115 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_49 = V_19 -> V_207 ;
V_2 -> V_74 = 0 ;
memset ( V_2 -> V_75 , 0 , sizeof( V_2 -> V_75 ) ) ;
for ( V_16 = 0 ; V_16 < V_19 -> V_208 ; V_16 ++ , V_49 ++ ) {
if ( F_39 ( F_40 ( V_19 , V_49 ) ) != V_65 )
continue;
if ( V_2 -> V_74 >= F_94 ( V_2 -> V_75 ) ) {
F_116 ( V_209 L_47 ) ;
break;
}
V_2 -> V_75 [ V_2 -> V_74 ++ ] = V_49 ;
}
}
static int F_117 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_135 * V_136 = & V_2 -> V_137 ;
struct V_135 * V_210 ;
unsigned int V_20 ;
int V_211 = V_212 ;
int V_154 ;
bool V_188 = true , V_189 = true ;
bool V_213 = true , V_214 = true ;
bool V_215 = false ;
V_210 = F_118 ( sizeof( * V_210 ) , V_13 ) ;
if ( ! V_210 )
return - V_121 ;
* V_210 = * V_136 ;
for (; ; ) {
V_154 = F_111 ( V_19 , V_188 ,
V_189 ) ;
if ( V_154 < 0 ) {
F_8 ( V_210 ) ;
return V_154 ;
}
F_114 ( L_48 ,
V_136 -> V_149 , V_188 , V_189 ,
V_154 ) ;
F_113 ( V_19 , V_136 ) ;
if ( V_154 < V_211 ) {
V_211 = V_154 ;
* V_210 = * V_136 ;
V_213 = V_188 ;
V_214 = V_189 ;
}
if ( ! V_154 )
break;
V_189 = ! V_189 ;
if ( ! V_189 )
continue;
V_188 = ! V_188 ;
if ( ! V_188 )
continue;
if ( V_215 )
break;
V_215 = true ;
if ( V_136 -> V_141 > 0 &&
V_136 -> V_149 == V_152 ) {
V_136 -> V_140 = V_136 -> V_138 ;
memcpy ( V_136 -> V_199 , V_136 -> V_198 ,
sizeof( V_136 -> V_199 ) ) ;
V_136 -> V_138 = V_136 -> V_141 ;
memcpy ( V_136 -> V_198 , V_136 -> V_200 ,
sizeof( V_136 -> V_200 ) ) ;
V_136 -> V_141 = 0 ;
memset ( V_136 -> V_200 , 0 , sizeof( V_136 -> V_200 ) ) ;
V_136 -> V_149 = V_150 ;
V_188 = true ;
continue;
}
if ( V_136 -> V_140 > 0 &&
V_136 -> V_149 == V_150 ) {
V_136 -> V_141 = V_136 -> V_138 ;
memcpy ( V_136 -> V_200 , V_136 -> V_198 ,
sizeof( V_136 -> V_200 ) ) ;
V_136 -> V_138 = V_136 -> V_140 ;
memcpy ( V_136 -> V_198 , V_136 -> V_199 ,
sizeof( V_136 -> V_199 ) ) ;
V_136 -> V_140 = 0 ;
memset ( V_136 -> V_199 , 0 , sizeof( V_136 -> V_199 ) ) ;
V_136 -> V_149 = V_152 ;
V_188 = true ;
continue;
}
break;
}
if ( V_154 ) {
F_114 ( L_49 ) ;
* V_136 = * V_210 ;
F_111 ( V_19 , V_213 , V_214 ) ;
}
F_114 ( L_50 ,
V_136 -> V_149 , V_213 , V_214 ) ;
F_113 ( V_19 , V_136 ) ;
if ( V_136 -> V_198 [ 0 ] ) {
struct V_6 * V_51 ;
V_51 = F_27 ( V_19 , V_2 -> V_184 [ 0 ] ) ;
if ( V_51 )
V_2 -> V_216 = F_51 ( V_19 , V_51 ) ;
if ( V_2 -> V_216 )
F_119 ( V_19 , V_2 -> V_216 ,
V_81 , V_2 -> V_217 ) ;
}
if ( V_2 -> V_218 || V_136 -> V_149 == V_152 )
V_20 = V_219 ;
else
V_20 = V_220 ;
F_20 ( V_19 , V_136 -> V_138 , V_136 -> V_198 , V_20 ) ;
if ( V_136 -> V_149 != V_152 )
F_20 ( V_19 , V_136 -> V_140 , V_136 -> V_199 , V_219 ) ;
if ( V_136 -> V_149 != V_150 ) {
V_20 = V_2 -> V_218 ? V_219 : V_220 ;
F_20 ( V_19 , V_136 -> V_141 ,
V_136 -> V_200 , V_20 ) ;
}
if ( V_2 -> V_38 && ! F_109 ( V_19 ) )
V_2 -> V_38 = 0 ;
F_8 ( V_210 ) ;
return 0 ;
}
static int F_120 ( struct V_18 * V_19 ,
const struct V_135 * V_136 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_190 , V_221 ;
V_221 = V_136 -> V_138 ;
if ( V_2 -> V_139 > 0 && V_136 -> V_138 < 3 )
V_221 += V_2 -> V_139 ;
for ( V_16 = 0 ; V_16 < V_221 ; V_16 ++ ) {
const char * V_10 ;
int V_115 ;
struct V_6 * V_51 ;
V_51 = F_27 ( V_19 , V_2 -> V_184 [ V_16 ] ) ;
if ( ! V_51 )
continue;
V_10 = F_93 ( V_19 , V_16 , & V_115 , V_97 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_51 ) ) {
V_190 = F_79 ( V_19 , L_52 , 0 , 1 , V_51 ) ;
if ( V_190 < 0 )
return V_190 ;
V_190 = F_79 ( V_19 , L_53 , 0 , 2 , V_51 ) ;
if ( V_190 < 0 )
return V_190 ;
} else {
V_190 = F_82 ( V_19 , V_10 , V_115 , V_51 ) ;
if ( V_190 < 0 )
return V_190 ;
}
V_10 = F_93 ( V_19 , V_16 , & V_115 , V_96 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_51 ) ) {
V_190 = F_83 ( V_19 , L_52 , 0 , 1 , V_51 ) ;
if ( V_190 < 0 )
return V_190 ;
V_190 = F_83 ( V_19 , L_53 , 0 , 2 , V_51 ) ;
if ( V_190 < 0 )
return V_190 ;
} else {
V_190 = F_87 ( V_19 , V_10 , V_115 , V_51 ) ;
if ( V_190 < 0 )
return V_190 ;
}
}
return 0 ;
}
static int F_121 ( struct V_18 * V_19 , int V_112 ,
const char * V_61 , int V_113 )
{
struct V_6 * V_51 ;
int V_190 ;
V_51 = F_27 ( V_19 , V_112 ) ;
if ( ! V_51 )
return 0 ;
V_190 = F_82 ( V_19 , V_61 , V_113 , V_51 ) ;
if ( V_190 < 0 )
return V_190 ;
V_190 = F_87 ( V_19 , V_61 , V_113 , V_51 ) ;
if ( V_190 < 0 )
return V_190 ;
return 0 ;
}
static int F_122 ( struct V_18 * V_19 , int V_47 ,
const int * V_5 , const char * V_61 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_47 ; V_16 ++ ) {
const char * V_10 ;
char V_63 [ V_120 ] ;
int V_190 , V_57 = 0 ;
if ( V_47 == 2 && V_16 == 1 && ! strcmp ( V_61 , L_32 ) )
V_10 = L_33 ;
else if ( V_47 >= 3 ) {
snprintf ( V_63 , sizeof( V_63 ) , L_54 ,
V_61 , V_148 [ V_16 ] ) ;
V_10 = V_63 ;
} else {
V_10 = V_61 ;
V_57 = V_16 ;
}
V_190 = F_121 ( V_19 , V_5 [ V_16 ] , V_10 , V_57 ) ;
if ( V_190 < 0 )
return V_190 ;
}
return 0 ;
}
static int F_123 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_122 ( V_19 , V_2 -> V_137 . V_140 ,
V_2 -> V_151 ,
L_34 ) ;
}
static int F_124 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_122 ( V_19 , V_2 -> V_137 . V_141 ,
V_2 -> V_153 ,
L_32 ) ;
}
static int F_125 ( struct V_126 * V_127 ,
struct V_222 * V_223 )
{
return F_126 ( V_127 , V_223 ) ;
}
static int F_127 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_129 -> V_132 . V_224 . V_225 [ 0 ] = V_2 -> V_226 ;
return 0 ;
}
static int F_128 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_227 = V_129 -> V_132 . V_224 . V_225 [ 0 ] ;
int V_228 = 0 ;
F_129 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_229 ) {
V_228 = - V_230 ;
goto V_231;
}
if ( V_2 -> V_226 != V_227 ) {
T_1 * V_232 ;
if ( V_2 -> V_137 . V_149 == V_152 )
V_232 = & V_2 -> V_157 [ 0 ] ;
else
V_232 = & V_2 -> V_144 . V_146 [ 0 ] ;
if ( V_2 -> V_233 ) {
if ( V_2 -> V_137 . V_149 == V_152 )
F_130 ( V_19 , V_2 -> V_234 ,
V_2 -> V_184 [ 0 ] ,
V_2 -> V_192 [ 0 ] ,
V_2 -> V_137 . V_149 ) ;
else
F_130 ( V_19 , V_2 -> V_234 ,
V_2 -> V_151 [ 0 ] ,
V_2 -> V_192 [ 1 ] ,
V_152 ) ;
}
V_2 -> V_226 = V_227 ;
if ( V_2 -> V_226 )
* V_232 = 0 ;
else
* V_232 = V_2 -> V_235 ;
F_131 ( V_19 , NULL ) ;
V_228 = 1 ;
}
V_231:
F_132 ( & V_2 -> V_9 ) ;
return V_228 ;
}
static int F_133 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_159 ;
if ( ! V_2 -> V_38 )
return 0 ;
if ( V_2 -> V_137 . V_149 == V_152 )
V_159 = V_2 -> V_144 . V_191 [ 0 ] ;
else
V_159 = V_2 -> V_144 . V_146 [ 0 ] ;
if ( ! V_159 ) {
V_2 -> V_38 = 0 ;
return 0 ;
}
V_2 -> V_226 = false ;
V_2 -> V_235 = V_159 ;
if ( ! F_4 ( V_2 , NULL , & V_236 ) )
return - V_121 ;
return 0 ;
}
static int F_134 ( struct V_126 * V_127 ,
struct V_222 * V_223 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_77 ;
V_223 -> type = V_237 ;
V_223 -> V_238 = 1 ;
V_223 -> V_132 . V_224 . V_239 = V_2 -> V_139 + 1 ;
if ( V_223 -> V_132 . V_224 . V_225 > V_2 -> V_139 )
V_223 -> V_132 . V_224 . V_225 = V_2 -> V_139 ;
V_77 = V_223 -> V_132 . V_224 . V_225 * 2 + V_2 -> V_204 ;
sprintf ( V_223 -> V_132 . V_224 . V_10 , L_55 , V_77 ) ;
return 0 ;
}
static int F_135 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_129 -> V_132 . V_224 . V_225 [ 0 ] =
( V_2 -> V_203 - V_2 -> V_204 ) / 2 ;
return 0 ;
}
static inline struct V_6 *
F_136 ( struct V_18 * V_19 , int V_57 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_27 ( V_19 ,
V_2 -> V_184 [ V_2 -> V_137 . V_138 + V_57 ] ) ;
}
static bool F_137 ( struct V_1 * V_2 )
{
return ! V_2 -> V_233 || V_2 -> V_234 ;
}
static int F_138 ( struct V_18 * V_19 , int V_57 , bool V_240 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_49 = V_2 -> V_158 [ V_57 ] . V_45 ;
struct V_6 * V_51 ;
V_51 = F_136 ( V_19 , V_57 ) ;
if ( ! V_51 )
return - V_241 ;
if ( V_51 -> V_87 == V_240 )
return 0 ;
if ( V_240 ) {
F_17 ( V_19 , V_49 , V_220 , true ) ;
F_64 ( V_19 , V_51 , true , F_137 ( V_2 ) ) ;
F_72 ( V_19 , V_49 , true ) ;
} else {
F_72 ( V_19 , V_49 , false ) ;
F_64 ( V_19 , V_51 , false , F_137 ( V_2 ) ) ;
F_17 ( V_19 , V_49 , V_2 -> V_158 [ V_57 ] . V_242 , true ) ;
F_68 ( V_19 , V_51 ) ;
}
F_139 ( V_19 ) ;
return 0 ;
}
static int F_140 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_134 ;
V_134 = V_129 -> V_132 . V_224 . V_225 [ 0 ] ;
if ( V_134 < 0 || V_134 > V_2 -> V_139 )
return - V_241 ;
if ( V_134 == ( V_2 -> V_203 - V_2 -> V_204 ) / 2 )
return 0 ;
V_2 -> V_203 = V_134 * 2 + V_2 -> V_204 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_139 ; V_16 ++ )
F_138 ( V_19 , V_16 , V_16 < V_134 ) ;
V_2 -> V_144 . V_243 = F_141 ( V_2 -> V_203 ,
V_2 -> V_244 ) ;
if ( V_2 -> V_34 )
V_2 -> V_144 . V_145 = V_2 -> V_144 . V_243 / 2 ;
return 1 ;
}
static int F_142 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_139 > 0 ) {
if ( ! F_4 ( V_2 , NULL , & V_245 ) )
return - V_121 ;
}
return 0 ;
}
static int F_143 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_129 -> V_132 . V_224 . V_225 [ 0 ] = V_2 -> V_234 ;
return 0 ;
}
static void F_130 ( struct V_18 * V_19 , bool V_246 ,
int V_247 , int V_248 ,
int V_249 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_250 , * V_251 ;
V_250 = F_27 ( V_19 , V_247 ) ;
V_251 = F_27 ( V_19 , V_248 ) ;
if ( ! V_250 || ! V_251 )
return;
if ( V_249 == V_152 && V_2 -> V_226 &&
V_251 -> V_51 [ 0 ] != V_2 -> V_235 )
V_246 = false ;
if ( V_246 ) {
F_64 ( V_19 , V_250 , false , true ) ;
F_64 ( V_19 , V_251 , true , true ) ;
F_68 ( V_19 , V_250 ) ;
} else {
F_64 ( V_19 , V_251 , false , false ) ;
F_64 ( V_19 , V_250 , true , false ) ;
F_68 ( V_19 , V_251 ) ;
}
}
static int F_144 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = V_129 -> V_132 . V_224 . V_225 [ 0 ] ;
if ( V_20 == V_2 -> V_234 )
return 0 ;
V_2 -> V_234 = V_20 ;
F_130 ( V_19 , V_20 , V_2 -> V_184 [ 0 ] ,
V_2 -> V_192 [ 0 ] ,
V_2 -> V_137 . V_149 ) ;
F_130 ( V_19 , V_20 , V_2 -> V_151 [ 0 ] ,
V_2 -> V_192 [ 1 ] ,
V_152 ) ;
F_130 ( V_19 , V_20 , V_2 -> V_153 [ 0 ] ,
V_2 -> V_192 [ 2 ] ,
V_150 ) ;
return 1 ;
}
static int F_145 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_44 )
return 0 ;
if ( ! ( V_2 -> V_192 [ 0 ] || V_2 -> V_192 [ 1 ] ||
V_2 -> V_192 [ 2 ] ) )
return 0 ;
if ( ! F_4 ( V_2 , NULL , & V_252 ) )
return - V_121 ;
V_2 -> V_233 = 1 ;
return 0 ;
}
static void F_146 ( struct V_18 * V_19 , int V_253 , bool V_254 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_255 ;
unsigned int V_20 ;
T_1 V_45 ;
V_45 = V_2 -> V_256 ;
V_255 = V_2 -> V_257 [ V_253 ] == V_2 -> V_258 ;
if ( ! V_254 ) {
V_20 = F_16 ( V_19 , V_45 ) ;
if ( V_255 ) {
if ( V_20 & V_259 )
return;
} else {
if ( V_20 & V_220 )
return;
}
}
V_20 = F_147 ( V_19 , V_45 ) ;
if ( V_20 == V_260 && V_2 -> V_261 ) {
const T_1 V_262 = V_2 -> V_261 ;
unsigned int V_263 = F_147 ( V_19 , V_262 ) ;
if ( V_263 != V_260 )
F_148 ( V_19 , V_262 ,
V_259 | ( V_255 ? V_263 : 0 ) ) ;
}
if ( ! V_2 -> V_264 ) {
if ( V_255 )
V_20 |= V_259 ;
else
V_20 = V_219 ;
F_17 ( V_19 , V_45 , V_20 , true ) ;
F_131 ( V_19 , NULL ) ;
}
}
static int F_149 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_135 * V_136 = & V_2 -> V_137 ;
unsigned int V_173 ;
T_1 V_49 ;
if ( ! V_2 -> V_42 ) {
if ( V_2 -> V_43 )
return 0 ;
if ( V_136 -> V_179 > 1 )
return 0 ;
else if ( V_136 -> V_179 == 1 ) {
V_173 = F_102 ( V_19 , V_136 -> V_180 [ 0 ] . V_45 ) ;
if ( F_150 ( V_173 ) != V_265 )
return 0 ;
}
}
V_2 -> V_42 = 0 ;
if ( V_136 -> V_179 >= V_266 )
return 0 ;
V_49 = 0 ;
if ( V_136 -> V_149 == V_152 && V_136 -> V_138 > 0 )
V_49 = V_136 -> V_198 [ 0 ] ;
else if ( V_136 -> V_140 > 0 )
V_49 = V_136 -> V_199 [ 0 ] ;
if ( ! V_49 )
return 0 ;
if ( ! ( F_73 ( V_19 , V_49 ) & V_267 ) )
return 0 ;
V_136 -> V_180 [ V_136 -> V_179 ] . V_45 = V_49 ;
V_136 -> V_180 [ V_136 -> V_179 ] . type = V_178 ;
V_136 -> V_180 [ V_136 -> V_179 ] . V_268 = 1 ;
V_136 -> V_179 ++ ;
V_2 -> V_42 = 1 ;
V_2 -> V_256 = V_49 ;
V_2 -> V_31 = 1 ;
F_36 ( L_56 , V_49 ) ;
return 0 ;
}
static int F_151 ( struct V_126 * V_127 ,
struct V_222 * V_223 )
{
return F_152 ( V_127 , V_223 , 2 , V_269 ) ;
}
static int F_153 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
T_1 V_49 = V_127 -> V_118 ;
if ( F_16 ( V_19 , V_49 ) == V_219 )
V_129 -> V_132 . V_224 . V_225 [ 0 ] = 1 ;
else
V_129 -> V_132 . V_224 . V_225 [ 0 ] = 0 ;
return 0 ;
}
static int F_154 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
T_1 V_49 = V_127 -> V_118 ;
unsigned int V_20 ;
V_20 = V_129 -> V_132 . V_224 . V_225 [ 0 ] ? V_219 : V_220 ;
if ( F_16 ( V_19 , V_49 ) == V_20 )
return 0 ;
F_148 ( V_19 , V_49 , V_20 ) ;
return 1 ;
}
static bool F_155 ( struct V_18 * V_19 , const char * V_10 , int V_57 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_3 . V_17 ; V_16 ++ ) {
struct V_4 * V_15 = F_24 ( & V_2 -> V_3 , V_16 ) ;
if ( ! strcmp ( V_15 -> V_10 , V_10 ) && V_15 -> V_115 == V_57 )
return true ;
}
return false ;
}
static void F_156 ( struct V_18 * V_19 , T_1 V_45 ,
char * V_10 , T_3 V_270 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_57 = 0 ;
F_157 ( V_19 , V_45 , & V_2 -> V_137 , V_10 , V_270 , & V_57 ) ;
F_35 ( V_10 , L_57 , V_270 ) ;
for (; F_155 ( V_19 , V_10 , V_57 ) ; V_57 ++ )
;
}
static int F_158 ( struct V_18 * V_19 , T_1 V_45 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_40 ) {
unsigned int V_271 = F_73 ( V_19 , V_45 ) ;
if ( ( V_271 & V_175 ) && ( V_271 & V_272 ) )
return 2 ;
}
return 1 ;
}
static int F_159 ( struct V_18 * V_19 , int V_47 ,
T_1 * V_48 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_47 ; V_16 ++ ) {
T_1 V_45 = V_48 [ V_16 ] ;
if ( V_45 == V_2 -> V_256 ) {
int V_228 = F_160 ( V_19 , V_45 ) ;
if ( V_228 < 0 )
return V_228 ;
continue;
}
if ( F_158 ( V_19 , V_45 ) > 1 ) {
struct V_4 * V_12 ;
char V_10 [ V_120 ] ;
F_156 ( V_19 , V_45 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 ,
& V_273 ) ;
if ( ! V_12 )
return - V_121 ;
V_12 -> V_118 = V_45 ;
}
}
return 0 ;
}
static unsigned int F_161 ( struct V_18 * V_19 , T_1 V_45 )
{
unsigned int V_271 ;
V_271 = F_73 ( V_19 , V_45 ) ;
V_271 = ( V_271 & V_274 ) >> V_275 ;
V_271 &= ~ ( V_276 | V_277 ) ;
return V_271 ;
}
static int F_162 ( unsigned int V_278 , unsigned int V_279 )
{
unsigned int V_16 , V_86 = 0 ;
for ( V_16 = 0 ; V_16 < V_280 ; V_16 ++ ) {
if ( V_278 & ( 1 << V_16 ) ) {
if ( V_86 == V_279 )
return V_16 ;
V_86 ++ ;
}
}
return 0 ;
}
static int F_163 ( unsigned int V_278 , unsigned int V_57 )
{
unsigned int V_16 , V_86 = 0 ;
for ( V_16 = 0 ; V_16 < V_280 ; V_16 ++ ) {
if ( V_16 == V_57 )
return V_86 ;
if ( V_278 & ( 1 << V_16 ) )
V_86 ++ ;
}
return 0 ;
}
static int F_164 ( struct V_126 * V_127 ,
struct V_222 * V_223 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
T_1 V_49 = V_127 -> V_118 ;
unsigned int V_278 = F_161 ( V_19 , V_49 ) ;
F_152 ( V_127 , V_223 , F_165 ( V_278 ) ,
V_281 ) ;
strcpy ( V_223 -> V_132 . V_224 . V_10 ,
V_281 [ F_162 ( V_278 , V_223 -> V_132 . V_224 . V_225 ) ] ) ;
return 0 ;
}
static int F_166 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
T_1 V_49 = V_127 -> V_118 ;
unsigned int V_278 = F_161 ( V_19 , V_49 ) ;
unsigned int V_57 ;
V_57 = F_16 ( V_19 , V_49 ) & V_282 ;
V_129 -> V_132 . V_224 . V_225 [ 0 ] = F_163 ( V_278 , V_57 ) ;
return 0 ;
}
static int F_167 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
T_1 V_49 = V_127 -> V_118 ;
unsigned int V_278 = F_161 ( V_19 , V_49 ) ;
unsigned int V_20 , V_57 ;
V_20 = F_16 ( V_19 , V_49 ) ;
V_57 = F_163 ( V_278 , V_20 & V_282 ) ;
if ( V_57 == V_129 -> V_132 . V_224 . V_225 [ 0 ] )
return 0 ;
V_20 &= ~ V_282 ;
V_20 |= F_162 ( V_278 , V_129 -> V_132 . V_224 . V_225 [ 0 ] ) ;
F_148 ( V_19 , V_49 , V_20 ) ;
return 1 ;
}
static int F_168 ( struct V_18 * V_19 , T_1 V_45 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_283 = 0 ;
if ( V_2 -> V_40 )
V_283 = F_165 ( F_161 ( V_19 , V_45 ) ) ;
return V_283 ? V_283 : 1 ;
}
static int F_169 ( struct V_18 * V_19 , T_1 V_45 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
char V_10 [ V_120 ] ;
unsigned int V_173 ;
if ( V_45 == V_2 -> V_256 )
return 0 ;
V_173 = F_102 ( V_19 , V_45 ) ;
if ( F_150 ( V_173 ) == V_265 )
return 0 ;
if ( F_168 ( V_19 , V_45 ) <= 1 )
return 0 ;
F_156 ( V_19 , V_45 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 , & V_284 ) ;
if ( ! V_12 )
return - V_121 ;
V_12 -> V_118 = V_45 ;
return 0 ;
}
static int F_170 ( struct V_126 * V_127 ,
struct V_222 * V_223 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
T_1 V_49 = V_127 -> V_118 ;
int V_285 = F_158 ( V_19 , V_49 ) ;
int V_286 = F_168 ( V_19 , V_49 ) ;
const char * V_287 = NULL ;
int V_57 ;
V_223 -> type = V_237 ;
V_223 -> V_238 = 1 ;
V_223 -> V_132 . V_224 . V_239 = V_285 + V_286 ;
if ( V_223 -> V_132 . V_224 . V_225 >= V_223 -> V_132 . V_224 . V_239 )
V_223 -> V_132 . V_224 . V_225 = V_223 -> V_132 . V_224 . V_239 - 1 ;
V_57 = V_223 -> V_132 . V_224 . V_225 ;
if ( V_57 < V_285 ) {
if ( V_285 > 1 )
V_287 = V_269 [ V_57 ] ;
else
V_287 = L_58 ;
} else {
V_57 -= V_285 ;
if ( V_286 > 1 ) {
unsigned int V_278 = F_161 ( V_19 , V_49 ) ;
V_287 = V_281 [ F_162 ( V_278 , V_57 ) ] ;
} else
V_287 = L_59 ;
}
strcpy ( V_223 -> V_132 . V_224 . V_10 , V_287 ) ;
return 0 ;
}
static int F_171 ( struct V_18 * V_19 , T_1 V_49 )
{
int V_285 = F_158 ( V_19 , V_49 ) ;
int V_286 = F_168 ( V_19 , V_49 ) ;
unsigned int V_20 = F_16 ( V_19 , V_49 ) ;
int V_57 = 0 ;
if ( V_20 & V_220 ) {
if ( V_285 > 1 && V_20 == V_219 )
V_57 = 1 ;
} else if ( V_20 & V_259 ) {
V_57 = V_285 ;
if ( V_286 > 1 ) {
unsigned int V_278 = F_161 ( V_19 , V_49 ) ;
V_20 &= V_282 ;
V_57 += F_163 ( V_278 , V_20 ) ;
}
}
return V_57 ;
}
static int F_172 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
T_1 V_49 = V_127 -> V_118 ;
V_129 -> V_132 . V_224 . V_225 [ 0 ] =
F_171 ( V_19 , V_49 ) ;
return 0 ;
}
static int F_173 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
T_1 V_49 = V_127 -> V_118 ;
int V_285 = F_158 ( V_19 , V_49 ) ;
int V_286 = F_168 ( V_19 , V_49 ) ;
unsigned int V_20 , V_288 , V_57 ;
V_288 = F_171 ( V_19 , V_49 ) ;
V_57 = V_129 -> V_132 . V_224 . V_225 [ 0 ] ;
if ( V_288 == V_57 )
return 0 ;
if ( V_57 < V_285 ) {
if ( V_285 > 1 )
V_20 = V_57 ? V_219 : V_220 ;
else
V_20 = V_219 ;
} else {
V_57 -= V_285 ;
if ( V_286 > 1 ) {
unsigned int V_278 = F_161 ( V_19 , V_49 ) ;
V_20 = F_16 ( V_19 , V_49 ) ;
V_20 &= ~ ( V_282 | V_219 ) ;
V_20 |= F_162 ( V_278 , V_57 ) | V_259 ;
} else
V_20 = F_147 ( V_19 , V_49 ) ;
}
F_148 ( V_19 , V_49 , V_20 ) ;
F_131 ( V_19 , NULL ) ;
return 1 ;
}
static int F_160 ( struct V_18 * V_19 , T_1 V_45 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
if ( F_158 ( V_19 , V_45 ) <= 1 &&
F_168 ( V_19 , V_45 ) <= 1 )
return 0 ;
V_12 = F_4 ( V_2 , L_60 ,
& V_289 ) ;
if ( ! V_12 )
return - V_121 ;
V_12 -> V_118 = V_45 ;
V_2 -> V_264 = 1 ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 , T_1 V_290 , int V_57 )
{
struct V_8 * V_14 ;
V_14 = F_5 ( & V_2 -> V_7 ) ;
if ( ! V_14 )
return - V_121 ;
V_14 -> V_49 = V_290 ;
V_14 -> V_60 = V_82 ;
V_14 -> V_57 = V_57 ;
V_2 -> V_291 . V_292 = V_2 -> V_7 . V_14 ;
return 0 ;
}
static int F_175 ( struct V_18 * V_19 , int V_293 ,
T_1 V_45 , const char * V_294 , int V_295 ,
T_1 V_296 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_51 ;
unsigned int V_20 ;
int V_190 , V_57 ;
if ( ! F_52 ( V_19 , V_296 , V_82 ) &&
! F_50 ( V_19 , V_296 , V_82 ) )
return 0 ;
V_51 = F_42 ( V_19 , V_45 , V_296 , 0 ) ;
if ( ! V_51 )
return - V_241 ;
F_34 ( L_61 , V_51 ) ;
V_2 -> V_195 [ V_293 ] = F_26 ( V_19 , V_51 ) ;
V_57 = V_51 -> V_57 [ V_51 -> V_52 - 1 ] ;
if ( F_52 ( V_19 , V_296 , V_82 ) ) {
V_20 = F_33 ( V_296 , 3 , V_57 , V_82 ) ;
V_190 = F_80 ( V_2 , V_122 , V_294 , V_295 , V_20 ) ;
if ( V_190 < 0 )
return V_190 ;
V_51 -> V_59 [ V_97 ] = V_20 ;
}
if ( F_50 ( V_19 , V_296 , V_82 ) ) {
V_20 = F_33 ( V_296 , 3 , V_57 , V_82 ) ;
V_190 = F_86 ( V_2 , V_124 , V_294 , V_295 , V_20 ) ;
if ( V_190 < 0 )
return V_190 ;
V_51 -> V_59 [ V_96 ] = V_20 ;
}
V_51 -> V_87 = true ;
V_190 = F_174 ( V_2 , V_296 , V_57 ) ;
if ( V_190 < 0 )
return V_190 ;
if ( V_2 -> V_44 != V_2 -> V_101 &&
! V_2 -> V_297 ) {
V_51 = F_42 ( V_19 , V_2 -> V_44 ,
V_2 -> V_101 , 0 ) ;
if ( V_51 ) {
F_34 ( L_62 , V_51 ) ;
V_51 -> V_87 = true ;
V_2 -> V_297 =
F_26 ( V_19 , V_51 ) ;
}
}
return 0 ;
}
static int F_176 ( struct V_18 * V_19 , T_1 V_49 )
{
unsigned int V_271 = F_73 ( V_19 , V_49 ) ;
return ( V_271 & V_267 ) != 0 ;
}
static int F_177 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_49 ;
T_1 * V_298 = V_2 -> V_298 ;
int V_299 = F_94 ( V_2 -> V_298 ) ;
int V_16 , V_50 = 0 ;
V_49 = V_19 -> V_207 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_208 ; V_16 ++ , V_49 ++ ) {
unsigned int V_83 = F_40 ( V_19 , V_49 ) ;
int type = F_39 ( V_83 ) ;
if ( type != V_68 || ( V_83 & V_76 ) )
continue;
V_298 [ V_50 ] = V_49 ;
if ( ++ V_50 >= V_299 )
break;
}
V_2 -> V_300 = V_50 ;
V_2 -> V_301 = V_50 ;
memcpy ( V_2 -> V_302 , V_2 -> V_298 , V_50 * sizeof( T_1 ) ) ;
return V_50 ;
}
static int F_178 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_303 * V_304 = & V_2 -> V_305 ;
unsigned int V_306 ;
int V_16 , V_86 , V_50 ;
V_50 = 0 ;
V_306 = 0 ;
for ( V_86 = 0 ; V_86 < V_2 -> V_300 ; V_86 ++ ) {
for ( V_16 = 0 ; V_16 < V_304 -> V_307 ; V_16 ++ ) {
if ( ! V_2 -> V_194 [ V_16 ] [ V_86 ] )
break;
}
if ( V_16 >= V_304 -> V_307 ) {
V_306 |= ( 1 << V_86 ) ;
V_50 ++ ;
}
}
if ( ! V_306 ) {
for ( V_16 = 0 ; V_16 < V_304 -> V_307 ; V_16 ++ ) {
for ( V_86 = 0 ; V_86 < V_2 -> V_300 ; V_86 ++ ) {
if ( V_2 -> V_194 [ V_16 ] [ V_86 ] ) {
V_2 -> V_308 [ V_16 ] = V_86 ;
break;
}
}
}
F_36 ( L_63 ) ;
V_2 -> V_309 = 1 ;
} else if ( V_50 != V_2 -> V_300 ) {
V_50 = 0 ;
for ( V_86 = 0 ; V_86 < V_2 -> V_300 ; V_86 ++ ) {
if ( ! ( V_306 & ( 1 << V_86 ) ) )
continue;
if ( V_86 != V_50 ) {
V_2 -> V_298 [ V_50 ] = V_2 -> V_298 [ V_86 ] ;
for ( V_16 = 0 ; V_16 < V_304 -> V_307 ; V_16 ++ ) {
F_43 ( V_19 ,
V_2 -> V_194 [ V_16 ] [ V_50 ] ) ;
V_2 -> V_194 [ V_16 ] [ V_50 ] =
V_2 -> V_194 [ V_16 ] [ V_86 ] ;
}
}
V_50 ++ ;
}
V_2 -> V_300 = V_50 ;
}
if ( V_304 -> V_307 == 1 ||
( V_304 -> V_307 == 2 && V_2 -> V_42 ) ) {
F_36 ( L_64 ) ;
V_2 -> V_300 = 1 ;
}
if ( ! V_2 -> V_309 && V_2 -> V_36 )
V_2 -> V_300 = 1 ;
return 0 ;
}
static int F_179 ( struct V_18 * V_19 , T_1 V_45 ,
int V_310 , int V_311 ,
const char * V_312 , int V_313 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_303 * V_304 = & V_2 -> V_305 ;
int V_314 = V_304 -> V_307 ;
bool V_315 = false ;
int V_316 ;
for ( V_316 = 0 ; V_316 < V_311 ; V_316 ++ ) {
struct V_6 * V_51 ;
T_1 V_317 = V_2 -> V_298 [ V_316 ] ;
if ( ! F_29 ( V_19 , V_45 , V_317 ) )
continue;
V_51 = F_42 ( V_19 , V_45 , V_317 , V_313 ) ;
if ( ! V_51 )
continue;
F_34 ( L_65 , V_51 ) ;
V_2 -> V_194 [ V_314 ] [ V_316 ] =
F_26 ( V_19 , V_51 ) ;
if ( ! V_315 ) {
if ( V_2 -> V_256 == V_45 )
V_2 -> V_258 = V_304 -> V_307 ;
V_2 -> V_318 [ V_304 -> V_307 ] = V_45 ;
F_180 ( V_304 , V_312 , V_310 , NULL ) ;
V_315 = true ;
}
}
return 0 ;
}
static int F_181 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_135 * V_136 = & V_2 -> V_137 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_136 -> V_179 ; V_16 ++ ) {
T_1 V_45 = V_136 -> V_180 [ V_16 ] . V_45 ;
const char * V_312 ;
int V_164 , V_57 ;
if ( ! F_176 ( V_19 , V_45 ) )
continue;
V_312 = F_182 ( V_19 , V_136 , V_16 ) ;
V_57 = 0 ;
for ( V_164 = V_16 - 1 ; V_164 >= 0 ; V_164 -- ) {
if ( V_2 -> V_319 [ V_164 ] &&
! strcmp ( V_2 -> V_319 [ V_164 ] , V_312 ) ) {
V_57 = V_2 -> V_320 [ V_164 ] + 1 ;
break;
}
}
V_2 -> V_319 [ V_16 ] = V_312 ;
V_2 -> V_320 [ V_16 ] = V_57 ;
}
return 0 ;
}
static int F_183 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_135 * V_136 = & V_2 -> V_137 ;
T_1 V_321 = V_2 -> V_44 ;
int V_311 ;
int V_16 , V_190 ;
unsigned int V_20 ;
V_311 = F_177 ( V_19 ) ;
if ( V_311 < 0 )
return 0 ;
V_190 = F_181 ( V_19 ) ;
if ( V_190 < 0 )
return V_190 ;
for ( V_16 = 0 ; V_16 < V_136 -> V_179 ; V_16 ++ ) {
T_1 V_45 ;
V_45 = V_136 -> V_180 [ V_16 ] . V_45 ;
if ( ! F_176 ( V_19 , V_45 ) )
continue;
V_20 = V_259 ;
if ( V_136 -> V_180 [ V_16 ] . type == V_178 )
V_20 |= F_147 ( V_19 , V_45 ) ;
if ( V_45 != V_2 -> V_256 )
F_17 ( V_19 , V_45 , V_20 , false ) ;
if ( V_321 ) {
if ( F_29 ( V_19 , V_45 , V_321 ) ) {
V_190 = F_175 ( V_19 , V_16 , V_45 ,
V_2 -> V_319 [ V_16 ] ,
V_2 -> V_320 [ V_16 ] ,
V_321 ) ;
if ( V_190 < 0 )
return V_190 ;
}
}
V_190 = F_179 ( V_19 , V_45 , V_16 , V_311 ,
V_2 -> V_319 [ V_16 ] , - V_321 ) ;
if ( V_190 < 0 )
return V_190 ;
if ( V_2 -> V_40 ) {
V_190 = F_169 ( V_19 , V_45 ) ;
if ( V_190 < 0 )
return V_190 ;
}
}
if ( V_321 && V_2 -> V_39 ) {
V_190 = F_179 ( V_19 , V_321 , V_322 , V_311 ,
L_66 , 0 ) ;
if ( V_190 < 0 )
return V_190 ;
}
return 0 ;
}
static struct V_6 * F_184 ( struct V_18 * V_19 , int V_323 , int V_314 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_314 < 0 || V_314 >= V_324 ) {
F_95 () ;
return NULL ;
}
if ( V_2 -> V_309 )
V_323 = V_2 -> V_308 [ V_314 ] ;
if ( V_323 < 0 || V_323 >= V_266 ) {
F_95 () ;
return NULL ;
}
return F_27 ( V_19 , V_2 -> V_194 [ V_314 ] [ V_323 ] ) ;
}
static int F_185 ( struct V_126 * V_127 ,
struct V_222 * V_223 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
return F_186 ( & V_2 -> V_305 , V_223 ) ;
}
static int F_187 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_323 = F_188 ( V_127 , & V_129 -> V_325 ) ;
V_129 -> V_132 . V_224 . V_225 [ 0 ] = V_2 -> V_257 [ V_323 ] ;
return 0 ;
}
static int F_189 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
unsigned int V_323 = F_188 ( V_127 , & V_129 -> V_325 ) ;
return F_190 ( V_19 , V_323 ,
V_129 -> V_132 . V_224 . V_225 [ 0 ] ) ;
}
static int F_191 ( struct V_126 * V_127 ,
struct V_128 * V_129 ,
T_4 V_326 , int type )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_303 * V_304 ;
struct V_6 * V_51 ;
int V_16 , V_323 , V_190 = 0 ;
V_304 = & V_2 -> V_305 ;
V_323 = V_127 -> V_325 . V_115 ;
F_129 ( & V_19 -> V_327 ) ;
V_19 -> V_328 = 1 ;
for ( V_16 = 0 ; V_16 < V_304 -> V_307 ; V_16 ++ ) {
V_51 = F_184 ( V_19 , V_323 , V_16 ) ;
if ( ! V_51 || ! V_51 -> V_59 [ type ] )
continue;
V_127 -> V_118 = V_51 -> V_59 [ type ] ;
V_190 = V_326 ( V_127 , V_129 ) ;
if ( V_190 < 0 )
goto error;
}
error:
V_19 -> V_328 = 0 ;
F_132 ( & V_19 -> V_327 ) ;
F_192 ( V_19 ) ;
if ( V_190 >= 0 && V_2 -> V_329 )
V_2 -> V_329 ( V_19 , V_129 ) ;
return V_190 ;
}
static int F_193 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
return F_191 ( V_127 , V_129 ,
V_330 ,
V_97 ) ;
}
static int F_194 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
return F_191 ( V_127 , V_129 ,
F_91 ,
V_96 ) ;
}
static int F_195 ( struct V_18 * V_19 , struct V_6 * V_51 )
{
T_1 V_49 ;
int V_16 , V_52 ;
V_51 -> V_59 [ V_97 ] = V_51 -> V_59 [ V_96 ] = 0 ;
for ( V_52 = 0 ; V_52 < 3 ; V_52 ++ ) {
if ( V_52 >= V_51 -> V_52 )
return - V_241 ;
V_16 = V_51 -> V_52 - V_52 - 1 ;
V_49 = V_51 -> V_51 [ V_16 ] ;
if ( ! V_51 -> V_59 [ V_97 ] ) {
if ( F_52 ( V_19 , V_49 , V_81 ) )
V_51 -> V_59 [ V_97 ] =
F_33 ( V_49 , 3 , 0 , V_81 ) ;
else if ( F_52 ( V_19 , V_49 , V_82 ) ) {
int V_57 = V_51 -> V_57 [ V_16 ] ;
if ( ! V_52 && V_19 -> V_29 )
V_57 = 0 ;
V_51 -> V_59 [ V_97 ] =
F_33 ( V_49 , 3 , V_57 , V_82 ) ;
}
}
if ( ! V_51 -> V_59 [ V_96 ] ) {
if ( F_50 ( V_19 , V_49 , V_81 ) )
V_51 -> V_59 [ V_96 ] =
F_33 ( V_49 , 3 , 0 , V_81 ) ;
else if ( F_50 ( V_19 , V_49 , V_82 ) ) {
int V_57 = V_51 -> V_57 [ V_16 ] ;
if ( ! V_52 && V_19 -> V_29 )
V_57 = 0 ;
V_51 -> V_59 [ V_96 ] =
F_33 ( V_49 , 3 , V_57 , V_82 ) ;
}
}
}
return 0 ;
}
static bool F_196 ( struct V_18 * V_19 , T_1 V_49 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_135 * V_136 = & V_2 -> V_137 ;
unsigned int V_20 ;
int V_16 ;
if ( ! V_2 -> V_37 )
return false ;
for ( V_16 = 0 ; V_16 < V_136 -> V_179 ; V_16 ++ ) {
if ( V_136 -> V_180 [ V_16 ] . V_45 != V_49 )
continue;
if ( V_136 -> V_180 [ V_16 ] . type != V_178 )
return false ;
V_20 = F_102 ( V_19 , V_49 ) ;
return F_150 ( V_20 ) == V_265 ;
}
return false ;
}
static int F_197 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_228 ;
V_228 = F_91 ( V_127 , V_129 ) ;
if ( V_228 < 0 )
return V_228 ;
if ( V_2 -> V_329 )
V_2 -> V_329 ( V_19 , V_129 ) ;
return V_228 ;
}
static int F_198 ( struct V_18 * V_19 , const char * V_312 ,
int V_57 , bool V_331 , unsigned int V_332 ,
bool V_333 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
char V_334 [ V_120 ] ;
int type = V_331 ? V_124 : V_122 ;
const char * V_119 = V_331 ? L_67 : L_68 ;
unsigned int V_77 = V_333 ? 1 : 3 ;
struct V_4 * V_12 ;
if ( ! V_332 )
return 0 ;
if ( V_312 )
snprintf ( V_334 , sizeof( V_334 ) ,
L_69 , V_312 , V_119 ) ;
else
snprintf ( V_334 , sizeof( V_334 ) ,
L_70 , V_119 ) ;
V_12 = F_76 ( V_2 , type , V_334 , V_57 ,
F_45 ( V_332 , V_77 ) ) ;
if ( ! V_12 )
return - V_121 ;
if ( V_331 )
V_12 -> V_335 = F_197 ;
if ( ! V_333 )
return 0 ;
if ( V_312 )
snprintf ( V_334 , sizeof( V_334 ) ,
L_71 , V_312 , V_119 ) ;
else
snprintf ( V_334 , sizeof( V_334 ) ,
L_72 , V_119 ) ;
V_12 = F_76 ( V_2 , type , V_334 , V_57 ,
F_45 ( V_332 , 2 ) ) ;
if ( ! V_12 )
return - V_121 ;
if ( V_331 )
V_12 -> V_335 = F_197 ;
return 0 ;
}
static int F_199 ( struct V_18 * V_19 , int V_57 ,
unsigned int V_336 , unsigned int V_337 ,
bool V_333 )
{
int V_190 ;
V_190 = F_198 ( V_19 , NULL , V_57 , false , V_336 , V_333 ) ;
if ( V_190 < 0 )
return V_190 ;
V_190 = F_198 ( V_19 , NULL , V_57 , true , V_337 , V_333 ) ;
if ( V_190 < 0 )
return V_190 ;
return 0 ;
}
static int F_200 ( struct V_18 * V_19 , int V_57 ,
unsigned int V_336 , unsigned int V_337 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
if ( V_336 ) {
V_12 = F_4 ( V_2 , NULL , & V_338 ) ;
if ( ! V_12 )
return - V_121 ;
V_12 -> V_115 = V_57 ;
V_12 -> V_118 = V_336 ;
V_12 -> V_116 = V_117 ;
}
if ( V_337 ) {
V_12 = F_4 ( V_2 , NULL , & V_339 ) ;
if ( ! V_12 )
return - V_121 ;
V_12 -> V_115 = V_57 ;
V_12 -> V_118 = V_337 ;
V_12 -> V_116 = V_117 ;
}
return 0 ;
}
static unsigned int F_201 ( struct V_18 * V_19 , int V_57 , int type )
{
struct V_6 * V_51 ;
unsigned int V_332 ;
int V_16 ;
V_51 = F_184 ( V_19 , 0 , V_57 ) ;
if ( ! V_51 )
return 0 ;
V_332 = V_51 -> V_59 [ type ] ;
if ( ! V_332 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_57 - 1 ; V_16 ++ ) {
V_51 = F_184 ( V_19 , 0 , V_16 ) ;
if ( V_51 && V_51 -> V_59 [ type ] == V_332 )
return 0 ;
}
return V_332 ;
}
static int F_202 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_303 * V_304 = & V_2 -> V_305 ;
int V_16 , V_190 , type ;
for ( V_16 = 0 ; V_16 < V_304 -> V_307 ; V_16 ++ ) {
bool V_333 ;
int V_57 ;
V_57 = V_304 -> V_239 [ V_16 ] . V_115 ;
if ( V_57 >= V_2 -> V_137 . V_179 )
continue;
V_333 = F_196 ( V_19 , V_2 -> V_318 [ V_16 ] ) ;
for ( type = 0 ; type < 2 ; type ++ ) {
V_190 = F_198 ( V_19 ,
V_2 -> V_319 [ V_57 ] ,
V_2 -> V_320 [ V_57 ] ,
type ,
F_201 ( V_19 , V_16 , type ) ,
V_333 ) ;
if ( V_190 < 0 )
return V_190 ;
}
}
return 0 ;
}
static int F_203 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_303 * V_304 = & V_2 -> V_305 ;
int V_16 , V_86 , V_50 , V_190 ;
if ( V_2 -> V_309 )
V_50 = 1 ;
else
V_50 = V_2 -> V_300 ;
if ( ! V_2 -> V_340 && V_304 -> V_307 > 1 ) {
struct V_4 * V_12 ;
const char * V_10 ;
V_10 = V_50 > 1 ? L_73 : L_74 ;
V_12 = F_4 ( V_2 , V_10 , & V_341 ) ;
if ( ! V_12 )
return - V_121 ;
V_12 -> V_238 = V_50 ;
}
for ( V_86 = 0 ; V_86 < V_50 ; V_86 ++ ) {
bool V_71 = false ;
bool V_36 = V_2 -> V_36 ;
bool V_333 = false ;
int V_342 , V_343 ;
V_342 = V_343 = 0 ;
for ( V_16 = 0 ; V_16 < V_304 -> V_307 ; V_16 ++ ) {
struct V_6 * V_51 ;
V_51 = F_184 ( V_19 , V_86 , V_16 ) ;
if ( ! V_51 )
continue;
F_195 ( V_19 , V_51 ) ;
if ( ! V_342 )
V_342 = V_51 -> V_59 [ V_97 ] ;
else if ( V_342 != V_51 -> V_59 [ V_97 ] ) {
V_71 = true ;
if ( ! F_48 ( V_19 , V_342 ,
V_51 -> V_59 [ V_97 ] , V_82 ) )
V_36 = true ;
}
if ( ! V_343 )
V_343 = V_51 -> V_59 [ V_96 ] ;
else if ( V_343 != V_51 -> V_59 [ V_96 ] ) {
V_71 = true ;
if ( ! F_48 ( V_19 , V_343 ,
V_51 -> V_59 [ V_96 ] , V_82 ) )
V_36 = true ;
}
if ( F_196 ( V_19 , V_2 -> V_318 [ V_16 ] ) )
V_333 = true ;
}
if ( ! V_71 )
V_190 = F_199 ( V_19 , V_86 , V_342 , V_343 ,
V_333 ) ;
else if ( ! V_36 )
V_190 = F_200 ( V_19 , V_86 , V_342 , V_343 ) ;
else
V_190 = F_202 ( V_19 ) ;
if ( V_190 < 0 )
return V_190 ;
}
return 0 ;
}
static bool F_204 ( struct V_18 * V_19 , T_1 V_49 ,
int V_60 , int V_57 )
{
unsigned int V_344 ;
if ( ! F_52 ( V_19 , V_49 , V_60 ) ||
F_32 ( V_19 , V_49 , V_60 , V_57 , V_97 ) ||
F_32 ( V_19 , V_49 , V_60 , V_57 , V_98 ) )
return false ;
V_344 = ( F_47 ( V_19 , V_49 , V_60 ) & V_345 )
>> V_346 ;
if ( V_344 < 0x20 )
return false ;
return true ;
}
static unsigned int F_205 ( struct V_18 * V_19 ,
struct V_6 * V_51 )
{
unsigned int V_20 = 0 ;
T_1 V_49 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < 3 ; V_52 ++ ) {
if ( V_52 >= V_51 -> V_52 - 1 )
break;
V_49 = V_51 -> V_51 [ V_52 ] ;
if ( V_52 && F_204 ( V_19 , V_49 , V_81 , 0 ) ) {
V_20 = F_33 ( V_49 , 3 , 0 , V_81 ) ;
break;
} else if ( F_204 ( V_19 , V_49 , V_82 ,
V_51 -> V_57 [ V_52 ] ) ) {
V_20 = F_33 ( V_49 , 3 , V_51 -> V_57 [ V_52 ] ,
V_82 ) ;
break;
}
}
return V_20 ;
}
static int F_206 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_135 * V_136 = & V_2 -> V_137 ;
struct V_303 * V_304 = & V_2 -> V_305 ;
int V_16 ;
if ( ! V_2 -> V_300 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_304 -> V_307 ; V_16 ++ ) {
struct V_6 * V_51 ;
unsigned int V_20 ;
int V_57 ;
char V_347 [ V_120 ] ;
V_57 = V_304 -> V_239 [ V_16 ] . V_115 ;
if ( V_57 >= V_304 -> V_307 )
continue;
if ( V_136 -> V_180 [ V_57 ] . type > V_177 )
continue;
V_51 = F_184 ( V_19 , 0 , V_16 ) ;
if ( ! V_51 )
continue;
V_20 = F_205 ( V_19 , V_51 ) ;
if ( ! V_20 )
continue;
snprintf ( V_347 , sizeof( V_347 ) ,
L_75 , V_2 -> V_319 [ V_57 ] ) ;
if ( ! F_76 ( V_2 , V_122 , V_347 ,
V_2 -> V_320 [ V_57 ] , V_20 ) )
return - V_121 ;
V_51 -> V_59 [ V_98 ] = V_20 ;
}
return 0 ;
}
static void F_207 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_51 ;
int V_16 , V_50 ;
T_1 V_348 , V_45 ;
V_50 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_137 . V_349 ; V_16 ++ ) {
V_45 = V_2 -> V_137 . V_350 [ V_16 ] ;
V_348 = F_44 ( V_19 , V_45 , true ) ;
if ( ! V_348 )
continue;
V_51 = F_42 ( V_19 , V_348 , V_45 , 0 ) ;
if ( ! V_51 )
continue;
F_34 ( L_76 , V_51 ) ;
V_51 -> V_87 = true ;
V_2 -> V_193 [ V_16 ] = F_26 ( V_19 , V_51 ) ;
F_17 ( V_19 , V_45 , V_220 , false ) ;
if ( ! V_50 ) {
V_2 -> V_144 . V_351 = V_348 ;
V_2 -> V_352 = V_2 -> V_137 . V_352 [ 0 ] ;
} else {
V_2 -> V_144 . V_353 = V_2 -> V_353 ;
if ( V_50 >= F_94 ( V_2 -> V_353 ) - 1 )
break;
V_2 -> V_353 [ V_50 - 1 ] = V_348 ;
}
V_50 ++ ;
}
if ( V_2 -> V_137 . V_354 ) {
V_45 = V_2 -> V_137 . V_354 ;
V_348 = V_19 -> V_207 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_208 ; V_16 ++ , V_348 ++ ) {
unsigned int V_355 = F_40 ( V_19 , V_348 ) ;
if ( F_39 ( V_355 ) != V_68 )
continue;
if ( ! ( V_355 & V_76 ) )
continue;
V_51 = F_42 ( V_19 , V_45 , V_348 , 0 ) ;
if ( V_51 ) {
F_34 ( L_77 , V_51 ) ;
V_51 -> V_87 = true ;
V_2 -> V_356 = V_348 ;
V_2 -> V_196 = F_26 ( V_19 , V_51 ) ;
F_17 ( V_19 , V_45 , V_259 , false ) ;
break;
}
}
}
}
static int F_190 ( struct V_18 * V_19 , unsigned int V_323 ,
unsigned int V_57 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_303 * V_304 ;
struct V_6 * V_357 , * V_51 ;
V_304 = & V_2 -> V_305 ;
if ( ! V_304 -> V_307 )
return 0 ;
if ( V_57 >= V_304 -> V_307 )
V_57 = V_304 -> V_307 - 1 ;
if ( V_2 -> V_257 [ V_323 ] == V_57 )
return 0 ;
V_357 = F_184 ( V_19 , V_323 , V_2 -> V_257 [ V_323 ] ) ;
if ( ! V_357 )
return 0 ;
if ( V_357 -> V_87 )
F_64 ( V_19 , V_357 , false , false ) ;
V_2 -> V_257 [ V_323 ] = V_57 ;
if ( V_2 -> V_42 )
F_146 ( V_19 , V_323 , false ) ;
if ( V_2 -> V_309 )
F_208 ( V_19 , V_57 ) ;
V_51 = F_184 ( V_19 , V_323 , V_57 ) ;
if ( ! V_51 )
return 0 ;
if ( V_51 -> V_87 )
return 0 ;
F_64 ( V_19 , V_51 , true , false ) ;
if ( V_2 -> V_329 )
V_2 -> V_329 ( V_19 , NULL ) ;
F_68 ( V_19 , V_357 ) ;
return 1 ;
}
static bool F_209 ( struct V_18 * V_19 , int V_47 , T_1 * V_48 )
{
int V_16 , V_358 = 0 ;
for ( V_16 = 0 ; V_16 < V_47 ; V_16 ++ ) {
T_1 V_49 = V_48 [ V_16 ] ;
if ( ! V_49 )
break;
if ( F_16 ( V_19 , V_49 ) & V_359 )
continue;
V_358 |= F_210 ( V_19 , V_49 ) ;
}
return V_358 ;
}
static void F_211 ( struct V_18 * V_19 , int V_47 , T_1 * V_48 ,
bool V_360 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_47 ; V_16 ++ ) {
T_1 V_49 = V_48 [ V_16 ] ;
unsigned int V_20 , V_288 ;
if ( ! V_49 )
break;
if ( V_2 -> V_33 ) {
if ( V_360 )
V_2 -> V_131 |= ( 1ULL << V_49 ) ;
else
V_2 -> V_131 &= ~ ( 1ULL << V_49 ) ;
F_72 ( V_19 , V_49 , ! V_360 ) ;
continue;
}
V_288 = F_16 ( V_19 , V_49 ) ;
if ( V_288 & V_259 )
continue;
if ( V_2 -> V_361 )
V_20 = V_288 & ~ V_219 ;
else
V_20 = 0 ;
if ( ! V_360 )
V_20 |= V_288 ;
F_15 ( V_19 , V_49 , V_20 ) ;
F_72 ( V_19 , V_49 , ! V_360 ) ;
}
}
void F_212 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_362 ;
F_211 ( V_19 , F_94 ( V_2 -> V_137 . V_199 ) ,
V_2 -> V_137 . V_199 , V_2 -> V_363 ) ;
if ( ! V_2 -> V_364 )
V_362 = 0 ;
else
V_362 = V_2 -> V_365 | V_2 -> V_366 ;
V_362 |= V_2 -> V_363 ;
V_2 -> V_367 = V_362 ;
F_211 ( V_19 , F_94 ( V_2 -> V_137 . V_200 ) ,
V_2 -> V_137 . V_200 , V_362 ) ;
if ( V_2 -> V_137 . V_198 [ 0 ] == V_2 -> V_137 . V_199 [ 0 ] ||
V_2 -> V_137 . V_198 [ 0 ] == V_2 -> V_137 . V_200 [ 0 ] )
return;
if ( ! V_2 -> V_368 )
V_362 = 0 ;
else
V_362 = V_2 -> V_365 ;
V_362 |= V_2 -> V_363 ;
V_2 -> V_369 = V_362 ;
F_211 ( V_19 , F_94 ( V_2 -> V_137 . V_198 ) ,
V_2 -> V_137 . V_198 , V_362 ) ;
}
static void F_213 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_370 )
V_2 -> V_370 ( V_19 ) ;
else
F_212 ( V_19 ) ;
if ( V_2 -> V_33 && ! V_19 -> V_371 -> V_372 )
F_214 ( V_2 -> V_142 . V_373 , false ) ;
}
void F_215 ( struct V_18 * V_19 , struct V_374 * V_375 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 * V_48 = V_2 -> V_137 . V_199 ;
int V_47 = F_94 ( V_2 -> V_137 . V_199 ) ;
if ( V_2 -> V_226 ) {
V_48 ++ ;
V_47 -- ;
}
V_2 -> V_365 = F_209 ( V_19 , V_47 , V_48 ) ;
if ( ! V_2 -> V_376 || ( ! V_2 -> V_364 && ! V_2 -> V_368 ) )
return;
F_213 ( V_19 ) ;
}
void F_216 ( struct V_18 * V_19 , struct V_374 * V_375 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_137 . V_149 == V_150 )
return;
if ( V_2 -> V_137 . V_198 [ 0 ] == V_2 -> V_137 . V_199 [ 0 ] )
return;
V_2 -> V_366 =
F_209 ( V_19 , F_94 ( V_2 -> V_137 . V_198 ) ,
V_2 -> V_137 . V_198 ) ;
if ( ! V_2 -> V_364 || ! V_2 -> V_377 )
return;
F_213 ( V_19 ) ;
}
void F_217 ( struct V_18 * V_19 , struct V_374 * V_375 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
if ( ! V_2 -> V_340 )
return;
for ( V_16 = V_2 -> V_378 - 1 ; V_16 > 0 ; V_16 -- ) {
T_1 V_45 = V_2 -> V_379 [ V_16 ] . V_45 ;
if ( F_16 ( V_19 , V_45 ) & V_380 )
continue;
if ( F_210 ( V_19 , V_45 ) ) {
F_190 ( V_19 , 0 , V_2 -> V_379 [ V_16 ] . V_57 ) ;
return;
}
}
F_190 ( V_19 , 0 , V_2 -> V_379 [ 0 ] . V_57 ) ;
}
static void F_131 ( struct V_18 * V_19 , struct V_374 * V_375 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_381 )
V_2 -> V_381 ( V_19 , V_375 ) ;
else
F_215 ( V_19 , V_375 ) ;
}
static void F_218 ( struct V_18 * V_19 ,
struct V_374 * V_375 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_382 )
V_2 -> V_382 ( V_19 , V_375 ) ;
else
F_216 ( V_19 , V_375 ) ;
}
static void F_219 ( struct V_18 * V_19 ,
struct V_374 * V_375 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_383 )
V_2 -> V_383 ( V_19 , V_375 ) ;
else
F_217 ( V_19 , V_375 ) ;
}
static void F_139 ( struct V_18 * V_19 )
{
F_131 ( V_19 , NULL ) ;
F_218 ( V_19 , NULL ) ;
F_219 ( V_19 , NULL ) ;
}
static int F_220 ( struct V_126 * V_127 ,
struct V_222 * V_223 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_384 [] = {
L_78 , L_79 , L_80
} ;
if ( V_2 -> V_385 && V_2 -> V_386 )
return F_152 ( V_127 , V_223 , 3 , V_384 ) ;
return F_126 ( V_127 , V_223 ) ;
}
static int F_221 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = 0 ;
if ( V_2 -> V_364 )
V_20 ++ ;
if ( V_2 -> V_368 )
V_20 ++ ;
V_129 -> V_132 . V_224 . V_225 [ 0 ] = V_20 ;
return 0 ;
}
static int F_222 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_18 * V_19 = F_89 ( V_127 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
switch ( V_129 -> V_132 . V_224 . V_225 [ 0 ] ) {
case 0 :
if ( ! V_2 -> V_364 && ! V_2 -> V_368 )
return 0 ;
V_2 -> V_364 = 0 ;
V_2 -> V_368 = 0 ;
break;
case 1 :
if ( V_2 -> V_385 ) {
if ( ! V_2 -> V_368 && V_2 -> V_364 )
return 0 ;
V_2 -> V_364 = 1 ;
V_2 -> V_368 = 0 ;
} else if ( V_2 -> V_386 ) {
if ( V_2 -> V_368 )
return 0 ;
V_2 -> V_368 = 1 ;
} else
return - V_241 ;
break;
case 2 :
if ( ! V_2 -> V_386 || ! V_2 -> V_385 )
return - V_241 ;
if ( V_2 -> V_364 && V_2 -> V_368 )
return 0 ;
V_2 -> V_364 = 1 ;
V_2 -> V_368 = 1 ;
break;
default:
return - V_241 ;
}
F_213 ( V_19 ) ;
return 1 ;
}
static int F_223 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! F_4 ( V_2 , NULL , & V_387 ) )
return - V_121 ;
return 0 ;
}
static int F_224 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_135 * V_136 = & V_2 -> V_137 ;
int V_358 = 0 ;
int V_16 , V_190 ;
if ( V_2 -> V_30 )
return 0 ;
if ( V_136 -> V_199 [ 0 ] )
V_358 ++ ;
if ( V_136 -> V_198 [ 0 ] )
V_358 ++ ;
if ( V_136 -> V_200 [ 0 ] )
V_358 ++ ;
if ( V_358 < 2 )
return 0 ;
if ( ! V_136 -> V_200 [ 0 ] &&
V_136 -> V_149 == V_150 ) {
memcpy ( V_136 -> V_200 , V_136 -> V_198 ,
sizeof( V_136 -> V_200 ) ) ;
V_136 -> V_141 = V_136 -> V_138 ;
}
if ( ! V_136 -> V_199 [ 0 ] &&
V_136 -> V_149 == V_152 ) {
memcpy ( V_136 -> V_199 , V_136 -> V_198 ,
sizeof( V_136 -> V_199 ) ) ;
V_136 -> V_140 = V_136 -> V_138 ;
}
for ( V_16 = 0 ; V_16 < V_136 -> V_140 ; V_16 ++ ) {
T_1 V_49 = V_136 -> V_199 [ V_16 ] ;
if ( ! F_225 ( V_19 , V_49 ) )
continue;
F_36 ( L_81 ,
V_49 ) ;
F_226 ( V_19 , V_49 , V_388 ,
F_131 ) ;
V_2 -> V_376 = 1 ;
}
if ( V_136 -> V_149 == V_389 && V_136 -> V_138 ) {
if ( V_136 -> V_141 )
for ( V_16 = 0 ; V_16 < V_136 -> V_138 ; V_16 ++ ) {
T_1 V_49 = V_136 -> V_198 [ V_16 ] ;
if ( ! F_225 ( V_19 , V_49 ) )
continue;
F_36 ( L_82 , V_49 ) ;
F_226 ( V_19 , V_49 ,
V_390 ,
F_218 ) ;
V_2 -> V_377 = 1 ;
}
V_2 -> V_386 = V_2 -> V_376 ;
}
V_2 -> V_385 = V_136 -> V_141 &&
( V_2 -> V_376 || V_2 -> V_377 ) ;
V_2 -> V_368 = V_2 -> V_386 ;
V_2 -> V_364 = V_2 -> V_385 ;
if ( V_2 -> V_385 || V_2 -> V_386 ) {
V_190 = F_223 ( V_19 ) ;
if ( V_190 < 0 )
return V_190 ;
}
return 0 ;
}
static bool F_227 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_303 * V_304 ;
int V_16 ;
V_304 = & V_2 -> V_305 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_378 ; V_16 ++ ) {
V_2 -> V_379 [ V_16 ] . V_57 =
F_21 ( V_2 -> V_379 [ V_16 ] . V_45 ,
V_2 -> V_318 , V_304 -> V_307 ) ;
if ( V_2 -> V_379 [ V_16 ] . V_57 < 0 )
return false ;
}
for ( V_16 = 1 ; V_16 < V_2 -> V_378 ; V_16 ++ )
F_226 ( V_19 ,
V_2 -> V_379 [ V_16 ] . V_45 ,
V_391 ,
F_219 ) ;
return true ;
}
static int F_228 ( const void * V_392 , const void * V_393 )
{
const struct V_394 * V_395 = V_392 ;
const struct V_394 * V_396 = V_393 ;
return ( int ) ( V_395 -> V_397 - V_396 -> V_397 ) ;
}
static int F_229 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_135 * V_136 = & V_2 -> V_137 ;
unsigned int V_398 ;
int V_16 , V_47 ;
if ( V_2 -> V_31 )
return 0 ;
V_398 = 0 ;
V_47 = 0 ;
for ( V_16 = 0 ; V_16 < V_136 -> V_179 ; V_16 ++ ) {
T_1 V_49 = V_136 -> V_180 [ V_16 ] . V_45 ;
unsigned int V_397 ;
V_397 = F_102 ( V_19 , V_49 ) ;
V_397 = F_150 ( V_397 ) ;
if ( V_398 & ( 1 << V_397 ) )
return 0 ;
switch ( V_397 ) {
case V_265 :
if ( V_136 -> V_180 [ V_16 ] . type != V_178 )
return 0 ;
break;
case V_399 :
return 0 ;
default:
if ( V_136 -> V_180 [ V_16 ] . type > V_177 )
return 0 ;
if ( ! V_2 -> V_32 &&
V_136 -> V_180 [ V_16 ] . type != V_178 )
return 0 ;
if ( ! F_225 ( V_19 , V_49 ) )
return 0 ;
break;
}
if ( V_47 >= V_400 )
return 0 ;
V_398 |= ( 1 << V_397 ) ;
V_2 -> V_379 [ V_47 ] . V_45 = V_49 ;
V_2 -> V_379 [ V_47 ] . V_397 = V_397 ;
V_47 ++ ;
}
if ( V_47 < 2 )
return 0 ;
V_2 -> V_378 = V_47 ;
F_230 ( V_2 -> V_379 , V_47 , sizeof( V_2 -> V_379 [ 0 ] ) ,
F_228 , NULL ) ;
if ( ! F_227 ( V_19 ) )
return 0 ;
V_2 -> V_340 = 1 ;
V_2 -> V_300 = 1 ;
V_2 -> V_257 [ 0 ] = V_2 -> V_379 [ 0 ] . V_57 ;
F_36 ( L_83 ,
V_2 -> V_379 [ 0 ] . V_45 ,
V_2 -> V_379 [ 1 ] . V_45 ,
V_2 -> V_379 [ 2 ] . V_45 ) ;
return 0 ;
}
static unsigned int F_231 ( struct V_18 * V_19 ,
T_1 V_49 ,
unsigned int V_401 )
{
if ( V_401 != V_102 )
return V_401 ;
if ( F_39 ( F_40 ( V_19 , V_49 ) ) >= V_402 )
return V_401 ;
if ( F_69 ( V_19 , V_49 ) )
return V_401 ;
return V_106 ;
}
int F_232 ( struct V_18 * V_19 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_190 ;
F_11 ( V_19 ) ;
if ( V_2 -> V_44 && ! V_2 -> V_101 )
V_2 -> V_101 = V_2 -> V_44 ;
if ( V_136 != & V_2 -> V_137 ) {
V_2 -> V_137 = * V_136 ;
V_136 = & V_2 -> V_137 ;
}
if ( ! V_2 -> V_201 )
V_2 -> V_201 = & V_403 ;
if ( ! V_2 -> V_202 )
V_2 -> V_202 = & V_404 ;
F_115 ( V_19 ) ;
if ( ! V_136 -> V_138 ) {
if ( V_136 -> V_349 || V_136 -> V_354 ) {
V_2 -> V_144 . V_243 = 2 ;
V_2 -> V_405 = 1 ;
goto V_406;
}
return 0 ;
}
if ( ! V_2 -> V_35 &&
V_136 -> V_149 == V_150 &&
V_136 -> V_138 <= V_136 -> V_140 ) {
V_136 -> V_141 = V_136 -> V_138 ;
memcpy ( V_136 -> V_200 , V_136 -> V_198 ,
sizeof( V_136 -> V_200 ) ) ;
V_136 -> V_138 = V_136 -> V_140 ;
memcpy ( V_136 -> V_198 , V_136 -> V_199 , sizeof( V_136 -> V_199 ) ) ;
V_136 -> V_140 = 0 ;
memset ( V_136 -> V_199 , 0 , sizeof( V_136 -> V_199 ) ) ;
V_136 -> V_149 = V_152 ;
}
V_190 = F_117 ( V_19 ) ;
if ( V_190 < 0 )
return V_190 ;
V_190 = F_142 ( V_19 ) ;
if ( V_190 < 0 )
return V_190 ;
V_190 = F_120 ( V_19 , V_136 ) ;
if ( V_190 < 0 )
return V_190 ;
V_190 = F_123 ( V_19 ) ;
if ( V_190 < 0 )
return V_190 ;
V_190 = F_124 ( V_19 ) ;
if ( V_190 < 0 )
return V_190 ;
V_190 = F_133 ( V_19 ) ;
if ( V_190 < 0 )
return V_190 ;
V_190 = F_145 ( V_19 ) ;
if ( V_190 < 0 )
return V_190 ;
V_190 = F_149 ( V_19 ) ;
if ( V_190 < 0 )
return V_190 ;
V_190 = F_183 ( V_19 ) ;
if ( V_190 < 0 )
return V_190 ;
V_2 -> V_244 = V_2 -> V_203 ;
if ( V_136 -> V_149 != V_150 )
V_2 -> V_244 = F_141 ( V_2 -> V_244 ,
V_136 -> V_141 * 2 ) ;
if ( V_136 -> V_149 != V_152 )
V_2 -> V_244 = F_141 ( V_2 -> V_244 ,
V_136 -> V_140 * 2 ) ;
V_2 -> V_144 . V_243 = F_141 ( V_2 -> V_203 ,
V_2 -> V_244 ) ;
V_190 = F_224 ( V_19 ) ;
if ( V_190 < 0 )
return V_190 ;
V_190 = F_178 ( V_19 ) ;
if ( V_190 < 0 )
return V_190 ;
V_190 = F_229 ( V_19 ) ;
if ( V_190 < 0 )
return V_190 ;
V_190 = F_203 ( V_19 ) ;
if ( V_190 < 0 )
return V_190 ;
V_190 = F_206 ( V_19 ) ;
if ( V_190 < 0 )
return V_190 ;
if ( V_2 -> V_40 ) {
if ( V_136 -> V_149 != V_150 ) {
V_190 = F_159 ( V_19 , V_136 -> V_138 ,
V_136 -> V_198 ) ;
if ( V_190 < 0 )
return V_190 ;
}
if ( V_136 -> V_149 != V_152 ) {
V_190 = F_159 ( V_19 , V_136 -> V_140 ,
V_136 -> V_199 ) ;
if ( V_190 < 0 )
return V_190 ;
}
}
V_406:
F_207 ( V_19 ) ;
if ( V_2 -> V_41 )
V_19 -> V_407 = F_231 ;
if ( ! V_2 -> V_405 && V_2 -> V_408 ) {
V_190 = F_233 ( V_19 , V_2 -> V_408 ) ;
if ( V_190 < 0 )
return V_190 ;
}
return 1 ;
}
int F_234 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_190 ;
if ( V_2 -> V_3 . V_17 ) {
V_190 = F_235 ( V_19 , V_2 -> V_3 . V_14 ) ;
if ( V_190 < 0 )
return V_190 ;
}
if ( V_2 -> V_144 . V_351 ) {
V_190 = F_236 ( V_19 ,
V_2 -> V_144 . V_351 ,
V_2 -> V_144 . V_351 ,
V_2 -> V_409 [ 1 ] . V_410 ) ;
if ( V_190 < 0 )
return V_190 ;
if ( ! V_2 -> V_405 ) {
V_190 = F_237 ( V_19 ,
& V_2 -> V_144 ) ;
if ( V_190 < 0 )
return V_190 ;
V_2 -> V_144 . V_411 = 1 ;
}
}
if ( V_2 -> V_356 ) {
V_190 = F_238 ( V_19 , V_2 -> V_356 ) ;
if ( V_190 < 0 )
return V_190 ;
}
if ( ! V_2 -> V_405 &&
! F_239 ( V_19 , L_84 ) ) {
V_190 = F_240 ( V_19 , L_84 ,
V_2 -> V_217 , V_412 ,
L_85 ) ;
if ( V_190 < 0 )
return V_190 ;
}
if ( ! V_2 -> V_405 &&
! F_239 ( V_19 , L_86 ) ) {
V_190 = F_241 ( V_19 , L_86 ,
NULL , V_412 ,
L_87 ,
true , & V_2 -> V_142 . V_373 ) ;
if ( V_190 < 0 )
return V_190 ;
if ( V_2 -> V_142 . V_143 )
F_242 ( V_19 , & V_2 -> V_142 ,
V_2 -> V_413 ) ;
}
F_7 ( V_2 ) ;
V_190 = F_243 ( V_19 , & V_2 -> V_137 ) ;
if ( V_190 < 0 )
return V_190 ;
return 0 ;
}
static void F_244 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
struct V_416 * V_417 ,
int V_418 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_419 )
V_2 -> V_419 ( V_415 , V_19 , V_417 , V_418 ) ;
}
static void F_245 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
struct V_416 * V_417 ,
int V_418 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_420 )
V_2 -> V_420 ( V_415 , V_19 , V_417 , V_418 ) ;
}
static int F_246 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_190 ;
F_129 ( & V_2 -> V_9 ) ;
V_190 = F_247 ( V_19 ,
& V_2 -> V_144 , V_417 ,
V_415 ) ;
if ( ! V_190 ) {
V_2 -> V_229 |= 1 << V_421 ;
F_244 ( V_415 , V_19 , V_417 ,
V_422 ) ;
}
F_132 ( & V_2 -> V_9 ) ;
return V_190 ;
}
static int F_248 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
unsigned int V_423 ,
unsigned int V_424 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_190 ;
V_190 = F_249 ( V_19 , & V_2 -> V_144 ,
V_423 , V_424 , V_417 ) ;
if ( ! V_190 )
F_244 ( V_415 , V_19 , V_417 ,
V_425 ) ;
return V_190 ;
}
static int F_250 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_190 ;
V_190 = F_251 ( V_19 , & V_2 -> V_144 ) ;
if ( ! V_190 )
F_244 ( V_415 , V_19 , V_417 ,
V_426 ) ;
return V_190 ;
}
static int F_252 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_129 ( & V_2 -> V_9 ) ;
V_2 -> V_229 &= ~ ( 1 << V_421 ) ;
F_244 ( V_415 , V_19 , V_417 ,
V_427 ) ;
F_132 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_253 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
struct V_416 * V_417 )
{
F_245 ( V_415 , V_19 , V_417 , V_422 ) ;
return 0 ;
}
static int F_254 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
unsigned int V_423 ,
unsigned int V_424 ,
struct V_416 * V_417 )
{
F_255 ( V_19 , V_415 -> V_49 , V_423 , 0 , V_424 ) ;
F_245 ( V_415 , V_19 , V_417 ,
V_425 ) ;
return 0 ;
}
static int F_256 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
struct V_416 * V_417 )
{
F_257 ( V_19 , V_415 -> V_49 ) ;
F_245 ( V_415 , V_19 , V_417 ,
V_426 ) ;
return 0 ;
}
static int F_258 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
struct V_416 * V_417 )
{
F_245 ( V_415 , V_19 , V_417 , V_427 ) ;
return 0 ;
}
static int F_259 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_190 = 0 ;
F_129 ( & V_2 -> V_9 ) ;
if ( ! V_2 -> V_226 )
V_190 = - V_230 ;
else
V_2 -> V_229 |= 1 << V_428 ;
F_244 ( V_415 , V_19 , V_417 ,
V_422 ) ;
F_132 ( & V_2 -> V_9 ) ;
return V_190 ;
}
static int F_260 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_129 ( & V_2 -> V_9 ) ;
V_2 -> V_229 &= ~ ( 1 << V_428 ) ;
F_244 ( V_415 , V_19 , V_417 ,
V_427 ) ;
F_132 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_261 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
unsigned int V_423 ,
unsigned int V_424 ,
struct V_416 * V_417 )
{
F_255 ( V_19 , V_415 -> V_49 , V_423 , 0 , V_424 ) ;
F_244 ( V_415 , V_19 , V_417 ,
V_425 ) ;
return 0 ;
}
static int F_262 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
struct V_416 * V_417 )
{
F_257 ( V_19 , V_415 -> V_49 ) ;
F_244 ( V_415 , V_19 , V_417 ,
V_426 ) ;
return 0 ;
}
static int F_263 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_264 ( V_19 , & V_2 -> V_144 ) ;
}
static int F_265 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
unsigned int V_423 ,
unsigned int V_424 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_266 ( V_19 , & V_2 -> V_144 ,
V_423 , V_424 , V_417 ) ;
}
static int F_267 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_268 ( V_19 , & V_2 -> V_144 ) ;
}
static int F_269 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_270 ( V_19 , & V_2 -> V_144 ) ;
}
static int F_271 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
unsigned int V_423 ,
unsigned int V_424 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_255 ( V_19 , V_2 -> V_298 [ V_417 -> V_429 + 1 ] ,
V_423 , 0 , V_424 ) ;
F_245 ( V_415 , V_19 , V_417 ,
V_425 ) ;
return 0 ;
}
static int F_272 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_257 ( V_19 ,
V_2 -> V_298 [ V_417 -> V_429 + 1 ] ) ;
F_245 ( V_415 , V_19 , V_417 ,
V_426 ) ;
return 0 ;
}
static bool F_208 ( struct V_18 * V_19 , int V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_431 = V_2 -> V_298 [ V_2 -> V_308 [ V_430 ] ] ;
if ( V_2 -> V_432 && V_2 -> V_432 != V_431 ) {
F_273 ( V_19 , V_2 -> V_432 , 1 ) ;
V_2 -> V_432 = V_431 ;
F_255 ( V_19 , V_431 ,
V_2 -> V_433 , 0 ,
V_2 -> V_434 ) ;
return true ;
}
return false ;
}
static int F_274 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
unsigned int V_423 ,
unsigned int V_424 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
V_2 -> V_432 = V_2 -> V_298 [ V_2 -> V_308 [ V_2 -> V_257 [ 0 ] ] ] ;
V_2 -> V_433 = V_423 ;
V_2 -> V_434 = V_424 ;
F_255 ( V_19 , V_2 -> V_432 , V_423 , 0 , V_424 ) ;
return 0 ;
}
static int F_275 ( struct V_414 * V_415 ,
struct V_18 * V_19 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_257 ( V_19 , V_2 -> V_432 ) ;
V_2 -> V_432 = 0 ;
return 0 ;
}
static void F_276 ( char * V_435 , T_3 V_436 , const char * V_119 ,
const char * V_437 )
{
char * V_438 ;
if ( * V_435 )
return;
F_277 ( V_435 , V_437 , V_436 ) ;
for ( V_438 = strchr ( V_435 , ' ' ) ; V_438 ; V_438 = strchr ( V_438 + 1 , ' ' ) ) {
if ( ! isalnum ( V_438 [ 1 ] ) ) {
* V_438 = 0 ;
break;
}
}
F_35 ( V_435 , V_119 , V_436 ) ;
}
int F_278 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_439 * V_440 = V_2 -> V_409 ;
const struct V_414 * V_438 ;
bool V_441 ;
V_19 -> V_442 = 1 ;
V_19 -> V_443 = V_440 ;
if ( V_2 -> V_405 )
goto V_444;
F_276 ( V_2 -> V_445 ,
sizeof( V_2 -> V_445 ) ,
L_88 , V_19 -> V_437 ) ;
V_440 -> V_10 = V_2 -> V_445 ;
if ( V_2 -> V_144 . V_145 > 0 ) {
V_438 = V_2 -> V_446 ;
if ( ! V_438 )
V_438 = & V_447 ;
V_440 -> V_448 [ V_449 ] = * V_438 ;
V_440 -> V_448 [ V_449 ] . V_49 = V_2 -> V_144 . V_191 [ 0 ] ;
V_440 -> V_448 [ V_449 ] . V_450 =
V_2 -> V_144 . V_243 ;
if ( V_2 -> V_137 . V_149 == V_150 &&
V_2 -> V_137 . V_138 == 2 )
V_440 -> V_448 [ V_449 ] . V_451 =
V_452 ;
}
if ( V_2 -> V_300 ) {
V_438 = V_2 -> V_453 ;
if ( ! V_438 ) {
if ( V_2 -> V_309 )
V_438 = & V_454 ;
else
V_438 = & V_455 ;
}
V_440 -> V_448 [ V_456 ] = * V_438 ;
V_440 -> V_448 [ V_456 ] . V_49 = V_2 -> V_298 [ 0 ] ;
}
V_444:
if ( V_2 -> V_144 . V_351 || V_2 -> V_356 ) {
F_276 ( V_2 -> V_457 ,
sizeof( V_2 -> V_457 ) ,
L_89 , V_19 -> V_437 ) ;
V_19 -> V_442 = 2 ;
V_19 -> V_353 = V_2 -> V_144 . V_353 ;
V_440 = V_2 -> V_409 + 1 ;
V_440 -> V_10 = V_2 -> V_457 ;
if ( V_2 -> V_352 )
V_440 -> V_410 = V_2 -> V_352 ;
else
V_440 -> V_410 = V_458 ;
if ( V_2 -> V_144 . V_351 ) {
V_438 = V_2 -> V_459 ;
if ( ! V_438 )
V_438 = & V_460 ;
V_440 -> V_448 [ V_449 ] = * V_438 ;
V_440 -> V_448 [ V_449 ] . V_49 = V_2 -> V_144 . V_351 ;
}
if ( V_2 -> V_356 ) {
V_438 = V_2 -> V_461 ;
if ( ! V_438 )
V_438 = & V_462 ;
V_440 -> V_448 [ V_456 ] = * V_438 ;
V_440 -> V_448 [ V_456 ] . V_49 = V_2 -> V_356 ;
}
}
if ( V_2 -> V_405 )
return 0 ;
V_441 = ( V_2 -> V_300 > 1 ) &&
! V_2 -> V_309 && ! V_2 -> V_340 ;
if ( V_2 -> V_235 || V_441 ) {
F_276 ( V_2 -> V_463 ,
sizeof( V_2 -> V_463 ) ,
L_90 , V_19 -> V_437 ) ;
V_19 -> V_442 = 3 ;
V_440 = V_2 -> V_409 + 2 ;
V_440 -> V_10 = V_2 -> V_463 ;
if ( V_2 -> V_235 ) {
V_438 = V_2 -> V_464 ;
if ( ! V_438 )
V_438 = & V_465 ;
V_440 -> V_448 [ V_449 ] = * V_438 ;
V_440 -> V_448 [ V_449 ] . V_49 =
V_2 -> V_235 ;
} else {
V_440 -> V_448 [ V_449 ] =
V_466 ;
V_440 -> V_448 [ V_449 ] . V_49 = 0 ;
}
if ( V_441 ) {
V_438 = V_2 -> V_467 ;
if ( ! V_438 )
V_438 = & V_468 ;
V_440 -> V_448 [ V_456 ] = * V_438 ;
V_440 -> V_448 [ V_456 ] . V_49 =
V_2 -> V_298 [ 1 ] ;
V_440 -> V_448 [ V_456 ] . V_469 =
V_2 -> V_300 - 1 ;
} else {
V_440 -> V_448 [ V_456 ] =
V_466 ;
V_440 -> V_448 [ V_456 ] . V_49 = 0 ;
}
}
return 0 ;
}
static void F_279 ( struct V_18 * V_19 , int V_112 )
{
struct V_6 * V_51 ;
T_1 V_45 ;
V_51 = F_27 ( V_19 , V_112 ) ;
if ( ! V_51 || ! V_51 -> V_52 )
return;
V_45 = V_51 -> V_51 [ V_51 -> V_52 - 1 ] ;
F_14 ( V_19 , V_45 ) ;
F_64 ( V_19 , V_51 , V_51 -> V_87 ,
F_137 ( V_19 -> V_2 ) ) ;
F_72 ( V_19 , V_45 , V_51 -> V_87 ) ;
}
static void F_280 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_137 . V_138 ; V_16 ++ )
F_279 ( V_19 , V_2 -> V_184 [ V_16 ] ) ;
}
static void F_281 ( struct V_18 * V_19 , int V_160 , int * V_5 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_160 ; V_16 ++ )
F_279 ( V_19 , V_5 [ V_16 ] ) ;
}
static void F_282 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_137 . V_149 != V_152 )
F_281 ( V_19 , V_2 -> V_137 . V_140 , V_2 -> V_151 ) ;
if ( V_2 -> V_137 . V_149 != V_150 )
F_281 ( V_19 , V_2 -> V_137 . V_141 ,
V_2 -> V_153 ) ;
}
static void F_283 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_139 ; V_16 ++ ) {
T_1 V_45 = V_2 -> V_158 [ V_16 ] . V_45 ;
struct V_6 * V_51 ;
V_51 = F_136 ( V_19 , V_16 ) ;
if ( ! V_51 )
continue;
if ( ! V_2 -> V_158 [ V_16 ] . V_242 )
V_2 -> V_158 [ V_16 ] . V_242 =
F_16 ( V_19 , V_45 ) ;
F_64 ( V_19 , V_51 , V_51 -> V_87 ,
F_137 ( V_2 ) ) ;
}
}
static void F_284 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_135 * V_136 = & V_2 -> V_137 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_136 -> V_179 ; V_16 ++ ) {
T_1 V_49 = V_136 -> V_180 [ V_16 ] . V_45 ;
if ( F_176 ( V_19 , V_49 ) )
F_14 ( V_19 , V_49 ) ;
if ( V_2 -> V_44 ) {
F_75 ( V_19 , V_2 -> V_195 [ V_16 ] ) ;
F_75 ( V_19 , V_2 -> V_297 ) ;
}
}
}
static void F_285 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_303 * V_304 = & V_2 -> V_305 ;
struct V_6 * V_51 ;
int V_16 , V_316 , V_50 ;
if ( V_2 -> V_309 )
V_50 = 1 ;
else
V_50 = V_2 -> V_300 ;
for ( V_316 = 0 ; V_316 < V_50 ; V_316 ++ ) {
for ( V_16 = 0 ; V_16 < V_304 -> V_307 ; V_16 ++ ) {
V_51 = F_184 ( V_19 , V_316 , V_16 ) ;
if ( V_51 ) {
bool V_87 = V_51 -> V_87 ;
if ( V_16 == V_2 -> V_257 [ V_316 ] )
V_87 = true ;
F_64 ( V_19 , V_51 , V_87 , false ) ;
}
}
if ( V_2 -> V_42 )
F_146 ( V_19 , V_316 , true ) ;
}
if ( V_2 -> V_329 )
V_2 -> V_329 ( V_19 , NULL ) ;
}
static void F_286 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_45 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_137 . V_349 ; V_16 ++ )
F_279 ( V_19 , V_2 -> V_193 [ V_16 ] ) ;
V_45 = V_2 -> V_137 . V_354 ;
if ( V_45 ) {
F_14 ( V_19 , V_45 ) ;
F_75 ( V_19 , V_2 -> V_196 ) ;
}
}
static void F_287 ( struct V_18 * V_19 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_470 . V_17 ; V_16 ++ ) {
struct V_471 * V_45 = F_24 ( & V_19 -> V_470 , V_16 ) ;
T_1 V_49 = V_45 -> V_49 ;
if ( F_225 ( V_19 , V_49 ) &&
! F_288 ( V_19 , V_49 ) )
F_74 ( V_19 , V_49 , 0 ,
V_472 , 0 ) ;
}
}
int F_289 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_473 )
V_2 -> V_473 ( V_19 ) ;
F_290 ( V_19 ) ;
V_19 -> V_328 = 1 ;
F_280 ( V_19 ) ;
F_282 ( V_19 ) ;
F_283 ( V_19 ) ;
F_284 ( V_19 ) ;
F_285 ( V_19 ) ;
F_286 ( V_19 ) ;
F_287 ( V_19 ) ;
F_139 ( V_19 ) ;
F_192 ( V_19 ) ;
if ( V_2 -> V_142 . V_373 && V_2 -> V_142 . V_143 )
F_291 ( & V_2 -> V_142 ) ;
F_292 ( V_19 , 0x01 ) ;
return 0 ;
}
void F_293 ( struct V_18 * V_19 )
{
F_294 ( V_19 ) ;
F_10 ( V_19 -> V_2 ) ;
F_8 ( V_19 -> V_2 ) ;
V_19 -> V_2 = NULL ;
}
int F_295 ( struct V_18 * V_19 , T_1 V_49 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_296 ( V_19 , & V_2 -> V_291 , V_49 ) ;
}
int F_297 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_190 ;
V_2 = F_298 ( sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 )
return - V_121 ;
F_1 ( V_2 ) ;
V_19 -> V_2 = V_2 ;
V_190 = F_299 ( V_19 , & V_2 -> V_137 , NULL , 0 ) ;
if ( V_190 < 0 )
return V_190 ;
V_190 = F_232 ( V_19 , & V_2 -> V_137 ) ;
if ( V_190 < 0 )
goto error;
V_19 -> V_474 = V_475 ;
return 0 ;
error:
F_293 ( V_19 ) ;
return V_190 ;
}
