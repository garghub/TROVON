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
V_2 -> V_6 . V_30 ;
struct V_8 * V_9 = F_7 ( V_2 ) ;
struct V_14 * V_15 , * V_31 ;
struct V_32 * V_33 ;
int V_5 , V_34 ;
V_15 = F_17 ( & V_2 -> V_6 , sizeof( * V_15 ) * V_29 -> V_35 ,
V_36 ) ;
if ( V_15 == NULL ) {
F_3 ( & V_2 -> V_6 , L_2 ) ;
return - V_37 ;
}
V_5 = F_4 ( V_2 , V_38 , V_29 -> V_39 ) ;
V_5 = F_4 ( V_2 , V_25 ,
( V_29 -> V_40 & 0x3 ) << 6 ) ;
V_5 |= F_4 ( V_2 , V_41 ,
F_18 ( V_29 -> V_42 , V_29 -> V_43 ) ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_3 ) ;
return V_5 ;
}
for ( V_34 = 0 ; V_34 < V_29 -> V_35 ; ++ V_34 ) {
V_33 = & V_29 -> V_44 [ V_34 ] ;
V_31 = & V_15 [ V_34 ] ;
V_31 -> V_17 = V_33 -> V_26 & V_45 ;
if ( V_31 -> V_17 > 7 || V_31 -> V_17 < 1 ) {
F_3 ( & V_2 -> V_6 , L_4 ,
V_31 -> V_17 ) ;
V_5 = - V_46 ;
goto V_47;
}
if ( V_29 -> V_48 & ( 1 << ( V_31 -> V_17 - 1 ) ) ) {
F_3 ( & V_2 -> V_6 , L_5 ,
V_31 -> V_17 ) ;
V_5 = - V_49 ;
goto V_47;
}
V_31 -> V_23 . V_50 = V_33 -> V_50 ;
V_31 -> V_23 . V_51 = V_33 -> V_51 ;
V_31 -> V_23 . V_52 = F_13 ;
V_31 -> V_23 . V_53 = V_54 ;
V_31 -> V_26 = V_33 -> V_26 >> V_55 ;
V_31 -> V_2 = V_2 ;
V_31 -> V_18 = V_54 ;
F_19 ( & V_31 -> V_13 , F_11 ) ;
V_5 = F_20 ( & V_2 -> V_6 , & V_31 -> V_23 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_6 ,
V_31 -> V_17 ) ;
goto V_47;
}
V_5 = F_15 ( V_31 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_3 ) ;
V_34 ++ ;
goto V_47;
}
}
V_9 -> V_15 = V_15 ;
return 0 ;
V_47:
for ( V_34 = V_34 - 1 ; V_34 >= 0 ; -- V_34 ) {
F_21 ( & V_15 [ V_34 ] . V_23 ) ;
F_22 ( & V_15 [ V_34 ] . V_13 ) ;
}
return V_5 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_28 * V_29 =
V_2 -> V_6 . V_30 ;
struct V_8 * V_9 = F_7 ( V_2 ) ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_29 -> V_35 ; V_34 ++ ) {
F_21 ( & V_9 -> V_15 [ V_34 ] . V_23 ) ;
F_22 ( & V_9 -> V_15 [ V_34 ] . V_13 ) ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_24 ( struct V_56 * V_57 , int V_53 )
{
struct V_8 * V_9 = F_25 ( V_57 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_5 = 0 ;
if ( V_9 -> V_58 ) {
if ( ( V_53 > 0 ) && ( V_53 < V_59 ) ) {
V_5 |= F_10 ( V_2 , V_60 ,
V_61 ) ;
V_5 |= F_4 ( V_2 , V_62 , V_53 ) ;
} else {
V_5 |= F_4 ( V_2 , V_62 ,
V_9 -> V_63 ) ;
V_5 |= F_6 ( V_2 , V_60 ,
V_61 ) ;
}
} else
V_5 |= F_4 ( V_2 , V_62 , V_53 ) ;
if ( V_9 -> V_64 && V_53 == 0 )
V_5 |= F_6 ( V_2 ,
V_60 , V_65 ) ;
else if ( V_9 -> V_64 == 0 && V_53 )
V_5 |= F_10 ( V_2 ,
V_60 , V_65 ) ;
if ( ! V_5 )
V_9 -> V_64 = V_53 ;
return V_5 ;
}
static int F_26 ( struct V_56 * V_57 )
{
int V_53 = V_57 -> V_66 . V_53 ;
if ( V_57 -> V_66 . V_67 != V_68 )
V_53 = 0 ;
if ( V_57 -> V_66 . V_69 != V_68 )
V_53 = 0 ;
return F_24 ( V_57 , V_53 ) ;
}
static int F_27 ( struct V_56 * V_57 )
{
struct V_8 * V_9 = F_25 ( V_57 ) ;
return V_9 -> V_64 ;
}
static int F_28 ( struct V_56 * V_57 )
{
struct V_8 * V_9 = F_25 ( V_57 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_28 * V_29 = V_9 -> V_29 ;
int V_5 = 0 ;
V_5 |= F_4 ( V_2 , V_70 , ~ V_29 -> V_48 ) ;
V_5 |= F_4 ( V_2 , V_62 , V_29 -> V_71 ) ;
V_5 |= F_4 ( V_2 , V_72 , V_29 -> V_73 ) ;
if ( V_9 -> V_58 ) {
V_9 -> V_63 = V_29 -> V_71 ;
V_5 |= F_4 ( V_2 , V_74 ,
V_29 -> V_75 ) ;
V_5 |= F_4 ( V_2 , V_76 ,
V_29 -> V_77 ) ;
V_5 |= F_4 ( V_2 , V_78 ,
V_29 -> V_79 ) ;
V_5 |= F_4 ( V_2 , V_80 ,
V_29 -> V_81 ) ;
V_5 |= F_4 ( V_2 , V_82 , V_29 -> V_83 ) ;
V_5 |= F_4 ( V_2 , V_84 , V_29 -> V_85 ) ;
V_5 |= F_4 ( V_2 , V_86 , V_29 -> V_87 ) ;
V_5 |= F_4 ( V_2 , V_88 , V_29 -> V_89 ) ;
V_5 |= F_4 ( V_2 , V_90 , V_91 | V_92 |
F_29 ( V_29 -> V_93 ) ) ;
}
V_5 |= F_4 ( V_2 , V_94 ,
F_30 ( V_29 -> V_95 , 0 ) ) ;
V_5 |= F_4 ( V_2 , V_96 , F_18 ( V_29 -> V_97 ,
V_29 -> V_98 ) ) ;
V_5 |= F_6 ( V_2 , V_60 , V_99 | V_65 | V_100 |
( V_9 -> V_101 ? V_102 : 0 ) ) ;
return V_5 ;
}
static T_3 F_31 ( struct V_103 * V_6 , char * V_104 , int V_3 )
{
struct V_8 * V_9 = F_32 ( V_6 ) ;
int error ;
T_1 V_10 ;
F_8 ( & V_9 -> V_11 ) ;
error = F_1 ( V_9 -> V_2 , V_3 , & V_10 ) ;
F_9 ( & V_9 -> V_11 ) ;
if ( error < 0 )
return error ;
return sprintf ( V_104 , L_7 , V_10 ) ;
}
static T_3 F_33 ( struct V_103 * V_6 , const char * V_104 ,
T_4 V_105 , int V_3 )
{
struct V_8 * V_9 = F_32 ( V_6 ) ;
unsigned long V_4 ;
int V_5 ;
V_5 = F_34 ( V_104 , 10 , & V_4 ) ;
if ( V_5 )
return V_5 ;
F_8 ( & V_9 -> V_11 ) ;
F_4 ( V_9 -> V_2 , V_3 , V_4 ) ;
F_9 ( & V_9 -> V_11 ) ;
return V_105 ;
}
static T_3 F_35 ( struct V_103 * V_6 ,
struct V_106 * V_107 , char * V_104 )
{
return F_31 ( V_6 , V_104 , V_78 ) ;
}
static T_3 F_36 ( struct V_103 * V_6 ,
struct V_106 * V_107 , const char * V_104 , T_4 V_105 )
{
return F_33 ( V_6 , V_104 , V_105 , V_78 ) ;
}
static T_3 F_37 ( struct V_103 * V_6 ,
struct V_106 * V_107 , char * V_104 )
{
return F_31 ( V_6 , V_104 , V_74 ) ;
}
static T_3 F_38 ( struct V_103 * V_6 ,
struct V_106 * V_107 , const char * V_104 , T_4 V_105 )
{
return F_33 ( V_6 , V_104 , V_105 , V_74 ) ;
}
static T_3 F_39 ( struct V_103 * V_6 ,
struct V_106 * V_107 , char * V_104 )
{
return F_31 ( V_6 , V_104 , V_62 ) ;
}
static T_3 F_40 ( struct V_103 * V_6 ,
struct V_106 * V_107 , const char * V_104 , T_4 V_105 )
{
struct V_8 * V_9 = F_32 ( V_6 ) ;
int V_5 = F_34 ( V_104 , 10 , & V_9 -> V_63 ) ;
if ( V_5 )
return V_5 ;
return F_33 ( V_6 , V_104 , V_105 , V_62 ) ;
}
static T_3 F_41 ( struct V_103 * V_6 ,
struct V_106 * V_107 , char * V_104 )
{
return F_31 ( V_6 , V_104 , V_80 ) ;
}
static T_3 F_42 ( struct V_103 * V_6 ,
struct V_106 * V_107 ,
const char * V_104 , T_4 V_105 )
{
return F_33 ( V_6 , V_104 , V_105 , V_80 ) ;
}
static T_3 F_43 ( struct V_103 * V_6 ,
struct V_106 * V_107 , char * V_104 )
{
return F_31 ( V_6 , V_104 , V_76 ) ;
}
static T_3 F_44 ( struct V_103 * V_6 ,
struct V_106 * V_107 ,
const char * V_104 , T_4 V_105 )
{
return F_33 ( V_6 , V_104 , V_105 , V_76 ) ;
}
static T_3 F_45 ( struct V_103 * V_6 ,
struct V_106 * V_107 , char * V_104 )
{
return F_31 ( V_6 , V_104 , V_72 ) ;
}
static T_3 F_46 ( struct V_103 * V_6 ,
struct V_106 * V_107 ,
const char * V_104 , T_4 V_105 )
{
return F_33 ( V_6 , V_104 , V_105 , V_72 ) ;
}
static T_3 F_47 ( struct V_103 * V_6 ,
struct V_106 * V_107 , char * V_104 )
{
struct V_8 * V_9 = F_32 ( V_6 ) ;
int error ;
T_1 V_10 ;
T_5 V_108 ;
F_8 ( & V_9 -> V_11 ) ;
error = F_1 ( V_9 -> V_2 , V_109 , & V_10 ) ;
V_108 = V_10 ;
error |= F_1 ( V_9 -> V_2 , V_110 , & V_10 ) ;
F_9 ( & V_9 -> V_11 ) ;
if ( error < 0 )
return error ;
V_108 += ( V_10 & 0x1F ) << 8 ;
return sprintf ( V_104 , L_7 , V_108 ) ;
}
static T_3 F_48 ( struct V_103 * V_6 ,
struct V_106 * V_107 , char * V_104 )
{
struct V_8 * V_9 = F_32 ( V_6 ) ;
int error ;
T_1 V_10 ;
F_8 ( & V_9 -> V_11 ) ;
error = F_1 ( V_9 -> V_2 , V_94 , & V_10 ) ;
F_9 ( & V_9 -> V_11 ) ;
if ( error < 0 )
return error ;
return sprintf ( V_104 , L_7 ,
( ( V_10 >> V_111 ) & V_112 ) + 1 ) ;
}
static T_3 F_49 ( struct V_103 * V_6 ,
struct V_106 * V_107 ,
const char * V_104 , T_4 V_105 )
{
struct V_8 * V_9 = F_32 ( V_6 ) ;
unsigned long V_4 ;
T_1 V_10 ;
int V_5 ;
V_5 = F_34 ( V_104 , 10 , & V_4 ) ;
if ( V_5 )
return V_5 ;
if ( V_4 == 0 ) {
F_6 ( V_9 -> V_2 , V_60 , V_61 ) ;
} else if ( ( V_4 > 0 ) && ( V_4 <= 3 ) ) {
F_10 ( V_9 -> V_2 , V_60 , V_61 ) ;
F_8 ( & V_9 -> V_11 ) ;
F_1 ( V_9 -> V_2 , V_94 , & V_10 ) ;
V_10 &= ~ ( V_112 << V_111 ) ;
V_10 |= ( V_4 - 1 ) << V_111 ;
F_4 ( V_9 -> V_2 , V_94 , V_10 ) ;
F_9 ( & V_9 -> V_11 ) ;
}
return V_105 ;
}
static int F_50 ( struct V_1 * V_2 ,
const struct V_113 * V_17 )
{
struct V_56 * V_57 ;
struct V_8 * V_9 ;
struct V_28 * V_29 =
V_2 -> V_6 . V_30 ;
struct V_114 V_66 ;
T_1 V_10 ;
int V_5 ;
if ( ! F_51 ( V_2 -> V_115 ,
V_116 ) ) {
F_3 ( & V_2 -> V_6 , L_8 ) ;
return - V_117 ;
}
if ( ! V_29 ) {
F_3 ( & V_2 -> V_6 , L_9 ) ;
return - V_46 ;
}
V_9 = F_17 ( & V_2 -> V_6 , sizeof( * V_9 ) , V_36 ) ;
if ( V_9 == NULL )
return - V_37 ;
V_5 = F_1 ( V_2 , V_118 , & V_10 ) ;
if ( V_5 < 0 )
return V_5 ;
switch ( F_52 ( V_10 ) ) {
case V_119 :
V_9 -> V_101 = ! ! V_29 -> V_101 ;
case V_120 :
V_9 -> V_58 = ! ! V_29 -> V_58 ;
break;
case V_121 :
V_9 -> V_101 = ! ! V_29 -> V_101 ;
break;
default:
F_3 ( & V_2 -> V_6 , L_10 ) ;
return - V_122 ;
}
V_9 -> V_123 = F_53 ( V_10 ) ;
V_9 -> V_2 = V_2 ;
V_9 -> V_29 = V_29 ;
V_9 -> V_17 = V_17 -> V_124 ;
V_9 -> V_64 = 0 ;
F_54 ( V_2 , V_9 ) ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . type = V_125 ;
V_66 . V_126 = V_59 ;
F_55 ( & V_9 -> V_11 ) ;
V_57 = F_56 ( F_57 ( & V_2 -> V_6 ) ,
& V_2 -> V_6 , V_9 , & V_127 , & V_66 ) ;
if ( F_58 ( V_57 ) ) {
F_3 ( & V_2 -> V_6 , L_11 ) ;
return F_59 ( V_57 ) ;
}
V_57 -> V_66 . V_53 = V_59 ;
V_9 -> V_57 = V_57 ;
if ( V_9 -> V_58 )
V_5 = F_60 ( & V_57 -> V_6 . V_128 ,
& V_129 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_12 ) ;
goto V_130;
}
V_5 = F_28 ( V_57 ) ;
if ( V_5 ) {
V_5 = - V_117 ;
goto V_131;
}
F_61 ( V_57 ) ;
F_62 ( & V_2 -> V_6 , L_13 ,
V_2 -> V_50 , V_9 -> V_123 ) ;
if ( V_29 -> V_35 )
F_16 ( V_2 ) ;
return 0 ;
V_131:
if ( V_9 -> V_58 )
F_63 ( & V_9 -> V_57 -> V_6 . V_128 ,
& V_129 ) ;
V_130:
F_64 ( V_57 ) ;
return V_5 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
F_10 ( V_2 , V_60 , V_100 ) ;
if ( V_9 -> V_15 )
F_23 ( V_2 ) ;
if ( V_9 -> V_58 )
F_63 ( & V_9 -> V_57 -> V_6 . V_128 ,
& V_129 ) ;
F_64 ( V_9 -> V_57 ) ;
return 0 ;
}
static int F_66 ( struct V_103 * V_6 )
{
struct V_1 * V_2 = F_67 ( V_6 ) ;
F_10 ( V_2 , V_60 , V_100 ) ;
return 0 ;
}
static int F_68 ( struct V_103 * V_6 )
{
struct V_1 * V_2 = F_67 ( V_6 ) ;
F_6 ( V_2 , V_60 , V_100 | V_99 ) ;
return 0 ;
}
