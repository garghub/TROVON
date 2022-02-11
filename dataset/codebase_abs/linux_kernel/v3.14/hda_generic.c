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
static T_1 F_44 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const T_1 * V_14 = V_2 -> V_73 ;
if ( ! V_14 )
return 0 ;
for (; * V_14 ; V_14 += 2 )
if ( * V_14 == V_46 )
return V_14 [ 1 ] ;
return 0 ;
}
static T_1 F_45 ( struct V_18 * V_19 , T_1 V_46 ,
bool V_74 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_75 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_76 ; V_16 ++ ) {
T_1 V_50 = V_2 -> V_77 [ V_16 ] ;
if ( ! V_50 || F_28 ( V_19 , V_50 ) )
continue;
V_75 = ! ! ( F_40 ( V_19 , V_50 ) & V_78 ) ;
if ( V_74 != V_75 )
continue;
if ( F_29 ( V_19 , V_50 , V_46 ) )
return V_50 ;
}
return 0 ;
}
static unsigned int F_46 ( unsigned int V_20 , unsigned int V_79 )
{
V_20 &= ~ ( 0x3U << 16 ) ;
V_20 |= V_79 << 16 ;
return V_20 ;
}
static bool F_47 ( struct V_18 * V_19 , T_1 V_50 ,
int V_61 , unsigned int V_80 )
{
if ( ! V_50 )
return false ;
if ( F_40 ( V_19 , V_50 ) & ( 1 << ( V_61 + 1 ) ) )
if ( F_48 ( V_19 , V_50 , V_61 ) & V_80 )
return true ;
return false ;
}
static bool F_49 ( struct V_18 * V_19 , T_1 V_81 ,
T_1 V_82 , int V_61 )
{
if ( ! ( F_40 ( V_19 , V_81 ) & ( 1 << ( V_61 + 1 ) ) ) )
return ! ( F_40 ( V_19 , V_82 ) & ( 1 << ( V_61 + 1 ) ) ) ;
return ( F_48 ( V_19 , V_81 , V_61 ) ==
F_48 ( V_19 , V_82 , V_61 ) ) ;
}
static T_1 F_50 ( struct V_18 * V_19 ,
struct V_6 * V_52 )
{
int V_16 ;
for ( V_16 = V_52 -> V_53 - 1 ; V_16 >= 0 ; V_16 -- ) {
if ( F_51 ( V_19 , V_52 -> V_52 [ V_16 ] , V_83 ) )
return V_52 -> V_52 [ V_16 ] ;
if ( V_16 != V_52 -> V_53 - 1 && V_16 != 0 &&
F_51 ( V_19 , V_52 -> V_52 [ V_16 ] , V_84 ) )
return V_52 -> V_52 [ V_16 ] ;
}
return 0 ;
}
static T_1 F_52 ( struct V_18 * V_19 ,
struct V_6 * V_52 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = V_52 -> V_53 - 1 ; V_16 >= 0 ; V_16 -- ) {
T_1 V_50 = V_52 -> V_52 [ V_16 ] ;
if ( ( V_2 -> V_85 >> V_50 ) & 1 )
continue;
if ( F_53 ( V_19 , V_50 , V_83 ) )
return V_50 ;
}
return 0 ;
}
static bool F_54 ( struct V_18 * V_19 , struct V_6 * V_52 , int V_58 )
{
T_1 V_50 = V_52 -> V_52 [ V_58 ] ;
unsigned int V_86 = F_40 ( V_19 , V_50 ) ;
unsigned int type = F_39 ( V_86 ) ;
if ( ! ( V_86 & V_87 ) )
return false ;
if ( type == V_70 && V_58 > 0 )
return false ;
return true ;
}
static bool F_55 ( struct V_18 * V_19 , struct V_6 * V_52 , int V_58 )
{
T_1 V_50 = V_52 -> V_52 [ V_58 ] ;
unsigned int V_86 = F_40 ( V_19 , V_50 ) ;
unsigned int type = F_39 ( V_86 ) ;
if ( ! ( V_86 & V_88 ) )
return false ;
if ( type == V_70 && ! V_58 )
return false ;
return true ;
}
static bool F_56 ( struct V_18 * V_19 , T_1 V_50 ,
unsigned int V_61 , unsigned int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_89 ;
for ( V_89 = 0 ; V_89 < V_2 -> V_5 . V_17 ; V_89 ++ ) {
struct V_6 * V_52 = F_24 ( & V_2 -> V_5 , V_89 ) ;
if ( ! V_52 -> V_90 )
continue;
for ( V_16 = 0 ; V_16 < V_52 -> V_53 ; V_16 ++ ) {
if ( V_52 -> V_52 [ V_16 ] == V_50 ) {
if ( V_61 == V_83 || V_52 -> V_58 [ V_16 ] == V_58 )
return true ;
break;
}
}
}
return false ;
}
static int F_57 ( struct V_18 * V_19 , T_1 V_50 ,
int V_61 , unsigned int V_86 , bool V_91 )
{
unsigned int V_20 = 0 ;
if ( V_86 & V_92 ) {
if ( V_91 )
V_20 = ( V_86 & V_93 ) >> V_94 ;
}
if ( V_86 & ( V_95 | V_96 ) ) {
if ( ! V_91 )
V_20 |= V_97 ;
}
return V_20 ;
}
static void F_58 ( struct V_18 * V_19 , T_1 V_50 , int V_61 , int V_58 )
{
unsigned int V_86 = F_48 ( V_19 , V_50 , V_61 ) ;
int V_20 = F_57 ( V_19 , V_50 , V_61 , V_86 , false ) ;
F_59 ( V_19 , V_50 , V_61 , V_58 , 0xff , V_20 ) ;
}
static unsigned int F_60 ( struct V_18 * V_19 ,
T_1 V_50 , int V_61 , int V_58 ,
unsigned int V_86 )
{
unsigned int V_98 = 0xff ;
if ( V_86 & ( V_95 | V_96 ) ) {
if ( F_32 ( V_19 , V_50 , V_61 , V_58 , V_99 ) )
V_98 &= ~ 0x80 ;
}
if ( V_86 & V_92 ) {
if ( F_32 ( V_19 , V_50 , V_61 , V_58 , V_100 ) ||
F_32 ( V_19 , V_50 , V_61 , V_58 , V_101 ) )
V_98 &= ~ 0x7f ;
}
return V_98 ;
}
static void F_61 ( struct V_18 * V_19 , T_1 V_50 , int V_61 ,
int V_58 , int V_102 , bool V_91 )
{
unsigned int V_86 ;
unsigned int V_98 , V_20 ;
if ( ! V_91 && F_56 ( V_19 , V_50 , V_61 , V_102 ) )
return;
V_86 = F_48 ( V_19 , V_50 , V_61 ) ;
V_20 = F_57 ( V_19 , V_50 , V_61 , V_86 , V_91 ) ;
V_98 = F_60 ( V_19 , V_50 , V_61 , V_102 , V_86 ) ;
if ( ! V_98 )
return;
V_20 &= V_98 ;
F_62 ( V_19 , V_50 , V_61 , V_58 , V_98 , V_20 ) ;
}
static void F_63 ( struct V_18 * V_19 , struct V_6 * V_52 ,
int V_16 , bool V_91 )
{
T_1 V_50 = V_52 -> V_52 [ V_16 ] ;
F_58 ( V_19 , V_50 , V_83 , 0 ) ;
F_61 ( V_19 , V_50 , V_83 , 0 , 0 , V_91 ) ;
}
static void F_64 ( struct V_18 * V_19 , struct V_6 * V_52 ,
int V_16 , bool V_91 , bool V_103 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const T_1 * V_65 ;
int V_89 , V_51 , V_58 ;
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
for ( V_89 = 0 ; V_89 < V_51 ; V_89 ++ )
F_58 ( V_19 , V_50 , V_84 , V_89 ) ;
for ( V_89 = 0 ; V_89 < V_51 ; V_89 ++ ) {
if ( V_89 != V_58 && ( ! V_103 || V_65 [ V_89 ] != V_2 -> V_104 ) )
continue;
F_61 ( V_19 , V_50 , V_84 , V_89 , V_58 , V_91 ) ;
}
}
void F_65 ( struct V_18 * V_19 , struct V_6 * V_52 ,
bool V_91 , bool V_103 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
if ( ! V_91 )
V_52 -> V_90 = false ;
for ( V_16 = V_52 -> V_53 - 1 ; V_16 >= 0 ; V_16 -- ) {
T_1 V_50 = V_52 -> V_52 [ V_16 ] ;
if ( V_91 && V_2 -> V_42 ) {
if ( ! F_66 ( V_19 , V_50 , V_105 ) )
F_67 ( V_19 , V_50 , 0 ,
V_106 ,
V_105 ) ;
}
if ( V_91 && V_52 -> V_72 [ V_16 ] )
F_68 ( V_19 , V_50 , 0 ,
V_107 ,
V_52 -> V_58 [ V_16 ] ) ;
if ( F_54 ( V_19 , V_52 , V_16 ) )
F_64 ( V_19 , V_52 , V_16 , V_91 , V_103 ) ;
if ( F_55 ( V_19 , V_52 , V_16 ) )
F_63 ( V_19 , V_52 , V_16 , V_91 ) ;
}
if ( V_91 )
V_52 -> V_90 = true ;
}
static void F_69 ( struct V_18 * V_19 , struct V_6 * V_52 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_108 = false ;
int V_16 ;
if ( ! V_2 -> V_42 || V_52 -> V_90 )
return;
for ( V_16 = 0 ; V_16 < V_52 -> V_53 ; V_16 ++ ) {
T_1 V_50 = V_52 -> V_52 [ V_16 ] ;
if ( ! F_66 ( V_19 , V_50 , V_109 ) &&
! F_70 ( V_19 , V_50 ) ) {
F_67 ( V_19 , V_50 , 0 ,
V_106 ,
V_109 ) ;
V_108 = true ;
}
}
if ( V_108 ) {
F_71 ( 10 ) ;
F_72 ( V_19 , V_52 -> V_52 [ 0 ] , 0 ,
V_110 , 0 ) ;
}
}
static void F_73 ( struct V_18 * V_19 , T_1 V_46 , bool V_91 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_111 ||
! ( F_74 ( V_19 , V_46 ) & V_112 ) )
return;
if ( V_2 -> V_113 && ! V_91 )
return;
if ( V_19 -> V_24 )
V_91 = ! V_91 ;
F_75 ( V_19 , V_46 , 0 ,
V_114 ,
V_91 ? 0x02 : 0x00 ) ;
}
static void F_76 ( struct V_18 * V_19 , int V_115 )
{
struct V_6 * V_52 = F_27 ( V_19 , V_115 ) ;
if ( V_52 )
F_65 ( V_19 , V_52 , V_52 -> V_90 , false ) ;
}
static struct V_4 *
F_77 ( struct V_1 * V_2 , int type , const char * V_10 ,
int V_116 , unsigned long V_20 )
{
struct V_4 * V_12 ;
V_12 = F_4 ( V_2 , V_10 , & V_117 [ type ] ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_118 = V_116 ;
if ( F_78 ( V_20 ) )
V_12 -> V_119 = V_120 ;
V_12 -> V_121 = V_20 ;
return V_12 ;
}
static int F_79 ( struct V_1 * V_2 , int type ,
const char * V_62 , const char * V_61 ,
const char * V_122 , int V_116 , unsigned long V_20 )
{
char V_10 [ V_123 ] ;
snprintf ( V_10 , sizeof( V_10 ) , L_30 , V_62 , V_61 , V_122 ) ;
if ( ! F_77 ( V_2 , type , V_10 , V_116 , V_20 ) )
return - V_124 ;
return 0 ;
}
static int F_80 ( struct V_18 * V_19 , const char * V_62 , int V_116 ,
unsigned int V_79 , struct V_6 * V_52 )
{
unsigned int V_20 ;
if ( ! V_52 )
return 0 ;
V_20 = V_52 -> V_60 [ V_100 ] ;
if ( ! V_20 )
return 0 ;
V_20 = F_46 ( V_20 , V_79 ) ;
return F_81 ( V_19 -> V_2 , V_125 , V_62 , V_116 , V_20 ) ;
}
static int F_82 ( struct V_18 * V_19 , struct V_6 * V_52 ,
int type )
{
int V_79 = 1 ;
if ( V_52 ) {
T_1 V_50 = F_78 ( V_52 -> V_60 [ type ] ) ;
if ( V_50 && ( F_40 ( V_19 , V_50 ) & V_126 ) )
V_79 = 3 ;
}
return V_79 ;
}
static int F_83 ( struct V_18 * V_19 , const char * V_62 , int V_116 ,
struct V_6 * V_52 )
{
int V_79 = F_82 ( V_19 , V_52 , V_100 ) ;
return F_80 ( V_19 , V_62 , V_116 , V_79 , V_52 ) ;
}
static int F_84 ( struct V_18 * V_19 , const char * V_62 , int V_116 ,
unsigned int V_79 , struct V_6 * V_52 )
{
unsigned int V_20 ;
int type = V_127 ;
if ( ! V_52 )
return 0 ;
V_20 = V_52 -> V_60 [ V_99 ] ;
if ( ! V_20 )
return 0 ;
V_20 = F_46 ( V_20 , V_79 ) ;
if ( F_85 ( V_20 ) == V_84 ) {
T_1 V_50 = F_78 ( V_20 ) ;
int V_51 = F_86 ( V_19 , V_50 ) ;
if ( V_51 > 1 ) {
type = V_128 ;
V_20 |= V_51 << 19 ;
}
}
return F_87 ( V_19 -> V_2 , type , V_62 , V_116 , V_20 ) ;
}
static int F_88 ( struct V_18 * V_19 , const char * V_62 ,
int V_116 , struct V_6 * V_52 )
{
int V_79 = F_82 ( V_19 , V_52 , V_99 ) ;
return F_84 ( V_19 , V_62 , V_116 , V_79 , V_52 ) ;
}
static void F_89 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_33 ) {
T_1 V_50 = F_91 ( V_130 ) ;
bool V_133 = ! ( ( V_2 -> V_134 >> V_50 ) & 1 ) ;
V_132 -> V_135 . integer . V_135 [ 0 ] &= V_133 ;
V_132 -> V_135 . integer . V_135 [ 1 ] &= V_133 ;
}
}
static int F_92 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
F_89 ( V_130 , V_132 ) ;
return F_93 ( V_130 , V_132 ) ;
}
static int F_94 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
F_89 ( V_130 , V_132 ) ;
return F_95 ( V_130 , V_132 ) ;
}
static bool F_96 ( struct V_18 * V_19 , int V_115 , int V_136 )
{
struct V_6 * V_52 = F_27 ( V_19 , V_115 ) ;
return V_52 && V_52 -> V_60 [ V_136 ] ;
}
static const char * F_97 ( struct V_18 * V_19 , int V_137 ,
int * V_118 , int V_136 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
* V_118 = 0 ;
if ( V_139 -> V_141 == 1 && ! V_2 -> V_142 &&
! V_139 -> V_143 && ! V_139 -> V_144 )
return V_2 -> V_145 . V_146 ? L_31 : L_32 ;
if ( V_2 -> V_147 . V_148 == 1 && ! V_2 -> V_45 &&
! V_2 -> V_147 . V_149 [ 0 ] && ! V_2 -> V_147 . V_150 [ 0 ] )
return V_2 -> V_145 . V_146 ? L_31 : L_32 ;
if ( V_137 >= V_139 -> V_141 )
return V_151 [ V_137 ] ;
switch ( V_139 -> V_152 ) {
case V_153 :
if ( ! V_137 && V_139 -> V_143 &&
! F_96 ( V_19 , V_2 -> V_154 [ 0 ] , V_136 ) )
break;
if ( V_139 -> V_141 == 1 )
return L_33 ;
if ( V_139 -> V_141 == 2 )
return V_137 ? L_34 : L_33 ;
break;
case V_155 :
if ( ! V_137 && V_139 -> V_144 &&
! F_96 ( V_19 , V_2 -> V_156 [ 0 ] , V_136 ) )
break;
if ( V_137 && V_2 -> V_142 )
break;
* V_118 = V_137 ;
return L_35 ;
}
if ( V_139 -> V_141 == 1 && ! V_2 -> V_142 )
return L_31 ;
if ( V_137 >= F_98 ( V_151 ) ) {
F_99 () ;
return L_31 ;
}
return V_151 [ V_137 ] ;
}
static int F_100 ( struct V_18 * V_19 , struct V_6 * V_52 )
{
T_1 V_50 ;
unsigned int V_20 ;
int V_157 = 0 ;
if ( ! V_52 )
return V_158 * 2 ;
if ( V_52 -> V_60 [ V_100 ] ||
V_52 -> V_60 [ V_99 ] )
return 0 ;
V_50 = F_52 ( V_19 , V_52 ) ;
if ( V_50 ) {
V_20 = F_33 ( V_50 , 3 , 0 , V_83 ) ;
if ( F_31 ( V_19 , V_20 , V_100 ) )
V_157 += V_158 ;
else
V_52 -> V_60 [ V_100 ] = V_20 ;
} else
V_157 += V_158 ;
V_50 = F_50 ( V_19 , V_52 ) ;
if ( V_50 ) {
unsigned int V_159 = F_39 ( F_40 ( V_19 , V_50 ) ) ;
if ( V_159 == V_70 || V_159 == V_66 ||
F_51 ( V_19 , V_50 , V_83 ) )
V_20 = F_33 ( V_50 , 3 , 0 , V_83 ) ;
else
V_20 = F_33 ( V_50 , 3 , 0 , V_84 ) ;
if ( F_31 ( V_19 , V_20 , V_99 ) )
V_157 += V_158 ;
else
V_52 -> V_60 [ V_99 ] = V_20 ;
} else
V_157 += V_158 ;
return V_157 ;
}
static T_1 F_101 ( struct V_18 * V_19 , int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
if ( V_139 -> V_141 > V_58 )
return V_2 -> V_160 [ V_58 ] ;
V_58 -= V_139 -> V_141 ;
if ( V_2 -> V_142 > V_58 )
return V_2 -> V_161 [ V_58 ] . V_162 ;
return 0 ;
}
static inline T_1 F_102 ( struct V_18 * V_19 ,
T_1 V_162 , T_1 V_46 )
{
return F_29 ( V_19 , V_162 , V_46 ) ? V_162 : 0 ;
}
static int F_103 ( struct V_18 * V_19 , int V_163 ,
const T_1 * V_49 , T_1 * V_164 ,
int * V_115 ,
const struct V_165 * V_166 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_167 ;
int V_157 = 0 ;
T_1 V_162 ;
if ( ! V_163 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_163 ; V_16 ++ ) {
struct V_6 * V_52 ;
T_1 V_46 = V_49 [ V_16 ] ;
V_52 = F_27 ( V_19 , V_115 [ V_16 ] ) ;
if ( V_52 ) {
V_157 += F_100 ( V_19 , V_52 ) ;
continue;
}
V_164 [ V_16 ] = F_44 ( V_19 , V_46 ) ;
if ( V_164 [ V_16 ] ) {
if ( F_28 ( V_19 , V_164 [ V_16 ] ) )
V_157 += V_166 -> V_168 ;
}
if ( ! V_164 [ V_16 ] )
V_164 [ V_16 ] = F_45 ( V_19 , V_46 , false ) ;
if ( ! V_164 [ V_16 ] && ! V_16 ) {
for ( V_167 = 1 ; V_167 < V_163 ; V_167 ++ ) {
if ( F_29 ( V_19 , V_164 [ V_167 ] , V_46 ) ) {
V_164 [ 0 ] = V_164 [ V_167 ] ;
V_164 [ V_167 ] = 0 ;
F_43 ( V_19 , V_115 [ V_167 ] ) ;
V_115 [ V_167 ] = 0 ;
break;
}
}
}
V_162 = V_164 [ V_16 ] ;
if ( ! V_162 ) {
if ( V_163 > 2 )
V_162 = F_102 ( V_19 , F_101 ( V_19 , V_16 ) , V_46 ) ;
if ( ! V_162 )
V_162 = F_102 ( V_19 , V_164 [ 0 ] , V_46 ) ;
if ( ! V_162 )
V_162 = F_102 ( V_19 , F_101 ( V_19 , V_16 ) , V_46 ) ;
if ( V_162 ) {
if ( ! V_16 )
V_157 += V_166 -> V_168 ;
else if ( V_16 == 1 )
V_157 += V_166 -> V_169 ;
else
V_157 += V_166 -> V_170 ;
} else if ( F_29 ( V_19 , V_2 -> V_160 [ 0 ] , V_46 ) ) {
V_162 = V_2 -> V_160 [ 0 ] ;
V_157 += V_166 -> V_171 ;
} else if ( ! V_16 )
V_157 += V_166 -> V_172 ;
else
V_157 += V_166 -> V_173 ;
}
if ( ! V_162 )
continue;
V_52 = F_42 ( V_19 , V_162 , V_46 , - V_2 -> V_45 ) ;
if ( ! V_52 && ! V_16 && V_2 -> V_45 ) {
V_52 = F_42 ( V_19 , V_162 , V_46 , 0 ) ;
}
if ( ! V_52 ) {
V_162 = V_164 [ V_16 ] = 0 ;
V_157 += V_166 -> V_173 ;
} else {
V_52 -> V_90 = true ;
V_115 [ V_16 ] = F_26 ( V_19 , V_52 ) ;
V_157 += F_100 ( V_19 , V_52 ) ;
}
}
return V_157 ;
}
static T_1 F_104 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_174 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_76 ; V_16 ++ ) {
T_1 V_50 = V_2 -> V_77 [ V_16 ] ;
if ( ! V_50 || F_28 ( V_19 , V_50 ) )
continue;
if ( F_29 ( V_19 , V_50 , V_46 ) ) {
if ( V_174 )
return 0 ;
V_174 = V_50 ;
}
}
return V_174 ;
}
static bool F_105 ( struct V_18 * V_19 ,
unsigned int V_175 , T_1 V_50 )
{
unsigned int V_176 , V_86 ;
V_176 = F_106 ( V_19 , V_50 ) ;
if ( F_107 ( V_176 ) != V_177 )
return false ;
if ( V_175 && F_108 ( V_176 ) != V_175 )
return false ;
V_86 = F_74 ( V_19 , V_50 ) ;
if ( ! ( V_86 & V_178 ) )
return false ;
return true ;
}
static int F_109 ( struct V_18 * V_19 , T_1 V_179 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
unsigned int V_176 = F_106 ( V_19 , V_179 ) ;
unsigned int V_175 = F_108 ( V_176 ) ;
int type , V_16 ;
int V_48 = 0 ;
for ( type = V_180 ; type >= V_181 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_139 -> V_182 ; V_16 ++ ) {
if ( V_139 -> V_183 [ V_16 ] . type != type )
continue;
if ( F_105 ( V_19 , V_175 ,
V_139 -> V_183 [ V_16 ] . V_46 ) )
V_48 ++ ;
}
}
return V_48 ;
}
static int F_110 ( struct V_18 * V_19 ,
T_1 V_179 ,
bool V_184 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
int type , V_16 , V_167 , V_48 , V_185 ;
unsigned int V_176 = F_106 ( V_19 , V_179 ) ;
unsigned int V_175 = F_108 ( V_176 ) ;
int V_157 = 0 ;
struct V_6 * V_52 ;
V_185 = V_2 -> V_142 ;
if ( V_185 >= 2 )
goto V_186;
V_48 = F_109 ( V_19 , V_179 ) ;
if ( V_48 < 2 )
goto V_186;
for ( type = V_180 ; type >= V_181 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_139 -> V_182 ; V_16 ++ ) {
T_1 V_50 = V_139 -> V_183 [ V_16 ] . V_46 ;
T_1 V_162 = 0 ;
if ( V_139 -> V_183 [ V_16 ] . type != type )
continue;
if ( ! F_105 ( V_19 , V_175 , V_50 ) )
continue;
for ( V_167 = 0 ; V_167 < V_2 -> V_142 ; V_167 ++ ) {
if ( V_50 == V_2 -> V_161 [ V_167 ] . V_46 )
break;
}
if ( V_167 < V_2 -> V_142 )
continue;
if ( V_184 )
V_162 = F_104 ( V_19 , V_50 ) ;
else if ( ! V_162 )
V_162 = F_45 ( V_19 , V_50 , false ) ;
if ( ! V_162 ) {
V_157 ++ ;
continue;
}
V_52 = F_42 ( V_19 , V_162 , V_50 ,
- V_2 -> V_45 ) ;
if ( ! V_52 ) {
V_157 ++ ;
continue;
}
V_2 -> V_161 [ V_2 -> V_142 ] . V_46 = V_50 ;
V_2 -> V_161 [ V_2 -> V_142 ] . V_162 = V_162 ;
V_2 -> V_187 [ V_139 -> V_141 + V_2 -> V_142 ] =
F_26 ( V_19 , V_52 ) ;
V_2 -> V_142 ++ ;
if ( V_2 -> V_142 >= 2 )
break;
}
}
V_186:
if ( V_157 )
V_157 = V_188 ;
if ( V_185 == V_2 -> V_142 ) {
if ( V_184 )
return 1 ;
else
return V_157 ;
}
if ( ! V_184 && V_2 -> V_142 < 2 ) {
V_2 -> V_5 . V_17 -= V_2 -> V_142 - V_185 ;
V_2 -> V_142 = V_185 ;
return V_157 ;
}
for ( V_16 = V_185 ; V_16 < V_2 -> V_142 ; V_16 ++ ) {
V_52 = F_27 ( V_19 , V_2 -> V_187 [ V_139 -> V_141 + V_16 ] ) ;
V_157 += F_100 ( V_19 , V_52 ) ;
}
return V_157 ;
}
static bool F_111 ( struct V_18 * V_19 , int V_189 ,
const T_1 * V_49 , T_1 * V_164 , int * V_115 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
bool V_67 = false ;
for ( V_16 = 0 ; V_16 < V_189 ; V_16 ++ ) {
struct V_6 * V_52 ;
T_1 V_162 ;
if ( V_164 [ V_16 ] )
continue;
V_162 = F_104 ( V_19 , V_49 [ V_16 ] ) ;
if ( ! V_162 )
continue;
V_52 = F_42 ( V_19 , V_162 , V_49 [ V_16 ] ,
- V_2 -> V_45 ) ;
if ( ! V_52 && ! V_16 && V_2 -> V_45 )
V_52 = F_42 ( V_19 , V_162 , V_49 [ V_16 ] , 0 ) ;
if ( V_52 ) {
V_164 [ V_16 ] = V_162 ;
V_67 = true ;
V_52 -> V_90 = true ;
V_115 [ V_16 ] = F_26 ( V_19 , V_52 ) ;
}
}
return V_67 ;
}
static int F_112 ( struct V_18 * V_19 , int V_115 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_52 ;
T_1 V_190 , V_162 , V_46 ;
V_52 = F_27 ( V_19 , V_115 ) ;
if ( ! V_52 || ! V_52 -> V_53 ||
F_22 ( V_52 , V_2 -> V_45 ) )
return 0 ;
V_190 = V_52 -> V_52 [ 0 ] ;
V_162 = V_2 -> V_160 [ 0 ] ;
V_46 = V_52 -> V_52 [ V_52 -> V_53 - 1 ] ;
V_52 = F_42 ( V_19 , V_162 , V_46 , V_2 -> V_45 ) ;
if ( ! V_52 ) {
if ( V_162 != V_190 )
V_162 = V_190 ;
else if ( V_2 -> V_147 . V_149 [ 0 ] )
V_162 = V_2 -> V_147 . V_149 [ 0 ] ;
else if ( V_2 -> V_147 . V_150 [ 0 ] )
V_162 = V_2 -> V_147 . V_150 [ 0 ] ;
else
V_162 = 0 ;
if ( V_162 )
V_52 = F_42 ( V_19 , V_162 , V_46 ,
V_2 -> V_45 ) ;
}
if ( ! V_52 )
return 0 ;
V_52 -> V_90 = false ;
return F_26 ( V_19 , V_52 ) ;
}
static bool F_113 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
struct V_6 * V_52 ;
int V_16 , V_58 ;
if ( V_139 -> V_152 == V_155 )
V_58 = V_2 -> V_187 [ 0 ] ;
else
V_58 = V_2 -> V_154 [ 0 ] ;
V_52 = F_27 ( V_19 , V_58 ) ;
if ( ! V_52 )
return false ;
if ( ! V_2 -> V_45 || ! F_22 ( V_52 , V_2 -> V_45 ) )
return true ;
for ( V_16 = 0 ; V_16 < V_139 -> V_141 ; V_16 ++ ) {
if ( V_2 -> V_187 [ V_16 ] == V_58 )
break;
V_52 = F_27 ( V_19 , V_2 -> V_187 [ V_16 ] ) ;
if ( V_52 && F_22 ( V_52 , V_2 -> V_45 ) )
return false ;
}
for ( V_16 = 0 ; V_16 < V_139 -> V_144 ; V_16 ++ ) {
V_52 = F_27 ( V_19 , V_2 -> V_156 [ V_16 ] ) ;
if ( V_52 && F_22 ( V_52 , V_2 -> V_45 ) )
return false ;
}
return true ;
}
static void F_114 ( struct V_18 * V_19 , int V_163 ,
T_1 * V_164 , int * V_115 )
{
struct V_6 * V_52 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_163 ; V_16 ++ ) {
if ( V_164 [ V_16 ] )
continue;
V_52 = F_27 ( V_19 , V_115 [ V_16 ] ) ;
if ( ! V_52 )
continue;
V_164 [ V_16 ] = V_52 -> V_52 [ 0 ] ;
}
}
static int F_115 ( struct V_18 * V_19 ,
bool V_191 ,
bool V_192 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
int V_16 , V_193 , V_157 ;
V_2 -> V_147 . V_148 = V_139 -> V_141 ;
V_2 -> V_147 . V_194 = V_2 -> V_160 ;
memset ( V_2 -> V_160 , 0 , sizeof( V_2 -> V_160 ) ) ;
memset ( V_2 -> V_147 . V_149 , 0 , sizeof( V_2 -> V_147 . V_149 ) ) ;
memset ( V_2 -> V_147 . V_150 , 0 , sizeof( V_2 -> V_147 . V_150 ) ) ;
V_2 -> V_142 = 0 ;
F_9 ( & V_2 -> V_5 ) ;
memset ( V_2 -> V_187 , 0 , sizeof( V_2 -> V_187 ) ) ;
memset ( V_2 -> V_154 , 0 , sizeof( V_2 -> V_154 ) ) ;
memset ( V_2 -> V_156 , 0 , sizeof( V_2 -> V_156 ) ) ;
memset ( V_2 -> V_195 , 0 , sizeof( V_2 -> V_195 ) ) ;
memset ( V_2 -> V_196 , 0 , sizeof( V_2 -> V_196 ) ) ;
memset ( V_2 -> V_197 , 0 , sizeof( V_2 -> V_197 ) ) ;
memset ( V_2 -> V_198 , 0 , sizeof( V_2 -> V_198 ) ) ;
memset ( & V_2 -> V_199 , 0 , sizeof( V_2 -> V_199 ) ) ;
V_157 = 0 ;
if ( V_191 ) {
bool V_200 ;
do {
V_200 = F_111 ( V_19 , V_139 -> V_141 ,
V_139 -> V_201 ,
V_2 -> V_160 ,
V_2 -> V_187 ) ;
V_200 |= F_111 ( V_19 , V_139 -> V_143 ,
V_139 -> V_202 ,
V_2 -> V_147 . V_149 ,
V_2 -> V_154 ) ;
V_200 |= F_111 ( V_19 , V_139 -> V_144 ,
V_139 -> V_203 ,
V_2 -> V_147 . V_150 ,
V_2 -> V_156 ) ;
if ( ! V_2 -> V_36 &&
V_192 && V_139 -> V_141 == 1 &&
V_139 -> V_152 != V_153 ) {
V_193 = F_110 ( V_19 , V_139 -> V_201 [ 0 ] , true ) ;
if ( ! V_193 )
V_200 = true ;
}
} while ( V_200 );
}
V_157 += F_103 ( V_19 , V_139 -> V_141 , V_139 -> V_201 ,
V_2 -> V_160 , V_2 -> V_187 ,
V_2 -> V_204 ) ;
if ( ! V_2 -> V_36 && V_192 &&
V_139 -> V_141 == 1 && V_139 -> V_152 != V_153 ) {
V_193 = F_110 ( V_19 , V_139 -> V_201 [ 0 ] , false ) ;
if ( V_193 < 0 )
return V_193 ;
}
if ( V_139 -> V_152 != V_155 ) {
V_193 = F_103 ( V_19 , V_139 -> V_143 , V_139 -> V_202 ,
V_2 -> V_147 . V_149 ,
V_2 -> V_154 ,
V_2 -> V_205 ) ;
if ( V_193 < 0 )
return V_193 ;
V_157 += V_193 ;
}
if ( V_139 -> V_152 != V_153 ) {
V_193 = F_103 ( V_19 , V_139 -> V_144 ,
V_139 -> V_203 ,
V_2 -> V_147 . V_150 ,
V_2 -> V_156 ,
V_2 -> V_205 ) ;
if ( V_193 < 0 )
return V_193 ;
V_157 += V_193 ;
}
if ( ! V_2 -> V_36 &&
V_139 -> V_141 == 1 && V_139 -> V_152 != V_153 ) {
V_193 = F_110 ( V_19 , V_139 -> V_201 [ 0 ] , false ) ;
if ( V_193 < 0 )
return V_193 ;
V_157 += V_193 ;
}
if ( V_2 -> V_45 ) {
V_2 -> V_195 [ 0 ] =
F_112 ( V_19 , V_2 -> V_187 [ 0 ] ) ;
if ( V_139 -> V_152 != V_155 )
V_2 -> V_195 [ 1 ] =
F_112 ( V_19 , V_2 -> V_154 [ 0 ] ) ;
if ( V_139 -> V_152 != V_153 )
V_2 -> V_195 [ 2 ] =
F_112 ( V_19 , V_2 -> V_156 [ 0 ] ) ;
}
if ( ! V_2 -> V_36 &&
V_139 -> V_143 && V_139 -> V_152 == V_153 )
if ( F_109 ( V_19 , V_139 -> V_202 [ 0 ] ) >= 2 )
V_2 -> V_142 = 1 ;
V_2 -> V_147 . V_148 = 0 ;
for ( V_16 = 0 ; V_16 < V_139 -> V_141 ; V_16 ++ ) {
if ( V_2 -> V_160 [ V_16 ] )
V_2 -> V_147 . V_148 ++ ;
else {
memmove ( V_2 -> V_160 + V_16 ,
V_2 -> V_160 + V_16 + 1 ,
sizeof( T_1 ) * ( V_139 -> V_141 - V_16 - 1 ) ) ;
V_2 -> V_160 [ V_139 -> V_141 - 1 ] = 0 ;
}
}
V_2 -> V_206 = V_2 -> V_207 =
V_2 -> V_147 . V_148 * 2 ;
if ( V_2 -> V_142 == 2 ) {
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
V_2 -> V_160 [ V_2 -> V_147 . V_148 ++ ] =
V_2 -> V_161 [ V_16 ] . V_162 ;
} else if ( V_2 -> V_142 ) {
V_2 -> V_142 = 0 ;
V_157 += V_188 ;
}
if ( V_2 -> V_39 && ! F_113 ( V_19 ) )
V_157 += V_208 ;
if ( V_139 -> V_152 != V_155 )
F_114 ( V_19 , V_139 -> V_143 ,
V_2 -> V_147 . V_149 ,
V_2 -> V_154 ) ;
if ( V_139 -> V_152 != V_153 )
F_114 ( V_19 , V_139 -> V_144 ,
V_2 -> V_147 . V_150 ,
V_2 -> V_156 ) ;
return V_157 ;
}
static inline void F_116 ( struct V_18 * V_19 ,
const char * V_62 , int V_58 )
{
struct V_6 * V_52 ;
V_52 = F_27 ( V_19 , V_58 ) ;
if ( V_52 )
F_34 ( V_62 , V_52 ) ;
}
static void F_117 ( struct V_18 * V_19 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_209 [ 3 ] = { L_36 , L_37 , L_38 } ;
int V_16 ;
F_118 ( L_39 ,
V_139 -> V_201 [ 0 ] , V_139 -> V_201 [ 1 ] ,
V_139 -> V_201 [ 2 ] , V_139 -> V_201 [ 3 ] ,
V_2 -> V_147 . V_194 [ 0 ] ,
V_2 -> V_147 . V_194 [ 1 ] ,
V_2 -> V_147 . V_194 [ 2 ] ,
V_2 -> V_147 . V_194 [ 3 ] ,
V_209 [ V_139 -> V_152 ] ) ;
for ( V_16 = 0 ; V_16 < V_139 -> V_141 ; V_16 ++ )
F_116 ( V_19 , L_40 , V_2 -> V_187 [ V_16 ] ) ;
if ( V_2 -> V_142 > 0 )
F_118 ( L_41 ,
V_2 -> V_142 ,
V_2 -> V_161 [ 0 ] . V_46 , V_2 -> V_161 [ 1 ] . V_46 ,
V_2 -> V_161 [ 0 ] . V_162 , V_2 -> V_161 [ 1 ] . V_162 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_142 ; V_16 ++ )
F_116 ( V_19 , L_42 ,
V_2 -> V_187 [ V_139 -> V_141 + V_16 ] ) ;
if ( V_139 -> V_143 )
F_118 ( L_43 ,
V_139 -> V_202 [ 0 ] , V_139 -> V_202 [ 1 ] ,
V_139 -> V_202 [ 2 ] , V_139 -> V_202 [ 3 ] ,
V_2 -> V_147 . V_149 [ 0 ] ,
V_2 -> V_147 . V_149 [ 1 ] ,
V_2 -> V_147 . V_149 [ 2 ] ,
V_2 -> V_147 . V_149 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_139 -> V_143 ; V_16 ++ )
F_116 ( V_19 , L_44 , V_2 -> V_154 [ V_16 ] ) ;
if ( V_139 -> V_144 )
F_118 ( L_45 ,
V_139 -> V_203 [ 0 ] , V_139 -> V_203 [ 1 ] ,
V_139 -> V_203 [ 2 ] , V_139 -> V_203 [ 3 ] ,
V_2 -> V_147 . V_150 [ 0 ] ,
V_2 -> V_147 . V_150 [ 1 ] ,
V_2 -> V_147 . V_150 [ 2 ] ,
V_2 -> V_147 . V_150 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_139 -> V_144 ; V_16 ++ )
F_116 ( V_19 , L_46 , V_2 -> V_156 [ V_16 ] ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ )
F_116 ( V_19 , L_47 , V_2 -> V_195 [ V_16 ] ) ;
}
static void F_119 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_50 = V_19 -> V_210 ;
V_2 -> V_76 = 0 ;
memset ( V_2 -> V_77 , 0 , sizeof( V_2 -> V_77 ) ) ;
for ( V_16 = 0 ; V_16 < V_19 -> V_211 ; V_16 ++ , V_50 ++ ) {
if ( F_39 ( F_40 ( V_19 , V_50 ) ) != V_66 )
continue;
if ( V_2 -> V_76 >= F_98 ( V_2 -> V_77 ) ) {
F_120 ( V_212 L_48 ) ;
break;
}
V_2 -> V_77 [ V_2 -> V_76 ++ ] = V_50 ;
}
}
static int F_121 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
struct V_138 * V_213 ;
unsigned int V_20 ;
int V_214 = V_215 ;
int V_157 ;
bool V_191 = true , V_192 = true ;
bool V_216 = true , V_217 = true ;
bool V_218 = false ;
V_213 = F_122 ( sizeof( * V_213 ) , V_13 ) ;
if ( ! V_213 )
return - V_124 ;
* V_213 = * V_139 ;
for (; ; ) {
V_157 = F_115 ( V_19 , V_191 ,
V_192 ) ;
if ( V_157 < 0 ) {
F_8 ( V_213 ) ;
return V_157 ;
}
F_118 ( L_49 ,
V_139 -> V_152 , V_191 , V_192 ,
V_157 ) ;
F_117 ( V_19 , V_139 ) ;
if ( V_157 < V_214 ) {
V_214 = V_157 ;
* V_213 = * V_139 ;
V_216 = V_191 ;
V_217 = V_192 ;
}
if ( ! V_157 )
break;
V_192 = ! V_192 ;
if ( ! V_192 )
continue;
V_191 = ! V_191 ;
if ( ! V_191 )
continue;
if ( V_218 )
break;
V_218 = true ;
if ( V_139 -> V_144 > 0 &&
V_139 -> V_152 == V_155 ) {
V_139 -> V_143 = V_139 -> V_141 ;
memcpy ( V_139 -> V_202 , V_139 -> V_201 ,
sizeof( V_139 -> V_202 ) ) ;
V_139 -> V_141 = V_139 -> V_144 ;
memcpy ( V_139 -> V_201 , V_139 -> V_203 ,
sizeof( V_139 -> V_203 ) ) ;
V_139 -> V_144 = 0 ;
memset ( V_139 -> V_203 , 0 , sizeof( V_139 -> V_203 ) ) ;
V_139 -> V_152 = V_153 ;
V_191 = true ;
continue;
}
if ( V_139 -> V_143 > 0 &&
V_139 -> V_152 == V_153 ) {
V_139 -> V_144 = V_139 -> V_141 ;
memcpy ( V_139 -> V_203 , V_139 -> V_201 ,
sizeof( V_139 -> V_203 ) ) ;
V_139 -> V_141 = V_139 -> V_143 ;
memcpy ( V_139 -> V_201 , V_139 -> V_202 ,
sizeof( V_139 -> V_202 ) ) ;
V_139 -> V_143 = 0 ;
memset ( V_139 -> V_202 , 0 , sizeof( V_139 -> V_202 ) ) ;
V_139 -> V_152 = V_155 ;
V_191 = true ;
continue;
}
break;
}
if ( V_157 ) {
F_118 ( L_50 ) ;
* V_139 = * V_213 ;
F_115 ( V_19 , V_216 , V_217 ) ;
}
F_118 ( L_51 ,
V_139 -> V_152 , V_216 , V_217 ) ;
F_117 ( V_19 , V_139 ) ;
if ( V_139 -> V_201 [ 0 ] ) {
struct V_6 * V_52 ;
V_52 = F_27 ( V_19 , V_2 -> V_187 [ 0 ] ) ;
if ( V_52 )
V_2 -> V_219 = F_52 ( V_19 , V_52 ) ;
if ( V_2 -> V_219 )
F_123 ( V_19 , V_2 -> V_219 ,
V_83 , V_2 -> V_220 ) ;
}
if ( V_2 -> V_221 || V_139 -> V_152 == V_155 )
V_20 = V_222 ;
else
V_20 = V_223 ;
F_20 ( V_19 , V_139 -> V_141 , V_139 -> V_201 , V_20 ) ;
if ( V_139 -> V_152 != V_155 )
F_20 ( V_19 , V_139 -> V_143 , V_139 -> V_202 , V_222 ) ;
if ( V_139 -> V_152 != V_153 ) {
V_20 = V_2 -> V_221 ? V_222 : V_223 ;
F_20 ( V_19 , V_139 -> V_144 ,
V_139 -> V_203 , V_20 ) ;
}
if ( V_2 -> V_39 && ! F_113 ( V_19 ) )
V_2 -> V_39 = 0 ;
F_8 ( V_213 ) ;
return 0 ;
}
static int F_124 ( struct V_18 * V_19 ,
const struct V_138 * V_139 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_193 , V_224 ;
V_224 = V_139 -> V_141 ;
if ( V_2 -> V_142 > 0 && V_139 -> V_141 < 3 )
V_224 += V_2 -> V_142 ;
for ( V_16 = 0 ; V_16 < V_224 ; V_16 ++ ) {
const char * V_10 ;
int V_118 ;
struct V_6 * V_52 ;
V_52 = F_27 ( V_19 , V_2 -> V_187 [ V_16 ] ) ;
if ( ! V_52 )
continue;
V_10 = F_97 ( V_19 , V_16 , & V_118 , V_100 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_52 ) ) {
V_193 = F_80 ( V_19 , L_53 , 0 , 1 , V_52 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_80 ( V_19 , L_54 , 0 , 2 , V_52 ) ;
if ( V_193 < 0 )
return V_193 ;
} else {
V_193 = F_83 ( V_19 , V_10 , V_118 , V_52 ) ;
if ( V_193 < 0 )
return V_193 ;
}
V_10 = F_97 ( V_19 , V_16 , & V_118 , V_99 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_52 ) ) {
V_193 = F_84 ( V_19 , L_53 , 0 , 1 , V_52 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_84 ( V_19 , L_54 , 0 , 2 , V_52 ) ;
if ( V_193 < 0 )
return V_193 ;
} else {
V_193 = F_88 ( V_19 , V_10 , V_118 , V_52 ) ;
if ( V_193 < 0 )
return V_193 ;
}
}
return 0 ;
}
static int F_125 ( struct V_18 * V_19 , int V_115 ,
const char * V_62 , int V_116 )
{
struct V_6 * V_52 ;
int V_193 ;
V_52 = F_27 ( V_19 , V_115 ) ;
if ( ! V_52 )
return 0 ;
V_193 = F_83 ( V_19 , V_62 , V_116 , V_52 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_88 ( V_19 , V_62 , V_116 , V_52 ) ;
if ( V_193 < 0 )
return V_193 ;
return 0 ;
}
static int F_126 ( struct V_18 * V_19 , int V_48 ,
const int * V_5 , const char * V_62 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
const char * V_10 ;
char V_64 [ V_123 ] ;
int V_193 , V_58 = 0 ;
if ( V_48 == 2 && V_16 == 1 && ! strcmp ( V_62 , L_33 ) )
V_10 = L_34 ;
else if ( V_48 >= 3 ) {
snprintf ( V_64 , sizeof( V_64 ) , L_55 ,
V_62 , V_151 [ V_16 ] ) ;
V_10 = V_64 ;
} else {
V_10 = V_62 ;
V_58 = V_16 ;
}
V_193 = F_125 ( V_19 , V_5 [ V_16 ] , V_10 , V_58 ) ;
if ( V_193 < 0 )
return V_193 ;
}
return 0 ;
}
static int F_127 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_126 ( V_19 , V_2 -> V_140 . V_143 ,
V_2 -> V_154 ,
L_35 ) ;
}
static int F_128 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_126 ( V_19 , V_2 -> V_140 . V_144 ,
V_2 -> V_156 ,
L_33 ) ;
}
static int F_129 ( struct V_129 * V_130 ,
struct V_225 * V_226 )
{
return F_130 ( V_130 , V_226 ) ;
}
static int F_131 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_132 -> V_135 . V_227 . V_228 [ 0 ] = V_2 -> V_229 ;
return 0 ;
}
static int F_132 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_230 = V_132 -> V_135 . V_227 . V_228 [ 0 ] ;
int V_231 = 0 ;
F_133 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_232 ) {
V_231 = - V_233 ;
goto V_234;
}
if ( V_2 -> V_229 != V_230 ) {
T_1 * V_235 ;
if ( V_2 -> V_140 . V_152 == V_155 )
V_235 = & V_2 -> V_160 [ 0 ] ;
else
V_235 = & V_2 -> V_147 . V_149 [ 0 ] ;
if ( V_2 -> V_236 ) {
if ( V_2 -> V_140 . V_152 == V_155 )
F_134 ( V_19 , V_2 -> V_237 ,
V_2 -> V_187 [ 0 ] ,
V_2 -> V_195 [ 0 ] ,
V_2 -> V_140 . V_152 ) ;
else
F_134 ( V_19 , V_2 -> V_237 ,
V_2 -> V_154 [ 0 ] ,
V_2 -> V_195 [ 1 ] ,
V_155 ) ;
}
V_2 -> V_229 = V_230 ;
if ( V_2 -> V_229 )
* V_235 = 0 ;
else
* V_235 = V_2 -> V_238 ;
F_135 ( V_19 , NULL ) ;
V_231 = 1 ;
}
V_234:
F_136 ( & V_2 -> V_9 ) ;
return V_231 ;
}
static int F_137 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_162 ;
if ( ! V_2 -> V_39 )
return 0 ;
if ( V_2 -> V_140 . V_152 == V_155 )
V_162 = V_2 -> V_147 . V_194 [ 0 ] ;
else
V_162 = V_2 -> V_147 . V_149 [ 0 ] ;
if ( ! V_162 ) {
V_2 -> V_39 = 0 ;
return 0 ;
}
V_2 -> V_229 = false ;
V_2 -> V_238 = V_162 ;
if ( ! F_4 ( V_2 , NULL , & V_239 ) )
return - V_124 ;
return 0 ;
}
static int F_138 ( struct V_129 * V_130 ,
struct V_225 * V_226 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_79 ;
V_226 -> type = V_240 ;
V_226 -> V_241 = 1 ;
V_226 -> V_135 . V_227 . V_242 = V_2 -> V_142 + 1 ;
if ( V_226 -> V_135 . V_227 . V_228 > V_2 -> V_142 )
V_226 -> V_135 . V_227 . V_228 = V_2 -> V_142 ;
V_79 = V_226 -> V_135 . V_227 . V_228 * 2 + V_2 -> V_207 ;
sprintf ( V_226 -> V_135 . V_227 . V_10 , L_56 , V_79 ) ;
return 0 ;
}
static int F_139 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_132 -> V_135 . V_227 . V_228 [ 0 ] =
( V_2 -> V_206 - V_2 -> V_207 ) / 2 ;
return 0 ;
}
static inline struct V_6 *
F_140 ( struct V_18 * V_19 , int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_27 ( V_19 ,
V_2 -> V_187 [ V_2 -> V_140 . V_141 + V_58 ] ) ;
}
static bool F_141 ( struct V_1 * V_2 )
{
return ! V_2 -> V_236 || V_2 -> V_237 ;
}
static int F_142 ( struct V_18 * V_19 , int V_58 , bool V_243 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_50 = V_2 -> V_161 [ V_58 ] . V_46 ;
struct V_6 * V_52 ;
V_52 = F_140 ( V_19 , V_58 ) ;
if ( ! V_52 )
return - V_244 ;
if ( V_52 -> V_90 == V_243 )
return 0 ;
if ( V_243 ) {
F_17 ( V_19 , V_50 , V_223 , true ) ;
F_65 ( V_19 , V_52 , true , F_141 ( V_2 ) ) ;
F_73 ( V_19 , V_50 , true ) ;
} else {
F_73 ( V_19 , V_50 , false ) ;
F_65 ( V_19 , V_52 , false , F_141 ( V_2 ) ) ;
F_17 ( V_19 , V_50 , V_2 -> V_161 [ V_58 ] . V_245 , true ) ;
F_69 ( V_19 , V_52 ) ;
}
F_143 ( V_19 ) ;
return 0 ;
}
static int F_144 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_137 ;
V_137 = V_132 -> V_135 . V_227 . V_228 [ 0 ] ;
if ( V_137 < 0 || V_137 > V_2 -> V_142 )
return - V_244 ;
if ( V_137 == ( V_2 -> V_206 - V_2 -> V_207 ) / 2 )
return 0 ;
V_2 -> V_206 = V_137 * 2 + V_2 -> V_207 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_142 ; V_16 ++ )
F_142 ( V_19 , V_16 , V_16 < V_137 ) ;
V_2 -> V_147 . V_246 = F_145 ( V_2 -> V_206 ,
V_2 -> V_247 ) ;
if ( V_2 -> V_34 )
V_2 -> V_147 . V_148 = V_2 -> V_147 . V_246 / 2 ;
return 1 ;
}
static int F_146 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_142 > 0 ) {
if ( ! F_4 ( V_2 , NULL , & V_248 ) )
return - V_124 ;
}
return 0 ;
}
static int F_147 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_132 -> V_135 . V_227 . V_228 [ 0 ] = V_2 -> V_237 ;
return 0 ;
}
static void F_134 ( struct V_18 * V_19 , bool V_249 ,
int V_250 , int V_251 ,
int V_252 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_253 , * V_254 ;
V_253 = F_27 ( V_19 , V_250 ) ;
V_254 = F_27 ( V_19 , V_251 ) ;
if ( ! V_253 || ! V_254 )
return;
if ( V_252 == V_155 && V_2 -> V_229 &&
V_254 -> V_52 [ 0 ] != V_2 -> V_238 )
V_249 = false ;
if ( V_249 ) {
F_65 ( V_19 , V_253 , false , true ) ;
F_65 ( V_19 , V_254 , true , true ) ;
F_69 ( V_19 , V_253 ) ;
} else {
F_65 ( V_19 , V_254 , false , false ) ;
F_65 ( V_19 , V_253 , true , false ) ;
F_69 ( V_19 , V_254 ) ;
}
}
static int F_148 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = V_132 -> V_135 . V_227 . V_228 [ 0 ] ;
if ( V_20 == V_2 -> V_237 )
return 0 ;
V_2 -> V_237 = V_20 ;
F_134 ( V_19 , V_20 , V_2 -> V_187 [ 0 ] ,
V_2 -> V_195 [ 0 ] ,
V_2 -> V_140 . V_152 ) ;
F_134 ( V_19 , V_20 , V_2 -> V_154 [ 0 ] ,
V_2 -> V_195 [ 1 ] ,
V_155 ) ;
F_134 ( V_19 , V_20 , V_2 -> V_156 [ 0 ] ,
V_2 -> V_195 [ 2 ] ,
V_153 ) ;
return 1 ;
}
static int F_149 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_45 )
return 0 ;
if ( ! ( V_2 -> V_195 [ 0 ] || V_2 -> V_195 [ 1 ] ||
V_2 -> V_195 [ 2 ] ) )
return 0 ;
if ( ! F_4 ( V_2 , NULL , & V_255 ) )
return - V_124 ;
V_2 -> V_236 = 1 ;
return 0 ;
}
static void F_150 ( struct V_18 * V_19 , int V_256 , bool V_257 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_258 ;
unsigned int V_20 ;
T_1 V_46 ;
V_46 = V_2 -> V_259 ;
V_258 = V_2 -> V_260 [ V_256 ] == V_2 -> V_261 ;
if ( ! V_257 ) {
V_20 = F_16 ( V_19 , V_46 ) ;
if ( V_258 ) {
if ( V_20 & V_262 )
return;
} else {
if ( V_20 & V_223 )
return;
}
}
V_20 = F_151 ( V_19 , V_46 ) ;
if ( V_20 == V_263 && V_2 -> V_264 ) {
const T_1 V_265 = V_2 -> V_264 ;
unsigned int V_266 = F_151 ( V_19 , V_265 ) ;
if ( V_266 != V_263 )
F_152 ( V_19 , V_265 ,
V_262 | ( V_258 ? V_266 : 0 ) ) ;
}
if ( ! V_2 -> V_267 ) {
if ( V_258 )
V_20 |= V_262 ;
else
V_20 = V_222 ;
F_17 ( V_19 , V_46 , V_20 , true ) ;
F_135 ( V_19 , NULL ) ;
}
}
static int F_153 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
unsigned int V_176 ;
T_1 V_50 ;
if ( ! V_2 -> V_43 ) {
if ( V_2 -> V_44 )
return 0 ;
if ( V_139 -> V_182 > 1 )
return 0 ;
else if ( V_139 -> V_182 == 1 ) {
V_176 = F_106 ( V_19 , V_139 -> V_183 [ 0 ] . V_46 ) ;
if ( F_154 ( V_176 ) != V_268 )
return 0 ;
}
}
V_2 -> V_43 = 0 ;
if ( V_139 -> V_182 >= V_269 )
return 0 ;
V_50 = 0 ;
if ( V_139 -> V_152 == V_155 && V_139 -> V_141 > 0 )
V_50 = V_139 -> V_201 [ 0 ] ;
else if ( V_139 -> V_143 > 0 )
V_50 = V_139 -> V_202 [ 0 ] ;
if ( ! V_50 )
return 0 ;
if ( ! ( F_74 ( V_19 , V_50 ) & V_270 ) )
return 0 ;
V_139 -> V_183 [ V_139 -> V_182 ] . V_46 = V_50 ;
V_139 -> V_183 [ V_139 -> V_182 ] . type = V_181 ;
V_139 -> V_183 [ V_139 -> V_182 ] . V_271 = 1 ;
V_139 -> V_182 ++ ;
V_2 -> V_43 = 1 ;
V_2 -> V_259 = V_50 ;
V_2 -> V_31 = 1 ;
F_36 ( L_57 , V_50 ) ;
return 0 ;
}
static int F_155 ( struct V_129 * V_130 ,
struct V_225 * V_226 )
{
return F_156 ( V_130 , V_226 , 2 , V_272 ) ;
}
static int F_157 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
T_1 V_50 = V_130 -> V_121 ;
if ( F_16 ( V_19 , V_50 ) == V_222 )
V_132 -> V_135 . V_227 . V_228 [ 0 ] = 1 ;
else
V_132 -> V_135 . V_227 . V_228 [ 0 ] = 0 ;
return 0 ;
}
static int F_158 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
T_1 V_50 = V_130 -> V_121 ;
unsigned int V_20 ;
V_20 = V_132 -> V_135 . V_227 . V_228 [ 0 ] ? V_222 : V_223 ;
if ( F_16 ( V_19 , V_50 ) == V_20 )
return 0 ;
F_152 ( V_19 , V_50 , V_20 ) ;
return 1 ;
}
static bool F_159 ( struct V_18 * V_19 , const char * V_10 , int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_3 . V_17 ; V_16 ++ ) {
struct V_4 * V_15 = F_24 ( & V_2 -> V_3 , V_16 ) ;
if ( ! strcmp ( V_15 -> V_10 , V_10 ) && V_15 -> V_118 == V_58 )
return true ;
}
return false ;
}
static void F_160 ( struct V_18 * V_19 , T_1 V_46 ,
char * V_10 , T_3 V_273 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_58 = 0 ;
F_161 ( V_19 , V_46 , & V_2 -> V_140 , V_10 , V_273 , & V_58 ) ;
F_35 ( V_10 , L_58 , V_273 ) ;
for (; F_159 ( V_19 , V_10 , V_58 ) ; V_58 ++ )
;
}
static int F_162 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_41 ) {
unsigned int V_274 = F_74 ( V_19 , V_46 ) ;
if ( ( V_274 & V_178 ) && ( V_274 & V_275 ) )
return 2 ;
}
return 1 ;
}
static int F_163 ( struct V_18 * V_19 , int V_48 ,
T_1 * V_49 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
T_1 V_46 = V_49 [ V_16 ] ;
if ( V_46 == V_2 -> V_259 )
continue;
if ( F_162 ( V_19 , V_46 ) > 1 ) {
struct V_4 * V_12 ;
char V_10 [ V_123 ] ;
F_160 ( V_19 , V_46 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 ,
& V_276 ) ;
if ( ! V_12 )
return - V_124 ;
V_12 -> V_121 = V_46 ;
}
}
return 0 ;
}
static unsigned int F_164 ( struct V_18 * V_19 , T_1 V_46 )
{
unsigned int V_274 ;
V_274 = F_74 ( V_19 , V_46 ) ;
V_274 = ( V_274 & V_277 ) >> V_278 ;
V_274 &= ~ ( V_279 | V_280 ) ;
return V_274 ;
}
static int F_165 ( unsigned int V_281 , unsigned int V_282 )
{
unsigned int V_16 , V_89 = 0 ;
for ( V_16 = 0 ; V_16 < V_283 ; V_16 ++ ) {
if ( V_281 & ( 1 << V_16 ) ) {
if ( V_89 == V_282 )
return V_16 ;
V_89 ++ ;
}
}
return 0 ;
}
static int F_166 ( unsigned int V_281 , unsigned int V_58 )
{
unsigned int V_16 , V_89 = 0 ;
for ( V_16 = 0 ; V_16 < V_283 ; V_16 ++ ) {
if ( V_16 == V_58 )
return V_89 ;
if ( V_281 & ( 1 << V_16 ) )
V_89 ++ ;
}
return 0 ;
}
static int F_167 ( struct V_129 * V_130 ,
struct V_225 * V_226 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
T_1 V_50 = V_130 -> V_121 ;
unsigned int V_281 = F_164 ( V_19 , V_50 ) ;
F_156 ( V_130 , V_226 , F_168 ( V_281 ) ,
V_284 ) ;
strcpy ( V_226 -> V_135 . V_227 . V_10 ,
V_284 [ F_165 ( V_281 , V_226 -> V_135 . V_227 . V_228 ) ] ) ;
return 0 ;
}
static int F_169 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
T_1 V_50 = V_130 -> V_121 ;
unsigned int V_281 = F_164 ( V_19 , V_50 ) ;
unsigned int V_58 ;
V_58 = F_16 ( V_19 , V_50 ) & V_285 ;
V_132 -> V_135 . V_227 . V_228 [ 0 ] = F_166 ( V_281 , V_58 ) ;
return 0 ;
}
static int F_170 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
T_1 V_50 = V_130 -> V_121 ;
unsigned int V_281 = F_164 ( V_19 , V_50 ) ;
unsigned int V_20 , V_58 ;
V_20 = F_16 ( V_19 , V_50 ) ;
V_58 = F_166 ( V_281 , V_20 & V_285 ) ;
if ( V_58 == V_132 -> V_135 . V_227 . V_228 [ 0 ] )
return 0 ;
V_20 &= ~ V_285 ;
V_20 |= F_165 ( V_281 , V_132 -> V_135 . V_227 . V_228 [ 0 ] ) ;
F_152 ( V_19 , V_50 , V_20 ) ;
return 1 ;
}
static int F_171 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_286 = 0 ;
if ( V_2 -> V_41 )
V_286 = F_168 ( F_164 ( V_19 , V_46 ) ) ;
return V_286 ? V_286 : 1 ;
}
static int F_172 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
char V_10 [ V_123 ] ;
unsigned int V_176 ;
if ( V_46 == V_2 -> V_259 )
return 0 ;
V_176 = F_106 ( V_19 , V_46 ) ;
if ( F_154 ( V_176 ) == V_268 )
return 0 ;
if ( F_171 ( V_19 , V_46 ) <= 1 )
return 0 ;
F_160 ( V_19 , V_46 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 , & V_287 ) ;
if ( ! V_12 )
return - V_124 ;
V_12 -> V_121 = V_46 ;
return 0 ;
}
static int F_173 ( struct V_129 * V_130 ,
struct V_225 * V_226 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
T_1 V_50 = V_130 -> V_121 ;
int V_288 = F_162 ( V_19 , V_50 ) ;
int V_289 = F_171 ( V_19 , V_50 ) ;
const char * V_290 = NULL ;
int V_58 ;
V_226 -> type = V_240 ;
V_226 -> V_241 = 1 ;
V_226 -> V_135 . V_227 . V_242 = V_288 + V_289 ;
if ( V_226 -> V_135 . V_227 . V_228 >= V_226 -> V_135 . V_227 . V_242 )
V_226 -> V_135 . V_227 . V_228 = V_226 -> V_135 . V_227 . V_242 - 1 ;
V_58 = V_226 -> V_135 . V_227 . V_228 ;
if ( V_58 < V_288 ) {
if ( V_288 > 1 )
V_290 = V_272 [ V_58 ] ;
else
V_290 = L_59 ;
} else {
V_58 -= V_288 ;
if ( V_289 > 1 ) {
unsigned int V_281 = F_164 ( V_19 , V_50 ) ;
V_290 = V_284 [ F_165 ( V_281 , V_58 ) ] ;
} else
V_290 = L_60 ;
}
strcpy ( V_226 -> V_135 . V_227 . V_10 , V_290 ) ;
return 0 ;
}
static int F_174 ( struct V_18 * V_19 , T_1 V_50 )
{
int V_288 = F_162 ( V_19 , V_50 ) ;
int V_289 = F_171 ( V_19 , V_50 ) ;
unsigned int V_20 = F_16 ( V_19 , V_50 ) ;
int V_58 = 0 ;
if ( V_20 & V_223 ) {
if ( V_288 > 1 && V_20 == V_222 )
V_58 = 1 ;
} else if ( V_20 & V_262 ) {
V_58 = V_288 ;
if ( V_289 > 1 ) {
unsigned int V_281 = F_164 ( V_19 , V_50 ) ;
V_20 &= V_285 ;
V_58 += F_166 ( V_281 , V_20 ) ;
}
}
return V_58 ;
}
static int F_175 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
T_1 V_50 = V_130 -> V_121 ;
V_132 -> V_135 . V_227 . V_228 [ 0 ] =
F_174 ( V_19 , V_50 ) ;
return 0 ;
}
static int F_176 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
T_1 V_50 = V_130 -> V_121 ;
int V_288 = F_162 ( V_19 , V_50 ) ;
int V_289 = F_171 ( V_19 , V_50 ) ;
unsigned int V_20 , V_291 , V_58 ;
V_291 = F_174 ( V_19 , V_50 ) ;
V_58 = V_132 -> V_135 . V_227 . V_228 [ 0 ] ;
if ( V_291 == V_58 )
return 0 ;
if ( V_58 < V_288 ) {
if ( V_288 > 1 )
V_20 = V_58 ? V_222 : V_223 ;
else
V_20 = V_222 ;
} else {
V_58 -= V_288 ;
if ( V_289 > 1 ) {
unsigned int V_281 = F_164 ( V_19 , V_50 ) ;
V_20 = F_16 ( V_19 , V_50 ) ;
V_20 &= ~ ( V_285 | V_222 ) ;
V_20 |= F_165 ( V_281 , V_58 ) | V_262 ;
} else
V_20 = F_151 ( V_19 , V_50 ) | V_262 ;
}
F_152 ( V_19 , V_50 , V_20 ) ;
F_135 ( V_19 , NULL ) ;
return 1 ;
}
static int F_177 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
V_12 = F_4 ( V_2 , L_61 ,
& V_292 ) ;
if ( ! V_12 )
return - V_124 ;
V_12 -> V_121 = V_46 ;
V_2 -> V_267 = 1 ;
return 0 ;
}
static int F_178 ( struct V_1 * V_2 , T_1 V_293 , int V_58 )
{
struct V_8 * V_14 ;
V_14 = F_5 ( & V_2 -> V_7 ) ;
if ( ! V_14 )
return - V_124 ;
V_14 -> V_50 = V_293 ;
V_14 -> V_61 = V_84 ;
V_14 -> V_58 = V_58 ;
V_2 -> V_294 . V_295 = V_2 -> V_7 . V_14 ;
return 0 ;
}
static bool F_179 ( struct V_18 * V_19 , T_1 V_296 ,
T_1 V_46 , unsigned int * V_297 ,
unsigned int * V_298 )
{
int V_58 , V_299 ;
const T_1 * V_14 ;
T_1 V_50 ;
V_58 = F_30 ( V_19 , V_296 , V_46 , true ) ;
if ( V_58 < 0 )
return false ;
* V_297 = * V_298 = 0 ;
if ( F_53 ( V_19 , V_296 , V_84 ) )
* V_297 = F_33 ( V_296 , 3 , V_58 , V_84 ) ;
if ( F_51 ( V_19 , V_296 , V_84 ) )
* V_298 = F_33 ( V_296 , 3 , V_58 , V_84 ) ;
if ( * V_297 && * V_298 )
return true ;
V_299 = F_38 ( V_19 , V_296 , & V_14 ) ;
if ( V_299 < V_58 )
return false ;
V_50 = V_14 [ V_58 ] ;
if ( ! * V_297 && F_53 ( V_19 , V_50 , V_83 ) &&
! F_32 ( V_19 , V_50 , V_83 , 0 , V_100 ) )
* V_297 = F_33 ( V_50 , 3 , 0 , V_83 ) ;
if ( ! * V_298 && F_51 ( V_19 , V_50 , V_83 ) &&
! F_32 ( V_19 , V_50 , V_83 , 0 , V_99 ) )
* V_298 = F_33 ( V_50 , 3 , 0 , V_83 ) ;
return * V_297 || * V_298 ;
}
static int F_180 ( struct V_18 * V_19 , int V_300 ,
T_1 V_46 , const char * V_301 , int V_302 ,
T_1 V_296 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_52 ;
unsigned int V_297 , V_298 ;
int V_193 , V_58 ;
if ( ! F_179 ( V_19 , V_296 , V_46 , & V_297 , & V_298 ) )
return 0 ;
V_52 = F_42 ( V_19 , V_46 , V_296 , 0 ) ;
if ( ! V_52 )
return - V_244 ;
F_34 ( L_62 , V_52 ) ;
V_2 -> V_198 [ V_300 ] = F_26 ( V_19 , V_52 ) ;
V_58 = V_52 -> V_58 [ V_52 -> V_53 - 1 ] ;
if ( V_297 ) {
V_193 = F_81 ( V_2 , V_125 , V_301 , V_302 , V_297 ) ;
if ( V_193 < 0 )
return V_193 ;
V_52 -> V_60 [ V_100 ] = V_297 ;
}
if ( V_298 ) {
V_193 = F_87 ( V_2 , V_127 , V_301 , V_302 , V_298 ) ;
if ( V_193 < 0 )
return V_193 ;
V_52 -> V_60 [ V_99 ] = V_298 ;
}
V_52 -> V_90 = true ;
V_193 = F_178 ( V_2 , V_296 , V_58 ) ;
if ( V_193 < 0 )
return V_193 ;
if ( V_2 -> V_45 != V_2 -> V_104 &&
! V_2 -> V_303 ) {
V_52 = F_42 ( V_19 , V_2 -> V_45 ,
V_2 -> V_104 , 0 ) ;
if ( V_52 ) {
F_34 ( L_63 , V_52 ) ;
V_52 -> V_90 = true ;
V_2 -> V_303 =
F_26 ( V_19 , V_52 ) ;
}
}
return 0 ;
}
static int F_181 ( struct V_18 * V_19 , T_1 V_50 )
{
unsigned int V_274 = F_74 ( V_19 , V_50 ) ;
return ( V_274 & V_270 ) != 0 ;
}
static int F_182 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_50 ;
T_1 * V_304 = V_2 -> V_304 ;
int V_305 = F_98 ( V_2 -> V_304 ) ;
int V_16 , V_51 = 0 ;
V_50 = V_19 -> V_210 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_211 ; V_16 ++ , V_50 ++ ) {
unsigned int V_86 = F_40 ( V_19 , V_50 ) ;
int type = F_39 ( V_86 ) ;
if ( type != V_69 || ( V_86 & V_78 ) )
continue;
V_304 [ V_51 ] = V_50 ;
if ( ++ V_51 >= V_305 )
break;
}
V_2 -> V_306 = V_51 ;
V_2 -> V_307 = V_51 ;
memcpy ( V_2 -> V_308 , V_2 -> V_304 , V_51 * sizeof( T_1 ) ) ;
return V_51 ;
}
static int F_183 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_309 * V_310 = & V_2 -> V_311 ;
unsigned int V_312 ;
int V_16 , V_89 , V_51 ;
V_51 = 0 ;
V_312 = 0 ;
for ( V_89 = 0 ; V_89 < V_2 -> V_306 ; V_89 ++ ) {
for ( V_16 = 0 ; V_16 < V_310 -> V_313 ; V_16 ++ ) {
if ( ! V_2 -> V_197 [ V_16 ] [ V_89 ] )
break;
}
if ( V_16 >= V_310 -> V_313 ) {
V_312 |= ( 1 << V_89 ) ;
V_51 ++ ;
}
}
if ( ! V_312 ) {
for ( V_16 = 0 ; V_16 < V_310 -> V_313 ; V_16 ++ ) {
for ( V_89 = 0 ; V_89 < V_2 -> V_306 ; V_89 ++ ) {
if ( V_2 -> V_197 [ V_16 ] [ V_89 ] ) {
V_2 -> V_314 [ V_16 ] = V_89 ;
break;
}
}
}
F_36 ( L_64 ) ;
V_2 -> V_315 = 1 ;
} else if ( V_51 != V_2 -> V_306 ) {
V_51 = 0 ;
for ( V_89 = 0 ; V_89 < V_2 -> V_306 ; V_89 ++ ) {
if ( ! ( V_312 & ( 1 << V_89 ) ) )
continue;
if ( V_89 != V_51 ) {
V_2 -> V_304 [ V_51 ] = V_2 -> V_304 [ V_89 ] ;
for ( V_16 = 0 ; V_16 < V_310 -> V_313 ; V_16 ++ ) {
F_43 ( V_19 ,
V_2 -> V_197 [ V_16 ] [ V_51 ] ) ;
V_2 -> V_197 [ V_16 ] [ V_51 ] =
V_2 -> V_197 [ V_16 ] [ V_89 ] ;
}
}
V_51 ++ ;
}
V_2 -> V_306 = V_51 ;
}
if ( V_310 -> V_313 == 1 ||
( V_310 -> V_313 == 2 && V_2 -> V_43 ) ) {
F_36 ( L_65 ) ;
V_2 -> V_306 = 1 ;
}
if ( ! V_2 -> V_315 && V_2 -> V_37 )
V_2 -> V_306 = 1 ;
return 0 ;
}
static int F_184 ( struct V_18 * V_19 , T_1 V_46 ,
int V_316 , int V_317 ,
const char * V_318 , int V_319 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_309 * V_310 = & V_2 -> V_311 ;
int V_320 = V_310 -> V_313 ;
bool V_321 = false ;
int V_322 ;
for ( V_322 = 0 ; V_322 < V_317 ; V_322 ++ ) {
struct V_6 * V_52 ;
T_1 V_323 = V_2 -> V_304 [ V_322 ] ;
if ( ! F_29 ( V_19 , V_46 , V_323 ) )
continue;
V_52 = F_42 ( V_19 , V_46 , V_323 , V_319 ) ;
if ( ! V_52 )
continue;
F_34 ( L_66 , V_52 ) ;
V_2 -> V_197 [ V_320 ] [ V_322 ] =
F_26 ( V_19 , V_52 ) ;
if ( ! V_321 ) {
if ( V_2 -> V_259 == V_46 )
V_2 -> V_261 = V_310 -> V_313 ;
V_2 -> V_324 [ V_310 -> V_313 ] = V_46 ;
F_185 ( V_310 , V_318 , V_316 , NULL ) ;
V_321 = true ;
if ( V_2 -> V_315 )
V_2 -> V_314 [ V_320 ] = V_322 ;
}
}
return 0 ;
}
static int F_186 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_138 * V_139 = & V_2 -> V_140 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_139 -> V_182 ; V_16 ++ ) {
T_1 V_46 = V_139 -> V_183 [ V_16 ] . V_46 ;
const char * V_318 ;
int V_167 , V_58 ;
if ( ! F_181 ( V_19 , V_46 ) )
continue;
V_318 = F_187 ( V_19 , V_139 , V_16 ) ;
V_58 = 0 ;
for ( V_167 = V_16 - 1 ; V_167 >= 0 ; V_167 -- ) {
if ( V_2 -> V_325 [ V_167 ] &&
! strcmp ( V_2 -> V_325 [ V_167 ] , V_318 ) ) {
V_58 = V_2 -> V_326 [ V_167 ] + 1 ;
break;
}
}
V_2 -> V_325 [ V_16 ] = V_318 ;
V_2 -> V_326 [ V_16 ] = V_58 ;
}
return 0 ;
}
static int F_188 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_138 * V_139 = & V_2 -> V_140 ;
T_1 V_327 = V_2 -> V_45 ;
int V_317 ;
int V_16 , V_193 ;
unsigned int V_20 ;
V_317 = F_182 ( V_19 ) ;
if ( V_317 < 0 )
return 0 ;
V_193 = F_186 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
for ( V_16 = 0 ; V_16 < V_139 -> V_182 ; V_16 ++ ) {
T_1 V_46 ;
V_46 = V_139 -> V_183 [ V_16 ] . V_46 ;
if ( ! F_181 ( V_19 , V_46 ) )
continue;
V_20 = V_262 ;
if ( V_139 -> V_183 [ V_16 ] . type == V_181 )
V_20 |= F_151 ( V_19 , V_46 ) ;
if ( V_46 != V_2 -> V_259 )
F_17 ( V_19 , V_46 , V_20 , false ) ;
if ( V_327 ) {
if ( F_29 ( V_19 , V_46 , V_327 ) ) {
V_193 = F_180 ( V_19 , V_16 , V_46 ,
V_2 -> V_325 [ V_16 ] ,
V_2 -> V_326 [ V_16 ] ,
V_327 ) ;
if ( V_193 < 0 )
return V_193 ;
}
}
V_193 = F_184 ( V_19 , V_46 , V_16 , V_317 ,
V_2 -> V_325 [ V_16 ] , - V_327 ) ;
if ( V_193 < 0 )
return V_193 ;
if ( V_2 -> V_41 ) {
V_193 = F_172 ( V_19 , V_46 ) ;
if ( V_193 < 0 )
return V_193 ;
}
}
if ( V_327 && V_2 -> V_40 &&
F_12 ( V_19 , L_20 ) > 0 ) {
V_193 = F_184 ( V_19 , V_327 , V_328 , V_317 ,
L_67 , 0 ) ;
if ( V_193 < 0 )
return V_193 ;
}
return 0 ;
}
static struct V_6 * F_189 ( struct V_18 * V_19 , int V_329 , int V_320 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_320 < 0 || V_320 >= V_330 ) {
F_99 () ;
return NULL ;
}
if ( V_2 -> V_315 )
V_329 = V_2 -> V_314 [ V_320 ] ;
if ( V_329 < 0 || V_329 >= V_269 ) {
F_99 () ;
return NULL ;
}
return F_27 ( V_19 , V_2 -> V_197 [ V_320 ] [ V_329 ] ) ;
}
static int F_190 ( struct V_129 * V_130 ,
struct V_225 * V_226 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
return F_191 ( & V_2 -> V_311 , V_226 ) ;
}
static int F_192 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_329 = F_193 ( V_130 , & V_132 -> V_331 ) ;
V_132 -> V_135 . V_227 . V_228 [ 0 ] = V_2 -> V_260 [ V_329 ] ;
return 0 ;
}
static int F_194 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
unsigned int V_329 = F_193 ( V_130 , & V_132 -> V_331 ) ;
return F_195 ( V_19 , V_329 ,
V_132 -> V_135 . V_227 . V_228 [ 0 ] ) ;
}
static int F_196 ( struct V_129 * V_130 ,
struct V_131 * V_132 ,
T_4 V_332 , int type )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_309 * V_310 ;
struct V_6 * V_52 ;
int V_16 , V_329 , V_193 = 0 ;
V_310 = & V_2 -> V_311 ;
V_329 = V_130 -> V_331 . V_118 ;
F_133 ( & V_19 -> V_333 ) ;
V_19 -> V_334 = 1 ;
for ( V_16 = 0 ; V_16 < V_310 -> V_313 ; V_16 ++ ) {
V_52 = F_189 ( V_19 , V_329 , V_16 ) ;
if ( ! V_52 || ! V_52 -> V_60 [ type ] )
continue;
V_130 -> V_121 = V_52 -> V_60 [ type ] ;
V_193 = V_332 ( V_130 , V_132 ) ;
if ( V_193 < 0 )
goto error;
}
error:
V_19 -> V_334 = 0 ;
F_136 ( & V_19 -> V_333 ) ;
F_197 ( V_19 ) ;
if ( V_193 >= 0 && V_2 -> V_335 )
V_2 -> V_335 ( V_19 , V_130 , V_132 ) ;
return V_193 ;
}
static int F_198 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
return F_196 ( V_130 , V_132 ,
V_336 ,
V_100 ) ;
}
static int F_199 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
return F_196 ( V_130 , V_132 ,
F_93 ,
V_99 ) ;
}
static int F_200 ( struct V_18 * V_19 , struct V_6 * V_52 )
{
T_1 V_50 ;
int V_16 , V_53 ;
V_52 -> V_60 [ V_100 ] = V_52 -> V_60 [ V_99 ] = 0 ;
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
if ( V_53 >= V_52 -> V_53 )
return - V_244 ;
V_16 = V_52 -> V_53 - V_53 - 1 ;
V_50 = V_52 -> V_52 [ V_16 ] ;
if ( ! V_52 -> V_60 [ V_100 ] ) {
if ( F_53 ( V_19 , V_50 , V_83 ) )
V_52 -> V_60 [ V_100 ] =
F_33 ( V_50 , 3 , 0 , V_83 ) ;
else if ( F_53 ( V_19 , V_50 , V_84 ) ) {
int V_58 = V_52 -> V_58 [ V_16 ] ;
if ( ! V_53 && V_19 -> V_29 )
V_58 = 0 ;
V_52 -> V_60 [ V_100 ] =
F_33 ( V_50 , 3 , V_58 , V_84 ) ;
}
}
if ( ! V_52 -> V_60 [ V_99 ] ) {
if ( F_51 ( V_19 , V_50 , V_83 ) )
V_52 -> V_60 [ V_99 ] =
F_33 ( V_50 , 3 , 0 , V_83 ) ;
else if ( F_51 ( V_19 , V_50 , V_84 ) ) {
int V_58 = V_52 -> V_58 [ V_16 ] ;
if ( ! V_53 && V_19 -> V_29 )
V_58 = 0 ;
V_52 -> V_60 [ V_99 ] =
F_33 ( V_50 , 3 , V_58 , V_84 ) ;
}
}
}
return 0 ;
}
static bool F_201 ( struct V_18 * V_19 , T_1 V_50 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
unsigned int V_20 ;
int V_16 ;
if ( ! V_2 -> V_38 )
return false ;
for ( V_16 = 0 ; V_16 < V_139 -> V_182 ; V_16 ++ ) {
if ( V_139 -> V_183 [ V_16 ] . V_46 != V_50 )
continue;
if ( V_139 -> V_183 [ V_16 ] . type != V_181 )
return false ;
V_20 = F_106 ( V_19 , V_50 ) ;
return F_154 ( V_20 ) == V_268 ;
}
return false ;
}
static int F_202 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_231 ;
V_231 = F_93 ( V_130 , V_132 ) ;
if ( V_231 < 0 )
return V_231 ;
if ( V_2 -> V_335 )
V_2 -> V_335 ( V_19 , V_130 , V_132 ) ;
return V_231 ;
}
static int F_203 ( struct V_18 * V_19 , const char * V_318 ,
int V_58 , bool V_337 , unsigned int V_338 ,
bool V_339 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
char V_340 [ V_123 ] ;
int type = V_337 ? V_127 : V_125 ;
const char * V_122 = V_337 ? L_68 : L_69 ;
unsigned int V_79 = V_339 ? 1 : 3 ;
struct V_4 * V_12 ;
if ( ! V_338 )
return 0 ;
if ( V_318 )
snprintf ( V_340 , sizeof( V_340 ) ,
L_70 , V_318 , V_122 ) ;
else
snprintf ( V_340 , sizeof( V_340 ) ,
L_71 , V_122 ) ;
V_12 = F_77 ( V_2 , type , V_340 , V_58 ,
F_46 ( V_338 , V_79 ) ) ;
if ( ! V_12 )
return - V_124 ;
if ( V_337 )
V_12 -> V_341 = F_202 ;
if ( ! V_339 )
return 0 ;
if ( V_318 )
snprintf ( V_340 , sizeof( V_340 ) ,
L_72 , V_318 , V_122 ) ;
else
snprintf ( V_340 , sizeof( V_340 ) ,
L_73 , V_122 ) ;
V_12 = F_77 ( V_2 , type , V_340 , V_58 ,
F_46 ( V_338 , 2 ) ) ;
if ( ! V_12 )
return - V_124 ;
if ( V_337 )
V_12 -> V_341 = F_202 ;
return 0 ;
}
static int F_204 ( struct V_18 * V_19 , int V_58 ,
unsigned int V_342 , unsigned int V_343 ,
bool V_339 )
{
int V_193 ;
V_193 = F_203 ( V_19 , NULL , V_58 , false , V_342 , V_339 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_203 ( V_19 , NULL , V_58 , true , V_343 , V_339 ) ;
if ( V_193 < 0 )
return V_193 ;
return 0 ;
}
static int F_205 ( struct V_18 * V_19 , int V_58 ,
unsigned int V_342 , unsigned int V_343 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
if ( V_342 ) {
V_12 = F_4 ( V_2 , NULL , & V_344 ) ;
if ( ! V_12 )
return - V_124 ;
V_12 -> V_118 = V_58 ;
V_12 -> V_121 = V_342 ;
V_12 -> V_119 = V_120 ;
}
if ( V_343 ) {
V_12 = F_4 ( V_2 , NULL , & V_345 ) ;
if ( ! V_12 )
return - V_124 ;
V_12 -> V_118 = V_58 ;
V_12 -> V_121 = V_343 ;
V_12 -> V_119 = V_120 ;
}
return 0 ;
}
static unsigned int F_206 ( struct V_18 * V_19 , int V_58 , int type )
{
struct V_6 * V_52 ;
unsigned int V_338 ;
int V_16 ;
V_52 = F_189 ( V_19 , 0 , V_58 ) ;
if ( ! V_52 )
return 0 ;
V_338 = V_52 -> V_60 [ type ] ;
if ( ! V_338 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_58 - 1 ; V_16 ++ ) {
V_52 = F_189 ( V_19 , 0 , V_16 ) ;
if ( V_52 && V_52 -> V_60 [ type ] == V_338 )
return 0 ;
}
return V_338 ;
}
static int F_207 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_309 * V_310 = & V_2 -> V_311 ;
int V_16 , V_193 , type ;
for ( V_16 = 0 ; V_16 < V_310 -> V_313 ; V_16 ++ ) {
bool V_339 ;
int V_58 ;
V_58 = V_310 -> V_242 [ V_16 ] . V_118 ;
if ( V_58 >= V_2 -> V_140 . V_182 )
continue;
V_339 = F_201 ( V_19 , V_2 -> V_324 [ V_16 ] ) ;
for ( type = 0 ; type < 2 ; type ++ ) {
V_193 = F_203 ( V_19 ,
V_2 -> V_325 [ V_58 ] ,
V_2 -> V_326 [ V_58 ] ,
type ,
F_206 ( V_19 , V_16 , type ) ,
V_339 ) ;
if ( V_193 < 0 )
return V_193 ;
}
}
return 0 ;
}
static int F_208 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_309 * V_310 = & V_2 -> V_311 ;
int V_16 , V_89 , V_51 , V_193 ;
if ( V_2 -> V_315 )
V_51 = 1 ;
else
V_51 = V_2 -> V_306 ;
if ( ! V_2 -> V_346 && V_310 -> V_313 > 1 ) {
struct V_4 * V_12 ;
const char * V_10 ;
V_10 = V_51 > 1 ? L_74 : L_75 ;
V_12 = F_4 ( V_2 , V_10 , & V_347 ) ;
if ( ! V_12 )
return - V_124 ;
V_12 -> V_241 = V_51 ;
}
for ( V_89 = 0 ; V_89 < V_51 ; V_89 ++ ) {
bool V_72 = false ;
bool V_37 = V_2 -> V_37 ;
bool V_339 = false ;
int V_348 , V_349 ;
V_348 = V_349 = 0 ;
for ( V_16 = 0 ; V_16 < V_310 -> V_313 ; V_16 ++ ) {
struct V_6 * V_52 ;
V_52 = F_189 ( V_19 , V_89 , V_16 ) ;
if ( ! V_52 )
continue;
F_200 ( V_19 , V_52 ) ;
if ( ! V_348 )
V_348 = V_52 -> V_60 [ V_100 ] ;
else if ( V_348 != V_52 -> V_60 [ V_100 ] ) {
V_72 = true ;
if ( ! F_49 ( V_19 , V_348 ,
V_52 -> V_60 [ V_100 ] , V_84 ) )
V_37 = true ;
}
if ( ! V_349 )
V_349 = V_52 -> V_60 [ V_99 ] ;
else if ( V_349 != V_52 -> V_60 [ V_99 ] ) {
V_72 = true ;
if ( ! F_49 ( V_19 , V_349 ,
V_52 -> V_60 [ V_99 ] , V_84 ) )
V_37 = true ;
}
if ( F_201 ( V_19 , V_2 -> V_324 [ V_16 ] ) )
V_339 = true ;
}
if ( ! V_72 )
V_193 = F_204 ( V_19 , V_89 , V_348 , V_349 ,
V_339 ) ;
else if ( ! V_37 && ! V_339 )
V_193 = F_205 ( V_19 , V_89 , V_348 , V_349 ) ;
else
V_193 = F_207 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
}
return 0 ;
}
static bool F_209 ( struct V_18 * V_19 , T_1 V_50 ,
int V_61 , int V_58 )
{
unsigned int V_350 ;
if ( ! F_53 ( V_19 , V_50 , V_61 ) ||
F_32 ( V_19 , V_50 , V_61 , V_58 , V_100 ) ||
F_32 ( V_19 , V_50 , V_61 , V_58 , V_101 ) )
return false ;
V_350 = ( F_48 ( V_19 , V_50 , V_61 ) & V_351 )
>> V_352 ;
if ( V_350 < 0x20 )
return false ;
return true ;
}
static unsigned int F_210 ( struct V_18 * V_19 ,
struct V_6 * V_52 )
{
unsigned int V_20 = 0 ;
T_1 V_50 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
if ( V_53 >= V_52 -> V_53 - 1 )
break;
V_50 = V_52 -> V_52 [ V_53 ] ;
if ( V_53 && F_209 ( V_19 , V_50 , V_83 , 0 ) ) {
V_20 = F_33 ( V_50 , 3 , 0 , V_83 ) ;
break;
} else if ( F_209 ( V_19 , V_50 , V_84 ,
V_52 -> V_58 [ V_53 ] ) ) {
V_20 = F_33 ( V_50 , 3 , V_52 -> V_58 [ V_53 ] ,
V_84 ) ;
break;
}
}
return V_20 ;
}
static int F_211 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
struct V_309 * V_310 = & V_2 -> V_311 ;
int V_16 ;
if ( ! V_2 -> V_306 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_310 -> V_313 ; V_16 ++ ) {
struct V_6 * V_52 ;
unsigned int V_20 ;
int V_58 ;
char V_353 [ V_123 ] ;
V_58 = V_310 -> V_242 [ V_16 ] . V_118 ;
if ( V_58 >= V_310 -> V_313 )
continue;
if ( V_139 -> V_183 [ V_58 ] . type > V_180 )
continue;
V_52 = F_189 ( V_19 , 0 , V_16 ) ;
if ( ! V_52 )
continue;
V_20 = F_210 ( V_19 , V_52 ) ;
if ( ! V_20 )
continue;
snprintf ( V_353 , sizeof( V_353 ) ,
L_76 , V_2 -> V_325 [ V_58 ] ) ;
if ( ! F_77 ( V_2 , V_125 , V_353 ,
V_2 -> V_326 [ V_58 ] , V_20 ) )
return - V_124 ;
V_52 -> V_60 [ V_101 ] = V_20 ;
}
return 0 ;
}
static void F_212 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_52 ;
int V_16 , V_51 ;
T_1 V_354 , V_46 ;
V_51 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_140 . V_355 ; V_16 ++ ) {
V_46 = V_2 -> V_140 . V_356 [ V_16 ] ;
V_354 = F_45 ( V_19 , V_46 , true ) ;
if ( ! V_354 )
continue;
V_52 = F_42 ( V_19 , V_354 , V_46 , 0 ) ;
if ( ! V_52 )
continue;
F_34 ( L_77 , V_52 ) ;
V_52 -> V_90 = true ;
V_2 -> V_196 [ V_16 ] = F_26 ( V_19 , V_52 ) ;
F_17 ( V_19 , V_46 , V_223 , false ) ;
if ( ! V_51 ) {
V_2 -> V_147 . V_357 = V_354 ;
V_2 -> V_358 = V_2 -> V_140 . V_358 [ 0 ] ;
} else {
V_2 -> V_147 . V_359 = V_2 -> V_359 ;
if ( V_51 >= F_98 ( V_2 -> V_359 ) - 1 )
break;
V_2 -> V_359 [ V_51 - 1 ] = V_354 ;
}
V_51 ++ ;
}
if ( V_2 -> V_140 . V_360 ) {
V_46 = V_2 -> V_140 . V_360 ;
V_354 = V_19 -> V_210 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_211 ; V_16 ++ , V_354 ++ ) {
unsigned int V_361 = F_40 ( V_19 , V_354 ) ;
if ( F_39 ( V_361 ) != V_69 )
continue;
if ( ! ( V_361 & V_78 ) )
continue;
V_52 = F_42 ( V_19 , V_46 , V_354 , 0 ) ;
if ( V_52 ) {
F_34 ( L_78 , V_52 ) ;
V_52 -> V_90 = true ;
V_2 -> V_362 = V_354 ;
V_2 -> V_199 = F_26 ( V_19 , V_52 ) ;
F_17 ( V_19 , V_46 , V_262 , false ) ;
break;
}
}
}
}
static int F_195 ( struct V_18 * V_19 , unsigned int V_329 ,
unsigned int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_309 * V_310 ;
struct V_6 * V_363 , * V_52 ;
V_310 = & V_2 -> V_311 ;
if ( ! V_310 -> V_313 )
return 0 ;
if ( V_58 >= V_310 -> V_313 )
V_58 = V_310 -> V_313 - 1 ;
if ( V_2 -> V_260 [ V_329 ] == V_58 )
return 0 ;
V_363 = F_189 ( V_19 , V_329 , V_2 -> V_260 [ V_329 ] ) ;
if ( ! V_363 )
return 0 ;
if ( V_363 -> V_90 )
F_65 ( V_19 , V_363 , false , false ) ;
V_2 -> V_260 [ V_329 ] = V_58 ;
if ( V_2 -> V_43 )
F_150 ( V_19 , V_329 , false ) ;
if ( V_2 -> V_315 )
F_213 ( V_19 , V_58 ) ;
V_52 = F_189 ( V_19 , V_329 , V_58 ) ;
if ( ! V_52 )
return 0 ;
if ( V_52 -> V_90 )
return 0 ;
F_65 ( V_19 , V_52 , true , false ) ;
if ( V_2 -> V_335 )
V_2 -> V_335 ( V_19 , NULL , NULL ) ;
F_69 ( V_19 , V_363 ) ;
return 1 ;
}
static bool F_214 ( struct V_18 * V_19 , int V_48 , T_1 * V_49 )
{
int V_16 ;
bool V_364 = false ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
T_1 V_50 = V_49 [ V_16 ] ;
if ( ! V_50 )
break;
if ( F_16 ( V_19 , V_50 ) & V_365 )
continue;
if ( F_215 ( V_19 , V_50 ) == V_366 )
V_364 = true ;
}
return V_364 ;
}
static void F_216 ( struct V_18 * V_19 , int V_48 , T_1 * V_49 ,
int * V_5 , bool V_367 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
T_1 V_50 = V_49 [ V_16 ] ;
unsigned int V_20 , V_291 ;
if ( ! V_50 )
break;
if ( V_2 -> V_33 ) {
struct V_6 * V_52 ;
T_1 V_368 ;
V_52 = F_27 ( V_19 , V_5 [ V_16 ] ) ;
if ( ! V_52 )
continue;
V_368 = F_78 ( V_52 -> V_60 [ V_99 ] ) ;
if ( ! V_368 )
continue;
if ( V_367 )
V_2 -> V_134 |= ( 1ULL << V_368 ) ;
else
V_2 -> V_134 &= ~ ( 1ULL << V_368 ) ;
F_73 ( V_19 , V_50 , ! V_367 ) ;
continue;
}
V_291 = F_16 ( V_19 , V_50 ) ;
if ( V_291 & V_262 )
continue;
if ( V_2 -> V_369 )
V_20 = V_291 & ~ V_222 ;
else
V_20 = 0 ;
if ( ! V_367 )
V_20 |= V_291 ;
F_15 ( V_19 , V_50 , V_20 ) ;
F_73 ( V_19 , V_50 , ! V_367 ) ;
}
}
void F_217 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int * V_5 ;
int V_370 ;
if ( V_2 -> V_140 . V_152 == V_155 )
V_5 = V_2 -> V_187 ;
else
V_5 = V_2 -> V_154 ;
F_216 ( V_19 , F_98 ( V_2 -> V_140 . V_202 ) ,
V_2 -> V_140 . V_202 , V_5 , V_2 -> V_371 ) ;
if ( ! V_2 -> V_372 )
V_370 = 0 ;
else
V_370 = V_2 -> V_373 | V_2 -> V_374 ;
V_370 |= V_2 -> V_371 ;
V_2 -> V_375 = V_370 ;
if ( V_2 -> V_140 . V_152 == V_153 )
V_5 = V_2 -> V_187 ;
else
V_5 = V_2 -> V_156 ;
F_216 ( V_19 , F_98 ( V_2 -> V_140 . V_203 ) ,
V_2 -> V_140 . V_203 , V_5 , V_370 ) ;
if ( V_2 -> V_140 . V_201 [ 0 ] == V_2 -> V_140 . V_202 [ 0 ] ||
V_2 -> V_140 . V_201 [ 0 ] == V_2 -> V_140 . V_203 [ 0 ] )
return;
if ( ! V_2 -> V_376 )
V_370 = 0 ;
else
V_370 = V_2 -> V_373 ;
V_370 |= V_2 -> V_371 ;
V_2 -> V_377 = V_370 ;
V_5 = V_2 -> V_187 ;
F_216 ( V_19 , F_98 ( V_2 -> V_140 . V_201 ) ,
V_2 -> V_140 . V_201 , V_5 , V_370 ) ;
}
static void F_218 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_378 )
V_2 -> V_378 ( V_19 ) ;
else
F_217 ( V_19 ) ;
if ( V_2 -> V_33 && ! V_19 -> V_379 -> V_380 )
F_219 ( V_2 -> V_145 . V_381 , false ) ;
}
void F_220 ( struct V_18 * V_19 , struct V_382 * V_383 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 * V_49 = V_2 -> V_140 . V_202 ;
int V_48 = F_98 ( V_2 -> V_140 . V_202 ) ;
if ( V_2 -> V_229 ) {
V_49 ++ ;
V_48 -- ;
}
V_2 -> V_373 = F_214 ( V_19 , V_48 , V_49 ) ;
if ( ! V_2 -> V_384 || ( ! V_2 -> V_372 && ! V_2 -> V_376 ) )
return;
F_218 ( V_19 ) ;
}
void F_221 ( struct V_18 * V_19 , struct V_382 * V_383 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_140 . V_152 == V_153 )
return;
if ( V_2 -> V_140 . V_201 [ 0 ] == V_2 -> V_140 . V_202 [ 0 ] )
return;
V_2 -> V_374 =
F_214 ( V_19 , F_98 ( V_2 -> V_140 . V_201 ) ,
V_2 -> V_140 . V_201 ) ;
if ( ! V_2 -> V_372 || ! V_2 -> V_385 )
return;
F_218 ( V_19 ) ;
}
void F_222 ( struct V_18 * V_19 , struct V_382 * V_383 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
if ( ! V_2 -> V_346 )
return;
for ( V_16 = V_2 -> V_386 - 1 ; V_16 > 0 ; V_16 -- ) {
T_1 V_46 = V_2 -> V_387 [ V_16 ] . V_46 ;
if ( F_16 ( V_19 , V_46 ) & V_388 )
continue;
if ( F_215 ( V_19 , V_46 ) == V_366 ) {
F_195 ( V_19 , 0 , V_2 -> V_387 [ V_16 ] . V_58 ) ;
return;
}
}
F_195 ( V_19 , 0 , V_2 -> V_387 [ 0 ] . V_58 ) ;
}
static void F_135 ( struct V_18 * V_19 , struct V_382 * V_383 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_389 )
V_2 -> V_389 ( V_19 , V_383 ) ;
else
F_220 ( V_19 , V_383 ) ;
}
static void F_223 ( struct V_18 * V_19 ,
struct V_382 * V_383 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_390 )
V_2 -> V_390 ( V_19 , V_383 ) ;
else
F_221 ( V_19 , V_383 ) ;
}
static void F_224 ( struct V_18 * V_19 ,
struct V_382 * V_383 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_391 )
V_2 -> V_391 ( V_19 , V_383 ) ;
else
F_222 ( V_19 , V_383 ) ;
}
static void F_143 ( struct V_18 * V_19 )
{
F_135 ( V_19 , NULL ) ;
F_223 ( V_19 , NULL ) ;
F_224 ( V_19 , NULL ) ;
}
static int F_225 ( struct V_129 * V_130 ,
struct V_225 * V_226 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_392 [] = {
L_79 , L_80 , L_81
} ;
if ( V_2 -> V_393 && V_2 -> V_394 )
return F_156 ( V_130 , V_226 , 3 , V_392 ) ;
return F_130 ( V_130 , V_226 ) ;
}
static int F_226 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = 0 ;
if ( V_2 -> V_372 )
V_20 ++ ;
if ( V_2 -> V_376 )
V_20 ++ ;
V_132 -> V_135 . V_227 . V_228 [ 0 ] = V_20 ;
return 0 ;
}
static int F_227 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_90 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
switch ( V_132 -> V_135 . V_227 . V_228 [ 0 ] ) {
case 0 :
if ( ! V_2 -> V_372 && ! V_2 -> V_376 )
return 0 ;
V_2 -> V_372 = 0 ;
V_2 -> V_376 = 0 ;
break;
case 1 :
if ( V_2 -> V_393 ) {
if ( ! V_2 -> V_376 && V_2 -> V_372 )
return 0 ;
V_2 -> V_372 = 1 ;
V_2 -> V_376 = 0 ;
} else if ( V_2 -> V_394 ) {
if ( V_2 -> V_376 )
return 0 ;
V_2 -> V_376 = 1 ;
} else
return - V_244 ;
break;
case 2 :
if ( ! V_2 -> V_394 || ! V_2 -> V_393 )
return - V_244 ;
if ( V_2 -> V_372 && V_2 -> V_376 )
return 0 ;
V_2 -> V_372 = 1 ;
V_2 -> V_376 = 1 ;
break;
default:
return - V_244 ;
}
F_218 ( V_19 ) ;
return 1 ;
}
static int F_228 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! F_4 ( V_2 , NULL , & V_395 ) )
return - V_124 ;
return 0 ;
}
static int F_229 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
int V_364 = 0 ;
int V_16 , V_193 ;
if ( V_2 -> V_30 )
return 0 ;
if ( V_139 -> V_202 [ 0 ] )
V_364 ++ ;
if ( V_139 -> V_201 [ 0 ] )
V_364 ++ ;
if ( V_139 -> V_203 [ 0 ] )
V_364 ++ ;
if ( V_364 < 2 )
return 0 ;
if ( ! V_139 -> V_203 [ 0 ] &&
V_139 -> V_152 == V_153 ) {
memcpy ( V_139 -> V_203 , V_139 -> V_201 ,
sizeof( V_139 -> V_203 ) ) ;
V_139 -> V_144 = V_139 -> V_141 ;
}
if ( ! V_139 -> V_202 [ 0 ] &&
V_139 -> V_152 == V_155 ) {
memcpy ( V_139 -> V_202 , V_139 -> V_201 ,
sizeof( V_139 -> V_202 ) ) ;
V_139 -> V_143 = V_139 -> V_141 ;
}
for ( V_16 = 0 ; V_16 < V_139 -> V_143 ; V_16 ++ ) {
T_1 V_50 = V_139 -> V_202 [ V_16 ] ;
if ( ! F_230 ( V_19 , V_50 ) )
continue;
F_36 ( L_82 ,
V_50 ) ;
F_231 ( V_19 , V_50 , V_396 ,
F_135 ) ;
V_2 -> V_384 = 1 ;
}
if ( V_139 -> V_152 == V_397 && V_139 -> V_141 ) {
if ( V_139 -> V_144 )
for ( V_16 = 0 ; V_16 < V_139 -> V_141 ; V_16 ++ ) {
T_1 V_50 = V_139 -> V_201 [ V_16 ] ;
if ( ! F_230 ( V_19 , V_50 ) )
continue;
F_36 ( L_83 , V_50 ) ;
F_231 ( V_19 , V_50 ,
V_398 ,
F_223 ) ;
V_2 -> V_385 = 1 ;
}
V_2 -> V_394 = V_2 -> V_384 ;
}
V_2 -> V_393 = V_139 -> V_144 &&
( V_2 -> V_384 || V_2 -> V_385 ) ;
V_2 -> V_376 = V_2 -> V_394 ;
V_2 -> V_372 = V_2 -> V_393 ;
if ( V_2 -> V_393 || V_2 -> V_394 ) {
V_193 = F_228 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
}
return 0 ;
}
static bool F_232 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_309 * V_310 ;
int V_16 ;
V_310 = & V_2 -> V_311 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_386 ; V_16 ++ ) {
V_2 -> V_387 [ V_16 ] . V_58 =
F_21 ( V_2 -> V_387 [ V_16 ] . V_46 ,
V_2 -> V_324 , V_310 -> V_313 ) ;
if ( V_2 -> V_387 [ V_16 ] . V_58 < 0 )
return false ;
}
for ( V_16 = 1 ; V_16 < V_2 -> V_386 ; V_16 ++ )
F_231 ( V_19 ,
V_2 -> V_387 [ V_16 ] . V_46 ,
V_399 ,
F_224 ) ;
return true ;
}
static int F_233 ( const void * V_400 , const void * V_401 )
{
const struct V_402 * V_403 = V_400 ;
const struct V_402 * V_404 = V_401 ;
return ( int ) ( V_403 -> V_405 - V_404 -> V_405 ) ;
}
static int F_234 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
unsigned int V_406 ;
int V_16 , V_48 ;
if ( V_2 -> V_31 )
return 0 ;
V_406 = 0 ;
V_48 = 0 ;
for ( V_16 = 0 ; V_16 < V_139 -> V_182 ; V_16 ++ ) {
T_1 V_50 = V_139 -> V_183 [ V_16 ] . V_46 ;
unsigned int V_405 ;
V_405 = F_106 ( V_19 , V_50 ) ;
V_405 = F_154 ( V_405 ) ;
if ( V_406 & ( 1 << V_405 ) )
return 0 ;
switch ( V_405 ) {
case V_268 :
if ( V_139 -> V_183 [ V_16 ] . type != V_181 )
return 0 ;
break;
case V_407 :
return 0 ;
default:
if ( V_139 -> V_183 [ V_16 ] . type > V_180 )
return 0 ;
if ( ! V_2 -> V_32 &&
V_139 -> V_183 [ V_16 ] . type != V_181 )
return 0 ;
if ( ! F_230 ( V_19 , V_50 ) )
return 0 ;
break;
}
if ( V_48 >= V_408 )
return 0 ;
V_406 |= ( 1 << V_405 ) ;
V_2 -> V_387 [ V_48 ] . V_46 = V_50 ;
V_2 -> V_387 [ V_48 ] . V_405 = V_405 ;
V_48 ++ ;
}
if ( V_48 < 2 )
return 0 ;
V_2 -> V_386 = V_48 ;
F_235 ( V_2 -> V_387 , V_48 , sizeof( V_2 -> V_387 [ 0 ] ) ,
F_233 , NULL ) ;
if ( ! F_232 ( V_19 ) )
return 0 ;
V_2 -> V_346 = 1 ;
V_2 -> V_306 = 1 ;
V_2 -> V_260 [ 0 ] = V_2 -> V_387 [ 0 ] . V_58 ;
F_36 ( L_84 ,
V_2 -> V_387 [ 0 ] . V_46 ,
V_2 -> V_387 [ 1 ] . V_46 ,
V_2 -> V_387 [ 2 ] . V_46 ) ;
return 0 ;
}
unsigned int F_236 ( struct V_18 * V_19 ,
T_1 V_50 ,
unsigned int V_409 )
{
if ( V_409 != V_105 || V_50 == V_19 -> V_410 )
return V_409 ;
if ( F_39 ( F_40 ( V_19 , V_50 ) ) >= V_411 )
return V_409 ;
if ( F_70 ( V_19 , V_50 ) )
return V_409 ;
return V_109 ;
}
static void F_237 ( struct V_18 * V_19 , T_1 V_293 )
{
int V_16 , V_51 ;
const T_1 * V_65 ;
bool V_412 ;
V_51 = F_38 ( V_19 , V_293 , & V_65 ) ;
V_412 = F_51 ( V_19 , V_293 , V_84 ) ;
for ( V_16 = 0 ; V_16 < V_51 ; V_16 ++ ) {
if ( V_412 )
F_62 ( V_19 , V_293 ,
V_84 , V_16 ,
0xff , V_97 ) ;
else if ( F_53 ( V_19 , V_65 [ V_16 ] , V_83 ) )
F_62 ( V_19 , V_65 [ V_16 ] ,
V_83 , 0 ,
0xff , V_97 ) ;
}
}
int F_238 ( struct V_18 * V_19 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_193 ;
F_11 ( V_19 ) ;
if ( V_2 -> V_45 && ! V_2 -> V_104 )
V_2 -> V_104 = V_2 -> V_45 ;
if ( V_139 != & V_2 -> V_140 ) {
V_2 -> V_140 = * V_139 ;
V_139 = & V_2 -> V_140 ;
}
if ( ! V_2 -> V_204 )
V_2 -> V_204 = & V_413 ;
if ( ! V_2 -> V_205 )
V_2 -> V_205 = & V_414 ;
F_119 ( V_19 ) ;
if ( ! V_139 -> V_141 ) {
if ( V_139 -> V_355 || V_139 -> V_360 ) {
V_2 -> V_147 . V_246 = 2 ;
V_2 -> V_415 = 1 ;
goto V_416;
}
if ( ! V_139 -> V_182 && ! V_139 -> V_360 )
return 0 ;
}
if ( ! V_2 -> V_35 &&
V_139 -> V_152 == V_153 &&
V_139 -> V_141 <= V_139 -> V_143 ) {
V_139 -> V_144 = V_139 -> V_141 ;
memcpy ( V_139 -> V_203 , V_139 -> V_201 ,
sizeof( V_139 -> V_203 ) ) ;
V_139 -> V_141 = V_139 -> V_143 ;
memcpy ( V_139 -> V_201 , V_139 -> V_202 , sizeof( V_139 -> V_202 ) ) ;
V_139 -> V_143 = 0 ;
memset ( V_139 -> V_202 , 0 , sizeof( V_139 -> V_202 ) ) ;
V_139 -> V_152 = V_155 ;
}
V_193 = F_121 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_146 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_124 ( V_19 , V_139 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_127 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_128 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_137 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_149 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_153 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_188 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_2 -> V_247 = V_2 -> V_206 ;
if ( V_139 -> V_152 != V_153 )
V_2 -> V_247 = F_145 ( V_2 -> V_247 ,
V_139 -> V_144 * 2 ) ;
if ( V_139 -> V_152 != V_155 )
V_2 -> V_247 = F_145 ( V_2 -> V_247 ,
V_139 -> V_143 * 2 ) ;
V_2 -> V_147 . V_246 = F_145 ( V_2 -> V_206 ,
V_2 -> V_247 ) ;
V_193 = F_229 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_183 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_234 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
if ( ! V_2 -> V_346 && V_2 -> V_45 &&
V_2 -> V_40 &&
V_2 -> V_311 . V_313 > 1 &&
F_12 ( V_19 , L_20 ) < 0 ) {
V_193 = F_184 ( V_19 , V_2 -> V_45 ,
V_328 , V_2 -> V_307 ,
L_67 , 0 ) ;
if ( V_193 < 0 )
return V_193 ;
}
V_193 = F_208 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_211 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
if ( V_2 -> V_259 &&
( V_2 -> V_346 || V_2 -> V_311 . V_313 == 1 ||
V_2 -> V_41 ) ) {
V_193 = F_177 ( V_19 , V_2 -> V_259 ) ;
if ( V_193 < 0 )
return V_193 ;
}
if ( V_2 -> V_41 ) {
if ( V_139 -> V_152 != V_153 ) {
V_193 = F_163 ( V_19 , V_139 -> V_141 ,
V_139 -> V_201 ) ;
if ( V_193 < 0 )
return V_193 ;
}
if ( V_139 -> V_152 != V_155 ) {
V_193 = F_163 ( V_19 , V_139 -> V_143 ,
V_139 -> V_202 ) ;
if ( V_193 < 0 )
return V_193 ;
}
}
if ( V_2 -> V_45 )
F_237 ( V_19 , V_2 -> V_45 ) ;
V_416:
F_212 ( V_19 ) ;
if ( V_2 -> V_42 )
V_19 -> V_417 = F_236 ;
if ( ! V_2 -> V_415 && V_2 -> V_418 ) {
V_193 = F_239 ( V_19 , V_2 -> V_418 ) ;
if ( V_193 < 0 )
return V_193 ;
}
return 1 ;
}
int F_240 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_193 ;
if ( V_2 -> V_3 . V_17 ) {
V_193 = F_241 ( V_19 , V_2 -> V_3 . V_14 ) ;
if ( V_193 < 0 )
return V_193 ;
}
if ( V_2 -> V_147 . V_357 ) {
V_193 = F_242 ( V_19 ,
V_2 -> V_147 . V_357 ,
V_2 -> V_147 . V_357 ,
V_2 -> V_419 [ 1 ] . V_420 ) ;
if ( V_193 < 0 )
return V_193 ;
if ( ! V_2 -> V_415 ) {
V_193 = F_243 ( V_19 ,
& V_2 -> V_147 ) ;
if ( V_193 < 0 )
return V_193 ;
V_2 -> V_147 . V_421 = 1 ;
}
}
if ( V_2 -> V_362 ) {
V_193 = F_244 ( V_19 , V_2 -> V_362 ) ;
if ( V_193 < 0 )
return V_193 ;
}
if ( ! V_2 -> V_415 &&
! F_245 ( V_19 , L_85 ) ) {
V_193 = F_246 ( V_19 , L_85 ,
V_2 -> V_220 , V_422 ,
L_86 ) ;
if ( V_193 < 0 )
return V_193 ;
}
if ( ! V_2 -> V_415 &&
! F_245 ( V_19 , L_87 ) ) {
V_193 = F_247 ( V_19 , L_87 ,
NULL , V_422 ,
L_88 ,
true , & V_2 -> V_145 . V_381 ) ;
if ( V_193 < 0 )
return V_193 ;
if ( V_2 -> V_145 . V_146 ) {
F_248 ( V_19 , & V_2 -> V_145 ,
V_2 -> V_423 ) ;
F_249 ( & V_2 -> V_145 ) ;
}
}
F_7 ( V_2 ) ;
V_193 = F_250 ( V_19 , & V_2 -> V_140 ) ;
if ( V_193 < 0 )
return V_193 ;
return 0 ;
}
static void F_251 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
struct V_426 * V_427 ,
int V_428 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_429 )
V_2 -> V_429 ( V_425 , V_19 , V_427 , V_428 ) ;
}
static void F_252 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
struct V_426 * V_427 ,
int V_428 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_430 )
V_2 -> V_430 ( V_425 , V_19 , V_427 , V_428 ) ;
}
static int F_253 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_193 ;
F_133 ( & V_2 -> V_9 ) ;
V_193 = F_254 ( V_19 ,
& V_2 -> V_147 , V_427 ,
V_425 ) ;
if ( ! V_193 ) {
V_2 -> V_232 |= 1 << V_431 ;
F_251 ( V_425 , V_19 , V_427 ,
V_432 ) ;
}
F_136 ( & V_2 -> V_9 ) ;
return V_193 ;
}
static int F_255 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
unsigned int V_433 ,
unsigned int V_434 ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_193 ;
V_193 = F_256 ( V_19 , & V_2 -> V_147 ,
V_433 , V_434 , V_427 ) ;
if ( ! V_193 )
F_251 ( V_425 , V_19 , V_427 ,
V_435 ) ;
return V_193 ;
}
static int F_257 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_193 ;
V_193 = F_258 ( V_19 , & V_2 -> V_147 ) ;
if ( ! V_193 )
F_251 ( V_425 , V_19 , V_427 ,
V_436 ) ;
return V_193 ;
}
static int F_259 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_133 ( & V_2 -> V_9 ) ;
V_2 -> V_232 &= ~ ( 1 << V_431 ) ;
F_251 ( V_425 , V_19 , V_427 ,
V_437 ) ;
F_136 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_260 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
struct V_426 * V_427 )
{
F_252 ( V_425 , V_19 , V_427 , V_432 ) ;
return 0 ;
}
static int F_261 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
unsigned int V_433 ,
unsigned int V_434 ,
struct V_426 * V_427 )
{
F_262 ( V_19 , V_425 -> V_50 , V_433 , 0 , V_434 ) ;
F_252 ( V_425 , V_19 , V_427 ,
V_435 ) ;
return 0 ;
}
static int F_263 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
struct V_426 * V_427 )
{
F_264 ( V_19 , V_425 -> V_50 ) ;
F_252 ( V_425 , V_19 , V_427 ,
V_436 ) ;
return 0 ;
}
static int F_265 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
struct V_426 * V_427 )
{
F_252 ( V_425 , V_19 , V_427 , V_437 ) ;
return 0 ;
}
static int F_266 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_193 = 0 ;
F_133 ( & V_2 -> V_9 ) ;
if ( ! V_2 -> V_229 )
V_193 = - V_233 ;
else
V_2 -> V_232 |= 1 << V_438 ;
F_251 ( V_425 , V_19 , V_427 ,
V_432 ) ;
F_136 ( & V_2 -> V_9 ) ;
return V_193 ;
}
static int F_267 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_133 ( & V_2 -> V_9 ) ;
V_2 -> V_232 &= ~ ( 1 << V_438 ) ;
F_251 ( V_425 , V_19 , V_427 ,
V_437 ) ;
F_136 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_268 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
unsigned int V_433 ,
unsigned int V_434 ,
struct V_426 * V_427 )
{
F_262 ( V_19 , V_425 -> V_50 , V_433 , 0 , V_434 ) ;
F_251 ( V_425 , V_19 , V_427 ,
V_435 ) ;
return 0 ;
}
static int F_269 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
struct V_426 * V_427 )
{
F_264 ( V_19 , V_425 -> V_50 ) ;
F_251 ( V_425 , V_19 , V_427 ,
V_436 ) ;
return 0 ;
}
static int F_270 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_271 ( V_19 , & V_2 -> V_147 ) ;
}
static int F_272 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
unsigned int V_433 ,
unsigned int V_434 ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_273 ( V_19 , & V_2 -> V_147 ,
V_433 , V_434 , V_427 ) ;
}
static int F_274 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_275 ( V_19 , & V_2 -> V_147 ) ;
}
static int F_276 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_277 ( V_19 , & V_2 -> V_147 ) ;
}
static int F_278 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
unsigned int V_433 ,
unsigned int V_434 ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_262 ( V_19 , V_2 -> V_304 [ V_427 -> V_439 + 1 ] ,
V_433 , 0 , V_434 ) ;
F_252 ( V_425 , V_19 , V_427 ,
V_435 ) ;
return 0 ;
}
static int F_279 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_264 ( V_19 ,
V_2 -> V_304 [ V_427 -> V_439 + 1 ] ) ;
F_252 ( V_425 , V_19 , V_427 ,
V_436 ) ;
return 0 ;
}
static bool F_213 ( struct V_18 * V_19 , int V_440 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_441 = V_2 -> V_304 [ V_2 -> V_314 [ V_440 ] ] ;
if ( V_2 -> V_442 && V_2 -> V_442 != V_441 ) {
F_280 ( V_19 , V_2 -> V_442 , 1 ) ;
V_2 -> V_442 = V_441 ;
F_262 ( V_19 , V_441 ,
V_2 -> V_443 , 0 ,
V_2 -> V_444 ) ;
return true ;
}
return false ;
}
static int F_281 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
unsigned int V_433 ,
unsigned int V_434 ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
V_2 -> V_442 = V_2 -> V_304 [ V_2 -> V_314 [ V_2 -> V_260 [ 0 ] ] ] ;
V_2 -> V_443 = V_433 ;
V_2 -> V_444 = V_434 ;
F_262 ( V_19 , V_2 -> V_442 , V_433 , 0 , V_434 ) ;
return 0 ;
}
static int F_282 ( struct V_424 * V_425 ,
struct V_18 * V_19 ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_264 ( V_19 , V_2 -> V_442 ) ;
V_2 -> V_442 = 0 ;
return 0 ;
}
static void F_283 ( char * V_445 , T_3 V_446 , const char * V_122 ,
const char * V_447 )
{
char * V_448 ;
if ( * V_445 )
return;
F_284 ( V_445 , V_447 , V_446 ) ;
for ( V_448 = strchr ( V_445 , ' ' ) ; V_448 ; V_448 = strchr ( V_448 + 1 , ' ' ) ) {
if ( ! isalnum ( V_448 [ 1 ] ) ) {
* V_448 = 0 ;
break;
}
}
F_35 ( V_445 , V_122 , V_446 ) ;
}
int F_285 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_449 * V_450 = V_2 -> V_419 ;
const struct V_424 * V_448 ;
bool V_451 ;
V_19 -> V_452 = 1 ;
V_19 -> V_453 = V_450 ;
if ( V_2 -> V_415 )
goto V_454;
F_283 ( V_2 -> V_455 ,
sizeof( V_2 -> V_455 ) ,
L_89 , V_19 -> V_447 ) ;
V_450 -> V_10 = V_2 -> V_455 ;
if ( V_2 -> V_147 . V_148 > 0 ) {
V_448 = V_2 -> V_456 ;
if ( ! V_448 )
V_448 = & V_457 ;
V_450 -> V_458 [ V_459 ] = * V_448 ;
V_450 -> V_458 [ V_459 ] . V_50 = V_2 -> V_147 . V_194 [ 0 ] ;
V_450 -> V_458 [ V_459 ] . V_460 =
V_2 -> V_147 . V_246 ;
if ( V_2 -> V_140 . V_152 == V_153 &&
V_2 -> V_140 . V_141 == 2 )
V_450 -> V_458 [ V_459 ] . V_461 =
V_462 ;
}
if ( V_2 -> V_306 ) {
V_448 = V_2 -> V_463 ;
if ( ! V_448 ) {
if ( V_2 -> V_315 )
V_448 = & V_464 ;
else
V_448 = & V_465 ;
}
V_450 -> V_458 [ V_466 ] = * V_448 ;
V_450 -> V_458 [ V_466 ] . V_50 = V_2 -> V_304 [ 0 ] ;
}
V_454:
if ( V_2 -> V_147 . V_357 || V_2 -> V_362 ) {
F_283 ( V_2 -> V_467 ,
sizeof( V_2 -> V_467 ) ,
L_90 , V_19 -> V_447 ) ;
V_19 -> V_452 = 2 ;
V_19 -> V_359 = V_2 -> V_147 . V_359 ;
V_450 = V_2 -> V_419 + 1 ;
V_450 -> V_10 = V_2 -> V_467 ;
if ( V_2 -> V_358 )
V_450 -> V_420 = V_2 -> V_358 ;
else
V_450 -> V_420 = V_468 ;
if ( V_2 -> V_147 . V_357 ) {
V_448 = V_2 -> V_469 ;
if ( ! V_448 )
V_448 = & V_470 ;
V_450 -> V_458 [ V_459 ] = * V_448 ;
V_450 -> V_458 [ V_459 ] . V_50 = V_2 -> V_147 . V_357 ;
}
if ( V_2 -> V_362 ) {
V_448 = V_2 -> V_471 ;
if ( ! V_448 )
V_448 = & V_472 ;
V_450 -> V_458 [ V_466 ] = * V_448 ;
V_450 -> V_458 [ V_466 ] . V_50 = V_2 -> V_362 ;
}
}
if ( V_2 -> V_415 )
return 0 ;
V_451 = ( V_2 -> V_306 > 1 ) &&
! V_2 -> V_315 && ! V_2 -> V_346 ;
if ( V_2 -> V_238 || V_451 ) {
F_283 ( V_2 -> V_473 ,
sizeof( V_2 -> V_473 ) ,
L_91 , V_19 -> V_447 ) ;
V_19 -> V_452 = 3 ;
V_450 = V_2 -> V_419 + 2 ;
V_450 -> V_10 = V_2 -> V_473 ;
if ( V_2 -> V_238 ) {
V_448 = V_2 -> V_474 ;
if ( ! V_448 )
V_448 = & V_475 ;
V_450 -> V_458 [ V_459 ] = * V_448 ;
V_450 -> V_458 [ V_459 ] . V_50 =
V_2 -> V_238 ;
} else {
V_450 -> V_458 [ V_459 ] =
V_476 ;
V_450 -> V_458 [ V_459 ] . V_50 = 0 ;
}
if ( V_451 ) {
V_448 = V_2 -> V_477 ;
if ( ! V_448 )
V_448 = & V_478 ;
V_450 -> V_458 [ V_466 ] = * V_448 ;
V_450 -> V_458 [ V_466 ] . V_50 =
V_2 -> V_304 [ 1 ] ;
V_450 -> V_458 [ V_466 ] . V_479 =
V_2 -> V_306 - 1 ;
} else {
V_450 -> V_458 [ V_466 ] =
V_476 ;
V_450 -> V_458 [ V_466 ] . V_50 = 0 ;
}
}
return 0 ;
}
static void F_286 ( struct V_18 * V_19 , int V_115 )
{
struct V_6 * V_52 ;
T_1 V_46 ;
V_52 = F_27 ( V_19 , V_115 ) ;
if ( ! V_52 || ! V_52 -> V_53 )
return;
V_46 = V_52 -> V_52 [ V_52 -> V_53 - 1 ] ;
F_14 ( V_19 , V_46 ) ;
F_65 ( V_19 , V_52 , V_52 -> V_90 ,
F_141 ( V_19 -> V_2 ) ) ;
F_73 ( V_19 , V_46 , V_52 -> V_90 ) ;
}
static void F_287 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_140 . V_141 ; V_16 ++ )
F_286 ( V_19 , V_2 -> V_187 [ V_16 ] ) ;
}
static void F_288 ( struct V_18 * V_19 , int V_163 , int * V_5 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_163 ; V_16 ++ )
F_286 ( V_19 , V_5 [ V_16 ] ) ;
}
static void F_289 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_140 . V_152 != V_155 )
F_288 ( V_19 , V_2 -> V_140 . V_143 , V_2 -> V_154 ) ;
if ( V_2 -> V_140 . V_152 != V_153 )
F_288 ( V_19 , V_2 -> V_140 . V_144 ,
V_2 -> V_156 ) ;
}
static void F_290 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_142 ; V_16 ++ ) {
T_1 V_46 = V_2 -> V_161 [ V_16 ] . V_46 ;
struct V_6 * V_52 ;
V_52 = F_140 ( V_19 , V_16 ) ;
if ( ! V_52 )
continue;
if ( ! V_2 -> V_161 [ V_16 ] . V_245 )
V_2 -> V_161 [ V_16 ] . V_245 =
F_16 ( V_19 , V_46 ) ;
F_65 ( V_19 , V_52 , V_52 -> V_90 ,
F_141 ( V_2 ) ) ;
}
}
static void F_291 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_236 )
return;
F_134 ( V_19 , V_2 -> V_237 , V_2 -> V_187 [ 0 ] ,
V_2 -> V_195 [ 0 ] ,
V_2 -> V_140 . V_152 ) ;
F_134 ( V_19 , V_2 -> V_237 , V_2 -> V_154 [ 0 ] ,
V_2 -> V_195 [ 1 ] ,
V_155 ) ;
F_134 ( V_19 , V_2 -> V_237 , V_2 -> V_156 [ 0 ] ,
V_2 -> V_195 [ 2 ] ,
V_153 ) ;
}
static void F_292 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_139 -> V_182 ; V_16 ++ ) {
T_1 V_50 = V_139 -> V_183 [ V_16 ] . V_46 ;
if ( F_181 ( V_19 , V_50 ) )
F_14 ( V_19 , V_50 ) ;
if ( V_2 -> V_45 ) {
F_76 ( V_19 , V_2 -> V_198 [ V_16 ] ) ;
F_76 ( V_19 , V_2 -> V_303 ) ;
}
}
}
static void F_293 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_309 * V_310 = & V_2 -> V_311 ;
struct V_6 * V_52 ;
int V_16 , V_322 , V_51 ;
if ( V_2 -> V_315 )
V_51 = 1 ;
else
V_51 = V_2 -> V_306 ;
for ( V_322 = 0 ; V_322 < V_51 ; V_322 ++ ) {
for ( V_16 = 0 ; V_16 < V_310 -> V_313 ; V_16 ++ ) {
V_52 = F_189 ( V_19 , V_322 , V_16 ) ;
if ( V_52 ) {
bool V_90 = V_52 -> V_90 ;
if ( V_16 == V_2 -> V_260 [ V_322 ] )
V_90 = true ;
F_65 ( V_19 , V_52 , V_90 , false ) ;
}
}
if ( V_2 -> V_43 )
F_150 ( V_19 , V_322 , true ) ;
}
if ( V_2 -> V_335 )
V_2 -> V_335 ( V_19 , NULL , NULL ) ;
}
static void F_294 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_46 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_140 . V_355 ; V_16 ++ )
F_286 ( V_19 , V_2 -> V_196 [ V_16 ] ) ;
V_46 = V_2 -> V_140 . V_360 ;
if ( V_46 ) {
F_14 ( V_19 , V_46 ) ;
F_76 ( V_19 , V_2 -> V_199 ) ;
}
}
static void F_295 ( struct V_18 * V_19 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_480 . V_17 ; V_16 ++ ) {
struct V_481 * V_46 = F_24 ( & V_19 -> V_480 , V_16 ) ;
T_1 V_50 = V_46 -> V_50 ;
if ( F_230 ( V_19 , V_50 ) &&
! F_296 ( V_19 , V_50 ) )
F_75 ( V_19 , V_50 , 0 ,
V_482 , 0 ) ;
}
}
int F_297 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_483 )
V_2 -> V_483 ( V_19 ) ;
F_298 ( V_19 ) ;
V_19 -> V_334 = 1 ;
F_287 ( V_19 ) ;
F_289 ( V_19 ) ;
F_290 ( V_19 ) ;
F_291 ( V_19 ) ;
F_292 ( V_19 ) ;
F_293 ( V_19 ) ;
F_294 ( V_19 ) ;
F_295 ( V_19 ) ;
F_143 ( V_19 ) ;
F_197 ( V_19 ) ;
if ( V_2 -> V_145 . V_381 && V_2 -> V_145 . V_146 )
F_249 ( & V_2 -> V_145 ) ;
F_299 ( V_19 , 0x01 ) ;
return 0 ;
}
void F_300 ( struct V_18 * V_19 )
{
F_301 ( V_19 ) ;
F_10 ( V_19 -> V_2 ) ;
F_8 ( V_19 -> V_2 ) ;
V_19 -> V_2 = NULL ;
}
int F_302 ( struct V_18 * V_19 , T_1 V_50 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_303 ( V_19 , & V_2 -> V_294 , V_50 ) ;
}
int F_304 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_193 ;
V_2 = F_305 ( sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 )
return - V_124 ;
F_1 ( V_2 ) ;
V_19 -> V_2 = V_2 ;
V_193 = F_306 ( V_19 , & V_2 -> V_140 , NULL , 0 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_238 ( V_19 , & V_2 -> V_140 ) ;
if ( V_193 < 0 )
goto error;
V_19 -> V_484 = V_485 ;
return 0 ;
error:
F_300 ( V_19 ) ;
return V_193 ;
}
