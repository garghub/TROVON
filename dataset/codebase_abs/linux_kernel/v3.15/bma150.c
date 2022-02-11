static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_2 V_5 ;
if ( V_2 -> V_6 )
F_2 ( V_2 -> V_6 ) ;
V_5 = F_3 ( V_2 , V_3 , V_4 ) ;
if ( V_2 -> V_6 )
F_4 ( V_2 -> V_6 ) ;
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 ,
int V_4 , int V_7 , T_1 V_8 , T_1 V_3 )
{
int V_9 ;
V_9 = F_6 ( V_2 , V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = ( V_9 & ~ V_8 ) | ( ( V_4 << V_7 ) & V_8 ) ;
return F_1 ( V_2 , V_3 , V_9 ) ;
}
static int F_7 ( struct V_10 * V_11 , T_1 V_12 )
{
int error ;
error = F_5 ( V_11 -> V_2 , V_12 , V_13 ,
V_14 , V_15 ) ;
if ( error )
return error ;
error = F_5 ( V_11 -> V_2 , V_12 , V_16 ,
V_17 , V_18 ) ;
if ( error )
return error ;
if ( V_12 == V_19 )
F_8 ( 2 ) ;
V_11 -> V_12 = V_12 ;
return 0 ;
}
static int F_9 ( struct V_10 * V_11 )
{
int error ;
error = F_5 ( V_11 -> V_2 , 1 , V_20 ,
V_21 , V_22 ) ;
if ( error )
return error ;
F_8 ( 2 ) ;
return 0 ;
}
static int F_10 ( struct V_10 * V_11 , T_1 V_23 )
{
return F_5 ( V_11 -> V_2 , V_23 , V_24 ,
V_25 , V_26 ) ;
}
static int F_11 ( struct V_10 * V_11 , T_1 V_27 )
{
return F_5 ( V_11 -> V_2 , V_27 , V_28 ,
V_29 , V_30 ) ;
}
static int F_12 ( struct V_10 * V_11 ,
T_1 V_31 , T_1 V_32 , T_1 V_33 , T_1 V_34 )
{
int error ;
error = F_5 ( V_11 -> V_2 , V_32 ,
V_35 , V_36 ,
V_37 ) ;
if ( error )
return error ;
error = F_1 ( V_11 -> V_2 , V_38 , V_33 ) ;
if ( error )
return error ;
error = F_1 ( V_11 -> V_2 , V_39 , V_34 ) ;
if ( error )
return error ;
return F_5 ( V_11 -> V_2 , ! ! V_31 ,
V_40 , V_41 ,
V_42 ) ;
}
static int F_13 ( struct V_10 * V_11 ,
T_1 V_31 , T_1 V_32 , T_1 V_33 , T_1 V_34 )
{
int error ;
error = F_5 ( V_11 -> V_2 , V_32 ,
V_43 , V_44 ,
V_45 ) ;
if ( error )
return error ;
error = F_1 ( V_11 -> V_2 ,
V_46 , V_33 ) ;
if ( error )
return error ;
error = F_1 ( V_11 -> V_2 ,
V_47 , V_34 ) ;
if ( error )
return error ;
return F_5 ( V_11 -> V_2 , ! ! V_31 ,
V_48 , V_49 ,
V_50 ) ;
}
static int F_14 ( struct V_10 * V_11 ,
T_1 V_31 , T_1 V_33 , T_1 V_34 )
{
int error ;
error = F_5 ( V_11 -> V_2 , V_33 ,
V_51 ,
V_52 ,
V_53 ) ;
if ( error )
return error ;
error = F_1 ( V_11 -> V_2 ,
V_54 , V_34 ) ;
if ( error )
return error ;
error = F_5 ( V_11 -> V_2 , ! ! V_31 ,
V_55 , V_56 ,
V_57 ) ;
if ( error )
return error ;
return F_5 ( V_11 -> V_2 , ! ! V_31 ,
V_58 ,
V_59 ,
V_60 ) ;
}
static void F_15 ( struct V_10 * V_11 )
{
T_1 V_9 [ V_61 ] ;
T_3 V_62 , V_63 , V_64 ;
T_2 V_5 ;
V_5 = F_16 ( V_11 -> V_2 ,
V_65 , V_61 , V_9 ) ;
if ( V_5 != V_61 )
return;
V_62 = ( ( 0xc0 & V_9 [ 0 ] ) >> 6 ) | ( V_9 [ 1 ] << 2 ) ;
V_63 = ( ( 0xc0 & V_9 [ 2 ] ) >> 6 ) | ( V_9 [ 3 ] << 2 ) ;
V_64 = ( ( 0xc0 & V_9 [ 4 ] ) >> 6 ) | ( V_9 [ 5 ] << 2 ) ;
V_62 = ( T_3 ) ( V_62 << 6 ) >> 6 ;
V_63 = ( T_3 ) ( V_63 << 6 ) >> 6 ;
V_64 = ( T_3 ) ( V_64 << 6 ) >> 6 ;
F_17 ( V_11 -> V_66 , V_67 , V_62 ) ;
F_17 ( V_11 -> V_66 , V_68 , V_63 ) ;
F_17 ( V_11 -> V_66 , V_69 , V_64 ) ;
F_18 ( V_11 -> V_66 ) ;
}
static T_4 F_19 ( int V_6 , void * V_70 )
{
F_15 ( V_70 ) ;
return V_71 ;
}
static void F_20 ( struct V_72 * V_70 )
{
F_15 ( V_70 -> V_73 ) ;
}
static int F_21 ( struct V_10 * V_11 )
{
int error ;
error = F_22 ( & V_11 -> V_2 -> V_70 ) ;
if ( error < 0 && error != - V_74 )
return error ;
if ( V_11 -> V_12 != V_19 ) {
error = F_7 ( V_11 , V_19 ) ;
if ( error )
return error ;
}
return 0 ;
}
static void F_23 ( struct V_10 * V_11 )
{
F_24 ( & V_11 -> V_2 -> V_70 ) ;
if ( V_11 -> V_12 != V_75 )
F_7 ( V_11 , V_75 ) ;
}
static int F_25 ( struct V_76 * V_66 )
{
struct V_10 * V_11 = F_26 ( V_66 ) ;
return F_21 ( V_11 ) ;
}
static void F_27 ( struct V_76 * V_66 )
{
struct V_10 * V_11 = F_26 ( V_66 ) ;
F_23 ( V_11 ) ;
}
static void F_28 ( struct V_72 * V_77 )
{
struct V_10 * V_11 = V_77 -> V_73 ;
F_21 ( V_11 ) ;
}
static void F_29 ( struct V_72 * V_77 )
{
struct V_10 * V_11 = V_77 -> V_73 ;
F_23 ( V_11 ) ;
}
static int F_30 ( struct V_10 * V_11 ,
const struct V_78 * V_79 )
{
int error ;
error = F_9 ( V_11 ) ;
if ( error )
return error ;
error = F_11 ( V_11 , V_79 -> V_80 ) ;
if ( error )
return error ;
error = F_10 ( V_11 , V_79 -> V_23 ) ;
if ( error )
return error ;
if ( V_11 -> V_2 -> V_6 ) {
error = F_14 ( V_11 ,
V_79 -> V_81 ,
V_79 -> V_82 ,
V_79 -> V_83 ) ;
if ( error )
return error ;
error = F_13 ( V_11 ,
V_79 -> V_84 , V_79 -> V_85 ,
V_79 -> V_86 , V_79 -> V_87 ) ;
if ( error )
return error ;
error = F_12 ( V_11 ,
V_79 -> V_88 , V_79 -> V_89 ,
V_79 -> V_90 , V_79 -> V_91 ) ;
if ( error )
return error ;
}
return F_7 ( V_11 , V_75 ) ;
}
static void F_31 ( struct V_10 * V_11 ,
struct V_76 * V_92 )
{
V_92 -> V_93 = V_94 ;
V_92 -> V_95 = V_94 L_1 ;
V_92 -> V_96 . V_97 = V_98 ;
V_92 -> V_70 . V_99 = & V_11 -> V_2 -> V_70 ;
V_92 -> V_100 [ 0 ] = F_32 ( V_101 ) ;
F_33 ( V_92 , V_67 , V_102 , V_103 , 0 , 0 ) ;
F_33 ( V_92 , V_68 , V_102 , V_103 , 0 , 0 ) ;
F_33 ( V_92 , V_69 , V_102 , V_103 , 0 , 0 ) ;
}
static int F_34 ( struct V_10 * V_11 )
{
struct V_76 * V_92 ;
int error ;
V_92 = F_35 () ;
if ( ! V_92 )
return - V_104 ;
F_31 ( V_11 , V_92 ) ;
V_92 -> V_105 = F_25 ;
V_92 -> V_106 = F_27 ;
F_36 ( V_92 , V_11 ) ;
error = F_37 ( V_92 ) ;
if ( error ) {
F_38 ( V_92 ) ;
return error ;
}
V_11 -> V_66 = V_92 ;
return 0 ;
}
static int F_39 ( struct V_10 * V_11 )
{
struct V_72 * V_77 ;
int error ;
V_77 = F_40 () ;
if ( ! V_77 )
return - V_104 ;
V_77 -> V_73 = V_11 ;
V_77 -> V_105 = F_28 ;
V_77 -> V_106 = F_29 ;
V_77 -> V_107 = F_20 ;
V_77 -> V_108 = V_109 ;
V_77 -> V_110 = V_111 ;
V_77 -> V_112 = V_113 ;
F_31 ( V_11 , V_77 -> V_66 ) ;
error = F_41 ( V_77 ) ;
if ( error ) {
F_42 ( V_77 ) ;
return error ;
}
V_11 -> V_114 = V_77 ;
V_11 -> V_66 = V_77 -> V_66 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
const struct V_115 * V_96 )
{
const struct V_116 * V_117 =
F_44 ( & V_2 -> V_70 ) ;
const struct V_78 * V_79 ;
struct V_10 * V_11 ;
int V_118 ;
int error ;
if ( ! F_45 ( V_2 -> V_119 , V_120 ) ) {
F_46 ( & V_2 -> V_70 , L_2 ) ;
return - V_121 ;
}
V_118 = F_6 ( V_2 , V_122 ) ;
if ( V_118 != V_123 && V_118 != V_124 ) {
F_46 ( & V_2 -> V_70 , L_3 , V_118 ) ;
return - V_125 ;
}
V_11 = F_47 ( sizeof( struct V_10 ) , V_126 ) ;
if ( ! V_11 )
return - V_104 ;
V_11 -> V_2 = V_2 ;
if ( V_117 ) {
if ( V_117 -> V_127 ) {
error = V_117 -> V_127 () ;
if ( error ) {
F_46 ( & V_2 -> V_70 ,
L_4 ,
V_2 -> V_6 , error ) ;
goto V_128;
}
}
V_79 = & V_117 -> V_79 ;
} else {
V_79 = & V_129 ;
}
error = F_30 ( V_11 , V_79 ) ;
if ( error )
goto V_128;
if ( V_2 -> V_6 > 0 ) {
error = F_34 ( V_11 ) ;
if ( error )
goto V_128;
error = F_48 ( V_2 -> V_6 ,
NULL , F_19 ,
V_130 | V_131 ,
V_94 , V_11 ) ;
if ( error ) {
F_46 ( & V_2 -> V_70 ,
L_5 ,
V_2 -> V_6 , error ) ;
F_49 ( V_11 -> V_66 ) ;
goto V_128;
}
} else {
error = F_39 ( V_11 ) ;
if ( error )
goto V_128;
}
F_50 ( V_2 , V_11 ) ;
F_51 ( & V_2 -> V_70 ) ;
return 0 ;
V_128:
F_52 ( V_11 ) ;
return error ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_54 ( V_2 ) ;
F_55 ( & V_2 -> V_70 ) ;
if ( V_2 -> V_6 > 0 ) {
F_56 ( V_2 -> V_6 , V_11 ) ;
F_49 ( V_11 -> V_66 ) ;
} else {
F_57 ( V_11 -> V_114 ) ;
F_42 ( V_11 -> V_114 ) ;
}
F_52 ( V_11 ) ;
return 0 ;
}
static int F_58 ( struct V_132 * V_70 )
{
struct V_1 * V_2 = F_59 ( V_70 ) ;
struct V_10 * V_11 = F_54 ( V_2 ) ;
return F_7 ( V_11 , V_75 ) ;
}
static int F_60 ( struct V_132 * V_70 )
{
struct V_1 * V_2 = F_59 ( V_70 ) ;
struct V_10 * V_11 = F_54 ( V_2 ) ;
return F_7 ( V_11 , V_19 ) ;
}
