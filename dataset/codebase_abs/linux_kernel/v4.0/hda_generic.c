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
static bool F_57 ( struct V_18 * V_19 , T_1 V_50 , int V_61 )
{
unsigned int V_97 = F_40 ( V_19 , V_50 ) ;
T_1 V_65 ;
if ( V_97 & V_98 )
return true ;
if ( V_61 != V_83 || F_39 ( V_97 ) != V_71 )
return false ;
if ( F_58 ( V_19 , V_50 ) != 1 )
return false ;
if ( F_59 ( V_19 , V_50 , & V_65 , 1 ) < 0 )
return false ;
return ! ! ( F_40 ( V_19 , V_65 ) & V_98 ) ;
}
static void F_60 ( struct V_18 * V_19 , T_1 V_50 , int V_61 , int V_58 )
{
unsigned int V_85 = F_48 ( V_19 , V_50 , V_61 ) ;
int V_20 = F_56 ( V_19 , V_50 , V_61 , V_85 , false ) ;
if ( F_57 ( V_19 , V_50 , V_61 ) )
F_61 ( V_19 , V_50 , V_61 , V_58 , 0xff , V_20 ) ;
else
F_62 ( V_19 , V_50 , 0 , V_61 , V_58 , 0xff , V_20 ) ;
}
static int F_63 ( struct V_18 * V_19 , T_1 V_50 , int V_61 , int V_58 ,
unsigned int V_99 , unsigned int V_20 )
{
if ( F_57 ( V_19 , V_50 , V_61 ) )
return F_64 ( V_19 , V_50 , V_61 , V_58 ,
V_99 , V_20 ) ;
else
return F_65 ( V_19 , V_50 , 0 , V_61 , V_58 ,
V_99 , V_20 ) ;
}
static unsigned int F_66 ( struct V_18 * V_19 ,
T_1 V_50 , int V_61 , int V_58 ,
unsigned int V_85 )
{
unsigned int V_99 = 0xff ;
if ( V_85 & ( V_94 | V_95 ) ) {
if ( F_32 ( V_19 , V_50 , V_61 , V_58 , V_100 ) )
V_99 &= ~ 0x80 ;
}
if ( V_85 & V_91 ) {
if ( F_32 ( V_19 , V_50 , V_61 , V_58 , V_101 ) ||
F_32 ( V_19 , V_50 , V_61 , V_58 , V_102 ) )
V_99 &= ~ 0x7f ;
}
return V_99 ;
}
static void F_67 ( struct V_18 * V_19 , T_1 V_50 , int V_61 ,
int V_58 , int V_103 , bool V_90 )
{
unsigned int V_85 ;
unsigned int V_99 , V_20 ;
if ( ! V_90 && F_55 ( V_19 , V_50 , V_61 , V_103 ) )
return;
V_85 = F_48 ( V_19 , V_50 , V_61 ) ;
V_20 = F_56 ( V_19 , V_50 , V_61 , V_85 , V_90 ) ;
V_99 = F_66 ( V_19 , V_50 , V_61 , V_103 , V_85 ) ;
if ( ! V_99 )
return;
V_20 &= V_99 ;
F_63 ( V_19 , V_50 , V_61 , V_58 , V_99 , V_20 ) ;
}
static void F_68 ( struct V_18 * V_19 , struct V_6 * V_52 ,
int V_16 , bool V_90 )
{
T_1 V_50 = V_52 -> V_52 [ V_16 ] ;
F_60 ( V_19 , V_50 , V_82 , 0 ) ;
F_67 ( V_19 , V_50 , V_82 , 0 , 0 , V_90 ) ;
}
static void F_69 ( struct V_18 * V_19 , struct V_6 * V_52 ,
int V_16 , bool V_90 , bool V_104 )
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
F_60 ( V_19 , V_50 , V_83 , V_88 ) ;
for ( V_88 = 0 ; V_88 < V_51 ; V_88 ++ ) {
if ( V_88 != V_58 && ( ! V_104 || V_65 [ V_88 ] != V_2 -> V_105 ) )
continue;
F_67 ( V_19 , V_50 , V_83 , V_88 , V_58 , V_90 ) ;
}
}
void F_70 ( struct V_18 * V_19 , struct V_6 * V_52 ,
bool V_90 , bool V_104 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
if ( ! V_90 )
V_52 -> V_89 = false ;
for ( V_16 = V_52 -> V_53 - 1 ; V_16 >= 0 ; V_16 -- ) {
T_1 V_50 = V_52 -> V_52 [ V_16 ] ;
if ( V_90 && V_2 -> V_42 ) {
if ( ! F_71 ( V_19 , V_50 , V_106 ) )
F_72 ( V_19 , V_50 , 0 ,
V_107 ,
V_106 ) ;
}
if ( V_90 && V_52 -> V_72 [ V_16 ] )
F_73 ( V_19 , V_50 , 0 ,
V_108 ,
V_52 -> V_58 [ V_16 ] ) ;
if ( F_53 ( V_19 , V_52 , V_16 ) )
F_69 ( V_19 , V_52 , V_16 , V_90 , V_104 ) ;
if ( F_54 ( V_19 , V_52 , V_16 ) )
F_68 ( V_19 , V_52 , V_16 , V_90 ) ;
}
if ( V_90 )
V_52 -> V_89 = true ;
}
static void F_74 ( struct V_18 * V_19 , struct V_6 * V_52 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_109 = false ;
int V_16 ;
if ( ! V_2 -> V_42 || V_52 -> V_89 )
return;
for ( V_16 = 0 ; V_16 < V_52 -> V_53 ; V_16 ++ ) {
T_1 V_50 = V_52 -> V_52 [ V_16 ] ;
if ( ! F_71 ( V_19 , V_50 , V_110 ) &&
! F_75 ( V_19 , V_50 ) ) {
F_72 ( V_19 , V_50 , 0 ,
V_107 ,
V_110 ) ;
V_109 = true ;
}
}
if ( V_109 ) {
F_76 ( 10 ) ;
F_77 ( V_19 , V_52 -> V_52 [ 0 ] , 0 ,
V_111 , 0 ) ;
}
}
static void F_78 ( struct V_18 * V_19 , T_1 V_46 , bool V_90 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_112 ||
! ( F_79 ( V_19 , V_46 ) & V_113 ) )
return;
if ( V_2 -> V_114 && ! V_90 )
return;
if ( V_19 -> V_24 )
V_90 = ! V_90 ;
F_73 ( V_19 , V_46 , 0 ,
V_115 ,
V_90 ? 0x02 : 0x00 ) ;
}
static void F_80 ( struct V_18 * V_19 , int V_116 )
{
struct V_6 * V_52 = F_27 ( V_19 , V_116 ) ;
if ( V_52 )
F_70 ( V_19 , V_52 , V_52 -> V_89 , false ) ;
}
static struct V_4 *
F_81 ( struct V_1 * V_2 , int type , const char * V_10 ,
int V_117 , unsigned long V_20 )
{
struct V_4 * V_12 ;
V_12 = F_4 ( V_2 , V_10 , & V_118 [ type ] ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_119 = V_117 ;
if ( F_82 ( V_20 ) )
V_12 -> V_120 = V_121 ;
V_12 -> V_122 = V_20 ;
return V_12 ;
}
static int F_83 ( struct V_1 * V_2 , int type ,
const char * V_62 , const char * V_61 ,
const char * V_123 , int V_117 , unsigned long V_20 )
{
char V_10 [ V_124 ] ;
snprintf ( V_10 , sizeof( V_10 ) , L_32 , V_62 , V_61 , V_123 ) ;
if ( ! F_81 ( V_2 , type , V_10 , V_117 , V_20 ) )
return - V_125 ;
return 0 ;
}
static int F_84 ( struct V_18 * V_19 , const char * V_62 , int V_117 ,
unsigned int V_79 , struct V_6 * V_52 )
{
unsigned int V_20 ;
if ( ! V_52 )
return 0 ;
V_20 = V_52 -> V_60 [ V_101 ] ;
if ( ! V_20 )
return 0 ;
V_20 = F_46 ( V_20 , V_79 ) ;
return F_85 ( V_19 -> V_2 , V_126 , V_62 , V_117 , V_20 ) ;
}
static int F_86 ( struct V_18 * V_19 , struct V_6 * V_52 ,
int type )
{
int V_79 = 1 ;
if ( V_52 ) {
T_1 V_50 = F_82 ( V_52 -> V_60 [ type ] ) ;
if ( V_50 && ( F_40 ( V_19 , V_50 ) & V_98 ) )
V_79 = 3 ;
}
return V_79 ;
}
static int F_87 ( struct V_18 * V_19 , const char * V_62 , int V_117 ,
struct V_6 * V_52 )
{
int V_79 = F_86 ( V_19 , V_52 , V_101 ) ;
return F_84 ( V_19 , V_62 , V_117 , V_79 , V_52 ) ;
}
static int F_88 ( struct V_18 * V_19 , const char * V_62 , int V_117 ,
unsigned int V_79 , struct V_6 * V_52 )
{
unsigned int V_20 ;
int type = V_127 ;
if ( ! V_52 )
return 0 ;
V_20 = V_52 -> V_60 [ V_100 ] ;
if ( ! V_20 )
return 0 ;
V_20 = F_46 ( V_20 , V_79 ) ;
if ( F_89 ( V_20 ) == V_83 ) {
T_1 V_50 = F_82 ( V_20 ) ;
int V_51 = F_58 ( V_19 , V_50 ) ;
if ( V_51 > 1 ) {
type = V_128 ;
V_20 |= V_51 << 19 ;
}
}
return F_90 ( V_19 -> V_2 , type , V_62 , V_117 , V_20 ) ;
}
static int F_91 ( struct V_18 * V_19 , const char * V_62 ,
int V_117 , struct V_6 * V_52 )
{
int V_79 = F_86 ( V_19 , V_52 , V_100 ) ;
return F_88 ( V_19 , V_62 , V_117 , V_79 , V_52 ) ;
}
static void F_92 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_33 ) {
T_1 V_50 = F_94 ( V_130 ) ;
bool V_133 = ! ( ( V_2 -> V_134 >> V_50 ) & 1 ) ;
V_132 -> V_135 . integer . V_135 [ 0 ] &= V_133 ;
V_132 -> V_135 . integer . V_135 [ 1 ] &= V_133 ;
}
}
static int F_95 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
F_92 ( V_130 , V_132 ) ;
return F_96 ( V_130 , V_132 ) ;
}
static int F_97 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
F_92 ( V_130 , V_132 ) ;
return F_98 ( V_130 , V_132 ) ;
}
static bool F_99 ( struct V_18 * V_19 , int V_116 , int V_136 )
{
struct V_6 * V_52 = F_27 ( V_19 , V_116 ) ;
return V_52 && V_52 -> V_60 [ V_136 ] ;
}
static const char * F_100 ( struct V_18 * V_19 , int V_137 ,
int * V_119 , int V_136 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
* V_119 = 0 ;
if ( V_139 -> V_141 == 1 && ! V_2 -> V_142 &&
! V_139 -> V_143 && ! V_139 -> V_144 )
return V_2 -> V_145 . V_146 ? L_33 : L_34 ;
if ( V_2 -> V_147 . V_148 == 1 && ! V_2 -> V_45 &&
! V_2 -> V_147 . V_149 [ 0 ] && ! V_2 -> V_147 . V_150 [ 0 ] )
return V_2 -> V_145 . V_146 ? L_33 : L_34 ;
if ( V_137 >= V_139 -> V_141 )
return V_151 [ V_137 ] ;
switch ( V_139 -> V_152 ) {
case V_153 :
if ( ! V_137 && V_139 -> V_143 &&
! F_99 ( V_19 , V_2 -> V_154 [ 0 ] , V_136 ) )
break;
if ( V_139 -> V_141 == 1 )
return L_35 ;
if ( V_139 -> V_141 == 2 )
return V_137 ? L_36 : L_35 ;
break;
case V_155 :
if ( ! V_137 && V_139 -> V_144 &&
! F_99 ( V_19 , V_2 -> V_156 [ 0 ] , V_136 ) )
break;
if ( V_137 && V_2 -> V_142 )
break;
* V_119 = V_137 ;
return L_37 ;
case V_157 :
if ( ! V_137 && V_139 -> V_144 && V_139 -> V_143 ) {
bool V_158 = ! F_99 ( V_19 , V_2 -> V_154 [ 0 ] , V_136 ) ;
bool V_159 = ! F_99 ( V_19 , V_2 -> V_156 [ 0 ] , V_136 ) ;
if ( V_158 && V_159 )
return V_2 -> V_145 . V_146 ? L_33 : L_34 ;
if ( V_158 )
return L_38 ;
if ( V_159 )
return L_39 ;
}
}
if ( V_139 -> V_141 == 1 && ! V_2 -> V_142 )
return L_40 ;
if ( V_137 >= F_101 ( V_151 ) ) {
F_102 () ;
return L_33 ;
}
return V_151 [ V_137 ] ;
}
static int F_103 ( struct V_18 * V_19 , struct V_6 * V_52 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_50 ;
unsigned int V_20 ;
int V_160 = 0 ;
if ( ! V_52 )
return V_161 * 2 ;
if ( V_52 -> V_60 [ V_101 ] ||
V_52 -> V_60 [ V_100 ] )
return 0 ;
V_50 = F_51 ( V_19 , V_52 ) ;
if ( V_50 ) {
V_20 = F_33 ( V_50 , 3 , 0 , V_82 ) ;
if ( V_2 -> V_162 )
V_20 |= V_163 ;
if ( F_31 ( V_19 , V_20 , V_101 ) )
V_160 += V_161 ;
else
V_52 -> V_60 [ V_101 ] = V_20 ;
} else
V_160 += V_161 ;
V_50 = F_49 ( V_19 , V_52 ) ;
if ( V_50 ) {
unsigned int V_164 = F_39 ( F_40 ( V_19 , V_50 ) ) ;
if ( V_164 == V_70 || V_164 == V_66 ||
F_50 ( V_19 , V_50 , V_82 ) )
V_20 = F_33 ( V_50 , 3 , 0 , V_82 ) ;
else
V_20 = F_33 ( V_50 , 3 , 0 , V_83 ) ;
if ( F_31 ( V_19 , V_20 , V_100 ) )
V_160 += V_161 ;
else
V_52 -> V_60 [ V_100 ] = V_20 ;
} else
V_160 += V_161 ;
return V_160 ;
}
static T_1 F_104 ( struct V_18 * V_19 , int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
if ( V_139 -> V_141 > V_58 )
return V_2 -> V_165 [ V_58 ] ;
V_58 -= V_139 -> V_141 ;
if ( V_2 -> V_142 > V_58 )
return V_2 -> V_166 [ V_58 ] . V_167 ;
return 0 ;
}
static inline T_1 F_105 ( struct V_18 * V_19 ,
T_1 V_167 , T_1 V_46 )
{
return F_29 ( V_19 , V_167 , V_46 ) ? V_167 : 0 ;
}
static int F_106 ( struct V_18 * V_19 , int V_168 ,
const T_1 * V_49 , T_1 * V_169 ,
int * V_116 ,
const struct V_170 * V_171 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_172 ;
int V_160 = 0 ;
T_1 V_167 ;
if ( ! V_168 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_168 ; V_16 ++ ) {
struct V_6 * V_52 ;
T_1 V_46 = V_49 [ V_16 ] ;
V_52 = F_27 ( V_19 , V_116 [ V_16 ] ) ;
if ( V_52 ) {
V_160 += F_103 ( V_19 , V_52 ) ;
continue;
}
V_169 [ V_16 ] = F_44 ( V_19 , V_46 ) ;
if ( V_169 [ V_16 ] ) {
if ( F_28 ( V_19 , V_169 [ V_16 ] ) )
V_160 += V_171 -> V_173 ;
}
if ( ! V_169 [ V_16 ] )
V_169 [ V_16 ] = F_45 ( V_19 , V_46 , false ) ;
if ( ! V_169 [ V_16 ] && ! V_16 ) {
for ( V_172 = 1 ; V_172 < V_168 ; V_172 ++ ) {
if ( F_29 ( V_19 , V_169 [ V_172 ] , V_46 ) ) {
V_169 [ 0 ] = V_169 [ V_172 ] ;
V_169 [ V_172 ] = 0 ;
F_43 ( V_19 , V_116 [ V_172 ] ) ;
V_116 [ V_172 ] = 0 ;
break;
}
}
}
V_167 = V_169 [ V_16 ] ;
if ( ! V_167 ) {
if ( V_168 > 2 )
V_167 = F_105 ( V_19 , F_104 ( V_19 , V_16 ) , V_46 ) ;
if ( ! V_167 )
V_167 = F_105 ( V_19 , V_169 [ 0 ] , V_46 ) ;
if ( ! V_167 )
V_167 = F_105 ( V_19 , F_104 ( V_19 , V_16 ) , V_46 ) ;
if ( V_167 ) {
if ( ! V_16 )
V_160 += V_171 -> V_173 ;
else if ( V_16 == 1 )
V_160 += V_171 -> V_174 ;
else
V_160 += V_171 -> V_175 ;
} else if ( F_29 ( V_19 , V_2 -> V_165 [ 0 ] , V_46 ) ) {
V_167 = V_2 -> V_165 [ 0 ] ;
V_160 += V_171 -> V_176 ;
} else if ( ! V_16 )
V_160 += V_171 -> V_177 ;
else
V_160 += V_171 -> V_178 ;
}
if ( ! V_167 )
continue;
V_52 = F_42 ( V_19 , V_167 , V_46 , - V_2 -> V_45 ) ;
if ( ! V_52 && ! V_16 && V_2 -> V_45 ) {
V_52 = F_42 ( V_19 , V_167 , V_46 , 0 ) ;
}
if ( ! V_52 ) {
V_167 = V_169 [ V_16 ] = 0 ;
V_160 += V_171 -> V_178 ;
} else {
V_52 -> V_89 = true ;
V_116 [ V_16 ] = F_26 ( V_19 , V_52 ) ;
V_160 += F_103 ( V_19 , V_52 ) ;
}
}
return V_160 ;
}
static T_1 F_107 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_179 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_76 ; V_16 ++ ) {
T_1 V_50 = V_2 -> V_77 [ V_16 ] ;
if ( ! V_50 || F_28 ( V_19 , V_50 ) )
continue;
if ( F_29 ( V_19 , V_50 , V_46 ) ) {
if ( V_179 )
return 0 ;
V_179 = V_50 ;
}
}
return V_179 ;
}
static bool F_108 ( struct V_18 * V_19 ,
unsigned int V_180 , T_1 V_50 )
{
unsigned int V_181 , V_85 ;
V_181 = F_109 ( V_19 , V_50 ) ;
if ( F_110 ( V_181 ) != V_182 )
return false ;
if ( V_180 && F_111 ( V_181 ) != V_180 )
return false ;
V_85 = F_79 ( V_19 , V_50 ) ;
if ( ! ( V_85 & V_183 ) )
return false ;
return true ;
}
static int F_112 ( struct V_18 * V_19 , T_1 V_184 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
unsigned int V_181 = F_109 ( V_19 , V_184 ) ;
unsigned int V_180 = F_111 ( V_181 ) ;
int type , V_16 ;
int V_48 = 0 ;
for ( type = V_185 ; type >= V_186 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_139 -> V_187 ; V_16 ++ ) {
if ( V_139 -> V_188 [ V_16 ] . type != type )
continue;
if ( F_108 ( V_19 , V_180 ,
V_139 -> V_188 [ V_16 ] . V_46 ) )
V_48 ++ ;
}
}
return V_48 ;
}
static int F_113 ( struct V_18 * V_19 ,
T_1 V_184 ,
bool V_189 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
int type , V_16 , V_172 , V_48 , V_190 ;
unsigned int V_181 = F_109 ( V_19 , V_184 ) ;
unsigned int V_180 = F_111 ( V_181 ) ;
int V_160 = 0 ;
struct V_6 * V_52 ;
V_190 = V_2 -> V_142 ;
if ( V_190 >= 2 )
goto V_191;
V_48 = F_112 ( V_19 , V_184 ) ;
if ( V_48 < 2 )
goto V_191;
for ( type = V_185 ; type >= V_186 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_139 -> V_187 ; V_16 ++ ) {
T_1 V_50 = V_139 -> V_188 [ V_16 ] . V_46 ;
T_1 V_167 = 0 ;
if ( V_139 -> V_188 [ V_16 ] . type != type )
continue;
if ( ! F_108 ( V_19 , V_180 , V_50 ) )
continue;
for ( V_172 = 0 ; V_172 < V_2 -> V_142 ; V_172 ++ ) {
if ( V_50 == V_2 -> V_166 [ V_172 ] . V_46 )
break;
}
if ( V_172 < V_2 -> V_142 )
continue;
if ( V_189 )
V_167 = F_107 ( V_19 , V_50 ) ;
else if ( ! V_167 )
V_167 = F_45 ( V_19 , V_50 , false ) ;
if ( ! V_167 ) {
V_160 ++ ;
continue;
}
V_52 = F_42 ( V_19 , V_167 , V_50 ,
- V_2 -> V_45 ) ;
if ( ! V_52 ) {
V_160 ++ ;
continue;
}
V_2 -> V_166 [ V_2 -> V_142 ] . V_46 = V_50 ;
V_2 -> V_166 [ V_2 -> V_142 ] . V_167 = V_167 ;
V_2 -> V_192 [ V_139 -> V_141 + V_2 -> V_142 ] =
F_26 ( V_19 , V_52 ) ;
V_2 -> V_142 ++ ;
if ( V_2 -> V_142 >= 2 )
break;
}
}
V_191:
if ( V_160 )
V_160 = V_193 ;
if ( V_190 == V_2 -> V_142 ) {
if ( V_189 )
return 1 ;
else
return V_160 ;
}
if ( ! V_189 && V_2 -> V_142 < 2 ) {
V_2 -> V_5 . V_17 -= V_2 -> V_142 - V_190 ;
V_2 -> V_142 = V_190 ;
return V_160 ;
}
for ( V_16 = V_190 ; V_16 < V_2 -> V_142 ; V_16 ++ ) {
V_52 = F_27 ( V_19 , V_2 -> V_192 [ V_139 -> V_141 + V_16 ] ) ;
V_160 += F_103 ( V_19 , V_52 ) ;
}
return V_160 ;
}
static bool F_114 ( struct V_18 * V_19 , int V_194 ,
const T_1 * V_49 , T_1 * V_169 , int * V_116 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
bool V_67 = false ;
for ( V_16 = 0 ; V_16 < V_194 ; V_16 ++ ) {
struct V_6 * V_52 ;
T_1 V_167 ;
if ( V_169 [ V_16 ] )
continue;
V_167 = F_107 ( V_19 , V_49 [ V_16 ] ) ;
if ( ! V_167 )
continue;
V_52 = F_42 ( V_19 , V_167 , V_49 [ V_16 ] ,
- V_2 -> V_45 ) ;
if ( ! V_52 && ! V_16 && V_2 -> V_45 )
V_52 = F_42 ( V_19 , V_167 , V_49 [ V_16 ] , 0 ) ;
if ( V_52 ) {
V_169 [ V_16 ] = V_167 ;
V_67 = true ;
V_52 -> V_89 = true ;
V_116 [ V_16 ] = F_26 ( V_19 , V_52 ) ;
}
}
return V_67 ;
}
static int F_115 ( struct V_18 * V_19 , int V_116 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_52 ;
T_1 V_195 , V_167 , V_46 ;
V_52 = F_27 ( V_19 , V_116 ) ;
if ( ! V_52 || ! V_52 -> V_53 ||
F_22 ( V_52 , V_2 -> V_45 ) )
return 0 ;
V_195 = V_52 -> V_52 [ 0 ] ;
V_167 = V_2 -> V_165 [ 0 ] ;
V_46 = V_52 -> V_52 [ V_52 -> V_53 - 1 ] ;
V_52 = F_42 ( V_19 , V_167 , V_46 , V_2 -> V_45 ) ;
if ( ! V_52 ) {
if ( V_167 != V_195 )
V_167 = V_195 ;
else if ( V_2 -> V_147 . V_149 [ 0 ] )
V_167 = V_2 -> V_147 . V_149 [ 0 ] ;
else if ( V_2 -> V_147 . V_150 [ 0 ] )
V_167 = V_2 -> V_147 . V_150 [ 0 ] ;
else
V_167 = 0 ;
if ( V_167 )
V_52 = F_42 ( V_19 , V_167 , V_46 ,
V_2 -> V_45 ) ;
}
if ( ! V_52 )
return 0 ;
V_52 -> V_89 = false ;
return F_26 ( V_19 , V_52 ) ;
}
static bool F_116 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
struct V_6 * V_52 ;
int V_16 , V_58 ;
if ( V_139 -> V_152 == V_155 )
V_58 = V_2 -> V_192 [ 0 ] ;
else
V_58 = V_2 -> V_154 [ 0 ] ;
V_52 = F_27 ( V_19 , V_58 ) ;
if ( ! V_52 )
return false ;
if ( ! V_2 -> V_45 || ! F_22 ( V_52 , V_2 -> V_45 ) )
return true ;
for ( V_16 = 0 ; V_16 < V_139 -> V_141 ; V_16 ++ ) {
if ( V_2 -> V_192 [ V_16 ] == V_58 )
break;
V_52 = F_27 ( V_19 , V_2 -> V_192 [ V_16 ] ) ;
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
static void F_117 ( struct V_18 * V_19 , int V_168 ,
T_1 * V_169 , int * V_116 )
{
struct V_6 * V_52 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_168 ; V_16 ++ ) {
if ( V_169 [ V_16 ] )
continue;
V_52 = F_27 ( V_19 , V_116 [ V_16 ] ) ;
if ( ! V_52 )
continue;
V_169 [ V_16 ] = V_52 -> V_52 [ 0 ] ;
}
}
static int F_118 ( struct V_18 * V_19 ,
bool V_196 ,
bool V_197 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
int V_16 , V_198 , V_160 ;
V_2 -> V_147 . V_148 = V_139 -> V_141 ;
V_2 -> V_147 . V_199 = V_2 -> V_165 ;
memset ( V_2 -> V_165 , 0 , sizeof( V_2 -> V_165 ) ) ;
memset ( V_2 -> V_147 . V_149 , 0 , sizeof( V_2 -> V_147 . V_149 ) ) ;
memset ( V_2 -> V_147 . V_150 , 0 , sizeof( V_2 -> V_147 . V_150 ) ) ;
V_2 -> V_142 = 0 ;
F_9 ( & V_2 -> V_5 ) ;
memset ( V_2 -> V_192 , 0 , sizeof( V_2 -> V_192 ) ) ;
memset ( V_2 -> V_154 , 0 , sizeof( V_2 -> V_154 ) ) ;
memset ( V_2 -> V_156 , 0 , sizeof( V_2 -> V_156 ) ) ;
memset ( V_2 -> V_200 , 0 , sizeof( V_2 -> V_200 ) ) ;
memset ( V_2 -> V_201 , 0 , sizeof( V_2 -> V_201 ) ) ;
memset ( V_2 -> V_202 , 0 , sizeof( V_2 -> V_202 ) ) ;
memset ( V_2 -> V_203 , 0 , sizeof( V_2 -> V_203 ) ) ;
memset ( & V_2 -> V_204 , 0 , sizeof( V_2 -> V_204 ) ) ;
V_160 = 0 ;
if ( V_196 ) {
bool V_205 ;
do {
V_205 = F_114 ( V_19 , V_139 -> V_141 ,
V_139 -> V_206 ,
V_2 -> V_165 ,
V_2 -> V_192 ) ;
V_205 |= F_114 ( V_19 , V_139 -> V_143 ,
V_139 -> V_207 ,
V_2 -> V_147 . V_149 ,
V_2 -> V_154 ) ;
V_205 |= F_114 ( V_19 , V_139 -> V_144 ,
V_139 -> V_208 ,
V_2 -> V_147 . V_150 ,
V_2 -> V_156 ) ;
if ( ! V_2 -> V_36 &&
V_197 && V_139 -> V_141 == 1 &&
V_139 -> V_152 != V_153 ) {
V_198 = F_113 ( V_19 , V_139 -> V_206 [ 0 ] , true ) ;
if ( ! V_198 )
V_205 = true ;
}
} while ( V_205 );
}
V_160 += F_106 ( V_19 , V_139 -> V_141 , V_139 -> V_206 ,
V_2 -> V_165 , V_2 -> V_192 ,
V_2 -> V_209 ) ;
if ( ! V_2 -> V_36 && V_197 &&
V_139 -> V_141 == 1 && V_139 -> V_152 != V_153 ) {
V_198 = F_113 ( V_19 , V_139 -> V_206 [ 0 ] , false ) ;
if ( V_198 < 0 )
return V_198 ;
}
if ( V_139 -> V_152 != V_155 ) {
V_198 = F_106 ( V_19 , V_139 -> V_143 , V_139 -> V_207 ,
V_2 -> V_147 . V_149 ,
V_2 -> V_154 ,
V_2 -> V_210 ) ;
if ( V_198 < 0 )
return V_198 ;
V_160 += V_198 ;
}
if ( V_139 -> V_152 != V_153 ) {
V_198 = F_106 ( V_19 , V_139 -> V_144 ,
V_139 -> V_208 ,
V_2 -> V_147 . V_150 ,
V_2 -> V_156 ,
V_2 -> V_210 ) ;
if ( V_198 < 0 )
return V_198 ;
V_160 += V_198 ;
}
if ( ! V_2 -> V_36 &&
V_139 -> V_141 == 1 && V_139 -> V_152 != V_153 ) {
V_198 = F_113 ( V_19 , V_139 -> V_206 [ 0 ] , false ) ;
if ( V_198 < 0 )
return V_198 ;
V_160 += V_198 ;
}
if ( V_2 -> V_45 ) {
V_2 -> V_200 [ 0 ] =
F_115 ( V_19 , V_2 -> V_192 [ 0 ] ) ;
if ( V_139 -> V_152 != V_155 )
V_2 -> V_200 [ 1 ] =
F_115 ( V_19 , V_2 -> V_154 [ 0 ] ) ;
if ( V_139 -> V_152 != V_153 )
V_2 -> V_200 [ 2 ] =
F_115 ( V_19 , V_2 -> V_156 [ 0 ] ) ;
}
if ( ! V_2 -> V_36 &&
V_139 -> V_143 && V_139 -> V_152 == V_153 )
if ( F_112 ( V_19 , V_139 -> V_207 [ 0 ] ) >= 2 )
V_2 -> V_142 = 1 ;
V_2 -> V_147 . V_148 = 0 ;
for ( V_16 = 0 ; V_16 < V_139 -> V_141 ; V_16 ++ ) {
if ( V_2 -> V_165 [ V_16 ] )
V_2 -> V_147 . V_148 ++ ;
else {
memmove ( V_2 -> V_165 + V_16 ,
V_2 -> V_165 + V_16 + 1 ,
sizeof( T_1 ) * ( V_139 -> V_141 - V_16 - 1 ) ) ;
V_2 -> V_165 [ V_139 -> V_141 - 1 ] = 0 ;
}
}
V_2 -> V_211 = V_2 -> V_212 =
V_2 -> V_147 . V_148 * 2 ;
if ( V_2 -> V_142 == 2 ) {
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
V_2 -> V_165 [ V_2 -> V_147 . V_148 ++ ] =
V_2 -> V_166 [ V_16 ] . V_167 ;
} else if ( V_2 -> V_142 ) {
V_2 -> V_142 = 0 ;
V_160 += V_193 ;
}
if ( V_2 -> V_39 && ! F_116 ( V_19 ) )
V_160 += V_213 ;
if ( V_139 -> V_152 != V_155 )
F_117 ( V_19 , V_139 -> V_143 ,
V_2 -> V_147 . V_149 ,
V_2 -> V_154 ) ;
if ( V_139 -> V_152 != V_153 )
F_117 ( V_19 , V_139 -> V_144 ,
V_2 -> V_147 . V_150 ,
V_2 -> V_156 ) ;
return V_160 ;
}
static inline void F_119 ( struct V_18 * V_19 ,
const char * V_62 , int V_58 )
{
struct V_6 * V_52 ;
V_52 = F_27 ( V_19 , V_58 ) ;
if ( V_52 )
F_34 ( V_19 , V_62 , V_52 ) ;
}
static void F_120 ( struct V_18 * V_19 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_214 [ 3 ] = { L_41 , L_42 , L_43 } ;
int V_16 ;
F_121 ( L_44 ,
V_139 -> V_206 [ 0 ] , V_139 -> V_206 [ 1 ] ,
V_139 -> V_206 [ 2 ] , V_139 -> V_206 [ 3 ] ,
V_2 -> V_147 . V_199 [ 0 ] ,
V_2 -> V_147 . V_199 [ 1 ] ,
V_2 -> V_147 . V_199 [ 2 ] ,
V_2 -> V_147 . V_199 [ 3 ] ,
V_214 [ V_139 -> V_152 ] ) ;
for ( V_16 = 0 ; V_16 < V_139 -> V_141 ; V_16 ++ )
F_119 ( V_19 , L_45 , V_2 -> V_192 [ V_16 ] ) ;
if ( V_2 -> V_142 > 0 )
F_121 ( L_46 ,
V_2 -> V_142 ,
V_2 -> V_166 [ 0 ] . V_46 , V_2 -> V_166 [ 1 ] . V_46 ,
V_2 -> V_166 [ 0 ] . V_167 , V_2 -> V_166 [ 1 ] . V_167 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_142 ; V_16 ++ )
F_119 ( V_19 , L_47 ,
V_2 -> V_192 [ V_139 -> V_141 + V_16 ] ) ;
if ( V_139 -> V_143 )
F_121 ( L_48 ,
V_139 -> V_207 [ 0 ] , V_139 -> V_207 [ 1 ] ,
V_139 -> V_207 [ 2 ] , V_139 -> V_207 [ 3 ] ,
V_2 -> V_147 . V_149 [ 0 ] ,
V_2 -> V_147 . V_149 [ 1 ] ,
V_2 -> V_147 . V_149 [ 2 ] ,
V_2 -> V_147 . V_149 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_139 -> V_143 ; V_16 ++ )
F_119 ( V_19 , L_49 , V_2 -> V_154 [ V_16 ] ) ;
if ( V_139 -> V_144 )
F_121 ( L_50 ,
V_139 -> V_208 [ 0 ] , V_139 -> V_208 [ 1 ] ,
V_139 -> V_208 [ 2 ] , V_139 -> V_208 [ 3 ] ,
V_2 -> V_147 . V_150 [ 0 ] ,
V_2 -> V_147 . V_150 [ 1 ] ,
V_2 -> V_147 . V_150 [ 2 ] ,
V_2 -> V_147 . V_150 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_139 -> V_144 ; V_16 ++ )
F_119 ( V_19 , L_51 , V_2 -> V_156 [ V_16 ] ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ )
F_119 ( V_19 , L_52 , V_2 -> V_200 [ V_16 ] ) ;
}
static void F_122 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_50 = V_19 -> V_215 ;
V_2 -> V_76 = 0 ;
memset ( V_2 -> V_77 , 0 , sizeof( V_2 -> V_77 ) ) ;
for ( V_16 = 0 ; V_16 < V_19 -> V_216 ; V_16 ++ , V_50 ++ ) {
if ( F_39 ( F_40 ( V_19 , V_50 ) ) != V_66 )
continue;
if ( V_2 -> V_76 >= F_101 ( V_2 -> V_77 ) ) {
F_123 ( V_19 , L_53 ) ;
break;
}
V_2 -> V_77 [ V_2 -> V_76 ++ ] = V_50 ;
}
}
static int F_124 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
struct V_138 * V_217 ;
unsigned int V_20 ;
int V_218 = V_219 ;
int V_160 ;
bool V_196 = true , V_197 = true ;
bool V_220 = true , V_221 = true ;
bool V_222 = false ;
V_217 = F_125 ( sizeof( * V_217 ) , V_13 ) ;
if ( ! V_217 )
return - V_125 ;
* V_217 = * V_139 ;
for (; ; ) {
V_160 = F_118 ( V_19 , V_196 ,
V_197 ) ;
if ( V_160 < 0 ) {
F_8 ( V_217 ) ;
return V_160 ;
}
F_121 ( L_54 ,
V_139 -> V_152 , V_196 , V_197 ,
V_160 ) ;
F_120 ( V_19 , V_139 ) ;
if ( V_160 < V_218 ) {
V_218 = V_160 ;
* V_217 = * V_139 ;
V_220 = V_196 ;
V_221 = V_197 ;
}
if ( ! V_160 )
break;
V_197 = ! V_197 ;
if ( ! V_197 )
continue;
V_196 = ! V_196 ;
if ( ! V_196 )
continue;
if ( V_222 )
break;
V_222 = true ;
if ( V_139 -> V_144 > 0 &&
V_139 -> V_152 == V_155 ) {
V_139 -> V_143 = V_139 -> V_141 ;
memcpy ( V_139 -> V_207 , V_139 -> V_206 ,
sizeof( V_139 -> V_207 ) ) ;
V_139 -> V_141 = V_139 -> V_144 ;
memcpy ( V_139 -> V_206 , V_139 -> V_208 ,
sizeof( V_139 -> V_208 ) ) ;
V_139 -> V_144 = 0 ;
memset ( V_139 -> V_208 , 0 , sizeof( V_139 -> V_208 ) ) ;
V_139 -> V_152 = V_153 ;
V_196 = true ;
continue;
}
if ( V_139 -> V_143 > 0 &&
V_139 -> V_152 == V_153 ) {
V_139 -> V_144 = V_139 -> V_141 ;
memcpy ( V_139 -> V_208 , V_139 -> V_206 ,
sizeof( V_139 -> V_208 ) ) ;
V_139 -> V_141 = V_139 -> V_143 ;
memcpy ( V_139 -> V_206 , V_139 -> V_207 ,
sizeof( V_139 -> V_207 ) ) ;
V_139 -> V_143 = 0 ;
memset ( V_139 -> V_207 , 0 , sizeof( V_139 -> V_207 ) ) ;
V_139 -> V_152 = V_155 ;
V_196 = true ;
continue;
}
break;
}
if ( V_160 ) {
F_121 ( L_55 ) ;
* V_139 = * V_217 ;
F_118 ( V_19 , V_220 , V_221 ) ;
}
F_121 ( L_56 ,
V_139 -> V_152 , V_220 , V_221 ) ;
F_120 ( V_19 , V_139 ) ;
if ( V_139 -> V_206 [ 0 ] ) {
struct V_6 * V_52 ;
V_52 = F_27 ( V_19 , V_2 -> V_192 [ 0 ] ) ;
if ( V_52 )
V_2 -> V_223 = F_51 ( V_19 , V_52 ) ;
if ( V_2 -> V_223 ) {
F_126 ( V_19 , V_2 -> V_223 ,
V_82 , V_2 -> V_224 ) ;
if ( V_2 -> V_162 )
V_2 -> V_224 [ 3 ] |= V_225 ;
}
}
if ( V_2 -> V_226 || V_139 -> V_152 == V_155 )
V_20 = V_227 ;
else
V_20 = V_228 ;
F_20 ( V_19 , V_139 -> V_141 , V_139 -> V_206 , V_20 ) ;
if ( V_139 -> V_152 != V_155 )
F_20 ( V_19 , V_139 -> V_143 , V_139 -> V_207 , V_227 ) ;
if ( V_139 -> V_152 != V_153 ) {
V_20 = V_2 -> V_226 ? V_227 : V_228 ;
F_20 ( V_19 , V_139 -> V_144 ,
V_139 -> V_208 , V_20 ) ;
}
if ( V_2 -> V_39 && ! F_116 ( V_19 ) )
V_2 -> V_39 = 0 ;
F_8 ( V_217 ) ;
return 0 ;
}
static int F_127 ( struct V_18 * V_19 ,
const struct V_138 * V_139 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_198 , V_229 ;
V_229 = V_139 -> V_141 ;
if ( V_2 -> V_142 > 0 && V_139 -> V_141 < 3 )
V_229 += V_2 -> V_142 ;
for ( V_16 = 0 ; V_16 < V_229 ; V_16 ++ ) {
const char * V_10 ;
int V_119 ;
struct V_6 * V_52 ;
V_52 = F_27 ( V_19 , V_2 -> V_192 [ V_16 ] ) ;
if ( ! V_52 )
continue;
V_10 = F_100 ( V_19 , V_16 , & V_119 , V_101 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_57 ) ) {
V_198 = F_84 ( V_19 , L_58 , 0 , 1 , V_52 ) ;
if ( V_198 < 0 )
return V_198 ;
V_198 = F_84 ( V_19 , L_59 , 0 , 2 , V_52 ) ;
if ( V_198 < 0 )
return V_198 ;
} else {
V_198 = F_87 ( V_19 , V_10 , V_119 , V_52 ) ;
if ( V_198 < 0 )
return V_198 ;
}
V_10 = F_100 ( V_19 , V_16 , & V_119 , V_100 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_57 ) ) {
V_198 = F_88 ( V_19 , L_58 , 0 , 1 , V_52 ) ;
if ( V_198 < 0 )
return V_198 ;
V_198 = F_88 ( V_19 , L_59 , 0 , 2 , V_52 ) ;
if ( V_198 < 0 )
return V_198 ;
} else {
V_198 = F_91 ( V_19 , V_10 , V_119 , V_52 ) ;
if ( V_198 < 0 )
return V_198 ;
}
}
return 0 ;
}
static int F_128 ( struct V_18 * V_19 , int V_116 ,
const char * V_62 , int V_117 )
{
struct V_6 * V_52 ;
int V_198 ;
V_52 = F_27 ( V_19 , V_116 ) ;
if ( ! V_52 )
return 0 ;
V_198 = F_87 ( V_19 , V_62 , V_117 , V_52 ) ;
if ( V_198 < 0 )
return V_198 ;
V_198 = F_91 ( V_19 , V_62 , V_117 , V_52 ) ;
if ( V_198 < 0 )
return V_198 ;
return 0 ;
}
static int F_129 ( struct V_18 * V_19 , int V_48 ,
const int * V_5 , const char * V_62 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
const char * V_10 ;
char V_230 [ V_124 ] ;
int V_198 , V_58 = 0 ;
if ( V_48 == 2 && V_16 == 1 && ! strcmp ( V_62 , L_35 ) )
V_10 = L_36 ;
else if ( V_48 >= 3 ) {
snprintf ( V_230 , sizeof( V_230 ) , L_60 ,
V_62 , V_151 [ V_16 ] ) ;
V_10 = V_230 ;
} else {
V_10 = V_62 ;
V_58 = V_16 ;
}
V_198 = F_128 ( V_19 , V_5 [ V_16 ] , V_10 , V_58 ) ;
if ( V_198 < 0 )
return V_198 ;
}
return 0 ;
}
static int F_130 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_129 ( V_19 , V_2 -> V_140 . V_143 ,
V_2 -> V_154 ,
L_37 ) ;
}
static int F_131 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_129 ( V_19 , V_2 -> V_140 . V_144 ,
V_2 -> V_156 ,
L_35 ) ;
}
static int F_132 ( struct V_129 * V_130 ,
struct V_231 * V_232 )
{
return F_133 ( V_130 , V_232 ) ;
}
static int F_134 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_132 -> V_135 . V_233 . V_234 [ 0 ] = V_2 -> V_235 ;
return 0 ;
}
static int F_135 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_236 = V_132 -> V_135 . V_233 . V_234 [ 0 ] ;
int V_237 = 0 ;
F_136 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_238 ) {
V_237 = - V_239 ;
goto V_240;
}
if ( V_2 -> V_235 != V_236 ) {
T_1 * V_241 ;
if ( V_2 -> V_140 . V_152 == V_155 )
V_241 = & V_2 -> V_165 [ 0 ] ;
else
V_241 = & V_2 -> V_147 . V_149 [ 0 ] ;
if ( V_2 -> V_242 ) {
if ( V_2 -> V_140 . V_152 == V_155 )
F_137 ( V_19 , V_2 -> V_243 ,
V_2 -> V_192 [ 0 ] ,
V_2 -> V_200 [ 0 ] ,
V_2 -> V_140 . V_152 ) ;
else
F_137 ( V_19 , V_2 -> V_243 ,
V_2 -> V_154 [ 0 ] ,
V_2 -> V_200 [ 1 ] ,
V_155 ) ;
}
V_2 -> V_235 = V_236 ;
if ( V_2 -> V_235 )
* V_241 = 0 ;
else
* V_241 = V_2 -> V_244 ;
F_138 ( V_19 , NULL ) ;
V_237 = 1 ;
}
V_240:
F_139 ( & V_2 -> V_9 ) ;
return V_237 ;
}
static int F_140 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_167 ;
if ( ! V_2 -> V_39 )
return 0 ;
if ( V_2 -> V_140 . V_152 == V_155 )
V_167 = V_2 -> V_147 . V_199 [ 0 ] ;
else
V_167 = V_2 -> V_147 . V_149 [ 0 ] ;
if ( ! V_167 ) {
V_2 -> V_39 = 0 ;
return 0 ;
}
V_2 -> V_235 = false ;
V_2 -> V_244 = V_167 ;
if ( ! F_4 ( V_2 , NULL , & V_245 ) )
return - V_125 ;
return 0 ;
}
static int F_141 ( struct V_129 * V_130 ,
struct V_231 * V_232 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_79 ;
V_232 -> type = V_246 ;
V_232 -> V_247 = 1 ;
V_232 -> V_135 . V_233 . V_248 = V_2 -> V_142 + 1 ;
if ( V_232 -> V_135 . V_233 . V_234 > V_2 -> V_142 )
V_232 -> V_135 . V_233 . V_234 = V_2 -> V_142 ;
V_79 = V_232 -> V_135 . V_233 . V_234 * 2 + V_2 -> V_212 ;
sprintf ( V_232 -> V_135 . V_233 . V_10 , L_61 , V_79 ) ;
return 0 ;
}
static int F_142 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_132 -> V_135 . V_233 . V_234 [ 0 ] =
( V_2 -> V_211 - V_2 -> V_212 ) / 2 ;
return 0 ;
}
static inline struct V_6 *
F_143 ( struct V_18 * V_19 , int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_27 ( V_19 ,
V_2 -> V_192 [ V_2 -> V_140 . V_141 + V_58 ] ) ;
}
static bool F_144 ( struct V_1 * V_2 )
{
return ! V_2 -> V_242 || V_2 -> V_243 ;
}
static int F_145 ( struct V_18 * V_19 , int V_58 , bool V_249 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_50 = V_2 -> V_166 [ V_58 ] . V_46 ;
struct V_6 * V_52 ;
V_52 = F_143 ( V_19 , V_58 ) ;
if ( ! V_52 )
return - V_250 ;
if ( V_52 -> V_89 == V_249 )
return 0 ;
if ( V_249 ) {
F_17 ( V_19 , V_50 , V_228 , true ) ;
F_70 ( V_19 , V_52 , true , F_144 ( V_2 ) ) ;
F_78 ( V_19 , V_50 , true ) ;
} else {
F_78 ( V_19 , V_50 , false ) ;
F_70 ( V_19 , V_52 , false , F_144 ( V_2 ) ) ;
F_17 ( V_19 , V_50 , V_2 -> V_166 [ V_58 ] . V_251 , true ) ;
F_74 ( V_19 , V_52 ) ;
}
F_146 ( V_19 ) ;
return 0 ;
}
static int F_147 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_137 ;
V_137 = V_132 -> V_135 . V_233 . V_234 [ 0 ] ;
if ( V_137 < 0 || V_137 > V_2 -> V_142 )
return - V_250 ;
if ( V_137 == ( V_2 -> V_211 - V_2 -> V_212 ) / 2 )
return 0 ;
V_2 -> V_211 = V_137 * 2 + V_2 -> V_212 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_142 ; V_16 ++ )
F_145 ( V_19 , V_16 , V_16 < V_137 ) ;
V_2 -> V_147 . V_252 = F_148 ( V_2 -> V_211 ,
V_2 -> V_253 ) ;
if ( V_2 -> V_34 )
V_2 -> V_147 . V_148 = V_2 -> V_147 . V_252 / 2 ;
return 1 ;
}
static int F_149 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_142 > 0 ) {
if ( ! F_4 ( V_2 , NULL , & V_254 ) )
return - V_125 ;
}
return 0 ;
}
static int F_150 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_132 -> V_135 . V_233 . V_234 [ 0 ] = V_2 -> V_243 ;
return 0 ;
}
static void F_137 ( struct V_18 * V_19 , bool V_255 ,
int V_256 , int V_257 ,
int V_258 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_259 , * V_260 ;
V_259 = F_27 ( V_19 , V_256 ) ;
V_260 = F_27 ( V_19 , V_257 ) ;
if ( ! V_259 || ! V_260 )
return;
if ( V_258 == V_155 && V_2 -> V_235 &&
V_260 -> V_52 [ 0 ] != V_2 -> V_244 )
V_255 = false ;
if ( V_255 ) {
F_70 ( V_19 , V_259 , false , true ) ;
F_70 ( V_19 , V_260 , true , true ) ;
F_74 ( V_19 , V_259 ) ;
} else {
F_70 ( V_19 , V_260 , false , false ) ;
F_70 ( V_19 , V_259 , true , false ) ;
F_74 ( V_19 , V_260 ) ;
}
}
static int F_151 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = V_132 -> V_135 . V_233 . V_234 [ 0 ] ;
if ( V_20 == V_2 -> V_243 )
return 0 ;
V_2 -> V_243 = V_20 ;
F_137 ( V_19 , V_20 , V_2 -> V_192 [ 0 ] ,
V_2 -> V_200 [ 0 ] ,
V_2 -> V_140 . V_152 ) ;
F_137 ( V_19 , V_20 , V_2 -> V_154 [ 0 ] ,
V_2 -> V_200 [ 1 ] ,
V_155 ) ;
F_137 ( V_19 , V_20 , V_2 -> V_156 [ 0 ] ,
V_2 -> V_200 [ 2 ] ,
V_153 ) ;
return 1 ;
}
static int F_152 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_45 )
return 0 ;
if ( ! ( V_2 -> V_200 [ 0 ] || V_2 -> V_200 [ 1 ] ||
V_2 -> V_200 [ 2 ] ) )
return 0 ;
if ( ! F_4 ( V_2 , NULL , & V_261 ) )
return - V_125 ;
V_2 -> V_242 = 1 ;
return 0 ;
}
static void F_153 ( struct V_18 * V_19 , int V_262 , bool V_263 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_264 ;
unsigned int V_20 ;
T_1 V_46 ;
V_46 = V_2 -> V_265 ;
V_264 = V_2 -> V_266 [ V_262 ] == V_2 -> V_267 ;
if ( ! V_263 ) {
V_20 = F_16 ( V_19 , V_46 ) ;
if ( V_264 ) {
if ( V_20 & V_268 )
return;
} else {
if ( V_20 & V_228 )
return;
}
}
V_20 = F_154 ( V_19 , V_46 ) ;
if ( V_20 == V_269 && V_2 -> V_270 ) {
const T_1 V_271 = V_2 -> V_270 ;
unsigned int V_272 = F_154 ( V_19 , V_271 ) ;
if ( V_272 != V_269 )
F_155 ( V_19 , V_271 ,
V_268 | ( V_264 ? V_272 : 0 ) ) ;
}
if ( ! V_2 -> V_273 ) {
if ( V_264 )
V_20 |= V_268 ;
else
V_20 = V_227 ;
F_17 ( V_19 , V_46 , V_20 , true ) ;
F_138 ( V_19 , NULL ) ;
}
}
static int F_156 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
unsigned int V_181 ;
T_1 V_50 ;
if ( ! V_2 -> V_43 ) {
if ( V_2 -> V_44 )
return 0 ;
if ( V_139 -> V_187 > 1 )
return 0 ;
else if ( V_139 -> V_187 == 1 ) {
V_181 = F_109 ( V_19 , V_139 -> V_188 [ 0 ] . V_46 ) ;
if ( F_157 ( V_181 ) != V_274 )
return 0 ;
}
}
V_2 -> V_43 = 0 ;
if ( V_139 -> V_187 >= V_275 )
return 0 ;
V_50 = 0 ;
if ( V_139 -> V_152 == V_155 && V_139 -> V_141 > 0 )
V_50 = V_139 -> V_206 [ 0 ] ;
else if ( V_139 -> V_143 > 0 )
V_50 = V_139 -> V_207 [ 0 ] ;
if ( ! V_50 )
return 0 ;
if ( ! ( F_79 ( V_19 , V_50 ) & V_276 ) )
return 0 ;
V_139 -> V_188 [ V_139 -> V_187 ] . V_46 = V_50 ;
V_139 -> V_188 [ V_139 -> V_187 ] . type = V_186 ;
V_139 -> V_188 [ V_139 -> V_187 ] . V_277 = 1 ;
V_139 -> V_187 ++ ;
V_2 -> V_43 = 1 ;
V_2 -> V_265 = V_50 ;
V_2 -> V_31 = 1 ;
F_36 ( V_19 , L_62 , V_50 ) ;
return 0 ;
}
static int F_158 ( struct V_129 * V_130 ,
struct V_231 * V_232 )
{
return F_159 ( V_130 , V_232 , 2 , V_278 ) ;
}
static int F_160 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
T_1 V_50 = V_130 -> V_122 ;
if ( F_16 ( V_19 , V_50 ) == V_227 )
V_132 -> V_135 . V_233 . V_234 [ 0 ] = 1 ;
else
V_132 -> V_135 . V_233 . V_234 [ 0 ] = 0 ;
return 0 ;
}
static int F_161 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
T_1 V_50 = V_130 -> V_122 ;
unsigned int V_20 ;
V_20 = V_132 -> V_135 . V_233 . V_234 [ 0 ] ? V_227 : V_228 ;
if ( F_16 ( V_19 , V_50 ) == V_20 )
return 0 ;
F_155 ( V_19 , V_50 , V_20 ) ;
return 1 ;
}
static bool F_162 ( struct V_18 * V_19 , const char * V_10 , int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_3 . V_17 ; V_16 ++ ) {
struct V_4 * V_15 = F_24 ( & V_2 -> V_3 , V_16 ) ;
if ( ! strcmp ( V_15 -> V_10 , V_10 ) && V_15 -> V_119 == V_58 )
return true ;
}
return false ;
}
static void F_163 ( struct V_18 * V_19 , T_1 V_46 ,
char * V_10 , T_3 V_279 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_58 = 0 ;
F_164 ( V_19 , V_46 , & V_2 -> V_140 , V_10 , V_279 , & V_58 ) ;
F_165 ( V_10 , L_63 , V_279 ) ;
for (; F_162 ( V_19 , V_10 , V_58 ) ; V_58 ++ )
;
}
static int F_166 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_41 ) {
unsigned int V_280 = F_79 ( V_19 , V_46 ) ;
if ( ( V_280 & V_183 ) && ( V_280 & V_281 ) )
return 2 ;
}
return 1 ;
}
static int F_167 ( struct V_18 * V_19 , int V_48 ,
T_1 * V_49 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
T_1 V_46 = V_49 [ V_16 ] ;
if ( V_46 == V_2 -> V_265 )
continue;
if ( F_166 ( V_19 , V_46 ) > 1 ) {
struct V_4 * V_12 ;
char V_10 [ V_124 ] ;
F_163 ( V_19 , V_46 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 ,
& V_282 ) ;
if ( ! V_12 )
return - V_125 ;
V_12 -> V_122 = V_46 ;
}
}
return 0 ;
}
static unsigned int F_168 ( struct V_18 * V_19 , T_1 V_46 )
{
unsigned int V_280 ;
V_280 = F_79 ( V_19 , V_46 ) ;
V_280 = ( V_280 & V_283 ) >> V_284 ;
V_280 &= ~ ( V_285 | V_286 ) ;
return V_280 ;
}
static int F_169 ( unsigned int V_287 , unsigned int V_288 )
{
unsigned int V_16 , V_88 = 0 ;
for ( V_16 = 0 ; V_16 < V_289 ; V_16 ++ ) {
if ( V_287 & ( 1 << V_16 ) ) {
if ( V_88 == V_288 )
return V_16 ;
V_88 ++ ;
}
}
return 0 ;
}
static int F_170 ( unsigned int V_287 , unsigned int V_58 )
{
unsigned int V_16 , V_88 = 0 ;
for ( V_16 = 0 ; V_16 < V_289 ; V_16 ++ ) {
if ( V_16 == V_58 )
return V_88 ;
if ( V_287 & ( 1 << V_16 ) )
V_88 ++ ;
}
return 0 ;
}
static int F_171 ( struct V_129 * V_130 ,
struct V_231 * V_232 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
T_1 V_50 = V_130 -> V_122 ;
unsigned int V_287 = F_168 ( V_19 , V_50 ) ;
F_159 ( V_130 , V_232 , F_172 ( V_287 ) ,
V_290 ) ;
strcpy ( V_232 -> V_135 . V_233 . V_10 ,
V_290 [ F_169 ( V_287 , V_232 -> V_135 . V_233 . V_234 ) ] ) ;
return 0 ;
}
static int F_173 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
T_1 V_50 = V_130 -> V_122 ;
unsigned int V_287 = F_168 ( V_19 , V_50 ) ;
unsigned int V_58 ;
V_58 = F_16 ( V_19 , V_50 ) & V_291 ;
V_132 -> V_135 . V_233 . V_234 [ 0 ] = F_170 ( V_287 , V_58 ) ;
return 0 ;
}
static int F_174 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
T_1 V_50 = V_130 -> V_122 ;
unsigned int V_287 = F_168 ( V_19 , V_50 ) ;
unsigned int V_20 , V_58 ;
V_20 = F_16 ( V_19 , V_50 ) ;
V_58 = F_170 ( V_287 , V_20 & V_291 ) ;
if ( V_58 == V_132 -> V_135 . V_233 . V_234 [ 0 ] )
return 0 ;
V_20 &= ~ V_291 ;
V_20 |= F_169 ( V_287 , V_132 -> V_135 . V_233 . V_234 [ 0 ] ) ;
F_155 ( V_19 , V_50 , V_20 ) ;
return 1 ;
}
static int F_175 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_292 = 0 ;
if ( V_2 -> V_41 )
V_292 = F_172 ( F_168 ( V_19 , V_46 ) ) ;
return V_292 ? V_292 : 1 ;
}
static int F_176 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
char V_10 [ V_124 ] ;
unsigned int V_181 ;
if ( V_46 == V_2 -> V_265 )
return 0 ;
V_181 = F_109 ( V_19 , V_46 ) ;
if ( F_157 ( V_181 ) == V_274 )
return 0 ;
if ( F_175 ( V_19 , V_46 ) <= 1 )
return 0 ;
F_163 ( V_19 , V_46 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 , & V_293 ) ;
if ( ! V_12 )
return - V_125 ;
V_12 -> V_122 = V_46 ;
return 0 ;
}
static int F_177 ( struct V_129 * V_130 ,
struct V_231 * V_232 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
T_1 V_50 = V_130 -> V_122 ;
int V_294 = F_166 ( V_19 , V_50 ) ;
int V_295 = F_175 ( V_19 , V_50 ) ;
const char * V_296 = NULL ;
int V_58 ;
V_232 -> type = V_246 ;
V_232 -> V_247 = 1 ;
V_232 -> V_135 . V_233 . V_248 = V_294 + V_295 ;
if ( V_232 -> V_135 . V_233 . V_234 >= V_232 -> V_135 . V_233 . V_248 )
V_232 -> V_135 . V_233 . V_234 = V_232 -> V_135 . V_233 . V_248 - 1 ;
V_58 = V_232 -> V_135 . V_233 . V_234 ;
if ( V_58 < V_294 ) {
if ( V_294 > 1 )
V_296 = V_278 [ V_58 ] ;
else
V_296 = L_64 ;
} else {
V_58 -= V_294 ;
if ( V_295 > 1 ) {
unsigned int V_287 = F_168 ( V_19 , V_50 ) ;
V_296 = V_290 [ F_169 ( V_287 , V_58 ) ] ;
} else
V_296 = L_65 ;
}
strcpy ( V_232 -> V_135 . V_233 . V_10 , V_296 ) ;
return 0 ;
}
static int F_178 ( struct V_18 * V_19 , T_1 V_50 )
{
int V_294 = F_166 ( V_19 , V_50 ) ;
int V_295 = F_175 ( V_19 , V_50 ) ;
unsigned int V_20 = F_16 ( V_19 , V_50 ) ;
int V_58 = 0 ;
if ( V_20 & V_228 ) {
if ( V_294 > 1 && V_20 == V_227 )
V_58 = 1 ;
} else if ( V_20 & V_268 ) {
V_58 = V_294 ;
if ( V_295 > 1 ) {
unsigned int V_287 = F_168 ( V_19 , V_50 ) ;
V_20 &= V_291 ;
V_58 += F_170 ( V_287 , V_20 ) ;
}
}
return V_58 ;
}
static int F_179 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
T_1 V_50 = V_130 -> V_122 ;
V_132 -> V_135 . V_233 . V_234 [ 0 ] =
F_178 ( V_19 , V_50 ) ;
return 0 ;
}
static int F_180 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
T_1 V_50 = V_130 -> V_122 ;
int V_294 = F_166 ( V_19 , V_50 ) ;
int V_295 = F_175 ( V_19 , V_50 ) ;
unsigned int V_20 , V_297 , V_58 ;
V_297 = F_178 ( V_19 , V_50 ) ;
V_58 = V_132 -> V_135 . V_233 . V_234 [ 0 ] ;
if ( V_297 == V_58 )
return 0 ;
if ( V_58 < V_294 ) {
if ( V_294 > 1 )
V_20 = V_58 ? V_227 : V_228 ;
else
V_20 = V_227 ;
} else {
V_58 -= V_294 ;
if ( V_295 > 1 ) {
unsigned int V_287 = F_168 ( V_19 , V_50 ) ;
V_20 = F_16 ( V_19 , V_50 ) ;
V_20 &= ~ ( V_291 | V_227 ) ;
V_20 |= F_169 ( V_287 , V_58 ) | V_268 ;
} else
V_20 = F_154 ( V_19 , V_50 ) | V_268 ;
}
F_155 ( V_19 , V_50 , V_20 ) ;
F_138 ( V_19 , NULL ) ;
return 1 ;
}
static int F_181 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
V_12 = F_4 ( V_2 , L_66 ,
& V_298 ) ;
if ( ! V_12 )
return - V_125 ;
V_12 -> V_122 = V_46 ;
V_2 -> V_273 = 1 ;
return 0 ;
}
static int F_182 ( struct V_1 * V_2 , T_1 V_299 , int V_58 )
{
struct V_8 * V_14 ;
V_14 = F_5 ( & V_2 -> V_7 ) ;
if ( ! V_14 )
return - V_125 ;
V_14 -> V_50 = V_299 ;
V_14 -> V_61 = V_83 ;
V_14 -> V_58 = V_58 ;
V_2 -> V_300 . V_301 = V_2 -> V_7 . V_14 ;
return 0 ;
}
static bool F_183 ( struct V_18 * V_19 , T_1 V_302 ,
T_1 V_46 , unsigned int * V_303 ,
unsigned int * V_304 )
{
int V_58 , V_305 ;
const T_1 * V_14 ;
T_1 V_50 ;
V_58 = F_30 ( V_19 , V_302 , V_46 , true ) ;
if ( V_58 < 0 )
return false ;
* V_303 = * V_304 = 0 ;
if ( F_52 ( V_19 , V_302 , V_83 ) )
* V_303 = F_33 ( V_302 , 3 , V_58 , V_83 ) ;
if ( F_50 ( V_19 , V_302 , V_83 ) )
* V_304 = F_33 ( V_302 , 3 , V_58 , V_83 ) ;
if ( * V_303 && * V_304 )
return true ;
V_305 = F_38 ( V_19 , V_302 , & V_14 ) ;
if ( V_305 < V_58 )
return false ;
V_50 = V_14 [ V_58 ] ;
if ( ! * V_303 && F_52 ( V_19 , V_50 , V_82 ) &&
! F_32 ( V_19 , V_50 , V_82 , 0 , V_101 ) )
* V_303 = F_33 ( V_50 , 3 , 0 , V_82 ) ;
if ( ! * V_304 && F_50 ( V_19 , V_50 , V_82 ) &&
! F_32 ( V_19 , V_50 , V_82 , 0 , V_100 ) )
* V_304 = F_33 ( V_50 , 3 , 0 , V_82 ) ;
return * V_303 || * V_304 ;
}
static int F_184 ( struct V_18 * V_19 , int V_306 ,
T_1 V_46 , const char * V_307 , int V_308 ,
T_1 V_302 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_52 ;
unsigned int V_303 , V_304 ;
int V_198 , V_58 ;
if ( ! F_183 ( V_19 , V_302 , V_46 , & V_303 , & V_304 ) )
return 0 ;
V_52 = F_42 ( V_19 , V_46 , V_302 , 0 ) ;
if ( ! V_52 )
return - V_250 ;
F_34 ( V_19 , L_67 , V_52 ) ;
V_2 -> V_203 [ V_306 ] = F_26 ( V_19 , V_52 ) ;
V_58 = V_52 -> V_58 [ V_52 -> V_53 - 1 ] ;
if ( V_303 ) {
V_198 = F_85 ( V_2 , V_126 , V_307 , V_308 , V_303 ) ;
if ( V_198 < 0 )
return V_198 ;
V_52 -> V_60 [ V_101 ] = V_303 ;
}
if ( V_304 ) {
V_198 = F_90 ( V_2 , V_127 , V_307 , V_308 , V_304 ) ;
if ( V_198 < 0 )
return V_198 ;
V_52 -> V_60 [ V_100 ] = V_304 ;
}
V_52 -> V_89 = true ;
V_198 = F_182 ( V_2 , V_302 , V_58 ) ;
if ( V_198 < 0 )
return V_198 ;
if ( V_2 -> V_45 != V_2 -> V_105 &&
! V_2 -> V_309 ) {
V_52 = F_42 ( V_19 , V_2 -> V_45 ,
V_2 -> V_105 , 0 ) ;
if ( V_52 ) {
F_34 ( V_19 , L_68 , V_52 ) ;
V_52 -> V_89 = true ;
V_2 -> V_309 =
F_26 ( V_19 , V_52 ) ;
}
}
return 0 ;
}
static int F_185 ( struct V_18 * V_19 , T_1 V_50 )
{
unsigned int V_280 = F_79 ( V_19 , V_50 ) ;
return ( V_280 & V_276 ) != 0 ;
}
static int F_186 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_50 ;
T_1 * V_310 = V_2 -> V_310 ;
int V_311 = F_101 ( V_2 -> V_310 ) ;
int V_16 , V_51 = 0 ;
V_50 = V_19 -> V_215 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_216 ; V_16 ++ , V_50 ++ ) {
unsigned int V_85 = F_40 ( V_19 , V_50 ) ;
int type = F_39 ( V_85 ) ;
if ( type != V_69 || ( V_85 & V_78 ) )
continue;
V_310 [ V_51 ] = V_50 ;
if ( ++ V_51 >= V_311 )
break;
}
V_2 -> V_312 = V_51 ;
V_2 -> V_313 = V_51 ;
memcpy ( V_2 -> V_314 , V_2 -> V_310 , V_51 * sizeof( T_1 ) ) ;
return V_51 ;
}
static int F_187 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_315 * V_316 = & V_2 -> V_317 ;
unsigned int V_318 ;
int V_16 , V_88 , V_51 ;
V_51 = 0 ;
V_318 = 0 ;
for ( V_88 = 0 ; V_88 < V_2 -> V_312 ; V_88 ++ ) {
for ( V_16 = 0 ; V_16 < V_316 -> V_319 ; V_16 ++ ) {
if ( ! V_2 -> V_202 [ V_16 ] [ V_88 ] )
break;
}
if ( V_16 >= V_316 -> V_319 ) {
V_318 |= ( 1 << V_88 ) ;
V_51 ++ ;
}
}
if ( ! V_318 ) {
for ( V_16 = 0 ; V_16 < V_316 -> V_319 ; V_16 ++ ) {
for ( V_88 = 0 ; V_88 < V_2 -> V_312 ; V_88 ++ ) {
if ( V_2 -> V_202 [ V_16 ] [ V_88 ] ) {
V_2 -> V_320 [ V_16 ] = V_88 ;
break;
}
}
}
F_36 ( V_19 , L_69 ) ;
V_2 -> V_321 = 1 ;
} else if ( V_51 != V_2 -> V_312 ) {
V_51 = 0 ;
for ( V_88 = 0 ; V_88 < V_2 -> V_312 ; V_88 ++ ) {
if ( ! ( V_318 & ( 1 << V_88 ) ) )
continue;
if ( V_88 != V_51 ) {
V_2 -> V_310 [ V_51 ] = V_2 -> V_310 [ V_88 ] ;
for ( V_16 = 0 ; V_16 < V_316 -> V_319 ; V_16 ++ ) {
F_43 ( V_19 ,
V_2 -> V_202 [ V_16 ] [ V_51 ] ) ;
V_2 -> V_202 [ V_16 ] [ V_51 ] =
V_2 -> V_202 [ V_16 ] [ V_88 ] ;
}
}
V_51 ++ ;
}
V_2 -> V_312 = V_51 ;
}
if ( V_316 -> V_319 == 1 ||
( V_316 -> V_319 == 2 && V_2 -> V_43 ) ) {
F_36 ( V_19 , L_70 ) ;
V_2 -> V_312 = 1 ;
}
if ( ! V_2 -> V_321 && V_2 -> V_37 )
V_2 -> V_312 = 1 ;
return 0 ;
}
static int F_188 ( struct V_18 * V_19 , T_1 V_46 ,
int V_322 , int V_323 ,
const char * V_324 , int V_325 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_315 * V_316 = & V_2 -> V_317 ;
int V_326 = V_316 -> V_319 ;
bool V_327 = false ;
int V_328 ;
for ( V_328 = 0 ; V_328 < V_323 ; V_328 ++ ) {
struct V_6 * V_52 ;
T_1 V_329 = V_2 -> V_310 [ V_328 ] ;
if ( ! F_29 ( V_19 , V_46 , V_329 ) )
continue;
V_52 = F_42 ( V_19 , V_46 , V_329 , V_325 ) ;
if ( ! V_52 )
continue;
F_34 ( V_19 , L_71 , V_52 ) ;
V_2 -> V_202 [ V_326 ] [ V_328 ] =
F_26 ( V_19 , V_52 ) ;
if ( ! V_327 ) {
if ( V_2 -> V_265 == V_46 )
V_2 -> V_267 = V_316 -> V_319 ;
V_2 -> V_330 [ V_316 -> V_319 ] = V_46 ;
F_189 ( V_19 , V_316 , V_324 , V_322 , NULL ) ;
V_327 = true ;
if ( V_2 -> V_321 )
V_2 -> V_320 [ V_326 ] = V_328 ;
}
}
return 0 ;
}
static int F_190 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_138 * V_139 = & V_2 -> V_140 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_139 -> V_187 ; V_16 ++ ) {
T_1 V_46 = V_139 -> V_188 [ V_16 ] . V_46 ;
const char * V_324 ;
int V_172 , V_58 ;
if ( ! F_185 ( V_19 , V_46 ) )
continue;
V_324 = F_191 ( V_19 , V_139 , V_16 ) ;
V_58 = 0 ;
for ( V_172 = V_16 - 1 ; V_172 >= 0 ; V_172 -- ) {
if ( V_2 -> V_331 [ V_172 ] &&
! strcmp ( V_2 -> V_331 [ V_172 ] , V_324 ) ) {
V_58 = V_2 -> V_332 [ V_172 ] + 1 ;
break;
}
}
V_2 -> V_331 [ V_16 ] = V_324 ;
V_2 -> V_332 [ V_16 ] = V_58 ;
}
return 0 ;
}
static int F_192 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_138 * V_139 = & V_2 -> V_140 ;
T_1 V_333 = V_2 -> V_45 ;
int V_323 ;
int V_16 , V_198 ;
unsigned int V_20 ;
V_323 = F_186 ( V_19 ) ;
if ( V_323 < 0 )
return 0 ;
V_198 = F_190 ( V_19 ) ;
if ( V_198 < 0 )
return V_198 ;
for ( V_16 = 0 ; V_16 < V_139 -> V_187 ; V_16 ++ ) {
T_1 V_46 ;
V_46 = V_139 -> V_188 [ V_16 ] . V_46 ;
if ( ! F_185 ( V_19 , V_46 ) )
continue;
V_20 = V_268 ;
if ( V_139 -> V_188 [ V_16 ] . type == V_186 )
V_20 |= F_154 ( V_19 , V_46 ) ;
if ( V_46 != V_2 -> V_265 )
F_17 ( V_19 , V_46 , V_20 , false ) ;
if ( V_333 ) {
if ( F_29 ( V_19 , V_46 , V_333 ) ) {
V_198 = F_184 ( V_19 , V_16 , V_46 ,
V_2 -> V_331 [ V_16 ] ,
V_2 -> V_332 [ V_16 ] ,
V_333 ) ;
if ( V_198 < 0 )
return V_198 ;
}
}
V_198 = F_188 ( V_19 , V_46 , V_16 , V_323 ,
V_2 -> V_331 [ V_16 ] , - V_333 ) ;
if ( V_198 < 0 )
return V_198 ;
if ( V_2 -> V_41 ) {
V_198 = F_176 ( V_19 , V_46 ) ;
if ( V_198 < 0 )
return V_198 ;
}
}
if ( V_333 && V_2 -> V_40 == V_334 ) {
V_198 = F_188 ( V_19 , V_333 , V_335 , V_323 ,
L_72 , 0 ) ;
if ( V_198 < 0 )
return V_198 ;
else
V_2 -> V_31 = 1 ;
}
return 0 ;
}
static struct V_6 * F_193 ( struct V_18 * V_19 , int V_336 , int V_326 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_326 < 0 || V_326 >= V_337 ) {
F_102 () ;
return NULL ;
}
if ( V_2 -> V_321 )
V_336 = V_2 -> V_320 [ V_326 ] ;
if ( V_336 < 0 || V_336 >= V_275 ) {
F_102 () ;
return NULL ;
}
return F_27 ( V_19 , V_2 -> V_202 [ V_326 ] [ V_336 ] ) ;
}
static int F_194 ( struct V_129 * V_130 ,
struct V_231 * V_232 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
return F_195 ( & V_2 -> V_317 , V_232 ) ;
}
static int F_196 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_336 = F_197 ( V_130 , & V_132 -> V_338 ) ;
V_132 -> V_135 . V_233 . V_234 [ 0 ] = V_2 -> V_266 [ V_336 ] ;
return 0 ;
}
static int F_198 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
unsigned int V_336 = F_197 ( V_130 , & V_132 -> V_338 ) ;
return F_199 ( V_19 , V_336 ,
V_132 -> V_135 . V_233 . V_234 [ 0 ] ) ;
}
static int F_200 ( struct V_129 * V_130 ,
struct V_131 * V_132 ,
T_4 V_339 , int type )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_315 * V_316 ;
struct V_6 * V_52 ;
int V_16 , V_336 , V_198 = 0 ;
V_316 = & V_2 -> V_317 ;
V_336 = V_130 -> V_338 . V_119 ;
F_136 ( & V_19 -> V_340 ) ;
V_19 -> V_341 = 1 ;
for ( V_16 = 0 ; V_16 < V_316 -> V_319 ; V_16 ++ ) {
V_52 = F_193 ( V_19 , V_336 , V_16 ) ;
if ( ! V_52 || ! V_52 -> V_60 [ type ] )
continue;
V_130 -> V_122 = V_52 -> V_60 [ type ] ;
V_198 = V_339 ( V_130 , V_132 ) ;
if ( V_198 < 0 )
goto error;
}
error:
V_19 -> V_341 = 0 ;
F_139 ( & V_19 -> V_340 ) ;
F_201 ( V_19 ) ;
if ( V_198 >= 0 && V_2 -> V_342 )
V_2 -> V_342 ( V_19 , V_130 , V_132 ) ;
return V_198 ;
}
static int F_202 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
return F_200 ( V_130 , V_132 ,
V_343 ,
V_101 ) ;
}
static int F_203 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
return F_200 ( V_130 , V_132 ,
F_96 ,
V_100 ) ;
}
static int F_204 ( struct V_18 * V_19 , struct V_6 * V_52 )
{
T_1 V_50 ;
int V_16 , V_53 ;
V_52 -> V_60 [ V_101 ] = V_52 -> V_60 [ V_100 ] = 0 ;
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
if ( V_53 >= V_52 -> V_53 )
return - V_250 ;
V_16 = V_52 -> V_53 - V_53 - 1 ;
V_50 = V_52 -> V_52 [ V_16 ] ;
if ( ! V_52 -> V_60 [ V_101 ] ) {
if ( F_52 ( V_19 , V_50 , V_82 ) )
V_52 -> V_60 [ V_101 ] =
F_33 ( V_50 , 3 , 0 , V_82 ) ;
else if ( F_52 ( V_19 , V_50 , V_83 ) ) {
int V_58 = V_52 -> V_58 [ V_16 ] ;
if ( ! V_53 && V_19 -> V_29 )
V_58 = 0 ;
V_52 -> V_60 [ V_101 ] =
F_33 ( V_50 , 3 , V_58 , V_83 ) ;
}
}
if ( ! V_52 -> V_60 [ V_100 ] ) {
if ( F_50 ( V_19 , V_50 , V_82 ) )
V_52 -> V_60 [ V_100 ] =
F_33 ( V_50 , 3 , 0 , V_82 ) ;
else if ( F_50 ( V_19 , V_50 , V_83 ) ) {
int V_58 = V_52 -> V_58 [ V_16 ] ;
if ( ! V_53 && V_19 -> V_29 )
V_58 = 0 ;
V_52 -> V_60 [ V_100 ] =
F_33 ( V_50 , 3 , V_58 , V_83 ) ;
}
}
}
return 0 ;
}
static bool F_205 ( struct V_18 * V_19 , T_1 V_50 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
unsigned int V_20 ;
int V_16 ;
if ( ! V_2 -> V_38 )
return false ;
for ( V_16 = 0 ; V_16 < V_139 -> V_187 ; V_16 ++ ) {
if ( V_139 -> V_188 [ V_16 ] . V_46 != V_50 )
continue;
if ( V_139 -> V_188 [ V_16 ] . type != V_186 )
return false ;
V_20 = F_109 ( V_19 , V_50 ) ;
return F_157 ( V_20 ) == V_274 ;
}
return false ;
}
static int F_206 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_237 ;
V_237 = F_96 ( V_130 , V_132 ) ;
if ( V_237 < 0 )
return V_237 ;
if ( V_2 -> V_342 )
V_2 -> V_342 ( V_19 , V_130 , V_132 ) ;
return V_237 ;
}
static int F_207 ( struct V_18 * V_19 , const char * V_324 ,
int V_58 , bool V_344 , unsigned int V_345 ,
bool V_346 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
char V_347 [ V_124 ] ;
int type = V_344 ? V_127 : V_126 ;
const char * V_123 = V_344 ? L_73 : L_74 ;
unsigned int V_79 = V_346 ? 1 : 3 ;
struct V_4 * V_12 ;
if ( ! V_345 )
return 0 ;
if ( V_324 )
snprintf ( V_347 , sizeof( V_347 ) ,
L_75 , V_324 , V_123 ) ;
else
snprintf ( V_347 , sizeof( V_347 ) ,
L_76 , V_123 ) ;
V_12 = F_81 ( V_2 , type , V_347 , V_58 ,
F_46 ( V_345 , V_79 ) ) ;
if ( ! V_12 )
return - V_125 ;
if ( V_344 )
V_12 -> V_348 = F_206 ;
if ( ! V_346 )
return 0 ;
if ( V_324 )
snprintf ( V_347 , sizeof( V_347 ) ,
L_77 , V_324 , V_123 ) ;
else
snprintf ( V_347 , sizeof( V_347 ) ,
L_78 , V_123 ) ;
V_12 = F_81 ( V_2 , type , V_347 , V_58 ,
F_46 ( V_345 , 2 ) ) ;
if ( ! V_12 )
return - V_125 ;
if ( V_344 )
V_12 -> V_348 = F_206 ;
return 0 ;
}
static int F_208 ( struct V_18 * V_19 , int V_58 ,
unsigned int V_349 , unsigned int V_350 ,
bool V_346 )
{
int V_198 ;
V_198 = F_207 ( V_19 , NULL , V_58 , false , V_349 , V_346 ) ;
if ( V_198 < 0 )
return V_198 ;
V_198 = F_207 ( V_19 , NULL , V_58 , true , V_350 , V_346 ) ;
if ( V_198 < 0 )
return V_198 ;
return 0 ;
}
static int F_209 ( struct V_18 * V_19 , int V_58 ,
unsigned int V_349 , unsigned int V_350 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
if ( V_349 ) {
V_12 = F_4 ( V_2 , NULL , & V_351 ) ;
if ( ! V_12 )
return - V_125 ;
V_12 -> V_119 = V_58 ;
V_12 -> V_122 = V_349 ;
V_12 -> V_120 = V_121 ;
}
if ( V_350 ) {
V_12 = F_4 ( V_2 , NULL , & V_352 ) ;
if ( ! V_12 )
return - V_125 ;
V_12 -> V_119 = V_58 ;
V_12 -> V_122 = V_350 ;
V_12 -> V_120 = V_121 ;
}
return 0 ;
}
static unsigned int F_210 ( struct V_18 * V_19 , int V_58 , int type )
{
struct V_6 * V_52 ;
unsigned int V_345 ;
int V_16 ;
V_52 = F_193 ( V_19 , 0 , V_58 ) ;
if ( ! V_52 )
return 0 ;
V_345 = V_52 -> V_60 [ type ] ;
if ( ! V_345 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_58 - 1 ; V_16 ++ ) {
V_52 = F_193 ( V_19 , 0 , V_16 ) ;
if ( V_52 && V_52 -> V_60 [ type ] == V_345 )
return 0 ;
}
return V_345 ;
}
static int F_211 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_315 * V_316 = & V_2 -> V_317 ;
int V_16 , V_198 , type ;
for ( V_16 = 0 ; V_16 < V_316 -> V_319 ; V_16 ++ ) {
bool V_346 ;
int V_58 ;
V_58 = V_316 -> V_248 [ V_16 ] . V_119 ;
if ( V_58 >= V_2 -> V_140 . V_187 )
continue;
V_346 = F_205 ( V_19 , V_2 -> V_330 [ V_16 ] ) ;
for ( type = 0 ; type < 2 ; type ++ ) {
V_198 = F_207 ( V_19 ,
V_2 -> V_331 [ V_58 ] ,
V_2 -> V_332 [ V_58 ] ,
type ,
F_210 ( V_19 , V_16 , type ) ,
V_346 ) ;
if ( V_198 < 0 )
return V_198 ;
}
}
return 0 ;
}
static int F_212 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_315 * V_316 = & V_2 -> V_317 ;
int V_16 , V_88 , V_51 , V_198 ;
if ( V_2 -> V_321 )
V_51 = 1 ;
else
V_51 = V_2 -> V_312 ;
if ( ! V_2 -> V_353 && V_316 -> V_319 > 1 ) {
struct V_4 * V_12 ;
const char * V_10 ;
V_10 = V_51 > 1 ? L_79 : L_80 ;
V_12 = F_4 ( V_2 , V_10 , & V_354 ) ;
if ( ! V_12 )
return - V_125 ;
V_12 -> V_247 = V_51 ;
}
for ( V_88 = 0 ; V_88 < V_51 ; V_88 ++ ) {
bool V_72 = false ;
bool V_37 = V_2 -> V_37 ;
bool V_346 = false ;
int V_355 , V_356 ;
V_355 = V_356 = 0 ;
for ( V_16 = 0 ; V_16 < V_316 -> V_319 ; V_16 ++ ) {
struct V_6 * V_52 ;
V_52 = F_193 ( V_19 , V_88 , V_16 ) ;
if ( ! V_52 )
continue;
F_204 ( V_19 , V_52 ) ;
if ( ! V_355 )
V_355 = V_52 -> V_60 [ V_101 ] ;
else if ( V_355 != V_52 -> V_60 [ V_101 ] ) {
V_72 = true ;
if ( ! F_47 ( V_19 , V_355 ,
V_52 -> V_60 [ V_101 ] , V_83 ) )
V_37 = true ;
}
if ( ! V_356 )
V_356 = V_52 -> V_60 [ V_100 ] ;
else if ( V_356 != V_52 -> V_60 [ V_100 ] ) {
V_72 = true ;
if ( ! F_47 ( V_19 , V_356 ,
V_52 -> V_60 [ V_100 ] , V_83 ) )
V_37 = true ;
}
if ( F_205 ( V_19 , V_2 -> V_330 [ V_16 ] ) )
V_346 = true ;
}
if ( ! V_72 )
V_198 = F_208 ( V_19 , V_88 , V_355 , V_356 ,
V_346 ) ;
else if ( ! V_37 && ! V_346 )
V_198 = F_209 ( V_19 , V_88 , V_355 , V_356 ) ;
else
V_198 = F_211 ( V_19 ) ;
if ( V_198 < 0 )
return V_198 ;
}
return 0 ;
}
static bool F_213 ( struct V_18 * V_19 , T_1 V_50 ,
int V_61 , int V_58 )
{
unsigned int V_357 ;
if ( ! F_52 ( V_19 , V_50 , V_61 ) ||
F_32 ( V_19 , V_50 , V_61 , V_58 , V_101 ) ||
F_32 ( V_19 , V_50 , V_61 , V_58 , V_102 ) )
return false ;
V_357 = ( F_48 ( V_19 , V_50 , V_61 ) & V_358 )
>> V_359 ;
if ( V_357 < 0x20 )
return false ;
return true ;
}
static unsigned int F_214 ( struct V_18 * V_19 ,
struct V_6 * V_52 )
{
unsigned int V_20 = 0 ;
T_1 V_50 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
if ( V_53 >= V_52 -> V_53 - 1 )
break;
V_50 = V_52 -> V_52 [ V_53 ] ;
if ( V_53 && F_213 ( V_19 , V_50 , V_82 , 0 ) ) {
V_20 = F_33 ( V_50 , 3 , 0 , V_82 ) ;
break;
} else if ( F_213 ( V_19 , V_50 , V_83 ,
V_52 -> V_58 [ V_53 ] ) ) {
V_20 = F_33 ( V_50 , 3 , V_52 -> V_58 [ V_53 ] ,
V_83 ) ;
break;
}
}
return V_20 ;
}
static int F_215 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
struct V_315 * V_316 = & V_2 -> V_317 ;
int V_16 ;
if ( ! V_2 -> V_312 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_316 -> V_319 ; V_16 ++ ) {
struct V_6 * V_52 ;
unsigned int V_20 ;
int V_58 ;
char V_360 [ V_124 ] ;
V_58 = V_316 -> V_248 [ V_16 ] . V_119 ;
if ( V_58 >= V_316 -> V_319 )
continue;
if ( V_139 -> V_188 [ V_58 ] . type > V_185 )
continue;
V_52 = F_193 ( V_19 , 0 , V_16 ) ;
if ( ! V_52 )
continue;
V_20 = F_214 ( V_19 , V_52 ) ;
if ( ! V_20 )
continue;
snprintf ( V_360 , sizeof( V_360 ) ,
L_81 , V_2 -> V_331 [ V_58 ] ) ;
if ( ! F_81 ( V_2 , V_126 , V_360 ,
V_2 -> V_332 [ V_58 ] , V_20 ) )
return - V_125 ;
V_52 -> V_60 [ V_102 ] = V_20 ;
}
return 0 ;
}
static void F_216 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_52 ;
int V_16 , V_51 ;
T_1 V_361 , V_46 ;
V_51 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_140 . V_362 ; V_16 ++ ) {
V_46 = V_2 -> V_140 . V_363 [ V_16 ] ;
V_361 = F_45 ( V_19 , V_46 , true ) ;
if ( ! V_361 )
continue;
V_52 = F_42 ( V_19 , V_361 , V_46 , 0 ) ;
if ( ! V_52 )
continue;
F_34 ( V_19 , L_82 , V_52 ) ;
V_52 -> V_89 = true ;
V_2 -> V_201 [ V_16 ] = F_26 ( V_19 , V_52 ) ;
F_17 ( V_19 , V_46 , V_228 , false ) ;
if ( ! V_51 ) {
V_2 -> V_147 . V_364 = V_361 ;
V_2 -> V_365 = V_2 -> V_140 . V_365 [ 0 ] ;
} else {
V_2 -> V_147 . V_366 = V_2 -> V_366 ;
if ( V_51 >= F_101 ( V_2 -> V_366 ) - 1 )
break;
V_2 -> V_366 [ V_51 - 1 ] = V_361 ;
}
V_51 ++ ;
}
if ( V_2 -> V_140 . V_367 ) {
V_46 = V_2 -> V_140 . V_367 ;
V_361 = V_19 -> V_215 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_216 ; V_16 ++ , V_361 ++ ) {
unsigned int V_97 = F_40 ( V_19 , V_361 ) ;
if ( F_39 ( V_97 ) != V_69 )
continue;
if ( ! ( V_97 & V_78 ) )
continue;
V_52 = F_42 ( V_19 , V_46 , V_361 , 0 ) ;
if ( V_52 ) {
F_34 ( V_19 , L_83 , V_52 ) ;
V_52 -> V_89 = true ;
V_2 -> V_368 = V_361 ;
V_2 -> V_204 = F_26 ( V_19 , V_52 ) ;
F_17 ( V_19 , V_46 , V_268 , false ) ;
break;
}
}
}
}
static int F_199 ( struct V_18 * V_19 , unsigned int V_336 ,
unsigned int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_315 * V_316 ;
struct V_6 * V_369 , * V_52 ;
V_316 = & V_2 -> V_317 ;
if ( ! V_316 -> V_319 )
return 0 ;
if ( V_58 >= V_316 -> V_319 )
V_58 = V_316 -> V_319 - 1 ;
if ( V_2 -> V_266 [ V_336 ] == V_58 )
return 0 ;
V_369 = F_193 ( V_19 , V_336 , V_2 -> V_266 [ V_336 ] ) ;
if ( ! V_369 )
return 0 ;
if ( V_369 -> V_89 )
F_70 ( V_19 , V_369 , false , false ) ;
V_2 -> V_266 [ V_336 ] = V_58 ;
if ( V_2 -> V_43 )
F_153 ( V_19 , V_336 , false ) ;
if ( V_2 -> V_321 )
F_217 ( V_19 , V_58 ) ;
V_52 = F_193 ( V_19 , V_336 , V_58 ) ;
if ( ! V_52 )
return 0 ;
if ( V_52 -> V_89 )
return 0 ;
F_70 ( V_19 , V_52 , true , false ) ;
if ( V_2 -> V_342 )
V_2 -> V_342 ( V_19 , NULL , NULL ) ;
F_74 ( V_19 , V_369 ) ;
return 1 ;
}
static bool F_218 ( struct V_18 * V_19 , int V_48 , T_1 * V_49 )
{
int V_16 ;
bool V_370 = false ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
T_1 V_50 = V_49 [ V_16 ] ;
if ( ! V_50 )
break;
if ( F_16 ( V_19 , V_50 ) & V_371 )
continue;
if ( F_219 ( V_19 , V_50 ) == V_372 )
V_370 = true ;
}
return V_370 ;
}
static void F_220 ( struct V_18 * V_19 , int V_48 , T_1 * V_49 ,
int * V_5 , bool V_373 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
T_1 V_50 = V_49 [ V_16 ] ;
unsigned int V_20 , V_297 ;
if ( ! V_50 )
break;
if ( V_2 -> V_33 ) {
struct V_6 * V_52 ;
T_1 V_374 ;
V_52 = F_27 ( V_19 , V_5 [ V_16 ] ) ;
if ( ! V_52 )
continue;
V_374 = F_82 ( V_52 -> V_60 [ V_100 ] ) ;
if ( ! V_374 )
continue;
if ( V_373 )
V_2 -> V_134 |= ( 1ULL << V_374 ) ;
else
V_2 -> V_134 &= ~ ( 1ULL << V_374 ) ;
F_78 ( V_19 , V_50 , ! V_373 ) ;
continue;
}
V_297 = F_16 ( V_19 , V_50 ) ;
if ( V_297 & V_268 )
continue;
if ( V_2 -> V_375 )
V_20 = V_297 & ~ V_227 ;
else
V_20 = 0 ;
if ( ! V_373 )
V_20 |= V_297 ;
F_15 ( V_19 , V_50 , V_20 ) ;
F_78 ( V_19 , V_50 , ! V_373 ) ;
}
}
void F_221 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int * V_5 ;
int V_376 ;
if ( V_2 -> V_140 . V_152 == V_155 )
V_5 = V_2 -> V_192 ;
else
V_5 = V_2 -> V_154 ;
F_220 ( V_19 , F_101 ( V_2 -> V_140 . V_207 ) ,
V_2 -> V_140 . V_207 , V_5 , V_2 -> V_377 ) ;
if ( ! V_2 -> V_378 )
V_376 = 0 ;
else
V_376 = V_2 -> V_379 | V_2 -> V_380 ;
V_376 |= V_2 -> V_377 ;
V_2 -> V_381 = V_376 ;
if ( V_2 -> V_140 . V_152 == V_153 )
V_5 = V_2 -> V_192 ;
else
V_5 = V_2 -> V_156 ;
F_220 ( V_19 , F_101 ( V_2 -> V_140 . V_208 ) ,
V_2 -> V_140 . V_208 , V_5 , V_376 ) ;
if ( V_2 -> V_140 . V_206 [ 0 ] == V_2 -> V_140 . V_207 [ 0 ] ||
V_2 -> V_140 . V_206 [ 0 ] == V_2 -> V_140 . V_208 [ 0 ] )
return;
if ( ! V_2 -> V_382 )
V_376 = 0 ;
else
V_376 = V_2 -> V_379 ;
V_376 |= V_2 -> V_377 ;
V_2 -> V_383 = V_376 ;
V_5 = V_2 -> V_192 ;
F_220 ( V_19 , F_101 ( V_2 -> V_140 . V_206 ) ,
V_2 -> V_140 . V_206 , V_5 , V_376 ) ;
}
static void F_222 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_384 )
V_2 -> V_384 ( V_19 ) ;
else
F_221 ( V_19 ) ;
if ( V_2 -> V_33 && ! V_19 -> V_385 -> V_386 )
F_223 ( V_2 -> V_145 . V_387 , false ) ;
}
void F_224 ( struct V_18 * V_19 ,
struct V_388 * V_389 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 * V_49 = V_2 -> V_140 . V_207 ;
int V_48 = F_101 ( V_2 -> V_140 . V_207 ) ;
if ( V_2 -> V_235 ) {
V_49 ++ ;
V_48 -- ;
}
V_2 -> V_379 = F_218 ( V_19 , V_48 , V_49 ) ;
if ( ! V_2 -> V_390 || ( ! V_2 -> V_378 && ! V_2 -> V_382 ) )
return;
F_222 ( V_19 ) ;
}
void F_225 ( struct V_18 * V_19 ,
struct V_388 * V_389 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_140 . V_152 == V_153 )
return;
if ( V_2 -> V_140 . V_206 [ 0 ] == V_2 -> V_140 . V_207 [ 0 ] )
return;
V_2 -> V_380 =
F_218 ( V_19 , F_101 ( V_2 -> V_140 . V_206 ) ,
V_2 -> V_140 . V_206 ) ;
if ( ! V_2 -> V_378 || ! V_2 -> V_391 )
return;
F_222 ( V_19 ) ;
}
void F_226 ( struct V_18 * V_19 ,
struct V_388 * V_389 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
if ( ! V_2 -> V_353 )
return;
for ( V_16 = V_2 -> V_392 - 1 ; V_16 > 0 ; V_16 -- ) {
T_1 V_46 = V_2 -> V_393 [ V_16 ] . V_46 ;
if ( F_16 ( V_19 , V_46 ) & V_394 )
continue;
if ( F_219 ( V_19 , V_46 ) == V_372 ) {
F_199 ( V_19 , 0 , V_2 -> V_393 [ V_16 ] . V_58 ) ;
return;
}
}
F_199 ( V_19 , 0 , V_2 -> V_393 [ 0 ] . V_58 ) ;
}
static void F_138 ( struct V_18 * V_19 ,
struct V_388 * V_389 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_395 )
V_2 -> V_395 ( V_19 , V_389 ) ;
else
F_224 ( V_19 , V_389 ) ;
}
static void F_227 ( struct V_18 * V_19 ,
struct V_388 * V_389 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_396 )
V_2 -> V_396 ( V_19 , V_389 ) ;
else
F_225 ( V_19 , V_389 ) ;
}
static void F_228 ( struct V_18 * V_19 ,
struct V_388 * V_389 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_397 )
V_2 -> V_397 ( V_19 , V_389 ) ;
else
F_226 ( V_19 , V_389 ) ;
}
static void F_146 ( struct V_18 * V_19 )
{
F_138 ( V_19 , NULL ) ;
F_227 ( V_19 , NULL ) ;
F_228 ( V_19 , NULL ) ;
}
static int F_229 ( struct V_129 * V_130 ,
struct V_231 * V_232 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_398 [] = {
L_84 , L_85 , L_86
} ;
if ( V_2 -> V_399 && V_2 -> V_400 )
return F_159 ( V_130 , V_232 , 3 , V_398 ) ;
return F_133 ( V_130 , V_232 ) ;
}
static int F_230 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = 0 ;
if ( V_2 -> V_378 )
V_20 ++ ;
if ( V_2 -> V_382 )
V_20 ++ ;
V_132 -> V_135 . V_233 . V_234 [ 0 ] = V_20 ;
return 0 ;
}
static int F_231 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_93 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
switch ( V_132 -> V_135 . V_233 . V_234 [ 0 ] ) {
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
return - V_250 ;
break;
case 2 :
if ( ! V_2 -> V_400 || ! V_2 -> V_399 )
return - V_250 ;
if ( V_2 -> V_378 && V_2 -> V_382 )
return 0 ;
V_2 -> V_378 = 1 ;
V_2 -> V_382 = 1 ;
break;
default:
return - V_250 ;
}
F_222 ( V_19 ) ;
return 1 ;
}
static int F_232 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! F_4 ( V_2 , NULL , & V_401 ) )
return - V_125 ;
return 0 ;
}
static int F_233 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
int V_370 = 0 ;
int V_16 , V_198 ;
if ( V_2 -> V_30 )
return 0 ;
if ( V_139 -> V_207 [ 0 ] )
V_370 ++ ;
if ( V_139 -> V_206 [ 0 ] )
V_370 ++ ;
if ( V_139 -> V_208 [ 0 ] )
V_370 ++ ;
if ( V_370 < 2 )
return 0 ;
if ( ! V_139 -> V_208 [ 0 ] &&
V_139 -> V_152 == V_153 ) {
memcpy ( V_139 -> V_208 , V_139 -> V_206 ,
sizeof( V_139 -> V_208 ) ) ;
V_139 -> V_144 = V_139 -> V_141 ;
}
if ( ! V_139 -> V_207 [ 0 ] &&
V_139 -> V_152 == V_155 ) {
memcpy ( V_139 -> V_207 , V_139 -> V_206 ,
sizeof( V_139 -> V_207 ) ) ;
V_139 -> V_143 = V_139 -> V_141 ;
}
for ( V_16 = 0 ; V_16 < V_139 -> V_143 ; V_16 ++ ) {
T_1 V_50 = V_139 -> V_207 [ V_16 ] ;
if ( ! F_234 ( V_19 , V_50 ) )
continue;
F_36 ( V_19 , L_87 , V_50 ) ;
F_235 ( V_19 , V_50 ,
F_138 ) ;
V_2 -> V_390 = 1 ;
}
if ( V_139 -> V_152 == V_157 && V_139 -> V_141 ) {
if ( V_139 -> V_144 )
for ( V_16 = 0 ; V_16 < V_139 -> V_141 ; V_16 ++ ) {
T_1 V_50 = V_139 -> V_206 [ V_16 ] ;
if ( ! F_234 ( V_19 , V_50 ) )
continue;
F_36 ( V_19 , L_88 , V_50 ) ;
F_235 ( V_19 , V_50 ,
F_227 ) ;
V_2 -> V_391 = 1 ;
}
V_2 -> V_400 = V_2 -> V_390 ;
}
V_2 -> V_399 = V_139 -> V_144 &&
( V_2 -> V_390 || V_2 -> V_391 ) ;
V_2 -> V_382 = V_2 -> V_400 ;
V_2 -> V_378 = V_2 -> V_399 ;
if ( V_2 -> V_399 || V_2 -> V_400 ) {
V_198 = F_232 ( V_19 ) ;
if ( V_198 < 0 )
return V_198 ;
}
return 0 ;
}
static bool F_236 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_315 * V_316 ;
int V_16 ;
V_316 = & V_2 -> V_317 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_392 ; V_16 ++ ) {
V_2 -> V_393 [ V_16 ] . V_58 =
F_21 ( V_2 -> V_393 [ V_16 ] . V_46 ,
V_2 -> V_330 , V_316 -> V_319 ) ;
if ( V_2 -> V_393 [ V_16 ] . V_58 < 0 )
return false ;
}
for ( V_16 = 1 ; V_16 < V_2 -> V_392 ; V_16 ++ )
F_235 ( V_19 ,
V_2 -> V_393 [ V_16 ] . V_46 ,
F_228 ) ;
return true ;
}
static int F_237 ( const void * V_402 , const void * V_403 )
{
const struct V_404 * V_405 = V_402 ;
const struct V_404 * V_406 = V_403 ;
return ( int ) ( V_405 -> V_407 - V_406 -> V_407 ) ;
}
static int F_238 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
unsigned int V_408 ;
int V_16 , V_48 ;
if ( V_2 -> V_31 )
return 0 ;
V_408 = 0 ;
V_48 = 0 ;
for ( V_16 = 0 ; V_16 < V_139 -> V_187 ; V_16 ++ ) {
T_1 V_50 = V_139 -> V_188 [ V_16 ] . V_46 ;
unsigned int V_407 ;
V_407 = F_109 ( V_19 , V_50 ) ;
V_407 = F_157 ( V_407 ) ;
if ( V_408 & ( 1 << V_407 ) )
return 0 ;
switch ( V_407 ) {
case V_274 :
if ( V_139 -> V_188 [ V_16 ] . type != V_186 )
return 0 ;
break;
case V_409 :
return 0 ;
default:
if ( V_139 -> V_188 [ V_16 ] . type > V_185 )
return 0 ;
if ( ! V_2 -> V_32 &&
V_139 -> V_188 [ V_16 ] . type != V_186 )
return 0 ;
if ( ! F_234 ( V_19 , V_50 ) )
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
F_239 ( V_2 -> V_393 , V_48 , sizeof( V_2 -> V_393 [ 0 ] ) ,
F_237 , NULL ) ;
if ( ! F_236 ( V_19 ) )
return 0 ;
V_2 -> V_353 = 1 ;
V_2 -> V_312 = 1 ;
V_2 -> V_266 [ 0 ] = V_2 -> V_393 [ 0 ] . V_58 ;
F_36 ( V_19 , L_89 ,
V_2 -> V_393 [ 0 ] . V_46 ,
V_2 -> V_393 [ 1 ] . V_46 ,
V_2 -> V_393 [ 2 ] . V_46 ) ;
return 0 ;
}
unsigned int F_240 ( struct V_18 * V_19 ,
T_1 V_50 ,
unsigned int V_411 )
{
if ( V_411 != V_106 || V_50 == V_19 -> V_412 )
return V_411 ;
if ( F_39 ( F_40 ( V_19 , V_50 ) ) >= V_413 )
return V_411 ;
if ( F_75 ( V_19 , V_50 ) )
return V_411 ;
return V_110 ;
}
static void F_241 ( struct V_18 * V_19 , T_1 V_299 )
{
int V_16 , V_51 ;
const T_1 * V_65 ;
bool V_414 ;
V_51 = F_38 ( V_19 , V_299 , & V_65 ) ;
V_414 = F_50 ( V_19 , V_299 , V_83 ) ;
for ( V_16 = 0 ; V_16 < V_51 ; V_16 ++ ) {
if ( V_414 )
F_63 ( V_19 , V_299 , V_83 , V_16 ,
0xff , V_96 ) ;
else if ( F_52 ( V_19 , V_65 [ V_16 ] , V_82 ) )
F_63 ( V_19 , V_65 [ V_16 ] , V_82 , 0 ,
0xff , V_96 ) ;
}
}
int F_242 ( struct V_18 * V_19 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_198 ;
F_11 ( V_19 ) ;
if ( V_2 -> V_45 && ! V_2 -> V_105 )
V_2 -> V_105 = V_2 -> V_45 ;
if ( V_139 != & V_2 -> V_140 ) {
V_2 -> V_140 = * V_139 ;
V_139 = & V_2 -> V_140 ;
}
if ( ! V_2 -> V_209 )
V_2 -> V_209 = & V_415 ;
if ( ! V_2 -> V_210 )
V_2 -> V_210 = & V_416 ;
F_122 ( V_19 ) ;
if ( ! V_139 -> V_141 ) {
if ( V_139 -> V_362 || V_139 -> V_367 ) {
V_2 -> V_147 . V_252 = 2 ;
V_2 -> V_417 = 1 ;
goto V_418;
}
if ( ! V_139 -> V_187 && ! V_139 -> V_367 )
return 0 ;
}
if ( ! V_2 -> V_35 &&
V_139 -> V_152 == V_153 &&
V_139 -> V_141 <= V_139 -> V_143 ) {
V_139 -> V_144 = V_139 -> V_141 ;
memcpy ( V_139 -> V_208 , V_139 -> V_206 ,
sizeof( V_139 -> V_208 ) ) ;
V_139 -> V_141 = V_139 -> V_143 ;
memcpy ( V_139 -> V_206 , V_139 -> V_207 , sizeof( V_139 -> V_207 ) ) ;
V_139 -> V_143 = 0 ;
memset ( V_139 -> V_207 , 0 , sizeof( V_139 -> V_207 ) ) ;
V_139 -> V_152 = V_155 ;
}
V_198 = F_124 ( V_19 ) ;
if ( V_198 < 0 )
return V_198 ;
V_198 = F_149 ( V_19 ) ;
if ( V_198 < 0 )
return V_198 ;
V_198 = F_127 ( V_19 , V_139 ) ;
if ( V_198 < 0 )
return V_198 ;
V_198 = F_130 ( V_19 ) ;
if ( V_198 < 0 )
return V_198 ;
V_198 = F_131 ( V_19 ) ;
if ( V_198 < 0 )
return V_198 ;
V_198 = F_140 ( V_19 ) ;
if ( V_198 < 0 )
return V_198 ;
V_198 = F_152 ( V_19 ) ;
if ( V_198 < 0 )
return V_198 ;
V_198 = F_156 ( V_19 ) ;
if ( V_198 < 0 )
return V_198 ;
V_198 = F_192 ( V_19 ) ;
if ( V_198 < 0 )
return V_198 ;
V_2 -> V_253 = V_2 -> V_211 ;
if ( V_139 -> V_152 != V_153 )
V_2 -> V_253 = F_148 ( V_2 -> V_253 ,
V_139 -> V_144 * 2 ) ;
if ( V_139 -> V_152 != V_155 )
V_2 -> V_253 = F_148 ( V_2 -> V_253 ,
V_139 -> V_143 * 2 ) ;
V_2 -> V_147 . V_252 = F_148 ( V_2 -> V_211 ,
V_2 -> V_253 ) ;
V_198 = F_233 ( V_19 ) ;
if ( V_198 < 0 )
return V_198 ;
V_198 = F_187 ( V_19 ) ;
if ( V_198 < 0 )
return V_198 ;
V_198 = F_238 ( V_19 ) ;
if ( V_198 < 0 )
return V_198 ;
if ( ! V_2 -> V_353 && V_2 -> V_45 &&
V_2 -> V_40 == V_419 &&
V_2 -> V_317 . V_319 > 1 ) {
V_198 = F_188 ( V_19 , V_2 -> V_45 ,
V_335 , V_2 -> V_313 ,
L_72 , 0 ) ;
if ( V_198 < 0 )
return V_198 ;
}
V_198 = F_212 ( V_19 ) ;
if ( V_198 < 0 )
return V_198 ;
V_198 = F_215 ( V_19 ) ;
if ( V_198 < 0 )
return V_198 ;
if ( V_2 -> V_265 &&
( V_2 -> V_353 || V_2 -> V_317 . V_319 == 1 ||
V_2 -> V_41 ) ) {
V_198 = F_181 ( V_19 , V_2 -> V_265 ) ;
if ( V_198 < 0 )
return V_198 ;
}
if ( V_2 -> V_41 ) {
if ( V_139 -> V_152 != V_153 ) {
V_198 = F_167 ( V_19 , V_139 -> V_141 ,
V_139 -> V_206 ) ;
if ( V_198 < 0 )
return V_198 ;
}
if ( V_139 -> V_152 != V_155 ) {
V_198 = F_167 ( V_19 , V_139 -> V_143 ,
V_139 -> V_207 ) ;
if ( V_198 < 0 )
return V_198 ;
}
}
if ( V_2 -> V_45 )
F_241 ( V_19 , V_2 -> V_45 ) ;
V_418:
F_216 ( V_19 ) ;
if ( V_2 -> V_42 )
V_19 -> V_420 = F_240 ;
if ( ! V_2 -> V_417 && V_2 -> V_421 ) {
V_198 = F_243 ( V_19 , V_2 -> V_421 ) ;
if ( V_198 < 0 )
return V_198 ;
}
return 1 ;
}
int F_244 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_198 ;
if ( V_2 -> V_3 . V_17 ) {
V_198 = F_245 ( V_19 , V_2 -> V_3 . V_14 ) ;
if ( V_198 < 0 )
return V_198 ;
}
if ( V_2 -> V_147 . V_364 ) {
V_198 = F_246 ( V_19 ,
V_2 -> V_147 . V_364 ,
V_2 -> V_147 . V_364 ,
V_2 -> V_422 [ 1 ] . V_423 ) ;
if ( V_198 < 0 )
return V_198 ;
if ( ! V_2 -> V_417 ) {
V_198 = F_247 ( V_19 ,
& V_2 -> V_147 ) ;
if ( V_198 < 0 )
return V_198 ;
V_2 -> V_147 . V_424 = 1 ;
}
}
if ( V_2 -> V_368 ) {
V_198 = F_248 ( V_19 , V_2 -> V_368 ) ;
if ( V_198 < 0 )
return V_198 ;
}
if ( ! V_2 -> V_417 &&
! F_249 ( V_19 , L_90 ) ) {
V_198 = F_250 ( V_19 , L_90 ,
V_2 -> V_224 , V_425 ,
L_91 ) ;
if ( V_198 < 0 )
return V_198 ;
}
if ( ! V_2 -> V_417 &&
! F_249 ( V_19 , L_92 ) ) {
V_198 = F_251 ( V_19 , L_92 ,
NULL , V_425 ,
L_93 ,
true , & V_2 -> V_145 . V_387 ) ;
if ( V_198 < 0 )
return V_198 ;
if ( V_2 -> V_145 . V_146 ) {
F_252 ( V_19 , & V_2 -> V_145 ,
V_2 -> V_426 ) ;
F_253 ( & V_2 -> V_145 ) ;
}
}
F_7 ( V_2 ) ;
V_198 = F_254 ( V_19 , & V_2 -> V_140 ) ;
if ( V_198 < 0 )
return V_198 ;
return 0 ;
}
static void F_255 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 ,
int V_431 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_432 )
V_2 -> V_432 ( V_428 , V_19 , V_430 , V_431 ) ;
}
static void F_256 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 ,
int V_431 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_433 )
V_2 -> V_433 ( V_428 , V_19 , V_430 , V_431 ) ;
}
static int F_257 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_198 ;
F_136 ( & V_2 -> V_9 ) ;
V_198 = F_258 ( V_19 ,
& V_2 -> V_147 , V_430 ,
V_428 ) ;
if ( ! V_198 ) {
V_2 -> V_238 |= 1 << V_434 ;
F_255 ( V_428 , V_19 , V_430 ,
V_435 ) ;
}
F_139 ( & V_2 -> V_9 ) ;
return V_198 ;
}
static int F_259 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
unsigned int V_436 ,
unsigned int V_437 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_198 ;
V_198 = F_260 ( V_19 , & V_2 -> V_147 ,
V_436 , V_437 , V_430 ) ;
if ( ! V_198 )
F_255 ( V_428 , V_19 , V_430 ,
V_438 ) ;
return V_198 ;
}
static int F_261 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_198 ;
V_198 = F_262 ( V_19 , & V_2 -> V_147 ) ;
if ( ! V_198 )
F_255 ( V_428 , V_19 , V_430 ,
V_439 ) ;
return V_198 ;
}
static int F_263 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_136 ( & V_2 -> V_9 ) ;
V_2 -> V_238 &= ~ ( 1 << V_434 ) ;
F_255 ( V_428 , V_19 , V_430 ,
V_440 ) ;
F_139 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_264 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
F_256 ( V_428 , V_19 , V_430 , V_435 ) ;
return 0 ;
}
static int F_265 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
unsigned int V_436 ,
unsigned int V_437 ,
struct V_429 * V_430 )
{
F_266 ( V_19 , V_428 -> V_50 , V_436 , 0 , V_437 ) ;
F_256 ( V_428 , V_19 , V_430 ,
V_438 ) ;
return 0 ;
}
static int F_267 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
F_268 ( V_19 , V_428 -> V_50 ) ;
F_256 ( V_428 , V_19 , V_430 ,
V_439 ) ;
return 0 ;
}
static int F_269 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
F_256 ( V_428 , V_19 , V_430 , V_440 ) ;
return 0 ;
}
static int F_270 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_198 = 0 ;
F_136 ( & V_2 -> V_9 ) ;
if ( ! V_2 -> V_235 )
V_198 = - V_239 ;
else
V_2 -> V_238 |= 1 << V_441 ;
F_255 ( V_428 , V_19 , V_430 ,
V_435 ) ;
F_139 ( & V_2 -> V_9 ) ;
return V_198 ;
}
static int F_271 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_136 ( & V_2 -> V_9 ) ;
V_2 -> V_238 &= ~ ( 1 << V_441 ) ;
F_255 ( V_428 , V_19 , V_430 ,
V_440 ) ;
F_139 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_272 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
unsigned int V_436 ,
unsigned int V_437 ,
struct V_429 * V_430 )
{
F_266 ( V_19 , V_428 -> V_50 , V_436 , 0 , V_437 ) ;
F_255 ( V_428 , V_19 , V_430 ,
V_438 ) ;
return 0 ;
}
static int F_273 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
F_268 ( V_19 , V_428 -> V_50 ) ;
F_255 ( V_428 , V_19 , V_430 ,
V_439 ) ;
return 0 ;
}
static int F_274 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_275 ( V_19 , & V_2 -> V_147 ) ;
}
static int F_276 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
unsigned int V_436 ,
unsigned int V_437 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_277 ( V_19 , & V_2 -> V_147 ,
V_436 , V_437 , V_430 ) ;
}
static int F_278 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_279 ( V_19 , & V_2 -> V_147 ) ;
}
static int F_280 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_281 ( V_19 , & V_2 -> V_147 ) ;
}
static int F_282 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
unsigned int V_436 ,
unsigned int V_437 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_266 ( V_19 , V_2 -> V_310 [ V_430 -> V_442 + 1 ] ,
V_436 , 0 , V_437 ) ;
F_256 ( V_428 , V_19 , V_430 ,
V_438 ) ;
return 0 ;
}
static int F_283 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_268 ( V_19 ,
V_2 -> V_310 [ V_430 -> V_442 + 1 ] ) ;
F_256 ( V_428 , V_19 , V_430 ,
V_439 ) ;
return 0 ;
}
static bool F_217 ( struct V_18 * V_19 , int V_443 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_444 = V_2 -> V_310 [ V_2 -> V_320 [ V_443 ] ] ;
if ( V_2 -> V_445 && V_2 -> V_445 != V_444 ) {
F_284 ( V_19 , V_2 -> V_445 , 1 ) ;
V_2 -> V_445 = V_444 ;
F_266 ( V_19 , V_444 ,
V_2 -> V_446 , 0 ,
V_2 -> V_447 ) ;
return true ;
}
return false ;
}
static int F_285 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
unsigned int V_436 ,
unsigned int V_437 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
V_2 -> V_445 = V_2 -> V_310 [ V_2 -> V_320 [ V_2 -> V_266 [ 0 ] ] ] ;
V_2 -> V_446 = V_436 ;
V_2 -> V_447 = V_437 ;
F_266 ( V_19 , V_2 -> V_445 , V_436 , 0 , V_437 ) ;
return 0 ;
}
static int F_286 ( struct V_427 * V_428 ,
struct V_18 * V_19 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_268 ( V_19 , V_2 -> V_445 ) ;
V_2 -> V_445 = 0 ;
return 0 ;
}
static void F_287 ( char * V_448 , T_3 V_449 , const char * V_123 ,
const char * V_450 )
{
char * V_451 ;
if ( * V_448 )
return;
F_288 ( V_448 , V_450 , V_449 ) ;
for ( V_451 = strchr ( V_448 , ' ' ) ; V_451 ; V_451 = strchr ( V_451 + 1 , ' ' ) ) {
if ( ! isalnum ( V_451 [ 1 ] ) ) {
* V_451 = 0 ;
break;
}
}
F_165 ( V_448 , V_123 , V_449 ) ;
}
int F_289 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_452 * V_453 = V_2 -> V_422 ;
const struct V_427 * V_451 ;
bool V_454 ;
V_19 -> V_455 = 1 ;
V_19 -> V_456 = V_453 ;
if ( V_2 -> V_417 )
goto V_457;
F_287 ( V_2 -> V_458 ,
sizeof( V_2 -> V_458 ) ,
L_94 , V_19 -> V_450 ) ;
V_453 -> V_10 = V_2 -> V_458 ;
if ( V_2 -> V_147 . V_148 > 0 ) {
V_451 = V_2 -> V_459 ;
if ( ! V_451 )
V_451 = & V_460 ;
V_453 -> V_461 [ V_462 ] = * V_451 ;
V_453 -> V_461 [ V_462 ] . V_50 = V_2 -> V_147 . V_199 [ 0 ] ;
V_453 -> V_461 [ V_462 ] . V_463 =
V_2 -> V_147 . V_252 ;
if ( V_2 -> V_140 . V_152 == V_153 &&
V_2 -> V_140 . V_141 == 2 )
V_453 -> V_461 [ V_462 ] . V_464 =
V_465 ;
}
if ( V_2 -> V_312 ) {
V_451 = V_2 -> V_466 ;
if ( ! V_451 ) {
if ( V_2 -> V_321 )
V_451 = & V_467 ;
else
V_451 = & V_468 ;
}
V_453 -> V_461 [ V_469 ] = * V_451 ;
V_453 -> V_461 [ V_469 ] . V_50 = V_2 -> V_310 [ 0 ] ;
}
V_457:
if ( V_2 -> V_147 . V_364 || V_2 -> V_368 ) {
F_287 ( V_2 -> V_470 ,
sizeof( V_2 -> V_470 ) ,
L_95 , V_19 -> V_450 ) ;
V_19 -> V_455 = 2 ;
V_19 -> V_366 = V_2 -> V_147 . V_366 ;
V_453 = V_2 -> V_422 + 1 ;
V_453 -> V_10 = V_2 -> V_470 ;
if ( V_2 -> V_365 )
V_453 -> V_423 = V_2 -> V_365 ;
else
V_453 -> V_423 = V_471 ;
if ( V_2 -> V_147 . V_364 ) {
V_451 = V_2 -> V_472 ;
if ( ! V_451 )
V_451 = & V_473 ;
V_453 -> V_461 [ V_462 ] = * V_451 ;
V_453 -> V_461 [ V_462 ] . V_50 = V_2 -> V_147 . V_364 ;
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
V_454 = ( V_2 -> V_312 > 1 ) &&
! V_2 -> V_321 && ! V_2 -> V_353 ;
if ( V_2 -> V_244 || V_454 ) {
F_287 ( V_2 -> V_476 ,
sizeof( V_2 -> V_476 ) ,
L_96 , V_19 -> V_450 ) ;
V_19 -> V_455 = 3 ;
V_453 = V_2 -> V_422 + 2 ;
V_453 -> V_10 = V_2 -> V_476 ;
if ( V_2 -> V_244 ) {
V_451 = V_2 -> V_477 ;
if ( ! V_451 )
V_451 = & V_478 ;
V_453 -> V_461 [ V_462 ] = * V_451 ;
V_453 -> V_461 [ V_462 ] . V_50 =
V_2 -> V_244 ;
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
V_2 -> V_310 [ 1 ] ;
V_453 -> V_461 [ V_469 ] . V_482 =
V_2 -> V_312 - 1 ;
} else {
V_453 -> V_461 [ V_469 ] =
V_479 ;
V_453 -> V_461 [ V_469 ] . V_50 = 0 ;
}
}
return 0 ;
}
static void F_290 ( struct V_18 * V_19 , int V_116 )
{
struct V_6 * V_52 ;
T_1 V_46 ;
V_52 = F_27 ( V_19 , V_116 ) ;
if ( ! V_52 || ! V_52 -> V_53 )
return;
V_46 = V_52 -> V_52 [ V_52 -> V_53 - 1 ] ;
F_14 ( V_19 , V_46 ) ;
F_70 ( V_19 , V_52 , V_52 -> V_89 ,
F_144 ( V_19 -> V_2 ) ) ;
F_78 ( V_19 , V_46 , V_52 -> V_89 ) ;
}
static void F_291 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_140 . V_141 ; V_16 ++ )
F_290 ( V_19 , V_2 -> V_192 [ V_16 ] ) ;
}
static void F_292 ( struct V_18 * V_19 , int V_168 , int * V_5 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_168 ; V_16 ++ )
F_290 ( V_19 , V_5 [ V_16 ] ) ;
}
static void F_293 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_140 . V_152 != V_155 )
F_292 ( V_19 , V_2 -> V_140 . V_143 , V_2 -> V_154 ) ;
if ( V_2 -> V_140 . V_152 != V_153 )
F_292 ( V_19 , V_2 -> V_140 . V_144 ,
V_2 -> V_156 ) ;
}
static void F_294 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_142 ; V_16 ++ ) {
T_1 V_46 = V_2 -> V_166 [ V_16 ] . V_46 ;
struct V_6 * V_52 ;
V_52 = F_143 ( V_19 , V_16 ) ;
if ( ! V_52 )
continue;
if ( ! V_2 -> V_166 [ V_16 ] . V_251 )
V_2 -> V_166 [ V_16 ] . V_251 =
F_16 ( V_19 , V_46 ) ;
F_70 ( V_19 , V_52 , V_52 -> V_89 ,
F_144 ( V_2 ) ) ;
}
}
static void F_295 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_242 )
return;
F_137 ( V_19 , V_2 -> V_243 , V_2 -> V_192 [ 0 ] ,
V_2 -> V_200 [ 0 ] ,
V_2 -> V_140 . V_152 ) ;
F_137 ( V_19 , V_2 -> V_243 , V_2 -> V_154 [ 0 ] ,
V_2 -> V_200 [ 1 ] ,
V_155 ) ;
F_137 ( V_19 , V_2 -> V_243 , V_2 -> V_156 [ 0 ] ,
V_2 -> V_200 [ 2 ] ,
V_153 ) ;
}
static void F_296 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_139 -> V_187 ; V_16 ++ ) {
T_1 V_50 = V_139 -> V_188 [ V_16 ] . V_46 ;
if ( F_185 ( V_19 , V_50 ) )
F_14 ( V_19 , V_50 ) ;
if ( V_2 -> V_45 ) {
F_80 ( V_19 , V_2 -> V_203 [ V_16 ] ) ;
F_80 ( V_19 , V_2 -> V_309 ) ;
}
}
}
static void F_297 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_315 * V_316 = & V_2 -> V_317 ;
struct V_6 * V_52 ;
int V_16 , V_328 , V_51 ;
if ( V_2 -> V_321 )
V_51 = 1 ;
else
V_51 = V_2 -> V_312 ;
for ( V_328 = 0 ; V_328 < V_51 ; V_328 ++ ) {
for ( V_16 = 0 ; V_16 < V_316 -> V_319 ; V_16 ++ ) {
V_52 = F_193 ( V_19 , V_328 , V_16 ) ;
if ( V_52 ) {
bool V_89 = V_52 -> V_89 ;
if ( V_16 == V_2 -> V_266 [ V_328 ] )
V_89 = true ;
F_70 ( V_19 , V_52 , V_89 , false ) ;
}
}
if ( V_2 -> V_43 )
F_153 ( V_19 , V_328 , true ) ;
}
if ( V_2 -> V_342 )
V_2 -> V_342 ( V_19 , NULL , NULL ) ;
}
static void F_298 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_46 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_140 . V_362 ; V_16 ++ )
F_290 ( V_19 , V_2 -> V_201 [ V_16 ] ) ;
V_46 = V_2 -> V_140 . V_367 ;
if ( V_46 ) {
F_14 ( V_19 , V_46 ) ;
F_80 ( V_19 , V_2 -> V_204 ) ;
}
}
static void F_299 ( struct V_18 * V_19 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_483 . V_17 ; V_16 ++ ) {
struct V_484 * V_46 = F_24 ( & V_19 -> V_483 , V_16 ) ;
T_1 V_50 = V_46 -> V_50 ;
if ( F_234 ( V_19 , V_50 ) &&
! F_300 ( V_19 , V_50 ) )
F_73 ( V_19 , V_50 , 0 ,
V_485 , 0 ) ;
}
}
int F_301 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_486 )
V_2 -> V_486 ( V_19 ) ;
F_302 ( V_19 ) ;
V_19 -> V_341 = 1 ;
F_291 ( V_19 ) ;
F_293 ( V_19 ) ;
F_294 ( V_19 ) ;
F_295 ( V_19 ) ;
F_296 ( V_19 ) ;
F_297 ( V_19 ) ;
F_298 ( V_19 ) ;
F_299 ( V_19 ) ;
F_146 ( V_19 ) ;
F_201 ( V_19 ) ;
if ( V_2 -> V_145 . V_387 && V_2 -> V_145 . V_146 )
F_253 ( & V_2 -> V_145 ) ;
F_303 ( V_19 , 0x01 ) ;
return 0 ;
}
void F_304 ( struct V_18 * V_19 )
{
F_305 ( V_19 , V_487 ) ;
F_10 ( V_19 -> V_2 ) ;
F_8 ( V_19 -> V_2 ) ;
V_19 -> V_2 = NULL ;
}
int F_306 ( struct V_18 * V_19 , T_1 V_50 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_307 ( V_19 , & V_2 -> V_300 , V_50 ) ;
}
int F_308 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_198 ;
V_2 = F_309 ( sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 )
return - V_125 ;
F_1 ( V_2 ) ;
V_19 -> V_2 = V_2 ;
V_198 = F_310 ( V_19 , & V_2 -> V_140 , NULL , 0 ) ;
if ( V_198 < 0 )
return V_198 ;
V_198 = F_242 ( V_19 , & V_2 -> V_140 ) ;
if ( V_198 < 0 )
goto error;
V_19 -> V_488 = V_489 ;
return 0 ;
error:
F_304 ( V_19 ) ;
return V_198 ;
}
