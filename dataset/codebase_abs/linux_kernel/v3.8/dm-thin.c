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
static void F_4 ( void )
{
F_5 ( & V_9 . V_10 ) ;
F_6 ( & V_9 . V_11 ) ;
}
static void F_7 ( struct V_12 * V_12 )
{
F_8 ( ! F_9 ( & V_9 . V_10 ) ) ;
F_10 ( & V_12 -> V_13 , & V_9 . V_11 ) ;
}
static void F_11 ( struct V_12 * V_12 )
{
F_8 ( ! F_9 ( & V_9 . V_10 ) ) ;
F_12 ( & V_12 -> V_13 ) ;
}
static struct V_12 * F_13 ( struct V_14 * V_15 )
{
struct V_12 * V_12 = NULL , * V_16 ;
F_8 ( ! F_9 ( & V_9 . V_10 ) ) ;
F_14 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_16 -> V_17 == V_15 ) {
V_12 = V_16 ;
break;
}
}
return V_12 ;
}
static struct V_12 * F_15 ( struct V_18 * V_19 )
{
struct V_12 * V_12 = NULL , * V_16 ;
F_8 ( ! F_9 ( & V_9 . V_10 ) ) ;
F_14 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_16 -> V_19 == V_19 ) {
V_12 = V_16 ;
break;
}
}
return V_12 ;
}
static void F_16 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
struct V_24 * V_24 ;
struct V_22 V_25 ;
F_17 ( & V_25 ) ;
F_18 ( & V_25 , V_23 ) ;
F_17 ( V_23 ) ;
while ( ( V_24 = F_19 ( & V_25 ) ) ) {
struct V_26 * V_27 = F_20 ( V_24 , sizeof( struct V_26 ) ) ;
if ( V_27 -> V_21 == V_21 )
F_21 ( V_24 , V_28 ) ;
else
F_22 ( V_23 , V_24 ) ;
}
}
static void F_23 ( struct V_20 * V_21 )
{
struct V_12 * V_12 = V_21 -> V_12 ;
unsigned long V_29 ;
F_24 ( & V_12 -> V_30 , V_29 ) ;
F_16 ( V_21 , & V_12 -> V_31 ) ;
F_16 ( V_21 , & V_12 -> V_32 ) ;
F_25 ( & V_12 -> V_30 , V_29 ) ;
}
static T_1 F_26 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
T_2 V_33 = V_24 -> V_34 ;
if ( V_21 -> V_12 -> V_35 < 0 )
( void ) F_27 ( V_33 , V_21 -> V_12 -> V_36 ) ;
else
V_33 >>= V_21 -> V_12 -> V_35 ;
return V_33 ;
}
static void F_28 ( struct V_20 * V_21 , struct V_24 * V_24 , T_1 V_8 )
{
struct V_12 * V_12 = V_21 -> V_12 ;
T_2 V_34 = V_24 -> V_34 ;
V_24 -> V_37 = V_21 -> V_38 -> V_39 ;
if ( V_21 -> V_12 -> V_35 < 0 )
V_24 -> V_34 = ( V_8 * V_12 -> V_36 ) +
F_27 ( V_34 , V_12 -> V_36 ) ;
else
V_24 -> V_34 = ( V_8 << V_12 -> V_35 ) |
( V_34 & ( V_12 -> V_36 - 1 ) ) ;
}
static void F_29 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
V_24 -> V_37 = V_21 -> V_40 -> V_39 ;
}
static int F_30 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
return ( V_24 -> V_41 & ( V_42 | V_43 ) ) &&
F_31 ( V_21 -> V_2 ) ;
}
static void F_32 ( struct V_12 * V_12 , struct V_24 * V_24 )
{
struct V_26 * V_27 ;
if ( V_24 -> V_41 & V_44 )
return;
V_27 = F_20 ( V_24 , sizeof( struct V_26 ) ) ;
V_27 -> V_45 = F_33 ( V_12 -> V_46 ) ;
}
static void F_34 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
struct V_12 * V_12 = V_21 -> V_12 ;
unsigned long V_29 ;
if ( ! F_30 ( V_21 , V_24 ) ) {
F_35 ( V_24 ) ;
return;
}
if ( F_36 ( V_21 -> V_2 ) ) {
F_37 ( V_24 ) ;
return;
}
F_24 ( & V_12 -> V_30 , V_29 ) ;
F_22 ( & V_12 -> V_47 , V_24 ) ;
F_25 ( & V_12 -> V_30 , V_29 ) ;
}
static void F_38 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
F_29 ( V_21 , V_24 ) ;
F_34 ( V_21 , V_24 ) ;
}
static void F_39 ( struct V_20 * V_21 , struct V_24 * V_24 ,
T_1 V_8 )
{
F_28 ( V_21 , V_24 , V_8 ) ;
F_34 ( V_21 , V_24 ) ;
}
static void F_40 ( struct V_12 * V_12 )
{
F_41 ( V_12 -> V_48 , & V_12 -> V_49 ) ;
}
static void F_42 ( struct V_50 * V_51 )
{
struct V_12 * V_12 = V_51 -> V_21 -> V_12 ;
if ( V_51 -> V_52 && V_51 -> V_53 ) {
F_10 ( & V_51 -> V_13 , & V_12 -> V_54 ) ;
F_40 ( V_12 ) ;
}
}
static void F_43 ( int V_55 , unsigned long V_56 , void * V_57 )
{
unsigned long V_29 ;
struct V_50 * V_51 = V_57 ;
struct V_12 * V_12 = V_51 -> V_21 -> V_12 ;
V_51 -> V_58 = V_55 || V_56 ? - V_59 : 0 ;
F_24 ( & V_12 -> V_30 , V_29 ) ;
V_51 -> V_53 = 1 ;
F_42 ( V_51 ) ;
F_25 ( & V_12 -> V_30 , V_29 ) ;
}
static void F_44 ( struct V_24 * V_24 , int V_58 )
{
unsigned long V_29 ;
struct V_26 * V_27 = F_20 ( V_24 , sizeof( struct V_26 ) ) ;
struct V_50 * V_51 = V_27 -> V_60 ;
struct V_12 * V_12 = V_51 -> V_21 -> V_12 ;
V_51 -> V_58 = V_58 ;
F_24 ( & V_12 -> V_30 , V_29 ) ;
V_51 -> V_53 = 1 ;
F_42 ( V_51 ) ;
F_25 ( & V_12 -> V_30 , V_29 ) ;
}
static void F_45 ( struct V_20 * V_21 , struct V_61 * V_62 )
{
struct V_12 * V_12 = V_21 -> V_12 ;
unsigned long V_29 ;
F_24 ( & V_12 -> V_30 , V_29 ) ;
F_46 ( V_62 , & V_12 -> V_31 ) ;
F_25 ( & V_21 -> V_12 -> V_30 , V_29 ) ;
F_40 ( V_12 ) ;
}
static void F_47 ( struct V_20 * V_21 , struct V_61 * V_62 )
{
struct V_12 * V_12 = V_21 -> V_12 ;
unsigned long V_29 ;
F_24 ( & V_12 -> V_30 , V_29 ) ;
F_48 ( V_62 , & V_12 -> V_31 ) ;
F_25 ( & V_12 -> V_30 , V_29 ) ;
F_40 ( V_12 ) ;
}
static void F_49 ( struct V_50 * V_51 )
{
if ( V_51 -> V_24 )
V_51 -> V_24 -> V_63 = V_51 -> V_64 ;
F_50 ( V_51 -> V_62 ) ;
F_12 ( & V_51 -> V_13 ) ;
F_51 ( V_51 , V_51 -> V_21 -> V_12 -> V_65 ) ;
}
static void F_52 ( struct V_50 * V_51 )
{
struct V_20 * V_21 = V_51 -> V_21 ;
struct V_24 * V_24 ;
int V_66 ;
V_24 = V_51 -> V_24 ;
if ( V_24 )
V_24 -> V_63 = V_51 -> V_64 ;
if ( V_51 -> V_58 ) {
F_50 ( V_51 -> V_62 ) ;
goto V_67;
}
V_66 = F_53 ( V_21 -> V_2 , V_51 -> V_68 , V_51 -> V_69 ) ;
if ( V_66 ) {
F_54 ( L_1 ) ;
F_50 ( V_51 -> V_62 ) ;
goto V_67;
}
if ( V_24 ) {
F_47 ( V_21 , V_51 -> V_62 ) ;
F_21 ( V_24 , 0 ) ;
} else
F_45 ( V_21 , V_51 -> V_62 ) ;
V_67:
F_12 ( & V_51 -> V_13 ) ;
F_51 ( V_51 , V_21 -> V_12 -> V_65 ) ;
}
static void F_55 ( struct V_50 * V_51 )
{
struct V_20 * V_21 = V_51 -> V_21 ;
F_37 ( V_51 -> V_24 ) ;
F_47 ( V_21 , V_51 -> V_62 ) ;
F_47 ( V_21 , V_51 -> V_70 ) ;
F_51 ( V_51 , V_21 -> V_12 -> V_65 ) ;
}
static void F_56 ( struct V_50 * V_51 )
{
struct V_20 * V_21 = V_51 -> V_21 ;
F_32 ( V_21 -> V_12 , V_51 -> V_24 ) ;
F_47 ( V_21 , V_51 -> V_62 ) ;
F_47 ( V_21 , V_51 -> V_70 ) ;
if ( V_51 -> V_71 )
F_39 ( V_21 , V_51 -> V_24 , V_51 -> V_69 ) ;
else
F_21 ( V_51 -> V_24 , 0 ) ;
F_51 ( V_51 , V_21 -> V_12 -> V_65 ) ;
}
static void F_57 ( struct V_50 * V_51 )
{
int V_66 ;
struct V_20 * V_21 = V_51 -> V_21 ;
V_66 = F_58 ( V_21 -> V_2 , V_51 -> V_68 ) ;
if ( V_66 )
F_54 ( L_2 ) ;
F_56 ( V_51 ) ;
}
static void F_59 ( struct V_12 * V_12 , struct V_72 * V_73 ,
T_3 * V_74 )
{
unsigned long V_29 ;
struct V_72 V_75 ;
struct V_50 * V_51 , * V_16 ;
F_6 ( & V_75 ) ;
F_24 ( & V_12 -> V_30 , V_29 ) ;
F_60 ( V_73 , & V_75 ) ;
F_25 ( & V_12 -> V_30 , V_29 ) ;
F_61 ( V_51 , V_16 , & V_75 , V_13 )
( * V_74 ) ( V_51 ) ;
}
static int F_62 ( struct V_12 * V_12 , struct V_24 * V_24 )
{
return V_24 -> V_76 == ( V_12 -> V_36 << V_77 ) ;
}
static int F_63 ( struct V_12 * V_12 , struct V_24 * V_24 )
{
return ( F_64 ( V_24 ) == V_78 ) &&
F_62 ( V_12 , V_24 ) ;
}
static void F_65 ( struct V_24 * V_24 , T_4 * * V_79 ,
T_4 * V_74 )
{
* V_79 = V_24 -> V_63 ;
V_24 -> V_63 = V_74 ;
}
static int F_66 ( struct V_12 * V_12 )
{
if ( V_12 -> V_80 )
return 0 ;
V_12 -> V_80 = F_67 ( V_12 -> V_65 , V_81 ) ;
return V_12 -> V_80 ? 0 : - V_82 ;
}
static struct V_50 * F_68 ( struct V_12 * V_12 )
{
struct V_50 * V_66 = V_12 -> V_80 ;
F_8 ( ! V_12 -> V_80 ) ;
V_12 -> V_80 = NULL ;
return V_66 ;
}
static void F_69 ( struct V_20 * V_21 , T_1 V_68 ,
struct V_83 * V_84 , T_1 V_85 ,
T_1 V_86 ,
struct V_61 * V_62 , struct V_24 * V_24 )
{
int V_66 ;
struct V_12 * V_12 = V_21 -> V_12 ;
struct V_50 * V_51 = F_68 ( V_12 ) ;
F_6 ( & V_51 -> V_13 ) ;
V_51 -> V_52 = 0 ;
V_51 -> V_53 = 0 ;
V_51 -> V_21 = V_21 ;
V_51 -> V_68 = V_68 ;
V_51 -> V_69 = V_86 ;
V_51 -> V_62 = V_62 ;
V_51 -> V_58 = 0 ;
V_51 -> V_24 = NULL ;
if ( ! F_70 ( V_12 -> V_87 , & V_51 -> V_13 ) )
V_51 -> V_52 = 1 ;
if ( F_63 ( V_12 , V_24 ) ) {
struct V_26 * V_27 = F_20 ( V_24 , sizeof( struct V_26 ) ) ;
V_27 -> V_60 = V_51 ;
V_51 -> V_24 = V_24 ;
F_65 ( V_24 , & V_51 -> V_64 , F_44 ) ;
F_32 ( V_12 , V_24 ) ;
F_39 ( V_21 , V_24 , V_86 ) ;
} else {
struct V_88 V_89 , V_90 ;
V_89 . V_39 = V_84 -> V_39 ;
V_89 . V_91 = V_85 * V_12 -> V_36 ;
V_89 . V_92 = V_12 -> V_36 ;
V_90 . V_39 = V_21 -> V_38 -> V_39 ;
V_90 . V_91 = V_86 * V_12 -> V_36 ;
V_90 . V_92 = V_12 -> V_36 ;
V_66 = F_71 ( V_12 -> V_93 , & V_89 , 1 , & V_90 ,
0 , F_43 , V_51 ) ;
if ( V_66 < 0 ) {
F_51 ( V_51 , V_12 -> V_65 ) ;
F_54 ( L_3 ) ;
F_50 ( V_62 ) ;
}
}
}
static void F_72 ( struct V_20 * V_21 , T_1 V_68 ,
T_1 V_85 , T_1 V_86 ,
struct V_61 * V_62 , struct V_24 * V_24 )
{
F_69 ( V_21 , V_68 , V_21 -> V_38 ,
V_85 , V_86 , V_62 , V_24 ) ;
}
static void F_73 ( struct V_20 * V_21 , T_1 V_68 ,
T_1 V_86 ,
struct V_61 * V_62 , struct V_24 * V_24 )
{
F_69 ( V_21 , V_68 , V_21 -> V_40 ,
V_68 , V_86 , V_62 , V_24 ) ;
}
static void F_74 ( struct V_20 * V_21 , T_1 V_68 ,
T_1 V_69 , struct V_61 * V_62 ,
struct V_24 * V_24 )
{
struct V_12 * V_12 = V_21 -> V_12 ;
struct V_50 * V_51 = F_68 ( V_12 ) ;
F_6 ( & V_51 -> V_13 ) ;
V_51 -> V_52 = 1 ;
V_51 -> V_53 = 0 ;
V_51 -> V_21 = V_21 ;
V_51 -> V_68 = V_68 ;
V_51 -> V_69 = V_69 ;
V_51 -> V_62 = V_62 ;
V_51 -> V_58 = 0 ;
V_51 -> V_24 = NULL ;
if ( ! V_12 -> V_94 . V_95 )
F_52 ( V_51 ) ;
else if ( F_63 ( V_12 , V_24 ) ) {
struct V_26 * V_27 = F_20 ( V_24 , sizeof( struct V_26 ) ) ;
V_27 -> V_60 = V_51 ;
V_51 -> V_24 = V_24 ;
F_65 ( V_24 , & V_51 -> V_64 , F_44 ) ;
F_32 ( V_12 , V_24 ) ;
F_39 ( V_21 , V_24 , V_69 ) ;
} else {
int V_66 ;
struct V_88 V_90 ;
V_90 . V_39 = V_21 -> V_38 -> V_39 ;
V_90 . V_91 = V_69 * V_12 -> V_36 ;
V_90 . V_92 = V_12 -> V_36 ;
V_66 = F_75 ( V_12 -> V_93 , 1 , & V_90 , 0 , F_43 , V_51 ) ;
if ( V_66 < 0 ) {
F_51 ( V_51 , V_12 -> V_65 ) ;
F_54 ( L_4 ) ;
F_50 ( V_62 ) ;
}
}
}
static int F_76 ( struct V_12 * V_12 )
{
int V_66 ;
V_66 = F_77 ( V_12 -> V_96 ) ;
if ( V_66 )
F_54 ( L_5 , V_66 ) ;
return V_66 ;
}
static int F_78 ( struct V_12 * V_12 )
{
int V_66 ;
if ( F_79 ( V_12 ) != V_97 )
return - V_98 ;
V_66 = F_76 ( V_12 ) ;
if ( V_66 )
F_80 ( V_12 , V_99 ) ;
return V_66 ;
}
static int F_81 ( struct V_20 * V_21 , T_1 * V_100 )
{
int V_66 ;
T_1 V_101 ;
unsigned long V_29 ;
struct V_12 * V_12 = V_21 -> V_12 ;
V_66 = F_82 ( V_12 -> V_96 , & V_101 ) ;
if ( V_66 )
return V_66 ;
if ( V_101 <= V_12 -> V_102 && ! V_12 -> V_103 ) {
F_83 ( L_6 ,
F_84 ( V_12 -> V_17 ) ) ;
F_24 ( & V_12 -> V_30 , V_29 ) ;
V_12 -> V_103 = 1 ;
F_25 ( & V_12 -> V_30 , V_29 ) ;
F_85 ( V_12 -> V_104 -> V_105 ) ;
}
if ( ! V_101 ) {
if ( V_12 -> V_106 )
return - V_107 ;
else {
( void ) F_78 ( V_12 ) ;
V_66 = F_82 ( V_12 -> V_96 , & V_101 ) ;
if ( V_66 )
return V_66 ;
if ( ! V_101 ) {
F_83 ( L_7 ,
F_84 ( V_12 -> V_17 ) ) ;
F_24 ( & V_12 -> V_30 , V_29 ) ;
V_12 -> V_106 = 1 ;
F_25 ( & V_12 -> V_30 , V_29 ) ;
return - V_107 ;
}
}
}
V_66 = F_86 ( V_12 -> V_96 , V_100 ) ;
if ( V_66 )
return V_66 ;
return 0 ;
}
static void F_87 ( struct V_24 * V_24 )
{
struct V_26 * V_27 = F_20 ( V_24 , sizeof( struct V_26 ) ) ;
struct V_20 * V_21 = V_27 -> V_21 ;
struct V_12 * V_12 = V_21 -> V_12 ;
unsigned long V_29 ;
F_24 ( & V_12 -> V_30 , V_29 ) ;
F_22 ( & V_12 -> V_32 , V_24 ) ;
F_25 ( & V_12 -> V_30 , V_29 ) ;
}
static void F_88 ( struct V_61 * V_62 )
{
struct V_24 * V_24 ;
struct V_22 V_25 ;
F_17 ( & V_25 ) ;
F_46 ( V_62 , & V_25 ) ;
while ( ( V_24 = F_19 ( & V_25 ) ) )
F_87 ( V_24 ) ;
}
static void F_89 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
int V_66 ;
unsigned long V_29 ;
struct V_12 * V_12 = V_21 -> V_12 ;
struct V_61 * V_62 , * V_70 ;
struct V_4 V_5 , V_108 ;
T_1 V_8 = F_26 ( V_21 , V_24 ) ;
struct V_109 V_110 ;
struct V_50 * V_51 ;
F_3 ( V_21 -> V_2 , V_8 , & V_5 ) ;
if ( F_90 ( V_21 -> V_12 -> V_111 , & V_5 , V_24 , & V_62 ) )
return;
V_66 = F_91 ( V_21 -> V_2 , V_8 , 1 , & V_110 ) ;
switch ( V_66 ) {
case 0 :
F_1 ( V_21 -> V_2 , V_110 . V_8 , & V_108 ) ;
if ( F_90 ( V_21 -> V_12 -> V_111 , & V_108 , V_24 , & V_70 ) ) {
F_47 ( V_21 , V_62 ) ;
break;
}
if ( F_62 ( V_12 , V_24 ) ) {
V_51 = F_68 ( V_12 ) ;
V_51 -> V_21 = V_21 ;
V_51 -> V_71 = ( ! V_110 . V_112 ) && V_12 -> V_94 . V_113 ;
V_51 -> V_68 = V_8 ;
V_51 -> V_69 = V_110 . V_8 ;
V_51 -> V_62 = V_62 ;
V_51 -> V_70 = V_70 ;
V_51 -> V_58 = 0 ;
V_51 -> V_24 = V_24 ;
if ( ! F_70 ( V_12 -> V_46 , & V_51 -> V_13 ) ) {
F_24 ( & V_12 -> V_30 , V_29 ) ;
F_10 ( & V_51 -> V_13 , & V_12 -> V_114 ) ;
F_25 ( & V_12 -> V_30 , V_29 ) ;
F_40 ( V_12 ) ;
}
} else {
F_32 ( V_12 , V_24 ) ;
F_47 ( V_21 , V_62 ) ;
F_47 ( V_21 , V_70 ) ;
if ( ( ! V_110 . V_112 ) && V_12 -> V_94 . V_113 )
F_39 ( V_21 , V_24 , V_110 . V_8 ) ;
else
F_21 ( V_24 , 0 ) ;
}
break;
case - V_115 :
F_47 ( V_21 , V_62 ) ;
F_21 ( V_24 , 0 ) ;
break;
default:
F_54 ( L_8 ,
V_116 , V_66 ) ;
F_47 ( V_21 , V_62 ) ;
F_37 ( V_24 ) ;
break;
}
}
static void F_92 ( struct V_20 * V_21 , struct V_24 * V_24 , T_1 V_8 ,
struct V_4 * V_5 ,
struct V_109 * V_110 ,
struct V_61 * V_62 )
{
int V_66 ;
T_1 V_69 ;
V_66 = F_81 ( V_21 , & V_69 ) ;
switch ( V_66 ) {
case 0 :
F_72 ( V_21 , V_8 , V_110 -> V_8 ,
V_69 , V_62 , V_24 ) ;
break;
case - V_107 :
F_88 ( V_62 ) ;
break;
default:
F_54 ( L_9 ,
V_116 , V_66 ) ;
F_50 ( V_62 ) ;
break;
}
}
static void F_93 ( struct V_20 * V_21 , struct V_24 * V_24 ,
T_1 V_8 ,
struct V_109 * V_110 )
{
struct V_61 * V_62 ;
struct V_12 * V_12 = V_21 -> V_12 ;
struct V_4 V_5 ;
F_1 ( V_21 -> V_2 , V_110 -> V_8 , & V_5 ) ;
if ( F_90 ( V_12 -> V_111 , & V_5 , V_24 , & V_62 ) )
return;
if ( F_64 ( V_24 ) == V_78 && V_24 -> V_76 )
F_92 ( V_21 , V_24 , V_8 , & V_5 , V_110 , V_62 ) ;
else {
struct V_26 * V_27 = F_20 ( V_24 , sizeof( struct V_26 ) ) ;
V_27 -> V_117 = F_33 ( V_12 -> V_87 ) ;
F_32 ( V_12 , V_24 ) ;
F_47 ( V_21 , V_62 ) ;
F_39 ( V_21 , V_24 , V_110 -> V_8 ) ;
}
}
static void F_94 ( struct V_20 * V_21 , struct V_24 * V_24 , T_1 V_8 ,
struct V_61 * V_62 )
{
int V_66 ;
T_1 V_69 ;
if ( ! V_24 -> V_76 ) {
F_32 ( V_21 -> V_12 , V_24 ) ;
F_47 ( V_21 , V_62 ) ;
F_39 ( V_21 , V_24 , 0 ) ;
return;
}
if ( F_64 ( V_24 ) == V_118 ) {
F_95 ( V_24 ) ;
F_47 ( V_21 , V_62 ) ;
F_21 ( V_24 , 0 ) ;
return;
}
V_66 = F_81 ( V_21 , & V_69 ) ;
switch ( V_66 ) {
case 0 :
if ( V_21 -> V_40 )
F_73 ( V_21 , V_8 , V_69 , V_62 , V_24 ) ;
else
F_74 ( V_21 , V_8 , V_69 , V_62 , V_24 ) ;
break;
case - V_107 :
F_88 ( V_62 ) ;
break;
default:
F_54 ( L_9 ,
V_116 , V_66 ) ;
F_80 ( V_21 -> V_12 , V_99 ) ;
F_50 ( V_62 ) ;
break;
}
}
static void F_96 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
int V_66 ;
T_1 V_8 = F_26 ( V_21 , V_24 ) ;
struct V_61 * V_62 ;
struct V_4 V_5 ;
struct V_109 V_110 ;
F_3 ( V_21 -> V_2 , V_8 , & V_5 ) ;
if ( F_90 ( V_21 -> V_12 -> V_111 , & V_5 , V_24 , & V_62 ) )
return;
V_66 = F_91 ( V_21 -> V_2 , V_8 , 1 , & V_110 ) ;
switch ( V_66 ) {
case 0 :
if ( V_110 . V_112 ) {
F_93 ( V_21 , V_24 , V_8 , & V_110 ) ;
F_47 ( V_21 , V_62 ) ;
} else {
F_32 ( V_21 -> V_12 , V_24 ) ;
F_47 ( V_21 , V_62 ) ;
F_39 ( V_21 , V_24 , V_110 . V_8 ) ;
}
break;
case - V_115 :
if ( F_64 ( V_24 ) == V_118 && V_21 -> V_40 ) {
F_32 ( V_21 -> V_12 , V_24 ) ;
F_47 ( V_21 , V_62 ) ;
F_38 ( V_21 , V_24 ) ;
} else
F_94 ( V_21 , V_24 , V_8 , V_62 ) ;
break;
default:
F_54 ( L_8 ,
V_116 , V_66 ) ;
F_47 ( V_21 , V_62 ) ;
F_37 ( V_24 ) ;
break;
}
}
static void F_97 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
int V_66 ;
int V_119 = F_64 ( V_24 ) ;
T_1 V_8 = F_26 ( V_21 , V_24 ) ;
struct V_109 V_110 ;
V_66 = F_91 ( V_21 -> V_2 , V_8 , 1 , & V_110 ) ;
switch ( V_66 ) {
case 0 :
if ( V_110 . V_112 && ( V_119 == V_78 ) && V_24 -> V_76 )
F_37 ( V_24 ) ;
else {
F_32 ( V_21 -> V_12 , V_24 ) ;
F_39 ( V_21 , V_24 , V_110 . V_8 ) ;
}
break;
case - V_115 :
if ( V_119 != V_118 ) {
F_37 ( V_24 ) ;
break;
}
if ( V_21 -> V_40 ) {
F_32 ( V_21 -> V_12 , V_24 ) ;
F_38 ( V_21 , V_24 ) ;
break;
}
F_95 ( V_24 ) ;
F_21 ( V_24 , 0 ) ;
break;
default:
F_54 ( L_8 ,
V_116 , V_66 ) ;
F_37 ( V_24 ) ;
break;
}
}
static void F_98 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
F_37 ( V_24 ) ;
}
static int F_99 ( struct V_12 * V_12 )
{
return V_120 < V_12 -> V_121 ||
V_120 > V_12 -> V_121 + V_122 ;
}
static void F_100 ( struct V_12 * V_12 )
{
unsigned long V_29 ;
struct V_24 * V_24 ;
struct V_22 V_25 ;
F_17 ( & V_25 ) ;
F_24 ( & V_12 -> V_30 , V_29 ) ;
F_18 ( & V_25 , & V_12 -> V_31 ) ;
F_17 ( & V_12 -> V_31 ) ;
F_25 ( & V_12 -> V_30 , V_29 ) ;
while ( ( V_24 = F_19 ( & V_25 ) ) ) {
struct V_26 * V_27 = F_20 ( V_24 , sizeof( struct V_26 ) ) ;
struct V_20 * V_21 = V_27 -> V_21 ;
if ( F_66 ( V_12 ) ) {
F_24 ( & V_12 -> V_30 , V_29 ) ;
F_18 ( & V_12 -> V_31 , & V_25 ) ;
F_25 ( & V_12 -> V_30 , V_29 ) ;
break;
}
if ( V_24 -> V_41 & V_44 )
V_12 -> F_89 ( V_21 , V_24 ) ;
else
V_12 -> F_96 ( V_21 , V_24 ) ;
}
F_17 ( & V_25 ) ;
F_24 ( & V_12 -> V_30 , V_29 ) ;
F_18 ( & V_25 , & V_12 -> V_47 ) ;
F_17 ( & V_12 -> V_47 ) ;
F_25 ( & V_12 -> V_30 , V_29 ) ;
if ( F_101 ( & V_25 ) && ! F_99 ( V_12 ) )
return;
if ( F_78 ( V_12 ) ) {
while ( ( V_24 = F_19 ( & V_25 ) ) )
F_37 ( V_24 ) ;
return;
}
V_12 -> V_121 = V_120 ;
while ( ( V_24 = F_19 ( & V_25 ) ) )
F_35 ( V_24 ) ;
}
static void F_102 ( struct V_123 * V_124 )
{
struct V_12 * V_12 = F_103 ( V_124 , struct V_12 , V_49 ) ;
F_59 ( V_12 , & V_12 -> V_54 , & V_12 -> F_52 ) ;
F_59 ( V_12 , & V_12 -> V_114 , & V_12 -> F_57 ) ;
F_100 ( V_12 ) ;
}
static void F_104 ( struct V_123 * V_124 )
{
struct V_12 * V_12 = F_103 ( F_105 ( V_124 ) , struct V_12 , V_125 ) ;
F_40 ( V_12 ) ;
F_106 ( V_12 -> V_48 , & V_12 -> V_125 , V_122 ) ;
}
static enum V_126 F_79 ( struct V_12 * V_12 )
{
return V_12 -> V_94 . V_127 ;
}
static void F_80 ( struct V_12 * V_12 , enum V_126 V_127 )
{
int V_66 ;
V_12 -> V_94 . V_127 = V_127 ;
switch ( V_127 ) {
case V_128 :
F_107 ( L_10 ) ;
V_12 -> F_96 = F_98 ;
V_12 -> F_89 = F_98 ;
V_12 -> F_52 = F_49 ;
V_12 -> F_57 = F_55 ;
break;
case V_99 :
F_107 ( L_11 ) ;
V_66 = F_108 ( V_12 -> V_96 ) ;
if ( V_66 ) {
F_107 ( L_12 ) ;
F_80 ( V_12 , V_128 ) ;
} else {
F_109 ( V_12 -> V_96 ) ;
V_12 -> F_96 = F_97 ;
V_12 -> F_89 = F_89 ;
V_12 -> F_52 = F_49 ;
V_12 -> F_57 = F_56 ;
}
break;
case V_97 :
V_12 -> F_96 = F_96 ;
V_12 -> F_89 = F_89 ;
V_12 -> F_52 = F_52 ;
V_12 -> F_57 = F_57 ;
break;
}
}
static void F_110 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
unsigned long V_29 ;
struct V_12 * V_12 = V_21 -> V_12 ;
F_24 ( & V_12 -> V_30 , V_29 ) ;
F_22 ( & V_12 -> V_31 , V_24 ) ;
F_25 ( & V_12 -> V_30 , V_29 ) ;
F_40 ( V_12 ) ;
}
static void F_111 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
struct V_26 * V_27 = F_20 ( V_24 , sizeof( struct V_26 ) ) ;
V_27 -> V_21 = V_21 ;
V_27 -> V_117 = NULL ;
V_27 -> V_45 = NULL ;
V_27 -> V_60 = NULL ;
}
static int F_112 ( struct V_129 * V_104 , struct V_24 * V_24 )
{
int V_66 ;
struct V_20 * V_21 = V_104 -> V_130 ;
T_1 V_8 = F_26 ( V_21 , V_24 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_109 V_100 ;
struct V_61 * V_131 , * V_70 ;
struct V_4 V_5 ;
F_111 ( V_21 , V_24 ) ;
if ( F_79 ( V_21 -> V_12 ) == V_128 ) {
F_37 ( V_24 ) ;
return V_132 ;
}
if ( V_24 -> V_41 & ( V_44 | V_42 | V_43 ) ) {
F_110 ( V_21 , V_24 ) ;
return V_132 ;
}
V_66 = F_91 ( V_2 , V_8 , 0 , & V_100 ) ;
switch ( V_66 ) {
case 0 :
if ( F_113 ( V_100 . V_112 ) ) {
F_110 ( V_21 , V_24 ) ;
return V_132 ;
}
F_3 ( V_21 -> V_2 , V_8 , & V_5 ) ;
if ( F_90 ( V_21 -> V_12 -> V_111 , & V_5 , V_24 , & V_131 ) )
return V_132 ;
F_1 ( V_21 -> V_2 , V_100 . V_8 , & V_5 ) ;
if ( F_90 ( V_21 -> V_12 -> V_111 , & V_5 , V_24 , & V_70 ) ) {
F_47 ( V_21 , V_131 ) ;
return V_132 ;
}
F_32 ( V_21 -> V_12 , V_24 ) ;
F_47 ( V_21 , V_70 ) ;
F_47 ( V_21 , V_131 ) ;
F_28 ( V_21 , V_24 , V_100 . V_8 ) ;
return V_133 ;
case - V_115 :
if ( F_79 ( V_21 -> V_12 ) == V_99 ) {
F_37 ( V_24 ) ;
return V_132 ;
}
case - V_134 :
F_110 ( V_21 , V_24 ) ;
return V_132 ;
default:
F_37 ( V_24 ) ;
return V_132 ;
}
}
static int F_114 ( struct V_135 * V_136 , int V_137 )
{
int V_66 ;
unsigned long V_29 ;
struct V_138 * V_139 = F_103 ( V_136 , struct V_138 , V_140 ) ;
F_24 ( & V_139 -> V_12 -> V_30 , V_29 ) ;
V_66 = ! F_101 ( & V_139 -> V_12 -> V_32 ) ;
F_25 ( & V_139 -> V_12 -> V_30 , V_29 ) ;
if ( ! V_66 ) {
struct V_141 * V_142 = F_115 ( V_139 -> V_143 -> V_39 ) ;
V_66 = F_116 ( & V_142 -> V_144 , V_137 ) ;
}
return V_66 ;
}
static void F_117 ( struct V_12 * V_12 )
{
F_18 ( & V_12 -> V_31 , & V_12 -> V_32 ) ;
F_17 ( & V_12 -> V_32 ) ;
}
static bool F_118 ( struct V_138 * V_139 )
{
struct V_141 * V_142 = F_115 ( V_139 -> V_143 -> V_39 ) ;
return V_142 && F_119 ( V_142 ) ;
}
static void F_120 ( struct V_138 * V_139 )
{
struct V_12 * V_12 = V_139 -> V_12 ;
struct V_18 * V_145 = V_139 -> V_143 -> V_39 ;
struct V_146 * V_147 = & F_115 ( V_145 ) -> V_148 ;
T_2 V_149 = V_12 -> V_36 << V_77 ;
const char * V_150 = NULL ;
char V_151 [ V_152 ] ;
if ( ! V_139 -> V_153 . V_113 )
return;
if ( ! F_118 ( V_139 ) )
V_150 = L_13 ;
else if ( V_147 -> V_154 < V_12 -> V_36 )
V_150 = L_14 ;
else if ( V_147 -> V_155 > V_149 )
V_150 = L_15 ;
else if ( V_149 & ( V_147 -> V_155 - 1 ) )
V_150 = L_16 ;
if ( V_150 ) {
F_83 ( L_17 , F_121 ( V_145 , V_151 ) , V_150 ) ;
V_139 -> V_153 . V_113 = false ;
}
}
static int F_122 ( struct V_12 * V_12 , struct V_129 * V_104 )
{
struct V_138 * V_139 = V_104 -> V_130 ;
enum V_126 V_156 = V_12 -> V_94 . V_127 ;
enum V_126 V_157 = V_139 -> V_153 . V_127 ;
if ( V_156 > V_157 )
V_157 = V_156 ;
V_12 -> V_104 = V_104 ;
V_12 -> V_102 = V_139 -> V_102 ;
V_12 -> V_94 = V_139 -> V_153 ;
F_80 ( V_12 , V_157 ) ;
return 0 ;
}
static void F_123 ( struct V_12 * V_12 , struct V_129 * V_104 )
{
if ( V_12 -> V_104 == V_104 )
V_12 -> V_104 = NULL ;
}
static void F_124 ( struct V_158 * V_94 )
{
V_94 -> V_127 = V_97 ;
V_94 -> V_95 = true ;
V_94 -> V_159 = true ;
V_94 -> V_113 = true ;
}
static void F_125 ( struct V_12 * V_12 )
{
F_11 ( V_12 ) ;
if ( F_126 ( V_12 -> V_96 ) < 0 )
F_83 ( L_18 , V_116 ) ;
F_127 ( V_12 -> V_111 ) ;
F_128 ( V_12 -> V_93 ) ;
if ( V_12 -> V_48 )
F_129 ( V_12 -> V_48 ) ;
if ( V_12 -> V_80 )
F_51 ( V_12 -> V_80 , V_12 -> V_65 ) ;
F_130 ( V_12 -> V_65 ) ;
F_131 ( V_12 -> V_87 ) ;
F_131 ( V_12 -> V_46 ) ;
F_132 ( V_12 ) ;
}
static struct V_12 * F_133 ( struct V_14 * V_17 ,
struct V_18 * V_160 ,
unsigned long V_149 ,
int V_161 , char * * error )
{
int V_66 ;
void * V_162 ;
struct V_12 * V_12 ;
struct V_163 * V_96 ;
bool V_164 = V_161 ? false : true ;
V_96 = F_134 ( V_160 , V_149 , V_164 ) ;
if ( F_135 ( V_96 ) ) {
* error = L_19 ;
return (struct V_12 * ) V_96 ;
}
V_12 = F_136 ( sizeof( * V_12 ) , V_165 ) ;
if ( ! V_12 ) {
* error = L_20 ;
V_162 = F_137 ( - V_82 ) ;
goto V_166;
}
V_12 -> V_96 = V_96 ;
V_12 -> V_36 = V_149 ;
if ( V_149 & ( V_149 - 1 ) )
V_12 -> V_35 = - 1 ;
else
V_12 -> V_35 = F_138 ( V_149 ) ;
V_12 -> V_102 = 0 ;
F_124 ( & V_12 -> V_94 ) ;
V_12 -> V_111 = F_139 ( V_167 ) ;
if ( ! V_12 -> V_111 ) {
* error = L_21 ;
V_162 = F_137 ( - V_82 ) ;
goto V_168;
}
V_12 -> V_93 = F_140 () ;
if ( F_135 ( V_12 -> V_93 ) ) {
V_66 = F_141 ( V_12 -> V_93 ) ;
* error = L_22 ;
V_162 = F_137 ( V_66 ) ;
goto V_169;
}
V_12 -> V_48 = F_142 ( L_23 V_170 , V_171 ) ;
if ( ! V_12 -> V_48 ) {
* error = L_24 ;
V_162 = F_137 ( - V_82 ) ;
goto V_172;
}
F_143 ( & V_12 -> V_49 , F_102 ) ;
F_144 ( & V_12 -> V_125 , F_104 ) ;
F_145 ( & V_12 -> V_30 ) ;
F_17 ( & V_12 -> V_31 ) ;
F_17 ( & V_12 -> V_47 ) ;
F_6 ( & V_12 -> V_54 ) ;
F_6 ( & V_12 -> V_114 ) ;
V_12 -> V_103 = 0 ;
V_12 -> V_106 = 0 ;
F_17 ( & V_12 -> V_32 ) ;
V_12 -> V_87 = F_146 () ;
if ( ! V_12 -> V_87 ) {
* error = L_25 ;
V_162 = F_137 ( - V_82 ) ;
goto V_173;
}
V_12 -> V_46 = F_146 () ;
if ( ! V_12 -> V_46 ) {
* error = L_26 ;
V_162 = F_137 ( - V_82 ) ;
goto V_174;
}
V_12 -> V_80 = NULL ;
V_12 -> V_65 = F_147 ( V_175 ,
V_176 ) ;
if ( ! V_12 -> V_65 ) {
* error = L_27 ;
V_162 = F_137 ( - V_82 ) ;
goto V_177;
}
V_12 -> V_178 = 1 ;
V_12 -> V_121 = V_120 ;
V_12 -> V_17 = V_17 ;
V_12 -> V_19 = V_160 ;
F_7 ( V_12 ) ;
return V_12 ;
V_177:
F_131 ( V_12 -> V_46 ) ;
V_174:
F_131 ( V_12 -> V_87 ) ;
V_173:
F_129 ( V_12 -> V_48 ) ;
V_172:
F_128 ( V_12 -> V_93 ) ;
V_169:
F_127 ( V_12 -> V_111 ) ;
V_168:
F_132 ( V_12 ) ;
V_166:
if ( F_126 ( V_96 ) )
F_83 ( L_18 , V_116 ) ;
return V_162 ;
}
static void F_148 ( struct V_12 * V_12 )
{
F_8 ( ! F_9 ( & V_9 . V_10 ) ) ;
V_12 -> V_178 ++ ;
}
static void F_149 ( struct V_12 * V_12 )
{
F_8 ( ! F_9 ( & V_9 . V_10 ) ) ;
F_8 ( ! V_12 -> V_178 ) ;
if ( ! -- V_12 -> V_178 )
F_125 ( V_12 ) ;
}
static struct V_12 * F_150 ( struct V_14 * V_17 ,
struct V_18 * V_160 ,
unsigned long V_149 , int V_161 ,
char * * error , int * V_179 )
{
struct V_12 * V_12 = F_15 ( V_160 ) ;
if ( V_12 ) {
if ( V_12 -> V_17 != V_17 ) {
* error = L_28 ;
return F_137 ( - V_180 ) ;
}
F_148 ( V_12 ) ;
} else {
V_12 = F_13 ( V_17 ) ;
if ( V_12 ) {
if ( V_12 -> V_19 != V_160 ) {
* error = L_29 ;
return F_137 ( - V_98 ) ;
}
F_148 ( V_12 ) ;
} else {
V_12 = F_133 ( V_17 , V_160 , V_149 , V_161 , error ) ;
* V_179 = 1 ;
}
}
return V_12 ;
}
static void F_151 ( struct V_129 * V_104 )
{
struct V_138 * V_139 = V_104 -> V_130 ;
F_152 ( & V_9 . V_10 ) ;
F_123 ( V_139 -> V_12 , V_104 ) ;
F_149 ( V_139 -> V_12 ) ;
F_153 ( V_104 , V_139 -> V_160 ) ;
F_153 ( V_104 , V_139 -> V_143 ) ;
F_132 ( V_139 ) ;
F_154 ( & V_9 . V_10 ) ;
}
static int F_155 ( struct V_181 * V_182 , struct V_158 * V_94 ,
struct V_129 * V_104 )
{
int V_66 ;
unsigned V_183 ;
const char * V_184 ;
static struct V_185 V_186 [] = {
{ 0 , 3 , L_30 } ,
} ;
if ( ! V_182 -> V_183 )
return 0 ;
V_66 = F_156 ( V_186 , V_182 , & V_183 , & V_104 -> error ) ;
if ( V_66 )
return - V_98 ;
while ( V_183 && ! V_66 ) {
V_184 = F_157 ( V_182 ) ;
V_183 -- ;
if ( ! strcasecmp ( V_184 , L_31 ) )
V_94 -> V_95 = false ;
else if ( ! strcasecmp ( V_184 , L_32 ) )
V_94 -> V_159 = false ;
else if ( ! strcasecmp ( V_184 , L_33 ) )
V_94 -> V_113 = false ;
else if ( ! strcasecmp ( V_184 , L_34 ) )
V_94 -> V_127 = V_99 ;
else {
V_104 -> error = L_35 ;
V_66 = - V_98 ;
break;
}
}
return V_66 ;
}
static int F_158 ( struct V_129 * V_104 , unsigned V_183 , char * * V_187 )
{
int V_66 , V_188 = 0 ;
struct V_138 * V_139 ;
struct V_12 * V_12 ;
struct V_158 V_94 ;
struct V_181 V_182 ;
struct V_83 * V_143 ;
unsigned long V_149 ;
T_1 V_102 ;
struct V_83 * V_160 ;
T_2 V_189 ;
char V_3 [ V_152 ] ;
F_152 ( & V_9 . V_10 ) ;
if ( V_183 < 4 ) {
V_104 -> error = L_36 ;
V_66 = - V_98 ;
goto V_190;
}
V_182 . V_183 = V_183 ;
V_182 . V_187 = V_187 ;
V_66 = F_159 ( V_104 , V_187 [ 0 ] , V_191 | V_192 , & V_160 ) ;
if ( V_66 ) {
V_104 -> error = L_37 ;
goto V_190;
}
V_189 = F_160 ( V_160 -> V_39 -> V_193 ) >> V_77 ;
if ( V_189 > V_194 )
F_83 ( L_38 ,
F_121 ( V_160 -> V_39 , V_3 ) , V_195 ) ;
V_66 = F_159 ( V_104 , V_187 [ 1 ] , V_191 | V_192 , & V_143 ) ;
if ( V_66 ) {
V_104 -> error = L_39 ;
goto V_196;
}
if ( F_161 ( V_187 [ 2 ] , 10 , & V_149 ) || ! V_149 ||
V_149 < V_197 ||
V_149 > V_198 ||
V_149 & ( V_197 - 1 ) ) {
V_104 -> error = L_40 ;
V_66 = - V_98 ;
goto V_67;
}
if ( F_162 ( V_187 [ 3 ] , 10 , ( unsigned long long * ) & V_102 ) ) {
V_104 -> error = L_41 ;
V_66 = - V_98 ;
goto V_67;
}
F_124 ( & V_94 ) ;
F_163 ( & V_182 , 4 ) ;
V_66 = F_155 ( & V_182 , & V_94 , V_104 ) ;
if ( V_66 )
goto V_67;
V_139 = F_164 ( sizeof( * V_139 ) , V_165 ) ;
if ( ! V_139 ) {
V_66 = - V_82 ;
goto V_67;
}
V_12 = F_150 ( F_165 ( V_104 -> V_105 ) , V_160 -> V_39 ,
V_149 , V_94 . V_127 == V_99 , & V_104 -> error , & V_188 ) ;
if ( F_135 ( V_12 ) ) {
V_66 = F_141 ( V_12 ) ;
goto V_199;
}
if ( ! V_188 && V_94 . V_159 != V_12 -> V_94 . V_159 ) {
V_104 -> error = L_42 ;
V_66 = - V_98 ;
goto V_200;
}
V_139 -> V_12 = V_12 ;
V_139 -> V_104 = V_104 ;
V_139 -> V_160 = V_160 ;
V_139 -> V_143 = V_143 ;
V_139 -> V_102 = V_102 ;
V_139 -> V_153 = V_139 -> V_201 = V_94 ;
V_104 -> V_202 = 1 ;
if ( V_94 . V_159 && V_94 . V_113 ) {
V_104 -> V_203 = 1 ;
V_104 -> V_204 = true ;
V_104 -> V_205 = true ;
}
V_104 -> V_130 = V_139 ;
V_139 -> V_140 . V_206 = F_114 ;
F_166 ( V_104 -> V_105 , & V_139 -> V_140 ) ;
F_154 ( & V_9 . V_10 ) ;
return 0 ;
V_200:
F_149 ( V_12 ) ;
V_199:
F_132 ( V_139 ) ;
V_67:
F_153 ( V_104 , V_143 ) ;
V_196:
F_153 ( V_104 , V_160 ) ;
V_190:
F_154 ( & V_9 . V_10 ) ;
return V_66 ;
}
static int F_167 ( struct V_129 * V_104 , struct V_24 * V_24 )
{
int V_66 ;
struct V_138 * V_139 = V_104 -> V_130 ;
struct V_12 * V_12 = V_139 -> V_12 ;
unsigned long V_29 ;
F_24 ( & V_12 -> V_30 , V_29 ) ;
V_24 -> V_37 = V_139 -> V_143 -> V_39 ;
V_66 = V_133 ;
F_25 ( & V_12 -> V_30 , V_29 ) ;
return V_66 ;
}
static int F_168 ( struct V_129 * V_104 )
{
int V_66 ;
struct V_138 * V_139 = V_104 -> V_130 ;
struct V_12 * V_12 = V_139 -> V_12 ;
T_2 V_207 = V_104 -> V_208 ;
T_1 V_209 ;
V_66 = F_122 ( V_12 , V_104 ) ;
if ( V_66 )
return V_66 ;
( void ) F_27 ( V_207 , V_12 -> V_36 ) ;
V_66 = F_169 ( V_12 -> V_96 , & V_209 ) ;
if ( V_66 ) {
F_107 ( L_43 ) ;
return V_66 ;
}
if ( V_207 < V_209 ) {
F_107 ( L_44 ,
( unsigned long long ) V_207 , V_209 ) ;
return - V_98 ;
} else if ( V_207 > V_209 ) {
V_66 = F_170 ( V_12 -> V_96 , V_207 ) ;
if ( V_66 ) {
F_107 ( L_45 ) ;
F_80 ( V_12 , V_99 ) ;
return V_66 ;
}
( void ) F_78 ( V_12 ) ;
}
return 0 ;
}
static void F_171 ( struct V_129 * V_104 )
{
struct V_138 * V_139 = V_104 -> V_130 ;
struct V_12 * V_12 = V_139 -> V_12 ;
unsigned long V_29 ;
F_24 ( & V_12 -> V_30 , V_29 ) ;
V_12 -> V_103 = 0 ;
V_12 -> V_106 = 0 ;
F_117 ( V_12 ) ;
F_25 ( & V_12 -> V_30 , V_29 ) ;
F_104 ( & V_12 -> V_125 . V_210 ) ;
}
static void F_172 ( struct V_129 * V_104 )
{
struct V_138 * V_139 = V_104 -> V_130 ;
struct V_12 * V_12 = V_139 -> V_12 ;
F_173 ( & V_12 -> V_125 ) ;
F_174 ( V_12 -> V_48 ) ;
( void ) F_78 ( V_12 ) ;
}
static int F_175 ( unsigned V_183 , unsigned V_211 )
{
if ( V_183 != V_211 ) {
F_83 ( L_46 ,
V_183 , V_211 ) ;
return - V_98 ;
}
return 0 ;
}
static int F_176 ( char * V_212 , T_5 * V_213 , int V_214 )
{
if ( ! F_162 ( V_212 , 10 , ( unsigned long long * ) V_213 ) &&
* V_213 <= V_215 )
return 0 ;
if ( V_214 )
F_83 ( L_47 , V_212 ) ;
return - V_98 ;
}
static int F_177 ( unsigned V_183 , char * * V_187 , struct V_12 * V_12 )
{
T_5 V_213 ;
int V_66 ;
V_66 = F_175 ( V_183 , 2 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_176 ( V_187 [ 1 ] , & V_213 , 1 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_178 ( V_12 -> V_96 , V_213 ) ;
if ( V_66 ) {
F_83 ( L_48 ,
V_187 [ 1 ] ) ;
return V_66 ;
}
return 0 ;
}
static int F_179 ( unsigned V_183 , char * * V_187 , struct V_12 * V_12 )
{
T_5 V_213 ;
T_5 V_216 ;
int V_66 ;
V_66 = F_175 ( V_183 , 3 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_176 ( V_187 [ 1 ] , & V_213 , 1 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_176 ( V_187 [ 2 ] , & V_216 , 1 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_180 ( V_12 -> V_96 , V_213 , V_216 ) ;
if ( V_66 ) {
F_83 ( L_49 ,
V_187 [ 1 ] , V_187 [ 2 ] ) ;
return V_66 ;
}
return 0 ;
}
static int F_181 ( unsigned V_183 , char * * V_187 , struct V_12 * V_12 )
{
T_5 V_213 ;
int V_66 ;
V_66 = F_175 ( V_183 , 2 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_176 ( V_187 [ 1 ] , & V_213 , 1 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_182 ( V_12 -> V_96 , V_213 ) ;
if ( V_66 )
F_83 ( L_50 , V_187 [ 1 ] ) ;
return V_66 ;
}
static int F_183 ( unsigned V_183 , char * * V_187 , struct V_12 * V_12 )
{
T_5 V_217 , V_218 ;
int V_66 ;
V_66 = F_175 ( V_183 , 3 ) ;
if ( V_66 )
return V_66 ;
if ( F_162 ( V_187 [ 1 ] , 10 , ( unsigned long long * ) & V_217 ) ) {
F_83 ( L_51 , V_187 [ 1 ] ) ;
return - V_98 ;
}
if ( F_162 ( V_187 [ 2 ] , 10 , ( unsigned long long * ) & V_218 ) ) {
F_83 ( L_52 , V_187 [ 2 ] ) ;
return - V_98 ;
}
V_66 = F_184 ( V_12 -> V_96 , V_217 , V_218 ) ;
if ( V_66 ) {
F_83 ( L_53 ,
V_187 [ 1 ] , V_187 [ 2 ] ) ;
return V_66 ;
}
return 0 ;
}
static int F_185 ( unsigned V_183 , char * * V_187 , struct V_12 * V_12 )
{
int V_66 ;
V_66 = F_175 ( V_183 , 1 ) ;
if ( V_66 )
return V_66 ;
( void ) F_78 ( V_12 ) ;
V_66 = F_186 ( V_12 -> V_96 ) ;
if ( V_66 )
F_83 ( L_54 ) ;
return V_66 ;
}
static int F_187 ( unsigned V_183 , char * * V_187 , struct V_12 * V_12 )
{
int V_66 ;
V_66 = F_175 ( V_183 , 1 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_188 ( V_12 -> V_96 ) ;
if ( V_66 )
F_83 ( L_55 ) ;
return V_66 ;
}
static int F_189 ( struct V_129 * V_104 , unsigned V_183 , char * * V_187 )
{
int V_66 = - V_98 ;
struct V_138 * V_139 = V_104 -> V_130 ;
struct V_12 * V_12 = V_139 -> V_12 ;
if ( ! strcasecmp ( V_187 [ 0 ] , L_56 ) )
V_66 = F_177 ( V_183 , V_187 , V_12 ) ;
else if ( ! strcasecmp ( V_187 [ 0 ] , L_57 ) )
V_66 = F_179 ( V_183 , V_187 , V_12 ) ;
else if ( ! strcasecmp ( V_187 [ 0 ] , L_58 ) )
V_66 = F_181 ( V_183 , V_187 , V_12 ) ;
else if ( ! strcasecmp ( V_187 [ 0 ] , L_59 ) )
V_66 = F_183 ( V_183 , V_187 , V_12 ) ;
else if ( ! strcasecmp ( V_187 [ 0 ] , L_60 ) )
V_66 = F_185 ( V_183 , V_187 , V_12 ) ;
else if ( ! strcasecmp ( V_187 [ 0 ] , L_61 ) )
V_66 = F_187 ( V_183 , V_187 , V_12 ) ;
else
F_83 ( L_62 , V_187 [ 0 ] ) ;
if ( ! V_66 )
( void ) F_78 ( V_12 ) ;
return V_66 ;
}
static void F_190 ( struct V_158 * V_94 , char * V_100 ,
unsigned V_219 , unsigned V_220 )
{
unsigned V_92 = ! V_94 -> V_95 + ! V_94 -> V_159 +
! V_94 -> V_113 + ( V_94 -> V_127 == V_99 ) ;
F_191 ( L_63 , V_92 ) ;
if ( ! V_94 -> V_95 )
F_191 ( L_64 ) ;
if ( ! V_94 -> V_159 )
F_191 ( L_65 ) ;
if ( ! V_94 -> V_113 )
F_191 ( L_66 ) ;
if ( V_94 -> V_127 == V_99 )
F_191 ( L_67 ) ;
}
static int F_192 ( struct V_129 * V_104 , T_6 type ,
unsigned V_221 , char * V_100 , unsigned V_220 )
{
int V_66 ;
unsigned V_219 = 0 ;
T_7 V_222 ;
T_1 V_223 ;
T_1 V_224 ;
T_1 V_225 ;
T_1 V_226 ;
T_1 V_227 ;
char V_151 [ V_152 ] ;
char V_228 [ V_152 ] ;
struct V_138 * V_139 = V_104 -> V_130 ;
struct V_12 * V_12 = V_139 -> V_12 ;
switch ( type ) {
case V_229 :
if ( F_79 ( V_12 ) == V_128 ) {
F_191 ( L_68 ) ;
break;
}
if ( ! ( V_221 & V_230 ) && ! F_193 ( V_104 ) )
( void ) F_78 ( V_12 ) ;
V_66 = F_194 ( V_12 -> V_96 ,
& V_222 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_195 ( V_12 -> V_96 ,
& V_224 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_196 ( V_12 -> V_96 , & V_226 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_82 ( V_12 -> V_96 ,
& V_223 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_169 ( V_12 -> V_96 , & V_225 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_197 ( V_12 -> V_96 , & V_227 ) ;
if ( V_66 )
return V_66 ;
F_191 ( L_69 ,
( unsigned long long ) V_222 ,
( unsigned long long ) ( V_226 - V_224 ) ,
( unsigned long long ) V_226 ,
( unsigned long long ) ( V_225 - V_223 ) ,
( unsigned long long ) V_225 ) ;
if ( V_227 )
F_191 ( L_70 , V_227 ) ;
else
F_191 ( L_71 ) ;
if ( V_12 -> V_94 . V_127 == V_99 )
F_191 ( L_72 ) ;
else
F_191 ( L_73 ) ;
if ( ! V_12 -> V_94 . V_159 )
F_191 ( L_32 ) ;
else if ( V_12 -> V_94 . V_113 )
F_191 ( L_74 ) ;
else
F_191 ( L_33 ) ;
break;
case V_231 :
F_191 ( L_75 ,
F_198 ( V_151 , V_139 -> V_160 -> V_39 -> V_232 ) ,
F_198 ( V_228 , V_139 -> V_143 -> V_39 -> V_232 ) ,
( unsigned long ) V_12 -> V_36 ,
( unsigned long long ) V_139 -> V_102 ) ;
F_190 ( & V_139 -> V_201 , V_100 , V_219 , V_220 ) ;
break;
}
return 0 ;
}
static int F_199 ( struct V_129 * V_104 ,
T_8 V_74 , void * V_233 )
{
struct V_138 * V_139 = V_104 -> V_130 ;
return V_74 ( V_104 , V_139 -> V_143 , 0 , V_104 -> V_208 , V_233 ) ;
}
static int F_200 ( struct V_129 * V_104 , struct V_234 * V_235 ,
struct V_236 * V_237 , int V_238 )
{
struct V_138 * V_139 = V_104 -> V_130 ;
struct V_141 * V_142 = F_115 ( V_139 -> V_143 -> V_39 ) ;
if ( ! V_142 -> V_239 )
return V_238 ;
V_235 -> V_37 = V_139 -> V_143 -> V_39 ;
return F_201 ( V_238 , V_142 -> V_239 ( V_142 , V_235 , V_237 ) ) ;
}
static bool F_202 ( struct V_12 * V_12 )
{
return V_12 -> V_35 >= 0 ;
}
static void F_203 ( struct V_138 * V_139 , struct V_146 * V_148 )
{
struct V_12 * V_12 = V_139 -> V_12 ;
struct V_146 * V_147 ;
V_148 -> V_154 = V_12 -> V_36 ;
if ( V_139 -> V_153 . V_113 ) {
V_147 = & F_115 ( V_139 -> V_143 -> V_39 ) -> V_148 ;
V_148 -> V_155 = V_147 -> V_155 ;
} else if ( F_202 ( V_12 ) )
V_148 -> V_155 = V_12 -> V_36 << V_77 ;
else
V_148 -> V_155 = F_204 ( 1 << ( F_205 ( V_12 -> V_36 ) - 1 ) ,
V_197 ) << V_77 ;
}
static void F_206 ( struct V_129 * V_104 , struct V_146 * V_148 )
{
struct V_138 * V_139 = V_104 -> V_130 ;
struct V_12 * V_12 = V_139 -> V_12 ;
F_207 ( V_148 , 0 ) ;
F_208 ( V_148 , V_12 -> V_36 << V_77 ) ;
if ( ! V_139 -> V_153 . V_159 )
return;
F_120 ( V_139 ) ;
F_203 ( V_139 , V_148 ) ;
}
static void F_209 ( struct V_129 * V_104 )
{
struct V_20 * V_21 = V_104 -> V_130 ;
F_152 ( & V_9 . V_10 ) ;
F_149 ( V_21 -> V_12 ) ;
F_210 ( V_21 -> V_2 ) ;
F_153 ( V_104 , V_21 -> V_38 ) ;
if ( V_21 -> V_40 )
F_153 ( V_104 , V_21 -> V_40 ) ;
F_132 ( V_21 ) ;
F_154 ( & V_9 . V_10 ) ;
}
static int F_211 ( struct V_129 * V_104 , unsigned V_183 , char * * V_187 )
{
int V_66 ;
struct V_20 * V_21 ;
struct V_83 * V_38 , * V_40 ;
struct V_14 * V_17 ;
F_152 ( & V_9 . V_10 ) ;
if ( V_183 != 2 && V_183 != 3 ) {
V_104 -> error = L_36 ;
V_66 = - V_98 ;
goto V_190;
}
V_21 = V_104 -> V_130 = F_164 ( sizeof( * V_21 ) , V_165 ) ;
if ( ! V_21 ) {
V_104 -> error = L_76 ;
V_66 = - V_82 ;
goto V_190;
}
if ( V_183 == 3 ) {
V_66 = F_159 ( V_104 , V_187 [ 2 ] , V_191 , & V_40 ) ;
if ( V_66 ) {
V_104 -> error = L_77 ;
goto V_240;
}
V_21 -> V_40 = V_40 ;
}
V_66 = F_159 ( V_104 , V_187 [ 0 ] , F_212 ( V_104 -> V_105 ) , & V_38 ) ;
if ( V_66 ) {
V_104 -> error = L_78 ;
goto V_241;
}
V_21 -> V_38 = V_38 ;
if ( F_176 ( V_187 [ 1 ] , ( unsigned long long * ) & V_21 -> V_213 , 0 ) ) {
V_104 -> error = L_79 ;
V_66 = - V_98 ;
goto V_242;
}
V_17 = F_213 ( V_21 -> V_38 -> V_39 -> V_232 ) ;
if ( ! V_17 ) {
V_104 -> error = L_80 ;
V_66 = - V_98 ;
goto V_242;
}
V_21 -> V_12 = F_13 ( V_17 ) ;
if ( ! V_21 -> V_12 ) {
V_104 -> error = L_81 ;
V_66 = - V_98 ;
goto V_243;
}
F_148 ( V_21 -> V_12 ) ;
if ( F_79 ( V_21 -> V_12 ) == V_128 ) {
V_104 -> error = L_82 ;
goto V_244;
}
V_66 = F_214 ( V_21 -> V_12 -> V_96 , V_21 -> V_213 , & V_21 -> V_2 ) ;
if ( V_66 ) {
V_104 -> error = L_83 ;
goto V_244;
}
V_66 = F_215 ( V_104 , V_21 -> V_12 -> V_36 ) ;
if ( V_66 )
goto V_244;
V_104 -> V_202 = 1 ;
V_104 -> V_245 = true ;
V_104 -> V_246 = sizeof( struct V_26 ) ;
if ( V_21 -> V_12 -> V_94 . V_159 ) {
V_104 -> V_204 = true ;
V_104 -> V_203 = 1 ;
V_104 -> V_205 = true ;
V_104 -> V_247 = true ;
}
F_216 ( V_17 ) ;
F_154 ( & V_9 . V_10 ) ;
return 0 ;
V_244:
F_149 ( V_21 -> V_12 ) ;
V_243:
F_216 ( V_17 ) ;
V_242:
F_153 ( V_104 , V_21 -> V_38 ) ;
V_241:
if ( V_21 -> V_40 )
F_153 ( V_104 , V_21 -> V_40 ) ;
V_240:
F_132 ( V_21 ) ;
V_190:
F_154 ( & V_9 . V_10 ) ;
return V_66 ;
}
static int F_217 ( struct V_129 * V_104 , struct V_24 * V_24 )
{
V_24 -> V_34 = F_218 ( V_104 , V_24 -> V_34 ) ;
return F_112 ( V_104 , V_24 ) ;
}
static int F_219 ( struct V_129 * V_104 , struct V_24 * V_24 , int V_58 )
{
unsigned long V_29 ;
struct V_26 * V_27 = F_20 ( V_24 , sizeof( struct V_26 ) ) ;
struct V_72 V_210 ;
struct V_50 * V_51 , * V_16 ;
struct V_12 * V_12 = V_27 -> V_21 -> V_12 ;
if ( V_27 -> V_117 ) {
F_6 ( & V_210 ) ;
F_220 ( V_27 -> V_117 , & V_210 ) ;
F_24 ( & V_12 -> V_30 , V_29 ) ;
F_61 (m, tmp, &work, list) {
F_12 ( & V_51 -> V_13 ) ;
V_51 -> V_52 = 1 ;
F_42 ( V_51 ) ;
}
F_25 ( & V_12 -> V_30 , V_29 ) ;
}
if ( V_27 -> V_45 ) {
F_6 ( & V_210 ) ;
F_220 ( V_27 -> V_45 , & V_210 ) ;
if ( ! F_221 ( & V_210 ) ) {
F_24 ( & V_12 -> V_30 , V_29 ) ;
F_61 (m, tmp, &work, list)
F_10 ( & V_51 -> V_13 , & V_12 -> V_114 ) ;
F_25 ( & V_12 -> V_30 , V_29 ) ;
F_40 ( V_12 ) ;
}
}
return 0 ;
}
static void F_222 ( struct V_129 * V_104 )
{
if ( F_223 ( V_104 ) )
F_23 ( (struct V_20 * ) V_104 -> V_130 ) ;
}
static int F_224 ( struct V_129 * V_104 , T_6 type ,
unsigned V_221 , char * V_100 , unsigned V_220 )
{
int V_66 ;
T_9 V_219 = 0 ;
T_1 V_248 , V_249 ;
char V_151 [ V_152 ] ;
struct V_20 * V_21 = V_104 -> V_130 ;
if ( F_79 ( V_21 -> V_12 ) == V_128 ) {
F_191 ( L_68 ) ;
return 0 ;
}
if ( ! V_21 -> V_2 )
F_191 ( L_84 ) ;
else {
switch ( type ) {
case V_229 :
V_66 = F_225 ( V_21 -> V_2 , & V_248 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_226 ( V_21 -> V_2 , & V_249 ) ;
if ( V_66 < 0 )
return V_66 ;
F_191 ( L_70 , V_248 * V_21 -> V_12 -> V_36 ) ;
if ( V_66 )
F_191 ( L_85 , ( ( V_249 + 1 ) *
V_21 -> V_12 -> V_36 ) - 1 ) ;
else
F_191 ( L_84 ) ;
break;
case V_231 :
F_191 ( L_86 ,
F_198 ( V_151 , V_21 -> V_38 -> V_39 -> V_232 ) ,
( unsigned long ) V_21 -> V_213 ) ;
if ( V_21 -> V_40 )
F_191 ( L_87 , F_198 ( V_151 , V_21 -> V_40 -> V_39 -> V_232 ) ) ;
break;
}
}
return 0 ;
}
static int F_227 ( struct V_129 * V_104 ,
T_8 V_74 , void * V_233 )
{
T_2 V_250 ;
struct V_20 * V_21 = V_104 -> V_130 ;
struct V_12 * V_12 = V_21 -> V_12 ;
if ( ! V_12 -> V_104 )
return 0 ;
V_250 = V_12 -> V_104 -> V_208 ;
( void ) F_27 ( V_250 , V_12 -> V_36 ) ;
if ( V_250 )
return V_74 ( V_104 , V_21 -> V_38 , 0 , V_12 -> V_36 * V_250 , V_233 ) ;
return 0 ;
}
static int T_10 F_228 ( void )
{
int V_66 ;
F_4 () ;
V_66 = F_229 ( & V_251 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_229 ( & V_252 ) ;
if ( V_66 )
goto V_253;
V_66 = - V_82 ;
V_176 = F_230 ( V_50 , 0 ) ;
if ( ! V_176 )
goto V_254;
return 0 ;
V_254:
F_231 ( & V_252 ) ;
V_253:
F_231 ( & V_251 ) ;
return V_66 ;
}
static void F_232 ( void )
{
F_231 ( & V_251 ) ;
F_231 ( & V_252 ) ;
F_233 ( V_176 ) ;
}
