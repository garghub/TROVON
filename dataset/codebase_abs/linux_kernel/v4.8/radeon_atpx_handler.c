bool F_1 ( void ) {
return V_1 . V_2 ;
}
bool F_2 ( void ) {
return V_1 . V_3 . V_4 . V_5 ;
}
bool F_3 ( void ) {
return V_1 . V_3 . V_6 ;
}
static union V_7 * F_4 ( T_1 V_8 , int V_9 ,
struct V_10 * V_11 )
{
T_2 V_12 ;
union V_7 V_13 [ 2 ] ;
struct V_14 V_15 ;
struct V_10 V_16 = { V_17 , NULL } ;
V_15 . V_18 = 2 ;
V_15 . V_19 = & V_13 [ 0 ] ;
V_13 [ 0 ] . type = V_20 ;
V_13 [ 0 ] . integer . V_21 = V_9 ;
if ( V_11 ) {
V_13 [ 1 ] . type = V_22 ;
V_13 [ 1 ] . V_16 . V_23 = V_11 -> V_23 ;
V_13 [ 1 ] . V_16 . V_19 = V_11 -> V_19 ;
} else {
V_13 [ 1 ] . type = V_20 ;
V_13 [ 1 ] . integer . V_21 = 0 ;
}
V_12 = F_5 ( V_8 , NULL , & V_15 , & V_16 ) ;
if ( F_6 ( V_12 ) && V_12 != V_24 ) {
F_7 ( L_1 ,
F_8 ( V_12 ) ) ;
F_9 ( V_16 . V_19 ) ;
return NULL ;
}
return V_16 . V_19 ;
}
static void F_10 ( struct V_25 * V_26 , T_3 V_27 )
{
V_26 -> V_28 = V_27 & V_29 ;
V_26 -> V_5 = V_27 & V_30 ;
V_26 -> V_31 = V_27 & V_32 ;
V_26 -> V_33 = V_27 & V_34 ;
V_26 -> V_35 = V_27 & V_36 ;
V_26 -> V_37 = V_27 & V_38 ;
V_26 -> V_39 = V_27 & V_40 ;
V_26 -> V_41 = V_27 & V_42 ;
}
static int F_11 ( struct V_43 * V_3 )
{
T_3 V_44 = 0 ;
if ( V_3 -> V_4 . V_28 ) {
union V_7 * V_45 ;
struct V_46 V_47 ;
T_4 V_48 ;
V_45 = F_4 ( V_3 -> V_8 , V_49 , NULL ) ;
if ( ! V_45 )
return - V_50 ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_48 = * ( V_51 * ) V_45 -> V_16 . V_19 ;
if ( V_48 < 10 ) {
F_7 ( L_2 , V_48 ) ;
F_9 ( V_45 ) ;
return - V_52 ;
}
V_48 = F_12 ( sizeof( V_47 ) , V_48 ) ;
memcpy ( & V_47 , V_45 -> V_16 . V_19 , V_48 ) ;
V_44 = V_47 . V_53 & V_47 . V_54 ;
F_9 ( V_45 ) ;
}
if ( V_44 & V_55 ) {
V_3 -> V_4 . V_33 = true ;
V_3 -> V_4 . V_31 = true ;
}
if ( V_44 & ( V_56 |
V_57 |
V_58 ) )
V_3 -> V_4 . V_31 = true ;
if ( V_44 & ( V_59 |
V_60 ) )
V_3 -> V_4 . V_5 = true ;
V_3 -> V_6 = false ;
if ( V_44 & V_61 ) {
F_7 ( L_3 ) ;
V_3 -> V_4 . V_5 = false ;
V_3 -> V_6 = true ;
}
return 0 ;
}
static int F_13 ( struct V_43 * V_3 )
{
union V_7 * V_45 ;
struct V_62 V_47 ;
T_4 V_48 ;
int V_63 = 0 ;
V_45 = F_4 ( V_3 -> V_8 , V_64 , NULL ) ;
if ( ! V_45 )
return - V_50 ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_48 = * ( V_51 * ) V_45 -> V_16 . V_19 ;
if ( V_48 < 8 ) {
F_7 ( L_2 , V_48 ) ;
V_63 = - V_52 ;
goto V_65;
}
V_48 = F_12 ( sizeof( V_47 ) , V_48 ) ;
memcpy ( & V_47 , V_45 -> V_16 . V_19 , V_48 ) ;
F_7 ( L_4 ,
V_47 . V_66 , V_47 . V_67 ) ;
F_10 ( & V_3 -> V_4 , V_47 . V_67 ) ;
V_65:
F_9 ( V_45 ) ;
return V_63 ;
}
static int F_14 ( struct V_43 * V_3 , T_5 V_68 )
{
struct V_10 V_11 ;
union V_7 * V_45 ;
struct V_69 V_70 ;
if ( V_3 -> V_4 . V_5 ) {
V_70 . V_48 = 3 ;
V_70 . V_71 = V_68 ;
V_11 . V_23 = V_70 . V_48 ;
V_11 . V_19 = & V_70 ;
V_45 = F_4 ( V_3 -> V_8 ,
V_72 ,
& V_11 ) ;
if ( ! V_45 )
return - V_50 ;
F_9 ( V_45 ) ;
if ( V_68 == 0 )
F_15 ( 200 ) ;
}
return 0 ;
}
static int F_16 ( struct V_43 * V_3 , V_51 V_73 )
{
struct V_10 V_11 ;
union V_7 * V_45 ;
struct V_74 V_70 ;
if ( V_3 -> V_4 . V_31 ) {
V_70 . V_48 = 4 ;
V_70 . V_75 = V_73 ;
V_11 . V_23 = V_70 . V_48 ;
V_11 . V_19 = & V_70 ;
V_45 = F_4 ( V_3 -> V_8 ,
V_76 ,
& V_11 ) ;
if ( ! V_45 )
return - V_50 ;
F_9 ( V_45 ) ;
}
return 0 ;
}
static int F_17 ( struct V_43 * V_3 , V_51 V_73 )
{
struct V_10 V_11 ;
union V_7 * V_45 ;
struct V_74 V_70 ;
if ( V_3 -> V_4 . V_33 ) {
V_70 . V_48 = 4 ;
V_70 . V_75 = V_73 ;
V_11 . V_23 = V_70 . V_48 ;
V_11 . V_19 = & V_70 ;
V_45 = F_4 ( V_3 -> V_8 ,
V_77 ,
& V_11 ) ;
if ( ! V_45 )
return - V_50 ;
F_9 ( V_45 ) ;
}
return 0 ;
}
static int F_18 ( struct V_43 * V_3 , V_51 V_73 )
{
struct V_10 V_11 ;
union V_7 * V_45 ;
struct V_74 V_70 ;
if ( V_3 -> V_4 . V_35 ) {
V_70 . V_48 = 4 ;
V_70 . V_75 = V_73 ;
V_11 . V_23 = V_70 . V_48 ;
V_11 . V_19 = & V_70 ;
V_45 = F_4 ( V_3 -> V_8 ,
V_78 ,
& V_11 ) ;
if ( ! V_45 )
return - V_50 ;
F_9 ( V_45 ) ;
}
return 0 ;
}
static int F_19 ( struct V_43 * V_3 , V_51 V_73 )
{
struct V_10 V_11 ;
union V_7 * V_45 ;
struct V_74 V_70 ;
if ( V_3 -> V_4 . V_37 ) {
V_70 . V_48 = 4 ;
V_70 . V_75 = V_73 ;
V_11 . V_23 = V_70 . V_48 ;
V_11 . V_19 = & V_70 ;
V_45 = F_4 ( V_3 -> V_8 ,
V_79 ,
& V_11 ) ;
if ( ! V_45 )
return - V_50 ;
F_9 ( V_45 ) ;
}
return 0 ;
}
static int F_20 ( enum V_80 V_81 )
{
V_51 V_82 ;
if ( V_81 == V_83 )
V_82 = V_84 ;
else
V_82 = V_85 ;
F_18 ( & V_1 . V_3 , V_82 ) ;
F_16 ( & V_1 . V_3 , V_82 ) ;
F_17 ( & V_1 . V_3 , V_82 ) ;
F_19 ( & V_1 . V_3 , V_82 ) ;
return 0 ;
}
static int F_21 ( enum V_80 V_81 ,
enum V_86 V_68 )
{
if ( V_81 == V_83 )
return 0 ;
F_14 ( & V_1 . V_3 , V_68 ) ;
return 0 ;
}
static bool F_22 ( struct V_87 * V_88 )
{
T_1 V_89 , V_90 ;
T_2 V_12 ;
V_89 = F_23 ( & V_88 -> V_91 ) ;
if ( ! V_89 )
return false ;
V_12 = F_24 ( V_89 , L_5 , & V_90 ) ;
if ( F_6 ( V_12 ) )
return false ;
V_1 . V_89 = V_89 ;
V_1 . V_3 . V_8 = V_90 ;
return true ;
}
static int F_25 ( void )
{
int V_92 ;
V_92 = F_13 ( & V_1 . V_3 ) ;
if ( V_92 )
return V_92 ;
V_92 = F_11 ( & V_1 . V_3 ) ;
if ( V_92 )
return V_92 ;
return 0 ;
}
static int F_26 ( struct V_87 * V_88 )
{
if ( V_1 . V_89 == F_23 ( & V_88 -> V_91 ) )
return V_83 ;
else
return V_93 ;
}
static bool F_27 ( void )
{
char V_94 [ 255 ] = { 0 } ;
struct V_10 V_16 = { sizeof( V_94 ) , V_94 } ;
struct V_87 * V_88 = NULL ;
bool V_95 = false ;
int V_96 = 0 ;
while ( ( V_88 = F_28 ( V_97 << 8 , V_88 ) ) != NULL ) {
V_96 ++ ;
V_95 |= ( F_22 ( V_88 ) == true ) ;
}
while ( ( V_88 = F_28 ( V_98 << 8 , V_88 ) ) != NULL ) {
V_96 ++ ;
V_95 |= ( F_22 ( V_88 ) == true ) ;
}
if ( V_95 && V_96 == 2 ) {
F_29 ( V_1 . V_3 . V_8 , V_99 , & V_16 ) ;
F_7 ( V_100 L_6 ,
V_94 ) ;
V_1 . V_2 = true ;
F_25 () ;
return true ;
}
return false ;
}
void F_30 ( void )
{
bool V_92 ;
enum V_101 V_102 = 0 ;
V_92 = F_27 () ;
if ( ! V_92 )
return;
F_31 ( & V_103 , V_102 ) ;
}
void F_32 ( void )
{
F_33 () ;
}
