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
V_3 -> V_7 = false ;
if ( V_45 & V_64 )
V_3 -> V_7 = true ;
return 0 ;
}
static int F_14 ( struct V_44 * V_3 )
{
union V_8 * V_46 ;
struct V_65 V_48 ;
T_4 V_49 ;
int V_66 = 0 ;
V_46 = F_5 ( V_3 -> V_9 , V_67 , NULL ) ;
if ( ! V_46 )
return - V_51 ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_49 = * ( V_52 * ) V_46 -> V_17 . V_20 ;
if ( V_49 < 8 ) {
F_8 ( L_2 , V_49 ) ;
V_66 = - V_53 ;
goto V_68;
}
V_49 = F_13 ( sizeof( V_48 ) , V_49 ) ;
memcpy ( & V_48 , V_46 -> V_17 . V_20 , V_49 ) ;
F_8 ( L_4 ,
V_48 . V_69 , V_48 . V_70 ) ;
F_11 ( & V_3 -> V_4 , V_48 . V_70 ) ;
V_68:
F_10 ( V_46 ) ;
return V_66 ;
}
static int F_15 ( struct V_44 * V_3 , T_5 V_71 )
{
struct V_11 V_12 ;
union V_8 * V_46 ;
struct V_72 V_73 ;
if ( V_3 -> V_4 . V_5 ) {
V_73 . V_49 = 3 ;
V_73 . V_74 = V_71 ;
V_12 . V_24 = V_73 . V_49 ;
V_12 . V_20 = & V_73 ;
V_46 = F_5 ( V_3 -> V_9 ,
V_75 ,
& V_12 ) ;
if ( ! V_46 )
return - V_51 ;
F_10 ( V_46 ) ;
if ( V_71 == 0 )
F_16 ( 200 ) ;
}
return 0 ;
}
static int F_17 ( struct V_44 * V_3 , V_52 V_76 )
{
struct V_11 V_12 ;
union V_8 * V_46 ;
struct V_77 V_73 ;
if ( V_3 -> V_4 . V_32 ) {
V_73 . V_49 = 4 ;
V_73 . V_78 = V_76 ;
V_12 . V_24 = V_73 . V_49 ;
V_12 . V_20 = & V_73 ;
V_46 = F_5 ( V_3 -> V_9 ,
V_79 ,
& V_12 ) ;
if ( ! V_46 )
return - V_51 ;
F_10 ( V_46 ) ;
}
return 0 ;
}
static int F_18 ( struct V_44 * V_3 , V_52 V_76 )
{
struct V_11 V_12 ;
union V_8 * V_46 ;
struct V_77 V_73 ;
if ( V_3 -> V_4 . V_34 ) {
V_73 . V_49 = 4 ;
V_73 . V_78 = V_76 ;
V_12 . V_24 = V_73 . V_49 ;
V_12 . V_20 = & V_73 ;
V_46 = F_5 ( V_3 -> V_9 ,
V_80 ,
& V_12 ) ;
if ( ! V_46 )
return - V_51 ;
F_10 ( V_46 ) ;
}
return 0 ;
}
static int F_19 ( struct V_44 * V_3 , V_52 V_76 )
{
struct V_11 V_12 ;
union V_8 * V_46 ;
struct V_77 V_73 ;
if ( V_3 -> V_4 . V_36 ) {
V_73 . V_49 = 4 ;
V_73 . V_78 = V_76 ;
V_12 . V_24 = V_73 . V_49 ;
V_12 . V_20 = & V_73 ;
V_46 = F_5 ( V_3 -> V_9 ,
V_81 ,
& V_12 ) ;
if ( ! V_46 )
return - V_51 ;
F_10 ( V_46 ) ;
}
return 0 ;
}
static int F_20 ( struct V_44 * V_3 , V_52 V_76 )
{
struct V_11 V_12 ;
union V_8 * V_46 ;
struct V_77 V_73 ;
if ( V_3 -> V_4 . V_38 ) {
V_73 . V_49 = 4 ;
V_73 . V_78 = V_76 ;
V_12 . V_24 = V_73 . V_49 ;
V_12 . V_20 = & V_73 ;
V_46 = F_5 ( V_3 -> V_9 ,
V_82 ,
& V_12 ) ;
if ( ! V_46 )
return - V_51 ;
F_10 ( V_46 ) ;
}
return 0 ;
}
static int F_21 ( enum V_83 V_84 )
{
V_52 V_85 ;
if ( V_84 == V_86 )
V_85 = V_87 ;
else
V_85 = V_88 ;
F_19 ( & V_1 . V_3 , V_85 ) ;
F_17 ( & V_1 . V_3 , V_85 ) ;
F_18 ( & V_1 . V_3 , V_85 ) ;
F_20 ( & V_1 . V_3 , V_85 ) ;
return 0 ;
}
static int F_22 ( enum V_83 V_84 ,
enum V_89 V_71 )
{
if ( V_84 == V_86 )
return 0 ;
F_15 ( & V_1 . V_3 , V_71 ) ;
return 0 ;
}
static bool F_23 ( struct V_90 * V_91 )
{
T_1 V_92 , V_93 ;
T_2 V_13 ;
V_92 = F_24 ( & V_91 -> V_94 ) ;
if ( ! V_92 )
return false ;
V_13 = F_25 ( V_92 , L_5 , & V_93 ) ;
if ( F_7 ( V_13 ) ) {
V_1 . V_95 = V_92 ;
return false ;
}
V_1 . V_92 = V_92 ;
V_1 . V_3 . V_9 = V_93 ;
return true ;
}
static int F_26 ( void )
{
int V_96 ;
V_96 = F_14 ( & V_1 . V_3 ) ;
if ( V_96 )
return V_96 ;
V_96 = F_12 ( & V_1 . V_3 ) ;
if ( V_96 )
return V_96 ;
return 0 ;
}
static int F_27 ( struct V_90 * V_91 )
{
if ( V_1 . V_92 == F_24 ( & V_91 -> V_94 ) )
return V_86 ;
else
return V_97 ;
}
static bool F_28 ( void )
{
char V_98 [ 255 ] = { 0 } ;
struct V_11 V_17 = { sizeof( V_98 ) , V_98 } ;
struct V_90 * V_91 = NULL ;
bool V_99 = false ;
int V_100 = 0 ;
bool V_101 = false ;
struct V_90 * V_102 ;
while ( ( V_91 = F_29 ( V_103 << 8 , V_91 ) ) != NULL ) {
V_100 ++ ;
V_99 |= ( F_23 ( V_91 ) == true ) ;
V_102 = F_30 ( V_91 ) ;
V_101 |= V_102 && V_102 -> V_104 ;
}
while ( ( V_91 = F_29 ( V_105 << 8 , V_91 ) ) != NULL ) {
V_100 ++ ;
V_99 |= ( F_23 ( V_91 ) == true ) ;
V_102 = F_30 ( V_91 ) ;
V_101 |= V_102 && V_102 -> V_104 ;
}
if ( V_99 && V_100 == 2 ) {
F_31 ( V_1 . V_3 . V_9 , V_106 , & V_17 ) ;
F_32 ( L_6 ,
V_98 ) ;
V_1 . V_2 = true ;
V_1 . V_63 = V_101 ;
F_26 () ;
return true ;
}
return false ;
}
void F_33 ( void )
{
bool V_96 ;
enum V_107 V_108 = 0 ;
V_96 = F_28 () ;
if ( ! V_96 )
return;
F_34 ( & V_109 , V_108 ) ;
}
void F_35 ( void )
{
F_36 () ;
}
