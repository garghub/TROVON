static union V_1 * F_1 ( T_1 V_2 , int V_3 ,
struct V_4 * V_5 )
{
T_2 V_6 ;
union V_1 V_7 [ 2 ] ;
struct V_8 V_9 ;
struct V_4 V_10 = { V_11 , NULL } ;
V_9 . V_12 = 2 ;
V_9 . V_13 = & V_7 [ 0 ] ;
V_7 [ 0 ] . type = V_14 ;
V_7 [ 0 ] . integer . V_15 = V_3 ;
if ( V_5 ) {
V_7 [ 1 ] . type = V_16 ;
V_7 [ 1 ] . V_10 . V_17 = V_5 -> V_17 ;
V_7 [ 1 ] . V_10 . V_13 = V_5 -> V_13 ;
} else {
V_7 [ 1 ] . type = V_14 ;
V_7 [ 1 ] . integer . V_15 = 0 ;
}
V_6 = F_2 ( V_2 , NULL , & V_9 , & V_10 ) ;
if ( F_3 ( V_6 ) && V_6 != V_18 ) {
F_4 ( L_1 ,
F_5 ( V_6 ) ) ;
F_6 ( V_10 . V_13 ) ;
return NULL ;
}
return V_10 . V_13 ;
}
static void F_7 ( struct V_19 * V_20 , T_3 V_21 )
{
V_20 -> V_22 = V_21 & V_23 ;
V_20 -> V_24 = V_21 & V_25 ;
V_20 -> V_26 = V_21 & V_27 ;
V_20 -> V_28 = V_21 & V_29 ;
V_20 -> V_30 = V_21 & V_31 ;
V_20 -> V_32 = V_21 & V_33 ;
V_20 -> V_34 = V_21 & V_35 ;
V_20 -> V_36 = V_21 & V_37 ;
}
static int F_8 ( struct V_38 * V_39 )
{
V_39 -> V_40 . V_24 = true ;
if ( V_39 -> V_40 . V_22 ) {
union V_1 * V_41 ;
struct V_42 V_43 ;
T_4 V_44 ;
T_3 V_45 ;
V_41 = F_1 ( V_39 -> V_2 , V_46 , NULL ) ;
if ( ! V_41 )
return - V_47 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_44 = * ( V_48 * ) V_41 -> V_10 . V_13 ;
if ( V_44 < 10 ) {
F_4 ( L_2 , V_44 ) ;
F_6 ( V_41 ) ;
return - V_49 ;
}
V_44 = F_9 ( sizeof( V_43 ) , V_44 ) ;
memcpy ( & V_43 , V_41 -> V_10 . V_13 , V_44 ) ;
V_45 = V_43 . V_50 & V_43 . V_51 ;
if ( V_45 & V_52 ) {
V_39 -> V_40 . V_28 = true ;
V_39 -> V_40 . V_26 = true ;
}
if ( V_45 & ( V_53 |
V_54 |
V_55 ) )
V_39 -> V_40 . V_26 = true ;
F_6 ( V_41 ) ;
}
return 0 ;
}
static int F_10 ( struct V_38 * V_39 )
{
union V_1 * V_41 ;
struct V_56 V_43 ;
T_4 V_44 ;
int V_57 = 0 ;
V_41 = F_1 ( V_39 -> V_2 , V_58 , NULL ) ;
if ( ! V_41 )
return - V_47 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_44 = * ( V_48 * ) V_41 -> V_10 . V_13 ;
if ( V_44 < 8 ) {
F_4 ( L_2 , V_44 ) ;
V_57 = - V_49 ;
goto V_59;
}
V_44 = F_9 ( sizeof( V_43 ) , V_44 ) ;
memcpy ( & V_43 , V_41 -> V_10 . V_13 , V_44 ) ;
F_4 ( L_3 , V_43 . V_60 ) ;
F_7 ( & V_39 -> V_40 , V_43 . V_61 ) ;
V_59:
F_6 ( V_41 ) ;
return V_57 ;
}
static int F_11 ( struct V_38 * V_39 , T_5 V_62 )
{
struct V_4 V_5 ;
union V_1 * V_41 ;
struct V_63 V_64 ;
if ( V_39 -> V_40 . V_24 ) {
V_64 . V_44 = 3 ;
V_64 . V_65 = V_62 ;
V_5 . V_17 = V_64 . V_44 ;
V_5 . V_13 = & V_64 ;
V_41 = F_1 ( V_39 -> V_2 ,
V_66 ,
& V_5 ) ;
if ( ! V_41 )
return - V_47 ;
F_6 ( V_41 ) ;
}
return 0 ;
}
static int F_12 ( struct V_38 * V_39 , V_48 V_67 )
{
struct V_4 V_5 ;
union V_1 * V_41 ;
struct V_68 V_64 ;
if ( V_39 -> V_40 . V_26 ) {
V_64 . V_44 = 4 ;
V_64 . V_69 = V_67 ;
V_5 . V_17 = V_64 . V_44 ;
V_5 . V_13 = & V_64 ;
V_41 = F_1 ( V_39 -> V_2 ,
V_70 ,
& V_5 ) ;
if ( ! V_41 )
return - V_47 ;
F_6 ( V_41 ) ;
}
return 0 ;
}
static int F_13 ( struct V_38 * V_39 , V_48 V_67 )
{
struct V_4 V_5 ;
union V_1 * V_41 ;
struct V_68 V_64 ;
if ( V_39 -> V_40 . V_28 ) {
V_64 . V_44 = 4 ;
V_64 . V_69 = V_67 ;
V_5 . V_17 = V_64 . V_44 ;
V_5 . V_13 = & V_64 ;
V_41 = F_1 ( V_39 -> V_2 ,
V_71 ,
& V_5 ) ;
if ( ! V_41 )
return - V_47 ;
F_6 ( V_41 ) ;
}
return 0 ;
}
static int F_14 ( struct V_38 * V_39 , V_48 V_67 )
{
struct V_4 V_5 ;
union V_1 * V_41 ;
struct V_68 V_64 ;
if ( V_39 -> V_40 . V_30 ) {
V_64 . V_44 = 4 ;
V_64 . V_69 = V_67 ;
V_5 . V_17 = V_64 . V_44 ;
V_5 . V_13 = & V_64 ;
V_41 = F_1 ( V_39 -> V_2 ,
V_72 ,
& V_5 ) ;
if ( ! V_41 )
return - V_47 ;
F_6 ( V_41 ) ;
}
return 0 ;
}
static int F_15 ( struct V_38 * V_39 , V_48 V_67 )
{
struct V_4 V_5 ;
union V_1 * V_41 ;
struct V_68 V_64 ;
if ( V_39 -> V_40 . V_32 ) {
V_64 . V_44 = 4 ;
V_64 . V_69 = V_67 ;
V_5 . V_17 = V_64 . V_44 ;
V_5 . V_13 = & V_64 ;
V_41 = F_1 ( V_39 -> V_2 ,
V_73 ,
& V_5 ) ;
if ( ! V_41 )
return - V_47 ;
F_6 ( V_41 ) ;
}
return 0 ;
}
static int F_16 ( enum V_74 V_75 )
{
V_48 V_76 ;
if ( V_75 == V_77 )
V_76 = V_78 ;
else
V_76 = V_79 ;
F_14 ( & V_80 . V_39 , V_76 ) ;
F_12 ( & V_80 . V_39 , V_76 ) ;
F_13 ( & V_80 . V_39 , V_76 ) ;
F_15 ( & V_80 . V_39 , V_76 ) ;
return 0 ;
}
static int F_17 ( enum V_74 V_75 ,
enum V_81 V_62 )
{
if ( V_75 == V_77 )
return 0 ;
F_11 ( & V_80 . V_39 , V_62 ) ;
return 0 ;
}
static bool F_18 ( struct V_82 * V_83 )
{
T_1 V_84 , V_85 ;
T_2 V_6 ;
V_84 = F_19 ( & V_83 -> V_86 ) ;
if ( ! V_84 )
return false ;
V_6 = F_20 ( V_84 , L_4 , & V_85 ) ;
if ( F_3 ( V_6 ) )
return false ;
V_80 . V_84 = V_84 ;
V_80 . V_39 . V_2 = V_85 ;
return true ;
}
static int F_21 ( void )
{
int V_87 ;
V_87 = F_10 ( & V_80 . V_39 ) ;
if ( V_87 )
return V_87 ;
V_87 = F_8 ( & V_80 . V_39 ) ;
if ( V_87 )
return V_87 ;
return 0 ;
}
static int F_22 ( struct V_82 * V_83 )
{
if ( V_80 . V_84 == F_19 ( & V_83 -> V_86 ) )
return V_77 ;
else
return V_88 ;
}
static bool F_23 ( void )
{
char V_89 [ 255 ] = { 0 } ;
struct V_4 V_10 = { sizeof( V_89 ) , V_89 } ;
struct V_82 * V_83 = NULL ;
bool V_90 = false ;
int V_91 = 0 ;
while ( ( V_83 = F_24 ( V_92 << 8 , V_83 ) ) != NULL ) {
V_91 ++ ;
V_90 |= ( F_18 ( V_83 ) == true ) ;
}
if ( V_90 && V_91 == 2 ) {
F_25 ( V_80 . V_39 . V_2 , V_93 , & V_10 ) ;
F_4 ( V_94 L_5 ,
V_89 ) ;
V_80 . V_95 = true ;
return true ;
}
return false ;
}
void F_26 ( void )
{
bool V_87 ;
V_87 = F_23 () ;
if ( ! V_87 )
return;
F_27 ( & V_96 ) ;
}
void F_28 ( void )
{
F_29 () ;
}
