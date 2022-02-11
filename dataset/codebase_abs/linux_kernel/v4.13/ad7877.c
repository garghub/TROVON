static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
int V_6 , V_7 ;
V_5 = F_2 ( sizeof *V_5 , V_8 ) ;
if ( ! V_5 )
return - V_9 ;
F_3 ( & V_5 -> V_10 ) ;
V_5 -> V_11 = ( T_1 ) ( F_4 ( V_12 ) |
F_5 ( V_3 ) ) ;
V_5 -> V_13 [ 0 ] . V_14 = & V_5 -> V_11 ;
V_5 -> V_13 [ 0 ] . V_15 = 2 ;
V_5 -> V_13 [ 0 ] . V_16 = 1 ;
V_5 -> V_13 [ 1 ] . V_17 = & V_5 -> V_18 ;
V_5 -> V_13 [ 1 ] . V_15 = 2 ;
F_6 ( & V_5 -> V_13 [ 0 ] , & V_5 -> V_10 ) ;
F_6 ( & V_5 -> V_13 [ 1 ] , & V_5 -> V_10 ) ;
V_6 = F_7 ( V_2 , & V_5 -> V_10 ) ;
V_7 = V_6 ? : V_5 -> V_18 ;
F_8 ( V_5 ) ;
return V_7 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_19 )
{
struct V_4 * V_5 ;
int V_6 ;
V_5 = F_2 ( sizeof *V_5 , V_8 ) ;
if ( ! V_5 )
return - V_9 ;
F_3 ( & V_5 -> V_10 ) ;
V_5 -> V_11 = ( T_1 ) ( F_4 ( V_3 ) | ( V_19 & V_20 ) ) ;
V_5 -> V_13 [ 0 ] . V_14 = & V_5 -> V_11 ;
V_5 -> V_13 [ 0 ] . V_15 = 2 ;
F_6 ( & V_5 -> V_13 [ 0 ] , & V_5 -> V_10 ) ;
V_6 = F_7 ( V_2 , & V_5 -> V_10 ) ;
F_8 ( V_5 ) ;
return V_6 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_11 )
{
struct V_21 * V_22 = F_11 ( V_2 ) ;
struct V_4 * V_5 ;
int V_6 ;
int V_18 ;
int V_23 ;
V_5 = F_2 ( sizeof *V_5 , V_8 ) ;
if ( ! V_5 )
return - V_9 ;
F_3 ( & V_5 -> V_10 ) ;
V_5 -> V_24 = F_4 ( V_25 ) |
F_12 ( V_22 -> V_26 ) |
F_13 ( 0 ) | F_14 ( 2 ) | F_15 ( 0 ) |
F_16 ( V_22 -> V_27 ) | F_17 ( 0 ) ;
V_5 -> V_28 = F_4 ( V_12 ) | V_29 ;
V_5 -> V_11 = ( T_1 ) V_11 ;
V_5 -> V_13 [ 0 ] . V_14 = & V_5 -> V_28 ;
V_5 -> V_13 [ 0 ] . V_15 = 2 ;
V_5 -> V_13 [ 0 ] . V_16 = 1 ;
V_5 -> V_13 [ 1 ] . V_14 = & V_5 -> V_24 ;
V_5 -> V_13 [ 1 ] . V_15 = 2 ;
V_5 -> V_13 [ 1 ] . V_30 = V_22 -> V_31 ;
V_5 -> V_13 [ 1 ] . V_16 = 1 ;
V_5 -> V_13 [ 2 ] . V_14 = & V_5 -> V_11 ;
V_5 -> V_13 [ 2 ] . V_15 = 2 ;
V_5 -> V_13 [ 2 ] . V_30 = V_22 -> V_31 ;
V_5 -> V_13 [ 2 ] . V_16 = 1 ;
V_5 -> V_13 [ 3 ] . V_17 = & V_5 -> V_18 ;
V_5 -> V_13 [ 3 ] . V_15 = 2 ;
V_5 -> V_13 [ 3 ] . V_16 = 1 ;
V_5 -> V_13 [ 4 ] . V_14 = & V_22 -> V_32 ;
V_5 -> V_13 [ 4 ] . V_15 = 2 ;
V_5 -> V_13 [ 4 ] . V_16 = 1 ;
V_5 -> V_13 [ 5 ] . V_14 = & V_22 -> V_33 ;
V_5 -> V_13 [ 5 ] . V_15 = 2 ;
for ( V_23 = 0 ; V_23 < 6 ; V_23 ++ )
F_6 ( & V_5 -> V_13 [ V_23 ] , & V_5 -> V_10 ) ;
V_6 = F_7 ( V_2 , & V_5 -> V_10 ) ;
V_18 = V_5 -> V_18 ;
F_8 ( V_5 ) ;
return V_6 ? : V_18 ;
}
static int F_18 ( struct V_21 * V_22 )
{
struct V_34 * V_34 = V_22 -> V_35 ;
unsigned V_36 ;
T_1 V_37 , V_38 , V_39 , V_40 ;
V_37 = V_22 -> V_41 [ V_42 ] & V_20 ;
V_38 = V_22 -> V_41 [ V_43 ] & V_20 ;
V_39 = V_22 -> V_41 [ V_44 ] & V_20 ;
V_40 = V_22 -> V_41 [ V_45 ] & V_20 ;
if ( F_19 ( V_37 && V_39 ) ) {
V_36 = ( V_40 - V_39 ) * V_37 * V_22 -> V_46 ;
V_36 /= V_39 ;
V_36 = ( V_36 + 2047 ) >> 12 ;
if ( V_36 > V_22 -> V_47 )
return - V_48 ;
if ( ! F_20 ( & V_22 -> V_49 ) )
F_21 ( V_34 , V_50 , 1 ) ;
F_22 ( V_34 , V_51 , V_37 ) ;
F_22 ( V_34 , V_52 , V_38 ) ;
F_22 ( V_34 , V_53 , V_36 ) ;
F_23 ( V_34 ) ;
return 0 ;
}
return - V_48 ;
}
static inline void F_24 ( struct V_21 * V_22 )
{
struct V_34 * V_34 = V_22 -> V_35 ;
F_22 ( V_34 , V_53 , 0 ) ;
F_21 ( V_34 , V_50 , 0 ) ;
F_23 ( V_34 ) ;
}
static void F_25 ( unsigned long V_54 )
{
struct V_21 * V_22 = ( void * ) V_54 ;
unsigned long V_55 ;
F_26 ( & V_22 -> V_56 , V_55 ) ;
F_24 ( V_22 ) ;
F_27 ( & V_22 -> V_56 , V_55 ) ;
}
static T_2 F_28 ( int V_57 , void * V_54 )
{
struct V_21 * V_22 = V_54 ;
unsigned long V_55 ;
int error ;
error = F_7 ( V_22 -> V_2 , & V_22 -> V_10 ) ;
if ( error ) {
F_29 ( & V_22 -> V_2 -> V_58 , L_1 , error ) ;
goto V_59;
}
F_26 ( & V_22 -> V_56 , V_55 ) ;
error = F_18 ( V_22 ) ;
if ( ! error )
F_30 ( & V_22 -> V_49 , V_60 + V_61 ) ;
F_27 ( & V_22 -> V_56 , V_55 ) ;
V_59:
return V_62 ;
}
static void F_31 ( struct V_21 * V_22 )
{
F_32 ( & V_22 -> V_63 ) ;
if ( ! V_22 -> V_64 ) {
V_22 -> V_64 = true ;
F_33 ( V_22 -> V_2 -> V_57 ) ;
if ( F_34 ( & V_22 -> V_49 ) )
F_24 ( V_22 ) ;
}
F_35 ( & V_22 -> V_63 ) ;
}
static void F_36 ( struct V_21 * V_22 )
{
F_32 ( & V_22 -> V_63 ) ;
if ( V_22 -> V_64 ) {
V_22 -> V_64 = false ;
F_37 ( V_22 -> V_2 -> V_57 ) ;
}
F_35 ( & V_22 -> V_63 ) ;
}
static T_3 F_38 ( struct V_65 * V_58 ,
struct V_66 * V_67 , char * V_68 )
{
struct V_21 * V_22 = F_39 ( V_58 ) ;
return sprintf ( V_68 , L_2 , V_22 -> V_64 ) ;
}
static T_3 F_40 ( struct V_65 * V_58 ,
struct V_66 * V_67 ,
const char * V_68 , T_4 V_69 )
{
struct V_21 * V_22 = F_39 ( V_58 ) ;
unsigned int V_19 ;
int error ;
error = F_41 ( V_68 , 10 , & V_19 ) ;
if ( error )
return error ;
if ( V_19 )
F_31 ( V_22 ) ;
else
F_36 ( V_22 ) ;
return V_69 ;
}
static T_3 F_42 ( struct V_65 * V_58 ,
struct V_66 * V_67 , char * V_68 )
{
struct V_21 * V_22 = F_39 ( V_58 ) ;
return sprintf ( V_68 , L_2 , V_22 -> V_70 ) ;
}
static T_3 F_43 ( struct V_65 * V_58 ,
struct V_66 * V_67 ,
const char * V_68 , T_4 V_69 )
{
struct V_21 * V_22 = F_39 ( V_58 ) ;
unsigned int V_19 ;
int error ;
error = F_41 ( V_68 , 10 , & V_19 ) ;
if ( error )
return error ;
F_32 ( & V_22 -> V_63 ) ;
V_22 -> V_70 = V_19 & 0xFF ;
F_9 ( V_22 -> V_2 , V_71 , ( V_22 -> V_70 << 4 ) | V_72 ) ;
F_35 ( & V_22 -> V_63 ) ;
return V_69 ;
}
static T_3 F_44 ( struct V_65 * V_58 ,
struct V_66 * V_67 , char * V_68 )
{
struct V_21 * V_22 = F_39 ( V_58 ) ;
return sprintf ( V_68 , L_2 , V_22 -> V_73 ) ;
}
static T_3 F_45 ( struct V_65 * V_58 ,
struct V_66 * V_67 ,
const char * V_68 , T_4 V_69 )
{
struct V_21 * V_22 = F_39 ( V_58 ) ;
unsigned int V_19 ;
int error ;
error = F_41 ( V_68 , 10 , & V_19 ) ;
if ( error )
return error ;
F_32 ( & V_22 -> V_63 ) ;
V_22 -> V_73 = ! ! V_19 ;
F_9 ( V_22 -> V_2 , V_74 , V_75 |
( V_22 -> V_76 << 4 ) | ( V_22 -> V_73 << 5 ) ) ;
F_35 ( & V_22 -> V_63 ) ;
return V_69 ;
}
static T_3 F_46 ( struct V_65 * V_58 ,
struct V_66 * V_67 , char * V_68 )
{
struct V_21 * V_22 = F_39 ( V_58 ) ;
return sprintf ( V_68 , L_2 , V_22 -> V_76 ) ;
}
static T_3 F_47 ( struct V_65 * V_58 ,
struct V_66 * V_67 ,
const char * V_68 , T_4 V_69 )
{
struct V_21 * V_22 = F_39 ( V_58 ) ;
unsigned int V_19 ;
int error ;
error = F_41 ( V_68 , 10 , & V_19 ) ;
if ( error )
return error ;
F_32 ( & V_22 -> V_63 ) ;
V_22 -> V_76 = ! ! V_19 ;
F_9 ( V_22 -> V_2 , V_74 , V_75 |
( V_22 -> V_76 << 4 ) | ( V_22 -> V_73 << 5 ) ) ;
F_35 ( & V_22 -> V_63 ) ;
return V_69 ;
}
static T_5 F_48 ( struct V_77 * V_78 ,
struct V_79 * V_67 , int V_80 )
{
T_5 V_81 = V_67 -> V_81 ;
if ( V_67 == & V_82 . V_67 ) {
if ( V_73 )
V_81 = 0 ;
} else if ( V_67 == & V_83 . V_67 ) {
if ( ! V_73 )
V_81 = 0 ;
}
return V_81 ;
}
static void F_49 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_84 * V_85 ;
int V_23 ;
V_22 -> V_32 = F_4 ( V_25 ) |
F_12 ( V_22 -> V_26 ) |
F_13 ( V_22 -> V_86 ) | F_14 ( 1 ) |
F_15 ( V_22 -> V_87 ) |
F_16 ( V_22 -> V_27 ) |
F_17 ( V_22 -> V_88 ) ;
F_9 ( V_2 , V_25 , V_22 -> V_32 ) ;
V_22 -> V_33 = F_4 ( V_12 ) |
F_5 ( V_89 - 1 ) |
V_90 | V_91 ;
F_9 ( V_2 , V_12 , V_22 -> V_33 ) ;
V_22 -> V_92 = 0 ;
V_85 = & V_22 -> V_10 ;
F_3 ( V_85 ) ;
V_85 -> V_93 = V_22 ;
V_22 -> V_13 [ 0 ] . V_14 = & V_22 -> V_33 ;
V_22 -> V_13 [ 0 ] . V_15 = 2 ;
V_22 -> V_13 [ 0 ] . V_16 = 1 ;
F_6 ( & V_22 -> V_13 [ 0 ] , V_85 ) ;
V_22 -> V_13 [ 1 ] . V_14 = & V_22 -> V_92 ;
V_22 -> V_13 [ 1 ] . V_15 = 2 ;
V_22 -> V_13 [ 1 ] . V_16 = 1 ;
F_6 ( & V_22 -> V_13 [ 1 ] , V_85 ) ;
for ( V_23 = 0 ; V_23 < V_94 ; V_23 ++ ) {
V_22 -> V_13 [ V_23 + 2 ] . V_17 = & V_22 -> V_41 [ V_43 + V_23 ] ;
V_22 -> V_13 [ V_23 + 2 ] . V_15 = 2 ;
if ( V_23 < ( V_94 - 1 ) )
V_22 -> V_13 [ V_23 + 2 ] . V_16 = 1 ;
F_6 ( & V_22 -> V_13 [ V_23 + 2 ] , V_85 ) ;
}
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
struct V_34 * V_34 ;
struct V_95 * V_96 = F_51 ( & V_2 -> V_58 ) ;
int V_97 ;
T_1 V_98 ;
if ( ! V_2 -> V_57 ) {
F_52 ( & V_2 -> V_58 , L_3 ) ;
return - V_99 ;
}
if ( ! V_96 ) {
F_52 ( & V_2 -> V_58 , L_4 ) ;
return - V_99 ;
}
if ( V_2 -> V_100 > V_101 ) {
F_52 ( & V_2 -> V_58 , L_5 , V_2 -> V_100 ) ;
return - V_48 ;
}
V_2 -> V_102 = 16 ;
V_97 = F_53 ( V_2 ) ;
if ( V_97 ) {
F_52 ( & V_2 -> V_58 , L_6 ) ;
return V_97 ;
}
V_22 = F_2 ( sizeof( struct V_21 ) , V_8 ) ;
V_34 = F_54 () ;
if ( ! V_22 || ! V_34 ) {
V_97 = - V_9 ;
goto V_103;
}
F_55 ( V_2 , V_22 ) ;
V_22 -> V_2 = V_2 ;
V_22 -> V_35 = V_34 ;
F_56 ( & V_22 -> V_49 , F_25 , ( unsigned long ) V_22 ) ;
F_57 ( & V_22 -> V_63 ) ;
F_58 ( & V_22 -> V_56 ) ;
V_22 -> V_104 = V_96 -> V_104 ? : 7877 ;
V_22 -> V_31 = V_96 -> V_31 ? : 100 ;
V_22 -> V_46 = V_96 -> V_46 ? : 400 ;
V_22 -> V_47 = V_96 -> V_47 ? : ~ 0 ;
V_22 -> V_26 = V_96 -> V_26 ;
V_22 -> V_88 = V_96 -> V_88 ;
V_22 -> V_27 = V_96 -> V_27 ;
V_22 -> V_86 = V_96 -> V_86 ;
V_22 -> V_87 = V_96 -> V_87 ;
snprintf ( V_22 -> V_105 , sizeof( V_22 -> V_105 ) , L_7 , F_59 ( & V_2 -> V_58 ) ) ;
V_34 -> V_106 = L_8 ;
V_34 -> V_105 = V_22 -> V_105 ;
V_34 -> V_58 . V_107 = & V_2 -> V_58 ;
F_60 ( V_108 , V_34 -> V_109 ) ;
F_60 ( V_50 , V_34 -> V_110 ) ;
F_60 ( V_111 , V_34 -> V_109 ) ;
F_60 ( V_51 , V_34 -> V_112 ) ;
F_60 ( V_52 , V_34 -> V_112 ) ;
F_60 ( V_53 , V_34 -> V_112 ) ;
F_61 ( V_34 , V_51 ,
V_96 -> V_113 ? : 0 ,
V_96 -> V_114 ? : V_20 ,
0 , 0 ) ;
F_61 ( V_34 , V_52 ,
V_96 -> V_115 ? : 0 ,
V_96 -> V_116 ? : V_20 ,
0 , 0 ) ;
F_61 ( V_34 , V_53 ,
V_96 -> V_117 , V_96 -> V_47 , 0 , 0 ) ;
F_9 ( V_2 , V_118 , V_119 ) ;
V_98 = F_1 ( V_2 , V_118 ) ;
if ( V_98 != V_119 ) {
F_29 ( & V_2 -> V_58 , L_9 ,
F_59 ( & V_2 -> V_58 ) , V_34 -> V_106 ) ;
V_97 = - V_99 ;
goto V_103;
}
if ( V_73 )
F_9 ( V_2 , V_74 , V_120 ) ;
F_49 ( V_2 , V_22 ) ;
V_97 = F_62 ( V_2 -> V_57 , NULL , F_28 ,
V_121 | V_122 ,
V_2 -> V_58 . V_123 -> V_106 , V_22 ) ;
if ( V_97 ) {
F_52 ( & V_2 -> V_58 , L_10 , V_2 -> V_57 ) ;
goto V_103;
}
V_97 = F_63 ( & V_2 -> V_58 . V_78 , & V_124 ) ;
if ( V_97 )
goto V_125;
V_97 = F_64 ( V_34 ) ;
if ( V_97 )
goto V_126;
return 0 ;
V_126:
F_65 ( & V_2 -> V_58 . V_78 , & V_124 ) ;
V_125:
F_66 ( V_2 -> V_57 , V_22 ) ;
V_103:
F_67 ( V_34 ) ;
F_8 ( V_22 ) ;
return V_97 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_11 ( V_2 ) ;
F_65 ( & V_2 -> V_58 . V_78 , & V_124 ) ;
F_31 ( V_22 ) ;
F_66 ( V_22 -> V_2 -> V_57 , V_22 ) ;
F_69 ( V_22 -> V_35 ) ;
F_8 ( V_22 ) ;
F_52 ( & V_2 -> V_58 , L_11 ) ;
return 0 ;
}
static int T_6 F_70 ( struct V_65 * V_58 )
{
struct V_21 * V_22 = F_39 ( V_58 ) ;
F_31 ( V_22 ) ;
return 0 ;
}
static int T_6 F_71 ( struct V_65 * V_58 )
{
struct V_21 * V_22 = F_39 ( V_58 ) ;
F_36 ( V_22 ) ;
return 0 ;
}
