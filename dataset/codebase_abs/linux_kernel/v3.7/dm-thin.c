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
struct V_26 * V_27 = F_20 ( V_24 ) -> V_28 ;
if ( V_27 -> V_21 == V_21 )
F_21 ( V_24 , V_29 ) ;
else
F_22 ( V_23 , V_24 ) ;
}
}
static void F_23 ( struct V_20 * V_21 )
{
struct V_12 * V_12 = V_21 -> V_12 ;
unsigned long V_30 ;
F_24 ( & V_12 -> V_31 , V_30 ) ;
F_16 ( V_21 , & V_12 -> V_32 ) ;
F_16 ( V_21 , & V_12 -> V_33 ) ;
F_25 ( & V_12 -> V_31 , V_30 ) ;
}
static T_1 F_26 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
T_2 V_34 = V_24 -> V_35 ;
if ( V_21 -> V_12 -> V_36 < 0 )
( void ) F_27 ( V_34 , V_21 -> V_12 -> V_37 ) ;
else
V_34 >>= V_21 -> V_12 -> V_36 ;
return V_34 ;
}
static void F_28 ( struct V_20 * V_21 , struct V_24 * V_24 , T_1 V_8 )
{
struct V_12 * V_12 = V_21 -> V_12 ;
T_2 V_35 = V_24 -> V_35 ;
V_24 -> V_38 = V_21 -> V_39 -> V_40 ;
if ( V_21 -> V_12 -> V_36 < 0 )
V_24 -> V_35 = ( V_8 * V_12 -> V_37 ) +
F_27 ( V_35 , V_12 -> V_37 ) ;
else
V_24 -> V_35 = ( V_8 << V_12 -> V_36 ) |
( V_35 & ( V_12 -> V_37 - 1 ) ) ;
}
static void F_29 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
V_24 -> V_38 = V_21 -> V_41 -> V_40 ;
}
static int F_30 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
return ( V_24 -> V_42 & ( V_43 | V_44 ) ) &&
F_31 ( V_21 -> V_2 ) ;
}
static void F_32 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
struct V_12 * V_12 = V_21 -> V_12 ;
unsigned long V_30 ;
if ( ! F_30 ( V_21 , V_24 ) ) {
F_33 ( V_24 ) ;
return;
}
if ( F_34 ( V_21 -> V_2 ) ) {
F_35 ( V_24 ) ;
return;
}
F_24 ( & V_12 -> V_31 , V_30 ) ;
F_22 ( & V_12 -> V_45 , V_24 ) ;
F_25 ( & V_12 -> V_31 , V_30 ) ;
}
static void F_36 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
F_29 ( V_21 , V_24 ) ;
F_32 ( V_21 , V_24 ) ;
}
static void F_37 ( struct V_20 * V_21 , struct V_24 * V_24 ,
T_1 V_8 )
{
F_28 ( V_21 , V_24 , V_8 ) ;
F_32 ( V_21 , V_24 ) ;
}
static void F_38 ( struct V_12 * V_12 )
{
F_39 ( V_12 -> V_46 , & V_12 -> V_47 ) ;
}
static void F_40 ( struct V_48 * V_49 )
{
struct V_12 * V_12 = V_49 -> V_21 -> V_12 ;
if ( V_49 -> V_50 && V_49 -> V_51 ) {
F_10 ( & V_49 -> V_13 , & V_12 -> V_52 ) ;
F_38 ( V_12 ) ;
}
}
static void F_41 ( int V_53 , unsigned long V_54 , void * V_55 )
{
unsigned long V_30 ;
struct V_48 * V_49 = V_55 ;
struct V_12 * V_12 = V_49 -> V_21 -> V_12 ;
V_49 -> V_56 = V_53 || V_54 ? - V_57 : 0 ;
F_24 ( & V_12 -> V_31 , V_30 ) ;
V_49 -> V_51 = 1 ;
F_40 ( V_49 ) ;
F_25 ( & V_12 -> V_31 , V_30 ) ;
}
static void F_42 ( struct V_24 * V_24 , int V_56 )
{
unsigned long V_30 ;
struct V_26 * V_27 = F_20 ( V_24 ) -> V_28 ;
struct V_48 * V_49 = V_27 -> V_58 ;
struct V_12 * V_12 = V_49 -> V_21 -> V_12 ;
V_49 -> V_56 = V_56 ;
F_24 ( & V_12 -> V_31 , V_30 ) ;
V_49 -> V_51 = 1 ;
F_40 ( V_49 ) ;
F_25 ( & V_12 -> V_31 , V_30 ) ;
}
static void F_43 ( struct V_20 * V_21 , struct V_59 * V_60 ,
T_1 V_61 )
{
struct V_12 * V_12 = V_21 -> V_12 ;
unsigned long V_30 ;
F_24 ( & V_12 -> V_31 , V_30 ) ;
F_44 ( V_60 , & V_12 -> V_32 ) ;
F_25 ( & V_21 -> V_12 -> V_31 , V_30 ) ;
F_38 ( V_12 ) ;
}
static void F_45 ( struct V_20 * V_21 , struct V_59 * V_60 )
{
struct V_22 V_25 ;
struct V_12 * V_12 = V_21 -> V_12 ;
unsigned long V_30 ;
F_17 ( & V_25 ) ;
F_24 ( & V_12 -> V_31 , V_30 ) ;
F_46 ( V_60 , & V_12 -> V_32 ) ;
F_25 ( & V_12 -> V_31 , V_30 ) ;
F_38 ( V_12 ) ;
}
static void F_47 ( struct V_48 * V_49 )
{
if ( V_49 -> V_24 )
V_49 -> V_24 -> V_62 = V_49 -> V_63 ;
F_48 ( V_49 -> V_60 ) ;
F_12 ( & V_49 -> V_13 ) ;
F_49 ( V_49 , V_49 -> V_21 -> V_12 -> V_64 ) ;
}
static void F_50 ( struct V_48 * V_49 )
{
struct V_20 * V_21 = V_49 -> V_21 ;
struct V_24 * V_24 ;
int V_65 ;
V_24 = V_49 -> V_24 ;
if ( V_24 )
V_24 -> V_62 = V_49 -> V_63 ;
if ( V_49 -> V_56 ) {
F_48 ( V_49 -> V_60 ) ;
goto V_66;
}
V_65 = F_51 ( V_21 -> V_2 , V_49 -> V_67 , V_49 -> V_61 ) ;
if ( V_65 ) {
F_52 ( L_1 ) ;
F_48 ( V_49 -> V_60 ) ;
goto V_66;
}
if ( V_24 ) {
F_45 ( V_21 , V_49 -> V_60 ) ;
F_21 ( V_24 , 0 ) ;
} else
F_43 ( V_21 , V_49 -> V_60 , V_49 -> V_61 ) ;
V_66:
F_12 ( & V_49 -> V_13 ) ;
F_49 ( V_49 , V_21 -> V_12 -> V_64 ) ;
}
static void F_53 ( struct V_48 * V_49 )
{
struct V_20 * V_21 = V_49 -> V_21 ;
F_35 ( V_49 -> V_24 ) ;
F_45 ( V_21 , V_49 -> V_60 ) ;
F_45 ( V_21 , V_49 -> V_68 ) ;
F_49 ( V_49 , V_21 -> V_12 -> V_64 ) ;
}
static void F_54 ( struct V_48 * V_49 )
{
struct V_20 * V_21 = V_49 -> V_21 ;
if ( V_49 -> V_69 )
F_37 ( V_21 , V_49 -> V_24 , V_49 -> V_61 ) ;
else
F_21 ( V_49 -> V_24 , 0 ) ;
F_45 ( V_21 , V_49 -> V_60 ) ;
F_45 ( V_21 , V_49 -> V_68 ) ;
F_49 ( V_49 , V_21 -> V_12 -> V_64 ) ;
}
static void F_55 ( struct V_48 * V_49 )
{
int V_65 ;
struct V_20 * V_21 = V_49 -> V_21 ;
V_65 = F_56 ( V_21 -> V_2 , V_49 -> V_67 ) ;
if ( V_65 )
F_52 ( L_2 ) ;
F_54 ( V_49 ) ;
}
static void F_57 ( struct V_12 * V_12 , struct V_70 * V_71 ,
T_3 * V_72 )
{
unsigned long V_30 ;
struct V_70 V_73 ;
struct V_48 * V_49 , * V_16 ;
F_6 ( & V_73 ) ;
F_24 ( & V_12 -> V_31 , V_30 ) ;
F_58 ( V_71 , & V_73 ) ;
F_25 ( & V_12 -> V_31 , V_30 ) ;
F_59 ( V_49 , V_16 , & V_73 , V_13 )
( * V_72 ) ( V_49 ) ;
}
static int F_60 ( struct V_12 * V_12 , struct V_24 * V_24 )
{
return V_24 -> V_74 == ( V_12 -> V_37 << V_75 ) ;
}
static int F_61 ( struct V_12 * V_12 , struct V_24 * V_24 )
{
return ( F_62 ( V_24 ) == V_76 ) &&
F_60 ( V_12 , V_24 ) ;
}
static void F_63 ( struct V_24 * V_24 , T_4 * * V_77 ,
T_4 * V_72 )
{
* V_77 = V_24 -> V_62 ;
V_24 -> V_62 = V_72 ;
}
static int F_64 ( struct V_12 * V_12 )
{
if ( V_12 -> V_78 )
return 0 ;
V_12 -> V_78 = F_65 ( V_12 -> V_64 , V_79 ) ;
return V_12 -> V_78 ? 0 : - V_80 ;
}
static struct V_48 * F_66 ( struct V_12 * V_12 )
{
struct V_48 * V_65 = V_12 -> V_78 ;
F_8 ( ! V_12 -> V_78 ) ;
V_12 -> V_78 = NULL ;
return V_65 ;
}
static void F_67 ( struct V_20 * V_21 , T_1 V_67 ,
struct V_81 * V_82 , T_1 V_83 ,
T_1 V_84 ,
struct V_59 * V_60 , struct V_24 * V_24 )
{
int V_65 ;
struct V_12 * V_12 = V_21 -> V_12 ;
struct V_48 * V_49 = F_66 ( V_12 ) ;
F_6 ( & V_49 -> V_13 ) ;
V_49 -> V_50 = 0 ;
V_49 -> V_51 = 0 ;
V_49 -> V_21 = V_21 ;
V_49 -> V_67 = V_67 ;
V_49 -> V_61 = V_84 ;
V_49 -> V_60 = V_60 ;
V_49 -> V_56 = 0 ;
V_49 -> V_24 = NULL ;
if ( ! F_68 ( V_12 -> V_85 , & V_49 -> V_13 ) )
V_49 -> V_50 = 1 ;
if ( F_61 ( V_12 , V_24 ) ) {
struct V_26 * V_27 = F_20 ( V_24 ) -> V_28 ;
V_27 -> V_58 = V_49 ;
V_49 -> V_24 = V_24 ;
F_63 ( V_24 , & V_49 -> V_63 , F_42 ) ;
F_37 ( V_21 , V_24 , V_84 ) ;
} else {
struct V_86 V_87 , V_88 ;
V_87 . V_40 = V_82 -> V_40 ;
V_87 . V_89 = V_83 * V_12 -> V_37 ;
V_87 . V_90 = V_12 -> V_37 ;
V_88 . V_40 = V_21 -> V_39 -> V_40 ;
V_88 . V_89 = V_84 * V_12 -> V_37 ;
V_88 . V_90 = V_12 -> V_37 ;
V_65 = F_69 ( V_12 -> V_91 , & V_87 , 1 , & V_88 ,
0 , F_41 , V_49 ) ;
if ( V_65 < 0 ) {
F_49 ( V_49 , V_12 -> V_64 ) ;
F_52 ( L_3 ) ;
F_48 ( V_60 ) ;
}
}
}
static void F_70 ( struct V_20 * V_21 , T_1 V_67 ,
T_1 V_83 , T_1 V_84 ,
struct V_59 * V_60 , struct V_24 * V_24 )
{
F_67 ( V_21 , V_67 , V_21 -> V_39 ,
V_83 , V_84 , V_60 , V_24 ) ;
}
static void F_71 ( struct V_20 * V_21 , T_1 V_67 ,
T_1 V_84 ,
struct V_59 * V_60 , struct V_24 * V_24 )
{
F_67 ( V_21 , V_67 , V_21 -> V_41 ,
V_67 , V_84 , V_60 , V_24 ) ;
}
static void F_72 ( struct V_20 * V_21 , T_1 V_67 ,
T_1 V_61 , struct V_59 * V_60 ,
struct V_24 * V_24 )
{
struct V_12 * V_12 = V_21 -> V_12 ;
struct V_48 * V_49 = F_66 ( V_12 ) ;
F_6 ( & V_49 -> V_13 ) ;
V_49 -> V_50 = 1 ;
V_49 -> V_51 = 0 ;
V_49 -> V_21 = V_21 ;
V_49 -> V_67 = V_67 ;
V_49 -> V_61 = V_61 ;
V_49 -> V_60 = V_60 ;
V_49 -> V_56 = 0 ;
V_49 -> V_24 = NULL ;
if ( ! V_12 -> V_92 . V_93 )
F_50 ( V_49 ) ;
else if ( F_61 ( V_12 , V_24 ) ) {
struct V_26 * V_27 = F_20 ( V_24 ) -> V_28 ;
V_27 -> V_58 = V_49 ;
V_49 -> V_24 = V_24 ;
F_63 ( V_24 , & V_49 -> V_63 , F_42 ) ;
F_37 ( V_21 , V_24 , V_61 ) ;
} else {
int V_65 ;
struct V_86 V_88 ;
V_88 . V_40 = V_21 -> V_39 -> V_40 ;
V_88 . V_89 = V_61 * V_12 -> V_37 ;
V_88 . V_90 = V_12 -> V_37 ;
V_65 = F_73 ( V_12 -> V_91 , 1 , & V_88 , 0 , F_41 , V_49 ) ;
if ( V_65 < 0 ) {
F_49 ( V_49 , V_12 -> V_64 ) ;
F_52 ( L_4 ) ;
F_48 ( V_60 ) ;
}
}
}
static int F_74 ( struct V_12 * V_12 )
{
int V_65 ;
V_65 = F_75 ( V_12 -> V_94 ) ;
if ( V_65 )
F_52 ( L_5 , V_65 ) ;
return V_65 ;
}
static int F_76 ( struct V_12 * V_12 )
{
int V_65 ;
if ( F_77 ( V_12 ) != V_95 )
return - V_96 ;
V_65 = F_74 ( V_12 ) ;
if ( V_65 )
F_78 ( V_12 , V_97 ) ;
return V_65 ;
}
static int F_79 ( struct V_20 * V_21 , T_1 * V_98 )
{
int V_65 ;
T_1 V_99 ;
unsigned long V_30 ;
struct V_12 * V_12 = V_21 -> V_12 ;
V_65 = F_80 ( V_12 -> V_94 , & V_99 ) ;
if ( V_65 )
return V_65 ;
if ( V_99 <= V_12 -> V_100 && ! V_12 -> V_101 ) {
F_81 ( L_6 ,
F_82 ( V_12 -> V_17 ) ) ;
F_24 ( & V_12 -> V_31 , V_30 ) ;
V_12 -> V_101 = 1 ;
F_25 ( & V_12 -> V_31 , V_30 ) ;
F_83 ( V_12 -> V_102 -> V_103 ) ;
}
if ( ! V_99 ) {
if ( V_12 -> V_104 )
return - V_105 ;
else {
( void ) F_76 ( V_12 ) ;
V_65 = F_80 ( V_12 -> V_94 , & V_99 ) ;
if ( V_65 )
return V_65 ;
if ( ! V_99 ) {
F_81 ( L_7 ,
F_82 ( V_12 -> V_17 ) ) ;
F_24 ( & V_12 -> V_31 , V_30 ) ;
V_12 -> V_104 = 1 ;
F_25 ( & V_12 -> V_31 , V_30 ) ;
return - V_105 ;
}
}
}
V_65 = F_84 ( V_12 -> V_94 , V_98 ) ;
if ( V_65 )
return V_65 ;
return 0 ;
}
static void F_85 ( struct V_24 * V_24 )
{
struct V_26 * V_27 = F_20 ( V_24 ) -> V_28 ;
struct V_20 * V_21 = V_27 -> V_21 ;
struct V_12 * V_12 = V_21 -> V_12 ;
unsigned long V_30 ;
F_24 ( & V_12 -> V_31 , V_30 ) ;
F_22 ( & V_12 -> V_33 , V_24 ) ;
F_25 ( & V_12 -> V_31 , V_30 ) ;
}
static void F_86 ( struct V_59 * V_60 )
{
struct V_24 * V_24 ;
struct V_22 V_25 ;
F_17 ( & V_25 ) ;
F_44 ( V_60 , & V_25 ) ;
while ( ( V_24 = F_19 ( & V_25 ) ) )
F_85 ( V_24 ) ;
}
static void F_87 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
int V_65 ;
unsigned long V_30 ;
struct V_12 * V_12 = V_21 -> V_12 ;
struct V_59 * V_60 , * V_68 ;
struct V_4 V_5 , V_106 ;
T_1 V_8 = F_26 ( V_21 , V_24 ) ;
struct V_107 V_108 ;
struct V_48 * V_49 ;
F_3 ( V_21 -> V_2 , V_8 , & V_5 ) ;
if ( F_88 ( V_21 -> V_12 -> V_109 , & V_5 , V_24 , & V_60 ) )
return;
V_65 = F_89 ( V_21 -> V_2 , V_8 , 1 , & V_108 ) ;
switch ( V_65 ) {
case 0 :
F_1 ( V_21 -> V_2 , V_108 . V_8 , & V_106 ) ;
if ( F_88 ( V_21 -> V_12 -> V_109 , & V_106 , V_24 , & V_68 ) ) {
F_90 ( V_60 , V_24 ) ;
break;
}
if ( F_60 ( V_12 , V_24 ) ) {
V_49 = F_66 ( V_12 ) ;
V_49 -> V_21 = V_21 ;
V_49 -> V_69 = ( ! V_108 . V_110 ) && V_12 -> V_92 . V_111 ;
V_49 -> V_67 = V_8 ;
V_49 -> V_61 = V_108 . V_8 ;
V_49 -> V_60 = V_60 ;
V_49 -> V_68 = V_68 ;
V_49 -> V_56 = 0 ;
V_49 -> V_24 = V_24 ;
if ( ! F_68 ( V_12 -> V_112 , & V_49 -> V_13 ) ) {
F_24 ( & V_12 -> V_31 , V_30 ) ;
F_10 ( & V_49 -> V_13 , & V_12 -> V_113 ) ;
F_25 ( & V_12 -> V_31 , V_30 ) ;
F_38 ( V_12 ) ;
}
} else {
F_90 ( V_60 , V_24 ) ;
F_90 ( V_68 , V_24 ) ;
if ( ( ! V_108 . V_110 ) && V_12 -> V_92 . V_111 )
F_37 ( V_21 , V_24 , V_108 . V_8 ) ;
else
F_21 ( V_24 , 0 ) ;
}
break;
case - V_114 :
F_90 ( V_60 , V_24 ) ;
F_21 ( V_24 , 0 ) ;
break;
default:
F_52 ( L_8 , V_65 ) ;
F_90 ( V_60 , V_24 ) ;
F_35 ( V_24 ) ;
break;
}
}
static void F_91 ( struct V_20 * V_21 , struct V_24 * V_24 , T_1 V_8 ,
struct V_4 * V_5 ,
struct V_107 * V_108 ,
struct V_59 * V_60 )
{
int V_65 ;
T_1 V_61 ;
V_65 = F_79 ( V_21 , & V_61 ) ;
switch ( V_65 ) {
case 0 :
F_70 ( V_21 , V_8 , V_108 -> V_8 ,
V_61 , V_60 , V_24 ) ;
break;
case - V_105 :
F_86 ( V_60 ) ;
break;
default:
F_52 ( L_9 , V_115 , V_65 ) ;
F_48 ( V_60 ) ;
break;
}
}
static void F_92 ( struct V_20 * V_21 , struct V_24 * V_24 ,
T_1 V_8 ,
struct V_107 * V_108 )
{
struct V_59 * V_60 ;
struct V_12 * V_12 = V_21 -> V_12 ;
struct V_4 V_5 ;
F_1 ( V_21 -> V_2 , V_108 -> V_8 , & V_5 ) ;
if ( F_88 ( V_12 -> V_109 , & V_5 , V_24 , & V_60 ) )
return;
if ( F_62 ( V_24 ) == V_76 && V_24 -> V_74 )
F_91 ( V_21 , V_24 , V_8 , & V_5 , V_108 , V_60 ) ;
else {
struct V_26 * V_27 = F_20 ( V_24 ) -> V_28 ;
V_27 -> V_116 = F_93 ( V_12 -> V_85 ) ;
F_90 ( V_60 , V_24 ) ;
F_37 ( V_21 , V_24 , V_108 -> V_8 ) ;
}
}
static void F_94 ( struct V_20 * V_21 , struct V_24 * V_24 , T_1 V_8 ,
struct V_59 * V_60 )
{
int V_65 ;
T_1 V_61 ;
if ( ! V_24 -> V_74 ) {
F_90 ( V_60 , V_24 ) ;
F_37 ( V_21 , V_24 , 0 ) ;
return;
}
if ( F_62 ( V_24 ) == V_117 ) {
F_95 ( V_24 ) ;
F_90 ( V_60 , V_24 ) ;
F_21 ( V_24 , 0 ) ;
return;
}
V_65 = F_79 ( V_21 , & V_61 ) ;
switch ( V_65 ) {
case 0 :
if ( V_21 -> V_41 )
F_71 ( V_21 , V_8 , V_61 , V_60 , V_24 ) ;
else
F_72 ( V_21 , V_8 , V_61 , V_60 , V_24 ) ;
break;
case - V_105 :
F_86 ( V_60 ) ;
break;
default:
F_52 ( L_9 , V_115 , V_65 ) ;
F_78 ( V_21 -> V_12 , V_97 ) ;
F_48 ( V_60 ) ;
break;
}
}
static void F_96 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
int V_65 ;
T_1 V_8 = F_26 ( V_21 , V_24 ) ;
struct V_59 * V_60 ;
struct V_4 V_5 ;
struct V_107 V_108 ;
F_3 ( V_21 -> V_2 , V_8 , & V_5 ) ;
if ( F_88 ( V_21 -> V_12 -> V_109 , & V_5 , V_24 , & V_60 ) )
return;
V_65 = F_89 ( V_21 -> V_2 , V_8 , 1 , & V_108 ) ;
switch ( V_65 ) {
case 0 :
F_90 ( V_60 , V_24 ) ;
if ( V_108 . V_110 )
F_92 ( V_21 , V_24 , V_8 , & V_108 ) ;
else
F_37 ( V_21 , V_24 , V_108 . V_8 ) ;
break;
case - V_114 :
if ( F_62 ( V_24 ) == V_117 && V_21 -> V_41 ) {
F_90 ( V_60 , V_24 ) ;
F_36 ( V_21 , V_24 ) ;
} else
F_94 ( V_21 , V_24 , V_8 , V_60 ) ;
break;
default:
F_52 ( L_10 , V_65 ) ;
F_90 ( V_60 , V_24 ) ;
F_35 ( V_24 ) ;
break;
}
}
static void F_97 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
int V_65 ;
int V_118 = F_62 ( V_24 ) ;
T_1 V_8 = F_26 ( V_21 , V_24 ) ;
struct V_107 V_108 ;
V_65 = F_89 ( V_21 -> V_2 , V_8 , 1 , & V_108 ) ;
switch ( V_65 ) {
case 0 :
if ( V_108 . V_110 && ( V_118 == V_76 ) && V_24 -> V_74 )
F_35 ( V_24 ) ;
else
F_37 ( V_21 , V_24 , V_108 . V_8 ) ;
break;
case - V_114 :
if ( V_118 != V_117 ) {
F_35 ( V_24 ) ;
break;
}
if ( V_21 -> V_41 ) {
F_36 ( V_21 , V_24 ) ;
break;
}
F_95 ( V_24 ) ;
F_21 ( V_24 , 0 ) ;
break;
default:
F_52 ( L_10 , V_65 ) ;
F_35 ( V_24 ) ;
break;
}
}
static void F_98 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
F_35 ( V_24 ) ;
}
static int F_99 ( struct V_12 * V_12 )
{
return V_119 < V_12 -> V_120 ||
V_119 > V_12 -> V_120 + V_121 ;
}
static void F_100 ( struct V_12 * V_12 )
{
unsigned long V_30 ;
struct V_24 * V_24 ;
struct V_22 V_25 ;
F_17 ( & V_25 ) ;
F_24 ( & V_12 -> V_31 , V_30 ) ;
F_18 ( & V_25 , & V_12 -> V_32 ) ;
F_17 ( & V_12 -> V_32 ) ;
F_25 ( & V_12 -> V_31 , V_30 ) ;
while ( ( V_24 = F_19 ( & V_25 ) ) ) {
struct V_26 * V_27 = F_20 ( V_24 ) -> V_28 ;
struct V_20 * V_21 = V_27 -> V_21 ;
if ( F_64 ( V_12 ) ) {
F_24 ( & V_12 -> V_31 , V_30 ) ;
F_18 ( & V_12 -> V_32 , & V_25 ) ;
F_25 ( & V_12 -> V_31 , V_30 ) ;
break;
}
if ( V_24 -> V_42 & V_122 )
V_12 -> F_87 ( V_21 , V_24 ) ;
else
V_12 -> F_96 ( V_21 , V_24 ) ;
}
F_17 ( & V_25 ) ;
F_24 ( & V_12 -> V_31 , V_30 ) ;
F_18 ( & V_25 , & V_12 -> V_45 ) ;
F_17 ( & V_12 -> V_45 ) ;
F_25 ( & V_12 -> V_31 , V_30 ) ;
if ( F_101 ( & V_25 ) && ! F_99 ( V_12 ) )
return;
if ( F_76 ( V_12 ) ) {
while ( ( V_24 = F_19 ( & V_25 ) ) )
F_35 ( V_24 ) ;
return;
}
V_12 -> V_120 = V_119 ;
while ( ( V_24 = F_19 ( & V_25 ) ) )
F_33 ( V_24 ) ;
}
static void F_102 ( struct V_123 * V_124 )
{
struct V_12 * V_12 = F_103 ( V_124 , struct V_12 , V_47 ) ;
F_57 ( V_12 , & V_12 -> V_52 , & V_12 -> F_50 ) ;
F_57 ( V_12 , & V_12 -> V_113 , & V_12 -> F_55 ) ;
F_100 ( V_12 ) ;
}
static void F_104 ( struct V_123 * V_124 )
{
struct V_12 * V_12 = F_103 ( F_105 ( V_124 ) , struct V_12 , V_125 ) ;
F_38 ( V_12 ) ;
F_106 ( V_12 -> V_46 , & V_12 -> V_125 , V_121 ) ;
}
static enum V_126 F_77 ( struct V_12 * V_12 )
{
return V_12 -> V_92 . V_127 ;
}
static void F_78 ( struct V_12 * V_12 , enum V_126 V_127 )
{
int V_65 ;
V_12 -> V_92 . V_127 = V_127 ;
switch ( V_127 ) {
case V_128 :
F_52 ( L_11 ) ;
V_12 -> F_96 = F_98 ;
V_12 -> F_87 = F_98 ;
V_12 -> F_50 = F_47 ;
V_12 -> F_55 = F_53 ;
break;
case V_97 :
F_52 ( L_12 ) ;
V_65 = F_107 ( V_12 -> V_94 ) ;
if ( V_65 ) {
F_52 ( L_13 ) ;
F_78 ( V_12 , V_128 ) ;
} else {
F_108 ( V_12 -> V_94 ) ;
V_12 -> F_96 = F_97 ;
V_12 -> F_87 = F_87 ;
V_12 -> F_50 = F_47 ;
V_12 -> F_55 = F_54 ;
}
break;
case V_95 :
V_12 -> F_96 = F_96 ;
V_12 -> F_87 = F_87 ;
V_12 -> F_50 = F_50 ;
V_12 -> F_55 = F_55 ;
break;
}
}
static void F_109 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
unsigned long V_30 ;
struct V_12 * V_12 = V_21 -> V_12 ;
F_24 ( & V_12 -> V_31 , V_30 ) ;
F_22 ( & V_12 -> V_32 , V_24 ) ;
F_25 ( & V_12 -> V_31 , V_30 ) ;
F_38 ( V_12 ) ;
}
static struct V_26 * F_110 ( struct V_20 * V_21 , struct V_24 * V_24 )
{
struct V_12 * V_12 = V_21 -> V_12 ;
struct V_26 * V_27 = F_65 ( V_12 -> V_129 , V_130 ) ;
V_27 -> V_21 = V_21 ;
V_27 -> V_116 = NULL ;
V_27 -> V_131 = V_24 -> V_42 & V_122 ? NULL : F_93 ( V_12 -> V_112 ) ;
V_27 -> V_58 = NULL ;
return V_27 ;
}
static int F_111 ( struct V_132 * V_102 , struct V_24 * V_24 ,
union V_133 * V_134 )
{
int V_65 ;
struct V_20 * V_21 = V_102 -> V_135 ;
T_1 V_8 = F_26 ( V_21 , V_24 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_107 V_98 ;
V_134 -> V_28 = F_110 ( V_21 , V_24 ) ;
if ( F_77 ( V_21 -> V_12 ) == V_128 ) {
F_35 ( V_24 ) ;
return V_136 ;
}
if ( V_24 -> V_42 & ( V_122 | V_43 | V_44 ) ) {
F_109 ( V_21 , V_24 ) ;
return V_136 ;
}
V_65 = F_89 ( V_2 , V_8 , 0 , & V_98 ) ;
switch ( V_65 ) {
case 0 :
if ( F_112 ( V_98 . V_110 ) ) {
F_109 ( V_21 , V_24 ) ;
V_65 = V_136 ;
} else {
F_28 ( V_21 , V_24 , V_98 . V_8 ) ;
V_65 = V_137 ;
}
break;
case - V_114 :
if ( F_77 ( V_21 -> V_12 ) == V_97 ) {
F_35 ( V_24 ) ;
V_65 = V_136 ;
break;
}
case - V_138 :
F_109 ( V_21 , V_24 ) ;
V_65 = V_136 ;
break;
default:
F_35 ( V_24 ) ;
V_65 = V_136 ;
break;
}
return V_65 ;
}
static int F_113 ( struct V_139 * V_140 , int V_141 )
{
int V_65 ;
unsigned long V_30 ;
struct V_142 * V_143 = F_103 ( V_140 , struct V_142 , V_144 ) ;
F_24 ( & V_143 -> V_12 -> V_31 , V_30 ) ;
V_65 = ! F_101 ( & V_143 -> V_12 -> V_33 ) ;
F_25 ( & V_143 -> V_12 -> V_31 , V_30 ) ;
if ( ! V_65 ) {
struct V_145 * V_146 = F_114 ( V_143 -> V_147 -> V_40 ) ;
V_65 = F_115 ( & V_146 -> V_148 , V_141 ) ;
}
return V_65 ;
}
static void F_116 ( struct V_12 * V_12 )
{
F_18 ( & V_12 -> V_32 , & V_12 -> V_33 ) ;
F_17 ( & V_12 -> V_33 ) ;
}
static bool F_117 ( struct V_142 * V_143 )
{
struct V_145 * V_146 = F_114 ( V_143 -> V_147 -> V_40 ) ;
return V_146 && F_118 ( V_146 ) ;
}
static void F_119 ( struct V_142 * V_143 )
{
struct V_12 * V_12 = V_143 -> V_12 ;
struct V_18 * V_149 = V_143 -> V_147 -> V_40 ;
struct V_150 * V_151 = & F_114 ( V_149 ) -> V_152 ;
T_2 V_153 = V_12 -> V_37 << V_75 ;
const char * V_154 = NULL ;
char V_155 [ V_156 ] ;
if ( ! V_143 -> V_157 . V_111 )
return;
if ( ! F_117 ( V_143 ) )
V_154 = L_14 ;
else if ( V_151 -> V_158 < V_12 -> V_37 )
V_154 = L_15 ;
else if ( V_151 -> V_159 > V_153 )
V_154 = L_16 ;
else if ( V_153 & ( V_151 -> V_159 - 1 ) )
V_154 = L_17 ;
if ( V_154 ) {
F_81 ( L_18 , F_120 ( V_149 , V_155 ) , V_154 ) ;
V_143 -> V_157 . V_111 = false ;
}
}
static int F_121 ( struct V_12 * V_12 , struct V_132 * V_102 )
{
struct V_142 * V_143 = V_102 -> V_135 ;
enum V_126 V_160 = V_12 -> V_92 . V_127 ;
enum V_126 V_161 = V_143 -> V_157 . V_127 ;
if ( V_160 > V_161 )
V_161 = V_160 ;
V_12 -> V_102 = V_102 ;
V_12 -> V_100 = V_143 -> V_100 ;
V_12 -> V_92 = V_143 -> V_157 ;
F_78 ( V_12 , V_161 ) ;
return 0 ;
}
static void F_122 ( struct V_12 * V_12 , struct V_132 * V_102 )
{
if ( V_12 -> V_102 == V_102 )
V_12 -> V_102 = NULL ;
}
static void F_123 ( struct V_162 * V_92 )
{
V_92 -> V_127 = V_95 ;
V_92 -> V_93 = true ;
V_92 -> V_163 = true ;
V_92 -> V_111 = true ;
}
static void F_124 ( struct V_12 * V_12 )
{
F_11 ( V_12 ) ;
if ( F_125 ( V_12 -> V_94 ) < 0 )
F_81 ( L_19 , V_115 ) ;
F_126 ( V_12 -> V_109 ) ;
F_127 ( V_12 -> V_91 ) ;
if ( V_12 -> V_46 )
F_128 ( V_12 -> V_46 ) ;
if ( V_12 -> V_78 )
F_49 ( V_12 -> V_78 , V_12 -> V_64 ) ;
F_129 ( V_12 -> V_64 ) ;
F_129 ( V_12 -> V_129 ) ;
F_130 ( V_12 -> V_85 ) ;
F_130 ( V_12 -> V_112 ) ;
F_131 ( V_12 ) ;
}
static struct V_12 * F_132 ( struct V_14 * V_17 ,
struct V_18 * V_164 ,
unsigned long V_153 ,
int V_165 , char * * error )
{
int V_65 ;
void * V_166 ;
struct V_12 * V_12 ;
struct V_167 * V_94 ;
bool V_168 = V_165 ? false : true ;
V_94 = F_133 ( V_164 , V_153 , V_168 ) ;
if ( F_134 ( V_94 ) ) {
* error = L_20 ;
return (struct V_12 * ) V_94 ;
}
V_12 = F_135 ( sizeof( * V_12 ) , V_169 ) ;
if ( ! V_12 ) {
* error = L_21 ;
V_166 = F_136 ( - V_80 ) ;
goto V_170;
}
V_12 -> V_94 = V_94 ;
V_12 -> V_37 = V_153 ;
if ( V_153 & ( V_153 - 1 ) )
V_12 -> V_36 = - 1 ;
else
V_12 -> V_36 = F_137 ( V_153 ) ;
V_12 -> V_100 = 0 ;
F_123 ( & V_12 -> V_92 ) ;
V_12 -> V_109 = F_138 ( V_171 ) ;
if ( ! V_12 -> V_109 ) {
* error = L_22 ;
V_166 = F_136 ( - V_80 ) ;
goto V_172;
}
V_12 -> V_91 = F_139 () ;
if ( F_134 ( V_12 -> V_91 ) ) {
V_65 = F_140 ( V_12 -> V_91 ) ;
* error = L_23 ;
V_166 = F_136 ( V_65 ) ;
goto V_173;
}
V_12 -> V_46 = F_141 ( L_24 V_174 , V_175 ) ;
if ( ! V_12 -> V_46 ) {
* error = L_25 ;
V_166 = F_136 ( - V_80 ) ;
goto V_176;
}
F_142 ( & V_12 -> V_47 , F_102 ) ;
F_143 ( & V_12 -> V_125 , F_104 ) ;
F_144 ( & V_12 -> V_31 ) ;
F_17 ( & V_12 -> V_32 ) ;
F_17 ( & V_12 -> V_45 ) ;
F_6 ( & V_12 -> V_52 ) ;
F_6 ( & V_12 -> V_113 ) ;
V_12 -> V_101 = 0 ;
V_12 -> V_104 = 0 ;
F_17 ( & V_12 -> V_33 ) ;
V_12 -> V_85 = F_145 () ;
if ( ! V_12 -> V_85 ) {
* error = L_26 ;
V_166 = F_136 ( - V_80 ) ;
goto V_177;
}
V_12 -> V_112 = F_145 () ;
if ( ! V_12 -> V_112 ) {
* error = L_27 ;
V_166 = F_136 ( - V_80 ) ;
goto V_178;
}
V_12 -> V_78 = NULL ;
V_12 -> V_64 = F_146 ( V_179 ,
V_180 ) ;
if ( ! V_12 -> V_64 ) {
* error = L_28 ;
V_166 = F_136 ( - V_80 ) ;
goto V_181;
}
V_12 -> V_129 = F_146 ( V_182 ,
V_183 ) ;
if ( ! V_12 -> V_129 ) {
* error = L_29 ;
V_166 = F_136 ( - V_80 ) ;
goto V_184;
}
V_12 -> V_185 = 1 ;
V_12 -> V_120 = V_119 ;
V_12 -> V_17 = V_17 ;
V_12 -> V_19 = V_164 ;
F_7 ( V_12 ) ;
return V_12 ;
V_184:
F_129 ( V_12 -> V_64 ) ;
V_181:
F_130 ( V_12 -> V_112 ) ;
V_178:
F_130 ( V_12 -> V_85 ) ;
V_177:
F_128 ( V_12 -> V_46 ) ;
V_176:
F_127 ( V_12 -> V_91 ) ;
V_173:
F_126 ( V_12 -> V_109 ) ;
V_172:
F_131 ( V_12 ) ;
V_170:
if ( F_125 ( V_94 ) )
F_81 ( L_19 , V_115 ) ;
return V_166 ;
}
static void F_147 ( struct V_12 * V_12 )
{
F_8 ( ! F_9 ( & V_9 . V_10 ) ) ;
V_12 -> V_185 ++ ;
}
static void F_148 ( struct V_12 * V_12 )
{
F_8 ( ! F_9 ( & V_9 . V_10 ) ) ;
F_8 ( ! V_12 -> V_185 ) ;
if ( ! -- V_12 -> V_185 )
F_124 ( V_12 ) ;
}
static struct V_12 * F_149 ( struct V_14 * V_17 ,
struct V_18 * V_164 ,
unsigned long V_153 , int V_165 ,
char * * error , int * V_186 )
{
struct V_12 * V_12 = F_15 ( V_164 ) ;
if ( V_12 ) {
if ( V_12 -> V_17 != V_17 ) {
* error = L_30 ;
return F_136 ( - V_187 ) ;
}
F_147 ( V_12 ) ;
} else {
V_12 = F_13 ( V_17 ) ;
if ( V_12 ) {
if ( V_12 -> V_19 != V_164 ) {
* error = L_31 ;
return F_136 ( - V_96 ) ;
}
F_147 ( V_12 ) ;
} else {
V_12 = F_132 ( V_17 , V_164 , V_153 , V_165 , error ) ;
* V_186 = 1 ;
}
}
return V_12 ;
}
static void F_150 ( struct V_132 * V_102 )
{
struct V_142 * V_143 = V_102 -> V_135 ;
F_151 ( & V_9 . V_10 ) ;
F_122 ( V_143 -> V_12 , V_102 ) ;
F_148 ( V_143 -> V_12 ) ;
F_152 ( V_102 , V_143 -> V_164 ) ;
F_152 ( V_102 , V_143 -> V_147 ) ;
F_131 ( V_143 ) ;
F_153 ( & V_9 . V_10 ) ;
}
static int F_154 ( struct V_188 * V_189 , struct V_162 * V_92 ,
struct V_132 * V_102 )
{
int V_65 ;
unsigned V_190 ;
const char * V_191 ;
static struct V_192 V_193 [] = {
{ 0 , 3 , L_32 } ,
} ;
if ( ! V_189 -> V_190 )
return 0 ;
V_65 = F_155 ( V_193 , V_189 , & V_190 , & V_102 -> error ) ;
if ( V_65 )
return - V_96 ;
while ( V_190 && ! V_65 ) {
V_191 = F_156 ( V_189 ) ;
V_190 -- ;
if ( ! strcasecmp ( V_191 , L_33 ) )
V_92 -> V_93 = false ;
else if ( ! strcasecmp ( V_191 , L_34 ) )
V_92 -> V_163 = false ;
else if ( ! strcasecmp ( V_191 , L_35 ) )
V_92 -> V_111 = false ;
else if ( ! strcasecmp ( V_191 , L_36 ) )
V_92 -> V_127 = V_97 ;
else {
V_102 -> error = L_37 ;
V_65 = - V_96 ;
break;
}
}
return V_65 ;
}
static int F_157 ( struct V_132 * V_102 , unsigned V_190 , char * * V_194 )
{
int V_65 , V_195 = 0 ;
struct V_142 * V_143 ;
struct V_12 * V_12 ;
struct V_162 V_92 ;
struct V_188 V_189 ;
struct V_81 * V_147 ;
unsigned long V_153 ;
T_1 V_100 ;
struct V_81 * V_164 ;
T_2 V_196 ;
char V_3 [ V_156 ] ;
F_151 ( & V_9 . V_10 ) ;
if ( V_190 < 4 ) {
V_102 -> error = L_38 ;
V_65 = - V_96 ;
goto V_197;
}
V_189 . V_190 = V_190 ;
V_189 . V_194 = V_194 ;
V_65 = F_158 ( V_102 , V_194 [ 0 ] , V_198 | V_199 , & V_164 ) ;
if ( V_65 ) {
V_102 -> error = L_39 ;
goto V_197;
}
V_196 = F_159 ( V_164 -> V_40 -> V_200 ) >> V_75 ;
if ( V_196 > V_201 )
F_81 ( L_40 ,
F_120 ( V_164 -> V_40 , V_3 ) , V_202 ) ;
V_65 = F_158 ( V_102 , V_194 [ 1 ] , V_198 | V_199 , & V_147 ) ;
if ( V_65 ) {
V_102 -> error = L_41 ;
goto V_203;
}
if ( F_160 ( V_194 [ 2 ] , 10 , & V_153 ) || ! V_153 ||
V_153 < V_204 ||
V_153 > V_205 ||
V_153 & ( V_204 - 1 ) ) {
V_102 -> error = L_42 ;
V_65 = - V_96 ;
goto V_66;
}
if ( F_161 ( V_194 [ 3 ] , 10 , ( unsigned long long * ) & V_100 ) ) {
V_102 -> error = L_43 ;
V_65 = - V_96 ;
goto V_66;
}
F_123 ( & V_92 ) ;
F_162 ( & V_189 , 4 ) ;
V_65 = F_154 ( & V_189 , & V_92 , V_102 ) ;
if ( V_65 )
goto V_66;
V_143 = F_163 ( sizeof( * V_143 ) , V_169 ) ;
if ( ! V_143 ) {
V_65 = - V_80 ;
goto V_66;
}
V_12 = F_149 ( F_164 ( V_102 -> V_103 ) , V_164 -> V_40 ,
V_153 , V_92 . V_127 == V_97 , & V_102 -> error , & V_195 ) ;
if ( F_134 ( V_12 ) ) {
V_65 = F_140 ( V_12 ) ;
goto V_206;
}
if ( ! V_195 && V_92 . V_163 != V_12 -> V_92 . V_163 ) {
V_102 -> error = L_44 ;
V_65 = - V_96 ;
goto V_207;
}
V_143 -> V_12 = V_12 ;
V_143 -> V_102 = V_102 ;
V_143 -> V_164 = V_164 ;
V_143 -> V_147 = V_147 ;
V_143 -> V_100 = V_100 ;
V_143 -> V_157 = V_143 -> V_208 = V_92 ;
V_102 -> V_209 = 1 ;
if ( V_92 . V_163 && V_92 . V_111 ) {
V_102 -> V_210 = 1 ;
V_102 -> V_211 = true ;
V_102 -> V_212 = true ;
}
V_102 -> V_135 = V_143 ;
V_143 -> V_144 . V_213 = F_113 ;
F_165 ( V_102 -> V_103 , & V_143 -> V_144 ) ;
F_153 ( & V_9 . V_10 ) ;
return 0 ;
V_207:
F_148 ( V_12 ) ;
V_206:
F_131 ( V_143 ) ;
V_66:
F_152 ( V_102 , V_147 ) ;
V_203:
F_152 ( V_102 , V_164 ) ;
V_197:
F_153 ( & V_9 . V_10 ) ;
return V_65 ;
}
static int F_166 ( struct V_132 * V_102 , struct V_24 * V_24 ,
union V_133 * V_134 )
{
int V_65 ;
struct V_142 * V_143 = V_102 -> V_135 ;
struct V_12 * V_12 = V_143 -> V_12 ;
unsigned long V_30 ;
F_24 ( & V_12 -> V_31 , V_30 ) ;
V_24 -> V_38 = V_143 -> V_147 -> V_40 ;
V_65 = V_137 ;
F_25 ( & V_12 -> V_31 , V_30 ) ;
return V_65 ;
}
static int F_167 ( struct V_132 * V_102 )
{
int V_65 ;
struct V_142 * V_143 = V_102 -> V_135 ;
struct V_12 * V_12 = V_143 -> V_12 ;
T_2 V_214 = V_102 -> V_215 ;
T_1 V_216 ;
V_65 = F_121 ( V_12 , V_102 ) ;
if ( V_65 )
return V_65 ;
( void ) F_27 ( V_214 , V_12 -> V_37 ) ;
V_65 = F_168 ( V_12 -> V_94 , & V_216 ) ;
if ( V_65 ) {
F_52 ( L_45 ) ;
return V_65 ;
}
if ( V_214 < V_216 ) {
F_52 ( L_46 ,
( unsigned long long ) V_214 , V_216 ) ;
return - V_96 ;
} else if ( V_214 > V_216 ) {
V_65 = F_169 ( V_12 -> V_94 , V_214 ) ;
if ( V_65 ) {
F_52 ( L_47 ) ;
F_78 ( V_12 , V_97 ) ;
return V_65 ;
}
( void ) F_76 ( V_12 ) ;
}
return 0 ;
}
static void F_170 ( struct V_132 * V_102 )
{
struct V_142 * V_143 = V_102 -> V_135 ;
struct V_12 * V_12 = V_143 -> V_12 ;
unsigned long V_30 ;
F_24 ( & V_12 -> V_31 , V_30 ) ;
V_12 -> V_101 = 0 ;
V_12 -> V_104 = 0 ;
F_116 ( V_12 ) ;
F_25 ( & V_12 -> V_31 , V_30 ) ;
F_104 ( & V_12 -> V_125 . V_217 ) ;
}
static void F_171 ( struct V_132 * V_102 )
{
struct V_142 * V_143 = V_102 -> V_135 ;
struct V_12 * V_12 = V_143 -> V_12 ;
F_172 ( & V_12 -> V_125 ) ;
F_173 ( V_12 -> V_46 ) ;
( void ) F_76 ( V_12 ) ;
}
static int F_174 ( unsigned V_190 , unsigned V_218 )
{
if ( V_190 != V_218 ) {
F_81 ( L_48 ,
V_190 , V_218 ) ;
return - V_96 ;
}
return 0 ;
}
static int F_175 ( char * V_219 , T_5 * V_220 , int V_221 )
{
if ( ! F_161 ( V_219 , 10 , ( unsigned long long * ) V_220 ) &&
* V_220 <= V_222 )
return 0 ;
if ( V_221 )
F_81 ( L_49 , V_219 ) ;
return - V_96 ;
}
static int F_176 ( unsigned V_190 , char * * V_194 , struct V_12 * V_12 )
{
T_5 V_220 ;
int V_65 ;
V_65 = F_174 ( V_190 , 2 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_175 ( V_194 [ 1 ] , & V_220 , 1 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_177 ( V_12 -> V_94 , V_220 ) ;
if ( V_65 ) {
F_81 ( L_50 ,
V_194 [ 1 ] ) ;
return V_65 ;
}
return 0 ;
}
static int F_178 ( unsigned V_190 , char * * V_194 , struct V_12 * V_12 )
{
T_5 V_220 ;
T_5 V_223 ;
int V_65 ;
V_65 = F_174 ( V_190 , 3 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_175 ( V_194 [ 1 ] , & V_220 , 1 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_175 ( V_194 [ 2 ] , & V_223 , 1 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_179 ( V_12 -> V_94 , V_220 , V_223 ) ;
if ( V_65 ) {
F_81 ( L_51 ,
V_194 [ 1 ] , V_194 [ 2 ] ) ;
return V_65 ;
}
return 0 ;
}
static int F_180 ( unsigned V_190 , char * * V_194 , struct V_12 * V_12 )
{
T_5 V_220 ;
int V_65 ;
V_65 = F_174 ( V_190 , 2 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_175 ( V_194 [ 1 ] , & V_220 , 1 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_181 ( V_12 -> V_94 , V_220 ) ;
if ( V_65 )
F_81 ( L_52 , V_194 [ 1 ] ) ;
return V_65 ;
}
static int F_182 ( unsigned V_190 , char * * V_194 , struct V_12 * V_12 )
{
T_5 V_224 , V_225 ;
int V_65 ;
V_65 = F_174 ( V_190 , 3 ) ;
if ( V_65 )
return V_65 ;
if ( F_161 ( V_194 [ 1 ] , 10 , ( unsigned long long * ) & V_224 ) ) {
F_81 ( L_53 , V_194 [ 1 ] ) ;
return - V_96 ;
}
if ( F_161 ( V_194 [ 2 ] , 10 , ( unsigned long long * ) & V_225 ) ) {
F_81 ( L_54 , V_194 [ 2 ] ) ;
return - V_96 ;
}
V_65 = F_183 ( V_12 -> V_94 , V_224 , V_225 ) ;
if ( V_65 ) {
F_81 ( L_55 ,
V_194 [ 1 ] , V_194 [ 2 ] ) ;
return V_65 ;
}
return 0 ;
}
static int F_184 ( unsigned V_190 , char * * V_194 , struct V_12 * V_12 )
{
int V_65 ;
V_65 = F_174 ( V_190 , 1 ) ;
if ( V_65 )
return V_65 ;
( void ) F_76 ( V_12 ) ;
V_65 = F_185 ( V_12 -> V_94 ) ;
if ( V_65 )
F_81 ( L_56 ) ;
return V_65 ;
}
static int F_186 ( unsigned V_190 , char * * V_194 , struct V_12 * V_12 )
{
int V_65 ;
V_65 = F_174 ( V_190 , 1 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_187 ( V_12 -> V_94 ) ;
if ( V_65 )
F_81 ( L_57 ) ;
return V_65 ;
}
static int F_188 ( struct V_132 * V_102 , unsigned V_190 , char * * V_194 )
{
int V_65 = - V_96 ;
struct V_142 * V_143 = V_102 -> V_135 ;
struct V_12 * V_12 = V_143 -> V_12 ;
if ( ! strcasecmp ( V_194 [ 0 ] , L_58 ) )
V_65 = F_176 ( V_190 , V_194 , V_12 ) ;
else if ( ! strcasecmp ( V_194 [ 0 ] , L_59 ) )
V_65 = F_178 ( V_190 , V_194 , V_12 ) ;
else if ( ! strcasecmp ( V_194 [ 0 ] , L_60 ) )
V_65 = F_180 ( V_190 , V_194 , V_12 ) ;
else if ( ! strcasecmp ( V_194 [ 0 ] , L_61 ) )
V_65 = F_182 ( V_190 , V_194 , V_12 ) ;
else if ( ! strcasecmp ( V_194 [ 0 ] , L_62 ) )
V_65 = F_184 ( V_190 , V_194 , V_12 ) ;
else if ( ! strcasecmp ( V_194 [ 0 ] , L_63 ) )
V_65 = F_186 ( V_190 , V_194 , V_12 ) ;
else
F_81 ( L_64 , V_194 [ 0 ] ) ;
if ( ! V_65 )
( void ) F_76 ( V_12 ) ;
return V_65 ;
}
static void F_189 ( struct V_162 * V_92 , char * V_98 ,
unsigned V_226 , unsigned V_227 )
{
unsigned V_90 = ! V_92 -> V_93 + ! V_92 -> V_163 +
! V_92 -> V_111 + ( V_92 -> V_127 == V_97 ) ;
F_190 ( L_65 , V_90 ) ;
if ( ! V_92 -> V_93 )
F_190 ( L_66 ) ;
if ( ! V_92 -> V_163 )
F_190 ( L_67 ) ;
if ( ! V_92 -> V_111 )
F_190 ( L_68 ) ;
if ( V_92 -> V_127 == V_97 )
F_190 ( L_69 ) ;
}
static int F_191 ( struct V_132 * V_102 , T_6 type ,
unsigned V_228 , char * V_98 , unsigned V_227 )
{
int V_65 ;
unsigned V_226 = 0 ;
T_7 V_229 ;
T_1 V_230 ;
T_1 V_231 ;
T_1 V_232 ;
T_1 V_233 ;
T_1 V_234 ;
char V_155 [ V_156 ] ;
char V_235 [ V_156 ] ;
struct V_142 * V_143 = V_102 -> V_135 ;
struct V_12 * V_12 = V_143 -> V_12 ;
switch ( type ) {
case V_236 :
if ( F_77 ( V_12 ) == V_128 ) {
F_190 ( L_70 ) ;
break;
}
if ( ! ( V_228 & V_237 ) && ! F_192 ( V_102 ) )
( void ) F_76 ( V_12 ) ;
V_65 = F_193 ( V_12 -> V_94 ,
& V_229 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_194 ( V_12 -> V_94 ,
& V_231 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_195 ( V_12 -> V_94 , & V_233 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_80 ( V_12 -> V_94 ,
& V_230 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_168 ( V_12 -> V_94 , & V_232 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_196 ( V_12 -> V_94 , & V_234 ) ;
if ( V_65 )
return V_65 ;
F_190 ( L_71 ,
( unsigned long long ) V_229 ,
( unsigned long long ) ( V_233 - V_231 ) ,
( unsigned long long ) V_233 ,
( unsigned long long ) ( V_232 - V_230 ) ,
( unsigned long long ) V_232 ) ;
if ( V_234 )
F_190 ( L_72 , V_234 ) ;
else
F_190 ( L_73 ) ;
if ( V_12 -> V_92 . V_127 == V_97 )
F_190 ( L_74 ) ;
else
F_190 ( L_75 ) ;
if ( V_12 -> V_92 . V_163 && V_12 -> V_92 . V_111 )
F_190 ( L_76 ) ;
else
F_190 ( L_35 ) ;
break;
case V_238 :
F_190 ( L_77 ,
F_197 ( V_155 , V_143 -> V_164 -> V_40 -> V_239 ) ,
F_197 ( V_235 , V_143 -> V_147 -> V_40 -> V_239 ) ,
( unsigned long ) V_12 -> V_37 ,
( unsigned long long ) V_143 -> V_100 ) ;
F_189 ( & V_143 -> V_208 , V_98 , V_226 , V_227 ) ;
break;
}
return 0 ;
}
static int F_198 ( struct V_132 * V_102 ,
T_8 V_72 , void * V_240 )
{
struct V_142 * V_143 = V_102 -> V_135 ;
return V_72 ( V_102 , V_143 -> V_147 , 0 , V_102 -> V_215 , V_240 ) ;
}
static int F_199 ( struct V_132 * V_102 , struct V_241 * V_242 ,
struct V_243 * V_244 , int V_245 )
{
struct V_142 * V_143 = V_102 -> V_135 ;
struct V_145 * V_146 = F_114 ( V_143 -> V_147 -> V_40 ) ;
if ( ! V_146 -> V_246 )
return V_245 ;
V_242 -> V_38 = V_143 -> V_147 -> V_40 ;
return F_200 ( V_245 , V_146 -> V_246 ( V_146 , V_242 , V_244 ) ) ;
}
static bool F_201 ( struct V_12 * V_12 )
{
return V_12 -> V_36 >= 0 ;
}
static void F_202 ( struct V_142 * V_143 , struct V_150 * V_152 )
{
struct V_12 * V_12 = V_143 -> V_12 ;
struct V_150 * V_151 ;
V_152 -> V_158 = V_12 -> V_37 ;
if ( V_143 -> V_157 . V_111 ) {
V_151 = & F_114 ( V_143 -> V_147 -> V_40 ) -> V_152 ;
V_152 -> V_159 = V_151 -> V_159 ;
} else if ( F_201 ( V_12 ) )
V_152 -> V_159 = V_12 -> V_37 << V_75 ;
else
V_152 -> V_159 = F_203 ( 1 << ( F_204 ( V_12 -> V_37 ) - 1 ) ,
V_204 ) << V_75 ;
}
static void F_205 ( struct V_132 * V_102 , struct V_150 * V_152 )
{
struct V_142 * V_143 = V_102 -> V_135 ;
struct V_12 * V_12 = V_143 -> V_12 ;
F_206 ( V_152 , 0 ) ;
F_207 ( V_152 , V_12 -> V_37 << V_75 ) ;
if ( ! V_143 -> V_157 . V_163 )
return;
F_119 ( V_143 ) ;
F_202 ( V_143 , V_152 ) ;
}
static void F_208 ( struct V_132 * V_102 )
{
struct V_20 * V_21 = V_102 -> V_135 ;
F_151 ( & V_9 . V_10 ) ;
F_148 ( V_21 -> V_12 ) ;
F_209 ( V_21 -> V_2 ) ;
F_152 ( V_102 , V_21 -> V_39 ) ;
if ( V_21 -> V_41 )
F_152 ( V_102 , V_21 -> V_41 ) ;
F_131 ( V_21 ) ;
F_153 ( & V_9 . V_10 ) ;
}
static int F_210 ( struct V_132 * V_102 , unsigned V_190 , char * * V_194 )
{
int V_65 ;
struct V_20 * V_21 ;
struct V_81 * V_39 , * V_41 ;
struct V_14 * V_17 ;
F_151 ( & V_9 . V_10 ) ;
if ( V_190 != 2 && V_190 != 3 ) {
V_102 -> error = L_38 ;
V_65 = - V_96 ;
goto V_197;
}
V_21 = V_102 -> V_135 = F_163 ( sizeof( * V_21 ) , V_169 ) ;
if ( ! V_21 ) {
V_102 -> error = L_78 ;
V_65 = - V_80 ;
goto V_197;
}
if ( V_190 == 3 ) {
V_65 = F_158 ( V_102 , V_194 [ 2 ] , V_198 , & V_41 ) ;
if ( V_65 ) {
V_102 -> error = L_79 ;
goto V_247;
}
V_21 -> V_41 = V_41 ;
}
V_65 = F_158 ( V_102 , V_194 [ 0 ] , F_211 ( V_102 -> V_103 ) , & V_39 ) ;
if ( V_65 ) {
V_102 -> error = L_80 ;
goto V_248;
}
V_21 -> V_39 = V_39 ;
if ( F_175 ( V_194 [ 1 ] , ( unsigned long long * ) & V_21 -> V_220 , 0 ) ) {
V_102 -> error = L_81 ;
V_65 = - V_96 ;
goto V_249;
}
V_17 = F_212 ( V_21 -> V_39 -> V_40 -> V_239 ) ;
if ( ! V_17 ) {
V_102 -> error = L_82 ;
V_65 = - V_96 ;
goto V_249;
}
V_21 -> V_12 = F_13 ( V_17 ) ;
if ( ! V_21 -> V_12 ) {
V_102 -> error = L_83 ;
V_65 = - V_96 ;
goto V_250;
}
F_147 ( V_21 -> V_12 ) ;
if ( F_77 ( V_21 -> V_12 ) == V_128 ) {
V_102 -> error = L_84 ;
goto V_251;
}
V_65 = F_213 ( V_21 -> V_12 -> V_94 , V_21 -> V_220 , & V_21 -> V_2 ) ;
if ( V_65 ) {
V_102 -> error = L_85 ;
goto V_251;
}
V_65 = F_214 ( V_102 , V_21 -> V_12 -> V_37 ) ;
if ( V_65 )
goto V_251;
V_102 -> V_209 = 1 ;
V_102 -> V_252 = true ;
if ( V_21 -> V_12 -> V_92 . V_163 ) {
V_102 -> V_211 = true ;
V_102 -> V_210 = 1 ;
V_102 -> V_212 = true ;
V_102 -> V_253 = true ;
}
F_215 ( V_17 ) ;
F_153 ( & V_9 . V_10 ) ;
return 0 ;
V_251:
F_148 ( V_21 -> V_12 ) ;
V_250:
F_215 ( V_17 ) ;
V_249:
F_152 ( V_102 , V_21 -> V_39 ) ;
V_248:
if ( V_21 -> V_41 )
F_152 ( V_102 , V_21 -> V_41 ) ;
V_247:
F_131 ( V_21 ) ;
V_197:
F_153 ( & V_9 . V_10 ) ;
return V_65 ;
}
static int F_216 ( struct V_132 * V_102 , struct V_24 * V_24 ,
union V_133 * V_134 )
{
V_24 -> V_35 = F_217 ( V_102 , V_24 -> V_35 ) ;
return F_111 ( V_102 , V_24 , V_134 ) ;
}
static int F_218 ( struct V_132 * V_102 ,
struct V_24 * V_24 , int V_56 ,
union V_133 * V_134 )
{
unsigned long V_30 ;
struct V_26 * V_27 = V_134 -> V_28 ;
struct V_70 V_217 ;
struct V_48 * V_49 , * V_16 ;
struct V_12 * V_12 = V_27 -> V_21 -> V_12 ;
if ( V_27 -> V_116 ) {
F_6 ( & V_217 ) ;
F_219 ( V_27 -> V_116 , & V_217 ) ;
F_24 ( & V_12 -> V_31 , V_30 ) ;
F_59 (m, tmp, &work, list) {
F_12 ( & V_49 -> V_13 ) ;
V_49 -> V_50 = 1 ;
F_40 ( V_49 ) ;
}
F_25 ( & V_12 -> V_31 , V_30 ) ;
}
if ( V_27 -> V_131 ) {
F_6 ( & V_217 ) ;
F_219 ( V_27 -> V_131 , & V_217 ) ;
F_24 ( & V_12 -> V_31 , V_30 ) ;
F_59 (m, tmp, &work, list)
F_10 ( & V_49 -> V_13 , & V_12 -> V_113 ) ;
F_25 ( & V_12 -> V_31 , V_30 ) ;
}
F_49 ( V_27 , V_12 -> V_129 ) ;
return 0 ;
}
static void F_220 ( struct V_132 * V_102 )
{
if ( F_221 ( V_102 ) )
F_23 ( (struct V_20 * ) V_102 -> V_135 ) ;
}
static int F_222 ( struct V_132 * V_102 , T_6 type ,
unsigned V_228 , char * V_98 , unsigned V_227 )
{
int V_65 ;
T_9 V_226 = 0 ;
T_1 V_254 , V_255 ;
char V_155 [ V_156 ] ;
struct V_20 * V_21 = V_102 -> V_135 ;
if ( F_77 ( V_21 -> V_12 ) == V_128 ) {
F_190 ( L_70 ) ;
return 0 ;
}
if ( ! V_21 -> V_2 )
F_190 ( L_86 ) ;
else {
switch ( type ) {
case V_236 :
V_65 = F_223 ( V_21 -> V_2 , & V_254 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_224 ( V_21 -> V_2 , & V_255 ) ;
if ( V_65 < 0 )
return V_65 ;
F_190 ( L_72 , V_254 * V_21 -> V_12 -> V_37 ) ;
if ( V_65 )
F_190 ( L_87 , ( ( V_255 + 1 ) *
V_21 -> V_12 -> V_37 ) - 1 ) ;
else
F_190 ( L_86 ) ;
break;
case V_238 :
F_190 ( L_88 ,
F_197 ( V_155 , V_21 -> V_39 -> V_40 -> V_239 ) ,
( unsigned long ) V_21 -> V_220 ) ;
if ( V_21 -> V_41 )
F_190 ( L_89 , F_197 ( V_155 , V_21 -> V_41 -> V_40 -> V_239 ) ) ;
break;
}
}
return 0 ;
}
static int F_225 ( struct V_132 * V_102 ,
T_8 V_72 , void * V_240 )
{
T_2 V_256 ;
struct V_20 * V_21 = V_102 -> V_135 ;
struct V_12 * V_12 = V_21 -> V_12 ;
if ( ! V_12 -> V_102 )
return 0 ;
V_256 = V_12 -> V_102 -> V_215 ;
( void ) F_27 ( V_256 , V_12 -> V_37 ) ;
if ( V_256 )
return V_72 ( V_102 , V_21 -> V_39 , 0 , V_12 -> V_37 * V_256 , V_240 ) ;
return 0 ;
}
static void F_226 ( struct V_132 * V_102 , struct V_150 * V_152 )
{
struct V_20 * V_21 = V_102 -> V_135 ;
* V_152 = F_114 ( V_21 -> V_39 -> V_40 ) -> V_152 ;
}
static int T_10 F_227 ( void )
{
int V_65 ;
F_4 () ;
V_65 = F_228 ( & V_257 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_228 ( & V_258 ) ;
if ( V_65 )
goto V_259;
V_65 = - V_80 ;
V_180 = F_229 ( V_48 , 0 ) ;
if ( ! V_180 )
goto V_260;
V_183 = F_229 ( V_26 , 0 ) ;
if ( ! V_183 )
goto V_261;
return 0 ;
V_261:
F_230 ( V_180 ) ;
V_260:
F_231 ( & V_258 ) ;
V_259:
F_231 ( & V_257 ) ;
return V_65 ;
}
static void F_232 ( void )
{
F_231 ( & V_257 ) ;
F_231 ( & V_258 ) ;
F_230 ( V_180 ) ;
F_230 ( V_183 ) ;
}
