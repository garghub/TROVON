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
static T_3 F_33 ( struct V_66 * V_49 ,
struct V_67 * V_68 , char * V_14 )
{
struct V_69 * V_48 = F_34 ( V_49 ) ;
struct V_1 * V_2 = F_35 ( V_48 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
T_1 V_70 = 0 ;
int V_13 ;
F_30 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_62 ) {
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
V_13 = F_26 ( V_2 ) ;
if ( ! V_13 )
V_13 = F_5 ( V_2 , V_71 ,
& V_70 ) ;
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
} else {
V_13 = - V_72 ;
}
F_31 ( & V_2 -> V_61 ) ;
if ( V_13 )
return V_13 ;
return snprintf ( V_14 , V_73 , L_6 , V_70 ) ;
}
static T_3 F_36 ( struct V_66 * V_49 ,
struct V_67 * V_68 , char * V_14 )
{
struct V_69 * V_48 = F_34 ( V_49 ) ;
struct V_1 * V_2 = F_35 ( V_48 ) ;
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
V_13 = - V_72 ;
}
F_31 ( & V_2 -> V_61 ) ;
if ( V_13 )
return V_13 ;
return snprintf ( V_14 , V_73 , L_7 , V_25 , V_26 , V_27 ) ;
}
static T_3 F_37 ( struct V_66 * V_49 ,
struct V_67 * V_68 ,
const char * V_14 , T_4 V_74 )
{
struct V_69 * V_48 = F_34 ( V_49 ) ;
struct V_1 * V_2 = F_35 ( V_48 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
unsigned long V_75 ;
int V_13 ;
V_13 = F_38 ( V_14 , 0 , & V_75 ) ;
if ( V_13 )
return V_13 ;
F_30 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_62 ) {
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
if ( V_75 )
V_13 = F_17 ( V_2 ) ;
else
V_13 = F_26 ( V_2 ) ;
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
}
F_31 ( & V_2 -> V_61 ) ;
if ( V_13 )
return V_13 ;
return V_74 ;
}
static T_3 F_39 ( struct V_66 * V_49 ,
struct V_67 * V_68 ,
char * V_14 )
{
struct V_69 * V_48 = F_34 ( V_49 ) ;
struct V_1 * V_2 = F_35 ( V_48 ) ;
unsigned V_75 ;
F_30 ( & V_2 -> V_61 ) ;
V_75 = V_2 -> V_44 ;
F_31 ( & V_2 -> V_61 ) ;
return snprintf ( V_14 , V_73 , L_8 , V_75 ) ;
}
static T_3 F_40 ( struct V_66 * V_49 ,
struct V_67 * V_68 ,
const char * V_14 , T_4 V_74 )
{
struct V_69 * V_48 = F_34 ( V_49 ) ;
struct V_1 * V_2 = F_35 ( V_48 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
unsigned long V_75 ;
int V_13 ;
V_13 = F_38 ( V_14 , 0 , & V_75 ) ;
if ( V_13 )
return V_13 ;
F_30 ( & V_2 -> V_61 ) ;
V_2 -> V_41 = V_75 ;
if ( V_2 -> V_62 ) {
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
V_13 = F_26 ( V_2 ) ;
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
}
F_31 ( & V_2 -> V_61 ) ;
if ( V_13 )
return V_13 ;
return V_74 ;
}
static T_3 F_41 ( struct V_66 * V_49 ,
struct V_67 * V_68 ,
char * V_14 )
{
struct V_69 * V_48 = F_34 ( V_49 ) ;
struct V_1 * V_2 = F_35 ( V_48 ) ;
unsigned V_75 ;
F_30 ( & V_2 -> V_61 ) ;
V_75 = V_2 -> V_41 ;
F_31 ( & V_2 -> V_61 ) ;
return snprintf ( V_14 , V_73 , L_8 , V_75 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
if ( ! F_19 ( V_2 -> V_76 ) )
return;
F_43 ( V_2 -> V_76 , 1 ) ;
F_44 ( 10 ) ;
F_43 ( V_2 -> V_76 , 0 ) ;
F_44 ( 10 ) ;
F_43 ( V_2 -> V_76 , 1 ) ;
F_9 ( 5000 , 10000 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
T_1 V_25 , V_26 , V_27 ;
int V_13 ;
struct V_77 V_78 = {
. V_79 = V_80 ,
. V_81 = V_82 ,
. V_83 = & V_2 -> V_83 ,
. V_84 = 150000000 ,
. V_85 = 300000000 ,
. V_86 = 7000000 ,
. V_87 = 10000000 ,
} ;
if ( V_2 -> V_88 . V_89 > 0 ) {
V_13 = V_12 -> V_15 . V_16 -> V_90 ( V_12 , & V_2 -> V_88 ) ;
if ( V_13 ) {
F_22 ( & V_2 -> V_48 -> V_49 ,
L_9 ) ;
goto V_91;
}
}
V_13 = V_12 -> V_15 . V_16 -> V_92 ( V_12 , & V_78 ) ;
if ( V_13 ) {
F_22 ( & V_2 -> V_48 -> V_49 , L_10 ) ;
goto V_91;
}
V_13 = V_12 -> V_15 . V_16 -> V_50 ( V_12 ) ;
if ( V_13 ) {
F_22 ( & V_2 -> V_48 -> V_49 , L_2 ) ;
goto V_91;
}
F_42 ( V_2 ) ;
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
V_13 = F_7 ( V_2 , V_93 ,
( 1 << 2 ) | ( 1 << 5 ) ) ;
if ( V_13 )
goto V_45;
V_13 = F_7 ( V_2 , V_94 ,
V_95 ) ;
if ( V_13 )
goto V_45;
V_13 = F_6 ( V_2 , V_96 ) ;
if ( V_13 )
goto V_45;
V_13 = F_18 ( V_2 , V_2 -> V_97 ) ;
if ( V_13 )
goto V_45;
V_13 = V_12 -> V_15 . V_16 -> V_98 ( V_12 , V_2 -> V_18 ) ;
if ( V_13 )
goto V_45;
V_2 -> V_62 = 1 ;
if ( ! V_2 -> V_99 ) {
F_46 ( & V_2 -> V_48 -> V_49 , L_11 ,
V_25 , V_26 , V_27 ) ;
V_2 -> V_99 = true ;
}
V_12 -> V_15 . V_16 -> V_52 ( V_12 , V_2 -> V_18 , true ) ;
return 0 ;
V_45:
F_22 ( & V_2 -> V_48 -> V_49 , L_12 ) ;
F_42 ( V_2 ) ;
V_12 -> V_15 . V_16 -> V_47 ( V_12 , true , false ) ;
V_91:
return V_13 ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
int V_13 ;
V_12 -> V_15 . V_16 -> V_100 ( V_12 , V_2 -> V_18 ) ;
V_13 = F_6 ( V_2 , V_101 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_2 ) ;
if ( V_13 ) {
F_22 ( & V_2 -> V_48 -> V_49 ,
L_13 ) ;
F_42 ( V_2 ) ;
}
V_12 -> V_15 . V_16 -> V_47 ( V_12 , true , false ) ;
V_2 -> V_62 = 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_48 -> V_49 , L_14 ) ;
F_47 ( V_2 ) ;
F_42 ( V_2 ) ;
return F_45 ( V_2 ) ;
}
static int F_48 ( struct V_11 * V_102 )
{
struct V_1 * V_2 = F_49 ( V_102 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_66 * V_49 = & V_2 -> V_48 -> V_49 ;
int V_13 ;
if ( F_50 ( V_102 ) )
return 0 ;
V_13 = V_12 -> V_15 . V_16 -> V_103 ( V_12 , V_102 ) ;
if ( V_13 ) {
F_22 ( V_49 , L_15 ) ;
return V_13 ;
}
V_13 = V_12 -> V_15 . V_16 -> V_104 ( V_2 -> V_12 , & V_2 -> V_18 ) ;
if ( V_13 ) {
F_22 ( V_49 , L_16 ) ;
goto V_105;
}
V_13 = V_12 -> V_15 . V_16 -> V_106 ( V_2 -> V_12 , V_2 -> V_18 , V_107 ) ;
if ( V_13 ) {
F_22 ( V_49 , L_17 ) ;
goto V_108;
}
return 0 ;
V_108:
V_12 -> V_15 . V_16 -> V_109 ( V_2 -> V_12 , V_2 -> V_18 ) ;
V_105:
V_12 -> V_15 . V_16 -> V_110 ( V_12 , V_102 ) ;
return V_13 ;
}
static void F_51 ( struct V_11 * V_102 )
{
struct V_1 * V_2 = F_49 ( V_102 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
if ( ! F_50 ( V_102 ) )
return;
V_12 -> V_15 . V_16 -> V_109 ( V_12 , V_2 -> V_18 ) ;
V_12 -> V_15 . V_16 -> V_110 ( V_12 , V_102 ) ;
}
static int F_52 ( struct V_11 * V_102 )
{
struct V_1 * V_2 = F_49 ( V_102 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
int V_13 ;
F_29 ( & V_2 -> V_48 -> V_49 , L_18 ) ;
F_30 ( & V_2 -> V_61 ) ;
if ( ! F_50 ( V_102 ) ) {
V_13 = - V_72 ;
goto V_45;
}
if ( F_53 ( V_102 ) ) {
V_13 = 0 ;
goto V_45;
}
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
V_13 = F_45 ( V_2 ) ;
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
if ( V_13 )
goto V_45;
V_102 -> V_111 = V_112 ;
F_31 ( & V_2 -> V_61 ) ;
return 0 ;
V_45:
F_29 ( & V_2 -> V_48 -> V_49 , L_19 ) ;
F_31 ( & V_2 -> V_61 ) ;
return V_13 ;
}
static void F_54 ( struct V_11 * V_102 )
{
struct V_1 * V_2 = F_49 ( V_102 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
int V_13 ;
F_29 ( & V_2 -> V_48 -> V_49 , L_20 ) ;
F_30 ( & V_2 -> V_61 ) ;
F_15 ( V_2 ) ;
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
if ( F_53 ( V_102 ) ) {
V_13 = F_26 ( V_2 ) ;
if ( ! V_13 )
F_47 ( V_2 ) ;
}
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
V_102 -> V_111 = V_113 ;
F_31 ( & V_2 -> V_61 ) ;
}
static void F_55 ( int V_45 , void * V_10 )
{
struct V_1 * V_2 = V_10 ;
struct V_11 * V_12 = V_2 -> V_12 ;
F_29 ( & V_2 -> V_48 -> V_49 , L_21 , V_45 ) ;
V_12 -> V_15 . V_16 -> V_65 ( V_2 -> V_12 ) ;
}
static T_5 F_56 ( int V_114 , void * V_10 )
{
struct V_1 * V_2 = V_10 ;
struct V_11 * V_12 = V_2 -> V_12 ;
int V_115 ;
int V_13 ;
V_115 = F_57 ( & V_2 -> V_116 , 1 , 0 ) ;
if ( V_115 ) {
F_16 ( & V_2 -> V_117 ) ;
V_13 = V_12 -> V_15 . V_16 -> V_118 ( V_12 , V_2 -> V_18 , F_55 ,
V_2 ) ;
if ( V_13 )
goto V_45;
}
return V_119 ;
V_45:
F_22 ( & V_2 -> V_48 -> V_49 , L_22 ) ;
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
return V_119 ;
}
static void F_58 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_59 ( V_121 , struct V_1 ,
V_117 . V_121 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
F_22 ( & V_2 -> V_48 -> V_49 , L_23 ) ;
F_60 ( & V_2 -> V_116 , 0 ) ;
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
}
static int F_61 ( struct V_11 * V_102 ,
T_2 V_31 , T_2 V_32 , T_2 V_33 , T_2 V_34 )
{
struct V_1 * V_2 = F_49 ( V_102 ) ;
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
V_102 -> V_122 . V_83 . V_123 ,
V_102 -> V_122 . V_83 . V_124 ) ;
if ( V_13 )
goto V_45;
if ( V_2 -> V_97 && F_19 ( V_2 -> V_46 ) ) {
F_62 ( & V_2 -> V_117 ,
F_2 ( 250 ) ) ;
F_60 ( & V_2 -> V_116 , 1 ) ;
} else {
V_13 = V_12 -> V_15 . V_16 -> V_118 ( V_12 , V_2 -> V_18 , F_55 ,
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
static int F_63 ( struct V_11 * V_102 )
{
struct V_1 * V_2 = F_49 ( V_102 ) ;
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
V_13 = F_7 ( V_2 , V_125 , 0 ) ;
else
V_13 = F_6 ( V_2 , V_126 ) ;
if ( ! F_19 ( V_2 -> V_46 ) )
V_12 -> V_15 . V_16 -> V_127 ( V_12 , V_50 ) ;
F_64 ( 100 ) ;
return V_13 ;
}
static int F_65 ( struct V_11 * V_102 , bool V_50 )
{
struct V_1 * V_2 = F_49 ( V_102 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
int V_13 ;
F_30 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_97 == V_50 )
goto V_128;
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
if ( V_2 -> V_62 ) {
V_13 = F_26 ( V_2 ) ;
if ( V_13 )
goto V_45;
V_13 = F_18 ( V_2 , V_50 ) ;
if ( V_13 )
goto V_45;
}
V_2 -> V_97 = V_50 ;
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
V_128:
F_31 ( & V_2 -> V_61 ) ;
return 0 ;
V_45:
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
F_31 ( & V_2 -> V_61 ) ;
return V_13 ;
}
static int F_66 ( struct V_11 * V_102 )
{
struct V_1 * V_2 = F_49 ( V_102 ) ;
int V_13 ;
F_30 ( & V_2 -> V_61 ) ;
V_13 = V_2 -> V_97 ;
F_31 ( & V_2 -> V_61 ) ;
return V_13 ;
}
static int F_67 ( struct V_11 * V_102 ,
void * V_14 , T_4 V_129 ,
T_2 V_31 , T_2 V_32 , T_2 V_33 , T_2 V_34 )
{
struct V_1 * V_2 = F_49 ( V_102 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
int V_13 ;
int V_130 = 1 ;
int V_131 ;
unsigned V_132 = 0 ;
if ( V_129 < V_33 * V_34 * 3 )
return - V_133 ;
F_30 ( & V_2 -> V_61 ) ;
if ( ! V_2 -> V_62 ) {
V_13 = - V_72 ;
goto V_51;
}
V_129 = F_68 ( ( V_134 ) V_33 * V_34 * 3 ,
V_102 -> V_122 . V_83 . V_123 * V_102 -> V_122 . V_83 . V_124 * 3 ) ;
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
V_13 = F_26 ( V_2 ) ;
if ( V_13 )
goto V_53;
if ( V_129 % 2 )
V_131 = 1 ;
else
V_131 = 2 ;
F_12 ( V_2 , V_31 , V_32 , V_33 , V_34 ) ;
V_13 = V_12 -> V_15 . V_16 -> V_135 ( V_12 , V_2 -> V_18 , V_131 ) ;
if ( V_13 )
goto V_53;
while ( V_132 < V_129 ) {
T_1 V_9 = V_130 ? 0x2e : 0x3e ;
V_130 = 0 ;
V_13 = V_12 -> V_15 . V_16 -> V_17 ( V_12 , V_2 -> V_18 , V_9 ,
V_14 + V_132 , V_129 - V_132 ) ;
if ( V_13 < 0 ) {
F_22 ( V_102 -> V_49 , L_27 ) ;
goto V_136;
}
V_132 += V_13 ;
if ( V_13 < V_131 ) {
F_22 ( & V_2 -> V_48 -> V_49 , L_28 ) ;
break;
}
if ( F_69 ( V_137 ) ) {
F_22 ( & V_2 -> V_48 -> V_49 , L_29
L_30 ) ;
V_13 = - V_138 ;
goto V_136;
}
}
V_13 = V_132 ;
V_136:
V_12 -> V_15 . V_16 -> V_135 ( V_12 , V_2 -> V_18 , 1 ) ;
V_53:
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
V_51:
F_31 ( & V_2 -> V_61 ) ;
return V_13 ;
}
static void F_70 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_59 ( V_121 , struct V_1 ,
V_43 . V_121 ) ;
struct V_11 * V_102 = & V_2 -> V_102 ;
struct V_11 * V_12 = V_2 -> V_12 ;
F_30 ( & V_2 -> V_61 ) ;
if ( V_102 -> V_111 != V_112 || ! V_2 -> V_62 ) {
F_31 ( & V_2 -> V_61 ) ;
return;
}
V_12 -> V_15 . V_16 -> V_63 ( V_12 ) ;
F_17 ( V_2 ) ;
V_12 -> V_15 . V_16 -> V_65 ( V_12 ) ;
F_31 ( & V_2 -> V_61 ) ;
}
static int F_71 ( struct V_69 * V_48 )
{
struct V_139 * V_140 = V_48 -> V_49 . V_141 ;
struct V_1 * V_2 = F_35 ( V_48 ) ;
struct V_11 * V_12 ;
int V_142 ;
V_142 = F_72 ( V_140 , L_31 , 0 ) ;
if ( ! F_19 ( V_142 ) ) {
F_22 ( & V_48 -> V_49 , L_32 ) ;
return V_142 ;
}
V_2 -> V_76 = V_142 ;
V_142 = F_72 ( V_140 , L_33 , 0 ) ;
if ( F_19 ( V_142 ) || V_142 == - V_143 ) {
V_2 -> V_46 = V_142 ;
} else {
F_22 ( & V_48 -> V_49 , L_34 ) ;
return V_142 ;
}
V_12 = F_73 ( V_140 ) ;
if ( F_74 ( V_12 ) ) {
F_22 ( & V_48 -> V_49 , L_35 ) ;
return F_75 ( V_12 ) ;
}
V_2 -> V_12 = V_12 ;
return 0 ;
}
static int F_76 ( struct V_69 * V_48 )
{
struct V_144 V_56 ;
struct V_1 * V_2 ;
struct V_54 * V_145 = NULL ;
struct V_66 * V_49 = & V_48 -> V_49 ;
struct V_11 * V_102 ;
int V_13 ;
F_29 ( V_49 , L_36 ) ;
V_2 = F_77 ( V_49 , sizeof( * V_2 ) , V_146 ) ;
if ( ! V_2 )
return - V_133 ;
F_78 ( V_48 , V_2 ) ;
V_2 -> V_48 = V_48 ;
if ( ! V_48 -> V_49 . V_141 )
return - V_72 ;
V_13 = F_71 ( V_48 ) ;
if ( V_13 )
return V_13 ;
V_2 -> V_83 . V_123 = 864 ;
V_2 -> V_83 . V_124 = 480 ;
V_2 -> V_83 . V_147 = 864 * 480 * 60 ;
V_102 = & V_2 -> V_102 ;
V_102 -> V_49 = V_49 ;
V_102 -> V_148 = & V_149 ;
V_102 -> V_122 . V_83 = V_2 -> V_83 ;
V_102 -> type = V_150 ;
V_102 -> V_151 = V_152 ;
V_102 -> V_122 . V_153 = V_82 ;
V_102 -> V_154 = V_155 |
V_156 ;
V_13 = F_79 ( V_102 ) ;
if ( V_13 ) {
F_22 ( V_49 , L_37 ) ;
goto V_157;
}
F_80 ( & V_2 -> V_61 ) ;
F_60 ( & V_2 -> V_116 , 0 ) ;
if ( F_19 ( V_2 -> V_76 ) ) {
V_13 = F_81 ( V_49 , V_2 -> V_76 ,
V_158 , L_38 ) ;
if ( V_13 ) {
F_22 ( V_49 , L_39 ) ;
return V_13 ;
}
}
if ( F_19 ( V_2 -> V_46 ) ) {
V_13 = F_81 ( V_49 , V_2 -> V_46 ,
V_159 , L_40 ) ;
if ( V_13 ) {
F_22 ( V_49 , L_41 ) ;
return V_13 ;
}
V_13 = F_82 ( V_49 , F_21 ( V_2 -> V_46 ) ,
F_56 ,
V_160 ,
L_42 , V_2 ) ;
if ( V_13 ) {
F_22 ( V_49 , L_43 ) ;
return V_13 ;
}
F_83 ( & V_2 -> V_117 ,
F_58 ) ;
F_29 ( V_49 , L_44 ) ;
}
V_2 -> V_42 = F_84 ( L_45 ) ;
if ( V_2 -> V_42 == NULL ) {
F_22 ( V_49 , L_46 ) ;
return - V_133 ;
}
F_85 ( & V_2 -> V_43 , F_70 ) ;
F_42 ( V_2 ) ;
if ( V_2 -> V_161 ) {
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_162 = 255 ;
V_56 . type = V_163 ;
V_145 = F_86 ( F_87 ( V_49 ) ,
V_49 , V_2 , & V_164 , & V_56 ) ;
if ( F_74 ( V_145 ) ) {
V_13 = F_75 ( V_145 ) ;
goto V_165;
}
V_2 -> V_145 = V_145 ;
V_145 -> V_56 . V_57 = V_58 ;
V_145 -> V_56 . V_59 = V_58 ;
V_145 -> V_56 . V_60 = 255 ;
F_27 ( V_145 ) ;
}
V_13 = F_88 ( & V_49 -> V_166 , & V_167 ) ;
if ( V_13 ) {
F_22 ( V_49 , L_47 ) ;
goto V_168;
}
return 0 ;
V_168:
F_89 ( V_145 ) ;
V_165:
F_90 ( V_2 -> V_42 ) ;
V_157:
return V_13 ;
}
static int T_6 F_91 ( struct V_69 * V_48 )
{
struct V_1 * V_2 = F_35 ( V_48 ) ;
struct V_11 * V_102 = & V_2 -> V_102 ;
struct V_54 * V_145 ;
F_29 ( & V_48 -> V_49 , L_48 ) ;
F_92 ( V_102 ) ;
F_54 ( V_102 ) ;
F_51 ( V_102 ) ;
F_93 ( & V_48 -> V_49 . V_166 , & V_167 ) ;
V_145 = V_2 -> V_145 ;
if ( V_145 != NULL ) {
V_145 -> V_56 . V_59 = V_169 ;
F_27 ( V_145 ) ;
F_89 ( V_145 ) ;
}
F_94 ( V_2 -> V_12 ) ;
F_15 ( V_2 ) ;
F_90 ( V_2 -> V_42 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
