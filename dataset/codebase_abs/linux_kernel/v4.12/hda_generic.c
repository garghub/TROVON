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
V_20 = F_12 ( V_19 , L_28 ) ;
if ( V_20 >= 0 )
V_2 -> V_46 = ! V_20 ;
if ( ! F_13 ( V_19 , L_29 , & V_20 ) )
V_2 -> V_47 = V_20 ;
}
static inline void F_14 ( struct V_18 * V_19 , T_1 V_48 )
{
F_15 ( V_19 , V_48 , F_16 ( V_19 , V_48 ) ) ;
}
static void F_17 ( struct V_18 * V_19 , T_1 V_48 ,
unsigned int V_20 , bool V_49 )
{
if ( ! V_48 )
return;
V_20 = F_18 ( V_19 , V_48 , V_20 ) ;
F_19 ( V_19 , V_48 , V_20 ) ;
if ( V_49 )
F_15 ( V_19 , V_48 , V_20 ) ;
}
static void F_20 ( struct V_18 * V_19 , int V_50 ,
T_1 * V_51 , unsigned int V_20 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_50 ; V_16 ++ )
F_17 ( V_19 , V_51 [ V_16 ] , V_20 , false ) ;
}
static int F_21 ( T_1 V_52 , const T_1 * V_14 , int V_53 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_53 ; V_16 ++ )
if ( V_14 [ V_16 ] == V_52 )
return V_16 ;
return - 1 ;
}
static bool F_22 ( struct V_6 * V_54 , T_1 V_52 )
{
return F_21 ( V_52 , V_54 -> V_54 , V_54 -> V_55 ) >= 0 ;
}
static struct V_6 * F_23 ( struct V_18 * V_19 ,
T_1 V_56 , T_1 V_57 ,
int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 . V_17 ; V_16 ++ ) {
struct V_6 * V_54 = F_24 ( & V_2 -> V_5 , V_16 ) ;
if ( V_54 -> V_55 <= 0 )
continue;
if ( ( ! V_56 || V_54 -> V_54 [ 0 ] == V_56 ) &&
( ! V_57 || V_54 -> V_54 [ V_54 -> V_55 - 1 ] == V_57 ) ) {
if ( ! V_58 ||
( V_58 > 0 && F_22 ( V_54 , V_58 ) ) ||
( V_58 < 0 && ! F_22 ( V_54 , V_58 ) ) )
return V_54 ;
}
}
return NULL ;
}
int F_25 ( struct V_18 * V_19 , struct V_6 * V_54 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_59 = V_2 -> V_5 . V_14 ;
T_2 V_60 ;
if ( ! V_2 -> V_5 . V_17 )
return 0 ;
V_60 = V_54 - V_59 ;
if ( V_60 < 0 || V_60 >= V_2 -> V_5 . V_17 )
return 0 ;
return V_60 + 1 ;
}
struct V_6 * F_26 ( struct V_18 * V_19 , int V_60 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_60 <= 0 || V_60 > V_2 -> V_5 . V_17 )
return NULL ;
return F_24 ( & V_2 -> V_5 , V_60 - 1 ) ;
}
static bool F_27 ( struct V_18 * V_19 , T_1 V_52 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 . V_17 ; V_16 ++ ) {
struct V_6 * V_54 = F_24 ( & V_2 -> V_5 , V_16 ) ;
if ( V_54 -> V_54 [ 0 ] == V_52 )
return true ;
}
return false ;
}
static bool F_28 ( struct V_18 * V_19 ,
T_1 V_56 , T_1 V_57 )
{
if ( ! V_56 || ! V_57 )
return false ;
return F_29 ( V_19 , V_57 , V_56 , true ) >= 0 ;
}
static bool F_30 ( struct V_18 * V_19 , unsigned int V_20 , int type )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
V_20 &= V_61 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 . V_17 ; V_16 ++ ) {
struct V_6 * V_54 = F_24 ( & V_2 -> V_5 , V_16 ) ;
if ( ( V_54 -> V_62 [ type ] & V_61 ) == V_20 )
return true ;
}
return false ;
}
static bool F_31 ( struct V_18 * V_19 , T_1 V_52 ,
int V_63 , int V_60 , int type )
{
unsigned int V_20 = F_32 ( V_52 , 3 , V_60 , V_63 ) ;
return F_30 ( V_19 , V_20 , type ) ;
}
static void F_33 ( struct V_18 * V_19 ,
const char * V_64 , struct V_6 * V_54 )
{
char V_65 [ 40 ] ;
char * V_66 = V_65 ;
int V_16 ;
* V_66 = 0 ;
for ( V_16 = 0 ; V_16 < V_54 -> V_55 ; V_16 ++ )
V_66 += F_34 ( V_66 , sizeof( V_65 ) - ( V_66 - V_65 ) , L_30 ,
V_66 != V_65 ? L_31 : L_32 ,
V_54 -> V_54 [ V_16 ] ) ;
F_35 ( V_19 , L_33 , V_64 , V_54 -> V_55 , V_65 ) ;
}
static bool F_36 ( struct V_18 * V_19 ,
T_1 V_56 , T_1 V_57 ,
int V_58 , struct V_6 * V_54 ,
int V_55 )
{
const T_1 * V_67 ;
int V_16 , V_53 ;
if ( V_57 == V_58 )
V_58 = 0 ;
else if ( V_57 == ( T_1 ) ( - V_58 ) )
return false ;
V_53 = F_37 ( V_19 , V_57 , & V_67 ) ;
for ( V_16 = 0 ; V_16 < V_53 ; V_16 ++ ) {
if ( V_67 [ V_16 ] != V_56 ) {
if ( V_56 ||
F_38 ( F_39 ( V_19 , V_67 [ V_16 ] ) ) != V_68 ||
F_27 ( V_19 , V_67 [ V_16 ] ) )
continue;
}
if ( V_58 <= 0 )
goto V_69;
}
if ( V_55 >= V_70 )
return false ;
for ( V_16 = 0 ; V_16 < V_53 ; V_16 ++ ) {
unsigned int type ;
type = F_38 ( F_39 ( V_19 , V_67 [ V_16 ] ) ) ;
if ( type == V_68 || type == V_71 ||
type == V_72 )
continue;
if ( F_36 ( V_19 , V_56 , V_67 [ V_16 ] ,
V_58 , V_54 , V_55 + 1 ) )
goto V_69;
}
return false ;
V_69:
V_54 -> V_54 [ V_54 -> V_55 ] = V_67 [ V_16 ] ;
V_54 -> V_60 [ V_54 -> V_55 + 1 ] = V_16 ;
if ( V_53 > 1 && F_38 ( F_39 ( V_19 , V_57 ) ) != V_73 )
V_54 -> V_74 [ V_54 -> V_55 + 1 ] = 1 ;
V_54 -> V_55 ++ ;
return true ;
}
static bool F_40 ( struct V_18 * V_19 , T_1 V_56 ,
T_1 V_57 , int V_58 ,
struct V_6 * V_54 )
{
if ( F_36 ( V_19 , V_56 , V_57 , V_58 , V_54 , 1 ) ) {
V_54 -> V_54 [ V_54 -> V_55 ] = V_57 ;
V_54 -> V_55 ++ ;
return true ;
}
return false ;
}
struct V_6 *
F_41 ( struct V_18 * V_19 , T_1 V_56 ,
T_1 V_57 , int V_58 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_54 ;
if ( V_56 && V_57 && ! F_28 ( V_19 , V_56 , V_57 ) )
return NULL ;
V_54 = F_23 ( V_19 , V_56 , V_57 , V_58 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_5 ( & V_2 -> V_5 ) ;
if ( ! V_54 )
return NULL ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
if ( F_40 ( V_19 , V_56 , V_57 , V_58 , V_54 ) )
return V_54 ;
V_2 -> V_5 . V_17 -- ;
return NULL ;
}
static void F_42 ( struct V_18 * V_19 , int V_60 )
{
struct V_6 * V_54 = F_26 ( V_19 , V_60 ) ;
if ( ! V_54 )
return;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
}
static T_1 F_43 ( struct V_18 * V_19 , T_1 V_48 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const T_1 * V_14 = V_2 -> V_75 ;
if ( ! V_14 )
return 0 ;
for (; * V_14 ; V_14 += 2 )
if ( * V_14 == V_48 )
return V_14 [ 1 ] ;
return 0 ;
}
static T_1 F_44 ( struct V_18 * V_19 , T_1 V_48 ,
bool V_76 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_77 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_78 ; V_16 ++ ) {
T_1 V_52 = V_2 -> V_79 [ V_16 ] ;
if ( ! V_52 || F_27 ( V_19 , V_52 ) )
continue;
V_77 = ! ! ( F_39 ( V_19 , V_52 ) & V_80 ) ;
if ( V_76 != V_77 )
continue;
if ( F_28 ( V_19 , V_52 , V_48 ) )
return V_52 ;
}
return 0 ;
}
static unsigned int F_45 ( unsigned int V_20 , unsigned int V_81 )
{
V_20 &= ~ ( 0x3U << 16 ) ;
V_20 |= V_81 << 16 ;
return V_20 ;
}
static bool F_46 ( struct V_18 * V_19 , T_1 V_82 ,
T_1 V_83 , int V_63 )
{
if ( ! ( F_39 ( V_19 , V_82 ) & ( 1 << ( V_63 + 1 ) ) ) )
return ! ( F_39 ( V_19 , V_83 ) & ( 1 << ( V_63 + 1 ) ) ) ;
return ( F_47 ( V_19 , V_82 , V_63 ) ==
F_47 ( V_19 , V_83 , V_63 ) ) ;
}
static T_1 F_48 ( struct V_18 * V_19 ,
struct V_6 * V_54 )
{
int V_16 ;
for ( V_16 = V_54 -> V_55 - 1 ; V_16 >= 0 ; V_16 -- ) {
if ( F_49 ( V_19 , V_54 -> V_54 [ V_16 ] , V_84 ) )
return V_54 -> V_54 [ V_16 ] ;
if ( V_16 != V_54 -> V_55 - 1 && V_16 != 0 &&
F_49 ( V_19 , V_54 -> V_54 [ V_16 ] , V_85 ) )
return V_54 -> V_54 [ V_16 ] ;
}
return 0 ;
}
static T_1 F_50 ( struct V_18 * V_19 ,
struct V_6 * V_54 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = V_54 -> V_55 - 1 ; V_16 >= 0 ; V_16 -- ) {
T_1 V_52 = V_54 -> V_54 [ V_16 ] ;
if ( ( V_2 -> V_86 >> V_52 ) & 1 )
continue;
if ( F_51 ( V_19 , V_52 , V_84 ) )
return V_52 ;
}
return 0 ;
}
static bool F_52 ( struct V_18 * V_19 , struct V_6 * V_54 , int V_60 )
{
T_1 V_52 = V_54 -> V_54 [ V_60 ] ;
unsigned int V_87 = F_39 ( V_19 , V_52 ) ;
unsigned int type = F_38 ( V_87 ) ;
if ( ! ( V_87 & V_88 ) )
return false ;
if ( type == V_72 && V_60 > 0 )
return false ;
return true ;
}
static bool F_53 ( struct V_18 * V_19 , struct V_6 * V_54 , int V_60 )
{
T_1 V_52 = V_54 -> V_54 [ V_60 ] ;
unsigned int V_87 = F_39 ( V_19 , V_52 ) ;
unsigned int type = F_38 ( V_87 ) ;
if ( ! ( V_87 & V_89 ) )
return false ;
if ( type == V_72 && ! V_60 )
return false ;
return true ;
}
static bool F_54 ( struct V_18 * V_19 , T_1 V_52 ,
unsigned int V_63 , unsigned int V_60 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int type = F_38 ( F_39 ( V_19 , V_52 ) ) ;
int V_16 , V_90 ;
if ( V_52 == V_19 -> V_91 . V_92 )
return true ;
for ( V_90 = 0 ; V_90 < V_2 -> V_5 . V_17 ; V_90 ++ ) {
struct V_6 * V_54 = F_24 ( & V_2 -> V_5 , V_90 ) ;
if ( ! V_54 -> V_93 )
continue;
if ( V_19 -> V_30 ) {
if ( ! V_54 -> V_94 )
continue;
if ( ! ( V_54 -> V_95 || V_54 -> V_96 ) &&
type != V_68 && type != V_71 )
continue;
}
for ( V_16 = 0 ; V_16 < V_54 -> V_55 ; V_16 ++ ) {
if ( V_54 -> V_54 [ V_16 ] == V_52 ) {
if ( V_63 == V_84 || V_60 == - 1 ||
V_54 -> V_60 [ V_16 ] == V_60 )
return true ;
break;
}
}
}
return false ;
}
static int F_55 ( struct V_18 * V_19 , T_1 V_52 ,
int V_63 , unsigned int V_87 , bool V_97 )
{
unsigned int V_20 = 0 ;
if ( V_87 & V_98 ) {
if ( V_97 )
V_20 = ( V_87 & V_99 ) >> V_100 ;
}
if ( V_87 & ( V_101 | V_102 ) ) {
if ( ! V_97 )
V_20 |= V_103 ;
}
return V_20 ;
}
static bool F_56 ( struct V_18 * V_19 , T_1 V_52 , int V_63 )
{
unsigned int V_104 = F_39 ( V_19 , V_52 ) ;
T_1 V_67 ;
if ( V_104 & V_105 )
return true ;
if ( V_63 != V_85 || F_38 ( V_104 ) != V_73 )
return false ;
if ( F_57 ( V_19 , V_52 ) != 1 )
return false ;
if ( F_58 ( V_19 , V_52 , & V_67 , 1 ) < 0 )
return false ;
return ! ! ( F_39 ( V_19 , V_67 ) & V_105 ) ;
}
static void F_59 ( struct V_18 * V_19 , T_1 V_52 , int V_63 , int V_60 )
{
unsigned int V_87 = F_47 ( V_19 , V_52 , V_63 ) ;
int V_20 = F_55 ( V_19 , V_52 , V_63 , V_87 , false ) ;
if ( F_56 ( V_19 , V_52 , V_63 ) )
F_60 ( V_19 , V_52 , V_63 , V_60 , 0xff , V_20 ) ;
else
F_61 ( V_19 , V_52 , 0 , V_63 , V_60 , 0xff , V_20 ) ;
}
static int F_62 ( struct V_18 * V_19 , T_1 V_52 , int V_63 , int V_60 ,
unsigned int V_106 , unsigned int V_20 )
{
if ( F_56 ( V_19 , V_52 , V_63 ) )
return F_63 ( V_19 , V_52 , V_63 , V_60 ,
V_106 , V_20 ) ;
else
return F_64 ( V_19 , V_52 , 0 , V_63 , V_60 ,
V_106 , V_20 ) ;
}
static unsigned int F_65 ( struct V_18 * V_19 ,
T_1 V_52 , int V_63 , int V_60 ,
unsigned int V_87 )
{
unsigned int V_106 = 0xff ;
if ( V_87 & ( V_101 | V_102 ) ) {
if ( F_31 ( V_19 , V_52 , V_63 , V_60 , V_107 ) )
V_106 &= ~ 0x80 ;
}
if ( V_87 & V_98 ) {
if ( F_31 ( V_19 , V_52 , V_63 , V_60 , V_108 ) ||
F_31 ( V_19 , V_52 , V_63 , V_60 , V_109 ) )
V_106 &= ~ 0x7f ;
}
return V_106 ;
}
static void F_66 ( struct V_18 * V_19 , T_1 V_52 , int V_63 ,
int V_60 , int V_110 , bool V_97 )
{
unsigned int V_87 ;
unsigned int V_106 , V_20 ;
V_87 = F_47 ( V_19 , V_52 , V_63 ) ;
V_20 = F_55 ( V_19 , V_52 , V_63 , V_87 , V_97 ) ;
V_106 = F_65 ( V_19 , V_52 , V_63 , V_110 , V_87 ) ;
if ( ! V_106 )
return;
V_20 &= V_106 ;
F_62 ( V_19 , V_52 , V_63 , V_60 , V_106 , V_20 ) ;
}
static void F_67 ( struct V_18 * V_19 , T_1 V_52 ,
int V_63 , int V_60 , int V_110 ,
bool V_97 )
{
if ( ! V_97 && F_54 ( V_19 , V_52 , V_63 , V_110 ) )
return;
F_66 ( V_19 , V_52 , V_63 , V_60 , V_110 , V_97 ) ;
}
static void F_68 ( struct V_18 * V_19 , struct V_6 * V_54 ,
int V_16 , bool V_97 )
{
T_1 V_52 = V_54 -> V_54 [ V_16 ] ;
F_59 ( V_19 , V_52 , V_84 , 0 ) ;
F_67 ( V_19 , V_52 , V_84 , 0 , 0 , V_97 ) ;
}
static void F_69 ( struct V_18 * V_19 , struct V_6 * V_54 ,
int V_16 , bool V_97 , bool V_111 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const T_1 * V_67 ;
int V_90 , V_53 , V_60 ;
int type ;
T_1 V_52 = V_54 -> V_54 [ V_16 ] ;
V_53 = F_37 ( V_19 , V_52 , & V_67 ) ;
type = F_38 ( F_39 ( V_19 , V_52 ) ) ;
if ( type == V_72 ||
( type == V_71 && V_19 -> V_29 ) ) {
V_53 = 1 ;
V_60 = 0 ;
} else
V_60 = V_54 -> V_60 [ V_16 ] ;
for ( V_90 = 0 ; V_90 < V_53 ; V_90 ++ )
F_59 ( V_19 , V_52 , V_85 , V_90 ) ;
for ( V_90 = 0 ; V_90 < V_53 ; V_90 ++ ) {
if ( V_90 != V_60 ) {
if ( V_67 [ V_90 ] != V_2 -> V_112 )
continue;
if ( ! V_111 ) {
F_66 ( V_19 , V_52 , V_85 , V_90 , V_90 , false ) ;
continue;
}
}
F_67 ( V_19 , V_52 , V_85 , V_90 , V_60 , V_97 ) ;
}
}
static T_1 F_70 ( struct V_18 * V_19 ,
struct V_6 * V_54 ,
bool V_113 )
{
T_1 V_52 , V_114 = 0 ;
int V_16 , V_115 , V_116 ;
for ( V_16 = 0 ; V_16 < V_54 -> V_55 ; V_16 ++ ) {
V_52 = V_54 -> V_54 [ V_16 ] ;
if ( ! ( F_39 ( V_19 , V_52 ) & V_117 ) )
continue;
if ( V_52 == V_19 -> V_91 . V_92 )
continue;
if ( ! V_113 || F_71 ( V_19 , V_52 ) )
V_115 = V_118 ;
else
V_115 = V_119 ;
V_116 = F_72 ( V_19 , V_52 , 0 ,
V_120 , 0 ) ;
if ( V_116 != ( V_115 | ( V_115 << 4 ) ) ) {
F_73 ( V_19 , V_52 , 0 ,
V_121 , V_115 ) ;
V_114 = V_52 ;
#if 0
if (state == AC_PWRST_D0)
snd_hdac_regmap_sync_node(&codec->core, nid);
#endif
}
}
return V_114 ;
}
static void F_74 ( struct V_18 * V_19 , T_1 V_52 )
{
if ( V_52 ) {
F_75 ( 10 ) ;
F_72 ( V_19 , V_52 , 0 , V_120 , 0 ) ;
}
}
void F_76 ( struct V_18 * V_19 , struct V_6 * V_54 ,
bool V_97 , bool V_111 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
V_54 -> V_93 = V_97 ;
if ( V_97 && ( V_2 -> V_43 || V_19 -> V_30 ) )
F_70 ( V_19 , V_54 , V_19 -> V_30 ) ;
for ( V_16 = V_54 -> V_55 - 1 ; V_16 >= 0 ; V_16 -- ) {
T_1 V_52 = V_54 -> V_54 [ V_16 ] ;
if ( V_97 && V_54 -> V_74 [ V_16 ] )
F_77 ( V_19 , V_52 , 0 ,
V_122 ,
V_54 -> V_60 [ V_16 ] ) ;
if ( F_52 ( V_19 , V_54 , V_16 ) )
F_69 ( V_19 , V_54 , V_16 , V_97 , V_111 ) ;
if ( F_53 ( V_19 , V_54 , V_16 ) )
F_68 ( V_19 , V_54 , V_16 , V_97 ) ;
}
}
static void F_78 ( struct V_18 * V_19 , struct V_6 * V_54 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! ( V_2 -> V_43 || V_19 -> V_30 ) || V_54 -> V_93 )
return;
F_74 ( V_19 , F_70 ( V_19 , V_54 , true ) ) ;
}
static void F_79 ( struct V_18 * V_19 , T_1 V_48 , bool V_97 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_123 ||
! ( F_80 ( V_19 , V_48 ) & V_124 ) )
return;
if ( V_2 -> V_125 && ! V_97 )
return;
if ( V_19 -> V_24 )
V_97 = ! V_97 ;
F_77 ( V_19 , V_48 , 0 ,
V_126 ,
V_97 ? 0x02 : 0x00 ) ;
}
static void F_81 ( struct V_18 * V_19 , int V_127 )
{
struct V_6 * V_54 = F_26 ( V_19 , V_127 ) ;
if ( V_54 )
F_76 ( V_19 , V_54 , V_54 -> V_93 , false ) ;
}
static struct V_4 *
F_82 ( struct V_1 * V_2 , int type , const char * V_10 ,
int V_128 , unsigned long V_20 )
{
struct V_4 * V_12 ;
V_12 = F_4 ( V_2 , V_10 , & V_129 [ type ] ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_130 = V_128 ;
if ( F_83 ( V_20 ) )
V_12 -> V_131 = V_132 ;
V_12 -> V_133 = V_20 ;
return V_12 ;
}
static int F_84 ( struct V_1 * V_2 , int type ,
const char * V_64 , const char * V_63 ,
const char * V_134 , int V_128 , unsigned long V_20 )
{
char V_10 [ V_135 ] ;
snprintf ( V_10 , sizeof( V_10 ) , L_34 , V_64 , V_63 , V_134 ) ;
if ( ! F_82 ( V_2 , type , V_10 , V_128 , V_20 ) )
return - V_136 ;
return 0 ;
}
static int F_85 ( struct V_18 * V_19 , const char * V_64 , int V_128 ,
unsigned int V_81 , struct V_6 * V_54 )
{
unsigned int V_20 ;
if ( ! V_54 )
return 0 ;
V_20 = V_54 -> V_62 [ V_108 ] ;
if ( ! V_20 )
return 0 ;
V_20 = F_45 ( V_20 , V_81 ) ;
return F_86 ( V_19 -> V_2 , V_137 , V_64 , V_128 , V_20 ) ;
}
static int F_87 ( struct V_18 * V_19 , struct V_6 * V_54 ,
int type )
{
int V_81 = 1 ;
if ( V_54 ) {
T_1 V_52 = F_83 ( V_54 -> V_62 [ type ] ) ;
if ( V_52 && ( F_39 ( V_19 , V_52 ) & V_105 ) )
V_81 = 3 ;
}
return V_81 ;
}
static int F_88 ( struct V_18 * V_19 , const char * V_64 , int V_128 ,
struct V_6 * V_54 )
{
int V_81 = F_87 ( V_19 , V_54 , V_108 ) ;
return F_85 ( V_19 , V_64 , V_128 , V_81 , V_54 ) ;
}
static int F_89 ( struct V_18 * V_19 , const char * V_64 , int V_128 ,
unsigned int V_81 , struct V_6 * V_54 )
{
unsigned int V_20 ;
int type = V_138 ;
if ( ! V_54 )
return 0 ;
V_20 = V_54 -> V_62 [ V_107 ] ;
if ( ! V_20 )
return 0 ;
V_20 = F_45 ( V_20 , V_81 ) ;
if ( F_90 ( V_20 ) == V_85 ) {
T_1 V_52 = F_83 ( V_20 ) ;
int V_53 = F_57 ( V_19 , V_52 ) ;
if ( V_53 > 1 ) {
type = V_139 ;
V_20 |= V_53 << 19 ;
}
}
return F_91 ( V_19 -> V_2 , type , V_64 , V_128 , V_20 ) ;
}
static int F_92 ( struct V_18 * V_19 , const char * V_64 ,
int V_128 , struct V_6 * V_54 )
{
int V_81 = F_87 ( V_19 , V_54 , V_107 ) ;
return F_89 ( V_19 , V_64 , V_128 , V_81 , V_54 ) ;
}
static void F_93 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_34 ) {
T_1 V_52 = F_95 ( V_141 ) ;
bool V_144 = ! ( ( V_2 -> V_145 >> V_52 ) & 1 ) ;
V_143 -> V_146 . integer . V_146 [ 0 ] &= V_144 ;
V_143 -> V_146 . integer . V_146 [ 1 ] &= V_144 ;
}
}
static int F_96 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
F_93 ( V_141 , V_143 ) ;
return F_97 ( V_141 , V_143 ) ;
}
static int F_98 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
F_93 ( V_141 , V_143 ) ;
return F_99 ( V_141 , V_143 ) ;
}
static bool F_100 ( struct V_18 * V_19 , int V_127 , int V_147 )
{
struct V_6 * V_54 = F_26 ( V_19 , V_127 ) ;
return V_54 && V_54 -> V_62 [ V_147 ] ;
}
static const char * F_101 ( struct V_18 * V_19 , int V_148 ,
int * V_130 , int V_147 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_151 ;
* V_130 = 0 ;
if ( V_150 -> V_152 == 1 && ! V_2 -> V_153 &&
! V_19 -> V_154 &&
! V_150 -> V_155 && ! V_150 -> V_156 )
return V_2 -> V_157 . V_158 ? L_35 : L_36 ;
if ( V_2 -> V_159 . V_160 == 1 && ! V_2 -> V_47 &&
! V_19 -> V_154 &&
! V_2 -> V_159 . V_161 [ 0 ] && ! V_2 -> V_159 . V_162 [ 0 ] )
return V_2 -> V_157 . V_158 ? L_35 : L_36 ;
if ( V_148 >= V_150 -> V_152 )
return V_163 [ V_148 ] ;
switch ( V_150 -> V_164 ) {
case V_165 :
if ( ! V_148 && V_150 -> V_155 &&
! F_100 ( V_19 , V_2 -> V_166 [ 0 ] , V_147 ) )
break;
if ( V_150 -> V_152 == 1 )
return L_37 ;
if ( V_150 -> V_152 == 2 )
return V_148 ? L_38 : L_37 ;
break;
case V_167 :
if ( ! V_148 && V_150 -> V_156 &&
! F_100 ( V_19 , V_2 -> V_168 [ 0 ] , V_147 ) )
break;
if ( V_148 && V_2 -> V_153 )
break;
* V_130 = V_148 ;
return L_39 ;
case V_169 :
if ( ! V_148 && V_150 -> V_156 && V_150 -> V_155 ) {
bool V_170 = ! F_100 ( V_19 , V_2 -> V_166 [ 0 ] , V_147 ) ;
bool V_171 = ! F_100 ( V_19 , V_2 -> V_168 [ 0 ] , V_147 ) ;
if ( V_170 && V_171 )
return V_2 -> V_157 . V_158 ? L_35 : L_36 ;
if ( V_170 )
return L_40 ;
if ( V_171 )
return L_41 ;
}
}
if ( V_150 -> V_152 == 1 && ! V_2 -> V_153 )
return L_42 ;
if ( V_148 >= F_102 ( V_163 ) ) {
F_103 () ;
return L_35 ;
}
return V_163 [ V_148 ] ;
}
static int F_104 ( struct V_18 * V_19 , struct V_6 * V_54 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_52 ;
unsigned int V_20 ;
int V_172 = 0 ;
if ( ! V_54 )
return V_173 * 2 ;
if ( V_54 -> V_62 [ V_108 ] ||
V_54 -> V_62 [ V_107 ] )
return 0 ;
V_52 = F_50 ( V_19 , V_54 ) ;
if ( V_52 ) {
V_20 = F_32 ( V_52 , 3 , 0 , V_84 ) ;
if ( V_2 -> V_174 )
V_20 |= V_175 ;
if ( F_30 ( V_19 , V_20 , V_108 ) )
V_172 += V_173 ;
else
V_54 -> V_62 [ V_108 ] = V_20 ;
} else
V_172 += V_173 ;
V_52 = F_48 ( V_19 , V_54 ) ;
if ( V_52 ) {
unsigned int V_176 = F_38 ( F_39 ( V_19 , V_52 ) ) ;
if ( V_176 == V_72 || V_176 == V_68 ||
F_49 ( V_19 , V_52 , V_84 ) )
V_20 = F_32 ( V_52 , 3 , 0 , V_84 ) ;
else
V_20 = F_32 ( V_52 , 3 , 0 , V_85 ) ;
if ( F_30 ( V_19 , V_20 , V_107 ) )
V_172 += V_173 ;
else
V_54 -> V_62 [ V_107 ] = V_20 ;
} else
V_172 += V_173 ;
return V_172 ;
}
static T_1 F_105 ( struct V_18 * V_19 , int V_60 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_151 ;
if ( V_150 -> V_152 > V_60 )
return V_2 -> V_177 [ V_60 ] ;
V_60 -= V_150 -> V_152 ;
if ( V_2 -> V_153 > V_60 )
return V_2 -> V_178 [ V_60 ] . V_179 ;
return 0 ;
}
static inline T_1 F_106 ( struct V_18 * V_19 ,
T_1 V_179 , T_1 V_48 )
{
return F_28 ( V_19 , V_179 , V_48 ) ? V_179 : 0 ;
}
static int F_107 ( struct V_18 * V_19 , int V_180 ,
const T_1 * V_51 , T_1 * V_181 ,
int * V_127 ,
const struct V_182 * V_183 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_184 ;
int V_172 = 0 ;
T_1 V_179 ;
if ( ! V_180 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_180 ; V_16 ++ ) {
struct V_6 * V_54 ;
T_1 V_48 = V_51 [ V_16 ] ;
V_54 = F_26 ( V_19 , V_127 [ V_16 ] ) ;
if ( V_54 ) {
V_172 += F_104 ( V_19 , V_54 ) ;
continue;
}
V_181 [ V_16 ] = F_43 ( V_19 , V_48 ) ;
if ( V_181 [ V_16 ] ) {
if ( F_27 ( V_19 , V_181 [ V_16 ] ) )
V_172 += V_183 -> V_185 ;
}
if ( ! V_181 [ V_16 ] )
V_181 [ V_16 ] = F_44 ( V_19 , V_48 , false ) ;
if ( ! V_181 [ V_16 ] && ! V_16 ) {
for ( V_184 = 1 ; V_184 < V_180 ; V_184 ++ ) {
if ( F_28 ( V_19 , V_181 [ V_184 ] , V_48 ) ) {
V_181 [ 0 ] = V_181 [ V_184 ] ;
V_181 [ V_184 ] = 0 ;
F_42 ( V_19 , V_127 [ V_184 ] ) ;
V_127 [ V_184 ] = 0 ;
break;
}
}
}
V_179 = V_181 [ V_16 ] ;
if ( ! V_179 ) {
if ( V_180 > 2 )
V_179 = F_106 ( V_19 , F_105 ( V_19 , V_16 ) , V_48 ) ;
if ( ! V_179 )
V_179 = F_106 ( V_19 , V_181 [ 0 ] , V_48 ) ;
if ( ! V_179 )
V_179 = F_106 ( V_19 , F_105 ( V_19 , V_16 ) , V_48 ) ;
if ( V_179 ) {
if ( ! V_16 )
V_172 += V_183 -> V_185 ;
else if ( V_16 == 1 )
V_172 += V_183 -> V_186 ;
else
V_172 += V_183 -> V_187 ;
} else if ( F_28 ( V_19 , V_2 -> V_177 [ 0 ] , V_48 ) ) {
V_179 = V_2 -> V_177 [ 0 ] ;
V_172 += V_183 -> V_188 ;
} else if ( ! V_16 )
V_172 += V_183 -> V_189 ;
else
V_172 += V_183 -> V_190 ;
}
if ( ! V_179 )
continue;
V_54 = F_41 ( V_19 , V_179 , V_48 , - V_2 -> V_47 ) ;
if ( ! V_54 && ! V_16 && V_2 -> V_47 ) {
V_54 = F_41 ( V_19 , V_179 , V_48 , 0 ) ;
}
if ( ! V_54 ) {
V_179 = V_181 [ V_16 ] = 0 ;
V_172 += V_183 -> V_190 ;
} else {
V_54 -> V_93 = true ;
V_127 [ V_16 ] = F_25 ( V_19 , V_54 ) ;
V_172 += F_104 ( V_19 , V_54 ) ;
}
}
return V_172 ;
}
static T_1 F_108 ( struct V_18 * V_19 , T_1 V_48 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_191 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_78 ; V_16 ++ ) {
T_1 V_52 = V_2 -> V_79 [ V_16 ] ;
if ( ! V_52 || F_27 ( V_19 , V_52 ) )
continue;
if ( F_28 ( V_19 , V_52 , V_48 ) ) {
if ( V_191 )
return 0 ;
V_191 = V_52 ;
}
}
return V_191 ;
}
static bool F_109 ( struct V_18 * V_19 ,
unsigned int V_192 , T_1 V_52 )
{
unsigned int V_193 , V_87 ;
V_193 = F_110 ( V_19 , V_52 ) ;
if ( F_111 ( V_193 ) != V_194 )
return false ;
if ( V_192 && F_112 ( V_193 ) != V_192 )
return false ;
V_87 = F_80 ( V_19 , V_52 ) ;
if ( ! ( V_87 & V_195 ) )
return false ;
return true ;
}
static int F_113 ( struct V_18 * V_19 , T_1 V_196 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_151 ;
unsigned int V_193 = F_110 ( V_19 , V_196 ) ;
unsigned int V_192 = F_112 ( V_193 ) ;
int type , V_16 ;
int V_50 = 0 ;
for ( type = V_197 ; type >= V_198 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_150 -> V_199 ; V_16 ++ ) {
if ( V_150 -> V_200 [ V_16 ] . type != type )
continue;
if ( F_109 ( V_19 , V_192 ,
V_150 -> V_200 [ V_16 ] . V_48 ) )
V_50 ++ ;
}
}
return V_50 ;
}
static int F_114 ( struct V_18 * V_19 ,
T_1 V_196 ,
bool V_201 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_151 ;
int type , V_16 , V_184 , V_50 , V_202 ;
unsigned int V_193 = F_110 ( V_19 , V_196 ) ;
unsigned int V_192 = F_112 ( V_193 ) ;
int V_172 = 0 ;
struct V_6 * V_54 ;
V_202 = V_2 -> V_153 ;
if ( V_202 >= 2 )
goto V_203;
V_50 = F_113 ( V_19 , V_196 ) ;
if ( V_50 < 2 )
goto V_203;
for ( type = V_197 ; type >= V_198 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_150 -> V_199 ; V_16 ++ ) {
T_1 V_52 = V_150 -> V_200 [ V_16 ] . V_48 ;
T_1 V_179 = 0 ;
if ( V_150 -> V_200 [ V_16 ] . type != type )
continue;
if ( ! F_109 ( V_19 , V_192 , V_52 ) )
continue;
for ( V_184 = 0 ; V_184 < V_2 -> V_153 ; V_184 ++ ) {
if ( V_52 == V_2 -> V_178 [ V_184 ] . V_48 )
break;
}
if ( V_184 < V_2 -> V_153 )
continue;
if ( V_201 )
V_179 = F_108 ( V_19 , V_52 ) ;
else if ( ! V_179 )
V_179 = F_44 ( V_19 , V_52 , false ) ;
if ( ! V_179 ) {
V_172 ++ ;
continue;
}
V_54 = F_41 ( V_19 , V_179 , V_52 ,
- V_2 -> V_47 ) ;
if ( ! V_54 ) {
V_172 ++ ;
continue;
}
V_2 -> V_178 [ V_2 -> V_153 ] . V_48 = V_52 ;
V_2 -> V_178 [ V_2 -> V_153 ] . V_179 = V_179 ;
V_2 -> V_204 [ V_150 -> V_152 + V_2 -> V_153 ] =
F_25 ( V_19 , V_54 ) ;
V_2 -> V_153 ++ ;
if ( V_2 -> V_153 >= 2 )
break;
}
}
V_203:
if ( V_172 )
V_172 = V_205 ;
if ( V_202 == V_2 -> V_153 ) {
if ( V_201 )
return 1 ;
else
return V_172 ;
}
if ( ! V_201 && V_2 -> V_153 < 2 ) {
V_2 -> V_5 . V_17 -= V_2 -> V_153 - V_202 ;
V_2 -> V_153 = V_202 ;
return V_172 ;
}
for ( V_16 = V_202 ; V_16 < V_2 -> V_153 ; V_16 ++ ) {
V_54 = F_26 ( V_19 , V_2 -> V_204 [ V_150 -> V_152 + V_16 ] ) ;
V_172 += F_104 ( V_19 , V_54 ) ;
}
return V_172 ;
}
static bool F_115 ( struct V_18 * V_19 , int V_206 ,
const T_1 * V_51 , T_1 * V_181 , int * V_127 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
bool V_69 = false ;
for ( V_16 = 0 ; V_16 < V_206 ; V_16 ++ ) {
struct V_6 * V_54 ;
T_1 V_179 ;
if ( V_181 [ V_16 ] )
continue;
V_179 = F_108 ( V_19 , V_51 [ V_16 ] ) ;
if ( ! V_179 )
continue;
V_54 = F_41 ( V_19 , V_179 , V_51 [ V_16 ] ,
- V_2 -> V_47 ) ;
if ( ! V_54 && ! V_16 && V_2 -> V_47 )
V_54 = F_41 ( V_19 , V_179 , V_51 [ V_16 ] , 0 ) ;
if ( V_54 ) {
V_181 [ V_16 ] = V_179 ;
V_69 = true ;
V_54 -> V_93 = true ;
V_127 [ V_16 ] = F_25 ( V_19 , V_54 ) ;
}
}
return V_69 ;
}
static inline bool F_116 ( struct V_1 * V_2 )
{
return V_2 -> V_207 [ 0 ] || V_2 -> V_207 [ 1 ] ||
V_2 -> V_207 [ 2 ] ;
}
static int F_117 ( struct V_18 * V_19 , int V_127 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_54 ;
T_1 V_208 , V_179 , V_48 ;
V_54 = F_26 ( V_19 , V_127 ) ;
if ( ! V_54 || ! V_54 -> V_55 ||
F_22 ( V_54 , V_2 -> V_47 ) )
return 0 ;
V_208 = V_54 -> V_54 [ 0 ] ;
V_179 = V_2 -> V_177 [ 0 ] ;
V_48 = V_54 -> V_54 [ V_54 -> V_55 - 1 ] ;
V_54 = F_41 ( V_19 , V_179 , V_48 , V_2 -> V_47 ) ;
if ( ! V_54 ) {
if ( V_179 != V_208 )
V_179 = V_208 ;
else if ( V_2 -> V_159 . V_161 [ 0 ] )
V_179 = V_2 -> V_159 . V_161 [ 0 ] ;
else if ( V_2 -> V_159 . V_162 [ 0 ] )
V_179 = V_2 -> V_159 . V_162 [ 0 ] ;
else
V_179 = 0 ;
if ( V_179 )
V_54 = F_41 ( V_19 , V_179 , V_48 ,
V_2 -> V_47 ) ;
}
if ( ! V_54 )
return 0 ;
V_54 -> V_93 = false ;
V_54 -> V_96 = true ;
return F_25 ( V_19 , V_54 ) ;
}
static bool F_118 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_151 ;
struct V_6 * V_54 ;
int V_16 , V_60 ;
if ( V_150 -> V_164 == V_167 )
V_60 = V_2 -> V_204 [ 0 ] ;
else
V_60 = V_2 -> V_166 [ 0 ] ;
V_54 = F_26 ( V_19 , V_60 ) ;
if ( ! V_54 )
return false ;
if ( ! V_2 -> V_47 || ! F_22 ( V_54 , V_2 -> V_47 ) )
return true ;
for ( V_16 = 0 ; V_16 < V_150 -> V_152 ; V_16 ++ ) {
if ( V_2 -> V_204 [ V_16 ] == V_60 )
break;
V_54 = F_26 ( V_19 , V_2 -> V_204 [ V_16 ] ) ;
if ( V_54 && F_22 ( V_54 , V_2 -> V_47 ) )
return false ;
}
for ( V_16 = 0 ; V_16 < V_150 -> V_156 ; V_16 ++ ) {
V_54 = F_26 ( V_19 , V_2 -> V_168 [ V_16 ] ) ;
if ( V_54 && F_22 ( V_54 , V_2 -> V_47 ) )
return false ;
}
return true ;
}
static void F_119 ( struct V_18 * V_19 , int V_180 ,
T_1 * V_181 , int * V_127 )
{
struct V_6 * V_54 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_180 ; V_16 ++ ) {
if ( V_181 [ V_16 ] )
continue;
V_54 = F_26 ( V_19 , V_127 [ V_16 ] ) ;
if ( ! V_54 )
continue;
V_181 [ V_16 ] = V_54 -> V_54 [ 0 ] ;
}
}
static int F_120 ( struct V_18 * V_19 ,
bool V_209 ,
bool V_210 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_151 ;
int V_16 , V_211 , V_172 ;
V_2 -> V_159 . V_160 = V_150 -> V_152 ;
V_2 -> V_159 . V_212 = V_2 -> V_177 ;
memset ( V_2 -> V_177 , 0 , sizeof( V_2 -> V_177 ) ) ;
memset ( V_2 -> V_159 . V_161 , 0 , sizeof( V_2 -> V_159 . V_161 ) ) ;
memset ( V_2 -> V_159 . V_162 , 0 , sizeof( V_2 -> V_159 . V_162 ) ) ;
V_2 -> V_153 = 0 ;
F_9 ( & V_2 -> V_5 ) ;
memset ( V_2 -> V_204 , 0 , sizeof( V_2 -> V_204 ) ) ;
memset ( V_2 -> V_166 , 0 , sizeof( V_2 -> V_166 ) ) ;
memset ( V_2 -> V_168 , 0 , sizeof( V_2 -> V_168 ) ) ;
memset ( V_2 -> V_207 , 0 , sizeof( V_2 -> V_207 ) ) ;
memset ( V_2 -> V_213 , 0 , sizeof( V_2 -> V_213 ) ) ;
memset ( V_2 -> V_214 , 0 , sizeof( V_2 -> V_214 ) ) ;
memset ( V_2 -> V_215 , 0 , sizeof( V_2 -> V_215 ) ) ;
memset ( & V_2 -> V_216 , 0 , sizeof( V_2 -> V_216 ) ) ;
V_172 = 0 ;
if ( V_209 ) {
bool V_217 ;
do {
V_217 = F_115 ( V_19 , V_150 -> V_152 ,
V_150 -> V_218 ,
V_2 -> V_177 ,
V_2 -> V_204 ) ;
V_217 |= F_115 ( V_19 , V_150 -> V_155 ,
V_150 -> V_219 ,
V_2 -> V_159 . V_161 ,
V_2 -> V_166 ) ;
V_217 |= F_115 ( V_19 , V_150 -> V_156 ,
V_150 -> V_220 ,
V_2 -> V_159 . V_162 ,
V_2 -> V_168 ) ;
if ( ! V_2 -> V_37 &&
V_210 && V_150 -> V_152 == 1 &&
V_150 -> V_164 != V_165 ) {
V_211 = F_114 ( V_19 , V_150 -> V_218 [ 0 ] , true ) ;
if ( ! V_211 )
V_217 = true ;
}
} while ( V_217 );
}
V_172 += F_107 ( V_19 , V_150 -> V_152 , V_150 -> V_218 ,
V_2 -> V_177 , V_2 -> V_204 ,
V_2 -> V_221 ) ;
if ( ! V_2 -> V_37 && V_210 &&
V_150 -> V_152 == 1 && V_150 -> V_164 != V_165 ) {
V_211 = F_114 ( V_19 , V_150 -> V_218 [ 0 ] , false ) ;
if ( V_211 < 0 )
return V_211 ;
}
if ( V_150 -> V_164 != V_167 ) {
V_211 = F_107 ( V_19 , V_150 -> V_155 , V_150 -> V_219 ,
V_2 -> V_159 . V_161 ,
V_2 -> V_166 ,
V_2 -> V_222 ) ;
if ( V_211 < 0 )
return V_211 ;
V_172 += V_211 ;
}
if ( V_150 -> V_164 != V_165 ) {
V_211 = F_107 ( V_19 , V_150 -> V_156 ,
V_150 -> V_220 ,
V_2 -> V_159 . V_162 ,
V_2 -> V_168 ,
V_2 -> V_222 ) ;
if ( V_211 < 0 )
return V_211 ;
V_172 += V_211 ;
}
if ( ! V_2 -> V_37 &&
V_150 -> V_152 == 1 && V_150 -> V_164 != V_165 ) {
V_211 = F_114 ( V_19 , V_150 -> V_218 [ 0 ] , false ) ;
if ( V_211 < 0 )
return V_211 ;
V_172 += V_211 ;
}
if ( V_2 -> V_47 ) {
V_2 -> V_207 [ 0 ] =
F_117 ( V_19 , V_2 -> V_204 [ 0 ] ) ;
if ( V_150 -> V_164 != V_167 )
V_2 -> V_207 [ 1 ] =
F_117 ( V_19 , V_2 -> V_166 [ 0 ] ) ;
if ( V_150 -> V_164 != V_165 )
V_2 -> V_207 [ 2 ] =
F_117 ( V_19 , V_2 -> V_168 [ 0 ] ) ;
}
if ( ! V_2 -> V_37 &&
V_150 -> V_155 && V_150 -> V_164 == V_165 )
if ( F_113 ( V_19 , V_150 -> V_219 [ 0 ] ) >= 2 )
V_2 -> V_153 = 1 ;
V_2 -> V_159 . V_160 = 0 ;
for ( V_16 = 0 ; V_16 < V_150 -> V_152 ; V_16 ++ ) {
if ( V_2 -> V_177 [ V_16 ] )
V_2 -> V_159 . V_160 ++ ;
else {
memmove ( V_2 -> V_177 + V_16 ,
V_2 -> V_177 + V_16 + 1 ,
sizeof( T_1 ) * ( V_150 -> V_152 - V_16 - 1 ) ) ;
V_2 -> V_177 [ V_150 -> V_152 - 1 ] = 0 ;
}
}
V_2 -> V_223 = V_2 -> V_224 =
V_2 -> V_159 . V_160 * 2 ;
if ( V_2 -> V_153 == 2 ) {
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
V_2 -> V_177 [ V_2 -> V_159 . V_160 ++ ] =
V_2 -> V_178 [ V_16 ] . V_179 ;
} else if ( V_2 -> V_153 ) {
V_2 -> V_153 = 0 ;
V_172 += V_205 ;
}
if ( V_2 -> V_40 && ! F_118 ( V_19 ) )
V_172 += V_225 ;
if ( V_150 -> V_164 != V_167 )
F_119 ( V_19 , V_150 -> V_155 ,
V_2 -> V_159 . V_161 ,
V_2 -> V_166 ) ;
if ( V_150 -> V_164 != V_165 )
F_119 ( V_19 , V_150 -> V_156 ,
V_2 -> V_159 . V_162 ,
V_2 -> V_168 ) ;
return V_172 ;
}
static inline void F_121 ( struct V_18 * V_19 ,
const char * V_64 , int V_60 )
{
struct V_6 * V_54 ;
V_54 = F_26 ( V_19 , V_60 ) ;
if ( V_54 )
F_33 ( V_19 , V_64 , V_54 ) ;
}
static void F_122 ( struct V_18 * V_19 ,
struct V_149 * V_150 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_226 [ 3 ] = { L_43 , L_44 , L_45 } ;
int V_16 ;
F_123 ( L_46 ,
V_150 -> V_218 [ 0 ] , V_150 -> V_218 [ 1 ] ,
V_150 -> V_218 [ 2 ] , V_150 -> V_218 [ 3 ] ,
V_2 -> V_159 . V_212 [ 0 ] ,
V_2 -> V_159 . V_212 [ 1 ] ,
V_2 -> V_159 . V_212 [ 2 ] ,
V_2 -> V_159 . V_212 [ 3 ] ,
V_226 [ V_150 -> V_164 ] ) ;
for ( V_16 = 0 ; V_16 < V_150 -> V_152 ; V_16 ++ )
F_121 ( V_19 , L_47 , V_2 -> V_204 [ V_16 ] ) ;
if ( V_2 -> V_153 > 0 )
F_123 ( L_48 ,
V_2 -> V_153 ,
V_2 -> V_178 [ 0 ] . V_48 , V_2 -> V_178 [ 1 ] . V_48 ,
V_2 -> V_178 [ 0 ] . V_179 , V_2 -> V_178 [ 1 ] . V_179 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_153 ; V_16 ++ )
F_121 ( V_19 , L_49 ,
V_2 -> V_204 [ V_150 -> V_152 + V_16 ] ) ;
if ( V_150 -> V_155 )
F_123 ( L_50 ,
V_150 -> V_219 [ 0 ] , V_150 -> V_219 [ 1 ] ,
V_150 -> V_219 [ 2 ] , V_150 -> V_219 [ 3 ] ,
V_2 -> V_159 . V_161 [ 0 ] ,
V_2 -> V_159 . V_161 [ 1 ] ,
V_2 -> V_159 . V_161 [ 2 ] ,
V_2 -> V_159 . V_161 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_150 -> V_155 ; V_16 ++ )
F_121 ( V_19 , L_51 , V_2 -> V_166 [ V_16 ] ) ;
if ( V_150 -> V_156 )
F_123 ( L_52 ,
V_150 -> V_220 [ 0 ] , V_150 -> V_220 [ 1 ] ,
V_150 -> V_220 [ 2 ] , V_150 -> V_220 [ 3 ] ,
V_2 -> V_159 . V_162 [ 0 ] ,
V_2 -> V_159 . V_162 [ 1 ] ,
V_2 -> V_159 . V_162 [ 2 ] ,
V_2 -> V_159 . V_162 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_150 -> V_156 ; V_16 ++ )
F_121 ( V_19 , L_53 , V_2 -> V_168 [ V_16 ] ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ )
F_121 ( V_19 , L_54 , V_2 -> V_207 [ V_16 ] ) ;
}
static void F_124 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_52 ;
V_2 -> V_78 = 0 ;
memset ( V_2 -> V_79 , 0 , sizeof( V_2 -> V_79 ) ) ;
F_125 (nid, codec) {
if ( F_38 ( F_39 ( V_19 , V_52 ) ) != V_68 )
continue;
if ( V_2 -> V_78 >= F_102 ( V_2 -> V_79 ) ) {
F_126 ( V_19 , L_55 ) ;
break;
}
V_2 -> V_79 [ V_2 -> V_78 ++ ] = V_52 ;
}
}
static int F_127 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_151 ;
struct V_149 * V_227 ;
unsigned int V_20 ;
int V_228 = V_229 ;
int V_172 ;
bool V_209 = true , V_210 = true ;
bool V_230 = true , V_231 = true ;
bool V_232 = false ;
V_227 = F_128 ( sizeof( * V_227 ) , V_13 ) ;
if ( ! V_227 )
return - V_136 ;
* V_227 = * V_150 ;
for (; ; ) {
V_172 = F_120 ( V_19 , V_209 ,
V_210 ) ;
if ( V_172 < 0 ) {
F_8 ( V_227 ) ;
return V_172 ;
}
F_123 ( L_56 ,
V_150 -> V_164 , V_209 , V_210 ,
V_172 ) ;
F_122 ( V_19 , V_150 ) ;
if ( V_172 < V_228 ) {
V_228 = V_172 ;
* V_227 = * V_150 ;
V_230 = V_209 ;
V_231 = V_210 ;
}
if ( ! V_172 )
break;
V_210 = ! V_210 ;
if ( ! V_210 )
continue;
V_209 = ! V_209 ;
if ( ! V_209 )
continue;
if ( V_232 )
break;
V_232 = true ;
if ( V_150 -> V_156 > 0 &&
V_150 -> V_164 == V_167 ) {
V_150 -> V_155 = V_150 -> V_152 ;
memcpy ( V_150 -> V_219 , V_150 -> V_218 ,
sizeof( V_150 -> V_219 ) ) ;
V_150 -> V_152 = V_150 -> V_156 ;
memcpy ( V_150 -> V_218 , V_150 -> V_220 ,
sizeof( V_150 -> V_220 ) ) ;
V_150 -> V_156 = 0 ;
memset ( V_150 -> V_220 , 0 , sizeof( V_150 -> V_220 ) ) ;
V_150 -> V_164 = V_165 ;
V_209 = true ;
continue;
}
if ( V_150 -> V_155 > 0 &&
V_150 -> V_164 == V_165 ) {
V_150 -> V_156 = V_150 -> V_152 ;
memcpy ( V_150 -> V_220 , V_150 -> V_218 ,
sizeof( V_150 -> V_220 ) ) ;
V_150 -> V_152 = V_150 -> V_155 ;
memcpy ( V_150 -> V_218 , V_150 -> V_219 ,
sizeof( V_150 -> V_219 ) ) ;
V_150 -> V_155 = 0 ;
memset ( V_150 -> V_219 , 0 , sizeof( V_150 -> V_219 ) ) ;
V_150 -> V_164 = V_167 ;
V_209 = true ;
continue;
}
break;
}
if ( V_172 ) {
F_123 ( L_57 ) ;
* V_150 = * V_227 ;
F_120 ( V_19 , V_230 , V_231 ) ;
}
F_123 ( L_58 ,
V_150 -> V_164 , V_230 , V_231 ) ;
F_122 ( V_19 , V_150 ) ;
if ( V_150 -> V_218 [ 0 ] ) {
struct V_6 * V_54 ;
V_54 = F_26 ( V_19 , V_2 -> V_204 [ 0 ] ) ;
if ( V_54 )
V_2 -> V_233 = F_50 ( V_19 , V_54 ) ;
if ( V_2 -> V_233 ) {
F_129 ( V_19 , V_2 -> V_233 ,
V_84 , V_2 -> V_234 ) ;
if ( V_2 -> V_174 )
V_2 -> V_234 [ 3 ] |= V_235 ;
}
}
if ( V_2 -> V_236 || V_150 -> V_164 == V_167 )
V_20 = V_237 ;
else
V_20 = V_238 ;
F_20 ( V_19 , V_150 -> V_152 , V_150 -> V_218 , V_20 ) ;
if ( V_150 -> V_164 != V_167 )
F_20 ( V_19 , V_150 -> V_155 , V_150 -> V_219 , V_237 ) ;
if ( V_150 -> V_164 != V_165 ) {
V_20 = V_2 -> V_236 ? V_237 : V_238 ;
F_20 ( V_19 , V_150 -> V_156 ,
V_150 -> V_220 , V_20 ) ;
}
if ( V_2 -> V_40 && ! F_118 ( V_19 ) )
V_2 -> V_40 = 0 ;
F_8 ( V_227 ) ;
return 0 ;
}
static int F_130 ( struct V_18 * V_19 ,
const struct V_149 * V_150 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_211 , V_239 ;
V_239 = V_150 -> V_152 ;
if ( V_2 -> V_153 > 0 && V_150 -> V_152 < 3 )
V_239 += V_2 -> V_153 ;
for ( V_16 = 0 ; V_16 < V_239 ; V_16 ++ ) {
const char * V_10 ;
int V_130 ;
struct V_6 * V_54 ;
V_54 = F_26 ( V_19 , V_2 -> V_204 [ V_16 ] ) ;
if ( ! V_54 )
continue;
V_10 = F_101 ( V_19 , V_16 , & V_130 , V_108 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_59 ) ) {
V_211 = F_85 ( V_19 , L_60 , 0 , 1 , V_54 ) ;
if ( V_211 < 0 )
return V_211 ;
V_211 = F_85 ( V_19 , L_61 , 0 , 2 , V_54 ) ;
if ( V_211 < 0 )
return V_211 ;
} else {
V_211 = F_88 ( V_19 , V_10 , V_130 , V_54 ) ;
if ( V_211 < 0 )
return V_211 ;
}
V_10 = F_101 ( V_19 , V_16 , & V_130 , V_107 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_59 ) ) {
V_211 = F_89 ( V_19 , L_60 , 0 , 1 , V_54 ) ;
if ( V_211 < 0 )
return V_211 ;
V_211 = F_89 ( V_19 , L_61 , 0 , 2 , V_54 ) ;
if ( V_211 < 0 )
return V_211 ;
} else {
V_211 = F_92 ( V_19 , V_10 , V_130 , V_54 ) ;
if ( V_211 < 0 )
return V_211 ;
}
}
return 0 ;
}
static int F_131 ( struct V_18 * V_19 , int V_127 ,
const char * V_64 , int V_128 )
{
struct V_6 * V_54 ;
int V_211 ;
V_54 = F_26 ( V_19 , V_127 ) ;
if ( ! V_54 )
return 0 ;
V_211 = F_88 ( V_19 , V_64 , V_128 , V_54 ) ;
if ( V_211 < 0 )
return V_211 ;
V_211 = F_92 ( V_19 , V_64 , V_128 , V_54 ) ;
if ( V_211 < 0 )
return V_211 ;
return 0 ;
}
static int F_132 ( struct V_18 * V_19 , int V_50 ,
const int * V_5 , const char * V_64 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_50 ; V_16 ++ ) {
const char * V_10 ;
char V_240 [ V_135 ] ;
int V_211 , V_60 = 0 ;
if ( V_50 == 2 && V_16 == 1 && ! strcmp ( V_64 , L_37 ) )
V_10 = L_38 ;
else if ( V_50 >= 3 ) {
snprintf ( V_240 , sizeof( V_240 ) , L_62 ,
V_64 , V_163 [ V_16 ] ) ;
V_10 = V_240 ;
} else {
V_10 = V_64 ;
V_60 = V_16 ;
}
V_211 = F_131 ( V_19 , V_5 [ V_16 ] , V_10 , V_60 ) ;
if ( V_211 < 0 )
return V_211 ;
}
return 0 ;
}
static int F_133 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_132 ( V_19 , V_2 -> V_151 . V_155 ,
V_2 -> V_166 ,
L_39 ) ;
}
static int F_134 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_132 ( V_19 , V_2 -> V_151 . V_156 ,
V_2 -> V_168 ,
L_37 ) ;
}
static int F_135 ( struct V_140 * V_141 ,
struct V_241 * V_242 )
{
return F_136 ( V_141 , V_242 ) ;
}
static int F_137 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_143 -> V_146 . V_243 . V_244 [ 0 ] = V_2 -> V_245 ;
return 0 ;
}
static int F_138 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_246 = V_143 -> V_146 . V_243 . V_244 [ 0 ] ;
int V_247 = 0 ;
F_139 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_248 ) {
V_247 = - V_249 ;
goto V_250;
}
if ( V_2 -> V_245 != V_246 ) {
T_1 * V_251 ;
if ( V_2 -> V_151 . V_164 == V_167 )
V_251 = & V_2 -> V_177 [ 0 ] ;
else
V_251 = & V_2 -> V_159 . V_161 [ 0 ] ;
if ( V_2 -> V_252 ) {
if ( V_2 -> V_151 . V_164 == V_167 )
F_140 ( V_19 , V_2 -> V_253 ,
V_2 -> V_204 [ 0 ] ,
V_2 -> V_207 [ 0 ] ,
V_2 -> V_151 . V_164 ) ;
else
F_140 ( V_19 , V_2 -> V_253 ,
V_2 -> V_166 [ 0 ] ,
V_2 -> V_207 [ 1 ] ,
V_167 ) ;
}
V_2 -> V_245 = V_246 ;
if ( V_2 -> V_245 )
* V_251 = 0 ;
else
* V_251 = V_2 -> V_254 ;
F_141 ( V_19 , NULL ) ;
V_247 = 1 ;
}
V_250:
F_142 ( & V_2 -> V_9 ) ;
return V_247 ;
}
static int F_143 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_179 ;
if ( ! V_2 -> V_40 )
return 0 ;
if ( V_2 -> V_151 . V_164 == V_167 )
V_179 = V_2 -> V_159 . V_212 [ 0 ] ;
else
V_179 = V_2 -> V_159 . V_161 [ 0 ] ;
if ( ! V_179 ) {
V_2 -> V_40 = 0 ;
return 0 ;
}
V_2 -> V_245 = false ;
V_2 -> V_254 = V_179 ;
if ( ! F_4 ( V_2 , NULL , & V_255 ) )
return - V_136 ;
return 0 ;
}
static int F_144 ( struct V_140 * V_141 ,
struct V_241 * V_242 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_81 ;
V_242 -> type = V_256 ;
V_242 -> V_257 = 1 ;
V_242 -> V_146 . V_243 . V_258 = V_2 -> V_153 + 1 ;
if ( V_242 -> V_146 . V_243 . V_244 > V_2 -> V_153 )
V_242 -> V_146 . V_243 . V_244 = V_2 -> V_153 ;
V_81 = V_242 -> V_146 . V_243 . V_244 * 2 + V_2 -> V_224 ;
sprintf ( V_242 -> V_146 . V_243 . V_10 , L_63 , V_81 ) ;
return 0 ;
}
static int F_145 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_143 -> V_146 . V_243 . V_244 [ 0 ] =
( V_2 -> V_223 - V_2 -> V_224 ) / 2 ;
return 0 ;
}
static inline struct V_6 *
F_146 ( struct V_18 * V_19 , int V_60 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_26 ( V_19 ,
V_2 -> V_204 [ V_2 -> V_151 . V_152 + V_60 ] ) ;
}
static bool F_147 ( struct V_1 * V_2 )
{
return ! V_2 -> V_252 || V_2 -> V_253 ;
}
static int F_148 ( struct V_18 * V_19 , int V_60 , bool V_259 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_52 = V_2 -> V_178 [ V_60 ] . V_48 ;
struct V_6 * V_54 ;
V_54 = F_146 ( V_19 , V_60 ) ;
if ( ! V_54 )
return - V_260 ;
if ( V_54 -> V_93 == V_259 )
return 0 ;
if ( V_259 ) {
F_17 ( V_19 , V_52 , V_238 , true ) ;
F_76 ( V_19 , V_54 , true , F_147 ( V_2 ) ) ;
F_79 ( V_19 , V_52 , true ) ;
} else {
F_79 ( V_19 , V_52 , false ) ;
F_76 ( V_19 , V_54 , false , F_147 ( V_2 ) ) ;
F_17 ( V_19 , V_52 , V_2 -> V_178 [ V_60 ] . V_261 , true ) ;
F_78 ( V_19 , V_54 ) ;
}
F_149 ( V_19 ) ;
return 0 ;
}
static int F_150 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_148 ;
V_148 = V_143 -> V_146 . V_243 . V_244 [ 0 ] ;
if ( V_148 < 0 || V_148 > V_2 -> V_153 )
return - V_260 ;
if ( V_148 == ( V_2 -> V_223 - V_2 -> V_224 ) / 2 )
return 0 ;
V_2 -> V_223 = V_148 * 2 + V_2 -> V_224 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_153 ; V_16 ++ )
F_148 ( V_19 , V_16 , V_16 < V_148 ) ;
V_2 -> V_159 . V_262 = F_151 ( V_2 -> V_223 ,
V_2 -> V_263 ) ;
if ( V_2 -> V_35 )
V_2 -> V_159 . V_160 = V_2 -> V_159 . V_262 / 2 ;
return 1 ;
}
static int F_152 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_153 > 0 ) {
if ( ! F_4 ( V_2 , NULL , & V_264 ) )
return - V_136 ;
}
return 0 ;
}
static int F_153 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_143 -> V_146 . V_243 . V_244 [ 0 ] = V_2 -> V_253 ;
return 0 ;
}
static void F_140 ( struct V_18 * V_19 , bool V_265 ,
int V_266 , int V_267 ,
int V_268 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_269 , * V_270 ;
V_269 = F_26 ( V_19 , V_266 ) ;
V_270 = F_26 ( V_19 , V_267 ) ;
if ( ! V_269 || ! V_270 )
return;
if ( V_268 == V_167 && V_2 -> V_245 &&
V_270 -> V_54 [ 0 ] != V_2 -> V_254 )
V_265 = false ;
if ( V_265 ) {
F_76 ( V_19 , V_269 , false , true ) ;
F_76 ( V_19 , V_270 , true , true ) ;
F_78 ( V_19 , V_269 ) ;
} else {
F_76 ( V_19 , V_270 , false , false ) ;
F_76 ( V_19 , V_269 , true , false ) ;
F_78 ( V_19 , V_270 ) ;
}
}
static void F_154 ( struct V_18 * V_19 , int V_180 ,
const int * V_5 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_54 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_180 ; V_16 ++ ) {
V_54 = F_26 ( V_19 , V_5 [ V_16 ] ) ;
if ( V_54 )
F_76 ( V_19 , V_54 , V_54 -> V_93 ,
V_2 -> V_253 ) ;
}
}
static int F_155 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_149 * V_150 = & V_2 -> V_151 ;
unsigned int V_20 = V_143 -> V_146 . V_243 . V_244 [ 0 ] ;
if ( V_20 == V_2 -> V_253 )
return 0 ;
V_2 -> V_253 = V_20 ;
if ( F_116 ( V_2 ) ) {
F_140 ( V_19 , V_20 , V_2 -> V_204 [ 0 ] ,
V_2 -> V_207 [ 0 ] ,
V_150 -> V_164 ) ;
F_140 ( V_19 , V_20 , V_2 -> V_166 [ 0 ] ,
V_2 -> V_207 [ 1 ] ,
V_167 ) ;
F_140 ( V_19 , V_20 , V_2 -> V_168 [ 0 ] ,
V_2 -> V_207 [ 2 ] ,
V_165 ) ;
} else {
F_154 ( V_19 , V_150 -> V_152 , V_2 -> V_204 ) ;
if ( V_150 -> V_164 != V_167 )
F_154 ( V_19 , V_150 -> V_155 , V_2 -> V_166 ) ;
if ( V_150 -> V_164 != V_165 )
F_154 ( V_19 , V_150 -> V_156 ,
V_2 -> V_168 ) ;
}
return 1 ;
}
static int F_156 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_47 )
return 0 ;
if ( ! F_4 ( V_2 , NULL , & V_271 ) )
return - V_136 ;
V_2 -> V_252 = 1 ;
return 0 ;
}
static void F_157 ( struct V_18 * V_19 , int V_272 , bool V_273 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_274 ;
unsigned int V_20 ;
T_1 V_48 ;
V_48 = V_2 -> V_275 ;
V_274 = V_2 -> V_276 [ V_272 ] == V_2 -> V_277 ;
if ( ! V_273 ) {
V_20 = F_16 ( V_19 , V_48 ) ;
if ( V_274 ) {
if ( V_20 & V_278 )
return;
} else {
if ( V_20 & V_238 )
return;
}
}
V_20 = F_158 ( V_19 , V_48 ) ;
if ( V_20 == V_279 && V_2 -> V_280 ) {
const T_1 V_281 = V_2 -> V_280 ;
unsigned int V_282 = F_158 ( V_19 , V_281 ) ;
if ( V_282 != V_279 )
F_159 ( V_19 , V_281 ,
V_278 | ( V_274 ? V_282 : 0 ) ) ;
}
if ( ! V_2 -> V_283 ) {
if ( V_274 )
V_20 |= V_278 ;
else
V_20 = V_237 ;
F_17 ( V_19 , V_48 , V_20 , true ) ;
F_141 ( V_19 , NULL ) ;
}
}
static int F_160 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_151 ;
unsigned int V_193 ;
T_1 V_52 ;
if ( ! V_2 -> V_44 ) {
if ( V_2 -> V_45 )
return 0 ;
if ( V_150 -> V_199 > 1 )
return 0 ;
else if ( V_150 -> V_199 == 1 ) {
V_193 = F_110 ( V_19 , V_150 -> V_200 [ 0 ] . V_48 ) ;
if ( F_161 ( V_193 ) != V_284 )
return 0 ;
}
}
V_2 -> V_44 = 0 ;
if ( V_150 -> V_199 >= V_285 )
return 0 ;
V_52 = 0 ;
if ( V_150 -> V_164 == V_167 && V_150 -> V_152 > 0 )
V_52 = V_150 -> V_218 [ 0 ] ;
else if ( V_150 -> V_155 > 0 )
V_52 = V_150 -> V_219 [ 0 ] ;
if ( ! V_52 )
return 0 ;
if ( ! ( F_80 ( V_19 , V_52 ) & V_286 ) )
return 0 ;
V_150 -> V_200 [ V_150 -> V_199 ] . V_48 = V_52 ;
V_150 -> V_200 [ V_150 -> V_199 ] . type = V_198 ;
V_150 -> V_200 [ V_150 -> V_199 ] . V_287 = 1 ;
V_150 -> V_199 ++ ;
V_2 -> V_44 = 1 ;
V_2 -> V_275 = V_52 ;
V_2 -> V_32 = 1 ;
F_35 ( V_19 , L_64 , V_52 ) ;
return 0 ;
}
static int F_162 ( struct V_140 * V_141 ,
struct V_241 * V_242 )
{
return F_163 ( V_141 , V_242 , 2 , V_288 ) ;
}
static int F_164 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
T_1 V_52 = V_141 -> V_133 ;
if ( F_16 ( V_19 , V_52 ) == V_237 )
V_143 -> V_146 . V_243 . V_244 [ 0 ] = 1 ;
else
V_143 -> V_146 . V_243 . V_244 [ 0 ] = 0 ;
return 0 ;
}
static int F_165 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
T_1 V_52 = V_141 -> V_133 ;
unsigned int V_20 ;
V_20 = V_143 -> V_146 . V_243 . V_244 [ 0 ] ? V_237 : V_238 ;
if ( F_16 ( V_19 , V_52 ) == V_20 )
return 0 ;
F_159 ( V_19 , V_52 , V_20 ) ;
return 1 ;
}
static bool F_166 ( struct V_18 * V_19 , const char * V_10 , int V_60 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_3 . V_17 ; V_16 ++ ) {
struct V_4 * V_15 = F_24 ( & V_2 -> V_3 , V_16 ) ;
if ( ! strcmp ( V_15 -> V_10 , V_10 ) && V_15 -> V_130 == V_60 )
return true ;
}
return false ;
}
static void F_167 ( struct V_18 * V_19 , T_1 V_48 ,
char * V_10 , T_3 V_289 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_60 = 0 ;
F_168 ( V_19 , V_48 , & V_2 -> V_151 , V_10 , V_289 , & V_60 ) ;
F_169 ( V_10 , L_65 , V_289 ) ;
for (; F_166 ( V_19 , V_10 , V_60 ) ; V_60 ++ )
;
}
static int F_170 ( struct V_18 * V_19 , T_1 V_48 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_42 ) {
unsigned int V_290 = F_80 ( V_19 , V_48 ) ;
if ( ( V_290 & V_195 ) && ( V_290 & V_291 ) )
return 2 ;
}
return 1 ;
}
static int F_171 ( struct V_18 * V_19 , int V_50 ,
T_1 * V_51 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_50 ; V_16 ++ ) {
T_1 V_48 = V_51 [ V_16 ] ;
if ( V_48 == V_2 -> V_275 )
continue;
if ( F_170 ( V_19 , V_48 ) > 1 ) {
struct V_4 * V_12 ;
char V_10 [ V_135 ] ;
F_167 ( V_19 , V_48 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 ,
& V_292 ) ;
if ( ! V_12 )
return - V_136 ;
V_12 -> V_133 = V_48 ;
}
}
return 0 ;
}
static unsigned int F_172 ( struct V_18 * V_19 , T_1 V_48 )
{
unsigned int V_290 ;
V_290 = F_80 ( V_19 , V_48 ) ;
V_290 = ( V_290 & V_293 ) >> V_294 ;
V_290 &= ~ ( V_295 | V_296 ) ;
return V_290 ;
}
static int F_173 ( unsigned int V_297 , unsigned int V_298 )
{
unsigned int V_16 , V_90 = 0 ;
for ( V_16 = 0 ; V_16 < V_299 ; V_16 ++ ) {
if ( V_297 & ( 1 << V_16 ) ) {
if ( V_90 == V_298 )
return V_16 ;
V_90 ++ ;
}
}
return 0 ;
}
static int F_174 ( unsigned int V_297 , unsigned int V_60 )
{
unsigned int V_16 , V_90 = 0 ;
for ( V_16 = 0 ; V_16 < V_299 ; V_16 ++ ) {
if ( V_16 == V_60 )
return V_90 ;
if ( V_297 & ( 1 << V_16 ) )
V_90 ++ ;
}
return 0 ;
}
static int F_175 ( struct V_140 * V_141 ,
struct V_241 * V_242 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
T_1 V_52 = V_141 -> V_133 ;
unsigned int V_297 = F_172 ( V_19 , V_52 ) ;
F_163 ( V_141 , V_242 , F_176 ( V_297 ) ,
V_300 ) ;
strcpy ( V_242 -> V_146 . V_243 . V_10 ,
V_300 [ F_173 ( V_297 , V_242 -> V_146 . V_243 . V_244 ) ] ) ;
return 0 ;
}
static int F_177 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
T_1 V_52 = V_141 -> V_133 ;
unsigned int V_297 = F_172 ( V_19 , V_52 ) ;
unsigned int V_60 ;
V_60 = F_16 ( V_19 , V_52 ) & V_301 ;
V_143 -> V_146 . V_243 . V_244 [ 0 ] = F_174 ( V_297 , V_60 ) ;
return 0 ;
}
static int F_178 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
T_1 V_52 = V_141 -> V_133 ;
unsigned int V_297 = F_172 ( V_19 , V_52 ) ;
unsigned int V_20 , V_60 ;
V_20 = F_16 ( V_19 , V_52 ) ;
V_60 = F_174 ( V_297 , V_20 & V_301 ) ;
if ( V_60 == V_143 -> V_146 . V_243 . V_244 [ 0 ] )
return 0 ;
V_20 &= ~ V_301 ;
V_20 |= F_173 ( V_297 , V_143 -> V_146 . V_243 . V_244 [ 0 ] ) ;
F_159 ( V_19 , V_52 , V_20 ) ;
return 1 ;
}
static int F_179 ( struct V_18 * V_19 , T_1 V_48 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_302 = 0 ;
if ( V_2 -> V_42 )
V_302 = F_176 ( F_172 ( V_19 , V_48 ) ) ;
return V_302 ? V_302 : 1 ;
}
static int F_180 ( struct V_18 * V_19 , T_1 V_48 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
char V_10 [ V_135 ] ;
unsigned int V_193 ;
if ( V_48 == V_2 -> V_275 )
return 0 ;
V_193 = F_110 ( V_19 , V_48 ) ;
if ( F_161 ( V_193 ) == V_284 )
return 0 ;
if ( F_179 ( V_19 , V_48 ) <= 1 )
return 0 ;
F_167 ( V_19 , V_48 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 , & V_303 ) ;
if ( ! V_12 )
return - V_136 ;
V_12 -> V_133 = V_48 ;
return 0 ;
}
static int F_181 ( struct V_140 * V_141 ,
struct V_241 * V_242 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
T_1 V_52 = V_141 -> V_133 ;
int V_304 = F_170 ( V_19 , V_52 ) ;
int V_305 = F_179 ( V_19 , V_52 ) ;
const char * V_306 = NULL ;
int V_60 ;
V_242 -> type = V_256 ;
V_242 -> V_257 = 1 ;
V_242 -> V_146 . V_243 . V_258 = V_304 + V_305 ;
if ( V_242 -> V_146 . V_243 . V_244 >= V_242 -> V_146 . V_243 . V_258 )
V_242 -> V_146 . V_243 . V_244 = V_242 -> V_146 . V_243 . V_258 - 1 ;
V_60 = V_242 -> V_146 . V_243 . V_244 ;
if ( V_60 < V_304 ) {
if ( V_304 > 1 )
V_306 = V_288 [ V_60 ] ;
else
V_306 = L_66 ;
} else {
V_60 -= V_304 ;
if ( V_305 > 1 ) {
unsigned int V_297 = F_172 ( V_19 , V_52 ) ;
V_306 = V_300 [ F_173 ( V_297 , V_60 ) ] ;
} else
V_306 = L_67 ;
}
strcpy ( V_242 -> V_146 . V_243 . V_10 , V_306 ) ;
return 0 ;
}
static int F_182 ( struct V_18 * V_19 , T_1 V_52 )
{
int V_304 = F_170 ( V_19 , V_52 ) ;
int V_305 = F_179 ( V_19 , V_52 ) ;
unsigned int V_20 = F_16 ( V_19 , V_52 ) ;
int V_60 = 0 ;
if ( V_20 & V_238 ) {
if ( V_304 > 1 && V_20 == V_237 )
V_60 = 1 ;
} else if ( V_20 & V_278 ) {
V_60 = V_304 ;
if ( V_305 > 1 ) {
unsigned int V_297 = F_172 ( V_19 , V_52 ) ;
V_20 &= V_301 ;
V_60 += F_174 ( V_297 , V_20 ) ;
}
}
return V_60 ;
}
static int F_183 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
T_1 V_52 = V_141 -> V_133 ;
V_143 -> V_146 . V_243 . V_244 [ 0 ] =
F_182 ( V_19 , V_52 ) ;
return 0 ;
}
static int F_184 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
T_1 V_52 = V_141 -> V_133 ;
int V_304 = F_170 ( V_19 , V_52 ) ;
int V_305 = F_179 ( V_19 , V_52 ) ;
unsigned int V_20 , V_307 , V_60 ;
V_307 = F_182 ( V_19 , V_52 ) ;
V_60 = V_143 -> V_146 . V_243 . V_244 [ 0 ] ;
if ( V_307 == V_60 )
return 0 ;
if ( V_60 < V_304 ) {
if ( V_304 > 1 )
V_20 = V_60 ? V_237 : V_238 ;
else
V_20 = V_237 ;
} else {
V_60 -= V_304 ;
if ( V_305 > 1 ) {
unsigned int V_297 = F_172 ( V_19 , V_52 ) ;
V_20 = F_16 ( V_19 , V_52 ) ;
V_20 &= ~ ( V_301 | V_237 ) ;
V_20 |= F_173 ( V_297 , V_60 ) | V_278 ;
} else
V_20 = F_158 ( V_19 , V_52 ) | V_278 ;
}
F_159 ( V_19 , V_52 , V_20 ) ;
F_141 ( V_19 , NULL ) ;
return 1 ;
}
static int F_185 ( struct V_18 * V_19 , T_1 V_48 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
V_12 = F_4 ( V_2 , L_68 ,
& V_308 ) ;
if ( ! V_12 )
return - V_136 ;
V_12 -> V_133 = V_48 ;
V_2 -> V_283 = 1 ;
return 0 ;
}
static int F_186 ( struct V_1 * V_2 , T_1 V_309 , int V_60 )
{
struct V_8 * V_14 ;
V_14 = F_5 ( & V_2 -> V_7 ) ;
if ( ! V_14 )
return - V_136 ;
V_14 -> V_52 = V_309 ;
V_14 -> V_63 = V_85 ;
V_14 -> V_60 = V_60 ;
V_2 -> V_310 . V_311 = V_2 -> V_7 . V_14 ;
return 0 ;
}
static bool F_187 ( struct V_18 * V_19 , T_1 V_312 ,
T_1 V_48 , unsigned int * V_313 ,
unsigned int * V_314 )
{
int V_60 , V_315 ;
const T_1 * V_14 ;
T_1 V_52 ;
V_60 = F_29 ( V_19 , V_312 , V_48 , true ) ;
if ( V_60 < 0 )
return false ;
* V_313 = * V_314 = 0 ;
if ( F_51 ( V_19 , V_312 , V_85 ) )
* V_313 = F_32 ( V_312 , 3 , V_60 , V_85 ) ;
if ( F_49 ( V_19 , V_312 , V_85 ) )
* V_314 = F_32 ( V_312 , 3 , V_60 , V_85 ) ;
if ( * V_313 && * V_314 )
return true ;
V_315 = F_37 ( V_19 , V_312 , & V_14 ) ;
if ( V_315 < V_60 )
return false ;
V_52 = V_14 [ V_60 ] ;
if ( ! * V_313 && F_51 ( V_19 , V_52 , V_84 ) &&
! F_31 ( V_19 , V_52 , V_84 , 0 , V_108 ) )
* V_313 = F_32 ( V_52 , 3 , 0 , V_84 ) ;
if ( ! * V_314 && F_49 ( V_19 , V_52 , V_84 ) &&
! F_31 ( V_19 , V_52 , V_84 , 0 , V_107 ) )
* V_314 = F_32 ( V_52 , 3 , 0 , V_84 ) ;
return * V_313 || * V_314 ;
}
static int F_188 ( struct V_18 * V_19 , int V_316 ,
T_1 V_48 , const char * V_317 , int V_318 ,
T_1 V_312 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_54 ;
unsigned int V_313 , V_314 ;
int V_211 , V_60 ;
if ( ! F_187 ( V_19 , V_312 , V_48 , & V_313 , & V_314 ) )
return 0 ;
V_54 = F_41 ( V_19 , V_48 , V_312 , 0 ) ;
if ( ! V_54 )
return - V_260 ;
F_33 ( V_19 , L_69 , V_54 ) ;
V_2 -> V_215 [ V_316 ] = F_25 ( V_19 , V_54 ) ;
V_60 = V_54 -> V_60 [ V_54 -> V_55 - 1 ] ;
if ( V_313 ) {
V_211 = F_86 ( V_2 , V_137 , V_317 , V_318 , V_313 ) ;
if ( V_211 < 0 )
return V_211 ;
V_54 -> V_62 [ V_108 ] = V_313 ;
}
if ( V_314 ) {
V_211 = F_91 ( V_2 , V_138 , V_317 , V_318 , V_314 ) ;
if ( V_211 < 0 )
return V_211 ;
V_54 -> V_62 [ V_107 ] = V_314 ;
}
V_54 -> V_93 = true ;
V_54 -> V_94 = true ;
V_211 = F_186 ( V_2 , V_312 , V_60 ) ;
if ( V_211 < 0 )
return V_211 ;
if ( V_2 -> V_47 != V_2 -> V_112 &&
! V_2 -> V_319 ) {
V_54 = F_41 ( V_19 , V_2 -> V_47 ,
V_2 -> V_112 , 0 ) ;
if ( V_54 ) {
F_33 ( V_19 , L_70 , V_54 ) ;
V_54 -> V_93 = true ;
V_54 -> V_96 = true ;
V_54 -> V_94 = true ;
V_2 -> V_319 =
F_25 ( V_19 , V_54 ) ;
}
}
return 0 ;
}
static int F_189 ( struct V_18 * V_19 , T_1 V_52 )
{
unsigned int V_290 = F_80 ( V_19 , V_52 ) ;
return ( V_290 & V_286 ) != 0 ;
}
static int F_190 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_52 ;
T_1 * V_320 = V_2 -> V_320 ;
int V_321 = F_102 ( V_2 -> V_320 ) ;
int V_53 = 0 ;
F_125 (nid, codec) {
unsigned int V_87 = F_39 ( V_19 , V_52 ) ;
int type = F_38 ( V_87 ) ;
if ( type != V_71 || ( V_87 & V_80 ) )
continue;
V_320 [ V_53 ] = V_52 ;
if ( ++ V_53 >= V_321 )
break;
}
V_2 -> V_322 = V_53 ;
V_2 -> V_323 = V_53 ;
memcpy ( V_2 -> V_324 , V_2 -> V_320 , V_53 * sizeof( T_1 ) ) ;
return V_53 ;
}
static int F_191 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_325 * V_326 = & V_2 -> V_327 ;
unsigned int V_328 ;
int V_16 , V_90 , V_53 ;
V_53 = 0 ;
V_328 = 0 ;
for ( V_90 = 0 ; V_90 < V_2 -> V_322 ; V_90 ++ ) {
for ( V_16 = 0 ; V_16 < V_326 -> V_329 ; V_16 ++ ) {
if ( ! V_2 -> V_214 [ V_16 ] [ V_90 ] )
break;
}
if ( V_16 >= V_326 -> V_329 ) {
V_328 |= ( 1 << V_90 ) ;
V_53 ++ ;
}
}
if ( ! V_328 ) {
for ( V_16 = 0 ; V_16 < V_326 -> V_329 ; V_16 ++ ) {
for ( V_90 = 0 ; V_90 < V_2 -> V_322 ; V_90 ++ ) {
if ( V_2 -> V_214 [ V_16 ] [ V_90 ] ) {
V_2 -> V_330 [ V_16 ] = V_90 ;
break;
}
}
}
F_35 ( V_19 , L_71 ) ;
V_2 -> V_331 = 1 ;
} else if ( V_53 != V_2 -> V_322 ) {
V_53 = 0 ;
for ( V_90 = 0 ; V_90 < V_2 -> V_322 ; V_90 ++ ) {
if ( ! ( V_328 & ( 1 << V_90 ) ) )
continue;
if ( V_90 != V_53 ) {
V_2 -> V_320 [ V_53 ] = V_2 -> V_320 [ V_90 ] ;
for ( V_16 = 0 ; V_16 < V_326 -> V_329 ; V_16 ++ ) {
F_42 ( V_19 ,
V_2 -> V_214 [ V_16 ] [ V_53 ] ) ;
V_2 -> V_214 [ V_16 ] [ V_53 ] =
V_2 -> V_214 [ V_16 ] [ V_90 ] ;
V_2 -> V_214 [ V_16 ] [ V_90 ] = 0 ;
}
}
V_53 ++ ;
}
V_2 -> V_322 = V_53 ;
}
if ( V_326 -> V_329 == 1 ||
( V_326 -> V_329 == 2 && V_2 -> V_44 ) ) {
F_35 ( V_19 , L_72 ) ;
V_2 -> V_322 = 1 ;
}
if ( ! V_2 -> V_331 && V_2 -> V_38 )
V_2 -> V_322 = 1 ;
return 0 ;
}
static int F_192 ( struct V_18 * V_19 , T_1 V_48 ,
int V_332 , int V_333 ,
const char * V_334 , int V_335 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_325 * V_326 = & V_2 -> V_327 ;
int V_336 = V_326 -> V_329 ;
bool V_337 = false ;
int V_338 ;
for ( V_338 = 0 ; V_338 < V_333 ; V_338 ++ ) {
struct V_6 * V_54 ;
T_1 V_339 = V_2 -> V_320 [ V_338 ] ;
if ( ! F_28 ( V_19 , V_48 , V_339 ) )
continue;
V_54 = F_41 ( V_19 , V_48 , V_339 , V_335 ) ;
if ( ! V_54 )
continue;
F_33 ( V_19 , L_73 , V_54 ) ;
V_2 -> V_214 [ V_336 ] [ V_338 ] =
F_25 ( V_19 , V_54 ) ;
if ( ! V_337 ) {
if ( V_2 -> V_275 == V_48 )
V_2 -> V_277 = V_326 -> V_329 ;
V_2 -> V_340 [ V_326 -> V_329 ] = V_48 ;
F_193 ( V_19 , V_326 , V_334 , V_332 , NULL ) ;
V_337 = true ;
if ( V_2 -> V_331 )
V_2 -> V_330 [ V_336 ] = V_338 ;
}
}
return 0 ;
}
static int F_194 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_149 * V_150 = & V_2 -> V_151 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_150 -> V_199 ; V_16 ++ ) {
T_1 V_48 = V_150 -> V_200 [ V_16 ] . V_48 ;
const char * V_334 ;
int V_184 , V_60 ;
if ( ! F_189 ( V_19 , V_48 ) )
continue;
V_334 = F_195 ( V_19 , V_150 , V_16 ) ;
V_60 = 0 ;
for ( V_184 = V_16 - 1 ; V_184 >= 0 ; V_184 -- ) {
if ( V_2 -> V_341 [ V_184 ] &&
! strcmp ( V_2 -> V_341 [ V_184 ] , V_334 ) ) {
V_60 = V_2 -> V_342 [ V_184 ] + 1 ;
break;
}
}
V_2 -> V_341 [ V_16 ] = V_334 ;
V_2 -> V_342 [ V_16 ] = V_60 ;
}
return 0 ;
}
static int F_196 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_149 * V_150 = & V_2 -> V_151 ;
T_1 V_343 = V_2 -> V_47 ;
int V_333 ;
int V_16 , V_211 ;
unsigned int V_20 ;
V_333 = F_190 ( V_19 ) ;
if ( V_333 < 0 )
return 0 ;
V_211 = F_194 ( V_19 ) ;
if ( V_211 < 0 )
return V_211 ;
for ( V_16 = 0 ; V_16 < V_150 -> V_199 ; V_16 ++ ) {
T_1 V_48 ;
V_48 = V_150 -> V_200 [ V_16 ] . V_48 ;
if ( ! F_189 ( V_19 , V_48 ) )
continue;
V_20 = V_278 ;
if ( V_150 -> V_200 [ V_16 ] . type == V_198 )
V_20 |= F_158 ( V_19 , V_48 ) ;
if ( V_48 != V_2 -> V_275 &&
! F_16 ( V_19 , V_48 ) )
F_17 ( V_19 , V_48 , V_20 , false ) ;
if ( V_343 ) {
if ( F_28 ( V_19 , V_48 , V_343 ) ) {
V_211 = F_188 ( V_19 , V_16 , V_48 ,
V_2 -> V_341 [ V_16 ] ,
V_2 -> V_342 [ V_16 ] ,
V_343 ) ;
if ( V_211 < 0 )
return V_211 ;
}
}
V_211 = F_192 ( V_19 , V_48 , V_16 , V_333 ,
V_2 -> V_341 [ V_16 ] , - V_343 ) ;
if ( V_211 < 0 )
return V_211 ;
if ( V_2 -> V_42 ) {
V_211 = F_180 ( V_19 , V_48 ) ;
if ( V_211 < 0 )
return V_211 ;
}
}
if ( V_343 && V_2 -> V_41 == V_344 ) {
V_211 = F_192 ( V_19 , V_343 , V_345 , V_333 ,
L_74 , 0 ) ;
if ( V_211 < 0 )
return V_211 ;
else
V_2 -> V_32 = 1 ;
}
return 0 ;
}
static struct V_6 * F_197 ( struct V_18 * V_19 , int V_346 , int V_336 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_336 < 0 || V_336 >= V_347 ) {
F_103 () ;
return NULL ;
}
if ( V_2 -> V_331 )
V_346 = V_2 -> V_330 [ V_336 ] ;
if ( V_346 < 0 || V_346 >= V_285 ) {
F_103 () ;
return NULL ;
}
return F_26 ( V_19 , V_2 -> V_214 [ V_336 ] [ V_346 ] ) ;
}
static int F_198 ( struct V_140 * V_141 ,
struct V_241 * V_242 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
return F_199 ( & V_2 -> V_327 , V_242 ) ;
}
static int F_200 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_346 = F_201 ( V_141 , & V_143 -> V_348 ) ;
V_143 -> V_146 . V_243 . V_244 [ 0 ] = V_2 -> V_276 [ V_346 ] ;
return 0 ;
}
static int F_202 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
unsigned int V_346 = F_201 ( V_141 , & V_143 -> V_348 ) ;
return F_203 ( V_19 , V_346 ,
V_143 -> V_146 . V_243 . V_244 [ 0 ] ) ;
}
static int F_204 ( struct V_140 * V_141 ,
struct V_142 * V_143 ,
T_4 V_349 , int type )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_325 * V_326 ;
struct V_6 * V_54 ;
int V_16 , V_346 , V_211 = 0 ;
V_326 = & V_2 -> V_327 ;
V_346 = V_141 -> V_348 . V_130 ;
F_139 ( & V_19 -> V_350 ) ;
for ( V_16 = 0 ; V_16 < V_326 -> V_329 ; V_16 ++ ) {
V_54 = F_197 ( V_19 , V_346 , V_16 ) ;
if ( ! V_54 || ! V_54 -> V_62 [ type ] )
continue;
V_141 -> V_133 = V_54 -> V_62 [ type ] ;
V_211 = V_349 ( V_141 , V_143 ) ;
if ( V_211 < 0 )
break;
}
F_142 ( & V_19 -> V_350 ) ;
if ( V_211 >= 0 && V_2 -> V_351 )
V_2 -> V_351 ( V_19 , V_141 , V_143 ) ;
return V_211 ;
}
static int F_205 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
return F_204 ( V_141 , V_143 ,
V_352 ,
V_108 ) ;
}
static int F_206 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
return F_204 ( V_141 , V_143 ,
F_97 ,
V_107 ) ;
}
static int F_207 ( struct V_18 * V_19 , struct V_6 * V_54 )
{
T_1 V_52 ;
int V_16 , V_55 ;
V_54 -> V_62 [ V_108 ] = V_54 -> V_62 [ V_107 ] = 0 ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( V_55 >= V_54 -> V_55 )
return - V_260 ;
V_16 = V_54 -> V_55 - V_55 - 1 ;
V_52 = V_54 -> V_54 [ V_16 ] ;
if ( ! V_54 -> V_62 [ V_108 ] ) {
if ( F_51 ( V_19 , V_52 , V_84 ) )
V_54 -> V_62 [ V_108 ] =
F_32 ( V_52 , 3 , 0 , V_84 ) ;
else if ( F_51 ( V_19 , V_52 , V_85 ) ) {
int V_60 = V_54 -> V_60 [ V_16 ] ;
if ( ! V_55 && V_19 -> V_29 )
V_60 = 0 ;
V_54 -> V_62 [ V_108 ] =
F_32 ( V_52 , 3 , V_60 , V_85 ) ;
}
}
if ( ! V_54 -> V_62 [ V_107 ] ) {
if ( F_49 ( V_19 , V_52 , V_84 ) )
V_54 -> V_62 [ V_107 ] =
F_32 ( V_52 , 3 , 0 , V_84 ) ;
else if ( F_49 ( V_19 , V_52 , V_85 ) ) {
int V_60 = V_54 -> V_60 [ V_16 ] ;
if ( ! V_55 && V_19 -> V_29 )
V_60 = 0 ;
V_54 -> V_62 [ V_107 ] =
F_32 ( V_52 , 3 , V_60 , V_85 ) ;
}
}
}
return 0 ;
}
static bool F_208 ( struct V_18 * V_19 , T_1 V_52 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_151 ;
unsigned int V_20 ;
int V_16 ;
if ( ! V_2 -> V_39 )
return false ;
for ( V_16 = 0 ; V_16 < V_150 -> V_199 ; V_16 ++ ) {
if ( V_150 -> V_200 [ V_16 ] . V_48 != V_52 )
continue;
if ( V_150 -> V_200 [ V_16 ] . type != V_198 )
return false ;
V_20 = F_110 ( V_19 , V_52 ) ;
return F_161 ( V_20 ) == V_284 ;
}
return false ;
}
static int F_209 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_247 ;
V_247 = F_97 ( V_141 , V_143 ) ;
if ( V_247 < 0 )
return V_247 ;
if ( V_2 -> V_351 )
V_2 -> V_351 ( V_19 , V_141 , V_143 ) ;
return V_247 ;
}
static int F_210 ( struct V_18 * V_19 , const char * V_334 ,
int V_60 , bool V_353 , unsigned int V_354 ,
bool V_355 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
char V_356 [ V_135 ] ;
int type = V_353 ? V_138 : V_137 ;
const char * V_134 = V_353 ? L_75 : L_76 ;
unsigned int V_81 = V_355 ? 1 : 3 ;
struct V_4 * V_12 ;
if ( ! V_354 )
return 0 ;
if ( V_334 )
snprintf ( V_356 , sizeof( V_356 ) ,
L_77 , V_334 , V_134 ) ;
else
snprintf ( V_356 , sizeof( V_356 ) ,
L_78 , V_134 ) ;
V_12 = F_82 ( V_2 , type , V_356 , V_60 ,
F_45 ( V_354 , V_81 ) ) ;
if ( ! V_12 )
return - V_136 ;
if ( V_353 )
V_12 -> V_357 = F_209 ;
if ( ! V_355 )
return 0 ;
if ( V_334 )
snprintf ( V_356 , sizeof( V_356 ) ,
L_79 , V_334 , V_134 ) ;
else
snprintf ( V_356 , sizeof( V_356 ) ,
L_80 , V_134 ) ;
V_12 = F_82 ( V_2 , type , V_356 , V_60 ,
F_45 ( V_354 , 2 ) ) ;
if ( ! V_12 )
return - V_136 ;
if ( V_353 )
V_12 -> V_357 = F_209 ;
return 0 ;
}
static int F_211 ( struct V_18 * V_19 , int V_60 ,
unsigned int V_358 , unsigned int V_359 ,
bool V_355 )
{
int V_211 ;
V_211 = F_210 ( V_19 , NULL , V_60 , false , V_358 , V_355 ) ;
if ( V_211 < 0 )
return V_211 ;
V_211 = F_210 ( V_19 , NULL , V_60 , true , V_359 , V_355 ) ;
if ( V_211 < 0 )
return V_211 ;
return 0 ;
}
static int F_212 ( struct V_18 * V_19 , int V_60 ,
unsigned int V_358 , unsigned int V_359 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
if ( V_358 ) {
V_12 = F_4 ( V_2 , NULL , & V_360 ) ;
if ( ! V_12 )
return - V_136 ;
V_12 -> V_130 = V_60 ;
V_12 -> V_133 = V_358 ;
V_12 -> V_131 = V_132 ;
}
if ( V_359 ) {
V_12 = F_4 ( V_2 , NULL , & V_361 ) ;
if ( ! V_12 )
return - V_136 ;
V_12 -> V_130 = V_60 ;
V_12 -> V_133 = V_359 ;
V_12 -> V_131 = V_132 ;
}
return 0 ;
}
static unsigned int F_213 ( struct V_18 * V_19 , int V_60 , int type )
{
struct V_6 * V_54 ;
unsigned int V_354 ;
int V_16 ;
V_54 = F_197 ( V_19 , 0 , V_60 ) ;
if ( ! V_54 )
return 0 ;
V_354 = V_54 -> V_62 [ type ] ;
if ( ! V_354 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_60 - 1 ; V_16 ++ ) {
V_54 = F_197 ( V_19 , 0 , V_16 ) ;
if ( V_54 && V_54 -> V_62 [ type ] == V_354 )
return 0 ;
}
return V_354 ;
}
static int F_214 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_325 * V_326 = & V_2 -> V_327 ;
int V_16 , V_211 , type ;
for ( V_16 = 0 ; V_16 < V_326 -> V_329 ; V_16 ++ ) {
bool V_355 ;
int V_60 ;
V_60 = V_326 -> V_258 [ V_16 ] . V_130 ;
if ( V_60 >= V_2 -> V_151 . V_199 )
continue;
V_355 = F_208 ( V_19 , V_2 -> V_340 [ V_16 ] ) ;
for ( type = 0 ; type < 2 ; type ++ ) {
V_211 = F_210 ( V_19 ,
V_2 -> V_341 [ V_60 ] ,
V_2 -> V_342 [ V_60 ] ,
type ,
F_213 ( V_19 , V_16 , type ) ,
V_355 ) ;
if ( V_211 < 0 )
return V_211 ;
}
}
return 0 ;
}
static int F_215 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_325 * V_326 = & V_2 -> V_327 ;
int V_16 , V_90 , V_53 , V_211 ;
if ( V_2 -> V_331 )
V_53 = 1 ;
else
V_53 = V_2 -> V_322 ;
if ( ! V_2 -> V_362 && V_326 -> V_329 > 1 ) {
struct V_4 * V_12 ;
const char * V_10 ;
V_10 = V_53 > 1 ? L_81 : L_82 ;
V_12 = F_4 ( V_2 , V_10 , & V_363 ) ;
if ( ! V_12 )
return - V_136 ;
V_12 -> V_257 = V_53 ;
}
for ( V_90 = 0 ; V_90 < V_53 ; V_90 ++ ) {
bool V_74 = false ;
bool V_38 = V_2 -> V_38 ;
bool V_355 = false ;
int V_364 , V_365 ;
V_364 = V_365 = 0 ;
for ( V_16 = 0 ; V_16 < V_326 -> V_329 ; V_16 ++ ) {
struct V_6 * V_54 ;
V_54 = F_197 ( V_19 , V_90 , V_16 ) ;
if ( ! V_54 )
continue;
F_207 ( V_19 , V_54 ) ;
if ( ! V_364 )
V_364 = V_54 -> V_62 [ V_108 ] ;
else if ( V_364 != V_54 -> V_62 [ V_108 ] ) {
V_74 = true ;
if ( ! F_46 ( V_19 , V_364 ,
V_54 -> V_62 [ V_108 ] , V_85 ) )
V_38 = true ;
}
if ( ! V_365 )
V_365 = V_54 -> V_62 [ V_107 ] ;
else if ( V_365 != V_54 -> V_62 [ V_107 ] ) {
V_74 = true ;
if ( ! F_46 ( V_19 , V_365 ,
V_54 -> V_62 [ V_107 ] , V_85 ) )
V_38 = true ;
}
if ( F_208 ( V_19 , V_2 -> V_340 [ V_16 ] ) )
V_355 = true ;
}
if ( ! V_74 )
V_211 = F_211 ( V_19 , V_90 , V_364 , V_365 ,
V_355 ) ;
else if ( ! V_38 && ! V_355 )
V_211 = F_212 ( V_19 , V_90 , V_364 , V_365 ) ;
else
V_211 = F_214 ( V_19 ) ;
if ( V_211 < 0 )
return V_211 ;
}
return 0 ;
}
static bool F_216 ( struct V_18 * V_19 , T_1 V_52 ,
int V_63 , int V_60 )
{
unsigned int V_366 ;
if ( ! F_51 ( V_19 , V_52 , V_63 ) ||
F_31 ( V_19 , V_52 , V_63 , V_60 , V_108 ) ||
F_31 ( V_19 , V_52 , V_63 , V_60 , V_109 ) )
return false ;
V_366 = ( F_47 ( V_19 , V_52 , V_63 ) & V_367 )
>> V_368 ;
if ( V_366 < 0x20 )
return false ;
return true ;
}
static unsigned int F_217 ( struct V_18 * V_19 ,
struct V_6 * V_54 )
{
unsigned int V_20 = 0 ;
T_1 V_52 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( V_55 >= V_54 -> V_55 - 1 )
break;
V_52 = V_54 -> V_54 [ V_55 ] ;
if ( V_55 && F_216 ( V_19 , V_52 , V_84 , 0 ) ) {
V_20 = F_32 ( V_52 , 3 , 0 , V_84 ) ;
break;
} else if ( F_216 ( V_19 , V_52 , V_85 ,
V_54 -> V_60 [ V_55 ] ) ) {
V_20 = F_32 ( V_52 , 3 , V_54 -> V_60 [ V_55 ] ,
V_85 ) ;
break;
}
}
return V_20 ;
}
static int F_218 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_151 ;
struct V_325 * V_326 = & V_2 -> V_327 ;
int V_16 ;
if ( ! V_2 -> V_322 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_326 -> V_329 ; V_16 ++ ) {
struct V_6 * V_54 ;
unsigned int V_20 ;
int V_60 ;
char V_369 [ V_135 ] ;
V_60 = V_326 -> V_258 [ V_16 ] . V_130 ;
if ( V_60 >= V_326 -> V_329 )
continue;
if ( V_150 -> V_200 [ V_60 ] . type > V_197 )
continue;
V_54 = F_197 ( V_19 , 0 , V_16 ) ;
if ( ! V_54 )
continue;
V_20 = F_217 ( V_19 , V_54 ) ;
if ( ! V_20 )
continue;
snprintf ( V_369 , sizeof( V_369 ) ,
L_83 , V_2 -> V_341 [ V_60 ] ) ;
if ( ! F_82 ( V_2 , V_137 , V_369 ,
V_2 -> V_342 [ V_60 ] , V_20 ) )
return - V_136 ;
V_54 -> V_62 [ V_109 ] = V_20 ;
}
return 0 ;
}
static void F_219 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_54 ;
int V_16 , V_53 ;
T_1 V_370 , V_48 ;
V_53 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_151 . V_371 ; V_16 ++ ) {
V_48 = V_2 -> V_151 . V_372 [ V_16 ] ;
V_370 = F_44 ( V_19 , V_48 , true ) ;
if ( ! V_370 )
continue;
V_54 = F_41 ( V_19 , V_370 , V_48 , 0 ) ;
if ( ! V_54 )
continue;
F_33 ( V_19 , L_84 , V_54 ) ;
V_54 -> V_93 = true ;
V_54 -> V_96 = true ;
V_2 -> V_213 [ V_16 ] = F_25 ( V_19 , V_54 ) ;
F_17 ( V_19 , V_48 , V_238 , false ) ;
if ( ! V_53 ) {
V_2 -> V_159 . V_373 = V_370 ;
V_2 -> V_374 = V_2 -> V_151 . V_374 [ 0 ] ;
} else {
V_2 -> V_159 . V_375 = V_2 -> V_375 ;
if ( V_53 >= F_102 ( V_2 -> V_375 ) - 1 )
break;
V_2 -> V_375 [ V_53 - 1 ] = V_370 ;
}
V_53 ++ ;
}
if ( V_2 -> V_151 . V_376 ) {
V_48 = V_2 -> V_151 . V_376 ;
F_125 (dig_nid, codec) {
unsigned int V_104 = F_39 ( V_19 , V_370 ) ;
if ( F_38 ( V_104 ) != V_71 )
continue;
if ( ! ( V_104 & V_80 ) )
continue;
V_54 = F_41 ( V_19 , V_48 , V_370 , 0 ) ;
if ( V_54 ) {
F_33 ( V_19 , L_85 , V_54 ) ;
V_54 -> V_93 = true ;
V_54 -> V_96 = true ;
V_2 -> V_377 = V_370 ;
V_2 -> V_216 = F_25 ( V_19 , V_54 ) ;
F_17 ( V_19 , V_48 , V_278 , false ) ;
break;
}
}
}
}
static int F_203 ( struct V_18 * V_19 , unsigned int V_346 ,
unsigned int V_60 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_325 * V_326 ;
struct V_6 * V_378 , * V_54 ;
V_326 = & V_2 -> V_327 ;
if ( ! V_326 -> V_329 )
return 0 ;
if ( V_60 >= V_326 -> V_329 )
V_60 = V_326 -> V_329 - 1 ;
if ( V_2 -> V_276 [ V_346 ] == V_60 )
return 0 ;
V_378 = F_197 ( V_19 , V_346 , V_2 -> V_276 [ V_346 ] ) ;
if ( ! V_378 )
return 0 ;
if ( V_378 -> V_93 )
F_76 ( V_19 , V_378 , false , false ) ;
V_2 -> V_276 [ V_346 ] = V_60 ;
if ( V_2 -> V_44 )
F_157 ( V_19 , V_346 , false ) ;
if ( V_2 -> V_331 )
F_220 ( V_19 , V_60 ) ;
V_54 = F_197 ( V_19 , V_346 , V_60 ) ;
if ( ! V_54 )
return 0 ;
if ( V_54 -> V_93 )
return 0 ;
F_76 ( V_19 , V_54 , true , false ) ;
if ( V_2 -> V_351 )
V_2 -> V_351 ( V_19 , NULL , NULL ) ;
F_78 ( V_19 , V_378 ) ;
return 1 ;
}
static T_1 F_221 ( struct V_18 * V_19 , T_1 V_52 ,
int V_379 , int V_380 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_381 , V_114 = 0 ;
struct V_6 * V_54 ;
int V_90 ;
for ( V_90 = 0 ; V_90 < V_2 -> V_5 . V_17 ; V_90 ++ ) {
V_54 = F_24 ( & V_2 -> V_5 , V_90 ) ;
if ( ! V_54 -> V_55 )
continue;
if ( V_54 -> V_54 [ 0 ] == V_52 ||
V_54 -> V_54 [ V_54 -> V_55 - 1 ] == V_52 ) {
bool V_382 = V_54 -> V_95 ;
bool V_383 = V_54 -> V_94 ;
if ( V_379 >= 0 )
V_54 -> V_95 = V_379 ;
if ( V_380 >= 0 )
V_54 -> V_94 = V_380 ;
if ( ( ! V_54 -> V_96 && V_54 -> V_95 != V_382 )
|| V_54 -> V_94 != V_383 ) {
V_381 = F_70 ( V_19 , V_54 , true ) ;
if ( V_381 )
V_114 = V_381 ;
}
}
}
return V_114 ;
}
static bool F_222 ( struct V_18 * V_19 , T_1 V_48 )
{
if ( ! F_223 ( V_19 , V_48 ) )
return true ;
return F_224 ( V_19 , V_48 ) != V_384 ;
}
static T_1 F_225 ( struct V_18 * V_19 , T_1 V_48 ,
int V_116 )
{
bool V_385 ;
if ( ! V_19 -> V_30 )
return 0 ;
V_385 = F_222 ( V_19 , V_48 ) ;
if ( V_116 >= 0 && V_385 != V_116 )
return 0 ;
return F_221 ( V_19 , V_48 , V_385 , - 1 ) ;
}
static void F_226 ( struct V_18 * V_19 ,
struct V_386 * V_387 ,
bool V_385 )
{
if ( V_387 && V_387 -> V_52 )
F_74 ( V_19 ,
F_225 ( V_19 , V_387 -> V_52 , V_385 ) ) ;
}
static void F_227 ( struct V_18 * V_19 ,
struct V_386 * V_387 )
{
F_226 ( V_19 , V_387 , true ) ;
}
static void F_228 ( struct V_18 * V_19 ,
struct V_386 * V_387 )
{
F_226 ( V_19 , V_387 , false ) ;
}
static void F_229 ( struct V_18 * V_19 , int V_50 ,
const T_1 * V_51 , bool V_385 )
{
int V_16 ;
T_5 V_388 =
V_385 ? F_227 : F_228 ;
for ( V_16 = 0 ; V_16 < V_50 && V_51 [ V_16 ] ; V_16 ++ ) {
if ( F_223 ( V_19 , V_51 [ V_16 ] ) )
F_230 ( V_19 , V_51 [ V_16 ] , V_388 ) ;
else
F_221 ( V_19 , V_51 [ V_16 ] , true , - 1 ) ;
}
}
static void F_231 ( struct V_18 * V_19 , bool V_385 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_151 ;
int V_16 ;
if ( ! V_19 -> V_30 )
return;
F_229 ( V_19 , V_150 -> V_152 , V_150 -> V_218 , V_385 ) ;
if ( V_150 -> V_164 != V_167 )
F_229 ( V_19 , V_150 -> V_155 , V_150 -> V_219 , V_385 ) ;
if ( V_150 -> V_164 != V_165 )
F_229 ( V_19 , V_150 -> V_156 , V_150 -> V_220 , V_385 ) ;
for ( V_16 = 0 ; V_16 < V_150 -> V_199 ; V_16 ++ )
F_229 ( V_19 , 1 , & V_150 -> V_200 [ V_16 ] . V_48 , V_385 ) ;
}
static void F_232 ( struct V_18 * V_19 , int V_50 ,
const T_1 * V_51 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_50 && V_51 [ V_16 ] ; V_16 ++ )
if ( F_223 ( V_19 , V_51 [ V_16 ] ) )
F_225 ( V_19 , V_51 [ V_16 ] , - 1 ) ;
}
static void F_233 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_151 ;
int V_16 ;
if ( ! V_19 -> V_30 )
return;
F_232 ( V_19 , V_150 -> V_152 , V_150 -> V_218 ) ;
if ( V_150 -> V_164 != V_167 )
F_232 ( V_19 , V_150 -> V_155 , V_150 -> V_219 ) ;
if ( V_150 -> V_164 != V_165 )
F_232 ( V_19 , V_150 -> V_156 , V_150 -> V_220 ) ;
for ( V_16 = 0 ; V_16 < V_150 -> V_199 ; V_16 ++ )
F_232 ( V_19 , 1 , & V_150 -> V_200 [ V_16 ] . V_48 ) ;
}
static int F_234 ( struct V_18 * V_19 , T_1 V_52 ,
int V_50 , const T_1 * V_51 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_54 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_50 ; V_16 ++ ) {
if ( ! V_51 [ V_16 ] )
break;
if ( F_23 ( V_19 , V_52 , V_51 [ V_16 ] , 0 ) )
continue;
V_54 = F_5 ( & V_2 -> V_5 ) ;
if ( ! V_54 )
return - V_136 ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_55 = 2 ;
V_54 -> V_54 [ 0 ] = V_52 ;
V_54 -> V_54 [ 1 ] = V_51 [ V_16 ] ;
V_54 -> V_93 = true ;
}
return 0 ;
}
static int F_235 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_151 ;
T_1 V_52 = V_2 -> V_389 ;
int V_211 ;
if ( ! V_19 -> V_30 || ! V_52 )
return 0 ;
V_211 = F_234 ( V_19 , V_52 , V_150 -> V_152 , V_150 -> V_218 ) ;
if ( V_211 < 0 )
return V_211 ;
if ( V_150 -> V_164 != V_167 ) {
V_211 = F_234 ( V_19 , V_52 , V_150 -> V_155 , V_150 -> V_219 ) ;
if ( V_211 < 0 )
return V_211 ;
}
if ( V_150 -> V_164 != V_165 ) {
V_211 = F_234 ( V_19 , V_52 , V_150 -> V_156 ,
V_150 -> V_220 ) ;
if ( V_211 < 0 )
return V_211 ;
}
return 0 ;
}
static void F_236 ( struct V_390 * V_391 , bool V_385 )
{
F_221 ( V_391 -> V_19 , V_391 -> V_52 , - 1 , V_385 ) ;
}
int F_237 ( struct V_18 * V_19 , T_1 V_48 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_54 ;
V_54 = F_5 ( & V_2 -> V_5 ) ;
if ( ! V_54 )
return - V_136 ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_55 = 1 ;
V_54 -> V_54 [ 0 ] = V_48 ;
V_54 -> V_93 = true ;
V_54 -> V_96 = true ;
V_54 -> V_94 = true ;
return 0 ;
}
static bool F_238 ( struct V_18 * V_19 , int V_50 , T_1 * V_51 )
{
int V_16 ;
bool V_392 = false ;
for ( V_16 = 0 ; V_16 < V_50 ; V_16 ++ ) {
T_1 V_52 = V_51 [ V_16 ] ;
if ( ! V_52 )
break;
if ( F_16 ( V_19 , V_52 ) & V_393 )
continue;
if ( F_224 ( V_19 , V_52 ) == V_394 )
V_392 = true ;
}
return V_392 ;
}
static void F_239 ( struct V_18 * V_19 , int V_50 , T_1 * V_51 ,
int * V_5 , bool V_395 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_50 ; V_16 ++ ) {
T_1 V_52 = V_51 [ V_16 ] ;
unsigned int V_20 , V_307 ;
if ( ! V_52 )
break;
V_307 = F_16 ( V_19 , V_52 ) ;
if ( V_307 & V_278 )
continue;
if ( V_2 -> V_34 ) {
struct V_6 * V_54 ;
T_1 V_396 ;
V_54 = F_26 ( V_19 , V_5 [ V_16 ] ) ;
if ( ! V_54 )
continue;
V_396 = F_83 ( V_54 -> V_62 [ V_107 ] ) ;
if ( ! V_396 )
continue;
if ( V_395 )
V_2 -> V_145 |= ( 1ULL << V_396 ) ;
else
V_2 -> V_145 &= ~ ( 1ULL << V_396 ) ;
continue;
} else {
if ( V_2 -> V_397 )
V_20 = V_307 & ~ V_237 ;
else
V_20 = 0 ;
if ( ! V_395 )
V_20 |= V_307 ;
F_15 ( V_19 , V_52 , V_20 ) ;
}
F_79 ( V_19 , V_52 , ! V_395 ) ;
if ( V_19 -> V_30 ) {
bool V_385 = ! V_395 ;
if ( V_385 )
V_385 = F_222 ( V_19 , V_52 ) ;
F_221 ( V_19 , V_52 , V_385 , - 1 ) ;
}
}
}
void F_240 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int * V_5 ;
int V_385 ;
if ( V_2 -> V_151 . V_164 == V_167 )
V_5 = V_2 -> V_204 ;
else
V_5 = V_2 -> V_166 ;
F_239 ( V_19 , F_102 ( V_2 -> V_151 . V_219 ) ,
V_2 -> V_151 . V_219 , V_5 , V_2 -> V_398 ) ;
if ( ! V_2 -> V_399 )
V_385 = 0 ;
else
V_385 = V_2 -> V_400 | V_2 -> V_401 ;
V_385 |= V_2 -> V_398 ;
V_2 -> V_402 = V_385 ;
if ( V_2 -> V_151 . V_164 == V_165 )
V_5 = V_2 -> V_204 ;
else
V_5 = V_2 -> V_168 ;
F_239 ( V_19 , F_102 ( V_2 -> V_151 . V_220 ) ,
V_2 -> V_151 . V_220 , V_5 , V_385 ) ;
if ( V_2 -> V_151 . V_218 [ 0 ] == V_2 -> V_151 . V_219 [ 0 ] ||
V_2 -> V_151 . V_218 [ 0 ] == V_2 -> V_151 . V_220 [ 0 ] )
return;
if ( ! V_2 -> V_403 )
V_385 = 0 ;
else
V_385 = V_2 -> V_400 ;
V_385 |= V_2 -> V_398 ;
V_2 -> V_404 = V_385 ;
V_5 = V_2 -> V_204 ;
F_239 ( V_19 , F_102 ( V_2 -> V_151 . V_218 ) ,
V_2 -> V_151 . V_218 , V_5 , V_385 ) ;
}
static void F_241 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_405 )
V_2 -> V_405 ( V_19 ) ;
else
F_240 ( V_19 ) ;
if ( V_2 -> V_34 && ! V_19 -> V_406 -> V_407 )
F_242 ( V_2 -> V_157 . V_408 , false ) ;
}
void F_243 ( struct V_18 * V_19 ,
struct V_386 * V_387 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 * V_51 = V_2 -> V_151 . V_219 ;
int V_50 = F_102 ( V_2 -> V_151 . V_219 ) ;
if ( V_2 -> V_245 ) {
V_51 ++ ;
V_50 -- ;
}
V_2 -> V_400 = F_238 ( V_19 , V_50 , V_51 ) ;
if ( ! V_2 -> V_409 || ( ! V_2 -> V_399 && ! V_2 -> V_403 ) )
return;
F_241 ( V_19 ) ;
}
void F_244 ( struct V_18 * V_19 ,
struct V_386 * V_387 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_151 . V_164 == V_165 )
return;
if ( V_2 -> V_151 . V_218 [ 0 ] == V_2 -> V_151 . V_219 [ 0 ] )
return;
V_2 -> V_401 =
F_238 ( V_19 , F_102 ( V_2 -> V_151 . V_218 ) ,
V_2 -> V_151 . V_218 ) ;
if ( ! V_2 -> V_399 || ! V_2 -> V_410 )
return;
F_241 ( V_19 ) ;
}
void F_245 ( struct V_18 * V_19 ,
struct V_386 * V_387 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
if ( ! V_2 -> V_362 )
return;
for ( V_16 = V_2 -> V_411 - 1 ; V_16 > 0 ; V_16 -- ) {
T_1 V_48 = V_2 -> V_412 [ V_16 ] . V_48 ;
if ( F_16 ( V_19 , V_48 ) & V_413 )
continue;
if ( F_224 ( V_19 , V_48 ) == V_394 ) {
F_203 ( V_19 , 0 , V_2 -> V_412 [ V_16 ] . V_60 ) ;
return;
}
}
F_203 ( V_19 , 0 , V_2 -> V_412 [ 0 ] . V_60 ) ;
}
static void F_141 ( struct V_18 * V_19 ,
struct V_386 * V_387 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_414 )
V_2 -> V_414 ( V_19 , V_387 ) ;
else
F_243 ( V_19 , V_387 ) ;
}
static void F_246 ( struct V_18 * V_19 ,
struct V_386 * V_387 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_415 )
V_2 -> V_415 ( V_19 , V_387 ) ;
else
F_244 ( V_19 , V_387 ) ;
}
static void F_247 ( struct V_18 * V_19 ,
struct V_386 * V_387 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_416 )
V_2 -> V_416 ( V_19 , V_387 ) ;
else
F_245 ( V_19 , V_387 ) ;
}
static void F_149 ( struct V_18 * V_19 )
{
F_141 ( V_19 , NULL ) ;
F_246 ( V_19 , NULL ) ;
F_247 ( V_19 , NULL ) ;
}
static int F_248 ( struct V_140 * V_141 ,
struct V_241 * V_242 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_417 [] = {
L_86 , L_87 , L_88
} ;
if ( V_2 -> V_418 && V_2 -> V_419 )
return F_163 ( V_141 , V_242 , 3 , V_417 ) ;
return F_136 ( V_141 , V_242 ) ;
}
static int F_249 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = 0 ;
if ( V_2 -> V_399 )
V_20 ++ ;
if ( V_2 -> V_403 )
V_20 ++ ;
V_143 -> V_146 . V_243 . V_244 [ 0 ] = V_20 ;
return 0 ;
}
static int F_250 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
switch ( V_143 -> V_146 . V_243 . V_244 [ 0 ] ) {
case 0 :
if ( ! V_2 -> V_399 && ! V_2 -> V_403 )
return 0 ;
V_2 -> V_399 = 0 ;
V_2 -> V_403 = 0 ;
break;
case 1 :
if ( V_2 -> V_418 ) {
if ( ! V_2 -> V_403 && V_2 -> V_399 )
return 0 ;
V_2 -> V_399 = 1 ;
V_2 -> V_403 = 0 ;
} else if ( V_2 -> V_419 ) {
if ( V_2 -> V_403 )
return 0 ;
V_2 -> V_403 = 1 ;
} else
return - V_260 ;
break;
case 2 :
if ( ! V_2 -> V_419 || ! V_2 -> V_418 )
return - V_260 ;
if ( V_2 -> V_399 && V_2 -> V_403 )
return 0 ;
V_2 -> V_399 = 1 ;
V_2 -> V_403 = 1 ;
break;
default:
return - V_260 ;
}
F_241 ( V_19 ) ;
return 1 ;
}
static int F_251 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! F_4 ( V_2 , NULL , & V_420 ) )
return - V_136 ;
return 0 ;
}
static int F_252 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_151 ;
int V_392 = 0 ;
int V_16 , V_211 ;
if ( V_2 -> V_31 )
return 0 ;
if ( V_150 -> V_219 [ 0 ] )
V_392 ++ ;
if ( V_150 -> V_218 [ 0 ] )
V_392 ++ ;
if ( V_150 -> V_220 [ 0 ] )
V_392 ++ ;
if ( V_392 < 2 )
return 0 ;
if ( ! V_150 -> V_220 [ 0 ] &&
V_150 -> V_164 == V_165 ) {
memcpy ( V_150 -> V_220 , V_150 -> V_218 ,
sizeof( V_150 -> V_220 ) ) ;
V_150 -> V_156 = V_150 -> V_152 ;
}
if ( ! V_150 -> V_219 [ 0 ] &&
V_150 -> V_164 == V_167 ) {
memcpy ( V_150 -> V_219 , V_150 -> V_218 ,
sizeof( V_150 -> V_219 ) ) ;
V_150 -> V_155 = V_150 -> V_152 ;
}
for ( V_16 = 0 ; V_16 < V_150 -> V_155 ; V_16 ++ ) {
T_1 V_52 = V_150 -> V_219 [ V_16 ] ;
if ( ! F_223 ( V_19 , V_52 ) )
continue;
F_35 ( V_19 , L_89 , V_52 ) ;
F_230 ( V_19 , V_52 ,
F_141 ) ;
V_2 -> V_409 = 1 ;
}
if ( V_150 -> V_164 == V_169 && V_150 -> V_152 ) {
if ( V_150 -> V_156 )
for ( V_16 = 0 ; V_16 < V_150 -> V_152 ; V_16 ++ ) {
T_1 V_52 = V_150 -> V_218 [ V_16 ] ;
if ( ! F_223 ( V_19 , V_52 ) )
continue;
F_35 ( V_19 , L_90 , V_52 ) ;
F_230 ( V_19 , V_52 ,
F_246 ) ;
V_2 -> V_410 = 1 ;
}
V_2 -> V_419 = V_2 -> V_409 ;
}
V_2 -> V_418 = V_150 -> V_156 &&
( V_2 -> V_409 || V_2 -> V_410 ) ;
V_2 -> V_403 = V_2 -> V_419 ;
V_2 -> V_399 = V_2 -> V_418 ;
if ( V_2 -> V_418 || V_2 -> V_419 ) {
V_211 = F_251 ( V_19 ) ;
if ( V_211 < 0 )
return V_211 ;
}
return 0 ;
}
static bool F_253 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_325 * V_326 ;
int V_16 ;
V_326 = & V_2 -> V_327 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_411 ; V_16 ++ ) {
V_2 -> V_412 [ V_16 ] . V_60 =
F_21 ( V_2 -> V_412 [ V_16 ] . V_48 ,
V_2 -> V_340 , V_326 -> V_329 ) ;
if ( V_2 -> V_412 [ V_16 ] . V_60 < 0 )
return false ;
}
for ( V_16 = 1 ; V_16 < V_2 -> V_411 ; V_16 ++ )
F_230 ( V_19 ,
V_2 -> V_412 [ V_16 ] . V_48 ,
F_247 ) ;
return true ;
}
static int F_254 ( const void * V_421 , const void * V_422 )
{
const struct V_423 * V_424 = V_421 ;
const struct V_423 * V_425 = V_422 ;
return ( int ) ( V_424 -> V_426 - V_425 -> V_426 ) ;
}
static int F_255 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_151 ;
unsigned int V_427 ;
int V_16 , V_50 ;
if ( V_2 -> V_32 )
return 0 ;
V_427 = 0 ;
V_50 = 0 ;
for ( V_16 = 0 ; V_16 < V_150 -> V_199 ; V_16 ++ ) {
T_1 V_52 = V_150 -> V_200 [ V_16 ] . V_48 ;
unsigned int V_426 ;
V_426 = F_110 ( V_19 , V_52 ) ;
V_426 = F_161 ( V_426 ) ;
if ( V_427 & ( 1 << V_426 ) )
return 0 ;
switch ( V_426 ) {
case V_284 :
if ( V_150 -> V_200 [ V_16 ] . type != V_198 )
return 0 ;
break;
case V_428 :
return 0 ;
default:
if ( V_150 -> V_200 [ V_16 ] . type > V_197 )
return 0 ;
if ( ! V_2 -> V_33 &&
V_150 -> V_200 [ V_16 ] . type != V_198 )
return 0 ;
if ( ! F_223 ( V_19 , V_52 ) )
return 0 ;
break;
}
if ( V_50 >= V_429 )
return 0 ;
V_427 |= ( 1 << V_426 ) ;
V_2 -> V_412 [ V_50 ] . V_48 = V_52 ;
V_2 -> V_412 [ V_50 ] . V_426 = V_426 ;
V_50 ++ ;
}
if ( V_50 < 2 )
return 0 ;
V_2 -> V_411 = V_50 ;
F_256 ( V_2 -> V_412 , V_50 , sizeof( V_2 -> V_412 [ 0 ] ) ,
F_254 , NULL ) ;
if ( ! F_253 ( V_19 ) )
return 0 ;
V_2 -> V_362 = 1 ;
V_2 -> V_322 = 1 ;
V_2 -> V_276 [ 0 ] = V_2 -> V_412 [ 0 ] . V_60 ;
F_35 ( V_19 , L_91 ,
V_2 -> V_412 [ 0 ] . V_48 ,
V_2 -> V_412 [ 1 ] . V_48 ,
V_2 -> V_412 [ 2 ] . V_48 ) ;
return 0 ;
}
unsigned int F_257 ( struct V_18 * V_19 ,
T_1 V_52 ,
unsigned int V_430 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_43 && ! V_19 -> V_30 )
return V_430 ;
if ( V_430 != V_118 || V_52 == V_19 -> V_91 . V_92 )
return V_430 ;
if ( F_38 ( F_39 ( V_19 , V_52 ) ) >= V_431 )
return V_430 ;
if ( F_71 ( V_19 , V_52 ) )
return V_430 ;
return V_119 ;
}
static void F_258 ( struct V_18 * V_19 , T_1 V_309 )
{
int V_16 , V_53 ;
const T_1 * V_67 ;
bool V_432 ;
V_53 = F_37 ( V_19 , V_309 , & V_67 ) ;
V_432 = F_49 ( V_19 , V_309 , V_85 ) ;
for ( V_16 = 0 ; V_16 < V_53 ; V_16 ++ ) {
if ( V_432 )
F_62 ( V_19 , V_309 , V_85 , V_16 ,
0xff , V_103 ) ;
else if ( F_51 ( V_19 , V_67 [ V_16 ] , V_84 ) )
F_62 ( V_19 , V_67 [ V_16 ] , V_84 , 0 ,
0xff , V_103 ) ;
}
}
void F_259 ( struct V_18 * V_19 , T_1 V_52 , bool V_385 )
{
if ( V_19 -> V_30 )
F_221 ( V_19 , V_52 , - 1 , V_385 ) ;
}
int F_260 ( struct V_18 * V_19 ,
struct V_149 * V_150 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_211 ;
F_11 ( V_19 ) ;
if ( V_2 -> V_47 && ! V_2 -> V_112 )
V_2 -> V_112 = V_2 -> V_47 ;
if ( V_150 != & V_2 -> V_151 ) {
V_2 -> V_151 = * V_150 ;
V_150 = & V_2 -> V_151 ;
}
if ( ! V_2 -> V_221 )
V_2 -> V_221 = & V_433 ;
if ( ! V_2 -> V_222 )
V_2 -> V_222 = & V_434 ;
F_124 ( V_19 ) ;
if ( ! V_150 -> V_152 ) {
if ( V_150 -> V_371 || V_150 -> V_376 ) {
V_2 -> V_159 . V_262 = 2 ;
V_2 -> V_435 = 1 ;
goto V_436;
}
if ( ! V_150 -> V_199 && ! V_150 -> V_376 )
return 0 ;
}
if ( ! V_2 -> V_36 &&
V_150 -> V_164 == V_165 &&
V_150 -> V_152 <= V_150 -> V_155 ) {
V_150 -> V_156 = V_150 -> V_152 ;
memcpy ( V_150 -> V_220 , V_150 -> V_218 ,
sizeof( V_150 -> V_220 ) ) ;
V_150 -> V_152 = V_150 -> V_155 ;
memcpy ( V_150 -> V_218 , V_150 -> V_219 , sizeof( V_150 -> V_219 ) ) ;
V_150 -> V_155 = 0 ;
memset ( V_150 -> V_219 , 0 , sizeof( V_150 -> V_219 ) ) ;
V_150 -> V_164 = V_167 ;
}
V_211 = F_127 ( V_19 ) ;
if ( V_211 < 0 )
return V_211 ;
V_211 = F_152 ( V_19 ) ;
if ( V_211 < 0 )
return V_211 ;
V_211 = F_130 ( V_19 , V_150 ) ;
if ( V_211 < 0 )
return V_211 ;
V_211 = F_133 ( V_19 ) ;
if ( V_211 < 0 )
return V_211 ;
V_211 = F_134 ( V_19 ) ;
if ( V_211 < 0 )
return V_211 ;
V_211 = F_143 ( V_19 ) ;
if ( V_211 < 0 )
return V_211 ;
V_211 = F_156 ( V_19 ) ;
if ( V_211 < 0 )
return V_211 ;
V_211 = F_160 ( V_19 ) ;
if ( V_211 < 0 )
return V_211 ;
V_211 = F_196 ( V_19 ) ;
if ( V_211 < 0 )
return V_211 ;
F_231 ( V_19 , false ) ;
V_2 -> V_263 = V_2 -> V_223 ;
if ( V_150 -> V_164 != V_165 )
V_2 -> V_263 = F_151 ( V_2 -> V_263 ,
V_150 -> V_156 * 2 ) ;
if ( V_150 -> V_164 != V_167 )
V_2 -> V_263 = F_151 ( V_2 -> V_263 ,
V_150 -> V_155 * 2 ) ;
V_2 -> V_159 . V_262 = F_151 ( V_2 -> V_223 ,
V_2 -> V_263 ) ;
V_211 = F_252 ( V_19 ) ;
if ( V_211 < 0 )
return V_211 ;
V_211 = F_191 ( V_19 ) ;
if ( V_211 < 0 )
return V_211 ;
V_211 = F_255 ( V_19 ) ;
if ( V_211 < 0 )
return V_211 ;
if ( ! V_2 -> V_362 && V_2 -> V_47 &&
V_2 -> V_41 == V_437 &&
V_2 -> V_327 . V_329 > 1 ) {
V_211 = F_192 ( V_19 , V_2 -> V_47 ,
V_345 , V_2 -> V_323 ,
L_74 , 0 ) ;
if ( V_211 < 0 )
return V_211 ;
}
V_211 = F_215 ( V_19 ) ;
if ( V_211 < 0 )
return V_211 ;
V_211 = F_218 ( V_19 ) ;
if ( V_211 < 0 )
return V_211 ;
if ( V_2 -> V_275 &&
( V_2 -> V_362 || V_2 -> V_327 . V_329 == 1 ||
V_2 -> V_42 ) ) {
V_211 = F_185 ( V_19 , V_2 -> V_275 ) ;
if ( V_211 < 0 )
return V_211 ;
}
if ( V_2 -> V_42 ) {
if ( V_150 -> V_164 != V_165 ) {
V_211 = F_171 ( V_19 , V_150 -> V_152 ,
V_150 -> V_218 ) ;
if ( V_211 < 0 )
return V_211 ;
}
if ( V_150 -> V_164 != V_167 ) {
V_211 = F_171 ( V_19 , V_150 -> V_155 ,
V_150 -> V_219 ) ;
if ( V_211 < 0 )
return V_211 ;
}
}
F_231 ( V_19 , true ) ;
if ( V_2 -> V_47 )
F_258 ( V_19 , V_2 -> V_47 ) ;
V_436:
F_219 ( V_19 ) ;
if ( V_2 -> V_43 || V_19 -> V_30 ) {
if ( ! V_19 -> V_438 )
V_19 -> V_438 = F_257 ;
if ( ! V_19 -> V_439 . V_440 )
V_19 -> V_439 . V_440 = F_259 ;
}
if ( ! V_2 -> V_435 && V_2 -> V_389 ) {
V_211 = F_261 ( V_19 , V_2 -> V_389 ) ;
if ( V_211 < 0 )
return V_211 ;
if ( V_19 -> V_391 && V_19 -> V_30 ) {
V_211 = F_235 ( V_19 ) ;
if ( V_211 < 0 )
return V_211 ;
V_19 -> V_391 -> V_441 = F_236 ;
}
}
return 1 ;
}
int F_262 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_211 ;
if ( V_2 -> V_3 . V_17 ) {
V_211 = F_263 ( V_19 , V_2 -> V_3 . V_14 ) ;
if ( V_211 < 0 )
return V_211 ;
}
if ( V_2 -> V_159 . V_373 ) {
V_211 = F_264 ( V_19 ,
V_2 -> V_159 . V_373 ,
V_2 -> V_159 . V_373 ,
V_2 -> V_442 [ 1 ] -> V_443 ) ;
if ( V_211 < 0 )
return V_211 ;
if ( ! V_2 -> V_435 ) {
V_211 = F_265 ( V_19 ,
& V_2 -> V_159 ) ;
if ( V_211 < 0 )
return V_211 ;
V_2 -> V_159 . V_444 = 1 ;
}
}
if ( V_2 -> V_377 ) {
V_211 = F_266 ( V_19 , V_2 -> V_377 ) ;
if ( V_211 < 0 )
return V_211 ;
}
if ( ! V_2 -> V_435 && ! V_2 -> V_46 &&
! F_267 ( V_19 , L_92 ) ) {
V_211 = F_268 ( V_19 , L_92 ,
V_2 -> V_234 , V_445 ,
L_93 ) ;
if ( V_211 < 0 )
return V_211 ;
}
if ( ! V_2 -> V_435 && ! V_2 -> V_46 &&
! F_267 ( V_19 , L_94 ) ) {
V_211 = F_269 ( V_19 , L_94 ,
NULL , V_445 ,
L_95 ,
true , & V_2 -> V_157 . V_408 ) ;
if ( V_211 < 0 )
return V_211 ;
if ( V_2 -> V_157 . V_158 ) {
F_270 ( V_19 , & V_2 -> V_157 ,
V_2 -> V_446 ) ;
F_271 ( & V_2 -> V_157 ) ;
}
}
F_7 ( V_2 ) ;
V_211 = F_272 ( V_19 , & V_2 -> V_151 ) ;
if ( V_211 < 0 )
return V_211 ;
return 0 ;
}
static void F_273 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
struct V_449 * V_450 ,
int V_451 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_452 )
V_2 -> V_452 ( V_448 , V_19 , V_450 , V_451 ) ;
}
static void F_274 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
struct V_449 * V_450 ,
int V_451 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_453 )
V_2 -> V_453 ( V_448 , V_19 , V_450 , V_451 ) ;
}
static int F_275 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
struct V_449 * V_450 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_211 ;
F_139 ( & V_2 -> V_9 ) ;
V_211 = F_276 ( V_19 ,
& V_2 -> V_159 , V_450 ,
V_448 ) ;
if ( ! V_211 ) {
V_2 -> V_248 |= 1 << V_454 ;
F_273 ( V_448 , V_19 , V_450 ,
V_455 ) ;
}
F_142 ( & V_2 -> V_9 ) ;
return V_211 ;
}
static int F_277 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
unsigned int V_456 ,
unsigned int V_457 ,
struct V_449 * V_450 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_211 ;
V_211 = F_278 ( V_19 , & V_2 -> V_159 ,
V_456 , V_457 , V_450 ) ;
if ( ! V_211 )
F_273 ( V_448 , V_19 , V_450 ,
V_458 ) ;
return V_211 ;
}
static int F_279 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
struct V_449 * V_450 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_211 ;
V_211 = F_280 ( V_19 , & V_2 -> V_159 ) ;
if ( ! V_211 )
F_273 ( V_448 , V_19 , V_450 ,
V_459 ) ;
return V_211 ;
}
static int F_281 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
struct V_449 * V_450 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_139 ( & V_2 -> V_9 ) ;
V_2 -> V_248 &= ~ ( 1 << V_454 ) ;
F_273 ( V_448 , V_19 , V_450 ,
V_460 ) ;
F_142 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_282 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
struct V_449 * V_450 )
{
F_274 ( V_448 , V_19 , V_450 , V_455 ) ;
return 0 ;
}
static int F_283 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
unsigned int V_456 ,
unsigned int V_457 ,
struct V_449 * V_450 )
{
F_284 ( V_19 , V_448 -> V_52 , V_456 , 0 , V_457 ) ;
F_274 ( V_448 , V_19 , V_450 ,
V_458 ) ;
return 0 ;
}
static int F_285 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
struct V_449 * V_450 )
{
F_286 ( V_19 , V_448 -> V_52 ) ;
F_274 ( V_448 , V_19 , V_450 ,
V_459 ) ;
return 0 ;
}
static int F_287 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
struct V_449 * V_450 )
{
F_274 ( V_448 , V_19 , V_450 , V_460 ) ;
return 0 ;
}
static int F_288 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
struct V_449 * V_450 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_211 = 0 ;
F_139 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_40 && ! V_2 -> V_245 )
V_211 = - V_249 ;
else
V_2 -> V_248 |= 1 << V_461 ;
F_273 ( V_448 , V_19 , V_450 ,
V_455 ) ;
F_142 ( & V_2 -> V_9 ) ;
return V_211 ;
}
static int F_289 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
struct V_449 * V_450 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_139 ( & V_2 -> V_9 ) ;
V_2 -> V_248 &= ~ ( 1 << V_461 ) ;
F_273 ( V_448 , V_19 , V_450 ,
V_460 ) ;
F_142 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_290 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
unsigned int V_456 ,
unsigned int V_457 ,
struct V_449 * V_450 )
{
F_284 ( V_19 , V_448 -> V_52 , V_456 , 0 , V_457 ) ;
F_273 ( V_448 , V_19 , V_450 ,
V_458 ) ;
return 0 ;
}
static int F_291 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
struct V_449 * V_450 )
{
F_286 ( V_19 , V_448 -> V_52 ) ;
F_273 ( V_448 , V_19 , V_450 ,
V_459 ) ;
return 0 ;
}
static int F_292 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
struct V_449 * V_450 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_293 ( V_19 , & V_2 -> V_159 ) ;
}
static int F_294 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
unsigned int V_456 ,
unsigned int V_457 ,
struct V_449 * V_450 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_295 ( V_19 , & V_2 -> V_159 ,
V_456 , V_457 , V_450 ) ;
}
static int F_296 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
struct V_449 * V_450 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_297 ( V_19 , & V_2 -> V_159 ) ;
}
static int F_298 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
struct V_449 * V_450 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_299 ( V_19 , & V_2 -> V_159 ) ;
}
static int F_300 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
unsigned int V_456 ,
unsigned int V_457 ,
struct V_449 * V_450 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_284 ( V_19 , V_2 -> V_320 [ V_450 -> V_462 + 1 ] ,
V_456 , 0 , V_457 ) ;
F_274 ( V_448 , V_19 , V_450 ,
V_458 ) ;
return 0 ;
}
static int F_301 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
struct V_449 * V_450 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_286 ( V_19 ,
V_2 -> V_320 [ V_450 -> V_462 + 1 ] ) ;
F_274 ( V_448 , V_19 , V_450 ,
V_459 ) ;
return 0 ;
}
static bool F_220 ( struct V_18 * V_19 , int V_463 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_464 = V_2 -> V_320 [ V_2 -> V_330 [ V_463 ] ] ;
if ( V_2 -> V_465 && V_2 -> V_465 != V_464 ) {
F_302 ( V_19 , V_2 -> V_465 , 1 ) ;
V_2 -> V_465 = V_464 ;
F_284 ( V_19 , V_464 ,
V_2 -> V_466 , 0 ,
V_2 -> V_467 ) ;
return true ;
}
return false ;
}
static int F_303 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
unsigned int V_456 ,
unsigned int V_457 ,
struct V_449 * V_450 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
V_2 -> V_465 = V_2 -> V_320 [ V_2 -> V_330 [ V_2 -> V_276 [ 0 ] ] ] ;
V_2 -> V_466 = V_456 ;
V_2 -> V_467 = V_457 ;
F_284 ( V_19 , V_2 -> V_465 , V_456 , 0 , V_457 ) ;
F_274 ( V_448 , V_19 , V_450 , V_458 ) ;
return 0 ;
}
static int F_304 ( struct V_447 * V_448 ,
struct V_18 * V_19 ,
struct V_449 * V_450 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_286 ( V_19 , V_2 -> V_465 ) ;
V_2 -> V_465 = 0 ;
F_274 ( V_448 , V_19 , V_450 , V_459 ) ;
return 0 ;
}
static void F_305 ( char * V_468 , T_3 V_469 , const char * V_134 ,
const char * V_470 )
{
char * V_471 ;
if ( * V_468 )
return;
F_306 ( V_468 , V_470 , V_469 ) ;
for ( V_471 = strchr ( V_468 , ' ' ) ; V_471 ; V_471 = strchr ( V_471 + 1 , ' ' ) ) {
if ( ! isalnum ( V_471 [ 1 ] ) ) {
* V_471 = 0 ;
break;
}
}
F_169 ( V_468 , V_134 , V_469 ) ;
}
static void F_307 ( struct V_447 * V_468 ,
const struct V_447 * V_472 ,
const struct V_447 * V_473 ,
T_1 V_52 )
{
* V_468 = * V_472 ;
if ( V_52 )
V_468 -> V_52 = V_52 ;
if ( V_473 ) {
if ( V_473 -> V_474 )
V_468 -> V_474 = V_473 -> V_474 ;
if ( V_473 -> V_475 )
V_468 -> V_475 = V_473 -> V_475 ;
if ( V_473 -> V_476 )
V_468 -> V_476 = V_473 -> V_476 ;
if ( V_473 -> V_477 )
V_468 -> V_477 = V_473 -> V_477 ;
if ( V_473 -> V_478 )
V_468 -> V_478 = V_473 -> V_478 ;
if ( V_473 -> V_479 )
V_468 -> V_479 = V_473 -> V_479 ;
}
}
int F_308 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_480 * V_481 ;
bool V_482 ;
if ( V_2 -> V_435 )
goto V_483;
F_305 ( V_2 -> V_484 ,
sizeof( V_2 -> V_484 ) ,
L_96 , V_19 -> V_91 . V_470 ) ;
V_481 = F_309 ( V_19 , L_97 , V_2 -> V_484 ) ;
if ( ! V_481 )
return - V_136 ;
V_2 -> V_442 [ 0 ] = V_481 ;
if ( V_2 -> V_159 . V_160 > 0 ) {
F_307 ( & V_481 -> V_485 [ V_486 ] ,
& V_487 ,
V_2 -> V_488 ,
V_2 -> V_159 . V_212 [ 0 ] ) ;
V_481 -> V_485 [ V_486 ] . V_476 =
V_2 -> V_159 . V_262 ;
if ( V_2 -> V_151 . V_164 == V_165 &&
V_2 -> V_151 . V_152 == 2 )
V_481 -> V_485 [ V_486 ] . V_489 =
V_490 ;
}
if ( V_2 -> V_322 ) {
F_307 ( & V_481 -> V_485 [ V_491 ] ,
( V_2 -> V_331 ?
& V_492 : & V_493 ) ,
V_2 -> V_494 ,
V_2 -> V_320 [ 0 ] ) ;
}
V_483:
if ( V_2 -> V_159 . V_373 || V_2 -> V_377 ) {
F_305 ( V_2 -> V_495 ,
sizeof( V_2 -> V_495 ) ,
L_98 , V_19 -> V_91 . V_470 ) ;
V_481 = F_309 ( V_19 , L_97 ,
V_2 -> V_495 ) ;
if ( ! V_481 )
return - V_136 ;
V_19 -> V_375 = V_2 -> V_159 . V_375 ;
V_2 -> V_442 [ 1 ] = V_481 ;
if ( V_2 -> V_374 )
V_481 -> V_443 = V_2 -> V_374 ;
else
V_481 -> V_443 = V_496 ;
if ( V_2 -> V_159 . V_373 )
F_307 ( & V_481 -> V_485 [ V_486 ] ,
& V_497 ,
V_2 -> V_498 ,
V_2 -> V_159 . V_373 ) ;
if ( V_2 -> V_377 )
F_307 ( & V_481 -> V_485 [ V_491 ] ,
& V_499 ,
V_2 -> V_500 ,
V_2 -> V_377 ) ;
}
if ( V_2 -> V_435 )
return 0 ;
V_482 = ( V_2 -> V_322 > 1 ) &&
! V_2 -> V_331 && ! V_2 -> V_362 ;
if ( V_2 -> V_254 || V_482 ) {
F_305 ( V_2 -> V_501 ,
sizeof( V_2 -> V_501 ) ,
L_99 , V_19 -> V_91 . V_470 ) ;
V_481 = F_309 ( V_19 , L_97 ,
V_2 -> V_501 ) ;
if ( ! V_481 )
return - V_136 ;
V_2 -> V_442 [ 2 ] = V_481 ;
if ( V_2 -> V_254 )
F_307 ( & V_481 -> V_485 [ V_486 ] ,
& V_502 ,
V_2 -> V_503 ,
V_2 -> V_254 ) ;
else
F_307 ( & V_481 -> V_485 [ V_486 ] ,
& V_504 , NULL , 0 ) ;
if ( V_482 ) {
F_307 ( & V_481 -> V_485 [ V_491 ] ,
& V_505 ,
V_2 -> V_506 ,
V_2 -> V_320 [ 1 ] ) ;
V_481 -> V_485 [ V_491 ] . V_474 =
V_2 -> V_322 - 1 ;
} else {
F_307 ( & V_481 -> V_485 [ V_491 ] ,
& V_504 , NULL , 0 ) ;
}
}
return 0 ;
}
static void F_310 ( struct V_18 * V_19 , int V_127 )
{
struct V_6 * V_54 ;
T_1 V_48 ;
V_54 = F_26 ( V_19 , V_127 ) ;
if ( ! V_54 || ! V_54 -> V_55 )
return;
V_48 = V_54 -> V_54 [ V_54 -> V_55 - 1 ] ;
F_14 ( V_19 , V_48 ) ;
F_76 ( V_19 , V_54 , V_54 -> V_93 ,
F_147 ( V_19 -> V_2 ) ) ;
F_79 ( V_19 , V_48 , V_54 -> V_93 ) ;
}
static void F_311 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_151 . V_152 ; V_16 ++ )
F_310 ( V_19 , V_2 -> V_204 [ V_16 ] ) ;
}
static void F_312 ( struct V_18 * V_19 , int V_180 , int * V_5 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_180 ; V_16 ++ )
F_310 ( V_19 , V_5 [ V_16 ] ) ;
}
static void F_313 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_151 . V_164 != V_167 )
F_312 ( V_19 , V_2 -> V_151 . V_155 , V_2 -> V_166 ) ;
if ( V_2 -> V_151 . V_164 != V_165 )
F_312 ( V_19 , V_2 -> V_151 . V_156 ,
V_2 -> V_168 ) ;
}
static void F_314 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_153 ; V_16 ++ ) {
T_1 V_48 = V_2 -> V_178 [ V_16 ] . V_48 ;
struct V_6 * V_54 ;
V_54 = F_146 ( V_19 , V_16 ) ;
if ( ! V_54 )
continue;
if ( ! V_2 -> V_178 [ V_16 ] . V_261 )
V_2 -> V_178 [ V_16 ] . V_261 =
F_16 ( V_19 , V_48 ) ;
F_76 ( V_19 , V_54 , V_54 -> V_93 ,
F_147 ( V_2 ) ) ;
}
}
static void F_315 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_252 )
return;
if ( ! F_116 ( V_2 ) )
return;
F_140 ( V_19 , V_2 -> V_253 , V_2 -> V_204 [ 0 ] ,
V_2 -> V_207 [ 0 ] ,
V_2 -> V_151 . V_164 ) ;
F_140 ( V_19 , V_2 -> V_253 , V_2 -> V_166 [ 0 ] ,
V_2 -> V_207 [ 1 ] ,
V_167 ) ;
F_140 ( V_19 , V_2 -> V_253 , V_2 -> V_168 [ 0 ] ,
V_2 -> V_207 [ 2 ] ,
V_165 ) ;
}
static void F_316 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_151 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_150 -> V_199 ; V_16 ++ ) {
T_1 V_52 = V_150 -> V_200 [ V_16 ] . V_48 ;
if ( F_189 ( V_19 , V_52 ) )
F_14 ( V_19 , V_52 ) ;
if ( V_2 -> V_47 ) {
F_81 ( V_19 , V_2 -> V_215 [ V_16 ] ) ;
F_81 ( V_19 , V_2 -> V_319 ) ;
}
}
}
static void F_317 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_325 * V_326 = & V_2 -> V_327 ;
struct V_6 * V_54 ;
int V_16 , V_338 , V_53 ;
if ( V_2 -> V_331 )
V_53 = 1 ;
else
V_53 = V_2 -> V_322 ;
for ( V_338 = 0 ; V_338 < V_53 ; V_338 ++ ) {
for ( V_16 = 0 ; V_16 < V_326 -> V_329 ; V_16 ++ ) {
V_54 = F_197 ( V_19 , V_338 , V_16 ) ;
if ( V_54 ) {
bool V_93 = V_54 -> V_93 ;
if ( V_16 == V_2 -> V_276 [ V_338 ] )
V_93 = true ;
F_76 ( V_19 , V_54 , V_93 , false ) ;
}
}
if ( V_2 -> V_44 )
F_157 ( V_19 , V_338 , true ) ;
}
if ( V_2 -> V_351 )
V_2 -> V_351 ( V_19 , NULL , NULL ) ;
}
static void F_318 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_48 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_151 . V_371 ; V_16 ++ )
F_310 ( V_19 , V_2 -> V_213 [ V_16 ] ) ;
V_48 = V_2 -> V_151 . V_376 ;
if ( V_48 ) {
F_14 ( V_19 , V_48 ) ;
F_81 ( V_19 , V_2 -> V_216 ) ;
}
}
static void F_319 ( struct V_18 * V_19 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_507 . V_17 ; V_16 ++ ) {
struct V_508 * V_48 = F_24 ( & V_19 -> V_507 , V_16 ) ;
T_1 V_52 = V_48 -> V_52 ;
if ( F_223 ( V_19 , V_52 ) &&
! F_320 ( V_19 , V_52 ) )
F_77 ( V_19 , V_52 , 0 ,
V_509 , 0 ) ;
}
}
int F_321 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_510 )
V_2 -> V_510 ( V_19 ) ;
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
F_323 ( V_19 -> V_91 . V_511 ) ;
if ( V_2 -> V_157 . V_408 && V_2 -> V_157 . V_158 )
F_271 ( & V_2 -> V_157 ) ;
F_324 ( V_19 , 0x01 ) ;
return 0 ;
}
void F_325 ( struct V_18 * V_19 )
{
F_326 ( V_19 , V_512 ) ;
F_10 ( V_19 -> V_2 ) ;
F_8 ( V_19 -> V_2 ) ;
V_19 -> V_2 = NULL ;
}
int F_327 ( struct V_18 * V_19 , T_1 V_52 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_328 ( V_19 , & V_2 -> V_310 , V_52 ) ;
}
static int F_329 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_211 ;
V_2 = F_330 ( sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 )
return - V_136 ;
F_1 ( V_2 ) ;
V_19 -> V_2 = V_2 ;
V_211 = F_331 ( V_19 , & V_2 -> V_151 , NULL , 0 ) ;
if ( V_211 < 0 )
return V_211 ;
V_211 = F_260 ( V_19 , & V_2 -> V_151 ) ;
if ( V_211 < 0 )
goto error;
V_19 -> V_439 = V_513 ;
return 0 ;
error:
F_325 ( V_19 ) ;
return V_211 ;
}
