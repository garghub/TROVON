static void * F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_7 , V_8 | V_9 ) ;
if ( V_6 == NULL )
V_6 = F_3 ( - V_10 ) ;
return V_6 ;
}
static void F_4 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_11 )
{
struct V_5 * V_6 = V_11 ;
F_5 ( V_7 , V_6 ) ;
}
static void * F_6 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_12 * V_13 ;
V_13 = F_2 ( V_14 , V_8 | V_9 ) ;
if ( V_13 == NULL )
V_13 = F_3 ( - V_10 ) ;
return V_13 ;
}
static void F_7 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_11 )
{
struct V_12 * V_13 = V_11 ;
F_5 ( V_14 , V_13 ) ;
}
static struct V_15 * F_8 ( const struct V_16 * V_17 ,
struct V_18 * V_19 ,
struct V_20 * V_21 )
{
return F_9 ( V_17 , V_19 , V_21 , & V_22 , & V_23 ) ;
}
int F_10 ( void )
{
int V_24 ;
V_24 = F_11 ( V_25 ) ;
if ( V_24 == 0 ) {
V_24 = F_12 ( & V_26 ) ;
if ( V_24 != 0 )
F_13 ( V_25 ) ;
}
return V_24 ;
}
void F_14 ( void )
{
F_15 ( & V_26 ) ;
F_13 ( V_25 ) ;
}
int F_16 ( struct V_27 * V_28 )
{
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_16 * V_17 ;
int V_33 = 0 ;
int V_34 ;
V_30 = F_17 ( V_28 ) ;
V_17 = F_18 ( & V_34 ) ;
if ( ! F_19 ( V_17 ) ) {
V_32 = F_20 ( V_17 , NULL , & V_26 ,
V_30 -> V_35 -> V_36 -> V_37 ) ;
if ( ! F_19 ( V_32 ) ) {
F_21 ( V_32 ) -> V_38 = V_28 ;
V_30 -> V_39 = V_32 ;
V_30 -> V_40 = F_22 ( V_32 ) -> V_41 ;
}
F_23 ( V_17 , & V_34 ) ;
} else
V_33 = F_24 ( V_17 ) ;
return V_33 ;
}
int F_25 ( struct V_27 * V_28 )
{
struct V_29 * V_30 ;
struct V_16 * V_17 ;
struct V_31 * V_42 ;
int V_34 ;
int V_24 ;
V_30 = F_17 ( V_28 ) ;
V_17 = F_18 ( & V_34 ) ;
if ( ! F_19 ( V_17 ) ) {
V_42 = V_30 -> V_39 ;
if ( V_42 != NULL ) {
F_26 ( V_17 , V_42 ) ;
V_30 -> V_39 = NULL ;
V_30 -> V_40 = NULL ;
}
F_23 ( V_17 , & V_34 ) ;
V_24 = 0 ;
} else {
F_27 ( L_1 ) ;
V_24 = F_24 ( V_17 ) ;
}
F_28 () ;
return V_24 ;
}
static void F_29 ( T_1 V_43 , struct V_44 * V_45 )
{
F_30 ( sizeof( V_43 ) == sizeof( V_46 ) ) ;
V_45 -> V_47 = V_43 & 0xffffffff ;
V_45 -> V_48 = ( V_43 >> V_49 ) & 0xf ;
V_45 -> V_50 = ( unsigned long long ) V_43 >> V_51 ;
}
static T_1 F_31 ( struct V_44 * V_45 )
{
return
( ( V_46 ) V_45 -> V_47 ) |
( ( V_46 ) V_45 -> V_48 << V_49 ) |
( ( V_46 ) V_45 -> V_50 << V_51 ) ;
}
static int F_32 ( struct V_52 * V_53 , struct V_54 * V_55 ,
struct V_56 * V_57 , void * V_11 )
{
struct V_44 * V_45 = V_11 ;
struct V_58 * V_59 = F_33 ( V_53 , V_57 ) ;
if ( V_45 -> V_60 -- > 0 )
return 0 ;
if ( F_34 ( V_59 ) )
return 1 ;
F_35 ( V_53 , V_57 ) ;
V_45 -> V_61 = V_59 ;
return 1 ;
}
static struct V_62 * F_36 ( const struct V_16 * V_17 ,
struct V_15 * V_63 ,
struct V_44 * V_45 )
{
F_37 ( F_38 ( V_63 ) ) ;
V_45 -> V_48 &= 0xf ;
V_45 -> V_61 = NULL ;
V_45 -> V_60 = V_45 -> V_48 ;
F_39 ( V_63 -> V_41 -> V_64 , V_45 -> V_50 ,
F_32 , V_45 ) ;
if ( V_45 -> V_61 != NULL ) {
struct V_65 * V_66 ;
V_66 = F_40 ( V_45 -> V_61 , V_63 -> V_67 ) ;
if ( V_66 != NULL ) {
F_41 ( V_66 , L_2 , V_68 ) ;
return F_42 ( V_66 ) ;
}
F_43 ( V_17 , F_44 ( V_45 -> V_61 ) ) ;
} else if ( V_45 -> V_60 > 0 ) {
V_45 -> V_48 = 0xf ;
}
return NULL ;
}
static T_1 F_45 ( const struct V_16 * V_17 ,
struct V_15 * V_63 , T_1 V_43 )
{
struct V_62 * V_69 ;
struct V_70 * V_71 ;
struct V_44 V_45 ;
V_71 = V_63 -> V_41 ;
F_29 ( V_43 , & V_45 ) ;
while ( 1 ) {
if ( V_45 . V_50 >= F_46 ( V_71 -> V_64 ) )
return ~ 0ULL ;
V_69 = F_36 ( V_17 , V_63 , & V_45 ) ;
if ( V_69 != NULL ) {
struct V_72 * V_59 ;
int V_73 ;
struct V_74 * V_75 ;
V_59 = V_72 ( V_69 ) ;
F_47 ( & V_59 -> V_76 ) ;
V_73 = F_48 ( & V_59 -> V_77 ,
( void * * ) & V_75 ,
V_45 . V_47 , 1 ) ;
if ( V_73 > 0 ) {
V_45 . V_47 = V_75 -> V_78 ;
V_73 = ! ( V_75 -> V_78 > 0xffffffff ) ;
}
F_49 ( & V_59 -> V_76 ) ;
F_50 ( & V_69 -> V_79 , L_2 , V_68 ) ;
F_51 ( V_17 , V_69 ) ;
if ( V_73 > 0 )
return F_31 ( & V_45 ) ;
}
++ V_45 . V_48 ;
V_45 . V_48 &= 0xf ;
if ( V_45 . V_48 == 0 && ++ V_45 . V_50 == 0 )
return ~ 0ULL ;
V_45 . V_47 = 0 ;
}
}
static void F_52 ( const struct V_16 * V_17 ,
struct V_80 * V_81 , struct V_74 * V_82 )
{
struct V_83 * V_84 ;
struct V_82 * V_85 ;
int V_86 ;
V_84 = F_53 ( F_54 ( V_82 , & V_26 ) ) ;
V_85 = V_84 -> V_87 ;
F_55 ( V_81 , L_3 ,
0 ,
V_84 , V_82 ,
L_4 ,
V_84 -> V_88 ? L_5 : L_6 ,
V_84 -> V_89 ? L_7 : L_6 ,
F_56 ( V_85 ) ? L_8 : L_9 ,
V_85 , V_85 -> V_90 -> V_91 -> V_92 ,
V_85 -> V_90 -> V_91 -> V_93 ,
V_85 -> V_90 -> V_91 , V_85 -> V_94 ,
F_57 ( V_85 ) ) ;
V_86 = 0 ;
F_58 ( V_81 , V_85 , V_95 , V_86 ) ;
F_58 ( V_81 , V_85 , error , V_86 ) ;
F_58 ( V_81 , V_85 , V_96 , V_86 ) ;
F_58 ( V_81 , V_85 , V_97 , V_86 ) ;
F_58 ( V_81 , V_85 , V_98 , V_86 ) ;
F_58 ( V_81 , V_85 , V_99 , V_86 ) ;
F_55 ( V_81 , L_10 , V_86 ? L_11 : L_9 ) ;
}
static int F_59 ( struct V_80 * V_100 , void * V_101 )
{
T_1 V_43 ;
struct V_29 * V_30 ;
struct V_62 * V_69 ;
struct V_16 * V_17 ;
struct V_74 * V_82 ;
struct V_72 * V_59 ;
struct V_44 V_45 ;
int V_34 ;
int V_24 ;
V_17 = F_18 ( & V_34 ) ;
if ( ! F_19 ( V_17 ) ) {
V_43 = * ( T_1 * ) V_101 ;
F_29 ( V_43 , & V_45 ) ;
V_30 = V_100 -> V_102 ;
V_69 = F_36 ( V_17 , & V_30 -> V_39 -> V_103 , & V_45 ) ;
if ( V_69 != NULL ) {
V_59 = V_72 ( V_69 ) ;
F_47 ( & V_59 -> V_76 ) ;
V_82 = F_60 ( V_59 , V_45 . V_47 ) ;
F_49 ( & V_59 -> V_76 ) ;
F_55 ( V_100 , L_12 V_104 L_13 ,
V_45 . V_47 , F_61 ( & V_59 -> V_105 . V_106 ) ) ;
if ( V_82 != NULL ) {
F_52 ( V_17 , V_100 , V_82 ) ;
F_62 ( V_17 , V_82 ) ;
} else
F_63 ( V_100 , L_14 ) ;
F_50 ( & V_69 -> V_79 , L_2 , V_68 ) ;
F_51 ( V_17 , V_69 ) ;
} else
F_55 ( V_100 , L_15 , V_43 ) ;
F_23 ( V_17 , & V_34 ) ;
V_24 = 0 ;
} else
V_24 = F_24 ( V_17 ) ;
return V_24 ;
}
static void * F_64 ( struct V_80 * V_100 , T_1 * V_43 )
{
struct V_29 * V_30 ;
struct V_16 * V_17 ;
int V_34 ;
V_30 = V_100 -> V_102 ;
V_17 = F_18 ( & V_34 ) ;
if ( ! F_19 ( V_17 ) ) {
V_30 = V_100 -> V_102 ;
if ( V_30 -> V_40 -> V_64 -> V_107 > 64 - V_51 )
V_43 = F_3 ( - V_108 ) ;
else {
* V_43 = F_45 ( V_17 , & V_30 -> V_39 -> V_103 ,
* V_43 ) ;
if ( * V_43 == ~ 0ULL )
V_43 = NULL ;
}
F_23 ( V_17 , & V_34 ) ;
}
return V_43 ;
}
static void * F_65 ( struct V_80 * V_100 , void * V_101 , T_1 * V_43 )
{
struct V_29 * V_30 ;
struct V_16 * V_17 ;
int V_34 ;
V_17 = F_18 ( & V_34 ) ;
if ( ! F_19 ( V_17 ) ) {
V_30 = V_100 -> V_102 ;
* V_43 = F_45 ( V_17 , & V_30 -> V_39 -> V_103 , * V_43 + 1 ) ;
if ( * V_43 == ~ 0ULL )
V_43 = NULL ;
F_23 ( V_17 , & V_34 ) ;
}
return V_43 ;
}
static void F_66 ( struct V_80 * V_100 , void * V_101 )
{
}
static int F_67 ( struct V_109 * V_109 , struct V_110 * V_111 )
{
struct V_80 * V_81 ;
int V_33 ;
V_33 = F_68 ( V_111 , & V_112 ) ;
if ( V_33 )
return V_33 ;
V_81 = V_111 -> V_113 ;
V_81 -> V_102 = V_109 -> V_114 ;
return 0 ;
}
