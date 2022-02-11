static inline int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
V_2 -> V_4 = V_3 ;
return F_2 ( V_2 -> V_5 ,
V_6 ,
( V_3 << 1 ) | V_2 -> V_7 ) ;
}
static inline int F_3 ( struct V_1 * V_2 ,
int V_8 )
{
V_2 -> V_7 = V_8 ;
return F_2 ( V_2 -> V_5 ,
V_6 ,
( V_2 -> V_4 << 1 ) | ( V_8 << 0 ) ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_9 )
{
if ( F_5 ( & V_2 -> V_5 -> V_10 ) )
return 0 ;
if ( V_2 -> V_11 )
V_9 = 0 ;
return F_2 ( V_2 -> V_5 ,
V_12 ,
V_9 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_13 )
{
int V_14 ;
V_14 = ( V_13 == V_15 ) ?
V_2 -> V_16 : V_2 -> V_17 ;
return F_2 ( V_2 -> V_5 ,
V_18 ,
V_14 ) ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_5 ,
V_19 ,
( V_20 << 6 ) |
( V_21 << 3 ) |
V_2 -> V_22 ) ;
}
static inline T_1 F_8 ( struct V_1 * V_2 , T_1 V_23 )
{
T_2 V_24 ;
V_24 = ( T_2 ) ( ( ( V_25 ) ( V_23 + V_2 -> V_26 ) * V_2 -> V_27 ) /
V_28 ) ;
if ( V_24 > V_29 )
V_24 = V_29 ;
return V_24 ;
}
static inline T_1 F_9 ( struct V_1 * V_2 , T_1 V_8 )
{
T_2 V_30 ;
V_30 = ( ( ( V_25 ) V_8 * V_28 ) / V_2 -> V_27 ) ;
if ( V_30 > V_2 -> V_26 )
V_30 = V_30 - V_2 -> V_26 ;
else
V_30 = 0 ;
return V_30 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_1 V_31 = 0 ;
if ( F_5 ( & V_2 -> V_5 -> V_10 ) )
return 0 ;
V_31 = F_9 ( V_2 , V_2 -> V_32 ) ;
V_2 -> V_33 = V_31 ;
return F_2 ( V_2 -> V_5 , V_34 ,
V_31 ) ;
}
static inline T_2 F_11 ( struct V_1 * V_2 , T_2 V_30 )
{
V_25 V_3 ;
V_3 = ( ( V_25 ) V_30 * V_2 -> V_35 ) / V_36 ;
return F_12 ( V_3 , ( V_25 ) V_37 ) ;
}
static inline T_2 F_13 ( struct V_1 * V_2 ,
T_2 V_24 )
{
return ( V_25 ) V_24 * V_36 / V_2 -> V_35 ;
}
static int F_14 ( struct V_1 * V_2 ,
T_2 V_38 , T_2 V_39 )
{
T_1 V_40 [ 4 ] ;
int V_41 ;
if ( F_5 ( & V_2 -> V_5 -> V_10 ) )
return 0 ;
if ( V_38 != V_37 && V_38 != 0 )
V_38 = F_13 ( V_2 , V_38 ) ;
if ( V_39 != V_37 && V_39 != 0 )
V_39 = F_13 ( V_2 , V_39 ) ;
if ( V_2 -> V_42 == V_38 &&
V_2 -> V_43 == V_39 )
return 0 ;
V_2 -> V_42 = V_38 ;
V_2 -> V_43 = V_39 ;
V_40 [ 0 ] = V_38 ;
V_40 [ 1 ] = V_38 >> 8 ;
V_40 [ 2 ] = V_39 ;
V_40 [ 3 ] = V_39 >> 8 ;
V_41 = F_15 ( V_2 -> V_5 ,
V_44 ,
F_16 ( V_40 ) ,
V_40 ) ;
return V_41 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_2 V_40 ;
int V_41 ;
V_41 = F_18 ( V_2 -> V_5 , V_45 ) ;
if ( V_41 < 0 )
return V_41 ;
V_40 = V_41 & 0xff ;
V_41 = F_18 ( V_2 -> V_5 , V_46 ) ;
if ( V_41 < 0 )
return V_41 ;
V_2 -> V_47 = V_40 | ( ( V_41 & 0xff ) << 8 ) ;
return 0 ;
}
static V_25 F_19 ( struct V_1 * V_2 )
{
V_25 V_31 ;
V_31 = ( V_36 * V_2 -> V_48 ) / V_49 ;
V_31 = ( V_31 * V_2 -> V_50 ) / V_51 ;
V_31 = ( V_31 * V_2 -> V_52 ) / V_53 ;
return V_31 ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_17 ( V_2 ) ;
return F_11 ( V_2 , V_2 -> V_47 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_41 = F_22 ( F_16 ( V_2 -> V_54 ) ,
V_2 -> V_54 ) ;
if ( V_41 < 0 )
return V_41 ;
F_23 ( V_55 , V_55 * 2 ) ;
F_2 ( V_2 -> V_5 , V_56 ,
V_57 ) ;
F_23 ( V_58 , V_58 * 2 ) ;
V_2 -> V_47 = 0 ;
V_2 -> V_59 = 0 ;
V_41 = F_2 ( V_2 -> V_5 ,
V_56 , V_60 ) ;
V_2 -> V_42 = V_37 ;
V_2 -> V_43 = 0 ;
return V_41 ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_5 ,
V_6 , V_61 ) ;
F_2 ( V_2 -> V_5 ,
V_56 , V_62 ) ;
F_2 ( V_2 -> V_5 ,
V_63 , V_62 ) ;
F_25 ( F_16 ( V_2 -> V_54 ) , V_2 -> V_54 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 ) {
V_2 -> V_64 = true ;
F_4 ( V_2 , V_2 -> V_65 ) ;
F_10 ( V_2 ) ;
F_7 ( V_2 ) ;
F_6 ( V_2 , V_66 ) ;
F_3 ( V_2 , V_67 ) ;
F_2 ( V_2 -> V_5 ,
V_63 , V_60 ) ;
} else {
V_2 -> V_59 = 0 ;
F_4 ( V_2 , V_2 -> V_65 ) ;
F_3 ( V_2 , V_61 ) ;
F_2 ( V_2 -> V_5 ,
V_63 , V_62 ) ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_41 ;
bool V_68 ;
T_1 V_13 ;
V_41 = F_18 ( V_2 -> V_5 , V_69 ) ;
if ( V_41 < 0 )
goto V_70;
if ( V_41 > V_2 -> V_33 )
V_68 = true ;
else
V_68 = false ;
if ( V_2 -> V_47 > V_71 )
V_41 = 0 ;
V_2 -> V_59 = F_8 ( V_2 , V_41 ) ;
if ( V_2 -> V_59 >= V_2 -> V_72 ||
V_2 -> V_64 )
V_2 -> V_73 = V_2 -> V_74 ;
V_2 -> V_64 = false ;
if ( F_28 ( V_68 ) ) {
if ( V_2 -> V_73 < V_2 -> V_74 ) {
V_2 -> V_73 ++ ;
V_41 = - V_75 ;
} else {
V_13 = V_15 ;
V_41 = 0 ;
}
} else {
V_2 -> V_73 = 0 ;
V_13 = V_66 ;
V_2 -> V_59 = 0 ;
V_41 = 0 ;
}
if ( V_41 == 0 ) {
F_6 ( V_2 , V_13 ) ;
F_29 ( & V_2 -> V_5 -> V_10 . V_76 , NULL , L_1 ) ;
}
V_70:
return V_41 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_77 * V_5 = V_2 -> V_5 ;
T_3 V_41 ;
T_1 V_78 , V_79 ;
V_41 = F_18 ( V_5 , V_80 ) ;
if ( V_41 < 0 )
goto error;
V_78 = ( T_1 ) V_41 ;
V_41 = F_18 ( V_5 , V_81 ) ;
if ( V_41 < 0 )
goto error;
V_79 = ( T_1 ) V_41 ;
V_2 -> V_82 = ( V_79 & V_83 ) >> V_84 ;
V_2 -> V_27 = V_28 ;
V_2 -> V_26 = 0 ;
V_2 -> V_50 = V_85 ;
if ( ( V_78 == V_86 ) &&
( ( V_79 & V_87 ) == V_88 ) ) {
snprintf ( V_2 -> V_89 , sizeof( V_2 -> V_89 ) , L_2 ) ;
return 0 ;
}
if ( ( V_78 == V_90 ) &&
( ( V_79 & V_87 ) == V_88 ) ) {
snprintf ( V_2 -> V_89 , sizeof( V_2 -> V_89 ) , L_3 ) ;
V_2 -> V_27 = 819 ;
V_2 -> V_26 = 40 ;
return 0 ;
}
V_41 = - V_91 ;
error:
F_31 ( & V_5 -> V_10 , L_4 ) ;
return V_41 ;
}
static void F_32 ( struct V_92 * V_93 )
{
struct V_1 * V_2 =
F_33 ( V_93 , struct V_1 , V_94 . V_93 ) ;
F_34 ( & V_2 -> V_95 ) ;
F_27 ( V_2 ) ;
F_35 ( & V_2 -> V_95 ) ;
}
static T_4 F_36 ( int V_96 , void * V_40 )
{
struct V_1 * V_2 = V_40 ;
int V_97 ;
int V_14 = 0 ;
F_34 ( & V_2 -> V_95 ) ;
V_97 = F_18 ( V_2 -> V_5 , V_98 ) ;
F_18 ( V_2 -> V_5 , V_6 ) ;
if ( V_97 & V_99 ) {
F_17 ( V_2 ) ;
if ( F_37 ( V_2 -> V_100 ) ) {
V_2 -> V_100 = false ;
F_38 ( & V_2 -> V_101 ) ;
F_14 ( V_2 ,
V_2 -> V_102 ,
V_2 -> V_103 ) ;
}
}
F_2 ( V_2 -> V_5 , V_6 ,
( 0 << 1 ) | ( 0 << 0 ) ) ;
if ( ( V_97 & V_104 ) )
F_29 ( & V_2 -> V_5 -> V_10 . V_76 , NULL , L_5 ) ;
if ( V_2 -> V_7 && ( V_97 & V_105 ) ) {
V_14 = V_106 [ V_2 -> V_16 ] ;
F_27 ( V_2 ) ;
}
F_2 ( V_2 -> V_5 , V_6 ,
( V_2 -> V_4 << 1 ) |
( V_2 -> V_7 << 0 ) ) ;
F_35 ( & V_2 -> V_95 ) ;
if ( V_14 ) {
F_39 ( & V_2 -> V_94 ) ;
F_40 ( & V_2 -> V_94 ,
F_41 ( V_14 + 50 ) ) ;
}
return V_107 ;
}
static T_5 F_42 ( struct V_108 * V_10 ,
struct V_109 * V_110 ,
const char * V_111 , T_6 V_112 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
unsigned long V_113 ;
T_5 V_41 ;
if ( F_44 ( V_111 , 0 , & V_113 ) )
return - V_114 ;
F_34 ( & V_2 -> V_95 ) ;
if ( V_113 ) {
F_45 ( V_10 ) ;
V_41 = F_4 ( V_2 , V_2 -> V_65 ) ;
if ( V_41 < 0 ) {
F_46 ( V_10 ) ;
goto V_115;
}
V_41 = F_1 ( V_2 , V_67 ) ;
if ( V_41 < 0 ) {
F_46 ( V_10 ) ;
goto V_115;
}
F_14 ( V_2 , V_116 ,
V_116 ) ;
V_2 -> V_100 = true ;
F_26 ( V_2 ) ;
} else if ( ! F_5 ( V_10 ) ) {
F_46 ( V_10 ) ;
}
V_41 = V_112 ;
V_115:
F_35 ( & V_2 -> V_95 ) ;
return V_41 ;
}
static T_5 F_47 ( struct V_108 * V_10 ,
struct V_109 * V_110 , char * V_111 )
{
return sprintf ( V_111 , L_6 , ! F_5 ( V_10 ) ) ;
}
static T_5 F_48 ( struct V_108 * V_10 ,
struct V_109 * V_110 , char * V_111 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
T_5 V_41 ;
long V_117 ;
if ( F_5 ( V_10 ) )
return - V_118 ;
V_117 = F_49 ( V_2 -> V_101 ,
! V_2 -> V_100 ,
F_41 ( V_119 ) ) ;
if ( ! V_117 )
return - V_118 ;
F_34 ( & V_2 -> V_95 ) ;
V_41 = sprintf ( V_111 , L_6 , F_20 ( V_2 ) ) ;
F_35 ( & V_2 -> V_95 ) ;
return V_41 ;
}
static T_5 F_50 ( struct V_108 * V_10 ,
struct V_109 * V_110 , char * V_111 )
{
return sprintf ( V_111 , L_6 , V_37 ) ;
}
static T_5 F_51 ( struct V_108 * V_10 ,
struct V_109 * V_110 ,
const char * V_111 , T_6 V_112 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
unsigned long V_113 ;
if ( F_44 ( V_111 , 0 , & V_113 ) )
return - V_114 ;
F_34 ( & V_2 -> V_95 ) ;
if ( ! V_2 -> V_11 )
V_2 -> V_59 = 0 ;
if ( V_113 )
V_2 -> V_11 ++ ;
else if ( V_2 -> V_11 > 0 )
V_2 -> V_11 -- ;
else
goto V_115;
if ( ! F_5 ( V_10 ) )
F_26 ( V_2 ) ;
V_115:
F_35 ( & V_2 -> V_95 ) ;
return V_112 ;
}
static T_5 F_52 ( struct V_108 * V_10 ,
struct V_109 * V_110 , char * V_111 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
T_5 V_120 ;
F_34 ( & V_2 -> V_95 ) ;
V_120 = sprintf ( V_111 , L_6 , V_2 -> V_11 ) ;
F_35 ( & V_2 -> V_95 ) ;
return V_120 ;
}
static T_5 F_53 ( struct V_108 * V_10 ,
struct V_109 * V_110 , char * V_111 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
T_5 V_41 ;
F_34 ( & V_2 -> V_95 ) ;
if ( V_2 -> V_11 && ! F_5 ( V_10 ) )
V_41 = sprintf ( V_111 , L_6 , V_2 -> V_59 ) ;
else
V_41 = - V_118 ;
F_35 ( & V_2 -> V_95 ) ;
return V_41 ;
}
static T_5 F_54 ( struct V_108 * V_10 ,
struct V_109 * V_110 , char * V_111 )
{
return sprintf ( V_111 , L_6 , V_29 ) ;
}
static T_5 F_55 ( struct V_108 * V_10 ,
struct V_109 * V_110 , char * V_111 )
{
int V_121 ;
int V_122 = 0 ;
for ( V_121 = 0 ; V_121 < F_16 ( V_123 ) ; V_121 ++ )
V_122 += sprintf ( V_111 + V_122 , L_7 , V_123 [ V_121 ] ) ;
sprintf ( V_111 + V_122 - 1 , L_8 ) ;
return V_122 ;
}
static T_5 F_56 ( struct V_108 * V_10 ,
struct V_109 * V_110 , char * V_111 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
return sprintf ( V_111 , L_6 , V_123 [ V_2 -> V_16 ] ) ;
}
static T_5 F_57 ( struct V_108 * V_10 ,
struct V_109 * V_110 , char * V_111 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
return sprintf ( V_111 , L_6 , V_123 [ V_2 -> V_17 ] ) ;
}
static int F_58 ( int V_14 )
{
int V_121 ;
for ( V_121 = 0 ; V_121 < F_16 ( V_123 ) - 1 ; V_121 ++ )
if ( V_14 >= V_123 [ V_121 ] )
break;
return V_121 ;
}
static T_5 F_59 ( struct V_108 * V_10 ,
struct V_109 * V_110 ,
const char * V_111 , T_6 V_112 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
unsigned long V_113 ;
if ( F_44 ( V_111 , 0 , & V_113 ) )
return - V_114 ;
F_34 ( & V_2 -> V_95 ) ;
V_2 -> V_16 = F_58 ( V_113 ) ;
F_35 ( & V_2 -> V_95 ) ;
return V_112 ;
}
static T_5 F_60 ( struct V_108 * V_10 ,
struct V_109 * V_110 ,
const char * V_111 , T_6 V_112 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
unsigned long V_113 ;
if ( F_44 ( V_111 , 0 , & V_113 ) )
return - V_114 ;
F_34 ( & V_2 -> V_95 ) ;
V_2 -> V_17 = F_58 ( V_113 ) ;
F_35 ( & V_2 -> V_95 ) ;
return V_112 ;
}
static T_5 F_61 ( struct V_108 * V_10 ,
struct V_109 * V_110 , char * V_111 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
return sprintf ( V_111 , L_6 , V_2 -> V_32 ) ;
}
static T_5 F_62 ( struct V_108 * V_10 ,
struct V_109 * V_110 ,
const char * V_111 , T_6 V_112 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
unsigned long V_113 ;
int V_41 ;
if ( F_44 ( V_111 , 0 , & V_113 ) )
return - V_114 ;
if ( V_113 > V_29 )
return - V_114 ;
F_34 ( & V_2 -> V_95 ) ;
V_2 -> V_32 = V_113 ;
V_41 = F_10 ( V_2 ) ;
F_35 ( & V_2 -> V_95 ) ;
if ( V_41 < 0 )
return V_41 ;
return V_112 ;
}
static T_5 F_63 ( struct V_108 * V_10 ,
struct V_109 * V_110 , char * V_111 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
return sprintf ( V_111 , L_9 , V_2 -> V_74 ) ;
}
static T_5 F_64 ( struct V_108 * V_10 ,
struct V_109 * V_110 ,
const char * V_111 , T_6 V_120 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
unsigned long V_113 ;
if ( F_44 ( V_111 , 0 , & V_113 ) )
return - V_114 ;
if ( V_113 > V_124 )
return - V_114 ;
V_2 -> V_74 = V_113 ;
return V_120 ;
}
static T_5 F_65 ( struct V_108 * V_10 ,
struct V_109 * V_110 , char * V_111 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
return sprintf ( V_111 , L_9 , V_2 -> V_72 ) ;
}
static T_5 F_66 ( struct V_108 * V_10 ,
struct V_109 * V_110 ,
const char * V_111 , T_6 V_120 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
unsigned long V_113 ;
if ( F_44 ( V_111 , 0 , & V_113 ) )
return - V_114 ;
if ( V_113 > V_29 )
return - V_114 ;
V_2 -> V_72 = V_113 ;
return V_120 ;
}
static T_5 F_67 ( struct V_108 * V_10 ,
struct V_109 * V_110 , char * V_111 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
return sprintf ( V_111 , L_10 , V_2 -> V_89 , V_2 -> V_82 ) ;
}
static T_5 F_68 ( struct V_108 * V_10 ,
struct V_109 * V_110 , char * V_111 )
{
return sprintf ( V_111 , L_9 , V_53 ) ;
}
static T_5 F_69 ( struct V_108 * V_10 ,
struct V_109 * V_110 , char * V_111 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
T_5 V_120 ;
F_34 ( & V_2 -> V_95 ) ;
V_120 = sprintf ( V_111 , L_9 , V_2 -> V_52 ) ;
F_35 ( & V_2 -> V_95 ) ;
return V_120 ;
}
static T_5 F_70 ( struct V_108 * V_10 ,
struct V_109 * V_110 ,
const char * V_111 , T_6 V_120 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
unsigned long V_113 ;
V_25 V_125 ;
V_25 V_126 ;
if ( F_44 ( V_111 , 0 , & V_113 ) )
return - V_114 ;
F_34 ( & V_2 -> V_95 ) ;
V_125 = V_2 -> V_52 ;
V_2 -> V_52 = V_113 ;
V_126 = F_19 ( V_2 ) ;
if ( V_126 == 0 ) {
V_2 -> V_52 = V_125 ;
F_35 ( & V_2 -> V_95 ) ;
return - V_114 ;
}
V_2 -> V_35 = V_126 ;
F_14 ( V_2 , V_2 -> V_102 ,
V_2 -> V_103 ) ;
F_35 ( & V_2 -> V_95 ) ;
return V_120 ;
}
static T_5 F_71 ( struct V_108 * V_10 ,
struct V_109 * V_110 , char * V_111 )
{
int V_121 ;
int V_122 = 0 ;
for ( V_121 = 0 ; V_121 < F_16 ( V_127 ) ; V_121 ++ )
V_122 += sprintf ( V_111 + V_122 , L_7 , V_127 [ V_121 ] ) ;
sprintf ( V_111 + V_122 - 1 , L_8 ) ;
return V_122 ;
}
static T_5 F_72 ( struct V_108 * V_10 ,
struct V_109 * V_110 , char * V_111 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
return sprintf ( V_111 , L_6 , V_127 [ V_2 -> V_65 ] ) ;
}
static T_5 F_73 ( struct V_108 * V_10 ,
struct V_109 * V_110 ,
const char * V_111 , T_6 V_112 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
unsigned long V_128 ;
int V_41 , V_121 ;
if ( F_44 ( V_111 , 0 , & V_128 ) )
return - V_114 ;
for ( V_121 = 0 ; V_121 < F_16 ( V_127 ) - 1 ; V_121 ++ )
if ( V_128 >= V_127 [ V_121 ] )
break;
F_34 ( & V_2 -> V_95 ) ;
V_2 -> V_65 = V_121 ;
V_41 = F_4 ( V_2 , V_121 ) ;
F_35 ( & V_2 -> V_95 ) ;
if ( V_41 < 0 )
return V_41 ;
return V_112 ;
}
static T_5 F_74 ( struct V_108 * V_10 ,
struct V_109 * V_110 , char * V_111 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
return sprintf ( V_111 , L_6 , V_2 -> V_102 ) ;
}
static T_5 F_75 ( struct V_108 * V_10 ,
struct V_109 * V_110 , char * V_111 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
return sprintf ( V_111 , L_6 , V_2 -> V_103 ) ;
}
static T_5 F_76 ( struct V_1 * V_2 , T_2 * V_129 ,
const char * V_111 )
{
int V_41 = 0 ;
unsigned long V_130 ;
if ( F_44 ( V_111 , 0 , & V_130 ) )
return - V_114 ;
if ( V_130 > V_37 )
return - V_114 ;
F_34 ( & V_2 -> V_95 ) ;
* V_129 = V_130 ;
if ( ! V_2 -> V_100 )
V_41 = F_14 ( V_2 ,
V_2 -> V_102 ,
V_2 -> V_103 ) ;
F_35 ( & V_2 -> V_95 ) ;
return V_41 ;
}
static T_5 F_77 ( struct V_108 * V_10 ,
struct V_109 * V_110 ,
const char * V_111 , T_6 V_120 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
int V_41 = F_76 ( V_2 , & V_2 -> V_102 , V_111 ) ;
if ( V_41 < 0 )
return V_41 ;
return V_120 ;
}
static T_5 F_78 ( struct V_108 * V_10 ,
struct V_109 * V_110 ,
const char * V_111 , T_6 V_120 )
{
struct V_1 * V_2 = F_43 ( V_10 ) ;
int V_41 = F_76 ( V_2 , & V_2 -> V_103 , V_111 ) ;
if ( V_41 < 0 )
return V_41 ;
return V_120 ;
}
static int T_7 F_79 ( struct V_77 * V_5 ,
const struct V_131 * V_132 )
{
struct V_1 * V_2 ;
int V_133 ;
V_2 = F_80 ( sizeof *V_2 , V_134 ) ;
if ( ! V_2 )
return - V_135 ;
F_81 ( V_5 , V_2 ) ;
V_2 -> V_5 = V_5 ;
F_82 ( & V_2 -> V_95 ) ;
F_83 ( & V_2 -> V_101 ) ;
F_84 ( & V_2 -> V_94 , F_32 ) ;
if ( V_5 -> V_10 . V_136 == NULL ) {
F_85 ( & V_5 -> V_10 , L_11 ) ;
V_133 = - V_114 ;
goto V_137;
}
V_2 -> V_138 = V_5 -> V_10 . V_136 ;
V_2 -> V_52 = V_139 ;
V_2 -> V_65 = V_140 ;
V_2 -> V_103 = V_116 ;
V_2 -> V_102 = V_116 ;
if ( V_2 -> V_138 -> V_141 == 0 )
V_2 -> V_48 = V_142 ;
else
V_2 -> V_48 = V_2 -> V_138 -> V_141 ;
V_2 -> V_32 = V_143 ;
V_2 -> V_22 = V_2 -> V_138 -> V_144 ;
V_2 -> V_72 = V_145 ;
V_2 -> V_74 = V_146 ;
V_2 -> V_16 = V_147 ;
V_2 -> V_17 = V_148 ;
V_2 -> V_59 = 0 ;
V_2 -> V_54 [ 0 ] . V_149 = V_150 ;
V_2 -> V_54 [ 1 ] . V_149 = V_151 ;
V_133 = F_86 ( & V_5 -> V_10 ,
F_16 ( V_2 -> V_54 ) , V_2 -> V_54 ) ;
if ( V_133 < 0 ) {
F_85 ( & V_5 -> V_10 , L_12 ) ;
goto V_137;
}
V_133 = F_22 ( F_16 ( V_2 -> V_54 ) ,
V_2 -> V_54 ) ;
if ( V_133 < 0 ) {
F_85 ( & V_5 -> V_10 , L_13 ) ;
goto V_152;
}
F_23 ( V_55 , V_55 * 2 ) ;
V_133 = F_30 ( V_2 ) ;
if ( V_133 < 0 )
goto V_153;
F_21 ( V_2 ) ;
F_87 ( & V_5 -> V_10 ) ;
F_88 ( & V_5 -> V_10 ) ;
V_2 -> V_35 = F_19 ( V_2 ) ;
if ( V_2 -> V_35 == 0 ) {
F_85 ( & V_5 -> V_10 , L_14 ) ;
V_133 = - V_114 ;
goto V_153;
}
if ( V_2 -> V_138 -> V_154 ) {
V_133 = V_2 -> V_138 -> V_154 () ;
if ( V_133 ) {
V_133 = - V_114 ;
goto V_153;
}
}
V_133 = F_89 ( & V_2 -> V_5 -> V_10 . V_76 ,
& V_155 ) ;
if ( V_133 < 0 ) {
F_85 ( & V_2 -> V_5 -> V_10 , L_15 ) ;
goto V_156;
}
V_133 = F_90 ( V_5 -> V_96 , NULL ,
F_36 ,
V_157 | V_158 |
V_159 ,
L_16 , V_2 ) ;
if ( V_133 ) {
F_85 ( & V_5 -> V_10 , L_17 ,
V_5 -> V_96 ) ;
goto V_160;
}
F_25 ( F_16 ( V_2 -> V_54 ) , V_2 -> V_54 ) ;
return V_133 ;
V_160:
F_91 ( & V_2 -> V_5 -> V_10 . V_76 ,
& V_155 ) ;
V_156:
if ( V_2 -> V_138 -> V_161 )
V_2 -> V_138 -> V_161 () ;
V_153:
F_25 ( F_16 ( V_2 -> V_54 ) , V_2 -> V_54 ) ;
V_152:
F_92 ( F_16 ( V_2 -> V_54 ) , V_2 -> V_54 ) ;
V_137:
F_93 ( V_2 ) ;
return V_133 ;
}
static int T_8 F_94 ( struct V_77 * V_5 )
{
struct V_1 * V_2 = F_95 ( V_5 ) ;
F_96 ( V_5 -> V_96 , V_2 ) ;
F_91 ( & V_2 -> V_5 -> V_10 . V_76 ,
& V_155 ) ;
if ( V_2 -> V_138 -> V_161 )
V_2 -> V_138 -> V_161 () ;
F_39 ( & V_2 -> V_94 ) ;
if ( ! F_5 ( & V_5 -> V_10 ) )
F_24 ( V_2 ) ;
F_97 ( & V_5 -> V_10 ) ;
F_98 ( & V_5 -> V_10 ) ;
F_92 ( F_16 ( V_2 -> V_54 ) , V_2 -> V_54 ) ;
F_93 ( V_2 ) ;
return 0 ;
}
static int F_99 ( struct V_108 * V_10 )
{
struct V_77 * V_5 = F_33 ( V_10 , struct V_77 , V_10 ) ;
struct V_1 * V_2 = F_95 ( V_5 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_100 ( struct V_108 * V_10 )
{
struct V_77 * V_5 = F_33 ( V_10 , struct V_77 , V_10 ) ;
struct V_1 * V_2 = F_95 ( V_5 ) ;
int V_41 = 0 ;
F_21 ( V_2 ) ;
if ( ! F_5 ( V_10 ) ) {
V_41 = F_4 ( V_2 , V_2 -> V_65 ) ;
V_41 |= F_1 ( V_2 , V_67 ) ;
F_14 ( V_2 , V_116 ,
V_116 ) ;
V_2 -> V_100 = true ;
F_26 ( V_2 ) ;
}
return V_41 ;
}
static int F_101 ( struct V_108 * V_10 )
{
struct V_77 * V_5 = F_33 ( V_10 , struct V_77 , V_10 ) ;
struct V_1 * V_2 = F_95 ( V_5 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_102 ( struct V_108 * V_10 )
{
struct V_77 * V_5 = F_33 ( V_10 , struct V_77 , V_10 ) ;
struct V_1 * V_2 = F_95 ( V_5 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
