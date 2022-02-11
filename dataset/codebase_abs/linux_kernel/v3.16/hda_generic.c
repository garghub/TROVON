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
int V_16 ;
V_63 [ 0 ] = 0 ;
for ( V_16 = 0 ; V_16 < V_52 -> V_53 ; V_16 ++ ) {
char V_64 [ 4 ] ;
sprintf ( V_64 , L_28 , V_52 -> V_52 [ V_16 ] ) ;
F_35 ( V_63 , V_64 , sizeof( V_63 ) ) ;
}
F_36 ( V_19 , L_29 , V_62 , V_52 -> V_53 , V_63 ) ;
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
F_68 ( V_19 , V_46 , 0 ,
V_114 ,
V_91 ? 0x02 : 0x00 ) ;
}
static void F_75 ( struct V_18 * V_19 , int V_115 )
{
struct V_6 * V_52 = F_27 ( V_19 , V_115 ) ;
if ( V_52 )
F_65 ( V_19 , V_52 , V_52 -> V_90 , false ) ;
}
static struct V_4 *
F_76 ( struct V_1 * V_2 , int type , const char * V_10 ,
int V_116 , unsigned long V_20 )
{
struct V_4 * V_12 ;
V_12 = F_4 ( V_2 , V_10 , & V_117 [ type ] ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_118 = V_116 ;
if ( F_77 ( V_20 ) )
V_12 -> V_119 = V_120 ;
V_12 -> V_121 = V_20 ;
return V_12 ;
}
static int F_78 ( struct V_1 * V_2 , int type ,
const char * V_62 , const char * V_61 ,
const char * V_122 , int V_116 , unsigned long V_20 )
{
char V_10 [ V_123 ] ;
snprintf ( V_10 , sizeof( V_10 ) , L_30 , V_62 , V_61 , V_122 ) ;
if ( ! F_76 ( V_2 , type , V_10 , V_116 , V_20 ) )
return - V_124 ;
return 0 ;
}
static int F_79 ( struct V_18 * V_19 , const char * V_62 , int V_116 ,
unsigned int V_79 , struct V_6 * V_52 )
{
unsigned int V_20 ;
if ( ! V_52 )
return 0 ;
V_20 = V_52 -> V_60 [ V_100 ] ;
if ( ! V_20 )
return 0 ;
V_20 = F_46 ( V_20 , V_79 ) ;
return F_80 ( V_19 -> V_2 , V_125 , V_62 , V_116 , V_20 ) ;
}
static int F_81 ( struct V_18 * V_19 , struct V_6 * V_52 ,
int type )
{
int V_79 = 1 ;
if ( V_52 ) {
T_1 V_50 = F_77 ( V_52 -> V_60 [ type ] ) ;
if ( V_50 && ( F_40 ( V_19 , V_50 ) & V_126 ) )
V_79 = 3 ;
}
return V_79 ;
}
static int F_82 ( struct V_18 * V_19 , const char * V_62 , int V_116 ,
struct V_6 * V_52 )
{
int V_79 = F_81 ( V_19 , V_52 , V_100 ) ;
return F_79 ( V_19 , V_62 , V_116 , V_79 , V_52 ) ;
}
static int F_83 ( struct V_18 * V_19 , const char * V_62 , int V_116 ,
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
if ( F_84 ( V_20 ) == V_84 ) {
T_1 V_50 = F_77 ( V_20 ) ;
int V_51 = F_85 ( V_19 , V_50 ) ;
if ( V_51 > 1 ) {
type = V_128 ;
V_20 |= V_51 << 19 ;
}
}
return F_86 ( V_19 -> V_2 , type , V_62 , V_116 , V_20 ) ;
}
static int F_87 ( struct V_18 * V_19 , const char * V_62 ,
int V_116 , struct V_6 * V_52 )
{
int V_79 = F_81 ( V_19 , V_52 , V_99 ) ;
return F_83 ( V_19 , V_62 , V_116 , V_79 , V_52 ) ;
}
static void F_88 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_33 ) {
T_1 V_50 = F_90 ( V_130 ) ;
bool V_133 = ! ( ( V_2 -> V_134 >> V_50 ) & 1 ) ;
V_132 -> V_135 . integer . V_135 [ 0 ] &= V_133 ;
V_132 -> V_135 . integer . V_135 [ 1 ] &= V_133 ;
}
}
static int F_91 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
F_88 ( V_130 , V_132 ) ;
return F_92 ( V_130 , V_132 ) ;
}
static int F_93 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
F_88 ( V_130 , V_132 ) ;
return F_94 ( V_130 , V_132 ) ;
}
static bool F_95 ( struct V_18 * V_19 , int V_115 , int V_136 )
{
struct V_6 * V_52 = F_27 ( V_19 , V_115 ) ;
return V_52 && V_52 -> V_60 [ V_136 ] ;
}
static const char * F_96 ( struct V_18 * V_19 , int V_137 ,
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
! F_95 ( V_19 , V_2 -> V_154 [ 0 ] , V_136 ) )
break;
if ( V_139 -> V_141 == 1 )
return L_33 ;
if ( V_139 -> V_141 == 2 )
return V_137 ? L_34 : L_33 ;
break;
case V_155 :
if ( ! V_137 && V_139 -> V_144 &&
! F_95 ( V_19 , V_2 -> V_156 [ 0 ] , V_136 ) )
break;
if ( V_137 && V_2 -> V_142 )
break;
* V_118 = V_137 ;
return L_35 ;
}
if ( V_139 -> V_141 == 1 && ! V_2 -> V_142 )
return L_31 ;
if ( V_137 >= F_97 ( V_151 ) ) {
F_98 () ;
return L_31 ;
}
return V_151 [ V_137 ] ;
}
static int F_99 ( struct V_18 * V_19 , struct V_6 * V_52 )
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
static T_1 F_100 ( struct V_18 * V_19 , int V_58 )
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
static inline T_1 F_101 ( struct V_18 * V_19 ,
T_1 V_162 , T_1 V_46 )
{
return F_29 ( V_19 , V_162 , V_46 ) ? V_162 : 0 ;
}
static int F_102 ( struct V_18 * V_19 , int V_163 ,
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
V_157 += F_99 ( V_19 , V_52 ) ;
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
V_162 = F_101 ( V_19 , F_100 ( V_19 , V_16 ) , V_46 ) ;
if ( ! V_162 )
V_162 = F_101 ( V_19 , V_164 [ 0 ] , V_46 ) ;
if ( ! V_162 )
V_162 = F_101 ( V_19 , F_100 ( V_19 , V_16 ) , V_46 ) ;
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
V_157 += F_99 ( V_19 , V_52 ) ;
}
}
return V_157 ;
}
static T_1 F_103 ( struct V_18 * V_19 , T_1 V_46 )
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
static bool F_104 ( struct V_18 * V_19 ,
unsigned int V_175 , T_1 V_50 )
{
unsigned int V_176 , V_86 ;
V_176 = F_105 ( V_19 , V_50 ) ;
if ( F_106 ( V_176 ) != V_177 )
return false ;
if ( V_175 && F_107 ( V_176 ) != V_175 )
return false ;
V_86 = F_74 ( V_19 , V_50 ) ;
if ( ! ( V_86 & V_178 ) )
return false ;
return true ;
}
static int F_108 ( struct V_18 * V_19 , T_1 V_179 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
unsigned int V_176 = F_105 ( V_19 , V_179 ) ;
unsigned int V_175 = F_107 ( V_176 ) ;
int type , V_16 ;
int V_48 = 0 ;
for ( type = V_180 ; type >= V_181 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_139 -> V_182 ; V_16 ++ ) {
if ( V_139 -> V_183 [ V_16 ] . type != type )
continue;
if ( F_104 ( V_19 , V_175 ,
V_139 -> V_183 [ V_16 ] . V_46 ) )
V_48 ++ ;
}
}
return V_48 ;
}
static int F_109 ( struct V_18 * V_19 ,
T_1 V_179 ,
bool V_184 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
int type , V_16 , V_167 , V_48 , V_185 ;
unsigned int V_176 = F_105 ( V_19 , V_179 ) ;
unsigned int V_175 = F_107 ( V_176 ) ;
int V_157 = 0 ;
struct V_6 * V_52 ;
V_185 = V_2 -> V_142 ;
if ( V_185 >= 2 )
goto V_186;
V_48 = F_108 ( V_19 , V_179 ) ;
if ( V_48 < 2 )
goto V_186;
for ( type = V_180 ; type >= V_181 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_139 -> V_182 ; V_16 ++ ) {
T_1 V_50 = V_139 -> V_183 [ V_16 ] . V_46 ;
T_1 V_162 = 0 ;
if ( V_139 -> V_183 [ V_16 ] . type != type )
continue;
if ( ! F_104 ( V_19 , V_175 , V_50 ) )
continue;
for ( V_167 = 0 ; V_167 < V_2 -> V_142 ; V_167 ++ ) {
if ( V_50 == V_2 -> V_161 [ V_167 ] . V_46 )
break;
}
if ( V_167 < V_2 -> V_142 )
continue;
if ( V_184 )
V_162 = F_103 ( V_19 , V_50 ) ;
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
V_157 += F_99 ( V_19 , V_52 ) ;
}
return V_157 ;
}
static bool F_110 ( struct V_18 * V_19 , int V_189 ,
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
V_162 = F_103 ( V_19 , V_49 [ V_16 ] ) ;
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
static int F_111 ( struct V_18 * V_19 , int V_115 )
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
static bool F_112 ( struct V_18 * V_19 )
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
static void F_113 ( struct V_18 * V_19 , int V_163 ,
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
static int F_114 ( struct V_18 * V_19 ,
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
V_200 = F_110 ( V_19 , V_139 -> V_141 ,
V_139 -> V_201 ,
V_2 -> V_160 ,
V_2 -> V_187 ) ;
V_200 |= F_110 ( V_19 , V_139 -> V_143 ,
V_139 -> V_202 ,
V_2 -> V_147 . V_149 ,
V_2 -> V_154 ) ;
V_200 |= F_110 ( V_19 , V_139 -> V_144 ,
V_139 -> V_203 ,
V_2 -> V_147 . V_150 ,
V_2 -> V_156 ) ;
if ( ! V_2 -> V_36 &&
V_192 && V_139 -> V_141 == 1 &&
V_139 -> V_152 != V_153 ) {
V_193 = F_109 ( V_19 , V_139 -> V_201 [ 0 ] , true ) ;
if ( ! V_193 )
V_200 = true ;
}
} while ( V_200 );
}
V_157 += F_102 ( V_19 , V_139 -> V_141 , V_139 -> V_201 ,
V_2 -> V_160 , V_2 -> V_187 ,
V_2 -> V_204 ) ;
if ( ! V_2 -> V_36 && V_192 &&
V_139 -> V_141 == 1 && V_139 -> V_152 != V_153 ) {
V_193 = F_109 ( V_19 , V_139 -> V_201 [ 0 ] , false ) ;
if ( V_193 < 0 )
return V_193 ;
}
if ( V_139 -> V_152 != V_155 ) {
V_193 = F_102 ( V_19 , V_139 -> V_143 , V_139 -> V_202 ,
V_2 -> V_147 . V_149 ,
V_2 -> V_154 ,
V_2 -> V_205 ) ;
if ( V_193 < 0 )
return V_193 ;
V_157 += V_193 ;
}
if ( V_139 -> V_152 != V_153 ) {
V_193 = F_102 ( V_19 , V_139 -> V_144 ,
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
V_193 = F_109 ( V_19 , V_139 -> V_201 [ 0 ] , false ) ;
if ( V_193 < 0 )
return V_193 ;
V_157 += V_193 ;
}
if ( V_2 -> V_45 ) {
V_2 -> V_195 [ 0 ] =
F_111 ( V_19 , V_2 -> V_187 [ 0 ] ) ;
if ( V_139 -> V_152 != V_155 )
V_2 -> V_195 [ 1 ] =
F_111 ( V_19 , V_2 -> V_154 [ 0 ] ) ;
if ( V_139 -> V_152 != V_153 )
V_2 -> V_195 [ 2 ] =
F_111 ( V_19 , V_2 -> V_156 [ 0 ] ) ;
}
if ( ! V_2 -> V_36 &&
V_139 -> V_143 && V_139 -> V_152 == V_153 )
if ( F_108 ( V_19 , V_139 -> V_202 [ 0 ] ) >= 2 )
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
if ( V_2 -> V_39 && ! F_112 ( V_19 ) )
V_157 += V_208 ;
if ( V_139 -> V_152 != V_155 )
F_113 ( V_19 , V_139 -> V_143 ,
V_2 -> V_147 . V_149 ,
V_2 -> V_154 ) ;
if ( V_139 -> V_152 != V_153 )
F_113 ( V_19 , V_139 -> V_144 ,
V_2 -> V_147 . V_150 ,
V_2 -> V_156 ) ;
return V_157 ;
}
static inline void F_115 ( struct V_18 * V_19 ,
const char * V_62 , int V_58 )
{
struct V_6 * V_52 ;
V_52 = F_27 ( V_19 , V_58 ) ;
if ( V_52 )
F_34 ( V_19 , V_62 , V_52 ) ;
}
static void F_116 ( struct V_18 * V_19 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_209 [ 3 ] = { L_36 , L_37 , L_38 } ;
int V_16 ;
F_117 ( L_39 ,
V_139 -> V_201 [ 0 ] , V_139 -> V_201 [ 1 ] ,
V_139 -> V_201 [ 2 ] , V_139 -> V_201 [ 3 ] ,
V_2 -> V_147 . V_194 [ 0 ] ,
V_2 -> V_147 . V_194 [ 1 ] ,
V_2 -> V_147 . V_194 [ 2 ] ,
V_2 -> V_147 . V_194 [ 3 ] ,
V_209 [ V_139 -> V_152 ] ) ;
for ( V_16 = 0 ; V_16 < V_139 -> V_141 ; V_16 ++ )
F_115 ( V_19 , L_40 , V_2 -> V_187 [ V_16 ] ) ;
if ( V_2 -> V_142 > 0 )
F_117 ( L_41 ,
V_2 -> V_142 ,
V_2 -> V_161 [ 0 ] . V_46 , V_2 -> V_161 [ 1 ] . V_46 ,
V_2 -> V_161 [ 0 ] . V_162 , V_2 -> V_161 [ 1 ] . V_162 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_142 ; V_16 ++ )
F_115 ( V_19 , L_42 ,
V_2 -> V_187 [ V_139 -> V_141 + V_16 ] ) ;
if ( V_139 -> V_143 )
F_117 ( L_43 ,
V_139 -> V_202 [ 0 ] , V_139 -> V_202 [ 1 ] ,
V_139 -> V_202 [ 2 ] , V_139 -> V_202 [ 3 ] ,
V_2 -> V_147 . V_149 [ 0 ] ,
V_2 -> V_147 . V_149 [ 1 ] ,
V_2 -> V_147 . V_149 [ 2 ] ,
V_2 -> V_147 . V_149 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_139 -> V_143 ; V_16 ++ )
F_115 ( V_19 , L_44 , V_2 -> V_154 [ V_16 ] ) ;
if ( V_139 -> V_144 )
F_117 ( L_45 ,
V_139 -> V_203 [ 0 ] , V_139 -> V_203 [ 1 ] ,
V_139 -> V_203 [ 2 ] , V_139 -> V_203 [ 3 ] ,
V_2 -> V_147 . V_150 [ 0 ] ,
V_2 -> V_147 . V_150 [ 1 ] ,
V_2 -> V_147 . V_150 [ 2 ] ,
V_2 -> V_147 . V_150 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_139 -> V_144 ; V_16 ++ )
F_115 ( V_19 , L_46 , V_2 -> V_156 [ V_16 ] ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ )
F_115 ( V_19 , L_47 , V_2 -> V_195 [ V_16 ] ) ;
}
static void F_118 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_50 = V_19 -> V_210 ;
V_2 -> V_76 = 0 ;
memset ( V_2 -> V_77 , 0 , sizeof( V_2 -> V_77 ) ) ;
for ( V_16 = 0 ; V_16 < V_19 -> V_211 ; V_16 ++ , V_50 ++ ) {
if ( F_39 ( F_40 ( V_19 , V_50 ) ) != V_66 )
continue;
if ( V_2 -> V_76 >= F_97 ( V_2 -> V_77 ) ) {
F_119 ( V_19 , L_48 ) ;
break;
}
V_2 -> V_77 [ V_2 -> V_76 ++ ] = V_50 ;
}
}
static int F_120 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
struct V_138 * V_212 ;
unsigned int V_20 ;
int V_213 = V_214 ;
int V_157 ;
bool V_191 = true , V_192 = true ;
bool V_215 = true , V_216 = true ;
bool V_217 = false ;
V_212 = F_121 ( sizeof( * V_212 ) , V_13 ) ;
if ( ! V_212 )
return - V_124 ;
* V_212 = * V_139 ;
for (; ; ) {
V_157 = F_114 ( V_19 , V_191 ,
V_192 ) ;
if ( V_157 < 0 ) {
F_8 ( V_212 ) ;
return V_157 ;
}
F_117 ( L_49 ,
V_139 -> V_152 , V_191 , V_192 ,
V_157 ) ;
F_116 ( V_19 , V_139 ) ;
if ( V_157 < V_213 ) {
V_213 = V_157 ;
* V_212 = * V_139 ;
V_215 = V_191 ;
V_216 = V_192 ;
}
if ( ! V_157 )
break;
V_192 = ! V_192 ;
if ( ! V_192 )
continue;
V_191 = ! V_191 ;
if ( ! V_191 )
continue;
if ( V_217 )
break;
V_217 = true ;
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
F_117 ( L_50 ) ;
* V_139 = * V_212 ;
F_114 ( V_19 , V_215 , V_216 ) ;
}
F_117 ( L_51 ,
V_139 -> V_152 , V_215 , V_216 ) ;
F_116 ( V_19 , V_139 ) ;
if ( V_139 -> V_201 [ 0 ] ) {
struct V_6 * V_52 ;
V_52 = F_27 ( V_19 , V_2 -> V_187 [ 0 ] ) ;
if ( V_52 )
V_2 -> V_218 = F_52 ( V_19 , V_52 ) ;
if ( V_2 -> V_218 )
F_122 ( V_19 , V_2 -> V_218 ,
V_83 , V_2 -> V_219 ) ;
}
if ( V_2 -> V_220 || V_139 -> V_152 == V_155 )
V_20 = V_221 ;
else
V_20 = V_222 ;
F_20 ( V_19 , V_139 -> V_141 , V_139 -> V_201 , V_20 ) ;
if ( V_139 -> V_152 != V_155 )
F_20 ( V_19 , V_139 -> V_143 , V_139 -> V_202 , V_221 ) ;
if ( V_139 -> V_152 != V_153 ) {
V_20 = V_2 -> V_220 ? V_221 : V_222 ;
F_20 ( V_19 , V_139 -> V_144 ,
V_139 -> V_203 , V_20 ) ;
}
if ( V_2 -> V_39 && ! F_112 ( V_19 ) )
V_2 -> V_39 = 0 ;
F_8 ( V_212 ) ;
return 0 ;
}
static int F_123 ( struct V_18 * V_19 ,
const struct V_138 * V_139 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_193 , V_223 ;
V_223 = V_139 -> V_141 ;
if ( V_2 -> V_142 > 0 && V_139 -> V_141 < 3 )
V_223 += V_2 -> V_142 ;
for ( V_16 = 0 ; V_16 < V_223 ; V_16 ++ ) {
const char * V_10 ;
int V_118 ;
struct V_6 * V_52 ;
V_52 = F_27 ( V_19 , V_2 -> V_187 [ V_16 ] ) ;
if ( ! V_52 )
continue;
V_10 = F_96 ( V_19 , V_16 , & V_118 , V_100 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_52 ) ) {
V_193 = F_79 ( V_19 , L_53 , 0 , 1 , V_52 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_79 ( V_19 , L_54 , 0 , 2 , V_52 ) ;
if ( V_193 < 0 )
return V_193 ;
} else {
V_193 = F_82 ( V_19 , V_10 , V_118 , V_52 ) ;
if ( V_193 < 0 )
return V_193 ;
}
V_10 = F_96 ( V_19 , V_16 , & V_118 , V_99 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_52 ) ) {
V_193 = F_83 ( V_19 , L_53 , 0 , 1 , V_52 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_83 ( V_19 , L_54 , 0 , 2 , V_52 ) ;
if ( V_193 < 0 )
return V_193 ;
} else {
V_193 = F_87 ( V_19 , V_10 , V_118 , V_52 ) ;
if ( V_193 < 0 )
return V_193 ;
}
}
return 0 ;
}
static int F_124 ( struct V_18 * V_19 , int V_115 ,
const char * V_62 , int V_116 )
{
struct V_6 * V_52 ;
int V_193 ;
V_52 = F_27 ( V_19 , V_115 ) ;
if ( ! V_52 )
return 0 ;
V_193 = F_82 ( V_19 , V_62 , V_116 , V_52 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_87 ( V_19 , V_62 , V_116 , V_52 ) ;
if ( V_193 < 0 )
return V_193 ;
return 0 ;
}
static int F_125 ( struct V_18 * V_19 , int V_48 ,
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
V_193 = F_124 ( V_19 , V_5 [ V_16 ] , V_10 , V_58 ) ;
if ( V_193 < 0 )
return V_193 ;
}
return 0 ;
}
static int F_126 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_125 ( V_19 , V_2 -> V_140 . V_143 ,
V_2 -> V_154 ,
L_35 ) ;
}
static int F_127 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_125 ( V_19 , V_2 -> V_140 . V_144 ,
V_2 -> V_156 ,
L_33 ) ;
}
static int F_128 ( struct V_129 * V_130 ,
struct V_224 * V_225 )
{
return F_129 ( V_130 , V_225 ) ;
}
static int F_130 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_132 -> V_135 . V_226 . V_227 [ 0 ] = V_2 -> V_228 ;
return 0 ;
}
static int F_131 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_229 = V_132 -> V_135 . V_226 . V_227 [ 0 ] ;
int V_230 = 0 ;
F_132 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_231 ) {
V_230 = - V_232 ;
goto V_233;
}
if ( V_2 -> V_228 != V_229 ) {
T_1 * V_234 ;
if ( V_2 -> V_140 . V_152 == V_155 )
V_234 = & V_2 -> V_160 [ 0 ] ;
else
V_234 = & V_2 -> V_147 . V_149 [ 0 ] ;
if ( V_2 -> V_235 ) {
if ( V_2 -> V_140 . V_152 == V_155 )
F_133 ( V_19 , V_2 -> V_236 ,
V_2 -> V_187 [ 0 ] ,
V_2 -> V_195 [ 0 ] ,
V_2 -> V_140 . V_152 ) ;
else
F_133 ( V_19 , V_2 -> V_236 ,
V_2 -> V_154 [ 0 ] ,
V_2 -> V_195 [ 1 ] ,
V_155 ) ;
}
V_2 -> V_228 = V_229 ;
if ( V_2 -> V_228 )
* V_234 = 0 ;
else
* V_234 = V_2 -> V_237 ;
F_134 ( V_19 , NULL ) ;
V_230 = 1 ;
}
V_233:
F_135 ( & V_2 -> V_9 ) ;
return V_230 ;
}
static int F_136 ( struct V_18 * V_19 )
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
V_2 -> V_228 = false ;
V_2 -> V_237 = V_162 ;
if ( ! F_4 ( V_2 , NULL , & V_238 ) )
return - V_124 ;
return 0 ;
}
static int F_137 ( struct V_129 * V_130 ,
struct V_224 * V_225 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_79 ;
V_225 -> type = V_239 ;
V_225 -> V_240 = 1 ;
V_225 -> V_135 . V_226 . V_241 = V_2 -> V_142 + 1 ;
if ( V_225 -> V_135 . V_226 . V_227 > V_2 -> V_142 )
V_225 -> V_135 . V_226 . V_227 = V_2 -> V_142 ;
V_79 = V_225 -> V_135 . V_226 . V_227 * 2 + V_2 -> V_207 ;
sprintf ( V_225 -> V_135 . V_226 . V_10 , L_56 , V_79 ) ;
return 0 ;
}
static int F_138 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_132 -> V_135 . V_226 . V_227 [ 0 ] =
( V_2 -> V_206 - V_2 -> V_207 ) / 2 ;
return 0 ;
}
static inline struct V_6 *
F_139 ( struct V_18 * V_19 , int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_27 ( V_19 ,
V_2 -> V_187 [ V_2 -> V_140 . V_141 + V_58 ] ) ;
}
static bool F_140 ( struct V_1 * V_2 )
{
return ! V_2 -> V_235 || V_2 -> V_236 ;
}
static int F_141 ( struct V_18 * V_19 , int V_58 , bool V_242 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_50 = V_2 -> V_161 [ V_58 ] . V_46 ;
struct V_6 * V_52 ;
V_52 = F_139 ( V_19 , V_58 ) ;
if ( ! V_52 )
return - V_243 ;
if ( V_52 -> V_90 == V_242 )
return 0 ;
if ( V_242 ) {
F_17 ( V_19 , V_50 , V_222 , true ) ;
F_65 ( V_19 , V_52 , true , F_140 ( V_2 ) ) ;
F_73 ( V_19 , V_50 , true ) ;
} else {
F_73 ( V_19 , V_50 , false ) ;
F_65 ( V_19 , V_52 , false , F_140 ( V_2 ) ) ;
F_17 ( V_19 , V_50 , V_2 -> V_161 [ V_58 ] . V_244 , true ) ;
F_69 ( V_19 , V_52 ) ;
}
F_142 ( V_19 ) ;
return 0 ;
}
static int F_143 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_137 ;
V_137 = V_132 -> V_135 . V_226 . V_227 [ 0 ] ;
if ( V_137 < 0 || V_137 > V_2 -> V_142 )
return - V_243 ;
if ( V_137 == ( V_2 -> V_206 - V_2 -> V_207 ) / 2 )
return 0 ;
V_2 -> V_206 = V_137 * 2 + V_2 -> V_207 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_142 ; V_16 ++ )
F_141 ( V_19 , V_16 , V_16 < V_137 ) ;
V_2 -> V_147 . V_245 = F_144 ( V_2 -> V_206 ,
V_2 -> V_246 ) ;
if ( V_2 -> V_34 )
V_2 -> V_147 . V_148 = V_2 -> V_147 . V_245 / 2 ;
return 1 ;
}
static int F_145 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_142 > 0 ) {
if ( ! F_4 ( V_2 , NULL , & V_247 ) )
return - V_124 ;
}
return 0 ;
}
static int F_146 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_132 -> V_135 . V_226 . V_227 [ 0 ] = V_2 -> V_236 ;
return 0 ;
}
static void F_133 ( struct V_18 * V_19 , bool V_248 ,
int V_249 , int V_250 ,
int V_251 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_252 , * V_253 ;
V_252 = F_27 ( V_19 , V_249 ) ;
V_253 = F_27 ( V_19 , V_250 ) ;
if ( ! V_252 || ! V_253 )
return;
if ( V_251 == V_155 && V_2 -> V_228 &&
V_253 -> V_52 [ 0 ] != V_2 -> V_237 )
V_248 = false ;
if ( V_248 ) {
F_65 ( V_19 , V_252 , false , true ) ;
F_65 ( V_19 , V_253 , true , true ) ;
F_69 ( V_19 , V_252 ) ;
} else {
F_65 ( V_19 , V_253 , false , false ) ;
F_65 ( V_19 , V_252 , true , false ) ;
F_69 ( V_19 , V_253 ) ;
}
}
static int F_147 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = V_132 -> V_135 . V_226 . V_227 [ 0 ] ;
if ( V_20 == V_2 -> V_236 )
return 0 ;
V_2 -> V_236 = V_20 ;
F_133 ( V_19 , V_20 , V_2 -> V_187 [ 0 ] ,
V_2 -> V_195 [ 0 ] ,
V_2 -> V_140 . V_152 ) ;
F_133 ( V_19 , V_20 , V_2 -> V_154 [ 0 ] ,
V_2 -> V_195 [ 1 ] ,
V_155 ) ;
F_133 ( V_19 , V_20 , V_2 -> V_156 [ 0 ] ,
V_2 -> V_195 [ 2 ] ,
V_153 ) ;
return 1 ;
}
static int F_148 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_45 )
return 0 ;
if ( ! ( V_2 -> V_195 [ 0 ] || V_2 -> V_195 [ 1 ] ||
V_2 -> V_195 [ 2 ] ) )
return 0 ;
if ( ! F_4 ( V_2 , NULL , & V_254 ) )
return - V_124 ;
V_2 -> V_235 = 1 ;
return 0 ;
}
static void F_149 ( struct V_18 * V_19 , int V_255 , bool V_256 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_257 ;
unsigned int V_20 ;
T_1 V_46 ;
V_46 = V_2 -> V_258 ;
V_257 = V_2 -> V_259 [ V_255 ] == V_2 -> V_260 ;
if ( ! V_256 ) {
V_20 = F_16 ( V_19 , V_46 ) ;
if ( V_257 ) {
if ( V_20 & V_261 )
return;
} else {
if ( V_20 & V_222 )
return;
}
}
V_20 = F_150 ( V_19 , V_46 ) ;
if ( V_20 == V_262 && V_2 -> V_263 ) {
const T_1 V_264 = V_2 -> V_263 ;
unsigned int V_265 = F_150 ( V_19 , V_264 ) ;
if ( V_265 != V_262 )
F_151 ( V_19 , V_264 ,
V_261 | ( V_257 ? V_265 : 0 ) ) ;
}
if ( ! V_2 -> V_266 ) {
if ( V_257 )
V_20 |= V_261 ;
else
V_20 = V_221 ;
F_17 ( V_19 , V_46 , V_20 , true ) ;
F_134 ( V_19 , NULL ) ;
}
}
static int F_152 ( struct V_18 * V_19 )
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
V_176 = F_105 ( V_19 , V_139 -> V_183 [ 0 ] . V_46 ) ;
if ( F_153 ( V_176 ) != V_267 )
return 0 ;
}
}
V_2 -> V_43 = 0 ;
if ( V_139 -> V_182 >= V_268 )
return 0 ;
V_50 = 0 ;
if ( V_139 -> V_152 == V_155 && V_139 -> V_141 > 0 )
V_50 = V_139 -> V_201 [ 0 ] ;
else if ( V_139 -> V_143 > 0 )
V_50 = V_139 -> V_202 [ 0 ] ;
if ( ! V_50 )
return 0 ;
if ( ! ( F_74 ( V_19 , V_50 ) & V_269 ) )
return 0 ;
V_139 -> V_183 [ V_139 -> V_182 ] . V_46 = V_50 ;
V_139 -> V_183 [ V_139 -> V_182 ] . type = V_181 ;
V_139 -> V_183 [ V_139 -> V_182 ] . V_270 = 1 ;
V_139 -> V_182 ++ ;
V_2 -> V_43 = 1 ;
V_2 -> V_258 = V_50 ;
V_2 -> V_31 = 1 ;
F_36 ( V_19 , L_57 , V_50 ) ;
return 0 ;
}
static int F_154 ( struct V_129 * V_130 ,
struct V_224 * V_225 )
{
return F_155 ( V_130 , V_225 , 2 , V_271 ) ;
}
static int F_156 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
T_1 V_50 = V_130 -> V_121 ;
if ( F_16 ( V_19 , V_50 ) == V_221 )
V_132 -> V_135 . V_226 . V_227 [ 0 ] = 1 ;
else
V_132 -> V_135 . V_226 . V_227 [ 0 ] = 0 ;
return 0 ;
}
static int F_157 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
T_1 V_50 = V_130 -> V_121 ;
unsigned int V_20 ;
V_20 = V_132 -> V_135 . V_226 . V_227 [ 0 ] ? V_221 : V_222 ;
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
if ( ! strcmp ( V_15 -> V_10 , V_10 ) && V_15 -> V_118 == V_58 )
return true ;
}
return false ;
}
static void F_159 ( struct V_18 * V_19 , T_1 V_46 ,
char * V_10 , T_3 V_272 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_58 = 0 ;
F_160 ( V_19 , V_46 , & V_2 -> V_140 , V_10 , V_272 , & V_58 ) ;
F_35 ( V_10 , L_58 , V_272 ) ;
for (; F_158 ( V_19 , V_10 , V_58 ) ; V_58 ++ )
;
}
static int F_161 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_41 ) {
unsigned int V_273 = F_74 ( V_19 , V_46 ) ;
if ( ( V_273 & V_178 ) && ( V_273 & V_274 ) )
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
if ( V_46 == V_2 -> V_258 )
continue;
if ( F_161 ( V_19 , V_46 ) > 1 ) {
struct V_4 * V_12 ;
char V_10 [ V_123 ] ;
F_159 ( V_19 , V_46 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 ,
& V_275 ) ;
if ( ! V_12 )
return - V_124 ;
V_12 -> V_121 = V_46 ;
}
}
return 0 ;
}
static unsigned int F_163 ( struct V_18 * V_19 , T_1 V_46 )
{
unsigned int V_273 ;
V_273 = F_74 ( V_19 , V_46 ) ;
V_273 = ( V_273 & V_276 ) >> V_277 ;
V_273 &= ~ ( V_278 | V_279 ) ;
return V_273 ;
}
static int F_164 ( unsigned int V_280 , unsigned int V_281 )
{
unsigned int V_16 , V_89 = 0 ;
for ( V_16 = 0 ; V_16 < V_282 ; V_16 ++ ) {
if ( V_280 & ( 1 << V_16 ) ) {
if ( V_89 == V_281 )
return V_16 ;
V_89 ++ ;
}
}
return 0 ;
}
static int F_165 ( unsigned int V_280 , unsigned int V_58 )
{
unsigned int V_16 , V_89 = 0 ;
for ( V_16 = 0 ; V_16 < V_282 ; V_16 ++ ) {
if ( V_16 == V_58 )
return V_89 ;
if ( V_280 & ( 1 << V_16 ) )
V_89 ++ ;
}
return 0 ;
}
static int F_166 ( struct V_129 * V_130 ,
struct V_224 * V_225 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
T_1 V_50 = V_130 -> V_121 ;
unsigned int V_280 = F_163 ( V_19 , V_50 ) ;
F_155 ( V_130 , V_225 , F_167 ( V_280 ) ,
V_283 ) ;
strcpy ( V_225 -> V_135 . V_226 . V_10 ,
V_283 [ F_164 ( V_280 , V_225 -> V_135 . V_226 . V_227 ) ] ) ;
return 0 ;
}
static int F_168 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
T_1 V_50 = V_130 -> V_121 ;
unsigned int V_280 = F_163 ( V_19 , V_50 ) ;
unsigned int V_58 ;
V_58 = F_16 ( V_19 , V_50 ) & V_284 ;
V_132 -> V_135 . V_226 . V_227 [ 0 ] = F_165 ( V_280 , V_58 ) ;
return 0 ;
}
static int F_169 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
T_1 V_50 = V_130 -> V_121 ;
unsigned int V_280 = F_163 ( V_19 , V_50 ) ;
unsigned int V_20 , V_58 ;
V_20 = F_16 ( V_19 , V_50 ) ;
V_58 = F_165 ( V_280 , V_20 & V_284 ) ;
if ( V_58 == V_132 -> V_135 . V_226 . V_227 [ 0 ] )
return 0 ;
V_20 &= ~ V_284 ;
V_20 |= F_164 ( V_280 , V_132 -> V_135 . V_226 . V_227 [ 0 ] ) ;
F_151 ( V_19 , V_50 , V_20 ) ;
return 1 ;
}
static int F_170 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_285 = 0 ;
if ( V_2 -> V_41 )
V_285 = F_167 ( F_163 ( V_19 , V_46 ) ) ;
return V_285 ? V_285 : 1 ;
}
static int F_171 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
char V_10 [ V_123 ] ;
unsigned int V_176 ;
if ( V_46 == V_2 -> V_258 )
return 0 ;
V_176 = F_105 ( V_19 , V_46 ) ;
if ( F_153 ( V_176 ) == V_267 )
return 0 ;
if ( F_170 ( V_19 , V_46 ) <= 1 )
return 0 ;
F_159 ( V_19 , V_46 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 , & V_286 ) ;
if ( ! V_12 )
return - V_124 ;
V_12 -> V_121 = V_46 ;
return 0 ;
}
static int F_172 ( struct V_129 * V_130 ,
struct V_224 * V_225 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
T_1 V_50 = V_130 -> V_121 ;
int V_287 = F_161 ( V_19 , V_50 ) ;
int V_288 = F_170 ( V_19 , V_50 ) ;
const char * V_289 = NULL ;
int V_58 ;
V_225 -> type = V_239 ;
V_225 -> V_240 = 1 ;
V_225 -> V_135 . V_226 . V_241 = V_287 + V_288 ;
if ( V_225 -> V_135 . V_226 . V_227 >= V_225 -> V_135 . V_226 . V_241 )
V_225 -> V_135 . V_226 . V_227 = V_225 -> V_135 . V_226 . V_241 - 1 ;
V_58 = V_225 -> V_135 . V_226 . V_227 ;
if ( V_58 < V_287 ) {
if ( V_287 > 1 )
V_289 = V_271 [ V_58 ] ;
else
V_289 = L_59 ;
} else {
V_58 -= V_287 ;
if ( V_288 > 1 ) {
unsigned int V_280 = F_163 ( V_19 , V_50 ) ;
V_289 = V_283 [ F_164 ( V_280 , V_58 ) ] ;
} else
V_289 = L_60 ;
}
strcpy ( V_225 -> V_135 . V_226 . V_10 , V_289 ) ;
return 0 ;
}
static int F_173 ( struct V_18 * V_19 , T_1 V_50 )
{
int V_287 = F_161 ( V_19 , V_50 ) ;
int V_288 = F_170 ( V_19 , V_50 ) ;
unsigned int V_20 = F_16 ( V_19 , V_50 ) ;
int V_58 = 0 ;
if ( V_20 & V_222 ) {
if ( V_287 > 1 && V_20 == V_221 )
V_58 = 1 ;
} else if ( V_20 & V_261 ) {
V_58 = V_287 ;
if ( V_288 > 1 ) {
unsigned int V_280 = F_163 ( V_19 , V_50 ) ;
V_20 &= V_284 ;
V_58 += F_165 ( V_280 , V_20 ) ;
}
}
return V_58 ;
}
static int F_174 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
T_1 V_50 = V_130 -> V_121 ;
V_132 -> V_135 . V_226 . V_227 [ 0 ] =
F_173 ( V_19 , V_50 ) ;
return 0 ;
}
static int F_175 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
T_1 V_50 = V_130 -> V_121 ;
int V_287 = F_161 ( V_19 , V_50 ) ;
int V_288 = F_170 ( V_19 , V_50 ) ;
unsigned int V_20 , V_290 , V_58 ;
V_290 = F_173 ( V_19 , V_50 ) ;
V_58 = V_132 -> V_135 . V_226 . V_227 [ 0 ] ;
if ( V_290 == V_58 )
return 0 ;
if ( V_58 < V_287 ) {
if ( V_287 > 1 )
V_20 = V_58 ? V_221 : V_222 ;
else
V_20 = V_221 ;
} else {
V_58 -= V_287 ;
if ( V_288 > 1 ) {
unsigned int V_280 = F_163 ( V_19 , V_50 ) ;
V_20 = F_16 ( V_19 , V_50 ) ;
V_20 &= ~ ( V_284 | V_221 ) ;
V_20 |= F_164 ( V_280 , V_58 ) | V_261 ;
} else
V_20 = F_150 ( V_19 , V_50 ) | V_261 ;
}
F_151 ( V_19 , V_50 , V_20 ) ;
F_134 ( V_19 , NULL ) ;
return 1 ;
}
static int F_176 ( struct V_18 * V_19 , T_1 V_46 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
V_12 = F_4 ( V_2 , L_61 ,
& V_291 ) ;
if ( ! V_12 )
return - V_124 ;
V_12 -> V_121 = V_46 ;
V_2 -> V_266 = 1 ;
return 0 ;
}
static int F_177 ( struct V_1 * V_2 , T_1 V_292 , int V_58 )
{
struct V_8 * V_14 ;
V_14 = F_5 ( & V_2 -> V_7 ) ;
if ( ! V_14 )
return - V_124 ;
V_14 -> V_50 = V_292 ;
V_14 -> V_61 = V_84 ;
V_14 -> V_58 = V_58 ;
V_2 -> V_293 . V_294 = V_2 -> V_7 . V_14 ;
return 0 ;
}
static bool F_178 ( struct V_18 * V_19 , T_1 V_295 ,
T_1 V_46 , unsigned int * V_296 ,
unsigned int * V_297 )
{
int V_58 , V_298 ;
const T_1 * V_14 ;
T_1 V_50 ;
V_58 = F_30 ( V_19 , V_295 , V_46 , true ) ;
if ( V_58 < 0 )
return false ;
* V_296 = * V_297 = 0 ;
if ( F_53 ( V_19 , V_295 , V_84 ) )
* V_296 = F_33 ( V_295 , 3 , V_58 , V_84 ) ;
if ( F_51 ( V_19 , V_295 , V_84 ) )
* V_297 = F_33 ( V_295 , 3 , V_58 , V_84 ) ;
if ( * V_296 && * V_297 )
return true ;
V_298 = F_38 ( V_19 , V_295 , & V_14 ) ;
if ( V_298 < V_58 )
return false ;
V_50 = V_14 [ V_58 ] ;
if ( ! * V_296 && F_53 ( V_19 , V_50 , V_83 ) &&
! F_32 ( V_19 , V_50 , V_83 , 0 , V_100 ) )
* V_296 = F_33 ( V_50 , 3 , 0 , V_83 ) ;
if ( ! * V_297 && F_51 ( V_19 , V_50 , V_83 ) &&
! F_32 ( V_19 , V_50 , V_83 , 0 , V_99 ) )
* V_297 = F_33 ( V_50 , 3 , 0 , V_83 ) ;
return * V_296 || * V_297 ;
}
static int F_179 ( struct V_18 * V_19 , int V_299 ,
T_1 V_46 , const char * V_300 , int V_301 ,
T_1 V_295 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_52 ;
unsigned int V_296 , V_297 ;
int V_193 , V_58 ;
if ( ! F_178 ( V_19 , V_295 , V_46 , & V_296 , & V_297 ) )
return 0 ;
V_52 = F_42 ( V_19 , V_46 , V_295 , 0 ) ;
if ( ! V_52 )
return - V_243 ;
F_34 ( V_19 , L_62 , V_52 ) ;
V_2 -> V_198 [ V_299 ] = F_26 ( V_19 , V_52 ) ;
V_58 = V_52 -> V_58 [ V_52 -> V_53 - 1 ] ;
if ( V_296 ) {
V_193 = F_80 ( V_2 , V_125 , V_300 , V_301 , V_296 ) ;
if ( V_193 < 0 )
return V_193 ;
V_52 -> V_60 [ V_100 ] = V_296 ;
}
if ( V_297 ) {
V_193 = F_86 ( V_2 , V_127 , V_300 , V_301 , V_297 ) ;
if ( V_193 < 0 )
return V_193 ;
V_52 -> V_60 [ V_99 ] = V_297 ;
}
V_52 -> V_90 = true ;
V_193 = F_177 ( V_2 , V_295 , V_58 ) ;
if ( V_193 < 0 )
return V_193 ;
if ( V_2 -> V_45 != V_2 -> V_104 &&
! V_2 -> V_302 ) {
V_52 = F_42 ( V_19 , V_2 -> V_45 ,
V_2 -> V_104 , 0 ) ;
if ( V_52 ) {
F_34 ( V_19 , L_63 , V_52 ) ;
V_52 -> V_90 = true ;
V_2 -> V_302 =
F_26 ( V_19 , V_52 ) ;
}
}
return 0 ;
}
static int F_180 ( struct V_18 * V_19 , T_1 V_50 )
{
unsigned int V_273 = F_74 ( V_19 , V_50 ) ;
return ( V_273 & V_269 ) != 0 ;
}
static int F_181 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_50 ;
T_1 * V_303 = V_2 -> V_303 ;
int V_304 = F_97 ( V_2 -> V_303 ) ;
int V_16 , V_51 = 0 ;
V_50 = V_19 -> V_210 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_211 ; V_16 ++ , V_50 ++ ) {
unsigned int V_86 = F_40 ( V_19 , V_50 ) ;
int type = F_39 ( V_86 ) ;
if ( type != V_69 || ( V_86 & V_78 ) )
continue;
V_303 [ V_51 ] = V_50 ;
if ( ++ V_51 >= V_304 )
break;
}
V_2 -> V_305 = V_51 ;
V_2 -> V_306 = V_51 ;
memcpy ( V_2 -> V_307 , V_2 -> V_303 , V_51 * sizeof( T_1 ) ) ;
return V_51 ;
}
static int F_182 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_308 * V_309 = & V_2 -> V_310 ;
unsigned int V_311 ;
int V_16 , V_89 , V_51 ;
V_51 = 0 ;
V_311 = 0 ;
for ( V_89 = 0 ; V_89 < V_2 -> V_305 ; V_89 ++ ) {
for ( V_16 = 0 ; V_16 < V_309 -> V_312 ; V_16 ++ ) {
if ( ! V_2 -> V_197 [ V_16 ] [ V_89 ] )
break;
}
if ( V_16 >= V_309 -> V_312 ) {
V_311 |= ( 1 << V_89 ) ;
V_51 ++ ;
}
}
if ( ! V_311 ) {
for ( V_16 = 0 ; V_16 < V_309 -> V_312 ; V_16 ++ ) {
for ( V_89 = 0 ; V_89 < V_2 -> V_305 ; V_89 ++ ) {
if ( V_2 -> V_197 [ V_16 ] [ V_89 ] ) {
V_2 -> V_313 [ V_16 ] = V_89 ;
break;
}
}
}
F_36 ( V_19 , L_64 ) ;
V_2 -> V_314 = 1 ;
} else if ( V_51 != V_2 -> V_305 ) {
V_51 = 0 ;
for ( V_89 = 0 ; V_89 < V_2 -> V_305 ; V_89 ++ ) {
if ( ! ( V_311 & ( 1 << V_89 ) ) )
continue;
if ( V_89 != V_51 ) {
V_2 -> V_303 [ V_51 ] = V_2 -> V_303 [ V_89 ] ;
for ( V_16 = 0 ; V_16 < V_309 -> V_312 ; V_16 ++ ) {
F_43 ( V_19 ,
V_2 -> V_197 [ V_16 ] [ V_51 ] ) ;
V_2 -> V_197 [ V_16 ] [ V_51 ] =
V_2 -> V_197 [ V_16 ] [ V_89 ] ;
}
}
V_51 ++ ;
}
V_2 -> V_305 = V_51 ;
}
if ( V_309 -> V_312 == 1 ||
( V_309 -> V_312 == 2 && V_2 -> V_43 ) ) {
F_36 ( V_19 , L_65 ) ;
V_2 -> V_305 = 1 ;
}
if ( ! V_2 -> V_314 && V_2 -> V_37 )
V_2 -> V_305 = 1 ;
return 0 ;
}
static int F_183 ( struct V_18 * V_19 , T_1 V_46 ,
int V_315 , int V_316 ,
const char * V_317 , int V_318 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_308 * V_309 = & V_2 -> V_310 ;
int V_319 = V_309 -> V_312 ;
bool V_320 = false ;
int V_321 ;
for ( V_321 = 0 ; V_321 < V_316 ; V_321 ++ ) {
struct V_6 * V_52 ;
T_1 V_322 = V_2 -> V_303 [ V_321 ] ;
if ( ! F_29 ( V_19 , V_46 , V_322 ) )
continue;
V_52 = F_42 ( V_19 , V_46 , V_322 , V_318 ) ;
if ( ! V_52 )
continue;
F_34 ( V_19 , L_66 , V_52 ) ;
V_2 -> V_197 [ V_319 ] [ V_321 ] =
F_26 ( V_19 , V_52 ) ;
if ( ! V_320 ) {
if ( V_2 -> V_258 == V_46 )
V_2 -> V_260 = V_309 -> V_312 ;
V_2 -> V_323 [ V_309 -> V_312 ] = V_46 ;
F_184 ( V_309 , V_317 , V_315 , NULL ) ;
V_320 = true ;
if ( V_2 -> V_314 )
V_2 -> V_313 [ V_319 ] = V_321 ;
}
}
return 0 ;
}
static int F_185 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_138 * V_139 = & V_2 -> V_140 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_139 -> V_182 ; V_16 ++ ) {
T_1 V_46 = V_139 -> V_183 [ V_16 ] . V_46 ;
const char * V_317 ;
int V_167 , V_58 ;
if ( ! F_180 ( V_19 , V_46 ) )
continue;
V_317 = F_186 ( V_19 , V_139 , V_16 ) ;
V_58 = 0 ;
for ( V_167 = V_16 - 1 ; V_167 >= 0 ; V_167 -- ) {
if ( V_2 -> V_324 [ V_167 ] &&
! strcmp ( V_2 -> V_324 [ V_167 ] , V_317 ) ) {
V_58 = V_2 -> V_325 [ V_167 ] + 1 ;
break;
}
}
V_2 -> V_324 [ V_16 ] = V_317 ;
V_2 -> V_325 [ V_16 ] = V_58 ;
}
return 0 ;
}
static int F_187 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_138 * V_139 = & V_2 -> V_140 ;
T_1 V_326 = V_2 -> V_45 ;
int V_316 ;
int V_16 , V_193 ;
unsigned int V_20 ;
V_316 = F_181 ( V_19 ) ;
if ( V_316 < 0 )
return 0 ;
V_193 = F_185 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
for ( V_16 = 0 ; V_16 < V_139 -> V_182 ; V_16 ++ ) {
T_1 V_46 ;
V_46 = V_139 -> V_183 [ V_16 ] . V_46 ;
if ( ! F_180 ( V_19 , V_46 ) )
continue;
V_20 = V_261 ;
if ( V_139 -> V_183 [ V_16 ] . type == V_181 )
V_20 |= F_150 ( V_19 , V_46 ) ;
if ( V_46 != V_2 -> V_258 )
F_17 ( V_19 , V_46 , V_20 , false ) ;
if ( V_326 ) {
if ( F_29 ( V_19 , V_46 , V_326 ) ) {
V_193 = F_179 ( V_19 , V_16 , V_46 ,
V_2 -> V_324 [ V_16 ] ,
V_2 -> V_325 [ V_16 ] ,
V_326 ) ;
if ( V_193 < 0 )
return V_193 ;
}
}
V_193 = F_183 ( V_19 , V_46 , V_16 , V_316 ,
V_2 -> V_324 [ V_16 ] , - V_326 ) ;
if ( V_193 < 0 )
return V_193 ;
if ( V_2 -> V_41 ) {
V_193 = F_171 ( V_19 , V_46 ) ;
if ( V_193 < 0 )
return V_193 ;
}
}
if ( V_326 && V_2 -> V_40 &&
F_12 ( V_19 , L_20 ) > 0 ) {
V_193 = F_183 ( V_19 , V_326 , V_327 , V_316 ,
L_67 , 0 ) ;
if ( V_193 < 0 )
return V_193 ;
}
return 0 ;
}
static struct V_6 * F_188 ( struct V_18 * V_19 , int V_328 , int V_319 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_319 < 0 || V_319 >= V_329 ) {
F_98 () ;
return NULL ;
}
if ( V_2 -> V_314 )
V_328 = V_2 -> V_313 [ V_319 ] ;
if ( V_328 < 0 || V_328 >= V_268 ) {
F_98 () ;
return NULL ;
}
return F_27 ( V_19 , V_2 -> V_197 [ V_319 ] [ V_328 ] ) ;
}
static int F_189 ( struct V_129 * V_130 ,
struct V_224 * V_225 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
return F_190 ( & V_2 -> V_310 , V_225 ) ;
}
static int F_191 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_328 = F_192 ( V_130 , & V_132 -> V_330 ) ;
V_132 -> V_135 . V_226 . V_227 [ 0 ] = V_2 -> V_259 [ V_328 ] ;
return 0 ;
}
static int F_193 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
unsigned int V_328 = F_192 ( V_130 , & V_132 -> V_330 ) ;
return F_194 ( V_19 , V_328 ,
V_132 -> V_135 . V_226 . V_227 [ 0 ] ) ;
}
static int F_195 ( struct V_129 * V_130 ,
struct V_131 * V_132 ,
T_4 V_331 , int type )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_308 * V_309 ;
struct V_6 * V_52 ;
int V_16 , V_328 , V_193 = 0 ;
V_309 = & V_2 -> V_310 ;
V_328 = V_130 -> V_330 . V_118 ;
F_132 ( & V_19 -> V_332 ) ;
V_19 -> V_333 = 1 ;
for ( V_16 = 0 ; V_16 < V_309 -> V_312 ; V_16 ++ ) {
V_52 = F_188 ( V_19 , V_328 , V_16 ) ;
if ( ! V_52 || ! V_52 -> V_60 [ type ] )
continue;
V_130 -> V_121 = V_52 -> V_60 [ type ] ;
V_193 = V_331 ( V_130 , V_132 ) ;
if ( V_193 < 0 )
goto error;
}
error:
V_19 -> V_333 = 0 ;
F_135 ( & V_19 -> V_332 ) ;
F_196 ( V_19 ) ;
if ( V_193 >= 0 && V_2 -> V_334 )
V_2 -> V_334 ( V_19 , V_130 , V_132 ) ;
return V_193 ;
}
static int F_197 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
return F_195 ( V_130 , V_132 ,
V_335 ,
V_100 ) ;
}
static int F_198 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
return F_195 ( V_130 , V_132 ,
F_92 ,
V_99 ) ;
}
static int F_199 ( struct V_18 * V_19 , struct V_6 * V_52 )
{
T_1 V_50 ;
int V_16 , V_53 ;
V_52 -> V_60 [ V_100 ] = V_52 -> V_60 [ V_99 ] = 0 ;
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
if ( V_53 >= V_52 -> V_53 )
return - V_243 ;
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
static bool F_200 ( struct V_18 * V_19 , T_1 V_50 )
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
V_20 = F_105 ( V_19 , V_50 ) ;
return F_153 ( V_20 ) == V_267 ;
}
return false ;
}
static int F_201 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_230 ;
V_230 = F_92 ( V_130 , V_132 ) ;
if ( V_230 < 0 )
return V_230 ;
if ( V_2 -> V_334 )
V_2 -> V_334 ( V_19 , V_130 , V_132 ) ;
return V_230 ;
}
static int F_202 ( struct V_18 * V_19 , const char * V_317 ,
int V_58 , bool V_336 , unsigned int V_337 ,
bool V_338 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
char V_339 [ V_123 ] ;
int type = V_336 ? V_127 : V_125 ;
const char * V_122 = V_336 ? L_68 : L_69 ;
unsigned int V_79 = V_338 ? 1 : 3 ;
struct V_4 * V_12 ;
if ( ! V_337 )
return 0 ;
if ( V_317 )
snprintf ( V_339 , sizeof( V_339 ) ,
L_70 , V_317 , V_122 ) ;
else
snprintf ( V_339 , sizeof( V_339 ) ,
L_71 , V_122 ) ;
V_12 = F_76 ( V_2 , type , V_339 , V_58 ,
F_46 ( V_337 , V_79 ) ) ;
if ( ! V_12 )
return - V_124 ;
if ( V_336 )
V_12 -> V_340 = F_201 ;
if ( ! V_338 )
return 0 ;
if ( V_317 )
snprintf ( V_339 , sizeof( V_339 ) ,
L_72 , V_317 , V_122 ) ;
else
snprintf ( V_339 , sizeof( V_339 ) ,
L_73 , V_122 ) ;
V_12 = F_76 ( V_2 , type , V_339 , V_58 ,
F_46 ( V_337 , 2 ) ) ;
if ( ! V_12 )
return - V_124 ;
if ( V_336 )
V_12 -> V_340 = F_201 ;
return 0 ;
}
static int F_203 ( struct V_18 * V_19 , int V_58 ,
unsigned int V_341 , unsigned int V_342 ,
bool V_338 )
{
int V_193 ;
V_193 = F_202 ( V_19 , NULL , V_58 , false , V_341 , V_338 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_202 ( V_19 , NULL , V_58 , true , V_342 , V_338 ) ;
if ( V_193 < 0 )
return V_193 ;
return 0 ;
}
static int F_204 ( struct V_18 * V_19 , int V_58 ,
unsigned int V_341 , unsigned int V_342 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
if ( V_341 ) {
V_12 = F_4 ( V_2 , NULL , & V_343 ) ;
if ( ! V_12 )
return - V_124 ;
V_12 -> V_118 = V_58 ;
V_12 -> V_121 = V_341 ;
V_12 -> V_119 = V_120 ;
}
if ( V_342 ) {
V_12 = F_4 ( V_2 , NULL , & V_344 ) ;
if ( ! V_12 )
return - V_124 ;
V_12 -> V_118 = V_58 ;
V_12 -> V_121 = V_342 ;
V_12 -> V_119 = V_120 ;
}
return 0 ;
}
static unsigned int F_205 ( struct V_18 * V_19 , int V_58 , int type )
{
struct V_6 * V_52 ;
unsigned int V_337 ;
int V_16 ;
V_52 = F_188 ( V_19 , 0 , V_58 ) ;
if ( ! V_52 )
return 0 ;
V_337 = V_52 -> V_60 [ type ] ;
if ( ! V_337 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_58 - 1 ; V_16 ++ ) {
V_52 = F_188 ( V_19 , 0 , V_16 ) ;
if ( V_52 && V_52 -> V_60 [ type ] == V_337 )
return 0 ;
}
return V_337 ;
}
static int F_206 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_308 * V_309 = & V_2 -> V_310 ;
int V_16 , V_193 , type ;
for ( V_16 = 0 ; V_16 < V_309 -> V_312 ; V_16 ++ ) {
bool V_338 ;
int V_58 ;
V_58 = V_309 -> V_241 [ V_16 ] . V_118 ;
if ( V_58 >= V_2 -> V_140 . V_182 )
continue;
V_338 = F_200 ( V_19 , V_2 -> V_323 [ V_16 ] ) ;
for ( type = 0 ; type < 2 ; type ++ ) {
V_193 = F_202 ( V_19 ,
V_2 -> V_324 [ V_58 ] ,
V_2 -> V_325 [ V_58 ] ,
type ,
F_205 ( V_19 , V_16 , type ) ,
V_338 ) ;
if ( V_193 < 0 )
return V_193 ;
}
}
return 0 ;
}
static int F_207 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_308 * V_309 = & V_2 -> V_310 ;
int V_16 , V_89 , V_51 , V_193 ;
if ( V_2 -> V_314 )
V_51 = 1 ;
else
V_51 = V_2 -> V_305 ;
if ( ! V_2 -> V_345 && V_309 -> V_312 > 1 ) {
struct V_4 * V_12 ;
const char * V_10 ;
V_10 = V_51 > 1 ? L_74 : L_75 ;
V_12 = F_4 ( V_2 , V_10 , & V_346 ) ;
if ( ! V_12 )
return - V_124 ;
V_12 -> V_240 = V_51 ;
}
for ( V_89 = 0 ; V_89 < V_51 ; V_89 ++ ) {
bool V_72 = false ;
bool V_37 = V_2 -> V_37 ;
bool V_338 = false ;
int V_347 , V_348 ;
V_347 = V_348 = 0 ;
for ( V_16 = 0 ; V_16 < V_309 -> V_312 ; V_16 ++ ) {
struct V_6 * V_52 ;
V_52 = F_188 ( V_19 , V_89 , V_16 ) ;
if ( ! V_52 )
continue;
F_199 ( V_19 , V_52 ) ;
if ( ! V_347 )
V_347 = V_52 -> V_60 [ V_100 ] ;
else if ( V_347 != V_52 -> V_60 [ V_100 ] ) {
V_72 = true ;
if ( ! F_49 ( V_19 , V_347 ,
V_52 -> V_60 [ V_100 ] , V_84 ) )
V_37 = true ;
}
if ( ! V_348 )
V_348 = V_52 -> V_60 [ V_99 ] ;
else if ( V_348 != V_52 -> V_60 [ V_99 ] ) {
V_72 = true ;
if ( ! F_49 ( V_19 , V_348 ,
V_52 -> V_60 [ V_99 ] , V_84 ) )
V_37 = true ;
}
if ( F_200 ( V_19 , V_2 -> V_323 [ V_16 ] ) )
V_338 = true ;
}
if ( ! V_72 )
V_193 = F_203 ( V_19 , V_89 , V_347 , V_348 ,
V_338 ) ;
else if ( ! V_37 && ! V_338 )
V_193 = F_204 ( V_19 , V_89 , V_347 , V_348 ) ;
else
V_193 = F_206 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
}
return 0 ;
}
static bool F_208 ( struct V_18 * V_19 , T_1 V_50 ,
int V_61 , int V_58 )
{
unsigned int V_349 ;
if ( ! F_53 ( V_19 , V_50 , V_61 ) ||
F_32 ( V_19 , V_50 , V_61 , V_58 , V_100 ) ||
F_32 ( V_19 , V_50 , V_61 , V_58 , V_101 ) )
return false ;
V_349 = ( F_48 ( V_19 , V_50 , V_61 ) & V_350 )
>> V_351 ;
if ( V_349 < 0x20 )
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
if ( V_53 && F_208 ( V_19 , V_50 , V_83 , 0 ) ) {
V_20 = F_33 ( V_50 , 3 , 0 , V_83 ) ;
break;
} else if ( F_208 ( V_19 , V_50 , V_84 ,
V_52 -> V_58 [ V_53 ] ) ) {
V_20 = F_33 ( V_50 , 3 , V_52 -> V_58 [ V_53 ] ,
V_84 ) ;
break;
}
}
return V_20 ;
}
static int F_210 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
struct V_308 * V_309 = & V_2 -> V_310 ;
int V_16 ;
if ( ! V_2 -> V_305 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_309 -> V_312 ; V_16 ++ ) {
struct V_6 * V_52 ;
unsigned int V_20 ;
int V_58 ;
char V_352 [ V_123 ] ;
V_58 = V_309 -> V_241 [ V_16 ] . V_118 ;
if ( V_58 >= V_309 -> V_312 )
continue;
if ( V_139 -> V_183 [ V_58 ] . type > V_180 )
continue;
V_52 = F_188 ( V_19 , 0 , V_16 ) ;
if ( ! V_52 )
continue;
V_20 = F_209 ( V_19 , V_52 ) ;
if ( ! V_20 )
continue;
snprintf ( V_352 , sizeof( V_352 ) ,
L_76 , V_2 -> V_324 [ V_58 ] ) ;
if ( ! F_76 ( V_2 , V_125 , V_352 ,
V_2 -> V_325 [ V_58 ] , V_20 ) )
return - V_124 ;
V_52 -> V_60 [ V_101 ] = V_20 ;
}
return 0 ;
}
static void F_211 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_52 ;
int V_16 , V_51 ;
T_1 V_353 , V_46 ;
V_51 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_140 . V_354 ; V_16 ++ ) {
V_46 = V_2 -> V_140 . V_355 [ V_16 ] ;
V_353 = F_45 ( V_19 , V_46 , true ) ;
if ( ! V_353 )
continue;
V_52 = F_42 ( V_19 , V_353 , V_46 , 0 ) ;
if ( ! V_52 )
continue;
F_34 ( V_19 , L_77 , V_52 ) ;
V_52 -> V_90 = true ;
V_2 -> V_196 [ V_16 ] = F_26 ( V_19 , V_52 ) ;
F_17 ( V_19 , V_46 , V_222 , false ) ;
if ( ! V_51 ) {
V_2 -> V_147 . V_356 = V_353 ;
V_2 -> V_357 = V_2 -> V_140 . V_357 [ 0 ] ;
} else {
V_2 -> V_147 . V_358 = V_2 -> V_358 ;
if ( V_51 >= F_97 ( V_2 -> V_358 ) - 1 )
break;
V_2 -> V_358 [ V_51 - 1 ] = V_353 ;
}
V_51 ++ ;
}
if ( V_2 -> V_140 . V_359 ) {
V_46 = V_2 -> V_140 . V_359 ;
V_353 = V_19 -> V_210 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_211 ; V_16 ++ , V_353 ++ ) {
unsigned int V_360 = F_40 ( V_19 , V_353 ) ;
if ( F_39 ( V_360 ) != V_69 )
continue;
if ( ! ( V_360 & V_78 ) )
continue;
V_52 = F_42 ( V_19 , V_46 , V_353 , 0 ) ;
if ( V_52 ) {
F_34 ( V_19 , L_78 , V_52 ) ;
V_52 -> V_90 = true ;
V_2 -> V_361 = V_353 ;
V_2 -> V_199 = F_26 ( V_19 , V_52 ) ;
F_17 ( V_19 , V_46 , V_261 , false ) ;
break;
}
}
}
}
static int F_194 ( struct V_18 * V_19 , unsigned int V_328 ,
unsigned int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_308 * V_309 ;
struct V_6 * V_362 , * V_52 ;
V_309 = & V_2 -> V_310 ;
if ( ! V_309 -> V_312 )
return 0 ;
if ( V_58 >= V_309 -> V_312 )
V_58 = V_309 -> V_312 - 1 ;
if ( V_2 -> V_259 [ V_328 ] == V_58 )
return 0 ;
V_362 = F_188 ( V_19 , V_328 , V_2 -> V_259 [ V_328 ] ) ;
if ( ! V_362 )
return 0 ;
if ( V_362 -> V_90 )
F_65 ( V_19 , V_362 , false , false ) ;
V_2 -> V_259 [ V_328 ] = V_58 ;
if ( V_2 -> V_43 )
F_149 ( V_19 , V_328 , false ) ;
if ( V_2 -> V_314 )
F_212 ( V_19 , V_58 ) ;
V_52 = F_188 ( V_19 , V_328 , V_58 ) ;
if ( ! V_52 )
return 0 ;
if ( V_52 -> V_90 )
return 0 ;
F_65 ( V_19 , V_52 , true , false ) ;
if ( V_2 -> V_334 )
V_2 -> V_334 ( V_19 , NULL , NULL ) ;
F_69 ( V_19 , V_362 ) ;
return 1 ;
}
static bool F_213 ( struct V_18 * V_19 , int V_48 , T_1 * V_49 )
{
int V_16 ;
bool V_363 = false ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
T_1 V_50 = V_49 [ V_16 ] ;
if ( ! V_50 )
break;
if ( F_16 ( V_19 , V_50 ) & V_364 )
continue;
if ( F_214 ( V_19 , V_50 ) == V_365 )
V_363 = true ;
}
return V_363 ;
}
static void F_215 ( struct V_18 * V_19 , int V_48 , T_1 * V_49 ,
int * V_5 , bool V_366 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
T_1 V_50 = V_49 [ V_16 ] ;
unsigned int V_20 , V_290 ;
if ( ! V_50 )
break;
if ( V_2 -> V_33 ) {
struct V_6 * V_52 ;
T_1 V_367 ;
V_52 = F_27 ( V_19 , V_5 [ V_16 ] ) ;
if ( ! V_52 )
continue;
V_367 = F_77 ( V_52 -> V_60 [ V_99 ] ) ;
if ( ! V_367 )
continue;
if ( V_366 )
V_2 -> V_134 |= ( 1ULL << V_367 ) ;
else
V_2 -> V_134 &= ~ ( 1ULL << V_367 ) ;
F_73 ( V_19 , V_50 , ! V_366 ) ;
continue;
}
V_290 = F_16 ( V_19 , V_50 ) ;
if ( V_290 & V_261 )
continue;
if ( V_2 -> V_368 )
V_20 = V_290 & ~ V_221 ;
else
V_20 = 0 ;
if ( ! V_366 )
V_20 |= V_290 ;
F_15 ( V_19 , V_50 , V_20 ) ;
F_73 ( V_19 , V_50 , ! V_366 ) ;
}
}
void F_216 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int * V_5 ;
int V_369 ;
if ( V_2 -> V_140 . V_152 == V_155 )
V_5 = V_2 -> V_187 ;
else
V_5 = V_2 -> V_154 ;
F_215 ( V_19 , F_97 ( V_2 -> V_140 . V_202 ) ,
V_2 -> V_140 . V_202 , V_5 , V_2 -> V_370 ) ;
if ( ! V_2 -> V_371 )
V_369 = 0 ;
else
V_369 = V_2 -> V_372 | V_2 -> V_373 ;
V_369 |= V_2 -> V_370 ;
V_2 -> V_374 = V_369 ;
if ( V_2 -> V_140 . V_152 == V_153 )
V_5 = V_2 -> V_187 ;
else
V_5 = V_2 -> V_156 ;
F_215 ( V_19 , F_97 ( V_2 -> V_140 . V_203 ) ,
V_2 -> V_140 . V_203 , V_5 , V_369 ) ;
if ( V_2 -> V_140 . V_201 [ 0 ] == V_2 -> V_140 . V_202 [ 0 ] ||
V_2 -> V_140 . V_201 [ 0 ] == V_2 -> V_140 . V_203 [ 0 ] )
return;
if ( ! V_2 -> V_375 )
V_369 = 0 ;
else
V_369 = V_2 -> V_372 ;
V_369 |= V_2 -> V_370 ;
V_2 -> V_376 = V_369 ;
V_5 = V_2 -> V_187 ;
F_215 ( V_19 , F_97 ( V_2 -> V_140 . V_201 ) ,
V_2 -> V_140 . V_201 , V_5 , V_369 ) ;
}
static void F_217 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_377 )
V_2 -> V_377 ( V_19 ) ;
else
F_216 ( V_19 ) ;
if ( V_2 -> V_33 && ! V_19 -> V_378 -> V_379 )
F_218 ( V_2 -> V_145 . V_380 , false ) ;
}
void F_219 ( struct V_18 * V_19 , struct V_381 * V_382 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 * V_49 = V_2 -> V_140 . V_202 ;
int V_48 = F_97 ( V_2 -> V_140 . V_202 ) ;
if ( V_2 -> V_228 ) {
V_49 ++ ;
V_48 -- ;
}
V_2 -> V_372 = F_213 ( V_19 , V_48 , V_49 ) ;
if ( ! V_2 -> V_383 || ( ! V_2 -> V_371 && ! V_2 -> V_375 ) )
return;
F_217 ( V_19 ) ;
}
void F_220 ( struct V_18 * V_19 , struct V_381 * V_382 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_140 . V_152 == V_153 )
return;
if ( V_2 -> V_140 . V_201 [ 0 ] == V_2 -> V_140 . V_202 [ 0 ] )
return;
V_2 -> V_373 =
F_213 ( V_19 , F_97 ( V_2 -> V_140 . V_201 ) ,
V_2 -> V_140 . V_201 ) ;
if ( ! V_2 -> V_371 || ! V_2 -> V_384 )
return;
F_217 ( V_19 ) ;
}
void F_221 ( struct V_18 * V_19 , struct V_381 * V_382 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
if ( ! V_2 -> V_345 )
return;
for ( V_16 = V_2 -> V_385 - 1 ; V_16 > 0 ; V_16 -- ) {
T_1 V_46 = V_2 -> V_386 [ V_16 ] . V_46 ;
if ( F_16 ( V_19 , V_46 ) & V_387 )
continue;
if ( F_214 ( V_19 , V_46 ) == V_365 ) {
F_194 ( V_19 , 0 , V_2 -> V_386 [ V_16 ] . V_58 ) ;
return;
}
}
F_194 ( V_19 , 0 , V_2 -> V_386 [ 0 ] . V_58 ) ;
}
static void F_134 ( struct V_18 * V_19 , struct V_381 * V_382 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_388 )
V_2 -> V_388 ( V_19 , V_382 ) ;
else
F_219 ( V_19 , V_382 ) ;
}
static void F_222 ( struct V_18 * V_19 ,
struct V_381 * V_382 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_389 )
V_2 -> V_389 ( V_19 , V_382 ) ;
else
F_220 ( V_19 , V_382 ) ;
}
static void F_223 ( struct V_18 * V_19 ,
struct V_381 * V_382 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_390 )
V_2 -> V_390 ( V_19 , V_382 ) ;
else
F_221 ( V_19 , V_382 ) ;
}
static void F_142 ( struct V_18 * V_19 )
{
F_134 ( V_19 , NULL ) ;
F_222 ( V_19 , NULL ) ;
F_223 ( V_19 , NULL ) ;
}
static int F_224 ( struct V_129 * V_130 ,
struct V_224 * V_225 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_391 [] = {
L_79 , L_80 , L_81
} ;
if ( V_2 -> V_392 && V_2 -> V_393 )
return F_155 ( V_130 , V_225 , 3 , V_391 ) ;
return F_129 ( V_130 , V_225 ) ;
}
static int F_225 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = 0 ;
if ( V_2 -> V_371 )
V_20 ++ ;
if ( V_2 -> V_375 )
V_20 ++ ;
V_132 -> V_135 . V_226 . V_227 [ 0 ] = V_20 ;
return 0 ;
}
static int F_226 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_89 ( V_130 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
switch ( V_132 -> V_135 . V_226 . V_227 [ 0 ] ) {
case 0 :
if ( ! V_2 -> V_371 && ! V_2 -> V_375 )
return 0 ;
V_2 -> V_371 = 0 ;
V_2 -> V_375 = 0 ;
break;
case 1 :
if ( V_2 -> V_392 ) {
if ( ! V_2 -> V_375 && V_2 -> V_371 )
return 0 ;
V_2 -> V_371 = 1 ;
V_2 -> V_375 = 0 ;
} else if ( V_2 -> V_393 ) {
if ( V_2 -> V_375 )
return 0 ;
V_2 -> V_375 = 1 ;
} else
return - V_243 ;
break;
case 2 :
if ( ! V_2 -> V_393 || ! V_2 -> V_392 )
return - V_243 ;
if ( V_2 -> V_371 && V_2 -> V_375 )
return 0 ;
V_2 -> V_371 = 1 ;
V_2 -> V_375 = 1 ;
break;
default:
return - V_243 ;
}
F_217 ( V_19 ) ;
return 1 ;
}
static int F_227 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! F_4 ( V_2 , NULL , & V_394 ) )
return - V_124 ;
return 0 ;
}
static int F_228 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
int V_363 = 0 ;
int V_16 , V_193 ;
if ( V_2 -> V_30 )
return 0 ;
if ( V_139 -> V_202 [ 0 ] )
V_363 ++ ;
if ( V_139 -> V_201 [ 0 ] )
V_363 ++ ;
if ( V_139 -> V_203 [ 0 ] )
V_363 ++ ;
if ( V_363 < 2 )
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
if ( ! F_229 ( V_19 , V_50 ) )
continue;
F_36 ( V_19 , L_82 , V_50 ) ;
F_230 ( V_19 , V_50 , V_395 ,
F_134 ) ;
V_2 -> V_383 = 1 ;
}
if ( V_139 -> V_152 == V_396 && V_139 -> V_141 ) {
if ( V_139 -> V_144 )
for ( V_16 = 0 ; V_16 < V_139 -> V_141 ; V_16 ++ ) {
T_1 V_50 = V_139 -> V_201 [ V_16 ] ;
if ( ! F_229 ( V_19 , V_50 ) )
continue;
F_36 ( V_19 , L_83 , V_50 ) ;
F_230 ( V_19 , V_50 ,
V_397 ,
F_222 ) ;
V_2 -> V_384 = 1 ;
}
V_2 -> V_393 = V_2 -> V_383 ;
}
V_2 -> V_392 = V_139 -> V_144 &&
( V_2 -> V_383 || V_2 -> V_384 ) ;
V_2 -> V_375 = V_2 -> V_393 ;
V_2 -> V_371 = V_2 -> V_392 ;
if ( V_2 -> V_392 || V_2 -> V_393 ) {
V_193 = F_227 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
}
return 0 ;
}
static bool F_231 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_308 * V_309 ;
int V_16 ;
V_309 = & V_2 -> V_310 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_385 ; V_16 ++ ) {
V_2 -> V_386 [ V_16 ] . V_58 =
F_21 ( V_2 -> V_386 [ V_16 ] . V_46 ,
V_2 -> V_323 , V_309 -> V_312 ) ;
if ( V_2 -> V_386 [ V_16 ] . V_58 < 0 )
return false ;
}
for ( V_16 = 1 ; V_16 < V_2 -> V_385 ; V_16 ++ )
F_230 ( V_19 ,
V_2 -> V_386 [ V_16 ] . V_46 ,
V_398 ,
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
struct V_138 * V_139 = & V_2 -> V_140 ;
unsigned int V_405 ;
int V_16 , V_48 ;
if ( V_2 -> V_31 )
return 0 ;
V_405 = 0 ;
V_48 = 0 ;
for ( V_16 = 0 ; V_16 < V_139 -> V_182 ; V_16 ++ ) {
T_1 V_50 = V_139 -> V_183 [ V_16 ] . V_46 ;
unsigned int V_404 ;
V_404 = F_105 ( V_19 , V_50 ) ;
V_404 = F_153 ( V_404 ) ;
if ( V_405 & ( 1 << V_404 ) )
return 0 ;
switch ( V_404 ) {
case V_267 :
if ( V_139 -> V_183 [ V_16 ] . type != V_181 )
return 0 ;
break;
case V_406 :
return 0 ;
default:
if ( V_139 -> V_183 [ V_16 ] . type > V_180 )
return 0 ;
if ( ! V_2 -> V_32 &&
V_139 -> V_183 [ V_16 ] . type != V_181 )
return 0 ;
if ( ! F_229 ( V_19 , V_50 ) )
return 0 ;
break;
}
if ( V_48 >= V_407 )
return 0 ;
V_405 |= ( 1 << V_404 ) ;
V_2 -> V_386 [ V_48 ] . V_46 = V_50 ;
V_2 -> V_386 [ V_48 ] . V_404 = V_404 ;
V_48 ++ ;
}
if ( V_48 < 2 )
return 0 ;
V_2 -> V_385 = V_48 ;
F_234 ( V_2 -> V_386 , V_48 , sizeof( V_2 -> V_386 [ 0 ] ) ,
F_232 , NULL ) ;
if ( ! F_231 ( V_19 ) )
return 0 ;
V_2 -> V_345 = 1 ;
V_2 -> V_305 = 1 ;
V_2 -> V_259 [ 0 ] = V_2 -> V_386 [ 0 ] . V_58 ;
F_36 ( V_19 , L_84 ,
V_2 -> V_386 [ 0 ] . V_46 ,
V_2 -> V_386 [ 1 ] . V_46 ,
V_2 -> V_386 [ 2 ] . V_46 ) ;
return 0 ;
}
unsigned int F_235 ( struct V_18 * V_19 ,
T_1 V_50 ,
unsigned int V_408 )
{
if ( V_408 != V_105 || V_50 == V_19 -> V_409 )
return V_408 ;
if ( F_39 ( F_40 ( V_19 , V_50 ) ) >= V_410 )
return V_408 ;
if ( F_70 ( V_19 , V_50 ) )
return V_408 ;
return V_109 ;
}
static void F_236 ( struct V_18 * V_19 , T_1 V_292 )
{
int V_16 , V_51 ;
const T_1 * V_65 ;
bool V_411 ;
V_51 = F_38 ( V_19 , V_292 , & V_65 ) ;
V_411 = F_51 ( V_19 , V_292 , V_84 ) ;
for ( V_16 = 0 ; V_16 < V_51 ; V_16 ++ ) {
if ( V_411 )
F_62 ( V_19 , V_292 ,
V_84 , V_16 ,
0xff , V_97 ) ;
else if ( F_53 ( V_19 , V_65 [ V_16 ] , V_83 ) )
F_62 ( V_19 , V_65 [ V_16 ] ,
V_83 , 0 ,
0xff , V_97 ) ;
}
}
int F_237 ( struct V_18 * V_19 ,
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
V_2 -> V_204 = & V_412 ;
if ( ! V_2 -> V_205 )
V_2 -> V_205 = & V_413 ;
F_118 ( V_19 ) ;
if ( ! V_139 -> V_141 ) {
if ( V_139 -> V_354 || V_139 -> V_359 ) {
V_2 -> V_147 . V_245 = 2 ;
V_2 -> V_414 = 1 ;
goto V_415;
}
if ( ! V_139 -> V_182 && ! V_139 -> V_359 )
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
V_193 = F_120 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_145 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_123 ( V_19 , V_139 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_126 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_127 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_136 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_148 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_152 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_187 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_2 -> V_246 = V_2 -> V_206 ;
if ( V_139 -> V_152 != V_153 )
V_2 -> V_246 = F_144 ( V_2 -> V_246 ,
V_139 -> V_144 * 2 ) ;
if ( V_139 -> V_152 != V_155 )
V_2 -> V_246 = F_144 ( V_2 -> V_246 ,
V_139 -> V_143 * 2 ) ;
V_2 -> V_147 . V_245 = F_144 ( V_2 -> V_206 ,
V_2 -> V_246 ) ;
V_193 = F_228 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_182 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_233 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
if ( ! V_2 -> V_345 && V_2 -> V_45 &&
V_2 -> V_40 &&
V_2 -> V_310 . V_312 > 1 &&
F_12 ( V_19 , L_20 ) < 0 ) {
V_193 = F_183 ( V_19 , V_2 -> V_45 ,
V_327 , V_2 -> V_306 ,
L_67 , 0 ) ;
if ( V_193 < 0 )
return V_193 ;
}
V_193 = F_207 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_210 ( V_19 ) ;
if ( V_193 < 0 )
return V_193 ;
if ( V_2 -> V_258 &&
( V_2 -> V_345 || V_2 -> V_310 . V_312 == 1 ||
V_2 -> V_41 ) ) {
V_193 = F_176 ( V_19 , V_2 -> V_258 ) ;
if ( V_193 < 0 )
return V_193 ;
}
if ( V_2 -> V_41 ) {
if ( V_139 -> V_152 != V_153 ) {
V_193 = F_162 ( V_19 , V_139 -> V_141 ,
V_139 -> V_201 ) ;
if ( V_193 < 0 )
return V_193 ;
}
if ( V_139 -> V_152 != V_155 ) {
V_193 = F_162 ( V_19 , V_139 -> V_143 ,
V_139 -> V_202 ) ;
if ( V_193 < 0 )
return V_193 ;
}
}
if ( V_2 -> V_45 )
F_236 ( V_19 , V_2 -> V_45 ) ;
V_415:
F_211 ( V_19 ) ;
if ( V_2 -> V_42 )
V_19 -> V_416 = F_235 ;
if ( ! V_2 -> V_414 && V_2 -> V_417 ) {
V_193 = F_238 ( V_19 , V_2 -> V_417 ) ;
if ( V_193 < 0 )
return V_193 ;
}
return 1 ;
}
int F_239 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_193 ;
if ( V_2 -> V_3 . V_17 ) {
V_193 = F_240 ( V_19 , V_2 -> V_3 . V_14 ) ;
if ( V_193 < 0 )
return V_193 ;
}
if ( V_2 -> V_147 . V_356 ) {
V_193 = F_241 ( V_19 ,
V_2 -> V_147 . V_356 ,
V_2 -> V_147 . V_356 ,
V_2 -> V_418 [ 1 ] . V_419 ) ;
if ( V_193 < 0 )
return V_193 ;
if ( ! V_2 -> V_414 ) {
V_193 = F_242 ( V_19 ,
& V_2 -> V_147 ) ;
if ( V_193 < 0 )
return V_193 ;
V_2 -> V_147 . V_420 = 1 ;
}
}
if ( V_2 -> V_361 ) {
V_193 = F_243 ( V_19 , V_2 -> V_361 ) ;
if ( V_193 < 0 )
return V_193 ;
}
if ( ! V_2 -> V_414 &&
! F_244 ( V_19 , L_85 ) ) {
V_193 = F_245 ( V_19 , L_85 ,
V_2 -> V_219 , V_421 ,
L_86 ) ;
if ( V_193 < 0 )
return V_193 ;
}
if ( ! V_2 -> V_414 &&
! F_244 ( V_19 , L_87 ) ) {
V_193 = F_246 ( V_19 , L_87 ,
NULL , V_421 ,
L_88 ,
true , & V_2 -> V_145 . V_380 ) ;
if ( V_193 < 0 )
return V_193 ;
if ( V_2 -> V_145 . V_146 ) {
F_247 ( V_19 , & V_2 -> V_145 ,
V_2 -> V_422 ) ;
F_248 ( & V_2 -> V_145 ) ;
}
}
F_7 ( V_2 ) ;
V_193 = F_249 ( V_19 , & V_2 -> V_140 ) ;
if ( V_193 < 0 )
return V_193 ;
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
int V_193 ;
F_132 ( & V_2 -> V_9 ) ;
V_193 = F_253 ( V_19 ,
& V_2 -> V_147 , V_426 ,
V_424 ) ;
if ( ! V_193 ) {
V_2 -> V_231 |= 1 << V_430 ;
F_250 ( V_424 , V_19 , V_426 ,
V_431 ) ;
}
F_135 ( & V_2 -> V_9 ) ;
return V_193 ;
}
static int F_254 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
unsigned int V_432 ,
unsigned int V_433 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_193 ;
V_193 = F_255 ( V_19 , & V_2 -> V_147 ,
V_432 , V_433 , V_426 ) ;
if ( ! V_193 )
F_250 ( V_424 , V_19 , V_426 ,
V_434 ) ;
return V_193 ;
}
static int F_256 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_193 ;
V_193 = F_257 ( V_19 , & V_2 -> V_147 ) ;
if ( ! V_193 )
F_250 ( V_424 , V_19 , V_426 ,
V_435 ) ;
return V_193 ;
}
static int F_258 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_132 ( & V_2 -> V_9 ) ;
V_2 -> V_231 &= ~ ( 1 << V_430 ) ;
F_250 ( V_424 , V_19 , V_426 ,
V_436 ) ;
F_135 ( & V_2 -> V_9 ) ;
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
int V_193 = 0 ;
F_132 ( & V_2 -> V_9 ) ;
if ( ! V_2 -> V_228 )
V_193 = - V_232 ;
else
V_2 -> V_231 |= 1 << V_437 ;
F_250 ( V_424 , V_19 , V_426 ,
V_431 ) ;
F_135 ( & V_2 -> V_9 ) ;
return V_193 ;
}
static int F_266 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_132 ( & V_2 -> V_9 ) ;
V_2 -> V_231 &= ~ ( 1 << V_437 ) ;
F_250 ( V_424 , V_19 , V_426 ,
V_436 ) ;
F_135 ( & V_2 -> V_9 ) ;
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
return F_270 ( V_19 , & V_2 -> V_147 ) ;
}
static int F_271 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
unsigned int V_432 ,
unsigned int V_433 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_272 ( V_19 , & V_2 -> V_147 ,
V_432 , V_433 , V_426 ) ;
}
static int F_273 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_274 ( V_19 , & V_2 -> V_147 ) ;
}
static int F_275 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_276 ( V_19 , & V_2 -> V_147 ) ;
}
static int F_277 ( struct V_423 * V_424 ,
struct V_18 * V_19 ,
unsigned int V_432 ,
unsigned int V_433 ,
struct V_425 * V_426 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_261 ( V_19 , V_2 -> V_303 [ V_426 -> V_438 + 1 ] ,
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
V_2 -> V_303 [ V_426 -> V_438 + 1 ] ) ;
F_251 ( V_424 , V_19 , V_426 ,
V_435 ) ;
return 0 ;
}
static bool F_212 ( struct V_18 * V_19 , int V_439 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_440 = V_2 -> V_303 [ V_2 -> V_313 [ V_439 ] ] ;
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
V_2 -> V_441 = V_2 -> V_303 [ V_2 -> V_313 [ V_2 -> V_259 [ 0 ] ] ] ;
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
static void F_282 ( char * V_444 , T_3 V_445 , const char * V_122 ,
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
F_35 ( V_444 , V_122 , V_445 ) ;
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
L_89 , V_19 -> V_446 ) ;
V_449 -> V_10 = V_2 -> V_454 ;
if ( V_2 -> V_147 . V_148 > 0 ) {
V_447 = V_2 -> V_455 ;
if ( ! V_447 )
V_447 = & V_456 ;
V_449 -> V_457 [ V_458 ] = * V_447 ;
V_449 -> V_457 [ V_458 ] . V_50 = V_2 -> V_147 . V_194 [ 0 ] ;
V_449 -> V_457 [ V_458 ] . V_459 =
V_2 -> V_147 . V_245 ;
if ( V_2 -> V_140 . V_152 == V_153 &&
V_2 -> V_140 . V_141 == 2 )
V_449 -> V_457 [ V_458 ] . V_460 =
V_461 ;
}
if ( V_2 -> V_305 ) {
V_447 = V_2 -> V_462 ;
if ( ! V_447 ) {
if ( V_2 -> V_314 )
V_447 = & V_463 ;
else
V_447 = & V_464 ;
}
V_449 -> V_457 [ V_465 ] = * V_447 ;
V_449 -> V_457 [ V_465 ] . V_50 = V_2 -> V_303 [ 0 ] ;
}
V_453:
if ( V_2 -> V_147 . V_356 || V_2 -> V_361 ) {
F_282 ( V_2 -> V_466 ,
sizeof( V_2 -> V_466 ) ,
L_90 , V_19 -> V_446 ) ;
V_19 -> V_451 = 2 ;
V_19 -> V_358 = V_2 -> V_147 . V_358 ;
V_449 = V_2 -> V_418 + 1 ;
V_449 -> V_10 = V_2 -> V_466 ;
if ( V_2 -> V_357 )
V_449 -> V_419 = V_2 -> V_357 ;
else
V_449 -> V_419 = V_467 ;
if ( V_2 -> V_147 . V_356 ) {
V_447 = V_2 -> V_468 ;
if ( ! V_447 )
V_447 = & V_469 ;
V_449 -> V_457 [ V_458 ] = * V_447 ;
V_449 -> V_457 [ V_458 ] . V_50 = V_2 -> V_147 . V_356 ;
}
if ( V_2 -> V_361 ) {
V_447 = V_2 -> V_470 ;
if ( ! V_447 )
V_447 = & V_471 ;
V_449 -> V_457 [ V_465 ] = * V_447 ;
V_449 -> V_457 [ V_465 ] . V_50 = V_2 -> V_361 ;
}
}
if ( V_2 -> V_414 )
return 0 ;
V_450 = ( V_2 -> V_305 > 1 ) &&
! V_2 -> V_314 && ! V_2 -> V_345 ;
if ( V_2 -> V_237 || V_450 ) {
F_282 ( V_2 -> V_472 ,
sizeof( V_2 -> V_472 ) ,
L_91 , V_19 -> V_446 ) ;
V_19 -> V_451 = 3 ;
V_449 = V_2 -> V_418 + 2 ;
V_449 -> V_10 = V_2 -> V_472 ;
if ( V_2 -> V_237 ) {
V_447 = V_2 -> V_473 ;
if ( ! V_447 )
V_447 = & V_474 ;
V_449 -> V_457 [ V_458 ] = * V_447 ;
V_449 -> V_457 [ V_458 ] . V_50 =
V_2 -> V_237 ;
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
V_2 -> V_303 [ 1 ] ;
V_449 -> V_457 [ V_465 ] . V_478 =
V_2 -> V_305 - 1 ;
} else {
V_449 -> V_457 [ V_465 ] =
V_475 ;
V_449 -> V_457 [ V_465 ] . V_50 = 0 ;
}
}
return 0 ;
}
static void F_285 ( struct V_18 * V_19 , int V_115 )
{
struct V_6 * V_52 ;
T_1 V_46 ;
V_52 = F_27 ( V_19 , V_115 ) ;
if ( ! V_52 || ! V_52 -> V_53 )
return;
V_46 = V_52 -> V_52 [ V_52 -> V_53 - 1 ] ;
F_14 ( V_19 , V_46 ) ;
F_65 ( V_19 , V_52 , V_52 -> V_90 ,
F_140 ( V_19 -> V_2 ) ) ;
F_73 ( V_19 , V_46 , V_52 -> V_90 ) ;
}
static void F_286 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_140 . V_141 ; V_16 ++ )
F_285 ( V_19 , V_2 -> V_187 [ V_16 ] ) ;
}
static void F_287 ( struct V_18 * V_19 , int V_163 , int * V_5 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_163 ; V_16 ++ )
F_285 ( V_19 , V_5 [ V_16 ] ) ;
}
static void F_288 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_140 . V_152 != V_155 )
F_287 ( V_19 , V_2 -> V_140 . V_143 , V_2 -> V_154 ) ;
if ( V_2 -> V_140 . V_152 != V_153 )
F_287 ( V_19 , V_2 -> V_140 . V_144 ,
V_2 -> V_156 ) ;
}
static void F_289 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_142 ; V_16 ++ ) {
T_1 V_46 = V_2 -> V_161 [ V_16 ] . V_46 ;
struct V_6 * V_52 ;
V_52 = F_139 ( V_19 , V_16 ) ;
if ( ! V_52 )
continue;
if ( ! V_2 -> V_161 [ V_16 ] . V_244 )
V_2 -> V_161 [ V_16 ] . V_244 =
F_16 ( V_19 , V_46 ) ;
F_65 ( V_19 , V_52 , V_52 -> V_90 ,
F_140 ( V_2 ) ) ;
}
}
static void F_290 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_235 )
return;
F_133 ( V_19 , V_2 -> V_236 , V_2 -> V_187 [ 0 ] ,
V_2 -> V_195 [ 0 ] ,
V_2 -> V_140 . V_152 ) ;
F_133 ( V_19 , V_2 -> V_236 , V_2 -> V_154 [ 0 ] ,
V_2 -> V_195 [ 1 ] ,
V_155 ) ;
F_133 ( V_19 , V_2 -> V_236 , V_2 -> V_156 [ 0 ] ,
V_2 -> V_195 [ 2 ] ,
V_153 ) ;
}
static void F_291 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_138 * V_139 = & V_2 -> V_140 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_139 -> V_182 ; V_16 ++ ) {
T_1 V_50 = V_139 -> V_183 [ V_16 ] . V_46 ;
if ( F_180 ( V_19 , V_50 ) )
F_14 ( V_19 , V_50 ) ;
if ( V_2 -> V_45 ) {
F_75 ( V_19 , V_2 -> V_198 [ V_16 ] ) ;
F_75 ( V_19 , V_2 -> V_302 ) ;
}
}
}
static void F_292 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_308 * V_309 = & V_2 -> V_310 ;
struct V_6 * V_52 ;
int V_16 , V_321 , V_51 ;
if ( V_2 -> V_314 )
V_51 = 1 ;
else
V_51 = V_2 -> V_305 ;
for ( V_321 = 0 ; V_321 < V_51 ; V_321 ++ ) {
for ( V_16 = 0 ; V_16 < V_309 -> V_312 ; V_16 ++ ) {
V_52 = F_188 ( V_19 , V_321 , V_16 ) ;
if ( V_52 ) {
bool V_90 = V_52 -> V_90 ;
if ( V_16 == V_2 -> V_259 [ V_321 ] )
V_90 = true ;
F_65 ( V_19 , V_52 , V_90 , false ) ;
}
}
if ( V_2 -> V_43 )
F_149 ( V_19 , V_321 , true ) ;
}
if ( V_2 -> V_334 )
V_2 -> V_334 ( V_19 , NULL , NULL ) ;
}
static void F_293 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_46 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_140 . V_354 ; V_16 ++ )
F_285 ( V_19 , V_2 -> V_196 [ V_16 ] ) ;
V_46 = V_2 -> V_140 . V_359 ;
if ( V_46 ) {
F_14 ( V_19 , V_46 ) ;
F_75 ( V_19 , V_2 -> V_199 ) ;
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
F_68 ( V_19 , V_50 , 0 ,
V_481 , 0 ) ;
}
}
int F_296 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_482 )
V_2 -> V_482 ( V_19 ) ;
F_297 ( V_19 ) ;
V_19 -> V_333 = 1 ;
F_286 ( V_19 ) ;
F_288 ( V_19 ) ;
F_289 ( V_19 ) ;
F_290 ( V_19 ) ;
F_291 ( V_19 ) ;
F_292 ( V_19 ) ;
F_293 ( V_19 ) ;
F_294 ( V_19 ) ;
F_142 ( V_19 ) ;
F_196 ( V_19 ) ;
if ( V_2 -> V_145 . V_380 && V_2 -> V_145 . V_146 )
F_248 ( & V_2 -> V_145 ) ;
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
return F_302 ( V_19 , & V_2 -> V_293 , V_50 ) ;
}
int F_303 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_193 ;
V_2 = F_304 ( sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 )
return - V_124 ;
F_1 ( V_2 ) ;
V_19 -> V_2 = V_2 ;
V_193 = F_305 ( V_19 , & V_2 -> V_140 , NULL , 0 ) ;
if ( V_193 < 0 )
return V_193 ;
V_193 = F_237 ( V_19 , & V_2 -> V_140 ) ;
if ( V_193 < 0 )
goto error;
V_19 -> V_484 = V_485 ;
return 0 ;
error:
F_299 ( V_19 ) ;
return V_193 ;
}
