static struct V_1 *
F_1 ( struct V_2 * V_3 , unsigned V_4 , T_1 V_5 )
{
struct V_1 * V_6 ;
V_6 = F_2 ( V_3 , V_5 ) ;
if ( V_6 != NULL ) {
V_6 -> V_7 = V_4 ;
V_6 -> V_8 = F_3 ( V_4 , V_5 ) ;
if ( V_6 -> V_8 == NULL ) {
F_4 ( V_3 , V_6 ) ;
return NULL ;
}
}
return V_6 ;
}
static void
F_5 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
if ( V_3 != NULL && V_6 != NULL ) {
F_6 ( V_6 -> V_8 ) ;
F_4 ( V_3 , V_6 ) ;
}
}
static void F_7 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
struct V_9 * V_10 = V_3 -> V_11 ;
int V_12 = V_6 -> V_12 ;
unsigned long V_13 ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
F_9 ( & V_6 -> V_15 ) ;
switch ( V_12 ) {
case 0 :
if ( V_6 -> V_16 > 0 ) {
F_10 ( & V_6 -> V_15 , & V_10 -> V_17 ) ;
F_11 ( V_10 , L_1 , V_6 -> V_16 ) ;
} else {
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
}
break;
case - V_19 :
case - V_20 :
F_13 ( V_10 , L_2 , V_12 ) ;
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
break;
case - V_21 :
F_11 ( V_10 , L_3 , V_3 -> V_22 ) ;
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
break;
case - V_23 :
default:
F_11 ( V_10 , L_4 , V_12 ) ;
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
break;
}
F_14 ( & V_10 -> V_24 ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
}
static void F_16 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
struct V_9 * V_10 = V_3 -> V_11 ;
switch ( V_6 -> V_12 ) {
default:
F_13 ( V_10 , L_5 , V_6 -> V_12 ) ;
case - V_19 :
case - V_20 :
break;
case 0 :
break;
}
F_17 ( & V_10 -> V_14 ) ;
F_9 ( & V_6 -> V_15 ) ;
F_12 ( & V_6 -> V_15 , & V_10 -> V_25 ) ;
F_14 ( & V_10 -> V_26 ) ;
if ( F_18 ( F_19 ( & V_10 -> V_27 ) ) )
F_14 ( & V_10 -> V_28 ) ;
F_20 ( & V_10 -> V_14 ) ;
}
static int
F_21 ( struct V_29 * V_29 , struct V_30 * V_31 )
{
struct V_9 * V_10 ;
unsigned long V_13 ;
int V_32 = - V_33 ;
F_22 ( & V_34 ) ;
V_10 = F_23 ( V_29 -> V_35 , struct V_9 , V_36 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
if ( ! V_10 -> V_37 ) {
V_10 -> V_37 = 1 ;
V_31 -> V_38 = V_10 ;
V_32 = 0 ;
V_10 -> V_39 |= V_40 ;
}
F_15 ( & V_10 -> V_14 , V_13 ) ;
F_11 ( V_10 , L_6 , V_32 ) ;
F_24 ( & V_34 ) ;
return V_32 ;
}
static int
F_25 ( struct V_29 * V_29 , struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_38 ;
unsigned long V_13 ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
V_10 -> V_37 = 0 ;
V_31 -> V_38 = NULL ;
V_10 -> V_39 &= ~ V_40 ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
F_11 ( V_10 , L_7 ) ;
return 0 ;
}
static void
F_26 ( struct V_9 * V_10 )
{
struct V_1 * V_6 ;
while ( F_18 ( ! F_19 ( & V_10 -> V_18 ) ) ) {
int error ;
V_6 = F_23 ( V_10 -> V_18 . V_41 ,
struct V_1 , V_15 ) ;
F_9 ( & V_6 -> V_15 ) ;
V_6 -> V_7 = V_42 ;
V_6 -> V_43 = F_7 ;
error = F_27 ( V_10 -> V_44 , V_6 , V_45 ) ;
if ( error ) {
F_11 ( V_10 , L_8 , error ) ;
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
break;
} else {
F_12 ( & V_6 -> V_15 , & V_10 -> V_46 ) ;
}
}
}
static T_2
F_28 ( struct V_30 * V_31 , char T_3 * V_8 , T_4 V_4 , T_5 * V_47 )
{
struct V_9 * V_10 = V_31 -> V_38 ;
unsigned long V_13 ;
T_4 V_48 ;
T_4 V_49 ;
struct V_1 * V_6 ;
struct V_1 * V_50 ;
T_4 V_51 ;
T_6 * V_52 ;
if ( V_4 == 0 )
return - V_53 ;
F_11 ( V_10 , L_9 , ( int ) V_4 ) ;
F_22 ( & V_10 -> V_54 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
V_10 -> V_55 = 0 ;
F_26 ( V_10 ) ;
V_49 = 0 ;
V_50 = V_10 -> V_50 ;
V_51 = V_10 -> V_51 ;
V_52 = V_10 -> V_52 ;
V_10 -> V_50 = NULL ;
V_10 -> V_51 = 0 ;
V_10 -> V_52 = NULL ;
if ( ( V_51 == 0 ) &&
( F_18 ( F_19 ( & V_10 -> V_17 ) ) ) ) {
F_15 ( & V_10 -> V_14 , V_13 ) ;
if ( V_31 -> V_56 & ( V_57 | V_58 ) ) {
F_24 ( & V_10 -> V_54 ) ;
return - V_59 ;
}
F_29 ( V_10 -> V_24 ,
( F_18 ( ! F_19 ( & V_10 -> V_17 ) ) ) ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
}
while ( ( V_51 || F_18 ( ! F_19 ( & V_10 -> V_17 ) ) )
&& V_4 ) {
if ( V_51 == 0 ) {
V_6 = F_23 ( V_10 -> V_17 . V_41 ,
struct V_1 , V_15 ) ;
F_9 ( & V_6 -> V_15 ) ;
if ( V_6 -> V_16 && V_6 -> V_8 ) {
V_50 = V_6 ;
V_51 = V_6 -> V_16 ;
V_52 = V_6 -> V_8 ;
} else {
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
continue;
}
}
F_15 ( & V_10 -> V_14 , V_13 ) ;
if ( V_4 > V_51 )
V_48 = V_51 ;
else
V_48 = V_4 ;
V_48 -= F_30 ( V_8 , V_52 , V_48 ) ;
V_49 += V_48 ;
V_4 -= V_48 ;
V_8 += V_48 ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
if ( V_10 -> V_55 ) {
F_12 ( & V_50 -> V_15 , & V_10 -> V_18 ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
F_24 ( & V_10 -> V_54 ) ;
return - V_59 ;
}
if ( V_48 < V_51 ) {
V_51 -= V_48 ;
V_52 += V_48 ;
} else {
F_12 ( & V_50 -> V_15 , & V_10 -> V_18 ) ;
V_51 = 0 ;
V_52 = NULL ;
V_50 = NULL ;
}
}
V_10 -> V_50 = V_50 ;
V_10 -> V_51 = V_51 ;
V_10 -> V_52 = V_52 ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
F_24 ( & V_10 -> V_54 ) ;
F_11 ( V_10 , L_10 , ( int ) V_49 ) ;
if ( V_49 )
return V_49 ;
else
return - V_59 ;
}
static T_2
F_31 ( struct V_30 * V_31 , const char T_3 * V_8 , T_4 V_4 , T_5 * V_47 )
{
struct V_9 * V_10 = V_31 -> V_38 ;
unsigned long V_13 ;
T_4 V_48 ;
T_4 V_49 = 0 ;
struct V_1 * V_6 ;
F_11 ( V_10 , L_11 , ( int ) V_4 ) ;
if ( V_4 == 0 )
return - V_53 ;
F_22 ( & V_10 -> V_54 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
V_10 -> V_55 = 0 ;
if ( F_18 ( F_19 ( & V_10 -> V_25 ) ) ) {
F_15 ( & V_10 -> V_14 , V_13 ) ;
if ( V_31 -> V_56 & ( V_57 | V_58 ) ) {
F_24 ( & V_10 -> V_54 ) ;
return - V_59 ;
}
F_29 ( V_10 -> V_26 ,
( F_18 ( ! F_19 ( & V_10 -> V_25 ) ) ) ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
}
while ( F_18 ( ! F_19 ( & V_10 -> V_25 ) ) && V_4 ) {
if ( V_4 > V_42 )
V_48 = V_42 ;
else
V_48 = V_4 ;
V_6 = F_23 ( V_10 -> V_25 . V_41 , struct V_1 ,
V_15 ) ;
F_9 ( & V_6 -> V_15 ) ;
V_6 -> V_43 = F_16 ;
V_6 -> V_7 = V_48 ;
if ( V_4 > V_48 )
V_6 -> V_60 = 0 ;
else
V_6 -> V_60 = ( ( V_4 % V_10 -> V_61 -> V_62 ) == 0 ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
if ( F_32 ( V_6 -> V_8 , V_8 , V_48 ) ) {
F_12 ( & V_6 -> V_15 , & V_10 -> V_25 ) ;
F_24 ( & V_10 -> V_54 ) ;
return V_49 ;
}
V_49 += V_48 ;
V_4 -= V_48 ;
V_8 += V_48 ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
if ( V_10 -> V_55 ) {
F_12 ( & V_6 -> V_15 , & V_10 -> V_25 ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
F_24 ( & V_10 -> V_54 ) ;
return - V_59 ;
}
if ( F_27 ( V_10 -> V_61 , V_6 , V_45 ) ) {
F_12 ( & V_6 -> V_15 , & V_10 -> V_25 ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
F_24 ( & V_10 -> V_54 ) ;
return - V_59 ;
}
F_12 ( & V_6 -> V_15 , & V_10 -> V_27 ) ;
}
F_15 ( & V_10 -> V_14 , V_13 ) ;
F_24 ( & V_10 -> V_54 ) ;
F_11 ( V_10 , L_12 , ( int ) V_49 ) ;
if ( V_49 ) {
return V_49 ;
} else {
return - V_59 ;
}
}
static int
F_33 ( struct V_30 * V_31 , T_5 V_63 , T_5 V_64 , int V_65 )
{
struct V_9 * V_10 = V_31 -> V_38 ;
struct V_29 * V_29 = V_31 -> V_66 . V_67 -> V_68 ;
unsigned long V_13 ;
int V_69 ;
F_22 ( & V_29 -> V_70 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
V_69 = ( F_18 ( F_19 ( & V_10 -> V_25 ) ) ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
if ( ! V_69 ) {
F_29 ( V_10 -> V_28 ,
( F_18 ( F_19 ( & V_10 -> V_27 ) ) ) ) ;
}
F_24 ( & V_29 -> V_70 ) ;
return 0 ;
}
static unsigned int
F_34 ( struct V_30 * V_31 , T_7 * V_71 )
{
struct V_9 * V_10 = V_31 -> V_38 ;
unsigned long V_13 ;
int V_12 = 0 ;
F_22 ( & V_10 -> V_54 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
F_26 ( V_10 ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
F_24 ( & V_10 -> V_54 ) ;
F_35 ( V_31 , & V_10 -> V_24 , V_71 ) ;
F_35 ( V_31 , & V_10 -> V_26 , V_71 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
if ( F_18 ( ! F_19 ( & V_10 -> V_25 ) ) )
V_12 |= V_72 | V_73 ;
if ( F_18 ( V_10 -> V_51 ) ||
F_18 ( ! F_19 ( & V_10 -> V_17 ) ) )
V_12 |= V_74 | V_75 ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
return V_12 ;
}
static long
F_36 ( struct V_30 * V_31 , unsigned int V_76 , unsigned long V_77 )
{
struct V_9 * V_10 = V_31 -> V_38 ;
unsigned long V_13 ;
int V_12 = 0 ;
F_11 ( V_10 , L_13 , V_76 , V_77 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
switch ( V_76 ) {
case V_78 :
V_12 = ( int ) V_10 -> V_39 ;
break;
case V_79 :
V_10 -> V_39 = ( T_6 ) V_77 ;
break;
default:
F_11 ( V_10 , L_14 ,
V_76 ) ;
V_12 = - V_80 ;
}
F_15 ( & V_10 -> V_14 , V_13 ) ;
return V_12 ;
}
static int
F_37 ( struct V_9 * V_10 )
{
int V_81 = 0 ;
V_10 -> V_61 -> V_82 = F_38 ( V_10 -> V_83 , & V_84 , & V_85 ) ;
V_10 -> V_61 -> V_11 = V_10 ;
V_10 -> V_44 -> V_82 = F_38 ( V_10 -> V_83 , & V_86 ,
& V_87 ) ;
V_10 -> V_44 -> V_11 = V_10 ;
V_81 = F_39 ( V_10 -> V_61 ) ;
if ( V_81 != 0 ) {
F_11 ( V_10 , L_15 , V_10 -> V_61 -> V_22 , V_81 ) ;
goto V_88;
}
V_81 = F_39 ( V_10 -> V_44 ) ;
if ( V_81 != 0 ) {
F_11 ( V_10 , L_15 , V_10 -> V_61 -> V_22 , V_81 ) ;
goto V_88;
}
V_88:
if ( V_81 != 0 ) {
( void ) F_40 ( V_10 -> V_61 ) ;
( void ) F_40 ( V_10 -> V_44 ) ;
V_10 -> V_61 -> V_82 = NULL ;
V_10 -> V_44 -> V_82 = NULL ;
}
return V_81 ;
}
static void F_41 ( struct V_9 * V_10 )
{
if ( V_10 -> V_89 < 0 )
return;
F_11 ( V_10 , L_16 , V_90 ) ;
if ( V_10 -> V_61 -> V_82 )
F_40 ( V_10 -> V_61 ) ;
if ( V_10 -> V_44 -> V_82 )
F_40 ( V_10 -> V_44 ) ;
V_10 -> V_61 -> V_82 = NULL ;
V_10 -> V_44 -> V_82 = NULL ;
V_10 -> V_89 = - 1 ;
}
static int
F_42 ( struct V_9 * V_10 , unsigned V_91 )
{
int V_81 = 0 ;
struct V_92 * V_83 = V_10 -> V_83 ;
switch ( V_91 ) {
case V_93 :
V_81 = 0 ;
break;
default:
V_81 = - V_53 ;
case 0 :
break;
}
if ( V_81 ) {
F_43 ( V_10 -> V_83 ,
V_10 -> V_83 -> V_94 ? 8 : 100 ) ;
} else {
char * V_95 ;
unsigned V_96 ;
V_96 = 2 * V_97 . V_98 ;
F_43 ( V_10 -> V_83 , V_96 ) ;
switch ( V_83 -> V_95 ) {
case V_99 : V_95 = L_17 ; break;
#ifdef F_44
case V_100 : V_95 = L_18 ; break;
#endif
default: V_95 = L_19 ; break;
}
V_10 -> V_101 = V_91 ;
F_45 ( V_10 , L_20 ,
V_95 , V_91 , V_96 , V_102 ) ;
}
return V_81 ;
}
static int
F_46 ( enum V_103 V_95 , T_6 * V_8 , T_6 type , unsigned V_104 ,
int V_94 )
{
int V_4 ;
const struct V_105 * * V_106 ;
#ifdef F_44
int V_107 = ( V_95 == V_100 ) ;
if ( type == V_108 )
V_107 = ! V_107 ;
if ( V_107 ) {
V_106 = V_109 ;
} else {
V_106 = V_110 ;
}
#else
V_106 = V_110 ;
#endif
if ( V_104 >= V_111 . V_112 )
return - V_53 ;
if ( ! V_94 )
V_106 ++ ;
V_4 = F_47 ( & V_97 , V_8 , V_113 ,
V_106 ) ;
if ( V_4 < 0 )
return V_4 ;
( (struct V_114 * ) V_8 ) -> V_115 = type ;
return V_4 ;
}
static int
F_48 ( struct V_9 * V_10 , unsigned V_91 )
{
int V_81 = 0 ;
switch ( V_10 -> V_89 ) {
case V_116 :
F_41 ( V_10 ) ;
break;
}
switch ( V_91 ) {
case V_116 :
V_81 = F_37 ( V_10 ) ;
if ( V_81 ) {
F_41 ( V_10 ) ;
} else {
V_10 -> V_89 = V_116 ;
}
break;
default:
V_81 = - V_53 ;
}
if ( ! V_81 )
F_45 ( V_10 , L_21 , V_91 ) ;
return V_81 ;
}
static void F_49 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
if ( V_6 -> V_12 || V_6 -> V_16 != V_6 -> V_7 )
F_11 ( (struct V_9 * ) V_3 -> V_11 ,
L_22 ,
V_6 -> V_12 , V_6 -> V_16 , V_6 -> V_7 ) ;
}
static void F_50 ( struct V_9 * V_10 )
{
struct V_1 * V_6 ;
F_45 ( V_10 , L_23 ) ;
if ( F_40 ( V_10 -> V_61 ) )
F_11 ( V_10 , L_24 ) ;
if ( F_40 ( V_10 -> V_44 ) )
F_11 ( V_10 , L_25 ) ;
if ( V_10 -> V_50 != NULL ) {
F_12 ( & V_10 -> V_50 -> V_15 , & V_10 -> V_18 ) ;
V_10 -> V_50 = NULL ;
}
V_10 -> V_51 = 0 ;
V_10 -> V_52 = NULL ;
V_10 -> V_55 = 1 ;
while ( F_18 ( ! ( F_19 ( & V_10 -> V_17 ) ) ) ) {
V_6 = F_23 ( V_10 -> V_17 . V_41 , struct V_1 ,
V_15 ) ;
F_9 ( & V_6 -> V_15 ) ;
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
}
while ( F_18 ( ! ( F_19 ( & V_10 -> V_46 ) ) ) ) {
V_6 = F_23 ( V_10 -> V_17 . V_41 , struct V_1 ,
V_15 ) ;
F_9 ( & V_6 -> V_15 ) ;
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
}
while ( F_18 ( ! ( F_19 ( & V_10 -> V_27 ) ) ) ) {
V_6 = F_23 ( V_10 -> V_27 . V_41 ,
struct V_1 , V_15 ) ;
F_9 ( & V_6 -> V_15 ) ;
F_12 ( & V_6 -> V_15 , & V_10 -> V_25 ) ;
}
if ( F_39 ( V_10 -> V_61 ) )
F_11 ( V_10 , L_26 ) ;
if ( F_39 ( V_10 -> V_44 ) )
F_11 ( V_10 , L_27 ) ;
F_14 ( & V_10 -> V_24 ) ;
F_14 ( & V_10 -> V_26 ) ;
F_14 ( & V_10 -> V_28 ) ;
}
static int
F_51 ( struct V_92 * V_83 , const struct V_117 * V_118 )
{
struct V_9 * V_10 = F_52 ( V_83 ) ;
struct V_1 * V_6 = V_10 -> V_6 ;
int V_119 = - V_120 ;
T_8 V_121 = F_53 ( V_118 -> V_121 ) ;
T_8 V_122 = F_53 ( V_118 -> V_122 ) ;
T_8 V_123 = F_53 ( V_118 -> V_123 ) ;
F_11 ( V_10 , L_28 ,
V_118 -> V_124 , V_118 -> V_125 , V_122 , V_121 , V_123 ) ;
V_6 -> V_43 = F_49 ;
switch ( V_118 -> V_124 & V_126 ) {
case V_127 :
switch ( V_118 -> V_125 ) {
case V_128 :
if ( V_118 -> V_124 != V_129 )
break;
switch ( V_122 >> 8 ) {
case V_130 :
V_111 . V_131 =
V_83 -> V_132 -> V_62 ;
V_119 = F_54 ( V_123 , ( T_8 ) sizeof V_111 ) ;
memcpy ( V_6 -> V_8 , & V_111 , V_119 ) ;
break;
#ifdef F_44
case V_133 :
if ( ! V_83 -> V_134 )
break;
V_135 . V_131 =
V_83 -> V_132 -> V_62 ;
V_119 = F_54 ( V_123 ,
( T_8 ) sizeof V_135 ) ;
memcpy ( V_6 -> V_8 , & V_135 , V_119 ) ;
break;
case V_108 :
if ( ! V_83 -> V_134 )
break;
#endif
case V_136 :
V_119 = F_46 ( V_83 -> V_95 , V_6 -> V_8 ,
V_122 >> 8 ,
V_122 & 0xff ,
V_83 -> V_94 ) ;
if ( V_119 >= 0 )
V_119 = F_54 ( V_123 , ( T_8 ) V_119 ) ;
break;
case V_137 :
V_119 = F_55 ( & V_138 ,
V_122 & 0xff , V_6 -> V_8 ) ;
if ( V_119 >= 0 )
V_119 = F_54 ( V_123 , ( T_8 ) V_119 ) ;
break;
}
break;
case V_139 :
if ( V_118 -> V_124 != 0 )
break;
if ( V_83 -> V_140 )
F_11 ( V_10 , L_29 ) ;
else if ( V_83 -> V_141 )
F_11 ( V_10 , L_30 ) ;
V_119 = F_42 ( V_10 , V_122 ) ;
if ( ! V_119 )
V_119 = F_48 ( V_10 , V_116 ) ;
break;
case V_142 :
if ( V_118 -> V_124 != V_129 )
break;
* ( T_6 * ) V_6 -> V_8 = V_10 -> V_101 ;
V_119 = F_54 ( V_123 , ( T_8 ) 1 ) ;
break;
case V_143 :
if ( V_118 -> V_124 != V_144 ||
! V_10 -> V_101 )
break;
V_119 = F_48 ( V_10 , V_116 ) ;
break;
case V_145 :
if ( V_118 -> V_124 !=
( V_129 | V_144 )
|| ! V_10 -> V_101 )
break;
* ( T_6 * ) V_6 -> V_8 = V_10 -> V_89 ;
V_119 = F_54 ( V_123 , ( T_8 ) 1 ) ;
break;
default:
goto V_146;
}
break;
case V_147 :
switch ( V_118 -> V_125 ) {
case 0 :
if ( ( V_121 >> 8 ) != V_116 )
break;
V_119 = ( V_148 [ 0 ] << 8 ) | V_148 [ 1 ] ;
memcpy ( V_6 -> V_8 , V_148 , V_119 ) ;
F_11 ( V_10 , L_31 , V_119 ,
& V_148 [ 2 ] ) ;
break;
case 1 :
if ( V_121 != V_116 )
break;
* ( T_6 * ) V_6 -> V_8 = V_10 -> V_39 ;
V_119 = F_54 ( V_123 , ( T_8 ) 1 ) ;
break;
case 2 :
if ( V_121 != V_116 )
break;
F_50 ( V_10 ) ;
V_119 = 0 ;
break;
default:
goto V_146;
}
break;
default:
V_146:
F_13 ( V_10 ,
L_32 ,
V_118 -> V_124 , V_118 -> V_125 ,
V_122 , V_121 , V_123 ) ;
break;
}
if ( V_119 >= 0 ) {
V_6 -> V_7 = V_119 ;
V_6 -> V_60 = V_119 < V_123 ;
V_119 = F_27 ( V_83 -> V_132 , V_6 , V_45 ) ;
if ( V_119 < 0 ) {
F_11 ( V_10 , L_33 , V_119 ) ;
V_6 -> V_12 = 0 ;
F_49 ( V_83 -> V_132 , V_6 ) ;
}
}
return V_119 ;
}
static void
F_56 ( struct V_92 * V_83 )
{
struct V_9 * V_10 = F_52 ( V_83 ) ;
unsigned long V_13 ;
F_11 ( V_10 , L_16 , V_90 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
F_41 ( V_10 ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
}
static void
F_57 ( struct V_92 * V_83 )
{
struct V_9 * V_10 = F_52 ( V_83 ) ;
struct V_1 * V_6 ;
F_11 ( V_10 , L_16 , V_90 ) ;
F_58 ( V_149 , V_150 ) ;
F_59 ( & V_10 -> V_36 ) ;
F_60 ( ! F_19 ( & V_10 -> V_27 ) ) ;
F_60 ( ! F_19 ( & V_10 -> V_46 ) ) ;
while ( ! F_19 ( & V_10 -> V_25 ) ) {
V_6 = F_23 ( V_10 -> V_25 . V_41 , struct V_1 ,
V_15 ) ;
F_61 ( & V_6 -> V_15 ) ;
F_5 ( V_10 -> V_61 , V_6 ) ;
}
if ( V_10 -> V_50 != NULL )
F_5 ( V_10 -> V_44 , V_10 -> V_50 ) ;
while ( ! F_19 ( & V_10 -> V_18 ) ) {
V_6 = F_23 ( V_10 -> V_18 . V_41 ,
struct V_1 , V_15 ) ;
F_61 ( & V_6 -> V_15 ) ;
F_5 ( V_10 -> V_44 , V_6 ) ;
}
while ( ! F_19 ( & V_10 -> V_17 ) ) {
V_6 = F_23 ( V_10 -> V_17 . V_41 ,
struct V_1 , V_15 ) ;
F_61 ( & V_6 -> V_15 ) ;
F_5 ( V_10 -> V_44 , V_6 ) ;
}
if ( V_10 -> V_6 ) {
F_5 ( V_83 -> V_132 , V_10 -> V_6 ) ;
V_10 -> V_6 = NULL ;
}
F_62 ( V_83 , NULL ) ;
}
static int T_9
F_63 ( struct V_92 * V_83 )
{
struct V_9 * V_10 ;
struct V_2 * V_61 , * V_44 ;
int V_12 = - V_151 ;
int V_152 ;
T_4 V_4 ;
T_10 V_153 ;
struct V_1 * V_6 ;
V_10 = & V_154 ;
V_10 -> V_155 = F_64 ( V_149 , NULL , V_150 ,
NULL , L_34 ) ;
if ( F_65 ( V_10 -> V_155 ) ) {
ERROR ( V_10 , L_35 ) ;
goto V_156;
}
F_66 ( & V_10 -> V_36 , & V_157 ) ;
V_10 -> V_36 . V_158 = V_159 ;
V_12 = F_67 ( & V_10 -> V_36 , V_150 , 1 ) ;
if ( V_12 ) {
ERROR ( V_10 , L_36 ) ;
goto V_156;
}
V_152 = F_68 ( V_83 ) ;
if ( V_152 >= 0 ) {
V_111 . V_160 = F_69 ( 0x0200 + V_152 ) ;
} else {
F_70 ( & V_83 -> V_10 , L_37 ,
V_83 -> V_22 ) ;
V_111 . V_160 =
F_69 ( 0xFFFF ) ;
}
snprintf ( V_161 , sizeof( V_161 ) , L_38 ,
F_71 () -> V_162 , F_71 () -> V_163 ,
V_83 -> V_22 ) ;
V_111 . V_164 =
F_69 ( V_165 ) ;
V_111 . V_166 =
F_69 ( V_167 ) ;
if ( V_164 ) {
if ( ! V_166 ) {
F_72 ( & V_83 -> V_10 , L_39 ) ;
return - V_168 ;
}
V_111 . V_164 = F_69 ( V_164 ) ;
V_111 . V_166 = F_69 ( V_166 ) ;
if ( V_160 )
V_111 . V_160 = F_69 ( V_160 ) ;
}
if ( V_169 )
F_73 ( V_161 , V_169 , sizeof V_161 ) ;
if ( V_170 )
F_73 ( V_171 , V_170 , sizeof V_171 ) ;
if ( V_172 )
F_73 ( V_173 , V_172 , sizeof V_173 ) ;
if ( V_174 )
F_73 ( & V_148 [ 2 ] , V_174 , ( sizeof V_148 ) - 2 ) ;
V_4 = strlen ( V_148 ) ;
V_148 [ 0 ] = ( V_4 >> 8 ) & 0xFF ;
V_148 [ 1 ] = V_4 & 0xFF ;
F_74 ( V_83 ) ;
V_61 = F_75 ( V_83 , & V_85 ) ;
if ( ! V_61 ) {
V_175:
F_72 ( & V_83 -> V_10 , L_40 ,
V_83 -> V_22 ) ;
return - V_168 ;
}
V_61 -> V_11 = V_61 ;
V_44 = F_75 ( V_83 , & V_87 ) ;
if ( ! V_44 )
goto V_175;
V_44 -> V_11 = V_44 ;
#ifdef F_44
V_84 . V_176 = V_85 . V_176 ;
V_86 . V_176 = V_87 . V_176 ;
#endif
F_76 ( V_83 ) ;
if ( V_83 -> V_94 ) {
V_177 . V_178 |= V_179 ,
V_97 . V_178 |= V_180 ;
}
F_77 ( & V_10 -> V_14 ) ;
F_78 ( & V_10 -> V_54 ) ;
F_79 ( & V_10 -> V_25 ) ;
F_79 ( & V_10 -> V_27 ) ;
F_79 ( & V_10 -> V_18 ) ;
F_79 ( & V_10 -> V_46 ) ;
F_79 ( & V_10 -> V_17 ) ;
F_80 ( & V_10 -> V_24 ) ;
F_80 ( & V_10 -> V_26 ) ;
F_80 ( & V_10 -> V_28 ) ;
V_10 -> V_101 = 0 ;
V_10 -> V_89 = - 1 ;
V_10 -> V_37 = 0 ;
V_10 -> V_39 = V_181 ;
V_10 -> V_50 = NULL ;
V_10 -> V_51 = 0 ;
V_10 -> V_52 = NULL ;
V_10 -> V_61 = V_61 ;
V_10 -> V_44 = V_44 ;
V_10 -> V_6 = F_1 ( V_83 -> V_132 , V_113 ,
V_182 ) ;
if ( ! V_10 -> V_6 ) {
V_12 = - V_151 ;
goto V_156;
}
for ( V_153 = 0 ; V_153 < V_183 ; V_153 ++ ) {
V_6 = F_1 ( V_10 -> V_61 , V_42 , V_182 ) ;
if ( ! V_6 ) {
while ( ! F_19 ( & V_10 -> V_25 ) ) {
V_6 = F_23 ( V_10 -> V_25 . V_41 ,
struct V_1 , V_15 ) ;
F_61 ( & V_6 -> V_15 ) ;
F_5 ( V_10 -> V_61 , V_6 ) ;
}
return - V_151 ;
}
F_12 ( & V_6 -> V_15 , & V_10 -> V_25 ) ;
}
for ( V_153 = 0 ; V_153 < V_183 ; V_153 ++ ) {
V_6 = F_1 ( V_10 -> V_44 , V_42 , V_182 ) ;
if ( ! V_6 ) {
while ( ! F_19 ( & V_10 -> V_18 ) ) {
V_6 = F_23 ( V_10 -> V_18 . V_41 ,
struct V_1 , V_15 ) ;
F_61 ( & V_6 -> V_15 ) ;
F_5 ( V_10 -> V_44 , V_6 ) ;
}
return - V_151 ;
}
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
}
V_10 -> V_6 -> V_43 = F_49 ;
V_10 -> V_83 = V_83 ;
F_62 ( V_83 , V_10 ) ;
V_83 -> V_132 -> V_11 = V_10 ;
F_45 ( V_10 , L_41 V_184 L_42 , V_102 ) ;
F_45 ( V_10 , L_43 , V_83 -> V_22 , V_44 -> V_22 ,
V_61 -> V_22 ) ;
return 0 ;
V_156:
F_57 ( V_83 ) ;
return V_12 ;
}
static int T_9
F_81 ( void )
{
int V_12 ;
V_149 = F_82 ( V_159 , L_44 ) ;
if ( F_65 ( V_149 ) ) {
V_12 = F_83 ( V_149 ) ;
ERROR ( V_10 , L_45 , V_12 ) ;
return V_12 ;
}
V_12 = F_84 ( & V_150 , 0 , 1 ,
L_46 ) ;
if ( V_12 ) {
ERROR ( V_10 , L_47 , V_12 ) ;
F_85 ( V_149 ) ;
return V_12 ;
}
V_12 = F_86 ( & V_185 , F_63 ) ;
if ( V_12 ) {
F_85 ( V_149 ) ;
F_87 ( V_150 , 1 ) ;
F_11 ( V_10 , L_48 , V_12 ) ;
}
return V_12 ;
}
static void T_11
F_88 ( void )
{
int V_12 ;
F_22 ( & V_154 . V_54 ) ;
V_12 = F_89 ( & V_185 ) ;
if ( V_12 )
ERROR ( V_10 , L_49 , V_12 ) ;
F_87 ( V_150 , 2 ) ;
F_85 ( V_149 ) ;
F_24 ( & V_154 . V_54 ) ;
}
