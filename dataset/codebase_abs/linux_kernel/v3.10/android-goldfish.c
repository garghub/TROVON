static inline int
F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static T_1
F_2 ( struct V_3 * V_4 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
return sprintf ( V_7 , L_1 , F_1 ( V_2 ) ? L_2 :
L_3 ) ;
}
static void
F_4 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
T_2 V_10 ;
T_2 V_11 ;
T_2 V_12 ;
V_2 -> V_9 = V_9 ;
V_11 = 0 ;
V_12 = 0 ;
switch ( F_5 ( V_9 ) ) {
case V_13 :
break;
case V_14 :
case V_15 :
V_11 = 1 ;
break;
case V_16 :
V_11 = 2 ;
break;
case V_17 :
V_11 = 3 ;
break;
default:
F_6 ( F_7 ( V_2 -> V_18 ) ,
L_4 , F_5 ( V_9 ) ) ;
break;
}
if ( F_8 ( V_9 ) == V_19 )
V_12 = V_20 ;
else if ( F_8 ( V_9 ) == V_21 )
V_12 = V_22 ;
else if ( F_8 ( V_9 ) == V_23 )
V_12 = V_24 ;
else
V_12 = V_25 ;
V_10 = V_9 -> V_26 | ( V_11 << 8 ) | ( V_12 << 12 ) ;
if ( V_2 -> V_27 == V_28 )
V_10 |= 1 << 6 ;
if ( V_9 -> V_29 & V_30 )
V_10 |= 1 << 11 ;
if ( V_2 -> V_31 && ! ( V_2 -> V_31 -> V_29 & V_32 ) )
V_10 |= 1 << 15 ;
F_9 ( V_2 , V_33 , V_9 -> V_34 ) ;
F_9 ( V_2 , V_35 , V_10 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_36 * V_31 )
{
if ( V_2 -> V_37 ) {
enum V_38 V_39 ;
if ( V_31 -> V_29 & V_32 )
V_39 = V_40 ;
else
V_39 = V_41 ;
if ( V_39 == V_41 ) {
T_3 * V_42 = ( T_3 * ) F_11 ( V_31 -> V_43 ) ;
memcpy ( V_42 , V_2 -> V_44 , V_31 -> V_43 -> V_45 ) ;
}
V_2 -> V_31 -> V_46 += V_31 -> V_43 -> V_45 ;
F_12 ( F_7 ( V_2 -> V_18 ) , V_31 -> V_43 , V_2 -> V_47 ,
V_39 ) ;
}
V_2 -> V_31 = NULL ;
V_2 -> V_47 = 0 ;
if ( ! V_31 -> V_48 ) {
V_2 -> V_49 = NULL ;
F_13 ( V_2 -> V_18 , V_31 -> V_49 ) ;
return;
}
F_4 ( V_2 , V_31 -> V_48 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_36 * V_31 )
{
if ( ! V_2 -> V_37 ) {
F_10 ( V_2 , V_31 ) ;
return;
}
if ( V_2 -> V_50 )
F_10 ( V_2 , V_31 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
V_2 -> V_9 = NULL ;
if ( V_9 -> V_29 & V_51 ) {
if ( V_9 -> V_29 & V_52 ) {
V_9 -> V_53 [ 3 ] =
F_16 ( V_2 , V_54 ) ;
V_9 -> V_53 [ 2 ] =
F_16 ( V_2 , V_55 ) ;
V_9 -> V_53 [ 1 ] =
F_16 ( V_2 , V_56 ) ;
V_9 -> V_53 [ 0 ] =
F_16 ( V_2 , V_57 ) ;
} else {
V_9 -> V_53 [ 0 ] =
F_16 ( V_2 , V_54 ) ;
}
}
if ( V_2 -> V_31 == NULL || V_9 -> error ) {
V_2 -> V_49 = NULL ;
F_13 ( V_2 -> V_18 , V_9 -> V_49 ) ;
}
}
static T_4 F_17 ( int V_58 , void * V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_59 ;
T_5 V_60 ;
int V_61 = 0 ;
int V_62 = 0 ;
int V_63 = 0 ;
int V_64 = 0 ;
int V_65 = 0 ;
while ( ( V_60 = F_16 ( V_2 , V_66 ) ) != 0 ) {
F_9 ( V_2 , V_66 , V_60 ) ;
if ( V_60 & V_67 )
V_61 = 1 ;
if ( V_60 & V_68 )
V_62 = 1 ;
if ( V_60 & V_69 )
V_64 = 1 ;
if ( V_60 & V_70 ) {
V_61 = 0 ;
V_65 = 1 ;
}
}
if ( V_65 ) {
struct V_71 * V_49 = V_2 -> V_49 ;
V_49 -> V_9 -> error = - V_72 ;
V_2 -> V_49 = NULL ;
F_13 ( V_2 -> V_18 , V_49 ) ;
}
if ( V_61 )
F_15 ( V_2 , V_2 -> V_9 ) ;
if ( V_63 )
F_10 ( V_2 , V_2 -> V_31 ) ;
else if ( V_62 ) {
V_2 -> V_50 = 1 ;
F_14 ( V_2 , V_2 -> V_31 ) ;
} else if ( V_2 -> V_31 != NULL ) {
V_2 -> V_50 = 1 ;
F_14 ( V_2 , V_2 -> V_31 ) ;
}
if ( V_64 ) {
T_2 V_73 = F_16 ( V_2 , V_74 ) ;
F_18 ( L_5 , V_75 ,
( V_73 & V_76 ) ) ;
F_19 ( V_2 -> V_18 , 0 ) ;
}
if ( ! V_61 && ! V_62 &&
! V_63 && ! V_64 && ! V_65 ) {
V_60 = F_16 ( V_2 , V_66 ) ;
F_20 ( F_7 ( V_2 -> V_18 ) , L_6 , V_60 ) ;
if ( V_60 != 0 ) {
F_9 ( V_2 , V_66 , V_60 ) ;
F_9 ( V_2 , V_77 , 0 ) ;
}
}
return V_78 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_71 * V_79 )
{
struct V_36 * V_31 = V_79 -> V_31 ;
int V_80 ;
unsigned V_47 ;
enum V_38 V_39 ;
V_2 -> V_31 = V_31 ;
if ( V_31 == NULL ) {
F_9 ( V_2 , V_81 , 0 ) ;
F_9 ( V_2 , V_82 , 0 ) ;
V_2 -> V_37 = 0 ;
return;
}
V_80 = V_31 -> V_83 ;
F_9 ( V_2 , V_82 , V_31 -> V_84 - 1 ) ;
F_9 ( V_2 , V_81 , V_80 - 1 ) ;
V_47 = ( V_31 -> V_84 == 1 ) ? 1 : V_31 -> V_47 ;
if ( V_31 -> V_29 & V_32 )
V_39 = V_40 ;
else
V_39 = V_41 ;
V_2 -> V_47 = F_22 ( F_7 ( V_2 -> V_18 ) , V_31 -> V_43 ,
V_47 , V_39 ) ;
V_2 -> V_50 = 0 ;
V_2 -> V_37 = 1 ;
if ( V_39 == V_40 ) {
const T_3 * V_85 = ( T_3 * ) F_11 ( V_31 -> V_43 ) ;
memcpy ( V_2 -> V_44 , V_85 , V_31 -> V_43 -> V_45 ) ;
}
}
static void F_23 ( struct V_86 * V_18 , struct V_71 * V_79 )
{
struct V_1 * V_2 = F_24 ( V_18 ) ;
F_25 ( V_2 -> V_49 != NULL ) ;
V_2 -> V_49 = V_79 ;
F_21 ( V_2 , V_79 ) ;
F_4 ( V_2 , V_79 -> V_9 ) ;
if ( V_79 -> V_9 -> V_26 == V_87 &&
V_79 -> V_9 -> V_29 == ( V_88 | V_89 | V_23 ) )
V_79 -> V_9 -> error = - V_90 ;
}
static void F_26 ( struct V_86 * V_18 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_24 ( V_18 ) ;
V_2 -> V_27 = V_92 -> V_27 ;
V_2 -> V_93 = V_2 -> V_27 ;
}
static int F_27 ( struct V_86 * V_18 )
{
T_6 V_73 ;
struct V_1 * V_2 = F_24 ( V_18 ) ;
V_73 = F_16 ( V_2 , V_74 ) ;
return ( ( V_73 & V_94 ) != 0 ) ;
}
static int F_28 ( struct V_95 * V_96 )
{
struct V_86 * V_18 ;
struct V_1 * V_2 = NULL ;
struct V_97 * V_98 ;
int V_99 = 0 ;
int V_58 ;
T_7 V_100 ;
V_98 = F_29 ( V_96 , V_101 , 0 ) ;
V_58 = F_30 ( V_96 , 0 ) ;
if ( V_98 == NULL || V_58 < 0 )
return - V_102 ;
V_18 = F_31 ( sizeof( struct V_1 ) , & V_96 -> V_4 ) ;
if ( V_18 == NULL ) {
V_99 = - V_103 ;
goto V_104;
}
V_2 = F_24 ( V_18 ) ;
V_2 -> V_18 = V_18 ;
F_32 ( L_7 , ( long ) V_98 -> V_105 , ( long ) V_98 -> V_106 ) ;
V_2 -> V_107 = F_33 ( V_98 -> V_105 , F_34 ( V_98 ) ) ;
if ( V_2 -> V_107 == NULL ) {
V_99 = - V_103 ;
goto V_108;
}
V_2 -> V_44 = F_35 ( & V_96 -> V_4 , V_109 ,
& V_100 , V_110 ) ;
if ( V_2 -> V_44 == 0 ) {
V_99 = - V_103 ;
goto V_111;
}
V_2 -> V_112 = V_100 ;
V_2 -> V_113 = V_96 -> V_113 ;
V_2 -> V_58 = V_58 ;
V_18 -> V_114 = & V_115 ;
V_18 -> V_116 = 400000 ;
V_18 -> V_117 = 24000000 ;
V_18 -> V_118 = V_119 | V_120 ;
V_18 -> V_121 = V_122 ;
V_18 -> V_123 = 32 ;
V_18 -> V_124 = 2048 ;
V_18 -> V_125 = 2048 ;
V_18 -> V_126 = V_109 ;
V_18 -> V_127 = V_18 -> V_126 ;
V_99 = F_36 ( V_2 -> V_58 , F_17 , 0 , V_128 , V_2 ) ;
if ( V_99 ) {
F_6 ( & V_96 -> V_4 , L_8 ) ;
goto V_129;
}
V_2 -> V_4 = & V_96 -> V_4 ;
F_37 ( V_96 , V_2 ) ;
V_99 = F_38 ( & V_96 -> V_4 , & V_130 ) ;
if ( V_99 )
F_39 ( F_7 ( V_2 -> V_18 ) ,
L_9 ) ;
F_9 ( V_2 , V_131 , V_2 -> V_112 ) ;
F_9 ( V_2 , V_77 ,
V_67 | V_68 |
V_69 | V_70 ) ;
F_40 ( V_18 ) ;
return 0 ;
V_129:
F_41 ( & V_96 -> V_4 , V_109 , V_2 -> V_44 ,
V_2 -> V_112 ) ;
V_111:
F_42 ( V_2 -> V_107 ) ;
V_108:
F_43 ( V_2 -> V_18 ) ;
V_104:
return V_99 ;
}
static int F_44 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_45 ( V_96 ) ;
F_37 ( V_96 , NULL ) ;
F_46 ( V_2 == NULL ) ;
F_47 ( V_2 -> V_18 ) ;
F_48 ( V_2 -> V_58 , V_2 ) ;
F_41 ( & V_96 -> V_4 , V_109 , V_2 -> V_44 , V_2 -> V_112 ) ;
F_42 ( V_2 -> V_107 ) ;
F_43 ( V_2 -> V_18 ) ;
return 0 ;
}
