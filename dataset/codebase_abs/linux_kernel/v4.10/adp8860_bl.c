static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 , L_1 , V_3 ) ;
return V_5 ;
}
* V_4 = ( T_1 ) V_5 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
return F_5 ( V_2 , V_3 , V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 , T_1 V_7 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
T_1 V_10 ;
int V_5 ;
F_8 ( & V_9 -> V_11 ) ;
V_5 = F_1 ( V_2 , V_3 , & V_10 ) ;
if ( ! V_5 && ( ( V_10 & V_7 ) != V_7 ) ) {
V_10 |= V_7 ;
V_5 = F_4 ( V_2 , V_3 , V_10 ) ;
}
F_9 ( & V_9 -> V_11 ) ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 , int V_3 , T_1 V_7 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
T_1 V_10 ;
int V_5 ;
F_8 ( & V_9 -> V_11 ) ;
V_5 = F_1 ( V_2 , V_3 , & V_10 ) ;
if ( ! V_5 && ( V_10 & V_7 ) ) {
V_10 &= ~ V_7 ;
V_5 = F_4 ( V_2 , V_3 , V_10 ) ;
}
F_9 ( & V_9 -> V_11 ) ;
return V_5 ;
}
static void F_11 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_12 ( V_13 , struct V_14 , V_13 ) ;
F_4 ( V_15 -> V_2 , V_16 - V_15 -> V_17 + 1 ,
V_15 -> V_18 >> 1 ) ;
}
static void F_13 ( struct V_19 * V_20 ,
enum V_21 V_22 )
{
struct V_14 * V_15 ;
V_15 = F_12 ( V_20 , struct V_14 , V_23 ) ;
V_15 -> V_18 = V_22 ;
F_14 ( & V_15 -> V_13 ) ;
}
static int F_15 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
int V_5 = 0 ;
V_5 = F_4 ( V_2 , V_16 - V_15 -> V_17 + 1 , 0 ) ;
V_5 |= F_6 ( V_2 , V_24 , 1 << ( V_15 -> V_17 - 1 ) ) ;
if ( V_15 -> V_17 > 4 )
V_5 |= F_6 ( V_2 , V_25 ,
( V_15 -> V_26 & 0x3 ) << ( ( V_15 -> V_17 - 5 ) * 2 ) ) ;
else
V_5 |= F_6 ( V_2 , V_27 ,
( V_15 -> V_26 & 0x3 ) << ( ( V_15 -> V_17 - 1 ) * 2 ) ) ;
return V_5 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_28 * V_29 =
F_17 ( & V_2 -> V_6 ) ;
struct V_8 * V_9 = F_7 ( V_2 ) ;
struct V_14 * V_15 , * V_30 ;
struct V_31 * V_32 ;
int V_5 , V_33 ;
V_15 = F_18 ( & V_2 -> V_6 , sizeof( * V_15 ) * V_29 -> V_34 ,
V_35 ) ;
if ( V_15 == NULL )
return - V_36 ;
V_5 = F_4 ( V_2 , V_37 , V_29 -> V_38 ) ;
V_5 = F_4 ( V_2 , V_25 ,
( V_29 -> V_39 & 0x3 ) << 6 ) ;
V_5 |= F_4 ( V_2 , V_40 ,
F_19 ( V_29 -> V_41 , V_29 -> V_42 ) ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_2 ) ;
return V_5 ;
}
for ( V_33 = 0 ; V_33 < V_29 -> V_34 ; ++ V_33 ) {
V_32 = & V_29 -> V_43 [ V_33 ] ;
V_30 = & V_15 [ V_33 ] ;
V_30 -> V_17 = V_32 -> V_26 & V_44 ;
if ( V_30 -> V_17 > 7 || V_30 -> V_17 < 1 ) {
F_3 ( & V_2 -> V_6 , L_3 ,
V_30 -> V_17 ) ;
V_5 = - V_45 ;
goto V_46;
}
if ( V_29 -> V_47 & ( 1 << ( V_30 -> V_17 - 1 ) ) ) {
F_3 ( & V_2 -> V_6 , L_4 ,
V_30 -> V_17 ) ;
V_5 = - V_48 ;
goto V_46;
}
V_30 -> V_23 . V_49 = V_32 -> V_49 ;
V_30 -> V_23 . V_50 = V_32 -> V_50 ;
V_30 -> V_23 . V_51 = F_13 ;
V_30 -> V_23 . V_52 = V_53 ;
V_30 -> V_26 = V_32 -> V_26 >> V_54 ;
V_30 -> V_2 = V_2 ;
V_30 -> V_18 = V_53 ;
F_20 ( & V_30 -> V_13 , F_11 ) ;
V_5 = F_21 ( & V_2 -> V_6 , & V_30 -> V_23 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_5 ,
V_30 -> V_17 ) ;
goto V_46;
}
V_5 = F_15 ( V_30 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_2 ) ;
V_33 ++ ;
goto V_46;
}
}
V_9 -> V_15 = V_15 ;
return 0 ;
V_46:
for ( V_33 = V_33 - 1 ; V_33 >= 0 ; -- V_33 ) {
F_22 ( & V_15 [ V_33 ] . V_23 ) ;
F_23 ( & V_15 [ V_33 ] . V_13 ) ;
}
return V_5 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_28 * V_29 =
F_17 ( & V_2 -> V_6 ) ;
struct V_8 * V_9 = F_7 ( V_2 ) ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_29 -> V_34 ; V_33 ++ ) {
F_22 ( & V_9 -> V_15 [ V_33 ] . V_23 ) ;
F_23 ( & V_9 -> V_15 [ V_33 ] . V_13 ) ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_25 ( struct V_55 * V_56 , int V_52 )
{
struct V_8 * V_9 = F_26 ( V_56 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_5 = 0 ;
if ( V_9 -> V_57 ) {
if ( ( V_52 > 0 ) && ( V_52 < V_58 ) ) {
V_5 |= F_10 ( V_2 , V_59 ,
V_60 ) ;
V_5 |= F_4 ( V_2 , V_61 , V_52 ) ;
} else {
V_5 |= F_4 ( V_2 , V_61 ,
V_9 -> V_62 ) ;
V_5 |= F_6 ( V_2 , V_59 ,
V_60 ) ;
}
} else
V_5 |= F_4 ( V_2 , V_61 , V_52 ) ;
if ( V_9 -> V_63 && V_52 == 0 )
V_5 |= F_6 ( V_2 ,
V_59 , V_64 ) ;
else if ( V_9 -> V_63 == 0 && V_52 )
V_5 |= F_10 ( V_2 ,
V_59 , V_64 ) ;
if ( ! V_5 )
V_9 -> V_63 = V_52 ;
return V_5 ;
}
static int F_27 ( struct V_55 * V_56 )
{
int V_52 = V_56 -> V_65 . V_52 ;
if ( V_56 -> V_65 . V_66 != V_67 )
V_52 = 0 ;
if ( V_56 -> V_65 . V_68 != V_67 )
V_52 = 0 ;
return F_25 ( V_56 , V_52 ) ;
}
static int F_28 ( struct V_55 * V_56 )
{
struct V_8 * V_9 = F_26 ( V_56 ) ;
return V_9 -> V_63 ;
}
static int F_29 ( struct V_55 * V_56 )
{
struct V_8 * V_9 = F_26 ( V_56 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_28 * V_29 = V_9 -> V_29 ;
int V_5 = 0 ;
V_5 |= F_4 ( V_2 , V_69 , ~ V_29 -> V_47 ) ;
V_5 |= F_4 ( V_2 , V_61 , V_29 -> V_70 ) ;
V_5 |= F_4 ( V_2 , V_71 , V_29 -> V_72 ) ;
if ( V_9 -> V_57 ) {
V_9 -> V_62 = V_29 -> V_70 ;
V_5 |= F_4 ( V_2 , V_73 ,
V_29 -> V_74 ) ;
V_5 |= F_4 ( V_2 , V_75 ,
V_29 -> V_76 ) ;
V_5 |= F_4 ( V_2 , V_77 ,
V_29 -> V_78 ) ;
V_5 |= F_4 ( V_2 , V_79 ,
V_29 -> V_80 ) ;
V_5 |= F_4 ( V_2 , V_81 , V_29 -> V_82 ) ;
V_5 |= F_4 ( V_2 , V_83 , V_29 -> V_84 ) ;
V_5 |= F_4 ( V_2 , V_85 , V_29 -> V_86 ) ;
V_5 |= F_4 ( V_2 , V_87 , V_29 -> V_88 ) ;
V_5 |= F_4 ( V_2 , V_89 , V_90 | V_91 |
F_30 ( V_29 -> V_92 ) ) ;
}
V_5 |= F_4 ( V_2 , V_93 ,
F_31 ( V_29 -> V_94 , 0 ) ) ;
V_5 |= F_4 ( V_2 , V_95 , F_19 ( V_29 -> V_96 ,
V_29 -> V_97 ) ) ;
V_5 |= F_6 ( V_2 , V_59 , V_98 | V_64 | V_99 |
( V_9 -> V_100 ? V_101 : 0 ) ) ;
return V_5 ;
}
static T_3 F_32 ( struct V_102 * V_6 , char * V_103 , int V_3 )
{
struct V_8 * V_9 = F_33 ( V_6 ) ;
int error ;
T_1 V_10 ;
F_8 ( & V_9 -> V_11 ) ;
error = F_1 ( V_9 -> V_2 , V_3 , & V_10 ) ;
F_9 ( & V_9 -> V_11 ) ;
if ( error < 0 )
return error ;
return sprintf ( V_103 , L_6 , V_10 ) ;
}
static T_3 F_34 ( struct V_102 * V_6 , const char * V_103 ,
T_4 V_104 , int V_3 )
{
struct V_8 * V_9 = F_33 ( V_6 ) ;
unsigned long V_4 ;
int V_5 ;
V_5 = F_35 ( V_103 , 10 , & V_4 ) ;
if ( V_5 )
return V_5 ;
F_8 ( & V_9 -> V_11 ) ;
F_4 ( V_9 -> V_2 , V_3 , V_4 ) ;
F_9 ( & V_9 -> V_11 ) ;
return V_104 ;
}
static T_3 F_36 ( struct V_102 * V_6 ,
struct V_105 * V_106 , char * V_103 )
{
return F_32 ( V_6 , V_103 , V_77 ) ;
}
static T_3 F_37 ( struct V_102 * V_6 ,
struct V_105 * V_106 , const char * V_103 , T_4 V_104 )
{
return F_34 ( V_6 , V_103 , V_104 , V_77 ) ;
}
static T_3 F_38 ( struct V_102 * V_6 ,
struct V_105 * V_106 , char * V_103 )
{
return F_32 ( V_6 , V_103 , V_73 ) ;
}
static T_3 F_39 ( struct V_102 * V_6 ,
struct V_105 * V_106 , const char * V_103 , T_4 V_104 )
{
return F_34 ( V_6 , V_103 , V_104 , V_73 ) ;
}
static T_3 F_40 ( struct V_102 * V_6 ,
struct V_105 * V_106 , char * V_103 )
{
return F_32 ( V_6 , V_103 , V_61 ) ;
}
static T_3 F_41 ( struct V_102 * V_6 ,
struct V_105 * V_106 , const char * V_103 , T_4 V_104 )
{
struct V_8 * V_9 = F_33 ( V_6 ) ;
int V_5 = F_35 ( V_103 , 10 , & V_9 -> V_62 ) ;
if ( V_5 )
return V_5 ;
return F_34 ( V_6 , V_103 , V_104 , V_61 ) ;
}
static T_3 F_42 ( struct V_102 * V_6 ,
struct V_105 * V_106 , char * V_103 )
{
return F_32 ( V_6 , V_103 , V_79 ) ;
}
static T_3 F_43 ( struct V_102 * V_6 ,
struct V_105 * V_106 ,
const char * V_103 , T_4 V_104 )
{
return F_34 ( V_6 , V_103 , V_104 , V_79 ) ;
}
static T_3 F_44 ( struct V_102 * V_6 ,
struct V_105 * V_106 , char * V_103 )
{
return F_32 ( V_6 , V_103 , V_75 ) ;
}
static T_3 F_45 ( struct V_102 * V_6 ,
struct V_105 * V_106 ,
const char * V_103 , T_4 V_104 )
{
return F_34 ( V_6 , V_103 , V_104 , V_75 ) ;
}
static T_3 F_46 ( struct V_102 * V_6 ,
struct V_105 * V_106 , char * V_103 )
{
return F_32 ( V_6 , V_103 , V_71 ) ;
}
static T_3 F_47 ( struct V_102 * V_6 ,
struct V_105 * V_106 ,
const char * V_103 , T_4 V_104 )
{
return F_34 ( V_6 , V_103 , V_104 , V_71 ) ;
}
static T_3 F_48 ( struct V_102 * V_6 ,
struct V_105 * V_106 , char * V_103 )
{
struct V_8 * V_9 = F_33 ( V_6 ) ;
int error ;
T_1 V_10 ;
T_5 V_107 ;
F_8 ( & V_9 -> V_11 ) ;
error = F_1 ( V_9 -> V_2 , V_108 , & V_10 ) ;
if ( ! error ) {
V_107 = V_10 ;
error = F_1 ( V_9 -> V_2 , V_109 , & V_10 ) ;
}
F_9 ( & V_9 -> V_11 ) ;
if ( error )
return error ;
V_107 += ( V_10 & 0x1F ) << 8 ;
return sprintf ( V_103 , L_6 , V_107 ) ;
}
static T_3 F_49 ( struct V_102 * V_6 ,
struct V_105 * V_106 , char * V_103 )
{
struct V_8 * V_9 = F_33 ( V_6 ) ;
int error ;
T_1 V_10 ;
F_8 ( & V_9 -> V_11 ) ;
error = F_1 ( V_9 -> V_2 , V_93 , & V_10 ) ;
F_9 ( & V_9 -> V_11 ) ;
if ( error < 0 )
return error ;
return sprintf ( V_103 , L_6 ,
( ( V_10 >> V_110 ) & V_111 ) + 1 ) ;
}
static T_3 F_50 ( struct V_102 * V_6 ,
struct V_105 * V_106 ,
const char * V_103 , T_4 V_104 )
{
struct V_8 * V_9 = F_33 ( V_6 ) ;
unsigned long V_4 ;
T_1 V_10 ;
int V_5 ;
V_5 = F_35 ( V_103 , 10 , & V_4 ) ;
if ( V_5 )
return V_5 ;
if ( V_4 == 0 ) {
F_6 ( V_9 -> V_2 , V_59 , V_60 ) ;
} else if ( ( V_4 > 0 ) && ( V_4 <= 3 ) ) {
F_10 ( V_9 -> V_2 , V_59 , V_60 ) ;
F_8 ( & V_9 -> V_11 ) ;
V_5 = F_1 ( V_9 -> V_2 , V_93 , & V_10 ) ;
if ( ! V_5 ) {
V_10 &= ~ ( V_111 << V_110 ) ;
V_10 |= ( V_4 - 1 ) << V_110 ;
F_4 ( V_9 -> V_2 , V_93 , V_10 ) ;
}
F_9 ( & V_9 -> V_11 ) ;
}
return V_104 ;
}
static int F_51 ( struct V_1 * V_2 ,
const struct V_112 * V_17 )
{
struct V_55 * V_56 ;
struct V_8 * V_9 ;
struct V_28 * V_29 =
F_17 ( & V_2 -> V_6 ) ;
struct V_113 V_65 ;
T_1 V_10 ;
int V_5 ;
if ( ! F_52 ( V_2 -> V_114 ,
V_115 ) ) {
F_3 ( & V_2 -> V_6 , L_7 ) ;
return - V_116 ;
}
if ( ! V_29 ) {
F_3 ( & V_2 -> V_6 , L_8 ) ;
return - V_45 ;
}
V_9 = F_18 ( & V_2 -> V_6 , sizeof( * V_9 ) , V_35 ) ;
if ( V_9 == NULL )
return - V_36 ;
V_5 = F_1 ( V_2 , V_117 , & V_10 ) ;
if ( V_5 < 0 )
return V_5 ;
switch ( F_53 ( V_10 ) ) {
case V_118 :
V_9 -> V_100 = ! ! V_29 -> V_100 ;
case V_119 :
V_9 -> V_57 = ! ! V_29 -> V_57 ;
break;
case V_120 :
V_9 -> V_100 = ! ! V_29 -> V_100 ;
break;
default:
F_3 ( & V_2 -> V_6 , L_9 ) ;
return - V_121 ;
}
V_9 -> V_122 = F_54 ( V_10 ) ;
V_9 -> V_2 = V_2 ;
V_9 -> V_29 = V_29 ;
V_9 -> V_17 = V_17 -> V_123 ;
V_9 -> V_63 = 0 ;
F_55 ( V_2 , V_9 ) ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . type = V_124 ;
V_65 . V_125 = V_58 ;
F_56 ( & V_9 -> V_11 ) ;
V_56 = F_57 ( & V_2 -> V_6 ,
F_58 ( & V_2 -> V_6 ) ,
& V_2 -> V_6 , V_9 , & V_126 , & V_65 ) ;
if ( F_59 ( V_56 ) ) {
F_3 ( & V_2 -> V_6 , L_10 ) ;
return F_60 ( V_56 ) ;
}
V_56 -> V_65 . V_52 = V_58 ;
V_9 -> V_56 = V_56 ;
if ( V_9 -> V_57 )
V_5 = F_61 ( & V_56 -> V_6 . V_127 ,
& V_128 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_11 ) ;
return V_5 ;
}
V_5 = F_29 ( V_56 ) ;
if ( V_5 ) {
V_5 = - V_116 ;
goto V_129;
}
F_62 ( V_56 ) ;
F_63 ( & V_2 -> V_6 , L_12 ,
V_2 -> V_49 , V_9 -> V_122 ) ;
if ( V_29 -> V_34 )
F_16 ( V_2 ) ;
return 0 ;
V_129:
if ( V_9 -> V_57 )
F_64 ( & V_9 -> V_56 -> V_6 . V_127 ,
& V_128 ) ;
return V_5 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
F_10 ( V_2 , V_59 , V_99 ) ;
if ( V_9 -> V_15 )
F_24 ( V_2 ) ;
if ( V_9 -> V_57 )
F_64 ( & V_9 -> V_56 -> V_6 . V_127 ,
& V_128 ) ;
return 0 ;
}
static int F_66 ( struct V_102 * V_6 )
{
struct V_1 * V_2 = F_67 ( V_6 ) ;
F_10 ( V_2 , V_59 , V_99 ) ;
return 0 ;
}
static int F_68 ( struct V_102 * V_6 )
{
struct V_1 * V_2 = F_67 ( V_6 ) ;
F_6 ( V_2 , V_59 , V_99 | V_98 ) ;
return 0 ;
}
