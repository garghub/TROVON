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
struct V_18 * V_19 = F_94 ( V_141 ) ;
unsigned long V_147 ;
int V_148 ;
F_99 ( & V_19 -> V_149 ) ;
V_147 = V_141 -> V_133 ;
V_141 -> V_133 = V_147 & ~ V_150 ;
V_148 = F_100 ( V_141 , V_143 ) ;
V_141 -> V_133 = V_147 ;
F_101 ( & V_19 -> V_149 ) ;
return V_148 ;
}
static int F_102 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
unsigned long V_147 ;
int V_16 , V_151 , V_148 = 0 , V_152 = 0 ;
F_93 ( V_141 , V_143 ) ;
F_99 ( & V_19 -> V_149 ) ;
V_147 = V_141 -> V_133 ;
V_151 = ( V_147 & V_150 ) >> V_153 ;
for ( V_16 = 0 ; V_16 < V_151 ; V_16 ++ ) {
V_141 -> V_133 = ( V_147 & ~ V_150 ) |
( V_16 << V_153 ) ;
V_148 = F_97 ( V_141 , V_143 ) ;
if ( V_148 < 0 )
break;
V_152 |= V_148 ;
}
V_141 -> V_133 = V_147 ;
F_101 ( & V_19 -> V_149 ) ;
return V_148 < 0 ? V_148 : V_152 ;
}
static bool F_103 ( struct V_18 * V_19 , int V_127 , int V_154 )
{
struct V_6 * V_54 = F_26 ( V_19 , V_127 ) ;
return V_54 && V_54 -> V_62 [ V_154 ] ;
}
static const char * F_104 ( struct V_18 * V_19 , int V_155 ,
int * V_130 , int V_154 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_156 * V_157 = & V_2 -> V_158 ;
* V_130 = 0 ;
if ( V_157 -> V_159 == 1 && ! V_2 -> V_160 &&
! V_19 -> V_161 &&
! V_157 -> V_162 && ! V_157 -> V_163 )
return V_2 -> V_164 . V_165 ? L_35 : L_36 ;
if ( V_2 -> V_166 . V_167 == 1 && ! V_2 -> V_47 &&
! V_19 -> V_161 &&
! V_2 -> V_166 . V_168 [ 0 ] && ! V_2 -> V_166 . V_169 [ 0 ] )
return V_2 -> V_164 . V_165 ? L_35 : L_36 ;
if ( V_155 >= V_157 -> V_159 )
return V_170 [ V_155 ] ;
switch ( V_157 -> V_171 ) {
case V_172 :
if ( ! V_155 && V_157 -> V_162 &&
! F_103 ( V_19 , V_2 -> V_173 [ 0 ] , V_154 ) )
break;
if ( V_157 -> V_159 == 1 )
return L_37 ;
if ( V_157 -> V_159 == 2 )
return V_155 ? L_38 : L_37 ;
break;
case V_174 :
if ( ! V_155 && V_157 -> V_163 &&
! F_103 ( V_19 , V_2 -> V_175 [ 0 ] , V_154 ) )
break;
if ( V_155 && V_2 -> V_160 )
break;
* V_130 = V_155 ;
return L_39 ;
case V_176 :
if ( ! V_155 && V_157 -> V_163 && V_157 -> V_162 ) {
bool V_177 = ! F_103 ( V_19 , V_2 -> V_173 [ 0 ] , V_154 ) ;
bool V_178 = ! F_103 ( V_19 , V_2 -> V_175 [ 0 ] , V_154 ) ;
if ( V_177 && V_178 )
return V_2 -> V_164 . V_165 ? L_35 : L_36 ;
if ( V_177 )
return L_40 ;
if ( V_178 )
return L_41 ;
}
}
if ( V_157 -> V_159 == 1 && ! V_2 -> V_160 )
return L_42 ;
if ( V_155 >= F_105 ( V_170 ) ) {
F_106 () ;
return L_35 ;
}
return V_170 [ V_155 ] ;
}
static int F_107 ( struct V_18 * V_19 , struct V_6 * V_54 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_52 ;
unsigned int V_20 ;
int V_179 = 0 ;
if ( ! V_54 )
return V_180 * 2 ;
if ( V_54 -> V_62 [ V_108 ] ||
V_54 -> V_62 [ V_107 ] )
return 0 ;
V_52 = F_50 ( V_19 , V_54 ) ;
if ( V_52 ) {
V_20 = F_32 ( V_52 , 3 , 0 , V_84 ) ;
if ( V_2 -> V_181 )
V_20 |= V_182 ;
if ( F_30 ( V_19 , V_20 , V_108 ) )
V_179 += V_180 ;
else
V_54 -> V_62 [ V_108 ] = V_20 ;
} else
V_179 += V_180 ;
V_52 = F_48 ( V_19 , V_54 ) ;
if ( V_52 ) {
unsigned int V_183 = F_38 ( F_39 ( V_19 , V_52 ) ) ;
if ( V_183 == V_72 || V_183 == V_68 ||
F_49 ( V_19 , V_52 , V_84 ) )
V_20 = F_32 ( V_52 , 3 , 0 , V_84 ) ;
else
V_20 = F_32 ( V_52 , 3 , 0 , V_85 ) ;
if ( F_30 ( V_19 , V_20 , V_107 ) )
V_179 += V_180 ;
else
V_54 -> V_62 [ V_107 ] = V_20 ;
} else
V_179 += V_180 ;
return V_179 ;
}
static T_1 F_108 ( struct V_18 * V_19 , int V_60 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_156 * V_157 = & V_2 -> V_158 ;
if ( V_157 -> V_159 > V_60 )
return V_2 -> V_184 [ V_60 ] ;
V_60 -= V_157 -> V_159 ;
if ( V_2 -> V_160 > V_60 )
return V_2 -> V_185 [ V_60 ] . V_186 ;
return 0 ;
}
static inline T_1 F_109 ( struct V_18 * V_19 ,
T_1 V_186 , T_1 V_48 )
{
return F_28 ( V_19 , V_186 , V_48 ) ? V_186 : 0 ;
}
static int F_110 ( struct V_18 * V_19 , int V_187 ,
const T_1 * V_51 , T_1 * V_188 ,
int * V_127 ,
const struct V_189 * V_190 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_191 ;
int V_179 = 0 ;
T_1 V_186 ;
if ( ! V_187 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_187 ; V_16 ++ ) {
struct V_6 * V_54 ;
T_1 V_48 = V_51 [ V_16 ] ;
V_54 = F_26 ( V_19 , V_127 [ V_16 ] ) ;
if ( V_54 ) {
V_179 += F_107 ( V_19 , V_54 ) ;
continue;
}
V_188 [ V_16 ] = F_43 ( V_19 , V_48 ) ;
if ( V_188 [ V_16 ] ) {
if ( F_27 ( V_19 , V_188 [ V_16 ] ) )
V_179 += V_190 -> V_192 ;
}
if ( ! V_188 [ V_16 ] )
V_188 [ V_16 ] = F_44 ( V_19 , V_48 , false ) ;
if ( ! V_188 [ V_16 ] && ! V_16 ) {
for ( V_191 = 1 ; V_191 < V_187 ; V_191 ++ ) {
if ( F_28 ( V_19 , V_188 [ V_191 ] , V_48 ) ) {
V_188 [ 0 ] = V_188 [ V_191 ] ;
V_188 [ V_191 ] = 0 ;
F_42 ( V_19 , V_127 [ V_191 ] ) ;
V_127 [ V_191 ] = 0 ;
break;
}
}
}
V_186 = V_188 [ V_16 ] ;
if ( ! V_186 ) {
if ( V_187 > 2 )
V_186 = F_109 ( V_19 , F_108 ( V_19 , V_16 ) , V_48 ) ;
if ( ! V_186 )
V_186 = F_109 ( V_19 , V_188 [ 0 ] , V_48 ) ;
if ( ! V_186 )
V_186 = F_109 ( V_19 , F_108 ( V_19 , V_16 ) , V_48 ) ;
if ( V_186 ) {
if ( ! V_16 )
V_179 += V_190 -> V_192 ;
else if ( V_16 == 1 )
V_179 += V_190 -> V_193 ;
else
V_179 += V_190 -> V_194 ;
} else if ( F_28 ( V_19 , V_2 -> V_184 [ 0 ] , V_48 ) ) {
V_186 = V_2 -> V_184 [ 0 ] ;
V_179 += V_190 -> V_195 ;
} else if ( ! V_16 )
V_179 += V_190 -> V_196 ;
else
V_179 += V_190 -> V_197 ;
}
if ( ! V_186 )
continue;
V_54 = F_41 ( V_19 , V_186 , V_48 , - V_2 -> V_47 ) ;
if ( ! V_54 && ! V_16 && V_2 -> V_47 ) {
V_54 = F_41 ( V_19 , V_186 , V_48 , 0 ) ;
}
if ( ! V_54 ) {
V_186 = V_188 [ V_16 ] = 0 ;
V_179 += V_190 -> V_197 ;
} else {
V_54 -> V_93 = true ;
V_127 [ V_16 ] = F_25 ( V_19 , V_54 ) ;
V_179 += F_107 ( V_19 , V_54 ) ;
}
}
return V_179 ;
}
static T_1 F_111 ( struct V_18 * V_19 , T_1 V_48 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_198 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_78 ; V_16 ++ ) {
T_1 V_52 = V_2 -> V_79 [ V_16 ] ;
if ( ! V_52 || F_27 ( V_19 , V_52 ) )
continue;
if ( F_28 ( V_19 , V_52 , V_48 ) ) {
if ( V_198 )
return 0 ;
V_198 = V_52 ;
}
}
return V_198 ;
}
static bool F_112 ( struct V_18 * V_19 ,
unsigned int V_199 , T_1 V_52 )
{
unsigned int V_200 , V_87 ;
V_200 = F_113 ( V_19 , V_52 ) ;
if ( F_114 ( V_200 ) != V_201 )
return false ;
if ( V_199 && F_115 ( V_200 ) != V_199 )
return false ;
V_87 = F_80 ( V_19 , V_52 ) ;
if ( ! ( V_87 & V_202 ) )
return false ;
return true ;
}
static int F_116 ( struct V_18 * V_19 , T_1 V_203 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_156 * V_157 = & V_2 -> V_158 ;
unsigned int V_200 = F_113 ( V_19 , V_203 ) ;
unsigned int V_199 = F_115 ( V_200 ) ;
int type , V_16 ;
int V_50 = 0 ;
for ( type = V_204 ; type >= V_205 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_157 -> V_206 ; V_16 ++ ) {
if ( V_157 -> V_207 [ V_16 ] . type != type )
continue;
if ( F_112 ( V_19 , V_199 ,
V_157 -> V_207 [ V_16 ] . V_48 ) )
V_50 ++ ;
}
}
return V_50 ;
}
static int F_117 ( struct V_18 * V_19 ,
T_1 V_203 ,
bool V_208 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_156 * V_157 = & V_2 -> V_158 ;
int type , V_16 , V_191 , V_50 , V_209 ;
unsigned int V_200 = F_113 ( V_19 , V_203 ) ;
unsigned int V_199 = F_115 ( V_200 ) ;
int V_179 = 0 ;
struct V_6 * V_54 ;
V_209 = V_2 -> V_160 ;
if ( V_209 >= 2 )
goto V_210;
V_50 = F_116 ( V_19 , V_203 ) ;
if ( V_50 < 2 )
goto V_210;
for ( type = V_204 ; type >= V_205 ; type -- ) {
for ( V_16 = 0 ; V_16 < V_157 -> V_206 ; V_16 ++ ) {
T_1 V_52 = V_157 -> V_207 [ V_16 ] . V_48 ;
T_1 V_186 = 0 ;
if ( V_157 -> V_207 [ V_16 ] . type != type )
continue;
if ( ! F_112 ( V_19 , V_199 , V_52 ) )
continue;
for ( V_191 = 0 ; V_191 < V_2 -> V_160 ; V_191 ++ ) {
if ( V_52 == V_2 -> V_185 [ V_191 ] . V_48 )
break;
}
if ( V_191 < V_2 -> V_160 )
continue;
if ( V_208 )
V_186 = F_111 ( V_19 , V_52 ) ;
else if ( ! V_186 )
V_186 = F_44 ( V_19 , V_52 , false ) ;
if ( ! V_186 ) {
V_179 ++ ;
continue;
}
V_54 = F_41 ( V_19 , V_186 , V_52 ,
- V_2 -> V_47 ) ;
if ( ! V_54 ) {
V_179 ++ ;
continue;
}
V_2 -> V_185 [ V_2 -> V_160 ] . V_48 = V_52 ;
V_2 -> V_185 [ V_2 -> V_160 ] . V_186 = V_186 ;
V_2 -> V_211 [ V_157 -> V_159 + V_2 -> V_160 ] =
F_25 ( V_19 , V_54 ) ;
V_2 -> V_160 ++ ;
if ( V_2 -> V_160 >= 2 )
break;
}
}
V_210:
if ( V_179 )
V_179 = V_212 ;
if ( V_209 == V_2 -> V_160 ) {
if ( V_208 )
return 1 ;
else
return V_179 ;
}
if ( ! V_208 && V_2 -> V_160 < 2 ) {
V_2 -> V_5 . V_17 -= V_2 -> V_160 - V_209 ;
V_2 -> V_160 = V_209 ;
return V_179 ;
}
for ( V_16 = V_209 ; V_16 < V_2 -> V_160 ; V_16 ++ ) {
V_54 = F_26 ( V_19 , V_2 -> V_211 [ V_157 -> V_159 + V_16 ] ) ;
V_179 += F_107 ( V_19 , V_54 ) ;
}
return V_179 ;
}
static bool F_118 ( struct V_18 * V_19 , int V_213 ,
const T_1 * V_51 , T_1 * V_188 , int * V_127 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
bool V_69 = false ;
for ( V_16 = 0 ; V_16 < V_213 ; V_16 ++ ) {
struct V_6 * V_54 ;
T_1 V_186 ;
if ( V_188 [ V_16 ] )
continue;
V_186 = F_111 ( V_19 , V_51 [ V_16 ] ) ;
if ( ! V_186 )
continue;
V_54 = F_41 ( V_19 , V_186 , V_51 [ V_16 ] ,
- V_2 -> V_47 ) ;
if ( ! V_54 && ! V_16 && V_2 -> V_47 )
V_54 = F_41 ( V_19 , V_186 , V_51 [ V_16 ] , 0 ) ;
if ( V_54 ) {
V_188 [ V_16 ] = V_186 ;
V_69 = true ;
V_54 -> V_93 = true ;
V_127 [ V_16 ] = F_25 ( V_19 , V_54 ) ;
}
}
return V_69 ;
}
static inline bool F_119 ( struct V_1 * V_2 )
{
return V_2 -> V_214 [ 0 ] || V_2 -> V_214 [ 1 ] ||
V_2 -> V_214 [ 2 ] ;
}
static int F_120 ( struct V_18 * V_19 , int V_127 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_54 ;
T_1 V_215 , V_186 , V_48 ;
V_54 = F_26 ( V_19 , V_127 ) ;
if ( ! V_54 || ! V_54 -> V_55 ||
F_22 ( V_54 , V_2 -> V_47 ) )
return 0 ;
V_215 = V_54 -> V_54 [ 0 ] ;
V_186 = V_2 -> V_184 [ 0 ] ;
V_48 = V_54 -> V_54 [ V_54 -> V_55 - 1 ] ;
V_54 = F_41 ( V_19 , V_186 , V_48 , V_2 -> V_47 ) ;
if ( ! V_54 ) {
if ( V_186 != V_215 )
V_186 = V_215 ;
else if ( V_2 -> V_166 . V_168 [ 0 ] )
V_186 = V_2 -> V_166 . V_168 [ 0 ] ;
else if ( V_2 -> V_166 . V_169 [ 0 ] )
V_186 = V_2 -> V_166 . V_169 [ 0 ] ;
else
V_186 = 0 ;
if ( V_186 )
V_54 = F_41 ( V_19 , V_186 , V_48 ,
V_2 -> V_47 ) ;
}
if ( ! V_54 )
return 0 ;
V_54 -> V_93 = false ;
V_54 -> V_96 = true ;
return F_25 ( V_19 , V_54 ) ;
}
static bool F_121 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_156 * V_157 = & V_2 -> V_158 ;
struct V_6 * V_54 ;
int V_16 , V_60 ;
if ( V_157 -> V_171 == V_174 )
V_60 = V_2 -> V_211 [ 0 ] ;
else
V_60 = V_2 -> V_173 [ 0 ] ;
V_54 = F_26 ( V_19 , V_60 ) ;
if ( ! V_54 )
return false ;
if ( ! V_2 -> V_47 || ! F_22 ( V_54 , V_2 -> V_47 ) )
return true ;
for ( V_16 = 0 ; V_16 < V_157 -> V_159 ; V_16 ++ ) {
if ( V_2 -> V_211 [ V_16 ] == V_60 )
break;
V_54 = F_26 ( V_19 , V_2 -> V_211 [ V_16 ] ) ;
if ( V_54 && F_22 ( V_54 , V_2 -> V_47 ) )
return false ;
}
for ( V_16 = 0 ; V_16 < V_157 -> V_163 ; V_16 ++ ) {
V_54 = F_26 ( V_19 , V_2 -> V_175 [ V_16 ] ) ;
if ( V_54 && F_22 ( V_54 , V_2 -> V_47 ) )
return false ;
}
return true ;
}
static void F_122 ( struct V_18 * V_19 , int V_187 ,
T_1 * V_188 , int * V_127 )
{
struct V_6 * V_54 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_187 ; V_16 ++ ) {
if ( V_188 [ V_16 ] )
continue;
V_54 = F_26 ( V_19 , V_127 [ V_16 ] ) ;
if ( ! V_54 )
continue;
V_188 [ V_16 ] = V_54 -> V_54 [ 0 ] ;
}
}
static int F_123 ( struct V_18 * V_19 ,
bool V_216 ,
bool V_217 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_156 * V_157 = & V_2 -> V_158 ;
int V_16 , V_148 , V_179 ;
V_2 -> V_166 . V_167 = V_157 -> V_159 ;
V_2 -> V_166 . V_218 = V_2 -> V_184 ;
memset ( V_2 -> V_184 , 0 , sizeof( V_2 -> V_184 ) ) ;
memset ( V_2 -> V_166 . V_168 , 0 , sizeof( V_2 -> V_166 . V_168 ) ) ;
memset ( V_2 -> V_166 . V_169 , 0 , sizeof( V_2 -> V_166 . V_169 ) ) ;
V_2 -> V_160 = 0 ;
F_9 ( & V_2 -> V_5 ) ;
memset ( V_2 -> V_211 , 0 , sizeof( V_2 -> V_211 ) ) ;
memset ( V_2 -> V_173 , 0 , sizeof( V_2 -> V_173 ) ) ;
memset ( V_2 -> V_175 , 0 , sizeof( V_2 -> V_175 ) ) ;
memset ( V_2 -> V_214 , 0 , sizeof( V_2 -> V_214 ) ) ;
memset ( V_2 -> V_219 , 0 , sizeof( V_2 -> V_219 ) ) ;
memset ( V_2 -> V_220 , 0 , sizeof( V_2 -> V_220 ) ) ;
memset ( V_2 -> V_221 , 0 , sizeof( V_2 -> V_221 ) ) ;
memset ( & V_2 -> V_222 , 0 , sizeof( V_2 -> V_222 ) ) ;
V_179 = 0 ;
if ( V_216 ) {
bool V_223 ;
do {
V_223 = F_118 ( V_19 , V_157 -> V_159 ,
V_157 -> V_224 ,
V_2 -> V_184 ,
V_2 -> V_211 ) ;
V_223 |= F_118 ( V_19 , V_157 -> V_162 ,
V_157 -> V_225 ,
V_2 -> V_166 . V_168 ,
V_2 -> V_173 ) ;
V_223 |= F_118 ( V_19 , V_157 -> V_163 ,
V_157 -> V_226 ,
V_2 -> V_166 . V_169 ,
V_2 -> V_175 ) ;
if ( ! V_2 -> V_37 &&
V_217 && V_157 -> V_159 == 1 &&
V_157 -> V_171 != V_172 ) {
V_148 = F_117 ( V_19 , V_157 -> V_224 [ 0 ] , true ) ;
if ( ! V_148 )
V_223 = true ;
}
} while ( V_223 );
}
V_179 += F_110 ( V_19 , V_157 -> V_159 , V_157 -> V_224 ,
V_2 -> V_184 , V_2 -> V_211 ,
V_2 -> V_227 ) ;
if ( ! V_2 -> V_37 && V_217 &&
V_157 -> V_159 == 1 && V_157 -> V_171 != V_172 ) {
V_148 = F_117 ( V_19 , V_157 -> V_224 [ 0 ] , false ) ;
if ( V_148 < 0 )
return V_148 ;
}
if ( V_157 -> V_171 != V_174 ) {
V_148 = F_110 ( V_19 , V_157 -> V_162 , V_157 -> V_225 ,
V_2 -> V_166 . V_168 ,
V_2 -> V_173 ,
V_2 -> V_228 ) ;
if ( V_148 < 0 )
return V_148 ;
V_179 += V_148 ;
}
if ( V_157 -> V_171 != V_172 ) {
V_148 = F_110 ( V_19 , V_157 -> V_163 ,
V_157 -> V_226 ,
V_2 -> V_166 . V_169 ,
V_2 -> V_175 ,
V_2 -> V_228 ) ;
if ( V_148 < 0 )
return V_148 ;
V_179 += V_148 ;
}
if ( ! V_2 -> V_37 &&
V_157 -> V_159 == 1 && V_157 -> V_171 != V_172 ) {
V_148 = F_117 ( V_19 , V_157 -> V_224 [ 0 ] , false ) ;
if ( V_148 < 0 )
return V_148 ;
V_179 += V_148 ;
}
if ( V_2 -> V_47 ) {
V_2 -> V_214 [ 0 ] =
F_120 ( V_19 , V_2 -> V_211 [ 0 ] ) ;
if ( V_157 -> V_171 != V_174 )
V_2 -> V_214 [ 1 ] =
F_120 ( V_19 , V_2 -> V_173 [ 0 ] ) ;
if ( V_157 -> V_171 != V_172 )
V_2 -> V_214 [ 2 ] =
F_120 ( V_19 , V_2 -> V_175 [ 0 ] ) ;
}
if ( ! V_2 -> V_37 &&
V_157 -> V_162 && V_157 -> V_171 == V_172 )
if ( F_116 ( V_19 , V_157 -> V_225 [ 0 ] ) >= 2 )
V_2 -> V_160 = 1 ;
V_2 -> V_166 . V_167 = 0 ;
for ( V_16 = 0 ; V_16 < V_157 -> V_159 ; V_16 ++ ) {
if ( V_2 -> V_184 [ V_16 ] )
V_2 -> V_166 . V_167 ++ ;
else {
memmove ( V_2 -> V_184 + V_16 ,
V_2 -> V_184 + V_16 + 1 ,
sizeof( T_1 ) * ( V_157 -> V_159 - V_16 - 1 ) ) ;
V_2 -> V_184 [ V_157 -> V_159 - 1 ] = 0 ;
}
}
V_2 -> V_229 = V_2 -> V_230 =
V_2 -> V_166 . V_167 * 2 ;
if ( V_2 -> V_160 == 2 ) {
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
V_2 -> V_184 [ V_2 -> V_166 . V_167 ++ ] =
V_2 -> V_185 [ V_16 ] . V_186 ;
} else if ( V_2 -> V_160 ) {
V_2 -> V_160 = 0 ;
V_179 += V_212 ;
}
if ( V_2 -> V_40 && ! F_121 ( V_19 ) )
V_179 += V_231 ;
if ( V_157 -> V_171 != V_174 )
F_122 ( V_19 , V_157 -> V_162 ,
V_2 -> V_166 . V_168 ,
V_2 -> V_173 ) ;
if ( V_157 -> V_171 != V_172 )
F_122 ( V_19 , V_157 -> V_163 ,
V_2 -> V_166 . V_169 ,
V_2 -> V_175 ) ;
return V_179 ;
}
static inline void F_124 ( struct V_18 * V_19 ,
const char * V_64 , int V_60 )
{
struct V_6 * V_54 ;
V_54 = F_26 ( V_19 , V_60 ) ;
if ( V_54 )
F_33 ( V_19 , V_64 , V_54 ) ;
}
static void F_125 ( struct V_18 * V_19 ,
struct V_156 * V_157 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_232 [ 3 ] = { L_43 , L_44 , L_45 } ;
int V_16 ;
F_126 ( L_46 ,
V_157 -> V_224 [ 0 ] , V_157 -> V_224 [ 1 ] ,
V_157 -> V_224 [ 2 ] , V_157 -> V_224 [ 3 ] ,
V_2 -> V_166 . V_218 [ 0 ] ,
V_2 -> V_166 . V_218 [ 1 ] ,
V_2 -> V_166 . V_218 [ 2 ] ,
V_2 -> V_166 . V_218 [ 3 ] ,
V_232 [ V_157 -> V_171 ] ) ;
for ( V_16 = 0 ; V_16 < V_157 -> V_159 ; V_16 ++ )
F_124 ( V_19 , L_47 , V_2 -> V_211 [ V_16 ] ) ;
if ( V_2 -> V_160 > 0 )
F_126 ( L_48 ,
V_2 -> V_160 ,
V_2 -> V_185 [ 0 ] . V_48 , V_2 -> V_185 [ 1 ] . V_48 ,
V_2 -> V_185 [ 0 ] . V_186 , V_2 -> V_185 [ 1 ] . V_186 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_160 ; V_16 ++ )
F_124 ( V_19 , L_49 ,
V_2 -> V_211 [ V_157 -> V_159 + V_16 ] ) ;
if ( V_157 -> V_162 )
F_126 ( L_50 ,
V_157 -> V_225 [ 0 ] , V_157 -> V_225 [ 1 ] ,
V_157 -> V_225 [ 2 ] , V_157 -> V_225 [ 3 ] ,
V_2 -> V_166 . V_168 [ 0 ] ,
V_2 -> V_166 . V_168 [ 1 ] ,
V_2 -> V_166 . V_168 [ 2 ] ,
V_2 -> V_166 . V_168 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_157 -> V_162 ; V_16 ++ )
F_124 ( V_19 , L_51 , V_2 -> V_173 [ V_16 ] ) ;
if ( V_157 -> V_163 )
F_126 ( L_52 ,
V_157 -> V_226 [ 0 ] , V_157 -> V_226 [ 1 ] ,
V_157 -> V_226 [ 2 ] , V_157 -> V_226 [ 3 ] ,
V_2 -> V_166 . V_169 [ 0 ] ,
V_2 -> V_166 . V_169 [ 1 ] ,
V_2 -> V_166 . V_169 [ 2 ] ,
V_2 -> V_166 . V_169 [ 3 ] ) ;
for ( V_16 = 0 ; V_16 < V_157 -> V_163 ; V_16 ++ )
F_124 ( V_19 , L_53 , V_2 -> V_175 [ V_16 ] ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ )
F_124 ( V_19 , L_54 , V_2 -> V_214 [ V_16 ] ) ;
}
static void F_127 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_52 ;
V_2 -> V_78 = 0 ;
memset ( V_2 -> V_79 , 0 , sizeof( V_2 -> V_79 ) ) ;
F_128 (nid, codec) {
if ( F_38 ( F_39 ( V_19 , V_52 ) ) != V_68 )
continue;
if ( V_2 -> V_78 >= F_105 ( V_2 -> V_79 ) ) {
F_129 ( V_19 , L_55 ) ;
break;
}
V_2 -> V_79 [ V_2 -> V_78 ++ ] = V_52 ;
}
}
static int F_130 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_156 * V_157 = & V_2 -> V_158 ;
struct V_156 * V_233 ;
unsigned int V_20 ;
int V_234 = V_235 ;
int V_179 ;
bool V_216 = true , V_217 = true ;
bool V_236 = true , V_237 = true ;
bool V_238 = false ;
V_233 = F_131 ( sizeof( * V_233 ) , V_13 ) ;
if ( ! V_233 )
return - V_136 ;
* V_233 = * V_157 ;
for (; ; ) {
V_179 = F_123 ( V_19 , V_216 ,
V_217 ) ;
if ( V_179 < 0 ) {
F_8 ( V_233 ) ;
return V_179 ;
}
F_126 ( L_56 ,
V_157 -> V_171 , V_216 , V_217 ,
V_179 ) ;
F_125 ( V_19 , V_157 ) ;
if ( V_179 < V_234 ) {
V_234 = V_179 ;
* V_233 = * V_157 ;
V_236 = V_216 ;
V_237 = V_217 ;
}
if ( ! V_179 )
break;
V_217 = ! V_217 ;
if ( ! V_217 )
continue;
V_216 = ! V_216 ;
if ( ! V_216 )
continue;
if ( V_238 )
break;
V_238 = true ;
if ( V_157 -> V_163 > 0 &&
V_157 -> V_171 == V_174 ) {
V_157 -> V_162 = V_157 -> V_159 ;
memcpy ( V_157 -> V_225 , V_157 -> V_224 ,
sizeof( V_157 -> V_225 ) ) ;
V_157 -> V_159 = V_157 -> V_163 ;
memcpy ( V_157 -> V_224 , V_157 -> V_226 ,
sizeof( V_157 -> V_226 ) ) ;
V_157 -> V_163 = 0 ;
memset ( V_157 -> V_226 , 0 , sizeof( V_157 -> V_226 ) ) ;
V_157 -> V_171 = V_172 ;
V_216 = true ;
continue;
}
if ( V_157 -> V_162 > 0 &&
V_157 -> V_171 == V_172 ) {
V_157 -> V_163 = V_157 -> V_159 ;
memcpy ( V_157 -> V_226 , V_157 -> V_224 ,
sizeof( V_157 -> V_226 ) ) ;
V_157 -> V_159 = V_157 -> V_162 ;
memcpy ( V_157 -> V_224 , V_157 -> V_225 ,
sizeof( V_157 -> V_225 ) ) ;
V_157 -> V_162 = 0 ;
memset ( V_157 -> V_225 , 0 , sizeof( V_157 -> V_225 ) ) ;
V_157 -> V_171 = V_174 ;
V_216 = true ;
continue;
}
break;
}
if ( V_179 ) {
F_126 ( L_57 ) ;
* V_157 = * V_233 ;
F_123 ( V_19 , V_236 , V_237 ) ;
}
F_126 ( L_58 ,
V_157 -> V_171 , V_236 , V_237 ) ;
F_125 ( V_19 , V_157 ) ;
if ( V_157 -> V_224 [ 0 ] ) {
struct V_6 * V_54 ;
V_54 = F_26 ( V_19 , V_2 -> V_211 [ 0 ] ) ;
if ( V_54 )
V_2 -> V_239 = F_50 ( V_19 , V_54 ) ;
if ( V_2 -> V_239 ) {
F_132 ( V_19 , V_2 -> V_239 ,
V_84 , V_2 -> V_240 ) ;
if ( V_2 -> V_181 )
V_2 -> V_240 [ 3 ] |= V_241 ;
}
}
if ( V_2 -> V_242 || V_157 -> V_171 == V_174 )
V_20 = V_243 ;
else
V_20 = V_244 ;
F_20 ( V_19 , V_157 -> V_159 , V_157 -> V_224 , V_20 ) ;
if ( V_157 -> V_171 != V_174 )
F_20 ( V_19 , V_157 -> V_162 , V_157 -> V_225 , V_243 ) ;
if ( V_157 -> V_171 != V_172 ) {
V_20 = V_2 -> V_242 ? V_243 : V_244 ;
F_20 ( V_19 , V_157 -> V_163 ,
V_157 -> V_226 , V_20 ) ;
}
if ( V_2 -> V_40 && ! F_121 ( V_19 ) )
V_2 -> V_40 = 0 ;
F_8 ( V_233 ) ;
return 0 ;
}
static int F_133 ( struct V_18 * V_19 ,
const struct V_156 * V_157 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_148 , V_245 ;
V_245 = V_157 -> V_159 ;
if ( V_2 -> V_160 > 0 && V_157 -> V_159 < 3 )
V_245 += V_2 -> V_160 ;
for ( V_16 = 0 ; V_16 < V_245 ; V_16 ++ ) {
const char * V_10 ;
int V_130 ;
struct V_6 * V_54 ;
V_54 = F_26 ( V_19 , V_2 -> V_211 [ V_16 ] ) ;
if ( ! V_54 )
continue;
V_10 = F_104 ( V_19 , V_16 , & V_130 , V_108 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_59 ) ) {
V_148 = F_85 ( V_19 , L_60 , 0 , 1 , V_54 ) ;
if ( V_148 < 0 )
return V_148 ;
V_148 = F_85 ( V_19 , L_61 , 0 , 2 , V_54 ) ;
if ( V_148 < 0 )
return V_148 ;
} else {
V_148 = F_88 ( V_19 , V_10 , V_130 , V_54 ) ;
if ( V_148 < 0 )
return V_148 ;
}
V_10 = F_104 ( V_19 , V_16 , & V_130 , V_107 ) ;
if ( ! V_10 || ! strcmp ( V_10 , L_59 ) ) {
V_148 = F_89 ( V_19 , L_60 , 0 , 1 , V_54 ) ;
if ( V_148 < 0 )
return V_148 ;
V_148 = F_89 ( V_19 , L_61 , 0 , 2 , V_54 ) ;
if ( V_148 < 0 )
return V_148 ;
} else {
V_148 = F_92 ( V_19 , V_10 , V_130 , V_54 ) ;
if ( V_148 < 0 )
return V_148 ;
}
}
return 0 ;
}
static int F_134 ( struct V_18 * V_19 , int V_127 ,
const char * V_64 , int V_128 )
{
struct V_6 * V_54 ;
int V_148 ;
V_54 = F_26 ( V_19 , V_127 ) ;
if ( ! V_54 )
return 0 ;
V_148 = F_88 ( V_19 , V_64 , V_128 , V_54 ) ;
if ( V_148 < 0 )
return V_148 ;
V_148 = F_92 ( V_19 , V_64 , V_128 , V_54 ) ;
if ( V_148 < 0 )
return V_148 ;
return 0 ;
}
static int F_135 ( struct V_18 * V_19 , int V_50 ,
const int * V_5 , const char * V_64 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_50 ; V_16 ++ ) {
const char * V_10 ;
char V_246 [ V_135 ] ;
int V_148 , V_60 = 0 ;
if ( V_50 == 2 && V_16 == 1 && ! strcmp ( V_64 , L_37 ) )
V_10 = L_38 ;
else if ( V_50 >= 3 ) {
snprintf ( V_246 , sizeof( V_246 ) , L_62 ,
V_64 , V_170 [ V_16 ] ) ;
V_10 = V_246 ;
} else {
V_10 = V_64 ;
V_60 = V_16 ;
}
V_148 = F_134 ( V_19 , V_5 [ V_16 ] , V_10 , V_60 ) ;
if ( V_148 < 0 )
return V_148 ;
}
return 0 ;
}
static int F_136 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_135 ( V_19 , V_2 -> V_158 . V_162 ,
V_2 -> V_173 ,
L_39 ) ;
}
static int F_137 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_135 ( V_19 , V_2 -> V_158 . V_163 ,
V_2 -> V_175 ,
L_37 ) ;
}
static int F_138 ( struct V_140 * V_141 ,
struct V_247 * V_248 )
{
return F_139 ( V_141 , V_248 ) ;
}
static int F_140 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_143 -> V_146 . V_249 . V_250 [ 0 ] = V_2 -> V_251 ;
return 0 ;
}
static int F_141 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_252 = V_143 -> V_146 . V_249 . V_250 [ 0 ] ;
int V_253 = 0 ;
F_99 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_254 ) {
V_253 = - V_255 ;
goto V_256;
}
if ( V_2 -> V_251 != V_252 ) {
T_1 * V_257 ;
if ( V_2 -> V_158 . V_171 == V_174 )
V_257 = & V_2 -> V_184 [ 0 ] ;
else
V_257 = & V_2 -> V_166 . V_168 [ 0 ] ;
if ( V_2 -> V_258 ) {
if ( V_2 -> V_158 . V_171 == V_174 )
F_142 ( V_19 , V_2 -> V_259 ,
V_2 -> V_211 [ 0 ] ,
V_2 -> V_214 [ 0 ] ,
V_2 -> V_158 . V_171 ) ;
else
F_142 ( V_19 , V_2 -> V_259 ,
V_2 -> V_173 [ 0 ] ,
V_2 -> V_214 [ 1 ] ,
V_174 ) ;
}
V_2 -> V_251 = V_252 ;
if ( V_2 -> V_251 )
* V_257 = 0 ;
else
* V_257 = V_2 -> V_260 ;
F_143 ( V_19 , NULL ) ;
V_253 = 1 ;
}
V_256:
F_101 ( & V_2 -> V_9 ) ;
return V_253 ;
}
static int F_144 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_186 ;
if ( ! V_2 -> V_40 )
return 0 ;
if ( V_2 -> V_158 . V_171 == V_174 )
V_186 = V_2 -> V_166 . V_218 [ 0 ] ;
else
V_186 = V_2 -> V_166 . V_168 [ 0 ] ;
if ( ! V_186 ) {
V_2 -> V_40 = 0 ;
return 0 ;
}
V_2 -> V_251 = false ;
V_2 -> V_260 = V_186 ;
if ( ! F_4 ( V_2 , NULL , & V_261 ) )
return - V_136 ;
return 0 ;
}
static int F_145 ( struct V_140 * V_141 ,
struct V_247 * V_248 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_81 ;
V_248 -> type = V_262 ;
V_248 -> V_263 = 1 ;
V_248 -> V_146 . V_249 . V_264 = V_2 -> V_160 + 1 ;
if ( V_248 -> V_146 . V_249 . V_250 > V_2 -> V_160 )
V_248 -> V_146 . V_249 . V_250 = V_2 -> V_160 ;
V_81 = V_248 -> V_146 . V_249 . V_250 * 2 + V_2 -> V_230 ;
sprintf ( V_248 -> V_146 . V_249 . V_10 , L_63 , V_81 ) ;
return 0 ;
}
static int F_146 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_143 -> V_146 . V_249 . V_250 [ 0 ] =
( V_2 -> V_229 - V_2 -> V_230 ) / 2 ;
return 0 ;
}
static inline struct V_6 *
F_147 ( struct V_18 * V_19 , int V_60 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_26 ( V_19 ,
V_2 -> V_211 [ V_2 -> V_158 . V_159 + V_60 ] ) ;
}
static bool F_148 ( struct V_1 * V_2 )
{
return ! V_2 -> V_258 || V_2 -> V_259 ;
}
static int F_149 ( struct V_18 * V_19 , int V_60 , bool V_265 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_52 = V_2 -> V_185 [ V_60 ] . V_48 ;
struct V_6 * V_54 ;
V_54 = F_147 ( V_19 , V_60 ) ;
if ( ! V_54 )
return - V_266 ;
if ( V_54 -> V_93 == V_265 )
return 0 ;
if ( V_265 ) {
F_17 ( V_19 , V_52 , V_244 , true ) ;
F_76 ( V_19 , V_54 , true , F_148 ( V_2 ) ) ;
F_79 ( V_19 , V_52 , true ) ;
} else {
F_79 ( V_19 , V_52 , false ) ;
F_76 ( V_19 , V_54 , false , F_148 ( V_2 ) ) ;
F_17 ( V_19 , V_52 , V_2 -> V_185 [ V_60 ] . V_267 , true ) ;
F_78 ( V_19 , V_54 ) ;
}
F_150 ( V_19 ) ;
return 0 ;
}
static int F_151 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 , V_155 ;
V_155 = V_143 -> V_146 . V_249 . V_250 [ 0 ] ;
if ( V_155 < 0 || V_155 > V_2 -> V_160 )
return - V_266 ;
if ( V_155 == ( V_2 -> V_229 - V_2 -> V_230 ) / 2 )
return 0 ;
V_2 -> V_229 = V_155 * 2 + V_2 -> V_230 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_160 ; V_16 ++ )
F_149 ( V_19 , V_16 , V_16 < V_155 ) ;
V_2 -> V_166 . V_268 = F_152 ( V_2 -> V_229 ,
V_2 -> V_269 ) ;
if ( V_2 -> V_35 )
V_2 -> V_166 . V_167 = V_2 -> V_166 . V_268 / 2 ;
return 1 ;
}
static int F_153 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_160 > 0 ) {
if ( ! F_4 ( V_2 , NULL , & V_270 ) )
return - V_136 ;
}
return 0 ;
}
static int F_154 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_143 -> V_146 . V_249 . V_250 [ 0 ] = V_2 -> V_259 ;
return 0 ;
}
static void F_142 ( struct V_18 * V_19 , bool V_271 ,
int V_272 , int V_273 ,
int V_274 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_275 , * V_276 ;
V_275 = F_26 ( V_19 , V_272 ) ;
V_276 = F_26 ( V_19 , V_273 ) ;
if ( ! V_275 || ! V_276 )
return;
if ( V_274 == V_174 && V_2 -> V_251 &&
V_276 -> V_54 [ 0 ] != V_2 -> V_260 )
V_271 = false ;
if ( V_271 ) {
F_76 ( V_19 , V_275 , false , true ) ;
F_76 ( V_19 , V_276 , true , true ) ;
F_78 ( V_19 , V_275 ) ;
} else {
F_76 ( V_19 , V_276 , false , false ) ;
F_76 ( V_19 , V_275 , true , false ) ;
F_78 ( V_19 , V_276 ) ;
}
}
static void F_155 ( struct V_18 * V_19 , int V_187 ,
const int * V_5 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_54 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_187 ; V_16 ++ ) {
V_54 = F_26 ( V_19 , V_5 [ V_16 ] ) ;
if ( V_54 )
F_76 ( V_19 , V_54 , V_54 -> V_93 ,
V_2 -> V_259 ) ;
}
}
static int F_156 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_156 * V_157 = & V_2 -> V_158 ;
unsigned int V_20 = V_143 -> V_146 . V_249 . V_250 [ 0 ] ;
if ( V_20 == V_2 -> V_259 )
return 0 ;
V_2 -> V_259 = V_20 ;
if ( F_119 ( V_2 ) ) {
F_142 ( V_19 , V_20 , V_2 -> V_211 [ 0 ] ,
V_2 -> V_214 [ 0 ] ,
V_157 -> V_171 ) ;
F_142 ( V_19 , V_20 , V_2 -> V_173 [ 0 ] ,
V_2 -> V_214 [ 1 ] ,
V_174 ) ;
F_142 ( V_19 , V_20 , V_2 -> V_175 [ 0 ] ,
V_2 -> V_214 [ 2 ] ,
V_172 ) ;
} else {
F_155 ( V_19 , V_157 -> V_159 , V_2 -> V_211 ) ;
if ( V_157 -> V_171 != V_174 )
F_155 ( V_19 , V_157 -> V_162 , V_2 -> V_173 ) ;
if ( V_157 -> V_171 != V_172 )
F_155 ( V_19 , V_157 -> V_163 ,
V_2 -> V_175 ) ;
}
return 1 ;
}
static int F_157 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_47 )
return 0 ;
if ( ! F_4 ( V_2 , NULL , & V_277 ) )
return - V_136 ;
V_2 -> V_258 = 1 ;
return 0 ;
}
static void F_158 ( struct V_18 * V_19 , int V_278 , bool V_279 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_280 ;
unsigned int V_20 ;
T_1 V_48 ;
V_48 = V_2 -> V_281 ;
V_280 = V_2 -> V_282 [ V_278 ] == V_2 -> V_283 ;
if ( ! V_279 ) {
V_20 = F_16 ( V_19 , V_48 ) ;
if ( V_280 ) {
if ( V_20 & V_284 )
return;
} else {
if ( V_20 & V_244 )
return;
}
}
V_20 = F_159 ( V_19 , V_48 ) ;
if ( V_20 == V_285 && V_2 -> V_286 ) {
const T_1 V_287 = V_2 -> V_286 ;
unsigned int V_288 = F_159 ( V_19 , V_287 ) ;
if ( V_288 != V_285 )
F_160 ( V_19 , V_287 ,
V_284 | ( V_280 ? V_288 : 0 ) ) ;
}
if ( ! V_2 -> V_289 ) {
if ( V_280 )
V_20 |= V_284 ;
else
V_20 = V_243 ;
F_17 ( V_19 , V_48 , V_20 , true ) ;
F_143 ( V_19 , NULL ) ;
}
}
static int F_161 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_156 * V_157 = & V_2 -> V_158 ;
unsigned int V_200 ;
T_1 V_52 ;
if ( ! V_2 -> V_44 ) {
if ( V_2 -> V_45 )
return 0 ;
if ( V_157 -> V_206 > 1 )
return 0 ;
else if ( V_157 -> V_206 == 1 ) {
V_200 = F_113 ( V_19 , V_157 -> V_207 [ 0 ] . V_48 ) ;
if ( F_162 ( V_200 ) != V_290 )
return 0 ;
}
}
V_2 -> V_44 = 0 ;
if ( V_157 -> V_206 >= V_291 )
return 0 ;
V_52 = 0 ;
if ( V_157 -> V_171 == V_174 && V_157 -> V_159 > 0 )
V_52 = V_157 -> V_224 [ 0 ] ;
else if ( V_157 -> V_162 > 0 )
V_52 = V_157 -> V_225 [ 0 ] ;
if ( ! V_52 )
return 0 ;
if ( ! ( F_80 ( V_19 , V_52 ) & V_292 ) )
return 0 ;
V_157 -> V_207 [ V_157 -> V_206 ] . V_48 = V_52 ;
V_157 -> V_207 [ V_157 -> V_206 ] . type = V_205 ;
V_157 -> V_207 [ V_157 -> V_206 ] . V_293 = 1 ;
V_157 -> V_206 ++ ;
V_2 -> V_44 = 1 ;
V_2 -> V_281 = V_52 ;
V_2 -> V_32 = 1 ;
F_35 ( V_19 , L_64 , V_52 ) ;
return 0 ;
}
static int F_163 ( struct V_140 * V_141 ,
struct V_247 * V_248 )
{
return F_164 ( V_141 , V_248 , 2 , V_294 ) ;
}
static int F_165 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
T_1 V_52 = V_141 -> V_133 ;
if ( F_16 ( V_19 , V_52 ) == V_243 )
V_143 -> V_146 . V_249 . V_250 [ 0 ] = 1 ;
else
V_143 -> V_146 . V_249 . V_250 [ 0 ] = 0 ;
return 0 ;
}
static int F_166 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
T_1 V_52 = V_141 -> V_133 ;
unsigned int V_20 ;
V_20 = V_143 -> V_146 . V_249 . V_250 [ 0 ] ? V_243 : V_244 ;
if ( F_16 ( V_19 , V_52 ) == V_20 )
return 0 ;
F_160 ( V_19 , V_52 , V_20 ) ;
return 1 ;
}
static bool F_167 ( struct V_18 * V_19 , const char * V_10 , int V_60 )
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
static void F_168 ( struct V_18 * V_19 , T_1 V_48 ,
char * V_10 , T_3 V_295 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_60 = 0 ;
F_169 ( V_19 , V_48 , & V_2 -> V_158 , V_10 , V_295 , & V_60 ) ;
F_170 ( V_10 , L_65 , V_295 ) ;
for (; F_167 ( V_19 , V_10 , V_60 ) ; V_60 ++ )
;
}
static int F_171 ( struct V_18 * V_19 , T_1 V_48 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_42 ) {
unsigned int V_296 = F_80 ( V_19 , V_48 ) ;
if ( ( V_296 & V_202 ) && ( V_296 & V_297 ) )
return 2 ;
}
return 1 ;
}
static int F_172 ( struct V_18 * V_19 , int V_50 ,
T_1 * V_51 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_50 ; V_16 ++ ) {
T_1 V_48 = V_51 [ V_16 ] ;
if ( V_48 == V_2 -> V_281 )
continue;
if ( F_171 ( V_19 , V_48 ) > 1 ) {
struct V_4 * V_12 ;
char V_10 [ V_135 ] ;
F_168 ( V_19 , V_48 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 ,
& V_298 ) ;
if ( ! V_12 )
return - V_136 ;
V_12 -> V_133 = V_48 ;
}
}
return 0 ;
}
static unsigned int F_173 ( struct V_18 * V_19 , T_1 V_48 )
{
unsigned int V_296 ;
V_296 = F_80 ( V_19 , V_48 ) ;
V_296 = ( V_296 & V_299 ) >> V_300 ;
V_296 &= ~ ( V_301 | V_302 ) ;
return V_296 ;
}
static int F_174 ( unsigned int V_303 , unsigned int V_304 )
{
unsigned int V_16 , V_90 = 0 ;
for ( V_16 = 0 ; V_16 < V_305 ; V_16 ++ ) {
if ( V_303 & ( 1 << V_16 ) ) {
if ( V_90 == V_304 )
return V_16 ;
V_90 ++ ;
}
}
return 0 ;
}
static int F_175 ( unsigned int V_303 , unsigned int V_60 )
{
unsigned int V_16 , V_90 = 0 ;
for ( V_16 = 0 ; V_16 < V_305 ; V_16 ++ ) {
if ( V_16 == V_60 )
return V_90 ;
if ( V_303 & ( 1 << V_16 ) )
V_90 ++ ;
}
return 0 ;
}
static int F_176 ( struct V_140 * V_141 ,
struct V_247 * V_248 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
T_1 V_52 = V_141 -> V_133 ;
unsigned int V_303 = F_173 ( V_19 , V_52 ) ;
F_164 ( V_141 , V_248 , F_177 ( V_303 ) ,
V_306 ) ;
strcpy ( V_248 -> V_146 . V_249 . V_10 ,
V_306 [ F_174 ( V_303 , V_248 -> V_146 . V_249 . V_250 ) ] ) ;
return 0 ;
}
static int F_178 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
T_1 V_52 = V_141 -> V_133 ;
unsigned int V_303 = F_173 ( V_19 , V_52 ) ;
unsigned int V_60 ;
V_60 = F_16 ( V_19 , V_52 ) & V_307 ;
V_143 -> V_146 . V_249 . V_250 [ 0 ] = F_175 ( V_303 , V_60 ) ;
return 0 ;
}
static int F_179 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
T_1 V_52 = V_141 -> V_133 ;
unsigned int V_303 = F_173 ( V_19 , V_52 ) ;
unsigned int V_20 , V_60 ;
V_20 = F_16 ( V_19 , V_52 ) ;
V_60 = F_175 ( V_303 , V_20 & V_307 ) ;
if ( V_60 == V_143 -> V_146 . V_249 . V_250 [ 0 ] )
return 0 ;
V_20 &= ~ V_307 ;
V_20 |= F_174 ( V_303 , V_143 -> V_146 . V_249 . V_250 [ 0 ] ) ;
F_160 ( V_19 , V_52 , V_20 ) ;
return 1 ;
}
static int F_180 ( struct V_18 * V_19 , T_1 V_48 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_308 = 0 ;
if ( V_2 -> V_42 )
V_308 = F_177 ( F_173 ( V_19 , V_48 ) ) ;
return V_308 ? V_308 : 1 ;
}
static int F_181 ( struct V_18 * V_19 , T_1 V_48 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
char V_10 [ V_135 ] ;
unsigned int V_200 ;
if ( V_48 == V_2 -> V_281 )
return 0 ;
V_200 = F_113 ( V_19 , V_48 ) ;
if ( F_162 ( V_200 ) == V_290 )
return 0 ;
if ( F_180 ( V_19 , V_48 ) <= 1 )
return 0 ;
F_168 ( V_19 , V_48 , V_10 , sizeof( V_10 ) ) ;
V_12 = F_4 ( V_2 , V_10 , & V_309 ) ;
if ( ! V_12 )
return - V_136 ;
V_12 -> V_133 = V_48 ;
return 0 ;
}
static int F_182 ( struct V_140 * V_141 ,
struct V_247 * V_248 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
T_1 V_52 = V_141 -> V_133 ;
int V_310 = F_171 ( V_19 , V_52 ) ;
int V_311 = F_180 ( V_19 , V_52 ) ;
const char * V_312 = NULL ;
int V_60 ;
V_248 -> type = V_262 ;
V_248 -> V_263 = 1 ;
V_248 -> V_146 . V_249 . V_264 = V_310 + V_311 ;
if ( V_248 -> V_146 . V_249 . V_250 >= V_248 -> V_146 . V_249 . V_264 )
V_248 -> V_146 . V_249 . V_250 = V_248 -> V_146 . V_249 . V_264 - 1 ;
V_60 = V_248 -> V_146 . V_249 . V_250 ;
if ( V_60 < V_310 ) {
if ( V_310 > 1 )
V_312 = V_294 [ V_60 ] ;
else
V_312 = L_66 ;
} else {
V_60 -= V_310 ;
if ( V_311 > 1 ) {
unsigned int V_303 = F_173 ( V_19 , V_52 ) ;
V_312 = V_306 [ F_174 ( V_303 , V_60 ) ] ;
} else
V_312 = L_67 ;
}
strcpy ( V_248 -> V_146 . V_249 . V_10 , V_312 ) ;
return 0 ;
}
static int F_183 ( struct V_18 * V_19 , T_1 V_52 )
{
int V_310 = F_171 ( V_19 , V_52 ) ;
int V_311 = F_180 ( V_19 , V_52 ) ;
unsigned int V_20 = F_16 ( V_19 , V_52 ) ;
int V_60 = 0 ;
if ( V_20 & V_244 ) {
if ( V_310 > 1 && V_20 == V_243 )
V_60 = 1 ;
} else if ( V_20 & V_284 ) {
V_60 = V_310 ;
if ( V_311 > 1 ) {
unsigned int V_303 = F_173 ( V_19 , V_52 ) ;
V_20 &= V_307 ;
V_60 += F_175 ( V_303 , V_20 ) ;
}
}
return V_60 ;
}
static int F_184 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
T_1 V_52 = V_141 -> V_133 ;
V_143 -> V_146 . V_249 . V_250 [ 0 ] =
F_183 ( V_19 , V_52 ) ;
return 0 ;
}
static int F_185 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
T_1 V_52 = V_141 -> V_133 ;
int V_310 = F_171 ( V_19 , V_52 ) ;
int V_311 = F_180 ( V_19 , V_52 ) ;
unsigned int V_20 , V_313 , V_60 ;
V_313 = F_183 ( V_19 , V_52 ) ;
V_60 = V_143 -> V_146 . V_249 . V_250 [ 0 ] ;
if ( V_313 == V_60 )
return 0 ;
if ( V_60 < V_310 ) {
if ( V_310 > 1 )
V_20 = V_60 ? V_243 : V_244 ;
else
V_20 = V_243 ;
} else {
V_60 -= V_310 ;
if ( V_311 > 1 ) {
unsigned int V_303 = F_173 ( V_19 , V_52 ) ;
V_20 = F_16 ( V_19 , V_52 ) ;
V_20 &= ~ ( V_307 | V_243 ) ;
V_20 |= F_174 ( V_303 , V_60 ) | V_284 ;
} else
V_20 = F_159 ( V_19 , V_52 ) | V_284 ;
}
F_160 ( V_19 , V_52 , V_20 ) ;
F_143 ( V_19 , NULL ) ;
return 1 ;
}
static int F_186 ( struct V_18 * V_19 , T_1 V_48 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
V_12 = F_4 ( V_2 , L_68 ,
& V_314 ) ;
if ( ! V_12 )
return - V_136 ;
V_12 -> V_133 = V_48 ;
V_2 -> V_289 = 1 ;
return 0 ;
}
static int F_187 ( struct V_1 * V_2 , T_1 V_315 , int V_60 )
{
struct V_8 * V_14 ;
V_14 = F_5 ( & V_2 -> V_7 ) ;
if ( ! V_14 )
return - V_136 ;
V_14 -> V_52 = V_315 ;
V_14 -> V_63 = V_85 ;
V_14 -> V_60 = V_60 ;
V_2 -> V_316 . V_317 = V_2 -> V_7 . V_14 ;
return 0 ;
}
static bool F_188 ( struct V_18 * V_19 , T_1 V_318 ,
T_1 V_48 , unsigned int * V_319 ,
unsigned int * V_320 )
{
int V_60 , V_321 ;
const T_1 * V_14 ;
T_1 V_52 ;
V_60 = F_29 ( V_19 , V_318 , V_48 , true ) ;
if ( V_60 < 0 )
return false ;
* V_319 = * V_320 = 0 ;
if ( F_51 ( V_19 , V_318 , V_85 ) )
* V_319 = F_32 ( V_318 , 3 , V_60 , V_85 ) ;
if ( F_49 ( V_19 , V_318 , V_85 ) )
* V_320 = F_32 ( V_318 , 3 , V_60 , V_85 ) ;
if ( * V_319 && * V_320 )
return true ;
V_321 = F_37 ( V_19 , V_318 , & V_14 ) ;
if ( V_321 < V_60 )
return false ;
V_52 = V_14 [ V_60 ] ;
if ( ! * V_319 && F_51 ( V_19 , V_52 , V_84 ) &&
! F_31 ( V_19 , V_52 , V_84 , 0 , V_108 ) )
* V_319 = F_32 ( V_52 , 3 , 0 , V_84 ) ;
if ( ! * V_320 && F_49 ( V_19 , V_52 , V_84 ) &&
! F_31 ( V_19 , V_52 , V_84 , 0 , V_107 ) )
* V_320 = F_32 ( V_52 , 3 , 0 , V_84 ) ;
return * V_319 || * V_320 ;
}
static int F_189 ( struct V_18 * V_19 , int V_322 ,
T_1 V_48 , const char * V_323 , int V_324 ,
T_1 V_318 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_54 ;
unsigned int V_319 , V_320 ;
int V_148 , V_60 ;
if ( ! F_188 ( V_19 , V_318 , V_48 , & V_319 , & V_320 ) )
return 0 ;
V_54 = F_41 ( V_19 , V_48 , V_318 , 0 ) ;
if ( ! V_54 )
return - V_266 ;
F_33 ( V_19 , L_69 , V_54 ) ;
V_2 -> V_221 [ V_322 ] = F_25 ( V_19 , V_54 ) ;
V_60 = V_54 -> V_60 [ V_54 -> V_55 - 1 ] ;
if ( V_319 ) {
V_148 = F_86 ( V_2 , V_137 , V_323 , V_324 , V_319 ) ;
if ( V_148 < 0 )
return V_148 ;
V_54 -> V_62 [ V_108 ] = V_319 ;
}
if ( V_320 ) {
V_148 = F_91 ( V_2 , V_138 , V_323 , V_324 , V_320 ) ;
if ( V_148 < 0 )
return V_148 ;
V_54 -> V_62 [ V_107 ] = V_320 ;
}
V_54 -> V_93 = true ;
V_54 -> V_94 = true ;
V_148 = F_187 ( V_2 , V_318 , V_60 ) ;
if ( V_148 < 0 )
return V_148 ;
if ( V_2 -> V_47 != V_2 -> V_112 &&
! V_2 -> V_325 ) {
V_54 = F_41 ( V_19 , V_2 -> V_47 ,
V_2 -> V_112 , 0 ) ;
if ( V_54 ) {
F_33 ( V_19 , L_70 , V_54 ) ;
V_54 -> V_93 = true ;
V_54 -> V_96 = true ;
V_54 -> V_94 = true ;
V_2 -> V_325 =
F_25 ( V_19 , V_54 ) ;
}
}
return 0 ;
}
static int F_190 ( struct V_18 * V_19 , T_1 V_52 )
{
unsigned int V_296 = F_80 ( V_19 , V_52 ) ;
return ( V_296 & V_292 ) != 0 ;
}
static int F_191 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_52 ;
T_1 * V_326 = V_2 -> V_326 ;
int V_327 = F_105 ( V_2 -> V_326 ) ;
int V_53 = 0 ;
F_128 (nid, codec) {
unsigned int V_87 = F_39 ( V_19 , V_52 ) ;
int type = F_38 ( V_87 ) ;
if ( type != V_71 || ( V_87 & V_80 ) )
continue;
V_326 [ V_53 ] = V_52 ;
if ( ++ V_53 >= V_327 )
break;
}
V_2 -> V_328 = V_53 ;
V_2 -> V_329 = V_53 ;
memcpy ( V_2 -> V_330 , V_2 -> V_326 , V_53 * sizeof( T_1 ) ) ;
return V_53 ;
}
static int F_192 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_331 * V_332 = & V_2 -> V_333 ;
unsigned int V_334 ;
int V_16 , V_90 , V_53 ;
V_53 = 0 ;
V_334 = 0 ;
for ( V_90 = 0 ; V_90 < V_2 -> V_328 ; V_90 ++ ) {
for ( V_16 = 0 ; V_16 < V_332 -> V_335 ; V_16 ++ ) {
if ( ! V_2 -> V_220 [ V_16 ] [ V_90 ] )
break;
}
if ( V_16 >= V_332 -> V_335 ) {
V_334 |= ( 1 << V_90 ) ;
V_53 ++ ;
}
}
if ( ! V_334 ) {
for ( V_16 = 0 ; V_16 < V_332 -> V_335 ; V_16 ++ ) {
for ( V_90 = 0 ; V_90 < V_2 -> V_328 ; V_90 ++ ) {
if ( V_2 -> V_220 [ V_16 ] [ V_90 ] ) {
V_2 -> V_336 [ V_16 ] = V_90 ;
break;
}
}
}
F_35 ( V_19 , L_71 ) ;
V_2 -> V_337 = 1 ;
} else if ( V_53 != V_2 -> V_328 ) {
V_53 = 0 ;
for ( V_90 = 0 ; V_90 < V_2 -> V_328 ; V_90 ++ ) {
if ( ! ( V_334 & ( 1 << V_90 ) ) )
continue;
if ( V_90 != V_53 ) {
V_2 -> V_326 [ V_53 ] = V_2 -> V_326 [ V_90 ] ;
for ( V_16 = 0 ; V_16 < V_332 -> V_335 ; V_16 ++ ) {
F_42 ( V_19 ,
V_2 -> V_220 [ V_16 ] [ V_53 ] ) ;
V_2 -> V_220 [ V_16 ] [ V_53 ] =
V_2 -> V_220 [ V_16 ] [ V_90 ] ;
V_2 -> V_220 [ V_16 ] [ V_90 ] = 0 ;
}
}
V_53 ++ ;
}
V_2 -> V_328 = V_53 ;
}
if ( V_332 -> V_335 == 1 ||
( V_332 -> V_335 == 2 && V_2 -> V_44 ) ) {
F_35 ( V_19 , L_72 ) ;
V_2 -> V_328 = 1 ;
}
if ( ! V_2 -> V_337 && V_2 -> V_38 )
V_2 -> V_328 = 1 ;
return 0 ;
}
static int F_193 ( struct V_18 * V_19 , T_1 V_48 ,
int V_338 , int V_339 ,
const char * V_340 , int V_341 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_331 * V_332 = & V_2 -> V_333 ;
int V_342 = V_332 -> V_335 ;
bool V_343 = false ;
int V_344 ;
for ( V_344 = 0 ; V_344 < V_339 ; V_344 ++ ) {
struct V_6 * V_54 ;
T_1 V_345 = V_2 -> V_326 [ V_344 ] ;
if ( ! F_28 ( V_19 , V_48 , V_345 ) )
continue;
V_54 = F_41 ( V_19 , V_48 , V_345 , V_341 ) ;
if ( ! V_54 )
continue;
F_33 ( V_19 , L_73 , V_54 ) ;
V_2 -> V_220 [ V_342 ] [ V_344 ] =
F_25 ( V_19 , V_54 ) ;
if ( ! V_343 ) {
if ( V_2 -> V_281 == V_48 )
V_2 -> V_283 = V_332 -> V_335 ;
V_2 -> V_346 [ V_332 -> V_335 ] = V_48 ;
F_194 ( V_19 , V_332 , V_340 , V_338 , NULL ) ;
V_343 = true ;
if ( V_2 -> V_337 )
V_2 -> V_336 [ V_342 ] = V_344 ;
}
}
return 0 ;
}
static int F_195 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_156 * V_157 = & V_2 -> V_158 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_157 -> V_206 ; V_16 ++ ) {
T_1 V_48 = V_157 -> V_207 [ V_16 ] . V_48 ;
const char * V_340 ;
int V_191 , V_60 ;
if ( ! F_190 ( V_19 , V_48 ) )
continue;
V_340 = F_196 ( V_19 , V_157 , V_16 ) ;
V_60 = 0 ;
for ( V_191 = V_16 - 1 ; V_191 >= 0 ; V_191 -- ) {
if ( V_2 -> V_347 [ V_191 ] &&
! strcmp ( V_2 -> V_347 [ V_191 ] , V_340 ) ) {
V_60 = V_2 -> V_348 [ V_191 ] + 1 ;
break;
}
}
V_2 -> V_347 [ V_16 ] = V_340 ;
V_2 -> V_348 [ V_16 ] = V_60 ;
}
return 0 ;
}
static int F_197 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_156 * V_157 = & V_2 -> V_158 ;
T_1 V_349 = V_2 -> V_47 ;
int V_339 ;
int V_16 , V_148 ;
unsigned int V_20 ;
V_339 = F_191 ( V_19 ) ;
if ( V_339 < 0 )
return 0 ;
V_148 = F_195 ( V_19 ) ;
if ( V_148 < 0 )
return V_148 ;
for ( V_16 = 0 ; V_16 < V_157 -> V_206 ; V_16 ++ ) {
T_1 V_48 ;
V_48 = V_157 -> V_207 [ V_16 ] . V_48 ;
if ( ! F_190 ( V_19 , V_48 ) )
continue;
V_20 = V_284 ;
if ( V_157 -> V_207 [ V_16 ] . type == V_205 )
V_20 |= F_159 ( V_19 , V_48 ) ;
if ( V_48 != V_2 -> V_281 &&
! F_16 ( V_19 , V_48 ) )
F_17 ( V_19 , V_48 , V_20 , false ) ;
if ( V_349 ) {
if ( F_28 ( V_19 , V_48 , V_349 ) ) {
V_148 = F_189 ( V_19 , V_16 , V_48 ,
V_2 -> V_347 [ V_16 ] ,
V_2 -> V_348 [ V_16 ] ,
V_349 ) ;
if ( V_148 < 0 )
return V_148 ;
}
}
V_148 = F_193 ( V_19 , V_48 , V_16 , V_339 ,
V_2 -> V_347 [ V_16 ] , - V_349 ) ;
if ( V_148 < 0 )
return V_148 ;
if ( V_2 -> V_42 ) {
V_148 = F_181 ( V_19 , V_48 ) ;
if ( V_148 < 0 )
return V_148 ;
}
}
if ( V_349 && V_2 -> V_41 == V_350 ) {
V_148 = F_193 ( V_19 , V_349 , V_351 , V_339 ,
L_74 , 0 ) ;
if ( V_148 < 0 )
return V_148 ;
else
V_2 -> V_32 = 1 ;
}
return 0 ;
}
static struct V_6 * F_198 ( struct V_18 * V_19 , int V_352 , int V_342 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_342 < 0 || V_342 >= V_353 ) {
F_106 () ;
return NULL ;
}
if ( V_2 -> V_337 )
V_352 = V_2 -> V_336 [ V_342 ] ;
if ( V_352 < 0 || V_352 >= V_291 ) {
F_106 () ;
return NULL ;
}
return F_26 ( V_19 , V_2 -> V_220 [ V_342 ] [ V_352 ] ) ;
}
static int F_199 ( struct V_140 * V_141 ,
struct V_247 * V_248 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
return F_200 ( & V_2 -> V_333 , V_248 ) ;
}
static int F_201 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_352 = F_202 ( V_141 , & V_143 -> V_354 ) ;
V_143 -> V_146 . V_249 . V_250 [ 0 ] = V_2 -> V_282 [ V_352 ] ;
return 0 ;
}
static int F_203 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
unsigned int V_352 = F_202 ( V_141 , & V_143 -> V_354 ) ;
return F_204 ( V_19 , V_352 ,
V_143 -> V_146 . V_249 . V_250 [ 0 ] ) ;
}
static int F_205 ( struct V_140 * V_141 ,
struct V_142 * V_143 ,
T_4 V_355 , int type )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_331 * V_332 ;
struct V_6 * V_54 ;
int V_16 , V_352 , V_148 = 0 ;
V_332 = & V_2 -> V_333 ;
V_352 = V_141 -> V_354 . V_130 ;
F_99 ( & V_19 -> V_149 ) ;
for ( V_16 = 0 ; V_16 < V_332 -> V_335 ; V_16 ++ ) {
V_54 = F_198 ( V_19 , V_352 , V_16 ) ;
if ( ! V_54 || ! V_54 -> V_62 [ type ] )
continue;
V_141 -> V_133 = V_54 -> V_62 [ type ] ;
V_148 = V_355 ( V_141 , V_143 ) ;
if ( V_148 < 0 )
break;
}
F_101 ( & V_19 -> V_149 ) ;
if ( V_148 >= 0 && V_2 -> V_356 )
V_2 -> V_356 ( V_19 , V_141 , V_143 ) ;
return V_148 ;
}
static int F_206 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
return F_205 ( V_141 , V_143 ,
V_357 ,
V_108 ) ;
}
static int F_207 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
return F_205 ( V_141 , V_143 ,
F_97 ,
V_107 ) ;
}
static int F_208 ( struct V_18 * V_19 , struct V_6 * V_54 )
{
T_1 V_52 ;
int V_16 , V_55 ;
V_54 -> V_62 [ V_108 ] = V_54 -> V_62 [ V_107 ] = 0 ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( V_55 >= V_54 -> V_55 )
return - V_266 ;
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
static bool F_209 ( struct V_18 * V_19 , T_1 V_52 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_156 * V_157 = & V_2 -> V_158 ;
unsigned int V_20 ;
int V_16 ;
if ( ! V_2 -> V_39 )
return false ;
for ( V_16 = 0 ; V_16 < V_157 -> V_206 ; V_16 ++ ) {
if ( V_157 -> V_207 [ V_16 ] . V_48 != V_52 )
continue;
if ( V_157 -> V_207 [ V_16 ] . type != V_205 )
return false ;
V_20 = F_113 ( V_19 , V_52 ) ;
return F_162 ( V_20 ) == V_290 ;
}
return false ;
}
static int F_210 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_253 ;
V_253 = F_97 ( V_141 , V_143 ) ;
if ( V_253 < 0 )
return V_253 ;
if ( V_2 -> V_356 )
V_2 -> V_356 ( V_19 , V_141 , V_143 ) ;
return V_253 ;
}
static int F_211 ( struct V_18 * V_19 , const char * V_340 ,
int V_60 , bool V_358 , unsigned int V_359 ,
bool V_360 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
char V_361 [ V_135 ] ;
int type = V_358 ? V_138 : V_137 ;
const char * V_134 = V_358 ? L_75 : L_76 ;
unsigned int V_81 = V_360 ? 1 : 3 ;
struct V_4 * V_12 ;
if ( ! V_359 )
return 0 ;
if ( V_340 )
snprintf ( V_361 , sizeof( V_361 ) ,
L_77 , V_340 , V_134 ) ;
else
snprintf ( V_361 , sizeof( V_361 ) ,
L_78 , V_134 ) ;
V_12 = F_82 ( V_2 , type , V_361 , V_60 ,
F_45 ( V_359 , V_81 ) ) ;
if ( ! V_12 )
return - V_136 ;
if ( V_358 )
V_12 -> V_362 = F_210 ;
if ( ! V_360 )
return 0 ;
if ( V_340 )
snprintf ( V_361 , sizeof( V_361 ) ,
L_79 , V_340 , V_134 ) ;
else
snprintf ( V_361 , sizeof( V_361 ) ,
L_80 , V_134 ) ;
V_12 = F_82 ( V_2 , type , V_361 , V_60 ,
F_45 ( V_359 , 2 ) ) ;
if ( ! V_12 )
return - V_136 ;
if ( V_358 )
V_12 -> V_362 = F_210 ;
return 0 ;
}
static int F_212 ( struct V_18 * V_19 , int V_60 ,
unsigned int V_363 , unsigned int V_364 ,
bool V_360 )
{
int V_148 ;
V_148 = F_211 ( V_19 , NULL , V_60 , false , V_363 , V_360 ) ;
if ( V_148 < 0 )
return V_148 ;
V_148 = F_211 ( V_19 , NULL , V_60 , true , V_364 , V_360 ) ;
if ( V_148 < 0 )
return V_148 ;
return 0 ;
}
static int F_213 ( struct V_18 * V_19 , int V_60 ,
unsigned int V_363 , unsigned int V_364 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_12 ;
if ( V_363 ) {
V_12 = F_4 ( V_2 , NULL , & V_365 ) ;
if ( ! V_12 )
return - V_136 ;
V_12 -> V_130 = V_60 ;
V_12 -> V_133 = V_363 ;
V_12 -> V_131 = V_132 ;
}
if ( V_364 ) {
V_12 = F_4 ( V_2 , NULL , & V_366 ) ;
if ( ! V_12 )
return - V_136 ;
V_12 -> V_130 = V_60 ;
V_12 -> V_133 = V_364 ;
V_12 -> V_131 = V_132 ;
}
return 0 ;
}
static unsigned int F_214 ( struct V_18 * V_19 , int V_60 , int type )
{
struct V_6 * V_54 ;
unsigned int V_359 ;
int V_16 ;
V_54 = F_198 ( V_19 , 0 , V_60 ) ;
if ( ! V_54 )
return 0 ;
V_359 = V_54 -> V_62 [ type ] ;
if ( ! V_359 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_60 - 1 ; V_16 ++ ) {
V_54 = F_198 ( V_19 , 0 , V_16 ) ;
if ( V_54 && V_54 -> V_62 [ type ] == V_359 )
return 0 ;
}
return V_359 ;
}
static int F_215 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_331 * V_332 = & V_2 -> V_333 ;
int V_16 , V_148 , type ;
for ( V_16 = 0 ; V_16 < V_332 -> V_335 ; V_16 ++ ) {
bool V_360 ;
int V_60 ;
V_60 = V_332 -> V_264 [ V_16 ] . V_130 ;
if ( V_60 >= V_2 -> V_158 . V_206 )
continue;
V_360 = F_209 ( V_19 , V_2 -> V_346 [ V_16 ] ) ;
for ( type = 0 ; type < 2 ; type ++ ) {
V_148 = F_211 ( V_19 ,
V_2 -> V_347 [ V_60 ] ,
V_2 -> V_348 [ V_60 ] ,
type ,
F_214 ( V_19 , V_16 , type ) ,
V_360 ) ;
if ( V_148 < 0 )
return V_148 ;
}
}
return 0 ;
}
static int F_216 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_331 * V_332 = & V_2 -> V_333 ;
int V_16 , V_90 , V_53 , V_148 ;
if ( V_2 -> V_337 )
V_53 = 1 ;
else
V_53 = V_2 -> V_328 ;
if ( ! V_2 -> V_367 && V_332 -> V_335 > 1 ) {
struct V_4 * V_12 ;
const char * V_10 ;
V_10 = V_53 > 1 ? L_81 : L_82 ;
V_12 = F_4 ( V_2 , V_10 , & V_368 ) ;
if ( ! V_12 )
return - V_136 ;
V_12 -> V_263 = V_53 ;
}
for ( V_90 = 0 ; V_90 < V_53 ; V_90 ++ ) {
bool V_74 = false ;
bool V_38 = V_2 -> V_38 ;
bool V_360 = false ;
int V_369 , V_370 ;
V_369 = V_370 = 0 ;
for ( V_16 = 0 ; V_16 < V_332 -> V_335 ; V_16 ++ ) {
struct V_6 * V_54 ;
V_54 = F_198 ( V_19 , V_90 , V_16 ) ;
if ( ! V_54 )
continue;
F_208 ( V_19 , V_54 ) ;
if ( ! V_369 )
V_369 = V_54 -> V_62 [ V_108 ] ;
else if ( V_369 != V_54 -> V_62 [ V_108 ] ) {
V_74 = true ;
if ( ! F_46 ( V_19 , V_369 ,
V_54 -> V_62 [ V_108 ] , V_85 ) )
V_38 = true ;
}
if ( ! V_370 )
V_370 = V_54 -> V_62 [ V_107 ] ;
else if ( V_370 != V_54 -> V_62 [ V_107 ] ) {
V_74 = true ;
if ( ! F_46 ( V_19 , V_370 ,
V_54 -> V_62 [ V_107 ] , V_85 ) )
V_38 = true ;
}
if ( F_209 ( V_19 , V_2 -> V_346 [ V_16 ] ) )
V_360 = true ;
}
if ( ! V_74 )
V_148 = F_212 ( V_19 , V_90 , V_369 , V_370 ,
V_360 ) ;
else if ( ! V_38 && ! V_360 )
V_148 = F_213 ( V_19 , V_90 , V_369 , V_370 ) ;
else
V_148 = F_215 ( V_19 ) ;
if ( V_148 < 0 )
return V_148 ;
}
return 0 ;
}
static bool F_217 ( struct V_18 * V_19 , T_1 V_52 ,
int V_63 , int V_60 )
{
unsigned int V_371 ;
if ( ! F_51 ( V_19 , V_52 , V_63 ) ||
F_31 ( V_19 , V_52 , V_63 , V_60 , V_108 ) ||
F_31 ( V_19 , V_52 , V_63 , V_60 , V_109 ) )
return false ;
V_371 = ( F_47 ( V_19 , V_52 , V_63 ) & V_372 )
>> V_373 ;
if ( V_371 < 0x20 )
return false ;
return true ;
}
static unsigned int F_218 ( struct V_18 * V_19 ,
struct V_6 * V_54 )
{
unsigned int V_20 = 0 ;
T_1 V_52 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( V_55 >= V_54 -> V_55 - 1 )
break;
V_52 = V_54 -> V_54 [ V_55 ] ;
if ( V_55 && F_217 ( V_19 , V_52 , V_84 , 0 ) ) {
V_20 = F_32 ( V_52 , 3 , 0 , V_84 ) ;
break;
} else if ( F_217 ( V_19 , V_52 , V_85 ,
V_54 -> V_60 [ V_55 ] ) ) {
V_20 = F_32 ( V_52 , 3 , V_54 -> V_60 [ V_55 ] ,
V_85 ) ;
break;
}
}
return V_20 ;
}
static int F_219 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_156 * V_157 = & V_2 -> V_158 ;
struct V_331 * V_332 = & V_2 -> V_333 ;
int V_16 ;
if ( ! V_2 -> V_328 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_332 -> V_335 ; V_16 ++ ) {
struct V_6 * V_54 ;
unsigned int V_20 ;
int V_60 ;
char V_374 [ V_135 ] ;
V_60 = V_332 -> V_264 [ V_16 ] . V_130 ;
if ( V_60 >= V_332 -> V_335 )
continue;
if ( V_157 -> V_207 [ V_60 ] . type > V_204 )
continue;
V_54 = F_198 ( V_19 , 0 , V_16 ) ;
if ( ! V_54 )
continue;
V_20 = F_218 ( V_19 , V_54 ) ;
if ( ! V_20 )
continue;
snprintf ( V_374 , sizeof( V_374 ) ,
L_83 , V_2 -> V_347 [ V_60 ] ) ;
if ( ! F_82 ( V_2 , V_137 , V_374 ,
V_2 -> V_348 [ V_60 ] , V_20 ) )
return - V_136 ;
V_54 -> V_62 [ V_109 ] = V_20 ;
}
return 0 ;
}
static void F_220 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_54 ;
int V_16 , V_53 ;
T_1 V_375 , V_48 ;
V_53 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_158 . V_376 ; V_16 ++ ) {
V_48 = V_2 -> V_158 . V_377 [ V_16 ] ;
V_375 = F_44 ( V_19 , V_48 , true ) ;
if ( ! V_375 )
continue;
V_54 = F_41 ( V_19 , V_375 , V_48 , 0 ) ;
if ( ! V_54 )
continue;
F_33 ( V_19 , L_84 , V_54 ) ;
V_54 -> V_93 = true ;
V_54 -> V_96 = true ;
V_2 -> V_219 [ V_16 ] = F_25 ( V_19 , V_54 ) ;
F_17 ( V_19 , V_48 , V_244 , false ) ;
if ( ! V_53 ) {
V_2 -> V_166 . V_378 = V_375 ;
V_2 -> V_379 = V_2 -> V_158 . V_379 [ 0 ] ;
} else {
V_2 -> V_166 . V_380 = V_2 -> V_380 ;
if ( V_53 >= F_105 ( V_2 -> V_380 ) - 1 )
break;
V_2 -> V_380 [ V_53 - 1 ] = V_375 ;
}
V_53 ++ ;
}
if ( V_2 -> V_158 . V_381 ) {
V_48 = V_2 -> V_158 . V_381 ;
F_128 (dig_nid, codec) {
unsigned int V_104 = F_39 ( V_19 , V_375 ) ;
if ( F_38 ( V_104 ) != V_71 )
continue;
if ( ! ( V_104 & V_80 ) )
continue;
V_54 = F_41 ( V_19 , V_48 , V_375 , 0 ) ;
if ( V_54 ) {
F_33 ( V_19 , L_85 , V_54 ) ;
V_54 -> V_93 = true ;
V_54 -> V_96 = true ;
V_2 -> V_382 = V_375 ;
V_2 -> V_222 = F_25 ( V_19 , V_54 ) ;
F_17 ( V_19 , V_48 , V_284 , false ) ;
break;
}
}
}
}
static int F_204 ( struct V_18 * V_19 , unsigned int V_352 ,
unsigned int V_60 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_331 * V_332 ;
struct V_6 * V_383 , * V_54 ;
V_332 = & V_2 -> V_333 ;
if ( ! V_332 -> V_335 )
return 0 ;
if ( V_60 >= V_332 -> V_335 )
V_60 = V_332 -> V_335 - 1 ;
if ( V_2 -> V_282 [ V_352 ] == V_60 )
return 0 ;
V_383 = F_198 ( V_19 , V_352 , V_2 -> V_282 [ V_352 ] ) ;
if ( ! V_383 )
return 0 ;
if ( V_383 -> V_93 )
F_76 ( V_19 , V_383 , false , false ) ;
V_2 -> V_282 [ V_352 ] = V_60 ;
if ( V_2 -> V_44 )
F_158 ( V_19 , V_352 , false ) ;
if ( V_2 -> V_337 )
F_221 ( V_19 , V_60 ) ;
V_54 = F_198 ( V_19 , V_352 , V_60 ) ;
if ( ! V_54 )
return 0 ;
if ( V_54 -> V_93 )
return 0 ;
F_76 ( V_19 , V_54 , true , false ) ;
if ( V_2 -> V_356 )
V_2 -> V_356 ( V_19 , NULL , NULL ) ;
F_78 ( V_19 , V_383 ) ;
return 1 ;
}
static T_1 F_222 ( struct V_18 * V_19 , T_1 V_52 ,
int V_384 , int V_385 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_386 , V_114 = 0 ;
struct V_6 * V_54 ;
int V_90 ;
for ( V_90 = 0 ; V_90 < V_2 -> V_5 . V_17 ; V_90 ++ ) {
V_54 = F_24 ( & V_2 -> V_5 , V_90 ) ;
if ( ! V_54 -> V_55 )
continue;
if ( V_54 -> V_54 [ 0 ] == V_52 ||
V_54 -> V_54 [ V_54 -> V_55 - 1 ] == V_52 ) {
bool V_387 = V_54 -> V_95 ;
bool V_388 = V_54 -> V_94 ;
if ( V_384 >= 0 )
V_54 -> V_95 = V_384 ;
if ( V_385 >= 0 )
V_54 -> V_94 = V_385 ;
if ( ( ! V_54 -> V_96 && V_54 -> V_95 != V_387 )
|| V_54 -> V_94 != V_388 ) {
V_386 = F_70 ( V_19 , V_54 , true ) ;
if ( V_386 )
V_114 = V_386 ;
}
}
}
return V_114 ;
}
static bool F_223 ( struct V_18 * V_19 , T_1 V_48 )
{
if ( ! F_224 ( V_19 , V_48 ) )
return true ;
return F_225 ( V_19 , V_48 ) != V_389 ;
}
static T_1 F_226 ( struct V_18 * V_19 , T_1 V_48 ,
int V_116 )
{
bool V_390 ;
if ( ! V_19 -> V_30 )
return 0 ;
V_390 = F_223 ( V_19 , V_48 ) ;
if ( V_116 >= 0 && V_390 != V_116 )
return 0 ;
return F_222 ( V_19 , V_48 , V_390 , - 1 ) ;
}
static void F_227 ( struct V_18 * V_19 ,
struct V_391 * V_392 ,
bool V_390 )
{
if ( V_392 && V_392 -> V_52 )
F_74 ( V_19 ,
F_226 ( V_19 , V_392 -> V_52 , V_390 ) ) ;
}
static void F_228 ( struct V_18 * V_19 ,
struct V_391 * V_392 )
{
F_227 ( V_19 , V_392 , true ) ;
}
static void F_229 ( struct V_18 * V_19 ,
struct V_391 * V_392 )
{
F_227 ( V_19 , V_392 , false ) ;
}
static void F_230 ( struct V_18 * V_19 , int V_50 ,
const T_1 * V_51 , bool V_390 )
{
int V_16 ;
T_5 V_393 =
V_390 ? F_228 : F_229 ;
for ( V_16 = 0 ; V_16 < V_50 && V_51 [ V_16 ] ; V_16 ++ ) {
if ( F_224 ( V_19 , V_51 [ V_16 ] ) )
F_231 ( V_19 , V_51 [ V_16 ] , V_393 ) ;
else
F_222 ( V_19 , V_51 [ V_16 ] , true , - 1 ) ;
}
}
static void F_232 ( struct V_18 * V_19 , bool V_390 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_156 * V_157 = & V_2 -> V_158 ;
int V_16 ;
if ( ! V_19 -> V_30 )
return;
F_230 ( V_19 , V_157 -> V_159 , V_157 -> V_224 , V_390 ) ;
if ( V_157 -> V_171 != V_174 )
F_230 ( V_19 , V_157 -> V_162 , V_157 -> V_225 , V_390 ) ;
if ( V_157 -> V_171 != V_172 )
F_230 ( V_19 , V_157 -> V_163 , V_157 -> V_226 , V_390 ) ;
for ( V_16 = 0 ; V_16 < V_157 -> V_206 ; V_16 ++ )
F_230 ( V_19 , 1 , & V_157 -> V_207 [ V_16 ] . V_48 , V_390 ) ;
}
static void F_233 ( struct V_18 * V_19 , int V_50 ,
const T_1 * V_51 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_50 && V_51 [ V_16 ] ; V_16 ++ )
if ( F_224 ( V_19 , V_51 [ V_16 ] ) )
F_226 ( V_19 , V_51 [ V_16 ] , - 1 ) ;
}
static void F_234 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_156 * V_157 = & V_2 -> V_158 ;
int V_16 ;
if ( ! V_19 -> V_30 )
return;
F_233 ( V_19 , V_157 -> V_159 , V_157 -> V_224 ) ;
if ( V_157 -> V_171 != V_174 )
F_233 ( V_19 , V_157 -> V_162 , V_157 -> V_225 ) ;
if ( V_157 -> V_171 != V_172 )
F_233 ( V_19 , V_157 -> V_163 , V_157 -> V_226 ) ;
for ( V_16 = 0 ; V_16 < V_157 -> V_206 ; V_16 ++ )
F_233 ( V_19 , 1 , & V_157 -> V_207 [ V_16 ] . V_48 ) ;
}
static int F_235 ( struct V_18 * V_19 , T_1 V_52 ,
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
static int F_236 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_156 * V_157 = & V_2 -> V_158 ;
T_1 V_52 = V_2 -> V_394 ;
int V_148 ;
if ( ! V_19 -> V_30 || ! V_52 )
return 0 ;
V_148 = F_235 ( V_19 , V_52 , V_157 -> V_159 , V_157 -> V_224 ) ;
if ( V_148 < 0 )
return V_148 ;
if ( V_157 -> V_171 != V_174 ) {
V_148 = F_235 ( V_19 , V_52 , V_157 -> V_162 , V_157 -> V_225 ) ;
if ( V_148 < 0 )
return V_148 ;
}
if ( V_157 -> V_171 != V_172 ) {
V_148 = F_235 ( V_19 , V_52 , V_157 -> V_163 ,
V_157 -> V_226 ) ;
if ( V_148 < 0 )
return V_148 ;
}
return 0 ;
}
static void F_237 ( struct V_395 * V_396 , bool V_390 )
{
F_222 ( V_396 -> V_19 , V_396 -> V_52 , - 1 , V_390 ) ;
}
int F_238 ( struct V_18 * V_19 , T_1 V_48 )
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
static bool F_239 ( struct V_18 * V_19 , int V_50 , T_1 * V_51 )
{
int V_16 ;
bool V_397 = false ;
for ( V_16 = 0 ; V_16 < V_50 ; V_16 ++ ) {
T_1 V_52 = V_51 [ V_16 ] ;
if ( ! V_52 )
break;
if ( F_16 ( V_19 , V_52 ) & V_398 )
continue;
if ( F_225 ( V_19 , V_52 ) == V_399 )
V_397 = true ;
}
return V_397 ;
}
static void F_240 ( struct V_18 * V_19 , int V_50 , T_1 * V_51 ,
int * V_5 , bool V_400 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_50 ; V_16 ++ ) {
T_1 V_52 = V_51 [ V_16 ] ;
unsigned int V_20 , V_313 ;
if ( ! V_52 )
break;
V_313 = F_16 ( V_19 , V_52 ) ;
if ( V_313 & V_284 )
continue;
if ( V_2 -> V_34 ) {
struct V_6 * V_54 ;
T_1 V_401 ;
V_54 = F_26 ( V_19 , V_5 [ V_16 ] ) ;
if ( ! V_54 )
continue;
V_401 = F_83 ( V_54 -> V_62 [ V_107 ] ) ;
if ( ! V_401 )
continue;
if ( V_400 )
V_2 -> V_145 |= ( 1ULL << V_401 ) ;
else
V_2 -> V_145 &= ~ ( 1ULL << V_401 ) ;
continue;
} else {
if ( V_2 -> V_402 )
V_20 = V_313 & ~ V_243 ;
else
V_20 = 0 ;
if ( ! V_400 )
V_20 |= V_313 ;
F_15 ( V_19 , V_52 , V_20 ) ;
}
F_79 ( V_19 , V_52 , ! V_400 ) ;
if ( V_19 -> V_30 ) {
bool V_390 = ! V_400 ;
if ( V_390 )
V_390 = F_223 ( V_19 , V_52 ) ;
F_222 ( V_19 , V_52 , V_390 , - 1 ) ;
}
}
}
void F_241 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int * V_5 ;
int V_390 ;
if ( V_2 -> V_158 . V_171 == V_174 )
V_5 = V_2 -> V_211 ;
else
V_5 = V_2 -> V_173 ;
F_240 ( V_19 , F_105 ( V_2 -> V_158 . V_225 ) ,
V_2 -> V_158 . V_225 , V_5 , V_2 -> V_403 ) ;
if ( ! V_2 -> V_404 )
V_390 = 0 ;
else
V_390 = V_2 -> V_405 | V_2 -> V_406 ;
V_390 |= V_2 -> V_403 ;
V_2 -> V_407 = V_390 ;
if ( V_2 -> V_158 . V_171 == V_172 )
V_5 = V_2 -> V_211 ;
else
V_5 = V_2 -> V_175 ;
F_240 ( V_19 , F_105 ( V_2 -> V_158 . V_226 ) ,
V_2 -> V_158 . V_226 , V_5 , V_390 ) ;
if ( V_2 -> V_158 . V_224 [ 0 ] == V_2 -> V_158 . V_225 [ 0 ] ||
V_2 -> V_158 . V_224 [ 0 ] == V_2 -> V_158 . V_226 [ 0 ] )
return;
if ( ! V_2 -> V_408 )
V_390 = 0 ;
else
V_390 = V_2 -> V_405 ;
V_390 |= V_2 -> V_403 ;
V_2 -> V_409 = V_390 ;
V_5 = V_2 -> V_211 ;
F_240 ( V_19 , F_105 ( V_2 -> V_158 . V_224 ) ,
V_2 -> V_158 . V_224 , V_5 , V_390 ) ;
}
static void F_242 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_410 )
V_2 -> V_410 ( V_19 ) ;
else
F_241 ( V_19 ) ;
if ( V_2 -> V_34 && ! V_19 -> V_411 -> V_412 )
F_243 ( V_2 -> V_164 . V_413 , false ) ;
}
void F_244 ( struct V_18 * V_19 ,
struct V_391 * V_392 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 * V_51 = V_2 -> V_158 . V_225 ;
int V_50 = F_105 ( V_2 -> V_158 . V_225 ) ;
if ( V_2 -> V_251 ) {
V_51 ++ ;
V_50 -- ;
}
V_2 -> V_405 = F_239 ( V_19 , V_50 , V_51 ) ;
if ( ! V_2 -> V_414 || ( ! V_2 -> V_404 && ! V_2 -> V_408 ) )
return;
F_242 ( V_19 ) ;
}
void F_245 ( struct V_18 * V_19 ,
struct V_391 * V_392 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_158 . V_171 == V_172 )
return;
if ( V_2 -> V_158 . V_224 [ 0 ] == V_2 -> V_158 . V_225 [ 0 ] )
return;
V_2 -> V_406 =
F_239 ( V_19 , F_105 ( V_2 -> V_158 . V_224 ) ,
V_2 -> V_158 . V_224 ) ;
if ( ! V_2 -> V_404 || ! V_2 -> V_415 )
return;
F_242 ( V_19 ) ;
}
void F_246 ( struct V_18 * V_19 ,
struct V_391 * V_392 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
if ( ! V_2 -> V_367 )
return;
for ( V_16 = V_2 -> V_416 - 1 ; V_16 > 0 ; V_16 -- ) {
T_1 V_48 = V_2 -> V_417 [ V_16 ] . V_48 ;
if ( F_16 ( V_19 , V_48 ) & V_418 )
continue;
if ( F_225 ( V_19 , V_48 ) == V_399 ) {
F_204 ( V_19 , 0 , V_2 -> V_417 [ V_16 ] . V_60 ) ;
return;
}
}
F_204 ( V_19 , 0 , V_2 -> V_417 [ 0 ] . V_60 ) ;
}
static void F_143 ( struct V_18 * V_19 ,
struct V_391 * V_392 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_419 )
V_2 -> V_419 ( V_19 , V_392 ) ;
else
F_244 ( V_19 , V_392 ) ;
}
static void F_247 ( struct V_18 * V_19 ,
struct V_391 * V_392 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_420 )
V_2 -> V_420 ( V_19 , V_392 ) ;
else
F_245 ( V_19 , V_392 ) ;
}
static void F_248 ( struct V_18 * V_19 ,
struct V_391 * V_392 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_421 )
V_2 -> V_421 ( V_19 , V_392 ) ;
else
F_246 ( V_19 , V_392 ) ;
}
static void F_150 ( struct V_18 * V_19 )
{
F_143 ( V_19 , NULL ) ;
F_247 ( V_19 , NULL ) ;
F_248 ( V_19 , NULL ) ;
}
static int F_249 ( struct V_140 * V_141 ,
struct V_247 * V_248 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
static const char * const V_422 [] = {
L_86 , L_87 , L_88
} ;
if ( V_2 -> V_423 && V_2 -> V_424 )
return F_164 ( V_141 , V_248 , 3 , V_422 ) ;
return F_139 ( V_141 , V_248 ) ;
}
static int F_250 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_20 = 0 ;
if ( V_2 -> V_404 )
V_20 ++ ;
if ( V_2 -> V_408 )
V_20 ++ ;
V_143 -> V_146 . V_249 . V_250 [ 0 ] = V_20 ;
return 0 ;
}
static int F_251 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_18 * V_19 = F_94 ( V_141 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
switch ( V_143 -> V_146 . V_249 . V_250 [ 0 ] ) {
case 0 :
if ( ! V_2 -> V_404 && ! V_2 -> V_408 )
return 0 ;
V_2 -> V_404 = 0 ;
V_2 -> V_408 = 0 ;
break;
case 1 :
if ( V_2 -> V_423 ) {
if ( ! V_2 -> V_408 && V_2 -> V_404 )
return 0 ;
V_2 -> V_404 = 1 ;
V_2 -> V_408 = 0 ;
} else if ( V_2 -> V_424 ) {
if ( V_2 -> V_408 )
return 0 ;
V_2 -> V_408 = 1 ;
} else
return - V_266 ;
break;
case 2 :
if ( ! V_2 -> V_424 || ! V_2 -> V_423 )
return - V_266 ;
if ( V_2 -> V_404 && V_2 -> V_408 )
return 0 ;
V_2 -> V_404 = 1 ;
V_2 -> V_408 = 1 ;
break;
default:
return - V_266 ;
}
F_242 ( V_19 ) ;
return 1 ;
}
static int F_252 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! F_4 ( V_2 , NULL , & V_425 ) )
return - V_136 ;
return 0 ;
}
static int F_253 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_156 * V_157 = & V_2 -> V_158 ;
int V_397 = 0 ;
int V_16 , V_148 ;
if ( V_2 -> V_31 )
return 0 ;
if ( V_157 -> V_225 [ 0 ] )
V_397 ++ ;
if ( V_157 -> V_224 [ 0 ] )
V_397 ++ ;
if ( V_157 -> V_226 [ 0 ] )
V_397 ++ ;
if ( V_397 < 2 )
return 0 ;
if ( ! V_157 -> V_226 [ 0 ] &&
V_157 -> V_171 == V_172 ) {
memcpy ( V_157 -> V_226 , V_157 -> V_224 ,
sizeof( V_157 -> V_226 ) ) ;
V_157 -> V_163 = V_157 -> V_159 ;
}
if ( ! V_157 -> V_225 [ 0 ] &&
V_157 -> V_171 == V_174 ) {
memcpy ( V_157 -> V_225 , V_157 -> V_224 ,
sizeof( V_157 -> V_225 ) ) ;
V_157 -> V_162 = V_157 -> V_159 ;
}
for ( V_16 = 0 ; V_16 < V_157 -> V_162 ; V_16 ++ ) {
T_1 V_52 = V_157 -> V_225 [ V_16 ] ;
if ( ! F_224 ( V_19 , V_52 ) )
continue;
F_35 ( V_19 , L_89 , V_52 ) ;
F_231 ( V_19 , V_52 ,
F_143 ) ;
V_2 -> V_414 = 1 ;
}
if ( V_157 -> V_171 == V_176 && V_157 -> V_159 ) {
if ( V_157 -> V_163 )
for ( V_16 = 0 ; V_16 < V_157 -> V_159 ; V_16 ++ ) {
T_1 V_52 = V_157 -> V_224 [ V_16 ] ;
if ( ! F_224 ( V_19 , V_52 ) )
continue;
F_35 ( V_19 , L_90 , V_52 ) ;
F_231 ( V_19 , V_52 ,
F_247 ) ;
V_2 -> V_415 = 1 ;
}
V_2 -> V_424 = V_2 -> V_414 ;
}
V_2 -> V_423 = V_157 -> V_163 &&
( V_2 -> V_414 || V_2 -> V_415 ) ;
V_2 -> V_408 = V_2 -> V_424 ;
V_2 -> V_404 = V_2 -> V_423 ;
if ( V_2 -> V_423 || V_2 -> V_424 ) {
V_148 = F_252 ( V_19 ) ;
if ( V_148 < 0 )
return V_148 ;
}
return 0 ;
}
static bool F_254 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
const struct V_331 * V_332 ;
int V_16 ;
V_332 = & V_2 -> V_333 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_416 ; V_16 ++ ) {
V_2 -> V_417 [ V_16 ] . V_60 =
F_21 ( V_2 -> V_417 [ V_16 ] . V_48 ,
V_2 -> V_346 , V_332 -> V_335 ) ;
if ( V_2 -> V_417 [ V_16 ] . V_60 < 0 )
return false ;
}
for ( V_16 = 1 ; V_16 < V_2 -> V_416 ; V_16 ++ )
F_231 ( V_19 ,
V_2 -> V_417 [ V_16 ] . V_48 ,
F_248 ) ;
return true ;
}
static int F_255 ( const void * V_426 , const void * V_427 )
{
const struct V_428 * V_429 = V_426 ;
const struct V_428 * V_430 = V_427 ;
return ( int ) ( V_429 -> V_431 - V_430 -> V_431 ) ;
}
static int F_256 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_156 * V_157 = & V_2 -> V_158 ;
unsigned int V_432 ;
int V_16 , V_50 ;
if ( V_2 -> V_32 )
return 0 ;
V_432 = 0 ;
V_50 = 0 ;
for ( V_16 = 0 ; V_16 < V_157 -> V_206 ; V_16 ++ ) {
T_1 V_52 = V_157 -> V_207 [ V_16 ] . V_48 ;
unsigned int V_431 ;
V_431 = F_113 ( V_19 , V_52 ) ;
V_431 = F_162 ( V_431 ) ;
if ( V_432 & ( 1 << V_431 ) )
return 0 ;
switch ( V_431 ) {
case V_290 :
if ( V_157 -> V_207 [ V_16 ] . type != V_205 )
return 0 ;
break;
case V_433 :
return 0 ;
default:
if ( V_157 -> V_207 [ V_16 ] . type > V_204 )
return 0 ;
if ( ! V_2 -> V_33 &&
V_157 -> V_207 [ V_16 ] . type != V_205 )
return 0 ;
if ( ! F_224 ( V_19 , V_52 ) )
return 0 ;
break;
}
if ( V_50 >= V_434 )
return 0 ;
V_432 |= ( 1 << V_431 ) ;
V_2 -> V_417 [ V_50 ] . V_48 = V_52 ;
V_2 -> V_417 [ V_50 ] . V_431 = V_431 ;
V_50 ++ ;
}
if ( V_50 < 2 )
return 0 ;
V_2 -> V_416 = V_50 ;
F_257 ( V_2 -> V_417 , V_50 , sizeof( V_2 -> V_417 [ 0 ] ) ,
F_255 , NULL ) ;
if ( ! F_254 ( V_19 ) )
return 0 ;
V_2 -> V_367 = 1 ;
V_2 -> V_328 = 1 ;
V_2 -> V_282 [ 0 ] = V_2 -> V_417 [ 0 ] . V_60 ;
F_35 ( V_19 , L_91 ,
V_2 -> V_417 [ 0 ] . V_48 ,
V_2 -> V_417 [ 1 ] . V_48 ,
V_2 -> V_417 [ 2 ] . V_48 ) ;
return 0 ;
}
unsigned int F_258 ( struct V_18 * V_19 ,
T_1 V_52 ,
unsigned int V_435 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_43 && ! V_19 -> V_30 )
return V_435 ;
if ( V_435 != V_118 || V_52 == V_19 -> V_91 . V_92 )
return V_435 ;
if ( F_38 ( F_39 ( V_19 , V_52 ) ) >= V_436 )
return V_435 ;
if ( F_71 ( V_19 , V_52 ) )
return V_435 ;
return V_119 ;
}
static void F_259 ( struct V_18 * V_19 , T_1 V_315 )
{
int V_16 , V_53 ;
const T_1 * V_67 ;
bool V_437 ;
V_53 = F_37 ( V_19 , V_315 , & V_67 ) ;
V_437 = F_49 ( V_19 , V_315 , V_85 ) ;
for ( V_16 = 0 ; V_16 < V_53 ; V_16 ++ ) {
if ( V_437 )
F_62 ( V_19 , V_315 , V_85 , V_16 ,
0xff , V_103 ) ;
else if ( F_51 ( V_19 , V_67 [ V_16 ] , V_84 ) )
F_62 ( V_19 , V_67 [ V_16 ] , V_84 , 0 ,
0xff , V_103 ) ;
}
}
void F_260 ( struct V_18 * V_19 , T_1 V_52 , bool V_390 )
{
if ( V_19 -> V_30 )
F_222 ( V_19 , V_52 , - 1 , V_390 ) ;
}
int F_261 ( struct V_18 * V_19 ,
struct V_156 * V_157 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_148 ;
F_11 ( V_19 ) ;
if ( V_2 -> V_47 && ! V_2 -> V_112 )
V_2 -> V_112 = V_2 -> V_47 ;
if ( V_157 != & V_2 -> V_158 ) {
V_2 -> V_158 = * V_157 ;
V_157 = & V_2 -> V_158 ;
}
if ( ! V_2 -> V_227 )
V_2 -> V_227 = & V_438 ;
if ( ! V_2 -> V_228 )
V_2 -> V_228 = & V_439 ;
F_127 ( V_19 ) ;
if ( ! V_157 -> V_159 ) {
if ( V_157 -> V_376 || V_157 -> V_381 ) {
V_2 -> V_166 . V_268 = 2 ;
V_2 -> V_440 = 1 ;
goto V_441;
}
if ( ! V_157 -> V_206 && ! V_157 -> V_381 )
return 0 ;
}
if ( ! V_2 -> V_36 &&
V_157 -> V_171 == V_172 &&
V_157 -> V_159 <= V_157 -> V_162 ) {
V_157 -> V_163 = V_157 -> V_159 ;
memcpy ( V_157 -> V_226 , V_157 -> V_224 ,
sizeof( V_157 -> V_226 ) ) ;
V_157 -> V_159 = V_157 -> V_162 ;
memcpy ( V_157 -> V_224 , V_157 -> V_225 , sizeof( V_157 -> V_225 ) ) ;
V_157 -> V_162 = 0 ;
memset ( V_157 -> V_225 , 0 , sizeof( V_157 -> V_225 ) ) ;
V_157 -> V_171 = V_174 ;
}
V_148 = F_130 ( V_19 ) ;
if ( V_148 < 0 )
return V_148 ;
V_148 = F_153 ( V_19 ) ;
if ( V_148 < 0 )
return V_148 ;
V_148 = F_133 ( V_19 , V_157 ) ;
if ( V_148 < 0 )
return V_148 ;
V_148 = F_136 ( V_19 ) ;
if ( V_148 < 0 )
return V_148 ;
V_148 = F_137 ( V_19 ) ;
if ( V_148 < 0 )
return V_148 ;
V_148 = F_144 ( V_19 ) ;
if ( V_148 < 0 )
return V_148 ;
V_148 = F_157 ( V_19 ) ;
if ( V_148 < 0 )
return V_148 ;
V_148 = F_161 ( V_19 ) ;
if ( V_148 < 0 )
return V_148 ;
V_148 = F_197 ( V_19 ) ;
if ( V_148 < 0 )
return V_148 ;
F_232 ( V_19 , false ) ;
V_2 -> V_269 = V_2 -> V_229 ;
if ( V_157 -> V_171 != V_172 )
V_2 -> V_269 = F_152 ( V_2 -> V_269 ,
V_157 -> V_163 * 2 ) ;
if ( V_157 -> V_171 != V_174 )
V_2 -> V_269 = F_152 ( V_2 -> V_269 ,
V_157 -> V_162 * 2 ) ;
V_2 -> V_166 . V_268 = F_152 ( V_2 -> V_229 ,
V_2 -> V_269 ) ;
V_148 = F_253 ( V_19 ) ;
if ( V_148 < 0 )
return V_148 ;
V_148 = F_192 ( V_19 ) ;
if ( V_148 < 0 )
return V_148 ;
V_148 = F_256 ( V_19 ) ;
if ( V_148 < 0 )
return V_148 ;
if ( ! V_2 -> V_367 && V_2 -> V_47 &&
V_2 -> V_41 == V_442 &&
V_2 -> V_333 . V_335 > 1 ) {
V_148 = F_193 ( V_19 , V_2 -> V_47 ,
V_351 , V_2 -> V_329 ,
L_74 , 0 ) ;
if ( V_148 < 0 )
return V_148 ;
}
V_148 = F_216 ( V_19 ) ;
if ( V_148 < 0 )
return V_148 ;
V_148 = F_219 ( V_19 ) ;
if ( V_148 < 0 )
return V_148 ;
if ( V_2 -> V_281 &&
( V_2 -> V_367 || V_2 -> V_333 . V_335 == 1 ||
V_2 -> V_42 ) ) {
V_148 = F_186 ( V_19 , V_2 -> V_281 ) ;
if ( V_148 < 0 )
return V_148 ;
}
if ( V_2 -> V_42 ) {
if ( V_157 -> V_171 != V_172 ) {
V_148 = F_172 ( V_19 , V_157 -> V_159 ,
V_157 -> V_224 ) ;
if ( V_148 < 0 )
return V_148 ;
}
if ( V_157 -> V_171 != V_174 ) {
V_148 = F_172 ( V_19 , V_157 -> V_162 ,
V_157 -> V_225 ) ;
if ( V_148 < 0 )
return V_148 ;
}
}
F_232 ( V_19 , true ) ;
if ( V_2 -> V_47 )
F_259 ( V_19 , V_2 -> V_47 ) ;
V_441:
F_220 ( V_19 ) ;
if ( V_2 -> V_43 || V_19 -> V_30 ) {
if ( ! V_19 -> V_443 )
V_19 -> V_443 = F_258 ;
if ( ! V_19 -> V_444 . V_445 )
V_19 -> V_444 . V_445 = F_260 ;
}
if ( ! V_2 -> V_440 && V_2 -> V_394 ) {
V_148 = F_262 ( V_19 , V_2 -> V_394 ) ;
if ( V_148 < 0 )
return V_148 ;
if ( V_19 -> V_396 && V_19 -> V_30 ) {
V_148 = F_236 ( V_19 ) ;
if ( V_148 < 0 )
return V_148 ;
V_19 -> V_396 -> V_446 = F_237 ;
}
}
return 1 ;
}
int F_263 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_148 ;
if ( V_2 -> V_3 . V_17 ) {
V_148 = F_264 ( V_19 , V_2 -> V_3 . V_14 ) ;
if ( V_148 < 0 )
return V_148 ;
}
if ( V_2 -> V_166 . V_378 ) {
V_148 = F_265 ( V_19 ,
V_2 -> V_166 . V_378 ,
V_2 -> V_166 . V_378 ,
V_2 -> V_447 [ 1 ] -> V_448 ) ;
if ( V_148 < 0 )
return V_148 ;
if ( ! V_2 -> V_440 ) {
V_148 = F_266 ( V_19 ,
& V_2 -> V_166 ) ;
if ( V_148 < 0 )
return V_148 ;
V_2 -> V_166 . V_449 = 1 ;
}
}
if ( V_2 -> V_382 ) {
V_148 = F_267 ( V_19 , V_2 -> V_382 ) ;
if ( V_148 < 0 )
return V_148 ;
}
if ( ! V_2 -> V_440 && ! V_2 -> V_46 &&
! F_268 ( V_19 , L_92 ) ) {
V_148 = F_269 ( V_19 , L_92 ,
V_2 -> V_240 , V_450 ,
L_93 ) ;
if ( V_148 < 0 )
return V_148 ;
}
if ( ! V_2 -> V_440 && ! V_2 -> V_46 &&
! F_268 ( V_19 , L_94 ) ) {
V_148 = F_270 ( V_19 , L_94 ,
NULL , V_450 ,
L_95 ,
true , & V_2 -> V_164 . V_413 ) ;
if ( V_148 < 0 )
return V_148 ;
if ( V_2 -> V_164 . V_165 ) {
F_271 ( V_19 , & V_2 -> V_164 ,
V_2 -> V_451 ) ;
F_272 ( & V_2 -> V_164 ) ;
}
}
F_7 ( V_2 ) ;
V_148 = F_273 ( V_19 , & V_2 -> V_158 ) ;
if ( V_148 < 0 )
return V_148 ;
return 0 ;
}
static void F_274 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
struct V_454 * V_455 ,
int V_456 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_457 )
V_2 -> V_457 ( V_453 , V_19 , V_455 , V_456 ) ;
}
static void F_275 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
struct V_454 * V_455 ,
int V_456 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_458 )
V_2 -> V_458 ( V_453 , V_19 , V_455 , V_456 ) ;
}
static int F_276 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
struct V_454 * V_455 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_148 ;
F_99 ( & V_2 -> V_9 ) ;
V_148 = F_277 ( V_19 ,
& V_2 -> V_166 , V_455 ,
V_453 ) ;
if ( ! V_148 ) {
V_2 -> V_254 |= 1 << V_459 ;
F_274 ( V_453 , V_19 , V_455 ,
V_460 ) ;
}
F_101 ( & V_2 -> V_9 ) ;
return V_148 ;
}
static int F_278 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
unsigned int V_461 ,
unsigned int V_462 ,
struct V_454 * V_455 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_148 ;
V_148 = F_279 ( V_19 , & V_2 -> V_166 ,
V_461 , V_462 , V_455 ) ;
if ( ! V_148 )
F_274 ( V_453 , V_19 , V_455 ,
V_463 ) ;
return V_148 ;
}
static int F_280 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
struct V_454 * V_455 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_148 ;
V_148 = F_281 ( V_19 , & V_2 -> V_166 ) ;
if ( ! V_148 )
F_274 ( V_453 , V_19 , V_455 ,
V_464 ) ;
return V_148 ;
}
static int F_282 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
struct V_454 * V_455 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_99 ( & V_2 -> V_9 ) ;
V_2 -> V_254 &= ~ ( 1 << V_459 ) ;
F_274 ( V_453 , V_19 , V_455 ,
V_465 ) ;
F_101 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_283 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
struct V_454 * V_455 )
{
F_275 ( V_453 , V_19 , V_455 , V_460 ) ;
return 0 ;
}
static int F_284 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
unsigned int V_461 ,
unsigned int V_462 ,
struct V_454 * V_455 )
{
F_285 ( V_19 , V_453 -> V_52 , V_461 , 0 , V_462 ) ;
F_275 ( V_453 , V_19 , V_455 ,
V_463 ) ;
return 0 ;
}
static int F_286 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
struct V_454 * V_455 )
{
F_287 ( V_19 , V_453 -> V_52 ) ;
F_275 ( V_453 , V_19 , V_455 ,
V_464 ) ;
return 0 ;
}
static int F_288 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
struct V_454 * V_455 )
{
F_275 ( V_453 , V_19 , V_455 , V_465 ) ;
return 0 ;
}
static int F_289 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
struct V_454 * V_455 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_148 = 0 ;
F_99 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_40 && ! V_2 -> V_251 )
V_148 = - V_255 ;
else
V_2 -> V_254 |= 1 << V_466 ;
F_274 ( V_453 , V_19 , V_455 ,
V_460 ) ;
F_101 ( & V_2 -> V_9 ) ;
return V_148 ;
}
static int F_290 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
struct V_454 * V_455 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_99 ( & V_2 -> V_9 ) ;
V_2 -> V_254 &= ~ ( 1 << V_466 ) ;
F_274 ( V_453 , V_19 , V_455 ,
V_465 ) ;
F_101 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_291 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
unsigned int V_461 ,
unsigned int V_462 ,
struct V_454 * V_455 )
{
F_285 ( V_19 , V_453 -> V_52 , V_461 , 0 , V_462 ) ;
F_274 ( V_453 , V_19 , V_455 ,
V_463 ) ;
return 0 ;
}
static int F_292 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
struct V_454 * V_455 )
{
F_287 ( V_19 , V_453 -> V_52 ) ;
F_274 ( V_453 , V_19 , V_455 ,
V_464 ) ;
return 0 ;
}
static int F_293 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
struct V_454 * V_455 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_294 ( V_19 , & V_2 -> V_166 ) ;
}
static int F_295 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
unsigned int V_461 ,
unsigned int V_462 ,
struct V_454 * V_455 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_296 ( V_19 , & V_2 -> V_166 ,
V_461 , V_462 , V_455 ) ;
}
static int F_297 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
struct V_454 * V_455 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_298 ( V_19 , & V_2 -> V_166 ) ;
}
static int F_299 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
struct V_454 * V_455 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_300 ( V_19 , & V_2 -> V_166 ) ;
}
static int F_301 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
unsigned int V_461 ,
unsigned int V_462 ,
struct V_454 * V_455 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_285 ( V_19 , V_2 -> V_326 [ V_455 -> V_467 + 1 ] ,
V_461 , 0 , V_462 ) ;
F_275 ( V_453 , V_19 , V_455 ,
V_463 ) ;
return 0 ;
}
static int F_302 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
struct V_454 * V_455 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_287 ( V_19 ,
V_2 -> V_326 [ V_455 -> V_467 + 1 ] ) ;
F_275 ( V_453 , V_19 , V_455 ,
V_464 ) ;
return 0 ;
}
static bool F_221 ( struct V_18 * V_19 , int V_468 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_469 = V_2 -> V_326 [ V_2 -> V_336 [ V_468 ] ] ;
if ( V_2 -> V_470 && V_2 -> V_470 != V_469 ) {
F_303 ( V_19 , V_2 -> V_470 , 1 ) ;
V_2 -> V_470 = V_469 ;
F_285 ( V_19 , V_469 ,
V_2 -> V_471 , 0 ,
V_2 -> V_472 ) ;
return true ;
}
return false ;
}
static int F_304 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
unsigned int V_461 ,
unsigned int V_462 ,
struct V_454 * V_455 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
V_2 -> V_470 = V_2 -> V_326 [ V_2 -> V_336 [ V_2 -> V_282 [ 0 ] ] ] ;
V_2 -> V_471 = V_461 ;
V_2 -> V_472 = V_462 ;
F_285 ( V_19 , V_2 -> V_470 , V_461 , 0 , V_462 ) ;
F_275 ( V_453 , V_19 , V_455 , V_463 ) ;
return 0 ;
}
static int F_305 ( struct V_452 * V_453 ,
struct V_18 * V_19 ,
struct V_454 * V_455 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_287 ( V_19 , V_2 -> V_470 ) ;
V_2 -> V_470 = 0 ;
F_275 ( V_453 , V_19 , V_455 , V_464 ) ;
return 0 ;
}
static void F_306 ( char * V_473 , T_3 V_474 , const char * V_134 ,
const char * V_475 )
{
char * V_476 ;
if ( * V_473 )
return;
F_307 ( V_473 , V_475 , V_474 ) ;
for ( V_476 = strchr ( V_473 , ' ' ) ; V_476 ; V_476 = strchr ( V_476 + 1 , ' ' ) ) {
if ( ! isalnum ( V_476 [ 1 ] ) ) {
* V_476 = 0 ;
break;
}
}
F_170 ( V_473 , V_134 , V_474 ) ;
}
static void F_308 ( struct V_452 * V_473 ,
const struct V_452 * V_477 ,
const struct V_452 * V_478 ,
T_1 V_52 )
{
* V_473 = * V_477 ;
if ( V_52 )
V_473 -> V_52 = V_52 ;
if ( V_478 ) {
if ( V_478 -> V_479 )
V_473 -> V_479 = V_478 -> V_479 ;
if ( V_478 -> V_480 )
V_473 -> V_480 = V_478 -> V_480 ;
if ( V_478 -> V_481 )
V_473 -> V_481 = V_478 -> V_481 ;
if ( V_478 -> V_482 )
V_473 -> V_482 = V_478 -> V_482 ;
if ( V_478 -> V_483 )
V_473 -> V_483 = V_478 -> V_483 ;
if ( V_478 -> V_484 )
V_473 -> V_484 = V_478 -> V_484 ;
}
}
int F_309 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_485 * V_486 ;
bool V_487 ;
if ( V_2 -> V_440 )
goto V_488;
F_306 ( V_2 -> V_489 ,
sizeof( V_2 -> V_489 ) ,
L_96 , V_19 -> V_91 . V_475 ) ;
V_486 = F_310 ( V_19 , L_97 , V_2 -> V_489 ) ;
if ( ! V_486 )
return - V_136 ;
V_2 -> V_447 [ 0 ] = V_486 ;
if ( V_2 -> V_166 . V_167 > 0 ) {
F_308 ( & V_486 -> V_490 [ V_491 ] ,
& V_492 ,
V_2 -> V_493 ,
V_2 -> V_166 . V_218 [ 0 ] ) ;
V_486 -> V_490 [ V_491 ] . V_481 =
V_2 -> V_166 . V_268 ;
if ( V_2 -> V_158 . V_171 == V_172 &&
V_2 -> V_158 . V_159 == 2 )
V_486 -> V_490 [ V_491 ] . V_494 =
V_495 ;
}
if ( V_2 -> V_328 ) {
F_308 ( & V_486 -> V_490 [ V_496 ] ,
( V_2 -> V_337 ?
& V_497 : & V_498 ) ,
V_2 -> V_499 ,
V_2 -> V_326 [ 0 ] ) ;
}
V_488:
if ( V_2 -> V_166 . V_378 || V_2 -> V_382 ) {
F_306 ( V_2 -> V_500 ,
sizeof( V_2 -> V_500 ) ,
L_98 , V_19 -> V_91 . V_475 ) ;
V_486 = F_310 ( V_19 , L_97 ,
V_2 -> V_500 ) ;
if ( ! V_486 )
return - V_136 ;
V_19 -> V_380 = V_2 -> V_166 . V_380 ;
V_2 -> V_447 [ 1 ] = V_486 ;
if ( V_2 -> V_379 )
V_486 -> V_448 = V_2 -> V_379 ;
else
V_486 -> V_448 = V_501 ;
if ( V_2 -> V_166 . V_378 )
F_308 ( & V_486 -> V_490 [ V_491 ] ,
& V_502 ,
V_2 -> V_503 ,
V_2 -> V_166 . V_378 ) ;
if ( V_2 -> V_382 )
F_308 ( & V_486 -> V_490 [ V_496 ] ,
& V_504 ,
V_2 -> V_505 ,
V_2 -> V_382 ) ;
}
if ( V_2 -> V_440 )
return 0 ;
V_487 = ( V_2 -> V_328 > 1 ) &&
! V_2 -> V_337 && ! V_2 -> V_367 ;
if ( V_2 -> V_260 || V_487 ) {
F_306 ( V_2 -> V_506 ,
sizeof( V_2 -> V_506 ) ,
L_99 , V_19 -> V_91 . V_475 ) ;
V_486 = F_310 ( V_19 , L_97 ,
V_2 -> V_506 ) ;
if ( ! V_486 )
return - V_136 ;
V_2 -> V_447 [ 2 ] = V_486 ;
if ( V_2 -> V_260 )
F_308 ( & V_486 -> V_490 [ V_491 ] ,
& V_507 ,
V_2 -> V_508 ,
V_2 -> V_260 ) ;
else
F_308 ( & V_486 -> V_490 [ V_491 ] ,
& V_509 , NULL , 0 ) ;
if ( V_487 ) {
F_308 ( & V_486 -> V_490 [ V_496 ] ,
& V_510 ,
V_2 -> V_511 ,
V_2 -> V_326 [ 1 ] ) ;
V_486 -> V_490 [ V_496 ] . V_479 =
V_2 -> V_328 - 1 ;
} else {
F_308 ( & V_486 -> V_490 [ V_496 ] ,
& V_509 , NULL , 0 ) ;
}
}
return 0 ;
}
static void F_311 ( struct V_18 * V_19 , int V_127 )
{
struct V_6 * V_54 ;
T_1 V_48 ;
V_54 = F_26 ( V_19 , V_127 ) ;
if ( ! V_54 || ! V_54 -> V_55 )
return;
V_48 = V_54 -> V_54 [ V_54 -> V_55 - 1 ] ;
F_14 ( V_19 , V_48 ) ;
F_76 ( V_19 , V_54 , V_54 -> V_93 ,
F_148 ( V_19 -> V_2 ) ) ;
F_79 ( V_19 , V_48 , V_54 -> V_93 ) ;
}
static void F_312 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_158 . V_159 ; V_16 ++ )
F_311 ( V_19 , V_2 -> V_211 [ V_16 ] ) ;
}
static void F_313 ( struct V_18 * V_19 , int V_187 , int * V_5 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_187 ; V_16 ++ )
F_311 ( V_19 , V_5 [ V_16 ] ) ;
}
static void F_314 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_158 . V_171 != V_174 )
F_313 ( V_19 , V_2 -> V_158 . V_162 , V_2 -> V_173 ) ;
if ( V_2 -> V_158 . V_171 != V_172 )
F_313 ( V_19 , V_2 -> V_158 . V_163 ,
V_2 -> V_175 ) ;
}
static void F_315 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_160 ; V_16 ++ ) {
T_1 V_48 = V_2 -> V_185 [ V_16 ] . V_48 ;
struct V_6 * V_54 ;
V_54 = F_147 ( V_19 , V_16 ) ;
if ( ! V_54 )
continue;
if ( ! V_2 -> V_185 [ V_16 ] . V_267 )
V_2 -> V_185 [ V_16 ] . V_267 =
F_16 ( V_19 , V_48 ) ;
F_76 ( V_19 , V_54 , V_54 -> V_93 ,
F_148 ( V_2 ) ) ;
}
}
static void F_316 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_2 -> V_258 )
return;
if ( ! F_119 ( V_2 ) )
return;
F_142 ( V_19 , V_2 -> V_259 , V_2 -> V_211 [ 0 ] ,
V_2 -> V_214 [ 0 ] ,
V_2 -> V_158 . V_171 ) ;
F_142 ( V_19 , V_2 -> V_259 , V_2 -> V_173 [ 0 ] ,
V_2 -> V_214 [ 1 ] ,
V_174 ) ;
F_142 ( V_19 , V_2 -> V_259 , V_2 -> V_175 [ 0 ] ,
V_2 -> V_214 [ 2 ] ,
V_172 ) ;
}
static void F_317 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_156 * V_157 = & V_2 -> V_158 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_157 -> V_206 ; V_16 ++ ) {
T_1 V_52 = V_157 -> V_207 [ V_16 ] . V_48 ;
if ( F_190 ( V_19 , V_52 ) )
F_14 ( V_19 , V_52 ) ;
if ( V_2 -> V_47 ) {
F_81 ( V_19 , V_2 -> V_221 [ V_16 ] ) ;
F_81 ( V_19 , V_2 -> V_325 ) ;
}
}
}
static void F_318 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_331 * V_332 = & V_2 -> V_333 ;
struct V_6 * V_54 ;
int V_16 , V_344 , V_53 ;
if ( V_2 -> V_337 )
V_53 = 1 ;
else
V_53 = V_2 -> V_328 ;
for ( V_344 = 0 ; V_344 < V_53 ; V_344 ++ ) {
for ( V_16 = 0 ; V_16 < V_332 -> V_335 ; V_16 ++ ) {
V_54 = F_198 ( V_19 , V_344 , V_16 ) ;
if ( V_54 ) {
bool V_93 = V_54 -> V_93 ;
if ( V_16 == V_2 -> V_282 [ V_344 ] )
V_93 = true ;
F_76 ( V_19 , V_54 , V_93 , false ) ;
}
}
if ( V_2 -> V_44 )
F_158 ( V_19 , V_344 , true ) ;
}
if ( V_2 -> V_356 )
V_2 -> V_356 ( V_19 , NULL , NULL ) ;
}
static void F_319 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_16 ;
T_1 V_48 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_158 . V_376 ; V_16 ++ )
F_311 ( V_19 , V_2 -> V_219 [ V_16 ] ) ;
V_48 = V_2 -> V_158 . V_381 ;
if ( V_48 ) {
F_14 ( V_19 , V_48 ) ;
F_81 ( V_19 , V_2 -> V_222 ) ;
}
}
static void F_320 ( struct V_18 * V_19 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_19 -> V_512 . V_17 ; V_16 ++ ) {
struct V_513 * V_48 = F_24 ( & V_19 -> V_512 , V_16 ) ;
T_1 V_52 = V_48 -> V_52 ;
if ( F_224 ( V_19 , V_52 ) &&
! F_321 ( V_19 , V_52 ) )
F_77 ( V_19 , V_52 , 0 ,
V_514 , 0 ) ;
}
}
int F_322 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_515 )
V_2 -> V_515 ( V_19 ) ;
F_323 ( V_19 ) ;
F_312 ( V_19 ) ;
F_314 ( V_19 ) ;
F_315 ( V_19 ) ;
F_316 ( V_19 ) ;
F_317 ( V_19 ) ;
F_318 ( V_19 ) ;
F_319 ( V_19 ) ;
F_320 ( V_19 ) ;
F_234 ( V_19 ) ;
F_150 ( V_19 ) ;
F_324 ( V_19 -> V_91 . V_516 ) ;
if ( V_2 -> V_164 . V_413 && V_2 -> V_164 . V_165 )
F_272 ( & V_2 -> V_164 ) ;
F_325 ( V_19 , 0x01 ) ;
return 0 ;
}
void F_326 ( struct V_18 * V_19 )
{
F_327 ( V_19 , V_517 ) ;
F_10 ( V_19 -> V_2 ) ;
F_8 ( V_19 -> V_2 ) ;
V_19 -> V_2 = NULL ;
}
int F_328 ( struct V_18 * V_19 , T_1 V_52 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_329 ( V_19 , & V_2 -> V_316 , V_52 ) ;
}
static int F_330 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_148 ;
V_2 = F_331 ( sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 )
return - V_136 ;
F_1 ( V_2 ) ;
V_19 -> V_2 = V_2 ;
V_148 = F_332 ( V_19 , & V_2 -> V_158 , NULL , 0 ) ;
if ( V_148 < 0 )
return V_148 ;
V_148 = F_261 ( V_19 , & V_2 -> V_158 ) ;
if ( V_148 < 0 )
goto error;
V_19 -> V_444 = V_518 ;
return 0 ;
error:
F_326 ( V_19 ) ;
return V_148 ;
}
