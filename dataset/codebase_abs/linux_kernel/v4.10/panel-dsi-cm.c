static void F_1 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 = F_2 ( V_3 ) ;
V_2 -> V_5 = V_6 + V_2 -> V_4 ;
}
static void V_4 ( struct V_1 * V_2 )
{
unsigned long V_7 = V_2 -> V_5 - V_6 ;
if ( ( long ) V_7 > 0 && V_7 <= V_2 -> V_4 ) {
F_3 ( V_8 ) ;
F_4 ( V_7 ) ;
}
}
static int F_5 ( struct V_1 * V_2 , T_1 V_9 , T_1 * V_10 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
int V_13 ;
T_1 V_14 [ 1 ] ;
V_13 = V_12 -> V_15 . V_16 -> V_17 ( V_12 , V_2 -> V_18 , V_9 , V_14 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_10 = V_14 [ 0 ] ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_9 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
return V_12 -> V_15 . V_16 -> V_19 ( V_12 , V_2 -> V_18 , & V_9 , 1 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_9 , T_1 V_20 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
T_1 V_14 [ 2 ] = { V_9 , V_20 } ;
return V_12 -> V_15 . V_16 -> V_19 ( V_12 , V_2 -> V_18 , V_14 , 2 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
T_1 V_21 ;
int V_13 ;
V_4 ( V_2 ) ;
V_21 = V_22 ;
V_13 = V_12 -> V_15 . V_16 -> V_23 ( V_12 , V_2 -> V_18 , & V_21 , 1 ) ;
if ( V_13 )
return V_13 ;
F_1 ( V_2 , 120 ) ;
F_9 ( 5000 , 10000 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_13 ;
V_4 ( V_2 ) ;
V_13 = F_6 ( V_2 , V_24 ) ;
if ( V_13 )
return V_13 ;
F_1 ( V_2 , 120 ) ;
F_9 ( 5000 , 10000 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 * V_25 , T_1 * V_26 , T_1 * V_27 )
{
int V_13 ;
V_13 = F_5 ( V_2 , V_28 , V_25 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_5 ( V_2 , V_29 , V_26 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_5 ( V_2 , V_30 , V_27 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
T_2 V_31 , T_2 V_32 , T_2 V_33 , T_2 V_34 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
int V_13 ;
T_2 V_35 = V_31 ;
T_2 V_36 = V_31 + V_33 - 1 ;
T_2 y1 = V_32 ;
T_2 V_37 = V_32 + V_34 - 1 ;
T_1 V_14 [ 5 ] ;
V_14 [ 0 ] = V_38 ;
V_14 [ 1 ] = ( V_35 >> 8 ) & 0xff ;
V_14 [ 2 ] = ( V_35 >> 0 ) & 0xff ;
V_14 [ 3 ] = ( V_36 >> 8 ) & 0xff ;
V_14 [ 4 ] = ( V_36 >> 0 ) & 0xff ;
V_13 = V_12 -> V_15 . V_16 -> V_23 ( V_12 , V_2 -> V_18 , V_14 , sizeof( V_14 ) ) ;
if ( V_13 )
return V_13 ;
V_14 [ 0 ] = V_39 ;
V_14 [ 1 ] = ( y1 >> 8 ) & 0xff ;
V_14 [ 2 ] = ( y1 >> 0 ) & 0xff ;
V_14 [ 3 ] = ( V_37 >> 8 ) & 0xff ;
V_14 [ 4 ] = ( V_37 >> 0 ) & 0xff ;
V_13 = V_12 -> V_15 . V_16 -> V_23 ( V_12 , V_2 -> V_18 , V_14 , sizeof( V_14 ) ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_15 . V_16 -> V_40 ( V_12 , V_2 -> V_18 ) ;
return V_13 ;
}
static void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 > 0 )
F_14 ( V_2 -> V_42 , & V_2 -> V_43 ,
F_2 ( V_2 -> V_41 ) ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_43 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
int V_13 ;
if ( V_2 -> V_44 )
return 0 ;
F_15 ( V_2 ) ;
V_13 = F_18 ( V_2 , false ) ;
if ( V_13 )
goto V_45;
if ( F_19 ( V_2 -> V_46 ) )
F_20 ( F_21 ( V_2 -> V_46 ) ) ;
V_12 -> V_15 . V_16 -> V_47 ( V_12 , false , true ) ;
V_2 -> V_44 = true ;
return 0 ;
V_45:
F_22 ( & V_2 -> V_48 -> V_49 , L_1 ) ;
F_23 ( V_2 ) ;
V_2 -> V_44 = false ;
F_13 ( V_2 ) ;
return V_13 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
int V_13 ;
if ( ! V_2 -> V_44 )
return 0 ;
V_13 = V_12 -> V_15 . V_16 -> V_50 ( V_12 ) ;
if ( V_13 ) {
F_22 ( & V_2 -> V_48 -> V_49 , L_2 ) ;
goto V_51;
}
V_12 -> V_15 . V_16 -> V_52 ( V_12 , V_2 -> V_18 , true ) ;
V_13 = F_18 ( V_2 , true ) ;
if ( V_13 ) {
F_22 ( & V_2 -> V_48 -> V_49 , L_3 ) ;
goto V_53;
}
if ( F_19 ( V_2 -> V_46 ) )
F_25 ( F_21 ( V_2 -> V_46 ) ) ;
F_13 ( V_2 ) ;
V_2 -> V_44 = false ;
return 0 ;
V_53:
F_22 ( & V_2 -> V_48 -> V_49 , L_4 ) ;
V_13 = F_23 ( V_2 ) ;
if ( ! V_13 ) {
if ( F_19 ( V_2 -> V_46 ) )
F_25 ( F_21 ( V_2 -> V_46 ) ) ;
V_2 -> V_44 = false ;
}
V_51:
F_13 ( V_2 ) ;
return V_13 ;
}
static int F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_44 )
return F_24 ( V_2 ) ;
F_15 ( V_2 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_54 * V_49 )
{
struct V_1 * V_2 = F_28 ( & V_49 -> V_49 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
int V_13 ;
int V_55 ;
if ( V_49 -> V_56 . V_57 == V_58 &&
V_49 -> V_56 . V_59 == V_58 )
V_55 = V_49 -> V_56 . V_60 ;
else
V_55 = 0 ;
F_29 ( & V_2 -> V_48 -> V_49 , L_5 , V_55 ) ;
F_30 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_62 ) {
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
V_13 = F_26 ( V_2 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_2 , V_64 , V_55 ) ;
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
} else {
V_13 = 0 ;
}
F_31 ( & V_2 -> V_61 ) ;
return V_13 ;
}
static int F_32 ( struct V_54 * V_49 )
{
if ( V_49 -> V_56 . V_57 == V_58 &&
V_49 -> V_56 . V_59 == V_58 )
return V_49 -> V_56 . V_60 ;
return 0 ;
}
static void F_33 ( struct V_11 * V_66 ,
T_2 * V_67 , T_2 * V_68 )
{
* V_67 = V_66 -> V_69 . V_70 . V_71 ;
* V_68 = V_66 -> V_69 . V_70 . V_72 ;
}
static T_3 F_34 ( struct V_73 * V_49 ,
struct V_74 * V_75 , char * V_14 )
{
struct V_76 * V_48 = F_35 ( V_49 ) ;
struct V_1 * V_2 = F_36 ( V_48 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
T_1 V_77 = 0 ;
int V_13 ;
F_30 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_62 ) {
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
V_13 = F_26 ( V_2 ) ;
if ( ! V_13 )
V_13 = F_5 ( V_2 , V_78 ,
& V_77 ) ;
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
} else {
V_13 = - V_79 ;
}
F_31 ( & V_2 -> V_61 ) ;
if ( V_13 )
return V_13 ;
return snprintf ( V_14 , V_80 , L_6 , V_77 ) ;
}
static T_3 F_37 ( struct V_73 * V_49 ,
struct V_74 * V_75 , char * V_14 )
{
struct V_76 * V_48 = F_35 ( V_49 ) ;
struct V_1 * V_2 = F_36 ( V_48 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
T_1 V_25 , V_26 , V_27 ;
int V_13 ;
F_30 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_62 ) {
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
V_13 = F_26 ( V_2 ) ;
if ( ! V_13 )
V_13 = F_11 ( V_2 , & V_25 , & V_26 , & V_27 ) ;
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
} else {
V_13 = - V_79 ;
}
F_31 ( & V_2 -> V_61 ) ;
if ( V_13 )
return V_13 ;
return snprintf ( V_14 , V_80 , L_7 , V_25 , V_26 , V_27 ) ;
}
static T_3 F_38 ( struct V_73 * V_49 ,
struct V_74 * V_75 ,
const char * V_14 , T_4 V_81 )
{
struct V_76 * V_48 = F_35 ( V_49 ) ;
struct V_1 * V_2 = F_36 ( V_48 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
unsigned long V_82 ;
int V_13 ;
V_13 = F_39 ( V_14 , 0 , & V_82 ) ;
if ( V_13 )
return V_13 ;
F_30 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_62 ) {
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
if ( V_82 )
V_13 = F_17 ( V_2 ) ;
else
V_13 = F_26 ( V_2 ) ;
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
}
F_31 ( & V_2 -> V_61 ) ;
if ( V_13 )
return V_13 ;
return V_81 ;
}
static T_3 F_40 ( struct V_73 * V_49 ,
struct V_74 * V_75 ,
char * V_14 )
{
struct V_76 * V_48 = F_35 ( V_49 ) ;
struct V_1 * V_2 = F_36 ( V_48 ) ;
unsigned V_82 ;
F_30 ( & V_2 -> V_61 ) ;
V_82 = V_2 -> V_44 ;
F_31 ( & V_2 -> V_61 ) ;
return snprintf ( V_14 , V_80 , L_8 , V_82 ) ;
}
static T_3 F_41 ( struct V_73 * V_49 ,
struct V_74 * V_75 ,
const char * V_14 , T_4 V_81 )
{
struct V_76 * V_48 = F_35 ( V_49 ) ;
struct V_1 * V_2 = F_36 ( V_48 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
unsigned long V_82 ;
int V_13 ;
V_13 = F_39 ( V_14 , 0 , & V_82 ) ;
if ( V_13 )
return V_13 ;
F_30 ( & V_2 -> V_61 ) ;
V_2 -> V_41 = V_82 ;
if ( V_2 -> V_62 ) {
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
V_13 = F_26 ( V_2 ) ;
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
}
F_31 ( & V_2 -> V_61 ) ;
if ( V_13 )
return V_13 ;
return V_81 ;
}
static T_3 F_42 ( struct V_73 * V_49 ,
struct V_74 * V_75 ,
char * V_14 )
{
struct V_76 * V_48 = F_35 ( V_49 ) ;
struct V_1 * V_2 = F_36 ( V_48 ) ;
unsigned V_82 ;
F_30 ( & V_2 -> V_61 ) ;
V_82 = V_2 -> V_41 ;
F_31 ( & V_2 -> V_61 ) ;
return snprintf ( V_14 , V_80 , L_8 , V_82 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
if ( ! F_19 ( V_2 -> V_83 ) )
return;
F_44 ( V_2 -> V_83 , 1 ) ;
F_45 ( 10 ) ;
F_44 ( V_2 -> V_83 , 0 ) ;
F_45 ( 10 ) ;
F_44 ( V_2 -> V_83 , 1 ) ;
F_9 ( 5000 , 10000 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
T_1 V_25 , V_26 , V_27 ;
int V_13 ;
struct V_84 V_85 = {
. V_86 = V_87 ,
. V_88 = V_89 ,
. V_70 = & V_2 -> V_70 ,
. V_90 = 150000000 ,
. V_91 = 300000000 ,
. V_92 = 7000000 ,
. V_93 = 10000000 ,
} ;
if ( V_2 -> V_94 . V_95 > 0 ) {
V_13 = V_12 -> V_15 . V_16 -> V_96 ( V_12 , & V_2 -> V_94 ) ;
if ( V_13 ) {
F_22 ( & V_2 -> V_48 -> V_49 ,
L_9 ) ;
goto V_97;
}
}
V_13 = V_12 -> V_15 . V_16 -> V_98 ( V_12 , & V_85 ) ;
if ( V_13 ) {
F_22 ( & V_2 -> V_48 -> V_49 , L_10 ) ;
goto V_97;
}
V_13 = V_12 -> V_15 . V_16 -> V_50 ( V_12 ) ;
if ( V_13 ) {
F_22 ( & V_2 -> V_48 -> V_49 , L_2 ) ;
goto V_97;
}
F_43 ( V_2 ) ;
V_12 -> V_15 . V_16 -> V_52 ( V_12 , V_2 -> V_18 , false ) ;
V_13 = F_10 ( V_2 ) ;
if ( V_13 )
goto V_45;
V_13 = F_11 ( V_2 , & V_25 , & V_26 , & V_27 ) ;
if ( V_13 )
goto V_45;
V_13 = F_7 ( V_2 , V_64 , 0xff ) ;
if ( V_13 )
goto V_45;
V_13 = F_7 ( V_2 , V_99 ,
( 1 << 2 ) | ( 1 << 5 ) ) ;
if ( V_13 )
goto V_45;
V_13 = F_7 ( V_2 , V_100 ,
V_101 ) ;
if ( V_13 )
goto V_45;
V_13 = F_6 ( V_2 , V_102 ) ;
if ( V_13 )
goto V_45;
V_13 = F_18 ( V_2 , V_2 -> V_103 ) ;
if ( V_13 )
goto V_45;
V_13 = V_12 -> V_15 . V_16 -> V_104 ( V_12 , V_2 -> V_18 ) ;
if ( V_13 )
goto V_45;
V_2 -> V_62 = 1 ;
if ( ! V_2 -> V_105 ) {
F_47 ( & V_2 -> V_48 -> V_49 , L_11 ,
V_25 , V_26 , V_27 ) ;
V_2 -> V_105 = true ;
}
V_12 -> V_15 . V_16 -> V_52 ( V_12 , V_2 -> V_18 , true ) ;
return 0 ;
V_45:
F_22 ( & V_2 -> V_48 -> V_49 , L_12 ) ;
F_43 ( V_2 ) ;
V_12 -> V_15 . V_16 -> V_47 ( V_12 , true , false ) ;
V_97:
return V_13 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
int V_13 ;
V_12 -> V_15 . V_16 -> V_106 ( V_12 , V_2 -> V_18 ) ;
V_13 = F_6 ( V_2 , V_107 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_2 ) ;
if ( V_13 ) {
F_22 ( & V_2 -> V_48 -> V_49 ,
L_13 ) ;
F_43 ( V_2 ) ;
}
V_12 -> V_15 . V_16 -> V_47 ( V_12 , true , false ) ;
V_2 -> V_62 = 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_48 -> V_49 , L_14 ) ;
F_48 ( V_2 ) ;
F_43 ( V_2 ) ;
return F_46 ( V_2 ) ;
}
static int F_49 ( struct V_11 * V_66 )
{
struct V_1 * V_2 = F_50 ( V_66 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_73 * V_49 = & V_2 -> V_48 -> V_49 ;
int V_13 ;
if ( F_51 ( V_66 ) )
return 0 ;
V_13 = V_12 -> V_15 . V_16 -> V_108 ( V_12 , V_66 ) ;
if ( V_13 ) {
F_22 ( V_49 , L_15 ) ;
return V_13 ;
}
V_13 = V_12 -> V_15 . V_16 -> V_109 ( V_2 -> V_12 , & V_2 -> V_18 ) ;
if ( V_13 ) {
F_22 ( V_49 , L_16 ) ;
goto V_110;
}
V_13 = V_12 -> V_15 . V_16 -> V_111 ( V_2 -> V_12 , V_2 -> V_18 , V_112 ) ;
if ( V_13 ) {
F_22 ( V_49 , L_17 ) ;
goto V_113;
}
return 0 ;
V_113:
V_12 -> V_15 . V_16 -> V_114 ( V_2 -> V_12 , V_2 -> V_18 ) ;
V_110:
V_12 -> V_15 . V_16 -> V_115 ( V_12 , V_66 ) ;
return V_13 ;
}
static void F_52 ( struct V_11 * V_66 )
{
struct V_1 * V_2 = F_50 ( V_66 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
if ( ! F_51 ( V_66 ) )
return;
V_12 -> V_15 . V_16 -> V_114 ( V_12 , V_2 -> V_18 ) ;
V_12 -> V_15 . V_16 -> V_115 ( V_12 , V_66 ) ;
}
static int F_53 ( struct V_11 * V_66 )
{
struct V_1 * V_2 = F_50 ( V_66 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
int V_13 ;
F_29 ( & V_2 -> V_48 -> V_49 , L_18 ) ;
F_30 ( & V_2 -> V_61 ) ;
if ( ! F_51 ( V_66 ) ) {
V_13 = - V_79 ;
goto V_45;
}
if ( F_54 ( V_66 ) ) {
V_13 = 0 ;
goto V_45;
}
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
V_13 = F_46 ( V_2 ) ;
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
if ( V_13 )
goto V_45;
V_66 -> V_116 = V_117 ;
F_31 ( & V_2 -> V_61 ) ;
return 0 ;
V_45:
F_29 ( & V_2 -> V_48 -> V_49 , L_19 ) ;
F_31 ( & V_2 -> V_61 ) ;
return V_13 ;
}
static void F_55 ( struct V_11 * V_66 )
{
struct V_1 * V_2 = F_50 ( V_66 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
int V_13 ;
F_29 ( & V_2 -> V_48 -> V_49 , L_20 ) ;
F_30 ( & V_2 -> V_61 ) ;
F_15 ( V_2 ) ;
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
if ( F_54 ( V_66 ) ) {
V_13 = F_26 ( V_2 ) ;
if ( ! V_13 )
F_48 ( V_2 ) ;
}
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
V_66 -> V_116 = V_118 ;
F_31 ( & V_2 -> V_61 ) ;
}
static void F_56 ( int V_45 , void * V_10 )
{
struct V_1 * V_2 = V_10 ;
struct V_11 * V_12 = V_2 -> V_12 ;
F_29 ( & V_2 -> V_48 -> V_49 , L_21 , V_45 ) ;
V_12 -> V_15 . V_16 -> V_65 ( V_2 -> V_12 ) ;
}
static T_5 F_57 ( int V_119 , void * V_10 )
{
struct V_1 * V_2 = V_10 ;
struct V_11 * V_12 = V_2 -> V_12 ;
int V_120 ;
int V_13 ;
V_120 = F_58 ( & V_2 -> V_121 , 1 , 0 ) ;
if ( V_120 ) {
F_16 ( & V_2 -> V_122 ) ;
V_13 = V_12 -> V_15 . V_16 -> V_123 ( V_12 , V_2 -> V_18 , F_56 ,
V_2 ) ;
if ( V_13 )
goto V_45;
}
return V_124 ;
V_45:
F_22 ( & V_2 -> V_48 -> V_49 , L_22 ) ;
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
return V_124 ;
}
static void F_59 ( struct V_125 * V_126 )
{
struct V_1 * V_2 = F_60 ( V_126 , struct V_1 ,
V_122 . V_126 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
F_22 ( & V_2 -> V_48 -> V_49 , L_23 ) ;
F_61 ( & V_2 -> V_121 , 0 ) ;
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
}
static int F_62 ( struct V_11 * V_66 ,
T_2 V_31 , T_2 V_32 , T_2 V_33 , T_2 V_34 )
{
struct V_1 * V_2 = F_50 ( V_66 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
int V_13 ;
F_29 ( & V_2 -> V_48 -> V_49 , L_24 , V_31 , V_32 , V_33 , V_34 ) ;
F_30 ( & V_2 -> V_61 ) ;
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
V_13 = F_26 ( V_2 ) ;
if ( V_13 )
goto V_45;
if ( ! V_2 -> V_62 ) {
V_13 = 0 ;
goto V_45;
}
V_13 = F_12 ( V_2 , 0 , 0 ,
V_66 -> V_69 . V_70 . V_71 ,
V_66 -> V_69 . V_70 . V_72 ) ;
if ( V_13 )
goto V_45;
if ( V_2 -> V_103 && F_19 ( V_2 -> V_46 ) ) {
F_63 ( & V_2 -> V_122 ,
F_2 ( 250 ) ) ;
F_61 ( & V_2 -> V_121 , 1 ) ;
} else {
V_13 = V_12 -> V_15 . V_16 -> V_123 ( V_12 , V_2 -> V_18 , F_56 ,
V_2 ) ;
if ( V_13 )
goto V_45;
}
F_31 ( & V_2 -> V_61 ) ;
return 0 ;
V_45:
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
F_31 ( & V_2 -> V_61 ) ;
return V_13 ;
}
static int F_64 ( struct V_11 * V_66 )
{
struct V_1 * V_2 = F_50 ( V_66 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
F_29 ( & V_2 -> V_48 -> V_49 , L_25 ) ;
F_30 ( & V_2 -> V_61 ) ;
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
F_31 ( & V_2 -> V_61 ) ;
F_29 ( & V_2 -> V_48 -> V_49 , L_26 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , bool V_50 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
int V_13 ;
if ( V_50 )
V_13 = F_7 ( V_2 , V_127 , 0 ) ;
else
V_13 = F_6 ( V_2 , V_128 ) ;
if ( ! F_19 ( V_2 -> V_46 ) )
V_12 -> V_15 . V_16 -> V_129 ( V_12 , V_50 ) ;
F_65 ( 100 ) ;
return V_13 ;
}
static int F_66 ( struct V_11 * V_66 , bool V_50 )
{
struct V_1 * V_2 = F_50 ( V_66 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
int V_13 ;
F_30 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_103 == V_50 )
goto V_130;
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
if ( V_2 -> V_62 ) {
V_13 = F_26 ( V_2 ) ;
if ( V_13 )
goto V_45;
V_13 = F_18 ( V_2 , V_50 ) ;
if ( V_13 )
goto V_45;
}
V_2 -> V_103 = V_50 ;
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
V_130:
F_31 ( & V_2 -> V_61 ) ;
return 0 ;
V_45:
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
F_31 ( & V_2 -> V_61 ) ;
return V_13 ;
}
static int F_67 ( struct V_11 * V_66 )
{
struct V_1 * V_2 = F_50 ( V_66 ) ;
int V_13 ;
F_30 ( & V_2 -> V_61 ) ;
V_13 = V_2 -> V_103 ;
F_31 ( & V_2 -> V_61 ) ;
return V_13 ;
}
static int F_68 ( struct V_11 * V_66 ,
void * V_14 , T_4 V_131 ,
T_2 V_31 , T_2 V_32 , T_2 V_33 , T_2 V_34 )
{
struct V_1 * V_2 = F_50 ( V_66 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
int V_13 ;
int V_132 = 1 ;
int V_133 ;
unsigned V_134 = 0 ;
if ( V_131 < V_33 * V_34 * 3 )
return - V_135 ;
F_30 ( & V_2 -> V_61 ) ;
if ( ! V_2 -> V_62 ) {
V_13 = - V_79 ;
goto V_51;
}
V_131 = F_69 ( ( V_136 ) V_33 * V_34 * 3 ,
V_66 -> V_69 . V_70 . V_71 * V_66 -> V_69 . V_70 . V_72 * 3 ) ;
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
V_13 = F_26 ( V_2 ) ;
if ( V_13 )
goto V_53;
if ( V_131 % 2 )
V_133 = 1 ;
else
V_133 = 2 ;
F_12 ( V_2 , V_31 , V_32 , V_33 , V_34 ) ;
V_13 = V_12 -> V_15 . V_16 -> V_137 ( V_12 , V_2 -> V_18 , V_133 ) ;
if ( V_13 )
goto V_53;
while ( V_134 < V_131 ) {
T_1 V_9 = V_132 ? 0x2e : 0x3e ;
V_132 = 0 ;
V_13 = V_12 -> V_15 . V_16 -> V_17 ( V_12 , V_2 -> V_18 , V_9 ,
V_14 + V_134 , V_131 - V_134 ) ;
if ( V_13 < 0 ) {
F_22 ( V_66 -> V_49 , L_27 ) ;
goto V_138;
}
V_134 += V_13 ;
if ( V_13 < V_133 ) {
F_22 ( & V_2 -> V_48 -> V_49 , L_28 ) ;
break;
}
if ( F_70 ( V_139 ) ) {
F_22 ( & V_2 -> V_48 -> V_49 , L_29
L_30 ) ;
V_13 = - V_140 ;
goto V_138;
}
}
V_13 = V_134 ;
V_138:
V_12 -> V_15 . V_16 -> V_137 ( V_12 , V_2 -> V_18 , 1 ) ;
V_53:
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
V_51:
F_31 ( & V_2 -> V_61 ) ;
return V_13 ;
}
static void F_71 ( struct V_125 * V_126 )
{
struct V_1 * V_2 = F_60 ( V_126 , struct V_1 ,
V_43 . V_126 ) ;
struct V_11 * V_66 = & V_2 -> V_66 ;
struct V_11 * V_12 = V_2 -> V_12 ;
F_30 ( & V_2 -> V_61 ) ;
if ( V_66 -> V_116 != V_117 || ! V_2 -> V_62 ) {
F_31 ( & V_2 -> V_61 ) ;
return;
}
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
F_17 ( V_2 ) ;
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
F_31 ( & V_2 -> V_61 ) ;
}
static int F_72 ( struct V_76 * V_48 )
{
struct V_141 * V_142 = V_48 -> V_49 . V_143 ;
struct V_1 * V_2 = F_36 ( V_48 ) ;
struct V_11 * V_12 ;
int V_144 ;
V_144 = F_73 ( V_142 , L_31 , 0 ) ;
if ( ! F_19 ( V_144 ) ) {
F_22 ( & V_48 -> V_49 , L_32 ) ;
return V_144 ;
}
V_2 -> V_83 = V_144 ;
V_144 = F_73 ( V_142 , L_33 , 0 ) ;
if ( F_19 ( V_144 ) || V_144 == - V_145 ) {
V_2 -> V_46 = V_144 ;
} else {
F_22 ( & V_48 -> V_49 , L_34 ) ;
return V_144 ;
}
V_12 = F_74 ( V_142 ) ;
if ( F_75 ( V_12 ) ) {
F_22 ( & V_48 -> V_49 , L_35 ) ;
return F_76 ( V_12 ) ;
}
V_2 -> V_12 = V_12 ;
return 0 ;
}
static int F_77 ( struct V_76 * V_48 )
{
struct V_146 V_56 ;
struct V_1 * V_2 ;
struct V_54 * V_147 = NULL ;
struct V_73 * V_49 = & V_48 -> V_49 ;
struct V_11 * V_66 ;
int V_13 ;
F_29 ( V_49 , L_36 ) ;
V_2 = F_78 ( V_49 , sizeof( * V_2 ) , V_148 ) ;
if ( ! V_2 )
return - V_135 ;
F_79 ( V_48 , V_2 ) ;
V_2 -> V_48 = V_48 ;
if ( ! V_48 -> V_49 . V_143 )
return - V_79 ;
V_13 = F_72 ( V_48 ) ;
if ( V_13 )
return V_13 ;
V_2 -> V_70 . V_71 = 864 ;
V_2 -> V_70 . V_72 = 480 ;
V_2 -> V_70 . V_149 = 864 * 480 * 60 ;
V_66 = & V_2 -> V_66 ;
V_66 -> V_49 = V_49 ;
V_66 -> V_150 = & V_151 ;
V_66 -> V_69 . V_70 = V_2 -> V_70 ;
V_66 -> type = V_152 ;
V_66 -> V_153 = V_154 ;
V_66 -> V_69 . V_155 = V_89 ;
V_66 -> V_156 = V_157 |
V_158 ;
V_13 = F_80 ( V_66 ) ;
if ( V_13 ) {
F_22 ( V_49 , L_37 ) ;
goto V_159;
}
F_81 ( & V_2 -> V_61 ) ;
F_61 ( & V_2 -> V_121 , 0 ) ;
if ( F_19 ( V_2 -> V_83 ) ) {
V_13 = F_82 ( V_49 , V_2 -> V_83 ,
V_160 , L_38 ) ;
if ( V_13 ) {
F_22 ( V_49 , L_39 ) ;
return V_13 ;
}
}
if ( F_19 ( V_2 -> V_46 ) ) {
V_13 = F_82 ( V_49 , V_2 -> V_46 ,
V_161 , L_40 ) ;
if ( V_13 ) {
F_22 ( V_49 , L_41 ) ;
return V_13 ;
}
V_13 = F_83 ( V_49 , F_21 ( V_2 -> V_46 ) ,
F_57 ,
V_162 ,
L_42 , V_2 ) ;
if ( V_13 ) {
F_22 ( V_49 , L_43 ) ;
return V_13 ;
}
F_84 ( & V_2 -> V_122 ,
F_59 ) ;
F_29 ( V_49 , L_44 ) ;
}
V_2 -> V_42 = F_85 ( L_45 ) ;
if ( V_2 -> V_42 == NULL ) {
F_22 ( V_49 , L_46 ) ;
return - V_135 ;
}
F_86 ( & V_2 -> V_43 , F_71 ) ;
F_43 ( V_2 ) ;
if ( V_2 -> V_163 ) {
memset ( & V_56 , 0 , sizeof( struct V_146 ) ) ;
V_56 . V_164 = 255 ;
V_56 . type = V_165 ;
V_147 = F_87 ( F_88 ( V_49 ) ,
V_49 , V_2 , & V_166 , & V_56 ) ;
if ( F_75 ( V_147 ) ) {
V_13 = F_76 ( V_147 ) ;
goto V_167;
}
V_2 -> V_147 = V_147 ;
V_147 -> V_56 . V_57 = V_58 ;
V_147 -> V_56 . V_59 = V_58 ;
V_147 -> V_56 . V_60 = 255 ;
F_27 ( V_147 ) ;
}
V_13 = F_89 ( & V_49 -> V_168 , & V_169 ) ;
if ( V_13 ) {
F_22 ( V_49 , L_47 ) ;
goto V_170;
}
return 0 ;
V_170:
F_90 ( V_147 ) ;
V_167:
F_91 ( V_2 -> V_42 ) ;
V_159:
return V_13 ;
}
static int T_6 F_92 ( struct V_76 * V_48 )
{
struct V_1 * V_2 = F_36 ( V_48 ) ;
struct V_11 * V_66 = & V_2 -> V_66 ;
struct V_54 * V_147 ;
F_29 ( & V_48 -> V_49 , L_48 ) ;
F_93 ( V_66 ) ;
F_55 ( V_66 ) ;
F_52 ( V_66 ) ;
F_94 ( & V_48 -> V_49 . V_168 , & V_169 ) ;
V_147 = V_2 -> V_147 ;
if ( V_147 != NULL ) {
V_147 -> V_56 . V_59 = V_171 ;
F_27 ( V_147 ) ;
F_90 ( V_147 ) ;
}
F_95 ( V_2 -> V_12 ) ;
F_15 ( V_2 ) ;
F_91 ( V_2 -> V_42 ) ;
F_43 ( V_2 ) ;
return 0 ;
}
