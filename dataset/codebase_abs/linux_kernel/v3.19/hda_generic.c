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
case V_156 :
if ( ! V_136 && V_138 -> V_143 && V_138 -> V_142 ) {
bool V_157 = ! F_94 ( V_19 , V_2 -> V_153 [ 0 ] , V_135 ) ;
bool V_158 = ! F_94 ( V_19 , V_2 -> V_155 [ 0 ] , V_135 ) ;
if ( V_157 && V_158 )
return V_2 -> V_144 . V_145 ? L_33 : L_34 ;
if ( V_157 )
return L_38 ;
if ( V_158 )
return L_39 ;
}
}
if ( V_138 -> V_140 == 1 && ! V_2 -> V_141 )
return L_40 ;
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
int V_159 = 0 ;
if ( ! V_52 )
return V_160 * 2 ;
if ( V_52 -> V_60 [ V_99 ] ||
V_52 -> V_60 [ V_98 ] )
return 0 ;
V_50 = F_51 ( V_19 , V_52 ) ;
if ( V_50 ) {
V_20 = F_33 ( V_50 , 3 , 0 , V_82 ) ;
if ( V_2 -> V_161 )
V_20 |= V_162 ;
if ( F_31 ( V_19 , V_20 , V_99 ) )
V_159 += V_160 ;
else
V_52 -> V_60 [ V_99 ] = V_20 ;
} else
V_159 += V_160 ;
V_50 = F_49 ( V_19 , V_52 ) ;
if ( V_50 ) {
unsigned int V_163 = F_39 ( F_40 ( V_19 , V_50 ) ) ;
if ( V_163 == V_70 || V_163 == V_66 ||
F_50 ( V_19 , V_50 , V_82 ) )
V_20 = F_33 ( V_50 , 3 , 0 , V_82 ) ;
else
V_20 = F_33 ( V_50 , 3 , 0 , V_83 ) ;
if ( F_31 ( V_19 , V_20 , V_98 ) )
V_159 += V_160 ;
else
V_52 -> V_60 [ V_98 ] = V_20 ;
} else
V_159 += V_160 ;
return V_159 ;
}
static T_1 F_99 ( struct V_18 * V_19 , int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
if ( V_138 -> V_140 > V_58 )
return V_2 -> V_164 [ V_58 ] ;
V_58 -= V_138 -> V_140 ;
if ( V_2 -> V_141 > V_58 )
return V_2 -> V_165 [ V_58 ] . V_166 ;
return 0 ;
}
static inline T_1 F_100 ( struct V_18 * V_19 ,
T_1 V_166 , T_1 V_46 )
{
return F_29 ( V_19 , V_166 , V_46 ) ? V_166 : 0 ;
}
static int F_101 ( struct V_18 * V_19 , int V_167 ,
const T_1 * V_49 , T_1 * V_168 ,
int * V_114 ,
const struct V_169 * V_170 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_171 ;
int V_159 = 0 ;
T_1 V_166 ;
if ( ! V_167 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_167 ; V_16 ++ ) {
struct V_6 * V_52 ;
T_1 V_46 = V_49 [ V_16 ] ;
V_52 = F_27 ( V_19 , V_114 [ V_16 ] ) ;
if ( V_52 ) {
V_159 += F_98 ( V_19 , V_52 ) ;
continue;
}
V_168 [ V_16 ] = F_44 ( V_19 , V_46 ) ;
if ( V_168 [ V_16 ] ) {
if ( F_28 ( V_19 , V_168 [ V_16 ] ) )
V_159 += V_170 -> V_172 ;
}
if ( ! V_168 [ V_16 ] )
V_168 [ V_16 ] = F_45 ( V_19 , V_46 , false ) ;
if ( ! V_168 [ V_16 ] && ! V_16 ) {
for ( V_171 = 1 ; V_171 < V_167 ; V_171 ++ ) {
if ( F_29 ( V_19 , V_168 [ V_171 ] , V_46 ) ) {
V_168 [ 0 ] = V_168 [ V_171 ] ;
V_168 [ V_171 ] = 0 ;
F_43 ( V_19 , V_114 [ V_171 ] ) ;
V_114 [ V_171 ] = 0 ;
break;
}
}
}
V_166 = V_168 [ V_16 ] ;
if ( ! V_166 ) {
if ( V_167 > 2 )
V_166 = F_100 ( V_19 , F_99 ( V_19 , V_16 ) , V_46 ) ;
if ( ! V_166 )
V_166 = F_100 ( V_19 , V_168 [ 0 ] , V_46 ) ;
if ( ! V_166 )
V_166 = F_100 ( V_19 , F_99 ( V_19 , V_16 ) , V_46 ) ;
if ( V_166 ) {
if ( ! V_16 )
V_159 += V_170 -> V_172 ;
else if ( V_16 == 1 )
V_159 += V_170 -> V_173 ;
else
V_159 += V_170 -> V_174 ;
} else if ( F_29 ( V_19 , V_2 -> V_164 [ 0 ] , V_46 ) ) {
V_166 = V_2 -> V_164 [ 0 ] ;
V_159 += V_170 -> V_175 ;
} else if ( ! V_16 )
V_159 += V_170 -> V_176 ;
else
V_159 += V_170 -> V_177 ;
}
if ( ! V_166 )
continue;
V_52 = F_42 ( V_19 , V_166 , V_46 , - V_2 -> V_45 ) ;
if ( ! V_52 && ! V_16 && V_2 -> V_45 ) {
V_52 = F_42 ( V_19 , V_166 , V_46 , 0 ) ;
}
if ( ! V_52 ) {
V_166 = V_168 [ V_16 ] = 0 ;
V_159 += V_170 -> V_177 ;
} else {
V_52 -> V_89 = true ;
V_114 [ V_16 ] = F_26 ( V_19 , V_52 ) ;
V_159 += F_98 ( V_19 , V_52 ) ;
}
}
return V_159 ;
}
static T_1 F_102 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_178 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_76 ; V_16 ++ ) {
T_1 V_50 = V_2 -> V_77 [ V_16 ] ;
if ( ! V_50 || F_28 ( V_19 , V_50 ) )
continue;
if ( F_29 ( V_19 , V_50 , V_46 ) ) {
if ( V_178 )
return 0 ;
V_178 = V_50 ;
}
}
return V_178 ;
}
static bool F_103 ( struct V_18 * V_19 ,
unsigned int V_179 , T_1 V_50 )
{
unsigned int V_180 , V_85 ;
V_180 = F_104 ( V_19 , V_50 ) ;
if ( F_105 ( V_180 ) != V_181 )
return false ;
if ( V_179 && F_106 ( V_180 ) != V_179 )
return false ;
V_85 = F_73 ( V_19 , V_50 ) ;
if ( ! ( V_85 & V_182 ) )
return false ;
return true ;
}
static int F_107 ( struct V_18 * V_19 , T_1 V_183 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
unsigned int V_180 = F_104 ( V_19 , V_183 ) ;
unsigned int V_179 = F_106 ( V_180 ) ;
int type , V_16 ;
int V_48 = 0 ;
for ( type = V_184 ; type >= V_185 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_138 -> V_186 ; V_16 ++ ) {
if ( V_138 -> V_187 [ V_16 ] . type != type )
continue;
if ( F_103 ( V_19 , V_179 ,
V_138 -> V_187 [ V_16 ] . V_46 ) )
V_48 ++ ;
}
}
return V_48 ;
}
static int F_108 ( struct V_18 * V_19 ,
T_1 V_183 ,
bool V_188 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
int type , V_16 , V_171 , V_48 , V_189 ;
unsigned int V_180 = F_104 ( V_19 , V_183 ) ;
unsigned int V_179 = F_106 ( V_180 ) ;
int V_159 = 0 ;
struct V_6 * V_52 ;
V_189 = V_2 -> V_141 ;
if ( V_189 >= 2 )
goto V_190;
V_48 = F_107 ( V_19 , V_183 ) ;
if ( V_48 < 2 )
goto V_190;
for ( type = V_184 ; type >= V_185 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_138 -> V_186 ; V_16 ++ ) {
T_1 V_50 = V_138 -> V_187 [ V_16 ] . V_46 ;
T_1 V_166 = 0 ;
if ( V_138 -> V_187 [ V_16 ] . type != type )
continue;
if ( ! F_103 ( V_19 , V_179 , V_50 ) )
continue;
for ( V_171 = 0 ; V_171 < V_2 -> V_141 ; V_171 ++ ) {
if ( V_50 == V_2 -> V_165 [ V_171 ] . V_46 )
break;
}
if ( V_171 < V_2 -> V_141 )
continue;
if ( V_188 )
V_166 = F_102 ( V_19 , V_50 ) ;
else if ( ! V_166 )
V_166 = F_45 ( V_19 , V_50 , false ) ;
if ( ! V_166 ) {
V_159 ++ ;
continue;
}
V_52 = F_42 ( V_19 , V_166 , V_50 ,
- V_2 -> V_45 ) ;
if ( ! V_52 ) {
V_159 ++ ;
continue;
}
V_2 -> V_165 [ V_2 -> V_141 ] . V_46 = V_50 ;
V_2 -> V_165 [ V_2 -> V_141 ] . V_166 = V_166 ;
V_2 -> V_191 [ V_138 -> V_140 + V_2 -> V_141 ] =
F_26 ( V_19 , V_52 ) ;
V_2 -> V_141 ++ ;
if ( V_2 -> V_141 >= 2 )
break;
}
}
V_190:
if ( V_159 )
V_159 = V_192 ;
if ( V_189 == V_2 -> V_141 ) {
if ( V_188 )
return 1 ;
else
return V_159 ;
}
if ( ! V_188 && V_2 -> V_141 < 2 ) {
V_2 -> V_5 . V_17 -= V_2 -> V_141 - V_189 ;
V_2 -> V_141 = V_189 ;
return V_159 ;
}
for ( V_16 = V_189 ; V_16 < V_2 -> V_141 ; V_16 ++ ) {
V_52 = F_27 ( V_19 , V_2 -> V_191 [ V_138 -> V_140 + V_16 ] ) ;
V_159 += F_98 ( V_19 , V_52 ) ;
}
return V_159 ;
}
static bool F_109 ( struct V_18 * V_19 , int V_193 ,
const T_1 * V_49 , T_1 * V_168 , int * V_114 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
bool V_67 = false ;
for ( V_16 = 0 ; V_16 < V_193 ; V_16 ++ ) {
struct V_6 * V_52 ;
T_1 V_166 ;
if ( V_168 [ V_16 ] )
continue;
V_166 = F_102 ( V_19 , V_49 [ V_16 ] ) ;
if ( ! V_166 )
continue;
V_52 = F_42 ( V_19 , V_166 , V_49 [ V_16 ] ,
- V_2 -> V_45 ) ;
if ( ! V_52 && ! V_16 && V_2 -> V_45 )
V_52 = F_42 ( V_19 , V_166 , V_49 [ V_16 ] , 0 ) ;
if ( V_52 ) {
V_168 [ V_16 ] = V_166 ;
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
T_1 V_194 , V_166 , V_46 ;
V_52 = F_27 ( V_19 , V_114 ) ;
if ( ! V_52 || ! V_52 -> V_53 ||
F_22 ( V_52 , V_2 -> V_45 ) )
return 0 ;
V_194 = V_52 -> V_52 [ 0 ] ;
V_166 = V_2 -> V_164 [ 0 ] ;
V_46 = V_52 -> V_52 [ V_52 -> V_53 - 1 ] ;
V_52 = F_42 ( V_19 , V_166 , V_46 , V_2 -> V_45 ) ;
if ( ! V_52 ) {
if ( V_166 != V_194 )
V_166 = V_194 ;
else if ( V_2 -> V_146 . V_148 [ 0 ] )
V_166 = V_2 -> V_146 . V_148 [ 0 ] ;
else if ( V_2 -> V_146 . V_149 [ 0 ] )
V_166 = V_2 -> V_146 . V_149 [ 0 ] ;
else
V_166 = 0 ;
if ( V_166 )
V_52 = F_42 ( V_19 , V_166 , V_46 ,
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
V_58 = V_2 -> V_191 [ 0 ] ;
else
V_58 = V_2 -> V_153 [ 0 ] ;
V_52 = F_27 ( V_19 , V_58 ) ;
if ( ! V_52 )
return false ;
if ( ! V_2 -> V_45 || ! F_22 ( V_52 , V_2 -> V_45 ) )
return true ;
for ( V_16 = 0 ; V_16 < V_138 -> V_140 ; V_16 ++ ) {
if ( V_2 -> V_191 [ V_16 ] == V_58 )
break;
V_52 = F_27 ( V_19 , V_2 -> V_191 [ V_16 ] ) ;
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
static void F_112 ( struct V_18 * V_19 , int V_167 ,
T_1 * V_168 , int * V_114 )
{
struct V_6 * V_52 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_167 ; V_16 ++ ) {
if ( V_168 [ V_16 ] )
continue;
V_52 = F_27 ( V_19 , V_114 [ V_16 ] ) ;
if ( ! V_52 )
continue;
V_168 [ V_16 ] = V_52 -> V_52 [ 0 ] ;
}
}
static int F_113 ( struct V_18 * V_19 ,
bool V_195 ,
bool V_196 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
int V_16 , V_197 , V_159 ;
V_2 -> V_146 . V_147 = V_138 -> V_140 ;
V_2 -> V_146 . V_198 = V_2 -> V_164 ;
memset ( V_2 -> V_164 , 0 , sizeof( V_2 -> V_164 ) ) ;
memset ( V_2 -> V_146 . V_148 , 0 , sizeof( V_2 -> V_146 . V_148 ) ) ;
memset ( V_2 -> V_146 . V_149 , 0 , sizeof( V_2 -> V_146 . V_149 ) ) ;
V_2 -> V_141 = 0 ;
F_9 ( & V_2 -> V_5 ) ;
memset ( V_2 -> V_191 , 0 , sizeof( V_2 -> V_191 ) ) ;
memset ( V_2 -> V_153 , 0 , sizeof( V_2 -> V_153 ) ) ;
memset ( V_2 -> V_155 , 0 , sizeof( V_2 -> V_155 ) ) ;
memset ( V_2 -> V_199 , 0 , sizeof( V_2 -> V_199 ) ) ;
memset ( V_2 -> V_200 , 0 , sizeof( V_2 -> V_200 ) ) ;
memset ( V_2 -> V_201 , 0 , sizeof( V_2 -> V_201 ) ) ;
memset ( V_2 -> V_202 , 0 , sizeof( V_2 -> V_202 ) ) ;
memset ( & V_2 -> V_203 , 0 , sizeof( V_2 -> V_203 ) ) ;
V_159 = 0 ;
if ( V_195 ) {
bool V_204 ;
do {
V_204 = F_109 ( V_19 , V_138 -> V_140 ,
V_138 -> V_205 ,
V_2 -> V_164 ,
V_2 -> V_191 ) ;
V_204 |= F_109 ( V_19 , V_138 -> V_142 ,
V_138 -> V_206 ,
V_2 -> V_146 . V_148 ,
V_2 -> V_153 ) ;
V_204 |= F_109 ( V_19 , V_138 -> V_143 ,
V_138 -> V_207 ,
V_2 -> V_146 . V_149 ,
V_2 -> V_155 ) ;
if ( ! V_2 -> V_36 &&
V_196 && V_138 -> V_140 == 1 &&
V_138 -> V_151 != V_152 ) {
V_197 = F_108 ( V_19 , V_138 -> V_205 [ 0 ] , true ) ;
if ( ! V_197 )
V_204 = true ;
}
} while ( V_204 );
}
V_159 += F_101 ( V_19 , V_138 -> V_140 , V_138 -> V_205 ,
V_2 -> V_164 , V_2 -> V_191 ,
V_2 -> V_208 ) ;
if ( ! V_2 -> V_36 && V_196 &&
V_138 -> V_140 == 1 && V_138 -> V_151 != V_152 ) {
V_197 = F_108 ( V_19 , V_138 -> V_205 [ 0 ] , false ) ;
if ( V_197 < 0 )
return V_197 ;
}
if ( V_138 -> V_151 != V_154 ) {
V_197 = F_101 ( V_19 , V_138 -> V_142 , V_138 -> V_206 ,
V_2 -> V_146 . V_148 ,
V_2 -> V_153 ,
V_2 -> V_209 ) ;
if ( V_197 < 0 )
return V_197 ;
V_159 += V_197 ;
}
if ( V_138 -> V_151 != V_152 ) {
V_197 = F_101 ( V_19 , V_138 -> V_143 ,
V_138 -> V_207 ,
V_2 -> V_146 . V_149 ,
V_2 -> V_155 ,
V_2 -> V_209 ) ;
if ( V_197 < 0 )
return V_197 ;
V_159 += V_197 ;
}
if ( ! V_2 -> V_36 &&
V_138 -> V_140 == 1 && V_138 -> V_151 != V_152 ) {
V_197 = F_108 ( V_19 , V_138 -> V_205 [ 0 ] , false ) ;
if ( V_197 < 0 )
return V_197 ;
V_159 += V_197 ;
}
if ( V_2 -> V_45 ) {
V_2 -> V_199 [ 0 ] =
F_110 ( V_19 , V_2 -> V_191 [ 0 ] ) ;
if ( V_138 -> V_151 != V_154 )
V_2 -> V_199 [ 1 ] =
F_110 ( V_19 , V_2 -> V_153 [ 0 ] ) ;
if ( V_138 -> V_151 != V_152 )
V_2 -> V_199 [ 2 ] =
F_110 ( V_19 , V_2 -> V_155 [ 0 ] ) ;
}
if ( ! V_2 -> V_36 &&
V_138 -> V_142 && V_138 -> V_151 == V_152 )
if ( F_107 ( V_19 , V_138 -> V_206 [ 0 ] ) >= 2 )
V_2 -> V_141 = 1 ;
V_2 -> V_146 . V_147 = 0 ;
for ( V_16 = 0 ; V_16 < V_138 -> V_140 ; V_16 ++ ) {
if ( V_2 -> V_164 [ V_16 ] )
V_2 -> V_146 . V_147 ++ ;
else {
memmove ( V_2 -> V_164 + V_16 ,
V_2 -> V_164 + V_16 + 1 ,
sizeof( T_1 ) * ( V_138 -> V_140 - V_16 - 1 ) ) ;
V_2 -> V_164 [ V_138 -> V_140 - 1 ] = 0 ;
}
}
V_2 -> V_210 = V_2 -> V_211 =
V_2 -> V_146 . V_147 * 2 ;
if ( V_2 -> V_141 == 2 ) {
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
V_2 -> V_164 [ V_2 -> V_146 . V_147 ++ ] =
V_2 -> V_165 [ V_16 ] . V_166 ;
} else if ( V_2 -> V_141 ) {
V_2 -> V_141 = 0 ;
V_159 += V_192 ;
}
if ( V_2 -> V_39 && ! F_111 ( V_19 ) )
V_159 += V_212 ;
if ( V_138 -> V_151 != V_154 )
F_112 ( V_19 , V_138 -> V_142 ,
V_2 -> V_146 . V_148 ,
V_2 -> V_153 ) ;
if ( V_138 -> V_151 != V_152 )
F_112 ( V_19 , V_138 -> V_143 ,
V_2 -> V_146 . V_149 ,
V_2 -> V_155 ) ;
return V_159 ;
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
static const char * const V_213 [ 3 ] = { L_41 , L_42 , L_43 } ;
int V_16 ;
F_116 ( L_44 ,
V_138 -> V_205 [ 0 ] , V_138 -> V_205 [ 1 ] ,
V_138 -> V_205 [ 2 ] , V_138 -> V_205 [ 3 ] ,
V_2 -> V_146 . V_198 [ 0 ] ,
V_2 -> V_146 . V_198 [ 1 ] ,
V_2 -> V_146 . V_198 [ 2 ] ,
V_2 -> V_146 . V_198 [ 3 ] ,
V_213 [ V_138 -> V_151 ] ) ;
for ( V_16 = 0 ; V_16 < V_138 -> V_140 ; V_16 ++ )
F_114 ( V_19 , L_45 , V_2 -> V_191 [ V_16 ] ) ;
if ( V_2 -> V_141 > 0 )
F_116 ( L_46 ,
V_2 -> V_141 ,
V_2 -> V_165 [ 0 ] . V_46 , V_2 -> V_165 [ 1 ] . V_46 ,
V_2 -> V_165 [ 0 ] . V_166 , V_2 -> V_165 [ 1 ] . V_166 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_141 ; V_16 ++ )
F_114 ( V_19 , L_47 ,
V_2 -> V_191 [ V_138 -> V_140 + V_16 ] ) ;
if ( V_138 -> V_142 )
F_116 ( L_48 ,
V_138 -> V_206 [ 0 ] , V_138 -> V_206 [ 1 ] ,
V_138 -> V_206 [ 2 ] , V_138 -> V_206 [ 3 ] ,
V_2 -> V_146 . V_148 [ 0 ] ,
V_2 -> V_146 . V_148 [ 1 ] ,
V_2 -> V_146 . V_148 [ 2 ] ,
V_2 -> V_146 . V_148 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_138 -> V_142 ; V_16 ++ )
F_114 ( V_19 , L_49 , V_2 -> V_153 [ V_16 ] ) ;
if ( V_138 -> V_143 )
F_116 ( L_50 ,
V_138 -> V_207 [ 0 ] , V_138 -> V_207 [ 1 ] ,
V_138 -> V_207 [ 2 ] , V_138 -> V_207 [ 3 ] ,
V_2 -> V_146 . V_149 [ 0 ] ,
V_2 -> V_146 . V_149 [ 1 ] ,
V_2 -> V_146 . V_149 [ 2 ] ,
V_2 -> V_146 . V_149 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_138 -> V_143 ; V_16 ++ )
F_114 ( V_19 , L_51 , V_2 -> V_155 [ V_16 ] ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ )
F_114 ( V_19 , L_52 , V_2 -> V_199 [ V_16 ] ) ;
}
static void F_117 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_50 = V_19 -> V_214 ;
V_2 -> V_76 = 0 ;
memset ( V_2 -> V_77 , 0 , sizeof( V_2 -> V_77 ) ) ;
for ( V_16 = 0 ; V_16 < V_19 -> V_215 ; V_16 ++ , V_50 ++ ) {
if ( F_39 ( F_40 ( V_19 , V_50 ) ) != V_66 )
continue;
if ( V_2 -> V_76 >= F_96 ( V_2 -> V_77 ) ) {
F_118 ( V_19 , L_53 ) ;
break;
}
V_2 -> V_77 [ V_2 -> V_76 ++ ] = V_50 ;
}
}
static int F_119 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
struct V_137 * V_216 ;
unsigned int V_20 ;
int V_217 = V_218 ;
int V_159 ;
bool V_195 = true , V_196 = true ;
bool V_219 = true , V_220 = true ;
bool V_221 = false ;
V_216 = F_120 ( sizeof( * V_216 ) , V_13 ) ;
if ( ! V_216 )
return - V_123 ;
* V_216 = * V_138 ;
for (; ; ) {
V_159 = F_113 ( V_19 , V_195 ,
V_196 ) ;
if ( V_159 < 0 ) {
F_8 ( V_216 ) ;
return V_159 ;
}
F_116 ( L_54 ,
V_138 -> V_151 , V_195 , V_196 ,
V_159 ) ;
F_115 ( V_19 , V_138 ) ;
if ( V_159 < V_217 ) {
V_217 = V_159 ;
* V_216 = * V_138 ;
V_219 = V_195 ;
V_220 = V_196 ;
}
if ( ! V_159 )
break;
V_196 = ! V_196 ;
if ( ! V_196 )
continue;
V_195 = ! V_195 ;
if ( ! V_195 )
continue;
if ( V_221 )
break;
V_221 = true ;
if ( V_138 -> V_143 > 0 &&
V_138 -> V_151 == V_154 ) {
V_138 -> V_142 = V_138 -> V_140 ;
memcpy ( V_138 -> V_206 , V_138 -> V_205 ,
sizeof( V_138 -> V_206 ) ) ;
V_138 -> V_140 = V_138 -> V_143 ;
memcpy ( V_138 -> V_205 , V_138 -> V_207 ,
sizeof( V_138 -> V_207 ) ) ;
V_138 -> V_143 = 0 ;
memset ( V_138 -> V_207 , 0 , sizeof( V_138 -> V_207 ) ) ;
V_138 -> V_151 = V_152 ;
V_195 = true ;
continue;
}
if ( V_138 -> V_142 > 0 &&
V_138 -> V_151 == V_152 ) {
V_138 -> V_143 = V_138 -> V_140 ;
memcpy ( V_138 -> V_207 , V_138 -> V_205 ,
sizeof( V_138 -> V_207 ) ) ;
V_138 -> V_140 = V_138 -> V_142 ;
memcpy ( V_138 -> V_205 , V_138 -> V_206 ,
sizeof( V_138 -> V_206 ) ) ;
V_138 -> V_142 = 0 ;
memset ( V_138 -> V_206 , 0 , sizeof( V_138 -> V_206 ) ) ;
V_138 -> V_151 = V_154 ;
V_195 = true ;
continue;
}
break;
}
if ( V_159 ) {
F_116 ( L_55 ) ;
* V_138 = * V_216 ;
F_113 ( V_19 , V_219 , V_220 ) ;
}
F_116 ( L_56 ,
V_138 -> V_151 , V_219 , V_220 ) ;
F_115 ( V_19 , V_138 ) ;
if ( V_138 -> V_205 [ 0 ] ) {
struct V_6 * V_52 ;
V_52 = F_27 ( V_19 , V_2 -> V_191 [ 0 ] ) ;
if ( V_52 )
V_2 -> V_222 = F_51 ( V_19 , V_52 ) ;
if ( V_2 -> V_222 ) {
F_121 ( V_19 , V_2 -> V_222 ,
V_82 , V_2 -> V_223 ) ;
if ( V_2 -> V_161 )
V_2 -> V_223 [ 3 ] |= V_224 ;
}
}
if ( V_2 -> V_225 || V_138 -> V_151 == V_154 )
V_20 = V_226 ;
else
V_20 = V_227 ;
F_20 ( V_19 , V_138 -> V_140 , V_138 -> V_205 , V_20 ) ;
if ( V_138 -> V_151 != V_154 )
F_20 ( V_19 , V_138 -> V_142 , V_138 -> V_206 , V_226 ) ;
if ( V_138 -> V_151 != V_152 ) {
V_20 = V_2 -> V_225 ? V_226 : V_227 ;
F_20 ( V_19 , V_138 -> V_143 ,
V_138 -> V_207 , V_20 ) ;
}
if ( V_2 -> V_39 && ! F_111 ( V_19 ) )
V_2 -> V_39 = 0 ;
F_8 ( V_216 ) ;
return 0 ;
}
static int F_122 ( struct V_18 * V_19 ,
const struct V_137 * V_138 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_197 , V_228 ;
V_228 = V_138 -> V_140 ;
if ( V_2 -> V_141 > 0 && V_138 -> V_140 < 3 )
V_228 += V_2 -> V_141 ;
for ( V_16 = 0 ; V_16 < V_228 ; V_16 ++ ) {
const char * V_10 ;
int V_117 ;
struct V_6 * V_52 ;
V_52 = F_27 ( V_19 , V_2 -> V_191 [ V_16 ] ) ;
if ( ! V_52 )
continue;
V_10 = F_95 ( V_19 , V_16 , & V_117 , V_99 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_57 ) ) {
V_197 = F_78 ( V_19 , L_58 , 0 , 1 , V_52 ) ;
if ( V_197 < 0 )
return V_197 ;
V_197 = F_78 ( V_19 , L_59 , 0 , 2 , V_52 ) ;
if ( V_197 < 0 )
return V_197 ;
} else {
V_197 = F_81 ( V_19 , V_10 , V_117 , V_52 ) ;
if ( V_197 < 0 )
return V_197 ;
}
V_10 = F_95 ( V_19 , V_16 , & V_117 , V_98 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_57 ) ) {
V_197 = F_82 ( V_19 , L_58 , 0 , 1 , V_52 ) ;
if ( V_197 < 0 )
return V_197 ;
V_197 = F_82 ( V_19 , L_59 , 0 , 2 , V_52 ) ;
if ( V_197 < 0 )
return V_197 ;
} else {
V_197 = F_86 ( V_19 , V_10 , V_117 , V_52 ) ;
if ( V_197 < 0 )
return V_197 ;
}
}
return 0 ;
}
static int F_123 ( struct V_18 * V_19 , int V_114 ,
const char * V_62 , int V_115 )
{
struct V_6 * V_52 ;
int V_197 ;
V_52 = F_27 ( V_19 , V_114 ) ;
if ( ! V_52 )
return 0 ;
V_197 = F_81 ( V_19 , V_62 , V_115 , V_52 ) ;
if ( V_197 < 0 )
return V_197 ;
V_197 = F_86 ( V_19 , V_62 , V_115 , V_52 ) ;
if ( V_197 < 0 )
return V_197 ;
return 0 ;
}
static int F_124 ( struct V_18 * V_19 , int V_48 ,
const int * V_5 , const char * V_62 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
const char * V_10 ;
char V_229 [ V_122 ] ;
int V_197 , V_58 = 0 ;
if ( V_48 == 2 && V_16 == 1 && ! strcmp ( V_62 , L_35 ) )
V_10 = L_36 ;
else if ( V_48 >= 3 ) {
snprintf ( V_229 , sizeof( V_229 ) , L_60 ,
V_62 , V_150 [ V_16 ] ) ;
V_10 = V_229 ;
} else {
V_10 = V_62 ;
V_58 = V_16 ;
}
V_197 = F_123 ( V_19 , V_5 [ V_16 ] , V_10 , V_58 ) ;
if ( V_197 < 0 )
return V_197 ;
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
struct V_230 * V_231 )
{
return F_128 ( V_129 , V_231 ) ;
}
static int F_129 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_131 -> V_134 . V_232 . V_233 [ 0 ] = V_2 -> V_234 ;
return 0 ;
}
static int F_130 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_235 = V_131 -> V_134 . V_232 . V_233 [ 0 ] ;
int V_236 = 0 ;
F_131 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_237 ) {
V_236 = - V_238 ;
goto V_239;
}
if ( V_2 -> V_234 != V_235 ) {
T_1 * V_240 ;
if ( V_2 -> V_139 . V_151 == V_154 )
V_240 = & V_2 -> V_164 [ 0 ] ;
else
V_240 = & V_2 -> V_146 . V_148 [ 0 ] ;
if ( V_2 -> V_241 ) {
if ( V_2 -> V_139 . V_151 == V_154 )
F_132 ( V_19 , V_2 -> V_242 ,
V_2 -> V_191 [ 0 ] ,
V_2 -> V_199 [ 0 ] ,
V_2 -> V_139 . V_151 ) ;
else
F_132 ( V_19 , V_2 -> V_242 ,
V_2 -> V_153 [ 0 ] ,
V_2 -> V_199 [ 1 ] ,
V_154 ) ;
}
V_2 -> V_234 = V_235 ;
if ( V_2 -> V_234 )
* V_240 = 0 ;
else
* V_240 = V_2 -> V_243 ;
F_133 ( V_19 , NULL ) ;
V_236 = 1 ;
}
V_239:
F_134 ( & V_2 -> V_9 ) ;
return V_236 ;
}
static int F_135 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_166 ;
if ( ! V_2 -> V_39 )
return 0 ;
if ( V_2 -> V_139 . V_151 == V_154 )
V_166 = V_2 -> V_146 . V_198 [ 0 ] ;
else
V_166 = V_2 -> V_146 . V_148 [ 0 ] ;
if ( ! V_166 ) {
V_2 -> V_39 = 0 ;
return 0 ;
}
V_2 -> V_234 = false ;
V_2 -> V_243 = V_166 ;
if ( ! F_4 ( V_2 , NULL , & V_244 ) )
return - V_123 ;
return 0 ;
}
static int F_136 ( struct V_128 * V_129 ,
struct V_230 * V_231 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_79 ;
V_231 -> type = V_245 ;
V_231 -> V_246 = 1 ;
V_231 -> V_134 . V_232 . V_247 = V_2 -> V_141 + 1 ;
if ( V_231 -> V_134 . V_232 . V_233 > V_2 -> V_141 )
V_231 -> V_134 . V_232 . V_233 = V_2 -> V_141 ;
V_79 = V_231 -> V_134 . V_232 . V_233 * 2 + V_2 -> V_211 ;
sprintf ( V_231 -> V_134 . V_232 . V_10 , L_61 , V_79 ) ;
return 0 ;
}
static int F_137 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_131 -> V_134 . V_232 . V_233 [ 0 ] =
( V_2 -> V_210 - V_2 -> V_211 ) / 2 ;
return 0 ;
}
static inline struct V_6 *
F_138 ( struct V_18 * V_19 , int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_27 ( V_19 ,
V_2 -> V_191 [ V_2 -> V_139 . V_140 + V_58 ] ) ;
}
static bool F_139 ( struct V_1 * V_2 )
{
return ! V_2 -> V_241 || V_2 -> V_242 ;
}
static int F_140 ( struct V_18 * V_19 , int V_58 , bool V_248 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_50 = V_2 -> V_165 [ V_58 ] . V_46 ;
struct V_6 * V_52 ;
V_52 = F_138 ( V_19 , V_58 ) ;
if ( ! V_52 )
return - V_249 ;
if ( V_52 -> V_89 == V_248 )
return 0 ;
if ( V_248 ) {
F_17 ( V_19 , V_50 , V_227 , true ) ;
F_64 ( V_19 , V_52 , true , F_139 ( V_2 ) ) ;
F_72 ( V_19 , V_50 , true ) ;
} else {
F_72 ( V_19 , V_50 , false ) ;
F_64 ( V_19 , V_52 , false , F_139 ( V_2 ) ) ;
F_17 ( V_19 , V_50 , V_2 -> V_165 [ V_58 ] . V_250 , true ) ;
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
V_136 = V_131 -> V_134 . V_232 . V_233 [ 0 ] ;
if ( V_136 < 0 || V_136 > V_2 -> V_141 )
return - V_249 ;
if ( V_136 == ( V_2 -> V_210 - V_2 -> V_211 ) / 2 )
return 0 ;
V_2 -> V_210 = V_136 * 2 + V_2 -> V_211 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_141 ; V_16 ++ )
F_140 ( V_19 , V_16 , V_16 < V_136 ) ;
V_2 -> V_146 . V_251 = F_143 ( V_2 -> V_210 ,
V_2 -> V_252 ) ;
if ( V_2 -> V_34 )
V_2 -> V_146 . V_147 = V_2 -> V_146 . V_251 / 2 ;
return 1 ;
}
static int F_144 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_141 > 0 ) {
if ( ! F_4 ( V_2 , NULL , & V_253 ) )
return - V_123 ;
}
return 0 ;
}
static int F_145 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_131 -> V_134 . V_232 . V_233 [ 0 ] = V_2 -> V_242 ;
return 0 ;
}
static void F_132 ( struct V_18 * V_19 , bool V_254 ,
int V_255 , int V_256 ,
int V_257 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_258 , * V_259 ;
V_258 = F_27 ( V_19 , V_255 ) ;
V_259 = F_27 ( V_19 , V_256 ) ;
if ( ! V_258 || ! V_259 )
return;
if ( V_257 == V_154 && V_2 -> V_234 &&
V_259 -> V_52 [ 0 ] != V_2 -> V_243 )
V_254 = false ;
if ( V_254 ) {
F_64 ( V_19 , V_258 , false , true ) ;
F_64 ( V_19 , V_259 , true , true ) ;
F_68 ( V_19 , V_258 ) ;
} else {
F_64 ( V_19 , V_259 , false , false ) ;
F_64 ( V_19 , V_258 , true , false ) ;
F_68 ( V_19 , V_259 ) ;
}
}
static int F_146 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = V_131 -> V_134 . V_232 . V_233 [ 0 ] ;
if ( V_20 == V_2 -> V_242 )
return 0 ;
V_2 -> V_242 = V_20 ;
F_132 ( V_19 , V_20 , V_2 -> V_191 [ 0 ] ,
V_2 -> V_199 [ 0 ] ,
V_2 -> V_139 . V_151 ) ;
F_132 ( V_19 , V_20 , V_2 -> V_153 [ 0 ] ,
V_2 -> V_199 [ 1 ] ,
V_154 ) ;
F_132 ( V_19 , V_20 , V_2 -> V_155 [ 0 ] ,
V_2 -> V_199 [ 2 ] ,
V_152 ) ;
return 1 ;
}
static int F_147 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_45 )
return 0 ;
if ( ! ( V_2 -> V_199 [ 0 ] || V_2 -> V_199 [ 1 ] ||
V_2 -> V_199 [ 2 ] ) )
return 0 ;
if ( ! F_4 ( V_2 , NULL , & V_260 ) )
return - V_123 ;
V_2 -> V_241 = 1 ;
return 0 ;
}
static void F_148 ( struct V_18 * V_19 , int V_261 , bool V_262 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_263 ;
unsigned int V_20 ;
T_1 V_46 ;
V_46 = V_2 -> V_264 ;
V_263 = V_2 -> V_265 [ V_261 ] == V_2 -> V_266 ;
if ( ! V_262 ) {
V_20 = F_16 ( V_19 , V_46 ) ;
if ( V_263 ) {
if ( V_20 & V_267 )
return;
} else {
if ( V_20 & V_227 )
return;
}
}
V_20 = F_149 ( V_19 , V_46 ) ;
if ( V_20 == V_268 && V_2 -> V_269 ) {
const T_1 V_270 = V_2 -> V_269 ;
unsigned int V_271 = F_149 ( V_19 , V_270 ) ;
if ( V_271 != V_268 )
F_150 ( V_19 , V_270 ,
V_267 | ( V_263 ? V_271 : 0 ) ) ;
}
if ( ! V_2 -> V_272 ) {
if ( V_263 )
V_20 |= V_267 ;
else
V_20 = V_226 ;
F_17 ( V_19 , V_46 , V_20 , true ) ;
F_133 ( V_19 , NULL ) ;
}
}
static int F_151 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
unsigned int V_180 ;
T_1 V_50 ;
if ( ! V_2 -> V_43 ) {
if ( V_2 -> V_44 )
return 0 ;
if ( V_138 -> V_186 > 1 )
return 0 ;
else if ( V_138 -> V_186 == 1 ) {
V_180 = F_104 ( V_19 , V_138 -> V_187 [ 0 ] . V_46 ) ;
if ( F_152 ( V_180 ) != V_273 )
return 0 ;
}
}
V_2 -> V_43 = 0 ;
if ( V_138 -> V_186 >= V_274 )
return 0 ;
V_50 = 0 ;
if ( V_138 -> V_151 == V_154 && V_138 -> V_140 > 0 )
V_50 = V_138 -> V_205 [ 0 ] ;
else if ( V_138 -> V_142 > 0 )
V_50 = V_138 -> V_206 [ 0 ] ;
if ( ! V_50 )
return 0 ;
if ( ! ( F_73 ( V_19 , V_50 ) & V_275 ) )
return 0 ;
V_138 -> V_187 [ V_138 -> V_186 ] . V_46 = V_50 ;
V_138 -> V_187 [ V_138 -> V_186 ] . type = V_185 ;
V_138 -> V_187 [ V_138 -> V_186 ] . V_276 = 1 ;
V_138 -> V_186 ++ ;
V_2 -> V_43 = 1 ;
V_2 -> V_264 = V_50 ;
V_2 -> V_31 = 1 ;
F_36 ( V_19 , L_62 , V_50 ) ;
return 0 ;
}
static int F_153 ( struct V_128 * V_129 ,
struct V_230 * V_231 )
{
return F_154 ( V_129 , V_231 , 2 , V_277 ) ;
}
static int F_155 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
T_1 V_50 = V_129 -> V_120 ;
if ( F_16 ( V_19 , V_50 ) == V_226 )
V_131 -> V_134 . V_232 . V_233 [ 0 ] = 1 ;
else
V_131 -> V_134 . V_232 . V_233 [ 0 ] = 0 ;
return 0 ;
}
static int F_156 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
T_1 V_50 = V_129 -> V_120 ;
unsigned int V_20 ;
V_20 = V_131 -> V_134 . V_232 . V_233 [ 0 ] ? V_226 : V_227 ;
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
char * V_10 , T_3 V_278 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_58 = 0 ;
F_159 ( V_19 , V_46 , & V_2 -> V_139 , V_10 , V_278 , & V_58 ) ;
F_160 ( V_10 , L_63 , V_278 ) ;
for (; F_157 ( V_19 , V_10 , V_58 ) ; V_58 ++ )
;
}
static int F_161 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_41 ) {
unsigned int V_279 = F_73 ( V_19 , V_46 ) ;
if ( ( V_279 & V_182 ) && ( V_279 & V_280 ) )
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
if ( V_46 == V_2 -> V_264 )
continue;
if ( F_161 ( V_19 , V_46 ) > 1 ) {
struct V_4 * V_12 ;
char V_10 [ V_122 ] ;
F_158 ( V_19 , V_46 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 ,
& V_281 ) ;
if ( ! V_12 )
return - V_123 ;
V_12 -> V_120 = V_46 ;
}
}
return 0 ;
}
static unsigned int F_163 ( struct V_18 * V_19 , T_1 V_46 )
{
unsigned int V_279 ;
V_279 = F_73 ( V_19 , V_46 ) ;
V_279 = ( V_279 & V_282 ) >> V_283 ;
V_279 &= ~ ( V_284 | V_285 ) ;
return V_279 ;
}
static int F_164 ( unsigned int V_286 , unsigned int V_287 )
{
unsigned int V_16 , V_88 = 0 ;
for ( V_16 = 0 ; V_16 < V_288 ; V_16 ++ ) {
if ( V_286 & ( 1 << V_16 ) ) {
if ( V_88 == V_287 )
return V_16 ;
V_88 ++ ;
}
}
return 0 ;
}
static int F_165 ( unsigned int V_286 , unsigned int V_58 )
{
unsigned int V_16 , V_88 = 0 ;
for ( V_16 = 0 ; V_16 < V_288 ; V_16 ++ ) {
if ( V_16 == V_58 )
return V_88 ;
if ( V_286 & ( 1 << V_16 ) )
V_88 ++ ;
}
return 0 ;
}
static int F_166 ( struct V_128 * V_129 ,
struct V_230 * V_231 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
T_1 V_50 = V_129 -> V_120 ;
unsigned int V_286 = F_163 ( V_19 , V_50 ) ;
F_154 ( V_129 , V_231 , F_167 ( V_286 ) ,
V_289 ) ;
strcpy ( V_231 -> V_134 . V_232 . V_10 ,
V_289 [ F_164 ( V_286 , V_231 -> V_134 . V_232 . V_233 ) ] ) ;
return 0 ;
}
static int F_168 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
T_1 V_50 = V_129 -> V_120 ;
unsigned int V_286 = F_163 ( V_19 , V_50 ) ;
unsigned int V_58 ;
V_58 = F_16 ( V_19 , V_50 ) & V_290 ;
V_131 -> V_134 . V_232 . V_233 [ 0 ] = F_165 ( V_286 , V_58 ) ;
return 0 ;
}
static int F_169 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
T_1 V_50 = V_129 -> V_120 ;
unsigned int V_286 = F_163 ( V_19 , V_50 ) ;
unsigned int V_20 , V_58 ;
V_20 = F_16 ( V_19 , V_50 ) ;
V_58 = F_165 ( V_286 , V_20 & V_290 ) ;
if ( V_58 == V_131 -> V_134 . V_232 . V_233 [ 0 ] )
return 0 ;
V_20 &= ~ V_290 ;
V_20 |= F_164 ( V_286 , V_131 -> V_134 . V_232 . V_233 [ 0 ] ) ;
F_150 ( V_19 , V_50 , V_20 ) ;
return 1 ;
}
static int F_170 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_291 = 0 ;
if ( V_2 -> V_41 )
V_291 = F_167 ( F_163 ( V_19 , V_46 ) ) ;
return V_291 ? V_291 : 1 ;
}
static int F_171 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
char V_10 [ V_122 ] ;
unsigned int V_180 ;
if ( V_46 == V_2 -> V_264 )
return 0 ;
V_180 = F_104 ( V_19 , V_46 ) ;
if ( F_152 ( V_180 ) == V_273 )
return 0 ;
if ( F_170 ( V_19 , V_46 ) <= 1 )
return 0 ;
F_158 ( V_19 , V_46 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 , & V_292 ) ;
if ( ! V_12 )
return - V_123 ;
V_12 -> V_120 = V_46 ;
return 0 ;
}
static int F_172 ( struct V_128 * V_129 ,
struct V_230 * V_231 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
T_1 V_50 = V_129 -> V_120 ;
int V_293 = F_161 ( V_19 , V_50 ) ;
int V_294 = F_170 ( V_19 , V_50 ) ;
const char * V_295 = NULL ;
int V_58 ;
V_231 -> type = V_245 ;
V_231 -> V_246 = 1 ;
V_231 -> V_134 . V_232 . V_247 = V_293 + V_294 ;
if ( V_231 -> V_134 . V_232 . V_233 >= V_231 -> V_134 . V_232 . V_247 )
V_231 -> V_134 . V_232 . V_233 = V_231 -> V_134 . V_232 . V_247 - 1 ;
V_58 = V_231 -> V_134 . V_232 . V_233 ;
if ( V_58 < V_293 ) {
if ( V_293 > 1 )
V_295 = V_277 [ V_58 ] ;
else
V_295 = L_64 ;
} else {
V_58 -= V_293 ;
if ( V_294 > 1 ) {
unsigned int V_286 = F_163 ( V_19 , V_50 ) ;
V_295 = V_289 [ F_164 ( V_286 , V_58 ) ] ;
} else
V_295 = L_65 ;
}
strcpy ( V_231 -> V_134 . V_232 . V_10 , V_295 ) ;
return 0 ;
}
static int F_173 ( struct V_18 * V_19 , T_1 V_50 )
{
int V_293 = F_161 ( V_19 , V_50 ) ;
int V_294 = F_170 ( V_19 , V_50 ) ;
unsigned int V_20 = F_16 ( V_19 , V_50 ) ;
int V_58 = 0 ;
if ( V_20 & V_227 ) {
if ( V_293 > 1 && V_20 == V_226 )
V_58 = 1 ;
} else if ( V_20 & V_267 ) {
V_58 = V_293 ;
if ( V_294 > 1 ) {
unsigned int V_286 = F_163 ( V_19 , V_50 ) ;
V_20 &= V_290 ;
V_58 += F_165 ( V_286 , V_20 ) ;
}
}
return V_58 ;
}
static int F_174 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
T_1 V_50 = V_129 -> V_120 ;
V_131 -> V_134 . V_232 . V_233 [ 0 ] =
F_173 ( V_19 , V_50 ) ;
return 0 ;
}
static int F_175 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
T_1 V_50 = V_129 -> V_120 ;
int V_293 = F_161 ( V_19 , V_50 ) ;
int V_294 = F_170 ( V_19 , V_50 ) ;
unsigned int V_20 , V_296 , V_58 ;
V_296 = F_173 ( V_19 , V_50 ) ;
V_58 = V_131 -> V_134 . V_232 . V_233 [ 0 ] ;
if ( V_296 == V_58 )
return 0 ;
if ( V_58 < V_293 ) {
if ( V_293 > 1 )
V_20 = V_58 ? V_226 : V_227 ;
else
V_20 = V_226 ;
} else {
V_58 -= V_293 ;
if ( V_294 > 1 ) {
unsigned int V_286 = F_163 ( V_19 , V_50 ) ;
V_20 = F_16 ( V_19 , V_50 ) ;
V_20 &= ~ ( V_290 | V_226 ) ;
V_20 |= F_164 ( V_286 , V_58 ) | V_267 ;
} else
V_20 = F_149 ( V_19 , V_50 ) | V_267 ;
}
F_150 ( V_19 , V_50 , V_20 ) ;
F_133 ( V_19 , NULL ) ;
return 1 ;
}
static int F_176 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
V_12 = F_4 ( V_2 , L_66 ,
& V_297 ) ;
if ( ! V_12 )
return - V_123 ;
V_12 -> V_120 = V_46 ;
V_2 -> V_272 = 1 ;
return 0 ;
}
static int F_177 ( struct V_1 * V_2 , T_1 V_298 , int V_58 )
{
struct V_8 * V_14 ;
V_14 = F_5 ( & V_2 -> V_7 ) ;
if ( ! V_14 )
return - V_123 ;
V_14 -> V_50 = V_298 ;
V_14 -> V_61 = V_83 ;
V_14 -> V_58 = V_58 ;
V_2 -> V_299 . V_300 = V_2 -> V_7 . V_14 ;
return 0 ;
}
static bool F_178 ( struct V_18 * V_19 , T_1 V_301 ,
T_1 V_46 , unsigned int * V_302 ,
unsigned int * V_303 )
{
int V_58 , V_304 ;
const T_1 * V_14 ;
T_1 V_50 ;
V_58 = F_30 ( V_19 , V_301 , V_46 , true ) ;
if ( V_58 < 0 )
return false ;
* V_302 = * V_303 = 0 ;
if ( F_52 ( V_19 , V_301 , V_83 ) )
* V_302 = F_33 ( V_301 , 3 , V_58 , V_83 ) ;
if ( F_50 ( V_19 , V_301 , V_83 ) )
* V_303 = F_33 ( V_301 , 3 , V_58 , V_83 ) ;
if ( * V_302 && * V_303 )
return true ;
V_304 = F_38 ( V_19 , V_301 , & V_14 ) ;
if ( V_304 < V_58 )
return false ;
V_50 = V_14 [ V_58 ] ;
if ( ! * V_302 && F_52 ( V_19 , V_50 , V_82 ) &&
! F_32 ( V_19 , V_50 , V_82 , 0 , V_99 ) )
* V_302 = F_33 ( V_50 , 3 , 0 , V_82 ) ;
if ( ! * V_303 && F_50 ( V_19 , V_50 , V_82 ) &&
! F_32 ( V_19 , V_50 , V_82 , 0 , V_98 ) )
* V_303 = F_33 ( V_50 , 3 , 0 , V_82 ) ;
return * V_302 || * V_303 ;
}
static int F_179 ( struct V_18 * V_19 , int V_305 ,
T_1 V_46 , const char * V_306 , int V_307 ,
T_1 V_301 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_52 ;
unsigned int V_302 , V_303 ;
int V_197 , V_58 ;
if ( ! F_178 ( V_19 , V_301 , V_46 , & V_302 , & V_303 ) )
return 0 ;
V_52 = F_42 ( V_19 , V_46 , V_301 , 0 ) ;
if ( ! V_52 )
return - V_249 ;
F_34 ( V_19 , L_67 , V_52 ) ;
V_2 -> V_202 [ V_305 ] = F_26 ( V_19 , V_52 ) ;
V_58 = V_52 -> V_58 [ V_52 -> V_53 - 1 ] ;
if ( V_302 ) {
V_197 = F_79 ( V_2 , V_124 , V_306 , V_307 , V_302 ) ;
if ( V_197 < 0 )
return V_197 ;
V_52 -> V_60 [ V_99 ] = V_302 ;
}
if ( V_303 ) {
V_197 = F_85 ( V_2 , V_126 , V_306 , V_307 , V_303 ) ;
if ( V_197 < 0 )
return V_197 ;
V_52 -> V_60 [ V_98 ] = V_303 ;
}
V_52 -> V_89 = true ;
V_197 = F_177 ( V_2 , V_301 , V_58 ) ;
if ( V_197 < 0 )
return V_197 ;
if ( V_2 -> V_45 != V_2 -> V_103 &&
! V_2 -> V_308 ) {
V_52 = F_42 ( V_19 , V_2 -> V_45 ,
V_2 -> V_103 , 0 ) ;
if ( V_52 ) {
F_34 ( V_19 , L_68 , V_52 ) ;
V_52 -> V_89 = true ;
V_2 -> V_308 =
F_26 ( V_19 , V_52 ) ;
}
}
return 0 ;
}
static int F_180 ( struct V_18 * V_19 , T_1 V_50 )
{
unsigned int V_279 = F_73 ( V_19 , V_50 ) ;
return ( V_279 & V_275 ) != 0 ;
}
static int F_181 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_50 ;
T_1 * V_309 = V_2 -> V_309 ;
int V_310 = F_96 ( V_2 -> V_309 ) ;
int V_16 , V_51 = 0 ;
V_50 = V_19 -> V_214 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_215 ; V_16 ++ , V_50 ++ ) {
unsigned int V_85 = F_40 ( V_19 , V_50 ) ;
int type = F_39 ( V_85 ) ;
if ( type != V_69 || ( V_85 & V_78 ) )
continue;
V_309 [ V_51 ] = V_50 ;
if ( ++ V_51 >= V_310 )
break;
}
V_2 -> V_311 = V_51 ;
V_2 -> V_312 = V_51 ;
memcpy ( V_2 -> V_313 , V_2 -> V_309 , V_51 * sizeof( T_1 ) ) ;
return V_51 ;
}
static int F_182 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_314 * V_315 = & V_2 -> V_316 ;
unsigned int V_317 ;
int V_16 , V_88 , V_51 ;
V_51 = 0 ;
V_317 = 0 ;
for ( V_88 = 0 ; V_88 < V_2 -> V_311 ; V_88 ++ ) {
for ( V_16 = 0 ; V_16 < V_315 -> V_318 ; V_16 ++ ) {
if ( ! V_2 -> V_201 [ V_16 ] [ V_88 ] )
break;
}
if ( V_16 >= V_315 -> V_318 ) {
V_317 |= ( 1 << V_88 ) ;
V_51 ++ ;
}
}
if ( ! V_317 ) {
for ( V_16 = 0 ; V_16 < V_315 -> V_318 ; V_16 ++ ) {
for ( V_88 = 0 ; V_88 < V_2 -> V_311 ; V_88 ++ ) {
if ( V_2 -> V_201 [ V_16 ] [ V_88 ] ) {
V_2 -> V_319 [ V_16 ] = V_88 ;
break;
}
}
}
F_36 ( V_19 , L_69 ) ;
V_2 -> V_320 = 1 ;
} else if ( V_51 != V_2 -> V_311 ) {
V_51 = 0 ;
for ( V_88 = 0 ; V_88 < V_2 -> V_311 ; V_88 ++ ) {
if ( ! ( V_317 & ( 1 << V_88 ) ) )
continue;
if ( V_88 != V_51 ) {
V_2 -> V_309 [ V_51 ] = V_2 -> V_309 [ V_88 ] ;
for ( V_16 = 0 ; V_16 < V_315 -> V_318 ; V_16 ++ ) {
F_43 ( V_19 ,
V_2 -> V_201 [ V_16 ] [ V_51 ] ) ;
V_2 -> V_201 [ V_16 ] [ V_51 ] =
V_2 -> V_201 [ V_16 ] [ V_88 ] ;
}
}
V_51 ++ ;
}
V_2 -> V_311 = V_51 ;
}
if ( V_315 -> V_318 == 1 ||
( V_315 -> V_318 == 2 && V_2 -> V_43 ) ) {
F_36 ( V_19 , L_70 ) ;
V_2 -> V_311 = 1 ;
}
if ( ! V_2 -> V_320 && V_2 -> V_37 )
V_2 -> V_311 = 1 ;
return 0 ;
}
static int F_183 ( struct V_18 * V_19 , T_1 V_46 ,
int V_321 , int V_322 ,
const char * V_323 , int V_324 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_314 * V_315 = & V_2 -> V_316 ;
int V_325 = V_315 -> V_318 ;
bool V_326 = false ;
int V_327 ;
for ( V_327 = 0 ; V_327 < V_322 ; V_327 ++ ) {
struct V_6 * V_52 ;
T_1 V_328 = V_2 -> V_309 [ V_327 ] ;
if ( ! F_29 ( V_19 , V_46 , V_328 ) )
continue;
V_52 = F_42 ( V_19 , V_46 , V_328 , V_324 ) ;
if ( ! V_52 )
continue;
F_34 ( V_19 , L_71 , V_52 ) ;
V_2 -> V_201 [ V_325 ] [ V_327 ] =
F_26 ( V_19 , V_52 ) ;
if ( ! V_326 ) {
if ( V_2 -> V_264 == V_46 )
V_2 -> V_266 = V_315 -> V_318 ;
V_2 -> V_329 [ V_315 -> V_318 ] = V_46 ;
F_184 ( V_19 , V_315 , V_323 , V_321 , NULL ) ;
V_326 = true ;
if ( V_2 -> V_320 )
V_2 -> V_319 [ V_325 ] = V_327 ;
}
}
return 0 ;
}
static int F_185 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_137 * V_138 = & V_2 -> V_139 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_138 -> V_186 ; V_16 ++ ) {
T_1 V_46 = V_138 -> V_187 [ V_16 ] . V_46 ;
const char * V_323 ;
int V_171 , V_58 ;
if ( ! F_180 ( V_19 , V_46 ) )
continue;
V_323 = F_186 ( V_19 , V_138 , V_16 ) ;
V_58 = 0 ;
for ( V_171 = V_16 - 1 ; V_171 >= 0 ; V_171 -- ) {
if ( V_2 -> V_330 [ V_171 ] &&
! strcmp ( V_2 -> V_330 [ V_171 ] , V_323 ) ) {
V_58 = V_2 -> V_331 [ V_171 ] + 1 ;
break;
}
}
V_2 -> V_330 [ V_16 ] = V_323 ;
V_2 -> V_331 [ V_16 ] = V_58 ;
}
return 0 ;
}
static int F_187 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_137 * V_138 = & V_2 -> V_139 ;
T_1 V_332 = V_2 -> V_45 ;
int V_322 ;
int V_16 , V_197 ;
unsigned int V_20 ;
V_322 = F_181 ( V_19 ) ;
if ( V_322 < 0 )
return 0 ;
V_197 = F_185 ( V_19 ) ;
if ( V_197 < 0 )
return V_197 ;
for ( V_16 = 0 ; V_16 < V_138 -> V_186 ; V_16 ++ ) {
T_1 V_46 ;
V_46 = V_138 -> V_187 [ V_16 ] . V_46 ;
if ( ! F_180 ( V_19 , V_46 ) )
continue;
V_20 = V_267 ;
if ( V_138 -> V_187 [ V_16 ] . type == V_185 )
V_20 |= F_149 ( V_19 , V_46 ) ;
if ( V_46 != V_2 -> V_264 )
F_17 ( V_19 , V_46 , V_20 , false ) ;
if ( V_332 ) {
if ( F_29 ( V_19 , V_46 , V_332 ) ) {
V_197 = F_179 ( V_19 , V_16 , V_46 ,
V_2 -> V_330 [ V_16 ] ,
V_2 -> V_331 [ V_16 ] ,
V_332 ) ;
if ( V_197 < 0 )
return V_197 ;
}
}
V_197 = F_183 ( V_19 , V_46 , V_16 , V_322 ,
V_2 -> V_330 [ V_16 ] , - V_332 ) ;
if ( V_197 < 0 )
return V_197 ;
if ( V_2 -> V_41 ) {
V_197 = F_171 ( V_19 , V_46 ) ;
if ( V_197 < 0 )
return V_197 ;
}
}
if ( V_332 && V_2 -> V_40 == V_333 ) {
V_197 = F_183 ( V_19 , V_332 , V_334 , V_322 ,
L_72 , 0 ) ;
if ( V_197 < 0 )
return V_197 ;
else
V_2 -> V_31 = 1 ;
}
return 0 ;
}
static struct V_6 * F_188 ( struct V_18 * V_19 , int V_335 , int V_325 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_325 < 0 || V_325 >= V_336 ) {
F_97 () ;
return NULL ;
}
if ( V_2 -> V_320 )
V_335 = V_2 -> V_319 [ V_325 ] ;
if ( V_335 < 0 || V_335 >= V_274 ) {
F_97 () ;
return NULL ;
}
return F_27 ( V_19 , V_2 -> V_201 [ V_325 ] [ V_335 ] ) ;
}
static int F_189 ( struct V_128 * V_129 ,
struct V_230 * V_231 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
return F_190 ( & V_2 -> V_316 , V_231 ) ;
}
static int F_191 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_335 = F_192 ( V_129 , & V_131 -> V_337 ) ;
V_131 -> V_134 . V_232 . V_233 [ 0 ] = V_2 -> V_265 [ V_335 ] ;
return 0 ;
}
static int F_193 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
unsigned int V_335 = F_192 ( V_129 , & V_131 -> V_337 ) ;
return F_194 ( V_19 , V_335 ,
V_131 -> V_134 . V_232 . V_233 [ 0 ] ) ;
}
static int F_195 ( struct V_128 * V_129 ,
struct V_130 * V_131 ,
T_4 V_338 , int type )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_314 * V_315 ;
struct V_6 * V_52 ;
int V_16 , V_335 , V_197 = 0 ;
V_315 = & V_2 -> V_316 ;
V_335 = V_129 -> V_337 . V_117 ;
F_131 ( & V_19 -> V_339 ) ;
V_19 -> V_340 = 1 ;
for ( V_16 = 0 ; V_16 < V_315 -> V_318 ; V_16 ++ ) {
V_52 = F_188 ( V_19 , V_335 , V_16 ) ;
if ( ! V_52 || ! V_52 -> V_60 [ type ] )
continue;
V_129 -> V_120 = V_52 -> V_60 [ type ] ;
V_197 = V_338 ( V_129 , V_131 ) ;
if ( V_197 < 0 )
goto error;
}
error:
V_19 -> V_340 = 0 ;
F_134 ( & V_19 -> V_339 ) ;
F_196 ( V_19 ) ;
if ( V_197 >= 0 && V_2 -> V_341 )
V_2 -> V_341 ( V_19 , V_129 , V_131 ) ;
return V_197 ;
}
static int F_197 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
return F_195 ( V_129 , V_131 ,
V_342 ,
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
return - V_249 ;
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
for ( V_16 = 0 ; V_16 < V_138 -> V_186 ; V_16 ++ ) {
if ( V_138 -> V_187 [ V_16 ] . V_46 != V_50 )
continue;
if ( V_138 -> V_187 [ V_16 ] . type != V_185 )
return false ;
V_20 = F_104 ( V_19 , V_50 ) ;
return F_152 ( V_20 ) == V_273 ;
}
return false ;
}
static int F_201 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_236 ;
V_236 = F_91 ( V_129 , V_131 ) ;
if ( V_236 < 0 )
return V_236 ;
if ( V_2 -> V_341 )
V_2 -> V_341 ( V_19 , V_129 , V_131 ) ;
return V_236 ;
}
static int F_202 ( struct V_18 * V_19 , const char * V_323 ,
int V_58 , bool V_343 , unsigned int V_344 ,
bool V_345 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
char V_346 [ V_122 ] ;
int type = V_343 ? V_126 : V_124 ;
const char * V_121 = V_343 ? L_73 : L_74 ;
unsigned int V_79 = V_345 ? 1 : 3 ;
struct V_4 * V_12 ;
if ( ! V_344 )
return 0 ;
if ( V_323 )
snprintf ( V_346 , sizeof( V_346 ) ,
L_75 , V_323 , V_121 ) ;
else
snprintf ( V_346 , sizeof( V_346 ) ,
L_76 , V_121 ) ;
V_12 = F_75 ( V_2 , type , V_346 , V_58 ,
F_46 ( V_344 , V_79 ) ) ;
if ( ! V_12 )
return - V_123 ;
if ( V_343 )
V_12 -> V_347 = F_201 ;
if ( ! V_345 )
return 0 ;
if ( V_323 )
snprintf ( V_346 , sizeof( V_346 ) ,
L_77 , V_323 , V_121 ) ;
else
snprintf ( V_346 , sizeof( V_346 ) ,
L_78 , V_121 ) ;
V_12 = F_75 ( V_2 , type , V_346 , V_58 ,
F_46 ( V_344 , 2 ) ) ;
if ( ! V_12 )
return - V_123 ;
if ( V_343 )
V_12 -> V_347 = F_201 ;
return 0 ;
}
static int F_203 ( struct V_18 * V_19 , int V_58 ,
unsigned int V_348 , unsigned int V_349 ,
bool V_345 )
{
int V_197 ;
V_197 = F_202 ( V_19 , NULL , V_58 , false , V_348 , V_345 ) ;
if ( V_197 < 0 )
return V_197 ;
V_197 = F_202 ( V_19 , NULL , V_58 , true , V_349 , V_345 ) ;
if ( V_197 < 0 )
return V_197 ;
return 0 ;
}
static int F_204 ( struct V_18 * V_19 , int V_58 ,
unsigned int V_348 , unsigned int V_349 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
if ( V_348 ) {
V_12 = F_4 ( V_2 , NULL , & V_350 ) ;
if ( ! V_12 )
return - V_123 ;
V_12 -> V_117 = V_58 ;
V_12 -> V_120 = V_348 ;
V_12 -> V_118 = V_119 ;
}
if ( V_349 ) {
V_12 = F_4 ( V_2 , NULL , & V_351 ) ;
if ( ! V_12 )
return - V_123 ;
V_12 -> V_117 = V_58 ;
V_12 -> V_120 = V_349 ;
V_12 -> V_118 = V_119 ;
}
return 0 ;
}
static unsigned int F_205 ( struct V_18 * V_19 , int V_58 , int type )
{
struct V_6 * V_52 ;
unsigned int V_344 ;
int V_16 ;
V_52 = F_188 ( V_19 , 0 , V_58 ) ;
if ( ! V_52 )
return 0 ;
V_344 = V_52 -> V_60 [ type ] ;
if ( ! V_344 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_58 - 1 ; V_16 ++ ) {
V_52 = F_188 ( V_19 , 0 , V_16 ) ;
if ( V_52 && V_52 -> V_60 [ type ] == V_344 )
return 0 ;
}
return V_344 ;
}
static int F_206 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_314 * V_315 = & V_2 -> V_316 ;
int V_16 , V_197 , type ;
for ( V_16 = 0 ; V_16 < V_315 -> V_318 ; V_16 ++ ) {
bool V_345 ;
int V_58 ;
V_58 = V_315 -> V_247 [ V_16 ] . V_117 ;
if ( V_58 >= V_2 -> V_139 . V_186 )
continue;
V_345 = F_200 ( V_19 , V_2 -> V_329 [ V_16 ] ) ;
for ( type = 0 ; type < 2 ; type ++ ) {
V_197 = F_202 ( V_19 ,
V_2 -> V_330 [ V_58 ] ,
V_2 -> V_331 [ V_58 ] ,
type ,
F_205 ( V_19 , V_16 , type ) ,
V_345 ) ;
if ( V_197 < 0 )
return V_197 ;
}
}
return 0 ;
}
static int F_207 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_314 * V_315 = & V_2 -> V_316 ;
int V_16 , V_88 , V_51 , V_197 ;
if ( V_2 -> V_320 )
V_51 = 1 ;
else
V_51 = V_2 -> V_311 ;
if ( ! V_2 -> V_352 && V_315 -> V_318 > 1 ) {
struct V_4 * V_12 ;
const char * V_10 ;
V_10 = V_51 > 1 ? L_79 : L_80 ;
V_12 = F_4 ( V_2 , V_10 , & V_353 ) ;
if ( ! V_12 )
return - V_123 ;
V_12 -> V_246 = V_51 ;
}
for ( V_88 = 0 ; V_88 < V_51 ; V_88 ++ ) {
bool V_72 = false ;
bool V_37 = V_2 -> V_37 ;
bool V_345 = false ;
int V_354 , V_355 ;
V_354 = V_355 = 0 ;
for ( V_16 = 0 ; V_16 < V_315 -> V_318 ; V_16 ++ ) {
struct V_6 * V_52 ;
V_52 = F_188 ( V_19 , V_88 , V_16 ) ;
if ( ! V_52 )
continue;
F_199 ( V_19 , V_52 ) ;
if ( ! V_354 )
V_354 = V_52 -> V_60 [ V_99 ] ;
else if ( V_354 != V_52 -> V_60 [ V_99 ] ) {
V_72 = true ;
if ( ! F_47 ( V_19 , V_354 ,
V_52 -> V_60 [ V_99 ] , V_83 ) )
V_37 = true ;
}
if ( ! V_355 )
V_355 = V_52 -> V_60 [ V_98 ] ;
else if ( V_355 != V_52 -> V_60 [ V_98 ] ) {
V_72 = true ;
if ( ! F_47 ( V_19 , V_355 ,
V_52 -> V_60 [ V_98 ] , V_83 ) )
V_37 = true ;
}
if ( F_200 ( V_19 , V_2 -> V_329 [ V_16 ] ) )
V_345 = true ;
}
if ( ! V_72 )
V_197 = F_203 ( V_19 , V_88 , V_354 , V_355 ,
V_345 ) ;
else if ( ! V_37 && ! V_345 )
V_197 = F_204 ( V_19 , V_88 , V_354 , V_355 ) ;
else
V_197 = F_206 ( V_19 ) ;
if ( V_197 < 0 )
return V_197 ;
}
return 0 ;
}
static bool F_208 ( struct V_18 * V_19 , T_1 V_50 ,
int V_61 , int V_58 )
{
unsigned int V_356 ;
if ( ! F_52 ( V_19 , V_50 , V_61 ) ||
F_32 ( V_19 , V_50 , V_61 , V_58 , V_99 ) ||
F_32 ( V_19 , V_50 , V_61 , V_58 , V_100 ) )
return false ;
V_356 = ( F_48 ( V_19 , V_50 , V_61 ) & V_357 )
>> V_358 ;
if ( V_356 < 0x20 )
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
struct V_314 * V_315 = & V_2 -> V_316 ;
int V_16 ;
if ( ! V_2 -> V_311 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_315 -> V_318 ; V_16 ++ ) {
struct V_6 * V_52 ;
unsigned int V_20 ;
int V_58 ;
char V_359 [ V_122 ] ;
V_58 = V_315 -> V_247 [ V_16 ] . V_117 ;
if ( V_58 >= V_315 -> V_318 )
continue;
if ( V_138 -> V_187 [ V_58 ] . type > V_184 )
continue;
V_52 = F_188 ( V_19 , 0 , V_16 ) ;
if ( ! V_52 )
continue;
V_20 = F_209 ( V_19 , V_52 ) ;
if ( ! V_20 )
continue;
snprintf ( V_359 , sizeof( V_359 ) ,
L_81 , V_2 -> V_330 [ V_58 ] ) ;
if ( ! F_75 ( V_2 , V_124 , V_359 ,
V_2 -> V_331 [ V_58 ] , V_20 ) )
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
T_1 V_360 , V_46 ;
V_51 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_139 . V_361 ; V_16 ++ ) {
V_46 = V_2 -> V_139 . V_362 [ V_16 ] ;
V_360 = F_45 ( V_19 , V_46 , true ) ;
if ( ! V_360 )
continue;
V_52 = F_42 ( V_19 , V_360 , V_46 , 0 ) ;
if ( ! V_52 )
continue;
F_34 ( V_19 , L_82 , V_52 ) ;
V_52 -> V_89 = true ;
V_2 -> V_200 [ V_16 ] = F_26 ( V_19 , V_52 ) ;
F_17 ( V_19 , V_46 , V_227 , false ) ;
if ( ! V_51 ) {
V_2 -> V_146 . V_363 = V_360 ;
V_2 -> V_364 = V_2 -> V_139 . V_364 [ 0 ] ;
} else {
V_2 -> V_146 . V_365 = V_2 -> V_365 ;
if ( V_51 >= F_96 ( V_2 -> V_365 ) - 1 )
break;
V_2 -> V_365 [ V_51 - 1 ] = V_360 ;
}
V_51 ++ ;
}
if ( V_2 -> V_139 . V_366 ) {
V_46 = V_2 -> V_139 . V_366 ;
V_360 = V_19 -> V_214 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_215 ; V_16 ++ , V_360 ++ ) {
unsigned int V_367 = F_40 ( V_19 , V_360 ) ;
if ( F_39 ( V_367 ) != V_69 )
continue;
if ( ! ( V_367 & V_78 ) )
continue;
V_52 = F_42 ( V_19 , V_46 , V_360 , 0 ) ;
if ( V_52 ) {
F_34 ( V_19 , L_83 , V_52 ) ;
V_52 -> V_89 = true ;
V_2 -> V_368 = V_360 ;
V_2 -> V_203 = F_26 ( V_19 , V_52 ) ;
F_17 ( V_19 , V_46 , V_267 , false ) ;
break;
}
}
}
}
static int F_194 ( struct V_18 * V_19 , unsigned int V_335 ,
unsigned int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_314 * V_315 ;
struct V_6 * V_369 , * V_52 ;
V_315 = & V_2 -> V_316 ;
if ( ! V_315 -> V_318 )
return 0 ;
if ( V_58 >= V_315 -> V_318 )
V_58 = V_315 -> V_318 - 1 ;
if ( V_2 -> V_265 [ V_335 ] == V_58 )
return 0 ;
V_369 = F_188 ( V_19 , V_335 , V_2 -> V_265 [ V_335 ] ) ;
if ( ! V_369 )
return 0 ;
if ( V_369 -> V_89 )
F_64 ( V_19 , V_369 , false , false ) ;
V_2 -> V_265 [ V_335 ] = V_58 ;
if ( V_2 -> V_43 )
F_148 ( V_19 , V_335 , false ) ;
if ( V_2 -> V_320 )
F_212 ( V_19 , V_58 ) ;
V_52 = F_188 ( V_19 , V_335 , V_58 ) ;
if ( ! V_52 )
return 0 ;
if ( V_52 -> V_89 )
return 0 ;
F_64 ( V_19 , V_52 , true , false ) ;
if ( V_2 -> V_341 )
V_2 -> V_341 ( V_19 , NULL , NULL ) ;
F_68 ( V_19 , V_369 ) ;
return 1 ;
}
static bool F_213 ( struct V_18 * V_19 , int V_48 , T_1 * V_49 )
{
int V_16 ;
bool V_370 = false ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
T_1 V_50 = V_49 [ V_16 ] ;
if ( ! V_50 )
break;
if ( F_16 ( V_19 , V_50 ) & V_371 )
continue;
if ( F_214 ( V_19 , V_50 ) == V_372 )
V_370 = true ;
}
return V_370 ;
}
static void F_215 ( struct V_18 * V_19 , int V_48 , T_1 * V_49 ,
int * V_5 , bool V_373 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
T_1 V_50 = V_49 [ V_16 ] ;
unsigned int V_20 , V_296 ;
if ( ! V_50 )
break;
if ( V_2 -> V_33 ) {
struct V_6 * V_52 ;
T_1 V_374 ;
V_52 = F_27 ( V_19 , V_5 [ V_16 ] ) ;
if ( ! V_52 )
continue;
V_374 = F_76 ( V_52 -> V_60 [ V_98 ] ) ;
if ( ! V_374 )
continue;
if ( V_373 )
V_2 -> V_133 |= ( 1ULL << V_374 ) ;
else
V_2 -> V_133 &= ~ ( 1ULL << V_374 ) ;
F_72 ( V_19 , V_50 , ! V_373 ) ;
continue;
}
V_296 = F_16 ( V_19 , V_50 ) ;
if ( V_296 & V_267 )
continue;
if ( V_2 -> V_375 )
V_20 = V_296 & ~ V_226 ;
else
V_20 = 0 ;
if ( ! V_373 )
V_20 |= V_296 ;
F_15 ( V_19 , V_50 , V_20 ) ;
F_72 ( V_19 , V_50 , ! V_373 ) ;
}
}
void F_216 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int * V_5 ;
int V_376 ;
if ( V_2 -> V_139 . V_151 == V_154 )
V_5 = V_2 -> V_191 ;
else
V_5 = V_2 -> V_153 ;
F_215 ( V_19 , F_96 ( V_2 -> V_139 . V_206 ) ,
V_2 -> V_139 . V_206 , V_5 , V_2 -> V_377 ) ;
if ( ! V_2 -> V_378 )
V_376 = 0 ;
else
V_376 = V_2 -> V_379 | V_2 -> V_380 ;
V_376 |= V_2 -> V_377 ;
V_2 -> V_381 = V_376 ;
if ( V_2 -> V_139 . V_151 == V_152 )
V_5 = V_2 -> V_191 ;
else
V_5 = V_2 -> V_155 ;
F_215 ( V_19 , F_96 ( V_2 -> V_139 . V_207 ) ,
V_2 -> V_139 . V_207 , V_5 , V_376 ) ;
if ( V_2 -> V_139 . V_205 [ 0 ] == V_2 -> V_139 . V_206 [ 0 ] ||
V_2 -> V_139 . V_205 [ 0 ] == V_2 -> V_139 . V_207 [ 0 ] )
return;
if ( ! V_2 -> V_382 )
V_376 = 0 ;
else
V_376 = V_2 -> V_379 ;
V_376 |= V_2 -> V_377 ;
V_2 -> V_383 = V_376 ;
V_5 = V_2 -> V_191 ;
F_215 ( V_19 , F_96 ( V_2 -> V_139 . V_205 ) ,
V_2 -> V_139 . V_205 , V_5 , V_376 ) ;
}
static void F_217 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_384 )
V_2 -> V_384 ( V_19 ) ;
else
F_216 ( V_19 ) ;
if ( V_2 -> V_33 && ! V_19 -> V_385 -> V_386 )
F_218 ( V_2 -> V_144 . V_387 , false ) ;
}
void F_219 ( struct V_18 * V_19 ,
struct V_388 * V_389 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 * V_49 = V_2 -> V_139 . V_206 ;
int V_48 = F_96 ( V_2 -> V_139 . V_206 ) ;
if ( V_2 -> V_234 ) {
V_49 ++ ;
V_48 -- ;
}
V_2 -> V_379 = F_213 ( V_19 , V_48 , V_49 ) ;
if ( ! V_2 -> V_390 || ( ! V_2 -> V_378 && ! V_2 -> V_382 ) )
return;
F_217 ( V_19 ) ;
}
void F_220 ( struct V_18 * V_19 ,
struct V_388 * V_389 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_139 . V_151 == V_152 )
return;
if ( V_2 -> V_139 . V_205 [ 0 ] == V_2 -> V_139 . V_206 [ 0 ] )
return;
V_2 -> V_380 =
F_213 ( V_19 , F_96 ( V_2 -> V_139 . V_205 ) ,
V_2 -> V_139 . V_205 ) ;
if ( ! V_2 -> V_378 || ! V_2 -> V_391 )
return;
F_217 ( V_19 ) ;
}
void F_221 ( struct V_18 * V_19 ,
struct V_388 * V_389 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
if ( ! V_2 -> V_352 )
return;
for ( V_16 = V_2 -> V_392 - 1 ; V_16 > 0 ; V_16 -- ) {
T_1 V_46 = V_2 -> V_393 [ V_16 ] . V_46 ;
if ( F_16 ( V_19 , V_46 ) & V_394 )
continue;
if ( F_214 ( V_19 , V_46 ) == V_372 ) {
F_194 ( V_19 , 0 , V_2 -> V_393 [ V_16 ] . V_58 ) ;
return;
}
}
F_194 ( V_19 , 0 , V_2 -> V_393 [ 0 ] . V_58 ) ;
}
static void F_133 ( struct V_18 * V_19 ,
struct V_388 * V_389 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_395 )
V_2 -> V_395 ( V_19 , V_389 ) ;
else
F_219 ( V_19 , V_389 ) ;
}
static void F_222 ( struct V_18 * V_19 ,
struct V_388 * V_389 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_396 )
V_2 -> V_396 ( V_19 , V_389 ) ;
else
F_220 ( V_19 , V_389 ) ;
}
static void F_223 ( struct V_18 * V_19 ,
struct V_388 * V_389 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_397 )
V_2 -> V_397 ( V_19 , V_389 ) ;
else
F_221 ( V_19 , V_389 ) ;
}
static void F_141 ( struct V_18 * V_19 )
{
F_133 ( V_19 , NULL ) ;
F_222 ( V_19 , NULL ) ;
F_223 ( V_19 , NULL ) ;
}
static int F_224 ( struct V_128 * V_129 ,
struct V_230 * V_231 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_398 [] = {
L_84 , L_85 , L_86
} ;
if ( V_2 -> V_399 && V_2 -> V_400 )
return F_154 ( V_129 , V_231 , 3 , V_398 ) ;
return F_128 ( V_129 , V_231 ) ;
}
static int F_225 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = 0 ;
if ( V_2 -> V_378 )
V_20 ++ ;
if ( V_2 -> V_382 )
V_20 ++ ;
V_131 -> V_134 . V_232 . V_233 [ 0 ] = V_20 ;
return 0 ;
}
static int F_226 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_18 * V_19 = F_88 ( V_129 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
switch ( V_131 -> V_134 . V_232 . V_233 [ 0 ] ) {
case 0 :
if ( ! V_2 -> V_378 && ! V_2 -> V_382 )
return 0 ;
V_2 -> V_378 = 0 ;
V_2 -> V_382 = 0 ;
break;
case 1 :
if ( V_2 -> V_399 ) {
if ( ! V_2 -> V_382 && V_2 -> V_378 )
return 0 ;
V_2 -> V_378 = 1 ;
V_2 -> V_382 = 0 ;
} else if ( V_2 -> V_400 ) {
if ( V_2 -> V_382 )
return 0 ;
V_2 -> V_382 = 1 ;
} else
return - V_249 ;
break;
case 2 :
if ( ! V_2 -> V_400 || ! V_2 -> V_399 )
return - V_249 ;
if ( V_2 -> V_378 && V_2 -> V_382 )
return 0 ;
V_2 -> V_378 = 1 ;
V_2 -> V_382 = 1 ;
break;
default:
return - V_249 ;
}
F_217 ( V_19 ) ;
return 1 ;
}
static int F_227 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! F_4 ( V_2 , NULL , & V_401 ) )
return - V_123 ;
return 0 ;
}
static int F_228 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
int V_370 = 0 ;
int V_16 , V_197 ;
if ( V_2 -> V_30 )
return 0 ;
if ( V_138 -> V_206 [ 0 ] )
V_370 ++ ;
if ( V_138 -> V_205 [ 0 ] )
V_370 ++ ;
if ( V_138 -> V_207 [ 0 ] )
V_370 ++ ;
if ( V_370 < 2 )
return 0 ;
if ( ! V_138 -> V_207 [ 0 ] &&
V_138 -> V_151 == V_152 ) {
memcpy ( V_138 -> V_207 , V_138 -> V_205 ,
sizeof( V_138 -> V_207 ) ) ;
V_138 -> V_143 = V_138 -> V_140 ;
}
if ( ! V_138 -> V_206 [ 0 ] &&
V_138 -> V_151 == V_154 ) {
memcpy ( V_138 -> V_206 , V_138 -> V_205 ,
sizeof( V_138 -> V_206 ) ) ;
V_138 -> V_142 = V_138 -> V_140 ;
}
for ( V_16 = 0 ; V_16 < V_138 -> V_142 ; V_16 ++ ) {
T_1 V_50 = V_138 -> V_206 [ V_16 ] ;
if ( ! F_229 ( V_19 , V_50 ) )
continue;
F_36 ( V_19 , L_87 , V_50 ) ;
F_230 ( V_19 , V_50 ,
F_133 ) ;
V_2 -> V_390 = 1 ;
}
if ( V_138 -> V_151 == V_156 && V_138 -> V_140 ) {
if ( V_138 -> V_143 )
for ( V_16 = 0 ; V_16 < V_138 -> V_140 ; V_16 ++ ) {
T_1 V_50 = V_138 -> V_205 [ V_16 ] ;
if ( ! F_229 ( V_19 , V_50 ) )
continue;
F_36 ( V_19 , L_88 , V_50 ) ;
F_230 ( V_19 , V_50 ,
F_222 ) ;
V_2 -> V_391 = 1 ;
}
V_2 -> V_400 = V_2 -> V_390 ;
}
V_2 -> V_399 = V_138 -> V_143 &&
( V_2 -> V_390 || V_2 -> V_391 ) ;
V_2 -> V_382 = V_2 -> V_400 ;
V_2 -> V_378 = V_2 -> V_399 ;
if ( V_2 -> V_399 || V_2 -> V_400 ) {
V_197 = F_227 ( V_19 ) ;
if ( V_197 < 0 )
return V_197 ;
}
return 0 ;
}
static bool F_231 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_314 * V_315 ;
int V_16 ;
V_315 = & V_2 -> V_316 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_392 ; V_16 ++ ) {
V_2 -> V_393 [ V_16 ] . V_58 =
F_21 ( V_2 -> V_393 [ V_16 ] . V_46 ,
V_2 -> V_329 , V_315 -> V_318 ) ;
if ( V_2 -> V_393 [ V_16 ] . V_58 < 0 )
return false ;
}
for ( V_16 = 1 ; V_16 < V_2 -> V_392 ; V_16 ++ )
F_230 ( V_19 ,
V_2 -> V_393 [ V_16 ] . V_46 ,
F_223 ) ;
return true ;
}
static int F_232 ( const void * V_402 , const void * V_403 )
{
const struct V_404 * V_405 = V_402 ;
const struct V_404 * V_406 = V_403 ;
return ( int ) ( V_405 -> V_407 - V_406 -> V_407 ) ;
}
static int F_233 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
unsigned int V_408 ;
int V_16 , V_48 ;
if ( V_2 -> V_31 )
return 0 ;
V_408 = 0 ;
V_48 = 0 ;
for ( V_16 = 0 ; V_16 < V_138 -> V_186 ; V_16 ++ ) {
T_1 V_50 = V_138 -> V_187 [ V_16 ] . V_46 ;
unsigned int V_407 ;
V_407 = F_104 ( V_19 , V_50 ) ;
V_407 = F_152 ( V_407 ) ;
if ( V_408 & ( 1 << V_407 ) )
return 0 ;
switch ( V_407 ) {
case V_273 :
if ( V_138 -> V_187 [ V_16 ] . type != V_185 )
return 0 ;
break;
case V_409 :
return 0 ;
default:
if ( V_138 -> V_187 [ V_16 ] . type > V_184 )
return 0 ;
if ( ! V_2 -> V_32 &&
V_138 -> V_187 [ V_16 ] . type != V_185 )
return 0 ;
if ( ! F_229 ( V_19 , V_50 ) )
return 0 ;
break;
}
if ( V_48 >= V_410 )
return 0 ;
V_408 |= ( 1 << V_407 ) ;
V_2 -> V_393 [ V_48 ] . V_46 = V_50 ;
V_2 -> V_393 [ V_48 ] . V_407 = V_407 ;
V_48 ++ ;
}
if ( V_48 < 2 )
return 0 ;
V_2 -> V_392 = V_48 ;
F_234 ( V_2 -> V_393 , V_48 , sizeof( V_2 -> V_393 [ 0 ] ) ,
F_232 , NULL ) ;
if ( ! F_231 ( V_19 ) )
return 0 ;
V_2 -> V_352 = 1 ;
V_2 -> V_311 = 1 ;
V_2 -> V_265 [ 0 ] = V_2 -> V_393 [ 0 ] . V_58 ;
F_36 ( V_19 , L_89 ,
V_2 -> V_393 [ 0 ] . V_46 ,
V_2 -> V_393 [ 1 ] . V_46 ,
V_2 -> V_393 [ 2 ] . V_46 ) ;
return 0 ;
}
unsigned int F_235 ( struct V_18 * V_19 ,
T_1 V_50 ,
unsigned int V_411 )
{
if ( V_411 != V_104 || V_50 == V_19 -> V_412 )
return V_411 ;
if ( F_39 ( F_40 ( V_19 , V_50 ) ) >= V_413 )
return V_411 ;
if ( F_69 ( V_19 , V_50 ) )
return V_411 ;
return V_108 ;
}
static void F_236 ( struct V_18 * V_19 , T_1 V_298 )
{
int V_16 , V_51 ;
const T_1 * V_65 ;
bool V_414 ;
V_51 = F_38 ( V_19 , V_298 , & V_65 ) ;
V_414 = F_50 ( V_19 , V_298 , V_83 ) ;
for ( V_16 = 0 ; V_16 < V_51 ; V_16 ++ ) {
if ( V_414 )
F_61 ( V_19 , V_298 ,
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
int V_197 ;
F_11 ( V_19 ) ;
if ( V_2 -> V_45 && ! V_2 -> V_103 )
V_2 -> V_103 = V_2 -> V_45 ;
if ( V_138 != & V_2 -> V_139 ) {
V_2 -> V_139 = * V_138 ;
V_138 = & V_2 -> V_139 ;
}
if ( ! V_2 -> V_208 )
V_2 -> V_208 = & V_415 ;
if ( ! V_2 -> V_209 )
V_2 -> V_209 = & V_416 ;
F_117 ( V_19 ) ;
if ( ! V_138 -> V_140 ) {
if ( V_138 -> V_361 || V_138 -> V_366 ) {
V_2 -> V_146 . V_251 = 2 ;
V_2 -> V_417 = 1 ;
goto V_418;
}
if ( ! V_138 -> V_186 && ! V_138 -> V_366 )
return 0 ;
}
if ( ! V_2 -> V_35 &&
V_138 -> V_151 == V_152 &&
V_138 -> V_140 <= V_138 -> V_142 ) {
V_138 -> V_143 = V_138 -> V_140 ;
memcpy ( V_138 -> V_207 , V_138 -> V_205 ,
sizeof( V_138 -> V_207 ) ) ;
V_138 -> V_140 = V_138 -> V_142 ;
memcpy ( V_138 -> V_205 , V_138 -> V_206 , sizeof( V_138 -> V_206 ) ) ;
V_138 -> V_142 = 0 ;
memset ( V_138 -> V_206 , 0 , sizeof( V_138 -> V_206 ) ) ;
V_138 -> V_151 = V_154 ;
}
V_197 = F_119 ( V_19 ) ;
if ( V_197 < 0 )
return V_197 ;
V_197 = F_144 ( V_19 ) ;
if ( V_197 < 0 )
return V_197 ;
V_197 = F_122 ( V_19 , V_138 ) ;
if ( V_197 < 0 )
return V_197 ;
V_197 = F_125 ( V_19 ) ;
if ( V_197 < 0 )
return V_197 ;
V_197 = F_126 ( V_19 ) ;
if ( V_197 < 0 )
return V_197 ;
V_197 = F_135 ( V_19 ) ;
if ( V_197 < 0 )
return V_197 ;
V_197 = F_147 ( V_19 ) ;
if ( V_197 < 0 )
return V_197 ;
V_197 = F_151 ( V_19 ) ;
if ( V_197 < 0 )
return V_197 ;
V_197 = F_187 ( V_19 ) ;
if ( V_197 < 0 )
return V_197 ;
V_2 -> V_252 = V_2 -> V_210 ;
if ( V_138 -> V_151 != V_152 )
V_2 -> V_252 = F_143 ( V_2 -> V_252 ,
V_138 -> V_143 * 2 ) ;
if ( V_138 -> V_151 != V_154 )
V_2 -> V_252 = F_143 ( V_2 -> V_252 ,
V_138 -> V_142 * 2 ) ;
V_2 -> V_146 . V_251 = F_143 ( V_2 -> V_210 ,
V_2 -> V_252 ) ;
V_197 = F_228 ( V_19 ) ;
if ( V_197 < 0 )
return V_197 ;
V_197 = F_182 ( V_19 ) ;
if ( V_197 < 0 )
return V_197 ;
V_197 = F_233 ( V_19 ) ;
if ( V_197 < 0 )
return V_197 ;
if ( ! V_2 -> V_352 && V_2 -> V_45 &&
V_2 -> V_40 == V_419 &&
V_2 -> V_316 . V_318 > 1 ) {
V_197 = F_183 ( V_19 , V_2 -> V_45 ,
V_334 , V_2 -> V_312 ,
L_72 , 0 ) ;
if ( V_197 < 0 )
return V_197 ;
}
V_197 = F_207 ( V_19 ) ;
if ( V_197 < 0 )
return V_197 ;
V_197 = F_210 ( V_19 ) ;
if ( V_197 < 0 )
return V_197 ;
if ( V_2 -> V_264 &&
( V_2 -> V_352 || V_2 -> V_316 . V_318 == 1 ||
V_2 -> V_41 ) ) {
V_197 = F_176 ( V_19 , V_2 -> V_264 ) ;
if ( V_197 < 0 )
return V_197 ;
}
if ( V_2 -> V_41 ) {
if ( V_138 -> V_151 != V_152 ) {
V_197 = F_162 ( V_19 , V_138 -> V_140 ,
V_138 -> V_205 ) ;
if ( V_197 < 0 )
return V_197 ;
}
if ( V_138 -> V_151 != V_154 ) {
V_197 = F_162 ( V_19 , V_138 -> V_142 ,
V_138 -> V_206 ) ;
if ( V_197 < 0 )
return V_197 ;
}
}
if ( V_2 -> V_45 )
F_236 ( V_19 , V_2 -> V_45 ) ;
V_418:
F_211 ( V_19 ) ;
if ( V_2 -> V_42 )
V_19 -> V_420 = F_235 ;
if ( ! V_2 -> V_417 && V_2 -> V_421 ) {
V_197 = F_238 ( V_19 , V_2 -> V_421 ) ;
if ( V_197 < 0 )
return V_197 ;
}
return 1 ;
}
int F_239 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_197 ;
if ( V_2 -> V_3 . V_17 ) {
V_197 = F_240 ( V_19 , V_2 -> V_3 . V_14 ) ;
if ( V_197 < 0 )
return V_197 ;
}
if ( V_2 -> V_146 . V_363 ) {
V_197 = F_241 ( V_19 ,
V_2 -> V_146 . V_363 ,
V_2 -> V_146 . V_363 ,
V_2 -> V_422 [ 1 ] . V_423 ) ;
if ( V_197 < 0 )
return V_197 ;
if ( ! V_2 -> V_417 ) {
V_197 = F_242 ( V_19 ,
& V_2 -> V_146 ) ;
if ( V_197 < 0 )
return V_197 ;
V_2 -> V_146 . V_424 = 1 ;
}
}
if ( V_2 -> V_368 ) {
V_197 = F_243 ( V_19 , V_2 -> V_368 ) ;
if ( V_197 < 0 )
return V_197 ;
}
if ( ! V_2 -> V_417 &&
! F_244 ( V_19 , L_90 ) ) {
V_197 = F_245 ( V_19 , L_90 ,
V_2 -> V_223 , V_425 ,
L_91 ) ;
if ( V_197 < 0 )
return V_197 ;
}
if ( ! V_2 -> V_417 &&
! F_244 ( V_19 , L_92 ) ) {
V_197 = F_246 ( V_19 , L_92 ,
NULL , V_425 ,
L_93 ,
true , & V_2 -> V_144 . V_387 ) ;
if ( V_197 < 0 )
return V_197 ;
if ( V_2 -> V_144 . V_145 ) {
F_247 ( V_19 , & V_2 -> V_144 ,
V_2 -> V_426 ) ;
F_248 ( & V_2 -> V_144 ) ;
}
}
F_7 ( V_2 ) ;
V_197 = F_249 ( V_19 , & V_2 -> V_139 ) ;
if ( V_197 < 0 )
return V_197 ;
return 0 ;
}
static void F_250 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 ,
int V_431 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_432 )
V_2 -> V_432 ( V_428 , V_19 , V_430 , V_431 ) ;
}
static void F_251 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 ,
int V_431 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_433 )
V_2 -> V_433 ( V_428 , V_19 , V_430 , V_431 ) ;
}
static int F_252 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_197 ;
F_131 ( & V_2 -> V_9 ) ;
V_197 = F_253 ( V_19 ,
& V_2 -> V_146 , V_430 ,
V_428 ) ;
if ( ! V_197 ) {
V_2 -> V_237 |= 1 << V_434 ;
F_250 ( V_428 , V_19 , V_430 ,
V_435 ) ;
}
F_134 ( & V_2 -> V_9 ) ;
return V_197 ;
}
static int F_254 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
unsigned int V_436 ,
unsigned int V_437 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_197 ;
V_197 = F_255 ( V_19 , & V_2 -> V_146 ,
V_436 , V_437 , V_430 ) ;
if ( ! V_197 )
F_250 ( V_428 , V_19 , V_430 ,
V_438 ) ;
return V_197 ;
}
static int F_256 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_197 ;
V_197 = F_257 ( V_19 , & V_2 -> V_146 ) ;
if ( ! V_197 )
F_250 ( V_428 , V_19 , V_430 ,
V_439 ) ;
return V_197 ;
}
static int F_258 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_131 ( & V_2 -> V_9 ) ;
V_2 -> V_237 &= ~ ( 1 << V_434 ) ;
F_250 ( V_428 , V_19 , V_430 ,
V_440 ) ;
F_134 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_259 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
F_251 ( V_428 , V_19 , V_430 , V_435 ) ;
return 0 ;
}
static int F_260 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
unsigned int V_436 ,
unsigned int V_437 ,
struct V_429 * V_430 )
{
F_261 ( V_19 , V_428 -> V_50 , V_436 , 0 , V_437 ) ;
F_251 ( V_428 , V_19 , V_430 ,
V_438 ) ;
return 0 ;
}
static int F_262 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
F_263 ( V_19 , V_428 -> V_50 ) ;
F_251 ( V_428 , V_19 , V_430 ,
V_439 ) ;
return 0 ;
}
static int F_264 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
F_251 ( V_428 , V_19 , V_430 , V_440 ) ;
return 0 ;
}
static int F_265 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_197 = 0 ;
F_131 ( & V_2 -> V_9 ) ;
if ( ! V_2 -> V_234 )
V_197 = - V_238 ;
else
V_2 -> V_237 |= 1 << V_441 ;
F_250 ( V_428 , V_19 , V_430 ,
V_435 ) ;
F_134 ( & V_2 -> V_9 ) ;
return V_197 ;
}
static int F_266 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_131 ( & V_2 -> V_9 ) ;
V_2 -> V_237 &= ~ ( 1 << V_441 ) ;
F_250 ( V_428 , V_19 , V_430 ,
V_440 ) ;
F_134 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_267 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
unsigned int V_436 ,
unsigned int V_437 ,
struct V_429 * V_430 )
{
F_261 ( V_19 , V_428 -> V_50 , V_436 , 0 , V_437 ) ;
F_250 ( V_428 , V_19 , V_430 ,
V_438 ) ;
return 0 ;
}
static int F_268 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
F_263 ( V_19 , V_428 -> V_50 ) ;
F_250 ( V_428 , V_19 , V_430 ,
V_439 ) ;
return 0 ;
}
static int F_269 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_270 ( V_19 , & V_2 -> V_146 ) ;
}
static int F_271 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
unsigned int V_436 ,
unsigned int V_437 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_272 ( V_19 , & V_2 -> V_146 ,
V_436 , V_437 , V_430 ) ;
}
static int F_273 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_274 ( V_19 , & V_2 -> V_146 ) ;
}
static int F_275 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_276 ( V_19 , & V_2 -> V_146 ) ;
}
static int F_277 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
unsigned int V_436 ,
unsigned int V_437 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_261 ( V_19 , V_2 -> V_309 [ V_430 -> V_442 + 1 ] ,
V_436 , 0 , V_437 ) ;
F_251 ( V_428 , V_19 , V_430 ,
V_438 ) ;
return 0 ;
}
static int F_278 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_263 ( V_19 ,
V_2 -> V_309 [ V_430 -> V_442 + 1 ] ) ;
F_251 ( V_428 , V_19 , V_430 ,
V_439 ) ;
return 0 ;
}
static bool F_212 ( struct V_18 * V_19 , int V_443 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_444 = V_2 -> V_309 [ V_2 -> V_319 [ V_443 ] ] ;
if ( V_2 -> V_445 && V_2 -> V_445 != V_444 ) {
F_279 ( V_19 , V_2 -> V_445 , 1 ) ;
V_2 -> V_445 = V_444 ;
F_261 ( V_19 , V_444 ,
V_2 -> V_446 , 0 ,
V_2 -> V_447 ) ;
return true ;
}
return false ;
}
static int F_280 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
unsigned int V_436 ,
unsigned int V_437 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
V_2 -> V_445 = V_2 -> V_309 [ V_2 -> V_319 [ V_2 -> V_265 [ 0 ] ] ] ;
V_2 -> V_446 = V_436 ;
V_2 -> V_447 = V_437 ;
F_261 ( V_19 , V_2 -> V_445 , V_436 , 0 , V_437 ) ;
return 0 ;
}
static int F_281 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_263 ( V_19 , V_2 -> V_445 ) ;
V_2 -> V_445 = 0 ;
return 0 ;
}
static void F_282 ( char * V_448 , T_3 V_449 , const char * V_121 ,
const char * V_450 )
{
char * V_451 ;
if ( * V_448 )
return;
F_283 ( V_448 , V_450 , V_449 ) ;
for ( V_451 = strchr ( V_448 , ' ' ) ; V_451 ; V_451 = strchr ( V_451 + 1 , ' ' ) ) {
if ( ! isalnum ( V_451 [ 1 ] ) ) {
* V_451 = 0 ;
break;
}
}
F_160 ( V_448 , V_121 , V_449 ) ;
}
int F_284 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_452 * V_453 = V_2 -> V_422 ;
const struct V_427 * V_451 ;
bool V_454 ;
V_19 -> V_455 = 1 ;
V_19 -> V_456 = V_453 ;
if ( V_2 -> V_417 )
goto V_457;
F_282 ( V_2 -> V_458 ,
sizeof( V_2 -> V_458 ) ,
L_94 , V_19 -> V_450 ) ;
V_453 -> V_10 = V_2 -> V_458 ;
if ( V_2 -> V_146 . V_147 > 0 ) {
V_451 = V_2 -> V_459 ;
if ( ! V_451 )
V_451 = & V_460 ;
V_453 -> V_461 [ V_462 ] = * V_451 ;
V_453 -> V_461 [ V_462 ] . V_50 = V_2 -> V_146 . V_198 [ 0 ] ;
V_453 -> V_461 [ V_462 ] . V_463 =
V_2 -> V_146 . V_251 ;
if ( V_2 -> V_139 . V_151 == V_152 &&
V_2 -> V_139 . V_140 == 2 )
V_453 -> V_461 [ V_462 ] . V_464 =
V_465 ;
}
if ( V_2 -> V_311 ) {
V_451 = V_2 -> V_466 ;
if ( ! V_451 ) {
if ( V_2 -> V_320 )
V_451 = & V_467 ;
else
V_451 = & V_468 ;
}
V_453 -> V_461 [ V_469 ] = * V_451 ;
V_453 -> V_461 [ V_469 ] . V_50 = V_2 -> V_309 [ 0 ] ;
}
V_457:
if ( V_2 -> V_146 . V_363 || V_2 -> V_368 ) {
F_282 ( V_2 -> V_470 ,
sizeof( V_2 -> V_470 ) ,
L_95 , V_19 -> V_450 ) ;
V_19 -> V_455 = 2 ;
V_19 -> V_365 = V_2 -> V_146 . V_365 ;
V_453 = V_2 -> V_422 + 1 ;
V_453 -> V_10 = V_2 -> V_470 ;
if ( V_2 -> V_364 )
V_453 -> V_423 = V_2 -> V_364 ;
else
V_453 -> V_423 = V_471 ;
if ( V_2 -> V_146 . V_363 ) {
V_451 = V_2 -> V_472 ;
if ( ! V_451 )
V_451 = & V_473 ;
V_453 -> V_461 [ V_462 ] = * V_451 ;
V_453 -> V_461 [ V_462 ] . V_50 = V_2 -> V_146 . V_363 ;
}
if ( V_2 -> V_368 ) {
V_451 = V_2 -> V_474 ;
if ( ! V_451 )
V_451 = & V_475 ;
V_453 -> V_461 [ V_469 ] = * V_451 ;
V_453 -> V_461 [ V_469 ] . V_50 = V_2 -> V_368 ;
}
}
if ( V_2 -> V_417 )
return 0 ;
V_454 = ( V_2 -> V_311 > 1 ) &&
! V_2 -> V_320 && ! V_2 -> V_352 ;
if ( V_2 -> V_243 || V_454 ) {
F_282 ( V_2 -> V_476 ,
sizeof( V_2 -> V_476 ) ,
L_96 , V_19 -> V_450 ) ;
V_19 -> V_455 = 3 ;
V_453 = V_2 -> V_422 + 2 ;
V_453 -> V_10 = V_2 -> V_476 ;
if ( V_2 -> V_243 ) {
V_451 = V_2 -> V_477 ;
if ( ! V_451 )
V_451 = & V_478 ;
V_453 -> V_461 [ V_462 ] = * V_451 ;
V_453 -> V_461 [ V_462 ] . V_50 =
V_2 -> V_243 ;
} else {
V_453 -> V_461 [ V_462 ] =
V_479 ;
V_453 -> V_461 [ V_462 ] . V_50 = 0 ;
}
if ( V_454 ) {
V_451 = V_2 -> V_480 ;
if ( ! V_451 )
V_451 = & V_481 ;
V_453 -> V_461 [ V_469 ] = * V_451 ;
V_453 -> V_461 [ V_469 ] . V_50 =
V_2 -> V_309 [ 1 ] ;
V_453 -> V_461 [ V_469 ] . V_482 =
V_2 -> V_311 - 1 ;
} else {
V_453 -> V_461 [ V_469 ] =
V_479 ;
V_453 -> V_461 [ V_469 ] . V_50 = 0 ;
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
F_285 ( V_19 , V_2 -> V_191 [ V_16 ] ) ;
}
static void F_287 ( struct V_18 * V_19 , int V_167 , int * V_5 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_167 ; V_16 ++ )
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
T_1 V_46 = V_2 -> V_165 [ V_16 ] . V_46 ;
struct V_6 * V_52 ;
V_52 = F_138 ( V_19 , V_16 ) ;
if ( ! V_52 )
continue;
if ( ! V_2 -> V_165 [ V_16 ] . V_250 )
V_2 -> V_165 [ V_16 ] . V_250 =
F_16 ( V_19 , V_46 ) ;
F_64 ( V_19 , V_52 , V_52 -> V_89 ,
F_139 ( V_2 ) ) ;
}
}
static void F_290 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_241 )
return;
F_132 ( V_19 , V_2 -> V_242 , V_2 -> V_191 [ 0 ] ,
V_2 -> V_199 [ 0 ] ,
V_2 -> V_139 . V_151 ) ;
F_132 ( V_19 , V_2 -> V_242 , V_2 -> V_153 [ 0 ] ,
V_2 -> V_199 [ 1 ] ,
V_154 ) ;
F_132 ( V_19 , V_2 -> V_242 , V_2 -> V_155 [ 0 ] ,
V_2 -> V_199 [ 2 ] ,
V_152 ) ;
}
static void F_291 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_137 * V_138 = & V_2 -> V_139 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_138 -> V_186 ; V_16 ++ ) {
T_1 V_50 = V_138 -> V_187 [ V_16 ] . V_46 ;
if ( F_180 ( V_19 , V_50 ) )
F_14 ( V_19 , V_50 ) ;
if ( V_2 -> V_45 ) {
F_74 ( V_19 , V_2 -> V_202 [ V_16 ] ) ;
F_74 ( V_19 , V_2 -> V_308 ) ;
}
}
}
static void F_292 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_314 * V_315 = & V_2 -> V_316 ;
struct V_6 * V_52 ;
int V_16 , V_327 , V_51 ;
if ( V_2 -> V_320 )
V_51 = 1 ;
else
V_51 = V_2 -> V_311 ;
for ( V_327 = 0 ; V_327 < V_51 ; V_327 ++ ) {
for ( V_16 = 0 ; V_16 < V_315 -> V_318 ; V_16 ++ ) {
V_52 = F_188 ( V_19 , V_327 , V_16 ) ;
if ( V_52 ) {
bool V_89 = V_52 -> V_89 ;
if ( V_16 == V_2 -> V_265 [ V_327 ] )
V_89 = true ;
F_64 ( V_19 , V_52 , V_89 , false ) ;
}
}
if ( V_2 -> V_43 )
F_148 ( V_19 , V_327 , true ) ;
}
if ( V_2 -> V_341 )
V_2 -> V_341 ( V_19 , NULL , NULL ) ;
}
static void F_293 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_46 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_139 . V_361 ; V_16 ++ )
F_285 ( V_19 , V_2 -> V_200 [ V_16 ] ) ;
V_46 = V_2 -> V_139 . V_366 ;
if ( V_46 ) {
F_14 ( V_19 , V_46 ) ;
F_74 ( V_19 , V_2 -> V_203 ) ;
}
}
static void F_294 ( struct V_18 * V_19 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_483 . V_17 ; V_16 ++ ) {
struct V_484 * V_46 = F_24 ( & V_19 -> V_483 , V_16 ) ;
T_1 V_50 = V_46 -> V_50 ;
if ( F_229 ( V_19 , V_50 ) &&
! F_295 ( V_19 , V_50 ) )
F_67 ( V_19 , V_50 , 0 ,
V_485 , 0 ) ;
}
}
int F_296 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_486 )
V_2 -> V_486 ( V_19 ) ;
F_297 ( V_19 ) ;
V_19 -> V_340 = 1 ;
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
if ( V_2 -> V_144 . V_387 && V_2 -> V_144 . V_145 )
F_248 ( & V_2 -> V_144 ) ;
F_298 ( V_19 , 0x01 ) ;
return 0 ;
}
void F_299 ( struct V_18 * V_19 )
{
F_300 ( V_19 , V_487 ) ;
F_10 ( V_19 -> V_2 ) ;
F_8 ( V_19 -> V_2 ) ;
V_19 -> V_2 = NULL ;
}
int F_301 ( struct V_18 * V_19 , T_1 V_50 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_302 ( V_19 , & V_2 -> V_299 , V_50 ) ;
}
int F_303 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_197 ;
V_2 = F_304 ( sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 )
return - V_123 ;
F_1 ( V_2 ) ;
V_19 -> V_2 = V_2 ;
V_197 = F_305 ( V_19 , & V_2 -> V_139 , NULL , 0 ) ;
if ( V_197 < 0 )
return V_197 ;
V_197 = F_237 ( V_19 , & V_2 -> V_139 ) ;
if ( V_197 < 0 )
goto error;
V_19 -> V_488 = V_489 ;
return 0 ;
error:
F_299 ( V_19 ) ;
return V_197 ;
}
