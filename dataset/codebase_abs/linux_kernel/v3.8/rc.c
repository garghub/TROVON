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
V_9 -> V_18 == V_20 ||
V_9 -> V_18 == V_21 ) {
if ( V_4 ) {
V_16 = (struct V_15 * ) V_4 -> V_22 ;
V_17 = V_16 -> V_17 ;
} else {
return 0 ;
}
} else {
V_17 = V_9 -> V_23 ;
}
if ( F_2 ( V_2 -> V_24 . V_25 , V_6 , true ) ||
V_7 ) {
return 0 ;
} else {
if ( V_11 -> V_26 == V_27 ) {
if ( V_17 == V_28 ) {
return V_29 ;
} else if ( V_17 == V_30 ) {
return V_31 ;
} else {
if ( F_3 ( V_13 ) != V_32 )
return V_33 ;
else
return V_34 ;
}
} else {
if ( V_17 == V_35 ) {
return V_36 ;
} else {
if ( F_3 ( V_13 ) != V_32 )
return V_33 ;
else
return V_34 ;
}
}
}
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_37 * V_38 ,
struct V_39 * V_40 ,
T_1 V_41 , char V_42 , int V_43 ,
bool V_7 )
{
struct V_8 * V_44 = V_8 ( V_2 ) ;
T_1 V_45 = 0 , V_46 = 0 ;
if ( V_4 ) {
V_45 = V_4 -> V_47 . V_48 & V_49 ;
V_46 = V_4 -> V_47 . V_48 & V_50 ;
}
V_38 -> V_51 = V_41 ;
V_38 -> V_52 = V_42 >= 0x00 ? V_42 : 0x00 ;
if ( ! V_7 ) {
if ( V_40 -> V_53 )
V_38 -> V_54 |= V_55 ;
if ( V_44 -> V_18 == V_19 ||
V_44 -> V_18 == V_20 ) {
if ( V_4 && ( V_4 -> V_47 . V_48 &
V_56 ) )
V_38 -> V_54 |= V_57 ;
} else {
if ( V_44 -> V_58 )
V_38 -> V_54 |= V_57 ;
}
if ( V_45 || V_46 )
V_38 -> V_54 |= V_59 ;
if ( V_4 && V_4 -> V_47 . V_60 )
V_38 -> V_54 |= V_61 ;
}
}
static void F_5 ( void * V_62 , struct V_3 * V_4 ,
void * V_63 , struct V_39 * V_40 )
{
struct V_1 * V_2 = V_62 ;
struct V_5 * V_6 = V_40 -> V_6 ;
struct V_64 * V_65 = F_6 ( V_6 ) ;
struct V_37 * V_66 = V_65 -> V_67 . V_66 ;
T_2 V_68 = F_7 ( V_6 ) ;
T_1 V_69 , V_70 , V_42 ;
bool V_7 = ! F_8 ( V_68 ) ;
if ( F_9 ( V_4 , V_63 , V_40 ) )
return;
V_42 = F_1 ( V_2 , V_4 , V_6 , V_7 ) ;
V_69 = 1 ;
F_4 ( V_2 , V_4 , & V_66 [ 0 ] , V_40 ,
V_69 , V_42 , 1 , V_7 ) ;
if ( ! V_7 ) {
for ( V_70 = 1 ; V_70 < 4 ; V_70 ++ )
F_4 ( V_2 , V_4 , & V_66 [ V_70 ] ,
V_40 , V_70 , ( V_42 - V_70 ) , 1 ,
V_7 ) ;
}
}
static bool F_10 ( struct V_1 * V_2 ,
struct V_15 * V_16 , T_3 V_71 )
{
struct V_8 * V_44 = V_8 ( V_2 ) ;
if ( V_44 -> V_72 )
return false ;
if ( V_44 -> V_18 == V_73 &&
V_44 -> V_74 < 3 )
return false ;
if ( V_16 -> V_75 [ V_71 ] . V_76 . V_77 == V_78 )
return true ;
return false ;
}
static void F_11 ( void * V_62 ,
struct V_79 * V_80 ,
struct V_3 * V_4 , void * V_63 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = V_62 ;
struct V_8 * V_44 = V_8 ( V_2 ) ;
struct V_81 * V_82 = F_12 ( V_6 ) ;
T_2 V_68 = F_7 ( V_6 ) ;
struct V_15 * V_16 ;
if ( ! V_63 || ! F_8 ( V_68 ) )
return;
if ( F_2 ( V_44 -> V_25 , V_6 , true ) )
return;
if ( F_13 ( F_14 ( V_82 ) )
|| F_15 ( F_14 ( V_82 ) ) )
return;
if ( V_4 ) {
V_16 = (struct V_15 * ) V_4 -> V_22 ;
if ( ( V_4 -> V_47 . V_60 ) &&
! ( V_6 -> V_83 == F_16 ( V_84 ) ) ) {
if ( F_17 ( V_68 ) ) {
T_1 V_71 = F_18 ( V_6 ) ;
if ( F_10 ( V_2 , V_16 ,
V_71 ) ) {
V_16 -> V_75 [ V_71 ] . V_76 . V_77 =
V_85 ;
F_19 ( V_4 ,
V_71 , 5000 ) ;
}
}
}
}
}
static void F_20 ( void * V_62 ,
struct V_79 * V_80 ,
struct V_3 * V_4 , void * V_63 )
{
}
static void F_21 ( void * V_62 ,
struct V_79 * V_80 ,
struct V_3 * V_4 , void * V_63 ,
T_4 V_86 )
{
}
static void * F_22 ( struct V_87 * V_25 ,
struct V_88 * V_89 )
{
struct V_1 * V_2 = V_1 ( V_25 ) ;
return V_2 ;
}
static void F_23 ( void * V_2 )
{
return;
}
static void * F_24 ( void * V_62 ,
struct V_3 * V_4 , T_5 V_90 )
{
struct V_1 * V_2 = V_62 ;
struct V_91 * V_92 ;
V_92 = F_25 ( sizeof( struct V_91 ) , V_90 ) ;
if ( ! V_92 ) {
F_26 ( V_2 , V_93 , V_94 ,
L_1 ) ;
return NULL ;
}
V_2 -> V_92 = V_92 ;
return V_92 ;
}
static void F_27 ( void * V_2 ,
struct V_3 * V_4 , void * V_63 )
{
struct V_91 * V_92 = V_63 ;
F_28 ( V_92 ) ;
}
int F_29 ( void )
{
return F_30 ( & V_95 ) ;
}
void F_31 ( void )
{
F_32 ( & V_95 ) ;
}
