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
static void F_10 ( struct V_1 * V_2 )
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
static void F_34 ( struct V_18 * V_19 ,
const char * V_62 , struct V_6 * V_52 )
{
char V_63 [ 40 ] ;
char * V_64 = V_63 ;
int V_16 ;
* V_64 = 0 ;
for ( V_16 = 0 ; V_16 < V_52 -> V_53 ; V_16 ++ )
V_64 += F_35 ( V_64 , sizeof( V_63 ) - ( V_64 - V_63 ) , L_28 ,
V_64 != V_63 ? L_29 : L_30 ,
V_52 -> V_52 [ V_16 ] ) ;
F_36 ( V_19 , L_31 , V_62 , V_52 -> V_53 , V_63 ) ;
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
static bool F_47 ( struct V_18 * V_19 , T_1 V_80 ,
T_1 V_81 , int V_61 )
{
if ( ! ( F_40 ( V_19 , V_80 ) & ( 1 << ( V_61 + 1 ) ) ) )
return ! ( F_40 ( V_19 , V_81 ) & ( 1 << ( V_61 + 1 ) ) ) ;
return ( F_48 ( V_19 , V_80 , V_61 ) ==
F_48 ( V_19 , V_81 , V_61 ) ) ;
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
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = V_52 -> V_53 - 1 ; V_16 >= 0 ; V_16 -- ) {
T_1 V_50 = V_52 -> V_52 [ V_16 ] ;
if ( ( V_2 -> V_84 >> V_50 ) & 1 )
continue;
if ( F_52 ( V_19 , V_50 , V_82 ) )
return V_50 ;
}
return 0 ;
}
static bool F_53 ( struct V_18 * V_19 , struct V_6 * V_52 , int V_58 )
{
T_1 V_50 = V_52 -> V_52 [ V_58 ] ;
unsigned int V_85 = F_40 ( V_19 , V_50 ) ;
unsigned int type = F_39 ( V_85 ) ;
if ( ! ( V_85 & V_86 ) )
return false ;
if ( type == V_70 && V_58 > 0 )
return false ;
return true ;
}
static bool F_54 ( struct V_18 * V_19 , struct V_6 * V_52 , int V_58 )
{
T_1 V_50 = V_52 -> V_52 [ V_58 ] ;
unsigned int V_85 = F_40 ( V_19 , V_50 ) ;
unsigned int type = F_39 ( V_85 ) ;
if ( ! ( V_85 & V_87 ) )
return false ;
if ( type == V_70 && ! V_58 )
return false ;
return true ;
}
static bool F_55 ( struct V_18 * V_19 , T_1 V_50 ,
unsigned int V_61 , unsigned int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_88 ;
for ( V_88 = 0 ; V_88 < V_2 -> V_5 . V_17 ; V_88 ++ ) {
struct V_6 * V_52 = F_24 ( & V_2 -> V_5 , V_88 ) ;
if ( ! V_52 -> V_89 )
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
int V_61 , unsigned int V_85 , bool V_90 )
{
unsigned int V_20 = 0 ;
if ( V_85 & V_91 ) {
if ( V_90 )
V_20 = ( V_85 & V_92 ) >> V_93 ;
}
if ( V_85 & ( V_94 | V_95 ) ) {
if ( ! V_90 )
V_20 |= V_96 ;
}
return V_20 ;
}
static void F_57 ( struct V_18 * V_19 , T_1 V_50 , int V_61 , int V_58 )
{
unsigned int V_85 = F_48 ( V_19 , V_50 , V_61 ) ;
int V_20 = F_56 ( V_19 , V_50 , V_61 , V_85 , false ) ;
F_58 ( V_19 , V_50 , V_61 , V_58 , 0xff , V_20 ) ;
}
static unsigned int F_59 ( struct V_18 * V_19 ,
T_1 V_50 , int V_61 , int V_58 ,
unsigned int V_85 )
{
unsigned int V_97 = 0xff ;
if ( V_85 & ( V_94 | V_95 ) ) {
if ( F_32 ( V_19 , V_50 , V_61 , V_58 , V_98 ) )
V_97 &= ~ 0x80 ;
}
if ( V_85 & V_91 ) {
if ( F_32 ( V_19 , V_50 , V_61 , V_58 , V_99 ) ||
F_32 ( V_19 , V_50 , V_61 , V_58 , V_100 ) )
V_97 &= ~ 0x7f ;
}
return V_97 ;
}
static void F_60 ( struct V_18 * V_19 , T_1 V_50 , int V_61 ,
int V_58 , int V_101 , bool V_90 )
{
unsigned int V_85 ;
unsigned int V_97 , V_20 ;
if ( ! V_90 && F_55 ( V_19 , V_50 , V_61 , V_101 ) )
return;
V_85 = F_48 ( V_19 , V_50 , V_61 ) ;
V_20 = F_56 ( V_19 , V_50 , V_61 , V_85 , V_90 ) ;
V_97 = F_59 ( V_19 , V_50 , V_61 , V_101 , V_85 ) ;
if ( ! V_97 )
return;
V_20 &= V_97 ;
F_61 ( V_19 , V_50 , V_61 , V_58 , V_97 , V_20 ) ;
}
static void F_62 ( struct V_18 * V_19 , struct V_6 * V_52 ,
int V_16 , bool V_90 )
{
T_1 V_50 = V_52 -> V_52 [ V_16 ] ;
F_57 ( V_19 , V_50 , V_82 , 0 ) ;
F_60 ( V_19 , V_50 , V_82 , 0 , 0 , V_90 ) ;
}
static void F_63 ( struct V_18 * V_19 , struct V_6 * V_52 ,
int V_16 , bool V_90 , bool V_102 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const T_1 * V_65 ;
int V_88 , V_51 , V_58 ;
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
for ( V_88 = 0 ; V_88 < V_51 ; V_88 ++ )
F_57 ( V_19 , V_50 , V_83 , V_88 ) ;
for ( V_88 = 0 ; V_88 < V_51 ; V_88 ++ ) {
if ( V_88 != V_58 && ( ! V_102 || V_65 [ V_88 ] != V_2 -> V_103 ) )
continue;
F_60 ( V_19 , V_50 , V_83 , V_88 , V_58 , V_90 ) ;
}
}
void F_64 ( struct V_18 * V_19 , struct V_6 * V_52 ,
bool V_90 , bool V_102 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
if ( ! V_90 )
V_52 -> V_89 = false ;
for ( V_16 = V_52 -> V_53 - 1 ; V_16 >= 0 ; V_16 -- ) {
T_1 V_50 = V_52 -> V_52 [ V_16 ] ;
if ( V_90 && V_2 -> V_42 ) {
if ( ! F_65 ( V_19 , V_50 , V_104 ) )
F_66 ( V_19 , V_50 , 0 ,
V_105 ,
V_104 ) ;
}
if ( V_90 && V_52 -> V_72 [ V_16 ] )
F_67 ( V_19 , V_50 , 0 ,
V_106 ,
V_52 -> V_58 [ V_16 ] ) ;
if ( F_53 ( V_19 , V_52 , V_16 ) )
F_63 ( V_19 , V_52 , V_16 , V_90 , V_102 ) ;
if ( F_54 ( V_19 , V_52 , V_16 ) )
F_62 ( V_19 , V_52 , V_16 , V_90 ) ;
}
if ( V_90 )
V_52 -> V_89 = true ;
}
static void F_68 ( struct V_18 * V_19 , struct V_6 * V_52 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_107 = false ;
int V_16 ;
if ( ! V_2 -> V_42 || V_52 -> V_89 )
return;
for ( V_16 = 0 ; V_16 < V_52 -> V_53 ; V_16 ++ ) {
T_1 V_50 = V_52 -> V_52 [ V_16 ] ;
if ( ! F_65 ( V_19 , V_50 , V_108 ) &&
! F_69 ( V_19 , V_50 ) ) {
F_66 ( V_19 , V_50 , 0 ,
V_105 ,
V_108 ) ;
V_107 = true ;
}
}
if ( V_107 ) {
F_70 ( 10 ) ;
F_71 ( V_19 , V_52 -> V_52 [ 0 ] , 0 ,
V_109 , 0 ) ;
}
}
static void F_72 ( struct V_18 * V_19 , T_1 V_46 , bool V_90 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_110 ||
! ( F_73 ( V_19 , V_46 ) & V_111 ) )
return;
if ( V_2 -> V_112 && ! V_90 )
return;
if ( V_19 -> V_24 )
V_90 = ! V_90 ;
F_67 ( V_19 , V_46 , 0 ,
V_113 ,
V_90 ? 0x02 : 0x00 ) ;
}
static void F_74 ( struct V_18 * V_19 , int V_114 )
{
struct V_6 * V_52 = F_27 ( V_19 , V_114 ) ;
if ( V_52 )
F_64 ( V_19 , V_52 , V_52 -> V_89 , false ) ;
}
static struct V_4 *
F_75 ( struct V_1 * V_2 , int type , const char * V_10 ,
int V_115 , unsigned long V_20 )
{
struct V_4 * V_12 ;
V_12 = F_4 ( V_2 , V_10 , & V_116 [ type ] ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_117 = V_115 ;
if ( F_76 ( V_20 ) )
V_12 -> V_118 = V_119 ;
V_12 -> V_120 = V_20 ;
return V_12 ;
}
static int F_77 ( struct V_1 * V_2 , int type ,
const char * V_62 , const char * V_61 ,
const char * V_121 , int V_115 , unsigned long V_20 )
{
char V_10 [ V_122 ] ;
snprintf ( V_10 , sizeof( V_10 ) , L_32 , V_62 , V_61 , V_121 ) ;
if ( ! F_75 ( V_2 , type , V_10 , V_115 , V_20 ) )
return - V_123 ;
return 0 ;
}
static int F_78 ( struct V_18 * V_19 , const char * V_62 , int V_115 ,
unsigned int V_79 , struct V_6 * V_52 )
{
unsigned int V_20 ;
if ( ! V_52 )
return 0 ;
V_20 = V_52 -> V_60 [ V_99 ] ;
if ( ! V_20 )
return 0 ;
V_20 = F_46 ( V_20 , V_79 ) ;
return F_79 ( V_19 -> V_2 , V_124 , V_62 , V_115 , V_20 ) ;
}
static int F_80 ( struct V_18 * V_19 , struct V_6 * V_52 ,
int type )
{
int V_79 = 1 ;
if ( V_52 ) {
T_1 V_50 = F_76 ( V_52 -> V_60 [ type ] ) ;
if ( V_50 && ( F_40 ( V_19 , V_50 ) & V_125 ) )
V_79 = 3 ;
}
return V_79 ;
}
static int F_81 ( struct V_18 * V_19 , const char * V_62 , int V_115 ,
struct V_6 * V_52 )
{
int V_79 = F_80 ( V_19 , V_52 , V_99 ) ;
return F_78 ( V_19 , V_62 , V_115 , V_79 , V_52 ) ;
}
static int F_82 ( struct V_18 * V_19 , const char * V_62 , int V_115 ,
unsigned int V_79 , struct V_6 * V_52 )
{
unsigned int V_20 ;
int type = V_126 ;
if ( ! V_52 )
return 0 ;
V_20 = V_52 -> V_60 [ V_98 ] ;
if ( ! V_20 )
return 0 ;
V_20 = F_46 ( V_20 , V_79 ) ;
if ( F_83 ( V_20 ) == V_83 ) {
T_1 V_50 = F_76 ( V_20 ) ;
int V_51 = F_84 ( V_19 , V_50 ) ;
if ( V_51 > 1 ) {
type = V_127 ;
V_20 |= V_51 << 19 ;
}
}
return F_85 ( V_19 -> V_2 , type , V_62 , V_115 , V_20 ) ;
}
static int F_86 ( struct V_18 * V_19 , const char * V_62 ,
int V_115 , struct V_6 * V_52 )
{
int V_79 = F_80 ( V_19 , V_52 , V_98 ) ;
return F_82 ( V_19 , V_62 , V_115 , V_79 , V_52 ) ;
}
static void F_87 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_33 ) {
T_1 V_50 = F_89 ( V_129 ) ;
bool V_132 = ! ( ( V_2 -> V_133 >> V_50 ) & 1 ) ;
V_131 -> V_134 . integer . V_134 [ 0 ] &= V_132 ;
V_131 -> V_134 . integer . V_134 [ 1 ] &= V_132 ;
}
}
static int F_90 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
F_87 ( V_129 , V_131 ) ;
return F_91 ( V_129 , V_131 ) ;
}
static int F_92 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
F_87 ( V_129 , V_131 ) ;
return F_93 ( V_129 , V_131 ) ;
}
static bool F_94 ( struct V_18 * V_19 , int V_114 , int V_135 )
{
struct V_6 * V_52 = F_27 ( V_19 , V_114 ) ;
return V_52 && V_52 -> V_60 [ V_135 ] ;
}
static const char * F_95 ( struct V_18 * V_19 , int V_136 ,
int * V_117 , int V_135 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
* V_117 = 0 ;
if ( V_138 -> V_140 == 1 && ! V_2 -> V_141 &&
! V_138 -> V_142 && ! V_138 -> V_143 )
return V_2 -> V_144 . V_145 ? L_33 : L_34 ;
if ( V_2 -> V_146 . V_147 == 1 && ! V_2 -> V_45 &&
! V_2 -> V_146 . V_148 [ 0 ] && ! V_2 -> V_146 . V_149 [ 0 ] )
return V_2 -> V_144 . V_145 ? L_33 : L_34 ;
if ( V_136 >= V_138 -> V_140 )
return V_150 [ V_136 ] ;
switch ( V_138 -> V_151 ) {
case V_152 :
if ( ! V_136 && V_138 -> V_142 &&
! F_94 ( V_19 , V_2 -> V_153 [ 0 ] , V_135 ) )
break;
if ( V_138 -> V_140 == 1 )
return L_35 ;
if ( V_138 -> V_140 == 2 )
return V_136 ? L_36 : L_35 ;
break;
case V_154 :
if ( ! V_136 && V_138 -> V_143 &&
! F_94 ( V_19 , V_2 -> V_155 [ 0 ] , V_135 ) )
break;
if ( V_136 && V_2 -> V_141 )
break;
* V_117 = V_136 ;
return L_37 ;
}
if ( V_138 -> V_140 == 1 && ! V_2 -> V_141 )
return L_33 ;
if ( V_136 >= F_96 ( V_150 ) ) {
F_97 () ;
return L_33 ;
}
return V_150 [ V_136 ] ;
}
static int F_98 ( struct V_18 * V_19 , struct V_6 * V_52 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_50 ;
unsigned int V_20 ;
int V_156 = 0 ;
if ( ! V_52 )
return V_157 * 2 ;
if ( V_52 -> V_60 [ V_99 ] ||
V_52 -> V_60 [ V_98 ] )
return 0 ;
V_50 = F_51 ( V_19 , V_52 ) ;
if ( V_50 ) {
V_20 = F_33 ( V_50 , 3 , 0 , V_82 ) ;
if ( V_2 -> V_158 )
V_20 |= V_159 ;
if ( F_31 ( V_19 , V_20 , V_99 ) )
V_156 += V_157 ;
else
V_52 -> V_60 [ V_99 ] = V_20 ;
} else
V_156 += V_157 ;
V_50 = F_49 ( V_19 , V_52 ) ;
if ( V_50 ) {
unsigned int V_160 = F_39 ( F_40 ( V_19 , V_50 ) ) ;
if ( V_160 == V_70 || V_160 == V_66 ||
F_50 ( V_19 , V_50 , V_82 ) )
V_20 = F_33 ( V_50 , 3 , 0 , V_82 ) ;
else
V_20 = F_33 ( V_50 , 3 , 0 , V_83 ) ;
if ( F_31 ( V_19 , V_20 , V_98 ) )
V_156 += V_157 ;
else
V_52 -> V_60 [ V_98 ] = V_20 ;
} else
V_156 += V_157 ;
return V_156 ;
}
static T_1 F_99 ( struct V_18 * V_19 , int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
if ( V_138 -> V_140 > V_58 )
return V_2 -> V_161 [ V_58 ] ;
V_58 -= V_138 -> V_140 ;
if ( V_2 -> V_141 > V_58 )
return V_2 -> V_162 [ V_58 ] . V_163 ;
return 0 ;
}
static inline T_1 F_100 ( struct V_18 * V_19 ,
T_1 V_163 , T_1 V_46 )
{
return F_29 ( V_19 , V_163 , V_46 ) ? V_163 : 0 ;
}
static int F_101 ( struct V_18 * V_19 , int V_164 ,
const T_1 * V_49 , T_1 * V_165 ,
int * V_114 ,
const struct V_166 * V_167 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_168 ;
int V_156 = 0 ;
T_1 V_163 ;
if ( ! V_164 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_164 ; V_16 ++ ) {
struct V_6 * V_52 ;
T_1 V_46 = V_49 [ V_16 ] ;
V_52 = F_27 ( V_19 , V_114 [ V_16 ] ) ;
if ( V_52 ) {
V_156 += F_98 ( V_19 , V_52 ) ;
continue;
}
V_165 [ V_16 ] = F_44 ( V_19 , V_46 ) ;
if ( V_165 [ V_16 ] ) {
if ( F_28 ( V_19 , V_165 [ V_16 ] ) )
V_156 += V_167 -> V_169 ;
}
if ( ! V_165 [ V_16 ] )
V_165 [ V_16 ] = F_45 ( V_19 , V_46 , false ) ;
if ( ! V_165 [ V_16 ] && ! V_16 ) {
for ( V_168 = 1 ; V_168 < V_164 ; V_168 ++ ) {
if ( F_29 ( V_19 , V_165 [ V_168 ] , V_46 ) ) {
V_165 [ 0 ] = V_165 [ V_168 ] ;
V_165 [ V_168 ] = 0 ;
F_43 ( V_19 , V_114 [ V_168 ] ) ;
V_114 [ V_168 ] = 0 ;
break;
}
}
}
V_163 = V_165 [ V_16 ] ;
if ( ! V_163 ) {
if ( V_164 > 2 )
V_163 = F_100 ( V_19 , F_99 ( V_19 , V_16 ) , V_46 ) ;
if ( ! V_163 )
V_163 = F_100 ( V_19 , V_165 [ 0 ] , V_46 ) ;
if ( ! V_163 )
V_163 = F_100 ( V_19 , F_99 ( V_19 , V_16 ) , V_46 ) ;
if ( V_163 ) {
if ( ! V_16 )
V_156 += V_167 -> V_169 ;
else if ( V_16 == 1 )
V_156 += V_167 -> V_170 ;
else
V_156 += V_167 -> V_171 ;
} else if ( F_29 ( V_19 , V_2 -> V_161 [ 0 ] , V_46 ) ) {
V_163 = V_2 -> V_161 [ 0 ] ;
V_156 += V_167 -> V_172 ;
} else if ( ! V_16 )
V_156 += V_167 -> V_173 ;
else
V_156 += V_167 -> V_174 ;
}
if ( ! V_163 )
continue;
V_52 = F_42 ( V_19 , V_163 , V_46 , - V_2 -> V_45 ) ;
if ( ! V_52 && ! V_16 && V_2 -> V_45 ) {
V_52 = F_42 ( V_19 , V_163 , V_46 , 0 ) ;
}
if ( ! V_52 ) {
V_163 = V_165 [ V_16 ] = 0 ;
V_156 += V_167 -> V_174 ;
} else {
V_52 -> V_89 = true ;
V_114 [ V_16 ] = F_26 ( V_19 , V_52 ) ;
V_156 += F_98 ( V_19 , V_52 ) ;
}
}
return V_156 ;
}
static T_1 F_102 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_175 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_76 ; V_16 ++ ) {
T_1 V_50 = V_2 -> V_77 [ V_16 ] ;
if ( ! V_50 || F_28 ( V_19 , V_50 ) )
continue;
if ( F_29 ( V_19 , V_50 , V_46 ) ) {
if ( V_175 )
return 0 ;
V_175 = V_50 ;
}
}
return V_175 ;
}
static bool F_103 ( struct V_18 * V_19 ,
unsigned int V_176 , T_1 V_50 )
{
unsigned int V_177 , V_85 ;
V_177 = F_104 ( V_19 , V_50 ) ;
if ( F_105 ( V_177 ) != V_178 )
return false ;
if ( V_176 && F_106 ( V_177 ) != V_176 )
return false ;
V_85 = F_73 ( V_19 , V_50 ) ;
if ( ! ( V_85 & V_179 ) )
return false ;
return true ;
}
static int F_107 ( struct V_18 * V_19 , T_1 V_180 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
unsigned int V_177 = F_104 ( V_19 , V_180 ) ;
unsigned int V_176 = F_106 ( V_177 ) ;
int type , V_16 ;
int V_48 = 0 ;
for ( type = V_181 ; type >= V_182 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_138 -> V_183 ; V_16 ++ ) {
if ( V_138 -> V_184 [ V_16 ] . type != type )
continue;
if ( F_103 ( V_19 , V_176 ,
V_138 -> V_184 [ V_16 ] . V_46 ) )
V_48 ++ ;
}
}
return V_48 ;
}
static int F_108 ( struct V_18 * V_19 ,
T_1 V_180 ,
bool V_185 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
int type , V_16 , V_168 , V_48 , V_186 ;
unsigned int V_177 = F_104 ( V_19 , V_180 ) ;
unsigned int V_176 = F_106 ( V_177 ) ;
int V_156 = 0 ;
struct V_6 * V_52 ;
V_186 = V_2 -> V_141 ;
if ( V_186 >= 2 )
goto V_187;
V_48 = F_107 ( V_19 , V_180 ) ;
if ( V_48 < 2 )
goto V_187;
for ( type = V_181 ; type >= V_182 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_138 -> V_183 ; V_16 ++ ) {
T_1 V_50 = V_138 -> V_184 [ V_16 ] . V_46 ;
T_1 V_163 = 0 ;
if ( V_138 -> V_184 [ V_16 ] . type != type )
continue;
if ( ! F_103 ( V_19 , V_176 , V_50 ) )
continue;
for ( V_168 = 0 ; V_168 < V_2 -> V_141 ; V_168 ++ ) {
if ( V_50 == V_2 -> V_162 [ V_168 ] . V_46 )
break;
}
if ( V_168 < V_2 -> V_141 )
continue;
if ( V_185 )
V_163 = F_102 ( V_19 , V_50 ) ;
else if ( ! V_163 )
V_163 = F_45 ( V_19 , V_50 , false ) ;
if ( ! V_163 ) {
V_156 ++ ;
continue;
}
V_52 = F_42 ( V_19 , V_163 , V_50 ,
- V_2 -> V_45 ) ;
if ( ! V_52 ) {
V_156 ++ ;
continue;
}
V_2 -> V_162 [ V_2 -> V_141 ] . V_46 = V_50 ;
V_2 -> V_162 [ V_2 -> V_141 ] . V_163 = V_163 ;
V_2 -> V_188 [ V_138 -> V_140 + V_2 -> V_141 ] =
F_26 ( V_19 , V_52 ) ;
V_2 -> V_141 ++ ;
if ( V_2 -> V_141 >= 2 )
break;
}
}
V_187:
if ( V_156 )
V_156 = V_189 ;
if ( V_186 == V_2 -> V_141 ) {
if ( V_185 )
return 1 ;
else
return V_156 ;
}
if ( ! V_185 && V_2 -> V_141 < 2 ) {
V_2 -> V_5 . V_17 -= V_2 -> V_141 - V_186 ;
V_2 -> V_141 = V_186 ;
return V_156 ;
}
for ( V_16 = V_186 ; V_16 < V_2 -> V_141 ; V_16 ++ ) {
V_52 = F_27 ( V_19 , V_2 -> V_188 [ V_138 -> V_140 + V_16 ] ) ;
V_156 += F_98 ( V_19 , V_52 ) ;
}
return V_156 ;
}
static bool F_109 ( struct V_18 * V_19 , int V_190 ,
const T_1 * V_49 , T_1 * V_165 , int * V_114 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
bool V_67 = false ;
for ( V_16 = 0 ; V_16 < V_190 ; V_16 ++ ) {
struct V_6 * V_52 ;
T_1 V_163 ;
if ( V_165 [ V_16 ] )
continue;
V_163 = F_102 ( V_19 , V_49 [ V_16 ] ) ;
if ( ! V_163 )
continue;
V_52 = F_42 ( V_19 , V_163 , V_49 [ V_16 ] ,
- V_2 -> V_45 ) ;
if ( ! V_52 && ! V_16 && V_2 -> V_45 )
V_52 = F_42 ( V_19 , V_163 , V_49 [ V_16 ] , 0 ) ;
if ( V_52 ) {
V_165 [ V_16 ] = V_163 ;
V_67 = true ;
V_52 -> V_89 = true ;
V_114 [ V_16 ] = F_26 ( V_19 , V_52 ) ;
}
}
return V_67 ;
}
static int F_110 ( struct V_18 * V_19 , int V_114 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_52 ;
T_1 V_191 , V_163 , V_46 ;
V_52 = F_27 ( V_19 , V_114 ) ;
if ( ! V_52 || ! V_52 -> V_53 ||
F_22 ( V_52 , V_2 -> V_45 ) )
return 0 ;
V_191 = V_52 -> V_52 [ 0 ] ;
V_163 = V_2 -> V_161 [ 0 ] ;
V_46 = V_52 -> V_52 [ V_52 -> V_53 - 1 ] ;
V_52 = F_42 ( V_19 , V_163 , V_46 , V_2 -> V_45 ) ;
if ( ! V_52 ) {
if ( V_163 != V_191 )
V_163 = V_191 ;
else if ( V_2 -> V_146 . V_148 [ 0 ] )
V_163 = V_2 -> V_146 . V_148 [ 0 ] ;
else if ( V_2 -> V_146 . V_149 [ 0 ] )
V_163 = V_2 -> V_146 . V_149 [ 0 ] ;
else
V_163 = 0 ;
if ( V_163 )
V_52 = F_42 ( V_19 , V_163 , V_46 ,
V_2 -> V_45 ) ;
}
if ( ! V_52 )
return 0 ;
V_52 -> V_89 = false ;
return F_26 ( V_19 , V_52 ) ;
}
static bool F_111 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
struct V_6 * V_52 ;
int V_16 , V_58 ;
if ( V_138 -> V_151 == V_154 )
V_58 = V_2 -> V_188 [ 0 ] ;
else
V_58 = V_2 -> V_153 [ 0 ] ;
V_52 = F_27 ( V_19 , V_58 ) ;
if ( ! V_52 )
return false ;
if ( ! V_2 -> V_45 || ! F_22 ( V_52 , V_2 -> V_45 ) )
return true ;
for ( V_16 = 0 ; V_16 < V_138 -> V_140 ; V_16 ++ ) {
if ( V_2 -> V_188 [ V_16 ] == V_58 )
break;
V_52 = F_27 ( V_19 , V_2 -> V_188 [ V_16 ] ) ;
if ( V_52 && F_22 ( V_52 , V_2 -> V_45 ) )
return false ;
}
for ( V_16 = 0 ; V_16 < V_138 -> V_143 ; V_16 ++ ) {
V_52 = F_27 ( V_19 , V_2 -> V_155 [ V_16 ] ) ;
if ( V_52 && F_22 ( V_52 , V_2 -> V_45 ) )
return false ;
}
return true ;
}
static void F_112 ( struct V_18 * V_19 , int V_164 ,
T_1 * V_165 , int * V_114 )
{
struct V_6 * V_52 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_164 ; V_16 ++ ) {
if ( V_165 [ V_16 ] )
continue;
V_52 = F_27 ( V_19 , V_114 [ V_16 ] ) ;
if ( ! V_52 )
continue;
V_165 [ V_16 ] = V_52 -> V_52 [ 0 ] ;
}
}
static int F_113 ( struct V_18 * V_19 ,
bool V_192 ,
bool V_193 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
int V_16 , V_194 , V_156 ;
V_2 -> V_146 . V_147 = V_138 -> V_140 ;
V_2 -> V_146 . V_195 = V_2 -> V_161 ;
memset ( V_2 -> V_161 , 0 , sizeof( V_2 -> V_161 ) ) ;
memset ( V_2 -> V_146 . V_148 , 0 , sizeof( V_2 -> V_146 . V_148 ) ) ;
memset ( V_2 -> V_146 . V_149 , 0 , sizeof( V_2 -> V_146 . V_149 ) ) ;
V_2 -> V_141 = 0 ;
F_9 ( & V_2 -> V_5 ) ;
memset ( V_2 -> V_188 , 0 , sizeof( V_2 -> V_188 ) ) ;
memset ( V_2 -> V_153 , 0 , sizeof( V_2 -> V_153 ) ) ;
memset ( V_2 -> V_155 , 0 , sizeof( V_2 -> V_155 ) ) ;
memset ( V_2 -> V_196 , 0 , sizeof( V_2 -> V_196 ) ) ;
memset ( V_2 -> V_197 , 0 , sizeof( V_2 -> V_197 ) ) ;
memset ( V_2 -> V_198 , 0 , sizeof( V_2 -> V_198 ) ) ;
memset ( V_2 -> V_199 , 0 , sizeof( V_2 -> V_199 ) ) ;
memset ( & V_2 -> V_200 , 0 , sizeof( V_2 -> V_200 ) ) ;
V_156 = 0 ;
if ( V_192 ) {
bool V_201 ;
do {
V_201 = F_109 ( V_19 , V_138 -> V_140 ,
V_138 -> V_202 ,
V_2 -> V_161 ,
V_2 -> V_188 ) ;
V_201 |= F_109 ( V_19 , V_138 -> V_142 ,
V_138 -> V_203 ,
V_2 -> V_146 . V_148 ,
V_2 -> V_153 ) ;
V_201 |= F_109 ( V_19 , V_138 -> V_143 ,
V_138 -> V_204 ,
V_2 -> V_146 . V_149 ,
V_2 -> V_155 ) ;
if ( ! V_2 -> V_36 &&
V_193 && V_138 -> V_140 == 1 &&
V_138 -> V_151 != V_152 ) {
V_194 = F_108 ( V_19 , V_138 -> V_202 [ 0 ] , true ) ;
if ( ! V_194 )
V_201 = true ;
}
} while ( V_201 );
}
V_156 += F_101 ( V_19 , V_138 -> V_140 , V_138 -> V_202 ,
V_2 -> V_161 , V_2 -> V_188 ,
V_2 -> V_205 ) ;
if ( ! V_2 -> V_36 && V_193 &&
V_138 -> V_140 == 1 && V_138 -> V_151 != V_152 ) {
V_194 = F_108 ( V_19 , V_138 -> V_202 [ 0 ] , false ) ;
if ( V_194 < 0 )
return V_194 ;
}
if ( V_138 -> V_151 != V_154 ) {
V_194 = F_101 ( V_19 , V_138 -> V_142 , V_138 -> V_203 ,
V_2 -> V_146 . V_148 ,
V_2 -> V_153 ,
V_2 -> V_206 ) ;
if ( V_194 < 0 )
return V_194 ;
V_156 += V_194 ;
}
if ( V_138 -> V_151 != V_152 ) {
V_194 = F_101 ( V_19 , V_138 -> V_143 ,
V_138 -> V_204 ,
V_2 -> V_146 . V_149 ,
V_2 -> V_155 ,
V_2 -> V_206 ) ;
if ( V_194 < 0 )
return V_194 ;
V_156 += V_194 ;
}
if ( ! V_2 -> V_36 &&
V_138 -> V_140 == 1 && V_138 -> V_151 != V_152 ) {
V_194 = F_108 ( V_19 , V_138 -> V_202 [ 0 ] , false ) ;
if ( V_194 < 0 )
return V_194 ;
V_156 += V_194 ;
}
if ( V_2 -> V_45 ) {
V_2 -> V_196 [ 0 ] =
F_110 ( V_19 , V_2 -> V_188 [ 0 ] ) ;
if ( V_138 -> V_151 != V_154 )
V_2 -> V_196 [ 1 ] =
F_110 ( V_19 , V_2 -> V_153 [ 0 ] ) ;
if ( V_138 -> V_151 != V_152 )
V_2 -> V_196 [ 2 ] =
F_110 ( V_19 , V_2 -> V_155 [ 0 ] ) ;
}
if ( ! V_2 -> V_36 &&
V_138 -> V_142 && V_138 -> V_151 == V_152 )
if ( F_107 ( V_19 , V_138 -> V_203 [ 0 ] ) >= 2 )
V_2 -> V_141 = 1 ;
V_2 -> V_146 . V_147 = 0 ;
for ( V_16 = 0 ; V_16 < V_138 -> V_140 ; V_16 ++ ) {
if ( V_2 -> V_161 [ V_16 ] )
V_2 -> V_146 . V_147 ++ ;
else {
memmove ( V_2 -> V_161 + V_16 ,
V_2 -> V_161 + V_16 + 1 ,
sizeof( T_1 ) * ( V_138 -> V_140 - V_16 - 1 ) ) ;
V_2 -> V_161 [ V_138 -> V_140 - 1 ] = 0 ;
}
}
V_2 -> V_207 = V_2 -> V_208 =
V_2 -> V_146 . V_147 * 2 ;
if ( V_2 -> V_141 == 2 ) {
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
V_2 -> V_161 [ V_2 -> V_146 . V_147 ++ ] =
V_2 -> V_162 [ V_16 ] . V_163 ;
} else if ( V_2 -> V_141 ) {
V_2 -> V_141 = 0 ;
V_156 += V_189 ;
}
if ( V_2 -> V_39 && ! F_111 ( V_19 ) )
V_156 += V_209 ;
if ( V_138 -> V_151 != V_154 )
F_112 ( V_19 , V_138 -> V_142 ,
V_2 -> V_146 . V_148 ,
V_2 -> V_153 ) ;
if ( V_138 -> V_151 != V_152 )
F_112 ( V_19 , V_138 -> V_143 ,
V_2 -> V_146 . V_149 ,
V_2 -> V_155 ) ;
return V_156 ;
}
static inline void F_114 ( struct V_18 * V_19 ,
const char * V_62 , int V_58 )
{
struct V_6 * V_52 ;
V_52 = F_27 ( V_19 , V_58 ) ;
if ( V_52 )
F_34 ( V_19 , V_62 , V_52 ) ;
}
static void F_115 ( struct V_18 * V_19 ,
struct V_137 * V_138 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_210 [ 3 ] = { L_38 , L_39 , L_40 } ;
int V_16 ;
F_116 ( L_41 ,
V_138 -> V_202 [ 0 ] , V_138 -> V_202 [ 1 ] ,
V_138 -> V_202 [ 2 ] , V_138 -> V_202 [ 3 ] ,
V_2 -> V_146 . V_195 [ 0 ] ,
V_2 -> V_146 . V_195 [ 1 ] ,
V_2 -> V_146 . V_195 [ 2 ] ,
V_2 -> V_146 . V_195 [ 3 ] ,
V_210 [ V_138 -> V_151 ] ) ;
for ( V_16 = 0 ; V_16 < V_138 -> V_140 ; V_16 ++ )
F_114 ( V_19 , L_42 , V_2 -> V_188 [ V_16 ] ) ;
if ( V_2 -> V_141 > 0 )
F_116 ( L_43 ,
V_2 -> V_141 ,
V_2 -> V_162 [ 0 ] . V_46 , V_2 -> V_162 [ 1 ] . V_46 ,
V_2 -> V_162 [ 0 ] . V_163 , V_2 -> V_162 [ 1 ] . V_163 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_141 ; V_16 ++ )
F_114 ( V_19 , L_44 ,
V_2 -> V_188 [ V_138 -> V_140 + V_16 ] ) ;
if ( V_138 -> V_142 )
F_116 ( L_45 ,
V_138 -> V_203 [ 0 ] , V_138 -> V_203 [ 1 ] ,
V_138 -> V_203 [ 2 ] , V_138 -> V_203 [ 3 ] ,
V_2 -> V_146 . V_148 [ 0 ] ,
V_2 -> V_146 . V_148 [ 1 ] ,
V_2 -> V_146 . V_148 [ 2 ] ,
V_2 -> V_146 . V_148 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_138 -> V_142 ; V_16 ++ )
F_114 ( V_19 , L_46 , V_2 -> V_153 [ V_16 ] ) ;
if ( V_138 -> V_143 )
F_116 ( L_47 ,
V_138 -> V_204 [ 0 ] , V_138 -> V_204 [ 1 ] ,
V_138 -> V_204 [ 2 ] , V_138 -> V_204 [ 3 ] ,
V_2 -> V_146 . V_149 [ 0 ] ,
V_2 -> V_146 . V_149 [ 1 ] ,
V_2 -> V_146 . V_149 [ 2 ] ,
V_2 -> V_146 . V_149 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_138 -> V_143 ; V_16 ++ )
F_114 ( V_19 , L_48 , V_2 -> V_155 [ V_16 ] ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ )
F_114 ( V_19 , L_49 , V_2 -> V_196 [ V_16 ] ) ;
}
static void F_117 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_50 = V_19 -> V_211 ;
V_2 -> V_76 = 0 ;
memset ( V_2 -> V_77 , 0 , sizeof( V_2 -> V_77 ) ) ;
for ( V_16 = 0 ; V_16 < V_19 -> V_212 ; V_16 ++ , V_50 ++ ) {
if ( F_39 ( F_40 ( V_19 , V_50 ) ) != V_66 )
continue;
if ( V_2 -> V_76 >= F_96 ( V_2 -> V_77 ) ) {
F_118 ( V_19 , L_50 ) ;
break;
}
V_2 -> V_77 [ V_2 -> V_76 ++ ] = V_50 ;
}
}
static int F_119 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
struct V_137 * V_213 ;
unsigned int V_20 ;
int V_214 = V_215 ;
int V_156 ;
bool V_192 = true , V_193 = true ;
bool V_216 = true , V_217 = true ;
bool V_218 = false ;
V_213 = F_120 ( sizeof( * V_213 ) , V_13 ) ;
if ( ! V_213 )
return - V_123 ;
* V_213 = * V_138 ;
for (; ; ) {
V_156 = F_113 ( V_19 , V_192 ,
V_193 ) ;
if ( V_156 < 0 ) {
F_8 ( V_213 ) ;
return V_156 ;
}
F_116 ( L_51 ,
V_138 -> V_151 , V_192 , V_193 ,
V_156 ) ;
F_115 ( V_19 , V_138 ) ;
if ( V_156 < V_214 ) {
V_214 = V_156 ;
* V_213 = * V_138 ;
V_216 = V_192 ;
V_217 = V_193 ;
}
if ( ! V_156 )
break;
V_193 = ! V_193 ;
if ( ! V_193 )
continue;
V_192 = ! V_192 ;
if ( ! V_192 )
continue;
if ( V_218 )
break;
V_218 = true ;
if ( V_138 -> V_143 > 0 &&
V_138 -> V_151 == V_154 ) {
V_138 -> V_142 = V_138 -> V_140 ;
memcpy ( V_138 -> V_203 , V_138 -> V_202 ,
sizeof( V_138 -> V_203 ) ) ;
V_138 -> V_140 = V_138 -> V_143 ;
memcpy ( V_138 -> V_202 , V_138 -> V_204 ,
sizeof( V_138 -> V_204 ) ) ;
V_138 -> V_143 = 0 ;
memset ( V_138 -> V_204 , 0 , sizeof( V_138 -> V_204 ) ) ;
V_138 -> V_151 = V_152 ;
V_192 = true ;
continue;
}
if ( V_138 -> V_142 > 0 &&
V_138 -> V_151 == V_152 ) {
V_138 -> V_143 = V_138 -> V_140 ;
memcpy ( V_138 -> V_204 , V_138 -> V_202 ,
sizeof( V_138 -> V_204 ) ) ;
V_138 -> V_140 = V_138 -> V_142 ;
memcpy ( V_138 -> V_202 , V_138 -> V_203 ,
sizeof( V_138 -> V_203 ) ) ;
V_138 -> V_142 = 0 ;
memset ( V_138 -> V_203 , 0 , sizeof( V_138 -> V_203 ) ) ;
V_138 -> V_151 = V_154 ;
V_192 = true ;
continue;
}
break;
}
if ( V_156 ) {
F_116 ( L_52 ) ;
* V_138 = * V_213 ;
F_113 ( V_19 , V_216 , V_217 ) ;
}
F_116 ( L_53 ,
V_138 -> V_151 , V_216 , V_217 ) ;
F_115 ( V_19 , V_138 ) ;
if ( V_138 -> V_202 [ 0 ] ) {
struct V_6 * V_52 ;
V_52 = F_27 ( V_19 , V_2 -> V_188 [ 0 ] ) ;
if ( V_52 )
V_2 -> V_219 = F_51 ( V_19 , V_52 ) ;
if ( V_2 -> V_219 ) {
F_121 ( V_19 , V_2 -> V_219 ,
V_82 , V_2 -> V_220 ) ;
if ( V_2 -> V_158 )
V_2 -> V_220 [ 3 ] |= V_221 ;
}
}
if ( V_2 -> V_222 || V_138 -> V_151 == V_154 )
V_20 = V_223 ;
else
V_20 = V_224 ;
F_20 ( V_19 , V_138 -> V_140 , V_138 -> V_202 , V_20 ) ;
if ( V_138 -> V_151 != V_154 )
F_20 ( V_19 , V_138 -> V_142 , V_138 -> V_203 , V_223 ) ;
if ( V_138 -> V_151 != V_152 ) {
V_20 = V_2 -> V_222 ? V_223 : V_224 ;
F_20 ( V_19 , V_138 -> V_143 ,
V_138 -> V_204 , V_20 ) ;
}
if ( V_2 -> V_39 && ! F_111 ( V_19 ) )
V_2 -> V_39 = 0 ;
F_8 ( V_213 ) ;
return 0 ;
}
static int F_122 ( struct V_18 * V_19 ,
const struct V_137 * V_138 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_194 , V_225 ;
V_225 = V_138 -> V_140 ;
if ( V_2 -> V_141 > 0 && V_138 -> V_140 < 3 )
V_225 += V_2 -> V_141 ;
for ( V_16 = 0 ; V_16 < V_225 ; V_16 ++ ) {
const char * V_10 ;
int V_117 ;
struct V_6 * V_52 ;
V_52 = F_27 ( V_19 , V_2 -> V_188 [ V_16 ] ) ;
if ( ! V_52 )
continue;
V_10 = F_95 ( V_19 , V_16 , & V_117 , V_99 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_54 ) ) {
V_194 = F_78 ( V_19 , L_55 , 0 , 1 , V_52 ) ;
if ( V_194 < 0 )
return V_194 ;
V_194 = F_78 ( V_19 , L_56 , 0 , 2 , V_52 ) ;
if ( V_194 < 0 )
return V_194 ;
} else {
V_194 = F_81 ( V_19 , V_10 , V_117 , V_52 ) ;
if ( V_194 < 0 )
return V_194 ;
}
V_10 = F_95 ( V_19 , V_16 , & V_117 , V_98 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_54 ) ) {
V_194 = F_82 ( V_19 , L_55 , 0 , 1 , V_52 ) ;
if ( V_194 < 0 )
return V_194 ;
V_194 = F_82 ( V_19 , L_56 , 0 , 2 , V_52 ) ;
if ( V_194 < 0 )
return V_194 ;
} else {
V_194 = F_86 ( V_19 , V_10 , V_117 , V_52 ) ;
if ( V_194 < 0 )
return V_194 ;
}
}
return 0 ;
}
static int F_123 ( struct V_18 * V_19 , int V_114 ,
const char * V_62 , int V_115 )
{
struct V_6 * V_52 ;
int V_194 ;
V_52 = F_27 ( V_19 , V_114 ) ;
if ( ! V_52 )
return 0 ;
V_194 = F_81 ( V_19 , V_62 , V_115 , V_52 ) ;
if ( V_194 < 0 )
return V_194 ;
V_194 = F_86 ( V_19 , V_62 , V_115 , V_52 ) ;
if ( V_194 < 0 )
return V_194 ;
return 0 ;
}
static int F_124 ( struct V_18 * V_19 , int V_48 ,
const int * V_5 , const char * V_62 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
const char * V_10 ;
char V_226 [ V_122 ] ;
int V_194 , V_58 = 0 ;
if ( V_48 == 2 && V_16 == 1 && ! strcmp ( V_62 , L_35 ) )
V_10 = L_36 ;
else if ( V_48 >= 3 ) {
snprintf ( V_226 , sizeof( V_226 ) , L_57 ,
V_62 , V_150 [ V_16 ] ) ;
V_10 = V_226 ;
} else {
V_10 = V_62 ;
V_58 = V_16 ;
}
V_194 = F_123 ( V_19 , V_5 [ V_16 ] , V_10 , V_58 ) ;
if ( V_194 < 0 )
return V_194 ;
}
return 0 ;
}
static int F_125 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_124 ( V_19 , V_2 -> V_139 . V_142 ,
V_2 -> V_153 ,
L_37 ) ;
}
static int F_126 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_124 ( V_19 , V_2 -> V_139 . V_143 ,
V_2 -> V_155 ,
L_35 ) ;
}
static int F_127 ( struct V_128 * V_129 ,
struct V_227 * V_228 )
{
return F_128 ( V_129 , V_228 ) ;
}
static int F_129 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_131 -> V_134 . V_229 . V_230 [ 0 ] = V_2 -> V_231 ;
return 0 ;
}
static int F_130 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_232 = V_131 -> V_134 . V_229 . V_230 [ 0 ] ;
int V_233 = 0 ;
F_131 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_234 ) {
V_233 = - V_235 ;
goto V_236;
}
if ( V_2 -> V_231 != V_232 ) {
T_1 * V_237 ;
if ( V_2 -> V_139 . V_151 == V_154 )
V_237 = & V_2 -> V_161 [ 0 ] ;
else
V_237 = & V_2 -> V_146 . V_148 [ 0 ] ;
if ( V_2 -> V_238 ) {
if ( V_2 -> V_139 . V_151 == V_154 )
F_132 ( V_19 , V_2 -> V_239 ,
V_2 -> V_188 [ 0 ] ,
V_2 -> V_196 [ 0 ] ,
V_2 -> V_139 . V_151 ) ;
else
F_132 ( V_19 , V_2 -> V_239 ,
V_2 -> V_153 [ 0 ] ,
V_2 -> V_196 [ 1 ] ,
V_154 ) ;
}
V_2 -> V_231 = V_232 ;
if ( V_2 -> V_231 )
* V_237 = 0 ;
else
* V_237 = V_2 -> V_240 ;
F_133 ( V_19 , NULL ) ;
V_233 = 1 ;
}
V_236:
F_134 ( & V_2 -> V_9 ) ;
return V_233 ;
}
static int F_135 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_163 ;
if ( ! V_2 -> V_39 )
return 0 ;
if ( V_2 -> V_139 . V_151 == V_154 )
V_163 = V_2 -> V_146 . V_195 [ 0 ] ;
else
V_163 = V_2 -> V_146 . V_148 [ 0 ] ;
if ( ! V_163 ) {
V_2 -> V_39 = 0 ;
return 0 ;
}
V_2 -> V_231 = false ;
V_2 -> V_240 = V_163 ;
if ( ! F_4 ( V_2 , NULL , & V_241 ) )
return - V_123 ;
return 0 ;
}
static int F_136 ( struct V_128 * V_129 ,
struct V_227 * V_228 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_79 ;
V_228 -> type = V_242 ;
V_228 -> V_243 = 1 ;
V_228 -> V_134 . V_229 . V_244 = V_2 -> V_141 + 1 ;
if ( V_228 -> V_134 . V_229 . V_230 > V_2 -> V_141 )
V_228 -> V_134 . V_229 . V_230 = V_2 -> V_141 ;
V_79 = V_228 -> V_134 . V_229 . V_230 * 2 + V_2 -> V_208 ;
sprintf ( V_228 -> V_134 . V_229 . V_10 , L_58 , V_79 ) ;
return 0 ;
}
static int F_137 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_131 -> V_134 . V_229 . V_230 [ 0 ] =
( V_2 -> V_207 - V_2 -> V_208 ) / 2 ;
return 0 ;
}
static inline struct V_6 *
F_138 ( struct V_18 * V_19 , int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_27 ( V_19 ,
V_2 -> V_188 [ V_2 -> V_139 . V_140 + V_58 ] ) ;
}
static bool F_139 ( struct V_1 * V_2 )
{
return ! V_2 -> V_238 || V_2 -> V_239 ;
}
static int F_140 ( struct V_18 * V_19 , int V_58 , bool V_245 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_50 = V_2 -> V_162 [ V_58 ] . V_46 ;
struct V_6 * V_52 ;
V_52 = F_138 ( V_19 , V_58 ) ;
if ( ! V_52 )
return - V_246 ;
if ( V_52 -> V_89 == V_245 )
return 0 ;
if ( V_245 ) {
F_17 ( V_19 , V_50 , V_224 , true ) ;
F_64 ( V_19 , V_52 , true , F_139 ( V_2 ) ) ;
F_72 ( V_19 , V_50 , true ) ;
} else {
F_72 ( V_19 , V_50 , false ) ;
F_64 ( V_19 , V_52 , false , F_139 ( V_2 ) ) ;
F_17 ( V_19 , V_50 , V_2 -> V_162 [ V_58 ] . V_247 , true ) ;
F_68 ( V_19 , V_52 ) ;
}
F_141 ( V_19 ) ;
return 0 ;
}
static int F_142 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_136 ;
V_136 = V_131 -> V_134 . V_229 . V_230 [ 0 ] ;
if ( V_136 < 0 || V_136 > V_2 -> V_141 )
return - V_246 ;
if ( V_136 == ( V_2 -> V_207 - V_2 -> V_208 ) / 2 )
return 0 ;
V_2 -> V_207 = V_136 * 2 + V_2 -> V_208 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_141 ; V_16 ++ )
F_140 ( V_19 , V_16 , V_16 < V_136 ) ;
V_2 -> V_146 . V_248 = F_143 ( V_2 -> V_207 ,
V_2 -> V_249 ) ;
if ( V_2 -> V_34 )
V_2 -> V_146 . V_147 = V_2 -> V_146 . V_248 / 2 ;
return 1 ;
}
static int F_144 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_141 > 0 ) {
if ( ! F_4 ( V_2 , NULL , & V_250 ) )
return - V_123 ;
}
return 0 ;
}
static int F_145 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_131 -> V_134 . V_229 . V_230 [ 0 ] = V_2 -> V_239 ;
return 0 ;
}
static void F_132 ( struct V_18 * V_19 , bool V_251 ,
int V_252 , int V_253 ,
int V_254 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_255 , * V_256 ;
V_255 = F_27 ( V_19 , V_252 ) ;
V_256 = F_27 ( V_19 , V_253 ) ;
if ( ! V_255 || ! V_256 )
return;
if ( V_254 == V_154 && V_2 -> V_231 &&
V_256 -> V_52 [ 0 ] != V_2 -> V_240 )
V_251 = false ;
if ( V_251 ) {
F_64 ( V_19 , V_255 , false , true ) ;
F_64 ( V_19 , V_256 , true , true ) ;
F_68 ( V_19 , V_255 ) ;
} else {
F_64 ( V_19 , V_256 , false , false ) ;
F_64 ( V_19 , V_255 , true , false ) ;
F_68 ( V_19 , V_256 ) ;
}
}
static int F_146 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = V_131 -> V_134 . V_229 . V_230 [ 0 ] ;
if ( V_20 == V_2 -> V_239 )
return 0 ;
V_2 -> V_239 = V_20 ;
F_132 ( V_19 , V_20 , V_2 -> V_188 [ 0 ] ,
V_2 -> V_196 [ 0 ] ,
V_2 -> V_139 . V_151 ) ;
F_132 ( V_19 , V_20 , V_2 -> V_153 [ 0 ] ,
V_2 -> V_196 [ 1 ] ,
V_154 ) ;
F_132 ( V_19 , V_20 , V_2 -> V_155 [ 0 ] ,
V_2 -> V_196 [ 2 ] ,
V_152 ) ;
return 1 ;
}
static int F_147 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_45 )
return 0 ;
if ( ! ( V_2 -> V_196 [ 0 ] || V_2 -> V_196 [ 1 ] ||
V_2 -> V_196 [ 2 ] ) )
return 0 ;
if ( ! F_4 ( V_2 , NULL , & V_257 ) )
return - V_123 ;
V_2 -> V_238 = 1 ;
return 0 ;
}
static void F_148 ( struct V_18 * V_19 , int V_258 , bool V_259 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_260 ;
unsigned int V_20 ;
T_1 V_46 ;
V_46 = V_2 -> V_261 ;
V_260 = V_2 -> V_262 [ V_258 ] == V_2 -> V_263 ;
if ( ! V_259 ) {
V_20 = F_16 ( V_19 , V_46 ) ;
if ( V_260 ) {
if ( V_20 & V_264 )
return;
} else {
if ( V_20 & V_224 )
return;
}
}
V_20 = F_149 ( V_19 , V_46 ) ;
if ( V_20 == V_265 && V_2 -> V_266 ) {
const T_1 V_267 = V_2 -> V_266 ;
unsigned int V_268 = F_149 ( V_19 , V_267 ) ;
if ( V_268 != V_265 )
F_150 ( V_19 , V_267 ,
V_264 | ( V_260 ? V_268 : 0 ) ) ;
}
if ( ! V_2 -> V_269 ) {
if ( V_260 )
V_20 |= V_264 ;
else
V_20 = V_223 ;
F_17 ( V_19 , V_46 , V_20 , true ) ;
F_133 ( V_19 , NULL ) ;
}
}
static int F_151 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
unsigned int V_177 ;
T_1 V_50 ;
if ( ! V_2 -> V_43 ) {
if ( V_2 -> V_44 )
return 0 ;
if ( V_138 -> V_183 > 1 )
return 0 ;
else if ( V_138 -> V_183 == 1 ) {
V_177 = F_104 ( V_19 , V_138 -> V_184 [ 0 ] . V_46 ) ;
if ( F_152 ( V_177 ) != V_270 )
return 0 ;
}
}
V_2 -> V_43 = 0 ;
if ( V_138 -> V_183 >= V_271 )
return 0 ;
V_50 = 0 ;
if ( V_138 -> V_151 == V_154 && V_138 -> V_140 > 0 )
V_50 = V_138 -> V_202 [ 0 ] ;
else if ( V_138 -> V_142 > 0 )
V_50 = V_138 -> V_203 [ 0 ] ;
if ( ! V_50 )
return 0 ;
if ( ! ( F_73 ( V_19 , V_50 ) & V_272 ) )
return 0 ;
V_138 -> V_184 [ V_138 -> V_183 ] . V_46 = V_50 ;
V_138 -> V_184 [ V_138 -> V_183 ] . type = V_182 ;
V_138 -> V_184 [ V_138 -> V_183 ] . V_273 = 1 ;
V_138 -> V_183 ++ ;
V_2 -> V_43 = 1 ;
V_2 -> V_261 = V_50 ;
V_2 -> V_31 = 1 ;
F_36 ( V_19 , L_59 , V_50 ) ;
return 0 ;
}
static int F_153 ( struct V_128 * V_129 ,
struct V_227 * V_228 )
{
return F_154 ( V_129 , V_228 , 2 , V_274 ) ;
}
static int F_155 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
T_1 V_50 = V_129 -> V_120 ;
if ( F_16 ( V_19 , V_50 ) == V_223 )
V_131 -> V_134 . V_229 . V_230 [ 0 ] = 1 ;
else
V_131 -> V_134 . V_229 . V_230 [ 0 ] = 0 ;
return 0 ;
}
static int F_156 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
T_1 V_50 = V_129 -> V_120 ;
unsigned int V_20 ;
V_20 = V_131 -> V_134 . V_229 . V_230 [ 0 ] ? V_223 : V_224 ;
if ( F_16 ( V_19 , V_50 ) == V_20 )
return 0 ;
F_150 ( V_19 , V_50 , V_20 ) ;
return 1 ;
}
static bool F_157 ( struct V_18 * V_19 , const char * V_10 , int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_3 . V_17 ; V_16 ++ ) {
struct V_4 * V_15 = F_24 ( & V_2 -> V_3 , V_16 ) ;
if ( ! strcmp ( V_15 -> V_10 , V_10 ) && V_15 -> V_117 == V_58 )
return true ;
}
return false ;
}
static void F_158 ( struct V_18 * V_19 , T_1 V_46 ,
char * V_10 , T_3 V_275 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_58 = 0 ;
F_159 ( V_19 , V_46 , & V_2 -> V_139 , V_10 , V_275 , & V_58 ) ;
F_160 ( V_10 , L_60 , V_275 ) ;
for (; F_157 ( V_19 , V_10 , V_58 ) ; V_58 ++ )
;
}
static int F_161 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_41 ) {
unsigned int V_276 = F_73 ( V_19 , V_46 ) ;
if ( ( V_276 & V_179 ) && ( V_276 & V_277 ) )
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
if ( V_46 == V_2 -> V_261 )
continue;
if ( F_161 ( V_19 , V_46 ) > 1 ) {
struct V_4 * V_12 ;
char V_10 [ V_122 ] ;
F_158 ( V_19 , V_46 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 ,
& V_278 ) ;
if ( ! V_12 )
return - V_123 ;
V_12 -> V_120 = V_46 ;
}
}
return 0 ;
}
static unsigned int F_163 ( struct V_18 * V_19 , T_1 V_46 )
{
unsigned int V_276 ;
V_276 = F_73 ( V_19 , V_46 ) ;
V_276 = ( V_276 & V_279 ) >> V_280 ;
V_276 &= ~ ( V_281 | V_282 ) ;
return V_276 ;
}
static int F_164 ( unsigned int V_283 , unsigned int V_284 )
{
unsigned int V_16 , V_88 = 0 ;
for ( V_16 = 0 ; V_16 < V_285 ; V_16 ++ ) {
if ( V_283 & ( 1 << V_16 ) ) {
if ( V_88 == V_284 )
return V_16 ;
V_88 ++ ;
}
}
return 0 ;
}
static int F_165 ( unsigned int V_283 , unsigned int V_58 )
{
unsigned int V_16 , V_88 = 0 ;
for ( V_16 = 0 ; V_16 < V_285 ; V_16 ++ ) {
if ( V_16 == V_58 )
return V_88 ;
if ( V_283 & ( 1 << V_16 ) )
V_88 ++ ;
}
return 0 ;
}
static int F_166 ( struct V_128 * V_129 ,
struct V_227 * V_228 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
T_1 V_50 = V_129 -> V_120 ;
unsigned int V_283 = F_163 ( V_19 , V_50 ) ;
F_154 ( V_129 , V_228 , F_167 ( V_283 ) ,
V_286 ) ;
strcpy ( V_228 -> V_134 . V_229 . V_10 ,
V_286 [ F_164 ( V_283 , V_228 -> V_134 . V_229 . V_230 ) ] ) ;
return 0 ;
}
static int F_168 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
T_1 V_50 = V_129 -> V_120 ;
unsigned int V_283 = F_163 ( V_19 , V_50 ) ;
unsigned int V_58 ;
V_58 = F_16 ( V_19 , V_50 ) & V_287 ;
V_131 -> V_134 . V_229 . V_230 [ 0 ] = F_165 ( V_283 , V_58 ) ;
return 0 ;
}
static int F_169 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
T_1 V_50 = V_129 -> V_120 ;
unsigned int V_283 = F_163 ( V_19 , V_50 ) ;
unsigned int V_20 , V_58 ;
V_20 = F_16 ( V_19 , V_50 ) ;
V_58 = F_165 ( V_283 , V_20 & V_287 ) ;
if ( V_58 == V_131 -> V_134 . V_229 . V_230 [ 0 ] )
return 0 ;
V_20 &= ~ V_287 ;
V_20 |= F_164 ( V_283 , V_131 -> V_134 . V_229 . V_230 [ 0 ] ) ;
F_150 ( V_19 , V_50 , V_20 ) ;
return 1 ;
}
static int F_170 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_288 = 0 ;
if ( V_2 -> V_41 )
V_288 = F_167 ( F_163 ( V_19 , V_46 ) ) ;
return V_288 ? V_288 : 1 ;
}
static int F_171 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
char V_10 [ V_122 ] ;
unsigned int V_177 ;
if ( V_46 == V_2 -> V_261 )
return 0 ;
V_177 = F_104 ( V_19 , V_46 ) ;
if ( F_152 ( V_177 ) == V_270 )
return 0 ;
if ( F_170 ( V_19 , V_46 ) <= 1 )
return 0 ;
F_158 ( V_19 , V_46 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 , & V_289 ) ;
if ( ! V_12 )
return - V_123 ;
V_12 -> V_120 = V_46 ;
return 0 ;
}
static int F_172 ( struct V_128 * V_129 ,
struct V_227 * V_228 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
T_1 V_50 = V_129 -> V_120 ;
int V_290 = F_161 ( V_19 , V_50 ) ;
int V_291 = F_170 ( V_19 , V_50 ) ;
const char * V_292 = NULL ;
int V_58 ;
V_228 -> type = V_242 ;
V_228 -> V_243 = 1 ;
V_228 -> V_134 . V_229 . V_244 = V_290 + V_291 ;
if ( V_228 -> V_134 . V_229 . V_230 >= V_228 -> V_134 . V_229 . V_244 )
V_228 -> V_134 . V_229 . V_230 = V_228 -> V_134 . V_229 . V_244 - 1 ;
V_58 = V_228 -> V_134 . V_229 . V_230 ;
if ( V_58 < V_290 ) {
if ( V_290 > 1 )
V_292 = V_274 [ V_58 ] ;
else
V_292 = L_61 ;
} else {
V_58 -= V_290 ;
if ( V_291 > 1 ) {
unsigned int V_283 = F_163 ( V_19 , V_50 ) ;
V_292 = V_286 [ F_164 ( V_283 , V_58 ) ] ;
} else
V_292 = L_62 ;
}
strcpy ( V_228 -> V_134 . V_229 . V_10 , V_292 ) ;
return 0 ;
}
static int F_173 ( struct V_18 * V_19 , T_1 V_50 )
{
int V_290 = F_161 ( V_19 , V_50 ) ;
int V_291 = F_170 ( V_19 , V_50 ) ;
unsigned int V_20 = F_16 ( V_19 , V_50 ) ;
int V_58 = 0 ;
if ( V_20 & V_224 ) {
if ( V_290 > 1 && V_20 == V_223 )
V_58 = 1 ;
} else if ( V_20 & V_264 ) {
V_58 = V_290 ;
if ( V_291 > 1 ) {
unsigned int V_283 = F_163 ( V_19 , V_50 ) ;
V_20 &= V_287 ;
V_58 += F_165 ( V_283 , V_20 ) ;
}
}
return V_58 ;
}
static int F_174 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
T_1 V_50 = V_129 -> V_120 ;
V_131 -> V_134 . V_229 . V_230 [ 0 ] =
F_173 ( V_19 , V_50 ) ;
return 0 ;
}
static int F_175 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
T_1 V_50 = V_129 -> V_120 ;
int V_290 = F_161 ( V_19 , V_50 ) ;
int V_291 = F_170 ( V_19 , V_50 ) ;
unsigned int V_20 , V_293 , V_58 ;
V_293 = F_173 ( V_19 , V_50 ) ;
V_58 = V_131 -> V_134 . V_229 . V_230 [ 0 ] ;
if ( V_293 == V_58 )
return 0 ;
if ( V_58 < V_290 ) {
if ( V_290 > 1 )
V_20 = V_58 ? V_223 : V_224 ;
else
V_20 = V_223 ;
} else {
V_58 -= V_290 ;
if ( V_291 > 1 ) {
unsigned int V_283 = F_163 ( V_19 , V_50 ) ;
V_20 = F_16 ( V_19 , V_50 ) ;
V_20 &= ~ ( V_287 | V_223 ) ;
V_20 |= F_164 ( V_283 , V_58 ) | V_264 ;
} else
V_20 = F_149 ( V_19 , V_50 ) | V_264 ;
}
F_150 ( V_19 , V_50 , V_20 ) ;
F_133 ( V_19 , NULL ) ;
return 1 ;
}
static int F_176 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
V_12 = F_4 ( V_2 , L_63 ,
& V_294 ) ;
if ( ! V_12 )
return - V_123 ;
V_12 -> V_120 = V_46 ;
V_2 -> V_269 = 1 ;
return 0 ;
}
static int F_177 ( struct V_1 * V_2 , T_1 V_295 , int V_58 )
{
struct V_8 * V_14 ;
V_14 = F_5 ( & V_2 -> V_7 ) ;
if ( ! V_14 )
return - V_123 ;
V_14 -> V_50 = V_295 ;
V_14 -> V_61 = V_83 ;
V_14 -> V_58 = V_58 ;
V_2 -> V_296 . V_297 = V_2 -> V_7 . V_14 ;
return 0 ;
}
static bool F_178 ( struct V_18 * V_19 , T_1 V_298 ,
T_1 V_46 , unsigned int * V_299 ,
unsigned int * V_300 )
{
int V_58 , V_301 ;
const T_1 * V_14 ;
T_1 V_50 ;
V_58 = F_30 ( V_19 , V_298 , V_46 , true ) ;
if ( V_58 < 0 )
return false ;
* V_299 = * V_300 = 0 ;
if ( F_52 ( V_19 , V_298 , V_83 ) )
* V_299 = F_33 ( V_298 , 3 , V_58 , V_83 ) ;
if ( F_50 ( V_19 , V_298 , V_83 ) )
* V_300 = F_33 ( V_298 , 3 , V_58 , V_83 ) ;
if ( * V_299 && * V_300 )
return true ;
V_301 = F_38 ( V_19 , V_298 , & V_14 ) ;
if ( V_301 < V_58 )
return false ;
V_50 = V_14 [ V_58 ] ;
if ( ! * V_299 && F_52 ( V_19 , V_50 , V_82 ) &&
! F_32 ( V_19 , V_50 , V_82 , 0 , V_99 ) )
* V_299 = F_33 ( V_50 , 3 , 0 , V_82 ) ;
if ( ! * V_300 && F_50 ( V_19 , V_50 , V_82 ) &&
! F_32 ( V_19 , V_50 , V_82 , 0 , V_98 ) )
* V_300 = F_33 ( V_50 , 3 , 0 , V_82 ) ;
return * V_299 || * V_300 ;
}
static int F_179 ( struct V_18 * V_19 , int V_302 ,
T_1 V_46 , const char * V_303 , int V_304 ,
T_1 V_298 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_52 ;
unsigned int V_299 , V_300 ;
int V_194 , V_58 ;
if ( ! F_178 ( V_19 , V_298 , V_46 , & V_299 , & V_300 ) )
return 0 ;
V_52 = F_42 ( V_19 , V_46 , V_298 , 0 ) ;
if ( ! V_52 )
return - V_246 ;
F_34 ( V_19 , L_64 , V_52 ) ;
V_2 -> V_199 [ V_302 ] = F_26 ( V_19 , V_52 ) ;
V_58 = V_52 -> V_58 [ V_52 -> V_53 - 1 ] ;
if ( V_299 ) {
V_194 = F_79 ( V_2 , V_124 , V_303 , V_304 , V_299 ) ;
if ( V_194 < 0 )
return V_194 ;
V_52 -> V_60 [ V_99 ] = V_299 ;
}
if ( V_300 ) {
V_194 = F_85 ( V_2 , V_126 , V_303 , V_304 , V_300 ) ;
if ( V_194 < 0 )
return V_194 ;
V_52 -> V_60 [ V_98 ] = V_300 ;
}
V_52 -> V_89 = true ;
V_194 = F_177 ( V_2 , V_298 , V_58 ) ;
if ( V_194 < 0 )
return V_194 ;
if ( V_2 -> V_45 != V_2 -> V_103 &&
! V_2 -> V_305 ) {
V_52 = F_42 ( V_19 , V_2 -> V_45 ,
V_2 -> V_103 , 0 ) ;
if ( V_52 ) {
F_34 ( V_19 , L_65 , V_52 ) ;
V_52 -> V_89 = true ;
V_2 -> V_305 =
F_26 ( V_19 , V_52 ) ;
}
}
return 0 ;
}
static int F_180 ( struct V_18 * V_19 , T_1 V_50 )
{
unsigned int V_276 = F_73 ( V_19 , V_50 ) ;
return ( V_276 & V_272 ) != 0 ;
}
static int F_181 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_50 ;
T_1 * V_306 = V_2 -> V_306 ;
int V_307 = F_96 ( V_2 -> V_306 ) ;
int V_16 , V_51 = 0 ;
V_50 = V_19 -> V_211 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_212 ; V_16 ++ , V_50 ++ ) {
unsigned int V_85 = F_40 ( V_19 , V_50 ) ;
int type = F_39 ( V_85 ) ;
if ( type != V_69 || ( V_85 & V_78 ) )
continue;
V_306 [ V_51 ] = V_50 ;
if ( ++ V_51 >= V_307 )
break;
}
V_2 -> V_308 = V_51 ;
V_2 -> V_309 = V_51 ;
memcpy ( V_2 -> V_310 , V_2 -> V_306 , V_51 * sizeof( T_1 ) ) ;
return V_51 ;
}
static int F_182 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_311 * V_312 = & V_2 -> V_313 ;
unsigned int V_314 ;
int V_16 , V_88 , V_51 ;
V_51 = 0 ;
V_314 = 0 ;
for ( V_88 = 0 ; V_88 < V_2 -> V_308 ; V_88 ++ ) {
for ( V_16 = 0 ; V_16 < V_312 -> V_315 ; V_16 ++ ) {
if ( ! V_2 -> V_198 [ V_16 ] [ V_88 ] )
break;
}
if ( V_16 >= V_312 -> V_315 ) {
V_314 |= ( 1 << V_88 ) ;
V_51 ++ ;
}
}
if ( ! V_314 ) {
for ( V_16 = 0 ; V_16 < V_312 -> V_315 ; V_16 ++ ) {
for ( V_88 = 0 ; V_88 < V_2 -> V_308 ; V_88 ++ ) {
if ( V_2 -> V_198 [ V_16 ] [ V_88 ] ) {
V_2 -> V_316 [ V_16 ] = V_88 ;
break;
}
}
}
F_36 ( V_19 , L_66 ) ;
V_2 -> V_317 = 1 ;
} else if ( V_51 != V_2 -> V_308 ) {
V_51 = 0 ;
for ( V_88 = 0 ; V_88 < V_2 -> V_308 ; V_88 ++ ) {
if ( ! ( V_314 & ( 1 << V_88 ) ) )
continue;
if ( V_88 != V_51 ) {
V_2 -> V_306 [ V_51 ] = V_2 -> V_306 [ V_88 ] ;
for ( V_16 = 0 ; V_16 < V_312 -> V_315 ; V_16 ++ ) {
F_43 ( V_19 ,
V_2 -> V_198 [ V_16 ] [ V_51 ] ) ;
V_2 -> V_198 [ V_16 ] [ V_51 ] =
V_2 -> V_198 [ V_16 ] [ V_88 ] ;
}
}
V_51 ++ ;
}
V_2 -> V_308 = V_51 ;
}
if ( V_312 -> V_315 == 1 ||
( V_312 -> V_315 == 2 && V_2 -> V_43 ) ) {
F_36 ( V_19 , L_67 ) ;
V_2 -> V_308 = 1 ;
}
if ( ! V_2 -> V_317 && V_2 -> V_37 )
V_2 -> V_308 = 1 ;
return 0 ;
}
static int F_183 ( struct V_18 * V_19 , T_1 V_46 ,
int V_318 , int V_319 ,
const char * V_320 , int V_321 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_311 * V_312 = & V_2 -> V_313 ;
int V_322 = V_312 -> V_315 ;
bool V_323 = false ;
int V_324 ;
for ( V_324 = 0 ; V_324 < V_319 ; V_324 ++ ) {
struct V_6 * V_52 ;
T_1 V_325 = V_2 -> V_306 [ V_324 ] ;
if ( ! F_29 ( V_19 , V_46 , V_325 ) )
continue;
V_52 = F_42 ( V_19 , V_46 , V_325 , V_321 ) ;
if ( ! V_52 )
continue;
F_34 ( V_19 , L_68 , V_52 ) ;
V_2 -> V_198 [ V_322 ] [ V_324 ] =
F_26 ( V_19 , V_52 ) ;
if ( ! V_323 ) {
if ( V_2 -> V_261 == V_46 )
V_2 -> V_263 = V_312 -> V_315 ;
V_2 -> V_326 [ V_312 -> V_315 ] = V_46 ;
F_184 ( V_19 , V_312 , V_320 , V_318 , NULL ) ;
V_323 = true ;
if ( V_2 -> V_317 )
V_2 -> V_316 [ V_322 ] = V_324 ;
}
}
return 0 ;
}
static int F_185 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_137 * V_138 = & V_2 -> V_139 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_138 -> V_183 ; V_16 ++ ) {
T_1 V_46 = V_138 -> V_184 [ V_16 ] . V_46 ;
const char * V_320 ;
int V_168 , V_58 ;
if ( ! F_180 ( V_19 , V_46 ) )
continue;
V_320 = F_186 ( V_19 , V_138 , V_16 ) ;
V_58 = 0 ;
for ( V_168 = V_16 - 1 ; V_168 >= 0 ; V_168 -- ) {
if ( V_2 -> V_327 [ V_168 ] &&
! strcmp ( V_2 -> V_327 [ V_168 ] , V_320 ) ) {
V_58 = V_2 -> V_328 [ V_168 ] + 1 ;
break;
}
}
V_2 -> V_327 [ V_16 ] = V_320 ;
V_2 -> V_328 [ V_16 ] = V_58 ;
}
return 0 ;
}
static int F_187 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_137 * V_138 = & V_2 -> V_139 ;
T_1 V_329 = V_2 -> V_45 ;
int V_319 ;
int V_16 , V_194 ;
unsigned int V_20 ;
V_319 = F_181 ( V_19 ) ;
if ( V_319 < 0 )
return 0 ;
V_194 = F_185 ( V_19 ) ;
if ( V_194 < 0 )
return V_194 ;
for ( V_16 = 0 ; V_16 < V_138 -> V_183 ; V_16 ++ ) {
T_1 V_46 ;
V_46 = V_138 -> V_184 [ V_16 ] . V_46 ;
if ( ! F_180 ( V_19 , V_46 ) )
continue;
V_20 = V_264 ;
if ( V_138 -> V_184 [ V_16 ] . type == V_182 )
V_20 |= F_149 ( V_19 , V_46 ) ;
if ( V_46 != V_2 -> V_261 )
F_17 ( V_19 , V_46 , V_20 , false ) ;
if ( V_329 ) {
if ( F_29 ( V_19 , V_46 , V_329 ) ) {
V_194 = F_179 ( V_19 , V_16 , V_46 ,
V_2 -> V_327 [ V_16 ] ,
V_2 -> V_328 [ V_16 ] ,
V_329 ) ;
if ( V_194 < 0 )
return V_194 ;
}
}
V_194 = F_183 ( V_19 , V_46 , V_16 , V_319 ,
V_2 -> V_327 [ V_16 ] , - V_329 ) ;
if ( V_194 < 0 )
return V_194 ;
if ( V_2 -> V_41 ) {
V_194 = F_171 ( V_19 , V_46 ) ;
if ( V_194 < 0 )
return V_194 ;
}
}
if ( V_329 && V_2 -> V_40 &&
F_12 ( V_19 , L_20 ) > 0 ) {
V_194 = F_183 ( V_19 , V_329 , V_330 , V_319 ,
L_69 , 0 ) ;
if ( V_194 < 0 )
return V_194 ;
}
return 0 ;
}
static struct V_6 * F_188 ( struct V_18 * V_19 , int V_331 , int V_322 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_322 < 0 || V_322 >= V_332 ) {
F_97 () ;
return NULL ;
}
if ( V_2 -> V_317 )
V_331 = V_2 -> V_316 [ V_322 ] ;
if ( V_331 < 0 || V_331 >= V_271 ) {
F_97 () ;
return NULL ;
}
return F_27 ( V_19 , V_2 -> V_198 [ V_322 ] [ V_331 ] ) ;
}
static int F_189 ( struct V_128 * V_129 ,
struct V_227 * V_228 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
return F_190 ( & V_2 -> V_313 , V_228 ) ;
}
static int F_191 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_331 = F_192 ( V_129 , & V_131 -> V_333 ) ;
V_131 -> V_134 . V_229 . V_230 [ 0 ] = V_2 -> V_262 [ V_331 ] ;
return 0 ;
}
static int F_193 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
unsigned int V_331 = F_192 ( V_129 , & V_131 -> V_333 ) ;
return F_194 ( V_19 , V_331 ,
V_131 -> V_134 . V_229 . V_230 [ 0 ] ) ;
}
static int F_195 ( struct V_128 * V_129 ,
struct V_130 * V_131 ,
T_4 V_334 , int type )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_311 * V_312 ;
struct V_6 * V_52 ;
int V_16 , V_331 , V_194 = 0 ;
V_312 = & V_2 -> V_313 ;
V_331 = V_129 -> V_333 . V_117 ;
F_131 ( & V_19 -> V_335 ) ;
V_19 -> V_336 = 1 ;
for ( V_16 = 0 ; V_16 < V_312 -> V_315 ; V_16 ++ ) {
V_52 = F_188 ( V_19 , V_331 , V_16 ) ;
if ( ! V_52 || ! V_52 -> V_60 [ type ] )
continue;
V_129 -> V_120 = V_52 -> V_60 [ type ] ;
V_194 = V_334 ( V_129 , V_131 ) ;
if ( V_194 < 0 )
goto error;
}
error:
V_19 -> V_336 = 0 ;
F_134 ( & V_19 -> V_335 ) ;
F_196 ( V_19 ) ;
if ( V_194 >= 0 && V_2 -> V_337 )
V_2 -> V_337 ( V_19 , V_129 , V_131 ) ;
return V_194 ;
}
static int F_197 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
return F_195 ( V_129 , V_131 ,
V_338 ,
V_99 ) ;
}
static int F_198 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
return F_195 ( V_129 , V_131 ,
F_91 ,
V_98 ) ;
}
static int F_199 ( struct V_18 * V_19 , struct V_6 * V_52 )
{
T_1 V_50 ;
int V_16 , V_53 ;
V_52 -> V_60 [ V_99 ] = V_52 -> V_60 [ V_98 ] = 0 ;
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
if ( V_53 >= V_52 -> V_53 )
return - V_246 ;
V_16 = V_52 -> V_53 - V_53 - 1 ;
V_50 = V_52 -> V_52 [ V_16 ] ;
if ( ! V_52 -> V_60 [ V_99 ] ) {
if ( F_52 ( V_19 , V_50 , V_82 ) )
V_52 -> V_60 [ V_99 ] =
F_33 ( V_50 , 3 , 0 , V_82 ) ;
else if ( F_52 ( V_19 , V_50 , V_83 ) ) {
int V_58 = V_52 -> V_58 [ V_16 ] ;
if ( ! V_53 && V_19 -> V_29 )
V_58 = 0 ;
V_52 -> V_60 [ V_99 ] =
F_33 ( V_50 , 3 , V_58 , V_83 ) ;
}
}
if ( ! V_52 -> V_60 [ V_98 ] ) {
if ( F_50 ( V_19 , V_50 , V_82 ) )
V_52 -> V_60 [ V_98 ] =
F_33 ( V_50 , 3 , 0 , V_82 ) ;
else if ( F_50 ( V_19 , V_50 , V_83 ) ) {
int V_58 = V_52 -> V_58 [ V_16 ] ;
if ( ! V_53 && V_19 -> V_29 )
V_58 = 0 ;
V_52 -> V_60 [ V_98 ] =
F_33 ( V_50 , 3 , V_58 , V_83 ) ;
}
}
}
return 0 ;
}
static bool F_200 ( struct V_18 * V_19 , T_1 V_50 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
unsigned int V_20 ;
int V_16 ;
if ( ! V_2 -> V_38 )
return false ;
for ( V_16 = 0 ; V_16 < V_138 -> V_183 ; V_16 ++ ) {
if ( V_138 -> V_184 [ V_16 ] . V_46 != V_50 )
continue;
if ( V_138 -> V_184 [ V_16 ] . type != V_182 )
return false ;
V_20 = F_104 ( V_19 , V_50 ) ;
return F_152 ( V_20 ) == V_270 ;
}
return false ;
}
static int F_201 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_233 ;
V_233 = F_91 ( V_129 , V_131 ) ;
if ( V_233 < 0 )
return V_233 ;
if ( V_2 -> V_337 )
V_2 -> V_337 ( V_19 , V_129 , V_131 ) ;
return V_233 ;
}
static int F_202 ( struct V_18 * V_19 , const char * V_320 ,
int V_58 , bool V_339 , unsigned int V_340 ,
bool V_341 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
char V_342 [ V_122 ] ;
int type = V_339 ? V_126 : V_124 ;
const char * V_121 = V_339 ? L_70 : L_71 ;
unsigned int V_79 = V_341 ? 1 : 3 ;
struct V_4 * V_12 ;
if ( ! V_340 )
return 0 ;
if ( V_320 )
snprintf ( V_342 , sizeof( V_342 ) ,
L_72 , V_320 , V_121 ) ;
else
snprintf ( V_342 , sizeof( V_342 ) ,
L_73 , V_121 ) ;
V_12 = F_75 ( V_2 , type , V_342 , V_58 ,
F_46 ( V_340 , V_79 ) ) ;
if ( ! V_12 )
return - V_123 ;
if ( V_339 )
V_12 -> V_343 = F_201 ;
if ( ! V_341 )
return 0 ;
if ( V_320 )
snprintf ( V_342 , sizeof( V_342 ) ,
L_74 , V_320 , V_121 ) ;
else
snprintf ( V_342 , sizeof( V_342 ) ,
L_75 , V_121 ) ;
V_12 = F_75 ( V_2 , type , V_342 , V_58 ,
F_46 ( V_340 , 2 ) ) ;
if ( ! V_12 )
return - V_123 ;
if ( V_339 )
V_12 -> V_343 = F_201 ;
return 0 ;
}
static int F_203 ( struct V_18 * V_19 , int V_58 ,
unsigned int V_344 , unsigned int V_345 ,
bool V_341 )
{
int V_194 ;
V_194 = F_202 ( V_19 , NULL , V_58 , false , V_344 , V_341 ) ;
if ( V_194 < 0 )
return V_194 ;
V_194 = F_202 ( V_19 , NULL , V_58 , true , V_345 , V_341 ) ;
if ( V_194 < 0 )
return V_194 ;
return 0 ;
}
static int F_204 ( struct V_18 * V_19 , int V_58 ,
unsigned int V_344 , unsigned int V_345 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
if ( V_344 ) {
V_12 = F_4 ( V_2 , NULL , & V_346 ) ;
if ( ! V_12 )
return - V_123 ;
V_12 -> V_117 = V_58 ;
V_12 -> V_120 = V_344 ;
V_12 -> V_118 = V_119 ;
}
if ( V_345 ) {
V_12 = F_4 ( V_2 , NULL , & V_347 ) ;
if ( ! V_12 )
return - V_123 ;
V_12 -> V_117 = V_58 ;
V_12 -> V_120 = V_345 ;
V_12 -> V_118 = V_119 ;
}
return 0 ;
}
static unsigned int F_205 ( struct V_18 * V_19 , int V_58 , int type )
{
struct V_6 * V_52 ;
unsigned int V_340 ;
int V_16 ;
V_52 = F_188 ( V_19 , 0 , V_58 ) ;
if ( ! V_52 )
return 0 ;
V_340 = V_52 -> V_60 [ type ] ;
if ( ! V_340 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_58 - 1 ; V_16 ++ ) {
V_52 = F_188 ( V_19 , 0 , V_16 ) ;
if ( V_52 && V_52 -> V_60 [ type ] == V_340 )
return 0 ;
}
return V_340 ;
}
static int F_206 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_311 * V_312 = & V_2 -> V_313 ;
int V_16 , V_194 , type ;
for ( V_16 = 0 ; V_16 < V_312 -> V_315 ; V_16 ++ ) {
bool V_341 ;
int V_58 ;
V_58 = V_312 -> V_244 [ V_16 ] . V_117 ;
if ( V_58 >= V_2 -> V_139 . V_183 )
continue;
V_341 = F_200 ( V_19 , V_2 -> V_326 [ V_16 ] ) ;
for ( type = 0 ; type < 2 ; type ++ ) {
V_194 = F_202 ( V_19 ,
V_2 -> V_327 [ V_58 ] ,
V_2 -> V_328 [ V_58 ] ,
type ,
F_205 ( V_19 , V_16 , type ) ,
V_341 ) ;
if ( V_194 < 0 )
return V_194 ;
}
}
return 0 ;
}
static int F_207 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_311 * V_312 = & V_2 -> V_313 ;
int V_16 , V_88 , V_51 , V_194 ;
if ( V_2 -> V_317 )
V_51 = 1 ;
else
V_51 = V_2 -> V_308 ;
if ( ! V_2 -> V_348 && V_312 -> V_315 > 1 ) {
struct V_4 * V_12 ;
const char * V_10 ;
V_10 = V_51 > 1 ? L_76 : L_77 ;
V_12 = F_4 ( V_2 , V_10 , & V_349 ) ;
if ( ! V_12 )
return - V_123 ;
V_12 -> V_243 = V_51 ;
}
for ( V_88 = 0 ; V_88 < V_51 ; V_88 ++ ) {
bool V_72 = false ;
bool V_37 = V_2 -> V_37 ;
bool V_341 = false ;
int V_350 , V_351 ;
V_350 = V_351 = 0 ;
for ( V_16 = 0 ; V_16 < V_312 -> V_315 ; V_16 ++ ) {
struct V_6 * V_52 ;
V_52 = F_188 ( V_19 , V_88 , V_16 ) ;
if ( ! V_52 )
continue;
F_199 ( V_19 , V_52 ) ;
if ( ! V_350 )
V_350 = V_52 -> V_60 [ V_99 ] ;
else if ( V_350 != V_52 -> V_60 [ V_99 ] ) {
V_72 = true ;
if ( ! F_47 ( V_19 , V_350 ,
V_52 -> V_60 [ V_99 ] , V_83 ) )
V_37 = true ;
}
if ( ! V_351 )
V_351 = V_52 -> V_60 [ V_98 ] ;
else if ( V_351 != V_52 -> V_60 [ V_98 ] ) {
V_72 = true ;
if ( ! F_47 ( V_19 , V_351 ,
V_52 -> V_60 [ V_98 ] , V_83 ) )
V_37 = true ;
}
if ( F_200 ( V_19 , V_2 -> V_326 [ V_16 ] ) )
V_341 = true ;
}
if ( ! V_72 )
V_194 = F_203 ( V_19 , V_88 , V_350 , V_351 ,
V_341 ) ;
else if ( ! V_37 && ! V_341 )
V_194 = F_204 ( V_19 , V_88 , V_350 , V_351 ) ;
else
V_194 = F_206 ( V_19 ) ;
if ( V_194 < 0 )
return V_194 ;
}
return 0 ;
}
static bool F_208 ( struct V_18 * V_19 , T_1 V_50 ,
int V_61 , int V_58 )
{
unsigned int V_352 ;
if ( ! F_52 ( V_19 , V_50 , V_61 ) ||
F_32 ( V_19 , V_50 , V_61 , V_58 , V_99 ) ||
F_32 ( V_19 , V_50 , V_61 , V_58 , V_100 ) )
return false ;
V_352 = ( F_48 ( V_19 , V_50 , V_61 ) & V_353 )
>> V_354 ;
if ( V_352 < 0x20 )
return false ;
return true ;
}
static unsigned int F_209 ( struct V_18 * V_19 ,
struct V_6 * V_52 )
{
unsigned int V_20 = 0 ;
T_1 V_50 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
if ( V_53 >= V_52 -> V_53 - 1 )
break;
V_50 = V_52 -> V_52 [ V_53 ] ;
if ( V_53 && F_208 ( V_19 , V_50 , V_82 , 0 ) ) {
V_20 = F_33 ( V_50 , 3 , 0 , V_82 ) ;
break;
} else if ( F_208 ( V_19 , V_50 , V_83 ,
V_52 -> V_58 [ V_53 ] ) ) {
V_20 = F_33 ( V_50 , 3 , V_52 -> V_58 [ V_53 ] ,
V_83 ) ;
break;
}
}
return V_20 ;
}
static int F_210 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
struct V_311 * V_312 = & V_2 -> V_313 ;
int V_16 ;
if ( ! V_2 -> V_308 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_312 -> V_315 ; V_16 ++ ) {
struct V_6 * V_52 ;
unsigned int V_20 ;
int V_58 ;
char V_355 [ V_122 ] ;
V_58 = V_312 -> V_244 [ V_16 ] . V_117 ;
if ( V_58 >= V_312 -> V_315 )
continue;
if ( V_138 -> V_184 [ V_58 ] . type > V_181 )
continue;
V_52 = F_188 ( V_19 , 0 , V_16 ) ;
if ( ! V_52 )
continue;
V_20 = F_209 ( V_19 , V_52 ) ;
if ( ! V_20 )
continue;
snprintf ( V_355 , sizeof( V_355 ) ,
L_78 , V_2 -> V_327 [ V_58 ] ) ;
if ( ! F_75 ( V_2 , V_124 , V_355 ,
V_2 -> V_328 [ V_58 ] , V_20 ) )
return - V_123 ;
V_52 -> V_60 [ V_100 ] = V_20 ;
}
return 0 ;
}
static void F_211 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_52 ;
int V_16 , V_51 ;
T_1 V_356 , V_46 ;
V_51 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_139 . V_357 ; V_16 ++ ) {
V_46 = V_2 -> V_139 . V_358 [ V_16 ] ;
V_356 = F_45 ( V_19 , V_46 , true ) ;
if ( ! V_356 )
continue;
V_52 = F_42 ( V_19 , V_356 , V_46 , 0 ) ;
if ( ! V_52 )
continue;
F_34 ( V_19 , L_79 , V_52 ) ;
V_52 -> V_89 = true ;
V_2 -> V_197 [ V_16 ] = F_26 ( V_19 , V_52 ) ;
F_17 ( V_19 , V_46 , V_224 , false ) ;
if ( ! V_51 ) {
V_2 -> V_146 . V_359 = V_356 ;
V_2 -> V_360 = V_2 -> V_139 . V_360 [ 0 ] ;
} else {
V_2 -> V_146 . V_361 = V_2 -> V_361 ;
if ( V_51 >= F_96 ( V_2 -> V_361 ) - 1 )
break;
V_2 -> V_361 [ V_51 - 1 ] = V_356 ;
}
V_51 ++ ;
}
if ( V_2 -> V_139 . V_362 ) {
V_46 = V_2 -> V_139 . V_362 ;
V_356 = V_19 -> V_211 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_212 ; V_16 ++ , V_356 ++ ) {
unsigned int V_363 = F_40 ( V_19 , V_356 ) ;
if ( F_39 ( V_363 ) != V_69 )
continue;
if ( ! ( V_363 & V_78 ) )
continue;
V_52 = F_42 ( V_19 , V_46 , V_356 , 0 ) ;
if ( V_52 ) {
F_34 ( V_19 , L_80 , V_52 ) ;
V_52 -> V_89 = true ;
V_2 -> V_364 = V_356 ;
V_2 -> V_200 = F_26 ( V_19 , V_52 ) ;
F_17 ( V_19 , V_46 , V_264 , false ) ;
break;
}
}
}
}
static int F_194 ( struct V_18 * V_19 , unsigned int V_331 ,
unsigned int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_311 * V_312 ;
struct V_6 * V_365 , * V_52 ;
V_312 = & V_2 -> V_313 ;
if ( ! V_312 -> V_315 )
return 0 ;
if ( V_58 >= V_312 -> V_315 )
V_58 = V_312 -> V_315 - 1 ;
if ( V_2 -> V_262 [ V_331 ] == V_58 )
return 0 ;
V_365 = F_188 ( V_19 , V_331 , V_2 -> V_262 [ V_331 ] ) ;
if ( ! V_365 )
return 0 ;
if ( V_365 -> V_89 )
F_64 ( V_19 , V_365 , false , false ) ;
V_2 -> V_262 [ V_331 ] = V_58 ;
if ( V_2 -> V_43 )
F_148 ( V_19 , V_331 , false ) ;
if ( V_2 -> V_317 )
F_212 ( V_19 , V_58 ) ;
V_52 = F_188 ( V_19 , V_331 , V_58 ) ;
if ( ! V_52 )
return 0 ;
if ( V_52 -> V_89 )
return 0 ;
F_64 ( V_19 , V_52 , true , false ) ;
if ( V_2 -> V_337 )
V_2 -> V_337 ( V_19 , NULL , NULL ) ;
F_68 ( V_19 , V_365 ) ;
return 1 ;
}
static bool F_213 ( struct V_18 * V_19 , int V_48 , T_1 * V_49 )
{
int V_16 ;
bool V_366 = false ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
T_1 V_50 = V_49 [ V_16 ] ;
if ( ! V_50 )
break;
if ( F_16 ( V_19 , V_50 ) & V_367 )
continue;
if ( F_214 ( V_19 , V_50 ) == V_368 )
V_366 = true ;
}
return V_366 ;
}
static void F_215 ( struct V_18 * V_19 , int V_48 , T_1 * V_49 ,
int * V_5 , bool V_369 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
T_1 V_50 = V_49 [ V_16 ] ;
unsigned int V_20 , V_293 ;
if ( ! V_50 )
break;
if ( V_2 -> V_33 ) {
struct V_6 * V_52 ;
T_1 V_370 ;
V_52 = F_27 ( V_19 , V_5 [ V_16 ] ) ;
if ( ! V_52 )
continue;
V_370 = F_76 ( V_52 -> V_60 [ V_98 ] ) ;
if ( ! V_370 )
continue;
if ( V_369 )
V_2 -> V_133 |= ( 1ULL << V_370 ) ;
else
V_2 -> V_133 &= ~ ( 1ULL << V_370 ) ;
F_72 ( V_19 , V_50 , ! V_369 ) ;
continue;
}
V_293 = F_16 ( V_19 , V_50 ) ;
if ( V_293 & V_264 )
continue;
if ( V_2 -> V_371 )
V_20 = V_293 & ~ V_223 ;
else
V_20 = 0 ;
if ( ! V_369 )
V_20 |= V_293 ;
F_15 ( V_19 , V_50 , V_20 ) ;
F_72 ( V_19 , V_50 , ! V_369 ) ;
}
}
void F_216 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int * V_5 ;
int V_372 ;
if ( V_2 -> V_139 . V_151 == V_154 )
V_5 = V_2 -> V_188 ;
else
V_5 = V_2 -> V_153 ;
F_215 ( V_19 , F_96 ( V_2 -> V_139 . V_203 ) ,
V_2 -> V_139 . V_203 , V_5 , V_2 -> V_373 ) ;
if ( ! V_2 -> V_374 )
V_372 = 0 ;
else
V_372 = V_2 -> V_375 | V_2 -> V_376 ;
V_372 |= V_2 -> V_373 ;
V_2 -> V_377 = V_372 ;
if ( V_2 -> V_139 . V_151 == V_152 )
V_5 = V_2 -> V_188 ;
else
V_5 = V_2 -> V_155 ;
F_215 ( V_19 , F_96 ( V_2 -> V_139 . V_204 ) ,
V_2 -> V_139 . V_204 , V_5 , V_372 ) ;
if ( V_2 -> V_139 . V_202 [ 0 ] == V_2 -> V_139 . V_203 [ 0 ] ||
V_2 -> V_139 . V_202 [ 0 ] == V_2 -> V_139 . V_204 [ 0 ] )
return;
if ( ! V_2 -> V_378 )
V_372 = 0 ;
else
V_372 = V_2 -> V_375 ;
V_372 |= V_2 -> V_373 ;
V_2 -> V_379 = V_372 ;
V_5 = V_2 -> V_188 ;
F_215 ( V_19 , F_96 ( V_2 -> V_139 . V_202 ) ,
V_2 -> V_139 . V_202 , V_5 , V_372 ) ;
}
static void F_217 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_380 )
V_2 -> V_380 ( V_19 ) ;
else
F_216 ( V_19 ) ;
if ( V_2 -> V_33 && ! V_19 -> V_381 -> V_382 )
F_218 ( V_2 -> V_144 . V_383 , false ) ;
}
void F_219 ( struct V_18 * V_19 ,
struct V_384 * V_385 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 * V_49 = V_2 -> V_139 . V_203 ;
int V_48 = F_96 ( V_2 -> V_139 . V_203 ) ;
if ( V_2 -> V_231 ) {
V_49 ++ ;
V_48 -- ;
}
V_2 -> V_375 = F_213 ( V_19 , V_48 , V_49 ) ;
if ( ! V_2 -> V_386 || ( ! V_2 -> V_374 && ! V_2 -> V_378 ) )
return;
F_217 ( V_19 ) ;
}
void F_220 ( struct V_18 * V_19 ,
struct V_384 * V_385 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_139 . V_151 == V_152 )
return;
if ( V_2 -> V_139 . V_202 [ 0 ] == V_2 -> V_139 . V_203 [ 0 ] )
return;
V_2 -> V_376 =
F_213 ( V_19 , F_96 ( V_2 -> V_139 . V_202 ) ,
V_2 -> V_139 . V_202 ) ;
if ( ! V_2 -> V_374 || ! V_2 -> V_387 )
return;
F_217 ( V_19 ) ;
}
void F_221 ( struct V_18 * V_19 ,
struct V_384 * V_385 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
if ( ! V_2 -> V_348 )
return;
for ( V_16 = V_2 -> V_388 - 1 ; V_16 > 0 ; V_16 -- ) {
T_1 V_46 = V_2 -> V_389 [ V_16 ] . V_46 ;
if ( F_16 ( V_19 , V_46 ) & V_390 )
continue;
if ( F_214 ( V_19 , V_46 ) == V_368 ) {
F_194 ( V_19 , 0 , V_2 -> V_389 [ V_16 ] . V_58 ) ;
return;
}
}
F_194 ( V_19 , 0 , V_2 -> V_389 [ 0 ] . V_58 ) ;
}
static void F_133 ( struct V_18 * V_19 ,
struct V_384 * V_385 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_391 )
V_2 -> V_391 ( V_19 , V_385 ) ;
else
F_219 ( V_19 , V_385 ) ;
}
static void F_222 ( struct V_18 * V_19 ,
struct V_384 * V_385 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_392 )
V_2 -> V_392 ( V_19 , V_385 ) ;
else
F_220 ( V_19 , V_385 ) ;
}
static void F_223 ( struct V_18 * V_19 ,
struct V_384 * V_385 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_393 )
V_2 -> V_393 ( V_19 , V_385 ) ;
else
F_221 ( V_19 , V_385 ) ;
}
static void F_141 ( struct V_18 * V_19 )
{
F_133 ( V_19 , NULL ) ;
F_222 ( V_19 , NULL ) ;
F_223 ( V_19 , NULL ) ;
}
static int F_224 ( struct V_128 * V_129 ,
struct V_227 * V_228 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_394 [] = {
L_81 , L_82 , L_83
} ;
if ( V_2 -> V_395 && V_2 -> V_396 )
return F_154 ( V_129 , V_228 , 3 , V_394 ) ;
return F_128 ( V_129 , V_228 ) ;
}
static int F_225 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = 0 ;
if ( V_2 -> V_374 )
V_20 ++ ;
if ( V_2 -> V_378 )
V_20 ++ ;
V_131 -> V_134 . V_229 . V_230 [ 0 ] = V_20 ;
return 0 ;
}
static int F_226 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
switch ( V_131 -> V_134 . V_229 . V_230 [ 0 ] ) {
case 0 :
if ( ! V_2 -> V_374 && ! V_2 -> V_378 )
return 0 ;
V_2 -> V_374 = 0 ;
V_2 -> V_378 = 0 ;
break;
case 1 :
if ( V_2 -> V_395 ) {
if ( ! V_2 -> V_378 && V_2 -> V_374 )
return 0 ;
V_2 -> V_374 = 1 ;
V_2 -> V_378 = 0 ;
} else if ( V_2 -> V_396 ) {
if ( V_2 -> V_378 )
return 0 ;
V_2 -> V_378 = 1 ;
} else
return - V_246 ;
break;
case 2 :
if ( ! V_2 -> V_396 || ! V_2 -> V_395 )
return - V_246 ;
if ( V_2 -> V_374 && V_2 -> V_378 )
return 0 ;
V_2 -> V_374 = 1 ;
V_2 -> V_378 = 1 ;
break;
default:
return - V_246 ;
}
F_217 ( V_19 ) ;
return 1 ;
}
static int F_227 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! F_4 ( V_2 , NULL , & V_397 ) )
return - V_123 ;
return 0 ;
}
static int F_228 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
int V_366 = 0 ;
int V_16 , V_194 ;
if ( V_2 -> V_30 )
return 0 ;
if ( V_138 -> V_203 [ 0 ] )
V_366 ++ ;
if ( V_138 -> V_202 [ 0 ] )
V_366 ++ ;
if ( V_138 -> V_204 [ 0 ] )
V_366 ++ ;
if ( V_366 < 2 )
return 0 ;
if ( ! V_138 -> V_204 [ 0 ] &&
V_138 -> V_151 == V_152 ) {
memcpy ( V_138 -> V_204 , V_138 -> V_202 ,
sizeof( V_138 -> V_204 ) ) ;
V_138 -> V_143 = V_138 -> V_140 ;
}
if ( ! V_138 -> V_203 [ 0 ] &&
V_138 -> V_151 == V_154 ) {
memcpy ( V_138 -> V_203 , V_138 -> V_202 ,
sizeof( V_138 -> V_203 ) ) ;
V_138 -> V_142 = V_138 -> V_140 ;
}
for ( V_16 = 0 ; V_16 < V_138 -> V_142 ; V_16 ++ ) {
T_1 V_50 = V_138 -> V_203 [ V_16 ] ;
if ( ! F_229 ( V_19 , V_50 ) )
continue;
F_36 ( V_19 , L_84 , V_50 ) ;
F_230 ( V_19 , V_50 ,
F_133 ) ;
V_2 -> V_386 = 1 ;
}
if ( V_138 -> V_151 == V_398 && V_138 -> V_140 ) {
if ( V_138 -> V_143 )
for ( V_16 = 0 ; V_16 < V_138 -> V_140 ; V_16 ++ ) {
T_1 V_50 = V_138 -> V_202 [ V_16 ] ;
if ( ! F_229 ( V_19 , V_50 ) )
continue;
F_36 ( V_19 , L_85 , V_50 ) ;
F_230 ( V_19 , V_50 ,
F_222 ) ;
V_2 -> V_387 = 1 ;
}
V_2 -> V_396 = V_2 -> V_386 ;
}
V_2 -> V_395 = V_138 -> V_143 &&
( V_2 -> V_386 || V_2 -> V_387 ) ;
V_2 -> V_378 = V_2 -> V_396 ;
V_2 -> V_374 = V_2 -> V_395 ;
if ( V_2 -> V_395 || V_2 -> V_396 ) {
V_194 = F_227 ( V_19 ) ;
if ( V_194 < 0 )
return V_194 ;
}
return 0 ;
}
static bool F_231 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_311 * V_312 ;
int V_16 ;
V_312 = & V_2 -> V_313 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_388 ; V_16 ++ ) {
V_2 -> V_389 [ V_16 ] . V_58 =
F_21 ( V_2 -> V_389 [ V_16 ] . V_46 ,
V_2 -> V_326 , V_312 -> V_315 ) ;
if ( V_2 -> V_389 [ V_16 ] . V_58 < 0 )
return false ;
}
for ( V_16 = 1 ; V_16 < V_2 -> V_388 ; V_16 ++ )
F_230 ( V_19 ,
V_2 -> V_389 [ V_16 ] . V_46 ,
F_223 ) ;
return true ;
}
static int F_232 ( const void * V_399 , const void * V_400 )
{
const struct V_401 * V_402 = V_399 ;
const struct V_401 * V_403 = V_400 ;
return ( int ) ( V_402 -> V_404 - V_403 -> V_404 ) ;
}
static int F_233 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
unsigned int V_405 ;
int V_16 , V_48 ;
if ( V_2 -> V_31 )
return 0 ;
V_405 = 0 ;
V_48 = 0 ;
for ( V_16 = 0 ; V_16 < V_138 -> V_183 ; V_16 ++ ) {
T_1 V_50 = V_138 -> V_184 [ V_16 ] . V_46 ;
unsigned int V_404 ;
V_404 = F_104 ( V_19 , V_50 ) ;
V_404 = F_152 ( V_404 ) ;
if ( V_405 & ( 1 << V_404 ) )
return 0 ;
switch ( V_404 ) {
case V_270 :
if ( V_138 -> V_184 [ V_16 ] . type != V_182 )
return 0 ;
break;
case V_406 :
return 0 ;
default:
if ( V_138 -> V_184 [ V_16 ] . type > V_181 )
return 0 ;
if ( ! V_2 -> V_32 &&
V_138 -> V_184 [ V_16 ] . type != V_182 )
return 0 ;
if ( ! F_229 ( V_19 , V_50 ) )
return 0 ;
break;
}
if ( V_48 >= V_407 )
return 0 ;
V_405 |= ( 1 << V_404 ) ;
V_2 -> V_389 [ V_48 ] . V_46 = V_50 ;
V_2 -> V_389 [ V_48 ] . V_404 = V_404 ;
V_48 ++ ;
}
if ( V_48 < 2 )
return 0 ;
V_2 -> V_388 = V_48 ;
F_234 ( V_2 -> V_389 , V_48 , sizeof( V_2 -> V_389 [ 0 ] ) ,
F_232 , NULL ) ;
if ( ! F_231 ( V_19 ) )
return 0 ;
V_2 -> V_348 = 1 ;
V_2 -> V_308 = 1 ;
V_2 -> V_262 [ 0 ] = V_2 -> V_389 [ 0 ] . V_58 ;
F_36 ( V_19 , L_86 ,
V_2 -> V_389 [ 0 ] . V_46 ,
V_2 -> V_389 [ 1 ] . V_46 ,
V_2 -> V_389 [ 2 ] . V_46 ) ;
return 0 ;
}
unsigned int F_235 ( struct V_18 * V_19 ,
T_1 V_50 ,
unsigned int V_408 )
{
if ( V_408 != V_104 || V_50 == V_19 -> V_409 )
return V_408 ;
if ( F_39 ( F_40 ( V_19 , V_50 ) ) >= V_410 )
return V_408 ;
if ( F_69 ( V_19 , V_50 ) )
return V_408 ;
return V_108 ;
}
static void F_236 ( struct V_18 * V_19 , T_1 V_295 )
{
int V_16 , V_51 ;
const T_1 * V_65 ;
bool V_411 ;
V_51 = F_38 ( V_19 , V_295 , & V_65 ) ;
V_411 = F_50 ( V_19 , V_295 , V_83 ) ;
for ( V_16 = 0 ; V_16 < V_51 ; V_16 ++ ) {
if ( V_411 )
F_61 ( V_19 , V_295 ,
V_83 , V_16 ,
0xff , V_96 ) ;
else if ( F_52 ( V_19 , V_65 [ V_16 ] , V_82 ) )
F_61 ( V_19 , V_65 [ V_16 ] ,
V_82 , 0 ,
0xff , V_96 ) ;
}
}
int F_237 ( struct V_18 * V_19 ,
struct V_137 * V_138 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_194 ;
F_11 ( V_19 ) ;
if ( V_2 -> V_45 && ! V_2 -> V_103 )
V_2 -> V_103 = V_2 -> V_45 ;
if ( V_138 != & V_2 -> V_139 ) {
V_2 -> V_139 = * V_138 ;
V_138 = & V_2 -> V_139 ;
}
if ( ! V_2 -> V_205 )
V_2 -> V_205 = & V_412 ;
if ( ! V_2 -> V_206 )
V_2 -> V_206 = & V_413 ;
F_117 ( V_19 ) ;
if ( ! V_138 -> V_140 ) {
if ( V_138 -> V_357 || V_138 -> V_362 ) {
V_2 -> V_146 . V_248 = 2 ;
V_2 -> V_414 = 1 ;
goto V_415;
}
if ( ! V_138 -> V_183 && ! V_138 -> V_362 )
return 0 ;
}
if ( ! V_2 -> V_35 &&
V_138 -> V_151 == V_152 &&
V_138 -> V_140 <= V_138 -> V_142 ) {
V_138 -> V_143 = V_138 -> V_140 ;
memcpy ( V_138 -> V_204 , V_138 -> V_202 ,
sizeof( V_138 -> V_204 ) ) ;
V_138 -> V_140 = V_138 -> V_142 ;
memcpy ( V_138 -> V_202 , V_138 -> V_203 , sizeof( V_138 -> V_203 ) ) ;
V_138 -> V_142 = 0 ;
memset ( V_138 -> V_203 , 0 , sizeof( V_138 -> V_203 ) ) ;
V_138 -> V_151 = V_154 ;
}
V_194 = F_119 ( V_19 ) ;
if ( V_194 < 0 )
return V_194 ;
V_194 = F_144 ( V_19 ) ;
if ( V_194 < 0 )
return V_194 ;
V_194 = F_122 ( V_19 , V_138 ) ;
if ( V_194 < 0 )
return V_194 ;
V_194 = F_125 ( V_19 ) ;
if ( V_194 < 0 )
return V_194 ;
V_194 = F_126 ( V_19 ) ;
if ( V_194 < 0 )
return V_194 ;
V_194 = F_135 ( V_19 ) ;
if ( V_194 < 0 )
return V_194 ;
V_194 = F_147 ( V_19 ) ;
if ( V_194 < 0 )
return V_194 ;
V_194 = F_151 ( V_19 ) ;
if ( V_194 < 0 )
return V_194 ;
V_194 = F_187 ( V_19 ) ;
if ( V_194 < 0 )
return V_194 ;
V_2 -> V_249 = V_2 -> V_207 ;
if ( V_138 -> V_151 != V_152 )
V_2 -> V_249 = F_143 ( V_2 -> V_249 ,
V_138 -> V_143 * 2 ) ;
if ( V_138 -> V_151 != V_154 )
V_2 -> V_249 = F_143 ( V_2 -> V_249 ,
V_138 -> V_142 * 2 ) ;
V_2 -> V_146 . V_248 = F_143 ( V_2 -> V_207 ,
V_2 -> V_249 ) ;
V_194 = F_228 ( V_19 ) ;
if ( V_194 < 0 )
return V_194 ;
V_194 = F_182 ( V_19 ) ;
if ( V_194 < 0 )
return V_194 ;
V_194 = F_233 ( V_19 ) ;
if ( V_194 < 0 )
return V_194 ;
if ( ! V_2 -> V_348 && V_2 -> V_45 &&
V_2 -> V_40 &&
V_2 -> V_313 . V_315 > 1 &&
F_12 ( V_19 , L_20 ) < 0 ) {
V_194 = F_183 ( V_19 , V_2 -> V_45 ,
V_330 , V_2 -> V_309 ,
L_69 , 0 ) ;
if ( V_194 < 0 )
return V_194 ;
}
V_194 = F_207 ( V_19 ) ;
if ( V_194 < 0 )
return V_194 ;
V_194 = F_210 ( V_19 ) ;
if ( V_194 < 0 )
return V_194 ;
if ( V_2 -> V_261 &&
( V_2 -> V_348 || V_2 -> V_313 . V_315 == 1 ||
V_2 -> V_41 ) ) {
V_194 = F_176 ( V_19 , V_2 -> V_261 ) ;
if ( V_194 < 0 )
return V_194 ;
}
if ( V_2 -> V_41 ) {
if ( V_138 -> V_151 != V_152 ) {
V_194 = F_162 ( V_19 , V_138 -> V_140 ,
V_138 -> V_202 ) ;
if ( V_194 < 0 )
return V_194 ;
}
if ( V_138 -> V_151 != V_154 ) {
V_194 = F_162 ( V_19 , V_138 -> V_142 ,
V_138 -> V_203 ) ;
if ( V_194 < 0 )
return V_194 ;
}
}
if ( V_2 -> V_45 )
F_236 ( V_19 , V_2 -> V_45 ) ;
V_415:
F_211 ( V_19 ) ;
if ( V_2 -> V_42 )
V_19 -> V_416 = F_235 ;
if ( ! V_2 -> V_414 && V_2 -> V_417 ) {
V_194 = F_238 ( V_19 , V_2 -> V_417 ) ;
if ( V_194 < 0 )
return V_194 ;
}
return 1 ;
}
int F_239 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_194 ;
if ( V_2 -> V_3 . V_17 ) {
V_194 = F_240 ( V_19 , V_2 -> V_3 . V_14 ) ;
if ( V_194 < 0 )
return V_194 ;
}
if ( V_2 -> V_146 . V_359 ) {
V_194 = F_241 ( V_19 ,
V_2 -> V_146 . V_359 ,
V_2 -> V_146 . V_359 ,
V_2 -> V_418 [ 1 ] . V_419 ) ;
if ( V_194 < 0 )
return V_194 ;
if ( ! V_2 -> V_414 ) {
V_194 = F_242 ( V_19 ,
& V_2 -> V_146 ) ;
if ( V_194 < 0 )
return V_194 ;
V_2 -> V_146 . V_420 = 1 ;
}
}
if ( V_2 -> V_364 ) {
V_194 = F_243 ( V_19 , V_2 -> V_364 ) ;
if ( V_194 < 0 )
return V_194 ;
}
if ( ! V_2 -> V_414 &&
! F_244 ( V_19 , L_87 ) ) {
V_194 = F_245 ( V_19 , L_87 ,
V_2 -> V_220 , V_421 ,
L_88 ) ;
if ( V_194 < 0 )
return V_194 ;
}
if ( ! V_2 -> V_414 &&
! F_244 ( V_19 , L_89 ) ) {
V_194 = F_246 ( V_19 , L_89 ,
NULL , V_421 ,
L_90 ,
true , & V_2 -> V_144 . V_383 ) ;
if ( V_194 < 0 )
return V_194 ;
if ( V_2 -> V_144 . V_145 ) {
F_247 ( V_19 , & V_2 -> V_144 ,
V_2 -> V_422 ) ;
F_248 ( & V_2 -> V_144 ) ;
}
}
F_7 ( V_2 ) ;
V_194 = F_249 ( V_19 , & V_2 -> V_139 ) ;
if ( V_194 < 0 )
return V_194 ;
return 0 ;
}
static void F_250 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 ,
int V_427 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_428 )
V_2 -> V_428 ( V_424 , V_19 , V_426 , V_427 ) ;
}
static void F_251 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 ,
int V_427 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_429 )
V_2 -> V_429 ( V_424 , V_19 , V_426 , V_427 ) ;
}
static int F_252 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_194 ;
F_131 ( & V_2 -> V_9 ) ;
V_194 = F_253 ( V_19 ,
& V_2 -> V_146 , V_426 ,
V_424 ) ;
if ( ! V_194 ) {
V_2 -> V_234 |= 1 << V_430 ;
F_250 ( V_424 , V_19 , V_426 ,
V_431 ) ;
}
F_134 ( & V_2 -> V_9 ) ;
return V_194 ;
}
static int F_254 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
unsigned int V_432 ,
unsigned int V_433 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_194 ;
V_194 = F_255 ( V_19 , & V_2 -> V_146 ,
V_432 , V_433 , V_426 ) ;
if ( ! V_194 )
F_250 ( V_424 , V_19 , V_426 ,
V_434 ) ;
return V_194 ;
}
static int F_256 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_194 ;
V_194 = F_257 ( V_19 , & V_2 -> V_146 ) ;
if ( ! V_194 )
F_250 ( V_424 , V_19 , V_426 ,
V_435 ) ;
return V_194 ;
}
static int F_258 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_131 ( & V_2 -> V_9 ) ;
V_2 -> V_234 &= ~ ( 1 << V_430 ) ;
F_250 ( V_424 , V_19 , V_426 ,
V_436 ) ;
F_134 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_259 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 )
{
F_251 ( V_424 , V_19 , V_426 , V_431 ) ;
return 0 ;
}
static int F_260 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
unsigned int V_432 ,
unsigned int V_433 ,
struct V_425 * V_426 )
{
F_261 ( V_19 , V_424 -> V_50 , V_432 , 0 , V_433 ) ;
F_251 ( V_424 , V_19 , V_426 ,
V_434 ) ;
return 0 ;
}
static int F_262 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 )
{
F_263 ( V_19 , V_424 -> V_50 ) ;
F_251 ( V_424 , V_19 , V_426 ,
V_435 ) ;
return 0 ;
}
static int F_264 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 )
{
F_251 ( V_424 , V_19 , V_426 , V_436 ) ;
return 0 ;
}
static int F_265 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_194 = 0 ;
F_131 ( & V_2 -> V_9 ) ;
if ( ! V_2 -> V_231 )
V_194 = - V_235 ;
else
V_2 -> V_234 |= 1 << V_437 ;
F_250 ( V_424 , V_19 , V_426 ,
V_431 ) ;
F_134 ( & V_2 -> V_9 ) ;
return V_194 ;
}
static int F_266 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_131 ( & V_2 -> V_9 ) ;
V_2 -> V_234 &= ~ ( 1 << V_437 ) ;
F_250 ( V_424 , V_19 , V_426 ,
V_436 ) ;
F_134 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_267 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
unsigned int V_432 ,
unsigned int V_433 ,
struct V_425 * V_426 )
{
F_261 ( V_19 , V_424 -> V_50 , V_432 , 0 , V_433 ) ;
F_250 ( V_424 , V_19 , V_426 ,
V_434 ) ;
return 0 ;
}
static int F_268 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 )
{
F_263 ( V_19 , V_424 -> V_50 ) ;
F_250 ( V_424 , V_19 , V_426 ,
V_435 ) ;
return 0 ;
}
static int F_269 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_270 ( V_19 , & V_2 -> V_146 ) ;
}
static int F_271 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
unsigned int V_432 ,
unsigned int V_433 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_272 ( V_19 , & V_2 -> V_146 ,
V_432 , V_433 , V_426 ) ;
}
static int F_273 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_274 ( V_19 , & V_2 -> V_146 ) ;
}
static int F_275 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_276 ( V_19 , & V_2 -> V_146 ) ;
}
static int F_277 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
unsigned int V_432 ,
unsigned int V_433 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_261 ( V_19 , V_2 -> V_306 [ V_426 -> V_438 + 1 ] ,
V_432 , 0 , V_433 ) ;
F_251 ( V_424 , V_19 , V_426 ,
V_434 ) ;
return 0 ;
}
static int F_278 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_263 ( V_19 ,
V_2 -> V_306 [ V_426 -> V_438 + 1 ] ) ;
F_251 ( V_424 , V_19 , V_426 ,
V_435 ) ;
return 0 ;
}
static bool F_212 ( struct V_18 * V_19 , int V_439 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_440 = V_2 -> V_306 [ V_2 -> V_316 [ V_439 ] ] ;
if ( V_2 -> V_441 && V_2 -> V_441 != V_440 ) {
F_279 ( V_19 , V_2 -> V_441 , 1 ) ;
V_2 -> V_441 = V_440 ;
F_261 ( V_19 , V_440 ,
V_2 -> V_442 , 0 ,
V_2 -> V_443 ) ;
return true ;
}
return false ;
}
static int F_280 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
unsigned int V_432 ,
unsigned int V_433 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
V_2 -> V_441 = V_2 -> V_306 [ V_2 -> V_316 [ V_2 -> V_262 [ 0 ] ] ] ;
V_2 -> V_442 = V_432 ;
V_2 -> V_443 = V_433 ;
F_261 ( V_19 , V_2 -> V_441 , V_432 , 0 , V_433 ) ;
return 0 ;
}
static int F_281 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_263 ( V_19 , V_2 -> V_441 ) ;
V_2 -> V_441 = 0 ;
return 0 ;
}
static void F_282 ( char * V_444 , T_3 V_445 , const char * V_121 ,
const char * V_446 )
{
char * V_447 ;
if ( * V_444 )
return;
F_283 ( V_444 , V_446 , V_445 ) ;
for ( V_447 = strchr ( V_444 , ' ' ) ; V_447 ; V_447 = strchr ( V_447 + 1 , ' ' ) ) {
if ( ! isalnum ( V_447 [ 1 ] ) ) {
* V_447 = 0 ;
break;
}
}
F_160 ( V_444 , V_121 , V_445 ) ;
}
int F_284 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_448 * V_449 = V_2 -> V_418 ;
const struct V_423 * V_447 ;
bool V_450 ;
V_19 -> V_451 = 1 ;
V_19 -> V_452 = V_449 ;
if ( V_2 -> V_414 )
goto V_453;
F_282 ( V_2 -> V_454 ,
sizeof( V_2 -> V_454 ) ,
L_91 , V_19 -> V_446 ) ;
V_449 -> V_10 = V_2 -> V_454 ;
if ( V_2 -> V_146 . V_147 > 0 ) {
V_447 = V_2 -> V_455 ;
if ( ! V_447 )
V_447 = & V_456 ;
V_449 -> V_457 [ V_458 ] = * V_447 ;
V_449 -> V_457 [ V_458 ] . V_50 = V_2 -> V_146 . V_195 [ 0 ] ;
V_449 -> V_457 [ V_458 ] . V_459 =
V_2 -> V_146 . V_248 ;
if ( V_2 -> V_139 . V_151 == V_152 &&
V_2 -> V_139 . V_140 == 2 )
V_449 -> V_457 [ V_458 ] . V_460 =
V_461 ;
}
if ( V_2 -> V_308 ) {
V_447 = V_2 -> V_462 ;
if ( ! V_447 ) {
if ( V_2 -> V_317 )
V_447 = & V_463 ;
else
V_447 = & V_464 ;
}
V_449 -> V_457 [ V_465 ] = * V_447 ;
V_449 -> V_457 [ V_465 ] . V_50 = V_2 -> V_306 [ 0 ] ;
}
V_453:
if ( V_2 -> V_146 . V_359 || V_2 -> V_364 ) {
F_282 ( V_2 -> V_466 ,
sizeof( V_2 -> V_466 ) ,
L_92 , V_19 -> V_446 ) ;
V_19 -> V_451 = 2 ;
V_19 -> V_361 = V_2 -> V_146 . V_361 ;
V_449 = V_2 -> V_418 + 1 ;
V_449 -> V_10 = V_2 -> V_466 ;
if ( V_2 -> V_360 )
V_449 -> V_419 = V_2 -> V_360 ;
else
V_449 -> V_419 = V_467 ;
if ( V_2 -> V_146 . V_359 ) {
V_447 = V_2 -> V_468 ;
if ( ! V_447 )
V_447 = & V_469 ;
V_449 -> V_457 [ V_458 ] = * V_447 ;
V_449 -> V_457 [ V_458 ] . V_50 = V_2 -> V_146 . V_359 ;
}
if ( V_2 -> V_364 ) {
V_447 = V_2 -> V_470 ;
if ( ! V_447 )
V_447 = & V_471 ;
V_449 -> V_457 [ V_465 ] = * V_447 ;
V_449 -> V_457 [ V_465 ] . V_50 = V_2 -> V_364 ;
}
}
if ( V_2 -> V_414 )
return 0 ;
V_450 = ( V_2 -> V_308 > 1 ) &&
! V_2 -> V_317 && ! V_2 -> V_348 ;
if ( V_2 -> V_240 || V_450 ) {
F_282 ( V_2 -> V_472 ,
sizeof( V_2 -> V_472 ) ,
L_93 , V_19 -> V_446 ) ;
V_19 -> V_451 = 3 ;
V_449 = V_2 -> V_418 + 2 ;
V_449 -> V_10 = V_2 -> V_472 ;
if ( V_2 -> V_240 ) {
V_447 = V_2 -> V_473 ;
if ( ! V_447 )
V_447 = & V_474 ;
V_449 -> V_457 [ V_458 ] = * V_447 ;
V_449 -> V_457 [ V_458 ] . V_50 =
V_2 -> V_240 ;
} else {
V_449 -> V_457 [ V_458 ] =
V_475 ;
V_449 -> V_457 [ V_458 ] . V_50 = 0 ;
}
if ( V_450 ) {
V_447 = V_2 -> V_476 ;
if ( ! V_447 )
V_447 = & V_477 ;
V_449 -> V_457 [ V_465 ] = * V_447 ;
V_449 -> V_457 [ V_465 ] . V_50 =
V_2 -> V_306 [ 1 ] ;
V_449 -> V_457 [ V_465 ] . V_478 =
V_2 -> V_308 - 1 ;
} else {
V_449 -> V_457 [ V_465 ] =
V_475 ;
V_449 -> V_457 [ V_465 ] . V_50 = 0 ;
}
}
return 0 ;
}
static void F_285 ( struct V_18 * V_19 , int V_114 )
{
struct V_6 * V_52 ;
T_1 V_46 ;
V_52 = F_27 ( V_19 , V_114 ) ;
if ( ! V_52 || ! V_52 -> V_53 )
return;
V_46 = V_52 -> V_52 [ V_52 -> V_53 - 1 ] ;
F_14 ( V_19 , V_46 ) ;
F_64 ( V_19 , V_52 , V_52 -> V_89 ,
F_139 ( V_19 -> V_2 ) ) ;
F_72 ( V_19 , V_46 , V_52 -> V_89 ) ;
}
static void F_286 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_139 . V_140 ; V_16 ++ )
F_285 ( V_19 , V_2 -> V_188 [ V_16 ] ) ;
}
static void F_287 ( struct V_18 * V_19 , int V_164 , int * V_5 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_164 ; V_16 ++ )
F_285 ( V_19 , V_5 [ V_16 ] ) ;
}
static void F_288 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_139 . V_151 != V_154 )
F_287 ( V_19 , V_2 -> V_139 . V_142 , V_2 -> V_153 ) ;
if ( V_2 -> V_139 . V_151 != V_152 )
F_287 ( V_19 , V_2 -> V_139 . V_143 ,
V_2 -> V_155 ) ;
}
static void F_289 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_141 ; V_16 ++ ) {
T_1 V_46 = V_2 -> V_162 [ V_16 ] . V_46 ;
struct V_6 * V_52 ;
V_52 = F_138 ( V_19 , V_16 ) ;
if ( ! V_52 )
continue;
if ( ! V_2 -> V_162 [ V_16 ] . V_247 )
V_2 -> V_162 [ V_16 ] . V_247 =
F_16 ( V_19 , V_46 ) ;
F_64 ( V_19 , V_52 , V_52 -> V_89 ,
F_139 ( V_2 ) ) ;
}
}
static void F_290 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_238 )
return;
F_132 ( V_19 , V_2 -> V_239 , V_2 -> V_188 [ 0 ] ,
V_2 -> V_196 [ 0 ] ,
V_2 -> V_139 . V_151 ) ;
F_132 ( V_19 , V_2 -> V_239 , V_2 -> V_153 [ 0 ] ,
V_2 -> V_196 [ 1 ] ,
V_154 ) ;
F_132 ( V_19 , V_2 -> V_239 , V_2 -> V_155 [ 0 ] ,
V_2 -> V_196 [ 2 ] ,
V_152 ) ;
}
static void F_291 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_138 -> V_183 ; V_16 ++ ) {
T_1 V_50 = V_138 -> V_184 [ V_16 ] . V_46 ;
if ( F_180 ( V_19 , V_50 ) )
F_14 ( V_19 , V_50 ) ;
if ( V_2 -> V_45 ) {
F_74 ( V_19 , V_2 -> V_199 [ V_16 ] ) ;
F_74 ( V_19 , V_2 -> V_305 ) ;
}
}
}
static void F_292 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_311 * V_312 = & V_2 -> V_313 ;
struct V_6 * V_52 ;
int V_16 , V_324 , V_51 ;
if ( V_2 -> V_317 )
V_51 = 1 ;
else
V_51 = V_2 -> V_308 ;
for ( V_324 = 0 ; V_324 < V_51 ; V_324 ++ ) {
for ( V_16 = 0 ; V_16 < V_312 -> V_315 ; V_16 ++ ) {
V_52 = F_188 ( V_19 , V_324 , V_16 ) ;
if ( V_52 ) {
bool V_89 = V_52 -> V_89 ;
if ( V_16 == V_2 -> V_262 [ V_324 ] )
V_89 = true ;
F_64 ( V_19 , V_52 , V_89 , false ) ;
}
}
if ( V_2 -> V_43 )
F_148 ( V_19 , V_324 , true ) ;
}
if ( V_2 -> V_337 )
V_2 -> V_337 ( V_19 , NULL , NULL ) ;
}
static void F_293 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_46 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_139 . V_357 ; V_16 ++ )
F_285 ( V_19 , V_2 -> V_197 [ V_16 ] ) ;
V_46 = V_2 -> V_139 . V_362 ;
if ( V_46 ) {
F_14 ( V_19 , V_46 ) ;
F_74 ( V_19 , V_2 -> V_200 ) ;
}
}
static void F_294 ( struct V_18 * V_19 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_479 . V_17 ; V_16 ++ ) {
struct V_480 * V_46 = F_24 ( & V_19 -> V_479 , V_16 ) ;
T_1 V_50 = V_46 -> V_50 ;
if ( F_229 ( V_19 , V_50 ) &&
! F_295 ( V_19 , V_50 ) )
F_67 ( V_19 , V_50 , 0 ,
V_481 , 0 ) ;
}
}
int F_296 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_482 )
V_2 -> V_482 ( V_19 ) ;
F_297 ( V_19 ) ;
V_19 -> V_336 = 1 ;
F_286 ( V_19 ) ;
F_288 ( V_19 ) ;
F_289 ( V_19 ) ;
F_290 ( V_19 ) ;
F_291 ( V_19 ) ;
F_292 ( V_19 ) ;
F_293 ( V_19 ) ;
F_294 ( V_19 ) ;
F_141 ( V_19 ) ;
F_196 ( V_19 ) ;
if ( V_2 -> V_144 . V_383 && V_2 -> V_144 . V_145 )
F_248 ( & V_2 -> V_144 ) ;
F_298 ( V_19 , 0x01 ) ;
return 0 ;
}
void F_299 ( struct V_18 * V_19 )
{
F_300 ( V_19 , V_483 ) ;
F_10 ( V_19 -> V_2 ) ;
F_8 ( V_19 -> V_2 ) ;
V_19 -> V_2 = NULL ;
}
int F_301 ( struct V_18 * V_19 , T_1 V_50 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_302 ( V_19 , & V_2 -> V_296 , V_50 ) ;
}
int F_303 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_194 ;
V_2 = F_304 ( sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 )
return - V_123 ;
F_1 ( V_2 ) ;
V_19 -> V_2 = V_2 ;
V_194 = F_305 ( V_19 , & V_2 -> V_139 , NULL , 0 ) ;
if ( V_194 < 0 )
return V_194 ;
V_194 = F_237 ( V_19 , & V_2 -> V_139 ) ;
if ( V_194 < 0 )
goto error;
V_19 -> V_484 = V_485 ;
return 0 ;
error:
F_299 ( V_19 ) ;
return V_194 ;
}
