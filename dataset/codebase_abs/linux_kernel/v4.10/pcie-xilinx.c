static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline bool F_5 ( struct V_1 * V_2 )
{
return ( F_1 ( V_2 , V_6 ) &
V_7 ) ? 1 : 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_5 = F_1 ( V_2 , V_10 ) ;
if ( V_5 & V_11 ) {
F_7 ( V_9 , L_1 ,
V_5 & V_12 ) ;
F_3 ( V_2 , V_13 ,
V_10 ) ;
}
}
static bool F_8 ( struct V_14 * V_15 , unsigned int V_16 )
{
struct V_1 * V_2 = V_15 -> V_17 ;
if ( V_15 -> V_18 != V_2 -> V_19 )
if ( ! F_5 ( V_2 ) )
return false ;
if ( V_15 -> V_18 == V_2 -> V_19 && V_16 > 0 )
return false ;
return true ;
}
static void T_2 * F_9 ( struct V_14 * V_15 ,
unsigned int V_16 , int V_20 )
{
struct V_1 * V_2 = V_15 -> V_17 ;
int V_21 ;
if ( ! F_8 ( V_15 , V_16 ) )
return NULL ;
V_21 = ( V_15 -> V_18 << V_22 ) |
( V_16 << V_23 ) ;
return V_2 -> V_4 + V_21 + V_20 ;
}
static void F_10 ( unsigned int V_24 )
{
struct V_25 * V_26 ;
struct V_1 * V_2 ;
struct V_27 * V_28 = F_11 ( V_24 ) ;
T_3 V_29 = F_12 ( V_28 ) ;
if ( ! F_13 ( V_29 , V_30 ) ) {
V_26 = F_14 ( V_24 ) ;
V_2 = F_15 ( V_26 ) ;
F_16 ( V_2 -> V_9 , L_2 , V_24 ) ;
} else {
F_17 ( V_29 , V_30 ) ;
}
}
static int F_18 ( void )
{
int V_31 ;
V_31 = F_19 ( V_30 , V_32 ) ;
if ( V_31 < V_32 )
F_20 ( V_31 , V_30 ) ;
else
return - V_33 ;
return V_31 ;
}
static void F_21 ( struct V_34 * V_35 ,
unsigned int V_24 )
{
F_10 ( V_24 ) ;
F_22 ( V_24 ) ;
}
static int F_23 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
struct V_25 * V_38 )
{
struct V_1 * V_2 = V_37 -> V_15 -> V_17 ;
unsigned int V_24 ;
int V_29 ;
struct V_39 V_40 ;
T_4 V_41 ;
V_29 = F_18 () ;
if ( V_29 < 0 )
return V_29 ;
V_24 = F_24 ( V_2 -> V_42 , V_29 ) ;
if ( ! V_24 )
return - V_43 ;
F_25 ( V_24 , V_38 ) ;
V_41 = F_26 ( ( void * ) V_2 -> V_44 ) ;
V_40 . V_45 = 0 ;
V_40 . V_46 = V_41 ;
V_40 . V_47 = V_24 ;
F_27 ( V_24 , & V_40 ) ;
return 0 ;
}
static int F_28 ( struct V_48 * V_49 , unsigned int V_24 ,
T_3 V_29 )
{
F_29 ( V_24 , & V_50 , V_51 ) ;
F_30 ( V_24 , V_49 -> V_52 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_4 V_41 ;
V_2 -> V_44 = F_32 ( V_53 , 0 ) ;
V_41 = F_26 ( ( void * ) V_2 -> V_44 ) ;
F_3 ( V_2 , 0x0 , V_54 ) ;
F_3 ( V_2 , V_41 , V_55 ) ;
}
static int F_33 ( struct V_48 * V_49 , unsigned int V_24 ,
T_3 V_29 )
{
F_29 ( V_24 , & V_56 , V_51 ) ;
F_30 ( V_24 , V_49 -> V_52 ) ;
return 0 ;
}
static T_5 F_34 ( int V_24 , void * V_47 )
{
struct V_1 * V_2 = (struct V_1 * ) V_47 ;
struct V_8 * V_9 = V_2 -> V_9 ;
T_1 V_5 , V_57 , V_58 , V_59 ;
V_5 = F_1 ( V_2 , V_60 ) ;
V_57 = F_1 ( V_2 , V_61 ) ;
V_58 = V_5 & V_57 ;
if ( ! V_58 )
return V_62 ;
if ( V_58 & V_63 )
F_35 ( V_9 , L_3 ) ;
if ( V_58 & V_64 )
F_35 ( V_9 , L_4 ) ;
if ( V_58 & V_65 )
F_35 ( V_9 , L_5 ) ;
if ( V_58 & V_66 )
F_36 ( V_9 , L_6 ) ;
if ( V_58 & V_67 )
F_35 ( V_9 , L_7 ) ;
if ( V_58 & V_68 ) {
F_35 ( V_9 , L_8 ) ;
F_6 ( V_2 ) ;
}
if ( V_58 & V_69 ) {
F_35 ( V_9 , L_9 ) ;
F_6 ( V_2 ) ;
}
if ( V_58 & V_70 ) {
F_35 ( V_9 , L_10 ) ;
F_6 ( V_2 ) ;
}
if ( V_58 & V_71 ) {
V_5 = F_1 ( V_2 , V_72 ) ;
if ( ! ( V_5 & V_73 ) ) {
F_35 ( V_9 , L_11 ) ;
goto error;
}
if ( ! ( V_5 & V_74 ) ) {
F_3 ( V_2 , V_75 ,
V_72 ) ;
V_5 = ( ( V_5 & V_76 ) >>
V_77 ) + 1 ;
F_37 ( F_38 ( V_2 -> V_78 ,
V_5 ) ) ;
}
}
if ( V_58 & V_79 ) {
V_5 = F_1 ( V_2 , V_72 ) ;
if ( ! ( V_5 & V_73 ) ) {
F_35 ( V_9 , L_11 ) ;
goto error;
}
if ( V_5 & V_74 ) {
V_59 = F_1 ( V_2 , V_80 ) &
V_81 ;
F_3 ( V_2 , V_75 ,
V_72 ) ;
if ( F_39 ( V_82 ) ) {
F_37 ( V_59 ) ;
}
}
}
if ( V_58 & V_83 )
F_35 ( V_9 , L_12 ) ;
if ( V_58 & V_84 )
F_35 ( V_9 , L_13 ) ;
if ( V_58 & V_85 )
F_35 ( V_9 , L_14 ) ;
if ( V_58 & V_86 )
F_35 ( V_9 , L_15 ) ;
if ( V_58 & V_87 )
F_35 ( V_9 , L_16 ) ;
if ( V_58 & V_88 )
F_35 ( V_9 , L_17 ) ;
if ( V_58 & V_89 )
F_35 ( V_9 , L_18 ) ;
if ( V_58 & V_90 )
F_35 ( V_9 , L_19 ) ;
if ( V_58 & V_91 )
F_35 ( V_9 , L_20 ) ;
error:
F_3 ( V_2 , V_58 , V_60 ) ;
return V_92 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_93 * V_94 = V_9 -> V_95 ;
struct V_93 * V_96 ;
V_96 = F_41 ( V_94 , NULL ) ;
if ( ! V_96 ) {
F_16 ( V_9 , L_21 ) ;
return - V_97 ;
}
V_2 -> V_78 = F_42 ( V_96 , 4 ,
& V_98 ,
V_2 ) ;
if ( ! V_2 -> V_78 ) {
F_16 ( V_9 , L_22 ) ;
return - V_97 ;
}
if ( F_39 ( V_82 ) ) {
V_2 -> V_42 = F_42 ( V_94 ,
V_32 ,
& V_99 ,
& V_100 ) ;
if ( ! V_2 -> V_42 ) {
F_16 ( V_9 , L_23 ) ;
return - V_97 ;
}
F_31 ( V_2 ) ;
}
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
if ( F_5 ( V_2 ) )
F_36 ( V_9 , L_24 ) ;
else
F_36 ( V_9 , L_25 ) ;
F_3 ( V_2 , ~ V_101 ,
V_61 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_60 ) &
V_102 ,
V_60 ) ;
F_3 ( V_2 , V_102 , V_61 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_103 ) |
V_104 ,
V_103 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_93 * V_94 = V_9 -> V_95 ;
struct V_105 V_106 ;
const char * type ;
int V_107 ;
type = F_45 ( V_94 , L_26 , NULL ) ;
if ( ! type || strcmp ( type , L_27 ) ) {
F_16 ( V_9 , L_28 , type ) ;
return - V_43 ;
}
V_107 = F_46 ( V_94 , 0 , & V_106 ) ;
if ( V_107 ) {
F_16 ( V_9 , L_29 ) ;
return V_107 ;
}
V_2 -> V_4 = F_47 ( V_9 , & V_106 ) ;
if ( F_48 ( V_2 -> V_4 ) )
return F_49 ( V_2 -> V_4 ) ;
V_2 -> V_24 = F_50 ( V_94 , 0 ) ;
V_107 = F_51 ( V_9 , V_2 -> V_24 , F_34 ,
V_108 | V_109 ,
L_30 , V_2 ) ;
if ( V_107 ) {
F_16 ( V_9 , L_31 , V_2 -> V_24 ) ;
return V_107 ;
}
return 0 ;
}
static int F_52 ( struct V_110 * V_37 )
{
struct V_8 * V_9 = & V_37 -> V_9 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
int V_107 ;
T_6 V_111 = 0 ;
F_53 ( V_112 ) ;
if ( ! V_9 -> V_95 )
return - V_97 ;
V_2 = F_54 ( V_9 , sizeof( * V_2 ) , V_53 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_9 = V_9 ;
V_107 = F_44 ( V_2 ) ;
if ( V_107 ) {
F_16 ( V_9 , L_32 ) ;
return V_107 ;
}
F_43 ( V_2 ) ;
V_107 = F_40 ( V_2 ) ;
if ( V_107 ) {
F_16 ( V_9 , L_33 ) ;
return V_107 ;
}
V_107 = F_55 ( V_9 -> V_95 , 0 , 0xff , & V_112 ,
& V_111 ) ;
if ( V_107 ) {
F_16 ( V_9 , L_34 ) ;
return V_107 ;
}
V_107 = F_56 ( V_9 , & V_112 ) ;
if ( V_107 )
goto error;
V_15 = F_57 ( V_9 , 0 , & V_114 , V_2 , & V_112 ) ;
if ( ! V_15 ) {
V_107 = - V_113 ;
goto error;
}
#ifdef V_82
V_100 . V_9 = V_9 ;
V_15 -> V_26 = & V_100 ;
#endif
F_58 ( V_15 ) ;
F_59 ( V_15 ) ;
#ifndef F_60
F_61 ( V_115 , V_116 ) ;
#endif
F_62 ( V_15 ) ;
return 0 ;
error:
F_63 ( & V_112 ) ;
return V_107 ;
}
