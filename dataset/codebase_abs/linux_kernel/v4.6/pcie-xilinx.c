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
unsigned long V_5 = F_1 ( V_2 , V_8 ) ;
if ( V_5 & V_9 ) {
F_7 ( V_2 -> V_10 , L_1 ,
V_5 & V_11 ) ;
F_3 ( V_2 , V_12 ,
V_8 ) ;
}
}
static bool F_8 ( struct V_13 * V_14 , unsigned int V_15 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
if ( V_14 -> V_17 != V_2 -> V_18 )
if ( ! F_5 ( V_2 ) )
return false ;
if ( V_14 -> V_17 == V_2 -> V_18 && V_15 > 0 )
return false ;
if ( V_14 -> V_19 == V_2 -> V_18 && V_15 > 0 )
return false ;
return true ;
}
static void T_2 * F_9 ( struct V_13 * V_14 ,
unsigned int V_15 , int V_20 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
int V_21 ;
if ( ! F_8 ( V_14 , V_15 ) )
return NULL ;
V_21 = ( V_14 -> V_17 << V_22 ) |
( V_15 << V_23 ) ;
return V_2 -> V_4 + V_21 + V_20 ;
}
static void F_10 ( unsigned int V_24 )
{
struct V_25 * V_26 ;
struct V_1 * V_2 ;
if ( ! F_11 ( V_24 , V_27 ) ) {
V_26 = F_12 ( V_24 ) ;
V_2 = F_13 ( V_26 ) ;
F_14 ( V_2 -> V_10 , L_2 , V_24 ) ;
} else {
F_15 ( V_24 , V_27 ) ;
}
}
static int F_16 ( struct V_1 * V_2 )
{
int V_28 ;
V_28 = F_17 ( V_27 , V_29 ) ;
if ( V_28 < V_29 )
F_18 ( V_28 , V_27 ) ;
else
return - V_30 ;
return V_28 ;
}
static void F_19 ( struct V_31 * V_32 ,
unsigned int V_24 )
{
F_10 ( V_24 ) ;
}
static int F_20 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_25 * V_35 )
{
struct V_1 * V_2 = V_34 -> V_14 -> V_16 ;
unsigned int V_24 ;
int V_36 ;
struct V_37 V_38 ;
T_3 V_39 ;
V_36 = F_16 ( V_2 ) ;
if ( V_36 < 0 )
return V_36 ;
V_24 = F_21 ( V_2 -> V_40 , V_36 ) ;
if ( ! V_24 )
return - V_41 ;
F_22 ( V_24 , V_35 ) ;
V_39 = F_23 ( ( void * ) V_2 -> V_42 ) ;
V_38 . V_43 = 0 ;
V_38 . V_44 = V_39 ;
V_38 . V_45 = V_24 ;
F_24 ( V_24 , & V_38 ) ;
return 0 ;
}
static int F_25 ( struct V_40 * V_46 , unsigned int V_24 ,
T_4 V_36 )
{
F_26 ( V_24 , & V_47 , V_48 ) ;
F_27 ( V_24 , V_46 -> V_49 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_3 V_39 ;
V_2 -> V_42 = F_29 ( V_50 , 0 ) ;
V_39 = F_23 ( ( void * ) V_2 -> V_42 ) ;
F_3 ( V_2 , 0x0 , V_51 ) ;
F_3 ( V_2 , V_39 , V_52 ) ;
}
static int F_30 ( struct V_40 * V_46 , unsigned int V_24 ,
T_4 V_36 )
{
F_26 ( V_24 , & V_53 , V_48 ) ;
F_27 ( V_24 , V_46 -> V_49 ) ;
return 0 ;
}
static T_5 F_31 ( int V_24 , void * V_45 )
{
struct V_1 * V_2 = (struct V_1 * ) V_45 ;
T_1 V_5 , V_54 , V_55 , V_56 ;
V_5 = F_1 ( V_2 , V_57 ) ;
V_54 = F_1 ( V_2 , V_58 ) ;
V_55 = V_5 & V_54 ;
if ( ! V_55 )
return V_59 ;
if ( V_55 & V_60 )
F_32 ( V_2 -> V_10 , L_3 ) ;
if ( V_55 & V_61 )
F_32 ( V_2 -> V_10 , L_4 ) ;
if ( V_55 & V_62 )
F_32 ( V_2 -> V_10 , L_5 ) ;
if ( V_55 & V_63 )
F_33 ( V_2 -> V_10 , L_6 ) ;
if ( V_55 & V_64 )
F_32 ( V_2 -> V_10 , L_7 ) ;
if ( V_55 & V_65 ) {
F_32 ( V_2 -> V_10 , L_8 ) ;
F_6 ( V_2 ) ;
}
if ( V_55 & V_66 ) {
F_32 ( V_2 -> V_10 , L_9 ) ;
F_6 ( V_2 ) ;
}
if ( V_55 & V_67 ) {
F_32 ( V_2 -> V_10 , L_10 ) ;
F_6 ( V_2 ) ;
}
if ( V_55 & V_68 ) {
V_5 = F_1 ( V_2 , V_69 ) ;
if ( ! ( V_5 & V_70 ) ) {
F_32 ( V_2 -> V_10 , L_11 ) ;
return V_71 ;
}
if ( ! ( V_5 & V_72 ) ) {
F_3 ( V_2 , V_73 ,
V_69 ) ;
V_5 = ( ( V_5 & V_74 ) >>
V_75 ) + 1 ;
F_34 ( F_35 ( V_2 -> V_40 ,
V_5 ) ) ;
}
}
if ( V_55 & V_76 ) {
V_5 = F_1 ( V_2 , V_69 ) ;
if ( ! ( V_5 & V_70 ) ) {
F_32 ( V_2 -> V_10 , L_11 ) ;
return V_71 ;
}
if ( V_5 & V_72 ) {
V_56 = F_1 ( V_2 , V_77 ) &
V_78 ;
F_3 ( V_2 , V_73 ,
V_69 ) ;
if ( F_36 ( V_79 ) ) {
F_34 ( V_56 ) ;
}
}
}
if ( V_55 & V_80 )
F_32 ( V_2 -> V_10 , L_12 ) ;
if ( V_55 & V_81 )
F_32 ( V_2 -> V_10 , L_13 ) ;
if ( V_55 & V_82 )
F_32 ( V_2 -> V_10 , L_14 ) ;
if ( V_55 & V_83 )
F_32 ( V_2 -> V_10 , L_15 ) ;
if ( V_55 & V_84 )
F_32 ( V_2 -> V_10 , L_16 ) ;
if ( V_55 & V_85 )
F_32 ( V_2 -> V_10 , L_17 ) ;
if ( V_55 & V_86 )
F_32 ( V_2 -> V_10 , L_18 ) ;
if ( V_55 & V_87 )
F_32 ( V_2 -> V_10 , L_19 ) ;
if ( V_55 & V_88 )
F_32 ( V_2 -> V_10 , L_20 ) ;
F_3 ( V_2 , V_55 , V_57 ) ;
return V_71 ;
}
static void F_37 ( struct V_1 * V_2 )
{
int V_89 ;
T_1 V_24 , V_90 ;
if ( F_36 ( V_79 ) ) {
F_38 ( V_2 -> V_42 , 0 ) ;
V_90 = V_29 ;
} else {
V_90 = 4 ;
}
for ( V_89 = 0 ; V_89 < V_90 ; V_89 ++ ) {
V_24 = F_35 ( V_2 -> V_40 , V_89 ) ;
if ( V_24 > 0 )
F_39 ( V_24 ) ;
}
F_40 ( V_2 -> V_40 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_91 * V_10 = V_2 -> V_10 ;
struct V_92 * V_93 = V_10 -> V_94 ;
struct V_92 * V_95 ;
V_95 = F_42 ( V_93 , NULL ) ;
if ( ! V_95 ) {
F_14 ( V_10 , L_21 ) ;
return F_43 ( V_95 ) ;
}
V_2 -> V_40 = F_44 ( V_95 , 4 ,
& V_96 ,
V_2 ) ;
if ( ! V_2 -> V_40 ) {
F_14 ( V_10 , L_22 ) ;
return F_43 ( V_2 -> V_40 ) ;
}
if ( F_36 ( V_79 ) ) {
V_2 -> V_40 = F_44 ( V_93 ,
V_29 ,
& V_97 ,
& V_98 ) ;
if ( ! V_2 -> V_40 ) {
F_14 ( V_10 , L_23 ) ;
return F_43 ( V_2 -> V_40 ) ;
}
F_28 ( V_2 ) ;
}
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 ) )
F_33 ( V_2 -> V_10 , L_24 ) ;
else
F_33 ( V_2 -> V_10 , L_25 ) ;
F_3 ( V_2 , ~ V_99 ,
V_58 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_57 ) &
V_100 ,
V_57 ) ;
F_3 ( V_2 , V_100 , V_58 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_101 ) |
V_102 ,
V_101 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_91 * V_10 = V_2 -> V_10 ;
struct V_92 * V_93 = V_10 -> V_94 ;
struct V_103 V_104 ;
const char * type ;
int V_105 ;
type = F_47 ( V_93 , L_26 , NULL ) ;
if ( ! type || strcmp ( type , L_27 ) ) {
F_14 ( V_10 , L_28 , type ) ;
return - V_41 ;
}
V_105 = F_48 ( V_93 , 0 , & V_104 ) ;
if ( V_105 ) {
F_14 ( V_10 , L_29 ) ;
return V_105 ;
}
V_2 -> V_4 = F_49 ( V_10 , & V_104 ) ;
if ( F_50 ( V_2 -> V_4 ) )
return F_43 ( V_2 -> V_4 ) ;
V_2 -> V_24 = F_51 ( V_93 , 0 ) ;
V_105 = F_52 ( V_10 , V_2 -> V_24 , F_31 ,
V_106 | V_107 ,
L_30 , V_2 ) ;
if ( V_105 ) {
F_14 ( V_10 , L_31 , V_2 -> V_24 ) ;
return V_105 ;
}
return 0 ;
}
static int F_53 ( struct V_108 * V_34 )
{
struct V_1 * V_2 ;
struct V_91 * V_10 = & V_34 -> V_10 ;
struct V_13 * V_14 ;
int V_105 ;
T_6 V_109 = 0 ;
F_54 ( V_110 ) ;
if ( ! V_10 -> V_94 )
return - V_111 ;
V_2 = F_55 ( V_10 , sizeof( * V_2 ) , V_50 ) ;
if ( ! V_2 )
return - V_112 ;
V_2 -> V_10 = V_10 ;
V_105 = F_46 ( V_2 ) ;
if ( V_105 ) {
F_14 ( V_10 , L_32 ) ;
return V_105 ;
}
F_45 ( V_2 ) ;
V_105 = F_41 ( V_2 ) ;
if ( V_105 ) {
F_14 ( V_10 , L_33 ) ;
return V_105 ;
}
V_105 = F_56 ( V_10 -> V_94 , 0 , 0xff , & V_110 ,
& V_109 ) ;
if ( V_105 ) {
F_14 ( V_10 , L_34 ) ;
return V_105 ;
}
V_14 = F_57 ( & V_34 -> V_10 , 0 ,
& V_113 , V_2 , & V_110 ) ;
if ( ! V_14 )
return - V_112 ;
#ifdef V_79
V_98 . V_10 = V_2 -> V_10 ;
V_14 -> V_26 = & V_98 ;
#endif
F_58 ( V_14 ) ;
F_59 ( V_14 ) ;
#ifndef F_60
F_61 ( V_114 , V_115 ) ;
#endif
F_62 ( V_14 ) ;
F_63 ( V_34 , V_2 ) ;
return 0 ;
}
static int F_64 ( struct V_108 * V_34 )
{
struct V_1 * V_2 = F_65 ( V_34 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
