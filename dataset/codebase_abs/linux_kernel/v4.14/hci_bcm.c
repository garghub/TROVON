static inline void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_2 -> V_4 )
F_2 ( V_2 -> V_4 , V_3 ) ;
else
F_3 ( V_2 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 V_10 ;
if ( V_3 > 3000000 ) {
struct V_11 clock ;
clock . type = V_12 ;
F_5 ( V_6 , L_1 , clock . type ) ;
V_8 = F_6 ( V_6 , 0xfc45 , 1 , & clock , V_13 ) ;
if ( F_7 ( V_8 ) ) {
int V_14 = F_8 ( V_8 ) ;
F_9 ( V_6 , L_2 ,
V_14 ) ;
return V_14 ;
}
F_10 ( V_8 ) ;
}
F_5 ( V_6 , L_3 , V_3 ) ;
V_10 . V_15 = F_11 ( 0 ) ;
V_10 . V_16 = F_12 ( V_3 ) ;
V_8 = F_6 ( V_6 , 0xfc18 , sizeof( V_10 ) , & V_10 ,
V_13 ) ;
if ( F_7 ( V_8 ) ) {
int V_14 = F_8 ( V_8 ) ;
F_9 ( V_6 , L_4 ,
V_14 ) ;
return V_14 ;
}
F_10 ( V_8 ) ;
return 0 ;
}
static bool F_13 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
F_14 (p, &bcm_device_list) {
struct V_17 * V_21 = F_15 ( V_20 , struct V_17 , V_22 ) ;
if ( V_18 == V_21 )
return true ;
}
return false ;
}
static int F_16 ( struct V_17 * V_21 , bool V_23 )
{
if ( V_23 && ! F_7 ( V_21 -> V_24 ) && ! V_21 -> V_25 )
F_17 ( V_21 -> V_24 ) ;
F_18 ( V_21 -> V_26 , V_23 ) ;
F_18 ( V_21 -> V_27 , V_23 ) ;
if ( ! V_23 && ! F_7 ( V_21 -> V_24 ) && V_21 -> V_25 )
F_19 ( V_21 -> V_24 ) ;
V_21 -> V_25 = V_23 ;
return 0 ;
}
static T_1 F_20 ( int V_28 , void * V_29 )
{
struct V_17 * V_30 = V_29 ;
F_5 ( V_30 , L_5 ) ;
F_21 ( & V_30 -> V_31 -> V_21 ) ;
F_22 ( & V_30 -> V_31 -> V_21 ) ;
F_23 ( & V_30 -> V_31 -> V_21 ) ;
return V_32 ;
}
static int F_24 ( struct V_33 * V_34 )
{
struct V_17 * V_30 = V_34 -> V_21 ;
int V_14 ;
F_25 ( & V_35 ) ;
if ( ! F_13 ( V_30 ) ) {
V_14 = - V_36 ;
goto V_37;
}
if ( V_30 -> V_28 <= 0 ) {
V_14 = - V_38 ;
goto V_37;
}
V_14 = F_26 ( & V_30 -> V_31 -> V_21 , V_30 -> V_28 , F_20 ,
V_39 , L_6 , V_30 ) ;
if ( V_14 )
goto V_37;
F_27 ( & V_30 -> V_31 -> V_21 , true ) ;
F_28 ( & V_30 -> V_31 -> V_21 ,
V_40 ) ;
F_29 ( & V_30 -> V_31 -> V_21 ) ;
F_30 ( & V_30 -> V_31 -> V_21 ) ;
F_31 ( & V_30 -> V_31 -> V_21 ) ;
V_37:
F_32 ( & V_35 ) ;
return V_14 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_41 ;
struct V_7 * V_8 ;
struct V_42 V_43 = V_44 ;
V_43 . V_45 = ! V_34 -> V_21 -> V_46 ;
V_8 = F_6 ( V_2 -> V_6 , 0xfc27 , sizeof( V_43 ) ,
& V_43 , V_13 ) ;
if ( F_7 ( V_8 ) ) {
int V_14 = F_8 ( V_8 ) ;
F_9 ( V_2 -> V_6 , L_7 , V_14 ) ;
return V_14 ;
}
F_10 ( V_8 ) ;
F_5 ( V_2 -> V_6 , L_8 ) ;
return 0 ;
}
static inline int F_24 ( struct V_33 * V_34 ) { return 0 ; }
static inline int F_33 ( struct V_1 * V_2 ) { return 0 ; }
static int F_34 ( struct V_5 * V_6 , bool V_47 )
{
struct V_1 * V_2 = F_35 ( V_6 ) ;
struct V_33 * V_34 = V_2 -> V_41 ;
struct V_7 * V_8 ;
if ( ! F_36 ( V_48 , & V_6 -> V_49 ) )
return - V_50 ;
V_8 = F_37 ( 3 , V_51 ) ;
if ( ! V_8 )
return - V_52 ;
F_38 ( V_8 , V_53 ) ;
F_38 ( V_8 , 0xf0 ) ;
F_38 ( V_8 , V_47 ) ;
F_39 ( & V_34 -> V_54 , V_8 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_33 * V_34 ;
struct V_19 * V_20 ;
F_5 ( V_2 -> V_6 , L_9 , V_2 ) ;
V_34 = F_42 ( sizeof( * V_34 ) , V_51 ) ;
if ( ! V_34 )
return - V_52 ;
F_43 ( & V_34 -> V_54 ) ;
V_2 -> V_41 = V_34 ;
if ( V_2 -> V_4 ) {
F_44 ( V_2 -> V_4 ) ;
goto V_55;
}
if ( ! V_2 -> V_56 -> V_21 )
goto V_55;
F_25 ( & V_35 ) ;
F_14 (p, &bcm_device_list) {
struct V_17 * V_21 = F_15 ( V_20 , struct V_17 , V_22 ) ;
if ( V_2 -> V_56 -> V_21 -> V_57 == V_21 -> V_31 -> V_21 . V_57 ) {
V_34 -> V_21 = V_21 ;
V_2 -> V_58 = V_21 -> V_58 ;
V_2 -> V_59 = V_21 -> V_59 ;
#ifdef F_45
V_21 -> V_2 = V_2 ;
#endif
F_16 ( V_34 -> V_21 , true ) ;
break;
}
}
F_32 ( & V_35 ) ;
V_55:
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_41 ;
struct V_17 * V_30 = V_34 -> V_21 ;
F_5 ( V_2 -> V_6 , L_9 , V_2 ) ;
if ( V_2 -> V_4 )
F_47 ( V_2 -> V_4 ) ;
F_25 ( & V_35 ) ;
if ( F_13 ( V_30 ) ) {
F_16 ( V_30 , false ) ;
#ifdef F_45
F_48 ( & V_30 -> V_31 -> V_21 ) ;
F_49 ( & V_30 -> V_31 -> V_21 ) ;
if ( F_50 ( & V_30 -> V_31 -> V_21 ) ) {
F_51 ( & V_30 -> V_31 -> V_21 , V_30 -> V_28 , V_30 ) ;
F_27 ( & V_30 -> V_31 -> V_21 , false ) ;
}
V_30 -> V_2 = NULL ;
#endif
}
F_32 ( & V_35 ) ;
F_52 ( & V_34 -> V_54 ) ;
F_10 ( V_34 -> V_60 ) ;
F_53 ( V_34 ) ;
V_2 -> V_41 = NULL ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_41 ;
F_5 ( V_2 -> V_6 , L_9 , V_2 ) ;
F_52 ( & V_34 -> V_54 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_41 ;
char V_61 [ 64 ] ;
const struct V_62 * V_63 ;
unsigned int V_3 ;
int V_14 ;
F_5 ( V_2 -> V_6 , L_9 , V_2 ) ;
V_2 -> V_6 -> V_64 = F_34 ;
V_2 -> V_6 -> V_65 = V_66 ;
V_14 = F_56 ( V_2 -> V_6 , V_61 , sizeof( V_61 ) ) ;
if ( V_14 )
return V_14 ;
V_14 = F_57 ( & V_63 , V_61 , & V_2 -> V_6 -> V_21 ) ;
if ( V_14 < 0 ) {
F_58 ( V_2 -> V_6 , L_10 , V_61 ) ;
return 0 ;
}
V_14 = F_59 ( V_2 -> V_6 , V_63 ) ;
if ( V_14 ) {
F_58 ( V_2 -> V_6 , L_11 , V_14 ) ;
goto V_67;
}
if ( V_2 -> V_58 )
V_3 = V_2 -> V_58 ;
else if ( V_2 -> V_68 -> V_58 )
V_3 = V_2 -> V_68 -> V_58 ;
else
V_3 = 0 ;
if ( V_3 )
F_1 ( V_2 , V_3 ) ;
if ( V_2 -> V_59 )
V_3 = V_2 -> V_59 ;
else if ( V_2 -> V_68 -> V_59 )
V_3 = V_2 -> V_68 -> V_59 ;
else
V_3 = 0 ;
if ( V_3 ) {
V_14 = F_4 ( V_2 , V_3 ) ;
if ( ! V_14 )
F_1 ( V_2 , V_3 ) ;
}
V_67:
F_60 ( V_63 ) ;
V_14 = F_61 ( V_2 -> V_6 ) ;
if ( V_14 )
return V_14 ;
if ( ! F_24 ( V_34 ) )
V_14 = F_33 ( V_2 ) ;
return V_14 ;
}
static int F_62 ( struct V_1 * V_2 , const void * V_29 , int V_69 )
{
struct V_33 * V_34 = V_2 -> V_41 ;
if ( ! F_36 ( V_70 , & V_2 -> V_49 ) )
return - V_71 ;
V_34 -> V_60 = F_63 ( V_2 -> V_6 , V_34 -> V_60 , V_29 , V_69 ,
V_72 , F_64 ( V_72 ) ) ;
if ( F_7 ( V_34 -> V_60 ) ) {
int V_14 = F_8 ( V_34 -> V_60 ) ;
F_9 ( V_2 -> V_6 , L_12 , V_14 ) ;
V_34 -> V_60 = NULL ;
return V_14 ;
} else if ( ! V_34 -> V_60 ) {
F_25 ( & V_35 ) ;
if ( V_34 -> V_21 && F_13 ( V_34 -> V_21 ) ) {
F_21 ( & V_34 -> V_21 -> V_31 -> V_21 ) ;
F_22 ( & V_34 -> V_21 -> V_31 -> V_21 ) ;
F_23 ( & V_34 -> V_21 -> V_31 -> V_21 ) ;
}
F_32 ( & V_35 ) ;
}
return V_69 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_33 * V_34 = V_2 -> V_41 ;
F_5 ( V_2 -> V_6 , L_13 , V_2 , V_8 ) ;
memcpy ( F_66 ( V_8 , 1 ) , & F_67 ( V_8 ) , 1 ) ;
F_39 ( & V_34 -> V_54 , V_8 ) ;
return 0 ;
}
static struct V_7 * F_68 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_41 ;
struct V_7 * V_8 = NULL ;
struct V_17 * V_30 = NULL ;
F_25 ( & V_35 ) ;
if ( F_13 ( V_34 -> V_21 ) ) {
V_30 = V_34 -> V_21 ;
F_69 ( & V_30 -> V_31 -> V_21 ) ;
}
V_8 = F_70 ( & V_34 -> V_54 ) ;
if ( V_30 ) {
F_22 ( & V_30 -> V_31 -> V_21 ) ;
F_23 ( & V_30 -> V_31 -> V_21 ) ;
}
F_32 ( & V_35 ) ;
return V_8 ;
}
static int F_71 ( struct V_18 * V_21 )
{
struct V_17 * V_30 = F_72 ( F_73 ( V_21 ) ) ;
F_5 ( V_30 , L_14 ) ;
if ( ! V_30 -> V_73 && V_30 -> V_2 ) {
F_74 ( V_30 -> V_2 , true ) ;
V_30 -> V_73 = true ;
}
if ( V_30 -> V_27 ) {
F_18 ( V_30 -> V_27 , false ) ;
F_5 ( V_30 , L_15 ) ;
F_75 ( 15 ) ;
}
return 0 ;
}
static int F_76 ( struct V_18 * V_21 )
{
struct V_17 * V_30 = F_72 ( F_73 ( V_21 ) ) ;
F_5 ( V_30 , L_14 ) ;
if ( V_30 -> V_27 ) {
F_18 ( V_30 -> V_27 , true ) ;
F_5 ( V_30 , L_16 ) ;
F_75 ( 15 ) ;
}
if ( V_30 -> V_73 && V_30 -> V_2 ) {
V_30 -> V_73 = false ;
F_74 ( V_30 -> V_2 , false ) ;
}
return 0 ;
}
static int F_77 ( struct V_18 * V_21 )
{
struct V_17 * V_30 = F_72 ( F_73 ( V_21 ) ) ;
int error ;
F_5 ( V_30 , L_17 , V_30 -> V_73 ) ;
F_25 ( & V_35 ) ;
if ( ! V_30 -> V_2 )
goto V_37;
if ( F_78 ( V_21 ) )
F_71 ( V_21 ) ;
if ( F_79 ( & V_30 -> V_31 -> V_21 ) ) {
error = F_80 ( V_30 -> V_28 ) ;
if ( ! error )
F_5 ( V_30 , L_18 ) ;
}
V_37:
F_32 ( & V_35 ) ;
return 0 ;
}
static int F_81 ( struct V_18 * V_21 )
{
struct V_17 * V_30 = F_72 ( F_73 ( V_21 ) ) ;
F_5 ( V_30 , L_19 , V_30 -> V_73 ) ;
F_25 ( & V_35 ) ;
if ( ! V_30 -> V_2 )
goto V_37;
if ( F_79 ( & V_30 -> V_31 -> V_21 ) ) {
F_82 ( V_30 -> V_28 ) ;
F_5 ( V_30 , L_20 ) ;
}
F_76 ( V_21 ) ;
V_37:
F_32 ( & V_35 ) ;
F_48 ( V_21 ) ;
F_30 ( V_21 ) ;
F_31 ( V_21 ) ;
return 0 ;
}
static int F_83 ( struct V_74 * V_75 , void * V_29 )
{
struct V_17 * V_21 = V_29 ;
struct V_76 * V_28 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
switch ( V_75 -> type ) {
case V_81 :
V_28 = & V_75 -> V_29 . V_82 ;
V_21 -> V_46 = V_28 -> V_83 ;
break;
case V_84 :
V_78 = & V_75 -> V_29 . V_78 ;
if ( V_78 -> V_85 == V_86 )
V_21 -> V_46 = V_78 -> V_83 ;
break;
case V_87 :
V_80 = & V_75 -> V_29 . V_88 ;
if ( V_80 -> type == V_89 ) {
V_21 -> V_58 = V_80 -> V_90 ;
V_21 -> V_59 = 4000000 ;
}
break;
default:
break;
}
return 1 ;
}
static int F_84 ( struct V_17 * V_21 )
{
struct V_91 * V_31 = V_21 -> V_31 ;
V_21 -> V_92 = F_85 ( & V_31 -> V_21 ) ;
V_21 -> V_24 = F_86 ( & V_31 -> V_21 , NULL ) ;
V_21 -> V_27 = F_87 ( & V_31 -> V_21 ,
L_21 ,
V_93 ) ;
if ( F_7 ( V_21 -> V_27 ) )
return F_8 ( V_21 -> V_27 ) ;
V_21 -> V_26 = F_87 ( & V_31 -> V_21 , L_22 ,
V_93 ) ;
if ( F_7 ( V_21 -> V_26 ) )
return F_8 ( V_21 -> V_26 ) ;
V_21 -> V_28 = F_88 ( V_31 , 0 ) ;
if ( V_21 -> V_28 <= 0 ) {
struct V_94 * V_78 ;
V_78 = F_87 ( & V_31 -> V_21 , L_23 ,
V_95 ) ;
if ( F_7 ( V_78 ) )
return F_8 ( V_78 ) ;
V_21 -> V_28 = F_89 ( V_78 ) ;
}
F_90 ( & V_31 -> V_21 , L_24 , V_21 -> V_28 ) ;
if ( ( ! V_21 -> V_27 && ! V_21 -> V_26 ) || ! V_21 -> V_92 ) {
F_91 ( & V_31 -> V_21 , L_25 ) ;
return - V_96 ;
}
return 0 ;
}
static int F_92 ( struct V_17 * V_21 )
{
struct V_91 * V_31 = V_21 -> V_31 ;
F_93 ( V_97 ) ;
const struct V_98 * V_99 ;
const struct V_100 * V_101 = V_102 ;
const struct V_103 * V_104 ;
int V_105 ;
V_104 = F_94 ( V_31 -> V_21 . V_106 -> V_107 , & V_31 -> V_21 ) ;
if ( V_104 )
V_101 = ( const struct V_100 * ) V_104 -> V_108 ;
V_105 = F_95 ( & V_31 -> V_21 , V_101 ) ;
if ( V_105 )
return V_105 ;
V_105 = F_84 ( V_21 ) ;
if ( V_105 )
return V_105 ;
V_105 = F_96 ( F_97 ( & V_21 -> V_31 -> V_21 ) ,
& V_97 , F_83 , V_21 ) ;
if ( V_105 < 0 )
return V_105 ;
F_98 ( & V_97 ) ;
V_99 = F_99 ( V_109 ) ;
if ( V_99 ) {
F_100 ( V_21 , L_26 ,
V_99 -> V_110 ) ;
V_21 -> V_46 = * ( V_111 * ) V_99 -> V_108 ;
}
return 0 ;
}
static int F_92 ( struct V_17 * V_21 )
{
return - V_96 ;
}
static int F_101 ( struct V_91 * V_31 )
{
struct V_17 * V_21 ;
int V_105 ;
V_21 = F_102 ( & V_31 -> V_21 , sizeof( * V_21 ) , V_51 ) ;
if ( ! V_21 )
return - V_52 ;
V_21 -> V_31 = V_31 ;
if ( F_103 ( & V_31 -> V_21 ) )
V_105 = F_92 ( V_21 ) ;
else
V_105 = F_84 ( V_21 ) ;
if ( V_105 )
return V_105 ;
F_104 ( V_31 , V_21 ) ;
F_90 ( & V_31 -> V_21 , L_27 , V_21 -> V_92 ) ;
F_25 ( & V_35 ) ;
F_105 ( & V_21 -> V_22 , & V_112 ) ;
F_32 ( & V_35 ) ;
F_16 ( V_21 , false ) ;
return 0 ;
}
static int F_106 ( struct V_91 * V_31 )
{
struct V_17 * V_21 = F_72 ( V_31 ) ;
F_25 ( & V_35 ) ;
F_107 ( & V_21 -> V_22 ) ;
F_32 ( & V_35 ) ;
F_90 ( & V_31 -> V_21 , L_28 , V_21 -> V_92 ) ;
return 0 ;
}
static int F_108 ( struct V_113 * V_4 )
{
struct V_114 * V_115 ;
T_2 V_3 ;
int V_14 ;
V_115 = F_102 ( & V_4 -> V_21 , sizeof( * V_115 ) , V_51 ) ;
if ( ! V_115 )
return - V_52 ;
V_115 -> V_2 . V_4 = V_4 ;
F_109 ( V_4 , V_115 ) ;
V_14 = F_110 ( & V_4 -> V_21 , L_29 , & V_3 ) ;
if ( ! V_14 )
V_115 -> V_2 . V_59 = V_3 ;
return F_111 ( & V_115 -> V_2 , & V_116 ) ;
}
static void F_112 ( struct V_113 * V_4 )
{
struct V_114 * V_115 = F_113 ( V_4 ) ;
F_114 ( & V_115 -> V_2 ) ;
}
int T_3 F_115 ( void )
{
F_116 ( & V_117 ) ;
F_117 ( & V_118 ) ;
return F_118 ( & V_116 ) ;
}
int T_4 F_119 ( void )
{
F_120 ( & V_117 ) ;
F_121 ( & V_118 ) ;
return F_122 ( & V_116 ) ;
}
