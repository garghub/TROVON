bool F_1 ( void ) {
return V_1 . V_2 ;
}
static union V_3 * F_2 ( T_1 V_4 , int V_5 ,
struct V_6 * V_7 )
{
T_2 V_8 ;
union V_3 V_9 [ 2 ] ;
struct V_10 V_11 ;
struct V_6 V_12 = { V_13 , NULL } ;
V_11 . V_14 = 2 ;
V_11 . V_15 = & V_9 [ 0 ] ;
V_9 [ 0 ] . type = V_16 ;
V_9 [ 0 ] . integer . V_17 = V_5 ;
if ( V_7 ) {
V_9 [ 1 ] . type = V_18 ;
V_9 [ 1 ] . V_12 . V_19 = V_7 -> V_19 ;
V_9 [ 1 ] . V_12 . V_15 = V_7 -> V_15 ;
} else {
V_9 [ 1 ] . type = V_16 ;
V_9 [ 1 ] . integer . V_17 = 0 ;
}
V_8 = F_3 ( V_4 , NULL , & V_11 , & V_12 ) ;
if ( F_4 ( V_8 ) && V_8 != V_20 ) {
F_5 ( L_1 ,
F_6 ( V_8 ) ) ;
F_7 ( V_12 . V_15 ) ;
return NULL ;
}
return V_12 . V_15 ;
}
static void F_8 ( struct V_21 * V_22 , T_3 V_23 )
{
V_22 -> V_24 = V_23 & V_25 ;
V_22 -> V_26 = V_23 & V_27 ;
V_22 -> V_28 = V_23 & V_29 ;
V_22 -> V_30 = V_23 & V_31 ;
V_22 -> V_32 = V_23 & V_33 ;
V_22 -> V_34 = V_23 & V_35 ;
V_22 -> V_36 = V_23 & V_37 ;
V_22 -> V_38 = V_23 & V_39 ;
}
static int F_9 ( struct V_40 * V_41 )
{
V_41 -> V_42 . V_26 = true ;
if ( V_41 -> V_42 . V_24 ) {
union V_3 * V_43 ;
struct V_44 V_45 ;
T_4 V_46 ;
T_3 V_47 ;
V_43 = F_2 ( V_41 -> V_4 , V_48 , NULL ) ;
if ( ! V_43 )
return - V_49 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_46 = * ( V_50 * ) V_43 -> V_12 . V_15 ;
if ( V_46 < 10 ) {
F_5 ( L_2 , V_46 ) ;
F_7 ( V_43 ) ;
return - V_51 ;
}
V_46 = F_10 ( sizeof( V_45 ) , V_46 ) ;
memcpy ( & V_45 , V_43 -> V_12 . V_15 , V_46 ) ;
V_47 = V_45 . V_52 & V_45 . V_53 ;
if ( V_47 & V_54 ) {
V_41 -> V_42 . V_30 = true ;
V_41 -> V_42 . V_28 = true ;
}
if ( V_47 & ( V_55 |
V_56 |
V_57 ) )
V_41 -> V_42 . V_28 = true ;
F_7 ( V_43 ) ;
}
return 0 ;
}
static int F_11 ( struct V_40 * V_41 )
{
union V_3 * V_43 ;
struct V_58 V_45 ;
T_4 V_46 ;
int V_59 = 0 ;
V_43 = F_2 ( V_41 -> V_4 , V_60 , NULL ) ;
if ( ! V_43 )
return - V_49 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_46 = * ( V_50 * ) V_43 -> V_12 . V_15 ;
if ( V_46 < 8 ) {
F_5 ( L_2 , V_46 ) ;
V_59 = - V_51 ;
goto V_61;
}
V_46 = F_10 ( sizeof( V_45 ) , V_46 ) ;
memcpy ( & V_45 , V_43 -> V_12 . V_15 , V_46 ) ;
F_5 ( L_3 ,
V_45 . V_62 , V_45 . V_63 ) ;
F_8 ( & V_41 -> V_42 , V_45 . V_63 ) ;
V_61:
F_7 ( V_43 ) ;
return V_59 ;
}
static int F_12 ( struct V_40 * V_41 , T_5 V_64 )
{
struct V_6 V_7 ;
union V_3 * V_43 ;
struct V_65 V_66 ;
if ( V_41 -> V_42 . V_26 ) {
V_66 . V_46 = 3 ;
V_66 . V_67 = V_64 ;
V_7 . V_19 = V_66 . V_46 ;
V_7 . V_15 = & V_66 ;
V_43 = F_2 ( V_41 -> V_4 ,
V_68 ,
& V_7 ) ;
if ( ! V_43 )
return - V_49 ;
F_7 ( V_43 ) ;
}
return 0 ;
}
static int F_13 ( struct V_40 * V_41 , V_50 V_69 )
{
struct V_6 V_7 ;
union V_3 * V_43 ;
struct V_70 V_66 ;
if ( V_41 -> V_42 . V_28 ) {
V_66 . V_46 = 4 ;
V_66 . V_71 = V_69 ;
V_7 . V_19 = V_66 . V_46 ;
V_7 . V_15 = & V_66 ;
V_43 = F_2 ( V_41 -> V_4 ,
V_72 ,
& V_7 ) ;
if ( ! V_43 )
return - V_49 ;
F_7 ( V_43 ) ;
}
return 0 ;
}
static int F_14 ( struct V_40 * V_41 , V_50 V_69 )
{
struct V_6 V_7 ;
union V_3 * V_43 ;
struct V_70 V_66 ;
if ( V_41 -> V_42 . V_30 ) {
V_66 . V_46 = 4 ;
V_66 . V_71 = V_69 ;
V_7 . V_19 = V_66 . V_46 ;
V_7 . V_15 = & V_66 ;
V_43 = F_2 ( V_41 -> V_4 ,
V_73 ,
& V_7 ) ;
if ( ! V_43 )
return - V_49 ;
F_7 ( V_43 ) ;
}
return 0 ;
}
static int F_15 ( struct V_40 * V_41 , V_50 V_69 )
{
struct V_6 V_7 ;
union V_3 * V_43 ;
struct V_70 V_66 ;
if ( V_41 -> V_42 . V_32 ) {
V_66 . V_46 = 4 ;
V_66 . V_71 = V_69 ;
V_7 . V_19 = V_66 . V_46 ;
V_7 . V_15 = & V_66 ;
V_43 = F_2 ( V_41 -> V_4 ,
V_74 ,
& V_7 ) ;
if ( ! V_43 )
return - V_49 ;
F_7 ( V_43 ) ;
}
return 0 ;
}
static int F_16 ( struct V_40 * V_41 , V_50 V_69 )
{
struct V_6 V_7 ;
union V_3 * V_43 ;
struct V_70 V_66 ;
if ( V_41 -> V_42 . V_34 ) {
V_66 . V_46 = 4 ;
V_66 . V_71 = V_69 ;
V_7 . V_19 = V_66 . V_46 ;
V_7 . V_15 = & V_66 ;
V_43 = F_2 ( V_41 -> V_4 ,
V_75 ,
& V_7 ) ;
if ( ! V_43 )
return - V_49 ;
F_7 ( V_43 ) ;
}
return 0 ;
}
static int F_17 ( enum V_76 V_77 )
{
V_50 V_78 ;
if ( V_77 == V_79 )
V_78 = V_80 ;
else
V_78 = V_81 ;
F_15 ( & V_1 . V_41 , V_78 ) ;
F_13 ( & V_1 . V_41 , V_78 ) ;
F_14 ( & V_1 . V_41 , V_78 ) ;
F_16 ( & V_1 . V_41 , V_78 ) ;
return 0 ;
}
static int F_18 ( enum V_76 V_77 ,
enum V_82 V_64 )
{
if ( V_77 == V_79 )
return 0 ;
F_12 ( & V_1 . V_41 , V_64 ) ;
return 0 ;
}
static bool F_19 ( struct V_83 * V_84 )
{
T_1 V_85 , V_86 ;
T_2 V_8 ;
V_85 = F_20 ( & V_84 -> V_87 ) ;
if ( ! V_85 )
return false ;
V_8 = F_21 ( V_85 , L_4 , & V_86 ) ;
if ( F_4 ( V_8 ) ) {
V_1 . V_88 = V_85 ;
return false ;
}
V_1 . V_85 = V_85 ;
V_1 . V_41 . V_4 = V_86 ;
return true ;
}
static int F_22 ( void )
{
int V_89 ;
V_89 = F_11 ( & V_1 . V_41 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_9 ( & V_1 . V_41 ) ;
if ( V_89 )
return V_89 ;
return 0 ;
}
static int F_23 ( struct V_83 * V_84 )
{
if ( V_1 . V_85 == F_20 ( & V_84 -> V_87 ) )
return V_79 ;
else
return V_90 ;
}
static bool F_24 ( void )
{
char V_91 [ 255 ] = { 0 } ;
struct V_6 V_12 = { sizeof( V_91 ) , V_91 } ;
struct V_83 * V_84 = NULL ;
bool V_92 = false ;
int V_93 = 0 ;
while ( ( V_84 = F_25 ( V_94 << 8 , V_84 ) ) != NULL ) {
V_93 ++ ;
V_92 |= ( F_19 ( V_84 ) == true ) ;
}
while ( ( V_84 = F_25 ( V_95 << 8 , V_84 ) ) != NULL ) {
V_93 ++ ;
V_92 |= ( F_19 ( V_84 ) == true ) ;
}
if ( V_92 && V_93 == 2 ) {
F_26 ( V_1 . V_41 . V_4 , V_96 , & V_12 ) ;
F_5 ( V_97 L_5 ,
V_91 ) ;
V_1 . V_2 = true ;
F_27 ( V_1 . V_85 ) ;
F_27 ( V_1 . V_88 ) ;
return true ;
}
return false ;
}
void F_28 ( void )
{
bool V_89 ;
V_89 = F_24 () ;
if ( ! V_89 )
return;
F_29 ( & V_98 ) ;
}
void F_30 ( void )
{
F_31 () ;
}
