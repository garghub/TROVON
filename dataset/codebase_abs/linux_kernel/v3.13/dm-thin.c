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
F_32 ( & V_21 ) ;
F_33 ( & V_21 , V_37 ) ;
F_32 ( V_37 ) ;
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
unsigned long V_24 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_31 ( V_23 , & V_9 -> V_26 ) ;
F_31 ( V_23 , & V_9 -> V_41 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
static bool F_39 ( struct V_9 * V_9 )
{
return V_9 -> V_42 >= 0 ;
}
static T_1 F_40 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
T_2 V_43 = V_12 -> V_44 ;
if ( F_39 ( V_9 ) )
V_43 >>= V_9 -> V_42 ;
else
( void ) F_41 ( V_43 , V_9 -> V_45 ) ;
return V_43 ;
}
static void F_42 ( struct V_22 * V_23 , struct V_12 * V_12 , T_1 V_8 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
T_2 V_44 = V_12 -> V_44 ;
V_12 -> V_46 = V_23 -> V_47 -> V_48 ;
if ( F_39 ( V_9 ) )
V_12 -> V_44 = ( V_8 << V_9 -> V_42 ) |
( V_44 & ( V_9 -> V_45 - 1 ) ) ;
else
V_12 -> V_44 = ( V_8 * V_9 -> V_45 ) +
F_41 ( V_44 , V_9 -> V_45 ) ;
}
static void F_43 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
V_12 -> V_46 = V_23 -> V_49 -> V_48 ;
}
static int F_44 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
return ( V_12 -> V_50 & ( V_51 | V_52 ) ) &&
F_45 ( V_23 -> V_2 ) ;
}
static void F_46 ( struct V_9 * V_9 , struct V_12 * V_12 )
{
struct V_38 * V_39 ;
if ( V_12 -> V_50 & V_53 )
return;
V_39 = F_35 ( V_12 , sizeof( struct V_38 ) ) ;
V_39 -> V_54 = F_47 ( V_9 -> V_55 ) ;
}
static void F_48 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
if ( ! F_44 ( V_23 , V_12 ) ) {
F_49 ( V_12 ) ;
return;
}
if ( F_50 ( V_23 -> V_2 ) ) {
F_51 ( V_12 ) ;
return;
}
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_37 ( & V_9 -> V_56 , V_12 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
static void F_52 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
F_43 ( V_23 , V_12 ) ;
F_48 ( V_23 , V_12 ) ;
}
static void F_53 ( struct V_22 * V_23 , struct V_12 * V_12 ,
T_1 V_8 )
{
F_42 ( V_23 , V_12 , V_8 ) ;
F_48 ( V_23 , V_12 ) ;
}
static void F_54 ( struct V_57 * V_58 )
{
struct V_9 * V_9 = V_58 -> V_23 -> V_9 ;
if ( V_58 -> V_59 && V_58 -> V_60 ) {
F_25 ( & V_58 -> V_30 , & V_9 -> V_61 ) ;
F_4 ( V_9 ) ;
}
}
static void F_55 ( int V_62 , unsigned long V_63 , void * V_64 )
{
unsigned long V_24 ;
struct V_57 * V_58 = V_64 ;
struct V_9 * V_9 = V_58 -> V_23 -> V_9 ;
V_58 -> V_65 = V_62 || V_63 ? - V_66 : 0 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_58 -> V_60 = 1 ;
F_54 ( V_58 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
static void F_56 ( struct V_12 * V_12 , int V_65 )
{
unsigned long V_24 ;
struct V_38 * V_39 = F_35 ( V_12 , sizeof( struct V_38 ) ) ;
struct V_57 * V_58 = V_39 -> V_67 ;
struct V_9 * V_9 = V_58 -> V_23 -> V_9 ;
V_58 -> V_65 = V_65 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_58 -> V_60 = 1 ;
F_54 ( V_58 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
static void F_57 ( struct V_22 * V_23 , struct V_13 * V_19 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_10 ( V_9 , V_19 , & V_9 -> V_26 ) ;
F_16 ( & V_23 -> V_9 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
static void F_58 ( struct V_22 * V_23 , struct V_13 * V_19 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_12 ( V_9 , V_19 , & V_9 -> V_26 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
static void F_59 ( struct V_57 * V_58 )
{
if ( V_58 -> V_12 )
V_58 -> V_12 -> V_68 = V_58 -> V_69 ;
F_17 ( V_58 -> V_23 -> V_9 , V_58 -> V_19 ) ;
F_27 ( & V_58 -> V_30 ) ;
F_60 ( V_58 , V_58 -> V_23 -> V_9 -> V_70 ) ;
}
static void F_61 ( struct V_57 * V_58 )
{
struct V_22 * V_23 = V_58 -> V_23 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_12 * V_12 ;
int V_15 ;
V_12 = V_58 -> V_12 ;
if ( V_12 )
V_12 -> V_68 = V_58 -> V_69 ;
if ( V_58 -> V_65 ) {
F_17 ( V_9 , V_58 -> V_19 ) ;
goto V_71;
}
V_15 = F_62 ( V_23 -> V_2 , V_58 -> V_72 , V_58 -> V_73 ) ;
if ( V_15 ) {
F_63 ( L_1 ,
F_64 ( V_9 -> V_34 ) , V_15 ) ;
F_65 ( V_9 , V_74 ) ;
F_17 ( V_9 , V_58 -> V_19 ) ;
goto V_71;
}
if ( V_12 ) {
F_58 ( V_23 , V_58 -> V_19 ) ;
F_36 ( V_12 , 0 ) ;
} else
F_57 ( V_23 , V_58 -> V_19 ) ;
V_71:
F_27 ( & V_58 -> V_30 ) ;
F_60 ( V_58 , V_9 -> V_70 ) ;
}
static void F_66 ( struct V_57 * V_58 )
{
struct V_22 * V_23 = V_58 -> V_23 ;
F_51 ( V_58 -> V_12 ) ;
F_58 ( V_23 , V_58 -> V_19 ) ;
F_58 ( V_23 , V_58 -> V_75 ) ;
F_60 ( V_58 , V_23 -> V_9 -> V_70 ) ;
}
static void F_67 ( struct V_57 * V_58 )
{
struct V_22 * V_23 = V_58 -> V_23 ;
F_46 ( V_23 -> V_9 , V_58 -> V_12 ) ;
F_58 ( V_23 , V_58 -> V_19 ) ;
F_58 ( V_23 , V_58 -> V_75 ) ;
if ( V_58 -> V_76 )
F_53 ( V_23 , V_58 -> V_12 , V_58 -> V_73 ) ;
else
F_36 ( V_58 -> V_12 , 0 ) ;
F_60 ( V_58 , V_23 -> V_9 -> V_70 ) ;
}
static void F_68 ( struct V_57 * V_58 )
{
int V_15 ;
struct V_22 * V_23 = V_58 -> V_23 ;
V_15 = F_69 ( V_23 -> V_2 , V_58 -> V_72 ) ;
if ( V_15 )
F_63 ( L_2 ) ;
F_67 ( V_58 ) ;
}
static void F_70 ( struct V_9 * V_9 , struct V_77 * V_78 ,
T_3 * V_79 )
{
unsigned long V_24 ;
struct V_77 V_80 ;
struct V_57 * V_58 , * V_33 ;
F_21 ( & V_80 ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_71 ( V_78 , & V_80 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_72 ( V_58 , V_33 , & V_80 , V_30 )
( * V_79 ) ( V_58 ) ;
}
static int F_73 ( struct V_9 * V_9 , struct V_12 * V_12 )
{
return V_12 -> V_81 == ( V_9 -> V_45 << V_82 ) ;
}
static int F_74 ( struct V_9 * V_9 , struct V_12 * V_12 )
{
return ( F_75 ( V_12 ) == V_83 ) &&
F_73 ( V_9 , V_12 ) ;
}
static void F_76 ( struct V_12 * V_12 , T_4 * * V_84 ,
T_4 * V_79 )
{
* V_84 = V_12 -> V_68 ;
V_12 -> V_68 = V_79 ;
}
static int F_77 ( struct V_9 * V_9 )
{
if ( V_9 -> V_85 )
return 0 ;
V_9 -> V_85 = F_78 ( V_9 -> V_70 , V_86 ) ;
return V_9 -> V_85 ? 0 : - V_87 ;
}
static struct V_57 * F_79 ( struct V_9 * V_9 )
{
struct V_57 * V_15 = V_9 -> V_85 ;
F_23 ( ! V_9 -> V_85 ) ;
V_9 -> V_85 = NULL ;
return V_15 ;
}
static void F_80 ( struct V_22 * V_23 , T_1 V_72 ,
struct V_88 * V_89 , T_1 V_90 ,
T_1 V_91 ,
struct V_13 * V_19 , struct V_12 * V_12 )
{
int V_15 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_57 * V_58 = F_79 ( V_9 ) ;
F_21 ( & V_58 -> V_30 ) ;
V_58 -> V_59 = 0 ;
V_58 -> V_60 = 0 ;
V_58 -> V_23 = V_23 ;
V_58 -> V_72 = V_72 ;
V_58 -> V_73 = V_91 ;
V_58 -> V_19 = V_19 ;
V_58 -> V_65 = 0 ;
V_58 -> V_12 = NULL ;
if ( ! F_81 ( V_9 -> V_92 , & V_58 -> V_30 ) )
V_58 -> V_59 = 1 ;
if ( F_74 ( V_9 , V_12 ) ) {
struct V_38 * V_39 = F_35 ( V_12 , sizeof( struct V_38 ) ) ;
V_39 -> V_67 = V_58 ;
V_58 -> V_12 = V_12 ;
F_76 ( V_12 , & V_58 -> V_69 , F_56 ) ;
F_46 ( V_9 , V_12 ) ;
F_53 ( V_23 , V_12 , V_91 ) ;
} else {
struct V_93 V_94 , V_95 ;
V_94 . V_48 = V_89 -> V_48 ;
V_94 . V_96 = V_90 * V_9 -> V_45 ;
V_94 . V_97 = V_9 -> V_45 ;
V_95 . V_48 = V_23 -> V_47 -> V_48 ;
V_95 . V_96 = V_91 * V_9 -> V_45 ;
V_95 . V_97 = V_9 -> V_45 ;
V_15 = F_82 ( V_9 -> V_98 , & V_94 , 1 , & V_95 ,
0 , F_55 , V_58 ) ;
if ( V_15 < 0 ) {
F_60 ( V_58 , V_9 -> V_70 ) ;
F_63 ( L_3 ) ;
F_17 ( V_9 , V_19 ) ;
}
}
}
static void F_83 ( struct V_22 * V_23 , T_1 V_72 ,
T_1 V_90 , T_1 V_91 ,
struct V_13 * V_19 , struct V_12 * V_12 )
{
F_80 ( V_23 , V_72 , V_23 -> V_47 ,
V_90 , V_91 , V_19 , V_12 ) ;
}
static void F_84 ( struct V_22 * V_23 , T_1 V_72 ,
T_1 V_91 ,
struct V_13 * V_19 , struct V_12 * V_12 )
{
F_80 ( V_23 , V_72 , V_23 -> V_49 ,
V_72 , V_91 , V_19 , V_12 ) ;
}
static void F_85 ( struct V_22 * V_23 , T_1 V_72 ,
T_1 V_73 , struct V_13 * V_19 ,
struct V_12 * V_12 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_57 * V_58 = F_79 ( V_9 ) ;
F_21 ( & V_58 -> V_30 ) ;
V_58 -> V_59 = 1 ;
V_58 -> V_60 = 0 ;
V_58 -> V_23 = V_23 ;
V_58 -> V_72 = V_72 ;
V_58 -> V_73 = V_73 ;
V_58 -> V_19 = V_19 ;
V_58 -> V_65 = 0 ;
V_58 -> V_12 = NULL ;
if ( ! V_9 -> V_99 . V_100 )
F_61 ( V_58 ) ;
else if ( F_74 ( V_9 , V_12 ) ) {
struct V_38 * V_39 = F_35 ( V_12 , sizeof( struct V_38 ) ) ;
V_39 -> V_67 = V_58 ;
V_58 -> V_12 = V_12 ;
F_76 ( V_12 , & V_58 -> V_69 , F_56 ) ;
F_46 ( V_9 , V_12 ) ;
F_53 ( V_23 , V_12 , V_73 ) ;
} else {
int V_15 ;
struct V_93 V_95 ;
V_95 . V_48 = V_23 -> V_47 -> V_48 ;
V_95 . V_96 = V_73 * V_9 -> V_45 ;
V_95 . V_97 = V_9 -> V_45 ;
V_15 = F_86 ( V_9 -> V_98 , 1 , & V_95 , 0 , F_55 , V_58 ) ;
if ( V_15 < 0 ) {
F_60 ( V_58 , V_9 -> V_70 ) ;
F_63 ( L_4 ) ;
F_17 ( V_9 , V_19 ) ;
}
}
}
static int F_87 ( struct V_9 * V_9 )
{
int V_15 ;
if ( F_88 ( V_9 ) != V_101 )
return - V_102 ;
V_15 = F_89 ( V_9 -> V_103 ) ;
if ( V_15 ) {
F_63 ( L_5 ,
F_64 ( V_9 -> V_34 ) , V_15 ) ;
F_65 ( V_9 , V_74 ) ;
}
return V_15 ;
}
static int F_90 ( struct V_22 * V_23 , T_1 * V_104 )
{
int V_15 ;
T_1 V_105 ;
unsigned long V_24 ;
struct V_9 * V_9 = V_23 -> V_9 ;
if ( V_9 -> V_106 )
return - V_107 ;
V_15 = F_91 ( V_9 -> V_103 , & V_105 ) ;
if ( V_15 )
return V_15 ;
if ( V_105 <= V_9 -> V_108 && ! V_9 -> V_109 ) {
F_92 ( L_6 ,
F_64 ( V_9 -> V_34 ) ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_9 -> V_109 = 1 ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_93 ( V_9 -> V_110 -> V_111 ) ;
}
if ( ! V_105 ) {
V_15 = F_87 ( V_9 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_91 ( V_9 -> V_103 , & V_105 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_105 ) {
F_92 ( L_7 ,
F_64 ( V_9 -> V_34 ) ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_9 -> V_106 = 1 ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
return - V_107 ;
}
}
V_15 = F_94 ( V_9 -> V_103 , V_104 ) ;
if ( V_15 ) {
if ( V_15 == - V_107 &&
! F_95 ( V_9 -> V_103 , & V_105 ) &&
! V_105 ) {
F_92 ( L_8 ,
F_64 ( V_9 -> V_34 ) ) ;
F_65 ( V_9 , V_74 ) ;
}
return V_15 ;
}
return 0 ;
}
static void F_96 ( struct V_12 * V_12 )
{
struct V_38 * V_39 = F_35 ( V_12 , sizeof( struct V_38 ) ) ;
struct V_22 * V_23 = V_39 -> V_23 ;
struct V_9 * V_9 = V_23 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_37 ( & V_9 -> V_41 , V_12 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
static void F_97 ( struct V_9 * V_9 , struct V_13 * V_19 )
{
struct V_12 * V_12 ;
struct V_20 V_21 ;
F_32 ( & V_21 ) ;
F_10 ( V_9 , V_19 , & V_21 ) ;
while ( ( V_12 = F_34 ( & V_21 ) ) )
F_96 ( V_12 ) ;
}
static void F_98 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
int V_15 ;
unsigned long V_24 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_13 * V_19 , * V_75 ;
struct V_4 V_5 , V_112 ;
T_1 V_8 = F_40 ( V_23 , V_12 ) ;
struct V_113 V_114 ;
struct V_57 * V_58 ;
F_3 ( V_23 -> V_2 , V_8 , & V_5 ) ;
if ( F_6 ( V_23 -> V_9 , & V_5 , V_12 , & V_19 ) )
return;
V_15 = F_99 ( V_23 -> V_2 , V_8 , 1 , & V_114 ) ;
switch ( V_15 ) {
case 0 :
F_1 ( V_23 -> V_2 , V_114 . V_8 , & V_112 ) ;
if ( F_6 ( V_23 -> V_9 , & V_112 , V_12 , & V_75 ) ) {
F_58 ( V_23 , V_19 ) ;
break;
}
if ( F_73 ( V_9 , V_12 ) ) {
V_58 = F_79 ( V_9 ) ;
V_58 -> V_23 = V_23 ;
V_58 -> V_76 = ( ! V_114 . V_115 ) && V_9 -> V_99 . V_116 ;
V_58 -> V_72 = V_8 ;
V_58 -> V_73 = V_114 . V_8 ;
V_58 -> V_19 = V_19 ;
V_58 -> V_75 = V_75 ;
V_58 -> V_65 = 0 ;
V_58 -> V_12 = V_12 ;
if ( ! F_81 ( V_9 -> V_55 , & V_58 -> V_30 ) ) {
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_25 ( & V_58 -> V_30 , & V_9 -> V_117 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
} else {
F_46 ( V_9 , V_12 ) ;
F_58 ( V_23 , V_19 ) ;
F_58 ( V_23 , V_75 ) ;
if ( ( ! V_114 . V_115 ) && V_9 -> V_99 . V_116 )
F_53 ( V_23 , V_12 , V_114 . V_8 ) ;
else
F_36 ( V_12 , 0 ) ;
}
break;
case - V_118 :
F_58 ( V_23 , V_19 ) ;
F_36 ( V_12 , 0 ) ;
break;
default:
F_63 ( L_9 ,
V_119 , V_15 ) ;
F_58 ( V_23 , V_19 ) ;
F_51 ( V_12 ) ;
break;
}
}
static void F_100 ( struct V_22 * V_23 , struct V_12 * V_12 , T_1 V_8 ,
struct V_4 * V_5 ,
struct V_113 * V_114 ,
struct V_13 * V_19 )
{
int V_15 ;
T_1 V_73 ;
struct V_9 * V_9 = V_23 -> V_9 ;
V_15 = F_90 ( V_23 , & V_73 ) ;
switch ( V_15 ) {
case 0 :
F_83 ( V_23 , V_8 , V_114 -> V_8 ,
V_73 , V_19 , V_12 ) ;
break;
case - V_107 :
F_97 ( V_9 , V_19 ) ;
break;
default:
F_63 ( L_10 ,
V_119 , V_15 ) ;
F_65 ( V_9 , V_74 ) ;
F_17 ( V_9 , V_19 ) ;
break;
}
}
static void F_101 ( struct V_22 * V_23 , struct V_12 * V_12 ,
T_1 V_8 ,
struct V_113 * V_114 )
{
struct V_13 * V_19 ;
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_4 V_5 ;
F_1 ( V_23 -> V_2 , V_114 -> V_8 , & V_5 ) ;
if ( F_6 ( V_9 , & V_5 , V_12 , & V_19 ) )
return;
if ( F_75 ( V_12 ) == V_83 && V_12 -> V_81 )
F_100 ( V_23 , V_12 , V_8 , & V_5 , V_114 , V_19 ) ;
else {
struct V_38 * V_39 = F_35 ( V_12 , sizeof( struct V_38 ) ) ;
V_39 -> V_120 = F_47 ( V_9 -> V_92 ) ;
F_46 ( V_9 , V_12 ) ;
F_58 ( V_23 , V_19 ) ;
F_53 ( V_23 , V_12 , V_114 -> V_8 ) ;
}
}
static void F_102 ( struct V_22 * V_23 , struct V_12 * V_12 , T_1 V_8 ,
struct V_13 * V_19 )
{
int V_15 ;
T_1 V_73 ;
struct V_9 * V_9 = V_23 -> V_9 ;
if ( ! V_12 -> V_81 ) {
F_46 ( V_9 , V_12 ) ;
F_58 ( V_23 , V_19 ) ;
F_53 ( V_23 , V_12 , 0 ) ;
return;
}
if ( F_75 ( V_12 ) == V_121 ) {
F_103 ( V_12 ) ;
F_58 ( V_23 , V_19 ) ;
F_36 ( V_12 , 0 ) ;
return;
}
V_15 = F_90 ( V_23 , & V_73 ) ;
switch ( V_15 ) {
case 0 :
if ( V_23 -> V_49 )
F_84 ( V_23 , V_8 , V_73 , V_19 , V_12 ) ;
else
F_85 ( V_23 , V_8 , V_73 , V_19 , V_12 ) ;
break;
case - V_107 :
F_97 ( V_9 , V_19 ) ;
break;
default:
F_63 ( L_10 ,
V_119 , V_15 ) ;
F_65 ( V_9 , V_74 ) ;
F_17 ( V_9 , V_19 ) ;
break;
}
}
static void F_104 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
int V_15 ;
struct V_9 * V_9 = V_23 -> V_9 ;
T_1 V_8 = F_40 ( V_23 , V_12 ) ;
struct V_13 * V_19 ;
struct V_4 V_5 ;
struct V_113 V_114 ;
F_3 ( V_23 -> V_2 , V_8 , & V_5 ) ;
if ( F_6 ( V_9 , & V_5 , V_12 , & V_19 ) )
return;
V_15 = F_99 ( V_23 -> V_2 , V_8 , 1 , & V_114 ) ;
switch ( V_15 ) {
case 0 :
if ( V_114 . V_115 ) {
F_101 ( V_23 , V_12 , V_8 , & V_114 ) ;
F_58 ( V_23 , V_19 ) ;
} else {
F_46 ( V_9 , V_12 ) ;
F_58 ( V_23 , V_19 ) ;
F_53 ( V_23 , V_12 , V_114 . V_8 ) ;
}
break;
case - V_118 :
if ( F_75 ( V_12 ) == V_121 && V_23 -> V_49 ) {
F_46 ( V_9 , V_12 ) ;
F_58 ( V_23 , V_19 ) ;
F_52 ( V_23 , V_12 ) ;
} else
F_102 ( V_23 , V_12 , V_8 , V_19 ) ;
break;
default:
F_63 ( L_9 ,
V_119 , V_15 ) ;
F_58 ( V_23 , V_19 ) ;
F_51 ( V_12 ) ;
break;
}
}
static void F_105 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
int V_15 ;
int V_122 = F_75 ( V_12 ) ;
T_1 V_8 = F_40 ( V_23 , V_12 ) ;
struct V_113 V_114 ;
V_15 = F_99 ( V_23 -> V_2 , V_8 , 1 , & V_114 ) ;
switch ( V_15 ) {
case 0 :
if ( V_114 . V_115 && ( V_122 == V_83 ) && V_12 -> V_81 )
F_51 ( V_12 ) ;
else {
F_46 ( V_23 -> V_9 , V_12 ) ;
F_53 ( V_23 , V_12 , V_114 . V_8 ) ;
}
break;
case - V_118 :
if ( V_122 != V_121 ) {
F_51 ( V_12 ) ;
break;
}
if ( V_23 -> V_49 ) {
F_46 ( V_23 -> V_9 , V_12 ) ;
F_52 ( V_23 , V_12 ) ;
break;
}
F_103 ( V_12 ) ;
F_36 ( V_12 , 0 ) ;
break;
default:
F_63 ( L_9 ,
V_119 , V_15 ) ;
F_51 ( V_12 ) ;
break;
}
}
static void F_106 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
F_51 ( V_12 ) ;
}
static int F_107 ( struct V_9 * V_9 )
{
return V_123 < V_9 -> V_124 ||
V_123 > V_9 -> V_124 + V_125 ;
}
static void F_108 ( struct V_9 * V_9 )
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
if ( F_77 ( V_9 ) ) {
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_33 ( & V_9 -> V_26 , & V_21 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
break;
}
if ( V_12 -> V_50 & V_53 )
V_9 -> F_98 ( V_23 , V_12 ) ;
else
V_9 -> F_104 ( V_23 , V_12 ) ;
}
F_32 ( & V_21 ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_33 ( & V_21 , & V_9 -> V_56 ) ;
F_32 ( & V_9 -> V_56 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
if ( F_109 ( & V_21 ) && ! F_107 ( V_9 ) )
return;
if ( F_87 ( V_9 ) ) {
while ( ( V_12 = F_34 ( & V_21 ) ) )
F_51 ( V_12 ) ;
return;
}
V_9 -> V_124 = V_123 ;
while ( ( V_12 = F_34 ( & V_21 ) ) )
F_49 ( V_12 ) ;
}
static void F_110 ( struct V_126 * V_127 )
{
struct V_9 * V_9 = F_111 ( V_127 , struct V_9 , V_11 ) ;
F_70 ( V_9 , & V_9 -> V_61 , & V_9 -> F_61 ) ;
F_70 ( V_9 , & V_9 -> V_117 , & V_9 -> F_68 ) ;
F_108 ( V_9 ) ;
}
static void F_112 ( struct V_126 * V_127 )
{
struct V_9 * V_9 = F_111 ( F_113 ( V_127 ) , struct V_9 , V_128 ) ;
F_4 ( V_9 ) ;
F_114 ( V_9 -> V_10 , & V_9 -> V_128 , V_125 ) ;
}
static enum V_129 F_88 ( struct V_9 * V_9 )
{
return V_9 -> V_99 . V_130 ;
}
static void F_65 ( struct V_9 * V_9 , enum V_129 V_130 )
{
int V_15 ;
V_9 -> V_99 . V_130 = V_130 ;
switch ( V_130 ) {
case V_131 :
F_115 ( L_11 ,
F_64 ( V_9 -> V_34 ) ) ;
F_116 ( V_9 -> V_103 ) ;
V_9 -> F_104 = F_106 ;
V_9 -> F_98 = F_106 ;
V_9 -> F_61 = F_59 ;
V_9 -> F_68 = F_66 ;
break;
case V_74 :
F_115 ( L_12 ,
F_64 ( V_9 -> V_34 ) ) ;
V_15 = F_117 ( V_9 -> V_103 ) ;
if ( V_15 ) {
F_115 ( L_13 ,
F_64 ( V_9 -> V_34 ) ) ;
F_65 ( V_9 , V_131 ) ;
} else {
F_116 ( V_9 -> V_103 ) ;
V_9 -> F_104 = F_105 ;
V_9 -> F_98 = F_98 ;
V_9 -> F_61 = F_59 ;
V_9 -> F_68 = F_67 ;
}
break;
case V_101 :
F_118 ( V_9 -> V_103 ) ;
V_9 -> F_104 = F_104 ;
V_9 -> F_98 = F_98 ;
V_9 -> F_61 = F_61 ;
V_9 -> F_68 = F_68 ;
break;
}
}
static void F_119 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
unsigned long V_24 ;
struct V_9 * V_9 = V_23 -> V_9 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_37 ( & V_9 -> V_26 , V_12 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
static void F_120 ( struct V_22 * V_23 , struct V_12 * V_12 )
{
struct V_38 * V_39 = F_35 ( V_12 , sizeof( struct V_38 ) ) ;
V_39 -> V_23 = V_23 ;
V_39 -> V_120 = NULL ;
V_39 -> V_54 = NULL ;
V_39 -> V_67 = NULL ;
}
static int F_121 ( struct V_132 * V_110 , struct V_12 * V_12 )
{
int V_15 ;
struct V_22 * V_23 = V_110 -> V_133 ;
T_1 V_8 = F_40 ( V_23 , V_12 ) ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_113 V_104 ;
struct V_13 V_134 , V_75 ;
struct V_13 * V_14 ;
struct V_4 V_5 ;
F_120 ( V_23 , V_12 ) ;
if ( F_88 ( V_23 -> V_9 ) == V_131 ) {
F_51 ( V_12 ) ;
return V_135 ;
}
if ( V_12 -> V_50 & ( V_53 | V_51 | V_52 ) ) {
F_119 ( V_23 , V_12 ) ;
return V_135 ;
}
V_15 = F_99 ( V_2 , V_8 , 0 , & V_104 ) ;
switch ( V_15 ) {
case 0 :
if ( F_122 ( V_104 . V_115 ) ) {
F_119 ( V_23 , V_12 ) ;
return V_135 ;
}
F_3 ( V_23 -> V_2 , V_8 , & V_5 ) ;
if ( F_8 ( V_23 -> V_9 -> V_17 , & V_5 , V_12 , & V_134 , & V_14 ) )
return V_135 ;
F_1 ( V_23 -> V_2 , V_104 . V_8 , & V_5 ) ;
if ( F_8 ( V_23 -> V_9 -> V_17 , & V_5 , V_12 , & V_75 , & V_14 ) ) {
F_14 ( V_23 , & V_134 ) ;
return V_135 ;
}
F_46 ( V_23 -> V_9 , V_12 ) ;
F_14 ( V_23 , & V_75 ) ;
F_14 ( V_23 , & V_134 ) ;
F_42 ( V_23 , V_12 , V_104 . V_8 ) ;
return V_136 ;
case - V_118 :
if ( F_88 ( V_23 -> V_9 ) == V_74 ) {
F_51 ( V_12 ) ;
return V_135 ;
}
case - V_137 :
F_119 ( V_23 , V_12 ) ;
return V_135 ;
default:
F_51 ( V_12 ) ;
return V_135 ;
}
}
static int F_123 ( struct V_138 * V_139 , int V_140 )
{
int V_15 ;
unsigned long V_24 ;
struct V_141 * V_142 = F_111 ( V_139 , struct V_141 , V_143 ) ;
F_15 ( & V_142 -> V_9 -> V_25 , V_24 ) ;
V_15 = ! F_109 ( & V_142 -> V_9 -> V_41 ) ;
F_16 ( & V_142 -> V_9 -> V_25 , V_24 ) ;
if ( ! V_15 ) {
struct V_144 * V_145 = F_124 ( V_142 -> V_146 -> V_48 ) ;
V_15 = F_125 ( & V_145 -> V_147 , V_140 ) ;
}
return V_15 ;
}
static void F_126 ( struct V_9 * V_9 )
{
F_33 ( & V_9 -> V_26 , & V_9 -> V_41 ) ;
F_32 ( & V_9 -> V_41 ) ;
}
static bool F_127 ( struct V_141 * V_142 )
{
struct V_144 * V_145 = F_124 ( V_142 -> V_146 -> V_48 ) ;
return V_145 && F_128 ( V_145 ) ;
}
static bool F_129 ( T_2 V_148 , T_5 V_149 )
{
return ! F_41 ( V_148 , V_149 ) ;
}
static void F_130 ( struct V_141 * V_142 )
{
struct V_9 * V_9 = V_142 -> V_9 ;
struct V_35 * V_150 = V_142 -> V_146 -> V_48 ;
struct V_151 * V_152 = & F_124 ( V_150 ) -> V_153 ;
T_2 V_148 = V_9 -> V_45 << V_82 ;
const char * V_154 = NULL ;
char V_155 [ V_156 ] ;
if ( ! V_142 -> V_157 . V_116 )
return;
if ( ! F_127 ( V_142 ) )
V_154 = L_14 ;
else if ( V_152 -> V_158 < V_9 -> V_45 )
V_154 = L_15 ;
else if ( V_152 -> V_159 > V_148 )
V_154 = L_16 ;
else if ( ! F_129 ( V_148 , V_152 -> V_159 ) )
V_154 = L_17 ;
if ( V_154 ) {
F_92 ( L_18 , F_131 ( V_150 , V_155 ) , V_154 ) ;
V_142 -> V_157 . V_116 = false ;
}
}
static int F_132 ( struct V_9 * V_9 , struct V_132 * V_110 )
{
struct V_141 * V_142 = V_110 -> V_133 ;
enum V_129 V_160 = V_9 -> V_99 . V_130 ;
enum V_129 V_161 = V_142 -> V_157 . V_130 ;
if ( V_160 == V_131 )
V_161 = V_160 ;
V_9 -> V_110 = V_110 ;
V_9 -> V_108 = V_142 -> V_108 ;
V_9 -> V_99 = V_142 -> V_157 ;
F_65 ( V_9 , V_161 ) ;
return 0 ;
}
static void F_133 ( struct V_9 * V_9 , struct V_132 * V_110 )
{
if ( V_9 -> V_110 == V_110 )
V_9 -> V_110 = NULL ;
}
static void F_134 ( struct V_162 * V_99 )
{
V_99 -> V_130 = V_101 ;
V_99 -> V_100 = true ;
V_99 -> V_163 = true ;
V_99 -> V_116 = true ;
}
static void F_135 ( struct V_9 * V_9 )
{
F_26 ( V_9 ) ;
if ( F_136 ( V_9 -> V_103 ) < 0 )
F_92 ( L_19 , V_119 ) ;
F_137 ( V_9 -> V_17 ) ;
F_138 ( V_9 -> V_98 ) ;
if ( V_9 -> V_10 )
F_139 ( V_9 -> V_10 ) ;
if ( V_9 -> V_85 )
F_60 ( V_9 -> V_85 , V_9 -> V_70 ) ;
F_140 ( V_9 -> V_70 ) ;
F_141 ( V_9 -> V_92 ) ;
F_141 ( V_9 -> V_55 ) ;
F_142 ( V_9 ) ;
}
static struct V_9 * F_143 ( struct V_31 * V_34 ,
struct V_35 * V_164 ,
unsigned long V_148 ,
int V_165 , char * * error )
{
int V_15 ;
void * V_166 ;
struct V_9 * V_9 ;
struct V_167 * V_103 ;
bool V_168 = V_165 ? false : true ;
V_103 = F_144 ( V_164 , V_148 , V_168 ) ;
if ( F_145 ( V_103 ) ) {
* error = L_20 ;
return (struct V_9 * ) V_103 ;
}
V_9 = F_146 ( sizeof( * V_9 ) , V_169 ) ;
if ( ! V_9 ) {
* error = L_21 ;
V_166 = F_147 ( - V_87 ) ;
goto V_170;
}
V_9 -> V_103 = V_103 ;
V_9 -> V_45 = V_148 ;
if ( V_148 & ( V_148 - 1 ) )
V_9 -> V_42 = - 1 ;
else
V_9 -> V_42 = F_148 ( V_148 ) ;
V_9 -> V_108 = 0 ;
F_134 ( & V_9 -> V_99 ) ;
V_9 -> V_17 = F_149 ( V_171 ) ;
if ( ! V_9 -> V_17 ) {
* error = L_22 ;
V_166 = F_147 ( - V_87 ) ;
goto V_172;
}
V_9 -> V_98 = F_150 ( & V_173 ) ;
if ( F_145 ( V_9 -> V_98 ) ) {
V_15 = F_151 ( V_9 -> V_98 ) ;
* error = L_23 ;
V_166 = F_147 ( V_15 ) ;
goto V_174;
}
V_9 -> V_10 = F_152 ( L_24 V_175 , V_176 ) ;
if ( ! V_9 -> V_10 ) {
* error = L_25 ;
V_166 = F_147 ( - V_87 ) ;
goto V_177;
}
F_153 ( & V_9 -> V_11 , F_110 ) ;
F_154 ( & V_9 -> V_128 , F_112 ) ;
F_155 ( & V_9 -> V_25 ) ;
F_32 ( & V_9 -> V_26 ) ;
F_32 ( & V_9 -> V_56 ) ;
F_21 ( & V_9 -> V_61 ) ;
F_21 ( & V_9 -> V_117 ) ;
V_9 -> V_109 = 0 ;
V_9 -> V_106 = 0 ;
F_32 ( & V_9 -> V_41 ) ;
V_9 -> V_92 = F_156 () ;
if ( ! V_9 -> V_92 ) {
* error = L_26 ;
V_166 = F_147 ( - V_87 ) ;
goto V_178;
}
V_9 -> V_55 = F_156 () ;
if ( ! V_9 -> V_55 ) {
* error = L_27 ;
V_166 = F_147 ( - V_87 ) ;
goto V_179;
}
V_9 -> V_85 = NULL ;
V_9 -> V_70 = F_157 ( V_180 ,
V_181 ) ;
if ( ! V_9 -> V_70 ) {
* error = L_28 ;
V_166 = F_147 ( - V_87 ) ;
goto V_182;
}
V_9 -> V_183 = 1 ;
V_9 -> V_124 = V_123 ;
V_9 -> V_34 = V_34 ;
V_9 -> V_36 = V_164 ;
F_22 ( V_9 ) ;
return V_9 ;
V_182:
F_141 ( V_9 -> V_55 ) ;
V_179:
F_141 ( V_9 -> V_92 ) ;
V_178:
F_139 ( V_9 -> V_10 ) ;
V_177:
F_138 ( V_9 -> V_98 ) ;
V_174:
F_137 ( V_9 -> V_17 ) ;
V_172:
F_142 ( V_9 ) ;
V_170:
if ( F_136 ( V_103 ) )
F_92 ( L_19 , V_119 ) ;
return V_166 ;
}
static void F_158 ( struct V_9 * V_9 )
{
F_23 ( ! F_24 ( & V_27 . V_28 ) ) ;
V_9 -> V_183 ++ ;
}
static void F_159 ( struct V_9 * V_9 )
{
F_23 ( ! F_24 ( & V_27 . V_28 ) ) ;
F_23 ( ! V_9 -> V_183 ) ;
if ( ! -- V_9 -> V_183 )
F_135 ( V_9 ) ;
}
static struct V_9 * F_160 ( struct V_31 * V_34 ,
struct V_35 * V_164 ,
unsigned long V_148 , int V_165 ,
char * * error , int * V_184 )
{
struct V_9 * V_9 = F_30 ( V_164 ) ;
if ( V_9 ) {
if ( V_9 -> V_34 != V_34 ) {
* error = L_29 ;
return F_147 ( - V_185 ) ;
}
F_158 ( V_9 ) ;
} else {
V_9 = F_28 ( V_34 ) ;
if ( V_9 ) {
if ( V_9 -> V_36 != V_164 ) {
* error = L_30 ;
return F_147 ( - V_102 ) ;
}
F_158 ( V_9 ) ;
} else {
V_9 = F_143 ( V_34 , V_164 , V_148 , V_165 , error ) ;
* V_184 = 1 ;
}
}
return V_9 ;
}
static void F_161 ( struct V_132 * V_110 )
{
struct V_141 * V_142 = V_110 -> V_133 ;
F_162 ( & V_27 . V_28 ) ;
F_133 ( V_142 -> V_9 , V_110 ) ;
F_159 ( V_142 -> V_9 ) ;
F_163 ( V_110 , V_142 -> V_164 ) ;
F_163 ( V_110 , V_142 -> V_146 ) ;
F_142 ( V_142 ) ;
F_164 ( & V_27 . V_28 ) ;
}
static int F_165 ( struct V_186 * V_187 , struct V_162 * V_99 ,
struct V_132 * V_110 )
{
int V_15 ;
unsigned V_188 ;
const char * V_189 ;
static struct V_190 V_191 [] = {
{ 0 , 3 , L_31 } ,
} ;
if ( ! V_187 -> V_188 )
return 0 ;
V_15 = F_166 ( V_191 , V_187 , & V_188 , & V_110 -> error ) ;
if ( V_15 )
return - V_102 ;
while ( V_188 && ! V_15 ) {
V_189 = F_167 ( V_187 ) ;
V_188 -- ;
if ( ! strcasecmp ( V_189 , L_32 ) )
V_99 -> V_100 = false ;
else if ( ! strcasecmp ( V_189 , L_33 ) )
V_99 -> V_163 = false ;
else if ( ! strcasecmp ( V_189 , L_34 ) )
V_99 -> V_116 = false ;
else if ( ! strcasecmp ( V_189 , L_35 ) )
V_99 -> V_130 = V_74 ;
else {
V_110 -> error = L_36 ;
V_15 = - V_102 ;
break;
}
}
return V_15 ;
}
static void F_168 ( void * V_64 )
{
struct V_9 * V_9 = V_64 ;
F_92 ( L_37 ,
F_64 ( V_9 -> V_34 ) ) ;
F_93 ( V_9 -> V_110 -> V_111 ) ;
}
static T_2 F_169 ( struct V_35 * V_48 )
{
T_2 V_192 = F_170 ( V_48 -> V_193 ) >> V_82 ;
char V_194 [ V_156 ] ;
if ( V_192 > V_195 ) {
F_92 ( L_38 ,
F_131 ( V_48 , V_194 ) , V_196 ) ;
V_192 = V_195 ;
}
return V_192 ;
}
static T_1 F_171 ( struct V_35 * V_48 )
{
T_2 V_192 = F_169 ( V_48 ) ;
F_41 ( V_192 , V_197 >> V_82 ) ;
return V_192 ;
}
static T_1 F_172 ( struct V_141 * V_142 )
{
T_1 V_198 = F_171 ( V_142 -> V_164 -> V_48 ) / 4 ;
return F_173 ( ( T_1 ) 1024ULL , V_198 ) ;
}
static int F_174 ( struct V_132 * V_110 , unsigned V_188 , char * * V_199 )
{
int V_15 , V_200 = 0 ;
struct V_141 * V_142 ;
struct V_9 * V_9 ;
struct V_162 V_99 ;
struct V_186 V_187 ;
struct V_88 * V_146 ;
unsigned long V_148 ;
T_1 V_108 ;
struct V_88 * V_164 ;
T_6 V_201 ;
F_162 ( & V_27 . V_28 ) ;
if ( V_188 < 4 ) {
V_110 -> error = L_39 ;
V_15 = - V_102 ;
goto V_202;
}
V_187 . V_188 = V_188 ;
V_187 . V_199 = V_199 ;
F_134 ( & V_99 ) ;
F_175 ( & V_187 , 4 ) ;
V_15 = F_165 ( & V_187 , & V_99 , V_110 ) ;
if ( V_15 )
goto V_202;
V_201 = V_203 | ( ( V_99 . V_130 == V_74 ) ? 0 : V_204 ) ;
V_15 = F_176 ( V_110 , V_199 [ 0 ] , V_201 , & V_164 ) ;
if ( V_15 ) {
V_110 -> error = L_40 ;
goto V_202;
}
( void ) F_169 ( V_164 -> V_48 ) ;
V_15 = F_176 ( V_110 , V_199 [ 1 ] , V_203 | V_204 , & V_146 ) ;
if ( V_15 ) {
V_110 -> error = L_41 ;
goto V_205;
}
if ( F_177 ( V_199 [ 2 ] , 10 , & V_148 ) || ! V_148 ||
V_148 < V_206 ||
V_148 > V_207 ||
V_148 & ( V_206 - 1 ) ) {
V_110 -> error = L_42 ;
V_15 = - V_102 ;
goto V_71;
}
if ( F_178 ( V_199 [ 3 ] , 10 , ( unsigned long long * ) & V_108 ) ) {
V_110 -> error = L_43 ;
V_15 = - V_102 ;
goto V_71;
}
V_142 = F_179 ( sizeof( * V_142 ) , V_169 ) ;
if ( ! V_142 ) {
V_15 = - V_87 ;
goto V_71;
}
V_9 = F_160 ( F_180 ( V_110 -> V_111 ) , V_164 -> V_48 ,
V_148 , V_99 . V_130 == V_74 , & V_110 -> error , & V_200 ) ;
if ( F_145 ( V_9 ) ) {
V_15 = F_151 ( V_9 ) ;
goto V_208;
}
if ( ! V_200 && V_99 . V_163 != V_9 -> V_99 . V_163 ) {
V_110 -> error = L_44 ;
V_15 = - V_102 ;
goto V_209;
}
V_142 -> V_9 = V_9 ;
V_142 -> V_110 = V_110 ;
V_142 -> V_164 = V_164 ;
V_142 -> V_146 = V_146 ;
V_142 -> V_108 = V_108 ;
V_142 -> V_157 = V_142 -> V_210 = V_99 ;
V_110 -> V_211 = 1 ;
V_110 -> V_212 = true ;
if ( V_99 . V_163 && V_99 . V_116 ) {
V_110 -> V_213 = 1 ;
V_110 -> V_214 = true ;
}
V_110 -> V_133 = V_142 ;
V_15 = F_181 ( V_142 -> V_9 -> V_103 ,
F_172 ( V_142 ) ,
F_168 ,
V_9 ) ;
if ( V_15 )
goto V_208;
V_142 -> V_143 . V_215 = F_123 ;
F_182 ( V_110 -> V_111 , & V_142 -> V_143 ) ;
F_164 ( & V_27 . V_28 ) ;
return 0 ;
V_209:
F_159 ( V_9 ) ;
V_208:
F_142 ( V_142 ) ;
V_71:
F_163 ( V_110 , V_146 ) ;
V_205:
F_163 ( V_110 , V_164 ) ;
V_202:
F_164 ( & V_27 . V_28 ) ;
return V_15 ;
}
static int F_183 ( struct V_132 * V_110 , struct V_12 * V_12 )
{
int V_15 ;
struct V_141 * V_142 = V_110 -> V_133 ;
struct V_9 * V_9 = V_142 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_12 -> V_46 = V_142 -> V_146 -> V_48 ;
V_15 = V_136 ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
return V_15 ;
}
static int F_184 ( struct V_132 * V_110 , bool * V_216 )
{
int V_15 ;
struct V_141 * V_142 = V_110 -> V_133 ;
struct V_9 * V_9 = V_142 -> V_9 ;
T_2 V_217 = V_110 -> V_218 ;
T_1 V_219 ;
* V_216 = false ;
( void ) F_41 ( V_217 , V_9 -> V_45 ) ;
V_15 = F_185 ( V_9 -> V_103 , & V_219 ) ;
if ( V_15 ) {
F_115 ( L_45 ,
F_64 ( V_9 -> V_34 ) ) ;
return V_15 ;
}
if ( V_217 < V_219 ) {
F_115 ( L_46 ,
F_64 ( V_9 -> V_34 ) ,
( unsigned long long ) V_217 , V_219 ) ;
return - V_102 ;
} else if ( V_217 > V_219 ) {
V_15 = F_186 ( V_9 -> V_103 , V_217 ) ;
if ( V_15 ) {
F_115 ( L_47 ,
F_64 ( V_9 -> V_34 ) ) ;
F_65 ( V_9 , V_74 ) ;
return V_15 ;
}
* V_216 = true ;
}
return 0 ;
}
static int F_187 ( struct V_132 * V_110 , bool * V_216 )
{
int V_15 ;
struct V_141 * V_142 = V_110 -> V_133 ;
struct V_9 * V_9 = V_142 -> V_9 ;
T_1 V_192 , V_220 ;
* V_216 = false ;
V_192 = F_171 ( V_9 -> V_36 ) ;
V_15 = F_188 ( V_9 -> V_103 , & V_220 ) ;
if ( V_15 ) {
F_115 ( L_48 ,
F_64 ( V_9 -> V_34 ) ) ;
return V_15 ;
}
if ( V_192 < V_220 ) {
F_115 ( L_49 ,
F_64 ( V_9 -> V_34 ) ,
V_192 , V_220 ) ;
return - V_102 ;
} else if ( V_192 > V_220 ) {
V_15 = F_189 ( V_9 -> V_103 , V_192 ) ;
if ( V_15 ) {
F_115 ( L_50 ,
F_64 ( V_9 -> V_34 ) ) ;
return V_15 ;
}
* V_216 = true ;
}
return 0 ;
}
static int F_190 ( struct V_132 * V_110 )
{
int V_15 ;
bool V_221 , V_222 ;
struct V_141 * V_142 = V_110 -> V_133 ;
struct V_9 * V_9 = V_142 -> V_9 ;
V_15 = F_132 ( V_9 , V_110 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_184 ( V_110 , & V_221 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_187 ( V_110 , & V_222 ) ;
if ( V_15 )
return V_15 ;
if ( V_221 || V_222 )
( void ) F_87 ( V_9 ) ;
return 0 ;
}
static void F_191 ( struct V_132 * V_110 )
{
struct V_141 * V_142 = V_110 -> V_133 ;
struct V_9 * V_9 = V_142 -> V_9 ;
unsigned long V_24 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_9 -> V_109 = 0 ;
V_9 -> V_106 = 0 ;
F_126 ( V_9 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_112 ( & V_9 -> V_128 . V_223 ) ;
}
static void F_192 ( struct V_132 * V_110 )
{
struct V_141 * V_142 = V_110 -> V_133 ;
struct V_9 * V_9 = V_142 -> V_9 ;
F_193 ( & V_9 -> V_128 ) ;
F_194 ( V_9 -> V_10 ) ;
( void ) F_87 ( V_9 ) ;
}
static int F_195 ( unsigned V_188 , unsigned V_224 )
{
if ( V_188 != V_224 ) {
F_92 ( L_51 ,
V_188 , V_224 ) ;
return - V_102 ;
}
return 0 ;
}
static int F_196 ( char * V_225 , T_7 * V_226 , int V_227 )
{
if ( ! F_178 ( V_225 , 10 , ( unsigned long long * ) V_226 ) &&
* V_226 <= V_228 )
return 0 ;
if ( V_227 )
F_92 ( L_52 , V_225 ) ;
return - V_102 ;
}
static int F_197 ( unsigned V_188 , char * * V_199 , struct V_9 * V_9 )
{
T_7 V_226 ;
int V_15 ;
V_15 = F_195 ( V_188 , 2 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_196 ( V_199 [ 1 ] , & V_226 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_198 ( V_9 -> V_103 , V_226 ) ;
if ( V_15 ) {
F_92 ( L_53 ,
V_199 [ 1 ] ) ;
return V_15 ;
}
return 0 ;
}
static int F_199 ( unsigned V_188 , char * * V_199 , struct V_9 * V_9 )
{
T_7 V_226 ;
T_7 V_229 ;
int V_15 ;
V_15 = F_195 ( V_188 , 3 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_196 ( V_199 [ 1 ] , & V_226 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_196 ( V_199 [ 2 ] , & V_229 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_200 ( V_9 -> V_103 , V_226 , V_229 ) ;
if ( V_15 ) {
F_92 ( L_54 ,
V_199 [ 1 ] , V_199 [ 2 ] ) ;
return V_15 ;
}
return 0 ;
}
static int F_201 ( unsigned V_188 , char * * V_199 , struct V_9 * V_9 )
{
T_7 V_226 ;
int V_15 ;
V_15 = F_195 ( V_188 , 2 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_196 ( V_199 [ 1 ] , & V_226 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_202 ( V_9 -> V_103 , V_226 ) ;
if ( V_15 )
F_92 ( L_55 , V_199 [ 1 ] ) ;
return V_15 ;
}
static int F_203 ( unsigned V_188 , char * * V_199 , struct V_9 * V_9 )
{
T_7 V_230 , V_231 ;
int V_15 ;
V_15 = F_195 ( V_188 , 3 ) ;
if ( V_15 )
return V_15 ;
if ( F_178 ( V_199 [ 1 ] , 10 , ( unsigned long long * ) & V_230 ) ) {
F_92 ( L_56 , V_199 [ 1 ] ) ;
return - V_102 ;
}
if ( F_178 ( V_199 [ 2 ] , 10 , ( unsigned long long * ) & V_231 ) ) {
F_92 ( L_57 , V_199 [ 2 ] ) ;
return - V_102 ;
}
V_15 = F_204 ( V_9 -> V_103 , V_230 , V_231 ) ;
if ( V_15 ) {
F_92 ( L_58 ,
V_199 [ 1 ] , V_199 [ 2 ] ) ;
return V_15 ;
}
return 0 ;
}
static int F_205 ( unsigned V_188 , char * * V_199 , struct V_9 * V_9 )
{
int V_15 ;
V_15 = F_195 ( V_188 , 1 ) ;
if ( V_15 )
return V_15 ;
( void ) F_87 ( V_9 ) ;
V_15 = F_206 ( V_9 -> V_103 ) ;
if ( V_15 )
F_92 ( L_59 ) ;
return V_15 ;
}
static int F_207 ( unsigned V_188 , char * * V_199 , struct V_9 * V_9 )
{
int V_15 ;
V_15 = F_195 ( V_188 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_208 ( V_9 -> V_103 ) ;
if ( V_15 )
F_92 ( L_60 ) ;
return V_15 ;
}
static int F_209 ( struct V_132 * V_110 , unsigned V_188 , char * * V_199 )
{
int V_15 = - V_102 ;
struct V_141 * V_142 = V_110 -> V_133 ;
struct V_9 * V_9 = V_142 -> V_9 ;
if ( ! strcasecmp ( V_199 [ 0 ] , L_61 ) )
V_15 = F_197 ( V_188 , V_199 , V_9 ) ;
else if ( ! strcasecmp ( V_199 [ 0 ] , L_62 ) )
V_15 = F_199 ( V_188 , V_199 , V_9 ) ;
else if ( ! strcasecmp ( V_199 [ 0 ] , L_63 ) )
V_15 = F_201 ( V_188 , V_199 , V_9 ) ;
else if ( ! strcasecmp ( V_199 [ 0 ] , L_64 ) )
V_15 = F_203 ( V_188 , V_199 , V_9 ) ;
else if ( ! strcasecmp ( V_199 [ 0 ] , L_65 ) )
V_15 = F_205 ( V_188 , V_199 , V_9 ) ;
else if ( ! strcasecmp ( V_199 [ 0 ] , L_66 ) )
V_15 = F_207 ( V_188 , V_199 , V_9 ) ;
else
F_92 ( L_67 , V_199 [ 0 ] ) ;
if ( ! V_15 )
( void ) F_87 ( V_9 ) ;
return V_15 ;
}
static void F_210 ( struct V_162 * V_99 , char * V_104 ,
unsigned V_232 , unsigned V_233 )
{
unsigned V_97 = ! V_99 -> V_100 + ! V_99 -> V_163 +
! V_99 -> V_116 + ( V_99 -> V_130 == V_74 ) ;
F_211 ( L_68 , V_97 ) ;
if ( ! V_99 -> V_100 )
F_211 ( L_69 ) ;
if ( ! V_99 -> V_163 )
F_211 ( L_70 ) ;
if ( ! V_99 -> V_116 )
F_211 ( L_71 ) ;
if ( V_99 -> V_130 == V_74 )
F_211 ( L_72 ) ;
}
static void F_212 ( struct V_132 * V_110 , T_8 type ,
unsigned V_234 , char * V_104 , unsigned V_233 )
{
int V_15 ;
unsigned V_232 = 0 ;
T_9 V_235 ;
T_1 V_236 ;
T_1 V_237 ;
T_1 V_238 ;
T_1 V_239 ;
T_1 V_240 ;
char V_155 [ V_156 ] ;
char V_241 [ V_156 ] ;
struct V_141 * V_142 = V_110 -> V_133 ;
struct V_9 * V_9 = V_142 -> V_9 ;
switch ( type ) {
case V_242 :
if ( F_88 ( V_9 ) == V_131 ) {
F_211 ( L_73 ) ;
break;
}
if ( ! ( V_234 & V_243 ) && ! F_213 ( V_110 ) )
( void ) F_87 ( V_9 ) ;
V_15 = F_214 ( V_9 -> V_103 , & V_235 ) ;
if ( V_15 ) {
F_115 ( L_74 ,
F_64 ( V_9 -> V_34 ) , V_15 ) ;
goto V_65;
}
V_15 = F_95 ( V_9 -> V_103 , & V_237 ) ;
if ( V_15 ) {
F_115 ( L_75 ,
F_64 ( V_9 -> V_34 ) , V_15 ) ;
goto V_65;
}
V_15 = F_188 ( V_9 -> V_103 , & V_239 ) ;
if ( V_15 ) {
F_115 ( L_76 ,
F_64 ( V_9 -> V_34 ) , V_15 ) ;
goto V_65;
}
V_15 = F_91 ( V_9 -> V_103 , & V_236 ) ;
if ( V_15 ) {
F_115 ( L_77 ,
F_64 ( V_9 -> V_34 ) , V_15 ) ;
goto V_65;
}
V_15 = F_185 ( V_9 -> V_103 , & V_238 ) ;
if ( V_15 ) {
F_115 ( L_78 ,
F_64 ( V_9 -> V_34 ) , V_15 ) ;
goto V_65;
}
V_15 = F_215 ( V_9 -> V_103 , & V_240 ) ;
if ( V_15 ) {
F_115 ( L_79 ,
F_64 ( V_9 -> V_34 ) , V_15 ) ;
goto V_65;
}
F_211 ( L_80 ,
( unsigned long long ) V_235 ,
( unsigned long long ) ( V_239 - V_237 ) ,
( unsigned long long ) V_239 ,
( unsigned long long ) ( V_238 - V_236 ) ,
( unsigned long long ) V_238 ) ;
if ( V_240 )
F_211 ( L_81 , V_240 ) ;
else
F_211 ( L_82 ) ;
if ( V_9 -> V_99 . V_130 == V_74 )
F_211 ( L_83 ) ;
else
F_211 ( L_84 ) ;
if ( ! V_9 -> V_99 . V_163 )
F_211 ( L_33 ) ;
else if ( V_9 -> V_99 . V_116 )
F_211 ( L_85 ) ;
else
F_211 ( L_34 ) ;
break;
case V_244 :
F_211 ( L_86 ,
F_216 ( V_155 , V_142 -> V_164 -> V_48 -> V_245 ) ,
F_216 ( V_241 , V_142 -> V_146 -> V_48 -> V_245 ) ,
( unsigned long ) V_9 -> V_45 ,
( unsigned long long ) V_142 -> V_108 ) ;
F_210 ( & V_142 -> V_210 , V_104 , V_232 , V_233 ) ;
break;
}
return;
V_65:
F_211 ( L_87 ) ;
}
static int F_217 ( struct V_132 * V_110 ,
T_10 V_79 , void * V_246 )
{
struct V_141 * V_142 = V_110 -> V_133 ;
return V_79 ( V_110 , V_142 -> V_146 , 0 , V_110 -> V_218 , V_246 ) ;
}
static int F_218 ( struct V_132 * V_110 , struct V_247 * V_248 ,
struct V_249 * V_250 , int V_251 )
{
struct V_141 * V_142 = V_110 -> V_133 ;
struct V_144 * V_145 = F_124 ( V_142 -> V_146 -> V_48 ) ;
if ( ! V_145 -> V_252 )
return V_251 ;
V_248 -> V_46 = V_142 -> V_146 -> V_48 ;
return F_173 ( V_251 , V_145 -> V_252 ( V_145 , V_248 , V_250 ) ) ;
}
static void F_219 ( struct V_141 * V_142 , struct V_151 * V_153 )
{
struct V_9 * V_9 = V_142 -> V_9 ;
struct V_151 * V_152 ;
V_153 -> V_158 = V_9 -> V_45 ;
if ( V_142 -> V_157 . V_116 ) {
V_152 = & F_124 ( V_142 -> V_146 -> V_48 ) -> V_153 ;
V_153 -> V_159 = V_152 -> V_159 ;
} else
V_153 -> V_159 = V_9 -> V_45 << V_82 ;
}
static void F_220 ( struct V_132 * V_110 , struct V_151 * V_153 )
{
struct V_141 * V_142 = V_110 -> V_133 ;
struct V_9 * V_9 = V_142 -> V_9 ;
T_9 V_253 = V_153 -> V_254 >> V_82 ;
if ( V_253 < V_9 -> V_45 ||
F_221 ( V_253 , V_9 -> V_45 ) ) {
F_222 ( V_153 , 0 ) ;
F_223 ( V_153 , V_9 -> V_45 << V_82 ) ;
}
if ( ! V_142 -> V_157 . V_163 ) {
V_153 -> V_159 = 0 ;
return;
}
F_130 ( V_142 ) ;
F_219 ( V_142 , V_153 ) ;
}
static void F_224 ( struct V_132 * V_110 )
{
struct V_22 * V_23 = V_110 -> V_133 ;
F_162 ( & V_27 . V_28 ) ;
F_159 ( V_23 -> V_9 ) ;
F_225 ( V_23 -> V_2 ) ;
F_163 ( V_110 , V_23 -> V_47 ) ;
if ( V_23 -> V_49 )
F_163 ( V_110 , V_23 -> V_49 ) ;
F_142 ( V_23 ) ;
F_164 ( & V_27 . V_28 ) ;
}
static int F_226 ( struct V_132 * V_110 , unsigned V_188 , char * * V_199 )
{
int V_15 ;
struct V_22 * V_23 ;
struct V_88 * V_47 , * V_49 ;
struct V_31 * V_34 ;
F_162 ( & V_27 . V_28 ) ;
if ( V_188 != 2 && V_188 != 3 ) {
V_110 -> error = L_39 ;
V_15 = - V_102 ;
goto V_202;
}
V_23 = V_110 -> V_133 = F_179 ( sizeof( * V_23 ) , V_169 ) ;
if ( ! V_23 ) {
V_110 -> error = L_88 ;
V_15 = - V_87 ;
goto V_202;
}
if ( V_188 == 3 ) {
V_15 = F_176 ( V_110 , V_199 [ 2 ] , V_203 , & V_49 ) ;
if ( V_15 ) {
V_110 -> error = L_89 ;
goto V_255;
}
V_23 -> V_49 = V_49 ;
}
V_15 = F_176 ( V_110 , V_199 [ 0 ] , F_227 ( V_110 -> V_111 ) , & V_47 ) ;
if ( V_15 ) {
V_110 -> error = L_90 ;
goto V_256;
}
V_23 -> V_47 = V_47 ;
if ( F_196 ( V_199 [ 1 ] , ( unsigned long long * ) & V_23 -> V_226 , 0 ) ) {
V_110 -> error = L_91 ;
V_15 = - V_102 ;
goto V_257;
}
V_34 = F_228 ( V_23 -> V_47 -> V_48 -> V_245 ) ;
if ( ! V_34 ) {
V_110 -> error = L_92 ;
V_15 = - V_102 ;
goto V_257;
}
V_23 -> V_9 = F_28 ( V_34 ) ;
if ( ! V_23 -> V_9 ) {
V_110 -> error = L_93 ;
V_15 = - V_102 ;
goto V_258;
}
F_158 ( V_23 -> V_9 ) ;
if ( F_88 ( V_23 -> V_9 ) == V_131 ) {
V_110 -> error = L_94 ;
goto V_259;
}
V_15 = F_229 ( V_23 -> V_9 -> V_103 , V_23 -> V_226 , & V_23 -> V_2 ) ;
if ( V_15 ) {
V_110 -> error = L_95 ;
goto V_259;
}
V_15 = F_230 ( V_110 , V_23 -> V_9 -> V_45 ) ;
if ( V_15 )
goto V_259;
V_110 -> V_211 = 1 ;
V_110 -> V_260 = true ;
V_110 -> V_261 = sizeof( struct V_38 ) ;
V_110 -> V_212 = true ;
if ( V_23 -> V_9 -> V_99 . V_163 ) {
V_110 -> V_214 = true ;
V_110 -> V_213 = 1 ;
V_110 -> V_262 = true ;
}
F_231 ( V_34 ) ;
F_164 ( & V_27 . V_28 ) ;
return 0 ;
V_259:
F_159 ( V_23 -> V_9 ) ;
V_258:
F_231 ( V_34 ) ;
V_257:
F_163 ( V_110 , V_23 -> V_47 ) ;
V_256:
if ( V_23 -> V_49 )
F_163 ( V_110 , V_23 -> V_49 ) ;
V_255:
F_142 ( V_23 ) ;
V_202:
F_164 ( & V_27 . V_28 ) ;
return V_15 ;
}
static int F_232 ( struct V_132 * V_110 , struct V_12 * V_12 )
{
V_12 -> V_44 = F_233 ( V_110 , V_12 -> V_44 ) ;
return F_121 ( V_110 , V_12 ) ;
}
static int F_234 ( struct V_132 * V_110 , struct V_12 * V_12 , int V_65 )
{
unsigned long V_24 ;
struct V_38 * V_39 = F_35 ( V_12 , sizeof( struct V_38 ) ) ;
struct V_77 V_223 ;
struct V_57 * V_58 , * V_33 ;
struct V_9 * V_9 = V_39 -> V_23 -> V_9 ;
if ( V_39 -> V_120 ) {
F_21 ( & V_223 ) ;
F_235 ( V_39 -> V_120 , & V_223 ) ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_72 (m, tmp, &work, list) {
F_27 ( & V_58 -> V_30 ) ;
V_58 -> V_59 = 1 ;
F_54 ( V_58 ) ;
}
F_16 ( & V_9 -> V_25 , V_24 ) ;
}
if ( V_39 -> V_54 ) {
F_21 ( & V_223 ) ;
F_235 ( V_39 -> V_54 , & V_223 ) ;
if ( ! F_236 ( & V_223 ) ) {
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_72 (m, tmp, &work, list)
F_25 ( & V_58 -> V_30 , & V_9 -> V_117 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_4 ( V_9 ) ;
}
}
return 0 ;
}
static void F_237 ( struct V_132 * V_110 )
{
if ( F_238 ( V_110 ) )
F_38 ( (struct V_22 * ) V_110 -> V_133 ) ;
}
static void F_239 ( struct V_132 * V_110 , T_8 type ,
unsigned V_234 , char * V_104 , unsigned V_233 )
{
int V_15 ;
T_11 V_232 = 0 ;
T_1 V_263 , V_264 ;
char V_155 [ V_156 ] ;
struct V_22 * V_23 = V_110 -> V_133 ;
if ( F_88 ( V_23 -> V_9 ) == V_131 ) {
F_211 ( L_73 ) ;
return;
}
if ( ! V_23 -> V_2 )
F_211 ( L_96 ) ;
else {
switch ( type ) {
case V_242 :
V_15 = F_240 ( V_23 -> V_2 , & V_263 ) ;
if ( V_15 ) {
F_115 ( L_97 , V_15 ) ;
goto V_65;
}
V_15 = F_241 ( V_23 -> V_2 , & V_264 ) ;
if ( V_15 < 0 ) {
F_115 ( L_98 , V_15 ) ;
goto V_65;
}
F_211 ( L_81 , V_263 * V_23 -> V_9 -> V_45 ) ;
if ( V_15 )
F_211 ( L_99 , ( ( V_264 + 1 ) *
V_23 -> V_9 -> V_45 ) - 1 ) ;
else
F_211 ( L_96 ) ;
break;
case V_244 :
F_211 ( L_100 ,
F_216 ( V_155 , V_23 -> V_47 -> V_48 -> V_245 ) ,
( unsigned long ) V_23 -> V_226 ) ;
if ( V_23 -> V_49 )
F_211 ( L_101 , F_216 ( V_155 , V_23 -> V_49 -> V_48 -> V_245 ) ) ;
break;
}
}
return;
V_65:
F_211 ( L_87 ) ;
}
static int F_242 ( struct V_132 * V_110 ,
T_10 V_79 , void * V_246 )
{
T_2 V_265 ;
struct V_22 * V_23 = V_110 -> V_133 ;
struct V_9 * V_9 = V_23 -> V_9 ;
if ( ! V_9 -> V_110 )
return 0 ;
V_265 = V_9 -> V_110 -> V_218 ;
( void ) F_41 ( V_265 , V_9 -> V_45 ) ;
if ( V_265 )
return V_79 ( V_110 , V_23 -> V_47 , 0 , V_9 -> V_45 * V_265 , V_246 ) ;
return 0 ;
}
static int T_12 F_243 ( void )
{
int V_15 ;
F_19 () ;
V_15 = F_244 ( & V_266 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_244 ( & V_267 ) ;
if ( V_15 )
goto V_268;
V_15 = - V_87 ;
V_181 = F_245 ( V_57 , 0 ) ;
if ( ! V_181 )
goto V_269;
return 0 ;
V_269:
F_246 ( & V_267 ) ;
V_268:
F_246 ( & V_266 ) ;
return V_15 ;
}
static void F_247 ( void )
{
F_246 ( & V_266 ) ;
F_246 ( & V_267 ) ;
F_248 ( V_181 ) ;
}
