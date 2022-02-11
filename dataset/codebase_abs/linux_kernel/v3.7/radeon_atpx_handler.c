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
union V_1 * V_40 ;
struct V_41 V_42 ;
T_4 V_43 ;
int V_44 = 0 ;
V_40 = F_1 ( V_39 -> V_2 , V_45 , NULL ) ;
if ( ! V_40 )
return - V_46 ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
V_43 = * ( V_47 * ) V_40 -> V_10 . V_13 ;
if ( V_43 < 8 ) {
F_4 ( L_2 , V_43 ) ;
V_44 = - V_48 ;
goto V_49;
}
V_43 = F_9 ( sizeof( V_42 ) , V_43 ) ;
memcpy ( & V_42 , V_40 -> V_10 . V_13 , V_43 ) ;
F_4 ( L_3 , V_42 . V_50 ) ;
F_7 ( & V_39 -> V_51 , V_42 . V_52 ) ;
V_49:
F_6 ( V_40 ) ;
return V_44 ;
}
static int F_10 ( struct V_38 * V_39 , T_5 V_53 )
{
struct V_4 V_5 ;
union V_1 * V_40 ;
struct V_54 V_55 ;
if ( V_39 -> V_51 . V_24 ) {
V_55 . V_43 = 3 ;
V_55 . V_56 = V_53 ;
V_5 . V_17 = V_55 . V_43 ;
V_5 . V_13 = & V_55 ;
V_40 = F_1 ( V_39 -> V_2 ,
V_57 ,
& V_5 ) ;
if ( ! V_40 )
return - V_46 ;
F_6 ( V_40 ) ;
}
return 0 ;
}
static int F_11 ( struct V_38 * V_39 , V_47 V_58 )
{
struct V_4 V_5 ;
union V_1 * V_40 ;
struct V_59 V_55 ;
if ( V_39 -> V_51 . V_26 ) {
V_55 . V_43 = 4 ;
V_55 . V_60 = V_58 ;
V_5 . V_17 = V_55 . V_43 ;
V_5 . V_13 = & V_55 ;
V_40 = F_1 ( V_39 -> V_2 ,
V_61 ,
& V_5 ) ;
if ( ! V_40 )
return - V_46 ;
F_6 ( V_40 ) ;
}
return 0 ;
}
static int F_12 ( struct V_38 * V_39 , V_47 V_58 )
{
struct V_4 V_5 ;
union V_1 * V_40 ;
struct V_59 V_55 ;
if ( V_39 -> V_51 . V_28 ) {
V_55 . V_43 = 4 ;
V_55 . V_60 = V_58 ;
V_5 . V_17 = V_55 . V_43 ;
V_5 . V_13 = & V_55 ;
V_40 = F_1 ( V_39 -> V_2 ,
V_62 ,
& V_5 ) ;
if ( ! V_40 )
return - V_46 ;
F_6 ( V_40 ) ;
}
return 0 ;
}
static int F_13 ( struct V_38 * V_39 , V_47 V_58 )
{
struct V_4 V_5 ;
union V_1 * V_40 ;
struct V_59 V_55 ;
if ( V_39 -> V_51 . V_30 ) {
V_55 . V_43 = 4 ;
V_55 . V_60 = V_58 ;
V_5 . V_17 = V_55 . V_43 ;
V_5 . V_13 = & V_55 ;
V_40 = F_1 ( V_39 -> V_2 ,
V_63 ,
& V_5 ) ;
if ( ! V_40 )
return - V_46 ;
F_6 ( V_40 ) ;
}
return 0 ;
}
static int F_14 ( struct V_38 * V_39 , V_47 V_58 )
{
struct V_4 V_5 ;
union V_1 * V_40 ;
struct V_59 V_55 ;
if ( V_39 -> V_51 . V_32 ) {
V_55 . V_43 = 4 ;
V_55 . V_60 = V_58 ;
V_5 . V_17 = V_55 . V_43 ;
V_5 . V_13 = & V_55 ;
V_40 = F_1 ( V_39 -> V_2 ,
V_64 ,
& V_5 ) ;
if ( ! V_40 )
return - V_46 ;
F_6 ( V_40 ) ;
}
return 0 ;
}
static int F_15 ( enum V_65 V_66 )
{
V_47 V_67 ;
if ( V_66 == V_68 )
V_67 = V_69 ;
else
V_67 = V_70 ;
F_13 ( & V_71 . V_39 , V_67 ) ;
F_11 ( & V_71 . V_39 , V_67 ) ;
F_12 ( & V_71 . V_39 , V_67 ) ;
F_14 ( & V_71 . V_39 , V_67 ) ;
return 0 ;
}
static int F_16 ( enum V_65 V_66 ,
enum V_72 V_53 )
{
if ( V_66 == V_68 )
return 0 ;
F_10 ( & V_71 . V_39 , V_53 ) ;
return 0 ;
}
static bool F_17 ( struct V_73 * V_74 )
{
T_1 V_75 , V_76 ;
T_2 V_6 ;
V_75 = F_18 ( & V_74 -> V_77 ) ;
if ( ! V_75 )
return false ;
V_6 = F_19 ( V_75 , L_4 , & V_76 ) ;
if ( F_3 ( V_6 ) )
return false ;
V_71 . V_75 = V_75 ;
V_71 . V_39 . V_2 = V_76 ;
return true ;
}
static int F_20 ( void )
{
return F_8 ( & V_71 . V_39 ) ;
}
static int F_21 ( struct V_73 * V_74 )
{
if ( V_71 . V_75 == F_18 ( & V_74 -> V_77 ) )
return V_68 ;
else
return V_78 ;
}
static bool F_22 ( void )
{
char V_79 [ 255 ] = { 0 } ;
struct V_4 V_10 = { sizeof( V_79 ) , V_79 } ;
struct V_73 * V_74 = NULL ;
bool V_80 = false ;
int V_81 = 0 ;
while ( ( V_74 = F_23 ( V_82 << 8 , V_74 ) ) != NULL ) {
V_81 ++ ;
V_80 |= ( F_17 ( V_74 ) == true ) ;
}
if ( V_80 && V_81 == 2 ) {
F_24 ( V_71 . V_39 . V_2 , V_83 , & V_10 ) ;
F_4 ( V_84 L_5 ,
V_79 ) ;
V_71 . V_85 = true ;
return true ;
}
return false ;
}
void F_25 ( void )
{
bool V_86 ;
V_86 = F_22 () ;
if ( ! V_86 )
return;
F_26 ( & V_87 ) ;
}
void F_27 ( void )
{
F_28 () ;
}
