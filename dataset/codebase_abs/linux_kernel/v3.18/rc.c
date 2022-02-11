static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , bool V_7 )
{
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_10 * V_11 = & ( V_2 -> V_12 ) ;
struct V_13 * V_14 = NULL ;
T_1 V_15 = 0 ;
if ( V_4 ) {
V_14 = (struct V_13 * ) V_4 -> V_16 ;
V_15 = V_14 -> V_15 ;
}
if ( F_2 ( V_2 -> V_17 . V_18 , V_6 , true ) || V_7 ) {
return 0 ;
} else {
if ( V_9 -> V_19 == V_20 ) {
if ( V_15 == V_21 ) {
return V_22 ;
} else if ( V_15 == V_23 ) {
return V_24 ;
} else if ( V_15 == V_25 ) {
if ( F_3 ( V_11 ) != V_26 )
return V_27 ;
else
return V_28 ;
} else if ( V_15 == V_29 ) {
return V_30 ;
}
return 0 ;
} else {
if ( V_15 == V_31 ) {
return V_32 ;
} else if ( V_15 == V_33 ) {
if ( F_3 ( V_11 ) != V_26 )
return V_27 ;
else
return V_28 ;
} else if ( V_15 == V_34 ) {
return V_30 ;
}
return 0 ;
}
}
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_35 * V_36 ,
struct V_37 * V_38 ,
T_1 V_39 , char V_40 , int V_41 ,
bool V_7 )
{
struct V_42 * V_43 = V_42 ( V_2 ) ;
struct V_13 * V_14 = NULL ;
T_1 V_15 = 0 ;
T_1 V_44 = 0 , V_45 = 0 , V_46 = 0 ;
if ( V_4 ) {
V_44 = V_4 -> V_47 . V_48 & V_49 ;
V_45 = V_4 -> V_47 . V_48 & V_50 ;
V_46 = V_4 -> V_51 . V_48 & V_52 ;
V_14 = (struct V_13 * ) V_4 -> V_16 ;
V_15 = V_14 -> V_15 ;
}
V_36 -> V_53 = V_39 ;
V_36 -> V_54 = V_40 >= 0x00 ? V_40 : 0x00 ;
if ( V_2 -> V_9 . V_55 == V_56 &&
V_15 == V_34 )
V_36 -> V_54 += 0x10 ;
if ( ! V_7 ) {
if ( V_38 -> V_57 )
V_36 -> V_58 |= V_59 ;
if ( V_43 -> V_60 == V_61 ||
V_43 -> V_60 == V_62 ) {
if ( V_4 && ( V_4 -> V_47 . V_48 &
V_63 ) )
V_36 -> V_58 |= V_64 ;
if ( V_4 && ( V_4 -> V_51 . V_65 ) )
V_36 -> V_58 |= V_66 ;
} else {
if ( V_43 -> V_67 )
V_36 -> V_58 |= V_64 ;
if ( V_43 -> V_68 )
V_36 -> V_58 |= V_66 ;
}
if ( V_44 || V_45 || V_46 )
V_36 -> V_58 |= V_69 ;
if ( V_4 && V_4 -> V_47 . V_70 &&
( ( V_15 == V_33 ) ||
( V_15 == V_25 ) ) )
V_36 -> V_58 |= V_71 ;
}
}
static void F_5 ( void * V_72 , struct V_3 * V_4 ,
void * V_73 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = V_72 ;
struct V_5 * V_6 = V_38 -> V_6 ;
struct V_74 * V_75 = F_6 ( V_6 ) ;
struct V_35 * V_76 = V_75 -> V_77 . V_76 ;
T_2 V_78 = F_7 ( V_6 ) ;
T_1 V_79 , V_80 , V_40 ;
bool V_7 = ! F_8 ( V_78 ) ;
if ( F_9 ( V_4 , V_73 , V_38 ) )
return;
V_40 = F_1 ( V_2 , V_4 , V_6 , V_7 ) ;
V_79 = 1 ;
F_4 ( V_2 , V_4 , & V_76 [ 0 ] , V_38 ,
V_79 , V_40 , 1 , V_7 ) ;
if ( ! V_7 ) {
for ( V_80 = 1 ; V_80 < 4 ; V_80 ++ )
F_4 ( V_2 , V_4 , & V_76 [ V_80 ] ,
V_38 , V_80 , ( V_40 - V_80 ) , 1 ,
V_7 ) ;
}
}
static bool F_10 ( struct V_1 * V_2 ,
struct V_13 * V_14 , T_3 V_81 )
{
struct V_42 * V_43 = V_42 ( V_2 ) ;
if ( V_43 -> V_82 )
return false ;
if ( V_43 -> V_60 == V_83 &&
V_43 -> V_84 < 3 )
return false ;
if ( V_14 -> V_85 [ V_81 ] . V_86 . V_87 == V_88 )
return true ;
return false ;
}
static void F_11 ( void * V_72 ,
struct V_89 * V_90 ,
struct V_3 * V_4 , void * V_73 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = V_72 ;
struct V_42 * V_43 = V_42 ( V_2 ) ;
struct V_91 * V_92 = F_12 ( V_6 ) ;
T_2 V_78 = F_7 ( V_6 ) ;
struct V_13 * V_14 ;
if ( ! V_73 || ! F_8 ( V_78 ) )
return;
if ( F_2 ( V_43 -> V_18 , V_6 , true ) )
return;
if ( F_13 ( F_14 ( V_92 ) ) ||
F_15 ( F_14 ( V_92 ) ) )
return;
if ( V_4 ) {
V_14 = (struct V_13 * ) V_4 -> V_16 ;
if ( ( V_4 -> V_47 . V_70 ) &&
! ( V_6 -> V_93 == F_16 ( V_94 ) ) ) {
if ( F_17 ( V_78 ) ) {
T_1 V_81 = F_18 ( V_6 ) ;
if ( F_10 ( V_2 , V_14 ,
V_81 ) ) {
V_14 -> V_85 [ V_81 ] . V_86 . V_87 =
V_95 ;
F_19 ( V_4 , V_81 ,
5000 ) ;
}
}
}
}
}
static void F_20 ( void * V_72 ,
struct V_89 * V_90 ,
struct V_96 * V_97 ,
struct V_3 * V_4 , void * V_73 )
{
}
static void F_21 ( void * V_72 ,
struct V_89 * V_90 ,
struct V_96 * V_97 ,
struct V_3 * V_4 , void * V_73 ,
T_4 V_98 )
{
}
static void * F_22 ( struct V_99 * V_18 , struct V_100 * V_101 )
{
struct V_1 * V_2 = V_1 ( V_18 ) ;
return V_2 ;
}
static void F_23 ( void * V_2 )
{
return;
}
static void * F_24 ( void * V_72 ,
struct V_3 * V_4 , T_5 V_102 )
{
struct V_1 * V_2 = V_72 ;
struct V_103 * V_104 ;
V_104 = F_25 ( sizeof( struct V_103 ) , V_102 ) ;
if ( ! V_104 ) {
F_26 ( V_2 , V_105 , V_106 ,
L_1 ) ;
return NULL ;
}
V_2 -> V_104 = V_104 ;
return V_104 ;
}
static void F_27 ( void * V_2 ,
struct V_3 * V_4 , void * V_73 )
{
struct V_103 * V_104 = V_73 ;
F_28 ( V_104 ) ;
}
int F_29 ( void )
{
return F_30 ( & V_107 ) ;
}
void F_31 ( void )
{
F_32 ( & V_107 ) ;
}
