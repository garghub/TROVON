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
static void * F_8 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_14 ;
V_14 = F_2 ( V_15 , V_8 ) ;
if ( ! V_14 )
V_14 = F_3 ( - V_9 ) ;
return V_14 ;
}
static void F_9 ( const struct V_1 * V_2 ,
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
V_23 = F_19 ( sizeof( * V_23 ) , V_8 ) ;
if ( V_23 ) {
V_32 = F_22 ( V_23 , & V_21 -> V_33 ) ;
if ( V_32 == 0 ) {
V_32 = F_23 ( & V_23 -> V_37 ) ;
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
const char * V_38 , struct V_16 * V_25 )
{
struct V_20 * V_21 ;
int V_32 ;
V_21 = F_11 ( V_19 ) ;
V_21 -> V_26 = F_17 ( V_25 ) ;
F_24 ( V_19 -> V_24 && V_25 -> V_39 ) ;
V_25 -> V_24 = V_19 -> V_24 ;
V_32 = V_25 -> V_39 -> V_40 -> V_41 ( V_18 , V_25 ,
V_25 -> V_39 -> V_42 ,
NULL ) ;
if ( V_32 == 0 ) {
F_27 ( V_25 ) ;
F_28 ( & V_25 -> V_43 , L_2 , & V_44 ) ;
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
V_32 = F_31 ( V_45 ) ;
if ( V_32 != 0 )
return V_32 ;
V_32 = F_32 ( & V_46 ) ;
if ( V_32 != 0 )
goto V_47;
return 0 ;
V_47:
F_33 ( V_45 ) ;
return V_32 ;
}
void F_34 ( void )
{
F_35 ( & V_46 ) ;
F_33 ( V_45 ) ;
}
int F_36 ( struct V_48 * V_49 )
{
struct V_50 * V_51 ;
struct V_52 * V_53 ;
struct V_17 * V_18 ;
int V_32 = 0 ;
T_1 V_54 ;
V_51 = F_37 ( V_49 ) ;
V_18 = F_38 ( & V_54 ) ;
if ( ! F_39 ( V_18 ) ) {
V_53 = F_40 ( V_18 , NULL , & V_46 ,
V_51 -> V_55 -> V_56 -> V_57 ) ;
if ( ! F_39 ( V_53 ) ) {
V_51 -> V_58 = V_53 ;
V_51 -> V_59 = F_13 ( V_53 ) -> V_24 ;
}
F_41 ( V_18 , & V_54 ) ;
} else {
V_32 = F_42 ( V_18 ) ;
}
return V_32 ;
}
int F_43 ( struct V_48 * V_49 )
{
struct V_50 * V_51 ;
struct V_17 * V_18 ;
struct V_52 * V_60 ;
T_1 V_54 ;
int V_61 ;
V_51 = F_37 ( V_49 ) ;
V_18 = F_38 ( & V_54 ) ;
if ( ! F_39 ( V_18 ) ) {
V_60 = V_51 -> V_58 ;
if ( V_60 ) {
F_44 ( V_18 , V_60 ) ;
V_51 -> V_58 = NULL ;
V_51 -> V_59 = NULL ;
}
F_41 ( V_18 , & V_54 ) ;
V_61 = 0 ;
} else {
F_25 ( L_3 ) ;
V_61 = F_42 ( V_18 ) ;
}
return V_61 ;
}
static void F_45 ( T_2 V_62 , struct V_63 * V_64 )
{
F_46 ( sizeof( V_62 ) != sizeof( V_65 ) ) ;
V_64 -> V_66 = V_62 & 0xffffffff ;
V_64 -> V_67 = ( V_62 >> V_68 ) & 0xf ;
V_64 -> V_69 = ( unsigned long long ) V_62 >> V_70 ;
}
static T_2 F_47 ( struct V_63 * V_64 )
{
return
( ( V_65 ) V_64 -> V_66 ) |
( ( V_65 ) V_64 -> V_67 << V_68 ) |
( ( V_65 ) V_64 -> V_69 << V_70 ) ;
}
static int F_48 ( struct V_71 * V_72 , struct V_73 * V_74 ,
struct V_75 * V_76 , void * V_10 )
{
struct V_63 * V_64 = V_10 ;
struct V_77 * V_78 = F_49 ( V_72 , V_76 ) ;
if ( V_64 -> V_79 -- > 0 )
return 0 ;
if ( F_50 ( V_78 ) )
return 1 ;
F_51 ( V_72 , V_76 ) ;
V_64 -> V_80 = V_78 ;
return 1 ;
}
static struct V_81 * F_52 ( const struct V_17 * V_18 ,
struct V_16 * V_82 ,
struct V_63 * V_64 )
{
F_24 ( F_53 ( V_82 ) ) ;
V_64 -> V_67 &= 0xf ;
V_64 -> V_80 = NULL ;
V_64 -> V_79 = V_64 -> V_67 ;
F_54 ( V_82 -> V_24 -> V_83 , V_64 -> V_69 ,
F_48 , V_64 ) ;
if ( V_64 -> V_80 ) {
struct V_84 * V_85 ;
V_85 = F_55 ( V_64 -> V_80 , V_82 -> V_39 ) ;
if ( V_85 ) {
F_56 ( V_85 , L_4 , V_86 ) ;
return F_57 ( V_85 ) ;
}
F_58 ( V_18 , F_59 ( V_64 -> V_80 ) ) ;
} else if ( V_64 -> V_79 > 0 ) {
V_64 -> V_67 = 0xf ;
}
return NULL ;
}
static T_2 F_60 ( const struct V_17 * V_18 ,
struct V_16 * V_82 , T_2 V_62 )
{
struct V_81 * V_87 ;
struct V_88 * V_23 ;
struct V_63 V_64 ;
V_23 = V_82 -> V_24 ;
F_45 ( V_62 , & V_64 ) ;
while ( 1 ) {
if ( V_64 . V_69 >= F_61 ( V_23 -> V_83 ) )
return ~ 0ULL ;
V_87 = F_52 ( V_18 , V_82 , & V_64 ) ;
if ( V_87 ) {
struct V_89 * V_89 = F_62 ( V_87 ) ;
struct V_90 * V_91 ;
int V_92 ;
V_92 = F_63 ( V_89 -> V_93 ,
V_64 . V_66 , 1 , & V_91 ) ;
if ( V_92 > 0 ) {
V_64 . V_66 = V_91 -> V_94 ;
V_92 = ! ( V_91 -> V_94 > 0xffffffff ) ;
F_64 ( V_91 ) ;
}
F_65 ( & V_87 -> V_95 , L_4 , V_86 ) ;
F_66 ( V_18 , V_87 ) ;
if ( V_92 > 0 )
return F_47 ( & V_64 ) ;
}
++ V_64 . V_67 ;
V_64 . V_67 &= 0xf ;
if ( V_64 . V_67 == 0 && ++ V_64 . V_69 == 0 )
return ~ 0ULL ;
V_64 . V_66 = 0 ;
}
}
static void F_67 ( const struct V_17 * V_18 ,
struct V_96 * V_97 , struct V_98 * V_90 )
{
struct V_99 * V_100 ;
struct V_90 * V_91 ;
int V_101 ;
V_100 = F_68 ( F_69 ( V_90 , & V_46 ) ) ;
V_91 = V_100 -> V_102 ;
F_70 ( V_97 , L_5 V_103 L_6 ,
0 ,
V_100 , V_90 ,
L_7 ,
V_100 -> V_104 ? L_8 : L_9 ,
F_71 ( V_91 ) ? L_10 : L_11 ,
V_91 , F_72 ( F_73 ( V_91 -> V_105 -> V_106 ) ) ,
V_91 -> V_105 -> V_106 , V_91 -> V_94 ,
F_74 ( V_91 ) ) ;
V_101 = 0 ;
F_75 ( V_97 , V_91 , V_107 , V_101 ) ;
F_75 ( V_97 , V_91 , error , V_101 ) ;
F_75 ( V_97 , V_91 , V_108 , V_101 ) ;
F_75 ( V_97 , V_91 , V_109 , V_101 ) ;
F_75 ( V_97 , V_91 , V_110 , V_101 ) ;
F_75 ( V_97 , V_91 , V_111 , V_101 ) ;
F_70 ( V_97 , L_12 , V_101 ? L_13 : L_11 ) ;
}
static int F_76 ( struct V_96 * V_112 , void * V_113 )
{
T_2 V_62 ;
struct V_50 * V_51 ;
struct V_81 * V_87 ;
struct V_17 * V_18 ;
struct V_63 V_64 ;
T_1 V_54 ;
int V_61 ;
V_18 = F_38 ( & V_54 ) ;
if ( ! F_39 ( V_18 ) ) {
V_62 = * ( T_2 * ) V_113 ;
F_45 ( V_62 , & V_64 ) ;
V_51 = V_112 -> V_114 ;
V_87 = F_52 ( V_18 , & V_51 -> V_58 -> V_34 , & V_64 ) ;
if ( V_87 ) {
struct V_89 * V_89 = F_62 ( V_87 ) ;
struct V_98 * V_90 = NULL ;
struct V_90 * V_91 ;
V_61 = F_63 ( V_89 -> V_93 ,
V_64 . V_66 , 1 ,
& V_91 ) ;
if ( V_61 > 0 ) {
F_77 ( V_91 ) ;
V_90 = F_78 ( V_91 , V_87 ) ;
F_79 ( V_91 ) ;
F_64 ( V_91 ) ;
}
F_70 ( V_112 , L_14 V_103 L_15 , V_64 . V_66 ,
F_72 ( F_80 ( & V_87 -> V_95 ) ) ) ;
if ( V_90 ) {
F_67 ( V_18 , V_112 , V_90 ) ;
F_81 ( V_18 , V_90 ) ;
} else {
F_82 ( V_112 , L_16 ) ;
}
F_65 ( & V_87 -> V_95 , L_4 , V_86 ) ;
F_66 ( V_18 , V_87 ) ;
} else {
F_70 ( V_112 , L_17 , V_62 ) ;
}
F_41 ( V_18 , & V_54 ) ;
V_61 = 0 ;
} else {
V_61 = F_42 ( V_18 ) ;
}
return V_61 ;
}
static void * F_83 ( struct V_96 * V_112 , T_2 * V_62 )
{
struct V_50 * V_51 ;
struct V_17 * V_18 ;
T_1 V_54 ;
V_51 = V_112 -> V_114 ;
V_18 = F_38 ( & V_54 ) ;
if ( ! F_39 ( V_18 ) ) {
V_51 = V_112 -> V_114 ;
if ( V_51 -> V_59 -> V_83 -> V_115 > 64 - V_70 )
V_62 = F_3 ( - V_116 ) ;
else {
* V_62 = F_60 ( V_18 , & V_51 -> V_58 -> V_34 ,
* V_62 ) ;
if ( * V_62 == ~ 0ULL )
V_62 = NULL ;
}
F_41 ( V_18 , & V_54 ) ;
}
return V_62 ;
}
static void * F_84 ( struct V_96 * V_112 , void * V_113 , T_2 * V_62 )
{
struct V_50 * V_51 ;
struct V_17 * V_18 ;
T_1 V_54 ;
V_18 = F_38 ( & V_54 ) ;
if ( ! F_39 ( V_18 ) ) {
V_51 = V_112 -> V_114 ;
* V_62 = F_60 ( V_18 , & V_51 -> V_58 -> V_34 , * V_62 + 1 ) ;
if ( * V_62 == ~ 0ULL )
V_62 = NULL ;
F_41 ( V_18 , & V_54 ) ;
}
return V_62 ;
}
static void F_85 ( struct V_96 * V_112 , void * V_113 )
{
}
static int F_86 ( struct V_89 * V_89 , struct V_117 * V_118 )
{
struct V_96 * V_97 ;
int V_32 ;
V_32 = F_87 ( V_118 , & V_119 ) ;
if ( V_32 )
return V_32 ;
V_97 = V_118 -> V_120 ;
V_97 -> V_114 = V_89 -> V_121 ;
return 0 ;
}
