static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 ,
struct V_5 * V_8 ,
struct V_5 * V_9 ,
struct V_5 * V_10 )
{
switch ( V_7 -> V_11 ) {
case V_12 :
return V_10 ;
case V_13 :
return V_9 ;
default:
return V_8 ;
}
}
static struct V_14 *
F_4 ( struct V_15 * V_16 , unsigned V_17 , T_1 V_18 )
{
struct V_14 * V_19 ;
V_19 = F_5 ( V_16 , V_18 ) ;
if ( V_19 != NULL ) {
V_19 -> V_20 = V_17 ;
V_19 -> V_21 = F_6 ( V_17 , V_18 ) ;
if ( V_19 -> V_21 == NULL ) {
F_7 ( V_16 , V_19 ) ;
return NULL ;
}
}
return V_19 ;
}
static void
F_8 ( struct V_15 * V_16 , struct V_14 * V_19 )
{
if ( V_16 != NULL && V_19 != NULL ) {
F_9 ( V_19 -> V_21 ) ;
F_7 ( V_16 , V_19 ) ;
}
}
static void F_10 ( struct V_15 * V_16 , struct V_14 * V_19 )
{
struct V_1 * V_22 = V_16 -> V_23 ;
int V_24 = V_19 -> V_24 ;
unsigned long V_25 ;
F_11 ( & V_22 -> V_26 , V_25 ) ;
F_12 ( & V_19 -> V_27 ) ;
switch ( V_24 ) {
case 0 :
if ( V_19 -> V_28 > 0 ) {
F_13 ( & V_19 -> V_27 , & V_22 -> V_29 ) ;
F_14 ( V_22 , L_1 , V_19 -> V_28 ) ;
} else {
F_15 ( & V_19 -> V_27 , & V_22 -> V_30 ) ;
}
break;
case - V_31 :
case - V_32 :
F_16 ( V_22 , L_2 , V_24 ) ;
F_15 ( & V_19 -> V_27 , & V_22 -> V_30 ) ;
break;
case - V_33 :
F_14 ( V_22 , L_3 , V_16 -> V_34 ) ;
F_15 ( & V_19 -> V_27 , & V_22 -> V_30 ) ;
break;
case - V_35 :
default:
F_14 ( V_22 , L_4 , V_24 ) ;
F_15 ( & V_19 -> V_27 , & V_22 -> V_30 ) ;
break;
}
F_17 ( & V_22 -> V_36 ) ;
F_18 ( & V_22 -> V_26 , V_25 ) ;
}
static void F_19 ( struct V_15 * V_16 , struct V_14 * V_19 )
{
struct V_1 * V_22 = V_16 -> V_23 ;
switch ( V_19 -> V_24 ) {
default:
F_16 ( V_22 , L_5 , V_19 -> V_24 ) ;
case - V_31 :
case - V_32 :
break;
case 0 :
break;
}
F_20 ( & V_22 -> V_26 ) ;
F_12 ( & V_19 -> V_27 ) ;
F_15 ( & V_19 -> V_27 , & V_22 -> V_37 ) ;
F_17 ( & V_22 -> V_38 ) ;
if ( F_21 ( F_22 ( & V_22 -> V_39 ) ) )
F_17 ( & V_22 -> V_40 ) ;
F_23 ( & V_22 -> V_26 ) ;
}
static int
F_24 ( struct V_41 * V_41 , struct V_42 * V_43 )
{
struct V_1 * V_22 ;
unsigned long V_25 ;
int V_44 = - V_45 ;
V_22 = F_2 ( V_41 -> V_46 , struct V_1 , V_47 ) ;
F_11 ( & V_22 -> V_26 , V_25 ) ;
if ( ! V_22 -> V_48 ) {
V_22 -> V_48 = 1 ;
V_43 -> V_49 = V_22 ;
V_44 = 0 ;
V_22 -> V_50 |= V_51 ;
}
F_18 ( & V_22 -> V_26 , V_25 ) ;
F_14 ( V_22 , L_6 , V_44 ) ;
return V_44 ;
}
static int
F_25 ( struct V_41 * V_41 , struct V_42 * V_43 )
{
struct V_1 * V_22 = V_43 -> V_49 ;
unsigned long V_25 ;
F_11 ( & V_22 -> V_26 , V_25 ) ;
V_22 -> V_48 = 0 ;
V_43 -> V_49 = NULL ;
V_22 -> V_50 &= ~ V_51 ;
F_18 ( & V_22 -> V_26 , V_25 ) ;
F_14 ( V_22 , L_7 ) ;
return 0 ;
}
static void
F_26 ( struct V_1 * V_22 )
{
struct V_14 * V_19 ;
while ( F_21 ( ! F_22 ( & V_22 -> V_30 ) ) ) {
int error ;
V_19 = F_2 ( V_22 -> V_30 . V_52 ,
struct V_14 , V_27 ) ;
F_12 ( & V_19 -> V_27 ) ;
V_19 -> V_20 = V_53 ;
V_19 -> V_54 = F_10 ;
F_23 ( & V_22 -> V_26 ) ;
error = F_27 ( V_22 -> V_55 , V_19 , V_56 ) ;
F_20 ( & V_22 -> V_26 ) ;
if ( error ) {
F_14 ( V_22 , L_8 , error ) ;
F_15 ( & V_19 -> V_27 , & V_22 -> V_30 ) ;
break;
}
else if ( F_22 ( & V_19 -> V_27 ) )
F_15 ( & V_19 -> V_27 , & V_22 -> V_57 ) ;
}
}
static T_2
F_28 ( struct V_42 * V_43 , char T_3 * V_21 , T_4 V_17 , T_5 * V_58 )
{
struct V_1 * V_22 = V_43 -> V_49 ;
unsigned long V_25 ;
T_4 V_59 ;
T_4 V_60 ;
struct V_14 * V_19 ;
struct V_14 * V_61 ;
T_4 V_62 ;
T_6 * V_63 ;
if ( V_17 == 0 )
return - V_64 ;
F_14 ( V_22 , L_9 , ( int ) V_17 ) ;
F_29 ( & V_22 -> V_65 ) ;
F_11 ( & V_22 -> V_26 , V_25 ) ;
V_22 -> V_66 = 0 ;
F_26 ( V_22 ) ;
V_60 = 0 ;
V_61 = V_22 -> V_61 ;
V_62 = V_22 -> V_62 ;
V_63 = V_22 -> V_63 ;
V_22 -> V_61 = NULL ;
V_22 -> V_62 = 0 ;
V_22 -> V_63 = NULL ;
if ( ( V_62 == 0 ) &&
( F_21 ( F_22 ( & V_22 -> V_29 ) ) ) ) {
F_18 ( & V_22 -> V_26 , V_25 ) ;
if ( V_43 -> V_67 & ( V_68 | V_69 ) ) {
F_30 ( & V_22 -> V_65 ) ;
return - V_70 ;
}
F_31 ( V_22 -> V_36 ,
( F_21 ( ! F_22 ( & V_22 -> V_29 ) ) ) ) ;
F_11 ( & V_22 -> V_26 , V_25 ) ;
}
while ( ( V_62 || F_21 ( ! F_22 ( & V_22 -> V_29 ) ) )
&& V_17 ) {
if ( V_62 == 0 ) {
V_19 = F_2 ( V_22 -> V_29 . V_52 ,
struct V_14 , V_27 ) ;
F_12 ( & V_19 -> V_27 ) ;
if ( V_19 -> V_28 && V_19 -> V_21 ) {
V_61 = V_19 ;
V_62 = V_19 -> V_28 ;
V_63 = V_19 -> V_21 ;
} else {
F_15 ( & V_19 -> V_27 , & V_22 -> V_30 ) ;
continue;
}
}
F_18 ( & V_22 -> V_26 , V_25 ) ;
if ( V_17 > V_62 )
V_59 = V_62 ;
else
V_59 = V_17 ;
V_59 -= F_32 ( V_21 , V_63 , V_59 ) ;
V_60 += V_59 ;
V_17 -= V_59 ;
V_21 += V_59 ;
F_11 ( & V_22 -> V_26 , V_25 ) ;
if ( V_22 -> V_66 ) {
F_15 ( & V_61 -> V_27 , & V_22 -> V_30 ) ;
F_18 ( & V_22 -> V_26 , V_25 ) ;
F_30 ( & V_22 -> V_65 ) ;
return - V_70 ;
}
if ( V_59 < V_62 ) {
V_62 -= V_59 ;
V_63 += V_59 ;
} else {
F_15 ( & V_61 -> V_27 , & V_22 -> V_30 ) ;
V_62 = 0 ;
V_63 = NULL ;
V_61 = NULL ;
}
}
V_22 -> V_61 = V_61 ;
V_22 -> V_62 = V_62 ;
V_22 -> V_63 = V_63 ;
F_18 ( & V_22 -> V_26 , V_25 ) ;
F_30 ( & V_22 -> V_65 ) ;
F_14 ( V_22 , L_10 , ( int ) V_60 ) ;
if ( V_60 )
return V_60 ;
else
return - V_70 ;
}
static T_2
F_33 ( struct V_42 * V_43 , const char T_3 * V_21 , T_4 V_17 , T_5 * V_58 )
{
struct V_1 * V_22 = V_43 -> V_49 ;
unsigned long V_25 ;
T_4 V_59 ;
T_4 V_60 = 0 ;
struct V_14 * V_19 ;
F_14 ( V_22 , L_11 , ( int ) V_17 ) ;
if ( V_17 == 0 )
return - V_64 ;
F_29 ( & V_22 -> V_65 ) ;
F_11 ( & V_22 -> V_26 , V_25 ) ;
V_22 -> V_66 = 0 ;
if ( F_21 ( F_22 ( & V_22 -> V_37 ) ) ) {
F_18 ( & V_22 -> V_26 , V_25 ) ;
if ( V_43 -> V_67 & ( V_68 | V_69 ) ) {
F_30 ( & V_22 -> V_65 ) ;
return - V_70 ;
}
F_31 ( V_22 -> V_38 ,
( F_21 ( ! F_22 ( & V_22 -> V_37 ) ) ) ) ;
F_11 ( & V_22 -> V_26 , V_25 ) ;
}
while ( F_21 ( ! F_22 ( & V_22 -> V_37 ) ) && V_17 ) {
if ( V_17 > V_53 )
V_59 = V_53 ;
else
V_59 = V_17 ;
V_19 = F_2 ( V_22 -> V_37 . V_52 , struct V_14 ,
V_27 ) ;
F_12 ( & V_19 -> V_27 ) ;
V_19 -> V_54 = F_19 ;
V_19 -> V_20 = V_59 ;
if ( V_17 > V_59 )
V_19 -> V_71 = 0 ;
else
V_19 -> V_71 = ( ( V_17 % V_22 -> V_72 -> V_73 ) == 0 ) ;
F_18 ( & V_22 -> V_26 , V_25 ) ;
if ( F_34 ( V_19 -> V_21 , V_21 , V_59 ) ) {
F_15 ( & V_19 -> V_27 , & V_22 -> V_37 ) ;
F_30 ( & V_22 -> V_65 ) ;
return V_60 ;
}
V_60 += V_59 ;
V_17 -= V_59 ;
V_21 += V_59 ;
F_11 ( & V_22 -> V_26 , V_25 ) ;
if ( V_22 -> V_66 ) {
F_15 ( & V_19 -> V_27 , & V_22 -> V_37 ) ;
F_18 ( & V_22 -> V_26 , V_25 ) ;
F_30 ( & V_22 -> V_65 ) ;
return - V_70 ;
}
if ( F_27 ( V_22 -> V_72 , V_19 , V_56 ) ) {
F_15 ( & V_19 -> V_27 , & V_22 -> V_37 ) ;
F_18 ( & V_22 -> V_26 , V_25 ) ;
F_30 ( & V_22 -> V_65 ) ;
return - V_70 ;
}
F_15 ( & V_19 -> V_27 , & V_22 -> V_39 ) ;
}
F_18 ( & V_22 -> V_26 , V_25 ) ;
F_30 ( & V_22 -> V_65 ) ;
F_14 ( V_22 , L_12 , ( int ) V_60 ) ;
if ( V_60 )
return V_60 ;
else
return - V_70 ;
}
static int
F_35 ( struct V_42 * V_43 , T_5 V_74 , T_5 V_75 , int V_76 )
{
struct V_1 * V_22 = V_43 -> V_49 ;
struct V_41 * V_41 = F_36 ( V_43 ) ;
unsigned long V_25 ;
int V_77 ;
F_29 ( & V_41 -> V_78 ) ;
F_11 ( & V_22 -> V_26 , V_25 ) ;
V_77 = ( F_21 ( F_22 ( & V_22 -> V_37 ) ) ) ;
F_18 ( & V_22 -> V_26 , V_25 ) ;
if ( ! V_77 ) {
F_31 ( V_22 -> V_40 ,
( F_21 ( F_22 ( & V_22 -> V_39 ) ) ) ) ;
}
F_30 ( & V_41 -> V_78 ) ;
return 0 ;
}
static unsigned int
F_37 ( struct V_42 * V_43 , T_7 * V_79 )
{
struct V_1 * V_22 = V_43 -> V_49 ;
unsigned long V_25 ;
int V_24 = 0 ;
F_29 ( & V_22 -> V_65 ) ;
F_11 ( & V_22 -> V_26 , V_25 ) ;
F_26 ( V_22 ) ;
F_18 ( & V_22 -> V_26 , V_25 ) ;
F_30 ( & V_22 -> V_65 ) ;
F_38 ( V_43 , & V_22 -> V_36 , V_79 ) ;
F_38 ( V_43 , & V_22 -> V_38 , V_79 ) ;
F_11 ( & V_22 -> V_26 , V_25 ) ;
if ( F_21 ( ! F_22 ( & V_22 -> V_37 ) ) )
V_24 |= V_80 | V_81 ;
if ( F_21 ( V_22 -> V_62 ) ||
F_21 ( ! F_22 ( & V_22 -> V_29 ) ) )
V_24 |= V_82 | V_83 ;
F_18 ( & V_22 -> V_26 , V_25 ) ;
return V_24 ;
}
static long
F_39 ( struct V_42 * V_43 , unsigned int V_84 , unsigned long V_85 )
{
struct V_1 * V_22 = V_43 -> V_49 ;
unsigned long V_25 ;
int V_24 = 0 ;
F_14 ( V_22 , L_13 , V_84 , V_85 ) ;
F_11 ( & V_22 -> V_26 , V_25 ) ;
switch ( V_84 ) {
case V_86 :
V_24 = ( int ) V_22 -> V_50 ;
break;
case V_87 :
V_22 -> V_50 = ( T_6 ) V_85 ;
break;
default:
F_14 ( V_22 , L_14 ,
V_84 ) ;
V_24 = - V_88 ;
}
F_18 ( & V_22 -> V_26 , V_25 ) ;
return V_24 ;
}
static int
F_40 ( struct V_1 * V_22 )
{
int V_89 = 0 ;
V_22 -> V_72 -> V_90 = F_3 ( V_22 -> V_7 , & V_91 , & V_92 ,
& V_93 ) ;
V_22 -> V_72 -> V_23 = V_22 ;
V_22 -> V_55 -> V_90 = F_3 ( V_22 -> V_7 , & V_94 ,
& V_95 , & V_96 ) ;
V_22 -> V_55 -> V_23 = V_22 ;
V_89 = F_41 ( V_22 -> V_72 ) ;
if ( V_89 != 0 ) {
F_14 ( V_22 , L_15 , V_22 -> V_72 -> V_34 , V_89 ) ;
goto V_97;
}
V_89 = F_41 ( V_22 -> V_55 ) ;
if ( V_89 != 0 ) {
F_14 ( V_22 , L_15 , V_22 -> V_72 -> V_34 , V_89 ) ;
goto V_97;
}
V_97:
if ( V_89 != 0 ) {
( void ) F_42 ( V_22 -> V_72 ) ;
( void ) F_42 ( V_22 -> V_55 ) ;
V_22 -> V_72 -> V_90 = NULL ;
V_22 -> V_55 -> V_90 = NULL ;
}
return V_89 ;
}
static void F_43 ( struct V_1 * V_22 )
{
unsigned long V_25 ;
if ( V_22 -> V_98 < 0 )
return;
F_14 ( V_22 , L_16 , V_99 ) ;
if ( V_22 -> V_72 -> V_90 )
F_42 ( V_22 -> V_72 ) ;
if ( V_22 -> V_55 -> V_90 )
F_42 ( V_22 -> V_55 ) ;
F_11 ( & V_22 -> V_26 , V_25 ) ;
V_22 -> V_72 -> V_90 = NULL ;
V_22 -> V_55 -> V_90 = NULL ;
V_22 -> V_98 = - 1 ;
F_18 ( & V_22 -> V_26 , V_25 ) ;
}
static int F_44 ( struct V_1 * V_22 , unsigned V_100 )
{
int V_89 = 0 ;
F_43 ( V_22 ) ;
V_89 = F_40 ( V_22 ) ;
if ( V_89 )
F_43 ( V_22 ) ;
else
V_22 -> V_98 = V_100 ;
if ( ! V_89 )
F_45 ( V_22 , L_17 , V_100 ) ;
return V_89 ;
}
static void F_46 ( struct V_1 * V_22 )
{
struct V_14 * V_19 ;
F_45 ( V_22 , L_18 ) ;
if ( F_42 ( V_22 -> V_72 ) )
F_14 ( V_22 , L_19 ) ;
if ( F_42 ( V_22 -> V_55 ) )
F_14 ( V_22 , L_20 ) ;
if ( V_22 -> V_61 != NULL ) {
F_15 ( & V_22 -> V_61 -> V_27 , & V_22 -> V_30 ) ;
V_22 -> V_61 = NULL ;
}
V_22 -> V_62 = 0 ;
V_22 -> V_63 = NULL ;
V_22 -> V_66 = 1 ;
while ( F_21 ( ! ( F_22 ( & V_22 -> V_29 ) ) ) ) {
V_19 = F_2 ( V_22 -> V_29 . V_52 , struct V_14 ,
V_27 ) ;
F_12 ( & V_19 -> V_27 ) ;
F_15 ( & V_19 -> V_27 , & V_22 -> V_30 ) ;
}
while ( F_21 ( ! ( F_22 ( & V_22 -> V_57 ) ) ) ) {
V_19 = F_2 ( V_22 -> V_29 . V_52 , struct V_14 ,
V_27 ) ;
F_12 ( & V_19 -> V_27 ) ;
F_15 ( & V_19 -> V_27 , & V_22 -> V_30 ) ;
}
while ( F_21 ( ! ( F_22 ( & V_22 -> V_39 ) ) ) ) {
V_19 = F_2 ( V_22 -> V_39 . V_52 ,
struct V_14 , V_27 ) ;
F_12 ( & V_19 -> V_27 ) ;
F_15 ( & V_19 -> V_27 , & V_22 -> V_37 ) ;
}
if ( F_41 ( V_22 -> V_72 ) )
F_14 ( V_22 , L_21 ) ;
if ( F_41 ( V_22 -> V_55 ) )
F_14 ( V_22 , L_22 ) ;
F_17 ( & V_22 -> V_36 ) ;
F_17 ( & V_22 -> V_38 ) ;
F_17 ( & V_22 -> V_40 ) ;
}
static bool F_47 ( struct V_2 * V_3 ,
const struct V_101 * V_102 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
T_8 V_103 = F_48 ( V_102 -> V_104 ) ;
T_8 V_105 = F_48 ( V_102 -> V_106 ) ;
T_8 V_107 = F_48 ( V_102 -> V_108 ) ;
if ( ( V_102 -> V_109 & V_110 ) != V_111 ||
( V_102 -> V_109 & V_112 ) != V_113 )
return false ;
switch ( V_102 -> V_114 ) {
case V_115 :
V_103 >>= 8 ;
if ( V_107 <= V_116 &&
( V_117 & V_102 -> V_109 ) )
break;
return false ;
case V_118 :
if ( ! V_105 && V_107 == 1 &&
( V_117 & V_102 -> V_109 ) )
break;
return false ;
case V_119 :
if ( ! V_105 && ! V_107 &&
! ( V_117 & V_102 -> V_109 ) )
break;
default:
return false ;
}
return V_103 == V_22 -> V_98 ;
}
static int F_49 ( struct V_2 * V_3 ,
const struct V_101 * V_102 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
struct V_120 * V_121 = V_3 -> V_122 -> V_121 ;
struct V_14 * V_19 = V_121 -> V_19 ;
int V_123 = - V_124 ;
T_8 V_104 = F_48 ( V_102 -> V_104 ) ;
T_8 V_106 = F_48 ( V_102 -> V_106 ) ;
T_8 V_108 = F_48 ( V_102 -> V_108 ) ;
F_14 ( V_22 , L_23 ,
V_102 -> V_109 , V_102 -> V_114 , V_106 , V_104 , V_108 ) ;
switch ( V_102 -> V_109 & V_112 ) {
case V_113 :
switch ( V_102 -> V_114 ) {
case V_115 :
if ( ( V_104 >> 8 ) != V_22 -> V_98 )
break;
V_123 = ( V_22 -> V_125 [ 0 ] << 8 ) | V_22 -> V_125 [ 1 ] ;
memcpy ( V_19 -> V_21 , V_22 -> V_125 , V_123 ) ;
F_14 ( V_22 , L_24 , V_123 ,
& V_22 -> V_125 [ 2 ] ) ;
break;
case V_118 :
if ( V_104 != V_22 -> V_98 )
break;
* ( T_6 * ) V_19 -> V_21 = V_22 -> V_50 ;
V_123 = F_50 ( T_8 , V_108 , 1 ) ;
break;
case V_119 :
if ( V_104 != V_22 -> V_98 )
break;
F_46 ( V_22 ) ;
V_123 = 0 ;
break;
default:
goto V_126;
}
break;
default:
V_126:
F_16 ( V_22 ,
L_25 ,
V_102 -> V_109 , V_102 -> V_114 ,
V_106 , V_104 , V_108 ) ;
break;
}
if ( V_123 >= 0 ) {
V_19 -> V_20 = V_123 ;
V_19 -> V_71 = V_123 < V_108 ;
V_123 = F_27 ( V_121 -> V_7 -> V_127 , V_19 , V_56 ) ;
if ( V_123 < 0 ) {
ERROR ( V_22 , L_26 , V_99 , __LINE__ ) ;
V_19 -> V_24 = 0 ;
}
}
return V_123 ;
}
static int F_51 ( struct V_128 * V_129 ,
struct V_2 * V_3 )
{
struct V_6 * V_7 = V_129 -> V_121 -> V_7 ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
struct V_130 * V_131 ;
struct V_120 * V_121 = V_129 -> V_121 ;
struct V_15 * V_72 ;
struct V_15 * V_55 = NULL ;
struct V_14 * V_19 ;
T_9 V_132 ;
int V_133 ;
int V_44 ;
T_10 V_134 ;
V_133 = F_52 ( V_129 , V_3 ) ;
if ( V_133 < 0 )
return V_133 ;
V_135 . V_136 = V_133 ;
V_22 -> V_7 = V_7 ;
V_72 = F_53 ( V_121 -> V_7 , & V_91 ) ;
if ( ! V_72 ) {
V_137:
F_54 ( & V_121 -> V_7 -> V_22 , L_27 ,
V_121 -> V_7 -> V_34 ) ;
return - V_138 ;
}
V_55 = F_53 ( V_121 -> V_7 , & V_94 ) ;
if ( ! V_55 )
goto V_137;
V_92 . V_139 = V_91 . V_139 ;
V_95 . V_139 = V_94 . V_139 ;
V_93 . V_139 = V_91 . V_139 ;
V_96 . V_139 = V_94 . V_139 ;
V_44 = F_55 ( V_3 , V_140 ,
V_141 , V_142 ) ;
if ( V_44 )
return V_44 ;
V_22 -> V_72 = V_72 ;
V_22 -> V_55 = V_55 ;
V_44 = - V_143 ;
for ( V_134 = 0 ; V_134 < V_22 -> V_144 ; V_134 ++ ) {
V_19 = F_4 ( V_22 -> V_72 , V_53 , V_145 ) ;
if ( ! V_19 )
goto V_146;
F_15 ( & V_19 -> V_27 , & V_22 -> V_37 ) ;
}
for ( V_134 = 0 ; V_134 < V_22 -> V_144 ; V_134 ++ ) {
V_19 = F_4 ( V_22 -> V_55 , V_53 , V_145 ) ;
if ( ! V_19 )
goto V_147;
F_15 ( & V_19 -> V_27 , & V_22 -> V_30 ) ;
}
V_132 = F_56 ( V_148 , V_22 -> V_149 ) ;
V_131 = F_57 ( V_150 , NULL , V_132 ,
NULL , L_28 , V_22 -> V_149 ) ;
if ( F_58 ( V_131 ) ) {
ERROR ( V_22 , L_29 ) ;
V_44 = F_59 ( V_131 ) ;
goto V_147;
}
F_60 ( & V_22 -> V_47 , & V_151 ) ;
V_22 -> V_47 . V_152 = V_153 ;
V_44 = F_61 ( & V_22 -> V_47 , V_132 , 1 ) ;
if ( V_44 ) {
ERROR ( V_22 , L_30 ) ;
goto V_154;
}
return 0 ;
V_154:
F_62 ( V_150 , V_132 ) ;
V_147:
while ( ! F_22 ( & V_22 -> V_30 ) ) {
V_19 = F_2 ( V_22 -> V_30 . V_52 , struct V_14 , V_27 ) ;
F_63 ( & V_19 -> V_27 ) ;
F_8 ( V_22 -> V_55 , V_19 ) ;
}
V_146:
while ( ! F_22 ( & V_22 -> V_37 ) ) {
V_19 = F_2 ( V_22 -> V_37 . V_52 , struct V_14 , V_27 ) ;
F_63 ( & V_19 -> V_27 ) ;
F_8 ( V_22 -> V_72 , V_19 ) ;
}
return V_44 ;
}
static int F_64 ( struct V_2 * V_3 ,
unsigned V_155 , unsigned V_156 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
int V_44 = - V_157 ;
if ( ! V_156 )
V_44 = F_44 ( V_22 , V_155 ) ;
return V_44 ;
}
static void F_65 ( struct V_2 * V_3 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
F_14 ( V_22 , L_16 , V_99 ) ;
F_43 ( V_22 ) ;
}
static inline struct V_158
* F_66 ( struct V_159 * V_160 )
{
return F_2 ( F_67 ( V_160 ) , struct V_158 ,
V_161 . V_162 ) ;
}
static void F_68 ( struct V_159 * V_160 )
{
struct V_158 * V_163 = F_66 ( V_160 ) ;
F_69 ( & V_163 -> V_161 ) ;
}
static T_2 F_70 ( struct V_159 * V_160 ,
char * V_164 )
{
struct V_158 * V_163 = F_66 ( V_160 ) ;
int V_89 ;
F_29 ( & V_163 -> V_26 ) ;
V_89 = F_71 ( V_164 , V_163 -> V_125 + 2 , V_116 - 2 ) ;
F_30 ( & V_163 -> V_26 ) ;
return V_89 ;
}
static T_2 F_72 ( struct V_159 * V_160 ,
const char * V_164 , T_4 V_17 )
{
struct V_158 * V_163 = F_66 ( V_160 ) ;
int V_89 , V_165 ;
F_29 ( & V_163 -> V_26 ) ;
V_89 = F_71 ( V_163 -> V_125 + 2 , V_164 , V_116 - 2 ) ;
V_165 = strlen ( V_163 -> V_125 + 2 ) + 2 ;
V_163 -> V_125 [ 0 ] = ( V_165 >> 8 ) & 0xFF ;
V_163 -> V_125 [ 1 ] = V_165 & 0xFF ;
F_30 ( & V_163 -> V_26 ) ;
return V_89 ;
}
static T_2 F_73 ( struct V_159 * V_160 ,
char * V_164 )
{
struct V_158 * V_163 = F_66 ( V_160 ) ;
int V_89 ;
F_29 ( & V_163 -> V_26 ) ;
V_89 = sprintf ( V_164 , L_31 , V_163 -> V_144 ) ;
F_30 ( & V_163 -> V_26 ) ;
return V_89 ;
}
static T_2 F_74 ( struct V_159 * V_160 ,
const char * V_164 , T_4 V_17 )
{
struct V_158 * V_163 = F_66 ( V_160 ) ;
int V_44 ;
T_8 V_166 ;
F_29 ( & V_163 -> V_26 ) ;
if ( V_163 -> V_167 ) {
V_44 = - V_45 ;
goto V_75;
}
V_44 = F_75 ( V_164 , 0 , & V_166 ) ;
if ( V_44 )
goto V_75;
V_163 -> V_144 = ( unsigned ) V_166 ;
V_44 = V_17 ;
V_75:
F_30 ( & V_163 -> V_26 ) ;
return V_44 ;
}
static inline int F_76 ( void )
{
int V_44 ;
V_44 = F_77 ( & V_168 , 0 , 0 , V_145 ) ;
if ( V_44 >= V_169 ) {
F_78 ( & V_168 , V_44 ) ;
V_44 = - V_138 ;
}
return V_44 ;
}
static inline void F_79 ( int V_149 )
{
F_78 ( & V_168 , V_149 ) ;
}
static void F_80 ( struct V_170 * V_3 )
{
struct V_158 * V_163 ;
V_163 = F_2 ( V_3 , struct V_158 , V_161 ) ;
F_29 ( & V_171 ) ;
F_79 ( V_163 -> V_149 ) ;
if ( F_81 ( & V_168 . V_172 ) )
F_82 () ;
F_30 ( & V_171 ) ;
F_9 ( V_163 ) ;
}
static struct V_170 * F_83 ( void )
{
struct V_158 * V_163 ;
struct V_170 * V_44 ;
int V_24 = 0 ;
V_163 = F_84 ( sizeof( * V_163 ) , V_145 ) ;
if ( ! V_163 )
return F_85 ( - V_143 ) ;
F_86 ( & V_163 -> V_26 ) ;
V_163 -> V_161 . V_173 = F_80 ;
V_44 = & V_163 -> V_161 ;
F_29 ( & V_171 ) ;
if ( F_81 ( & V_168 . V_172 ) ) {
V_24 = F_87 ( V_169 ) ;
if ( V_24 ) {
V_44 = F_85 ( V_24 ) ;
F_9 ( V_163 ) ;
goto V_174;
}
}
V_163 -> V_149 = F_76 () ;
if ( V_163 -> V_149 < 0 ) {
V_44 = F_85 ( V_163 -> V_149 ) ;
F_9 ( V_163 ) ;
if ( F_81 ( & V_168 . V_172 ) )
F_82 () ;
goto V_174;
}
F_88 ( & V_163 -> V_161 . V_162 , L_32 ,
& V_175 ) ;
V_174:
F_30 ( & V_171 ) ;
return V_44 ;
}
static void F_89 ( struct V_2 * V_3 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
struct V_158 * V_163 ;
V_163 = F_2 ( V_3 -> V_176 , struct V_158 , V_161 ) ;
F_9 ( V_22 ) ;
F_29 ( & V_163 -> V_26 ) ;
-- V_163 -> V_167 ;
F_30 ( & V_163 -> V_26 ) ;
}
static void F_90 ( struct V_128 * V_129 ,
struct V_2 * V_3 )
{
struct V_1 * V_22 ;
struct V_14 * V_19 ;
V_22 = F_1 ( V_3 ) ;
F_62 ( V_150 , F_56 ( V_148 , V_22 -> V_149 ) ) ;
F_91 ( & V_22 -> V_47 ) ;
F_92 ( ! F_22 ( & V_22 -> V_39 ) ) ;
F_92 ( ! F_22 ( & V_22 -> V_57 ) ) ;
while ( ! F_22 ( & V_22 -> V_37 ) ) {
V_19 = F_2 ( V_22 -> V_37 . V_52 , struct V_14 ,
V_27 ) ;
F_63 ( & V_19 -> V_27 ) ;
F_8 ( V_22 -> V_72 , V_19 ) ;
}
if ( V_22 -> V_61 != NULL )
F_8 ( V_22 -> V_55 , V_22 -> V_61 ) ;
while ( ! F_22 ( & V_22 -> V_30 ) ) {
V_19 = F_2 ( V_22 -> V_30 . V_52 ,
struct V_14 , V_27 ) ;
F_63 ( & V_19 -> V_27 ) ;
F_8 ( V_22 -> V_55 , V_19 ) ;
}
while ( ! F_22 ( & V_22 -> V_29 ) ) {
V_19 = F_2 ( V_22 -> V_29 . V_52 ,
struct V_14 , V_27 ) ;
F_63 ( & V_19 -> V_27 ) ;
F_8 ( V_22 -> V_55 , V_19 ) ;
}
F_93 ( V_3 ) ;
}
static struct V_2 * F_94 ( struct V_170 * V_176 )
{
struct V_1 * V_22 ;
struct V_158 * V_163 ;
V_163 = F_2 ( V_176 , struct V_158 , V_161 ) ;
F_29 ( & V_163 -> V_26 ) ;
if ( V_163 -> V_149 >= V_177 ) {
F_30 ( & V_163 -> V_26 ) ;
return F_85 ( - V_178 ) ;
}
V_22 = F_84 ( sizeof( * V_22 ) , V_145 ) ;
if ( ! V_22 ) {
F_30 ( & V_163 -> V_26 ) ;
return F_85 ( - V_143 ) ;
}
++ V_163 -> V_167 ;
V_22 -> V_149 = V_163 -> V_149 ;
V_22 -> V_125 = V_163 -> V_125 ;
V_22 -> V_144 = V_163 -> V_144 ;
F_30 ( & V_163 -> V_26 ) ;
V_22 -> V_4 . V_34 = L_33 ;
V_22 -> V_4 . V_179 = F_51 ;
V_22 -> V_4 . V_180 = F_49 ;
V_22 -> V_4 . V_181 = F_90 ;
V_22 -> V_4 . V_182 = F_64 ;
V_22 -> V_4 . V_183 = F_65 ;
V_22 -> V_4 . V_184 = F_47 ;
V_22 -> V_4 . V_185 = F_89 ;
F_95 ( & V_22 -> V_37 ) ;
F_95 ( & V_22 -> V_30 ) ;
F_95 ( & V_22 -> V_29 ) ;
F_95 ( & V_22 -> V_39 ) ;
F_95 ( & V_22 -> V_57 ) ;
F_96 ( & V_22 -> V_26 ) ;
F_86 ( & V_22 -> V_65 ) ;
F_97 ( & V_22 -> V_36 ) ;
F_97 ( & V_22 -> V_38 ) ;
F_97 ( & V_22 -> V_40 ) ;
V_22 -> V_98 = - 1 ;
V_22 -> V_48 = 0 ;
V_22 -> V_50 = V_186 ;
V_22 -> V_61 = NULL ;
V_22 -> V_62 = 0 ;
V_22 -> V_63 = NULL ;
return & V_22 -> V_4 ;
}
static int F_87 ( int V_187 )
{
int V_24 ;
T_9 V_132 ;
V_150 = F_98 ( V_153 , L_34 ) ;
if ( F_58 ( V_150 ) ) {
V_24 = F_59 ( V_150 ) ;
V_150 = NULL ;
F_99 ( L_35 , V_24 ) ;
return V_24 ;
}
V_24 = F_100 ( & V_132 , 0 , V_187 , L_36 ) ;
if ( V_24 ) {
F_99 ( L_37 , V_24 ) ;
F_101 ( V_150 ) ;
V_150 = NULL ;
return V_24 ;
}
V_148 = F_102 ( V_132 ) ;
V_177 = V_187 ;
return V_24 ;
}
static void F_82 ( void )
{
if ( V_148 ) {
F_103 ( F_56 ( V_148 , 0 ) , V_177 ) ;
V_148 = V_177 = 0 ;
}
F_101 ( V_150 ) ;
V_150 = NULL ;
}
