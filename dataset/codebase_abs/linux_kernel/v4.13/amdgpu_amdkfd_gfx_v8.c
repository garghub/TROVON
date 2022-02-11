struct V_1 * F_1 ( void )
{
return (struct V_1 * ) & V_2 ;
}
static inline struct V_3 * F_2 ( struct V_4 * V_5 )
{
return (struct V_3 * ) V_5 ;
}
static void F_3 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 ,
T_1 V_8 , T_1 V_9 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_11 = F_4 ( V_7 ) | F_5 ( V_6 ) | F_6 ( V_9 ) | F_7 ( V_8 ) ;
F_8 ( & V_10 -> V_12 ) ;
F_9 ( V_13 , V_11 ) ;
}
static void F_10 ( struct V_4 * V_5 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
F_9 ( V_13 , 0 ) ;
F_11 ( & V_10 -> V_12 ) ;
}
static void F_12 ( struct V_4 * V_5 , T_1 V_14 ,
T_1 V_15 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_6 = ( ++ V_14 / V_10 -> V_16 . V_6 . V_17 ) + 1 ;
T_1 V_7 = ( V_14 % V_10 -> V_16 . V_6 . V_17 ) ;
F_3 ( V_5 , V_6 , V_7 , V_15 , 0 ) ;
}
static void F_13 ( struct V_4 * V_5 )
{
F_10 ( V_5 ) ;
}
static void F_14 ( struct V_4 * V_5 , T_1 V_9 ,
T_1 V_18 ,
T_1 V_19 ,
T_1 V_20 ,
T_1 V_21 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
F_3 ( V_5 , 0 , 0 , 0 , V_9 ) ;
F_9 ( V_22 , V_18 ) ;
F_9 ( V_23 , V_19 ) ;
F_9 ( V_24 , V_20 ) ;
F_9 ( V_25 , V_21 ) ;
F_10 ( V_5 ) ;
}
static int F_15 ( struct V_4 * V_5 , unsigned int V_26 ,
unsigned int V_9 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_27 = ( V_26 == 0 ) ? 0 : ( T_1 ) V_26 |
V_28 ;
F_9 ( V_29 + V_9 , V_27 ) ;
while ( ! ( F_16 ( V_30 ) & ( 1U << V_9 ) ) )
F_17 () ;
F_9 ( V_30 , 1U << V_9 ) ;
F_9 ( V_31 + V_9 , V_27 ) ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 , T_1 V_14 ,
T_1 V_32 , T_2 V_33 )
{
return 0 ;
}
static int F_19 ( struct V_4 * V_5 , T_1 V_14 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_6 ;
T_1 V_7 ;
V_6 = ( ++ V_14 / V_10 -> V_16 . V_6 . V_17 ) + 1 ;
V_7 = ( V_14 % V_10 -> V_16 . V_6 . V_17 ) ;
F_3 ( V_5 , V_6 , V_7 , 0 , 0 ) ;
F_9 ( V_34 , V_35 ) ;
F_10 ( V_5 ) ;
return 0 ;
}
static inline T_1 F_20 ( struct V_36 * V_37 )
{
return 0 ;
}
static inline struct V_38 * F_21 ( void * V_39 )
{
return (struct V_38 * ) V_39 ;
}
static inline struct V_36 * F_22 ( void * V_39 )
{
return (struct V_36 * ) V_39 ;
}
static int F_23 ( struct V_4 * V_5 , void * V_39 , T_1 V_14 ,
T_1 V_15 , T_1 T_3 * V_40 )
{
struct V_38 * V_37 ;
T_1 V_41 , V_42 ;
struct V_3 * V_10 = F_2 ( V_5 ) ;
V_37 = F_21 ( V_39 ) ;
V_42 = F_24 ( & V_41 , V_40 , sizeof( V_41 ) ) ;
if ( V_42 == 0 )
V_37 -> V_43 = V_41 ;
F_12 ( V_5 , V_14 , V_15 ) ;
F_25 ( V_10 , V_39 ) ;
F_13 ( V_5 ) ;
return 0 ;
}
static int F_26 ( struct V_4 * V_5 , void * V_39 )
{
return 0 ;
}
static bool F_27 ( struct V_4 * V_5 , T_2 V_44 ,
T_1 V_14 , T_1 V_15 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_45 ;
bool V_46 = false ;
T_1 V_47 , V_48 ;
F_12 ( V_5 , V_14 , V_15 ) ;
V_45 = F_16 ( V_49 ) ;
if ( V_45 ) {
V_47 = F_28 ( V_44 >> 8 ) ;
V_48 = F_29 ( V_44 >> 8 ) ;
if ( V_47 == F_16 ( V_50 ) &&
V_48 == F_16 ( V_51 ) )
V_46 = true ;
}
F_13 ( V_5 ) ;
return V_46 ;
}
static bool F_30 ( struct V_4 * V_5 , void * V_39 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
struct V_36 * V_37 ;
T_1 V_52 ;
T_1 V_53 ;
V_37 = F_22 ( V_39 ) ;
V_52 = F_20 ( V_37 ) ;
V_53 = F_16 ( V_52 + V_54 ) ;
if ( V_53 & V_55 )
return true ;
return false ;
}
static int F_31 ( struct V_4 * V_5 , T_1 V_56 ,
unsigned int V_57 , T_1 V_14 ,
T_1 V_15 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_58 ;
int V_59 = V_57 ;
F_12 ( V_5 , V_14 , V_15 ) ;
F_9 ( V_60 , V_56 ) ;
while ( true ) {
V_58 = F_16 ( V_49 ) ;
if ( V_58 & V_61 )
break;
if ( V_59 <= 0 ) {
F_32 ( L_1 ) ;
F_13 ( V_5 ) ;
return - V_62 ;
}
F_33 ( 20 ) ;
V_59 -= 20 ;
}
F_13 ( V_5 ) ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 , void * V_39 ,
unsigned int V_57 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
struct V_36 * V_37 ;
T_1 V_52 ;
T_1 V_58 ;
int V_59 = V_57 ;
V_37 = F_22 ( V_39 ) ;
V_52 = F_20 ( V_37 ) ;
V_58 = F_16 ( V_52 + V_54 ) ;
V_58 = V_58 & ~ V_55 ;
F_9 ( V_52 + V_54 , V_58 ) ;
while ( true ) {
V_58 = F_16 ( V_52 + V_63 ) ;
if ( V_58 & V_64 )
break;
if ( V_59 <= 0 )
return - V_62 ;
F_33 ( 20 ) ;
V_59 -= 20 ;
}
F_9 ( V_52 + V_65 , 0 ) ;
F_9 ( V_52 + V_66 , 0 ) ;
F_9 ( V_52 + V_67 , 0 ) ;
F_9 ( V_52 + V_68 , 0 ) ;
return 0 ;
}
static bool F_35 ( struct V_4 * V_5 ,
T_4 V_9 )
{
T_1 V_69 ;
struct V_3 * V_10 = (struct V_3 * ) V_5 ;
V_69 = F_16 ( V_29 + V_9 ) ;
return V_69 & V_28 ;
}
static T_5 F_36 ( struct V_4 * V_5 ,
T_4 V_9 )
{
T_1 V_69 ;
struct V_3 * V_10 = (struct V_3 * ) V_5 ;
V_69 = F_16 ( V_29 + V_9 ) ;
return V_69 & V_28 ;
}
static void F_37 ( struct V_4 * V_5 , T_4 V_9 )
{
struct V_3 * V_10 = (struct V_3 * ) V_5 ;
F_9 ( V_70 , 1 << V_9 ) ;
}
static int F_38 ( struct V_4 * V_5 )
{
return 0 ;
}
static int F_39 ( struct V_4 * V_5 ,
unsigned int V_71 ,
T_1 V_72 ,
T_1 V_73 ,
T_1 V_74 )
{
return 0 ;
}
static int F_40 ( struct V_4 * V_5 ,
T_1 V_75 ,
T_1 V_76 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_77 = 0 ;
F_8 ( & V_10 -> V_78 ) ;
F_9 ( V_79 , V_75 ) ;
F_9 ( V_80 , V_76 ) ;
V_77 = F_41 ( V_77 , V_81 ,
V_82 , 1 ) ;
V_77 = F_41 ( V_77 , V_81 ,
V_83 , 1 ) ;
V_77 = F_41 ( V_77 , V_81 ,
V_84 , 1 ) ;
F_9 ( V_79 , V_77 ) ;
F_11 ( & V_10 -> V_78 ) ;
return 0 ;
}
static T_1 F_42 ( struct V_4 * V_5 ,
unsigned int V_71 ,
unsigned int V_85 )
{
return 0 ;
}
static T_5 F_43 ( struct V_4 * V_5 , enum V_86 type )
{
struct V_3 * V_10 = (struct V_3 * ) V_5 ;
const union V_87 * V_88 ;
F_44 ( V_5 == NULL ) ;
switch ( type ) {
case V_89 :
V_88 = ( const union V_87 * )
V_10 -> V_16 . V_90 -> V_77 ;
break;
case V_91 :
V_88 = ( const union V_87 * )
V_10 -> V_16 . V_92 -> V_77 ;
break;
case V_93 :
V_88 = ( const union V_87 * )
V_10 -> V_16 . V_94 -> V_77 ;
break;
case V_95 :
V_88 = ( const union V_87 * )
V_10 -> V_16 . V_96 -> V_77 ;
break;
case V_97 :
V_88 = ( const union V_87 * )
V_10 -> V_16 . V_98 -> V_77 ;
break;
case V_99 :
V_88 = ( const union V_87 * )
V_10 -> V_16 . V_100 -> V_77 ;
break;
case V_101 :
V_88 = ( const union V_87 * )
V_10 -> V_102 . V_103 [ 0 ] . V_104 -> V_77 ;
break;
case V_105 :
V_88 = ( const union V_87 * )
V_10 -> V_102 . V_103 [ 1 ] . V_104 -> V_77 ;
break;
default:
return 0 ;
}
if ( V_88 == NULL )
return 0 ;
return V_88 -> V_106 . V_107 ;
}
