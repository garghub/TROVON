static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_8 V_9 ;
if ( V_3 > 3000000 ) {
struct V_10 clock ;
clock . type = V_11 ;
F_2 ( V_5 , L_1 , clock . type ) ;
V_7 = F_3 ( V_5 , 0xfc45 , 1 , & clock , V_12 ) ;
if ( F_4 ( V_7 ) ) {
int V_13 = F_5 ( V_7 ) ;
F_6 ( V_5 , L_2 ,
V_13 ) ;
return V_13 ;
}
F_7 ( V_7 ) ;
}
F_2 ( V_5 , L_3 , V_3 ) ;
V_9 . V_14 = F_8 ( 0 ) ;
V_9 . V_15 = F_9 ( V_3 ) ;
V_7 = F_3 ( V_5 , 0xfc18 , sizeof( V_9 ) , & V_9 ,
V_12 ) ;
if ( F_4 ( V_7 ) ) {
int V_13 = F_5 ( V_7 ) ;
F_6 ( V_5 , L_4 ,
V_13 ) ;
return V_13 ;
}
F_7 ( V_7 ) ;
return 0 ;
}
static bool F_10 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
F_11 (p, &bcm_device_list) {
struct V_16 * V_20 = F_12 ( V_19 , struct V_16 , V_21 ) ;
if ( V_17 == V_20 )
return true ;
}
return false ;
}
static int F_13 ( struct V_16 * V_20 , bool V_22 )
{
if ( V_22 && ! F_4 ( V_20 -> V_23 ) && ! V_20 -> V_24 )
F_14 ( V_20 -> V_23 ) ;
F_15 ( V_20 -> V_25 , V_22 ) ;
F_15 ( V_20 -> V_26 , V_22 ) ;
if ( ! V_22 && ! F_4 ( V_20 -> V_23 ) && V_20 -> V_24 )
F_16 ( V_20 -> V_23 ) ;
V_20 -> V_24 = V_22 ;
return 0 ;
}
static T_1 F_17 ( int V_27 , void * V_28 )
{
struct V_16 * V_29 = V_28 ;
F_2 ( V_29 , L_5 ) ;
F_18 ( & V_29 -> V_30 -> V_20 ) ;
F_19 ( & V_29 -> V_30 -> V_20 ) ;
F_20 ( & V_29 -> V_30 -> V_20 ) ;
return V_31 ;
}
static int F_21 ( struct V_32 * V_33 )
{
struct V_16 * V_29 = V_33 -> V_20 ;
int V_13 = 0 ;
F_22 ( & V_34 ) ;
if ( ! F_10 ( V_29 ) ) {
V_13 = - V_35 ;
goto V_36;
}
if ( V_29 -> V_27 > 0 ) {
V_13 = F_23 ( & V_29 -> V_30 -> V_20 , V_29 -> V_27 ,
F_17 , V_37 ,
L_6 , V_29 ) ;
if ( V_13 )
goto V_36;
F_24 ( & V_29 -> V_30 -> V_20 , true ) ;
F_25 ( & V_29 -> V_30 -> V_20 ,
V_38 ) ;
F_26 ( & V_29 -> V_30 -> V_20 ) ;
F_27 ( & V_29 -> V_30 -> V_20 ) ;
F_28 ( & V_29 -> V_30 -> V_20 ) ;
}
V_36:
F_29 ( & V_34 ) ;
return V_13 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_39 ;
struct V_6 * V_7 ;
struct V_40 V_41 = V_42 ;
V_41 . V_43 = ! V_33 -> V_20 -> V_44 ;
V_7 = F_3 ( V_2 -> V_5 , 0xfc27 , sizeof( V_41 ) ,
& V_41 , V_12 ) ;
if ( F_4 ( V_7 ) ) {
int V_13 = F_5 ( V_7 ) ;
F_6 ( V_2 -> V_5 , L_7 , V_13 ) ;
return V_13 ;
}
F_7 ( V_7 ) ;
F_2 ( V_2 -> V_5 , L_8 ) ;
return 0 ;
}
static inline int F_21 ( struct V_32 * V_33 ) { return 0 ; }
static inline int F_30 ( struct V_1 * V_2 ) { return 0 ; }
static int F_31 ( struct V_4 * V_5 , bool V_45 )
{
struct V_1 * V_2 = F_32 ( V_5 ) ;
struct V_32 * V_33 = V_2 -> V_39 ;
struct V_6 * V_7 ;
if ( ! F_33 ( V_46 , & V_5 -> V_47 ) )
return - V_48 ;
V_7 = F_34 ( 3 , V_49 ) ;
if ( ! V_7 )
return - V_50 ;
* F_35 ( V_7 , 1 ) = V_51 ;
* F_35 ( V_7 , 1 ) = 0xf0 ;
* F_35 ( V_7 , 1 ) = V_45 ;
F_36 ( & V_33 -> V_52 , V_7 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
struct V_18 * V_19 ;
F_2 ( V_2 -> V_5 , L_9 , V_2 ) ;
V_33 = F_39 ( sizeof( * V_33 ) , V_49 ) ;
if ( ! V_33 )
return - V_50 ;
F_40 ( & V_33 -> V_52 ) ;
V_2 -> V_39 = V_33 ;
F_22 ( & V_34 ) ;
F_11 (p, &bcm_device_list) {
struct V_16 * V_20 = F_12 ( V_19 , struct V_16 , V_21 ) ;
if ( V_2 -> V_53 -> V_20 -> V_54 == V_20 -> V_30 -> V_20 . V_54 ) {
V_33 -> V_20 = V_20 ;
V_2 -> V_55 = V_20 -> V_55 ;
#ifdef F_41
V_20 -> V_2 = V_2 ;
#endif
F_13 ( V_33 -> V_20 , true ) ;
break;
}
}
F_29 ( & V_34 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_39 ;
struct V_16 * V_29 = V_33 -> V_20 ;
F_2 ( V_2 -> V_5 , L_9 , V_2 ) ;
F_22 ( & V_34 ) ;
if ( F_10 ( V_29 ) ) {
F_13 ( V_29 , false ) ;
#ifdef F_41
F_43 ( & V_29 -> V_30 -> V_20 ) ;
F_44 ( & V_29 -> V_30 -> V_20 ) ;
if ( F_45 ( & V_29 -> V_30 -> V_20 ) ) {
F_46 ( & V_29 -> V_30 -> V_20 , V_29 -> V_27 , V_29 ) ;
F_24 ( & V_29 -> V_30 -> V_20 , false ) ;
}
V_29 -> V_2 = NULL ;
#endif
}
F_29 ( & V_34 ) ;
F_47 ( & V_33 -> V_52 ) ;
F_7 ( V_33 -> V_56 ) ;
F_48 ( V_33 ) ;
V_2 -> V_39 = NULL ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_39 ;
F_2 ( V_2 -> V_5 , L_9 , V_2 ) ;
F_47 ( & V_33 -> V_52 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_39 ;
char V_57 [ 64 ] ;
const struct V_58 * V_59 ;
unsigned int V_3 ;
int V_13 ;
F_2 ( V_2 -> V_5 , L_9 , V_2 ) ;
V_2 -> V_5 -> V_60 = F_31 ;
V_2 -> V_5 -> V_61 = V_62 ;
V_13 = F_51 ( V_2 -> V_5 , V_57 , sizeof( V_57 ) ) ;
if ( V_13 )
return V_13 ;
V_13 = F_52 ( & V_59 , V_57 , & V_2 -> V_5 -> V_20 ) ;
if ( V_13 < 0 ) {
F_53 ( V_2 -> V_5 , L_10 , V_57 ) ;
return 0 ;
}
V_13 = F_54 ( V_2 -> V_5 , V_59 ) ;
if ( V_13 ) {
F_53 ( V_2 -> V_5 , L_11 , V_13 ) ;
goto V_63;
}
if ( V_2 -> V_55 )
V_3 = V_2 -> V_55 ;
else if ( V_2 -> V_64 -> V_55 )
V_3 = V_2 -> V_64 -> V_55 ;
else
V_3 = 0 ;
if ( V_3 )
F_55 ( V_2 , V_3 ) ;
if ( V_2 -> V_65 )
V_3 = V_2 -> V_65 ;
else if ( V_2 -> V_64 -> V_65 )
V_3 = V_2 -> V_64 -> V_65 ;
else
V_3 = 0 ;
if ( V_3 ) {
V_13 = F_1 ( V_2 , V_3 ) ;
if ( ! V_13 )
F_55 ( V_2 , V_3 ) ;
}
V_63:
F_56 ( V_59 ) ;
V_13 = F_57 ( V_2 -> V_5 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_21 ( V_33 ) ;
if ( ! V_13 )
V_13 = F_30 ( V_2 ) ;
return V_13 ;
}
static int F_58 ( struct V_1 * V_2 , const void * V_28 , int V_66 )
{
struct V_32 * V_33 = V_2 -> V_39 ;
if ( ! F_33 ( V_67 , & V_2 -> V_47 ) )
return - V_68 ;
V_33 -> V_56 = F_59 ( V_2 -> V_5 , V_33 -> V_56 , V_28 , V_66 ,
V_69 , F_60 ( V_69 ) ) ;
if ( F_4 ( V_33 -> V_56 ) ) {
int V_13 = F_5 ( V_33 -> V_56 ) ;
F_6 ( V_2 -> V_5 , L_12 , V_13 ) ;
V_33 -> V_56 = NULL ;
return V_13 ;
} else if ( ! V_33 -> V_56 ) {
F_22 ( & V_34 ) ;
if ( V_33 -> V_20 && F_10 ( V_33 -> V_20 ) ) {
F_18 ( & V_33 -> V_20 -> V_30 -> V_20 ) ;
F_19 ( & V_33 -> V_20 -> V_30 -> V_20 ) ;
F_20 ( & V_33 -> V_20 -> V_30 -> V_20 ) ;
}
F_29 ( & V_34 ) ;
}
return V_66 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_32 * V_33 = V_2 -> V_39 ;
F_2 ( V_2 -> V_5 , L_13 , V_2 , V_7 ) ;
memcpy ( F_62 ( V_7 , 1 ) , & F_63 ( V_7 ) -> V_70 , 1 ) ;
F_36 ( & V_33 -> V_52 , V_7 ) ;
return 0 ;
}
static struct V_6 * F_64 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_39 ;
struct V_6 * V_7 = NULL ;
struct V_16 * V_29 = NULL ;
F_22 ( & V_34 ) ;
if ( F_10 ( V_33 -> V_20 ) ) {
V_29 = V_33 -> V_20 ;
F_65 ( & V_29 -> V_30 -> V_20 ) ;
}
V_7 = F_66 ( & V_33 -> V_52 ) ;
if ( V_29 ) {
F_19 ( & V_29 -> V_30 -> V_20 ) ;
F_20 ( & V_29 -> V_30 -> V_20 ) ;
}
F_29 ( & V_34 ) ;
return V_7 ;
}
static int F_67 ( struct V_17 * V_20 )
{
struct V_16 * V_29 = F_68 ( F_69 ( V_20 ) ) ;
F_2 ( V_29 , L_14 ) ;
if ( ! V_29 -> V_71 && V_29 -> V_2 ) {
F_70 ( V_29 -> V_2 , true ) ;
V_29 -> V_71 = true ;
}
if ( V_29 -> V_26 ) {
F_15 ( V_29 -> V_26 , false ) ;
F_2 ( V_29 , L_15 ) ;
F_71 ( 15 ) ;
}
return 0 ;
}
static int F_72 ( struct V_17 * V_20 )
{
struct V_16 * V_29 = F_68 ( F_69 ( V_20 ) ) ;
F_2 ( V_29 , L_14 ) ;
if ( V_29 -> V_26 ) {
F_15 ( V_29 -> V_26 , true ) ;
F_2 ( V_29 , L_16 ) ;
F_71 ( 15 ) ;
}
if ( V_29 -> V_71 && V_29 -> V_2 ) {
V_29 -> V_71 = false ;
F_70 ( V_29 -> V_2 , false ) ;
}
return 0 ;
}
static int F_73 ( struct V_17 * V_20 )
{
struct V_16 * V_29 = F_68 ( F_69 ( V_20 ) ) ;
int error ;
F_2 ( V_29 , L_17 , V_29 -> V_71 ) ;
F_22 ( & V_34 ) ;
if ( ! V_29 -> V_2 )
goto V_36;
if ( F_74 ( V_20 ) )
F_67 ( V_20 ) ;
if ( F_75 ( & V_29 -> V_30 -> V_20 ) ) {
error = F_76 ( V_29 -> V_27 ) ;
if ( ! error )
F_2 ( V_29 , L_18 ) ;
}
V_36:
F_29 ( & V_34 ) ;
return 0 ;
}
static int F_77 ( struct V_17 * V_20 )
{
struct V_16 * V_29 = F_68 ( F_69 ( V_20 ) ) ;
F_2 ( V_29 , L_19 , V_29 -> V_71 ) ;
F_22 ( & V_34 ) ;
if ( ! V_29 -> V_2 )
goto V_36;
if ( F_75 ( & V_29 -> V_30 -> V_20 ) ) {
F_78 ( V_29 -> V_27 ) ;
F_2 ( V_29 , L_20 ) ;
}
F_72 ( V_20 ) ;
V_36:
F_29 ( & V_34 ) ;
F_43 ( V_20 ) ;
F_27 ( V_20 ) ;
F_28 ( V_20 ) ;
return 0 ;
}
static int F_79 ( struct V_72 * V_73 , void * V_28 )
{
struct V_16 * V_20 = V_28 ;
struct V_74 * V_27 ;
struct V_75 * V_76 ;
struct V_77 * V_78 ;
switch ( V_73 -> type ) {
case V_79 :
V_27 = & V_73 -> V_28 . V_80 ;
V_20 -> V_44 = V_27 -> V_81 ;
break;
case V_82 :
V_76 = & V_73 -> V_28 . V_76 ;
if ( V_76 -> V_83 == V_84 )
V_20 -> V_44 = V_76 -> V_81 ;
break;
case V_85 :
V_78 = & V_73 -> V_28 . V_86 ;
if ( V_78 -> type == V_87 )
V_20 -> V_55 = V_78 -> V_88 ;
break;
default:
break;
}
return 1 ;
}
static int F_80 ( struct V_16 * V_20 )
{
struct V_89 * V_30 = V_20 -> V_30 ;
F_81 ( V_90 ) ;
const struct V_91 * V_92 ;
int V_93 ;
V_20 -> V_94 = F_82 ( & V_30 -> V_20 ) ;
V_93 = F_83 ( F_84 ( & V_30 -> V_20 ) ,
V_95 ) ;
if ( V_93 )
return V_93 ;
V_20 -> V_23 = F_85 ( & V_30 -> V_20 , NULL ) ;
V_20 -> V_26 = F_86 ( & V_30 -> V_20 ,
L_21 ,
V_96 ) ;
if ( F_4 ( V_20 -> V_26 ) )
return F_5 ( V_20 -> V_26 ) ;
V_20 -> V_25 = F_86 ( & V_30 -> V_20 , L_22 ,
V_96 ) ;
if ( F_4 ( V_20 -> V_25 ) )
return F_5 ( V_20 -> V_25 ) ;
V_20 -> V_27 = F_87 ( V_30 , 0 ) ;
if ( V_20 -> V_27 <= 0 ) {
struct V_97 * V_76 ;
V_76 = F_86 ( & V_30 -> V_20 , L_23 ,
V_98 ) ;
if ( F_4 ( V_76 ) )
return F_5 ( V_76 ) ;
V_20 -> V_27 = F_88 ( V_76 ) ;
}
F_89 ( & V_30 -> V_20 , L_24 , V_20 -> V_27 ) ;
if ( ( ! V_20 -> V_26 && ! V_20 -> V_25 ) || ! V_20 -> V_94 ) {
F_90 ( & V_30 -> V_20 , L_25 ) ;
return - V_99 ;
}
V_93 = F_91 ( F_84 ( & V_20 -> V_30 -> V_20 ) ,
& V_90 , F_79 , V_20 ) ;
if ( V_93 < 0 )
return V_93 ;
F_92 ( & V_90 ) ;
V_92 = F_93 ( V_100 ) ;
if ( V_92 ) {
F_94 ( V_20 , L_26 ,
V_92 -> V_101 ) ;
V_20 -> V_44 = * ( V_102 * ) V_92 -> V_103 ;
}
return 0 ;
}
static int F_80 ( struct V_16 * V_20 )
{
return - V_99 ;
}
static int F_95 ( struct V_89 * V_30 )
{
struct V_16 * V_20 ;
int V_93 ;
V_20 = F_96 ( & V_30 -> V_20 , sizeof( * V_20 ) , V_49 ) ;
if ( ! V_20 )
return - V_50 ;
V_20 -> V_30 = V_30 ;
V_93 = F_80 ( V_20 ) ;
if ( V_93 )
return V_93 ;
F_97 ( V_30 , V_20 ) ;
F_89 ( & V_30 -> V_20 , L_27 , V_20 -> V_94 ) ;
F_22 ( & V_34 ) ;
F_98 ( & V_20 -> V_21 , & V_104 ) ;
F_29 ( & V_34 ) ;
F_13 ( V_20 , false ) ;
return 0 ;
}
static int F_99 ( struct V_89 * V_30 )
{
struct V_16 * V_20 = F_68 ( V_30 ) ;
F_22 ( & V_34 ) ;
F_100 ( & V_20 -> V_21 ) ;
F_29 ( & V_34 ) ;
F_101 ( F_84 ( & V_30 -> V_20 ) ) ;
F_89 ( & V_30 -> V_20 , L_28 , V_20 -> V_94 ) ;
return 0 ;
}
int T_2 F_102 ( void )
{
F_103 ( & V_105 ) ;
return F_104 ( & V_106 ) ;
}
int T_3 F_105 ( void )
{
F_106 ( & V_105 ) ;
return F_107 ( & V_106 ) ;
}
