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
if ( V_4 && ( V_4 -> V_56 >= V_57 ) )
V_38 -> V_54 |= V_58 ;
} else {
if ( V_44 -> V_59 )
V_38 -> V_54 |= V_58 ;
}
if ( V_45 || V_46 )
V_38 -> V_54 |= V_60 ;
if ( V_4 && V_4 -> V_47 . V_61 )
V_38 -> V_54 |= V_62 ;
}
}
static void F_5 ( void * V_63 , struct V_3 * V_4 ,
void * V_64 , struct V_39 * V_40 )
{
struct V_1 * V_2 = V_63 ;
struct V_5 * V_6 = V_40 -> V_6 ;
struct V_65 * V_66 = F_6 ( V_6 ) ;
struct V_37 * V_67 = V_66 -> V_68 . V_67 ;
T_2 V_69 = F_7 ( V_6 ) ;
T_1 V_70 , V_71 , V_42 ;
bool V_7 = ! F_8 ( V_69 ) ;
if ( F_9 ( V_4 , V_64 , V_40 ) )
return;
V_42 = F_1 ( V_2 , V_4 , V_6 , V_7 ) ;
V_70 = 1 ;
F_4 ( V_2 , V_4 , & V_67 [ 0 ] , V_40 ,
V_70 , V_42 , 1 , V_7 ) ;
if ( ! V_7 ) {
for ( V_71 = 1 ; V_71 < 4 ; V_71 ++ )
F_4 ( V_2 , V_4 , & V_67 [ V_71 ] ,
V_40 , V_71 , ( V_42 - V_71 ) , 1 ,
V_7 ) ;
}
}
static bool F_10 ( struct V_1 * V_2 ,
struct V_15 * V_16 , T_3 V_72 )
{
struct V_8 * V_44 = V_8 ( V_2 ) ;
if ( V_44 -> V_73 )
return false ;
if ( V_44 -> V_18 == V_74 &&
V_44 -> V_75 < 3 )
return false ;
if ( V_16 -> V_76 [ V_72 ] . V_77 . V_78 == V_79 )
return true ;
return false ;
}
static void F_11 ( void * V_63 ,
struct V_80 * V_81 ,
struct V_3 * V_4 , void * V_64 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = V_63 ;
struct V_8 * V_44 = V_8 ( V_2 ) ;
struct V_82 * V_83 = F_12 ( V_6 ) ;
T_2 V_69 = F_7 ( V_6 ) ;
struct V_15 * V_16 ;
if ( ! V_64 || ! F_8 ( V_69 ) )
return;
if ( F_2 ( V_44 -> V_25 , V_6 , true ) )
return;
if ( F_13 ( F_14 ( V_83 ) )
|| F_15 ( F_14 ( V_83 ) ) )
return;
if ( V_4 ) {
V_16 = (struct V_15 * ) V_4 -> V_22 ;
if ( ( V_4 -> V_47 . V_61 ) &&
! ( V_6 -> V_84 == F_16 ( V_85 ) ) ) {
if ( F_17 ( V_69 ) ) {
T_1 V_72 = F_18 ( V_6 ) ;
if ( F_10 ( V_2 , V_16 ,
V_72 ) ) {
V_16 -> V_76 [ V_72 ] . V_77 . V_78 =
V_86 ;
F_19 ( V_4 ,
V_72 , 5000 ) ;
}
}
}
}
}
static void F_20 ( void * V_63 ,
struct V_80 * V_81 ,
struct V_87 * V_88 ,
struct V_3 * V_4 , void * V_64 )
{
}
static void * F_21 ( struct V_89 * V_25 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = V_1 ( V_25 ) ;
return V_2 ;
}
static void F_22 ( void * V_2 )
{
return;
}
static void * F_23 ( void * V_63 ,
struct V_3 * V_4 , T_4 V_92 )
{
struct V_1 * V_2 = V_63 ;
struct V_93 * V_94 ;
V_94 = F_24 ( sizeof( struct V_93 ) , V_92 ) ;
if ( ! V_94 ) {
F_25 ( V_2 , V_95 , V_96 ,
L_1 ) ;
return NULL ;
}
V_2 -> V_94 = V_94 ;
return V_94 ;
}
static void F_26 ( void * V_2 ,
struct V_3 * V_4 , void * V_64 )
{
struct V_93 * V_94 = V_64 ;
F_27 ( V_94 ) ;
}
int F_28 ( void )
{
return F_29 ( & V_97 ) ;
}
void F_30 ( void )
{
F_31 ( & V_97 ) ;
}
