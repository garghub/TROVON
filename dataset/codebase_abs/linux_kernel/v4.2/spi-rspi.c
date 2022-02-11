static void F_1 ( const struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static void F_3 ( const struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
F_4 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static void F_5 ( const struct V_1 * V_2 , T_3 V_3 , T_2 V_4 )
{
F_6 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static T_1 F_7 ( const struct V_1 * V_2 , T_2 V_4 )
{
return F_8 ( V_2 -> V_5 + V_4 ) ;
}
static T_2 F_9 ( const struct V_1 * V_2 , T_2 V_4 )
{
return F_10 ( V_2 -> V_5 + V_4 ) ;
}
static void F_11 ( const struct V_1 * V_2 , T_2 V_3 )
{
if ( V_2 -> V_6 )
F_1 ( V_2 , V_3 , V_7 ) ;
else
F_3 ( V_2 , V_3 , V_7 ) ;
}
static T_2 F_12 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_6 )
return F_7 ( V_2 , V_7 ) ;
else
return F_9 ( V_2 , V_7 ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_8 )
{
int V_9 ;
F_1 ( V_2 , V_2 -> V_10 , V_11 ) ;
V_9 = F_14 ( F_15 ( V_2 -> V_12 ) ,
2 * V_2 -> V_13 ) - 1 ;
F_1 ( V_2 , F_16 ( V_9 , 0 , 255 ) , V_14 ) ;
F_1 ( V_2 , 0 , V_15 ) ;
V_2 -> V_6 = 0 ;
F_1 ( V_2 , 0x00 , V_16 ) ;
F_1 ( V_2 , 0x00 , V_17 ) ;
F_1 ( V_2 , 0x00 , V_18 ) ;
F_1 ( V_2 , 0x00 , V_19 ) ;
V_2 -> V_20 |= F_17 ( V_8 ) ;
F_3 ( V_2 , V_2 -> V_20 , V_21 ) ;
F_1 ( V_2 , V_22 , V_23 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_8 )
{
int V_9 ;
F_1 ( V_2 , V_2 -> V_10 , V_11 ) ;
V_9 = F_14 ( F_15 ( V_2 -> V_12 ) ,
2 * V_2 -> V_13 ) - 1 ;
F_1 ( V_2 , F_16 ( V_9 , 0 , 255 ) , V_14 ) ;
F_1 ( V_2 , V_24 , V_15 ) ;
V_2 -> V_6 = 1 ;
F_1 ( V_2 , 0x00 , V_16 ) ;
F_1 ( V_2 , 0x00 , V_17 ) ;
F_1 ( V_2 , 0x00 , V_18 ) ;
V_2 -> V_20 |= F_17 ( V_8 ) ;
F_3 ( V_2 , V_2 -> V_20 , V_21 ) ;
F_1 ( V_2 , V_22 , V_23 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_8 )
{
int V_9 ;
F_1 ( V_2 , V_2 -> V_10 , V_11 ) ;
V_9 = F_14 ( F_15 ( V_2 -> V_12 ) , 2 * V_2 -> V_13 ) ;
F_1 ( V_2 , F_16 ( V_9 , 0 , 255 ) , V_14 ) ;
F_1 ( V_2 , 0 , V_15 ) ;
V_2 -> V_6 = 1 ;
F_1 ( V_2 , 0x00 , V_16 ) ;
F_1 ( V_2 , 0x00 , V_17 ) ;
F_1 ( V_2 , 0x00 , V_18 ) ;
if ( V_8 == 8 )
V_2 -> V_20 |= V_25 ;
else if ( V_8 == 16 )
V_2 -> V_20 |= V_26 ;
else
V_2 -> V_20 |= V_27 ;
V_2 -> V_20 |= V_28 | V_29 | V_30 ;
F_5 ( V_2 , 0 , V_31 ) ;
F_1 ( V_2 , V_32 | V_33 , V_34 ) ;
F_1 ( V_2 , 0x00 , V_34 ) ;
F_3 ( V_2 , V_2 -> V_20 , V_21 ) ;
F_1 ( V_2 , V_35 | V_22 , V_23 ) ;
return 0 ;
}
static void F_20 ( const struct V_1 * V_2 , T_1 V_36 , T_1 V_37 , T_1 V_38 )
{
T_1 V_3 ;
V_3 = F_7 ( V_2 , V_38 ) ;
V_3 &= ~ V_36 ;
V_3 |= ( V_37 & V_36 ) ;
F_1 ( V_2 , V_3 , V_38 ) ;
}
static int F_21 ( struct V_1 * V_2 , unsigned int V_39 )
{
unsigned int V_40 ;
V_40 = F_22 ( V_39 , V_41 ) ;
if ( V_39 >= V_41 ) {
F_20 ( V_2 , V_42 ,
V_43 , V_34 ) ;
} else {
F_20 ( V_2 , V_42 ,
V_44 , V_34 ) ;
}
return V_40 ;
}
static void F_23 ( struct V_1 * V_2 , unsigned int V_39 )
{
unsigned int V_40 ;
V_40 = F_22 ( V_39 , V_41 ) ;
if ( V_39 >= V_41 ) {
F_20 ( V_2 , V_45 ,
V_46 , V_34 ) ;
} else {
F_20 ( V_2 , V_45 ,
V_47 , V_34 ) ;
}
}
static void F_24 ( const struct V_1 * V_2 , T_1 V_48 )
{
F_1 ( V_2 , F_7 ( V_2 , V_23 ) | V_48 , V_23 ) ;
}
static void F_25 ( const struct V_1 * V_2 , T_1 V_49 )
{
F_1 ( V_2 , F_7 ( V_2 , V_23 ) & ~ V_49 , V_23 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_50 ,
T_1 V_51 )
{
int V_52 ;
V_2 -> V_53 = F_7 ( V_2 , V_54 ) ;
if ( V_2 -> V_53 & V_50 )
return 0 ;
F_24 ( V_2 , V_51 ) ;
V_52 = F_27 ( V_2 -> V_55 , V_2 -> V_53 & V_50 , V_56 ) ;
if ( V_52 == 0 && ! ( V_2 -> V_53 & V_50 ) )
return - V_57 ;
return 0 ;
}
static inline int F_28 ( struct V_1 * V_2 )
{
return F_26 ( V_2 , V_58 , V_59 ) ;
}
static inline int F_29 ( struct V_1 * V_2 )
{
return F_26 ( V_2 , V_60 , V_61 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_3 )
{
int error = F_28 ( V_2 ) ;
if ( error < 0 ) {
F_31 ( & V_2 -> V_62 -> V_63 , L_1 ) ;
return error ;
}
F_11 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int error ;
T_1 V_3 ;
error = F_29 ( V_2 ) ;
if ( error < 0 ) {
F_31 ( & V_2 -> V_62 -> V_63 , L_2 ) ;
return error ;
}
V_3 = F_12 ( V_2 ) ;
return V_3 ;
}
static int F_33 ( struct V_1 * V_2 , const T_1 * V_64 , T_1 * V_65 ,
unsigned int V_40 )
{
while ( V_40 -- > 0 ) {
if ( V_64 ) {
int V_52 = F_30 ( V_2 , * V_64 ++ ) ;
if ( V_52 < 0 )
return V_52 ;
}
if ( V_65 ) {
int V_52 = F_32 ( V_2 ) ;
if ( V_52 < 0 )
return V_52 ;
* V_65 ++ = V_52 ;
}
}
return 0 ;
}
static void F_34 ( void * V_66 )
{
struct V_1 * V_2 = V_66 ;
V_2 -> V_67 = 1 ;
F_35 ( & V_2 -> V_55 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_68 * V_64 ,
struct V_68 * V_65 )
{
struct V_69 * V_70 = NULL , * V_71 = NULL ;
T_1 V_72 = 0 ;
unsigned int V_73 = 0 ;
T_4 V_74 ;
int V_52 ;
if ( V_65 ) {
V_71 = F_37 ( V_2 -> V_62 -> V_75 ,
V_65 -> V_76 , V_65 -> V_77 , V_78 ,
V_79 | V_80 ) ;
if ( ! V_71 ) {
V_52 = - V_81 ;
goto V_82;
}
V_71 -> V_83 = F_34 ;
V_71 -> V_84 = V_2 ;
V_74 = F_38 ( V_71 ) ;
if ( F_39 ( V_74 ) ) {
V_52 = V_74 ;
goto V_82;
}
V_72 |= V_61 ;
}
if ( V_64 ) {
V_70 = F_37 ( V_2 -> V_62 -> V_85 ,
V_64 -> V_76 , V_64 -> V_77 , V_86 ,
V_79 | V_80 ) ;
if ( ! V_70 ) {
V_52 = - V_81 ;
goto V_87;
}
if ( V_65 ) {
V_70 -> V_83 = NULL ;
} else {
V_70 -> V_83 = F_34 ;
V_70 -> V_84 = V_2 ;
}
V_74 = F_38 ( V_70 ) ;
if ( F_39 ( V_74 ) ) {
V_52 = V_74 ;
goto V_87;
}
V_72 |= V_59 ;
}
if ( V_64 )
F_40 ( V_73 = V_2 -> V_88 ) ;
if ( V_65 && V_2 -> V_89 != V_73 )
F_40 ( V_2 -> V_89 ) ;
F_24 ( V_2 , V_72 ) ;
V_2 -> V_67 = 0 ;
if ( V_65 )
F_41 ( V_2 -> V_62 -> V_75 ) ;
if ( V_64 )
F_41 ( V_2 -> V_62 -> V_85 ) ;
V_52 = F_42 ( V_2 -> V_55 ,
V_2 -> V_67 , V_56 ) ;
if ( V_52 > 0 && V_2 -> V_67 )
V_52 = 0 ;
else if ( ! V_52 ) {
F_31 ( & V_2 -> V_62 -> V_63 , L_3 ) ;
V_52 = - V_57 ;
if ( V_64 )
F_43 ( V_2 -> V_62 -> V_85 ) ;
if ( V_65 )
F_43 ( V_2 -> V_62 -> V_75 ) ;
}
F_25 ( V_2 , V_72 ) ;
if ( V_64 )
F_44 ( V_2 -> V_88 ) ;
if ( V_65 && V_2 -> V_89 != V_73 )
F_44 ( V_2 -> V_89 ) ;
return V_52 ;
V_87:
if ( V_65 )
F_43 ( V_2 -> V_62 -> V_75 ) ;
V_82:
if ( V_52 == - V_81 ) {
F_45 ( L_4 ,
F_46 ( & V_2 -> V_62 -> V_63 ) ,
F_47 ( & V_2 -> V_62 -> V_63 ) ) ;
}
return V_52 ;
}
static void F_48 ( const struct V_1 * V_2 )
{
T_1 V_53 ;
V_53 = F_7 ( V_2 , V_54 ) ;
if ( V_53 & V_60 )
F_12 ( V_2 ) ;
if ( V_53 & V_90 )
F_1 ( V_2 , F_7 ( V_2 , V_54 ) & ~ V_90 ,
V_54 ) ;
}
static void F_49 ( const struct V_1 * V_2 )
{
F_48 ( V_2 ) ;
F_1 ( V_2 , V_32 | V_33 , V_91 ) ;
F_1 ( V_2 , 0 , V_91 ) ;
}
static void F_50 ( const struct V_1 * V_2 )
{
T_1 V_53 ;
V_53 = F_7 ( V_2 , V_54 ) ;
if ( V_53 & V_60 )
F_12 ( V_2 ) ;
F_1 ( V_2 , V_32 | V_33 , V_34 ) ;
F_1 ( V_2 , 0 , V_34 ) ;
}
static bool F_51 ( const struct V_1 * V_2 ,
const struct V_92 * V_93 )
{
return V_93 -> V_39 > V_2 -> V_94 -> V_95 ;
}
static bool F_52 ( struct V_96 * V_62 , struct V_97 * V_98 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = F_53 ( V_62 ) ;
return F_51 ( V_2 , V_93 ) ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_92 * V_93 )
{
if ( ! V_2 -> V_62 -> V_99 || ! F_51 ( V_2 , V_93 ) )
return - V_81 ;
return F_36 ( V_2 , & V_93 -> V_100 ,
V_93 -> V_101 ? & V_93 -> V_102 : NULL ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_92 * V_93 )
{
int V_52 ;
V_52 = F_54 ( V_2 , V_93 ) ;
if ( V_52 != - V_81 )
return V_52 ;
V_52 = F_33 ( V_2 , V_93 -> V_103 , V_93 -> V_101 , V_93 -> V_39 ) ;
if ( V_52 < 0 )
return V_52 ;
F_28 ( V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_96 * V_62 , struct V_97 * V_98 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = F_53 ( V_62 ) ;
T_1 V_104 ;
V_104 = F_7 ( V_2 , V_23 ) ;
if ( V_93 -> V_101 ) {
F_48 ( V_2 ) ;
V_104 &= ~ V_105 ;
} else {
V_104 |= V_105 ;
}
F_1 ( V_2 , V_104 , V_23 ) ;
return F_55 ( V_2 , V_93 ) ;
}
static int F_57 ( struct V_96 * V_62 ,
struct V_97 * V_98 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = F_53 ( V_62 ) ;
F_49 ( V_2 ) ;
return F_55 ( V_2 , V_93 ) ;
}
static int F_58 ( struct V_1 * V_2 , const T_1 * V_64 ,
T_1 * V_65 , unsigned int V_39 )
{
int V_106 , V_40 , V_52 ;
int error ;
while ( V_39 > 0 ) {
V_40 = F_21 ( V_2 , V_39 ) ;
F_23 ( V_2 , V_39 ) ;
if ( V_40 == V_41 ) {
error = F_28 ( V_2 ) ;
if ( error < 0 ) {
F_31 ( & V_2 -> V_62 -> V_63 , L_1 ) ;
return error ;
}
for ( V_106 = 0 ; V_106 < V_40 ; V_106 ++ )
F_11 ( V_2 , * V_64 ++ ) ;
error = F_29 ( V_2 ) ;
if ( error < 0 ) {
F_31 ( & V_2 -> V_62 -> V_63 , L_2 ) ;
return error ;
}
for ( V_106 = 0 ; V_106 < V_40 ; V_106 ++ )
* V_65 ++ = F_12 ( V_2 ) ;
} else {
V_52 = F_33 ( V_2 , V_64 , V_65 , V_40 ) ;
if ( V_52 < 0 )
return V_52 ;
}
V_39 -= V_40 ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_92 * V_93 )
{
int V_52 ;
F_50 ( V_2 ) ;
V_52 = F_54 ( V_2 , V_93 ) ;
if ( V_52 != - V_81 )
return V_52 ;
return F_58 ( V_2 , V_93 -> V_103 ,
V_93 -> V_101 , V_93 -> V_39 ) ;
}
static int F_60 ( struct V_1 * V_2 , struct V_92 * V_93 )
{
int V_52 ;
if ( V_2 -> V_62 -> V_99 && F_51 ( V_2 , V_93 ) ) {
V_52 = F_36 ( V_2 , & V_93 -> V_100 , NULL ) ;
if ( V_52 != - V_81 )
return V_52 ;
}
V_52 = F_33 ( V_2 , V_93 -> V_103 , NULL , V_93 -> V_39 ) ;
if ( V_52 < 0 )
return V_52 ;
F_28 ( V_2 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_92 * V_93 )
{
if ( V_2 -> V_62 -> V_99 && F_51 ( V_2 , V_93 ) ) {
int V_52 = F_36 ( V_2 , NULL , & V_93 -> V_102 ) ;
if ( V_52 != - V_81 )
return V_52 ;
}
return F_33 ( V_2 , NULL , V_93 -> V_101 , V_93 -> V_39 ) ;
}
static int F_62 ( struct V_96 * V_62 , struct V_97 * V_98 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = F_53 ( V_62 ) ;
if ( V_98 -> V_107 & V_108 ) {
return F_59 ( V_2 , V_93 ) ;
} else if ( V_93 -> V_109 > V_110 ) {
return F_60 ( V_2 , V_93 ) ;
} else if ( V_93 -> V_111 > V_110 ) {
return F_61 ( V_2 , V_93 ) ;
} else {
return F_59 ( V_2 , V_93 ) ;
}
}
static int F_63 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_53 ( V_98 -> V_62 ) ;
V_2 -> V_13 = V_98 -> V_13 ;
V_2 -> V_20 = V_112 ;
if ( V_98 -> V_107 & V_113 )
V_2 -> V_20 |= V_114 ;
if ( V_98 -> V_107 & V_115 )
V_2 -> V_20 |= V_116 ;
V_2 -> V_10 = 0 ;
if ( V_98 -> V_107 & V_108 )
V_2 -> V_10 |= V_117 ;
F_64 ( V_2 , 8 ) ;
return 0 ;
}
static T_2 F_65 ( const struct V_92 * V_93 )
{
if ( V_93 -> V_103 )
switch ( V_93 -> V_109 ) {
case V_118 :
return V_119 ;
case V_120 :
return V_121 ;
default:
return 0 ;
}
if ( V_93 -> V_101 )
switch ( V_93 -> V_111 ) {
case V_118 :
return V_119 | V_122 ;
case V_120 :
return V_121 | V_122 ;
default:
return 0 ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
const struct V_123 * V_124 )
{
const struct V_92 * V_93 ;
unsigned int V_106 = 0 , V_39 = 0 ;
T_2 V_125 = 0xffff , V_107 ;
F_67 (xfer, &msg->transfers, transfer_list) {
V_107 = F_65 ( V_93 ) ;
if ( V_107 == V_125 ) {
V_39 += V_93 -> V_39 ;
continue;
}
if ( V_106 ) {
F_5 ( V_2 , V_39 , F_68 ( V_106 - 1 ) ) ;
}
if ( V_106 >= V_126 ) {
F_31 ( & V_124 -> V_98 -> V_63 ,
L_5 ) ;
return - V_127 ;
}
F_3 ( V_2 , V_2 -> V_20 | V_107 , F_69 ( V_106 ) ) ;
V_125 = V_107 ;
V_39 = V_93 -> V_39 ;
V_106 ++ ;
}
if ( V_106 ) {
F_5 ( V_2 , V_39 , F_68 ( V_106 - 1 ) ) ;
F_1 ( V_2 , V_106 - 1 , V_128 ) ;
}
return 0 ;
}
static int F_70 ( struct V_96 * V_62 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_53 ( V_62 ) ;
int V_52 ;
if ( V_124 -> V_98 -> V_107 &
( V_129 | V_130 | V_131 | V_132 ) ) {
V_52 = F_66 ( V_2 , V_124 ) ;
if ( V_52 < 0 )
return V_52 ;
}
F_1 ( V_2 , F_7 ( V_2 , V_23 ) | V_35 , V_23 ) ;
return 0 ;
}
static int F_71 ( struct V_96 * V_62 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_53 ( V_62 ) ;
F_1 ( V_2 , F_7 ( V_2 , V_23 ) & ~ V_35 , V_23 ) ;
F_3 ( V_2 , V_2 -> V_20 , V_21 ) ;
F_1 ( V_2 , 0 , V_128 ) ;
return 0 ;
}
static T_5 F_72 ( int V_133 , void * V_134 )
{
struct V_1 * V_2 = V_134 ;
T_1 V_53 ;
T_5 V_52 = V_135 ;
T_1 F_40 = 0 ;
V_2 -> V_53 = V_53 = F_7 ( V_2 , V_54 ) ;
if ( V_53 & V_60 )
F_40 |= V_61 ;
if ( V_53 & V_58 )
F_40 |= V_59 ;
if ( F_40 ) {
V_52 = V_136 ;
F_25 ( V_2 , F_40 ) ;
F_73 ( & V_2 -> V_55 ) ;
}
return V_52 ;
}
static T_5 F_74 ( int V_133 , void * V_134 )
{
struct V_1 * V_2 = V_134 ;
T_1 V_53 ;
V_2 -> V_53 = V_53 = F_7 ( V_2 , V_54 ) ;
if ( V_53 & V_60 ) {
F_25 ( V_2 , V_61 ) ;
F_73 ( & V_2 -> V_55 ) ;
return V_136 ;
}
return 0 ;
}
static T_5 F_75 ( int V_133 , void * V_134 )
{
struct V_1 * V_2 = V_134 ;
T_1 V_53 ;
V_2 -> V_53 = V_53 = F_7 ( V_2 , V_54 ) ;
if ( V_53 & V_58 ) {
F_25 ( V_2 , V_59 ) ;
F_73 ( & V_2 -> V_55 ) ;
return V_136 ;
}
return 0 ;
}
static struct V_137 * F_76 ( struct V_138 * V_63 ,
enum V_139 V_140 ,
unsigned int V_141 ,
T_6 V_142 )
{
T_7 V_36 ;
struct V_137 * V_143 ;
struct V_144 V_145 ;
int V_52 ;
F_77 ( V_36 ) ;
F_78 ( V_146 , V_36 ) ;
V_143 = F_79 ( V_36 , V_147 ,
( void * ) ( unsigned long ) V_141 , V_63 ,
V_140 == V_148 ? L_6 : L_7 ) ;
if ( ! V_143 ) {
F_80 ( V_63 , L_8 ) ;
return NULL ;
}
memset ( & V_145 , 0 , sizeof( V_145 ) ) ;
V_145 . V_149 = V_140 ;
if ( V_140 == V_148 ) {
V_145 . V_150 = V_142 ;
V_145 . V_151 = V_152 ;
} else {
V_145 . V_153 = V_142 ;
V_145 . V_154 = V_152 ;
}
V_52 = F_81 ( V_143 , & V_145 ) ;
if ( V_52 ) {
F_80 ( V_63 , L_9 , V_52 ) ;
F_82 ( V_143 ) ;
return NULL ;
}
return V_143 ;
}
static int F_83 ( struct V_138 * V_63 , struct V_96 * V_62 ,
const struct V_155 * V_156 )
{
const struct V_157 * V_158 = F_84 ( V_63 ) ;
unsigned int V_159 , V_160 ;
if ( V_63 -> V_161 ) {
V_159 = 0 ;
V_160 = 0 ;
} else if ( V_158 && V_158 -> V_159 && V_158 -> V_160 ) {
V_159 = V_158 -> V_159 ;
V_160 = V_158 -> V_160 ;
} else {
return 0 ;
}
V_62 -> V_85 = F_76 ( V_63 , V_148 , V_159 ,
V_156 -> V_162 + V_7 ) ;
if ( ! V_62 -> V_85 )
return - V_163 ;
V_62 -> V_75 = F_76 ( V_63 , V_164 , V_160 ,
V_156 -> V_162 + V_7 ) ;
if ( ! V_62 -> V_75 ) {
F_82 ( V_62 -> V_85 ) ;
V_62 -> V_85 = NULL ;
return - V_163 ;
}
V_62 -> V_99 = F_52 ;
F_85 ( V_63 , L_10 ) ;
return 0 ;
}
static void F_86 ( struct V_96 * V_62 )
{
if ( V_62 -> V_85 )
F_82 ( V_62 -> V_85 ) ;
if ( V_62 -> V_75 )
F_82 ( V_62 -> V_75 ) ;
}
static int F_87 ( struct V_165 * V_166 )
{
struct V_1 * V_2 = F_88 ( V_166 ) ;
F_86 ( V_2 -> V_62 ) ;
F_89 ( & V_166 -> V_63 ) ;
return 0 ;
}
static int F_90 ( struct V_138 * V_63 , struct V_96 * V_62 )
{
T_3 V_167 ;
int error ;
error = F_91 ( V_63 -> V_161 , L_11 , & V_167 ) ;
if ( error ) {
F_31 ( V_63 , L_12 , error ) ;
return error ;
}
V_62 -> V_168 = V_167 ;
return 0 ;
}
static inline int F_90 ( struct V_138 * V_63 , struct V_96 * V_62 )
{
return - V_127 ;
}
static int F_92 ( struct V_138 * V_63 , unsigned int V_133 ,
T_8 V_169 , const char * V_170 ,
void * V_171 )
{
const char * V_172 = F_93 ( V_63 , V_173 , L_13 ,
F_47 ( V_63 ) , V_170 ) ;
if ( ! V_172 )
return - V_174 ;
return F_94 ( V_63 , V_133 , V_169 , 0 , V_172 , V_171 ) ;
}
static int F_95 ( struct V_165 * V_166 )
{
struct V_155 * V_156 ;
struct V_96 * V_62 ;
struct V_1 * V_2 ;
int V_52 ;
const struct V_175 * V_176 ;
const struct V_157 * V_158 ;
const struct V_177 * V_94 ;
V_62 = F_96 ( & V_166 -> V_63 , sizeof( struct V_1 ) ) ;
if ( V_62 == NULL ) {
F_31 ( & V_166 -> V_63 , L_14 ) ;
return - V_174 ;
}
V_176 = F_97 ( V_178 , & V_166 -> V_63 ) ;
if ( V_176 ) {
V_94 = V_176 -> V_3 ;
V_52 = F_90 ( & V_166 -> V_63 , V_62 ) ;
if ( V_52 )
goto V_179;
} else {
V_94 = (struct V_177 * ) V_166 -> V_180 -> V_181 ;
V_158 = F_84 ( & V_166 -> V_63 ) ;
if ( V_158 && V_158 -> V_168 )
V_62 -> V_168 = V_158 -> V_168 ;
else
V_62 -> V_168 = 2 ;
}
if ( ! V_94 -> F_64 ) {
F_31 ( & V_166 -> V_63 , L_15 ) ;
V_52 = - V_163 ;
goto V_179;
}
V_2 = F_53 ( V_62 ) ;
F_98 ( V_166 , V_2 ) ;
V_2 -> V_94 = V_94 ;
V_2 -> V_62 = V_62 ;
V_156 = F_99 ( V_166 , V_182 , 0 ) ;
V_2 -> V_5 = F_100 ( & V_166 -> V_63 , V_156 ) ;
if ( F_101 ( V_2 -> V_5 ) ) {
V_52 = F_102 ( V_2 -> V_5 ) ;
goto V_179;
}
V_2 -> V_12 = F_103 ( & V_166 -> V_63 , NULL ) ;
if ( F_101 ( V_2 -> V_12 ) ) {
F_31 ( & V_166 -> V_63 , L_16 ) ;
V_52 = F_102 ( V_2 -> V_12 ) ;
goto V_179;
}
F_104 ( & V_166 -> V_63 ) ;
F_105 ( & V_2 -> V_55 ) ;
V_62 -> V_183 = V_166 -> V_141 ;
V_62 -> V_184 = F_63 ;
V_62 -> V_185 = true ;
V_62 -> V_186 = V_94 -> V_186 ;
V_62 -> V_187 = F_70 ;
V_62 -> V_188 = F_71 ;
V_62 -> V_189 = V_94 -> V_189 ;
V_62 -> V_190 = V_94 -> V_190 ;
V_62 -> V_63 . V_161 = V_166 -> V_63 . V_161 ;
V_52 = F_106 ( V_166 , L_7 ) ;
if ( V_52 < 0 ) {
V_52 = F_106 ( V_166 , L_17 ) ;
if ( V_52 < 0 )
V_52 = F_107 ( V_166 , 0 ) ;
if ( V_52 >= 0 )
V_2 -> V_89 = V_2 -> V_88 = V_52 ;
} else {
V_2 -> V_89 = V_52 ;
V_52 = F_106 ( V_166 , L_6 ) ;
if ( V_52 >= 0 )
V_2 -> V_88 = V_52 ;
}
if ( V_52 < 0 ) {
F_31 ( & V_166 -> V_63 , L_18 ) ;
goto V_191;
}
if ( V_2 -> V_89 == V_2 -> V_88 ) {
V_52 = F_92 ( & V_166 -> V_63 , V_2 -> V_89 , F_72 ,
L_17 , V_2 ) ;
} else {
V_52 = F_92 ( & V_166 -> V_63 , V_2 -> V_89 , F_74 ,
L_7 , V_2 ) ;
if ( ! V_52 )
V_52 = F_92 ( & V_166 -> V_63 , V_2 -> V_88 ,
F_75 , L_6 , V_2 ) ;
}
if ( V_52 < 0 ) {
F_31 ( & V_166 -> V_63 , L_19 ) ;
goto V_191;
}
V_52 = F_83 ( & V_166 -> V_63 , V_62 , V_156 ) ;
if ( V_52 < 0 )
F_80 ( & V_166 -> V_63 , L_20 ) ;
V_52 = F_108 ( & V_166 -> V_63 , V_62 ) ;
if ( V_52 < 0 ) {
F_31 ( & V_166 -> V_63 , L_21 ) ;
goto V_192;
}
F_85 ( & V_166 -> V_63 , L_22 ) ;
return 0 ;
V_192:
F_86 ( V_62 ) ;
V_191:
F_89 ( & V_166 -> V_63 ) ;
V_179:
F_109 ( V_62 ) ;
return V_52 ;
}
