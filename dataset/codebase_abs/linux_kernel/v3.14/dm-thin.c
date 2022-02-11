static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , struct V_4 * V_5 )
{
V_5 -> V_6 = 0 ;
V_5 -> V_7 = F_2 ( V_2 ) ;
V_5 -> V_8 = V_3 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
V_5 -> V_6 = 1 ;
V_5 -> V_7 = F_2 ( V_2 ) ;
V_5 -> V_8 = V_3 ;
}
static void F_4 ( struct V_9 * V_9 )
{
F_5 ( V_9 -> V_10 , & V_9 -> V_11 ) ;
}
static int F_6 ( struct V_9 * V_9 , struct V_4 * V_5 , struct V_12 * V_12 ,
struct V_13 * * V_14 )
{
int V_15 ;
struct V_13 * V_16 ;
V_16 = F_7 ( V_9 -> V_17 , V_18 ) ;
V_15 = F_8 ( V_9 -> V_17 , V_5 , V_12 , V_16 , V_14 ) ;
if ( V_15 )
F_9 ( V_9 -> V_17 , V_16 ) ;
return V_15 ;
}
static void F_10 ( struct V_9 * V_9 ,
struct V_13 * V_19 ,
struct V_20 * V_21 )
{
F_11 ( V_9 -> V_17 , V_19 , V_21 ) ;
F_9 ( V_9 -> V_17 , V_19 ) ;
}
static void F_12 ( struct V_9 * V_9 ,
struct V_13 * V_19 ,
struct V_20 * V_21 )
{
F_13 ( V_9 -> V_17 , V_19 , V_21 ) ;
F_9 ( V_9 -> V_17 , V_19 ) ;
}
static void F_14 ( struct V_22 * V_23 ,
struct V_13 * V_19 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_13 ( V_9 -> V_17 , V_19 , & V_9 -> V_26 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
static void F_17 ( struct V_9 * V_9 ,
struct V_13 * V_19 )
{
F_18 ( V_9 -> V_17 , V_19 ) ;
F_9 ( V_9 -> V_17 , V_19 ) ;
}
static void F_19 ( void )
{
F_20 ( & V_27 . V_28 ) ;
F_21 ( & V_27 . V_29 ) ;
}
static void F_22 ( struct V_9 * V_9 )
{
F_23 ( ! F_24 ( & V_27 . V_28 ) ) ;
F_25 ( & V_9 -> V_30 , & V_27 . V_29 ) ;
}
static void F_26 ( struct V_9 * V_9 )
{
F_23 ( ! F_24 ( & V_27 . V_28 ) ) ;
F_27 ( & V_9 -> V_30 ) ;
}
static struct V_9 * F_28 ( struct V_31 * V_32 )
{
struct V_9 * V_9 = NULL , * V_33 ;
F_23 ( ! F_24 ( & V_27 . V_28 ) ) ;
F_29 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_33 -> V_34 == V_32 ) {
V_9 = V_33 ;
break;
}
}
return V_9 ;
}
static struct V_9 * F_30 ( struct V_35 * V_36 )
{
struct V_9 * V_9 = NULL , * V_33 ;
F_23 ( ! F_24 ( & V_27 . V_28 ) ) ;
F_29 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_33 -> V_36 == V_36 ) {
V_9 = V_33 ;
break;
}
}
return V_9 ;
}
static void F_31 ( struct V_22 * V_23 , struct V_20 * V_37 )
{
struct V_12 * V_12 ;
struct V_20 V_21 ;
unsigned long V_24 ;
F_32 ( & V_21 ) ;
F_15 ( & V_23 -> V_9 -> V_25 , V_24 ) ;
F_33 ( & V_21 , V_37 ) ;
F_32 ( V_37 ) ;
F_16 ( & V_23 -> V_9 -> V_25 , V_24 ) ;
while ( ( V_12 = F_34 ( & V_21 ) ) ) {
struct V_38 * V_39 = F_35 ( V_12 , sizeof( struct V_38 ) ) ;
if ( V_39 -> V_23 == V_23 )
F_36 ( V_12 , V_40 ) ;
else
F_37 ( V_37 , V_12 ) ;
}
}
static void F_38 ( struct V_22 * V_23 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
F_31 ( V_23 , & V_9 -> V_26 ) ;
F_31 ( V_23 , & V_9 -> V_41 ) ;
}
static void F_39 ( struct V_9 * V_9 )
{
struct V_12 * V_12 ;
unsigned long V_24 ;
struct V_20 V_21 ;
F_32 ( & V_21 ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_33 ( & V_21 , & V_9 -> V_41 ) ;
F_32 ( & V_9 -> V_41 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
while ( ( V_12 = F_34 ( & V_21 ) ) )
F_40 ( V_12 ) ;
}
static bool F_41 ( struct V_9 * V_9 )
{
return V_9 -> V_42 >= 0 ;
}
static T_1 F_42 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
T_2 V_43 = V_12 -> V_44 . V_45 ;
if ( F_41 ( V_9 ) )
V_43 >>= V_9 -> V_42 ;
else
( void ) F_43 ( V_43 , V_9 -> V_46 ) ;
return V_43 ;
}
static void F_44 ( struct V_22 * V_23 , struct V_12 * V_12 , T_1 V_8 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
T_2 V_45 = V_12 -> V_44 . V_45 ;
V_12 -> V_47 = V_23 -> V_48 -> V_49 ;
if ( F_41 ( V_9 ) )
V_12 -> V_44 . V_45 =
( V_8 << V_9 -> V_42 ) |
( V_45 & ( V_9 -> V_46 - 1 ) ) ;
else
V_12 -> V_44 . V_45 = ( V_8 * V_9 -> V_46 ) +
F_43 ( V_45 , V_9 -> V_46 ) ;
}
static void F_45 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
V_12 -> V_47 = V_23 -> V_50 -> V_49 ;
}
static int F_46 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
return ( V_12 -> V_51 & ( V_52 | V_53 ) ) &&
F_47 ( V_23 -> V_2 ) ;
}
static void F_48 ( struct V_9 * V_9 , struct V_12 * V_12 )
{
struct V_38 * V_39 ;
if ( V_12 -> V_51 & V_54 )
return;
V_39 = F_35 ( V_12 , sizeof( struct V_38 ) ) ;
V_39 -> V_55 = F_49 ( V_9 -> V_56 ) ;
}
static void F_50 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
if ( ! F_46 ( V_23 , V_12 ) ) {
F_51 ( V_12 ) ;
return;
}
if ( F_52 ( V_23 -> V_2 ) ) {
F_40 ( V_12 ) ;
return;
}
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_37 ( & V_9 -> V_57 , V_12 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
static void F_53 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
F_45 ( V_23 , V_12 ) ;
F_50 ( V_23 , V_12 ) ;
}
static void F_54 ( struct V_22 * V_23 , struct V_12 * V_12 ,
T_1 V_8 )
{
F_44 ( V_23 , V_12 , V_8 ) ;
F_50 ( V_23 , V_12 ) ;
}
static void F_55 ( struct V_58 * V_59 )
{
struct V_9 * V_9 = V_59 -> V_23 -> V_9 ;
if ( V_59 -> V_60 && V_59 -> V_61 ) {
F_56 ( & V_59 -> V_30 , & V_9 -> V_62 ) ;
F_4 ( V_9 ) ;
}
}
static void F_57 ( int V_63 , unsigned long V_64 , void * V_65 )
{
unsigned long V_24 ;
struct V_58 * V_59 = V_65 ;
struct V_9 * V_9 = V_59 -> V_23 -> V_9 ;
V_59 -> V_66 = V_63 || V_64 ? - V_67 : 0 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_59 -> V_61 = true ;
F_55 ( V_59 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
static void F_58 ( struct V_12 * V_12 , int V_66 )
{
unsigned long V_24 ;
struct V_38 * V_39 = F_35 ( V_12 , sizeof( struct V_38 ) ) ;
struct V_58 * V_59 = V_39 -> V_68 ;
struct V_9 * V_9 = V_59 -> V_23 -> V_9 ;
V_59 -> V_66 = V_66 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_59 -> V_61 = true ;
F_55 ( V_59 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
static void F_59 ( struct V_22 * V_23 , struct V_13 * V_19 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_10 ( V_9 , V_19 , & V_9 -> V_26 ) ;
F_16 ( & V_23 -> V_9 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
static void F_60 ( struct V_22 * V_23 , struct V_13 * V_19 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_12 ( V_9 , V_19 , & V_9 -> V_26 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
static void F_61 ( struct V_58 * V_59 )
{
if ( V_59 -> V_12 ) {
V_59 -> V_12 -> V_69 = V_59 -> V_70 ;
F_62 ( & V_59 -> V_12 -> V_71 ) ;
}
F_17 ( V_59 -> V_23 -> V_9 , V_59 -> V_19 ) ;
F_27 ( & V_59 -> V_30 ) ;
F_63 ( V_59 , V_59 -> V_23 -> V_9 -> V_72 ) ;
}
static void F_64 ( struct V_58 * V_59 )
{
struct V_22 * V_23 = V_59 -> V_23 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_12 * V_12 ;
int V_15 ;
V_12 = V_59 -> V_12 ;
if ( V_12 ) {
V_12 -> V_69 = V_59 -> V_70 ;
F_62 ( & V_12 -> V_71 ) ;
}
if ( V_59 -> V_66 ) {
F_17 ( V_9 , V_59 -> V_19 ) ;
goto V_73;
}
V_15 = F_65 ( V_23 -> V_2 , V_59 -> V_74 , V_59 -> V_75 ) ;
if ( V_15 ) {
F_66 ( V_9 , L_1 , V_15 ) ;
F_17 ( V_9 , V_59 -> V_19 ) ;
goto V_73;
}
if ( V_12 ) {
F_60 ( V_23 , V_59 -> V_19 ) ;
F_36 ( V_12 , 0 ) ;
} else
F_59 ( V_23 , V_59 -> V_19 ) ;
V_73:
F_27 ( & V_59 -> V_30 ) ;
F_63 ( V_59 , V_9 -> V_72 ) ;
}
static void F_67 ( struct V_58 * V_59 )
{
struct V_22 * V_23 = V_59 -> V_23 ;
F_40 ( V_59 -> V_12 ) ;
F_60 ( V_23 , V_59 -> V_19 ) ;
F_60 ( V_23 , V_59 -> V_76 ) ;
F_63 ( V_59 , V_23 -> V_9 -> V_72 ) ;
}
static void F_68 ( struct V_58 * V_59 )
{
struct V_22 * V_23 = V_59 -> V_23 ;
F_48 ( V_23 -> V_9 , V_59 -> V_12 ) ;
F_60 ( V_23 , V_59 -> V_19 ) ;
F_60 ( V_23 , V_59 -> V_76 ) ;
if ( V_59 -> V_77 )
if ( V_59 -> V_78 )
F_54 ( V_23 , V_59 -> V_12 , V_59 -> V_75 ) ;
else {
bool V_79 = false ;
if ( F_69 ( V_23 -> V_9 -> V_80 , V_59 -> V_75 , & V_79 ) || V_79 )
F_36 ( V_59 -> V_12 , 0 ) ;
else
F_54 ( V_23 , V_59 -> V_12 , V_59 -> V_75 ) ;
}
else
F_36 ( V_59 -> V_12 , 0 ) ;
F_63 ( V_59 , V_23 -> V_9 -> V_72 ) ;
}
static void F_70 ( struct V_58 * V_59 )
{
int V_15 ;
struct V_22 * V_23 = V_59 -> V_23 ;
V_15 = F_71 ( V_23 -> V_2 , V_59 -> V_74 ) ;
if ( V_15 )
F_72 ( L_2 ) ;
F_68 ( V_59 ) ;
}
static void F_73 ( struct V_9 * V_9 , struct V_81 * V_82 ,
T_3 * V_83 )
{
unsigned long V_24 ;
struct V_81 V_84 ;
struct V_58 * V_59 , * V_33 ;
F_21 ( & V_84 ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_74 ( V_82 , & V_84 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_75 ( V_59 , V_33 , & V_84 , V_30 )
( * V_83 ) ( V_59 ) ;
}
static int F_76 ( struct V_9 * V_9 , struct V_12 * V_12 )
{
return V_12 -> V_44 . V_85 ==
( V_9 -> V_46 << V_86 ) ;
}
static int F_77 ( struct V_9 * V_9 , struct V_12 * V_12 )
{
return ( F_78 ( V_12 ) == V_87 ) &&
F_76 ( V_9 , V_12 ) ;
}
static void F_79 ( struct V_12 * V_12 , T_4 * * V_88 ,
T_4 * V_83 )
{
* V_88 = V_12 -> V_69 ;
V_12 -> V_69 = V_83 ;
}
static int F_80 ( struct V_9 * V_9 )
{
if ( V_9 -> V_89 )
return 0 ;
V_9 -> V_89 = F_81 ( V_9 -> V_72 , V_90 ) ;
return V_9 -> V_89 ? 0 : - V_91 ;
}
static struct V_58 * F_82 ( struct V_9 * V_9 )
{
struct V_58 * V_59 = V_9 -> V_89 ;
F_23 ( ! V_9 -> V_89 ) ;
memset ( V_59 , 0 , sizeof( struct V_58 ) ) ;
F_21 ( & V_59 -> V_30 ) ;
V_59 -> V_12 = NULL ;
V_9 -> V_89 = NULL ;
return V_59 ;
}
static void F_83 ( struct V_22 * V_23 , T_1 V_74 ,
struct V_92 * V_93 , T_1 V_94 ,
T_1 V_95 ,
struct V_13 * V_19 , struct V_12 * V_12 )
{
int V_15 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_58 * V_59 = F_82 ( V_9 ) ;
V_59 -> V_23 = V_23 ;
V_59 -> V_74 = V_74 ;
V_59 -> V_75 = V_95 ;
V_59 -> V_19 = V_19 ;
if ( ! F_84 ( V_9 -> V_96 , & V_59 -> V_30 ) )
V_59 -> V_60 = true ;
if ( F_77 ( V_9 , V_12 ) ) {
struct V_38 * V_39 = F_35 ( V_12 , sizeof( struct V_38 ) ) ;
V_39 -> V_68 = V_59 ;
V_59 -> V_12 = V_12 ;
F_79 ( V_12 , & V_59 -> V_70 , F_58 ) ;
F_48 ( V_9 , V_12 ) ;
F_54 ( V_23 , V_12 , V_95 ) ;
} else {
struct V_97 V_98 , V_99 ;
V_98 . V_49 = V_93 -> V_49 ;
V_98 . V_100 = V_94 * V_9 -> V_46 ;
V_98 . V_101 = V_9 -> V_46 ;
V_99 . V_49 = V_23 -> V_48 -> V_49 ;
V_99 . V_100 = V_95 * V_9 -> V_46 ;
V_99 . V_101 = V_9 -> V_46 ;
V_15 = F_85 ( V_9 -> V_102 , & V_98 , 1 , & V_99 ,
0 , F_57 , V_59 ) ;
if ( V_15 < 0 ) {
F_63 ( V_59 , V_9 -> V_72 ) ;
F_72 ( L_3 ) ;
F_17 ( V_9 , V_19 ) ;
}
}
}
static void F_86 ( struct V_22 * V_23 , T_1 V_74 ,
T_1 V_94 , T_1 V_95 ,
struct V_13 * V_19 , struct V_12 * V_12 )
{
F_83 ( V_23 , V_74 , V_23 -> V_48 ,
V_94 , V_95 , V_19 , V_12 ) ;
}
static void F_87 ( struct V_22 * V_23 , T_1 V_74 ,
T_1 V_95 ,
struct V_13 * V_19 , struct V_12 * V_12 )
{
F_83 ( V_23 , V_74 , V_23 -> V_50 ,
V_74 , V_95 , V_19 , V_12 ) ;
}
static void F_88 ( struct V_22 * V_23 , T_1 V_74 ,
T_1 V_75 , struct V_13 * V_19 ,
struct V_12 * V_12 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_58 * V_59 = F_82 ( V_9 ) ;
V_59 -> V_60 = true ;
V_59 -> V_61 = false ;
V_59 -> V_23 = V_23 ;
V_59 -> V_74 = V_74 ;
V_59 -> V_75 = V_75 ;
V_59 -> V_19 = V_19 ;
if ( ! V_9 -> V_103 . V_104 )
F_64 ( V_59 ) ;
else if ( F_77 ( V_9 , V_12 ) ) {
struct V_38 * V_39 = F_35 ( V_12 , sizeof( struct V_38 ) ) ;
V_39 -> V_68 = V_59 ;
V_59 -> V_12 = V_12 ;
F_79 ( V_12 , & V_59 -> V_70 , F_58 ) ;
F_48 ( V_9 , V_12 ) ;
F_54 ( V_23 , V_12 , V_75 ) ;
} else {
int V_15 ;
struct V_97 V_99 ;
V_99 . V_49 = V_23 -> V_48 -> V_49 ;
V_99 . V_100 = V_75 * V_9 -> V_46 ;
V_99 . V_101 = V_9 -> V_46 ;
V_15 = F_89 ( V_9 -> V_102 , 1 , & V_99 , 0 , F_57 , V_59 ) ;
if ( V_15 < 0 ) {
F_63 ( V_59 , V_9 -> V_72 ) ;
F_72 ( L_4 ) ;
F_17 ( V_9 , V_19 ) ;
}
}
}
static int F_90 ( struct V_9 * V_9 )
{
int V_15 ;
if ( F_91 ( V_9 ) != V_105 )
return - V_106 ;
V_15 = F_92 ( V_9 -> V_80 ) ;
if ( V_15 )
F_66 ( V_9 , L_5 , V_15 ) ;
return V_15 ;
}
static void F_93 ( struct V_9 * V_9 , T_1 V_107 )
{
unsigned long V_24 ;
if ( V_107 <= V_9 -> V_108 && ! V_9 -> V_109 ) {
F_94 ( L_6 ,
F_95 ( V_9 -> V_34 ) ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_9 -> V_109 = true ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_96 ( V_9 -> V_110 -> V_111 ) ;
}
}
static int F_97 ( struct V_22 * V_23 , T_1 * V_112 )
{
int V_15 ;
T_1 V_107 ;
struct V_9 * V_9 = V_23 -> V_9 ;
if ( F_98 ( F_91 ( V_9 ) != V_105 ) )
return - V_106 ;
V_15 = F_99 ( V_9 -> V_80 , & V_107 ) ;
if ( V_15 ) {
F_66 ( V_9 , L_7 , V_15 ) ;
return V_15 ;
}
F_93 ( V_9 , V_107 ) ;
if ( ! V_107 ) {
V_15 = F_90 ( V_9 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_99 ( V_9 -> V_80 , & V_107 ) ;
if ( V_15 ) {
F_66 ( V_9 , L_7 , V_15 ) ;
return V_15 ;
}
if ( ! V_107 ) {
F_100 ( V_9 , V_113 ) ;
return - V_114 ;
}
}
V_15 = F_101 ( V_9 -> V_80 , V_112 ) ;
if ( V_15 ) {
F_66 ( V_9 , L_8 , V_15 ) ;
return V_15 ;
}
return 0 ;
}
static void F_102 ( struct V_12 * V_12 )
{
struct V_38 * V_39 = F_35 ( V_12 , sizeof( struct V_38 ) ) ;
struct V_22 * V_23 = V_39 -> V_23 ;
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_37 ( & V_9 -> V_41 , V_12 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
static bool F_103 ( struct V_9 * V_9 )
{
enum V_115 V_59 = F_91 ( V_9 ) ;
switch ( V_59 ) {
case V_105 :
F_72 ( L_9 ) ;
return true ;
case V_113 :
return V_9 -> V_103 . V_116 ;
case V_117 :
case V_118 :
return true ;
default:
F_72 ( L_10 ) ;
return true ;
}
}
static void F_104 ( struct V_9 * V_9 , struct V_12 * V_12 )
{
if ( F_103 ( V_9 ) )
F_40 ( V_12 ) ;
else
F_102 ( V_12 ) ;
}
static void F_105 ( struct V_9 * V_9 , struct V_13 * V_19 )
{
struct V_12 * V_12 ;
struct V_20 V_21 ;
if ( F_103 ( V_9 ) ) {
F_17 ( V_9 , V_19 ) ;
return;
}
F_32 ( & V_21 ) ;
F_10 ( V_9 , V_19 , & V_21 ) ;
if ( F_103 ( V_9 ) )
while ( ( V_12 = F_34 ( & V_21 ) ) )
F_40 ( V_12 ) ;
else
while ( ( V_12 = F_34 ( & V_21 ) ) )
F_102 ( V_12 ) ;
}
static void F_106 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
int V_15 ;
unsigned long V_24 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_13 * V_19 , * V_76 ;
struct V_4 V_5 , V_119 ;
T_1 V_8 = F_42 ( V_23 , V_12 ) ;
struct V_120 V_121 ;
struct V_58 * V_59 ;
F_3 ( V_23 -> V_2 , V_8 , & V_5 ) ;
if ( F_6 ( V_23 -> V_9 , & V_5 , V_12 , & V_19 ) )
return;
V_15 = F_107 ( V_23 -> V_2 , V_8 , 1 , & V_121 ) ;
switch ( V_15 ) {
case 0 :
F_1 ( V_23 -> V_2 , V_121 . V_8 , & V_119 ) ;
if ( F_6 ( V_23 -> V_9 , & V_119 , V_12 , & V_76 ) ) {
F_60 ( V_23 , V_19 ) ;
break;
}
if ( F_76 ( V_9 , V_12 ) ) {
V_59 = F_82 ( V_9 ) ;
V_59 -> V_23 = V_23 ;
V_59 -> V_77 = V_9 -> V_103 . V_122 ;
V_59 -> V_78 = ! V_121 . V_123 ;
V_59 -> V_74 = V_8 ;
V_59 -> V_75 = V_121 . V_8 ;
V_59 -> V_19 = V_19 ;
V_59 -> V_76 = V_76 ;
V_59 -> V_12 = V_12 ;
if ( ! F_84 ( V_9 -> V_56 , & V_59 -> V_30 ) ) {
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_56 ( & V_59 -> V_30 , & V_9 -> V_124 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
} else {
F_48 ( V_9 , V_12 ) ;
F_60 ( V_23 , V_19 ) ;
F_60 ( V_23 , V_76 ) ;
if ( ( ! V_121 . V_123 ) && V_9 -> V_103 . V_122 )
F_54 ( V_23 , V_12 , V_121 . V_8 ) ;
else
F_36 ( V_12 , 0 ) ;
}
break;
case - V_125 :
F_60 ( V_23 , V_19 ) ;
F_36 ( V_12 , 0 ) ;
break;
default:
F_72 ( L_11 ,
V_126 , V_15 ) ;
F_60 ( V_23 , V_19 ) ;
F_40 ( V_12 ) ;
break;
}
}
static void F_108 ( struct V_22 * V_23 , struct V_12 * V_12 , T_1 V_8 ,
struct V_4 * V_5 ,
struct V_120 * V_121 ,
struct V_13 * V_19 )
{
int V_15 ;
T_1 V_75 ;
struct V_9 * V_9 = V_23 -> V_9 ;
V_15 = F_97 ( V_23 , & V_75 ) ;
switch ( V_15 ) {
case 0 :
F_86 ( V_23 , V_8 , V_121 -> V_8 ,
V_75 , V_19 , V_12 ) ;
break;
case - V_114 :
F_105 ( V_9 , V_19 ) ;
break;
default:
F_72 ( L_12 ,
V_126 , V_15 ) ;
F_17 ( V_9 , V_19 ) ;
break;
}
}
static void F_109 ( struct V_22 * V_23 , struct V_12 * V_12 ,
T_1 V_8 ,
struct V_120 * V_121 )
{
struct V_13 * V_19 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_4 V_5 ;
F_1 ( V_23 -> V_2 , V_121 -> V_8 , & V_5 ) ;
if ( F_6 ( V_9 , & V_5 , V_12 , & V_19 ) )
return;
if ( F_78 ( V_12 ) == V_87 && V_12 -> V_44 . V_85 )
F_108 ( V_23 , V_12 , V_8 , & V_5 , V_121 , V_19 ) ;
else {
struct V_38 * V_39 = F_35 ( V_12 , sizeof( struct V_38 ) ) ;
V_39 -> V_127 = F_49 ( V_9 -> V_96 ) ;
F_48 ( V_9 , V_12 ) ;
F_60 ( V_23 , V_19 ) ;
F_54 ( V_23 , V_12 , V_121 -> V_8 ) ;
}
}
static void F_110 ( struct V_22 * V_23 , struct V_12 * V_12 , T_1 V_8 ,
struct V_13 * V_19 )
{
int V_15 ;
T_1 V_75 ;
struct V_9 * V_9 = V_23 -> V_9 ;
if ( ! V_12 -> V_44 . V_85 ) {
F_48 ( V_9 , V_12 ) ;
F_60 ( V_23 , V_19 ) ;
F_54 ( V_23 , V_12 , 0 ) ;
return;
}
if ( F_78 ( V_12 ) == V_128 ) {
F_111 ( V_12 ) ;
F_60 ( V_23 , V_19 ) ;
F_36 ( V_12 , 0 ) ;
return;
}
V_15 = F_97 ( V_23 , & V_75 ) ;
switch ( V_15 ) {
case 0 :
if ( V_23 -> V_50 )
F_87 ( V_23 , V_8 , V_75 , V_19 , V_12 ) ;
else
F_88 ( V_23 , V_8 , V_75 , V_19 , V_12 ) ;
break;
case - V_114 :
F_105 ( V_9 , V_19 ) ;
break;
default:
F_72 ( L_12 ,
V_126 , V_15 ) ;
F_17 ( V_9 , V_19 ) ;
break;
}
}
static void F_112 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
int V_15 ;
struct V_9 * V_9 = V_23 -> V_9 ;
T_1 V_8 = F_42 ( V_23 , V_12 ) ;
struct V_13 * V_19 ;
struct V_4 V_5 ;
struct V_120 V_121 ;
F_3 ( V_23 -> V_2 , V_8 , & V_5 ) ;
if ( F_6 ( V_9 , & V_5 , V_12 , & V_19 ) )
return;
V_15 = F_107 ( V_23 -> V_2 , V_8 , 1 , & V_121 ) ;
switch ( V_15 ) {
case 0 :
if ( V_121 . V_123 ) {
F_109 ( V_23 , V_12 , V_8 , & V_121 ) ;
F_60 ( V_23 , V_19 ) ;
} else {
F_48 ( V_9 , V_12 ) ;
F_60 ( V_23 , V_19 ) ;
F_54 ( V_23 , V_12 , V_121 . V_8 ) ;
}
break;
case - V_125 :
if ( F_78 ( V_12 ) == V_128 && V_23 -> V_50 ) {
F_48 ( V_9 , V_12 ) ;
F_60 ( V_23 , V_19 ) ;
F_53 ( V_23 , V_12 ) ;
} else
F_110 ( V_23 , V_12 , V_8 , V_19 ) ;
break;
default:
F_72 ( L_11 ,
V_126 , V_15 ) ;
F_60 ( V_23 , V_19 ) ;
F_40 ( V_12 ) ;
break;
}
}
static void F_113 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
int V_15 ;
int V_129 = F_78 ( V_12 ) ;
T_1 V_8 = F_42 ( V_23 , V_12 ) ;
struct V_120 V_121 ;
V_15 = F_107 ( V_23 -> V_2 , V_8 , 1 , & V_121 ) ;
switch ( V_15 ) {
case 0 :
if ( V_121 . V_123 && ( V_129 == V_87 ) && V_12 -> V_44 . V_85 )
F_104 ( V_23 -> V_9 , V_12 ) ;
else {
F_48 ( V_23 -> V_9 , V_12 ) ;
F_54 ( V_23 , V_12 , V_121 . V_8 ) ;
}
break;
case - V_125 :
if ( V_129 != V_128 ) {
F_104 ( V_23 -> V_9 , V_12 ) ;
break;
}
if ( V_23 -> V_50 ) {
F_48 ( V_23 -> V_9 , V_12 ) ;
F_53 ( V_23 , V_12 ) ;
break;
}
F_111 ( V_12 ) ;
F_36 ( V_12 , 0 ) ;
break;
default:
F_72 ( L_11 ,
V_126 , V_15 ) ;
F_40 ( V_12 ) ;
break;
}
}
static void F_114 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
F_36 ( V_12 , 0 ) ;
}
static void F_115 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
F_40 ( V_12 ) ;
}
static int F_116 ( struct V_9 * V_9 )
{
return V_130 < V_9 -> V_131 ||
V_130 > V_9 -> V_131 + V_132 ;
}
static void F_117 ( struct V_9 * V_9 )
{
unsigned long V_24 ;
struct V_12 * V_12 ;
struct V_20 V_21 ;
F_32 ( & V_21 ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_33 ( & V_21 , & V_9 -> V_26 ) ;
F_32 ( & V_9 -> V_26 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
while ( ( V_12 = F_34 ( & V_21 ) ) ) {
struct V_38 * V_39 = F_35 ( V_12 , sizeof( struct V_38 ) ) ;
struct V_22 * V_23 = V_39 -> V_23 ;
if ( V_23 -> V_133 ) {
F_36 ( V_12 , V_40 ) ;
continue;
}
if ( F_80 ( V_9 ) ) {
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_33 ( & V_9 -> V_26 , & V_21 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
break;
}
if ( V_12 -> V_51 & V_54 )
V_9 -> F_106 ( V_23 , V_12 ) ;
else
V_9 -> F_112 ( V_23 , V_12 ) ;
}
F_32 ( & V_21 ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_33 ( & V_21 , & V_9 -> V_57 ) ;
F_32 ( & V_9 -> V_57 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
if ( F_118 ( & V_21 ) &&
! ( F_119 ( V_9 -> V_80 ) && F_116 ( V_9 ) ) )
return;
if ( F_90 ( V_9 ) ) {
while ( ( V_12 = F_34 ( & V_21 ) ) )
F_40 ( V_12 ) ;
return;
}
V_9 -> V_131 = V_130 ;
while ( ( V_12 = F_34 ( & V_21 ) ) )
F_51 ( V_12 ) ;
}
static void F_120 ( struct V_134 * V_135 )
{
struct V_9 * V_9 = F_121 ( V_135 , struct V_9 , V_11 ) ;
F_73 ( V_9 , & V_9 -> V_62 , & V_9 -> F_64 ) ;
F_73 ( V_9 , & V_9 -> V_124 , & V_9 -> F_70 ) ;
F_117 ( V_9 ) ;
}
static void F_122 ( struct V_134 * V_135 )
{
struct V_9 * V_9 = F_121 ( F_123 ( V_135 ) , struct V_9 , V_136 ) ;
F_4 ( V_9 ) ;
F_124 ( V_9 -> V_10 , & V_9 -> V_136 , V_132 ) ;
}
static void F_125 ( struct V_137 * V_138 )
{
F_126 ( & V_138 -> V_139 , 1 ) ;
F_127 ( & V_138 -> V_140 ) ;
}
static void F_128 ( struct V_134 * V_135 )
{
struct V_137 * V_138 = F_121 ( V_135 , struct V_137 , V_11 ) ;
V_138 -> V_23 -> V_133 = true ;
F_38 ( V_138 -> V_23 ) ;
F_125 ( V_138 ) ;
}
static void F_129 ( struct V_134 * V_135 )
{
struct V_137 * V_138 = F_121 ( V_135 , struct V_137 , V_11 ) ;
V_138 -> V_23 -> V_133 = false ;
F_125 ( V_138 ) ;
}
static void V_137 ( struct V_22 * V_23 , void (* V_83)( struct V_134 * ) )
{
struct V_137 V_138 ;
F_130 ( & V_138 . V_11 , V_83 ) ;
V_138 . V_23 = V_23 ;
F_126 ( & V_138 . V_139 , 0 ) ;
F_131 ( & V_138 . V_140 ) ;
F_5 ( V_23 -> V_9 -> V_10 , & V_138 . V_11 ) ;
F_132 ( V_138 . V_140 , F_133 ( & V_138 . V_139 ) ) ;
}
static enum V_115 F_91 ( struct V_9 * V_9 )
{
return V_9 -> V_103 . V_141 ;
}
static void F_134 ( struct V_9 * V_9 , const char * V_142 )
{
F_96 ( V_9 -> V_110 -> V_111 ) ;
F_135 ( L_13 ,
F_95 ( V_9 -> V_34 ) , V_142 ) ;
}
static void F_100 ( struct V_9 * V_9 , enum V_115 V_142 )
{
struct V_143 * V_144 = V_9 -> V_110 -> V_145 ;
bool V_146 = F_136 ( V_9 -> V_80 ) ;
enum V_115 V_147 = F_91 ( V_9 ) ;
if ( V_142 == V_105 && V_146 ) {
F_137 ( L_14 ,
F_95 ( V_9 -> V_34 ) ) ;
if ( V_147 != V_142 )
V_142 = V_147 ;
else
V_142 = V_117 ;
}
if ( V_147 == V_118 )
V_142 = V_147 ;
switch ( V_142 ) {
case V_118 :
if ( V_147 != V_142 )
F_134 ( V_9 , L_15 ) ;
F_138 ( V_9 -> V_80 ) ;
V_9 -> F_112 = F_115 ;
V_9 -> F_106 = F_115 ;
V_9 -> F_64 = F_61 ;
V_9 -> F_70 = F_67 ;
F_39 ( V_9 ) ;
break;
case V_117 :
if ( V_147 != V_142 )
F_134 ( V_9 , L_16 ) ;
F_138 ( V_9 -> V_80 ) ;
V_9 -> F_112 = F_113 ;
V_9 -> F_106 = F_114 ;
V_9 -> F_64 = F_61 ;
V_9 -> F_70 = F_68 ;
F_39 ( V_9 ) ;
break;
case V_113 :
if ( V_147 != V_142 )
F_134 ( V_9 , L_17 ) ;
V_9 -> F_112 = F_113 ;
V_9 -> F_106 = F_106 ;
V_9 -> F_64 = F_64 ;
V_9 -> F_70 = F_68 ;
break;
case V_105 :
if ( V_147 != V_142 )
F_134 ( V_9 , L_18 ) ;
F_139 ( V_9 -> V_80 ) ;
V_9 -> F_112 = F_112 ;
V_9 -> F_106 = F_106 ;
V_9 -> F_64 = F_64 ;
V_9 -> F_70 = F_70 ;
break;
}
V_9 -> V_103 . V_141 = V_142 ;
V_144 -> V_148 . V_141 = V_142 ;
}
static void F_140 ( struct V_9 * V_9 )
{
const char * V_149 = F_95 ( V_9 -> V_34 ) ;
F_72 ( L_19 , V_149 ) ;
if ( F_141 ( V_9 -> V_80 ) ) {
F_137 ( L_20 , V_149 ) ;
F_100 ( V_9 , V_118 ) ;
}
if ( F_142 ( V_9 -> V_80 ) ) {
F_137 ( L_21 , V_149 ) ;
F_100 ( V_9 , V_118 ) ;
}
}
static void F_66 ( struct V_9 * V_9 , const char * V_150 , int V_15 )
{
F_72 ( L_22 ,
F_95 ( V_9 -> V_34 ) , V_150 , V_15 ) ;
F_140 ( V_9 ) ;
F_100 ( V_9 , V_117 ) ;
}
static void F_143 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
unsigned long V_24 ;
struct V_9 * V_9 = V_23 -> V_9 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_37 ( & V_9 -> V_26 , V_12 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
static void F_144 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
struct V_38 * V_39 = F_35 ( V_12 , sizeof( struct V_38 ) ) ;
V_39 -> V_23 = V_23 ;
V_39 -> V_127 = NULL ;
V_39 -> V_55 = NULL ;
V_39 -> V_68 = NULL ;
}
static int F_145 ( struct V_151 * V_110 , struct V_12 * V_12 )
{
int V_15 ;
struct V_22 * V_23 = V_110 -> V_145 ;
T_1 V_8 = F_42 ( V_23 , V_12 ) ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_120 V_112 ;
struct V_13 V_152 , V_76 ;
struct V_13 * V_14 ;
struct V_4 V_5 ;
F_144 ( V_23 , V_12 ) ;
if ( V_23 -> V_133 ) {
F_36 ( V_12 , V_40 ) ;
return V_153 ;
}
if ( F_91 ( V_23 -> V_9 ) == V_118 ) {
F_40 ( V_12 ) ;
return V_153 ;
}
if ( V_12 -> V_51 & ( V_54 | V_52 | V_53 ) ) {
F_143 ( V_23 , V_12 ) ;
return V_153 ;
}
V_15 = F_107 ( V_2 , V_8 , 0 , & V_112 ) ;
switch ( V_15 ) {
case 0 :
if ( F_146 ( V_112 . V_123 ) ) {
F_143 ( V_23 , V_12 ) ;
return V_153 ;
}
F_3 ( V_23 -> V_2 , V_8 , & V_5 ) ;
if ( F_8 ( V_23 -> V_9 -> V_17 , & V_5 , V_12 , & V_152 , & V_14 ) )
return V_153 ;
F_1 ( V_23 -> V_2 , V_112 . V_8 , & V_5 ) ;
if ( F_8 ( V_23 -> V_9 -> V_17 , & V_5 , V_12 , & V_76 , & V_14 ) ) {
F_14 ( V_23 , & V_152 ) ;
return V_153 ;
}
F_48 ( V_23 -> V_9 , V_12 ) ;
F_14 ( V_23 , & V_76 ) ;
F_14 ( V_23 , & V_152 ) ;
F_44 ( V_23 , V_12 , V_112 . V_8 ) ;
return V_154 ;
case - V_125 :
if ( F_91 ( V_23 -> V_9 ) == V_117 ) {
F_104 ( V_23 -> V_9 , V_12 ) ;
return V_153 ;
}
case - V_155 :
F_143 ( V_23 , V_12 ) ;
return V_153 ;
default:
F_40 ( V_12 ) ;
return V_153 ;
}
}
static int F_147 ( struct V_156 * V_157 , int V_158 )
{
int V_15 ;
unsigned long V_24 ;
struct V_143 * V_144 = F_121 ( V_157 , struct V_143 , V_159 ) ;
F_15 ( & V_144 -> V_9 -> V_25 , V_24 ) ;
V_15 = ! F_118 ( & V_144 -> V_9 -> V_41 ) ;
F_16 ( & V_144 -> V_9 -> V_25 , V_24 ) ;
if ( ! V_15 ) {
struct V_160 * V_161 = F_148 ( V_144 -> V_162 -> V_49 ) ;
V_15 = F_149 ( & V_161 -> V_163 , V_158 ) ;
}
return V_15 ;
}
static void F_150 ( struct V_9 * V_9 )
{
F_33 ( & V_9 -> V_26 , & V_9 -> V_41 ) ;
F_32 ( & V_9 -> V_41 ) ;
}
static bool F_151 ( struct V_143 * V_144 )
{
struct V_160 * V_161 = F_148 ( V_144 -> V_162 -> V_49 ) ;
return V_161 && F_152 ( V_161 ) ;
}
static bool F_153 ( T_2 V_164 , T_5 V_165 )
{
return ! F_43 ( V_164 , V_165 ) ;
}
static void F_154 ( struct V_143 * V_144 )
{
struct V_9 * V_9 = V_144 -> V_9 ;
struct V_35 * V_166 = V_144 -> V_162 -> V_49 ;
struct V_167 * V_168 = & F_148 ( V_166 ) -> V_169 ;
T_2 V_164 = V_9 -> V_46 << V_86 ;
const char * V_170 = NULL ;
char V_171 [ V_172 ] ;
if ( ! V_144 -> V_148 . V_122 )
return;
if ( ! F_151 ( V_144 ) )
V_170 = L_23 ;
else if ( V_168 -> V_173 < V_9 -> V_46 )
V_170 = L_24 ;
else if ( V_168 -> V_174 > V_164 )
V_170 = L_25 ;
else if ( ! F_153 ( V_164 , V_168 -> V_174 ) )
V_170 = L_26 ;
if ( V_170 ) {
F_94 ( L_27 , F_155 ( V_166 , V_171 ) , V_170 ) ;
V_144 -> V_148 . V_122 = false ;
}
}
static int F_156 ( struct V_9 * V_9 , struct V_151 * V_110 )
{
struct V_143 * V_144 = V_110 -> V_145 ;
enum V_115 V_147 = F_91 ( V_9 ) ;
enum V_115 V_142 = V_144 -> V_148 . V_141 ;
V_144 -> V_148 . V_141 = V_147 ;
V_9 -> V_110 = V_110 ;
V_9 -> V_103 = V_144 -> V_148 ;
V_9 -> V_108 = V_144 -> V_108 ;
F_100 ( V_9 , V_142 ) ;
return 0 ;
}
static void F_157 ( struct V_9 * V_9 , struct V_151 * V_110 )
{
if ( V_9 -> V_110 == V_110 )
V_9 -> V_110 = NULL ;
}
static void F_158 ( struct V_175 * V_103 )
{
V_103 -> V_141 = V_105 ;
V_103 -> V_104 = true ;
V_103 -> V_176 = true ;
V_103 -> V_122 = true ;
V_103 -> V_116 = false ;
}
static void F_159 ( struct V_9 * V_9 )
{
F_26 ( V_9 ) ;
if ( F_160 ( V_9 -> V_80 ) < 0 )
F_94 ( L_28 , V_126 ) ;
F_161 ( V_9 -> V_17 ) ;
F_162 ( V_9 -> V_102 ) ;
if ( V_9 -> V_10 )
F_163 ( V_9 -> V_10 ) ;
if ( V_9 -> V_89 )
F_63 ( V_9 -> V_89 , V_9 -> V_72 ) ;
F_164 ( V_9 -> V_72 ) ;
F_165 ( V_9 -> V_96 ) ;
F_165 ( V_9 -> V_56 ) ;
F_166 ( V_9 ) ;
}
static struct V_9 * F_167 ( struct V_31 * V_34 ,
struct V_35 * V_177 ,
unsigned long V_164 ,
int V_178 , char * * error )
{
int V_15 ;
void * V_179 ;
struct V_9 * V_9 ;
struct V_180 * V_80 ;
bool V_181 = V_178 ? false : true ;
V_80 = F_168 ( V_177 , V_164 , V_181 ) ;
if ( F_169 ( V_80 ) ) {
* error = L_29 ;
return (struct V_9 * ) V_80 ;
}
V_9 = F_170 ( sizeof( * V_9 ) , V_182 ) ;
if ( ! V_9 ) {
* error = L_30 ;
V_179 = F_171 ( - V_91 ) ;
goto V_183;
}
V_9 -> V_80 = V_80 ;
V_9 -> V_46 = V_164 ;
if ( V_164 & ( V_164 - 1 ) )
V_9 -> V_42 = - 1 ;
else
V_9 -> V_42 = F_172 ( V_164 ) ;
V_9 -> V_108 = 0 ;
F_158 ( & V_9 -> V_103 ) ;
V_9 -> V_17 = F_173 ( V_184 ) ;
if ( ! V_9 -> V_17 ) {
* error = L_31 ;
V_179 = F_171 ( - V_91 ) ;
goto V_185;
}
V_9 -> V_102 = F_174 ( & V_186 ) ;
if ( F_169 ( V_9 -> V_102 ) ) {
V_15 = F_175 ( V_9 -> V_102 ) ;
* error = L_32 ;
V_179 = F_171 ( V_15 ) ;
goto V_187;
}
V_9 -> V_10 = F_176 ( L_33 V_188 , V_189 ) ;
if ( ! V_9 -> V_10 ) {
* error = L_34 ;
V_179 = F_171 ( - V_91 ) ;
goto V_190;
}
F_130 ( & V_9 -> V_11 , F_120 ) ;
F_177 ( & V_9 -> V_136 , F_122 ) ;
F_178 ( & V_9 -> V_25 ) ;
F_32 ( & V_9 -> V_26 ) ;
F_32 ( & V_9 -> V_57 ) ;
F_21 ( & V_9 -> V_62 ) ;
F_21 ( & V_9 -> V_124 ) ;
V_9 -> V_109 = false ;
F_32 ( & V_9 -> V_41 ) ;
V_9 -> V_96 = F_179 () ;
if ( ! V_9 -> V_96 ) {
* error = L_35 ;
V_179 = F_171 ( - V_91 ) ;
goto V_191;
}
V_9 -> V_56 = F_179 () ;
if ( ! V_9 -> V_56 ) {
* error = L_36 ;
V_179 = F_171 ( - V_91 ) ;
goto V_192;
}
V_9 -> V_89 = NULL ;
V_9 -> V_72 = F_180 ( V_193 ,
V_194 ) ;
if ( ! V_9 -> V_72 ) {
* error = L_37 ;
V_179 = F_171 ( - V_91 ) ;
goto V_195;
}
V_9 -> V_196 = 1 ;
V_9 -> V_131 = V_130 ;
V_9 -> V_34 = V_34 ;
V_9 -> V_36 = V_177 ;
F_22 ( V_9 ) ;
return V_9 ;
V_195:
F_165 ( V_9 -> V_56 ) ;
V_192:
F_165 ( V_9 -> V_96 ) ;
V_191:
F_163 ( V_9 -> V_10 ) ;
V_190:
F_162 ( V_9 -> V_102 ) ;
V_187:
F_161 ( V_9 -> V_17 ) ;
V_185:
F_166 ( V_9 ) ;
V_183:
if ( F_160 ( V_80 ) )
F_94 ( L_28 , V_126 ) ;
return V_179 ;
}
static void F_181 ( struct V_9 * V_9 )
{
F_23 ( ! F_24 ( & V_27 . V_28 ) ) ;
V_9 -> V_196 ++ ;
}
static void F_182 ( struct V_9 * V_9 )
{
F_23 ( ! F_24 ( & V_27 . V_28 ) ) ;
F_23 ( ! V_9 -> V_196 ) ;
if ( ! -- V_9 -> V_196 )
F_159 ( V_9 ) ;
}
static struct V_9 * F_183 ( struct V_31 * V_34 ,
struct V_35 * V_177 ,
unsigned long V_164 , int V_178 ,
char * * error , int * V_197 )
{
struct V_9 * V_9 = F_30 ( V_177 ) ;
if ( V_9 ) {
if ( V_9 -> V_34 != V_34 ) {
* error = L_38 ;
return F_171 ( - V_198 ) ;
}
F_181 ( V_9 ) ;
} else {
V_9 = F_28 ( V_34 ) ;
if ( V_9 ) {
if ( V_9 -> V_36 != V_177 ) {
* error = L_39 ;
return F_171 ( - V_106 ) ;
}
F_181 ( V_9 ) ;
} else {
V_9 = F_167 ( V_34 , V_177 , V_164 , V_178 , error ) ;
* V_197 = 1 ;
}
}
return V_9 ;
}
static void F_184 ( struct V_151 * V_110 )
{
struct V_143 * V_144 = V_110 -> V_145 ;
F_185 ( & V_27 . V_28 ) ;
F_157 ( V_144 -> V_9 , V_110 ) ;
F_182 ( V_144 -> V_9 ) ;
F_186 ( V_110 , V_144 -> V_177 ) ;
F_186 ( V_110 , V_144 -> V_162 ) ;
F_166 ( V_144 ) ;
F_187 ( & V_27 . V_28 ) ;
}
static int F_188 ( struct V_199 * V_200 , struct V_175 * V_103 ,
struct V_151 * V_110 )
{
int V_15 ;
unsigned V_201 ;
const char * V_202 ;
static struct V_203 V_204 [] = {
{ 0 , 4 , L_40 } ,
} ;
if ( ! V_200 -> V_201 )
return 0 ;
V_15 = F_189 ( V_204 , V_200 , & V_201 , & V_110 -> error ) ;
if ( V_15 )
return - V_106 ;
while ( V_201 && ! V_15 ) {
V_202 = F_190 ( V_200 ) ;
V_201 -- ;
if ( ! strcasecmp ( V_202 , L_41 ) )
V_103 -> V_104 = false ;
else if ( ! strcasecmp ( V_202 , L_42 ) )
V_103 -> V_176 = false ;
else if ( ! strcasecmp ( V_202 , L_43 ) )
V_103 -> V_122 = false ;
else if ( ! strcasecmp ( V_202 , L_44 ) )
V_103 -> V_141 = V_117 ;
else if ( ! strcasecmp ( V_202 , L_45 ) )
V_103 -> V_116 = true ;
else {
V_110 -> error = L_46 ;
V_15 = - V_106 ;
break;
}
}
return V_15 ;
}
static void F_191 ( void * V_65 )
{
struct V_9 * V_9 = V_65 ;
F_94 ( L_47 ,
F_95 ( V_9 -> V_34 ) ) ;
F_96 ( V_9 -> V_110 -> V_111 ) ;
}
static T_2 F_192 ( struct V_35 * V_49 )
{
return F_193 ( V_49 -> V_205 ) >> V_86 ;
}
static void F_194 ( struct V_35 * V_49 )
{
T_2 V_206 = F_192 ( V_49 ) ;
char V_207 [ V_172 ] ;
if ( V_206 > V_208 )
F_94 ( L_48 ,
F_155 ( V_49 , V_207 ) , V_209 ) ;
}
static T_2 F_195 ( struct V_35 * V_49 )
{
T_2 V_206 = F_192 ( V_49 ) ;
if ( V_206 > V_209 )
V_206 = V_209 ;
return V_206 ;
}
static T_1 F_196 ( struct V_35 * V_49 )
{
T_2 V_206 = F_195 ( V_49 ) ;
F_43 ( V_206 , V_210 ) ;
return V_206 ;
}
static T_1 F_197 ( struct V_143 * V_144 )
{
T_1 V_211 = F_196 ( V_144 -> V_177 -> V_49 ) / 4 ;
return F_198 ( ( T_1 ) 1024ULL , V_211 ) ;
}
static int F_199 ( struct V_151 * V_110 , unsigned V_201 , char * * V_212 )
{
int V_15 , V_213 = 0 ;
struct V_143 * V_144 ;
struct V_9 * V_9 ;
struct V_175 V_103 ;
struct V_199 V_200 ;
struct V_92 * V_162 ;
unsigned long V_164 ;
T_1 V_108 ;
struct V_92 * V_177 ;
T_6 V_214 ;
F_185 ( & V_27 . V_28 ) ;
if ( V_201 < 4 ) {
V_110 -> error = L_49 ;
V_15 = - V_106 ;
goto V_215;
}
V_200 . V_201 = V_201 ;
V_200 . V_212 = V_212 ;
F_158 ( & V_103 ) ;
F_200 ( & V_200 , 4 ) ;
V_15 = F_188 ( & V_200 , & V_103 , V_110 ) ;
if ( V_15 )
goto V_215;
V_214 = V_216 | ( ( V_103 . V_141 == V_117 ) ? 0 : V_217 ) ;
V_15 = F_201 ( V_110 , V_212 [ 0 ] , V_214 , & V_177 ) ;
if ( V_15 ) {
V_110 -> error = L_50 ;
goto V_215;
}
F_194 ( V_177 -> V_49 ) ;
V_15 = F_201 ( V_110 , V_212 [ 1 ] , V_216 | V_217 , & V_162 ) ;
if ( V_15 ) {
V_110 -> error = L_51 ;
goto V_218;
}
if ( F_202 ( V_212 [ 2 ] , 10 , & V_164 ) || ! V_164 ||
V_164 < V_219 ||
V_164 > V_220 ||
V_164 & ( V_219 - 1 ) ) {
V_110 -> error = L_52 ;
V_15 = - V_106 ;
goto V_73;
}
if ( F_203 ( V_212 [ 3 ] , 10 , ( unsigned long long * ) & V_108 ) ) {
V_110 -> error = L_53 ;
V_15 = - V_106 ;
goto V_73;
}
V_144 = F_204 ( sizeof( * V_144 ) , V_182 ) ;
if ( ! V_144 ) {
V_15 = - V_91 ;
goto V_73;
}
V_9 = F_183 ( F_205 ( V_110 -> V_111 ) , V_177 -> V_49 ,
V_164 , V_103 . V_141 == V_117 , & V_110 -> error , & V_213 ) ;
if ( F_169 ( V_9 ) ) {
V_15 = F_175 ( V_9 ) ;
goto V_221;
}
if ( ! V_213 && V_103 . V_176 != V_9 -> V_103 . V_176 ) {
V_110 -> error = L_54 ;
V_15 = - V_106 ;
goto V_222;
}
V_144 -> V_9 = V_9 ;
V_144 -> V_110 = V_110 ;
V_144 -> V_177 = V_177 ;
V_144 -> V_162 = V_162 ;
V_144 -> V_108 = V_108 ;
V_144 -> V_148 = V_144 -> V_223 = V_103 ;
V_110 -> V_224 = 1 ;
V_110 -> V_225 = true ;
if ( V_103 . V_176 && V_103 . V_122 ) {
V_110 -> V_226 = 1 ;
V_110 -> V_227 = true ;
}
V_110 -> V_145 = V_144 ;
V_15 = F_206 ( V_144 -> V_9 -> V_80 ,
F_197 ( V_144 ) ,
F_191 ,
V_9 ) ;
if ( V_15 )
goto V_221;
V_144 -> V_159 . V_228 = F_147 ;
F_207 ( V_110 -> V_111 , & V_144 -> V_159 ) ;
F_187 ( & V_27 . V_28 ) ;
return 0 ;
V_222:
F_182 ( V_9 ) ;
V_221:
F_166 ( V_144 ) ;
V_73:
F_186 ( V_110 , V_162 ) ;
V_218:
F_186 ( V_110 , V_177 ) ;
V_215:
F_187 ( & V_27 . V_28 ) ;
return V_15 ;
}
static int F_208 ( struct V_151 * V_110 , struct V_12 * V_12 )
{
int V_15 ;
struct V_143 * V_144 = V_110 -> V_145 ;
struct V_9 * V_9 = V_144 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_12 -> V_47 = V_144 -> V_162 -> V_49 ;
V_15 = V_154 ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
return V_15 ;
}
static int F_209 ( struct V_151 * V_110 , bool * V_229 )
{
int V_15 ;
struct V_143 * V_144 = V_110 -> V_145 ;
struct V_9 * V_9 = V_144 -> V_9 ;
T_2 V_230 = V_110 -> V_231 ;
T_1 V_232 ;
* V_229 = false ;
( void ) F_43 ( V_230 , V_9 -> V_46 ) ;
V_15 = F_210 ( V_9 -> V_80 , & V_232 ) ;
if ( V_15 ) {
F_137 ( L_55 ,
F_95 ( V_9 -> V_34 ) ) ;
return V_15 ;
}
if ( V_230 < V_232 ) {
F_137 ( L_56 ,
F_95 ( V_9 -> V_34 ) ,
( unsigned long long ) V_230 , V_232 ) ;
return - V_106 ;
} else if ( V_230 > V_232 ) {
if ( F_136 ( V_9 -> V_80 ) ) {
F_137 ( L_57 ,
F_95 ( V_9 -> V_34 ) ) ;
return 0 ;
}
if ( V_232 )
F_135 ( L_58 ,
F_95 ( V_9 -> V_34 ) ,
V_232 , ( unsigned long long ) V_230 ) ;
V_15 = F_211 ( V_9 -> V_80 , V_230 ) ;
if ( V_15 ) {
F_66 ( V_9 , L_59 , V_15 ) ;
return V_15 ;
}
* V_229 = true ;
}
return 0 ;
}
static int F_212 ( struct V_151 * V_110 , bool * V_229 )
{
int V_15 ;
struct V_143 * V_144 = V_110 -> V_145 ;
struct V_9 * V_9 = V_144 -> V_9 ;
T_1 V_206 , V_233 ;
* V_229 = false ;
V_206 = F_196 ( V_9 -> V_36 ) ;
V_15 = F_213 ( V_9 -> V_80 , & V_233 ) ;
if ( V_15 ) {
F_137 ( L_60 ,
F_95 ( V_9 -> V_34 ) ) ;
return V_15 ;
}
if ( V_206 < V_233 ) {
F_137 ( L_61 ,
F_95 ( V_9 -> V_34 ) ,
V_206 , V_233 ) ;
return - V_106 ;
} else if ( V_206 > V_233 ) {
if ( F_136 ( V_9 -> V_80 ) ) {
F_137 ( L_62 ,
F_95 ( V_9 -> V_34 ) ) ;
return 0 ;
}
F_194 ( V_9 -> V_36 ) ;
F_135 ( L_63 ,
F_95 ( V_9 -> V_34 ) ,
V_233 , V_206 ) ;
V_15 = F_214 ( V_9 -> V_80 , V_206 ) ;
if ( V_15 ) {
F_66 ( V_9 , L_64 , V_15 ) ;
return V_15 ;
}
* V_229 = true ;
}
return 0 ;
}
static int F_215 ( struct V_151 * V_110 )
{
int V_15 ;
bool V_234 , V_235 ;
struct V_143 * V_144 = V_110 -> V_145 ;
struct V_9 * V_9 = V_144 -> V_9 ;
V_15 = F_156 ( V_9 , V_110 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_209 ( V_110 , & V_234 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_212 ( V_110 , & V_235 ) ;
if ( V_15 )
return V_15 ;
if ( V_234 || V_235 )
( void ) F_90 ( V_9 ) ;
return 0 ;
}
static void F_216 ( struct V_151 * V_110 )
{
struct V_143 * V_144 = V_110 -> V_145 ;
struct V_9 * V_9 = V_144 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_9 -> V_109 = false ;
F_150 ( V_9 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_122 ( & V_9 -> V_136 . V_236 ) ;
}
static void F_217 ( struct V_151 * V_110 )
{
struct V_143 * V_144 = V_110 -> V_145 ;
struct V_9 * V_9 = V_144 -> V_9 ;
F_218 ( & V_9 -> V_136 ) ;
F_219 ( V_9 -> V_10 ) ;
( void ) F_90 ( V_9 ) ;
}
static int F_220 ( unsigned V_201 , unsigned V_237 )
{
if ( V_201 != V_237 ) {
F_94 ( L_65 ,
V_201 , V_237 ) ;
return - V_106 ;
}
return 0 ;
}
static int F_221 ( char * V_238 , T_7 * V_239 , int V_240 )
{
if ( ! F_203 ( V_238 , 10 , ( unsigned long long * ) V_239 ) &&
* V_239 <= V_241 )
return 0 ;
if ( V_240 )
F_94 ( L_66 , V_238 ) ;
return - V_106 ;
}
static int F_222 ( unsigned V_201 , char * * V_212 , struct V_9 * V_9 )
{
T_7 V_239 ;
int V_15 ;
V_15 = F_220 ( V_201 , 2 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_221 ( V_212 [ 1 ] , & V_239 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_223 ( V_9 -> V_80 , V_239 ) ;
if ( V_15 ) {
F_94 ( L_67 ,
V_212 [ 1 ] ) ;
return V_15 ;
}
return 0 ;
}
static int F_224 ( unsigned V_201 , char * * V_212 , struct V_9 * V_9 )
{
T_7 V_239 ;
T_7 V_242 ;
int V_15 ;
V_15 = F_220 ( V_201 , 3 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_221 ( V_212 [ 1 ] , & V_239 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_221 ( V_212 [ 2 ] , & V_242 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_225 ( V_9 -> V_80 , V_239 , V_242 ) ;
if ( V_15 ) {
F_94 ( L_68 ,
V_212 [ 1 ] , V_212 [ 2 ] ) ;
return V_15 ;
}
return 0 ;
}
static int F_226 ( unsigned V_201 , char * * V_212 , struct V_9 * V_9 )
{
T_7 V_239 ;
int V_15 ;
V_15 = F_220 ( V_201 , 2 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_221 ( V_212 [ 1 ] , & V_239 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_227 ( V_9 -> V_80 , V_239 ) ;
if ( V_15 )
F_94 ( L_69 , V_212 [ 1 ] ) ;
return V_15 ;
}
static int F_228 ( unsigned V_201 , char * * V_212 , struct V_9 * V_9 )
{
T_7 V_243 , V_244 ;
int V_15 ;
V_15 = F_220 ( V_201 , 3 ) ;
if ( V_15 )
return V_15 ;
if ( F_203 ( V_212 [ 1 ] , 10 , ( unsigned long long * ) & V_243 ) ) {
F_94 ( L_70 , V_212 [ 1 ] ) ;
return - V_106 ;
}
if ( F_203 ( V_212 [ 2 ] , 10 , ( unsigned long long * ) & V_244 ) ) {
F_94 ( L_71 , V_212 [ 2 ] ) ;
return - V_106 ;
}
V_15 = F_229 ( V_9 -> V_80 , V_243 , V_244 ) ;
if ( V_15 ) {
F_94 ( L_72 ,
V_212 [ 1 ] , V_212 [ 2 ] ) ;
return V_15 ;
}
return 0 ;
}
static int F_230 ( unsigned V_201 , char * * V_212 , struct V_9 * V_9 )
{
int V_15 ;
V_15 = F_220 ( V_201 , 1 ) ;
if ( V_15 )
return V_15 ;
( void ) F_90 ( V_9 ) ;
V_15 = F_231 ( V_9 -> V_80 ) ;
if ( V_15 )
F_94 ( L_73 ) ;
return V_15 ;
}
static int F_232 ( unsigned V_201 , char * * V_212 , struct V_9 * V_9 )
{
int V_15 ;
V_15 = F_220 ( V_201 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_233 ( V_9 -> V_80 ) ;
if ( V_15 )
F_94 ( L_74 ) ;
return V_15 ;
}
static int F_234 ( struct V_151 * V_110 , unsigned V_201 , char * * V_212 )
{
int V_15 = - V_106 ;
struct V_143 * V_144 = V_110 -> V_145 ;
struct V_9 * V_9 = V_144 -> V_9 ;
if ( ! strcasecmp ( V_212 [ 0 ] , L_75 ) )
V_15 = F_222 ( V_201 , V_212 , V_9 ) ;
else if ( ! strcasecmp ( V_212 [ 0 ] , L_76 ) )
V_15 = F_224 ( V_201 , V_212 , V_9 ) ;
else if ( ! strcasecmp ( V_212 [ 0 ] , L_77 ) )
V_15 = F_226 ( V_201 , V_212 , V_9 ) ;
else if ( ! strcasecmp ( V_212 [ 0 ] , L_78 ) )
V_15 = F_228 ( V_201 , V_212 , V_9 ) ;
else if ( ! strcasecmp ( V_212 [ 0 ] , L_79 ) )
V_15 = F_230 ( V_201 , V_212 , V_9 ) ;
else if ( ! strcasecmp ( V_212 [ 0 ] , L_80 ) )
V_15 = F_232 ( V_201 , V_212 , V_9 ) ;
else
F_94 ( L_81 , V_212 [ 0 ] ) ;
if ( ! V_15 )
( void ) F_90 ( V_9 ) ;
return V_15 ;
}
static void F_235 ( struct V_175 * V_103 , char * V_112 ,
unsigned V_245 , unsigned V_246 )
{
unsigned V_101 = ! V_103 -> V_104 + ! V_103 -> V_176 +
! V_103 -> V_122 + ( V_103 -> V_141 == V_117 ) +
V_103 -> V_116 ;
F_236 ( L_82 , V_101 ) ;
if ( ! V_103 -> V_104 )
F_236 ( L_83 ) ;
if ( ! V_103 -> V_176 )
F_236 ( L_84 ) ;
if ( ! V_103 -> V_122 )
F_236 ( L_85 ) ;
if ( V_103 -> V_141 == V_117 )
F_236 ( L_86 ) ;
if ( V_103 -> V_116 )
F_236 ( L_87 ) ;
}
static void F_237 ( struct V_151 * V_110 , T_8 type ,
unsigned V_247 , char * V_112 , unsigned V_246 )
{
int V_15 ;
unsigned V_245 = 0 ;
T_9 V_248 ;
T_1 V_249 ;
T_1 V_250 ;
T_1 V_251 ;
T_1 V_252 ;
T_1 V_253 ;
char V_171 [ V_172 ] ;
char V_254 [ V_172 ] ;
struct V_143 * V_144 = V_110 -> V_145 ;
struct V_9 * V_9 = V_144 -> V_9 ;
switch ( type ) {
case V_255 :
if ( F_91 ( V_9 ) == V_118 ) {
F_236 ( L_88 ) ;
break;
}
if ( ! ( V_247 & V_256 ) && ! F_238 ( V_110 ) )
( void ) F_90 ( V_9 ) ;
V_15 = F_239 ( V_9 -> V_80 , & V_248 ) ;
if ( V_15 ) {
F_137 ( L_89 ,
F_95 ( V_9 -> V_34 ) , V_15 ) ;
goto V_66;
}
V_15 = F_240 ( V_9 -> V_80 , & V_250 ) ;
if ( V_15 ) {
F_137 ( L_90 ,
F_95 ( V_9 -> V_34 ) , V_15 ) ;
goto V_66;
}
V_15 = F_213 ( V_9 -> V_80 , & V_252 ) ;
if ( V_15 ) {
F_137 ( L_91 ,
F_95 ( V_9 -> V_34 ) , V_15 ) ;
goto V_66;
}
V_15 = F_99 ( V_9 -> V_80 , & V_249 ) ;
if ( V_15 ) {
F_137 ( L_92 ,
F_95 ( V_9 -> V_34 ) , V_15 ) ;
goto V_66;
}
V_15 = F_210 ( V_9 -> V_80 , & V_251 ) ;
if ( V_15 ) {
F_137 ( L_93 ,
F_95 ( V_9 -> V_34 ) , V_15 ) ;
goto V_66;
}
V_15 = F_241 ( V_9 -> V_80 , & V_253 ) ;
if ( V_15 ) {
F_137 ( L_94 ,
F_95 ( V_9 -> V_34 ) , V_15 ) ;
goto V_66;
}
F_236 ( L_95 ,
( unsigned long long ) V_248 ,
( unsigned long long ) ( V_252 - V_250 ) ,
( unsigned long long ) V_252 ,
( unsigned long long ) ( V_251 - V_249 ) ,
( unsigned long long ) V_251 ) ;
if ( V_253 )
F_236 ( L_96 , V_253 ) ;
else
F_236 ( L_97 ) ;
if ( V_9 -> V_103 . V_141 == V_113 )
F_236 ( L_98 ) ;
else if ( V_9 -> V_103 . V_141 == V_117 )
F_236 ( L_99 ) ;
else
F_236 ( L_100 ) ;
if ( ! V_9 -> V_103 . V_176 )
F_236 ( L_84 ) ;
else if ( V_9 -> V_103 . V_122 )
F_236 ( L_101 ) ;
else
F_236 ( L_85 ) ;
if ( V_9 -> V_103 . V_116 )
F_236 ( L_87 ) ;
else
F_236 ( L_102 ) ;
break;
case V_257 :
F_236 ( L_103 ,
F_242 ( V_171 , V_144 -> V_177 -> V_49 -> V_258 ) ,
F_242 ( V_254 , V_144 -> V_162 -> V_49 -> V_258 ) ,
( unsigned long ) V_9 -> V_46 ,
( unsigned long long ) V_144 -> V_108 ) ;
F_235 ( & V_144 -> V_223 , V_112 , V_245 , V_246 ) ;
break;
}
return;
V_66:
F_236 ( L_104 ) ;
}
static int F_243 ( struct V_151 * V_110 ,
T_10 V_83 , void * V_259 )
{
struct V_143 * V_144 = V_110 -> V_145 ;
return V_83 ( V_110 , V_144 -> V_162 , 0 , V_110 -> V_231 , V_259 ) ;
}
static int F_244 ( struct V_151 * V_110 , struct V_260 * V_261 ,
struct V_262 * V_263 , int V_264 )
{
struct V_143 * V_144 = V_110 -> V_145 ;
struct V_160 * V_161 = F_148 ( V_144 -> V_162 -> V_49 ) ;
if ( ! V_161 -> V_265 )
return V_264 ;
V_261 -> V_47 = V_144 -> V_162 -> V_49 ;
return F_198 ( V_264 , V_161 -> V_265 ( V_161 , V_261 , V_263 ) ) ;
}
static void F_245 ( struct V_143 * V_144 , struct V_167 * V_169 )
{
struct V_9 * V_9 = V_144 -> V_9 ;
struct V_167 * V_168 ;
V_169 -> V_173 = V_9 -> V_46 ;
if ( V_144 -> V_148 . V_122 ) {
V_168 = & F_148 ( V_144 -> V_162 -> V_49 ) -> V_169 ;
V_169 -> V_174 = V_168 -> V_174 ;
} else
V_169 -> V_174 = V_9 -> V_46 << V_86 ;
}
static void F_246 ( struct V_151 * V_110 , struct V_167 * V_169 )
{
struct V_143 * V_144 = V_110 -> V_145 ;
struct V_9 * V_9 = V_144 -> V_9 ;
T_9 V_266 = V_169 -> V_267 >> V_86 ;
if ( V_266 < V_9 -> V_46 ||
F_247 ( V_266 , V_9 -> V_46 ) ) {
F_248 ( V_169 , 0 ) ;
F_249 ( V_169 , V_9 -> V_46 << V_86 ) ;
}
if ( ! V_144 -> V_148 . V_176 ) {
V_169 -> V_174 = 0 ;
return;
}
F_154 ( V_144 ) ;
F_245 ( V_144 , V_169 ) ;
}
static void F_250 ( struct V_151 * V_110 )
{
struct V_22 * V_23 = V_110 -> V_145 ;
F_185 ( & V_27 . V_28 ) ;
F_182 ( V_23 -> V_9 ) ;
F_251 ( V_23 -> V_2 ) ;
F_186 ( V_110 , V_23 -> V_48 ) ;
if ( V_23 -> V_50 )
F_186 ( V_110 , V_23 -> V_50 ) ;
F_166 ( V_23 ) ;
F_187 ( & V_27 . V_28 ) ;
}
static int F_252 ( struct V_151 * V_110 , unsigned V_201 , char * * V_212 )
{
int V_15 ;
struct V_22 * V_23 ;
struct V_92 * V_48 , * V_50 ;
struct V_31 * V_34 ;
F_185 ( & V_27 . V_28 ) ;
if ( V_201 != 2 && V_201 != 3 ) {
V_110 -> error = L_49 ;
V_15 = - V_106 ;
goto V_215;
}
V_23 = V_110 -> V_145 = F_204 ( sizeof( * V_23 ) , V_182 ) ;
if ( ! V_23 ) {
V_110 -> error = L_105 ;
V_15 = - V_91 ;
goto V_215;
}
if ( V_201 == 3 ) {
V_15 = F_201 ( V_110 , V_212 [ 2 ] , V_216 , & V_50 ) ;
if ( V_15 ) {
V_110 -> error = L_106 ;
goto V_268;
}
V_23 -> V_50 = V_50 ;
}
V_15 = F_201 ( V_110 , V_212 [ 0 ] , F_253 ( V_110 -> V_111 ) , & V_48 ) ;
if ( V_15 ) {
V_110 -> error = L_107 ;
goto V_269;
}
V_23 -> V_48 = V_48 ;
if ( F_221 ( V_212 [ 1 ] , ( unsigned long long * ) & V_23 -> V_239 , 0 ) ) {
V_110 -> error = L_108 ;
V_15 = - V_106 ;
goto V_270;
}
V_34 = F_254 ( V_23 -> V_48 -> V_49 -> V_258 ) ;
if ( ! V_34 ) {
V_110 -> error = L_109 ;
V_15 = - V_106 ;
goto V_270;
}
V_23 -> V_9 = F_28 ( V_34 ) ;
if ( ! V_23 -> V_9 ) {
V_110 -> error = L_110 ;
V_15 = - V_106 ;
goto V_271;
}
F_181 ( V_23 -> V_9 ) ;
if ( F_91 ( V_23 -> V_9 ) == V_118 ) {
V_110 -> error = L_111 ;
V_15 = - V_106 ;
goto V_272;
}
V_15 = F_255 ( V_23 -> V_9 -> V_80 , V_23 -> V_239 , & V_23 -> V_2 ) ;
if ( V_15 ) {
V_110 -> error = L_112 ;
goto V_272;
}
V_15 = F_256 ( V_110 , V_23 -> V_9 -> V_46 ) ;
if ( V_15 )
goto V_273;
V_110 -> V_224 = 1 ;
V_110 -> V_274 = true ;
V_110 -> V_275 = sizeof( struct V_38 ) ;
V_110 -> V_225 = true ;
if ( V_23 -> V_9 -> V_103 . V_176 ) {
V_110 -> V_227 = true ;
V_110 -> V_226 = 1 ;
V_110 -> V_276 = true ;
}
F_257 ( V_34 ) ;
F_187 ( & V_27 . V_28 ) ;
return 0 ;
V_273:
F_251 ( V_23 -> V_2 ) ;
V_272:
F_182 ( V_23 -> V_9 ) ;
V_271:
F_257 ( V_34 ) ;
V_270:
F_186 ( V_110 , V_23 -> V_48 ) ;
V_269:
if ( V_23 -> V_50 )
F_186 ( V_110 , V_23 -> V_50 ) ;
V_268:
F_166 ( V_23 ) ;
V_215:
F_187 ( & V_27 . V_28 ) ;
return V_15 ;
}
static int F_258 ( struct V_151 * V_110 , struct V_12 * V_12 )
{
V_12 -> V_44 . V_45 = F_259 ( V_110 , V_12 -> V_44 . V_45 ) ;
return F_145 ( V_110 , V_12 ) ;
}
static int F_260 ( struct V_151 * V_110 , struct V_12 * V_12 , int V_66 )
{
unsigned long V_24 ;
struct V_38 * V_39 = F_35 ( V_12 , sizeof( struct V_38 ) ) ;
struct V_81 V_236 ;
struct V_58 * V_59 , * V_33 ;
struct V_9 * V_9 = V_39 -> V_23 -> V_9 ;
if ( V_39 -> V_127 ) {
F_21 ( & V_236 ) ;
F_261 ( V_39 -> V_127 , & V_236 ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_75 (m, tmp, &work, list) {
F_27 ( & V_59 -> V_30 ) ;
V_59 -> V_60 = true ;
F_55 ( V_59 ) ;
}
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
if ( V_39 -> V_55 ) {
F_21 ( & V_236 ) ;
F_261 ( V_39 -> V_55 , & V_236 ) ;
if ( ! F_262 ( & V_236 ) ) {
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_75 (m, tmp, &work, list)
F_56 ( & V_59 -> V_30 , & V_9 -> V_124 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
}
return 0 ;
}
static void F_263 ( struct V_151 * V_110 )
{
struct V_22 * V_23 = V_110 -> V_145 ;
if ( F_264 ( V_110 ) )
V_137 ( V_23 , F_128 ) ;
}
static void F_265 ( struct V_151 * V_110 )
{
struct V_22 * V_23 = V_110 -> V_145 ;
V_137 ( V_23 , F_129 ) ;
}
static void F_266 ( struct V_151 * V_110 , T_8 type ,
unsigned V_247 , char * V_112 , unsigned V_246 )
{
int V_15 ;
T_11 V_245 = 0 ;
T_1 V_277 , V_278 ;
char V_171 [ V_172 ] ;
struct V_22 * V_23 = V_110 -> V_145 ;
if ( F_91 ( V_23 -> V_9 ) == V_118 ) {
F_236 ( L_88 ) ;
return;
}
if ( ! V_23 -> V_2 )
F_236 ( L_113 ) ;
else {
switch ( type ) {
case V_255 :
V_15 = F_267 ( V_23 -> V_2 , & V_277 ) ;
if ( V_15 ) {
F_137 ( L_114 , V_15 ) ;
goto V_66;
}
V_15 = F_268 ( V_23 -> V_2 , & V_278 ) ;
if ( V_15 < 0 ) {
F_137 ( L_115 , V_15 ) ;
goto V_66;
}
F_236 ( L_96 , V_277 * V_23 -> V_9 -> V_46 ) ;
if ( V_15 )
F_236 ( L_116 , ( ( V_278 + 1 ) *
V_23 -> V_9 -> V_46 ) - 1 ) ;
else
F_236 ( L_113 ) ;
break;
case V_257 :
F_236 ( L_117 ,
F_242 ( V_171 , V_23 -> V_48 -> V_49 -> V_258 ) ,
( unsigned long ) V_23 -> V_239 ) ;
if ( V_23 -> V_50 )
F_236 ( L_118 , F_242 ( V_171 , V_23 -> V_50 -> V_49 -> V_258 ) ) ;
break;
}
}
return;
V_66:
F_236 ( L_104 ) ;
}
static int F_269 ( struct V_151 * V_110 ,
T_10 V_83 , void * V_259 )
{
T_2 V_279 ;
struct V_22 * V_23 = V_110 -> V_145 ;
struct V_9 * V_9 = V_23 -> V_9 ;
if ( ! V_9 -> V_110 )
return 0 ;
V_279 = V_9 -> V_110 -> V_231 ;
( void ) F_43 ( V_279 , V_9 -> V_46 ) ;
if ( V_279 )
return V_83 ( V_110 , V_23 -> V_48 , 0 , V_9 -> V_46 * V_279 , V_259 ) ;
return 0 ;
}
static int T_12 F_270 ( void )
{
int V_15 ;
F_19 () ;
V_15 = F_271 ( & V_280 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_271 ( & V_281 ) ;
if ( V_15 )
goto V_282;
V_15 = - V_91 ;
V_194 = F_272 ( V_58 , 0 ) ;
if ( ! V_194 )
goto V_283;
return 0 ;
V_283:
F_273 ( & V_281 ) ;
V_282:
F_273 ( & V_280 ) ;
return V_15 ;
}
static void F_274 ( void )
{
F_273 ( & V_280 ) ;
F_273 ( & V_281 ) ;
F_275 ( V_194 ) ;
}
