static void * F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_7 , V_8 ) ;
if ( ! V_6 )
V_6 = F_3 ( - V_9 ) ;
return V_6 ;
}
static void F_4 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_10 )
{
struct V_5 * V_6 = V_10 ;
F_5 ( V_7 , V_6 ) ;
}
static void * F_6 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_12 ;
V_12 = F_2 ( V_13 , V_8 ) ;
if ( ! V_12 )
V_12 = F_3 ( - V_9 ) ;
return V_12 ;
}
static void F_7 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_10 )
{
struct V_11 * V_12 = V_10 ;
F_5 ( V_13 , V_12 ) ;
}
void * F_8 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_14 ;
V_14 = F_2 ( V_15 , V_8 ) ;
if ( ! V_14 )
V_14 = F_3 ( - V_9 ) ;
return V_14 ;
}
void F_9 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_10 )
{
struct V_5 * V_14 = V_10 ;
F_5 ( V_15 , V_14 ) ;
}
static struct V_16 * F_10 ( const struct V_17 * V_18 ,
struct V_16 * V_19 )
{
struct V_20 * V_21 = F_11 ( V_19 ) ;
struct V_22 * V_23 = F_12 ( V_19 -> V_24 ) ;
struct V_16 * V_25 = F_13 ( V_21 -> V_26 ) ;
if ( V_19 -> V_24 ) {
F_14 ( V_23 ) ;
F_15 ( V_23 ) ;
}
F_16 ( F_17 ( V_19 ) ) ;
F_15 ( V_21 ) ;
return V_25 ;
}
static struct V_16 * F_18 ( const struct V_17 * V_18 ,
struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_20 * V_21 ;
struct V_16 * V_31 ;
struct V_22 * V_23 ;
int V_32 ;
V_21 = F_19 ( sizeof( * V_21 ) , V_8 ) ;
if ( ! V_21 )
return F_3 ( - V_9 ) ;
V_31 = & V_21 -> V_33 . V_34 ;
F_20 ( & V_21 -> V_33 , V_28 ) ;
F_21 ( V_21 ) -> V_35 = & V_36 ;
V_21 -> V_33 . V_37 = & V_38 ;
V_23 = F_19 ( sizeof( * V_23 ) , V_8 ) ;
if ( V_23 ) {
V_32 = F_22 ( V_23 , & V_21 -> V_33 ) ;
if ( V_32 == 0 ) {
V_32 = F_23 ( & V_23 -> V_39 ) ;
} else {
F_24 ( ! V_31 -> V_24 ) ;
F_25 ( L_1 , V_32 ) ;
F_15 ( V_23 ) ;
}
} else {
V_32 = - V_9 ;
}
if ( V_32 != 0 ) {
F_10 ( V_18 , V_31 ) ;
V_31 = F_3 ( V_32 ) ;
}
return V_31 ;
}
static int F_26 ( const struct V_17 * V_18 , struct V_16 * V_19 ,
const char * V_40 , struct V_16 * V_25 )
{
struct V_20 * V_21 ;
int V_32 ;
V_21 = F_11 ( V_19 ) ;
V_21 -> V_26 = F_17 ( V_25 ) ;
F_24 ( V_19 -> V_24 && V_25 -> V_41 ) ;
V_25 -> V_24 = V_19 -> V_24 ;
V_32 = V_25 -> V_41 -> V_42 -> V_43 ( V_18 , V_25 ,
V_25 -> V_41 -> V_44 ,
NULL ) ;
if ( V_32 == 0 ) {
F_27 ( V_25 ) ;
F_28 ( & V_25 -> V_45 , L_2 , & V_46 ) ;
}
return V_32 ;
}
static struct V_16 * F_29 ( const struct V_17 * V_18 ,
struct V_16 * V_19 )
{
return F_13 ( F_11 ( V_19 ) -> V_26 ) ;
}
int F_30 ( void )
{
int V_32 ;
V_32 = F_31 ( V_47 ) ;
if ( V_32 != 0 )
return V_32 ;
V_32 = F_32 ( & V_48 ) ;
if ( V_32 != 0 )
goto V_49;
return 0 ;
V_49:
F_33 ( V_47 ) ;
return V_32 ;
}
void F_34 ( void )
{
F_35 ( & V_48 ) ;
F_33 ( V_47 ) ;
}
int F_36 ( struct V_50 * V_51 )
{
struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_17 * V_18 ;
int V_32 = 0 ;
int V_56 ;
V_53 = F_37 ( V_51 ) ;
V_18 = F_38 ( & V_56 ) ;
if ( ! F_39 ( V_18 ) ) {
V_55 = F_40 ( V_18 , NULL , & V_48 ,
V_53 -> V_57 -> V_58 -> V_59 ) ;
if ( ! F_39 ( V_55 ) ) {
F_41 ( V_55 ) -> V_60 = V_51 ;
V_53 -> V_61 = V_55 ;
V_53 -> V_62 = F_13 ( V_55 ) -> V_24 ;
}
F_42 ( V_18 , & V_56 ) ;
} else {
V_32 = F_43 ( V_18 ) ;
}
return V_32 ;
}
int F_44 ( struct V_50 * V_51 )
{
struct V_52 * V_53 ;
struct V_17 * V_18 ;
struct V_54 * V_63 ;
int V_56 ;
int V_64 ;
V_53 = F_37 ( V_51 ) ;
V_18 = F_38 ( & V_56 ) ;
if ( ! F_39 ( V_18 ) ) {
V_63 = V_53 -> V_61 ;
if ( V_63 ) {
F_45 ( V_18 , V_63 ) ;
V_53 -> V_61 = NULL ;
V_53 -> V_62 = NULL ;
}
F_42 ( V_18 , & V_56 ) ;
V_64 = 0 ;
} else {
F_25 ( L_3 ) ;
V_64 = F_43 ( V_18 ) ;
}
F_46 () ;
return V_64 ;
}
static void F_47 ( T_1 V_65 , struct V_66 * V_67 )
{
F_48 ( sizeof( V_65 ) == sizeof( V_68 ) ) ;
V_67 -> V_69 = V_65 & 0xffffffff ;
V_67 -> V_70 = ( V_65 >> V_71 ) & 0xf ;
V_67 -> V_72 = ( unsigned long long ) V_65 >> V_73 ;
}
static T_1 F_49 ( struct V_66 * V_67 )
{
return
( ( V_68 ) V_67 -> V_69 ) |
( ( V_68 ) V_67 -> V_70 << V_71 ) |
( ( V_68 ) V_67 -> V_72 << V_73 ) ;
}
static int F_50 ( struct V_74 * V_75 , struct V_76 * V_77 ,
struct V_78 * V_79 , void * V_10 )
{
struct V_66 * V_67 = V_10 ;
struct V_80 * V_81 = F_51 ( V_75 , V_79 ) ;
if ( V_67 -> V_82 -- > 0 )
return 0 ;
if ( F_52 ( V_81 ) )
return 1 ;
F_53 ( V_75 , V_79 ) ;
V_67 -> V_83 = V_81 ;
return 1 ;
}
static struct V_84 * F_54 ( const struct V_17 * V_18 ,
struct V_16 * V_85 ,
struct V_66 * V_67 )
{
F_24 ( F_55 ( V_85 ) ) ;
V_67 -> V_70 &= 0xf ;
V_67 -> V_83 = NULL ;
V_67 -> V_82 = V_67 -> V_70 ;
F_56 ( V_85 -> V_24 -> V_86 , V_67 -> V_72 ,
F_50 , V_67 ) ;
if ( V_67 -> V_83 ) {
struct V_87 * V_88 ;
V_88 = F_57 ( V_67 -> V_83 , V_85 -> V_41 ) ;
if ( V_88 ) {
F_58 ( V_88 , L_4 , V_89 ) ;
return F_59 ( V_88 ) ;
}
F_60 ( V_18 , F_61 ( V_67 -> V_83 ) ) ;
} else if ( V_67 -> V_82 > 0 ) {
V_67 -> V_70 = 0xf ;
}
return NULL ;
}
static T_1 F_62 ( const struct V_17 * V_18 ,
struct V_16 * V_85 , T_1 V_65 )
{
struct V_84 * V_90 ;
struct V_91 * V_23 ;
struct V_66 V_67 ;
V_23 = V_85 -> V_24 ;
F_47 ( V_65 , & V_67 ) ;
while ( 1 ) {
if ( V_67 . V_72 >= F_63 ( V_23 -> V_86 ) )
return ~ 0ULL ;
V_90 = F_54 ( V_18 , V_85 , & V_67 ) ;
if ( V_90 ) {
struct V_92 * V_92 = F_64 ( V_90 ) ;
struct V_93 * V_94 ;
int V_95 ;
V_95 = F_65 ( V_92 -> V_96 ,
V_67 . V_69 , 1 , & V_94 ) ;
if ( V_95 > 0 ) {
V_67 . V_69 = V_94 -> V_97 ;
V_95 = ! ( V_94 -> V_97 > 0xffffffff ) ;
F_66 ( V_94 ) ;
}
F_67 ( & V_90 -> V_98 , L_4 , V_89 ) ;
F_68 ( V_18 , V_90 ) ;
if ( V_95 > 0 )
return F_49 ( & V_67 ) ;
}
++ V_67 . V_70 ;
V_67 . V_70 &= 0xf ;
if ( V_67 . V_70 == 0 && ++ V_67 . V_72 == 0 )
return ~ 0ULL ;
V_67 . V_69 = 0 ;
}
}
static void F_69 ( const struct V_17 * V_18 ,
struct V_99 * V_100 , struct V_101 * V_93 )
{
struct V_102 * V_103 ;
struct V_93 * V_94 ;
int V_104 ;
V_103 = F_70 ( F_71 ( V_93 , & V_48 ) ) ;
V_94 = V_103 -> V_105 ;
F_72 ( V_100 , L_5 V_106 L_6 ,
0 ,
V_103 , V_93 ,
L_7 ,
V_103 -> V_107 ? L_8 : L_9 ,
V_103 -> V_108 ? L_10 : L_9 ,
F_73 ( V_94 ) ? L_11 : L_12 ,
V_94 , F_74 ( F_75 ( V_94 -> V_109 -> V_110 ) ) ,
V_94 -> V_109 -> V_110 , V_94 -> V_97 ,
F_76 ( V_94 ) ) ;
V_104 = 0 ;
F_77 ( V_100 , V_94 , V_111 , V_104 ) ;
F_77 ( V_100 , V_94 , error , V_104 ) ;
F_77 ( V_100 , V_94 , V_112 , V_104 ) ;
F_77 ( V_100 , V_94 , V_113 , V_104 ) ;
F_77 ( V_100 , V_94 , V_114 , V_104 ) ;
F_77 ( V_100 , V_94 , V_115 , V_104 ) ;
F_72 ( V_100 , L_13 , V_104 ? L_14 : L_12 ) ;
}
static int F_78 ( struct V_99 * V_116 , void * V_117 )
{
T_1 V_65 ;
struct V_52 * V_53 ;
struct V_84 * V_90 ;
struct V_17 * V_18 ;
struct V_66 V_67 ;
int V_56 ;
int V_64 ;
V_18 = F_38 ( & V_56 ) ;
if ( ! F_39 ( V_18 ) ) {
V_65 = * ( T_1 * ) V_117 ;
F_47 ( V_65 , & V_67 ) ;
V_53 = V_116 -> V_118 ;
V_90 = F_54 ( V_18 , & V_53 -> V_61 -> V_34 , & V_67 ) ;
if ( V_90 ) {
struct V_92 * V_92 = F_64 ( V_90 ) ;
struct V_101 * V_93 = NULL ;
struct V_93 * V_94 ;
V_64 = F_65 ( V_92 -> V_96 ,
V_67 . V_69 , 1 ,
& V_94 ) ;
if ( V_64 > 0 ) {
F_79 ( V_94 ) ;
V_93 = F_80 ( V_94 , V_90 ) ;
F_81 ( V_94 ) ;
F_66 ( V_94 ) ;
}
F_72 ( V_116 , L_15 V_106 L_16 , V_67 . V_69 ,
F_74 ( F_82 ( & V_90 -> V_98 ) ) ) ;
if ( V_93 ) {
F_69 ( V_18 , V_116 , V_93 ) ;
F_83 ( V_18 , V_93 ) ;
} else {
F_84 ( V_116 , L_17 ) ;
}
F_67 ( & V_90 -> V_98 , L_4 , V_89 ) ;
F_68 ( V_18 , V_90 ) ;
} else {
F_72 ( V_116 , L_18 , V_65 ) ;
}
F_42 ( V_18 , & V_56 ) ;
V_64 = 0 ;
} else {
V_64 = F_43 ( V_18 ) ;
}
return V_64 ;
}
static void * F_85 ( struct V_99 * V_116 , T_1 * V_65 )
{
struct V_52 * V_53 ;
struct V_17 * V_18 ;
int V_56 ;
V_53 = V_116 -> V_118 ;
V_18 = F_38 ( & V_56 ) ;
if ( ! F_39 ( V_18 ) ) {
V_53 = V_116 -> V_118 ;
if ( V_53 -> V_62 -> V_86 -> V_119 > 64 - V_73 )
V_65 = F_3 ( - V_120 ) ;
else {
* V_65 = F_62 ( V_18 , & V_53 -> V_61 -> V_34 ,
* V_65 ) ;
if ( * V_65 == ~ 0ULL )
V_65 = NULL ;
}
F_42 ( V_18 , & V_56 ) ;
}
return V_65 ;
}
static void * F_86 ( struct V_99 * V_116 , void * V_117 , T_1 * V_65 )
{
struct V_52 * V_53 ;
struct V_17 * V_18 ;
int V_56 ;
V_18 = F_38 ( & V_56 ) ;
if ( ! F_39 ( V_18 ) ) {
V_53 = V_116 -> V_118 ;
* V_65 = F_62 ( V_18 , & V_53 -> V_61 -> V_34 , * V_65 + 1 ) ;
if ( * V_65 == ~ 0ULL )
V_65 = NULL ;
F_42 ( V_18 , & V_56 ) ;
}
return V_65 ;
}
static void F_87 ( struct V_99 * V_116 , void * V_117 )
{
}
static int F_88 ( struct V_92 * V_92 , struct V_121 * V_122 )
{
struct V_99 * V_100 ;
int V_32 ;
V_32 = F_89 ( V_122 , & V_123 ) ;
if ( V_32 )
return V_32 ;
V_100 = V_122 -> V_124 ;
V_100 -> V_118 = V_92 -> V_125 ;
return 0 ;
}
