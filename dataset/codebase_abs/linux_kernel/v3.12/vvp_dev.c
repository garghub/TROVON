static void * F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_2 ( V_6 , V_7 , V_8 ) ;
if ( V_6 == NULL )
V_6 = F_3 ( - V_9 ) ;
return V_6 ;
}
static void F_4 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_10 )
{
struct V_5 * V_6 = V_10 ;
F_5 ( V_6 , V_7 ) ;
}
static void * F_6 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_12 ;
F_2 ( V_12 , V_13 , V_8 ) ;
if ( V_12 == NULL )
V_12 = F_3 ( - V_9 ) ;
return V_12 ;
}
static void F_7 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_10 )
{
struct V_11 * V_12 = V_10 ;
F_5 ( V_12 , V_13 ) ;
}
static struct V_14 * F_8 ( const struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_19 * V_20 )
{
return F_9 ( V_16 , V_18 , V_20 , & V_21 , & V_22 ) ;
}
int F_10 ( void )
{
int V_23 ;
V_23 = F_11 ( V_24 ) ;
if ( V_23 == 0 ) {
V_23 = F_12 ( & V_25 ) ;
if ( V_23 != 0 )
F_13 ( V_24 ) ;
}
return V_23 ;
}
void F_14 ( void )
{
F_15 ( & V_25 ) ;
F_13 ( V_24 ) ;
}
int F_16 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
struct V_30 * V_31 ;
struct V_15 * V_16 ;
int V_32 = 0 ;
int V_33 ;
V_29 = F_17 ( V_27 ) ;
V_16 = F_18 ( & V_33 ) ;
if ( ! F_19 ( V_16 ) ) {
V_31 = F_20 ( V_16 , NULL , & V_25 ,
V_29 -> V_34 -> V_35 -> V_36 ) ;
if ( ! F_19 ( V_31 ) ) {
F_21 ( V_31 ) -> V_37 = V_27 ;
V_29 -> V_38 = V_31 ;
V_29 -> V_39 = F_22 ( V_31 ) -> V_40 ;
}
F_23 ( V_16 , & V_33 ) ;
} else
V_32 = F_24 ( V_16 ) ;
return V_32 ;
}
int F_25 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
struct V_15 * V_16 ;
struct V_30 * V_41 ;
int V_33 ;
int V_23 ;
V_29 = F_17 ( V_27 ) ;
V_16 = F_18 ( & V_33 ) ;
if ( ! F_19 ( V_16 ) ) {
V_41 = V_29 -> V_38 ;
if ( V_41 != NULL ) {
F_26 ( V_16 , V_41 ) ;
V_29 -> V_38 = NULL ;
V_29 -> V_39 = NULL ;
}
F_23 ( V_16 , & V_33 ) ;
V_23 = 0 ;
} else {
F_27 ( L_1 ) ;
V_23 = F_24 ( V_16 ) ;
}
F_28 () ;
return V_23 ;
}
static void F_29 ( T_1 V_42 , struct V_43 * V_44 )
{
F_30 ( sizeof( V_42 ) == sizeof( V_45 ) ) ;
V_44 -> V_46 = V_42 & 0xffffffff ;
V_44 -> V_47 = ( V_42 >> V_48 ) & 0xf ;
V_44 -> V_49 = ( ( unsigned long long ) V_42 >> V_50 ) ;
}
static T_1 F_31 ( struct V_43 * V_44 )
{
return
( ( V_45 ) V_44 -> V_46 ) |
( ( V_45 ) V_44 -> V_47 << V_48 ) |
( ( V_45 ) V_44 -> V_49 << V_50 ) ;
}
static int F_32 ( T_2 * V_51 , T_3 * V_52 ,
struct V_53 * V_54 , void * V_10 )
{
struct V_43 * V_44 = V_10 ;
struct V_55 * V_56 = F_33 ( V_51 , V_54 ) ;
if ( V_44 -> V_57 -- > 0 )
return 0 ;
if ( F_34 ( V_56 ) )
return 1 ;
F_35 ( V_51 , V_54 ) ;
V_44 -> V_58 = V_56 ;
return 1 ;
}
static struct V_59 * F_36 ( const struct V_15 * V_16 ,
struct V_14 * V_60 ,
struct V_43 * V_44 )
{
F_37 ( F_38 ( V_60 ) ) ;
V_44 -> V_47 &= 0xf ;
V_44 -> V_58 = NULL ;
V_44 -> V_57 = V_44 -> V_47 ;
F_39 ( V_60 -> V_40 -> V_61 , V_44 -> V_49 ,
F_32 , V_44 ) ;
if ( V_44 -> V_58 != NULL ) {
struct V_62 * V_63 ;
V_63 = F_40 ( V_44 -> V_58 , V_60 -> V_64 ) ;
if ( V_63 != NULL ) {
F_41 ( V_63 , L_2 , V_65 ) ;
return F_42 ( V_63 ) ;
}
F_43 ( V_16 , F_44 ( V_44 -> V_58 ) ) ;
} else if ( V_44 -> V_57 > 0 ) {
V_44 -> V_47 = 0xf ;
}
return NULL ;
}
static T_1 F_45 ( const struct V_15 * V_16 ,
struct V_14 * V_60 , T_1 V_42 )
{
struct V_59 * V_66 ;
struct V_67 * V_68 ;
struct V_43 V_44 ;
V_68 = V_60 -> V_40 ;
F_29 ( V_42 , & V_44 ) ;
while ( 1 ) {
if ( V_44 . V_49 >= F_46 ( V_68 -> V_61 ) )
return ~ 0ULL ;
V_66 = F_36 ( V_16 , V_60 , & V_44 ) ;
if ( V_66 != NULL ) {
struct V_69 * V_56 ;
int V_70 ;
struct V_71 * V_72 ;
V_56 = V_69 ( V_66 ) ;
F_47 ( & V_56 -> V_73 ) ;
V_70 = F_48 ( & V_56 -> V_74 ,
( void * * ) & V_72 ,
V_44 . V_46 , 1 ) ;
if ( V_70 > 0 ) {
V_44 . V_46 = V_72 -> V_75 ;
V_70 = ! ( V_72 -> V_75 > 0xffffffff ) ;
}
F_49 ( & V_56 -> V_73 ) ;
F_50 ( & V_66 -> V_76 , L_2 , V_65 ) ;
F_51 ( V_16 , V_66 ) ;
if ( V_70 > 0 )
return F_31 ( & V_44 ) ;
}
++ V_44 . V_47 ;
V_44 . V_47 &= 0xf ;
if ( V_44 . V_47 == 0 && ++ V_44 . V_49 == 0 )
return ~ 0ULL ;
V_44 . V_46 = 0 ;
}
}
static void F_52 ( const struct V_15 * V_16 ,
struct V_77 * V_78 , struct V_71 * V_79 )
{
struct V_80 * V_81 ;
struct V_79 * V_82 ;
int V_83 ;
V_81 = F_53 ( F_54 ( V_79 , & V_25 ) ) ;
V_82 = V_81 -> V_84 ;
F_55 ( V_78 , L_3 ,
0 ,
V_81 , V_79 ,
L_4 ,
V_81 -> V_85 ? L_5 : L_6 ,
V_81 -> V_86 ? L_7 : L_6 ,
F_56 ( V_82 ) ? L_8 : L_9 ,
V_82 , V_82 -> V_87 -> V_88 -> V_89 ,
V_82 -> V_87 -> V_88 -> V_90 ,
V_82 -> V_87 -> V_88 , V_82 -> V_91 ,
F_57 ( V_82 ) ) ;
V_83 = 0 ;
F_58 ( V_78 , V_82 , V_92 , V_83 ) ;
F_58 ( V_78 , V_82 , error , V_83 ) ;
F_58 ( V_78 , V_82 , V_93 , V_83 ) ;
F_58 ( V_78 , V_82 , V_94 , V_83 ) ;
F_58 ( V_78 , V_82 , V_95 , V_83 ) ;
F_58 ( V_78 , V_82 , V_96 , V_83 ) ;
F_55 ( V_78 , L_10 , V_83 ? L_11 : L_9 ) ;
}
static int F_59 ( struct V_77 * V_97 , void * V_98 )
{
T_1 V_42 ;
struct V_28 * V_29 ;
struct V_59 * V_66 ;
struct V_15 * V_16 ;
struct V_71 * V_79 ;
struct V_69 * V_56 ;
struct V_43 V_44 ;
int V_33 ;
int V_23 ;
V_16 = F_18 ( & V_33 ) ;
if ( ! F_19 ( V_16 ) ) {
V_42 = * ( T_1 * ) V_98 ;
F_29 ( V_42 , & V_44 ) ;
V_29 = V_97 -> V_99 ;
V_66 = F_36 ( V_16 , & V_29 -> V_38 -> V_100 , & V_44 ) ;
if ( V_66 != NULL ) {
V_56 = V_69 ( V_66 ) ;
F_47 ( & V_56 -> V_73 ) ;
V_79 = F_60 ( V_56 , V_44 . V_46 ) ;
F_49 ( & V_56 -> V_73 ) ;
F_55 ( V_97 , L_12 V_101 L_13 ,
V_44 . V_46 , F_61 ( & V_56 -> V_102 . V_103 ) ) ;
if ( V_79 != NULL ) {
F_52 ( V_16 , V_97 , V_79 ) ;
F_62 ( V_16 , V_79 ) ;
} else
F_63 ( V_97 , L_14 ) ;
F_50 ( & V_66 -> V_76 , L_2 , V_65 ) ;
F_51 ( V_16 , V_66 ) ;
} else
F_55 ( V_97 , L_15 , V_42 ) ;
F_23 ( V_16 , & V_33 ) ;
V_23 = 0 ;
} else
V_23 = F_24 ( V_16 ) ;
return V_23 ;
}
static void * F_64 ( struct V_77 * V_97 , T_1 * V_42 )
{
struct V_28 * V_29 ;
struct V_15 * V_16 ;
int V_33 ;
V_29 = V_97 -> V_99 ;
V_16 = F_18 ( & V_33 ) ;
if ( ! F_19 ( V_16 ) ) {
V_29 = V_97 -> V_99 ;
if ( V_29 -> V_39 -> V_61 -> V_104 > 64 - V_50 )
V_42 = F_3 ( - V_105 ) ;
else {
* V_42 = F_45 ( V_16 , & V_29 -> V_38 -> V_100 ,
* V_42 ) ;
if ( * V_42 == ~ 0ULL )
V_42 = NULL ;
}
F_23 ( V_16 , & V_33 ) ;
}
return V_42 ;
}
static void * F_65 ( struct V_77 * V_97 , void * V_98 , T_1 * V_42 )
{
struct V_28 * V_29 ;
struct V_15 * V_16 ;
int V_33 ;
V_16 = F_18 ( & V_33 ) ;
if ( ! F_19 ( V_16 ) ) {
V_29 = V_97 -> V_99 ;
* V_42 = F_45 ( V_16 , & V_29 -> V_38 -> V_100 , * V_42 + 1 ) ;
if ( * V_42 == ~ 0ULL )
V_42 = NULL ;
F_23 ( V_16 , & V_33 ) ;
}
return V_42 ;
}
static void F_66 ( struct V_77 * V_97 , void * V_98 )
{
}
static int F_67 ( struct V_106 * V_106 , struct V_107 * V_108 )
{
struct V_28 * V_29 = F_68 ( V_106 ) ;
struct V_77 * V_78 ;
int V_23 ;
V_23 = F_69 ( V_108 , & V_109 ) ;
if ( V_23 == 0 ) {
V_78 = V_108 -> V_110 ;
V_78 -> V_99 = V_29 ;
}
return V_23 ;
}
