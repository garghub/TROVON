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
RETURN ( V_32 ) ;
}
int F_25 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
struct V_15 * V_16 ;
struct V_30 * V_41 ;
int V_33 ;
int V_23 ;
V_42 ;
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
RETURN ( V_23 ) ;
}
static void F_29 ( T_1 V_43 , struct V_44 * V_45 )
{
F_30 ( sizeof( V_43 ) == sizeof( V_46 ) ) ;
V_45 -> V_47 = V_43 & 0xffffffff ;
V_45 -> V_48 = ( V_43 >> V_49 ) & 0xf ;
V_45 -> V_50 = ( ( unsigned long long ) V_43 >> V_51 ) ;
}
static T_1 F_31 ( struct V_44 * V_45 )
{
return
( ( V_46 ) V_45 -> V_47 ) |
( ( V_46 ) V_45 -> V_48 << V_49 ) |
( ( V_46 ) V_45 -> V_50 << V_51 ) ;
}
static int F_32 ( T_2 * V_52 , T_3 * V_53 ,
struct V_54 * V_55 , void * V_10 )
{
struct V_44 * V_45 = V_10 ;
struct V_56 * V_57 = F_33 ( V_52 , V_55 ) ;
if ( V_45 -> V_58 -- > 0 )
return 0 ;
if ( F_34 ( V_57 ) )
return 1 ;
F_35 ( V_52 , V_55 ) ;
V_45 -> V_59 = V_57 ;
return 1 ;
}
static struct V_60 * F_36 ( const struct V_15 * V_16 ,
struct V_14 * V_61 ,
struct V_44 * V_45 )
{
F_37 ( F_38 ( V_61 ) ) ;
V_45 -> V_48 &= 0xf ;
V_45 -> V_59 = NULL ;
V_45 -> V_58 = V_45 -> V_48 ;
F_39 ( V_61 -> V_40 -> V_62 , V_45 -> V_50 ,
F_32 , V_45 ) ;
if ( V_45 -> V_59 != NULL ) {
struct V_63 * V_64 ;
V_64 = F_40 ( V_45 -> V_59 , V_61 -> V_65 ) ;
if ( V_64 != NULL ) {
F_41 ( V_64 , L_2 , V_66 ) ;
return F_42 ( V_64 ) ;
}
F_43 ( V_16 , F_44 ( V_45 -> V_59 ) ) ;
} else if ( V_45 -> V_58 > 0 ) {
V_45 -> V_48 = 0xf ;
}
return NULL ;
}
static T_1 F_45 ( const struct V_15 * V_16 ,
struct V_14 * V_61 , T_1 V_43 )
{
struct V_60 * V_67 ;
struct V_68 * V_69 ;
struct V_44 V_45 ;
V_69 = V_61 -> V_40 ;
F_29 ( V_43 , & V_45 ) ;
while ( 1 ) {
if ( V_45 . V_50 >= F_46 ( V_69 -> V_62 ) )
return ~ 0ULL ;
V_67 = F_36 ( V_16 , V_61 , & V_45 ) ;
if ( V_67 != NULL ) {
struct V_70 * V_57 ;
int V_71 ;
struct V_72 * V_73 ;
V_57 = V_70 ( V_67 ) ;
F_47 ( & V_57 -> V_74 ) ;
V_71 = F_48 ( & V_57 -> V_75 ,
( void * * ) & V_73 ,
V_45 . V_47 , 1 ) ;
if ( V_71 > 0 ) {
V_45 . V_47 = V_73 -> V_76 ;
V_71 = ! ( V_73 -> V_76 > 0xffffffff ) ;
}
F_49 ( & V_57 -> V_74 ) ;
F_50 ( & V_67 -> V_77 , L_2 , V_66 ) ;
F_51 ( V_16 , V_67 ) ;
if ( V_71 > 0 )
return F_31 ( & V_45 ) ;
}
++ V_45 . V_48 ;
V_45 . V_48 &= 0xf ;
if ( V_45 . V_48 == 0 && ++ V_45 . V_50 == 0 )
return ~ 0ULL ;
V_45 . V_47 = 0 ;
}
}
static void F_52 ( const struct V_15 * V_16 ,
struct V_78 * V_79 , struct V_72 * V_80 )
{
struct V_81 * V_82 ;
struct V_80 * V_83 ;
int V_84 ;
V_82 = F_53 ( F_54 ( V_80 , & V_25 ) ) ;
V_83 = V_82 -> V_85 ;
F_55 ( V_79 , L_3 ,
0 ,
V_82 , V_80 ,
L_4 ,
V_82 -> V_86 ? L_5 : L_6 ,
V_82 -> V_87 ? L_7 : L_6 ,
F_56 ( V_83 ) ? L_8 : L_9 ,
V_83 , V_83 -> V_88 -> V_89 -> V_90 ,
V_83 -> V_88 -> V_89 -> V_91 ,
V_83 -> V_88 -> V_89 , V_83 -> V_92 ,
F_57 ( V_83 ) ) ;
V_84 = 0 ;
F_58 ( V_79 , V_83 , V_93 , V_84 ) ;
F_58 ( V_79 , V_83 , error , V_84 ) ;
F_58 ( V_79 , V_83 , V_94 , V_84 ) ;
F_58 ( V_79 , V_83 , V_95 , V_84 ) ;
F_58 ( V_79 , V_83 , V_96 , V_84 ) ;
F_58 ( V_79 , V_83 , V_97 , V_84 ) ;
F_55 ( V_79 , L_10 , V_84 ? L_11 : L_9 ) ;
}
static int F_59 ( struct V_78 * V_98 , void * V_99 )
{
T_1 V_43 ;
struct V_28 * V_29 ;
struct V_60 * V_67 ;
struct V_15 * V_16 ;
struct V_72 * V_80 ;
struct V_70 * V_57 ;
struct V_44 V_45 ;
int V_33 ;
int V_23 ;
V_16 = F_18 ( & V_33 ) ;
if ( ! F_19 ( V_16 ) ) {
V_43 = * ( T_1 * ) V_99 ;
F_29 ( V_43 , & V_45 ) ;
V_29 = V_98 -> V_100 ;
V_67 = F_36 ( V_16 , & V_29 -> V_38 -> V_101 , & V_45 ) ;
if ( V_67 != NULL ) {
V_57 = V_70 ( V_67 ) ;
F_47 ( & V_57 -> V_74 ) ;
V_80 = F_60 ( V_57 , V_45 . V_47 ) ;
F_49 ( & V_57 -> V_74 ) ;
F_55 ( V_98 , L_12 V_102 L_13 ,
V_45 . V_47 , F_61 ( & V_57 -> V_103 . V_104 ) ) ;
if ( V_80 != NULL ) {
F_52 ( V_16 , V_98 , V_80 ) ;
F_62 ( V_16 , V_80 ) ;
} else
F_63 ( V_98 , L_14 ) ;
F_50 ( & V_67 -> V_77 , L_2 , V_66 ) ;
F_51 ( V_16 , V_67 ) ;
} else
F_55 ( V_98 , L_15 , V_43 ) ;
F_23 ( V_16 , & V_33 ) ;
V_23 = 0 ;
} else
V_23 = F_24 ( V_16 ) ;
return V_23 ;
}
static void * F_64 ( struct V_78 * V_98 , T_1 * V_43 )
{
struct V_28 * V_29 ;
struct V_15 * V_16 ;
int V_33 ;
V_29 = V_98 -> V_100 ;
V_16 = F_18 ( & V_33 ) ;
if ( ! F_19 ( V_16 ) ) {
V_29 = V_98 -> V_100 ;
if ( V_29 -> V_39 -> V_62 -> V_105 > 64 - V_51 )
V_43 = F_3 ( - V_106 ) ;
else {
* V_43 = F_45 ( V_16 , & V_29 -> V_38 -> V_101 ,
* V_43 ) ;
if ( * V_43 == ~ 0ULL )
V_43 = NULL ;
}
F_23 ( V_16 , & V_33 ) ;
}
return V_43 ;
}
static void * F_65 ( struct V_78 * V_98 , void * V_99 , T_1 * V_43 )
{
struct V_28 * V_29 ;
struct V_15 * V_16 ;
int V_33 ;
V_16 = F_18 ( & V_33 ) ;
if ( ! F_19 ( V_16 ) ) {
V_29 = V_98 -> V_100 ;
* V_43 = F_45 ( V_16 , & V_29 -> V_38 -> V_101 , * V_43 + 1 ) ;
if ( * V_43 == ~ 0ULL )
V_43 = NULL ;
F_23 ( V_16 , & V_33 ) ;
}
return V_43 ;
}
static void F_66 ( struct V_78 * V_98 , void * V_99 )
{
}
static int F_67 ( struct V_107 * V_107 , struct V_108 * V_109 )
{
struct V_28 * V_29 = F_68 ( V_107 ) ;
struct V_78 * V_79 ;
int V_23 ;
V_23 = F_69 ( V_109 , & V_110 ) ;
if ( V_23 == 0 ) {
V_79 = V_109 -> V_111 ;
V_79 -> V_100 = V_29 ;
}
return V_23 ;
}
