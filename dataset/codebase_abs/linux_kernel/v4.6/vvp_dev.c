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
if ( V_41 ) {
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
V_44 -> V_49 = ( unsigned long long ) V_42 >> V_50 ;
}
static T_1 F_31 ( struct V_43 * V_44 )
{
return
( ( V_45 ) V_44 -> V_46 ) |
( ( V_45 ) V_44 -> V_47 << V_48 ) |
( ( V_45 ) V_44 -> V_49 << V_50 ) ;
}
static int F_32 ( struct V_51 * V_52 , struct V_53 * V_54 ,
struct V_55 * V_56 , void * V_10 )
{
struct V_43 * V_44 = V_10 ;
struct V_57 * V_58 = F_33 ( V_52 , V_56 ) ;
if ( V_44 -> V_59 -- > 0 )
return 0 ;
if ( F_34 ( V_58 ) )
return 1 ;
F_35 ( V_52 , V_56 ) ;
V_44 -> V_60 = V_58 ;
return 1 ;
}
static struct V_61 * F_36 ( const struct V_15 * V_16 ,
struct V_14 * V_62 ,
struct V_43 * V_44 )
{
F_37 ( F_38 ( V_62 ) ) ;
V_44 -> V_47 &= 0xf ;
V_44 -> V_60 = NULL ;
V_44 -> V_59 = V_44 -> V_47 ;
F_39 ( V_62 -> V_40 -> V_63 , V_44 -> V_49 ,
F_32 , V_44 ) ;
if ( V_44 -> V_60 ) {
struct V_64 * V_65 ;
V_65 = F_40 ( V_44 -> V_60 , V_62 -> V_66 ) ;
if ( V_65 ) {
F_41 ( V_65 , L_2 , V_67 ) ;
return F_42 ( V_65 ) ;
}
F_43 ( V_16 , F_44 ( V_44 -> V_60 ) ) ;
} else if ( V_44 -> V_59 > 0 ) {
V_44 -> V_47 = 0xf ;
}
return NULL ;
}
static T_1 F_45 ( const struct V_15 * V_16 ,
struct V_14 * V_62 , T_1 V_42 )
{
struct V_61 * V_68 ;
struct V_69 * V_70 ;
struct V_43 V_44 ;
V_70 = V_62 -> V_40 ;
F_29 ( V_42 , & V_44 ) ;
while ( 1 ) {
if ( V_44 . V_49 >= F_46 ( V_70 -> V_63 ) )
return ~ 0ULL ;
V_68 = F_36 ( V_16 , V_62 , & V_44 ) ;
if ( V_68 ) {
struct V_71 * V_58 ;
int V_72 ;
struct V_73 * V_74 ;
V_58 = V_71 ( V_68 ) ;
F_47 ( & V_58 -> V_75 ) ;
V_72 = F_48 ( & V_58 -> V_76 ,
( void * * ) & V_74 ,
V_44 . V_46 , 1 ) ;
if ( V_72 > 0 ) {
V_44 . V_46 = V_74 -> V_77 ;
V_72 = ! ( V_74 -> V_77 > 0xffffffff ) ;
}
F_49 ( & V_58 -> V_75 ) ;
F_50 ( & V_68 -> V_78 , L_2 , V_67 ) ;
F_51 ( V_16 , V_68 ) ;
if ( V_72 > 0 )
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
struct V_79 * V_80 , struct V_73 * V_81 )
{
struct V_82 * V_83 ;
struct V_81 * V_84 ;
int V_85 ;
V_83 = F_53 ( F_54 ( V_81 , & V_25 ) ) ;
V_84 = V_83 -> V_86 ;
F_55 ( V_80 , L_3 ,
0 ,
V_83 , V_81 ,
L_4 ,
V_83 -> V_87 ? L_5 : L_6 ,
V_83 -> V_88 ? L_7 : L_6 ,
F_56 ( V_84 ) ? L_8 : L_9 ,
V_84 , V_84 -> V_89 -> V_90 -> V_91 ,
V_84 -> V_89 -> V_90 -> V_92 ,
V_84 -> V_89 -> V_90 , V_84 -> V_93 ,
F_57 ( V_84 ) ) ;
V_85 = 0 ;
F_58 ( V_80 , V_84 , V_94 , V_85 ) ;
F_58 ( V_80 , V_84 , error , V_85 ) ;
F_58 ( V_80 , V_84 , V_95 , V_85 ) ;
F_58 ( V_80 , V_84 , V_96 , V_85 ) ;
F_58 ( V_80 , V_84 , V_97 , V_85 ) ;
F_58 ( V_80 , V_84 , V_98 , V_85 ) ;
F_55 ( V_80 , L_10 , V_85 ? L_11 : L_9 ) ;
}
static int F_59 ( struct V_79 * V_99 , void * V_100 )
{
T_1 V_42 ;
struct V_28 * V_29 ;
struct V_61 * V_68 ;
struct V_15 * V_16 ;
struct V_73 * V_81 ;
struct V_71 * V_58 ;
struct V_43 V_44 ;
int V_33 ;
int V_23 ;
V_16 = F_18 ( & V_33 ) ;
if ( ! F_19 ( V_16 ) ) {
V_42 = * ( T_1 * ) V_100 ;
F_29 ( V_42 , & V_44 ) ;
V_29 = V_99 -> V_101 ;
V_68 = F_36 ( V_16 , & V_29 -> V_38 -> V_102 , & V_44 ) ;
if ( V_68 ) {
V_58 = V_71 ( V_68 ) ;
F_47 ( & V_58 -> V_75 ) ;
V_81 = F_60 ( V_58 , V_44 . V_46 ) ;
F_49 ( & V_58 -> V_75 ) ;
F_55 ( V_99 , L_12 V_103 L_13 ,
V_44 . V_46 , F_61 ( & V_58 -> V_104 . V_105 ) ) ;
if ( V_81 ) {
F_52 ( V_16 , V_99 , V_81 ) ;
F_62 ( V_16 , V_81 ) ;
} else
F_63 ( V_99 , L_14 ) ;
F_50 ( & V_68 -> V_78 , L_2 , V_67 ) ;
F_51 ( V_16 , V_68 ) ;
} else
F_55 ( V_99 , L_15 , V_42 ) ;
F_23 ( V_16 , & V_33 ) ;
V_23 = 0 ;
} else
V_23 = F_24 ( V_16 ) ;
return V_23 ;
}
static void * F_64 ( struct V_79 * V_99 , T_1 * V_42 )
{
struct V_28 * V_29 ;
struct V_15 * V_16 ;
int V_33 ;
V_29 = V_99 -> V_101 ;
V_16 = F_18 ( & V_33 ) ;
if ( ! F_19 ( V_16 ) ) {
V_29 = V_99 -> V_101 ;
if ( V_29 -> V_39 -> V_63 -> V_106 > 64 - V_50 )
V_42 = F_3 ( - V_107 ) ;
else {
* V_42 = F_45 ( V_16 , & V_29 -> V_38 -> V_102 ,
* V_42 ) ;
if ( * V_42 == ~ 0ULL )
V_42 = NULL ;
}
F_23 ( V_16 , & V_33 ) ;
}
return V_42 ;
}
static void * F_65 ( struct V_79 * V_99 , void * V_100 , T_1 * V_42 )
{
struct V_28 * V_29 ;
struct V_15 * V_16 ;
int V_33 ;
V_16 = F_18 ( & V_33 ) ;
if ( ! F_19 ( V_16 ) ) {
V_29 = V_99 -> V_101 ;
* V_42 = F_45 ( V_16 , & V_29 -> V_38 -> V_102 , * V_42 + 1 ) ;
if ( * V_42 == ~ 0ULL )
V_42 = NULL ;
F_23 ( V_16 , & V_33 ) ;
}
return V_42 ;
}
static void F_66 ( struct V_79 * V_99 , void * V_100 )
{
}
static int F_67 ( struct V_108 * V_108 , struct V_109 * V_110 )
{
struct V_79 * V_80 ;
int V_32 ;
V_32 = F_68 ( V_110 , & V_111 ) ;
if ( V_32 )
return V_32 ;
V_80 = V_110 -> V_112 ;
V_80 -> V_101 = V_108 -> V_113 ;
return 0 ;
}
