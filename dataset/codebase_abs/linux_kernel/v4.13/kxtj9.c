static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
struct V_6 V_7 [] = {
{
. V_3 = V_2 -> V_8 -> V_3 ,
. V_9 = V_2 -> V_8 -> V_9 ,
. V_5 = 1 ,
. V_10 = & V_3 ,
} ,
{
. V_3 = V_2 -> V_8 -> V_3 ,
. V_9 = V_2 -> V_8 -> V_9 | V_11 ,
. V_5 = V_5 ,
. V_10 = V_4 ,
} ,
} ;
return F_2 ( V_2 -> V_8 -> V_12 , V_7 , 2 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_2 V_13 [ 3 ] ;
T_2 V_14 , V_15 , V_16 ;
int V_17 ;
V_17 = F_1 ( V_2 , V_18 , ( T_1 * ) V_13 , 6 ) ;
if ( V_17 < 0 )
F_4 ( & V_2 -> V_8 -> V_19 , L_1 ) ;
V_14 = F_5 ( V_13 [ V_2 -> V_20 . V_21 ] ) ;
V_15 = F_5 ( V_13 [ V_2 -> V_20 . V_22 ] ) ;
V_16 = F_5 ( V_13 [ V_2 -> V_20 . V_23 ] ) ;
V_14 >>= V_2 -> V_24 ;
V_15 >>= V_2 -> V_24 ;
V_16 >>= V_2 -> V_24 ;
F_6 ( V_2 -> V_25 , V_26 , V_2 -> V_20 . V_27 ? - V_14 : V_14 ) ;
F_6 ( V_2 -> V_25 , V_28 , V_2 -> V_20 . V_29 ? - V_15 : V_15 ) ;
F_6 ( V_2 -> V_25 , V_30 , V_2 -> V_20 . V_31 ? - V_16 : V_16 ) ;
F_7 ( V_2 -> V_25 ) ;
}
static T_3 F_8 ( int V_32 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
int V_17 ;
F_3 ( V_2 ) ;
V_17 = F_9 ( V_2 -> V_8 , V_33 ) ;
if ( V_17 < 0 )
F_4 ( & V_2 -> V_8 -> V_19 ,
L_2 , V_17 ) ;
return V_34 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_35 )
{
switch ( V_35 ) {
case V_36 :
V_2 -> V_24 = 4 ;
break;
case V_37 :
V_2 -> V_24 = 3 ;
break;
case V_38 :
V_2 -> V_24 = 2 ;
break;
default:
return - V_39 ;
}
V_2 -> V_40 &= 0xe7 ;
V_2 -> V_40 |= V_35 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int V_41 )
{
int V_17 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < F_12 ( V_43 ) ; V_42 ++ ) {
V_2 -> V_44 = V_43 [ V_42 ] . V_45 ;
if ( V_41 < V_43 [ V_42 ] . V_46 )
break;
}
V_17 = F_13 ( V_2 -> V_8 , V_47 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_13 ( V_2 -> V_8 , V_48 , V_2 -> V_44 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_13 ( V_2 -> V_8 , V_47 , V_2 -> V_40 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_20 . V_49 )
return V_2 -> V_20 . V_49 () ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
int V_17 ;
V_2 -> V_40 &= V_50 ;
V_17 = F_13 ( V_2 -> V_8 , V_47 , V_2 -> V_40 ) ;
if ( V_17 < 0 )
F_4 ( & V_2 -> V_8 -> V_19 , L_3 ) ;
if ( V_2 -> V_20 . V_51 )
V_2 -> V_20 . V_51 () ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_17 ;
V_17 = F_14 ( V_2 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_13 ( V_2 -> V_8 , V_47 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_2 -> V_8 -> V_32 ) {
V_17 = F_13 ( V_2 -> V_8 ,
V_52 , V_2 -> V_53 ) ;
if ( V_17 < 0 )
return V_17 ;
}
V_17 = F_10 ( V_2 , V_2 -> V_20 . V_54 ) ;
if ( V_17 < 0 )
return V_17 ;
V_2 -> V_40 |= V_55 ;
V_17 = F_13 ( V_2 -> V_8 , V_47 , V_2 -> V_40 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_11 ( V_2 , V_2 -> V_56 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_2 -> V_8 -> V_32 ) {
V_17 = F_9 ( V_2 -> V_8 , V_33 ) ;
if ( V_17 < 0 ) {
F_4 ( & V_2 -> V_8 -> V_19 ,
L_4 , V_17 ) ;
goto V_57;
}
}
return 0 ;
V_57:
F_15 ( V_2 ) ;
return V_17 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
}
static int F_18 ( struct V_25 * V_58 )
{
struct V_1 * V_2 = F_19 ( V_58 ) ;
return F_16 ( V_2 ) ;
}
static void F_20 ( struct V_25 * V_19 )
{
struct V_1 * V_2 = F_19 ( V_19 ) ;
F_17 ( V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_25 * V_25 )
{
F_22 ( V_59 , V_25 -> V_60 ) ;
F_23 ( V_25 , V_26 , - V_61 , V_61 , V_62 , V_63 ) ;
F_23 ( V_25 , V_28 , - V_61 , V_61 , V_62 , V_63 ) ;
F_23 ( V_25 , V_30 , - V_61 , V_61 , V_62 , V_63 ) ;
V_25 -> V_64 = L_5 ;
V_25 -> V_65 . V_66 = V_67 ;
V_25 -> V_19 . V_68 = & V_2 -> V_8 -> V_19 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_25 * V_25 ;
int V_17 ;
V_25 = F_25 () ;
if ( ! V_25 ) {
F_4 ( & V_2 -> V_8 -> V_19 , L_6 ) ;
return - V_69 ;
}
V_2 -> V_25 = V_25 ;
V_25 -> V_70 = F_18 ;
V_25 -> V_71 = F_20 ;
F_26 ( V_25 , V_2 ) ;
F_21 ( V_2 , V_25 ) ;
V_17 = F_27 ( V_2 -> V_25 ) ;
if ( V_17 ) {
F_4 ( & V_2 -> V_8 -> V_19 ,
L_7 ,
V_2 -> V_25 -> V_64 , V_17 ) ;
F_28 ( V_2 -> V_25 ) ;
return V_17 ;
}
return 0 ;
}
static T_4 F_29 ( struct V_72 * V_19 ,
struct V_73 * V_74 , char * V_10 )
{
struct V_75 * V_8 = F_30 ( V_19 ) ;
struct V_1 * V_2 = F_31 ( V_8 ) ;
return sprintf ( V_10 , L_8 , V_2 -> V_56 ) ;
}
static T_4 F_32 ( struct V_72 * V_19 , struct V_73 * V_74 ,
const char * V_10 , T_5 V_76 )
{
struct V_75 * V_8 = F_30 ( V_19 ) ;
struct V_1 * V_2 = F_31 ( V_8 ) ;
struct V_25 * V_25 = V_2 -> V_25 ;
unsigned int V_77 ;
int error ;
error = F_33 ( V_10 , 10 , & V_77 ) ;
if ( error < 0 )
return error ;
F_34 ( & V_25 -> V_78 ) ;
F_35 ( V_8 -> V_32 ) ;
V_2 -> V_56 = F_36 ( V_77 , V_2 -> V_20 . V_79 ) ;
F_11 ( V_2 , V_2 -> V_56 ) ;
F_37 ( V_8 -> V_32 ) ;
F_38 ( & V_25 -> V_78 ) ;
return V_76 ;
}
static void F_39 ( struct V_80 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_81 ;
unsigned int V_41 = V_19 -> V_41 ;
F_3 ( V_2 ) ;
if ( V_41 != V_2 -> V_56 ) {
F_11 ( V_2 , V_41 ) ;
V_2 -> V_56 = V_41 ;
}
}
static void F_40 ( struct V_80 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_81 ;
F_16 ( V_2 ) ;
}
static void F_41 ( struct V_80 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_81 ;
F_17 ( V_2 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_80 * V_82 ;
V_82 = F_43 () ;
if ( ! V_82 ) {
F_4 ( & V_2 -> V_8 -> V_19 ,
L_9 ) ;
return - V_69 ;
}
V_2 -> V_82 = V_82 ;
V_2 -> V_25 = V_82 -> V_58 ;
V_82 -> V_81 = V_2 ;
V_82 -> V_83 = F_39 ;
V_82 -> V_70 = F_40 ;
V_82 -> V_71 = F_41 ;
F_21 ( V_2 , V_82 -> V_58 ) ;
V_17 = F_44 ( V_82 ) ;
if ( V_17 ) {
F_4 ( & V_2 -> V_8 -> V_19 ,
L_10 , V_17 ) ;
F_45 ( V_82 ) ;
return V_17 ;
}
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_47 ( V_2 -> V_82 ) ;
F_45 ( V_2 -> V_82 ) ;
}
static inline int F_42 ( struct V_1 * V_2 )
{
return - V_84 ;
}
static inline void F_46 ( struct V_1 * V_2 )
{
}
static int F_48 ( struct V_1 * V_2 )
{
int V_85 ;
V_85 = F_14 ( V_2 ) ;
if ( V_85 < 0 )
return V_85 ;
V_85 = F_9 ( V_2 -> V_8 , V_86 ) ;
if ( V_85 < 0 ) {
F_4 ( & V_2 -> V_8 -> V_19 , L_11 ) ;
goto V_87;
}
V_85 = ( V_85 != 0x07 && V_85 != 0x08 ) ? - V_88 : 0 ;
V_87:
F_15 ( V_2 ) ;
return V_85 ;
}
static int F_49 ( struct V_75 * V_8 ,
const struct V_89 * V_65 )
{
const struct V_90 * V_20 =
F_50 ( & V_8 -> V_19 ) ;
struct V_1 * V_2 ;
int V_17 ;
if ( ! F_51 ( V_8 -> V_12 ,
V_91 | V_92 ) ) {
F_4 ( & V_8 -> V_19 , L_12 ) ;
return - V_93 ;
}
if ( ! V_20 ) {
F_4 ( & V_8 -> V_19 , L_13 ) ;
return - V_39 ;
}
V_2 = F_52 ( sizeof( * V_2 ) , V_94 ) ;
if ( ! V_2 ) {
F_4 ( & V_8 -> V_19 ,
L_14 ) ;
return - V_69 ;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_20 = * V_20 ;
if ( V_20 -> V_95 ) {
V_17 = V_20 -> V_95 () ;
if ( V_17 < 0 )
goto V_96;
}
V_17 = F_48 ( V_2 ) ;
if ( V_17 < 0 ) {
F_4 ( & V_8 -> V_19 , L_15 ) ;
goto V_97;
}
F_53 ( V_8 , V_2 ) ;
V_2 -> V_40 = V_2 -> V_20 . V_98 | V_2 -> V_20 . V_54 ;
V_2 -> V_56 = V_2 -> V_20 . V_99 ;
if ( V_8 -> V_32 ) {
V_2 -> V_53 |= V_100 | V_101 | V_102 ;
V_2 -> V_40 |= V_103 ;
V_17 = F_24 ( V_2 ) ;
if ( V_17 )
goto V_97;
V_17 = F_54 ( V_8 -> V_32 , NULL , F_8 ,
V_104 | V_105 ,
L_16 , V_2 ) ;
if ( V_17 ) {
F_4 ( & V_8 -> V_19 , L_17 , V_17 ) ;
goto V_106;
}
V_17 = F_55 ( & V_8 -> V_19 . V_107 , & V_108 ) ;
if ( V_17 ) {
F_4 ( & V_8 -> V_19 , L_18 , V_17 ) ;
goto V_109;
}
} else {
V_17 = F_42 ( V_2 ) ;
if ( V_17 )
goto V_97;
}
return 0 ;
V_109:
F_56 ( V_8 -> V_32 , V_2 ) ;
V_106:
F_57 ( V_2 -> V_25 ) ;
V_97:
if ( V_2 -> V_20 . exit )
V_2 -> V_20 . exit () ;
V_96:
F_58 ( V_2 ) ;
return V_17 ;
}
static int F_59 ( struct V_75 * V_8 )
{
struct V_1 * V_2 = F_31 ( V_8 ) ;
if ( V_8 -> V_32 ) {
F_60 ( & V_8 -> V_19 . V_107 , & V_108 ) ;
F_56 ( V_8 -> V_32 , V_2 ) ;
F_57 ( V_2 -> V_25 ) ;
} else {
F_46 ( V_2 ) ;
}
if ( V_2 -> V_20 . exit )
V_2 -> V_20 . exit () ;
F_58 ( V_2 ) ;
return 0 ;
}
static int T_6 F_61 ( struct V_72 * V_19 )
{
struct V_75 * V_8 = F_30 ( V_19 ) ;
struct V_1 * V_2 = F_31 ( V_8 ) ;
struct V_25 * V_25 = V_2 -> V_25 ;
F_34 ( & V_25 -> V_78 ) ;
if ( V_25 -> V_110 )
F_17 ( V_2 ) ;
F_38 ( & V_25 -> V_78 ) ;
return 0 ;
}
static int T_6 F_62 ( struct V_72 * V_19 )
{
struct V_75 * V_8 = F_30 ( V_19 ) ;
struct V_1 * V_2 = F_31 ( V_8 ) ;
struct V_25 * V_25 = V_2 -> V_25 ;
F_34 ( & V_25 -> V_78 ) ;
if ( V_25 -> V_110 )
F_16 ( V_2 ) ;
F_38 ( & V_25 -> V_78 ) ;
return 0 ;
}
