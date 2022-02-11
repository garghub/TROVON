bool F_1 ( void ) {
return V_1 . V_2 ;
}
bool F_2 ( void ) {
return V_1 . V_3 . V_4 . V_5 ;
}
bool F_3 ( void ) {
return V_1 . V_3 . V_6 ;
}
bool F_4 ( void ) {
return V_1 . V_3 . V_7 ;
}
static union V_8 * F_5 ( T_1 V_9 , int V_10 ,
struct V_11 * V_12 )
{
T_2 V_13 ;
union V_8 V_14 [ 2 ] ;
struct V_15 V_16 ;
struct V_11 V_17 = { V_18 , NULL } ;
V_16 . V_19 = 2 ;
V_16 . V_20 = & V_14 [ 0 ] ;
V_14 [ 0 ] . type = V_21 ;
V_14 [ 0 ] . integer . V_22 = V_10 ;
if ( V_12 ) {
V_14 [ 1 ] . type = V_23 ;
V_14 [ 1 ] . V_17 . V_24 = V_12 -> V_24 ;
V_14 [ 1 ] . V_17 . V_20 = V_12 -> V_20 ;
} else {
V_14 [ 1 ] . type = V_21 ;
V_14 [ 1 ] . integer . V_22 = 0 ;
}
V_13 = F_6 ( V_9 , NULL , & V_16 , & V_17 ) ;
if ( F_7 ( V_13 ) && V_13 != V_25 ) {
F_8 ( L_1 ,
F_9 ( V_13 ) ) ;
F_10 ( V_17 . V_20 ) ;
return NULL ;
}
return V_17 . V_20 ;
}
static void F_11 ( struct V_26 * V_27 , T_3 V_28 )
{
V_27 -> V_29 = V_28 & V_30 ;
V_27 -> V_5 = V_28 & V_31 ;
V_27 -> V_32 = V_28 & V_33 ;
V_27 -> V_34 = V_28 & V_35 ;
V_27 -> V_36 = V_28 & V_37 ;
V_27 -> V_38 = V_28 & V_39 ;
V_27 -> V_40 = V_28 & V_41 ;
V_27 -> V_42 = V_28 & V_43 ;
}
static int F_12 ( struct V_44 * V_3 )
{
T_3 V_45 = 0 ;
if ( V_3 -> V_4 . V_29 ) {
union V_8 * V_46 ;
struct V_47 V_48 ;
T_4 V_49 ;
V_46 = F_5 ( V_3 -> V_9 , V_50 , NULL ) ;
if ( ! V_46 )
return - V_51 ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_49 = * ( V_52 * ) V_46 -> V_17 . V_20 ;
if ( V_49 < 10 ) {
F_8 ( L_2 , V_49 ) ;
F_10 ( V_46 ) ;
return - V_53 ;
}
V_49 = F_13 ( sizeof( V_48 ) , V_49 ) ;
memcpy ( & V_48 , V_46 -> V_17 . V_20 , V_49 ) ;
V_45 = V_48 . V_54 & V_48 . V_55 ;
F_10 ( V_46 ) ;
}
if ( V_45 & V_56 ) {
V_3 -> V_4 . V_34 = true ;
V_3 -> V_4 . V_32 = true ;
}
if ( V_45 & ( V_57 |
V_58 |
V_59 ) )
V_3 -> V_4 . V_32 = true ;
if ( V_45 & ( V_60 |
V_61 ) )
V_3 -> V_4 . V_5 = true ;
V_3 -> V_6 = false ;
if ( V_45 & V_62 ) {
F_8 ( L_3 ) ;
V_3 -> V_4 . V_5 = ! V_1 . V_63 ;
V_3 -> V_6 = true ;
}
return 0 ;
}
static int F_14 ( struct V_44 * V_3 )
{
union V_8 * V_46 ;
struct V_64 V_48 ;
T_4 V_49 ;
int V_65 = 0 ;
V_46 = F_5 ( V_3 -> V_9 , V_66 , NULL ) ;
if ( ! V_46 )
return - V_51 ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_49 = * ( V_52 * ) V_46 -> V_17 . V_20 ;
if ( V_49 < 8 ) {
F_8 ( L_2 , V_49 ) ;
V_65 = - V_53 ;
goto V_67;
}
V_49 = F_13 ( sizeof( V_48 ) , V_49 ) ;
memcpy ( & V_48 , V_46 -> V_17 . V_20 , V_49 ) ;
F_8 ( L_4 ,
V_48 . V_68 , V_48 . V_69 ) ;
F_11 ( & V_3 -> V_4 , V_48 . V_69 ) ;
V_67:
F_10 ( V_46 ) ;
return V_65 ;
}
static int F_15 ( struct V_44 * V_3 , T_5 V_70 )
{
struct V_11 V_12 ;
union V_8 * V_46 ;
struct V_71 V_72 ;
if ( V_3 -> V_4 . V_5 ) {
V_72 . V_49 = 3 ;
V_72 . V_73 = V_70 ;
V_12 . V_24 = V_72 . V_49 ;
V_12 . V_20 = & V_72 ;
V_46 = F_5 ( V_3 -> V_9 ,
V_74 ,
& V_12 ) ;
if ( ! V_46 )
return - V_51 ;
F_10 ( V_46 ) ;
if ( V_70 == 0 )
F_16 ( 200 ) ;
}
return 0 ;
}
static int F_17 ( struct V_44 * V_3 , V_52 V_75 )
{
struct V_11 V_12 ;
union V_8 * V_46 ;
struct V_76 V_72 ;
if ( V_3 -> V_4 . V_32 ) {
V_72 . V_49 = 4 ;
V_72 . V_77 = V_75 ;
V_12 . V_24 = V_72 . V_49 ;
V_12 . V_20 = & V_72 ;
V_46 = F_5 ( V_3 -> V_9 ,
V_78 ,
& V_12 ) ;
if ( ! V_46 )
return - V_51 ;
F_10 ( V_46 ) ;
}
return 0 ;
}
static int F_18 ( struct V_44 * V_3 , V_52 V_75 )
{
struct V_11 V_12 ;
union V_8 * V_46 ;
struct V_76 V_72 ;
if ( V_3 -> V_4 . V_34 ) {
V_72 . V_49 = 4 ;
V_72 . V_77 = V_75 ;
V_12 . V_24 = V_72 . V_49 ;
V_12 . V_20 = & V_72 ;
V_46 = F_5 ( V_3 -> V_9 ,
V_79 ,
& V_12 ) ;
if ( ! V_46 )
return - V_51 ;
F_10 ( V_46 ) ;
}
return 0 ;
}
static int F_19 ( struct V_44 * V_3 , V_52 V_75 )
{
struct V_11 V_12 ;
union V_8 * V_46 ;
struct V_76 V_72 ;
if ( V_3 -> V_4 . V_36 ) {
V_72 . V_49 = 4 ;
V_72 . V_77 = V_75 ;
V_12 . V_24 = V_72 . V_49 ;
V_12 . V_20 = & V_72 ;
V_46 = F_5 ( V_3 -> V_9 ,
V_80 ,
& V_12 ) ;
if ( ! V_46 )
return - V_51 ;
F_10 ( V_46 ) ;
}
return 0 ;
}
static int F_20 ( struct V_44 * V_3 , V_52 V_75 )
{
struct V_11 V_12 ;
union V_8 * V_46 ;
struct V_76 V_72 ;
if ( V_3 -> V_4 . V_38 ) {
V_72 . V_49 = 4 ;
V_72 . V_77 = V_75 ;
V_12 . V_24 = V_72 . V_49 ;
V_12 . V_20 = & V_72 ;
V_46 = F_5 ( V_3 -> V_9 ,
V_81 ,
& V_12 ) ;
if ( ! V_46 )
return - V_51 ;
F_10 ( V_46 ) ;
}
return 0 ;
}
static int F_21 ( enum V_82 V_83 )
{
V_52 V_84 ;
if ( V_83 == V_85 )
V_84 = V_86 ;
else
V_84 = V_87 ;
F_19 ( & V_1 . V_3 , V_84 ) ;
F_17 ( & V_1 . V_3 , V_84 ) ;
F_18 ( & V_1 . V_3 , V_84 ) ;
F_20 ( & V_1 . V_3 , V_84 ) ;
return 0 ;
}
static int F_22 ( enum V_82 V_83 ,
enum V_88 V_70 )
{
if ( V_83 == V_85 )
return 0 ;
F_15 ( & V_1 . V_3 , V_70 ) ;
return 0 ;
}
static bool F_23 ( struct V_89 * V_90 )
{
T_1 V_91 , V_92 ;
T_2 V_13 ;
V_91 = F_24 ( & V_90 -> V_93 ) ;
if ( ! V_91 )
return false ;
V_13 = F_25 ( V_91 , L_5 , & V_92 ) ;
if ( F_7 ( V_13 ) )
return false ;
V_1 . V_91 = V_91 ;
V_1 . V_3 . V_9 = V_92 ;
return true ;
}
static int F_26 ( void )
{
int V_94 ;
V_94 = F_14 ( & V_1 . V_3 ) ;
if ( V_94 )
return V_94 ;
V_94 = F_12 ( & V_1 . V_3 ) ;
if ( V_94 )
return V_94 ;
return 0 ;
}
static int F_27 ( struct V_89 * V_90 )
{
if ( V_1 . V_91 == F_24 ( & V_90 -> V_93 ) )
return V_85 ;
else
return V_95 ;
}
static bool F_28 ( void )
{
char V_96 [ 255 ] = { 0 } ;
struct V_11 V_17 = { sizeof( V_96 ) , V_96 } ;
struct V_89 * V_90 = NULL ;
bool V_97 = false ;
int V_98 = 0 ;
bool V_99 = false ;
struct V_89 * V_100 ;
while ( ( V_90 = F_29 ( V_101 << 8 , V_90 ) ) != NULL ) {
V_98 ++ ;
V_97 |= ( F_23 ( V_90 ) == true ) ;
V_100 = F_30 ( V_90 ) ;
V_99 |= V_100 && V_100 -> V_102 ;
}
while ( ( V_90 = F_29 ( V_103 << 8 , V_90 ) ) != NULL ) {
V_98 ++ ;
V_97 |= ( F_23 ( V_90 ) == true ) ;
V_100 = F_30 ( V_90 ) ;
V_99 |= V_100 && V_100 -> V_102 ;
}
if ( V_97 && V_98 == 2 ) {
F_31 ( V_1 . V_3 . V_9 , V_104 , & V_17 ) ;
F_8 ( V_105 L_6 ,
V_96 ) ;
V_1 . V_2 = true ;
V_1 . V_63 = V_99 ;
F_26 () ;
return true ;
}
return false ;
}
void F_32 ( void )
{
bool V_94 ;
enum V_106 V_107 = 0 ;
V_94 = F_28 () ;
if ( ! V_94 )
return;
F_33 ( & V_108 , V_107 ) ;
}
void F_34 ( void )
{
F_35 () ;
}
