static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , bool V_7 )
{
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_10 * V_11 = V_10 ( V_2 ) ;
struct V_12 * V_13 = & ( V_2 -> V_14 ) ;
struct V_15 * V_16 = NULL ;
T_1 V_17 = 0 ;
if ( V_9 -> V_18 == V_19 ||
V_9 -> V_18 == V_20 ) {
if ( V_4 ) {
V_16 = (struct V_15 * ) V_4 -> V_21 ;
V_17 = V_16 -> V_17 ;
} else {
return 0 ;
}
} else {
V_17 = V_9 -> V_22 ;
}
if ( F_2 ( V_2 -> V_23 . V_24 , V_6 , true ) ||
V_7 ) {
return 0 ;
} else {
if ( V_11 -> V_25 == V_26 ) {
if ( V_17 == V_27 ) {
return V_28 ;
} else if ( V_17 == V_29 ) {
return V_30 ;
} else {
if ( F_3 ( V_13 ) != V_31 )
return V_32 ;
else
return V_33 ;
}
} else {
if ( V_17 == V_34 ) {
return V_35 ;
} else {
if ( F_3 ( V_13 ) != V_31 )
return V_32 ;
else
return V_33 ;
}
}
}
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_36 * V_37 ,
struct V_38 * V_39 ,
T_1 V_40 , char V_41 , int V_42 ,
bool V_7 )
{
struct V_8 * V_43 = V_8 ( V_2 ) ;
T_1 V_44 = 0 , V_45 = 0 ;
if ( V_4 ) {
V_44 = V_4 -> V_46 . V_47 & V_48 ;
V_45 = V_4 -> V_46 . V_47 & V_49 ;
}
V_37 -> V_50 = V_40 ;
V_37 -> V_51 = V_41 >= 0x00 ? V_41 : 0x00 ;
if ( ! V_7 ) {
if ( V_39 -> V_52 )
V_37 -> V_53 |= V_54 ;
if ( V_43 -> V_18 == V_19 ||
V_43 -> V_18 == V_20 ) {
if ( V_4 && ( V_4 -> V_46 . V_47 &
V_55 ) )
V_37 -> V_53 |= V_56 ;
} else {
if ( V_43 -> V_57 )
V_37 -> V_53 |= V_56 ;
}
if ( V_44 || V_45 )
V_37 -> V_53 |= V_58 ;
if ( V_4 && V_4 -> V_46 . V_59 )
V_37 -> V_53 |= V_60 ;
}
}
static void F_5 ( void * V_61 , struct V_3 * V_4 ,
void * V_62 , struct V_38 * V_39 )
{
struct V_1 * V_2 = V_61 ;
struct V_5 * V_6 = V_39 -> V_6 ;
struct V_63 * V_64 = F_6 ( V_6 ) ;
struct V_36 * V_65 = V_64 -> V_66 . V_65 ;
T_2 V_67 = F_7 ( V_6 ) ;
T_1 V_68 , V_69 , V_41 ;
bool V_7 = ! F_8 ( V_67 ) ;
if ( F_9 ( V_4 , V_62 , V_39 ) )
return;
V_41 = F_1 ( V_2 , V_4 , V_6 , V_7 ) ;
V_68 = 1 ;
F_4 ( V_2 , V_4 , & V_65 [ 0 ] , V_39 ,
V_68 , V_41 , 1 , V_7 ) ;
if ( ! V_7 ) {
for ( V_69 = 1 ; V_69 < 4 ; V_69 ++ )
F_4 ( V_2 , V_4 , & V_65 [ V_69 ] ,
V_39 , V_69 , ( V_41 - V_69 ) , 1 ,
V_7 ) ;
}
}
static bool F_10 ( struct V_1 * V_2 ,
struct V_15 * V_16 , T_3 V_70 )
{
struct V_8 * V_43 = V_8 ( V_2 ) ;
if ( V_43 -> V_71 )
return false ;
if ( V_43 -> V_18 == V_72 &&
V_43 -> V_73 < 3 )
return false ;
if ( V_16 -> V_74 [ V_70 ] . V_75 . V_76 == V_77 )
return true ;
return false ;
}
static void F_11 ( void * V_61 ,
struct V_78 * V_79 ,
struct V_3 * V_4 , void * V_62 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = V_61 ;
struct V_8 * V_43 = V_8 ( V_2 ) ;
struct V_80 * V_81 = F_12 ( V_6 ) ;
T_2 V_67 = F_7 ( V_6 ) ;
struct V_15 * V_16 ;
if ( ! V_62 || ! F_8 ( V_67 ) )
return;
if ( F_2 ( V_43 -> V_24 , V_6 , true ) )
return;
if ( F_13 ( F_14 ( V_81 ) )
|| F_15 ( F_14 ( V_81 ) ) )
return;
if ( V_4 ) {
V_16 = (struct V_15 * ) V_4 -> V_21 ;
if ( ( V_4 -> V_46 . V_59 == true ) &&
! ( V_6 -> V_82 == F_16 ( V_83 ) ) ) {
if ( F_17 ( V_67 ) ) {
T_1 V_70 = F_18 ( V_6 ) ;
if ( F_10 ( V_2 , V_16 ,
V_70 ) ) {
V_16 -> V_74 [ V_70 ] . V_75 . V_76 =
V_84 ;
F_19 ( V_4 ,
V_70 , 5000 ) ;
}
}
}
}
}
static void F_20 ( void * V_61 ,
struct V_78 * V_79 ,
struct V_3 * V_4 , void * V_62 )
{
}
static void F_21 ( void * V_61 ,
struct V_78 * V_79 ,
struct V_3 * V_4 , void * V_62 ,
T_4 V_85 ,
enum V_86 V_87 )
{
}
static void * F_22 ( struct V_88 * V_24 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 = V_1 ( V_24 ) ;
return V_2 ;
}
static void F_23 ( void * V_2 )
{
return;
}
static void * F_24 ( void * V_61 ,
struct V_3 * V_4 , T_5 V_91 )
{
struct V_1 * V_2 = V_61 ;
struct V_92 * V_93 ;
V_93 = F_25 ( sizeof( struct V_92 ) , V_91 ) ;
if ( ! V_93 ) {
F_26 ( V_2 , V_94 , V_95 ,
( L_1 ) ) ;
return NULL ;
}
V_2 -> V_93 = V_93 ;
return V_93 ;
}
static void F_27 ( void * V_2 ,
struct V_3 * V_4 , void * V_62 )
{
struct V_92 * V_93 = V_62 ;
F_28 ( V_93 ) ;
}
int F_29 ( void )
{
return F_30 ( & V_96 ) ;
}
void F_31 ( void )
{
F_32 ( & V_96 ) ;
}
