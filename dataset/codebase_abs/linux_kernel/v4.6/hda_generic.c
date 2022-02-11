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
V_19 -> V_30 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_11 ) ;
if ( V_20 >= 0 )
V_2 -> V_31 = ! V_20 ;
V_20 = F_12 ( V_19 , L_12 ) ;
if ( V_20 >= 0 )
V_2 -> V_32 = ! V_20 ;
V_20 = F_12 ( V_19 , L_13 ) ;
if ( V_20 >= 0 )
V_2 -> V_33 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_14 ) ;
if ( V_20 >= 0 )
V_2 -> V_34 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_15 ) ;
if ( V_20 >= 0 )
V_2 -> V_35 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_16 ) ;
if ( V_20 >= 0 )
V_2 -> V_36 = ! V_20 ;
V_20 = F_12 ( V_19 , L_17 ) ;
if ( V_20 >= 0 )
V_2 -> V_37 = ! V_20 ;
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
V_2 -> V_42 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_23 ) ;
if ( V_20 >= 0 )
V_2 -> V_42 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_24 ) ;
if ( V_20 >= 0 )
V_2 -> V_42 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_25 ) ;
if ( V_20 >= 0 )
V_2 -> V_43 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_26 ) ;
if ( V_20 >= 0 )
V_2 -> V_44 = ! ! V_20 ;
V_20 = F_12 ( V_19 , L_27 ) ;
if ( V_20 >= 0 )
V_2 -> V_45 = ! V_20 ;
if ( ! F_13 ( V_19 , L_28 , & V_20 ) )
V_2 -> V_46 = V_20 ;
}
static inline void F_14 ( struct V_18 * V_19 , T_1 V_47 )
{
F_15 ( V_19 , V_47 , F_16 ( V_19 , V_47 ) ) ;
}
static void F_17 ( struct V_18 * V_19 , T_1 V_47 ,
unsigned int V_20 , bool V_48 )
{
if ( ! V_47 )
return;
V_20 = F_18 ( V_19 , V_47 , V_20 ) ;
F_19 ( V_19 , V_47 , V_20 ) ;
if ( V_48 )
F_15 ( V_19 , V_47 , V_20 ) ;
}
static void F_20 ( struct V_18 * V_19 , int V_49 ,
T_1 * V_50 , unsigned int V_20 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_49 ; V_16 ++ )
F_17 ( V_19 , V_50 [ V_16 ] , V_20 , false ) ;
}
static int F_21 ( T_1 V_51 , const T_1 * V_14 , int V_52 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_52 ; V_16 ++ )
if ( V_14 [ V_16 ] == V_51 )
return V_16 ;
return - 1 ;
}
static bool F_22 ( struct V_6 * V_53 , T_1 V_51 )
{
return F_21 ( V_51 , V_53 -> V_53 , V_53 -> V_54 ) >= 0 ;
}
static struct V_6 * F_23 ( struct V_18 * V_19 ,
T_1 V_55 , T_1 V_56 ,
int V_57 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 . V_17 ; V_16 ++ ) {
struct V_6 * V_53 = F_24 ( & V_2 -> V_5 , V_16 ) ;
if ( V_53 -> V_54 <= 0 )
continue;
if ( ( ! V_55 || V_53 -> V_53 [ 0 ] == V_55 ) &&
( ! V_56 || V_53 -> V_53 [ V_53 -> V_54 - 1 ] == V_56 ) ) {
if ( ! V_57 ||
( V_57 > 0 && F_22 ( V_53 , V_57 ) ) ||
( V_57 < 0 && ! F_22 ( V_53 , V_57 ) ) )
return V_53 ;
}
}
return NULL ;
}
int F_25 ( struct V_18 * V_19 , struct V_6 * V_53 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_58 = V_2 -> V_5 . V_14 ;
T_2 V_59 ;
if ( ! V_2 -> V_5 . V_17 )
return 0 ;
V_59 = V_53 - V_58 ;
if ( V_59 < 0 || V_59 >= V_2 -> V_5 . V_17 )
return 0 ;
return V_59 + 1 ;
}
struct V_6 * F_26 ( struct V_18 * V_19 , int V_59 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_59 <= 0 || V_59 > V_2 -> V_5 . V_17 )
return NULL ;
return F_24 ( & V_2 -> V_5 , V_59 - 1 ) ;
}
static bool F_27 ( struct V_18 * V_19 , T_1 V_51 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 . V_17 ; V_16 ++ ) {
struct V_6 * V_53 = F_24 ( & V_2 -> V_5 , V_16 ) ;
if ( V_53 -> V_53 [ 0 ] == V_51 )
return true ;
}
return false ;
}
static bool F_28 ( struct V_18 * V_19 ,
T_1 V_55 , T_1 V_56 )
{
if ( ! V_55 || ! V_56 )
return false ;
return F_29 ( V_19 , V_56 , V_55 , true ) >= 0 ;
}
static bool F_30 ( struct V_18 * V_19 , unsigned int V_20 , int type )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
V_20 &= V_60 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 . V_17 ; V_16 ++ ) {
struct V_6 * V_53 = F_24 ( & V_2 -> V_5 , V_16 ) ;
if ( ( V_53 -> V_61 [ type ] & V_60 ) == V_20 )
return true ;
}
return false ;
}
static bool F_31 ( struct V_18 * V_19 , T_1 V_51 ,
int V_62 , int V_59 , int type )
{
unsigned int V_20 = F_32 ( V_51 , 3 , V_59 , V_62 ) ;
return F_30 ( V_19 , V_20 , type ) ;
}
static void F_33 ( struct V_18 * V_19 ,
const char * V_63 , struct V_6 * V_53 )
{
char V_64 [ 40 ] ;
char * V_65 = V_64 ;
int V_16 ;
* V_65 = 0 ;
for ( V_16 = 0 ; V_16 < V_53 -> V_54 ; V_16 ++ )
V_65 += F_34 ( V_65 , sizeof( V_64 ) - ( V_65 - V_64 ) , L_29 ,
V_65 != V_64 ? L_30 : L_31 ,
V_53 -> V_53 [ V_16 ] ) ;
F_35 ( V_19 , L_32 , V_63 , V_53 -> V_54 , V_64 ) ;
}
static bool F_36 ( struct V_18 * V_19 ,
T_1 V_55 , T_1 V_56 ,
int V_57 , struct V_6 * V_53 ,
int V_54 )
{
const T_1 * V_66 ;
int V_16 , V_52 ;
if ( V_56 == V_57 )
V_57 = 0 ;
else if ( V_56 == ( T_1 ) ( - V_57 ) )
return false ;
V_52 = F_37 ( V_19 , V_56 , & V_66 ) ;
for ( V_16 = 0 ; V_16 < V_52 ; V_16 ++ ) {
if ( V_66 [ V_16 ] != V_55 ) {
if ( V_55 ||
F_38 ( F_39 ( V_19 , V_66 [ V_16 ] ) ) != V_67 ||
F_27 ( V_19 , V_66 [ V_16 ] ) )
continue;
}
if ( V_57 <= 0 )
goto V_68;
}
if ( V_54 >= V_69 )
return false ;
for ( V_16 = 0 ; V_16 < V_52 ; V_16 ++ ) {
unsigned int type ;
type = F_38 ( F_39 ( V_19 , V_66 [ V_16 ] ) ) ;
if ( type == V_67 || type == V_70 ||
type == V_71 )
continue;
if ( F_36 ( V_19 , V_55 , V_66 [ V_16 ] ,
V_57 , V_53 , V_54 + 1 ) )
goto V_68;
}
return false ;
V_68:
V_53 -> V_53 [ V_53 -> V_54 ] = V_66 [ V_16 ] ;
V_53 -> V_59 [ V_53 -> V_54 + 1 ] = V_16 ;
if ( V_52 > 1 && F_38 ( F_39 ( V_19 , V_56 ) ) != V_72 )
V_53 -> V_73 [ V_53 -> V_54 + 1 ] = 1 ;
V_53 -> V_54 ++ ;
return true ;
}
static bool F_40 ( struct V_18 * V_19 , T_1 V_55 ,
T_1 V_56 , int V_57 ,
struct V_6 * V_53 )
{
if ( F_36 ( V_19 , V_55 , V_56 , V_57 , V_53 , 1 ) ) {
V_53 -> V_53 [ V_53 -> V_54 ] = V_56 ;
V_53 -> V_54 ++ ;
return true ;
}
return false ;
}
struct V_6 *
F_41 ( struct V_18 * V_19 , T_1 V_55 ,
T_1 V_56 , int V_57 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_53 ;
if ( V_55 && V_56 && ! F_28 ( V_19 , V_55 , V_56 ) )
return NULL ;
V_53 = F_23 ( V_19 , V_55 , V_56 , V_57 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_5 ( & V_2 -> V_5 ) ;
if ( ! V_53 )
return NULL ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
if ( F_40 ( V_19 , V_55 , V_56 , V_57 , V_53 ) )
return V_53 ;
V_2 -> V_5 . V_17 -- ;
return NULL ;
}
static void F_42 ( struct V_18 * V_19 , int V_59 )
{
struct V_6 * V_53 = F_26 ( V_19 , V_59 ) ;
if ( ! V_53 )
return;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
}
static T_1 F_43 ( struct V_18 * V_19 , T_1 V_47 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const T_1 * V_14 = V_2 -> V_74 ;
if ( ! V_14 )
return 0 ;
for (; * V_14 ; V_14 += 2 )
if ( * V_14 == V_47 )
return V_14 [ 1 ] ;
return 0 ;
}
static T_1 F_44 ( struct V_18 * V_19 , T_1 V_47 ,
bool V_75 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_76 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_77 ; V_16 ++ ) {
T_1 V_51 = V_2 -> V_78 [ V_16 ] ;
if ( ! V_51 || F_27 ( V_19 , V_51 ) )
continue;
V_76 = ! ! ( F_39 ( V_19 , V_51 ) & V_79 ) ;
if ( V_75 != V_76 )
continue;
if ( F_28 ( V_19 , V_51 , V_47 ) )
return V_51 ;
}
return 0 ;
}
static unsigned int F_45 ( unsigned int V_20 , unsigned int V_80 )
{
V_20 &= ~ ( 0x3U << 16 ) ;
V_20 |= V_80 << 16 ;
return V_20 ;
}
static bool F_46 ( struct V_18 * V_19 , T_1 V_81 ,
T_1 V_82 , int V_62 )
{
if ( ! ( F_39 ( V_19 , V_81 ) & ( 1 << ( V_62 + 1 ) ) ) )
return ! ( F_39 ( V_19 , V_82 ) & ( 1 << ( V_62 + 1 ) ) ) ;
return ( F_47 ( V_19 , V_81 , V_62 ) ==
F_47 ( V_19 , V_82 , V_62 ) ) ;
}
static T_1 F_48 ( struct V_18 * V_19 ,
struct V_6 * V_53 )
{
int V_16 ;
for ( V_16 = V_53 -> V_54 - 1 ; V_16 >= 0 ; V_16 -- ) {
if ( F_49 ( V_19 , V_53 -> V_53 [ V_16 ] , V_83 ) )
return V_53 -> V_53 [ V_16 ] ;
if ( V_16 != V_53 -> V_54 - 1 && V_16 != 0 &&
F_49 ( V_19 , V_53 -> V_53 [ V_16 ] , V_84 ) )
return V_53 -> V_53 [ V_16 ] ;
}
return 0 ;
}
static T_1 F_50 ( struct V_18 * V_19 ,
struct V_6 * V_53 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = V_53 -> V_54 - 1 ; V_16 >= 0 ; V_16 -- ) {
T_1 V_51 = V_53 -> V_53 [ V_16 ] ;
if ( ( V_2 -> V_85 >> V_51 ) & 1 )
continue;
if ( F_51 ( V_19 , V_51 , V_83 ) )
return V_51 ;
}
return 0 ;
}
static bool F_52 ( struct V_18 * V_19 , struct V_6 * V_53 , int V_59 )
{
T_1 V_51 = V_53 -> V_53 [ V_59 ] ;
unsigned int V_86 = F_39 ( V_19 , V_51 ) ;
unsigned int type = F_38 ( V_86 ) ;
if ( ! ( V_86 & V_87 ) )
return false ;
if ( type == V_71 && V_59 > 0 )
return false ;
return true ;
}
static bool F_53 ( struct V_18 * V_19 , struct V_6 * V_53 , int V_59 )
{
T_1 V_51 = V_53 -> V_53 [ V_59 ] ;
unsigned int V_86 = F_39 ( V_19 , V_51 ) ;
unsigned int type = F_38 ( V_86 ) ;
if ( ! ( V_86 & V_88 ) )
return false ;
if ( type == V_71 && ! V_59 )
return false ;
return true ;
}
static bool F_54 ( struct V_18 * V_19 , T_1 V_51 ,
unsigned int V_62 , unsigned int V_59 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int type = F_38 ( F_39 ( V_19 , V_51 ) ) ;
int V_16 , V_89 ;
if ( V_51 == V_19 -> V_90 . V_91 )
return true ;
for ( V_89 = 0 ; V_89 < V_2 -> V_5 . V_17 ; V_89 ++ ) {
struct V_6 * V_53 = F_24 ( & V_2 -> V_5 , V_89 ) ;
if ( ! V_53 -> V_92 )
continue;
if ( V_19 -> V_30 ) {
if ( ! V_53 -> V_93 )
continue;
if ( ! ( V_53 -> V_94 || V_53 -> V_95 ) &&
type != V_67 && type != V_70 )
continue;
}
for ( V_16 = 0 ; V_16 < V_53 -> V_54 ; V_16 ++ ) {
if ( V_53 -> V_53 [ V_16 ] == V_51 ) {
if ( V_62 == V_83 || V_59 == - 1 ||
V_53 -> V_59 [ V_16 ] == V_59 )
return true ;
break;
}
}
}
return false ;
}
static int F_55 ( struct V_18 * V_19 , T_1 V_51 ,
int V_62 , unsigned int V_86 , bool V_96 )
{
unsigned int V_20 = 0 ;
if ( V_86 & V_97 ) {
if ( V_96 )
V_20 = ( V_86 & V_98 ) >> V_99 ;
}
if ( V_86 & ( V_100 | V_101 ) ) {
if ( ! V_96 )
V_20 |= V_102 ;
}
return V_20 ;
}
static bool F_56 ( struct V_18 * V_19 , T_1 V_51 , int V_62 )
{
unsigned int V_103 = F_39 ( V_19 , V_51 ) ;
T_1 V_66 ;
if ( V_103 & V_104 )
return true ;
if ( V_62 != V_84 || F_38 ( V_103 ) != V_72 )
return false ;
if ( F_57 ( V_19 , V_51 ) != 1 )
return false ;
if ( F_58 ( V_19 , V_51 , & V_66 , 1 ) < 0 )
return false ;
return ! ! ( F_39 ( V_19 , V_66 ) & V_104 ) ;
}
static void F_59 ( struct V_18 * V_19 , T_1 V_51 , int V_62 , int V_59 )
{
unsigned int V_86 = F_47 ( V_19 , V_51 , V_62 ) ;
int V_20 = F_55 ( V_19 , V_51 , V_62 , V_86 , false ) ;
if ( F_56 ( V_19 , V_51 , V_62 ) )
F_60 ( V_19 , V_51 , V_62 , V_59 , 0xff , V_20 ) ;
else
F_61 ( V_19 , V_51 , 0 , V_62 , V_59 , 0xff , V_20 ) ;
}
static int F_62 ( struct V_18 * V_19 , T_1 V_51 , int V_62 , int V_59 ,
unsigned int V_105 , unsigned int V_20 )
{
if ( F_56 ( V_19 , V_51 , V_62 ) )
return F_63 ( V_19 , V_51 , V_62 , V_59 ,
V_105 , V_20 ) ;
else
return F_64 ( V_19 , V_51 , 0 , V_62 , V_59 ,
V_105 , V_20 ) ;
}
static unsigned int F_65 ( struct V_18 * V_19 ,
T_1 V_51 , int V_62 , int V_59 ,
unsigned int V_86 )
{
unsigned int V_105 = 0xff ;
if ( V_86 & ( V_100 | V_101 ) ) {
if ( F_31 ( V_19 , V_51 , V_62 , V_59 , V_106 ) )
V_105 &= ~ 0x80 ;
}
if ( V_86 & V_97 ) {
if ( F_31 ( V_19 , V_51 , V_62 , V_59 , V_107 ) ||
F_31 ( V_19 , V_51 , V_62 , V_59 , V_108 ) )
V_105 &= ~ 0x7f ;
}
return V_105 ;
}
static void F_66 ( struct V_18 * V_19 , T_1 V_51 , int V_62 ,
int V_59 , int V_109 , bool V_96 )
{
unsigned int V_86 ;
unsigned int V_105 , V_20 ;
V_86 = F_47 ( V_19 , V_51 , V_62 ) ;
V_20 = F_55 ( V_19 , V_51 , V_62 , V_86 , V_96 ) ;
V_105 = F_65 ( V_19 , V_51 , V_62 , V_109 , V_86 ) ;
if ( ! V_105 )
return;
V_20 &= V_105 ;
F_62 ( V_19 , V_51 , V_62 , V_59 , V_105 , V_20 ) ;
}
static void F_67 ( struct V_18 * V_19 , T_1 V_51 ,
int V_62 , int V_59 , int V_109 ,
bool V_96 )
{
if ( ! V_96 && F_54 ( V_19 , V_51 , V_62 , V_109 ) )
return;
F_66 ( V_19 , V_51 , V_62 , V_59 , V_109 , V_96 ) ;
}
static void F_68 ( struct V_18 * V_19 , struct V_6 * V_53 ,
int V_16 , bool V_96 )
{
T_1 V_51 = V_53 -> V_53 [ V_16 ] ;
F_59 ( V_19 , V_51 , V_83 , 0 ) ;
F_67 ( V_19 , V_51 , V_83 , 0 , 0 , V_96 ) ;
}
static void F_69 ( struct V_18 * V_19 , struct V_6 * V_53 ,
int V_16 , bool V_96 , bool V_110 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const T_1 * V_66 ;
int V_89 , V_52 , V_59 ;
int type ;
T_1 V_51 = V_53 -> V_53 [ V_16 ] ;
V_52 = F_37 ( V_19 , V_51 , & V_66 ) ;
type = F_38 ( F_39 ( V_19 , V_51 ) ) ;
if ( type == V_71 ||
( type == V_70 && V_19 -> V_29 ) ) {
V_52 = 1 ;
V_59 = 0 ;
} else
V_59 = V_53 -> V_59 [ V_16 ] ;
for ( V_89 = 0 ; V_89 < V_52 ; V_89 ++ )
F_59 ( V_19 , V_51 , V_84 , V_89 ) ;
for ( V_89 = 0 ; V_89 < V_52 ; V_89 ++ ) {
if ( V_89 != V_59 ) {
if ( V_66 [ V_89 ] != V_2 -> V_111 )
continue;
if ( ! V_110 ) {
F_66 ( V_19 , V_51 , V_84 , V_89 , V_89 , false ) ;
continue;
}
}
F_67 ( V_19 , V_51 , V_84 , V_89 , V_59 , V_96 ) ;
}
}
static T_1 F_70 ( struct V_18 * V_19 ,
struct V_6 * V_53 ,
bool V_112 )
{
T_1 V_51 , V_113 = 0 ;
int V_16 , V_114 , V_115 ;
for ( V_16 = 0 ; V_16 < V_53 -> V_54 ; V_16 ++ ) {
V_51 = V_53 -> V_53 [ V_16 ] ;
if ( ! ( F_39 ( V_19 , V_51 ) & V_116 ) )
continue;
if ( V_51 == V_19 -> V_90 . V_91 )
continue;
if ( ! V_112 || F_71 ( V_19 , V_51 ) )
V_114 = V_117 ;
else
V_114 = V_118 ;
V_115 = F_72 ( V_19 , V_51 , 0 ,
V_119 , 0 ) ;
if ( V_115 != ( V_114 | ( V_114 << 4 ) ) ) {
F_73 ( V_19 , V_51 , 0 ,
V_120 , V_114 ) ;
V_113 = V_51 ;
#if 0
if (state == AC_PWRST_D0)
snd_hdac_regmap_sync_node(&codec->core, nid);
#endif
}
}
return V_113 ;
}
static void F_74 ( struct V_18 * V_19 , T_1 V_51 )
{
if ( V_51 ) {
F_75 ( 10 ) ;
F_72 ( V_19 , V_51 , 0 , V_119 , 0 ) ;
}
}
void F_76 ( struct V_18 * V_19 , struct V_6 * V_53 ,
bool V_96 , bool V_110 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
V_53 -> V_92 = V_96 ;
if ( V_96 && ( V_2 -> V_43 || V_19 -> V_30 ) )
F_70 ( V_19 , V_53 , V_19 -> V_30 ) ;
for ( V_16 = V_53 -> V_54 - 1 ; V_16 >= 0 ; V_16 -- ) {
T_1 V_51 = V_53 -> V_53 [ V_16 ] ;
if ( V_96 && V_53 -> V_73 [ V_16 ] )
F_77 ( V_19 , V_51 , 0 ,
V_121 ,
V_53 -> V_59 [ V_16 ] ) ;
if ( F_52 ( V_19 , V_53 , V_16 ) )
F_69 ( V_19 , V_53 , V_16 , V_96 , V_110 ) ;
if ( F_53 ( V_19 , V_53 , V_16 ) )
F_68 ( V_19 , V_53 , V_16 , V_96 ) ;
}
}
static void F_78 ( struct V_18 * V_19 , struct V_6 * V_53 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! ( V_2 -> V_43 || V_19 -> V_30 ) || V_53 -> V_92 )
return;
F_74 ( V_19 , F_70 ( V_19 , V_53 , true ) ) ;
}
static void F_79 ( struct V_18 * V_19 , T_1 V_47 , bool V_96 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_122 ||
! ( F_80 ( V_19 , V_47 ) & V_123 ) )
return;
if ( V_2 -> V_124 && ! V_96 )
return;
if ( V_19 -> V_24 )
V_96 = ! V_96 ;
F_77 ( V_19 , V_47 , 0 ,
V_125 ,
V_96 ? 0x02 : 0x00 ) ;
}
static void F_81 ( struct V_18 * V_19 , int V_126 )
{
struct V_6 * V_53 = F_26 ( V_19 , V_126 ) ;
if ( V_53 )
F_76 ( V_19 , V_53 , V_53 -> V_92 , false ) ;
}
static struct V_4 *
F_82 ( struct V_1 * V_2 , int type , const char * V_10 ,
int V_127 , unsigned long V_20 )
{
struct V_4 * V_12 ;
V_12 = F_4 ( V_2 , V_10 , & V_128 [ type ] ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_129 = V_127 ;
if ( F_83 ( V_20 ) )
V_12 -> V_130 = V_131 ;
V_12 -> V_132 = V_20 ;
return V_12 ;
}
static int F_84 ( struct V_1 * V_2 , int type ,
const char * V_63 , const char * V_62 ,
const char * V_133 , int V_127 , unsigned long V_20 )
{
char V_10 [ V_134 ] ;
snprintf ( V_10 , sizeof( V_10 ) , L_33 , V_63 , V_62 , V_133 ) ;
if ( ! F_82 ( V_2 , type , V_10 , V_127 , V_20 ) )
return - V_135 ;
return 0 ;
}
static int F_85 ( struct V_18 * V_19 , const char * V_63 , int V_127 ,
unsigned int V_80 , struct V_6 * V_53 )
{
unsigned int V_20 ;
if ( ! V_53 )
return 0 ;
V_20 = V_53 -> V_61 [ V_107 ] ;
if ( ! V_20 )
return 0 ;
V_20 = F_45 ( V_20 , V_80 ) ;
return F_86 ( V_19 -> V_2 , V_136 , V_63 , V_127 , V_20 ) ;
}
static int F_87 ( struct V_18 * V_19 , struct V_6 * V_53 ,
int type )
{
int V_80 = 1 ;
if ( V_53 ) {
T_1 V_51 = F_83 ( V_53 -> V_61 [ type ] ) ;
if ( V_51 && ( F_39 ( V_19 , V_51 ) & V_104 ) )
V_80 = 3 ;
}
return V_80 ;
}
static int F_88 ( struct V_18 * V_19 , const char * V_63 , int V_127 ,
struct V_6 * V_53 )
{
int V_80 = F_87 ( V_19 , V_53 , V_107 ) ;
return F_85 ( V_19 , V_63 , V_127 , V_80 , V_53 ) ;
}
static int F_89 ( struct V_18 * V_19 , const char * V_63 , int V_127 ,
unsigned int V_80 , struct V_6 * V_53 )
{
unsigned int V_20 ;
int type = V_137 ;
if ( ! V_53 )
return 0 ;
V_20 = V_53 -> V_61 [ V_106 ] ;
if ( ! V_20 )
return 0 ;
V_20 = F_45 ( V_20 , V_80 ) ;
if ( F_90 ( V_20 ) == V_84 ) {
T_1 V_51 = F_83 ( V_20 ) ;
int V_52 = F_57 ( V_19 , V_51 ) ;
if ( V_52 > 1 ) {
type = V_138 ;
V_20 |= V_52 << 19 ;
}
}
return F_91 ( V_19 -> V_2 , type , V_63 , V_127 , V_20 ) ;
}
static int F_92 ( struct V_18 * V_19 , const char * V_63 ,
int V_127 , struct V_6 * V_53 )
{
int V_80 = F_87 ( V_19 , V_53 , V_106 ) ;
return F_89 ( V_19 , V_63 , V_127 , V_80 , V_53 ) ;
}
static void F_93 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_34 ) {
T_1 V_51 = F_95 ( V_140 ) ;
bool V_143 = ! ( ( V_2 -> V_144 >> V_51 ) & 1 ) ;
V_142 -> V_145 . integer . V_145 [ 0 ] &= V_143 ;
V_142 -> V_145 . integer . V_145 [ 1 ] &= V_143 ;
}
}
static int F_96 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
F_93 ( V_140 , V_142 ) ;
return F_97 ( V_140 , V_142 ) ;
}
static int F_98 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
F_93 ( V_140 , V_142 ) ;
return F_99 ( V_140 , V_142 ) ;
}
static bool F_100 ( struct V_18 * V_19 , int V_126 , int V_146 )
{
struct V_6 * V_53 = F_26 ( V_19 , V_126 ) ;
return V_53 && V_53 -> V_61 [ V_146 ] ;
}
static const char * F_101 ( struct V_18 * V_19 , int V_147 ,
int * V_129 , int V_146 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_148 * V_149 = & V_2 -> V_150 ;
* V_129 = 0 ;
if ( V_149 -> V_151 == 1 && ! V_2 -> V_152 &&
! V_149 -> V_153 && ! V_149 -> V_154 )
return V_2 -> V_155 . V_156 ? L_34 : L_35 ;
if ( V_2 -> V_157 . V_158 == 1 && ! V_2 -> V_46 &&
! V_2 -> V_157 . V_159 [ 0 ] && ! V_2 -> V_157 . V_160 [ 0 ] )
return V_2 -> V_155 . V_156 ? L_34 : L_35 ;
if ( V_147 >= V_149 -> V_151 )
return V_161 [ V_147 ] ;
switch ( V_149 -> V_162 ) {
case V_163 :
if ( ! V_147 && V_149 -> V_153 &&
! F_100 ( V_19 , V_2 -> V_164 [ 0 ] , V_146 ) )
break;
if ( V_149 -> V_151 == 1 )
return L_36 ;
if ( V_149 -> V_151 == 2 )
return V_147 ? L_37 : L_36 ;
break;
case V_165 :
if ( ! V_147 && V_149 -> V_154 &&
! F_100 ( V_19 , V_2 -> V_166 [ 0 ] , V_146 ) )
break;
if ( V_147 && V_2 -> V_152 )
break;
* V_129 = V_147 ;
return L_38 ;
case V_167 :
if ( ! V_147 && V_149 -> V_154 && V_149 -> V_153 ) {
bool V_168 = ! F_100 ( V_19 , V_2 -> V_164 [ 0 ] , V_146 ) ;
bool V_169 = ! F_100 ( V_19 , V_2 -> V_166 [ 0 ] , V_146 ) ;
if ( V_168 && V_169 )
return V_2 -> V_155 . V_156 ? L_34 : L_35 ;
if ( V_168 )
return L_39 ;
if ( V_169 )
return L_40 ;
}
}
if ( V_149 -> V_151 == 1 && ! V_2 -> V_152 )
return L_41 ;
if ( V_147 >= F_102 ( V_161 ) ) {
F_103 () ;
return L_34 ;
}
return V_161 [ V_147 ] ;
}
static int F_104 ( struct V_18 * V_19 , struct V_6 * V_53 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_51 ;
unsigned int V_20 ;
int V_170 = 0 ;
if ( ! V_53 )
return V_171 * 2 ;
if ( V_53 -> V_61 [ V_107 ] ||
V_53 -> V_61 [ V_106 ] )
return 0 ;
V_51 = F_50 ( V_19 , V_53 ) ;
if ( V_51 ) {
V_20 = F_32 ( V_51 , 3 , 0 , V_83 ) ;
if ( V_2 -> V_172 )
V_20 |= V_173 ;
if ( F_30 ( V_19 , V_20 , V_107 ) )
V_170 += V_171 ;
else
V_53 -> V_61 [ V_107 ] = V_20 ;
} else
V_170 += V_171 ;
V_51 = F_48 ( V_19 , V_53 ) ;
if ( V_51 ) {
unsigned int V_174 = F_38 ( F_39 ( V_19 , V_51 ) ) ;
if ( V_174 == V_71 || V_174 == V_67 ||
F_49 ( V_19 , V_51 , V_83 ) )
V_20 = F_32 ( V_51 , 3 , 0 , V_83 ) ;
else
V_20 = F_32 ( V_51 , 3 , 0 , V_84 ) ;
if ( F_30 ( V_19 , V_20 , V_106 ) )
V_170 += V_171 ;
else
V_53 -> V_61 [ V_106 ] = V_20 ;
} else
V_170 += V_171 ;
return V_170 ;
}
static T_1 F_105 ( struct V_18 * V_19 , int V_59 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_148 * V_149 = & V_2 -> V_150 ;
if ( V_149 -> V_151 > V_59 )
return V_2 -> V_175 [ V_59 ] ;
V_59 -= V_149 -> V_151 ;
if ( V_2 -> V_152 > V_59 )
return V_2 -> V_176 [ V_59 ] . V_177 ;
return 0 ;
}
static inline T_1 F_106 ( struct V_18 * V_19 ,
T_1 V_177 , T_1 V_47 )
{
return F_28 ( V_19 , V_177 , V_47 ) ? V_177 : 0 ;
}
static int F_107 ( struct V_18 * V_19 , int V_178 ,
const T_1 * V_50 , T_1 * V_179 ,
int * V_126 ,
const struct V_180 * V_181 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_182 ;
int V_170 = 0 ;
T_1 V_177 ;
if ( ! V_178 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_178 ; V_16 ++ ) {
struct V_6 * V_53 ;
T_1 V_47 = V_50 [ V_16 ] ;
V_53 = F_26 ( V_19 , V_126 [ V_16 ] ) ;
if ( V_53 ) {
V_170 += F_104 ( V_19 , V_53 ) ;
continue;
}
V_179 [ V_16 ] = F_43 ( V_19 , V_47 ) ;
if ( V_179 [ V_16 ] ) {
if ( F_27 ( V_19 , V_179 [ V_16 ] ) )
V_170 += V_181 -> V_183 ;
}
if ( ! V_179 [ V_16 ] )
V_179 [ V_16 ] = F_44 ( V_19 , V_47 , false ) ;
if ( ! V_179 [ V_16 ] && ! V_16 ) {
for ( V_182 = 1 ; V_182 < V_178 ; V_182 ++ ) {
if ( F_28 ( V_19 , V_179 [ V_182 ] , V_47 ) ) {
V_179 [ 0 ] = V_179 [ V_182 ] ;
V_179 [ V_182 ] = 0 ;
F_42 ( V_19 , V_126 [ V_182 ] ) ;
V_126 [ V_182 ] = 0 ;
break;
}
}
}
V_177 = V_179 [ V_16 ] ;
if ( ! V_177 ) {
if ( V_178 > 2 )
V_177 = F_106 ( V_19 , F_105 ( V_19 , V_16 ) , V_47 ) ;
if ( ! V_177 )
V_177 = F_106 ( V_19 , V_179 [ 0 ] , V_47 ) ;
if ( ! V_177 )
V_177 = F_106 ( V_19 , F_105 ( V_19 , V_16 ) , V_47 ) ;
if ( V_177 ) {
if ( ! V_16 )
V_170 += V_181 -> V_183 ;
else if ( V_16 == 1 )
V_170 += V_181 -> V_184 ;
else
V_170 += V_181 -> V_185 ;
} else if ( F_28 ( V_19 , V_2 -> V_175 [ 0 ] , V_47 ) ) {
V_177 = V_2 -> V_175 [ 0 ] ;
V_170 += V_181 -> V_186 ;
} else if ( ! V_16 )
V_170 += V_181 -> V_187 ;
else
V_170 += V_181 -> V_188 ;
}
if ( ! V_177 )
continue;
V_53 = F_41 ( V_19 , V_177 , V_47 , - V_2 -> V_46 ) ;
if ( ! V_53 && ! V_16 && V_2 -> V_46 ) {
V_53 = F_41 ( V_19 , V_177 , V_47 , 0 ) ;
}
if ( ! V_53 ) {
V_177 = V_179 [ V_16 ] = 0 ;
V_170 += V_181 -> V_188 ;
} else {
V_53 -> V_92 = true ;
V_126 [ V_16 ] = F_25 ( V_19 , V_53 ) ;
V_170 += F_104 ( V_19 , V_53 ) ;
}
}
return V_170 ;
}
static T_1 F_108 ( struct V_18 * V_19 , T_1 V_47 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_189 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_77 ; V_16 ++ ) {
T_1 V_51 = V_2 -> V_78 [ V_16 ] ;
if ( ! V_51 || F_27 ( V_19 , V_51 ) )
continue;
if ( F_28 ( V_19 , V_51 , V_47 ) ) {
if ( V_189 )
return 0 ;
V_189 = V_51 ;
}
}
return V_189 ;
}
static bool F_109 ( struct V_18 * V_19 ,
unsigned int V_190 , T_1 V_51 )
{
unsigned int V_191 , V_86 ;
V_191 = F_110 ( V_19 , V_51 ) ;
if ( F_111 ( V_191 ) != V_192 )
return false ;
if ( V_190 && F_112 ( V_191 ) != V_190 )
return false ;
V_86 = F_80 ( V_19 , V_51 ) ;
if ( ! ( V_86 & V_193 ) )
return false ;
return true ;
}
static int F_113 ( struct V_18 * V_19 , T_1 V_194 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_148 * V_149 = & V_2 -> V_150 ;
unsigned int V_191 = F_110 ( V_19 , V_194 ) ;
unsigned int V_190 = F_112 ( V_191 ) ;
int type , V_16 ;
int V_49 = 0 ;
for ( type = V_195 ; type >= V_196 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_149 -> V_197 ; V_16 ++ ) {
if ( V_149 -> V_198 [ V_16 ] . type != type )
continue;
if ( F_109 ( V_19 , V_190 ,
V_149 -> V_198 [ V_16 ] . V_47 ) )
V_49 ++ ;
}
}
return V_49 ;
}
static int F_114 ( struct V_18 * V_19 ,
T_1 V_194 ,
bool V_199 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_148 * V_149 = & V_2 -> V_150 ;
int type , V_16 , V_182 , V_49 , V_200 ;
unsigned int V_191 = F_110 ( V_19 , V_194 ) ;
unsigned int V_190 = F_112 ( V_191 ) ;
int V_170 = 0 ;
struct V_6 * V_53 ;
V_200 = V_2 -> V_152 ;
if ( V_200 >= 2 )
goto V_201;
V_49 = F_113 ( V_19 , V_194 ) ;
if ( V_49 < 2 )
goto V_201;
for ( type = V_195 ; type >= V_196 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_149 -> V_197 ; V_16 ++ ) {
T_1 V_51 = V_149 -> V_198 [ V_16 ] . V_47 ;
T_1 V_177 = 0 ;
if ( V_149 -> V_198 [ V_16 ] . type != type )
continue;
if ( ! F_109 ( V_19 , V_190 , V_51 ) )
continue;
for ( V_182 = 0 ; V_182 < V_2 -> V_152 ; V_182 ++ ) {
if ( V_51 == V_2 -> V_176 [ V_182 ] . V_47 )
break;
}
if ( V_182 < V_2 -> V_152 )
continue;
if ( V_199 )
V_177 = F_108 ( V_19 , V_51 ) ;
else if ( ! V_177 )
V_177 = F_44 ( V_19 , V_51 , false ) ;
if ( ! V_177 ) {
V_170 ++ ;
continue;
}
V_53 = F_41 ( V_19 , V_177 , V_51 ,
- V_2 -> V_46 ) ;
if ( ! V_53 ) {
V_170 ++ ;
continue;
}
V_2 -> V_176 [ V_2 -> V_152 ] . V_47 = V_51 ;
V_2 -> V_176 [ V_2 -> V_152 ] . V_177 = V_177 ;
V_2 -> V_202 [ V_149 -> V_151 + V_2 -> V_152 ] =
F_25 ( V_19 , V_53 ) ;
V_2 -> V_152 ++ ;
if ( V_2 -> V_152 >= 2 )
break;
}
}
V_201:
if ( V_170 )
V_170 = V_203 ;
if ( V_200 == V_2 -> V_152 ) {
if ( V_199 )
return 1 ;
else
return V_170 ;
}
if ( ! V_199 && V_2 -> V_152 < 2 ) {
V_2 -> V_5 . V_17 -= V_2 -> V_152 - V_200 ;
V_2 -> V_152 = V_200 ;
return V_170 ;
}
for ( V_16 = V_200 ; V_16 < V_2 -> V_152 ; V_16 ++ ) {
V_53 = F_26 ( V_19 , V_2 -> V_202 [ V_149 -> V_151 + V_16 ] ) ;
V_170 += F_104 ( V_19 , V_53 ) ;
}
return V_170 ;
}
static bool F_115 ( struct V_18 * V_19 , int V_204 ,
const T_1 * V_50 , T_1 * V_179 , int * V_126 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
bool V_68 = false ;
for ( V_16 = 0 ; V_16 < V_204 ; V_16 ++ ) {
struct V_6 * V_53 ;
T_1 V_177 ;
if ( V_179 [ V_16 ] )
continue;
V_177 = F_108 ( V_19 , V_50 [ V_16 ] ) ;
if ( ! V_177 )
continue;
V_53 = F_41 ( V_19 , V_177 , V_50 [ V_16 ] ,
- V_2 -> V_46 ) ;
if ( ! V_53 && ! V_16 && V_2 -> V_46 )
V_53 = F_41 ( V_19 , V_177 , V_50 [ V_16 ] , 0 ) ;
if ( V_53 ) {
V_179 [ V_16 ] = V_177 ;
V_68 = true ;
V_53 -> V_92 = true ;
V_126 [ V_16 ] = F_25 ( V_19 , V_53 ) ;
}
}
return V_68 ;
}
static inline bool F_116 ( struct V_1 * V_2 )
{
return V_2 -> V_205 [ 0 ] || V_2 -> V_205 [ 1 ] ||
V_2 -> V_205 [ 2 ] ;
}
static int F_117 ( struct V_18 * V_19 , int V_126 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_53 ;
T_1 V_206 , V_177 , V_47 ;
V_53 = F_26 ( V_19 , V_126 ) ;
if ( ! V_53 || ! V_53 -> V_54 ||
F_22 ( V_53 , V_2 -> V_46 ) )
return 0 ;
V_206 = V_53 -> V_53 [ 0 ] ;
V_177 = V_2 -> V_175 [ 0 ] ;
V_47 = V_53 -> V_53 [ V_53 -> V_54 - 1 ] ;
V_53 = F_41 ( V_19 , V_177 , V_47 , V_2 -> V_46 ) ;
if ( ! V_53 ) {
if ( V_177 != V_206 )
V_177 = V_206 ;
else if ( V_2 -> V_157 . V_159 [ 0 ] )
V_177 = V_2 -> V_157 . V_159 [ 0 ] ;
else if ( V_2 -> V_157 . V_160 [ 0 ] )
V_177 = V_2 -> V_157 . V_160 [ 0 ] ;
else
V_177 = 0 ;
if ( V_177 )
V_53 = F_41 ( V_19 , V_177 , V_47 ,
V_2 -> V_46 ) ;
}
if ( ! V_53 )
return 0 ;
V_53 -> V_92 = false ;
V_53 -> V_95 = true ;
return F_25 ( V_19 , V_53 ) ;
}
static bool F_118 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_148 * V_149 = & V_2 -> V_150 ;
struct V_6 * V_53 ;
int V_16 , V_59 ;
if ( V_149 -> V_162 == V_165 )
V_59 = V_2 -> V_202 [ 0 ] ;
else
V_59 = V_2 -> V_164 [ 0 ] ;
V_53 = F_26 ( V_19 , V_59 ) ;
if ( ! V_53 )
return false ;
if ( ! V_2 -> V_46 || ! F_22 ( V_53 , V_2 -> V_46 ) )
return true ;
for ( V_16 = 0 ; V_16 < V_149 -> V_151 ; V_16 ++ ) {
if ( V_2 -> V_202 [ V_16 ] == V_59 )
break;
V_53 = F_26 ( V_19 , V_2 -> V_202 [ V_16 ] ) ;
if ( V_53 && F_22 ( V_53 , V_2 -> V_46 ) )
return false ;
}
for ( V_16 = 0 ; V_16 < V_149 -> V_154 ; V_16 ++ ) {
V_53 = F_26 ( V_19 , V_2 -> V_166 [ V_16 ] ) ;
if ( V_53 && F_22 ( V_53 , V_2 -> V_46 ) )
return false ;
}
return true ;
}
static void F_119 ( struct V_18 * V_19 , int V_178 ,
T_1 * V_179 , int * V_126 )
{
struct V_6 * V_53 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_178 ; V_16 ++ ) {
if ( V_179 [ V_16 ] )
continue;
V_53 = F_26 ( V_19 , V_126 [ V_16 ] ) ;
if ( ! V_53 )
continue;
V_179 [ V_16 ] = V_53 -> V_53 [ 0 ] ;
}
}
static int F_120 ( struct V_18 * V_19 ,
bool V_207 ,
bool V_208 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_148 * V_149 = & V_2 -> V_150 ;
int V_16 , V_209 , V_170 ;
V_2 -> V_157 . V_158 = V_149 -> V_151 ;
V_2 -> V_157 . V_210 = V_2 -> V_175 ;
memset ( V_2 -> V_175 , 0 , sizeof( V_2 -> V_175 ) ) ;
memset ( V_2 -> V_157 . V_159 , 0 , sizeof( V_2 -> V_157 . V_159 ) ) ;
memset ( V_2 -> V_157 . V_160 , 0 , sizeof( V_2 -> V_157 . V_160 ) ) ;
V_2 -> V_152 = 0 ;
F_9 ( & V_2 -> V_5 ) ;
memset ( V_2 -> V_202 , 0 , sizeof( V_2 -> V_202 ) ) ;
memset ( V_2 -> V_164 , 0 , sizeof( V_2 -> V_164 ) ) ;
memset ( V_2 -> V_166 , 0 , sizeof( V_2 -> V_166 ) ) ;
memset ( V_2 -> V_205 , 0 , sizeof( V_2 -> V_205 ) ) ;
memset ( V_2 -> V_211 , 0 , sizeof( V_2 -> V_211 ) ) ;
memset ( V_2 -> V_212 , 0 , sizeof( V_2 -> V_212 ) ) ;
memset ( V_2 -> V_213 , 0 , sizeof( V_2 -> V_213 ) ) ;
memset ( & V_2 -> V_214 , 0 , sizeof( V_2 -> V_214 ) ) ;
V_170 = 0 ;
if ( V_207 ) {
bool V_215 ;
do {
V_215 = F_115 ( V_19 , V_149 -> V_151 ,
V_149 -> V_216 ,
V_2 -> V_175 ,
V_2 -> V_202 ) ;
V_215 |= F_115 ( V_19 , V_149 -> V_153 ,
V_149 -> V_217 ,
V_2 -> V_157 . V_159 ,
V_2 -> V_164 ) ;
V_215 |= F_115 ( V_19 , V_149 -> V_154 ,
V_149 -> V_218 ,
V_2 -> V_157 . V_160 ,
V_2 -> V_166 ) ;
if ( ! V_2 -> V_37 &&
V_208 && V_149 -> V_151 == 1 &&
V_149 -> V_162 != V_163 ) {
V_209 = F_114 ( V_19 , V_149 -> V_216 [ 0 ] , true ) ;
if ( ! V_209 )
V_215 = true ;
}
} while ( V_215 );
}
V_170 += F_107 ( V_19 , V_149 -> V_151 , V_149 -> V_216 ,
V_2 -> V_175 , V_2 -> V_202 ,
V_2 -> V_219 ) ;
if ( ! V_2 -> V_37 && V_208 &&
V_149 -> V_151 == 1 && V_149 -> V_162 != V_163 ) {
V_209 = F_114 ( V_19 , V_149 -> V_216 [ 0 ] , false ) ;
if ( V_209 < 0 )
return V_209 ;
}
if ( V_149 -> V_162 != V_165 ) {
V_209 = F_107 ( V_19 , V_149 -> V_153 , V_149 -> V_217 ,
V_2 -> V_157 . V_159 ,
V_2 -> V_164 ,
V_2 -> V_220 ) ;
if ( V_209 < 0 )
return V_209 ;
V_170 += V_209 ;
}
if ( V_149 -> V_162 != V_163 ) {
V_209 = F_107 ( V_19 , V_149 -> V_154 ,
V_149 -> V_218 ,
V_2 -> V_157 . V_160 ,
V_2 -> V_166 ,
V_2 -> V_220 ) ;
if ( V_209 < 0 )
return V_209 ;
V_170 += V_209 ;
}
if ( ! V_2 -> V_37 &&
V_149 -> V_151 == 1 && V_149 -> V_162 != V_163 ) {
V_209 = F_114 ( V_19 , V_149 -> V_216 [ 0 ] , false ) ;
if ( V_209 < 0 )
return V_209 ;
V_170 += V_209 ;
}
if ( V_2 -> V_46 ) {
V_2 -> V_205 [ 0 ] =
F_117 ( V_19 , V_2 -> V_202 [ 0 ] ) ;
if ( V_149 -> V_162 != V_165 )
V_2 -> V_205 [ 1 ] =
F_117 ( V_19 , V_2 -> V_164 [ 0 ] ) ;
if ( V_149 -> V_162 != V_163 )
V_2 -> V_205 [ 2 ] =
F_117 ( V_19 , V_2 -> V_166 [ 0 ] ) ;
}
if ( ! V_2 -> V_37 &&
V_149 -> V_153 && V_149 -> V_162 == V_163 )
if ( F_113 ( V_19 , V_149 -> V_217 [ 0 ] ) >= 2 )
V_2 -> V_152 = 1 ;
V_2 -> V_157 . V_158 = 0 ;
for ( V_16 = 0 ; V_16 < V_149 -> V_151 ; V_16 ++ ) {
if ( V_2 -> V_175 [ V_16 ] )
V_2 -> V_157 . V_158 ++ ;
else {
memmove ( V_2 -> V_175 + V_16 ,
V_2 -> V_175 + V_16 + 1 ,
sizeof( T_1 ) * ( V_149 -> V_151 - V_16 - 1 ) ) ;
V_2 -> V_175 [ V_149 -> V_151 - 1 ] = 0 ;
}
}
V_2 -> V_221 = V_2 -> V_222 =
V_2 -> V_157 . V_158 * 2 ;
if ( V_2 -> V_152 == 2 ) {
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
V_2 -> V_175 [ V_2 -> V_157 . V_158 ++ ] =
V_2 -> V_176 [ V_16 ] . V_177 ;
} else if ( V_2 -> V_152 ) {
V_2 -> V_152 = 0 ;
V_170 += V_203 ;
}
if ( V_2 -> V_40 && ! F_118 ( V_19 ) )
V_170 += V_223 ;
if ( V_149 -> V_162 != V_165 )
F_119 ( V_19 , V_149 -> V_153 ,
V_2 -> V_157 . V_159 ,
V_2 -> V_164 ) ;
if ( V_149 -> V_162 != V_163 )
F_119 ( V_19 , V_149 -> V_154 ,
V_2 -> V_157 . V_160 ,
V_2 -> V_166 ) ;
return V_170 ;
}
static inline void F_121 ( struct V_18 * V_19 ,
const char * V_63 , int V_59 )
{
struct V_6 * V_53 ;
V_53 = F_26 ( V_19 , V_59 ) ;
if ( V_53 )
F_33 ( V_19 , V_63 , V_53 ) ;
}
static void F_122 ( struct V_18 * V_19 ,
struct V_148 * V_149 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_224 [ 3 ] = { L_42 , L_43 , L_44 } ;
int V_16 ;
F_123 ( L_45 ,
V_149 -> V_216 [ 0 ] , V_149 -> V_216 [ 1 ] ,
V_149 -> V_216 [ 2 ] , V_149 -> V_216 [ 3 ] ,
V_2 -> V_157 . V_210 [ 0 ] ,
V_2 -> V_157 . V_210 [ 1 ] ,
V_2 -> V_157 . V_210 [ 2 ] ,
V_2 -> V_157 . V_210 [ 3 ] ,
V_224 [ V_149 -> V_162 ] ) ;
for ( V_16 = 0 ; V_16 < V_149 -> V_151 ; V_16 ++ )
F_121 ( V_19 , L_46 , V_2 -> V_202 [ V_16 ] ) ;
if ( V_2 -> V_152 > 0 )
F_123 ( L_47 ,
V_2 -> V_152 ,
V_2 -> V_176 [ 0 ] . V_47 , V_2 -> V_176 [ 1 ] . V_47 ,
V_2 -> V_176 [ 0 ] . V_177 , V_2 -> V_176 [ 1 ] . V_177 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_152 ; V_16 ++ )
F_121 ( V_19 , L_48 ,
V_2 -> V_202 [ V_149 -> V_151 + V_16 ] ) ;
if ( V_149 -> V_153 )
F_123 ( L_49 ,
V_149 -> V_217 [ 0 ] , V_149 -> V_217 [ 1 ] ,
V_149 -> V_217 [ 2 ] , V_149 -> V_217 [ 3 ] ,
V_2 -> V_157 . V_159 [ 0 ] ,
V_2 -> V_157 . V_159 [ 1 ] ,
V_2 -> V_157 . V_159 [ 2 ] ,
V_2 -> V_157 . V_159 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_149 -> V_153 ; V_16 ++ )
F_121 ( V_19 , L_50 , V_2 -> V_164 [ V_16 ] ) ;
if ( V_149 -> V_154 )
F_123 ( L_51 ,
V_149 -> V_218 [ 0 ] , V_149 -> V_218 [ 1 ] ,
V_149 -> V_218 [ 2 ] , V_149 -> V_218 [ 3 ] ,
V_2 -> V_157 . V_160 [ 0 ] ,
V_2 -> V_157 . V_160 [ 1 ] ,
V_2 -> V_157 . V_160 [ 2 ] ,
V_2 -> V_157 . V_160 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_149 -> V_154 ; V_16 ++ )
F_121 ( V_19 , L_52 , V_2 -> V_166 [ V_16 ] ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ )
F_121 ( V_19 , L_53 , V_2 -> V_205 [ V_16 ] ) ;
}
static void F_124 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_51 ;
V_2 -> V_77 = 0 ;
memset ( V_2 -> V_78 , 0 , sizeof( V_2 -> V_78 ) ) ;
F_125 (nid, codec) {
if ( F_38 ( F_39 ( V_19 , V_51 ) ) != V_67 )
continue;
if ( V_2 -> V_77 >= F_102 ( V_2 -> V_78 ) ) {
F_126 ( V_19 , L_54 ) ;
break;
}
V_2 -> V_78 [ V_2 -> V_77 ++ ] = V_51 ;
}
}
static int F_127 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_148 * V_149 = & V_2 -> V_150 ;
struct V_148 * V_225 ;
unsigned int V_20 ;
int V_226 = V_227 ;
int V_170 ;
bool V_207 = true , V_208 = true ;
bool V_228 = true , V_229 = true ;
bool V_230 = false ;
V_225 = F_128 ( sizeof( * V_225 ) , V_13 ) ;
if ( ! V_225 )
return - V_135 ;
* V_225 = * V_149 ;
for (; ; ) {
V_170 = F_120 ( V_19 , V_207 ,
V_208 ) ;
if ( V_170 < 0 ) {
F_8 ( V_225 ) ;
return V_170 ;
}
F_123 ( L_55 ,
V_149 -> V_162 , V_207 , V_208 ,
V_170 ) ;
F_122 ( V_19 , V_149 ) ;
if ( V_170 < V_226 ) {
V_226 = V_170 ;
* V_225 = * V_149 ;
V_228 = V_207 ;
V_229 = V_208 ;
}
if ( ! V_170 )
break;
V_208 = ! V_208 ;
if ( ! V_208 )
continue;
V_207 = ! V_207 ;
if ( ! V_207 )
continue;
if ( V_230 )
break;
V_230 = true ;
if ( V_149 -> V_154 > 0 &&
V_149 -> V_162 == V_165 ) {
V_149 -> V_153 = V_149 -> V_151 ;
memcpy ( V_149 -> V_217 , V_149 -> V_216 ,
sizeof( V_149 -> V_217 ) ) ;
V_149 -> V_151 = V_149 -> V_154 ;
memcpy ( V_149 -> V_216 , V_149 -> V_218 ,
sizeof( V_149 -> V_218 ) ) ;
V_149 -> V_154 = 0 ;
memset ( V_149 -> V_218 , 0 , sizeof( V_149 -> V_218 ) ) ;
V_149 -> V_162 = V_163 ;
V_207 = true ;
continue;
}
if ( V_149 -> V_153 > 0 &&
V_149 -> V_162 == V_163 ) {
V_149 -> V_154 = V_149 -> V_151 ;
memcpy ( V_149 -> V_218 , V_149 -> V_216 ,
sizeof( V_149 -> V_218 ) ) ;
V_149 -> V_151 = V_149 -> V_153 ;
memcpy ( V_149 -> V_216 , V_149 -> V_217 ,
sizeof( V_149 -> V_217 ) ) ;
V_149 -> V_153 = 0 ;
memset ( V_149 -> V_217 , 0 , sizeof( V_149 -> V_217 ) ) ;
V_149 -> V_162 = V_165 ;
V_207 = true ;
continue;
}
break;
}
if ( V_170 ) {
F_123 ( L_56 ) ;
* V_149 = * V_225 ;
F_120 ( V_19 , V_228 , V_229 ) ;
}
F_123 ( L_57 ,
V_149 -> V_162 , V_228 , V_229 ) ;
F_122 ( V_19 , V_149 ) ;
if ( V_149 -> V_216 [ 0 ] ) {
struct V_6 * V_53 ;
V_53 = F_26 ( V_19 , V_2 -> V_202 [ 0 ] ) ;
if ( V_53 )
V_2 -> V_231 = F_50 ( V_19 , V_53 ) ;
if ( V_2 -> V_231 ) {
F_129 ( V_19 , V_2 -> V_231 ,
V_83 , V_2 -> V_232 ) ;
if ( V_2 -> V_172 )
V_2 -> V_232 [ 3 ] |= V_233 ;
}
}
if ( V_2 -> V_234 || V_149 -> V_162 == V_165 )
V_20 = V_235 ;
else
V_20 = V_236 ;
F_20 ( V_19 , V_149 -> V_151 , V_149 -> V_216 , V_20 ) ;
if ( V_149 -> V_162 != V_165 )
F_20 ( V_19 , V_149 -> V_153 , V_149 -> V_217 , V_235 ) ;
if ( V_149 -> V_162 != V_163 ) {
V_20 = V_2 -> V_234 ? V_235 : V_236 ;
F_20 ( V_19 , V_149 -> V_154 ,
V_149 -> V_218 , V_20 ) ;
}
if ( V_2 -> V_40 && ! F_118 ( V_19 ) )
V_2 -> V_40 = 0 ;
F_8 ( V_225 ) ;
return 0 ;
}
static int F_130 ( struct V_18 * V_19 ,
const struct V_148 * V_149 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_209 , V_237 ;
V_237 = V_149 -> V_151 ;
if ( V_2 -> V_152 > 0 && V_149 -> V_151 < 3 )
V_237 += V_2 -> V_152 ;
for ( V_16 = 0 ; V_16 < V_237 ; V_16 ++ ) {
const char * V_10 ;
int V_129 ;
struct V_6 * V_53 ;
V_53 = F_26 ( V_19 , V_2 -> V_202 [ V_16 ] ) ;
if ( ! V_53 )
continue;
V_10 = F_101 ( V_19 , V_16 , & V_129 , V_107 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_58 ) ) {
V_209 = F_85 ( V_19 , L_59 , 0 , 1 , V_53 ) ;
if ( V_209 < 0 )
return V_209 ;
V_209 = F_85 ( V_19 , L_60 , 0 , 2 , V_53 ) ;
if ( V_209 < 0 )
return V_209 ;
} else {
V_209 = F_88 ( V_19 , V_10 , V_129 , V_53 ) ;
if ( V_209 < 0 )
return V_209 ;
}
V_10 = F_101 ( V_19 , V_16 , & V_129 , V_106 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_58 ) ) {
V_209 = F_89 ( V_19 , L_59 , 0 , 1 , V_53 ) ;
if ( V_209 < 0 )
return V_209 ;
V_209 = F_89 ( V_19 , L_60 , 0 , 2 , V_53 ) ;
if ( V_209 < 0 )
return V_209 ;
} else {
V_209 = F_92 ( V_19 , V_10 , V_129 , V_53 ) ;
if ( V_209 < 0 )
return V_209 ;
}
}
return 0 ;
}
static int F_131 ( struct V_18 * V_19 , int V_126 ,
const char * V_63 , int V_127 )
{
struct V_6 * V_53 ;
int V_209 ;
V_53 = F_26 ( V_19 , V_126 ) ;
if ( ! V_53 )
return 0 ;
V_209 = F_88 ( V_19 , V_63 , V_127 , V_53 ) ;
if ( V_209 < 0 )
return V_209 ;
V_209 = F_92 ( V_19 , V_63 , V_127 , V_53 ) ;
if ( V_209 < 0 )
return V_209 ;
return 0 ;
}
static int F_132 ( struct V_18 * V_19 , int V_49 ,
const int * V_5 , const char * V_63 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_49 ; V_16 ++ ) {
const char * V_10 ;
char V_238 [ V_134 ] ;
int V_209 , V_59 = 0 ;
if ( V_49 == 2 && V_16 == 1 && ! strcmp ( V_63 , L_36 ) )
V_10 = L_37 ;
else if ( V_49 >= 3 ) {
snprintf ( V_238 , sizeof( V_238 ) , L_61 ,
V_63 , V_161 [ V_16 ] ) ;
V_10 = V_238 ;
} else {
V_10 = V_63 ;
V_59 = V_16 ;
}
V_209 = F_131 ( V_19 , V_5 [ V_16 ] , V_10 , V_59 ) ;
if ( V_209 < 0 )
return V_209 ;
}
return 0 ;
}
static int F_133 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_132 ( V_19 , V_2 -> V_150 . V_153 ,
V_2 -> V_164 ,
L_38 ) ;
}
static int F_134 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_132 ( V_19 , V_2 -> V_150 . V_154 ,
V_2 -> V_166 ,
L_36 ) ;
}
static int F_135 ( struct V_139 * V_140 ,
struct V_239 * V_240 )
{
return F_136 ( V_140 , V_240 ) ;
}
static int F_137 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_142 -> V_145 . V_241 . V_242 [ 0 ] = V_2 -> V_243 ;
return 0 ;
}
static int F_138 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_244 = V_142 -> V_145 . V_241 . V_242 [ 0 ] ;
int V_245 = 0 ;
F_139 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_246 ) {
V_245 = - V_247 ;
goto V_248;
}
if ( V_2 -> V_243 != V_244 ) {
T_1 * V_249 ;
if ( V_2 -> V_150 . V_162 == V_165 )
V_249 = & V_2 -> V_175 [ 0 ] ;
else
V_249 = & V_2 -> V_157 . V_159 [ 0 ] ;
if ( V_2 -> V_250 ) {
if ( V_2 -> V_150 . V_162 == V_165 )
F_140 ( V_19 , V_2 -> V_251 ,
V_2 -> V_202 [ 0 ] ,
V_2 -> V_205 [ 0 ] ,
V_2 -> V_150 . V_162 ) ;
else
F_140 ( V_19 , V_2 -> V_251 ,
V_2 -> V_164 [ 0 ] ,
V_2 -> V_205 [ 1 ] ,
V_165 ) ;
}
V_2 -> V_243 = V_244 ;
if ( V_2 -> V_243 )
* V_249 = 0 ;
else
* V_249 = V_2 -> V_252 ;
F_141 ( V_19 , NULL ) ;
V_245 = 1 ;
}
V_248:
F_142 ( & V_2 -> V_9 ) ;
return V_245 ;
}
static int F_143 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_177 ;
if ( ! V_2 -> V_40 )
return 0 ;
if ( V_2 -> V_150 . V_162 == V_165 )
V_177 = V_2 -> V_157 . V_210 [ 0 ] ;
else
V_177 = V_2 -> V_157 . V_159 [ 0 ] ;
if ( ! V_177 ) {
V_2 -> V_40 = 0 ;
return 0 ;
}
V_2 -> V_243 = false ;
V_2 -> V_252 = V_177 ;
if ( ! F_4 ( V_2 , NULL , & V_253 ) )
return - V_135 ;
return 0 ;
}
static int F_144 ( struct V_139 * V_140 ,
struct V_239 * V_240 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_80 ;
V_240 -> type = V_254 ;
V_240 -> V_255 = 1 ;
V_240 -> V_145 . V_241 . V_256 = V_2 -> V_152 + 1 ;
if ( V_240 -> V_145 . V_241 . V_242 > V_2 -> V_152 )
V_240 -> V_145 . V_241 . V_242 = V_2 -> V_152 ;
V_80 = V_240 -> V_145 . V_241 . V_242 * 2 + V_2 -> V_222 ;
sprintf ( V_240 -> V_145 . V_241 . V_10 , L_62 , V_80 ) ;
return 0 ;
}
static int F_145 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_142 -> V_145 . V_241 . V_242 [ 0 ] =
( V_2 -> V_221 - V_2 -> V_222 ) / 2 ;
return 0 ;
}
static inline struct V_6 *
F_146 ( struct V_18 * V_19 , int V_59 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_26 ( V_19 ,
V_2 -> V_202 [ V_2 -> V_150 . V_151 + V_59 ] ) ;
}
static bool F_147 ( struct V_1 * V_2 )
{
return ! V_2 -> V_250 || V_2 -> V_251 ;
}
static int F_148 ( struct V_18 * V_19 , int V_59 , bool V_257 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_51 = V_2 -> V_176 [ V_59 ] . V_47 ;
struct V_6 * V_53 ;
V_53 = F_146 ( V_19 , V_59 ) ;
if ( ! V_53 )
return - V_258 ;
if ( V_53 -> V_92 == V_257 )
return 0 ;
if ( V_257 ) {
F_17 ( V_19 , V_51 , V_236 , true ) ;
F_76 ( V_19 , V_53 , true , F_147 ( V_2 ) ) ;
F_79 ( V_19 , V_51 , true ) ;
} else {
F_79 ( V_19 , V_51 , false ) ;
F_76 ( V_19 , V_53 , false , F_147 ( V_2 ) ) ;
F_17 ( V_19 , V_51 , V_2 -> V_176 [ V_59 ] . V_259 , true ) ;
F_78 ( V_19 , V_53 ) ;
}
F_149 ( V_19 ) ;
return 0 ;
}
static int F_150 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_147 ;
V_147 = V_142 -> V_145 . V_241 . V_242 [ 0 ] ;
if ( V_147 < 0 || V_147 > V_2 -> V_152 )
return - V_258 ;
if ( V_147 == ( V_2 -> V_221 - V_2 -> V_222 ) / 2 )
return 0 ;
V_2 -> V_221 = V_147 * 2 + V_2 -> V_222 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_152 ; V_16 ++ )
F_148 ( V_19 , V_16 , V_16 < V_147 ) ;
V_2 -> V_157 . V_260 = F_151 ( V_2 -> V_221 ,
V_2 -> V_261 ) ;
if ( V_2 -> V_35 )
V_2 -> V_157 . V_158 = V_2 -> V_157 . V_260 / 2 ;
return 1 ;
}
static int F_152 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_152 > 0 ) {
if ( ! F_4 ( V_2 , NULL , & V_262 ) )
return - V_135 ;
}
return 0 ;
}
static int F_153 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_142 -> V_145 . V_241 . V_242 [ 0 ] = V_2 -> V_251 ;
return 0 ;
}
static void F_140 ( struct V_18 * V_19 , bool V_263 ,
int V_264 , int V_265 ,
int V_266 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_267 , * V_268 ;
V_267 = F_26 ( V_19 , V_264 ) ;
V_268 = F_26 ( V_19 , V_265 ) ;
if ( ! V_267 || ! V_268 )
return;
if ( V_266 == V_165 && V_2 -> V_243 &&
V_268 -> V_53 [ 0 ] != V_2 -> V_252 )
V_263 = false ;
if ( V_263 ) {
F_76 ( V_19 , V_267 , false , true ) ;
F_76 ( V_19 , V_268 , true , true ) ;
F_78 ( V_19 , V_267 ) ;
} else {
F_76 ( V_19 , V_268 , false , false ) ;
F_76 ( V_19 , V_267 , true , false ) ;
F_78 ( V_19 , V_268 ) ;
}
}
static void F_154 ( struct V_18 * V_19 , int V_178 ,
const int * V_5 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_53 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_178 ; V_16 ++ ) {
V_53 = F_26 ( V_19 , V_5 [ V_16 ] ) ;
if ( V_53 )
F_76 ( V_19 , V_53 , V_53 -> V_92 ,
V_2 -> V_251 ) ;
}
}
static int F_155 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_148 * V_149 = & V_2 -> V_150 ;
unsigned int V_20 = V_142 -> V_145 . V_241 . V_242 [ 0 ] ;
if ( V_20 == V_2 -> V_251 )
return 0 ;
V_2 -> V_251 = V_20 ;
if ( F_116 ( V_2 ) ) {
F_140 ( V_19 , V_20 , V_2 -> V_202 [ 0 ] ,
V_2 -> V_205 [ 0 ] ,
V_149 -> V_162 ) ;
F_140 ( V_19 , V_20 , V_2 -> V_164 [ 0 ] ,
V_2 -> V_205 [ 1 ] ,
V_165 ) ;
F_140 ( V_19 , V_20 , V_2 -> V_166 [ 0 ] ,
V_2 -> V_205 [ 2 ] ,
V_163 ) ;
} else {
F_154 ( V_19 , V_149 -> V_151 , V_2 -> V_202 ) ;
if ( V_149 -> V_162 != V_165 )
F_154 ( V_19 , V_149 -> V_153 , V_2 -> V_164 ) ;
if ( V_149 -> V_162 != V_163 )
F_154 ( V_19 , V_149 -> V_154 ,
V_2 -> V_166 ) ;
}
return 1 ;
}
static int F_156 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_46 )
return 0 ;
if ( ! F_4 ( V_2 , NULL , & V_269 ) )
return - V_135 ;
V_2 -> V_250 = 1 ;
V_2 -> V_251 = ! F_116 ( V_2 ) ;
return 0 ;
}
static void F_157 ( struct V_18 * V_19 , int V_270 , bool V_271 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_272 ;
unsigned int V_20 ;
T_1 V_47 ;
V_47 = V_2 -> V_273 ;
V_272 = V_2 -> V_274 [ V_270 ] == V_2 -> V_275 ;
if ( ! V_271 ) {
V_20 = F_16 ( V_19 , V_47 ) ;
if ( V_272 ) {
if ( V_20 & V_276 )
return;
} else {
if ( V_20 & V_236 )
return;
}
}
V_20 = F_158 ( V_19 , V_47 ) ;
if ( V_20 == V_277 && V_2 -> V_278 ) {
const T_1 V_279 = V_2 -> V_278 ;
unsigned int V_280 = F_158 ( V_19 , V_279 ) ;
if ( V_280 != V_277 )
F_159 ( V_19 , V_279 ,
V_276 | ( V_272 ? V_280 : 0 ) ) ;
}
if ( ! V_2 -> V_281 ) {
if ( V_272 )
V_20 |= V_276 ;
else
V_20 = V_235 ;
F_17 ( V_19 , V_47 , V_20 , true ) ;
F_141 ( V_19 , NULL ) ;
}
}
static int F_160 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_148 * V_149 = & V_2 -> V_150 ;
unsigned int V_191 ;
T_1 V_51 ;
if ( ! V_2 -> V_44 ) {
if ( V_2 -> V_45 )
return 0 ;
if ( V_149 -> V_197 > 1 )
return 0 ;
else if ( V_149 -> V_197 == 1 ) {
V_191 = F_110 ( V_19 , V_149 -> V_198 [ 0 ] . V_47 ) ;
if ( F_161 ( V_191 ) != V_282 )
return 0 ;
}
}
V_2 -> V_44 = 0 ;
if ( V_149 -> V_197 >= V_283 )
return 0 ;
V_51 = 0 ;
if ( V_149 -> V_162 == V_165 && V_149 -> V_151 > 0 )
V_51 = V_149 -> V_216 [ 0 ] ;
else if ( V_149 -> V_153 > 0 )
V_51 = V_149 -> V_217 [ 0 ] ;
if ( ! V_51 )
return 0 ;
if ( ! ( F_80 ( V_19 , V_51 ) & V_284 ) )
return 0 ;
V_149 -> V_198 [ V_149 -> V_197 ] . V_47 = V_51 ;
V_149 -> V_198 [ V_149 -> V_197 ] . type = V_196 ;
V_149 -> V_198 [ V_149 -> V_197 ] . V_285 = 1 ;
V_149 -> V_197 ++ ;
V_2 -> V_44 = 1 ;
V_2 -> V_273 = V_51 ;
V_2 -> V_32 = 1 ;
F_35 ( V_19 , L_63 , V_51 ) ;
return 0 ;
}
static int F_162 ( struct V_139 * V_140 ,
struct V_239 * V_240 )
{
return F_163 ( V_140 , V_240 , 2 , V_286 ) ;
}
static int F_164 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
T_1 V_51 = V_140 -> V_132 ;
if ( F_16 ( V_19 , V_51 ) == V_235 )
V_142 -> V_145 . V_241 . V_242 [ 0 ] = 1 ;
else
V_142 -> V_145 . V_241 . V_242 [ 0 ] = 0 ;
return 0 ;
}
static int F_165 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
T_1 V_51 = V_140 -> V_132 ;
unsigned int V_20 ;
V_20 = V_142 -> V_145 . V_241 . V_242 [ 0 ] ? V_235 : V_236 ;
if ( F_16 ( V_19 , V_51 ) == V_20 )
return 0 ;
F_159 ( V_19 , V_51 , V_20 ) ;
return 1 ;
}
static bool F_166 ( struct V_18 * V_19 , const char * V_10 , int V_59 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_3 . V_17 ; V_16 ++ ) {
struct V_4 * V_15 = F_24 ( & V_2 -> V_3 , V_16 ) ;
if ( ! strcmp ( V_15 -> V_10 , V_10 ) && V_15 -> V_129 == V_59 )
return true ;
}
return false ;
}
static void F_167 ( struct V_18 * V_19 , T_1 V_47 ,
char * V_10 , T_3 V_287 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_59 = 0 ;
F_168 ( V_19 , V_47 , & V_2 -> V_150 , V_10 , V_287 , & V_59 ) ;
F_169 ( V_10 , L_64 , V_287 ) ;
for (; F_166 ( V_19 , V_10 , V_59 ) ; V_59 ++ )
;
}
static int F_170 ( struct V_18 * V_19 , T_1 V_47 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_42 ) {
unsigned int V_288 = F_80 ( V_19 , V_47 ) ;
if ( ( V_288 & V_193 ) && ( V_288 & V_289 ) )
return 2 ;
}
return 1 ;
}
static int F_171 ( struct V_18 * V_19 , int V_49 ,
T_1 * V_50 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_49 ; V_16 ++ ) {
T_1 V_47 = V_50 [ V_16 ] ;
if ( V_47 == V_2 -> V_273 )
continue;
if ( F_170 ( V_19 , V_47 ) > 1 ) {
struct V_4 * V_12 ;
char V_10 [ V_134 ] ;
F_167 ( V_19 , V_47 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 ,
& V_290 ) ;
if ( ! V_12 )
return - V_135 ;
V_12 -> V_132 = V_47 ;
}
}
return 0 ;
}
static unsigned int F_172 ( struct V_18 * V_19 , T_1 V_47 )
{
unsigned int V_288 ;
V_288 = F_80 ( V_19 , V_47 ) ;
V_288 = ( V_288 & V_291 ) >> V_292 ;
V_288 &= ~ ( V_293 | V_294 ) ;
return V_288 ;
}
static int F_173 ( unsigned int V_295 , unsigned int V_296 )
{
unsigned int V_16 , V_89 = 0 ;
for ( V_16 = 0 ; V_16 < V_297 ; V_16 ++ ) {
if ( V_295 & ( 1 << V_16 ) ) {
if ( V_89 == V_296 )
return V_16 ;
V_89 ++ ;
}
}
return 0 ;
}
static int F_174 ( unsigned int V_295 , unsigned int V_59 )
{
unsigned int V_16 , V_89 = 0 ;
for ( V_16 = 0 ; V_16 < V_297 ; V_16 ++ ) {
if ( V_16 == V_59 )
return V_89 ;
if ( V_295 & ( 1 << V_16 ) )
V_89 ++ ;
}
return 0 ;
}
static int F_175 ( struct V_139 * V_140 ,
struct V_239 * V_240 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
T_1 V_51 = V_140 -> V_132 ;
unsigned int V_295 = F_172 ( V_19 , V_51 ) ;
F_163 ( V_140 , V_240 , F_176 ( V_295 ) ,
V_298 ) ;
strcpy ( V_240 -> V_145 . V_241 . V_10 ,
V_298 [ F_173 ( V_295 , V_240 -> V_145 . V_241 . V_242 ) ] ) ;
return 0 ;
}
static int F_177 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
T_1 V_51 = V_140 -> V_132 ;
unsigned int V_295 = F_172 ( V_19 , V_51 ) ;
unsigned int V_59 ;
V_59 = F_16 ( V_19 , V_51 ) & V_299 ;
V_142 -> V_145 . V_241 . V_242 [ 0 ] = F_174 ( V_295 , V_59 ) ;
return 0 ;
}
static int F_178 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
T_1 V_51 = V_140 -> V_132 ;
unsigned int V_295 = F_172 ( V_19 , V_51 ) ;
unsigned int V_20 , V_59 ;
V_20 = F_16 ( V_19 , V_51 ) ;
V_59 = F_174 ( V_295 , V_20 & V_299 ) ;
if ( V_59 == V_142 -> V_145 . V_241 . V_242 [ 0 ] )
return 0 ;
V_20 &= ~ V_299 ;
V_20 |= F_173 ( V_295 , V_142 -> V_145 . V_241 . V_242 [ 0 ] ) ;
F_159 ( V_19 , V_51 , V_20 ) ;
return 1 ;
}
static int F_179 ( struct V_18 * V_19 , T_1 V_47 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_300 = 0 ;
if ( V_2 -> V_42 )
V_300 = F_176 ( F_172 ( V_19 , V_47 ) ) ;
return V_300 ? V_300 : 1 ;
}
static int F_180 ( struct V_18 * V_19 , T_1 V_47 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
char V_10 [ V_134 ] ;
unsigned int V_191 ;
if ( V_47 == V_2 -> V_273 )
return 0 ;
V_191 = F_110 ( V_19 , V_47 ) ;
if ( F_161 ( V_191 ) == V_282 )
return 0 ;
if ( F_179 ( V_19 , V_47 ) <= 1 )
return 0 ;
F_167 ( V_19 , V_47 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 , & V_301 ) ;
if ( ! V_12 )
return - V_135 ;
V_12 -> V_132 = V_47 ;
return 0 ;
}
static int F_181 ( struct V_139 * V_140 ,
struct V_239 * V_240 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
T_1 V_51 = V_140 -> V_132 ;
int V_302 = F_170 ( V_19 , V_51 ) ;
int V_303 = F_179 ( V_19 , V_51 ) ;
const char * V_304 = NULL ;
int V_59 ;
V_240 -> type = V_254 ;
V_240 -> V_255 = 1 ;
V_240 -> V_145 . V_241 . V_256 = V_302 + V_303 ;
if ( V_240 -> V_145 . V_241 . V_242 >= V_240 -> V_145 . V_241 . V_256 )
V_240 -> V_145 . V_241 . V_242 = V_240 -> V_145 . V_241 . V_256 - 1 ;
V_59 = V_240 -> V_145 . V_241 . V_242 ;
if ( V_59 < V_302 ) {
if ( V_302 > 1 )
V_304 = V_286 [ V_59 ] ;
else
V_304 = L_65 ;
} else {
V_59 -= V_302 ;
if ( V_303 > 1 ) {
unsigned int V_295 = F_172 ( V_19 , V_51 ) ;
V_304 = V_298 [ F_173 ( V_295 , V_59 ) ] ;
} else
V_304 = L_66 ;
}
strcpy ( V_240 -> V_145 . V_241 . V_10 , V_304 ) ;
return 0 ;
}
static int F_182 ( struct V_18 * V_19 , T_1 V_51 )
{
int V_302 = F_170 ( V_19 , V_51 ) ;
int V_303 = F_179 ( V_19 , V_51 ) ;
unsigned int V_20 = F_16 ( V_19 , V_51 ) ;
int V_59 = 0 ;
if ( V_20 & V_236 ) {
if ( V_302 > 1 && V_20 == V_235 )
V_59 = 1 ;
} else if ( V_20 & V_276 ) {
V_59 = V_302 ;
if ( V_303 > 1 ) {
unsigned int V_295 = F_172 ( V_19 , V_51 ) ;
V_20 &= V_299 ;
V_59 += F_174 ( V_295 , V_20 ) ;
}
}
return V_59 ;
}
static int F_183 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
T_1 V_51 = V_140 -> V_132 ;
V_142 -> V_145 . V_241 . V_242 [ 0 ] =
F_182 ( V_19 , V_51 ) ;
return 0 ;
}
static int F_184 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
T_1 V_51 = V_140 -> V_132 ;
int V_302 = F_170 ( V_19 , V_51 ) ;
int V_303 = F_179 ( V_19 , V_51 ) ;
unsigned int V_20 , V_305 , V_59 ;
V_305 = F_182 ( V_19 , V_51 ) ;
V_59 = V_142 -> V_145 . V_241 . V_242 [ 0 ] ;
if ( V_305 == V_59 )
return 0 ;
if ( V_59 < V_302 ) {
if ( V_302 > 1 )
V_20 = V_59 ? V_235 : V_236 ;
else
V_20 = V_235 ;
} else {
V_59 -= V_302 ;
if ( V_303 > 1 ) {
unsigned int V_295 = F_172 ( V_19 , V_51 ) ;
V_20 = F_16 ( V_19 , V_51 ) ;
V_20 &= ~ ( V_299 | V_235 ) ;
V_20 |= F_173 ( V_295 , V_59 ) | V_276 ;
} else
V_20 = F_158 ( V_19 , V_51 ) | V_276 ;
}
F_159 ( V_19 , V_51 , V_20 ) ;
F_141 ( V_19 , NULL ) ;
return 1 ;
}
static int F_185 ( struct V_18 * V_19 , T_1 V_47 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
V_12 = F_4 ( V_2 , L_67 ,
& V_306 ) ;
if ( ! V_12 )
return - V_135 ;
V_12 -> V_132 = V_47 ;
V_2 -> V_281 = 1 ;
return 0 ;
}
static int F_186 ( struct V_1 * V_2 , T_1 V_307 , int V_59 )
{
struct V_8 * V_14 ;
V_14 = F_5 ( & V_2 -> V_7 ) ;
if ( ! V_14 )
return - V_135 ;
V_14 -> V_51 = V_307 ;
V_14 -> V_62 = V_84 ;
V_14 -> V_59 = V_59 ;
V_2 -> V_308 . V_309 = V_2 -> V_7 . V_14 ;
return 0 ;
}
static bool F_187 ( struct V_18 * V_19 , T_1 V_310 ,
T_1 V_47 , unsigned int * V_311 ,
unsigned int * V_312 )
{
int V_59 , V_313 ;
const T_1 * V_14 ;
T_1 V_51 ;
V_59 = F_29 ( V_19 , V_310 , V_47 , true ) ;
if ( V_59 < 0 )
return false ;
* V_311 = * V_312 = 0 ;
if ( F_51 ( V_19 , V_310 , V_84 ) )
* V_311 = F_32 ( V_310 , 3 , V_59 , V_84 ) ;
if ( F_49 ( V_19 , V_310 , V_84 ) )
* V_312 = F_32 ( V_310 , 3 , V_59 , V_84 ) ;
if ( * V_311 && * V_312 )
return true ;
V_313 = F_37 ( V_19 , V_310 , & V_14 ) ;
if ( V_313 < V_59 )
return false ;
V_51 = V_14 [ V_59 ] ;
if ( ! * V_311 && F_51 ( V_19 , V_51 , V_83 ) &&
! F_31 ( V_19 , V_51 , V_83 , 0 , V_107 ) )
* V_311 = F_32 ( V_51 , 3 , 0 , V_83 ) ;
if ( ! * V_312 && F_49 ( V_19 , V_51 , V_83 ) &&
! F_31 ( V_19 , V_51 , V_83 , 0 , V_106 ) )
* V_312 = F_32 ( V_51 , 3 , 0 , V_83 ) ;
return * V_311 || * V_312 ;
}
static int F_188 ( struct V_18 * V_19 , int V_314 ,
T_1 V_47 , const char * V_315 , int V_316 ,
T_1 V_310 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_53 ;
unsigned int V_311 , V_312 ;
int V_209 , V_59 ;
if ( ! F_187 ( V_19 , V_310 , V_47 , & V_311 , & V_312 ) )
return 0 ;
V_53 = F_41 ( V_19 , V_47 , V_310 , 0 ) ;
if ( ! V_53 )
return - V_258 ;
F_33 ( V_19 , L_68 , V_53 ) ;
V_2 -> V_213 [ V_314 ] = F_25 ( V_19 , V_53 ) ;
V_59 = V_53 -> V_59 [ V_53 -> V_54 - 1 ] ;
if ( V_311 ) {
V_209 = F_86 ( V_2 , V_136 , V_315 , V_316 , V_311 ) ;
if ( V_209 < 0 )
return V_209 ;
V_53 -> V_61 [ V_107 ] = V_311 ;
}
if ( V_312 ) {
V_209 = F_91 ( V_2 , V_137 , V_315 , V_316 , V_312 ) ;
if ( V_209 < 0 )
return V_209 ;
V_53 -> V_61 [ V_106 ] = V_312 ;
}
V_53 -> V_92 = true ;
V_53 -> V_93 = true ;
V_209 = F_186 ( V_2 , V_310 , V_59 ) ;
if ( V_209 < 0 )
return V_209 ;
if ( V_2 -> V_46 != V_2 -> V_111 &&
! V_2 -> V_317 ) {
V_53 = F_41 ( V_19 , V_2 -> V_46 ,
V_2 -> V_111 , 0 ) ;
if ( V_53 ) {
F_33 ( V_19 , L_69 , V_53 ) ;
V_53 -> V_92 = true ;
V_53 -> V_95 = true ;
V_53 -> V_93 = true ;
V_2 -> V_317 =
F_25 ( V_19 , V_53 ) ;
}
}
return 0 ;
}
static int F_189 ( struct V_18 * V_19 , T_1 V_51 )
{
unsigned int V_288 = F_80 ( V_19 , V_51 ) ;
return ( V_288 & V_284 ) != 0 ;
}
static int F_190 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_51 ;
T_1 * V_318 = V_2 -> V_318 ;
int V_319 = F_102 ( V_2 -> V_318 ) ;
int V_52 = 0 ;
F_125 (nid, codec) {
unsigned int V_86 = F_39 ( V_19 , V_51 ) ;
int type = F_38 ( V_86 ) ;
if ( type != V_70 || ( V_86 & V_79 ) )
continue;
V_318 [ V_52 ] = V_51 ;
if ( ++ V_52 >= V_319 )
break;
}
V_2 -> V_320 = V_52 ;
V_2 -> V_321 = V_52 ;
memcpy ( V_2 -> V_322 , V_2 -> V_318 , V_52 * sizeof( T_1 ) ) ;
return V_52 ;
}
static int F_191 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_323 * V_324 = & V_2 -> V_325 ;
unsigned int V_326 ;
int V_16 , V_89 , V_52 ;
V_52 = 0 ;
V_326 = 0 ;
for ( V_89 = 0 ; V_89 < V_2 -> V_320 ; V_89 ++ ) {
for ( V_16 = 0 ; V_16 < V_324 -> V_327 ; V_16 ++ ) {
if ( ! V_2 -> V_212 [ V_16 ] [ V_89 ] )
break;
}
if ( V_16 >= V_324 -> V_327 ) {
V_326 |= ( 1 << V_89 ) ;
V_52 ++ ;
}
}
if ( ! V_326 ) {
for ( V_16 = 0 ; V_16 < V_324 -> V_327 ; V_16 ++ ) {
for ( V_89 = 0 ; V_89 < V_2 -> V_320 ; V_89 ++ ) {
if ( V_2 -> V_212 [ V_16 ] [ V_89 ] ) {
V_2 -> V_328 [ V_16 ] = V_89 ;
break;
}
}
}
F_35 ( V_19 , L_70 ) ;
V_2 -> V_329 = 1 ;
} else if ( V_52 != V_2 -> V_320 ) {
V_52 = 0 ;
for ( V_89 = 0 ; V_89 < V_2 -> V_320 ; V_89 ++ ) {
if ( ! ( V_326 & ( 1 << V_89 ) ) )
continue;
if ( V_89 != V_52 ) {
V_2 -> V_318 [ V_52 ] = V_2 -> V_318 [ V_89 ] ;
for ( V_16 = 0 ; V_16 < V_324 -> V_327 ; V_16 ++ ) {
F_42 ( V_19 ,
V_2 -> V_212 [ V_16 ] [ V_52 ] ) ;
V_2 -> V_212 [ V_16 ] [ V_52 ] =
V_2 -> V_212 [ V_16 ] [ V_89 ] ;
}
}
V_52 ++ ;
}
V_2 -> V_320 = V_52 ;
}
if ( V_324 -> V_327 == 1 ||
( V_324 -> V_327 == 2 && V_2 -> V_44 ) ) {
F_35 ( V_19 , L_71 ) ;
V_2 -> V_320 = 1 ;
}
if ( ! V_2 -> V_329 && V_2 -> V_38 )
V_2 -> V_320 = 1 ;
return 0 ;
}
static int F_192 ( struct V_18 * V_19 , T_1 V_47 ,
int V_330 , int V_331 ,
const char * V_332 , int V_333 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_323 * V_324 = & V_2 -> V_325 ;
int V_334 = V_324 -> V_327 ;
bool V_335 = false ;
int V_336 ;
for ( V_336 = 0 ; V_336 < V_331 ; V_336 ++ ) {
struct V_6 * V_53 ;
T_1 V_337 = V_2 -> V_318 [ V_336 ] ;
if ( ! F_28 ( V_19 , V_47 , V_337 ) )
continue;
V_53 = F_41 ( V_19 , V_47 , V_337 , V_333 ) ;
if ( ! V_53 )
continue;
F_33 ( V_19 , L_72 , V_53 ) ;
V_2 -> V_212 [ V_334 ] [ V_336 ] =
F_25 ( V_19 , V_53 ) ;
if ( ! V_335 ) {
if ( V_2 -> V_273 == V_47 )
V_2 -> V_275 = V_324 -> V_327 ;
V_2 -> V_338 [ V_324 -> V_327 ] = V_47 ;
F_193 ( V_19 , V_324 , V_332 , V_330 , NULL ) ;
V_335 = true ;
if ( V_2 -> V_329 )
V_2 -> V_328 [ V_334 ] = V_336 ;
}
}
return 0 ;
}
static int F_194 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_148 * V_149 = & V_2 -> V_150 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_149 -> V_197 ; V_16 ++ ) {
T_1 V_47 = V_149 -> V_198 [ V_16 ] . V_47 ;
const char * V_332 ;
int V_182 , V_59 ;
if ( ! F_189 ( V_19 , V_47 ) )
continue;
V_332 = F_195 ( V_19 , V_149 , V_16 ) ;
V_59 = 0 ;
for ( V_182 = V_16 - 1 ; V_182 >= 0 ; V_182 -- ) {
if ( V_2 -> V_339 [ V_182 ] &&
! strcmp ( V_2 -> V_339 [ V_182 ] , V_332 ) ) {
V_59 = V_2 -> V_340 [ V_182 ] + 1 ;
break;
}
}
V_2 -> V_339 [ V_16 ] = V_332 ;
V_2 -> V_340 [ V_16 ] = V_59 ;
}
return 0 ;
}
static int F_196 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_148 * V_149 = & V_2 -> V_150 ;
T_1 V_341 = V_2 -> V_46 ;
int V_331 ;
int V_16 , V_209 ;
unsigned int V_20 ;
V_331 = F_190 ( V_19 ) ;
if ( V_331 < 0 )
return 0 ;
V_209 = F_194 ( V_19 ) ;
if ( V_209 < 0 )
return V_209 ;
for ( V_16 = 0 ; V_16 < V_149 -> V_197 ; V_16 ++ ) {
T_1 V_47 ;
V_47 = V_149 -> V_198 [ V_16 ] . V_47 ;
if ( ! F_189 ( V_19 , V_47 ) )
continue;
V_20 = V_276 ;
if ( V_149 -> V_198 [ V_16 ] . type == V_196 )
V_20 |= F_158 ( V_19 , V_47 ) ;
if ( V_47 != V_2 -> V_273 &&
! F_16 ( V_19 , V_47 ) )
F_17 ( V_19 , V_47 , V_20 , false ) ;
if ( V_341 ) {
if ( F_28 ( V_19 , V_47 , V_341 ) ) {
V_209 = F_188 ( V_19 , V_16 , V_47 ,
V_2 -> V_339 [ V_16 ] ,
V_2 -> V_340 [ V_16 ] ,
V_341 ) ;
if ( V_209 < 0 )
return V_209 ;
}
}
V_209 = F_192 ( V_19 , V_47 , V_16 , V_331 ,
V_2 -> V_339 [ V_16 ] , - V_341 ) ;
if ( V_209 < 0 )
return V_209 ;
if ( V_2 -> V_42 ) {
V_209 = F_180 ( V_19 , V_47 ) ;
if ( V_209 < 0 )
return V_209 ;
}
}
if ( V_341 && V_2 -> V_41 == V_342 ) {
V_209 = F_192 ( V_19 , V_341 , V_343 , V_331 ,
L_73 , 0 ) ;
if ( V_209 < 0 )
return V_209 ;
else
V_2 -> V_32 = 1 ;
}
return 0 ;
}
static struct V_6 * F_197 ( struct V_18 * V_19 , int V_344 , int V_334 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_334 < 0 || V_334 >= V_345 ) {
F_103 () ;
return NULL ;
}
if ( V_2 -> V_329 )
V_344 = V_2 -> V_328 [ V_334 ] ;
if ( V_344 < 0 || V_344 >= V_283 ) {
F_103 () ;
return NULL ;
}
return F_26 ( V_19 , V_2 -> V_212 [ V_334 ] [ V_344 ] ) ;
}
static int F_198 ( struct V_139 * V_140 ,
struct V_239 * V_240 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
return F_199 ( & V_2 -> V_325 , V_240 ) ;
}
static int F_200 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_344 = F_201 ( V_140 , & V_142 -> V_346 ) ;
V_142 -> V_145 . V_241 . V_242 [ 0 ] = V_2 -> V_274 [ V_344 ] ;
return 0 ;
}
static int F_202 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
unsigned int V_344 = F_201 ( V_140 , & V_142 -> V_346 ) ;
return F_203 ( V_19 , V_344 ,
V_142 -> V_145 . V_241 . V_242 [ 0 ] ) ;
}
static int F_204 ( struct V_139 * V_140 ,
struct V_141 * V_142 ,
T_4 V_347 , int type )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_323 * V_324 ;
struct V_6 * V_53 ;
int V_16 , V_344 , V_209 = 0 ;
V_324 = & V_2 -> V_325 ;
V_344 = V_140 -> V_346 . V_129 ;
F_139 ( & V_19 -> V_348 ) ;
for ( V_16 = 0 ; V_16 < V_324 -> V_327 ; V_16 ++ ) {
V_53 = F_197 ( V_19 , V_344 , V_16 ) ;
if ( ! V_53 || ! V_53 -> V_61 [ type ] )
continue;
V_140 -> V_132 = V_53 -> V_61 [ type ] ;
V_209 = V_347 ( V_140 , V_142 ) ;
if ( V_209 < 0 )
break;
}
F_142 ( & V_19 -> V_348 ) ;
if ( V_209 >= 0 && V_2 -> V_349 )
V_2 -> V_349 ( V_19 , V_140 , V_142 ) ;
return V_209 ;
}
static int F_205 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
return F_204 ( V_140 , V_142 ,
V_350 ,
V_107 ) ;
}
static int F_206 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
return F_204 ( V_140 , V_142 ,
F_97 ,
V_106 ) ;
}
static int F_207 ( struct V_18 * V_19 , struct V_6 * V_53 )
{
T_1 V_51 ;
int V_16 , V_54 ;
V_53 -> V_61 [ V_107 ] = V_53 -> V_61 [ V_106 ] = 0 ;
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
if ( V_54 >= V_53 -> V_54 )
return - V_258 ;
V_16 = V_53 -> V_54 - V_54 - 1 ;
V_51 = V_53 -> V_53 [ V_16 ] ;
if ( ! V_53 -> V_61 [ V_107 ] ) {
if ( F_51 ( V_19 , V_51 , V_83 ) )
V_53 -> V_61 [ V_107 ] =
F_32 ( V_51 , 3 , 0 , V_83 ) ;
else if ( F_51 ( V_19 , V_51 , V_84 ) ) {
int V_59 = V_53 -> V_59 [ V_16 ] ;
if ( ! V_54 && V_19 -> V_29 )
V_59 = 0 ;
V_53 -> V_61 [ V_107 ] =
F_32 ( V_51 , 3 , V_59 , V_84 ) ;
}
}
if ( ! V_53 -> V_61 [ V_106 ] ) {
if ( F_49 ( V_19 , V_51 , V_83 ) )
V_53 -> V_61 [ V_106 ] =
F_32 ( V_51 , 3 , 0 , V_83 ) ;
else if ( F_49 ( V_19 , V_51 , V_84 ) ) {
int V_59 = V_53 -> V_59 [ V_16 ] ;
if ( ! V_54 && V_19 -> V_29 )
V_59 = 0 ;
V_53 -> V_61 [ V_106 ] =
F_32 ( V_51 , 3 , V_59 , V_84 ) ;
}
}
}
return 0 ;
}
static bool F_208 ( struct V_18 * V_19 , T_1 V_51 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_148 * V_149 = & V_2 -> V_150 ;
unsigned int V_20 ;
int V_16 ;
if ( ! V_2 -> V_39 )
return false ;
for ( V_16 = 0 ; V_16 < V_149 -> V_197 ; V_16 ++ ) {
if ( V_149 -> V_198 [ V_16 ] . V_47 != V_51 )
continue;
if ( V_149 -> V_198 [ V_16 ] . type != V_196 )
return false ;
V_20 = F_110 ( V_19 , V_51 ) ;
return F_161 ( V_20 ) == V_282 ;
}
return false ;
}
static int F_209 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_245 ;
V_245 = F_97 ( V_140 , V_142 ) ;
if ( V_245 < 0 )
return V_245 ;
if ( V_2 -> V_349 )
V_2 -> V_349 ( V_19 , V_140 , V_142 ) ;
return V_245 ;
}
static int F_210 ( struct V_18 * V_19 , const char * V_332 ,
int V_59 , bool V_351 , unsigned int V_352 ,
bool V_353 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
char V_354 [ V_134 ] ;
int type = V_351 ? V_137 : V_136 ;
const char * V_133 = V_351 ? L_74 : L_75 ;
unsigned int V_80 = V_353 ? 1 : 3 ;
struct V_4 * V_12 ;
if ( ! V_352 )
return 0 ;
if ( V_332 )
snprintf ( V_354 , sizeof( V_354 ) ,
L_76 , V_332 , V_133 ) ;
else
snprintf ( V_354 , sizeof( V_354 ) ,
L_77 , V_133 ) ;
V_12 = F_82 ( V_2 , type , V_354 , V_59 ,
F_45 ( V_352 , V_80 ) ) ;
if ( ! V_12 )
return - V_135 ;
if ( V_351 )
V_12 -> V_355 = F_209 ;
if ( ! V_353 )
return 0 ;
if ( V_332 )
snprintf ( V_354 , sizeof( V_354 ) ,
L_78 , V_332 , V_133 ) ;
else
snprintf ( V_354 , sizeof( V_354 ) ,
L_79 , V_133 ) ;
V_12 = F_82 ( V_2 , type , V_354 , V_59 ,
F_45 ( V_352 , 2 ) ) ;
if ( ! V_12 )
return - V_135 ;
if ( V_351 )
V_12 -> V_355 = F_209 ;
return 0 ;
}
static int F_211 ( struct V_18 * V_19 , int V_59 ,
unsigned int V_356 , unsigned int V_357 ,
bool V_353 )
{
int V_209 ;
V_209 = F_210 ( V_19 , NULL , V_59 , false , V_356 , V_353 ) ;
if ( V_209 < 0 )
return V_209 ;
V_209 = F_210 ( V_19 , NULL , V_59 , true , V_357 , V_353 ) ;
if ( V_209 < 0 )
return V_209 ;
return 0 ;
}
static int F_212 ( struct V_18 * V_19 , int V_59 ,
unsigned int V_356 , unsigned int V_357 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
if ( V_356 ) {
V_12 = F_4 ( V_2 , NULL , & V_358 ) ;
if ( ! V_12 )
return - V_135 ;
V_12 -> V_129 = V_59 ;
V_12 -> V_132 = V_356 ;
V_12 -> V_130 = V_131 ;
}
if ( V_357 ) {
V_12 = F_4 ( V_2 , NULL , & V_359 ) ;
if ( ! V_12 )
return - V_135 ;
V_12 -> V_129 = V_59 ;
V_12 -> V_132 = V_357 ;
V_12 -> V_130 = V_131 ;
}
return 0 ;
}
static unsigned int F_213 ( struct V_18 * V_19 , int V_59 , int type )
{
struct V_6 * V_53 ;
unsigned int V_352 ;
int V_16 ;
V_53 = F_197 ( V_19 , 0 , V_59 ) ;
if ( ! V_53 )
return 0 ;
V_352 = V_53 -> V_61 [ type ] ;
if ( ! V_352 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_59 - 1 ; V_16 ++ ) {
V_53 = F_197 ( V_19 , 0 , V_16 ) ;
if ( V_53 && V_53 -> V_61 [ type ] == V_352 )
return 0 ;
}
return V_352 ;
}
static int F_214 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_323 * V_324 = & V_2 -> V_325 ;
int V_16 , V_209 , type ;
for ( V_16 = 0 ; V_16 < V_324 -> V_327 ; V_16 ++ ) {
bool V_353 ;
int V_59 ;
V_59 = V_324 -> V_256 [ V_16 ] . V_129 ;
if ( V_59 >= V_2 -> V_150 . V_197 )
continue;
V_353 = F_208 ( V_19 , V_2 -> V_338 [ V_16 ] ) ;
for ( type = 0 ; type < 2 ; type ++ ) {
V_209 = F_210 ( V_19 ,
V_2 -> V_339 [ V_59 ] ,
V_2 -> V_340 [ V_59 ] ,
type ,
F_213 ( V_19 , V_16 , type ) ,
V_353 ) ;
if ( V_209 < 0 )
return V_209 ;
}
}
return 0 ;
}
static int F_215 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_323 * V_324 = & V_2 -> V_325 ;
int V_16 , V_89 , V_52 , V_209 ;
if ( V_2 -> V_329 )
V_52 = 1 ;
else
V_52 = V_2 -> V_320 ;
if ( ! V_2 -> V_360 && V_324 -> V_327 > 1 ) {
struct V_4 * V_12 ;
const char * V_10 ;
V_10 = V_52 > 1 ? L_80 : L_81 ;
V_12 = F_4 ( V_2 , V_10 , & V_361 ) ;
if ( ! V_12 )
return - V_135 ;
V_12 -> V_255 = V_52 ;
}
for ( V_89 = 0 ; V_89 < V_52 ; V_89 ++ ) {
bool V_73 = false ;
bool V_38 = V_2 -> V_38 ;
bool V_353 = false ;
int V_362 , V_363 ;
V_362 = V_363 = 0 ;
for ( V_16 = 0 ; V_16 < V_324 -> V_327 ; V_16 ++ ) {
struct V_6 * V_53 ;
V_53 = F_197 ( V_19 , V_89 , V_16 ) ;
if ( ! V_53 )
continue;
F_207 ( V_19 , V_53 ) ;
if ( ! V_362 )
V_362 = V_53 -> V_61 [ V_107 ] ;
else if ( V_362 != V_53 -> V_61 [ V_107 ] ) {
V_73 = true ;
if ( ! F_46 ( V_19 , V_362 ,
V_53 -> V_61 [ V_107 ] , V_84 ) )
V_38 = true ;
}
if ( ! V_363 )
V_363 = V_53 -> V_61 [ V_106 ] ;
else if ( V_363 != V_53 -> V_61 [ V_106 ] ) {
V_73 = true ;
if ( ! F_46 ( V_19 , V_363 ,
V_53 -> V_61 [ V_106 ] , V_84 ) )
V_38 = true ;
}
if ( F_208 ( V_19 , V_2 -> V_338 [ V_16 ] ) )
V_353 = true ;
}
if ( ! V_73 )
V_209 = F_211 ( V_19 , V_89 , V_362 , V_363 ,
V_353 ) ;
else if ( ! V_38 && ! V_353 )
V_209 = F_212 ( V_19 , V_89 , V_362 , V_363 ) ;
else
V_209 = F_214 ( V_19 ) ;
if ( V_209 < 0 )
return V_209 ;
}
return 0 ;
}
static bool F_216 ( struct V_18 * V_19 , T_1 V_51 ,
int V_62 , int V_59 )
{
unsigned int V_364 ;
if ( ! F_51 ( V_19 , V_51 , V_62 ) ||
F_31 ( V_19 , V_51 , V_62 , V_59 , V_107 ) ||
F_31 ( V_19 , V_51 , V_62 , V_59 , V_108 ) )
return false ;
V_364 = ( F_47 ( V_19 , V_51 , V_62 ) & V_365 )
>> V_366 ;
if ( V_364 < 0x20 )
return false ;
return true ;
}
static unsigned int F_217 ( struct V_18 * V_19 ,
struct V_6 * V_53 )
{
unsigned int V_20 = 0 ;
T_1 V_51 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
if ( V_54 >= V_53 -> V_54 - 1 )
break;
V_51 = V_53 -> V_53 [ V_54 ] ;
if ( V_54 && F_216 ( V_19 , V_51 , V_83 , 0 ) ) {
V_20 = F_32 ( V_51 , 3 , 0 , V_83 ) ;
break;
} else if ( F_216 ( V_19 , V_51 , V_84 ,
V_53 -> V_59 [ V_54 ] ) ) {
V_20 = F_32 ( V_51 , 3 , V_53 -> V_59 [ V_54 ] ,
V_84 ) ;
break;
}
}
return V_20 ;
}
static int F_218 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_148 * V_149 = & V_2 -> V_150 ;
struct V_323 * V_324 = & V_2 -> V_325 ;
int V_16 ;
if ( ! V_2 -> V_320 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_324 -> V_327 ; V_16 ++ ) {
struct V_6 * V_53 ;
unsigned int V_20 ;
int V_59 ;
char V_367 [ V_134 ] ;
V_59 = V_324 -> V_256 [ V_16 ] . V_129 ;
if ( V_59 >= V_324 -> V_327 )
continue;
if ( V_149 -> V_198 [ V_59 ] . type > V_195 )
continue;
V_53 = F_197 ( V_19 , 0 , V_16 ) ;
if ( ! V_53 )
continue;
V_20 = F_217 ( V_19 , V_53 ) ;
if ( ! V_20 )
continue;
snprintf ( V_367 , sizeof( V_367 ) ,
L_82 , V_2 -> V_339 [ V_59 ] ) ;
if ( ! F_82 ( V_2 , V_136 , V_367 ,
V_2 -> V_340 [ V_59 ] , V_20 ) )
return - V_135 ;
V_53 -> V_61 [ V_108 ] = V_20 ;
}
return 0 ;
}
static void F_219 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_53 ;
int V_16 , V_52 ;
T_1 V_368 , V_47 ;
V_52 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_150 . V_369 ; V_16 ++ ) {
V_47 = V_2 -> V_150 . V_370 [ V_16 ] ;
V_368 = F_44 ( V_19 , V_47 , true ) ;
if ( ! V_368 )
continue;
V_53 = F_41 ( V_19 , V_368 , V_47 , 0 ) ;
if ( ! V_53 )
continue;
F_33 ( V_19 , L_83 , V_53 ) ;
V_53 -> V_92 = true ;
V_53 -> V_95 = true ;
V_2 -> V_211 [ V_16 ] = F_25 ( V_19 , V_53 ) ;
F_17 ( V_19 , V_47 , V_236 , false ) ;
if ( ! V_52 ) {
V_2 -> V_157 . V_371 = V_368 ;
V_2 -> V_372 = V_2 -> V_150 . V_372 [ 0 ] ;
} else {
V_2 -> V_157 . V_373 = V_2 -> V_373 ;
if ( V_52 >= F_102 ( V_2 -> V_373 ) - 1 )
break;
V_2 -> V_373 [ V_52 - 1 ] = V_368 ;
}
V_52 ++ ;
}
if ( V_2 -> V_150 . V_374 ) {
V_47 = V_2 -> V_150 . V_374 ;
F_125 (dig_nid, codec) {
unsigned int V_103 = F_39 ( V_19 , V_368 ) ;
if ( F_38 ( V_103 ) != V_70 )
continue;
if ( ! ( V_103 & V_79 ) )
continue;
V_53 = F_41 ( V_19 , V_47 , V_368 , 0 ) ;
if ( V_53 ) {
F_33 ( V_19 , L_84 , V_53 ) ;
V_53 -> V_92 = true ;
V_53 -> V_95 = true ;
V_2 -> V_375 = V_368 ;
V_2 -> V_214 = F_25 ( V_19 , V_53 ) ;
F_17 ( V_19 , V_47 , V_276 , false ) ;
break;
}
}
}
}
static int F_203 ( struct V_18 * V_19 , unsigned int V_344 ,
unsigned int V_59 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_323 * V_324 ;
struct V_6 * V_376 , * V_53 ;
V_324 = & V_2 -> V_325 ;
if ( ! V_324 -> V_327 )
return 0 ;
if ( V_59 >= V_324 -> V_327 )
V_59 = V_324 -> V_327 - 1 ;
if ( V_2 -> V_274 [ V_344 ] == V_59 )
return 0 ;
V_376 = F_197 ( V_19 , V_344 , V_2 -> V_274 [ V_344 ] ) ;
if ( ! V_376 )
return 0 ;
if ( V_376 -> V_92 )
F_76 ( V_19 , V_376 , false , false ) ;
V_2 -> V_274 [ V_344 ] = V_59 ;
if ( V_2 -> V_44 )
F_157 ( V_19 , V_344 , false ) ;
if ( V_2 -> V_329 )
F_220 ( V_19 , V_59 ) ;
V_53 = F_197 ( V_19 , V_344 , V_59 ) ;
if ( ! V_53 )
return 0 ;
if ( V_53 -> V_92 )
return 0 ;
F_76 ( V_19 , V_53 , true , false ) ;
if ( V_2 -> V_349 )
V_2 -> V_349 ( V_19 , NULL , NULL ) ;
F_78 ( V_19 , V_376 ) ;
return 1 ;
}
static T_1 F_221 ( struct V_18 * V_19 , T_1 V_51 ,
int V_377 , int V_378 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_379 , V_113 = 0 ;
struct V_6 * V_53 ;
int V_89 ;
for ( V_89 = 0 ; V_89 < V_2 -> V_5 . V_17 ; V_89 ++ ) {
V_53 = F_24 ( & V_2 -> V_5 , V_89 ) ;
if ( V_53 -> V_53 [ 0 ] == V_51 ||
V_53 -> V_53 [ V_53 -> V_54 - 1 ] == V_51 ) {
bool V_380 = V_53 -> V_94 ;
bool V_381 = V_53 -> V_93 ;
if ( V_377 >= 0 )
V_53 -> V_94 = V_377 ;
if ( V_378 >= 0 )
V_53 -> V_93 = V_378 ;
if ( ( ! V_53 -> V_95 && V_53 -> V_94 != V_380 )
|| V_53 -> V_93 != V_381 ) {
V_379 = F_70 ( V_19 , V_53 , true ) ;
if ( V_379 )
V_113 = V_379 ;
}
}
}
return V_113 ;
}
static bool F_222 ( struct V_18 * V_19 , T_1 V_47 )
{
if ( ! F_223 ( V_19 , V_47 ) )
return true ;
return F_224 ( V_19 , V_47 ) != V_382 ;
}
static T_1 F_225 ( struct V_18 * V_19 , T_1 V_47 ,
int V_115 )
{
bool V_383 ;
if ( ! V_19 -> V_30 )
return 0 ;
V_383 = F_222 ( V_19 , V_47 ) ;
if ( V_115 >= 0 && V_383 != V_115 )
return 0 ;
return F_221 ( V_19 , V_47 , V_383 , - 1 ) ;
}
static void F_226 ( struct V_18 * V_19 ,
struct V_384 * V_385 ,
bool V_383 )
{
if ( V_385 && V_385 -> V_51 )
F_74 ( V_19 ,
F_225 ( V_19 , V_385 -> V_51 , V_383 ) ) ;
}
static void F_227 ( struct V_18 * V_19 ,
struct V_384 * V_385 )
{
F_226 ( V_19 , V_385 , true ) ;
}
static void F_228 ( struct V_18 * V_19 ,
struct V_384 * V_385 )
{
F_226 ( V_19 , V_385 , false ) ;
}
static void F_229 ( struct V_18 * V_19 , int V_49 ,
const T_1 * V_50 , bool V_383 )
{
int V_16 ;
T_5 V_386 =
V_383 ? F_227 : F_228 ;
for ( V_16 = 0 ; V_16 < V_49 && V_50 [ V_16 ] ; V_16 ++ ) {
if ( F_223 ( V_19 , V_50 [ V_16 ] ) )
F_230 ( V_19 , V_50 [ V_16 ] , V_386 ) ;
else
F_221 ( V_19 , V_50 [ V_16 ] , true , - 1 ) ;
}
}
static void F_231 ( struct V_18 * V_19 , bool V_383 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_148 * V_149 = & V_2 -> V_150 ;
int V_16 ;
if ( ! V_19 -> V_30 )
return;
F_229 ( V_19 , V_149 -> V_151 , V_149 -> V_216 , V_383 ) ;
if ( V_149 -> V_162 != V_165 )
F_229 ( V_19 , V_149 -> V_153 , V_149 -> V_217 , V_383 ) ;
if ( V_149 -> V_162 != V_163 )
F_229 ( V_19 , V_149 -> V_154 , V_149 -> V_218 , V_383 ) ;
for ( V_16 = 0 ; V_16 < V_149 -> V_197 ; V_16 ++ )
F_229 ( V_19 , 1 , & V_149 -> V_198 [ V_16 ] . V_47 , V_383 ) ;
}
static void F_232 ( struct V_18 * V_19 , int V_49 ,
const T_1 * V_50 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_49 && V_50 [ V_16 ] ; V_16 ++ )
if ( F_223 ( V_19 , V_50 [ V_16 ] ) )
F_225 ( V_19 , V_50 [ V_16 ] , - 1 ) ;
}
static void F_233 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_148 * V_149 = & V_2 -> V_150 ;
int V_16 ;
if ( ! V_19 -> V_30 )
return;
F_232 ( V_19 , V_149 -> V_151 , V_149 -> V_216 ) ;
if ( V_149 -> V_162 != V_165 )
F_232 ( V_19 , V_149 -> V_153 , V_149 -> V_217 ) ;
if ( V_149 -> V_162 != V_163 )
F_232 ( V_19 , V_149 -> V_154 , V_149 -> V_218 ) ;
for ( V_16 = 0 ; V_16 < V_149 -> V_197 ; V_16 ++ )
F_232 ( V_19 , 1 , & V_149 -> V_198 [ V_16 ] . V_47 ) ;
}
static int F_234 ( struct V_18 * V_19 , T_1 V_51 ,
int V_49 , const T_1 * V_50 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_53 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_49 ; V_16 ++ ) {
if ( ! V_50 [ V_16 ] )
break;
if ( F_23 ( V_19 , V_51 , V_50 [ V_16 ] , 0 ) )
continue;
V_53 = F_5 ( & V_2 -> V_5 ) ;
if ( ! V_53 )
return - V_135 ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_53 -> V_54 = 2 ;
V_53 -> V_53 [ 0 ] = V_51 ;
V_53 -> V_53 [ 1 ] = V_50 [ V_16 ] ;
V_53 -> V_92 = true ;
}
return 0 ;
}
static int F_235 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_148 * V_149 = & V_2 -> V_150 ;
T_1 V_51 = V_2 -> V_387 ;
int V_209 ;
if ( ! V_19 -> V_30 || ! V_51 )
return 0 ;
V_209 = F_234 ( V_19 , V_51 , V_149 -> V_151 , V_149 -> V_216 ) ;
if ( V_209 < 0 )
return V_209 ;
if ( V_149 -> V_162 != V_165 ) {
V_209 = F_234 ( V_19 , V_51 , V_149 -> V_153 , V_149 -> V_217 ) ;
if ( V_209 < 0 )
return V_209 ;
}
if ( V_149 -> V_162 != V_163 ) {
V_209 = F_234 ( V_19 , V_51 , V_149 -> V_154 ,
V_149 -> V_218 ) ;
if ( V_209 < 0 )
return V_209 ;
}
return 0 ;
}
static void F_236 ( struct V_388 * V_389 , bool V_383 )
{
F_221 ( V_389 -> V_19 , V_389 -> V_51 , - 1 , V_383 ) ;
}
int F_237 ( struct V_18 * V_19 , T_1 V_47 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_53 ;
V_53 = F_5 ( & V_2 -> V_5 ) ;
if ( ! V_53 )
return - V_135 ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_53 -> V_54 = 1 ;
V_53 -> V_53 [ 0 ] = V_47 ;
V_53 -> V_92 = true ;
V_53 -> V_95 = true ;
V_53 -> V_93 = true ;
return 0 ;
}
static bool F_238 ( struct V_18 * V_19 , int V_49 , T_1 * V_50 )
{
int V_16 ;
bool V_390 = false ;
for ( V_16 = 0 ; V_16 < V_49 ; V_16 ++ ) {
T_1 V_51 = V_50 [ V_16 ] ;
if ( ! V_51 )
break;
if ( F_16 ( V_19 , V_51 ) & V_391 )
continue;
if ( F_224 ( V_19 , V_51 ) == V_392 )
V_390 = true ;
}
return V_390 ;
}
static void F_239 ( struct V_18 * V_19 , int V_49 , T_1 * V_50 ,
int * V_5 , bool V_393 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_49 ; V_16 ++ ) {
T_1 V_51 = V_50 [ V_16 ] ;
unsigned int V_20 , V_305 ;
if ( ! V_51 )
break;
V_305 = F_16 ( V_19 , V_51 ) ;
if ( V_305 & V_276 )
continue;
if ( V_2 -> V_34 ) {
struct V_6 * V_53 ;
T_1 V_394 ;
V_53 = F_26 ( V_19 , V_5 [ V_16 ] ) ;
if ( ! V_53 )
continue;
V_394 = F_83 ( V_53 -> V_61 [ V_106 ] ) ;
if ( ! V_394 )
continue;
if ( V_393 )
V_2 -> V_144 |= ( 1ULL << V_394 ) ;
else
V_2 -> V_144 &= ~ ( 1ULL << V_394 ) ;
continue;
} else {
if ( V_2 -> V_395 )
V_20 = V_305 & ~ V_235 ;
else
V_20 = 0 ;
if ( ! V_393 )
V_20 |= V_305 ;
F_15 ( V_19 , V_51 , V_20 ) ;
}
F_79 ( V_19 , V_51 , ! V_393 ) ;
if ( V_19 -> V_30 ) {
bool V_383 = ! V_393 ;
if ( V_383 )
V_383 = F_222 ( V_19 , V_51 ) ;
F_221 ( V_19 , V_51 , V_383 , - 1 ) ;
}
}
}
void F_240 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int * V_5 ;
int V_383 ;
if ( V_2 -> V_150 . V_162 == V_165 )
V_5 = V_2 -> V_202 ;
else
V_5 = V_2 -> V_164 ;
F_239 ( V_19 , F_102 ( V_2 -> V_150 . V_217 ) ,
V_2 -> V_150 . V_217 , V_5 , V_2 -> V_396 ) ;
if ( ! V_2 -> V_397 )
V_383 = 0 ;
else
V_383 = V_2 -> V_398 | V_2 -> V_399 ;
V_383 |= V_2 -> V_396 ;
V_2 -> V_400 = V_383 ;
if ( V_2 -> V_150 . V_162 == V_163 )
V_5 = V_2 -> V_202 ;
else
V_5 = V_2 -> V_166 ;
F_239 ( V_19 , F_102 ( V_2 -> V_150 . V_218 ) ,
V_2 -> V_150 . V_218 , V_5 , V_383 ) ;
if ( V_2 -> V_150 . V_216 [ 0 ] == V_2 -> V_150 . V_217 [ 0 ] ||
V_2 -> V_150 . V_216 [ 0 ] == V_2 -> V_150 . V_218 [ 0 ] )
return;
if ( ! V_2 -> V_401 )
V_383 = 0 ;
else
V_383 = V_2 -> V_398 ;
V_383 |= V_2 -> V_396 ;
V_2 -> V_402 = V_383 ;
V_5 = V_2 -> V_202 ;
F_239 ( V_19 , F_102 ( V_2 -> V_150 . V_216 ) ,
V_2 -> V_150 . V_216 , V_5 , V_383 ) ;
}
static void F_241 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_403 )
V_2 -> V_403 ( V_19 ) ;
else
F_240 ( V_19 ) ;
if ( V_2 -> V_34 && ! V_19 -> V_404 -> V_405 )
F_242 ( V_2 -> V_155 . V_406 , false ) ;
}
void F_243 ( struct V_18 * V_19 ,
struct V_384 * V_385 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 * V_50 = V_2 -> V_150 . V_217 ;
int V_49 = F_102 ( V_2 -> V_150 . V_217 ) ;
if ( V_2 -> V_243 ) {
V_50 ++ ;
V_49 -- ;
}
V_2 -> V_398 = F_238 ( V_19 , V_49 , V_50 ) ;
if ( ! V_2 -> V_407 || ( ! V_2 -> V_397 && ! V_2 -> V_401 ) )
return;
F_241 ( V_19 ) ;
}
void F_244 ( struct V_18 * V_19 ,
struct V_384 * V_385 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_150 . V_162 == V_163 )
return;
if ( V_2 -> V_150 . V_216 [ 0 ] == V_2 -> V_150 . V_217 [ 0 ] )
return;
V_2 -> V_399 =
F_238 ( V_19 , F_102 ( V_2 -> V_150 . V_216 ) ,
V_2 -> V_150 . V_216 ) ;
if ( ! V_2 -> V_397 || ! V_2 -> V_408 )
return;
F_241 ( V_19 ) ;
}
void F_245 ( struct V_18 * V_19 ,
struct V_384 * V_385 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
if ( ! V_2 -> V_360 )
return;
for ( V_16 = V_2 -> V_409 - 1 ; V_16 > 0 ; V_16 -- ) {
T_1 V_47 = V_2 -> V_410 [ V_16 ] . V_47 ;
if ( F_16 ( V_19 , V_47 ) & V_411 )
continue;
if ( F_224 ( V_19 , V_47 ) == V_392 ) {
F_203 ( V_19 , 0 , V_2 -> V_410 [ V_16 ] . V_59 ) ;
return;
}
}
F_203 ( V_19 , 0 , V_2 -> V_410 [ 0 ] . V_59 ) ;
}
static void F_141 ( struct V_18 * V_19 ,
struct V_384 * V_385 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_412 )
V_2 -> V_412 ( V_19 , V_385 ) ;
else
F_243 ( V_19 , V_385 ) ;
}
static void F_246 ( struct V_18 * V_19 ,
struct V_384 * V_385 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_413 )
V_2 -> V_413 ( V_19 , V_385 ) ;
else
F_244 ( V_19 , V_385 ) ;
}
static void F_247 ( struct V_18 * V_19 ,
struct V_384 * V_385 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_414 )
V_2 -> V_414 ( V_19 , V_385 ) ;
else
F_245 ( V_19 , V_385 ) ;
}
static void F_149 ( struct V_18 * V_19 )
{
F_141 ( V_19 , NULL ) ;
F_246 ( V_19 , NULL ) ;
F_247 ( V_19 , NULL ) ;
}
static int F_248 ( struct V_139 * V_140 ,
struct V_239 * V_240 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_415 [] = {
L_85 , L_86 , L_87
} ;
if ( V_2 -> V_416 && V_2 -> V_417 )
return F_163 ( V_140 , V_240 , 3 , V_415 ) ;
return F_136 ( V_140 , V_240 ) ;
}
static int F_249 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = 0 ;
if ( V_2 -> V_397 )
V_20 ++ ;
if ( V_2 -> V_401 )
V_20 ++ ;
V_142 -> V_145 . V_241 . V_242 [ 0 ] = V_20 ;
return 0 ;
}
static int F_250 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_18 * V_19 = F_94 ( V_140 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
switch ( V_142 -> V_145 . V_241 . V_242 [ 0 ] ) {
case 0 :
if ( ! V_2 -> V_397 && ! V_2 -> V_401 )
return 0 ;
V_2 -> V_397 = 0 ;
V_2 -> V_401 = 0 ;
break;
case 1 :
if ( V_2 -> V_416 ) {
if ( ! V_2 -> V_401 && V_2 -> V_397 )
return 0 ;
V_2 -> V_397 = 1 ;
V_2 -> V_401 = 0 ;
} else if ( V_2 -> V_417 ) {
if ( V_2 -> V_401 )
return 0 ;
V_2 -> V_401 = 1 ;
} else
return - V_258 ;
break;
case 2 :
if ( ! V_2 -> V_417 || ! V_2 -> V_416 )
return - V_258 ;
if ( V_2 -> V_397 && V_2 -> V_401 )
return 0 ;
V_2 -> V_397 = 1 ;
V_2 -> V_401 = 1 ;
break;
default:
return - V_258 ;
}
F_241 ( V_19 ) ;
return 1 ;
}
static int F_251 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! F_4 ( V_2 , NULL , & V_418 ) )
return - V_135 ;
return 0 ;
}
static int F_252 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_148 * V_149 = & V_2 -> V_150 ;
int V_390 = 0 ;
int V_16 , V_209 ;
if ( V_2 -> V_31 )
return 0 ;
if ( V_149 -> V_217 [ 0 ] )
V_390 ++ ;
if ( V_149 -> V_216 [ 0 ] )
V_390 ++ ;
if ( V_149 -> V_218 [ 0 ] )
V_390 ++ ;
if ( V_390 < 2 )
return 0 ;
if ( ! V_149 -> V_218 [ 0 ] &&
V_149 -> V_162 == V_163 ) {
memcpy ( V_149 -> V_218 , V_149 -> V_216 ,
sizeof( V_149 -> V_218 ) ) ;
V_149 -> V_154 = V_149 -> V_151 ;
}
if ( ! V_149 -> V_217 [ 0 ] &&
V_149 -> V_162 == V_165 ) {
memcpy ( V_149 -> V_217 , V_149 -> V_216 ,
sizeof( V_149 -> V_217 ) ) ;
V_149 -> V_153 = V_149 -> V_151 ;
}
for ( V_16 = 0 ; V_16 < V_149 -> V_153 ; V_16 ++ ) {
T_1 V_51 = V_149 -> V_217 [ V_16 ] ;
if ( ! F_223 ( V_19 , V_51 ) )
continue;
F_35 ( V_19 , L_88 , V_51 ) ;
F_230 ( V_19 , V_51 ,
F_141 ) ;
V_2 -> V_407 = 1 ;
}
if ( V_149 -> V_162 == V_167 && V_149 -> V_151 ) {
if ( V_149 -> V_154 )
for ( V_16 = 0 ; V_16 < V_149 -> V_151 ; V_16 ++ ) {
T_1 V_51 = V_149 -> V_216 [ V_16 ] ;
if ( ! F_223 ( V_19 , V_51 ) )
continue;
F_35 ( V_19 , L_89 , V_51 ) ;
F_230 ( V_19 , V_51 ,
F_246 ) ;
V_2 -> V_408 = 1 ;
}
V_2 -> V_417 = V_2 -> V_407 ;
}
V_2 -> V_416 = V_149 -> V_154 &&
( V_2 -> V_407 || V_2 -> V_408 ) ;
V_2 -> V_401 = V_2 -> V_417 ;
V_2 -> V_397 = V_2 -> V_416 ;
if ( V_2 -> V_416 || V_2 -> V_417 ) {
V_209 = F_251 ( V_19 ) ;
if ( V_209 < 0 )
return V_209 ;
}
return 0 ;
}
static bool F_253 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_323 * V_324 ;
int V_16 ;
V_324 = & V_2 -> V_325 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_409 ; V_16 ++ ) {
V_2 -> V_410 [ V_16 ] . V_59 =
F_21 ( V_2 -> V_410 [ V_16 ] . V_47 ,
V_2 -> V_338 , V_324 -> V_327 ) ;
if ( V_2 -> V_410 [ V_16 ] . V_59 < 0 )
return false ;
}
for ( V_16 = 1 ; V_16 < V_2 -> V_409 ; V_16 ++ )
F_230 ( V_19 ,
V_2 -> V_410 [ V_16 ] . V_47 ,
F_247 ) ;
return true ;
}
static int F_254 ( const void * V_419 , const void * V_420 )
{
const struct V_421 * V_422 = V_419 ;
const struct V_421 * V_423 = V_420 ;
return ( int ) ( V_422 -> V_424 - V_423 -> V_424 ) ;
}
static int F_255 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_148 * V_149 = & V_2 -> V_150 ;
unsigned int V_425 ;
int V_16 , V_49 ;
if ( V_2 -> V_32 )
return 0 ;
V_425 = 0 ;
V_49 = 0 ;
for ( V_16 = 0 ; V_16 < V_149 -> V_197 ; V_16 ++ ) {
T_1 V_51 = V_149 -> V_198 [ V_16 ] . V_47 ;
unsigned int V_424 ;
V_424 = F_110 ( V_19 , V_51 ) ;
V_424 = F_161 ( V_424 ) ;
if ( V_425 & ( 1 << V_424 ) )
return 0 ;
switch ( V_424 ) {
case V_282 :
if ( V_149 -> V_198 [ V_16 ] . type != V_196 )
return 0 ;
break;
case V_426 :
return 0 ;
default:
if ( V_149 -> V_198 [ V_16 ] . type > V_195 )
return 0 ;
if ( ! V_2 -> V_33 &&
V_149 -> V_198 [ V_16 ] . type != V_196 )
return 0 ;
if ( ! F_223 ( V_19 , V_51 ) )
return 0 ;
break;
}
if ( V_49 >= V_427 )
return 0 ;
V_425 |= ( 1 << V_424 ) ;
V_2 -> V_410 [ V_49 ] . V_47 = V_51 ;
V_2 -> V_410 [ V_49 ] . V_424 = V_424 ;
V_49 ++ ;
}
if ( V_49 < 2 )
return 0 ;
V_2 -> V_409 = V_49 ;
F_256 ( V_2 -> V_410 , V_49 , sizeof( V_2 -> V_410 [ 0 ] ) ,
F_254 , NULL ) ;
if ( ! F_253 ( V_19 ) )
return 0 ;
V_2 -> V_360 = 1 ;
V_2 -> V_320 = 1 ;
V_2 -> V_274 [ 0 ] = V_2 -> V_410 [ 0 ] . V_59 ;
F_35 ( V_19 , L_90 ,
V_2 -> V_410 [ 0 ] . V_47 ,
V_2 -> V_410 [ 1 ] . V_47 ,
V_2 -> V_410 [ 2 ] . V_47 ) ;
return 0 ;
}
unsigned int F_257 ( struct V_18 * V_19 ,
T_1 V_51 ,
unsigned int V_428 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_43 && ! V_19 -> V_30 )
return V_428 ;
if ( V_428 != V_117 || V_51 == V_19 -> V_90 . V_91 )
return V_428 ;
if ( F_38 ( F_39 ( V_19 , V_51 ) ) >= V_429 )
return V_428 ;
if ( F_71 ( V_19 , V_51 ) )
return V_428 ;
return V_118 ;
}
static void F_258 ( struct V_18 * V_19 , T_1 V_307 )
{
int V_16 , V_52 ;
const T_1 * V_66 ;
bool V_430 ;
V_52 = F_37 ( V_19 , V_307 , & V_66 ) ;
V_430 = F_49 ( V_19 , V_307 , V_84 ) ;
for ( V_16 = 0 ; V_16 < V_52 ; V_16 ++ ) {
if ( V_430 )
F_62 ( V_19 , V_307 , V_84 , V_16 ,
0xff , V_102 ) ;
else if ( F_51 ( V_19 , V_66 [ V_16 ] , V_83 ) )
F_62 ( V_19 , V_66 [ V_16 ] , V_83 , 0 ,
0xff , V_102 ) ;
}
}
void F_259 ( struct V_18 * V_19 , T_1 V_51 , bool V_383 )
{
if ( V_19 -> V_30 )
F_221 ( V_19 , V_51 , - 1 , V_383 ) ;
}
int F_260 ( struct V_18 * V_19 ,
struct V_148 * V_149 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_209 ;
F_11 ( V_19 ) ;
if ( V_2 -> V_46 && ! V_2 -> V_111 )
V_2 -> V_111 = V_2 -> V_46 ;
if ( V_149 != & V_2 -> V_150 ) {
V_2 -> V_150 = * V_149 ;
V_149 = & V_2 -> V_150 ;
}
if ( ! V_2 -> V_219 )
V_2 -> V_219 = & V_431 ;
if ( ! V_2 -> V_220 )
V_2 -> V_220 = & V_432 ;
F_124 ( V_19 ) ;
if ( ! V_149 -> V_151 ) {
if ( V_149 -> V_369 || V_149 -> V_374 ) {
V_2 -> V_157 . V_260 = 2 ;
V_2 -> V_433 = 1 ;
goto V_434;
}
if ( ! V_149 -> V_197 && ! V_149 -> V_374 )
return 0 ;
}
if ( ! V_2 -> V_36 &&
V_149 -> V_162 == V_163 &&
V_149 -> V_151 <= V_149 -> V_153 ) {
V_149 -> V_154 = V_149 -> V_151 ;
memcpy ( V_149 -> V_218 , V_149 -> V_216 ,
sizeof( V_149 -> V_218 ) ) ;
V_149 -> V_151 = V_149 -> V_153 ;
memcpy ( V_149 -> V_216 , V_149 -> V_217 , sizeof( V_149 -> V_217 ) ) ;
V_149 -> V_153 = 0 ;
memset ( V_149 -> V_217 , 0 , sizeof( V_149 -> V_217 ) ) ;
V_149 -> V_162 = V_165 ;
}
V_209 = F_127 ( V_19 ) ;
if ( V_209 < 0 )
return V_209 ;
V_209 = F_152 ( V_19 ) ;
if ( V_209 < 0 )
return V_209 ;
V_209 = F_130 ( V_19 , V_149 ) ;
if ( V_209 < 0 )
return V_209 ;
V_209 = F_133 ( V_19 ) ;
if ( V_209 < 0 )
return V_209 ;
V_209 = F_134 ( V_19 ) ;
if ( V_209 < 0 )
return V_209 ;
V_209 = F_143 ( V_19 ) ;
if ( V_209 < 0 )
return V_209 ;
V_209 = F_156 ( V_19 ) ;
if ( V_209 < 0 )
return V_209 ;
V_209 = F_160 ( V_19 ) ;
if ( V_209 < 0 )
return V_209 ;
V_209 = F_196 ( V_19 ) ;
if ( V_209 < 0 )
return V_209 ;
F_231 ( V_19 , false ) ;
V_2 -> V_261 = V_2 -> V_221 ;
if ( V_149 -> V_162 != V_163 )
V_2 -> V_261 = F_151 ( V_2 -> V_261 ,
V_149 -> V_154 * 2 ) ;
if ( V_149 -> V_162 != V_165 )
V_2 -> V_261 = F_151 ( V_2 -> V_261 ,
V_149 -> V_153 * 2 ) ;
V_2 -> V_157 . V_260 = F_151 ( V_2 -> V_221 ,
V_2 -> V_261 ) ;
V_209 = F_252 ( V_19 ) ;
if ( V_209 < 0 )
return V_209 ;
V_209 = F_191 ( V_19 ) ;
if ( V_209 < 0 )
return V_209 ;
V_209 = F_255 ( V_19 ) ;
if ( V_209 < 0 )
return V_209 ;
if ( ! V_2 -> V_360 && V_2 -> V_46 &&
V_2 -> V_41 == V_435 &&
V_2 -> V_325 . V_327 > 1 ) {
V_209 = F_192 ( V_19 , V_2 -> V_46 ,
V_343 , V_2 -> V_321 ,
L_73 , 0 ) ;
if ( V_209 < 0 )
return V_209 ;
}
V_209 = F_215 ( V_19 ) ;
if ( V_209 < 0 )
return V_209 ;
V_209 = F_218 ( V_19 ) ;
if ( V_209 < 0 )
return V_209 ;
if ( V_2 -> V_273 &&
( V_2 -> V_360 || V_2 -> V_325 . V_327 == 1 ||
V_2 -> V_42 ) ) {
V_209 = F_185 ( V_19 , V_2 -> V_273 ) ;
if ( V_209 < 0 )
return V_209 ;
}
if ( V_2 -> V_42 ) {
if ( V_149 -> V_162 != V_163 ) {
V_209 = F_171 ( V_19 , V_149 -> V_151 ,
V_149 -> V_216 ) ;
if ( V_209 < 0 )
return V_209 ;
}
if ( V_149 -> V_162 != V_165 ) {
V_209 = F_171 ( V_19 , V_149 -> V_153 ,
V_149 -> V_217 ) ;
if ( V_209 < 0 )
return V_209 ;
}
}
F_231 ( V_19 , true ) ;
if ( V_2 -> V_46 )
F_258 ( V_19 , V_2 -> V_46 ) ;
V_434:
F_219 ( V_19 ) ;
if ( V_2 -> V_43 || V_19 -> V_30 ) {
if ( ! V_19 -> V_436 )
V_19 -> V_436 = F_257 ;
if ( ! V_19 -> V_437 . V_438 )
V_19 -> V_437 . V_438 = F_259 ;
}
if ( ! V_2 -> V_433 && V_2 -> V_387 ) {
V_209 = F_261 ( V_19 , V_2 -> V_387 ) ;
if ( V_209 < 0 )
return V_209 ;
if ( V_19 -> V_389 && V_19 -> V_30 ) {
V_209 = F_235 ( V_19 ) ;
if ( V_209 < 0 )
return V_209 ;
V_19 -> V_389 -> V_439 = F_236 ;
}
}
return 1 ;
}
int F_262 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_209 ;
if ( V_2 -> V_3 . V_17 ) {
V_209 = F_263 ( V_19 , V_2 -> V_3 . V_14 ) ;
if ( V_209 < 0 )
return V_209 ;
}
if ( V_2 -> V_157 . V_371 ) {
V_209 = F_264 ( V_19 ,
V_2 -> V_157 . V_371 ,
V_2 -> V_157 . V_371 ,
V_2 -> V_440 [ 1 ] -> V_441 ) ;
if ( V_209 < 0 )
return V_209 ;
if ( ! V_2 -> V_433 ) {
V_209 = F_265 ( V_19 ,
& V_2 -> V_157 ) ;
if ( V_209 < 0 )
return V_209 ;
V_2 -> V_157 . V_442 = 1 ;
}
}
if ( V_2 -> V_375 ) {
V_209 = F_266 ( V_19 , V_2 -> V_375 ) ;
if ( V_209 < 0 )
return V_209 ;
}
if ( ! V_2 -> V_433 &&
! F_267 ( V_19 , L_91 ) ) {
V_209 = F_268 ( V_19 , L_91 ,
V_2 -> V_232 , V_443 ,
L_92 ) ;
if ( V_209 < 0 )
return V_209 ;
}
if ( ! V_2 -> V_433 &&
! F_267 ( V_19 , L_93 ) ) {
V_209 = F_269 ( V_19 , L_93 ,
NULL , V_443 ,
L_94 ,
true , & V_2 -> V_155 . V_406 ) ;
if ( V_209 < 0 )
return V_209 ;
if ( V_2 -> V_155 . V_156 ) {
F_270 ( V_19 , & V_2 -> V_155 ,
V_2 -> V_444 ) ;
F_271 ( & V_2 -> V_155 ) ;
}
}
F_7 ( V_2 ) ;
V_209 = F_272 ( V_19 , & V_2 -> V_150 ) ;
if ( V_209 < 0 )
return V_209 ;
return 0 ;
}
static void F_273 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
struct V_447 * V_448 ,
int V_449 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_450 )
V_2 -> V_450 ( V_446 , V_19 , V_448 , V_449 ) ;
}
static void F_274 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
struct V_447 * V_448 ,
int V_449 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_451 )
V_2 -> V_451 ( V_446 , V_19 , V_448 , V_449 ) ;
}
static int F_275 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
struct V_447 * V_448 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_209 ;
F_139 ( & V_2 -> V_9 ) ;
V_209 = F_276 ( V_19 ,
& V_2 -> V_157 , V_448 ,
V_446 ) ;
if ( ! V_209 ) {
V_2 -> V_246 |= 1 << V_452 ;
F_273 ( V_446 , V_19 , V_448 ,
V_453 ) ;
}
F_142 ( & V_2 -> V_9 ) ;
return V_209 ;
}
static int F_277 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
unsigned int V_454 ,
unsigned int V_455 ,
struct V_447 * V_448 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_209 ;
V_209 = F_278 ( V_19 , & V_2 -> V_157 ,
V_454 , V_455 , V_448 ) ;
if ( ! V_209 )
F_273 ( V_446 , V_19 , V_448 ,
V_456 ) ;
return V_209 ;
}
static int F_279 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
struct V_447 * V_448 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_209 ;
V_209 = F_280 ( V_19 , & V_2 -> V_157 ) ;
if ( ! V_209 )
F_273 ( V_446 , V_19 , V_448 ,
V_457 ) ;
return V_209 ;
}
static int F_281 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
struct V_447 * V_448 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_139 ( & V_2 -> V_9 ) ;
V_2 -> V_246 &= ~ ( 1 << V_452 ) ;
F_273 ( V_446 , V_19 , V_448 ,
V_458 ) ;
F_142 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_282 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
struct V_447 * V_448 )
{
F_274 ( V_446 , V_19 , V_448 , V_453 ) ;
return 0 ;
}
static int F_283 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
unsigned int V_454 ,
unsigned int V_455 ,
struct V_447 * V_448 )
{
F_284 ( V_19 , V_446 -> V_51 , V_454 , 0 , V_455 ) ;
F_274 ( V_446 , V_19 , V_448 ,
V_456 ) ;
return 0 ;
}
static int F_285 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
struct V_447 * V_448 )
{
F_286 ( V_19 , V_446 -> V_51 ) ;
F_274 ( V_446 , V_19 , V_448 ,
V_457 ) ;
return 0 ;
}
static int F_287 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
struct V_447 * V_448 )
{
F_274 ( V_446 , V_19 , V_448 , V_458 ) ;
return 0 ;
}
static int F_288 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
struct V_447 * V_448 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_209 = 0 ;
F_139 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_40 && ! V_2 -> V_243 )
V_209 = - V_247 ;
else
V_2 -> V_246 |= 1 << V_459 ;
F_273 ( V_446 , V_19 , V_448 ,
V_453 ) ;
F_142 ( & V_2 -> V_9 ) ;
return V_209 ;
}
static int F_289 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
struct V_447 * V_448 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_139 ( & V_2 -> V_9 ) ;
V_2 -> V_246 &= ~ ( 1 << V_459 ) ;
F_273 ( V_446 , V_19 , V_448 ,
V_458 ) ;
F_142 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_290 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
unsigned int V_454 ,
unsigned int V_455 ,
struct V_447 * V_448 )
{
F_284 ( V_19 , V_446 -> V_51 , V_454 , 0 , V_455 ) ;
F_273 ( V_446 , V_19 , V_448 ,
V_456 ) ;
return 0 ;
}
static int F_291 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
struct V_447 * V_448 )
{
F_286 ( V_19 , V_446 -> V_51 ) ;
F_273 ( V_446 , V_19 , V_448 ,
V_457 ) ;
return 0 ;
}
static int F_292 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
struct V_447 * V_448 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_293 ( V_19 , & V_2 -> V_157 ) ;
}
static int F_294 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
unsigned int V_454 ,
unsigned int V_455 ,
struct V_447 * V_448 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_295 ( V_19 , & V_2 -> V_157 ,
V_454 , V_455 , V_448 ) ;
}
static int F_296 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
struct V_447 * V_448 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_297 ( V_19 , & V_2 -> V_157 ) ;
}
static int F_298 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
struct V_447 * V_448 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_299 ( V_19 , & V_2 -> V_157 ) ;
}
static int F_300 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
unsigned int V_454 ,
unsigned int V_455 ,
struct V_447 * V_448 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_284 ( V_19 , V_2 -> V_318 [ V_448 -> V_460 + 1 ] ,
V_454 , 0 , V_455 ) ;
F_274 ( V_446 , V_19 , V_448 ,
V_456 ) ;
return 0 ;
}
static int F_301 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
struct V_447 * V_448 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_286 ( V_19 ,
V_2 -> V_318 [ V_448 -> V_460 + 1 ] ) ;
F_274 ( V_446 , V_19 , V_448 ,
V_457 ) ;
return 0 ;
}
static bool F_220 ( struct V_18 * V_19 , int V_461 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_462 = V_2 -> V_318 [ V_2 -> V_328 [ V_461 ] ] ;
if ( V_2 -> V_463 && V_2 -> V_463 != V_462 ) {
F_302 ( V_19 , V_2 -> V_463 , 1 ) ;
V_2 -> V_463 = V_462 ;
F_284 ( V_19 , V_462 ,
V_2 -> V_464 , 0 ,
V_2 -> V_465 ) ;
return true ;
}
return false ;
}
static int F_303 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
unsigned int V_454 ,
unsigned int V_455 ,
struct V_447 * V_448 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
V_2 -> V_463 = V_2 -> V_318 [ V_2 -> V_328 [ V_2 -> V_274 [ 0 ] ] ] ;
V_2 -> V_464 = V_454 ;
V_2 -> V_465 = V_455 ;
F_284 ( V_19 , V_2 -> V_463 , V_454 , 0 , V_455 ) ;
return 0 ;
}
static int F_304 ( struct V_445 * V_446 ,
struct V_18 * V_19 ,
struct V_447 * V_448 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_286 ( V_19 , V_2 -> V_463 ) ;
V_2 -> V_463 = 0 ;
return 0 ;
}
static void F_305 ( char * V_466 , T_3 V_467 , const char * V_133 ,
const char * V_468 )
{
char * V_469 ;
if ( * V_466 )
return;
F_306 ( V_466 , V_468 , V_467 ) ;
for ( V_469 = strchr ( V_466 , ' ' ) ; V_469 ; V_469 = strchr ( V_469 + 1 , ' ' ) ) {
if ( ! isalnum ( V_469 [ 1 ] ) ) {
* V_469 = 0 ;
break;
}
}
F_169 ( V_466 , V_133 , V_467 ) ;
}
static void F_307 ( struct V_445 * V_466 ,
const struct V_445 * V_470 ,
const struct V_445 * V_471 ,
T_1 V_51 )
{
* V_466 = * V_470 ;
if ( V_51 )
V_466 -> V_51 = V_51 ;
if ( V_471 ) {
if ( V_471 -> V_472 )
V_466 -> V_472 = V_471 -> V_472 ;
if ( V_471 -> V_473 )
V_466 -> V_473 = V_471 -> V_473 ;
if ( V_471 -> V_474 )
V_466 -> V_474 = V_471 -> V_474 ;
if ( V_471 -> V_475 )
V_466 -> V_475 = V_471 -> V_475 ;
if ( V_471 -> V_476 )
V_466 -> V_476 = V_471 -> V_476 ;
if ( V_471 -> V_477 )
V_466 -> V_477 = V_471 -> V_477 ;
}
}
int F_308 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_478 * V_479 ;
bool V_480 ;
if ( V_2 -> V_433 )
goto V_481;
F_305 ( V_2 -> V_482 ,
sizeof( V_2 -> V_482 ) ,
L_95 , V_19 -> V_90 . V_468 ) ;
V_479 = F_309 ( V_19 , L_96 , V_2 -> V_482 ) ;
if ( ! V_479 )
return - V_135 ;
V_2 -> V_440 [ 0 ] = V_479 ;
if ( V_2 -> V_157 . V_158 > 0 ) {
F_307 ( & V_479 -> V_483 [ V_484 ] ,
& V_485 ,
V_2 -> V_486 ,
V_2 -> V_157 . V_210 [ 0 ] ) ;
V_479 -> V_483 [ V_484 ] . V_474 =
V_2 -> V_157 . V_260 ;
if ( V_2 -> V_150 . V_162 == V_163 &&
V_2 -> V_150 . V_151 == 2 )
V_479 -> V_483 [ V_484 ] . V_487 =
V_488 ;
}
if ( V_2 -> V_320 ) {
F_307 ( & V_479 -> V_483 [ V_489 ] ,
( V_2 -> V_329 ?
& V_490 : & V_491 ) ,
V_2 -> V_492 ,
V_2 -> V_318 [ 0 ] ) ;
}
V_481:
if ( V_2 -> V_157 . V_371 || V_2 -> V_375 ) {
F_305 ( V_2 -> V_493 ,
sizeof( V_2 -> V_493 ) ,
L_97 , V_19 -> V_90 . V_468 ) ;
V_479 = F_309 ( V_19 , L_96 ,
V_2 -> V_493 ) ;
if ( ! V_479 )
return - V_135 ;
V_19 -> V_373 = V_2 -> V_157 . V_373 ;
V_2 -> V_440 [ 1 ] = V_479 ;
if ( V_2 -> V_372 )
V_479 -> V_441 = V_2 -> V_372 ;
else
V_479 -> V_441 = V_494 ;
if ( V_2 -> V_157 . V_371 )
F_307 ( & V_479 -> V_483 [ V_484 ] ,
& V_495 ,
V_2 -> V_496 ,
V_2 -> V_157 . V_371 ) ;
if ( V_2 -> V_375 )
F_307 ( & V_479 -> V_483 [ V_489 ] ,
& V_497 ,
V_2 -> V_498 ,
V_2 -> V_375 ) ;
}
if ( V_2 -> V_433 )
return 0 ;
V_480 = ( V_2 -> V_320 > 1 ) &&
! V_2 -> V_329 && ! V_2 -> V_360 ;
if ( V_2 -> V_252 || V_480 ) {
F_305 ( V_2 -> V_499 ,
sizeof( V_2 -> V_499 ) ,
L_98 , V_19 -> V_90 . V_468 ) ;
V_479 = F_309 ( V_19 , L_96 ,
V_2 -> V_499 ) ;
if ( ! V_479 )
return - V_135 ;
V_2 -> V_440 [ 2 ] = V_479 ;
if ( V_2 -> V_252 )
F_307 ( & V_479 -> V_483 [ V_484 ] ,
& V_500 ,
V_2 -> V_501 ,
V_2 -> V_252 ) ;
else
F_307 ( & V_479 -> V_483 [ V_484 ] ,
& V_502 , NULL , 0 ) ;
if ( V_480 ) {
F_307 ( & V_479 -> V_483 [ V_489 ] ,
& V_503 ,
V_2 -> V_504 ,
V_2 -> V_318 [ 1 ] ) ;
V_479 -> V_483 [ V_489 ] . V_472 =
V_2 -> V_320 - 1 ;
} else {
F_307 ( & V_479 -> V_483 [ V_489 ] ,
& V_502 , NULL , 0 ) ;
}
}
return 0 ;
}
static void F_310 ( struct V_18 * V_19 , int V_126 )
{
struct V_6 * V_53 ;
T_1 V_47 ;
V_53 = F_26 ( V_19 , V_126 ) ;
if ( ! V_53 || ! V_53 -> V_54 )
return;
V_47 = V_53 -> V_53 [ V_53 -> V_54 - 1 ] ;
F_14 ( V_19 , V_47 ) ;
F_76 ( V_19 , V_53 , V_53 -> V_92 ,
F_147 ( V_19 -> V_2 ) ) ;
F_79 ( V_19 , V_47 , V_53 -> V_92 ) ;
}
static void F_311 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_150 . V_151 ; V_16 ++ )
F_310 ( V_19 , V_2 -> V_202 [ V_16 ] ) ;
}
static void F_312 ( struct V_18 * V_19 , int V_178 , int * V_5 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_178 ; V_16 ++ )
F_310 ( V_19 , V_5 [ V_16 ] ) ;
}
static void F_313 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_150 . V_162 != V_165 )
F_312 ( V_19 , V_2 -> V_150 . V_153 , V_2 -> V_164 ) ;
if ( V_2 -> V_150 . V_162 != V_163 )
F_312 ( V_19 , V_2 -> V_150 . V_154 ,
V_2 -> V_166 ) ;
}
static void F_314 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_152 ; V_16 ++ ) {
T_1 V_47 = V_2 -> V_176 [ V_16 ] . V_47 ;
struct V_6 * V_53 ;
V_53 = F_146 ( V_19 , V_16 ) ;
if ( ! V_53 )
continue;
if ( ! V_2 -> V_176 [ V_16 ] . V_259 )
V_2 -> V_176 [ V_16 ] . V_259 =
F_16 ( V_19 , V_47 ) ;
F_76 ( V_19 , V_53 , V_53 -> V_92 ,
F_147 ( V_2 ) ) ;
}
}
static void F_315 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_250 )
return;
if ( ! F_116 ( V_2 ) )
return;
F_140 ( V_19 , V_2 -> V_251 , V_2 -> V_202 [ 0 ] ,
V_2 -> V_205 [ 0 ] ,
V_2 -> V_150 . V_162 ) ;
F_140 ( V_19 , V_2 -> V_251 , V_2 -> V_164 [ 0 ] ,
V_2 -> V_205 [ 1 ] ,
V_165 ) ;
F_140 ( V_19 , V_2 -> V_251 , V_2 -> V_166 [ 0 ] ,
V_2 -> V_205 [ 2 ] ,
V_163 ) ;
}
static void F_316 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_148 * V_149 = & V_2 -> V_150 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_149 -> V_197 ; V_16 ++ ) {
T_1 V_51 = V_149 -> V_198 [ V_16 ] . V_47 ;
if ( F_189 ( V_19 , V_51 ) )
F_14 ( V_19 , V_51 ) ;
if ( V_2 -> V_46 ) {
F_81 ( V_19 , V_2 -> V_213 [ V_16 ] ) ;
F_81 ( V_19 , V_2 -> V_317 ) ;
}
}
}
static void F_317 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_323 * V_324 = & V_2 -> V_325 ;
struct V_6 * V_53 ;
int V_16 , V_336 , V_52 ;
if ( V_2 -> V_329 )
V_52 = 1 ;
else
V_52 = V_2 -> V_320 ;
for ( V_336 = 0 ; V_336 < V_52 ; V_336 ++ ) {
for ( V_16 = 0 ; V_16 < V_324 -> V_327 ; V_16 ++ ) {
V_53 = F_197 ( V_19 , V_336 , V_16 ) ;
if ( V_53 ) {
bool V_92 = V_53 -> V_92 ;
if ( V_16 == V_2 -> V_274 [ V_336 ] )
V_92 = true ;
F_76 ( V_19 , V_53 , V_92 , false ) ;
}
}
if ( V_2 -> V_44 )
F_157 ( V_19 , V_336 , true ) ;
}
if ( V_2 -> V_349 )
V_2 -> V_349 ( V_19 , NULL , NULL ) ;
}
static void F_318 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_47 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_150 . V_369 ; V_16 ++ )
F_310 ( V_19 , V_2 -> V_211 [ V_16 ] ) ;
V_47 = V_2 -> V_150 . V_374 ;
if ( V_47 ) {
F_14 ( V_19 , V_47 ) ;
F_81 ( V_19 , V_2 -> V_214 ) ;
}
}
static void F_319 ( struct V_18 * V_19 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_505 . V_17 ; V_16 ++ ) {
struct V_506 * V_47 = F_24 ( & V_19 -> V_505 , V_16 ) ;
T_1 V_51 = V_47 -> V_51 ;
if ( F_223 ( V_19 , V_51 ) &&
! F_320 ( V_19 , V_51 ) )
F_77 ( V_19 , V_51 , 0 ,
V_507 , 0 ) ;
}
}
int F_321 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_508 )
V_2 -> V_508 ( V_19 ) ;
F_322 ( V_19 ) ;
F_311 ( V_19 ) ;
F_313 ( V_19 ) ;
F_314 ( V_19 ) ;
F_315 ( V_19 ) ;
F_316 ( V_19 ) ;
F_317 ( V_19 ) ;
F_318 ( V_19 ) ;
F_319 ( V_19 ) ;
F_233 ( V_19 ) ;
F_149 ( V_19 ) ;
F_323 ( V_19 -> V_90 . V_509 ) ;
if ( V_2 -> V_155 . V_406 && V_2 -> V_155 . V_156 )
F_271 ( & V_2 -> V_155 ) ;
F_324 ( V_19 , 0x01 ) ;
return 0 ;
}
void F_325 ( struct V_18 * V_19 )
{
F_326 ( V_19 , V_510 ) ;
F_10 ( V_19 -> V_2 ) ;
F_8 ( V_19 -> V_2 ) ;
V_19 -> V_2 = NULL ;
}
int F_327 ( struct V_18 * V_19 , T_1 V_51 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_328 ( V_19 , & V_2 -> V_308 , V_51 ) ;
}
static int F_329 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_209 ;
V_2 = F_330 ( sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 )
return - V_135 ;
F_1 ( V_2 ) ;
V_19 -> V_2 = V_2 ;
V_209 = F_331 ( V_19 , & V_2 -> V_150 , NULL , 0 ) ;
if ( V_209 < 0 )
return V_209 ;
V_209 = F_260 ( V_19 , & V_2 -> V_150 ) ;
if ( V_209 < 0 )
goto error;
V_19 -> V_437 = V_511 ;
return 0 ;
error:
F_325 ( V_19 ) ;
return V_209 ;
}
