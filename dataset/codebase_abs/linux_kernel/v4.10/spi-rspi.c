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
int div = 0 ;
unsigned long V_24 ;
F_1 ( V_2 , V_2 -> V_10 , V_11 ) ;
V_24 = F_15 ( V_2 -> V_12 ) ;
while ( div < 3 ) {
if ( V_2 -> V_13 >= V_24 / 4 )
break;
div ++ ;
V_24 /= 2 ;
}
V_9 = F_14 ( V_24 , 2 * V_2 -> V_13 ) - 1 ;
F_1 ( V_2 , F_16 ( V_9 , 0 , 255 ) , V_14 ) ;
V_2 -> V_20 |= div << 2 ;
F_1 ( V_2 , V_25 , V_15 ) ;
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
V_2 -> V_20 |= V_26 ;
else if ( V_8 == 16 )
V_2 -> V_20 |= V_27 ;
else
V_2 -> V_20 |= V_28 ;
V_2 -> V_20 |= V_29 | V_30 | V_31 ;
F_5 ( V_2 , 0 , V_32 ) ;
F_1 ( V_2 , V_33 | V_34 , V_35 ) ;
F_1 ( V_2 , 0x00 , V_35 ) ;
F_3 ( V_2 , V_2 -> V_20 , V_21 ) ;
F_1 ( V_2 , V_36 | V_22 , V_23 ) ;
return 0 ;
}
static void F_20 ( const struct V_1 * V_2 , T_1 V_37 , T_1 V_38 , T_1 V_39 )
{
T_1 V_3 ;
V_3 = F_7 ( V_2 , V_39 ) ;
V_3 &= ~ V_37 ;
V_3 |= ( V_38 & V_37 ) ;
F_1 ( V_2 , V_3 , V_39 ) ;
}
static unsigned int F_21 ( struct V_1 * V_2 ,
unsigned int V_40 )
{
unsigned int V_41 ;
V_41 = F_22 ( V_40 , V_42 ) ;
if ( V_40 >= V_42 ) {
F_20 ( V_2 , V_43 ,
V_44 , V_35 ) ;
} else {
F_20 ( V_2 , V_43 ,
V_45 , V_35 ) ;
}
return V_41 ;
}
static int F_23 ( struct V_1 * V_2 , unsigned int V_40 )
{
unsigned int V_41 ;
V_41 = F_22 ( V_40 , V_42 ) ;
if ( V_40 >= V_42 ) {
F_20 ( V_2 , V_46 ,
V_47 , V_35 ) ;
} else {
F_20 ( V_2 , V_46 ,
V_48 , V_35 ) ;
}
return V_41 ;
}
static void F_24 ( const struct V_1 * V_2 , T_1 V_49 )
{
F_1 ( V_2 , F_7 ( V_2 , V_23 ) | V_49 , V_23 ) ;
}
static void F_25 ( const struct V_1 * V_2 , T_1 V_50 )
{
F_1 ( V_2 , F_7 ( V_2 , V_23 ) & ~ V_50 , V_23 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_51 ,
T_1 V_52 )
{
int V_53 ;
V_2 -> V_54 = F_7 ( V_2 , V_55 ) ;
if ( V_2 -> V_54 & V_51 )
return 0 ;
F_24 ( V_2 , V_52 ) ;
V_53 = F_27 ( V_2 -> V_56 , V_2 -> V_54 & V_51 , V_57 ) ;
if ( V_53 == 0 && ! ( V_2 -> V_54 & V_51 ) )
return - V_58 ;
return 0 ;
}
static inline int F_28 ( struct V_1 * V_2 )
{
return F_26 ( V_2 , V_59 , V_60 ) ;
}
static inline int F_29 ( struct V_1 * V_2 )
{
return F_26 ( V_2 , V_61 , V_62 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_3 )
{
int error = F_28 ( V_2 ) ;
if ( error < 0 ) {
F_31 ( & V_2 -> V_63 -> V_64 , L_1 ) ;
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
F_31 ( & V_2 -> V_63 -> V_64 , L_2 ) ;
return error ;
}
V_3 = F_12 ( V_2 ) ;
return V_3 ;
}
static int F_33 ( struct V_1 * V_2 , const T_1 * V_65 , T_1 * V_66 ,
unsigned int V_41 )
{
while ( V_41 -- > 0 ) {
if ( V_65 ) {
int V_53 = F_30 ( V_2 , * V_65 ++ ) ;
if ( V_53 < 0 )
return V_53 ;
}
if ( V_66 ) {
int V_53 = F_32 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
* V_66 ++ = V_53 ;
}
}
return 0 ;
}
static void F_34 ( void * V_67 )
{
struct V_1 * V_2 = V_67 ;
V_2 -> V_68 = 1 ;
F_35 ( & V_2 -> V_56 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_69 * V_65 ,
struct V_69 * V_66 )
{
struct V_70 * V_71 = NULL , * V_72 = NULL ;
T_1 V_73 = 0 ;
unsigned int V_74 = 0 ;
T_4 V_75 ;
int V_53 ;
if ( V_66 ) {
V_72 = F_37 ( V_2 -> V_63 -> V_76 ,
V_66 -> V_77 , V_66 -> V_78 , V_79 ,
V_80 | V_81 ) ;
if ( ! V_72 ) {
V_53 = - V_82 ;
goto V_83;
}
V_72 -> V_84 = F_34 ;
V_72 -> V_85 = V_2 ;
V_75 = F_38 ( V_72 ) ;
if ( F_39 ( V_75 ) ) {
V_53 = V_75 ;
goto V_83;
}
V_73 |= V_62 ;
}
if ( V_65 ) {
V_71 = F_37 ( V_2 -> V_63 -> V_86 ,
V_65 -> V_77 , V_65 -> V_78 , V_87 ,
V_80 | V_81 ) ;
if ( ! V_71 ) {
V_53 = - V_82 ;
goto V_88;
}
if ( V_66 ) {
V_71 -> V_84 = NULL ;
} else {
V_71 -> V_84 = F_34 ;
V_71 -> V_85 = V_2 ;
}
V_75 = F_38 ( V_71 ) ;
if ( F_39 ( V_75 ) ) {
V_53 = V_75 ;
goto V_88;
}
V_73 |= V_60 ;
}
if ( V_65 )
F_40 ( V_74 = V_2 -> V_89 ) ;
if ( V_66 && V_2 -> V_90 != V_74 )
F_40 ( V_2 -> V_90 ) ;
F_24 ( V_2 , V_73 ) ;
V_2 -> V_68 = 0 ;
if ( V_66 )
F_41 ( V_2 -> V_63 -> V_76 ) ;
if ( V_65 )
F_41 ( V_2 -> V_63 -> V_86 ) ;
V_53 = F_42 ( V_2 -> V_56 ,
V_2 -> V_68 , V_57 ) ;
if ( V_53 > 0 && V_2 -> V_68 )
V_53 = 0 ;
else if ( ! V_53 ) {
F_31 ( & V_2 -> V_63 -> V_64 , L_3 ) ;
V_53 = - V_58 ;
if ( V_65 )
F_43 ( V_2 -> V_63 -> V_86 ) ;
if ( V_66 )
F_43 ( V_2 -> V_63 -> V_76 ) ;
}
F_25 ( V_2 , V_73 ) ;
if ( V_65 )
F_44 ( V_2 -> V_89 ) ;
if ( V_66 && V_2 -> V_90 != V_74 )
F_44 ( V_2 -> V_90 ) ;
return V_53 ;
V_88:
if ( V_66 )
F_43 ( V_2 -> V_63 -> V_76 ) ;
V_83:
if ( V_53 == - V_82 ) {
F_45 ( L_4 ,
F_46 ( & V_2 -> V_63 -> V_64 ) ,
F_47 ( & V_2 -> V_63 -> V_64 ) ) ;
}
return V_53 ;
}
static void F_48 ( const struct V_1 * V_2 )
{
T_1 V_54 ;
V_54 = F_7 ( V_2 , V_55 ) ;
if ( V_54 & V_61 )
F_12 ( V_2 ) ;
if ( V_54 & V_91 )
F_1 ( V_2 , F_7 ( V_2 , V_55 ) & ~ V_91 ,
V_55 ) ;
}
static void F_49 ( const struct V_1 * V_2 )
{
F_48 ( V_2 ) ;
F_1 ( V_2 , V_33 | V_34 , V_92 ) ;
F_1 ( V_2 , 0 , V_92 ) ;
}
static void F_50 ( const struct V_1 * V_2 )
{
T_1 V_54 ;
V_54 = F_7 ( V_2 , V_55 ) ;
if ( V_54 & V_61 )
F_12 ( V_2 ) ;
F_1 ( V_2 , V_33 | V_34 , V_35 ) ;
F_1 ( V_2 , 0 , V_35 ) ;
}
static bool F_51 ( const struct V_1 * V_2 ,
const struct V_93 * V_94 )
{
return V_94 -> V_40 > V_2 -> V_95 -> V_96 ;
}
static bool F_52 ( struct V_97 * V_63 , struct V_98 * V_99 ,
struct V_93 * V_94 )
{
struct V_1 * V_2 = F_53 ( V_63 ) ;
return F_51 ( V_2 , V_94 ) ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
if ( ! V_2 -> V_63 -> V_100 || ! F_51 ( V_2 , V_94 ) )
return - V_82 ;
return F_36 ( V_2 , & V_94 -> V_101 ,
V_94 -> V_102 ? & V_94 -> V_103 : NULL ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
int V_53 ;
V_53 = F_54 ( V_2 , V_94 ) ;
if ( V_53 != - V_82 )
return V_53 ;
V_53 = F_33 ( V_2 , V_94 -> V_104 , V_94 -> V_102 , V_94 -> V_40 ) ;
if ( V_53 < 0 )
return V_53 ;
F_28 ( V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_97 * V_63 , struct V_98 * V_99 ,
struct V_93 * V_94 )
{
struct V_1 * V_2 = F_53 ( V_63 ) ;
T_1 V_105 ;
V_105 = F_7 ( V_2 , V_23 ) ;
if ( V_94 -> V_102 ) {
F_48 ( V_2 ) ;
V_105 &= ~ V_106 ;
} else {
V_105 |= V_106 ;
}
F_1 ( V_2 , V_105 , V_23 ) ;
return F_55 ( V_2 , V_94 ) ;
}
static int F_57 ( struct V_97 * V_63 ,
struct V_98 * V_99 ,
struct V_93 * V_94 )
{
struct V_1 * V_2 = F_53 ( V_63 ) ;
F_49 ( V_2 ) ;
return F_55 ( V_2 , V_94 ) ;
}
static int F_58 ( struct V_1 * V_2 , const T_1 * V_65 ,
T_1 * V_66 , unsigned int V_40 )
{
unsigned int V_107 , V_41 ;
int V_53 ;
while ( V_40 > 0 ) {
V_41 = F_21 ( V_2 , V_40 ) ;
F_23 ( V_2 , V_40 ) ;
if ( V_41 == V_42 ) {
V_53 = F_28 ( V_2 ) ;
if ( V_53 < 0 ) {
F_31 ( & V_2 -> V_63 -> V_64 , L_1 ) ;
return V_53 ;
}
for ( V_107 = 0 ; V_107 < V_41 ; V_107 ++ )
F_11 ( V_2 , * V_65 ++ ) ;
V_53 = F_29 ( V_2 ) ;
if ( V_53 < 0 ) {
F_31 ( & V_2 -> V_63 -> V_64 , L_2 ) ;
return V_53 ;
}
for ( V_107 = 0 ; V_107 < V_41 ; V_107 ++ )
* V_66 ++ = F_12 ( V_2 ) ;
} else {
V_53 = F_33 ( V_2 , V_65 , V_66 , V_41 ) ;
if ( V_53 < 0 )
return V_53 ;
}
V_40 -= V_41 ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
int V_53 ;
F_50 ( V_2 ) ;
V_53 = F_54 ( V_2 , V_94 ) ;
if ( V_53 != - V_82 )
return V_53 ;
return F_58 ( V_2 , V_94 -> V_104 ,
V_94 -> V_102 , V_94 -> V_40 ) ;
}
static int F_60 ( struct V_1 * V_2 , struct V_93 * V_94 )
{
const T_1 * V_65 = V_94 -> V_104 ;
unsigned int V_41 = V_94 -> V_40 ;
unsigned int V_107 , V_40 ;
int V_53 ;
if ( V_2 -> V_63 -> V_100 && F_51 ( V_2 , V_94 ) ) {
V_53 = F_36 ( V_2 , & V_94 -> V_101 , NULL ) ;
if ( V_53 != - V_82 )
return V_53 ;
}
while ( V_41 > 0 ) {
V_40 = F_21 ( V_2 , V_41 ) ;
if ( V_40 == V_42 ) {
V_53 = F_28 ( V_2 ) ;
if ( V_53 < 0 ) {
F_31 ( & V_2 -> V_63 -> V_64 , L_1 ) ;
return V_53 ;
}
for ( V_107 = 0 ; V_107 < V_40 ; V_107 ++ )
F_11 ( V_2 , * V_65 ++ ) ;
} else {
V_53 = F_33 ( V_2 , V_65 , NULL , V_41 ) ;
if ( V_53 < 0 )
return V_53 ;
}
V_41 -= V_40 ;
}
F_28 ( V_2 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_93 * V_94 )
{
T_1 * V_66 = V_94 -> V_102 ;
unsigned int V_41 = V_94 -> V_40 ;
unsigned int V_107 , V_40 ;
int V_53 ;
if ( V_2 -> V_63 -> V_100 && F_51 ( V_2 , V_94 ) ) {
int V_53 = F_36 ( V_2 , NULL , & V_94 -> V_103 ) ;
if ( V_53 != - V_82 )
return V_53 ;
}
while ( V_41 > 0 ) {
V_40 = F_23 ( V_2 , V_41 ) ;
if ( V_40 == V_42 ) {
V_53 = F_29 ( V_2 ) ;
if ( V_53 < 0 ) {
F_31 ( & V_2 -> V_63 -> V_64 , L_2 ) ;
return V_53 ;
}
for ( V_107 = 0 ; V_107 < V_40 ; V_107 ++ )
* V_66 ++ = F_12 ( V_2 ) ;
} else {
V_53 = F_33 ( V_2 , NULL , V_66 , V_41 ) ;
if ( V_53 < 0 )
return V_53 ;
* V_66 ++ = V_53 ;
}
V_41 -= V_40 ;
}
return 0 ;
}
static int F_62 ( struct V_97 * V_63 , struct V_98 * V_99 ,
struct V_93 * V_94 )
{
struct V_1 * V_2 = F_53 ( V_63 ) ;
if ( V_99 -> V_108 & V_109 ) {
return F_59 ( V_2 , V_94 ) ;
} else if ( V_94 -> V_110 > V_111 ) {
return F_60 ( V_2 , V_94 ) ;
} else if ( V_94 -> V_112 > V_111 ) {
return F_61 ( V_2 , V_94 ) ;
} else {
return F_59 ( V_2 , V_94 ) ;
}
}
static int F_63 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = F_53 ( V_99 -> V_63 ) ;
V_2 -> V_13 = V_99 -> V_13 ;
V_2 -> V_20 = V_113 ;
if ( V_99 -> V_108 & V_114 )
V_2 -> V_20 |= V_115 ;
if ( V_99 -> V_108 & V_116 )
V_2 -> V_20 |= V_117 ;
V_2 -> V_10 = 0 ;
if ( V_99 -> V_108 & V_109 )
V_2 -> V_10 |= V_118 ;
F_64 ( V_2 , 8 ) ;
return 0 ;
}
static T_2 F_65 ( const struct V_93 * V_94 )
{
if ( V_94 -> V_104 )
switch ( V_94 -> V_110 ) {
case V_119 :
return V_120 ;
case V_121 :
return V_122 ;
default:
return 0 ;
}
if ( V_94 -> V_102 )
switch ( V_94 -> V_112 ) {
case V_119 :
return V_120 | V_123 ;
case V_121 :
return V_122 | V_123 ;
default:
return 0 ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
const struct V_124 * V_125 )
{
const struct V_93 * V_94 ;
unsigned int V_107 = 0 , V_40 = 0 ;
T_2 V_126 = 0xffff , V_108 ;
F_67 (xfer, &msg->transfers, transfer_list) {
V_108 = F_65 ( V_94 ) ;
if ( V_108 == V_126 ) {
V_40 += V_94 -> V_40 ;
continue;
}
if ( V_107 ) {
F_5 ( V_2 , V_40 , F_68 ( V_107 - 1 ) ) ;
}
if ( V_107 >= V_127 ) {
F_31 ( & V_125 -> V_99 -> V_64 ,
L_5 ) ;
return - V_128 ;
}
F_3 ( V_2 , V_2 -> V_20 | V_108 , F_69 ( V_107 ) ) ;
V_126 = V_108 ;
V_40 = V_94 -> V_40 ;
V_107 ++ ;
}
if ( V_107 ) {
F_5 ( V_2 , V_40 , F_68 ( V_107 - 1 ) ) ;
F_1 ( V_2 , V_107 - 1 , V_129 ) ;
}
return 0 ;
}
static int F_70 ( struct V_97 * V_63 ,
struct V_124 * V_125 )
{
struct V_1 * V_2 = F_53 ( V_63 ) ;
int V_53 ;
if ( V_125 -> V_99 -> V_108 &
( V_130 | V_131 | V_132 | V_133 ) ) {
V_53 = F_66 ( V_2 , V_125 ) ;
if ( V_53 < 0 )
return V_53 ;
}
F_1 ( V_2 , F_7 ( V_2 , V_23 ) | V_36 , V_23 ) ;
return 0 ;
}
static int F_71 ( struct V_97 * V_63 ,
struct V_124 * V_125 )
{
struct V_1 * V_2 = F_53 ( V_63 ) ;
F_1 ( V_2 , F_7 ( V_2 , V_23 ) & ~ V_36 , V_23 ) ;
F_3 ( V_2 , V_2 -> V_20 , V_21 ) ;
F_1 ( V_2 , 0 , V_129 ) ;
return 0 ;
}
static T_5 F_72 ( int V_134 , void * V_135 )
{
struct V_1 * V_2 = V_135 ;
T_1 V_54 ;
T_5 V_53 = V_136 ;
T_1 F_40 = 0 ;
V_2 -> V_54 = V_54 = F_7 ( V_2 , V_55 ) ;
if ( V_54 & V_61 )
F_40 |= V_62 ;
if ( V_54 & V_59 )
F_40 |= V_60 ;
if ( F_40 ) {
V_53 = V_137 ;
F_25 ( V_2 , F_40 ) ;
F_73 ( & V_2 -> V_56 ) ;
}
return V_53 ;
}
static T_5 F_74 ( int V_134 , void * V_135 )
{
struct V_1 * V_2 = V_135 ;
T_1 V_54 ;
V_2 -> V_54 = V_54 = F_7 ( V_2 , V_55 ) ;
if ( V_54 & V_61 ) {
F_25 ( V_2 , V_62 ) ;
F_73 ( & V_2 -> V_56 ) ;
return V_137 ;
}
return 0 ;
}
static T_5 F_75 ( int V_134 , void * V_135 )
{
struct V_1 * V_2 = V_135 ;
T_1 V_54 ;
V_2 -> V_54 = V_54 = F_7 ( V_2 , V_55 ) ;
if ( V_54 & V_59 ) {
F_25 ( V_2 , V_60 ) ;
F_73 ( & V_2 -> V_56 ) ;
return V_137 ;
}
return 0 ;
}
static struct V_138 * F_76 ( struct V_139 * V_64 ,
enum V_140 V_141 ,
unsigned int V_142 ,
T_6 V_143 )
{
T_7 V_37 ;
struct V_138 * V_144 ;
struct V_145 V_146 ;
int V_53 ;
F_77 ( V_37 ) ;
F_78 ( V_147 , V_37 ) ;
V_144 = F_79 ( V_37 , V_148 ,
( void * ) ( unsigned long ) V_142 , V_64 ,
V_141 == V_149 ? L_6 : L_7 ) ;
if ( ! V_144 ) {
F_80 ( V_64 , L_8 ) ;
return NULL ;
}
memset ( & V_146 , 0 , sizeof( V_146 ) ) ;
V_146 . V_150 = V_141 ;
if ( V_141 == V_149 ) {
V_146 . V_151 = V_143 ;
V_146 . V_152 = V_153 ;
} else {
V_146 . V_154 = V_143 ;
V_146 . V_155 = V_153 ;
}
V_53 = F_81 ( V_144 , & V_146 ) ;
if ( V_53 ) {
F_80 ( V_64 , L_9 , V_53 ) ;
F_82 ( V_144 ) ;
return NULL ;
}
return V_144 ;
}
static int F_83 ( struct V_139 * V_64 , struct V_97 * V_63 ,
const struct V_156 * V_157 )
{
const struct V_158 * V_159 = F_84 ( V_64 ) ;
unsigned int V_160 , V_161 ;
if ( V_64 -> V_162 ) {
V_160 = 0 ;
V_161 = 0 ;
} else if ( V_159 && V_159 -> V_160 && V_159 -> V_161 ) {
V_160 = V_159 -> V_160 ;
V_161 = V_159 -> V_161 ;
} else {
return 0 ;
}
V_63 -> V_86 = F_76 ( V_64 , V_149 , V_160 ,
V_157 -> V_163 + V_7 ) ;
if ( ! V_63 -> V_86 )
return - V_164 ;
V_63 -> V_76 = F_76 ( V_64 , V_165 , V_161 ,
V_157 -> V_163 + V_7 ) ;
if ( ! V_63 -> V_76 ) {
F_82 ( V_63 -> V_86 ) ;
V_63 -> V_86 = NULL ;
return - V_164 ;
}
V_63 -> V_100 = F_52 ;
F_85 ( V_64 , L_10 ) ;
return 0 ;
}
static void F_86 ( struct V_97 * V_63 )
{
if ( V_63 -> V_86 )
F_82 ( V_63 -> V_86 ) ;
if ( V_63 -> V_76 )
F_82 ( V_63 -> V_76 ) ;
}
static int F_87 ( struct V_166 * V_167 )
{
struct V_1 * V_2 = F_88 ( V_167 ) ;
F_86 ( V_2 -> V_63 ) ;
F_89 ( & V_167 -> V_64 ) ;
return 0 ;
}
static int F_90 ( struct V_139 * V_64 , struct V_97 * V_63 )
{
T_3 V_168 ;
int error ;
error = F_91 ( V_64 -> V_162 , L_11 , & V_168 ) ;
if ( error ) {
F_31 ( V_64 , L_12 , error ) ;
return error ;
}
V_63 -> V_169 = V_168 ;
return 0 ;
}
static inline int F_90 ( struct V_139 * V_64 , struct V_97 * V_63 )
{
return - V_128 ;
}
static int F_92 ( struct V_139 * V_64 , unsigned int V_134 ,
T_8 V_170 , const char * V_171 ,
void * V_172 )
{
const char * V_173 = F_93 ( V_64 , V_174 , L_13 ,
F_47 ( V_64 ) , V_171 ) ;
if ( ! V_173 )
return - V_175 ;
return F_94 ( V_64 , V_134 , V_170 , 0 , V_173 , V_172 ) ;
}
static int F_95 ( struct V_166 * V_167 )
{
struct V_156 * V_157 ;
struct V_97 * V_63 ;
struct V_1 * V_2 ;
int V_53 ;
const struct V_176 * V_177 ;
const struct V_158 * V_159 ;
const struct V_178 * V_95 ;
V_63 = F_96 ( & V_167 -> V_64 , sizeof( struct V_1 ) ) ;
if ( V_63 == NULL ) {
F_31 ( & V_167 -> V_64 , L_14 ) ;
return - V_175 ;
}
V_177 = F_97 ( V_179 , & V_167 -> V_64 ) ;
if ( V_177 ) {
V_95 = V_177 -> V_3 ;
V_53 = F_90 ( & V_167 -> V_64 , V_63 ) ;
if ( V_53 )
goto V_180;
} else {
V_95 = (struct V_178 * ) V_167 -> V_181 -> V_182 ;
V_159 = F_84 ( & V_167 -> V_64 ) ;
if ( V_159 && V_159 -> V_169 )
V_63 -> V_169 = V_159 -> V_169 ;
else
V_63 -> V_169 = 2 ;
}
if ( ! V_95 -> F_64 ) {
F_31 ( & V_167 -> V_64 , L_15 ) ;
V_53 = - V_164 ;
goto V_180;
}
V_2 = F_53 ( V_63 ) ;
F_98 ( V_167 , V_2 ) ;
V_2 -> V_95 = V_95 ;
V_2 -> V_63 = V_63 ;
V_157 = F_99 ( V_167 , V_183 , 0 ) ;
V_2 -> V_5 = F_100 ( & V_167 -> V_64 , V_157 ) ;
if ( F_101 ( V_2 -> V_5 ) ) {
V_53 = F_102 ( V_2 -> V_5 ) ;
goto V_180;
}
V_2 -> V_12 = F_103 ( & V_167 -> V_64 , NULL ) ;
if ( F_101 ( V_2 -> V_12 ) ) {
F_31 ( & V_167 -> V_64 , L_16 ) ;
V_53 = F_102 ( V_2 -> V_12 ) ;
goto V_180;
}
F_104 ( & V_167 -> V_64 ) ;
F_105 ( & V_2 -> V_56 ) ;
V_63 -> V_184 = V_167 -> V_142 ;
V_63 -> V_185 = F_63 ;
V_63 -> V_186 = true ;
V_63 -> V_187 = V_95 -> V_187 ;
V_63 -> V_188 = F_70 ;
V_63 -> V_189 = F_71 ;
V_63 -> V_190 = V_95 -> V_190 ;
V_63 -> V_191 = V_95 -> V_191 ;
V_63 -> V_64 . V_162 = V_167 -> V_64 . V_162 ;
V_53 = F_106 ( V_167 , L_7 ) ;
if ( V_53 < 0 ) {
V_53 = F_106 ( V_167 , L_17 ) ;
if ( V_53 < 0 )
V_53 = F_107 ( V_167 , 0 ) ;
if ( V_53 >= 0 )
V_2 -> V_90 = V_2 -> V_89 = V_53 ;
} else {
V_2 -> V_90 = V_53 ;
V_53 = F_106 ( V_167 , L_6 ) ;
if ( V_53 >= 0 )
V_2 -> V_89 = V_53 ;
}
if ( V_53 < 0 ) {
F_31 ( & V_167 -> V_64 , L_18 ) ;
goto V_192;
}
if ( V_2 -> V_90 == V_2 -> V_89 ) {
V_53 = F_92 ( & V_167 -> V_64 , V_2 -> V_90 , F_72 ,
L_17 , V_2 ) ;
} else {
V_53 = F_92 ( & V_167 -> V_64 , V_2 -> V_90 , F_74 ,
L_7 , V_2 ) ;
if ( ! V_53 )
V_53 = F_92 ( & V_167 -> V_64 , V_2 -> V_89 ,
F_75 , L_6 , V_2 ) ;
}
if ( V_53 < 0 ) {
F_31 ( & V_167 -> V_64 , L_19 ) ;
goto V_192;
}
V_53 = F_83 ( & V_167 -> V_64 , V_63 , V_157 ) ;
if ( V_53 < 0 )
F_80 ( & V_167 -> V_64 , L_20 ) ;
V_53 = F_108 ( & V_167 -> V_64 , V_63 ) ;
if ( V_53 < 0 ) {
F_31 ( & V_167 -> V_64 , L_21 ) ;
goto V_193;
}
F_85 ( & V_167 -> V_64 , L_22 ) ;
return 0 ;
V_193:
F_86 ( V_63 ) ;
V_192:
F_89 ( & V_167 -> V_64 ) ;
V_180:
F_109 ( V_63 ) ;
return V_53 ;
}
