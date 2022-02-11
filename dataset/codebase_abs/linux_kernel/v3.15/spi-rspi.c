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
V_9 = F_14 ( V_2 -> V_12 ) / ( 2 * V_2 -> V_13 ) - 1 ;
F_1 ( V_2 , F_15 ( V_9 , 0 , 255 ) , V_14 ) ;
F_1 ( V_2 , 0 , V_15 ) ;
V_2 -> V_6 = 0 ;
F_1 ( V_2 , 0x00 , V_16 ) ;
F_1 ( V_2 , 0x00 , V_17 ) ;
F_1 ( V_2 , 0x00 , V_18 ) ;
F_1 ( V_2 , 0x00 , V_19 ) ;
V_2 -> V_20 |= F_16 ( V_8 ) ;
F_3 ( V_2 , V_2 -> V_20 , V_21 ) ;
F_1 ( V_2 , V_22 , V_23 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_8 )
{
int V_9 ;
F_1 ( V_2 , V_2 -> V_10 , V_11 ) ;
V_9 = F_14 ( V_2 -> V_12 ) / ( 2 * V_2 -> V_13 ) - 1 ;
F_1 ( V_2 , F_15 ( V_9 , 0 , 255 ) , V_14 ) ;
F_1 ( V_2 , V_24 , V_15 ) ;
V_2 -> V_6 = 1 ;
F_1 ( V_2 , 0x00 , V_16 ) ;
F_1 ( V_2 , 0x00 , V_17 ) ;
F_1 ( V_2 , 0x00 , V_18 ) ;
V_2 -> V_20 |= F_16 ( V_8 ) ;
F_3 ( V_2 , V_2 -> V_20 , V_21 ) ;
F_1 ( V_2 , V_22 , V_23 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_8 )
{
int V_9 ;
F_1 ( V_2 , V_2 -> V_10 , V_11 ) ;
V_9 = F_14 ( V_2 -> V_12 ) / ( 2 * V_2 -> V_13 ) ;
F_1 ( V_2 , F_15 ( V_9 , 0 , 255 ) , V_14 ) ;
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
static void F_19 ( const struct V_1 * V_2 , T_1 V_36 )
{
F_1 ( V_2 , F_7 ( V_2 , V_23 ) | V_36 , V_23 ) ;
}
static void F_20 ( const struct V_1 * V_2 , T_1 V_37 )
{
F_1 ( V_2 , F_7 ( V_2 , V_23 ) & ~ V_37 , V_23 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_38 ,
T_1 V_39 )
{
int V_40 ;
V_2 -> V_41 = F_7 ( V_2 , V_42 ) ;
if ( V_2 -> V_41 & V_38 )
return 0 ;
F_19 ( V_2 , V_39 ) ;
V_40 = F_22 ( V_2 -> V_43 , V_2 -> V_41 & V_38 , V_44 ) ;
if ( V_40 == 0 && ! ( V_2 -> V_41 & V_38 ) )
return - V_45 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( F_21 ( V_2 , V_46 , V_47 ) < 0 ) {
F_24 ( & V_2 -> V_48 -> V_49 , L_1 ) ;
return - V_45 ;
}
F_11 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( F_21 ( V_2 , V_50 , V_51 ) < 0 ) {
F_24 ( & V_2 -> V_48 -> V_49 , L_2 ) ;
return - V_45 ;
}
V_3 = F_12 ( V_2 ) ;
return V_3 ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_40 ;
V_40 = F_23 ( V_2 , V_3 ) ;
if ( V_40 < 0 )
return V_40 ;
return F_25 ( V_2 ) ;
}
static void F_27 ( void * V_52 )
{
struct V_1 * V_2 = V_52 ;
V_2 -> V_53 = 1 ;
F_28 ( & V_2 -> V_43 ) ;
}
static int F_29 ( struct V_54 * V_55 , const void * V_56 ,
unsigned V_57 , struct V_58 * V_59 ,
enum V_60 V_61 )
{
F_30 ( V_55 , 1 ) ;
F_31 ( V_55 , V_56 , V_57 ) ;
F_32 ( V_55 ) = V_57 ;
return F_33 ( V_59 -> V_62 -> V_49 , V_55 , 1 , V_61 ) ;
}
static void F_34 ( struct V_54 * V_55 , struct V_58 * V_59 ,
enum V_60 V_61 )
{
F_35 ( V_59 -> V_62 -> V_49 , V_55 , 1 , V_61 ) ;
}
static void F_36 ( void * V_56 , const void * V_3 , unsigned V_57 )
{
T_2 * V_63 = V_56 ;
const T_1 * V_64 = V_3 ;
while ( V_57 ) {
* V_63 ++ = ( T_2 ) ( * V_64 ++ ) ;
V_57 -- ;
}
}
static void F_37 ( void * V_56 , const void * V_3 , unsigned V_57 )
{
T_1 * V_63 = V_56 ;
const T_2 * V_64 = V_3 ;
while ( V_57 ) {
* V_63 ++ = ( T_1 ) * V_64 ++ ;
V_57 -- ;
}
}
static int F_38 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
struct V_54 V_55 ;
const void * V_56 = NULL ;
struct V_67 * V_68 ;
unsigned int V_57 ;
int V_40 = 0 ;
if ( V_2 -> V_69 ) {
void * V_70 ;
V_57 = V_66 -> V_57 * 2 ;
V_70 = F_39 ( V_57 , V_71 ) ;
if ( ! V_70 )
return - V_72 ;
F_36 ( V_70 , V_66 -> V_73 , V_66 -> V_57 ) ;
V_56 = V_70 ;
} else {
V_57 = V_66 -> V_57 ;
V_56 = V_66 -> V_73 ;
}
if ( ! F_29 ( & V_55 , V_56 , V_57 , V_2 -> V_74 , V_75 ) ) {
V_40 = - V_76 ;
goto V_77;
}
V_68 = F_40 ( V_2 -> V_74 , & V_55 , 1 , V_75 ,
V_78 | V_79 ) ;
if ( ! V_68 ) {
V_40 = - V_80 ;
goto V_81;
}
F_41 ( V_2 -> V_82 ) ;
F_1 ( V_2 , F_7 ( V_2 , V_23 ) | V_83 , V_23 ) ;
F_19 ( V_2 , V_47 ) ;
V_2 -> V_53 = 0 ;
V_68 -> V_84 = F_27 ;
V_68 -> V_85 = V_2 ;
F_42 ( V_68 ) ;
F_43 ( V_2 -> V_74 ) ;
V_40 = F_44 ( V_2 -> V_43 ,
V_2 -> V_53 , V_44 ) ;
if ( V_40 > 0 && V_2 -> V_53 )
V_40 = 0 ;
else if ( ! V_40 )
V_40 = - V_45 ;
F_20 ( V_2 , V_47 ) ;
F_45 ( V_2 -> V_82 ) ;
V_81:
F_34 ( & V_55 , V_2 -> V_74 , V_75 ) ;
V_77:
if ( V_2 -> V_69 )
F_46 ( V_56 ) ;
return V_40 ;
}
static void F_47 ( const struct V_1 * V_2 )
{
T_1 V_41 ;
V_41 = F_7 ( V_2 , V_42 ) ;
if ( V_41 & V_50 )
F_12 ( V_2 ) ;
if ( V_41 & V_86 )
F_1 ( V_2 , F_7 ( V_2 , V_42 ) & ~ V_86 ,
V_42 ) ;
}
static void F_48 ( const struct V_1 * V_2 )
{
F_47 ( V_2 ) ;
F_1 ( V_2 , V_32 | V_33 , V_87 ) ;
F_1 ( V_2 , 0 , V_87 ) ;
}
static void F_49 ( const struct V_1 * V_2 )
{
T_1 V_41 ;
V_41 = F_7 ( V_2 , V_42 ) ;
if ( V_41 & V_50 )
F_12 ( V_2 ) ;
F_1 ( V_2 , V_32 | V_33 , V_34 ) ;
F_1 ( V_2 , 0 , V_34 ) ;
}
static int F_50 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
struct V_54 V_55 , V_88 ;
void * V_89 = NULL , * V_90 = NULL ;
struct V_67 * V_68 , * V_91 ;
unsigned int V_57 ;
int V_40 = 0 ;
if ( V_2 -> V_69 ) {
V_57 = V_66 -> V_57 * 2 ;
V_90 = F_39 ( V_57 , V_71 ) ;
if ( ! V_90 )
return - V_72 ;
} else {
V_57 = V_66 -> V_57 ;
V_90 = V_66 -> V_90 ;
}
V_89 = F_51 ( V_57 , V_71 ) ;
if ( ! V_89 ) {
V_40 = - V_72 ;
goto V_77;
}
if ( ! F_29 ( & V_88 , V_89 , V_57 , V_2 -> V_74 ,
V_75 ) ) {
V_40 = - V_76 ;
goto V_77;
}
V_91 = F_40 ( V_2 -> V_74 , & V_88 , 1 ,
V_75 , V_78 | V_79 ) ;
if ( ! V_91 ) {
V_40 = - V_80 ;
goto V_92;
}
if ( ! F_29 ( & V_55 , V_90 , V_57 , V_2 -> V_93 ,
V_94 ) ) {
V_40 = - V_76 ;
goto V_92;
}
V_68 = F_40 ( V_2 -> V_93 , & V_55 , 1 , V_94 ,
V_78 | V_79 ) ;
if ( ! V_68 ) {
V_40 = - V_80 ;
goto V_81;
}
F_47 ( V_2 ) ;
F_41 ( V_2 -> V_82 ) ;
if ( V_2 -> V_95 != V_2 -> V_82 )
F_41 ( V_2 -> V_95 ) ;
F_1 ( V_2 , F_7 ( V_2 , V_23 ) & ~ V_83 , V_23 ) ;
F_19 ( V_2 , V_47 | V_51 ) ;
V_2 -> V_53 = 0 ;
V_68 -> V_84 = F_27 ;
V_68 -> V_85 = V_2 ;
F_42 ( V_68 ) ;
F_43 ( V_2 -> V_93 ) ;
V_91 -> V_84 = NULL ;
F_42 ( V_91 ) ;
F_43 ( V_2 -> V_74 ) ;
V_40 = F_44 ( V_2 -> V_43 ,
V_2 -> V_53 , V_44 ) ;
if ( V_40 > 0 && V_2 -> V_53 )
V_40 = 0 ;
else if ( ! V_40 )
V_40 = - V_45 ;
F_20 ( V_2 , V_47 | V_51 ) ;
F_45 ( V_2 -> V_82 ) ;
if ( V_2 -> V_95 != V_2 -> V_82 )
F_45 ( V_2 -> V_95 ) ;
V_81:
F_34 ( & V_55 , V_2 -> V_93 , V_94 ) ;
V_92:
F_34 ( & V_88 , V_2 -> V_74 , V_75 ) ;
V_77:
if ( V_2 -> V_69 ) {
if ( ! V_40 )
F_37 ( V_66 -> V_90 , V_90 , V_66 -> V_57 ) ;
F_46 ( V_90 ) ;
}
F_46 ( V_89 ) ;
return V_40 ;
}
static int F_52 ( const struct V_1 * V_2 , struct V_65 * V_66 )
{
if ( V_66 -> V_73 && V_2 -> V_74 )
return 1 ;
if ( V_66 -> V_90 && V_2 -> V_74 && V_2 -> V_93 )
return 1 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_65 * V_96 )
{
int V_97 = V_96 -> V_57 , V_40 ;
const T_1 * V_73 = V_96 -> V_73 ;
T_1 * V_90 = V_96 -> V_90 ;
T_1 V_98 , V_3 ;
F_47 ( V_2 ) ;
V_98 = F_7 ( V_2 , V_23 ) ;
if ( V_90 )
V_98 &= ~ V_83 ;
else
V_98 |= V_83 ;
F_1 ( V_2 , V_98 , V_23 ) ;
while ( V_97 > 0 ) {
V_3 = V_73 ? * V_73 ++ : V_99 ;
V_40 = F_23 ( V_2 , V_3 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_90 ) {
V_40 = F_25 ( V_2 ) ;
if ( V_40 < 0 )
return V_40 ;
* V_90 ++ = V_40 ;
}
V_97 -- ;
}
F_21 ( V_2 , V_46 , V_47 ) ;
return 0 ;
}
static int F_54 ( struct V_100 * V_48 , struct V_101 * V_102 ,
struct V_65 * V_96 )
{
struct V_1 * V_2 = F_55 ( V_48 ) ;
int V_40 ;
if ( ! F_52 ( V_2 , V_96 ) )
return F_53 ( V_2 , V_96 ) ;
if ( V_96 -> V_73 ) {
V_40 = F_38 ( V_2 , V_96 ) ;
if ( V_40 < 0 )
return V_40 ;
}
if ( V_96 -> V_90 )
return F_50 ( V_2 , V_96 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_65 * V_96 )
{
int V_97 = V_96 -> V_57 , V_40 ;
const T_1 * V_73 = V_96 -> V_73 ;
T_1 * V_90 = V_96 -> V_90 ;
T_1 V_3 ;
F_48 ( V_2 ) ;
while ( V_97 > 0 ) {
V_3 = V_73 ? * V_73 ++ : V_99 ;
V_40 = F_26 ( V_2 , V_3 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_90 )
* V_90 ++ = V_40 ;
V_97 -- ;
}
F_21 ( V_2 , V_46 , V_47 ) ;
return 0 ;
}
static int F_57 ( struct V_100 * V_48 ,
struct V_101 * V_102 ,
struct V_65 * V_96 )
{
struct V_1 * V_2 = F_55 ( V_48 ) ;
return F_56 ( V_2 , V_96 ) ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_65 * V_96 )
{
int V_97 = V_96 -> V_57 , V_40 ;
const T_1 * V_73 = V_96 -> V_73 ;
T_1 * V_90 = V_96 -> V_90 ;
T_1 V_3 ;
F_49 ( V_2 ) ;
while ( V_97 > 0 ) {
V_3 = V_73 ? * V_73 ++ : V_99 ;
V_40 = F_26 ( V_2 , V_3 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_90 )
* V_90 ++ = V_40 ;
V_97 -- ;
}
F_21 ( V_2 , V_46 , V_47 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_65 * V_96 )
{
const T_1 * V_56 = V_96 -> V_73 ;
unsigned int V_103 ;
int V_40 ;
for ( V_103 = 0 ; V_103 < V_96 -> V_57 ; V_103 ++ ) {
V_40 = F_23 ( V_2 , * V_56 ++ ) ;
if ( V_40 < 0 )
return V_40 ;
}
F_21 ( V_2 , V_46 , V_47 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_65 * V_96 )
{
T_1 * V_56 = V_96 -> V_90 ;
unsigned int V_103 ;
int V_40 ;
for ( V_103 = 0 ; V_103 < V_96 -> V_57 ; V_103 ++ ) {
V_40 = F_25 ( V_2 ) ;
if ( V_40 < 0 )
return V_40 ;
* V_56 ++ = V_40 ;
}
return 0 ;
}
static int F_61 ( struct V_100 * V_48 , struct V_101 * V_102 ,
struct V_65 * V_96 )
{
struct V_1 * V_2 = F_55 ( V_48 ) ;
if ( V_102 -> V_104 & V_105 ) {
return F_58 ( V_2 , V_96 ) ;
} else if ( V_96 -> V_73 && V_96 -> V_106 > V_107 ) {
return F_59 ( V_2 , V_96 ) ;
} else if ( V_96 -> V_90 && V_96 -> V_108 > V_107 ) {
return F_60 ( V_2 , V_96 ) ;
} else {
return F_58 ( V_2 , V_96 ) ;
}
}
static int F_62 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = F_55 ( V_102 -> V_48 ) ;
V_2 -> V_13 = V_102 -> V_13 ;
V_2 -> V_20 = V_109 ;
if ( V_102 -> V_104 & V_110 )
V_2 -> V_20 |= V_111 ;
if ( V_102 -> V_104 & V_112 )
V_2 -> V_20 |= V_113 ;
V_2 -> V_10 = 0 ;
if ( V_102 -> V_104 & V_105 )
V_2 -> V_10 |= V_114 ;
F_63 ( V_2 , 8 ) ;
return 0 ;
}
static T_2 F_64 ( const struct V_65 * V_96 )
{
if ( V_96 -> V_73 )
switch ( V_96 -> V_106 ) {
case V_115 :
return V_116 ;
case V_117 :
return V_118 ;
default:
return 0 ;
}
if ( V_96 -> V_90 )
switch ( V_96 -> V_108 ) {
case V_115 :
return V_116 | V_119 ;
case V_117 :
return V_118 | V_119 ;
default:
return 0 ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
const struct V_120 * V_121 )
{
const struct V_65 * V_96 ;
unsigned int V_103 = 0 , V_57 = 0 ;
T_2 V_122 = 0xffff , V_104 ;
F_66 (xfer, &msg->transfers, transfer_list) {
V_104 = F_64 ( V_96 ) ;
if ( V_104 == V_122 ) {
V_57 += V_96 -> V_57 ;
continue;
}
if ( V_103 ) {
F_5 ( V_2 , V_57 , F_67 ( V_103 - 1 ) ) ;
}
if ( V_103 >= V_123 ) {
F_24 ( & V_121 -> V_102 -> V_49 ,
L_3 ) ;
return - V_124 ;
}
F_3 ( V_2 , V_2 -> V_20 | V_104 , F_68 ( V_103 ) ) ;
V_122 = V_104 ;
V_57 = V_96 -> V_57 ;
V_103 ++ ;
}
if ( V_103 ) {
F_5 ( V_2 , V_57 , F_67 ( V_103 - 1 ) ) ;
F_1 ( V_2 , V_103 - 1 , V_125 ) ;
}
return 0 ;
}
static int F_69 ( struct V_100 * V_48 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_55 ( V_48 ) ;
int V_40 ;
if ( V_121 -> V_102 -> V_104 &
( V_126 | V_127 | V_128 | V_129 ) ) {
V_40 = F_65 ( V_2 , V_121 ) ;
if ( V_40 < 0 )
return V_40 ;
}
F_1 ( V_2 , F_7 ( V_2 , V_23 ) | V_35 , V_23 ) ;
return 0 ;
}
static int F_70 ( struct V_100 * V_48 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_55 ( V_48 ) ;
F_1 ( V_2 , F_7 ( V_2 , V_23 ) & ~ V_35 , V_23 ) ;
F_3 ( V_2 , V_2 -> V_20 , V_21 ) ;
F_1 ( V_2 , 0 , V_125 ) ;
return 0 ;
}
static T_4 F_71 ( int V_130 , void * V_131 )
{
struct V_1 * V_2 = V_131 ;
T_1 V_41 ;
T_4 V_40 = V_132 ;
T_1 F_41 = 0 ;
V_2 -> V_41 = V_41 = F_7 ( V_2 , V_42 ) ;
if ( V_41 & V_50 )
F_41 |= V_51 ;
if ( V_41 & V_46 )
F_41 |= V_47 ;
if ( F_41 ) {
V_40 = V_133 ;
F_20 ( V_2 , F_41 ) ;
F_72 ( & V_2 -> V_43 ) ;
}
return V_40 ;
}
static T_4 F_73 ( int V_130 , void * V_131 )
{
struct V_1 * V_2 = V_131 ;
T_1 V_41 ;
V_2 -> V_41 = V_41 = F_7 ( V_2 , V_42 ) ;
if ( V_41 & V_50 ) {
F_20 ( V_2 , V_51 ) ;
F_72 ( & V_2 -> V_43 ) ;
return V_133 ;
}
return 0 ;
}
static T_4 F_74 ( int V_130 , void * V_131 )
{
struct V_1 * V_2 = V_131 ;
T_1 V_41 ;
V_2 -> V_41 = V_41 = F_7 ( V_2 , V_42 ) ;
if ( V_41 & V_46 ) {
F_20 ( V_2 , V_47 ) ;
F_72 ( & V_2 -> V_43 ) ;
return V_133 ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_134 * V_135 )
{
const struct V_136 * V_137 = F_76 ( & V_135 -> V_49 ) ;
struct V_138 * V_139 = F_77 ( V_135 , V_140 , 0 ) ;
T_5 V_141 ;
struct V_142 V_143 ;
int V_40 ;
if ( ! V_139 || ! V_137 )
return 0 ;
V_2 -> V_69 = V_137 -> V_69 ;
if ( V_137 -> V_144 && V_137 -> V_145 ) {
F_78 ( V_141 ) ;
F_79 ( V_146 , V_141 ) ;
V_2 -> V_93 = F_80 ( V_141 , V_147 ,
( void * ) V_137 -> V_144 ) ;
if ( V_2 -> V_93 ) {
V_143 . V_148 = V_137 -> V_144 ;
V_143 . V_149 = V_150 ;
V_143 . V_151 = 0 ;
V_143 . V_152 = V_139 -> V_153 + V_7 ;
V_40 = F_81 ( V_2 -> V_93 , & V_143 ) ;
if ( ! V_40 )
F_82 ( & V_135 -> V_49 , L_4 ) ;
else
return V_40 ;
}
}
if ( V_137 -> V_145 ) {
F_78 ( V_141 ) ;
F_79 ( V_146 , V_141 ) ;
V_2 -> V_74 = F_80 ( V_141 , V_147 ,
( void * ) V_137 -> V_145 ) ;
if ( V_2 -> V_74 ) {
V_143 . V_148 = V_137 -> V_145 ;
V_143 . V_149 = V_154 ;
V_143 . V_151 = V_139 -> V_153 + V_7 ;
V_143 . V_152 = 0 ;
V_40 = F_81 ( V_2 -> V_74 , & V_143 ) ;
if ( ! V_40 )
F_82 ( & V_135 -> V_49 , L_5 ) ;
else
return V_40 ;
}
}
return 0 ;
}
static void F_83 ( struct V_1 * V_2 )
{
if ( V_2 -> V_74 )
F_84 ( V_2 -> V_74 ) ;
if ( V_2 -> V_93 )
F_84 ( V_2 -> V_93 ) ;
}
static int F_85 ( struct V_134 * V_135 )
{
struct V_1 * V_2 = F_86 ( V_135 ) ;
F_83 ( V_2 ) ;
F_87 ( & V_135 -> V_49 ) ;
return 0 ;
}
static int F_88 ( struct V_62 * V_49 , struct V_100 * V_48 )
{
T_3 V_155 ;
int error ;
error = F_89 ( V_49 -> V_156 , L_6 , & V_155 ) ;
if ( error ) {
F_24 ( V_49 , L_7 , error ) ;
return error ;
}
V_48 -> V_157 = V_155 ;
return 0 ;
}
static inline int F_88 ( struct V_62 * V_49 , struct V_100 * V_48 )
{
return - V_124 ;
}
static int F_90 ( struct V_62 * V_49 , unsigned int V_130 ,
T_6 V_158 , const char * V_159 ,
void * V_160 )
{
const char * V_161 = F_91 ( V_49 ) ;
T_7 V_57 = strlen ( V_161 ) + strlen ( V_159 ) + 2 ;
char * V_162 = F_92 ( V_49 , V_57 , V_71 ) ;
if ( ! V_162 )
return - V_72 ;
snprintf ( V_162 , V_57 , L_8 , V_161 , V_159 ) ;
return F_93 ( V_49 , V_130 , V_158 , 0 , V_162 , V_160 ) ;
}
static int F_94 ( struct V_134 * V_135 )
{
struct V_138 * V_139 ;
struct V_100 * V_48 ;
struct V_1 * V_2 ;
int V_40 ;
const struct V_163 * V_164 ;
const struct V_136 * V_137 ;
const struct V_165 * V_166 ;
V_48 = F_95 ( & V_135 -> V_49 , sizeof( struct V_1 ) ) ;
if ( V_48 == NULL ) {
F_24 ( & V_135 -> V_49 , L_9 ) ;
return - V_72 ;
}
V_164 = F_96 ( V_167 , & V_135 -> V_49 ) ;
if ( V_164 ) {
V_166 = V_164 -> V_3 ;
V_40 = F_88 ( & V_135 -> V_49 , V_48 ) ;
if ( V_40 )
goto V_168;
} else {
V_166 = (struct V_165 * ) V_135 -> V_169 -> V_170 ;
V_137 = F_76 ( & V_135 -> V_49 ) ;
if ( V_137 && V_137 -> V_157 )
V_48 -> V_157 = V_137 -> V_157 ;
else
V_48 -> V_157 = 2 ;
} ;
if ( ! V_166 -> F_63 ) {
F_24 ( & V_135 -> V_49 , L_10 ) ;
V_40 = - V_171 ;
goto V_168;
}
V_2 = F_55 ( V_48 ) ;
F_97 ( V_135 , V_2 ) ;
V_2 -> V_166 = V_166 ;
V_2 -> V_48 = V_48 ;
V_139 = F_77 ( V_135 , V_140 , 0 ) ;
V_2 -> V_5 = F_98 ( & V_135 -> V_49 , V_139 ) ;
if ( F_99 ( V_2 -> V_5 ) ) {
V_40 = F_100 ( V_2 -> V_5 ) ;
goto V_168;
}
V_2 -> V_12 = F_101 ( & V_135 -> V_49 , NULL ) ;
if ( F_99 ( V_2 -> V_12 ) ) {
F_24 ( & V_135 -> V_49 , L_11 ) ;
V_40 = F_100 ( V_2 -> V_12 ) ;
goto V_168;
}
F_102 ( & V_135 -> V_49 ) ;
F_103 ( & V_2 -> V_43 ) ;
V_48 -> V_172 = V_135 -> V_173 ;
V_48 -> V_174 = F_62 ;
V_48 -> V_175 = true ;
V_48 -> V_176 = V_166 -> V_176 ;
V_48 -> V_177 = F_69 ;
V_48 -> V_178 = F_70 ;
V_48 -> V_179 = V_166 -> V_179 ;
V_48 -> V_49 . V_156 = V_135 -> V_49 . V_156 ;
V_40 = F_104 ( V_135 , L_12 ) ;
if ( V_40 < 0 ) {
V_40 = F_104 ( V_135 , L_13 ) ;
if ( V_40 < 0 )
V_40 = F_105 ( V_135 , 0 ) ;
if ( V_40 >= 0 )
V_2 -> V_95 = V_2 -> V_82 = V_40 ;
} else {
V_2 -> V_95 = V_40 ;
V_40 = F_104 ( V_135 , L_14 ) ;
if ( V_40 >= 0 )
V_2 -> V_82 = V_40 ;
}
if ( V_40 < 0 ) {
F_24 ( & V_135 -> V_49 , L_15 ) ;
goto V_180;
}
if ( V_2 -> V_95 == V_2 -> V_82 ) {
V_40 = F_90 ( & V_135 -> V_49 , V_2 -> V_95 , F_71 ,
L_13 , V_2 ) ;
} else {
V_40 = F_90 ( & V_135 -> V_49 , V_2 -> V_95 , F_73 ,
L_12 , V_2 ) ;
if ( ! V_40 )
V_40 = F_90 ( & V_135 -> V_49 , V_2 -> V_82 ,
F_74 , L_14 , V_2 ) ;
}
if ( V_40 < 0 ) {
F_24 ( & V_135 -> V_49 , L_16 ) ;
goto V_180;
}
V_40 = F_75 ( V_2 , V_135 ) ;
if ( V_40 < 0 ) {
F_24 ( & V_135 -> V_49 , L_17 ) ;
goto V_181;
}
V_40 = F_106 ( & V_135 -> V_49 , V_48 ) ;
if ( V_40 < 0 ) {
F_24 ( & V_135 -> V_49 , L_18 ) ;
goto V_181;
}
F_82 ( & V_135 -> V_49 , L_19 ) ;
return 0 ;
V_181:
F_83 ( V_2 ) ;
V_180:
F_87 ( & V_135 -> V_49 ) ;
V_168:
F_107 ( V_48 ) ;
return V_40 ;
}
