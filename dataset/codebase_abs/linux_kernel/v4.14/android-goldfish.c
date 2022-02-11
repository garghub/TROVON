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
V_39 = F_11 ( V_31 ) ;
if ( V_39 == V_40 ) {
T_3 * V_41 = ( T_3 * ) F_12 ( V_31 -> V_42 ) ;
memcpy ( V_41 , V_2 -> V_43 , V_31 -> V_42 -> V_44 ) ;
}
V_2 -> V_31 -> V_45 += V_31 -> V_42 -> V_44 ;
F_13 ( F_7 ( V_2 -> V_18 ) , V_31 -> V_42 , V_2 -> V_46 ,
V_39 ) ;
}
V_2 -> V_31 = NULL ;
V_2 -> V_46 = 0 ;
if ( ! V_31 -> V_47 ) {
V_2 -> V_48 = NULL ;
F_14 ( V_2 -> V_18 , V_31 -> V_48 ) ;
return;
}
F_4 ( V_2 , V_31 -> V_47 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_36 * V_31 )
{
if ( ! V_2 -> V_37 ) {
F_10 ( V_2 , V_31 ) ;
return;
}
if ( V_2 -> V_49 )
F_10 ( V_2 , V_31 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
V_2 -> V_9 = NULL ;
if ( V_9 -> V_29 & V_50 ) {
if ( V_9 -> V_29 & V_51 ) {
V_9 -> V_52 [ 3 ] =
F_17 ( V_2 , V_53 ) ;
V_9 -> V_52 [ 2 ] =
F_17 ( V_2 , V_54 ) ;
V_9 -> V_52 [ 1 ] =
F_17 ( V_2 , V_55 ) ;
V_9 -> V_52 [ 0 ] =
F_17 ( V_2 , V_56 ) ;
} else {
V_9 -> V_52 [ 0 ] =
F_17 ( V_2 , V_53 ) ;
}
}
if ( V_2 -> V_31 == NULL || V_9 -> error ) {
V_2 -> V_48 = NULL ;
F_14 ( V_2 -> V_18 , V_9 -> V_48 ) ;
}
}
static T_4 F_18 ( int V_57 , void * V_58 )
{
struct V_1 * V_2 = (struct V_1 * ) V_58 ;
T_5 V_59 ;
int V_60 = 0 ;
int V_61 = 0 ;
int V_62 = 0 ;
int V_63 = 0 ;
while ( ( V_59 = F_17 ( V_2 , V_64 ) ) != 0 ) {
F_9 ( V_2 , V_64 , V_59 ) ;
if ( V_59 & V_65 )
V_60 = 1 ;
if ( V_59 & V_66 )
V_61 = 1 ;
if ( V_59 & V_67 )
V_62 = 1 ;
if ( V_59 & V_68 ) {
V_60 = 0 ;
V_63 = 1 ;
}
}
if ( V_63 ) {
struct V_69 * V_48 = V_2 -> V_48 ;
V_48 -> V_9 -> error = - V_70 ;
V_2 -> V_48 = NULL ;
F_14 ( V_2 -> V_18 , V_48 ) ;
}
if ( V_60 )
F_16 ( V_2 , V_2 -> V_9 ) ;
if ( V_61 ) {
V_2 -> V_49 = 1 ;
F_15 ( V_2 , V_2 -> V_31 ) ;
} else if ( V_2 -> V_31 != NULL ) {
V_2 -> V_49 = 1 ;
F_15 ( V_2 , V_2 -> V_31 ) ;
}
if ( V_62 ) {
T_2 V_71 = F_17 ( V_2 , V_72 ) ;
F_19 ( L_5 , V_73 ,
( V_71 & V_74 ) ) ;
F_20 ( V_2 -> V_18 , 0 ) ;
}
if ( ! V_60 && ! V_61 && ! V_62 && ! V_63 ) {
V_59 = F_17 ( V_2 , V_64 ) ;
F_21 ( F_7 ( V_2 -> V_18 ) , L_6 , V_59 ) ;
if ( V_59 != 0 ) {
F_9 ( V_2 , V_64 , V_59 ) ;
F_9 ( V_2 , V_75 , 0 ) ;
}
}
return V_76 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_69 * V_77 )
{
struct V_36 * V_31 = V_77 -> V_31 ;
int V_78 ;
unsigned V_46 ;
enum V_38 V_39 ;
V_2 -> V_31 = V_31 ;
if ( V_31 == NULL ) {
F_9 ( V_2 , V_79 , 0 ) ;
F_9 ( V_2 , V_80 , 0 ) ;
V_2 -> V_37 = 0 ;
return;
}
V_78 = V_31 -> V_81 ;
F_9 ( V_2 , V_80 , V_31 -> V_82 - 1 ) ;
F_9 ( V_2 , V_79 , V_78 - 1 ) ;
V_46 = ( V_31 -> V_82 == 1 ) ? 1 : V_31 -> V_46 ;
V_39 = F_11 ( V_31 ) ;
V_2 -> V_46 = F_23 ( F_7 ( V_2 -> V_18 ) , V_31 -> V_42 ,
V_46 , V_39 ) ;
V_2 -> V_49 = 0 ;
V_2 -> V_37 = 1 ;
if ( V_39 == V_83 ) {
const T_3 * V_84 = ( T_3 * ) F_12 ( V_31 -> V_42 ) ;
memcpy ( V_2 -> V_43 , V_84 , V_31 -> V_42 -> V_44 ) ;
}
}
static void F_24 ( struct V_85 * V_18 , struct V_69 * V_77 )
{
struct V_1 * V_2 = F_25 ( V_18 ) ;
F_26 ( V_2 -> V_48 != NULL ) ;
V_2 -> V_48 = V_77 ;
F_22 ( V_2 , V_77 ) ;
F_4 ( V_2 , V_77 -> V_9 ) ;
if ( V_77 -> V_9 -> V_26 == V_86 &&
V_77 -> V_9 -> V_29 == ( V_87 | V_88 | V_23 ) )
V_77 -> V_9 -> error = - V_89 ;
}
static void F_27 ( struct V_85 * V_18 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_25 ( V_18 ) ;
V_2 -> V_27 = V_91 -> V_27 ;
V_2 -> V_92 = V_2 -> V_27 ;
}
static int F_28 ( struct V_85 * V_18 )
{
T_6 V_71 ;
struct V_1 * V_2 = F_25 ( V_18 ) ;
V_71 = F_17 ( V_2 , V_72 ) ;
return ( ( V_71 & V_93 ) != 0 ) ;
}
static int F_29 ( struct V_94 * V_95 )
{
struct V_85 * V_18 ;
struct V_1 * V_2 = NULL ;
struct V_96 * V_97 ;
int V_98 = 0 ;
int V_57 ;
T_7 V_99 ;
V_97 = F_30 ( V_95 , V_100 , 0 ) ;
V_57 = F_31 ( V_95 , 0 ) ;
if ( V_97 == NULL || V_57 < 0 )
return - V_101 ;
V_18 = F_32 ( sizeof( struct V_1 ) , & V_95 -> V_4 ) ;
if ( V_18 == NULL ) {
V_98 = - V_102 ;
goto V_103;
}
V_2 = F_25 ( V_18 ) ;
V_2 -> V_18 = V_18 ;
F_33 ( L_7 , ( long ) V_97 -> V_104 , ( long ) V_97 -> V_105 ) ;
V_2 -> V_106 = F_34 ( V_97 -> V_104 , F_35 ( V_97 ) ) ;
if ( V_2 -> V_106 == NULL ) {
V_98 = - V_102 ;
goto V_107;
}
V_2 -> V_43 = F_36 ( & V_95 -> V_4 , V_108 ,
& V_99 , V_109 ) ;
if ( V_2 -> V_43 == 0 ) {
V_98 = - V_102 ;
goto V_110;
}
V_2 -> V_111 = V_99 ;
V_2 -> V_112 = V_95 -> V_112 ;
V_2 -> V_57 = V_57 ;
V_18 -> V_113 = & V_114 ;
V_18 -> V_115 = 400000 ;
V_18 -> V_116 = 24000000 ;
V_18 -> V_117 = V_118 | V_119 ;
V_18 -> V_120 = V_121 ;
V_18 -> V_122 = 32 ;
V_18 -> V_123 = 2048 ;
V_18 -> V_124 = 2048 ;
V_18 -> V_125 = V_108 ;
V_18 -> V_126 = V_18 -> V_125 ;
V_98 = F_37 ( V_2 -> V_57 , F_18 , 0 , V_127 , V_2 ) ;
if ( V_98 ) {
F_6 ( & V_95 -> V_4 , L_8 ) ;
goto V_128;
}
V_2 -> V_4 = & V_95 -> V_4 ;
F_38 ( V_95 , V_2 ) ;
V_98 = F_39 ( & V_95 -> V_4 , & V_129 ) ;
if ( V_98 )
F_40 ( F_7 ( V_2 -> V_18 ) ,
L_9 ) ;
F_9 ( V_2 , V_130 , V_2 -> V_111 ) ;
F_9 ( V_2 , V_75 ,
V_65 | V_66 |
V_67 | V_68 ) ;
F_41 ( V_18 ) ;
return 0 ;
V_128:
F_42 ( & V_95 -> V_4 , V_108 , V_2 -> V_43 ,
V_2 -> V_111 ) ;
V_110:
F_43 ( V_2 -> V_106 ) ;
V_107:
F_44 ( V_2 -> V_18 ) ;
V_103:
return V_98 ;
}
static int F_45 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_46 ( V_95 ) ;
F_47 ( V_2 == NULL ) ;
F_48 ( V_2 -> V_18 ) ;
F_49 ( V_2 -> V_57 , V_2 ) ;
F_42 ( & V_95 -> V_4 , V_108 , V_2 -> V_43 , V_2 -> V_111 ) ;
F_43 ( V_2 -> V_106 ) ;
F_44 ( V_2 -> V_18 ) ;
return 0 ;
}
